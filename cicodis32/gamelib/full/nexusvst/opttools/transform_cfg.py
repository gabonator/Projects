#!/usr/bin/env python3
"""
transform_cfg.py — CFG / basic-block FPU transformer.

Algorithm:
  1. Split the function into basic blocks (BB) at label/goto/return boundaries.
  2. For each BB compute the net FPU-stack depth delta and the intra-BB depth range.
  3. BFS-propagate depths from the function entry; every successor BB inherits
     (predecessor.entry_depth + predecessor.delta).
  4. At any join point (label reachable from two or more paths): if the incoming
     depths disagree, raise FpuConflictError – the function cannot be translated
     unambiguously and the caller should prepend stop().
  5. With exact entry-depth known for every BB, generate C++ using a fixed ring of
     N = max_absolute_depth variables (fp0 … fp_{N-1}).  ST(k) at depth-counter d
     maps to fp[(n_in + d - 1 - k) % N].
  6. fxch emits a physical variable swap, not a metadata rename.

Usage (same interface as transform2.transform):
    import transform_cfg
    out = transform_cfg.transform(src, proto=(n_in, n_out), sigs=sig_table)
"""

import re
import sys
from collections import deque
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional

sys.path.insert(0, str(Path(__file__).parent))
from transform2 import (
    FPU_CALL_RE, FNSTSW_RE, PARITYODD_RE, AH_MASK_RE,
    split_args, mem_float_get,
    rewrite_store_line, rewrite_fistp_store,
    resolve_cond,
)

# ---------------------------------------------------------------------------
# FPU depth delta for every supported op
# ---------------------------------------------------------------------------

FPU_DELTA: dict[str, int] = {
    # +1 (push)
    'fld32': 1, 'fld64': 1, 'fld80': 1,
    'fldz': 1, 'fld1': 1, 'fldpi': 1,
    'fldln2': 1, 'fldl2e': 1, 'fldl2t': 1, 'fldlg2': 1,
    'fild16': 1, 'fild32': 1, 'fild64': 1,
    'fldst': 1,
    # -1 (pop)
    'fstp32': -1, 'fstp64': -1, 'fstp80': -1,
    'fstpst': -1,
    'fistp16': -1, 'fistp32': -1, 'fistp64': -1,
    'fcomp32': -1, 'fcomp64': -1, 'fcomp80': -1, 'fcompst': -1,
    # -2 (double pop)
    'fcompp': -2,
    # -1 (pop-arithmetic)
    'faddpst': -1, 'fsubpst': -1, 'fsubrpst': -1,
    'fmulpst': -1, 'fdivpst': -1, 'fdivrpst': -1,
    'fdivp80': -1,                                   # FDIVP ST(i),ST — pops
    # 0 (no stack change)
    'fst32': 0, 'fst64': 0,
    'fadd32': 0, 'fadd64': 0, 'fsub32': 0, 'fsub64': 0,
    'fsubr32': 0, 'fsubr64': 0, 'fmul32': 0, 'fmul64': 0,
    'fdiv32': 0, 'fdiv64': 0, 'fdivr32': 0, 'fdivr64': 0,
    'fdivr80': 0,                                    # FDIVR extended — no pop
    'faddst': 0, 'fsubst': 0, 'fsubrst': 0, 'fmulst': 0, 'fdivst': 0, 'fdivrst': 0,
    'fmulst2': 0, 'faddst2': 0, 'fsubst2': 0, 'fdivst2': 0, 'fsubrst2': 0,
    'fimul32': 0, 'fimul16': 0, 'fiadd32': 0, 'fiadd16': 0,
    'fabs': 0, 'fchs': 0, 'fsqrt': 0, 'fsin': 0, 'fcos': 0,
    'fxchst2': 0,
    'fcom32': 0, 'fcom64': 0, 'fcom80': 0, 'fcomst': 0,
}

LABEL_RE  = re.compile(r'^(\s*)(loc_[0-9a-fA-F]+)\s*:\s*(?://.*)?$')
GOTO_RE   = re.compile(r'\bgoto\s+(loc_[0-9a-fA-F]+)\s*;')
RETURN_RE = re.compile(r'\breturn\b')
STOP_RE   = re.compile(r'\bstop\s*\(')   # stop() never returns — treat as terminator

# ---------------------------------------------------------------------------
# Basic block data structure
# ---------------------------------------------------------------------------

