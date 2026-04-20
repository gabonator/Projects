// Forward declarations for SYNSOEMU functions used before definition
void sub_11001323(); void sub_11001450();
void sub_11006054(); void sub_1100605a(); void sub_11006060();
void sub_11006066(); void sub_1100606c(); void sub_11006072();
void sub_110039bb();

void posRegisterApplicationWithPackage()
{
    sub_110018fa();
}


void posUnregisterApplication()
{
    sub_110018fa();
}


void posInstantiateObject()
{
    sub_11001582();
}


void posCallMethod()
{
    sub_110015fc();
}


void posFreeDLLHeapData()
{
    sub_110015ed();
}


void posDeleteObject()
{
    sub_110015a2();
}


void posRegisterApplicationWithPackageName()
{
    sub_110018fa();
}


void posRegisterApplication()
{
    sub_110018fa();
}


void posInstantiateObjectOnExecuter()
{
    sub_110018fa();
}


void posCallMethodOnExecuter()
{
    sub_110018fa();
}


void posGetObjectInfo()
{
    sub_110018fa();
}


void posGetClassInfo()
{
    sub_110018fa();
}


void posGetExecuterInfo()
{
    sub_110018fa();
}


void posGetInfo()
{
    sub_110018fa();
}


void posExecuteCMD()
{
    sub_110018fa();
}


void posDeleteDLLHeapData()
{
    sub_110015de();
}


void posRegisterApplicationWithClasses()
{
    sub_11001531();
}


void posGetInfoWithCommand()
{
    sub_110015b7();
}


void posEncryptData()
{
    sub_110018fa();
}


void posDecryptData()
{
    sub_110018fa();
}


void posEncryptFile()
{
    sub_110018fa();
}


void posDecryptFile()
{
    sub_110018fa();
}


void posCreateNewSymmetricKey()
{
    sub_110018fa();
}


void posSetAlgorithmParameter()
{
    sub_110018fa();
}


void posModifyPinCode()
{
    sub_110018fa();
}


void posDCPCreateEncryptionContext()
{
    sub_110018bb();
}


void posDCPEncryptData()
{
    sub_110018e5();
}


void posDCPDecryptData()
{
    sub_110018d0();
}

void sub_11001000();
void sub_1100101d();
void sub_1100112d();
void sub_11001157();
void sub_11001181();
void sub_11001200();
void sub_110012f5();
void sub_11001316();
void sub_1100131c();
void sub_11001322();
void sub_11001323();
void sub_110013d0();
void sub_11001443();
void sub_11001449();
void sub_1100144f();
void sub_11001450();
void sub_11001507();
void sub_11001525();
void sub_11001531();
void sub_11001582();
void sub_110015a2();
void sub_110015b7();
void sub_110015de();
void sub_110015ed();
void sub_110015fc();
void sub_110018bb();
void sub_110018d0();
void sub_110018e5();
void sub_110018fa();
void sub_11001900();
void sub_11001990();
void sub_11002d50();
void sub_11002f74();
void sub_11003022();
void sub_11003803();
void sub_110039bb();
void sub_1100430e();
void sub_11004337();
void sub_11004379();
void sub_110043a2();
void sub_110043e4();
void sub_1100440d();
void sub_1100444f();
void sub_11004478();
void sub_110044ba();
void sub_11004560();
void sub_110045d0();
void sub_11004600();
void sub_11004640();
void sub_11004670();
void sub_110046b0();
void sub_11005a60();
void sub_11005ad0();
void sub_11005dc6();
void sub_11005e70();
void sub_11005ea6();
void sub_11006054();
void sub_1100605a();
void sub_11006060();
void sub_11006066();
void sub_1100606c();
void sub_11006072();

void sub_11001000() // 0000:11001000 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    eax = 0;
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0x00000004;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsd<DS_ESI, ES_EDI>();
    al = !flags.zero;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_1100101d() // 0000:1100101d +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    eax = 0;
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = memoryAGet32(ss, ebp + 0x10);
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    al = !flags.zero;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_1100112d() // 0000:1100112d +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x10);
    ecx = 0;
loc_1100113e: // 0000:1100113e
    eax = memoryAGet32(ds, esi + ecx * 4);
    edx = memoryAGet32(ds, ebx + ecx * 4);
    eax = (int32_t)eax * (int32_t)edx;
    memoryASet32(ds, edi + ecx * 4, eax);
    ecx++;
    if (ecx != 0x00000004)
        goto loc_1100113e;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_11001157() // 0000:11001157 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x10);
    ecx = 0;
loc_11001168: // 0000:11001168
    eax = memoryAGet32(ds, esi + ecx * 4);
    edx = memoryAGet32(ds, ebx + ecx * 4);
    eax = (int32_t)eax * (int32_t)edx;
    memoryASet32(ds, edi + ecx * 4, eax);
    ecx++;
    if (ecx != 0x00000004)
        goto loc_11001168;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_11001181() // 0000:11001181 +long +stackDrop16
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(esi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    esi = memoryAGet32(ss, ebp + 0x14);
loc_11001190: // 0000:11001190
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp + 0xc);
    edx = memoryAGet16(ds, edx + ecx * 2);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 14;
    edx &= 0x000003f0;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 12;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1100);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1200);
    eax = edx;
    edx &= 0x00ffffff;
    memoryASet32(ss, ebp - 4, edx);
    eax >>= 24;
    edx = memoryAGet32(ss, ebp + 0x10);
    memoryASet(ds, ecx + edx, al);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_11001190;
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 16/8) // SEH removed (was stack_below, 16/8)
    esp += 20;
}
void sub_11001200() // 0000:11001200 +long +stackDrop20
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff8;
    push32(ebx);
    push32(esi);
    ebx = 0;
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    memoryASet32(ss, ebp - 8, ecx);
    esi = memoryAGet32(ss, ebp + 0x18);
loc_11001215: // 0000:11001215
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8400);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8600);
    memoryASet32(ss, ebp - 4, edx);
    eax = edx;
    eax >>= 21;
    eax &= 0x00000700;
    edx = memoryAGet32(ss, ebp - 8);
    edx &= 0x00003800;
    eax |= edx;
    eax >>= 3;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx = memoryAGet16(ds, edx + ecx * 2);
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4 + 0x8a00);
    eax = memoryAGet32(ss, ebp - 8);
    eax >>= 4;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa00);
    eax = memoryAGet32(ss, ebp - 8);
    eax >>= 8;
    eax &= 0x00000007;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa40);
    eax = memoryAGet32(ss, ebp - 8);
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa60);
    memoryASet32(ss, ebp - 8, edx);
    if (ecx < 0x00000008)
        goto loc_110012e3;
    edx >>= 14;
    edx &= 0x00000001;
    ebx |= edx;
    ebx = ror32(ebx, 0x00000001);
