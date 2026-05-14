// Forward declarations for native functions from other opt files
// (defined in nexusopt_1006d830.cpp / nexusopt_1006df90.cpp / nexusopt_1006ff60.cpp)
void sub_1006d830_native(uint8_t*, float*, float*, float*, float*, int);
void sub_1006df90_native(uint8_t*, float*, float*, float*, float*, int);
void sub_1006fb80_native(uint8_t*, float*, float*, int);
void sub_1006ff60_native(char*,    float*, int);

// Forward declarations for subopt_* functions
void subopt_1006b050();
void subopt_10070470();
void subopt_10070420();
void subopt_1006ccd0();
void subopt_1006f230();
void subopt_1006efe0();
void subopt_1006d830();
void subopt_100704c0();
void subopt_10070390();
void subopt_1006df90();
void subopt_1006fb80();
void subopt_1006ff60();
void subopt_1006ce60();
void subopt_100ca3f6(double);

void sub_1006b050() // 0000:1006b050 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3;
    double _cmp0r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    push32(0xffffffff); // SEH prologue
    push32(0x100e3d38); // SEH prologue
    eax = 0x00000000; // SEH: fs read replaced with 0
    push32(eax); // SEH prologue
    // SEH removed // SEH removed
    esp -= 0x0000002c;
    push32(ebp);
    ebp = ecx;
    push32(esi);
    eax = ebp + 4;
    push32(edi);
    memoryASet32(ds, esp + 0x30, eax);
    memoryASet(ds, esp + 0x34, 0x00);
    eax = memoryAGet32(ss, ebp + 0x3a0);
    esi = memoryAGet32(ds, esp + 0x50);
    edi = 0;
    memoryASet32(ds, esp + 0x40, edi);
    if ((int32_t)eax < (int32_t)esi)
        goto loc_1006b9da;
    if (eax == edi)
        goto loc_1006b9da;
    push32(ebx);
    ecx = esp + 52;
    subopt_10070470();
    if (al)
        goto loc_1006b11a;
    al = memoryAGet(ds, esp + 0x58);
    if (!al)
        goto loc_1006b0f4;
    edx = memoryAGet32(ds, esp + 0x4c);
    ebx = memoryAGet32(ds, esp + 0x50);
    edi = memoryAGet32(ds, ebx);
    eax = (esi * 4) + 0;
    esi = memoryAGet32(ds, edx);
    ecx = eax;
    ebp = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = ebp;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    ecx = memoryAGet32(ds, edx + 0x4);
    if (!ecx)
        goto loc_1006b0dd;
    edx = ecx;
    goto loc_1006b0df;
loc_1006b0dd: // 0000:1006b0dd
    edx = memoryAGet32(ds, edx);
loc_1006b0df: // 0000:1006b0df
    edi = memoryAGet32(ds, ebx + 0x4);
    ecx = eax;
    esi = edx;
    edx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
loc_1006b0f4: // 0000:1006b0f4
    ecx = esp + 52;
    memoryASet32(ds, esp + 0x44, 0xffffffff);
    subopt_10070420();
    ebx = pop32();
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ecx = memoryAGet32(ds, esp + 0x2c);
    // SEH removed // SEH removed
    esp += 0x00000038;
    esp += 20; return;
loc_1006b11a: // 0000:1006b11a
    fp0 = memoryFGet32(ss, ebp + 0x36c);
    eax = memoryAGet32(ds, esp + 0x4c);
    fp0 += 1.0f;
    edx = memoryAGet32(ds, eax + 0x4);
    ecx = memoryAGet32(ds, eax);
    fp0 *= 0.5f;
    ebx = esi;
    memoryASet32(ds, esp + 0x10, edi);
    memoryASet32(ds, esp + 0x2c, ecx);
    fp0 *= memoryFGet32(ss, ebp + 0x3c8);
    memoryASet32(ds, esp + 0x30, edx);
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x3c8);
    fp0 -= memoryFGet32(ds, esp + 0x14);
    memoryFSet32(ds, esp + 0x24, fp0);
    if (edx != edi)
        goto loc_1006b163;
    memoryASet32(ds, esp + 0x30, ecx);
loc_1006b163: // 0000:1006b163
    edi = memoryAGet32(ds, esp + 0x50);
    ecx = memoryAGet32(ds, edi);
    edx = memoryAGet32(ds, edi + 0x4);
    memoryASet32(ds, esp + 0x18, ecx);
    ecx = ebp + 20;
    memoryASet32(ds, esp + 0x50, ecx);
    ecx = esp + 44;
    ecx -= eax;
    edi -= eax;
    memoryASet32(ds, esp + 0x4c, edx);
    edx = eax;
    memoryASet32(ds, esp + 0x28, ecx);
    memoryASet32(ds, esp + 0x1c, edi);
    memoryASet32(ds, esp + 0x20, 0x00000002);
loc_1006b195: // 0000:1006b195
    eax = memoryAGet32(ds, edx);
    if (eax != memoryAGet32(ds, edi + edx))
        goto loc_1006b1bb;
    ecx = esi;
    esi = eax;
    eax = memoryAGet32(ds, esp + 0x50);
    edi = memoryAGet32(ds, eax);
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, esp + 0x54);
    edi = memoryAGet32(ds, esp + 0x1c);
    ecx = eax;
    eax = memoryAGet32(ds, ecx);
    ecx = memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, ecx + edx, eax);
loc_1006b1bb: // 0000:1006b1bb
    al = memoryAGet(ds, esp + 0x58);
    if (!al)
        goto loc_1006b1d0;
    edi = memoryAGet32(ds, edi + edx);
    ecx = esi;
    eax = 0;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    edi = memoryAGet32(ds, esp + 0x1c);
loc_1006b1d0: // 0000:1006b1d0
    ecx = memoryAGet32(ds, esp + 0x50);
    eax = memoryAGet32(ds, esp + 0x20);
    ecx += 0x00000004;
    edx += 0x00000004;
    eax--;
    memoryASet32(ds, esp + 0x50, ecx);
    memoryASet32(ds, esp + 0x20, eax);
    if (eax)
        goto loc_1006b195;
    ecx = memoryAGet32(ss, ebp + 0x2f0);
    al = memoryAGet(ds, ecx + 0x8);
    if (!al)
        goto loc_1006b21c;
    edx = memoryAGet32(ss, ebp + 0x1c);
    eax = memoryAGet32(ds, esp + 0x2c);
    push32(esi);
    push32(edx);
    push32(eax);
    subopt_1006ccd0();
    ecx = memoryAGet32(ss, ebp + 0x20);
    edx = memoryAGet32(ds, esp + 0x30);
    push32(esi);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x2f4);
    push32(edx);
    subopt_1006ccd0();
    ebx = eax;
loc_1006b21c: // 0000:1006b21c
    fp0 = 1.000000045813705e-18f;
    eax = 0;
    if ((int32_t)ebx < (int32_t)0x00000004)
        goto loc_1006b2ba;
    edx = ebx - 3;
loc_1006b230: // 0000:1006b230
    ecx = memoryAGet32(ss, ebp + 0x1c);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx + eax * 4);
    ecx = ecx + (eax * 4);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x20);
    ecx = ecx + (eax * 4);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#endif
    ecx = memoryAGet32(ss, ebp + 0x1c);
    ecx = (ecx + (eax * 4)) + 4;
    fp0 *= -1.0f;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x20);
    ecx = (ecx + (eax * 4)) + 4;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#endif
    ecx = memoryAGet32(ss, ebp + 0x1c);
    ecx = (ecx + (eax * 4)) + 8;
    fp0 *= -1.0f;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x20);
    ecx = (ecx + (eax * 4)) + 8;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#endif
    ecx = memoryAGet32(ss, ebp + 0x1c);
    ecx = (ecx + (eax * 4)) + 12;
    fp0 *= -1.0f;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x20);
    ecx = (ecx + (eax * 4)) + 12;
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#endif
    eax += 0x00000004;
    fp0 *= -1.0f;
    if ((int32_t)eax < (int32_t)edx)
        goto loc_1006b230;
loc_1006b2ba: // 0000:1006b2ba
    if ((int32_t)eax >= (int32_t)ebx)
        goto loc_1006b2e4;
    edi = edi;
loc_1006b2c0: // 0000:1006b2c0
    edx = memoryAGet32(ss, ebp + 0x1c);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, edx + eax * 4);
    ecx = edx + (eax * 4);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x20);
    ecx = ecx + (eax * 4);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
#endif
    eax++;
    fp0 *= -1.0f;
    if ((int32_t)eax < (int32_t)ebx)
        goto loc_1006b2c0;
loc_1006b2e4: // 0000:1006b2e4
    eax = memoryAGet32(ss, ebp + 0x1c);

    ecx = memoryAGet32(ss, ebp + 0x4c);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006efe0();
    eax = memoryAGet32(ss, ebp + 0x20);
    ecx = memoryAGet32(ss, ebp + 0x50);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006efe0();
    fp0 = memoryFGet32(ss, ebp + 0x378);
    _cmp0r = (double)fromFp32(0);

    if (fp0 <= _cmp0r)  // fp0 vs (double)fromFp32(0)
        goto loc_1006b32b;
    eax = memoryAGet32(ss, ebp + 0x20);
    ecx = memoryAGet32(ss, ebp + 0x1c);
    push32(ebx);
    push32(eax);
    push32(ecx);
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x2d8);
    subopt_1006d830();
loc_1006b32b: // 0000:1006b32b
    edx = memoryAGet32(ss, ebp + 0x30);
    eax = memoryAGet32(ss, ebp + 0x2c);
    ecx = memoryAGet32(ss, ebp + 0x20);
    push32(ebx);
    push32(edx);
    edx = memoryAGet32(ss, ebp + 0x1c);
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x2d4);
    push32(edx);
    subopt_1006df90();
    eax = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ss, ebp + 0x24);
    edx = memoryAGet32(ss, ebp + 0x30);
    push32(ebx);
    push32(eax);
    eax = memoryAGet32(ss, ebp + 0x2c);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x2dc);
    push32(edx);
    push32(eax);
    subopt_1006d830();
    edi = memoryAGet32(ss, ebp + 0x40);
    esi = memoryAGet32(ss, ebp + 0x3c);
    edx = 0;
    memoryASet32(ds, esp + 0x50, edi);
    if ((int32_t)ebx <= 0)
        goto loc_1006b40e;
    goto loc_1006b380;
    // gap 7 bytes // gap 7 bytes
loc_1006b380: // 0000:1006b380
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp0 = memoryFGet32(ds, esp + 0x24);
    fp0 *= memoryFGet32(ds, ecx + edx * 4);
    eax = ecx + (edx * 4);
    ecx = memoryAGet32(ss, ebp + 0x24);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, ecx + edx * 4);
    ecx = ecx + (edx * 4);
    esi -= 0x00000004;
    edi -= 0x00000004;
    fp0 += fp1;
    fp1 = memoryFGet32(ds, esp + 0x24);
    fp1 *= memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esp + 0x14);
    fp2 *= memoryFGet32(ds, eax);
    fp1 += fp2;
    fp2 = fp0;
    fp2 *= 1.5f;
    fp3 = memoryFGet32(ss, ebp + 0x3dc);
    fp3 *= 0.5f;
    fp2 -= fp3;
    memoryFSet32(ds, esi + 0x4, fp2);
    fp2 = 1.5f;
    fp2 *= fp1;
    fp3 = memoryFGet32(ss, ebp + 0x3e0);
    fp3 *= 0.5f;
    fp2 -= fp3;
    memoryFSet32(ds, edi + 0x4, fp2);
    eax = memoryAGet32(ss, ebp + 0x34);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ss, ebp + 0x3dc, fp1);
    memoryFSet32(ss, ebp + 0x3e0, fp0);
    if (esi >= eax)
        goto loc_1006b401;
    eax = memoryAGet32(ss, ebp + 0x44);
    eax <<= 2;
    esi += eax;
    edi += eax;
loc_1006b401: // 0000:1006b401
    edx++;
    if ((int32_t)edx < (int32_t)ebx)
        goto loc_1006b380;
    memoryASet32(ds, esp + 0x50, edi);
loc_1006b40e: // 0000:1006b40e
    edi = memoryAGet32(ss, ebp + 0x24);
    eax = 0;
    ecx = (ebx * 4) + 0;
    edx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) stosb<ES_EDI>(al);
    edi = memoryAGet32(ss, ebp + 0x28);
    ecx = (ebx * 4) + 0;
    edx = ecx;
    ecx >>= 2;
    eax = 0;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) stosb<ES_EDI>(al);
    eax = memoryAGet32(ss, ebp + 0x300);
    eax <<= 1;
    memoryASet32(ds, esp + 0x58, 0x00000000);
    if ((int32_t)eax <= 0)
        goto loc_1006b4ce;
    edi = ebp + 88;
    esp = esp;
loc_1006b460: // 0000:1006b460
    push32(ebx);
    if ((int32_t)memoryAGet32(ds, esp + 0x10) >= (int32_t)0x00000002)
        goto loc_1006b486;
    ecx = memoryAGet32(ss, ebp + 0x24);
    push32(ecx);
    ecx = memoryAGet32(ds, edi - 4);
    subopt_1006ff60();
    edx = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ds, edi);
    push32(ebx);
#ifndef MONO
    push32(edx);
#else
    push32(memoryAGet32(ss, ebp + 0x24));
#endif
    subopt_1006ff60();
    memoryASet32(ds, esp + 0x10, memoryAGet32(ds, esp + 0x10) + 1);
    goto loc_1006b4b4;
loc_1006b486: // 0000:1006b486
#ifndef MONO
    eax = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ds, edi - 4);
    push32(eax);
#else
    ecx = memoryAGet32(ds, edi - 4);
    push32(memoryAGet32(ss, ebp + 0x24));
#endif
    subopt_1006ff60();
    ecx = memoryAGet32(ss, ebp + 0x24);
    push32(ebx);
    push32(ecx);
    ecx = memoryAGet32(ds, edi);
    subopt_1006ff60();
    eax = memoryAGet32(ds, esp + 0x10);
    eax++;
    memoryASet32(ds, esp + 0x10, eax);
    if ((int32_t)eax <= (int32_t)0x00000003)
        goto loc_1006b4b4;
    memoryASet32(ds, esp + 0x10, 0x00000000);