@dataclass
class BB:
    idx:         int
    label:       Optional[str]       # entry label, None for entry block
    lines:       list[str]           = field(default_factory=list)
    delta:       int                 = 0   # net FPU depth change
    rel_min:     int                 = 0   # min depth relative to BB entry
    rel_max:     int                 = 0   # max depth relative to BB entry
    successors:  list[str]           = field(default_factory=list)  # labels / '__exit__'
    entry_depth: Optional[int]       = None
    conflict:    Optional[str]       = None  # set if depth conflict detected
    stop_exit:   bool                = False # True when exit is via stop() (error handler)

# ---------------------------------------------------------------------------
# Step 1 – Parse into basic blocks
# ---------------------------------------------------------------------------

def _bb_key(bb: BB) -> str:
    return bb.label if bb.label else f'__bb{bb.idx}__'


def parse_basic_blocks(body_lines: list[str]) -> list[BB]:
    """Split the function body into basic blocks."""
    # Find BB start indices: function entry (0) + any label line + line after goto/return
    starts: list[int] = [0]
    for i, line in enumerate(body_lines):
        s = line.strip()
        if not s:
            continue
        if LABEL_RE.match(line) and i > 0:
            starts.append(i)
        if GOTO_RE.search(line) or RETURN_RE.search(line):
            if i + 1 < len(body_lines):
                starts.append(i + 1)

    starts = sorted(set(starts))
    ends   = starts[1:] + [len(body_lines)]

    bbs: list[BB] = []
    for idx, (s, e) in enumerate(zip(starts, ends)):
        lines = body_lines[s:e]
        lbl   = None
        if lines:
            m = LABEL_RE.match(lines[0])
            if m:
                lbl = m.group(2)
        bbs.append(BB(idx=idx, label=lbl, lines=lines))

    # Assign successors
    for idx, bb in enumerate(bbs):
        non_empty = [l.strip() for l in bb.lines
                     if l.strip() and not l.strip().startswith('//')]
        if not non_empty:
            _add_fallthrough(bb, bbs, idx)
            continue

        last = non_empty[-1]
        prev = non_empty[-2] if len(non_empty) >= 2 else ''

        m_goto = GOTO_RE.search(last)
        if m_goto:
            target = m_goto.group(1)
            # Conditional if branch: previous line is the if test
            # Switch case branch: the goto line itself starts with 'case'
            is_cond = (prev.startswith('if (') or prev.startswith('if(') or
                       re.match(r'\s*case\b', last))
            bb.successors.append(target)
            if is_cond:
                _add_fallthrough(bb, bbs, idx)
        elif RETURN_RE.search(last):
            bb.successors.append('__exit__')
        elif STOP_RE.search(last):
            bb.successors.append('__exit__')
            bb.stop_exit = True
        elif last.strip() == '}' and STOP_RE.search(prev):
            # switch default: stop("..."); }  — closing brace follows stop()
            bb.successors.append('__exit__')
            bb.stop_exit = True
        else:
            _add_fallthrough(bb, bbs, idx)

    return bbs


def _add_fallthrough(bb: BB, bbs: list[BB], idx: int) -> None:
    if idx + 1 < len(bbs):
        bb.successors.append(_bb_key(bbs[idx + 1]))
    else:
        bb.successors.append('__exit__')   # falls off the end of the function


# ---------------------------------------------------------------------------
# Step 2 – Compute FPU delta per BB
# ---------------------------------------------------------------------------

def compute_bb_fpu(bb: BB, sigs: dict) -> None:
    depth = 0
    for line in bb.lines:
        m = FPU_CALL_RE.search(line)
        if m:
            delta = FPU_DELTA.get(m.group('op'), 0)
            depth += delta
            bb.rel_min = min(bb.rel_min, depth)
            bb.rel_max = max(bb.rel_max, depth)

        m_cs = re.search(r'\b(sub_[0-9a-fA-F]+)\s*\(\s*\)\s*;', line)
        if m_cs and m_cs.group(1) in sigs:
            ni, no = sigs[m_cs.group(1)]
            depth += (no - ni)
            bb.rel_min = min(bb.rel_min, depth)
            bb.rel_max = max(bb.rel_max, depth)

    bb.delta = depth


# ---------------------------------------------------------------------------
# Step 3 – BFS depth propagation
# ---------------------------------------------------------------------------

class FpuConflictError(Exception):
    pass


