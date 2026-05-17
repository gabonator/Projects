#!/usr/bin/env python3
"""
Replace all FP and integer constant reads from hardcoded addresses with inline literals.

Replacements performed (float):
  fld80(memoryAGet80(ds, ADDR))  →  fppush(VALUE)
  fld64(memoryAGet64(ds, ADDR))  →  fppush(VALUE)
  fld32(memoryAGet32(ds, ADDR))  →  fppush(VALUE)
  memoryFGet64(ds, ADDR)         →  VALUE
  memoryFGet32(ds, ADDR)         →  VALUEf
  memoryAGet80(ds, ADDR)         →  VALUE   (standalone, leftover after fld80)

Replacements performed (integer — .rdata only, non-pointer values):
  memoryAGet64(ds, ADDR)         →  VALUE ull
  memoryAGet32(ds, ADDR)         →  VALUE u
  memoryAGet16(ds, ADDR)         →  VALUE
  memoryAGet(ds, ADDR)           →  VALUE

Usage:
  python3 replace_fp_consts.py                        # dry-run (print diffs only)
  python3 replace_fp_consts.py --apply                # write to processed/ subdir
  python3 replace_fp_consts.py --apply --outdir DIR   # write to DIR/
"""

import re, os, glob, sys, struct, math
from collections import defaultdict

# ── Section layout ──────────────────────────────────────────────────────────
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
SECTIONS = {
    "rdata": (0x100e6000, 0x103fa819, os.path.join(SCRIPT_DIR, "../res", "Nexus_rdata.bin")),
    "data":  (0x103fb000, 0x10583d5c, os.path.join(SCRIPT_DIR, "../res", "Nexus_data.bin")),
    "text":  (0x10001000, 0x100e531b, os.path.join(SCRIPT_DIR, "../res", "Nexus_text.bin")),
}
_binaries: dict = {}

def load_section(name):
    if name not in _binaries:
        try:
            with open(SECTIONS[name][2], "rb") as f:
                _binaries[name] = f.read()
        except OSError:
            _binaries[name] = None
    return _binaries[name]

RDATA_LO, RDATA_HI = SECTIONS["rdata"][0], SECTIONS["rdata"][1]
DATA_LO,  DATA_HI  = SECTIONS["data"][0],  SECTIONS["data"][1]

# Set to True by --force-data-fp80 to also inline fld80 constants from .data.
FORCE_DATA_FP80: bool = False

def read_bytes(addr, n, allow_data: bool = False):
    # Only inline constants from .rdata (guaranteed read-only at runtime).
    # .data can be written, so leave it alone — unless allow_data is set.
    if RDATA_LO <= addr <= RDATA_HI:
        data = load_section("rdata")
        off  = addr - RDATA_LO
    elif allow_data and (DATA_LO <= addr <= DATA_HI):
        data = load_section("data")
        off  = addr - DATA_LO
    else:
        return None
    if data is None: return None
    if off + n > len(data): return None
    return data[off:off+n]

def decode_f80_maybe_data(addr):
    """For fld80: read from .rdata normally, or from .data if FORCE_DATA_FP80."""
    raw = read_bytes(addr, 10, allow_data=FORCE_DATA_FP80)
    if raw is None: return None
    mantissa  = int.from_bytes(raw[0:8], "little")
    sign_exp  = int.from_bytes(raw[8:10], "little")
    sign = (sign_exp >> 15) & 1
    exp  = sign_exp & 0x7FFF
    if exp == 0 and mantissa == 0:
        return -0.0 if sign else 0.0
    if exp == 0x7FFF:
        if mantissa & 0x7FFFFFFFFFFFFFFF:
            return float("nan")
        return float("-inf") if sign else float("inf")
    d_exp = exp - 16383 + 1023
    frac52 = (mantissa & 0x7FFFFFFFFFFFFFFF) >> 11
    if d_exp <= 0:  return -0.0 if sign else 0.0
    if d_exp >= 0x7FF: return float("-inf") if sign else float("inf")
    bits = (sign << 63) | (d_exp << 52) | frac52
    return struct.unpack("<d", struct.pack("<Q", bits))[0]

# ── Float decoders ──────────────────────────────────────────────────────────
def decode_f32(addr):
    raw = read_bytes(addr, 4)
    if raw is None: return None
    return struct.unpack_from("<f", raw)[0]

