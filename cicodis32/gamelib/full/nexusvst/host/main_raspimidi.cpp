#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <atomic>
#include <algorithm>
#include <cstring>
#include <csignal>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <alsa/asoundlib.h>

#include "mmap.h"

const char* appRootPath = "res/";

extern int allocatorPtr;

#ifdef RASPI
static inline void memoryASet(int s, int o, uint8_t v) {
    *((uint8_t*)o) = v;
}
static inline void memoryASet16(int s, int o, uint16_t v) {
    *((uint16_t*)o) = v;
}
static inline void memoryASet32(int s, int o, uint32_t v) {
    *((uint32_t*)o) = v;
}
static inline void memoryASet64(int s, int o, uint64_t v) {
    *((uint64_t*)o) = v;
}
static inline uint8_t memoryAGet(int s, int o) {
    return *((uint8_t*)o);
}
static inline uint16_t memoryAGet16(int s, int o) {
    return *((uint16_t*)o);
}
static inline uint32_t memoryAGet32(int s, int o) {
    return *((uint32_t*)o);
}
static inline uint64_t memoryAGet64(int s, int o) {
    return *((uint64_t*)o);
}
#define memoryFGet32(s, o) *((float*)(o))
#define memoryFGet64(s, o) *((double*)(o))
#else
uint32_t memoryAGet32(int s, int o);
void memoryASet32(int s, int o, uint32_t v);
uint64_t memoryAGet64(int s, int o);
void memoryASet64(int s, int o, uint64_t v);
void memoryASet(int s, int o, uint8_t v);
float memoryFGet32(int s, int o);
#endif


int allocate(int size);

namespace fpuinsns {
//float fromFp32(uint32_t v);
}

extern uint32_t eax, ecx, esp;
extern uint16_t ds, ss, es, gs, cs, fs;
void push32(uint32_t);

// -----------------------------------------------------------------------------
// Audio config
// -----------------------------------------------------------------------------

static constexpr int SAMPLE_RATE = 44100;
static constexpr int BLOCK_SIZE  = 512;
static constexpr int CHANNELS    = 2;

// 512 / 44100 = 11.609 ms of audio per block.
static constexpr double BLOCK_AUDIO_MS =
    1000.0 * double(BLOCK_SIZE) / double(SAMPLE_RATE);

struct AudioBlock {
    std::vector<int16_t> pcm; // interleaved stereo
};

static std::deque<AudioBlock> audioQueue;
static std::mutex audioMutex;
static std::condition_variable audioCv;
static std::atomic<bool> renderingDone{false};
static std::atomic<int> underrunCount{0};

static size_t maxQueueSeen = 0;
static constexpr size_t MAX_QUEUE_BLOCKS = 4;

static inline int16_t floatToS16(float v) {
    if (v > 1.0f) v = 1.0f;
    if (v < -1.0f) v = -1.0f;
    return (int16_t)(v * 32767.0f);
}

