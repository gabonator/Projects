# DDX10 Emulator — Confirmed Findings

## Key Addresses

| Symbol | Address | Notes |
|---|---|---|
| Plugin vtable | 0x1003f404 | MSVC RTTI, set at sub_10008b40 |
| AudioEffect vtable | 0x1003fd44 | set in sub_10010790 |
| AEffect struct | thisPtr + 0x20 | magic 'VstP' at +0x00 |
| editorPtr | thisPtr + 0x08 | |
| CFrame ptr | editorPtr + 0x10 | stored at end of sub_10001b10 line 2373 |
| presetBank ptr | thisPtr + 0xb0 | pointer to array of 0x60-byte preset structs |
| currentProgram | thisPtr + 0x1c | index into presetBank |

## AEffect Struct Layout (at thisPtr+0x20)

| Offset | Value | Description |
|---|---|---|
| +0x00 | 0x56737450 | magic 'VstP' |
| +0x04 | 0x10010680 | dispatcher fn ptr (sub_10010680) |
| +0x08 | processAudio | |
| +0x0c | 0x10010700 | setParameter fn ptr |
| +0x10 | 0x100106e0 | getParameter fn ptr |
| +0x40 | thisPtr | back-pointer to C++ Plugin object |

## Plugin vtable (0x1003f404)

| Slot | Offset | Address | Function |
|---|---|---|---|
| 0 | +0x00 | 0x10009fe0 | destructor |
| 1 | +0x04 | 0x100110b0 | dispatch() — routes opcodes 25..79, else calls sub_10010870 |
| 2 | +0x08 | 0x10008800 | processAudio |
| 3 | +0x0c | 0x10008800 | processAudio (dup) |
| 4 | +0x10 | 0x100087f0 | |
| 5 | +0x14 | 0x100087e0 | |
| 6 | +0x18 | 0x10008910 | setParameter (float store) |
| 7 | +0x1c | 0x10008920 | getParameter (float load) |
| 12 | +0x30 | 0x10010b70 | |
| 13 | +0x34 | 0x1000bc60 | getProgramName (effGetProgramName, opcode 5) |
| 14 | +0x38 | 0x1000bc70 | setProgram(index) — called for opcode 2 |
| 15 | +0x3c | 0x1000bcc0 | getCurrentProgram |
| 17 | +0x44 | 0x1000aeb0 | |
| 18 | +0x48 | 0x1000ac40 | |
| 19 | +0x4c | 0x1000aa00 | |
| 77 | +0x134 | 0x1000b7a0 | effProcessEvents MIDI parser |
| 97 | +0x184 | 0x1000a160 | effCanDo handler |
| 105 | +0x1a4 | 0x10011e80 | audioMasterUpdateDisplay notify (called after setProgram) |
| 152 | +0x260 | 0x10008810 | voice reset/init |
| 155 | +0x26c | 0x1000aee0 | voice DSP recompute |
| 156 | +0x270 | 0x1000ba30 | voice allocator (called from processReplacing) |

## Dispatcher Chain

### sub_10010680 — AEffect dispatcher wrapper
- Reads opcode from stack, loads Plugin C++ object from `[pluginPtr+0x40]`
- opcode == 1 → direct vtable[1] call with ptr arg
- opcode != 1 → calls vtable[1] = sub_100110b0 with (opcode, value, ptr, opt)

### sub_100110b0 — Plugin::dispatch() vtable[1]
Switch on `opcode - 25` (handles opcodes 25..79). Out-of-range → sub_10010870.

| opcode | edx (opcode-25) | address | name |
|---|---|---|---|
| 25+0=25 | 0 | 0x100110cd | effProcessEvents → vtable[0x134] |
| 25+1=26 | 1 | 0x100110e3 | → vtable[0xc8] |
| 25+2=27 | 2 | 0x10011102 | → vtable[0xcc] |
| 25+4=29 | 4 | 0x10011126 | → vtable[0xdc] |
| 25+8=33 | 8 | 0x1001114f | → vtable[0x150] |
| 25+13=38 | 13 | 0x100111a8 | |
| 25+14=39 | 14 | 0x100111d1 | |
| 25+15=40 | 15 | 0x100111ef | |
| 25+26=51 | 26 | 0x10011294 | effCanDo → vtable[0x184] |
| 25+33=58 | 33 | 0x10011356 | |

### sub_10010870 — AudioEffect base dispatch (opcodes 0..24)

