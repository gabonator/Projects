#!/usr/bin/env python3
import argparse
from pathlib import Path

def remove_fpustack_comments(line: str) -> str:
    # Remove comments that start with // and contain "fpustack"
    comment_pos = line.find("//")
    if comment_pos != -1 and "fpustack" in line[comment_pos:]:
        return line[:comment_pos].rstrip() + "\n"
    return line

def main() -> None:
    parser = argparse.ArgumentParser(
        description='Remove C++ // comments containing the word "fpustack".'
    )
    parser.add_argument("input_file", help="C++ source file to process")
    parser.add_argument(
        "-o", "--output",
        help="Output file. If omitted, the input file is overwritten."
    )
    args = parser.parse_args()

    input_path = Path(args.input_file)
    output_path = Path(args.output) if args.output else input_path

    lines = input_path.read_text(encoding="utf-8").splitlines(keepends=True)

    cleaned_lines = [remove_fpustack_comments(line) for line in lines]

    output_path.write_text("".join(cleaned_lines), encoding="utf-8")

if __name__ == "__main__":
    main()