__attribute__((no_profile_instrument_function))
void playbackThreadFunc() {
#ifdef SILENT

    // Consume queue without ALSA playback.
    // Lets us benchmark rendering speed only.

    while (true) {
        AudioBlock block;

        {
            std::unique_lock<std::mutex> lock(audioMutex);

            audioCv.wait(lock, [] {
                return !audioQueue.empty() || renderingDone.load();
            });

            if (audioQueue.empty() && renderingDone.load())
                break;

            block = std::move(audioQueue.front());
            audioQueue.pop_front();

            audioCv.notify_all();
        }

        // Intentionally discard audio block.
    }

#else
    snd_pcm_t* pcm = nullptr;

    int err = snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (err < 0) {
        fprintf(stderr, "snd_pcm_open failed: %s\n", snd_strerror(err));
        renderingDone = true;
        audioCv.notify_all();
        return;
    }

    err = snd_pcm_set_params(
        pcm,
        SND_PCM_FORMAT_S16_LE,
        SND_PCM_ACCESS_RW_INTERLEAVED,
        CHANNELS,
        SAMPLE_RATE,
        1,
        50000  // 50 ms latency
    );

    if (err < 0) {
        fprintf(stderr, "snd_pcm_set_params failed: %s\n", snd_strerror(err));
        snd_pcm_close(pcm);
        renderingDone = true;
        audioCv.notify_all();
        return;
    }

    while (true) {
        AudioBlock block;

        {
            std::unique_lock<std::mutex> lock(audioMutex);

            audioCv.wait(lock, [] {
                return !audioQueue.empty() || renderingDone.load();
            });

            if (audioQueue.empty() && renderingDone.load())
                break;

            block = std::move(audioQueue.front());
            audioQueue.pop_front();

            audioCv.notify_all();
        }

        const int16_t* data = block.pcm.data();
        snd_pcm_sframes_t framesLeft = block.pcm.size() / CHANNELS;

        while (framesLeft > 0) {
            snd_pcm_sframes_t written =
                snd_pcm_writei(pcm, data, framesLeft);

            if (written == -EPIPE) {
                underrunCount++;
                fprintf(stderr, "ALSA underrun\n");
                snd_pcm_prepare(pcm);
                continue;
            }

            if (written < 0) {
                written = snd_pcm_recover(pcm, written, 1);

                if (written < 0) {
                    fprintf(stderr,
                            "snd_pcm_writei failed: %s\n",
                            snd_strerror(written));
                    break;
                }

                continue;
            }

            data += written * CHANNELS;
            framesLeft -= written;
        }
    }

    snd_pcm_drain(pcm);
    snd_pcm_close(pcm);
#endif
}

// -----------------------------------------------------------------------------
// audiomaster
// -----------------------------------------------------------------------------

void sub_77778888() {
    uint32_t _amc_op = memoryAGet32(ss, esp + 4);

    switch (_amc_op) {
        case 0:
            eax = 1;
            break;

        case 1:
            eax = 2400;
            break;

        case 6:
            eax = 1;
            break;

        case 7: {
            uint32_t _reqFlags = memoryAGet32(ss, esp + 12);
            (void)_reqFlags;

            static uint32_t _vtiPtr = 0;

            double _samplePos, _ppqPos;

            {
                uint64_t t;

                t = memoryAGet64(ds, 0x10593000);
                memcpy(&_samplePos, &t, 8);

                t = memoryAGet64(ds, 0x10593008);
                memcpy(&_ppqPos, &t, 8);
            }

            if (!_vtiPtr)
                _vtiPtr = allocate(128);

            uint64_t sp64;

            memcpy(&sp64, &_samplePos, 8);
            memoryASet64(ds, _vtiPtr + 0, sp64);

            double sr = 44100.0;
            memcpy(&sp64, &sr, 8);
            memoryASet64(ds, _vtiPtr + 8, sp64);

            memcpy(&sp64, &_ppqPos, 8);
            memoryASet64(ds, _vtiPtr + 24, sp64);

            double bpm = 140.0;
            memcpy(&sp64, &bpm, 8);
            memoryASet64(ds, _vtiPtr + 32, sp64);

            memoryASet32(ds, _vtiPtr + 64, 4);
            memoryASet32(ds, _vtiPtr + 68, 4);

            uint32_t _transportFlag =
                memoryAGet32(ds, 0x10593010);

            memoryASet32(
                ds,
                _vtiPtr + 84,
                _transportFlag |
                (1 << 8) |
                (1 << 9) |
                (1 << 10) |
                (1 << 13)
            );

            eax = _vtiPtr;
            break;
        }

        default:
            eax = 0;
            break;
    }
}

static void DumpPath(const char* p) {
    fprintf(stderr, "path strlen=%zu\n", strlen(p));
    fprintf(stderr, "path escaped='");

    for (const unsigned char* s = (const unsigned char*)p; *s; ++s) {
        if (*s == '\n') fprintf(stderr, "\\n");
        else if (*s == '\r') fprintf(stderr, "\\r");
        else if (*s == '\t') fprintf(stderr, "\\t");
        else if (isprint(*s)) fputc(*s, stderr);
        else fprintf(stderr, "\\x%02X", *s);
    }

    fprintf(stderr, "'\n");
}

