#!/usr/bin/env python3
"""
transform2.py — Phase-1 FPU-emulation → native-double transformer.

Processes one balanced (simple:true) C++ source function at a time.
Each FPU instruction call is replaced with equivalent native-double code.
All double variables are declared at the top of the function.
Comparison save temps (_cmpNl/_cmpNr) are declared inline at the compare site.

Usage:
    python3 transform2.py in_XXXXXX.cpp > ref_XXXXXX.cpp
"""

import argparse
import re
from pathlib import Path

# ---------------------------------------------------------------------------
# Regex: every FPU call we handle
# ---------------------------------------------------------------------------

FPU_CALL_RE = re.compile(
    r"""
    (?:
        \bfpuinsns\s*::\s*
      | \b
    )
    (?P<op>
        fld32|fld64|fld80|fldz|fld1|fldpi|fldln2|fldl2e|fldl2t|fldlg2|
        fild16|fild32|fild64|
        fistp32|fistp64|fistp16|
        fst32|fst64|fstp32|fstp64|fstp80|fstpst|
        fadd32|fadd64|fsub32|fsub64|fsubr32|fsubr64|
        fmul32|fmul64|fdiv32|fdiv64|fdivr32|fdivr64|
        faddst|fsubst|fsubrst|fmulst|fdivst|fdivrst|
        fmulst2|faddst2|fsubst2|fdivst2|fsubrst2|
        faddpst|fsubpst|fsubrpst|fmulpst|fdivpst|fdivrpst|fdivp80|
        fdivr80|
        fimul32|fimul16|fiadd32|fiadd16|
        fldst|
        fabs|fchs|fsqrt|fsin|fcos|
        fcom32|fcom64|fcom80|fcomp32|fcomp64|fcomp80|
        fcomst|fcompst|fcompp|
        fxchst2
    )
    \s*\(
    (?P<args>[^;]*)
    \)
    """,
    re.VERBOSE,
)

# Multi-line FPU status patterns
FNSTSW_RE   = re.compile(r'\bfnstsw\s*\(\s*\)')
PARITYODD_RE = re.compile(
    r'(?P<neg>!\s*\()?\s*parityOdd\s*\(\s*ah\s*,\s*(?P<mask>0x[0-9a-fA-F]+)\s*\)\s*(?P<close>\))?'
)
AH_MASK_RE  = re.compile(r'ah\s*&\s*(0x[0-9a-fA-F]+)')

# ---------------------------------------------------------------------------

def split_args(text: str) -> list[str]:
    args, cur, depth = [], [], 0
    for ch in text:
        if ch == ',' and depth == 0:
            args.append(''.join(cur).strip())
            cur = []
            continue
        cur.append(ch)
        if ch in '([{':
            depth += 1
        elif ch in ')]}':
            depth -= 1
    if s := ''.join(cur).strip():
        args.append(s)
    return args

# ---------------------------------------------------------------------------
# FPU stack model
# ---------------------------------------------------------------------------

class FpuStack:
    def __init__(self, initial_depth: int = 0, typed: bool = False):
        self.stack:     list[str]      = []
        self.next_id:   int            = 0
        self.declared:  list[str]      = []   # fp* vars for function-top decl
        self.pending_cmp               = None # (cmp_id, lhs, rhs, lhs_save, rhs_save)
        self.cmp_counter: int          = 0
        self.typed:     bool           = typed
        self.precision: dict[str, str] = {}   # var → "float" | "double"
        self.sigs:      dict[str, tuple[int,int]] = {}  # callee→(n_in,n_out)
        self.fpu_out:   int            = 0    # items to return at function exit

        for i in range(initial_depth):
            name = f"fp_in{i}"
            self.stack.append(name)
            self.declared.append(name)

    def push_new(self) -> str:
        name = f"fp{self.next_id}"
        self.next_id += 1
        self.stack.insert(0, name)
        self.declared.append(name)
        return name

    def pop(self) -> str:
        if not self.stack:
            raise RuntimeError("FPU stack underflow")
        return self.stack.pop(0)

    def st(self, i: int) -> str:
        if i >= len(self.stack):
            raise RuntimeError(
                f"FPU stack underflow: st({i}) requested but depth={len(self.stack)}"
            )
        return self.stack[i]

    def swap(self, i: int, j: int):
        self.stack[i], self.stack[j] = self.stack[j], self.stack[i]

    def stack_str(self) -> str:
        return "[" + ", ".join(self.stack) + "]" if self.stack else "[empty]"

    # ---- precision helpers (no-ops when typed=False) -----------------------

    def get_prec(self, var: str) -> str:
        return self.precision.get(var, "double") if self.typed else "double"

    def set_prec(self, var: str, prec: str) -> None:
        if self.typed:
            self.precision[var] = prec

    @staticmethod
    def merge_prec(p1: str, p2: str) -> str:
        """Widest of two precisions: float+float→float, anything else→double."""
        return "float" if p1 == "float" and p2 == "float" else "double"