| opcode | case | calls | name |
|---|---|---|---|
| 0 | 0x10010887 | vtable[0x08] | effOpen |
| 1 | 0x10010894 | vtable[0x0c] | effClose |
| 2 | 0x100108a1 | vtable[0x38] = sub_1000bc70 | effSetProgram |
| 3 | 0x100108bc | vtable[0x34] | effGetProgram |
| 4 | 0x100108c9 | vtable[0x3c] | effGetProgramName ptr arg |
| 5 | 0x100108db | vtable[0x40] | effSetProgramName |
| 6 | 0x100108ed | vtable[0x44] | effGetParamLabel |
| 7 | 0x10010904 | vtable[0x48] | effGetParamDisplay |
| 8 | 0x1001091b | vtable[0x4c] | effGetParamName |
| 10 | 0x10010932 | vtable[0x54] | effSetSampleRate |
| 11 | 0x10010947 | vtable[0x58] | effSetBlockSize |
| 12 | 0x10010959 | vtable[0x5c] | effMainsChanged |
| 13 | 0x1001096c | vtable[0x60] | effEditGetRect |
| 14 | 0x10010993 | vtable[0x64] | effEditOpen |
| 15 | 0x100109ba | vtable[0x68] | effEditClose |
| 19 | 0x100109cf | vtable[0x78] | effEditIdle |
| 22 | 0x100109e4 | vtable[0x84] | |
| 23 | 0x100109ef | vtable[0x88] | |

## Preset Struct (0x60 bytes per preset, bank at thisPtr+0xb0)

```
presetBase = presetBank + 0x60 * currentProgram
```

| Offset | Type | Parameter name |
|---|---|---|
| +0x00 | float | **Slider 0** — Modulation Coarse |
| +0x04 | float | **Slider 1** — Modulation Fine |
| +0x08 | float | **Slider 2** — Envelope Initial |
| +0x0c | float | **Slider 3** — Envelope Decay |
| +0x10 | float | **Slider 4** — Envelope Sustain |
| +0x14 | float | **Slider 5** — Envelope Release |
| +0x18 | float | **Slider 6** — Modulation Velocity |
| +0x1c | float | **Slider 7** — Modulation Wave |
| +0x20 | float | **Slider 8** — Modulation Thru |
| +0x24 | float | **Slider 9** — Amp Envelope Attack |
| +0x28 | float | **Slider 10** — Amp Envelope Decay |
| +0x2c | float | **Slider 11** — Amp Envelope Release |
| +0x30 | float | **Knob 0** (leftmost pair) |
| +0x34 | float | **Knob 1** (leftmost pair) |
| +0x38 | float | **Knob 2** (rightmost group) |
| +0x3c | float | **Knob 3** (rightmost group) |
| +0x40 | float | **Knob 4** (rightmost group) |
| +0x44 | char[24] | preset name (null-terminated, max 24 chars) |

**Reading preset name:**
```javascript
const presetBank  = memoryAGet32(ds, thisPtr + 0xb0);
const currentProg = memoryAGet32(ds, thisPtr + 0x1c);
const namePtr     = presetBank + 0x60 * currentProg + 0x44;
const name        = readstring(namePtr);
```

**getProgramName:** sub_1000bcf0 — copies name via strncpy(dst, presetBase+0x44, 0x18)

**setProgram:** sub_1000bc70 — clamps index to [0,98], writes to thisPtr+0x1c, calls vtable[152] (voice reset), vtable[155] (voice DSP recompute), vtable[105] (audioMasterUpdateDisplay)

## VSTGUI Widget Memory Layout (CView)

All widgets inherit CView:
```
[widget + 0x00] = vtable ptr
[widget + 0x04] = refcount
[widget + 0x08] = CRect.left
[widget + 0x0c] = CRect.top
[widget + 0x10] = CRect.right
[widget + 0x14] = CRect.bottom
```

CControl additional fields:
```
[widget + 0x44] = CControlListener* listener   ← NOTE: REVERSED from standard VSTGUI docs
[widget + 0x48] = long tag (parameter index)   ← confirmed by runtime probe
[widget + 0x4c] = value (float, current normalized 0..1)
[widget + 0x50] = defaultValue (set by sub_100012c0)
[widget + 0x54] = vmin
[widget + 0x58] = vmax
```

