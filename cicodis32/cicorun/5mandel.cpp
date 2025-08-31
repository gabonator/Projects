#if 0
#include "cico32.h"

void sub_15e010();
void start()
{
    ds = 0x7777;
    esp = 0x200;
    loadAddress = 0;
    endAddress = 0x40000;
    load("", "MEMDUMP.BIN", 0x40000);
    sub_15e010();
    while (1)
        sync();
}

void sub_15e010();
void sub_15e27b();
void sub_15e2b0();
void sub_15e2d0();
void sub_15e2dc();
void sub_15e2f0();
void sub_15e358();
void sub_15e370();
void sub_15e390();
void sub_15e3a4();
void sub_15e6e0();
void sub_15e710();
void sub_15e7e0();
void sub_15e820();
void sub_15e830();
void sub_15e880();
void sub_15fa60();
void sub_15fa88();
void sub_15fac8();
void sub_15fee0();
void sub_164000();

void sub_15e010()
{
    push32(0x0000009c);
//    sub_15e27b();
    push32(ebx);
    push32(ecx);
    push32(edx);
    push32(esi);
    push32(edi);
    push32(ebp);
    esp -= 0x00000080;
    eax = 0;
    memoryASet32(ds, esp + 108, eax);
    memoryASet32(ds, esp + 112, 0xbff80000);
    memoryASet32(ds, esp + 116, eax);
    memoryASet32(ds, esp + 120, 0xbff00000);
    memoryASet32(ds, esp + 52, eax);
    edi = 0x40000000;
    memoryASet32(ds, esp + 56, edi);
    memoryASet32(ds, esp + 76, eax);
    memoryASet32(ds, esp + 80, edi);
    ebp = 0x000a0000;
    memoryASet16(ds, esp, 0x0013);
    ebx = esp;
    edx = esp;
    eax = 0x00000010;
    sub_15e2b0(); // eax = int 10h, ds:esp=13, RESETS EBP!
    eax = 0;
    ecx = 0;
loc_15e072:
    edx = ecx;
    eax = 0x000003c8;
    sub_15e2d0();
//    stop("propagate sign flag");
    memoryASet32(ds, esp + 124, ecx);
    fild32(memoryAGet32(ds, esp + 124));
    fmul64(memoryAGet64(ds, 0x17c004));
    memoryASet64(ds, esp + 36, fstp64());
    fld1();
    fmul64(memoryAGet64(ds, esp + 36));
    sub_15e2dc();
    fmul64(memoryAGet64(ds, 0x17c00c));
    fsubr64(memoryAGet64(ds, 0x17c014));
    sub_15e358();
    memoryASet64(ds, esp + 84, fistp64());
    edx = memoryAGet32(ds, esp + 84);
    eax = 0x000003c9;
    sub_15e2d0();
    fld64(memoryAGet64(ds, esp + 36));
    fmul64(memoryAGet64(ds, 0x17c01c));
    sub_15e2dc();
    fmul64(memoryAGet64(ds, 0x17c00c));
    fsubr64(memoryAGet64(ds, 0x17c014));
    sub_15e358();
    memoryASet64(ds, esp + 84, fistp64());
    edx = memoryAGet32(ds, esp + 84);
    eax = 0x000003c9;
    sub_15e2d0();
    fld64(memoryAGet64(ds, esp + 36));
    fmul64(memoryAGet64(ds, 0x17c024));
    sub_15e2dc();
    fmul64(memoryAGet64(ds, 0x17c00c));
    fsubr64(memoryAGet64(ds, 0x17c014));
    sub_15e358();
    memoryASet64(ds, esp + 84, fistp64());
    edx = memoryAGet32(ds, esp + 84);
    eax = 0x000003c9;
    sub_15e2d0();
    ecx++;
    if ((int32_t)ecx < (int32_t)0x00000100)
        goto loc_15e072;
    ebx = 0;
    goto loc_15e140;
loc_15e133:
    ebx++;
    if ((int32_t)ebx >= (int32_t)0x000000c8)
        goto loc_15e241;
loc_15e140:
    memoryASet32(ds, esp + 124, ebx);
    fild32(memoryAGet32(ds, esp + 124));
    fmul64(memoryAGet64(ds, esp + 76));
    fdiv64(memoryAGet64(ds, 0x17c02c));
    fadd64(memoryAGet64(ds, esp + 116));
    memoryASet64(ds, esp + 68, fstp64());
    ecx = 0;
    goto loc_15e210;
loc_15e161:
    edx++;
    if (edx > 0x00000100)
        goto loc_15e1cf;
loc_15e16a:
    fld64(memoryAGet64(ds, esp + 92));
    fmul80(st(0));
    fld64(memoryAGet64(ds, esp + 100));
    fmul80(st(0));
    fsubp80(); //st(1));
    fadd64(memoryAGet64(ds, esp + 44));
    memoryASet64(ds, esp + 28, fstp64());
    fld64(memoryAGet64(ds, esp + 92));
    fmul64(memoryAGet64(ds, 0x17c03c));
    fmul64(memoryAGet64(ds, esp + 100));
    fadd64(memoryAGet64(ds, esp + 68));
    memoryASet64(ds, esp + 60, fstp64());
    eax = memoryAGet32(ds, esp + 28);
    memoryASet32(ds, esp + 92, eax);
    eax = memoryAGet32(ds, esp + 32);
    memoryASet32(ds, esp + 96, eax);
    eax = memoryAGet32(ds, esp + 60);
    memoryASet32(ds, esp + 100, eax);
    eax = memoryAGet32(ds, esp + 64);
    memoryASet32(ds, esp + 104, eax);
    fld64(memoryAGet64(ds, esp + 28));
    fmul80(st(0));
    fld64(memoryAGet64(ds, esp + 60));
    fmul80(st(0));
    faddp80(st(1));
    fcomp64(memoryAGet64(ds, 0x17c044));
    ax = fnstsw();
    sahf();
    if (flags.carry)
        goto loc_15e161;
loc_15e1cf:
    if (edx >= 0x00000100)
        goto loc_15e203;
    memoryASet32(ds, esp + 124, edx);
    fild32(memoryAGet32(ds, esp + 124));
    fmul64(memoryAGet64(ds, 0x17c04c));
    fmul64(memoryAGet64(ds, 0x17c054));
    sub_15e358();
    memoryASet32(ds, esp + 124, fistp32());
    al = memoryAGet(ds, esp + 124);
    edx = ebx * 0x00000140;
    edx += ebp;
    memoryASet(ds, ecx + edx, al);
loc_15e203:
    ecx++;
    if ((int32_t)ecx >= (int32_t)0x00000140)
        goto loc_15e133;
loc_15e210:
    memoryASet32(ds, esp + 124, ecx);
    fild32(memoryAGet32(ds, esp + 124));
    fmul64(memoryAGet64(ds, esp + 52));
    fdiv64(memoryAGet64(ds, 0x17c034));
    fadd64(memoryAGet64(ds, esp + 108));
    memoryASet64(ds, esp + 44, fstp64());
    edx = 0;
    memoryASet32(ds, esp + 92, edx);
    memoryASet32(ds, esp + 96, edx);
    memoryASet32(ds, esp + 100, edx);
    memoryASet32(ds, esp + 104, edx);
    goto loc_15e16a;
loc_15e241:
//    sub_15e370();
    memoryASet16(ds, esp, 0x0003);
    ebx = esp;
    edx = esp;
    eax = 0x00000010;
//    sub_15e2b0();
    eax = 0x00000001;
    esp += 0x00000080;
    ebp = pop32();
    edi = pop32();
    esi = pop32();
    edx = pop32();
    ecx = pop32();
    ebx = pop32();
//    stop("stack_unbalanced");
}
void sub_15e27b()
{
    push32(eax);
    eax = memoryAGet32(ds, esp + 8);
    if (eax >= esp)
        goto loc_15e2a0;
    eax -= esp;
    eax = -eax;
    flags.zero = eax == memoryAGet32(ds, 0x17c234);
    if (eax > memoryAGet32(ds, 0x17c234))
        goto loc_15e29a;
    ax = ss;
    flags.zero = ax == memoryAGet16(ds, 0x17c1f4);
loc_15e29a:
    if (flags.zero)
        goto loc_15e2a0;
    eax = pop32();
    stop("stack_below");
//    sp += 4; // CICO?
    return;
loc_15e2a0:
    eax = pop32();
    eax = 0x0017c1f6;
    edx = 0x00000001;
    goto loc_15e6c0;
  // gap 729 bytes
loc_15e589:
    push32(eax);
    goto loc_15e5bc;
loc_15e58c:
    push32(edx);
    push32(eax);
    edx = 0x0015e399;
    ax = 0x3d01;
    interrupt(0x21);
    bx = ax;
    edx = pop32();
    esi = edx;
    flags.direction = 0;
loc_15e5a0:
    al = lodsb<DS_ESI>();
    if (al)
        goto loc_15e5a0;
    ecx = esi;
    ecx -= edx;
    ecx--;
    ah = 0x40;
    interrupt(0x21);
    edx = 0x0015e39d;
    ecx = 0x00000002;
    ah = 0x40;
    interrupt(0x21);
loc_15e5bc:
    eax = 0;
    edx = 0x0000000f;
    sub_15e880();
    eax = pop32();
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
  // gap 243 bytes
loc_15e6c0:
    ebx = eax;
    ecx = edx;
    edx = ds;
    sub_15fa60();
    if (eax)
        goto loc_15e6d8;
    edx = ecx;
    eax = ebx;
    goto loc_15e58c;
loc_15e6d8:
    eax = ecx;
    goto loc_15e589;
}
void sub_15e2b0()
{
    push32(ecx);
    push32(esi);
    esp -= 0x0000000c;
    esi = eax;
    eax = esp;
    ecx = esp;
    sub_15e6e0();
    eax = esi;
    sub_15e710();
    esp += 0x0000000c;
    esi = pop32();
    ecx = pop32();
}
void sub_15e2d0()
{
    push32(ecx);
    ecx = eax;
    al = dl;
    edx = ecx;
    out8(dx, al);
    ecx = pop32();
}
void sub_15e2dc()
{
//loc_15e2dc:
    fcos();
//    sub_15e2f0();
//    stop("propagate sign flag");
//    if (!flags.carry)
//        goto loc_15e2dc;
}
void sub_15e2f0() // +returnCarry
{
    push32(ebp);
    ebp = esp;
    push32(eax);
    memoryASet16(ds, ebp + -2, fnstsw());
    ah = memoryAGet(ds, ebp + -1);
    ah |= 0x01;
    sahf();
    if (stop("build_condition_failed"))
        goto loc_15e31a;
    stop(); //fld80(memoryAGet80(ds, 0x17c208));
    stop(); //fxch(st(0));
loc_15e30a:
    stop(); //fprem();
    memoryASet16(ds, ebp + -2, fnstsw());
    ah = memoryAGet(ds, ebp + -1);
    sahf();
    if (stop("build_condition_failed"))
        goto loc_15e30a;
    stop(); //st(1) = fstp80();
    flags.carry = 0;
loc_15e31a:
    eax = pop32();
    ebp = pop32();
}
void sub_15e358()
{
//    push32(0x00000c3f);
//    stop(); //memoryASet16(ds, esp + 2, fnstcw());
//    stop(); //fldcw(memoryAGet16(ds, esp));
    frndtint();
//    stop(); //fldcw(memoryAGet16(ds, esp + 2));
//    esp = esp + 4;
//    stop("stack_unbalanced");
}
void sub_15e370()
{
    push32(edx);
    edx = 0;
    eax = memoryAGet32(ds, 0x17c244);
    memoryASet32(ds, 0x17c244, edx);
    if (!eax)
        goto loc_15e384;
    edx = pop32();
    return;
loc_15e384:
    ah = 0x08;
    interrupt(0x21);
    eax &= 0x000000ff;
    edx = pop32();
}
void sub_15e390()
{
  sub_15e3a4();
}