# ---------------------------------------------------------------------------
# Memory-operand helpers
# ---------------------------------------------------------------------------

def mem_float_get(op: str, expr: str) -> str:
    """Replace memoryAGetNN with memoryFGetNN for float reads."""
    if "64" in op:
        return expr.replace("memoryAGet64", "memoryFGet64")
    if "32" in op:
        return expr.replace("memoryAGet32", "memoryFGet32")
    return expr

def _prec_mem(op_name: str) -> str:
    """Precision of a memory operand based on the op suffix (32→float, else double)."""
    return "float" if "32" in op_name else "double"

def rewrite_store_line(line: str, value: str) -> str:
    """Rewrite a memoryASetNN(..., fst/fstpNN()) call to memoryFSetNN(...)."""
    m = re.search(
        r"memoryASet(?P<w>32|64)\s*\((?P<args>.*?),\s*fstp?(?P=w)\s*\(\s*\)\s*\)",
        line,
    )
    if m:
        return f"memoryFSet{m.group('w')}({m.group('args')}, {value});"
    return line  # fallback: caller will emit raw expression

def rewrite_fistp_store(line: str, value: str, w: str) -> str | None:
    """Rewrite memoryASetNN(..., fistpNN()) to keep memoryASetNN with int cast."""
    pat = rf"memoryASet{w}\s*\((.*?),\s*fistp{w}\s*\(\s*\)\s*\)"
    m = re.search(pat, line)
    if m:
        return f"memoryASet{w}({m.group(1)}, {value});"
    return None

# ---------------------------------------------------------------------------
# Comparison-condition resolver
# ---------------------------------------------------------------------------

# parityOdd(ah, mask) semantics (from emulate_fnstsw_compare):
#   a < b  → C0=1  → AH bit-0 = 1
#   a == b → C3=1  → AH bit-6 = 1
#   a > b  → all zero
# parityOdd(value, mask) = popcount(value & mask) is odd
#   0x05 (bits 0+2):  only C0 set → a < b        → parityOdd=True
#   0x41 (bits 0+6):  C0 or C3   → a <= b        → parityOdd=True
#   0x44 (bits 2+6):  only C3    → a == b        → parityOdd=True
# Direct ah & mask:
#   0x01  → C0 set → a < b
#   0x40  → C3 set → a == b
#   0x41  → C0|C3  → a <= b

_PARITY_OPS = {
    0x05: ("<",  ">="),   # parityOdd / !parityOdd
    0x41: ("<=", ">" ),
    0x44: ("==", "!="),
}
_AH_OPS = {
    0x01: ("<",  ">="),
    0x40: ("==", "!="),
    0x41: ("<=", ">" ),
    0x44: ("==", "!="),
}

def resolve_cond(lhs: str, rhs: str, mask_str: str, negated: bool,
                 is_parity: bool) -> str | None:
    mask = int(mask_str, 16)
    table = _PARITY_OPS if is_parity else _AH_OPS
    if mask not in table:
        return None
    pos_op, neg_op = table[mask]
    op = neg_op if negated else pos_op
    return f"{lhs} {op} {rhs}"

# ---------------------------------------------------------------------------
# Core FPU-op emitter
# ---------------------------------------------------------------------------

