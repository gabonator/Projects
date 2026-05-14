#include <stdint.h>
#include <math.h>

#define U8(base, o)    (*(uint8_t*)((base) + (o)))
#define I32(base, o)   (*(int32_t*)((base) + (o)))
#define F32(base, o)   (*(float*)((base) + (o)))
#define F64(base, o)   (*(double*)((base) + (o)))
#define load_f32(addr)   (*(float*)(addr))
#define load_f64(addr)   (*(double*)(addr))

//static inline float load_f32(uintptr_t addr)
//{ 
//    return *(float*)addr;
//}

//static inline double load_f64(uintptr_t addr)
//{
//    return *(double*)addr;
//}

static inline int round_to_int_nearest(float x)
{
    return (int)lrintf(x);
}

// ============================================================
// sub_100704c0 native
// modulation coefficient update
// ============================================================

void sub_100704c0_native(uint8_t* self)
{
    if (!self)
        return;

    const double C_103d83f8 = load_f64(0x103d83f8);

    double phase = F64(self, 0x08) / F64(self, 0x00);
    phase *= C_103d83f8;

    U8(self, 0x40) = 0;

    F64(self, 0x10) = phase;

    double c = cos(phase);

    F64(self, 0x20) = c + c;

    double base = F64(self, 0x18);

    F64(self, 0x30) = sin(base - phase);
    F64(self, 0x38) = sin(base - phase * 2.0);

    // original also called sub_10070420(), probably SetEvent.
}

// portable wrapper
//void sub_100704c0()
//{
//    uint8_t* self = (uint8_t*)ecx;
//    sub_100704c0_native(self);
//}

// ============================================================
// sub_1006d830 native
// stereo circular delay / modulated interpolation
// ============================================================

void sub_1006d830_native(
    uint8_t* self,
    float* inL,
    float* inR,
    float* outL,
    float* outR,
    int samples)
{
    if (!self || !inL || !inR || !outL || !outR || samples <= 0)
        return;

    const int DELAY_LEN = 0x84d0;

    const float C_ZERO = load_f32(0x100e6494);
    const float C_WRAP = load_f32(0x103d7e0c);

    float* delayL = (float*)(self + 0x000004);
#ifndef MONO
    float* delayR = (float*)(self + 0x21348);
#endif

    uint8_t* oscL = self + 272160; // 0x42720
#ifndef MONO
    uint8_t* oscR = self + 272248; // 0x42778
#endif

    int tapL = I32(self, 0x426c8) + I32(self, 0x42690);
    if (tapL > DELAY_LEN)
        tapL -= DELAY_LEN;

#ifndef MONO
    int tapR = I32(self, 0x426cc) + I32(self, 0x42694);
    if (tapR > DELAY_LEN)
        tapR -= DELAY_LEN;
#endif

    int writeL = I32(self, 0x42690);
#ifndef MONO
    int writeR = I32(self, 0x42694);
#endif

    for (int i = 0; i < samples; ++i)
    {
        // --------------------------------------------------------
        // Left channel fractional read
        // --------------------------------------------------------

        float posL = (float)writeL - F32(self, 0x42698);

        if (posL < C_ZERO)
            posL += C_WRAP;

        int idxL = round_to_int_nearest(posL);
        float fracL = posL - (float)idxL;

        float aL = delayL[idxL];
        float bL = delayL[idxL + 1];

        delayL[writeL + 1] += inL[i];

        float interpL = aL + (bL - aL) * fracL;
        outL[i] = interpL;

        float fbL =
            interpL * F32(self, 0x426f8) +
            F32(self, 0x426d8) * F32(self, 0x426e8);

        F32(self, 0x426d8) = fbL;

        float writeValueL = -(fbL * F32(self, 0x42714));

#ifndef MONO
        // --------------------------------------------------------
        // Right channel fractional read
        // --------------------------------------------------------

        float posR = (float)writeR - F32(self, 0x4269c);

        if (posR < C_ZERO)
            posR += C_WRAP;

        int idxR = round_to_int_nearest(posR);
        float fracR = posR - (float)idxR;

        float aR = delayR[idxR];
        float bR = delayR[idxR + 1];

        delayR[writeR + 1] += inR[i];

        float interpR = aR + (bR - aR) * fracR;
        outR[i] = interpR;

        float fbR =
            F32(self, 0x426dc) * F32(self, 0x426ec) +
            interpR * F32(self, 0x426fc);

        F32(self, 0x426dc) = fbR;

        float writeValueR = -(fbR * F32(self, 0x42718));
#endif

        // --------------------------------------------------------
        // feedback write taps
        // --------------------------------------------------------

        if (tapL > DELAY_LEN)
            tapL = 1;

        delayL[tapL + 1] = writeValueL;
        ++tapL;

#ifndef MONO
        if (tapR > DELAY_LEN)
            tapR = 1;

        delayR[tapR + 1] = writeValueR;
        ++tapR;
#endif

        ++writeL;
        if (writeL > DELAY_LEN)
        {
            delayL[1] = delayL[writeL + 1];
            writeL = 1;
        }

#ifndef MONO
        ++writeR;
        if (writeR > DELAY_LEN)
        {
            delayR[1] = delayR[writeR + 1];
            writeR = 1;
        }
#endif

        I32(self, 0x42690) = writeL;
#ifndef MONO
        I32(self, 0x42694) = writeR;
#endif

        // --------------------------------------------------------
        // update modulation oscillator L
        // --------------------------------------------------------

        if (U8(oscL, 0x40))
            sub_100704c0_native(oscL);

        double nextL =
            F64(oscL, 0x20) * F64(oscL, 0x30)
            - F64(oscL, 0x38);

        F64(oscL, 0x28) = nextL;
        F64(oscL, 0x38) = F64(oscL, 0x30);
        F64(oscL, 0x30) = nextL;

        F32(self, 0x42698) =
            (float)((nextL + (double)C_ZERO) * F32(self, 0x426c0));

#ifndef MONO
        // --------------------------------------------------------
        // update modulation oscillator R
        // --------------------------------------------------------

        if (U8(oscR, 0x40))
            sub_100704c0_native(oscR);

        double nextR =
            F64(self, 0x42798) * F64(self, 0x427a8)
            - F64(self, 0x427b0);

        F64(self, 0x427a0) = nextR;
        F64(self, 0x427b0) = F64(self, 0x427a8);
        F64(self, 0x427a8) = nextR;

        F32(self, 0x4269c) =
            (float)((nextR + (double)C_ZERO) * F32(self, 0x426c4));
#endif
    }
}

