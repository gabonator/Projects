// delaylama_dsp.cpp
// Clean C++ reimplementation of the Delay Lama VST DSP engine.
//
// Constants confirmed from rdata binary:
//   MIDI0_Hz        = 8.175798916    (= A0 = 440/2^(69/12))
//   semitone_ratio  = 1.059463094    (= 2^(1/12))
//   freq_step       = 0.03125        (= 1/32)
//   K               = 0.02           (→ N_frames = trunc(sr*0.02))
//   decay_const     = 50π = 157.0796 (→ exp_win[k] = e^(-k*50π/sr))
//   delay_steps     = 0.65, 0.95, 1.25 (32.5/47.5/62.5 * 0.02)
//   out_bias        = 2.0, out_scale = -0.01389  (note scaling)
//   port_neg        = -12,  port_pos  = 12
//   port_add        = 0.01            (portamento denominator addend)
//   wt_scale1       = 0.2,  wt_scale2 = 1.0  (voice oscillator formula)
//   amp_bias        = 5.0             (amp_env offset after vtable call)
//   formant_scale   = 1279            (vowel_param * 1279 = vowel_idx)
//   kern_freq1      = 4950 Hz, step1 = 3.0
//   kern_freq2      = 3800 Hz, step2 = 3.6

#include "delaylama_dsp.h"
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

static constexpr float TWO_PI       = 6.283185307f;
static constexpr float MIDI0_HZ     = 8.175798916f;
static constexpr float SEMITONE     = 1.059463094f;   // 2^(1/12)
static constexpr float DECAY_CONST  = 157.0796327f;   // 50 * π
static constexpr float KERN_F1      = 4950.f;
static constexpr float KERN_F2      = 3800.f;
static constexpr float KERN_STEP1   = 3.0f;
static constexpr float KERN_STEP2   = 3.6f;

// Formant frequencies for 5 vowels (a, e, i, o, u approximate)
// F1: {280, 450, 800, 350, 270} Hz
// F2: {600, 800, 1150, 2000, 2140} Hz
// F3: {2240, 2830, 2900, 2800, 2950} Hz
static const float VOWEL_F1[5] = {280.f, 450.f,  800.f, 350.f,  270.f};
static const float VOWEL_F2[5] = {600.f, 800.f, 1150.f, 2000.f, 2140.f};
static const float VOWEL_F3[5] = {2240.f,2830.f, 2900.f, 2800.f, 2950.f};

// ─────────────────────────────────────────────────────────
// buildFormantTable
// Fills `out[0..1279]` by linearly interpolating between the
// 5 Hz values (4 segments × 320 samples each), matching what
// sub_10005350 (Horner-polynomial-FIR) produces at DC for each
// position. We use simple Hermite spline for smoothness.
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::buildFormantTable(float* out, const float* hz)
{
    // 4 segments between 5 vowel points, 320 floats each
    for (int seg = 0; seg < FORMANT_STEPS; seg++) {
        float h0 = hz[seg];
        float h1 = hz[seg + 1];
        // Hermite tangents (clamped)
        float t0 = (seg > 0)              ? 0.5f*(hz[seg+1]-hz[seg-1]) : (h1-h0);
        float t1 = (seg < FORMANT_STEPS-1)? 0.5f*(hz[seg+2]-hz[seg])   : (h1-h0);
        for (int i = 0; i < FORMANT_SEG; i++) {
            float u  = (float)i / FORMANT_SEG;
            float u2 = u*u, u3 = u2*u;
            // Cubic Hermite
            out[seg*FORMANT_SEG + i] =
                (2*u3 - 3*u2 + 1)*h0 + (u3 - 2*u2 + u)*t0 +
                (-2*u3 + 3*u2)*h1    + (u3 - u2)*t1;
        }
    }
}

