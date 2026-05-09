#!/usr/bin/env python3
"""
build_nexus_opt.py — Transform all FPU functions in nexus.cpp → nexus_opt.cpp

For each function with FPU instructions:
  • single-valued FPU balance (deterministic proto) → transform with transform_cfg;
      on TRANSFORM ERROR → prepend stop() and keep original body
  • UNKNOWN balance, all missing callees covered by sigs → infer proto via CFG,
      then transform; on error → prepend stop()
  • UNKNOWN balance, callees still missing → prepend stop("FPU balance unknown…")
  • multi-valued FPU balance ({0,1} etc.) → prepend stop("FPU balance not deterministic…")
  • no FPU instructions → pass through unchanged

The full call-site signature table (all single-valued-balance functions) is passed to
the transformer so that calls to nonzero-balance callees are expanded correctly.

Usage:
    python3 build_nexus_opt.py [nexus.cpp [nexus_opt.cpp]]
Usage:
    python3 build_nexus_opt.py [nexus.cpp [nexus_opt.cpp]] [--sigs sigs.json]

--sigs  JSON file with external prototype overrides:
        { "sub_XXXXXX": [n_in, n_out], ... }
        Entries are merged into the sig table after analyse.txt is loaded.
        Use this to supply balance info for callees listed as unresolved.
"""

import json
import re
import sys
import ast
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import transform_cfg
from transform_cfg import FpuConflictError

_prec_stats: dict = {'float': 0, 'double': 0}

# ---------------------------------------------------------------------------
# Parse argv: positional args + optional --sigs path
_args      = sys.argv[1:]
_sigs_path: Path | None = None
if '--sigs' in _args:
    _i = _args.index('--sigs')
    _sigs_path = Path(_args[_i + 1])
    del _args[_i:_i + 2]

NEXUS_PATH   = Path(_args[0] if len(_args) > 0 else 'nexus.cpp')
OUT_PATH     = Path(_args[1] if len(_args) > 1 else 'nexus_opt.cpp')
ANALYSE_PATH = Path('analyse.txt')

# ---------------------------------------------------------------------------
# 1. Parse analyse.txt
# ---------------------------------------------------------------------------

def load_analysis() -> dict:
    """fn_name → {finsns, bal, smin, notes, missing}"""
    result = {}
    for line in ANALYSE_PATH.read_text().splitlines():
        if not line.startswith('| `sub_'):
            continue
        parts = [p.strip() for p in line.split('|')]
        if len(parts) < 13:
            continue
        try:
            fn      = parts[1].strip('`')
            finsns  = int(parts[3])
            bal_str = parts[4].strip('`')
            smin_str = parts[5].strip()
            missing = parts[11]   # unresolved callee functions
            notes   = parts[12]   # human-readable reason
            if bal_str == 'UNKNOWN' or smin_str == 'UNKNOWN':
                if finsns > 0:
                    # bal=None signals unknown balance; notes/missing carry the reason
                    result[fn] = dict(finsns=finsns, bal=None, smin=0,
                                      notes=notes, missing=missing)
                continue
            smin = int(smin_str)
            bal  = ast.literal_eval(bal_str)
            result[fn] = dict(finsns=finsns, bal=bal, smin=smin,
                              notes=notes, missing=missing)
        except Exception:
            pass
    return result


# ---------------------------------------------------------------------------
# 2. Build signature table for call-site expansion
# ---------------------------------------------------------------------------

def build_sig_table(analysis: dict) -> dict:
    """fn → (n_in, n_out) for every function with a single-valued, non-trivial balance."""
    sigs = {}
    for fn, d in analysis.items():
        bal = d['bal']
        if bal is None or len(bal) != 1:
            continue
        net   = next(iter(bal))
        n_in  = max(0, -d['smin'])
        n_out = n_in + net
        if n_out < 0:
            continue
        if n_in == 0 and n_out == 0:
            continue                      # trivial; no call-site rewrite needed
        sigs[fn] = (n_in, n_out)
    return sigs


# ---------------------------------------------------------------------------
# 3. Function extraction from nexus.cpp
# ---------------------------------------------------------------------------

# Matches: void sub_HEX() // optional comment\n{
FUNC_HDR_RE = re.compile(
    r'^(void\s+(sub_[0-9a-fA-F]+)\s*\(\s*\)[^\n]*)\n\{',
    re.MULTILINE,
)


def match_brace(text: str, start: int) -> int:
    """Return index just after the } that closes the { at position start."""
    depth = 0
    i     = start
    n     = len(text)
    while i < n:
        c = text[i]
        if c == '{':
            depth += 1;  i += 1
        elif c == '}':
            depth -= 1;  i += 1
            if depth == 0:
                return i
        elif c == '"':
            i += 1
            while i < n and text[i] != '"':
                if text[i] == '\\':
                    i += 1
                i += 1
            i += 1
        elif c == '/' and i + 1 < n and text[i + 1] == '/':
            while i < n and text[i] != '\n':
                i += 1
        else:
            i += 1
    return n


