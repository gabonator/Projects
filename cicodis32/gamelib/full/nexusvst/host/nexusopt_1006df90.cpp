#include <stdint.h>
#include <string.h>
#include <math.h>

#define U8(base, o)    (*(uint8_t*)((base) + (o)))
#define I32(base, o)   (*(int32_t*)((base) + (o)))
#define F32(base, o)   (*(float*)((base) + (o)))
#define FPTR(base, o)  (*(float**)((base) + (o)))

//static inline float load_f32(uintptr_t addr)
//{
//    return *(float*)addr;
//}

static inline void copy_float_buffer(float* dst, const float* src, int samples)
{
    if (samples > 0)
        memcpy(dst, src, (size_t)samples * sizeof(float));
}

// ============================================================
// sub_1006fb80 native
// Delay/allpass stage
// args: self, input, output, samples
// ============================================================

void sub_1006fb80_native(
    uint8_t* self,
    float* input,
    float* output,
    int samples)
{
    if (!self || !input || !output || samples <= 0)
        return;

    const float coef = F32(self, 0x0c);

    float* delayPtr = FPTR(self, 0xfb0);
    int remainingUntilWrap = I32(self, 0xfb4);

    const int delayLength = I32(self, 0x08);
    float* const delayStart = (float*)(self + 0x10);

    int done = 0;

    while (done < samples)
    {
        if (remainingUntilWrap <= 0)
        {
            delayPtr = delayStart;
            remainingUntilWrap = delayLength;
        }

        int block = samples - done;
        if (block > remainingUntilWrap)
            block = remainingUntilWrap;

        int i = 0;

        for (; i + 3 < block; i += 4)
        {
            float x0 = input[done + i + 0];
            float b0 = delayPtr[0];
            float y0 = b0 - coef * x0;
            delayPtr[0] = x0 + coef * y0;
            output[done + i + 0] = y0;

            float x1 = input[done + i + 1];
            float b1 = delayPtr[1];
            float y1 = b1 - coef * x1;
            delayPtr[1] = x1 + coef * y1;
            output[done + i + 1] = y1;

            float x2 = input[done + i + 2];
            float b2 = delayPtr[2];
            float y2 = b2 - coef * x2;
            delayPtr[2] = x2 + coef * y2;
            output[done + i + 2] = y2;

            float x3 = input[done + i + 3];
            float b3 = delayPtr[3];
            float y3 = b3 - coef * x3;
            delayPtr[3] = x3 + coef * y3;
            output[done + i + 3] = y3;

            delayPtr += 4;
        }

        for (; i < block; ++i)
        {
            float x = input[done + i];
            float b = *delayPtr;

            float y = b - coef * x;

            *delayPtr = x + coef * y;
            output[done + i] = y;

            ++delayPtr;
        }

        done += block;
        remainingUntilWrap -= block;
    }

    FPTR(self, 0xfb0) = delayPtr;
    I32(self, 0xfb4) = remainingUntilWrap;
    U8(self, 0x04) = 0;
}

// Portable stack wrapper for sub_1006fb80
//void sub_1006fb80()
//{
//    uint8_t* self = (uint8_t*)ecx;
//
//    float* input  = *(float**)(esp + 0);
//    float* output = *(float**)(esp + 4);
//    int samples   = *(int32_t*)(esp + 8);
//
//    sub_1006fb80_native(self, input, output, samples);
//
//    esp += 12;
//}

// External helper used by sub_1006df90
//extern int sub_100ca3f6_native(float x);

static inline int sub_100ca3f6_native(float x)
{
    // TODO: gabo check range!
    return (int)x;
}

// ============================================================
// sub_1006df90 native
// Stereo reverb with 3-stage allpass network and multi-tap ring buffer.
// In MONO mode: skip all R-channel allpass stages and R ring-buffer writes.
// The ring buffer stores interleaved [L, R] float pairs; fb[1] is still
// zeroed each sample to prevent accumulation even when outR is not written.
// ============================================================

