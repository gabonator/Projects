# Full fixed code with robust conditional-goto handling, lines, and fpu-instruction count columns.
# Save as analyze_fpu_balance.py

#!/usr/bin/env python3

import argparse
import csv
import json
import re
import sys
from pathlib import Path
from dataclasses import dataclass, field


STATE_LIMIT_PER_BLOCK = 512
MAX_ITERATIONS = 1000


FPU_BALANCE = {
    "fld32": 1, "fld64": 1, "fld80": 1, "fld16": 1, "fldst": 1,
    "fld1": 1, "fldz": 1, "fldpi": 1, "fldln2": 1, "fldl2e": 1,
    "fldl2t": 1, "fldlg2": 1,
    "fild16": 1, "fild32": 1, "fild64": 1,

    "fst32": 0, "fst64": 0, "fst80": 0,
    "fstp32": -1, "fstp64": -1, "fstp80": -1,
    "fistp16": -1, "fistp32": -1, "fistp64": -1,
    "fstpst": -1,

    "fadd32": 0, "fadd64": 0, "fadd80": 0,
    "fiadd16": 0, "fiadd32": 0,
    "fsub32": 0, "fsub64": 0, "fsub80": 0,
    "fisub16": 0, "fisub32": 0,
    "fsubr32": 0, "fsubr64": 0, "fisubr32": 0,
    "fmul32": 0, "fmul64": 0, "fmul80": 0,
    "fimul16": 0, "fimul32": 0,
    "fdiv32": 0, "fdiv64": 0, "fdiv80": 0,
    "fidiv16": 0, "fidiv32": 0,
    "fdivr32": 0, "fdivr64": 0, "fdivr80": 0,

    "faddst": 0, "fsubst": 0, "fsubrst": 0,
    "fmulst": 0, "fdivst": 0, "fdivrst": 0,
    "faddst2": 0, "fmulst2": 0, "fsubst2": 0,
    "fsubrst2": 0, "fdivst2": 0, "fdivrst2": 0,

    "faddp80": -1, "fsubp80": -1, "fmulp80": -1,
    "fdivp80": -1, "fdivrp80": -1, "faddp64": -1,
    "faddpst": -1, "fsubpst": -1, "fsubrpst": -1,
    "fmulpst": -1, "fdivpst": -1, "fdivrpst": -1,

    "fcom32": 0, "fcom64": 0, "fcom80": 0, "fcomst": 0,
    "fcomp32": -1, "fcomp64": -1, "fcomp80": -1, "fcompst": -1,
    "fcompp": -2, "ftst": 0,

    "fabs": 0, "fchs": 0, "fsqrt": 0, "fsin": 0, "fcos": 0,
    "fpatan": -1, "fptan": 1,
    "fyl2x": -1, "fyl2xp1": -1,
    "f2xm1": 0, "fscale": 0, "fprem": 0,
    "frndtint": 0, "frndint": 0, "fxam": 0,

    "fnstsw": 0, "fldcw": 0, "fnstcw": 0, "fninit": 0,
    "fxchst2": 0, "fxch80": 0,
}


# Ops that require at least double precision:
#   - 64/80-bit memory operands (information would be lost in float)
#   - 64-bit integer loads/stores (exceed float's 23-bit mantissa)
#   - transcendentals and non-trivial constants
DOUBLE_OPS: set[str] = {
    "fld64", "fst64", "fstp64",
    "fadd64", "fsub64", "fsubr64", "fmul64", "fdiv64", "fdivr64",
    "fcom64", "fcomp64", "faddp64",
    "fld80", "fst80", "fstp80",
    "fadd80", "fsub80", "fmul80", "fdiv80", "fcom80", "fcomp80",
    "faddp80", "fsubp80", "fmulp80", "fdivp80", "fdivrp80", "fxch80",
    "fild64", "fistp64",
    "fldpi", "fldln2", "fldl2e", "fldl2t", "fldlg2",
    "fsqrt", "fsin", "fcos", "fpatan", "fptan",
    "fyl2x", "fyl2xp1", "f2xm1", "fscale", "fprem",
}


FUNC_DEF_RE = re.compile(
    r"""
    (?P<ret>
        \b(?:void|int|uint32_t|uint64_t|double|float|bool|char|short|long|auto)\b
        [\w\s:&*<>]*
    )
    \s+
    (?P<name>sub_[0-9a-fA-F]+)
    \s*\([^)]*\)
    \s*(?://[^\n]*)?
    \{
    """,
    re.VERBOSE,
)