def find_functions(text: str) -> list[tuple[str, int, int]]:
    """Return [(fn_name, char_start, char_end), ...] spanning each full function."""
    fns = []
    for m in FUNC_HDR_RE.finditer(text):
        fn_name   = m.group(2)
        fn_start  = m.start()
        brace_pos = m.end() - 1        # position of the opening {
        fn_end    = match_brace(text, brace_pos)
        fns.append((fn_name, fn_start, fn_end))
    return fns


# ---------------------------------------------------------------------------
# 4. stop() insertion helpers
# ---------------------------------------------------------------------------

def prepend_stop(src: str, msg: str) -> str:
    """Insert stop("msg"); as the very first statement inside the function body."""
    lines = src.split('\n')
    for i, line in enumerate(lines):
        if line.strip() == '{':
            lines.insert(i + 1, f'    stop("{msg}");')
            return '\n'.join(lines)
    return src


# ---------------------------------------------------------------------------
# 5. Classify and transform one function
# ---------------------------------------------------------------------------

def process_fn(fn_src: str, fn_name: str,
               analysis: dict, sig_table: dict) -> tuple[str, str]:
    """
    Returns (output_src, outcome_tag) where outcome_tag is:
      'passthrough'   – no FPU ops, returned verbatim
      'transformed'   – successfully transformed
      'stop:MESSAGE'  – stop() prepended for the given reason
    """
    d = analysis.get(fn_name)

    # Not in analysis or no FPU instructions → pass through unchanged
    if d is None or d['finsns'] == 0:
        return fn_src, 'passthrough'

    bal = d['bal']

    # Unknown balance (analyse.txt reported UNKNOWN)
    if bal is None:
        note    = d.get('notes', '').strip()
        missing = d.get('missing', '').strip()

        # If all missing callees are now in sig_table, try to infer proto and transform
        missing_fns  = [f.strip() for f in missing.split(',') if f.strip()] if missing else []
        still_missing = [f for f in missing_fns if f not in sig_table]

        if not still_missing:
            try:
                proto = transform_cfg.infer_proto(fn_src, sig_table)
            except FpuConflictError as exc:
                reason = f'FPU balance conflict: {exc}'
                return prepend_stop(fn_src, reason), f'stop:{reason}'
            except Exception as exc:
                reason = f'FPU infer_proto exception: {exc}'
                return prepend_stop(fn_src, reason), f'stop:{reason}'

            try:
                transformed = transform_cfg.transform(fn_src, proto=proto, sigs=sig_table,
                                                      _stats=_prec_stats)
            except FpuConflictError as exc:
                reason = f'FPU balance conflict: {exc}'
                return prepend_stop(fn_src, reason), f'stop:{reason}'
            except Exception as exc:
                reason = f'FPU transform exception: {exc}'
                return prepend_stop(fn_src, reason), f'stop:{reason}'

            errors = [ln for ln in transformed.splitlines() if 'TRANSFORM ERROR' in ln]
            if errors:
                reason = f'FPU transform failed ({len(errors)} error(s))'
                return prepend_stop(fn_src, reason), f'stop:{reason}'

            return transformed, 'transformed'

        # Some callees still unresolved — prepend stop() with diagnostics
        reason = f'FPU balance unknown: {note}' if note else 'FPU balance unknown'
        if still_missing:
            reason += f' (unresolved callees: {", ".join(still_missing)})'
        return prepend_stop(fn_src, reason), f'stop:{reason}'

    # Multi-valued balance: different branches leave different stack depths
    if len(bal) != 1:
        reason = f'FPU balance not deterministic: {sorted(bal)}'
        return prepend_stop(fn_src, reason), f'stop:{reason}'

    net   = next(iter(bal))
    n_in  = max(0, -d['smin'])
    n_out = n_in + net

    if n_out < 0:
        reason = f'FPU transform skipped: invalid proto ({n_in}:{n_out})'
        return prepend_stop(fn_src, reason), f'stop:{reason}'

    proto = (n_in, n_out)

    try:
        transformed = transform_cfg.transform(fn_src, proto=proto, sigs=sig_table,
                                              _stats=_prec_stats)
    except FpuConflictError as exc:
        reason = f'FPU balance conflict: {exc}'
        return prepend_stop(fn_src, reason), f'stop:{reason}'
    except Exception as exc:
        reason = f'FPU transform exception: {exc}'
        return prepend_stop(fn_src, reason), f'stop:{reason}'

    errors = [ln for ln in transformed.splitlines() if 'TRANSFORM ERROR' in ln]
    if errors:
        reason = f'FPU transform failed ({len(errors)} error(s))'
        return prepend_stop(fn_src, reason), f'stop:{reason}'

    return transformed, 'transformed'


