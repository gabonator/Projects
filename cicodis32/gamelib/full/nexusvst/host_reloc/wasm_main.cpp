// wasm_main.cpp — WebAssembly interface for Nexus VST emulator (RELOC build)
//
// Memory model: flat direct access, same as RASPI.
// App only touches addresses >= 0xe6000.  Low memory (0x0–0xe5fff) is
// available for the JS host (output buffers live at OUT_L_ADDR / OUT_R_ADDR).
//
// Startup sequence from JS:
//   1. Fetch & write section bins into wasm memory at their RELOC addresses:
//        Nexus_rdata.bin   → 0x0e6000
//        Nexus_data.bin    → 0x3fb000
//        SYNSOEMU_rdata.bin→ 0x1007000
//        SYNSOEMU_data.bin → 0x10a6000
//   2. Call nexus_init()
//   3. Optionally call nexus_load_preset(ptr, size) with FXP chunk in wasm memory
//   4. Loop: nexus_midi() then nexus_process(), read Float32Arrays at out_l/out_r

#include <cstdint>
#include <cstdio>
#include <cstring>

static const int BLOCK_SIZE = 512;

// Output buffers at fixed low-memory addresses (below 0xe6000, safe from app)
#define OUT_L_ADDR 0x2000  // float[512] = 2048 bytes  (0x2000–0x27ff)
#define OUT_R_ADDR 0x2800  // float[512] = 2048 bytes  (0x2800–0x2fff)

// Direct memory access — wasm linear memory starts at host address 0
static inline void     memoryASet  (int,int o,uint8_t  v){*(uint8_t*) o=v;}
static inline void     memoryASet16(int,int o,uint16_t v){*(uint16_t*)o=v;}
static inline void     memoryASet32(int,int o,uint32_t v){*(uint32_t*)o=v;}
static inline void     memoryASet64(int,int o,uint64_t v){*(uint64_t*)o=v;}
static inline uint8_t  memoryAGet  (int,int o){return *(uint8_t*) o;}
static inline uint16_t memoryAGet16(int,int o){return *(uint16_t*)o;}
static inline uint32_t memoryAGet32(int,int o){return *(uint32_t*)o;}
static inline uint64_t memoryAGet64(int,int o){return *(uint64_t*)o;}
// Float macros defined by cico32.h (via nexus.cpp), not needed here

// appRootPath — not used in WASM (file access goes through VFS/JS), but referenced in kernel32.h
const char* appRootPath = "";

// Forward declarations — defined in cico32.h (included via nexus.cpp)
extern uint32_t eax, ecx;
extern volatile uint32_t esp;
extern uint16_t ds, ss;
extern int allocatorPtr;
int  allocate(int size);
void push32(uint32_t);

// Forward declarations — defined in nexus.cpp
void init();
void _initterm();
void sub_15070();
void sub_1b3a0();
void sub_1b470();

// --- Audio master callback (called by plugin via callByAddress(0x77778888)) ---
void sub_77778888()
{
    uint32_t op = memoryAGet32(ss, esp + 4);
    switch (op) {
        case 0: eax = 1;    break; // audioMasterAutomate
        case 1: eax = 2400; break; // audioMasterVersion
        case 6: eax = 1;    break; // audioMasterWantMidi
        case 7: {                   // audioMasterGetTime
            static uint32_t vtiPtr = 0;
            if (!vtiPtr) {
                vtiPtr = allocate(128);
                // sampleRate at +0x08 (double) — read by sub_55570 via edx+0x8;
                // without this, sub_55570 writes 0.0 → thisPtr+0x110 → grain ratio = inf → hang
                double sr = 44100.0; uint64_t srBits; memcpy(&srBits, &sr, 8);
                *(uint64_t*)(uintptr_t)(vtiPtr + 8) = srBits;
                // tempo at +0x20 (double) — match native main.cpp
                double bpm = 140.0; uint64_t bpmBits; memcpy(&bpmBits, &bpm, 8);
                *(uint64_t*)(uintptr_t)(vtiPtr + 32) = bpmBits;
            }
            eax = vtiPtr;
            break;
        }
        default: eax = 0; break;
    }
}

// --- Plugin state ---
static uint32_t s_pluginPtr, s_thisPtr;
static uint32_t s_inL, s_inR, s_outL, s_outR;
static uint32_t s_inputPtrs, s_outputPtrs;
static int s_midiStatus = -1, s_midiD1, s_midiD2;

static uint32_t callDispatcher(uint32_t opcode, uint32_t index, uint32_t value,
                               uint32_t ptr, uint32_t opt)
{
    push32(opt); push32(ptr); push32(value);
    push32(index); push32(opcode); push32(s_pluginPtr);
    sub_1b3a0();
    return eax;
}

