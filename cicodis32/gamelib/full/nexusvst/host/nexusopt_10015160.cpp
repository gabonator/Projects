// Forward declarations for subopt_* functions
void subopt_10015160();
void subopt_100617c0();
void subopt_10061330();
void subopt_10060f90();
void subopt_10060bf0();
void subopt_100686b0();
void subopt_10061a50();
void subopt_10061ad0();
void subopt_100656a0();
void subopt_100614d0();
void subopt_1005f7e0();
void subopt_10060640();
void subopt_1005fc90();
void subopt_10060380();
void subopt_10066dc0();
void subopt_10065830();
void subopt_100678c0();
void subopt_100646d0();
void subopt_10007230();
void subopt_10059ed0();
void subopt_1005d330();
void subopt_100685e0();
void subopt_1005a9d0();
void subopt_10058ab0();
void subopt_10058ad0();
void subopt_1001a000();
void subopt_10019ea0();
void subopt_10058230();
void subopt_10062c60();
void subopt_10062760();
void subopt_10068620();
void subopt_100629a0();
void subopt_10062f90();
double subopt2_10062e20();
void subopt_10056420();
void subopt_1005a960();

void sub_10015160() // 0000:10015160 +long +stackDrop8
{
    double fp0, fp1, fp2, fp3;
    float fp4, fp5, fp6, fp7;
    double _cmp0r, _cmp1r, _cmp2r, _cmp3r, _cmp4r, _cmp5r, _cmp6r, _cmp7r, _cmp11r, _cmp12r, _cmp16r, _cmp17r, _cmp18r, _cmp20r, _cmp22r, _cmp24r, _cmp26r, _cmp28r, _cmp30r, _cmp32r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000048;
    fp0 = 0.007874015718698502f;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x54);
    fp1 = 1.0f;
    push32(ebp);
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi + 0xde54);
    push32(edi);
    edi = 0;
    memoryASet(ds, esp + 0x20, 0x00);
    memoryASet(ds, esp + 0x21, 0x00);
    memoryASet(ds, esp + 0x22, 0x00);
    memoryASet(ds, esp + 0x23, 0x00);
    if (!eax)
        goto loc_10015918;
    if (!memoryAGet(ds, esi + 0x37e1d8))
        goto loc_1001520f;
    edx = memoryAGet32(ds, esi);

    eax = memoryAGet32(ds, edx + 0x12c);

    indirectCall(cs, eax, 0x0000, 0x100151ae); // 0000:100151ae
    if (eax != 0x00000004)
        goto loc_10015207;
    fp0 = 1.0f;
    fp1 = 0.007874015718698502f;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_100151bf: // 0000:100151bf
    memoryASet32(ds, esi + 0x1ceb0, eax);
    memoryASet32(ds, esi + 0x26c38, eax);
    memoryASet32(ds, esi + 0xf7f50, eax);
    memoryASet32(ds, esi + 0x101cd8, eax);
    memoryASet32(ds, esi + 0x1d2ff0, eax);
    memoryASet32(ds, esi + 0x1dcd78, eax);
    memoryASet32(ds, esi + 0x2ae090, eax);
    memoryASet32(ds, esi + 0x2b7e18, eax);
    edx = memoryAGet32(ds, esi + 0xde54);
    if ((int32_t)edx <= 0)
        goto loc_1001521f;
    eax = memoryAGet32(ds, esi + 0xde60);
    ecx = memoryAGet32(ds, eax);
    memoryASet32(ds, esp + 0x14, ecx);
    goto loc_10015223;
loc_10015207: // 0000:10015207
    fp0 = 0.007874015718698502f;
    fp1 = 1.0f;
loc_1001520f: // 0000:1001520f
    ecx = (int8_t)memoryAGet(ds, esi + 0xf4d3);
    eax = memoryAGet32(ds, ecx * 4 + 0x103fd424);
    goto loc_100151bf;
loc_1001521f: // 0000:1001521f
    memoryASet32(ds, esp + 0x14, edi);
loc_10015223: // 0000:10015223
    memoryASet32(ds, esp + 0x1c, edi);
    memoryASet32(ds, esp + 0x3c, edi);
    memoryASet32(ds, esp + 0x38, edi);
loc_1001522f: // 0000:1001522f
    fp2 = 0.0f;
    edx = memoryAGet32(ds, esp + 0x14);
    _cmp0r = (double)fromFp32(memoryAGet32(ds, edx + 0x20));

    if (fp2 == _cmp0r)  // fp2 vs (double)fromFp32(memoryAGet32(ds, edx + 0x20))
        goto loc_100158e3;
    eax = edx;

    edi = memoryAGet32(ds, eax + 0x30);

    eax = memoryAGet32(ds, edi);
    edx = memoryAGet32(ds, esi + 0xded0);
    memoryASet32(ds, esp + 0x34, eax);
    eax = (int32_t)eax * (int32_t)0x00028358;
    ecx = (eax + esi) + 3662328;
    eax = (ebx * 4) + 0;
    push32(eax);
    ebp = esi + 57040;
    push32(0x00000000);
    push32(edx);
    memoryASet32(ds, esp + 0x38, edi);
    memoryASet32(ds, esp + 0x50, ecx);
    sub_100c8680();
    eax = (ebx * 4) + 0;
    push32(eax);
    eax = memoryAGet32(ds, esi + 0xded4);
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    eax = memoryAGet32(ds, esp + 0x4c);
    eax = (int32_t)eax * (int32_t)0x00000274;
    ecx = 0;
    esp += 0x00000018;
    edi += 0x00000058;
    memoryASet32(ds, esp + 0x28, edi);
    memoryASet32(ds, esp + 0x18, ecx);
    memoryASet32(ds, esp + 0x24, ecx);
    memoryASet32(ds, esp + 0x48, 0x00000001);
    memoryASet32(ds, esp + 0x40, eax);
    memoryASet32(ds, esp + 0x30, ecx);
    edi = esi + 158784;
    ecx = ecx;
loc_100152d0: // 0000:100152d0
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = memoryAGet32(ds, esp + 0x40);
    ecx += eax;
    eax = memoryAGet32(ds, esp + 0x24);
    dl = memoryAGet(ds, ecx + eax + 0x133);
    ecx = memoryAGet32(ds, esp + 0x2c);
    if (!(memoryAGet(ds, ecx + eax + 0x8) & dl))
        goto loc_10015449;
    edx = memoryAGet32(ds, esp + 0x48);
    if (!(memoryAGet32(ds, esi + 0x438b70) & edx))
        goto loc_10015449;
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = memoryAGet32(ds, esp + 0x30);
    edx = (int8_t)memoryAGet(ds, eax + ecx + 0x76);
    eax = memoryAGet32(ds, esp + 0x14);
    memoryASet32(ds, esp + 0x54, edx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    _cmp1r = (double)fromFp32(memoryAGet32(ds, eax + 0x20));

    if (fp0 > _cmp1r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, eax + 0x20))
        goto loc_10015441;
    fp0 = 0.0f;
    ecx = memoryAGet32(ds, esp + 0x28);
    _cmp2r = (double)fromFp32(memoryAGet32(ds, ecx - 4));

    if (!memoryAGet(ds, edi - 85272))
        goto loc_100153a0;
    if (fp0 == _cmp2r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, ecx - 4))
        goto loc_1001535b;
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, eax + 0x4);
    edx = memoryAGet32(ds, edi);
    edx = memoryAGet32(ds, edx + 0x24);
    push32(ecx);
    push32(ebx);
    push32(ebp);
    push32(ebp);
    ecx = edi;
    switch (edx)
    {
        case 0x100617c0: subopt_100617c0(); break;
        default:
            stop("unhandled indirect 0000:10015359");
    }
loc_1001535b: // 0000:1001535b
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = memoryAGet32(ds, esp + 0x30);
    if (!memoryAGet(ds, ecx + eax + 0x74))
        goto loc_10015397;
    fp0 = 0.0f;
    edx = memoryAGet32(ds, esp + 0x28);
    _cmp3r = (double)fromFp32(memoryAGet32(ds, edx));

    if (fp0 == _cmp3r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, edx))
        goto loc_10015397;
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4);
    eax = memoryAGet32(ds, edi + 0x62fb0);
    eax = memoryAGet32(ds, eax + 0x24);
    push32(edx);
    push32(ebx);
    ecx = edi + 405424;
    push32(ebp);
    push32(ebp);
    switch (eax)
    {
        case 0x100617c0: subopt_100617c0(); break;
        default:
            stop("unhandled indirect 0000:10015395");
    }
loc_10015397: // 0000:10015397
    memoryASet32(ds, esp + 0x18, memoryAGet32(ds, esp + 0x18) + 1);
    goto loc_10015449;
loc_100153a0: // 0000:100153a0
    if (fp0 == _cmp2r)  //gabooo!!! PROBLEM!
        goto loc_100153e2;
    eax = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edi - 80656);
    eax = memoryAGet32(ds, eax + 0x4);
    edx = memoryAGet32(ds, edx + 0x68);
    ecx = edi - 80656;
    push32(eax);
    switch (edx)
    {
        case 0x1005f7e0: subopt_1005f7e0(); break;
        default:
            stop("unhandled indirect 0000:100153bc");
    }
    if (!al)
        goto loc_100153e2;
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4);
    eax = memoryAGet32(ds, edi - 80656);
    eax = memoryAGet32(ds, eax + 0x24);
    push32(edx);
    push32(ebx);
    ecx = edi - 80656;
    push32(ebp);
    push32(ebp);
    switch (eax)
    {
        case 0x10060640: subopt_10060640(); break;
        default:
            stop("unhandled indirect 0000:100153dc");
    }
    memoryASet32(ds, esp + 0x18, memoryAGet32(ds, esp + 0x18) + 1);
loc_100153e2: // 0000:100153e2
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x30);
    if (!memoryAGet(ds, edx + ecx + 0x74))
        goto loc_10015449;
    fp0 = 0.0f;
    eax = memoryAGet32(ds, esp + 0x28);
    _cmp4r = (double)fromFp32(memoryAGet32(ds, eax));

    if (fp0 == _cmp4r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, eax))
        goto loc_10015449;
    eax = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edi - 40328);
    eax = memoryAGet32(ds, eax + 0x4);
    edx = memoryAGet32(ds, edx + 0x68);
    ecx = edi - 40328;
    push32(eax);
    switch (edx)
    {
        case 0x1005f7e0: subopt_1005f7e0(); break;
        default:
            stop("unhandled indirect 0000:10015419");
    }
    if (!al)
        goto loc_10015449;
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4);
    eax = memoryAGet32(ds, edi - 40328);
    eax = memoryAGet32(ds, eax + 0x24);
    push32(edx);
    push32(ebx);
    ecx = edi - 40328;
    push32(ebp);
    push32(ebp);
    switch (eax)
    {
        case 0x10060640: subopt_10060640(); break;
        default:
            stop("unhandled indirect 0000:10015439");
    }
    memoryASet32(ds, esp + 0x18, memoryAGet32(ds, esp + 0x18) + 1);
    goto loc_10015449;
loc_10015441: // 0000:10015441
    memoryASet32(ds, esp + 0x18, 0x00000001);
loc_10015449: // 0000:10015449
    eax = memoryAGet32(ds, esp + 0x30);
    ecx = memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) + 1);
    memoryASet32(ds, esp + 0x28, memoryAGet32(ds, esp + 0x28) + 0x00000008);
    eax += 0x0000003d;
    edi += 0x000db0a0;
    ecx = rol32(ecx, 0x00000001);
    memoryASet32(ds, esp + 0x30, eax);
    memoryASet32(ds, esp + 0x48, ecx);
    if ((int32_t)eax < (int32_t)0x000000f4)
        goto loc_100152d0;
    if (!memoryAGet32(ds, esp + 0x18))
        goto loc_100158bc;
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = memoryAGet32(ds, esp + 0x40);
    if (!memoryAGet(ds, eax + edx + 0x137))
        goto loc_100154b3;
    eax = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, eax + 0x4);
    ecx = memoryAGet32(ds, esp + 0x44);
    ecx = memoryAGet32(ds, ecx + 0x10464);
    edx = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, edx + 0x24);
    push32(eax);
    push32(ebx);
    push32(ebp);
    push32(ebp);
    switch (edx)
    {
        case 0x10066dc0: sub_10066dc0(); break;
        default:
            stop("unhandled indirect 0000:100154b1");
    }
loc_100154b3: // 0000:100154b3
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4);
    ecx = memoryAGet32(ds, esp + 0x44);
    eax = memoryAGet32(ds, ecx + 0x10478);
    eax = memoryAGet32(ds, eax + 0x24);
    push32(edx);
    push32(ebx);
    ecx += 0x00010478;
    push32(ebp);
    push32(ebp);
    switch (eax)
    {
        case 0x100656a0: subopt_100656a0(); break;
        default:
            stop("unhandled indirect 0000:100154d1");
    }
    edi = memoryAGet32(ds, esp + 0x34);
    if (memoryAGet(ds, esp + edi + 0x20))
        goto loc_100155a1;
    ecx = memoryAGet32(ds, esp + 0x34);
    edx = memoryAGet32(ds, esi + ecx * 8 + 0xdeb0);
    edi = (ebx * 4) + 0;
    push32(edi);
    eax = esi + 57008;
    push32(0x00000000);
    push32(edx);
    sub_100c8680();
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x44);
    eax = esi + 57008;
    eax = memoryAGet32(ds, eax + edi * 8 + 0x4);
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    esp += 0x00000018;
    ecx = 0;
    memoryASet(ds, esp + edi + 0x20, 0x01);
    memoryASet32(ds, esp + 0x24, ecx);
    goto loc_10015530;
    // gap 6 bytes // gap 6 bytes
loc_10015530: // 0000:10015530
    eax = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x38);
    edx += eax;
    edi = edx + ecx;
    if (!memoryAGet(ds, edx + ecx + 0x16c))
        goto loc_1001558b;
    edx = memoryAGet32(ds, esp + 0x3c);
    edx += eax;
    eax = memoryAGet32(ds, esp + 0x24);
    if (memoryAGet(ds, edx + eax + 0xd56))
        goto loc_1001558b;
    al = memoryAGet(ds, edi + 0x16d);
    if (al == 0x01)
        goto loc_1001556b;
    if (al != 0x02)
        goto loc_1001558b;
loc_1001556b: // 0000:1001556b
    fp0 = memoryFGet32(ds, esi + 0xb4);
    memoryFSet32(ds, esp + 0x54, fp0);
    fp0 = memoryFGet32(ds, esp + 0x54);
    memoryASet32(ds, esp + 0x4c, (int32_t)floor(fp0));
    edx = memoryAGet32(ds, esp + 0x4c);
    eax = memoryAGet32(ds, esp + 0x44);
    memoryASet32(ds, eax + 0x28120, edx);
loc_1001558b: // 0000:1001558b
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) + 1);
    ecx += 0x00000090;
    if ((int32_t)ecx < (int32_t)0x00000120)
        goto loc_10015530;
    edi = memoryAGet32(ds, esp + 0x34);
loc_100155a1: // 0000:100155a1
    eax = memoryAGet32(ds, esp + 0x2c);
    fp0 = memoryFGet32(ds, eax + 0xc);
    _cmp5r = (double)fromFp32(memoryAGet32(ds, eax + 0x14));

    if (fp0 < _cmp5r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, eax + 0x14))
        goto loc_10015604;
    fp0 = 5.0f;
    ecx = memoryAGet32(ds, esp + 0x14);
    _cmp6r = (double)fromFp32(memoryAGet32(ds, ecx + 0x20));

    if (fp0 <= _cmp6r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, ecx + 0x20))
        goto loc_10015604;
    edx = memoryAGet32(ds, esi + 0xe734);
    fp0 = memoryFGet32(ds, esi + 0xb8);
    eax = memoryAGet32(ds, esp + 0x40);
    fp1 = 0.007499999832361937f;
    ecx = (int8_t)memoryAGet(ds, eax + edx + 0x14e);
    fp0 *= fp1;
    memoryASet32(ds, esp + 0x54, ecx);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp3 = 0.007874015718698502f;
    fp2 *= fp3;
    fp4 = 1.0f;
    fp5 = fp4;
    fp5 -= fp0;
    fp2 *= fp5;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    fp0 += fp4;
    goto loc_1001561a;
loc_10015604: // 0000:10015604
    fp0 = memoryFGet32(ds, esi + 0xb8);
    fp1 = 0.007499999832361937f;
    fp0 *= fp1;
    fp2 = 1.0f;
    fp3 = 0.007874015718698502f;
loc_1001561a: // 0000:1001561a
    ecx = memoryAGet32(ds, esi + edi * 8 + 0xdeb0);
    ebp = memoryAGet32(ss, ebp);
    eax = esi + 57008;
    eax = memoryAGet32(ds, esp + 0x2c);
    fp4 = memoryFGet32(ds, eax + 0x14);
    edx = ebx;
    fp5 = memoryFGet32(ds, eax + 0xc);
    fp6 = fp5;
    fp6 -= fp4;
    fp6 = fabsf(fp6);
    fp7 = 6.103515625e-05f;

    _cmp7r = fp6;
    fp6 = fp7;
    if (fp7 <= _cmp7r)  // fp7 vs fp6
        goto loc_100156dd;
    fp4 = fp6;
    fp0 = fp5;
    fp5 = fp0;
    fp6 = fp2;
    fp6 -= fp0;
    fp6 = fabsf(fp6);

    if (fp6 >= fp4)  // fp6 vs fp4
        goto loc_10015688;

    eax = ecx;
    fp0 = fp5;
    if (!ebx)
        goto loc_10015706;
    ebp -= ecx;
loc_10015676: // 0000:10015676
    fp5 = memoryFGet32(ds, eax + ebp);
    edx--;
    fp5 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp5);
    if (edx)
        goto loc_10015676;
    goto loc_10015706;
loc_10015688: // 0000:10015688
    { double _xchg = fp6; fp6 = fp0; fp0 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_1001575e;
    { double _xchg = fp6; fp6 = fp0; fp0 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_100156c1;
    if (!ebx)
        goto loc_100156bd;
    eax = ebp;
    eax -= ecx;
loc_100156aa: // 0000:100156aa
    fp6 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp6 *= fp0;
    ecx += 0x00000004;
    fp6 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp6);
    if (edx)
        goto loc_100156aa;
loc_100156bd: // 0000:100156bd
    fp0 = fp5;
    goto loc_10015706;
loc_100156c1: // 0000:100156c1
    fp0 = fp5;
    if (!ebx)
        goto loc_10015706;
    eax = ebp;
    eax -= ecx;
loc_100156cb: // 0000:100156cb
    fp5 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp5 += memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp5);
    if (edx)
        goto loc_100156cb;
    goto loc_10015706;
loc_100156dd: // 0000:100156dd
    if (!ebx)
        goto loc_10015700;
    eax = ebp;
    eax -= ecx;
loc_100156e5: // 0000:100156e5
    fp7 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp7 *= fp4;
    ecx += 0x00000004;
    fp7 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp7);
    fp7 = fp5;
    fp7 -= fp4;
    fp7 *= fp0;
    fp4 += fp7;
    if (edx)
        goto loc_100156e5;
loc_10015700: // 0000:10015700
    fp5 = fp6;
    fp0 = fp5;
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
loc_10015706: // 0000:10015706
    eax = memoryAGet32(ds, esp + 0x2c);
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, eax + 0x14, fp4);
    fp4 = memoryFGet32(ds, eax + 0x10);
    _cmp11r = (double)fromFp32(memoryAGet32(ds, eax + 0x18));

    if (fp4 < _cmp11r)  // fp4 vs (double)fromFp32(memoryAGet32(ds, eax + 0x18))
        goto loc_10015764;
    fp4 = 5.0f;
    edx = memoryAGet32(ds, esp + 0x14);
    _cmp12r = (double)fromFp32(memoryAGet32(ds, edx + 0x20));

    if (fp4 <= _cmp12r)  // fp4 vs (double)fromFp32(memoryAGet32(ds, edx + 0x20))
        goto loc_10015764;
    eax = memoryAGet32(ds, esi + 0xe734);
    fp4 = memoryFGet32(ds, esi + 0xb8);
    ecx = memoryAGet32(ds, esp + 0x40);
    fp1 *= fp4;
    edx = (int8_t)memoryAGet(ds, ecx + eax + 0x14e);
    memoryASet32(ds, esp + 0x54, edx);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp3;
    fp5 = fp2;
    fp5 -= fp1;
    fp4 *= fp5;
    fp1 += fp4;
    goto loc_1001576c;
loc_1001575e: // 0000:1001575e
    fp0 = fp6;
    fp0 = fp5;
    goto loc_10015706;
loc_10015764: // 0000:10015764
    fp4 = memoryFGet32(ds, esi + 0xb8);
    fp1 *= fp4;
loc_1001576c: // 0000:1001576c
    ecx = memoryAGet32(ds, esi + edi * 8 + 0xdeb4);
    ebp = memoryAGet32(ds, esi + 0xded4);
    eax = esi + 57008;
    eax = memoryAGet32(ds, esp + 0x2c);
    fp4 = memoryFGet32(ds, eax + 0x18);
    edx = ebx;
    fp5 = memoryFGet32(ds, eax + 0x10);
    fp6 = fp5;
    fp6 -= fp4;
    fp6 = fabsf(fp6);

    if (fp6 >= fp0)  // fp6 vs fp0
        goto loc_1001582f;
    fp4 = fp5;
    fp1 = fp4;
    fp4 = fp1;
    fp5 = fp2;
    fp5 -= fp1;
    fp5 = fabsf(fp5);

    if (fp5 >= fp0)  // fp5 vs fp0
        goto loc_100157da;

    eax = ecx;
    fp1 = fp4;
    fp0 = fp3;
    if (!ebx)
        goto loc_1001585e;
    ebp -= ecx;
loc_100157c5: // 0000:100157c5
    fp3 = memoryFGet32(ds, eax + ebp);
    edx--;
    fp3 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp3);
    if (edx)
        goto loc_100157c5;
    goto loc_1001585e;
loc_100157da: // 0000:100157da
    { double _xchg = fp5; fp5 = fp1; fp1 = _xchg; }

    if (fp5 < fp0)  // fp5 vs fp0
        goto loc_10015a9f;
    { double _xchg = fp5; fp5 = fp1; fp1 = _xchg; }

    _cmp16r = fp0;
    fp0 = fp4;
    if (fp5 < _cmp16r)  // fp5 vs fp0
        goto loc_10015813;
    if (!ebx)
        goto loc_10015856;
    eax = ebp;
    eax -= ecx;
loc_100157fe: // 0000:100157fe
    fp4 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp4 *= fp1;
    ecx += 0x00000004;
    fp4 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp4);
    if (edx)
        goto loc_100157fe;
    goto loc_10015856;
loc_10015813: // 0000:10015813
    fp1 = fp3;
    if (!ebx)
        goto loc_10015858;
    eax = ebp;
    eax -= ecx;
loc_1001581d: // 0000:1001581d
    fp3 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp3 += memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp3);
    if (edx)
        goto loc_1001581d;
    goto loc_10015858;
loc_1001582f: // 0000:1001582f
    fp0 = fp5;
    if (!ebx)
        goto loc_10015854;
    eax = ebp;
    eax -= ecx;
loc_10015839: // 0000:10015839
    fp5 = memoryFGet32(ds, ecx + eax);
    edx--;
    fp5 *= fp4;
    ecx += 0x00000004;
    fp5 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp5);
    fp5 = fp0;
    fp5 -= fp4;
    fp5 *= fp1;
    fp4 += fp5;
    if (edx)
        goto loc_10015839;
loc_10015854: // 0000:10015854
    fp0 = fp4;
loc_10015856: // 0000:10015856
    fp1 = fp3;
loc_10015858: // 0000:10015858
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
loc_1001585e: // 0000:1001585e
    edi = memoryAGet32(ds, esp + 0x2c);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    eax = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ds, edi + 0x18, fp2);
    if (memoryAGet(ds, eax + 0x28))
        goto loc_1001589a;
    ecx = memoryAGet32(ds, esp + 0x44);

    edx = memoryAGet32(ds, ecx + 0x10930);

    eax = memoryAGet32(ds, eax + 0x4);
    edx = memoryAGet32(ds, edx + 0x68);
    ecx += 0x00010930;
    push32(eax);
    switch (edx)
    {
        case 0x10065830: subopt_10065830(); break;
        default:
            stop("unhandled indirect 0000:1001588c");
    }
    if (al)
        goto loc_100158d9;
    fp0 = 0.007874015718698502f;
    fp1 = 1.0f;
loc_1001589a: // 0000:1001589a
    fp2 = 3.050082341360394e-05f;
    _cmp17r = (double)fromFp32(memoryAGet32(ds, edi + 0x14));

    if (fp2 <= _cmp17r)  // fp2 vs (double)fromFp32(memoryAGet32(ds, edi + 0x14))
        goto loc_10015aaa;
    _cmp18r = (double)fromFp32(memoryAGet32(ds, edi + 0x18));

    if (fp2 <= _cmp18r)  // fp2 vs (double)fromFp32(memoryAGet32(ds, edi + 0x18))
        goto loc_100158e3;


loc_100158bc: // 0000:100158bc
    eax = memoryAGet32(ds, esp + 0x14);
    push32(eax);
    ecx = esi;
    subopt_100678c0();
    memoryASet32(ds, esp + 0x1c, memoryAGet32(ds, esp + 0x1c) - 1);
    memoryASet32(ds, esp + 0x38, memoryAGet32(ds, esp + 0x38) - 0x00000274);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 0x00000007);
loc_100158d9: // 0000:100158d9
    fp0 = 1.0f;
    fp1 = 0.007874015718698502f;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_100158e3: // 0000:100158e3
    eax = memoryAGet32(ds, esp + 0x1c);
    ecx = memoryAGet32(ds, esi + 0xde54);
    memoryASet32(ds, esp + 0x38, memoryAGet32(ds, esp + 0x38) + 0x00000274);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) + 0x00000007);
    eax++;
    memoryASet32(ds, esp + 0x1c, eax);
    if ((int32_t)eax >= (int32_t)ecx)
        goto loc_10015918;
    edx = memoryAGet32(ds, esi + 0xde60);
    eax = memoryAGet32(ds, edx + eax * 4);
    memoryASet32(ds, esp + 0x14, eax);
    if (eax)
        goto loc_1001522f;
loc_10015918: // 0000:10015918
    fp2 = 0.5f;
    eax = 0;
    ecx = esi + 3825976;
    memoryASet32(ds, esp + 0x1c, eax);
    memoryASet32(ds, esp + 0x18, eax);
    memoryASet32(ds, esp + 0x24, eax);
    edi = esi + 57008;
    memoryASet32(ds, esp + 0x44, 0x000e89c8);
    memoryASet32(ds, esp + 0x14, ecx);
loc_10015944: // 0000:10015944
    eax = memoryAGet32(ds, esp + 0x14);
    memoryASet(ds, esp + 0x13, 0x00);
    if ((int32_t)memoryAGet32(ds, eax + 0x1e0) <= 0x00000000)
        goto loc_100159ab;
    edx = memoryAGet32(ds, esp + 0x1c);
    if (memoryAGet(ds, esp + edx + 0x20))
        goto loc_100159a5;
    eax = memoryAGet32(ds, edi);
    fp1 = fp2;
    ebp = (ebx * 4) + 0;

    push32(ebp);

    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    ecx = memoryAGet32(ds, edi + 0x4);
    push32(ebp);
    push32(0x00000000);
    push32(ecx);
    sub_100c8680();
    fp0 = 0.5f;
    edx = memoryAGet32(ds, esp + 0x34);
    fp1 = 1.0f;
    fp2 = 0.007874015718698502f;
    eax = memoryAGet32(ds, esp + 0x2c);
    esp += 0x00000018;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    memoryASet(ds, esp + edx + 0x20, 0x01);
loc_100159a5: // 0000:100159a5
    memoryASet32(ds, eax + 0x1e0, memoryAGet32(ds, eax + 0x1e0) - ebx);
loc_100159ab: // 0000:100159ab
    eax = memoryAGet32(ds, esp + 0x1c);
    cl = memoryAGet(ds, esp + eax + 0x20);
    if (cl)
        goto loc_100159f3;
    eax = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x18);
    if (memoryAGet(ds, eax + edx + 0x2c0) == cl)
        goto loc_10015f42;
    edx = memoryAGet32(ds, esp + 0x24);
    if (memoryAGet(ds, eax + edx + 0xd59) != cl)
        goto loc_10015f42;
    if (memoryAGet(ds, eax + 0xb04) != cl)
        goto loc_10015f42;
    if (!cl)
        goto loc_10015c92;
loc_100159f3: // 0000:100159f3
    eax = memoryAGet32(ds, esi + 0xe734);
    fp1 = fp2;
    ecx = memoryAGet32(ds, esp + 0x18);


    if (!memoryAGet(ds, ecx + eax + 0x156))
        goto loc_10015a27;
    ecx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, ecx - 14864);
    eax = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(ebx);
    ecx += 0xffffc5f0;
    push32(edi);
    push32(edi);
    switch (eax)
    {
        case 0x100646d0: subopt_100646d0(); break;
        default:
            stop("unhandled indirect 0000:10015a25");
    }
loc_10015a27: // 0000:10015a27
    ebp = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ss, ebp - 14604);
    eax = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(ebx);
    ecx = ebp - 14604;
    push32(edi);
    push32(edi);
    switch (eax)
    {
        case 0x10059ed0: subopt_10059ed0(); break;
        default:
            stop("unhandled indirect 0000:10015a3f");
    }
    eax = 0;
    memoryASet32(ds, esp + 0x3c, eax);
    memoryASet32(ds, esp + 0x48, eax);
    ebp += 0xffffce24;
loc_10015a51: // 0000:10015a51
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x48);
    eax = memoryAGet32(ds, esp + 0x18);
    edx += ecx;
    eax += edx;
    if (!memoryAGet(ds, eax + 0x16c))
        goto loc_10015c25;
    edx = memoryAGet32(ds, esp + 0x24);
    ecx += edx;
    edx = memoryAGet32(ds, esp + 0x3c);
    if (memoryAGet(ds, ecx + edx + 0xd56))
        goto loc_10015c25;
    ecx = (int8_t)memoryAGet(ds, eax + 0x16d);
    if (ecx > 0x0000000a)
        goto loc_10015c25;
    switch (ecx)
    {
        case 0: goto loc_10015ab1;
        case 1: goto loc_10015acc;
        case 2: goto loc_10015ae0;
        case 3: goto loc_10015afb;
        case 4: goto loc_10015b16;
        case 5: goto loc_10015b86;
        case 6: goto loc_10015bf3;
        case 7: goto loc_10015bfb;
        case 8: goto loc_10015c03;
        case 9: goto loc_10015c0b;
        case 10: goto loc_10015c13;
        default:
            stop("unhandled indirect 0000:10015a98");
    }
loc_10015a9f: // 0000:10015a9f
    fp1 = fp5;
    fp1 = fp4;
    fp0 = fp3;
    goto loc_1001585e;
loc_10015aaa: // 0000:10015aaa

    goto loc_100158e3;
loc_10015ab1: // 0000:10015ab1
    eax = memoryAGet32(ss, ebp - 660);
    edx = memoryAGet32(ds, eax + 0x24);
    push32(0x00000000);
    push32(ebx);
    ecx = ebp - 660;
    push32(edi);
    push32(edi);
    switch (edx)
    {
        case 0x1005d330: subopt_1005d330(); break;
        default:
            stop("unhandled indirect 0000:10015ac5");
    }
    goto loc_10015c25;
loc_10015acc: // 0000:10015acc
    eax = memoryAGet32(ss, ebp);
    edx = memoryAGet32(ds, eax + 0x24);
    push32(0x00000000);
    push32(ebx);
    push32(edi);
    push32(edi);
    ecx = ebp;
    switch (edx)
    {
        case 0x1005d330: subopt_1005d330(); break;
        default:
            stop("unhandled indirect 0000:10015ad9");
    }
    goto loc_10015c25;
loc_10015ae0: // 0000:10015ae0
    eax = memoryAGet32(ss, ebp + 0x528);
    edx = memoryAGet32(ds, eax + 0x24);
    push32(0x00000000);
    push32(ebx);
    ecx = ebp + 1320;
    push32(edi);
    push32(edi);
    switch (edx)
    {
        case 0x1005a9d0: subopt_1005a9d0(); break;
        default:
            stop("unhandled indirect 0000:10015af4");
    }
    goto loc_10015c25;
loc_10015afb: // 0000:10015afb
    eax = memoryAGet32(ss, ebp + 0x294);
    edx = memoryAGet32(ds, eax + 0x24);
    push32(0x00000000);
    push32(ebx);
    ecx = ebp + 660;
    push32(edi);
    push32(edi);
    switch (edx)
    {
        case 0x1005d330: subopt_1005d330(); break;
        default:
            stop("unhandled indirect 0000:10015b0f");
    }
    goto loc_10015c25;
loc_10015b16: // 0000:10015b16
    edx = memoryAGet32(ds, esp + 0x3c);
    ecx = memoryAGet32(ds, esp + 0x44);
    eax = (int8_t)memoryAGet(ds, eax + 0x198);
    ecx += edx;
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp + 0x6c8);
    fp0 = memoryFGet32(ds, esi + ecx * 4);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    ecx = ebp + 1736;
    fp1 = fabsf(fp1);
    push32(ecx);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    fp3 *= 0.007874015718698502f;
    fp1 += fp3;
    fp3 = fp1;
    fp3 = fabsf(fp3);
    fp3 += fp0;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp0 = fp3 - fp0;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    switch (eax)
    {
        case 0x10058ab0: subopt_10058ab0(); break;
        default:
            stop("unhandled indirect 0000:10015b79");
    }
    ecx = ebp + 1736;
    goto loc_10015c19;
loc_10015b86: // 0000:10015b86
    edx = memoryAGet32(ds, esp + 0x3c);
    ecx = memoryAGet32(ds, esp + 0x44);
    eax = (int8_t)memoryAGet(ds, eax + 0x1a2);
    ecx += edx;
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp + 0xf58);
    fp0 = memoryFGet32(ds, esi + ecx * 4);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    ecx = ebp + 3928;
    fp1 = fabsf(fp1);
    push32(ecx);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    fp3 *= 0.007874015718698502f;
    fp1 += fp3;
    fp3 = fp1;
    fp3 = fabsf(fp3);
    fp3 += fp0;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp0 = fp3 - fp0;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    indirectCall(cs, eax, 0x0000, 0x10015be9); // 0000:10015be9
    ecx = ebp + 3928;
    goto loc_10015c19;
loc_10015bf3: // 0000:10015bf3
    ecx = ebp + 4148;
    goto loc_10015c19;
loc_10015bfb: // 0000:10015bfb
    ecx = ebp + 4352;
    goto loc_10015c19;
loc_10015c03: // 0000:10015c03
    ecx = ebp + 4588;
    goto loc_10015c19;
loc_10015c0b: // 0000:10015c0b
    ecx = ebp + 5552;
    goto loc_10015c19;
loc_10015c13: // 0000:10015c13
    ecx = ebp + 5792;
loc_10015c19: // 0000:10015c19
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(ebx);
    push32(edi);
    push32(edi);
    switch (eax)
    {
        case 0x10058ad0: subopt_10058ad0(); break;
        default:
            stop("unhandled indirect 0000:10015c23");
    }
loc_10015c25: // 0000:10015c25
    eax = memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) + 1);
    eax += 0x00000090;
    ebp += 0x00001a2c;
    memoryASet32(ds, esp + 0x48, eax);
    if ((int32_t)eax < (int32_t)0x00000120)
        goto loc_10015a51;
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = memoryAGet32(ds, esp + 0x18);
    if (!memoryAGet(ds, eax + ecx + 0x2ac))
        goto loc_10015cc6;
    edx = memoryAGet32(ds, esp + 0x24);
    if (memoryAGet(ds, eax + edx + 0xd58))
        goto loc_10015cc6;
    if (memoryAGet(ds, eax + 0xc1f))
        goto loc_10015cc6;
    edx = (eax + ecx) + 652;
    eax = memoryAGet32(ds, esp + 0x14);
    push32(ebx);
    push32(edx);
    eax += 0xffffffe8;
    push32(eax);
    push32(edi);
    ecx = esi;
    subopt_1001a000();
    memoryASet(ds, esp + 0x13, 0x01);
    goto loc_10015cc6;
loc_10015c92: // 0000:10015c92
    ecx = memoryAGet32(ds, esp + 0x14);
    if (!memoryAGet32(ds, ecx + 0x1dc))
        goto loc_10015cd6;
    edx = memoryAGet32(ds, edi);
    fp1 = fp2;
    ebp = (ebx * 4) + 0;

    push32(ebp);

    push32(0x00000000);
    push32(edx);
    sub_100c8680();
    eax = memoryAGet32(ds, edi + 0x4);
    push32(ebp);
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    esp += 0x00000018;
loc_10015cc6: // 0000:10015cc6
    fp0 = 0.5f;
    fp1 = 1.0f;
    fp2 = 0.007874015718698502f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
loc_10015cd6: // 0000:10015cd6
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = memoryAGet32(ds, esp + 0x18);
    if (!memoryAGet(ds, eax + ecx + 0x2c0))
        goto loc_1001607d;
    edx = memoryAGet32(ds, esp + 0x24);
    if (memoryAGet(ds, eax + edx + 0xd59))
        goto loc_1001607d;
    if (memoryAGet(ds, eax + 0xb04))
        goto loc_1001607d;
    ecx = memoryAGet32(ds, esp + 0x14);
    ebp = ecx;
    if (!memoryAGet32(ds, ecx + 0x1dc))
        goto loc_10015e9a;
    edx = memoryAGet32(ds, esp + 0x18);
    eax = (int8_t)memoryAGet(ds, eax + edx + 0x2c2);
    memoryASet32(ds, esp + 0x54, eax);
    push32(ecx);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    fp0 *= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 += memoryFGet32(ds, esi + 0x434094);
    fp3 = fp2;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    subopt_10058230();
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x18);
    eax = (int8_t)memoryAGet(ds, edx + ecx + 0x2c4);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    ecx = ebp;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + 0x43409c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000008);
    switch (eax)
    {
        case 0x10062c60: subopt_10062c60(); break;
        default:
            stop("unhandled indirect 0000:10015da3");
    }
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x18);
    eax = (int8_t)memoryAGet(ds, edx + ecx + 0x2c7);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    ecx = ebp;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + 0x434098);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000f);
    switch (eax)
    {
        case 0x10062c60: subopt_10062c60(); break;
        default:
            stop("unhandled indirect 0000:10015def");
    }
    edx = memoryAGet32(ds, esp + 0x18);
    ecx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edx + ecx + 0x2c6);
    edx = memoryAGet32(ss, ebp);
    memoryASet32(ds, esp + 0x54, eax);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + 0x4340a0);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    ecx = ebp;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000e);
    switch (eax)
    {
        case 0x10062c60: subopt_10062c60(); break;
        default:
            stop("unhandled indirect 0000:10015e3b");
    }
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, esp + 0x18);
    eax = (int8_t)memoryAGet(ds, edx + ecx + 0x2c5);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    ecx = ebp;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + 0x4340a4);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000b);
    switch (eax)
    {
        case 0x10062c60: subopt_10062c60(); break;
        default:
            stop("unhandled indirect 0000:10015e87");
    }
    edx = memoryAGet32(ss, ebp);
    eax = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(ebx);
    push32(edi);
    push32(edi);
    ecx = ebp;
    switch (eax)
    {
        case 0x10062f90: subopt_10062f90(); break;
        default:
            stop("unhandled indirect 0000:10015e96");
    }
    goto loc_10015ea0;
loc_10015e9a: // 0000:10015e9a
    fp1 = fp2;


loc_10015ea0: // 0000:10015ea0
    push32(ebx);
    push32(edi);
    subopt_10056420();
    fp0 = 0.5f;
    fp1 = 1.0f;
    esp += 0x00000008;
    fp2 = 0.007874015718698502f;
    memoryASet32(ss, ebp + 0x1dc, eax);
    if (eax)
        goto loc_1001606e;
    memoryASet32(ss, ebp + 0x1d8, memoryAGet32(ss, ebp + 0x1d8) + ebx);
    eax = memoryAGet32(ss, ebp + 0x1d8);
    if ((int32_t)eax >= (int32_t)memoryAGet32(ss, ebp + 0x1d4))
        goto loc_10015ee4;
    memoryASet32(ss, ebp + 0x1dc, 0x00000001);
loc_10015ee4: // 0000:10015ee4
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
loc_10015ee6: // 0000:10015ee6
    ecx = memoryAGet32(ds, esp + 0x1c);
    if (memoryAGet(ds, esp + ecx + 0x20))
        goto loc_10015efa;
    if (!memoryAGet32(ss, ebp + 0x1dc))
        goto loc_10015f42;
loc_10015efa: // 0000:10015efa
    if (memoryAGet32(ds, esi + 0x37e1c8))
        goto loc_10015f42;
    ebp = memoryAGet32(ds, esp + 0x5c);
    eax = memoryAGet32(ss, ebp);
    ecx = ebx;
    if (!ebx)
        goto loc_10015f24;
    edx = memoryAGet32(ds, edi);
    edx -= eax;
loc_10015f14: // 0000:10015f14
    fp3 = memoryFGet32(ds, eax + edx);
    ecx--;
    fp3 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp3);
    if (ecx)
        goto loc_10015f14;
loc_10015f24: // 0000:10015f24
    eax = memoryAGet32(ss, ebp + 0x4);
    ecx = ebx;
    if (!ebx)
        goto loc_10015f42;
    edx = memoryAGet32(ds, edi + 0x4);
    edx -= eax;
loc_10015f32: // 0000:10015f32
    fp3 = memoryFGet32(ds, eax + edx);
    ecx--;
    fp3 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp3);
    if (ecx)
        goto loc_10015f32;
loc_10015f42: // 0000:10015f42
    eax = memoryAGet32(ds, esi + 0xe734);
    ebp = memoryAGet32(ds, esp + 0x18);
    if (!memoryAGet(ds, eax + ebp + 0x2ac))
        goto loc_10015fa3;
    edx = memoryAGet32(ds, esp + 0x24);
    if (memoryAGet(ds, eax + edx + 0xd58))
        goto loc_10015fa3;
    if (memoryAGet(ds, eax + 0xc1f))
        goto loc_10015fa3;
    if (memoryAGet(ds, esp + 0x13))
        goto loc_10015fa3;
    ecx = memoryAGet32(ds, esp + 0x14);
    fp1 = fp2;
    push32(ebx);

    eax = (eax + ebp) + 652;

    push32(eax);
    ecx += 0xffffffe8;
    push32(ecx);
    push32(edi);
    ecx = esi;
    subopt_1001a000();
    fp0 = 0.5f;
    fp1 = 1.0f;
    fp2 = 0.007874015718698502f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
loc_10015fa3: // 0000:10015fa3
    eax = memoryAGet32(ds, esp + 0x44);
    memoryASet32(ds, esp + 0x1c, memoryAGet32(ds, esp + 0x1c) + 1);
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) + 0x00000007);
    memoryASet32(ds, esp + 0x14, memoryAGet32(ds, esp + 0x14) + 0x00028358);
    eax += 0x0000a0d6;
    ebp += 0x00000274;
    edi += 0x00000008;
    memoryASet32(ds, esp + 0x44, eax);
    memoryASet32(ds, esp + 0x18, ebp);
    if ((int32_t)eax < (int32_t)0x00110d20)
        goto loc_10015944;
    eax = 0;
    ecx = esi + 3826452;
loc_10015fe1: // 0000:10015fe1
    if (memoryAGet(ds, esp + eax + 0x20))
        goto loc_10016096;
    if (memoryAGet32(ds, ecx))
        goto loc_10016096;
    eax++;
    ecx += 0x00028358;
    if ((int32_t)eax < (int32_t)0x00000004)
        goto loc_10015fe1;
loc_10016001: // 0000:10016001
    if ((int32_t)memoryAGet32(ds, esi + 0x438b7c) <= 0x00000000)
        goto loc_10016e6b;
loc_1001600e: // 0000:1001600e
    memoryASet32(ds, esi + 0x438b7c, memoryAGet32(ds, esi + 0x438b7c) - ebx);
    fp3 = 1e-10;
    ecx = 0;
    edi = 0;
    memoryASet32(ds, esp + 0x24, 0x103fd4e4);
    memoryASet32(ds, esp + 0x2c, 0x103fd4c4);
    ebp = esi + 4321772;
    memoryASet32(ds, esp + 0x3c, ecx);
    memoryASet32(ds, esp + 0x14, ecx);
    memoryASet32(ds, esp + 0x18, ecx);
loc_10016040: // 0000:10016040
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = edi + edx;
    if (!memoryAGet(ds, edi + edx + 0xc33))
        goto loc_10016df8;
    edx = (int8_t)memoryAGet(ds, eax + 0xc34);
    if (edx > 0x0000000a)
        goto loc_10016df8;
    switch (edx)
    {
        case 0: goto loc_10016107;
        case 1: goto loc_100161ed;
        case 2: goto loc_10016375;
        case 3: goto loc_1001645b;
        case 4: goto loc_100164f5;
        case 5: goto loc_1001668b;
        case 6: goto loc_10016821;
        case 7: goto loc_100169c3;
        case 8: goto loc_10016a83;
        case 9: goto loc_10016bd6;
        case 10: goto loc_10016d77;
        default:
            stop("unhandled indirect 0000:10016067");
    }
loc_1001606e: // 0000:1001606e
    memoryASet32(ss, ebp + 0x1d8, 0x00000000);
    goto loc_10015ee4;
loc_1001607d: // 0000:1001607d
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = 0;
    memoryASet32(ds, eax + 0x1d8, ecx);
    memoryASet32(ds, eax + 0x1dc, ecx);
    ebp = eax;
    goto loc_10015ee6;
loc_10016096: // 0000:10016096
    if ((int32_t)eax >= (int32_t)0x00000004)
        goto loc_10016001;
    ecx = 0;
loc_100160a1: // 0000:100160a1
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = ecx + edx;
    if (!memoryAGet(ds, ecx + edx + 0xc33))
        goto loc_100160f4;
    al = memoryAGet(ds, eax + 0xc34);
    if (al == 0x01)
        goto loc_100160c2;
    if (al != 0x02)
        goto loc_100160f4;
loc_100160c2: // 0000:100160c2
    fp1 = fp2;


    fp0 = memoryFGet32(ds, esi + 0xb4);
    memoryFSet32(ds, esp + 0x54, fp0);
    fp0 = memoryFGet32(ds, esp + 0x54);
    memoryASet32(ds, esp + 0x50, (int32_t)floor(fp0));
    fp0 = 0.5f;
    eax = memoryAGet32(ds, esp + 0x50);
    fp1 = 1.0f;
    memoryASet32(ds, esi + 0x438b7c, eax);
    fp2 = 0.007874015718698502f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
loc_100160f4: // 0000:100160f4
    ecx += 0x00000090;
    if ((int32_t)ecx < (int32_t)0x00000120)
        goto loc_100160a1;
    goto loc_1001600e;
loc_10016107: // 0000:10016107
    eax = (int8_t)memoryAGet(ds, eax + 0xc35);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_10016142;

    fp4 = 0.0f;
loc_10016142: // 0000:10016142
    memoryFSet32(ss, ebp - 528, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc36);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp20r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp20r))  // fp4 vs fp3
        goto loc_1001618c;

    fp3 = 0.0f;
loc_1001618c: // 0000:1001618c
    edx = memoryAGet32(ds, esp + 0x3c);
    memoryFSet32(ss, ebp - 532, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd440);
    edx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + edx + 0xc38);
    ecx = ebp - 660;
    memoryASet32(ds, esp + 0x54, edx);
    push32(ecx);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000a);
    indirectCall(cs, edx, 0x0000, 0x100161e0); // 0000:100161e0
    ecx = ebp - 660;
    goto loc_10016dc8;
loc_100161ed: // 0000:100161ed
    eax = (int8_t)memoryAGet(ds, eax + 0xc3f);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_10016228;

    fp4 = 0.0f;
loc_10016228: // 0000:10016228
    memoryFSet32(ss, ebp + 0x84, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc40);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp22r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp22r))  // fp4 vs fp3
        goto loc_10016272;

    fp3 = 0.0f;
loc_10016272: // 0000:10016272
    edx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ss, ebp + 0x80, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd448);
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc42);
    memoryASet32(ds, esp + 0x54, edx);
    push32(ecx);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    ecx = ebp;
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ss, ebp);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000a);
    indirectCall(cs, edx, 0x0000, 0x100162c3); // 0000:100162c3
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc43);
    edx = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, edx + 0x103fd44c);
    memoryASet32(ds, esp + 0x54, ecx);
    edx = memoryAGet32(ss, ebp);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    ecx = ebp;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000b);
    indirectCall(cs, eax, 0x0000, 0x10016316); // 0000:10016316
    ecx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, ecx + 0x103fd450);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc44);
    memoryASet32(ds, esp + 0x54, ecx);
    push32(ecx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    ecx = ebp;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ss, ebp);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x0000000c);
    indirectCall(cs, eax, 0x0000, 0x10016369); // 0000:10016369
    edx = memoryAGet32(ss, ebp);
    ecx = ebp;
    goto loc_10016dca;
loc_10016375: // 0000:10016375
    eax = (int8_t)memoryAGet(ds, eax + 0xc49);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_100163b0;

    fp4 = 0.0f;
loc_100163b0: // 0000:100163b0
    memoryFSet32(ss, ebp + 0x5ac, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc4a);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp24r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp24r))  // fp4 vs fp3
        goto loc_100163fa;

    fp3 = 0.0f;
loc_100163fa: // 0000:100163fa
    edx = memoryAGet32(ds, esp + 0x3c);
    memoryFSet32(ss, ebp + 0x5a8, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd460);
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc4b);
    memoryASet32(ds, esp + 0x54, edx);
    ecx = ebp + 1320;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000008);
    switch (edx)
    {
        case 0x1005a960: subopt_1005a960(); break;
        default:
            stop("unhandled indirect 0000:1001644e");
    }
    ecx = ebp + 1320;
    goto loc_10016dc8;
loc_1001645b: // 0000:1001645b
    eax = (int8_t)memoryAGet(ds, eax + 0xc53);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_10016496;

    fp4 = 0.0f;
loc_10016496: // 0000:10016496
    memoryFSet32(ss, ebp + 0x318, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc54);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp0 *= fp4;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp4 = fp3;
    fp4 = fabsf(fp4);
    fp4 += fp1;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp1 = fp4 - fp1;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp3 = fabsf(fp3);
    fp1 -= fp3;
    fp1 *= fp2;

    _cmp26r = fp0;
    fp0 = fp1;
    if (!(fp1 <= _cmp26r))  // fp1 vs fp0
        goto loc_100164e4;

    fp0 = 0.0f;
loc_100164e4: // 0000:100164e4
    memoryFSet32(ss, ebp + 0x314, fp0);
    ecx = ebp + 660;
    goto loc_10016dc8;
loc_100164f5: // 0000:100164f5
    eax = (int8_t)memoryAGet(ds, eax + 0xc5d);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_10016530;

    fp4 = 0.0f;
loc_10016530: // 0000:10016530
    memoryFSet32(ss, ebp + 0x74c, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc5e);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp28r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp28r))  // fp4 vs fp3
        goto loc_1001657a;

    fp3 = 0.0f;
loc_1001657a: // 0000:1001657a
    edx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ss, ebp + 0x748, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd468);
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc5f);
    memoryASet32(ds, esp + 0x54, edx);
    ecx = ebp + 1736;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    switch (edx)
    {
        case 0x10058ab0: subopt_10058ab0(); break;
        default:
            stop("unhandled indirect 0000:100165ce");
    }
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, eax + 0x103fd46c);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc60);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp + 0x6c8);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    ecx = ebp + 1736;
    push32(ecx);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    switch (eax)
    {
        case 0x10058ab0: subopt_10058ab0(); break;
        default:
            stop("unhandled indirect 0000:10016628");
    }
    ecx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, ecx + 0x103fd470);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc61);
    memoryASet32(ds, esp + 0x54, ecx);
    ecx = ebp + 1736;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000003);
    indirectCall(cs, eax, 0x0000, 0x1001667e); // 0000:1001667e
    ecx = ebp + 1736;
    goto loc_10016dc8;
loc_1001668b: // 0000:1001668b
    eax = (int8_t)memoryAGet(ds, eax + 0xc67);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_100166c6;

    fp4 = 0.0f;
loc_100166c6: // 0000:100166c6
    memoryFSet32(ss, ebp + 0xfdc, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc68);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp30r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp30r))  // fp4 vs fp3
        goto loc_10016710;

    fp3 = 0.0f;
loc_10016710: // 0000:10016710
    edx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ss, ebp + 0xfd8, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd480);
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc69);
    memoryASet32(ds, esp + 0x54, edx);
    ecx = ebp + 3928;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    indirectCall(cs, edx, 0x0000, 0x10016764); // 0000:10016764
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, eax + 0x103fd484);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc6a);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp + 0xf58);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    ecx = ebp + 3928;
    push32(ecx);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    indirectCall(cs, eax, 0x0000, 0x100167be); // 0000:100167be
    ecx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, ecx + 0x103fd488);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc6b);
    memoryASet32(ds, esp + 0x54, ecx);
    ecx = ebp + 3928;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000003);
    indirectCall(cs, eax, 0x0000, 0x10016814); // 0000:10016814
    ecx = ebp + 3928;
    goto loc_10016dc8;
loc_10016821: // 0000:10016821
    eax = (int8_t)memoryAGet(ds, eax + 0xc71);
    edx = memoryAGet32(ds, ecx + 0x103fd430);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    if (!(fp4 <= fp3))  // fp4 vs fp3
        goto loc_1001685c;

    fp4 = 0.0f;
loc_1001685c: // 0000:1001685c
    memoryFSet32(ss, ebp + 0x10b8, fp4);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc72);
    ecx = memoryAGet32(ds, ecx + 0x103fd434);
    memoryASet32(ds, esp + 0x54, eax);
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp4 *= fp0;
    fp4 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp1;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;

    _cmp32r = fp3;
    fp3 = fp4;
    if (!(fp4 <= _cmp32r))  // fp4 vs fp3
        goto loc_100168a6;

    fp3 = 0.0f;
loc_100168a6: // 0000:100168a6
    edx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ss, ebp + 0x10b4, fp3);
    eax = memoryAGet32(ds, edx + 0x103fd498);
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc73);
    memoryASet32(ds, esp + 0x54, edx);
    ecx = ebp + 4148;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + eax * 4 + 0x434054);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    indirectCall(cs, edx, 0x0000, 0x100168fa); // 0000:100168fa
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, eax + 0x103fd49c);
    edx = memoryAGet32(ds, esi + 0xe734);
    eax = (int8_t)memoryAGet(ds, edi + edx + 0xc75);
    memoryASet32(ds, esp + 0x54, eax);
    edx = memoryAGet32(ss, ebp + 0x1034);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    ecx = ebp + 4148;
    push32(ecx);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    indirectCall(cs, eax, 0x0000, 0x10016954); // 0000:10016954
    ecx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, ecx + 0x103fd4a0);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc78);
    memoryASet32(ds, esp + 0x54, ecx);
    ecx = ebp + 4148;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    fp1 = -1.0f;
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0 - fp1;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 += fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000005);
    indirectCall(cs, eax, 0x0000, 0x100169b6); // 0000:100169b6
    ecx = ebp + 4148;
    goto loc_10016dc8;
loc_100169c3: // 0000:100169c3
    eax = (int8_t)memoryAGet(ds, eax + 0xc7d);

    ecx = memoryAGet32(ds, esp + 0x18);
    edx = memoryAGet32(ds, ecx + 0x103fd4b0);
    memoryASet32(ds, esp + 0x54, eax);
    ecx = ebp + 4352;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 -= -1.0f;
    fp3 = fabsf(fp3);
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 -= fp1;
    fp3 = fabsf(fp3);
    fp0 -= fp3;
    fp0 *= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp1 += fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    indirectCall(cs, eax, 0x0000, 0x10016a14); // 0000:10016a14
    ecx = memoryAGet32(ds, esp + 0x18);
    edx = memoryAGet32(ds, ecx + 0x103fd4b4);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc7e);
    memoryASet32(ds, esp + 0x54, ecx);
    ecx = ebp + 4352;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    fp1 = -1.0f;
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0 - fp1;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 += fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    indirectCall(cs, eax, 0x0000, 0x10016a76); // 0000:10016a76
    ecx = ebp + 4352;
    goto loc_10016dc8;
loc_10016a83: // 0000:10016a83
    eax = (int8_t)memoryAGet(ds, eax + 0xc87);

    ecx = memoryAGet32(ds, esp + 0x2c);
    edx = memoryAGet32(ds, ecx - 4);
    memoryASet32(ds, esp + 0x54, eax);
    ecx = ebp + 4588;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    indirectCall(cs, eax, 0x0000, 0x10016ac9); // 0000:10016ac9
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc88);
    eax = memoryAGet32(ds, esp + 0x2c);
    ecx = memoryAGet32(ds, eax);
    memoryASet32(ds, esp + 0x54, edx);
    edx = memoryAGet32(ss, ebp + 0x11ec);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    ecx = ebp + 4588;
    push32(ecx);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    indirectCall(cs, eax, 0x0000, 0x10016b1f); // 0000:10016b1f
    ecx = memoryAGet32(ds, esp + 0x2c);
    edx = memoryAGet32(ds, ecx + 0x4);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc89);
    memoryASet32(ds, esp + 0x54, ecx);
    ecx = ebp + 4588;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000002);
    indirectCall(cs, eax, 0x0000, 0x10016b72); // 0000:10016b72
    ecx = memoryAGet32(ds, esp + 0x2c);
    edx = memoryAGet32(ds, ecx + 0x8);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc8a);
    memoryASet32(ds, esp + 0x54, ecx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ss, ebp + 0x11ec);
    fp1 = fp0;
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    ecx = ebp + 4588;
    fp1 += fp2;
    push32(ecx);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000003);
    indirectCall(cs, eax, 0x0000, 0x10016bc9); // 0000:10016bc9
    ecx = ebp + 4588;
    goto loc_10016dc8;
loc_10016bd6: // 0000:10016bd6
    eax = (int8_t)memoryAGet(ds, eax + 0xc91);

    ecx = memoryAGet32(ds, esp + 0x24);
    edx = memoryAGet32(ds, ecx - 4);
    memoryASet32(ds, esp + 0x54, eax);
    push32(ecx);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    ebx = ebp + 5552;
    ecx = ebx;
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ebx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    indirectCall(cs, eax, 0x0000, 0x10016c1e); // 0000:10016c1e
    ecx = memoryAGet32(ds, esi + 0xe734);
    edx = (int8_t)memoryAGet(ds, edi + ecx + 0xc94);
    eax = memoryAGet32(ds, esp + 0x24);
    ecx = memoryAGet32(ds, eax);
    memoryASet32(ds, esp + 0x54, edx);
    edx = memoryAGet32(ds, ebx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + ecx * 4 + 0x434054);
    ecx = ebx;
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000003);
    indirectCall(cs, eax, 0x0000, 0x10016c6c); // 0000:10016c6c
    ecx = memoryAGet32(ds, esp + 0x24);
    edx = memoryAGet32(ds, ecx + 0x4);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc95);
    memoryASet32(ds, esp + 0x54, ecx);
    push32(ecx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    ecx = ebx;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ebx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000004);
    indirectCall(cs, eax, 0x0000, 0x10016cbb); // 0000:10016cbb
    ecx = memoryAGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, esi + 0xe734);
    edx = memoryAGet32(ds, ecx + 0x8);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc96);
    memoryASet32(ds, esp + 0x54, ecx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ebx);
    eax = memoryAGet32(ds, edx + 0x4c);
    push32(ecx);
    fp1 = fp0;
    ecx = ebx;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000005);
    indirectCall(cs, eax, 0x0000, 0x10016d0a); // 0000:10016d0a
    ecx = memoryAGet32(ds, esp + 0x24);
    edx = memoryAGet32(ds, ecx + 0xc);
    eax = memoryAGet32(ds, esi + 0xe734);
    ecx = (int8_t)memoryAGet(ds, edi + eax + 0xc98);
    memoryASet32(ds, esp + 0x54, ecx);
    push32(ecx);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x58);
    ecx = ebx;
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ebx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000007);
    indirectCall(cs, eax, 0x0000, 0x10016d59); // 0000:10016d59
    eax = memoryAGet32(ds, esp + 0x60);
    edx = memoryAGet32(ds, ebx);
    edx = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x64);
    push32(eax);
    push32(eax);
    ecx = ebx;
    indirectCall(cs, edx, 0x0000, 0x10016d6f); // 0000:10016d6f
    ebx = memoryAGet32(ds, esp + 0x60);
    goto loc_10016dd8;
loc_10016d77: // 0000:10016d77
    eax = (int8_t)memoryAGet(ds, eax + 0xc9f);

    ecx = memoryAGet32(ds, esp + 0x3c);
    edx = memoryAGet32(ds, ecx + 0x103fd508);
    memoryASet32(ds, esp + 0x54, eax);
    ecx = ebp + 5792;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x54);
    push32(ecx);
    fp0 *= fp3;
    fp3 = memoryFGet32(ds, esi + edx * 4 + 0x434054);
    edx = memoryAGet32(ds, ecx);
    eax = memoryAGet32(ds, edx + 0x4c);
    fp0 += fp3;
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esp, fp0);
    push32(0x00000004);
    indirectCall(cs, eax, 0x0000, 0x10016dc0); // 0000:10016dc0
    ecx = ebp + 5792;
loc_10016dc8: // 0000:10016dc8
    edx = memoryAGet32(ds, ecx);
loc_10016dca: // 0000:10016dca
    eax = memoryAGet32(ds, esp + 0x5c);
    push32(0x00000000);
    push32(ebx);
    push32(eax);
    push32(eax);
    eax = memoryAGet32(ds, edx + 0x24);
    switch (eax)
    {
        case 0x1005a9d0: subopt_1005a9d0(); break;
        case 0x1005d330: subopt_1005d330(); break;
        default:
            stop("unhandled indirect 0000:10016dd6");
    }
loc_10016dd8: // 0000:10016dd8
    fp0 = 1e-10;
    ecx = memoryAGet32(ds, esp + 0x18);
    fp1 = 0.5f;
    fp2 = 1.0f;
    fp3 = 0.007874015718698502f;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
loc_10016df8: // 0000:10016df8
    eax = memoryAGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x14, memoryAGet32(ds, esp + 0x14) + 0x0000000c);
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) + 0x00000014);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) + 0x00000004);
    eax += 0x00000010;
    ecx += 0x00000008;
    edi += 0x00000090;
    ebp += 0x00001a2c;
    memoryASet32(ds, esp + 0x18, ecx);
    memoryASet32(ds, esp + 0x2c, eax);
    if ((int32_t)eax < (int32_t)0x103fd4e4)
        goto loc_10016040;
    fp1 = fp3;

    fp0 = fp1;
loc_10016e36: // 0000:10016e36
    eax = memoryAGet32(ds, esi + 0xe734);

    if (!memoryAGet(ds, eax + 0xc1f))
        goto loc_10016e61;
    edx = memoryAGet32(ds, esp + 0x5c);
    push32(ebx);
    eax += 0x00000bff;
    push32(eax);
    ecx = esi + 4334512;
    push32(ecx);
    push32(edx);
    ecx = esi;
    subopt_1001a000();
loc_10016e61: // 0000:10016e61
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000048;
    esp += 12; return;
loc_10016e6b: // 0000:10016e6b
    fp1 = fp2;

    goto loc_10016e36;
}

void subopt_100617c0() // 0000:100617c0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4;
    double _cmp0r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000018;
    push32(esi);
    push32(edi);
    edi = ecx;
    ecx = memoryAGet32(ds, esp + 0x30);
    eax = ecx;
    eax = (int32_t)eax * (int32_t)0x00000628;
    edx = edi + 4;
    esi = (eax + edi) + 1380;
    if (!edx)
        goto loc_100619e0;
    fp0 = 0.0f;
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0x618));

    if (fp0 == _cmp0r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0x618))
        goto loc_100619de;
    fp1 = memoryFGet32(ds, edi + 0x62d74);
    fp1 *= memoryFGet32(ds, esi + 0x604);
    push32(ebx);
    push32(ebp);
    memoryFSet32(ds, esp + 0x1c, fp1);
    fp1 = memoryFGet32(ds, esi + 0x608);
    fp2 = 0.5f;
    fp1 -= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 += memoryFGet32(ds, edi + 0x62d78);
    fp3 = fp2;
    fp3 = fabsf(fp3);
    fp4 = 1.0f;
    fp3 += fp4;
    fp2 -= fp4;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    fp4 = fabsf(fp4);
    fp3 -= fp4;
    fp1 *= fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x18, fp2);
    if (!memoryAGet(ds, edi + 0x62d64))
        goto loc_1006196b;
    fp2 = memoryFGet32(ds, edi + 0x62d6c);
    ebp = memoryAGet32(ds, edi + 0x62d68);
    ebp--;
    fp2 = -fp2;
    memoryFSet32(ds, esp + 0x20, fp2);
    memoryFSet32(ds, esp + 0x14, fp2);
    fp3 = memoryFGet32(ds, edi + 0x62d70);
    fp3 = -fp3;
    memoryFSet32(ds, esp + 0x24, fp3);
    memoryFSet32(ds, esp + 0x10, fp3);
    if ((int32_t)ebp < 0)
        goto loc_100619c7;
    ebx = memoryAGet32(ds, esp + 0x34);
    goto loc_10061880;
loc_1006187a: // 0000:1006187a
    fp2 = 1.0f;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
loc_10061880: // 0000:10061880
    if (ebp)
        goto loc_1006189d;
    if (!(memoryAGet(ds, edi + 0x62d68) & 0x01))
        goto loc_1006189d;

    fp2 = fp0;
    memoryFSet32(ds, esp + 0x14, fp2);
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x10, fp2);
    goto loc_1006189f;
loc_1006189d: // 0000:1006189d
    fp0 = fp2;
loc_1006189f: // 0000:1006189f
    eax = memoryAGet32(ds, esp + 0x38);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= 0.05000000074505806f;
    push32(ebx);
    push32(ecx);
    ecx = edi;
    fp0 += fp1;
    fp0 *= memoryFGet32(ds, esi + 0x618);
    memoryFSet32(ds, esp, fp0);
    push32(ebp);
    push32(eax);
    subopt_10061330();
    fp0 = memoryFGet32(ds, esp + 0x10);
    fp0 += memoryFGet32(ds, esp + 0x18);
    dl = memoryAGet(ds, esi + 0x624);
    ecx = ebp;
    ecx = (int32_t)ecx * (int32_t)0x00000130;
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    push32(0x00000000);
    fp1 = fabsf(fp1);
    esp -= 0x00000008;
    fp0 -= fp1;
    eax = ecx + esi;
    memoryASet(ds, eax + 0x12c, dl);
    ecx = edi;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp + 0x4, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryFSet32(ds, esp, fp0);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x3c);
    push32(ebx);
    push32(eax);
    subopt_100614d0();
    fp0 = memoryFGet32(ds, esp + 0x14);
    fp0 = -fp0;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 = -fp1;
    memoryFSet32(ds, esp + 0x10, fp1);
    fp2 = 0.0f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_10061967;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 += memoryFGet32(ds, esp + 0x20);
    memoryFSet32(ds, esp + 0x14, fp2);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 += memoryFGet32(ds, esp + 0x24);
    memoryFSet32(ds, esp + 0x10, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_10061949: // 0000:10061949
    ebp--;
    if ((int32_t)ebp >= 0)
        goto loc_1006187a;
    ebp = pop32();
    fp0 = fp1;
    ebx = pop32();

    edi = pop32();
    memoryASet(ds, esi + 0x624, 0x01);
    esi = pop32();
    esp += 0x00000018;
    esp += 20; return;
loc_10061967: // 0000:10061967
    fp1 = fp2;
    goto loc_10061949;
loc_1006196b: // 0000:1006196b
    ebx = memoryAGet32(ds, esp + 0x34);

    push32(ebx);

    fp0 = memoryFGet32(ds, esi + 0x618);
    push32(ecx);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    push32(ecx);
    ecx = edi;
    subopt_10061330();
    fp0 = memoryFGet32(ds, esp + 0x18);
    cl = memoryAGet(ds, esi + 0x624);
    edx = memoryAGet32(ds, esp + 0x2c);
    push32(0x00000000);
    esp -= 0x00000008;
    memoryFSet32(ds, esp + 0x4, fp0);
    memoryASet(ds, esi + 0x12c, cl);
    fp0 = memoryFGet32(ds, esp + 0x28);
    ecx = edi;
    memoryFSet32(ds, esp, fp0);
    push32(esi);
    push32(ebx);
    push32(edx);
    subopt_100614d0();
    ebp = pop32();
    ebx = pop32();
    edi = pop32();
    memoryASet(ds, esi + 0x624, 0x01);
    esi = pop32();
    esp += 0x00000018;
    esp += 20; return;
loc_100619c7: // 0000:100619c7
    ebp = pop32();

    ebx = pop32();

    edi = pop32();

    memoryASet(ds, esi + 0x624, 0x01);
    esi = pop32();
    esp += 0x00000018;
    esp += 20; return;
loc_100619de: // 0000:100619de

loc_100619e0: // 0000:100619e0
    edi = pop32();
    esi = pop32();
    esp += 0x00000018;
    esp += 20;
}

void subopt_10061330() // 0000:10061330 +long +stackDrop16
{
    double fp0;
    float fp1, fp2;
    double _cmp0r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x0000002c;
    push32(ebx);
    push32(esi);
    esi = ecx;
    push32(edi);
    if (!memoryAGet32(ds, esi + 0x62dac))
        goto loc_100613a7;
    eax = memoryAGet32(ss, ebp + 0x8);
    fp0 = memoryFGet32(ds, esi + 0x62d7c);
    ecx = memoryAGet32(ss, ebp + 0x14);
    eax = (int32_t)eax * (int32_t)0x00000628;
    fp0 += memoryFGet32(ds, eax + esi + 0xb74);
    fp1 = memoryFGet32(ss, ebp + 0x10);
    edx = memoryAGet32(ss, ebp + 0xc);
    eax = (eax + esi) + 1380;
    edx = (int32_t)edx * (int32_t)0x00000130;
    push32(ecx);
    esp -= 0x00000008;
    edx += eax;
    eax = memoryAGet32(ds, esi + 0x4);
    memoryFSet32(ds, esp + 0x4, fp1);
    ecx = esi;
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp, fp0);
    push32(edx);
    push32(eax);
    subopt_10060f90();
    goto loc_100614aa;
loc_100613a7: // 0000:100613a7
    if (!memoryAGet32(ds, esi + 0x62da0))
        goto loc_100614aa;
    ebx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet32(ss, ebp + 0xc);
    ebx = (int32_t)ebx * (int32_t)0x00000628;
    edx = (int32_t)edx * (int32_t)0x00000130;
    edx += ebx;
    eax = (edx + esi) + 1380;
    ecx = memoryAGet32(ds, esi + 0x4);
    memoryASet32(ds, esp + 0x18, ecx);
    fp0 = memoryFGet32(ds, eax);
    ecx = memoryAGet32(ss, ebp + 0x14);
    memoryFSet32(ds, esp + 0x10, fp0);
    memoryASet32(ds, esp + 0x34, eax);
    fp1 = 1.0f;
    fp1 /= memoryFGet32(ss, ebp + 0x10);
    memoryFSet32(ds, esp + 0x24, fp1);
loc_100613ec: // 0000:100613ec
    fp1 = 1.0f;
    fp0 = fp1 - fp0;
    fp0 *= memoryFGet32(ds, esp + 0x24);
    memoryFSet64(ds, esp + 0x28, fp0);
    fp0 = memoryFGet64(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x14, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    edi = memoryAGet32(ds, esp + 0x14);
    memoryASet32(ds, esp + 0x1c, edi);
    fp0 = memoryFGet64(ds, esp + 0x28) - fp0;
    _cmp0r = 0.0;

    if (fp0 <= _cmp0r)  // fp0 vs 0.0
        goto loc_10061422;
    edi++;
    memoryASet32(ds, esp + 0x1c, edi);
loc_10061422: // 0000:10061422
    if ((int32_t)ecx >= (int32_t)edi)
        goto loc_1006142c;
    edi = ecx;
    memoryASet32(ds, esp + 0x1c, edi);
loc_1006142c: // 0000:1006142c
    ecx -= edi;
    memoryASet32(ds, esp + 0x28, ecx);
    if (!edi)
        goto loc_10061498;
    fp0 = memoryFGet32(ss, ebp + 0x10);
    eax = memoryAGet32(ss, ebp + 0xc);
    edx = memoryAGet32(ds, esp + 0x18);
    push32(edi);
    esp -= 0x00000008;
    memoryFSet32(ds, esp + 0x4, fp0);
    ecx = (ebx + esi) + 1380;
    fp0 = memoryFGet32(ds, esp + 0x1c);
    memoryFSet32(ds, esp, fp0);
    push32(eax);
    eax = memoryAGet32(ds, esi + 0x62da0);
    push32(ecx);
    push32(edx);
    switch (eax)
    {
        case 0x10061a50: subopt_10061a50(); break;
        case 0x10061ad0: subopt_10061ad0(); break;
        default:
            stop("unhandled indirect 0000:1006145f");
    }
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    ecx = memoryAGet32(ds, esp + 0x30);
    edx = ecx + (edi * 4);
    fp0 *= memoryFGet32(ss, ebp + 0x10);
    esp += 0x00000018;
    memoryASet32(ds, esp + 0x18, edx);
    fp0 += memoryFGet32(ds, esp + 0x10);
    memoryFSet32(ds, esp + 0x10, fp0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    ecx = memoryAGet32(ds, esp + 0x28);
    fp0 = memoryFGet32(ds, esp + 0x10) - fp0;
    memoryFSet32(ds, esp + 0x10, fp0);
    goto loc_1006149c;
loc_10061498: // 0000:10061498
    fp0 = memoryFGet32(ds, esp + 0x10);
loc_1006149c: // 0000:1006149c
    if (ecx)
        goto loc_100613ec;
    eax = memoryAGet32(ds, esp + 0x34);
    memoryFSet32(ds, eax, fp0);
loc_100614aa: // 0000:100614aa
    eax = memoryAGet32(ss, ebp + 0x14);
    edx = memoryAGet32(ds, esi + 0xac);
    edx = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    ecx = esi + 172;
    esi += 0x00000004;
    push32(eax);
    push32(esi);
    push32(esi);
    switch (edx)
    {
        case 0x100656a0: subopt_100656a0(); break;
        default:
            stop("unhandled indirect 0000:100614c4");
    }
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 20;
}

void subopt_10060f90() // 0000:10060f90 +long +stackDrop20
{
    float fp0, fp1, fp2, fp3, fp4, fp5;
    double _cmp0r, _cmp1r, _cmp2r;
    StackGuard _sg(20, __FUNCTION__);
    esp -= 4;
    push32(ecx);
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x14);
    fp0 = memoryFGet32(ds, esi + 0x11c);
    push32(edi);
    fp0 *= 127.98999786376953f;
    edi = ecx;
    memoryFSet32(ds, esp + 0xc, fp0);
    fp0 = memoryFGet32(ds, esp + 0xc);
    memoryASet32(ds, esp + 0x18, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x18);
    fp0 = memoryFGet32(ds, edi + eax * 4 + 0x62db0);
    ebx = memoryAGet32(ds, esp + 0x24);
    memoryFSet32(ds, esp + 0xc, fp0);
    fp0 = memoryFGet32(ds, esi);
    if (!ebx)
        goto loc_10061108;
    fp1 = memoryFGet32(ds, esp + 0x20);
    push32(ebp);
    fp2 = memoryFGet32(ds, esp + 0x20);
    ebp = memoryAGet32(ds, esp + 0x18);
    fp3 = 0.0f;
    fp4 = 1.0f;
    goto loc_10060fe6;
loc_10060fe2: // 0000:10060fe2
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
loc_10060fe6: // 0000:10060fe6
    ecx = memoryAGet32(ds, esi + 0x14);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, esi + ecx * 4 + 0x18, fp4);
    edx = memoryAGet32(ds, esi + 0x14);
    memoryFSet32(ds, esi + edx * 4 + 0x98, fp4);
    memoryASet32(ds, esi + 0x14, memoryAGet32(ds, esi + 0x14) + 1);
    eax = memoryAGet32(ds, esi + 0x14);
    ebx--;
    if ((int32_t)eax < (int32_t)0x00000020)
        goto loc_1006100b;
    eax += 0xffffffe0;
    memoryASet32(ds, esi + 0x14, eax);
loc_1006100b: // 0000:1006100b
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    fp4 += fp1;
    memoryFSet32(ds, esp + 0x1c, fp4);
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0x4));

    if (fp4 < _cmp0r)  // fp4 vs (double)fromFp32(memoryAGet32(ds, esi + 0x4))
        goto loc_100610c5;
    fp0 = fp4;
    fp4 = fp3;
    fp1 = fp4 / fp1;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x18, fp3);
    goto loc_10061035;
loc_1006102f: // 0000:1006102f
    fp1 = 1.0f;
    fp2 = memoryFGet32(ds, esp + 0x20);
loc_10061035: // 0000:10061035
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    _cmp1r = (double)fromFp32(memoryAGet32(ds, esi + 0x4));

    if (fp2 > _cmp1r)  // fp2 vs (double)fromFp32(memoryAGet32(ds, esi + 0x4))
        goto loc_10061081;
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x1c, fp1);
    memoryFSet32(ds, esi + 0x11c, fp0);
    fp0 *= 127.98999786376953f;
    memoryFSet32(ds, esp + 0x10, fp0);
    fp0 = memoryFGet32(ds, esp + 0x10);
    memoryASet32(ds, esp + 0x28, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x28);
    fp0 = memoryFGet32(ds, edi + eax * 4 + 0x62db0);
    push32(esi);
    memoryFSet32(ds, esp + 0x14, fp0);
    push32(ecx);
    fp0 = memoryFGet32(ds, esp + 0x20);
    fp0 *= memoryFGet32(ds, esp + 0x24);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    goto loc_10061096;
loc_10061081: // 0000:10061081
    fp1 = fp2;
    push32(esi);

    push32(ecx);
    fp0 -= memoryFGet32(ds, esi + 0x4);
    ecx = memoryAGet32(ds, esi + 0x10);
    ecx++;
    fp0 *= memoryFGet32(ds, esp + 0x20);
    memoryFSet32(ds, esp, fp0);
    push32(ecx);
loc_10061096: // 0000:10061096
    ecx = edi;
    subopt_10060bf0();
    fp0 = memoryFGet32(ds, esi + 0x4);
    fp1 = memoryFGet32(ds, esp + 0x1c);

    _cmp2r = fp0;
    fp0 = fp1;
    if (!(fp1 < _cmp2r))  // fp1 vs fp0
        goto loc_1006102f;
    fp1 = 0.0f;
    fp2 = memoryFGet32(ds, esp + 0x20);
    fp3 = memoryFGet32(ds, esp + 0x24);
    fp4 = 1.0f;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
loc_100610c5: // 0000:100610c5
    eax = memoryAGet32(ds, esi + 0x14);
    fp5 = memoryFGet32(ds, esi + eax * 4 + 0x98);
    ebp += 0x00000004;
    fp5 += memoryFGet32(ds, esi + 0x8);
    memoryFSet32(ds, esi + 0x8, fp5);
    fp5 -= memoryFGet32(ds, esi + 0x118);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + eax * 4 + 0x18);
    fp5 += memoryFGet32(ds, esi + 0x118);
    memoryFSet32(ds, esi + 0x118, fp5);
    fp5 += memoryFGet32(ds, esp + 0x10);
    memoryFSet32(ss, ebp - 4, fp5);
    if (ebx)
        goto loc_10060fe2;
    fp2 = fp4;
    ebp = pop32();

    fp1 = fp2;
    fp0 = fp1;
loc_10061108: // 0000:10061108
    edi = pop32();
    memoryFSet32(ds, esi, fp0);
    esi = pop32();
    ebx = pop32();
    ecx = pop32();
    esp += 24;
}

void subopt_10060bf0() // 0000:10060bf0 +long +stackDrop12
{
    float fp0, fp1, fp2, fp3, fp4;
    double _cmp0r;
    StackGuard _sg(12, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000008;
    eax = memoryAGet32(ds, ecx + 0x62dac);
    push32(ebx);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x14);
    edx = ebp + (ebp * 2);
    edx += edx;
    push32(esi);
    edx += edx;
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x24);
    fp0 = memoryFGet32(ds, edi + 0x11c);
    edx += edx;
    memoryFSet32(ds, esp + 0x10, fp0);
    eax += edx;
    fp1 = memoryFGet32(ds, eax + 0x14);
    fp1 -= memoryFGet32(ds, eax + 0x10);
    fp1 *= fp0;
    fp1 += memoryFGet32(ds, eax + 0x10);
    memoryFSet32(ds, edi + 0x4, fp1);
    fp2 = fp1;
    fp3 = 1.0f;

    _cmp0r = fp1;
    fp1 = fp3;
    if (fp3 > _cmp0r)  // fp3 vs fp1
        goto loc_10060c3f;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x4, fp2);
    goto loc_10060c41;
loc_10060c3f: // 0000:10060c3f
    fp1 = fp2;
loc_10060c41: // 0000:10060c41
    if (!ebp)
        goto loc_10060c5b;
    eax = memoryAGet32(ds, ecx + 0x62dac);
    fp2 = memoryFGet32(ds, eax + edx - 4);
    eax += edx;
    fp2 -= memoryFGet32(ds, eax - 8);
    fp2 *= fp0;
    fp2 += memoryFGet32(ds, eax - 8);
    fp1 -= fp2;
loc_10060c5b: // 0000:10060c5b
    fp2 = 0.0f;

    if (fp2 < fp1)  // fp2 vs fp1
        goto loc_10060c6c;
    fp0 = fp2;

    goto loc_10060c91;
loc_10060c6c: // 0000:10060c6c
    eax = memoryAGet32(ds, ecx + 0x62dac);

    fp2 = memoryFGet32(ds, eax + edx + 0xc);
    eax += edx;
    fp2 -= memoryFGet32(ds, eax + 0x8);
    fp2 *= fp0;
    fp2 += memoryFGet32(ds, eax + 0x8);
    fp3 = memoryFGet32(ds, eax + 0x4);
    fp3 -= memoryFGet32(ds, eax);
    fp0 *= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 += memoryFGet32(ds, eax);
    fp0 -= fp2;
    fp0 /= fp1;
loc_10060c91: // 0000:10060c91
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esp + 0x20);
    fp0 *= 64.0f;
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x24, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, ecx + 0x62dac);
    ecx = memoryAGet32(ds, edi + 0x10);
    esi = memoryAGet32(ds, edi + 0x14);
    fp0 = memoryFGet32(ds, esp + 0x20) - fp0;
    ecx = ecx + (ecx * 2);
    ecx = eax + (ecx * 8);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, eax + edx + 0x4);
    fp0 -= memoryFGet32(ds, eax + edx);
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp0 *= fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, eax + edx);
    fp2 = memoryFGet32(ds, ecx + 0xc);
    fp2 -= memoryFGet32(ds, ecx + 0x8);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx + 0x8);
    fp0 -= fp1;
    memoryFSet32(ds, esp + 0x10, fp0);
    fp0 = memoryFGet32(ds, esp + 0x14);
    fp0 -= memoryFGet32(ds, edi + 0xc);
    memoryFSet32(ds, esp + 0x1c, fp0);
    subopt_100686b0();
    fp0 = memoryFGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esp + 0x24);
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp2 = memoryFGet32(ds, esp + 0x20);
    eax = eax + (edx * 4);
    ebx = esi;
    if ((int32_t)esi >= (int32_t)0x00000020)
        goto loc_10060e48;
    ecx = 0x00000020;
    ecx -= esi;
    if ((int32_t)ecx < (int32_t)0x00000004)
        goto loc_10060dff;
    edx = 0x0000001c;
    edx -= esi;
    edx >>= 2;
    edx++;
    ecx = (edi + (esi * 4)) + 152;
    ebx = esi + (edx * 4);
loc_10060d41: // 0000:10060d41
    fp3 = memoryFGet32(ds, eax + 0x4);
    eax += 0x00000400;
    fp3 -= memoryFGet32(ds, eax - 1024);
    ecx += 0x00000010;
    edx--;
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 1024);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 144);
    memoryFSet32(ds, ecx - 144, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 16);
    memoryFSet32(ds, ecx - 16, fp3);
    fp3 = memoryFGet32(ds, eax - 764);
    fp3 -= memoryFGet32(ds, eax - 768);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 768);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 140);
    memoryFSet32(ds, ecx - 140, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 12);
    memoryFSet32(ds, ecx - 12, fp3);
    fp3 = memoryFGet32(ds, eax - 508);
    fp3 -= memoryFGet32(ds, eax - 512);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 512);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 136);
    memoryFSet32(ds, ecx - 136, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 8);
    memoryFSet32(ds, ecx - 8, fp3);
    fp3 = memoryFGet32(ds, eax - 252);
    fp3 -= memoryFGet32(ds, eax - 256);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 256);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 132);
    memoryFSet32(ds, ecx - 132, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    if (edx)
        goto loc_10060d41;
loc_10060dff: // 0000:10060dff
    if ((int32_t)ebx >= (int32_t)0x00000020)
        goto loc_10060e48;
    edx = 0x00000020;
    ecx = (edi + (ebx * 4)) + 152;
    edx -= ebx;
loc_10060e12: // 0000:10060e12
    fp3 = memoryFGet32(ds, eax + 0x4);
    eax += 0x00000100;
    fp3 -= memoryFGet32(ds, eax - 256);
    ecx += 0x00000004;
    edx--;
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 256);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 132);
    memoryFSet32(ds, ecx - 132, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    if (edx)
        goto loc_10060e12;
loc_10060e48: // 0000:10060e48
    ebx = 0;
    if ((int32_t)esi < (int32_t)0x00000004)
        goto loc_10060f25;
    edx = esi - 4;
    edx >>= 2;
    edx++;
    ecx = edi + 152;
    ebx = (edx * 4) + 0;
loc_10060e67: // 0000:10060e67
    fp3 = memoryFGet32(ds, eax + 0x4);
    eax += 0x00000400;
    fp3 -= memoryFGet32(ds, eax - 1024);
    ecx += 0x00000010;
    edx--;
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 1024);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 144);
    memoryFSet32(ds, ecx - 144, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 16);
    memoryFSet32(ds, ecx - 16, fp3);
    fp3 = memoryFGet32(ds, eax - 764);
    fp3 -= memoryFGet32(ds, eax - 768);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 768);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 140);
    memoryFSet32(ds, ecx - 140, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 12);
    memoryFSet32(ds, ecx - 12, fp3);
    fp3 = memoryFGet32(ds, eax - 508);
    fp3 -= memoryFGet32(ds, eax - 512);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 512);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 136);
    memoryFSet32(ds, ecx - 136, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 8);
    memoryFSet32(ds, ecx - 8, fp3);
    fp3 = memoryFGet32(ds, eax - 252);
    fp3 -= memoryFGet32(ds, eax - 256);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 256);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 132);
    memoryFSet32(ds, ecx - 132, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    if (edx)
        goto loc_10060e67;
loc_10060f25: // 0000:10060f25
    if ((int32_t)ebx >= (int32_t)esi)
        goto loc_10060f68;
    ecx = (edi + (ebx * 4)) + 152;
    esi -= ebx;
loc_10060f32: // 0000:10060f32
    fp3 = memoryFGet32(ds, eax + 0x4);
    eax += 0x00000100;
    fp3 -= memoryFGet32(ds, eax - 256);
    ecx += 0x00000004;
    esi--;
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, eax - 256);
    fp4 = fp3;
    fp4 *= fp1;
    fp4 += memoryFGet32(ds, ecx - 132);
    memoryFSet32(ds, ecx - 132, fp4);
    fp3 *= fp0;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    if (esi)
        goto loc_10060f32;
loc_10060f68: // 0000:10060f68

    memoryASet32(ds, edi + 0x10, ebp);


    fp0 = memoryFGet32(ds, esp + 0x14);
    memoryFSet32(ds, edi + 0xc, fp0);
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000008;
    esp += 16;
}

void subopt_100686b0() // 0000:100686b0 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    eax = 0x103d4600;
    esp += 4;
}

void subopt_10061a50() // 0000:10061a50 +long
{
    double fp0, fp1;
    double _cmp0r;
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, esp + 0xc);
    fp0 = memoryFGet32(ds, ecx + edx * 4 + 0x5f0);
    memoryFSet32(ds, esp + 0x8, fp0);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    fp0 *= memoryFGet32(ds, esp + 0x14);
    fp0 += memoryFGet32(ds, esp + 0x10);
    fp1 = 1.0f;

    _cmp0r = fp0;
    fp0 = fp1;
    if (fp1 > _cmp0r)  // fp1 vs fp0
        goto loc_10061ab6;
    eax = memoryAGet32(ds, 0x1057cca4);
    eax = (int32_t)eax * (int32_t)0x0bb38435;
    eax += 0x3619636b;
    memoryASet32(ds, esp + 0xc, eax);
    memoryASet32(ds, 0x1057cca4, eax);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0xc);
    if ((int32_t)eax >= 0)
        goto loc_10061aa3;
    fp1 += 4294967296.0;
loc_10061aa3: // 0000:10061aa3
    fp1 *= 2.3283064370807974e-10;
    fp1 += fp1;
    fp0 = fp1 - fp0;
    memoryFSet32(ds, ecx + edx * 4 + 0x5f0, fp0);
    goto loc_10061ab8;
loc_10061ab6: // 0000:10061ab6

loc_10061ab8: // 0000:10061ab8
    ecx = memoryAGet32(ds, esp + 0x18);
    if (!ecx)
        goto loc_10061acc;
    eax = memoryAGet32(ds, esp + 0x8);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x8);
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    edi = pop32();
loc_10061acc: // 0000:10061acc
    esp += 4; return;
}

void subopt_10061ad0() // 0000:10061ad0 +long
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    fp0 = memoryFGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, esp + 0x18);
    fp1 = 6.2831854820251465f;
    fp0 *= fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x14, fp1);
    fp0 *= memoryFGet32(ds, esp + 0x10);
    fp0 -= 3.1415927410125732f;
    if (!eax)
        goto loc_10061b51;
    fp1 = -2.3900000201138027e-08f;
    ecx = memoryAGet32(ds, esp + 0x4);
    fp2 = 2.7526000394573202e-06f;
    fp3 = 0.00019840900495182723f;
    fp4 = 0.008333331905305386f;
    fp5 = 0.1666666716337204f;
loc_10061b16: // 0000:10061b16
    fp6 = fp0;
    eax--;
    fp6 *= fp0;
    ecx += 0x00000004;
    fp7 = fp6;
    fp7 *= fp1;
    fp7 += fp2;
    fp7 *= fp6;
    fp7 -= fp3;
    fp7 *= fp6;
    fp7 += fp4;
    fp7 *= fp6;
    fp7 -= fp5;
    fp6 *= fp7;
    fp6 += 1.0f;
    fp6 *= fp0;
    memoryFSet32(ds, ecx - 4, fp6);
    fp6 = memoryFGet32(ds, esp + 0x14);
    fp0 += fp6;
    if (eax)
        goto loc_10061b16;
    fp0 = fp5;
    fp1 = fp4;
    fp2 = fp3;


loc_10061b51: // 0000:10061b51

    esp += 4;
}

void subopt_100656a0() // 0000:100656a0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4, fp5;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x10);
    fp0 = memoryFGet32(ds, ecx + eax * 4 + 0xac);
    fp0 += memoryFGet32(ds, ecx + 0x4ac);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp1 *= 0.5f;
    fp2 = 0.0f;

    if (fp2 == fp1)  // fp2 vs fp1
        goto loc_1006576f;
    fp2 = fp1;
    eax = memoryAGet32(ds, esp + 0x4);
    fp2 *= fp1;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x10);
    push32(ebp);
    fp3 = fp2;
    ebp = memoryAGet32(ds, esp + 0x10);
    fp3 *= fp1;
    push32(esi);
    push32(edi);
    edi = 0;
    fp3 *= fp1;
    esi = eax;
    ebp -= eax;
    fp3 *= 40.0f;
    fp4 = memoryFGet32(ds, ecx + 0x4b0);
    fp1 *= fp4;
    fp4 = fp0;
    fp1 = fp4 - fp1;
    fp4 = fp3;
    fp4 += fp0;
    fp1 *= fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp3 *= 4.0f;
    fp3 += fp0;
    fp3 *= memoryFGet32(ds, ecx + 0x4b4);
    fp4 = fp0;
    fp4 -= memoryFGet32(ds, ecx + 0x4b4);
    fp3 += fp4;
loc_10065728: // 0000:10065728
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_10065767;
    ecx = ebx;
    edx = eax;
    if (!memoryAGet32(ds, esp + 0x18))
        goto loc_1006573c;
    eax = memoryAGet32(ds, esi + ebp);
loc_1006573c: // 0000:1006573c
    if (!ebx)
        goto loc_1006575e;
loc_10065740: // 0000:10065740
    fp4 = memoryFGet32(ds, eax);
    ecx--;
    fp5 = fp4;
    eax += 0x00000004;
    fp5 = fabsf(fp5);
    edx += 0x00000004;
    fp5 *= fp2;
    fp5 += fp0;
    fp4 /= fp5;
    fp4 *= fp1;
    fp4 *= fp3;
    memoryFSet32(ds, edx - 4, fp4);
    if (ecx)
        goto loc_10065740;
loc_1006575e: // 0000:1006575e
    edi++;
    esi += 0x00000004;
    if ((int32_t)edi < (int32_t)0x00000002)
        goto loc_10065728;
loc_10065767: // 0000:10065767
    edi = pop32();
    fp0 = fp3;
    esi = pop32();

    ebp = pop32();
    ebx = pop32();
loc_1006576f: // 0000:1006576f


    esp += 20;
}

void subopt_100614d0() // 0000:100614d0 +long +stackDrop24
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6;
    double _cmp0r;
    StackGuard _sg(24, __FUNCTION__);
    esp -= 4;
    fp0 = 330.0f;
    push32(ebx);
    push32(ebp);
    ebp = ecx;
    fp0 /= memoryFGet32(ss, ebp + 0x70);
    ebx = memoryAGet32(ds, esp + 0x14);
    push32(esi);
    push32(edi);
    fp1 = memoryFGet32(ds, esp + 0x24);
    fp1 *= 1.5707963705062866f;
    fp2 = fp1;
    fp2 *= fp2;
    fp3 = -2.605000020139414e-07f;
    fp3 *= fp2;
    fp3 += 2.476090048730839e-05f;
    fp3 *= fp2;
    fp3 -= 0.001388839678838849f;
    fp3 *= fp2;
    fp3 += 0.04166664183139801f;
    fp3 *= fp2;
    fp3 -= 0.5f;
    fp2 *= fp3;
    fp3 = 1.0f;
    fp2 += fp3;
    fp4 = memoryFGet32(ds, esp + 0x20);
    fp2 *= fp4;
    fp5 = fp1;
    fp5 *= fp1;
    fp6 = -2.3900000201138027e-08f;
    fp6 *= fp5;
    fp6 += 2.7526000394573202e-06f;
    fp6 *= fp5;
    fp6 -= 0.00019840900495182723f;
    fp6 *= fp5;
    fp6 += 0.008333331905305386f;
    fp6 *= fp5;
    fp6 -= 0.1666666716337204f;
    fp5 *= fp6;
    fp5 += fp3;
    fp1 *= fp5;
    fp1 *= fp4;
    if (memoryAGet(ds, ebx + 0x12c))
        goto loc_10061579;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryASet(ds, ebx + 0x12c, 0x01);
    memoryFSet32(ds, ebx + 0x124, fp3);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ebx + 0x128, fp3);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
loc_10061579: // 0000:10061579
    fp4 = memoryFGet32(ds, ebx + 0x124);
    eax = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, eax);
    fp5 = fp2;
    edi = memoryAGet32(ds, esp + 0x18);
    fp5 -= fp4;
    esi = memoryAGet32(ss, ebp + 0x4);
    ecx = edi;
    fp5 = fabsf(fp5);
    fp6 = 6.103515625e-05f;

    _cmp0r = fp5;
    fp5 = fp6;
    if (fp6 <= _cmp0r)  // fp6 vs fp5
        goto loc_1006162f;
    fp4 = fp5;
    fp5 = fp2;
    fp6 = fp3;
    fp6 -= fp2;
    fp6 = fabsf(fp6);

    if (fp6 >= fp4)  // fp6 vs fp4
        goto loc_100615de;

    eax = edx;
    fp2 = fp5;
    if (!edi)
        goto loc_10061654;
    esi -= edx;
loc_100615cc: // 0000:100615cc
    fp5 = memoryFGet32(ds, esi + eax);
    ecx--;
    fp5 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp5);
    if (ecx)
        goto loc_100615cc;
    goto loc_10061654;
loc_100615de: // 0000:100615de
    { double _xchg = fp6; fp6 = fp2; fp2 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_100616dc;
    { double _xchg = fp6; fp6 = fp2; fp2 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_10061615;
    if (!edi)
        goto loc_10061611;
    esi -= edx;
loc_100615fe: // 0000:100615fe
    fp6 = memoryFGet32(ds, esi + edx);
    ecx--;
    fp6 *= fp2;
    edx += 0x00000004;
    fp6 += memoryFGet32(ds, edx - 4);
    memoryFSet32(ds, edx - 4, fp6);
    if (ecx)
        goto loc_100615fe;
loc_10061611: // 0000:10061611
    fp2 = fp5;
    goto loc_10061654;
loc_10061615: // 0000:10061615
    fp2 = fp5;
    if (!edi)
        goto loc_10061654;
    esi -= edx;
loc_1006161d: // 0000:1006161d
    fp5 = memoryFGet32(ds, esi + edx);
    ecx--;
    fp5 += memoryFGet32(ds, edx);
    edx += 0x00000004;
    memoryFSet32(ds, edx - 4, fp5);
    if (ecx)
        goto loc_1006161d;
    goto loc_10061654;
loc_1006162f: // 0000:1006162f
    if (!edi)
        goto loc_10061650;
loc_10061633: // 0000:10061633
    fp6 = memoryFGet32(ds, esi);
    ecx--;
    fp6 *= fp4;
    esi += 0x00000004;
    edx += 0x00000004;
    fp6 += memoryFGet32(ds, edx - 4);
    memoryFSet32(ds, edx - 4, fp6);
    fp6 = fp2;
    fp6 -= fp4;
    fp6 *= fp0;
    fp4 += fp6;
    if (ecx)
        goto loc_10061633;
loc_10061650: // 0000:10061650
    fp2 = fp5;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
loc_10061654: // 0000:10061654
    edx = memoryAGet(ds, esp + 0x28);
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    ecx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ds, ebx + 0x124, fp4);
    ecx = memoryAGet32(ds, ecx + 0x4);
    eax = edx;
    eax &= 0x00000001;
    ebx = memoryAGet32(ss, ebp + eax * 4 + 0x4);
    eax = memoryAGet32(ds, esp + 0x1c);
    esi = edi;
    fp4 = memoryFGet32(ds, eax + 0x128);
    fp5 = fp1;
    fp5 -= fp4;
    fp5 = fabsf(fp5);

    if (fp5 >= fp2)  // fp5 vs fp2
        goto loc_1006175a;

    fp0 = fp3;
    fp3 = fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 -= fp1;
    fp3 = fabsf(fp3);

    if (fp3 >= fp2)  // fp3 vs fp2
        goto loc_100616e5;

    edx = edi;
    fp1 = fp2;
    eax = ecx;

    if (!edi)
        goto loc_1006178a;
    esi = ebx;
    esi -= ecx;
loc_100616bb: // 0000:100616bb
    fp1 = memoryFGet32(ds, esi + eax);
    edx--;
    fp1 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp1);
    if (edx)
        goto loc_100616bb;
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x128, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_100616dc: // 0000:100616dc
    fp2 = fp6;
    fp2 = fp5;
    goto loc_10061654;
loc_100616e5: // 0000:100616e5
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }

    if (fp3 < fp2)  // fp3 vs fp2
        goto loc_1006179b;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    edx = edi;

    if (fp3 < fp2)  // fp3 vs fp2
        goto loc_1006172f;
    if (!edi)
        goto loc_1006171c;
    eax = ebx;
    eax -= ecx;
loc_10061709: // 0000:10061709
    fp2 = memoryFGet32(ds, eax + ecx);
    edx--;
    fp2 *= fp1;
    ecx += 0x00000004;
    fp2 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp2);
    if (edx)
        goto loc_10061709;
loc_1006171c: // 0000:1006171c
    ecx = memoryAGet32(ds, esp + 0x1c);

    edi = pop32();
    memoryFSet32(ds, ecx + 0x128, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_1006172f: // 0000:1006172f

    if (!edi)
        goto loc_1006178a;
    eax = ebx;
    eax -= ecx;
loc_10061739: // 0000:10061739
    fp1 = memoryFGet32(ds, eax + ecx);
    edx--;
    fp1 += memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp1);
    if (edx)
        goto loc_10061739;
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x128, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_1006175a: // 0000:1006175a
    fp2 = fp4;

    if (!edi)
        goto loc_10061786;
    edx &= 0x00000001;
    edx = memoryAGet32(ss, ebp + edx * 4 + 0x4);
    edx -= ecx;
loc_1006176b: // 0000:1006176b
    fp3 = memoryFGet32(ds, edx + ecx);
    esi--;
    fp3 *= fp2;
    ecx += 0x00000004;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    fp3 = fp1;
    fp3 -= fp2;
    fp3 *= fp0;
    fp2 += fp3;
    if (esi)
        goto loc_1006176b;
loc_10061786: // 0000:10061786
    fp1 = fp2;
    fp0 = fp1;
loc_1006178a: // 0000:1006178a
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x128, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_1006179b: // 0000:1006179b
    ecx = memoryAGet32(ds, esp + 0x1c);
    fp1 = fp3;
    edi = pop32();
    fp1 = fp2;
    esi = pop32();

    ebp = pop32();
    memoryFSet32(ds, ecx + 0x128, fp0);
    ebx = pop32();
    esp += 28;
}

void subopt_1005f7e0() // 0000:1005f7e0 +long +stackDrop4
{
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = (int32_t)eax * (int32_t)0x00000098;
    al = memoryAGet(ds, eax + ecx + 0x144);
    esp += 8;
}

void subopt_10060640() // 0000:10060640 +long +stackDrop16
{
    float fp0, fp1, fp2;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xffffffc0;
    eax = memoryAGet32(ss, ebp + 0x14);
    esp -= 0x00000034;
    push32(ebx);
    push32(esi);
    esi = ecx;
    ecx = eax;
    ecx = (int32_t)ecx * (int32_t)0x00000098;
    push32(edi);
    edi = (ecx + esi) + 176;
    ecx = esi + 4;
    if (!ecx)
        goto loc_10060800;
    if (!memoryAGet32(ds, edi + 0x90))
        goto loc_10060800;
    if (!memoryAGet(ds, edi + 0x94))
        goto loc_10060800;
    fp0 = memoryFGet32(ds, esi + 0x9d78);
    fp0 *= memoryFGet32(ds, edi + 0x68);
    memoryFSet32(ds, esp + 0x34, fp0);
    fp0 = memoryFGet32(ds, edi + 0x6c);
    fp0 -= 0.5f;
    fp0 += memoryFGet32(ds, esi + 0x9d7c);
    memoryFSet32(ds, esp + 0x30, fp0);
    if (!memoryAGet(ds, esi + 0x9d68))
        goto loc_1006080d;
    fp0 = memoryFGet32(ds, esi + 0x9d70);
    ebx = memoryAGet32(ds, esi + 0x9d6c);
    fp0 = -fp0;
    ecx = 0x00000001;
    ebx -= ecx;
    memoryFSet32(ds, esp + 0x38, fp0);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp1 = memoryFGet32(ds, esi + 0x9d74);
    fp1 = -fp1;
    memoryFSet32(ds, esp + 0x3c, fp1);
    memoryFSet32(ds, esp + 0x24, fp1);
    if ((int32_t)ebx < 0)
        goto loc_100607f7;
    fp1 = 0.0f;
    goto loc_100606f0;
loc_100606e9: // 0000:100606e9
    ecx = memoryAGet32(ds, esp + 0x2c);
    eax = memoryAGet32(ss, ebp + 0x14);
loc_100606f0: // 0000:100606f0
    if (!ecx)
        goto loc_100607f5;
    if (ebx)
        goto loc_10060715;
    if (!(memoryAGet(ds, esi + 0x9d6c) & 0x01))
        goto loc_10060715;
    fp0 = fp1;
    fp1 = fp0;
    memoryFSet32(ds, esp + 0x28, fp1);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x24, fp1);
    goto loc_10060717;
loc_10060715: // 0000:10060715

loc_10060717: // 0000:10060717
    fp0 *= 0.05000000074505806f;
    edx = memoryAGet32(ss, ebp + 0x10);
    push32(edx);
    esp -= 0x00000008;
    fp0 += 1.0f;
    ecx = esi;
    fp0 *= memoryFGet32(ds, edi + 0x88);
    memoryFSet64(ds, esp, fp0);
    push32(ebx);
    push32(eax);
    sub_1005fc90();
    memoryASet32(ds, esp + 0x2c, eax);
    if (!eax)
        goto loc_100607b7;
    eax = memoryAGet32(ss, ebp + 0x10);
    edx = memoryAGet32(ds, esi + 0x98b0);
    edx = memoryAGet32(ds, edx + 0x24);
    push32(0x00000000);
    push32(eax);
    eax = esi + 4;
    ecx = esi + 39088;
    push32(eax);
    push32(eax);
    switch (edx)
    {
        case 0x100656a0: subopt_100656a0(); break;
        default:
            stop("unhandled indirect 0000:1006075e");
    }
    fp0 = memoryFGet32(ds, esp + 0x24);
    fp0 += memoryFGet32(ds, esp + 0x30);
    cl = memoryAGet(ds, edi + 0x96);
    eax = ebx + (ebx * 2);
    fp1 = fp0;
    eax = edi + (eax * 4);
    fp1 = fabsf(fp1);
    dl = memoryAGet32(ds, esp + 0x2c) == 0x00000002;
    fp2 = 1.0f;
    memoryASet(ds, eax + 0x8, cl);
    fp1 += fp2;
    ecx = dl;
    edx = memoryAGet32(ss, ebp + 0x10);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    push32(ecx);
    esp -= 0x00000008;
    ecx = esi;
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp + 0x4, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryFSet32(ds, esp, fp0);
    push32(eax);
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(edx);
    push32(eax);
    subopt_10060380();
loc_100607b7: // 0000:100607b7
    fp0 = memoryFGet32(ds, esp + 0x28);
    fp0 = -fp0;
    memoryFSet32(ds, esp + 0x28, fp0);
    fp1 = memoryFGet32(ds, esp + 0x24);
    fp1 = -fp1;
    memoryFSet32(ds, esp + 0x24, fp1);
    fp2 = 0.0f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_10060809;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 += memoryFGet32(ds, esp + 0x38);
    memoryFSet32(ds, esp + 0x28, fp2);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 += memoryFGet32(ds, esp + 0x3c);
    memoryFSet32(ds, esp + 0x24, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_100607ec: // 0000:100607ec
    ebx--;
    if ((int32_t)ebx >= 0)
        goto loc_100606e9;
loc_100607f5: // 0000:100607f5
    fp0 = fp1;
loc_100607f7: // 0000:100607f7

loc_100607f9: // 0000:100607f9
    memoryASet(ds, edi + 0x96, 0x01);
loc_10060800: // 0000:10060800
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 20; return;
loc_10060809: // 0000:10060809
    fp1 = fp2;
    goto loc_100607ec;
loc_1006080d: // 0000:1006080d
    ebx = memoryAGet32(ss, ebp + 0x10);
    fp0 = memoryFGet32(ds, edi + 0x88);
    push32(ebx);
    esp -= 0x00000008;
    memoryFSet64(ds, esp, fp0);
    push32(0x00000000);
    push32(eax);
    ecx = esi;
    sub_1005fc90();
    memoryASet32(ds, esp + 0x2c, eax);
    if (!eax)
        goto loc_100607f9;
    edx = memoryAGet32(ds, esi + 0x98b0);
    push32(0x00000000);
    push32(ebx);
    eax = esi + 4;
    ecx = esi + 39088;
    push32(eax);
    push32(eax);
    eax = memoryAGet32(ds, edx + 0x24);
    switch (eax)
    {
        case 0x100656a0: subopt_100656a0(); break;
        default:
            stop("unhandled indirect 0000:10060846");
    }
    fp0 = memoryFGet32(ds, esp + 0x30);
    fp1 = fp0;
    cl = memoryAGet(ds, edi + 0x96);
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    dl = memoryAGet32(ds, esp + 0x2c) == 0x00000002;
    fp1 += fp2;
    eax = dl;
    fp0 -= fp2;
    push32(eax);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    esp -= 0x00000008;
    memoryASet(ds, edi + 0x8, cl);
    ecx = memoryAGet32(ss, ebp + 0x8);
    fp1 = fabsf(fp1);
    fp0 -= fp1;
    fp0 *= 0.5f;
    memoryFSet32(ds, esp + 0x4, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryFSet32(ds, esp, fp0);
    push32(edi);
    push32(ebx);
    push32(ecx);
    ecx = esi;
    subopt_10060380();
    memoryASet(ds, edi + 0x96, 0x01);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 20;
}

void subopt_1005fc90() // 0000:1005fc90 +long +stackDrop20
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
    fp0 = memoryFGet64(ds, ecx + eax * 8 + 0x40);
    edi = memoryAGet32(ds, ecx + eax * 4 + 0x74);
    memoryFSet64(ds, esp + 0x70, fp0);
    memoryASet32(ds, esp + 0x10, edi);
    fp1 = memoryFGet64(ss, ebp + 0x10);
    fp2 = 0.0f;
    fp3 = -1.0;
loc_1005fd2f: // 0000:1005fd2f
    fp4 = fp1;
    memoryFSet64(ds, esp + 0x60, fp4);
    if (!memoryAGet(ds, ecx + 0x95))
        goto loc_1005fd4c;
    if ((int32_t)edi < 0)
        goto loc_1005fd4c;

    fp4 = fp1;
    fp4 = -fp4;
    memoryFSet64(ds, esp + 0x60, fp4);
loc_1005fd4c: // 0000:1005fd4c

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
    fp4 = -fp4;
    edi = esi;
    memoryFSet64(ds, esp + 0x60, fp4);
loc_1005fd7d: // 0000:1005fd7d
    memoryASet(ds, ecx + 0x95, 0x00);
loc_1005fd84: // 0000:1005fd84
    memoryASet32(ds, esp + 0x10, edi);
loc_1005fd88: // 0000:1005fd88
    if (!memoryAGet(ds, ecx + 0x94))
        goto loc_10060357;
    fp0 = fp4;
    fp1 = fp3;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005fdf2;
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_1005fdea;
    eax = edi;
    eax -= esi;
    memoryASet32(ds, esp + 0x40, eax);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 / fp0;
    fp0 *= fp1;
    goto loc_1005fe1d;
loc_1005fdbd: // 0000:1005fdbd
    eax = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, eax + 0xc);
    eax -= esi;
    edi += eax;
    goto loc_1005fd84;
loc_1005fdca: // 0000:1005fdca
    eax = esi;
    fp4 = -fp4;
    eax -= edi;
    memoryFSet64(ds, esp + 0x60, fp4);
    edi = eax;
    goto loc_1005fd7d;
loc_1005fdd8: // 0000:1005fdd8
    if ((int32_t)edi >= 0)
        goto loc_1005fd88;

    memoryASet(ds, ecx + 0x94, 0x00);
    goto loc_100602f7;
loc_1005fdea: // 0000:1005fdea
    fp0 = fp1 / fp0;
    fp0 *= (double)(int32_t)memoryAGet32(ds, esp + 0x10);
    goto loc_1005fe1d;
loc_1005fdf2: // 0000:1005fdf2

    eax = memoryAGet32(ds, esp + 0x14);
    if (!memoryAGet(ds, esp + 0xf))
        goto loc_1005fe0e;
    eax = memoryAGet32(ds, eax + 0xc);
    eax -= edi;
    memoryASet32(ds, esp + 0x40, eax);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    goto loc_1005fe1b;
loc_1005fe0e: // 0000:1005fe0e
    eax = memoryAGet32(ds, eax + 0x4);
    eax -= edi;
    memoryASet32(ds, esp + 0x40, eax);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
loc_1005fe1b: // 0000:1005fe1b
    fp0 = fp1 / fp0;
loc_1005fe1d: // 0000:1005fe1d
    memoryFSet64(ds, esp + 0x48, fp0);
    fp0 = memoryFGet64(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x2c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x2c);
    ebx = memoryAGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x24, ebx);
    fp0 = memoryFGet64(ds, esp + 0x48) - fp0;
    fp1 = 0.0f;

    _cmp2r = fp0;
    fp0 = fp1;
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

    fp0 = memoryFGet64(ds, esp + 0x70);
    memoryFSet32(ds, esp + 0x44, fp0);
    goto loc_1005fe92;
    // gap 5 bytes // gap 5 bytes
loc_1005fe90: // 0000:1005fe90

loc_1005fe92: // 0000:1005fe92
    fp0 = memoryFGet64(ds, esp + 0x70);
    ecx = memoryAGet32(ds, esp + 0x40);
    fp1 = memoryFGet32(ds, esp + 0x44);
    edi = memoryAGet32(ds, esp + ecx * 4 + 0x68);
    memoryFSet32(ds, esp + 0x20, fp1);
    edx = 0;
    fp2 = 1.0f;
    fp3 = fp2;
    fp4 = memoryFGet64(ds, esp + 0x60);

    _cmp3r = fp3;
    fp3 = fp4;
    if (fp4 != _cmp3r)  // fp4 vs fp3
        goto loc_1005ff03;
    fp4 = 0.0f;

    if (fp4 != fp1)  // fp4 vs fp1
        goto loc_1005ff03;

    eax = ebx;

    edx = esi;
    fp0 = fp1;
    ecx = edi;
    fp1 = 3.0517578125e-05f;
loc_1005fed8: // 0000:1005fed8
    ebx = (int16_t)memoryAGet16(ds, edx);
    memoryASet32(ds, esp + 0x48, ebx);
    eax--;
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    ecx += 0x00000004;
    edx += 0x00000002;
    fp2 *= fp1;
    memoryFSet32(ds, ecx - 4, fp2);
    if (eax)
        goto loc_1005fed8;
    ebx = memoryAGet32(ds, esp + 0x24);

    edi = edi + (ebx * 4);
    edx = ebx;
    goto loc_1005ffe7;
loc_1005ff03: // 0000:1005ff03
    fp4 = -1.0;

    if (fp4 != fp3)  // fp4 vs fp3
        goto loc_1005ff5a;
    fp3 = 0.0f;

    if (fp3 != fp1)  // fp3 vs fp1
        goto loc_1005ff5a;

    eax = ebx;
    fp0 = fp1;
    edx = esi;
    fp1 = 3.0517578125e-05f;
    ecx = edi;
loc_1005ff2d: // 0000:1005ff2d
    ebx = (int16_t)memoryAGet16(ds, edx);
    memoryASet32(ds, esp + 0x48, ebx);
    eax--;
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    ecx += 0x00000004;
    edx -= 0x00000002;
    fp2 *= fp1;
    memoryFSet32(ds, ecx - 4, fp2);
    if (eax)
        goto loc_1005ff2d;
    ebx = memoryAGet32(ds, esp + 0x24);

    edx = ebx;
    edi = edi + (ebx * 4);
    edx = -edx;
    goto loc_1005ffe7;
loc_1005ff5a: // 0000:1005ff5a
    eax = memoryAGet32(ds, esp + 0x28);
    ecx = memoryAGet32(ds, eax + 0x9d80);
    if (ecx != 0x00000003)
        goto loc_1005ff89;
    fp2 -= memoryFGet64(ss, ebp + 0x10);
    fp2 = fabs(fp2);
    _cmp7r = 0.10000000149011612;

    if (fp2 < _cmp7r)  // fp2 vs 0.10000000149011612
        goto loc_1005ff82;
    ecx = 0x00000001;
    goto loc_1005ff8b;
loc_1005ff82: // 0000:1005ff82
    ecx = 0x00000002;
    goto loc_1005ff8b;
loc_1005ff89: // 0000:1005ff89

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

    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    edi += 0x00000004;
    fp1 *= 3.0517578125e-05f;
    memoryFSet32(ds, edi - 4, fp1);
    fp0 += memoryFGet64(ds, esp + 0x60);
    memoryFSet64(ds, esp + 0x50, fp0);
    fp0 = memoryFGet64(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x30, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x30);
    edx = memoryAGet32(ds, esp + 0x30);
    fp1 = memoryFGet64(ds, esp + 0x50);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x20, fp1);
    if (eax)
        goto loc_1005ffa0;
loc_1005ffe5: // 0000:1005ffe5
    fp0 = fp1;
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
    fp1 = 0.0f;
    edi = memoryAGet32(ds, esp + 0x10);
    ecx = memoryAGet32(ds, esp + 0x5c);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_10060015: // 0000:10060015
    esi = memoryAGet32(ds, esp + 0x18);
    memoryFSet64(ds, esp + 0x50, fp1);
    edi += edx;
    memoryASet32(ds, esp + 0x10, edi);
loc_10060023: // 0000:10060023
    _cmp8r = memoryFGet64(ds, esp + 0x60);

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
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_1006007a: // 0000:1006007a
    edx = memoryAGet32(ds, esi + edx * 2);
    ecx = (int16_t)dx;
    edx = sar32(edx, 0x10);
    edx -= ecx;
    memoryASet32(ds, esp + 0x48, edx);
    memoryASet32(ds, esp + 0x20, ecx);
    fp1 *= (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    eax--;
    edi += 0x00000004;
    fp1 += (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    fp1 *= 3.0517578125e-05f;
    memoryFSet32(ds, edi - 4, fp1);
    fp0 += memoryFGet64(ds, esp + 0x60);
    memoryFSet64(ds, esp + 0x50, fp0);
    fp0 = memoryFGet64(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    edx = memoryAGet32(ds, esp + 0x34);
    fp1 = memoryFGet64(ds, esp + 0x50);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (eax)
        goto loc_10060078;

    memoryFSet32(ds, esp + 0x20, fp0);
    goto loc_1005ffe7;
loc_100600d1: // 0000:100600d1
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_100600d3: // 0000:100600d3
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 - 2);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x2);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    edx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x4);
    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x48, edx);
    edi += 0x00000004;
    fp5 = fp4;
    fp5 -= fp2;
    fp6 = 0.5f;
    fp5 *= fp6;
    fp7 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    fp7 -= fp2;
    fp6 *= fp7;
    fp7 = fp3;
    fp4 = fp7 - fp4;
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }
    fp6 *= 1.5f;
    fp4 += fp6;
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }
    fp5 -= fp3;
    fp5 += fp2;
    fp5 -= fp4;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 *= fp1;
    fp4 += fp5;
    fp4 *= fp1;
    fp2 += fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp1 *= fp3;
    fp1 += fp2;
    fp1 *= 3.0517578125e-05f;
    memoryFSet32(ds, edi - 4, fp1);
    fp0 += memoryFGet64(ds, esp + 0x60);
    memoryFSet64(ds, esp + 0x50, fp0);
    fp0 = memoryFGet64(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x38, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x38);
    edx = memoryAGet32(ds, esp + 0x38);
    fp1 = memoryFGet64(ds, esp + 0x50);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (eax)
        goto loc_100600d1;

    memoryFSet32(ds, esp + 0x20, fp0);
    goto loc_1005ffe7;
loc_1006017c: // 0000:1006017c
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_1006017e: // 0000:1006017e
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 - 2);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x48, ecx);
    ecx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x2);
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    edx = (int16_t)memoryAGet16(ds, esi + edx * 2 + 0x4);
    memoryASet32(ds, esp + 0x48, ecx);
    eax--;
    fp4 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    memoryASet32(ds, esp + 0x48, edx);
    edi += 0x00000004;
    fp5 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    memoryFSet32(ds, esp + 0x48, fp5);
    fp5 = fp2 - fp5;
    memoryFSet32(ds, esp + 0x50, fp5);
    fp6 = fp4;
    fp6 -= fp3;
    memoryFSet32(ds, esp + 0x20, fp6);
    fp6 *= 6.0f;
    fp7 = 2.0f;
    fp5 *= fp7;
    { double _xchg = fp7; fp7 = fp6; fp6 = _xchg; }
    fp5 += fp7;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp1;
    fp7 = memoryFGet32(ds, esp + 0x48);
    fp7 -= fp2;
    fp7 *= 5.0f;
    fp6 += fp7;
    fp7 = fp3;
    fp7 -= fp4;
    fp7 *= 15.0f;
    fp6 += fp7;
    fp6 *= fp1;
    fp7 = memoryFGet32(ds, esp + 0x20);
    fp7 *= 9.0f;
    fp6 += fp7;
    fp7 = memoryFGet32(ds, esp + 0x50);
    fp7 *= 3.0f;
    fp6 += fp7;
    fp6 *= fp1;
    fp7 = fp3;
    fp5 *= fp7;
    fp5 = fp6 - fp5;
    fp5 += fp4;
    fp5 += fp2;
    fp5 *= fp1;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp2 = fp5 - fp2;
    fp2 += fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp1 *= fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 *= 0.5f;
    fp1 += fp2;
    fp1 *= 3.0517578125e-05f;
    memoryFSet32(ds, edi - 4, fp1);
    fp0 += memoryFGet64(ds, esp + 0x60);
    memoryFSet64(ds, esp + 0x50, fp0);
    fp0 = memoryFGet64(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x3c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x3c);
    edx = memoryAGet32(ds, esp + 0x3c);
    fp1 = memoryFGet64(ds, esp + 0x50);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (eax)
        goto loc_1006017c;

    memoryFSet32(ds, esp + 0x20, fp0);
    goto loc_1005ffe7;
loc_1006026f: // 0000:1006026f
    fp1 = memoryFGet32(ds, esp + 0x20);
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
    fp1 = memoryFGet64(ds, esp + 0x50);
    ebx = memoryAGet32(ds, esp + 0x28);
    memoryFSet64(ds, esp + 0x70, fp1);
    fp2 = memoryFGet64(ss, ebp + 0x10);
    fp3 = -1.0;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
loc_100602f7: // 0000:100602f7
    if (!memoryAGet32(ss, ebp + 0x18))
        goto loc_1006030a;
    if (memoryAGet(ds, ecx + 0x94))
        goto loc_1005fd2f;
loc_1006030a: // 0000:1006030a
    eax = memoryAGet32(ss, ebp + 0xc);
    fp1 = fp3;


    memoryFSet64(ds, ecx + eax * 8 + 0x40, fp0);
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

void subopt_10060380() // 0000:10060380 +long +stackDrop24
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6;
    double _cmp0r;
    StackGuard _sg(24, __FUNCTION__);
    esp -= 4;
    fp0 = 330.0f;
    push32(ebx);
    push32(ebp);
    ebp = ecx;
    fp0 /= memoryFGet32(ss, ebp + 0x70);
    ebx = memoryAGet32(ds, esp + 0x14);
    push32(esi);
    push32(edi);
    fp1 = memoryFGet32(ds, esp + 0x24);
    fp1 *= 1.5707963705062866f;
    fp2 = fp1;
    fp2 *= fp2;
    fp3 = -2.605000020139414e-07f;
    fp3 *= fp2;
    fp3 += 2.476090048730839e-05f;
    fp3 *= fp2;
    fp3 -= 0.001388839678838849f;
    fp3 *= fp2;
    fp3 += 0.04166664183139801f;
    fp3 *= fp2;
    fp3 -= 0.5f;
    fp2 *= fp3;
    fp3 = 1.0f;
    fp2 += fp3;
    fp4 = memoryFGet32(ds, esp + 0x20);
    fp2 *= fp4;
    fp5 = fp1;
    fp5 *= fp1;
    fp6 = -2.3900000201138027e-08f;
    fp6 *= fp5;
    fp6 += 2.7526000394573202e-06f;
    fp6 *= fp5;
    fp6 -= 0.00019840900495182723f;
    fp6 *= fp5;
    fp6 += 0.008333331905305386f;
    fp6 *= fp5;
    fp6 -= 0.1666666716337204f;
    fp5 *= fp6;
    fp5 += fp3;
    fp1 *= fp5;
    fp1 *= fp4;
    if (memoryAGet(ds, ebx + 0x8))
        goto loc_1006041c;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryASet(ds, ebx + 0x8, 0x01);
    memoryFSet32(ds, ebx, fp3);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ebx + 0x4, fp3);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
loc_1006041c: // 0000:1006041c
    fp4 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, eax);
    fp5 = fp2;
    edi = memoryAGet32(ds, esp + 0x18);
    fp5 -= fp4;
    esi = memoryAGet32(ss, ebp + 0x4);
    ecx = edi;
    fp5 = fabsf(fp5);
    fp6 = 6.103515625e-05f;

    _cmp0r = fp5;
    fp5 = fp6;
    if (fp6 <= _cmp0r)  // fp6 vs fp5
        goto loc_100604ce;
    fp4 = fp5;
    fp5 = fp2;
    fp6 = fp3;
    fp6 -= fp2;
    fp6 = fabsf(fp6);

    if (fp6 >= fp4)  // fp6 vs fp4
        goto loc_1006047d;

    eax = edx;
    fp2 = fp5;
    if (!edi)
        goto loc_100604f3;
    esi -= edx;
loc_1006046b: // 0000:1006046b
    fp5 = memoryFGet32(ds, esi + eax);
    ecx--;
    fp5 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp5);
    if (ecx)
        goto loc_1006046b;
    goto loc_100604f3;
loc_1006047d: // 0000:1006047d
    { double _xchg = fp6; fp6 = fp2; fp2 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_10060571;
    { double _xchg = fp6; fp6 = fp2; fp2 = _xchg; }

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_100604b4;
    if (!edi)
        goto loc_100604b0;
    esi -= edx;
loc_1006049d: // 0000:1006049d
    fp6 = memoryFGet32(ds, esi + edx);
    ecx--;
    fp6 *= fp2;
    edx += 0x00000004;
    fp6 += memoryFGet32(ds, edx - 4);
    memoryFSet32(ds, edx - 4, fp6);
    if (ecx)
        goto loc_1006049d;
loc_100604b0: // 0000:100604b0
    fp2 = fp5;
    goto loc_100604f3;
loc_100604b4: // 0000:100604b4
    fp2 = fp5;
    if (!edi)
        goto loc_100604f3;
    esi -= edx;
loc_100604bc: // 0000:100604bc
    fp5 = memoryFGet32(ds, esi + edx);
    ecx--;
    fp5 += memoryFGet32(ds, edx);
    edx += 0x00000004;
    memoryFSet32(ds, edx - 4, fp5);
    if (ecx)
        goto loc_100604bc;
    goto loc_100604f3;
loc_100604ce: // 0000:100604ce
    if (!edi)
        goto loc_100604ef;
loc_100604d2: // 0000:100604d2
    fp6 = memoryFGet32(ds, esi);
    ecx--;
    fp6 *= fp4;
    esi += 0x00000004;
    edx += 0x00000004;
    fp6 += memoryFGet32(ds, edx - 4);
    memoryFSet32(ds, edx - 4, fp6);
    fp6 = fp2;
    fp6 -= fp4;
    fp6 *= fp0;
    fp4 += fp6;
    if (ecx)
        goto loc_100604d2;
loc_100604ef: // 0000:100604ef
    fp2 = fp5;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
loc_100604f3: // 0000:100604f3
    edx = memoryAGet(ds, esp + 0x28);
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    ecx = memoryAGet32(ds, esp + 0x14);
    memoryFSet32(ds, ebx, fp4);
    ecx = memoryAGet32(ds, ecx + 0x4);
    eax = edx;
    eax &= 0x00000001;
    ebx = memoryAGet32(ss, ebp + eax * 4 + 0x4);
    eax = memoryAGet32(ds, esp + 0x1c);
    esi = edi;
    fp4 = memoryFGet32(ds, eax + 0x4);
    fp5 = fp1;
    fp5 -= fp4;
    fp5 = fabsf(fp5);

    if (fp5 >= fp2)  // fp5 vs fp2
        goto loc_100605e9;

    fp0 = fp3;
    fp3 = fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 -= fp1;
    fp3 = fabsf(fp3);

    if (fp3 >= fp2)  // fp3 vs fp2
        goto loc_1006057a;

    edx = edi;
    fp1 = fp2;
    eax = ecx;

    if (!edi)
        goto loc_10060619;
    esi = ebx;
    esi -= ecx;
loc_10060553: // 0000:10060553
    fp1 = memoryFGet32(ds, esi + eax);
    edx--;
    fp1 += memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, eax - 4, fp1);
    if (edx)
        goto loc_10060553;
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x4, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_10060571: // 0000:10060571
    fp2 = fp6;
    fp2 = fp5;
    goto loc_100604f3;
loc_1006057a: // 0000:1006057a
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }

    if (fp3 < fp2)  // fp3 vs fp2
        goto loc_10060627;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    edx = edi;

    if (fp3 < fp2)  // fp3 vs fp2
        goto loc_100605c1;
    if (!edi)
        goto loc_100605b1;
    eax = ebx;
    eax -= ecx;
loc_1006059e: // 0000:1006059e
    fp2 = memoryFGet32(ds, eax + ecx);
    edx--;
    fp2 *= fp1;
    ecx += 0x00000004;
    fp2 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp2);
    if (edx)
        goto loc_1006059e;
loc_100605b1: // 0000:100605b1
    ecx = memoryAGet32(ds, esp + 0x1c);

    edi = pop32();
    memoryFSet32(ds, ecx + 0x4, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_100605c1: // 0000:100605c1

    if (!edi)
        goto loc_10060619;
    eax = ebx;
    eax -= ecx;
loc_100605cb: // 0000:100605cb
    fp1 = memoryFGet32(ds, eax + ecx);
    edx--;
    fp1 += memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp1);
    if (edx)
        goto loc_100605cb;
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x4, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_100605e9: // 0000:100605e9
    fp2 = fp4;

    if (!edi)
        goto loc_10060615;
    edx &= 0x00000001;
    edx = memoryAGet32(ss, ebp + edx * 4 + 0x4);
    edx -= ecx;
loc_100605fa: // 0000:100605fa
    fp3 = memoryFGet32(ds, ecx + edx);
    esi--;
    fp3 *= fp2;
    ecx += 0x00000004;
    fp3 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp3);
    fp3 = fp1;
    fp3 -= fp2;
    fp3 *= fp0;
    fp2 += fp3;
    if (esi)
        goto loc_100605fa;
loc_10060615: // 0000:10060615
    fp1 = fp2;
    fp0 = fp1;
loc_10060619: // 0000:10060619
    ecx = memoryAGet32(ds, esp + 0x1c);
    edi = pop32();
    memoryFSet32(ds, ecx + 0x4, fp0);
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 28; return;
loc_10060627: // 0000:10060627
    ecx = memoryAGet32(ds, esp + 0x1c);
    fp1 = fp3;
    edi = pop32();
    fp1 = fp2;
    esi = pop32();

    ebp = pop32();
    memoryFSet32(ds, ecx + 0x4, fp0);
    ebx = pop32();
    esp += 28;
}

void subopt_10066dc0() // 0000:10066dc0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    double _cmp0r, _cmp1r, _cmp2r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x0000001c;
    eax = memoryAGet32(ds, esp + 0x2c);
    edx = eax;
    edx = (int32_t)edx * (int32_t)0x0000004c;
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = (edx + ecx) + 172;
    edx = memoryAGet32(ds, ecx + 0x64);
    eax = memoryAGet32(ds, edx + eax * 4);
    edx = memoryAGet32(ds, ecx + 0x58);
    memoryASet32(ds, esp + 0x18, esi);
    push32(edi);
    fp0 = memoryFGet32(ds, edx);
    memoryASet32(ds, esp + 0x14, ecx);
    fp0 += memoryFGet32(ds, eax);
    memoryASet32(ds, esp + 0x10, 0x00000000);
    esi += 0x00000004;
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    fp3 = memoryFGet32(ds, edx + 0x4);
    fp3 += memoryFGet32(ds, eax + 0x4);
    fp4 = fp3;
    fp4 = fabsf(fp4);
    fp4 += fp0;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 -= fp0;
    fp4 = fabsf(fp4);
    fp3 -= fp4;
    fp3 *= fp2;
    fp4 = memoryFGet32(ds, edx + 0x8);
    fp4 += memoryFGet32(ds, eax + 0x8);
    fp5 = fp4;
    fp5 = fabsf(fp5);
    fp5 += fp0;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp0;
    fp5 = fabsf(fp5);
    fp4 -= fp5;
    fp4 *= fp2;
    memoryFSet32(ds, esp + 0x3c, fp4);
    fp4 = fp1;
    fp4 *= fp1;
    memoryFSet32(ds, esp + 0x18, fp4);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp3 *= 0.20000000298023224f;
    fp3 += 0.800000011920929f;
    fp1 *= fp3;
    fp3 = 1.0499999523162842f;
    fp1 = fp3 - fp1;
    fp3 = (double)(int32_t)memoryAGet32(ds, esp + 0x38);
    memoryFSet32(ds, esp + 0x20, fp3);
    fp3 = 0.0f;
    fp4 = 1.000000045813705e-18f;
    goto loc_10066e79;
loc_10066e71: // 0000:10066e71
    fp4 = 0.0f;
    ecx = memoryAGet32(ds, esp + 0x14);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
loc_10066e79: // 0000:10066e79
    fp5 = 44100.0f;
    eax = memoryAGet32(ds, esp + 0x30);
    fp5 /= memoryFGet32(ds, ecx + 0x70);
    edx = memoryAGet32(ds, esp + 0x10);
    edi = memoryAGet32(ds, eax + edx * 4);
    eax = memoryAGet32(ds, ecx + 0x4cac);
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    ebx = memoryAGet32(ds, esp + 0x38);
    fp5 *= memoryFGet32(ds, esp + 0x18);
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 += fp0;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 -= fp0;
    fp6 = fabsf(fp6);
    fp5 -= fp6;
    ebp = eax;
    fp5 *= fp2;
    eax = memoryAGet32(ds, esp + 0x1c);
    ecx = edx;
    fp5 += 9.999999960041972e-13f;
    memoryFSet32(ds, esp + 0x28, fp5);
    fp6 = fp5;
    fp6 -= fp2;
    fp7 = fp6;
    fp7 = fabsf(fp7);
    fp6 += fp7;
    fp6 *= fp2;
    fp6 = fp5 - fp6;
    fp6 += fp6;
    fp6 = fp0 - fp6;
    fp6 *= memoryFGet32(ds, esp + 0x3c);
    if (memoryAGet(ds, eax + 0x48))
        goto loc_10066eef;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryASet(ds, eax + 0x48, 0x01);
    memoryFSet32(ds, eax + 0x44, fp6);
    memoryFSet32(ds, eax + 0x20, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
loc_10066eef: // 0000:10066eef
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4cac);
    eax = 0x55555556;
    imul32(edx);
    eax = edx;
    eax >>= 31;
    eax += edx;
    edx = (esi + (eax * 4)) + -4;
    if (eax != 0x00000003)
        goto loc_10066f13;
    edx = esi + 4;
loc_10066f13: // 0000:10066f13
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    eax = ecx;
    eax -= 0x00000000;
    fp6 -= memoryFGet32(ds, esi + 0x1c);
    fp6 /= memoryFGet32(ds, esp + 0x20);
    if (!eax)
        goto loc_10067193;
    eax--;
    if (!eax)
        goto loc_100670b2;
    eax--;
    if (eax)
        goto loc_10067270;
    { double _xchg = fp6; fp6 = fp3; fp3 = _xchg; }
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esp + 0x3c));

    if (fp6 >= _cmp0r)  // fp6 vs (double)fromFp32(memoryAGet32(ds, esp + 0x3c))
        goto loc_10067001;
    if (!ebx)
        goto loc_10067279;
    fp2 = fp5;
    eax = (esi + (ebp * 4)) + 12;
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    fp4 -= fp2;
loc_10066f5c: // 0000:10066f5c
    fp5 = memoryFGet32(ds, esi);
    ebx--;
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    edi += 0x00000004;
    fp5 += fp0;
    fp5 = memoryFGet32(ds, esi + 0x4) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x4, fp6);
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp6 += fp4;
    fp6 *= fp5;
    fp6 += fp0;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp0;
    fp6 = memoryFGet32(ds, esi - 4) - fp6;
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, edi - 4);
    fp5 = fp6 - fp5;
    fp5 += fp0;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, esi + 0x10);
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    fp5 += fp0;
    fp5 = memoryFGet32(ds, esi + 0x14) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x14, fp6);
    fp6 = memoryFGet32(ds, esi + 0x4);
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp6 += fp4;
    fp6 *= fp5;
    fp6 += fp0;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp0;
    fp6 = memoryFGet32(ds, esi + 0xc) - fp6;
    memoryFSet32(ds, esi + 0xc, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= 1.0499999523162842f;
    fp6 += memoryFGet32(ds, edx);
    fp5 = fp6 - fp5;
    memoryFSet32(ds, esi + 0x10, fp5);
    fp5 = memoryFGet32(ds, edi - 4);
    fp5 -= memoryFGet32(ds, esi + 0x14);
    memoryFSet32(ds, esi + 0x18, fp5);
    fp5 = memoryFGet32(ds, eax);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_10066f5c;
loc_10066fec: // 0000:10066fec
    fp2 = fp4;


    fp2 = 0.5f;
    fp3 = 1.0f;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    goto loc_10067084;
loc_10067001: // 0000:10067001

    if (!ebx)
        goto loc_10067082;
    eax = (esi + (ebp * 4)) + 12;
loc_1006700b: // 0000:1006700b
    fp5 = memoryFGet32(ds, esi);
    ebx--;
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    edi += 0x00000004;
    fp5 += fp4;
    fp5 = memoryFGet32(ds, esi + 0x4) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x4, fp6);
    fp6 = fp5;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 = memoryFGet32(ds, esi - 4) - fp6;
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, edi - 4);
    fp5 = fp6 - fp5;
    fp5 += fp4;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, esi + 0x10);
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    fp5 += fp4;
    fp5 = memoryFGet32(ds, esi + 0x14) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x14, fp6);
    fp6 = fp5;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 = memoryFGet32(ds, esi + 0xc) - fp6;
    memoryFSet32(ds, esi + 0xc, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= 1.0499999523162842f;
    fp6 += memoryFGet32(ds, edx);
    fp5 = fp6 - fp5;
    memoryFSet32(ds, esi + 0x10, fp5);
    fp5 = memoryFGet32(ds, edi - 4);
    fp5 -= memoryFGet32(ds, esi + 0x14);
    memoryFSet32(ds, esi + 0x18, fp5);
    fp5 = memoryFGet32(ds, eax);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_1006700b;
loc_10067082: // 0000:10067082
    fp3 = fp4;
loc_10067084: // 0000:10067084
    eax = memoryAGet32(ds, esp + 0x10);
    fp4 = memoryFGet32(ds, esp + 0x28);
    eax++;
    memoryFSet32(ds, esi + 0x1c, fp4);
    esi += 0x00000024;
    memoryASet32(ds, esp + 0x10, eax);
    if ((int32_t)eax < (int32_t)0x00000002)
        goto loc_10066e71;

    edi = pop32();
    fp0 = fp2;
    esi = pop32();

    ebp = pop32();

    ebx = pop32();
    esp += 0x0000001c;
    esp += 20; return;
loc_100670b2: // 0000:100670b2
    { double _xchg = fp6; fp6 = fp3; fp3 = _xchg; }
    _cmp1r = (double)fromFp32(memoryAGet32(ds, esp + 0x3c));

    if (fp6 >= _cmp1r)  // fp6 vs (double)fromFp32(memoryAGet32(ds, esp + 0x3c))
        goto loc_10067139;
    if (!ebx)
        goto loc_10067279;
    fp2 = fp5;
    fp5 = fp0;
    fp5 -= fp2;
    memoryFSet32(ds, esp + 0x24, fp5);
loc_100670d1: // 0000:100670d1
    fp5 = memoryFGet32(ds, esi);
    ebx--;
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    edi += 0x00000004;
    fp5 += fp4;
    fp5 = memoryFGet32(ds, esi + 0x4) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x4, fp6);
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp6 += memoryFGet32(ds, esp + 0x24);
    fp6 *= fp5;
    fp6 += fp4;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 = memoryFGet32(ds, esi - 4) - fp6;
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, edi - 4);
    fp5 = fp6 - fp5;
    fp5 += fp4;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, edi - 4);
    fp5 -= memoryFGet32(ds, esi + 0x4);
    memoryFSet32(ds, esi + 0x8, fp5);
    fp5 = memoryFGet32(ds, esi + ebp * 4 - 4);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_100670d1;
    fp2 = fp4;

    fp3 = 0.5f;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    goto loc_10067084;
loc_10067139: // 0000:10067139

    if (!ebx)
        goto loc_10067082;
loc_10067143: // 0000:10067143
    fp5 = memoryFGet32(ds, esi);
    ebx--;
    fp5 *= memoryFGet32(ds, esi + 0x1c);
    edi += 0x00000004;
    fp5 += fp4;
    fp5 = memoryFGet32(ds, esi + 0x4) - fp5;
    fp6 = fp5;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    memoryFSet32(ds, esi + 0x4, fp6);
    fp6 = fp5;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 = memoryFGet32(ds, esi - 4) - fp6;
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, edi - 4);
    fp5 = fp6 - fp5;
    fp5 += fp4;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, edi - 4);
    fp5 -= memoryFGet32(ds, esi + 0x4);
    memoryFSet32(ds, esi + 0x8, fp5);
    fp5 = memoryFGet32(ds, esi + ebp * 4 - 4);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_10067143;
    goto loc_10067082;
loc_10067193: // 0000:10067193
    { double _xchg = fp6; fp6 = fp3; fp3 = _xchg; }
    _cmp2r = (double)fromFp32(memoryAGet32(ds, esp + 0x3c));

    if (fp6 >= _cmp2r)  // fp6 vs (double)fromFp32(memoryAGet32(ds, esp + 0x3c))
        goto loc_10067215;
    if (!ebx)
        goto loc_10067279;
    fp2 = fp5;
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    fp4 -= fp2;
loc_100671ae: // 0000:100671ae
    fp5 = memoryFGet32(ds, edi);
    ebx--;
    fp5 -= memoryFGet32(ds, esi - 4);
    edi += 0x00000004;
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp6 += fp4;
    fp6 *= fp5;
    fp6 += fp0;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp0;
    fp6 += memoryFGet32(ds, esi - 4);
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 -= memoryFGet32(ds, esi + 0xc);
    fp7 = fp6;
    fp7 = fabsf(fp7);
    fp7 *= fp2;
    fp7 += fp4;
    fp6 *= fp7;
    fp6 += fp0;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp0;
    fp6 += memoryFGet32(ds, esi + 0xc);
    memoryFSet32(ds, esi + 0xc, fp6);
    fp5 = memoryFGet32(ds, edi - 4) - fp5;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, esi + 0xc);
    fp5 += fp5;
    memoryFSet32(ds, esi + 0x4, fp5);
    fp5 = memoryFGet32(ds, edi - 4) - fp5;
    memoryFSet32(ds, esi + 0x8, fp5);
    fp5 = memoryFGet32(ds, esi + ebp * 4 - 4);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_100671ae;
    goto loc_10066fec;
loc_10067215: // 0000:10067215

    if (!ebx)
        goto loc_10067082;
loc_1006721f: // 0000:1006721f
    fp5 = memoryFGet32(ds, edi);
    ebx--;
    fp5 -= memoryFGet32(ds, esi - 4);
    edi += 0x00000004;
    fp6 = fp5;
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 += memoryFGet32(ds, esi - 4);
    memoryFSet32(ds, esi - 4, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 -= memoryFGet32(ds, esi + 0xc);
    fp6 *= memoryFGet32(ds, esi + 0x1c);
    fp6 += fp4;
    fp6 += memoryFGet32(ds, esi + 0xc);
    memoryFSet32(ds, esi + 0xc, fp6);
    fp5 = memoryFGet32(ds, edi - 4) - fp5;
    memoryFSet32(ds, esi, fp5);
    fp5 = memoryFGet32(ds, esi + 0xc);
    fp5 += fp5;
    memoryFSet32(ds, esi + 0x4, fp5);
    fp5 = memoryFGet32(ds, edi - 4) - fp5;
    memoryFSet32(ds, esi + 0x8, fp5);
    fp5 = memoryFGet32(ds, esi + ebp * 4 - 4);
    memoryFSet32(ds, edi - 4, fp5);
    fp5 = fp3;
    fp5 += memoryFGet32(ds, esi + 0x1c);
    memoryFSet32(ds, esi + 0x1c, fp5);
    if (ebx)
        goto loc_1006721f;
    goto loc_10067082;
loc_10067270: // 0000:10067270
    fp5 = fp6;
    fp3 = fp5;
    goto loc_10067082;
loc_10067279: // 0000:10067279

    goto loc_10067082;
}

void subopt_10065830() // 0000:10065830 +long +stackDrop4
{
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax <<= 4;
    edx = 0;
    dl = memoryAGet32(ds, eax + ecx + 0xb8) != edx;
    al = dl;
    esp += 8;
}

void subopt_100678c0() // 0000:100678c0 +long +stackDrop4
{
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (!eax)
        goto loc_10067918;
    edx = memoryAGet32(ds, ecx + 0xde54);
    if (!edx)
        goto loc_10067918;
    edx = memoryAGet32(ds, ecx + 0xde50);
    push32(esi);
    esi = memoryAGet32(ds, ecx + 0xde5c);
    memoryASet32(ds, esi + edx * 4, eax);
    memoryASet32(ds, ecx + 0xde50, memoryAGet32(ds, ecx + 0xde50) + 1);
    memoryASet32(ds, ecx + 0xde54, memoryAGet32(ds, ecx + 0xde54) - 1);
    eax = memoryAGet32(ds, eax);
    edx = memoryAGet32(ds, ecx + 0xde54);
    if ((int32_t)edx <= (int32_t)eax)
        goto loc_10067917;
    edx = memoryAGet32(ds, ecx + 0xde60);
    esi = memoryAGet32(ds, ecx + 0xde54);
    esi = memoryAGet32(ds, edx + esi * 4);
    memoryASet32(ds, edx + eax * 4, esi);
    ecx = memoryAGet32(ds, ecx + 0xde60);
    edx = memoryAGet32(ds, ecx + eax * 4);
    memoryASet32(ds, edx, eax);
loc_10067917: // 0000:10067917
    esi = pop32();
loc_10067918: // 0000:10067918
    esp += 8; return;
}

void subopt_100646d0() // 0000:100646d0 +long +stackDrop16
{
    double fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    StackGuard _sg(16, __FUNCTION__);
    bool temp_cond0;
    bool temp_cond1;
    bool temp_cond2;
    esp -= 4;
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:100646d8");
    }
    // subopt_10007230 sets AL!
    if (!al)
        goto loc_100649c5;
    fp0 = 1.0f;
    eax = memoryAGet32(ds, esp + 0xc);
    fp0 /= memoryFGet32(ds, esi + 0x70);
    edx = memoryAGet32(ds, eax);
    push32(ebx);
    ebx = memoryAGet32(ds, eax + 0x4);
    eax = memoryAGet32(ds, esp + 0xc);
    push32(ebp);
    ebp = memoryAGet32(ds, eax + 0x4);
    push32(edi);
    edi = memoryAGet32(ds, eax);
    fp1 = memoryFGet32(ds, esi + 0xac);
    fp1 *= 7900.0f;
    fp1 += 100.0f;
    fp0 *= fp1;
    fp0 *= 3.1415927410125732f;
    fp0 *= 0.15915493667125702f;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esp + 0x14);
    memoryASet32(ds, esp + 0x18, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    eax = memoryAGet32(ds, esp + 0x1c);
    ecx = eax;
    fp0 = memoryFGet32(ds, esp + 0x14) - fp0;
    fp0 *= 6.2831854820251465f;
    fp0 -= 3.1415927410125732f;
    fp1 = fp0;
    fp1 *= fp0;
    fp2 = -2.3900000201138027e-08f;
    fp2 *= fp1;
    fp2 += 2.7526000394573202e-06f;
    fp2 *= fp1;
    fp2 -= 0.00019840900495182723f;
    fp2 *= fp1;
    fp2 += 0.008333331905305386f;
    fp2 *= fp1;
    fp2 -= 0.1666666716337204f;
    fp1 *= fp2;
    fp1 += 1.0f;
    fp0 *= fp1;
    fp0 = -fp0;
    fp0 += fp0;
    fp1 = memoryFGet32(ds, esi + 0xb0);
    fp2 = 1.4426950408889634;
    fp1 *= fp2;
    fp2 = fp1;
    frndint();
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 -= fp1;
    f2xm1();
    fp3 = 1.0f;
    fp2 += fp3;
    fscale();
    fp1 = fp2;
    fp2 = 0.6000000238418579f;
    fp1 *= fp2;
    fp3 = memoryFGet32(ds, esi + 0xb4);
    fp4 = 1.4426950408889634;
    fp3 *= fp4;
    fp4 = fp3;
    frndint();
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 -= fp3;
    f2xm1();
    fp5 = 1.0f;
    fp4 += fp5;
    fscale();
    fp3 = fp4;
    fp3 *= fp2;
    fp4 = memoryFGet32(ds, esi + 0xb8);
    fp5 = 1.4426950408889634;
    fp4 *= fp5;
    fp5 = fp4;
    frndint();
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp4;
    f2xm1();
    fp6 = 1.0f;
    fp5 += fp6;
    fscale();
    fp4 = fp5;
    fp4 *= fp2;
    fp5 = 1.000000045813705e-18f;
    if (!eax)
        goto loc_100648a0;
    fp2 = fp5;
loc_100647ea: // 0000:100647ea
    fp5 = memoryFGet32(ds, edx);
    ecx--;
    fp5 += fp2;
    edx += 0x00000004;
    fp6 = memoryFGet32(ds, esi + 0xd8);
    edi += 0x00000004;
    fp6 *= fp0;
    fp6 += memoryFGet32(ds, esi + 0xd4);
    memoryFSet32(ds, esi + 0xd4, fp6);
    fp5 -= fp6;
    fp5 -= memoryFGet32(ds, esi + 0xd8);
    memoryFSet32(ds, esi + 0xdc, fp5);
    fp5 *= fp0;
    fp5 += memoryFGet32(ds, esi + 0xd8);
    fp5 += fp2;
    memoryFSet32(ds, esi + 0xd8, fp5);
    fp6 = fp0;
    fp6 *= memoryFGet32(ds, esi + 0xe4);
    fp6 += memoryFGet32(ds, esi + 0xe0);
    memoryFSet32(ds, esi + 0xe0, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp3;
    fp7 = memoryFGet32(ds, esi + 0xd4);
    fp7 *= fp1;
    fp6 += fp7;
    fp7 = fp4;
    fp7 *= memoryFGet32(ds, esi + 0xdc);
    fp6 += fp7;
    fp5 = fp6 - fp5;
    fp5 -= memoryFGet32(ds, esi + 0xe4);
    memoryFSet32(ds, esi + 0xe8, fp5);
    fp5 *= fp0;
    fp5 += memoryFGet32(ds, esi + 0xe4);
    fp5 += fp2;
    memoryFSet32(ds, esi + 0xe4, fp5);
    fp5 *= fp3;
    fp6 = fp4;
    fp6 *= memoryFGet32(ds, esi + 0xe8);
    fp5 += fp6;
    fp6 = fp1;
    fp6 *= memoryFGet32(ds, esi + 0xe0);
    fp5 += fp6;
    memoryFSet32(ds, edi - 4, fp5);
    if (ecx)
        goto loc_100647ea;

    fp1 = fp3;
    fp1 = fp2;
    fp2 = 0.6000000238418579f;
    goto loc_100648a6;
loc_100648a0: // 0000:100648a0
    fp4 = fp5;
    fp1 = fp4;

loc_100648a6: // 0000:100648a6
    if (!ebx)
        goto loc_100649c9;
    fp3 = memoryFGet32(ds, esi + 0xbc);
    fp4 = 1.4426950408889634;
    fp3 *= fp4;
    fp4 = fp3;
    frndint();
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 -= fp3;
    f2xm1();
    fp5 = 1.0f;
    fp4 += fp5;
    fscale();
    fp3 = fp4;
    fp3 *= fp2;
    fp4 = memoryFGet32(ds, esi + 0xc0);
    fp5 = 1.4426950408889634;
    fp4 *= fp5;
    fp5 = fp4;
    frndint();
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 -= fp4;
    f2xm1();
    fp6 = 1.0f;
    fp5 += fp6;
    fscale();
    fp4 = fp5;
    fp4 *= fp2;
    fp5 = memoryFGet32(ds, esi + 0xc4);
    fp6 = 1.4426950408889634;
    fp5 *= fp6;
    fp6 = fp5;
    frndint();
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 -= fp5;
    f2xm1();
    fp7 = 1.0f;
    fp6 += fp7;
    fscale();
    fp5 = fp6;
    fp2 *= fp5;
    if (!eax)
        goto loc_100649b8;
loc_10064910: // 0000:10064910
    fp5 = memoryFGet32(ds, ebx);
    eax--;
    fp5 += fp1;
    ebx += 0x00000004;
    fp6 = memoryFGet32(ds, esi + 0xf0);
    ebp += 0x00000004;
    fp6 *= fp0;
    fp6 += memoryFGet32(ds, esi + 0xec);
    memoryFSet32(ds, esi + 0xec, fp6);
    fp5 -= fp6;
    fp5 -= memoryFGet32(ds, esi + 0xf0);
    memoryFSet32(ds, esi + 0xf4, fp5);
    fp5 *= fp0;
    fp5 += memoryFGet32(ds, esi + 0xf0);
    fp5 += fp1;
    memoryFSet32(ds, esi + 0xf0, fp5);
    fp6 = memoryFGet32(ds, esi + 0xfc);
    fp6 *= fp0;
    fp6 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp6);
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= fp4;
    fp7 = memoryFGet32(ds, esi + 0xec);
    fp7 *= fp3;
    fp6 += fp7;
    fp7 = memoryFGet32(ds, esi + 0xf4);
    fp7 *= fp2;
    fp6 += fp7;
    fp5 = fp6 - fp5;
    fp5 -= memoryFGet32(ds, esi + 0xfc);
    memoryFSet32(ds, esi + 0x100, fp5);
    fp5 *= fp0;
    fp5 += memoryFGet32(ds, esi + 0xfc);
    fp5 += fp1;
    memoryFSet32(ds, esi + 0xfc, fp5);
    fp5 *= fp4;
    fp6 = memoryFGet32(ds, esi + 0x100);
    fp6 *= fp2;
    fp5 += fp6;
    fp6 = memoryFGet32(ds, esi + 0xf8);
    fp6 *= fp3;
    fp5 += fp6;
    memoryFSet32(ss, ebp - 4, fp5);
    if (eax)
        goto loc_10064910;
loc_100649b8: // 0000:100649b8
    fp2 = fp4;
    edi = pop32();
    fp0 = fp3;
    ebp = pop32();
    fp1 = fp2;
    ebx = pop32();
    fp0 = fp1;

loc_100649c5: // 0000:100649c5
    esi = pop32();
    esp += 20; return;
loc_100649c9: // 0000:100649c9
    edi = pop32();
    fp0 = fp2;
    ebp = pop32();

    ebx = pop32();

    esi = pop32();
    esp += 20;
}

void subopt_10007230() // 0000:10007230 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    al = memoryAGet(ds, ecx + 0x8d);
    esp += 4;
}

void subopt_10059ed0() // 0000:10059ed0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x0000000c;
    push32(esi);
    esi = ecx;
    fp0 = memoryFGet32(ds, esi + 0xac);
    memoryASet32(ds, esp + 0x8, esi);
    memoryFSet32(ds, esp + 0xc, fp0);
    fp0 = memoryFGet32(ds, esp + 0xc);
    memoryASet32(ds, esp + 0x4, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:10059ef1");
    }
    if (!al)
        goto loc_1005a385;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax = 0x00000001;
    eax <<= cl;
    eax--;
    if (!(memoryAGet32(ds, esi + 0x498) & eax))
        goto loc_1005a385;
    eax = memoryAGet32(ds, esp + 0x18);
    fp0 = 1.000000045813705e-18f;
    edx = memoryAGet32(ds, eax + 0x4);
    fp1 = memoryFGet32(ds, esp + 0x1c);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x20);
    push32(ebp);
    push32(edi);
    edi = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, esp + 0x20);
    ebp = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, eax + 0x4);
    memoryASet32(ds, esp + 0x24, edx);
    memoryASet32(ds, esp + 0x20, eax);
    if (!ebx)
        goto loc_1005a150;
loc_10059f46: // 0000:10059f46
    fp2 = memoryFGet32(ds, edi);
    eax = esi + 376;
    ebx--;
    fp2 += fp0;
    edi += 0x00000004;
    esi = 0;
    if ((int32_t)ecx < (int32_t)0x00000004)
        goto loc_1005a0e6;
    edx = ecx - 4;
    edx >>= 2;
    edx++;
    esi = (edx * 4) + 0;
loc_10059f6d: // 0000:10059f6d
    if (!memoryAGet(ds, eax))
        goto loc_10059faf;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x8);
    fp2 *= memoryFGet32(ds, eax + 0x18);
    fp3 = memoryFGet32(ds, eax + 0x4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xc);
    fp3 *= memoryFGet32(ds, eax + 0x1c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x10);
    fp3 *= memoryFGet32(ds, eax + 0x20);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x14);
    fp3 *= memoryFGet32(ds, eax + 0x24);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x18);
    memoryFSet32(ds, eax + 0x1c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x18, fp2);
    fp2 = memoryFGet32(ds, eax + 0x20);
    memoryFSet32(ds, eax + 0x24, fp2);
    memoryFSet32(ds, eax + 0x20, fp1);
    fp2 = fp1;
loc_10059faf: // 0000:10059faf
    if (!memoryAGet(ds, eax + 0x50))
        goto loc_10059ff2;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x58);
    fp2 *= memoryFGet32(ds, eax + 0x68);
    fp3 = memoryFGet32(ds, eax + 0x54);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x5c);
    fp3 *= memoryFGet32(ds, eax + 0x6c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x60);
    fp3 *= memoryFGet32(ds, eax + 0x70);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x64);
    fp3 *= memoryFGet32(ds, eax + 0x74);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x68);
    memoryFSet32(ds, eax + 0x6c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x68, fp2);
    fp2 = memoryFGet32(ds, eax + 0x70);
    memoryFSet32(ds, eax + 0x74, fp2);
    memoryFSet32(ds, eax + 0x70, fp1);
    fp2 = fp1;
loc_10059ff2: // 0000:10059ff2
    if (!memoryAGet(ds, eax + 0xa0))
        goto loc_1005a065;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0xa8);
    fp2 *= memoryFGet32(ds, eax + 0xb8);
    fp3 = memoryFGet32(ds, eax + 0xa4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xac);
    fp3 *= memoryFGet32(ds, eax + 0xbc);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xb0);
    fp3 *= memoryFGet32(ds, eax + 0xc0);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0xb4);
    fp3 *= memoryFGet32(ds, eax + 0xc4);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0xb8);
    memoryFSet32(ds, eax + 0xbc, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0xb8, fp2);
    fp2 = memoryFGet32(ds, eax + 0xc0);
    memoryFSet32(ds, eax + 0xc4, fp2);
    memoryFSet32(ds, eax + 0xc0, fp1);
    fp2 = fp1;
loc_1005a065: // 0000:1005a065
    if (!memoryAGet(ds, eax + 0xf0))
        goto loc_1005a0d8;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0xf8);
    fp2 *= memoryFGet32(ds, eax + 0x108);
    fp3 = memoryFGet32(ds, eax + 0xf4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xfc);
    fp3 *= memoryFGet32(ds, eax + 0x10c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x100);
    fp3 *= memoryFGet32(ds, eax + 0x110);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x104);
    fp3 *= memoryFGet32(ds, eax + 0x114);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x108);
    memoryFSet32(ds, eax + 0x10c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x108, fp2);
    fp2 = memoryFGet32(ds, eax + 0x110);
    memoryFSet32(ds, eax + 0x114, fp2);
    memoryFSet32(ds, eax + 0x110, fp1);
    fp2 = fp1;
loc_1005a0d8: // 0000:1005a0d8
    eax += 0x00000140;
    edx--;
    if (edx)
        goto loc_10059f6d;
loc_1005a0e6: // 0000:1005a0e6
    if ((int32_t)esi >= (int32_t)ecx)
        goto loc_1005a138;
    edx = ecx;
    edx -= esi;
loc_1005a0ee: // 0000:1005a0ee
    if (!memoryAGet(ds, eax))
        goto loc_1005a130;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x8);
    fp2 *= memoryFGet32(ds, eax + 0x18);
    fp3 = memoryFGet32(ds, eax + 0x4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xc);
    fp3 *= memoryFGet32(ds, eax + 0x1c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x10);
    fp3 *= memoryFGet32(ds, eax + 0x20);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x14);
    fp3 *= memoryFGet32(ds, eax + 0x24);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x18);
    memoryFSet32(ds, eax + 0x1c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x18, fp2);
    fp2 = memoryFGet32(ds, eax + 0x20);
    memoryFSet32(ds, eax + 0x24, fp2);
    memoryFSet32(ds, eax + 0x20, fp1);
    fp2 = fp1;
loc_1005a130: // 0000:1005a130
    eax += 0x00000050;
    edx--;
    if (edx)
        goto loc_1005a0ee;
loc_1005a138: // 0000:1005a138
    esi = memoryAGet32(ds, esp + 0x14);

    memoryFSet32(ss, ebp, fp1);
    ebp += 0x00000004;
    if (ebx)
        goto loc_10059f46;
    ebx = memoryAGet32(ds, esp + 0x28);
loc_1005a150: // 0000:1005a150
    if (!memoryAGet32(ds, esp + 0x24))
        goto loc_1005a37e;
    if (!ebx)
        goto loc_1005a37e;
    edi = esi + 416;
loc_1005a169: // 0000:1005a169
    eax = memoryAGet32(ds, esp + 0x24);
    fp2 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    ebx--;
    fp2 += fp0;
    esi = 0;
    memoryASet32(ds, esp + 0x24, eax);
    memoryASet32(ds, esp + 0x28, ebx);
    eax = edi;
    if ((int32_t)ecx < (int32_t)0x00000004)
        goto loc_1005a311;
    edx = ecx - 4;
    edx >>= 2;
    edx++;
    esi = (edx * 4) + 0;
loc_1005a198: // 0000:1005a198
    if (!memoryAGet(ds, eax))
        goto loc_1005a1da;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x8);
    fp2 *= memoryFGet32(ds, eax + 0x18);
    fp3 = memoryFGet32(ds, eax + 0x4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xc);
    fp3 *= memoryFGet32(ds, eax + 0x1c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x10);
    fp3 *= memoryFGet32(ds, eax + 0x20);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x14);
    fp3 *= memoryFGet32(ds, eax + 0x24);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x18);
    memoryFSet32(ds, eax + 0x1c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x18, fp2);
    fp2 = memoryFGet32(ds, eax + 0x20);
    memoryFSet32(ds, eax + 0x24, fp2);
    memoryFSet32(ds, eax + 0x20, fp1);
    fp2 = fp1;
loc_1005a1da: // 0000:1005a1da
    if (!memoryAGet(ds, eax + 0x50))
        goto loc_1005a21d;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x58);
    fp2 *= memoryFGet32(ds, eax + 0x68);
    fp3 = memoryFGet32(ds, eax + 0x54);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x5c);
    fp3 *= memoryFGet32(ds, eax + 0x6c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x60);
    fp3 *= memoryFGet32(ds, eax + 0x70);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x64);
    fp3 *= memoryFGet32(ds, eax + 0x74);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x68);
    memoryFSet32(ds, eax + 0x6c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x68, fp2);
    fp2 = memoryFGet32(ds, eax + 0x70);
    memoryFSet32(ds, eax + 0x74, fp2);
    memoryFSet32(ds, eax + 0x70, fp1);
    fp2 = fp1;
loc_1005a21d: // 0000:1005a21d
    if (!memoryAGet(ds, eax + 0xa0))
        goto loc_1005a290;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0xa8);
    fp2 *= memoryFGet32(ds, eax + 0xb8);
    fp3 = memoryFGet32(ds, eax + 0xa4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xac);
    fp3 *= memoryFGet32(ds, eax + 0xbc);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xb0);
    fp3 *= memoryFGet32(ds, eax + 0xc0);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0xb4);
    fp3 *= memoryFGet32(ds, eax + 0xc4);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0xb8);
    memoryFSet32(ds, eax + 0xbc, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0xb8, fp2);
    fp2 = memoryFGet32(ds, eax + 0xc0);
    memoryFSet32(ds, eax + 0xc4, fp2);
    memoryFSet32(ds, eax + 0xc0, fp1);
    fp2 = fp1;
loc_1005a290: // 0000:1005a290
    if (!memoryAGet(ds, eax + 0xf0))
        goto loc_1005a303;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0xf8);
    fp2 *= memoryFGet32(ds, eax + 0x108);
    fp3 = memoryFGet32(ds, eax + 0xf4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xfc);
    fp3 *= memoryFGet32(ds, eax + 0x10c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x100);
    fp3 *= memoryFGet32(ds, eax + 0x110);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x104);
    fp3 *= memoryFGet32(ds, eax + 0x114);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x108);
    memoryFSet32(ds, eax + 0x10c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x108, fp2);
    fp2 = memoryFGet32(ds, eax + 0x110);
    memoryFSet32(ds, eax + 0x114, fp2);
    memoryFSet32(ds, eax + 0x110, fp1);
    fp2 = fp1;
loc_1005a303: // 0000:1005a303
    eax += 0x00000140;
    edx--;
    if (edx)
        goto loc_1005a198;
loc_1005a311: // 0000:1005a311
    if ((int32_t)esi >= (int32_t)ecx)
        goto loc_1005a363;
    edx = ecx;
    edx -= esi;
loc_1005a319: // 0000:1005a319
    if (!memoryAGet(ds, eax))
        goto loc_1005a35b;
    fp1 = fp2;
    fp2 = memoryFGet32(ds, eax + 0x8);
    fp2 *= memoryFGet32(ds, eax + 0x18);
    fp3 = memoryFGet32(ds, eax + 0x4);
    fp3 *= fp1;
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0xc);
    fp3 *= memoryFGet32(ds, eax + 0x1c);
    fp2 += fp3;
    fp3 = memoryFGet32(ds, eax + 0x10);
    fp3 *= memoryFGet32(ds, eax + 0x20);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x14);
    fp3 *= memoryFGet32(ds, eax + 0x24);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, eax + 0x18);
    memoryFSet32(ds, eax + 0x1c, fp3);
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax + 0x18, fp2);
    fp2 = memoryFGet32(ds, eax + 0x20);
    memoryFSet32(ds, eax + 0x24, fp2);
    memoryFSet32(ds, eax + 0x20, fp1);
    fp2 = fp1;
loc_1005a35b: // 0000:1005a35b
    eax += 0x00000050;
    edx--;
    if (edx)
        goto loc_1005a319;
loc_1005a363: // 0000:1005a363
    eax = memoryAGet32(ds, esp + 0x20);

    ebx = memoryAGet32(ds, esp + 0x28);
    memoryFSet32(ds, eax, fp1);
    eax += 0x00000004;
    memoryASet32(ds, esp + 0x20, eax);
    if (ebx)
        goto loc_1005a169;
loc_1005a37e: // 0000:1005a37e
    edi = pop32();

    ebp = pop32();

    ebx = pop32();
loc_1005a385: // 0000:1005a385
    esi = pop32();
    esp += 0x0000000c;
    esp += 20;
}

void subopt_1005d330() // 0000:1005d330 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000054;
    push32(edi);
    edi = ecx;
    eax = memoryAGet32(ds, edi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:1005d33b");
    }
    if (!al)
        goto loc_1005e9e5;
    push32(ebx);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x68);
    edx = memoryAGet32(ss, ebp);
    ebx = memoryAGet32(ss, ebp + 0x4);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x68);
    eax = memoryAGet32(ds, esi);
    ecx = memoryAGet32(ds, esi + 0x4);
    memoryASet32(ds, esp + 0x10, edx);
    memoryASet32(ds, esp + 0x18, ebx);
    memoryASet32(ds, esp + 0x68, eax);
    memoryASet32(ds, esp + 0x6c, ecx);
    if (edx != eax)
        goto loc_1005d37b;
    fp0 = 1.0f;
    fp0 -= memoryFGet32(ds, edi + 0x84);
    fp0 = -fp0;
    goto loc_1005d381;
loc_1005d37b: // 0000:1005d37b
    fp0 = memoryFGet32(ds, edi + 0x84);
loc_1005d381: // 0000:1005d381
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp1 = memoryFGet32(ds, edi + 0x80);
    memoryFSet32(ds, esp + 0x24, fp1);
    fp2 = 330.0f;
    fp2 /= memoryFGet32(ds, edi + 0x70);
    memoryFSet32(ds, esp + 0x28, fp2);
    if (memoryAGet(ds, edi + 0x290))
        goto loc_1005d3bc;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryASet(ds, edi + 0x290, 0x01);
    memoryFSet32(ds, edi + 0x28c, fp1);
    memoryFSet32(ds, edi + 0x288, fp0);
    goto loc_1005d3c0;
loc_1005d3bc: // 0000:1005d3bc
    fp0 = fp1;

loc_1005d3c0: // 0000:1005d3c0
    fp0 = memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, esp + 0x48, fp0);
    fp0 = memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, esp + 0x1c, fp0);
    fp0 = memoryFGet32(ds, edi + 0xac);
    memoryFSet32(ds, esp + 0x4c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x4c);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x44);
    if (eax > 0x00000005)
        goto loc_1005e9e2;
    switch (eax)
    {
        case 0: goto loc_1005d3fa;
        case 1: goto loc_1005d787;
        case 2: goto loc_1005e9e2;
        case 3: goto loc_1005ddd9;
        case 4: goto loc_1005e25f;
        case 5: goto loc_1005e62b;
        default:
            stop("unhandled indirect 0000:1005d3f3");
    }
loc_1005d3fa: // 0000:1005d3fa
    eax = memoryAGet32(ds, esp + 0x70);
    fp0 = 0.5f;
    ecx = memoryAGet32(ds, edi + 0x280);
    fp1 = 1.000000045813705e-18f;
    if (!eax)
        goto loc_1005d42d;
loc_1005d414: // 0000:1005d414
    fp2 = memoryFGet32(ds, ebx);
    eax--;
    fp2 += memoryFGet32(ds, edx);
    ecx += 0x00000004;
    ebx += 0x00000004;
    edx += 0x00000004;
    fp2 *= fp0;
    fp2 += fp1;
    memoryFSet32(ds, ecx - 4, fp2);
    if (eax)
        goto loc_1005d414;
loc_1005d42d: // 0000:1005d42d

    ecx = edi + 228;
    fp1 = memoryFGet32(ds, edi + 0xb4);
    eax = ecx;
    fp2 = memoryFGet32(ds, edi + 0x70);
    eax += 0x00000088;
    fp3 = 0.3333333432674408f;
    fp2 *= fp3;
    fp4 = 1.0f;
    fp5 = fp4;
    fp2 = fp5 / fp2;
    fp5 = fp1;
    fp1 *= fp5;
    fp5 = 0.009999999776482582f;
    fp1 += fp5;
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }
    fp1 *= fp5;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, eax - 80, fp4);
    fp4 = (double)(int32_t)memoryAGet32(ds, eax - 92);
    fp5 = fp4;
    fp5 *= memoryFGet32(ds, edi + 0xb8);
    fp5 *= fp0;
    memoryFSet32(ds, eax - 76, fp5);
    fp5 = memoryFGet32(ds, edi + 0xb0);
    fp6 = 0.49000000953674316f;
    fp5 *= fp6;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 += fp2;
    fp4 *= fp6;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    memoryFSet32(ds, eax - 72, fp5);
    fp5 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, eax - 108, fp5);
    fp5 = memoryFGet32(ds, edi + 0xb4);
    fp6 = memoryFGet32(ds, edi + 0x70);
    fp6 *= fp3;
    fp6 = fp1 / fp6;
    fp7 = fp5;
    fp5 *= fp7;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 += fp2;
    fp5 *= fp6;
    memoryFSet32(ds, eax + 0x38, fp5);
    fp5 = (double)(int32_t)memoryAGet32(ds, eax + 0x2c);
    fp6 = fp5;
    fp6 *= memoryFGet32(ds, edi + 0xb8);
    fp6 *= fp0;
    memoryFSet32(ds, eax + 0x3c, fp6);
    fp6 = memoryFGet32(ds, edi + 0xb0);
    fp6 *= fp4;
    fp6 += fp2;
    fp5 *= fp6;
    memoryFSet32(ds, eax + 0x40, fp5);
    fp5 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, eax + 0x1c, fp5);
    eax = edi + 296;
    fp5 = memoryFGet32(ds, edi + 0xc4);
    eax += 0x00000088;
    fp6 = memoryFGet32(ds, edi + 0x70);
    fp6 *= fp3;
    fp6 = fp1 / fp6;
    fp7 = fp5;
    fp5 *= fp7;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 += fp2;
    fp5 *= fp6;
    memoryFSet32(ds, eax - 80, fp5);
    fp5 = (double)(int32_t)memoryAGet32(ds, eax - 92);
    fp5 *= memoryFGet32(ds, edi + 0xc8);
    fp5 *= fp0;
    memoryFSet32(ds, eax - 76, fp5);
    fp5 = memoryFGet32(ds, edi + 0xc0);
    fp5 *= fp4;
    fp5 += fp2;
    fp5 *= (double)(int32_t)memoryAGet32(ds, eax - 92);
    memoryFSet32(ds, eax - 72, fp5);
    fp5 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, eax - 108, fp5);
    fp5 = memoryFGet32(ds, edi + 0xc4);
    fp6 = memoryFGet32(ds, edi + 0x70);
    fp3 *= fp6;
    memoryASet32(ds, esp + 0x20, esi);
    fp6 = fp1;
    memoryASet32(ds, esp + 0x30, ecx);
    memoryASet32(ds, esp + 0x3c, 0x00000002);
    fp3 = fp6 / fp3;
    fp5 *= fp5;
    fp5 += fp2;
    fp3 *= fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, eax + 0x38, fp4);
    fp4 = (double)(int32_t)memoryAGet32(ds, eax + 0x2c);
    fp4 *= memoryFGet32(ds, edi + 0xc8);
    fp0 *= fp4;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, eax + 0x3c, fp3);
    fp3 = memoryFGet32(ds, edi + 0xc0);
    fp0 *= fp3;
    fp0 += fp2;
    fp2 = (double)(int32_t)memoryAGet32(ds, eax + 0x2c);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, eax + 0x40, fp1);
    fp1 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, eax + 0x1c, fp1);
    eax = ebp;
    fp1 = 2.0f;
    eax -= esi;
    memoryASet32(ds, esp + 0x4c, eax);
loc_1005d58d: // 0000:1005d58d
    esi = memoryAGet32(ds, esp + 0x30);
    memoryASet32(ds, esp + 0x40, 0x00000002);
loc_1005d599: // 0000:1005d599
    eax = memoryAGet32(ds, esp + 0x20);
    fp2 = memoryFGet32(ds, esp + 0x48);
    edx = memoryAGet32(ds, esp + 0x4c);
    ecx = memoryAGet32(ds, edx + eax);
    ebp = memoryAGet32(ds, eax);
    memoryFSet32(ds, edi + 0x288, fp2);
    eax = memoryAGet32(ds, esp + 0x70);
    fp2 = memoryFGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, edi + 0x280);
    memoryFSet32(ds, edi + 0x28c, fp2);
    memoryASet32(ds, esp + 0x10, ecx);
    memoryASet32(ds, esp + 0x6c, edx);
    memoryASet32(ds, esp + 0x68, ebp);
    memoryASet32(ds, esp + 0x34, eax);
    if (!eax)
        goto loc_1005d753;
loc_1005d5dc: // 0000:1005d5dc
    eax = memoryAGet32(ds, esp + 0x6c);
    fp2 = memoryFGet32(ds, eax);
    memoryASet32(ds, esp + 0x34, memoryAGet32(ds, esp + 0x34) - 1);
    memoryFSet32(ds, esp + 0x50, fp2);
    fp2 = memoryFGet32(ds, esi + 0x34);
    fp2 *= fp1;
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    fp0 *= memoryFGet32(ds, esi + 0x3c);
    fp0 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esi + 0x38);
    fp0 += memoryFGet32(ds, esi + 0x34);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x18, fp0);
    fp0 = memoryFGet32(ds, esp + 0x18);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x44);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x1c);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x18, fp0);
    fp0 = memoryFGet32(ds, esp + 0x18);
    memoryASet32(ds, esp + 0x38, (int32_t)floor(fp0));
    ecx = memoryAGet32(ds, esp + 0x38);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x38);
    edx = memoryAGet32(ds, esi);
    ebx = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx += ecx;
    fp1 = 1.0f;
    ecx += ecx;
    eax = edx;
    fp2 = fp1;
    eax -= ecx;
    fp0 = fp2 - fp0;
    ecx = eax - 4;
    if (ecx >= ebx)
        goto loc_1005d681;
    ebp = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x68);
loc_1005d681: // 0000:1005d681
    if (eax >= ebx)
        goto loc_1005d68b;
    ebx = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (ebx * 4);
loc_1005d68b: // 0000:1005d68b
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, esi + 0xc, fp3);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, esi + 0x1c);
    fp3 *= fp2;
    fp4 = memoryFGet32(ds, esp + 0x50);
    fp1 += fp4;
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edx, fp2);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005d6e4;
    edx = memoryAGet32(ds, esi + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi, eax);
loc_1005d6e4: // 0000:1005d6e4
    fp2 = memoryFGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, esp + 0x10);
    fp2 -= memoryFGet32(ds, edi + 0x288);
    memoryASet32(ds, esp + 0x6c, memoryAGet32(ds, esp + 0x6c) + 0x00000004);
    fp3 = memoryFGet32(ds, esp + 0x28);
    eax += 0x00000004;
    ebp += 0x00000004;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryASet32(ds, esp + 0x10, eax);
    memoryASet32(ds, esp + 0x68, ebp);
    fp3 += memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, edi + 0x288, fp3);
    fp4 = memoryFGet32(ds, esp + 0x2c);
    fp4 -= memoryFGet32(ds, edi + 0x28c);
    fp2 *= fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp3 += memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, edi + 0x28c, fp3);
    fp3 *= memoryFGet32(ds, eax - 4);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp2 *= fp3;
    fp1 += fp2;
    fp1 += memoryFGet32(ss, ebp - 4);
    memoryFSet32(ss, ebp - 4, fp1);
    fp1 = 2.0f;
    if (memoryAGet32(ds, esp + 0x34))
        goto loc_1005d5dc;
loc_1005d753: // 0000:1005d753
    esi += 0x00000088;
    memoryASet32(ds, esp + 0x40, memoryAGet32(ds, esp + 0x40) - 0x00000001);
    if (memoryAGet32(ds, esp + 0x40))
        goto loc_1005d599;
    memoryASet32(ds, esp + 0x30, memoryAGet32(ds, esp + 0x30) + 0x00000044);
    memoryASet32(ds, esp + 0x20, memoryAGet32(ds, esp + 0x20) + 0x00000004);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 0x00000001);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_1005d58d;
    esi = pop32();

    ebp = pop32();

    ebx = pop32();
    edi = pop32();
    esp += 0x00000054;
    esp += 20; return;
loc_1005d787: // 0000:1005d787
    fp0 = memoryFGet32(ds, edi + 0xb4);
    fp1 = memoryFGet32(ds, edi + 0x70);
    fp1 *= 0.3333333432674408f;
    fp2 = 1.0f;
    fp3 = fp2;
    fp1 = fp3 / fp1;
    fp3 = fp0;
    fp0 *= fp3;
    fp3 = 0.009999999776482582f;
    fp0 += fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 *= fp1;
    memoryFSet32(ds, edi + 0x1a4, fp3);
    memoryFSet32(ds, edi + 0x11c, fp3);
    fp3 = memoryFGet32(ds, edi + 0xc4);
    fp3 *= fp3;
    fp3 += fp0;
    fp1 *= fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x1e8, fp2);
    memoryFSet32(ds, edi + 0x160, fp2);
    fp2 = (double)(int32_t)memoryAGet32(ds, edi + 0x110);
    fp3 = memoryFGet32(ds, edi + 0xb8);
    fp3 *= fp2;
    fp4 = 0.5f;
    fp3 *= fp4;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, edi + 0x1a8, fp4);
    memoryFSet32(ds, edi + 0x120, fp4);
    fp4 = (double)(int32_t)memoryAGet32(ds, edi + 0x154);
    fp5 = memoryFGet32(ds, edi + 0xc8);
    fp5 *= fp4;
    fp3 *= fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, edi + 0x1ec, fp4);
    memoryFSet32(ds, edi + 0x164, fp4);
    fp4 = memoryFGet32(ds, edi + 0xb0);
    fp5 = 0.49000000953674316f;
    fp4 *= fp5;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 += fp0;
    fp2 *= fp5;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x1ac, fp4);
    memoryFSet32(ds, edi + 0x124, fp4);
    fp4 = memoryFGet32(ds, edi + 0xc0);
    fp2 *= fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp0 += fp3;
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edi + 0x1f0, fp1);
    memoryFSet32(ds, edi + 0x168, fp1);
    fp1 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, edi + 0x100, fp1);
    fp1 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, edi + 0x188, fp1);
    fp1 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x144, fp1);
    fp1 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x1cc, fp1);
    if (!memoryAGet32(ds, esp + 0x70))
        goto loc_1005e9e0;
    fp1 = 1.000000045813705e-18f;
    esi = edi + 228;
    ebx = edi + 296;
    ebp = edi + 364;
loc_1005d8a5: // 0000:1005d8a5
    eax = memoryAGet32(ds, esp + 0x10);
    fp2 = 2.0f;
    fp3 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    fp3 += fp1;
    memoryASet32(ds, esp + 0x10, eax);
    eax = memoryAGet32(ds, esp + 0x18);
    memoryASet32(ds, esp + 0x70, memoryAGet32(ds, esp + 0x70) - 1);
    memoryFSet32(ds, esp + 0x14, fp3);
    eax += 0x00000004;
    fp3 = memoryFGet32(ds, eax - 4);
    memoryASet32(ds, esp + 0x18, eax);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x1c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x34);
    fp2 *= fp1;
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esi + 0x3c);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, esi + 0x34);
    fp0 += memoryFGet32(ds, esi + 0x38);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x48, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x38, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x38);
    ecx = memoryAGet32(ds, esp + 0x38);
    eax = memoryAGet32(ds, esi);
    edx = (ecx * 4) + 0;
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    eax -= edx;
    fp1 = 1.0f;
    edx = memoryAGet32(ds, esi + 0x4);
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    memoryASet32(ds, esp + 0x50, eax);
    if (ecx >= edx)
        goto loc_1005d976;
    eax = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (eax * 4);
    eax = memoryAGet32(ds, esp + 0x50);
loc_1005d976: // 0000:1005d976
    if (eax >= edx)
        goto loc_1005d980;
    edx = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (edx * 4);
loc_1005d980: // 0000:1005d980
    fp2 = memoryFGet32(ds, eax);
    eax = memoryAGet32(ds, esi);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, esi + 0xc, fp3);
    fp2 -= fp3;
    memoryFSet32(ds, esp + 0x58, fp2);
    fp3 = memoryFGet32(ds, esp + 0x14);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x54, fp2);
    fp3 = memoryFGet32(ds, esi + 0x1c);
    fp1 *= fp3;
    fp1 += fp2;
    memoryFSet32(ds, eax, fp1);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005d9e3;
    ecx = memoryAGet32(ds, esi + 0x2c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi, eax);
loc_1005d9e3: // 0000:1005d9e3
    fp1 = memoryFGet32(ds, ebx + 0x34);
    fp2 = 2.0f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    fp0 *= memoryFGet32(ds, ebx + 0x3c);
    fp0 += memoryFGet32(ds, ebx + 0x40);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, ebx + 0x34);
    fp0 += memoryFGet32(ds, ebx + 0x38);
    memoryFSet32(ds, ebx + 0x34, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x4c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x4c);
    push32(0x00000000);
    push32(ecx);
    ecx = ebx;
    fp0 = memoryFGet32(ds, ebx + 0x34) - fp0;
    memoryFSet32(ds, ebx + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, ebx + 0x14);
    fp0 -= memoryFGet32(ds, ebx + 0x18);
    fp0 *= memoryFGet32(ds, ebx + 0x20);
    fp0 += memoryFGet32(ds, ebx + 0x18);
    memoryFSet32(ds, ebx + 0x18, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x3c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x3c);
    edx = memoryAGet32(ds, esp + 0x3c);
    eax = memoryAGet32(ds, ebx);
    ecx = (edx * 4) + 0;
    fp0 = memoryFGet32(ds, ebx + 0x18) - fp0;
    eax -= ecx;
    fp1 = 1.0f;
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (ecx >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005da7d;
    edx = memoryAGet32(ds, ebx + 0x2c);
    ecx = ecx + (edx * 4);
loc_1005da7d: // 0000:1005da7d
    if (eax >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005da88;
    edx = memoryAGet32(ds, ebx + 0x2c);
    eax = eax + (edx * 4);
loc_1005da88: // 0000:1005da88
    fp2 = memoryFGet32(ds, eax);
    eax = memoryAGet32(ds, ebx);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, ebx + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, ebx + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ebx + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, ebx + 0xc);
    fp3 *= memoryFGet32(ds, ebx + 0x24);
    fp3 += memoryFGet32(ds, ebx + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, ebx + 0xc, fp3);
    fp2 -= fp3;
    memoryFSet32(ds, esp + 0x60, fp2);
    fp3 = memoryFGet32(ds, esp + 0x1c);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x5c, fp2);
    fp3 = memoryFGet32(ds, ebx + 0x1c);
    fp1 *= fp3;
    fp1 += fp2;
    memoryFSet32(ds, eax, fp1);
    memoryASet32(ds, ebx, memoryAGet32(ds, ebx) + 0x00000004);
    eax = memoryAGet32(ds, ebx);
    if (eax < memoryAGet32(ds, ebx + 0x8))
        goto loc_1005daeb;
    ecx = memoryAGet32(ds, ebx + 0x2c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, ebx, eax);
loc_1005daeb: // 0000:1005daeb
    fp1 = memoryFGet32(ss, ebp + 0x34);
    fp2 = 2.0f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ss, ebp + 0x3c);
    fp0 *= fp1;
    fp0 += memoryFGet32(ss, ebp + 0x40);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ss, ebp + 0x34);
    fp0 += memoryFGet32(ss, ebp + 0x38);
    memoryFSet32(ss, ebp + 0x34, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x30, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x30);
    push32(0x00000000);
    push32(ecx);
    ecx = ebp;
    fp0 = memoryFGet32(ss, ebp + 0x34) - fp0;
    memoryFSet32(ss, ebp + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ss, ebp + 0x14);
    fp0 -= memoryFGet32(ss, ebp + 0x18);
    fp0 *= memoryFGet32(ss, ebp + 0x20);
    fp0 += memoryFGet32(ss, ebp + 0x18);
    memoryFSet32(ss, ebp + 0x18, fp0);
    memoryFSet32(ds, esp + 0x50, fp0);
    fp0 = memoryFGet32(ds, esp + 0x50);
    memoryASet32(ds, esp + 0x40, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    edx = memoryAGet32(ds, esp + 0x40);
    eax = memoryAGet32(ss, ebp);
    ecx = (edx * 4) + 0;
    fp0 = memoryFGet32(ss, ebp + 0x18) - fp0;
    eax -= ecx;
    fp1 = 1.0f;
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (ecx >= memoryAGet32(ss, ebp + 0x4))
        goto loc_1005db88;
    edx = memoryAGet32(ss, ebp + 0x2c);
    ecx = ecx + (edx * 4);
loc_1005db88: // 0000:1005db88
    if (eax >= memoryAGet32(ss, ebp + 0x4))
        goto loc_1005db93;
    edx = memoryAGet32(ss, ebp + 0x2c);
    eax = eax + (edx * 4);
loc_1005db93: // 0000:1005db93
    fp2 = memoryFGet32(ds, eax);
    eax = memoryAGet32(ss, ebp);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ss, ebp + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ss, ebp + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ss, ebp + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ss, ebp + 0xc);
    fp3 *= memoryFGet32(ss, ebp + 0x24);
    fp3 += memoryFGet32(ss, ebp + 0xc);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ss, ebp + 0xc, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ss, ebp + 0x1c);
    fp2 *= fp1;
    fp2 += memoryFGet32(ds, esp + 0x54);
    memoryFSet32(ds, eax, fp2);
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) + 0x00000004);
    eax = memoryAGet32(ss, ebp);
    if (eax < memoryAGet32(ss, ebp + 0x8))
        goto loc_1005dbee;
    ecx = memoryAGet32(ss, ebp + 0x2c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ss, ebp, eax);
loc_1005dbee: // 0000:1005dbee
    fp1 += memoryFGet32(ds, esp + 0x58);
    ecx = edi + 432;
    memoryFSet32(ds, esp + 0x20, fp1);
    fp1 = memoryFGet32(ds, ecx + 0x34);
    fp2 = 2.0f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    fp0 *= memoryFGet32(ds, ecx + 0x3c);
    fp0 += memoryFGet32(ds, ecx + 0x40);
    memoryFSet32(ds, esp + 0x54, fp0);
    fp0 = memoryFGet32(ds, ecx + 0x34);
    fp0 += memoryFGet32(ds, ecx + 0x38);
    memoryFSet32(ds, ecx + 0x34, fp0);
    memoryFSet32(ds, esp + 0x58, fp0);
    fp0 = memoryFGet32(ds, esp + 0x58);
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    push32(0x00000000);
    push32(ecx);
    fp0 = memoryFGet32(ds, ecx + 0x34) - fp0;
    memoryFSet32(ds, ecx + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x5c);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, edi + 0x1c4);
    fp0 -= memoryFGet32(ds, edi + 0x1c8);
    fp0 *= memoryFGet32(ds, edi + 0x1d0);
    fp0 += memoryFGet32(ds, edi + 0x1c8);
    memoryFSet32(ds, edi + 0x1c8, fp0);
    memoryFSet32(ds, esp + 0x58, fp0);
    fp0 = memoryFGet32(ds, esp + 0x58);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x44);
    edx = memoryAGet32(ds, esp + 0x44);
    eax = memoryAGet32(ds, edi + 0x1b0);
    ecx = (edx * 4) + 0;
    fp0 = memoryFGet32(ds, edi + 0x1c8) - fp0;
    eax -= ecx;
    fp1 = 1.0f;
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (ecx >= memoryAGet32(ds, edi + 0x1b4))
        goto loc_1005dcb0;
    edx = memoryAGet32(ds, edi + 0x1dc);
    ecx = ecx + (edx * 4);
loc_1005dcb0: // 0000:1005dcb0
    if (eax >= memoryAGet32(ds, edi + 0x1b4))
        goto loc_1005dcc1;
    edx = memoryAGet32(ds, edi + 0x1dc);
    eax = eax + (edx * 4);
loc_1005dcc1: // 0000:1005dcc1
    fp2 = memoryFGet32(ds, eax);
    eax = memoryAGet32(ds, edi + 0x1b0);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, edi + 0x1c0);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, edi + 0x1d8);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x1c0, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, edi + 0x1bc);
    fp3 *= memoryFGet32(ds, edi + 0x1d4);
    fp3 += memoryFGet32(ds, edi + 0x1bc);
    fp3 += fp1;
    memoryFSet32(ds, edi + 0x1bc, fp3);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, edi + 0x1cc);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, esp + 0x5c);
    memoryFSet32(ds, eax, fp3);
    memoryASet32(ds, edi + 0x1b0, memoryAGet32(ds, edi + 0x1b0) + 0x00000004);
    eax = memoryAGet32(ds, edi + 0x1b0);
    if (eax < memoryAGet32(ds, edi + 0x1b8))
        goto loc_1005dd44;
    ecx = memoryAGet32(ds, edi + 0x1dc);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, edi + 0x1b0, eax);
loc_1005dd44: // 0000:1005dd44
    fp3 = memoryFGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, esp + 0x68);
    fp3 -= memoryFGet32(ds, edi + 0x288);
    eax += 0x00000004;
    fp4 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x68, eax);
    fp3 *= fp4;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 += memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, edi + 0x288, fp4);
    fp5 = memoryFGet32(ds, esp + 0x2c);
    fp5 -= memoryFGet32(ds, edi + 0x28c);
    fp3 *= fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 += memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, edi + 0x28c, fp4);
    fp4 *= memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= memoryFGet32(ds, esp + 0x20);
    fp3 += fp4;
    fp3 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp3);
    eax = memoryAGet32(ds, esp + 0x6c);
    eax += 0x00000004;
    fp2 += memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x6c, eax);
    fp2 *= memoryFGet32(ds, edi + 0x288);
    fp3 = memoryFGet32(ds, edi + 0x28c);
    fp3 *= memoryFGet32(ds, esp + 0x1c);
    fp2 += fp3;
    fp2 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp2);
    if (memoryAGet32(ds, esp + 0x70))
        goto loc_1005d8a5;
    esi = pop32();

    ebp = pop32();

    ebx = pop32();
    edi = pop32();
    esp += 0x00000054;
    esp += 20; return;
loc_1005ddd9: // 0000:1005ddd9
    fp0 = memoryFGet32(ds, edi + 0xb4);
    fp1 = memoryFGet32(ds, edi + 0x70);
    fp1 *= 0.3333333432674408f;
    fp2 = 1.0f;
    fp3 = fp2;
    fp1 = fp3 / fp1;
    fp3 = fp0;
    fp0 *= fp3;
    fp3 = 0.009999999776482582f;
    fp0 += fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 *= fp1;
    memoryFSet32(ds, esp + 0x60, fp3);
    fp3 = memoryFGet32(ds, edi + 0xc4);
    fp3 *= fp3;
    fp3 += fp0;
    fp1 *= fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x54, fp2);
    fp2 = (double)(int32_t)memoryAGet32(ds, edi + 0x110);
    fp3 = memoryFGet32(ds, edi + 0xb8);
    fp3 *= fp2;
    fp4 = 0.5f;
    fp3 *= fp4;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, edi + 0x230, fp4);
    memoryFSet32(ds, edi + 0x1a8, fp4);
    memoryFSet32(ds, edi + 0x120, fp4);
    fp4 = (double)(int32_t)memoryAGet32(ds, edi + 0x154);
    fp5 = memoryFGet32(ds, edi + 0xc8);
    fp5 *= fp4;
    fp5 *= fp3;
    memoryFSet32(ds, edi + 0x274, fp5);
    memoryFSet32(ds, edi + 0x1ec, fp5);
    memoryFSet32(ds, edi + 0x164, fp5);
    fp5 = memoryFGet32(ds, edi + 0xb0);
    fp6 = 0.49000000953674316f;
    fp5 *= fp6;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 += fp0;
    fp2 *= fp6;
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x234, fp5);
    memoryFSet32(ds, edi + 0x1ac, fp5);
    memoryFSet32(ds, edi + 0x124, fp5);
    fp5 = memoryFGet32(ds, edi + 0xc0);
    fp2 *= fp5;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    fp0 += fp4;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp2 *= fp3;
    memoryFSet32(ds, edi + 0x278, fp2);
    memoryFSet32(ds, edi + 0x1f0, fp2);
    memoryFSet32(ds, edi + 0x168, fp2);
    fp2 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, edi + 0x100, fp2);
    fp2 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, edi + 0x188, fp2);
    fp2 = memoryFGet32(ds, edi + 0xbc);
    memoryFSet32(ds, edi + 0x210, fp2);
    fp2 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x144, fp2);
    fp2 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x1cc, fp2);
    fp2 = memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x254, fp2);
    if (!memoryAGet32(ds, esp + 0x70))
        goto loc_1005e9de;
    fp2 = 1.000000045813705e-18f;
    fp3 = 2.0f;
    fp4 = 0.0f;
    goto loc_1005df1f;
loc_1005df0d: // 0000:1005df0d
    fp3 = 0.0f;
    fp4 = 2.0f;
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    { double _xchg = fp4; fp4 = fp0; fp0 = _xchg; }
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
loc_1005df1f: // 0000:1005df1f
    eax = memoryAGet32(ds, esp + 0x10);
    memoryFSet32(ds, esp + 0x4c, fp4);
    memoryFSet32(ds, esp + 0x20, fp4);
    memoryASet32(ds, esp + 0x70, memoryAGet32(ds, esp + 0x70) - 1);
    fp4 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x14, fp4);
    memoryASet32(ds, esp + 0x10, eax);
    eax = memoryAGet32(ds, esp + 0x18);
    fp5 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x1c, fp5);
    memoryASet32(ds, esp + 0x18, eax);
    fp4 += fp5;
    esi = edi + 228;
    memoryASet32(ds, esp + 0x48, 0x00000003);
    fp0 *= fp4;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 += fp2;
    fp4 = fp1;
    memoryFSet32(ds, esp + 0x3c, fp4);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp2 += fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, esp + 0x38, fp3);
    goto loc_1005df85;
loc_1005df75: // 0000:1005df75
    fp3 = fp4;
    fp1 = fp3;

    fp2 = 2.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
loc_1005df85: // 0000:1005df85
    fp2 *= memoryFGet32(ds, esp + 0x60);
    memoryFSet32(ds, esi + 0x38, fp2);
    fp3 = memoryFGet32(ds, esi + 0x34);
    fp3 *= fp0;
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp3 = fp2;
    fp3 = fabsf(fp3);
    fp0 -= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esi + 0x3c);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x58, fp1);
    fp0 += memoryFGet32(ds, esi + 0x34);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x5c);
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x5c);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x44);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x44);
    edx = memoryAGet32(ds, esi);
    ebx = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp2 = fp1;
    ecx = eax - 4;
    fp0 = fp2 - fp0;
    if (ecx >= ebx)
        goto loc_1005e023;
    ebp = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (ebp * 4);
loc_1005e023: // 0000:1005e023
    if (eax >= ebx)
        goto loc_1005e02d;
    ebx = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (ebx * 4);
loc_1005e02d: // 0000:1005e02d
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0xc, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0x1c);
    fp2 *= fp1;
    fp2 += memoryFGet32(ds, esp + 0x38);
    memoryFSet32(ds, edx, fp2);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005e082;
    edx = memoryAGet32(ds, esi + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi, eax);
loc_1005e082: // 0000:1005e082
    fp1 += memoryFGet32(ds, esp + 0x20);
    esi += 0x00000044;
    memoryFSet32(ds, esp + 0x20, fp1);
    fp1 = memoryFGet32(ds, esp + 0x3c);
    fp1 *= memoryFGet32(ds, esp + 0x54);
    memoryFSet32(ds, esi + 0x38, fp1);
    fp2 = memoryFGet32(ds, esi + 0x34);
    fp3 = 2.0f;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp0 = fp3 - fp0;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp3 = fp2;
    fp3 = fabsf(fp3);
    fp0 -= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esi + 0x3c);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x58, fp1);
    fp0 += memoryFGet32(ds, esi + 0x34);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x5c);
    memoryASet32(ds, esp + 0x30, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x30);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x5c);
    memoryASet32(ds, esp + 0x40, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x40);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    edx = memoryAGet32(ds, esi);
    ebx = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp2 = fp1;
    ecx = eax - 4;
    fp0 = fp2 - fp0;
    if (ecx >= ebx)
        goto loc_1005e137;
    ebp = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (ebp * 4);
loc_1005e137: // 0000:1005e137
    if (eax >= ebx)
        goto loc_1005e141;
    ebx = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (ebx * 4);
loc_1005e141: // 0000:1005e141
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, esi + 0xc, fp3);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, esi + 0x1c);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, esp + 0x38);
    memoryFSet32(ds, edx, fp3);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005e194;
    edx = memoryAGet32(ds, esi + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi, eax);
loc_1005e194: // 0000:1005e194
    fp2 += memoryFGet32(ds, esp + 0x4c);
    esi += 0x00000044;
    memoryASet32(ds, esp + 0x48, memoryAGet32(ds, esp + 0x48) - 0x00000001);
    memoryFSet32(ds, esp + 0x4c, fp2);
    fp3 = memoryFGet32(ds, edi + 0xe0);
    fp4 = 0.5f;
    fp3 *= fp4;
    fp5 = fp0;
    fp3 = fp5 - fp3;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= memoryFGet32(ds, esp + 0x3c);
    memoryFSet32(ds, esp + 0x3c, fp4);
    if (memoryAGet32(ds, esp + 0x48))
        goto loc_1005df75;

    eax = memoryAGet32(ds, esp + 0x68);
    fp4 = memoryFGet32(ds, esp + 0x24);
    eax += 0x00000004;
    fp4 -= memoryFGet32(ds, edi + 0x288);
    memoryASet32(ds, esp + 0x68, eax);
    fp5 = memoryFGet32(ds, esp + 0x28);
    fp4 *= fp5;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 += memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, edi + 0x288, fp5);
    fp6 = memoryFGet32(ds, esp + 0x2c);
    fp6 -= memoryFGet32(ds, edi + 0x28c);
    fp4 *= fp6;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 += memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, edi + 0x28c, fp5);
    fp5 *= memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 *= memoryFGet32(ds, esp + 0x20);
    fp4 += fp5;
    fp4 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp4);
    eax = memoryAGet32(ds, esp + 0x6c);
    fp4 = memoryFGet32(ds, edi + 0x288);
    eax += 0x00000004;
    fp2 *= fp4;
    fp4 = memoryFGet32(ds, edi + 0x28c);
    memoryASet32(ds, esp + 0x6c, eax);
    fp4 *= memoryFGet32(ds, esp + 0x1c);
    fp2 += fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp3 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp3);
    if (memoryAGet32(ds, esp + 0x70))
        goto loc_1005df0d;
    esi = pop32();
    fp0 = fp2;
    ebp = pop32();
    fp0 = fp1;
    ebx = pop32();

    edi = pop32();
    esp += 0x00000054;
    esp += 20; return;
loc_1005e25f: // 0000:1005e25f
    fp0 = memoryFGet32(ds, edi + 0xb4);
    fp1 = 1.0f;
    fp2 = fp1;
    fp2 /= memoryFGet32(ds, edi + 0x70);
    fp3 = fp0;
    fp0 *= fp3;
    fp3 = 0.009999999776482582f;
    fp0 += fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 *= fp2;
    memoryFSet32(ds, edi + 0x11c, fp3);
    fp3 = memoryFGet32(ds, edi + 0xc4);
    fp3 *= fp3;
    fp0 += fp3;
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edi + 0x160, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, edi + 0x110);
    fp2 = memoryFGet32(ds, edi + 0xb8);
    fp2 *= fp1;
    fp3 = 0.05000000074505806f;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x1a8, fp3);
    memoryFSet32(ds, edi + 0x120, fp3);
    fp3 = (double)(int32_t)memoryAGet32(ds, edi + 0x154);
    fp4 = memoryFGet32(ds, edi + 0xc8);
    fp4 *= fp3;
    fp2 *= fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x1ec, fp3);
    memoryFSet32(ds, edi + 0x164, fp3);
    fp3 = memoryFGet32(ds, edi + 0xb0);
    fp4 = 0.04500000178813934f;
    fp3 *= fp4;
    fp5 = 0.004999999888241291f;
    fp3 += fp5;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    fp1 *= fp5;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x1ac, fp4);
    memoryFSet32(ds, edi + 0x124, fp4);
    fp4 = memoryFGet32(ds, edi + 0xc0);
    fp1 *= fp4;
    fp1 += fp3;
    fp1 *= fp2;
    memoryFSet32(ds, edi + 0x1f0, fp1);
    memoryFSet32(ds, edi + 0x168, fp1);
    fp1 = memoryFGet32(ds, edi + 0xbc);
    fp2 = -0.8999999761581421f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x100, fp2);
    fp1 *= memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x144, fp1);
    if (!memoryAGet32(ds, esp + 0x70))
        goto loc_1005e9e0;
    fp1 = 1.000000045813705e-18f;
    esi = edi + 228;
    ebx = edi + 296;
loc_1005e357: // 0000:1005e357
    eax = memoryAGet32(ds, esp + 0x10);
    fp2 = 2.0f;
    fp3 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x14, fp3);
    memoryASet32(ds, esp + 0x10, eax);
    eax = memoryAGet32(ds, esp + 0x18);
    fp4 = memoryFGet32(ds, eax);
    memoryASet32(ds, esp + 0x70, memoryAGet32(ds, esp + 0x70) - 1);
    memoryFSet32(ds, esp + 0x1c, fp4);
    eax += 0x00000004;
    fp3 += fp4;
    memoryASet32(ds, esp + 0x18, eax);
    fp3 *= 0.5f;
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x58, fp2);
    fp2 = memoryFGet32(ds, esi + 0x34);
    fp2 *= fp1;
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esi + 0x3c);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esi + 0x34);
    fp0 += memoryFGet32(ds, esi + 0x38);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x4c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x4c);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x64);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x44);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x44);
    edx = memoryAGet32(ds, esi);
    ebp = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp2 = fp1;
    ecx = eax - 4;
    fp0 = fp2 - fp0;
    memoryASet32(ds, esp + 0x60, eax);
    if (ecx >= ebp)
        goto loc_1005e433;
    eax = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (eax * 4);
    eax = memoryAGet32(ds, esp + 0x60);
loc_1005e433: // 0000:1005e433
    if (eax >= ebp)
        goto loc_1005e43d;
    ebp = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (ebp * 4);
loc_1005e43d: // 0000:1005e43d
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, esi + 0xc, fp3);
    fp2 -= fp3;
    memoryFSet32(ds, esp + 0x54, fp2);
    fp3 = memoryFGet32(ds, esp + 0x58);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x38, fp2);
    fp3 = memoryFGet32(ds, esi + 0x1c);
    fp1 *= fp3;
    fp1 += fp2;
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005e49e;
    ecx = memoryAGet32(ds, esi + 0x2c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi, eax);
loc_1005e49e: // 0000:1005e49e
    fp1 = memoryFGet32(ds, ebx + 0x34);
    fp2 = 2.0f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    fp0 *= memoryFGet32(ds, ebx + 0x3c);
    fp0 += memoryFGet32(ds, ebx + 0x40);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, ebx + 0x34);
    fp0 += memoryFGet32(ds, ebx + 0x38);
    memoryFSet32(ds, ebx + 0x34, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x48, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    push32(0x00000000);
    push32(ecx);
    ecx = ebx;
    fp0 = memoryFGet32(ds, ebx + 0x34) - fp0;
    memoryFSet32(ds, ebx + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x64);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, ebx + 0x14);
    fp0 -= memoryFGet32(ds, ebx + 0x18);
    fp0 *= memoryFGet32(ds, ebx + 0x20);
    fp0 += memoryFGet32(ds, ebx + 0x18);
    memoryFSet32(ds, ebx + 0x18, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x40, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x40);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    edx = memoryAGet32(ds, ebx);
    ecx = (eax * 4) + 0;
    fp0 = memoryFGet32(ds, ebx + 0x18) - fp0;
    eax = edx;
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (ecx >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005e53a;
    ebp = memoryAGet32(ds, ebx + 0x2c);
    ecx = ecx + (ebp * 4);
loc_1005e53a: // 0000:1005e53a
    if (eax >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005e545;
    ebp = memoryAGet32(ds, ebx + 0x2c);
    eax = eax + (ebp * 4);
loc_1005e545: // 0000:1005e545
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, ebx + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, ebx + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ebx + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, ebx + 0xc);
    fp3 *= memoryFGet32(ds, ebx + 0x24);
    fp3 += memoryFGet32(ds, ebx + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, ebx + 0xc, fp3);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, ebx + 0x1c);
    fp3 *= fp2;
    fp3 += memoryFGet32(ds, esp + 0x38);
    memoryFSet32(ds, edx, fp3);
    memoryASet32(ds, ebx, memoryAGet32(ds, ebx) + 0x00000004);
    eax = memoryAGet32(ds, ebx);
    if (eax < memoryAGet32(ds, ebx + 0x8))
        goto loc_1005e598;
    edx = memoryAGet32(ds, ebx + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, ebx, eax);
loc_1005e598: // 0000:1005e598
    fp3 = memoryFGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, esp + 0x68);
    fp3 -= memoryFGet32(ds, edi + 0x288);
    eax += 0x00000004;
    fp4 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x68, eax);
    fp3 *= fp4;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 += memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, edi + 0x288, fp4);
    fp5 = memoryFGet32(ds, esp + 0x2c);
    fp5 -= memoryFGet32(ds, edi + 0x28c);
    fp3 *= fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 += memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, edi + 0x28c, fp4);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= memoryFGet32(ds, esp + 0x54);
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp4 *= memoryFGet32(ds, esp + 0x14);
    fp3 += fp4;
    fp3 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp3);
    eax = memoryAGet32(ds, esp + 0x6c);
    eax += 0x00000004;
    fp2 *= memoryFGet32(ds, edi + 0x288);
    fp3 = memoryFGet32(ds, edi + 0x28c);
    memoryASet32(ds, esp + 0x6c, eax);
    fp3 *= memoryFGet32(ds, esp + 0x1c);
    fp2 += fp3;
    fp2 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp2);
    if (memoryAGet32(ds, esp + 0x70))
        goto loc_1005e357;
    esi = pop32();
    fp0 = fp1;
    ebp = pop32();

    ebx = pop32();
    edi = pop32();
    esp += 0x00000054;
    esp += 20; return;
loc_1005e62b: // 0000:1005e62b
    fp0 = memoryFGet32(ds, edi + 0xb4);
    fp1 = 1.0f;
    fp2 = fp1;
    fp2 /= memoryFGet32(ds, edi + 0x70);
    fp3 = fp0;
    fp0 *= fp3;
    fp3 = 0.009999999776482582f;
    fp0 += fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 *= fp2;
    memoryFSet32(ds, edi + 0x11c, fp3);
    fp3 = memoryFGet32(ds, edi + 0xc4);
    fp3 *= fp3;
    fp0 += fp3;
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edi + 0x160, fp1);
    fp1 = (double)(int32_t)memoryAGet32(ds, edi + 0x110);
    fp2 = memoryFGet32(ds, edi + 0xb8);
    fp2 *= fp1;
    fp3 = 0.05000000074505806f;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x1a8, fp3);
    memoryFSet32(ds, edi + 0x120, fp3);
    fp3 = (double)(int32_t)memoryAGet32(ds, edi + 0x154);
    fp4 = memoryFGet32(ds, edi + 0xc8);
    fp4 *= fp3;
    fp2 *= fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, edi + 0x1ec, fp3);
    memoryFSet32(ds, edi + 0x164, fp3);
    fp3 = memoryFGet32(ds, edi + 0xb0);
    fp4 = 0.04500000178813934f;
    fp3 *= fp4;
    fp5 = 0.004999999888241291f;
    fp3 += fp5;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    fp1 *= fp5;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x1ac, fp4);
    memoryFSet32(ds, edi + 0x124, fp4);
    fp4 = memoryFGet32(ds, edi + 0xc0);
    fp1 *= fp4;
    fp1 += fp3;
    fp1 *= fp2;
    memoryFSet32(ds, edi + 0x1f0, fp1);
    memoryFSet32(ds, edi + 0x168, fp1);
    fp1 = memoryFGet32(ds, edi + 0xbc);
    fp2 = -0.8999999761581421f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, edi + 0x100, fp2);
    fp1 *= memoryFGet32(ds, edi + 0xcc);
    memoryFSet32(ds, edi + 0x144, fp1);
    if (!memoryAGet32(ds, esp + 0x70))
        goto loc_1005e9e0;
    fp1 = 1.000000045813705e-18f;
    esi = edi + 228;
    ebx = edi + 296;
loc_1005e723: // 0000:1005e723
    eax = memoryAGet32(ds, esp + 0x10);
    fp2 = 2.0f;
    fp3 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    fp3 += fp1;
    memoryASet32(ds, esp + 0x10, eax);
    eax = memoryAGet32(ds, esp + 0x18);
    memoryASet32(ds, esp + 0x70, memoryAGet32(ds, esp + 0x70) - 1);
    memoryFSet32(ds, esp + 0x14, fp3);
    eax += 0x00000004;
    fp3 = memoryFGet32(ds, eax - 4);
    memoryASet32(ds, esp + 0x18, eax);
    fp1 += fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esp + 0x1c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x34);
    fp2 *= fp1;
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esi + 0x3c);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, esi + 0x40);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, esi + 0x34);
    fp0 += memoryFGet32(ds, esi + 0x38);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x4c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x4c);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x64);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x44, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x44);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x44);
    edx = memoryAGet32(ds, esi);
    ebp = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp2 = fp1;
    ecx = eax - 4;
    fp0 = fp2 - fp0;
    memoryASet32(ds, esp + 0x60, eax);
    if (ecx >= ebp)
        goto loc_1005e7f6;
    eax = memoryAGet32(ds, esi + 0x2c);
    ecx = ecx + (eax * 4);
    eax = memoryAGet32(ds, esp + 0x60);
loc_1005e7f6: // 0000:1005e7f6
    if (eax >= ebp)
        goto loc_1005e800;
    ebp = memoryAGet32(ds, esi + 0x2c);
    eax = eax + (ebp * 4);
loc_1005e800: // 0000:1005e800
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, esi + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, esi + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, esi + 0xc);
    fp3 *= memoryFGet32(ds, esi + 0x24);
    fp3 += memoryFGet32(ds, esi + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, esi + 0xc, fp3);
    fp2 -= fp3;
    memoryFSet32(ds, esp + 0x58, fp2);
    fp2 *= memoryFGet32(ds, esi + 0x1c);
    fp3 = memoryFGet32(ds, esp + 0x14);
    fp1 += fp3;
    fp1 += fp2;
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) + 0x00000004);
    eax = memoryAGet32(ds, esi);
    if (eax < memoryAGet32(ds, esi + 0x8))
        goto loc_1005e859;
    ecx = memoryAGet32(ds, esi + 0x2c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi, eax);
loc_1005e859: // 0000:1005e859
    fp1 = memoryFGet32(ds, ebx + 0x34);
    fp2 = 2.0f;
    fp1 *= fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 = fp2 - fp0;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 = fabsf(fp1);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    fp0 *= memoryFGet32(ds, ebx + 0x3c);
    fp0 += memoryFGet32(ds, ebx + 0x40);
    memoryFSet32(ds, esp + 0x5c, fp0);
    fp0 = memoryFGet32(ds, ebx + 0x34);
    fp0 += memoryFGet32(ds, ebx + 0x38);
    memoryFSet32(ds, ebx + 0x34, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x48, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x48);
    push32(0x00000000);
    push32(ecx);
    ecx = ebx;
    fp0 = memoryFGet32(ds, ebx + 0x34) - fp0;
    memoryFSet32(ds, ebx + 0x34, fp0);
    fp0 = memoryFGet32(ds, esp + 0x64);
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, ebx + 0x14);
    fp0 -= memoryFGet32(ds, ebx + 0x18);
    fp0 *= memoryFGet32(ds, ebx + 0x20);
    fp0 += memoryFGet32(ds, ebx + 0x18);
    memoryFSet32(ds, ebx + 0x18, fp0);
    memoryFSet32(ds, esp + 0x60, fp0);
    fp0 = memoryFGet32(ds, esp + 0x60);
    memoryASet32(ds, esp + 0x40, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x40);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x40);
    edx = memoryAGet32(ds, ebx);
    ecx = (eax * 4) + 0;
    fp0 = memoryFGet32(ds, ebx + 0x18) - fp0;
    eax = edx;
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp2 = fp1;
    fp0 = fp2 - fp0;
    if (ecx >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005e8f5;
    ebp = memoryAGet32(ds, ebx + 0x2c);
    ecx = ecx + (ebp * 4);
loc_1005e8f5: // 0000:1005e8f5
    if (eax >= memoryAGet32(ds, ebx + 0x4))
        goto loc_1005e900;
    ebp = memoryAGet32(ds, ebx + 0x2c);
    eax = eax + (ebp * 4);
loc_1005e900: // 0000:1005e900
    fp2 = memoryFGet32(ds, eax);
    fp2 -= memoryFGet32(ds, ecx);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 += memoryFGet32(ds, ecx);
    fp2 = memoryFGet32(ds, ebx + 0x10);
    fp2 -= fp1;
    fp2 *= memoryFGet32(ds, ebx + 0x28);
    fp1 += fp2;
    fp2 = 1.000000045813705e-18f;
    fp1 += fp2;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ebx + 0x10, fp2);
    fp3 = fp2;
    fp3 -= memoryFGet32(ds, ebx + 0xc);
    fp3 *= memoryFGet32(ds, ebx + 0x24);
    fp3 += memoryFGet32(ds, ebx + 0xc);
    fp3 += fp1;
    memoryFSet32(ds, ebx + 0xc, fp3);
    fp2 -= fp3;
    fp3 = memoryFGet32(ds, ebx + 0x1c);
    fp3 *= fp2;
    fp4 = memoryFGet32(ds, esp + 0x1c);
    fp5 = fp4;
    fp5 += fp1;
    fp3 += fp5;
    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, edx, fp4);
    memoryASet32(ds, ebx, memoryAGet32(ds, ebx) + 0x00000004);
    eax = memoryAGet32(ds, ebx);
    if (eax < memoryAGet32(ds, ebx + 0x8))
        goto loc_1005e95b;
    edx = memoryAGet32(ds, ebx + 0x2c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, ebx, eax);
loc_1005e95b: // 0000:1005e95b
    fp4 = memoryFGet32(ds, esp + 0x24);
    eax = memoryAGet32(ds, esp + 0x68);
    fp4 -= memoryFGet32(ds, edi + 0x288);
    eax += 0x00000004;
    fp5 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x68, eax);
    fp4 *= fp5;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 += memoryFGet32(ds, edi + 0x288);
    memoryFSet32(ds, edi + 0x288, fp5);
    fp6 = memoryFGet32(ds, esp + 0x2c);
    fp6 -= memoryFGet32(ds, edi + 0x28c);
    fp4 *= fp6;
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 += memoryFGet32(ds, edi + 0x28c);
    memoryFSet32(ds, edi + 0x28c, fp5);
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 *= memoryFGet32(ds, esp + 0x58);
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    fp5 *= memoryFGet32(ds, esp + 0x14);
    fp4 += fp5;
    fp4 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp4);
    eax = memoryAGet32(ds, esp + 0x6c);
    fp4 = memoryFGet32(ds, edi + 0x288);
    eax += 0x00000004;
    fp2 *= fp4;
    memoryASet32(ds, esp + 0x6c, eax);
    fp3 *= memoryFGet32(ds, edi + 0x28c);
    fp2 += fp3;
    fp2 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp2);
    if (memoryAGet32(ds, esp + 0x70))
        goto loc_1005e723;
loc_1005e9de: // 0000:1005e9de

loc_1005e9e0: // 0000:1005e9e0

loc_1005e9e2: // 0000:1005e9e2
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
loc_1005e9e5: // 0000:1005e9e5
    edi = pop32();
    esp += 0x00000054;
    esp += 20;
}

void subopt_100685e0() // 0000:100685e0 +long +stackDrop8
{
    float fp0, fp1;
    double _cmp0r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    fp0 = memoryFGet32(ds, esp + 0x4);
    memoryFSet32(ds, ecx + 0x14, fp0);
    fp1 = (double)(int32_t)memoryAGet32(ds, ecx + 0x2c);

    _cmp0r = fp0;
    fp0 = fp1;
    if (fp1 > _cmp0r)  // fp1 vs fp0
        goto loc_100685fa;
    memoryFSet32(ds, ecx + 0x14, fp0);
    goto loc_100685fc;
loc_100685fa: // 0000:100685fa

loc_100685fc: // 0000:100685fc
    if (memoryAGet(ds, esp + 0x8))
        goto loc_10068609;
    if (memoryAGet(ds, ecx + 0x30))
        goto loc_1006860f;
loc_10068609: // 0000:10068609
    fp0 = memoryFGet32(ds, ecx + 0x14);
    memoryFSet32(ds, ecx + 0x18, fp0);
loc_1006860f: // 0000:1006860f
    memoryASet(ds, ecx + 0x30, 0x01);
    esp += 12;
}

void subopt_1005a9d0() // 0000:1005a9d0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4;
    double _cmp0r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000034;
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:1005a9db");
    }
    if (!al)
        goto loc_1005b62f;
    eax = memoryAGet32(ds, esp + 0x40);
    fp0 = memoryFGet32(ds, esi + 0x84);
    ecx = memoryAGet32(ds, eax);
    edx = memoryAGet32(ds, eax + 0x4);
    eax = memoryAGet32(ds, esp + 0x3c);
    memoryFSet32(ds, esp + 0x3c, fp0);
    fp1 = memoryFGet32(ds, esi + 0x80);
    push32(ebp);
    memoryFSet32(ds, esp + 0x10, fp1);
    ebp = memoryAGet32(ds, eax + 0x4);
    fp1 = memoryFGet32(ds, esi + 0xb4);
    push32(edi);
    fp2 = memoryFGet32(ds, esi + 0x70);
    edi = memoryAGet32(ds, eax);
    fp2 *= 0.3333333432674408f;
    fp3 = 1.0f;
    fp4 = fp3;
    fp2 = fp4 / fp2;
    fp4 = fp1;
    fp1 *= fp4;
    fp4 = 0.0010000000474974513f;
    fp1 += fp4;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    fp4 *= fp2;
    memoryFSet32(ds, esp + 0x28, fp4);
    fp4 = memoryFGet32(ds, esi + 0xc0);
    fp4 *= fp4;
    fp1 += fp4;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp2 *= fp3;
    memoryFSet32(ds, esp + 0x2c, fp2);
    memoryFSet32(ds, esp + 0x48, fp1);
    fp2 = 0.5f;
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0xd4));

    if (fp2 > _cmp0r)  // fp2 vs (double)fromFp32(memoryAGet32(ds, esi + 0xd4))
        goto loc_1005aa69;
    fp2 = -1.0f;
    memoryFSet32(ds, esp + 0x48, fp2);
loc_1005aa69: // 0000:1005aa69
    if (ecx != edi)
        goto loc_1005aa77;
    fp0 = fp1 - fp0;
    fp0 = -fp0;
    memoryFSet32(ds, esp + 0x44, fp0);
    goto loc_1005aa7b;
loc_1005aa77: // 0000:1005aa77


loc_1005aa7b: // 0000:1005aa7b
    fp0 = memoryFGet32(ds, esi + 0xac);
    push32(ebx);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x14, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x14);
    eax -= 0x00000000;
    if (!eax)
        goto loc_1005b05d;
    eax--;
    if (eax)
        goto loc_1005b62c;
    ebx = memoryAGet32(ds, esp + 0x50);
    if (!ebx)
        goto loc_1005b62c;
loc_1005aab0: // 0000:1005aab0
    fp0 = memoryFGet32(ds, ecx);
    ebx--;
    fp0 += 1.000000045813705e-18f;
    ecx += 0x00000004;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esi + 0xe8);
    fp0 += memoryFGet32(ds, esp + 0x2c);
    memoryFSet32(ds, esi + 0xe8, fp0);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    fp0 = memoryFGet32(ds, esi + 0xe8) - fp0;
    memoryFSet32(ds, esi + 0xe8, fp0);
    fp1 = memoryFGet32(ds, esi + 0xb8);
    fp1 *= memoryFGet32(ds, esi + 0xd8);
    fp1 *= 0.800000011920929f;
    fp1 += memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x24, fp1);
    fp2 = memoryFGet32(ds, esi + 0xb0);
    fp2 *= 0.8999999761581421f;
    memoryFSet32(ds, esp + 0x34, fp2);
    fp2 = memoryFGet32(ds, esi + 0x108);
    fp2 -= fp0;
    fp2 *= 0.2328290045261383f;
    fp2 += memoryFGet32(ds, esi + 0x100);
    memoryFSet32(ds, esi + 0xf0, fp2);
    fp2 = memoryFGet32(ds, esi + 0x110) - fp2;
    fp2 *= 0.8435729742050171f;
    fp2 += memoryFGet32(ds, esi + 0x108);
    memoryFSet32(ds, esi + 0xf4, fp2);
    fp2 = memoryFGet32(ds, esi + 0x118) - fp2;
    fp2 *= 0.9803509712219238f;
    fp2 += memoryFGet32(ds, esi + 0x110);
    memoryFSet32(ds, esi + 0xf8, fp2);
    memoryFSet32(ds, esp + 0x3c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x114);
    memoryFSet32(ds, esi + 0x118, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0x114, fp2);
    fp2 = memoryFGet32(ds, esi + 0x10c);
    memoryFSet32(ds, esi + 0x110, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf4);
    memoryFSet32(ds, esi + 0x10c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x104);
    memoryFSet32(ds, esi + 0x108, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf0);
    memoryFSet32(ds, esi + 0x104, fp2);
    fp2 = memoryFGet32(ds, esi + 0xfc);
    memoryFSet32(ds, esi + 0x100, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xfc, fp1);
    fp2 = memoryFGet32(ds, esi + 0x160);
    fp2 -= fp1;
    fp2 *= 0.6127790212631226f;
    fp2 += memoryFGet32(ds, esi + 0x158);
    memoryFSet32(ds, esi + 0x148, fp2);
    fp2 = memoryFGet32(ds, esi + 0x168) - fp2;
    fp2 *= 0.9426360130310059f;
    fp2 += memoryFGet32(ds, esi + 0x160);
    memoryFSet32(ds, esi + 0x14c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x170) - fp2;
    fp2 *= 0.9953020215034485f;
    fp2 += memoryFGet32(ds, esi + 0x168);
    memoryFSet32(ds, esi + 0x150, fp2);
    fp2 = memoryFGet32(ds, esi + 0x16c);
    memoryFSet32(ds, esp + 0x38, fp2);
    fp2 = memoryFGet32(ds, esi + 0x16c);
    memoryFSet32(ds, esi + 0x170, fp2);
    fp2 = memoryFGet32(ds, esi + 0x150);
    memoryFSet32(ds, esi + 0x16c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x164);
    memoryFSet32(ds, esi + 0x168, fp2);
    fp2 = memoryFGet32(ds, esi + 0x14c);
    memoryFSet32(ds, esi + 0x164, fp2);
    fp2 = memoryFGet32(ds, esi + 0x15c);
    memoryFSet32(ds, esi + 0x160, fp2);
    fp2 = memoryFGet32(ds, esi + 0x148);
    memoryFSet32(ds, esi + 0x15c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x154);
    memoryFSet32(ds, esi + 0x158, fp2);
    memoryFSet32(ds, esi + 0x154, fp1);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, esp + 0x24);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    fp2 = 0.5f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005acab;

    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005acc1;
loc_1005acab: // 0000:1005acab
    fp0 -= fp2;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005acc1: // 0000:1005acc1
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x28, fp1);
    fp0 += 0.25f;
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, esp + 0x24);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    fp0 = memoryFGet32(ds, esp + 0x24) - fp0;
    fp1 = 0.5f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_1005ad04;

    fp1 = 16.0f;
    fp1 *= fp0;
    fp1 = 8.0f - fp1;
    fp0 *= fp1;
    goto loc_1005ad1a;
loc_1005ad04: // 0000:1005ad04
    fp0 -= fp1;
    fp1 = fp0;
    fp1 *= fp0;
    fp1 *= 16.0f;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= 8.0f;
    fp0 -= fp1;
loc_1005ad1a: // 0000:1005ad1a
    fp1 = memoryFGet32(ds, esp + 0x34);
    edi += 0x00000004;
    fp0 *= fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esp + 0x38);
    fp2 = memoryFGet32(ds, esp + 0x28);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esp + 0x3c);
    fp0 += fp1;
    memoryFSet32(ds, esi + 0xd8, fp0);
    fp1 = fp0;
    fp1 -= memoryFGet32(ds, esi + 0xe0);
    fp1 *= 0.0010000000474974513f;
    fp1 += memoryFGet32(ds, esi + 0xe0);
    memoryFSet32(ds, esi + 0xe0, fp1);
    fp0 -= fp1;
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, esp + 0x48);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, edi - 4);
    memoryFSet32(ds, edi - 4, fp0);
    if (ebx)
        goto loc_1005aab0;
    goto loc_1005ad80;
    // gap 9 bytes // gap 9 bytes
loc_1005ad80: // 0000:1005ad80
    fp0 = memoryFGet32(ds, edx);
    memoryASet32(ds, esp + 0x50, memoryAGet32(ds, esp + 0x50) - 1);
    fp0 += 1.000000045813705e-18f;
    edx += 0x00000004;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esp + 0x30);
    fp0 += memoryFGet32(ds, esi + 0xec);
    memoryFSet32(ds, esi + 0xec, fp0);
    memoryFSet32(ds, esp + 0x3c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x3c);
    memoryASet32(ds, esp + 0x28, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    fp0 = memoryFGet32(ds, esi + 0xec) - fp0;
    memoryFSet32(ds, esi + 0xec, fp0);
    fp1 = memoryFGet32(ds, esi + 0xc4);
    fp1 *= memoryFGet32(ds, esp + 0x4c);
    fp1 *= memoryFGet32(ds, esi + 0xdc);
    fp1 *= 0.800000011920929f;
    fp1 += memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x38, fp1);
    fp2 = memoryFGet32(ds, esi + 0xbc);
    fp2 *= 0.8999999761581421f;
    memoryFSet32(ds, esp + 0x34, fp2);
    fp2 = memoryFGet32(ds, esi + 0x134);
    fp2 -= fp0;
    fp2 *= 0.2328290045261383f;
    fp2 += memoryFGet32(ds, esi + 0x12c);
    memoryFSet32(ds, esi + 0x11c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x13c) - fp2;
    fp2 *= 0.8435729742050171f;
    fp2 += memoryFGet32(ds, esi + 0x134);
    memoryFSet32(ds, esi + 0x120, fp2);
    fp2 = memoryFGet32(ds, esi + 0x144) - fp2;
    fp2 *= 0.9803509712219238f;
    fp2 += memoryFGet32(ds, esi + 0x13c);
    memoryFSet32(ds, esi + 0x124, fp2);
    memoryFSet32(ds, esp + 0x40, fp2);
    fp2 = memoryFGet32(ds, esi + 0x140);
    memoryFSet32(ds, esi + 0x144, fp2);
    fp2 = memoryFGet32(ds, esi + 0x124);
    memoryFSet32(ds, esi + 0x140, fp2);
    fp2 = memoryFGet32(ds, esi + 0x138);
    memoryFSet32(ds, esi + 0x13c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x120);
    memoryFSet32(ds, esi + 0x138, fp2);
    fp2 = memoryFGet32(ds, esi + 0x130);
    memoryFSet32(ds, esi + 0x134, fp2);
    fp2 = memoryFGet32(ds, esi + 0x11c);
    memoryFSet32(ds, esi + 0x130, fp2);
    fp2 = memoryFGet32(ds, esi + 0x128);
    memoryFSet32(ds, esi + 0x12c, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0x128, fp1);
    fp2 = memoryFGet32(ds, esi + 0x18c);
    fp2 -= fp1;
    fp2 *= 0.6127790212631226f;
    fp2 += memoryFGet32(ds, esi + 0x184);
    memoryFSet32(ds, esi + 0x174, fp2);
    fp2 = memoryFGet32(ds, esi + 0x194) - fp2;
    fp2 *= 0.9426360130310059f;
    fp2 += memoryFGet32(ds, esi + 0x18c);
    memoryFSet32(ds, esi + 0x178, fp2);
    fp2 = memoryFGet32(ds, esi + 0x19c) - fp2;
    fp2 *= 0.9953020215034485f;
    fp2 += memoryFGet32(ds, esi + 0x194);
    memoryFSet32(ds, esi + 0x17c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x198);
    memoryFSet32(ds, esp + 0x2c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x198);
    memoryFSet32(ds, esi + 0x19c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x17c);
    memoryFSet32(ds, esi + 0x198, fp2);
    fp2 = memoryFGet32(ds, esi + 0x190);
    memoryFSet32(ds, esi + 0x194, fp2);
    fp2 = memoryFGet32(ds, esi + 0x178);
    memoryFSet32(ds, esi + 0x190, fp2);
    fp2 = memoryFGet32(ds, esi + 0x188);
    memoryFSet32(ds, esi + 0x18c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x174);
    memoryFSet32(ds, esi + 0x188, fp2);
    fp2 = memoryFGet32(ds, esi + 0x180);
    memoryFSet32(ds, esi + 0x184, fp2);
    memoryFSet32(ds, esi + 0x180, fp1);
    memoryFSet32(ds, esp + 0x3c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x3c);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x10);
    fp1 = memoryFGet32(ds, esp + 0x38);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    fp2 = 0.5f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005af82;

    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005af98;
loc_1005af82: // 0000:1005af82
    fp0 -= fp2;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005af98: // 0000:1005af98
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x1c, fp1);
    fp0 += 0.25f;
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x24, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x24);
    fp0 = memoryFGet32(ds, esp + 0x20) - fp0;
    fp1 = 0.5f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_1005afdb;

    fp1 = 16.0f;
    fp1 *= fp0;
    fp1 = 8.0f - fp1;
    fp0 *= fp1;
    goto loc_1005aff1;
loc_1005afdb: // 0000:1005afdb
    fp0 -= fp1;
    fp1 = fp0;
    fp1 *= fp0;
    fp1 *= 16.0f;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= 8.0f;
    fp0 -= fp1;
loc_1005aff1: // 0000:1005aff1
    fp1 = memoryFGet32(ds, esp + 0x34);
    ebp += 0x00000004;
    fp0 *= fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esp + 0x2c);
    fp1 *= memoryFGet32(ds, esp + 0x4c);
    fp2 = memoryFGet32(ds, esp + 0x1c);
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= memoryFGet32(ds, esp + 0x40);
    fp0 += fp1;
    memoryFSet32(ds, esi + 0xdc, fp0);
    fp1 = fp0;
    fp1 -= memoryFGet32(ds, esi + 0xe4);
    fp1 *= 0.0010000000474974513f;
    fp1 += memoryFGet32(ds, esi + 0xe4);
    memoryFSet32(ds, esi + 0xe4, fp1);
    fp0 -= fp1;
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x14);
    fp1 *= memoryFGet32(ds, esp + 0x48);
    fp0 += fp1;
    fp0 += memoryFGet32(ss, ebp - 4);
    memoryFSet32(ss, ebp - 4, fp0);
    if (memoryAGet32(ds, esp + 0x50))
        goto loc_1005ad80;
    ebx = pop32();
    edi = pop32();
    ebp = pop32();
    esi = pop32();
    esp += 0x00000034;
    esp += 20; return;
loc_1005b05d: // 0000:1005b05d
    ebx = memoryAGet32(ds, esp + 0x50);
    fp0 = 0.5f;
    memoryASet32(ds, esp + 0x10, ebx);
    if (!ebx)
        goto loc_1005b344;
loc_1005b073: // 0000:1005b073
    fp1 = memoryFGet32(ds, edx);
    memoryASet32(ds, esp + 0x10, memoryAGet32(ds, esp + 0x10) - 1);
    fp1 += memoryFGet32(ds, ecx);
    edx += 0x00000004;
    fp0 *= fp1;
    fp0 += 1.000000045813705e-18f;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esi + 0xe8);
    fp0 += memoryFGet32(ds, esp + 0x2c);
    memoryFSet32(ds, esi + 0xe8, fp0);
    memoryFSet32(ds, esp + 0x40, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryASet32(ds, esp + 0x28, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    fp0 = memoryFGet32(ds, esi + 0xe8) - fp0;
    memoryFSet32(ds, esi + 0xe8, fp0);
    fp1 = memoryFGet32(ds, esi + 0xb8);
    fp1 *= memoryFGet32(ds, esi + 0xd8);
    fp1 *= 0.800000011920929f;
    fp1 += memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x3c, fp1);
    fp2 = memoryFGet32(ds, esi + 0xb0);
    fp2 *= 0.8999999761581421f;
    memoryFSet32(ds, esp + 0x38, fp2);
    fp2 = memoryFGet32(ds, esi + 0x108);
    fp2 -= fp0;
    fp2 *= 0.2328290045261383f;
    fp2 += memoryFGet32(ds, esi + 0x100);
    memoryFSet32(ds, esi + 0xf0, fp2);
    fp2 = memoryFGet32(ds, esi + 0x110) - fp2;
    fp2 *= 0.8435729742050171f;
    fp2 += memoryFGet32(ds, esi + 0x108);
    memoryFSet32(ds, esi + 0xf4, fp2);
    fp2 = memoryFGet32(ds, esi + 0x118) - fp2;
    fp2 *= 0.9803509712219238f;
    fp2 += memoryFGet32(ds, esi + 0x110);
    memoryFSet32(ds, esi + 0xf8, fp2);
    memoryFSet32(ds, esp + 0x14, fp2);
    fp2 = memoryFGet32(ds, esi + 0x114);
    memoryFSet32(ds, esi + 0x118, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0x114, fp2);
    fp2 = memoryFGet32(ds, esi + 0x10c);
    memoryFSet32(ds, esi + 0x110, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf4);
    memoryFSet32(ds, esi + 0x10c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x104);
    memoryFSet32(ds, esi + 0x108, fp2);
    fp2 = memoryFGet32(ds, esi + 0xf0);
    memoryFSet32(ds, esi + 0x104, fp2);
    fp2 = memoryFGet32(ds, esi + 0xfc);
    memoryFSet32(ds, esi + 0x100, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xfc, fp1);
    fp2 = memoryFGet32(ds, esi + 0x160);
    fp2 -= fp1;
    fp2 *= 0.6127790212631226f;
    fp2 += memoryFGet32(ds, esi + 0x158);
    memoryFSet32(ds, esi + 0x148, fp2);
    fp2 = memoryFGet32(ds, esi + 0x168) - fp2;
    fp2 *= 0.9426360130310059f;
    fp2 += memoryFGet32(ds, esi + 0x160);
    memoryFSet32(ds, esi + 0x14c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x170) - fp2;
    fp2 *= 0.9953020215034485f;
    fp2 += memoryFGet32(ds, esi + 0x168);
    memoryFSet32(ds, esi + 0x150, fp2);
    fp2 = memoryFGet32(ds, esi + 0x16c);
    memoryFSet32(ds, esp + 0x34, fp2);
    fp2 = memoryFGet32(ds, esi + 0x16c);
    memoryFSet32(ds, esi + 0x170, fp2);
    fp2 = memoryFGet32(ds, esi + 0x150);
    memoryFSet32(ds, esi + 0x16c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x164);
    memoryFSet32(ds, esi + 0x168, fp2);
    fp2 = memoryFGet32(ds, esi + 0x14c);
    memoryFSet32(ds, esi + 0x164, fp2);
    fp2 = memoryFGet32(ds, esi + 0x15c);
    memoryFSet32(ds, esi + 0x160, fp2);
    fp2 = memoryFGet32(ds, esi + 0x148);
    memoryFSet32(ds, esi + 0x15c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x154);
    memoryFSet32(ds, esi + 0x158, fp2);
    memoryFSet32(ds, esi + 0x154, fp1);
    memoryFSet32(ds, esp + 0x40, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryASet32(ds, esp + 0x50, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x50);
    fp1 = memoryFGet32(ds, esp + 0x3c);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    fp2 = 0.5f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005b275;

    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005b28b;
loc_1005b275: // 0000:1005b275
    fp0 -= fp2;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005b28b: // 0000:1005b28b
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x1c, fp1);
    fp0 += 0.25f;
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, esp + 0x20);
    memoryASet32(ds, esp + 0x24, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x24);
    fp0 = memoryFGet32(ds, esp + 0x20) - fp0;
    fp1 = 0.5f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_1005b2cc;
    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005b2e2;
loc_1005b2cc: // 0000:1005b2cc
    fp0 -= fp1;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005b2e2: // 0000:1005b2e2
    fp2 = memoryFGet32(ds, esp + 0x38);
    ecx += 0x00000004;
    fp0 *= fp2;
    edi += 0x00000004;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esp + 0x34);
    fp3 = memoryFGet32(ds, esp + 0x1c);
    fp0 *= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esp + 0x14);
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xd8, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xe0);
    fp2 *= 0.0010000000474974513f;
    fp2 += memoryFGet32(ds, esi + 0xe0);
    memoryFSet32(ds, esi + 0xe0, fp2);
    fp1 -= fp2;
    fp1 *= memoryFGet32(ds, esp + 0x18);
    fp2 = memoryFGet32(ds, ecx - 4);
    fp2 *= memoryFGet32(ds, esp + 0x48);
    fp1 += fp2;
    fp1 += memoryFGet32(ds, edi - 4);
    memoryFSet32(ds, edi - 4, fp1);
    if (memoryAGet32(ds, esp + 0x10))
        goto loc_1005b073;
loc_1005b344: // 0000:1005b344
    eax = (ebx * 4) + 0;
    ecx -= eax;
    edx -= eax;
    if (!ebx)
        goto loc_1005b62a;
loc_1005b357: // 0000:1005b357
    fp1 = memoryFGet32(ds, edx);
    ebx--;
    fp1 += memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    fp0 *= fp1;
    fp0 += 1.000000045813705e-18f;
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esp + 0x30);
    fp0 += memoryFGet32(ds, esi + 0xec);
    memoryFSet32(ds, esi + 0xec, fp0);
    memoryFSet32(ds, esp + 0x40, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryASet32(ds, esp + 0x2c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x2c);
    fp0 = memoryFGet32(ds, esi + 0xec) - fp0;
    memoryFSet32(ds, esi + 0xec, fp0);
    fp1 = memoryFGet32(ds, esi + 0xc4);
    fp1 *= memoryFGet32(ds, esp + 0x4c);
    fp1 *= memoryFGet32(ds, esi + 0xdc);
    fp1 *= 0.800000011920929f;
    fp1 += memoryFGet32(ds, esp + 0x14);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x3c, fp1);
    fp2 = memoryFGet32(ds, esi + 0xbc);
    fp2 *= 0.8999999761581421f;
    memoryFSet32(ds, esp + 0x38, fp2);
    fp2 = memoryFGet32(ds, esi + 0x134);
    fp2 -= fp0;
    fp2 *= 0.2328290045261383f;
    fp2 += memoryFGet32(ds, esi + 0x12c);
    memoryFSet32(ds, esi + 0x11c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x13c) - fp2;
    fp2 *= 0.8435729742050171f;
    fp2 += memoryFGet32(ds, esi + 0x134);
    memoryFSet32(ds, esi + 0x120, fp2);
    fp2 = memoryFGet32(ds, esi + 0x144) - fp2;
    fp2 *= 0.9803509712219238f;
    fp2 += memoryFGet32(ds, esi + 0x13c);
    memoryFSet32(ds, esi + 0x124, fp2);
    memoryFSet32(ds, esp + 0x1c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x140);
    memoryFSet32(ds, esi + 0x144, fp2);
    fp2 = memoryFGet32(ds, esi + 0x124);
    memoryFSet32(ds, esi + 0x140, fp2);
    fp2 = memoryFGet32(ds, esi + 0x138);
    memoryFSet32(ds, esi + 0x13c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x120);
    memoryFSet32(ds, esi + 0x138, fp2);
    fp2 = memoryFGet32(ds, esi + 0x130);
    memoryFSet32(ds, esi + 0x134, fp2);
    fp2 = memoryFGet32(ds, esi + 0x11c);
    memoryFSet32(ds, esi + 0x130, fp2);
    fp2 = memoryFGet32(ds, esi + 0x128);
    memoryFSet32(ds, esi + 0x12c, fp2);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0x128, fp1);
    fp2 = memoryFGet32(ds, esi + 0x18c);
    fp2 -= fp1;
    fp2 *= 0.6127790212631226f;
    fp2 += memoryFGet32(ds, esi + 0x184);
    memoryFSet32(ds, esi + 0x174, fp2);
    fp2 = memoryFGet32(ds, esi + 0x194) - fp2;
    fp2 *= 0.9426360130310059f;
    fp2 += memoryFGet32(ds, esi + 0x18c);
    memoryFSet32(ds, esi + 0x178, fp2);
    fp2 = memoryFGet32(ds, esi + 0x19c) - fp2;
    fp2 *= 0.9953020215034485f;
    fp2 += memoryFGet32(ds, esi + 0x194);
    memoryFSet32(ds, esi + 0x17c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x198);
    memoryFSet32(ds, esp + 0x34, fp2);
    fp2 = memoryFGet32(ds, esi + 0x198);
    memoryFSet32(ds, esi + 0x19c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x17c);
    memoryFSet32(ds, esi + 0x198, fp2);
    fp2 = memoryFGet32(ds, esi + 0x190);
    memoryFSet32(ds, esi + 0x194, fp2);
    fp2 = memoryFGet32(ds, esi + 0x178);
    memoryFSet32(ds, esi + 0x190, fp2);
    fp2 = memoryFGet32(ds, esi + 0x188);
    memoryFSet32(ds, esi + 0x18c, fp2);
    fp2 = memoryFGet32(ds, esi + 0x174);
    memoryFSet32(ds, esi + 0x188, fp2);
    fp2 = memoryFGet32(ds, esi + 0x180);
    memoryFSet32(ds, esi + 0x184, fp2);
    memoryFSet32(ds, esi + 0x180, fp1);
    memoryFSet32(ds, esp + 0x40, fp0);
    fp0 = memoryFGet32(ds, esp + 0x40);
    memoryASet32(ds, esp + 0x50, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x50);
    fp1 = memoryFGet32(ds, esp + 0x3c);
    fp2 = fp1;
    fp0 = fp2 - fp0;
    fp2 = 0.5f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_1005b55a;

    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005b570;
loc_1005b55a: // 0000:1005b55a
    fp0 -= fp2;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005b570: // 0000:1005b570
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esp + 0x20, fp1);
    fp0 += 0.25f;
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, esp + 0x24);
    memoryASet32(ds, esp + 0x28, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x28);
    fp0 = memoryFGet32(ds, esp + 0x24) - fp0;
    fp1 = 0.5f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_1005b5b1;
    fp2 = fp0;
    fp2 *= 16.0f;
    fp2 = 8.0f - fp2;
    fp0 *= fp2;
    goto loc_1005b5c7;
loc_1005b5b1: // 0000:1005b5b1
    fp0 -= fp1;
    fp2 = fp0;
    fp2 *= fp0;
    fp2 *= 16.0f;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= 8.0f;
    fp0 -= fp2;
loc_1005b5c7: // 0000:1005b5c7
    fp2 = memoryFGet32(ds, esp + 0x38);
    edx += 0x00000004;
    fp0 *= fp2;
    ebp += 0x00000004;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esp + 0x34);
    fp2 *= memoryFGet32(ds, esp + 0x4c);
    fp3 = memoryFGet32(ds, esp + 0x20);
    fp0 *= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 *= memoryFGet32(ds, esp + 0x1c);
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xdc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xe4);
    fp2 *= 0.0010000000474974513f;
    fp2 += memoryFGet32(ds, esi + 0xe4);
    memoryFSet32(ds, esi + 0xe4, fp2);
    fp1 -= fp2;
    fp1 *= memoryFGet32(ds, esp + 0x18);
    fp2 = memoryFGet32(ds, edx - 4);
    fp2 *= memoryFGet32(ds, esp + 0x48);
    fp1 += fp2;
    fp1 += memoryFGet32(ss, ebp - 4);
    memoryFSet32(ss, ebp - 4, fp1);
    if (ebx)
        goto loc_1005b357;
loc_1005b62a: // 0000:1005b62a

loc_1005b62c: // 0000:1005b62c
    ebx = pop32();
    edi = pop32();
    ebp = pop32();
loc_1005b62f: // 0000:1005b62f
    esi = pop32();
    esp += 0x00000034;
    esp += 20;
}

void subopt_10058ab0() // 0000:10058ab0 +long +stackDrop8
{
    float fp0;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (eax > 0x00000004)
        goto loc_10058ac4;
    fp0 = memoryFGet32(ds, esp + 0x8);
    memoryFSet32(ds, ecx + eax * 4 + 0xac, fp0);
loc_10058ac4: // 0000:10058ac4
    esp += 12; return;
}

void subopt_10058ad0() // 0000:10058ad0 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    double _cmp2r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000020;
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:10058adb");
    }
    if (!al)
        goto loc_1005904f;
    eax = memoryAGet32(ds, esp + 0x2c);
    fp0 = memoryFGet32(ds, esi + 0x84);
    edx = memoryAGet32(ds, eax);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp1 = memoryFGet32(ds, esi + 0x80);
    push32(ebx);
    ebx = memoryAGet32(ds, eax + 0x4);
    memoryFSet32(ds, esp + 0x8, fp1);
    eax = memoryAGet32(ds, esp + 0x2c);
    ecx = memoryAGet32(ds, eax);
    push32(edi);
    edi = memoryAGet32(ds, eax + 0x4);
    if (edx != ecx)
        goto loc_10058b1d;
    fp1 = 1.0f;
    fp0 = fp1 - fp0;
    fp0 = -fp0;
    memoryFSet32(ds, esp + 0x34, fp0);
    goto loc_10058b1f;
loc_10058b1d: // 0000:10058b1d

loc_10058b1f: // 0000:10058b1f
    fp0 = memoryFGet32(ds, esi + 0xac);
    push32(ebp);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x34);
    eax -= 0x00000000;
    if (!eax)
        goto loc_10058d2b;
    eax--;
    if (eax)
        goto loc_1005904c;
    fp0 = 1.0f;
    fp1 = fp0;
    fp1 /= memoryFGet32(ds, esi + 0x70);
    fp2 = memoryFGet32(ds, esi + 0xb4);
    fp2 *= 8000.0f;
    fp2 += 10000.0f;
    fp2 *= fp1;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_10058b70;

    fp2 = fp0;
loc_10058b70: // 0000:10058b70
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 *= 22050.0f;

    if (fp2 <= fp0)  // fp2 vs fp0
        goto loc_10058b85;

    fp2 = fp0;
loc_10058b85: // 0000:10058b85
    ebp = memoryAGet32(ds, esp + 0x3c);
    if (!ebp)
        goto loc_10059038;
    fp3 = fp0;
    fp3 -= fp2;
    fp4 = 1.5259021893143654e-05f;
loc_10058b9b: // 0000:10058b9b
    fp5 = memoryFGet32(ds, edx);
    eax = memoryAGet32(ds, esi + 0x858);
    fp5 += fp5;
    eax = (int32_t)eax * (int32_t)0x0019660d;
    fp6 = memoryFGet32(ds, esi + 0x864);
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, esi + 0x860);
    memoryFSet32(ds, esi + 0x860, fp6);
    eax += 0x3c6ef35f;
    fp5 -= fp6;
    memoryASet32(ds, esi + 0x858, eax);
    eax >>= 22;
    ebp--;
    fp5 -= memoryFGet32(ds, esi + 0x864);
    memoryASet32(ds, esp + 0x34, eax);
    memoryFSet32(ds, esi + 0x868, fp5);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x864);
    fp5 += 1.000000045813705e-18f;
    memoryFSet32(ds, esi + 0x864, fp5);
    fp5 = memoryFGet32(ds, esi + 0x860);
    fp5 *= fp5;
    fp5 += fp0;
    fp5 = memoryFGet32(ds, esi + 0x860) / fp5;
    fp5 *= 0.699999988079071f;
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp7 = fp3;
    fp7 *= memoryFGet32(ds, esi + 0x878);
    fp6 += fp7;
    memoryFSet32(ds, esi + 0x878, fp6);
    fp7 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    if ((int32_t)eax >= 0)
        goto loc_10058c2e;
    fp7 += 4294967296.0f;
loc_10058c2e: // 0000:10058c2e
    fp7 *= fp4;
    edx += 0x00000004;
    ecx += 0x00000004;
    fp6 *= fp7;
    fp5 += fp6;
    fp5 *= memoryFGet32(ds, esp + 0x10);
    fp6 = memoryFGet32(ds, edx - 4);
    fp6 *= memoryFGet32(ds, esp + 0x38);
    fp5 += fp6;
    fp5 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp5);
    if (ebp)
        goto loc_10058b9b;
loc_10058c55: // 0000:10058c55
    fp5 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esi + 0x85c);
    fp5 += fp5;
    ecx = memoryAGet32(ds, esp + 0x3c);
    eax = (int32_t)eax * (int32_t)0x0019660d;
    fp6 = memoryFGet32(ds, esi + 0x870);
    fp6 *= fp1;
    fp6 += memoryFGet32(ds, esi + 0x86c);
    memoryFSet32(ds, esi + 0x86c, fp6);
    fp5 -= fp6;
    eax += 0x3c6ef35f;
    memoryASet32(ds, esi + 0x85c, eax);
    eax >>= 22;
    fp5 -= memoryFGet32(ds, esi + 0x870);
    ecx--;
    memoryASet32(ds, esp + 0x34, eax);
    memoryASet32(ds, esp + 0x3c, ecx);
    memoryFSet32(ds, esi + 0x874, fp5);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x870);
    fp5 += 1.000000045813705e-18f;
    memoryFSet32(ds, esi + 0x870, fp5);
    fp5 = memoryFGet32(ds, esi + 0x86c);
    fp5 *= fp5;
    fp5 += fp0;
    fp5 = memoryFGet32(ds, esi + 0x86c) / fp5;
    fp5 *= 0.699999988079071f;
    fp6 = fp5;
    fp6 = fabsf(fp6);
    fp6 *= fp2;
    fp7 = fp3;
    fp7 *= memoryFGet32(ds, esi + 0x87c);
    fp6 += fp7;
    memoryFSet32(ds, esi + 0x87c, fp6);
    fp7 = (double)(int32_t)memoryAGet32(ds, esp + 0x34);
    if ((int32_t)eax >= 0)
        goto loc_10058cf0;
    fp7 += 4294967296.0f;
loc_10058cf0: // 0000:10058cf0
    fp7 *= fp4;
    ebx += 0x00000004;
    edi += 0x00000004;
    fp6 *= fp7;
    fp5 += fp6;
    fp5 *= memoryFGet32(ds, esp + 0x10);
    fp6 = memoryFGet32(ds, ebx - 4);
    fp6 *= memoryFGet32(ds, esp + 0x38);
    fp5 += fp6;
    fp5 += memoryFGet32(ds, edi - 4);
    memoryFSet32(ds, edi - 4, fp5);
    if (ecx)
        goto loc_10058c55;
    fp1 = fp4;
    ebp = pop32();
    fp0 = fp3;
    edi = pop32();

    ebx = pop32();
    fp0 = fp1;
    esi = pop32();

    esp += 0x00000020;
    esp += 20; return;
loc_10058d2b: // 0000:10058d2b
    fp0 = 0.9900000095367432f;
    _cmp2r = (double)fromFp32(memoryAGet32(ds, esi + 0xb4));

    if (fp0 > _cmp2r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0xb4))
        goto loc_10058d43;
    fp0 = memoryFGet32(ds, esi + 0x70);
    goto loc_10058d4f;
loc_10058d43: // 0000:10058d43
    fp0 = memoryFGet32(ds, esi + 0xb4);
    fp0 *= 44100.0f;
loc_10058d4f: // 0000:10058d4f
    memoryFSet32(ds, esp + 0x14, fp0);
    fp0 = memoryFGet32(ds, esi + 0xb8);
    memoryFSet32(ds, esp + 0x18, fp0);
    fp0 = memoryFGet32(ds, esi + 0xb0);
    fp0 *= 240.99000549316406f;
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x34, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x34);
    fp0 = memoryFGet32(ds, esi + eax * 8 + 0xc0);
    ebp = memoryAGet32(ds, esp + 0x3c);
    memoryFSet32(ds, esp + 0x20, fp0);
    fp0 = memoryFGet32(ds, esi + eax * 8 + 0xc4);
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = 44100.0f;
    fp0 /= memoryFGet32(ds, esi + 0x70);
    fp0 *= memoryFGet32(ds, esi + 0xbc);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp1 *= 0.5f;
    memoryFSet32(ds, esp + 0x28, fp1);
    if (!ebp)
        goto loc_10059048;
    fp2 = 1.000000045813705e-18f;
    fp3 = -0.125f;
    fp4 = memoryFGet32(ds, esp + 0x18);
loc_10058dd4: // 0000:10058dd4
    fp5 = memoryFGet32(ds, esi + 0x850);
    ebp--;
    fp5 -= memoryFGet32(ds, esp + 0x14);
    memoryFSet32(ds, esi + 0x850, fp5);
    fp6 = 0.0f;

    if (fp6 < fp5)  // fp6 vs fp5
        goto loc_10058e05;
    fp5 += memoryFGet32(ds, esi + 0x70);
    memoryFSet32(ds, esi + 0x850, fp5);
    fp5 = memoryFGet32(ds, edx);
    fp5 += fp2;
    memoryFSet32(ds, esi + 0x848, fp5);
    goto loc_10058e07;
loc_10058e05: // 0000:10058e05

loc_10058e07: // 0000:10058e07
    fp5 = memoryFGet32(ds, esi + 0x848);
    if ((int32_t)memoryAGet32(ds, esp + 0x34) >= (int32_t)0x000000f0)
        goto loc_10058e5b;
    fp1 = fp5;

    fp2 = fp3;
    fp0 = fp2;
    fp0 = fp1;
    fp0 *= memoryFGet32(ds, esp + 0x20);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    fp0 *= memoryFGet32(ds, esp + 0x24);
    fp1 = -0.125f;
    fp2 = 1.000000045813705e-18f;
    fp3 = 1.0f;
    fp4 = memoryFGet32(ds, esp + 0x28);
    fp5 = memoryFGet32(ds, esp + 0x18);
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp0; fp0 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    { double _xchg = fp5; fp5 = fp1; fp1 = _xchg; }
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
loc_10058e5b: // 0000:10058e5b
    fp6 = 0.0f;

    if (fp6 == fp4)  // fp6 vs fp4
        goto loc_10058e9e;
    fp6 = 64.0f;
    fp6 *= fp5;

    if (fp6 >= fp3)  // fp6 vs fp3
        goto loc_10058e7d;

    fp6 = fp3;
    goto loc_10058e94;
loc_10058e7d: // 0000:10058e7d
    fp7 = 0.125f;

    if (fp7 >= fp6)  // fp7 vs fp6
        goto loc_10058e94;

    fp6 = 0.125f;
loc_10058e94: // 0000:10058e94
    fp7 = fp0;
    fp7 -= fp4;
    fp5 *= fp7;
    fp6 *= fp4;
    fp5 += fp6;
loc_10058e9e: // 0000:10058e9e
    fp6 = 0.9900000095367432f;

    if (fp6 < fp1)  // fp6 vs fp1
        goto loc_10058ed7;
    fp5 += fp2;
    fp5 -= memoryFGet32(ds, esi + 0x880);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x880);
    memoryFSet32(ds, esi + 0x880, fp5);
    fp5 -= memoryFGet32(ds, esi + 0x884);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x884);
    memoryFSet32(ds, esi + 0x884, fp5);
loc_10058ed7: // 0000:10058ed7
    fp6 = memoryFGet32(ds, edx);
    edx += 0x00000004;
    fp6 *= memoryFGet32(ds, esp + 0x38);
    ecx += 0x00000004;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= memoryFGet32(ds, esp + 0x10);
    fp5 += fp6;
    fp5 += memoryFGet32(ds, ecx - 4);
    memoryFSet32(ds, ecx - 4, fp5);
    if (ebp)
        goto loc_10058dd4;
loc_10058ef9: // 0000:10058ef9
    fp5 = memoryFGet32(ds, esi + 0x854);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    fp5 -= memoryFGet32(ds, esp + 0x14);
    memoryFSet32(ds, esi + 0x854, fp5);
    fp6 = 0.0f;

    if (fp6 < fp5)  // fp6 vs fp5
        goto loc_10058f2d;
    fp5 += memoryFGet32(ds, esi + 0x70);
    memoryFSet32(ds, esi + 0x854, fp5);
    fp5 = memoryFGet32(ds, ebx);
    fp5 += fp2;
    memoryFSet32(ds, esi + 0x84c, fp5);
    goto loc_10058f2f;
loc_10058f2d: // 0000:10058f2d

loc_10058f2f: // 0000:10058f2f
    fp5 = memoryFGet32(ds, esi + 0x84c);
    if ((int32_t)memoryAGet32(ds, esp + 0x34) >= (int32_t)0x000000f0)
        goto loc_10058f83;
    fp1 = fp5;

    fp2 = fp3;
    fp0 = fp2;
    fp0 = fp1;
    fp0 *= memoryFGet32(ds, esp + 0x20);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    fp0 *= memoryFGet32(ds, esp + 0x24);
    fp1 = -0.125f;
    fp2 = 1.000000045813705e-18f;
    fp3 = 1.0f;
    fp4 = memoryFGet32(ds, esp + 0x28);
    fp5 = memoryFGet32(ds, esp + 0x18);
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp0; fp0 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    { double _xchg = fp5; fp5 = fp1; fp1 = _xchg; }
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
loc_10058f83: // 0000:10058f83
    fp6 = 0.0f;

    if (fp6 == fp4)  // fp6 vs fp4
        goto loc_10058fc6;
    fp6 = 64.0f;
    fp6 *= fp5;

    if (fp6 >= fp3)  // fp6 vs fp3
        goto loc_10058fa5;

    fp6 = fp3;
    goto loc_10058fbc;
loc_10058fa5: // 0000:10058fa5
    fp7 = 0.125f;

    if (fp7 >= fp6)  // fp7 vs fp6
        goto loc_10058fbc;

    fp6 = 0.125f;
loc_10058fbc: // 0000:10058fbc
    fp7 = fp0;
    fp7 -= fp4;
    fp5 *= fp7;
    fp6 *= fp4;
    fp5 += fp6;
loc_10058fc6: // 0000:10058fc6
    fp6 = 0.9900000095367432f;

    if (fp6 < fp1)  // fp6 vs fp1
        goto loc_10058fff;
    fp5 += fp2;
    fp5 -= memoryFGet32(ds, esi + 0x888);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x888);
    memoryFSet32(ds, esi + 0x888, fp5);
    fp5 -= memoryFGet32(ds, esi + 0x88c);
    fp5 *= fp1;
    fp5 += memoryFGet32(ds, esi + 0x88c);
    memoryFSet32(ds, esi + 0x88c, fp5);
loc_10058fff: // 0000:10058fff
    fp6 = memoryFGet32(ds, ebx);
    ebx += 0x00000004;
    fp6 *= memoryFGet32(ds, esp + 0x38);
    edi += 0x00000004;
    { double _xchg = fp6; fp6 = fp5; fp5 = _xchg; }
    fp6 *= memoryFGet32(ds, esp + 0x10);
    fp5 += fp6;
    fp5 += memoryFGet32(ds, edi - 4);
    memoryFSet32(ds, edi - 4, fp5);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_10058ef9;
    fp1 = fp4;
    ebp = pop32();
    fp1 = fp3;
    edi = pop32();

    ebx = pop32();
    fp0 = fp1;
    esi = pop32();

    esp += 0x00000020;
    esp += 20; return;
loc_10059038: // 0000:10059038
    ebp = pop32();
    fp1 = fp2;
    edi = pop32();
    fp0 = fp1;
    ebx = pop32();

    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_10059048: // 0000:10059048


loc_1005904c: // 0000:1005904c
    ebp = pop32();
    edi = pop32();
    ebx = pop32();
loc_1005904f: // 0000:1005904f
    esi = pop32();
    esp += 0x00000020;
    esp += 20;
}

void subopt_1001a000() // 0000:1001a000 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
    double _cmp2r, _cmp3r, _cmp4r;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000014;
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x2c);
    eax = ecx;
    ecx = (int8_t)memoryAGet(ds, esi + 0x24);
    fp0 = memoryFGet32(ds, eax + 0xb8);
    fp0 *= 0.007499999832361937f;
    memoryASet32(ds, esp + 0x2c, ecx);
    edx = memoryAGet32(ds, esp + 0x28);
    push32(edi);
    fp1 = (double)(int32_t)memoryAGet32(ds, esp + 0x30);
    memoryASet32(ds, esp + 0x14, eax);
    fp1 *= 0.007874015718698502f;
    fp1 += memoryFGet32(ds, eax + 0x43408c);
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp3 = 1.0f;
    fp2 += fp3;
    fp1 -= fp3;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp1 *= 0.5f;
    fp2 = fp0;
    fp2 *= 0.004999999888241291f;
    fp0 -= fp2;
    fp3 = fp1;
    fp1 *= fp3;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp1 *= fp2;
    fp0 += fp1;
    memoryFSet32(ds, esp + 0x30, fp0);
    fp0 = memoryFGet32(ds, edx + 0x10);
    memoryFSet32(ds, esp + 0x18, fp0);
    fp0 = memoryFGet32(ds, esp + 0x18);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    ebx = memoryAGet32(ds, esp + 0x10);
    ecx = ebx;
    ecx &= 0x00000007;
    edi = 0x00000001;
    edi <<= cl;
    ecx = (int8_t)memoryAGet(ds, esi + 0x26);
    memoryASet32(ds, esp + 0x18, ecx);
    ebx = sar32(ebx, 0x03);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, eax + 0x434090);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp1 *= 0.5f;
    fp0 -= fp1;
    memoryFSet32(ds, esp + 0x18, fp0);
    subopt_10019ea0();
    ecx = (int8_t)memoryAGet(ds, ebx + esi + 0x29);
    ecx &= edi;
    edx = eax;
    ebp = ecx;
    if (!memoryAGet(ds, esi + 0x21))
        goto loc_1001a0da;
    ebp = (int8_t)memoryAGet(ds, ebx + esi + 0x2d);
    ebp &= edi;
loc_1001a0da: // 0000:1001a0da
    eax = memoryAGet32(ds, esp + 0x14);
    edi = memoryAGet32(ds, eax + 0xe734);
    edi = (int8_t)memoryAGet(ds, edi + 0xc26);
    memoryASet32(ds, esp + 0x1c, edi);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    fp0 *= 0.007874015718698502f;
    fp0 += memoryFGet32(ds, eax + 0x4341c4);
    fp1 = fp0;
    fp1 = fabsf(fp1);
    fp2 = 1.0f;
    fp1 += fp2;
    fp0 -= fp2;
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    fp2 = fabsf(fp2);
    fp1 -= fp2;
    fp2 = 0.5f;
    fp1 *= fp2;
    fp3 = 0.0010000000474974513f;

    if (fp3 > fp1)  // fp3 vs fp1
        goto loc_1001a228;
    eax = (int8_t)memoryAGet(ds, esi + 0x23);
    bl = memoryAGet(ds, eax + edx);
    if (!bl)
        goto loc_1001a228;
    eax = (int8_t)memoryAGet(ds, esi + 0x23);
    edi = (int8_t)memoryAGet(ds, eax + edx);
    eax = memoryAGet32(ds, esp + 0x10);
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(edi);
    eax = edx;
    memoryASet32(ds, esp + 0x1c, eax);
    eax = edi;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ds, esp + 0x1c);
    eax = sar32(eax, 0x00000001);
    if (edx != eax)
        goto loc_1001a228;
    eax = (int8_t)bl;
    fp0 = fp2;
    ebx = memoryAGet32(ds, esp + 0x2c);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    eax = sar32(eax, 0x00000001);
    memoryASet32(ds, esp + 0x1c, eax);
    fp1 *= (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    fp0 *= fp1;
    fp0 = memoryFGet32(ds, ebx + 0x10) - fp0;
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp1 = 0.0f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_1001a19d;
    ecx = (int8_t)memoryAGet(ds, esi + 0x25);
    memoryASet32(ds, esp + 0x2c, ecx);
    fp0 += (double)(int32_t)memoryAGet32(ds, esp + 0x2c);
    memoryFSet32(ds, esp + 0x2c, fp0);
    goto loc_1001a19f;
loc_1001a19d: // 0000:1001a19d

loc_1001a19f: // 0000:1001a19f
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x10, (int32_t)floor(fp0));
    fp0 = 0.5f;
    edx = memoryAGet32(ds, esp + 0x10);
    fp1 = 1.0f;
    ecx = edx;
    ecx &= 0x00000007;
    eax = 0x00000001;
    eax <<= cl;
    edx = sar32(edx, 0x03);
    ebp = (int8_t)memoryAGet(ds, edx + esi + 0x29);
    ebp &= eax;
    ecx = ebp;
    if (!memoryAGet(ds, esi + 0x21))
        goto loc_1001a1d8;
    ebp = (int8_t)memoryAGet(ds, edx + esi + 0x2d);
    ebp &= eax;
loc_1001a1d8: // 0000:1001a1d8
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_1001a1da: // 0000:1001a1da
    edx = (int8_t)memoryAGet(ds, esi + 0x22);
    eax = memoryAGet32(ds, esp + 0x14);
    memoryASet32(ds, esp + 0x2c, edx);
    fp2 = (double)(int32_t)memoryAGet32(ds, esp + 0x2c);
    fp2 *= 0.007874015718698502f;
    fp2 += memoryFGet32(ds, eax + 0x434088);
    fp3 = fp2;
    fp3 = fabsf(fp3);
    fp3 += fp0;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp3 -= fp0;
    fp3 = fabsf(fp3);
    fp2 -= fp3;
    fp2 *= fp1;
    fp2 = fp0 - fp2;
    fp3 = fp2;
    memoryFSet32(ds, esp + 0x20, fp3);
    if (ecx == ebp)
        goto loc_1001a23a;
    if (!ecx)
        goto loc_1001a230;

    fp3 = fp0;
    fp3 -= fp2;
    fp3 *= memoryFGet32(ds, esp + 0x18);
    fp3 += fp2;
    memoryFSet32(ds, esp + 0x20, fp3);
    goto loc_1001a23a;
loc_1001a228: // 0000:1001a228
    ebx = memoryAGet32(ds, esp + 0x2c);
    fp1 = fp2;
    goto loc_1001a1da;
loc_1001a230: // 0000:1001a230
    fp4 = fp0;
    fp4 -= fp2;
    fp4 *= memoryFGet32(ds, esp + 0x18);
    fp2 += fp4;
loc_1001a23a: // 0000:1001a23a
    fp4 = 0.0f;
    _cmp2r = (double)fromFp32(memoryAGet32(ds, ebx));

    if (fp4 >= _cmp2r)  // fp4 vs (double)fromFp32(memoryAGet32(ds, ebx))
        goto loc_1001a255;
    fp2 = fp4;
    fp2 = fp3;

    fp2 = fp0;
    memoryFSet32(ds, esp + 0x20, fp2);
    fp3 = fp0;
    goto loc_1001a277;
loc_1001a255: // 0000:1001a255
    _cmp3r = (double)fromFp32(memoryAGet32(ds, ebx + 0x4));

    if (fp4 >= _cmp3r)  // fp4 vs (double)fromFp32(memoryAGet32(ds, ebx + 0x4))
        goto loc_1001a275;
    fp4 = fp0;
    fp4 -= fp2;
    fp4 *= memoryFGet32(ds, ebx + 0x4);
    fp2 += fp4;
    fp4 = fp0;
    fp4 -= fp3;
    fp4 *= memoryFGet32(ds, ebx + 0x4);
    fp3 += fp4;
    memoryFSet32(ds, esp + 0x20, fp3);
loc_1001a275: // 0000:1001a275
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
loc_1001a277: // 0000:1001a277
    if (!ecx)
        goto loc_1001a27f;

    fp3 = fp0;
loc_1001a27f: // 0000:1001a27f
    fp4 = memoryFGet32(ds, ebx + 0x8);
    edi = memoryAGet32(ds, esp + 0x28);
    esi = memoryAGet32(ds, esp + 0x34);
    fp5 = fp3;
    ecx = memoryAGet32(ds, edi);
    fp5 -= fp4;
    edx = esi;
    fp5 = fabsf(fp5);
    fp6 = 6.103515625e-05f;

    _cmp4r = fp5;
    fp5 = fp6;
    if (fp6 <= _cmp4r)  // fp6 vs fp5
        goto loc_1001a34b;
    fp4 = fp5;
    fp5 = fp3;
    memoryFSet32(ds, esp + 0x2c, fp5);
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }

    if (fp5 >= fp4)  // fp5 vs fp4
        goto loc_1001a319;
    fp3 = fp5;
    edx = (esi * 4) + 0;
    fp3 = fp4;
    push32(edx);
    fp0 = fp3;
    push32(0x00000000);
    fp1 = fp2;
    push32(ecx);
    fp0 = fp1;

    sub_100c8680();
    fp0 = memoryFGet32(ds, esp + 0x38);
    esp += 0x0000000c;
    fp1 = 6.103515625e-05f;
    fp2 = 0.5f;
    fp3 = 1.0f;
    fp4 = memoryFGet32(ds, esp + 0x20);
    fp5 = memoryFGet32(ds, esp + 0x30);
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp0; fp0 = _xchg; }
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }
    { double _xchg = fp5; fp5 = fp1; fp1 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    { double _xchg = fp5; fp5 = fp2; fp2 = _xchg; }
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
loc_1001a303: // 0000:1001a303
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    memoryFSet32(ds, ebx + 0x8, fp5);
    if (!ebp)
        goto loc_1001a3dc;
    fp2 = fp4;
    fp4 = fp0;
    goto loc_1001a3de;
loc_1001a319: // 0000:1001a319
    fp6 = fp0;
    fp6 -= fp5;
    fp6 = fabsf(fp6);

    if (fp6 < fp4)  // fp6 vs fp4
        goto loc_1001a3c4;
    if (!esi)
        goto loc_1001a3c4;
loc_1001a334: // 0000:1001a334
    fp6 = memoryFGet32(ds, ecx);
    edx--;
    fp6 *= fp5;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp6);
    if (edx)
        goto loc_1001a334;

    fp5 = memoryFGet32(ds, esp + 0x30);
    goto loc_1001a303;
loc_1001a34b: // 0000:1001a34b
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }

    if (fp5 >= fp4)  // fp5 vs fp4
        goto loc_1001a38c;
    if (!esi)
        goto loc_1001a3cf;
    fp6 = memoryFGet32(ds, esp + 0x30);
    goto loc_1001a362;
loc_1001a360: // 0000:1001a360
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }
loc_1001a362: // 0000:1001a362
    fp7 = memoryFGet32(ds, ecx);
    edx--;
    fp7 *= fp4;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp7);
    fp4 -= fp6;
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }
    fp6 -= fp5;
    fp7 = fp6;
    fp7 = fabsf(fp7);
    fp6 += fp7;
    fp6 *= fp1;
    fp6 += fp5;
    if (edx)
        goto loc_1001a360;
    fp5 = fp6;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    goto loc_1001a303;
loc_1001a38c: // 0000:1001a38c
    if (!esi)
        goto loc_1001a3cf;
    fp6 = memoryFGet32(ds, esp + 0x30);
    goto loc_1001a398;
loc_1001a396: // 0000:1001a396
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }
loc_1001a398: // 0000:1001a398
    fp7 = memoryFGet32(ds, ecx);
    edx--;
    fp7 *= fp4;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp7);
    fp4 += fp6;
    fp7 = fp5;
    fp4 = fp7 - fp4;
    fp7 = fp4;
    fp7 = fabsf(fp7);
    fp4 += fp7;
    { double _xchg = fp6; fp6 = fp4; fp4 = _xchg; }
    fp6 *= fp1;
    fp6 = fp5 - fp6;
    if (edx)
        goto loc_1001a396;
    fp5 = fp6;
    { double _xchg = fp5; fp5 = fp3; fp3 = _xchg; }
    { double _xchg = fp5; fp5 = fp4; fp4 = _xchg; }
    goto loc_1001a303;
loc_1001a3c4: // 0000:1001a3c4

    fp5 = memoryFGet32(ds, esp + 0x30);
    goto loc_1001a303;
loc_1001a3cf: // 0000:1001a3cf

    { double _xchg = fp4; fp4 = fp3; fp3 = _xchg; }
    fp5 = memoryFGet32(ds, esp + 0x30);
    goto loc_1001a303;
loc_1001a3dc: // 0000:1001a3dc
    { double _xchg = fp4; fp4 = fp2; fp2 = _xchg; }
loc_1001a3de: // 0000:1001a3de
    fp5 = memoryFGet32(ds, ebx + 0xc);
    ecx = memoryAGet32(ds, edi + 0x4);
    fp6 = fp4;
    edx = esi;
    fp6 -= fp5;
    fp6 = fabsf(fp6);

    if (fp6 >= fp2)  // fp6 vs fp2
        goto loc_1001a469;

    fp1 = fp4;

    fp3 = fp1;
    memoryFSet32(ds, esp + 0x2c, fp3);
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }

    if (fp3 >= fp2)  // fp3 vs fp2
        goto loc_1001a438;
    fp1 = fp3;
    eax = (esi * 4) + 0;
    push32(eax);
    fp1 = fp2;
    push32(0x00000000);
    fp0 = fp1;
    push32(ecx);

    sub_100c8680();
    fp0 = memoryFGet32(ds, esp + 0x38);
    esp += 0x0000000c;
    memoryFSet32(ds, ebx + 0xc, fp0);
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000014;
    esp += 20; return;
loc_1001a438: // 0000:1001a438
    fp0 -= fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 = fabsf(fp3);

    if (fp3 < fp2)  // fp3 vs fp2
        goto loc_1001a45a;
    if (!esi)
        goto loc_1001a45a;
loc_1001a44b: // 0000:1001a44b
    fp2 = memoryFGet32(ds, ecx);
    edx--;
    fp2 *= fp0;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp2);
    if (edx)
        goto loc_1001a44b;
loc_1001a45a: // 0000:1001a45a
    edi = pop32();
    fp0 = fp1;
    esi = pop32();
    memoryFSet32(ds, ebx + 0xc, fp0);
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000014;
    esp += 20; return;
loc_1001a469: // 0000:1001a469
    fp0 = fp5;
    fp2 = fp4;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }

    if (fp3 >= fp0)  // fp3 vs fp0
        goto loc_1001a4c3;
    if (esi)
        goto loc_1001a491;
loc_1001a47c: // 0000:1001a47c

    edi = pop32();
    fp1 = fp2;
    esi = pop32();

    ebp = pop32();
    memoryFSet32(ds, ebx + 0xc, fp0);
    ebx = pop32();
    esp += 0x00000014;
    esp += 20; return;
loc_1001a48f: // 0000:1001a48f
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
loc_1001a491: // 0000:1001a491
    fp4 = memoryFGet32(ds, ecx);
    edx--;
    fp4 *= fp0;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp4);
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 -= fp2;
    fp3 -= fp0;
    fp4 = fp3;
    fp4 = fabsf(fp4);
    fp3 += fp4;
    fp3 *= fp1;
    fp3 += fp0;
    if (edx)
        goto loc_1001a48f;
    fp0 = fp3;
    edi = pop32();
    fp1 = fp2;
    esi = pop32();

    ebp = pop32();
    memoryFSet32(ds, ebx + 0xc, fp0);
    ebx = pop32();
    esp += 0x00000014;
    esp += 20; return;
loc_1001a4c3: // 0000:1001a4c3
    if (!esi)
        goto loc_1001a47c;
    goto loc_1001a4cb;
loc_1001a4c9: // 0000:1001a4c9
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
loc_1001a4cb: // 0000:1001a4cb
    fp4 = memoryFGet32(ds, ecx);
    edx--;
    fp4 *= fp0;
    ecx += 0x00000004;
    memoryFSet32(ds, ecx - 4, fp4);
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp3 += fp2;
    fp3 = fp0 - fp3;
    fp4 = fp3;
    fp4 = fabsf(fp4);
    fp3 += fp4;
    fp3 *= fp1;
    fp3 = fp0 - fp3;
    if (edx)
        goto loc_1001a4c9;
    fp0 = fp3;
    edi = pop32();
    fp1 = fp2;
    esi = pop32();

    ebp = pop32();
    memoryFSet32(ds, ebx + 0xc, fp0);
    ebx = pop32();
    esp += 0x00000014;
    esp += 20;
}

void subopt_10019ea0() // 0000:10019ea0 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    eax = 0x100e763c;
    esp += 4;
}

void subopt_10058230() // 0000:10058230 +long +stackDrop4
{
    double fp0, fp3;
    float fp1, fp2, fp4;
    double _cmp1r;
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    fp0 = memoryFGet32(ds, esp + 0x4);
    fp0 *= 1.5707963705062866f;
    fp1 = fp0;
    fp2 = fp1;
    fp2 *= fp1;
    fp3 = -2.3900000201138027e-08f;
    fp3 *= fp2;
    fp3 += 2.7526000394573202e-06f;
    fp3 *= fp2;
    fp3 -= 0.00019840900495182723f;
    fp3 *= fp2;
    fp3 += 0.008333331905305386f;
    fp3 *= fp2;
    fp3 -= 0.1666666716337204f;
    fp2 *= fp3;
    fp3 = 1.0f;
    fp2 += fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp1 *= fp3;
    fp3 = 1e-10;

    fp4 = 0.0f;
    if (fp3 < fp1)  // fp3 vs fp1
        goto loc_10058287;
    fp1 = fp4;
    fp4 = fp1;
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
loc_10058287: // 0000:10058287
    { double _xchg = fp4; fp4 = fp1; fp1 = _xchg; }
    memoryFSet32(ds, ecx + 0x80, fp4);
    fp4 = fp0;
    fp0 *= fp4;
    fp4 = fp0;
    fp4 *= -2.605000020139414e-07f;
    fp4 += 2.476090048730839e-05f;
    fp4 *= fp0;
    fp4 -= 0.001388839678838849f;
    fp4 *= fp0;
    fp4 += 0.04166664183139801f;
    fp4 *= fp0;
    fp4 -= 0.5f;
    fp0 *= fp4;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp2 += fp3;

    _cmp1r = fp0;
    fp0 = fp2;
    if (fp2 <= _cmp1r)  // fp2 vs fp0
        goto loc_100582d5;

    memoryFSet32(ds, ecx + 0x84, fp0);
    esp += 8; return;
loc_100582d5: // 0000:100582d5
    fp0 = fp1;
    memoryFSet32(ds, ecx + 0x84, fp0);
    esp += 8;
}

void subopt_10062c60() // 0000:10062c60 +long +stackDrop8
{
    float fp0, fp1, fp2, fp3;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    fp0 = memoryFGet32(ds, esp + 0x8);
    push32(esi);
    esi = ecx;
    memoryFSet32(ds, esi + eax * 4 + 0x18c, fp0);
    eax--;
    if (eax > 0x0000000f)
        goto loc_10062de8;
    ecx = memoryAGet(ds, eax + 0x10062e0c);
    switch (memoryAGet32(ds, ecx * 4 + 0x10062df0))
    {
        case 0x10062c8a: goto loc_10062c8a;
        case 0x10062ccc: goto loc_10062ccc;
        case 0x10062cdc: goto loc_10062cdc;
        case 0x10062d0a: goto loc_10062d0a;
        case 0x10062d2c: goto loc_10062d2c;
        case 0x10062d8b: goto loc_10062d8b;
        case 0x10062de8: goto loc_10062de8;
        default:
            stop("unhandled indirect 0000:10062c83");
    }
loc_10062c8a: // 0000:10062c8a
    edx = memoryAGet32(ds, esi);

    eax = memoryAGet32(ds, edx + 0x60);
    ecx = esi;
    switch (eax)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:10062c93");
    }
    if (!al)
        goto loc_10062ca2;
    edx = memoryAGet32(ds, esi);
    eax = memoryAGet32(ds, edx + 0x4);
    ecx = esi;
    switch (eax)
    {
        case 0x10062760: subopt_10062760(); break;
        default:
            stop("unhandled indirect 0000:10062ca0");
    }
loc_10062ca2: // 0000:10062ca2
    fp0 = memoryFGet32(ds, esi + 0x190);
    push32(ecx);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    ecx = esi;
    subopt_100629a0();
    fp0 = memoryFGet32(ds, esi + 0x194);
    push32(ecx);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    ecx = esi;
    subopt_100629a0();
    esi = pop32();
    esp += 12; return;
loc_10062ccc: // 0000:10062ccc
    push32(ecx);
    memoryFSet32(ds, esp, fp0);
    push32(eax);
    ecx = esi;
    subopt_100629a0();
    esi = pop32();
    esp += 12; return;
loc_10062cdc: // 0000:10062cdc
    push32(ecx);
    memoryFSet32(ds, esi + 0x190, fp0);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000000);
    ecx = esi;
    subopt_100629a0();
    fp0 = memoryFGet32(ds, esp + 0xc);
    push32(ecx);
    memoryFSet32(ds, esi + 0x194, fp0);
    memoryFSet32(ds, esp, fp0);
    push32(0x00000001);
    ecx = esi;
    subopt_100629a0();
    esi = pop32();
    esp += 12; return;
loc_10062d0a: // 0000:10062d0a
    memoryFSet32(ds, esi + 0x1a4, fp0);
    memoryFSet32(ds, esi + 0x1a8, fp0);
    fp0 *= 0.949999988079071f;
    memoryFSet32(ds, esi + 0xc8, fp0);
    memoryFSet32(ds, esi + 0xfc, fp0);
    esi = pop32();
    esp += 12; return;
loc_10062d2c: // 0000:10062d2c
    memoryFSet32(ds, esi + 0x1b0, fp0);
    memoryFSet32(ds, esi + 0x1b4, fp0);
    fp0 *= fp0;
    fp1 = 1.0f;
    fp0 = fp1 - fp0;
    fp1 = 44100.0f;
    fp1 /= memoryFGet32(ds, esi + 0x70);
    fp0 *= fp1;
    fp1 = fp0;
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp3 = 0.9900000095367432f;
    fp2 += fp3;
    fp1 -= fp3;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp3 = fabsf(fp3);
    fp2 -= fp3;
    fp3 = 0.5f;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, esi + 0xd4, fp3);
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esi + 0x108, fp0);
    esi = pop32();
    esp += 12; return;
loc_10062d8b: // 0000:10062d8b
    memoryFSet32(ds, esi + 0x1bc, fp0);
    memoryFSet32(ds, esi + 0x1c0, fp0);
    fp1 = 44100.0f;
    fp1 /= memoryFGet32(ds, esi + 0x70);
    fp2 = fp0;
    fp0 *= fp2;
    fp0 *= fp1;
    fp1 = fp0;
    fp2 = fp1;
    fp2 = fabsf(fp2);
    fp3 = 0.9900000095367432f;
    fp2 += fp3;
    fp1 -= fp3;
    { double _xchg = fp3; fp3 = fp1; fp1 = _xchg; }
    fp3 = fabsf(fp3);
    fp2 -= fp3;
    fp3 = 0.5f;
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    memoryFSet32(ds, esi + 0xd0, fp3);
    fp3 = fp0;
    fp3 = fabsf(fp3);
    fp3 += fp1;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp1 = fp3 - fp1;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 = fabsf(fp2);
    fp0 -= fp2;
    fp0 *= fp1;
    memoryFSet32(ds, esi + 0x104, fp0);
    esi = pop32();
    esp += 12; return;
loc_10062de8: // 0000:10062de8

    esi = pop32();
    esp += 12;
}

void subopt_10062760() // 0000:10062760 +long
{
    double fp0, fp1;
    double _cmp0r, _cmp0l;
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    goto loc_10062760;
loc_10007230: // 0000:10007230
    al = memoryAGet(ds, ecx + 0x8d);
    esp += 4; return;
    // gap 374057 bytes // gap 374057 bytes
loc_10062760: // 0000:10062760
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:10062768");
    }
    if (!al)
        goto loc_10062772;
    al = 0x01;
    esi = pop32();
    esp += 4; return;
loc_10062772: // 0000:10062772
    fp0 = 0.5f;
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0x1cc));

    _cmp0l = fp0;
    fp0 = memoryFGet32(ds, esi + 0x70);
    if (_cmp0l > _cmp0r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0x1cc))
        goto loc_10062790;
    fp0 *= 5.0f;
    goto loc_10062796;
loc_10062790: // 0000:10062790
    fp0 *= 10.0f;
loc_10062796: // 0000:10062796
    sub_100ca3c0(fp0);
    push32(ebx);
    push32(ebp);
    push32(edi);
    memoryASet32(ds, esi + 0x1d0, eax);
    ebx = esi + 328;
    edi = esi + 204;
    ebp = 0x00000002;
loc_100627b5: // 0000:100627b5
    eax = memoryAGet32(ds, esi + 0x1d0);
    push32(eax);
    ecx = edi - 32;
    subopt_10068620();
    fp0 = 1.0f;
    fp0 /= memoryFGet32(ds, esi + 0x70);
    fp1 = 0.00390625;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp0 = sub_100caaf0(fp1, fp0);
    fp1 = 1.0f;
    fp0 = fp1 - fp0;
    memoryFSet32(ds, edi, fp0);
    fp0 = memoryFGet32(ds, esi + 0x70);
    fp0 *= 0.014999999664723873f;
    sub_100ca3c0(fp0);
    push32(eax);
    ecx = ebx - 52;
    subopt_10068620();
    fp0 = 0.0f;
    memoryFSet32(ds, ebx, fp0);
    edi += 0x00000034;
    ebx += 0x0000003c;
    ebp--;
    if (ebp)
        goto loc_100627b5;
    edx = memoryAGet32(ds, esi);
    eax = memoryAGet32(ds, edx + 0x60);
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    memoryASet(ds, esi + 0x8d, 0x01);
    ecx = esi;
    esi = pop32();
    switch (eax)
    {
        case 0x10007230: goto loc_10007230;
        default:
            stop("unhandled indirect 0000:10062814");
    }
}

void subopt_10068620() // 0000:10068620 +long +stackDrop4
{
    StackGuard _sg(4, __FUNCTION__);
    esp -= 4;
    push32(ebx);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x10);
    esi = ecx;
    ebx = 0;
    if (memoryAGet32(ds, esi + 0x2c) != edi)
        goto loc_1006863d;
    if (memoryAGet32(ds, esi + 0x4) == ebx)
        goto loc_1006863d;
    edi = pop32();
    esi = pop32();
    al = 0x01;
    ebx = pop32();
    esp += 8; return;
loc_1006863d: // 0000:1006863d
    eax = memoryAGet32(ds, esi + 0x4);
    if (eax == ebx)
        goto loc_1006864d;
    push32(eax);
    sub_100c91bc();
    esp += 0x00000004;
loc_1006864d: // 0000:1006864d
    memoryASet32(ds, esi + 0x4, ebx);
    memoryASet32(ds, esi, ebx);
    memoryASet32(ds, esi + 0x8, ebx);
    memoryASet(ds, esi + 0x30, bl);
    memoryASet32(ds, esi + 0x2c, edi);
    if (edi == ebx)
        goto loc_10068697;
    eax = (edi * 4) + 0;
    push32(eax);
    sub_100c8749();
    esp += 0x00000004;
    memoryASet32(ds, esi + 0x4, eax);
    memoryASet32(ds, esi, eax);
    if (eax != ebx)
        goto loc_1006867b;
    memoryASet32(ds, esi + 0x2c, ebx);
loc_1006867b: // 0000:1006867b
    ecx = memoryAGet32(ds, esi + 0x2c);
    ecx += ecx;
    ecx += ecx;
    edx = ecx + eax;
    memoryASet32(ds, esi + 0x8, edx);
    if (eax == ebx)
        goto loc_10068697;
    push32(ecx);
    push32(ebx);
    push32(eax);
    sub_100c8680();
    esp += 0x0000000c;
loc_10068697: // 0000:10068697
    eax = 0;
    flags.zero = memoryAGet32(ds, esi + 0x4) == ebx;
    edi = pop32();
    esi = pop32();
    al = !flags.zero;
    ebx = pop32();
    esp += 8;
}

void subopt_100629a0() // 0000:100629a0 +long +stackDrop8
{
    float fp0, fp1, fp2, fp3;
    double _cmp0r, _cmp0l, _cmp1r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    memoryASet32(ds, esi + 0x1d4, 0x00000000);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:100629b2");
    }
    if (!al)
        goto loc_10062b3f;
    fp0 = 0.5f;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0xc);
    push32(edi);
    if (!memoryAGet(ds, esi + 0x8f))
        goto loc_10062a46;
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0x1cc));

    _cmp0l = fp0;
    fp0 = memoryFGet32(ds, esp + 0x14);
    if (_cmp0l > _cmp0r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0x1cc))
        goto loc_100629fc;
    fp0 *= -17.989999771118164f;
    sub_100ca3c0(fp0);
    eax += eax;
    eax += eax;
    ecx = 0x103d3fa8;
    ecx -= eax;
    fp0 = memoryFGet32(ds, ecx);
    goto loc_10062a14;
loc_100629fc: // 0000:100629fc
    fp0 *= -26.989999771118164f;
    sub_100ca3c0(fp0);
    eax += eax;
    eax += eax;
    edx = 0x103d3f38;
    edx -= eax;
    fp0 = memoryFGet32(ds, edx);
loc_10062a14: // 0000:10062a14
    fp0 *= 240.0f;
    fp0 *= memoryFGet32(ds, esi + 0x70);
    fp0 /= memoryFGet32(ds, esi + 0x7c);
    sub_100ca3c0(fp0);
    edi = eax;
    memoryASet32(ds, esp + 0x14, edi);
    if (edi)
        goto loc_10062ac2;
    eax = memoryAGet32(ds, esi + 0x1d0);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edi = eax;
    edi = sar32(edi, 0x00000001);
    memoryASet32(ds, esp + 0x14, edi);
    goto loc_10062ac2;
loc_10062a46: // 0000:10062a46
    _cmp1r = (double)fromFp32(memoryAGet32(ds, esi + 0x1cc));

    fp1 = memoryFGet32(ds, esp + 0x14);
    if (fp0 > _cmp1r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0x1cc))
        goto loc_10062a5f;
    fp1 *= 4.999000072479248f;
    goto loc_10062a65;
loc_10062a5f: // 0000:10062a5f
    fp1 *= 9.99899959564209f;
loc_10062a65: // 0000:10062a65
    fp2 = 0.0010000000474974513f;
    fp1 += fp2;
    if (!(bl & 0x01))
        goto loc_10062abc;
    fp3 = memoryFGet32(ds, esi + 0x18c);
    sub_100ca3c0(fp3);
    if (eax == 0x00000003)
        goto loc_10062a94;
    eax += 0xfffffffc;
    fp0 = fp2;
    if (eax > 0x00000001)
        goto loc_10062a9a;
    fp1 *= 0.009999999776482582f;
    goto loc_10062a9a;
loc_10062a94: // 0000:10062a94
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp0 *= fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
loc_10062a9a: // 0000:10062a9a
    fp1 *= memoryFGet32(ds, esi + 0x70);
    sub_100ca3c0(fp1);
    edi = eax;
    memoryASet32(ds, esp + 0x14, edi);
    if (edi)
        goto loc_10062ac0;
    fp0 *= memoryFGet32(ds, esi + 0x70);
    sub_100ca3c0(fp0);
    edi = eax;
    memoryASet32(ds, esp + 0x14, edi);
    goto loc_10062ac2;
loc_10062abc: // 0000:10062abc
    fp0 = fp2;
    goto loc_10062a9a;
loc_10062ac0: // 0000:10062ac0

loc_10062ac2: // 0000:10062ac2
    if (!(bl & 0x01))
        goto loc_10062aec;
    fp0 = memoryFGet32(ds, esi + 0x18c);
    sub_100ca3c0(fp0);
    if ((int32_t)eax < (int32_t)0x00000004)
        goto loc_10062aec;
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    fp0 *= memoryFGet32(ds, esi + 0x19c);
    sub_100ca3c0(fp0);
    edi += eax;
    memoryASet32(ds, esp + 0x14, edi);
loc_10062aec: // 0000:10062aec
    if ((int32_t)edi <= (int32_t)memoryAGet32(ds, esi + 0x1d0))
        goto loc_10062b0a;
    eax = memoryAGet32(ds, esi + 0x1d0);
    ebx = ebx;
loc_10062b00: // 0000:10062b00
    edi = sar32(edi, 0x00000001);
    if ((int32_t)edi > (int32_t)eax)
        goto loc_10062b00;
    memoryASet32(ds, esp + 0x14, edi);
loc_10062b0a: // 0000:10062b0a
    if ((int32_t)memoryAGet32(ds, esi + 0x1d4) >= (int32_t)edi)
        goto loc_10062b18;
    memoryASet32(ds, esi + 0x1d4, edi);
loc_10062b18: // 0000:10062b18
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x14);
    al = memoryAGet(ds, esi + 0x8c) == 0x00;
    ebx = (int32_t)ebx * (int32_t)0x00000034;
    ecx = al;
    push32(ecx);
    push32(ecx);
    ecx = (ebx + esi) + 172;
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    edi = pop32();
    ebx = pop32();
loc_10062b3f: // 0000:10062b3f
    esi = pop32();
    esp += 12;
}

void subopt_10062f90() // 0000:10062f90 +long +stackDrop16
{
    float fp0, fp1, fp2, fp3;
    StackGuard _sg(16, __FUNCTION__);
    esp -= 4;
    esp -= 0x00000020;
    push32(esi);
    esi = ecx;
    eax = memoryAGet32(ds, esi);
    edx = memoryAGet32(ds, eax + 0x60);
    switch (edx)
    {
        case 0x10007230: subopt_10007230(); break;
        default:
            stop("unhandled indirect 0000:10062f9b");
    }
    if (!al)
        goto loc_10063e02;
    eax = memoryAGet32(ds, esp + 0x2c);
    fp0 = memoryFGet32(ds, esi + 0x84);
    push32(ebx);
    memoryFSet32(ds, esp + 0xc, fp0);
    ebx = memoryAGet32(ds, eax);
    fp1 = memoryFGet32(ds, esi + 0x80);
    eax = memoryAGet32(ds, eax + 0x4);
    memoryFSet32(ds, esp + 0x10, fp1);
    memoryASet32(ds, esp + 0x30, eax);
    eax = memoryAGet32(ds, esp + 0x2c);
    ecx = memoryAGet32(ds, eax + 0x4);
    push32(ebp);
    ebp = memoryAGet32(ds, eax);
    memoryASet32(ds, esp + 0xc, ebp);
    memoryASet32(ds, esp + 0x30, ecx);
    if (ebx != ebp)
        goto loc_10062fe9;
    fp1 = 1.0f;
    fp0 = fp1 - fp0;
    fp0 = -fp0;
    memoryFSet32(ds, esp + 0x10, fp0);
    goto loc_10062feb;
loc_10062fe9: // 0000:10062fe9

loc_10062feb: // 0000:10062feb
    fp0 = memoryFGet32(ds, esi + 0x18c);
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, esp + 0x24);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    if (eax > 0x00000005)
        goto loc_10063e00;
    push32(edi);
    switch (eax)
    {
        case 0: goto loc_10063012;
        case 1: goto loc_100631b1;
        case 2: goto loc_1006344f;
        case 3: goto loc_100636fa;
        case 4: goto loc_1006398a;
        case 5: goto loc_10063bb0;
        default:
            stop("unhandled indirect 0000:1006300b");
    }
loc_10063012: // 0000:10063012
    fp0 = memoryFGet32(ds, esi + 0x1c8);
    fp0 *= 0.33000001311302185f;
    memoryFSet32(ds, esi + 0x14c, fp0);
    memoryFSet32(ds, esi + 0x188, fp0);
    if (!memoryAGet32(ds, esp + 0x3c))
        goto loc_10063dff;
loc_10063035: // 0000:10063035
    fp0 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x38);
    memoryFSet32(ds, esp + 0x20, fp0);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    fp1 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x2c, fp1);
    ebx += 0x00000004;
    fp0 += fp1;
    memoryASet32(ds, esp + 0x38, eax);
    fp0 *= 0.5f;
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, esi + 0xc0);
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esi + 0xac);
    edi = memoryAGet32(ds, esi + 0xb0);
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_100630c6;
    ebp = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x10);
loc_100630c6: // 0000:100630c6
    if (eax >= edi)
        goto loc_100630d3;
    edi = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edi * 4);
loc_100630d3: // 0000:100630d3
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xb8, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xc8);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x24);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + 0x00000004);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_10063154;
    edx = memoryAGet32(ds, esi + 0xd8);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xac, eax);
loc_10063154: // 0000:10063154
    eax = esi + 276;
    push32(eax);
    push32(ecx);
    ecx = esi;
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x20);
    eax = memoryAGet32(ds, esp + 0x34);
    fp2 = memoryFGet32(ds, esp + 0x14);
    ebp += 0x00000004;
    fp1 *= fp2;
    eax += 0x00000004;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    memoryASet32(ds, esp + 0x10, ebp);
    fp2 += fp0;
    memoryASet32(ds, esp + 0x34, eax);
    fp2 += memoryFGet32(ss, ebp - 4);
    memoryFSet32(ss, ebp - 4, fp2);
    fp1 *= memoryFGet32(ds, esp + 0x2c);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp0);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_10063035;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_100631b1: // 0000:100631b1
    fp0 = memoryFGet32(ds, esi + 0x1c8);
    fp0 *= 0.33000001311302185f;
    memoryFSet32(ds, esi + 0x14c, fp0);
    memoryFSet32(ds, esi + 0x188, fp0);
    if (!memoryAGet32(ds, esp + 0x3c))
        goto loc_10063dff;
loc_100631d4: // 0000:100631d4
    fp0 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x38);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x28, fp0);
    ebx += 0x00000004;
    fp0 = memoryFGet32(ds, esi + 0xc0);
    memoryASet32(ds, esp + 0x38, eax);
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esi + 0xac);
    edi = memoryAGet32(ds, esi + 0xb0);
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10063259;
    ebp = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x10);
loc_10063259: // 0000:10063259
    if (eax >= edi)
        goto loc_10063266;
    edi = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edi * 4);
loc_10063266: // 0000:10063266
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xb8, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xc8);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x24);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + 0x00000004);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_100632e7;
    edx = memoryAGet32(ds, esi + 0xd8);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xac, eax);
loc_100632e7: // 0000:100632e7
    eax = esi + 276;
    push32(eax);
    push32(ecx);
    ecx = esi;
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x24);
    ebp += 0x00000004;
    fp1 *= memoryFGet32(ds, esp + 0x14);
    memoryASet32(ds, esp + 0x10, ebp);
    fp0 += fp1;
    fp0 += memoryFGet32(ss, ebp - 4);
    memoryFSet32(ss, ebp - 4, fp0);
    fp0 = memoryFGet32(ds, esi + 0xf4);
    fp0 -= memoryFGet32(ds, esi + 0xf8);
    fp0 *= memoryFGet32(ds, esi + 0x100);
    fp0 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x20);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0xe0);
    edi = memoryAGet32(ds, esi + 0xe4);
    fp0 = memoryFGet32(ds, esi + 0xf8) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_1006337b;
    ebp = memoryAGet32(ds, esi + 0x10c);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x10);
loc_1006337b: // 0000:1006337b
    if (eax >= edi)
        goto loc_10063388;
    edi = memoryAGet32(ds, esi + 0x10c);
    eax = eax + (edi * 4);
loc_10063388: // 0000:10063388
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xf0);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x108);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xf0, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xec);
    fp2 *= memoryFGet32(ds, esi + 0x104);
    fp2 += memoryFGet32(ds, esi + 0xec);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xec, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xfc);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x28);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xe0, memoryAGet32(ds, esi + 0xe0) + 0x00000004);
    eax = memoryAGet32(ds, esi + 0xe0);
    if (eax < memoryAGet32(ds, esi + 0xe8))
        goto loc_10063409;
    edx = memoryAGet32(ds, esi + 0x10c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xe0, eax);
loc_10063409: // 0000:10063409
    eax = esi + 336;
    push32(eax);
    push32(ecx);
    ecx = esi;
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x28);
    eax = memoryAGet32(ds, esp + 0x34);
    fp1 *= memoryFGet32(ds, esp + 0x14);
    eax += 0x00000004;
    memoryASet32(ds, esp + 0x34, eax);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, eax - 4);
    memoryFSet32(ds, eax - 4, fp0);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_100631d4;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_1006344f: // 0000:1006344f
    fp0 = memoryFGet32(ds, esi + 0x1c8);
    fp0 *= 0.33000001311302185f;
    memoryFSet32(ds, esi + 0x14c, fp0);
    memoryFSet32(ds, esi + 0x188, fp0);
    if (!memoryAGet32(ds, esp + 0x3c))
        goto loc_10063dff;
    edi = 0x00000004;
    goto loc_10063480;
    // gap 7 bytes // gap 7 bytes
loc_10063480: // 0000:10063480
    fp0 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x38);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, eax);
    eax += edi;
    memoryFSet32(ds, esp + 0x10, fp0);
    ebx += edi;
    fp0 = memoryFGet32(ds, esi + 0xc0);
    memoryASet32(ds, esp + 0x38, eax);
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x20);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0xb0);
    ecx = (eax * 4) + 0;
    eax = memoryAGet32(ds, esi + 0xac);
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp0 = fp1 - fp0;
    if (ecx >= edx)
        goto loc_100634fd;
    edi = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (edi * 4);
loc_100634fd: // 0000:100634fd
    if (eax >= edx)
        goto loc_1006350a;
    edx = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edx * 4);
loc_1006350a: // 0000:1006350a
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xb8, fp1);
    fp0 -= fp1;
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, esi + 0xf4);
    fp0 -= memoryFGet32(ds, esi + 0xf8);
    fp0 *= memoryFGet32(ds, esi + 0x100);
    fp0 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esi + 0xe4);
    ecx = (eax * 4) + 0;
    eax = memoryAGet32(ds, esi + 0xe0);
    fp0 = memoryFGet32(ds, esi + 0xf8) - fp0;
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp0 = fp1 - fp0;
    if (ecx >= edx)
        goto loc_100635b7;
    edi = memoryAGet32(ds, esi + 0x10c);
    ecx = ecx + (edi * 4);
loc_100635b7: // 0000:100635b7
    if (eax >= edx)
        goto loc_100635c4;
    edx = memoryAGet32(ds, esi + 0x10c);
    eax = eax + (edx * 4);
loc_100635c4: // 0000:100635c4
    fp1 = memoryFGet32(ds, eax);
    edi = 0x00000004;
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xf0);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x108);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xf0, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xec);
    fp2 *= memoryFGet32(ds, esi + 0x104);
    fp2 += memoryFGet32(ds, esi + 0xec);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xec, fp2);
    eax = memoryAGet32(ds, esi + 0xac);
    fp1 -= fp2;
    fp2 = fp1;
    fp2 *= memoryFGet32(ds, esi + 0xc8);
    fp2 += memoryFGet32(ds, esp + 0x28);
    fp2 += fp0;
    memoryFSet32(ds, eax, fp2);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + edi);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_1006364b;
    ecx = memoryAGet32(ds, esi + 0xd8);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi + 0xac, eax);
loc_1006364b: // 0000:1006364b
    fp2 = memoryFGet32(ds, esi + 0xfc);
    edx = memoryAGet32(ds, esi + 0xe0);
    fp2 *= memoryFGet32(ds, esp + 0x24);
    fp2 += memoryFGet32(ds, esp + 0x10);
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xe0, memoryAGet32(ds, esi + 0xe0) + edi);
    eax = memoryAGet32(ds, esi + 0xe0);
    if (eax < memoryAGet32(ds, esi + 0xe8))
        goto loc_1006368b;
    ecx = memoryAGet32(ds, esi + 0x10c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi + 0xe0, eax);
loc_1006368b: // 0000:1006368b
    eax = esi + 336;
    push32(eax);
    push32(ecx);
    ecx = esi;
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 *= memoryFGet32(ds, esp + 0x18);
    fp1 = memoryFGet32(ds, esp + 0x28);
    eax = esi + 276;
    fp1 *= memoryFGet32(ds, esp + 0x14);
    push32(eax);
    push32(ecx);
    ecx = esi;
    fp0 += fp1;
    fp0 += memoryFGet32(ss, ebp);
    memoryFSet32(ss, ebp, fp0);
    ebp += edi;
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 *= memoryFGet32(ds, esp + 0x18);
    eax = memoryAGet32(ds, esp + 0x34);
    fp1 = memoryFGet32(ds, esp + 0x10);
    fp1 *= memoryFGet32(ds, esp + 0x14);
    fp0 += fp1;
    fp0 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp0);
    eax += edi;
    memoryASet32(ds, esp + 0x34, eax);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_10063480;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_100636fa: // 0000:100636fa
    fp0 = memoryFGet32(ds, esi + 0x1c8);
    memoryFSet32(ds, esi + 0x14c, fp0);
    if (!memoryAGet32(ds, esp + 0x3c))
        goto loc_10063dff;
    edi = 0x00000004;
loc_10063716: // 0000:10063716
    fp0 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x38);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    memoryFSet32(ds, esp + 0x24, fp0);
    fp0 = memoryFGet32(ds, eax);
    eax += edi;
    memoryFSet32(ds, esp + 0x10, fp0);
    ebx += edi;
    fp0 = memoryFGet32(ds, esi + 0xc0);
    memoryASet32(ds, esp + 0x38, eax);
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    edx = memoryAGet32(ds, esp + 0x20);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    eax = memoryAGet32(ds, esi + 0xac);
    ecx = (edx * 4) + 0;
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    edx = memoryAGet32(ds, esi + 0xb0);
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp0 = fp1 - fp0;
    if (ecx >= edx)
        goto loc_10063793;
    edi = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (edi * 4);
loc_10063793: // 0000:10063793
    if (eax >= edx)
        goto loc_100637a0;
    edx = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edx * 4);
loc_100637a0: // 0000:100637a0
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xb8, fp1);
    fp0 -= fp1;
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esi + 0xf4);
    fp0 -= memoryFGet32(ds, esi + 0xf8);
    fp0 *= memoryFGet32(ds, esi + 0x100);
    fp0 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esi + 0xe4);
    ecx = (eax * 4) + 0;
    eax = memoryAGet32(ds, esi + 0xe0);
    fp0 = memoryFGet32(ds, esi + 0xf8) - fp0;
    fp1 = 1.0f;
    eax -= ecx;
    ecx = eax - 4;
    fp0 = fp1 - fp0;
    if (ecx >= edx)
        goto loc_1006384d;
    edi = memoryAGet32(ds, esi + 0x10c);
    ecx = ecx + (edi * 4);
loc_1006384d: // 0000:1006384d
    if (eax >= edx)
        goto loc_1006385a;
    edx = memoryAGet32(ds, esi + 0x10c);
    eax = eax + (edx * 4);
loc_1006385a: // 0000:1006385a
    fp1 = memoryFGet32(ds, eax);
    edi = 0x00000004;
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xf0);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x108);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xf0, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xec);
    fp2 *= memoryFGet32(ds, esi + 0x104);
    fp2 += memoryFGet32(ds, esi + 0xec);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xec, fp2);
    eax = memoryAGet32(ds, esi + 0xac);
    fp1 -= fp2;
    memoryFSet32(ds, esp + 0x2c, fp1);
    fp2 = memoryFGet32(ds, esp + 0x10);
    fp2 += memoryFGet32(ds, esp + 0x24);
    fp2 *= 0.5f;
    { double _xchg = fp2; fp2 = fp1; fp1 = _xchg; }
    fp2 *= memoryFGet32(ds, esi + 0xc8);
    fp1 += fp2;
    fp0 += fp1;
    memoryFSet32(ds, eax, fp0);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + edi);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_100638f1;
    ecx = memoryAGet32(ds, esi + 0xd8);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi + 0xac, eax);
loc_100638f1: // 0000:100638f1
    fp0 = memoryFGet32(ds, esp + 0x28);
    eax = esi + 276;
    push32(eax);
    push32(ecx);
    ecx = esi;
    memoryFSet32(ds, esp, fp0);
    fp0 = subopt2_10062e20();
    fp0 += 1.000000045813705e-18f;
    edx = memoryAGet32(ds, esi + 0xe0);
    memoryFSet32(ds, edx, fp0);
    memoryASet32(ds, esi + 0xe0, memoryAGet32(ds, esi + 0xe0) + edi);
    eax = memoryAGet32(ds, esi + 0xe0);
    if (eax < memoryAGet32(ds, esi + 0xe8))
        goto loc_1006393b;
    ecx = memoryAGet32(ds, esi + 0x10c);
    ecx += ecx;
    ecx += ecx;
    eax -= ecx;
    memoryASet32(ds, esi + 0xe0, eax);
loc_1006393b: // 0000:1006393b
    fp0 = memoryFGet32(ds, esp + 0x28);
    eax = memoryAGet32(ds, esp + 0x34);
    fp1 = memoryFGet32(ds, esp + 0x18);
    fp0 *= fp1;
    fp2 = memoryFGet32(ds, esp + 0x24);
    fp3 = memoryFGet32(ds, esp + 0x14);
    fp2 *= fp3;
    { double _xchg = fp3; fp3 = fp0; fp0 = _xchg; }
    fp2 += fp3;
    fp2 += memoryFGet32(ss, ebp);
    memoryFSet32(ss, ebp, fp2);
    ebp += edi;
    fp1 *= memoryFGet32(ds, esp + 0x2c);
    fp2 = memoryFGet32(ds, esp + 0x10);
    fp0 *= fp2;
    fp0 += fp1;
    fp0 += memoryFGet32(ds, eax);
    memoryFSet32(ds, eax, fp0);
    eax += edi;
    memoryASet32(ds, esp + 0x34, eax);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_10063716;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_1006398a: // 0000:1006398a
    ebx = memoryAGet32(ds, esp + 0x3c);
    if (!ebx)
        goto loc_10063dff;
    ebp = 0x00000004;
    goto loc_100639a0;
    // gap 3 bytes // gap 3 bytes
loc_100639a0: // 0000:100639a0
    fp0 = memoryFGet32(ds, esi + 0xc0);
    ebx--;
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x3c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x3c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x3c);
    edx = memoryAGet32(ds, esi + 0xac);
    edi = memoryAGet32(ds, esi + 0xb0);
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10063a09;
    ebp = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (ebp * 4);
    ebp = 0x00000004;
loc_10063a09: // 0000:10063a09
    if (eax >= edi)
        goto loc_10063a16;
    edi = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edi * 4);
loc_10063a16: // 0000:10063a16
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xb8, fp2);
    fp1 -= fp2;
    fp1 *= memoryFGet32(ds, esi + 0xc8);
    fp0 += fp1;
    memoryFSet32(ds, edx, fp0);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + ebp);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_10063a8c;
    edx = memoryAGet32(ds, esi + 0xd8);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xac, eax);
loc_10063a8c: // 0000:10063a8c
    eax = memoryAGet32(ds, esp + 0x38);
    fp0 = memoryFGet32(ds, eax);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, esi + 0xf4);
    fp0 -= memoryFGet32(ds, esi + 0xf8);
    fp0 *= memoryFGet32(ds, esi + 0x100);
    fp0 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    ecx = memoryAGet32(ds, esp + 0x20);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0xe0);
    edi = memoryAGet32(ds, esi + 0xe4);
    fp0 = memoryFGet32(ds, esi + 0xf8) - fp0;
    ecx += ecx;
    fp1 = 1.0f;
    ecx += ecx;
    eax = edx;
    fp0 = fp1 - fp0;
    eax -= ecx;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10063afb;
    ebp = memoryAGet32(ds, esi + 0x10c);
    ecx = ecx + (ebp * 4);
    ebp = 0x00000004;
loc_10063afb: // 0000:10063afb
    if (eax >= edi)
        goto loc_10063b08;
    edi = memoryAGet32(ds, esi + 0x10c);
    eax = eax + (edi * 4);
loc_10063b08: // 0000:10063b08
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xf0);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x108);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xf0, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xec);
    fp2 *= memoryFGet32(ds, esi + 0x104);
    fp2 += memoryFGet32(ds, esi + 0xec);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xec, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xfc);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x28);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xe0, memoryAGet32(ds, esi + 0xe0) + ebp);
    eax = memoryAGet32(ds, esi + 0xe0);
    if (eax < memoryAGet32(ds, esi + 0xe8))
        goto loc_10063b88;
    edx = memoryAGet32(ds, esi + 0x10c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xe0, eax);
loc_10063b88: // 0000:10063b88
    fp0 *= 1.2999999523162842f;
    eax = memoryAGet32(ds, esp + 0x34);
    memoryASet32(ds, esp + 0x38, memoryAGet32(ds, esp + 0x38) + ebp);
    memoryFSet32(ds, eax, fp0);
    eax += ebp;
    memoryASet32(ds, esp + 0x34, eax);
    if (ebx)
        goto loc_100639a0;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esi = pop32();
    esp += 0x00000020;
    esp += 20; return;
loc_10063bb0: // 0000:10063bb0
    if (!memoryAGet32(ds, esp + 0x3c))
        goto loc_10063dff;
    goto loc_10063bc0;
    // gap 3 bytes // gap 3 bytes
loc_10063bc0: // 0000:10063bc0
    fp0 = memoryFGet32(ds, ebx);
    eax = memoryAGet32(ds, esp + 0x38);
    memoryASet32(ds, esp + 0x3c, memoryAGet32(ds, esp + 0x3c) - 1);
    memoryFSet32(ds, esp + 0x28, fp0);
    fp0 = memoryFGet32(ds, eax);
    eax += 0x00000004;
    memoryFSet32(ds, esp + 0x24, fp0);
    ebx += 0x00000004;
    fp0 = memoryFGet32(ds, esi + 0xf4);
    memoryASet32(ds, esp + 0x38, eax);
    fp0 -= memoryFGet32(ds, esi + 0xf8);
    fp0 *= memoryFGet32(ds, esi + 0x100);
    fp0 += memoryFGet32(ds, esi + 0xf8);
    memoryFSet32(ds, esi + 0xf8, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x20, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x20);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0xe0);
    edi = memoryAGet32(ds, esi + 0xe4);
    fp0 = memoryFGet32(ds, esi + 0xf8) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10063c45;
    ebp = memoryAGet32(ds, esi + 0x10c);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x10);
loc_10063c45: // 0000:10063c45
    if (eax >= edi)
        goto loc_10063c52;
    edi = memoryAGet32(ds, esi + 0x10c);
    eax = eax + (edi * 4);
loc_10063c52: // 0000:10063c52
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xf0);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x108);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xf0, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xec);
    fp2 *= memoryFGet32(ds, esi + 0x104);
    fp2 += memoryFGet32(ds, esi + 0xec);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xec, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xfc);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x24);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xe0, memoryAGet32(ds, esi + 0xe0) + 0x00000004);
    eax = memoryAGet32(ds, esi + 0xe0);
    if (eax < memoryAGet32(ds, esi + 0xe8))
        goto loc_10063cd3;
    edx = memoryAGet32(ds, esi + 0x10c);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xe0, eax);
loc_10063cd3: // 0000:10063cd3
    fp0 *= memoryFGet32(ds, esi + 0x1a0);
    ebp += 0x00000004;
    memoryASet32(ds, esp + 0x10, ebp);
    fp0 += memoryFGet32(ds, esp + 0x28);
    memoryFSet32(ss, ebp - 4, fp0);
    fp0 = memoryFGet32(ds, esi + 0xc0);
    fp0 -= memoryFGet32(ds, esi + 0xc4);
    fp0 *= memoryFGet32(ds, esi + 0xcc);
    fp0 += memoryFGet32(ds, esi + 0xc4);
    memoryFSet32(ds, esi + 0xc4, fp0);
    memoryFSet32(ds, esp + 0x2c, fp0);
    fp0 = memoryFGet32(ds, esp + 0x2c);
    memoryASet32(ds, esp + 0x1c, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x1c);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x1c);
    edx = memoryAGet32(ds, esi + 0xac);
    edi = memoryAGet32(ds, esi + 0xb0);
    fp0 = memoryFGet32(ds, esi + 0xc4) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
    ecx = eax - 4;
    if (ecx >= edi)
        goto loc_10063d4e;
    ebp = memoryAGet32(ds, esi + 0xd8);
    ecx = ecx + (ebp * 4);
    ebp = memoryAGet32(ds, esp + 0x10);
loc_10063d4e: // 0000:10063d4e
    if (eax >= edi)
        goto loc_10063d5b;
    edi = memoryAGet32(ds, esi + 0xd8);
    eax = eax + (edi * 4);
loc_10063d5b: // 0000:10063d5b
    fp1 = memoryFGet32(ds, eax);
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0xbc);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0xd4);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0xbc, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xb8);
    fp2 *= memoryFGet32(ds, esi + 0xd0);
    fp2 += memoryFGet32(ds, esi + 0xb8);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xb8, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0xc8);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x28);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
    memoryASet32(ds, esi + 0xac, memoryAGet32(ds, esi + 0xac) + 0x00000004);
    eax = memoryAGet32(ds, esi + 0xac);
    if (eax < memoryAGet32(ds, esi + 0xb4))
        goto loc_10063ddc;
    edx = memoryAGet32(ds, esi + 0xd8);
    edx += edx;
    edx += edx;
    eax -= edx;
    memoryASet32(ds, esi + 0xac, eax);
loc_10063ddc: // 0000:10063ddc
    fp0 *= memoryFGet32(ds, esi + 0x1a0);
    eax = memoryAGet32(ds, esp + 0x34);
    eax += 0x00000004;
    fp0 += memoryFGet32(ds, esp + 0x24);
    memoryASet32(ds, esp + 0x34, eax);
    memoryFSet32(ds, eax - 4, fp0);
    if (memoryAGet32(ds, esp + 0x3c))
        goto loc_10063bc0;
loc_10063dff: // 0000:10063dff
    edi = pop32();
loc_10063e00: // 0000:10063e00
    ebp = pop32();
    ebx = pop32();
loc_10063e02: // 0000:10063e02
    esi = pop32();
    esp += 0x00000020;
    esp += 20;
}
/*
double subopt_10062e20() // 0000:10062e20 +long +stackDrop8
{
    float fp0, fp1, fp2, fp3, fp4;
    double _cmp0r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    fp0 = 0.009999999776482582f;
    esp -= 0x00000008;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x14);
    _cmp0r = (double)fromFp32(memoryAGet32(ds, esi + 0x38));

    if (fp0 <= _cmp0r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, esi + 0x38))
        goto loc_10062e43;
    fp0 = memoryFGet32(ds, esp + 0x10);
    esi = pop32();
    esp += 0x00000008;
    esp += 12; return fp0;
loc_10062e43: // 0000:10062e43
    fp0 = memoryFGet32(ds, esi + 0x34);
    fp1 = 0.5f;

    if (fp1 <= fp0)  // fp1 vs fp0
        goto loc_10062e6d;
    fp2 = fp0;
    fp2 *= 8.0f;
    fp3 = 4.0f;
    fp4 = fp3;
    fp2 = fp4 - fp2;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp0 *= fp3;
    goto loc_10062e85;
loc_10062e6d: // 0000:10062e6d
    fp0 -= fp1;
    fp2 = fp0;
    fp2 *= fp2;
    fp2 *= 8.0f;
    fp3 = 4.0f;
    fp0 *= fp3;
    { double _xchg = fp3; fp3 = fp2; fp2 = _xchg; }
    fp0 = fp3 - fp0;
loc_10062e85: // 0000:10062e85
    { double _xchg = fp2; fp2 = fp0; fp0 = _xchg; }
    push32(edi);
    fp1 += fp2;
    memoryFSet32(ds, esp + 0x8, fp1);
    fp0 /= memoryFGet32(ds, ecx + 0x70);
    fp0 += memoryFGet32(ds, esi + 0x34);
    memoryFSet32(ds, esi + 0x34, fp0);
    memoryFSet32(ds, esp + 0xc, fp0);
    fp0 = memoryFGet32(ds, esp + 0xc);
    memoryASet32(ds, esp + 0x18, (int32_t)floor(fp0));
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    push32(0x00000000);
    push32(ecx);
    ecx = esi;
    fp0 = memoryFGet32(ds, esi + 0x34) - fp0;
    memoryFSet32(ds, esi + 0x34, fp0);
    fp0 = (double)(int32_t)memoryAGet32(ds, esi + 0x2c);
    fp1 = fp0;
    fp1 *= memoryFGet32(ds, esi + 0x38);
    fp1 *= 0.3499999940395355f;
    fp1 *= memoryFGet32(ds, esp + 0x10);
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    fp1 *= 0.49000000953674316f;
    fp0 += fp1;
    memoryFSet32(ds, esp, fp0);
    subopt_100685e0();
    fp0 = memoryFGet32(ds, esi + 0x14);
    fp0 -= memoryFGet32(ds, esi + 0x18);
    fp0 *= memoryFGet32(ds, esi + 0x20);
    fp0 += memoryFGet32(ds, esi + 0x18);
    memoryFSet32(ds, esi + 0x18, fp0);
    memoryFSet32(ds, esp + 0xc, fp0);
    fp0 = memoryFGet32(ds, esp + 0xc);
    memoryASet32(ds, esp + 0x18, (int32_t)floor(fp0));
    eax = memoryAGet32(ds, esp + 0x18);
    fp0 = (double)(int32_t)memoryAGet32(ds, esp + 0x18);
    edx = memoryAGet32(ds, esi);
    edi = memoryAGet32(ds, esi + 0x4);
    fp0 = memoryFGet32(ds, esi + 0x18) - fp0;
    ecx = (eax * 4) + 0;
    fp1 = 1.0f;
    eax = edx;
    eax -= ecx;
    fp0 = fp1 - fp0;
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
    fp1 = memoryFGet32(ds, eax);
    edi = pop32();
    fp1 -= memoryFGet32(ds, ecx);
    fp0 *= fp1;
    fp0 += memoryFGet32(ds, ecx);
    fp1 = memoryFGet32(ds, esi + 0x10);
    fp1 -= fp0;
    fp1 *= memoryFGet32(ds, esi + 0x28);
    fp0 += fp1;
    fp1 = 1.000000045813705e-18f;
    fp0 += fp1;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, esi + 0x10, fp1);
    fp2 = fp1;
    fp2 -= memoryFGet32(ds, esi + 0xc);
    fp2 *= memoryFGet32(ds, esi + 0x24);
    fp2 += memoryFGet32(ds, esi + 0xc);
    fp2 += fp0;
    memoryFSet32(ds, esi + 0xc, fp2);
    fp1 -= fp2;
    fp2 = memoryFGet32(ds, esi + 0x1c);
    fp2 *= fp1;
    fp3 = memoryFGet32(ds, esp + 0x10);
    fp0 += fp3;
    fp0 += fp2;
    { double _xchg = fp1; fp1 = fp0; fp0 = _xchg; }
    memoryFSet32(ds, edx, fp1);
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
    return fp0;
}
*/
void subopt_10056420() // 0000:10056420 +long
{
    float fp0, fp1;
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    fp0 = 3.0517578125e-05f;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0xc);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0xc);
    edx = memoryAGet32(ds, edi);
    ecx = esi;
loc_10056434: // 0000:10056434
    eax = ecx;
    ecx--;
    if (!eax)
        goto loc_1005644b;
    fp1 = memoryFGet32(ds, edx);
    edx += 0x00000004;
    fp1 = fabsf(fp1);

    if (fp1 < fp0)  // fp1 vs fp0
        goto loc_10056434;
loc_1005644b: // 0000:1005644b
    if (ecx == 0xffffffff)
        goto loc_10056458;
    edi = pop32();

    eax = ecx + 1;
    esi = pop32();
    esp += 4; return;
loc_10056458: // 0000:10056458
    ecx = memoryAGet32(ds, edi + 0x4);
    if (!ecx)
        goto loc_1005647e;
loc_1005645f: // 0000:1005645f
    edx = esi;
    esi--;
    if (!edx)
        goto loc_10056476;
    fp1 = memoryFGet32(ds, ecx);
    ecx += 0x00000004;
    fp1 = fabsf(fp1);

    if (fp1 < fp0)  // fp1 vs fp0
        goto loc_1005645f;
loc_10056476: // 0000:10056476
    edi = pop32();

    eax = esi + 1;
    esi = pop32();
    esp += 4; return;
loc_1005647e: // 0000:1005647e
    edi = pop32();

    eax = 0;
    esi = pop32();
    esp += 4;
}

void subopt_1005a960() // 0000:1005a960 +long +stackDrop8
{
    float fp0;
    double _cmp0r;
    StackGuard _sg(8, __FUNCTION__);
    esp -= 4;
    edx = memoryAGet32(ds, esp + 0x4);
    if (edx > 0x0000000a)
        goto loc_1005a9c2;
    fp0 = memoryFGet32(ds, esp + 0x8);
    _cmp0r = (double)fromFp32(memoryAGet32(ds, ecx + edx * 4 + 0xac));

    if (fp0 == _cmp0r)  // fp0 vs (double)fromFp32(memoryAGet32(ds, ecx + edx * 4 + 0xac))
        goto loc_1005a9c0;
    eax = edx;
    memoryFSet32(ds, ecx + edx * 4 + 0xac, fp0);
    eax -= 0x00000007;
    if (!eax)
        goto loc_1005a9b1;
    eax--;
    if (!eax)
        goto loc_1005a9a2;
    eax--;
    if (eax)
        goto loc_1005a9c0;
    memoryFSet32(ds, ecx + 0xb8, fp0);
    memoryFSet32(ds, ecx + 0xc4, fp0);
    esp += 12; return;
loc_1005a9a2: // 0000:1005a9a2
    memoryFSet32(ds, ecx + 0xb4, fp0);
    memoryFSet32(ds, ecx + 0xc0, fp0);
    esp += 12; return;
loc_1005a9b1: // 0000:1005a9b1
    memoryFSet32(ds, ecx + 0xb0, fp0);
    memoryFSet32(ds, ecx + 0xbc, fp0);
    esp += 12; return;
loc_1005a9c0: // 0000:1005a9c0

loc_1005a9c2: // 0000:1005a9c2
    esp += 12; return;
}

