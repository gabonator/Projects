void sub_1005fc90() // 0000:1005fc90 +long +stackDrop20
{
    double fp0, fp1, fp2, fp3, fp4, fp5, fp6;
    float fp7;
    double _cmp2r, _cmp3r, _cmp7r, _cmp8r;
    StackGuard _sg(20, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x0000006c;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = (int32_t)eax * (int32_t)0x00000098;
    push32(ebx);
    ebx = ecx;
    edx = memoryAGet32(ds, eax + ebx + 0x140);
    ecx = (eax + ebx) + 176;
    push32(esi);
    eax = 0;
    push32(edi);
    memoryASet32(ds, esp + 0x28, ebx);
    memoryASet32(ds, esp + 0x5c, ecx);
    memoryASet32(ds, esp + 0x14, edx);
    if (!edx)
        goto loc_1006035f;
    al = memoryAGet(ds, edx + 0x14);
    if (!(al & 0x01))
        goto loc_1005fce5;
    if (memoryAGet32(ds, ebx + 0x9d84) == 0x00000002)
        goto loc_1005fce5;
    esi = memoryAGet32(ds, edx + 0x8);
    memoryASet(ds, esp + 0xf, 0x01);
    goto loc_1005fcec;
loc_1005fce5: // 0000:1005fce5
    memoryASet(ds, esp + 0xf, 0x00);
    esi = 0;
loc_1005fcec: // 0000:1005fcec
    edx = memoryAGet32(ds, ebx + 0x4);
    flags.zero = !(al & 0x02);
    eax = 0x00000000;
    al = !flags.zero;
    memoryASet32(ds, esp + 0x68, edx);
    edx = memoryAGet32(ds, ebx + 0x8);
    memoryASet32(ds, esp + 0x6c, edx);
    edx = memoryAGet32(ds, esp + 0x5c);
    memoryASet32(ds, esp + 0x18, esi);
    eax++;
    memoryASet32(ds, esp + 0x1c, eax);
    eax = memoryAGet32(ss, ebp + 0xc);
    fp0 = memoryFGet64(ds, ecx + eax * 8 + 0x40); // fld64(memoryAGet64(ds, ecx + eax * 8 + 0x40)) fpustack: [fp0]
    edi = memoryAGet32(ds, ecx + eax * 4 + 0x74);
    memoryFSet64(ds, esp + 0x70, fp0); // fst64()) fpustack: [fp0]
    memoryASet32(ds, esp + 0x10, edi);
    fp1 = memoryFGet64(ss, ebp + 0x10); // fld64(memoryAGet64(ss, ebp + 0x10)) fpustack: [fp1, fp0]
    fp2 = 0.0f; // fldz() fpustack: [fp2, fp1, fp0]
    fp3 = memoryFGet64(ds, 0x103d3c90); // fld64(memoryAGet64(ds, 0x103d3c90)) fpustack: [fp3, fp2, fp1, fp0]
loc_1005fd2f: // 0000:1005fd2f
    fp4 = fp1; // fldst(2) fpustack: [fp4, fp3, fp2, fp1, fp0]
    memoryFSet64(ds, esp + 0x60, fp4); // fst64()) fpustack: [fp4, fp3, fp2, fp1, fp0]
    if (!memoryAGet(ds, ecx + 0x95))
        goto loc_1005fd4c;
    if ((int32_t)edi < 0)
        goto loc_1005fd4c;
    // fstpst(0) (pop) fpustack: [fp3, fp2, fp1, fp0]
    fp4 = fp1; // fldst(2) fpustack: [fp4, fp3, fp2, fp1, fp0]
    fp4 = -fp4; // fchs() fpustack: [fp4, fp3, fp2, fp1, fp0]
    memoryFSet64(ds, esp + 0x60, fp4); // fst64()) fpustack: [fp4, fp3, fp2, fp1, fp0]
loc_1005fd4c: // 0000:1005fd4c
    // fcomst(2) fpustack: [fp4, fp3, fp2, fp1, fp0]
    if (fp4 >= fp2)  // fp4 vs fp2
        goto loc_1005fd88;
    if ((int32_t)edi >= (int32_t)esi)
        goto loc_1005fd88;
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_1005fdd8;
    eax = memoryAGet32(ds, ebx + 0x9d84);
    eax -= 0x00000000;
    if (!eax)
        goto loc_1005fdca;
    eax--;
    if (!eax)
        goto loc_1005fdbd;
    eax -= 0x00000002;
    if (eax)
        goto loc_1005fd88;
    fp4 = -fp4; // fchs() fpustack: [fp4, fp3, fp2, fp1, fp0]
    edi = esi;
    memoryFSet64(ds, esp + 0x60, fp4); // fst64()) fpustack: [fp4, fp3, fp2, fp1, fp0]
loc_1005fd7d: // 0000:1005fd7d
    memoryASet(ds, ecx + 0x95, 0x00);
loc_1005fd84: // 0000:1005fd84
    memoryASet32(ds, esp + 0x10, edi);
loc_1005fd88: // 0000:1005fd88
    if (!memoryAGet(ds, ecx + 0x94))
        goto loc_10060357;
    fp0 = fp4; // fstpst(4) fpustack: [fp3, fp2, fp1, fp0]
    fp1 = fp3; // fstpst(2) fpustack: [fp2, fp1, fp0]
    // fcompst(2) fpustack: [fp1, fp0]
    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005fdf2;
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_1005fdea;
    eax = edi;
    eax -= esi;
    memoryASet32(ds, esp + 0x40, eax);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x40); // fild32(memoryAGet32(ds, esp + 0x40)) fpustack: [fp2, fp1, fp0]
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }  // fxchst2(0, 1) fpustack: [fp2, fp1, fp0]
    fp0 = fp2 / fp0; // fdivrpst(2) fpustack: [fp1, fp0]
    fp0 *= fp1; // fmulpst(1) fpustack: [fp0]
    goto loc_1005fe1d;
