#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <cmath>
#include <string>

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

uint32_t memoryAGet32(int s, int o);
void memoryASet32(int s, int o, uint32_t v);
void memoryASet(int s, int o, uint8_t v);
int allocate(int size);
namespace fpuinsns {
float fromFp32(uint32_t v);
}

void loadOverlay(const char* image, int base) {
    std::string path = std::string(appRootPath) + image;
    auto data = GetFileContents(path);
    if (data.empty()) {
        fprintf(stderr, "loadOverlay failed: %s\n", path.c_str());
        return;
    }
    for (size_t i = 0; i < data.size(); i++)
        memoryASet(0, base + i, data[i]);
    printf("Loaded %s at 0x%08x (%zu bytes)\n", image, base, data.size());
}

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
extern uint32_t eax, ecx;
void push32(uint32_t);

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

// --- Main ---
int main(int argc, char* argv[]) {
    printf("Nexus C++ emulator starting...\n");
    init();

    // Load SYNSOEMU DRM engine overlays
    loadOverlay("SYNSOEMU_rdata.bin", 0x11007000);
    loadOverlay("SYNSOEMU_data.bin", 0x110a6000);

    // Set ContentPath string
    const char* contentPath = "C:\\Nexus\\installer\\Nexus Content\\";
    for (int i = 0; contentPath[i]; i++)
        memoryASet(0, 0x1057f420 + i, contentPath[i]);
    memoryASet(0, 0x1057f420 + strlen(contentPath), 0);

    // --- Run _initterm global constructors ---
    // The real DLL runs these 75 constructors during DllMain via CRT _initterm.
    // They initialize global objects (linked lists, vtables, etc.) that the main
    // constructor depends on. Without them, the constructor hangs in list walks.
    {
        // _initterm table: 0x100e62ec - 0x100e6418 (75 function pointers)
        printf("Running _initterm global constructors...\n");
        for (uint32_t slot = 0x100e62ec; slot < 0x100e6418; slot += 4) {
            callByAddress(memoryAGet32(0, slot));
        }
    }
    // --- Call sub_10015070 (VSTPluginMain init) directly ---
    extern void sub_10015070();

    // Check if rdata vtable is intact before constructor
    printf("Calling sub_10015070...\n");
    push32(0x77778888);
    sub_10015070();

    uint32_t pluginPtr = eax + 0x20; // sub_10015070 returns thisPtr
    assert(memoryAGet32(0, pluginPtr + 4) == 0x1001b3a0);
    uint32_t thisPtr = memoryAGet32(0, pluginPtr + 0x40);
    uint32_t dispatcherAddr = memoryAGet32(0, pluginPtr + 0x04);
    uint32_t processReplacingAddr = memoryAGet32(0, pluginPtr + 0x50);

    auto callDispatcher = [&](uint32_t opcode, uint32_t index, uint32_t value,
                              uint32_t ptr, uint32_t opt) -> uint32_t {
        push32(opt);
        push32(ptr);
        push32(value);
        push32(index);
        push32(opcode);
        push32(pluginPtr);
        callByAddress(dispatcherAddr);
        return eax;
    };

    // effSetSampleRate (opcode 10)
    float sampleRate = 44100.0f;
    uint32_t srBits;
    memcpy(&srBits, &sampleRate, 4);
    callDispatcher(10, 0, 0, 0, srBits);

    // effSetBlockSize (opcode 11)
    const int BLOCK_SIZE = 512;
    callDispatcher(11, 0, BLOCK_SIZE, 0, 0);

    // effMainsChanged (opcode 12) — activate
    callDispatcher(12, 0, 1, 0, 0);

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
        callDispatcher(25, 0, 0, eventsPtr, 0); // effProcessEvents
    };

    // --- Render audio blocks ---
    const int NUM_BLOCKS = 400;
    printf("Rendering %d blocks of %d samples...\n", NUM_BLOCKS, BLOCK_SIZE);

    for (int block = 0; block < NUM_BLOCKS; block++) {
        if (block == 0) {
            printf("  ON  note=%d at block 0\n", midiNote);
            sendMidi(0x90, midiNote, 100);
        }
        if (block == 100) {
//            sendMidi(0x80, midiNote, 0);
            sendMidi(0x90, midiNote+12, 100);
        }
        if (block == 200) {
//            sendMidi(0x80, midiNote+12, 0);
            sendMidi(0x90, midiNote+4, 100);
        }
        if (block == 350) {
            printf("  OFF note=%d at block 172\n", midiNote);
            sendMidi(0x80, midiNote+4, 0);
        }

        // Call processReplacing with alarm-based timeout (crashes on timeout)
        push32(BLOCK_SIZE);
        push32(outputPtrs);
        push32(inputPtrs);
        push32(pluginPtr);
        ecx = thisPtr;
        callByAddress(processReplacingAddr);

        // Read output samples from wherever processReplacing actually wrote them
        uint32_t actualOutL = memoryAGet32(0, outputPtrs);
        uint32_t actualOutR = memoryAGet32(0, outputPtrs + 4);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            allLeft.push_back(fpuinsns::fromFp32(memoryAGet32(0, actualOutL + i * 4)));
            allRight.push_back(fpuinsns::fromFp32(memoryAGet32(0, actualOutR + i * 4)));
        }
    }

    // --- Write WAV ---
    const char* outFile = (argc > 2) ? argv[2] : "output.wav";
    printf("Writing %s (%zu samples)...\n", outFile, allLeft.size());
    writeWav(outFile, allLeft.data(), allRight.data(), (int)allLeft.size(), 44100);

    printf("Done.\n");
    return 0;
}
