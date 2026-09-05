#!/usr/bin/env python3
"""
Novation Remote 25 Audio — Full Backup (All Patches)

Captures multiple template dumps sequentially and saves each to a numbered file.
Also creates a combined backup file with all patches.

Instructions:
  1. Run this script
  2. On the Remote 25, for each patch:
     - Select the patch
     - MENU -> Global Settings -> Dump Current Template -> WRITE
     - Wait for "Saved" confirmation before sending the next one
  3. Repeat for all patches
  4. Press Ctrl+C when done

Each dump takes ~2.6s over DIN MIDI (USB Uno).
"""

import os
import time
import signal
import mido

PORT_NAME = "USB Uno MIDI Interface"
EXPECTED_SIZE = 8208
OUTPUT_DIR = "patches"

# Offsets in mido data (full message offset minus 1 for stripped F0)
BOTTOM_NAME_OFFSET = 12   # 0x0D - 1
BOTTOM_NAME_LEN = 16
TOP_NAME_OFFSET = 29      # 0x1E - 1
TOP_NAME_LEN = 13


def extract_name(data):
    """Extract top and bottom display names from template dump."""
    try:
        top = bytes(data[TOP_NAME_OFFSET:TOP_NAME_OFFSET + TOP_NAME_LEN]).decode('ascii', errors='replace').strip()
        bottom = bytes(data[BOTTOM_NAME_OFFSET:BOTTOM_NAME_OFFSET + BOTTOM_NAME_LEN]).decode('ascii', errors='replace').strip()
        return top, bottom
    except Exception:
        return "???", "???"


def main():
    names = mido.get_input_names()
    port = None
    for n in names:
        if "USB Uno" in n or "Novation" in n:
            port = n
            break
    if not port and names:
        port = names[0]
    if not port:
        print("No MIDI input port found!")
        return

    os.makedirs(OUTPUT_DIR, exist_ok=True)

    print(f"Listening on: {port}")
    print(f"Saving to:    {OUTPUT_DIR}/")
    print(f"Expected dump size: {EXPECTED_SIZE} bytes per patch")
    print()
    print("For each patch on the Remote 25:")
    print("  1. Select the patch")
    print("  2. MENU -> Global Settings -> Dump Current Template -> WRITE")
    print("  3. Wait for confirmation here, then send the next one")
    print()
    print("Press Ctrl+C when all patches are sent.")
    print("=" * 60)
    print()

    running = True
    def stop(sig, frame):
        nonlocal running
        running = False
    signal.signal(signal.SIGINT, stop)

    patch_count = 0
    all_dumps = []

    with mido.open_input(port) as inport:
        while inport.poll():
            pass

        while running:
            msg = inport.poll()
            if msg:
                if msg.type == 'sysex':
                    data = msg.data
                    wire_size = len(data) + 2

                    if wire_size < 100:
                        # Small sysex, probably not a template dump
                        preview = ' '.join(f'{b:02X}' for b in data[:32])
                        print(f"  (skipped small SysEx: {wire_size} bytes: F0 {preview} F7)")
                        continue

                    patch_count += 1
                    top_name, bottom_name = extract_name(data)

                    # Build filename from name or just number
                    safe_name = ''.join(c if c.isalnum() or c in ' _-' else '_' for c in top_name).strip()
                    if not safe_name:
                        safe_name = f"patch"
                    fname = f"patch_{patch_count:02d}_{safe_name}.syx"
                    fpath = os.path.join(OUTPUT_DIR, fname)

                    raw = bytes([0xF0]) + bytes(data) + bytes([0xF7])
                    with open(fpath, 'wb') as f:
                        f.write(raw)
                    all_dumps.append(raw)

                    ok = "OK" if wire_size == EXPECTED_SIZE else f"({wire_size} bytes!)"
                    print(f"  [{patch_count:2d}] {ok:6s}  top=\"{top_name}\"  bottom=\"{bottom_name}\"  -> {fname}")

                elif msg.type == 'control_change':
                    pass  # ignore CC noise while switching patches
                elif msg.type in ('note_on', 'note_off'):
                    pass
                elif msg.type == 'program_change':
                    print(f"  (program change: {msg.program} ch={msg.channel})")

            time.sleep(0.001)

    # Save combined backup
    print()
    print("=" * 60)
    if all_dumps:
        combined_path = os.path.join(OUTPUT_DIR, "all_patches.syx")
        with open(combined_path, 'wb') as f:
            for raw in all_dumps:
                f.write(raw)
        print(f"Backup complete: {patch_count} patches saved.")
        print(f"  Individual: {OUTPUT_DIR}/patch_*.syx")
        print(f"  Combined:   {combined_path} ({os.path.getsize(combined_path)} bytes)")
    else:
        print("No patches captured.")


if __name__ == "__main__":
    main()
