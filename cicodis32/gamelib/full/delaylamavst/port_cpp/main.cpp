#include "delaylama_dsp.h"
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

// ─────────────────────────────────────────────────────────
// WAV writer
// ─────────────────────────────────────────────────────────
static void write_u16le(FILE* f, uint16_t v) { fputc(v & 0xff, f); fputc(v >> 8, f); }
static void write_u32le(FILE* f, uint32_t v) {
    fputc(v & 0xff, f); fputc((v>>8)&0xff, f);
    fputc((v>>16)&0xff, f); fputc((v>>24)&0xff, f);
}

static bool write_wav(const char* path,
                      const float* left, const float* right,
                      int num_samples, int sample_rate)
{
    FILE* f = fopen(path, "wb");
    if (!f) { perror(path); return false; }

    const int    channels       = 2;
    const int    bits           = 16;
    const int    bytes_per_samp = channels * bits / 8;   // 4
    const uint32_t data_size   = (uint32_t)(num_samples * bytes_per_samp);

    // RIFF header
    fwrite("RIFF", 1, 4, f);
    write_u32le(f, 36 + data_size);
    fwrite("WAVE", 1, 4, f);

    // fmt chunk
    fwrite("fmt ", 1, 4, f);
    write_u32le(f, 16);                                 // chunk size
    write_u16le(f, 1);                                  // PCM
    write_u16le(f, (uint16_t)channels);
    write_u32le(f, (uint32_t)sample_rate);
    write_u32le(f, (uint32_t)(sample_rate * bytes_per_samp)); // byte rate
    write_u16le(f, (uint16_t)bytes_per_samp);           // block align
    write_u16le(f, (uint16_t)bits);

    // data chunk
    fwrite("data", 1, 4, f);
    write_u32le(f, data_size);

    for (int i = 0; i < num_samples; i++) {
        float l = std::max(-1.f, std::min(1.f, left[i]));
        float r = std::max(-1.f, std::min(1.f, right[i]));
        int16_t ls = (int16_t)(int)(l * 32767.f);   // truncation, matches Python int()
        int16_t rs = (int16_t)(int)(r * 32767.f);
        write_u16le(f, (uint16_t)ls);
        write_u16le(f, (uint16_t)rs);
    }

    fclose(f);
    return true;
}

// ─────────────────────────────────────────────────────────
// Main
// ─────────────────────────────────────────────────────────
int main(int argc, char** argv)
{
    const char* out_path    = (argc > 1) ? argv[1] : "output_cpp.wav";
    const int   SAMPLE_RATE = 44100;
    const int   BLOCK_SIZE  = 2048;   // matches ground truth (delaylama_win_2048.wav)

    // Init DSP
    DelayLamaDSP dsp;
    dsp.init((float)SAMPLE_RATE);

    // Parameters — match DLL default preset 0 (confirmed from JS emulator state dump):
    //   portamento=0.5, vowel_sel=0.5, vowel_depth=0.5, feedback=0.8
    dsp.setParameter(0, 0.5f);   // volume
    dsp.setParameter(1, 0.5f);   // vowel_sel
    dsp.setParameter(2, 0.5f);   // portamento (DLL default [esi+0xb0]=0.5)
    dsp.setParameter(3, 0.5f);   // vowel_depth (DLL default [esi+0xc4]=0.5)
    dsp.setParameter(4, 0.8f);   // feedback (DLL default [esi+0xbc]=0.8)

    // Accumulate all audio into vectors
    std::vector<float> all_left, all_right;
    all_left.reserve(SAMPLE_RATE * 5);
    all_right.reserve(SAMPLE_RATE * 5);

    std::vector<float> buf_L(BLOCK_SIZE), buf_R(BLOCK_SIZE);

    auto render_block = [&]() {
        dsp.process(buf_L.data(), buf_R.data(), BLOCK_SIZE);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            all_left.push_back(buf_L[i]);
            all_right.push_back(buf_R[i]);
        }
    };

    // Block counts — match ground truth: int() truncation
    int blocks_on  = (int)(3.0f * SAMPLE_RATE / BLOCK_SIZE);  // 64
    int blocks_rel = (int)(1.0f * SAMPLE_RATE / BLOCK_SIZE);  // 21

    // Note-on: MIDI 60 (middle C), velocity 100
    printf("Note on: MIDI 60, velocity 100\n");
    dsp.noteOn(60, 100);

    // Render note-on duration
    printf("Rendering %d blocks (%d samples) sustain...\n", blocks_on, blocks_on * BLOCK_SIZE);
    for (int b = 0; b < blocks_on; b++)
        render_block();

    printf("First 20 samples (left):\n");
    for (int i = 0; i < 20; i++)
        printf("  [%2d] %+.8f\n", i, all_left[i]);

    // Note-off
    printf("Note off\n");
    dsp.noteOff(60);

    // Render release
    printf("Rendering %d blocks (%d samples) tail...\n", blocks_rel, blocks_rel * BLOCK_SIZE);
    for (int b = 0; b < blocks_rel; b++)
        render_block();

    int total = (int)all_left.size();

    // Compute amplitude statistics
    float max_amp = 0.f;
    for (int i = 0; i < total; i++)
        max_amp = std::max(max_amp, std::abs(all_left[i]));
    printf("Total samples : %d (%.2f s)\n", total, (float)total / SAMPLE_RATE);
    printf("Max amplitude : %.4f (%.1f%%)\n", max_amp, max_amp * 100.f);

    // Write WAV
    bool ok = write_wav(out_path, all_left.data(), all_right.data(), total, SAMPLE_RATE);
    if (ok) {
        printf("WAV written   : %s\n", out_path);
    } else {
        fprintf(stderr, "Failed to write WAV\n");
        dsp.cleanup();
        return 1;
    }

    dsp.cleanup();
    return 0;
}