loc_110012e3: // 0000:110012e3
    ecx++;
    if (ecx != 0x00000028)
        goto loc_11001215;
    eax = ebx;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 20/8) // SEH removed (was stack_below, 20/8)
    esp += 24;
}
void sub_110012f5() // 0000:110012f5 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    eax = edx + 44;
    push32(eax);
    eax = edx + 556;
    push32(eax);
    eax = edx + 4;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11001323();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_11001316() // 0000:11001316 +long
{
    esp -= 4;
    eax = 0x11007114;
    esp += 4;
}
void sub_1100131c() // 0000:1100131c +long
{
    esp -= 4;
    eax = 0x11007124;
    esp += 4;
}
void sub_11001322() // 0000:11001322 +long
{
    esp -= 4;
    esp += 4;
}
void sub_11001323() // 0000:11001323 +long +stackDrop16
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff4;
    push32(ebx);
    push32(esi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    ebx = 0;
    esi = memoryAGet32(ss, ebp + 0x10);
loc_11001335: // 0000:11001335
    edx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet16(ds, edx + ecx * 2);
    memoryASet32(ss, ebp - 8, edx);
    edx <<= 3;
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet(ds, ecx + eax);
    memoryASet32(ss, ebp - 12, eax);
    eax <<= 1;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx &= 0x07fc0000;
    edx >>= 13;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 12;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10100);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10200);
    edx &= 0x07ffffff;
    etx = memoryAGet32(ss, ebp - 4); memoryASet32(ss, ebp - 4, edx); edx = etx;
    if (ecx < 0x00000008)
        goto loc_110013be;
    edx >>= 18;
    eax = memoryAGet32(ss, ebp + 0x14);
    eax = memoryAGet(ds, edx + eax);
    indirectCall(cs, memoryAGet32(ds, eax * 4 + 0x11007134), __LINE__, 0); // 0000:110013a6
    edx = memoryAGet32(ss, ebp - 8);
    eax = eax + (edx * 4);
    edx = memoryAGet32(ss, ebp - 12);
    eax = memoryAGet(ds, edx + eax);
    ebx |= eax;
    ebx = ror32(ebx, 0x00000001);
loc_110013be: // 0000:110013be
    ecx++;
    if (ecx != 0x00000028)
        goto loc_11001335;
    eax = ebx;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 20;
}
void sub_110013d0() // 0000:110013d0 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = memoryAGet32(ss, ebp + 0x10);
    edi = 0;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_110013e5: // 0000:110013e5
    edx = ebx + 66860;
    esi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0;
loc_110013f0: // 0000:110013f0
    eax = memoryAGet16(ds, edx + ecx * 2);
    memoryASet16(ds, esi + ecx * 2, ax);
    ecx++;
    if (ecx != 0x00000008)
        goto loc_110013f0;
    push32(memoryAGet32(ss, ebp - 4));
    eax = ebx + 66876;
    push32(eax);
    eax = ebx + 66940;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11001450();
    eax = ebx;
    push32(memoryAGet32(ss, ebp + 0xc));
    indirectCall(cs, memoryAGet32(ds, eax), __LINE__, 0); // 0000:1100141f
    if (eax == memoryAGet32(ss, ebp + 0x8))
        goto loc_1100143c;
    ecx = (int32_t)edi * (int32_t)0x00000008;
    eax >>= cl;
    if (memoryAGet(ss, edi + ebp + 0x8) != al)
        goto loc_11001435;
    edi++;
    goto loc_1100143a;
loc_11001435: // 0000:11001435
    memoryASet(ss, edi + ebp - 4, memoryAGet(ss, edi + ebp - 4) + 1);
loc_1100143a: // 0000:1100143a
    goto loc_110013e5;
loc_1100143c: // 0000:1100143c
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 16;
}
void sub_11001443() // 0000:11001443 +long
{
    esp -= 4;
    eax = 0x11007140;
    esp += 4;
}
void sub_11001449() // 0000:11001449 +long
{
    esp -= 4;
    eax = 0x11007144;
    esp += 4;
}
void sub_1100144f() // 0000:1100144f +long
{
    esp -= 4;
    esp += 4;
}
void sub_11001450() // 0000:11001450 +long +stackDrop20
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0x18);
    esi = memoryAGet32(ss, ebp + 0x10);
loc_11001467: // 0000:11001467
    if (ecx < 0x00000008)
        goto loc_1100149c;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 12;
    eax = memoryAGet32(ss, ebp + 0x14);
    eax = memoryAGet(ds, edx + eax);
    indirectCall(cs, memoryAGet32(ds, eax * 4 + 0x11007148), __LINE__, 0); // 0000:11001479
    edx = ebx;
    edx &= 0x00000001;
    eax = eax + (edx * 2);
    edx = edi;
    edx &= 0x00000001;
    eax = memoryAGet(ds, edx + eax);
    edx = memoryAGet32(ss, ebp + 0xc);
    memoryASet16(ds, edx + ecx * 2, ax);
    ebx = ror32(ebx, 0x00000001);
    edi = ror32(edi, 0x00000001);
loc_1100149c: // 0000:1100149c
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 4);
    edx &= 0x0003f000;
    edx >>= 10;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 8;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x400);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 4;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x440);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x480);
    eax = edx;
    edx &= 0x0003ffff;
    memoryASet32(ss, ebp - 4, edx);
    eax >>= 18;
    edx = memoryAGet32(ss, ebp + 0xc);
    memoryASet16(ds, edx + ecx * 2, ax);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_11001467;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 20/12) // SEH removed (was stack_below, 20/12)
    esp += 24;
}
void sub_11001507() // 0000:11001507 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_110012f5();
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(eax);
    sub_110013d0();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_11001525() // 0000:11001525 +stackDrop12 +entry
{
    push32(ebp);
    ebp = esp;
    eax = 0x00000001;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 12;
}
void sub_11001531() // 0000:11001531 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    eax = memoryAGet32(ss, ebp + 0x1c);
    printf("  posRegister: [ebp+0xc]=0x%08x [ebp+0x1c]=0x%08x outPtr=0x%08x\n",
        memoryAGet32(ss, ebp+0xc), memoryAGet32(ss, ebp+0x1c), eax);
    memoryASet32(ds, eax, 0xffffffff);
    printf("  posRegister: wrote 0xffffffff to outPtr=0x%08x\n", eax);
    if (!memoryAGet32(ss, ebp + 0xc)) {
        printf("  posRegister: SKIP (arg2=0)\n");
        goto loc_1100157b; }
    ebx = 0x11007020;
loc_1100154b: // 0000:1100154b
    printf("  posRegister: matching class at ebx=0x%08x [ebx]=0x%08x vs appClasses=0x%08x\n",
        ebx, memoryAGet32(ds, ebx), memoryAGet32(ss, ebp+0xc));
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0xc));
    sub_11001000();
    printf("  posRegister: sub_11001000 returned eax=%d\n", eax);
    if (eax)
        goto loc_11001573;
    push32(0x0000001c);
    push32(0x00000040);
    sub_11006054();
    edi = eax;
    eax = memoryAGet32(ss, ebp + 0x1c);
    printf("  posRegister: MATCH! alloc=0x%08x storing at outPtr=0x%08x, copying from ebx=0x%08x\n", edi, eax, ebx);
    // Save entire ordinal table + handle area (0x105814bc..0x1058150c = 20 DWORDs)
    uint32_t _sv[21]; for(int _i=0;_i<21;_i++) _sv[_i]=memoryAGet32(ds,0x105814bc+_i*4);
    memoryASet32(ds, eax, edi);
    esi = ebx;
    ecx = 0x00000018;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    { uint32_t h = memoryAGet32(ds, 0x105814bc);
      printf("  POST-COPY: handle=0x%08x [+0x14]=0x%08x edi=0x%08x\n", h, memoryAGet32(ds, h+0x14), edi); }
    // Restore ordinal table (skip first entry which is the handle ptr itself)
    for(int _i=2;_i<21;_i++) memoryASet32(ds,0x105814bc+_i*4,_sv[_i]);
    // Keep the handle ptr and first copy byte at 0x105814bc..0x105814c3
    { uint32_t h=memoryAGet32(ds,0x105814bc);
      printf("  posRegister: handle=0x%08x [+0x10]=0x%08x [+0x14]=0x%08x\n",
          h, memoryAGet32(ds,h+0x10), memoryAGet32(ds,h+0x14)); }
    goto loc_1100157b;
loc_11001573: // 0000:11001573
    ebx = ebx + 24;
    if (memoryAGet32(ds, ebx))
        goto loc_1100154b;
