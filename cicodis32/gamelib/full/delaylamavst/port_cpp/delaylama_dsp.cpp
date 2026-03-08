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
    // sin_lut / voice_wt: sin(k * 2π/1024)
    sin_lut_  = new float[SIN_LUT_SIZE];
    voice_wt_ = new float[SIN_LUT_SIZE];
    for (int k = 0; k < SIN_LUT_SIZE; k++) {
        float v = sinf(k * TWO_PI / SIN_LUT_SIZE);
        sin_lut_[k] = v;
        voice_wt_[k] = v;
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

    // ampl_buf[k] = Hann window: 0.5*(1-cos(k*2π/N_frames))
    // The DLL uses a two-segment window; we approximate with a standard Hann.
    ampl_buf_ = new float[N_frames];
    for (int k = 0; k < N_frames; k++) {
        ampl_buf_[k] = 0.5f * (1.f - cosf(k * TWO_PI / N_frames));
    }

    // kern_buf[k] = (sin(k*2π*KERN_F1/sr)*exp_win[trunc(k*KERN_STEP1)]
    //              + sin(k*2π*KERN_F2/sr)*exp_win[trunc(k*KERN_STEP2)]) * 0.5
    kern_buf_ = new float[N_frames];
    int exp_cap = exp_size - 1;
    for (int k = 0; k < N_frames; k++) {
        int idx1 = std::min((int)(k * KERN_STEP1), exp_cap);
        int idx2 = std::min((int)(k * KERN_STEP2), exp_cap);
        float s1 = sinf(k * TWO_PI * KERN_F1 / sr) * exp_win_[idx1];
        float s2 = sinf(k * TWO_PI * KERN_F2 / sr) * exp_win_[idx2];
        kern_buf_[k] = (s1 + s2) * 0.5f;
    }

    // output_buf: scratch buffer for resonator output
    output_buf_ = new float[N_frames]();

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
    note_on_        = false;
    current_note_   = 60.f;
    target_note_    = 60.f;
    amp_env_        = 0.f;
    amp_target_     = 0.f;
    voice_wt_pos_   = 0.f;
    voice_pos_      = 5.f;
    period_counter_ = 0;
    period_         = (int)(sr / 261.63f);  // ~middle C default
    block_ctr_      = 0;
    lcg_state_      = 0x12345678u;
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
    }
}

// ─────────────────────────────────────────────────────────
// noteOn / noteOff
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::noteOn(int midi_note, int /*velocity*/)
{
    target_note_ = (float)midi_note;
    if (!note_on_) {
        current_note_ = target_note_;  // no portamento on first note
    }
    note_on_    = true;
    amp_target_ = 5.f;  // target amp_env when note is on
    // portamento step: ±12 / ((param + 0.01) * sr)
    // computed lazily in process() when current != target
}

