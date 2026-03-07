function allocate(size)
{
    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    for (var i=0; i<size; i++) if (memoryAGet(0, ptr+i) != 0) throw "not clean"
    allocatorPtr += size;
    return ptr;
}

function sub_1001ef91()
{
    const size = stack32(0);

    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    for (var i=0; i<size; i++) if (memoryAGet(0, ptr+i) != 0) throw "not clean"
    allocatorPtr += size;
    r32[eax] = ptr;  
}

// operator new(size_t) — same bump allocator, never throws
const sub_1001fa1d = sub_1001ef91;


function sub_10020d33()
{
  // eh_vector_constructor_iterator
  const ptr = stack32(0);
  const elementSize = stack32(1);
  const elementCount = stack32(2);
  const ctorFunc = stack32(3);
  const dtorFunc = stack32(4);
  console.log("eh_vector_constructor_iterator", ptr.toString(16), elementSize, elementCount,
    ctorFunc.toString(16), dtorFunc.toString(16))
  for (let i=0; i<elementCount; i++)
  {
    r32[ecx] = ptr + elementSize*i;
    switch (ctorFunc)
    {
      case 0x100105f0: sub_100105f0(); break;
      case 0x1000c040: sub_1000c040(); break;
      default:
        console.assert("no indirect ctor")
    }
 }
}

function readstring(ptr)
{
    let str = "";
    for (let i=0; i<200; i++)
    {
      const c = memoryAGet(0, ptr+i);
      if (c == 0)
        break;
      str += String.fromCharCode(c);
    }
    return str;
}

function sub_10020480()
{
  // strncpy
  const dst = stack32(0);
  const src = stack32(1);
  const len = stack32(2);
  console.log(readstring(src));
  for (let i=0; i<len; i++)
  {
    const c = memoryAGet(0, src+i);
    memoryASet(0, dst+i, c);
    if (!c)
      break;
  }
}

function sub_10028e30()
{
  // memset
  const ptr = stack32(0);
  const val = stack32(1);
  const len = stack32(2);
  for (let i=0; i<len; i++)
    memoryASet(0, ptr+i, val);
}

function sub_10035bb0()
{
  // trunc
  const v = FromFp64(memoryAGet64(0, r32[esp]));
  console.log("sub_10035bb0 - trunc ", v, Math.trunc(v))
//fppush(v);
  fppush(Math.floor(v));
}

function sub_10010470()
{
  // AEffGUIEditor constructor: this (esi) = editor object, edi = plugin thisPtr (effect*)
  // Store effect* into editor+4 (the AEffGUIEditor::effect field)
  memoryASet32(ds, r32[esi] + 0x4, r32[edi]);
  r32[eax] = r32[esi];
}

function sub_10008980()
{
  // LEA eax, [ecx+0x20] — returns pointer to AEffect+0x20 (start of process buffers / voice data)
  r32[eax] = r32[ecx] + 0x20;
}

function sub_10035500()
{
  setst(0, Math.sin(st(0)));
}


function sub_10035630(x) {
  setst(0, Math.cos(st(0)));
}


// sub_100358cc: MSVC CRT sin() wrapper
// Input:  ST(0) = angle (radians)
// Output: ST(0) = sin(angle)
function sub_100358cc() {
// TODO: CHECK!!
//console.log("sub_100358cc - sin", st(0), Math.sin(st(0)));
//    setst(0, Math.sin(st(0)));
setst(0, Math.exp(st(0)));
}

