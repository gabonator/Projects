#!/usr/bin/env python3
import re
import sys
from pathlib import Path

FUNC_RE = re.compile(
    r"""
    ^void\s+
    (?P<name>sub_[0-9a-fA-F]+)
    \s*\(\s*\)
    \s*
    (?://[^\n]*)?
    \n
    \{
    """,
    re.MULTILINE | re.VERBOSE,
)

CALL_RE = re.compile(r"\b(sub_[0-9a-fA-F]+)\s*\(")


def find_matching_brace(text: str, open_pos: int) -> int:
    depth = 0
    i = open_pos
    n = len(text)

    in_line_comment = False
    in_block_comment = False
    in_string = False
    in_char = False
    escape = False

    while i < n:
        c = text[i]
        nxt = text[i + 1] if i + 1 < n else ""

        if in_line_comment:
            if c == "\n":
                in_line_comment = False

        elif in_block_comment:
            if c == "*" and nxt == "/":
                in_block_comment = False
                i += 1

        elif in_string:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == '"':
                in_string = False

        elif in_char:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == "'":
                in_char = False

        else:
            if c == "/" and nxt == "/":
                in_line_comment = True
                i += 1
            elif c == "/" and nxt == "*":
                in_block_comment = True
                i += 1
            elif c == '"':
                in_string = True
            elif c == "'":
                in_char = True
            elif c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    return i + 1

        i += 1

    raise ValueError("No matching closing brace found")


def extract_functions(text: str) -> dict[str, str]:
    funcs = {}

    for m in FUNC_RE.finditer(text):
        name = m.group("name")
        open_brace = text.find("{", m.start())
        end = find_matching_brace(text, open_brace)

        # Include trailing newline after function if present
        while end < len(text) and text[end] in " \t\r\n":
            if text[end] == "\n":
                end += 1
                break
            end += 1

        funcs[name] = text[m.start():end]

    return funcs


def collect_recursive(funcs: dict[str, str], root: str) -> list[str]:
    seen = set()
    ordered = []

    def visit(name: str):
        if name in seen:
            return
        seen.add(name)

        body = funcs.get(name)
        if body is None:
            print(f"Warning: function not found: {name}", file=sys.stderr)
            return

        ordered.append(name)

        for callee in CALL_RE.findall(body):
            if callee != name:
                visit(callee)

    visit(root)
    return ordered


def main():
    if len(sys.argv) < 4:
        print(
            "Usage: extract_recursive.py input.cpp output.cpp sub_10058970 [sub_ABCDEF ...]",
            file=sys.stderr,
        )
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])
    root_names = sys.argv[3:]

    text = input_path.read_text(encoding="utf-8", errors="replace")

    funcs = extract_functions(text)

    seen = set()
    ordered_names = []

    for root_name in root_names:
        for name in collect_recursive(funcs, root_name):
            if name not in seen:
                seen.add(name)
                ordered_names.append(name)

    output = []
    for name in ordered_names:
        output.append(funcs[name].rstrip())
        output.append("\n\n")

    output_path.write_text("".join(output), encoding="utf-8")

    print(f"Extracted {len(ordered_names)} functions:")
    for name in ordered_names:
        print(name)

if __name__ == "__main__":
    main()