void DelayLamaDSP::noteOff(int /*midi_note*/)
{
    note_on_    = false;
    amp_target_ = 0.f;
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
    // amp_step = vowel_depth_float * Hz * (1024/sr)
    // where vowel_depth_float = p_vowel_depth * 0.5 (maps [esi+0xc4]*0.5)
    // Doubling to account for the * 0.5 in original code so the resonant
    // frequency matches the formant Hz value:
    float depth = p_vowel_depth;   // 0..1, treated as 0..1 multiplier
    float inv_sr_1024 = 1024.f / sr;

    float amp_step[3];
    amp_step[0] = depth * formant_F1_[vowel_idx] * inv_sr_1024;
    amp_step[1] = depth * formant_F2_[vowel_idx] * inv_sr_1024;
    amp_step[2] = depth * formant_F3_[vowel_idx] * inv_sr_1024;

    // Delay steps (32.5/47.5/62.5 * 0.02) confirmed from rdata:
    static constexpr float DELAY_STEP[3] = {0.65f, 0.95f, 1.25f};

    // Initialize resonator phases to 0 (as in the DLL: fld32(0)*6)
    float phase_delay[3] = {0.f, 0.f, 0.f};
    float phase_lut[3]   = {0.f, 0.f, 0.f};

    int exp_cap = N_frames * 4 - 1;

    // Clear output buffer
    memset(output_buf_, 0, N_frames * sizeof(float));

    // Main resonator loop
    for (int i = 0; i < N_frames; i++) {
        float sample = 0.f;

        for (int r = 0; r < 3; r++) {
            // sin_lut read (phase_delay, wraps at 1024)
            int dl_idx = (int)phase_delay[r] & (SIN_LUT_SIZE - 1);
            // exp_win read (phase_lut, clamped)
            int pl_idx = (int)phase_lut[r];
            if (pl_idx > exp_cap) pl_idx = exp_cap;

            sample += sin_lut_[dl_idx] * exp_win_[pl_idx];

            // Advance delay phase
            phase_delay[r] += DELAY_STEP[r];

            // Advance lut phase, wrap at 1024
            phase_lut[r] += amp_step[r];
            if (phase_lut[r] >= 1024.f) phase_lut[r] -= 1024.f;
        }

        // Add kernel contribution (4950+3800 Hz windowed sinusoids)
        sample += kern_buf_[i] * 0.5f;

        // Apply Hann window
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

    // Accumulate output_buf_ into pitch_buf_ starting at write_pos_
    int wp = write_pos_;
    for (int i = 0; i < N_frames; i++) {
        pitch_buf_[wp] += output_buf_[i];
        if (++wp >= PITCH_BUF_SIZE) wp = 0;
    }
    // write_pos_ stays at write_pos + period_cnt (NOT advanced by N_frames)
    // This matches the DLL: write_pos = W + period_cnt, loop increments internally
}

// ─────────────────────────────────────────────────────────
// process — main audio callback
// ─────────────────────────────────────────────────────────
void DelayLamaDSP::process(float* out_L, float* out_R, int num_frames)
{
    for (int s = 0; s < num_frames; s++) {

        // ── Amplitude block update (every N_frames samples) ──
        if (block_ctr_ <= 0) {
            updateAmpBlock();
            // LCG update for voice_pos noise (Borland: state = state * 0x0019660D + 0x3C6EF35F)
            lcg_state_ = lcg_state_ * 0x0019660Du + 0x3C6EF35Fu;
            // voice_pos ≈ 5 ± small noise. Map LCG to [4.8, 5.2].
            float noise = ((float)(lcg_state_ >> 16) / 65535.f - 0.5f) * 0.4f;
            voice_pos_  = 5.f + noise;
            block_ctr_  = N_frames;
        }
        block_ctr_--;

        // ── Portamento ──
        // step = ±12 / ((p_portamento + 0.01) * sr)
        if (current_note_ != target_note_) {
            float port_rate = 12.f / ((p_portamento + 0.01f) * sr);
            if (current_note_ < target_note_) {
                current_note_ = std::min(current_note_ + port_rate, target_note_);
            } else {
                current_note_ = std::max(current_note_ - port_rate, target_note_);
            }
        }

        // ── Voice oscillator ──
        // voice_wt_pos wraps at 1024 (voice wavetable size)
        if (voice_wt_pos_ >= 1024.f) voice_wt_pos_ -= 1024.f;

        int wt_idx = (int)voice_wt_pos_ & (SIN_LUT_SIZE - 1);
        float voice_sample = (voice_pos_ + 0.2f) * voice_wt_[wt_idx];

        // Advance voice oscillator: (voice_pos*0.2 + 1.0) * amp_env * (sr/1024)
        voice_wt_pos_ += (voice_pos_ * 0.2f + 1.f) * amp_env_ * (sr / 1024.f);

        // ── Pitch → frequency → period ──
        float pitch = current_note_ + voice_sample;

        // freq_table index: trunc(pitch * 32), clamped to [0, 4095]
        int ft_idx = (int)(pitch * 32.f);
        if (ft_idx < 0)    ft_idx = 0;
        if (ft_idx > 4095) ft_idx = 4095;
        float freq_hz = freq_table_[ft_idx];

        // period in samples
        int new_period = (freq_hz > 0.f) ? (int)(sr / freq_hz) : 100;
        if (new_period < 1) new_period = 1;
        period_ = new_period;

        // ── Period counter → resonator trigger ──
        if (period_counter_ >= period_) {
            // Only trigger when note is on (amp_env > 0)
            if (amp_env_ > 0.f) {
                triggerResonator(p_vowel_sel);
            }
            pitchShift(period_counter_);
            period_counter_ = 0;
        }
        period_counter_++;

        // ── Output ──
        // Read from pitch_delay_buf at read_pos, then clear and advance.
        float samp = pitch_buf_[read_pos_];
        pitch_buf_[read_pos_] = 0.f;
        if (++read_pos_ >= PITCH_BUF_SIZE) read_pos_ = 0;

        // Note-scaling: (current_note * -0.01389 + 2.0) * volume
        float note_scale = current_note_ * -0.013888889f + 2.f;
        float mixed = samp * note_scale * p_volume;

        out_L[s] = mixed;
        out_R[s] = mixed;
    }
}
