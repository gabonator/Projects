# Win32 VST DLL → JavaScript Porting Guide

This document is both a general methodology guide and a specific log for porting "Delay Lama" (a Win32 x86 VST 2.x synthesizer DLL) to JavaScript using the cicodis disassembler and a hand-written x86 emulator. A future AI agent should be able to reproduce or extend this work by reading this file thoroughly before touching any code.

---

## 1. Infrastructure overview

The emulator is split across several files that are concatenated and `eval()`'d by `port/run.js`:

```
run.js  →  eval(cpu.js + crt.js + fpu.js + delaylama.js + main.js)
```

| File | Role |
|------|------|
| `cpu.js` | x86 register arrays, memory, flag helpers, push/pop, string ops |
| `fpu.js` | x87 FPU stack (8-deep circular array), all FPU instructions |
| `crt.js` | `indirectCall()` dispatch table, Windows API stubs, bump allocator |
| `delaylama.js` | All disassembled plugin functions, appended as you go |
| `main.js` | VST host: init plugin, send MIDI, run audio loop, write WAV |

**Run command (from `port/` directory):**
```
node run.js
```
Output is `port/output.wav`.

**Disassemble command (from project root):**
```
./cicodis.elf input/delaylama.txt ADDR1 ADDR2 ...
```
Append the output to `port/delaylama.js`.

---

## 2. The porting workflow (iterative loop)

The process is strictly iterative. Run → crash → identify what's missing → add it → repeat.

```
1. Run: node run.js
2. Read the error (throw message or assertion failure)
3. Identify the cause:
   - "unimplemented indirect" → add a case to indirectCall() in crt.js
   - "assertion failed" / "bad ofs" → wrong address calculation or missing function
   - "FPU stack overflow/underflow" → mismatched push/pop in a ported function
   - TypeError / not-a-function → name collision or missing function
4. Fix (disassemble the missing function or add a stub)
5. Goto 1
```

When you hit `indirectCall` or `indirectJump` with an unknown address:
- Search for that address in `delaylama.js` to find if it's a named import (e.g., `ptr_kernel32_GetTickCount`)
- If it's an import, add a Windows API stub in crt.js
- If it's a plugin function pointer, disassemble it and add a case to indirectCall

When you hit `indirectJump` to a jump table:
- Add a jump table hint to `input/delaylama.txt` (cicodis needs hints to decode them)
- Re-disassemble the function containing the jump

---

## 3. cicodis — what the generated code looks like

cicodis outputs JavaScript functions that emulate x86 instructions. Key patterns:

### 3.1 Function skeleton
Every function gets:
```js
function sub_10001234() // 0000:10001234 +long +stackDropN
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;      // ← synthetic! Not in the real x86. Simulates return-addr slot.
    ...
  case 0x10001240:
    ...
    { pc = 0x10001260; break; }  // jump
  ...
  return;
  }
}
```

The `r32[esp] -= 4` at the top is **synthetic** — cicodis adds it to every function to simulate the return address slot that `CALL` would push. This means:
- `[esp+0]` after entry = (fake) return addr
- `[esp+4]` = first argument (stdcall/cdecl convention)
- `[ebp+8]` = first argument (frame-pointer convention, when the function does `push ebp; mov ebp,esp`)

### 3.2 `+stackDropN` annotation
Means the function pops N bytes of caller arguments before returning (stdcall convention). The `+stackDrop8` after the function declaration means the callee does `r32[esp] += 8` before returning, cleaning up 2 arguments.

### 3.3 Thunks (import jump stubs)
A thunk is a tiny function whose entire body is one indirect jump to a Windows API:
```js
function sub_100068b0() // GetTickCount thunk
{
  r32[esp] -= 4;  // ← do NOT keep this
  indirectJump(cs, memoryAGet32(ds, 0x1000b074));
  return;
}
```
**NEVER keep the `r32[esp] -= 4` in a thunk replacement.** Replace the entire body:
```js
function sub_100068b0() {
  r32[eax] = Date.now() & 0xffffffff;
}
```
If you keep `r32[esp] -= 4`, the stack pointer shifts by 4 permanently every time this thunk is called.

### 3.4 SEH (Structured Exception Handling)
Ignore all SEH setup/teardown code entirely. It accesses the `fs:` segment, which is already a no-op in the emulator (`if (seg == fs) return;`). Do not try to port it.

### 3.5 Common cicodis bug: `r16[er16[cx]]`
The cicodis register-name replacement has a bug: it replaces `"ecx"→"r32[ecx]"` and then separately `"cx"→"r16[cx]"`, producing `"r16[er32[cx]]"` or similar corruption.

**Fix in `printJsSync.h` — `ProcessFuncName()`:**
Make the replacements mutually exclusive: if `"ecx"` is found in the token, use `r32[ecx]`; only replace `"cx"` (without the `e`) if `"ecx"` was NOT present.

---

## 4. FPU emulation — the most common source of bugs

### 4.1 The x87 FPU stack
- 8 registers: ST(0) at top, ST(7) at bottom
- Implemented as circular array `fpstack[0..7]` with `fptop` pointer
- `fppush()` decrements fptop (mod 8); `fppop()` increments and zeroes the slot
- `st(i)` = `fpstack[(fptop + i) & 7]`

### 4.2 D8 vs DC form — THE critical distinction (where most bugs hide)

x87 arithmetic instructions have two encoding families:

| Encoding | Assembly | Meaning | cicodis name |
|----------|----------|---------|--------------|
| **D8** | `FADD ST(0), ST(i)` | ST(0) = ST(0) + ST(i) | `faddst(i)` |
| **DC** | `FADD ST(i), ST(0)` | ST(i) = ST(i) + ST(0) | `faddst2(i, 0)` or `faddpst(i)` |
| **D8** | `FMUL ST(0), ST(i)` | ST(0) = ST(0) * ST(i) | `fmulst(i)` |
| **DC** | `FMUL ST(i), ST(0)` | ST(i) = ST(i) * ST(0) | `fmulpst(i)` |
| **D8** | `FSUB ST(0), ST(i)` | ST(0) = ST(0) - ST(i) | `fsubst(i)` |
| **DC** | `FSUB ST(i), ST(0)` | ST(i) = ST(i) - ST(0) | `fsubpst(i)` |
| **DC+pop** | `FADD ST(i), ST(0); pop` | ST(i) = ST(i) + ST(0); pop | `faddpst(i)` |

**Rule: `faddst(i)`, `fmulst(i)`, `fsubst(i)` ALL store result into ST(0), never into ST(i).**