CParamDisplay / CTextLabel / CTextEdit fields:
```
[widget + 0x74] = font ptr
[widget + 0x78] = ?
[widget + 0x8c] = font (GDI+ font ptr)
[widget + 0x90..0x93] = font color RGBA
[widget + 0x94..0x97] = frame color RGBA
[widget + 0x98..0x9b] = shadow color RGBA
[widget + 0xa0] = style/alignment byte
[widget + 0xa4] = char* text (heap-allocated, malloc'd copy of string)
```

**Reading widget text:**
```javascript
const textPtr = memoryAGet32(ds, widgetPtr + 0xa4);
const text = textPtr ? readstring(textPtr) : '';
```

## Widget Vtables

| Widget | Vtable | Notes |
|---|---|---|
| TextLabel | 0x1003e89c | |
| TextEdit | 0x1003ea0c | |
| OptionMenu | 0x1003eb8c | |
| TooltipKnob | 0x1003f864 | |
| TooltipDisplay | 0x1003fb5c | NOT added to CFrame — knob-internal |
| TooltipSlider | 0x1003f9f4 | |
| CSplashScreen | 0x10040c74 | |
| CParamDisplay | 0x10040084 | |
| CControl | 0x1003ff24 | |
| CKickButton | 0x10040b2c | |
| CFrame | 0x10040fcc | |

## VSTGUI vtable slots — draw/drawRect (confirmed by comparing all text widget vtables)

Slot 88 (+0x160) is `draw(CDrawContext*)`, slot 87 (+0x15c) is `drawRect(CDrawContext*, CRect&)`.
The CFrame's drawRect iterates children and calls child vtable[87]. Most widgets inherit the
default drawRect which simply calls draw(). CTextEdit overrides it to manage the native HWND.

| Slot | Offset | CControl (base) | CParamDisplay | CTextLabel (VSTGUI) | TextLabel (DDX10) | TextEdit (DDX10) | CTextEdit (VSTGUI) | CFrame |
|---|---|---|---|---|---|---|---|---|
| 84 | +0x150 | 0x10001ad0 | 0x100143d0 | 0x100143d0 | 0x100143d0 | 0x100143d0 | 0x100141a0 | 0x1001af50 |
| 85 | +0x154 | 0x10017c10 | 0x10014400 | 0x10014400 | 0x10014400 | 0x10014400 | 0x100141e0 | 0x100187b0 |
| 86 | +0x158 | 0x0         | 0x10013c40 | 0x10013c40 | 0x10013c40 | 0x10013c40 | 0x10014250 | 0x1001afb0 |
| **87** | **+0x15c** | 0x10048948 | **0x100013d0** | **0x100013d0** | **0x100013d0** | **0x100013d0** | **0x100142c0** | **0x1001afd0** |
| **88** | **+0x160** | 0x10013a80 | **0x10013d20** | **0x10013d20** | **0x10013d20** | **0x10013d20** | 0x10014330 | 0x1001aff0 |
| 89 | +0x164 | 0x10019820 | 0x10048934 | 0x10014560 | 0x10014560 | 0x10014750 | 0x100013c0 | 0x1001b040 |
| 90 | +0x168 | 0x10001000 | 0x10014470 | 0x10014610 | 0x10014610 | 0x10001520 | 0x100143a0 | 0x1001b0c0 |
| 91 | +0x16c | 0x10019c90 | 0x10019820 | 0x10048920 | 0x10047708 | 0x10014800 | 0x100143e0 | 0x1001b210 |
| 92 | +0x170 | 0x10013c70 | 0x10001000 | 0x10001930 | 0x10001930 | 0x10014ef0 | 0x100143d0 | 0x100187c0 |
| 93 | +0x174 | 0x10001010 | 0x10019c90 | 0x10019820 | 0x10019820 | 0x10014ee0 | 0x10014400 | 0x1001b1f0 |

### drawRect addresses by class

| Class | Vtable | Slot 87 address | Behaviour |
|---|---|---|---|
| TextLabel (DDX10) | 0x1003e89c | 0x100013d0 | default — calls draw() |
| TextEdit (DDX10) | 0x1003ea0c | 0x100013d0 | default — calls draw() |
| OptionMenu (DDX10) | 0x1003eb8c | 0x100013d0 | default — calls draw() |
| CParamDisplay | 0x10040084 | 0x100013d0 | default — calls draw() |
| VSTGUI::CTextEdit | 0x100404bc | **0x100142c0** | override — shows/hides native Win32 EDIT HWND |
| CFrame | 0x10040fcc | **0x1001afd0** | CViewContainer — iterates children, calls child->drawRect() |