std::vector<uint8_t> GetFileContents(const char* fullPath) {
    FILE* f = fopen(fullPath, "rb");

    if (!f) {
        DumpPath(fullPath);
        fprintf(stderr, "GetFileContents - Cannot open: '%s', error: %s\n", fullPath, strerror(errno));
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

void loadOverlay(const char* image, int base) {
    std::string path = std::string(appRootPath) + image;
    auto data = GetFileContents(path.c_str());

    if (data.empty()) {
        fprintf(stderr, "loadOverlay failed: %s\n", path.c_str());
        return;
    }

    for (size_t i = 0; i < data.size(); i++)
        memoryASet(0, base + i, data[i]);

    printf("Loaded %s at 0x%08x (%zu bytes)\n",
           image,
           base,
           data.size());
}

// -----------------------------------------------------------------------------
// External emulator/plugin functions
// -----------------------------------------------------------------------------

void init();
void start();
void VSTPluginMain();
void sub_1001d100();
void sub_10015070();
void sub_1001b3a0();
void sub_10031d10();
void sub_1001b470();
void _initterm();

// -----------------------------------------------------------------------------
// UART MIDI input
// -----------------------------------------------------------------------------

// termios2 allows setting non-standard baud rates (MIDI uses 31250 baud).
// Defined inline to avoid conflicts between <termios.h> and <linux/termios.h>.
struct MidiTermios2 {
    uint32_t c_iflag;
    uint32_t c_oflag;
    uint32_t c_cflag;
    uint32_t c_lflag;
    uint8_t  c_line;
    uint8_t  c_cc[19];
    uint32_t c_ispeed;
    uint32_t c_ospeed;
};
static_assert(sizeof(MidiTermios2) == 44, "termios2 size mismatch");

// ioctl numbers for termios2 on Linux/ARM and x86_64 (struct size = 44 = 0x2C).
static const unsigned long MIDI_TCGETS2 = _IOR('T', 0x2A, MidiTermios2);
static const unsigned long MIDI_TCSETS2 = _IOW('T', 0x2B, MidiTermios2);
static const uint32_t      MIDI_BOTHER  = 010000U; // custom baud rate selector

#ifndef CBAUD
#define CBAUD 010017U
#endif

struct MidiMsg {
    uint8_t status, data1, data2;
};

static std::deque<MidiMsg> midiQueue;
static std::mutex          midiMutex;
static std::atomic<bool>   g_stopped{false};
static int                 g_uartFd = -1;

static void sigintHandler(int) {
    if (g_stopped.exchange(true))
        _exit(1);  // second signal: render thread is stuck, force quit
}

// Returns the number of data bytes that follow a given channel status byte.
static int midiMsgDataLen(uint8_t status) {
    switch (status & 0xF0) {
        case 0x80: case 0x90: case 0xA0:
        case 0xB0: case 0xE0: return 2;
        case 0xC0: case 0xD0: return 1;
        default:              return 0;
    }
}

static void midiReaderThread() {
    const int fd = g_uartFd;  // capture once; main thread may close/nullify later

    uint8_t runStatus = 0;
    int     need      = 0;
    uint8_t data[2]   = {};
    int     pos       = 0;
    bool    inSysex   = false;

    while (!g_stopped.load()) {
        // Use select() with a short timeout so we can check g_stopped
        // periodically without relying on close() to unblock read().
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);
        struct timeval tv = {0, 10000};  // 10 ms
        int ret = select(fd + 1, &rfds, nullptr, nullptr, &tv);
        if (ret < 0) break;   // fd closed or error
        if (ret == 0) continue; // timeout – loop back to check g_stopped

        uint8_t b;
        ssize_t n = read(fd, &b, 1);

        if (n <= 0) break; // fd closed or fatal error

        // Real-time messages (0xF8-0xFF) are single-byte and may appear
        // anywhere in the stream; we don't forward them to the VST.
        if (b >= 0xF8) continue;

        // SysEx framing
        if (b == 0xF0) { inSysex = true;  continue; }
        if (b == 0xF7) { inSysex = false; continue; }
        if (inSysex)   continue;

        // System common (0xF1-0xF6): cancel running status, skip
        if (b >= 0xF1) { runStatus = 0; pos = 0; continue; }

        if (b & 0x80) {
            // New channel status byte
            runStatus = b;
            need      = midiMsgDataLen(b);
            pos       = 0;
        } else {
            // Data byte; running status applies if no new status seen
            if (!runStatus || !need) continue;

            data[pos++] = b;

            if (pos == need) {
                MidiMsg msg;
                msg.status = runStatus;
                msg.data1  = data[0];
                msg.data2  = (need == 2) ? data[1] : 0;

                // MIDI spec: Note On with velocity 0 is equivalent to Note Off.
                // Many keyboards never send 0x80 and use this form instead.
                // Normalise here so the VST always receives an explicit 0x80,
                // avoiding code paths that may only have been tested with 0x80.
                if ((msg.status & 0xF0) == 0x90 && msg.data2 == 0)
                    msg.status = (msg.status & 0x0F) | 0x80;

                { std::lock_guard<std::mutex> lk(midiMutex); midiQueue.push_back(msg); }

                pos = 0; // ready for next message under running status
            }
        }
    }
}

static int openUartMidi(const char* dev) {
    int fd = open(dev, O_RDONLY | O_NOCTTY);
    if (fd < 0) {
        perror("open UART");
        return -1;
    }

    MidiTermios2 t2 {};
    if (ioctl(fd, MIDI_TCGETS2, &t2) < 0) {
        perror("TCGETS2");
        close(fd);
        return -1;
    }

    // Raw mode: no processing, no echo, no signals
    t2.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
                    INLCR  | IGNCR  | ICRNL  | IXON);
    t2.c_oflag &= ~OPOST;
    t2.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);

    // 8N1
    t2.c_cflag &= ~(CSIZE | PARENB | CSTOPB);
    t2.c_cflag |=  CS8 | CREAD | CLOCAL;

    // Custom baud rate 31250 via BOTHER
    t2.c_cflag &= ~CBAUD;
    t2.c_cflag |=  MIDI_BOTHER;
    t2.c_ispeed = 31250;
    t2.c_ospeed = 31250;

    // Blocking read, return as soon as 1 byte is available
    t2.c_cc[VMIN]  = 1;
    t2.c_cc[VTIME] = 0;

    if (ioctl(fd, MIDI_TCSETS2, &t2) < 0) {
        perror("TCSETS2");
        close(fd);
        return -1;
    }

    return fd;
}

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

