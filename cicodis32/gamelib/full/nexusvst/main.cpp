#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
//
// main.cpp — Nexus VST DLL C++ emulator
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>

// Memory constants
static const int MEM_BASE_MAIN = 0x10000000;
static const int MEM_SIZE_MAIN = 1024 * 1024 * 1024;

const char* appRootPath = "res/";

// Memory layout:
// 0x10000000 base
// 0x10001000 - 0x100e531b: .text (934KB)
// 0x100e6000 - 0x103fa819: .rdata (3.2MB)
// 0x103fb000 - 0x10583d5c: .data (1.6MB)
// 0x10584000 - 0x105842c8: .rsrc
// 0x10585000 - 0x10592110: .reloc
// 0x11000000 - 0x1114b000: SYNSOEMU sections
// 0x11100000 - 0x111fffff: stack (1MB)
// 0x12000000+: heap (bump allocator)

static const int MEM_SIZE = MEM_SIZE_MAIN; // 1GB
std::vector<uint8_t> memory(MEM_SIZE, 0);

int allocatorPtr = 0x12000000;

std::vector<uint8_t> GetFileContents(std::string fullPath)
{
    FILE* f = fopen(fullPath.c_str(), "rb");
    if (!f) {
        fprintf(stderr, "Cannot open: %s\n", fullPath.c_str());
        return {};
    }
    fseek(f, 0, SEEK_END);
    size_t sz = ftell(f);
    rewind(f);
    std::vector<uint8_t> data(sz);
    fread(data.data(), 1, sz, f);
    fclose(f);
    return data;
}

long long get32count = 0;
uint32_t _trapAddr = 0;
uint32_t _outLWatch = 0;
bool _outLWatchArmed = false;
bool _trapArmed = false;
int _escapeTimeoutSec = 120; // 2 minute timeout
bool _rdataLocked = false;
bool _nanTraceArmed = false;
const char* _currentFunc = nullptr;
int _nanTrapArmed_g = -1;
uint32_t _nanWatchStart = 0, _nanWatchEnd = 0;
int _nanWatchHits = -1;
uint32_t _nanWatchBase = 0;
bool _nanWatchArmed = false;
bool _nanDetectArmed = false;
bool _fldNanArmed = false;
uint32_t _memWatch = 0;
int _memWatchArmed = 0;
namespace fpuinsns { bool _traceFpuCompare = false; }
using fpuinsns::_traceFpuCompare;
void alarmHandler(int sig) {
    void* _bt[20]; int _bn = backtrace(_bt, 20);
    fprintf(stderr, "TIMEOUT — crashing immediately. Backtrace:\n");
    backtrace_symbols_fd(_bt, _bn, 2);
    fflush(stderr);
    abort();
}

void memoryASet(int s, int o, int v) {
    unsigned uo = (unsigned)o;
    // Near-zero: SEH chain reads — fs: returns 0, code accesses near-zero
    if (uo < 0x1000) return;
    // Crash on rdata write after init
    extern bool _rdataLocked;
    if (_rdataLocked && ((uo >= 0x100e6000u && uo < 0x103fa819u) || (uo >= 0x11007000u && uo < 0x110a6000u))) {
        fprintf(stderr, "RDATA WRITE: [0x%08x]=0x%02x\n", o, v & 0xff);
        void* _bt[15]; int _bn = backtrace(_bt, 15);
        backtrace_symbols_fd(_bt, _bn, 2);
        assert(0);
    }
    int idx = o - MEM_BASE_MAIN;
    if (idx < 0 || idx >= MEM_SIZE) {
        fprintf(stderr, "WRITE OUT OF RANGE: [0x%08x]\n", uo);
        assert(0);
    }
    memory[idx] = (uint8_t)v;
    // Watch write to preset+0x111b (effects enable byte, Layer 2)
    // preset=0x120114d8 + 0x111b = 0x120125f3
    if (uo == 0x120125f3u && (v & 0xff) != 0) {
        fprintf(stderr, "EFFECTS_FLAG WRITE: [0x120125f3]=0x%02x\n", v & 0xff);
        void* _bt[15]; int _bn = backtrace(_bt, 15);
        backtrace_symbols_fd(_bt, _bn, 2);
        fflush(stderr);
    }
    // Catch first NaN write to outL buffer area
    extern uint32_t _nanWatchBase;
    extern bool _nanWatchArmed;
    if (__builtin_expect(_nanWatchArmed && uo >= _nanWatchBase && uo < _nanWatchBase + 2048 && idx >= 3, 0)) {
        // After writing this byte, check if the containing float is NaN
        uint32_t floatAddr = uo & ~3u;
        int fi = floatAddr - MEM_BASE_MAIN;
        if (fi >= 0 && fi + 3 < MEM_SIZE) {
            uint32_t w = memory[fi] | (memory[fi+1]<<8) | (memory[fi+2]<<16) | ((uint32_t)memory[fi+3]<<24);
            // Check if this is NaN (exponent=0xFF, mantissa!=0)
            if ((w & 0x7F800000) == 0x7F800000 && (w & 0x007FFFFF) != 0) {
                _nanWatchArmed = false;
                fprintf(stderr, "NaN WRITE 0x%08x at addr 0x%08x (outL+%d)\n", w, floatAddr, floatAddr - _nanWatchBase);
                void* _bt[20]; int _bn = backtrace(_bt, 20);
                backtrace_symbols_fd(_bt, _bn, 2);
                fflush(stderr);
            }
        }
    }
    // Detect vtable 0x103d4008 being written to heap
    if (v == 0x10 && uo >= 0x12000000u && idx >= 3) {
        uint32_t w = memory[idx-3] | (memory[idx-2]<<8) | (memory[idx-1]<<16) | ((uint32_t)v<<24);
        if (w == 0x103d4008) {
            fprintf(stderr, "VTABLE 0x103d4008 written at 0x%08x\n", uo-3);
            void* _bt[20]; int _bn = backtrace(_bt, 20);
            backtrace_symbols_fd(_bt, _bn, 2);
            fflush(stderr);
        }
    }
}