# ---------------------------------------------------------------------------
# 6. Main
# ---------------------------------------------------------------------------

def main() -> None:
    print(f'Loading {ANALYSE_PATH}…', flush=True)
    analysis  = load_analysis()
    sig_table = build_sig_table(analysis)

    if _sigs_path is not None:
        ext = json.loads(_sigs_path.read_text())
        for fn, proto in ext.items():
            sig_table[fn] = (int(proto[0]), int(proto[1]))
        print(f'  +{len(ext)} external signature(s) loaded from {_sigs_path}')
    print(f'  {len(analysis)} functions in analysis, '
          f'{len(sig_table)} non-trivial signatures')

    # Collect unique unresolved callees across all UNKNOWN-balance functions
    unresolved: set[str] = set()
    for d in analysis.values():
        if d['bal'] is None and d.get('missing', '').strip():
            for fn in d['missing'].split(','):
                fn = fn.strip()
                if fn and fn not in sig_table:
                    unresolved.add(fn)
    if unresolved:
        print(f'\n  {len(unresolved)} callee(s) with unknown balance block analysis'
              f' — provide their signatures to resolve:')
        for fn in sorted(unresolved):
            print(f'    {fn}')
        print()

    print(f'Parsing {NEXUS_PATH} ({NEXUS_PATH.stat().st_size // 1024} KB)…', flush=True)
    text      = NEXUS_PATH.read_text(errors='replace')
    functions = find_functions(text)
    print(f'  {len(functions)} function definitions found')

    # Count FPU functions for progress reporting
    fpu_fns = sum(1 for fn, _, _ in functions
                  if analysis.get(fn, {}).get('finsns', 0) > 0)
    print(f'  {fpu_fns} have FPU instructions')

    # Build output
    parts    = []
    prev_end = 0
    stats    = dict(passthrough=0, transformed=0, stop=0)
    proto_stats: dict[tuple, int] = {}
    stop_log: list[str] = []

    for idx, (fn_name, fn_start, fn_end) in enumerate(functions, 1):
        if idx % 50 == 0:
            print(f'  [{idx}/{len(functions)}]…', flush=True)

        parts.append(text[prev_end:fn_start])   # gap / preamble between functions

        fn_src           = text[fn_start:fn_end]
        out_src, outcome = process_fn(fn_src, fn_name, analysis, sig_table)
        parts.append(out_src)
        prev_end = fn_end

        if outcome == 'passthrough':
            stats['passthrough'] += 1
        elif outcome == 'transformed':
            stats['transformed'] += 1
            d   = analysis.get(fn_name, {})
            bal = d.get('bal')
            if bal is not None and len(bal) == 1:
                net   = next(iter(bal))
                n_in  = max(0, -d.get('smin', 0))
                n_out = n_in + net
            else:
                # inferred proto — report as (?,?)
                n_in, n_out = -1, -1
            proto_stats[(n_in, n_out)] = proto_stats.get((n_in, n_out), 0) + 1
        else:
            stats['stop'] += 1
            stop_log.append(f'  {fn_name:30s}  {outcome[5:]}')

    parts.append(text[prev_end:])               # anything after the last function

    print(f'\nWriting {OUT_PATH}…', flush=True)
    OUT_PATH.write_text(''.join(parts), encoding='utf-8', errors='replace')

    total = sum(stats.values())
    print(f'\n=== Results ({total} functions) ===')
    print(f'  transformed : {stats["transformed"]:4d}')
    if proto_stats:
        for (ni, no), cnt in sorted(proto_stats.items()):
            label = 'inferred' if (ni, no) == (-1, -1) else f'proto {ni}:{no}'
            print(f'      {label}  →  {cnt}')
    print(f'  passthrough : {stats["passthrough"]:4d}  (no FPU ops)')
    print(f'  stop()      : {stats["stop"]:4d}')
    if stop_log:
        print('\nstop() details:')
        for s in stop_log:
            print(s)

    total_vars = _prec_stats['float'] + _prec_stats['double']
    if total_vars:
        pct = 100 * _prec_stats['float'] // total_vars
        print(f'\nLocal FPU variable types ({total_vars} total):')
        print(f'  float  : {_prec_stats["float"]:4d}  ({pct}%)')
        print(f'  double : {_prec_stats["double"]:4d}  ({100 - pct}%)')


if __name__ == '__main__':
    main()