loc_1100157b: // 0000:1100157b
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_11001582() // 0000:11001582 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    printf("  posInstantiate: ebx(handle)=0x%08x [ebx+0x10]=0x%08x [ebp+0x10]=0x%08x\n",
        ebx, ebx >= 0x10000000 ? memoryAGet32(ds, ebx+0x10) : 0, memoryAGet32(ss, ebp+0x10));
    if (ebx == 0xffffffff)
        goto loc_1100159d;
    eax = memoryAGet32(ds, ebx + 0x10);
    printf("  posInstantiate: factory fn = 0x%08x\n", eax);
    if (!eax)
        goto loc_1100159d;
    push32(memoryAGet32(ss, ebp + 0x10));
    indirectCall(cs, eax, __LINE__, 0); // 0000:11001598
    printf("  posInstantiate: factory returned eax=0x%08x, storing at [0x%08x+0x18]\n", eax, ebx);
    memoryASet32(ds, ebx + 0x18, eax);
loc_1100159d: // 0000:1100159d
    eax = 0;
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_110015a2() // 0000:110015a2 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (eax == 0xffffffff)
        goto loc_110015b3;
    push32(eax);
    sub_1100605a();
loc_110015b3: // 0000:110015b3
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_110015b7() // 0000:110015b7 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(0x00000150);
    push32(0x00000040);
    sub_11006054();
    edx = memoryAGet32(ss, ebp + 0x18);
    memoryASet32(ds, edx, 0x00000150);
    edx = memoryAGet32(ss, ebp + 0x14);
    memoryASet32(ds, edx, eax);
    memoryASet32(ds, eax, 0x00000001);
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_110015de() // 0000:110015de +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1100605a();
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_110015ed() // 0000:110015ed +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1100605a();
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_110015fc() // 0000:110015fc +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(0x11007154);
    push32(memoryAGet32(ss, ebp + 0x10));
    sub_11001000();
    if (eax)
        goto loc_11001782;
    push32(0x0000001c);
    push32(0x00000040);
    sub_11006054();
    edi = eax;
    eax = memoryAGet32(ss, ebp + 0x1c);
    memoryASet32(ds, eax, edi);
    eax = memoryAGet32(ss, ebp + 0x20);
    memoryASet32(ds, eax, 0x0000001c);
    esi = 0x1100719c;
    ecx = 0x0000001c;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    push32(0x11007038);
    push32(ebx);
    sub_11001000();
    if (!eax)
        goto loc_110018b4;
    push32(0x11007050);
    push32(ebx);
    sub_11001000();
    if (!eax)
        goto loc_110018b4;
    push32(0x11007020);
    push32(ebx);
    sub_11001000();
    if (!eax)
        goto loc_110018b4;
    push32(0x11007068);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_1100169e;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x111079b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_11001507();
    goto loc_110018b4;
loc_1100169e: // 0000:1100169e
    push32(0x11007080);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_110016c4;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x110b1eb8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_11001507();
    goto loc_110018b4;
loc_110016c4: // 0000:110016c4
    push32(0x110070b0);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_110016ea;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x110ce7b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_11001507();
    goto loc_110018b4;
loc_110016ea: // 0000:110016ea
    push32(0x110070c8);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_11001726;
    if (memoryAGet32(ds, ebx + 0x18) != 0x00000262)
        goto loc_11001715;
    eax = memoryAGet32(ss, ebp + 0xa8);
    edx = memoryAGet32(ss, ebp + 0xac);
    memoryASet32(ss, ebp + 0x8c, memoryAGet32(ss, ebp + 0x8c) + 0x00000011);
loc_11001715: // 0000:11001715
    push32(0x11134d00);
    push32(edx);
    push32(eax);
    sub_11001507();
    goto loc_110018b4;
loc_11001726: // 0000:11001726
    push32(0x110070e0);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_1100174c;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x111242b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_11001507();
    goto loc_110018b4;
loc_1100174c: // 0000:1100174c
    push32(0x110070f8);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_11001772;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x110eb0b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_11001507();
    goto loc_110018b4;
loc_11001772: // 0000:11001772
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0xdead0001);
    sub_11006060();
loc_11001782: // 0000:11001782
    push32(0x11007178);
    push32(memoryAGet32(ss, ebp + 0x10));
    sub_11001000();
    if (eax)
        goto loc_110018a4;
    push32(0x110070e0);
    push32(ebx);
    sub_11001000();
    if (!eax)
        goto loc_110018b4;
    push32(0x11007068);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_110017d6;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001ae)
        goto loc_110017cd;
    eax = eax + 3754892;
loc_110017cd: // 0000:110017cd
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:110017ce
    goto loc_110018b4;
loc_110017d6: // 0000:110017d6
    push32(0x11007080);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_11001824;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001f4)
        goto loc_110017fb;
    eax = eax + 3315348;
    goto loc_1100181b;
loc_110017fb: // 0000:110017fb
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001f5)
        goto loc_1100180c;
    eax = eax + 3320236;
    goto loc_1100181b;
loc_1100180c: // 0000:1100180c
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001fe)
        goto loc_1100181b;
    eax = eax + 3333812;
loc_1100181b: // 0000:1100181b
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:1100181c
    goto loc_110018b4;
loc_11001824: // 0000:11001824
    push32(0x11007098);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_11001852;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x0000006e)
        goto loc_11001846;
    eax = eax + 746332;
    goto loc_1100184c;
loc_11001846: // 0000:11001846
    eax = eax + 746332;
loc_1100184c: // 0000:1100184c
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:1100184d
    goto loc_110018b4;
loc_11001852: // 0000:11001852
    push32(0x110070b0);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_1100187b;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x0000015e)
        goto loc_11001875;
    eax = eax + 928228;
loc_11001875: // 0000:11001875
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:11001876
    goto loc_110018b4;
loc_1100187b: // 0000:1100187b
    push32(0x110070f8);
    push32(ebx);
    sub_11001000();
    if (eax)
        goto loc_110018a4;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000000dc)
        goto loc_1100189e;
    eax = eax + 201308;
loc_1100189e: // 0000:1100189e
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:1100189f
    goto loc_110018b4;
loc_110018a4: // 0000:110018a4
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0xdead0002);
    sub_11006060();
loc_110018b4: // 0000:110018b4
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_110018bb() // 0000:110018bb +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), __LINE__, 0); // 0000:110018c9
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_110018d0() // 0000:110018d0 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    { uint32_t _vfn = memoryAGet32(ds, eax + 0x14);
      printf("  DCP vtable call: arg=0x%08x [arg+4]=0x%08x addr=0x%08x fn=0x%08x\n",
          memoryAGet32(ss, ebp+8), eax, eax+0x14, _vfn); }
    push32(0x00000002);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), __LINE__, 0); // 0000:110018de
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_110018e5() // 0000:110018e5 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(0x00000001);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), __LINE__, 0); // 0000:110018f3
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_110018fa() // 0000:110018fa +long
{
    esp -= 4;
    eax = 0;
    esp += 4;
}
void sub_11001900() // 0000:11001900 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x01616380)
        goto loc_11001929;
    eax = 0x000001f4;
    goto loc_11001947;
loc_11001929: // 0000:11001929
    if (eax != 0x0161d890)
        goto loc_11001937;
    eax = 0x000001f5;
    goto loc_11001947;
loc_11001937: // 0000:11001937
    if (eax != 0x0162e530)
        goto loc_11001945;
    eax = 0x000001fe;
    goto loc_11001947;
loc_11001945: // 0000:11001945
    eax = 0;