// sub_10035960: MSVC CRT pow() function wrapper with floating-point exception checking
//
// This is Microsoft Visual C++ Runtime Library's implementation of pow(base, exponent).
// It wraps the actual IEEE 754-compliant power function (FUN_100372e0 -> FUN_100372f9)
// with floating-point exception state validation.
//
// Function behavior:
// 1. Checks global flag DAT_100505ec to see if FPU exception checking is enabled
// 2. If enabled:
//    - Reads MXCSR register (SSE control/status) via STMXCSR instruction
//    - Checks if all SSE exceptions are masked (bits 0x1f80)
//    - Reads FPU control word via FNSTCW instruction  
//    - Checks if all FPU exceptions are masked (bits 0x7f)
// 3. If exceptions are properly masked, calls FUN_100372e0 which implements pow()
// 4. The actual pow implementation handles special cases:
//    - NaN propagation
//    - Infinity handling  
//    - Zero base cases
//    - Negative base with fractional exponent (returns NaN)
//    - Over/underflow detection
//
// Calling convention:
// - Arguments passed on FPU stack after FXCH exchange at call site
// - ST(0) = exponent (double)
// - ST(1) = base (double)  
// - Returns result in ST(0)
//
// The function ultimately chains to a complex IEEE 754 implementation that uses
// logarithmic identities: pow(x,y) = exp(y * log(x))
function sub_10035960() {
    // Get arguments from FPU stack
    // After FXCH at call site: ST(0) = exponent, ST(1) = base
    const exponent = st(0);
    const base = st(1);
    console.log("sub_10035960 - pow(", base, exponent, ")")
    // Pop both arguments from FPU stack
    fppop();
    fppop();
    
    // Calculate pow(base, exponent) and push result
    // JavaScript's Math.pow handles all the IEEE 754 special cases:
    // - pow(NaN, y) = NaN
    // - pow(x, NaN) = NaN
    // - pow(x, 0) = 1
    // - pow(1, y) = 1
    // - pow(x, Infinity) = Infinity (if |x| > 1)
    // - pow(x, -Infinity) = 0 (if |x| > 1)
    // - pow(Infinity, y) = Infinity (if y > 0)
    // - pow(-x, non-integer) = NaN
    fppush(Math.pow(base, exponent));
}

// sub_10035bb0: MSVC CRT sqrt() wrapper
// Caller pops argument off FPU stack into [ESP] via fstp64, then calls here.
// This function reads from [ESP] and PUSHES sqrt result onto FPU stack.
/*
function sub_10035bb0() {
    const val = FromFp64(memoryAGet64(ds, r32[esp]));
    fppush(Math.sqrt(val));
}
*/
// sub_1000b100: MSVC CRT cos() wrapper (memory-arg form)
// Caller pops argument off FPU stack into [ESP] via fstp64 (or memoryASet64),
// then calls here. This function reads from [ESP] and PUSHES cos result onto FPU stack.
function sub_1000b100() {
    const val = FromFp64(memoryAGet64(ds, r32[esp]));
    fppush(Math.cos(val));
}