loc_1005fdbd: // 0000:1005fdbd
    eax = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, eax + 0xc);
    eax -= esi;
    edi += eax;
    goto loc_1005fd84;
loc_1005fdca: // 0000:1005fdca
    eax = esi;
    fp4 = -fp4; // fchs() fpustack: [fp4, fp3, fp2, fp1, fp0]
    eax -= edi;
    memoryFSet64(ds, esp + 0x60, fp4); // fst64()) fpustack: [fp4, fp3, fp2, fp1, fp0]
    edi = eax;
    goto loc_1005fd7d;
loc_1005fdd8: // 0000:1005fdd8
    if ((int32_t)edi >= 0)
        goto loc_1005fd88;
    // fstpst(0) (pop) fpustack: [fp3, fp2, fp1, fp0]
    memoryASet(ds, ecx + 0x94, 0x00);
    goto loc_100602f7;
loc_1005fdea: // 0000:1005fdea
    fp0 = fp1 / fp0; // fdivrpst(1) fpustack: [fp0]
    fp0 *= (double)(int32_t)memoryAGet32(ds, esp + 0x10); // fimul32(memoryAGet32(ds, esp + 0x10)) fpustack: [fp0]
    goto loc_1005fe1d;
loc_1005fdf2: // 0000:1005fdf2
    // fstpst(0) (pop) fpustack: [fp0]
    eax = memoryAGet32(ds, esp + 0x14);
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_1005fe0e;
    eax = memoryAGet32(ds, eax + 0xc);
    eax -= edi;
    memoryASet32(ds, esp + 0x40, eax);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x40); // fild32(memoryAGet32(ds, esp + 0x40)) fpustack: [fp1, fp0]
    goto loc_1005fe1b;
loc_1005fe0e: // 0000:1005fe0e
    eax = memoryAGet32(ds, eax + 0x4);
    eax -= edi;
    memoryASet32(ds, esp + 0x40, eax);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x40); // fild32(memoryAGet32(ds, esp + 0x40)) fpustack: [fp1, fp0]
loc_1005fe1b: // 0000:1005fe1b
    fp0 = fp1 / fp0; // fdivrpst(1) fpustack: [fp0]