loc_1006b4b4: // 0000:1006b4b4
    eax = memoryAGet32(ds, esp + 0x58);
    edx = memoryAGet32(ss, ebp + 0x300);
    eax += 0x00000002;
    edx <<= 1;
    edi += 0x00000008;
    memoryASet32(ds, esp + 0x58, eax);
    if ((int32_t)eax < (int32_t)edx)
        goto loc_1006b460;
loc_1006b4ce: // 0000:1006b4ce
    ecx = memoryAGet32(ss, ebp + 0x30c);
    eax = memoryAGet32(ds, esp + 0x50);
    memoryASet32(ss, ebp + 0x3c, esi);
    ecx <<= 1;
    esi = 0;
    memoryASet32(ss, ebp + 0x40, eax);
    if ((int32_t)ecx <= 0)
        goto loc_1006b51d;
    edi = ebp + 408;
    esp = esp;
loc_1006b4f0: // 0000:1006b4f0
    eax = memoryAGet32(ss, ebp + 0x24);
    ecx = memoryAGet32(ds, edi - 4);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006fb80();
#ifndef MONO
    eax = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ds, edi);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006fb80();
#endif
    edx = memoryAGet32(ss, ebp + 0x30c);
    esi += 0x00000002;
    edx <<= 1;
    edi += 0x00000008;
    if ((int32_t)esi < (int32_t)edx)
        goto loc_1006b4f0;
loc_1006b51d: // 0000:1006b51d
    eax = 0;
    if ((int32_t)ebx < (int32_t)0x00000004)
        goto loc_1006b6ee;
    edx = ebx - 3;
    goto loc_1006b530;
    // gap 3 bytes // gap 3 bytes
loc_1006b530: // 0000:1006b530
    // sub-iter 1 (sample i)
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x30);
    fp0 = memoryFGet32(ds, ecx + eax * 4);
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp0 *= memoryFGet32(ss, ebp + 0x3bc);
    esi = memoryAGet32(ss, ebp + 0x2c);
    fp1 = memoryFGet32(ds, ecx + eax * 4);
    ecx = memoryAGet32(ss, ebp + 0x24);
    fp1 *= memoryFGet32(ss, ebp + 0x3cc);
    ecx = ecx + (eax * 4);
    fp0 += fp1;
#else
    esi = memoryAGet32(ss, ebp + 0x2c);
    ecx = memoryAGet32(ss, ebp + 0x24);
    ecx = ecx + (eax * 4);
#endif
    fp1 = memoryFGet32(ds, esi + eax * 4);
    fp1 *= memoryFGet32(ss, ebp + 0x3bc);
    fp2 = memoryFGet32(ss, ebp + 0x3cc);
    fp2 *= memoryFGet32(ds, ecx);
    fp1 += fp2;
    fp1 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp0 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx + eax * 4, fp0);
#endif
    ecx = memoryAGet32(ss, ebp + 0x30);
    fp0 = memoryFGet32(ss, ebp + 0x3b4);
    esi = memoryAGet32(ss, ebp + 0x2c);
    fp0 -= memoryFGet32(ss, ebp + 0x3b8);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ss, ebp + 0x3b8, fp0);
    // sub-iter 2 (sample i+1)
#ifndef MONO
    fp1 = memoryFGet32(ds, ecx + eax * 4 + 0x4);
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp1 *= memoryFGet32(ss, ebp + 0x3bc);
    fp2 = memoryFGet32(ds, ecx + eax * 4 + 0x4);
    ecx = memoryAGet32(ss, ebp + 0x24);
    fp2 *= memoryFGet32(ss, ebp + 0x3cc);
    ecx = (ecx + (eax * 4)) + 4;
    fp1 += fp2;
#else
    ecx = memoryAGet32(ss, ebp + 0x24);
    ecx = (ecx + (eax * 4)) + 4;
#endif
    fp2 = memoryFGet32(ds, esi + eax * 4 + 0x4);
    fp2 *= memoryFGet32(ss, ebp + 0x3bc);
    fp3 = memoryFGet32(ss, ebp + 0x3cc);
    fp3 *= memoryFGet32(ds, ecx);
    fp2 += fp3;
    fp2 *= fp0;
    memoryFSet32(ds, ecx, fp2);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp1 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx + eax * 4 + 0x4, fp1);
#endif
    ecx = memoryAGet32(ss, ebp + 0x28);
    esi = memoryAGet32(ss, ebp + 0x2c);

    fp0 = memoryFGet32(ss, ebp + 0x3b4);
    fp0 -= memoryFGet32(ss, ebp + 0x3b8);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ss, ebp + 0x3b8, fp0);
    // sub-iter 3 (sample i+2)
#ifndef MONO
    fp1 = memoryFGet32(ds, ecx + eax * 4 + 0x8);
    ecx = memoryAGet32(ss, ebp + 0x30);
    fp1 *= memoryFGet32(ss, ebp + 0x3cc);
    fp2 = memoryFGet32(ds, ecx + eax * 4 + 0x8);
    ecx = memoryAGet32(ss, ebp + 0x24);
    fp2 *= memoryFGet32(ss, ebp + 0x3bc);
    ecx = (ecx + (eax * 4)) + 8;
    fp1 += fp2;
#else
    ecx = memoryAGet32(ss, ebp + 0x24);
    ecx = (ecx + (eax * 4)) + 8;
#endif
    fp2 = memoryFGet32(ds, esi + eax * 4 + 0x8);
    fp2 *= memoryFGet32(ss, ebp + 0x3bc);
    fp3 = memoryFGet32(ss, ebp + 0x3cc);
    fp3 *= memoryFGet32(ds, ecx);
    fp2 += fp3;
    fp2 *= fp0;
    memoryFSet32(ds, ecx, fp2);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp1 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx + eax * 4 + 0x8, fp1);
#endif

    fp0 = memoryFGet32(ss, ebp + 0x3b4);
    fp0 -= memoryFGet32(ss, ebp + 0x3b8);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3b8);
    esi = memoryAGet32(ss, ebp + 0x2c);
    ecx = memoryAGet32(ss, ebp + 0x24);
    ecx = (ecx + (eax * 4)) + 12;
    memoryFSet32(ss, ebp + 0x3b8, fp0);
    eax += 0x00000004;
    // sub-iter 4 (sample i+3)
    fp1 = memoryFGet32(ds, esi + eax * 4 - 4);
    fp1 *= memoryFGet32(ss, ebp + 0x3bc);
    esi = memoryAGet32(ss, ebp + 0x30);
    fp2 = memoryFGet32(ss, ebp + 0x3cc);
    fp2 *= memoryFGet32(ds, ecx);
    fp1 += fp2;
#ifndef MONO
    fp2 = memoryFGet32(ds, esi + eax * 4 - 4);
    esi = memoryAGet32(ss, ebp + 0x28);
    fp2 *= memoryFGet32(ss, ebp + 0x3bc);
    fp3 = memoryFGet32(ds, esi + eax * 4 - 4);
    fp3 *= memoryFGet32(ss, ebp + 0x3cc);
    fp2 += fp3;
    memoryFSet32(ds, esp + 0x58, fp2);
#endif
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= fp0;
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x28);

    fp0 = memoryFGet32(ds, esp + 0x58);
    fp0 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx + eax * 4 - 4, fp0);
#endif
    fp0 = memoryFGet32(ss, ebp + 0x3b4);
    fp0 -= memoryFGet32(ss, ebp + 0x3b8);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ss, ebp + 0x3b8, fp0);
    if ((int32_t)eax < (int32_t)edx)
        goto loc_1006b530;
loc_1006b6ee: // 0000:1006b6ee
    if ((int32_t)eax >= (int32_t)ebx)
        goto loc_1006b764;
loc_1006b6f2: // 0000:1006b6f2
    edx = memoryAGet32(ss, ebp + 0x24);
    ecx = edx + (eax * 4);
    edx = memoryAGet32(ss, ebp + 0x2c);
    fp0 = memoryFGet32(ds, edx + eax * 4);
    edx = memoryAGet32(ss, ebp + 0x30);
    fp0 *= memoryFGet32(ss, ebp + 0x3bc);
    eax++;
    fp1 = memoryFGet32(ss, ebp + 0x3cc);
    fp1 *= memoryFGet32(ds, ecx);
    fp0 += fp1;
#ifndef MONO
    fp1 = memoryFGet32(ds, edx + eax * 4 - 4);
    edx = memoryAGet32(ss, ebp + 0x28);
    fp1 *= memoryFGet32(ss, ebp + 0x3bc);
    fp2 = memoryFGet32(ds, edx + eax * 4 - 4);
    fp2 *= memoryFGet32(ss, ebp + 0x3cc);
    fp1 += fp2;
#endif
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx, fp1);
#ifndef MONO
    ecx = memoryAGet32(ss, ebp + 0x28);
    fp0 *= memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ds, ecx + eax * 4 - 4, fp0);
#endif
    fp0 = memoryFGet32(ss, ebp + 0x3b4);
    fp0 -= memoryFGet32(ss, ebp + 0x3b8);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3b8);
    memoryFSet32(ss, ebp + 0x3b8, fp0);
    if ((int32_t)eax < (int32_t)ebx)
        goto loc_1006b6f2;
loc_1006b764: // 0000:1006b764
    al = memoryAGet(ss, ebp + 0x3d9);
    if (!al)
        goto loc_1006b790;
    eax = memoryAGet32(ss, ebp + 0x24);
    ecx = memoryAGet32(ss, ebp + 0x2e0);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006f230();
#ifndef MONO
    eax = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ss, ebp + 0x2e8);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006f230();
#endif
loc_1006b790: // 0000:1006b790
    al = memoryAGet(ss, ebp + 0x3d8);
    if (!al)
        goto loc_1006b7bc;
    eax = memoryAGet32(ss, ebp + 0x24);
    ecx = memoryAGet32(ss, ebp + 0x2e4);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006f230();
#ifndef MONO
    eax = memoryAGet32(ss, ebp + 0x28);
    ecx = memoryAGet32(ss, ebp + 0x2ec);
    push32(ebx);
    push32(eax);
    push32(eax);
    subopt_1006f230();
#endif
loc_1006b7bc: // 0000:1006b7bc
    edx = memoryAGet32(ss, ebp + 0x2f0);
    al = memoryAGet(ds, edx + 0x8);
    edi = memoryAGet32(ds, esp + 0x18);
    if (!al)
        goto loc_1006b7f9;
    esi = memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ss, ebp + 0x24);
    ecx = memoryAGet32(ss, ebp + 0x2f8);
    push32(esi);
    push32(ebx);
    push32(edi);
    push32(eax);
    subopt_1006ce60();
    ecx = memoryAGet32(ds, esp + 0x4c);
    edx = memoryAGet32(ss, ebp + 0x28);
    push32(esi);
    push32(ebx);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x2fc);
    push32(edx);
    subopt_1006ce60();
loc_1006b7f9: // 0000:1006b7f9
    eax = memoryAGet32(ds, esp + 0x54);
    esi = 0;
    if ((int32_t)eax < (int32_t)0x00000004)
        goto loc_1006b967;
    ebx = memoryAGet32(ds, esp + 0x2c);
    edx = memoryAGet32(ds, esp + 0x30);
    ecx = memoryAGet32(ds, esp + 0x4c);
    ebx -= edi;
    memoryASet32(ds, esp + 0x58, ebx);
    ebx = memoryAGet32(ds, esp + 0x30);
    ebx -= edi;
    memoryASet32(ds, esp + 0x50, ebx);
    ebx = memoryAGet32(ds, esp + 0x4c);
    ebx -= edi;
    eax = edi + 4;
    edi = memoryAGet32(ds, esp + 0x30);
    memoryASet32(ds, esp + 0x28, ebx);
    edi -= memoryAGet32(ds, esp + 0x4c);
    ebx = memoryAGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x24, edi);
    edi = memoryAGet32(ds, esp + 0x30);
    edx += 0x0000000c;
    ecx += 0x00000008;
    ebx -= edi;
    ecx = ecx;
loc_1006b850: // 0000:1006b850
    edi = memoryAGet32(ds, esp + 0x2c);
    fp0 = memoryFGet32(ds, edi + esi * 4);
    edi = memoryAGet32(ds, esp + 0x58);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    esi += 0x00000004;
    eax += 0x00000010;
    edx += 0x00000010;
    fp0 += memoryFGet32(ds, eax - 20);
    memoryFSet32(ds, eax - 20, fp0);
    fp0 = memoryFGet32(ds, edx - 28);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    fp0 += memoryFGet32(ds, ecx - 8);
    memoryFSet32(ds, ecx - 8, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x3c0);
    fp0 -= memoryFGet32(ss, ebp + 0x3c4);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3c4);
    memoryFSet32(ss, ebp + 0x3c4, fp0);
    fp0 *= memoryFGet32(ds, edi + eax - 16);
    edi = memoryAGet32(ds, esp + 0x50);
    fp0 += memoryFGet32(ds, eax - 16);
    memoryFSet32(ds, eax - 16, fp0);
    fp0 = memoryFGet32(ds, edi + eax - 16);
    edi = memoryAGet32(ds, esp + 0x28);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    fp0 += memoryFGet32(ds, edi + eax - 16);
    memoryFSet32(ds, edi + eax - 16, fp0);
    edi = memoryAGet32(ds, esp + 0x24);
    fp0 = memoryFGet32(ss, ebp + 0x3c0);
    edi += ecx;
    fp0 -= memoryFGet32(ss, ebp + 0x3c4);
    ecx += 0x00000010;
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3c4);
    memoryFSet32(ss, ebp + 0x3c4, fp0);
    fp0 *= memoryFGet32(ds, edi + ebx);
    fp0 += memoryFGet32(ds, eax - 12);
    memoryFSet32(ds, eax - 12, fp0);
    fp0 = memoryFGet32(ds, edi);
    edi = memoryAGet32(ds, esp + 0x54);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    edi += 0xfffffffd;
    fp0 += memoryFGet32(ds, ecx - 16);
    memoryFSet32(ds, ecx - 16, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x3c0);
    fp0 -= memoryFGet32(ss, ebp + 0x3c4);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3c4);
    memoryFSet32(ss, ebp + 0x3c4, fp0);
    fp0 *= memoryFGet32(ds, ebx + edx - 16);
    fp0 += memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, eax - 8, fp0);
    fp0 = memoryFGet32(ds, edx - 16);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    fp0 += memoryFGet32(ds, ecx - 12);
    memoryFSet32(ds, ecx - 12, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x3c0);
    fp0 -= memoryFGet32(ss, ebp + 0x3c4);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3c4);
    memoryFSet32(ss, ebp + 0x3c4, fp0);
    if ((int32_t)esi < (int32_t)edi)
        goto loc_1006b850;
    edi = memoryAGet32(ds, esp + 0x18);