def propagate_depths(bbs: list[BB], n_in: int) -> None:
    """
    BFS from entry BB.  Raises FpuConflictError if any join-point has
    predecessors with different FPU depths.
    """
    label_map: dict[str, int] = {}
    for bb in bbs:
        label_map[_bb_key(bb)] = bb.idx
        if bb.label:
            label_map[bb.label] = bb.idx

    bbs[0].entry_depth = 0
    queue = deque([0])
    visited: set[int] = set()
    conflicts: list[str] = []

    while queue:
        idx = queue.popleft()
        if idx in visited:
            continue
        visited.add(idx)

        bb = bbs[idx]
        if bb.entry_depth is None:
            continue

        exit_depth = bb.entry_depth + bb.delta

        for succ_key in bb.successors:
            if succ_key == '__exit__':
                continue
            succ_idx = label_map.get(succ_key)
            if succ_idx is None:
                continue
            succ = bbs[succ_idx]
            if succ.entry_depth is None:
                succ.entry_depth = exit_depth
                queue.append(succ_idx)
            elif succ.entry_depth != exit_depth:
                src_lbl  = bb.label or f'entry'
                dst_lbl  = succ.label or f'bb{succ_idx}'
                msg = (f"at {dst_lbl}: incoming depth {exit_depth} "
                       f"(from {src_lbl}) conflicts with "
                       f"established depth {succ.entry_depth}")
                if msg not in conflicts:
                    conflicts.append(msg)
                succ.conflict = msg
                # Still propagate the established depth to avoid cascade noise
                if succ_idx not in visited:
                    queue.append(succ_idx)

    if conflicts:
        raise FpuConflictError("; ".join(conflicts))


# ---------------------------------------------------------------------------
# Step 4 – Compute ring size N
# ---------------------------------------------------------------------------

def compute_ring_size(bbs: list[BB], n_in: int) -> int:
    """N = maximum absolute FPU depth reached across all reachable BBs."""
    peak = n_in  # at minimum we need the n_in input slots
    for bb in bbs:
        if bb.entry_depth is None:
            continue
        abs_max = n_in + bb.entry_depth + bb.rel_max
        peak = max(peak, abs_max)
    return peak  # slots 0 … peak-1


# ---------------------------------------------------------------------------
# Step 5 – Code generation using the fixed ring
# ---------------------------------------------------------------------------

class RingState:
    """Mutable state threaded through the per-line emitter."""
    def __init__(self, n_in: int, N: int, sigs: dict):
        self.n_in  = n_in
        self.N     = N
        self.sigs  = sigs
        self.depth = 0          # depth counter (0 = n_in items pre-loaded)
        self.pending_cmp = None # (cid, lhs, rhs, ls_save, rs_save)
        self.cmp_counter = 0
        self.fpu_out = 0
        self.cmp_vars: list[str] = []  # cmp temp names, hoisted to top of function
        # Precision tracking per ring variable
        self.slot_prec: dict[str, str] = {}   # current precision of each slot
        self.decl_prec: dict[str, str] = {}   # worst-case (double is sticky)
        # Input parameters assumed double (conservative)
        for i in range(n_in):
            vname = f'fp{i}'
            self.slot_prec[vname] = 'double'
            self.decl_prec[vname] = 'double'

    def _gp(self, var: str) -> str:
        """Get precision of a ring variable ('float' by default)."""
        return self.slot_prec.get(var, 'float')

    def _sp(self, var: str, prec: str) -> None:
        """Set precision; decl_prec widens monotonically (double is sticky)."""
        self.slot_prec[var] = prec
        if prec == 'double' or var not in self.decl_prec:
            self.decl_prec[var] = prec

    def _mp(self, *args: str) -> str:
        """Merge precisions: 'double' beats 'float'."""
        for a in args:
            p = a if a in ('float', 'double') else self.slot_prec.get(a, 'float')
            if p == 'double':
                return 'double'
        return 'float'

    # ---- slot naming -------------------------------------------------------

    def slot(self, k: int = 0, d: Optional[int] = None) -> str:
        """Variable name for ST(k) at depth-counter d (default: current)."""
        if d is None:
            d = self.depth
        return f"fp{(self.n_in + d - 1 - k) % self.N}"

    def stack_str(self) -> str:
        total = self.n_in + self.depth
        if total <= 0:
            return "[empty]"
        names = [self.slot(k) for k in range(total)]
        return "[" + ", ".join(names) + "]"

    # ---- pending-comparison capture ----------------------------------------

    def capture(self, var: str, indent: str) -> list[str]:
        """If var is a pending-cmp operand about to be overwritten, save it."""
        if self.pending_cmp is None:
            return []
        cid, lhs, rhs, ls, rs = self.pending_cmp
        out = []
        if var == lhs and ls is None:
            ls = f'_cmp{cid}l'
            self.pending_cmp = (cid, lhs, rhs, ls, rs)
            self.cmp_vars.append(ls)
            out.append(f'{indent}{ls} = {var};')
        elif var == rhs and rs is None:
            rs = f'_cmp{cid}r'
            self.pending_cmp = (cid, lhs, rhs, ls, rs)
            self.cmp_vars.append(rs)
            out.append(f'{indent}{rs} = {var};')
        return out