// ─────────────────────────────────────────────────────────
// buildTables — called once from init()
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::buildTables()
{
    // sin_lut: one full cycle — sin(k * 2π/1024) — used by resonator formants
    sin_lut_  = new float[SIN_LUT_SIZE];
    for (int k = 0; k < SIN_LUT_SIZE; k++) {
        sin_lut_[k] = sinf(k * TWO_PI / SIN_LUT_SIZE);
    }

    // voice_wt: standard sine wave sin(k * 2π/1024) for k=0..1023
    // DLL sub_100048d0 lines 3720-3732: fild32(i) * 2π / 1024, fsin()
    // [esi+0x64b8] = pointer to 1024-entry table; [esi+0x64bc] = 1024 (wrap size)
    voice_wt_ = new float[SIN_LUT_SIZE];
    for (int k = 0; k < SIN_LUT_SIZE; k++) {
        voice_wt_[k] = sinf(k * TWO_PI / SIN_LUT_SIZE);
    }

    // freq_table[k] = MIDI0_Hz * (2^(1/12))^(k/32)
    // Accessed as: freq = freq_table[trunc(pitch * 32)]
    // pitch = current_note + voice_sample (in MIDI note units)
    for (int k = 0; k < 4096; k++) {
        freq_table_[k] = MIDI0_HZ * powf(SEMITONE, (float)k * 0.03125f);
    }

    // exp_win[k] = e^(-k * 50π / sr)
    // Size = N_frames * 4 (resonator lut phase can reach up to N_frames * max_step)
    int exp_size = N_frames * 4;
    exp_win_ = new float[exp_size];
    for (int k = 0; k < exp_size; k++) {
        exp_win_[k] = expf(-(float)k * DECAY_CONST / sr);
    }

    // ampl_buf: piecewise window from DLL sub_100048d0 (NOT a Hann window)
    // Constants from rdata: rise_K=0x1000baf8=0.0018, fade_start_K=0x1000baf0=0.013, fade_K=0x1000bae8=0.007
    // Structure: rise (fast 79-sample cosine ramp), flat (1.0), fade (slow 308-sample cosine ramp)
    static constexpr float PI_F = 3.14159265358979f;
    int rise_len   = (int)(sr * 0.0018f);   // 79 at 44100 Hz
    int fade_start = (int)(sr * 0.013f);    // 573 at 44100 Hz
    int fade_len   = (int)(sr * 0.007f);    // 308 at 44100 Hz
    ampl_buf_ = new float[N_frames];
    for (int k = 0; k < N_frames; k++) ampl_buf_[k] = 1.0f;
    for (int k = 0; k < rise_len && k < N_frames; k++)
        ampl_buf_[k] = 0.5f * (1.f - cosf((float)k * PI_F / rise_len));
    for (int k = fade_start; k < N_frames; k++)
        ampl_buf_[k] = 0.5f * (1.f - cosf((float)(fade_len + k) * PI_F / fade_len));

    // kern_buf[k] = (sin(k*2π*KERN_F1/sr)*exp_win[trunc(k*KERN_STEP1)]
    //              + sin(k*2π*KERN_F2/sr)*exp_win[trunc(k*KERN_STEP2)]) * 0.5
    kern_buf_ = new float[N_frames];
    int exp_cap = exp_size - 1;
    for (int k = 0; k < N_frames; k++) {
        int idx1 = std::min((int)(k * KERN_STEP1), exp_cap);
        int idx2 = std::min((int)(k * KERN_STEP2), exp_cap);
        float s1 = sinf(k * TWO_PI * KERN_F1 / sr) * exp_win_[idx1];
        float s2 = sinf(k * TWO_PI * KERN_F2 / sr) * exp_win_[idx2];
        kern_buf_[k] = s1 + s2;
    }

    // output_buf: scratch buffer for resonator output
    output_buf_ = new float[N_frames]();

    // IIR feedback delay buffers (20000 samples each, zero-initialized)
    fb_A_ = new float[FB_BUF_SIZE]();
    fb_B_ = new float[FB_BUF_SIZE]();

    // formant tables: 1280 Hz values across 5 vowel positions
    formant_F1_ = new float[FORMANT_SIZE];
    formant_F2_ = new float[FORMANT_SIZE];
    formant_F3_ = new float[FORMANT_SIZE];
    buildFormantTable(formant_F1_, VOWEL_F1);
    buildFormantTable(formant_F2_, VOWEL_F2);
    buildFormantTable(formant_F3_, VOWEL_F3);
}