loc_1005fe1d: // 0000:1005fe1d
    memoryFSet64(ds, esp + 0x48, fp0); // fstp64()) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x48); // fld64(memoryAGet64(ds, esp + 0x48)) fpustack: [fp0]
    memoryASet32(ds, esp + 0x2c, (int32_t)floor(fp0)); // fistp32()) fpustack: [empty]
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x2c); // fild32(memoryAGet32(ds, esp + 0x2c)) fpustack: [fp0]
    ebx = memoryAGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x24, ebx);
    fp0 = memoryFGet64(ds, esp + 0x48) - fp0; // fsubr64(memoryAGet64(ds, esp + 0x48)) fpustack: [fp0]
    fp1 = 0.0f; // fldz() fpustack: [fp1, fp0]
    // fcomst(1) fpustack: [fp1, fp0]
    _cmp2r = fp0;
    fp0 = fp1; // fstpst(1) fpustack: [fp0]
    if (fp1 >= _cmp2r)  // fp1 vs fp0
        goto loc_1005fe4b;
    ebx++;
    memoryASet32(ds, esp + 0x24, ebx);
loc_1005fe4b: // 0000:1005fe4b
    if ((int32_t)memoryAGet32(ss, ebp + 0x18) >= (int32_t)ebx)
        goto loc_1005fe57;
    ebx = memoryAGet32(ss, ebp + 0x18);
    memoryASet32(ds, esp + 0x24, ebx);
loc_1005fe57: // 0000:1005fe57
    memoryASet32(ss, ebp + 0x18, memoryAGet32(ss, ebp + 0x18) - ebx);
    if (!ebx)
        goto loc_10060023;
    eax = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, eax + 0x1c);
    esi = eax + (edi * 2);
    memoryASet32(ds, esp + 0x40, 0x00000000);
    if ((int32_t)memoryAGet32(ds, esp + 0x1c) <= 0x00000000)
        goto loc_1006026f;
    // fstpst(0) (pop) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x70); // fld64(memoryAGet64(ds, esp + 0x70)) fpustack: [fp0]
    memoryFSet32(ds, esp + 0x44, fp0); // fstp32()) fpustack: [empty]
    goto loc_1005fe92;
    // gap 5 bytes // gap 5 bytes
loc_1005fe90: // 0000:1005fe90
    // fstpst(0) (pop) fpustack: [empty]
loc_1005fe92: // 0000:1005fe92
    fp0 = memoryFGet64(ds, esp + 0x70); // fld64(memoryAGet64(ds, esp + 0x70)) fpustack: [fp0]
    ecx = memoryAGet32(ds, esp + 0x40);
    fp1 = memoryFGet32(ds, esp + 0x44); // fld32(memoryAGet32(ds, esp + 0x44)) fpustack: [fp1, fp0]
    edi = memoryAGet32(ds, esp + ecx * 4 + 0x68);
    memoryFSet32(ds, esp + 0x20, fp1); // fst32()) fpustack: [fp1, fp0]
    edx = 0;
    fp2 = 1.0f; // fld1() fpustack: [fp2, fp1, fp0]
    fp3 = fp2; // fldst(0) fpustack: [fp3, fp2, fp1, fp0]
    fp4 = memoryFGet64(ds, esp + 0x60); // fld64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp4, fp3, fp2, fp1, fp0]
    // fcomst(1) fpustack: [fp4, fp3, fp2, fp1, fp0]
    _cmp3r = fp3;
    fp3 = fp4; // fstpst(1) fpustack: [fp3, fp2, fp1, fp0]
    if (fp4 != _cmp3r)  // fp4 vs fp3
        goto loc_1005ff03;
    fp4 = 0.0f; // fldz() fpustack: [fp4, fp3, fp2, fp1, fp0]
    // fcompst(3) fpustack: [fp3, fp2, fp1, fp0]
    if (fp4 != fp1)  // fp4 vs fp1
        goto loc_1005ff03;
    // fstpst(0) (pop) fpustack: [fp2, fp1, fp0]
    eax = ebx;
    // fstpst(0) (pop) fpustack: [fp1, fp0]
    edx = esi;
    fp0 = fp1; // fstpst(1) fpustack: [fp0]
    ecx = edi;
    fp1 = memoryFGet32(ds, 0x103d33fc); // fld32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
loc_1005fed8: // 0000:1005fed8
    ebx = (int16_t)memoryAGet16(ds, edx);
    memoryASet32(ds, esp + 0x48, ebx);
    eax--;
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp2, fp1, fp0]
    ecx += 0x00000004;
    edx += 0x00000002;
    fp2 *= fp1; // fmulst(1) fpustack: [fp2, fp1, fp0]
    memoryFSet32(ds, ecx - 4, fp2); // fstp32()) fpustack: [fp1, fp0]
    if (eax)
        goto loc_1005fed8;
    ebx = memoryAGet32(ds, esp + 0x24);
    // fstpst(0) (pop) fpustack: [fp0]
    edi = edi + (ebx * 4);
    edx = ebx;
    goto loc_1005ffe7;