LABEL_RE = re.compile(r"^\s*(loc_[0-9a-fA-F]+)\s*:\s*(?://.*)?$")
GOTO_RE = re.compile(r"\bgoto\s+(loc_[0-9a-fA-F]+)\s*;")
IF_RE = re.compile(r"^\s*if\s*\(.*")
RETURN_RE = re.compile(r"\breturn\b")
CALL_RE = re.compile(r"\b(?P<name>sub_[0-9a-fA-F]+)\s*\(")

FPU_CALL_RE = re.compile(
    r"""
    (?:
        \bfpuinsns\s*::\s*
      | \b
    )
    (?P<name>
        fld32|fld64|fld80|fld16|fldst|fld1|fldz|fldpi|fldln2|fldl2e|fldl2t|fldlg2|
        fild16|fild32|fild64|
        fst32|fst64|fst80|fstp32|fstp64|fstp80|fistp16|fistp32|fistp64|fstpst|
        fadd32|fadd64|fadd80|fiadd16|fiadd32|
        fsub32|fsub64|fsub80|fisub16|fisub32|fsubr32|fsubr64|fisubr32|
        fmul32|fmul64|fmul80|fimul16|fimul32|
        fdiv32|fdiv64|fdiv80|fidiv16|fidiv32|fdivr32|fdivr64|fdivr80|
        faddst2|fmulst2|fsubst2|fsubrst2|fdivst2|fdivrst2|
        faddst|fsubst|fsubrst|fmulst|fdivst|fdivrst|
        faddp80|fsubp80|fmulp80|fdivp80|fdivrp80|faddp64|
        faddpst|fsubpst|fsubrpst|fmulpst|fdivpst|fdivrpst|
        fcom32|fcom64|fcom80|fcomst|fcomp32|fcomp64|fcomp80|fcompst|fcompp|ftst|
        fabs|fchs|fsqrt|fsin|fcos|fpatan|fptan|fyl2x|fyl2xp1|f2xm1|fscale|fprem|
        frndtint|frndint|fxam|fnstsw|fldcw|fnstcw|fninit|
        fxchst2|fxch80
    )
    \s*\(
    """,
    re.VERBOSE,
)


@dataclass
class FunctionInfo:
    name: str
    body: str
    lines: list[str]


@dataclass
class Block:
    name: str
    lines: list[str] = field(default_factory=list)
    successors: list[str] = field(default_factory=list)


@dataclass(frozen=True)
class State:
    balance: int
    min_depth: int
    max_depth: int


@dataclass
class Result:
    states: set[State] | None
    uses_fpu: bool
    missing: set[str] = field(default_factory=set)
    cycle: bool = False
    calls_nonzero_balance: bool = False


def strip_comments(src: str) -> str:
    src = re.sub(r"/\*.*?\*/", "", src, flags=re.S)
    src = re.sub(r"//.*", "", src)
    return src


def normalize_lines(lines: list[str]) -> list[str]:
    out = []
    i = 0

    while i < len(lines):
        line = lines[i].strip()

        if (
            IF_RE.match(line)
            and i + 1 < len(lines)
            and GOTO_RE.search(lines[i + 1])
            and not GOTO_RE.search(line)
        ):
            out.append(line + " " + lines[i + 1].strip())
            i += 2
            continue

        out.append(line)
        i += 1

    return out


def find_matching_brace(src: str, open_pos: int) -> int:
    depth = 0
    in_str = False
    in_chr = False
    esc = False

    for i in range(open_pos, len(src)):
        c = src[i]

        if esc:
            esc = False
            continue

        if c == "\\" and (in_str or in_chr):
            esc = True
            continue

        if c == '"' and not in_chr:
            in_str = not in_str
            continue

        if c == "'" and not in_str:
            in_chr = not in_chr
            continue

        if in_str or in_chr:
            continue

        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i

    raise ValueError("Unmatched brace")


def parse_functions(src: str) -> dict[str, FunctionInfo]:
    clean = strip_comments(src)
    functions = {}

    for m in FUNC_DEF_RE.finditer(clean):
        name = m.group("name")
        open_brace = clean.find("{", m.start())
        close_brace = find_matching_brace(clean, open_brace)
        body = clean[open_brace + 1:close_brace]

        raw_lines = [line.strip() for line in body.splitlines() if line.strip()]
        lines = normalize_lines(raw_lines)

        functions[name] = FunctionInfo(name=name, body=body, lines=lines)

    return functions