// ─────────────────────────────────────────────────────────
// init
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::init(float sample_rate)
{
    sr       = sample_rate;
    N_frames = (int)(sr * 0.02f);   // = 882 at 44100 Hz

    cleanup();    // free any previous allocation
    buildTables();

    memset(pitch_buf_, 0, sizeof(pitch_buf_));
    write_pos_      = 0;
    read_pos_       = 0;

    // IIR feedback buffer indices (from DLL sub_100048d0 init)
    // read_A = trunc(sr * -0.309592) mod 20000  →  6347 at 44100 Hz
    // read_B = trunc(sr * -0.398435) mod 20000  →  2429 at 44100 Hz
    write_fb_ = 0;
    {
        int ra = (int)(sr * -0.309592f);
        ra %= FB_BUF_SIZE;
        if (ra < 0) ra += FB_BUF_SIZE;
        read_A_fb_ = ra;

        int rb = (int)(sr * -0.398435f);
        rb %= FB_BUF_SIZE;
        if (rb < 0) rb += FB_BUF_SIZE;
        read_B_fb_ = rb;
    }
    note_on_        = false;
    force_trigger_  = false;
    current_note_   = 60.f;
    target_note_    = 60.f;
    amp_env_        = 0.f;
    amp_target_     = 0.f;
    voice_wt_pos_   = 36.f;  // DLL initial value (confirmed from JS emulator state dump)
    voice_pos_      = 4.f;   // DLL [esi+0x615c]=0x40800000=4.0 at activation
    period_counter_ = 0;
    period_         = 100;
    // DLL [esi+0x616c] = trunc(sr * 104 * 0.001) = 4586 at 44100 Hz (LCG fires every 4586 samples)
    // DLL counter [esi+0x6170] starts at 0, increments each sample, fires when >= limit.
    // Initialise block_ctr_ to the limit so first fire is at sample LCG_LIMIT, not sample 0.
    block_ctr_      = (int)(sr * 104.f * 0.001f);
    lcg_state_      = 0u;   // DLL heap zero-initialized; JS emulator also starts at 0
}

// ─────────────────────────────────────────────────────────
// cleanup
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::cleanup()
{
    delete[] sin_lut_;    sin_lut_    = nullptr;
    delete[] voice_wt_;   voice_wt_   = nullptr;
    delete[] exp_win_;    exp_win_    = nullptr;
    delete[] ampl_buf_;   ampl_buf_   = nullptr;
    delete[] kern_buf_;   kern_buf_   = nullptr;
    delete[] output_buf_; output_buf_ = nullptr;
    delete[] formant_F1_; formant_F1_ = nullptr;
    delete[] formant_F2_; formant_F2_ = nullptr;
    delete[] formant_F3_; formant_F3_ = nullptr;
    delete[] fb_A_;       fb_A_       = nullptr;
    delete[] fb_B_;       fb_B_       = nullptr;
}

// ─────────────────────────────────────────────────────────
// setParameter
//   0: volume  (0..1)
//   1: vowel   (0..1 — selects formant position)
//   2: portamento speed  (0..1)
//   3: vowel depth / resonator amplitude  (0..1)
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::setParameter(int idx, float value)
{
    switch (idx) {
        case 0: p_volume      = value; break;
        case 1: p_vowel_sel   = value; break;
        case 2: p_portamento  = value; break;
        case 3: p_vowel_depth = value; break;
        case 4: p_feedback    = value; break;
    }
}

// ─────────────────────────────────────────────────────────
// noteOn / noteOff
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::noteOn(int midi_note, int /*velocity*/)
{
    // DLL stores internal_note = midi_note - 12 (see sub_10006240: ebx -= 0x0C)
    target_note_ = (float)(midi_note - 12);
    if (!note_on_) {
        current_note_ = target_note_;  // no portamento on first note
    }
    note_on_        = true;
    amp_target_     = 5.f;
    // Matches DLL [esi+0x6142]=1 at note-on: fire resonator at sample 0
    // of the first pass with pitchShift(0), pre-filling pitch_buf_[0..N_frames-1]
    force_trigger_  = true;
    period_counter_ = 0;
}