loc_1005ff03: // 0000:1005ff03
    fp4 = memoryFGet64(ds, 0x103d3c90); // fld64(memoryAGet64(ds, 0x103d3c90)) fpustack: [fp4, fp3, fp2, fp1, fp0]
    // fcompp() fpustack: [fp2, fp1, fp0]
    if (fp4 != fp3)  // fp4 vs fp3
        goto loc_1005ff5a;
    fp3 = 0.0f; // fldz() fpustack: [fp3, fp2, fp1, fp0]
    // fcompst(2) fpustack: [fp2, fp1, fp0]
    if (fp3 != fp1)  // fp3 vs fp1
        goto loc_1005ff5a;
    // fstpst(0) (pop) fpustack: [fp1, fp0]
    eax = ebx;
    fp0 = fp1; // fstpst(1) fpustack: [fp0]
    edx = esi;
    fp1 = memoryFGet32(ds, 0x103d33fc); // fld32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
    ecx = edi;
loc_1005ff2d: // 0000:1005ff2d
    ebx = (int16_t)memoryAGet16(ds, edx);
    memoryASet32(ds, esp + 0x48, ebx);
    eax--;
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp2, fp1, fp0]
    ecx += 0x00000004;
    edx -= 0x00000002;
    fp2 *= fp1; // fmulst(1) fpustack: [fp2, fp1, fp0]
    memoryFSet32(ds, ecx - 4, fp2); // fstp32()) fpustack: [fp1, fp0]
    if (eax)
        goto loc_1005ff2d;
    ebx = memoryAGet32(ds, esp + 0x24);
    // fstpst(0) (pop) fpustack: [fp0]
    edx = ebx;
    edi = edi + (ebx * 4);
    edx = -edx;
    goto loc_1005ffe7;
loc_1005ff5a: // 0000:1005ff5a
    eax = memoryAGet32(ds, esp + 0x28);
    ecx = memoryAGet32(ds, eax + 0x9d80);
    if (ecx != 0x00000003)
        goto loc_1005ff89;
    fp2 -= memoryFGet64(ss, ebp + 0x10); // fsub64(memoryAGet64(ss, ebp + 0x10)) fpustack: [fp2, fp1, fp0]
    fp2 = fabs(fp2); // fabs() fpustack: [fp2, fp1, fp0]
    _cmp7r = memoryFGet64(ds, 0x103d3c88);
    // fcomp64(memoryAGet64(ds, 0x103d3c88)) fpustack: [fp1, fp0] [cmp_7]
    if (fp2 < _cmp7r)  // fp2 vs memoryFGet64(ds, 0x103d3c88)
        goto loc_1005ff82;
    ecx = 0x00000001;
    goto loc_1005ff8b;
loc_1005ff82: // 0000:1005ff82
    ecx = 0x00000002;
    goto loc_1005ff8b;
loc_1005ff89: // 0000:1005ff89
    // fstpst(0) (pop) fpustack: [fp1, fp0]
loc_1005ff8b: // 0000:1005ff8b
    eax = ebx;
    if (ecx > 0x00000004)
        goto loc_1005ffe5;
    switch (ecx)
    {
        case 0: goto loc_1005ffa0;
        case 1: goto loc_1006007a;
        case 2: goto loc_100600d3;
        case 3: goto loc_1005ffe5;
        case 4: goto loc_1006017e;
        default:
            stop("unhandled indirect 0000:1005ff92");
    }
    // gap 7 bytes // gap 7 bytes