function indirectCall(s, o)
{
  switch (o)
  {
    case 0x10008810: sub_10008810(); break;
    case 0x1000aee0: sub_1000aee0(); break;
    case 0x10011e80: sub_10011e80(); break;
    case 0x10010680: sub_10010680(); break;
    case 0x100110b0: sub_100110b0(); break;
    case 0x77778888: audioMasterHandler(); break;
    case 0x10008800: break;
    case 0x1000b180: // Voice DSP processing
      const voiceDspThis = r32[ecx]; // __thiscall: thisPtr is in ECX
      const voiceCount = memoryAGet32(ds, voiceDspThis + 0xfbc);
      if (voiceCount > 0) {
        console.log(">>> Voice DSP 0x1000b180 called with", voiceCount, "active voices");
      }
      sub_1000b180();
      break;
    case 0x1000b7a0: 
        console.log(">>> Note on handler");
      sub_1000b7a0(); break;
    case 0x100087e0: sub_100087e0(); break;
    case 0x1000bc70: sub_1000bc70(); break;
    case 0x1000ba30: sub_1000ba30(); break;
    case 0x10008910: sub_10008910(); break;
    case 0x10008920: sub_10008920(); break;
    case 0x10008a30: // effProcessEvents MIDI handler
      console.log(">>> MIDI handler 0x10008a30 called!");
      console.log("    Stack args:", {
        arg0: "0x" + stack32(0).toString(16),
        arg1: "0x" + stack32(1).toString(16),
        arg2: "0x" + stack32(2).toString(16),
        arg3: "0x" + stack32(3).toString(16)
      });
      // Check what this pointer and voice count are
      const midiThis = stack32(0); // Likely 'this' pointer
      console.log("    [this+0xfc0] (voice count) =", memoryAGet32(ds, midiThis + 0xfc0));
      console.log("    [this+0xfbc] (active voices) =", memoryAGet32(ds, midiThis + 0xfbc));
      
      // Now call the actual function
      sub_10008a30();
      
      console.log("<<< MIDI handler returned, eax =", r32[eax]);
      console.log("    [this+0xfbc] (active voices after) =", memoryAGet32(ds, midiThis + 0xfbc));
      break;
    case 0x1000bcf0: sub_1000bcf0(); break;
    case 0x10010750: sub_10010750(); break;
    case 0x1000a160: sub_1000a160(); break;
    case 0x100087f0: sub_100087f0(); break;
    // gui
    case 0x100012c0: sub_100012c0(); break;
    case 0xff6ab013: r32[esp] += 4; break; // setBackground — ignore
    case 0xff6ab014: { // CFrame::addView(CView* child)
      const cnt = memoryAGet32(ds, r32[ecx] + 0x100);
      memoryASet32(ds, r32[ecx] + 0x104 + cnt * 4, memoryAGet32(ds, r32[esp]));
      memoryASet32(ds, r32[ecx] + 0x100, cnt + 1);
      r32[esp] += 4;
      break; }
    case 0x1000a820: sub_1000a820(); break; // getParameter(idx) — returns float via FPU
    // knob widget float setter/getter pairs (field@ecx+0x54, +0x58, +0x5c)
    case 0x10001240: sub_10001240(); return;
    case 0x10001250: sub_10001250(); return;
    case 0x10001260: sub_10001260(); return;
    case 0x10001270: sub_10001270(); return;
    case 0x10001280: sub_10001280(); return;
    case 0x10001290: sub_10001290(); return;
    case 0x1000ff90: sub_1000ff90(); return;
    case 0x10010380: sub_10010380(); return;
    case 0x10012a00: sub_10012a00(); return;
    case 0x10001000: sub_10001000(); return;
    case 0x10019820: sub_10019820(); return;
    case 0x100143d0: sub_100143d0(); return;
    case 0x10010170: sub_10010170(); return;
    case 0x10001620: sub_10001620(); return;
    case 0x1001d6c0: sub_1001d6c0(); return;
    // ddx10handlers.js — GUI event handlers
    case 0x10001990: sub_10001990(); break;
    case 0x100043b0: sub_100043b0(); break;
    case 0x10010510: sub_10010510(); break;
    case 0x10017470: sub_10017470(); break;
    case 0x100174b0: sub_100174b0(); break;
    case 0x10017510: sub_10017510(); break;
    case 0x10019d20: sub_10019d20(); break;
/*
    case 0x10001240: memoryASet32(ds, r32[ecx]+0x54, memoryAGet32(ds,r32[esp])); r32[esp]+=4; break;
    case 0x10001250: fld32(memoryAGet32(ds, r32[ecx]+0x54)); break;
    case 0x10001260: memoryASet32(ds, r32[ecx]+0x58, memoryAGet32(ds,r32[esp])); r32[esp]+=4; break;
    case 0x10001270: fld32(memoryAGet32(ds, r32[ecx]+0x58)); break;
    case 0x10001280: memoryASet32(ds, r32[ecx]+0x5c, memoryAGet32(ds,r32[esp])); r32[esp]+=4; break;
    case 0x10001290: fld32(memoryAGet32(ds, r32[ecx]+0x5c)); break;
    case 0x1000ff90: ? r32[esp]+=4; break;
//         10010380
*/
    case 0x1000a200: sub_1000a200(); break; // setParameter(index, float) — indexed preset store
    case 0x10010700: { // AEffect.setParameter(effect*, index, float) — cdecl 3 args
      // Stack on entry (no ret addr in emulator): [esp+0]=AEffect*, [esp+4]=index, [esp+8]=float_bits
      const effect  = memoryAGet32(ds, r32[esp]);
      const idx     = memoryAGet32(ds, r32[esp] + 4);
      const fval    = memoryAGet32(ds, r32[esp] + 8);
      const tp      = memoryAGet32(ds, effect + 0x40);  // thisPtr from AEffect backptr
      r32[ecx] = tp;
      push32(fval); push32(idx);   // push (float, index) → [esp]=idx, [esp+4]=fval
      sub_1000a200();
      // cdecl: caller cleans r32[esp] += 12
      break; }
    case 0x100106e0: { // AEffect.getParameter(effect*, index) — cdecl 2 args, returns float in FPU
      // Stack on entry: [esp+0]=AEffect*, [esp+4]=index
      const effect  = memoryAGet32(ds, r32[esp]);
      const idx     = memoryAGet32(ds, r32[esp] + 4);
      const tp      = memoryAGet32(ds, effect + 0x40);  // thisPtr from AEffect backptr
      r32[ecx] = tp;
      push32(idx);   // push index → [esp]=idx
      sub_1000a820();
      // cdecl: caller cleans r32[esp] += 8
      break; }
    default:
      console.log(o.toString(16))
      throw "unimplemented indirect";
  }
}




