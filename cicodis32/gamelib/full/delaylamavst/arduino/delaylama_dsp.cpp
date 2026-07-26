// delaylama_dsp.cpp
// Clean C++ reimplementation of the Delay Lama VST DSP engine.
//
// Constants confirmed from rdata binary:
//   MIDI0_Hz        = 8.175798916    (= 440/2^(69/12))
//   semitone_ratio  = 1.059463094    (= 2^(1/12))
//   freq_step       = 1/32           (freq_table index = pitch * 32)
//   K               = 1/50           (-> N_frames = trunc(sr/50) = 20ms)
//   decay_const     = 50*pi          (-> exp_win[k] = e^(-k*50*pi/sr))
//   delay_steps     = 13/20, 19/20, 5/4 (resonator exp_phase advance)
//   out_scale       = -1/72          (note scaling: note*(-1/72)+2)
//   port_range      = 12             (portamento +/-12 semitones/s)
//   port_add        = 1/100          (portamento denominator addend)
//   wt_scale        = 0.2            (voice oscillator amplitude)
//   amp_bias        = 5.0            (amp_env target when note on)
//   formant_scale   = 1279           (vowel_param * 1279 = vowel_idx)
//   kern_freq1      = 4950 Hz, step1 = 3.0
//   kern_freq2      = 3800 Hz, step2 = 18/5
//
// Precision: double for all intermediate arithmetic (matching the JS
// emulator's float64 FPU stack), float for stored tables and buffers
// (matching the DLL's float32 memory layout).

#include "delaylama_dsp.h"
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define DOUBLE float

static const DOUBLE TWO_PI       = 2.0 * M_PI;
static const DOUBLE MIDI0_HZ     = 440.0 / pow(2.0, 69.0 / 12.0);  // MIDI note 0 frequency
static const DOUBLE SEMITONE     = pow(2.0, 1.0 / 12.0);            // semitone frequency ratio
static const DOUBLE DECAY_CONST  = 50.0 * M_PI;                     // exponential decay rate
static constexpr DOUBLE KERN_F1      = 4950.0;
static constexpr DOUBLE KERN_F2      = 3800.0;
static constexpr DOUBLE KERN_STEP1   = 3.0;
static constexpr DOUBLE KERN_STEP2   = 18.0 / 5.0;

// Formant frequencies for 5 vowels (a, e, i, o, u approximate)
// F1: {280, 450, 800, 350, 270} Hz
// F2: {600, 800, 1150, 2000, 2140} Hz
// F3: {2240, 2830, 2900, 2800, 2950} Hz
static const float VOWEL_F1[5] = {280.f, 450.f,  800.f, 350.f,  270.f};
static const float VOWEL_F2[5] = {600.f, 800.f, 1150.f, 2000.f, 2140.f};
static const float VOWEL_F3[5] = {2240.f,2830.f, 2900.f, 2800.f, 2950.f};

// -----------------------------------------------------------------
// buildFormantTable
// Fills out[0..1279] by Hermite-interpolating between the 5 Hz values
// (4 segments x 320 samples each), approximating what the DLL's
// sub_10005350 (Horner-polynomial-FIR) produces at DC for each position.
// -----------------------------------------------------------------
void DelayLamaDSP::buildFormantTable(float* out, const float* hz)
{
    for (int seg = 0; seg < FORMANT_STEPS; seg++) {
        DOUBLE h0 = hz[seg];
        DOUBLE h1 = hz[seg + 1];
        // Hermite tangents (clamped at endpoints)
        DOUBLE t0 = (seg > 0)              ? 0.5*(hz[seg+1]-hz[seg-1]) : (h1-h0);
        DOUBLE t1 = (seg < FORMANT_STEPS-1)? 0.5*(hz[seg+2]-hz[seg])   : (h1-h0);
        for (int i = 0; i < FORMANT_SEG; i++) {
            DOUBLE u  = (DOUBLE)i / FORMANT_SEG;
            DOUBLE u2 = u*u, u3 = u2*u;
            // Cubic Hermite interpolation
            out[seg*FORMANT_SEG + i] = (float)(
                (2*u3 - 3*u2 + 1)*h0 + (u3 - 2*u2 + u)*t0 +
                (-2*u3 + 3*u2)*h1    + (u3 - u2)*t1);
        }
    }
}