loc_1006b967: // 0000:1006b967
    if ((int32_t)esi >= (int32_t)memoryAGet32(ds, esp + 0x54))
        goto loc_1006b0f4;
    edx = memoryAGet32(ds, esp + 0x2c);
    ebx = memoryAGet32(ds, esp + 0x30);
    ecx = memoryAGet32(ds, esp + 0x4c);
    eax = edi + (esi * 4);
    edx -= edi;
    ebx -= edi;
    ecx -= edi;
    edi = memoryAGet32(ds, esp + 0x54);
    edi -= esi;
    esi = edi;
    edi = edi;
loc_1006b990: // 0000:1006b990
    fp0 = memoryFGet32(ds, eax + edx);
    eax += 0x00000004;
    esi--;
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    fp0 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp0);
    fp0 = memoryFGet32(ds, eax + ebx - 4);
    fp0 *= memoryFGet32(ss, ebp + 0x3c4);
    fp0 += memoryFGet32(ds, eax + ecx - 4);
    memoryFSet32(ds, eax + ecx - 4, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x3c0);
    fp0 -= memoryFGet32(ss, ebp + 0x3c4);
    fp0 *= 0.0010000000474974513f;
    fp0 += memoryFGet32(ss, ebp + 0x3c4);
    memoryFSet32(ss, ebp + 0x3c4, fp0);
    if (esi)
        goto loc_1006b990;
    goto loc_1006b0f4;
loc_1006b9da: // 0000:1006b9da
    ecx = esp + 48;
    memoryASet32(ds, esp + 0x40, 0xffffffff);
    subopt_10070420();
    ecx = memoryAGet32(ds, esp + 0x38);
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    // SEH removed // SEH removed
    esp += 0x00000038;
    esp += 20;
}

void subopt_10070470() // 0000:10070470 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    push32(ebx);
    push32(esi);
    push32(0x00000000);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    ebx = 0x00000001;
    push32(ebx);
    push32(eax);
    indirectCall(cs, 0x6ab00017u, 0x0000, 0x1007047f); // 0000:1007047f
    if (eax)
        goto loc_1007049e;
    ecx = memoryAGet32(ds, esi);
    memoryASet32(ds, ecx + 0x4, ebx);
    indirectCall(cs, 0x6ab0002fu, 0x0000, 0x1007048e); // 0000:1007048e
    edx = memoryAGet32(ds, esi);
    memoryASet32(ds, edx + 0xc, eax);
    esi = pop32();
    al = bl;
    ebx = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 0x0000004; return; // SEH fixed: was +4, deficit 12
loc_1007049e: // 0000:1007049e
    esi = memoryAGet32(ds, esi);
    indirectCall(cs, 0x6ab0002fu, 0x0000, 0x100704a0); // 0000:100704a0
    if (memoryAGet32(ds, esi + 0xc) != eax)
        goto loc_100704b3;
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) + 1);
    esi = pop32();
    al = bl;
    ebx = pop32();
    // SEH fixed (was stack_unbalanced, 0/-12) // SEH fixed (was stack_unbalanced, 0/-12)
    esp += 0x0000004; return; // SEH fixed: was +4, deficit 12
loc_100704b3: // 0000:100704b3
    esi = pop32();
    al = 0;
    ebx = pop32();
    // SEH fixed (was stack_unbalanced, 0/-12) // SEH fixed (was stack_unbalanced, 0/-12)
    esp += 4;
}

void subopt_10070420() // 0000:10070420 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    push32(esi);
    esi = ecx;
    push32(edi);
    edi = memoryAGet32(ds, esi);
    indirectCall(cs, 0x6ab0002fu, 0x0000, 0x10070426); // 0000:10070426
    if (memoryAGet32(ds, edi + 0xc) != eax)
        goto loc_1007045f;
    memoryASet32(ds, edi + 0x4, memoryAGet32(ds, edi + 0x4) - 1);
    eax = memoryAGet32(ds, esi);
    ecx = memoryAGet32(ds, eax + 0x4);
    if (ecx)
        goto loc_1007045f;
    memoryASet32(ds, eax + 0xc, 0x00000000);
    eax = memoryAGet32(ds, esi);
    push32(0x00000000);
    push32(eax);
    indirectCall(cs, 0x6ab00016u, 0x0000, 0x10070449); // 0000:10070449
    if ((int32_t)eax >= 0)
        goto loc_1007045f;
    ecx = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, ecx + 0x8);
    push32(edx);
    indirectCall(cs, 0x6ab00030u, 0x0000, 0x10070459); // 0000:10070459
loc_1007045f: // 0000:1007045f
    edi = pop32();
    esi = pop32();
    esp += 4;
}

void subopt_1006ccd0() // 0000:1006ccd0 +long +stackDrop12
{
    double fp0, fp3, fp4, fp5, fp6;
    float fp1, fp2;
    double _cmp1r;
    StackGuard _sg(12, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x00000024;
    push32(ebx);
    ebx = ecx;
    fp0 = memoryFGet32(ds, ebx + 0x10);
    push32(esi);
    fp1 = memoryFGet32(ds, ebx + 0xc);
    push32(edi);

    if (fp1 == fp0)  // fp1 vs fp0
        goto loc_1006ce42;
    al = memoryAGet(ds, ebx + 0x8);
    if (!al)
        goto loc_1006ce42;
    fp0 = memoryFGet32(ds, ebx + 0xc);
    _cmp1r = (double)fromFp32(memoryAGet32(ds, ebx + 0x10));

    if (fp0 <= _cmp1r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, ebx + 0x10))
        goto loc_1006cd22;
    eax = memoryAGet32(ds, ebx + 0x28);
    edi = memoryAGet32(ss, ebp + 0x10);
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
    eax += 0x00000010;
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x4c);
    subopt_1006f230();
    goto loc_1006cd33;
loc_1006cd22: // 0000:1006cd22
    edi = memoryAGet32(ds, ebx + 0x28);
    ecx = memoryAGet32(ss, ebp + 0x10);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi += 0x00000010;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    edi = memoryAGet32(ss, ebp + 0x10);
loc_1006cd33: // 0000:1006cd33
    fp0 = (double)(int32_t)memoryAGet32(ss, ebp + 0x10);
    memoryFSet64(ds, esp + 0x18, fp0);
    fp0 += 1.0;
    fp0 -= memoryFGet64(ds, ebx + 0x20);
    fp0 /= memoryFGet64(ds, ebx + 0x18);
    fp0 += 1.0;
    subopt_100ca3f6(fp0);
    fp0 = memoryFGet64(ds, ebx + 0x20);
    esi = 0;
    memoryFSet64(ds, esp + 0x28, fp0);
    memoryASet32(ds, esp + 0x14, eax);
    if ((int32_t)eax <= 0)
        goto loc_1006ce01;
    goto loc_1006cd70;
    // gap 8 bytes // gap 8 bytes
loc_1006cd70: // 0000:1006cd70
    fp0 = memoryFGet64(ds, ebx + 0x20);
    memoryFSet64(ds, esp + 0x20, fp0);
    fp0 = memoryFGet64(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    ecx = memoryAGet32(ds, ebx + 0x28);
    fp0 = memoryFGet64(ds, ebx + 0x20);
    fisub32(memoryAGet32(ds, esp + 0x10));
    edx = memoryAGet32(ds, esp + 0x10);
    esi++;
    fp1 = memoryFGet32(ds, ecx + edx * 4 - 4);
    fp2 = memoryFGet32(ds, ecx + edx * 4);
    fp3 = memoryFGet32(ds, ecx + edx * 4 + 0x4);
    fp4 = memoryFGet32(ds, ecx + edx * 4 + 0x8);
    fp5 = fp3;
    fp5 += fp5;
    edx = memoryAGet32(ss, ebp + 0xc);
    fp5 += fp1;
    fp6 = fp2;
    fp6 *= 5.0f;
    fp6 += fp4;
    fp6 *= 0.5f;
    fp5 -= fp6;
    fp6 = fp2;
    fp6 -= fp3;
    fp6 *= 3.0f;
    fp6 -= fp1;
    fp6 += fp4;
    fp6 *= 0.5f;
    fp6 *= fp0;
    fp5 += fp6;
    fp5 *= fp0;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    fp5 -= fp1;
    fp5 *= 0.5f;
    fp3 += fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= fp0;
    fp4 += fp2;
    memoryFSet32(ds, edx + esi * 4 - 4, fp4);




    fp0 = memoryFGet64(ds, ebx + 0x18);
    fp0 += memoryFGet64(ds, ebx + 0x20);
    memoryFSet64(ds, ebx + 0x20, fp0);
    if ((int32_t)esi < (int32_t)eax)
        goto loc_1006cd70;
loc_1006ce01: // 0000:1006ce01
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, ebx + 0x28);
    fp0 *= memoryFGet64(ds, ebx + 0x18);
    fp0 += memoryFGet64(ds, esp + 0x28);
    fp0 -= memoryFGet64(ds, esp + 0x18);
    memoryFSet64(ds, ebx + 0x20, fp0);
    edx = memoryAGet32(ds, ecx + edi * 4);
    memoryASet32(ds, ecx, edx);
    ecx = memoryAGet32(ds, ebx + 0x28);
    edx = memoryAGet32(ds, ecx + edi * 4 + 0x4);
    memoryASet32(ds, ecx + 0x4, edx);
    ecx = memoryAGet32(ds, ebx + 0x28);
    edx = memoryAGet32(ds, ecx + edi * 4 + 0x8);
    memoryASet32(ds, ecx + 0x8, edx);
    ebx = memoryAGet32(ds, ebx + 0x28);
    ecx = memoryAGet32(ds, ebx + edi * 4 + 0xc);
    memoryASet32(ds, ebx + 0xc, ecx);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 16; return;
loc_1006ce42: // 0000:1006ce42
    eax = memoryAGet32(ss, ebp + 0x10);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = eax;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 16;
}

// ============================================================
// sub_1006f230 native  — simple path (mode == 0)
// 2-pole direct-form-I IIR filter.
//
// Object layout (self = ecx):
//   self + 0x4  : float  s1    (state 1)
//   self + 0x8  : float  s2    (state 2)
//   self + 0x10 : float  b0    (output coeff for new state)
//   self + 0x14 : float  b1    (output coeff for state 1)
//   self + 0x18 : float  b2    (output coeff for state 2)
//   self + 0x1c : float  a1    (feedback coeff for state 1)
//   self + 0x20 : float  a2    (feedback coeff for state 2)
//   self + 0x24 : uint32 mode  (0 = simple, !=0 = coefficient transition)
//
// Stack args (stackDrop12, last-pushed = esp+0):
//   esp+0  : float* inBuf
//   esp+4  : float* outBuf
//   esp+8  : int    count
// ============================================================

static void sub_1006f230_native(uint8_t* self, float* inBuf, float* outBuf, int count)
{
    float s1 = *(float*)(self + 0x4);
    float s2 = *(float*)(self + 0x8);
    const float a1 = *(float*)(self + 0x1c);
    const float a2 = *(float*)(self + 0x20);
    const float b0 = *(float*)(self + 0x10);
    const float b1 = *(float*)(self + 0x14);
    const float b2 = *(float*)(self + 0x18);
    for (int i = 0; i < count; ++i) {
        float x   = s1 * a1 + s2 * a2 + inBuf[i];
        float y   = x * b0 + s1 * b1 + s2 * b2;
        outBuf[i] = y;
        s2 = s1; s1 = x;
    }
    *(float*)(self + 0x4) = s1;
    *(float*)(self + 0x8) = s2;
}

void subopt_1006f230() // 0000:1006f230 +long +stackDrop12
{
    // Native fast-path: simple 2-pole IIR (~99% of calls, mode == 0)
    if (*(uint32_t*)((uint8_t*)ecx + 0x24) == 0) {
        sub_1006f230_native((uint8_t*)ecx,
                            *(float**)(esp + 0),
                            *(float**)(esp + 4),
                            *(int32_t*)(esp + 8));
        esp += 12;
        return;
    }
    // Coefficient-transition crossfade (mode != 0) — emulated.
    // Simple-path code below (loc_1006f273/loc_1006f352/loc_1006f363) is
    // never reached here: eax != 0 causes the immediate goto loc_1006f3a1.
    float fp0, fp1, fp2;
    double _cmp0r, _cmp1r, _cmp2r, _cmp3r;
    StackGuard _sg(12, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, ecx + 0x24);
    esp -= 0x0000000c;
    push32(ebx);
    push32(ebp);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x28);
    if (eax)
        goto loc_1006f3a1;
    esi = memoryAGet32(ds, esp + 0x24);
    ebx = memoryAGet32(ds, esp + 0x20);
    ebp = 0;
    if ((int32_t)edi < (int32_t)0x00000004)
        goto loc_1006f352;
    eax = esi + 4;
    edx = ebx + 12;
    ebx -= esi;
    esi = edi - 4;
    esi >>= 2;
    esi++;
    ebp = (esi * 4) + 0;
    memoryASet32(ds, esp + 0x14, ebp);
loc_1006f273: // 0000:1006f273
    fp0 = memoryFGet32(ds, ecx + 0x4);
    eax += 0x00000010;
    fp0 *= memoryFGet32(ds, ecx + 0x1c);
    edx += 0x00000010;
    esi--;
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 28);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 20, fp1);
    ebp = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebp);
    memoryFSet32(ds, ecx + 0x4, fp0);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += memoryFGet32(ds, ebx + eax - 16);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 16, fp1);
    ebp = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebp);
    memoryFSet32(ds, ecx + 0x4, fp0);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 20);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 12, fp1);
    ebp = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebp);
    memoryFSet32(ds, ecx + 0x4, fp0);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 16);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 8, fp1);
    ebp = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebp);
    memoryFSet32(ds, ecx + 0x4, fp0);
    if (esi)
        goto loc_1006f273;
    ebx = memoryAGet32(ds, esp + 0x20);
    esi = memoryAGet32(ds, esp + 0x24);
    ebp = memoryAGet32(ds, esp + 0x14);
