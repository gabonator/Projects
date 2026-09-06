// DDX10 — Compact C++ FM Synthesizer DSP
// Reverse-engineered from ddx10.dll (double-precision mda DX10 variant)
// 32-voice polyphonic, 2-operator FM with polynomial waveshaping
#pragma once
#include <cmath>
#include <cstring>
#include <cstdint>
#include <cstdio>
#include <algorithm>

struct DDX10 {
    static constexpr int NVOICES = 32;
    static constexpr double SILENCE = 3e-4;

    struct Voice {
        double env;    // modulation envelope level
        double car;    // carrier oscillator coeff = 2*cos(w)
        double cdr;    // carrier y[n-1]
        double cdr2;   // carrier y[n-2]
        double menv;   // modulator envelope (one-pole smoothed)
        double mdec;   // modulator envelope target
        double mlev;   // modulator envelope rate
        double mod;    // modulator phase accumulator
        double dmod;   // modulator frequency increment
        double cenv;   // carrier envelope (one-pole tracking)
        double catt;   // carrier envelope rate
        double mmod;   // mod envelope decay/release multiplier
        int32_t note;  // MIDI note (0x78 = free)
    };

    // Voices
    Voice voice[NVOICES];

    // Preset (17 floats + 24-char name = 0x60 bytes)
    struct Preset {
        float param[17];
        char name[24];
        char _pad[4];
    };
    enum { // param indices
        pAttack, pDecay, pRelease,          // 0-2: mod envelope
        pCoarse, pFine, pModInit,           // 3-5: FM ratio + mod depth
        pModDec, pModSus, pModRel,          // 6-8: mod envelope targets
        pModVel, pVibrato, pOctave,         // 9-11: velocity, vibrato, octave
        pFineTune, pWaveform, pModThru,     // 12-14: fine tune, richness, mod mix
        pLFORate, pVolume                   // 15-16: LFO, volume
    };

    // Global coefficients
    double modFreqScale;   // base pitch (tune * iFs)
    double modRatio;       // coarse carrier ratio (floored integer)
    double modInitLevel;   // (cos(fine) + modRatio) * pi/2
    double modCoarse;      // ModInit^2 * 2e-4 (initial mod depth)
    double modFine;        // ModSus^2 * 2e-4 (sustain mod depth)
    double modVelocity;    // velocity sensitivity
    double vibBase;        // vibrato base depth
    double modAttack;      // mod env attack rate
    double modDecay;       // mod env decay rate
    double modRelease;     // mod env release rate
    double ampAttack;      // amp env attack rate
    double ampRelease;     // amp env release rate
    double rich;           // waveshaping: 0.5 - 3*Waveform^2
    double modmix;         // carrier mix-through: ModThru^2 * 0.25
    double vibRate;        // LFO rate coefficient
    double masterVolume;   // output volume
    double vibI, vibQ;     // quadrature LFO state
    double vibDepth;       // current LFO output
    double pitchBend;      // pitch bend multiplier (default 1.0)
    double modWheelDepth;  // from CC1 (mod wheel)
    double lfoDepth;       // from CC7 / init (default 0.0035)
    float sampleRate;
    int sustainPedal;
    int activeVoices;
    int lfoCounter;

    // MIDI event queue (triplets: deltaFrames, note, velocity)
    static constexpr int MIDI_QUEUE_SIZE = 128;
    int midiQueue[MIDI_QUEUE_SIZE * 3 + 1]; // sentinel at end
    int midiQueueLen;

    // Preset bank
    static constexpr int NUM_PRESETS = 99;
    Preset presets[NUM_PRESETS];
    int currentProgram;

    void init(float sr = 44100.f) {
        sampleRate = sr;
        pitchBend = 1.0;
        vibI = 1.0;
        vibQ = 0.0;
        vibDepth = 0.0;
        modWheelDepth = 0.0;
        lfoDepth = 0.0035;
        sustainPedal = 0;
        activeVoices = 0;
        lfoCounter = 0;
        midiQueueLen = 0;
        currentProgram = 0;
        memset(voice, 0, sizeof(voice));
        for (auto& v : voice) { v.note = 0x78; }
        initPresets();
        update();
    }