// -----------------------------------------------------------------
// buildTables -- called once from init()
// -----------------------------------------------------------------
void DelayLamaDSP::buildTables()
{
    // sin_lut / voice_wt: one full cycle sin(k * 2*pi/1024)
    // DLL sub_100048d0: fild32(i) * 2*pi / 1024, fsin(), fstp32
    // [esi+0x64b8] = pointer to 1024-entry table; [esi+0x64bc] = 1024 (wrap size)
    //sin_lut_  = new float[SIN_LUT_SIZE];
    //voice_wt_ = new float[SIN_LUT_SIZE];
    for (int k = 0; k < SIN_LUT_SIZE; k++) {
        float v = (float)sin(k * TWO_PI / SIN_LUT_SIZE);
        sin_lut_[k] = v;
        voice_wt_[k] = v;
    }

    // freq_table[k] = MIDI0_Hz * (2^(1/12))^(k/32)
    // Accessed as: freq = freq_table[trunc(pitch * 32)]
    // pitch = current_note + voice_sample (in MIDI note units)
    for (int k = 0; k < 4096; k++)
        freq_table_[k] = (float)(MIDI0_HZ * pow(SEMITONE, (DOUBLE)k / 32.0));

    // exp_win[k] = e^(-k * 50*pi / sr)
    // Size = N_frames * 4 (resonator phase can reach up to N_frames * max_step)
    int exp_size = N_frames * 4;
    //exp_win_ = new float[exp_size];
    for (int k = 0; k < exp_size; k++)
        exp_win_[k] = (float)exp(-(DOUBLE)k * DECAY_CONST / sr);

    // ampl_buf: piecewise window from DLL sub_100048d0 (NOT a Hann window)
    // rdata constants: rise_K=0x1000baf8, fade_start_K=0x1000baf0, fade_K=0x1000bae8
    // Structure: rise (fast ~79-sample cosine ramp), flat (1.0), fade (slow ~308-sample cosine ramp)
    int rise_len   = (int)(sr * 9.f / 5000.f);    // ~79 at 44100 Hz
    int fade_start = (int)(sr * 13.f / 1000.f);   // ~573 at 44100 Hz
    int fade_len   = (int)(sr * 7.f / 1000.f);    // ~308 at 44100 Hz
    //ampl_buf_ = new float[N_frames];
    for (int k = 0; k < N_frames; k++) ampl_buf_[k] = 1.0f;
    for (int k = 0; k < rise_len && k < N_frames; k++)
        ampl_buf_[k] = (float)(0.5 * (1.0 - cos((DOUBLE)k * M_PI / rise_len)));
    for (int k = fade_start; k < N_frames; k++)
        ampl_buf_[k] = (float)(0.5 * (1.0 - cos((DOUBLE)(fade_len + k) * M_PI / fade_len)));

    // kern_buf[k] = sin(k*2*pi*4950/sr)*exp_win[trunc(k*3.0)]
    //             + sin(k*2*pi*3800/sr)*exp_win[trunc(k*3.6)]
    //kern_buf_ = new float[N_frames];
    int exp_cap = exp_size - 1;
    for (int k = 0; k < N_frames; k++) {
        int idx1 = std::min((int)(k * KERN_STEP1), exp_cap);
        int idx2 = std::min((int)(k * KERN_STEP2), exp_cap);
        DOUBLE s1 = sin(k * TWO_PI * KERN_F1 / sr) * exp_win_[idx1];
        DOUBLE s2 = sin(k * TWO_PI * KERN_F2 / sr) * exp_win_[idx2];
        kern_buf_[k] = (float)(s1 + s2);
    }

    // Formant tables: 1280 Hz values across 5 vowel positions
    //formant_F1_ = new float[FORMANT_SIZE];
    //formant_F2_ = new float[FORMANT_SIZE];
    //formant_F3_ = new float[FORMANT_SIZE];
    buildFormantTable(formant_F1_, VOWEL_F1);
    buildFormantTable(formant_F2_, VOWEL_F2);
    buildFormantTable(formant_F3_, VOWEL_F3);

    //output_buf_ = new float[N_frames]();
    //fb_A_ = new float[FB_BUF_SIZE]();
    //fb_B_ = new float[FB_BUF_SIZE]();
}