loc_1006f352: // 0000:1006f352
    if ((int32_t)ebp >= (int32_t)edi)
        goto loc_1006f8c4;
    edx = ebx;
    edx -= esi;
    eax = esi + (ebp * 4);
    edi -= ebp;
loc_1006f363: // 0000:1006f363
    fp0 = memoryFGet32(ds, ecx + 0x4);
    eax += 0x00000004;
    edi--;
    fp0 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += memoryFGet32(ds, eax + edx - 4);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp0 += fp1;
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 4, fp1);
    esi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, esi);
    memoryFSet32(ds, ecx + 0x4, fp0);
    if (edi)
        goto loc_1006f363;
    goto loc_1006f8c4;
loc_1006f3a1: // 0000:1006f3a1
    eax = edi - 30;
    memoryASet32(ds, esp + 0x10, 0x0000001e);
    if ((int32_t)eax >= (int32_t)0x0000000a)
        goto loc_1006f3b8;
    edx = edi - 10;
    memoryASet32(ds, esp + 0x10, edx);
loc_1006f3b8: // 0000:1006f3b8
    ebp = memoryAGet32(ds, esp + 0x10);
    ebx = memoryAGet32(ds, esp + 0x20);
    ebp += 0x0000000a;
    esi = 0;
    memoryASet32(ds, esp + 0x18, ebp);
    if ((int32_t)ebp < (int32_t)0x00000004)
        goto loc_1006f54b;
    edi = ebp - 4;
    edi >>= 2;
    edi++;
    edx = ebx + 8;
    eax = ecx + 44;
    esi = (edi * 4) + 0;
    goto loc_1006f3f0;
    // gap 8 bytes // gap 8 bytes
loc_1006f3f0: // 0000:1006f3f0
    fp0 = memoryFGet32(ds, ecx + 0xf0);
    eax += 0x00000010;
    fp0 *= memoryFGet32(ds, ecx + 0xe8);
    edx += 0x00000010;
    edi--;
    fp1 = memoryFGet32(ds, ecx + 0xf4);
    fp1 *= memoryFGet32(ds, ecx + 0xec);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 24);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0xdc);
    fp2 = memoryFGet32(ds, ecx + 0xf4);
    fp2 *= memoryFGet32(ds, ecx + 0xe4);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0xe0);
    fp2 *= memoryFGet32(ds, ecx + 0xf0);
    fp1 += fp2;
    memoryFSet32(ds, eax - 20, fp1);
    ebx = memoryAGet32(ds, ecx + 0xf0);
    memoryASet32(ds, ecx + 0xf4, ebx);
    memoryFSet32(ds, ecx + 0xf0, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0xe8);
    fp1 = memoryFGet32(ds, ecx + 0xf4);
    fp1 *= memoryFGet32(ds, ecx + 0xec);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 20);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0xdc);
    fp2 = memoryFGet32(ds, ecx + 0xf4);
    fp2 *= memoryFGet32(ds, ecx + 0xe4);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0xe0);
    fp2 *= memoryFGet32(ds, ecx + 0xf0);
    fp1 += fp2;
    memoryFSet32(ds, eax - 16, fp1);
    ebx = memoryAGet32(ds, ecx + 0xf0);
    memoryASet32(ds, ecx + 0xf4, ebx);
    memoryFSet32(ds, ecx + 0xf0, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0xe8);
    fp1 = memoryFGet32(ds, ecx + 0xf4);
    fp1 *= memoryFGet32(ds, ecx + 0xec);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 16);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0xdc);
    fp2 = memoryFGet32(ds, ecx + 0xf4);
    fp2 *= memoryFGet32(ds, ecx + 0xe4);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0xe0);
    fp2 *= memoryFGet32(ds, ecx + 0xf0);
    fp1 += fp2;
    memoryFSet32(ds, eax - 12, fp1);
    ebx = memoryAGet32(ds, ecx + 0xf0);
    memoryASet32(ds, ecx + 0xf4, ebx);
    memoryFSet32(ds, ecx + 0xf0, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0xe8);
    fp1 = memoryFGet32(ds, ecx + 0xf4);
    fp1 *= memoryFGet32(ds, ecx + 0xec);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 12);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0xdc);
    fp2 = memoryFGet32(ds, ecx + 0xf4);
    fp2 *= memoryFGet32(ds, ecx + 0xe4);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0xe0);
    fp2 *= memoryFGet32(ds, ecx + 0xf0);
    fp1 += fp2;
    memoryFSet32(ds, eax - 8, fp1);
    ebx = memoryAGet32(ds, ecx + 0xf0);
    memoryASet32(ds, ecx + 0xf4, ebx);
    memoryFSet32(ds, ecx + 0xf0, fp0);
    if (edi)
        goto loc_1006f3f0;
    ebx = memoryAGet32(ds, esp + 0x20);
    edi = memoryAGet32(ds, esp + 0x28);
loc_1006f54b: // 0000:1006f54b
    if ((int32_t)esi >= (int32_t)ebp)
        goto loc_1006f5b2;
    eax = (ecx + (esi * 4)) + 40;
loc_1006f553: // 0000:1006f553
    fp0 = memoryFGet32(ds, ecx + 0xf0);
    esi++;
    fp0 *= memoryFGet32(ds, ecx + 0xe8);
    eax += 0x00000004;
    fp0 += memoryFGet32(ds, ebx + esi * 4 - 4);
    fp1 = memoryFGet32(ds, ecx + 0xf4);
    fp1 *= memoryFGet32(ds, ecx + 0xec);
    fp0 += fp1;
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0xdc);
    fp2 = memoryFGet32(ds, ecx + 0xf4);
    fp2 *= memoryFGet32(ds, ecx + 0xe4);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0xe0);
    fp2 *= memoryFGet32(ds, ecx + 0xf0);
    fp1 += fp2;
    memoryFSet32(ds, eax - 4, fp1);
    edx = memoryAGet32(ds, ecx + 0xf0);
    memoryASet32(ds, ecx + 0xf4, edx);
    memoryFSet32(ds, ecx + 0xf0, fp0);
    if ((int32_t)esi < (int32_t)ebp)
        goto loc_1006f553;
loc_1006f5b2: // 0000:1006f5b2
    esi = memoryAGet32(ds, esp + 0x24);
    edx = 0;
    if ((int32_t)edi < (int32_t)0x00000004)
        goto loc_1006f6c3;
    edi += 0xfffffffc;
    edx = ebx + 12;
    ebx -= esi;
    edi >>= 2;
    edi++;
    memoryASet32(ds, esp + 0x24, ebx);
    ebx = (edi * 4) + 0;
    eax = esi + 4;
    memoryASet32(ds, esp + 0x14, ebx);
loc_1006f5e0: // 0000:1006f5e0
    fp0 = memoryFGet32(ds, ecx + 0x4);
    eax += 0x00000010;
    fp0 *= memoryFGet32(ds, ecx + 0x1c);
    edx += 0x00000010;
    edi--;
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 28);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 20, fp1);
    ebx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebx);
    memoryFSet32(ds, ecx + 0x4, fp0);
    ebx = memoryAGet32(ds, esp + 0x24);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += memoryFGet32(ds, eax + ebx - 16);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 16, fp1);
    ebx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebx);
    memoryFSet32(ds, ecx + 0x4, fp0);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 20);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 12, fp1);
    ebx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebx);
    memoryFSet32(ds, ecx + 0x4, fp0);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edx - 16);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 8, fp1);
    ebx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, ebx);
    memoryFSet32(ds, ecx + 0x4, fp0);
    if (edi)
        goto loc_1006f5e0;
    edx = memoryAGet32(ds, esp + 0x14);
    ebx = memoryAGet32(ds, esp + 0x20);
    edi = memoryAGet32(ds, esp + 0x28);
loc_1006f6c3: // 0000:1006f6c3
    if ((int32_t)edx >= (int32_t)edi)
        goto loc_1006f709;
    ebx -= esi;
    eax = esi + (edx * 4);
    edi -= edx;
    edi = edi;
loc_1006f6d0: // 0000:1006f6d0
    fp0 = memoryFGet32(ds, ecx + 0x4);
    eax += 0x00000004;
    edi--;
    fp0 *= memoryFGet32(ds, ecx + 0x1c);
    fp0 += memoryFGet32(ds, ebx + eax - 4);
    fp1 = memoryFGet32(ds, ecx + 0x20);
    fp1 *= memoryFGet32(ds, ecx + 0x8);
    fp0 += fp1;
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, ecx + 0x10);
    fp2 = memoryFGet32(ds, ecx + 0x4);
    fp2 *= memoryFGet32(ds, ecx + 0x14);
    fp1 += fp2;
    fp2 = memoryFGet32(ds, ecx + 0x18);
    fp2 *= memoryFGet32(ds, ecx + 0x8);
    fp1 += fp2;
    memoryFSet32(ds, eax - 4, fp1);
    edx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edx);
    memoryFSet32(ds, ecx + 0x4, fp0);
    if (edi)
        goto loc_1006f6d0;
loc_1006f709: // 0000:1006f709
    eax = memoryAGet32(ds, ecx + 0x28);
    memoryASet32(ds, esi, eax);
    edx = memoryAGet32(ds, ecx + 0x2c);
    memoryASet32(ds, esi + 0x4, edx);
    eax = memoryAGet32(ds, ecx + 0x30);
    memoryASet32(ds, esi + 0x8, eax);
    edx = memoryAGet32(ds, ecx + 0x34);
    memoryASet32(ds, esi + 0xc, edx);
    eax = memoryAGet32(ds, ecx + 0x38);
    memoryASet32(ds, esi + 0x10, eax);
    edx = memoryAGet32(ds, ecx + 0x3c);
    memoryASet32(ds, esi + 0x14, edx);
    eax = memoryAGet32(ds, ecx + 0x40);
    memoryASet32(ds, esi + 0x18, eax);
    edx = memoryAGet32(ds, ecx + 0x44);
    memoryASet32(ds, esi + 0x1c, edx);
    eax = memoryAGet32(ds, ecx + 0x48);
    memoryASet32(ds, esi + 0x20, eax);
    edx = memoryAGet32(ds, ecx + 0x4c);
    eax = ebp - 10;
    memoryASet32(ds, esi + 0x24, edx);
    edi = 0x0000000a;
    if ((int32_t)eax < (int32_t)0x00000004)
        goto loc_1006f855;
    edi = memoryAGet32(ds, esp + 0x10);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x10);
    edi--;
    memoryASet32(ds, esp + 0x20, edi);
    edi = ebp - 14;
    edi >>= 2;
    edi++;
    ebx = 0x00000001;
    memoryASet32(ds, esp + 0x24, edi);
    memoryASet32(ds, esp + 0x28, ebx);
    edx = esi + 48;
    eax = ecx + 84;
    edi = (edi * 4) + 10;
loc_1006f783: // 0000:1006f783
    ebp = memoryAGet32(ds, esp + 0x20);
    ebp++;
    memoryASet32(ds, esp + 0x14, ebp);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    ebp = ebx - 1;
    memoryASet32(ds, esp + 0x14, ebp);
    ebp = memoryAGet32(ds, esp + 0x20);
    fdiv80(st(1));
    ebp--;
    eax += 0x00000010;
    edx += 0x00000010;
    fp1 *= memoryFGet32(ds, eax - 20);
    memoryFSet32(ds, eax - 20, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, edx - 24);
    memoryFSet32(ds, edx - 24, fp1);
    fp1 += memoryFGet32(ds, eax - 20);
    memoryFSet32(ds, edx - 24, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, eax - 16);
    memoryFSet32(ds, eax - 16, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, ebp);
    ebp = ebx + 1;
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, edx - 20);
    memoryFSet32(ds, edx - 20, fp1);
    fp1 += memoryFGet32(ds, eax - 16);
    memoryFSet32(ds, edx - 20, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, ebp);
    ebp = memoryAGet32(ds, esp + 0x20);
    ebp += 0xfffffffe;
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, eax - 12);
    memoryFSet32(ds, eax - 12, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, ebp);
    ebp = ebx + 2;
    ebx += 0x00000004;
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, edx - 16);
    memoryFSet32(ds, edx - 16, fp1);
    fp1 += memoryFGet32(ds, eax - 12);
    memoryFSet32(ds, edx - 16, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, ebp);
    ebp = memoryAGet32(ds, esp + 0x20);
    ebp -= 0x00000004;
    fdiv80(st(1));
    memoryASet32(ds, esp + 0x20, ebp);
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) - 1);
    fp1 *= memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, eax - 8, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, ebx);
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, edx - 12);
    memoryFSet32(ds, edx - 12, fp1);
    fp1 += memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, edx - 12, fp1);
    if (memoryAGet32(ds, esp + 0x24))
        goto loc_1006f783;
    ebp = memoryAGet32(ds, esp + 0x18);

loc_1006f855: // 0000:1006f855
    if ((int32_t)edi >= (int32_t)ebp)
        goto loc_1006f8bd;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x10);
    edx = edi - 10;
    memoryASet32(ds, esp + 0x28, edx);
    edx = memoryAGet32(ds, esp + 0x10);
    edx -= edi;
    edx += 0x0000000a;
    eax = (ecx + (edi * 4)) + 40;
    memoryASet32(ds, esp + 0x20, edx);
    goto loc_1006f880;
    // gap 9 bytes // gap 9 bytes
loc_1006f880: // 0000:1006f880
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    ebx = memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esp + 0x28);
    edi++;
    fdiv80(st(1));
    ebx--;
    edx++;
    eax += 0x00000004;
    memoryASet32(ds, esp + 0x20, ebx);
    fp1 *= memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x28, edx);
    fdiv80(st(1));
    fp1 *= memoryFGet32(ds, esi + edi * 4 - 4);
    memoryFSet32(ds, esi + edi * 4 - 4, fp1);
    fp1 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, esi + edi * 4 - 4, fp1);
    if ((int32_t)edi < (int32_t)ebp)
        goto loc_1006f880;

loc_1006f8bd: // 0000:1006f8bd
    memoryASet32(ds, ecx + 0x24, 0x00000000);
loc_1006f8c4: // 0000:1006f8c4
    fp0 = memoryFGet32(ds, ecx + 0xf0);
    edi = pop32();
    _cmp0r = (double)fromFp32(0x8704ec3du);

    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    if (fp0 <= _cmp0r)  // fp0 vs (double)fromFp32(0x8704ec3du)
        goto loc_1006f8f8;
    fp0 = memoryFGet32(ds, ecx + 0xf0);
    _cmp1r = (double)fromFp32(0x0704ec3du);

    if (fp0 >= _cmp1r)  // fp0 vs (double)fromFp32(0x0704ec3du)
        goto loc_1006f8f8;
    memoryASet32(ds, ecx + 0xf0, 0x00000000);
