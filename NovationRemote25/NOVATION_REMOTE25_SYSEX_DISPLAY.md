# Novation Remote 25 Audio / X-Station — SysEx Display Protocol

Reverse-engineered by probing the device (firmware 3.0.03) over MIDI.

---

## Device Identification

| Field | Value |
|---|---|
| Product | Novation Remote 25 Audio (same hardware as X-Station 25) |
| Firmware | X-Station OS 3.0.03 |
| Display | 2 × 16 character LCD |
| SysEx Manufacturer ID | `00 20 29` (Focusrite/Novation) |
| Identity Reply ID | `00 20 08` (Evolution Electronics — misleading, ignore for SysEx) |
| Product type byte | `0x02` |

### Identity Reply (Universal SysEx 0x06 0x01)

```
F0 7E 7F 06 02  00 20 08  63 0E  50 02  20 31 32 35  F7
               └──mfr───┘ └fam┘ └mbr┘ └──rev " 125"─┘
```

> Note: the identity reply reports `00 20 08` (Evolution Electronics) but all
> operational SysEx uses `00 20 29` (Novation). Use `00 20 29` for everything.

---

## Display Layout

```
┌────────────────┐
│ Top    line    │  ← 13 visible chars, then device appends " <patch#>" (3 chars)
│ Bottom line    │  ← 16 visible chars, full width
└────────────────┘
```

The device firmware **always** appends a space and the current patch number
(`00`–`99`) to the end of the top line. Design top-line content accordingly.

---

## SysEx Message Format

There is no dedicated short "write display" command. The display is updated by
sending a full **template dump** with the name fields patched.

### Full Message Structure

```
F0 00 20 29 02 00 7F 00  [8198 bytes of template data]  F7
│  └──mfr ID──┘ │  │ └──── command ────┘
│               │  └─ device ID (0x00 = any)
│               └─ product type (0x02 = X-Station / Remote 25 Audio)
└─ SysEx start
```

Total length: **8208 bytes**

### Name Field Offsets (within the full 8208-byte message)

| Display line | Offset (hex) | Offset (dec) | Length | Notes |
|---|---|---|---|---|
| **Bottom** | `0x0D` | 13 | **16 bytes** | Full 16-char width |
| **Top** | `0x1E` | 30 | **13 bytes** | Device appends ` XX` patch number |

Both fields are plain ASCII, space-padded on the right.

### First 48 bytes annotated

```
Offset  Hex                                              ASCII
0x0000  F0 00 20 29 02 00 7F 00                          .. ).....
0x0008  00 18 03 00                                      ....        ← internal header
0x000C  27                                               '           ← field prefix byte (do not modify)
0x000D  ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **  BOTTOM LINE  ← 16 bytes, write here
0x001D  25                                               %           ← field prefix byte (do not modify)
0x001E  ** ** ** ** ** ** ** ** ** ** ** ** **           TOP LINE     ← 13 bytes, write here
0x002B  10 30 00 ...                                                  ← template data, do not touch
```

---

## How to Update the Display

### Algorithm

1. Keep a reference copy of the full 8208-byte template dump.
2. Patch bytes at the two offsets (bottom line first, then top line).
3. Send the entire 8208-byte buffer as a single SysEx message.
4. The device loads the template and immediately shows the new names.

### Python example

```python
import rtmidi

BOTTOM_OFFSET = 0x0D   # 13
TOP_OFFSET    = 0x1E   # 30
BOTTOM_LEN    = 16
TOP_LEN       = 13     # device appends " <patch#>" automatically

def pad(text: str, length: int) -> bytes:
    return text[:length].ljust(length).encode("ascii")

def make_display_sysex(template: bytearray, top: str, bottom: str) -> bytearray:
    msg = bytearray(template)
    msg[BOTTOM_OFFSET : BOTTOM_OFFSET + BOTTOM_LEN] = pad(bottom, BOTTOM_LEN)
    msg[TOP_OFFSET    : TOP_OFFSET    + TOP_LEN]    = pad(top,    TOP_LEN)
    return msg

# --- setup ---
with open("remote25audio_dump.syx", "rb") as f:
    template = bytearray(f.read())          # 8208 bytes

midi_out = rtmidi.MidiOut()
midi_out.open_port(0)                       # USB MIDI port of the X-Station

# --- update display ---
msg = make_display_sysex(template, top="Hello World  ", bottom="Line two text   ")
midi_out.send_message(msg)
```