### setText addresses by class (slot 89)

| Class | Address |
|---|---|
| CParamDisplay | 0x10048934 |
| CTextLabel (VSTGUI base) | 0x10014560 |
| TextLabel (DDX10) | 0x10014560 |
| TextEdit (DDX10) | 0x10014750 |
| VSTGUI::CTextEdit | 0x100013c0 |

## Text Rendering Call Chain

```
CFrame::drawRect (0x1001afd0)          iterates children, calls child vtable[87]
  → TextEdit drawRect (0x100013d0)     CView default: just calls draw()
    → draw() (0x10013d20)              CParamDisplay::draw — reads widget fields
      → FUN_100196c0                   fill background, set GDI+ text hint
        → FUN_100195b0                 char*→wchar_t, build RectF from widget rect
          → FUN_10018210               thin GdipDrawString wrapper
            → GdipDrawString (import)
```

draw() (0x10013d20) reads from `this` (the widget object):
- text string at `[widget+0xa4]`  (heap char*, set via setText)
- font at `[widget+0x8c]`         (GDI+ Font*)
- font color RGBA at `[widget+0x90..0x93]`
- rect at `[widget+0x08..0x14]`

## CFrame Children Storage (custom emulator extension)

CFrame is allocated 0x200 bytes. Children tracking added at end of object:
```
[frame + 0x100] = child count
[frame + 0x104 + i*4] = child_ptr[i]   (for i = 0..count-1)
```

## TooltipKnob (CAnimKnob) Layout

**No tag is stored in the knob widget itself.** The parameter index is implicit from the knob's position in the editor's pointer array (at `editorPtr + 0x2c + knobIndex*8`).

Knob widget fields confirmed by runtime probe:
```
[knob + 0x00] = vtable = 0x1003f864
[knob + 0x04] = refcount = 1
[knob + 0x08] = CRect.left
[knob + 0x0c] = CRect.top
[knob + 0x10] = CRect.right
[knob + 0x14] = CRect.bottom
[knob + 0x50] = defaultValue (float, set by sub_100012c0; some knobs = 0.5 or 1.0)
[knob + 0xa4] = 0x41a00000 (float 20.0 — sprite frame count - 1)
[knob + 0xd0] = 0x1003f9dc (inner TooltipDisplay vtable ptr)
```

Fields +0x44 (listener), +0x48 (tag), +0x4c (value) are all 0 — knob does not use CControl tag.
The current value is read directly from the preset struct, not from the widget.

**Knob positions and editor pointer slots:**
| Knob index | editor offset | rect (left,top)-(right,bot) | VST param | Preset offset |
|---|---|---|---|---|
| 0 | +0x2c | (64,80)-(128,144) | 15 | +0x30 |
| 1 | +0x34 | (136,80)-(200,144) | 9 | +0x34 |
| 2 | +0x3c | (584,80)-(648,144) | 10 | +0x38 |
| 3 | +0x44 | (656,80)-(720,144) | 0 | +0x3c |
| 4 | +0x50 | (728,80)-(792,144) | 16 | +0x40 |

Note: `editor+0x30`, `+0x38`, `+0x40`, `+0x48`, `+0x4c` hold the paired TooltipDisplay objects.

Reading knob value for SVG rendering — use preset float directly:
```javascript
// knobIndex 0..4
const presetOffset = [0x30, 0x34, 0x38, 0x3c, 0x40][knobIndex];
const value = FromFp32(memoryAGet32(ds, presetBase + presetOffset));
// frameIndex = Math.round(value * 100);  // 0..100 into 64×6464 Knob sprite sheet
```

## CSlider (TooltipSlider) Layout

sub_10016950 constructs the slider and stores:
```
[slider + 0x74] = handle bitmap ptr
[slider + 0x78] = handle bitmap width
[slider + 0x84] = background bitmap ptr
[slider + 0x8c] = handle width (from bitmap)
[slider + 0x90] = handle height (from bitmap)
[slider + 0x94] = iMaxPos - iMinPos  = 112 (travel range in px)
[slider + 0xa0] = iMinPos - rect.top = 0   (relative min position)
[slider + 0xa4] = rect width
[slider + 0xa8] = rect height
[slider + 0xac] = current value (float 0..1)
```

