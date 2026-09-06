// DDX10 DSP test — renders a short MIDI sequence to a WAV file
// Build: c++ -O2 -std=c++17 -o ddx10_test ddx10_test.cpp -lm
// Play:  open ddx10_out.wav   (or: afplay ddx10_out.wav)
#include "ddx10_dsp.h"
#include <cstdio>
#include <cstdint>
#include <vector>

static void writeWav(const char* path, const std::vector<float>& interleaved,
                     int sampleRate, int channels) {
    uint32_t numSamples = (uint32_t)interleaved.size();
    uint32_t dataSize   = numSamples * sizeof(int16_t);
    uint32_t fileSize   = 36 + dataSize;

    FILE* f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "Cannot open %s\n", path); return; }

    fwrite("RIFF", 1, 4, f);
    fwrite(&fileSize, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    fwrite("fmt ", 1, 4, f);
    uint32_t fmtSize = 16;
    uint16_t audioFmt = 1;
    uint16_t nCh = channels;
    uint32_t sr = sampleRate;
    uint16_t bitsPerSample = 16;
    uint32_t byteRate = sr * nCh * bitsPerSample / 8;
    uint16_t blockAlign = nCh * bitsPerSample / 8;
    fwrite(&fmtSize, 4, 1, f);
    fwrite(&audioFmt, 2, 1, f);
    fwrite(&nCh, 2, 1, f);
    fwrite(&sr, 4, 1, f);
    fwrite(&byteRate, 4, 1, f);
    fwrite(&blockAlign, 2, 1, f);
    fwrite(&bitsPerSample, 2, 1, f);
    fwrite("data", 1, 4, f);
    fwrite(&dataSize, 4, 1, f);
    for (uint32_t i = 0; i < numSamples; i++) {
        float s = interleaved[i];
        if (s >  1.f) s =  1.f;
        if (s < -1.f) s = -1.f;
        int16_t pcm = (int16_t)(s * 32767.f);
        fwrite(&pcm, 2, 1, f);
    }
    fclose(f);
}

static void writeRaw(const char* path, const std::vector<float>& interleaved) {
    FILE* f = fopen(path, "wb");
    if (!f) return;
    fwrite(interleaved.data(), sizeof(float), interleaved.size(), f);
    fclose(f);
}

int main() {
    DDX10 synth;
    synth.init(44100.f);

    constexpr int SR = 44100;
    constexpr int BLOCK = 512;
    float L[BLOCK], R[BLOCK];
    std::vector<float> out;

    // Render full blocks (matching the JS reference which always renders BLOCK_SIZE)
    auto renderBlocks = [&](double seconds) {
        int totalSamples = (int)(seconds * SR);
        int numBlocks = (totalSamples + BLOCK - 1) / BLOCK;  // round up
        for (int b = 0; b < numBlocks; b++) {
            synth.processReplacing(L, R, BLOCK);
            for (int i = 0; i < BLOCK; i++) {
                out.push_back(L[i]);
                out.push_back(R[i]);
            }
        }
    };

    // Play a C major chord
    synth.noteOn(60, 100); // C4
    synth.noteOn(64, 90);  // E4
    synth.noteOn(67, 85);  // G4
    renderBlocks(1.0);

    synth.noteOff(60);
    synth.noteOff(64);
    synth.noteOff(67);
    renderBlocks(0.5);

    // Chromatic run
    for (int n = 48; n <= 72; n++) {
        synth.noteOn(n, 80);
        renderBlocks(0.15);
        synth.noteOff(n);
        renderBlocks(0.05);
    }

    renderBlocks(1.0); // tail

    writeWav("ddx10_out.wav", out, SR, 2);
    writeRaw("ddx10_out.raw", out);
    printf("Wrote ddx10_out.wav (%d Hz, 16-bit stereo, %.1f sec, %zu samples)\n",
           SR, (double)out.size() / 2.0 / SR, out.size());
    printf("Wrote ddx10_out.raw (float32 interleaved L/R)\n");
    return 0;
}