def emit_fpu_op(
    op: str, args: list[str], orig_call: str, line: str, fpu: FpuStack
) -> list[str]:
    """Return list of output lines for one FPU instruction."""
    indent = re.match(r'(\s*)', line).group(1)

    def cmt() -> str:
        return f" // {orig_call} fpustack: {fpu.stack_str()}"

    def store_or_assign(expr: str) -> list[str]:
        """Emit a store line (memoryFSetNN) or bare assignment."""
        if "memoryASet" in line:
            rewritten = rewrite_store_line(line, expr)
            if rewritten != line:
                return [indent + rewritten + cmt()]
        return [f"{indent}{expr};{cmt()}"]

    def _capture_if_pending(var: str) -> list[str]:
        """Lazily capture a pending-comparison operand before it gets overwritten."""
        if fpu.pending_cmp is None:
            return []
        cid2, lhs2, rhs2, ls2, rs2 = fpu.pending_cmp
        if var == lhs2 and ls2 is None:
            ls2 = f'_cmp{cid2}l'
            fpu.pending_cmp = (cid2, lhs2, rhs2, ls2, rs2)
            return [f'{indent}double {ls2} = {var};']
        if var == rhs2 and rs2 is None:
            rs2 = f'_cmp{cid2}r'
            fpu.pending_cmp = (cid2, lhs2, rhs2, ls2, rs2)
            return [f'{indent}double {rs2} = {var};']
        return []

    # ---- LOADS (push) -------------------------------------------------------

    if op in ("fld32", "fld64", "fld80"):
        dst = fpu.push_new()
        fpu.set_prec(dst, "float" if op == "fld32" else "double")
        return store_or_assign(f"{dst} = {mem_float_get(op, args[0])}")

    if op == "fldz":
        dst = fpu.push_new()
        fpu.set_prec(dst, "float")
        return store_or_assign(f"{dst} = 0.0")

    if op == "fld1":
        dst = fpu.push_new()
        fpu.set_prec(dst, "float")
        return store_or_assign(f"{dst} = 1.0")

    if op == "fldpi":
        dst = fpu.push_new()
        fpu.set_prec(dst, "double")
        return store_or_assign(f"{dst} = M_PI")

    if op == "fldst":
        src = fpu.st(int(args[0]))
        dst = fpu.push_new()
        fpu.set_prec(dst, fpu.get_prec(src))
        return store_or_assign(f"{dst} = {src}")

    if op == "fild16":
        dst = fpu.push_new()
        fpu.set_prec(dst, "double")
        return store_or_assign(f"{dst} = (double)(int16_t){args[0]}")

    if op == "fild32":
        dst = fpu.push_new()
        fpu.set_prec(dst, "double")
        return store_or_assign(f"{dst} = (double)(int32_t){args[0]}")

    if op == "fild64":
        dst = fpu.push_new()
        fpu.set_prec(dst, "double")
        return store_or_assign(f"{dst} = (double)(int64_t){args[0]}")

    # ---- INTEGER STORE-AND-POP (fistp) --------------------------------------

    if op in ("fistp32", "fistp16"):
        w   = "32" if op == "fistp32" else "16"
        val = fpu.pop()
        cast = f"(int{w}_t)"
        expr = f"{cast}floor({val})"
        if "memoryASet" in line:
            rewritten = rewrite_fistp_store(line, expr, w)
            if rewritten:
                return [indent + rewritten + cmt()]
        return [f"{indent}{expr};{cmt()}"]

    if op == "fistp64":
        val = fpu.pop()
        expr = f"(int64_t)floor({val})"
        if "memoryASet" in line:
            rewritten = rewrite_fistp_store(line, expr, "64")
            if rewritten:
                return [indent + rewritten + cmt()]
        return [f"{indent}{expr};{cmt()}"]

    # ---- STORES (pop) -------------------------------------------------------

    if op in ("fstp32", "fstp64", "fstp80"):
        return store_or_assign(fpu.pop())

    # ---- STORES (no pop) ----------------------------------------------------

    if op in ("fst32", "fst64"):
        return store_or_assign(fpu.st(0))

    # ---- fstpst(i): ST(i) = ST(0); pop ST(0) --------------------------------

    if op == "fstpst":
        i = int(args[0])
        src = fpu.stack[0]
        if i == 0:                          # fstpst(0) = plain pop
            fpu.pop()
            return [f"{indent}// {orig_call} (pop) fpustack: {fpu.stack_str()}"]
        dst = fpu.stack[i]
        extra = _capture_if_pending(dst)
        fpu.set_prec(dst, fpu.get_prec(src))
        fpu.stack.pop(0)                    # remove ST(0) from tracking
        return extra + [f"{indent}{dst} = {src};{cmt()}"]

    # ---- EXCHANGE (zero-emit, just swap tracking) ---------------------------

    if op == "fxchst2":
        i, j = int(args[0]), int(args[1])
        fpu.swap(i, j)
        return [f"{indent}// {orig_call} fpustack: {fpu.stack_str()}"]

    # ---- ARITHMETIC: memory operand, ST(0) = ST(0) OP mem -------------------

    if op in ("fadd32", "fadd64"):
        dst = fpu.st(0)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} += {mem_float_get(op, args[0])}")

    if op in ("fsub32", "fsub64"):
        dst = fpu.st(0)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} -= {mem_float_get(op, args[0])}")

    if op in ("fsubr32", "fsubr64"):
        dst = fpu.st(0)
        src = mem_float_get(op, args[0])
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = {src} - {dst}")

    if op in ("fmul32", "fmul64"):
        dst = fpu.st(0)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} *= {mem_float_get(op, args[0])}")

    if op in ("fdiv32", "fdiv64"):
        dst = fpu.st(0)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} /= {mem_float_get(op, args[0])}")

    if op in ("fdivr32", "fdivr64"):
        dst = fpu.st(0)
        src = mem_float_get(op, args[0])
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), _prec_mem(op)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = {src} / {dst}")

    # ---- ARITHMETIC: integer memory operand ---------------------------------

    if op in ("fimul32", "fimul16"):
        dst  = fpu.st(0)
        cast = "(int32_t)" if "32" in op else "(int16_t)"
        fpu.set_prec(dst, "double")  # integer operand always widens to double
        return _capture_if_pending(dst) + store_or_assign(f"{dst} *= (double){cast}{args[0]}")

    if op in ("fiadd32", "fiadd16"):
        dst  = fpu.st(0)
        cast = "(int32_t)" if "32" in op else "(int16_t)"
        fpu.set_prec(dst, "double")  # integer operand always widens to double
        return _capture_if_pending(dst) + store_or_assign(f"{dst} += (double){cast}{args[0]}")

    # ---- ARITHMETIC: register ST(0) OP ST(i), no pop ------------------------

    if op == "faddst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} += {src}")

    if op == "fsubst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} -= {src}")

    if op == "fsubrst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = {src} - {dst}")

    if op == "fmulst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} *= {src}")

    if op == "fdivst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} /= {src}")

    if op == "fdivrst":
        dst = fpu.st(0); src = fpu.st(int(args[0]))
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = {src} / {dst}")

    # ---- ARITHMETIC: DC forms ST(i) OP= ST(j), no pop ----------------------

    if op == "fmulst2":
        i, j = int(args[0]), int(args[1]); dst = fpu.st(i); src = fpu.st(j)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} *= {src}")

    if op == "faddst2":
        i, j = int(args[0]), int(args[1]); dst = fpu.st(i); src = fpu.st(j)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} += {src}")

    if op == "fsubst2":
        i, j = int(args[0]), int(args[1]); dst = fpu.st(i); src = fpu.st(j)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} -= {src}")

    if op == "fdivst2":
        i, j = int(args[0]), int(args[1]); dst = fpu.st(i); src = fpu.st(j)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} /= {src}")

    if op == "fsubrst2":
        i, j = int(args[0]), int(args[1]); dst = fpu.st(i); src = fpu.st(j)
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = {src} - {dst}")

    # ---- ARITHMETIC with pop: ST(i) OP= ST(0); pop ST(0) -------------------

    if op == "fmulpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} *= {src};{cmt()}"]

    if op == "faddpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} += {src};{cmt()}"]

    if op == "fsubpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} -= {src};{cmt()}"]

    if op == "fsubrpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} = {src} - {dst};{cmt()}"]

    if op == "fdivpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} /= {src};{cmt()}"]

    if op == "fdivrpst":
        i = int(args[0]); src = fpu.stack[0]; dst = fpu.stack[i]
        fpu.set_prec(dst, fpu.merge_prec(fpu.get_prec(dst), fpu.get_prec(src)))
        extra = _capture_if_pending(dst); fpu.stack.pop(0)
        return extra + [f"{indent}{dst} = {src} / {dst};{cmt()}"]

    # ---- UNARY --------------------------------------------------------------

    if op == "fabs":
        dst = fpu.st(0)
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = fabs({dst})")

    if op == "fchs":
        dst = fpu.st(0)
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = -{dst}")

    if op == "fsqrt":
        dst = fpu.st(0)
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = sqrt({dst})")

    if op == "fsin":
        dst = fpu.st(0)
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = sin({dst})")

    if op == "fcos":
        dst = fpu.st(0)
        return _capture_if_pending(dst) + store_or_assign(f"{dst} = cos({dst})")

    # ---- COMPARE ops --------------------------------------------------------
    # These capture lhs/rhs for use by the subsequent fnstsw+if pattern.
    # Save temps are declared inline here (not in the function-top decl).

    def _cmp_save(lhs: str, rhs: str, pop_count: int) -> list[str]:
        """Record comparison operands; only capture immediately for non-variable exprs."""
        cid = fpu.cmp_counter
        fpu.cmp_counter += 1
        for _ in range(pop_count):
            fpu.stack.pop(0)
        _fpvar = re.compile(r'^fp\d+$')
        # Simple fpN variables are safe to reference at condition time unless dirtied
        # by an intervening fstpst.  Complex expressions (memory reads) capture now.
        ls = None if _fpvar.match(lhs) else f'_cmp{cid}l'
        rs = None if _fpvar.match(rhs) else f'_cmp{cid}r'
        fpu.pending_cmp = (cid, lhs, rhs, ls, rs)
        out: list[str] = []
        if ls:
            out.append(f'{indent}double {ls} = {lhs};')
        if rs:
            out.append(f'{indent}double {rs} = {rhs};')
        note = f' [cmp_{cid}]' if (ls or rs) else ''
        out.append(f'{indent}// {orig_call} fpustack: {fpu.stack_str()}{note}')
        return out

    if op == "fcomst":
        lhs = fpu.st(0); rhs = fpu.st(int(args[0]))
        return _cmp_save(lhs, rhs, 0)

    if op == "fcompst":
        lhs = fpu.stack[0]; rhs = fpu.stack[int(args[0])]
        return _cmp_save(lhs, rhs, 1)

    if op == "fcompp":
        lhs = fpu.stack[0]; rhs = fpu.stack[1]
        return _cmp_save(lhs, rhs, 2)

    if op in ("fcom32", "fcomp32"):
        lhs = fpu.st(0)
        rhs = f"(double)fromFp32({args[0]})"
        pop = 1 if op == "fcomp32" else 0
        return _cmp_save(lhs, rhs, pop)

    if op in ("fcom64", "fcomp64"):
        lhs = fpu.st(0)
        rhs = mem_float_get("64", args[0])
        pop = 1 if op == "fcomp64" else 0
        return _cmp_save(lhs, rhs, pop)

    if op in ("fcom80", "fcomp80"):
        lhs = fpu.st(0)
        rhs = args[0]
        pop = 1 if op == "fcomp80" else 0
        return _cmp_save(lhs, rhs, pop)

    raise RuntimeError(f"Unsupported FPU op: {op!r}")