void DelayLamaDSP::noteOff(int /*midi_note*/)
{
    note_on_ = false;
    // DLL note-off: skip all trigger/pitchShift logic each sample; let pitch_buf_ drain.
    // IIR delay buffers (fb_A_, fb_B_) continue to echo naturally.
}

// ─────────────────────────────────────────────────────────
// updateAmpBlock — called every N_frames samples.
// In the DLL this calls a vtable function that returns the
// current envelope value; we approximate with linear ramp.
// amp_env = 2 * envelope_value + 5.0 (from disasm)
// We skip the vtable and use a direct amp_env ramp.
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::updateAmpBlock()
{
    // Ramp amp_env toward amp_target_ at 50 Hz update rate
    float rate = N_frames / sr * 10.f;   // ~0.2 s attack/release
    if (amp_env_ < amp_target_)
        amp_env_ = std::min(amp_env_ + rate, amp_target_);
    else
        amp_env_ = std::max(amp_env_ - rate, amp_target_);
}

// ─────────────────────────────────────────────────────────
// triggerResonator
// Fills output_buf_[0..N_frames-1] with 3-resonator output.
// Called every `period` samples with the current vowel_param.
//
// Each resonator:
//   phase_delay starts at 0, advances by delay_step per sample
//   phase_lut   starts at 0, advances by amp_step per sample
//   sample = sin_lut[trunc(phase_delay) & 1023] * exp_win[trunc(phase_lut)]
// Then: output_buf[i] += kern_buf[i]*0.5
//       output_buf[i] *= ampl_buf[i]  (Hann window)
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::triggerResonator(float vowel_param)
{
    // Compute vowel index: trunc(vowel_param * 1279)
    // The DLL uses [esi+0xb4] * 1279 for the formant table index.
    int vowel_idx = (int)(vowel_param * 1279.f);
    if (vowel_idx < 0) vowel_idx = 0;
    if (vowel_idx >= FORMANT_SIZE) vowel_idx = FORMANT_SIZE - 1;

    // Compute resonator amplitude-per-sample from formant Hz values.
    // amp_step = vowel_pos_float * Hz * (1024/sr)
    // vowel_pos_float = [esi+0xc4] * 0.5 + 0.75
    // where [esi+0xc4] = p_vowel_depth (DLL preset parameter 3)
    // confirmed: 0x1000ba78=0.5 (f64), 0x1000bb70=0.75 (f64)
    // e.g. preset 1: [esi+0xc4]=0 → vowel_pos_float=0.75
    float vowel_pos_float = p_vowel_depth * 0.5f + 0.75f;
    float inv_sr_1024 = 1024.f / sr;

    float amp_step[3];
    amp_step[0] = vowel_pos_float * formant_F1_[vowel_idx] * inv_sr_1024;
    amp_step[1] = vowel_pos_float * formant_F2_[vowel_idx] * inv_sr_1024;
    amp_step[2] = vowel_pos_float * formant_F3_[vowel_idx] * inv_sr_1024;

    // Delay steps (32.5/47.5/62.5 * 0.02) confirmed from rdata at [esi+0x639c/63a0/63a4]:
    static constexpr float DELAY_STEP[3] = {0.65f, 0.95f, 1.25f};

    // sin_phase: indexes sin_lut (wraps at 1024), advances by amp_step
    // exp_phase: indexes exp_win (monotonic), advances by DELAY_STEP
    // Confirmed from sub_10005fb0:
    //   fldst(2)/sub_1000a75c() → sin_lut index; faddpst(3) with amp_step → advance; wrap at 1024
    //   fldst(5)/sub_1000a75c() → exp_win index; fxchst2+fadd([0x639c]) → advance at DELAY_STEP
    float sin_phase[3] = {0.f, 0.f, 0.f};
    float exp_phase[3] = {0.f, 0.f, 0.f};

    int exp_cap = N_frames * 4 - 1;

    // Clear output buffer
    memset(output_buf_, 0, N_frames * sizeof(float));

    // Main resonator loop
    for (int i = 0; i < N_frames; i++) {
        float sample = 0.f;

        for (int r = 0; r < 3; r++) {
            // sin_lut indexed by sin_phase (wraps at 1024) → formant frequency oscillation
            int sl_idx = (int)sin_phase[r] & (SIN_LUT_SIZE - 1);
            // exp_win indexed by exp_phase (no wrap, clamped) → exponential decay envelope
            int ep_idx = (int)exp_phase[r];
            if (ep_idx > exp_cap) ep_idx = exp_cap;

            sample += sin_lut_[sl_idx] * exp_win_[ep_idx];

            // Advance sin_phase by amp_step, wrap at 1024 (sin_lut size)
            sin_phase[r] += amp_step[r];
            if (sin_phase[r] >= 1024.f) sin_phase[r] -= 1024.f;

            // Advance exp_phase by delay_step (monotonic, no wrap)
            exp_phase[r] += DELAY_STEP[r];
        }

        // Add kernel contribution (4950+3800 Hz windowed sinusoids)
        // kern_buf already unscaled; DLL applies *0.5 once here (0x1000ba78 = 0.5)
        sample += kern_buf_[i] * 0.5f;

        // Apply amplitude window
        output_buf_[i] = sample * ampl_buf_[i];
    }
}