int main(int argc, char* argv[]) {
    printf("Nexus MIDI streaming starting...\n");

    if (init_mmap())
        return 1;

    init();

    loadOverlay("SYNSOEMU_rdata.bin", 0x11007000);
    loadOverlay("SYNSOEMU_data.bin", 0x110a6000);

    uint32_t allocatorPtrBegin = allocatorPtr;

    const char* contentPath = "C:\\Nexus\\installer\\Nexus Content\\";

    for (int i = 0; contentPath[i]; i++)
        memoryASet(0, 0x1057f420 + i, contentPath[i]);

    memoryASet(0, 0x1057f420 + strlen(contentPath), 0);

    _initterm();

    printf("Calling sub_10015070...\n");

    push32(0x77778888);
    sub_10015070();

    uint32_t pluginPtr = eax + 0x20;

    assert(memoryAGet32(0, pluginPtr + 4) == 0x1001b3a0);

    uint32_t thisPtr = memoryAGet32(0, pluginPtr + 0x40);
    uint32_t dispatcherAddr = memoryAGet32(0, pluginPtr + 0x04);
    uint32_t processReplacingAddr = memoryAGet32(0, pluginPtr + 0x50);

    (void)dispatcherAddr;
    (void)processReplacingAddr;

    auto callDispatcher = [&](uint32_t opcode,
                              uint32_t index,
                              uint32_t value,
                              uint32_t ptr,
                              uint32_t opt) -> uint32_t {
        push32(opt);
        push32(ptr);
        push32(value);
        push32(index);
        push32(opcode);
        push32(pluginPtr);

        sub_1001b3a0();
        esp += 6*4;

        return eax;
    };

    float sampleRate = 44100.0f;
    uint32_t srBits;
    memcpy(&srBits, &sampleRate, 4);

    callDispatcher(10, 0, 0, 0, srBits);
    callDispatcher(11, 0, BLOCK_SIZE, 0, 0);
    callDispatcher(12, 0, 1, 0, 0);

    {
        const char* fxpFile = (argc > 1) ? argv[1] : nullptr;

        if (fxpFile) {
            auto fxpData = GetFileContents(fxpFile);

            if (fxpData.size() > 60 &&
                fxpData[8]  == 'F' &&
                fxpData[9]  == 'P' &&
                fxpData[10] == 'C' &&
                fxpData[11] == 'h') {

                uint32_t chunkSize =
                    (fxpData[56] << 24) |
                    (fxpData[57] << 16) |
                    (fxpData[58] << 8)  |
                    fxpData[59];

                if (60 + chunkSize <= fxpData.size()) {
                    uint32_t chunkBuf = allocate(chunkSize);

                    for (uint32_t i = 0; i < chunkSize; i++)
                        memoryASet(0, chunkBuf + i, fxpData[60 + i]);

                    printf("Loading preset: %s (%u bytes chunk)\n",
                           fxpFile,
                           chunkSize);

                    callDispatcher(24, 1, chunkSize, chunkBuf, 0);

                    printf("effSetChunk returned\n");
                }
            } else if (!fxpData.empty()) {
                printf("WARNING: unrecognized FXP format in '%s'\n",
                       fxpFile);
            } else {
                printf("WARNING: cannot read '%s'\n", fxpFile);
            }
        }
    }

    uint32_t inL  = allocate(BLOCK_SIZE * 4);
    uint32_t inR  = allocate(BLOCK_SIZE * 4);
    uint32_t outL = allocate(BLOCK_SIZE * 4);
    uint32_t outR = allocate(BLOCK_SIZE * 4);

    (void)inL;
    (void)inR;

    uint32_t inputPtrs  = 0;
    uint32_t outputPtrs = allocate(8);

    memoryASet32(0, outputPtrs + 0, outL);
    memoryASet32(0, outputPtrs + 4, outR);

    // Pre-allocate a fixed MIDI event pool so the render loop never calls
    // allocate() per event.  1024 slots is far more than any single block
    // will ever carry; the pool is written in-place and reused every block.
    static constexpr int MIDI_EVENT_SLOTS = 1024;

    // VstEvents header: numEvents(4) + reserved(4) + event-ptr table
    uint32_t midiEventsHdr = allocate(8 + MIDI_EVENT_SLOTS * 4);
    // VstMidiEvent array: 32 bytes each
    uint32_t midiEventPool = allocate(MIDI_EVENT_SLOTS * 32);

    // Pre-fill the pointer table and the invariant fields of every event slot.
    for (int i = 0; i < MIDI_EVENT_SLOTS; i++) {
        memoryASet32(0, midiEventsHdr + 8 + i * 4, midiEventPool + i * 32);
        uint32_t ep = midiEventPool + i * 32;
        memoryASet32(0, ep + 0x00, 1);   // type = kVstMidiType
        memoryASet32(0, ep + 0x04, 32);  // byteSize
        memoryASet32(0, ep + 0x08, 0);   // deltaFrames
    }

    // Send all msgs in one effProcessEvents call using the pre-allocated pool.
    // Calling with an empty list (count=0) is valid and also primes Nexus's
    // internal event pointer before the very first processReplacing call.
    auto dispatchMidi = [&](const std::vector<MidiMsg>& msgs) {
        int count = std::min((int)msgs.size(), MIDI_EVENT_SLOTS);
        memoryASet32(0, midiEventsHdr + 0, count);
        memoryASet32(0, midiEventsHdr + 4, 0);
        for (int i = 0; i < count; i++) {
            memoryASet32(0, midiEventPool + i * 32 + 0x18,
                         msgs[i].status | (msgs[i].data1 << 8) | (msgs[i].data2 << 16));
        }
        callDispatcher(25, 0, 0, midiEventsHdr, 0);
    };

    // Open UART MIDI input; optional second argument overrides the device.
    const char* uartDev = (argc > 2) ? argv[2] : "/dev/serial0";

    g_uartFd = openUartMidi(uartDev);
    if (g_uartFd < 0)
        return 1;

    printf("MIDI input: %s at 31250 baud\n", uartDev);

    signal(SIGINT,  sigintHandler);
    signal(SIGTERM, sigintHandler);

    std::thread midiThread(midiReaderThread);
    std::thread playbackThread(playbackThreadFunc);

    printf("Streaming audio (Ctrl+C to stop)...\n");
    printf("Each block is %.3f ms of audio\n", BLOCK_AUDIO_MS);

    double totalRenderMs = 0.0;
    double minRenderMs   = 1e30;
    double maxRenderMs   = 0.0;
    int    slowBlocks    = 0;
    int    blockIndex    = 0;

    // Prime the VST: effProcessEvents must be called at least once before the
    // first processReplacing so Nexus's internal event-list pointer is valid.
    // We do it once here with numEvents=0 using the pre-allocated header.
    memoryASet32(0, midiEventsHdr + 0, 0);  // numEvents = 0
    memoryASet32(0, midiEventsHdr + 4, 0);  // reserved
    callDispatcher(25, 0, 0, midiEventsHdr, 0);

    auto totalStart = std::chrono::steady_clock::now();
    int totalEvents = 0;

    while (!g_stopped.load()) {
        bool first = true;
        MidiMsg firstMsg;

        // Collect pending MIDI messages (lock held only during drain).
        std::vector<MidiMsg> pending;
        {
            std::lock_guard<std::mutex> lk(midiMutex);
            while (!midiQueue.empty()) {
                totalEvents++;
                if (first) {
                  first = false;
                  firstMsg = midiQueue.front();
                }
                pending.push_back(midiQueue.front());
                midiQueue.pop_front();
            }
        }
        if (!first) {
          printf("event: %02x %02x %02x\n", firstMsg.status, firstMsg.data1, firstMsg.data2);
        }
        // Only call effProcessEvents when there are actual MIDI events.
        // Calling callDispatcher every block even with numEvents=0 causes
        // accumulated esp drift in the emulated stack and crashes after
        // many notes.  nexus_stream.cpp only calls it when events exist.
        if (!pending.empty())
            dispatchMidi(pending);

        auto renderStart = std::chrono::steady_clock::now();

        push32(BLOCK_SIZE);
        push32(outputPtrs);
        push32(inputPtrs);
        push32(pluginPtr);

        ecx = thisPtr;

        sub_1001b470();
        esp += 4*4;

        auto renderEnd = std::chrono::steady_clock::now();

        double renderMs =
            std::chrono::duration<double, std::milli>(
                renderEnd - renderStart
            ).count();

        if (blockIndex > 0) {
            totalRenderMs += renderMs;
            minRenderMs = std::min(minRenderMs, renderMs);
            maxRenderMs = std::max(maxRenderMs, renderMs);
            if (renderMs > BLOCK_AUDIO_MS)
                slowBlocks++;
        }

        uint32_t actualOutL = memoryAGet32(0, outputPtrs);
        uint32_t actualOutR = memoryAGet32(0, outputPtrs + 4);

        AudioBlock audioBlock;
        audioBlock.pcm.resize(BLOCK_SIZE * CHANNELS);

        for (int i = 0; i < BLOCK_SIZE; i++) {
            float l = memoryFGet32(0, actualOutL + i * 4);
            float r = memoryFGet32(0, actualOutR + i * 4);
            audioBlock.pcm[i * 2 + 0] = floatToS16(l);
            audioBlock.pcm[i * 2 + 1] = floatToS16(r);
        }

        {
            std::unique_lock<std::mutex> lock(audioMutex);

            audioCv.wait(lock, [] {
                return audioQueue.size() < MAX_QUEUE_BLOCKS || g_stopped.load();
            });

            if (g_stopped.load())
                break;

            audioQueue.push_back(std::move(audioBlock));
            maxQueueSeen = std::max(maxQueueSeen, audioQueue.size());
        }

        audioCv.notify_all();

        if ((blockIndex % 50) == 0) {
            double headroomMs = BLOCK_AUDIO_MS - renderMs;
            double realtimeFactor = BLOCK_AUDIO_MS / renderMs;

            printf(
                "block %6d: render %.3f ms, audio %.3f ms, "
                "headroom %.3f ms, %.2fx realtime, queue %zu, events %d, ptr %x, esp %x\n",
                blockIndex,
                renderMs,
                BLOCK_AUDIO_MS,
                headroomMs,
                realtimeFactor,
                audioQueue.size(),
                totalEvents,
                allocatorPtr, esp
            );
        }

        blockIndex++;
    }

    auto totalEnd = std::chrono::steady_clock::now();

    // Closing g_uartFd unblocks the blocking read() in midiReaderThread.
    close(g_uartFd);
    g_uartFd = -1;
    midiThread.join();

    renderingDone = true;
    audioCv.notify_all();
    playbackThread.join();

    double wallMs =
        std::chrono::duration<double, std::milli>(
            totalEnd - totalStart
        ).count();

    int measuredBlocks = blockIndex - 1; // skip first block (warmup)
    double audioMs     = blockIndex * BLOCK_AUDIO_MS;
    double avgRenderMs = (measuredBlocks > 0)
                         ? totalRenderMs / double(measuredBlocks) : 0.0;
    double avgHeadroomMs = BLOCK_AUDIO_MS - avgRenderMs;
    double realtimeFactor = (totalRenderMs > 0)
                            ? audioMs / totalRenderMs : 0.0;

    uint32_t allocatorPtrEnd = allocatorPtr;

    printf("\n");
    printf("========================================\n");
    printf("Realtime statistics\n");
    printf("========================================\n");
    printf("Sample rate:             %d Hz\n", SAMPLE_RATE);
    printf("Block size:              %d samples\n", BLOCK_SIZE);
    printf("Audio per block:         %.3f ms\n", BLOCK_AUDIO_MS);
    printf("Blocks rendered:         %d\n", blockIndex);
    printf("Total audio generated:   %.3f ms\n", audioMs);
    printf("Total render CPU time:   %.3f ms\n", totalRenderMs);
    printf("Wall render loop time:   %.3f ms\n", wallMs);
    printf("Average render/block:    %.3f ms\n", avgRenderMs);
    printf("Minimum render/block:    %.3f ms\n", minRenderMs);
    printf("Maximum render/block:    %.3f ms\n", maxRenderMs);
    printf("Average headroom/block:  %.3f ms\n", avgHeadroomMs);
    printf("Realtime factor:         %.2fx\n", realtimeFactor);
    printf("Slow blocks:             %d / %d\n", slowBlocks, blockIndex);
    printf("ALSA underruns:          %d\n", underrunCount.load());
    printf("Max queue depth:         %zu blocks\n", maxQueueSeen);
    printf("RAM consumed:            %u MB\n",
           (allocatorPtrEnd - allocatorPtrBegin) / 1024 / 1024);

    if (realtimeFactor >= 1.0 && underrunCount.load() == 0) {
        printf("Result: fast enough for realtime streaming.\n");
    } else if (realtimeFactor >= 1.0) {
        printf("Result: average speed is OK, but underruns occurred.\n");
        printf("Try increasing ALSA latency or queue depth.\n");
    } else {
        printf("Result: not fast enough for realtime streaming.\n");
        printf("Try larger BLOCK_SIZE, optimization, or fewer voices/effects.\n");
    }

    printf("Done.\n");

    return 0;
}