void sub_1006df90_native(
    uint8_t* self,
    float* inL,
    float* inR,
    float* outL,
    float* outR,
    int samples)
{
    if (!self || !inL || !inR || !outL || !outR || samples <= 0)
        return;

    const float C_103d83c0 = load_f32(0x103d83c0);
    const float C_103cd1c4 = load_f32(0x103cd1c4);
    const float C_103d3a00 = load_f32(0x103d3a00);
    const float C_103cd2c0 = load_f32(0x103cd2c0);

    float* tmp0L = FPTR(self, 0x3ed2c);
#ifndef MONO
    float* tmp0R = FPTR(self, 0x3ed30);
#endif
    float* tmp1L = FPTR(self, 0x3ed34);
#ifndef MONO
    float* tmp1R = FPTR(self, 0x3ed38);
#endif
    float* tmp2L = FPTR(self, 0x3ed3c);
#ifndef MONO
    float* tmp2R = FPTR(self, 0x3ed40);
#endif

    const float amount = F32(self, 0x3ed50);

    int selector = sub_100ca3f6_native(
        F32(self, 0x3ed6c) *
        F32(self, 0x3ed64) *
        F32(self, 0x3e820) *
        C_103d83c0
    );

    float* ringEnd = (float*)(self + (4 - selector) * 8);
    float* ringStart = (float*)(self + 0x20);

    // stage 0
    if (amount >= C_103cd1c4)
    {
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x04), inL, tmp0L, samples);
#ifndef MONO
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x08), inR, tmp0R, samples);
#endif
    }
    else
    {
        copy_float_buffer(tmp0L, inL, samples);
#ifndef MONO
        copy_float_buffer(tmp0R, inR, samples);
#endif
    }

    // stage 1
    if (amount >= C_103d3a00)
    {
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x0c), tmp0L, tmp1L, samples);
#ifndef MONO
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x10), tmp0R, tmp1R, samples);
#endif
    }
    else
    {
        copy_float_buffer(tmp1L, tmp0L, samples);
#ifndef MONO
        copy_float_buffer(tmp1R, tmp0R, samples);
#endif
    }

    // stage 2
    if (amount >= C_103cd2c0)
    {
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x14), tmp1L, tmp2L, samples);
#ifndef MONO
        sub_1006fb80_native((uint8_t*)FPTR(self, 0x18), tmp1R, tmp2R, samples);
#endif
    }
    else
    {
        copy_float_buffer(tmp2L, tmp1L, samples);
#ifndef MONO
        copy_float_buffer(tmp2R, tmp1R, samples);
#endif
    }

    const float dryGain = F32(self, 0x3ed4c);

    const int tapCount = I32(self, 0x3ed58);
    const int splitA   = I32(self, 0x3ed5c);
    const int splitB   = I32(self, 0x3ed60);

    for (int i = 0; i < samples; ++i)
    {
        float* srcL = tmp0L;
#ifndef MONO
        float* srcR = tmp0R;
#endif
        int split = splitA;

        uint8_t* tap = self + 0x3ea0c; // 256524 decimal

        for (int t = 0; t < tapCount; ++t, tap += 4)
        {
            if (t == split)
            {
                if (split == splitA)
                {
                    split = splitB;
                    srcL = tmp1L;
#ifndef MONO
                    srcR = tmp1R;
#endif
                }
                else
                {
                    srcL = tmp2L;
#ifndef MONO
                    srcR = tmp2R;
#endif
                }
            }

            float l = srcL[i];
#ifndef MONO
            float r = srcR[i];
#endif

            float*& p0 = *(float**)tap;
            float*& p1 = *(float**)(tap + 0x50);

            p0[0] += l * (*(float*)(tap + 0x1e0));
#ifndef MONO
            p0[1] += r * (*(float*)(tap + 0x230));

            p1[0] += r * (*(float*)(tap + 0x280));
            p1[1] += l * (*(float*)(tap + 0x2d0));
#endif

            p0 += 2;
            if (p0 >= ringEnd)
                p0 = ringStart;

            p1 += 2;
            if (p1 >= ringEnd)
                p1 = ringStart;
        }

        float*& fb = FPTR(self, 0x3e828);

        outL[i] = inL[i] * dryGain + fb[0];
        fb[0] = 0.0f;

#ifndef MONO
        outR[i] = inR[i] * dryGain + fb[1];
#endif
        fb[1] = 0.0f;  // always zero to prevent ring-buffer accumulation

        fb += 2;
        if (fb >= ringEnd)
            fb = ringStart;
    }
}

// Portable stack wrapper for sub_1006df90
void sub_1006df90()
{
    uint8_t* self = (uint8_t*)ecx;

    float* inL  = *(float**)(esp + 0);
    float* inR  = *(float**)(esp + 4);
    float* outL = *(float**)(esp + 8);
    float* outR = *(float**)(esp + 12);
    int samples = *(int32_t*)(esp + 16);

    sub_1006df90_native(self, inL, inR, outL, outR, samples);

    esp += 20;
}
