#pragma once
#include <cstdint>

// ============================================================
// Delay Lama DSP — clean C++ reimplementation
// Reverse-engineered from the Win32 x86 DLL via x86 emulation.
//
// Signal flow (per sample):
//   1. Portamento: smooth current_note toward target_note
//   2. Voice oscillator: sine wavetable runs at high speed, modulating pitch
//       voice_wt_pos += (voice_pos*0.2 + 1.0) * amp_env * (sr/1024)
//       voice_sample  = (voice_pos + 0.2) * sin_lut[trunc(voice_wt_pos)]
//   3. Pitch → period:
//       pitch   = current_note + voice_sample
//       freq_hz = freq_table[trunc(pitch * 32)]
//       period  = trunc(sr / freq_hz)
//   4. Period counter: incremented each sample. On reaching period:
//       a. triggerResonator(vowel_param) → fills output_buf[N_frames]
//       b. pitchShift(period_counter)   → accumulates output_buf into pitch_delay_buf
//   5. Output: out = pitch_delay_buf[read_pos] * (note*-0.01389 + 2.0) * volume
//              clear pitch_delay_buf[read_pos]; read_pos++
// ============================================================

struct DelayLamaDSP {

    // ----- constants -----
    static constexpr int   SIN_LUT_SIZE   = 1024;
    static constexpr int   PITCH_BUF_SIZE = 10240;
    static constexpr int   FORMANT_STEPS  = 4;   // 5 vowels → 4 segments
    static constexpr int   FORMANT_SEG    = 320;  // floats per segment
    static constexpr int   FORMANT_SIZE   = FORMANT_STEPS * FORMANT_SEG; // 1280

    // ----- plugin parameters (set by host, range 0..1) -----
    float p_volume      = 0.5f;
    float p_portamento  = 0.0f;
    float p_vowel_sel   = 0.5f;   // selects formant index (→ vowel_idx = trunc(p*1279))
    float p_vowel_depth = 1.0f;   // scales resonator amplitude (maps [esi+0xc4])

    // ----- public API -----
    void  init(float sample_rate);
    void  noteOn(int midi_note, int velocity);
    void  noteOff(int midi_note);
    void  setParameter(int idx, float value);
    void  process(float* out_L, float* out_R, int num_frames);
    void  cleanup();

    // ----- state (exposed for inspection) -----
    float sr         = 44100.f;
    int   N_frames   = 882;        // trunc(sr * 0.02)

private:
    // note state
    bool  note_on_     = false;
    float target_note_ = 60.f;
    float current_note_= 60.f;
    float port_step_   = 0.f;

    // amplitude envelope (simple linear ADSR approximation)
    float amp_env_     = 0.f;    // ≈ 5 when fully on; drives voice oscillator speed
    float amp_target_  = 0.f;
    float amp_rate_    = 0.f;
    int   block_ctr_   = 0;      // counts samples within N_frames block

    // voice oscillator
    float voice_wt_pos_ = 0.f;   // phase in sin_lut (0..1024)
    float voice_pos_    = 5.f;   // modulation amount (≈5 ± LCG noise)

    // resonator trigger
    int   period_counter_ = 0;
    int   period_         = 100;

    // resonator phase pairs (reset to 0 each trigger)
    // Not stored between triggers; computed fresh each call to triggerResonator.

    // pitch delay buffer
    float pitch_buf_[PITCH_BUF_SIZE] = {};
    int   write_pos_ = 0;        // write position (advanced by period_counter each trigger)
    int   read_pos_  = 0;        // read/clear position (advanced by 1 each sample)

    // LCG vowel noise
    uint32_t lcg_state_ = 0x12345678u;

    // tables (heap-allocated after init)
    float* sin_lut_    = nullptr;  // [1024] sin(k*2π/1024)
    float* voice_wt_   = nullptr;  // [1024] sin(k*2π/1024)  (same formula, separate alloc)
    float* exp_win_    = nullptr;  // [N_frames*4] e^(-k*50π/sr)
    float* ampl_buf_   = nullptr;  // [N_frames] Hann window: 0.5*(1-cos(k*2π/N_frames))
    float* kern_buf_   = nullptr;  // [N_frames] windowed dual-sinusoid: 4950+3800 Hz kernel
    float* output_buf_ = nullptr;  // [N_frames] resonator scratch buffer
    float* formant_F1_ = nullptr;  // [1280] F1 Hz interpolated across vowels
    float* formant_F2_ = nullptr;  // [1280] F2 Hz interpolated across vowels
    float* formant_F3_ = nullptr;  // [1280] F3 Hz interpolated across vowels
    float  freq_table_[4096] = {}; // freq_table[k] = MIDI0_Hz * (2^(1/12))^(k/32)

    void buildTables();
    void buildFormantTable(float* out, const float* hz_values);
    void triggerResonator(float vowel_param);
    void pitchShift(int period_cnt);
    void updateAmpBlock();
};