loc_1005ffa0: // 0000:1005ffa0
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2);
    // fstpst(0) (pop) fpustack: [fp0]
    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp1, fp0]
    edi += 0x00000004;
    fp1 *= memoryFGet32(ds, 0x103d33fc); // fmul32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
    memoryFSet32(ds, edi - 4, fp1); // fstp32()) fpustack: [fp0]
    fp0 += memoryFGet64(ds, esp + 0x60); // fadd64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp0]
    memoryFSet64(ds, esp + 0x50, fp0); // fstp64()) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp0]
    memoryASet32(ds, esp + 0x30, (int32_t)floor(fp0)); // fistp32()) fpustack: [empty]
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x30); // fild32(memoryAGet32(ds, esp + 0x30)) fpustack: [fp0]
    edx = memoryAGet32(ds, esp + 0x30);
    fp1 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp1, fp0]
    fp2 = fp1; // fldst(0) fpustack: [fp2, fp1, fp0]
    fp0 = fp2 - fp0; // fsubrpst(2) fpustack: [fp1, fp0]
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }  // fxchst2(0, 1) fpustack: [fp1, fp0]
    memoryFSet32(ds, esp + 0x20, fp1); // fst32()) fpustack: [fp1, fp0]
    if (eax)
        goto loc_1005ffa0;
loc_1005ffe5: // 0000:1005ffe5
    fp0 = fp1; // fstpst(1) fpustack: [fp0]
loc_1005ffe7: // 0000:1005ffe7
    eax = memoryAGet32(ds, esp + 0x40);
    ecx = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, esp + eax * 4 + 0x68, edi);
    eax++;
    esi = (esi + (ecx * 2)) + 8;
    memoryASet32(ds, esp + 0x40, eax);
    if ((int32_t)eax < (int32_t)memoryAGet32(ds, esp + 0x1c))
        goto loc_1005fe90;
    fp1 = 0.0f; // fldz() fpustack: [fp1, fp0]
    edi = memoryAGet32(ds, esp + 0x10);
    ecx = memoryAGet32(ds, esp + 0x5c);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }  // fxchst2(0, 1) fpustack: [fp1, fp0]
loc_10060015: // 0000:10060015
    esi = memoryAGet32(ds, esp + 0x18);
    memoryFSet64(ds, esp + 0x50, fp1); // fstp64()) fpustack: [fp0]
    edi += edx;
    memoryASet32(ds, esp + 0x10, edi);
loc_10060023: // 0000:10060023
    _cmp8r = memoryFGet64(ds, esp + 0x60);
    // fcom64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp0] [cmp_8]
    if (fp0 <= _cmp8r)  // fp0 vs memoryFGet64(ds, esp + 0x60)
        goto loc_10060289;
    if ((int32_t)edi > (int32_t)esi)
        goto loc_100602da;
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_100602d3;
    eax = memoryAGet32(ds, esp + 0x28);
    eax = memoryAGet32(ds, eax + 0x9d84);
    eax -= 0x00000000;
    if (!eax)
        goto loc_10060066;
    eax--;
    if (!eax)
        goto loc_10060278;
    eax -= 0x00000002;
    if (eax)
        goto loc_100602da;
loc_10060066: // 0000:10060066
    edi = esi;
    memoryASet32(ds, esp + 0x10, edi);
    memoryASet(ds, ecx + 0x95, 0x00);
    goto loc_100602da;
loc_10060078: // 0000:10060078
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }  // fxchst2(0, 1) fpustack: [fp1, fp0]
loc_1006007a: // 0000:1006007a
    edx = memoryAGet32(ds, esi + edx * 2);
    ecx = (int16_t)dx;
    edx = sar32(edx, 0x10);
    edx -= ecx;
    memoryASet32(ds, esp + 0x48, edx);
    memoryASet32(ds, esp + 0x20, ecx);
    fp1 *= (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fimul32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp1, fp0]
    eax--;
    edi += 0x00000004;
    fp1 += (double)(int32_t)memoryAGet32(ds, esp + 0x20); // fiadd32(memoryAGet32(ds, esp + 0x20)) fpustack: [fp1, fp0]
    fp1 *= memoryFGet32(ds, 0x103d33fc); // fmul32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
    memoryFSet32(ds, edi - 4, fp1); // fstp32()) fpustack: [fp0]
    fp0 += memoryFGet64(ds, esp + 0x60); // fadd64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp0]
    memoryFSet64(ds, esp + 0x50, fp0); // fstp64()) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp0]
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0)); // fistp32()) fpustack: [empty]
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x34); // fild32(memoryAGet32(ds, esp + 0x34)) fpustack: [fp0]
    edx = memoryAGet32(ds, esp + 0x34);
    fp1 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp1, fp0]
    fp2 = fp1; // fldst(0) fpustack: [fp2, fp1, fp0]
    fp0 = fp2 - fp0; // fsubrpst(2) fpustack: [fp1, fp0]
    if (eax)
        goto loc_10060078;
    // fstpst(0) (pop) fpustack: [fp0]
    memoryFSet32(ds, esp + 0x20, fp0); // fst32()) fpustack: [fp0]
    goto loc_1005ffe7;