# ---------------------------------------------------------------------------
# FPU op emitter
# ---------------------------------------------------------------------------

_FPVAR_RE  = re.compile(r'^fp\d+$')
_STIDX_RE  = re.compile(r'^\s*st\s*\(\s*(\d+)\s*\)\s*$', re.IGNORECASE)


def _stidx(arg: str) -> int:
    """Parse 'N' or 'st(N)' → integer N."""
    m = _STIDX_RE.match(arg)
    return int(m.group(1)) if m else int(arg)


def emit_fpu_op(op: str, args: list[str], orig: str,
                line: str, st: RingState) -> list[str]:
    indent = re.match(r'(\s*)', line).group(1)
    d = st.depth          # depth BEFORE this op

    def cmt() -> str:
        return f" // {orig} fpustack: {st.stack_str()}"

    def sor(expr: str, pre: list[str] | None = None) -> list[str]:
        """store-or-assign: try memoryFSet rewrite first, else bare assignment."""
        out = list(pre or [])
        if "memoryASet" in line:
            rw = rewrite_store_line(line, expr)
            if rw != line:
                return out + [indent + rw + cmt()]
        return out + [f"{indent}{expr};{cmt()}"]

    # ---- LOADS (push) -------------------------------------------------------

    if op in ('fld32', 'fld64', 'fld80'):
        dst = st.slot(0, d + 1)
        pre = st.capture(dst, indent)
        st.depth += 1
        st._sp(dst, 'float' if op == 'fld32' else 'double')
        return sor(f"{dst} = {mem_float_get(op, args[0])}", pre)

    if op == 'fldz':
        dst = st.slot(0, d + 1); pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, 'float')
        return sor(f"{dst} = 0.0f", pre)

    if op == 'fld1':
        dst = st.slot(0, d + 1); pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, 'float')
        return sor(f"{dst} = 1.0f", pre)

    if op == 'fldpi':
        dst = st.slot(0, d + 1); pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, 'double')
        return sor(f"{dst} = M_PI", pre)

    _LDCONST = {'fldln2': 'M_LN2', 'fldl2e': '1.4426950408889634',
                'fldl2t': '3.321928094887362', 'fldlg2': '0.3010299956639812'}
    if op in _LDCONST:
        dst = st.slot(0, d + 1); pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, 'double')
        return sor(f"{dst} = {_LDCONST[op]}", pre)

    if op == 'fldst':
        src = st.slot(_stidx(args[0]))     # ST(k) BEFORE push
        dst = st.slot(0, d + 1)
        pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, st._gp(src))
        return sor(f"{dst} = {src}", pre)

    _ILDCAST = {'fild16': 'int16_t', 'fild32': 'int32_t', 'fild64': 'int64_t'}
    if op in _ILDCAST:
        dst = st.slot(0, d + 1); pre = st.capture(dst, indent); st.depth += 1
        st._sp(dst, 'double' if op == 'fild64' else 'float')
        return sor(f"{dst} = (double)({_ILDCAST[op]}){args[0]}", pre)

    # ---- STORES (pop) -------------------------------------------------------

    if op in ('fstp32', 'fstp64', 'fstp80'):
        src = st.slot(0); st.depth -= 1
        return sor(src)

    if op in ('fst32', 'fst64'):
        return sor(st.slot(0))

    if op == 'fstpst':
        i = _stidx(args[0])
        src = st.slot(0)
        if i == 0:
            st.depth -= 1
            return [f"{indent}// {orig} (pop) fpustack: {st.stack_str()}"]
        dst = st.slot(i)
        src_prec = st._gp(src)
        pre = st.capture(dst, indent)
        st._sp(dst, src_prec)
        st.depth -= 1
        return pre + [f"{indent}{dst} = {src};{cmt()}"]

    # ---- FISTP --------------------------------------------------------------

    if op in ('fistp32', 'fistp16'):
        w   = '32' if op == 'fistp32' else '16'
        src = st.slot(0); st.depth -= 1
        expr = f"(int{w}_t)floor({src})"
        if "memoryASet" in line:
            rw = rewrite_fistp_store(line, expr, w)
            if rw:
                return [indent + rw + cmt()]
        return [f"{indent}{expr};{cmt()}"]

    if op == 'fistp64':
        src = st.slot(0); st.depth -= 1
        expr = f"(int64_t)floor({src})"
        if "memoryASet" in line:
            rw = rewrite_fistp_store(line, expr, '64')
            if rw:
                return [indent + rw + cmt()]
        return [f"{indent}{expr};{cmt()}"]

    # ---- ARITHMETIC: ST(0) OP= mem ------------------------------------------

    _MEM_OPS = {
        'fadd32': '{d} += {s}', 'fadd64': '{d} += {s}',
        'fsub32': '{d} -= {s}', 'fsub64': '{d} -= {s}',
        'fsubr32': '{d} = {s} - {d}', 'fsubr64': '{d} = {s} - {d}',
        'fmul32': '{d} *= {s}', 'fmul64': '{d} *= {s}',
        'fdiv32': '{d} /= {s}', 'fdiv64': '{d} /= {s}',
        'fdivr32': '{d} = {s} / {d}', 'fdivr64': '{d} = {s} / {d}',
    }
    if op in _MEM_OPS:
        dst = st.slot(0)
        src = mem_float_get(op, args[0])
        pre = st.capture(dst, indent)
        st._sp(dst, st._mp(dst, 'float' if op.endswith('32') else 'double'))
        return sor(_MEM_OPS[op].format(d=dst, s=src), pre)

    # ---- INTEGER ARITHMETIC -------------------------------------------------

    _ICAST = {'fimul32': 'int32_t', 'fimul16': 'int16_t',
              'fiadd32': 'int32_t', 'fiadd16': 'int16_t'}
    _ITPL  = {'fimul32': '{d} *= (double)({c}){s}', 'fimul16': '{d} *= (double)({c}){s}',
              'fiadd32': '{d} += (double)({c}){s}', 'fiadd16': '{d} += (double)({c}){s}'}
    if op in _ICAST:
        dst = st.slot(0); pre = st.capture(dst, indent)
        return sor(_ITPL[op].format(d=dst, c=_ICAST[op], s=args[0]), pre)

    # ---- ARITHMETIC: ST(0) OP= ST(k), no pop --------------------------------

    _ST_OPS = {
        'faddst':  '{d} += {s}',  'fsubst':  '{d} -= {s}',
        'fsubrst': '{d} = {s} - {d}',
        'fmulst':  '{d} *= {s}',  'fdivst':  '{d} /= {s}',
        'fdivrst': '{d} = {s} / {d}',
        'fdivr80': '{d} = {s} / {d}',           # FDIVR extended — same as fdivrst
    }
    if op in _ST_OPS:
        dst = st.slot(0); src = st.slot(_stidx(args[0]))
        pre = st.capture(dst, indent)
        st._sp(dst, st._mp(dst, src))
        return sor(_ST_OPS[op].format(d=dst, s=src), pre)

    # ---- ARITHMETIC: ST(i) OP= ST(j), no pop (DC forms) --------------------

    _DC_OPS = {
        'fmulst2': '{d} *= {s}', 'faddst2': '{d} += {s}',
        'fsubst2': '{d} -= {s}', 'fdivst2': '{d} /= {s}',
        'fsubrst2': '{d} = {s} - {d}',
    }
    if op in _DC_OPS:
        i, j = _stidx(args[0]), _stidx(args[1])
        dst = st.slot(i); src = st.slot(j)
        pre = st.capture(dst, indent)
        st._sp(dst, st._mp(dst, src))
        return sor(_DC_OPS[op].format(d=dst, s=src), pre)

    # ---- ARITHMETIC with pop: ST(i) OP= ST(0); pop --------------------------

    _PST_OPS = {
        'fmulpst':  '{d} *= {s}',  'faddpst':  '{d} += {s}',
        'fsubpst':  '{d} -= {s}',  'fsubrpst': '{d} = {s} - {d}',
        'fdivpst':  '{d} /= {s}',  'fdivrpst': '{d} = {s} / {d}',
        'fdivp80':  '{d} /= {s}',                # FDIVP ST(i),ST — same as fdivpst
    }
    if op in _PST_OPS:
        i   = _stidx(args[0])
        src = st.slot(0)          # ST(0) = will be popped
        dst = st.slot(i)          # ST(i) = receives result
        new_prec = st._mp(dst, src)
        pre = st.capture(dst, indent)
        st.depth -= 1
        st._sp(dst, new_prec)
        return pre + [f"{indent}{_PST_OPS[op].format(d=dst, s=src)};{cmt()}"]

    # ---- UNARY --------------------------------------------------------------

    _UNARY = {
        # (double_tpl, float_tpl)
        'fabs':  ('{d} = fabs({d})',  '{d} = fabsf({d})'),
        'fchs':  ('{d} = -{d}',       '{d} = -{d}'),
        'fsqrt': ('{d} = sqrt({d})',   '{d} = sqrtf({d})'),
        'fsin':  ('{d} = sin({d})',    '{d} = sinf({d})'),
        'fcos':  ('{d} = cos({d})',    '{d} = cosf({d})'),
    }
    if op in _UNARY:
        dst = st.slot(0); pre = st.capture(dst, indent)
        tpl = _UNARY[op][1] if st._gp(dst) == 'float' else _UNARY[op][0]
        return sor(tpl.format(d=dst), pre)

    # ---- EXCHANGE: physical swap --------------------------------------------

    if op == 'fxchst2':
        i, j = _stidx(args[0]), _stidx(args[1])
        a, b = st.slot(i), st.slot(j)
        if a == b:
            return [f"{indent}// {orig} (no-op self-swap) fpustack: {st.stack_str()}"]
        pa, pb = st._gp(a), st._gp(b)
        st._sp(a, pb); st._sp(b, pa)
        return [f"{indent}{{ double _xchg = {a}; {a} = {b}; {b} = _xchg; }}"
                f"  // {orig} fpustack: {st.stack_str()}"]

    # ---- COMPARE ops --------------------------------------------------------

    def do_cmp(lhs: str, rhs: str, pop_count: int) -> list[str]:
        cid = st.cmp_counter; st.cmp_counter += 1
        ls  = None if _FPVAR_RE.match(lhs) else f'_cmp{cid}l'
        rs  = None if _FPVAR_RE.match(rhs) else f'_cmp{cid}r'
        st.depth -= pop_count
        st.pending_cmp = (cid, lhs, rhs, ls, rs)
        out = []
        if ls: st.cmp_vars.append(ls); out.append(f'{indent}{ls} = {lhs};')
        if rs: st.cmp_vars.append(rs); out.append(f'{indent}{rs} = {rhs};')
        note = f' [cmp_{cid}]' if (ls or rs) else ''
        out.append(f'{indent}// {orig} fpustack: {st.stack_str()}{note}')
        return out

    if op == 'fcomst':
        return do_cmp(st.slot(0), st.slot(_stidx(args[0])), 0)
    if op == 'fcompst':
        return do_cmp(st.slot(0), st.slot(_stidx(args[0])), 1)
    if op == 'fcompp':
        return do_cmp(st.slot(0), st.slot(1), 2)
    if op in ('fcom32', 'fcomp32'):
        rhs = f"(double)fromFp32({args[0]})"
        return do_cmp(st.slot(0), rhs, 1 if op == 'fcomp32' else 0)
    if op in ('fcom64', 'fcomp64'):
        rhs = mem_float_get('64', args[0])
        return do_cmp(st.slot(0), rhs, 1 if op == 'fcomp64' else 0)
    if op in ('fcom80', 'fcomp80'):
        return do_cmp(st.slot(0), args[0], 1 if op == 'fcomp80' else 0)

    raise RuntimeError(f"Unsupported FPU op: {op!r}")