// ===== AEffect parameter functions =====

// VST param index → preset struct byte offset mapping
// Decoded from sub_1000a200 and sub_1000a820 binary jump tables.
// Derived from confirmed slider VSTGUI tags 2–13 (widget+0x48) mapping to preset+0x00..+0x2c.
// Knob params 0,1 and 14,15,16 fill the remaining slots.
const paramIndexToPresetOffset = [
  0x30, // param 0  → Knob 0 (Vibrato Rate)
  0x34, // param 1  → Knob 1 (Vibrato Amount)
  0x00, // param 2  → Slider 0 (Mod Coarse)
  0x04, // param 3  → Slider 1 (Mod Fine)
  0x08, // param 4  → Slider 2 (Env Initial)
  0x0c, // param 5  → Slider 3 (Env Decay)
  0x10, // param 6  → Slider 4 (Env Sustain)
  0x14, // param 7  → Slider 5 (Env Release)
  0x18, // param 8  → Slider 6 (Mod Velocity)
  0x1c, // param 9  → Slider 7 (Mod Wave)
  0x20, // param 10 → Slider 8 (Mod Thru)
  0x24, // param 11 → Slider 9 (Amp Env Attack)
  0x28, // param 12 → Slider 10 (Amp Env Decay)
  0x2c, // param 13 → Slider 11 (Amp Env Release)
  0x38, // param 14 → Knob 2 (Master Octave)
  0x3c, // param 15 → Knob 3 (Master Tuning)
  0x40, // param 16 → Knob 4 (Master Volume)
];

// sub_1000a200 — Plugin::setParameter(index, float) — vtable[10]
// Called as: ecx=thisPtr, stack=[index, float_value, ...]
// Stores float to presetBank[currentProgram * 0x60 + presetOffset].
// Caller pushes (float, index) in that order so index is at top of stack.
function sub_1000a200() {
  const idx    = memoryAGet32(ds, r32[esp]);      // top of stack = index
  const fval   = memoryAGet32(ds, r32[esp] + 4);  // next = float value (raw bits)
  r32[esp] += 8;                                   // callee pops 2 args

  const tptr = r32[ecx];                           // ecx = thisPtr (set by caller)
  if (idx > 16) return;                            // only handle known params 0..16

  const presetOffset = paramIndexToPresetOffset[idx];
  const presetBank   = memoryAGet32(ds, tptr + 0xb0);
  const curProg      = memoryAGet32(ds, tptr + 0x1c);
  memoryASet32(ds, presetBank + curProg * 0x60 + presetOffset, fval);
  sub_1000aee0(); // recompute derived DSP constants (vtable[155]: attack/release/freq factors)
}