# ---------------------------------------------------------------------------
# Per-line transformer
# ---------------------------------------------------------------------------

# Matches stack-hint comments placed before labels:
#   // STACK: fp3, fp1, fp0
STACK_HINT_RE = re.compile(r'//\s*STACK\s*:\s*([\w, ]+)')

# Matches stack-assign hints: // STACK_ASSIGN: dst0=src0, dst1=src1
# Generates C++ assignments and resets stack tracking.
STACK_ASSIGN_RE = re.compile(r'//\s*STACK_ASSIGN\s*:\s*([\w =,]+)')


def transform_line(line: str, fpu: FpuStack) -> list[str]:
    """Map one source line to zero or more output lines."""
    indent = re.match(r'(\s*)', line).group(1)

    # ---- stack assign: // STACK_ASSIGN: fp14=fp32, fp13=fp33  -------------
    m_sa = STACK_ASSIGN_RE.search(line)
    if m_sa:
        pairs = []
        for item in m_sa.group(1).split(','):
            item = item.strip()
            if '=' in item:
                dst, src = [x.strip() for x in item.split('=', 1)]
                pairs.append((dst, src))
        if pairs:
            dsts = [d for d, _ in pairs]
            fpu.stack = list(dsts)
            for d in dsts:
                if d not in fpu.declared:
                    fpu.declared.append(d)
            assignments = '; '.join(f'{d} = {s}' for d, s in pairs)
            return [f'{indent}{assignments};  // STACK_ASSIGN → [{", ".join(dsts)}]']

    # ---- stack hint: // STACK: fp3, fp1, fp0  ------------------------------
    m_hint = STACK_HINT_RE.search(line)
    if m_hint:
        names = [n.strip() for n in m_hint.group(1).split(',') if n.strip()]
        fpu.stack = list(names)         # reset tracking to stated contents
        return [line]                   # pass the comment through unchanged

    # ---- fnstsw: drop when a comparison is pending (condition emitted inline)
    # ax is only used by the immediately-following parityOdd/ah& pattern, which
    # we rewrite.  There are no other side effects of fnstsw worth preserving.
    if FNSTSW_RE.search(line):
        if fpu.pending_cmp is not None:
            return []          # consumed — comparison will be inlined below
        return [line]          # no pending compare (unusual); keep for safety

    # ---- if-condition containing parityOdd or ah & mask --------------------
    if fpu.pending_cmp is not None:
        cid, lhs, rhs, ls, rs = fpu.pending_cmp

        m_po = PARITYODD_RE.search(line)
        m_ah = AH_MASK_RE.search(line) if not m_po else None

        if m_po or m_ah:
            fpu.pending_cmp = None

            # Use captured temp if variable was dirtied; original name otherwise
            use_lhs = ls if ls is not None else lhs
            use_rhs = rs if rs is not None else rhs

            if m_po:
                mask_str = m_po.group("mask")
                negated  = bool(m_po.group("neg"))
                cond = resolve_cond(use_lhs, use_rhs, mask_str, negated, True)
                if cond is not None:
                    span_start = m_po.start()
                    span_end   = m_po.end()
                    new_line = line[:span_start] + cond + line[span_end:]
                    return [new_line.rstrip() + f"  // {lhs} vs {rhs}"]
            else:  # m_ah
                mask_str = m_ah.group(1)
                negated  = False
                cond = resolve_cond(use_lhs, use_rhs, mask_str, negated, False)
                if cond is not None:
                    span_start = m_ah.start()
                    span_end   = m_ah.end()
                    new_line = line[:span_start] + cond + line[span_end:]
                    return [new_line.rstrip() + f"  // {lhs} vs {rhs}"]

    # ---- call-site expansion for known-signature callees --------------------
    _cs = re.match(r'^(\s*)(sub_[0-9a-fA-F]+)\s*\(\s*\)\s*;', line)
    if _cs and _cs.group(2) in fpu.sigs:
        fn_cs = _cs.group(2)
        n_in, n_out = fpu.sigs[fn_cs]
        try:
            args = [fpu.pop() for _ in range(n_in)]
        except RuntimeError as e:
            return [line + f'  // TRANSFORM ERROR (call {fn_cs}): {e}']
        rets = [fpu.push_new() for _ in range(n_out)]
        args_str = ', '.join(args)
        cmt = f'  // fpustack: {fpu.stack_str()}'
        ci = _cs.group(1)
        if n_out == 0:
            return [f'{ci}{fn_cs}({args_str});{cmt}']
        if n_out == 1:
            return [f'{ci}{rets[0]} = {fn_cs}({args_str});{cmt}']
        return [f'{ci}auto [{", ".join(rets)}] = {fn_cs}({args_str});{cmt}']

    # ---- return; → return fpN; when function is declared to return FPU vals -
    if fpu.fpu_out > 0 and re.match(r'\s*return\s*;\s*$', line):
        if len(fpu.stack) < fpu.fpu_out:
            return [line.rstrip() + f'  // TRANSFORM ERROR: need {fpu.fpu_out} on stack'
                    f' for return, got {len(fpu.stack)}']
        if fpu.fpu_out == 1:
            return [f'{indent}return {fpu.stack[0]};']
        vals = ', '.join(fpu.stack[:fpu.fpu_out])
        return [f'{indent}return {{{vals}}};']

    # ---- FPU call ----------------------------------------------------------
    m = FPU_CALL_RE.search(line)
    if not m:
        return [line]

    op       = m.group("op")
    args     = split_args(m.group("args"))
    orig_call = m.group(0)

    try:
        return emit_fpu_op(op, args, orig_call, line, fpu)
    except Exception as e:
        return [line + f"  // TRANSFORM ERROR: {e}"]