loc_100600d1: // 0000:100600d1
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }  // fxchst2(0, 1) fpustack: [fp1, fp0]
loc_100600d3: // 0000:100600d3
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 - 2);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp2, fp1, fp0]
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x2);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp3, fp2, fp1, fp0]
    edx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x4);
    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp4, fp3, fp2, fp1, fp0]
    memoryASet32(ds, esp + 0x48, edx);
    edi += 0x00000004;
    fp5 = fp4; // fldst(0) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 -= fp2; // fsubst(3) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 = memoryFGet32(ds, 0x100e6490); // fld32(memoryAGet32(ds, 0x100e6490)) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 *= fp6; // fmulst2(1, 0) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 -= fp2; // fsubst(5) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= fp7; // fmulpst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = fp3; // fldst(3) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp4 = fp7 - fp4; // fsubrpst(3) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }  // fxchst2(0, 2) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= memoryFGet32(ds, 0x103cd1c0); // fmul32(memoryAGet32(ds, 0x103cd1c0)) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp4 += fp6; // faddpst(2) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }  // fxchst2(0, 3) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 -= fp3; // fsubst(2) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 += fp2; // faddst(3) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 -= fp4; // fsubst(1) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }  // fxchst2(0, 1) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 *= fp1; // fmulst(4) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp4 += fp5; // faddpst(1) fpustack: [fp4, fp3, fp2, fp1, fp0]
    fp4 *= fp1; // fmulst(3) fpustack: [fp4, fp3, fp2, fp1, fp0]
    fp2 += fp4; // faddpst(2) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }  // fxchst2(0, 1) fpustack: [fp3, fp2, fp1, fp0]
    fp1 *= fp3; // fmulpst(2) fpustack: [fp2, fp1, fp0]
    fp1 += fp2; // faddpst(1) fpustack: [fp1, fp0]
    fp1 *= memoryFGet32(ds, 0x103d33fc); // fmul32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
    memoryFSet32(ds, edi - 4, fp1); // fstp32()) fpustack: [fp0]
    fp0 += memoryFGet64(ds, esp + 0x60); // fadd64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp0]
    memoryFSet64(ds, esp + 0x50, fp0); // fstp64()) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp0]
    memoryASet32(ds, esp + 0x38, (int32_t)floor(fp0)); // fistp32()) fpustack: [empty]
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x38); // fild32(memoryAGet32(ds, esp + 0x38)) fpustack: [fp0]
    edx = memoryAGet32(ds, esp + 0x38);
    fp1 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp1, fp0]
    fp2 = fp1; // fldst(0) fpustack: [fp2, fp1, fp0]
    fp0 = fp2 - fp0; // fsubrpst(2) fpustack: [fp1, fp0]
    if (eax)
        goto loc_100600d1;
    // fstpst(0) (pop) fpustack: [fp0]
    memoryFSet32(ds, esp + 0x20, fp0); // fst32()) fpustack: [fp0]
    goto loc_1005ffe7;