// ============================================================
// portable drop-in wrapper
// ============================================================

void sub_1006d830()
{
    uint8_t* self = (uint8_t*)ecx;

    float* inL  = *(float**)(esp + 0);
    float* inR  = *(float**)(esp + 4);
    float* outL = *(float**)(esp + 8);
    float* outR = *(float**)(esp + 12);
    int samples = *(int32_t*)(esp + 16);

    sub_1006d830_native(
        self,
        inL,
        inR,
        outL,
        outR,
        samples
    );

    esp += 20;
}

#if 0
void sub_1006d830() // 0000:1006d830 +long +stackDrop20
{
    StackGuard _sg(20, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x00000024;
    push32(ebx);
    push32(esi);
    esi = ecx;
    ebx = memoryAGet32(ds, esi + 0x426c8);
    ebx += memoryAGet32(ds, esi + 0x42690);
    push32(edi);
    if ((int32_t)ebx <= (int32_t)0x000084d0)
        goto loc_1006d858;
    ebx -= 0x000084d0;
loc_1006d858: // 0000:1006d858
    edx = memoryAGet32(ds, esi + 0x426cc);
    edx += memoryAGet32(ds, esi + 0x42694);
    if ((int32_t)edx <= (int32_t)0x000084d0)
        goto loc_1006d872;
    edx -= 0x000084d0;
loc_1006d872: // 0000:1006d872
    eax = memoryAGet32(ss, ebp + 0x18);
    if ((int32_t)eax <= 0)
        goto loc_1006dafc;
    edi = esi + 272160;
    memoryASet32(ds, esp + 0x1c, eax);
    goto loc_1006d890;
    // gap 7 bytes // gap 7 bytes
loc_1006d890: // 0000:1006d890
    fild32(memoryAGet32(ds, esi + 0x42690));
    fsub32(memoryAGet32(ds, esi + 0x42698));
    fcom32(0x3f800000u);
    memoryASet32(ds, esp + 0x10, fst32());
    ax = fnstsw();
    if (!(parityOdd(ah, 0x05)))
        goto loc_1006d8b7;
    fadd32(0x4704d000u);
    memoryASet32(ds, esp + 0x10, fst32());
loc_1006d8b7: // 0000:1006d8b7
    memoryASet64(ds, esp + 0x20, fstp64());
    fld64(memoryAGet64(ds, esp + 0x20));
    memoryASet32(ds, esp + 0x14, fistp32());
    eax = memoryAGet32(ds, esp + 0x14);
    fld32(memoryAGet32(ds, esi + eax * 4 + 0x4));
    ecx = memoryAGet32(ss, ebp + 0x8);
    fld32(memoryAGet32(ds, esi + eax * 4 + 0x8));
    eax = memoryAGet32(ds, esi + 0x42690);
    fld32(memoryAGet32(ds, esi + eax * 4 + 0x8));
    eax = (esi + (eax * 4)) + 8;
    fadd32(memoryAGet32(ds, ecx));
    memoryASet32(ds, eax, fstp32());
    eax = memoryAGet32(ss, ebp + 0x10);
    fild32(memoryAGet32(ds, esp + 0x14));
    fsubr32(memoryAGet32(ds, esp + 0x10)); // d8 6c 24 10 : fsubr dword ptr [esp + 0x10]
    fxchst2(0, 1);
    fsubst(2);
    fmulpst(1);
    faddpst(1);
    fldst(0);
    memoryASet32(ds, eax, fstp32());
    fmul32(memoryAGet32(ds, esi + 0x426f8));
    fld32(memoryAGet32(ds, esi + 0x426d8));
    fmul32(memoryAGet32(ds, esi + 0x426e8));
    faddpst(1);
    memoryASet32(ds, esi + 0x426d8, fst32());
    fmul32(memoryAGet32(ds, esi + 0x42714));
    memoryASet32(ds, esp + 0x20, fstp32());
    fild32(memoryAGet32(ds, esi + 0x42694));
    fsub32(memoryAGet32(ds, esi + 0x4269c));
    fcom32(0x3f800000u);
    memoryASet32(ds, esp + 0x10, fst32());
    ax = fnstsw();
    if (!(parityOdd(ah, 0x05)))
        goto loc_1006d946;
    fadd32(0x4704d000u);
    memoryASet32(ds, esp + 0x10, fst32());
loc_1006d946: // 0000:1006d946
    memoryASet64(ds, esp + 0x28, fstp64());
    fld64(memoryAGet64(ds, esp + 0x28));
    memoryASet32(ds, esp + 0x18, fistp32());
    eax = memoryAGet32(ds, esp + 0x18);
    fld32(memoryAGet32(ds, esi + eax * 4 + 0x21348));
    ecx = memoryAGet32(ds, esi + 0x42694);
    fld32(memoryAGet32(ds, esi + eax * 4 + 0x2134c));
    eax = (esi + (ecx * 4)) + 136012;
    fld32(memoryAGet32(ds, eax));
    ecx = memoryAGet32(ss, ebp + 0xc);
    fadd32(memoryAGet32(ds, ecx));
    ecx = 0x00000001;
    memoryASet32(ds, eax, fstp32());
    eax = memoryAGet32(ss, ebp + 0x14);
    fild32(memoryAGet32(ds, esp + 0x18));
    fsubr32(memoryAGet32(ds, esp + 0x10)); // d8 6c 24 10 : fsubr dword ptr [esp + 0x10]
    fxchst2(0, 1);
    fsubst(2);
    fmulpst(1);
    faddpst(1);
    fldst(0);
    memoryASet32(ds, eax, fstp32());
    fld32(memoryAGet32(ds, esi + 0x426dc));
    fmul32(memoryAGet32(ds, esi + 0x426ec));
    fxchst2(0, 1);
    fmul32(memoryAGet32(ds, esi + 0x426fc));
    faddpst(1);
    memoryASet32(ds, esi + 0x426dc, fst32());
    fmul32(memoryAGet32(ds, esi + 0x42718));
    if ((int32_t)ebx <= (int32_t)0x000084d0)
        goto loc_1006d9c2;
    ebx = ecx;
loc_1006d9c2: // 0000:1006d9c2
    if ((int32_t)edx <= (int32_t)0x000084d0)
        goto loc_1006d9d0;
    memoryASet32(ds, esp + 0x10, ecx);
    edx = ecx;
loc_1006d9d0: // 0000:1006d9d0
    eax = memoryAGet32(ss, ebp + 0x8);
    fchs();
    eax += 0x00000004;
    memoryASet32(ds, esi + ebx * 4 + 0x8, fstp32());
    fld32(memoryAGet32(ds, esp + 0x20));
    memoryASet32(ss, ebp + 0x8, eax);
    eax = memoryAGet32(ss, ebp + 0x10);
    fchs();
    eax += 0x00000004;
    memoryASet32(ds, esi + edx * 4 + 0x2134c, fstp32());
    memoryASet32(ss, ebp + 0x10, eax);
    memoryASet32(ss, ebp + 0xc, memoryAGet32(ss, ebp + 0xc) + 0x00000004);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax += 0x00000004;
    ebx++;
    memoryASet32(ss, ebp + 0x14, eax);
    eax = memoryAGet32(ds, esi + 0x42690);
    edx++;
    eax++;
    memoryASet32(ds, esp + 0x10, edx);
    memoryASet32(ds, esi + 0x42690, eax);
    if ((int32_t)eax <= (int32_t)0x000084d0)
        goto loc_1006da29;
    eax = memoryAGet32(ds, esi + eax * 4 + 0x4);
    memoryASet32(ds, esi + 0x8, eax);
    memoryASet32(ds, esi + 0x42690, ecx);
loc_1006da29: // 0000:1006da29
    eax = memoryAGet32(ds, esi + 0x42694);
    eax++;
    memoryASet32(ds, esi + 0x42694, eax);
    if ((int32_t)eax <= (int32_t)0x000084d0)
        goto loc_1006da50;
    eax = memoryAGet32(ds, esi + eax * 4 + 0x21348);
    memoryASet32(ds, esi + 0x2134c, eax);
    memoryASet32(ds, esi + 0x42694, ecx);
loc_1006da50: // 0000:1006da50
    al = memoryAGet(ds, edi + 0x40);
    if (!al)
        goto loc_1006da62;
    ecx = edi;
    sub_100704c0();
    edx = memoryAGet32(ds, esp + 0x10);
loc_1006da62: // 0000:1006da62
    fld64(memoryAGet64(ds, edi + 0x20));
    ecx = esi + 272248;
    fmul64(memoryAGet64(ds, edi + 0x30));
    fsub64(memoryAGet64(ds, edi + 0x38));
    memoryASet64(ds, edi + 0x28, fstp64());
    fld64(memoryAGet64(ds, edi + 0x30));
    memoryASet64(ds, edi + 0x38, fstp64());
    fld64(memoryAGet64(ds, edi + 0x28));
    memoryASet64(ds, edi + 0x30, fstp64());
    fld64(memoryAGet64(ds, edi + 0x28));
    fadd32(0x3f800000u);
    fmul32(memoryAGet32(ds, esi + 0x426c0));
    memoryASet32(ds, esi + 0x42698, fstp32());
    al = memoryAGet(ds, ecx + 0x40);
    if (!al)
        goto loc_1006daa5;
    sub_100704c0();
    edx = memoryAGet32(ds, esp + 0x10);
loc_1006daa5: // 0000:1006daa5
    fld64(memoryAGet64(ds, esi + 0x42798));
    eax = memoryAGet32(ds, esp + 0x1c);
    fmul64(memoryAGet64(ds, esi + 0x427a8));
    eax--;
    memoryASet32(ds, esp + 0x1c, eax);
    fsub64(memoryAGet64(ds, esi + 0x427b0));
    memoryASet64(ds, esi + 0x427a0, fstp64());
    fld64(memoryAGet64(ds, esi + 0x427a8));
    memoryASet64(ds, esi + 0x427b0, fstp64());
    fld64(memoryAGet64(ds, esi + 0x427a0));
    memoryASet64(ds, esi + 0x427a8, fstp64());
    fld64(memoryAGet64(ds, esi + 0x427a0));
    fadd32(0x3f800000u);
    fmul32(memoryAGet32(ds, esi + 0x426c4));
    memoryASet32(ds, esi + 0x4269c, fstp32());
    if (eax)
        goto loc_1006d890;
loc_1006dafc: // 0000:1006dafc
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 24;
}

void sub_100704c0() // 0000:100704c0 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    push32(ecx);
    push32(esi);
    esi = ecx;
    eax = esi + 68;
    push32(eax);
    ecx = esp + 8;
    sub_10070390();
    fld64(memoryAGet64(ds, esi + 0x8));
    fdiv64(memoryAGet64(ds, esi));
    ecx = esp + 4;
    memoryASet(ds, esi + 0x40, 0x00);
    fmul64(0x401921fb60000000ull);
    memoryASet64(ds, esi + 0x10, fst64());
    fldst(0);
    fcos();
    faddst2(0, 0);
    memoryASet64(ds, esi + 0x20, fstp64());
    fld64(memoryAGet64(ds, esi + 0x18));
    fsubst(1);
    fsin();
    memoryASet64(ds, esi + 0x30, fstp64());
    faddst2(0, 0);
    fsubr64(memoryAGet64(ds, esi + 0x18)); // dc 6e 18 : fsubr qword ptr [esi + 0x18]
    fsin();
    memoryASet64(ds, esi + 0x38, fstp64());
    sub_10070420();
    esi = pop32();
    ecx = pop32();
    esp += 4;
}


void sub_10070390()
{
  // interlockedcompareexchange, wait for single object
  esp += 4;
}

void sub_10070420()
{
  // set event
}
#endif