loc_11001947: // 0000:11001947
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11001990() // 0000:11001990 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffdc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    memoryASet32(ss, ebp - 32, 0x00000000);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_110019b1: // 0000:110019b1
    push32(edi);
    esi = 0x11007378;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (!flags.zero)
        goto loc_110019c4;
    memoryASet32(ss, ebp - 32, memoryAGet32(ss, ebp - 32) + 1);
loc_110019c4: // 0000:110019c4
    if (memoryAGet32(ss, ebp - 32) == 0x00000002)
        goto loc_110019cd;
    edi++;
    goto loc_110019b1;
loc_110019cd: // 0000:110019cd
    memoryASet32(ds, 0x11145744, edi);
    goto loc_110019f9;
    // gap 36 bytes // gap 36 bytes
loc_110019f9: // 0000:110019f9
    edi = memoryAGet32(ds, ebx + 0x4);
loc_110019fc: // 0000:110019fc
    push32(edi);
    esi = 0x110073a0;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_11001a0f;
    edi++;
    goto loc_110019fc;
loc_11001a0f: // 0000:11001a0f
    memoryASet32(ds, 0x11145748, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_11001a18: // 0000:11001a18
    esi = memoryAGet32(ds, 0x11145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11001a2a;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11001a2d;
loc_11001a2a: // 0000:11001a2a
    edi++;
    goto loc_11001a18;
loc_11001a2d: // 0000:11001a2d
    push32(edi);
loc_11001a2e: // 0000:11001a2e
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11001a3a;
    goto loc_11001a2e;
loc_11001a3a: // 0000:11001a3a
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_11001a56: // 0000:11001a56
    esi = memoryAGet32(ds, 0x11145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11001a68;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11001a6b;
loc_11001a68: // 0000:11001a68
    edi++;
    goto loc_11001a56;
loc_11001a6b: // 0000:11001a6b
    push32(edi);
loc_11001a6c: // 0000:11001a6c
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11001a78;
    goto loc_11001a6c;
loc_11001a78: // 0000:11001a78
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_11001a94: // 0000:11001a94
    esi = memoryAGet32(ds, 0x11145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11001aa6;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11001aa9;
loc_11001aa6: // 0000:11001aa6
    edi++;
    goto loc_11001a94;
loc_11001aa9: // 0000:11001aa9
    push32(edi);
loc_11001aaa: // 0000:11001aaa
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11001ab6;
    goto loc_11001aaa;
loc_11001ab6: // 0000:11001ab6
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_11001ad2: // 0000:11001ad2
    esi = memoryAGet32(ds, 0x11145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11001ae4;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11001ae7;
loc_11001ae4: // 0000:11001ae4
    edi++;
    goto loc_11001ad2;
loc_11001ae7: // 0000:11001ae7
    push32(edi);
loc_11001ae8: // 0000:11001ae8
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11001af4;
    goto loc_11001ae8;
loc_11001af4: // 0000:11001af4
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_11001b10: // 0000:11001b10
    esi = memoryAGet32(ds, 0x11145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11001b22;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11001b25;
loc_11001b22: // 0000:11001b22
    edi++;
    goto loc_11001b10;
loc_11001b25: // 0000:11001b25
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11001b31;
    goto loc_11001b25;
loc_11001b31: // 0000:11001b31
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-128) // SEH removed (was stack_unbalanced, 4/-128)
    esp += 8;
}
void sub_11002d50() // 0000:11002d50 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe0;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    edi = memoryAGet32(ds, ebx + 0x4);
loc_11002d6a: // 0000:11002d6a
    push32(edi);
    esi = 0x1102cf48;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_11002d7d;
    edi++;
    goto loc_11002d6a;
loc_11002d7d: // 0000:11002d7d
    memoryASet32(ds, 0x11146c94, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_11002d86: // 0000:11002d86
    push32(edi);
    esi = 0x1102cf70;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_11002d99;
    edi++;
    goto loc_11002d86;
loc_11002d99: // 0000:11002d99
    memoryASet32(ds, 0x11146c98, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_11002da2: // 0000:11002da2
    esi = memoryAGet32(ds, 0x11146c98);
    if (memoryAGet32(ds, edi) == esi)
        goto loc_11002daf;
    edi++;
    goto loc_11002da2;
loc_11002daf: // 0000:11002daf
    edi--;
    if (memoryAGet16(ds, edi - 2) == 0xcccc)
        goto loc_11002dba;
    goto loc_11002daf;
loc_11002dba: // 0000:11002dba
    goto loc_11002dd6;
    // gap 26 bytes // gap 26 bytes
loc_11002dd6: // 0000:11002dd6
    ebx = 0x0000001a;
    eax = ebp - 32;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x11002dbc;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-60) // SEH removed (was stack_unbalanced, 4/-60)
    esp += 8;
}
void sub_11002f74() // 0000:11002f74 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0x8);
    eax = 0xffffffff;
    ecx = 0x00000028;
    for (; ecx != 0; --ecx) stosb<ES_EDI>(al);
    ebx = 0;
    ecx = 0;
loc_11002f8c: // 0000:11002f8c
    push32(ebx);
    eax = memoryAGet(ds, ecx + 0x1103dc10);
    edx = memoryAGet32(ss, ebp + 0xc);
    edx = memoryAGet16(ds, edx + ecx * 2);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x8);
    memoryASet(ds, ecx + edx, memoryAGet(ds, ecx + edx) + 1);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    edx <<= 4;
    eax |= edx;
    edx = ebx;
    edx >>= 18;
    edx &= 0x000003c0;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1103dc38);
    eax = ebx;
    eax >>= 16;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103ec38);
    eax = ebx;
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103f038);
    eax = ebx;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103f438);
    eax = edx;
    eax >>= 28;
    ebx = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet16(ds, ebx + ecx * 2) == ax)
        goto loc_11003007;
    ebx = pop32();
    goto loc_11003013;
loc_11003007: // 0000:11003007
    esp += 0x00000008; // SEH fixed: was +4, deficit 4
    ebx = edx;
    ebx &= 0x0fffffff;
    ecx++;
loc_11003013: // 0000:11003013
    if (ecx != 0x00000028)
        goto loc_11002f8c;
    edi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH fixed (was stack_below, 12/8) // SEH fixed (was stack_below, 12/8)
    esp += 16;
}
void sub_11003022() // 0000:11003022 +long
{
    esp -= 4;
    esp -= 0x0000006c;
    eax = memoryAGet32(ds, esp + 0x20);
    ecx = memoryAGet32(ds, esp + 0x2c);
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x28);
    push32(edi);
    edi = esp - 42;
    memoryASet32(ds, esp - 52, eax);
    eax = memoryAGet32(ds, esp + 0x34);
    ebx = edi;
    ebx -= eax;
    memoryASet32(ds, esp - 48, ebx);
    ebp = esp - 44;
    memoryASet32(ds, esp - 64, ecx);
    ebx = esp - 40;
    ecx = 0;
    esi++;
    ebp -= eax;
    ebx -= eax;
    edx = eax + 4;
    memoryASet32(ds, esp - 60, ebx);
    memoryASet32(ds, esp - 68, 0x00000008);
    esp = esp;