void sub_15e3a4()
{
    flags.interrupts = 1;
    esp &= 0xfffffffc;
    ebx = esp;
    memoryASet32(ds, 0x17c238, ebx);
    memoryASet32(ds, 0x17c224, ebx);
    ax = 0x0024;
    memoryASet16(ds, 0x17c230, ax);
    ebx = 0x50484152;
    eax = 0;
    ah = 0x30;
    interrupt(0x21);
    memoryASet(ds, 0x17c25a, al);
    memoryASet(ds, 0x17c25b, ah);
    ecx = eax;
    esi = 0;
    edi = 0x00000081;
    eax >>= 16;
    if (ax != 0x4458)
        goto loc_15e42e;
    ah = 0x00;
    if (ebx != 0x4a613231)
        goto loc_15e3f4;
    ah = 0x01;
loc_15e3f4:
    bl -= 0x2f;
    al = bl;
    push32(eax);
    stop();
    es = memoryAGet16(ds, 0x17c230);
    ebx = memoryAGet32(es, 0x005c);
    ebx += 0x00000fff;
    ebx &= 0xfffff000;
    memoryASet32(ds, 0x17c224, ebx);
    ebx >>= 12;
    eax = ds;
    es = eax;
    ah = 0x4a;
    interrupt(0x21);
    eax = pop32();
    ebx = ds;
    cx = 0x002c;
    goto loc_15e46f;
loc_15e42e:
    dx = 0x0078;
    ax = 0xff00;
    interrupt(0x21);
    if (!al)
        goto loc_15e46d;
    eax = gs;
    if (!ax)
        goto loc_15e449;
    memoryASet16(ds, 0x17c214, ax);
loc_15e449:
    ax = 0x0006;
    ebx = ds;
    interrupt(0x31);
    al = 0x01;
    ah = 0x00;
    dx |= cx;
    if (!dx)
        goto loc_15e45c;
    ah = 0x01;
loc_15e45c:
    memoryASet16(ds, 0x17c230, es);
    cx = memoryAGet16(es, 0x002c);
    goto loc_15e46f;
loc_15e46d:
    eax = 0;
loc_15e46f:
    memoryASet(ds, 0x17c251, al);
    memoryASet(ds, 0x17c252, ah);
    es = ebx;
    memoryASet16(es, 0x15e65d, ds);
    memoryASet32(ds, 0x17c254, esi);
    memoryASet16(ds, 0x17c258, cx);
    push32(esi);
    es = memoryAGet16(ds, 0x17c230);
    edx = 0x0017c75c;
    edx += 0x0000000f;
    dl &= 0xf0;
    ecx = 0;
    cl = memoryAGet(es, edi + -1);
    flags.direction = 0;
    al = 0x20;
    stop(); //repe_scasb_inv<ES_EDI>(al);
    esi = edi + -1;
    edi = edx;
    ebx = es;
    edx = ds;
    ds = ebx;
    es = edx;
    if (flags.zero)
        goto loc_15e4c1;
    ecx++;
    for (; cx != 0; --cx) movsb<ES_EDI, DS_ESI>();
loc_15e4c1:
    al = 0;
    stosb<ES_EDI>(al);
    stosb<ES_EDI>(al);
    esi = pop32();
    edi--;
    push32(edi);
    push32(edx);
    ds = memoryAGet16(es, 0x17c258);
    bx = 0x0100;
loc_15e4d5:
    eax = memoryAGet32(ds, esi);
    eax |= 0x20202020;
    if (eax != 0x37386f6e)
        goto loc_15e4ee;
    if (memoryAGet(ds, esi + 4) != 0x3d)
        goto loc_15e501;
    bl |= 0x01;
    goto loc_15e501;
loc_15e4ee:
    if (eax != 0x3d6e666c)
        goto loc_15e501;
    al = memoryAGet(ds, esi + 4);
    al |= 0x20;
    if (al != 0x6e)
        goto loc_15e501;
    bh &= 0xfe;
loc_15e501:
    al = lodsb<DS_ESI>();
    if (memoryAGet(ds, esi) != 0x00)
        goto loc_15e501;
    if (memoryAGet(ds, esi) != 0x00)
        goto loc_15e4d5;
    al = lodsb<DS_ESI>();
    esi++;
    esi++;
loc_15e50f:
    movsb<ES_EDI, DS_ESI>();
    if (memoryAGet(ds, esi) != 0x00)
        goto loc_15e50f;
    ds = pop();
    esi = pop32();
    memoryASet(ds, 0x17c250, bl);
    memoryASet(ds, 0x17c264, memoryAGet(ds, 0x17c264) & bh);
    memoryASet32(ds, 0x17c234, edi);
    ebx = esp;
    memoryASet32(ds, 0x17c220, ebx);
    ecx = 0x0017c75c;
    edi = 0x0017c6a8;
    ecx -= edi;
    if (memoryAGet(ds, 0x17c251) != 0x01)
        goto loc_15e553;
    if (ecx <= 0x00001000)
        goto loc_15e553;
    ecx = 0x00001000;
loc_15e553:
    dl = cl;
    ecx >>= 2;
    eax = 0;
    stop(); //for (; cx != 0; --cx) stosd<ES_EDI>(eax);
    cl = dl;
    cl &= 0x03;
    for (; cx != 0; --cx) stosb<ES_EDI>(al);
    eax = 0x0017c75c;
    eax += 0x0000000f;
    al &= 0xf0;
    memoryASet32(ds, 0x17c228, eax);
    memoryASet32(ds, 0x17c22c, esi);
    ebp = 0;
    eax = 0x000000ff;
    sub_15e830();
    sub_15e7e0();
    push32(eax);
    goto loc_15e5bc;
  // gap 48 bytes
loc_15e5bc:
    eax = 0;
    edx = 0x0000000f;
    sub_15e880();
    eax = pop32();
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
}
void sub_15e6e0()
{
    push32(edx);
    edx = eax;
    eax = cs;
    memoryASet16(ds, edx + 2, ax);
    eax = ds;
    memoryASet16(ds, edx + 6, ax);
    eax = es;
    memoryASet16(ds, edx, ax);
    eax = ss;
    memoryASet16(ds, edx + 4, ax);
    eax = fs;
    memoryASet16(ds, edx + 8, ax);
    eax = gs;
    memoryASet16(ds, edx + 10, ax);
    edx = pop32();
}
void sub_15e710()
{
    push32(esi);
    push32(edi);
    push32(ebp);
    edi = edx;
    ebp = ebx;
    eax &= 0x000000ff;
    ebx = ecx;
    edx = ebp;
    sub_15fa88(); // breaks stack!
    eax = memoryAGet32(ds, ebp);
    ebp = pop32();
    edi = pop32();
    esi = pop32();
}
void sub_15e7e0()
{
    goto loc_15e7e0;
loc_15e589:
    push32(eax);
    goto loc_15e5bc;
  // gap 48 bytes
loc_15e5bc:
    eax = 0;
    edx = 0x0000000f;
    sub_15e880();
    eax = pop32();
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
  // gap 531 bytes
loc_15e7e0:
    push32(edx);
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ds, 0x17c23c);
    eax += 0x00000003;
    al &= 0xfc;
    edx = memoryAGet32(ds, 0x17c23c);
    esp -= eax;
    eax = esp;
    eax += edx;
    memoryASet32(ds, 0x17c240, eax);
    sub_15fee0();
    edx = memoryAGet32(ds, 0x17c6d0);
    eax = memoryAGet32(ds, 0x17c6d4);
    sub_15e010();
    goto loc_15ff31;
  // gap 5912 bytes