def is_if_line(line: str) -> bool:
    return line.lstrip().startswith("if")


def goto_target(line: str) -> str | None:
    m = GOTO_RE.search(line)
    return m.group(1) if m else None


def is_conditional_goto(line: str) -> bool:
    return is_if_line(line) and goto_target(line) is not None


def is_unconditional_goto(line: str) -> bool:
    return not is_if_line(line) and goto_target(line) is not None


def line_ends_block(line: str) -> bool:
    return bool(goto_target(line) or RETURN_RE.search(line))


def build_cfg(fn: FunctionInfo) -> dict[str, Block]:
    blocks: dict[str, Block] = {}
    order: list[str] = []

    def new_block(name: str) -> Block:
        if name not in blocks:
            blocks[name] = Block(name=name)
            order.append(name)
        return blocks[name]

    current = new_block("entry")
    anon_id = 0

    for line in fn.lines:
        label_match = LABEL_RE.match(line)

        if label_match:
            label = label_match.group(1)
            current = new_block(label)
            continue

        current.lines.append(line)

        if line_ends_block(line):
            anon_id += 1
            current = new_block(f"bb_{anon_id}")

    for name in list(blocks):
        if name.startswith("bb_") and not blocks[name].lines:
            blocks.pop(name)
            order.remove(name)

    for idx, name in enumerate(order):
        block = blocks[name]

        if not block.lines:
            block.successors.append(order[idx + 1] if idx + 1 < len(order) else "__exit__")
            continue

        last = block.lines[-1]
        target = goto_target(last)
        is_return = bool(RETURN_RE.search(last))

        if is_conditional_goto(last):
            if target in blocks:
                block.successors.append(target)
            block.successors.append(order[idx + 1] if idx + 1 < len(order) else "__exit__")

        elif is_unconditional_goto(last):
            if target in blocks:
                block.successors.append(target)

        elif is_return:
            block.successors.append("__exit__")

        else:
            block.successors.append(order[idx + 1] if idx + 1 < len(order) else "__exit__")

    blocks["__exit__"] = Block("__exit__")
    return blocks


def normalize_external_balances(raw: dict) -> dict[str, set[State]]:
    result = {}

    for name, value in raw.items():
        if isinstance(value, int):
            values = [value]
        elif isinstance(value, list):
            values = [int(x) for x in value]
        else:
            raise ValueError(f"Invalid external balance for {name}: {value!r}")

        states = set()
        for b in values:
            states.add(State(balance=b, min_depth=min(0, b), max_depth=max(0, b)))

        result[name] = states

    return result


def direct_fpu_calls(line: str) -> list[str]:
    return [m.group("name") for m in FPU_CALL_RE.finditer(line)]


def count_direct_fpu_instructions(fn: FunctionInfo) -> int:
    return sum(len(direct_fpu_calls(line)) for line in fn.lines)


def needs_double_precision(fn: FunctionInfo) -> bool:
    """True if the function directly uses any 64/80-bit or transcendental FPU op."""
    for line in fn.lines:
        for op in direct_fpu_calls(line):
            if op in DOUBLE_OPS:
                return True
    return False


def sub_calls(line: str, self_name: str) -> list[str]:
    return [m.group("name") for m in CALL_RE.finditer(line) if m.group("name") != self_name]


def apply_delta_to_states(states: set[State], delta: int) -> set[State]:
    out = set()

    for s in states:
        nb = s.balance + delta
        out.add(State(
            balance=nb,
            min_depth=min(s.min_depth, nb),
            max_depth=max(s.max_depth, nb),
        ))

    return out


def compose_states(prefix: set[State], callee: set[State]) -> set[State]:
    out = set()

    for a in prefix:
        for b in callee:
            final_balance = a.balance + b.balance
            out.add(State(
                balance=final_balance,
                min_depth=min(a.min_depth, a.balance + b.min_depth),
                max_depth=max(a.max_depth, a.balance + b.max_depth),
            ))

    return out