loc_11003070: // 0000:11003070
    eax = (int16_t)memoryAGet16(ds, edx - 4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi - 1);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fb38);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1103fc38);
    ecx = eax;
    eax &= 0x001fffff;
    ecx >>= 21;
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    memoryASet16(ds, edi - 2, cx);
    ecx = (int16_t)memoryAGet16(ds, edx - 2);
    ecx |= ebx;
    ebx = memoryAGet(ds, esi);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x1103f838);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1103fa38);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1103fb38);
    ebx = (int16_t)memoryAGet16(ds, edx);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x1103fc38);
    eax = ecx;
    eax >>= 21;
    memoryASet16(ds, edi, ax);
    ecx &= 0x001fffff;
    eax = ecx;
    eax >>= 14;
    eax &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi + 0x1);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fb38);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1103fc38);
    ecx = eax;
    ecx >>= 21;
    eax &= 0x001fffff;
    memoryASet16(ss, ebp + edx, cx);
    ecx = (int16_t)memoryAGet16(ds, edx + 0x2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = memoryAGet(ds, esi + 0x2);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x1103f838);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1103fa38);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1103fb38);
    ebx = memoryAGet32(ds, esp - 48);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x1103fc38);
    esi += 0x00000005;
    eax = ecx;
    eax >>= 21;
    memoryASet16(ds, edx + ebx, ax);
    eax = (int16_t)memoryAGet16(ds, edx + 0x4);
    ecx &= 0x001fffff;
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi - 2);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1103fb38);
    ebx = memoryAGet32(ds, esp - 60);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1103fc38);
    edi += 0x0000000a;
    ecx = eax;
    ecx >>= 21;
    memoryASet16(ds, edx + ebx, cx);
    eax &= 0x001fffff;
    edx += 0x0000000a;
    memoryASet32(ds, esp - 68, memoryAGet32(ds, esp - 68) - 0x00000001);
    ecx = eax;
    if (memoryAGet32(ds, esp - 68))
        goto loc_11003070;
    eax = memoryAGet32(ds, esp - 64);
    ecx = 0x00000002;
    ecx -= 0x1102cf49;
    memoryASet32(ds, esp - 60, ecx);
    ecx = 0x00000003;
    ecx -= 0x1102cf49;
    ebx = 0;
    memoryASet32(ds, esp - 48, ecx);
    memoryASet32(ds, eax, ebx);
    ecx = 0x00000004;
    edx = 0;
    eax = 0;
    ecx -= 0x1102cf49;
    memoryASet32(ds, esp - 68, ebx);
    memoryASet32(ds, esp - 56, ecx);
loc_11003283: // 0000:11003283
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 44);
    edx <<= 10;
    edx |= ecx;
    edx += edx;
    edx += edx;
    ecx = ebx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edx |= ecx;
    ecx = memoryAGet(ds, eax + 0x1102cf48);
    edx |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    edi = bh;
    ebx &= 0x000000ff;
    ecx += ecx;
    edx += edx;
    ecx += ecx;
    edi += edi;
    ebx += ebx;
    esi = memoryAGet32(ds, ebx + ebx + 0x1103fd38);
    esi ^= memoryAGet32(ds, edi + edi + 0x11040138);
    edi += edi;
    esi ^= memoryAGet32(ds, ecx + 0x11040538);
    ebx += ebx;
    edx += edx;
    ebp = edx;
    esi ^= memoryAGet32(ss, ebp + 0x11040938);
    edx = memoryAGet32(ds, ebx + 0x11048938);
    edx ^= memoryAGet32(ds, edi + 0x11048d38);
    edi = esi;
    edx ^= memoryAGet32(ds, ecx + 0x11049138);
    ecx = esi;
    edx ^= memoryAGet32(ss, ebp + 0x11049538);
    ebp = memoryAGet32(ds, esp - 64);
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 44, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    edi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)eax < (int32_t)0x00000008)
        goto loc_1100332d;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 8;
    esi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | esi);
loc_1100332d: // 0000:1100332d
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 42);
    edi <<= 10;
    edi |= ecx;
    edi += edi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edi += edi;
    edi |= ecx;
    ecx = memoryAGet(ds, eax + 0x1102cf49);
    edi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi = dh;
    edx &= 0x000000ff;
    edi += edi;
    edx += edx;
    edi += edi;
    edx += edx;
    ecx += ecx;
    ebx = edi;
    edi = memoryAGet32(ds, edx + 0x1103fd38);
    edx = memoryAGet32(ds, edx + 0x11048938);
    ecx += ecx;
    esi += esi;
    edi ^= memoryAGet32(ds, esi + esi + 0x11040138);
    edx ^= memoryAGet32(ds, esi + esi + 0x11048d38);
    edi ^= memoryAGet32(ds, ecx + 0x11040538);
    edx ^= memoryAGet32(ds, ecx + 0x11049138);
    edi ^= memoryAGet32(ds, ebx + 0x11040938);
    edx ^= memoryAGet32(ds, ebx + 0x11049538);
    esi += esi;
    ecx = edi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 42, cx);
    ecx = edi;
    ecx = sar32(ecx, 0x02);
    esi = edi;
    cl &= 0x03;
    esi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)eax < (int32_t)0x00000007)
        goto loc_110033d3;
    edi = sar32(edi, 0x00000001);
    edi &= 0x00000001;
    ecx = eax - 7;
    edi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | edi);
loc_110033d3: // 0000:110033d3
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 40);
    esi <<= 10;
    esi |= ecx;
    esi += esi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    esi += esi;
    esi |= ecx;
    ecx = memoryAGet(ds, eax + 0x1102cf4a);
    esi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    edi = dh;
    edx &= 0x000000ff;
    esi += esi;
    esi += esi;
    edx += edx;
    edx += edx;
    ebx = esi;
    esi = memoryAGet32(ds, ebx + 0x11040938);
    ecx += ecx;
    ecx += ecx;
    ebp = edx;
    esi ^= memoryAGet32(ss, ebp + 0x1103fd38);
    edx = memoryAGet32(ds, ebx + 0x11049538);
    edx ^= memoryAGet32(ss, ebp + 0x11048938);
    edi += edi;
    esi ^= memoryAGet32(ds, edi + edi + 0x11040138);
    edx ^= memoryAGet32(ds, edi + edi + 0x11048d38);
    esi ^= memoryAGet32(ds, ecx + 0x11040538);
    edx ^= memoryAGet32(ds, ecx + 0x11049138);
    edi += edi;
    ecx = esi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 40, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 60);
    edi = esi;
    ecx = (ecx + eax) + 285396809;
    edi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_11003489;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 6;
    esi <<= cl;
    ecx = memoryAGet32(ds, esp - 64);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) | esi);
loc_11003489: // 0000:11003489
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 38);
    edi <<= 10;
    edi |= ecx;
    edi += edi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edi += edi;
    edi |= ecx;
    ecx = memoryAGet(ds, eax + 0x1102cf4b);
    edi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi = dh;
    edx &= 0x000000ff;
    edi += edi;
    edi += edi;
    edx += edx;
    edx += edx;
    ebx = edi;
    edi = memoryAGet32(ds, ebx + 0x11040938);
    ecx += ecx;
    ebp = edx;
    edi ^= memoryAGet32(ss, ebp + 0x1103fd38);
    edx = memoryAGet32(ds, ebx + 0x11049538);
    edx ^= memoryAGet32(ss, ebp + 0x11048938);
    ecx += ecx;
    esi += esi;
    edi ^= memoryAGet32(ds, esi + esi + 0x11040138);
    edx ^= memoryAGet32(ds, esi + esi + 0x11048d38);
    edi ^= memoryAGet32(ds, ecx + 0x11040538);
    edx ^= memoryAGet32(ds, ecx + 0x11049138);
    ebp = memoryAGet32(ds, esp - 64);
    esi += esi;
    ecx = edi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 38, cx);
    ecx = edi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 48);
    esi = edi;
    ecx = (ecx + eax) + 285396809;
    esi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_11003540;
    edi = sar32(edi, 0x00000001);
    edi &= 0x00000001;
    ecx = eax - 5;
    edi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | edi);