    // Compute DSP coefficients from current preset
    void update() {
        const float* p = presets[currentProgram].param;
        double iFs = 1.0 / sampleRate;

        // Octave / base pitch
        modFreqScale = pow(2.0, floor(p[pOctave] * 6.9) - 2.0) * 8.175799 * iFs;

        // Coarse ratio
        modRatio = floor(p[pCoarse] * p[pCoarse] * 41.01);

        // Fine ratio → affects carrier angular freq
        double cosFine = cos((double)p[pFine]);
        modInitLevel = (cosFine + modRatio) * (M_PI / 2.0);

        // Modulation depth (initial and sustain)
        modCoarse = p[pModInit] * p[pModInit] * 2e-4;
        modFine   = p[pModSus] * p[pModSus] * 2e-4;

        // Velocity sensitivity
        modVelocity = p[pModVel];

        // Vibrato base depth
        vibBase = p[pVibrato] * p[pVibrato] * 1e-3;

        // Mod envelope rates (double-exponential mapping)
        modAttack  = 1.0 - exp(-exp(8.0 * (1.0 - p[pAttack])) * iFs);
        modDecay   = (p[pDecay] > 0.98) ? 1.0
                     : exp(-exp(5.0 - p[pDecay] * 8.0) * iFs);
        modRelease = exp(-exp(5.0 * (1.0 - p[pRelease])) * iFs);

        // Amp envelope rates
        ampAttack  = 1.0 - exp(-exp(6.0 - p[pModDec] * 7.0) * iFs);
        ampRelease = 1.0 - exp(-exp(5.0 - p[pModRel] * 8.0) * iFs);

        // Waveshaping
        rich   = 0.5 - 3.0 * p[pWaveform] * p[pWaveform];
        modmix = 0.25 * p[pModThru] * p[pModThru];

        // LFO rate
        vibRate = iFs * 628.3 * 25.0 * p[pLFORate] * p[pLFORate];

        // Master volume
        masterVolume = p[pVolume] * p[pVolume];
    }

    // Set program and recompute
    void setProgram(int idx) {
        if (idx < 0) idx = 0;
        if (idx > NUM_PRESETS - 1) idx = NUM_PRESETS - 1;
        currentProgram = idx;
        update();
    }

    // Queue a MIDI event for sample-accurate processing
    void queueMidi(int deltaFrames, int note, int velocity) {
        if (midiQueueLen >= MIDI_QUEUE_SIZE) return;
        int i = midiQueueLen * 3;
        midiQueue[i]     = deltaFrames;
        midiQueue[i + 1] = note;
        midiQueue[i + 2] = velocity;
        midiQueueLen++;
    }

    void noteOn(int note, int velocity, int delta = 0) {
        queueMidi(delta, note & 0x7F, velocity & 0x7F);
    }

    void noteOff(int note, int delta = 0) {
        queueMidi(delta, (note & 0x7F) | 0x80, 0);
    }

    void controlChange(int cc, int value) {
        double v2 = (double)(value * value);
        switch (cc) {
            case 1:   modWheelDepth = v2 * 5e-8; break;      // mod wheel
            case 7:   lfoDepth = v2 * 3.5e-7; break;         // data entry
            case 64:  // sustain pedal
                sustainPedal = value & 0x40;
                if (!sustainPedal) {
                    // release all sustained notes
                    for (auto& v : voice) {
                        if (v.note == 0x80) releaseVoice(v);
                    }
                }
                break;
            default:
                if (cc >= 0x7B) allNotesOff();
                break;
        }
    }

    void setPitchBend(int lsb, int msb) {
        double bend = (double)((msb - 64) * 128 + lsb);
        if (bend > 0)
            pitchBend = 1.0 + bend * 1.4951e-5;
        else
            pitchBend = 1.0 + bend * 1.3318e-5;
    }