loc_15ff31:
    ecx = eax;
    callIndirect(cs, memoryAGet32(ds, 0x17c390)); // CALL DWORD 0000:15ff33;
    edx = 0x000000ff;
    eax = 0x00000010;
    sub_15e880();
    callIndirect(cs, memoryAGet32(ds, 0x17c390)); // CALL DWORD 0000:15ff48;
    callIndirect(cs, memoryAGet32(ds, 0x17c394)); // CALL DWORD 0000:15ff4e;
    eax = ecx;
    goto loc_15e589;
}
void sub_15e820()
{
    push(es);
    if (memoryAGet32(ds, eax) != 0x00000000)
        goto loc_15e828;
    es = pop();
    return;
loc_15e828:
    push(ds);
    es = pop();
    callIndirect(cs, memoryAGet32(ds, eax)); // CALL DWORD 0000:15e82a;
    es = pop();
}
void sub_15e830()
{
    push32(ebx);
    push32(ecx);
    push32(edx);
    push32(esi);
    push(es);
    dh = al;
    esi = 0x0017c68a;
loc_15e83c:
    eax = 0x0017c660;
    ecx = esi;
    dl = dh;
    if (esi <= eax)
        goto loc_15e863;
loc_15e849:
    if (memoryAGet(ds, eax) == 0x02)
        goto loc_15e859;
    bh = memoryAGet(ds, eax + 1);
    if (dl < bh)
        goto loc_15e859;
    ecx = eax;
    dl = bh;
loc_15e859:
    eax += 0x00000006;
    if (eax < 0x0017c68a)
        goto loc_15e849;
loc_15e863:
    if (ecx == 0x0017c68a)
        goto loc_15e878;
    eax = ecx + 2;
    sub_15e820();
    memoryASet(ds, ecx, 0x02);
    goto loc_15e83c;
loc_15e878:
    es = pop();
    esi = pop32();
    edx = pop32();
    ecx = pop32();
    ebx = pop32();
}
void sub_15e880()
{
    push32(ebx);
    push32(ecx);
    push32(esi);
    push(es);
    bl = al;
    dh = dl;
    esi = 0x0017c690;
loc_15e88d:
    eax = 0x0017c68a;
    ecx = esi;
    dl = bl;
    if (esi <= eax)
        goto loc_15e8b4;
loc_15e89a:
    if (memoryAGet(ds, eax) == 0x02)
        goto loc_15e8aa;
    bh = memoryAGet(ds, eax + 1);
    if (dl > bh)
        goto loc_15e8aa;
    ecx = eax;
    dl = bh;
loc_15e8aa:
    eax += 0x00000006;
    if (eax < 0x0017c690)
        goto loc_15e89a;
loc_15e8b4:
    if (ecx == 0x0017c690)
        goto loc_15e8d0;
    if (dh >= memoryAGet(ds, ecx + 1))
        goto loc_15e8c6;
loc_15e8c1:
    memoryASet(ds, ecx, 0x02);
    goto loc_15e88d;
loc_15e8c6:
    eax = ecx + 2;
    sub_15e820();
    goto loc_15e8c1;
loc_15e8d0:
    es = pop();
    esi = pop32();
    ecx = pop32();
    ebx = pop32();
}
void sub_15fa60()
{
    if (memoryAGet(ds, 0x17c38c) != 0x00)
        goto loc_15fa6c;
    eax = 0;
    return;
loc_15fa6c:
    edx &= 0x0000ffff;
    push32(edx);
    push32(eax);
    stop("breakpoint");
    goto loc_15fa7d;
  // gap 6 bytes
loc_15fa7d:
    eax = 0x00000001;
    esp += 0x00000008;
    stop("stack_unbalanced");
}
void sub_15fa88()
{
//    push32(flagAsReg32());
    int x = esp;
    push32(ebp);
    push(es);
    push(ds);
    push32(edx);
    push32(ebx);
    edx = 0;
    int y = esp;
    sub_15fac8();
    assert(esp == y);
    push(ds);
    push32(edx);
    ebp = esp;
    ds = memoryAGet16(ds, ebp + 16);
    edx = memoryAGet32(ds, ebp + 12);
    memoryASet32(ds, edx, eax);
    memoryASet32(ds, edx + 4, ebx);
    memoryASet32(ds, edx + 8, ecx);
    memoryASet32(ds, edx + 12, pop32());
    memoryASet32(ds, edx + 16, esi);
    memoryASet32(ds, edx + 20, edi);
    eax = -flags.carry;
    eax &= 0x00000001;
    memoryASet32(ds, edx + 24, eax);
    eax = pop32();
    ebx = pop32();
    memoryASet16(ds, ebx, es);
    memoryASet16(ds, ebx + 6, ax);
    edx = pop32();
    ds = pop();
    es = pop();
    ebp = pop32();
    assert(esp == x);
//    push32(flagAsReg32());
//    stop(); //popfd();
//    stop("stack_unbalanced");
}
void sub_15fba3()
{
    interrupt(0x10);
}
void sub_15fac8() // +returnCarry
{
    eax = eax + eax*2;
    eax = eax + 1440627;
    push32(eax);
    ah = dl;
    sahf();
    es = memoryAGet16(ds, ebx);
    bp = memoryAGet16(ds, ebx + 6);
    eax = memoryAGet32(ds, edi);
    ebx = memoryAGet32(ds, edi + 4);
    ecx = memoryAGet32(ds, edi + 8);
    edx = memoryAGet32(ds, edi + 12);
    esi = memoryAGet32(ds, edi + 16);
    edi = memoryAGet32(ds, edi + 20);
    ds = bp;
    assert(pop32() == 0x15fba3); // TODO!
    sub_15fba3();
    //stop("stack_unbalanced");
}
void sub_15fee0()
{
    push32(ebx);
    push32(ecx);
    push32(esi);
    push32(edi);
    al = memoryAGet(ds, 0x17c251);
    if ((char)al < (char)0x02)
        goto loc_15fef6;
    if ((char)al > (char)0x09)
        goto loc_15fef6;
loc_15fef1:
    edi = pop32();
    esi = pop32();
    ecx = pop32();
    ebx = pop32();
    return;
loc_15fef6:
    sub_164000();
    if (eax != 0x00000001)
        goto loc_15fef1;
    esi = 0x0015e65f;
    ebx = 0x0015e654;
    esi -= 0x0015e654;
    di = si;
    esi >>= 16;
    cx = bx;
    ebx >>= 16;
    ax = 0x0600;
    interrupt(0x31);
    eax = -flags.carry;
    edi = pop32();
    esi = pop32();
    ecx = pop32();
    ebx = pop32();
}
void sub_164000()
{
    push32(ebx);
    push32(ecx);
    push32(edx);
    push32(esi);
    push32(edi);
    esp -= 0x00000008;
    edi = memoryAGet32(ds, 0x17c430);
    if (edi)
        goto loc_164064;
    if (memoryAGet(ds, 0x17c251) != 0x01)
        goto loc_164075;
loc_16401b:
    ah = 0;
    esi = esp;
    memoryASet(ds, esp, ah);
    memoryASet(ds, esp + 1, ah);
    al = 0;
    edx = ds;
    memoryASet16(ds, esp + 2, ax);
    memoryASet(ds, esp + 4, ah);
    push(ds);
    ds = edx;
    ax = 0x0400;
    interrupt(0x31);
    memoryASet(ds, esi, ah);
    memoryASet(ds, esi + 1, al);
    memoryASet16(ds, esi + 2, bx);
    memoryASet(ds, esi + 4, cl);
    memoryASet(ds, esi + 5, dh);
    memoryASet(ds, esi + 6, dl);
    ds = pop();
    eax = 0;
    esi = memoryAGet(ds, esp + 1);
    al = memoryAGet(ds, esp);
    eax += esi;
    if ((int32_t)(eax & eax) <= 0 /*test+jle check*/)
        goto loc_164080;
    edi = 0x00000001;
loc_164064:
    eax = edi;
    memoryASet32(ds, 0x17c430, edi);
    esp += 0x00000008;
    edi = pop32();
    esi = pop32();
    edx = pop32();
    ecx = pop32();
    ebx = pop32();
    return;
loc_164075:
    ax = 0x1686;
    interrupt(0x2f);
    if (!ax)
        goto loc_16401b;
loc_164080:
    edi = 0xffffffff;
    eax = edi;
    memoryASet32(ds, 0x17c430, edi);
    esp += 0x00000008;
    edi = pop32();
    esi = pop32();
    edx = pop32();
    ecx = pop32();
    ebx = pop32();
}