# ---------------------------------------------------------------------------
# Declaration insertion
# ---------------------------------------------------------------------------

def insert_decls(src: str, names: list[str],
                 precision: dict[str, str] | None = None) -> str:
    if not names:
        return src
    pos = src.find("{")
    if precision:
        floats  = [n for n in names if precision.get(n, "double") == "float"]
        doubles = [n for n in names if precision.get(n, "double") != "float"]
        decl = ""
        if floats:
            decl += "\n    float "  + ", ".join(floats)  + ";"
        if doubles:
            decl += "\n    double " + ", ".join(doubles) + ";"
        decl += "\n"
    else:
        decl = "\n    double " + ", ".join(names) + ";\n"
    return src[: pos + 1] + decl + src[pos + 1 :]

# ---------------------------------------------------------------------------
# Proto helpers: rewrite function signature and inject return statement
# ---------------------------------------------------------------------------

_PROTO_SIG_RE = re.compile(r'^void\s+(sub_[0-9a-fA-F]+)\s*\(\s*\)', re.MULTILINE)

def rewrite_proto(src: str, fpu_in: int, fpu_out: int) -> str:
    """Change void→double and add fp_inN parameters for non-trivial proto."""
    if fpu_out == 0 and fpu_in == 0:
        return src
    params  = ', '.join(f'double fp_in{i}' for i in range(fpu_in))
    ret     = 'void' if fpu_out == 0 else 'double' if fpu_out == 1 else \
              'std::pair<double,double>'
    return _PROTO_SIG_RE.sub(lambda m: f'{ret} {m.group(1)}({params})', src, count=1)