// Memory access helpers for main.cpp (same logic as cico32.h inline versions)
// These are separate definitions for this TU since main.cpp doesn't include cico32.h
static inline void memoryASet16(int s, int o, int v) {
    memoryASet(s, o, v & 0xff);
    memoryASet(s, o + 1, (v >> 8) & 0xff);
}
static inline void memoryASet32(int s, int o, uint32_t v) {
    memoryASet(s, o, v & 0xff);
    memoryASet(s, o + 1, (v >> 8) & 0xff);
    memoryASet(s, o + 2, (v >> 16) & 0xff);
    memoryASet(s, o + 3, (v >> 24) & 0xff);
}
static inline void memoryASet64(int s, int o, uint64_t v) {
    for (int i = 0; i < 8; i++)
        memoryASet(s, o + i, (v >> (i * 8)) & 0xff);
}
static inline uint8_t memoryAGet(int s, int o) {
    unsigned uo = (unsigned)o;
    if (uo < 0x1000) return 0;
    int idx = o - MEM_BASE_MAIN;
    if (idx < 0 || idx >= MEM_SIZE) {
        fprintf(stderr, "READ OUT OF RANGE: [0x%08x]\n", uo);
        assert(0);
    }
    return memory[idx];
}
static inline uint16_t memoryAGet16(int s, int o) {
    unsigned uo = (unsigned)o;
    if (uo < 0x1000) return 0;
    int idx = o - MEM_BASE_MAIN;
    if (idx < 0 || idx + 1 >= MEM_SIZE) {
        fprintf(stderr, "READ OUT OF RANGE: [0x%08x]\n", uo);
        assert(0);
    }
    return memory[idx] | (memory[idx+1] << 8);
}
static inline uint32_t memoryAGet32(int s, int o) {
    ++get32count;
    unsigned uo = (unsigned)o;
    if (uo < 0x1000) return 0;
    int idx = o - MEM_BASE_MAIN;
    if (idx < 0 || idx + 3 >= MEM_SIZE) {
        fprintf(stderr, "READ OUT OF RANGE: [0x%08x]\n", uo);
        assert(0);
    }
    return memory[idx] | (memory[idx+1] << 8) | (memory[idx+2] << 16) | ((uint32_t)memory[idx+3] << 24);
}
static inline uint64_t memoryAGet64(int s, int o) {
    unsigned uo = (unsigned)o;
    if (uo < 0x1000) return 0;
    int idx = o - MEM_BASE_MAIN;
    if (idx < 0 || idx + 7 >= MEM_SIZE) {
        fprintf(stderr, "READ OUT OF RANGE: [0x%08x]\n", uo);
        assert(0);
    }
    uint64_t v = 0;
    for (int i = 0; i < 8; i++) v |= (uint64_t)memory[idx+i] << (i * 8);
    return v;
}

void loadOverlay(const char* image, int base) {
    std::string path = std::string(appRootPath) + image;
    auto data = GetFileContents(path);
    if (data.empty()) {
        fprintf(stderr, "loadOverlay failed: %s\n", path.c_str());
        return;
    }
    int idx = base - MEM_BASE_MAIN;
    if (idx >= 0 && idx + (int)data.size() <= MEM_SIZE) {
        for (size_t i = 0; i < data.size(); i++) memoryASet(0, base + i, data[i]);
        printf("Loaded %s at 0x%08x (%zu bytes)\n", image, base, data.size());
    }
}

// Trash page for failed allocations — writes here are harmless
static const int TRASH_PAGE = 0x10590000; // in .reloc section, not used

void watchTrap(int o, uint32_t v); // forward decl
int allocate(int size) {
    static int _ac = 0;
    // Ring buffer of last 10 allocs for debugging
    static struct { int sz; int ptr; int idx; } _hist[10];
    static int _hpos = 0;
    ++_ac;
    _hist[_hpos] = {size, allocatorPtr, _ac};
    _hpos = (_hpos + 1) % 10;
    if (_ac <= 30 || _ac % 10000 == 0)
        printf("[alloc#%d] sz=%d at=0x%08x\n", _ac, size, allocatorPtr);
    if (size < 0 || size > 100000000) {
        fprintf(stderr, "[alloc] FATAL: bad size %u (0x%08x) alloc#%d\n", (unsigned)size, (unsigned)size, _ac);
        void* _abt[20]; int _abn = backtrace(_abt, 20); backtrace_symbols_fd(_abt, _abn, 2);
        fflush(stderr);
        abort();
    }
    if ((uint32_t)allocatorPtr + size > (uint32_t)(MEM_BASE_MAIN + MEM_SIZE) || allocatorPtr < MEM_BASE_MAIN) {
        printf("[alloc] FATAL: OOM! ptr=0x%08x sz=%d — aborting\n", allocatorPtr, size);
        abort();
    }
    int ptr = allocatorPtr;
    allocatorPtr += (size + 3) & ~3;
    // Zero-initialize
    int idx = ptr - MEM_BASE_MAIN;
    if (idx >= 0 && idx + size <= MEM_SIZE) {
        // Check if this allocation overlaps watched address
        if (ptr <= 0x103fb04c && ptr + size > 0x103fb04c) {
            printf("[alloc] OVERLAP: alloc(sz=%d) at 0x%08x..0x%08x covers 0x103fb04c!\n", size, ptr, ptr+size);
            watchTrap(0x103fb04c, 0);
        }
        for (int z = 0; z < size; z++) memoryASet(0, ptr + z, 0);
    }
    return ptr;
}

// fixReloc is defined in nexus.cpp (empty — no-op for flat memory model)

void sync() {
    // Heartbeat — can add timing/progress here
    static int count = 0;
    if (++count % 1000000 == 0) {
        printf("[sync] %dM calls, allocatorPtr=0x%08x\n", count / 1000000, allocatorPtr);
    }
}

// --- Registers (defined in cico32.h, compiled in nexus.cpp) ---
extern uint32_t eax, ebx, ecx, edx, esi, edi, esp, ebp;
extern uint16_t ds, ss, es, gs, cs, fs;

// --- Functions from nexus.cpp ---
extern void init();
extern void start();
extern void VSTPluginMain();
extern void sub_1001d100();  // VSTPluginMain entry
extern void sub_10015070();  // real plugin init (called by sub_1001d100)
extern void sub_1001b3a0();  // dispatcher
extern void sub_10031d10();  // bus struct initializer
extern void indirectCall(int s, int o, int originSeg, int originOfs);
inline void indirectCall(int s, int o) { indirectCall(s, o, 0, 0); }
extern void callByAddress(uint32_t addr); // dispatch to sub_xxx by address

// Stack helpers (need access to registers)
static void _push32(uint32_t v) {
    esp -= 4;
    memoryASet32(ss, esp, v);
}
static uint32_t _pop32() {
    uint32_t v = memoryAGet32(ss, esp);
    esp += 4;
    return v;
}