// -----------------------------------------------------------------
// init
// -----------------------------------------------------------------
void DelayLamaDSP::init(float sample_rate)
{
    //sr       = sample_rate;
    //N_frames = (int)(sr / 50.f);     // 20 ms frame size (= 882 at 44100 Hz)

    cleanup();
    buildTables();

    memset(pitch_buf_, 0, sizeof(pitch_buf_));
    write_pos_      = 0;
    read_pos_       = 0;

    // IIR feedback buffer indices (from DLL sub_100048d0 init)
    // read_A = trunc(sr * -0.309592) mod 20000 -> 6347 at 44100 Hz
    // read_B = trunc(sr * -0.398435) mod 20000 -> 2429 at 44100 Hz
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
    current_note_   = 0.f;
    target_note_    = 0.f;
    amp_env_        = 0.f;
    amp_target_     = 0.f;
    voice_phase_    = 0.f;
    voice_pos_      = 4.f;                        // DLL [esi+0x615c]=0x40800000=4.0
    sr_div_1024_    = sr / (float)SIN_LUT_SIZE;   // DLL [esi+0x6168] precomputed
    period_counter_ = 0;
    period_         = (int)(sr * 104.f / 1000.f); // DLL [esi+0x616c] = 4586 at 44100 Hz
    block_counter_  = 0;
    new_period_     = 100;
    block_ctr_      = (int)(sr * 104.f / 1000.f); // ~4586 samples at 44100 Hz
    lcg_state_      = 0u;                          // DLL heap zero-initialized
}

// -----------------------------------------------------------------
// cleanup
// -----------------------------------------------------------------
void DelayLamaDSP::cleanup()
{
  /*
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
    */
}

// -----------------------------------------------------------------
// setParameter
//   0: volume  (0..1)
//   1: vowel   (0..1 -- selects formant position)
//   2: portamento speed  (0..1)
//   3: vowel depth / resonator amplitude  (0..1)
//   4: IIR feedback coefficient  (0..1)
// -----------------------------------------------------------------
void DelayLamaDSP::setParameter(int idx, float value)
{
    switch (idx) {
        case 0: p_volume      = value; break;
        case 1: {
        int newVowel = (int)(value * (FORMANT_SIZE+1));
        if (newVowel >= FORMANT_SIZE)
          newVowel = FORMANT_SIZE-1;
        if (newVowel < 0)
          newVowel = 0;
        
        if (newVowel != p_vowel_sel)
        {
          p_vowel_sel   = newVowel;
          p_vowel_changed = true;
          }
        break;
        }
        case 2: p_portamento  = value; break;
        case 3: p_vowel_depth = value; break;
        case 4: p_feedback    = value; break;
    }
}