    // Main audio processing
    void processReplacing(float* outL, float* outR, int sampleFrames) {
        if (activeVoices == 0 && midiQueueLen == 0) {
            memset(outL, 0, sampleFrames * sizeof(float));
            memset(outR, 0, sampleFrames * sizeof(float));
            return;
        }

        // Sort MIDI events by deltaFrames (simple insertion sort)
        for (int i = 1; i < midiQueueLen; i++) {
            int j = i;
            while (j > 0 && midiQueue[j*3] < midiQueue[(j-1)*3]) {
                for (int k = 0; k < 3; k++)
                    std::swap(midiQueue[j*3+k], midiQueue[(j-1)*3+k]);
                j--;
            }
        }

        int event = 0;
        int frame = 0;

        while (frame < sampleFrames) {
            // Determine how many frames until next MIDI event
            int frames;
            if (event < midiQueueLen)
                frames = midiQueue[event * 3];
            else
                frames = sampleFrames;
            if (frames > sampleFrames) frames = sampleFrames;
            frames -= frame;

            // Process audio block
            for (int s = 0; s < frames; s++) {
                double o = 0.0;

                // LFO update (every 100 samples)
                if (--lfoCounter < 0) {
                    lfoCounter = 100;
                    double oldI = vibI;
                    vibQ = oldI * vibRate + vibQ;
                    vibI = oldI - vibQ * vibRate;
                    vibDepth = (vibBase + modWheelDepth) * vibI;
                }

                // Process all voices
                for (int i = 0; i < NVOICES; i++) {
                    Voice& v = voice[i];
                    double e = v.env;
                    if (e <= SILENCE) continue;

                    // Mod envelope decay
                    v.env = e * v.mmod;

                    // Carrier envelope (one-pole tracking mod env)
                    v.cenv += v.catt * (e - v.cenv);

                    // Coupled-form carrier oscillator
                    double x = v.car * v.cdr - v.cdr2;
                    v.cdr2 = v.cdr;
                    v.cdr = x;

                    // Modulator envelope smoothing (one-pole)
                    v.menv += v.mlev * (v.mdec - v.menv);

                    // Phase accumulation with carrier feedback + vibrato
                    double p = v.dmod + v.mod + v.menv * x + vibDepth;

                    // Wrap phase to [-1, 1]
                    while (p >  1.0) p -= 2.0;
                    while (p < -1.0) p += 2.0;
                    v.mod = p;

                    // Polynomial waveshaping
                    double p3 = p * p * p;
                    double shaped = p + (p * p * rich - 1.0 - rich) * p3;

                    // Output: carrier env * (shaped wave + prev carrier * modmix)
                    o += v.cenv * (shaped + v.cdr2 * modmix);
                }

                float out = (float)(o * masterVolume);
                outL[frame + s] = out;
                outR[frame + s] = out;
            }

            frame += frames;

            // Process MIDI event at this frame position
            if (event < midiQueueLen) {
                int note = midiQueue[event * 3 + 1];
                int vel  = midiQueue[event * 3 + 2];
                if (note & 0x80) {
                    // Note off
                    doNoteOff(note & 0x7F);
                } else if (vel > 0) {
                    // Note on
                    doNoteOn(note, vel);
                } else {
                    // Velocity 0 = note off
                    doNoteOff(note);
                }
                event++;
            }
        }

        // Post-processing: count active voices, flush denormals
        activeVoices = 0;
        for (auto& v : voice) {
            if (v.env > SILENCE) {
                activeVoices++;
            } else {
                v.env = v.cenv = SILENCE;
            }
            if (v.menv < SILENCE) {
                v.menv = v.mdec = SILENCE;
            }
        }

        midiQueueLen = 0;
    }

private:
    // Find quietest voice for stealing
    int findQuietestVoice() {
        int best = 0;
        double bestLevel = voice[0].env;
        for (int i = 1; i < NVOICES; i++) {
            if (voice[i].env < bestLevel) {
                bestLevel = voice[i].env;
                best = i;
            }
        }
        return best;
    }

    void doNoteOn(int note, int velocity) {
        int idx = findQuietestVoice();
        Voice& v = voice[idx];

        const float* p = presets[currentProgram].param;

        // Carrier base frequency
        double rawFreq = exp(((double)note + 2.0 * p[pFineTune] - 1.0) * (M_LN2 / 12.0));
        if (rawFreq > 50.0) rawFreq = 50.0;

        // Velocity scaling
        double velFactor = ((velocity - 64.0) * modVelocity + 64.0) * rawFreq;

        // Modulator frequency
        v.dmod = pitchBend * modFreqScale * rawFreq;

        // Modulator phase reset
        v.mod = 0.0;

        // Modulator envelope (initial depth → sustain depth)
        v.menv = modCoarse * velFactor;
        v.mdec = modFine * velFactor;
        v.mlev = ampAttack;

        // Carrier oscillator init: coupled-form at angular freq w0
        double w0 = modInitLevel * v.dmod;
        v.car  = 2.0 * cos(w0);
        v.cdr  = 0.0;
        v.cdr2 = sin(w0);

        // Carrier envelope
        v.cenv = 0.0;
        v.catt = modAttack;

        // Mod envelope
        v.env  = (velocity + 10.0) * (1.5 - p[pWaveform]) * lfoDepth;
        v.mmod = modDecay;

        // Note
        v.note = note;
    }

    void doNoteOff(int note) {
        for (auto& v : voice) {
            if (v.note != note) continue;
            if (sustainPedal) {
                v.note = 0x80; // defer release
            } else {
                releaseVoice(v);
            }
        }
    }