Handle Y position: `handleY = rect.top + Math.round((1 - value) * 112)` — value=0 at bottom, value=1 at top.
Note: slider `value` field at widget+0x4c is initialized to 0 at construction (stub), so read directly from preset floats.
Preset float → slider: offsets +0x00..+0x2c = slider 0..11; offsets +0x30..+0x40 = knob 0..4.

Reading slider values for SVG:
```javascript
const presetFloats = [];
for (let i = 0; i <= 16; i++) presetFloats.push(FromFp32(memoryAGet32(ds, presetBase + i*4)));
// sliders: presetFloats[0..11]; knobs: presetFloats[12..16]
```

## CKickButton Layout

Two CKickButton widgets (Prev/Next preset):
```
[widget + 0x00] = vtable = 0x10040b2c
[widget + 0x44] = listener ptr (DDX10Editor + 0x24)
[widget + 0x48] = tag:  0x68 (104) = Prev button,  0x67 (103) = Next button
[widget + 0x74] = bitmap ptr = 0x10040c60
[widget + 0x78] = 0x10 (bitmap width = 16)
[widget + 0x7c] = 0
[widget + 0x80] = 0
```

Button positions (from runtime probe):
- Prev button: rect (320, 112)–(336, 128), tag 0x68
- Next button: rect (336, 112)–(352, 128), tag 0x67

CKickButton vtable slots (all at vtable 0x10040b2c):

| Slot | Offset | Address | Status | Role |
|---|---|---|---|---|
| 8 | +0x20 | 0x10012a00 | implemented | setEnabled — sets widget+0x30, updates value |
| 9 | +0x24 | 0x10019d20 | ddx10handlers.js | mouse forwarder |
| 10 | +0x28 | 0x10001050 | **MISSING** | unknown |
| 11 | +0x2c | 0x10019f40 | **MISSING** | unknown |
| 12 | +0x30 | 0x10017470 | ddx10handlers.js | onMouseDown |
| 13 | +0x34 | 0x100174b0 | ddx10handlers.js | onMouseUp — calls valueChanged |
| 14 | +0x38 | 0x10017510 | ddx10handlers.js | onMouseMoved |
| 68 | +0x110 | 0x10012970 | **MISSING** | called from onMouseDown |
| 69 | +0x114 | 0x100129b0 | **MISSING** | called from onMouseUp |
| 7 | +0x1c | 0x100129e0 | **MISSING** | called from onMouseUp |
| 10 | +0x28 | 0x10001050 | **MISSING** | called from onMouseUp |

## OptionMenu Layout

```
[widget + 0x00] = vtable = 0x1003eb8c
[widget + 0x44] = listener ptr (DDX10Editor + 0x24)
[widget + 0x48] = tag 0x69 (105)
[widget + 0xc8] = secondary listener
[widget + 0xb4] = current selection index (set by sub_10001990)
```

OptionMenu vtable slots (unique to OptionMenu unless noted as shared):

| Slot | Offset | Address | Status | Role |
|---|---|---|---|---|
| 7 | +0x1c | 0x100129e0 | **MISSING** | shared with CKickButton |
| 10 | +0x28 | 0x10001050 | **MISSING** | shared with CKickButton |
| 12 | +0x30 | 0x10001990 | ddx10handlers.js | onMouseDown — builds menu, calls valueChanged |
| 41 | +0xa4 | 0x10016470 | **MISSING** | |
| 67 | +0x10c | 0x100012f0 | **MISSING** | getValue |
| 68 | +0x110 | 0x10012970 | **MISSING** | shared with CKickButton |
| 69 | +0x114 | 0x100129b0 | **MISSING** | shared with CKickButton |
| 89 | +0x164 | 0x100156b0 | **MISSING** | setText (adds menu item strings) |
| 92 | +0x170 | 0x10015790 | **MISSING** | |
| 99 | +0x18c | 0x10015b40 | **MISSING** | |

## IControlListener (DDX10Editor)

DDX10Editor has an IControlListener sub-object at offset +0x24.
Vtable for this sub-object is at 0x1003ee2c:

| Slot | Offset | Address | Role |
|---|---|---|---|
| 0 | +0x00 | 0x100043b0 | this-ptr adjustment thunk (subtracts 0x24, jumps to real destructor at 0x100104d0) |
| 1 | +0x04 | 0x10010510 | **valueChanged(CControl\*)** — the actual dispatch handler |

