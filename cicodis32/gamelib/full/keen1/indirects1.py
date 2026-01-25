import re

# Regex to match the indirectJump line:
# captures:
#   + offset (decimal)
#   + address segment
#   + address offset
jump_re = re.compile(
    r"indirectJump\(cs,\s*memoryAGet16\(cs,\s*bx\s*\+\s*(\d+)\)\);\s*return;\s*//\s*([0-9a-fA-F]{4}):([0-9a-fA-F]{4})"
)

# Regex to match bounds like:
#    if (bx > 0x0008)
#    if (bx <= 0x0017)
bounds_re = re.compile(
    r"if\s*\(\s*bx\s*[<>]=?\s*0x([0-9a-fA-F]+)\s*\)"
)

def scan_file(filename):
    with open(filename, "r", encoding="utf-8") as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        m = jump_re.search(line)
        if not m:
            continue

        offset_decimal = int(m.group(1))
        seg = m.group(2).lower()
        addr_off = m.group(3).lower()

        # Compute table offset (hex)
        table_off_hex = f"{offset_decimal:04x}"

        # Search upward for bx bound
        entries = None
        for j in range(i-1, max(i-10, -1), -1):
            b = bounds_re.search(lines[j])
            if b:
                bound_hex = b.group(1)
                # Entry count = bound + 1
                entries = int(bound_hex, 16) + 1
                break

        # If no bounds found, entries unknown
        if entries is None:
            entries = "?"

        #print(f"addr={seg}:{addr_off} table={seg}:{table_off_hex} entries={entries}")
        print(f'{{"id": "jumpTable", "addr": "{seg}:{addr_off}", "table": "{seg}:{table_off_hex}", "type": "jumpwords", "entries": {entries}, "selector": "bx"}}')


# Example usage:

scan_file("keen1.cpp")