loc_1006f8f8: // 0000:1006f8f8
    fp0 = memoryFGet32(ds, ecx + 0x4);
    _cmp2r = (double)fromFp32(0x8704ec3du);

    if (fp0 <= _cmp2r)  // fp0 vs (double)fromFp32(0x8704ec3du)
        goto loc_1006f91f;
    fp0 = memoryFGet32(ds, ecx + 0x4);
    _cmp3r = (double)fromFp32(0x0704ec3du);

    if (fp0 >= _cmp3r)  // fp0 vs (double)fromFp32(0x0704ec3du)
        goto loc_1006f91f;
    memoryASet32(ds, ecx + 0x4, 0x00000000);
loc_1006f91f: // 0000:1006f91f
    esp += 0x0000000c;
    esp += 16;
}

void subopt_100ca3f6(double fp0) // 0000:100ca3f6 +long
{
    // Caller uses eax as a positive sample count; (int32_t) truncation is equivalent.
    eax = (int32_t)fp0;
}

#if 0 // emulated subopt_100ca3f6 body preserved for reference
void subopt_100ca3f6_emulated(double fp0) // 0000:100ca3f6 +long
{
    double fp1;
    StackGuard _sg(0, __FUNCTION__);
    bool temp_cf;
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000020;
    esp &= 0xfffffff0;
    fp1 = fp0;
    memoryFSet32(ds, esp + 0x18, fp1);
    memoryASet64(ds, esp + 0x10, (int64_t)floor(fp1));
    fp1 = (double)(int64_t)memoryAGet64(ds, esp + 0x10);
    edx = memoryAGet32(ds, esp + 0x18);
    eax = memoryAGet32(ds, esp + 0x10);
    if (!eax)
        goto loc_100ca455;
loc_100ca419:
    fp0 -= fp1;
    if ((int32_t)edx >= 0)
        goto loc_100ca43d;
    memoryFSet32(ds, esp, fp0);
    ecx = memoryAGet32(ds, esp);
    ecx ^= 0x80000000;
    flags.carry = overflow32(ecx, 0x7fffffff);
    ecx += 0x7fffffff;
    temp_cf = flags.carry;
    temp_cf = overflow32(eax, 0x00000000, flags.carry);
    eax += (0x00000000 + flags.carry);
    flags.carry = temp_cf;
    edx = memoryAGet32(ds, esp + 0x14);
    edx += (0x00000000 + flags.carry);
    goto loc_100ca469;
loc_100ca43d:
    memoryFSet32(ds, esp, fp0);
    ecx = memoryAGet32(ds, esp);
    flags.carry = overflow32(ecx, 0x7fffffff);
    ecx += 0x7fffffff;
    temp_cf = flags.carry;
    temp_cf = eax < 0x00000000 + flags.carry;
    eax -= (0x00000000 + flags.carry);
    flags.carry = temp_cf;
    edx = memoryAGet32(ds, esp + 0x14);
    edx -= (0x00000000 + flags.carry);
    goto loc_100ca469;
loc_100ca455:
    edx = memoryAGet32(ds, esp + 0x14);
    if (edx & 0x7fffffff)
        goto loc_100ca419;
    memoryFSet32(ds, esp + 0x18, fp1);
    memoryFSet32(ds, esp + 0x18, fp0);
loc_100ca469:
    esp = ebp; ebp = pop32();
    esp += 4;
}
#endif // end emulated reference

// ============================================================
// subopt_1006efe0 native
// Ring-buffer delay exchange: for each sample, outputs the old
// ring-buffer value and stores the incoming sample into the ring.
// Called in-place: in == out (same float* buffer).
//
// Object layout (self = ecx):
//   self + 0x4  : float* bufStart  (ring buffer base)
//   self + 0x8  : float* writePtr  (current position, byte-addressed)
//   self + 0xc  : int32  bufCount  (length in floats)
//
// Stack args (stackDrop12, last-pushed = esp+0):
//   esp+0  : float* in  (input  buffer)
//   esp+4  : float* out (output buffer)
//   esp+8  : int    samples
// ============================================================

static void subopt_1006efe0_native(uint8_t* self, float* in, float* out, int samples)
{
    float* const bufStart = *(float**)(self + 0x4);
    float*       writePtr = *(float**)(self + 0x8);
    const int    bufCount = *(int32_t*)(self + 0xc);
    float* const limit    = bufStart + bufCount - 1;

    for (int i = 0; i < samples; ++i)
    {
        const float old = *writePtr;
        *writePtr       = in[i];
        out[i]          = old;
        if (++writePtr > limit)
            writePtr = bufStart;
    }

    *(float**)(self + 0x8) = writePtr;
}

void subopt_1006efe0() // 0000:1006efe0 +long +stackDrop12
{
    float* in    = *(float**)(esp + 0);
    float* out   = *(float**)(esp + 4);
    int    count = *(int32_t*)(esp + 8);
    subopt_1006efe0_native((uint8_t*)ecx, in, out, count);
    esp += 12;
}

#if 0 // emulated body preserved for reference
void subopt_1006efe0_emulated() // 0000:1006efe0 +long +stackDrop12
{
    float fp0;
    StackGuard _sg(12, __FUNCTION__);
    esp -= 4;
    edx = memoryAGet32(ds, ecx + 0x4);
    eax = memoryAGet32(ds, ecx + 0xc);
    esp -= 0x00000008;
    push32(ebx);
    push32(ebp);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x24);
    ebx = 0x00000004;
    ebp = 0;
    esi = (edx + (eax * 4)) + -4;
    edx = memoryAGet32(ds, esp + 0x20);
    if ((int32_t)edi < (int32_t)ebx)
        goto loc_1006f0c1;
    eax = edi - 4;
    eax >>= 2;
    eax++;
    memoryASet32(ds, esp + 0x10, eax);
    eax <<= 2;
    memoryASet32(ds, esp + 0x14, eax);
    eax = memoryAGet32(ds, esp + 0x1c);
    edi = edi;
loc_1006f020: // 0000:1006f020
    edi = memoryAGet32(ds, ecx + 0x8);
    ebp = memoryAGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi);
    memoryASet32(ds, edi, ebp);
    memoryFSet32(ds, edx, fp0);
    ebp = memoryAGet32(ds, ecx + 0x8);
    ebp += ebx;
    edi = ebp;
    memoryASet32(ds, ecx + 0x8, ebp);
    if (edi <= esi)
        goto loc_1006f03f;
    edi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edi);
loc_1006f03f: // 0000:1006f03f
    edi = memoryAGet32(ds, ecx + 0x8);
    ebp = memoryAGet32(ds, eax + 0x4);
    fp0 = memoryFGet32(ds, edi);
    memoryASet32(ds, edi, ebp);
    memoryFSet32(ds, edx + 0x4, fp0);
    ebp = memoryAGet32(ds, ecx + 0x8);
    ebp += ebx;
    edi = ebp;
    memoryASet32(ds, ecx + 0x8, ebp);
    if (edi <= esi)
        goto loc_1006f060;
    edi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edi);
loc_1006f060: // 0000:1006f060
    edi = memoryAGet32(ds, ecx + 0x8);
    ebp = memoryAGet32(ds, eax + 0x8);
    fp0 = memoryFGet32(ds, edi);
    memoryASet32(ds, edi, ebp);
    memoryFSet32(ds, edx + 0x8, fp0);
    ebp = memoryAGet32(ds, ecx + 0x8);
    ebp += ebx;
    edi = ebp;
    memoryASet32(ds, ecx + 0x8, ebp);
    if (edi <= esi)
        goto loc_1006f081;
    edi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edi);
loc_1006f081: // 0000:1006f081
    edi = memoryAGet32(ds, ecx + 0x8);
    ebp = memoryAGet32(ds, eax + 0xc);
    fp0 = memoryFGet32(ds, edi);
    memoryASet32(ds, edi, ebp);
    memoryFSet32(ds, edx + 0xc, fp0);
    ebp = memoryAGet32(ds, ecx + 0x8);
    ebp += ebx;
    edi = ebp;
    memoryASet32(ds, ecx + 0x8, ebp);
    if (edi <= esi)
        goto loc_1006f0a2;
    edi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edi);
loc_1006f0a2: // 0000:1006f0a2
    edi = memoryAGet32(ds, esp + 0x10);
    eax += 0x00000010;
    edx += 0x00000010;
    edi--;
    memoryASet32(ds, esp + 0x10, edi);
    if (edi)
        goto loc_1006f020;
    ebp = memoryAGet32(ds, esp + 0x14);
    edi = memoryAGet32(ds, esp + 0x24);
    goto loc_1006f0c5;
loc_1006f0c1: // 0000:1006f0c1
    eax = memoryAGet32(ds, esp + 0x1c);
loc_1006f0c5: // 0000:1006f0c5
    if ((int32_t)ebp >= (int32_t)edi)
        goto loc_1006f0fe;
    edi -= ebp;
    memoryASet32(ds, esp + 0x24, edi);
loc_1006f0d0: // 0000:1006f0d0
    edi = memoryAGet32(ds, ecx + 0x8);
    ebp = memoryAGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi);
    memoryASet32(ds, edi, ebp);
    memoryFSet32(ds, edx, fp0);
    ebp = memoryAGet32(ds, ecx + 0x8);
    ebp += ebx;
    edi = ebp;
    memoryASet32(ds, ecx + 0x8, ebp);
    if (edi <= esi)
        goto loc_1006f0ef;
    edi = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, ecx + 0x8, edi);
loc_1006f0ef: // 0000:1006f0ef
    edi = memoryAGet32(ds, esp + 0x24);
    eax += ebx;
    edx += ebx;
    edi--;
    memoryASet32(ds, esp + 0x24, edi);
    if (edi)
        goto loc_1006f0d0;
loc_1006f0fe: // 0000:1006f0fe
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000008;
    esp += 16;
}
#endif // end emulated reference

void subopt_1006d830() // 0000:1006d830 +long +stackDrop20
{
    float* inL = *(float**)(esp + 0);
    float* inR = *(float**)(esp + 4);
    float* outL = *(float**)(esp + 8);
    float* outR = *(float**)(esp + 12);
    int    samp = *(int32_t*)(esp + 16);
    sub_1006d830_native((uint8_t*)ecx, inL, inR, outL, outR, samp);
    esp += 20;
}

#if 0 // emulated subopt_1006d830 body preserved for reference
void subopt_1006d830() // 0000:1006d830 +long +stackDrop20
{
    double fp0;
    float fp1, fp2;
    double _cmp0r, _cmp1r;
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
    fp0 = (double)(int32_t)memoryAGet32(ds, esi + 0x42690);
    fp0 -= memoryFGet32(ds, esi + 0x42698);
    _cmp0r = (double)fromFp32(0x3f800000u);

    memoryFSet32(ds, esp + 0x10, fp0);
    if (fp0 >= _cmp0r)  // fp0 vs (double)fromFp32(0x3f800000u)
        goto loc_1006d8b7;
    fp0 += 34000.0f;
    memoryFSet32(ds, esp + 0x10, fp0);
loc_1006d8b7: // 0000:1006d8b7
    memoryFSet64(ds, esp + 0x20, fp0);
    fp0 = memoryFGet64(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x14, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x14);
    fp0 = memoryFGet32(ds, esi + eax * 4 + 0x4);
    ecx = memoryAGet32(ss, ebp + 0x8);
    fp1 = memoryFGet32(ds, esi + eax * 4 + 0x8);
    eax = memoryAGet32(ds, esi + 0x42690);
    fp2 = memoryFGet32(ds, esi + eax * 4 + 0x8);
    eax = (esi + (eax * 4)) + 8;
    fp2 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, eax, fp2);
    eax = memoryAGet32(ss, ebp + 0x10);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    fp2 = memoryFGet32(ds, esp + 0x10) - fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 -= fp0;
    fp1 *= fp2;
    fp0 += fp1;
    fp1 = fp0;
    memoryFSet32(ds, eax, fp1);
    fp0 *= memoryFGet32(ds, esi + 0x426f8);
    fp1 = memoryFGet32(ds, esi + 0x426d8);
    fp1 *= memoryFGet32(ds, esi + 0x426e8);
    fp0 += fp1;
    memoryFSet32(ds, esi + 0x426d8, fp0);
    fp0 *= memoryFGet32(ds, esi + 0x42714);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = (double)(int32_t)memoryAGet32(ds, esi + 0x42694);
    fp0 -= memoryFGet32(ds, esi + 0x4269c);
    _cmp1r = (double)fromFp32(0x3f800000u);

    memoryFSet32(ds, esp + 0x10, fp0);
    if (fp0 >= _cmp1r)  // fp0 vs (double)fromFp32(0x3f800000u)
        goto loc_1006d946;
    fp0 += 34000.0f;
    memoryFSet32(ds, esp + 0x10, fp0);
loc_1006d946: // 0000:1006d946
    memoryFSet64(ds, esp + 0x28, fp0);
    fp0 = memoryFGet64(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x18, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x18);
    fp0 = memoryFGet32(ds, esi + eax * 4 + 0x21348);
    ecx = memoryAGet32(ds, esi + 0x42694);
    fp1 = memoryFGet32(ds, esi + eax * 4 + 0x2134c);
    eax = (esi + (ecx * 4)) + 136012;
    fp2 = memoryFGet32(ds, eax);
    ecx = memoryAGet32(ss, ebp + 0xc);
    fp2 += memoryFGet32(ds, ecx);
    ecx = 0x00000001;
    memoryFSet32(ds, eax, fp2);
    eax = memoryAGet32(ss, ebp + 0x14);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    fp2 = memoryFGet32(ds, esp + 0x10) - fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 -= fp0;
    fp1 *= fp2;
    fp0 += fp1;
    fp1 = fp0;
    memoryFSet32(ds, eax, fp1);
    fp1 = memoryFGet32(ds, esi + 0x426dc);
    fp1 *= memoryFGet32(ds, esi + 0x426ec);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esi + 0x426fc);
    fp0 += fp1;
    memoryFSet32(ds, esi + 0x426dc, fp0);
    fp0 *= memoryFGet32(ds, esi + 0x42718);
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
    fp0 = -fp0;
    eax += 0x00000004;
    memoryFSet32(ds, esi + ebx * 4 + 0x8, fp0);
    fp0 = memoryFGet32(ds, esp + 0x20);
    memoryASet32(ss, ebp + 0x8, eax);
    eax = memoryAGet32(ss, ebp + 0x10);
    fp0 = -fp0;
    eax += 0x00000004;
    memoryFSet32(ds, esi + edx * 4 + 0x2134c, fp0);
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
    subopt_100704c0();
    edx = memoryAGet32(ds, esp + 0x10);
