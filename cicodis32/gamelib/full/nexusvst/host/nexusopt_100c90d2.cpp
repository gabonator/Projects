#include <stdint.h>

static inline unsigned char ascii_tolower(unsigned char c)
{
    if (c >= 'A' && c <= 'Z')
        c = (unsigned char)(c + 0x20);

    return c;
}

// Native fast ASCII-only strcmpi.
// Matches the visible fallback loop in the disassembly.
int sub_100c90d2_native(const char* a, const char* b)
{
    if (!a || !b)
        return 0x7fffffff;

    for (;;)
    {
        unsigned char ca = ascii_tolower((unsigned char)*a++);
        unsigned char cb = ascii_tolower((unsigned char)*b++);

        if (ca == 0 || ca != cb)
            return (int)ca - (int)cb;
    }
}

// Portable drop-in stack wrapper.
void sub_100c90d2()
{
    const char* a = *(const char**)(esp + 0);
    const char* b = *(const char**)(esp + 4);

    eax = sub_100c90d2_native(a, b);
}

#if 0
void sub_100c90d2() // 0000:100c90d2 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    goto loc_100c90d2;
loc_100c8fc4: // 0000:100c8fc4
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
loc_100c8fd1: // 0000:100c8fd1
    eax = memoryAGet(ds, esi);
    ecx = eax - 65;
    esi++;
    if (ecx > 0x00000019)
        goto loc_100c8fe0;
    eax += 0x00000020;
loc_100c8fe0: // 0000:100c8fe0
    ecx = memoryAGet(ds, edx);
    edi = ecx - 65;
    edx++;
    if (edi > 0x00000019)
        goto loc_100c8fef;
    ecx += 0x00000020;
loc_100c8fef: // 0000:100c8fef
    if (!eax)
        goto loc_100c8ff7;
    if (eax == ecx)
        goto loc_100c8fd1;
loc_100c8ff7: // 0000:100c8ff7
    edi = pop32();
    eax -= ecx;
    esi = pop32();
    ebp = pop32();
    esp += 4; return;
    // gap 213 bytes // gap 213 bytes
loc_100c90d2: // 0000:100c90d2
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = 0;
    if (memoryAGet32(ds, 0x10582164) != esi)
        goto loc_100c9112;
    if (memoryAGet32(ss, ebp + 0x8) != esi)
        goto loc_100c9106;
loc_100c90e7: // 0000:100c90e7
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax = 0x7fffffff;
    goto loc_100c9121;
loc_100c9106: // 0000:100c9106
    if (memoryAGet32(ss, ebp + 0xc) == esi)
        goto loc_100c90e7;
    esi = pop32();
    ebp = pop32();
    goto loc_100c8fc4;
loc_100c9112: // 0000:100c9112
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8ffd();
    esp += 0x0000000c;
loc_100c9121: // 0000:100c9121
    esi = pop32();
    ebp = pop32();
    esp += 4;
}

void sub_100cbff1() // 0000:100cbff1 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    sub_100d1219();
    if (eax)
        goto loc_100cc000;
    eax = 0x1057deb0;
    esp += 4; return;
loc_100cc000: // 0000:100cc000
    eax += 0x00000008;
    esp += 4;
}

void sub_100c90d2() // 0000:100c90d2 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    goto loc_100c90d2;
loc_100c8fc4: // 0000:100c8fc4
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
loc_100c8fd1: // 0000:100c8fd1
    eax = memoryAGet(ds, esi);
    ecx = eax - 65;
    esi++;
    if (ecx > 0x00000019)
        goto loc_100c8fe0;
    eax += 0x00000020;
loc_100c8fe0: // 0000:100c8fe0
    ecx = memoryAGet(ds, edx);
    edi = ecx - 65;
    edx++;
    if (edi > 0x00000019)
        goto loc_100c8fef;
    ecx += 0x00000020;
loc_100c8fef: // 0000:100c8fef
    if (!eax)
        goto loc_100c8ff7;
    if (eax == ecx)
        goto loc_100c8fd1;
loc_100c8ff7: // 0000:100c8ff7
    edi = pop32();
    eax -= ecx;
    esi = pop32();
    ebp = pop32();
    esp += 4; return;
    // gap 213 bytes // gap 213 bytes
loc_100c90d2: // 0000:100c90d2
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = 0;
    if (memoryAGet32(ds, 0x10582164) != esi)
        goto loc_100c9112;
    if (memoryAGet32(ss, ebp + 0x8) != esi)
        goto loc_100c9106;
loc_100c90e7: // 0000:100c90e7
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax = 0x7fffffff;
    goto loc_100c9121;
loc_100c9106: // 0000:100c9106
    if (memoryAGet32(ss, ebp + 0xc) == esi)
        goto loc_100c90e7;
    esi = pop32();
    ebp = pop32();
    goto loc_100c8fc4;
loc_100c9112: // 0000:100c9112
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8ffd();
    esp += 0x0000000c;