loc_11003540: // 0000:11003540
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 36);
    esi <<= 10;
    esi |= ecx;
    esi += esi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    esi += esi;
    esi |= ecx;
    ecx = memoryAGet(ds, eax + 0x1102cf4c);
    esi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi += esi;
    ebx = dh;
    esi += esi;
    edx &= 0x000000ff;
    edi = esi;
    esi = memoryAGet32(ds, edi + 0x11040938);
    edi = memoryAGet32(ds, edi + 0x11049538);
    ecx += ecx;
    edx += edx;
    esi ^= memoryAGet32(ds, edx + edx + 0x1103fd38);
    edi ^= memoryAGet32(ds, edx + edx + 0x11048938);
    ecx += ecx;
    edx += edx;
    ebx += ebx;
    esi ^= memoryAGet32(ds, ebx + ebx + 0x11040138);
    edi ^= memoryAGet32(ds, ebx + ebx + 0x11048d38);
    esi ^= memoryAGet32(ds, ecx + 0x11040538);
    edi ^= memoryAGet32(ds, ecx + 0x11049138);
    ebx += ebx;
    ecx = esi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 36, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 56);
    edx = esi;
    ecx = (ecx + eax) + 285396809;
    edx &= 0x00000001;
    ebx = edi;
    memoryASet32(ds, esp - 68, ebx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_110035f5;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 4;
    esi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | esi);
loc_110035f5: // 0000:110035f5
    eax += 0x00000005;
    if ((int32_t)eax < (int32_t)0x00000028)
        goto loc_11003283;
    eax = memoryAGet32(ds, esp + 0x38);
    esi = memoryAGet32(ds, esp - 52);
    edi = esp - 42;
    ebx = edi;
    ebx -= eax;
    memoryASet32(ds, esp - 52, ebx);
    ebp = esp - 44;
    ebx = esp - 40;
    ecx = 0;
    esi++;
    ebp -= eax;
    ebx -= eax;
    edx = eax + 4;
    memoryASet32(ds, esp - 56, ebx);
    memoryASet32(ds, esp - 64, 0x00000008);
loc_11003635: // 0000:11003635
    eax = (int16_t)memoryAGet16(ds, edx - 4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = (int16_t)memoryAGet16(ds, edi - 2);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x11051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x11051938);
    ecx = eax;
    eax &= 0x001fffff;
    ecx >>= 21;
    memoryASet(ds, esi - 1, cl);
    ecx = (int16_t)memoryAGet16(ds, edx - 2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = (int16_t)memoryAGet16(ds, edi);
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x11051538);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x11051738);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x11051838);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x11051938);
    eax = ecx;
    eax >>= 21;
    memoryASet(ds, esi, al);
    ebx = (int16_t)memoryAGet16(ds, edx);
    ecx &= 0x001fffff;
    eax = ecx;
    eax >>= 14;
    eax &= 0x00000070;
    eax |= ebx;
    ebx = (int16_t)memoryAGet16(ss, ebp + edx);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x11051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x11051938);
    ecx = eax;
    ecx >>= 21;
    eax &= 0x001fffff;
    memoryASet(ds, esi + 0x1, cl);
    ecx = (int16_t)memoryAGet16(ds, edx + 0x2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = memoryAGet32(ds, esp - 52);
    ebx = (int16_t)memoryAGet16(ds, edx + ebx);
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x11051538);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x11051738);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x11051838);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x11051938);
    esi += 0x00000005;
    eax = ecx;
    eax >>= 21;
    ecx &= 0x001fffff;
    memoryASet(ds, esi - 3, al);
    eax = (int16_t)memoryAGet16(ds, edx + 0x4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet32(ds, esp - 56);
    ebx = (int16_t)memoryAGet16(ds, edx + ebx);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x11051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x11051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x11051938);
    edi += 0x0000000a;
    ecx = eax;
    ecx >>= 21;
    memoryASet(ds, esi - 2, cl);
    eax &= 0x001fffff;
    edx += 0x0000000a;
    memoryASet32(ds, esp - 64, memoryAGet32(ds, esp - 64) - 0x00000001);
    ecx = eax;
    if (memoryAGet32(ds, esp - 64))
        goto loc_11003635;
    ecx = memoryAGet32(ds, esp + 0x24);
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x0000006c;
    // SEH removed (was stack_unbalanced, 0/-333) // SEH removed (was stack_unbalanced, 0/-333)
    esp += 4;
}
void sub_11003803() // 0000:11003803 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd4;
    push32(ebx);
    push32(esi);
    push32(edi);
    edx = memoryAGet32(ds, 0x11146c90);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(memoryAGet32(ds, edx + 0x1c));
    eax = ebp - 44;
    push32(eax);
    sub_11002f74();
    memoryASet32(ss, ebp - 4, 0x00000028);
    if (memoryAGet32(ss, ebp + 0x10) == 0x00000001)
        goto loc_11003912;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_11003839: // 0000:11003839
    if (memoryAGet32(ss, ebp - 4))
        goto loc_11003854;
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    sub_110039bb();
    goto loc_1100389d;
loc_11003854: // 0000:11003854
    if (memoryAGet32(ss, ebp - 4) == 0x00000028)
        goto loc_11003990;
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_11003990;
    ecx = memoryAGet32(ss, ebp - 4);
    ecx--;
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 286551196;
    ecx = memoryAGet32(ds, ebx + 0x80);
    ecx = (int32_t)ecx * (int32_t)0x00000020;
    ebx = ecx + ebx;
    push32(memoryAGet32(ds, ebx + 0x14));
    push32(memoryAGet32(ds, ebx + 0x10));
    push32(memoryAGet32(ds, ebx + 0xc));
    push32(memoryAGet32(ds, ebx + 0x8));
    push32(memoryAGet32(ds, ebx + 0x4));
    push32(memoryAGet32(ds, ebx));
    push32(memoryAGet32(ss, ebp - 4));
    sub_110039bb();
loc_1100389d: // 0000:1100389d
    ecx = memoryAGet32(ss, ebp - 4);
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 286551196;
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
    memoryASet32(ds, ebx + 0x84, 0x00000000);
    ecx = memoryAGet32(ss, ebp - 4);
    edx = ebp - 44;
    edx = memoryAGet(ds, ecx + edx);
    ecx = 0;
    edi = 0;
loc_110038ce: // 0000:110038ce
    memoryASet32(ds, ecx + ebx + 0x1c, 0x00000000);
    eax = memoryAGet32(ds, ecx + ebx + 0x18);
    if (eax != edx)
        goto loc_110038fb;
    memoryASet32(ds, ecx + ebx + 0x1c, 0x00000001);
    memoryASet32(ds, ebx + 0x84, memoryAGet32(ds, ebx + 0x84) + 1);
    if (memoryAGet32(ds, ebx + 0x80) != 0xffffffff)
        goto loc_110038fb;
    memoryASet32(ds, ebx + 0x80, edi);
loc_110038fb: // 0000:110038fb
    ecx = ecx + 32;
    edi++;
    if (edi != 0x00000004)
        goto loc_110038ce;
    if (memoryAGet32(ds, ebx + 0x80) == 0xffffffff)
        goto loc_11003912;
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) + 1);
    goto loc_11003986;
loc_11003912: // 0000:11003912
    ecx = memoryAGet32(ss, ebp - 4);
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_11003986;
    ecx--;
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 286551196;
    if (!memoryAGet32(ds, ebx + 0x84))
        goto loc_11003966;
    memoryASet32(ds, ebx + 0x80, memoryAGet32(ds, ebx + 0x80) + 1);
    edi = memoryAGet32(ds, ebx + 0x80);
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
    goto loc_1100395f;
loc_11003949: // 0000:11003949
    ecx = 0;
    ecx = (int32_t)edi * (int32_t)0x00000020;
    eax = memoryAGet32(ds, ecx + ebx + 0x1c);
    if (!eax)
        goto loc_1100395e;
    memoryASet32(ds, ebx + 0x80, edi);
    goto loc_11003970;