// sub_1000a820 — Plugin::getParameter(index) — vtable[11]
// Called as: ecx=thisPtr, stack=[index, ...]
// Returns float value in FPU ST(0). Pops 1 arg (ret 4 = stdcall).
function sub_1000a820() {
  const idx    = memoryAGet32(ds, r32[esp]);   // top of stack = index
  r32[esp] += 4;                               // pop 1 arg

  const tptr = r32[ecx];                       // ecx = thisPtr (already set by caller)

  if (idx > 16) { fldz(); return; }

  const presetOffset = paramIndexToPresetOffset[idx];
  const presetBank   = memoryAGet32(ds, tptr + 0xb0);
  const curProg      = memoryAGet32(ds, tptr + 0x1c);
  const srcAddr      = presetBank + curProg * 0x60 + presetOffset;
  fld32(memoryAGet32(ds, srcAddr));            // push float onto FPU stack
}

// gui ========
function sub_1001eab0()
{
  // gdi plus startup
  memoryASet32(0, 0x100505bc, 0xff6ab070);  
}

const bitmapFiles = {};  // bitmapPtr → filename (for image rendering)
function sub_1001d370()
{
  const name = readstring(memoryAGet32(0, r32[eax]+4));
  console.log("LOAD IMAGE", name);
  bitmapFiles[r32[eax]] = name;
//  r32[esp] += 4;
}

function sub_1001a0b0()
{
  const vtable = allocate(0x100);            // 256 bytes for vtable entries
  r32[eax] = allocate(0x200);               // 512 bytes for CFrame object
  memoryASet32(0, r32[eax], vtable);
  memoryASet32(0, vtable + 0xb0, 0xff6ab013); // vtable[44] = setBackground
  memoryASet32(0, vtable + 0xdc, 0xff6ab014); // vtable[55] = addView
  memoryASet32(0, r32[eax] + 0x100, 0);       // child count = 0
  r32[esp] += 8;
}

function sub_100166c0()
{
  // esi = CAnimKnob object (pre-allocated this), ecx = CRect& (left+0, top+4, right+8, bottom+c)
  memoryASet32(ds, r32[esi] + 0x04, 1);
  memoryASet32(ds, r32[esi] + 0x08, memoryAGet32(ds, r32[ecx]));
  memoryASet32(ds, r32[esi] + 0x0c, memoryAGet32(ds, r32[ecx] + 0x4));
  memoryASet32(ds, r32[esi] + 0x10, memoryAGet32(ds, r32[ecx] + 0x8));
  memoryASet32(ds, r32[esi] + 0x14, memoryAGet32(ds, r32[ecx] + 0xc));
  r32[esp] += 8;
}

function sub_100177e0()
{
  // arg[0] = pre-allocated CSplashScreen ptr; ecx = CRect& (left, top, right, bottom)
  const splash = memoryAGet32(ds, r32[esp]);
  if (splash) {
    memoryASet32(ds, splash, 0x10040c74);  // vtable = CSplashScreen
    memoryASet32(ds, splash + 0x04, 1);
    memoryASet32(ds, splash + 0x08, memoryAGet32(ds, r32[ecx]));
    memoryASet32(ds, splash + 0x0c, memoryAGet32(ds, r32[ecx] + 0x4));
    memoryASet32(ds, splash + 0x10, memoryAGet32(ds, r32[ecx] + 0x8));
    memoryASet32(ds, splash + 0x14, memoryAGet32(ds, r32[ecx] + 0xc));
  }
  r32[eax] = splash;
  r32[esp] += 0x14;
}


function user32__GetDoubleClickTime()
{
  return 0x6ab0100;
}

// Stubs for Windows API functions called directly from ddx10handlers.js
// (destructor/heap-management paths — not needed in normal GUI operation)
function ole32__OleUninitialize() { r32[eax] = 0; }
function kernel32__EnterCriticalSection() { r32[eax] = 0; }
function kernel32__HeapFree() { r32[eax] = 1; }
function kernel32__GetLastError() { r32[eax] = 0; }
// Missing sub-functions called within ddx10handlers.js heap management
function sub_1001ff47() {}
function sub_10024be4() {}
function sub_10024c26() { r32[eax] = 0; }
function sub_100267e0() {}
function sub_10027015() {}
function sub_10027381() {}
function sub_1002a3b5() {}