loc_1006da62: // 0000:1006da62
    fp0 = memoryFGet64(ds, edi + 0x20);
    ecx = esi + 272248;
    fp0 *= memoryFGet64(ds, edi + 0x30);
    fp0 -= memoryFGet64(ds, edi + 0x38);
    memoryFSet64(ds, edi + 0x28, fp0);
    fp0 = memoryFGet64(ds, edi + 0x30);
    memoryFSet64(ds, edi + 0x38, fp0);
    fp0 = memoryFGet64(ds, edi + 0x28);
    memoryFSet64(ds, edi + 0x30, fp0);
    fp0 = memoryFGet64(ds, edi + 0x28);
    fp0 += 1.0f;
    fp0 *= memoryFGet32(ds, esi + 0x426c0);
    memoryFSet32(ds, esi + 0x42698, fp0);
    al = memoryAGet(ds, ecx + 0x40);
    if (!al)
        goto loc_1006daa5;
    subopt_100704c0();
    edx = memoryAGet32(ds, esp + 0x10);
loc_1006daa5: // 0000:1006daa5
    fp0 = memoryFGet64(ds, esi + 0x42798);
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 *= memoryFGet64(ds, esi + 0x427a8);
    eax--;
    memoryASet32(ds, esp + 0x1c, eax);
    fp0 -= memoryFGet64(ds, esi + 0x427b0);
    memoryFSet64(ds, esi + 0x427a0, fp0);
    fp0 = memoryFGet64(ds, esi + 0x427a8);
    memoryFSet64(ds, esi + 0x427b0, fp0);
    fp0 = memoryFGet64(ds, esi + 0x427a0);
    memoryFSet64(ds, esi + 0x427a8, fp0);
    fp0 = memoryFGet64(ds, esi + 0x427a0);
    fp0 += 1.0f;
    fp0 *= memoryFGet32(ds, esi + 0x426c4);
    memoryFSet32(ds, esi + 0x4269c, fp0);
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

#endif // end emulated reference

void subopt_100704c0() // 0000:100704c0 +long
{
    double fp0, fp1;
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    push32(ecx);
    push32(esi);
    esi = ecx;
    eax = esi + 68;
    push32(eax);
    ecx = esp + 8;
    subopt_10070390();
    fp0 = memoryFGet64(ds, esi + 0x8);
    fp0 /= memoryFGet64(ds, esi);
    ecx = esp + 4;
    memoryASet(ds, esi + 0x40, 0x00);
    fp0 *= 6.2831854820251465;
    memoryFSet64(ds, esi + 0x10, fp0);
    fp1 = fp0;
    fp1 = cos(fp1);
    fp1 += fp1;
    memoryFSet64(ds, esi + 0x20, fp1);
    fp1 = memoryFGet64(ds, esi + 0x18);
    fp1 -= fp0;
    fp1 = sin(fp1);
    memoryFSet64(ds, esi + 0x30, fp1);
    fp0 += fp0;
    fp0 = memoryFGet64(ds, esi + 0x18) - fp0;
    fp0 = sin(fp0);
    memoryFSet64(ds, esi + 0x38, fp0);
    subopt_10070420();
    esi = pop32();
    ecx = pop32();
    esp += 4;
}

void subopt_10070390() // 0000:10070390 +long +stackDrop4
{
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    push32(ebx);
    push32(esi);
    esi = ecx;
    memoryASet32(ds, esi, eax);
    indirectCall(cs, 0x6ab0002fu, 0x0000, 0x1007039a); // 0000:1007039a
    ecx = memoryAGet32(ds, esi);
    push32(0x00000000);
    push32(0x00000001);
    push32(ecx);
    ebx = eax;
    indirectCall(cs, 0x6ab00017u, 0x0000, 0x100703a9); // 0000:100703a9
    if (eax)
        goto loc_100703c8;
    edx = memoryAGet32(ds, esi);
    memoryASet32(ds, edx + 0x4, 0x00000001);
    eax = memoryAGet32(ds, esi);
    memoryASet32(ds, eax + 0xc, ebx);
    eax = esi;
    esi = pop32();
    ebx = pop32();
    // SEH removed (was stack_unbalanced, 4/-8) // SEH removed (was stack_unbalanced, 4/-8)
    esp += 0x0000008; return; // SEH fixed: was +8, deficit 12
loc_100703c8: // 0000:100703c8
    eax = memoryAGet32(ds, esi);
    if (ebx != memoryAGet32(ds, eax + 0xc))
        goto loc_100703d9;
    memoryASet32(ds, eax + 0x4, memoryAGet32(ds, eax + 0x4) + 1);
    eax = esi;
    esi = pop32();
    ebx = pop32();
    // SEH fixed (was stack_unbalanced, 4/-8) // SEH fixed (was stack_unbalanced, 4/-8)
    esp += 8; return;
loc_100703d9: // 0000:100703d9
    push32(ebp);
    push32(edi);
    edi = 0x6ab00016u;
    push32(0xffffffff);
    push32(eax);
    indirectCall(cs, edi, 0x0000, 0x100703e4); // 0000:100703e4
    if (!eax)
        goto loc_10070409;
    ebp = 0x6ab0002au;
loc_100703f0: // 0000:100703f0
    ecx = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, ecx + 0x8);
    push32(0xffffffff);
    push32(edx);
    indirectCall(cs, ebp, 0x0000, 0x100703f8); // 0000:100703f8
    if (eax)
        goto loc_10070417;
    eax = memoryAGet32(ds, esi);
    push32(0xffffffff);
    push32(eax);
    indirectCall(cs, edi, 0x0000, 0x10070403); // 0000:10070403
    if (eax)
        goto loc_100703f0;
loc_10070409: // 0000:10070409
    ecx = memoryAGet32(ds, esi);
    memoryASet32(ds, ecx + 0x4, 0x00000001);
    edx = memoryAGet32(ds, esi);
    memoryASet32(ds, edx + 0xc, ebx);
loc_10070417: // 0000:10070417
    edi = pop32();
    ebp = pop32();
    eax = esi;
    esi = pop32();
    ebx = pop32();
    // SEH removed (was stack_unbalanced, 4/-16) // SEH removed (was stack_unbalanced, 4/-16)
    esp += 8;
}

void subopt_1006df90() // 0000:1006df90 +long +stackDrop20
{
    float* inL = *(float**)(esp + 0);
    float* inR = *(float**)(esp + 4);
    float* outL = *(float**)(esp + 8);
    float* outR = *(float**)(esp + 12);
    int    samp = *(int32_t*)(esp + 16);
    sub_1006df90_native((uint8_t*)ecx, inL, inR, outL, outR, samp);
    esp += 20;
}

#if 0 // emulated subopt_1006df90 body preserved for reference
void subopt_1006df90() // 0000:1006df90 +long +stackDrop20
{
    float fp0, fp1, fp2;
    double _cmp0r, _cmp1r, _cmp2r;
    StackGuard _sg(20, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000008;
    push32(ebx);
    ebx = ecx;
    fp0 = memoryFGet32(ds, ebx + 0x3ed6c);
    push32(ebp);
    fp0 *= memoryFGet32(ds, ebx + 0x3ed64);
    push32(esi);
    push32(edi);
    fp0 *= memoryFGet32(ds, ebx + 0x3e820);
    fp0 *= -0.0010000000474974513f;
    subopt_100ca3f6(fp0);
    fp0 = memoryFGet32(ds, ebx + 0x3ed50);
    _cmp0r = (double)fromFp32(0x3e4ccccdu);

    ecx = 0x00000004;
    ecx -= eax;
    ebp = ebx + (ecx * 8);
    if (fp0 <= _cmp0r)  // fp0 vs (double)fromFp32(0x3e4ccccdu)
        goto loc_1006e003;
    esi = memoryAGet32(ds, esp + 0x2c);
    edx = memoryAGet32(ds, ebx + 0x3ed2c);
    eax = memoryAGet32(ds, esp + 0x1c);
    ecx = memoryAGet32(ds, ebx + 0x4);
    push32(esi);
    push32(edx);
    push32(eax);
    subopt_1006fb80();
    ecx = memoryAGet32(ds, ebx + 0x3ed30);
    edx = memoryAGet32(ds, esp + 0x20);
    push32(esi);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x8);
    push32(edx);
    subopt_1006fb80();
    goto loc_1006e040;
loc_1006e003: // 0000:1006e003
    eax = memoryAGet32(ds, esp + 0x2c);
    edi = memoryAGet32(ds, ebx + 0x3ed2c);
    esi = memoryAGet32(ds, esp + 0x1c);
    eax <<= 2;
    ecx = eax;
    edx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = memoryAGet32(ds, ebx + 0x3ed30);
    esi = memoryAGet32(ds, esp + 0x20);
    ecx = eax;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = eax;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, esp + 0x2c);
loc_1006e040: // 0000:1006e040
    fp0 = memoryFGet32(ds, ebx + 0x3ed50);
    _cmp1r = (double)fromFp32(0x3ecccccdu);

    if (fp0 <= _cmp1r)  // fp0 vs (double)fromFp32(0x3ecccccdu)
        goto loc_1006e083;
    ecx = memoryAGet32(ds, ebx + 0x3ed34);
    edx = memoryAGet32(ds, ebx + 0x3ed2c);
    push32(esi);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0xc);
    push32(edx);
    subopt_1006fb80();
    eax = memoryAGet32(ds, ebx + 0x3ed38);
    ecx = memoryAGet32(ds, ebx + 0x3ed30);
    push32(esi);
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x10);
    subopt_1006fb80();
    goto loc_1006e0c4;
loc_1006e083: // 0000:1006e083
    edi = memoryAGet32(ds, ebx + 0x3ed34);
    eax = (esi * 4) + 0;
    esi = memoryAGet32(ds, ebx + 0x3ed2c);
    ecx = eax;
    edx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, ebx + 0x3ed30);
    edi = memoryAGet32(ds, ebx + 0x3ed38);
    ecx = eax;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = eax;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, esp + 0x2c);
loc_1006e0c4: // 0000:1006e0c4
    fp0 = memoryFGet32(ds, ebx + 0x3ed50);
    _cmp2r = (double)fromFp32(0x3f19999au);

    if (fp0 <= _cmp2r)  // fp0 vs (double)fromFp32(0x3f19999au)
        goto loc_1006e107;
    ecx = memoryAGet32(ds, ebx + 0x3ed3c);
    edx = memoryAGet32(ds, ebx + 0x3ed34);
    push32(esi);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x14);
    push32(edx);
    subopt_1006fb80();
    eax = memoryAGet32(ds, ebx + 0x3ed40);
    ecx = memoryAGet32(ds, ebx + 0x3ed38);
    push32(esi);
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x18);
    subopt_1006fb80();
    goto loc_1006e148;
loc_1006e107: // 0000:1006e107
    edi = memoryAGet32(ds, ebx + 0x3ed3c);
    eax = (esi * 4) + 0;
    esi = memoryAGet32(ds, ebx + 0x3ed34);
    ecx = eax;
    edx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = edx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, ebx + 0x3ed38);
    edi = memoryAGet32(ds, ebx + 0x3ed40);
    ecx = eax;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = eax;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ds, esp + 0x2c);
loc_1006e148: // 0000:1006e148
    edi = 0;
    if ((int32_t)esi <= 0)
        goto loc_1006e2f8;
    eax = memoryAGet32(ds, esp + 0x24);
    edx = memoryAGet32(ds, esp + 0x1c);
    edx -= eax;
    memoryASet32(ds, esp + 0x10, edx);
    edx = memoryAGet32(ds, esp + 0x20);
    edx -= eax;
    memoryASet32(ds, esp + 0x14, edx);
    edx = memoryAGet32(ds, esp + 0x28);
    ecx = eax;
    edx -= eax;
    memoryASet32(ds, esp + 0x24, ecx);
    memoryASet32(ds, esp + 0x28, edx);
    ebx = ebx;
loc_1006e180: // 0000:1006e180
    eax = memoryAGet32(ds, ebx + 0x3ed5c);
    edx = memoryAGet32(ds, ebx + 0x3ed2c);
    esi = memoryAGet32(ds, ebx + 0x3ed30);
    memoryASet32(ds, esp + 0x20, eax);
    eax = memoryAGet32(ds, ebx + 0x3ed58);
    memoryASet32(ds, esp + 0x1c, 0x00000000);
    if ((int32_t)eax <= 0)
        goto loc_1006e270;
    eax = ebx + 256524;
loc_1006e1b2: // 0000:1006e1b2
    ecx = memoryAGet32(ds, esp + 0x20);
    if (memoryAGet32(ds, esp + 0x1c) != ecx)
        goto loc_1006e1e8;
    if (ecx != memoryAGet32(ds, ebx + 0x3ed5c))
        goto loc_1006e1dc;
    ecx = memoryAGet32(ds, ebx + 0x3ed60);
    edx = memoryAGet32(ds, ebx + 0x3ed34);
    esi = memoryAGet32(ds, ebx + 0x3ed38);
    memoryASet32(ds, esp + 0x20, ecx);
    goto loc_1006e1e8;
loc_1006e1dc: // 0000:1006e1dc
    edx = memoryAGet32(ds, ebx + 0x3ed3c);
    esi = memoryAGet32(ds, ebx + 0x3ed40);