loc_1100395e: // 0000:1100395e
    edi++;
loc_1100395f: // 0000:1100395f
    if (edi != 0x00000004)
        goto loc_11003949;
    goto loc_11003970;
loc_11003966: // 0000:11003966
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
loc_11003970: // 0000:11003970
    if (memoryAGet32(ds, ebx + 0x80) == 0xffffffff)
        goto loc_1100397b;
    goto loc_11003986;
loc_1100397b: // 0000:1100397b
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) - 1);
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_11003986;
    goto loc_11003912;
loc_11003986: // 0000:11003986
    if (memoryAGet32(ss, ebp - 4))
        goto loc_11003839;
loc_11003990: // 0000:11003990
    if (memoryAGet32(ss, ebp - 4) != 0x00000028)
        goto loc_110039b4;
    ebx = 0x11146c9c;
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0;
loc_110039a0: // 0000:110039a0
    eax = (int32_t)ecx * (int32_t)0x00000088;
    eax = memoryAGet32(ds, eax + ebx + 0x80);
    stosb<ES_EDI>(al);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_110039a0;
loc_110039b4: // 0000:110039b4
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 12/-36) // SEH removed (was stack_unbalanced, 12/-36)
    esp += 16;
}
void sub_110039bb() // 0000:110039bb +long +stackDrop28
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff8;
    push32(ebx);
    push32(esi);
    ecx = memoryAGet32(ss, ebp + 0x8);
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 286551196;
    esi = memoryAGet32(ds, 0x11146c90);
    ecx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000000;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x1102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000000;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000001;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x1102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000001;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000002;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x1102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000002;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000003;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x1102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000003;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x11035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x11035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 28/16) // SEH removed (was stack_below, 28/16)
    esp += 32;
}
void sub_1100430e() // 0000:1100430e +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x11051cb0);
    push32(0x11051d00);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_11004337() // 0000:11004337 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x11146c90, 0x11051c90);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
loc_11004355: // 0000:11004355
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_1100430e();
    if (!eax)
        goto loc_11004375;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
    goto loc_11004355;
loc_11004375: // 0000:11004375
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_11004379() // 0000:11004379 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x11051fc8);
    push32(0x11052018);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_110043a2() // 0000:110043a2 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x11146c90, 0x11051fa8);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
loc_110043c0: // 0000:110043c0
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_11004379();
    if (!eax)
        goto loc_110043e0;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
    goto loc_110043c0;
loc_110043e0: // 0000:110043e0
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_110043e4() // 0000:110043e4 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x110522e0);
    push32(0x11052330);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_1100440d() // 0000:1100440d +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x11146c90, 0x110522c0);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
loc_1100442b: // 0000:1100442b
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_110043e4();
    if (!eax)
        goto loc_1100444b;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
    goto loc_1100442b;
loc_1100444b: // 0000:1100444b
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_1100444f() // 0000:1100444f +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x110525f8);
    push32(0x11052648);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_11004478() // 0000:11004478 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x11146c90, 0x110525d8);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
loc_11004496: // 0000:11004496
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_1100444f();
    if (!eax)
        goto loc_110044b6;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11003803();
    goto loc_11004496;
loc_110044b6: // 0000:110044b6
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_110044ba() // 0000:110044ba +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, 0x11146c94);
    esi = 0x1102cf48;
    ecx = 0x00000028;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x1102cde0);
    sub_1100101d();
    if (eax)
        goto loc_110044f1;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11004337();
    goto loc_11004558;
loc_110044f1: // 0000:110044f1
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x1102ce30);
    sub_1100101d();
    if (eax)
        goto loc_11004511;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_110043a2();
    goto loc_11004558;
loc_11004511: // 0000:11004511
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x1102ce80);
    sub_1100101d();
    if (eax)
        goto loc_11004531;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1100440d();
    goto loc_11004558;
loc_11004531: // 0000:11004531
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x1102ced0);
    sub_1100101d();
    if (eax)
        goto loc_11004551;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11004478();
    goto loc_11004558;
loc_11004551: // 0000:11004551
    push32(0x00000000);
    sub_1100606c();
loc_11004558: // 0000:11004558
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_11004560() // 0000:11004560 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00a1cb58)
        goto loc_11004589;
    eax = 0x0000015e;
    goto loc_1100458b;
loc_11004589: // 0000:11004589
    eax = 0;
loc_1100458b: // 0000:1100458b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_110045d0() // 0000:110045d0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    { uint32_t _a = eax, _b = memoryAGet32(ds, ebx + 0x4);
      printf("  factory check: arg=0x%08x [ebx+4]=0x%08x diff=0x%08x (need 0x00581450)\n", _a, _b, _a - _b); }
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00581450)
        goto loc_110045f9;
    eax = 0x000000dc;
    goto loc_110045fb;
loc_110045f9: // 0000:110045f9
    eax = 0;
loc_110045fb: // 0000:110045fb
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11004600() // 0000:11004600 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    push32(ebx);
    ebx = ebp - 40;
    push32(0x110df318);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x110df200);
    sub_11001181();
    push32(0x110e0618);
    push32(0x110df2c8);
    push32(0x110df2a0);
    push32(0x110df250);
    push32(ebx);
    sub_11001200();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11004640() // 0000:11004640 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x0155daa0)
        goto loc_11004669;
    eax = 0x000001ae;
    goto loc_1100466b;
loc_11004669: // 0000:11004669
    eax = 0;
loc_1100466b: // 0000:1100466b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11004670() // 0000:11004670 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    push32(ebx);
    ebx = ebp - 40;
    push32(0x110fbc18);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x110fbb00);
    sub_11001181();
    push32(0x110fcf18);
    push32(0x110fbbc8);
    push32(0x110fbba0);
    push32(0x110fbb50);
    push32(ebx);
    sub_11001200();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_110046b0() // 0000:110046b0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffdc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    memoryASet32(ss, ebp - 32, 0x00000000);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_110046d1: // 0000:110046d1
    push32(edi);
    esi = 0x11052858;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (!flags.zero)
        goto loc_110046e4;
    memoryASet32(ss, ebp - 32, memoryAGet32(ss, ebp - 32) + 1);
loc_110046e4: // 0000:110046e4
    if (memoryAGet32(ss, ebp - 32) == 0x00000002)
        goto loc_110046ed;
    edi++;
    goto loc_110046d1;
loc_110046ed: // 0000:110046ed
    memoryASet32(ds, 0x111481e4, edi);
    goto loc_11004718;
    // gap 35 bytes // gap 35 bytes
loc_11004718: // 0000:11004718
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1100471b: // 0000:1100471b
    push32(edi);
    esi = 0x11052880;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_1100472e;
    edi++;
    goto loc_1100471b;
