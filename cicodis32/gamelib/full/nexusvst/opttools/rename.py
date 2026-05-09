#!/usr/bin/env python3
import re
import sys
from pathlib import Path

DECL_RE = re.compile(
    r'^\s*(?:void|float|double)\s+(sub_[0-9A-Fa-f]+)\s*\(',
    re.MULTILINE
)

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <cpp-file>")
        sys.exit(1)

    path = Path(sys.argv[1])
    text = path.read_text(encoding="utf-8", errors="ignore")

    declared = sorted(set(DECL_RE.findall(text)))

    if not declared:
        print("No declared void/float/double sub_* functions found.")
        return

    symbol_re = re.compile(
        r'\b(' + '|'.join(re.escape(name) for name in declared) + r')\b'
    )

    def repl(match):
        return match.group(1).replace("sub_", "subopt_", 1)

    new_text, count = symbol_re.subn(repl, text)

    backup = path.with_suffix(path.suffix + ".bak")
    backup.write_text(text, encoding="utf-8")
    path.write_text(new_text, encoding="utf-8")

    print(f"Found {len(declared)} declared functions.")
    print(f"Made {count} replacements.")
    print(f"Backup saved to {backup}")

if __name__ == "__main__":
    main()