Correct implementations:
```js
function fsubst(i)  { setst(0, st(0) - st(i)); }   // D8: result in ST(0)
function fmulst(i)  { setst(0, st(0) * st(i)); }   // D8: result in ST(0)
function faddst(i)  { setst(0, st(0) + st(i)); }   // D8: result in ST(0)
function faddst2(i, j) { setst(i, st(i) + st(j)); } // DC: result in ST(i)
function fmulpst(i) { setst(i, st(i) * st(0)); fppop(); } // DC+pop
function faddpst(i) { setst(i, st(i) + st(0)); fppop(); } // DC+pop
function fsubpst(i) { setst(i, st(i) - st(0)); fppop(); } // DC+pop
```

Getting these wrong causes:
- Filter coefficients computed entirely wrong (Horner polynomial evaluation)
- Phase accumulators not wrapping (audio sounds like static or wrong pitch)
- Silent output (FPU state corrupted from iteration 1)

### 4.3 FDIVP — the "divide and pop" family

`FDIVP ST(i), ST(0)` means: ST(i) = ST(i) / ST(0), then pop ST(0). Result goes into ST(i) (which becomes the new ST(i-1) after the pop).

The most common form is `FDIVP ST(1), ST(0)` (implicit when no operands given in AT&T syntax):
```js
function fdivp80(v) { setst(1, v / st(0)); fppop(); }
// called as: fdivp80(st(1)) — capture ST(1) before the call
```
Do NOT write it as `setst(0, st(0)/v)` — that's backwards and loses the result on pop.

### 4.4 Phase accumulator wrap pattern

A common x87 idiom for modulo-wrapping a phase accumulator stored in ST(i):
```
fxchst2(0, i)   // swap: ST(0) = accumulator, ST(i) = max_period
fsubst(i)       // ST(0) = accumulator - max_period  (D8 form, result in ST(0))
fxchst2(0, i)   // swap back: ST(0) = max_period, ST(i) = wrapped accumulator
fstpst(0)       // discard max_period
```
If `fsubst` stores into ST(i) instead of ST(0), the wrap does nothing.

### 4.5 Horner polynomial evaluation pattern

Recognize this pattern in FIR/IIR filter loops:
```js
fldst(0);        // push copy of input x: ST(0)=x ST(1)=x ST(2..7)=coefficients
fmulst(5);       // ST(0) = x * c5
faddst(4);       // ST(0) = x*c5 + c4
fmulst(1);       // ST(0) = (x*c5+c4) * x
faddst(3);       // ST(0) = prev + c3
fmulst(1);       // ST(0) = prev * x
faddst(2);       // ST(0) = prev + c2  ← final polynomial output
fstp32(...);     // store output, pop
fstpst(0);       // discard x copy
```
Evaluates: `c2 + x*(c3 + x*(c4 + x*c5))` — Horner's method. The loop iterates once per sample and accumulates coefficients in ST(2)–ST(5).

---

## 5. Calling conventions

### 5.1 stdcall (Windows API, most plugin functions)
- Callee cleans up arguments: `r32[esp] += N` before return
- In cicodis: annotated as `+stackDropN`
- In crt.js stubs: you must add `r32[esp] += N` inside the case

### 5.2 cdecl (msvcrt: malloc, free, sprintf, etc.)
- Caller cleans up arguments: `r32[esp] += N` after the call returns
- In crt.js stubs: do NOT add esp cleanup — the caller handles it

### 5.3 thiscall (C++ methods)
- `ecx` = `this` pointer (not pushed on stack)
- Arguments on stack as normal stdcall
- cicodis already uses `r32[ecx]` for `this`

### 5.4 Stack frame convention in the emulator
Because JS calls don't push a real return address, cicodis adds `r32[esp] -= 4` synthetically. So:
- `[esp+0]` = fake return addr slot (usually ignored)
- `[esp+4]` = first argument
- After `push ebp; mov ebp,esp`: `[ebp+8]` = first argument ✓

The one exception: **operator new** (`sub_1000a7fc`). This thunk reads its size argument from `[esp+0]` (not `[esp+4]`), because it's entered without the synthetic esp decrement.

---

## 6. indirectCall and the IAT stub system

All calls through function pointers go through `indirectCall(cs, address)`. You must add a `case` for every address that gets called at runtime.

### 6.1 How to discover missing cases
Run the plugin; when it throws `"unimplemented indirect"` with a hex address, that's your missing case.

### 6.2 Plugin function pointers
Add the function to the switch:
```js
case 0x10004870: sub_10004870(); break;  // vtable+0x4c: effSetSampleRate handler
```
Then disassemble the function if it isn't already in delaylama.js.

### 6.3 Windows API stubs — the IAT enum system
Windows API addresses are virtualized. The real DLL's IAT (Import Address Table) is at `0x1000b000`. Each 4-byte IAT slot gets an enum value: `enum = (IAT_addr - 0x1000b000) / 4 + 1`, base `0x6ab00000`.

So IAT slot at `0x1000b000` → enum `0x6ab00001`, at `0x1000b004` → `0x6ab00002`, etc.

To identify which API corresponds to an unknown enum value:
1. Compute the IAT offset: `(enum - 0x6ab00000 - 1) * 4`
2. Search `delaylama.js` for the comment at that address (e.g., `ptr_kernel32_GetTickCount, // 0x1000b074`)

Write the stub:
```js
// stdcall — pop args; return value in eax
case 0x6ab0001d:
  r32[eax] = Date.now() & 0xffffffff;  // GetTickCount
  break;

// stdcall with args — pop them too
case 0x6ab00028: {  // malloc(size)
  const size = memoryAGet32(ds, r32[esp] + 4);
  r32[eax] = allocatorPtr; allocatorPtr += size;
  break;
}

// cdecl — no esp cleanup in stub
case 0x6ab0002e: r32[eax] = 0; break;  // floor (cdecl, caller pops)
```

**Stdcall arg count**: find the Windows API on MSDN, count the parameters, multiply by 4.

---

## 7. Jump tables

Some functions use computed jumps (`switch`/jump table). cicodis needs a hint in `input/delaylama.txt` to decode them. Format (add near the relevant address in the file):
```
; jumpTable 0x100011f0 table=0x10001384 count=25 selector=eax
```
- `0x100011f0` = address of the computed jump instruction
- `table=0x10001384` = address of the pointer table in .rdata
- `count=25` = number of entries
- `selector=eax` = register holding the index

After adding the hint, re-disassemble the function.

To find the table address: look at the jump instruction in the raw disassembly or in cicodis error output. You can also search `.rdata` for a sequence of pointers into `.text`.

---

## 8. JavaScript-specific pitfalls