# ---------------------------------------------------------------------------
# Per-line emitter
# ---------------------------------------------------------------------------

def emit_line(line: str, st: RingState,
              label_to_bb: dict, bbs: list[BB]) -> list[str]:
    """Translate one source line; returns list of output lines."""
    indent = re.match(r'(\s*)', line).group(1)

    # ---- Label: snap depth to CFG-determined entry depth -------------------
    m_lbl = LABEL_RE.match(line)
    if m_lbl:
        lbl = m_lbl.group(2)
        bb_idx = label_to_bb.get(lbl)
        if bb_idx is not None:
            bb = bbs[bb_idx]
            if bb.entry_depth is not None:
                st.depth = bb.entry_depth   # always safe — propagation resolved this
        return [line]

    # ---- fnstsw: drop when comparison is pending ---------------------------
    if FNSTSW_RE.search(line):
        return [] if st.pending_cmp is not None else [line]

    # ---- if-condition: resolve pending comparison --------------------------
    if st.pending_cmp is not None:
        cid, lhs, rhs, ls, rs = st.pending_cmp
        m_po = PARITYODD_RE.search(line)
        m_ah = AH_MASK_RE.search(line) if not m_po else None
        if m_po or m_ah:
            st.pending_cmp = None
            use_lhs = ls if ls is not None else lhs
            use_rhs = rs if rs is not None else rhs
            if m_po:
                cond = resolve_cond(use_lhs, use_rhs,
                                    m_po.group('mask'),
                                    bool(m_po.group('neg')), True)
                if cond:
                    s, e = m_po.start(), m_po.end()
                    # When neg is present the close paren closes the !(  which we
                    # are removing; the if-condition's own ) survives in line[e:].
                    # When neg is absent, close carries the if-condition's ) which
                    # was consumed by the regex and must be re-inserted.
                    close = '' if m_po.group('neg') else (m_po.group('close') or '')
                    return [(line[:s] + cond + close + line[e:]).rstrip()
                            + f"  // {lhs} vs {rhs}"]
            else:
                cond = resolve_cond(use_lhs, use_rhs,
                                    m_ah.group(1), False, False)
                if cond:
                    s, e = m_ah.start(), m_ah.end()
                    return [(line[:s] + cond + line[e:]).rstrip()
                            + f"  // {lhs} vs {rhs}"]

    # ---- call-site expansion -----------------------------------------------
    m_cs = re.match(r'^(\s*)(sub_[0-9a-fA-F]+)\s*\(\s*\)\s*;', line)
    if m_cs and m_cs.group(2) in st.sigs:
        fn = m_cs.group(2); ci = m_cs.group(1)
        ni, no = st.sigs[fn]
        d = st.depth
        # args consumed: ST(0)..ST(ni-1)
        args_str = ', '.join(st.slot(k) for k in range(ni))
        st.depth -= ni
        rets = [st.slot(0, st.depth + j + 1) for j in range(no)]
        st.depth += no
        cmt = f'  // fpustack: {st.stack_str()}'
        if no == 0:
            return [f'{ci}{fn}({args_str});{cmt}']
        if no == 1:
            return [f'{ci}{rets[0]} = {fn}({args_str});{cmt}']
        return [f'{ci}auto [{", ".join(rets)}] = {fn}({args_str});{cmt}']

    # ---- explicit return with FPU output -----------------------------------
    if st.fpu_out > 0 and re.match(r'\s*return\s*;\s*$', line):
        if st.fpu_out == 1:
            return [f'{indent}return {st.slot(0)};']
        vals = ', '.join(st.slot(k) for k in range(st.fpu_out - 1, -1, -1))
        return [f'{indent}return {{{vals}}};']

    # ---- FPU instruction ---------------------------------------------------
    m_fpu = FPU_CALL_RE.search(line)
    if m_fpu:
        op   = m_fpu.group('op')
        args = split_args(m_fpu.group('args'))
        orig = m_fpu.group(0)
        try:
            return emit_fpu_op(op, args, orig, line, st)
        except Exception as exc:
            return [line + f"  // TRANSFORM ERROR: {exc}"]

    return [line]