def block_state_transform(
    block: Block,
    self_name: str,
    functions: dict[str, FunctionInfo],
    external: dict[str, set[State]],
    memo: dict[str, Result],
    stack: list[str],
) -> tuple[set[State] | None, bool, set[str], bool, bool]:
    states = {State(balance=0, min_depth=0, max_depth=0)}
    uses_fpu = False
    missing: set[str] = set()
    cycle = False
    calls_nonzero_balance = False

    for line in block.lines:
        for fpu in direct_fpu_calls(line):
            uses_fpu = True
            states = apply_delta_to_states(states, FPU_BALANCE[fpu])

        for callee in sub_calls(line, self_name):
            cr = analyze_function(callee, functions, external, memo, stack)

            if cr.states is None:
                missing |= cr.missing
                cycle = cycle or cr.cycle
                continue

            callee_balances = {s.balance for s in cr.states}
            if callee_balances != {0}:
                calls_nonzero_balance = True

            calls_nonzero_balance = calls_nonzero_balance or cr.calls_nonzero_balance
            states = compose_states(states, cr.states)
            uses_fpu = uses_fpu or cr.uses_fpu

    if missing or cycle:
        return None, uses_fpu, missing, cycle, calls_nonzero_balance

    return states, uses_fpu, missing, cycle, calls_nonzero_balance


def analyze_function(
    name: str,
    functions: dict[str, FunctionInfo],
    external: dict[str, set[State]],
    memo: dict[str, Result],
    stack: list[str],
) -> Result:
    if name in memo:
        return memo[name]

    if name in external:
        states = external[name]
        r = Result(
            states=states,
            uses_fpu=any(s.balance != 0 or s.min_depth != 0 or s.max_depth != 0 for s in states),
            calls_nonzero_balance=False,
        )
        memo[name] = r
        return r

    if name not in functions:
        return Result(states=None, uses_fpu=False, missing={name})

    if name in stack:
        return Result(states=None, uses_fpu=False, cycle=True)

    stack.append(name)

    fn = functions[name]
    blocks = build_cfg(fn)

    block_transforms: dict[str, set[State]] = {}
    uses_fpu = False
    missing: set[str] = set()
    cycle = False
    calls_nonzero_balance = False

    for bname, block in blocks.items():
        if bname == "__exit__":
            continue

        transform, buse, bmissing, bcycle, b_calls_nonzero = block_state_transform(
            block, name, functions, external, memo, stack
        )

        uses_fpu = uses_fpu or buse
        missing |= bmissing
        cycle = cycle or bcycle
        calls_nonzero_balance = calls_nonzero_balance or b_calls_nonzero

        if transform is not None:
            block_transforms[bname] = transform

    stack.pop()

    if missing or cycle:
        r = Result(
            states=None,
            uses_fpu=uses_fpu,
            missing=missing,
            cycle=cycle,
            calls_nonzero_balance=calls_nonzero_balance,
        )
        memo[name] = r
        return r

    incoming: dict[str, set[State]] = {
        "entry": {State(balance=0, min_depth=0, max_depth=0)}
    }

    changed = True
    iterations = 0

    while changed:
        changed = False
        iterations += 1

        if iterations > MAX_ITERATIONS:
            r = Result(
                states=None,
                uses_fpu=uses_fpu,
                cycle=True,
                calls_nonzero_balance=calls_nonzero_balance,
            )
            memo[name] = r
            return r

        for bname, block in blocks.items():
            if bname == "__exit__":
                continue

            in_states = incoming.get(bname, set())
            if not in_states:
                continue

            transform = block_transforms.get(
                bname,
                {State(balance=0, min_depth=0, max_depth=0)},
            )

            out_states = compose_states(in_states, transform)

            for succ in block.successors:
                target_states = incoming.setdefault(succ, set())
                before = len(target_states)
                target_states.update(out_states)

                if len(target_states) > STATE_LIMIT_PER_BLOCK:
                    r = Result(
                        states=None,
                        uses_fpu=uses_fpu,
                        cycle=True,
                        calls_nonzero_balance=calls_nonzero_balance,
                    )
                    memo[name] = r
                    return r

                if len(target_states) != before:
                    changed = True

    final_states = incoming.get("__exit__", set())

    if not final_states:
        final_states = {State(balance=0, min_depth=0, max_depth=0)}

    r = Result(
        states=final_states,
        uses_fpu=uses_fpu,
        calls_nonzero_balance=calls_nonzero_balance,
    )
    memo[name] = r
    return r