### 8.1 32-bit unsigned arithmetic overflow
JavaScript uses 64-bit floats. Adding two `Uint32Array` values can produce a result > 2³². Always apply `>>> 0` when computing memory addresses from register addition:
```js
// WRONG — can produce 0x1103ec8a8 (33 bits)
memoryASet32(ds, r32[edx] + r32[ecx] - 4, value);

// CORRECT
memoryASet32(ds, (r32[edx] + r32[ecx] - 4) >>> 0, value);
```
Symptom: `memoryASet32 bad ofs: 0x1103ec8a8` (address has more than 32 bits).

### 8.2 Name collision: `fs` segment register vs Node.js `fs` module
`cpu.js` declares `let fs = 5` (the FS segment register number). Inside the `eval()` scope, this shadows Node.js's `require('fs')` module.

**Symptom**: `TypeError: fs.writeFileSync is not a function`

**Fix**: In `main.js`, use `require('fs').writeFileSync(filename, buf)` directly instead of `fs.writeFileSync`.

### 8.3 Signed vs unsigned register reads
`r32[eax]` is always unsigned (Uint32Array). For signed comparisons, use `r32s[eax]` (Int32Array on same buffer). cicodis generates `r32s` for signed comparisons and `signed32(x)` for explicit sign extension.

### 8.4 BigInt for 64-bit operations
`memoryAGet64` / `memoryASet64` return/take BigInt. `fild64`, `fistp64`, etc. use `BigInt`. Be careful when mixing with regular JS numbers.

### 8.5 `eval()` scope — everything is global
All functions defined in cpu.js, crt.js, fpu.js, delaylama.js, and main.js share one flat namespace. Avoid redefining any name. cicodis-generated functions use names like `sub_10001234`, which are safe.

---

## 9. Memory system

```
Base address: 0x10000000
Total size:   5 MB (0x500000 bytes)
Array:        Uint8Array 'memory', accessed via memoryAGet32/Set32 etc.

Section layout (for Delay Lama):
  .text:   0x10001000  (code)
  .rdata:  0x1000b000  (read-only data: constants, vtables, IAT)
  .data:   0x1000d000  (mutable data)

Stack:      esp starts at 0x1038c000, grows downward
Heap:       allocatorPtr starts at 0x103a0000, grows upward (bump allocator)
```

**Memory bounds checks**: `memoryAGet32` checks `ofs >= 0x10001000`, `memoryASet32` checks `ofs >= 0x1004d000`. Adjust these bounds if you get false assertion failures on valid accesses.

**Reading constants from .rdata** (useful for understanding the DSP):
```js
node -e "
const b = require('fs').readFileSync('port/res/Delay Lama_rdata.bin');
const dv = new DataView(b.buffer, b.byteOffset);
// Address 0x1000bb10 → rdata offset 0xb10
console.log(dv.getFloat64(0xb10, true));  // = 6.283... = 2π
console.log(dv.getFloat32(0xb48, true));  // = -32.0
"
```

---

## 10. Resolving indirectJump (vtable calls)

Vtable calls look like:
```js
r32[edx] = memoryAGet32(ds, r32[esi]);          // load vtable ptr
indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x214)); // call vtable[0x214/4]
```
To find what's at vtable offset `0x214`:
1. Look up the vtable base address in the layout (e.g., `0x1000b250`)
2. Read the pointer at `0x1000b250 + 0x214` from the rdata binary: offset = `0xb250 + 0x214 = 0xb464` → 4-byte LE address
3. That address is the function to disassemble and add to indirectCall

Or grep for the offset constant in delaylama.js to find existing comments.

---

## 11. Debugging approach

### 11.1 Assertion failures
```
memoryAGet32 bad ofs: 0x...  → wrong address, likely 32-bit overflow (add >>> 0)
memoryASet32 bad ofs: 0x...  → same
assertion failed (fppos > 0) → FPU stack underflow; a pop has no matching push
assertion failed (fppos < 8) → FPU stack overflow; a push has no matching pop
```

### 11.2 FPU stack tracing
To debug FPU issues, add temporary logging:
```js
console.log(`FPU: fppos=${fppos} ST(0)=${st(0)} ST(1)=${st(1)}`);
```
The FPU stack must be balanced (same fppos on entry and exit) for every function.

### 11.3 Audio quality checks
```js
node -e "
const b = require('fs').readFileSync('port/output.wav');
const dv = new DataView(b.buffer, b.byteOffset);
let maxL = 0; const n = (b.length-44)/4;
for (let i=0; i<n; i++) { const s=Math.abs(dv.getInt16(44+i*4,true)); if(s>maxL) maxL=s; }
console.log('Max amplitude:', maxL, '(' + (maxL/32767*100).toFixed(1) + '%)');
"
```
- **0%**: complete silence → likely FPU bug (fsubst/fmulst/faddst wrong form, or fdivp wrong)
- **< 5%**: audio present but nearly silent → FPU accumulator or filter bug
- **5–30%**: reasonable range for synthesizer output
- **> 80%**: clipping likely → scaling bug or wrong constant

### 11.4 Identifying wrong FPU functions
If audio exists but sounds wrong (wrong pitch, no formants, static):
1. Check `fsubst`, `fmulst`, `faddst` — ensure they store result in ST(0) not ST(i)
2. Check `fdivp80` / `fdivp32` / `fdivp64` — ensure result goes to ST(1), not ST(0)
3. Check `fdivrpst` — `ST(i) = ST(0) / ST(i)` (reverse divide, not `ST(0) / ST(0)`)
4. Check `fpatan` — `setst(0, Math.atan2(y, st(0)))` where `y = fppop()`
5. Check `fyl2x` — `setst(0, y * log2(x))` where `y = fppop()`

---

## 12. VST 2.x host protocol

The host (main.js) must call the plugin in this exact order:

```js
// 1. Create plugin — calls VSTPluginMain(audioMasterCallback)
push32(audioMasterPtr);
sub_10003560();           // VSTPluginMain
r32[esp] += 4;
let pluginPtr = r32[eax]; // returns AEffect*

// 2. Read function pointers from AEffect struct
const dispatcherPtr       = memoryAGet32(ds, pluginPtr + 0x04);
const processReplacingPtr = memoryAGet32(ds, pluginPtr + 0x50);

// 3. Configure (each call: push args right-to-left, call, pop)
// effSetProgram (opcode 2): select preset
push32(0); push32(0); push32(presetIndex); push32(0); push32(2); push32(pluginPtr);
indirectCall(cs, dispatcherPtr); r32[esp] += 24;

// effSetSampleRate (opcode 10): float in opt slot (arg4)
const srBits = toFp32Bits(44100);
push32(srBits); push32(0); push32(0); push32(0); push32(10); push32(pluginPtr);
indirectCall(cs, dispatcherPtr); r32[esp] += 24;

// effSetBlockSize (opcode 11): int in value slot (arg3)
push32(0); push32(0); push32(blockSize); push32(0); push32(11); push32(pluginPtr);
indirectCall(cs, dispatcherPtr); r32[esp] += 24;

// effMainsChanged (opcode 12): value=1 to activate
push32(0); push32(0); push32(1); push32(0); push32(12); push32(pluginPtr);
indirectCall(cs, dispatcherPtr); r32[esp] += 24;

// 4. Audio loop: processReplacing(AEffect*, inputs**, outputs**, nFrames)
push32(blockSize); push32(outputPtrs); push32(inputPtrs); push32(pluginPtr);
indirectCall(cs, processReplacingPtr); r32[esp] += 16;
```

