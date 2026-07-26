#pragma once
#include <cstdint>

// ============================================================
// Delay Lama DSP -- clean C++ reimplementation
// Reverse-engineered from the Win32 x86 DLL via x86 emulation.
//
// Signal flow (per sample):
//   1. Portamento: smooth current_note toward target_note
//   2. Voice oscillator: sine wavetable at low speed modulates pitch
//       voice_phase += voice_pos / (sr / 1024)
//       voice_sample = 0.2 * voice_wt[trunc(voice_phase)]
//   3. Pitch -> period:
//       pitch   = current_note + voice_sample
//       freq_hz = freq_table[trunc(pitch * 32)]
//       period  = trunc(sr / freq_hz)
//   4. Period counter: incremented each sample. On reaching period:
//       a. triggerResonator(vowel_param) -> fills output_buf[N_frames]
//       b. pitchShift(block_counter)    -> accumulates output_buf into pitch_buf
//   5. Output (second pass over the block):
//       out = (pitch_buf[read_pos] + fb_delay) * note_scale * 0.1
//       IIR feedback into stereo delay lines
//
// DLL field map (offsets from C++ this / esi):
//   0x614c  current_note      (float32)
//   0x6148  target_note       (float32)
//   0x6154  voice_wt_pos      (float32) -- temp: copies current_note, then pitch
//   0x6158  voice_phase       (float32) -- voice oscillator phase (0..1024)
//   0x615c  voice_pos         (float32) -- LCG-derived oscillator speed
//   0x6160  voice_raw         (float32) -- always 0
//   0x6164  voice_sample      (float32) -- 0.2 * voice_wt[phase]
//   0x6168  sr_div_1024       (float32) -- sr / 1024 (precomputed)
//   0x616c  period            (int32)   -- pitch period for LCG trigger
//   0x6170  period_counter    (int32)   -- counts up to period (LCG trigger)
//   0x6378  write_pos         (int32)   -- pitch_buf write position
//   0x637c  new_period        (int32)   -- pitch period for pitchShift trigger
//   0x6388  block_counter     (int32)   -- counts up to new_period (pitchShift trigger)
//   0x6142  force_trigger     (byte)
//   0x6174  note_on           (byte)
// ============================================================

struct DelayLamaDSP {

    // ----- constants -----
    static constexpr int   SIN_LUT_SIZE   = 1024;
    static constexpr int   PITCH_BUF_SIZE = 10240;
    static constexpr int   FB_BUF_SIZE    = 20000;  // IIR delay buffer size
    //static constexpr int   FB_BUF_SIZE    = 10000;  // IIR delay buffer size
    static constexpr int   FORMANT_STEPS  = 4;      // 5 vowels -> 4 segments
    static constexpr int   FORMANT_SEG    = 320;    // floats per segment
    static constexpr int   FORMANT_SIZE   = FORMANT_STEPS * FORMANT_SEG; // 1280

    // ----- plugin parameters (set by host, range 0..1) -----triggerResonator
    float p_volume      = 0.5f;
    float p_portamento  = 0.0f;
    int p_vowel_sel   = 2;   // selects formant position
    bool p_vowel_changed = false;
    float p_vowel_depth = 1.0f;   // scales resonator amplitude
    float p_feedback    = 0.3f;   // IIR delay feedback coefficient

    // ----- public API -----
    void  init(float sample_rate);
    void  noteOn(int midi_note, int velocity);
    void  noteOff(int midi_note);
    void  setParameter(int idx, float value);
    void  process(float* out_L, float* out_R, int num_frames);
    void  cleanup();

    // ----- state (exposed for inspection) -----
    static constexpr float sr         = 44100.f;
    static constexpr int   N_frames   = 882;       // trunc(sr / 50) = 20ms frame

private:
    // note state
    bool  note_on_       = false;
    bool  force_trigger_ = false;
    float target_note_   = 0.f;
    float current_note_  = 0.f;

    // voice oscillator
    float voice_phase_   = 0.f;   // oscillator phase (0..1024)
    float voice_pos_     = 4.f;   // LCG-derived speed (~4..6)
    float sr_div_1024_   = 0.f;   // precomputed sr/1024

    // two separate trigger counters
    int   period_counter_ = 0;    // counts up to period_ -> LCG update
    int   period_         = 100;  // LCG trigger threshold
    int   block_counter_  = 0;    // counts up to new_period_ -> pitchShift
    int   new_period_     = 100;  // pitchShift trigger threshold

    // amplitude envelope
    float amp_env_     = 0.f;
    float amp_target_  = 0.f;
    int   block_ctr_   = 4586;

    // pitch delay buffer (circular, 10240 floats)
    float pitch_buf_[PITCH_BUF_SIZE] = {};
    int   write_pos_ = 0;
    int   read_pos_  = 0;

    // LCG noise (Borland Delphi constants)
    uint32_t lcg_state_ = 0u;

    // lookup tables (heap-allocated in init)
    //sin_lut_  = new float[SIN_LUT_SIZE];
    //voice_wt_ = new float[SIN_LUT_SIZE];
    //    int exp_size = N_frames * 4;
    //exp_win_ = new float[exp_size];
    //ampl_buf_ = new float[N_frames];
    //    kern_buf_ = new float[N_frames];
    //output_buf_ = new float[N_frames]();
    //fb_A_ = new float[FB_BUF_SIZE]();
    //fb_B_ = new float[FB_BUF_SIZE]();
    //formant_F1_ = new float[FORMANT_SIZE];
    //formant_F2_ = new float[FORMANT_SIZE];
    //formant_F3_ = new float[FORMANT_SIZE];

    float sin_lut_[SIN_LUT_SIZE];  // [1024] sin(k * 2pi / 1024)
    float voice_wt_[SIN_LUT_SIZE];  // [1024] same sine wavetable

    float exp_win_[N_frames*4];  // [N_frames*4] e^(-k * 50pi / sr)
    float ampl_buf_[N_frames];  // [N_frames] piecewise window (rise/flat/fade)
    float kern_buf_[N_frames];  // [N_frames] 4950+3800 Hz dual-sinusoid kernel
    float output_buf_[N_frames];  // [N_frames] resonator scratch buffer
    float formant_F1_[FORMANT_SIZE];  // [1280] F1 Hz interpolated across 5 vowels
    float formant_F2_[FORMANT_SIZE];  // [1280] F2 Hz
    float formant_F3_[FORMANT_SIZE];  // [1280] F3 Hz
    float freq_table_[4096]; // MIDI-to-Hz: midi0 * 2^(k/384)

    // IIR feedback delay lines (stereo spread)
    float fb_A_[FB_BUF_SIZE];    // [20000] left channel delay
    float fb_B_[FB_BUF_SIZE];    // [20000] right channel delay
    int    write_fb_   = 0;
    int    read_A_fb_  = 0;        // ~0.31s delay
    int    read_B_fb_  = 0;        // ~0.40s delay

    void buildTables();
    void buildFormantTable(float* out, const float* hz_values);
    void triggerResonator(int vowel_param);
    void pitchShift(int period_cnt);
    void updateAmpBlock();
};
