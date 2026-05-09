#include <stdint.h>
#include <math.h>

// ============================================================
// Memory helpers (exact layout)
// ============================================================

#define U8(base, o)   (*(uint8_t*)((base) + (o)))
#define I32(base, o)  (*(int32_t*)((base) + (o)))
#define F32(base, o)  (*(float*)((base) + (o)))
#define FPTR(base, o) (*(float**)((base) + (o)))

#define SF32(st, o)   (*(float*)((st) + (o)))

// runtime constant loader
static inline float load_f32(uintptr_t addr)
{
    return *(float*)addr;
}

// ============================================================
// Minimal SAFE processing (mode 1 only for now)
// ============================================================

static inline void process_mode1_safe(
    uint8_t* st,
    float* buffer,
    int samples,
    int phaseSlot,
    float phaseStep)
{
    for (int i = 0; i < samples; ++i)
    {
        float in = buffer[i];

        float phase = SF32(st, 0x1c);

        float a = SF32(st, 0x04) - SF32(st, 0x00) * phase;

        SF32(st, 0x04) = a;
        SF32(st, -4)   = SF32(st, -4) - a * phase;

        SF32(st, 0x00) = in - a;
        SF32(st, 0x08) = in - SF32(st, 0x04);

        // safe output tap (matches pattern *(esi + ebp*4 - 4))
        buffer[i] = SF32(st, phaseSlot * 4 - 4);

        SF32(st, 0x1c) = phase + phaseStep;
    }
}

// ============================================================
// Native function (SAFE baseline)
// ============================================================

void sub_10066dc0_native(
    uint8_t* self,
    float** channelBuffers,
    int /*unused*/,
    int samplesToProcess,
    int index)
{
    // ---- safety guards ----
    if (!self) return;
    if (!channelBuffers) return;
    if (!channelBuffers[0] || !channelBuffers[1]) return;
    if (samplesToProcess <= 0) return;
    if (index < 0) return;

    // ---- runtime constants ----
    const float C_100e77e8 = load_f32(0x100e77e8);
    const float C_103d4538 = load_f32(0x103d4538);

    // ---- stage base ----
    uint8_t* stageBase = self + 0xac + index * 0x4c;

    // ---- modulation source ----
    float** vecTable = *(float***)(self + 0x64);
    float* srcVec = vecTable[index];
    float* baseVec = FPTR(self, 0x58);

    float x = baseVec[0] + srcVec[0];
    float y = baseVec[1] + srcVec[1];
    float z = baseVec[2] + srcVec[2];

    float amount =
        (1.0f - fabsf(fabsf(x) - 1.0f)) *
        (1.0f - fabsf(fabsf(y) - 1.0f)) *
        (1.0f - fabsf(fabsf(z) - 1.0f));

    // ---- phase logic ----
    int counter = I32(self, 0x4cac);
    int phaseSlot = counter / 3;
    int mode = counter % 3;

    if (phaseSlot == 3)
        phaseSlot = 1;

    float phaseStepBase = C_100e77e8 / F32(self, 0x70);
    float phaseStep = phaseStepBase * amount;

    // ============================================================
    // Process 2 channels
    // ============================================================

    for (int ch = 0; ch < 2; ++ch)
    {
        float* buffer = channelBuffers[ch];

        // IMPORTANT: correct layout
        uint8_t* st = stageBase + 0x04 + ch * 0x24;

        float oldPhase = SF32(st, 0x1c);
        SF32(st, 0x1c) = phaseStep + C_103d4538;

        // ---- SAFE MODE ONLY ----
        // Only mode1 implemented to avoid corruption
        if (mode == 1)
        {
            process_mode1_safe(
                st,
                buffer,
                samplesToProcess,
                phaseSlot,
                phaseStep
            );
        }

        // restore phase accumulation
        SF32(st, 0x1c) = oldPhase + phaseStep * samplesToProcess;
    }
}

// ============================================================
// Portable wrapper (no x86 asm)
// ============================================================

void sub_10066dc0()
{
    uint8_t* self = (uint8_t*)ecx;

    float** channelBuffers = *(float***)(esp + 0);
    int arg1               = *(int32_t*)(esp + 4);
    int samplesToProcess   = *(int32_t*)(esp + 8);
    int index              = *(int32_t*)(esp + 12);

    sub_10066dc0_native(
        self,
        channelBuffers,
        arg1,
        samplesToProcess,
        index
    );

    esp += 16;
}
