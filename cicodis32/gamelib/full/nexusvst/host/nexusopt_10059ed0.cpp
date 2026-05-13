#ifdef RASPI
#include <stdint.h>
#include <math.h>

// ============================================================
// sub_10059ed0 — biquad filter chain (Direct Form I), native
//
// Object layout (self = ecx = this):
//   self + 0x8d   : uint8_t  active flag
//   self + 0xac   : float    number of sections (stored as float, used as int)
//   self + 0x178  : BiquadSection[numSections]  filter chain 1 (for buf1)
//   self + 0x1a0  : BiquadSection[numSections]  filter chain 2 (for buf2)
//   self + 0x498  : uint32_t bitmask (bit N = section N active)
//
// BiquadSection layout (0x50 bytes each):
//   +0x00 : uint8_t  enabled
//   +0x04 : float    b0
//   +0x08 : float    b1
//   +0x0c : float    b2
//   +0x10 : float    a1
//   +0x14 : float    a2
//   +0x18 : float    w1  (x[n-1])
//   +0x1c : float    w2  (x[n-2])
//   +0x20 : float    w3  (y[n-1])
//   +0x24 : float    w4  (y[n-2])
//   +0x28..+0x4f : padding
//
// Difference equation:
//   y[n] = b0*x[n] + b1*x[n-1] + b2*x[n-2] - a1*y[n-1] - a2*y[n-2]
//
// Calling convention (emulated thiscall / stdcall, stackDrop16):
//   ecx     = this
//   esp+0   = arg1  (same as arg2, ignored)
//   esp+4   = arg2  = buf_desc pointer  { float* buf1, float* buf2 }
//   esp+8   = arg3  = sample count
//   esp+12  = arg4  = 0 (unused)
// ============================================================

static inline void killDenormal(float& x)
{
    if (fabsf(x) < 1.0e-20f)
        x = 0.0f;
}

// Process one biquad chain over a single float buffer, in-place.
static void biquad_chain(uint8_t* chain, int numSections, float* buf, int samples)
{
    for (int i = 0; i < samples; ++i)
    {
        float x = buf[i];

        uint8_t* sec = chain;
        for (int s = 0; s < numSections; ++s, sec += 0x50)
        {
            if (!*sec)          // enabled flag at offset 0
                continue;

            const float b0 = *(float*)(sec + 0x04);
            const float b1 = *(float*)(sec + 0x08);
            const float b2 = *(float*)(sec + 0x0c);
            const float a1 = *(float*)(sec + 0x10);
            const float a2 = *(float*)(sec + 0x14);

            float w1 = *(float*)(sec + 0x18);   // x[n-1]
            float w2 = *(float*)(sec + 0x1c);   // x[n-2]
            float w3 = *(float*)(sec + 0x20);   // y[n-1]
            float w4 = *(float*)(sec + 0x24);   // y[n-2]

            const float y = b0*x + b1*w1 + b2*w2 - a1*w3 - a2*w4;

            *(float*)(sec + 0x1c) = w1;         // w2 <- old w1
            *(float*)(sec + 0x18) = x;           // w1 <- x
            *(float*)(sec + 0x24) = w3;         // w4 <- old w3
            *(float*)(sec + 0x20) = y;           // w3 <- y

            x = y;
        }

        buf[i] = x;
    }

    // Flush denormals in all section state variables once per buffer.
    uint8_t* sec = chain;
    for (int s = 0; s < numSections; ++s, sec += 0x50)
    {
        if (!*sec) continue;
        killDenormal(*(float*)(sec + 0x18));
        killDenormal(*(float*)(sec + 0x1c));
        killDenormal(*(float*)(sec + 0x20));
        killDenormal(*(float*)(sec + 0x24));
    }
}

void sub_10059ed0_native(uint8_t* self, uint8_t* buf_desc, int samples)
{
    // Active flag (equivalent to vtable call sub_10007230 which returns self+0x8d)
    if (!*(uint8_t*)(self + 0x8d))
        return;

    // Number of biquad sections stored as float
    const int numSections = (int)(*(float*)(self + 0xac));
    if (numSections <= 0)
        return;

    // Global bitmask: if no active-section bits are set, nothing to do
    const uint32_t mask = (numSections < 32)
                          ? ((1u << numSections) - 1u)
                          : 0xFFFFFFFFu;
    if (!(*(uint32_t*)(self + 0x498) & mask))
        return;

    if (!buf_desc || samples <= 0)
        return;

    float* buf1 = *(float**)(buf_desc + 0);
    float* buf2 = *(float**)(buf_desc + 4);

    // Chain 1 at self+0x178, processes buf1 in-place
    if (buf1)
        biquad_chain(self + 0x178, numSections, buf1, samples);

    // Chain 2 at self+0x1a0, processes buf2 in-place (may be null)
#ifndef MONO
    if (buf2)
        biquad_chain(self + 0x1a0, numSections, buf2, samples);
#endif
}

// Emulated stack wrapper — replaces the original sub_10059ed0() body.
void sub_10059ed0()
{
    uint8_t* self     = (uint8_t*)ecx;
    // arg1 at esp+0 is the same pointer as arg2 (ignored)
    uint8_t* buf_desc = *(uint8_t**)(esp +  4);   // arg2: { float* buf1, float* buf2 }
    int      samples  = *(int32_t*) (esp +  8);   // arg3: sample count
    // arg4 at esp+12 = 0, ignored

    sub_10059ed0_native(self, buf_desc, samples);

    esp += 16;   // stackDrop16: callee cleans 4 args × 4 bytes
}

#else
#error nexusopt_10059ed0.cpp included outside RASPI build
#endif