def decode_f64(addr):
    raw = read_bytes(addr, 8)
    if raw is None: return None
    return struct.unpack_from("<d", raw)[0]

# ── Integer decoders ────────────────────────────────────────────────────────
def decode_u8(addr):
    raw = read_bytes(addr, 1)
    if raw is None: return None
    return struct.unpack_from("<B", raw)[0]

def decode_u16(addr):
    raw = read_bytes(addr, 2)
    if raw is None: return None
    return struct.unpack_from("<H", raw)[0]

def decode_u32(addr):
    raw = read_bytes(addr, 4)
    if raw is None: return None
    return struct.unpack_from("<I", raw)[0]

def decode_u64(addr):
    raw = read_bytes(addr, 8)
    if raw is None: return None
    return struct.unpack_from("<Q", raw)[0]

# PE module virtual address range — values in this range are pointers, not constants.
PE_ADDR_LO = 0x10000000
PE_ADDR_HI = 0x10600000

def is_ptr(val: int) -> bool:
    return PE_ADDR_LO <= val <= PE_ADDR_HI

# ── C++ literal formatters ──────────────────────────────────────────────────
def _base_repr(val: float) -> str:
    """Shortest decimal representation, guaranteed to have a decimal point."""
    if math.isnan(val):  return "NAN"
    if math.isinf(val):  return "INFINITY" if val > 0 else "-INFINITY"
    s = repr(val)
    # ensure there's a decimal point so compiler knows it's floating-point
    if "." not in s and "e" not in s:
        s += ".0"
    return s

def c_f64(val: float) -> str:
    return _base_repr(val)

def c_u8(val: int) -> str:
    return str(val)                              # always 0-255, decimal is readable

def c_u16(val: int) -> str:
    return str(val) if val <= 9999 else f"0x{val:04x}u"

def c_u32(val: int) -> str:
    return str(val) if val <= 9999 else f"0x{val:08x}u"

def c_u64(val: int) -> str:
    return str(val) if val <= 9999 else f"0x{val:016x}ull"

def c_f32(val: float) -> str:
    if math.isnan(val):  return "NAN"
    if math.isinf(val):  return "INFINITY" if val > 0 else "-INFINITY"
    # Re-pack as float32 then format; repr() of the promoted double is
    # always the shortest decimal that round-trips as float32 too.
    f32val = struct.unpack("<f", struct.pack("<f", val))[0]
    s = repr(f32val)
    if "." not in s and "e" not in s:
        s += ".0"
    return s + "f"

# ── Regex patterns (most specific first) ───────────────────────────────────
SP  = r"\s*"
SEG = r"(?:ds|ss|es|fs|gs)"
HEX = r"(0x[0-9A-Fa-f]+)"

