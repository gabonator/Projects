static inline void sub_100685e0_inlined(uint32_t s, float value, uint8_t flag)
{
    const int count = (int32_t)memoryAGet32(ds, s + 0x2c);

    memoryFSet32(ds, s + 0x14, value);

    if ((float)count > value)
        memoryFSet32(ds, s + 0x14, floorf(value));

    if (flag || memoryAGet(ds, s + 0x30))
        memoryFSet32(ds, s + 0x18, floorf(memoryFGet32(ds, s + 0x14)));

    memoryASet(ds, s + 0x30, 0x01);
}

void sub_10062e20()
{
    StackGuard _sg(8, __FUNCTION__);

    const uint32_t s = memoryAGet32(ds, esp + 0x08);
    const float in = memoryFGet32(ds, esp + 0x04);

    const float v38 = memoryFGet32(ds, s + 0x38);

    if (memoryFGet32(ds, 0x100e6750) > v38)
    {
        esp += 8;
        fppush(in);
        return;
    }

    float x34 = memoryFGet32(ds, s + 0x34);

    float curve;
    const float c6490 = memoryFGet32(ds, 0x100e6490);
    const float c74d4 = memoryFGet32(ds, 0x100e74d4);
    const float c7448 = memoryFGet32(ds, 0x100e7448);

    if (c6490 > x34)
    {
        curve = c7448 + x34 * (c7448 - x34 * c74d4);
    }
    else
    {
        const float d = x34 - c6490;
        curve = c7448 + d * (c7448 - d * c74d4);
    }

    x34 += curve / memoryFGet32(ds, ecx + 0x70);

    const int ix34 = (int)floorf(x34);
    x34 -= (float)ix34;
    memoryFSet32(ds, s + 0x34, x34);

    const int count = (int32_t)memoryAGet32(ds, s + 0x2c);

    const float callArg =
        (float)count * v38 * memoryFGet32(ds, 0x103cf534) * curve +
        (float)count * memoryFGet32(ds, 0x103d33f8);

    sub_100685e0_inlined(s, callArg, 0);
    ecx = s;

    float x18 = memoryFGet32(ds, s + 0x18);
    x18 += (memoryFGet32(ds, s + 0x14) - x18) * memoryFGet32(ds, s + 0x20);
    memoryFSet32(ds, s + 0x18, x18);

    const int i18 = (int)floorf(x18);
    const float frac = x18 - (float)i18;
    const float invFrac = 1.0f - frac;

    uint32_t writePtr = memoryAGet32(ds, s + 0x00);
    const uint32_t basePtr = memoryAGet32(ds, s + 0x04);
    const uint32_t endPtr = memoryAGet32(ds, s + 0x08);
    const uint32_t ringBytes = (uint32_t)count * 4u;

    uint32_t p0 = writePtr - (uint32_t)i18 * 4u;
    uint32_t p1 = p0 - 4u;

    if (p1 < basePtr)
        p1 += ringBytes;

    if (p0 < basePtr)
        p0 += ringBytes;

    const float a = memoryFGet32(ds, p1);
    const float b = memoryFGet32(ds, p0);
    const float interp = a + (b - a) * invFrac;

    float x10 = memoryFGet32(ds, s + 0x10);
    x10 += (interp - x10) * memoryFGet32(ds, s + 0x28);
    memoryFSet32(ds, s + 0x10, x10);

    float x0c = memoryFGet32(ds, s + 0x0c);
    x0c += (x10 - x0c) * memoryFGet32(ds, s + 0x24);
    memoryFSet32(ds, s + 0x0c, x0c);

    const float remainingFpuValue = x10 - x0c;

    const float out =
        in +
        memoryFGet32(ds, 0x103d33f0) +
        x0c +
        remainingFpuValue * memoryFGet32(ds, s + 0x1c);

    memoryFSet32(ds, writePtr, out);

    writePtr += 4;
    if (writePtr >= endPtr)
        writePtr -= ringBytes;

    memoryASet32(ds, s + 0x00, writePtr);

    esp += 8;
    fppush(remainingFpuValue);
}