# ---------------------------------------------------------------------------
# infer_proto() — deduce (n_in, n_out) from a function body + sigs
# ---------------------------------------------------------------------------

def infer_proto(src: str, sigs: dict) -> tuple[int, int]:
    """
    Infer (n_in, n_out) for a function whose balance was previously UNKNOWN
    because some callee sigs were missing.  Now that sigs is populated, we
    re-run the CFG analysis and deduce the proto.

    Raises FpuConflictError  if join-point depths disagree (still ambiguous).
    Raises ValueError        if no exit found, or n_out would be negative.
    """
    lines   = src.split('\n')
    open_b  = next((i for i, l in enumerate(lines) if l.strip() == '{'), None)
    close_b = next((i for i in range(len(lines) - 1, -1, -1)
                    if lines[i].strip() == '}'), None)
    if open_b is None or close_b is None:
        raise ValueError("cannot parse function body")

    body_lines = lines[open_b + 1: close_b]
    bbs = parse_basic_blocks(body_lines)
    for bb in bbs:
        compute_bb_fpu(bb, sigs)

    # propagate with entry at relative depth 0; raises FpuConflictError on mismatch
    propagate_depths(bbs, 0)

    # find global minimum relative depth and collect exit depths
    global_min  = 0
    exit_depths: list[int] = []

    for bb in bbs:
        if bb.entry_depth is None:
            continue
        global_min = min(global_min, bb.entry_depth + bb.rel_min)
        for succ in bb.successors:
            if succ == '__exit__' and not bb.stop_exit:
                exit_depths.append(bb.entry_depth + bb.delta)

    if not exit_depths:
        raise ValueError("no exit point found in function")

    unique_exits = set(exit_depths)
    if len(unique_exits) > 1:
        raise FpuConflictError(
            f"inconsistent exit depths across return sites: {sorted(unique_exits)}")

    exit_depth = exit_depths[0]
    n_in  = max(0, -global_min)
    n_out = n_in + exit_depth

    if n_out < 0:
        raise ValueError(f"inferred invalid proto: n_in={n_in}, exit_depth={exit_depth}")

    return n_in, n_out