// ─────────────────────────────────────────────────────────
// pitchShift — accumulates output_buf_ into pitch_delay_buf_
// starting at write_pos + period_cnt (circular, size 10240).
// Mirrors sub_10005eb0 in the original DLL.
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::pitchShift(int period_cnt)
{
    // Advance write_pos by period_cnt
    write_pos_ = (write_pos_ + period_cnt) % PITCH_BUF_SIZE;
    // Clamp to positive range
    if (write_pos_ < 0) write_pos_ += PITCH_BUF_SIZE;

    // Accumulate output_buf_ into pitch_buf_ starting at write_pos_.
    // DLL sub_10005eb0: loop increments [ecx+0x6378] N_frames times to W+P+N,
    // then EXIT code (0x10005f95) does [ecx+0x6378] -= N_frames → net = W+P.
    // So write_pos_ stays at W+period_cnt; do NOT advance by N_frames here.
    int wp = write_pos_;
    for (int i = 0; i < N_frames; i++) {
        pitch_buf_[wp] += output_buf_[i];
        if (++wp >= PITCH_BUF_SIZE) wp = 0;
    }
    // write_pos_ already = W + period_cnt from the modulo above — leave it.
}

// ─────────────────────────────────────────────────────────
// process — main audio callback
//
// Mirrors the DLL's sub_100054c0 two-pass structure:
//   FIRST LOOP  (num_frames iterations): resonator trigger logic, writes to pitch_buf_
//   SECOND LOOP (num_frames iterations): reads pitch_buf_, generates audio output
//
// This matches [esi+0x6142] (force_trigger_) being set at note-on, causing
// pitchShift(0) at sample 0 of the first loop to pre-fill pitch_buf_[0..N_frames-1].
// The second loop then reads those values, making output sample[1] non-zero.
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::process(float* out_L, float* out_R, int num_frames)
{
    // ── FIRST PASS: resonator trigger + pitch_buf_ writes ──
    for (int s = 0; s < num_frames; s++) {

        // ── Amplitude block update (every N_frames samples) ──
        if (block_ctr_ <= 0) {
            updateAmpBlock();
            // LCG (Borland): new_state = state * 0x0019660D + 0x3C6EF35F
            // DLL sub_10006400: fild32(new_state) * (1/2^32), caller doubles + adds 5.0
            // voice_pos = 2 * ((int32_t)state / 2^32) + 5.0  in [4.0, 6.0)
            lcg_state_ = lcg_state_ * 0x0019660Du + 0x3C6EF35Fu;
            voice_pos_ = 2.0f * ((int32_t)lcg_state_ * (1.0f / 4294967296.0f)) + 5.0f;

            block_ctr_  = (int)(sr * 104.f * 0.001f);  // LCG period = 4586 at 44100 Hz
        }
        block_ctr_--;

        // ── Portamento ──
        if (current_note_ != target_note_) {
            float port_rate = 12.f / ((p_portamento + 0.01f) * sr);
            if (current_note_ < target_note_) {
                current_note_ = std::min(current_note_ + port_rate, target_note_);
            } else {
                current_note_ = std::max(current_note_ - port_rate, target_note_);
            }
        }

        // ── Voice oscillator ──
        if (voice_wt_pos_ >= 1024.f) voice_wt_pos_ -= 1024.f;
        int wt_idx = (int)voice_wt_pos_ & (SIN_LUT_SIZE - 1);
        float voice_sample = 0.2f * voice_wt_[wt_idx];
        voice_wt_pos_ += voice_pos_ * (1024.f / sr);

        // ── Pitch → frequency → period ──
        // current_note_ is in internal space (MIDI - 12).
        // DLL reads freq_table at index trunc(pitch * 32) with MIDI0_Hz base,
        // so internal note 48 → index 1536 → 130.8 Hz (C3) → period 337.
        // No +12 offset: the DLL subtracts 12 at note-on, so the freq lookup is
        // naturally one octave lower than the nominal MIDI note.
        float pitch = current_note_ + voice_sample;
        int ft_idx = (int)(pitch * 32.f);
        if (ft_idx < 0)    ft_idx = 0;
        if (ft_idx > 4095) ft_idx = 4095;
        float freq_hz = freq_table_[ft_idx];
        int new_period = (freq_hz > 0.f) ? (int)(sr / freq_hz) : 100;
        if (new_period < 1) new_period = 1;
        period_ = new_period;

        // ── Period counter → resonator trigger ──
        // DLL note-off path: jumps directly to loop tail, NEVER reaching this trigger logic.
        // So: only trigger when note is on (note_on_ == true).
        //
        // force_trigger_ (= DLL's [esi+0x6142]=1 at note-on):
        //   fires resonator + pitchShift(period_counter_)
        //   At note-on, period_counter_=0 → pitchShift(0) fills pitch_buf_[0..N_frames-1].
        // Normal trigger: fires pitchShift(period_counter_) when period_counter_ >= period_.
        //   Reuses existing output_buf_ (DLL skips resonator when force_trigger==0).
        // After note-off: no trigger; pitch_buf_ drains to silence; IIR echo continues.
        bool do_trigger = false;
        int  pitch_cnt  = 0;

        if (note_on_) {
            if (force_trigger_) {
                // DLL [esi+0x6142]=1 at note-on: call resonator then pitchShift(period_counter_)
                pitch_cnt      = period_counter_;
                do_trigger     = true;
                force_trigger_ = false;
                triggerResonator(p_vowel_sel);
            } else if (period_counter_ >= period_) {
                // DLL normal period trigger: pitchShift only, reuse existing output_buf_
                pitch_cnt  = period_counter_;
                do_trigger = true;
                // triggerResonator NOT called — DLL skips it when force_trigger==0
            }

            if (do_trigger) {
                pitchShift(pitch_cnt);
                period_counter_ = 0;
            }

            period_counter_++;
        }
    }

    // ── SECOND PASS: read pitch_buf_, generate audio ──
    float note_scale = current_note_ * -0.013888889f + 2.f;
    float vol        = note_scale * 0.1f;

    for (int s = 0; s < num_frames; s++) {
        float a_val = fb_A_[read_A_fb_];
        float b_val = fb_B_[read_B_fb_];
        float pval = pitch_buf_[read_pos_];

        fb_A_[write_fb_] = (a_val * 0.5f + pval) * p_feedback;
        fb_B_[write_fb_] = (b_val * 0.5f + pval) * p_feedback;
        if (++write_fb_ >= FB_BUF_SIZE) write_fb_ = 0;

        out_L[s] = (pval + a_val) * vol;
        out_R[s] = (pval + b_val) * vol;

        // Clear pitch_buf slot and advance read position
        pitch_buf_[read_pos_] = 0.f;
        if (++read_pos_ >= PITCH_BUF_SIZE) read_pos_ = 0;

        // Advance feedback read indices
        if (++read_A_fb_ >= FB_BUF_SIZE) read_A_fb_ = 0;
        if (++read_B_fb_ >= FB_BUF_SIZE) read_B_fb_ = 0;
    }
}