loc_1006017c: // 0000:1006017c
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }  // fxchst2(0, 1) fpustack: [fp1, fp0]
loc_1006017e: // 0000:1006017e
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 - 2);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp2, fp1, fp0]
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x2);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp3, fp2, fp1, fp0]
    edx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x4);
    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp4, fp3, fp2, fp1, fp0]
    memoryASet32(ds, esp + 0x48, edx);
    edi += 0x00000004;
    fp5 = (double)(int32_t)memoryAGet32(ds, esp + 0x48); // fild32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    memoryFSet32(ds, esp + 0x48, fp5); // fst32()) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 = fp2 - fp5; // fsubrst(3) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    memoryFSet32(ds, esp + 0x50, fp5); // fst32()) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 = fp4; // fldst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 -= fp3; // fsubst(3) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    memoryFSet32(ds, esp + 0x20, fp6); // fst32()) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= memoryFGet32(ds, 0x103cf1d4); // fmul32(memoryAGet32(ds, 0x103cf1d4)) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = memoryFGet32(ds, 0x100e7458); // fld32(memoryAGet32(ds, 0x100e7458)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 *= fp7; // fmulst2(2, 0) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp7; fp7 = fp6; fp6 = _xchg; }  // fxchst2(0, 1) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 += fp7; // faddpst(2) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }  // fxchst2(0, 1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= fp1; // fmulst(5) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = memoryFGet32(ds, esp + 0x48); // fld32(memoryAGet32(ds, esp + 0x48)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 -= fp2; // fsubst(5) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 *= memoryFGet32(ds, 0x100e7454); // fmul32(memoryAGet32(ds, 0x100e7454)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 += fp7; // faddpst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = fp3; // fldst(3) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 -= fp4; // fsubst(3) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 *= memoryFGet32(ds, 0x103d3a08); // fmul32(memoryAGet32(ds, 0x103d3a08)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 += fp7; // faddpst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= fp1; // fmulst(5) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = memoryFGet32(ds, esp + 0x20); // fld32(memoryAGet32(ds, esp + 0x20)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 *= memoryFGet32(ds, 0x103cf288); // fmul32(memoryAGet32(ds, 0x103cf288)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 += fp7; // faddpst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = memoryFGet32(ds, esp + 0x50); // fld32(memoryAGet32(ds, esp + 0x50)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 *= memoryFGet32(ds, 0x100e7450); // fmul32(memoryAGet32(ds, 0x100e7450)) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 += fp7; // faddpst(1) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp6 *= fp1; // fmulst(5) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp7 = fp3; // fldst(3) fpustack: [fp7, fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 *= fp7; // fmulpst(2) fpustack: [fp6, fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 = fp6 - fp5; // fsubrpst(1) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 += fp4; // faddst(1) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 += fp2; // faddst(3) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp5 *= fp1; // fmulst(4) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }  // fxchst2(0, 1) fpustack: [fp5, fp4, fp3, fp2, fp1, fp0]
    fp2 = fp5 - fp2; // fsubrpst(3) fpustack: [fp4, fp3, fp2, fp1, fp0]
    fp2 += fp4; // faddpst(2) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }  // fxchst2(0, 1) fpustack: [fp3, fp2, fp1, fp0]
    fp1 *= fp3; // fmulpst(2) fpustack: [fp2, fp1, fp0]
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }  // fxchst2(0, 1) fpustack: [fp2, fp1, fp0]
    fp2 *= memoryFGet32(ds, 0x100e6490); // fmul32(memoryAGet32(ds, 0x100e6490)) fpustack: [fp2, fp1, fp0]
    fp1 += fp2; // faddpst(1) fpustack: [fp1, fp0]
    fp1 *= memoryFGet32(ds, 0x103d33fc); // fmul32(memoryAGet32(ds, 0x103d33fc)) fpustack: [fp1, fp0]
    memoryFSet32(ds, edi - 4, fp1); // fstp32()) fpustack: [fp0]
    fp0 += memoryFGet64(ds, esp + 0x60); // fadd64(memoryAGet64(ds, esp + 0x60)) fpustack: [fp0]
    memoryFSet64(ds, esp + 0x50, fp0); // fstp64()) fpustack: [empty]
    fp0 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp0]
    memoryASet32(ds, esp + 0x3c, (int32_t)floor(fp0)); // fistp32()) fpustack: [empty]
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x3c); // fild32(memoryAGet32(ds, esp + 0x3c)) fpustack: [fp0]
    edx = memoryAGet32(ds, esp + 0x3c);
    fp1 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp1, fp0]
    fp2 = fp1; // fldst(0) fpustack: [fp2, fp1, fp0]
    fp0 = fp2 - fp0; // fsubrpst(2) fpustack: [fp1, fp0]
    if (eax)
        goto loc_1006017c;
    // fstpst(0) (pop) fpustack: [fp0]
    memoryFSet32(ds, esp + 0x20, fp0); // fst32()) fpustack: [fp0]
    goto loc_1005ffe7;
loc_1006026f: // 0000:1006026f
    fp1 = memoryFGet32(ds, esp + 0x20); // fld32(memoryAGet32(ds, esp + 0x20)) fpustack: [fp1, fp0]
    goto loc_10060015;