# ---------------------------------------------------------------------------
# Top-level transform()
# ---------------------------------------------------------------------------

def transform(src: str,
              proto: tuple[int, int] = (0, 0),
              sigs:  dict | None = None,
              _stats: dict | None = None) -> str:
    """
    Transform a single function.
    Raises FpuConflictError if any CFG join-point has a depth mismatch.
    If _stats is a dict, increments _stats['float'] and _stats['double'] with
    the count of local variables declared as each type.
    """
    sigs = sigs or {}
    n_in, n_out = proto

    # --- extract body -------------------------------------------------------
    lines = src.split('\n')
    open_b = next((i for i, l in enumerate(lines) if l.strip() == '{'), None)
    close_b = next((i for i in range(len(lines) - 1, -1, -1)
                    if lines[i].strip() == '}'), None)
    if open_b is None or close_b is None:
        return src  # can't parse

    header     = '\n'.join(lines[:open_b + 1])
    body_lines = lines[open_b + 1: close_b]
    footer     = '\n'.join(lines[close_b:])

    # --- build and analyse BBs ---------------------------------------------
    bbs = parse_basic_blocks(body_lines)
    for bb in bbs:
        compute_bb_fpu(bb, sigs)

    propagate_depths(bbs, n_in)   # raises FpuConflictError on mismatch

    N = compute_ring_size(bbs, n_in)
    if N == 0:
        return src   # no FPU ops — should not reach here, but be safe

    # --- label → BB index mapping ------------------------------------------
    label_to_bb: dict[str, int] = {}
    for bb in bbs:
        if bb.label:
            label_to_bb[bb.label] = bb.idx

    # --- code generation ---------------------------------------------------
    st = RingState(n_in=n_in, N=N, sigs=sigs)
    st.fpu_out = n_out
    out_lines: list[str] = []

    for line in body_lines:
        out_lines.extend(emit_line(line, st, label_to_bb, bbs))

    body_out = '\n'.join(out_lines)

    # --- variable declarations ---------------------------------------------
    # fp0..fp{n_in-1} are parameters; fp{n_in}..fp{N-1} are locals
    local_vars = [f"fp{i}" for i in range(n_in, N)]
    decls = []
    if local_vars:
        float_vars  = [v for v in local_vars if st.decl_prec.get(v, 'float') == 'float']
        double_vars = [v for v in local_vars if st.decl_prec.get(v, 'float') == 'double']
        if double_vars:
            decls.append("    double " + ", ".join(double_vars) + ";")
        if float_vars:
            decls.append("    float "  + ", ".join(float_vars)  + ";")
        if _stats is not None:
            _stats['float']  = _stats.get('float',  0) + len(float_vars)
            _stats['double'] = _stats.get('double', 0) + len(double_vars)
    # cmp temps hoisted to top to avoid goto-crosses-initialization errors
    if st.cmp_vars:
        decls.append("    double " + ", ".join(st.cmp_vars) + ";")
    if decls:
        body_out = "\n".join(decls) + "\n" + body_out

    # --- function signature rewrite (proto != 0:0) -------------------------
    if n_in > 0 or n_out > 0:
        params = ', '.join(f'double fp{i}' for i in range(n_in))
        ret    = ('void'   if n_out == 0 else
                  'double' if n_out == 1 else 'std::pair<double,double>')
        _SIG_RE = re.compile(r'^void\s+(sub_[0-9a-fA-F]+)\s*\(\s*\)', re.MULTILINE)
        header = _SIG_RE.sub(lambda m: f'{ret} {m.group(1)}({params})', header, count=1)

        # inject fall-off-end return if needed
        if n_out > 0:
            body_lines_out = body_out.split('\n')
            for i in range(len(body_lines_out) - 1, -1, -1):
                if body_lines_out[i].strip():
                    if not re.match(r'\s*return\b', body_lines_out[i]):
                        ret_var = st.slot(0) if st.depth >= 1 else 'fp0'
                        body_lines_out.insert(i + 1, f'    return {ret_var};')
                    break
            body_out = '\n'.join(body_lines_out)

    return header + "\n" + body_out + "\n" + footer


# ---------------------------------------------------------------------------
# CLI for standalone testing
# ---------------------------------------------------------------------------

if __name__ == '__main__':
    import argparse, json

    ap = argparse.ArgumentParser()
    ap.add_argument('input')
    ap.add_argument('--fpu-proto', default='0:0')
    ap.add_argument('--sigs', default=None)
    a = ap.parse_args()

    fpu_in, fpu_out = (int(x) for x in a.fpu_proto.split(':'))
    sigs = {}
    if a.sigs:
        raw = json.loads(Path(a.sigs).read_text())
        sigs = {k: tuple(v) for k, v in raw.items()}

    src = Path(a.input).read_text()
    try:
        print(transform(src, proto=(fpu_in, fpu_out), sigs=sigs))
    except FpuConflictError as e:
        print(f"// FPU CONFLICT: {e}", file=sys.stderr)
        sys.exit(1)
