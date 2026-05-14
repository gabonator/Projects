// ============================================================
// sub_10056490 native  — 4-stage cascaded one-pole smoother
//
// Called twice per block per active section (800×/run).
// Computes one coefficient (sin-based) up front, then runs
// a 4-stage one-pole IIR cascade in-place over the buffer.
//
// One-pole per stage:
//   new_state = state + coeff * (input - state)
//   output    = input - new_state + K   (K = denormal guard ≈ 1e-38)
// Output of each stage is the input to the next; the final
// stage output is written back to buf[].
//
// Object layout (self = ecx):
//   self + 0x1a8           : uint32  ptr to parameter table
//   [table + 0x3c]         : float   raw frequency/cutoff param
//   self + 0xb4            : float   sample-rate divisor
//   self + sectionIdx*16 + 0xDF30/34/38/3C : float[4] one-pole states
//
// Stack args (stackDrop12, last-pushed = esp+0):
//   esp+0  : float* buf        (in-place input/output buffer)
//   esp+4  : int    count      (number of samples)
//   esp+8  : int    sectionIdx (0 or 1, selects state slot)
//
// Global constants used:
//   0x103cf094 : float  2π (or 2π/something)
//   0x103d33f0 : float  denormal guard K ≈ 1e-38
// ============================================================

static void sub_10056490_native(uint8_t* self, float* buf, int count, int sectionIdx)
{
    // Coefficient: sin(param / divisor * 2π)
    const uint32_t tablePtr = *(uint32_t*)(self + 0x1a8);  // emulated ptr
    const float param   = memoryFGet32(ds, tablePtr + 0x3c);
    const float divisor = *(float*)(self + 0xb4);
    const float k2pi    = 6.2831854820251465f;
    const float coeff   = sinf(param / divisor * k2pi);

    if (count == 0) return;

    // One-pole states: 4 consecutive floats at self + sectionIdx*16 + 0xDF30
    uint8_t* const base = self + (uint32_t)sectionIdx * 16;
    float* const s0 = (float*)(base + 0xDF30);
    float* const s1 = (float*)(base + 0xDF34);
    float* const s2 = (float*)(base + 0xDF38);
    float* const s3 = (float*)(base + 0xDF3C);

    const float K = 1.000000045813705e-18f;  // denormal guard

    for (int i = 0; i < count; ++i) {
        float sig = buf[i] + K;

        *s0 += coeff * (sig - *s0);  sig = sig - *s0 + K;
        *s1 += coeff * (sig - *s1);  sig = sig - *s1 + K;
        *s2 += coeff * (sig - *s2);  sig = sig - *s2 + K;
        *s3 += coeff * (sig - *s3);  sig = sig - *s3 + K;

        buf[i] = sig;
    }
}

void sub_10056490() // 0000:10056490 +long +stackDrop12
{
    float* buf      = *(float**)(esp + 0);
    int    count    = *(int32_t*)(esp + 4);
    int    sectionIdx = *(int32_t*)(esp + 8);
    sub_10056490_native((uint8_t*)ecx, buf, count, sectionIdx);
    esp += 12;
}

#if 0 // emulated body preserved for reference
void sub_10056490_emulated() // 0000:10056490 +long +stackDrop12
{
    StackGuard _sg(12, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, ecx + 0x1a8);
    fld32(memoryAGet32(ds, eax + 0x3c));
    push32(esi);
    fdiv32(memoryAGet32(ds, ecx + 0xb4));
    esi = memoryAGet32(ds, esp + 0xc);
    fmul32(0x40c90fdbu);
    fsin();
    if (!esi)
        goto loc_1005653f;
    eax = memoryAGet32(ds, esp + 0x10);
    fppush(1.000000045813705e-18);
    edx = eax + 3571;
    edx <<= 4;
    edx += ecx;
    eax <<= 4;
    eax += ecx;
    ecx = memoryAGet32(ds, esp + 0x8);
loc_100564d2:
    fld32(memoryAGet32(ds, ecx));
    esi--;
    faddst(1);
    ecx += 0x00000004;
    fldst(0);
    fsub32(memoryAGet32(ds, edx));
    fmulst(3);
    fadd32(memoryAGet32(ds, edx));
    memoryASet32(ds, edx, fst32());
    fsubpst(1);
    faddst(1);
    fldst(0);
    fsub32(memoryAGet32(ds, eax + 0xdf34));
    fmulst(3);
    fadd32(memoryAGet32(ds, eax + 0xdf34));
    memoryASet32(ds, eax + 0xdf34, fst32());
    fsubpst(1);
    faddst(1);
    fldst(0);
    fsub32(memoryAGet32(ds, eax + 0xdf38));
    fmulst(3);
    fadd32(memoryAGet32(ds, eax + 0xdf38));
    memoryASet32(ds, eax + 0xdf38, fst32());
    fsubpst(1);
    faddst(1);
    fldst(0);
    fsub32(memoryAGet32(ds, eax + 0xdf3c));
    fmulst(3);
    fadd32(memoryAGet32(ds, eax + 0xdf3c));
    memoryASet32(ds, eax + 0xdf3c, fst32());
    fsubpst(1);
    faddst(1);
    memoryASet32(ds, ecx - 4, fstp32());
    if (esi)
        goto loc_100564d2;
    fstpst(0);
loc_1005653f:
    fstpst(0);
    esi = pop32();
    esp += 16;
}
#endif // end emulated reference