loc_10060278: // 0000:10060278
    eax = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, eax + 0xc);
    eax -= esi;
    edi += eax;
    memoryASet32(ds, esp + 0x10, edi);
    goto loc_100602da;
loc_10060289: // 0000:10060289
    eax = memoryAGet32(ds, esp + 0x14);
    ebx = memoryAGet32(ds, eax + 0xc);
    if ((int32_t)edi < (int32_t)ebx)
        goto loc_100602da;
    esi = memoryAGet32(ds, esp + 0x18);
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_100602d3;
    eax = memoryAGet32(ds, esp + 0x28);
    eax = memoryAGet32(ds, eax + 0x9d84);
    eax -= 0x00000000;
    if (!eax)
        goto loc_100602c7;
    eax--;
    if (!eax)
        goto loc_100602be;
    eax -= 0x00000002;
    if (eax)
        goto loc_100602da;
    edi = ebx;
    memoryASet32(ds, esp + 0x10, edi);
loc_100602be: // 0000:100602be
    memoryASet(ds, ecx + 0x95, 0x01);
    goto loc_100602da;
loc_100602c7: // 0000:100602c7
    eax = esi;
    eax -= ebx;
    edi += eax;
    memoryASet32(ds, esp + 0x10, edi);
    goto loc_100602da;
loc_100602d3: // 0000:100602d3
    memoryASet(ds, ecx + 0x94, 0x00);
loc_100602da: // 0000:100602da
    fp1 = memoryFGet64(ds, esp + 0x50); // fld64(memoryAGet64(ds, esp + 0x50)) fpustack: [fp1, fp0]
    ebx = memoryAGet32(ds, esp + 0x28);
    memoryFSet64(ds, esp + 0x70, fp1); // fst64()) fpustack: [fp1, fp0]
    fp2 = memoryFGet64(ss, ebp + 0x10); // fld64(memoryAGet64(ss, ebp + 0x10)) fpustack: [fp2, fp1, fp0]
    fp3 = memoryFGet64(ds, 0x103d3c90); // fld64(memoryAGet64(ds, 0x103d3c90)) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }  // fxchst2(0, 2) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }  // fxchst2(0, 3) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }  // fxchst2(0, 1) fpustack: [fp3, fp2, fp1, fp0]
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }  // fxchst2(0, 2) fpustack: [fp3, fp2, fp1, fp0]
loc_100602f7: // 0000:100602f7
    if (!memoryAGet32(ss, ebp + 0x18))
        goto loc_1006030a;
    if (memoryAGet(ds, ecx + 0x94))
        goto loc_1005fd2f;
loc_1006030a: // 0000:1006030a
    eax = memoryAGet32(ss, ebp + 0xc);
    fp1 = fp3; // fstpst(2) fpustack: [fp2, fp1, fp0]
    // fstpst(0) (pop) fpustack: [fp1, fp0]
    // fstpst(0) (pop) fpustack: [fp0]
    memoryFSet64(ds, ecx + eax * 8 + 0x40, fp0); // fstp64()) fpustack: [empty]
    memoryASet32(ds, ecx + eax * 4 + 0x74, edi);
    if (memoryAGet(ds, ecx + 0x94))
        goto loc_1006035b;
    edi = 0;
    if ((int32_t)memoryAGet32(ds, esp + 0x1c) <= (int32_t)edi)
        goto loc_1006035b;
    ebx = memoryAGet32(ss, ebp + 0x18);
    esi = memoryAGet32(ds, esp + 0x1c);
    ebx += ebx;
    ebx += ebx;
loc_10060337: // 0000:10060337
    ecx = memoryAGet32(ds, esp + edi * 4 + 0x68);
    push32(ebx);
    push32(0x00000000);
    push32(ecx);
    sub_100c8680();
    edi++;
    esp += 0x0000000c;
    if ((int32_t)edi < (int32_t)esi)
        goto loc_10060337;
    eax = esi;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 24; return;
loc_10060357: // 0000:10060357
    // fstpst(0) (pop) fpustack: [fp3, fp2, fp1, fp0]
    goto loc_100602f7;
loc_1006035b: // 0000:1006035b
    eax = memoryAGet32(ds, esp + 0x1c);
loc_1006035f: // 0000:1006035f
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 24;
}