loc_1100472e: // 0000:1100472e
    memoryASet32(ds, 0x111481e8, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_11004737: // 0000:11004737
    esi = memoryAGet32(ds, 0x111481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11004749;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1100474c;
loc_11004749: // 0000:11004749
    edi++;
    goto loc_11004737;
loc_1100474c: // 0000:1100474c
    push32(edi);
loc_1100474d: // 0000:1100474d
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11004759;
    goto loc_1100474d;
loc_11004759: // 0000:11004759
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_11004775: // 0000:11004775
    esi = memoryAGet32(ds, 0x111481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11004787;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1100478a;
loc_11004787: // 0000:11004787
    edi++;
    goto loc_11004775;
loc_1100478a: // 0000:1100478a
    push32(edi);
loc_1100478b: // 0000:1100478b
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11004797;
    goto loc_1100478b;
loc_11004797: // 0000:11004797
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_110047b3: // 0000:110047b3
    esi = memoryAGet32(ds, 0x111481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_110047c5;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_110047c8;
loc_110047c5: // 0000:110047c5
    edi++;
    goto loc_110047b3;
loc_110047c8: // 0000:110047c8
    push32(edi);
loc_110047c9: // 0000:110047c9
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_110047d5;
    goto loc_110047c9;
loc_110047d5: // 0000:110047d5
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_110047f1: // 0000:110047f1
    esi = memoryAGet32(ds, 0x111481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11004803;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11004806;
loc_11004803: // 0000:11004803
    edi++;
    goto loc_110047f1;
loc_11004806: // 0000:11004806
    push32(edi);
loc_11004807: // 0000:11004807
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11004813;
    goto loc_11004807;
loc_11004813: // 0000:11004813
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1100482f: // 0000:1100482f
    esi = memoryAGet32(ds, 0x111481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_11004841;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_11004844;
loc_11004841: // 0000:11004841
    edi++;
    goto loc_1100482f;
loc_11004844: // 0000:11004844
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_11004850;
    goto loc_11004844;
loc_11004850: // 0000:11004850
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_11006072();
    esi = 0x110046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-128) // SEH removed (was stack_unbalanced, 4/-128)
    esp += 8;
}
void sub_11005a60() // 0000:11005a60 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00580408)
        goto loc_11005a89;
    eax = 0x00000079;
    goto loc_11005a8b;
loc_11005a89: // 0000:11005a89
    eax = 0;
loc_11005a8b: // 0000:11005a8b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11005ad0() // 0000:11005ad0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x0067d268)
        goto loc_11005af9;
    eax = 0x00000262;
    goto loc_11005afb;
loc_11005af9: // 0000:11005af9
    eax = 0;
loc_11005afb: // 0000:11005afb
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11005dc6() // 0000:11005dc6 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00ea9550)
        goto loc_11005def;
    eax = 0x0000006e;
    goto loc_11005df1;
loc_11005def: // 0000:11005def
    eax = 0;
loc_11005df1: // 0000:11005df1
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_11005e70() // 0000:11005e70 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = 0x1109c770;
loc_11005e7b: // 0000:11005e7b
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_11001000();
    if (eax)
        goto loc_11005e97;
    esi = ebx + 16;
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0x00000004;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    goto loc_11005e9f;
loc_11005e97: // 0000:11005e97
    ebx = ebx + 32;
    if (memoryAGet32(ds, ebx))
        goto loc_11005e7b;
loc_11005e9f: // 0000:11005e9f
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_11005ea6() // 0000:11005ea6 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    if (memoryAGet32(ss, ebp + 0xc))
        goto loc_11005ede;
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(0x0000008b);
    push32(0x00000040);
    sub_11006054();
    memoryASet32(ds, ebx + 0x28, eax);
    memoryASet32(ds, ebx + 0x2c, 0x0000008b);
    edi = eax;
    esi = 0x110a5834;
    ecx = 0x0000008b;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    goto loc_11005f79;
loc_11005ede: // 0000:11005ede
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000001)
        goto loc_11005f12;
    ebx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, ebx + 0x14);
    memoryASet32(ds, ebx + 0x1c, eax);
    esi = memoryAGet32(ds, ebx + 0x10);
    edi = memoryAGet32(ds, ebx + 0x18);
    ebx = memoryAGet32(ds, ebx + 0x1c);
loc_11005ef6: // 0000:11005ef6
    push32(0x110a58df);
    push32(edi);
    push32(esi);
    sub_11001157();
    esi = esi + 16;
    edi = edi + 16;
    ebx = ebx - 16;
    if (ebx > 0x00000000)
        goto loc_11005ef6;
    goto loc_11005f79;
loc_11005f12: // 0000:11005f12
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000002)
        goto loc_11005f64;
    ebx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, ebx + 0x8);
    eax = eax + 91;
    printf("  DCP decrypt: keyLookup at 0x%08x, keyTable=0x11149770\n", eax);
    printf("    key bytes: "); for(int _k=0;_k<16;_k++) printf("%02x",memoryAGet(ds,eax+_k)); printf("\n");
    push32(0x11149770);
    push32(eax);
    sub_11005e70();
    printf("  DCP key verification: eax=%d (%s)\n", eax, eax?"FAIL":"OK");
    if (eax)
        goto loc_11005f5b;
    eax = memoryAGet32(ds, ebx + 0x1c);
    memoryASet32(ds, ebx + 0x24, eax);
    esi = memoryAGet32(ds, ebx + 0x18);
    edi = memoryAGet32(ds, ebx + 0x20);
    ebx = memoryAGet32(ds, ebx + 0x24);
loc_11005f3f: // 0000:11005f3f
    push32(0x11149770);
    push32(edi);
    push32(esi);
    sub_1100112d();
    esi = esi + 16;
    edi = edi + 16;
    ebx = ebx - 16;
    if (ebx > 0x00000000)
        goto loc_11005f3f;
    goto loc_11005f79;
loc_11005f5b: // 0000:11005f5b
    memoryASet32(ds, ebx + 0x24, 0x00000000);
    goto loc_11005f79;
loc_11005f64: // 0000:11005f64
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000003)
        goto loc_11005f79;
    esi = 0x110a58bf;
    edi = memoryAGet32(ss, ebp + 0x8);
    ecx = 0x00000004;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
loc_11005f79: // 0000:11005f79
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_11006054() // GlobalAlloc (stdcall, 2 args: flags, size)
{ uint32_t flags=memoryAGet32(ss,esp); uint32_t size=memoryAGet32(ss,esp+4);
  if(!size) size=32; // minimum alloc
  eax=allocate(size); printf("  SYNSO GlobalAlloc(flags=0x%x,sz=%d)=0x%08x\n",flags,size,eax); esp+=8; }
void sub_1100605a() // GlobalFree thunk
{ esp+=4; eax=0; }
void sub_11006060() // RaiseException thunk
{ printf("  SYNSO RaiseException!\n"); esp+=16; }
void sub_11006066() // VirtualQuery (stdcall, 3 args: addr, buf, len)
{ esp -= 4; // synthetic
  uint32_t addr=memoryAGet32(ss,esp+4); uint32_t buf=memoryAGet32(ss,esp+8);
  printf("  VirtualQuery(addr=0x%08x, buf=0x%08x)\n", addr, buf);
  if(buf){
    // Determine allocation base from address
    uint32_t allocBase = 0x10000000; // default: main DLL base
    if (addr >= 0x11000000 && addr < 0x11200000) allocBase = 0x11000000; // SYNSOEMU
    memoryASet32(ds,buf+0x00,addr);       // BaseAddress
    memoryASet32(ds,buf+0x04,allocBase);  // AllocationBase
    memoryASet32(ds,buf+0x08,0x40);       // AllocationProtect (PAGE_EXECUTE_READWRITE)
    memoryASet32(ds,buf+0x0C,0x1000);     // RegionSize
    memoryASet32(ds,buf+0x10,0x1000);     // State (MEM_COMMIT)
    memoryASet32(ds,buf+0x14,0x40);       // Protect
    memoryASet32(ds,buf+0x18,0x1000000);  // Type (MEM_IMAGE)
  } eax=28; esp+=16; } // +4 synthetic +12 stdcall
void sub_1100606c() // ExitProcess thunk
{ printf("  SYNSO ExitProcess!\n"); esp+=4; }
void sub_11006072() // VirtualProtect thunk
{ uint32_t oldProt=memoryAGet32(ss,esp+16); if(oldProt) memoryASet32(ds,oldProt,0x40); eax=1; esp+=16; }