def collect_direct_fpu_calls(fn: FunctionInfo) -> list[str]:
    calls = []
    for line in fn.lines:
        calls.extend(direct_fpu_calls(line))
    return calls


def final_balances(states: set[State] | None) -> set[int] | None:
    if states is None:
        return None
    return {s.balance for s in states}


def fmt_balance_set(states: set[State] | None) -> str:
    balances = final_balances(states)
    if balances is None:
        return "UNKNOWN"
    return "{" + ", ".join(str(x) for x in sorted(balances)) + "}"


def fmt_stack_min(states: set[State] | None) -> str:
    if states is None:
        return "UNKNOWN"
    return str(min(s.min_depth for s in states))


def fmt_stack_max(states: set[State] | None) -> str:
    if states is None:
        return "UNKNOWN"
    return str(max(s.max_depth for s in states))


def balance_status(states: set[State] | None) -> str:
    balances = final_balances(states)

    if balances is None:
        return "unknown"
    if balances == {0}:
        return "balanced"
    if len(balances) == 1:
        v = next(iter(balances))
        if v > 0:
            return "always pushes"
        if v < 0:
            return "always pops"
    return "branch-dependent"


def is_simple(r: Result) -> bool:
    balances = final_balances(r.states)
    return balances == {0} and not r.calls_nonzero_balance


def markdown_table(rows):
    out = []
    out.append(
        "| Function | Lines | FPU insns | FPU balance set | stack-min | stack-max | simple | needs double | Status | Direct FPU calls | Missing callees | Notes |"
    )
    out.append("|---|---:|---:|---:|---:|---:|---|---|---|---|---|---|")

    for r in rows:
        out.append(
            f"| `{r['function']}` | {r['lines']} | {r['fpu_insns']} | `{r['balances']}` | "
            f"{r['stack_min']} | {r['stack_max']} | {r['simple']} | {r['needs_double']} | {r['status']} | "
            f"{r['direct_fpu_calls']} | {r['missing']} | {r['notes']} |"
        )

    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cpp", help="Generated C++ source file")
    ap.add_argument(
        "--external-balances",
        default=None,
        help='JSON file like {"sub_12345678": [0], "sub_deadbeef": [-1, 0]}',
    )
    ap.add_argument(
        "--format",
        choices=["markdown", "csv", "json"],
        default="markdown",
    )
    ap.add_argument(
        "--include-all",
        action="store_true",
        help="Include functions that do not use FPU",
    )
    args = ap.parse_args()

    src = Path(args.cpp).read_text(errors="replace")
    functions = parse_functions(src)

    external = {}
    if args.external_balances:
        raw = json.loads(Path(args.external_balances).read_text())
        external = normalize_external_balances(raw)

    memo: dict[str, Result] = {}
    rows = []

    for name in sorted(functions):
        r = analyze_function(name, functions, external, memo, [])

        if not args.include_all and not r.uses_fpu:
            continue

        fn = functions[name]
        direct = collect_direct_fpu_calls(fn)
        balances = final_balances(r.states)

        notes = []
        if r.cycle:
            notes.append("loop/cycle or state explosion")
        if balances is not None and len(balances) > 1:
            notes.append("different branches have different FPU balance")
        if r.calls_nonzero_balance:
            notes.append("calls function with nonzero balance")

        rows.append({
            "function": name,
            "lines": len(fn.lines),
            "fpu_insns": count_direct_fpu_instructions(fn),
            "balances": fmt_balance_set(r.states),
            "stack_min": fmt_stack_min(r.states),
            "stack_max": fmt_stack_max(r.states),
            "simple": "true" if is_simple(r) else "false",
            "needs_double": "true" if needs_double_precision(fn) else "false",
            "status": balance_status(r.states),
            "direct_fpu_calls": ", ".join(direct),
            "missing": ", ".join(sorted(r.missing)),
            "notes": "; ".join(notes),
        })

    if args.format == "json":
        print(json.dumps(rows, indent=2))
    elif args.format == "csv":
        w = csv.DictWriter(
            sys.stdout,
            fieldnames=[
                "function",
                "lines",
                "fpu_insns",
                "balances",
                "stack_min",
                "stack_max",
                "simple",
                "needs_double",
                "status",
                "direct_fpu_calls",
                "missing",
                "notes",
            ],
        )
        w.writeheader()
        w.writerows(rows)
    else:
        print(markdown_table(rows))


if __name__ == "__main__":
    main()