int GetProcAt(int seg, int ofs)
{
    int map[] = {
        0x15e010, 0x0, 0x15e010, 0x0, 0x15e079, 0x15e010, 0x0, 0x15e07e, 0x0, 0x15e26b, 
        0x15e27b, 0x0, 0x15e27b, 0x0, 0x15e29d, 0x15e27b, 0x0, 0x15e2a0, 0x0, 0x15e2b0, 
        0x15e27b, 0x0, 0x15e589, 0x0, 0x15e5cd, 0x15e27b, 0x0, 0x15e6c0, 0x0, 0x15e6df, 
        0x15e2b0, 0x0, 0x15e2b0, 0x0, 0x15e2cd, 0x15e2d0, 0x0, 0x15e2d0, 0x0, 0x15e2da, 
        0x15e2dc, 0x0, 0x15e2dc, 0x0, 0x15e2de, 0x15e2dc, 0x0, 0x15e2e3, 0x0, 0x15e2e6, 
        0x15e2f0, 0x0, 0x15e2f0, 0x0, 0x15e31d, 0x15e358, 0x0, 0x15e358, 0x0, 0x15e36e, 
        0x15e370, 0x0, 0x15e370, 0x0, 0x15e38f, 0x15e390, 0x0, 0x15e390, 0x0, 0x15e392, 
        0x15e3a4, 0x0, 0x15e3a4, 0x0, 0x15e58c, 0x15e3a4, 0x0, 0x15e5bc, 0x0, 0x15e5cd, 
        0x15e6e0, 0x0, 0x15e6e0, 0x0, 0x15e708, 0x15e710, 0x0, 0x15e710, 0x0, 0x15e72c, 
        0x15e7e0, 0x0, 0x15e589, 0x0, 0x15e58c, 0x15e7e0, 0x0, 0x15e5bc, 0x0, 0x15e5cd, 
        0x15e7e0, 0x0, 0x15e7e0, 0x0, 0x15e819, 0x15e7e0, 0x0, 0x15ff31, 0x0, 0x15ff5b, 
        0x15e820, 0x0, 0x15e820, 0x0, 0x15e82e, 0x15e830, 0x0, 0x15e830, 0x0, 0x15e87e, 
        0x15e880, 0x0, 0x15e880, 0x0, 0x15e8d5, 0x15fa60, 0x0, 0x15fa60, 0x0, 0x15fa77, 
        0x15fa60, 0x0, 0x15fa7d, 0x0, 0x15fa85, 0x15fa88, 0x0, 0x15fa88, 0x0, 0x15fac7, 
        0x15fac8, 0x0, 0x15fac8, 0x0, 0x15faf0, 0x15fee0, 0x0, 0x15fee0, 0x0, 0x15ff29, 
        0x164000, 0x0, 0x164000, 0x0, 0x164096,     };
    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs <= map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
#endif
