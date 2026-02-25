function allocate(size)
{
    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    allocatorPtr += size;
    return ptr;
}

function sub_1001ef91()
{
    const size = stack32(0);

    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
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
  // AEffGUIEditor / TooltipEditor constructor — skipped, GUI not needed
  // eax = AEffect* (esi holds the editor this-ptr, already set by caller)
  // Just return esi unchanged; the caller at 0x10009fa0 will set hasEditor flag.
  r32[eax] = r32[esi];
  // OleInitialize - todo gui
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
      const voiceDspThis = stack32(0);
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
    default:
      console.log(o.toString(16))
      throw "unimplemented indirect";
  }
}

