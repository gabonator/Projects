#!/usr/bin/env python3
"""
Novation Remote 25 Audio — Send SysEx Template

Sends a .syx template dump to the device with modified display name.
Uses the full 8208-byte template dump protocol as documented.

Usage:
  python3 midi_sysex_send.py <file.syx> [--top "text"] [--bottom "text"] [--patch N]

Examples:
  python3 midi_sysex_send.py novation_backup/patch_12_Generic.syx --top "Hello" --bottom "World"
  python3 midi_sysex_send.py novation_backup/patch_12_Generic.syx --patch 1
"""

import sys
import time
import mido

BOTTOM_OFFSET = 0x0D   # 13 - in full message including F0
TOP_OFFSET    = 0x1E   # 30
BOTTOM_LEN    = 16
TOP_LEN       = 13
PATCH_OFFSET  = 0x0C   # 12


def pad(text, length):
    return text[:length].ljust(length).encode("ascii")


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return

    syx_file = sys.argv[1]
    new_top = None
    new_bottom = None
    target_patch = None

    # Parse args
    i = 2
    while i < len(sys.argv):
        if sys.argv[i] == '--top' and i + 1 < len(sys.argv):
            new_top = sys.argv[i + 1]
            i += 2
        elif sys.argv[i] == '--bottom' and i + 1 < len(sys.argv):
            new_bottom = sys.argv[i + 1]
            i += 2
        elif sys.argv[i] == '--patch' and i + 1 < len(sys.argv):
            target_patch = int(sys.argv[i + 1]) - 1  # 0-based
            i += 2
        else:
            print(f"Unknown arg: {sys.argv[i]}")
            return

    with open(syx_file, 'rb') as f:
        raw = bytearray(f.read())

    print(f"File: {syx_file} ({len(raw)} bytes)")

    if raw[0] != 0xF0 or raw[-1] != 0xF7:
        print("ERROR: Not a valid SysEx file (missing F0/F7 framing)")
        return

    # Show original names
    orig_bottom = raw[BOTTOM_OFFSET:BOTTOM_OFFSET + BOTTOM_LEN].decode('ascii', errors='replace').strip()
    orig_top = raw[TOP_OFFSET:TOP_OFFSET + TOP_LEN].decode('ascii', errors='replace').strip()
    orig_patch = raw[PATCH_OFFSET]
    print(f"Original: top=\"{orig_top}\"  bottom=\"{orig_bottom}\"  patch={orig_patch + 1}")

    # Apply modifications
    if new_top is not None:
        raw[TOP_OFFSET:TOP_OFFSET + TOP_LEN] = pad(new_top, TOP_LEN)
        print(f"New top:    \"{new_top}\"")
    if new_bottom is not None:
        raw[BOTTOM_OFFSET:BOTTOM_OFFSET + BOTTOM_LEN] = pad(new_bottom, BOTTOM_LEN)
        print(f"New bottom: \"{new_bottom}\"")
    if target_patch is not None:
        raw[PATCH_OFFSET] = target_patch & 0x7F
        print(f"New patch:  {target_patch + 1}")

    # Find output port
    names = mido.get_output_names()
    port = None
    for n in names:
        if "USB Uno" in n or "Novation" in n:
            port = n
            break
    if not port and names:
        port = names[0]
    if not port:
        print("No MIDI output port found!")
        return

    print(f"Output: {port}")
    print()
    print("Sending in 3 seconds...")
    time.sleep(3)

    # mido expects data without F0/F7
    data = list(raw[1:-1])
    msg = mido.Message('sysex', data=data)
    with mido.open_output(port) as outport:
        print("Sending...")
        outport.send(msg)
        # DIN MIDI: ~2.6s for 8208 bytes
        time.sleep(4)

    print("Done. Template sent to device.")
    print("To make permanent: MENU -> Write Template")


if __name__ == "__main__":
    main()