The audioMaster callback:
```js
function audioMasterHandler() {
  const opcode = stack32(1);  // opcode is at [esp+4] (second slot after fake ret addr)
  if (opcode === 1) r32[eax] = 2400;  // audioMasterVersion → VST 2.4
  else r32[eax] = 0;
}
```

MIDI events are sent via `effProcessEvents` (opcode 25) before each `processReplacing` call. See `processEvents()` in main.js for the VstEvents struct layout.

---

## 13. Checklist for porting a new Win32 VST

- [ ] Load binary sections into `memory[]` (see `loadOverlay` in cpu.js and `init()` in delaylama.js)
- [ ] Set `esp` to a valid stack region, `allocatorPtr` to a free heap region
- [ ] Disassemble `VSTPluginMain` (usually exported as `main` or `VSTPluginMain`)
- [ ] Follow the call graph: VSTPluginMain → constructor chain → AEffect init
- [ ] For each `indirectCall` crash: add stub or disassemble target
- [ ] For each jump table: add hint to .txt, re-disassemble
- [ ] Implement Windows API stubs (compute IAT enum values as described above)
- [ ] Implement thunks (replace body, remove `r32[esp] -= 4`)
- [ ] Verify plugin initialises: AEffect* returned, dispatcher/processReplacing pointers non-zero
- [ ] Send effSetSampleRate, effSetBlockSize, effMainsChanged(1)
- [ ] Send MIDI note-on, run processReplacing blocks, send note-off, tail
- [ ] Check output.wav amplitude > 10%
- [ ] Listen: does it sound right?

---

## Progress & Findings (Delay Lama specific)

### Current status — COMPLETE ✓
Plugin fully ported and working. `node run.js` from `port/` generates a correct `output.wav` (~4s, 178176 samples at 44100 Hz) with the characteristic Delay Lama "human voice" vocal synthesis sound. Amplitude at 22–25% full scale.

---

## All bugs found and fixed

### JavaScript / runtime bugs

| Bug | Location | Fix |
|-----|----------|-----|
| `fs.writeFileSync` crash | `port/main.js` `writeWav()` | `cpu.js` declares `let fs = 5` (FS segment register), shadowing Node.js `fs` module inside the `eval` scope. Use `require('fs').writeFileSync(...)` directly. |
| 32-bit arithmetic overflow | `port/delaylama.js` line 3073 | `r32[edx] + r32[ecx] - 4` produces a 33-bit result when registers hold large unsigned values. Apply `>>> 0` to wrap: `(r32[edx] + r32[ecx] - 4) >>> 0`. |

### FPU emulation bugs (fpu.js)

| Bug | Old code | Fix |
|-----|----------|-----|
| `fdivp80` wrong operand/register | `setst(0, st(0)/v); fppop()` | `setst(1, v/st(0)); fppop()` — FDIVP ST(1),ST(0): result in ST(1). Same fix for fdivp32/fdivp64. |
| `fsubst(i)` wrong form — **CRITICAL** | `setst(i, st(i)-st(j))` | `setst(0, st(0)-st(i))` — D8-form: result always in ST(0) |
| `fmulst(i)` wrong form — **CRITICAL** | `setst(i, st(i)*st(j))` | `setst(0, st(0)*st(i))` — D8-form: result always in ST(0) |
| `faddst(i)` wrong form — **CRITICAL** | `setst(i, st(i)+st(j))` | `setst(0, st(0)+st(i))` — D8-form: result always in ST(0) |
| `fdivrpst` bad division-by-zero guard | returned 1.0 arbitrarily | removed; `setst(i, st(0)/st(i)); fppop()` — let setst clamp infinity |

### cicodis tool bug

| Bug | Fix |
|-----|-----|
| Register name double-replace: `"ecx"→"r32[ecx]"` then `"cx"→"r16[cx]"` produces `"r16[er32[cx]]"` | In `printJsSync.h ProcessFuncName()`: mutually exclusive — if `"ecx"` found use `r32[ecx]`, else replace `"cx"` with `r16[cx]` |

---

## Architecture & conventions

### Memory layout
- Load base: `0x10000000`; `.text`: `+0x1000`; `.rdata`: `+0xb000`; `.data`: `+0xd000`
- Stack: `esp = 0x1038c000`; heap bump-allocator starts at `0x103a0000`
- Plugin object: `0x103a1508` (25840 B); vtable `0x1000b460`
- Sub-object: `0x103a79f8` (184 B); vtable `0x1000b250`
- AEffect at plugin+0x20 = `0x103a1528`; dispatcher=`0x10001000`; processReplacing=`0x100010c0`

### AEffect struct layout (at 0x103a1528)
- `+0x00`: magic `'VstP'` (0x56737450)
- `+0x04`: dispatcher = 0x10001000
- `+0x40`: C++ object ptr = 0x103a1508
- `+0x50`: processReplacing = 0x100010c0

### Windows API IAT enum values
- Enum base = `0x6ab00000`; gdi32 starts at IAT `0x1000b000` → enum `0x6ab00001`
- Formula: `enum = (IAT_addr - 0x1000b000) / 4 + 1`
- All Windows APIs are **stdcall** → stubs must pop args: `r32[esp] += N*4`
- msvcrt is **cdecl** → stubs don't pop

### Jump table hints added to delaylama.txt
- `0x10002dc0` / table `0x10002fa0`: 12 entries, selector=eax (sub_10002db0 opcode dispatch)
- `0x100011f0` / table `0x10001384`: 25 entries, selector=eax (sub_100011e0 VST opcode switch, opcodes 0–0x18)

---

## Important rdata constants (section base 0x1000b000)

