#!/usr/bin/env python3
import re
import sys
from pathlib import Path

FUNC_RE = re.compile(
    r'^\s*(void|float|double)\s+(subopt_[0-9A-Fa-f]+)\s*\(\s*\)',
    re.MULTILINE
)

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <cpp-file>")
        sys.exit(1)

    path = Path(sys.argv[1])
    text = path.read_text(encoding="utf-8", errors="ignore")

    funcs = []
    seen = set()

    for ret, name in FUNC_RE.findall(text):
        if name not in seen:
            seen.add(name)
            funcs.append((ret, name))

    if not funcs:
        print("No void/float/double subopt_* declarations found.")
        return

    forward_decls = "\n".join(
        f"{ret} {name}();"
        for ret, name in funcs
    )

    block = (
        "// Forward declarations for subopt_* functions\n"
        + forward_decls
        + "\n\n"
    )

    # Avoid inserting twice
    if "// Forward declarations for subopt_* functions" in text:
        print("Forward declaration block already exists. Not inserting again.")
        return

    new_text = block + text

    backup = path.with_suffix(path.suffix + ".bak")
    backup.write_text(text, encoding="utf-8")
    path.write_text(new_text, encoding="utf-8")

    print(f"Inserted {len(funcs)} forward declarations.")
    print(f"Backup saved to {backup}")

if __name__ == "__main__":
    main()