### Swift / CoreMIDI example

```swift
func display(top: String, bottom: String,
             template: [UInt8], dest: MIDIEndpointRef, port: MIDIPortRef) {
    var msg = template
    let b = Array(bottom.padding(toLength: 16, withPad: " ", startingAt: 0).prefix(16).utf8)
    let t = Array(top   .padding(toLength: 13, withPad: " ", startingAt: 0).prefix(13).utf8)
    for i in 0..<16 { msg[0x0D + i] = b[i] }
    for i in 0..<13 { msg[0x1E + i] = t[i] }

    let size = MemoryLayout<MIDIPacketList>.size + msg.count + 16
    let buf = UnsafeMutableRawPointer.allocate(byteCount: size, alignment: 4)
    defer { buf.deallocate() }
    let pl  = buf.assumingMemoryBound(to: MIDIPacketList.self)
    var pkt = MIDIPacketListInit(pl)
    pkt = MIDIPacketListAdd(pl, size, pkt, 0, msg.count, msg)
    MIDISend(port, dest, pl)
}
```

---

## Performance

### DIN MIDI (5-pin, via M-Audio USB Uno or similar)

| Metric | Value |
|---|---|
| Baud rate | 31,250 bps |
| Effective byte rate | 3,125 bytes/sec |
| Transfer time (8208 bytes) | **~2.63 seconds** |
| Max update rate | **~0.38 Hz** |

DIN MIDI is **too slow for frequent updates**. One full template takes 2.6 s to
transmit — updates will queue up and the device will lag badly.

### USB MIDI (direct X-Station USB connection — recommended)

| Metric | Value |
|---|---|
| Transfer time (8208 bytes) | **~8 ms** |
| Max update rate | **~60–120 Hz** (limited by device processing) |

Connect the X-Station directly to the Mac via USB. It appears as a USB MIDI
device and the same SysEx message works identically, just ~300× faster.

> The M-Audio USB Uno translates USB↔DIN MIDI at 31,250 baud regardless of
> what speed the host sends. Bypass it by using the X-Station's own USB port.

---

## Obtaining the Template Dump

You must capture a reference dump from your specific device before you can
send display updates (the dump encodes the current template's controller
assignments, synth parameters, etc.).

**On the device:**
1. Press **MENU**
2. Navigate to **Global Settings** (or Utilities)
3. Select **Dump Current Template**
4. Press **WRITE**

**On the host (capture):**

```python
import rtmidi, time

midi_in = rtmidi.MidiIn()
midi_in.open_port(0)
midi_in.ignore_types(sysex=False)   # enable SysEx capture

buf = []
print("Perform the dump from the device now...")
deadline = time.time() + 30
while time.time() < deadline:
    msg = midi_in.get_message()
    if msg:
        data, _ = msg
        if data[0] == 0xF0:
            buf = list(data)
        elif buf:
            buf.extend(data)
            if data[-1] == 0xF7:
                with open("remote25audio_dump.syx", "wb") as f:
                    f.write(bytes(buf))
                print(f"Saved {len(buf)} bytes.")
                break
```

---

## Known Limitations

- **No short display-write command exists.** The full 8208-byte template must
  be retransmitted every time. Confirmed by probing all powers-of-two from
  44 bytes up to 6400 bytes — the device ignored every truncated payload and
  only accepted the full 8208-byte message (SysEx ID `0x2010` hex). The device
  likely validates the complete template (checksum or fixed-length guard) before
  updating the display.
- **Top line is 13 chars, not 16.** The firmware always appends ` <patch#>` to
  the top line, consuming the last 3 characters.
- **Template is modified in RAM.** The original template persists in flash until
  the user manually saves. Power-cycling the device restores the original name.
- **One template only.** This protocol writes to the currently selected
  template. Switching templates via Program Change will load a different name.
- **USB MIDI is mandatory for real-time use.** DIN MIDI at 31,250 baud cannot
  sustain update rates above ~0.38 Hz.