`sub_10010510` (valueChanged) flow:
1. Reads complete DDX10Editor ptr via `[listener - 0x20]`
2. Calls vtable[0xdc] (addView/invalidate) on the control's parent
3. Calls vtable[0x10c] (getValue) on the control → `sub_100012f0`
4. Calls vtable[0x30] on DDX10Editor to dispatch setParameter/effSetProgram
5. Calls vtable[0x20] (redraw) on the control's parent

## crt.js — New AEffect Parameter Functions (added this session)

| Address | Function | Role |
|---|---|---|
| 0x1000a200 | sub_1000a200 | Plugin::setParameter(index, float) — writes preset float via paramIndexToPresetOffset[] |
| 0x1000a820 | sub_1000a820 | Plugin::getParameter(index) — reads preset float, returns in FPU ST(0) |
| 0x10010700 | AEffect.setParameter wrapper | cdecl(AEffect*, index, float) → calls sub_1000a200 |
| 0x100106e0 | AEffect.getParameter wrapper | cdecl(AEffect*, index) → calls sub_1000a820, returns ST(0) |

**Also added**: `paramIndexToPresetOffset[]` array mapping VST param indices 0..16 to preset byte offsets.
**Also fixed**: `0x1000a820` indirectCall case was a zero-returning stub; replaced with real implementation.

## ddx10handlers.js — Status

Functions implemented in ddx10handlers.js (need registration in crt.js + loading in test.html):

| Address | Function | Role |
|---|---|---|
| 0x100012c0 | sub_100012c0 | Stores float arg to widget+0x50 (defaultValue). Replaces old stub in crt.js. |
| 0x10001990 | sub_10001990 | OptionMenu onMouseDown |
| 0x100043b0 | sub_100043b0 | IControlListener vtable[0] — destructor thunk |
| 0x10010510 | sub_10010510 | IControlListener valueChanged |
| 0x10017470 | sub_10017470 | CKickButton onMouseDown |
| 0x100174b0 | sub_100174b0 | CKickButton onMouseUp (triggers valueChanged) |
| 0x10017510 | sub_10017510 | CKickButton onMouseMoved |
| 0x10019d20 | sub_10019d20 | Mouse event forwarder |
| 0x1001f9a6 | sub_1001f9a6 | Heap free helper (destructor path) |
| 0x10026fd0 | sub_10026fd0 | Exception frame setup |
| 0x10027444 | sub_10027444 | EnterCriticalSection wrapper |
| 0x10027477 | sub_10027477 | Heap segment lookup |
| 0x100274a7 | sub_100274a7 | Free heap block (linked list) |

**Integration TODOs:**
1. Add `<script src="ddx10handlers.js"></script>` to test.html (after ddx10gui.js)
2. Add case entries to crt.js indirectCall for all 12 addresses above
3. Remove old `sub_100012c0` stub from crt.js (replaced by ddx10handlers.js version)
4. Stub `ole32::OleUninitialize` (called from sub_100043b0 destructor)

**Still missing (need Ghidra) — critical for CKickButton:**
`sub_10001050` (0x10001050), `sub_10019f40` (0x10019f40), `sub_10012970` (0x10012970),
`sub_100129b0` (0x100129b0), `sub_100129e0` (0x100129e0), `sub_100012f0` (0x100012f0)

**Still missing — critical for OptionMenu:**
`sub_100156b0` (0x100156b0), `sub_10015790` (0x10015790), `sub_10015b40` (0x10015b40), `sub_10016470` (0x10016470)

**Still missing — heap management (destructor path only, less urgent):**
`sub_1001ff47`, `sub_10024be4`, `sub_10024c26`, `sub_100267e0`, `sub_10027015`, `sub_10027381`, `sub_1002a3b5`

## MIDI Delivery

```javascript
// Internal queue at thisPtr+0xdb8: [deltaFrames, note, velocity, sentinel=0x5f5e0ff]
// Deliver via:
push32(0); push32(eventsPtr); push32(0); push32(0); push32(25); push32(pluginPtr);
indirectCall(cs, dispatcherPtr); r32[esp] += 24;
// → vtable[77] = 0x1000b7a0 = effProcessEvents MIDI parser
```

## VST Parameter Index → Preset Offset Mapping

Decoded from `sub_1000a200` (setParameter) and `sub_1000a820` (getParameter) binary jump tables.
These are called via the AEffect wrappers at 0x10010700 and 0x100106e0 respectively.