| Address | Type | Value | Role |
|---------|------|-------|------|
| 0x1000b208 | f32 | 0.0 | Initial FPU accumulator fill value |
| 0x1000b684 | f32 | 127.0 | MIDI param scaling |
| 0x1000b688 | f32 | 0.2 | Portamento threshold |
| 0x1000b8fc | f32 | 1.0 | Pitch step addend |
| 0x1000ba78 | f64 | 0.5 | Formant index scale |
| 0x1000bb04 | f32 | 1/3800 | Filter 2 freq param |
| 0x1000bb08 | f32 | 1/4950 | Filter 1 freq param |
| 0x1000bb10 | f64 | 2π | Filter kernel phase multiplier |
| 0x1000bb18 | f64 | e | Exponential decay base |
| 0x1000bb20 | f64 | 50π | Decay constant |
| 0x1000bb48 | f32 | -32.0 | Pitch-to-delay-index multiplier |
| 0x1000bb4c | f32 | 5.0 | Vowel position base |
| 0x1000bb50 | f32 | -12.0 | Portamento step divisor (downward) |
| 0x1000bb54 | f32 | 0.01 | Portamento step addend |
| 0x1000bb64 | f32 | 12.0 | Portamento step divisor (upward) |
| 0x1000bb78 | f32 | 1279.0 | Voice input amplitude scale |

---

## DSP algorithm overview (Delay Lama synthesis chain)

1. **Note-on/off** (`sub_10006240`): stores MIDI note (range 4–72 enforced) as float at `[plugin+0x6144]`; sets playing flag at `+0x6174`
2. **Portamento** (`sub_100054c0`, lines 2750–2788): interpolates current pitch `[+0x614c]` toward target `[+0x6144]` with per-sample step `[+0x6148]`; stores interpolated pitch at `[+0x6154]`
3. **Vowel modulation** (`sub_10006400`): Borland LCG (`state = state * 0x0019660d + 0x3c6ef35f`), scaled to vowel position ≈ `5 + 2*(LCG*scale)` → `[+0x615c]`
4. **Wavetable oscillator**: pitch × -32 → integer delay-buffer index; reads amplitude from lookup table
5. **Phase accumulator wrap** (`sub_10005fb0`): pattern `fxchst2/fsubst/fxchst2` wraps three delay-line phase accumulators modulo max_period
6. **Horner polynomial FIR filter** (`sub_10005fb0`, lines 4215–4220): `fmulst(5)→faddst(4)→fmulst(1)→faddst(3)→fmulst(1)→faddst(2)` = `c2 + x*(c3 + x*(c4 + x*c5))`
7. **Resonator bank** (`sub_10005fb0`): 6 FPU accumulators for 3 parallel band resonators; output mixed to output buffer
8. **Delay-based pitch shifter** (`sub_10005eb0`): circular delay buffer with variable read step

---

## Functions ported

| Address | Name / role |
|---------|-------------|
| 10003560 | VSTPluginMain — checks audioMaster version, allocs plugin, calls 10003470; returns AEffect* in eax |
| 10003470 | Plugin ctor wrapper — calls 10002820, 1000a7fc(0x68), then 10003640 |
| 10002820 | Main plugin object ctor — inits AEffect, calls 10001a50, 1000a7fc×2, 1000a77a, 100032c0, 10002b10 |
| 100010e0 | AEffect struct init — writes 'VstP' magic, sets dispatcher/process ptrs |
| 10001a50 | Calls 100010e0; sets vtable ptr 0x1000b250 |
| 10001520 | Set/clear flag bit in [ecx+0x44] |
| 100014c0 | (ported, role TBD) |
| 100014e0 | (ported, role TBD) |
| 10002670 | (ported, role TBD) |
| 10002810 | Default ctor stub — returns `this` (ecx) in eax |
| 1000a77a | Generic loop: calls a callback N times advancing ptr by stride |
| 1000a7e4 | Loop cleanup handler |
| 100032c0 | Init default parameter floats + string copies from .data into plugin+0xd8 |
| 10002b10 | Sets sample-rate/tempo via sub_10002db0 opcodes 0, 2, 3 |
| 10002db0 | Opcode dispatcher (opcodes 0–11), jump table at 0x10002fa0 |
| 10003640 | Creates UI/timer object (104 bytes); calls sub_10006680, sub_1000a7fc, sub_10007e20 |
| 10006680 | Timer/OleInit wrapper: calls GetTickCount, OleInitialize |
| 100068b0 | Thunk: kernel32.GetTickCount — `r32[eax] = Date.now() & 0xffffffff` |
| 10007e20 | Bitmap loader (LoadBitmapA/GetObjectA) — returns early when bitmap=NULL |
| 10001000 | VST dispatcher entry point |
| 100010c0 | VST processReplacing entry point |
| 10001ab0 | Dispatcher impl — calls sub_100011e0 |
| 100011e0 | VST opcode switch (opcodes 0–0x18); jump table at 0x10001384 |
| 100054c0 | processReplacing implementation — main audio loop |
| 10005eb0 | Delay-based pitch shifter |
| 10005fb0 | Resonator bank / Horner FIR filter — 6 FPU accumulators |
| 10006240 | Note-on/off handler |
| 10006400 | LCG random number generator (vowel modulation) |
| 10003530 | vtable[1]: wraps sub_10002db0, calls sub-obj vtable |
| 100040c0 | Sub-obj opcode switch (opcodes 0–6) |
| 100061e0 | processEvents: copies MIDI into plugin buffer |
| 10004870 | vtable+0x4c: effSetSampleRate handler |
| 10004890 | vtable+0x50: effSetBlockSize handler |
| 100048b0 | vtable+0x58: effMainsChanged=1 handler |
| 100048d0 | Delay buffer init / activation |
| 10002060 | vtable+0x88: sample-rate getter callback |
| 10001970 | (ported) |
| 1000a75c | Thunk: msvcrt._ftol — `r32[eax] = Math.trunc(fppop()) \| 0` |
| 1000a7fc | operator new thunk — reimplemented in crt.js |

---

## crt.js — indirectCall cases

Code pointers:
- `0x77778888` → audioMasterHandler
- `0x10001000` → sub_10001000 (VST dispatcher)
- `0x100010c0` → sub_100010c0 (VST processReplacing)
- `0x10001ab0` → sub_10001ab0 (dispatcher impl)
- `0x10002810` → sub_10002810 (default ctor stub)
- `0x10002db0` → sub_10002db0 (opcode dispatcher)
- `0x10002b10` → sub_10002b10 (sets sample-rate/tempo)
- `0x10003530` → sub_10003530 (vtable[1])
- `0x100040c0` → sub_100040c0 (sub-obj opcode switch)
- `0x100061e0` → sub_100061e0 (processEvents)
- `0x100054c0` → sub_100054c0 (processReplacing impl)
- `0x10006400` → sub_10006400 (LCG RNG)
- `0x10004870` → sub_10004870 (effSetSampleRate)
- `0x10004890` → sub_10004890 (effSetBlockSize)
- `0x100048b0` → sub_100048b0 (effMainsChanged)
- `0x100048d0` → sub_100048d0 (delay buffer init)
- `0x10002060` → sub_10002060 (sample-rate getter)
- `0x10001970` → sub_10001970