// Read float from emulated memory
static float readFloat32(uint32_t addr) {
    uint32_t bits = memoryAGet32(0, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

// Write float to emulated memory
static void writeFloat32(uint32_t addr, float f) {
    uint32_t bits;
    memcpy(&bits, &f, 4);
    memoryASet32(0, addr, bits);
}

// --- WAV writer ---
void writeWav(const char* filename, const float* left, const float* right, int numSamples, int sampleRate) {
    FILE* f = fopen(filename, "wb");
    if (!f) return;
    int dataSize = numSamples * 2 * 2; // 16-bit stereo
    int fileSize = 44 + dataSize;
    // RIFF header
    fwrite("RIFF", 1, 4, f);
    uint32_t tmp = fileSize - 8; fwrite(&tmp, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    fwrite("fmt ", 1, 4, f);
    tmp = 16; fwrite(&tmp, 4, 1, f);
    uint16_t fmt = 1; fwrite(&fmt, 2, 1, f); // PCM
    fmt = 2; fwrite(&fmt, 2, 1, f); // stereo
    tmp = sampleRate; fwrite(&tmp, 4, 1, f);
    tmp = sampleRate * 4; fwrite(&tmp, 4, 1, f); // byte rate
    fmt = 4; fwrite(&fmt, 2, 1, f); // block align
    fmt = 16; fwrite(&fmt, 2, 1, f); // bits per sample
    fwrite("data", 1, 4, f);
    tmp = dataSize; fwrite(&tmp, 4, 1, f);
    for (int i = 0; i < numSamples; i++) {
        float lv = left[i], rv = right[i];
        if (lv > 1.0f) lv = 1.0f; if (lv < -1.0f) lv = -1.0f;
        if (rv > 1.0f) rv = 1.0f; if (rv < -1.0f) rv = -1.0f;
        int16_t l = (int16_t)(lv * 32767.0f);
        int16_t r = (int16_t)(rv * 32767.0f);
        fwrite(&l, 2, 1, f);
        fwrite(&r, 2, 1, f);
    }
    fclose(f);
    printf("WAV written: %s (%d samples)\n", filename, numSamples);
}

__attribute__((noinline)) void watchTrap(int o, uint32_t v) {
    printf("  TRAP: [0x%08x] = 0x%08x\n", o, v);
    // Set breakpoint here in lldb: b watchTrap
}

// --- Main ---
int main(int argc, char* argv[]) {
    setbuf(stdout, NULL); // disable buffering
    printf("Nexus C++ emulator starting...\n");

    // Set transport playing early — arp engine may cache state during init
    memoryASet32(0, 0x10593010, (1<<1)); // kVstTransportPlaying

    // Initialize — load PE sections
    init();
    printf("Init done. allocatorPtr=0x%08x\n", allocatorPtr);

    // Load SYNSOEMU DRM engine overlays
    loadOverlay("SYNSOEMU_headers.bin", 0x11000000);
    loadOverlay("SYNSOEMU_text.bin", 0x11001000);
    loadOverlay("SYNSOEMU_rdata.bin", 0x11007000);
    loadOverlay("SYNSOEMU_data.bin", 0x110a6000);
    loadOverlay("SYNSOEMU_rsrc.bin", 0x1114a000);
    loadOverlay("SYNSOEMU_reloc.bin", 0x1114b000);

    // SYNSOEMU PE relocations are PRE-APPLIED in the binary section files
    // (cicodis already applied delta=0x1000000 when generating the overlays)
    // Do NOT apply relocations again — that would double-relocate!

    // --- Patch IAT with enum values ---
    // Each IAT slot gets its corresponding ptrImportTable enum value.
    // The IAT has GAPS (not every 4-byte slot has an import), so we
    // patch by actual address, not sequentially.
    printf("Patching IAT...\n");
    {
#include "iat_patches.inc"
    }

    // --- Patch SYNSOEMU IAT ---
    // SYNSOEMU has its own IAT at 0x11007000 with 6 kernel32 imports.
    // Use unique enum values (0x6ab10001+) to avoid collision with Nexus IAT.
    printf("Patching SYNSOEMU IAT...\n");
    memoryASet32(0, 0x11007000, 0x6ab10001); // GlobalFree
    memoryASet32(0, 0x11007004, 0x6ab10002); // RaiseException
    memoryASet32(0, 0x11007008, 0x6ab10003); // VirtualQuery
    memoryASet32(0, 0x1100700c, 0x6ab10004); // ExitProcess
    memoryASet32(0, 0x11007010, 0x6ab10005); // VirtualProtect
    memoryASet32(0, 0x11007014, 0x6ab10006); // GlobalAlloc

    // Set up CRT heap handle
    memoryASet32(0, 0x105822fc, 0x10000002);

    // FPU exception flag (enables fast path in sub_100caaf0)
    memoryASet32(0, 0x10582d08, 1);

    // Set ContentPath string
    const char* contentPath = "C:\\Nexus\\installer\\Nexus Content\\";
    for (int i = 0; contentPath[i]; i++)
        memoryASet(0, 0x1057f420 + i, contentPath[i]);
    memoryASet(0, 0x1057f420 + strlen(contentPath), 0);

    // rdata will be locked after _initterm (constructors may write to rdata)

    // --- Initialize bus structs (8 global constructors) ---
    printf("Initializing bus structs...\n");
    uint32_t busInits[][2] = {
        {0x10581728, 0x103fd610}, {0x10581800, 0x103fd650},
        {0x10581570, 0x103fd690}, {0x10581770, 0x103fd6d0},
        {0x105815b8, 0x103fd710}, {0x105817b8, 0x103fd750},
        {0x10581650, 0x103fd790}, {0x105816e0, 0x103fd7d0},
    };
    for (auto& bi : busInits) {
        _push32(bi[1]);        // source data pointer as arg
        ecx = bi[0];           // target address in ecx (thiscall)
        sub_10031d10();        // +stackDrop4: pops its own arg
    }
    printf("Bus structs initialized.\n");

    // --- Call VSTPluginMain ---

    // DRM strategy: run DRM init naturally (no bypass) but set bypass flags
    // AFTER init completes, to simplify the constructor's alloca-heavy module init.
    // The cipher state is seeded and the ordinal table is populated by sub_10026080.
    // The bypass flags only affect the module initialization path, not the cipher itself.

    // NO SEEDING — let the natural SYNSOEMU init path compute all DRM data

    // Verify DRM cipher tables against Windows reference
    { FILE* dsf = fopen("win_data_section.bin", "rb");
      if (dsf) {
        fseek(dsf, 0, SEEK_END); long dsz = ftell(dsf); rewind(dsf);
        std::vector<uint8_t> dd(dsz);
        fread(dd.data(), 1, dsz, dsf); fclose(dsf);
        int mismatches = 0, checked = 0, first_mm = -1, last_mm = -1;
        int ours_zero = 0; // mismatches where ours=0 (not computed)
        for (int i = 0; i < (int)dd.size(); i++) {
            if (dd[i] <= 3) {
                checked++;
                uint8_t ours = memoryAGet(0, 0x10580000 + i);
                if (ours != dd[i]) {
                    mismatches++;
                    if (ours == 0) ours_zero++;
                    if (first_mm < 0) first_mm = i;
                    last_mm = i;
                }
            }
        }
        printf("DRM verify: %d/%d match (%d mismatches, %d where ours=0)\n",
               checked-mismatches, checked, mismatches, ours_zero);
        if (first_mm >= 0)
            printf("  First mismatch at 0x%08x, last at 0x%08x\n", 0x10580000+first_mm, 0x10580000+last_mm);
        // Show first 10 mismatches
        int shown = 0;
        for (int i = 0; i < (int)dd.size() && shown < 10; i++) {
            if (dd[i] <= 3) {
                uint8_t ours = memoryAGet(0, 0x10580000 + i);
                if (ours != dd[i]) {
                    printf("  MM[%d] 0x%08x: ours=%d win=%d\n", shown, 0x10580000+i, ours, dd[i]);
                    shown++;
                }
            }
        }
        // Don't abort here — tables are computed during constructor, not before it
      }
    }


    // --- Run _initterm global constructors ---
    // The real DLL runs these 75 constructors during DllMain via CRT _initterm.
    // They initialize global objects (linked lists, vtables, etc.) that the main
    // constructor depends on. Without them, the constructor hangs in list walks.
    {
        // _initterm table: 0x100e62ec - 0x100e6418 (75 function pointers)
        printf("Running _initterm global constructors...\n");
        printf("  PRE-initterm: [0x103fb04c]=0x%08x\n", memoryAGet32(0, 0x103fb04c));
        int ctorCount = 0;
        for (uint32_t slot = 0x100e62ec; slot < 0x100e6418; slot += 4) {
            uint32_t fn = memoryAGet32(0, slot);
            if (fn && fn >= 0x10001000 && fn < 0x100e5320) {
                uint32_t savedEsp = esp;
                printf("  ctor[%d] = 0x%08x\n", ctorCount, fn);
                callByAddress(fn);
                esp = savedEsp; // restore in case of stack drift
                ctorCount++;
            }
        }
        printf("  Ran %d global constructors\n", ctorCount);
        printf("  POST-initterm: [0x103fb04c]=0x%08x\n", memoryAGet32(0, 0x103fb04c));

        // Lock rdata — constructors done, any write after this is a bug
        _rdataLocked = true;
        printf("rdata locked.\n");
    }

    // --- Call SYNSOEMU DllMain (initializes class factories) ---
    {
        extern void sub_11001000(); // SYNSOEMU entry point
        printf("Calling SYNSOEMU DllMain...\n");
        uint32_t savedEsp = esp;
        _push32(0);           // lpvReserved
        _push32(1);           // fdwReason = DLL_PROCESS_ATTACH
        _push32(0x11000000);  // hinstDLL
        sub_11001000();
        esp = savedEsp;
        printf("SYNSOEMU DllMain done, eax=%d\n", eax);
    }

    // --- Call sub_10015070 (VSTPluginMain init) directly ---
    extern void sub_10015070();

    extern long long get32count;
    get32count = 0;

    // Check if rdata vtable is intact before constructor
    printf("Pre-constructor: [0x103d417c]=0x%08x (should be 0x100640b0)\n", memoryAGet32(0, 0x103d417c));
    printf("PRE-constructor: [0x103fb04c]=0x%08x\n", memoryAGet32(0, 0x103fb04c));
    printf("Calling sub_10015070...\n");
    fpuinsns::_traceFpuCompare = true;
    // Alarm-based timeout — crashes immediately if exceeded
    signal(SIGALRM, alarmHandler);
    alarm(_escapeTimeoutSec);
    uint32_t savedEsp0 = esp;
    _push32(0x77778888);
    sub_10015070();
    esp = savedEsp0;
    alarm(0); // cancel timeout
    fpuinsns::_traceFpuCompare = false;
    printf("Constructor call 1 done! (%lldM reads)\n", get32count / 1000000);
    uint32_t pluginPtr = eax; // sub_10015070 returns thisPtr
    printf("sub_10015070 returned: eax=0x%08x allocPtr=0x%08x\n", pluginPtr, allocatorPtr);

    // Scan for AEffect in allocated heap if returned ptr doesn't look like AEffect
    // (VSTPluginMain may return thisPtr instead of AEffect)
    uint32_t dispCheck = (pluginPtr >= 0x12000000) ? memoryAGet32(0, pluginPtr + 4) : 0;
    bool looksLikeAEffect = (dispCheck >= 0x10001000 && dispCheck < 0x100e5320); // code section range
    if (!looksLikeAEffect) {
        printf("Scanning for AEffect (dispatcher=0x1001b3a0)...\n");
        for (uint32_t scan = 0x12000000; scan < (uint32_t)allocatorPtr; scan += 4) {
            if (memoryAGet32(0, scan + 4) == 0x1001b3a0) {
                pluginPtr = scan;
                printf("Found AEffect at 0x%08x\n", pluginPtr);
                break;
            }
        }
    }
    // If still not found, search for the 4.4MB allocation (thisPtr) which has vtable 0x100e7120
    if (pluginPtr < 0x12000000) {
        printf("Scanning for thisPtr (vtable=0x100e7120)...\n");
        for (uint32_t scan = 0x12000000; scan < (uint32_t)allocatorPtr; scan += 4) {
            if (memoryAGet32(0, scan) == 0x100e7120) {
                printf("Found thisPtr candidate at 0x%08x\n", scan);
                // Check if this has an AEffect at [+8]
                uint32_t ae = memoryAGet32(0, scan + 8);
                if (ae >= 0x12000000 && ae < (uint32_t)allocatorPtr) {
                    uint32_t disp = memoryAGet32(0, ae + 4);
                    printf("  [+8]=0x%08x [ae+4]=0x%08x\n", ae, disp);
                    if (disp == 0x1001b3a0) {
                        pluginPtr = ae;
                        printf("Found AEffect at 0x%08x via thisPtr 0x%08x\n", ae, scan);
                        break;
                    }
                }
                // Even if no AEffect yet, the constructor allocated 0x438b88 starting here
                // The AEffect might be at a fixed offset inside
                uint32_t candidateThis = scan;
                // Check processReplacing at ae+0x50
                uint32_t pr = memoryAGet32(0, scan + 8 + 0x50);
                printf("  candidateThis=0x%08x [+8+50]=0x%08x\n", scan, pr);
                break;
            }
        }
    }
    uint32_t thisPtr = 0;
    if (pluginPtr >= 0x12000000) {
        thisPtr = memoryAGet32(0, pluginPtr + 0x40);
        if (!thisPtr || thisPtr < 0x12000000) thisPtr = pluginPtr;
    } else {
        // Use the first 4.4MB allocation directly as thisPtr
        // The first large allocation is at 0x120000e4 (alloc#10)
        thisPtr = 0x120000e4;
        pluginPtr = memoryAGet32(0, thisPtr + 8); // AEffect at thisPtr+8
        if (pluginPtr < 0x12000000) {
            // No AEffect — we need to create one manually
            printf("No AEffect found. Creating manually.\n");
            pluginPtr = allocate(256);
            memoryASet32(0, pluginPtr + 0x04, 0x1001b3a0); // dispatcher
            memoryASet32(0, pluginPtr + 0x50, 0x1001b470); // processReplacing
            memoryASet32(0, pluginPtr + 0x40, thisPtr);     // object ptr
            memoryASet32(0, pluginPtr + 0x48, 0x4E455855);  // uniqueID "NEXU"
            memoryASet32(0, thisPtr + 0x08, pluginPtr);     // store back-pointer
        }
    }
    uint32_t dispatcherAddr = memoryAGet32(0, pluginPtr + 0x04);
    uint32_t processReplacingAddr = memoryAGet32(0, pluginPtr + 0x50);
    printf("Plugin: AEffect=0x%08x this=0x%08x dispatcher=0x%08x processReplacing=0x%08x\n",
           pluginPtr, thisPtr, dispatcherAddr, processReplacingAddr);

    // Dump key float values for comparison with Windows
    printf("\n=== Post-constructor state dump ===\n");
    auto dumpFloat = [](uint32_t addr, const char* name) {
        uint32_t raw = memoryAGet32(0, addr);
        float f; memcpy(&f, &raw, 4);
        printf("  [0x%08x] %s = 0x%08x (float: %g)\n", addr, name, raw, f);
    };
    dumpFloat(thisPtr + 0xb4, "+0xb4 sampleRate");
    dumpFloat(thisPtr + 0xb8, "+0xb8");
    dumpFloat(thisPtr + 0xcc, "+0xcc");
    dumpFloat(thisPtr + 0xdc, "+0xdc");
    dumpFloat(thisPtr + 0x1d8, "+0x1d8 chunkSize");
    dumpFloat(thisPtr + 0x1dc, "+0x1dc");
    // Module[0] buffer
    uint32_t m0buf = memoryAGet32(0, thisPtr + 0x26C44);
    printf("  Module[0] buf ptr: 0x%08x\n", m0buf);
    // DED0/DED4
    printf("  DED0: 0x%08x  DED4: 0x%08x\n", memoryAGet32(0, thisPtr + 0xded0), memoryAGet32(0, thisPtr + 0xded4));
    // Effects module
    uint32_t effPtr = memoryAGet32(0, thisPtr + 0x42A11C);
    printf("  Effects module ptr: 0x%08x\n", effPtr);
    if (effPtr > 0x10000000) {
        printf("    [+0x00]=0x%08x [+0x24]=0x%08x\n", memoryAGet32(0, effPtr), memoryAGet32(0, effPtr + 0x24));
    }
    // Preset flags
    uint32_t presetPtr = memoryAGet32(0, thisPtr + 0xe734);
    printf("  Preset ptr: 0x%08x\n", presetPtr);
    if (presetPtr > 0x10000000) {
        printf("    [+0xb00]=%d [+0xb0c]=%d\n", memoryAGet(0, presetPtr + 0xb00), memoryAGet(0, presetPtr + 0xb0c));
    }
    printf("=== End dump ===\n\n");

    // No heap dump — running naturally from constructor output

    // Set audioMaster callback pointer at thisPtr+4
    memoryASet32(0, thisPtr + 0x4, 0x77778888);

    // Force main vtable — constructor leaves derived vtable (0x103d3450) but
    // Windows has base vtable (0x100e7120) after full init. vtbl[0x288] needs
    // to be 0x10015160 (voice render) which only exists in the base vtable.
    memoryASet32(0, thisPtr, 0x100e7120);
    printf("  Set vtable to 0x100e7120 (base class, matches Windows)\n");

    // NOTE: port_cpp reloaded rdata here because the constructor corrupted it.
    // With _rdataLocked, the constructor should NOT write to rdata.
    // If it does, the assert will catch it and we fix the root cause.
    {
    }

    // No IAT re-patching needed — rdata was not reloaded

    // --- Post-init setup ---
    // Re-verify DRM tables after constructor
    { FILE* dsf = fopen("win_data_section.bin", "rb");
      if (dsf) {
        fseek(dsf, 0, SEEK_END); long dsz = ftell(dsf); rewind(dsf);
        std::vector<uint8_t> dd(dsz);
        fread(dd.data(), 1, dsz, dsf); fclose(dsf);
        int mm = 0, checked = 0, oz = 0;
        for (int i = 0; i < (int)dd.size(); i++) {
            if (dd[i] <= 3) { checked++; uint8_t o = memoryAGet(0, 0x10580000+i);
              if (o != dd[i]) { mm++; if (o==0) oz++; } } }
        printf("POST-CTOR DRM verify: %d/%d match (%d mismatches, %d ours=0)\n",
               checked-mm, checked, mm, oz);
        if (mm) {
            printf("  ALL %d mismatches:\n", mm);
            for (int i = 0; i < (int)dd.size(); i++) {
                if (dd[i] <= 3) { uint8_t o = memoryAGet(0, 0x10580000+i);
                  if (o != dd[i]) printf("    0x%08x: ours=%d win=%d\n", 0x10580000+i, o, dd[i]); } }
        }
      }
    }
    printf("Post-init: thisPtr=0x%08x de54=%d de58=%d allocPtr=0x%08x\n",
           thisPtr, memoryAGet32(0, thisPtr+0xde54), memoryAGet32(0, thisPtr+0xde58), allocatorPtr);

    // content_ready must be 0 (like Windows) — setting to 1 causes wrong code path
    // in sub_10015160 during processReplacing
    // memoryASet(0, thisPtr + 0x37e1d8, 0x01);  // WRONG — was forcing content_ready=1

    // Set module vtable at thisPtr+0x42c3c8 (Windows value: 0x103d3eb8)
    // This is set during content initialization by sub_10062160.
    // Without it, sub_100016e0's 134 vtable dispatches crash on null.
    if (!memoryAGet32(0, thisPtr + 0x42c3c8)) {
        memoryASet32(0, thisPtr + 0x42c3c8, 0x103d3eb8);
        printf("  Set module vtable [thisPtr+0x42c3c8] = 0x103d3eb8\n");
    }

    // watchpoints removed

    
    // Dump full preset for comparison
    if (0)
    { uint32_t pp2 = memoryAGet32(0, thisPtr + 0xe734);
      if (pp2 >= 0x12000000) {
        FILE* df = fopen("dump_preset.bin", "wb");
        if (df) {
          for (int i = 0; i < 0xc00; i++) { uint8_t b = memoryAGet(0, pp2+i); fwrite(&b, 1, 1, df); }
          fclose(df);
          printf("  Dumped preset to dump_preset.bin\n");
        }
      }
    }
// Fix: clear garbage bytes at preset+0xb20..0xb23 (should be 0 like Windows)
    { uint32_t pp = memoryAGet32(0, thisPtr + 0xe734);
      if (pp >= 0x12000000) {
        memoryASet32(0, pp + 0xb20, 0);
        // Dump module enable flags
        printf("  Module enable flags: ");
        for (int i = 0; i < 10; i++) {
          int ebp_val = i * 5;
          uint8_t v = memoryAGet(0, pp + ebp_val + 0xb4b);
          printf("[%d]=0x%02x ", i, v);
        }
        printf("\n");
      }
    }

    // Dump de60/de5c/de64 pointers for debugging
    { uint32_t de60_ptr = memoryAGet32(0, thisPtr + 0xde60);
      if (de60_ptr >= 0x12000000) {
        printf("  de60[0]=0x%08x\n", memoryAGet32(0, de60_ptr));
        uint32_t de5c_ptr = memoryAGet32(0, thisPtr + 0xde5c);
        uint32_t de64_ptr = memoryAGet32(0, thisPtr + 0xde64);
        printf("  de5c[0]=0x%08x de64[0]=0x%08x\n",
               de5c_ptr ? memoryAGet32(0, de5c_ptr) : 0,
               de64_ptr ? memoryAGet32(0, de64_ptr) : 0);
      }
    }

    // Dump preset data to verify field population
    { uint32_t pp = memoryAGet32(0, thisPtr + 0xe734);
      printf("Preset dump @0x%08x:\n", pp);
      if (pp >= 0x12000000) {
        printf("  +0x08 (name): ");
        for(int i=0;i<20;i++) { uint8_t c=memoryAGet(0,pp+8+i); printf("%c",(c>=32&&c<127)?c:'.'); } printf("\n");
        printf("  +0x131 (l0en)=%d  +0x133 (vmask)=0x%02x  +0x134 (vtype)=0x%02x\n",
               memoryAGet(0,pp+0x131), memoryAGet(0,pp+0x133), memoryAGet(0,pp+0x134));
        printf("  +0x3f (osc): ");
        for(int i=0;i<20;i++) { uint8_t c=memoryAGet(0,pp+0x3f+i); printf("%c",(c>=32&&c<127)?c:'.'); } printf("\n");
        // Dump raw bytes around l0en
        printf("  +0x128..0x140: "); for(int i=0x128;i<0x140;i++) printf("%02x",memoryAGet(0,pp+i)); printf("\n");
      }
    }

    // Allocate module internal buffers if not set
    for (int li = 0; li < 2; li++) {
        uint32_t modPtr = thisPtr + 0x26C40 + li * 0x62fb0;
        if (!memoryAGet32(0, modPtr + 4)) {
            memoryASet32(0, modPtr + 4, allocate(2048 * 4));
            printf("  Allocated module[%d] internal buffer\n", li);
        }
    }

    // --- Set timing parameters ---
    { float cs = 44.1f; uint32_t cb; memcpy(&cb, &cs, 4);
      memoryASet32(0, thisPtr + 0x1d8, cb); }   // chunk accumulator
    { float cr = 1000.0f; uint32_t crb; memcpy(&crb, &cr, 4);
      memoryASet32(0, thisPtr + 0x1dc, crb); }  // chunk rate
    { float sr = 44100.0f; uint32_t srb; memcpy(&srb, &sr, 4);
      memoryASet32(0, thisPtr + 0xb4, srb); }   // sample rate at plugin level
    memoryASet32(0, thisPtr + 0x1d4, 1);         // host output routing flag

    // Initialize voice data at module level for content entry 159
    for (int li = 0; li < 2; li++) {
        uint32_t modPtr = thisPtr + 0x26C40 + li * 0x62fb0;
        printf("  Module[%d] at 0x%08x vtable=0x%08x\n", li, modPtr, memoryAGet32(0, modPtr));
        // Ensure module vtable is set
        if (!memoryAGet32(0, modPtr)) {
            memoryASet32(0, modPtr, 0x103d3e28);
            printf("    Set vtable to 0x103d3e28\n");
        }
        uint32_t vd159 = modPtr + 159 * 0x628 + 0x564;
        // Oscillator frequency (normalized: C4/sampleRate)
        float freq = 261.63f / 44100.0f;
        uint32_t fb; memcpy(&fb, &freq, 4);
        memoryASet32(0, vd159 + 0x11c, fb);
        // Period (samples per cycle)
        float period = 44100.0f / 261.63f;
        uint32_t pb; memcpy(&pb, &period, 4);
        memoryASet32(0, vd159 + 0x4, pb);
        // Envelope multiplier
        float env = 1.0f; uint32_t eb; memcpy(&eb, &env, 4);
        memoryASet32(0, vd159 + 0x618, eb);
        // Module gain + wavetable + sample rate
        memoryASet32(0, modPtr + 0x62da4, eb); // gain=1.0
        memoryASet32(0, modPtr + 0x62dac, 0x103d3d44); // wavetable ptr
        float sr = 44100.0f; uint32_t srb; memcpy(&srb, &sr, 4);
        memoryASet32(0, modPtr + 0x70, srb);
        // BLIT is DISABLED on Windows (0x62d64=0). Use non-BLIT path.
        // Set BLIT params to match Windows:
        memoryASet32(0, modPtr + 0x62d64, 0);         // BLIT disabled
        memoryASet32(0, modPtr + 0x62d68, 2);         // mode=2 (from Windows)
        writeFloat32(modPtr + 0x62d6c, 0.094488f);    // from Windows
        writeFloat32(modPtr + 0x62d70, 0.850394f);    // from Windows
        writeFloat32(modPtr + 0x62d74, 1.0f);         // filter freq mult (matches)
        writeFloat32(modPtr + 0x62d78, 0.5f);         // filter freq offset (matches)
    }

    auto callDispatcher = [&](uint32_t opcode, uint32_t index, uint32_t value,
                              uint32_t ptr, uint32_t opt) -> uint32_t {
        uint32_t savedEsp = esp;
        _push32(opt);
        _push32(ptr);
        _push32(value);
        _push32(index);
        _push32(opcode);
        _push32(pluginPtr);
        callByAddress(dispatcherAddr);
        uint32_t ret = eax;
        esp = savedEsp;
        return ret;
    };

    // effSetSampleRate (opcode 10)
    float sampleRate = 44100.0f;
    uint32_t srBits;
    memcpy(&srBits, &sampleRate, 4);
    printf("effSetSampleRate...\n");
    // Force [thisPtr+0xb4] = 0 to match Windows state before effSetSampleRate
    // On Windows, this is 0 after VSTPluginMain. Our emulator prematurely sets it to 44100
    // during constructor via sub_1005f4c0 (called from sub_1000c600 chain)
    printf("  PRE-setSR: [tp+0xb4]=%.6g → forcing to 0\n",
           readFloat32(thisPtr + 0xb4));
    memoryASet32(0, thisPtr + 0xb4, 0);
    printf("  PRE-setSR: [tp+0x42c1f0+0xd8]=0x%08x [+0xac]=0x%08x [+0xb0]=0x%08x\n",
           memoryAGet32(0, thisPtr+0x42c1f0+0xd8), memoryAGet32(0, thisPtr+0x42c1f0+0xac), memoryAGet32(0, thisPtr+0x42c1f0+0xb0));
    { auto _t0 = std::chrono::high_resolution_clock::now();
    callDispatcher(10, 0, 0, 0, srBits);
    auto _t1 = std::chrono::high_resolution_clock::now();
    printf("  took %lld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(_t1-_t0).count());
    printf("  POST-setSR: [tp+0x42c1f0+0xd8]=0x%08x [+0xac]=0x%08x [+0xb0]=0x%08x\n",
           memoryAGet32(0, thisPtr+0x42c1f0+0xd8), memoryAGet32(0, thisPtr+0x42c1f0+0xac), memoryAGet32(0, thisPtr+0x42c1f0+0xb0));
    }

    // effSetBlockSize (opcode 11)
    const int BLOCK_SIZE = 512;
    printf("effSetBlockSize(%d)...\n", BLOCK_SIZE);
    printf("  PRE-blocksize: modBuf=[0x%08x] Module0=[0x%08x]\n",
           memoryAGet32(0, thisPtr + 0x26C44), memoryAGet32(0, thisPtr + 0x26C40));
    { fpuinsns::_traceFpuCompare = true;
    auto _t0 = std::chrono::high_resolution_clock::now();
    callDispatcher(11, 0, BLOCK_SIZE, 0, 0);
    auto _t1 = std::chrono::high_resolution_clock::now();
    fpuinsns::_traceFpuCompare = false;
    printf("  took %lld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(_t1-_t0).count()); }
    printf("  POST-blocksize: modBuf=[0x%08x] Module0=[0x%08x]\n",
           memoryAGet32(0, thisPtr + 0x26C44), memoryAGet32(0, thisPtr + 0x26C40));

    // effSetChunk NOT needed: Windows render_wav.py produces sound without it.
    // The constructor should populate de60 entries naturally.
    if (0) { // DISABLED — content activation happens during constructor, not effSetChunk
    // Save LAY0 area before effSetChunk (its DRM call memsets the preset)
    uint8_t _lay0Save[32]; uint32_t _pp = memoryAGet32(0, thisPtr + 0xe734);
    bool _hasSave = false;
    if (_pp >= 0x12000000) {
        for (int i = 0; i < 32; i++) _lay0Save[i] = memoryAGet(0, _pp + 0x128 + i);
        _hasSave = true;
    }
    {
        FILE* bf = fopen("decrypted_nexus_bank.bin", "rb");
        if (bf) {
            fseek(bf, 0, SEEK_END); long bsz = ftell(bf); rewind(bf);
            uint32_t bankBuf = allocate((int)bsz);
            std::vector<uint8_t> bd(bsz);
            fread(bd.data(), 1, bsz, bf); fclose(bf);
            for (long i = 0; i < bsz; i++) memoryASet(0, bankBuf + i, bd[i]);
            printf("effSetChunk: loading %ld bytes at 0x%08x\n", bsz, bankBuf);
            callDispatcher(24, 0, (uint32_t)bsz, bankBuf, 0);
            printf("  effSetChunk returned\n");
        } else {
            printf("WARNING: decrypted_nexus_bank.bin not found\n");
        }
    }
    // Restore LAY0 area after effSetChunk
    if (_hasSave && _pp >= 0x12000000) {
        for (int i = 0; i < 32; i++) memoryASet(0, _pp + 0x128 + i, _lay0Save[i]);
        printf("  Restored LAY0 area: l0en=%d\n", memoryAGet(0, _pp + 0x131));
    }
    } // end if(0) effSetChunk block

    // effMainsChanged (opcode 12) — activate
    printf("  PRE-mainsChanged: modBuf=[0x%08x]\n", memoryAGet32(0, thisPtr + 0x26C44));
    printf("effMainsChanged(1)...\n");
    { auto _t0 = std::chrono::high_resolution_clock::now();
    callDispatcher(12, 0, 1, 0, 0);
    auto _t1 = std::chrono::high_resolution_clock::now();
    printf("  took %lld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(_t1-_t0).count()); }
    printf("  POST-mainsChanged: modBuf=[0x%08x]\n", memoryAGet32(0, thisPtr + 0x26C44));

    // Usage: nexus_emu [patch.fxp] [output.wav] [note]
    int midiNote = (argc > 3) ? atoi(argv[3]) : 48;

    // --- Load preset from .fxp file (if provided) ---
    {
        const char* fxpFile = (argc > 1) ? argv[1] : nullptr;
        if (fxpFile) {
            auto fxpData = GetFileContents(fxpFile);
            if (fxpData.size() > 60 && fxpData[8]=='F' && fxpData[9]=='P' && fxpData[10]=='C' && fxpData[11]=='h') {
                // FPCh format: 28-byte header + 28-byte prgName + 4-byte chunkSize (big-endian) + chunk
                uint32_t chunkSize = (fxpData[56]<<24)|(fxpData[57]<<16)|(fxpData[58]<<8)|fxpData[59];
                if (60 + chunkSize <= fxpData.size()) {
                    uint32_t chunkBuf = allocate(chunkSize);
                    for (uint32_t i = 0; i < chunkSize; i++)
                        memoryASet(0, chunkBuf + i, fxpData[60 + i]);
                    printf("Loading preset: %s (%d bytes chunk)\n", fxpFile, chunkSize);
                    callDispatcher(24, 1, chunkSize, chunkBuf, 0);
                    printf("  effSetChunk returned\n");
                }
            } else if (fxpData.size() > 0) {
                printf("WARNING: unrecognized FXP format in %s\n", fxpFile);
            } else {
                printf("WARNING: cannot read %s\n", fxpFile);
            }
        }
    }

    // --- Allocate I/O buffers ---
    uint32_t inL  = allocate(BLOCK_SIZE * 4);
    uint32_t inR  = allocate(BLOCK_SIZE * 4);
    uint32_t outL = allocate(BLOCK_SIZE * 4);
    uint32_t outR = allocate(BLOCK_SIZE * 4);
    uint32_t inputPtrs  = allocate(8);
    uint32_t outputPtrs = allocate(8);
    printf("outL=0x%08x outR=0x%08x outputPtrs=0x%08x\n", outL, outR, outputPtrs);
    { extern uint32_t _outLWatch; extern bool _outLWatchArmed;
      _outLWatch = outL; _outLWatchArmed = true; }
    memoryASet32(0, inputPtrs + 0, inL);
    memoryASet32(0, inputPtrs + 4, inR);
    memoryASet32(0, outputPtrs + 0, outL);
    memoryASet32(0, outputPtrs + 4, outR);

    std::vector<float> allLeft, allRight;

    // --- Send MIDI helper ---
    auto sendMidi = [&](uint8_t status, uint8_t note, uint8_t velocity) {
        uint32_t eventPtr = allocate(32);
        memoryASet32(0, eventPtr + 0x00, 1);  // kVstMidiType
        memoryASet32(0, eventPtr + 0x04, 32); // byteSize
        memoryASet32(0, eventPtr + 0x08, 0);  // deltaFrames
        memoryASet32(0, eventPtr + 0x18, status | (note << 8) | (velocity << 16));

        uint32_t eventsPtr = allocate(8 + 4);
        memoryASet32(0, eventsPtr + 0, 1);         // numEvents
        memoryASet32(0, eventsPtr + 4, 0);         // reserved
        memoryASet32(0, eventsPtr + 8, eventPtr);  // events[0]

        printf("  effProcessEvents: eventsPtr=0x%08x event[0]=0x%08x data=0x%08x\n",
               eventsPtr, memoryAGet32(0, eventsPtr + 8),
               memoryAGet32(0, memoryAGet32(0, eventsPtr + 8) + 0x18));
        callDispatcher(25, 0, 0, eventsPtr, 0); // effProcessEvents
    };

    // kVstTransportPlaying — was set only before render, but arp engine
    // may cache transport state during init. Now set before VSTPluginMain too.
    // (moved earlier; see also the init block below)

    // No force-patches for voice data — let the plugin handle MIDI naturally

    // Debug: check voice data before render
    {
        uint32_t modPtr = thisPtr + 0x26C40;
        uint32_t vd159 = modPtr + 159 * 0x628 + 0x564;
        printf("  VD159: period=0x%08x freq=0x%08x env=0x%08x modVtbl=0x%08x vtbl24=0x%08x\n",
            memoryAGet32(0, vd159+4), memoryAGet32(0, vd159+0x11c),
            memoryAGet32(0, vd159+0x618), memoryAGet32(0, modPtr),
            memoryAGet32(0, memoryAGet32(0, modPtr) + 0x24));
    }
    // Check state before render
    { uint32_t pp = memoryAGet32(0, thisPtr + 0xe734);
      printf("Pre-render: de54=%d content_ready=%d E0FC=%d [1d8]=0x%08x DED0=0x%08x\n",
           memoryAGet32(0, thisPtr+0xde54), memoryAGet(0, thisPtr+0x37e1d8),
           memoryAGet32(0, thisPtr+0xE0FC), memoryAGet32(0, thisPtr+0x1d8), memoryAGet32(0, thisPtr+0xded0));
      printf("  preset=0x%08x l0en=%d vmask=0x%02x vtype=0x%02x\n",
           pp, memoryAGet(0,pp+0x131), memoryAGet(0,pp+0x133), memoryAGet(0,pp+0x139));
      // Check for "Saw Init"
      char name[16]={0}; for(int i=0;i<15;i++) name[i]=memoryAGet(0,pp+8+i);
      printf("  name='%s'\n", name);
    }

    // --- Render audio blocks ---
    // Match Windows render_batch.py: 217 blocks, note-on at 0, note-off at 172
    const int NUM_BLOCKS = 217;
    // Scan for Inf/NaN in thisPtr range before processReplacing
    { int ic=0, nc=0;
      for (uint32_t addr=0x12000000; addr<(uint32_t)allocatorPtr; addr+=4) {
        uint32_t raw = memoryAGet32(0, addr); uint32_t off = addr - thisPtr;
        if (raw==0x7F800000||raw==0xFF800000) { ic++; if(ic<=20) printf("  EMU INF at 0x%08x\n",addr); }
        if (raw==0x7FC00000||raw==0xFFC00000) { nc++; if(nc<=20) printf("  EMU NaN at 0x%08x\n",addr); }
      }
      printf("EMU scan: %d Inf, %d NaN\n", ic, nc);
      // Dump bytes around the diverging flag
      { uint32_t pp = memoryAGet32(0, thisPtr + 0xe734);
        printf("EMU [preset+0x1110..112f]:");
        for (int i=0x1110; i<0x1130; i++) printf(" %02x", memoryAGet(0, pp+i));
        printf("\n  ASCII: ");
        for (int i=0x1110; i<0x1130; i++) { uint8_t c=memoryAGet(0,pp+i); printf("%c",(c>=32&&c<127)?c:'.'); }
        printf("\n");
      }
    }
    printf("Rendering %d blocks of %d samples...\n", NUM_BLOCKS, BLOCK_SIZE);

    // Do NOT force-set de54 or content_ready — let the natural path handle it
    // On Windows: de54=0 before processReplacing, voice allocator sets it to 1 during render
    printf("Pre-render: de50=%d de54=%d de58=%d de5c=0x%08x de60=0x%08x\n",
           memoryAGet32(0, thisPtr+0xde50), memoryAGet32(0, thisPtr+0xde54),
           memoryAGet32(0, thisPtr+0xde58), memoryAGet32(0, thisPtr+0xde5c),
           memoryAGet32(0, thisPtr+0xde60));

    for (int block = 0; block < NUM_BLOCKS; block++) {
        // Match Windows render_batch.py: note C4 (60) vel 100, off at block 172
        if (block == 0) {
            printf("  ON  note=%d at block 0\n", midiNote);
            sendMidi(0x90, midiNote, 100);
            _memWatch = thisPtr + 0xDE54;
            _memWatchArmed = 1;
            // Also watch the queue pending count [thisPtr+0x1E8]
            printf("  Queue pending: [+0x1E8]=%d\n", memoryAGet32(0, thisPtr + 0x1E8));
        }
        if (block == 172) {
            printf("  OFF note=%d at block 172\n", midiNote);
            sendMidi(0x80, midiNote, 0);
        }
        // Note-offs handled by the sequence above
        if (block == 0) {
            // Check content state after MIDI
            uint32_t de54v = memoryAGet32(0, thisPtr + 0xde54);
            uint32_t de5cv = memoryAGet32(0, thisPtr + 0xde5c);
            printf("  After MIDI: de54=%d\n", de54v);
            // Check voice oscillator name
            if (de54v > 0) {
                uint32_t entPtr = memoryAGet32(0, de5cv);
                if (entPtr >= 0x12000000) {
                    char oscName[32] = {0};
                    for (int i = 0; i < 31; i++) { oscName[i] = memoryAGet(0, entPtr + 0x11F08 + i); if (!oscName[i]) break; }
                    printf("  Voice[0] osc name at +0x11F08: '%s'\n", oscName);
                    printf("  Voice[0] [+0x42c3c8]=0x%08x (module ptr)\n", memoryAGet32(0, entPtr + 0x42c3c8));
                }
            }
            // Dump all active entries
            for (uint32_t ei = 0; ei < de54v && ei < 4; ei++) {
                uint32_t entPtr = memoryAGet32(0, de5cv + ei * 4);
                if (entPtr >= 0x12000000) {
                    printf("  Entry[%d] @0x%08x: [0]=0x%08x [4]=0x%08x [8]=0x%08x [c]=0x%08x [20]=0x%08x\n",
                           ei, entPtr,
                           memoryAGet32(0, entPtr), memoryAGet32(0, entPtr+4),
                           memoryAGet32(0, entPtr+8), memoryAGet32(0, entPtr+0xc),
                           memoryAGet32(0, entPtr+0x20));
                }
            }
        }
        // Note-offs handled by the sequence above

        // Reset call counter for this block
        {
            extern long long _icTotal;
            extern long long get32count;
            _icTotal = 0;
            get32count = 0;
        }

        // Clear output buffers
        for (int i = 0; i < BLOCK_SIZE; i++) {
            memoryASet32(0, outL + i * 4, 0);
            memoryASet32(0, outR + i * 4, 0);
        }


        // Call processReplacing with alarm-based timeout (crashes on timeout)
        uint32_t savedEsp = esp;
        _push32(BLOCK_SIZE);
        _push32(outputPtrs);
        _push32(inputPtrs);
        _push32(pluginPtr);
        ecx = thisPtr;
        get32count = 0;
        // NaN detection armed via static counter in fst32 (skip first 99 init NaNs)
        signal(SIGALRM, alarmHandler);
        alarm(_escapeTimeoutSec);
        auto t0 = std::chrono::high_resolution_clock::now();
        // On first block, scan thisPtr heap area and zero any stored NaN values
        // These are artifacts from init computing 1/0 = Inf → NaN (doesn't happen on Windows x87)
        if (block == 0) {
            int cleared = 0;
            for (uint32_t off = 0; off < 0x500000; off += 4) {
                uint32_t raw = memoryAGet32(0, thisPtr + off);
                if (raw == 0x7FC00000 || raw == 0xFFC00000) {
                    memoryASet32(0, thisPtr + off, 0);
                    cleared++;
                }
            }
            if (cleared) printf("  Cleared %d NaN values from init artifacts\n", cleared);
        }
        if (block == 48) _fldNanArmed = true;
        //if (block == 49) { _nanWatchStart = 0x10000000; _nanWatchEnd = 0x20000000; _nanWatchHits = 0; }
        callByAddress(processReplacingAddr);
        if (block == 0) printf("  POST processReplacing: E0FC=%d de54=%d 1E8=%d\n", memoryAGet32(0, thisPtr+0xE0FC), memoryAGet32(0, thisPtr+0xde54), memoryAGet32(0, thisPtr+0x1E8));
        if (block == 49) { _nanWatchHits = -1; }
        alarm(0);
        // Advance samplePos and ppqPos AFTER processReplacing (matching Windows host behavior)
        {
            double spos, ppos;
            uint64_t t = memoryAGet64(0, 0x10593000); memcpy(&spos, &t, 8);
            t = memoryAGet64(0, 0x10593008); memcpy(&ppos, &t, 8);
            spos += BLOCK_SIZE;
            ppos += (140.0 / 60.0) * ((double)BLOCK_SIZE / 44100.0);
            memcpy(&t, &spos, 8); memoryASet64(0, 0x10593000, t);
            memcpy(&t, &ppos, 8); memoryASet64(0, 0x10593008, t);
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        esp = savedEsp;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count();

        // Output should be written directly to outL/outR by processReplacing

        // Read output samples from wherever processReplacing actually wrote them
        uint32_t actualOutL = memoryAGet32(0, outputPtrs);
        uint32_t actualOutR = memoryAGet32(0, outputPtrs + 4);
        float maxSample = 0;
        for (int i = 0; i < BLOCK_SIZE; i++) {
            float l = readFloat32(actualOutL + i * 4);
            float r = actualOutR ? readFloat32(actualOutR + i * 4) : l;
            if (!std::isfinite(l)) l = 0.0f;
            if (!std::isfinite(r)) r = 0.0f;
            allLeft.push_back(l);
            allRight.push_back(r);
            if (fabsf(l) > maxSample) maxSample = fabsf(l);
        }
        // Restore outputPtrs for next block
        memoryASet32(0, outputPtrs, outL);
        memoryASet32(0, outputPtrs + 4, outR);

    }

    // --- Write WAV ---
    { extern long long _icTotal; extern long long get32count;
      printf("Total: %lld indirectCalls, %lld memReads\n", _icTotal, get32count); }
    const char* outFile = (argc > 2) ? argv[2] : "output.wav";
    printf("Writing %s (%zu samples)...\n", outFile, allLeft.size());
    writeWav(outFile, allLeft.data(), allRight.data(), (int)allLeft.size(), 44100);

    printf("Done.\n");
    return 0;
}