# Each entry: (regex, addr_group, decode_fn, replacement_fn)
#   replacement_fn(decoded_value) → replacement string
RULES = [
    # fld80(memoryAGet80(ds, ADDR)) → fppush(VALUE)
    (re.compile(rf"fld80{SP}\({SP}memoryAGet80{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\){SP}\)"),
     1, decode_f80_maybe_data, lambda v: f"fppush({c_f64(v)})"),

    # fld64(memoryAGet64(ds, ADDR)) → fppush(VALUE)
    (re.compile(rf"fld64{SP}\({SP}memoryAGet64{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\){SP}\)"),
     1, decode_f64, lambda v: f"fppush({c_f64(v)})"),

    # fld32(memoryAGet32(ds, ADDR)) → fppush(VALUE)
    (re.compile(rf"fld32{SP}\({SP}memoryAGet32{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\){SP}\)"),
     1, decode_f32, lambda v: f"fppush({c_f64(v)})"),

    # memoryFGet64(ds, ADDR) → VALUE
    (re.compile(rf"memoryFGet64{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_f64, c_f64),

    # memoryFGet32(ds, ADDR) → VALUEf
    (re.compile(rf"memoryFGet32{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_f32, c_f32),

    # memoryAGet80(ds, ADDR) standalone → VALUE  (leftover after fld80 pass)
    (re.compile(rf"memoryAGet80{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_f80_maybe_data, c_f64),

    # ── Integer rules (after all float-wrapper rules so fld32/fld64 are consumed first) ──

    # memoryAGet64(ds, ADDR) → VALUEull   (skip pointer-range values)
    (re.compile(rf"memoryAGet64{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_u64, lambda v: None if is_ptr(v) else c_u64(v)),

    # memoryAGet32(ds, ADDR) → VALUEu     (skip pointer-range values)
    (re.compile(rf"memoryAGet32{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_u32, lambda v: None if is_ptr(v) else c_u32(v)),

    # memoryAGet16(ds, ADDR) → VALUE
    (re.compile(rf"memoryAGet16{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_u16, c_u16),

    # memoryAGet(ds, ADDR) → VALUE   (bare byte read — note: match last, most generic)
    (re.compile(rf"memoryAGet{SP}\({SP}{SEG}{SP},{SP}{HEX}{SP}\)"),
     1, decode_u8, c_u8),
]

# ── Single-line substitution ─────────────────────────────────────────────────
def substitute_line(line: str) -> tuple[str, int]:
    """Return (new_line, n_replacements)."""
    count = 0
    for rx, grp, decoder, formatter in RULES:
        def repl(m, _decoder=decoder, _formatter=formatter, _grp=grp):
            addr = int(m.group(_grp), 16)
            val  = _decoder(addr)
            if val is None:
                return m.group(0)   # address not in .rdata (or .data) — leave as-is
            replacement = _formatter(val)
            if replacement is None:
                return m.group(0)   # formatter opted out (e.g. pointer-range integer)
            return replacement
        new_line, n = rx.subn(repl, line)
        count += n
        line = new_line
    return line, count

# ── File-level processing ────────────────────────────────────────────────────
def process_file(path: str, apply: bool, outdir: str | None) -> tuple[int, int]:
    """Return (lines_changed, replacements_made).
    Writes processed output to outdir/<basename> — never overwrites the source."""
    with open(path, encoding="utf-8", errors="replace") as f:
        original_lines = f.readlines()

    new_lines = []
    lines_changed = 0
    total_replacements = 0

    for lineno, line in enumerate(original_lines, 1):
        new_line, n = substitute_line(line)
        if n:
            lines_changed += 1
            total_replacements += n
            if not apply:
                rel = os.path.relpath(path, SCRIPT_DIR)
                print(f"  {rel}:{lineno}")
                print(f"  - {line.rstrip()}")
                print(f"  + {new_line.rstrip()}")
                print()
        new_lines.append(new_line)

    if apply and outdir:
        basename = os.path.basename(path)
        out_path = os.path.join(outdir, basename)
        with open(out_path, "w", encoding="utf-8") as f:
            f.writelines(new_lines)

    return lines_changed, total_replacements

# ── Main ─────────────────────────────────────────────────────────────────────
def main():
    global FORCE_DATA_FP80
    args = sys.argv[1:]
    apply = "--apply" in args
    FORCE_DATA_FP80 = "--force-data-fp80" in args

    # Parse optional --outdir DIR
    outdir = None
    if apply:
        if "--outdir" in args:
            idx = args.index("--outdir")
            outdir = args[idx + 1]
        else:
            outdir = os.path.join(SCRIPT_DIR, "processed")
        os.makedirs(outdir, exist_ok=True)

    cpp_files = sorted(glob.glob(os.path.join(SCRIPT_DIR, "**", "*.cpp"), recursive=True))
    if not cpp_files:
        print("No .cpp files found.")
        return

    extras = []
    if FORCE_DATA_FP80: extras.append("--force-data-fp80")
    mode = f"APPLYING → {outdir}" if apply else "DRY RUN"
    scope = ".rdata" + (" + .data fp80" if FORCE_DATA_FP80 else "")
    print(f"\n{'='*70}")
    print(f"  Constant inliner — {mode}")
    print(f"  {len(cpp_files)} source files  |  {scope}")
    print(f"{'='*70}\n")

    total_files   = 0
    total_lines   = 0
    total_repls   = 0

    for path in cpp_files:
        lc, rc = process_file(path, apply, outdir)
        if lc:
            total_files += 1
            total_lines += lc
            total_repls += rc
            if apply:
                rel = os.path.relpath(path, SCRIPT_DIR)
                print(f"  wrote {os.path.join(outdir, os.path.basename(path))}  "
                      f"({rc} replacements in {lc} lines)")

    action = "Written" if apply else "Would modify"
    print(f"\n{'─'*70}")
    print(f"  {action}: {total_files} files, {total_lines} lines, {total_repls} replacements")
    if not apply:
        print(f"  Run with --apply to write to processed/")
    print()

if __name__ == "__main__":
    main()