loc_100c9121: // 0000:100c9121
    esi = pop32();
    ebp = pop32();
    esp += 4;
}

void sub_100c8ffd() // 0000:100c8ffd +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000010;
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x10));
    ecx = ebp - 16;
    sub_100c8f3d();
    ebx = 0;
    if (memoryAGet32(ss, ebp + 0x8) != ebx)
        goto loc_100c9046;
    sub_100cbff1();
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    if (memoryAGet(ss, ebp - 4) == bl)
        goto loc_100c903c;
    eax = memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, eax + 0x70, memoryAGet32(ds, eax + 0x70) & 0xfffffffd);
loc_100c903c: // 0000:100c903c
    eax = 0x7fffffff;
    goto loc_100c90cf;
loc_100c9046: // 0000:100c9046
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0xc);
    if (edi != ebx)
        goto loc_100c9079;
    sub_100cbff1();
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    if (memoryAGet(ss, ebp - 4) == bl)
        goto loc_100c9072;
    eax = memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, eax + 0x70, memoryAGet32(ds, eax + 0x70) & 0xfffffffd);
loc_100c9072: // 0000:100c9072
    eax = 0x7fffffff;
    goto loc_100c90ce;
loc_100c9079: // 0000:100c9079
    eax = memoryAGet32(ss, ebp - 16);
    if (memoryAGet32(ds, eax + 0x14) != ebx)
        goto loc_100c908e;
    push32(edi);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8fc4();
    ecx = pop32();
    ecx = pop32();
    goto loc_100c90c2;
loc_100c908e: // 0000:100c908e
    push32(esi);
loc_100c908f: // 0000:100c908f
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet(ds, eax);
    ecx = ebp - 16;
    push32(ecx);
    push32(eax);
    sub_100cd31b();
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) + 1);
    esi = eax;
    eax = memoryAGet(ds, edi);
    ecx = ebp - 16;
    push32(ecx);
    push32(eax);
    sub_100cd31b();
    esp += 0x00000010;
    edi++;
    if (esi == ebx)
        goto loc_100c90bd;
    if (esi == eax)
        goto loc_100c908f;
loc_100c90bd: // 0000:100c90bd
    esi -= eax;
    eax = esi;
    esi = pop32();
loc_100c90c2: // 0000:100c90c2
    if (memoryAGet(ss, ebp - 4) == bl)
        goto loc_100c90ce;
    ecx = memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, ecx + 0x70, memoryAGet32(ds, ecx + 0x70) & 0xfffffffd);
loc_100c90ce: // 0000:100c90ce
    edi = pop32();
loc_100c90cf: // 0000:100c90cf
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-24) // SEH removed (was stack_unbalanced, 0/-24)
    esp += 4;
}

void sub_100c8fc4() // 0000:100c8fc4 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
loc_100c8fd1: // 0000:100c8fd1
    eax = memoryAGet(ds, esi);
    ecx = eax - 65;
    esi++;
    if (ecx > 0x00000019)
        goto loc_100c8fe0;
    eax += 0x00000020;
loc_100c8fe0: // 0000:100c8fe0
    ecx = memoryAGet(ds, edx);
    edi = ecx - 65;
    edx++;
    if (edi > 0x00000019)
        goto loc_100c8fef;
    ecx += 0x00000020;
loc_100c8fef: // 0000:100c8fef
    if (!eax)
        goto loc_100c8ff7;
    if (eax == ecx)
        goto loc_100c8fd1;
loc_100c8ff7: // 0000:100c8ff7
    edi = pop32();
    eax -= ecx;
    esi = pop32();
    ebp = pop32();
    esp += 4;
}

void sub_100cd31b() // 0000:100cd31b +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000018;
    push32(ebx);
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0xc));
    ecx = ebp - 24;
    sub_100c8f3d();
    ebx = memoryAGet32(ss, ebp + 0x8);
    esi = 0x00000100;
    if (ebx >= esi)
        goto loc_100cd390;
    ecx = memoryAGet32(ss, ebp - 24);
    if ((int32_t)memoryAGet32(ds, ecx + 0xac) <= (int32_t)0x00000001)
        goto loc_100cd35c;
    eax = ebp - 24;
    push32(eax);
    push32(0x00000001);
    push32(ebx);
    sub_100d2d11();
    ecx = memoryAGet32(ss, ebp - 24);
    esp += 0x0000000c;
    goto loc_100cd369;
loc_100cd35c: // 0000:100cd35c
    eax = memoryAGet32(ds, ecx + 0xc8);
    eax = memoryAGet16(ds, eax + ebx * 2);
    eax &= 0x00000001;
loc_100cd369: // 0000:100cd369
    if (!eax)
        goto loc_100cd37c;
    eax = memoryAGet32(ds, ecx + 0xcc);
    eax = memoryAGet(ds, eax + ebx);
    goto loc_100cd41f;
