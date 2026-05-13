#ifdef RASPI
#include <math.h>

// ============================================================
// Optimized DSP core
// ============================================================

static inline void process_core(
    float*& writePtr,
    float*& readPtr,
    float* bufferStart,
    float* readLimit,
    int readWrapSamples,
    int delayLength,
    int& remainingUntilWriteWrap,
    float gain,
    float feedback,
    float smoothA,
    float smoothB,
    float& z,
    float*& out,
    int& samples)
{
    while (samples > 0)
    {
        int block = remainingUntilWriteWrap;

        if (block > samples)
            block = samples;

        if (block <= 0)
        {
            writePtr = bufferStart;
            remainingUntilWriteWrap = delayLength;
            continue;
        }

        for (int i = 0; i < block; ++i)
        {
            const float x = *writePtr;

            *out += x;

            const float delayed = *readPtr;

            z = ((x + delayed * feedback) * smoothB)
                + (smoothA * z);

            *writePtr = -z * gain;

            --readPtr;
            if (readPtr < readLimit)
                readPtr += readWrapSamples;

            ++writePtr;
            ++out;
        }

        samples -= block;
        remainingUntilWriteWrap -= block;

        if (remainingUntilWriteWrap <= 0 && samples > 0)
        {
            writePtr = bufferStart;
            remainingUntilWriteWrap = delayLength;
        }
    }
}

// ============================================================
// Drop-in replacement wrapper (32-bit __thiscall)
// ============================================================

void sub_1006ff60_native(char* ecx, float* out, int sampleCount)
{
#define U8(o)   (*(unsigned char*)(ecx + (o)))
#define I32(o)  (*(int*)(ecx + (o)))
#define F32(o)  (*(float*)(ecx + (o)))
#define PTR(o)  (*(float**)(ecx + (o)))

    const float smoothA = F32(0x70);
    const float smoothB = F32(0x78);

    if (U8(0x09))
    {
        PTR(0x24) = PTR(0x2c);
        I32(0x28) = I32(0x30);
        U8(0x09) = 0;
    }

    const int delayLength = I32(0x0c);
    if (!delayLength || !out || sampleCount <= 0)
        return;

    float* writePtr = PTR(0x1c);
    float* readPtr  = PTR(0x24);

    float* bufferStart = PTR(0x18);
    float* readLimit   = PTR(0x20);

    int readWrapSamples = I32(0x28);

    const float gain     = F32(0x14);
    const float feedback = F32(0x38);

    float z = F32(0x68);

    int remainingUntilWriteWrap = I32(0x84);

    while (sampleCount > 0)
    {
        int block = remainingUntilWriteWrap;

        if (block > sampleCount)
            block = sampleCount;

        if (block <= 0)
        {
            writePtr = bufferStart;
            remainingUntilWriteWrap = delayLength;
            continue;
        }

        for (int i = 0; i < block; ++i)
        {
            const float x = *writePtr;

            *out += x;

            const float delayed = *readPtr;

            z = ((x + delayed * feedback) * smoothB)
                + (smoothA * z);

            *writePtr = -z * gain;

            --readPtr;
            if (readPtr < readLimit)
                readPtr += readWrapSamples;

            ++writePtr;
            ++out;
        }

        sampleCount -= block;
        remainingUntilWriteWrap -= block;

        if (remainingUntilWriteWrap <= 0 && sampleCount > 0)
        {
            writePtr = bufferStart;
            remainingUntilWriteWrap = delayLength;
        }
    }

    PTR(0x1c) = writePtr;
    PTR(0x24) = readPtr;
    F32(0x68) = z;
    I32(0x84) = remainingUntilWriteWrap;

    if (fabsf(F32(0x68)) < 1e-20f) F32(0x68) = 0.0f;
    if (fabsf(F32(0x6c)) < 1e-20f) F32(0x6c) = 0.0f;

    U8(0x08) = 0;

#undef U8
#undef I32
#undef F32
#undef PTR
}

void sub_1006ff60()
{
    uint8_t* self = (uint8_t*)ecx;

    float* out = *(float**)(esp + 0);
    int sampleCount = *(int32_t*)(esp + 4);

    sub_1006ff60_native(
        (char*)self,
        out,
        sampleCount
    );

    // (no modified args to write back in this case)

    esp += 8;
}

#else
#error not used!?
#endif