def inject_return(src: str, ret_var: str, fpu_out: int) -> str:
    """Insert fall-off-end return before the final } if not already there."""
    if fpu_out == 0 or not ret_var:
        return src
    lines = src.split('\n')
    for i in range(len(lines) - 1, -1, -1):
        if lines[i].strip() == '}':
            j = i - 1
            while j >= 0 and not lines[j].strip():
                j -= 1
            if j >= 0 and re.match(r'\s*return\b', lines[j]):
                break  # explicit return already present
            if fpu_out == 1:
                lines.insert(i, f'    return {ret_var};')
            else:
                raise NotImplementedError("fpu_out > 1 return not yet implemented")
            break
    return '\n'.join(lines)

# ---------------------------------------------------------------------------
# Top-level
# ---------------------------------------------------------------------------

def transform(src: str, initial_depth: int = 0, typed: bool = False,
              proto: tuple[int,int] = (0, 0),
              sigs:  dict[str, tuple[int,int]] | None = None) -> str:
    fpu_in, fpu_out = proto if proto != (0, 0) else (initial_depth, 0)
    fpu = FpuStack(fpu_in, typed=typed)
    fpu.fpu_out = fpu_out
    fpu.sigs    = sigs or {}
    out: list[str] = []

    for line in src.splitlines():
        out.extend(transform_line(line, fpu))

    result = "\n".join(out)
    prec   = fpu.precision if typed else None
    # fp_in* become parameters, not local declarations
    params     = {f'fp_in{i}' for i in range(fpu_in)}
    local_vars = [v for v in fpu.declared if v not in params]
    result = insert_decls(result, local_vars, prec)
    if proto != (0, 0):
        result = rewrite_proto(result, fpu_in, fpu_out)
    if fpu_out > 0:
        ret_var = fpu.stack[0] if fpu.stack else ''
        result  = inject_return(result, ret_var, fpu_out)
    return result

def main():
    ap = argparse.ArgumentParser(description="Phase-1 FPU emulation remover")
    ap.add_argument("input", help="Input .cpp file (single balanced function)")
    ap.add_argument("--initial-depth", type=int, default=0,
                    help="FPU stack depth on entry (for unbalanced callers)")
    ap.add_argument("--typed-floats", action="store_true",
                    help="Emit float/double declarations based on operand-width inference")
    ap.add_argument("--fpu-proto", default="0:0", metavar="N:M",
                    help="Items consumed from / left on caller FPU stack (default 0:0)")
    ap.add_argument("--sigs", default=None, metavar="FILE",
                    help="JSON file mapping fn→[n_in,n_out] for call-site expansion")
    a  = ap.parse_args()

    fpu_in, fpu_out = (int(x) for x in a.fpu_proto.split(':'))
    sigs = None
    if a.sigs:
        import json
        raw  = json.loads(Path(a.sigs).read_text())
        sigs = {k: tuple(v) for k, v in raw.items()}

    src    = Path(a.input).read_text()
    result = transform(src, typed=a.typed_floats,
                       proto=(fpu_in, fpu_out), sigs=sigs)
    print(result)

if __name__ == "__main__":
    main()