loc_100cd37c: // 0000:100cd37c
    if (!memoryAGet(ss, ebp - 12))
        goto loc_100cd389;
    eax = memoryAGet32(ss, ebp - 16);
    memoryASet32(ds, eax + 0x70, memoryAGet32(ds, eax + 0x70) & 0xfffffffd);
loc_100cd389: // 0000:100cd389
    eax = ebx;
    goto loc_100cd42c;
loc_100cd390: // 0000:100cd390
    eax = memoryAGet32(ss, ebp - 24);
    if ((int32_t)memoryAGet32(ds, eax + 0xac) <= (int32_t)0x00000001)
        goto loc_100cd3cd;
    memoryASet32(ss, ebp + 0x8, ebx);
    memoryASet32(ss, ebp + 0x8, sar32(memoryAGet32(ss, ebp + 0x8), 0x08));
    eax = ebp - 24;
    push32(eax);
    eax = memoryAGet32(ss, ebp + 0x8);
    eax &= 0x000000ff;
    push32(eax);
    sub_100d5670();
    ecx = pop32();
    ecx = pop32();
    if (!eax)
        goto loc_100cd3cd;
    al = memoryAGet(ss, ebp + 0x8);
    push32(0x00000002);
    memoryASet(ss, ebp - 4, al);
    memoryASet(ss, ebp - 3, bl);
    memoryASet(ss, ebp - 2, 0x00);
    ecx = pop32();
    goto loc_100cd3e2;
loc_100cd3cd: // 0000:100cd3cd
    sub_100cbff1();
    memoryASet32(ds, eax, 0x0000002a);
    ecx = 0;
    memoryASet(ss, ebp - 4, bl);
    memoryASet(ss, ebp - 3, 0x00);
    ecx++;
loc_100cd3e2: // 0000:100cd3e2
    eax = memoryAGet32(ss, ebp - 24);
    push32(0x00000001);
    push32(memoryAGet32(ds, eax + 0x4));
    edx = ebp - 8;
    push32(0x00000003);
    push32(edx);
    push32(ecx);
    ecx = ebp - 4;
    push32(ecx);
    push32(esi);
    push32(memoryAGet32(ds, eax + 0x14));
    eax = ebp - 24;
    push32(eax);
    sub_100cbe39();
    esp += 0x00000024;
    if (!eax)
        goto loc_100cd37c;
    flags.zero = eax == 0x00000001;
    eax = memoryAGet(ss, ebp - 8);
    if (flags.zero)
        goto loc_100cd41f;
    ecx = memoryAGet(ss, ebp - 7);
    eax <<= 8;
    eax |= ecx;
loc_100cd41f: // 0000:100cd41f
    if (!memoryAGet(ss, ebp - 12))
        goto loc_100cd42c;
    ecx = memoryAGet32(ss, ebp - 16);
    memoryASet32(ds, ecx + 0x70, memoryAGet32(ds, ecx + 0x70) & 0xfffffffd);
loc_100cd42c: // 0000:100cd42c
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-32) // SEH removed (was stack_unbalanced, 0/-32)
    esp += 4;
}

void sub_100cbe39() // 0000:100cbe39 +long
{
    StackGuard _sg(0, __FUNCTION__);
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000010;
    push32(memoryAGet32(ss, ebp + 0x8));
    ecx = ebp - 16;
    sub_100c8f3d();
    push32(memoryAGet32(ss, ebp + 0x28));
    ecx = ebp - 16;
    push32(memoryAGet32(ss, ebp + 0x24));
    push32(memoryAGet32(ss, ebp + 0x20));
    push32(memoryAGet32(ss, ebp + 0x1c));
    push32(memoryAGet32(ss, ebp + 0x18));
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    sub_100cba94();
    esp += 0x00000038; // SEH fixed: was +32, deficit 24
    if (!memoryAGet(ss, ebp - 4))
        goto loc_100cbe7c;
    ecx = memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, ecx + 0x70, memoryAGet32(ds, ecx + 0x70) & 0xfffffffd);
loc_100cbe7c: // 0000:100cbe7c
    esp = ebp; ebp = pop32();
    // SEH fixed (was stack_unbalanced, 0/-24) // SEH fixed (was stack_unbalanced, 0/-24)
    esp += 4;
}

void sub_100d1219() // 0000:100d1219 +long — __getptd_noexit (thread-local storage)
{
    static uint32_t getptdptr = 0;
    // used by rand, eax+0x14 = rand seed
    if (getptdptr == 0)
        getptdptr = allocate(32);
    eax = getptdptr;
}

void sub_100c8f3d() // 0000:100c8f3d +long +stackDrop4
{ esp -= 4; esp += 8; } // stub +stackDrop4 (no-op)

void sub_100cb27c() // 0000:100cb27c +long — CRT invalid parameter handler
{
    printf("FATAL: unimplemented CRT function sub_100cb27c called\n"); abort();
}


//	    sub_100cbe39();
//	    sub_100d2d11();
//	    sub_100d5670();
#endif