/*
void sub_10062e20() // 0000:10062e20 +long +stackDrop8
{
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    fld32(memoryAGet32(ds, 0x100e6750));
    esp -= 0x00000008;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x14);
    fcomp32(memoryAGet32(ds, esi + 0x38));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_10062e43;
    fld32(memoryAGet32(ds, esp + 0x10));
    esi = pop32();
    esp += 0x00000008;
    esp += 12; return;
loc_10062e43: // 0000:10062e43
    fld32(memoryAGet32(ds, esi + 0x34));
    fld32(memoryAGet32(ds, 0x100e6490));
    fcomst(1);
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_10062e6d;
    fldst(1);
    fmul32(memoryAGet32(ds, 0x100e74d4));
    fld32(memoryAGet32(ds, 0x100e7448));
    fldst(0);
    fsubrpst(2);
    fxchst2(0, 1);
    fmulpst(3);
    goto loc_10062e85;
loc_10062e6d: // 0000:10062e6d
    fsubst2(1, 0);
    fldst(1);
    fmulst2(0, 0);
    fmul32(memoryAGet32(ds, 0x100e74d4));
    fld32(memoryAGet32(ds, 0x100e7448));
    fmulst2(3, 0);
    fxchst2(0, 1);
    fsubrpst(3);
loc_10062e85: // 0000:10062e85
    fxchst2(0, 2);
    push32(edi);
    faddpst(1);
    memoryASet32(ds, esp + 0x8, fstp32());
    fdiv32(memoryAGet32(ds, ecx + 0x70));
    fadd32(memoryAGet32(ds, esi + 0x34));
    memoryASet32(ds, esi + 0x34, fst32());
    memoryASet32(ds, esp + 0xc, fstp32());
    fld32(memoryAGet32(ds, esp + 0xc));
    memoryASet32(ds, esp + 0x18, fistp32());
    fild32(memoryAGet32(ds, esp + 0x18));
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fsubr32(memoryAGet32(ds, esi + 0x34)); // d8 6e 34 : fsubr dword ptr [esi + 0x34]
    memoryASet32(ds, esi + 0x34, fstp32());
    fild32(memoryAGet32(ds, esi + 0x2c));
    fldst(0);
    fmul32(memoryAGet32(ds, esi + 0x38));
    fmul32(memoryAGet32(ds, 0x103cf534));
    fmul32(memoryAGet32(ds, esp + 0x10));
    fxchst2(0, 1);
    fmul32(memoryAGet32(ds, 0x103d33f8));
    faddpst(1);
    memoryASet32(ds, esp, fstp32());
    sub_100685e0();
    fld32(memoryAGet32(ds, esi + 0x14));
    fsub32(memoryAGet32(ds, esi + 0x18));
    fmul32(memoryAGet32(ds, esi + 0x20));
    fadd32(memoryAGet32(ds, esi + 0x18));
    memoryASet32(ds, esi + 0x18, fst32());
    memoryASet32(ds, esp + 0xc, fstp32());
    fld32(memoryAGet32(ds, esp + 0xc));
    memoryASet32(ds, esp + 0x18, fistp32());
    eax = memoryAGet32(ds, esp + 0x18);
    fild32(memoryAGet32(ds, esp + 0x18));
    edx = memoryAGet32(ds, esi);
    edi = memoryAGet32(ds, esi + 0x4);
    fsubr32(memoryAGet32(ds, esi + 0x18)); // d8 6e 18 : fsubr dword ptr [esi + 0x18]
    ecx = (eax * 4) + 0;
    fld1();
    eax = edx;
    eax -= ecx;
    fsubrpst(1);
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10062f1f;
    push32(ebx);
    ebx = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (ebx * 4);
    ebx = pop32();
loc_10062f1f: // 0000:10062f1f
    if (eax >= edi)
        goto loc_10062f29;
    edi = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (edi * 4);
loc_10062f29: // 0000:10062f29
    fld32(memoryAGet32(ds, eax));
    edi = pop32();
    fsub32(memoryAGet32(ds, ecx));
    fmulpst(1);
    fadd32(memoryAGet32(ds, ecx));
    fld32(memoryAGet32(ds, esi + 0x10));
    fsubst(1);
    fmul32(memoryAGet32(ds, esi + 0x28));
    faddpst(1);
    fld32(memoryAGet32(ds, 0x103d33f0));
    faddst2(1, 0);
    fxchst2(0, 1);
    memoryASet32(ds, esi + 0x10, fst32());
    fldst(0);
    fsub32(memoryAGet32(ds, esi + 0xc));
    fmul32(memoryAGet32(ds, esi + 0x24));
    fadd32(memoryAGet32(ds, esi + 0xc));
    faddst(2);
    memoryASet32(ds, esi + 0xc, fst32());
    fsubpst(1);
    fld32(memoryAGet32(ds, esi + 0x1c));
    fmulst(1);
    fld32(memoryAGet32(ds, esp + 0x10));
    faddpst(3);
    faddpst(2);
    fxchst2(0, 1);
    memoryASet32(ds, edx, fstp32());
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_10062f81;
    edx = memoryAGet32(ds, esi + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi, eax);
loc_10062f81: // 0000:10062f81
    esi = pop32();
    esp += 0x00000008;
    esp += 12;
}
*/