extern "C" {

// nexus_init — call after JS has written all four section bins into wasm memory
void nexus_init()
{
    init();   // sets ESP=0x592110; loadOverlay calls are #ifndef WASM'd out
    _initterm();

    push32(0x77778888);
    sub_15070();

    s_pluginPtr = eax + 0x20;
    s_thisPtr   = memoryAGet32(0, s_pluginPtr + 0x40);

    float sr = 44100.0f;
    uint32_t srBits; memcpy(&srBits, &sr, 4);
    callDispatcher(10, 0, 0, 0, srBits);     // effSetSampleRate
    callDispatcher(11, 0, BLOCK_SIZE, 0, 0); // effSetBlockSize
    callDispatcher(12, 0, 1, 0, 0);          // effMainsChanged (activate)

    s_inL  = allocate(BLOCK_SIZE * 4);
    s_inR  = allocate(BLOCK_SIZE * 4);
    s_outL = allocate(BLOCK_SIZE * 4);
    s_outR = allocate(BLOCK_SIZE * 4);
    s_inputPtrs  = allocate(8);
    s_outputPtrs = allocate(8);
    memoryASet32(0, s_inputPtrs  + 0, s_inL);
    memoryASet32(0, s_inputPtrs  + 4, s_inR);
    memoryASet32(0, s_outputPtrs + 0, s_outL);
    memoryASet32(0, s_outputPtrs + 4, s_outR);
}

// nexus_load_preset — ptr/size point to FXP chunk data already in wasm memory
void nexus_load_preset(int ptr, int size)
{
    callDispatcher(24, 1, (uint32_t)size, (uint32_t)ptr, 0); // effSetChunk

    // effSetChunk enables audio objects (sets byte+0x8d=1 via sub_62240).
    // The per-SR audio setup (sub_68810) only runs inside sub_62310 when:
    //   (a) the stored SR differs from the new SR, AND (b) al==1.
    // During nexus_init(), the child list was empty so sub_62310 was never
    // reached.  Now that objects exist and are enabled, force a re-propagation
    // by clearing the cached SR so sub_5f4c0 sees a "changed" value.
    memoryASet32(0, s_thisPtr + 0xb4, 0);
    float sr = 44100.0f;
    uint32_t srBits; memcpy(&srBits, &sr, 4);
    callDispatcher(10, 0, 0, 0, srBits); // effSetSampleRate — now with al==1
}

// nexus_midi — queue one MIDI event for the next nexus_process() call
void nexus_midi(int status, int data1, int data2)
{
    s_midiStatus = status;
    s_midiD1 = data1;
    s_midiD2 = data2;
}

// nexus_process — render 512 samples; copies L/R output to OUT_L_ADDR / OUT_R_ADDR
// Returns OUT_L_ADDR so JS can build Float32Array(Module.HEAPF32.buffer, retval, 512)
int nexus_process()
{
    if (s_midiStatus >= 0) {
        uint32_t ev = allocate(32);
        memoryASet32(0, ev + 0x00, 1);   // kVstMidiType
        memoryASet32(0, ev + 0x04, 32);  // byteSize
        memoryASet32(0, ev + 0x08, 0);   // deltaFrames
        memoryASet32(0, ev + 0x18, (uint32_t)(s_midiStatus | (s_midiD1<<8) | (s_midiD2<<16)));
        uint32_t evs = allocate(12);
        memoryASet32(0, evs + 0, 1);
        memoryASet32(0, evs + 4, 0);
        memoryASet32(0, evs + 8, ev);
        callDispatcher(25, 0, 0, evs, 0); // effProcessEvents
        s_midiStatus = -1;
    }

    push32(BLOCK_SIZE);
    push32(s_outputPtrs);
    push32(s_inputPtrs);
    push32(s_pluginPtr);
    ecx = s_thisPtr;
    sub_1b470();

    uint32_t aL = memoryAGet32(0, s_outputPtrs + 0);
    uint32_t aR = memoryAGet32(0, s_outputPtrs + 4);
    memcpy((void*)OUT_L_ADDR, (void*)(uintptr_t)aL, BLOCK_SIZE * 4);
    memcpy((void*)OUT_R_ADDR, (void*)(uintptr_t)aR, BLOCK_SIZE * 4);
    return OUT_L_ADDR;
}

// Convenience accessors so JS can hardcode the output buffer addresses
int nexus_out_l() { return OUT_L_ADDR; }
int nexus_out_r() { return OUT_R_ADDR; }

} // extern "C"