// -----------------------------------------------------------------
// noteOn / noteOff
// -----------------------------------------------------------------
void DelayLamaDSP::noteOn(int midi_note, int /*velocity*/)
{
    // DLL stores internal_note = midi_note - 12 (see sub_10006240: ebx -= 0x0C)
    target_note_ = (float)(midi_note - 12);
    if (!note_on_)
        current_note_ = target_note_;  // no portamento on first note
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

// -----------------------------------------------------------------
// updateAmpBlock -- called every block_ctr_ samples.
// In the DLL this calls a vtable function that returns the current
// envelope value; we approximate with linear ramp.
// -----------------------------------------------------------------
void DelayLamaDSP::updateAmpBlock()
{
    float rate = (float)((DOUBLE)N_frames / sr * 10.0);
    if (amp_env_ < amp_target_)
        amp_env_ = std::min(amp_env_ + rate, amp_target_);
    else
        amp_env_ = std::max(amp_env_ - rate, amp_target_);
}

// -----------------------------------------------------------------
// triggerResonator -- fills output_buf_[0..N_frames-1] with
// 3-resonator formant output. Matches DLL sub_10005fb0:
//
// Each resonator (r=0,1,2):
//   sin_phase indexes sin_lut (wraps at 1024), advances by amp_step[r]
//   exp_phase indexes exp_win (monotonic),     advances by DELAY_STEP[r]
//   sample = sin_lut[trunc(sin_phase)] * exp_win[trunc(exp_phase)]
//
// DLL stores output_buf as float32 after EACH resonator (reload-add-store).
// amp_step computed through float32 intermediates matching DLL chain.
// sin_phase/exp_phase kept in DOUBLE (x87 FPU registers in original DLL).
//
// Confirmed from sub_10005fb0:
//   sin_lut index via fldst(2)/sub_1000a75c(); advance via faddpst(3); wrap at 1024
//   exp_win index via fldst(5)/sub_1000a75c(); advance via fadd32([0x639c])
// -----------------------------------------------------------------
void DelayLamaDSP::triggerResonator(int vowel_idx)
{
    // Compute vowel index: trunc(vowel_param * 1279)
    // DLL uses [esi+0xb4] * 1279 for the formant table index
    if (vowel_idx < 0) vowel_idx = 0;
    if (vowel_idx >= FORMANT_SIZE) vowel_idx = FORMANT_SIZE - 1;

    // vowel_pos = [esi+0xc4] * 0.5 + 0.75
    // confirmed: 0x1000ba78=0.5 (f64), 0x1000bb70=0.75 (f64)
    // e.g. preset 0: [esi+0xc4]=0.5 -> vowel_pos=1.0
    float vowel_pos_f32 = (float)((DOUBLE)p_vowel_depth / 2.0 + 3.0 / 4.0);
    float inv_sr_1024_f32 = (float)((DOUBLE)SIN_LUT_SIZE / sr);

    // amp_step = vowel_pos * formant_Hz * (1024/sr)
    // float32 intermediate chain matching DLL fstp32/fld32 round-trips
    float amp_step_f32[3];
    amp_step_f32[0] = (float)((DOUBLE)vowel_pos_f32 * (DOUBLE)formant_F1_[vowel_idx]) * inv_sr_1024_f32;
    amp_step_f32[1] = (float)((DOUBLE)vowel_pos_f32 * (DOUBLE)formant_F2_[vowel_idx]) * inv_sr_1024_f32;
    amp_step_f32[2] = (float)((DOUBLE)vowel_pos_f32 * (DOUBLE)formant_F3_[vowel_idx]) * inv_sr_1024_f32;

    // Delay steps confirmed from rdata at [esi+0x639c/63a0/63a4]:
    // 32.5*0.02=0.65, 47.5*0.02=0.95, 62.5*0.02=1.25
    static constexpr float DELAY_STEP_F32[3] = {13.f/20.f, 19.f/20.f, 5.f/4.f};

    DOUBLE sin_phase[3] = {0.0, 0.0, 0.0};
    DOUBLE exp_phase[3] = {0.0, 0.0, 0.0};

    int exp_cap = N_frames * 4 - 1;

    for (int i = 0; i < N_frames; i++) {
        // Resonator 0: direct store (not add)
        {
            int sl_idx = (int)sin_phase[0] & (SIN_LUT_SIZE - 1);
            int ep_idx = (int)exp_phase[0]; if (ep_idx > exp_cap) ep_idx = exp_cap;
            output_buf_[i] = (float)((DOUBLE)sin_lut_[sl_idx] * (DOUBLE)exp_win_[ep_idx]);
            exp_phase[0] += (DOUBLE)DELAY_STEP_F32[0];
            sin_phase[0] += (DOUBLE)amp_step_f32[0];
            if (sin_phase[0] >= 1024.0) sin_phase[0] -= 1024.0;
        }
        // Resonator 1: reload float32, add, store float32
        {
            int sl_idx = (int)sin_phase[1] & (SIN_LUT_SIZE - 1);
            int ep_idx = (int)exp_phase[1]; if (ep_idx > exp_cap) ep_idx = exp_cap;
            output_buf_[i] = (float)((DOUBLE)output_buf_[i] + (DOUBLE)sin_lut_[sl_idx] * (DOUBLE)exp_win_[ep_idx]);
            exp_phase[1] += (DOUBLE)DELAY_STEP_F32[1];
            sin_phase[1] += (DOUBLE)amp_step_f32[1];
            if (sin_phase[1] >= 1024.0) sin_phase[1] -= 1024.0;
        }
        // Resonator 2: reload float32, add, store float32
        {
            int sl_idx = (int)sin_phase[2] & (SIN_LUT_SIZE - 1);
            int ep_idx = (int)exp_phase[2]; if (ep_idx > exp_cap) ep_idx = exp_cap;
            output_buf_[i] = (float)((DOUBLE)output_buf_[i] + (DOUBLE)sin_lut_[sl_idx] * (DOUBLE)exp_win_[ep_idx]);
            exp_phase[2] += (DOUBLE)DELAY_STEP_F32[2];
            sin_phase[2] += (DOUBLE)amp_step_f32[2];
            if (sin_phase[2] >= 1024.0) sin_phase[2] -= 1024.0;
        }

        // Add kernel contribution (4950+3800 Hz windowed sinusoids)
        // DLL applies *0.5 here (0x1000ba78 = 0.5)
        output_buf_[i] = (float)((DOUBLE)kern_buf_[i] * 0.5 + (DOUBLE)output_buf_[i]);

        // Apply amplitude window
        output_buf_[i] = (float)((DOUBLE)ampl_buf_[i] * (DOUBLE)output_buf_[i]);
    }
}

// -----------------------------------------------------------------
// pitchShift -- accumulates output_buf_ into pitch_buf_ starting at
// write_pos + period_cnt (circular, size 10240).
// Mirrors sub_10005eb0 in the original DLL.
// DLL sub_10005eb0: loop increments write_pos N_frames times,
// then exit code subtracts N_frames -> net advance = period_cnt only.
// -----------------------------------------------------------------
void DelayLamaDSP::pitchShift(int period_cnt)
{
    write_pos_ = (write_pos_ + period_cnt) % PITCH_BUF_SIZE;
    if (write_pos_ < 0) write_pos_ += PITCH_BUF_SIZE;

    int wp = write_pos_;
    for (int i = 0; i < N_frames; i++) {
        pitch_buf_[wp] = (float)((DOUBLE)pitch_buf_[wp] + (DOUBLE)output_buf_[i]);
        if (++wp >= PITCH_BUF_SIZE) wp = 0;
    }
}

// -----------------------------------------------------------------
// process -- main audio callback
//
// Mirrors the DLL's sub_100054c0 two-pass structure:
//   FIRST LOOP  (num_frames iterations): trigger logic, writes to pitch_buf_
//   SECOND LOOP (num_frames iterations): reads pitch_buf_, generates output
//
// Two separate counters (confirmed from DLL field map):
//   period_counter [esi+0x6170]: counts up to period [esi+0x616c] -> LCG update
//   block_counter  [esi+0x6388]: counts up to new_period [esi+0x637c] -> pitchShift
//
// force_trigger [esi+0x6142]=1 at note-on causes pitchShift(0) at sample 0,
// pre-filling pitch_buf_[0..N_frames-1]. triggerResonator is called ONLY
// when force_trigger is set; normal period triggers reuse existing output_buf_.
// After note-off: no triggers; pitch_buf_ drains to silence; IIR echoes continue.
// -----------------------------------------------------------------
void DelayLamaDSP::process(float* out_L, float* out_R, int num_frames)
{
    // -- FIRST PASS --
    for (int s = 0; s < num_frames; s++) {

        // Amplitude block update
        if (block_ctr_ <= 0) {
            updateAmpBlock();
            block_ctr_ = (int)(sr * 104.f / 1000.f);
        }
        block_ctr_--;

        // Portamento: smooth current_note toward target_note
        if (current_note_ != target_note_) {
            float port_rate = (float)(12.0 / ((DOUBLE)p_portamento + 1.0/100.0) / sr);
            if (current_note_ < target_note_)
                current_note_ = std::min(current_note_ + port_rate, target_note_);
            else
                current_note_ = std::max(current_note_ - port_rate, target_note_);
        }

        if (note_on_) {
            // DLL copies current_note to voice_wt_pos each sample (temp for pitch calc)
            float voice_wt_pos = current_note_;

            // Voice phase wrap at 1024
            if (voice_phase_ >= 1024.f)
                voice_phase_ -= 1024.f;

            // LCG update when period_counter >= period
            // LCG (Borland): state = state * 0x0019660D + 0x3C6EF35F
            // DLL sub_10006400: fild32(state) * (1/2^32), caller DOUBLEs + adds 5.0
            // voice_pos = 2 * ((int32_t)state / 2^32) + 5.0  in [4.0, 6.0)
            if (period_counter_ >= period_) {
                period_counter_ = 0;
                lcg_state_ = lcg_state_ * 0x0019660Du + 0x3C6EF35Fu;
                voice_pos_ = (float)(2.0 * ((int32_t)lcg_state_ / 4294967296.0) + 5.0);
            }

            // Voice wavetable sample: voice_sample = 0.2 * voice_wt[trunc(phase)]
            int wt_idx = (int)voice_phase_;
            float voice_sample = (float)(0.2 * (DOUBLE)voice_wt_[wt_idx]);

            // Voice phase advance: voice_pos / (sr / 1024)
            voice_phase_ = (float)((DOUBLE)voice_phase_ +
                            (DOUBLE)voice_pos_ / (DOUBLE)sr_div_1024_);

            // Pitch = voice_sample + current_note (in internal MIDI space, -12 from input)
            // current_note 48 -> index 1536 -> 130.8 Hz (C3) -> period 337
            DOUBLE pitch_dbl = (DOUBLE)voice_sample + (DOUBLE)voice_wt_pos;

            // Freq table lookup via pitch * -32 (DLL uses negative indexing from table end)
            int ft_neg_idx = (int)(pitch_dbl * -32.0);
            int ft_idx = -ft_neg_idx;
            if (ft_idx < 0)    ft_idx = 0;
            if (ft_idx > 4095) ft_idx = 4095;

            float freq_hz = freq_table_[ft_idx];
            new_period_ = (freq_hz > 0.f) ? (int)((DOUBLE)sr / (DOUBLE)freq_hz) : 100;

            // Trigger: block_counter >= new_period, or force_trigger at note-on
            bool do_trigger = false;
            if (block_counter_ >= new_period_) {
                do_trigger = true;
            } else if (force_trigger_) {
                do_trigger = true;
            } 

            if (do_trigger) {
                if (force_trigger_ || p_vowel_changed) {
                    triggerResonator(p_vowel_sel);
                    p_vowel_changed = false;
                }
                pitchShift(block_counter_);
                block_counter_ = 0;
                force_trigger_ = false;
                p_vowel_changed = false;
            }

            // End-of-sample increments (both counters)
            period_counter_++;
            block_counter_++;
        }
    }

    // -- SECOND PASS: read pitch_buf_, apply IIR feedback, generate output --
    // note_scale = current_note * (-1/72) + 2.0
    float note_scale_f32 = (float)((DOUBLE)current_note_ * (-1.0 / 72.0) + 2.0);

    for (int s = 0; s < num_frames; s++) {
        DOUBLE a_val = (DOUBLE)fb_A_[read_A_fb_];
        DOUBLE b_val = (DOUBLE)fb_B_[read_B_fb_];
        DOUBLE pval  = (DOUBLE)pitch_buf_[read_pos_];

        // IIR update: buf[write] = (buf[read]*0.5 + pitch_buf) * feedback
        fb_A_[write_fb_] = (float)((a_val * 0.5 + pval) * (DOUBLE)p_feedback);
        fb_B_[write_fb_] = (float)((b_val * 0.5 + pval) * (DOUBLE)p_feedback);
        if (++write_fb_ >= FB_BUF_SIZE) write_fb_ = 0;

        // Output: (pitch_buf + feedback) * note_scale * 0.1
        out_L[s] = (float)(((pval + a_val) * (DOUBLE)note_scale_f32) * 0.1);
        out_R[s] = (float)(((pval + b_val) * (DOUBLE)note_scale_f32) * 0.1);

        // Clear pitch_buf slot and advance read position
        pitch_buf_[read_pos_] = 0.f;
        if (++read_pos_ >= PITCH_BUF_SIZE) read_pos_ = 0;

        // Advance feedback read indices
        if (++read_A_fb_ >= FB_BUF_SIZE) read_A_fb_ = 0;
        if (++read_B_fb_ >= FB_BUF_SIZE) read_B_fb_ = 0;
    }
}
