#pragma once
#include <cstdint>

// ============================================================
// Delay Lama DSP — clean C++ reimplementation
// Reverse-engineered from the Win32 x86 DLL via x86 emulation.
//
// Precision model: The original DLL uses x87 80-bit FPU for all
// arithmetic, storing results to float32 memory.  We use double
// for all intermediate/accumulating state (matching the JS
// emulator's float64 FPU stack) and float for stored tables and
// buffers (matching the DLL's float32 memory layout).
// ============================================================

struct DelayLamaDSP {

    // ----- constants -----
    static constexpr int   SIN_LUT_SIZE   = 1024;
    static constexpr int   PITCH_BUF_SIZE = 10240;
    static constexpr int   FB_BUF_SIZE    = 20000;
    static constexpr int   FORMANT_STEPS  = 4;
    static constexpr int   FORMANT_SEG    = 320;
    static constexpr int   FORMANT_SIZE   = FORMANT_STEPS * FORMANT_SEG; // 1280

    // ----- plugin parameters (set by host, range 0..1) -----
    // Stored as float (matching DLL float32 memory at [esi+0xb0..0xc4])
    float p_volume      = 0.5f;
    float p_portamento  = 0.0f;
    float p_vowel_sel   = 0.5f;
    float p_vowel_depth = 1.0f;
    float p_feedback    = 0.3f;

    // ----- public API -----
    void  init(float sample_rate);
    void  noteOn(int midi_note, int velocity);
    void  noteOff(int midi_note);
    void  setParameter(int idx, float value);
    void  process(float* out_L, float* out_R, int num_frames);
    void  cleanup();

    // ----- state (exposed for inspection) -----
    float sr         = 44100.f;
    int   N_frames   = 882;

private:
    // note state — double for x87-precision arithmetic
    bool   note_on_       = false;
    bool   force_trigger_ = false;
    double target_note_   = 60.0;
    double current_note_  = 60.0;

    // amplitude envelope — double for accumulation precision
    double amp_env_     = 0.0;
    double amp_target_  = 0.0;
    int    block_ctr_   = 4586;

    // voice oscillator — double for phase accumulation
    double voice_wt_pos_ = 36.0;   // DLL inits to 36
    double voice_pos_    = 4.0;    // DLL inits [esi+0x615c]=4.0

    // resonator trigger
    int   period_counter_ = 0;
    int   period_         = 100;

    // pitch delay buffer — float (DLL float32 memory)
    float pitch_buf_[PITCH_BUF_SIZE] = {};
    int   write_pos_ = 0;
    int   read_pos_  = 0;

    // LCG noise
    uint32_t lcg_state_ = 0x12345678u;

    // tables — float* (DLL float32 memory)
    float* sin_lut_    = nullptr;
    float* voice_wt_   = nullptr;
    float* exp_win_    = nullptr;
    float* ampl_buf_   = nullptr;
    float* kern_buf_   = nullptr;
    float* output_buf_ = nullptr;
    float* formant_F1_ = nullptr;
    float* formant_F2_ = nullptr;
    float* formant_F3_ = nullptr;
    float  freq_table_[4096] = {};

    // IIR feedback delay buffers — float (DLL float32 memory)
    float* fb_A_     = nullptr;
    float* fb_B_     = nullptr;
    int    write_fb_   = 0;
    int    read_A_fb_  = 0;
    int    read_B_fb_  = 0;

    void buildTables();
    void buildFormantTable(float* out, const float* hz_values);
    void triggerResonator(float vowel_param);
    void pitchShift(int period_cnt);
    void updateAmpBlock();
};