**Calling convention:**
- `sub_1000a200`: ecx=thisPtr, stack=[index, float_value] (callee pops 2)
- `sub_1000a820`: ecx=thisPtr, stack=[index] (callee pops 1, returns float in FPU ST0)
- `sub_10010700` (AEffect.setParameter): cdecl(AEffect*, index, float), caller pops 3
- `sub_100106e0` (AEffect.getParameter): cdecl(AEffect*, index), caller pops 2, returns ST0

**Implementation in crt.js**: `paramIndexToPresetOffset[]`, `sub_1000a200()`, `sub_1000a820()`, and `indirectCall` cases for `0x10010700` and `0x100106e0`.

| VST param index | Preset struct byte offset | Name (from CLAUDE.md preset layout) |
|---|---|---|
| 0 | +0x3c | Knob 3 (rightmost group) |
| 1 | +0x28 | Slider 10 — Amp Envelope Decay |
| 2 | +0x0c | Slider 3 — Envelope Decay |
| 3 | +0x10 | Slider 4 — Envelope Sustain |
| 4 | +0x14 | Slider 5 — Envelope Release |
| 5 | +0x18 | Slider 6 — Modulation Velocity |
| 6 | +0x1c | Slider 7 — Modulation Wave |
| 7 | +0x20 | Slider 8 — Modulation Thru |
| 8 | +0x24 | Slider 9 — Amp Envelope Attack |
| 9 | +0x34 | Knob 1 (leftmost pair) |
| 10 | +0x38 | Knob 2 (rightmost group) |
| 11 | +0x00 | Slider 0 — Modulation Coarse |
| 12 | +0x04 | Slider 1 — Modulation Fine |
| 13 | +0x08 | Slider 2 — Envelope Initial |
| 14 | +0x2c | Slider 11 — Amp Envelope Release |
| 15 | +0x30 | Knob 0 (leftmost pair) |
| 16 | +0x40 | Knob 4 (rightmost group) |

Indices 17+ (up to 0x69=105) dispatch to additional handlers (program/voice control), not yet implemented.

## Known Bug Fixes

1. `faddpst(3)` fix at ddx10.js ~line 2578 (was wrong FADDP target)
2. Removed bad global constant overrides from main.js
3. Removed BUGFIX block in sub_1000b180 that overwrote deltaFrames=0
4. Don't call dispatcher opcode 5 with ptr=0 (opcode 5 = effSetProgramName, not effGetProgramName)
5. `fmulst(i)` / `faddst(i)` fix in fpu.js — must write back to ST(0), not ST(i)

## Import Table Addresses

Base: `0x6ab00000` (sequential enum in ddx10.js). Key GDI+ entries used for rendering:

- `ptr_gdiplus_GdipDrawString` — text draw call (in FUN_10018210)
- `ptr_gdiplus_GdipMeasureString` — text measurement
- `ptr_gdiplus_GdipSetTextRenderingHint` — antialiasing
- `ptr_gdiplus_GdipCreateFont` / `GdipCreateFontFamilyFromName` — font creation
- `ptr_gdiplus_GdipFillRectangle` — background fill
- `ptr_gdiplus_GdipCreateSolidFill` / `GdipSetSolidFillColor` — brush for text color
- `ptr_user32_CreateWindowExW` — creates native HWND EDIT control (TextEdit edit mode)
- `ptr_user32_GetWindowTextW` — reads typed text from native EDIT on commit

## Resource Images (res/ folder)

| Log name | File | Usage |
|---|---|---|
| Background | res/BACKGROUND.png | Full canvas background |
| Splashscreen | res/SPLASHSCREEN.png | CSplashScreen widget |
| Knob | res/KNOB.png | Sprite sheet: 101 frames × 64×64px (64×6464 total) |
| SliderBack | res/SLIDERBACK.png | 48×128 slider background |
| SliderHandle | res/SLIDERHANDLE.png | 48×16 slider handle (overlaid on SliderBack) |
| Next | res/NEXT.png | CKickButton (next preset) |
| Prev | res/PREV.png | CKickButton (prev preset) |
| MenuInactive | res/MENUINACTIVE.png | OptionMenu inactive state |
| MenuActive | res/MENUACTIVE.png | OptionMenu active state |

**Knob sprite:** frame index 0..100 = value 0..100%. SVG crop: `viewBox="0 {frameIndex*64} 64 64"`.

**Slider handle position:** `handleY = widget.top + (1 - value) * 112` — value=0 at bottom, value=1 at top.