Windows API stubs (IAT enum 0x6ab000xx — stdcall pop args, cdecl don't):
- gdi32: GetCurrentObject(0x01)…SetBkMode(0x15)
- kernel32: Sleep(0x1a), GlobalFree(0x1b), GetLastError(0x1c), GetTickCount(0x1d)
- msvcrt (cdecl): _stricmp(0x1e), _adjust_fdiv(0x1f), _initterm(0x20), _except_handler3(0x22), _purecall(0x23 throws), strrchr(0x24), realloc(0x25), free(0x27), malloc(0x28), __CxxFrameHandler(0x29), operator new(0x2a), sprintf(0x2b), floor(0x2e), _ftol(0x2f)
- user32: LoadBitmapA(0x38), SetCursor(0x39), LoadCursorA(0x3a), GetWindowLongA(0x3b), CreateWindowExA(0x3c), SetWindowLongA(0x3d), DestroyWindow(0x3e), GetDC(0x3f), ReleaseDC(0x40), GetCursorPos(0x41), GetAsyncKeyState(0x42), FillRect(0x43), GetWindowRect(0x44), PeekMessageA(0x45), DispatchMessageA(0x46), GetCursor(0x47)
- ole32: OleInitialize(0x48), OleUninitialize(0x49), RevokeDragDrop(0x4a), RegisterDragDrop(0x4b), CoCreateInstance(0x4c)

---

## Delay Lama DSP Algorithm — Deep Dive

### What kind of synthesizer is this?

Delay Lama is a **delay-line resonator vocal synthesizer**. It does not use subtractive synthesis (filter on oscillator) or frequency modulation. Instead it uses a technique related to **physical modelling / waveguide synthesis**: a pre-recorded voice sample is played through a circular delay buffer, and a bank of exponentially-damped resonators reads from that buffer at positions determined by the desired vowel formant frequencies. The MIDI pitch is implemented by controlling how fast the read head moves through the delay buffer, not by resampling.

The name is a double pun: "Delay" from the delay-line synthesis method, "Lama" from the Tibetan monk vocal timbre it produces.

---

### Data buffers (plugin object offsets from `this = [esi]`)

| Offset | Name | Size | Contents |
|--------|------|------|----------|
| `+0x6144` | `target_note` | f32 | Target MIDI note (set on note-on) |
| `+0x614c` | `current_note` | f32 | Portamento-smoothed pitch (interpolates toward target) |
| `+0x6148` | `portamento_step` | f32 | Amount to add to current_note each sample |
| `+0x6154` | `pitch_accumulator` | f32 | Phase accumulator for delay-buffer read position |
| `+0x6158` | `wavetable_pos` | f32 | Current read position in voice wavetable (0..1023) |
| `+0x615c` | `vowel_pos` | f32 | Vowel position from LCG (~5 ± random) |
| `+0x6160` | `amp_envelope` | f32 | Current amplitude envelope value |
| `+0x6164` | `voice_sample` | f32 | Current voice sample read from wavetable |
| `+0x6174` | `playing` | byte | 1 if note is held, 0 if released |
| `+0x6384` | `excitation` | f32 | Excitation sample for resonator bank |
| `+0x63ec` | `sample_rate` | f32 | Audio sample rate (44100.0) |
| `+0x63f8` | `lcg_state` | i32 | LCG random number state |
| `+0x64a4` | `output_buf` | f32[] | Per-block resonator output buffer (N_frames floats) |
| `+0x64a8` | `N_frames` | i32 | Samples per block = trunc(sr × K) |
| `+0x64ac` | `pitch_delay_buf` | f32[] | Circular pitch-shift delay buffer (10240 floats) |
| `+0x64b0` | `delay_buf_size` | i32 | 10240 (0x2800) |
| `+0x64b8` | `voice_wavetable` | f32* | Pointer to pre-computed voice samples |
| `+0x64bc` | `wavetable_size` | i32 | 1024 (0x400) |
| `+0x64c0` | `exp_window` | f32[] | Exponential decay window: `e^(-k × 50π/sr)` |
| `+0x64cc` | `sin_lut` | f32[] | Sine LUT: `sin(i × 2π/1024)` for 1024 entries |
| `+0x64d0` | `sin_lut_size` | i32 | 1024 (0x400) |
| `+0x64d4` | `lut_freq_scale` | f32 | = 1024 / sr ≈ 0.0232 — converts Hz to LUT step |
| `+0x64d8` | `kernel1` | f32[] | Resonator kernel 1 (windowed sinusoid at f1) |
| `+0x64e4` | `formant_table_A` | f32* | Vowel formant amplitude table A |
| `+0x64e8` | `formant_table_B` | f32* | Vowel formant amplitude table B |
| `+0x64ec` | `formant_table_C` | f32* | Vowel formant amplitude table C |
| `+0x6378` | `delay_write_pos` | i32 | Current write position in pitch_delay_buf |

---

### Phase 1 — Activation (sub_100048d0, called on effMainsChanged=1)

This runs once when the host activates the plugin. It allocates all buffers and pre-computes all static tables.

```
ACTIVATION PSEUDOCODE
─────────────────────
sr = sample_rate   // 44100.0
N  = trunc(sr × K) // block size, e.g. 2048 (K ≈ 0.04644)

// 1. Allocate per-block output buffer
output_buf = new float[N]

// 2. Allocate pitch-shift delay buffer
pitch_delay_buf = new float[10240]   // 10240 samples ≈ 232 ms at 44100 Hz
fill(pitch_delay_buf, 0.0)

// 3. Build exponential decay window
//    This is the impulse response envelope of a decaying resonator.
//    Decay constant α = 50π/sr ≈ 0.00356 per sample
α = (50 × π) / sr
for k in 0 .. N×4:
    exp_window[k] = e^(-k × α)
//    After ~3×sr/50π ≈ 844 samples, amplitude falls to e^(-3) ≈ 5%

// 4. Build sine look-up table (1024 entries, one full cycle)
for i in 0 .. 1023:
    sin_lut[i] = sin(i × 2π / 1024)

// 5. Pre-compute frequency-domain scale factor
lut_freq_scale = 1024 / sr   // = 0.02322 — LUT entries per sample at 1 Hz

// 6. Build resonator kernel 1 (sinusoidal at f1 = sr / (sr × 1/4950) ≈ 4950 Hz)
//    Each tap: sin(2π × f1 × i / sr) × exp_window[floor(i × 3.0)]
//    This is the sampled impulse response of a resonant filter at f1.
idx_A = 0.0   // window index accumulates at 3.0 per tap
for i in 0 .. N-1:
    kernel1[i] = sin(i × 2π × 4950 / sr) × exp_window[floor(idx_A)]
    idx_A += 3.0

// 7. Build resonator kernel 2 (sinusoidal at f2 ≈ 3800 Hz)
//    Same shape but slower window decay (3.6 per tap vs 3.0)
idx_B = 0.0
for i in 0 .. N-1:
    kernel2[i] = sin(i × 2π × 3800 / sr) × exp_window[floor(idx_B)]
    idx_B += 3.6

// Note: kernel1 decays to ~5% after N/3.0 × α⁻¹ samples (sharper resonance)
//       kernel2 decays slightly slower (lower Q)

// 8. Store combined kernel (kernel1 + kernel2 for each sample, stored together)
//    Actual implementation builds them into a single interleaved table.

// 9. Compute voice wavetable (1024 samples)
//    Loaded from 'Delay Lama_data.bin' or derived from it.
//    Contains the pre-recorded Tibetan monk voice sample (one cycle).
voice_wavetable = <loaded from resource, 1024 floats>
```

---

### Phase 2 — Per-block processing (sub_100054c0)

Called every block (N_frames samples) by processReplacing.

```
PER-BLOCK PSEUDOCODE
─────────────────────

// ── PORTAMENTO ──
// Smoothly slide current_note toward target_note, one step per block.
if playing:
    if current_note < target_note - 0.2:
        // Note is below target: move upward
        portamento_step = (tempo + 0.01) × sr / 12.0
    elif current_note > target_note + 0.2:
        // Note is above target: move downward
        portamento_step = (tempo + 0.01) × sr / (-12.0)
    else:
        // Close enough: snap to target, no step this block
        current_note = target_note
        portamento_step = 0.0

    current_note += portamento_step

// ── VOWEL MODULATION (LCG random) ──
// Borland linear congruential generator, advances once per block.
lcg_state = (lcg_state × 0x0019660D + 0x3C6EF35F) & 0xFFFFFFFF
vowel_pos = 5.0 + 2.0 × (int32(lcg_state) × vowel_scale)
// vowel_pos ≈ 5.0 ± random_noise
// This slowly wobbles the vowel formant selection, creating
// the organic, slightly unstable quality of the voice.

// ── FORMANT AMPLITUDE LOOKUP ──
// Convert vowel_pos to an index into the formant tables.
// Three separate amplitude tables correspond to three formant bands.
vowel_idx = floor(vowel_pos × 0.5 + 0.75)
amp_A = formant_table_A[vowel_idx] × kernel_scale × input_amp
amp_B = formant_table_B[vowel_idx] × kernel_scale × input_amp
amp_C = formant_table_C[vowel_idx] × kernel_scale × input_amp

// ── PER-SAMPLE INNER LOOP ──
for each sample i in block:

    // 1. READ VOICE WAVETABLE
    //    The voice wavetable contains one cycle of the pre-recorded voice.
    //    Read it at the current wavetable position (which advances each sample).
    wt_idx = floor(wavetable_pos)
    voice_sample = amp_envelope × voice_wavetable[wt_idx]

    // 2. ADVANCE WAVETABLE POSITION
    //    Wavetable read speed is modulated by vowel_pos (from LCG).
    //    This creates the "wobble" — the voice timbre shifts slightly each block.
    wavetable_pos += (amp_envelope × 0.2 + 1.0) × vowel_pos / block_size
    if wavetable_pos >= 1024.0: wavetable_pos -= 1024.0   // wrap

    // 3. ACCUMULATE PITCH PHASE
    //    pitch_accumulator grows by (voice_sample + current_note) each sample.
    //    This mixes the voice waveform shape into the pitch phase, creating
    //    a pitch that is modulated by the voice source — the "singing" quality.
    pitch_accumulator += voice_sample + current_note
    // (pitch_accumulator stored back to [esi+0x6154])

    // 4. COMPUTE DELAY-BUFFER READ INDEX
    //    Multiply accumulated pitch by -32 to get a signed integer offset.
    //    Negative sign = reading backwards relative to the write head.
    //    The factor 32 sets the relationship between pitch (MIDI note) and
    //    the delay-buffer distance. MIDI note 60 → offset ≈ 60×32 = 1920 samples.
    delay_read_idx = trunc(pitch_accumulator × -32.0)
    excitation = pitch_delay_buf[delay_buf_base - delay_read_idx × 4]
    //    This reads the sample that was written into the delay buffer
    //    'delay_read_idx' samples ago — i.e. pitch-shifted voice.

    // 5. COMPUTE SECONDARY INDEX (for resonator phase)
    //    sr / excitation gives a frequency-related step size for the resonators.
    resonator_phase_step = trunc(sr / excitation)
    //    (Used as the resonator loop boundary in sub_10005fb0)

// ── RESONATOR BANK (sub_10005fb0) ──
// Applied once per block to the full output_buf.
// Implements 3 formant resonators using exponentially-windowed sinusoids.
resonator_bank(excitation_samples, amp_A, amp_B, amp_C)  // see below

// ── PITCH SHIFTER (sub_10005eb0) ──
// Writes the resonator output back into the circular delay buffer
// at the current write position, which advances by pitch_offset each block.
pitch_shifter(output_buf)  // see below
```

---

### Resonator bank in detail (sub_10005fb0)

This is the core "vowel shaping" stage. It maintains 3 pairs of phase accumulators and produces samples by reading from the exponential window and the pre-computed sine kernels.

```
RESONATOR BANK PSEUDOCODE
──────────────────────────
// 6 FPU registers (x87 stack) hold 3 pairs: (delay_phase, lut_phase) for each resonator.
// All initialized to 0.0 at the start of each block.

phase_delay_1 = phase_delay_2 = phase_delay_3 = 0.0   // delay-buffer read phases
phase_lut_1   = phase_lut_2   = phase_lut_3   = 0.0   // LUT/window phases

for i in 0 .. N_frames-1:
    output_buf[i] = 0.0

    // ── Resonator 1 ──
    // Read voice from delay buffer at position floor(phase_delay_1)
    // Weight by exp_window at position floor(phase_lut_1)
    // Accumulate to output
    d1 = floor(phase_delay_1)
    w1 = floor(phase_lut_1)
    samp1 = pitch_delay_buf[d1] × exp_window[w1]
    output_buf[i] += samp1

    phase_delay_1 += delay_step_1      // advances at fixed rate (pitch-frequency related)
    phase_lut_1   += amp_A             // advances at formant-1 frequency
    if phase_lut_1 >= 1024.0:
        phase_lut_1 -= 1024.0          // wrap: resonator completes one formant cycle

    // ── Resonator 2 ──
    d2 = floor(phase_delay_2)
    w2 = floor(phase_lut_2)
    samp2 = pitch_delay_buf[d2] × exp_window[w2]
    output_buf[i] += samp2

    phase_delay_2 += delay_step_2
    phase_lut_2   += amp_B
    if phase_lut_2 >= 1024.0:
        phase_lut_2 -= 1024.0

    // ── Resonator 3 ──
    d3 = floor(phase_delay_3)
    w3 = floor(phase_lut_3)
    samp3 = pitch_delay_buf[d3] × exp_window[w3]
    output_buf[i] += samp3

    phase_delay_3 += delay_step_3
    phase_lut_3   += amp_C
    if phase_lut_3 >= 1024.0:
        phase_lut_3 -= 1024.0

// After the loop: the 6 phase accumulators are DISCARDED (they live only on the
// FPU stack within this call). Each block starts fresh from 0. This means each
// block produces one "burst" from the resonators, not a continuous ringing tone.
// The burst length is N_frames samples, shaped by the exponential window.
// Formant character comes from WHICH frequencies resonate (controlled by amp_A/B/C).
```

**Why this works as a formant filter:**
Each resonator outputs `delay_buf[phase] × exp_window[lut_phase]`. When `amp_X` is large, `lut_phase` sweeps through 0→1024 quickly, meaning the exponential window's early (loud) portion is used for many delay-buffer samples. When `amp_X` is small, the sweep is slow and the window fades to near-zero before completing a cycle — the resonator is narrow-band (high Q). The three different `amp_A/B/C` values from the vowel table select three different formant frequencies, creating the vowel shape.

---

### Pitch shifter in detail (sub_10005eb0)

```
PITCH SHIFTER PSEUDOCODE
─────────────────────────
// This function writes the current block's output samples into the
// circular delay buffer (pitch_delay_buf) at a position offset
// from the last write, implementing a delay-line pitch shifter.

// advance write position by the current pitch offset
write_pos = (write_pos + pitch_offset) mod 10240

// Wrap to valid range (handles both positive and negative offsets)
while write_pos > buf_size:  write_pos -= buf_size
while write_pos < 0:         write_pos += buf_size

// Accumulate output samples into the delay buffer
// (adds to existing content, not overwrites — feedback loop)
for i in 0 .. N_frames-1:
    idx = (write_pos + i) mod 10240
    pitch_delay_buf[idx] += output_buf[i]

// Back-step by N_frames so next call's position is consistent
write_pos -= N_frames
```

**Why reading and writing the same buffer at different rates shifts pitch:**
- Write head advances at 1 sample/sample (normal speed)
- Read head (in the resonator bank) advances at a rate set by the MIDI note (see `pitch_accumulator × -32`)
- If the read head moves faster than the write head → pitch shift up
- If slower → pitch shift down
- This is identical in principle to a tape-delay pitch shifter, or the classic "phase vocoder" approach without the FFT

---

### Complete signal flow diagram

```
MIDI note-on (velocity, pitch)
         │
         ▼
┌─────────────────────┐
│   PORTAMENTO        │  current_note ─→ slides toward target_note
│   (per block)       │  [plugin+0x614c]
└─────────────────────┘
         │ current_note (float, e.g. 60.0)
         ▼
┌─────────────────────┐
│  LCG RANDOM         │  vowel_pos = 5 ± LCG_noise
│  (per block)        │  [plugin+0x615c]
└─────────────────────┘
         │ vowel_pos
         ▼
┌─────────────────────┐
│  FORMANT TABLE      │  vowel_idx → {amp_A, amp_B, amp_C}
│  LOOKUP             │  (3 arrays indexed by vowel position)
└─────────────────────┘
         │ amp_A, amp_B, amp_C (formant band strengths)
         ▼
┌──────────────────────────────────────────────────────────────┐
│  PER-SAMPLE LOOP                                             │
│                                                              │
│  voice_wavetable[wt_pos] × amp_envelope → voice_sample      │
│                    │                                         │
│  pitch_acc += voice_sample + current_note  (phase ramp)     │
│                    │                                         │
│  delay_read_idx = trunc(pitch_acc × -32)                    │
│                    │                                         │
│  excitation = pitch_delay_buf[base - delay_read_idx]        │
│               ▲                                              │
│               │                  (circular feedback)         │
│               └──────────────────────────────────────┐       │
└──────────────────────────────────────────────────────│───────┘
                                                       │
         ┌─────────────────────────────────────────────┘
         │ pitch_delay_buf (10240 floats, circular)
         ▼
┌─────────────────────┐
│  RESONATOR BANK     │  3 parallel resonators:
│  (sub_10005fb0)     │  each reads delay_buf at its own phase
│                     │  weighted by exp_window[lut_phase]
│  Resonator 1: F1    │  lut_phase advances by amp_A / block
│  Resonator 2: F2    │  lut_phase advances by amp_B / block
│  Resonator 3: F3    │  lut_phase advances by amp_C / block
│                     │
│  output = Σ samp_r  │  (sum of 3 resonator outputs per sample)
└─────────────────────┘
         │ output_buf[N_frames]
         ▼
┌─────────────────────┐
│  PITCH SHIFTER      │  Writes output_buf into pitch_delay_buf
│  (sub_10005eb0)     │  at write_pos + pitch_offset, creating
│                     │  the feedback loop for next block.
└─────────────────────┘
         │
         ▼
    output_buf → float32 stereo → host output buffers
```

---

### Why it sounds like a "human voice"

1. **Voice wavetable source**: The raw material is a recording of a real human voice (Tibetan monk chanting), stored as 1024-sample cycles in the plugin's data section. The "lama" timbre is baked in from the start.

2. **Pitch via delay-line reading**: The pitch is controlled by *how far back* in the delay buffer the read head reaches, not by resampling. This preserves the spectral character of the voice source regardless of pitch — a key quality of physical modelling synthesis.

3. **Formant selection via exponentially-damped resonators**: The three resonators shape the spectrum to emphasize the frequencies that define vowel identity (F1, F2, F3). The exponential damping gives each resonator a natural Q curve — like a real vocal tract resonance.

4. **LCG vowel modulation**: The random perturbation of `vowel_pos` each block means the formants subtly shift over time. Real singing has small continuous variations in formant frequencies — the LCG approximates this with cheap pseudo-randomness.

5. **Pitch accumulator with voice feedback**: The fact that `pitch_acc += voice_sample + note` means the pitch phase is *perturbed by the voice waveform shape* itself. This creates a slight non-linear pitch modulation — the voice source "breathes" into the pitch control, adding the micro-variations that make it feel alive rather than mechanical.