loc_1006e1e8: // 0000:1006e1e8
    fp0 = memoryFGet32(ds, edx + edi * 4);
    ecx = memoryAGet32(ds, eax);
    fp1 = memoryFGet32(ds, esi + edi * 4);
    fp2 = fp0;
    fp2 *= memoryFGet32(ds, eax + 0x1e0);
    fp2 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp2);
    ecx = memoryAGet32(ds, eax);
    ecx += 0x00000004;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, eax + 0x230);
    memoryASet32(ds, eax, ecx);
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
    ecx = memoryAGet32(ds, eax + 0x50);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, eax + 0x280);
    fp1 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp1);
    ecx = memoryAGet32(ds, eax + 0x50);
    ecx += 0x00000004;
    fp0 *= memoryFGet32(ds, eax + 0x2d0);
    memoryASet32(ds, eax + 0x50, ecx);
    fp0 += memoryFGet32(ds, ecx);
    memoryFSet32(ds, ecx, fp0);
    ecx = memoryAGet32(ds, eax);
    ecx += 0x00000004;
    memoryASet32(ds, eax, ecx);
    if (ecx < ebp)
        goto loc_1006e241;
    ecx = ebx + 32;
    memoryASet32(ds, eax, ecx);
loc_1006e241: // 0000:1006e241
    ecx = memoryAGet32(ds, eax + 0x50);
    ecx += 0x00000004;
    memoryASet32(ds, eax + 0x50, ecx);
    if (ecx < ebp)
        goto loc_1006e254;
    ecx = ebx + 32;
    memoryASet32(ds, eax + 0x50, ecx);
loc_1006e254: // 0000:1006e254
    ecx = memoryAGet32(ds, esp + 0x1c);
    ecx++;
    eax += 0x00000004;
    memoryASet32(ds, esp + 0x1c, ecx);
    if ((int32_t)ecx < (int32_t)memoryAGet32(ds, ebx + 0x3ed58))
        goto loc_1006e1b2;
    ecx = memoryAGet32(ds, esp + 0x24);
loc_1006e270: // 0000:1006e270
    edx = memoryAGet32(ds, esp + 0x10);
    fp0 = memoryFGet32(ds, edx + ecx);
    eax = memoryAGet32(ds, ebx + 0x3e828);
    fp0 *= memoryFGet32(ds, ebx + 0x3ed4c);
    esi = memoryAGet32(ds, esp + 0x14);
    fp0 += memoryFGet32(ds, eax);
    memoryFSet32(ds, ecx, fp0);
    edx = memoryAGet32(ds, ebx + 0x3e828);
    memoryASet32(ds, edx, 0x00000000);
    eax = memoryAGet32(ds, ebx + 0x3e828);
    edx = 0x00000004;
    eax += edx;
    memoryASet32(ds, ebx + 0x3e828, eax);
    fp0 = memoryFGet32(ds, esi + ecx);
    fp0 *= memoryFGet32(ds, ebx + 0x3ed4c);
    fp0 += memoryFGet32(ds, eax);
    eax = memoryAGet32(ds, esp + 0x28);
    memoryFSet32(ds, eax + ecx, fp0);
    eax = memoryAGet32(ds, ebx + 0x3e828);
    memoryASet32(ds, eax, 0x00000000);
    esi = memoryAGet32(ds, ebx + 0x3e828);
    esi += edx;
    eax = esi;
    memoryASet32(ds, ebx + 0x3e828, esi);
    if (eax < ebp)
        goto loc_1006e2e5;
    eax = ebx + 32;
    memoryASet32(ds, ebx + 0x3e828, eax);
loc_1006e2e5: // 0000:1006e2e5
    eax = memoryAGet32(ds, esp + 0x2c);
    edi++;
    ecx += edx;
    memoryASet32(ds, esp + 0x24, ecx);
    if ((int32_t)edi < (int32_t)eax)
        goto loc_1006e180;
loc_1006e2f8: // 0000:1006e2f8
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000008;
    esp += 24;
}

#endif // end emulated reference

void subopt_1006fb80() // 0000:1006fb80 +long +stackDrop12
{
    float* in = *(float**)(esp + 0);
    float* out = *(float**)(esp + 4);
    int    samp = *(int32_t*)(esp + 8);
    sub_1006fb80_native((uint8_t*)ecx, in, out, samp);
    esp += 12;
}

#if 0 // emulated subopt_1006fb80 body preserved for reference
void subopt_1006fb80() // 0000:1006fb80 +long +stackDrop12
{
    float fp0, fp1;
    StackGuard _sg(12, __FUNCTION__);
    bool temp_cond0;
    esp -= 4;
    push32(ecx);
    eax = memoryAGet32(ds, ecx + 0xc);
    edx = memoryAGet32(ds, esp + 0xc);
    push32(ebx);
    push32(ebp);
    push32(esi);
    memoryASet32(ds, esp + 0xc, eax);
    eax = memoryAGet32(ds, ecx + 0xfb4);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x20);
    temp_cond0 = (int32_t)eax < (int32_t)edi;
    eax = memoryAGet32(ds, esp + 0x18);
    esi = 0x00000004;
    if (temp_cond0)
        goto loc_1006fccd;
    ebp = 0;
    if ((int32_t)edi < (int32_t)esi)
        goto loc_1006fc6d;
    ebx = edi - 4;
    ebx >>= 2;
    ebx++;
    ebp = (ebx * 4) + 0;
loc_1006fbc3: // 0000:1006fbc3
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    fp0 *= memoryFGet32(ds, eax);
    eax += 0x00000010;
    edx += 0x00000010;
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax - 16);
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx - 16, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax - 12);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax - 12);
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx - 12, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax - 8);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx - 8, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax - 4);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx - 4, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    edi += esi;
    ebx--;
    memoryASet32(ds, ecx + 0xfb0, edi);
    if (ebx)
        goto loc_1006fbc3;
    edi = memoryAGet32(ds, esp + 0x20);
loc_1006fc6d: // 0000:1006fc6d
    if ((int32_t)ebp >= (int32_t)edi)
        goto loc_1006fcb3;
    ebx = edi;
    ebx -= ebp;
    goto loc_1006fc80;
    // gap 9 bytes // gap 9 bytes
loc_1006fc80: // 0000:1006fc80
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 *= memoryFGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    ebp = memoryAGet32(ds, ecx + 0xfb0);
    ebp += esi;
    edx += esi;
    ebx--;
    memoryASet32(ds, ecx + 0xfb0, ebp);
    if (ebx)
        goto loc_1006fc80;
    edi = memoryAGet32(ds, esp + 0x20);
loc_1006fcb3: // 0000:1006fcb3
    eax = memoryAGet32(ds, ecx + 0xfb4);
    eax -= edi;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    memoryASet32(ds, ecx + 0xfb4, eax);
    memoryASet(ds, ecx + 0x4, 0x00);
    ebx = pop32();
    ecx = pop32();
    esp += 16; return;
loc_1006fccd: // 0000:1006fccd
    ebp = ecx + 16;
loc_1006fcd0: // 0000:1006fcd0
    ebx = 0;
    if ((int32_t)memoryAGet32(ds, ecx + 0xfb4) <= (int32_t)ebx)
        goto loc_1006fd1b;
    ebx = ebx;
loc_1006fce0: // 0000:1006fce0
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    fp0 *= memoryFGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    edi += esi;
    edx += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    edi = memoryAGet32(ds, ecx + 0xfb4);
    ebx++;
    if ((int32_t)ebx < (int32_t)edi)
        goto loc_1006fce0;
    edi = memoryAGet32(ds, esp + 0x20);
loc_1006fd1b: // 0000:1006fd1b
    edi -= memoryAGet32(ds, ecx + 0xfb4);
    ebx = memoryAGet32(ds, ecx + 0x8);
    memoryASet32(ds, esp + 0x20, edi);
    memoryASet32(ds, ecx + 0xfb0, ebp);
    memoryASet32(ds, ecx + 0xfb4, ebx);
    if ((int32_t)ebx <= (int32_t)edi)
        goto loc_1006fcd0;
    ebx = edi;
    ebp = 0;
    if ((int32_t)ebx < (int32_t)esi)
        goto loc_1006fdfb;
    ebx += 0xfffffffc;
    ebx >>= 2;
    ebx++;
    ebp = (ebx * 4) + 0;
loc_1006fd52: // 0000:1006fd52
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    fp0 *= memoryFGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax);
    edx += esi;
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax);
    edx += esi;
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi += esi;
    memoryASet32(ds, ecx + 0xfb0, edi);
    fp0 *= memoryFGet32(ds, eax);
    edx += esi;
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    edi += esi;
    edx += esi;
    ebx--;
    memoryASet32(ds, ecx + 0xfb0, edi);
    if (ebx)
        goto loc_1006fd52;
    ebx = memoryAGet32(ds, esp + 0x20);
loc_1006fdfb: // 0000:1006fdfb
    if ((int32_t)ebp >= (int32_t)ebx)
        goto loc_1006fe34;
    ebx -= ebp;
loc_1006fe01: // 0000:1006fe01
    fp0 = memoryFGet32(ds, esp + 0x10);
    edi = memoryAGet32(ds, ecx + 0xfb0);
    fp0 *= memoryFGet32(ds, eax);
    fp0 = memoryFGet32(ds, edi) - fp0;
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax);
    eax += esi;
    memoryFSet32(ds, edi, fp1);
    memoryFSet32(ds, edx, fp0);
    ebp = memoryAGet32(ds, ecx + 0xfb0);
    ebp += esi;
    edx += esi;
    ebx--;
    memoryASet32(ds, ecx + 0xfb0, ebp);
    if (ebx)
        goto loc_1006fe01;
    ebx = memoryAGet32(ds, esp + 0x20);
loc_1006fe34: // 0000:1006fe34
    eax = memoryAGet32(ds, ecx + 0xfb4);
    edi = pop32();
    esi = pop32();
    eax -= ebx;
    ebp = pop32();
    memoryASet32(ds, ecx + 0xfb4, eax);
    memoryASet(ds, ecx + 0x4, 0x00);
    ebx = pop32();
    ecx = pop32();
    esp += 16;
}

#endif // end emulated reference

void subopt_1006ff60() // 0000:1006ff60 +long +stackDrop8
{
    float* out = *(float**)(esp + 0);
    int    samp = *(int32_t*)(esp + 4);
    sub_1006ff60_native((char*)ecx, out, samp);
    esp += 8;
}

#if 0 // emulated subopt_1006ff60 body preserved for reference
void subopt_1006ff60() // 0000:1006ff60 +long +stackDrop8
{
    float fp0, fp1;
    double _cmp0r, _cmp1r, _cmp2r, _cmp3r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000008;
    eax = memoryAGet32(ds, ecx + 0x70);
    edx = memoryAGet32(ds, ecx + 0x78);
    memoryASet32(ds, esp + 0x4, eax);
    al = memoryAGet(ds, ecx + 0x9);
    memoryASet32(ds, esp, edx);
    if (!al)
        goto loc_1006ff87;
    eax = memoryAGet32(ds, ecx + 0x30);
    edx = memoryAGet32(ds, ecx + 0x2c);
    memoryASet32(ds, ecx + 0x28, eax);
    memoryASet32(ds, ecx + 0x24, edx);
    memoryASet(ds, ecx + 0x9, 0x00);
loc_1006ff87: // 0000:1006ff87
    eax = memoryAGet32(ds, ecx + 0xc);
    if (!eax)
        goto loc_1007017a;
    eax = memoryAGet32(ds, ecx + 0x84);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x14);
    push32(ebp);
    push32(esi);
    push32(edi);
    if ((int32_t)eax < (int32_t)ebx)
        goto loc_1007001b;
    if ((int32_t)ebx <= 0)
        goto loc_10070116;
    eax = memoryAGet32(ds, esp + 0x1c);
    esi = ebx;
    edi = 0x00000004;
    ebp = 0xfffffffc;
    esp = esp;
loc_1006ffc0: // 0000:1006ffc0
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp0 = memoryFGet32(ds, edx);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp1);
    edx = memoryAGet32(ds, ecx + 0x24);
    fp1 = memoryFGet32(ds, edx);
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp1 *= memoryFGet32(ds, ecx + 0x38);
    eax += edi;
    fp0 += fp1;
    fp0 *= memoryFGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, ecx + 0x68);
    fp0 += fp1;
    memoryFSet32(ds, ecx + 0x68, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0x14);
    fp0 = -fp0;
    memoryFSet32(ds, edx, fp0);
    edx = memoryAGet32(ds, ecx + 0x24);
    edx += ebp;
    memoryASet32(ds, ecx + 0x24, edx);
    if (edx >= memoryAGet32(ds, ecx + 0x20))
        goto loc_1007000b;
    ebx = memoryAGet32(ds, ecx + 0x28);
    edx = edx + (ebx * 4);
    ebx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, ecx + 0x24, edx);
loc_1007000b: // 0000:1007000b
    edx = memoryAGet32(ds, ecx + 0x1c);
    edx += edi;
    esi--;
    memoryASet32(ds, ecx + 0x1c, edx);
    if (esi)
        goto loc_1006ffc0;
    goto loc_10070116;
loc_1007001b: // 0000:1007001b
    eax = memoryAGet32(ds, esp + 0x1c);
    edi = 0x00000004;
    ebp = 0xfffffffc;
    esp = esp;
loc_10070030: // 0000:10070030
    edx = memoryAGet32(ds, ecx + 0x84);
    esi = 0;
    if ((int32_t)edx <= 0)
        goto loc_10070099;
    esp = esp;
loc_10070040: // 0000:10070040
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp0 = memoryFGet32(ds, edx);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp1);
    edx = memoryAGet32(ds, ecx + 0x24);
    fp1 = memoryFGet32(ds, edx);
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp1 *= memoryFGet32(ds, ecx + 0x38);
    eax += edi;
    fp0 += fp1;
    fp0 *= memoryFGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, ecx + 0x68);
    fp0 += fp1;
    memoryFSet32(ds, ecx + 0x68, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0x14);
    fp0 = -fp0;
    memoryFSet32(ds, edx, fp0);
    edx = memoryAGet32(ds, ecx + 0x24);
    edx += ebp;
    memoryASet32(ds, ecx + 0x24, edx);
    if (edx >= memoryAGet32(ds, ecx + 0x20))
        goto loc_1007008b;
    ebx = memoryAGet32(ds, ecx + 0x28);
    edx = edx + (ebx * 4);
    ebx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, ecx + 0x24, edx);
loc_1007008b: // 0000:1007008b
    memoryASet32(ds, ecx + 0x1c, memoryAGet32(ds, ecx + 0x1c) + edi);
    edx = memoryAGet32(ds, ecx + 0x84);
    esi++;
    if ((int32_t)esi < (int32_t)edx)
        goto loc_10070040;