    void releaseVoice(Voice& v) {
        v.mmod = modRelease;
        v.env  = v.cenv;
        v.catt = 0.0;
        v.mdec = 0.0;
        v.mlev = ampRelease;
        v.note = 0x78; // free
    }

    void allNotesOff() {
        for (auto& v : voice) {
            v.env = 0.0;
            v.cenv = 0.0;
        }
        sustainPedal = 0;
        activeVoices = 0;
    }

    // Presets recovered from ddx10.dll binary
    void initPresets() {
        struct { const char* name; float p[17]; } bank[] = {
          {"Bright E.Piano", {0.000f,0.650f,0.441f,0.842f,0.329f,0.230f,0.800f,0.050f,0.800f,0.900f,0.000f,0.500f,0.500f,0.447f,0.000f,0.414f,1.000f}},
          {"Jazz E.Piano",   {0.000f,0.500f,0.100f,0.671f,0.000f,0.441f,0.336f,0.243f,0.800f,0.500f,0.000f,0.500f,0.500f,0.178f,0.000f,0.500f,1.000f}},
          {"E.Piano Pad",    {0.000f,0.700f,0.400f,0.230f,0.184f,0.270f,0.474f,0.224f,0.800f,0.974f,0.250f,0.500f,0.500f,0.428f,0.836f,0.500f,1.000f}},
          {"Fuzzy E.Piano",  {0.000f,0.700f,0.400f,0.320f,0.217f,0.599f,0.670f,0.309f,0.800f,0.500f,0.263f,0.507f,0.500f,0.276f,0.638f,0.526f,1.000f}},
          {"Soft Chimes",    {0.400f,0.600f,0.650f,0.760f,0.000f,0.390f,0.250f,0.160f,0.900f,0.500f,0.362f,0.500f,0.500f,0.401f,0.296f,0.493f,1.000f}},
          {"Harpsichord",    {0.000f,0.342f,0.000f,0.280f,0.000f,0.880f,0.100f,0.408f,0.740f,0.000f,0.000f,0.600f,0.500f,0.842f,0.651f,0.500f,1.000f}},
          {"Funk Clav",      {0.000f,0.400f,0.100f,0.360f,0.000f,0.875f,0.160f,0.592f,0.800f,0.500f,0.000f,0.500f,0.500f,0.303f,0.868f,0.500f,1.000f}},
          {"Sitar",          {0.000f,0.500f,0.704f,0.230f,0.000f,0.151f,0.750f,0.493f,0.770f,0.500f,0.000f,0.400f,0.500f,0.421f,0.632f,0.500f,1.000f}},
          {"Chiff Organ",    {0.600f,0.990f,0.400f,0.320f,0.283f,0.570f,0.300f,0.050f,0.240f,0.500f,0.138f,0.500f,0.500f,0.283f,0.822f,0.500f,1.000f}},
          {"Tinkle",         {0.000f,0.500f,0.650f,0.368f,0.651f,0.395f,0.550f,0.257f,0.900f,0.500f,0.300f,0.800f,0.500f,0.000f,0.414f,0.500f,1.000f}},
          {"Space Pad",      {0.000f,0.700f,0.520f,0.230f,0.197f,0.520f,0.720f,0.280f,0.730f,0.500f,0.250f,0.500f,0.500f,0.336f,0.428f,0.500f,1.000f}},
          {"Koto",           {0.000f,0.240f,0.000f,0.390f,0.000f,0.880f,0.100f,0.600f,0.740f,0.500f,0.000f,0.500f,0.500f,0.526f,0.480f,0.500f,1.000f}},
          {"Harp",           {0.000f,0.500f,0.700f,0.160f,0.000f,0.158f,0.349f,0.000f,0.280f,0.900f,0.000f,0.618f,0.500f,0.401f,0.000f,0.500f,1.000f}},
          {"Jazz Guitar",    {0.000f,0.500f,0.100f,0.390f,0.000f,0.490f,0.250f,0.250f,0.800f,0.500f,0.000f,0.500f,0.500f,0.263f,0.145f,0.500f,1.000f}},
          {"Steel Drum",     {0.000f,0.300f,0.507f,0.480f,0.730f,0.000f,0.100f,0.303f,0.730f,1.000f,0.000f,0.600f,0.500f,0.579f,0.000f,0.500f,1.000f}},
          {"Log Drum",       {0.000f,0.300f,0.500f,0.320f,0.000f,0.467f,0.079f,0.158f,0.500f,0.500f,0.000f,0.400f,0.500f,0.151f,0.020f,0.500f,1.000f}},
          {"Trumpet",        {0.000f,0.990f,0.100f,0.230f,0.000f,0.000f,0.200f,0.450f,0.800f,0.000f,0.112f,0.600f,0.500f,0.711f,0.000f,0.401f,1.000f}},
          {"Horn",           {0.280f,0.990f,0.280f,0.230f,0.000f,0.180f,0.400f,0.300f,0.800f,0.500f,0.000f,0.400f,0.500f,0.217f,0.480f,0.500f,1.000f}},
          {"Reed 1",         {0.220f,0.990f,0.250f,0.170f,0.000f,0.240f,0.310f,0.257f,0.900f,0.757f,0.000f,0.500f,0.500f,0.697f,0.803f,0.500f,1.000f}},
          {"Reed 2",         {0.220f,0.990f,0.250f,0.450f,0.070f,0.240f,0.310f,0.360f,0.900f,0.500f,0.211f,0.500f,0.500f,0.184f,0.000f,0.414f,1.000f}},
          {"Violin",         {0.697f,0.990f,0.421f,0.230f,0.138f,0.750f,0.390f,0.513f,0.800f,0.316f,0.467f,0.678f,0.500f,0.743f,0.757f,0.487f,1.000f}},
          {"Chunky Bass",    {0.000f,0.400f,0.000f,0.280f,0.125f,0.474f,0.250f,0.100f,0.500f,0.500f,0.000f,0.400f,0.500f,0.579f,0.592f,0.500f,1.000f}},
          {"E.Bass",         {0.230f,0.500f,0.100f,0.395f,0.000f,0.388f,0.092f,0.250f,0.150f,0.500f,0.200f,0.200f,0.500f,0.178f,0.822f,0.500f,1.000f}},
          {"Clunk Bass",     {0.000f,0.600f,0.400f,0.230f,0.000f,0.450f,0.320f,0.050f,0.900f,0.500f,0.000f,0.200f,0.500f,0.520f,0.105f,0.500f,1.000f}},
          {"Thick Bass",     {0.000f,0.600f,0.400f,0.170f,0.145f,0.290f,0.350f,0.100f,0.900f,0.500f,0.000f,0.400f,0.500f,0.441f,0.309f,0.500f,1.000f}},
          {"Sine Bass",      {0.000f,0.600f,0.490f,0.170f,0.151f,0.099f,0.400f,0.000f,0.900f,0.500f,0.000f,0.400f,0.500f,0.118f,0.013f,0.500f,1.000f}},
          {"Square Bass",    {0.000f,0.600f,0.100f,0.320f,0.000f,0.350f,0.670f,0.100f,0.150f,0.500f,0.000f,0.200f,0.500f,0.303f,0.730f,0.500f,1.000f}},
          {"Upright Bass 1", {0.300f,0.500f,0.400f,0.280f,0.000f,0.180f,0.540f,0.000f,0.700f,0.500f,0.000f,0.400f,0.500f,0.296f,0.033f,0.500f,1.000f}},
          {"Upright Bass 2", {0.300f,0.500f,0.400f,0.360f,0.000f,0.461f,0.070f,0.070f,0.700f,0.500f,0.000f,0.400f,0.500f,0.546f,0.467f,0.500f,1.000f}},
          {"Harmonics",      {0.000f,0.500f,0.500f,0.280f,0.000f,0.330f,0.200f,0.000f,0.700f,0.500f,0.000f,0.500f,0.500f,0.151f,0.079f,0.500f,1.000f}},
          {"Scratch",        {0.000f,0.500f,0.000f,0.000f,0.240f,0.580f,0.630f,0.000f,0.000f,0.500f,0.000f,0.600f,0.500f,0.816f,0.243f,0.500f,1.000f}},
          {"Syn Tom",        {0.000f,0.355f,0.350f,0.000f,0.105f,0.000f,0.000f,0.200f,0.500f,0.500f,0.000f,0.645f,0.500f,1.000f,0.296f,0.500f,1.000f}},
        };
        // "Empty" preset for slots 32-98
        static const float empty[17] = {0,1,0,0,0,0,0,0.5f,0,0,0,0.5f,0.5f,0,0,0,1};
        static constexpr int NBANK = sizeof(bank) / sizeof(bank[0]);
        for (int i = 0; i < NUM_PRESETS; i++) {
            if (i < NBANK) {
                memcpy(presets[i].param, bank[i].p, sizeof(float) * 17);
                strncpy(presets[i].name, bank[i].name, 23);
                presets[i].name[23] = 0;
            } else {
                memcpy(presets[i].param, empty, sizeof(float) * 17);
                strncpy(presets[i].name, "Empty", 23);
            }
        }
    }
};