loc_10070099: // 0000:10070099
    edx = memoryAGet32(ds, ecx + 0x18);
    ebx -= memoryAGet32(ds, ecx + 0x84);
    memoryASet32(ds, ecx + 0x1c, edx);
    edx = memoryAGet32(ds, ecx + 0xc);
    memoryASet32(ds, esp + 0x20, ebx);
    memoryASet32(ds, ecx + 0x84, edx);
    if ((int32_t)edx <= (int32_t)ebx)
        goto loc_10070030;
    if ((int32_t)ebx <= 0)
        goto loc_10070116;
    esi = ebx;
loc_100700c0: // 0000:100700c0
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp0 = memoryFGet32(ds, edx);
    fp1 = fp0;
    fp1 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp1);
    edx = memoryAGet32(ds, ecx + 0x24);
    fp1 = memoryFGet32(ds, edx);
    edx = memoryAGet32(ds, ecx + 0x1c);
    fp1 *= memoryFGet32(ds, ecx + 0x38);
    eax += edi;
    fp0 += fp1;
    fp0 *= memoryFGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, ecx + 0x68);
    fp0 += fp1;
    memoryFSet32(ds, ecx + 0x68, fp0);
    fp0 *= memoryFGet32(ds, ecx + 0x14);
    fp0 = -fp0;
    memoryFSet32(ds, edx, fp0);
    edx = memoryAGet32(ds, ecx + 0x24);
    edx += ebp;
    memoryASet32(ds, ecx + 0x24, edx);
    if (edx >= memoryAGet32(ds, ecx + 0x20))
        goto loc_1007010b;
    ebx = memoryAGet32(ds, ecx + 0x28);
    edx = edx + (ebx * 4);
    ebx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, ecx + 0x24, edx);
loc_1007010b: // 0000:1007010b
    edx = memoryAGet32(ds, ecx + 0x1c);
    edx += edi;
    esi--;
    memoryASet32(ds, ecx + 0x1c, edx);
    if (esi)
        goto loc_100700c0;
loc_10070116: // 0000:10070116
    fp0 = memoryFGet32(ds, ecx + 0x68);
    eax = memoryAGet32(ds, ecx + 0x84);
    _cmp0r = (double)fromFp32(0x8704ec3du);

    eax -= ebx;
    edi = pop32();
    memoryASet32(ds, ecx + 0x84, eax);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    if (fp0 <= _cmp0r)  // fp0 vs (double)fromFp32(0x8704ec3du)
        goto loc_1007014f;
    fp0 = memoryFGet32(ds, ecx + 0x68);
    _cmp1r = (double)fromFp32(0x0704ec3du);

    if (fp0 >= _cmp1r)  // fp0 vs (double)fromFp32(0x0704ec3du)
        goto loc_1007014f;
    memoryASet32(ds, ecx + 0x68, 0x00000000);
loc_1007014f: // 0000:1007014f
    fp0 = memoryFGet32(ds, ecx + 0x6c);
    _cmp2r = (double)fromFp32(0x8704ec3du);

    if (fp0 <= _cmp2r)  // fp0 vs (double)fromFp32(0x8704ec3du)
        goto loc_10070176;
    fp0 = memoryFGet32(ds, ecx + 0x6c);
    _cmp3r = (double)fromFp32(0x0704ec3du);

    if (fp0 >= _cmp3r)  // fp0 vs (double)fromFp32(0x0704ec3du)
        goto loc_10070176;
    memoryASet32(ds, ecx + 0x6c, 0x00000000);
loc_10070176: // 0000:10070176
    memoryASet(ds, ecx + 0x8, 0x00);
loc_1007017a: // 0000:1007017a
    esp += 0x00000008;
    esp += 12;
}

#endif // end emulated reference

void subopt_1006ce60() // 0000:1006ce60 +long +stackDrop16
{
    double fp0, fp3, fp4, fp5, fp6;
    float fp1, fp2;
    double _cmp1r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x00000024;
    push32(ebx);
    ebx = ecx;
    fp0 = memoryFGet32(ds, ebx + 0x10);
    push32(esi);
    fp1 = memoryFGet32(ds, ebx + 0xc);
    push32(edi);

    if (fp1 == fp0)  // fp1 vs fp0
        goto loc_1006d0b8;
    al = memoryAGet(ds, ebx + 0x8);
    if (!al)
        goto loc_1006d0b8;
    fp0 = memoryFGet32(ds, ebx + 0xc);
    _cmp1r = (double)fromFp32(memoryAGet32(ds, ebx + 0x10));

    if (fp0 <= _cmp1r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, ebx + 0x10))
        goto loc_1006ceb2;
    eax = memoryAGet32(ds, ebx + 0x28);
    esi = memoryAGet32(ss, ebp + 0x10);
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    eax += 0x00000010;
    push32(eax);
    push32(ecx);
    ecx = memoryAGet32(ds, ebx + 0x4c);
    subopt_1006f230();
    goto loc_1006cec3;
loc_1006ceb2: // 0000:1006ceb2
    edi = memoryAGet32(ds, ebx + 0x28);
    ecx = memoryAGet32(ss, ebp + 0x10);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi += 0x00000010;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    esi = memoryAGet32(ss, ebp + 0x10);
loc_1006cec3: // 0000:1006cec3
    fp0 = (double)(int32_t)memoryAGet32(ss, ebp + 0x10);
    memoryFSet64(ds, esp + 0x18, fp0);
    fp0 += 1.0;
    fp0 -= memoryFGet64(ds, ebx + 0x20);
    fp0 /= memoryFGet64(ds, ebx + 0x18);
    fp0 += 1.0;
    subopt_100ca3f6(fp0);
    fp0 = memoryFGet64(ds, ebx + 0x20);
    memoryFSet64(ds, esp + 0x28, fp0);
    memoryASet32(ds, esp + 0x14, eax);
    edi = 0x00000004;
    if ((int32_t)eax <= 0)
        goto loc_1006cfa2;
    edx = eax;
    goto loc_1006cf00;
    // gap 3 bytes // gap 3 bytes
loc_1006cf00: // 0000:1006cf00
    fp0 = memoryFGet64(ds, ebx + 0x20);
    memoryFSet64(ds, esp + 0x20, fp0);
    fp0 = memoryFGet64(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, ebx + 0x28);
    fp0 = memoryFGet64(ds, ebx + 0x20);
    fisub32(memoryAGet32(ds, esp + 0x10));
    ecx = memoryAGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, eax + ecx * 4 - 4);
    fp2 = memoryFGet32(ds, eax + ecx * 4);
    fp3 = memoryFGet32(ds, eax + ecx * 4 + 0x4);
    fp4 = memoryFGet32(ds, eax + ecx * 4 + 0x8);
    fp5 = fp3;
    fp5 += fp5;
    eax = memoryAGet32(ds, ebx + 0x34);
    fp5 += fp1;
    fp6 = fp2;
    fp6 *= 5.0f;
    fp6 += fp4;
    fp6 *= 0.5f;
    fp5 -= fp6;
    fp6 = fp2;
    fp6 -= fp3;
    fp6 *= 3.0f;
    fp6 -= fp1;
    fp6 += fp4;
    fp6 *= 0.5f;
    fp6 *= fp0;
    fp5 += fp6;
    fp5 *= fp0;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    fp5 -= fp1;
    fp5 *= 0.5f;
    fp3 += fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= fp0;
    fp4 += fp2;
    memoryFSet32(ds, eax, fp4);
    eax = memoryAGet32(ds, ebx + 0x34);
    ecx = memoryAGet32(ds, ebx + 0x3c);

    eax += edi;


    memoryASet32(ds, ebx + 0x34, eax);

    if (eax < ecx)
        goto loc_1006cf92;
    ecx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x34, ecx);
loc_1006cf92: // 0000:1006cf92
    edx--;
    fp0 = memoryFGet64(ds, ebx + 0x18);
    fp0 += memoryFGet64(ds, ebx + 0x20);
    memoryFSet64(ds, ebx + 0x20, fp0);
    if (edx)
        goto loc_1006cf00;
loc_1006cfa2: // 0000:1006cfa2
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, ebx + 0x28);
    fp0 *= memoryFGet64(ds, ebx + 0x18);
    fp0 += memoryFGet64(ds, esp + 0x28);
    fp0 -= memoryFGet64(ds, esp + 0x18);
    memoryFSet64(ds, ebx + 0x20, fp0);
    edx = memoryAGet32(ds, eax + esi * 4);
    memoryASet32(ds, eax, edx);
    eax = memoryAGet32(ds, ebx + 0x28);
    ecx = memoryAGet32(ds, eax + esi * 4 + 0x4);
    memoryASet32(ds, eax + 0x4, ecx);
    eax = memoryAGet32(ds, ebx + 0x28);
    edx = memoryAGet32(ds, eax + esi * 4 + 0x8);
    memoryASet32(ds, eax + 0x8, edx);
    eax = memoryAGet32(ds, ebx + 0x28);
    ecx = memoryAGet32(ds, eax + esi * 4 + 0xc);
    esi = memoryAGet32(ss, ebp + 0x14);
    memoryASet32(ds, eax + 0xc, ecx);
    ecx = 0;
    if ((int32_t)esi < (int32_t)edi)
        goto loc_1006d07f;
    eax = memoryAGet32(ss, ebp + 0xc);
    esi += 0xfffffffc;
    esi >>= 2;
    eax += 0x00000008;
    esi++;
    ecx = (esi * 4) + 0;
    goto loc_1006d000;
    // gap 3 bytes // gap 3 bytes
loc_1006d000: // 0000:1006d000
    edx = memoryAGet32(ds, ebx + 0x38);
    fp0 = memoryFGet32(ds, edx);
    fp0 += memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, eax - 8, fp0);
    edx = memoryAGet32(ds, ebx + 0x38);
    edx += edi;
    memoryASet32(ds, ebx + 0x38, edx);
    if (edx < memoryAGet32(ds, ebx + 0x3c))
        goto loc_1006d01e;
    edx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x38, edx);
loc_1006d01e: // 0000:1006d01e
    edx = memoryAGet32(ds, ebx + 0x38);
    fp0 = memoryFGet32(ds, edx);
    fp0 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp0);
    edx = memoryAGet32(ds, ebx + 0x38);
    edx += edi;
    memoryASet32(ds, ebx + 0x38, edx);
    if (edx < memoryAGet32(ds, ebx + 0x3c))
        goto loc_1006d03c;
    edx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x38, edx);
loc_1006d03c: // 0000:1006d03c
    edx = memoryAGet32(ds, ebx + 0x38);
    fp0 = memoryFGet32(ds, edx);
    fp0 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp0);
    edx = memoryAGet32(ds, ebx + 0x38);
    edx += edi;
    memoryASet32(ds, ebx + 0x38, edx);
    if (edx < memoryAGet32(ds, ebx + 0x3c))
        goto loc_1006d058;
    edx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x38, edx);
loc_1006d058: // 0000:1006d058
    edx = memoryAGet32(ds, ebx + 0x38);
    fp0 = memoryFGet32(ds, edx);
    fp0 += memoryFGet32(ds, eax + 0x4);
    memoryFSet32(ds, eax + 0x4, fp0);
    edx = memoryAGet32(ds, ebx + 0x38);
    edx += edi;
    memoryASet32(ds, ebx + 0x38, edx);
    if (edx < memoryAGet32(ds, ebx + 0x3c))
        goto loc_1006d076;
    edx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x38, edx);
loc_1006d076: // 0000:1006d076
    eax += 0x00000010;
    esi--;
    if (esi)
        goto loc_1006d000;
    esi = memoryAGet32(ss, ebp + 0x14);
loc_1006d07f: // 0000:1006d07f
    if ((int32_t)ecx >= (int32_t)esi)
        goto loc_1006d130;
loc_1006d087: // 0000:1006d087
    eax = memoryAGet32(ds, ebx + 0x38);
    fp0 = memoryFGet32(ds, eax);
    eax = memoryAGet32(ss, ebp + 0xc);
    fp0 += memoryFGet32(ds, eax + ecx * 4);
    memoryFSet32(ds, eax + ecx * 4, fp0);
    eax = memoryAGet32(ds, ebx + 0x38);
    edx = memoryAGet32(ds, ebx + 0x3c);
    eax += edi;
    memoryASet32(ds, ebx + 0x38, eax);
    if (eax < edx)
        goto loc_1006d0aa;
    edx = memoryAGet32(ds, ebx + 0x2c);
    memoryASet32(ds, ebx + 0x38, edx);
loc_1006d0aa: // 0000:1006d0aa
    ecx++;
    if ((int32_t)ecx < (int32_t)esi)
        goto loc_1006d087;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 20; return;
loc_1006d0b8: // 0000:1006d0b8
    esi = memoryAGet32(ss, ebp + 0x14);
    ecx = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x8);
    edi = 0;
    if ((int32_t)esi < (int32_t)0x00000004)
        goto loc_1006d114;
    eax = ecx + 4;
    edx = ebx + 12;
    ebx -= ecx;
    ecx = esi - 4;
    ecx >>= 2;
    ecx++;
    edi = (ecx * 4) + 0;
    edi = edi;
loc_1006d0e0: // 0000:1006d0e0
    fp0 = memoryFGet32(ds, edx - 12);
    eax += 0x00000010;
    fp0 += memoryFGet32(ds, eax - 20);
    edx += 0x00000010;
    ecx--;
    memoryFSet32(ds, eax - 20, fp0);
    fp0 = memoryFGet32(ds, ebx + eax - 16);
    fp0 += memoryFGet32(ds, eax - 16);
    memoryFSet32(ds, eax - 16, fp0);
    fp0 = memoryFGet32(ds, edx - 20);
    fp0 += memoryFGet32(ds, eax - 12);
    memoryFSet32(ds, eax - 12, fp0);
    fp0 = memoryFGet32(ds, edx - 16);
    fp0 += memoryFGet32(ds, eax - 8);
    memoryFSet32(ds, eax - 8, fp0);
    if (ecx)
        goto loc_1006d0e0;
    ecx = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x8);
loc_1006d114: // 0000:1006d114
    if ((int32_t)edi >= (int32_t)esi)
        goto loc_1006d130;
    edx = ebx;
    edx -= ecx;
    eax = ecx + (edi * 4);
    esi -= edi;
loc_1006d121: // 0000:1006d121
    fp0 = memoryFGet32(ds, eax + edx);
    eax += 0x00000004;
    esi--;
    fp0 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp0);
    if (esi)
        goto loc_1006d121;
loc_1006d130: // 0000:1006d130
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 20;
}

