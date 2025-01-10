#include "cicoemu.h"
#include <stdio.h>
using namespace CicoContext;

void sub_64f6();

void start()
{
    headerSize = 0x0c70;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x0e00;
    sp = 0x3e80;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/cervi/dos", "CERVII.EXE", 47200);
    sub_64f6();
}
// 01ed:4676 Terminator reached
void sub_1f34();
void sub_1f62();
void sub_1f98();
void sub_1fb3();
void sub_20ae();
void sub_2174();
void sub_21c6();
void sub_22c0();
void sub_25f9();
void sub_277a();
void sub_2966();
void sub_2a0b();
void sub_2d25();
void sub_39fc();
void sub_3be3();
void sub_4992();
void sub_4a23();
void sub_4a87();
void sub_4b2a();
void sub_52fb();
void sub_5423();
void sub_5465();
void sub_5760();
void sub_64f6();
void sub_65a5();
void sub_65f3();
void sub_6607();
void sub_6620();
void sub_6651();
void sub_66bb();
void sub_67b2();
void sub_68fb();
void sub_696f();
void sub_6a63();
void sub_6bd6();
void sub_6c96();
void sub_6f70();
void sub_6f9d();
void sub_7068();
void sub_70fd();
void sub_711a();
void sub_7145();
void sub_717f();
void sub_71c6();
void sub_71f1();
void sub_724c();
void sub_727f();
void sub_72a1();
void sub_72c2();
void sub_72f7();
void sub_739f();
void sub_73be();
void sub_7479();
void sub_74bb();
void sub_7708();
void sub_7761();
void sub_7764();
void sub_77af();
void sub_77ef();
void sub_783d();
void sub_78a8();
void sub_78c2();
void sub_78ec();
void sub_7948();
void sub_79bc();
void sub_79de();
void sub_7a00();
void sub_7a28();
void sub_7a3c();
void sub_7a50();
void sub_7a98();
void sub_7aea();
void sub_7b45();
void sub_7b8c();
void sub_7ba4();
void sub_7bb4();
void sub_7bc4();
void sub_7bed();
void sub_7bfe();
void sub_7c47();
void sub_7c59();
void sub_7cb5();
void sub_7cdc();
void sub_7d00();
void sub_7d96();
void sub_7dae();
void sub_7dc5();
void sub_7df9();
void sub_7e3d();
void sub_7e73();
void sub_7eda();
void sub_7ef8();
void sub_7f38();
void sub_7f47();
void sub_7f68();
void sub_7f6b();
void sub_7f9d();
void sub_99f6();
void sub_9a32();
void sub_9a4a();
void sub_9a60();
void sub_9a8e();
void sub_9af7();
void sub_9b45();
void sub_9ba3();
void sub_9c20();
void sub_9c73();
void sub_9cb7();
void sub_9cfc();
void sub_9d1f();
void sub_9d27();
void sub_9d54();
void sub_9d5b();
void sub_9d6d();
void sub_9d8f();
void sub_9dba();
void sub_9e9f();
void sub_9ed0();
void sub_9ed5();
void sub_9edc();
void sub_9f35();
void sub_9f56();
void sub_9f5d();
void sub_9f64();
void sub_a001();
void sub_a069();
void sub_a080();
void sub_a169();
void sub_a225();
void sub_a233();
void sub_a23f();
void sub_a24d();
void sub_a254();
void sub_a25f();
void sub_a267();
void sub_a2bf();
void sub_a2d4();
void sub_a388();
void sub_a453();
void sub_a4b2();
void sub_a511();
void sub_a522();
void sub_a529();
void sub_a537();
void sub_a55f();
void sub_a575();
void sub_a5e5();
void sub_a5ea();
void sub_a63f();
void sub_a67b();
void sub_a68c();
void sub_a70e();
void sub_a836();
void sub_a85a();
void sub_a8c8();
void sub_a8ec();
void sub_a8f9();
void sub_a935();
void sub_a997();
void sub_a9d5();
void sub_a9f1();
void sub_aa0c();
void sub_aaa1();
void sub_aabb();
void sub_aaed();
void sub_ab2e();
void sub_aba6();
void sub_abd1();
void sub_abe3();
void sub_ac52();
void sub_ad56();
void sub_ae02();
void sub_ae06();
void sub_aec9();
void sub_afce();
void sub_b045();
void sub_b05c();
void sub_b06f();
void sub_b0ae();
void sub_b10a();
void sub_b110();
void sub_b11c();
void sub_b122();
void sub_b12c();
void sub_b130();
void sub_b13c();
void sub_b156();
void sub_b160();
void sub_b16a();
void sub_b174();
void sub_b17e();
void sub_b1cf();
void sub_b242();
void sub_b255();
void sub_b561();
void sub_b57a();
void sub_b5c9();
void sub_b618();
void sub_b650();
void sub_b65d();
void sub_b76f();
void sub_b7eb();
void sub_b819();
void sub_b822();
void sub_b89a();
void sub_b8bf();
void sub_b8ce();
void sub_b8d5();
void sub_b904();
void sub_b9b3();
void sub_b9e3();
void sub_ba28();
void sub_ba4b();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x6550055: sub_65a5(); return;
        case 0x65500a3: sub_65f3(); return;
        case 0x65500b7: sub_6607(); return;
        case 0x65500d0: sub_6620(); return;
        case 0x9a6035a: sub_9dba(); return;
        case 0x9a6043f: sub_9e9f(); return;
        case 0x9a60470: sub_9ed0(); return;
        case 0xa08060c: sub_a68c(); return;
        default:
            break;
    }
    if (seg == 0x7fe && ofs == 0)
    {
        if (si == 0)
        {
            int temp = ax;
            ax = 0x00ff;
            interrupt(0x10);
            ax = temp;
            bx = 0x2e5;
            es = 0x11f2; // 11f2:2e5=00 00
        } else {
            if (si != 0x2e && si != 0x30 && si != 0x1e && si != 0x0c)
                printf("EGAVGA %04x: %x %x %x %x\n", si, ax, bx, cx, dx);
            interrupt(0x10);
        }
        cs = pop();
        return;
    }
    assert(0);
}
// 01ed:4676 Terminator reached
// 01ed:4676 Terminator reached
// INJECT: Error: cannot inject flag in sub_7f38() because of being label!
// INJECT: Error: cannot inject zero flag in sub_7f68() because no traceback!
// INJECT: Error: cannot inject flag in sub_a388() because of being label!
// INJECT: Error: cannot inject carry flag in sub_a388()!
// INJECT: Error: cannot inject flag in sub_a453() because of being label!
// INJECT: Error: cannot inject zero flag in sub_a67b()!
// INJECT: Error: cannot inject zero flag in sub_a836()!
// INJECT: Error: cannot inject flag in sub_ae02() because of being label!
// INJECT: Error: cannot inject carry flag in sub_ae02()!
// INJECT: Error: cannot inject carry flag in sub_ae02()!
// INJECT: Error: cannot inject flag in sub_ae06() because of being label!
// INJECT: Error: cannot inject carry flag in sub_ae06()!
// INJECT: Error: cannot inject carry flag in sub_ae06()!
// INJECT: Error: cannot inject carry flag in sub_aec9()!
// INJECT: Error: cannot inject carry flag in sub_aec9()!
// INJECT: Error: cannot inject carry flag in sub_afce()!
// INJECT: Error: cannot inject carry flag in sub_afce()!
// INJECT: Error: cannot inject carry flag in sub_b045()!
// INJECT: Error: cannot inject carry flag in sub_b045()!
// INJECT: Error: cannot inject flag in sub_b045() because of being label!
// INJECT: Error: cannot inject flag in sub_b05c() because of being label!
// INJECT: Error: cannot inject carry flag in sub_b0ae()!
// INJECT: Error: cannot inject zero flag in sub_b12c() because no traceback!
// INJECT: Error: cannot inject flag in sub_b8bf() because of being label!
// INJECT: Error: cannot inject carry flag in sub_b9e3()!
void sub_1f34() // 01ed:0064
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0004;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0004;
    memoryASet16(ss, bp - 2, 0x0009);
    memoryASet16(ss, bp - 4, 0x0002);
    di = bp - 0x2;
    push(ss);
    push(di);
    di = bp - 0x4;
    push(ss);
    push(di);
    di = 0x0063;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0655;
    sub_6c96();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1f62() // 01ed:0092
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    di = 0x20d0;
    push(ds);
    push(di);
    push(0x0080);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_ba4b();
    assert(cs == 0x01ed);
    push(0x0009);
    di = 0x20cc;
    push(ds);
    push(di);
    push(cs);
    cs = 0x099c;
    sub_9a32();
    assert(cs == 0x01ed);
    push(0x0009);
    di = 0x0008;
    ax = 0x01ed;
    push(ax);
    push(di);
    push(cs);
    cs = 0x099c;
    sub_9a4a();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1f98() // 01ed:00c8
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    push(0x0009);
    push(memoryAGet16(ds, 0x20ce));
    push(memoryAGet16(ds, 0x20cc));
    push(cs);
    cs = 0x099c;
    sub_9a4a();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fb3() // 01ed:00e3
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x001c;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x001c;
    memoryASet16(ss, bp - 28, 0x1f81);
    memoryASet16(ss, bp - 26, 0x5214);
    memoryASet16(ss, bp - 24, 0x1e06);
    di = bp - 0xa;
    push(ss);
    push(di);
    di = bp - 0xc;
    push(ss);
    push(di);
    di = bp - 0xe;
    push(ss);
    push(di);
    di = bp - 0x10;
    push(ss);
    push(di);
    push(cs);
    cs = 0x099c;
    sub_99f6();
    assert(cs == 0x01ed);
    imul(ax, memoryAGet16(ss, bp - 14), 0x0064);
    ax += memoryAGet16(ss, bp - 16);
    dx = 0;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_200c;
loc_2004: // 01ed:0134
    flags.carry = (memoryAGet16(ss, bp - 4) + 0x0001) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0001);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + flags.carry);
loc_200c: // 01ed:013c
    ax = memoryAGet16(ss, bp - 28);
    bx = memoryAGet16(ss, bp - 26);
    dx = memoryAGet16(ss, bp - 24);
    cx = memoryAGet16(ss, bp - 28);
    si = memoryAGet16(ss, bp - 26);
    di = memoryAGet16(ss, bp - 24);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 22, ax);
    memoryASet16(ss, bp - 20, bx);
    memoryASet16(ss, bp - 18, dx);
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_2004;
    if (memoryAGet16(ss, bp - 4) != 0x4e20)
        goto loc_2004;
    di = bp - 0xa;
    push(ss);
    push(di);
    di = bp - 0xc;
    push(ss);
    push(di);
    di = bp - 0xe;
    push(ss);
    push(di);
    di = bp - 0x10;
    push(ss);
    push(di);
    push(cs);
    cs = 0x099c;
    sub_99f6();
    assert(cs == 0x01ed);
    imul(ax, memoryAGet16(ss, bp - 14), 0x0064);
    ax += memoryAGet16(ss, bp - 16);
    dx = 0;
    flags.carry = ax < memoryAGet16(ss, bp - 8);
    ax -= memoryAGet16(ss, bp - 8);
    dx -= memoryAGet16(ss, bp - 6) + flags.carry;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0000)
        goto loc_2075;
    if ((short)memoryAGet16(ss, bp - 6) > (short)0x0000)
        goto loc_2087;
    if (memoryAGet16(ss, bp - 8) >= 0x0000)
        goto loc_2087;
loc_2075: // 01ed:01a5
    ax = memoryAGet16(ss, bp - 8);
    dx = memoryAGet16(ss, bp - 6);
    flags.carry = (ax + 0x1770) >= 0x10000;
    ax += 0x1770;
    dx += flags.carry;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
loc_2087: // 01ed:01b7
    ax = 0x1770;
    dx = 0;
    cx = memoryAGet16(ss, bp - 8);
    bx = memoryAGet16(ss, bp - 6);
    push(cs);
    cs = 0x0a08;
    sub_aa0c();
    assert(cs == 0x01ed);
    flags.carry = ax < 0x0015;
    ax -= 0x0015;
    dx -= flags.carry;
    memoryASet16(ds, 0x20c8, ax);
    memoryASet16(ds, 0x20ca, dx);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_20ae() // 01ed:01de
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0002;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0002;
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_20c6;
loc_20c3: // 01ed:01f3
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_20c6: // 01ed:01f6
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(cs);
    cs = 0x0a08;
    sub_b130();
    assert(cs == 0x01ed);
    cx = 0xc282;
    si = 0xdb19;
    di = 0x490f;
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = 0x0087;
    si = 0;
    di = 0x3400;
    push(cs);
    cs = 0x0a08;
    sub_b122();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_b255();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x01d6;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 6220, ax);
    memoryASet16(ds, di + 6222, bx);
    memoryASet16(ds, di + 6224, dx);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(cs);
    cs = 0x0a08;
    sub_b130();
    assert(cs == 0x01ed);
    cx = 0xc282;
    si = 0xdb19;
    di = 0x490f;
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = 0x0087;
    si = 0;
    di = 0x3400;
    push(cs);
    cs = 0x0a08;
    sub_b122();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_b242();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x01d6;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 7306, ax);
    memoryASet16(ds, di + 7308, bx);
    memoryASet16(ds, di + 7310, dx);
    if (memoryAGet16(ss, bp - 2) == 0x00b3)
        goto loc_2172;
    goto loc_20c3;
loc_2172: // 01ed:02a2
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2174() // 01ed:02a4
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0002;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0002;
    memoryASet16(ds, 0x183c, 0x0062);
    memoryASet16(ds, 0x1830, 0x006e);
    memoryASet16(ds, 0x183e, 0x007b);
    memoryASet16(ds, 0x1834, 0x0083);
    memoryASet16(ds, 0x1836, 0x0093);
    memoryASet16(ds, 0x1838, 0x00a5);
    memoryASet16(ds, 0x183a, 0x00af);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_21c6() // 01ed:02f6
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    if (memoryAGet(ds, 0x1672) != 0x00)
        goto loc_21da;
    goto loc_229e;
loc_21da: // 01ed:030a
    al = memoryAGet(ds, 0x006c);
    ah = 0;
    if ((short)ax >= (short)memoryAGet16(ds, 0x1840))
        goto loc_21eb;
    memoryASet16(ds, 0x1840, 0x0001);
loc_21eb: // 01ed:031b
    if ((short)memoryAGet16(ds, 0x1842) >= (short)0x0000)
        goto loc_220a;
    ax = memoryAGet16(ds, 0x1842);
    ax <<= 1;
    ax += memoryAGet16(ds, 0x1834);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x02de;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_220a: // 01ed:033a
    ax = memoryAGet16(ds, 0x1840);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x02e6;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 108);
    if (al != 0x2d)
        goto loc_222e;
    if (memoryAGet16(ds, 0x1842) != 0x0000)
        goto loc_222c;
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
loc_222c: // 01ed:035c
    goto loc_228a;
loc_222e: // 01ed:035e
    if (al != 0x20)
        goto loc_2240;
    if (memoryAGet16(ds, 0x1842) != 0x0000)
        goto loc_223e;
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
loc_223e: // 01ed:036e
    goto loc_228a;
loc_2240: // 01ed:0370
    if (memoryAGet16(ds, 0x1842) != 0x0000)
        goto loc_224e;
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    goto loc_228a;
loc_224e: // 01ed:037e
    if (memoryAGet16(ds, 0x1842) != 0x0001)
        goto loc_228a;
    ax = memoryAGet16(ds, 0x1840);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x02e6;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 108);
    ah = 0;
    dx = 0;
    di = 0x02ee;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 5998);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x02de;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_228a: // 01ed:03ba
    memoryASet16(ds, 0x1842, memoryAGet16(ds, 0x1842) + 1);
    if (memoryAGet16(ds, 0x1842) != 0x000e)
        goto loc_229e;
    ax = 0;
    memoryASet16(ds, 0x1842, ax);
    memoryASet16(ds, 0x1840, memoryAGet16(ds, 0x1840) + 1);
loc_229e: // 01ed:03ce
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_22c0() // 01ed:03f0
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0008;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0008;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 6167, 0x00);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, 0x00);
    push(0x0064);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    push(cs);
    cs = 0x0a08;
    sub_b130();
    assert(cs == 0x01ed);
    cx = 0x0088;
    si = 0;
    di = 0x4800;
    push(cs);
    cs = 0x0a08;
    sub_b122();
    assert(cs == 0x01ed);
    cx = 0x0081;
    si = 0;
    di = 0;
    push(cs);
    cs = 0x0a08;
    sub_b10a();
    assert(cs == 0x01ed);
    cx = 0x0080;
    si = 0;
    di = 0;
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5742, ax);
    memoryASet16(ds, di + 5744, bx);
    memoryASet16(ds, di + 5746, dx);
loc_234f: // 01ed:047f
    push(0x00b4);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x03d8;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6142, cx);
    push(0x01f4);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax += 0x05dc;
    dx = 0;
    push(cs);
    cs = 0x0a08;
    sub_b130();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, bx);
    memoryASet16(ss, bp - 4, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6142);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03e0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 7306);
    bx = memoryAGet16(ds, di + 7308);
    dx = memoryAGet16(ds, di + 7310);
    cx = 0xab88;
    si = 0xaaaa;
    di = 0x3aaa;
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = memoryAGet16(ss, bp - 8);
    si = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ss, bp - 4);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = 0x008b;
    si = 0;
    di = 0x7a00;
    push(cs);
    cs = 0x0a08;
    sub_b122();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = 0x0089;
    bx = 0;
    dx = 0x0c00;
    cx = pop();
    si = pop();
    di = pop();
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5772, ax);
    memoryASet16(ds, di + 5774, bx);
    memoryASet16(ds, di + 5776, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6142);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03e0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 6220);
    bx = memoryAGet16(ds, di + 6222);
    dx = memoryAGet16(ds, di + 6224);
    cx = 0x0088;
    si = 0;
    di = 0x2000;
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = memoryAGet16(ss, bp - 8);
    si = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ss, bp - 4);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    cx = 0x008b;
    si = 0;
    di = 0x7a00;
    push(cs);
    cs = 0x0a08;
    sub_b122();
    assert(cs == 0x01ed);
    cx = 0x0088;
    si = 0;
    di = 0x7000;
    push(cs);
    cs = 0x0a08;
    sub_b10a();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5880, ax);
    memoryASet16(ds, di + 5882, bx);
    memoryASet16(ds, di + 5884, dx);
    ax = memoryAGet16(ss, bp + 4);
    ax--;
    if ((short)ax >= (short)0x0001)
        goto loc_24b7;
    goto loc_2571;
loc_24b7: // 01ed:05e7
    memoryASet16(ss, bp - 2, ax);
    goto loc_24bf;
loc_24bc: // 01ed:05ec
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) - 1);
loc_24bf: // 01ed:05ef
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5772);
    bx = memoryAGet16(ds, di + 5774);
    dx = memoryAGet16(ds, di + 5776);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5772);
    bx = memoryAGet16(ds, di + 5774);
    dx = memoryAGet16(ds, di + 5776);
    cx = pop();
    si = pop();
    di = pop();
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    dh &= 0x7f;
    cx = 0x0085;
    si = 0;
    di = 0x7000;
    push(cs);
    cs = 0x0a08;
    sub_b12c();
    assert(cs == 0x01ed);
    if (!flags.carry)
        goto loc_2568;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5880);
    bx = memoryAGet16(ds, di + 5882);
    dx = memoryAGet16(ds, di + 5884);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5880);
    bx = memoryAGet16(ds, di + 5882);
    dx = memoryAGet16(ds, di + 5884);
    cx = pop();
    si = pop();
    di = pop();
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    dh &= 0x7f;
    cx = 0x0085;
    si = 0;
    di = 0x7000;
    push(cs);
    cs = 0x0a08;
    sub_b12c();
    assert(cs == 0x01ed);
    if (!flags.carry)
        goto loc_2568;
    goto loc_234f;
loc_2568: // 01ed:0698
    if (memoryAGet16(ss, bp - 2) == 0x0001)
        goto loc_2571;
    goto loc_24bc;
loc_2571: // 01ed:06a1
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_257b;
loc_2578: // 01ed:06a8
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_257b: // 01ed:06ab
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03e8;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = 0;
    memoryASet16(ds, di + 5992, ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03e8;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x03d0;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = 0;
    memoryASet16(ds, di + 6028, ax);
    if (memoryAGet16(ss, bp - 2) != 0x0003)
        goto loc_2578;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_25f9() // 01ed:0729
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0006;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0006;
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_2611;
loc_260e: // 01ed:073e
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2611: // 01ed:0741
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0719;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cx = ax;
    ax = memoryAGet16(ss, bp + 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0711;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0007);
    di += cx;
    if (memoryAGet(ds, di + 1) != 0x01)
        goto loc_264b;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0721;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    goto loc_2652;
loc_264b: // 01ed:077b
    push(0x0008);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
loc_2652: // 01ed:0782
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0719;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    si = di;
    di <<= 1;
    di += si;
    al = memoryAGet(ds, di + 84);
    ah = 0;
    imul(ax, ax, 0x000a);
    ax += memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0719;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    si = di;
    di <<= 1;
    di += si;
    al = memoryAGet(ds, di + 85);
    ah = 0;
    imul(ax, ax, 0x000a);
    ax += memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0719;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    si = di;
    di <<= 1;
    di += si;
    if (memoryAGet(ds, di + 83) != 0x01)
        goto loc_2709;
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x000a;
    ax--;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x000a;
    ax--;
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x000a;
    ax--;
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
    goto loc_275d;
loc_2709: // 01ed:0839
    push(memoryAGet16(ss, bp - 2));
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 2);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax--;
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax--;
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a50();
    assert(cs == 0x01ed);
loc_275d: // 01ed:088d
    if (memoryAGet16(ss, bp - 6) == 0x0007)
        goto loc_2766;
    goto loc_260e;
loc_2766: // 01ed:0896
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_277a() // 01ed:08aa
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0002;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0002;
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_2792;
loc_278f: // 01ed:08bf
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_2792: // 01ed:08c2
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_27aa;
    goto loc_2949;
loc_27aa: // 01ed:08da
    push(0x0000);
    push(0x0274);
    imul(ax, memoryAGet16(ss, bp - 2), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x08a2;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    if (memoryAGet(ss, bp + 4) != 0x00)
        goto loc_27ff;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) == 0x00)
        goto loc_27ff;
    goto loc_2900;
loc_27ff: // 01ed:092f
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0064;
    idiv(cx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x000a;
    idiv(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    push(ax);
    push(0x0236);
    imul(ax, memoryAGet16(ss, bp - 2), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x08a2;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x000a;
    idiv(cx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x000a;
    idiv(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    push(ax);
    push(0x0248);
    imul(ax, memoryAGet16(ss, bp - 2), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x08a2;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x000a;
    idiv(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    push(ax);
    push(0x025a);
    imul(ax, memoryAGet16(ss, bp - 2), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x08a2;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    goto loc_2949;
loc_2900: // 01ed:0a30
    push(0x000b);
    push(0x0248);
    imul(ax, memoryAGet16(ss, bp - 2), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    dx = 0;
    di = 0x089a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x08a2;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
loc_2949: // 01ed:0a79
    if (memoryAGet16(ss, bp - 2) == 0x0006)
        goto loc_2952;
    goto loc_278f;
loc_2952: // 01ed:0a82
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_2966() // 01ed:0a96
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    push(0x0001);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0a86;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_71c6();
    assert(cs == 0x01ed);
    push(0x0004);
    push(0x0004);
    push(0x022b);
    push(0x01db);
    push(cs);
    cs = 0x0655;
    sub_7a98();
    assert(cs == 0x01ed);
    push(0x0235);
    push(0x0000);
    push(0x027b);
    push(0x0030);
    push(cs);
    cs = 0x0655;
    sub_7a98();
    assert(cs == 0x01ed);
    push(0x000f);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    push(0x0000);
    push(0x0000);
    push(0x022f);
    push(0x01df);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    push(0x0001);
    push(0x0001);
    push(0x022e);
    push(0x01de);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    push(0x0003);
    push(0x0003);
    push(0x022c);
    push(0x01dc);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    al = memoryAGet(ss, bp + 4);
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0a8e;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_277a();
    push(0x03e8);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_2a0b() // 01ed:0b3b
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0014;
    memoryASet16(ss, bp - 6, 0xffff);
    memoryASet16(ss, bp - 2, 0x0228);
    memoryASet16(ss, bp - 4, 0x0004);
loc_2a28: // 01ed:0b58
    memoryASet16(ss, bp - 8, 0x03e8);
    memoryASet16(ss, bp - 10, 0x0001);
    goto loc_2a37;
loc_2a34: // 01ed:0b64
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_2a37: // 01ed:0b67
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_2ab8;
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 6))
        goto loc_2ab8;
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_2ab8;
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_2a9c;
    memoryASet16(ss, bp - 18, memoryAGet16(ss, bp - 18) + 1);
    goto loc_2ab8;
loc_2a9c: // 01ed:0bcc
    memoryASet16(ss, bp - 18, 0x0001);
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    memoryASet16(ss, bp - 8, ax);
loc_2ab8: // 01ed:0be8
    if (memoryAGet16(ss, bp - 10) == 0x0006)
        goto loc_2ac1;
    goto loc_2a34;
loc_2ac1: // 01ed:0bf1
    ax = 0;
    memoryASet16(ss, bp - 14, ax);
    memoryASet16(ss, bp - 10, 0x0001);
    goto loc_2ad0;
loc_2acd: // 01ed:0bfd
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_2ad0: // 01ed:0c00
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_2ae8;
    goto loc_2b78;
loc_2ae8: // 01ed:0c18
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_2b78;
    push(0x0001);
    ax = memoryAGet16(ss, bp - 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0b2b;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_71c6();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 14);
    mul(memoryAGet16(ss, bp - 2));
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(memoryAGet16(ss, bp - 18));
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0000;
    ax += dx;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 14);
    ax++;
    mul(memoryAGet16(ss, bp - 2));
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(memoryAGet16(ss, bp - 18));
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0000;
    ax += dx;
    ax--;
    push(ax);
    ax = 0x01e0;
    ax -= memoryAGet16(ss, bp - 4);
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a98();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) + 1);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 20, ax);
loc_2b78: // 01ed:0ca8
    if (memoryAGet16(ss, bp - 10) == 0x0006)
        goto loc_2b81;
    goto loc_2acd;
loc_2b81: // 01ed:0cb1
    ax = memoryAGet16(ss, bp - 2);
    ax -= 0x003c;
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x001e;
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 8);
    if (ax == memoryAGet16(ds, 0x182c))
        goto loc_2ba5;
    goto loc_2a28;
loc_2ba5: // 01ed:0cd5
    ax = memoryAGet16(ds, 0x182e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3525);
    ah = 0;
    if (ax == memoryAGet16(ss, bp - 18))
        goto loc_2bc1;
    goto loc_2cf3;
loc_2bc1: // 01ed:0cf1
    push(0x0001);
    ax = memoryAGet16(ds, 0x182e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b23;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0b2b;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3512);
    ah = 0;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_71c6();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1834);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b33;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    push(0x003c);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 16, 0x0004);
    goto loc_2c12;
loc_2c0f: // 01ed:0d3f
    memoryASet16(ss, bp - 16, memoryAGet16(ss, bp - 16) - 1);
loc_2c12: // 01ed:0d42
    ax = memoryAGet16(ss, bp - 16);
    if (ax != 0x0003)
        goto loc_2c2e;
    ax = memoryAGet16(ds, 0x1838);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b33;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    goto loc_2c62;
loc_2c2e: // 01ed:0d5e
    if (ax != 0x0002)
        goto loc_2c49;
    ax = memoryAGet16(ds, 0x183c);
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b33;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    goto loc_2c62;
loc_2c49: // 01ed:0d79
    if (ax != 0x0001)
        goto loc_2c62;
    ax = memoryAGet16(ds, 0x1834);
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0b33;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_2c62: // 01ed:0d92
    ax = 0;
    memoryASet16(ss, bp - 10, ax);
    goto loc_2c6c;
loc_2c69: // 01ed:0d99
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_2c6c: // 01ed:0d9c
    ax = 0;
    memoryASet16(ss, bp - 12, ax);
    goto loc_2c76;
loc_2c73: // 01ed:0da3
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 1);
loc_2c76: // 01ed:0da6
    ax = memoryAGet16(ss, bp - 10);
    ax += 0x023c;
    push(ax);
    imul(ax, memoryAGet16(ds, 0x182e), 0x0048);
    ax += 0x0000;
    ax -= 0x0014;
    ax += memoryAGet16(ss, bp - 12);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    if (stop(/*condition!*/))
        goto loc_2cca;
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 2;
    ax += 0x009a;
    push(ax);
    ax = memoryAGet16(ss, bp - 12);
    ax <<= 2;
    ax += 0x00d0;
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    ax++;
    ax <<= 2;
    ax += 0x009a;
    ax -= memoryAGet16(ss, bp - 16);
    push(ax);
    ax = memoryAGet16(ss, bp - 12);
    ax++;
    ax <<= 2;
    ax += 0x00d0;
    ax -= memoryAGet16(ss, bp - 16);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a98();
    assert(cs == 0x01ed);
loc_2cca: // 01ed:0dfa
    if (memoryAGet16(ss, bp - 12) != 0x000f)
        goto loc_2c73;
    if (memoryAGet16(ss, bp - 10) != 0x003f)
        goto loc_2c69;
    push(0x0028);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 16) == 0x0001)
        goto loc_2ce6;
    goto loc_2c0f;
loc_2ce6: // 01ed:0e16
    push(0x00a0);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
loc_2cf3: // 01ed:0e23
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2d25() // 01ed:0e55
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0014;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 371);
    ah = 0;
    dx = 0;
    di = 0x0e2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 8400) != 0x01) // key
        goto loc_2d9e;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 6142) >= (short)0x00b3)
        goto loc_2d88;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6142, memoryAGet16(ds, di + 6142) + 1); // gabo
    goto loc_2d9e;
loc_2d88: // 01ed:0eb8
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 6142, ax);
loc_2d9e: // 01ed:0ece
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 377);
    ah = 0;
    dx = 0;
    di = 0x0e2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 8400) != 0x01)
        goto loc_2e08;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 6142) <= (short)0x0000)
        goto loc_2df2;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6142, memoryAGet16(ds, di + 6142) - 1);
    goto loc_2e08;
loc_2df2: // 01ed:0f22
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6142, 0x00b3);
loc_2e08: // 01ed:0f38
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6142);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e35;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 6220);
    bx = memoryAGet16(ds, di + 6222);
    dx = memoryAGet16(ds, di + 6224);
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, bx);
    memoryASet16(ss, bp - 2, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6142);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e35;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 7306);
    bx = memoryAGet16(ds, di + 7308);
    dx = memoryAGet16(ds, di + 7310);
    memoryASet16(ss, bp - 12, ax);
    memoryASet16(ss, bp - 10, bx);
    memoryASet16(ss, bp - 8, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 5742);
    bx = memoryAGet16(ds, di + 5744);
    dx = memoryAGet16(ds, di + 5746);
    cx = memoryAGet16(ss, bp - 12);
    si = memoryAGet16(ss, bp - 10);
    di = memoryAGet16(ss, bp - 8);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5772);
    bx = memoryAGet16(ds, di + 5774);
    dx = memoryAGet16(ds, di + 5776);
    cx = pop();
    si = pop();
    di = pop();
    push(cs);
    cs = 0x0a08;
    sub_b10a();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5772, ax);
    memoryASet16(ds, di + 5774, bx);
    memoryASet16(ds, di + 5776, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    ax = memoryAGet16(ds, di + 5742);
    bx = memoryAGet16(ds, di + 5744);
    dx = memoryAGet16(ds, di + 5746);
    cx = memoryAGet16(ss, bp - 6);
    si = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp - 2);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5880);
    bx = memoryAGet16(ds, di + 5882);
    dx = memoryAGet16(ds, di + 5884);
    cx = pop();
    si = pop();
    di = pop();
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5880, ax);
    memoryASet16(ds, di + 5882, bx);
    memoryASet16(ds, di + 5884, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5772);
    bx = memoryAGet16(ds, di + 5774);
    dx = memoryAGet16(ds, di + 5776);
    cx = memoryAGet16(ss, bp - 6);
    si = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp - 2);
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5766, ax);
    memoryASet16(ds, di + 5768, bx);
    memoryASet16(ds, di + 5770, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5880);
    bx = memoryAGet16(ds, di + 5882);
    dx = memoryAGet16(ds, di + 5884);
    cx = memoryAGet16(ss, bp - 12);
    si = memoryAGet16(ss, bp - 10);
    di = memoryAGet16(ss, bp - 8);
    push(cs);
    cs = 0x0a08;
    sub_b110();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5874, ax);
    memoryASet16(ds, di + 5876, bx);
    memoryASet16(ds, di + 5878, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5772);
    bx = memoryAGet16(ds, di + 5774);
    dx = memoryAGet16(ds, di + 5776);
    cx = memoryAGet16(ss, bp - 6);
    si = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp - 2);
    push(cs);
    cs = 0x0a08;
    sub_b10a();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5778, ax);
    memoryASet16(ds, di + 5780, bx);
    memoryASet16(ds, di + 5782, dx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = memoryAGet16(ds, di + 5880);
    bx = memoryAGet16(ds, di + 5882);
    dx = memoryAGet16(ds, di + 5884);
    cx = memoryAGet16(ss, bp - 12);
    si = memoryAGet16(ss, bp - 10);
    di = memoryAGet16(ss, bp - 8);
    push(cs);
    cs = 0x0a08;
    sub_b10a();
    assert(cs == 0x01ed);
    push(dx);
    push(bx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    ax = pop();
    bx = pop();
    dx = pop();
    memoryASet16(ds, di + 5886, ax);
    memoryASet16(ds, di + 5888, bx);
    memoryASet16(ds, di + 5890, dx);
    memoryASet(ss, bp - 14, 0x00);
    memoryASet(ss, bp - 13, 0x01);
    goto loc_30a3;
loc_30a0: // 01ed:11d0
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
loc_30a3: // 01ed:11d3
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    di += cx;
    ax = memoryAGet16(ds, di + 5760);
    bx = memoryAGet16(ds, di + 5762);
    dx = memoryAGet16(ds, di + 5764);
    push(cs);
    cs = 0x0a08;
    sub_b13c();
    assert(cs == 0x01ed);
    push(dx);
    push(ax);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 5992);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = pop();
    bx = pop();
    if (dx == bx)
        goto loc_3119;
    goto loc_3197;
loc_3119: // 01ed:1249
    if (ax != cx)
        goto loc_3197;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    di += cx;
    ax = memoryAGet16(ds, di + 5868);
    bx = memoryAGet16(ds, di + 5870);
    dx = memoryAGet16(ds, di + 5872);
    push(cs);
    cs = 0x0a08;
    sub_b13c();
    assert(cs == 0x01ed);
    push(dx);
    push(ax);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6028);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = pop();
    bx = pop();
    if (dx != bx)
        goto loc_3197;
    if (ax != cx)
        goto loc_3197;
    goto loc_34df;
loc_3197: // 01ed:12c7
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    di += cx;
    ax = memoryAGet16(ds, di + 5760);
    bx = memoryAGet16(ds, di + 5762);
    dx = memoryAGet16(ds, di + 5764);
    push(cs);
    cs = 0x0a08;
    sub_b13c();
    assert(cs == 0x01ed);
    di = 0x0e45;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    bx = ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    memoryASet16(ds, di + 6064, bx);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0012);
    di += cx;
    ax = memoryAGet16(ds, di + 5868);
    bx = memoryAGet16(ds, di + 5870);
    dx = memoryAGet16(ds, di + 5872);
    push(cs);
    cs = 0x0a08;
    sub_b13c();
    assert(cs == 0x01ed);
    di = 0x0e45;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    bx = ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    memoryASet16(ds, di + 6100, bx);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    push(memoryAGet16(ds, di + 6064));
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    push(memoryAGet16(ds, di + 6100));
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 16, ax);
    if (memoryAGet16(ss, bp - 16) != 0x0000)
        goto loc_32ee;
    goto loc_34df;
loc_32ee: // 01ed:141e
    if (memoryAGet(ss, bp - 13) != 0x02)
        goto loc_32f7;
    goto loc_339e;
loc_32f7: // 01ed:1427
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 5996);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6064);
    if (ax != bx)
        goto loc_3391;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 6032);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6100);
    if (ax == bx)
        goto loc_339b;
loc_3391: // 01ed:14c1
    memoryASet(ss, bp - 14, 0x01);
    ax = memoryAGet16(ss, bp - 16);
    memoryASet16(ss, bp - 18, ax);
loc_339b: // 01ed:14cb
    goto loc_34df;
loc_339e: // 01ed:14ce
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 5994);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6064);
    if (ax != bx)
        goto loc_343b;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 6030);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6100);
    if (ax != bx)
        goto loc_343b;
    goto loc_34df;
loc_343b: // 01ed:156b
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 5998);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6064);
    if (ax != bx)
        goto loc_34d5;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    bx = memoryAGet16(ds, di + 6034);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e3d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    di += cx;
    ax = memoryAGet16(ds, di + 6100);
    if (ax == bx)
        goto loc_34df;
loc_34d5: // 01ed:1605
    memoryASet(ss, bp - 14, 0x01);
    ax = memoryAGet16(ss, bp - 16);
    memoryASet16(ss, bp - 18, ax);
loc_34df: // 01ed:160f
    if (memoryAGet(ss, bp - 13) == 0x03)
        goto loc_34e8;
    goto loc_30a0;
loc_34e8: // 01ed:1618
    if (memoryAGet(ds, 0x0dcd) == 0x00)
        goto loc_350a;
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_350a;
    memoryASet16(ss, bp - 16, 0x000f);
    if (memoryAGet16(ss, bp - 18) == 0x000f)
        goto loc_3508;
    memoryASet(ss, bp - 14, 0x00);
loc_3508: // 01ed:1638
    goto loc_3533;
loc_350a: // 01ed:163a
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0e4d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    memoryASet16(ss, bp - 16, ax);
loc_3533: // 01ed:1663
    if (memoryAGet16(ss, bp - 16) != 0x000f)
        goto loc_356b;
    if (memoryAGet(ds, 0x0dce) != 0x01)
        goto loc_356b;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0e4d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    memoryASet16(ss, bp - 20, ax);
    goto loc_3571;
loc_356b: // 01ed:169b
    ax = memoryAGet16(ss, bp - 16);
    memoryASet16(ss, bp - 20, ax);
loc_3571: // 01ed:16a1
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6066);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 5994, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6102);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 6030, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6066));
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6102));
    push(memoryAGet16(ss, bp - 20));
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6070);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 5998, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6106);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 6034, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6070));
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6106));
    push(memoryAGet16(ss, bp - 20));
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6068);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 5996, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    cx = memoryAGet16(ds, di + 6104);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    memoryASet16(ds, di + 6032, cx);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6068));
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    si = di;
    di <<= 1;
    di += si;
    push(memoryAGet16(ds, di + 6104));
    push(memoryAGet16(ss, bp - 16));
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
    if (memoryAGet(ss, bp - 14) != 0x00)
        goto loc_3766;
    goto loc_39e0;
loc_3766: // 01ed:1896
    memoryASet(ss, bp - 13, 0x01);
loc_376a: // 01ed:189a
    if (memoryAGet(ss, bp - 13) > 0x06)
        goto loc_37a3;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0e4d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    if (ax == memoryAGet16(ss, bp - 18))
        goto loc_37a3;
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
    goto loc_376a;
loc_37a3: // 01ed:18d3
    if (memoryAGet(ds, 0x0d80) != 0x00)
        goto loc_37ad;
    goto loc_3851;
loc_37ad: // 01ed:18dd
    if (memoryAGet(ss, bp - 13) <= 0x06)
        goto loc_37b6;
    goto loc_3851;
loc_37b6: // 01ed:18e6
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_37c3;
    goto loc_3851;
loc_37c3: // 01ed:18f3
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) == 0x00)
        goto loc_381a;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    if (al == memoryAGet(ss, bp - 13))
        goto loc_384e;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    cl = memoryAGet(ds, di + 3519);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    if (al == cl)
        goto loc_384e;
loc_381a: // 01ed:194a
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) == 0x00)
        goto loc_3851;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_3851;
loc_384e: // 01ed:197e
    goto loc_39e0;
loc_3851: // 01ed:1981
    if (memoryAGet(ds, 0x0d89) > 0x00)
        goto loc_385b;
    goto loc_3938;
loc_385b: // 01ed:198b
    if (memoryAGet(ss, bp - 13) <= 0x06)
        goto loc_3864;
    goto loc_3938;
loc_3864: // 01ed:1994
    if (memoryAGet(ds, 0x0d89) != 0x01)
        goto loc_3872;
    if (memoryAGet(ds, 0x0daf) != 0x00)
        goto loc_387f;
loc_3872: // 01ed:19a2
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_387f;
    goto loc_3938;
loc_387f: // 01ed:19af
    if (memoryAGet(ds, 0x0d82) != 0x00)
        goto loc_38a1;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 6167) == 0x00)
        goto loc_38a1;
    goto loc_3938;
loc_38a1: // 01ed:19d1
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, memoryAGet(ds, di + 4189) + 1);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 4189) <= 0x09)
        goto loc_38e4;
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, 0x09);
loc_38e4: // 01ed:1a14
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    push(ax);
    push(0x0274);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    imul(ax, ax, 0x0048);
    ax += 0x0000;
    push(ax);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    dx = 0;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0e4d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
loc_3938: // 01ed:1a68
    memoryASet16(ds, 0x1822, memoryAGet16(ds, 0x1822) - 1);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 6167, 0x01);
    if (memoryAGet(ds, 0x0d89) >= 0x02)
        goto loc_3972;
    ax = memoryAGet16(ds, 0x1670);
    ax -= memoryAGet16(ds, 0x1822);
    ax--;
    cl = al;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, memoryAGet(ds, di + 4189) + cl);
loc_3972: // 01ed:1aa2
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    push(ax);
    push(0x0274);
    imul(ax, memoryAGet16(ss, bp + 4), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x0e25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x0e4d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    if (memoryAGet(ds, 0x0d83) == 0x00)
        goto loc_39e0;
    if (memoryAGet16(ds, 0x0d86) != 0x0000)
        goto loc_39d7;
    memoryASet16(ds, 0x0d86, 0x0014);
    memoryASet(ds, 0x0d85, 0x02);
    goto loc_39e0;
loc_39d7: // 01ed:1b07
    memoryASet(ds, 0x0d85, memoryAGet(ds, 0x0d85) + 1);
    memoryASet16(ds, 0x0d86, memoryAGet16(ds, 0x0d86) + 0x0014);
loc_39e0: // 01ed:1b10
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_39fc() // 01ed:1b2c
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    memoryASet16(ds, 0x0dd0, memoryAGet16(ds, 0x0dd0) - 1);
    if (memoryAGet16(ds, 0x0dd0) == 0x0000)
        goto loc_3a14;
    goto loc_3b7a;
loc_3a14: // 01ed:1b44
    if (memoryAGet(ds, 0x0dcc) != 0x00)
        goto loc_3a1e;
    goto loc_3ad5;
loc_3a1e: // 01ed:1b4e
    memoryASet(ds, 0x0dce, memoryAGet(ds, 0x0dce) - 1);
    if (memoryAGet(ds, 0x0dce) <= 0x00)
        goto loc_3a42;
    if (memoryAGet(ds, 0x0dce) >= 0x03)
        goto loc_3a3a;
    push(0x07d0);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    goto loc_3a42;
loc_3a3a: // 01ed:1b6a
    push(0x03e8);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_3a42: // 01ed:1b72
    memoryASet16(ds, 0x0dd0, 0x01f4);
    if (memoryAGet(ds, 0x0dce) <= 0x00)
        goto loc_3a6b;
    al = memoryAGet(ds, 0x0dce);
    ah = 0;
    push(ax);
    push(0x0274);
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    imul(ax, ax, 0x0048);
    ax += 0x0000;
    push(ax);
    push(0x000f);
    sub_25f9();
    goto loc_3ad2;
loc_3a6b: // 01ed:1b9b
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    dx = 0;
    di = 0x1b14;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    push(ax);
    push(0x0274);
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    imul(ax, ax, 0x0048);
    ax += 0x0000;
    push(ax);
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    dx = 0;
    di = 0x1b14;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1b1c;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    memoryASet(ds, 0x0dcc, 0x00);
    push(0x2710);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax += 0x03e8;
    memoryASet16(ds, 0x0dd0, ax);
loc_3ad2: // 01ed:1c02
    goto loc_3b75;
loc_3ad5: // 01ed:1c05
    push(0x03e8);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_3add: // 01ed:1c0d
    push(0x1770);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    cx = 0x0006;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    ax++;
    dx = 0;
    di = 0x1b24;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0dcc, al);
    if (memoryAGet(ds, 0x0dcc) <= 0x00)
        goto loc_3add;
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    dx = 0;
    di = 0x1b14;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_3add;
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    dx = 0;
    di = 0x1b14;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 6167) != 0x00)
        goto loc_3add;
    push(0x0007);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax += 0x0003;
    dx = 0;
    di = 0x1b24;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0dce, al);
    if (memoryAGet(ds, 0x0dce) <= 0x09)
        goto loc_3b55;
    memoryASet(ds, 0x0dce, 0x09);
loc_3b55: // 01ed:1c85
    memoryASet16(ds, 0x0dd0, 0x01f4);
    al = memoryAGet(ds, 0x0dce);
    ah = 0;
    push(ax);
    push(0x0274);
    al = memoryAGet(ds, 0x0dcc);
    ah = 0;
    imul(ax, ax, 0x0048);
    ax += 0x0000;
    push(ax);
    push(0x000f);
    sub_25f9();
loc_3b75: // 01ed:1ca5
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
loc_3b7a: // 01ed:1caa
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3be3() // 01ed:1d13
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x05aa;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x05aa;
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_3bfe;
loc_3bfa: // 01ed:1d2a
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_3bfe: // 01ed:1d2e
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3525, 0x01);
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_3c7f;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_3c7f;
    memoryASet16(ss, bp - 266, 0x0001);
    goto loc_3c4a;
loc_3c46: // 01ed:1d76
    memoryASet16(ss, bp - 266, memoryAGet16(ss, bp - 266) + 1);
loc_3c4a: // 01ed:1d7a
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    if (ax != memoryAGet16(ss, bp - 264))
        goto loc_3c78;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3525, memoryAGet(ds, di + 3525) + 1);
loc_3c78: // 01ed:1da8
    if (memoryAGet16(ss, bp - 266) != 0x0006)
        goto loc_3c46;
loc_3c7f: // 01ed:1daf
    if (memoryAGet16(ss, bp - 264) == 0x0006)
        goto loc_3c89;
    goto loc_3bfa;
loc_3c89: // 01ed:1db9
    memoryASet16(ss, bp - 926, 0x1f81);
    memoryASet16(ss, bp - 924, 0x5214);
    memoryASet16(ss, bp - 922, 0x1e06);
    push(cs);
    cs = 0x0a08;
    sub_b650();
    assert(cs == 0x01ed);
    sub_2174();
    sub_1f34();
    ax = 0;
    memoryASet16(ds, 0x184a, ax);
    ax = 0;
    memoryASet16(ds, 0x0d86, ax);
    memoryASet(ds, 0x0d85, 0x00);
    memoryASet(ds, 0x0d88, 0x01);
    memoryASet(ds, 0x0d84, 0x00);
    memoryASet16(ds, 0x1820, 0x0001);
    goto loc_3ccb;
loc_3cc7: // 01ed:1df7
    memoryASet16(ds, 0x1820, memoryAGet16(ds, 0x1820) + 1);
loc_3ccb: // 01ed:1dfb
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_3ce3;
    goto loc_3f5b;
loc_3ce3: // 01ed:1e13
    memoryASet(ss, bp - 256, 0x00);
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_3cf4;
loc_3cf0: // 01ed:1e20
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_3cf4: // 01ed:1e24
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cb4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cx = ax;
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += cx;
    if (memoryAGet(ds, di + 3940) == 0x20)
        goto loc_3d73;
    di = bp - 0x5aa;
    push(ss);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = bp - 0x4aa;
    push(ss);
    push(di);
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cb4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cx = ax;
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += cx;
    al = memoryAGet(ds, di + 3940);
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abd1();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
loc_3d73: // 01ed:1ea3
    if (memoryAGet16(ss, bp - 264) == 0x0008)
        goto loc_3d7d;
    goto loc_3cf0;
loc_3d7d: // 01ed:1ead
    di = bp - 0x4aa;
    push(ss);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = 0x1cbc;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 935, 0x00);
    di = bp - 0x100;
    push(ss);
    push(di);
    di = 0x1cbc;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_3e09;
    di = bp - 0x392;
    push(ss);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x01ed);
    di = bp - 0x392;
    push(ss);
    push(di);
    push(0x0207);
    push(cs);
    cs = 0x0a08;
    sub_b819();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x01ed);
    if (ax)
        goto loc_3e09;
    di = bp - 0x392;
    push(ss);
    push(di);
    di = bp - 0x312;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b8ce();
    assert(cs == 0x01ed);
    sp += 0x0004;
    memoryASet(ss, bp - 935, 0x01);
    di = bp - 0x392;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x01ed);
loc_3e09: // 01ed:1f39
    if (memoryAGet(ss, bp - 935) != 0x00)
        goto loc_3e13;
    goto loc_3ec6;
loc_3e13: // 01ed:1f43
    push(0x023c);
    imul(ax, memoryAGet16(ds, 0x1820), 0x0048);
    ax += 0x0000;
    ax -= 0x0014;
    push(ax);
    di = bp - 0x312;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 264, 0x023c);
    goto loc_3e3b;
loc_3e37: // 01ed:1f67
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_3e3b: // 01ed:1f6b
    imul(ax, memoryAGet16(ds, 0x1820), 0x0048);
    ax += 0x0000;
    ax -= 0x0014;
    ax += 0x0010;
    ax--;
    memoryASet16(ss, bp - 940, ax);
    imul(ax, memoryAGet16(ds, 0x1820), 0x0048);
    ax += 0x0000;
    ax -= 0x0014;
    if ((short)ax > (short)memoryAGet16(ss, bp - 940))
        goto loc_3eb8;
    memoryASet16(ss, bp - 266, ax);
    goto loc_3e69;
loc_3e65: // 01ed:1f95
    memoryASet16(ss, bp - 266, memoryAGet16(ss, bp - 266) + 1);
loc_3e69: // 01ed:1f99
    push(memoryAGet16(ss, bp - 264));
    push(memoryAGet16(ss, bp - 266));
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    if (stop(/*condition!*/))
        goto loc_3eae;
    push(memoryAGet16(ss, bp - 264));
    push(memoryAGet16(ss, bp - 266));
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1cc1;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
loc_3eae: // 01ed:1fde
    ax = memoryAGet16(ss, bp - 266);
    if (ax != memoryAGet16(ss, bp - 940))
        goto loc_3e65;
loc_3eb8: // 01ed:1fe8
    if (memoryAGet16(ss, bp - 264) == 0x027b)
        goto loc_3ec3;
    goto loc_3e37;
loc_3ec3: // 01ed:1ff3
    goto loc_3f5b;
loc_3ec6: // 01ed:1ff6
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1cc1;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    di = 0x1cc9;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x01ed);
    if (!flags.zero)
        goto loc_3f30;
    push(0x023c);
    imul(ax, memoryAGet16(ds, 0x1820), 0x0048);
    ax += 0x0000;
    ax -= 0x0010;
    push(ax);
    di = 0x1cd2;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0655;
    sub_7cdc();
    assert(cs == 0x01ed);
    goto loc_3f5b;
loc_3f30: // 01ed:2060
    push(0x023c);
    imul(ax, memoryAGet16(ds, 0x1820), 0x0048);
    ax += 0x0000;
    ax -= 0x0010;
    push(ax);
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0655;
    sub_7cdc();
    assert(cs == 0x01ed);
loc_3f5b: // 01ed:208b
    if (memoryAGet16(ds, 0x1820) == 0x0006)
        goto loc_3f65;
    goto loc_3cc7;
loc_3f65: // 01ed:2095
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_3f71;
loc_3f6d: // 01ed:209d
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_3f71: // 01ed:20a1
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 6154, ax);
    if (memoryAGet16(ss, bp - 264) != 0x0006)
        goto loc_3f6d;
loc_3f8f: // 01ed:20bf
    sub_1f62();
    memoryASet16(ds, 0x1840, 0x0001);
    memoryASet16(ds, 0x1842, 0xffce);
    push(0x0000);
    push(0x0000);
    sub_2966();
    memoryASet16(ds, 0x1820, 0x0001);
    goto loc_3fb1;
loc_3fad: // 01ed:20dd
    memoryASet16(ds, 0x1820, memoryAGet16(ds, 0x1820) + 1);
loc_3fb1: // 01ed:20e1
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_3fcd;
    push(memoryAGet16(ds, 0x1820));
    sub_22c0();
loc_3fcd: // 01ed:20fd
    if (memoryAGet16(ds, 0x1820) != 0x0006)
        goto loc_3fad;
    ax = memoryAGet16(ds, 0x1670);
    memoryASet16(ds, 0x1822, ax);
    ax = 0;
    memoryASet16(ds, 0x1824, ax);
    memoryASet16(ds, 0x1826, ax);
    memoryASet16(ds, 0x1820, 0x0001);
loc_3fe8: // 01ed:2118
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) != 0x00)
        goto loc_4003;
    memoryASet16(ds, 0x1820, memoryAGet16(ds, 0x1820) + 1);
    goto loc_3fe8;
loc_4003: // 01ed:2133
    memoryASet(ds, 0x1828, 0x00);
    memoryASet16(ds, 0x182a, 0x0032);
    ax = 0;
    memoryASet16(ss, bp - 934, ax);
    memoryASet16(ss, bp - 932, 0x0064);
    memoryASet(ds, 0x0dcc, 0x00);
    push(0x2710);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 938, ax);
    push(0x1388);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax += 0x01f4;
    memoryASet16(ds, 0x0dd0, ax);
loc_4039: // 01ed:2169
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 6167) != 0x00)
        goto loc_40c8;
    push(memoryAGet16(ds, 0x1820));
    sub_2d25();
    ax = memoryAGet16(ds, 0x20c8);
    dx = memoryAGet16(ds, 0x20ca); // gabo
    memoryASet16(ss, bp - 942, ax);
    memoryASet16(ss, bp - 940, dx);
    ax = 0x0001;
    dx = 0;
    if ((short)dx > (short)memoryAGet16(ss, bp - 940))
        goto loc_40c8;
    if ((short)dx < (short)memoryAGet16(ss, bp - 940))
        goto loc_4077;
    if (ax > memoryAGet16(ss, bp - 942))
        goto loc_40c8;
loc_4077: // 01ed:21a7
    memoryASet16(ss, bp - 930, ax);
    memoryASet16(ss, bp - 928, dx);
    goto loc_408b;
loc_4081: // 01ed:21b1
    flags.carry = (memoryAGet16(ss, bp - 930) + 0x0001) >= 0x10000;
    memoryASet16(ss, bp - 930, memoryAGet16(ss, bp - 930) + 0x0001);
    memoryASet16(ss, bp - 928, memoryAGet16(ss, bp - 928) + flags.carry);
loc_408b: // 01ed:21bb
    ax = memoryAGet16(ss, bp - 926);
    bx = memoryAGet16(ss, bp - 924);
    dx = memoryAGet16(ss, bp - 922);
    cx = memoryAGet16(ss, bp - 926);
    si = memoryAGet16(ss, bp - 924);
    di = memoryAGet16(ss, bp - 922);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 920, ax);
    memoryASet16(ss, bp - 918, bx);
    memoryASet16(ss, bp - 916, dx);
    ax = memoryAGet16(ss, bp - 930);
    dx = memoryAGet16(ss, bp - 928);
    if (dx != memoryAGet16(ss, bp - 940))
        goto loc_4081;
    if (ax != memoryAGet16(ss, bp - 942))
        goto loc_4081;
loc_40c8: // 01ed:21f8
    if (memoryAGet(ds, 0x0dcd) == 0x00)
        goto loc_40d2;
    sub_39fc();
loc_40d2: // 01ed:2202
    memoryASet16(ds, 0x1820, memoryAGet16(ds, 0x1820) + 1);
    if ((short)memoryAGet16(ds, 0x1820) > (short)0x0006)
        goto loc_40e0;
    goto loc_4166;
loc_40e0: // 01ed:2210
    memoryASet16(ds, 0x1820, 0x0001);
    sub_21c6();
    if ((short)memoryAGet16(ds, 0x182a) <= (short)0x0000)
        goto loc_4166;
    ax = memoryAGet16(ds, 0x182a);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = memoryAGet16(ds, 0x20c8);
    bx = memoryAGet16(ds, 0x20ca);
    push(cs);
    cs = 0x0a08;
    sub_a9f1();
    assert(cs == 0x01ed);
    cx = 0x0003;
    bx = 0;
    push(cs);
    cs = 0x0a08;
    sub_aa0c();
    assert(cs == 0x01ed);
    if ((short)dx < (short)0x0000)
        goto loc_4166;
    if ((short)dx > (short)0x0000)
        goto loc_4117;
    if (ax < 0x0001)
        goto loc_4166;
loc_4117: // 01ed:2247
    memoryASet16(ss, bp - 930, ax);
    memoryASet16(ss, bp - 928, dx);
    goto loc_412b;
loc_4121: // 01ed:2251
    flags.carry = memoryAGet16(ss, bp - 930) < 0x0001;
    memoryASet16(ss, bp - 930, memoryAGet16(ss, bp - 930) - 0x0001);
    memoryASet16(ss, bp - 928, memoryAGet16(ss, bp - 928) - flags.carry);
loc_412b: // 01ed:225b
    ax = memoryAGet16(ss, bp - 926);
    bx = memoryAGet16(ss, bp - 924);
    dx = memoryAGet16(ss, bp - 922);
    cx = memoryAGet16(ss, bp - 926);
    si = memoryAGet16(ss, bp - 924);
    di = memoryAGet16(ss, bp - 922);
    push(cs);
    cs = 0x0a08;
    sub_b11c();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 920, ax);
    memoryASet16(ss, bp - 918, bx);
    memoryASet16(ss, bp - 916, dx);
    memoryASet16(ds, 0x182a, memoryAGet16(ds, 0x182a) - 1);
    if (memoryAGet16(ss, bp - 928) != 0x0000)
        goto loc_4121;
    if (memoryAGet16(ss, bp - 930) != 0x0001)
        goto loc_4121;
loc_4166: // 01ed:2296
    ax = memoryAGet16(ds, 0x1820);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_417e;
    goto loc_40c8;
loc_417e: // 01ed:22ae
    if (memoryAGet(ds, 0x0d81) != 0x00)
        goto loc_4188;
    goto loc_4262;
loc_4188: // 01ed:22b8
    memoryASet16(ss, bp - 938, memoryAGet16(ss, bp - 938) - 1);
    if (memoryAGet16(ss, bp - 938) == 0x0000)
        goto loc_4196;
    goto loc_4262;
loc_4196: // 01ed:22c6
    push(0x022b);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x1cdb;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 258, ax);
    push(0x01db);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x1cdb;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 260, ax);
    push(0x0019);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x1cdb;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 262, ax);
    if ((short)memoryAGet16(ss, bp - 262) <= (short)0x0007)
        goto loc_4196;
    ax = memoryAGet16(ss, bp - 258);
    ax += memoryAGet16(ss, bp - 262);
    if ((short)ax >= (short)0x0229)
        goto loc_4196;
    ax = memoryAGet16(ss, bp - 258);
    ax -= memoryAGet16(ss, bp - 262);
    if ((short)ax <= (short)0x0006)
        goto loc_4196;
    ax = memoryAGet16(ss, bp - 260);
    ax += memoryAGet16(ss, bp - 262);
    if ((short)ax >= (short)0x01d9)
        goto loc_4196;
    ax = memoryAGet16(ss, bp - 260);
    ax -= memoryAGet16(ss, bp - 262);
    if ((short)ax <= (short)0x0006)
        goto loc_4196;
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    push(0x0001);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_71c6();
    assert(cs == 0x01ed);
    push(memoryAGet16(ss, bp - 258));
    push(memoryAGet16(ss, bp - 260));
    push(0x0000);
    push(0x0168);
    ax = memoryAGet16(ss, bp - 262);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1ce3;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_72a1();
    assert(cs == 0x01ed);
loc_4247: // 01ed:2377
    push(0x2710);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 938, ax);
    if (memoryAGet16(ss, bp - 938) > 0x0bb8)
        goto loc_4262;
    if (memoryAGet16(ss, bp - 938) >= 0x0064)
        goto loc_4247;
loc_4262: // 01ed:2392
    if (memoryAGet(ds, 0x0d83) != 0x00)
        goto loc_426c;
    goto loc_4319;
loc_426c: // 01ed:239c
    if (memoryAGet16(ds, 0x0d86) > 0x0000)
        goto loc_4276;
    goto loc_4319;
loc_4276: // 01ed:23a6
    al = 0x0c;
    dx = 0x03d4;
    out(dx, al);
    al = memoryAGet(ds, 0x0d84);
    ah = 0;
    ax >>= 1;
    dx = ax;
    al = memoryAGet(ds, 0x0d84);
    ah = 0;
    ax <<= 1;
    ax += dx;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cb4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    dx = 0x03d5;
    out(dx, al);
    al = 0x0d;
    dx = 0x03d4;
    out(dx, al);
    al = memoryAGet(ds, 0x0d84);
    al &= 0x01;
    ah = 0;
    ax <<= 7;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cb4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    dx = 0x03d5;
    out(dx, al);
    memoryASet16(ds, 0x0d86, memoryAGet16(ds, 0x0d86) - 1);
    if (memoryAGet16(ds, 0x0d86) != 0x0000)
        goto loc_42e1;
    if (memoryAGet(ds, 0x0d84) == 0x00)
        goto loc_42d2;
    memoryASet16(ds, 0x0d86, 0x0005);
    goto loc_42e1;
loc_42d2: // 01ed:2402
    memoryASet(ds, 0x0d85, 0x00);
    memoryASet(ds, 0x0d88, 0xff);
    memoryASet(ds, 0x0d84, 0x01);
loc_42e1: // 01ed:2411
    ax = memoryAGet16(ds, 0x0d86);
    dx = 0;
    cx = 0x0005;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    if (ax)
        goto loc_4319;
    al = memoryAGet(ds, 0x0d88);
    memoryASet(ds, 0x0d84, memoryAGet(ds, 0x0d84) + al);
    if (memoryAGet(ds, 0x0d84) != 0x00)
        goto loc_4305;
    memoryASet(ds, 0x0d88, 0x01);
    goto loc_4319;
loc_4305: // 01ed:2435
    al = memoryAGet(ds, 0x0d84);
    if (al < memoryAGet(ds, 0x0d85))
        goto loc_4319;
    memoryASet(ds, 0x0d88, 0xff);
    al = memoryAGet(ds, 0x0d85);
    memoryASet(ds, 0x0d84, al);
loc_4319: // 01ed:2449
    if (memoryAGet(ds, 0x0dae) != 0x00)
        goto loc_4323;
    goto loc_4576;
loc_4323: // 01ed:2453
    ax = memoryAGet16(ds, 0x1822);
    si = ax;
    ax <<= 1;
    ax += si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0002;
    idiv(cx);
    memoryASet16(ss, bp - 934, memoryAGet16(ss, bp - 934) + ax);
    if (memoryAGet16(ss, bp - 934) > 0xfde8)
        goto loc_4341;
    goto loc_4576;
loc_4341: // 01ed:2471
    push(0x0019);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x1cdb;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 258, ax);
    memoryASet16(ss, bp - 262, 0x0013);
    memoryASet16(ss, bp - 266, 0x0001);
    goto loc_4368;
loc_4364: // 01ed:2494
    memoryASet16(ss, bp - 266, memoryAGet16(ss, bp - 266) + 1);
loc_4368: // 01ed:2498
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 6167) == 0x00)
        goto loc_4381;
    goto loc_44ce;
loc_4381: // 01ed:24b1
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_439a;
    goto loc_44ce;
loc_439a: // 01ed:24ca
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1cc1;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    ax = 0;
    memoryASet16(ss, bp - 260, ax);
    goto loc_43d3;
loc_43cf: // 01ed:24ff
    memoryASet16(ss, bp - 260, memoryAGet16(ss, bp - 260) + 1);
loc_43d3: // 01ed:2503
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024e;
    push(ax);
    push(0x0018);
    ax = memoryAGet16(ss, bp - 262);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1ce3;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_727f();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 262, memoryAGet16(ss, bp - 262) - 1);
    if (memoryAGet16(ss, bp - 260) != 0x0002)
        goto loc_43cf;
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, memoryAGet(ds, di + 4189) + 1);
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 4189) <= 0x09)
        goto loc_4438;
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, 0x09);
loc_4438: // 01ed:2568
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    push(ax);
    push(0x0274);
    imul(ax, memoryAGet16(ss, bp - 266), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1cc1;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
    if (memoryAGet(ds, 0x1672) == 0x00)
        goto loc_44c9;
    memoryASet16(ss, bp - 264, 0x03e8);
    goto loc_4498;
loc_4494: // 01ed:25c4
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_4498: // 01ed:25c8
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1ce3;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    ax = 0x1388;
    ax -= memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1ce3;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 264) != 0x0fa0)
        goto loc_4494;
loc_44c9: // 01ed:25f9
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
loc_44ce: // 01ed:25fe
    if (memoryAGet16(ss, bp - 266) == 0x0006)
        goto loc_44d8;
    goto loc_4364;
loc_44d8: // 01ed:2608
    push(0x000f);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
loc_44df: // 01ed:260f
    if ((short)memoryAGet16(ss, bp - 262) <= (short)0x0000)
        goto loc_4509;
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024e;
    push(ax);
    push(0x0018);
    ax = memoryAGet16(ss, bp - 262);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1ce3;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_727f();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 262, memoryAGet16(ss, bp - 262) - 1);
    goto loc_44df;
loc_4509: // 01ed:2639
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024e;
    push(ax);
    push(0x0018);
    push(cs);
    cs = 0x0655;
    sub_70fd();
    assert(cs == 0x01ed);
    push(0x0000);
    push(0xffee);
    push(cs);
    cs = 0x0655;
    sub_711a();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024e;
    push(ax);
    push(0x0018);
    push(cs);
    cs = 0x0655;
    sub_70fd();
    assert(cs == 0x01ed);
    push(0x000a);
    push(0x000a);
    push(cs);
    cs = 0x0655;
    sub_711a();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024d;
    push(ax);
    push(0x0018);
    push(cs);
    cs = 0x0655;
    sub_70fd();
    assert(cs == 0x01ed);
    push(0x0000);
    push(0xffee);
    push(cs);
    cs = 0x0655;
    sub_711a();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 258);
    ax += 0x024d;
    push(ax);
    push(0x0018);
    push(cs);
    cs = 0x0655;
    sub_70fd();
    assert(cs == 0x01ed);
    push(0x000a);
    push(0x000a);
    push(cs);
    cs = 0x0655;
    sub_711a();
    assert(cs == 0x01ed);
    ax = 0;
    memoryASet16(ss, bp - 934, ax);
loc_4576: // 01ed:26a6
    if ((short)memoryAGet16(ds, 0x1822) >= (short)0x0002)
        goto loc_4581;
    memoryASet16(ss, bp - 932, memoryAGet16(ss, bp - 932) - 1);
loc_4581: // 01ed:26b1
    if (memoryAGet16(ds, 0x0d86) == 0x0000)
        goto loc_458b;
    goto loc_4039;
loc_458b: // 01ed:26bb
    if ((short)memoryAGet16(ds, 0x1822) >= (short)0x0002)
        goto loc_4599;
    if (memoryAGet16(ss, bp - 932) == 0x0000)
        goto loc_45a3;
loc_4599: // 01ed:26c9
    if (memoryAGet(ds, 0x20d1) == 0x01)
        goto loc_45a3;
    goto loc_4039;
loc_45a3: // 01ed:26d3
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    if ((short)memoryAGet16(ds, 0x1822) < (short)0x0002)
        goto loc_45b2;
    goto loc_46b2;
loc_45b2: // 01ed:26e2
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_45be;
loc_45ba: // 01ed:26ea
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_45be: // 01ed:26ee
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_45d7;
    goto loc_46a8;
loc_45d7: // 01ed:2707
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 6167) == 0x00)
        goto loc_45f0;
    goto loc_46a8;
loc_45f0: // 01ed:2720
    if (memoryAGet(ds, 0x0d89) >= 0x02)
        goto loc_4610;
    ax = memoryAGet16(ds, 0x1670);
    ax--;
    cl = al;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, memoryAGet(ds, di + 4189) + cl);
loc_4610: // 01ed:2740
    if (memoryAGet(ds, 0x0d89) != 0x01)
        goto loc_4631;
    if (memoryAGet(ds, 0x0daf) == 0x00)
        goto loc_4631;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, memoryAGet(ds, di + 4189) + 1);
loc_4631: // 01ed:2761
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 4189) <= 0x09)
        goto loc_465b;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 4189, 0x09);
loc_465b: // 01ed:278b
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    push(ax);
    push(0x0274);
    imul(ax, memoryAGet16(ss, bp - 264), 0x0048);
    ax += 0x0000;
    push(ax);
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x1cc1;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_25f9();
loc_46a8: // 01ed:27d8
    if (memoryAGet16(ss, bp - 264) == 0x0006)
        goto loc_46b2;
    goto loc_45ba;
loc_46b2: // 01ed:27e2
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_46be;
loc_46ba: // 01ed:27ea
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_46be: // 01ed:27ee
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_4702;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6154, memoryAGet16(ds, di + 6154) + cx);
    goto loc_4740;
loc_4702: // 01ed:2832
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 4189);
    ah = 0;
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    dx = 0;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6154, memoryAGet16(ds, di + 6154) + cx);
loc_4740: // 01ed:2870
    if (memoryAGet16(ss, bp - 264) == 0x0006)
        goto loc_474a;
    goto loc_46ba;
loc_474a: // 01ed:287a
    if (memoryAGet(ds, 0x20d1) != 0x01)
        goto loc_4756;
    memoryASet(ds, 0x1828, 0x01);
loc_4756: // 01ed:2886
    sub_1f98();
loc_4759: // 01ed:2889
    push(cs);
    cs = 0x09a6;
    sub_9d5b();
    assert(cs == 0x01ed);
    if (!al)
        goto loc_4769;
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    goto loc_4759;
loc_4769: // 01ed:2899
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    push(ax);
    di = 0x1ceb;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ad56();
    assert(cs == 0x01ed);
//    if (flags.zero)
//        goto loc_4769;
    ax = 0;
    memoryASet16(ds, 0x182c, ax);
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_478c;
loc_4788: // 01ed:28b8
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_478c: // 01ed:28bc
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_47a5;
    goto loc_4829;
loc_47a5: // 01ed:28d5
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_4829;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3525);
    ah = 0;
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(cx);
    if ((short)ax <= (short)memoryAGet16(ds, 0x182c))
        goto loc_4829;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3525);
    ah = 0;
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(cx);
    memoryASet16(ds, 0x182c, ax);
    ax = memoryAGet16(ss, bp - 264);
    memoryASet16(ds, 0x182e, ax);
loc_4829: // 01ed:2959
    if (memoryAGet16(ss, bp - 264) == 0x0006)
        goto loc_4833;
    goto loc_4788;
loc_4833: // 01ed:2963
    if (memoryAGet(ds, 0x1828) != 0x00)
        goto loc_485a;
    al = memoryAGet(ds, 0x016c);
    ah = 0;
    dx = 0;
    di = 0x1d0b;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 366);
    ah = 0;
    if ((short)ax <= (short)memoryAGet16(ds, 0x182c))
        goto loc_485a;
    goto loc_3f8f;
loc_485a: // 01ed:298a
    if (memoryAGet(ds, 0x1828) == 0x00)
        goto loc_4864;
    goto loc_497e;
loc_4864: // 01ed:2994
    memoryASet16(ss, bp - 264, 0x0001);
    goto loc_4870;
loc_486c: // 01ed:299c
    memoryASet16(ss, bp - 264, memoryAGet16(ss, bp - 264) + 1);
loc_4870: // 01ed:29a0
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_4889;
    goto loc_4940;
loc_4889: // 01ed:29b9
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) == 0x00)
        goto loc_48a2;
    goto loc_4940;
loc_48a2: // 01ed:29d2
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3525);
    ah = 0;
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 6154);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(cx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6154, cx);
    memoryASet16(ss, bp - 266, 0x0001);
    goto loc_48f4;
loc_48f0: // 01ed:2a20
    memoryASet16(ss, bp - 266, memoryAGet16(ss, bp - 266) + 1);
loc_48f4: // 01ed:2a24
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    if (ax != memoryAGet16(ss, bp - 264))
        goto loc_4939;
    ax = memoryAGet16(ss, bp - 264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    cx = memoryAGet16(ds, di + 6154);
    ax = memoryAGet16(ss, bp - 266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x1cac;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 6154, cx);
loc_4939: // 01ed:2a69
    if (memoryAGet16(ss, bp - 266) != 0x0006)
        goto loc_48f0;
loc_4940: // 01ed:2a70
    if (memoryAGet16(ss, bp - 264) == 0x0006)
        goto loc_494a;
    goto loc_486c;
loc_494a: // 01ed:2a7a
    push(0x0000);
    push(0x0001);
    sub_2966();
    sub_2a0b();
    push(0x03e8);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
loc_495c: // 01ed:2a8c
    push(cs);
    cs = 0x09a6;
    sub_9d5b();
    assert(cs == 0x01ed);
    if (!al)
        goto loc_496c;
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    goto loc_495c;
loc_496c: // 01ed:2a9c
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    push(ax);
    di = 0x1ceb;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ad56();
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_496c;
loc_497e: // 01ed:2aae
    push(cs);
    cs = 0x0655;
    sub_6f9d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4992() // 01ed:2ac2
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax += 0x00c8;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2aba;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
    push(0x0001);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2aba;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_71c6();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 10);
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x00a0;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x0064;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x00a0;
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x0064;
    ax--;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7a98();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_4a23() // 01ed:2b53
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0004;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0004;
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_4a3b;
loc_4a38: // 01ed:2b68
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4a3b: // 01ed:2b6b
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    goto loc_4a45;
loc_4a42: // 01ed:2b72
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_4a45: // 01ed:2b75
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2b4b;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_4992();
    if (memoryAGet16(ss, bp - 4) != 0x000f)
        goto loc_4a42;
    if (memoryAGet16(ss, bp - 2) != 0x003f)
        goto loc_4a38;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4a87() // 01ed:2bb7
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2baf;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 10);
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x00a0;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x0064;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x00a0;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    ax += 0x0064;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_4b2a() // 01ed:2c5a
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x1178;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x1178;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    di = bp - 0xdac;
    push(ss);
    push(di);
    di = 0x2c1a;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x01ed);
    di = bp - 0xdac;
    push(ss);
    push(di);
    push(0x0207);
    push(cs);
    cs = 0x0a08;
    sub_b819();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 3630, 0x0001);
    goto loc_4b7b;
loc_4b77: // 01ed:2ca7
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4b7b: // 01ed:2cab
    di = bp - 0xdac;
    push(ss);
    push(di);
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c25;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x0207);
    stop(); // lea!
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b8ce();
    assert(cs == 0x01ed);
    sp += 0x0004;
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 3630) != 0x0005)
        goto loc_4b77;
    di = bp - 0xdac;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 3894, 0x00);
    memoryASet16(ss, bp - 3630, 0x0001);
    goto loc_4bcd;
loc_4bc9: // 01ed:2cf9
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4bcd: // 01ed:2cfd
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ss, bp + di + 65280) == 0x20)
        goto loc_4c26;
    di = bp - 0x1178;
    push(ss);
    push(di);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = bp - 0x1078;
    push(ss);
    push(di);
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ss, bp + di + 65280);
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abd1();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
loc_4c26: // 01ed:2d56
    if (memoryAGet16(ss, bp - 3630) != 0x0008)
        goto loc_4bc9;
    di = bp - 0x1078;
    push(ss);
    push(di);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = 0x2c35;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    sub_1f34();
    push(0x0120);
    push(0x0020);
    di = bp - 0xd2c;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    push(0x0120);
    push(0x0030);
    di = bp - 0xb25;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    di = bp - 0xdac;
    push(ss);
    push(di);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x01ed);
    di = bp - 0xdac;
    push(ss);
    push(di);
    push(0x0207);
    push(cs);
    cs = 0x0a08;
    sub_b819();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x01ed);
    if (ax)
        goto loc_4cc6;
    di = bp - 0xdac;
    push(ss);
    push(di);
    di = bp - 0x308;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b8ce();
    assert(cs == 0x01ed);
    sp += 0x0004;
    di = bp - 0xdac;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x01ed);
    goto loc_4cee;
loc_4cc6: // 01ed:2df6
    memoryASet16(ss, bp - 3630, 0x0001);
    goto loc_4cd2;
loc_4cce: // 01ed:2dfe
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4cd2: // 01ed:2e02
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c3a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ss, bp + di + 64759, 0x00);
    if (memoryAGet16(ss, bp - 3630) != 0x0207)
        goto loc_4cce;
loc_4cee: // 01ed:2e1e
    ax = 0;
    memoryASet16(ss, bp - 3634, ax);
    ax = 0;
    memoryASet16(ss, bp - 3636, ax);
    memoryASet16(ss, bp - 3638, 0xffff);
    push(0x000f);
    push(cs);
    cs = 0x0655;
    sub_7b8c();
    assert(cs == 0x01ed);
    push(0x011e);
    push(0x00c6);
    push(0x0161);
    push(0x00d9);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    push(0x009e);
    push(0x0062);
    push(0x01e1);
    push(0x00b5);
    push(cs);
    cs = 0x0655;
    sub_717f();
    assert(cs == 0x01ed);
    push(0x0120);
    push(0x00c8);
    di = bp - 0x308;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 3630, 0x0120);
    goto loc_4d47;
loc_4d43: // 01ed:2e73
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4d47: // 01ed:2e77
    memoryASet16(ss, bp - 3632, 0x00c8);
    goto loc_4d53;
loc_4d4f: // 01ed:2e7f
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4d53: // 01ed:2e83
    push(memoryAGet16(ss, bp - 3630));
    push(memoryAGet16(ss, bp - 3632));
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    if (stop(/*condition!*/))
        goto loc_4d7e;
    push(memoryAGet16(ss, bp - 3630));
    push(memoryAGet16(ss, bp - 3632));
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c42;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7dae();
    assert(cs == 0x01ed);
loc_4d7e: // 01ed:2eae
    if (memoryAGet16(ss, bp - 3632) != 0x00d7)
        goto loc_4d4f;
    if (memoryAGet16(ss, bp - 3630) != 0x015f)
        goto loc_4d43;
    push(bp);
    sub_4a23();
loc_4d92: // 01ed:2ec2
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x000f);
    push(bp);
    sub_4a87();
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 257, al);
    al = memoryAGet(ss, bp - 257);
    if (al == 0x00)
        goto loc_4db4;
    goto loc_518d;
loc_4db4: // 01ed:2ee4
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 257, al);
    al = memoryAGet(ss, bp - 257);
    if (al != 0x48)
        goto loc_4de1;
    if ((short)memoryAGet16(ss, bp - 3636) <= (short)0x0000)
        goto loc_4dde;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x0000);
    push(bp);
    sub_4a87();
    memoryASet16(ss, bp - 3636, memoryAGet16(ss, bp - 3636) - 1);
loc_4dde: // 01ed:2f0e
    goto loc_518a;
loc_4de1: // 01ed:2f11
    if (al != 0x4b)
        goto loc_4e01;
    if ((short)memoryAGet16(ss, bp - 3634) <= (short)0x0000)
        goto loc_4dfe;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x0000);
    push(bp);
    sub_4a87();
    memoryASet16(ss, bp - 3634, memoryAGet16(ss, bp - 3634) - 1);
loc_4dfe: // 01ed:2f2e
    goto loc_518a;
loc_4e01: // 01ed:2f31
    if (al != 0x4d)
        goto loc_4e21;
    if ((short)memoryAGet16(ss, bp - 3634) >= (short)0x003f)
        goto loc_4e1e;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x0000);
    push(bp);
    sub_4a87();
    memoryASet16(ss, bp - 3634, memoryAGet16(ss, bp - 3634) + 1);
loc_4e1e: // 01ed:2f4e
    goto loc_518a;
loc_4e21: // 01ed:2f51
    if (al != 0x50)
        goto loc_4e41;
    if ((short)memoryAGet16(ss, bp - 3636) >= (short)0x003f)
        goto loc_4e3e;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x0000);
    push(bp);
    sub_4a87();
    memoryASet16(ss, bp - 3636, memoryAGet16(ss, bp - 3636) + 1);
loc_4e3e: // 01ed:2f6e
    goto loc_518a;
loc_4e41: // 01ed:2f71
    if (al == 0x47)
        goto loc_4e48;
    goto loc_4f14;
loc_4e48: // 01ed:2f78
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4e54;
loc_4e50: // 01ed:2f80
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4e54: // 01ed:2f84
    push(0x0120);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cl = al;
    ax = memoryAGet16(ss, bp - 3632);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ss, bp + di + 61576, cl);
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4e50;
    memoryASet16(ss, bp - 3630, 0x0001);
    goto loc_4e96;
loc_4e92: // 01ed:2fc2
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4e96: // 01ed:2fc6
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4ea2;
loc_4e9e: // 01ed:2fce
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4ea2: // 01ed:2fd2
    ax = memoryAGet16(ss, bp - 3630);
    ax--;
    push(ax);
    push(memoryAGet16(ss, bp - 3632));
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c52;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4e9e;
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_4e92;
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4eea;
loc_4ee6: // 01ed:3016
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4eea: // 01ed:301a
    push(0x003f);
    push(memoryAGet16(ss, bp - 3632));
    ax = memoryAGet16(ss, bp - 3632);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ss, bp + di + 61576);
    ah = 0;
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4ee6;
    goto loc_518a;
loc_4f14: // 01ed:3044
    if (al == 0x4f)
        goto loc_4f1b;
    goto loc_4fe7;
loc_4f1b: // 01ed:304b
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4f27;
loc_4f23: // 01ed:3053
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4f27: // 01ed:3057
    push(0x015f);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cl = al;
    ax = memoryAGet16(ss, bp - 3632);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ss, bp + di + 61576, cl);
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4f23;
    memoryASet16(ss, bp - 3630, 0x003e);
    goto loc_4f69;
loc_4f65: // 01ed:3095
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) - 1);
loc_4f69: // 01ed:3099
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4f75;
loc_4f71: // 01ed:30a1
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4f75: // 01ed:30a5
    ax = memoryAGet16(ss, bp - 3630);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 3632));
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c52;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4f71;
    if (memoryAGet16(ss, bp - 3630) != 0x0000)
        goto loc_4f65;
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_4fbd;
loc_4fb9: // 01ed:30e9
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_4fbd: // 01ed:30ed
    push(0x0000);
    push(memoryAGet16(ss, bp - 3632));
    ax = memoryAGet16(ss, bp - 3632);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ss, bp + di + 61576);
    ah = 0;
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_4fb9;
    goto loc_518a;
loc_4fe7: // 01ed:3117
    if (al == 0x49)
        goto loc_4fee;
    goto loc_50ba;
loc_4fee: // 01ed:311e
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_4ffa;
loc_4ff6: // 01ed:3126
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_4ffa: // 01ed:312a
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    push(0x00c8);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cl = al;
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ss, bp + di + 61576, cl);
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_4ff6;
    memoryASet16(ss, bp - 3632, 0x0001);
    goto loc_503c;
loc_5038: // 01ed:3168
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_503c: // 01ed:316c
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_5048;
loc_5044: // 01ed:3174
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_5048: // 01ed:3178
    push(memoryAGet16(ss, bp - 3630));
    ax = memoryAGet16(ss, bp - 3632);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c52;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_5044;
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_5038;
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_5090;
loc_508c: // 01ed:31bc
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_5090: // 01ed:31c0
    push(memoryAGet16(ss, bp - 3630));
    push(0x000f);
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ss, bp + di + 61576);
    ah = 0;
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_508c;
    goto loc_518a;
loc_50ba: // 01ed:31ea
    if (al == 0x51)
        goto loc_50c1;
    goto loc_518a;
loc_50c1: // 01ed:31f1
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_50cd;
loc_50c9: // 01ed:31f9
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_50cd: // 01ed:31fd
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    push(0x00d7);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c2d;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    cl = al;
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ss, bp + di + 61576, cl);
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_50c9;
    memoryASet16(ss, bp - 3632, 0x000e);
    goto loc_510f;
loc_510b: // 01ed:323b
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) - 1);
loc_510f: // 01ed:323f
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_511b;
loc_5117: // 01ed:3247
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_511b: // 01ed:324b
    push(memoryAGet16(ss, bp - 3630));
    ax = memoryAGet16(ss, bp - 3632);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 3630);
    ax += 0x0120;
    push(ax);
    ax = memoryAGet16(ss, bp - 3632);
    ax += 0x00c8;
    push(ax);
    push(cs);
    cs = 0x0655;
    sub_7d96();
    assert(cs == 0x01ed);
    dx = 0;
    di = 0x2c52;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_5117;
    if (memoryAGet16(ss, bp - 3632) != 0x0000)
        goto loc_510b;
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_5163;
loc_515f: // 01ed:328f
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_5163: // 01ed:3293
    push(memoryAGet16(ss, bp - 3630));
    push(0x0000);
    ax = memoryAGet16(ss, bp - 3630);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x2c4a;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ss, bp + di + 61576);
    ah = 0;
    push(ax);
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_515f;
loc_518a: // 01ed:32ba
    goto loc_525a;
loc_518d: // 01ed:32bd
    if (al != 0x31)
        goto loc_51a2;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(0x0000);
    push(bp);
    sub_4992();
    goto loc_525a;
loc_51a2: // 01ed:32d2
    if (al != 0x32)
        goto loc_51b8;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(memoryAGet16(ss, bp + 4));
    push(bp);
    sub_4992();
    goto loc_525a;
loc_51b8: // 01ed:32e8
    if (al != 0x20)
        goto loc_5219;
    ax = memoryAGet16(ss, bp - 3638);
    if (ax != 0xffff)
        goto loc_51e0;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, bp - 3638, ax);
    push(0x0120);
    push(0x0040);
    di = bp - 0x717;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    goto loc_5217;
loc_51e0: // 01ed:3310
    if (ax != 0x0000)
        goto loc_51ff;
    memoryASet16(ss, bp - 3638, 0xffff);
    push(0x0120);
    push(0x0040);
    di = bp - 0x91e;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
    goto loc_5217;
loc_51ff: // 01ed:332f
    ax = 0;
    memoryASet16(ss, bp - 3638, ax);
    push(0x0120);
    push(0x0040);
    di = bp - 0x510;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0655;
    sub_73be();
    assert(cs == 0x01ed);
loc_5217: // 01ed:3347
    goto loc_525a;
loc_5219: // 01ed:3349
    if (al != 0x08)
        goto loc_525a;
    if (memoryAGet16(ss, bp - 3638) == 0xffff)
        goto loc_525a;
    ax = 0;
    memoryASet16(ss, bp - 3630, ax);
    goto loc_5230;
loc_522c: // 01ed:335c
    memoryASet16(ss, bp - 3630, memoryAGet16(ss, bp - 3630) + 1);
loc_5230: // 01ed:3360
    ax = 0;
    memoryASet16(ss, bp - 3632, ax);
    goto loc_523c;
loc_5238: // 01ed:3368
    memoryASet16(ss, bp - 3632, memoryAGet16(ss, bp - 3632) + 1);
loc_523c: // 01ed:336c
    push(memoryAGet16(ss, bp - 3630));
    push(memoryAGet16(ss, bp - 3632));
    push(memoryAGet16(ss, bp - 3638));
    push(bp);
    sub_4992();
    if (memoryAGet16(ss, bp - 3632) != 0x000f)
        goto loc_5238;
    if (memoryAGet16(ss, bp - 3630) != 0x003f)
        goto loc_522c;
loc_525a: // 01ed:338a
    if ((short)memoryAGet16(ss, bp - 3638) <= (short)0xffff)
        goto loc_5271;
    push(memoryAGet16(ss, bp - 3634));
    push(memoryAGet16(ss, bp - 3636));
    push(memoryAGet16(ss, bp - 3638));
    push(bp);
    sub_4992();
loc_5271: // 01ed:33a1
    if (memoryAGet(ss, bp - 257) == 0x1b)
        goto loc_527b;
    goto loc_4d92;
loc_527b: // 01ed:33ab
    di = bp - 0xe2c;
    push(ss);
    push(di);
    di = bp - 0xf36;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x01ed);
    di = bp - 0xe2c;
    push(ss);
    push(di);
    push(0x0207);
    push(cs);
    cs = 0x0a08;
    sub_b822();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(0x0120);
    push(0x00c8);
    push(0x015f);
    push(0x00d7);
    di = bp - 0x308;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0655;
    sub_7dc5();
    assert(cs == 0x01ed);
    di = bp - 0xe2c;
    push(ss);
    push(di);
    di = bp - 0x308;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b8d5();
    assert(cs == 0x01ed);
    sp += 0x0004;
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    di = bp - 0xe2c;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0655;
    sub_6f9d();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_52fb() // 01ed:342b
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x020a;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x020a;
    di = 0x3418;
    push(cs);
    push(di);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0008);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
loc_531b: // 01ed:344b
    ax = memoryAGet16(ss, bp + 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3421;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3421;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    if (al < 0x61)
        goto loc_5368;
    if (al <= 0x7a)
        goto loc_5378;
loc_5368: // 01ed:3498
    if (al < 0x41)
        goto loc_5370;
    if (al <= 0x5a)
        goto loc_5378;
loc_5370: // 01ed:34a0
    if (al < 0x31)
        goto loc_53b8;
    if (al > 0x39)
        goto loc_53b8;
loc_5378: // 01ed:34a8
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0001);
    push(0x0001);
    push(cs);
    cs = 0x0a08;
    sub_ac52();
    assert(cs == 0x01ed);
    di = bp - 0x20a;
    push(ss);
    push(di);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = bp - 0x10a;
    push(ss);
    push(di);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abd1();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0008);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    goto loc_53f0;
loc_53b8: // 01ed:34e8
    if (al != 0x08)
        goto loc_53f0;
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0008);
    push(0x0001);
    push(cs);
    cs = 0x0a08;
    sub_ac52();
    assert(cs == 0x01ed);
    di = bp - 0x10a;
    push(ss);
    push(di);
    di = 0x3429;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0008);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
loc_53f0: // 01ed:3520
    if (memoryAGet(ss, bp - 1) == 0x0d)
        goto loc_53ff;
    if (memoryAGet(ss, bp - 1) == 0x1b)
        goto loc_53ff;
    goto loc_531b;
loc_53ff: // 01ed:352f
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_5417;
    di = bp - 0xa;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(es);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
loc_5417: // 01ed:3547
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_5423() // 01ed:3553
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
loc_542d: // 01ed:355d
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet(es, di, memoryAGet(es, di) + 1);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet(es, di) <= 0x06)
        goto loc_5443;
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet(es, di, 0x01);
loc_5443: // 01ed:3573
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    al = memoryAGet(es, di);
    ah = 0;
    dx = 0;
    di = 0x354b;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5737) != 0x00)
        goto loc_542d;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_5465() // 01ed:3595
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0202;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x0202;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    push(es);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    if (memoryAGet(ss, bp + 4) != 0x00)
        goto loc_5490;
    goto loc_550e;
loc_5490: // 01ed:35c0
    push(0x000f);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = bp - 0x100;
    push(ss);
    push(di);
    di = bp - 0x200;
    push(ss);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    di = bp - 0x200;
    push(ss);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    push(ax);
    push(0x0064);
    push(cs);
    cs = 0x0a08;
    sub_ac52();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = bp - 0x200;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(0x0006);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x0001);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x0a08;
    sub_ac52();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    goto loc_5531;
loc_550e: // 01ed:363e
    push(0x0008);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
loc_5531: // 01ed:3661
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x3592;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_5760() // 01ed:3890
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x010a;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    sp -= 0x010a;
    sub_1fb3();
    memoryASet(ds, 0x1672, 0x01);
    sub_20ae();
    memoryASet16(ss, bp - 2, 0x0001);
    ax = 0;
    memoryASet16(ds, 0x1670, ax);
    push(cs);
    cs = 0x09a6;
    sub_9c20();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_5793;
loc_5790: // 01ed:38c0
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_5793: // 01ed:38c3
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5731, 0x00);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5737, 0x00);
    di = 0x3688;
    push(cs);
    push(di);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    push(0x00ff);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) != 0x0006)
        goto loc_5790;
loc_57e3: // 01ed:3913
    push(0x0001);
    push(0x0001);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    push(0x0001);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x3691;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(0x0009);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x36c5;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_583a;
loc_5837: // 01ed:3967
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_583a: // 01ed:396a
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x36d4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    push(0x0002);
    ax = memoryAGet16(ss, bp - 4);
    si = ax;
    ax <<= 1;
    ax += si;
    ax++;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x36e4;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    push(0x0008);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_591e;
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) == 0x00)
        goto loc_591e;
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x36d4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
loc_591e: // 01ed:3a4e
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x36f0;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x36d4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x36fd;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0080;
    push(ds);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    di = 0x370f;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0680;
    push(ds);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(0x003e);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a935();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) == 0x0006)
        goto loc_59d8;
    goto loc_5837;
loc_59d8: // 01ed:3b08
    push(0x0002);
    ax = memoryAGet16(ss, bp - 2);
    si = ax;
    ax <<= 1;
    ax += si;
    ax++;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    push(0x000f);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x3717;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(0x0002);
    push(0x0016);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) != 0x00)
        goto loc_5a41;
    di = 0x371b;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5a4d;
loc_5a41: // 01ed:3b71
    di = 0x372b;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5a4d: // 01ed:3b7d
    di = 0x373b;
    push(cs);
    push(di);
    push(0x0001);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = 0x00;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_5a6c;
    ax++;
loc_5a6c: // 01ed:3b9c
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
    di = 0x3750;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    di = 0x3755;
    push(cs);
    push(di);
    push(0x0001);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    di = 0x3688;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_5ac5;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_5ac9;
loc_5ac5: // 01ed:3bf5
    al = 0x00;
    goto loc_5acb;
loc_5ac9: // 01ed:3bf9
    al = 0x01;
loc_5acb: // 01ed:3bfb
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
    di = 0x375a;
    push(cs);
    push(di);
    push(0x0002);
    push(0x0001);
    sub_5465();
    di = 0x375d;
    push(cs);
    push(di);
    push(0x0004);
    push(0x0001);
    sub_5465();
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    if ((short)memoryAGet16(ds, 0x1670) <= (short)0x0001)
        goto loc_5b3f;
    memoryASet(ss, bp - 6, 0x01);
    goto loc_5b06;
loc_5b03: // 01ed:3c33
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_5b06: // 01ed:3c36
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_5b39;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_5b39;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_5b39: // 01ed:3c69
    if (memoryAGet(ss, bp - 6) != 0x06)
        goto loc_5b03;
loc_5b3f: // 01ed:3c6f
    di = 0x3762;
    push(cs);
    push(di);
    push(0x0001);
    al = 0x00;
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x0001)
        goto loc_5b4f;
    ax++;
loc_5b4f: // 01ed:3c7f
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
    if (memoryAGet(ds, 0x1672) == 0x00)
        goto loc_5b72;
    di = 0x3767;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5b7e;
loc_5b72: // 01ed:3ca2
    di = 0x3774;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5b7e: // 01ed:3cae
    di = 0x3781;
    push(cs);
    push(di);
    push(0x0003);
    push(0x0001);
    sub_5465();
    push(0x0002);
    push(0x0017);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    al = memoryAGet(ds, 0x016c);
    ah = 0;
    dx = 0;
    di = 0x3788;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 366);
    ah = 0;
    dx = 0;
    push(dx);
    push(ax);
    push(0x0002);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(0x0003);
    push(cs);
    cs = 0x0a08;
    sub_b76f();
    assert(cs == 0x01ed);
    di = bp - 0x10a;
    push(ss);
    push(di);
    di = 0x3790;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    di = bp - 0xa;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    push(0x0001);
    push(0x0001);
    sub_5465();
    di = bp - 0x10a;
    push(ss);
    push(di);
    di = 0x37a0;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x01ed);
    al = memoryAGet(ds, 0x0d89);
    ah = 0;
    dx = 0;
    di = 0x3798;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    imul(di, ax, 0x000c);
    di += 0x0d8a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x01ed);
    push(0x0001);
    push(0x0001);
    sub_5465();
    if (memoryAGet(ds, 0x0daf) == 0x00)
        goto loc_5c39;
    di = 0x37ab;
    push(cs);
    push(di);
    push(0x0001);
    al = 0x00;
    if (memoryAGet(ds, 0x0d89) != 0x01)
        goto loc_5c29;
    ax++;
loc_5c29: // 01ed:3d59
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
    goto loc_5c58;
loc_5c39: // 01ed:3d69
    di = 0x37b9;
    push(cs);
    push(di);
    push(0x0001);
    al = 0x00;
    if (memoryAGet(ds, 0x0d89) != 0x01)
        goto loc_5c4a;
    ax++;
loc_5c4a: // 01ed:3d7a
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
loc_5c58: // 01ed:3d88
    if (memoryAGet(ds, 0x0dae) == 0x00)
        goto loc_5c6d;
    di = 0x37c7;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5c79;
loc_5c6d: // 01ed:3d9d
    di = 0x37d5;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5c79: // 01ed:3da9
    di = 0x37e3;
    push(cs);
    push(di);
    push(0x0001);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_5c9c;
    if ((short)memoryAGet16(ds, 0x1670) > (short)0x0001)
        goto loc_5ca0;
loc_5c9c: // 01ed:3dcc
    al = 0x00;
    goto loc_5ca2;
loc_5ca0: // 01ed:3dd0
    al = 0x01;
loc_5ca2: // 01ed:3dd2
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    sub_5465();
    push(0x0002);
    push(0x0018);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    if (memoryAGet(ds, 0x0d80) == 0x00)
        goto loc_5cce;
    di = 0x37ee;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5cda;
loc_5cce: // 01ed:3dfe
    di = 0x37f9;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5cda: // 01ed:3e0a
    if (memoryAGet(ds, 0x0d81) == 0x00)
        goto loc_5cef;
    di = 0x3804;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5cfb;
loc_5cef: // 01ed:3e1f
    di = 0x380c;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5cfb: // 01ed:3e2b
    if (memoryAGet(ds, 0x0d82) == 0x00)
        goto loc_5d10;
    di = 0x3814;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5d1c;
loc_5d10: // 01ed:3e40
    di = 0x3822;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5d1c: // 01ed:3e4c
    if (memoryAGet(ds, 0x0dcd) == 0x00)
        goto loc_5d31;
    di = 0x3830;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5d3d;
loc_5d31: // 01ed:3e61
    di = 0x3843;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5d3d: // 01ed:3e6d
    if (memoryAGet(ds, 0x0d83) == 0x00)
        goto loc_5d52;
    di = 0x3856;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    goto loc_5d5e;
loc_5d52: // 01ed:3e82
    di = 0x3865;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
loc_5d5e: // 01ed:3e8e
    di = 0x3874;
    push(cs);
    push(di);
    push(0x0001);
    push(0x0001);
    sub_5465();
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 5, al);
    al = memoryAGet(ss, bp - 5);
    if (al != 0x00)
        goto loc_5db1;
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 5, al);
    al = memoryAGet(ss, bp - 5);
    if (al != 0x48)
        goto loc_5d9a;
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x0001)
        goto loc_5d93;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) - 1);
    goto loc_5d98;
loc_5d93: // 01ed:3ec3
    memoryASet16(ss, bp - 2, 0x0006);
loc_5d98: // 01ed:3ec8
    goto loc_5dae;
loc_5d9a: // 01ed:3eca
    if (al != 0x50)
        goto loc_5dae;
    if ((short)memoryAGet16(ss, bp - 2) >= (short)0x0006)
        goto loc_5da9;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
    goto loc_5dae;
loc_5da9: // 01ed:3ed9
    memoryASet16(ss, bp - 2, 0x0001);
loc_5dae: // 01ed:3ede
    goto loc_63ed;
loc_5db1: // 01ed:3ee1
    if (al == 0x66)
        goto loc_5db9;
    if (al != 0x46)
        goto loc_5dd6;
loc_5db9: // 01ed:3ee9
    al = memoryAGet(ds, 0x016c);
    al++;
    ah = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0006;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x016c, al);
    goto loc_63ed;
loc_5dd6: // 01ed:3f06
    if (al == 0x69)
        goto loc_5de1;
    if (al == 0x49)
        goto loc_5de1;
    goto loc_5f2b;
loc_5de1: // 01ed:3f11
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_5df9;
    goto loc_5f28;
loc_5df9: // 01ed:3f29
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_5e27;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0006;
    idiv(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    ax++;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 6, al);
    goto loc_5e62;
loc_5e27: // 01ed:3f57
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0006;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    ax++;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 6, al);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3519, 0x00);
loc_5e62: // 01ed:3f92
    memoryASet16(ss, bp - 4, 0x0006);
loc_5e67: // 01ed:3f97
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x0000)
        goto loc_5ebb;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_5e9d;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) != 0x00)
        goto loc_5ebb;
loc_5e9d: // 01ed:3fcd
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0006;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    ax++;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 6, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
    goto loc_5e67;
loc_5ebb: // 01ed:3feb
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x0000)
        goto loc_5f28;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    if (ax != memoryAGet16(ss, bp - 2))
        goto loc_5ecf;
    memoryASet(ss, bp - 6, 0x00);
loc_5ecf: // 01ed:3fff
    cl = memoryAGet(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3519, cl);
    if (memoryAGet(ss, bp - 6) == 0x00)
        goto loc_5f28;
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_5ef4;
loc_5ef1: // 01ed:4021
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_5ef4: // 01ed:4024
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    if (ax != memoryAGet16(ss, bp - 2))
        goto loc_5f22;
    cl = memoryAGet(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3519, cl);
loc_5f22: // 01ed:4052
    if (memoryAGet16(ss, bp - 4) != 0x0006)
        goto loc_5ef1;
loc_5f28: // 01ed:4058
    goto loc_63ed;
loc_5f2b: // 01ed:405b
    if (al == 0x61)
        goto loc_5f33;
    if (al != 0x41)
        goto loc_5f8b;
loc_5f33: // 01ed:4063
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) != 0x00)
        goto loc_5f88;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di += 0x1663;
    push(ds);
    push(di);
    sub_5423();
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5737, 0x01);
    memoryASet16(ds, 0x1670, memoryAGet16(ds, 0x1670) + 1);
loc_5f88: // 01ed:40b8
    goto loc_63ed;
loc_5f8b: // 01ed:40bb
    if (al == 0x62)
        goto loc_5f93;
    if (al != 0x42)
        goto loc_5fb0;
loc_5f93: // 01ed:40c3
    al = memoryAGet(ds, 0x0d89);
    al++;
    ah = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0003;
    div(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0d89, al);
    goto loc_63ed;
loc_5fb0: // 01ed:40e0
    if (al == 0x74)
        goto loc_5fb8;
    if (al != 0x54)
        goto loc_5fd2;
loc_5fb8: // 01ed:40e8
    al = 0x00;
    if (memoryAGet(ds, 0x0dae) != 0x00)
        goto loc_5fc2;
    ax++;
loc_5fc2: // 01ed:40f2
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0dae, al);
    goto loc_63ed;
loc_5fd2: // 01ed:4102
    if (al == 0x64)
        goto loc_5fdd;
    if (al == 0x44)
        goto loc_5fdd;
    goto loc_60a1;
loc_5fdd: // 01ed:410d
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) > 0x00)
        goto loc_5ff5;
    goto loc_6087;
loc_5ff5: // 01ed:4125
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5737, 0x00);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5731, 0x00);
    memoryASet16(ds, 0x1670, memoryAGet16(ds, 0x1670) - 1);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3519, 0x00);
    memoryASet(ss, bp - 6, 0x01);
    goto loc_604d;
loc_604a: // 01ed:417a
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_604d: // 01ed:417d
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3519);
    ah = 0;
    if (ax != memoryAGet16(ss, bp - 2))
        goto loc_607f;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 3519, 0x00);
loc_607f: // 01ed:41af
    if (memoryAGet(ss, bp - 6) != 0x06)
        goto loc_604a;
    goto loc_609e;
loc_6087: // 01ed:41b7
    al = 0x00;
    if (memoryAGet(ds, 0x0d82) != 0x00)
        goto loc_6091;
    ax++;
loc_6091: // 01ed:41c1
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0d82, al);
loc_609e: // 01ed:41ce
    goto loc_63ed;
loc_60a1: // 01ed:41d1
    if (al == 0x63)
        goto loc_60a9;
    if (al != 0x43)
        goto loc_6122;
loc_60a9: // 01ed:41d9
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_611f;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5737, 0x00);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di += 0x1663;
    push(ds);
    push(di);
    sub_5423();
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    memoryASet(ds, di + 5737, 0x01);
loc_611f: // 01ed:424f
    goto loc_63ed;
loc_6122: // 01ed:4252
    if (al == 0x65)
        goto loc_612a;
    if (al != 0x45)
        goto loc_61a6;
loc_612a: // 01ed:425a
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_61a3;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    di = 0x3688;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_61a3;
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 5731);
    ah = 0;
    dx = 0;
    di = 0x36d4;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    al = memoryAGet(ds, di + 3504);
    ah = 0;
    push(ax);
    sub_4b2a();
loc_61a3: // 01ed:42d3
    goto loc_63ed;
loc_61a6: // 01ed:42d6
    if (al == 0x6e)
        goto loc_61ae;
    if (al != 0x4e)
        goto loc_61df;
loc_61ae: // 01ed:42de
    push(0x000f);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    push(0x000d);
    ax = memoryAGet16(ss, bp - 2);
    si = ax;
    ax <<= 1;
    ax += si;
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    di <<= 8;
    di += 0x0f64;
    push(ds);
    push(di);
    sub_52fb();
    goto loc_63ed;
loc_61df: // 01ed:430f
    if (al == 0x75)
        goto loc_61e7;
    if (al != 0x55)
        goto loc_6201;
loc_61e7: // 01ed:4317
    al = 0x00;
    if (memoryAGet(ds, 0x0dcd) != 0x00)
        goto loc_61f1;
    ax++;
loc_61f1: // 01ed:4321
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0dcd, al);
    goto loc_63ed;
loc_6201: // 01ed:4331
    if (al == 0x73)
        goto loc_6209;
    if (al != 0x53)
        goto loc_622a;
loc_6209: // 01ed:4339
    if (memoryAGet(ds, 0x0d89) != 0x01)
        goto loc_6227;
    al = 0x00;
    if (memoryAGet(ds, 0x0daf) != 0x00)
        goto loc_621a;
    ax++;
loc_621a: // 01ed:434a
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0daf, al);
loc_6227: // 01ed:4357
    goto loc_63ed;
loc_622a: // 01ed:435a
    if (al == 0x6d)
        goto loc_6232;
    if (al != 0x4d)
        goto loc_624c;
loc_6232: // 01ed:4362
    al = 0x00;
    if (memoryAGet(ds, 0x1672) != 0x00)
        goto loc_623c;
    ax++;
loc_623c: // 01ed:436c
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x1672, al);
    goto loc_63ed;
loc_624c: // 01ed:437c
    if (al == 0x78)
        goto loc_6254;
    if (al != 0x58)
        goto loc_626e;
loc_6254: // 01ed:4384
    al = 0x00;
    if (memoryAGet(ds, 0x0d80) != 0x00)
        goto loc_625e;
    ax++;
loc_625e: // 01ed:438e
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0d80, al);
    goto loc_63ed;
loc_626e: // 01ed:439e
    if (al == 0x67)
        goto loc_6276;
    if (al != 0x47)
        goto loc_6290;
loc_6276: // 01ed:43a6
    al = 0x00;
    if (memoryAGet(ds, 0x0d81) != 0x00)
        goto loc_6280;
    ax++;
loc_6280: // 01ed:43b0
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0d81, al);
    goto loc_63ed;
loc_6290: // 01ed:43c0
    if (al == 0x76)
        goto loc_6298;
    if (al != 0x56)
        goto loc_62b2;
loc_6298: // 01ed:43c8
    al = 0x00;
    if (memoryAGet(ds, 0x0d83) != 0x00)
        goto loc_62a2;
    ax++;
loc_62a2: // 01ed:43d2
    cbw();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3748;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0d83, al);
    goto loc_63ed;
loc_62b2: // 01ed:43e2
    if (al == 0x77)
        goto loc_62bd;
    if (al == 0x57)
        goto loc_62bd;
    goto loc_6358;
loc_62bd: // 01ed:43ed
    push(0x0046);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax++;
    dx = 0;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(0x0018);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax++;
    dx = 0;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9c73();
    assert(cs == 0x01ed);
    push(0x000f);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    ax++;
    dx = 0;
    di = 0x36dc;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9cb7();
    assert(cs == 0x01ed);
    if (memoryAGet(ds, 0x1672) == 0x00)
        goto loc_6315;
    push(0x2260);
    push(cs);
    cs = 0x0a08;
    sub_b5c9();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
loc_6315: // 01ed:4445
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x387c;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8ec();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
    push(0x000a);
    push(cs);
    cs = 0x09a6;
    sub_9cfc();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9d5b();
    assert(cs == 0x01ed);
    if (al)
        goto loc_6343;
    goto loc_62bd;
loc_6343: // 01ed:4473
    push(cs);
    cs = 0x09a6;
    sub_9d6d();
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 5, al);
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9c20();
    assert(cs == 0x01ed);
    goto loc_63ed;
loc_6358: // 01ed:4488
    if (al == 0x0d)
        goto loc_6367;
    if (al == 0x70)
        goto loc_6367;
    if (al == 0x50)
        goto loc_6367;
    goto loc_63ed;
loc_6367: // 01ed:4497
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    if ((short)memoryAGet16(ds, 0x1670) <= (short)0x0001)
        goto loc_63b5;
    memoryASet(ss, bp - 6, 0x01);
    goto loc_637c;
loc_6379: // 01ed:44a9
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_637c: // 01ed:44ac
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 5731) <= 0x00)
        goto loc_63af;
    al = memoryAGet(ss, bp - 6);
    ah = 0;
    dx = 0;
    di = 0x3680;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    di = ax;
    if (memoryAGet(ds, di + 3519) != 0x00)
        goto loc_63af;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_63af: // 01ed:44df
    if (memoryAGet(ss, bp - 6) != 0x06)
        goto loc_6379;
loc_63b5: // 01ed:44e5
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x0001)
        goto loc_63ed;
    if (memoryAGet(ds, 0x1672) == 0x00)
        goto loc_63e5;
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_63cc;
loc_63c9: // 01ed:44f9
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_63cc: // 01ed:44fc
    ax = memoryAGet16(ss, bp - 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di = 0x3888;
    push(cs);
    cs = 0x0a08;
    sub_a537();
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x09a6;
    sub_9d27();
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) != 0x1388)
        goto loc_63c9;
loc_63e5: // 01ed:4515
    push(cs);
    cs = 0x09a6;
    sub_9d54();
    assert(cs == 0x01ed);
    sub_3be3();
loc_63ed: // 01ed:451d
    if (memoryAGet(ss, bp - 5) == 0x1b)
        goto loc_63f6;
    goto loc_57e3;
loc_63f6: // 01ed:4526
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
// 01ed:4676 Terminator reached
void sub_64f6() // 01ed:4626
{
    push(cs);
    cs = 0x0a08;
    sub_a080();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x09a6;
    sub_9a60();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0655;
    sub_7708();
    assert(cs == 0x01ed);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a55f();
    assert(cs == 0x01ed);
    memoryASet(ds, 0x1672, 0x01);
    if (memoryAGet(ds, 0x1672) != 0x00)
        goto loc_6536;
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x4528;
    push(cs);
    push(di);
    push(0x0000);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a8c8();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x01ed);
loc_6536: // 01ed:4666
    push(cs);
    cs = 0x09a6;
    sub_9c20();
    assert(cs == 0x01ed);
    sub_5760();
    sp = bp;
    bp = pop();
    ax = 0;
    push(cs);
    cs = 0x0a08;
    sub_a169();
    assert(cs == 0x01ed);
    stop(/*7*/); //   Terminator reached
}
void sub_65a5() // 0655:0055
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet(ds, 0x22de) != 0x00)
        goto loc_65cd;
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x0000;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a8c8();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x0655);
    goto loc_65e9;
loc_65cd: // 0655:007d
    di = 0x244a;
    push(ds);
    push(di);
    di = 0x0034;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_a997();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a8c8();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a529();
    assert(cs == 0x0655);
loc_65e9: // 0655:0099
    ax = 0x0001;
    push(cs);
    cs = 0x0a08;
    sub_a169();
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_65f3() // 0655:00a3
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    memoryASet16(ss, bp - 2, 0x0001);
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_6607() // 0655:00b7
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x0a08;
    sub_a2bf();
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_6620() // 0655:00d0
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(es, di);
    ax |= memoryAGet16(es, di + 2);
    if (!ax)
        goto loc_6641;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    push(memoryAGet16(es, di + 2));
    push(memoryAGet16(es, di));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x0a08;
    sub_a2d4();
    assert(cs == 0x0655);
loc_6641: // 0655:00f1
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = 0;
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_6651() // 0655:0101
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(es, di);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + ax);
    ax = memoryAGet16(ss, bp + 12);
    cx = 0x0004;
    ax >>= cl;
    ax += memoryAGet16(ss, bp + 14);
    dx = ax;
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
    ax = memoryAGet16(ss, bp + 12);
    ax &= 0x000f;
    if (!ax)
        goto loc_66a0;
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(memoryAGet16(es, di));
    push(cs);
    cs = 0x0a08;
    sub_ba28();
    assert(cs == 0x0655);
    ax = memoryAGet16(ss, bp + 12);
    ax &= 0x000f;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di, memoryAGet16(es, di) - ax);
loc_66a0: // 0655:0150
    ax = memoryAGet16(ss, bp - 8);
    dx = memoryAGet16(ss, bp - 6);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    ax = memoryAGet16(ss, bp - 4);
    dx = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_66bb() // 0655:016b
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0108;
    if (memoryAGet(ds, 0x22de) == 0x00)
        goto loc_66d7;
    memoryASet16(ds, 0x22a8, 0xfff5);
    memoryASet16(ss, bp - 2, 0xfff5);
    goto loc_67a6;
loc_66d7: // 0655:0187
    memoryASet16(ds, 0x22a8, 0xfffc);
    memoryASet16(ss, bp - 2, 0xfffc);
    di = bp - 0x108;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abe3();
    assert(cs == 0x0655);
    di = 0x0168;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x0655);
    if (flags.zero)
        goto loc_6705;
    goto loc_67a6;
loc_6705: // 0655:01b5
    ax = memoryAGet16(ss, bp + 6);
    ax += 0x0080;
    dx = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, dx);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    memoryASet16(ss, bp - 12, di);
    memoryASet16(ss, bp - 10, es);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet(es, di + 6) < 0x02)
        goto loc_6731;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet(es, di + 8) <= 0x01)
        goto loc_6733;
loc_6731: // 0655:01e1
    goto loc_67a6;
loc_6733: // 0655:01e3
    ax = memoryAGet16(ds, 0x2248);
    memoryASet16(ss, bp - 14, ax);
    ax = 0;
    if ((short)ax > (short)memoryAGet16(ss, bp - 14))
        goto loc_67a6;
    memoryASet16(ss, bp - 8, ax);
    goto loc_6748;
loc_6745: // 0655:01f5
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_6748: // 0655:01f8
    ax = 0x001a;
    mul(memoryAGet16(ss, bp - 8));
    di = ax;
    di += 0x0dd2;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += 0x000a;
    push(es);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x0655);
    if (!flags.zero)
        goto loc_679e;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += 0x0004;
    push(es);
    push(di);
    sub_6651();
    cx = ax;
    bx = dx;
    ax = 0x001a;
    mul(memoryAGet16(ss, bp - 8));
    di = ax;
    memoryASet16(ds, di + 3560, cx);
    memoryASet16(ds, di + 3562, bx);
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 2, ax);
    ax = 0;
    memoryASet16(ds, 0x22a8, ax);
    goto loc_67a6;
loc_679e: // 0655:024e
    ax = memoryAGet16(ss, bp - 8);
    if (ax != memoryAGet16(ss, bp - 14))
        goto loc_6745;
loc_67a6: // 0655:0256
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_67b2() // 0655:0262
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0112;
    memoryASet16(ds, 0x22a8, 0xfff3);
    ax = memoryAGet16(ds, 0x22a8);
    memoryASet16(ss, bp - 2, ax);
    di = bp - 0x10a;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abe3();
    assert(cs == 0x0655);
    di = 0x025f;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x0655);
    if (flags.zero)
        goto loc_67e8;
    goto loc_68f2;
loc_67e8: // 0655:0298
    ax = 0;
    memoryASet16(ss, bp - 10, ax);
loc_67ed: // 0655:029d
    ax = memoryAGet16(ss, bp - 10);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    di += ax;
    if (memoryAGet(es, di) == 0x1a)
        goto loc_6807;
    if (memoryAGet16(ss, bp - 10) >= 0x0101)
        goto loc_6807;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
    goto loc_67ed;
loc_6807: // 0655:02b7
    if (memoryAGet16(ss, bp - 10) < 0x0100)
        goto loc_6811;
    goto loc_68f2;
loc_6811: // 0655:02c1
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = di;
    ax += memoryAGet16(ss, bp - 10);
    ax++;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = es;
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, dx);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    memoryASet16(ss, bp - 14, di);
    memoryASet16(ss, bp - 12, es);
    di = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    if (memoryAGet(es, di + 8) < 0x01)
        goto loc_6842;
    di = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    if (memoryAGet(es, di + 10) <= 0x01)
        goto loc_6845;
loc_6842: // 0655:02f2
    goto loc_68f2;
loc_6845: // 0655:02f5
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_684f;
loc_684c: // 0655:02fc
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_684f: // 0655:02ff
    ax = 0x000f;
    mul(memoryAGet16(ss, bp - 8));
    di = ax;
    di += 0x0eeb;
    push(ds);
    push(di);
    di = bp - 0x10e;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    di += 0x0002;
    push(es);
    push(di);
    ax = 0x0004;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_abe3();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_aba6();
    assert(cs == 0x0655);
    if (!flags.zero)
        goto loc_68e9;
    ax = 0x000f;
    mul(memoryAGet16(ss, bp - 8));
    di = ax;
    di += 0x0ee1;
    memoryASet16(ss, bp - 274, di);
    memoryASet16(ss, bp - 272, ds);
    di = memoryAGet16(ss, bp - 274);
    es = memoryAGet16(ss, bp - 274 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 274);
    es = memoryAGet16(ss, bp - 274 + 2);
    push(memoryAGet16(es, di + 8));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp - 274);
    es = memoryAGet16(ss, bp - 274 + 2);
    ax = 0;
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    di = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    di += 0x0006;
    push(es);
    push(di);
    sub_6651();
    di = memoryAGet16(ss, bp - 274);
    es = memoryAGet16(ss, bp - 274 + 2);
    memoryASet16(es, di + 4, ax);
    memoryASet16(es, di + 6, dx);
    di = memoryAGet16(ss, bp - 274);
    es = memoryAGet16(ss, bp - 274 + 2);
    ax = 0;
    memoryASet16(es, di + 8, ax);
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 2, ax);
    ax = 0;
    memoryASet16(ds, 0x22a8, ax);
    goto loc_68f2;
loc_68e9: // 0655:0399
    if (memoryAGet16(ss, bp - 8) == 0x0014)
        goto loc_68f2;
    goto loc_684c;
loc_68f2: // 0655:03a2
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_68fb() // 0655:03ab
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0055;
    dx = 0x0655;
    memoryASet16(ds, 0x22b0, ax);
    memoryASet16(ds, 0x22b2, dx);
    ax = 0x0055;
    dx = 0x0655;
    memoryASet16(ds, 0x22c2, ax);
    memoryASet16(ds, 0x22c4, dx);
    ax = 0;
    memoryASet16(ds, 0x22b4, ax);
    memoryASet16(ds, 0x22b6, ax);
    ax = 0;
    memoryASet16(ds, 0x22c6, ax);
    memoryASet16(ds, 0x22c8, ax);
    ax = 0;
    memoryASet16(ds, 0x22b8, ax);
    memoryASet16(ds, 0x22ba, ax);
    ax = 0;
    memoryASet16(ds, 0x22be, ax);
    memoryASet16(ds, 0x22c0, ax);
    ax = 0;
    memoryASet16(ds, 0x2270, ax);
    memoryASet16(ds, 0x2272, ax);
    ax = 0;
    memoryASet16(ds, 0x2274, ax);
    ax = 0;
    memoryASet16(ds, 0x228a, ax);
    memoryASet16(ds, 0x228c, ax);
    ax = 0;
    memoryASet16(ds, 0x228e, ax);
    memoryASet(ds, 0x227a, 0x00);
    memoryASet16(ds, 0x22da, 0x0001);
    memoryASet16(ds, 0x22dc, 0x0001);
    ax = 0;
    memoryASet16(ds, 0x21da, ax);
    memoryASet(ds, 0x22de, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_696f() // 0655:041f
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0302;
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    push(es);
    push(di);
    di = bp - 0x102;
    push(ss);
    push(di);
    ax = 0x00ff;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    di = bp - 0x202;
    push(ss);
    push(di);
    ax = 0x00ff;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    memoryASet(ss, bp - 1, 0x00);
    memoryASet16(ds, 0x22a8, 0xfffd);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = 0;
    memoryASet16(es, di, ax);
    di = 0x215a;
    push(ds);
    push(di);
    di = bp - 0x302;
    push(ss);
    push(di);
    di = bp - 0x102;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x0655);
    di = bp - 0x202;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x0655);
    di = 0x215a;
    push(ds);
    push(di);
    ax = 0x0001;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_b819();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x0655);
    if (!ax)
        goto loc_6a21;
    if (memoryAGet(ss, bp - 258) != 0x00)
        goto loc_69f8;
    goto loc_6a55;
    //   gap of 2 bytes
loc_69f8: // 0655:04a8
    di = 0x215a;
    push(ds);
    push(di);
    di = bp - 0x202;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b7eb();
    assert(cs == 0x0655);
    di = 0x215a;
    push(ds);
    push(di);
    ax = 0x0001;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_b819();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x0655);
    if (!ax)
        goto loc_6a21;
    goto loc_6a55;
loc_6a21: // 0655:04d1
    ax = 0;
    memoryASet16(ds, 0x22a8, ax);
    di = 0x215a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b9b3();
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, di, ax);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, di) <= 0xffff)
        goto loc_6a51;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x22a8, ax);
    di = 0x215a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x0655);
    goto loc_6a55;
loc_6a51: // 0655:0501
    memoryASet(ss, bp - 1, 0x01);
loc_6a55: // 0655:0505
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 14;
}
void sub_6a63() // 0655:0513
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x020e;
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(es);
    push(di);
    di = bp - 0x102;
    push(ss);
    push(di);
    ax = 0x00ff;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    memoryASet(ss, bp - 1, 0x00);
    di = bp - 0x20e;
    push(ss);
    push(di);
    ax = 0x001a;
    mul(memoryAGet16(ss, bp + 8));
    di = ax;
    di += 0x0dd2;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x0655);
    di = 0x050e;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x0655);
    di = 0x21e6;
    push(ds);
    push(di);
    ax = 0x000c;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    ax = 0x001a;
    mul(memoryAGet16(ss, bp + 8));
    di = ax;
    ax = memoryAGet16(ds, di + 3560);
    ax |= memoryAGet16(ds, di + 3562);
    if (!ax)
        goto loc_6af0;
    ax = 0x001a;
    mul(memoryAGet16(ss, bp + 8));
    di = ax;
    ax = memoryAGet16(ds, di + 3560);
    dx = memoryAGet16(ds, di + 3562);
    memoryASet16(ds, 0x22c2, ax);
    memoryASet16(ds, 0x22c4, dx);
    ax = 0;
    memoryASet16(ds, 0x22b8, ax);
    memoryASet16(ds, 0x22ba, ax);
    ax = 0;
    memoryASet16(ds, 0x22bc, ax);
    memoryASet(ss, bp - 1, 0x01);
    goto loc_6bcd;
loc_6af0: // 0655:05a0
    di = bp - 0x102;
    push(ss);
    push(di);
    di = 0x21e6;
    push(ds);
    push(di);
    di = 0x22bc;
    push(ds);
    push(di);
    ax = 0xfffc;
    push(ax);
    sub_696f();
    if (al)
        goto loc_6b0e;
    goto loc_6bcd;
loc_6b0e: // 0655:05be
    ax = memoryAGet16(ds, 0x1044);
    dx = memoryAGet16(ds, 0x1046);
    memoryASet16(ds, 0x224c, ax);
    memoryASet16(ds, 0x224e, dx);
    ax = 0x00a3;
    dx = 0x0655;
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    di = 0x22b8;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x22bc));
    push(cs);
    cs = memoryAGet16(ds, 0x2152 + 2);
    callIndirect(memoryAGet16(ds, 0x2152 + 2), memoryAGet16(ds, 0x2152));
    assert(cs == 0x0655);
    ax = memoryAGet16(ds, 0x224c);
    dx = memoryAGet16(ds, 0x224e);
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    ax = memoryAGet16(ds, 0x22b8);
    ax |= memoryAGet16(ds, 0x22ba);
    if (ax)
        goto loc_6b55;
    memoryASet16(ds, 0x22a8, 0xfffb);
    goto loc_6bcd;
loc_6b55: // 0655:0605
    di = 0x215a;
    push(ds);
    push(di);
    di = memoryAGet16(ds, 0x22b8);
    es = memoryAGet16(ds, 0x22b8 + 2);
    push(es);
    push(di);
    push(memoryAGet16(ds, 0x22bc));
    di = bp - 0x10a;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b904();
    assert(cs == 0x0655);
    di = 0x215a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x0655);
    if (ax)
        goto loc_6b9d;
    ax = memoryAGet16(ss, bp - 266);
    if (ax != memoryAGet16(ds, 0x22bc))
        goto loc_6b9d;
    push(memoryAGet16(ds, 0x22ba));
    push(memoryAGet16(ds, 0x22b8));
    push(cs);
    sub_66bb();
    if (ax == memoryAGet16(ss, bp + 8))
        goto loc_6bb2;
loc_6b9d: // 0655:064d
    memoryASet16(ds, 0x22a8, 0xfffc);
    di = 0x22b8;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x22bc));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    goto loc_6bcd;
loc_6bb2: // 0655:0662
    ax = 0x001a;
    mul(memoryAGet16(ss, bp + 8));
    di = ax;
    ax = memoryAGet16(ds, di + 3560);
    dx = memoryAGet16(ds, di + 3562);
    memoryASet16(ds, 0x22c2, ax);
    memoryASet16(ds, 0x22c4, dx);
    memoryASet(ss, bp - 1, 0x01);
loc_6bcd: // 0655:067d
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_6bd6() // 0655:0686
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryAGet(ds, 0x22de) != 0x00)
        goto loc_6be7;
    push(cs);
    sub_65a5();
loc_6be7: // 0655:0697
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x2252));
    push(memoryAGet16(ds, 0x2254));
    al = 0x01;
    push(ax);
    push(cs);
    sub_7068();
    di = 0x230a;
    push(ds);
    push(di);
    push(cs);
    sub_739f();
    di = 0x230a;
    push(ds);
    push(di);
    push(cs);
    sub_72f7();
    push(cs);
    sub_7bb4();
    if (ax == 0x0001)
        goto loc_6c1e;
    ax = 0;
    push(ax);
    push(cs);
    sub_72c2();
loc_6c1e: // 0655:06ce
    memoryASet(ds, 0x22d0, 0x00);
    push(cs);
    sub_7ba4();
    push(ax);
    push(cs);
    sub_7b8c();
    di = bp - 0x8;
    push(ss);
    push(di);
    ax = 0x0008;
    push(ax);
    al = 0xff;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_ba4b();
    assert(cs == 0x0655);
    di = bp - 0x8;
    push(ss);
    push(di);
    push(cs);
    sub_7ba4();
    push(ax);
    push(cs);
    sub_71f1();
    ax = 0x0001;
    push(ax);
    push(cs);
    sub_7ba4();
    push(ax);
    push(cs);
    sub_71c6();
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(cs);
    sub_7145();
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(cs);
    sub_74bb();
    ax = 0;
    push(ax);
    ax = 0x0002;
    push(ax);
    push(cs);
    sub_7479();
    ax = 0;
    push(ax);
    push(cs);
    sub_78a8();
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    sub_70fd();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_6c96() // 0655:0746
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0208;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    ax = 0x00ff;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    ax = 0x1a7d;
    dx = 0x0655;
    memoryASet16(ds, 0x22b0, ax);
    memoryASet16(ds, 0x22b2, dx);
    push(memoryAGet16(ds, 0x22b2));
    push(memoryAGet16(ds, 0x22b0));
    di = memoryAGet16(ds, 0x22b0);
    es = memoryAGet16(ds, 0x22b0 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ds, 0x22b0);
    es = memoryAGet16(ds, 0x22b0 + 2);
    di += 0x0002;
    push(es);
    push(di);
    sub_6651();
    memoryASet16(ds, 0x22b0, ax);
    memoryASet16(ds, 0x22b2, dx);
    memoryASet(ss, bp - 263, 0x00);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    if (memoryAGet16(es, di) == 0x0000)
        goto loc_6cf1;
    goto loc_6d6e;
loc_6cf1: // 0655:07a1
    ax = 0;
    memoryASet16(ss, bp - 260, ax);
    memoryASet16(ss, bp - 262, 0xffff);
loc_6cfd: // 0655:07ad
    ax = memoryAGet16(ss, bp - 260);
    if ((short)ax >= (short)memoryAGet16(ds, 0x2248))
        goto loc_6d6e;
    if ((short)memoryAGet16(ss, bp - 262) >= (short)0x0000)
        goto loc_6d6e;
    ax = 0x001a;
    mul(memoryAGet16(ss, bp - 260));
    di = ax;
    ax = memoryAGet16(ds, di + 3556);
    ax |= memoryAGet16(ds, di + 3558);
    if (!ax)
        goto loc_6d68;
    ax = 0x001a;
    mul(memoryAGet16(ss, bp - 260));
    di = ax;
    ax = memoryAGet16(ds, di + 3556);
    dx = memoryAGet16(ds, di + 3558);
    memoryASet16(ds, 0x2326, ax);
    memoryASet16(ds, 0x2328, dx);
    push(cs);
    cs = memoryAGet16(ds, 0x2326 + 2);
    callIndirect(memoryAGet16(ds, 0x2326 + 2), memoryAGet16(ds, 0x2326));
    assert(cs == 0x0655);
    memoryASet16(ss, bp - 262, ax);
    if ((short)memoryAGet16(ss, bp - 262) < (short)0x0000)
        goto loc_6d68;
    ax = memoryAGet16(ss, bp - 260);
    memoryASet16(ds, 0x22a4, ax);
    ax = memoryAGet16(ss, bp - 260);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, di, ax);
    ax = memoryAGet16(ss, bp - 262);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, di, ax);
    memoryASet(ss, bp - 263, 0x01);
loc_6d68: // 0655:0818
    memoryASet16(ss, bp - 260, memoryAGet16(ss, bp - 260) + 1);
    goto loc_6cfd;
loc_6d6e: // 0655:081e
    if (memoryAGet(ss, bp - 263) != 0x00)
        goto loc_6d8a;
    di = 0x22a4;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    push(cs);
    sub_7948();
    goto loc_6db3;
loc_6d8a: // 0655:083a
    ax = memoryAGet16(ds, 0x22a4);
    memoryASet16(ss, bp - 260, ax);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    ax = memoryAGet16(es, di);
    ax += 0x0080;
    memoryASet16(ss, bp - 262, ax);
    di = bp - 0x104;
    push(ss);
    push(di);
    di = bp - 0x106;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    push(cs);
    sub_7948();
loc_6db3: // 0655:0863
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    if ((short)memoryAGet16(es, di) >= (short)0x0000)
        goto loc_6dd0;
    memoryASet16(ds, 0x22a8, 0xfffe);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, di, 0xfffe);
    sub_68fb();
    goto loc_6f6a;
loc_6dd0: // 0655:0880
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    ax = memoryAGet16(es, di);
    memoryASet16(ds, 0x22a6, ax);
    di = bp - 0x100;
    push(ss);
    push(di);
    di = 0x21f4;
    push(ds);
    push(di);
    ax = 0x0050;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    if (memoryAGet(ds, 0x21f4) == 0x00)
        goto loc_6e3a;
    al = memoryAGet(ds, 0x21f4);
    ah = 0;
    di = ax;
    al = memoryAGet(ds, di + 8692);
    memoryASet(ss, bp - 257, al);
    if (memoryAGet(ss, bp - 257) == 0x3a)
        goto loc_6e3a;
    if (memoryAGet(ss, bp - 257) == 0x5c)
        goto loc_6e3a;
    di = bp - 0x208;
    push(ss);
    push(di);
    di = bp - 0x100;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x0655);
    di = 0x0744;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x0655);
    di = 0x21f4;
    push(ds);
    push(di);
    ax = 0x0050;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
loc_6e3a: // 0655:08ea
    push(memoryAGet16(ds, 0x22a4));
    di = 0x21f4;
    push(ds);
    push(di);
    sub_6a63();
    if (al)
        goto loc_6e59;
    ax = memoryAGet16(ds, 0x22a8);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, di, ax);
    sub_68fb();
    goto loc_6f6a;
loc_6e59: // 0655:0909
    di = 0x2264;
    push(ds);
    push(di);
    ax = 0x003f;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_ba4b();
    assert(cs == 0x0655);
    ax = memoryAGet16(ds, 0x1044);
    dx = memoryAGet16(ds, 0x1046);
    memoryASet16(ds, 0x224c, ax);
    memoryASet16(ds, 0x224e, dx);
    ax = 0x00a3;
    dx = 0x0655;
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    di = 0x2270;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x2246));
    push(cs);
    cs = memoryAGet16(ds, 0x2152 + 2);
    callIndirect(memoryAGet16(ds, 0x2152 + 2), memoryAGet16(ds, 0x2152));
    assert(cs == 0x0655);
    ax = memoryAGet16(ds, 0x224c);
    dx = memoryAGet16(ds, 0x224e);
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    ax = memoryAGet16(ds, 0x2270);
    ax |= memoryAGet16(ds, 0x2272);
    if (ax)
        goto loc_6eca;
    memoryASet16(ds, 0x22a8, 0xfffb);
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, di, 0xfffb);
    di = 0x22b8;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x22bc));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    sub_68fb();
    goto loc_6f6a;
loc_6eca: // 0655:097a
    memoryASet(ds, 0x2265, 0x00);
    memoryASet(ds, 0x227a, 0x00);
    ax = memoryAGet16(ds, 0x2270);
    dx = memoryAGet16(ds, 0x2272);
    memoryASet16(ds, 0x22be, ax);
    memoryASet16(ds, 0x22c0, dx);
    ax = memoryAGet16(ds, 0x2246);
    memoryASet16(ds, 0x2274, ax);
    ax = memoryAGet16(ds, 0x2270);
    dx = memoryAGet16(ds, 0x2272);
    memoryASet16(ds, 0x228a, ax);
    memoryASet16(ds, 0x228c, dx);
    ax = memoryAGet16(ds, 0x2246);
    memoryASet16(ds, 0x228e, ax);
    ax = 0x22a8;
    dx = ds;
    memoryASet16(ds, 0x227e, ax);
    memoryASet16(ds, 0x2280, dx);
    di = 0x2264;
    push(ds);
    push(di);
    push(cs);
    sub_77af();
    ax = memoryAGet16(ds, 0x22ca);
    dx = memoryAGet16(ds, 0x22cc);
    di = ax;
    es = dx;
    push(es);
    push(di);
    di = 0x2250;
    push(ds);
    push(di);
    ax = 0x0013;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_ba28();
    assert(cs == 0x0655);
    di = 0x2264;
    push(ds);
    push(di);
    push(cs);
    sub_7a00();
    if (memoryAGet(ds, 0x2250) == 0x00)
        goto loc_6f49;
    al = memoryAGet(ds, 0x2250);
    ah = 0;
    memoryASet16(ds, 0x22a8, ax);
    sub_68fb();
    goto loc_6f6a;
loc_6f49: // 0655:09f9
    push(cs);
    sub_7bed();
    memoryASet16(ds, 0x22d8, ax);
    ax = memoryAGet16(ds, 0x225e);
    memoryASet16(ds, 0x22da, ax);
    memoryASet16(ds, 0x22dc, 0x2710);
    memoryASet(ds, 0x22de, 0x01);
    push(cs);
    sub_6bd6();
    ax = 0;
    memoryASet16(ds, 0x22a8, ax);
loc_6f6a: // 0655:0a1a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_6f70() // 0655:0a20
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    sub_783d();
    ax = memoryAGet16(ds, 0x22b4);
    ax |= memoryAGet16(ds, 0x22b6);
    if (ax)
        goto loc_6f9b;
    ax = memoryAGet16(ds, 0x22b0);
    dx = memoryAGet16(ds, 0x22b2);
    memoryASet16(ds, 0x22b4, ax);
    memoryASet16(ds, 0x22b6, dx);
    ax = 0x0055;
    dx = 0x0655;
    memoryASet16(ds, 0x22b0, ax);
    memoryASet16(ds, 0x22b2, dx);
loc_6f9b: // 0655:0a4b
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_6f9d() // 0655:0a4d
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet(ds, 0x22de) != 0x00)
        goto loc_6fb3;
    memoryASet16(ds, 0x22a8, 0xffff);
    goto loc_7064;
loc_6fb3: // 0655:0a63
    push(cs);
    sub_6f70();
    di = 0x22be;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x2246));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    ax = memoryAGet16(ds, 0x22b8);
    ax |= memoryAGet16(ds, 0x22ba);
    if (!ax)
        goto loc_6fe0;
    ax = 0x001a;
    mul(memoryAGet16(ds, 0x22a4));
    di = ax;
    ax = 0;
    memoryASet16(ds, di + 3560, ax);
    memoryASet16(ds, di + 3562, ax);
loc_6fe0: // 0655:0a90
    di = 0x22b8;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x22bc));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    sub_68fb();
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_6ffa;
loc_6ff7: // 0655:0aa7
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_6ffa: // 0655:0aaa
    ax = 0x000f;
    mul(memoryAGet16(ss, bp - 2));
    di = ax;
    di += 0x0ee1;
    memoryASet16(ss, bp - 6, di);
    memoryASet16(ss, bp - 4, ds);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    if (memoryAGet(es, di + 10) == 0x00)
        goto loc_705e;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    if (memoryAGet16(es, di + 8) == 0x0000)
        goto loc_705e;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = memoryAGet16(es, di);
    ax |= memoryAGet16(es, di + 2);
    if (!ax)
        goto loc_705e;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, di + 8));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = 0;
    memoryASet16(es, di + 8, ax);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = 0;
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = 0;
    memoryASet16(es, di + 4, ax);
    memoryASet16(es, di + 6, ax);
loc_705e: // 0655:0b0e
    if (memoryAGet16(ss, bp - 2) != 0x0014)
        goto loc_6ff7;
loc_7064: // 0655:0b14
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7068() // 0655:0b18
{
    push(0x7777);
    push(bp);
    bp = sp;
    if ((short)memoryAGet16(ss, bp + 14) < (short)0x0000)
        goto loc_70b5;
    if ((short)memoryAGet16(ss, bp + 12) < (short)0x0000)
        goto loc_70b5;
    ax = memoryAGet16(ds, 0x2252);
    dx = 0;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    if ((short)dx > (short)bx)
        goto loc_70b5;
    if ((short)dx < (short)bx)
        goto loc_708e;
    if (ax > cx)
        goto loc_70b5;
loc_708e: // 0655:0b3e
    ax = memoryAGet16(ds, 0x2254);
    dx = 0;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    if ((short)dx > (short)bx)
        goto loc_70b5;
    if ((short)dx < (short)bx)
        goto loc_70a5;
    if (ax > cx)
        goto loc_70b5;
loc_70a5: // 0655:0b55
    ax = memoryAGet16(ss, bp + 10);
    if ((short)ax < (short)memoryAGet16(ss, bp + 14))
        goto loc_70b5;
    ax = memoryAGet16(ss, bp + 8);
    if ((short)ax >= (short)memoryAGet16(ss, bp + 12))
        goto loc_70bd;
loc_70b5: // 0655:0b65
    memoryASet16(ds, 0x22a8, 0xfff5);
    goto loc_70f9;
loc_70bd: // 0655:0b6d
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ds, 0x22e2, ax);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(ds, 0x22e4, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x22e6, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x22e8, ax);
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x22ea, al);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    push(cs);
    sub_77ef();
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    sub_70fd();
loc_70f9: // 0655:0ba9
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_70fd() // 0655:0bad
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7a28();
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x22d4, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x22d6, ax);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_711a() // 0655:0bca
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x22d4);
    ax += memoryAGet16(ss, bp + 8);
    push(ax);
    ax = memoryAGet16(ds, 0x22d6);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(cs);
    sub_7a3c();
    ax = memoryAGet16(ds, 0x22d4);
    ax += memoryAGet16(ss, bp + 8);
    push(ax);
    ax = memoryAGet16(ds, 0x22d6);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(cs);
    sub_70fd();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7145() // 0655:0bf5
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 10) > 0x0004)
        goto loc_7154;
    if (memoryAGet16(ss, bp + 6) <= 0x0003)
        goto loc_715c;
loc_7154: // 0655:0c04
    memoryASet16(ds, 0x22a8, 0xfff5);
    goto loc_717b;
loc_715c: // 0655:0c0c
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x22ec, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x22ee, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x22f0, ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7c59();
loc_717b: // 0655:0c2b
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_717f() // 0655:0c2f
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_7a50();
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7a50();
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7a50();
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_7a50();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_71c6() // 0655:0c76
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 8) <= 0x000b)
        goto loc_71d7;
    memoryASet16(ds, 0x22a8, 0xfff5);
    goto loc_71ed;
loc_71d7: // 0655:0c87
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x22f2, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x22f4, ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7cb5();
loc_71ed: // 0655:0c9d
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_71f1() // 0655:0ca1
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    push(es);
    push(di);
    di = bp - 0x8;
    push(ss);
    push(di);
    ax = 0x0008;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_a9d5();
    assert(cs == 0x0655);
    push(cs);
    sub_7ba4();
    if (ax >= memoryAGet16(ss, bp + 6))
        goto loc_721b;
    memoryASet16(ds, 0x22a8, 0xfff5);
    goto loc_7246;
loc_721b: // 0655:0ccb
    memoryASet16(ds, 0x22f2, 0x000c);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x22f4, ax);
    di = bp - 0x8;
    push(ss);
    push(di);
    di = 0x22f6;
    push(ds);
    push(di);
    ax = 0x0008;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_a9d5();
    assert(cs == 0x0655);
    di = bp - 0x8;
    push(ss);
    push(di);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_78c2();
loc_7246: // 0655:0cf6
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_724c() // 0655:0cfc
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    ax = memoryAGet16(ds, 0x22dc);
    dx = 0;
    push(dx);
    push(ax);
    ax = memoryAGet16(ds, 0x22da);
    dx = 0;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 4);
    dx = 0;
    push(cs);
    cs = 0x0a08;
    sub_a9f1();
    assert(cs == 0x0655);
    cx = pop();
    bx = pop();
    push(cs);
    cs = 0x0a08;
    sub_aa0c();
    assert(cs == 0x0655);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_727f() // 0655:0d2f
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    ax = 0;
    push(ax);
    ax = 0x0168;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 6));
    sub_724c();
    push(ax);
    push(cs);
    sub_7aea();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_72a1() // 0655:0d51
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 6));
    sub_724c();
    push(ax);
    push(cs);
    sub_7b45();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_72c2() // 0655:0d72
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 6) <= 0x000f)
        goto loc_72cd;
    goto loc_72f3;
loc_72cd: // 0655:0d7d
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x22d0, al);
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_72e0;
    memoryASet(ds, 0x230b, 0x00);
    goto loc_72ea;
loc_72e0: // 0655:0d90
    di = memoryAGet16(ss, bp + 6);
    al = memoryAGet(ds, di + 8971);
    memoryASet(ds, 0x230b, al);
loc_72ea: // 0655:0d9a
    al = memoryAGet(ds, 0x230b);
    cbw();
    push(ax);
    push(cs);
    sub_7bfe();
loc_72f3: // 0655:0da3
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_72f7() // 0655:0da7
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x001c;
    if (memoryAGet(ds, 0x22de) != 0x00)
        goto loc_7307;
    goto loc_7399;
loc_7307: // 0655:0db7
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ss, bp - 26, di);
    memoryASet16(ss, bp - 24, es);
    di = memoryAGet16(ss, bp - 26);
    es = memoryAGet16(ss, bp - 26 + 2);
    if (memoryAGet(es, di) <= 0x10)
        goto loc_731f;
    memoryASet(ss, bp - 3, 0x10);
    goto loc_7328;
loc_731f: // 0655:0dcf
    di = memoryAGet16(ss, bp - 26);
    es = memoryAGet16(ss, bp - 26 + 2);
    al = memoryAGet(es, di);
    memoryASet(ss, bp - 3, al);
loc_7328: // 0655:0dd8
    al = memoryAGet(ss, bp - 3);
    ah = 0;
    ax--;
    memoryASet16(ss, bp - 28, ax);
    ax = 0;
    if ((short)ax > (short)memoryAGet16(ss, bp - 28))
        goto loc_736a;
    memoryASet16(ss, bp - 2, ax);
    goto loc_7340;
loc_733d: // 0655:0ded
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_7340: // 0655:0df0
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp - 26);
    es = memoryAGet16(ss, bp - 26 + 2);
    di += ax;
    if ((char)memoryAGet(es, di + 1) <= (char)0xff)
        goto loc_7362;
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp - 26);
    es = memoryAGet16(ss, bp - 26 + 2);
    di += ax;
    al = memoryAGet(es, di + 1);
    di = memoryAGet16(ss, bp - 2);
    memoryASet(ds, di + 8971, al);
loc_7362: // 0655:0e12
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 28))
        goto loc_733d;
loc_736a: // 0655:0e1a
    di = memoryAGet16(ss, bp - 26);
    es = memoryAGet16(ss, bp - 26 + 2);
    if (memoryAGet(es, di + 1) == 0xff)
        goto loc_7379;
    memoryASet(ds, 0x22d0, 0x00);
loc_7379: // 0655:0e29
    di = 0x230a;
    push(ds);
    push(di);
    di = bp - 0x16;
    push(ss);
    push(di);
    ax = 0x0011;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_ba28();
    assert(cs == 0x0655);
    memoryASet(ss, bp - 5, 0x00);
    di = bp - 0x16;
    push(ss);
    push(di);
    push(cs);
    sub_7c47();
loc_7399: // 0655:0e49
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_739f() // 0655:0e4f
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    sub_7bc4();
    di = ax;
    es = dx;
    push(es);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    ax = 0x0011;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_a9d5();
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_73be() // 0655:0e6e
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(es, di + 2);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp + 12);
    ax += memoryAGet16(ds, 0x22e4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ds, 0x2254);
    dx = 0;
    flags.carry = ax < cx;
    ax -= cx;
    dx -= bx + flags.carry;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di + 2, ax);
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(es, di + 2);
    if (ax <= memoryAGet16(ss, bp - 2))
        goto loc_7400;
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di + 2, ax);
loc_7400: // 0655:0eb0
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(es, di);
    dx = 0;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 14);
    ax += memoryAGet16(ds, 0x22e2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    dx += bx + flags.carry;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ds, 0x2252);
    dx = 0;
    if ((short)dx < (short)bx)
        goto loc_744b;
    if ((short)dx > (short)bx)
        goto loc_742b;
    if (ax < cx)
        goto loc_744b;
loc_742b: // 0655:0edb
    ax = memoryAGet16(ss, bp + 14);
    ax += memoryAGet16(ds, 0x22e2);
    if ((short)ax < 0)
        goto loc_744b;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, di + 2) < 0x0000)
        goto loc_744b;
    ax = memoryAGet16(ss, bp + 12);
    ax += memoryAGet16(ds, 0x22e4);
    if ((short)ax >= 0)
        goto loc_7457;
loc_744b: // 0655:0efb
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di + 2, ax);
    goto loc_7473;
loc_7457: // 0655:0f07
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    push(es);
    push(di);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7df9();
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di + 2, ax);
loc_7473: // 0655:0f23
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_7479() // 0655:0f29
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 8) < 0x0000)
        goto loc_7494;
    if (memoryAGet16(ss, bp + 8) > 0x0002)
        goto loc_7494;
    if (memoryAGet16(ss, bp + 6) < 0x0000)
        goto loc_7494;
    if (memoryAGet16(ss, bp + 6) <= 0x0002)
        goto loc_749c;
loc_7494: // 0655:0f44
    memoryASet16(ds, 0x22a8, 0xfff5);
    goto loc_74b2;
loc_749c: // 0655:0f4c
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x2322, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x2324, ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_78ec();
loc_74b2: // 0655:0f62
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_74bb() // 0655:0f6b
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x010a;
    if (memoryAGet16(ss, bp + 10) > 0x0014)
        goto loc_74e3;
    if (memoryAGet16(ss, bp + 10) < 0x0000)
        goto loc_74e3;
    if (memoryAGet16(ss, bp + 10) == 0x0000)
        goto loc_74f6;
    ax = 0x000f;
    mul(memoryAGet16(ss, bp + 10));
    di = ax;
    if (memoryAGet(ds, di + 3819) != 0x00)
        goto loc_74f6;
loc_74e3: // 0655:0f93
    memoryASet16(ds, 0x22a8, 0xfff2);
    ax = 0;
    memoryASet16(ss, bp + 10, ax);
    memoryASet16(ss, bp + 6, 0x0001);
    goto loc_76e3;
loc_74f6: // 0655:0fa6
    if (memoryAGet16(ss, bp + 10) != 0x0000)
        goto loc_74ff;
    goto loc_76e3;
loc_74ff: // 0655:0faf
    ax = memoryAGet16(ss, bp + 10);
    if (ax != memoryAGet16(ds, 0x231c))
        goto loc_750b;
    goto loc_76e3;
loc_750b: // 0655:0fbb
    ax = memoryAGet16(ss, bp + 10);
    if (ax != memoryAGet16(ds, 0x21da))
        goto loc_7517;
    goto loc_76cc;
loc_7517: // 0655:0fc7
    if (memoryAGet16(ds, 0x21da) == 0x0000)
        goto loc_756d;
    ax = 0x000f;
    mul(memoryAGet16(ds, 0x21da));
    di = ax;
    di += 0x0ee1;
    memoryASet16(ss, bp - 10, di);
    memoryASet16(ss, bp - 8, ds);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    if (memoryAGet16(es, di + 8) == 0x0000)
        goto loc_756d;
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    push(memoryAGet16(es, di + 8));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    ax = 0;
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    ax = 0;
    memoryASet16(es, di + 4, ax);
    memoryASet16(es, di + 6, ax);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    ax = 0;
    memoryASet16(es, di + 8, ax);
loc_756d: // 0655:101d
    ax = 0x000f;
    mul(memoryAGet16(ss, bp + 10));
    di = ax;
    di += 0x0ee1;
    memoryASet16(ss, bp - 10, di);
    memoryASet16(ss, bp - 8, ds);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    ax = memoryAGet16(es, di + 4);
    ax |= memoryAGet16(es, di + 6);
    if (!ax)
        goto loc_758f;
    goto loc_76c6;
loc_758f: // 0655:103f
    di = bp - 0x10a;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    di += 0x000a;
    push(es);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_aaa1();
    assert(cs == 0x0655);
    di = 0x0f66;
    push(cs);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_ab2e();
    assert(cs == 0x0655);
    di = 0x21dc;
    push(ds);
    push(di);
    ax = 0x0008;
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_aabb();
    assert(cs == 0x0655);
    di = 0x21f4;
    push(ds);
    push(di);
    di = 0x21dc;
    push(ds);
    push(di);
    di = bp - 0x2;
    push(ss);
    push(di);
    ax = 0xfff3;
    push(ax);
    sub_696f();
    if (al)
        goto loc_75ef;
    if (memoryAGet16(ds, 0x22a8) != 0xfffd)
        goto loc_75e2;
    memoryASet16(ds, 0x22a8, 0xfff8);
loc_75e2: // 0655:1092
    ax = 0;
    memoryASet16(ss, bp + 10, ax);
    memoryASet16(ss, bp + 6, 0x0001);
    goto loc_76e3;
loc_75ef: // 0655:109f
    ax = memoryAGet16(ds, 0x1044);
    dx = memoryAGet16(ds, 0x1046);
    memoryASet16(ds, 0x224c, ax);
    memoryASet16(ds, 0x224e, dx);
    ax = 0x00a3;
    dx = 0x0655;
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    di = bp - 0x6;
    push(ss);
    push(di);
    push(memoryAGet16(ss, bp - 2));
    push(cs);
    cs = memoryAGet16(ds, 0x2152 + 2);
    callIndirect(memoryAGet16(ds, 0x2152 + 2), memoryAGet16(ds, 0x2152));
    assert(cs == 0x0655);
    ax = memoryAGet16(ds, 0x224c);
    dx = memoryAGet16(ds, 0x224e);
    memoryASet16(ds, 0x1044, ax);
    memoryASet16(ds, 0x1046, dx);
    ax = memoryAGet16(ss, bp - 6);
    ax |= memoryAGet16(ss, bp - 4);
    if (ax)
        goto loc_7649;
    di = 0x215a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x0655);
    memoryASet16(ds, 0x22a8, 0xfff7);
    ax = 0;
    memoryASet16(ss, bp + 10, ax);
    memoryASet16(ss, bp + 6, 0x0001);
    goto loc_76e3;
loc_7649: // 0655:10f9
    di = 0x215a;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(es);
    push(di);
    push(memoryAGet16(ss, bp - 2));
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x0a08;
    sub_b904();
    assert(cs == 0x0655);
    di = 0x215a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_b89a();
    assert(cs == 0x0655);
    push(cs);
    cs = 0x0a08;
    sub_a522();
    assert(cs == 0x0655);
    if (ax)
        goto loc_768e;
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    sub_67b2();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 10);
    dx = 0;
    if (dx != bx)
        goto loc_768e;
    if (ax == cx)
        goto loc_76ac;
loc_768e: // 0655:113e
    memoryASet16(ds, 0x22a8, 0xfff3);
    di = bp - 0x6;
    push(ss);
    push(di);
    push(memoryAGet16(ss, bp - 2));
    push(cs);
    cs = memoryAGet16(ds, 0x2156 + 2);
    callIndirect(memoryAGet16(ds, 0x2156 + 2), memoryAGet16(ds, 0x2156));
    assert(cs == 0x0655);
    ax = 0;
    memoryASet16(ss, bp + 10, ax);
    memoryASet16(ss, bp + 6, 0x0001);
    goto loc_76e3;
loc_76ac: // 0655:115c
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    memoryASet16(es, di + 8, ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
loc_76c6: // 0655:1176
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x21da, ax);
loc_76cc: // 0655:117c
    ax = 0x000f;
    mul(memoryAGet16(ss, bp + 10));
    di = ax;
    ax = memoryAGet16(ds, di + 3813);
    dx = memoryAGet16(ds, di + 3815);
    memoryASet16(ds, 0x22c6, ax);
    memoryASet16(ds, 0x22c8, dx);
loc_76e3: // 0655:1193
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x231c, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x231e, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x2320, ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_7d00();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_7708() // 0655:11b8
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x22a8, ax);
    memoryASet16(ds, 0x2246, 0x1000);
    push(cs);
    sub_79de();
    sub_68fb();
    ax = 0x00b7;
    dx = 0x0655;
    memoryASet16(ds, 0x2152, ax);
    memoryASet16(ds, 0x2154, dx);
    ax = 0x00d0;
    dx = 0x0655;
    memoryASet16(ds, 0x2156, ax);
    memoryASet16(ds, 0x2158, dx);
    memoryASet(ds, 0x21dc, 0x00);
    memoryASet(ds, 0x21e6, 0x00);
    memoryASet16(ds, 0x2248, 0x0006);
    memoryASet16(ds, 0x224a, 0x000a);
    memoryASet16(ds, 0x22e0, 0x0001);
    memoryASet16(ds, 0x22da, 0x0001);
    memoryASet16(ds, 0x22dc, 0x0001);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7761() // 0655:1211
{
    //push(es);
    //push(bx);
    //assert(al == 1);
    assert(es == 0x11f2 && bx == 0xc4);
    al = 1;
    memoryASet16(cs, 0x258, al);
//    cx = memoryAGet16(ds, 0x272);
//    callIndirect(es, bx);  //TODO CICO!!
    cs = pop();
}
void sub_7764() // 0655:1214
{
    if (memoryAGet(ds, 0x2333) != 0xff)
        return;
    if (memoryAGet(ds, 0x22e0) != 0xa5)
        goto loc_7778;
    memoryASet(ds, 0x2333, 0x00);
    return;
loc_7778: // 0655:1228
    ah = 0x0f;
    interrupt(0x10);
    memoryASet(ds, 0x2333, al);
    ax = 0x0040;
    es = ax;
    bx = 0x0010;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x2334, al);
    if (memoryAGet(ds, 0x232c) == 0x05)
        return;
    if (memoryAGet(ds, 0x232c) == 0x07)
        return;
    al &= 0xcf;
    al |= 0x20;
    memoryASet(es, bx, al);
}
void sub_77af() // 0655:125f
{
    push(0x7777);
    memoryASet(ds, 0x2333, 0xff);
    push(bp);
    bp = sp;
    ax = 0;
    ch = memoryAGet(ds, 0x232d);
    if (memoryAGet(ds, 0x232c) != 0x05)
        goto loc_77c6;
    ch = 0x03;
loc_77c6: // 0655:1276
    cl = memoryAGet(ds, 0x232b);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ah = 0x01;
    if (memoryAGet(es, bx + 22) != 0x00)
        goto loc_77dc;
    ah = 0;
    bx = memoryAGet16(ds, 0x22c2);
    es = memoryAGet16(ds, 0x22c2 + 2);
loc_77dc: // 0655:128c
    si = 0x0000;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    memoryASet16(ds, 0x22ca, bx);
    memoryASet16(ds, 0x22cc, es);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_77ef() // 0655:129f
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 14);
    bx = memoryAGet16(ss, bp + 12);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    if (memoryAGet(ss, bp + 6) != 0x00)
        goto loc_7807;
    ah |= 0x80;
loc_7807: // 0655:12b7
    si = 0x0038;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_783d() // 0655:12ed
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet(ds, 0x2333) == 0xff)
        goto loc_786a;
    si = 0x0006;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    if (memoryAGet(ds, 0x22e0) == 0xa5)
        goto loc_786a;
    ax = 0x0040;
    es = ax;
    bx = 0x0010;
    al = memoryAGet(ds, 0x2334);
    memoryASet(es, bx, al);
    ah = 0;
    al = memoryAGet(ds, 0x2333);
    interrupt(0x10);
loc_786a: // 0655:131a
    memoryASet(ds, 0x2333, 0xff);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_78a8() // 0655:1358
{
    push(0x7777);
    goto loc_78a8;
loc_789f: // 0655:134f
//    stop(override stack);
    ax = pop();
    push(cs);
    sub_7761();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
    return;
loc_78a8: // 0655:1358
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    push(ax);
    si = 0x0032;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bx = memoryAGet16(es, bx + 14);
    goto loc_789f;
}
void sub_78c2() // 0655:1372
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x22cf, ah);
    al = memoryAGet(ds, 0x22ce);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    memoryASet(ds, 0x22d2, 0x0c);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = 0xffff;
    si = 0x0020;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_78ec() // 0655:139c
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = memoryAGet(ss, bp + 8);
    al = memoryAGet(ss, bp + 6);
    si = 0x002a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7948() // 0655:13f8
{
    push(0x7777);
    push(bp);
    bp = sp;
    memoryASet(ds, 0x232a, 0xff);
    memoryASet(ds, 0x232b, 0x00);
    memoryASet(ds, 0x232d, 0x0a);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(es, di);
    memoryASet(ds, 0x232c, al);
    if (al != 0)
        goto loc_796f;
    sub_79bc();
    al = memoryAGet(ds, 0x232a);
    goto loc_799e;
loc_796f: // 0655:141f
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, di);
    memoryASet(ds, 0x232b, al);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bl = memoryAGet(es, di);
    if ((char)bl < 0)
        goto loc_79a6;
    al = 0x0a;
    flags.carry = al < bl;
    al -= bl;
    if (!flags.carry)
        goto loc_798c;
    al = -al;
    goto loc_799e;
loc_798c: // 0655:143c
    bh = 0;
    al = memoryAGet(cs, bx + 6367);
    memoryASet(ds, 0x232d, al);
    al = memoryAGet(cs, bx + 6339);
    memoryASet(ds, 0x232a, al);
loc_799e: // 0655:144e
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    ah = 0;
    memoryASet16(es, di, ax);
loc_79a6: // 0655:1456
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_79bc() // 0655:146c
{
    push(bp);
    sub_7e3d();
    bp = pop();
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(ds, 0x232c);
    ah = 0;
    if (al != 0xff)
        goto loc_79cf;
    ah = al;
loc_79cf: // 0655:147f
    memoryASet16(es, di, ax);
    ah = 0;
    al = memoryAGet(ds, 0x232b);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, di, ax);
}
void sub_79de() // 0655:148e
{
    ax = 0;
    memoryASet(ds, 0x232a, 0xff);
    memoryASet(ds, 0x232b, al);
    memoryASet(ds, 0x232c, al);
    memoryASet(ds, 0x232d, al);
    memoryASet(ds, 0x232e, al);
    memoryASet16(ds, 0x232f, ax);
    memoryASet16(ds, 0x2331, ax);
    memoryASet(ds, 0x2333, 0xff);
    memoryASet(ds, 0x2334, al);
    cs = pop();
}
void sub_7a00() // 0655:14b0
{
    push(0x7777);
    push(bp);
    bp = sp;
    sub_7764();
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ds, 0x232f, bx);
    memoryASet16(ds, 0x2331, es);
    si = 0x0002;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7a28() // 0655:14d8
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7a3c() // 0655:14ec
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    si = 0x000a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7a50() // 0655:1500
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    si = 0x000c;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_7a98() // 0655:1548
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    si = 0x0012;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_7aea() // 0655:159a
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 16);
    bx = memoryAGet16(ss, bp + 14);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ax = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    si = 0x0014;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_7b45() // 0655:15f5
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 16);
    bx = memoryAGet16(ss, bp + 14);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ax = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    si = 0x0016;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_7b8c() // 0655:163c
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x22ce, al);
    ah = memoryAGet(ds, 0x22cf);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_7ba4() // 0655:1654
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0;
    si = 0x003a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ax = cx;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7bb4() // 0655:1664
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0;
    si = 0x003a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ax = bx;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7bc4() // 0655:1674
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x01;
    si = 0x003a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    dx = es;
    ax = bx;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7bed() // 0655:169d
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x01;
    si = 0x0000;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ax = cx;
    ax--;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7bfe() // 0655:16ae
{
    push(0x7777);
    push(bp);
    bp = sp;
    bl = memoryAGet(ss, bp + 6);
    bh = 0;
    ax = 0xffff;
    si = 0x001a;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_7c47() // 0655:16f7
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx++;
    si = 0x001c;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7c59() // 0655:1709
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 10);
    memoryASet(ds, 0x22d1, al);
    bx = memoryAGet16(ss, bp + 8);
    cl = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x232e, cl);
    ch = 0;
    si = 0x0022;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_7cb5() // 0655:1765
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x22cf, ah);
    al = memoryAGet(ds, 0x22ce);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    al = memoryAGet(ss, bp + 8);
    memoryASet(ds, 0x22d2, al);
    ah = al;
    si = 0x0020;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7cdc() // 0655:178c
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    cl = memoryAGet(es, bx);
    ch = 0;
    bx++;
    si = 0x0026;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_7d00() // 0655:17b0
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ds, 0x22ca);
    es = memoryAGet16(ds, 0x22ca + 2);
    bx = memoryAGet16(es, bx + 16);
    bx &= 0x7f7f;
    dl = memoryAGet(ss, bp + 6);
    al = bh;
    mul(dl);
    cx = ax;
    al = bl;
    mul(dl);
    bx = ax;
    al = memoryAGet(ss, bp + 10);
    ah = memoryAGet(ss, bp + 8);
    if (al == 0)
        goto loc_7d3d;
    di = memoryAGet16(ds, 0x22ca);
    es = memoryAGet16(ds, 0x22ca + 2);
    if (memoryAGet(es, di + 1) == 0x03)
        goto loc_7d3d;
    cl = dl;
    ch = 0;
    bx = cx;
    dx = memoryAGet16(ds, 0x22c8);
loc_7d3d: // 0655:17ed
    si = 0x0024;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_7d96() // 0655:1846 get pixel
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    si = 0x002e;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    ah = 0;
    al = dl;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7dae() // 0655:185e
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 8);
    dl = memoryAGet(ss, bp + 6);
    si = 0x0030;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_7dc5() // 0655:1875
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    cx = memoryAGet16(ss, bp + 16);
    dx = memoryAGet16(ss, bp + 14);
    si = memoryAGet16(ss, bp + 12);
    di = memoryAGet16(ss, bp + 10);
    if (cx < si)
        goto loc_7ddd;
    tx = cx;
    cx = si;
    si = tx;
loc_7ddd: // 0655:188d
    if (dx < di)
        goto loc_7de3;
    tx = dx;
    dx = di;
    di = tx;
loc_7de3: // 0655:1893
    si -= cx;
    memoryASet16(es, bx, si);
    di -= dx;
    memoryASet16(es, bx + 2, di);
    si = 0x0034;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_7df9() // 0655:18a9
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    cx = memoryAGet16(ss, bp + 14);
    dx = memoryAGet16(ss, bp + 12);
    al = memoryAGet(ss, bp + 6);
    si = 0x0036;
    push(cs);
    cs = memoryAGet16(ds, 0x22b0 + 2);
    callIndirect(memoryAGet16(ds, 0x22b0 + 2), memoryAGet16(ds, 0x22b0));
    assert(cs == 0x0655);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_7e3d() // 0655:18ed
{
    memoryASet(ds, 0x232a, 0xff);
    memoryASet(ds, 0x232c, 0xff);
    memoryASet(ds, 0x232b, 0x00);
    sub_7e73();
    bl = memoryAGet(ds, 0x232c);
    if (bl == 0xff)
        return;
    bh = 0;
    al = memoryAGet(cs, bx + 6339);
    memoryASet(ds, 0x232a, al);
    al = memoryAGet(cs, bx + 6353);
    memoryASet(ds, 0x232b, al);
    al = memoryAGet(cs, bx + 6367);
    memoryASet(ds, 0x232d, al);
}
void sub_7e73() // 0655:1923
{
    ah = 0x0f;
    interrupt(0x10);
    if (al == 0x07)
        goto loc_7eac;
    sub_7f68();
    if (!flags.carry)
        goto loc_7e86;
    memoryASet(ds, 0x232c, 0x06);
    return;
loc_7e86: // 0655:1936
    sub_7eda();
    if (!flags.carry)
        goto loc_7e8f;
loc_7e8b: // 0655:193b
    sub_7ef8();
    return;
loc_7e8f: // 0655:193f
    sub_7f9d();
    if (ax == 0)
        goto loc_7e9c;
    memoryASet(ds, 0x232c, 0x0a);
    return;
loc_7e9c: // 0655:194c
    memoryASet(ds, 0x232c, 0x01);
    sub_7f47();
    if (!flags.carry)
        goto loc_7eab;
    memoryASet(ds, 0x232c, 0x02);
loc_7eab: // 0655:195b
    return;
loc_7eac: // 0655:195c
    sub_7eda();
    if (flags.carry)
        goto loc_7e8b;
    sub_7f6b();
    if (al == 0)
        goto loc_7ebe;
    memoryASet(ds, 0x232c, 0x07);
    return;
loc_7ebe: // 0655:196e
    si = 0xb800;
    es = si;
    si = 0;
    ax = memoryAGet16(es, si);
    ax = ~ax;
    memoryASet16(es, si, ~memoryAGet16(es, si));
    if (ax != memoryAGet16(es, si))
        return;
    memoryASet(ds, 0x232c, 0x01);
}
void sub_7eda() // 0655:198a
{
    ax = 0x1200;
    bl = 0x10;
    bh = 0xff;
    cl = 0x0f;
    interrupt(0x10);
    if ((char)cl >= (char)0x0c)
        goto loc_7ef6;
    if ((char)bh > (char)0x01)
        goto loc_7ef6;
    if ((char)bl > (char)0x03)
        goto loc_7ef6;
    flags.carry = true;
    return;
loc_7ef6: // 0655:19a6
    flags.carry = false;
}
void sub_7ef8() // 0655:19a8
{
    memoryASet(ds, 0x232c, 0x04);
    if (bh == 0x01)
        goto loc_7f32;
    sub_7f38();
    if (flags.carry)
        goto loc_7f31;
    if (bl == 0)
        goto loc_7f31;
    memoryASet(ds, 0x232c, 0x03);
    sub_7f47();
    if (flags.carry)
        goto loc_7f2c;
    bx = 0xc000;
    es = bx;
    bx = 0x0039;
    if (memoryAGet16(es, bx) != 0x345a)
        goto loc_7f31;
    if (memoryAGet16(es, bx + 2) != 0x3934)
        goto loc_7f31;
loc_7f2c: // 0655:19dc
    memoryASet(ds, 0x232c, 0x09);
loc_7f31: // 0655:19e1
    return;
loc_7f32: // 0655:19e2
    memoryASet(ds, 0x232c, 0x05);
}
// INJECT: Error: cannot inject flag in sub_7f38() because of being label!
void sub_7f38() // 0655:19e8
{
    if (cl < 0x02)
        goto loc_7f46;
    flags.carry = !flags.carry;
    if (stop(/*1 - jae loc_7f46*/))
        goto loc_7f46;
loc_7f46: // 0655:19f6
    stop(/*inject ret*/);
}
void sub_7f47() // 0655:19f7
{
    ax = 0x1a00;
    interrupt(0x10);
    if (al != 0x1a)
        goto loc_7f66;
    if (bl == 0x07)
        goto loc_7f64;
    if (bl == 0x08)
        goto loc_7f64;
    if (bl < 0x0b)
        goto loc_7f66;
    if (bl > 0x0c)
        goto loc_7f66;
loc_7f64: // 0655:1a14
    flags.carry = true;
    return;
loc_7f66: // 0655:1a16
    flags.carry = false;
}
// INJECT: Error: cannot inject zero flag in sub_7f68() because no traceback!
void sub_7f68() // 0655:1a18
{
    al = 0;
    stop(/*inject ret*/);
}
void sub_7f6b() // 0655:1a1b
{
    dx = 0x03ba;
    bl = 0;
    in(al, dx);
    al &= 0x80;
    ah = al;
    cx = 0x8000;
loc_7f78: // 0655:1a28
    in(al, dx);
    al &= 0x80;
    if (al == ah)
        goto loc_7f86;
    bl++;
    if (bl >= 0x0a)
        goto loc_7f8b;
loc_7f86: // 0655:1a36
    if (--cx)
        goto loc_7f78;
    al = 0;
    return;
loc_7f8b: // 0655:1a3b
    cx = 0x8000;
loc_7f8e: // 0655:1a3e
    in(al, dx);
    al &= 0x30;
    if (al != 0x10)
        goto loc_7f9a;
    if (--cx)
        goto loc_7f8e;
    al = 0x02;
    return;
loc_7f9a: // 0655:1a4a
    al = 0x01;
}
void sub_7f9d() // 0655:1a4d
{
    al = 0x06;
    cx = 0;
    dx = 0;
    ah = 0x30;
    interrupt(0x10);
    ax = cx;
    ax |= dx;
    if (!ax)
        goto loc_7fca;
    push(ds);
    ds = cx;
    bx = dx;
    al = memoryAGet(ds, bx + 2);
    ds = pop();
    if (!al)
        goto loc_7fbe;
    if (al != 0x02)
        goto loc_7fca;
loc_7fbe: // 0655:1a6e
    dx = 0x0188;
    in(al, dx);
    if (!(al & 0x04))
        goto loc_7fca;
    ax = 0x0001;
    return;
loc_7fca: // 0655:1a7a
    ax = 0;
}
void sub_99f6() // 099c:0036
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x2c;
    interrupt(0x21);
    ah = 0;
    al = dl;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    stosw<MemAuto, DirAuto>();
    al = dh;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    stosw<MemAuto, DirAuto>();
    al = cl;
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    stosw<MemAuto, DirAuto>();
    al = ch;
    di = memoryAGet16(ss, bp + 18);
    es = memoryAGet16(ss, bp + 18 + 2);
    stosw<MemAuto, DirAuto>();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 16;
}
void sub_9a32() // 099c:0072
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 10);
    ah = 0x35;
    interrupt(0x21);
    ax = es;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    flags.direction = false;
    tx = bx;
    bx = ax;
    ax = tx;
    stosw<MemAuto, DirAuto>();
    tx = bx;
    bx = ax;
    ax = tx;
    stosw<MemAuto, DirAuto>();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_9a4a() // 099c:008a
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(ss, bp + 10);
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_9a60() // 09a6:0000
{
    push(0x7777);
    push(bp);
    bp = sp;
    sub_9a8e();
    di = 0x234a;
    push(ds);
    push(di);
    push(cs);
    sub_9d8f();
    di = 0x234a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_a5e5();
    assert(cs == 0x09a6);
    di = 0x244a;
    push(ds);
    push(di);
    push(cs);
    sub_9d8f();
    di = 0x244a;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0a08;
    sub_a5ea();
    assert(cs == 0x09a6);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_9a8e() // 09a6:002e
{
    ah = 0x0f;
    sub_a069();
    if (al == 0x07)
        goto loc_9aa1;
    if (al <= 0x03)
        goto loc_9aa1;
    ax = 0x0003;
    sub_9af7();
loc_9aa1: // 09a6:0041
    sub_9b45();
    ah = 0x08;
    bh = 0;
    sub_a069();
    al = ah;
    al &= 0x7f;
    memoryASet(ds, 0x2346, al);
    memoryASet(ds, 0x233c, al);
    ax = 0;
    memoryASet(ds, 0x2337, al);
    memoryASet(ds, 0x2347, al);
    memoryASet(ds, 0x2348, al);
    ax++;
    memoryASet(ds, 0x2336, al);
    ax = 0x0040;
    es = ax;
    di = 0x006c;
    al = memoryAGet(es, di);
loc_9acf: // 09a6:006f
    if (al == memoryAGet(es, di))
        goto loc_9acf;
    al = memoryAGet(es, di);
    cx = 0xffff;
    sub_9d1f();
    ax = 0x0037;
    tx = cx;
    cx = ax;
    ax = tx;
    ax = ~ax;
    dx = 0;
    div(cx);
    memoryASet16(ds, 0x2342, ax);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x012d;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
}
void sub_9af7() // 09a6:0097
{
    dx = 0x0040;
    es = dx;
    memoryASet(es, 0x0087, memoryAGet(es, 0x0087) & 0xfe);
    if (al == 0x07)
        goto loc_9b0c;
    if (al < 0x04)
        goto loc_9b0c;
    al = 0x03;
loc_9b0c: // 09a6:00ac
    push(ax);
    ah = 0x00;
    sub_a069();
    ax = pop();
    if (!ah)
        return;
    ax = 0x1112;
    bl = 0x00;
    sub_a069();
    ax = 0x1130;
    bh = 0x00;
    dl = 0x00;
    sub_a069();
    if (dl != 0x2a)
        return;
    memoryASet(es, 0x0087, memoryAGet(es, 0x0087) | 0x01);
    ax = 0x0100;
    cx = 0x0600;
    sub_a069();
    ah = 0x12;
    bl = 0x20;
    sub_a069();
}
void sub_9b45() // 09a6:00e5
{
    ah = 0x0f;
    sub_a069();
    push(ax);
    ax = 0x1130;
    bh = 0x00;
    dl = 0x00;
    sub_a069();
    ax = pop();
    cl = 0x00;
    if (dl)
        goto loc_9b64;
    dl = 0x18;
    if (al > 0x03)
        goto loc_9b64;
    cl = 0x01;
loc_9b64: // 09a6:0104
    dh = dl;
    dl = ah;
    dl--;
    ah = 0x00;
    if (dh <= 0x18)
        goto loc_9b73;
    ah = 0x01;
loc_9b73: // 09a6:0113
    memoryASet16(ds, 0x233a, ax);
    memoryASet16(ds, 0x2344, dx);
    memoryASet(ds, 0x2339, cl);
    memoryASet(ds, 0x2338, 0x01);
    ax = 0;
    memoryASet16(ds, 0x233e, ax);
    memoryASet16(ds, 0x2340, dx);
}
void sub_9ba3() // 09a6:0143
{
//    stop(/*unk call conv*/);
    if (memoryAGet(ds, 0x2348) != 0x00)
        goto loc_9bab;
//    stop(/*unk call conv*/);
    return;
loc_9bab: // 09a6:014b
    memoryASet(ds, 0x2348, 0x00);
loc_9bb0: // 09a6:0150
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_9bbc;
    ah = 0x00;
    interrupt(0x16);
    goto loc_9bb0;
loc_9bbc: // 09a6:015c
    al = 0x5e;
    sub_9edc();
    al = 0x43;
    sub_9edc();
    sub_9ed5();
    interrupt(0x23);
    bx = sp;
    ax = memoryAGet16(ss, bx + 4);
    sub_9af7();
    sub_9b45();
    al = memoryAGet(ds, 0x2346);
    memoryASet(ds, 0x233c, al);
//    stop(/*unk call conv*/);
    sp += 2;
}
void sub_9c20() // 09a6:01c0
{
    ax = 0x0600;
    bh = memoryAGet(ds, 0x233c);
    cx = memoryAGet16(ds, 0x233e);
    dx = memoryAGet16(ds, 0x2340);
    sub_a069();
    dx = memoryAGet16(ds, 0x233e);
    sub_9f5d();
    cs = pop();
}
void sub_9c73() // 09a6:0213
{
    push(0x7777);
    bx = sp;
    dl = memoryAGet(ss, bx + 6);
    dh = memoryAGet(ss, bx + 4);
    dl--;
    flags.carry = (dl + memoryAGet(ds, 0x233e)) >= 0x100;
    dl += memoryAGet(ds, 0x233e);
    if (flags.carry)
        goto loc_9c9c;
    if (dl > memoryAGet(ds, 0x2340))
        goto loc_9c9c;
    dh--;
    flags.carry = (dh + memoryAGet(ds, 0x233f)) >= 0x100;
    dh += memoryAGet(ds, 0x233f);
    if (flags.carry)
        goto loc_9c9c;
    if (dh > memoryAGet(ds, 0x2341))
        goto loc_9c9c;
    sub_9f5d();
loc_9c9c: // 09a6:023c
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_9cb7() // 09a6:0257
{
    push(0x7777);
    bx = sp;
    al = memoryAGet(ss, bx + 4);
    if (!(al & 0xf0))
        goto loc_9cc5;
    al &= 0x0f;
    al |= 0x80;
loc_9cc5: // 09a6:0265
    memoryASet(ds, 0x233c, memoryAGet(ds, 0x233c) & 0x70);
    memoryASet(ds, 0x233c, memoryAGet(ds, 0x233c) | al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9cfc() // 09a6:029c
{
    push(0x7777);
    bx = sp;
    dx = memoryAGet16(ss, bx + 4);
    if (!dx)
        goto loc_9d1c;
    ax = 0x0040;
    es = ax;
    di = 0;
    al = memoryAGet(es, di);
    bx = memoryAGet16(ds, 0x2342);
loc_9d14: // 09a6:02b4
    cx = bx;
    sub_9d1f();
    tx = dx;
    dx--;
    if (tx != 1)
        goto loc_9d14;
loc_9d1c: // 09a6:02bc
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9d1f() // 09a6:02bf
{
loc_9d1f: // 09a6:02bf
    if (al != memoryAGet(es, di))
        return;
    if (--cx)
        goto loc_9d1f;
}
void sub_9d27() // 09a6:02c7
{
    push(0x7777);
    bx = sp;
    bx = memoryAGet16(ss, bx + 4);
    ax = 0x34dd;
    dx = 0x0012;
    if (dx >= bx)
        goto loc_9d51;
    div(bx);
    bx = ax;
    in(al, 0x61);
    if (al & 0x03)
        goto loc_9d49;
    al |= 0x03;
    out(0x61, al);
    al = 0xb6;
    out(0x43, al);
loc_9d49: // 09a6:02e9
    al = bl;
    out(0x42, al);
    al = bh;
    out(0x42, al);
loc_9d51: // 09a6:02f1
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9d54() // 09a6:02f4
{
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    cs = pop();
}
void sub_9d5b() // 09a6:02fb
{
    if (memoryAGet(ds, 0x2347) != 0x00)
        goto loc_9d6a;
    ah = 0x01;
    interrupt(0x16);
    al = 0x00;
    if (flags.zero)
        goto loc_9d6c;
loc_9d6a: // 09a6:030a
    al = 0x01;
loc_9d6c: // 09a6:030c
    cs = pop();
}
void sub_9d6d() // 09a6:030d
{
    al = memoryAGet(ds, 0x2347);
    memoryASet(ds, 0x2347, 0x00);
    if (al)
        goto loc_9d8b;
    ah = 0;
    interrupt(0x16);
    if (al)
        goto loc_9d8b;
    memoryASet(ds, 0x2347, ah);
    if (ah)
        goto loc_9d8b;
    al = 0x03;
loc_9d8b: // 09a6:032b
    sub_9ba3();
    cs = pop();
}
void sub_9d8f() // 09a6:032f
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    memoryASet16(ds, di + 2, 0xd7b0);
    memoryASet16(ds, di + 4, 0x0080);
    ax = di + 0x80;
    memoryASet16(ds, di + 12, ax);
    memoryASet16(ds, di + 14, ds);
    memoryASet16(ds, di + 16, 0x035a);
    memoryASet16(ds, di + 18, cs);
    memoryASet(ds, di + 48, 0x00);
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_9dba() // 09a6:035a
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    ax = 0x0392;
    bx = 0x0470;
    cx = bx;
    if (memoryAGet16(ds, di + 2) == 0xd7b1)
        goto loc_9dda;
    memoryASet16(ds, di + 2, 0xd7b2);
    ax = 0x043f;
    bx = ax;
loc_9dda: // 09a6:037a
    memoryASet16(ds, di + 20, ax);
    memoryASet16(ds, di + 22, cs);
    memoryASet16(ds, di + 24, bx);
    memoryASet16(ds, di + 26, cs);
    memoryASet16(ds, di + 28, cx);
    memoryASet16(ds, di + 30, cs);
    ax = 0;
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_9e9f() // 09a6:043f
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    cx = memoryAGet16(es, di + 8);
    memoryASet16(es, di + 8, memoryAGet16(es, di + 8) - cx);
    if (cx == 0)
        goto loc_9ec8;
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    if (memoryAGet(ds, 0x2338) != 0x00)
        goto loc_9ec5;
loc_9eba: // 09a6:045a
    al = memoryAGet(es, di);
    sub_9edc();
    di++;
    if (--cx)
        goto loc_9eba;
    goto loc_9ec8;
loc_9ec5: // 09a6:0465
    sub_9f64();
loc_9ec8: // 09a6:0468
    sub_9ba3();
    ax = 0;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_9ed0() // 09a6:0470
{
    ax = 0;
    cs = pop();
    sp += 4;
}
void sub_9ed5() // 09a6:0475
{
    al = 0x0d;
    sub_9edc();
    al = 0x0a;
    push(bx);
    push(cx);
    push(dx);
    push(es);
    push(ax);
    sub_9f56();
    ax = pop();
    if (al == 0x07)
        goto loc_9f13;
    if (al == 0x08)
        goto loc_9f1a;
    if (al == 0x0d)
        goto loc_9f24;
    if (al == 0x0a)
        goto loc_9f2a;
    ah = 0x09;
    bl = memoryAGet(ds, 0x233c);
    bh = 0;
    cx = 0x0001;
    push(dx);
    sub_a069();
    dx = pop();
    dl++;
    if (dl <= memoryAGet(ds, 0x2340))
        goto loc_9f2d;
    dl = memoryAGet(ds, 0x233e);
    goto loc_9f2a;
loc_9f13: // 09a6:04b3
    ah = 0x0e;
    sub_a069();
    goto loc_9f2d;
loc_9f1a: // 09a6:04ba
    if (dl == memoryAGet(ds, 0x233e))
        goto loc_9f2d;
    dl--;
    goto loc_9f2d;
loc_9f24: // 09a6:04c4
    dl = memoryAGet(ds, 0x233e);
    goto loc_9f2d;
loc_9f2a: // 09a6:04ca
    sub_9f35();
loc_9f2d: // 09a6:04cd
    sub_9f5d();
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_9edc() // 09a6:047c
{
    push(bx);
    push(cx);
    push(dx);
    push(es);
    push(ax);
    sub_9f56();
    ax = pop();
    if (al == 0x07)
        goto loc_9f13;
    if (al == 0x08)
        goto loc_9f1a;
    if (al == 0x0d)
        goto loc_9f24;
    if (al == 0x0a)
        goto loc_9f2a;
    ah = 0x09;
    bl = memoryAGet(ds, 0x233c);
    bh = 0;
    cx = 0x0001;
    push(dx);
    sub_a069();
    dx = pop();
    dl++;
    if (dl <= memoryAGet(ds, 0x2340))
        goto loc_9f2d;
    dl = memoryAGet(ds, 0x233e);
    goto loc_9f2a;
loc_9f13: // 09a6:04b3
    ah = 0x0e;
    sub_a069();
    goto loc_9f2d;
loc_9f1a: // 09a6:04ba
    if (dl == memoryAGet(ds, 0x233e))
        goto loc_9f2d;
    dl--;
    goto loc_9f2d;
loc_9f24: // 09a6:04c4
    dl = memoryAGet(ds, 0x233e);
    goto loc_9f2d;
loc_9f2a: // 09a6:04ca
    sub_9f35();
loc_9f2d: // 09a6:04cd
    sub_9f5d();
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_9f35() // 09a6:04d5
{
    dh++;
    if (dh <= memoryAGet(ds, 0x2341))
        return;
    dh--;
    push(cx);
    push(dx);
    ax = 0x0601;
    bh = memoryAGet(ds, 0x233c);
    cx = memoryAGet16(ds, 0x233e);
    dx = memoryAGet16(ds, 0x2340);
    sub_a069();
    dx = pop();
    cx = pop();
}
void sub_9f56() // 09a6:04f6
{
    ah = 0x03;
    bh = 0;
    goto loc_a069;
    //   gap of 268 bytes
loc_a069: // 09a6:0609
    push(si);
    push(di);
    push(bp);
    push(es);
    interrupt(0x10);
    es = pop();
    bp = pop();
    di = pop();
    si = pop();
}
void sub_9f5d() // 09a6:04fd
{
    ah = 0x02;
    bh = 0;
    goto loc_a069;
    //   gap of 261 bytes
loc_a069: // 09a6:0609
    push(si);
    push(di);
    push(bp);
    push(es);
    interrupt(0x10);
    es = pop();
    bp = pop();
    di = pop();
    si = pop();
}
void sub_9f64() // 09a6:0504
{
    push(ds);
    ax = 0x0040;
    ds = ax;
    dx = memoryAGet16(ds, 0x0050);
    ds = pop();
    bx = dx;
    si = di;
loc_9f73: // 09a6:0513
    al = memoryAGet(es, di);
    if (al == 0x07)
        goto loc_9f9b;
    if (al == 0x08)
        goto loc_9faa;
    if (al == 0x0a)
        goto loc_9fb7;
    if (al == 0x0d)
        goto loc_9fbf;
    di++;
    dl++;
    if (dl <= memoryAGet(ds, 0x2340))
        goto loc_9fcb;
    sub_a001();
    sub_9f35();
    dl = memoryAGet(ds, 0x233e);
    goto loc_9fc7;
loc_9f9b: // 09a6:053b
    sub_a001();
    push(cx);
    push(dx);
    ax = 0x0e07;
    sub_a069();
    dx = pop();
    cx = pop();
    goto loc_9fc6;
loc_9faa: // 09a6:054a
    sub_a001();
    if (dl == memoryAGet(ds, 0x233e))
        goto loc_9fc6;
    dl--;
    goto loc_9fc6;
loc_9fb7: // 09a6:0557
    sub_a001();
    sub_9f35();
    goto loc_9fc6;
loc_9fbf: // 09a6:055f
    sub_a001();
    dl = memoryAGet(ds, 0x233e);
loc_9fc6: // 09a6:0566
    di++;
loc_9fc7: // 09a6:0567
    si = di;
    bx = dx;
loc_9fcb: // 09a6:056b
    if (--cx)
        goto loc_9f73;
    sub_a001();
    push(ds);
    ax = 0x0040;
    ds = ax;
    memoryASet16(ds, 0x0050, dx);
    al = dh;
    mul(memoryAGet(ds, 0x004a));
    dh = 0;
    ax += dx;
    cx = ax;
    dx = memoryAGet16(ds, 0x0063);
    al = 0x0e;
    out(dx, al);
    al = ch;
    dx++;
    out(dx, al);
    dx--;
    al = 0x0f;
    out(dx, al);
    al = cl;
    dx++;
    out(dx, al);
    ds = pop();
}
void sub_a001() // 09a6:05a1
{
    if (si == di)
        return;
    push(cx);
    push(dx);
    push(di);
    push(ds);
    push(es);
    cx = di;
    cx -= si;
    dl = memoryAGet(ds, 0x2339);
    dh = memoryAGet(ds, 0x233c);
    ax = 0x0040;
    ds = ax;
    al = bh;
    mul(memoryAGet(ds, 0x004a));
    bh = 0;
    ax += bx;
    ax <<= 1;
    di = ax;
    bx = dx;
    dx = memoryAGet16(ds, 0x0063);
    dx += 0x0006;
    ax = 0xb800;
    if (memoryAGet(ds, 0x0049) != 0x07)
        goto loc_a03e;
    ah = 0xb0;
loc_a03e: // 09a6:05de
    push(es);
    ds = pop();
    es = ax;
    flags.direction = false;
    if (!bl)
        goto loc_a05d;
loc_a047: // 09a6:05e7
    lodsb<MemAuto, DirAuto>();
    bl = al;
loc_a04a: // 09a6:05ea
    in(al, dx);
    if (al & 0x01)
        goto loc_a04a;
    flags.interrupts = false;
loc_a050: // 09a6:05f0
    in(al, dx);
    if (!(al & 0x01))
        goto loc_a050;
    ax = bx;
    stosw<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_a047;
    goto loc_a063;
loc_a05d: // 09a6:05fd
    ah = bh;
loc_a05f: // 09a6:05ff
    lodsb<MemAuto, DirAuto>();
    stosw<MemAuto, DirAuto>();
    if (--cx)
        goto loc_a05f;
loc_a063: // 09a6:0603
    es = pop();
    ds = pop();
    di = pop();
    dx = pop();
    cx = pop();
}
void sub_a069() // 09a6:0609
{
    push(si);
    push(di);
    push(bp);
    push(es);
    interrupt(0x10);
    es = pop();
    bp = pop();
    di = pop();
    si = pop();
}
void sub_a080() // 0a08:0000
{
    push(0x7777);
    dx = 0x0ba6;
    ds = dx;
    memoryASet16(ds, 0x1052, es);
    bp = 0;
    ax = sp;
    ax += 0x0013;
    cl = 0x04;
    ax >>= cl;
    dx = ss;
    ax += dx;
    memoryASet16(ds, 0x1024, ax);
    memoryASet16(ds, 0x1026, ax);
    ax += memoryAGet16(ds, 0x101e);
    memoryASet16(ds, 0x1028, ax);
    memoryASet16(ds, 0x1032, ax);
    memoryASet16(ds, 0x1036, ax);
    memoryASet16(ds, 0x103e, ax);
    dx = memoryAGet16(es, 0x0002);
    memoryASet16(ds, 0x103a, dx);
    memoryASet16(ds, 0x1044, 0x00a9);
    memoryASet16(ds, 0x1046, cs);
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a0cb: // 0a08:004b
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x35;
    interrupt(0x21);
    memoryASet16(ds, di, bx);
    memoryASet16(ds, di + 2, es);
    di += 0x0004;
    if (--cx)
        goto loc_a0cb;
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x00df;
    ax = 0x2500;
    interrupt(0x21);
    dx = 0x00e6;
    ax = 0x2523;
    interrupt(0x21);
    dx = 0x00ae;
    ax = 0x2524;
    interrupt(0x21);
    dx = 0x00d7;
    ax = 0x253f;
    interrupt(0x21);
    ds = pop();
    ax = 0x234a;
    push(ds);
    push(ax);
    push(ds);
    push(ax);
    ax = 0x0218;
    push(cs);
    push(ax);
    push(cs);
    sub_a575();
    push(cs);
    sub_a5e5();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(ds);
    push(ax);
    ax = 0x0218;
    push(cs);
    push(ax);
    push(cs);
    sub_a575();
    push(cs);
    sub_a5ea();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_a169() // 0a08:00e9
{
    cx = 0;
    bx = 0;
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
}
void sub_a225() // 0a08:01a5
{
loc_a225: // 0a08:01a5
    al = memoryAGet(cs, bx);
    if (!al)
        return;
    sub_a267();
    bx++;
    goto loc_a225;
}
void sub_a233() // 0a08:01b3
{
    cl = 0x64;
    sub_a23f();
    cl = 0x0a;
    sub_a23f();
    goto loc_a243;
    //   gap of 4 bytes
loc_a243: // 0a08:01c3
    al += 0x30;
    push(ax);
    sub_a267();
    ax = pop();
    al = ah;
}
void sub_a23f() // 0a08:01bf
{
    ah = 0;
    div(cl);
    al += 0x30;
    push(ax);
    sub_a267();
    ax = pop();
    al = ah;
}
void sub_a24d() // 0a08:01cd
{
    push(ax);
    al = ah;
    sub_a254();
    ax = pop();
    push(ax);
    cl = 0x04;
    al >>= cl;
    sub_a25f();
    ax = pop();
    al &= 0x0f;
    al += 0x30;
    if (al < 0x3a)
        goto loc_a267;
    al += 0x07;
loc_a267: // 0a08:01e7
    dl = al;
    ah = 0x06;
    interrupt(0x21);
}
void sub_a254() // 0a08:01d4
{
    push(ax);
    cl = 0x04;
    al >>= cl;
    sub_a25f();
    ax = pop();
    al &= 0x0f;
    al += 0x30;
    if (al < 0x3a)
        goto loc_a267;
    al += 0x07;
loc_a267: // 0a08:01e7
    dl = al;
    ah = 0x06;
    interrupt(0x21);
}
void sub_a25f() // 0a08:01df
{
    al += 0x30;
    if (al < 0x3a)
        goto loc_a267;
    al += 0x07;
loc_a267: // 0a08:01e7
    dl = al;
    ah = 0x06;
    interrupt(0x21);
}
void sub_a267() // 0a08:01e7
{
    dl = al;
    ah = 0x06;
    interrupt(0x21);
}
void sub_a2bf() // 0a08:023f
{
    push(0x7777);
    goto loc_a2bf;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 154 bytes
loc_a2bf: // 0a08:023f
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    sub_a388();
    bp = pop();
    if (flags.carry)
        goto loc_a2ce;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
    return;
loc_a2ce: // 0a08:024e
    ax = 0x00cb;
    goto loc_a162;
}
void sub_a2d4() // 0a08:0254
{
    push(0x7777);
    goto loc_a2d4;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 175 bytes
loc_a2d4: // 0a08:0254
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    bx = es;
    sub_a453();
    bp = pop();
    if (flags.carry)
        goto loc_a2e8;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
    return;
loc_a2e8: // 0a08:0268
    ax = 0x00cc;
    goto loc_a162;
}
// INJECT: Error: cannot inject flag in sub_a388() because of being label!
// INJECT: Error: cannot inject carry flag in sub_a388()!
void sub_a388() // 0a08:0308
{
    flags.carry = false;
    if (!ax)
        goto loc_a402;
    memoryASet16(ds, 0x2596, ax);
loc_a38f: // 0a08:030f
    sub_a511();
    di = 0x103c;
    cx = ds;
    es = cx;
loc_a399: // 0a08:0319
    cx = di;
    bx = es;
    tx = di;
    di = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    si = es;
    if (si == memoryAGet16(ds, 0x1036))
        goto loc_a403;
    if (dx > memoryAGet16(es, di + 6))
        goto loc_a399;
    if (dx < memoryAGet16(es, di + 6))
        goto loc_a3b6;
    if (ax > memoryAGet16(es, di + 4))
        goto loc_a399;
loc_a3b6: // 0a08:0336
    push(es);
    push(di);
    push(bx);
    push(cx);
    cx = memoryAGet16(es, di);
    bx = memoryAGet16(es, di + 2);
    if (stop(/*1 - je loc_a3f6*/))
        goto loc_a3f6;
    push(bx);
    push(cx);
    cx = memoryAGet16(es, di + 4);
    bx = memoryAGet16(es, di + 6);
    flags.carry = cx < ax;
    cx -= ax;
    bx -= dx + flags.carry;
    cx &= 0x000f;
    ax += di;
    dx += si;
    flags.carry = (al + 0xf0) >= 0x100;
    al += 0xf0;
    dx += flags.carry;
    al &= 0x0f;
    di = ax;
    es = dx;
    memoryASet16(es, di, pop());
    memoryASet16(es, di + 2, pop());
    memoryASet16(es, di + 4, cx);
    memoryASet16(es, di + 6, bx);
    cx = di;
    bx = es;
loc_a3f6: // 0a08:0376
    di = pop();
    es = pop();
    memoryASet16(es, di, cx);
    memoryASet16(es, di + 2, bx);
    ax = pop();
    dx = pop();
    flags.carry = false;
loc_a402: // 0a08:0382
    return;
loc_a403: // 0a08:0383
    ax += di;
    dx += si;
    flags.carry = (al + 0xf0) >= 0x100;
    al += 0xf0;
    dx += flags.carry;
    al &= 0x0f;
    if (dx < memoryAGet16(ds, 0x103a))
        goto loc_a41c;
    if (dx > memoryAGet16(ds, 0x103a))
        goto loc_a43b;
    if (ax > memoryAGet16(ds, 0x1038))
        goto loc_a43b;
loc_a41c: // 0a08:039c
    push(es);
    push(di);
    di = cx;
    es = bx;
    memoryASet16(ds, 0x1034, ax);
    memoryASet16(ds, 0x1036, dx);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
    ax = 0;
    push(ax);
    push(cs);
    cs = memoryAGet16(ds, 0x1044 + 2);
    callIndirect(memoryAGet16(ds, 0x1044 + 2), memoryAGet16(ds, 0x1044));
    assert(cs == 0x0a08);
    ax = pop();
    dx = pop();
    flags.carry = false;
    return;
loc_a43b: // 0a08:03bb
    push(memoryAGet16(ds, 0x2596));
    push(cs);
    cs = memoryAGet16(ds, 0x1044 + 2);
    callIndirect(memoryAGet16(ds, 0x1044 + 2), memoryAGet16(ds, 0x1044));
    assert(cs == 0x0a08);
    if (al < 0x01)
    {
        flags.carry = true;
        goto loc_a402;
    }
    if (al == 0x01)
        goto loc_a44f;
    ax = memoryAGet16(ds, 0x2596);
    goto loc_a38f;
loc_a44f: // 0a08:03cf
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    stop(/*inject ret*/);
}
// INJECT: Error: cannot inject flag in sub_a453() because of being label!
void sub_a453() // 0a08:03d3
{
    if (!ax)
        goto loc_a4b1;
    if (cx & 0xfff7)
        goto loc_a4b0;
    if (bx > memoryAGet16(ds, 0x1032))
        goto loc_a46b;
    if (bx < memoryAGet16(ds, 0x1032))
        goto loc_a4b0;
    if (cx < memoryAGet16(ds, 0x1030))
        goto loc_a4b0;
loc_a46b: // 0a08:03eb
    if (bx < memoryAGet16(ds, 0x1036))
        goto loc_a479;
    if (bx > memoryAGet16(ds, 0x1036))
        goto loc_a4b0;
    if (cx >= memoryAGet16(ds, 0x1034))
        goto loc_a4b0;
loc_a479: // 0a08:03f9
    sub_a511();
    di = cx;
    es = bx;
    memoryASet16(es, di + 4, ax);
    memoryASet16(es, di + 6, dx);
    di = 0x103c;
    ax = ds;
    es = ax;
loc_a48f: // 0a08:040f
    ax = di;
    dx = es;
    tx = di;
    di = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    si = es;
    if (bx > si)
        goto loc_a48f;
    if (bx < si)
        goto loc_a4a4;
    if (cx > di)
        goto loc_a48f;
    if (cx == di)
        goto loc_a4b0;
loc_a4a4: // 0a08:0424
    push(dx);
    push(ax);
    sub_a4b2();
    cx = pop();
    bx = pop();
    sub_a4b2();
    flags.carry = false;
    return;
loc_a4b0: // 0a08:0430
    flags.carry = true;
loc_a4b1: // 0a08:0431
    return;
}
void sub_a4b2() // 0a08:0432
{
    ax = di;
    dx = es;
    di = cx;
    es = bx;
    cx += memoryAGet16(es, di + 4);
    bx += memoryAGet16(es, di + 6);
    flags.carry = (cl + 0xf0) >= 0x100;
    cl += 0xf0;
    bx += flags.carry;
    cl &= 0x0f;
    if (bx != dx)
        goto loc_a509;
    if (cx != ax)
        goto loc_a509;
    if (dx != memoryAGet16(ds, 0x1036))
        goto loc_a4e8;
    if (ax != memoryAGet16(ds, 0x1034))
        goto loc_a4e8;
    memoryASet16(ds, 0x1034, di);
    memoryASet16(ds, 0x1036, es);
    return;
loc_a4e8: // 0a08:0468
    push(ds);
    push(di);
    si = ax;
    ds = dx;
    flags.direction = false;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    lodsw<MemAuto, DirAuto>();
    tx = dx;
    dx = ax;
    ax = tx;
    lodsw<MemAuto, DirAuto>();
    tx = dx;
    dx = ax;
    ax = tx;
    ax += memoryAGet16(es, di);
    dx += memoryAGet16(es, di + 2);
    flags.carry = (al + 0xf0) >= 0x100;
    al += 0xf0;
    dx += flags.carry;
    al &= 0x0f;
    stosw<MemAuto, DirAuto>();
    tx = dx;
    dx = ax;
    ax = tx;
    stosw<MemAuto, DirAuto>();
    di = pop();
    ds = pop();
    return;
loc_a509: // 0a08:0489
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
}
void sub_a511() // 0a08:0491
{
    flags.carry = (ax + 0x0007) >= 0x10000;
    ax += 0x0007;
    dx = ax;
    dx = rcr(dx, 0x0001);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    ax &= 0x0008;
}
void sub_a522() // 0a08:04a2
{
    ax = 0;
    tx = memoryAGet16(ds, 0x1056);
    memoryASet16(ds, 0x1056, ax);
    ax = tx;
    cs = pop();
}
void sub_a529() // 0a08:04a9
{
    goto loc_a529;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 772 bytes
loc_a529: // 0a08:04a9
    if (memoryAGet16(ds, 0x1056) != 0x0000)
        goto loc_a531;
    cs = pop();
    return;
loc_a531: // 0a08:04b1
    ax = memoryAGet16(ds, 0x1056);
    goto loc_a162;
}
void sub_a537() // 0a08:04b7
{
    push(0x7777);
    goto loc_a537;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 786 bytes
loc_a537: // 0a08:04b7
    si = sp;
    es = memoryAGet16(ss, si + 2);
    //GABO RETURN SKIP!
    if ((short)dx > (short)memoryAGet16(es, di + 2))
        goto loc_a54a;
    if ((short)dx < (short)memoryAGet16(es, di + 2))
        goto loc_a559;
    if (ax < memoryAGet16(es, di))
        goto loc_a559;
loc_a54a: // 0a08:04ca
    if ((short)dx < (short)memoryAGet16(es, di + 6))
        goto loc_a558;
    if ((short)dx > (short)memoryAGet16(es, di + 6))
        goto loc_a559;
    if (ax > memoryAGet16(es, di + 4))
        goto loc_a559;
loc_a558: // 0a08:04d8
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a559: // 0a08:04d9
    ax = 0x00c9;
    goto loc_a162;
}
void sub_a55f() // 0a08:04df
{
    push(0x7777);
    goto loc_a55f;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 826 bytes
loc_a55f: // 0a08:04df
    ax += 0x0200;
    flags.carry = ax < sp;
    ax -= sp;
    if (!flags.carry)
        goto loc_a56f;
    ax = -ax;
    if (ax < memoryAGet16(ds, 0x1054))
        goto loc_a56f;
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a56f: // 0a08:04ef
    ax = 0x00ca;
    goto loc_a162;
}
void sub_a575() // 0a08:04f5
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    si = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    flags.direction = false;
    ax = 0;
    stosw<MemAuto, DirAuto>();
    ax = 0xd7b0;
    stosw<MemAuto, DirAuto>();
    ax = 0x0080;
    stosw<MemAuto, DirAuto>();
    ax = 0;
    stosw<MemAuto, DirAuto>();
    stosw<MemAuto, DirAuto>();
    stosw<MemAuto, DirAuto>();
    ax = di + 0x74;
    stosw<MemAuto, DirAuto>();
    ax = es;
    stosw<MemAuto, DirAuto>();
    ax = 0x060c;
    stosw<MemAuto, DirAuto>();
    ax = cs;
    stosw<MemAuto, DirAuto>();
    ax = 0;
    cx = 0x000e;
    rep_stosw<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    if (al <= 0x4f)
        goto loc_a5ad;
    al = 0x4f;
loc_a5ad: // 0a08:052d
    cl = al;
    ch = 0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_a5e5() // 0a08:0565
{
    push(0x7777);
    dx = 0xd7b1;
    goto loc_a5f2;
    //   gap of 8 bytes
loc_a5f2: // 0a08:0572
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, di + 2);
    if (ax == 0xd7b1)
        goto loc_a613;
    if (ax == 0xd7b2)
        goto loc_a613;
    if (ax == 0xd7b0)
        goto loc_a61b;
    memoryASet16(ds, 0x1056, 0x0066);
    goto loc_a637;
loc_a613: // 0a08:0593
    push(dx);
    push(es);
    push(di);
    push(cs);
    sub_a63f();
    dx = pop();
loc_a61b: // 0a08:059b
    ax = 0;
    memoryASet16(es, di + 2, dx);
    memoryASet16(es, di + 8, ax);
    memoryASet16(es, di + 10, ax);
    bx = 0x0010;
    sub_a67b();
    if (flags.zero)
        goto loc_a637;
    memoryASet16(es, di + 2, 0xd7b0);
loc_a637: // 0a08:05b7
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a5ea() // 0a08:056a
{
    push(0x7777);
    dx = 0xd7b2;
    goto loc_a5f2;
    //   gap of 3 bytes
loc_a5f2: // 0a08:0572
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, di + 2);
    if (ax == 0xd7b1)
        goto loc_a613;
    if (ax == 0xd7b2)
        goto loc_a613;
    if (ax == 0xd7b0)
        goto loc_a61b;
    memoryASet16(ds, 0x1056, 0x0066);
    goto loc_a637;
loc_a613: // 0a08:0593
    push(dx);
    push(es);
    push(di);
    push(cs);
    sub_a63f();
    dx = pop();
loc_a61b: // 0a08:059b
    ax = 0;
    memoryASet16(es, di + 2, dx);
    memoryASet16(es, di + 8, ax);
    memoryASet16(es, di + 10, ax);
    bx = 0x0010;
    sub_a67b();
    if (flags.zero)
        goto loc_a637;
    memoryASet16(es, di + 2, 0xd7b0);
loc_a637: // 0a08:05b7
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a63f() // 0a08:05bf
{
    push(0x7777);
    al = 0x01;
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, di + 2) == 0xd7b1)
        goto loc_a667;
    if (memoryAGet16(es, di + 2) == 0xd7b2)
        goto loc_a65f;
    memoryASet16(ds, 0x1056, 0x0067);
    goto loc_a677;
loc_a65f: // 0a08:05df
    push(ax);
    bx = 0x0014;
    sub_a67b();
    ax = pop();
loc_a667: // 0a08:05e7
    if (!al)
        goto loc_a677;
    bx = 0x001c;
    sub_a67b();
    memoryASet16(es, di + 2, 0xd7b0);
loc_a677: // 0a08:05f7
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
// INJECT: Error: cannot inject zero flag in sub_a67b()!
void sub_a67b() // 0a08:05fb
{
    push(es);
    push(di);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, bx + di + 2);
    callIndirect(memoryAGet16(es, bx + di + 2), memoryAGet16(es, bx + di));
    assert(cs == 0x0a08);
    flags.zero = ax == 0;
    if (!ax)
        goto loc_a689;
    memoryASet16(ds, 0x1056, ax);
loc_a689: // 0a08:0609
    di = pop();
    es = pop();
}
void sub_a68c() // 0a08:060c
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    cx = 0;
    memoryASet16(ds, di, cx);
    ax = 0x3d00;
    if (memoryAGet16(ds, di + 2) == 0xd7b1)
        goto loc_a6ae;
    al = 0x02;
    memoryASet16(ds, di, memoryAGet16(ds, di) + 1);
    if (memoryAGet16(ds, di + 2) == 0xd7b3)
        goto loc_a6ae;
    ah = 0x3c;
loc_a6ae: // 0a08:062e
    if (memoryAGet(ds, di + 48) == 0x00)
        goto loc_a6bd;
    dx = di + 0x30;
    interrupt(0x21);
    if (flags.carry)
        goto loc_a70a;
    memoryASet16(ds, di, ax);
loc_a6bd: // 0a08:063d
    ax = 0x06e8;
    cx = 0;
    bx = cx;
    if (memoryAGet16(ds, di + 2) == 0xd7b1)
        goto loc_a6f4;
    bx = memoryAGet16(ds, di);
    ax = 0x4400;
    interrupt(0x21);
    ax = 0x073d;
    cx = ax;
    bx = cs;
    if (dl & 0x80)
        goto loc_a6ef;
    if (memoryAGet16(ds, di + 2) != 0xd7b3)
        goto loc_a6e8;
    sub_a70e();
loc_a6e8: // 0a08:0668
    ax = 0x0718;
    cx = 0;
    bx = cx;
loc_a6ef: // 0a08:066f
    memoryASet16(ds, di + 2, 0xd7b2);
loc_a6f4: // 0a08:0674
    memoryASet16(ds, di + 20, ax);
    memoryASet16(ds, di + 22, cs);
    memoryASet16(ds, di + 24, cx);
    memoryASet16(ds, di + 26, bx);
    memoryASet16(ds, di + 28, 0x075d);
    memoryASet16(ds, di + 30, cs);
    ax = 0;
loc_a70a: // 0a08:068a
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a70e() // 0a08:068e
{
    dx = 0;
    cx = 0;
    bx = memoryAGet16(ds, di);
    ax = 0x4202;
    interrupt(0x21);
    flags.carry = ax < 0x0080;
    ax -= 0x0080;
    dx -= flags.carry;
    if (stop(/*70*/))
        goto loc_a725;
    ax = 0;
    dx = 0;
loc_a725: // 0a08:06a5
    cx = dx;
    dx = ax;
    bx = memoryAGet16(ds, di);
    ax = 0x4200;
    interrupt(0x21);
    dx = di + 0x80;
    cx = 0x0080;
    bx = memoryAGet16(ds, di);
    ah = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_a741;
    ax = 0;
loc_a741: // 0a08:06c1
    bx = 0;
loc_a743: // 0a08:06c3
    if (bx == ax)
        return;
    if (memoryAGet(ds, bx + di + 128) == 0x1a)
        goto loc_a751;
    bx++;
    goto loc_a743;
loc_a751: // 0a08:06d1
    dx = bx;
    dx -= ax;
    cx = 0xffff;
    bx = memoryAGet16(ds, di);
    ax = 0x4202;
    interrupt(0x21);
    cx = 0;
    bx = memoryAGet16(ds, di);
    ah = 0x40;
    interrupt(0x21);
}
// INJECT: Error: cannot inject zero flag in sub_a836()!
void sub_a836() // 0a08:07b6
{
    if (memoryAGet16(ds, 0x1056) != 0x0000)
        goto loc_a845;
    flags.zero = true;
    if (memoryAGet16(es, di + 2) != 0xd7b2)
    {
        flags.zero = false;
        goto loc_a852;
    }
loc_a845: // 0a08:07c5
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 4);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
//    stop(inject ret);
    return;
loc_a852: // 0a08:07d2
    memoryASet16(ds, 0x1056, 0x0069);
    goto loc_a845;
}
void sub_a85a() // 0a08:07da
{
    push(0x7777);
    memoryASet(es, bx + di, al);
    bx++;
    if (bx == dx)
        goto loc_a863;
    assert(pop() == 0x7777);
    return;
loc_a863: // 0a08:07e3
    di = sp;
    tx = di;
    di = memoryAGet16(ss, tx + 2);
    es = memoryAGet16(ss, tx + 2 + 2);
    push(cx);
    push(si);
    push(ds);
    dx = 0x0ba6;
    ds = dx;
    memoryASet16(es, di + 8, bx);
    push(es);
    push(di);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 20 + 2);
    callIndirect(memoryAGet16(es, di + 20 + 2), memoryAGet16(es, di + 20));
    assert(cs == 0x0a08);
    if (!ax)
        goto loc_a884;
    memoryASet16(ds, 0x1056, ax);
loc_a884: // 0a08:0804
    di = pop();
    es = pop();
    ax = memoryAGet16(es, di + 10);
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 4);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    ds = pop();
    si = pop();
    cx = pop();
    assert(pop() == 0x7777);
}
void sub_a8c8() // 0a08:0848
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    sub_a836();
    if (!flags.zero)
        goto loc_a8df;
    al = 0x0d;
    sub_a85a();
    al = 0x0a;
    sub_a85a();
loc_a8df: // 0a08:085f
    di = pop();
    es = pop();
    memoryASet16(es, di + 8, bx);
    sub_a8f9();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a8ec() // 0a08:086c
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    sub_a8f9();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a8f9() // 0a08:0879
{
    if (memoryAGet16(es, di + 26) != 0x0000)
        goto loc_a901;
    return;
loc_a901: // 0a08:0881
    if (memoryAGet16(ds, 0x1056) != 0x0000)
        return;
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 24 + 2);
    callIndirect(memoryAGet16(es, di + 24 + 2), memoryAGet16(es, di + 24));
    assert(cs == 0x0a08);
    if (!ax)
        return;
    memoryASet16(ds, 0x1056, ax);
}
void sub_a935() // 0a08:08b5
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    sub_a836();
    if (!flags.zero)
        goto loc_a955;
    cx = memoryAGet16(ss, bp + 6);
    cx--;
    if ((int16_t)cx <= 0)
        goto loc_a94f;
loc_a948: // 0a08:08c8
    al = 0x20;
    sub_a85a();
    if (--cx)
        goto loc_a948;
loc_a94f: // 0a08:08cf
    al = memoryAGet(ss, bp + 8);
    sub_a85a();
loc_a955: // 0a08:08d5
    di = pop();
    es = pop();
    memoryASet16(es, di + 8, bx);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a997() // 0a08:0917
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    push(es);
    push(di);
    sub_a836();
    if (!flags.zero)
        goto loc_a9ca;
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    cx = memoryAGet16(ss, bp + 6);
    flags.direction = false;
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    tx = cx;
    cx -= ax;
    if ((short)tx - (short)ax <= 0)
        goto loc_a9bf;
loc_a9b3: // 0a08:0933
    al = 0x20;
    sub_a85a();
    if (--cx)
        goto loc_a9b3;
    al = memoryAGet(ds, si + 65535);
    ah = 0;
loc_a9bf: // 0a08:093f
    cx = ax;
    if (cx == 0)
        goto loc_a9ca;
loc_a9c3: // 0a08:0943
    flags.direction = false;
    lodsb<MemAuto, DirAuto>();
    sub_a85a();
    if (--cx)
        goto loc_a9c3;
loc_a9ca: // 0a08:094a
    di = pop();
    es = pop();
    memoryASet16(es, di + 8, bx);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_a9d5() // 0a08:0955
{
    push(0x7777);
    bx = sp;
    dx = ds;
    si = memoryAGet16(ss, bx + 10);
    ds = memoryAGet16(ss, bx + 10 + 2);
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    cx = memoryAGet16(ss, bx + 4);
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_a9f1() // 0a08:0971
{
    si = ax;
    di = dx;
    mul(cx);
    push(ax);
    push(dx);
    ax = si;
    mul(bx);
    bx = ax;
    ax = di;
    mul(cx);
    cx = ax;
    dx = pop();
    ax = pop();
    dx += bx;
    dx += cx;
    cs = pop();
}
void sub_aa0c() // 0a08:098c terminate app!
{
    goto loc_aa0c;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225(); // print runtime error!
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21); // terminate
    //   gap of 2023 bytes
loc_aa0c: // 0a08:098c
    push(bp);
    bp = cx;
    bp |= bx;
    if (!bp)
        goto loc_aa73;
    tx = flags.carry | (flags.zero << 1) | (bp & 0x8000);
    push(tx);
    if (!(bp & 0x8000))
        goto loc_aa22;
    cx = ~cx;
    bx = ~bx;
    flags.carry = (cx + 0x0001) >= 0x10000;
    cx += 0x0001;
    bx += flags.carry;
loc_aa22: // 0a08:09a2
    tx = flags.carry | (flags.zero << 1) | 0;
    push(tx);
    if (!(dx & 0x8000))
        goto loc_aa31;
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_aa31: // 0a08:09b1
    si = cx;
    di = bx;
    cx = 0;
    bx = 0;
    bp = 0x0021;
    flags.carry = 0; // gabo?
loc_aa3c: // 0a08:09bc
    cx = rcl(cx, 0x0001);
    bx = rcl(bx, 0x0001);
    flags.carry = cx < si;
    cx -= si;
    tl = bx < di + flags.carry;
    bx -= di + flags.carry;
    flags.carry = tl;
    if (!tl)
        goto loc_aa4a;
    flags.carry = (cx + si) >= 0x10000;
    cx += si;
    bx += di + flags.carry;
loc_aa4a: // 0a08:09ca
    flags.carry = !flags.carry;
    //stop(/*carry2*/); //gabo?
    ax = rcl(ax, 0x0001);
    dx = rcl(dx, 0x0001);
    tx = bp;
    flags.carry = bp == 0;
    bp--;
    if (tx != 1)
        goto loc_aa3c;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (!(tx & 0x8000))
        goto loc_aa64;
    cx = ~cx;
    bx = ~bx;
    flags.carry = (cx + 0x0001) >= 0x10000;
    cx += 0x0001;
    bx += flags.carry;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (stop(/*1 - jns loc_aa67*/))
        goto loc_aa67;
    goto loc_aa71;
loc_aa64: // 0a08:09e4
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (!(tx & 0x8000))
        goto loc_aa71;
loc_aa67: // 0a08:09e7
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_aa71: // 0a08:09f1
    bp = pop();
    cs = pop();
    return;
loc_aa73: // 0a08:09f3
    bp = pop();
    ax = 0x00c8;
    goto loc_a162;
}
void sub_aaa1() // 0a08:0a21
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    si = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    cl = al;
    ch = 0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_aabb() // 0a08:0a3b
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    si = memoryAGet16(ss, bx + 10);
    ds = memoryAGet16(ss, bx + 10 + 2);
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    cx = memoryAGet16(ss, bx + 4);
    lodsb<MemAuto, DirAuto>();
    if (al <= cl)
        goto loc_aad3;
    al = cl;
loc_aad3: // 0a08:0a53
    stosb<MemAuto, DirAuto>();
    cl = al;
    ch = 0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_aaed() // 0a08:0a6d
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    di = memoryAGet16(ss, bx + 12);
    es = memoryAGet16(ss, bx + 12 + 2);
    si = memoryAGet16(ss, bx + 8);
    ds = memoryAGet16(ss, bx + 8 + 2);
    al = memoryAGet(ds, si);
    ah = 0;
    cx = memoryAGet16(ss, bx + 6);
    if ((short)cx > 0)
        goto loc_ab09;
    cx = 0x0001;
loc_ab09: // 0a08:0a89
    si += cx;
    tx = ax;
    ax -= cx;
    if (tx < cx)
        goto loc_ab22;
    ax++;
    cx = memoryAGet16(ss, bx + 4);
    if ((short)cx >= 0)
        goto loc_ab1a;
    cx = 0;
loc_ab1a: // 0a08:0a9a
    if (ax <= cx)
        goto loc_ab24;
    ax = cx;
    goto loc_ab24;
loc_ab22: // 0a08:0aa2
    ax = 0;
loc_ab24: // 0a08:0aa4
    stosb<MemAuto, DirAuto>();
    cx = ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_ab2e() // 0a08:0aae
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    si = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    cl = memoryAGet(es, di);
    ch = 0;
    lodsb<MemAuto, DirAuto>();
    flags.carry = (memoryAGet(es, di) + al) >= 0x100;
    memoryASet(es, di, memoryAGet(es, di) + al);
    if (!flags.carry)
        goto loc_ab4e;
    memoryASet(es, di, 0xff);
    al = cl;
    al = ~al;
loc_ab4e: // 0a08:0ace
    di += cx;
    di++;
    cl = al;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_aba6() // 0a08:0b26
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    si = memoryAGet16(ss, bx + 8);
    ds = memoryAGet16(ss, bx + 8 + 2);
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    lodsb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    di++;
    cl = al;
    if (cl <= ah)
        goto loc_abc0;
    cl = ah;
loc_abc0: // 0a08:0b40
    if (!cl)
        goto loc_abca;
    ch = 0;
    repe_cmpsb<MemData, MemData, DirAuto>();
    if (!flags.zero)
        goto loc_abcc;
loc_abca: // 0a08:0b4a
    flags.zero = al == ah;
loc_abcc: // 0a08:0b4c
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_abd1() // 0a08:0b51
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    al = 0x01;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, bx + 4);
    stosb<MemAuto, DirAuto>();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_abe3() // 0a08:0b63
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    di = memoryAGet16(ss, bx + 10);
    es = memoryAGet16(ss, bx + 10 + 2);
    si = memoryAGet16(ss, bx + 6);
    ds = memoryAGet16(ss, bx + 6 + 2);
    ax = memoryAGet16(ss, bx + 4);
    stosb<MemAuto, DirAuto>();
    cx = ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_ac52() // 0a08:0bd2
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0200;
    if ((short)memoryAGet16(ss, bp + 6) <= (short)0x0000)
        goto loc_aca2;
    di = bp - 0x100;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    ax = 0x0001;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax--;
    push(ax);
    push(cs);
    sub_aaed();
    di = bp - 0x200;
    push(ss);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    ax = 0x00ff;
    push(ax);
    push(cs);
    sub_aaed();
    push(cs);
    sub_ab2e();
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    ax = 0x00ff;
    push(ax);
    push(cs);
    sub_aabb();
loc_aca2: // 0a08:0c22
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_ad56() // 0a08:0cd6
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    al = memoryAGet(ss, bx + 8);
    bl = al;
    bh = 0;
    cl = 0x03;
    bx >>= cl;
    cl = al;
    cl &= 0x07;
    al = 0x01;
    al <<= cl;
    flags.zero = !(memoryAGet(es, bx + di) & al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_ae02() // 0a08:0d82
{
    di ^= 0x8000;
    sub_ae06();
}
void sub_ae06() // 0a08:0d86
{
    if (!cl)
        goto loc_ae85;
    if (!al)
        goto loc_ae86;
    if (al <= cl)
        goto loc_ae17;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = dx;
    dx = tx;
loc_ae17:
    al -= cl;
    al = -al;
    if (al >= 0x28)
        goto loc_ae86;
    tl = cl;
    cl = al;
    al = tl;
    push(bp);
    push(ax);
    ah = dh;
    ah &= 0x80;
    bp = ax;
    ax ^= di;
    tx = ax;
    ax = pop();
    tx = flags.carry | (flags.zero << 1) | (tx & 0x8000);
    push(tx);
    al = 0x00;
    dh |= 0x80;
    di |= 0x8000;
loc_ae37:
    if (cl < 0x08)
        goto loc_ae4d;
    al = ah; // check! dx = be99 vs b9ee
    ah = bl;
    bl = bh;
    bh = dl;
    dl = dh;
    dh = 0;
    cl -= 0x08;
    goto loc_ae37;
loc_ae4d: // 0a08:0dcd
    if (!cl)
        goto loc_ae5b;
loc_ae51: // 0a08:0dd1
    flags.carry = dx & 1;
    dx >>= 1;
    bx = rcr(bx, 0x0001);
    ax = rcr(ax, 0x0001);
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_ae51;
loc_ae5b: // 0a08:0ddb
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (tx & 0x8000)
        goto loc_ae95;
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    tl = flags.carry;
    flags.carry = (bx + si + tl) >= 0x10000;
    bx += si + tl;
    tl = flags.carry;
    flags.carry = (dx + di + tl) >= 0x10000;
    dx += di + tl;
    cx = bp;
    bp = pop();
    if (!flags.carry)
        goto loc_ae73;
    dx = rcr(dx, 0x0001);
    bx = rcr(bx, 0x0001);
    ax = rcr(ax, 0x0001);
    cl++;
    if (cl == 0)
        goto loc_ae93;
loc_ae73: // 0a08:0df3
    flags.carry = (ax + 0x0080) >= 0x10000;
    ax += 0x0080;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    tl = flags.carry;
    flags.carry = (dx + 0x0000 + tl) >= 0x10000;
    dx += tl;
    if (flags.carry)
        goto loc_ae8d;
loc_ae7e:
    al = cl;
    dh &= 0x7f;
    dh |= ch;
loc_ae85:
    return;
loc_ae86:
    ax = cx;
    bx = si;
    dx = di;
    return;
loc_ae8d:
    stop(/*carry1*/);
    dx = rcr(dx, 0x0001);
    cl++;
    if (cl != 0)
        goto loc_ae7e;
loc_ae93:
    flags.carry = true;
    return;
loc_ae95:// a08:e15
    flags.carry = ax < cx;
    ax -= cx;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = dx < di + flags.carry;
    dx -= di + flags.carry;
    flags.carry = tl;
    cx = bp;
    bp = pop();
    if (!flags.carry)
        goto loc_aeb0;
    dx = ~dx;
    bx = ~bx;
    ax = -ax;
    flags.carry = !flags.carry;
    tl = bx+flags.carry >= 0x10000;
    bx += flags.carry;
    flags.carry = tl;
    tl = dx+flags.carry >= 0x10000;
    dx += flags.carry;
    flags.carry = tl;
    ch ^= 0x80;
loc_aeb0:
    di = dx;
    di |= bx;
    di |= ax;
    if (!di)
        goto loc_ae85;
loc_aeb8:
    if (dh & 0x80)
        goto loc_ae73;
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_aeb8;
    goto loc_afc7;
    //   gap of 254 bytes
loc_afc7: // 0a08:0f47
    ax = 0;
    bx = ax;
    dx = ax;
    stop(/*inject ret*/);
}
// INJECT: Error: cannot inject carry flag in sub_aec9()!
// INJECT: Error: cannot inject carry flag in sub_aec9()!
void sub_aec9() // 0a08:0e49
{
    push(0x7777);
    goto loc_aec9;
loc_aec6: // 0a08:0e46
    goto loc_afc7;
loc_aec9: // 0a08:0e49
    if (!al)
        goto loc_aec6;
    if (!cl)
        goto loc_aec6;
    push(bp);
    bp = dx;
    dx ^= di;
    dx &= 0x8000;
    tl = al;
    al = dl;
    dl = tl;
    flags.carry = (dl + cl) >= 0x100;
    dl += cl;
    dh += al + flags.carry;
    cl = al;
    bp |= 0x8000;
    di |= 0x8000;
    push(dx);
    if (ah)
        goto loc_aef3;
    if (!bx)
        goto loc_af00;
loc_aef3: // 0a08:0e73
    if (ch)
        goto loc_af1f;
    if (si)
        goto loc_af1f;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = bp;
    bp = tx;
loc_af00: // 0a08:0e80
    ax = bp;
    al = ah;
    mul(ch);
    bx = ax;
    ax = bp;
    mul(si);
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    dx += flags.carry;
    cx = dx;
    ax = bp;
    mul(di);
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    dx += flags.carry;
    goto loc_af9a;
loc_af1f: // 0a08:0e9f
    push(di);
    push(si);
    push(cx);
    push(bp);
    push(bx);
    push(ax);
    bp = sp;
    cx = 0;
    al = memoryAGet(ss, bp + 1);
    mul(memoryAGet(ss, bp + 7));
    si = ax;
    di = cx;
    bx = cx;
    ax = memoryAGet16(ss, bp);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    tl = flags.carry;
    flags.carry = (di + dx + tl) >= 0x10000;
    di += dx + tl;
    bx += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 6));
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    tl = flags.carry;
    flags.carry = (di + dx + tl) >= 0x10000;
    di += dx + tl;
    bx += cx + flags.carry;
    si = cx;
    ax = memoryAGet16(ss, bp);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 6));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    di = cx;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    tl = flags.carry;
    flags.carry = (si + dx + tl) >= 0x10000;
    si += dx + tl;
    di += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    tl = flags.carry;
    flags.carry = (si + dx + tl) >= 0x10000;
    si += dx + tl;
    di += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (ax + si) >= 0x10000;
    ax += si;
    dx += di + flags.carry;
    sp += 0x000c;
loc_af9a: // 0a08:0f1a
    tx = bx;
    bx = ax;
    ax = tx;
    cx = pop();
    bp = pop();
    if (dh & 0x80)
        goto loc_afa8;
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    cx--;
loc_afa8: // 0a08:0f28
    cx -= 0x8081;
    flags.carry = (ax + 0x0080) >= 0x10000;
    ax += 0x0080;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    tl = flags.carry;
    flags.carry = (dx + 0x0000 + tl) >= 0x10000;
    dx += tl;
    if (!flags.carry)
        goto loc_afba;
    dx = rcr(dx, 0x0001);
    cx++;
loc_afba: // 0a08:0f3a
    if (ch & 0x40)
        goto loc_afc7;
    cx++;
    al = cl;
    dh ^= ch;
    flags.carry = ch & 1;
    ch >>= 1;
    assert(pop() == 0x7777);
    return;
loc_afc7: // 0a08:0f47
    flags.carry = false;
    ax = 0;
    bx = ax;
    dx = ax;
    assert(pop() == 0x7777);
}
// INJECT: Error: cannot inject carry flag in sub_afce()!
// INJECT: Error: cannot inject carry flag in sub_afce()!
void sub_afce() // 0a08:0f4e
{
    goto loc_afce;
loc_afac: // 0a08:0f2c
    flags.carry = (ax + 0x0080) >= 0x10000;
    ax += 0x0080;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    tl = flags.carry;
    flags.carry = (dx + 0x0000 + tl) >= 0x10000;
    dx += tl;
    if (!flags.carry)
        goto loc_afba;
    dx = rcr(dx, 0x0001);
    cx++;
loc_afba: // 0a08:0f3a
    if (ch & 0x40)
        goto loc_afc7;
    cx++;
    al = cl;
    dh ^= ch;
    flags.carry = ch & 1;
    ch >>= 1;
    return;
loc_afc7: // 0a08:0f47
    ax = 0;
    bx = ax;
    dx = ax;
    flags.carry = 0;
    return;
loc_afce: // 0a08:0f4e
    if (!al)
        goto loc_afc7;
    push(bp);
    bp = dx;
    dx ^= di;
    di |= 0x8000;
    bp |= 0x8000;
    dx &= 0x8000;
    tl = dl;
    dl = al;
    al = tl;
    flags.carry = dl < cl;
    dl -= cl;
    dh -= al + flags.carry;
    push(dx);
    al = 0x02;
    dx = 0x0001;
loc_afef: // 0a08:0f6f
    if (bp != di)
    {
        flags.carry = bp < di;
        goto loc_aff9;
    }
    flags.carry = bx < si;
    if (bx != si)
        goto loc_aff9;
loc_aff9: // 0a08:0f79
    if (flags.carry)
        goto loc_b001;
    flags.carry = ah < ch;
    ah -= ch;
//    stop(/*74*/);
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = bp < di + flags.carry;
    bp -= di + flags.carry;
loc_b001: // 0a08:0f81
    dx = rcl(dx, 0x0001);
    if (flags.carry)
        goto loc_b016;
loc_b005: // 0a08:0f85
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    bp = rcl(bp, 0x0001);
    if (!flags.carry)
        goto loc_afef;
    flags.carry = ah < ch;
    ah -= ch;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = bp < di + flags.carry;
    bp -= di + flags.carry;
    flags.carry = false;
    goto loc_b001;
loc_b016: // 0a08:0f96
    tl = al;
    al--;
    if ((char)al < 0)
        goto loc_b024;
    push(dx);
    dx = 0x0001;
    if (tl != 1)
        goto loc_b005;
    dl = 0x40;
    goto loc_b005;
loc_b024: // 0a08:0fa4
    ax = dx;
    cl = 0x06;
    ax <<= cl;
    bx = pop();
    dx = pop();
    cx = pop();
    bp = pop();
    ax = ~ax;
    bx = ~bx;
    dx ^= 0xffff;
    if (dx & 0x8000)
        goto loc_b03e;
    ax = rcl(ax, 0x0001);
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    cx--;
loc_b03e: // 0a08:0fbe
    cx += 0x8080;
    goto loc_afac;
}
// INJECT: Error: cannot inject carry flag in sub_b045()!
// INJECT: Error: cannot inject carry flag in sub_b045()!
// INJECT: Error: cannot inject flag in sub_b045() because of being label!
void sub_b045() // 0a08:0fc5
{
    push(dx);
    dx ^= di;
    dx = pop();
    flags.carry = false;
    if (!(dx & 0x8000))
        goto loc_b050;
    push(dx);
    flags.carry = !!(dx & 0x8000);
    dx = rcl(dx, 0x0001);
    dx = pop();
    return;
loc_b050: // 0a08:0fd0
    if (!(dh & 0x80))
        goto loc_b05c;
    sub_b05c();
    if (flags.zero)
        goto loc_b06e;
    flags.carry = !flags.carry;
    stop(/*inject ret*/);
    return;
loc_b05c: // 0a08:0fdc
    if (al != cl)
    {
        flags.carry = al < cl;
        goto loc_b06e;
    }
    if (!al)
    {
        flags.carry = false;
        goto loc_b06e;
    }
    if (dx != di)
    {
        flags.carry = dx < di;
        goto loc_b06e;
    }
    if (bx != si)
    {
        flags.carry = bx < si;
        goto loc_b06e;
    }
    flags.carry = ch < cl;
loc_b06e: // 0a08:0fee
    return;
}
// INJECT: Error: cannot inject flag in sub_b05c() because of being label!
void sub_b05c() // 0a08:0fdc
{
    if (al != cl)
        goto loc_b06e;
    if (!al)
        goto loc_b06e;
    if (dx != di)
        goto loc_b06e;
    if (bx != si)
        goto loc_b06e;
loc_b06e: // 0a08:0fee
    stop(/*inject ret*/);
}
void sub_b06f() // 0a08:0fef
{
    bx = ax;
    bx |= dx;
    if (!bx)
        return;
    ch = dh;
    if (!(dx & 0x8000))
        goto loc_b085;
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_b085: // 0a08:1005
    bx = ax;
    ax = 0x00a0;
    if (dx)
        goto loc_b09a;
    tx = bx;
    bx = dx;
    dx = tx;
    al = 0x90;
    if (dh)
        goto loc_b09a;
    tl = dl;
    dl = dh;
    dh = tl;
    al = 0x88;
loc_b09a: // 0a08:101a
    if (dx & 0x8000)
        goto loc_b0a6;
loc_b09e: // 0a08:101e
    al--;
    flags.carry = (bx + bx) >= 0x10000;
    bx += bx;
    dx += dx + flags.carry;
    if ((short)dx >= 0)
        goto loc_b09e;
loc_b0a6: // 0a08:1026
    if (ch & 0x80)
        return;
    dh &= 0x7f;
}
// INJECT: Error: cannot inject carry flag in sub_b0ae()!
void sub_b0ae() // 0a08:102e
{
    tx = bx;
    bx = ax;
    ax = tx;
    cl = 0x9f;
    tl = cl;
    cl -= bl;
    if (tl < bl)
        goto loc_b103;
    if (cl > 0x1f)
        goto loc_b105;
    cl++;
    bh = dh;
    dh |= 0x80;
    if (cl < 0x11)
        goto loc_b0cd;
    ax = dx;
    dx = 0;
    cl -= 0x10;
loc_b0cd: // 0a08:104d
    if (cl < 0x09)
        goto loc_b0dd;
    al = ah;
    ah = dl;
    dl = dh;
    dh = 0;
    cl -= 0x08;
loc_b0dd: // 0a08:105d
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = cl == 0;
    cl--;
    if (cl != 0)
        goto loc_b0dd;
    if (!flags.carry)
        goto loc_b0f3;
    if (!ch)
        goto loc_b0f3;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    if ((short)dx < 0)
        goto loc_b103;
loc_b0f3: // 0a08:1073
    if (!(bh & 0x80))
        goto loc_b101;
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_b101: // 0a08:1081
    flags.carry = false;
    return;
loc_b103: // 0a08:1083
    flags.carry = true;
    return;
loc_b105: // 0a08:1085
    flags.carry = false;
    ax = 0;
    dx = 0;
    stop(/*inject ret*/);
}
void sub_b10a() // 0a08:108a
{
    goto loc_b10a;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3813 bytes
loc_b10a: // 0a08:108a
    sub_ae06();
    if (flags.carry)
        goto loc_b14a;
    cs = pop();
    return;
    //   gap of 58 bytes
loc_b14a: // 0a08:10ca
    ax = 0x00cd;
    goto loc_a162;
}
void sub_b110() // 0a08:1090
{
    goto loc_b110;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3819 bytes
loc_b110: // 0a08:1090
    sub_ae02();
    if (flags.carry)
        goto loc_b14a;
    cs = pop();
    return;
    //   gap of 52 bytes
loc_b14a: // 0a08:10ca
    ax = 0x00cd;
    goto loc_a162;
}
void sub_b11c() // 0a08:109c
{
    goto loc_b11c;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3831 bytes
loc_b11c: // 0a08:109c
    sub_aec9();
    if (flags.carry)
        goto loc_b14a;
    cs = pop();
    return;
    //   gap of 40 bytes
loc_b14a: // 0a08:10ca
    ax = 0x00cd;
    goto loc_a162;
}
void sub_b122() // 0a08:10a2
{
    goto loc_b122;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3837 bytes
loc_b122: // 0a08:10a2
    if (!cl)
        goto loc_b150;
    sub_afce();
    if (flags.carry)
        goto loc_b14a;
    cs = pop();
    return;
    //   gap of 30 bytes
loc_b14a: // 0a08:10ca
    ax = 0x00cd;
    goto loc_a162;
loc_b150: // 0a08:10d0
    ax = 0x00c8;
    goto loc_a162;
}
// INJECT: Error: cannot inject zero flag in sub_b12c() because no traceback!
void sub_b12c() // 0a08:10ac
{
    sub_b045();
    cs = pop();
}
void sub_b130() // 0a08:10b0
{
    sub_b06f();
    cs = pop();
}
void sub_b13c() // 0a08:10bc
{
    goto loc_b13c;
loc_a162: // 0a08:00e2
    stop(/*override stack*/);
    cx = pop();
    bx = pop();
    goto loc_a16d;
    //   gap of 7 bytes
loc_a16d: // 0a08:00ed
    dx = 0x0ba6;
    ds = dx;
    flags.interrupts = true;
    memoryASet16(ds, 0x104c, ax);
    ax = cx;
    ax |= bx;
    if (!ax)
        goto loc_a19b;
    ax = memoryAGet16(ds, 0x102a);
loc_a17f: // 0a08:00ff
    if (!ax)
        goto loc_a194;
    es = ax;
    if (bx == memoryAGet16(es, 0x0010))
        goto loc_a192;
    ax = memoryAGet16(es, 0x0014);
    goto loc_a17f;
loc_a192: // 0a08:0112
    bx = es;
loc_a194: // 0a08:0114
    bx -= memoryAGet16(ds, 0x1052);
    bx -= 0x0010;
loc_a19b: // 0a08:011b
    memoryASet16(ds, 0x104e, cx);
    memoryASet16(ds, 0x1050, bx);
    bx = memoryAGet16(ds, 0x1048);
    es = memoryAGet16(ds, 0x1048 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_a1c0;
    ax = 0;
    memoryASet16(ds, 0x1048, ax);
    memoryASet16(ds, 0x104a, ax);
    memoryASet16(ds, 0x1056, ax);
    ax = 0x0123;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_a1c0: // 0a08:0140
    ax = 0x234a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    ax = 0x244a;
    push(ds);
    push(ax);
    push(cs);
    sub_a63f();
    di = 0x254a;
    si = 0x01ee;
    cx = 0x0013;
loc_a1dc: // 0a08:015c
    flags.direction = false;
    lodsb_cs<MemAuto, DirAuto>();
    ah = 0x25;
    push(ds);
    dx = memoryAGet16(ds, di);
    ds = memoryAGet16(ds, di + 2);
    interrupt(0x21);
    ds = pop();
    di += 0x0004;
    if (--cx)
        goto loc_a1dc;
    ax = memoryAGet16(ds, 0x104e);
    ax |= memoryAGet16(ds, 0x1050);
    if (!ax)
        goto loc_a21e;
    bx = 0x0201;
    sub_a225();
    ax = memoryAGet16(ds, 0x104c);
    sub_a233();
    bx = 0x0210;
    sub_a225();
    ax = memoryAGet16(ds, 0x1050);
    sub_a24d();
    al = 0x3a;
    sub_a267();
    ax = memoryAGet16(ds, 0x104e);
    sub_a24d();
    bx = 0x0215;
    sub_a225();
loc_a21e: // 0a08:019e
    ax = memoryAGet16(ds, 0x104c);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3863 bytes
loc_b13c: // 0a08:10bc
    ch = 0x01;
    sub_b0ae();
    if (flags.carry)
        goto loc_b144;
    cs = pop();
    return;
loc_b144: // 0a08:10c4
    ax = 0x00cf;
    goto loc_a162;
}
void sub_b156() // 0a08:10d6
{
    push(di);
    push(si);
    push(cx);
    sub_ae06();
    cx = pop();
    si = pop();
    di = pop();
}
void sub_b160() // 0a08:10e0
{
    push(di);
    push(si);
    push(cx);
    sub_ae02();
    cx = pop();
    si = pop();
    di = pop();
}
void sub_b16a() // 0a08:10ea
{
    push(di);
    push(si);
    push(cx);
    sub_aec9();
    cx = pop();
    si = pop();
    di = pop();
}
void sub_b174() // 0a08:10f4
{
    push(di);
    push(si);
    push(cx);
    sub_afce();
    cx = pop();
    si = pop();
    di = pop();
}
void sub_b17e() // 0a08:10fe
{
    if (al >= 0xa8)
        goto loc_b1cb;
    cx = ax;
    si = bx;
    di = dx;
    ah = 0;
    bx = 0;
    dx = 0;
    tl = cl;
    cl -= 0x80;
    if (tl <= 0x80)
        goto loc_b1cc;
loc_b193: // 0a08:1113
    if (cl < 0x10)
        goto loc_b1a4;
    ah = bh;
    bx = dx;
    dx = 0xffff;
    cl -= 0x10;
    goto loc_b193;
loc_b1a4: // 0a08:1124
    if (cl < 0x08)
        goto loc_b1b6;
    ah = bl;
    bl = bh;
    bh = dl;
    dl = dh;
    dh = 0xff;
    cl -= 0x08;
loc_b1b6: // 0a08:1136
    if (!cl)
        goto loc_b1c5;
loc_b1ba: // 0a08:113a
    flags.carry = true;
    dx = rcr(dx, 0x0001);
    bx = rcr(bx, 0x0001);
    ah = rcr(ah, 0x01);
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_b1ba;
loc_b1c5: // 0a08:1145
    dx &= di;
    bx &= si;
    ah &= ch;
loc_b1cb: // 0a08:114b
    cs = pop();
    return;
loc_b1cc: // 0a08:114c
    al = 0;
    cs = pop();
}
void sub_b1cf() // 0a08:114f
{
    push(dx);
    push(bx);
    push(ax);
    push(cs);
    sub_b17e();
    cx = ax;
    si = bx;
    di = dx;
    ax = pop();
    bx = pop();
    dx = pop();
    sub_ae02();
    cs = pop();
}
void sub_b242() // 0a08:11c2
{
    cx = 0x2181;
    si = 0xdaa2;
    di = 0xc90f;
    sub_ae06();
    if (!al)
        goto loc_b255;
    dh ^= 0x80;
loc_b255: // 0a08:11d5
    if (al < 0x6c)
        goto loc_b2b5;
    cx = 0x2183;
    si = 0xdaa2;
    di = 0x490f;
    push(dx);
    dh &= 0x7f;
    sub_b045();
    dx = pop();
    if (flags.carry)
        goto loc_b27c;
    sub_b174();
    push(di);
    push(si);
    push(cx);
    push(cs);
    sub_b1cf();
    cx = pop();
    si = pop();
    di = pop();
    sub_b16a();
loc_b27c: // 0a08:11fc
    if (!(dh & 0x80))
        goto loc_b284;
    sub_b156();
loc_b284: // 0a08:1204
    cl--;
    sub_b045();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    if (flags.carry)
        goto loc_b28f;
    sub_b160();
loc_b28f: // 0a08:120f
    cl--;
    sub_b045();
    if (flags.carry)
        goto loc_b29e;
    cl++;
    dh |= 0x80;
    sub_ae06();
loc_b29e: // 0a08:121e
    if (al < 0x6c)
        goto loc_b2ab;
    di = 0x1236;
    cx = 0x0007;
    sub_b561();
loc_b2ab: // 0a08:122b
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (flags.carry)
        goto loc_b2b5;
    if (!al)
        goto loc_b2b5;
    dh ^= 0x80;
loc_b2b5: // 0a08:1235
    cs = pop();
}
void sub_b255() // 0a08:11d5
{
    if (al < 0x6c)
        goto loc_b2b5;
    cx = 0x2183;
    si = 0xdaa2;
    di = 0x490f;
    push(dx);
    dh &= 0x7f;
    sub_b045();
    dx = pop();
    if (flags.carry)
        goto loc_b27c;
    sub_b174();
    push(di);
    push(si);
    push(cx);
    push(cs);
    sub_b1cf();
    cx = pop();
    si = pop();
    di = pop();
    sub_b16a();
loc_b27c: // 0a08:11fc
    if (!(dh & 0x80))
        goto loc_b284;
    sub_b156();
loc_b284: // 0a08:1204
    cl--;
    sub_b045();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    if (flags.carry)
        goto loc_b28f;
    sub_b160();
loc_b28f: // 0a08:120f
    cl--;
    sub_b045();
    if (flags.carry)
        goto loc_b29e;
    cl++;
    dh |= 0x80;
    sub_ae06();
loc_b29e: // 0a08:121e
    if (al < 0x6c)
        goto loc_b2ab;
    di = 0x1236;
    cx = 0x0007;
    sub_b561();
loc_b2ab: // 0a08:122b
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (flags.carry)
        goto loc_b2b5;
    if (!al)
        goto loc_b2b5;
    dh ^= 0x80;
loc_b2b5: // 0a08:1235
    cs = pop();
}
void sub_b561() // 0a08:14e1
{
    push(0x7777);
    goto loc_b561;
loc_aec6: // 0a08:0e46
    goto loc_afc7;
loc_aec9: // 0a08:0e49
    if (!al)
        goto loc_aec6;
    if (!cl)
        goto loc_aec6;
    push(bp);
    bp = dx;
    dx ^= di;
    dx &= 0x8000;
    tl = al;
    al = dl;
    dl = tl;
    flags.carry = (dl + cl) >= 0x100;
    dl += cl;
    dh += al + flags.carry;
    cl = al;
    bp |= 0x8000;
    di |= 0x8000;
    push(dx);
    if (ah)
        goto loc_aef3;
    if (!bx)
        goto loc_af00;
loc_aef3: // 0a08:0e73
    if (ch)
        goto loc_af1f;
    if (si)
        goto loc_af1f;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = bp;
    bp = tx;
loc_af00: // 0a08:0e80
    ax = bp;
    al = ah;
    mul(ch);
    bx = ax;
    ax = bp;
    mul(si);
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    dx += flags.carry;
    cx = dx;
    ax = bp;
    mul(di);
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    dx += flags.carry;
    goto loc_af9a;
loc_af1f: // 0a08:0e9f
    push(di);
    push(si);
    push(cx);
    push(bp);
    push(bx);
    push(ax);
    bp = sp;
    cx = 0;
    al = memoryAGet(ss, bp + 1);
    mul(memoryAGet(ss, bp + 7));
    si = ax;
    di = cx;
    bx = cx;
    ax = memoryAGet16(ss, bp);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    tl = flags.carry;
    flags.carry = (di + dx + tl) >= 0x10000;
    di += dx + tl;
    bx += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 6));
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    tl = flags.carry;
    flags.carry = (di + dx + tl) >= 0x10000;
    di += dx + tl;
    bx += cx + flags.carry;
    si = cx;
    ax = memoryAGet16(ss, bp);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 6));
    flags.carry = (di + ax) >= 0x10000;
    di += ax;
    tl = flags.carry;
    flags.carry = (bx + dx + tl) >= 0x10000;
    bx += dx + tl;
    si += cx + flags.carry;
    di = cx;
    ax = memoryAGet16(ss, bp + 2);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    tl = flags.carry;
    flags.carry = (si + dx + tl) >= 0x10000;
    si += dx + tl;
    di += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 8));
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    tl = flags.carry;
    flags.carry = (si + dx + tl) >= 0x10000;
    si += dx + tl;
    di += cx + flags.carry;
    ax = memoryAGet16(ss, bp + 4);
    mul(memoryAGet16(ss, bp + 10));
    flags.carry = (ax + si) >= 0x10000;
    ax += si;
    dx += di + flags.carry;
    sp += 0x000c;
loc_af9a: // 0a08:0f1a
    tx = bx;
    bx = ax;
    ax = tx;
    cx = pop();
    bp = pop();
    if (dh & 0x80)
        goto loc_afa8;
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    cx--;
loc_afa8: // 0a08:0f28
    cx -= 0x8081;
    flags.carry = (ax + 0x0080) >= 0x10000;
    ax += 0x0080;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    tl = flags.carry;
    flags.carry = (dx + 0x0000 + tl) >= 0x10000;
    dx += tl;
    if (!flags.carry)
        goto loc_afba;
    dx = rcr(dx, 0x0001);
    cx++;
loc_afba: // 0a08:0f3a
    if (ch & 0x40)
        goto loc_afc7;
    cx++;
    al = cl;
    dh ^= ch;
    ch >>= 1;
    assert(pop() == 0x7777);
    return;
loc_afc7: // 0a08:0f47
    ax = 0;
    bx = ax;
    dx = ax;
    assert(pop() == 0x7777);
    return;
    //   gap of 1427 bytes
loc_b561: // 0a08:14e1
    push(dx);
    push(bx);
    push(ax);
    push(cx);
    push(di);
    cx = ax;
    si = bx;
    di = dx;
    sub_aec9();
    di = pop();
    cx = pop();
    sub_b57a();
    cx = pop();
    si = pop();
    di = pop();
    goto loc_aec9;
}
void sub_b57a() // 0a08:14fa
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, bx);
    memoryASet16(ss, bp - 2, dx);
    ax = memoryAGet16(cs, di);
    bx = memoryAGet16(cs, di + 2);
    dx = memoryAGet16(cs, di + 4);
    push(cx);
    push(di);
    goto loc_b5a8;
loc_b598: // 0a08:1518
    push(cx);
    push(di);
    cx = memoryAGet16(cs, di);
    si = memoryAGet16(cs, di + 2);
    di = memoryAGet16(cs, di + 4);
    sub_ae06();
loc_b5a8: // 0a08:1528
    cx = memoryAGet16(ss, bp - 6);
    si = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp - 2);
    sub_aec9();
    di = pop();
    cx = pop();
    di += 0x0006;
    if (--cx)
        goto loc_b598;
    cx = 0x0081;
    si = 0;
    di = 0;
    sub_ae06();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b5c9() // 0a08:1549
{
    push(0x7777);
    sub_b618();
    ax = 0;
    bx = sp;
    bx = memoryAGet16(ss, bx + 4);
    if (!bx)
        goto loc_b5dc;
    tx = dx;
    dx = ax;
    ax = tx;
    div(bx);
    tx = dx;
    dx = ax;
    ax = tx;
loc_b5dc: // 0a08:155c
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_b618() // 0a08:1598
{
    ax = memoryAGet16(ds, 0x1058);
    bx = memoryAGet16(ds, 0x105a);
    cx = ax;
    mul(memoryAGet16(cs, 0x15ce));
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    ch += cl;
    dx += cx;
    dx += bx;
    bx <<= 1;
    bx <<= 1;
    dx += bx;
    dh += bl;
    cl = 0x05;
    bx <<= cl;
    dh += bl;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    memoryASet16(ds, 0x1058, ax);
    memoryASet16(ds, 0x105a, dx);
}
void sub_b650() // 0a08:15d0
{
    ah = 0x2c;
    interrupt(0x21);
    memoryASet16(ds, 0x1058, cx);
    memoryASet16(ds, 0x105a, dx);
    cs = pop();
}
void sub_b65d() // 0a08:15dd
{
    push(di);
    flags.direction = false;
    bx = ax;
    if ((short)dx >= 0)
        goto loc_b672;
    bx = ~bx;
    dx = ~dx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    dx += flags.carry;
    al = 0x2d;
    stosb<MemAuto, DirAuto>();
loc_b672: // 0a08:15f2
    si = 0x162f;
    cl = 0x09;
loc_b677: // 0a08:15f7
    if (dx < memoryAGet16(cs, si + 2))
        goto loc_b684;
    if (dx > memoryAGet16(cs, si + 2))
        goto loc_b68b;
    if (bx >= memoryAGet16(cs, si))
        goto loc_b68b;
loc_b684: // 0a08:1604
    si += 0x0004;
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_b677;
loc_b68b: // 0a08:160b
    cl++;
loc_b68d: // 0a08:160d
    al = 0x2f;
loc_b68f: // 0a08:160f
    al++;
    flags.carry = bx < memoryAGet16(cs, si);
    bx -= memoryAGet16(cs, si);
    tl = dx <  memoryAGet16(cs, si + 2) + flags.carry;
    dx -= memoryAGet16(cs, si + 2) + flags.carry;
    flags.carry = tl;
    if (!flags.carry)
        goto loc_b68f;
    flags.carry = (bx + memoryAGet16(cs, si)) >= 0x10000;
    bx += memoryAGet16(cs, si);
    dx += memoryAGet16(cs, si + 2) + flags.carry;
    si += 0x0004;
    stosb<MemAuto, DirAuto>();
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_b68d;
    cx = di;
    di = pop();
    cx -= di;
}
void sub_b76f() // 0a08:16ef
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0020;
    ax = memoryAGet16(ss, bp + 14);
    dx = memoryAGet16(ss, bp + 16);
    di = bp - 0x20;
    push(ss);
    es = pop();
    sub_b65d();
    push(ds);
    si = di;
    push(ss);
    ds = pop();
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 12);
    if ((short)ax <= (short)dx)
        goto loc_b797;
    ax = dx;
loc_b797: // 0a08:1717
    if ((short)cx <= (short)dx)
        goto loc_b79d;
    cx = dx;
loc_b79d: // 0a08:171d
    if ((short)ax >= (short)cx)
        goto loc_b7a3;
    ax = cx;
loc_b7a3: // 0a08:1723
    flags.direction = false;
    stosb<MemAuto, DirAuto>();
    ax -= cx;
    if (ax == 0)
        goto loc_b7b1;
    push(cx);
    cx = ax;
    al = 0x20;
    rep_stosb<MemAuto, DirAuto>();
    cx = pop();
loc_b7b1: // 0a08:1731
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 12;
}
void sub_b7eb() // 0a08:176b
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    si = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    flags.direction = false;
    ax = 0;
    stosw<MemAuto, DirAuto>();
    ax = 0xd7b0;
    stosw<MemAuto, DirAuto>();
    ax = 0;
    cx = 0x0016;
    rep_stosw<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    if (al <= 0x4f)
        goto loc_b80c;
    al = 0x4f;
loc_b80c: // 0a08:178c
    cl = al;
    ch = 0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_b819() // 0a08:1799
{
    push(0x7777);
    al = memoryAGet(ds, 0x105c);
    ah = 0x3d;
    dx = 0;
    goto loc_b828;
    //   gap of 6 bytes
loc_b828: // 0a08:17a8
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, di + 2) == 0xd7b0)
        goto loc_b850;
    if (memoryAGet16(es, di + 2) == 0xd7b3)
        goto loc_b846;
    memoryASet16(ds, 0x1056, 0x0066);
    goto loc_b87a;
loc_b846: // 0a08:17c6
    push(ax);
    push(dx);
    push(es);
    push(di);
    push(cs);
    sub_b89a();
    dx = pop();
    ax = pop();
loc_b850: // 0a08:17d0
    if (memoryAGet(es, di + 48) == 0x00)
        goto loc_b869;
    push(ds);
    dx = di + 0x30;
    push(es);
    ds = pop();
    cx = 0;
    interrupt(0x21);
    ds = pop();
    if (!flags.carry)
        goto loc_b86a;
    memoryASet16(ds, 0x1056, ax);
    goto loc_b87a;
loc_b869: // 0a08:17e9
    tx = dx;
    dx = ax;
    ax = tx;
loc_b86a: // 0a08:17ea
    memoryASet16(es, di + 2, 0xd7b3);
    memoryASet16(es, di, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, di + 4, ax);
loc_b87a: // 0a08:17fa
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_b822() // 0a08:17a2
{
    push(0x7777);
    ax = 0x3c00;
    dx = 0x0001;
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, di + 2) == 0xd7b0)
        goto loc_b850;
    if (memoryAGet16(es, di + 2) == 0xd7b3)
        goto loc_b846;
    memoryASet16(ds, 0x1056, 0x0066);
    goto loc_b87a;
loc_b846: // 0a08:17c6
    push(ax);
    push(dx);
    push(es);
    push(di);
    push(cs);
    sub_b89a();
    dx = pop();
    ax = pop();
loc_b850: // 0a08:17d0
    if (memoryAGet(es, di + 48) == 0x00)
        goto loc_b869;
    push(ds);
    dx = di + 0x30;
    push(es);
    ds = pop();
    cx = 0;
    interrupt(0x21);
    ds = pop();
    if (!flags.carry)
        goto loc_b86a;
    memoryASet16(ds, 0x1056, ax);
    goto loc_b87a;
loc_b869: // 0a08:17e9
    tx = dx;
    dx = ax;
    ax = tx;
loc_b86a: // 0a08:17ea
    memoryASet16(es, di + 2, 0xd7b3);
    memoryASet16(es, di, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, di + 4, ax);
loc_b87a: // 0a08:17fa
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_b89a() // 0a08:181a
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    sub_b8bf();
    if (!flags.zero)
        goto loc_b8bc;
    bx = memoryAGet16(es, di);
    if (bx <= 0x0004)
        goto loc_b8b6;
    ah = 0x3e;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_b8b6;
    memoryASet16(ds, 0x1056, ax);
loc_b8b6: // 0a08:1836
    memoryASet16(es, di + 2, 0xd7b0);
loc_b8bc: // 0a08:183c
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
// INJECT: Error: cannot inject flag in sub_b8bf() because of being label!
void sub_b8bf() // 0a08:183f
{
    if (memoryAGet16(es, di + 2) == 0xd7b3)
    {
        flags.zero = true;
        goto loc_b8cd;
    }
    flags.zero = false;
    memoryASet16(ds, 0x1056, 0x0067);
loc_b8cd: // 0a08:184d
    return;
}
void sub_b8ce() // 0a08:184e
{
    push(0x7777);
    ah = 0x3f;
    dx = 0x0064;
    goto loc_b8da;
    //   gap of 5 bytes
loc_b8da: // 0a08:185a
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    sub_b8bf();
    if (!flags.zero)
        goto loc_b900;
    push(ds);
    push(dx);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    cx = memoryAGet16(es, di + 4);
    bx = memoryAGet16(es, di);
    interrupt(0x21);
    dx = pop();
    ds = pop();
    if (flags.carry)
        goto loc_b8fd;
    if (ax == cx)
        goto loc_b900;
    ax = dx;
loc_b8fd: // 0a08:187d
    memoryASet16(ds, 0x1056, ax);
loc_b900: // 0a08:1880
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_b8d5() // 0a08:1855
{
    push(0x7777);
    ah = 0x40;
    dx = 0x0065;
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    sub_b8bf();
    if (!flags.zero)
        goto loc_b900;
    push(ds);
    push(dx);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    cx = memoryAGet16(es, di + 4);
    bx = memoryAGet16(es, di);
    interrupt(0x21);
    dx = pop();
    ds = pop();
    if (flags.carry)
        goto loc_b8fd;
    if (ax == cx)
        goto loc_b900;
    ax = dx;
loc_b8fd: // 0a08:187d
    memoryASet16(ds, 0x1056, ax);
loc_b900: // 0a08:1880
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_b904() // 0a08:1884
{
    push(0x7777);
    bl = 0x3f;
    cx = 0x0064;
    goto loc_b910;
    //   gap of 5 bytes
loc_b910: // 0a08:1890
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 16);
    es = memoryAGet16(ss, bp + 16 + 2);
    sub_b8bf();
    if (!flags.zero)
        goto loc_b95a;
    ax = memoryAGet16(ss, bp + 10);
    if (!ax)
        goto loc_b93e;
    push(ds);
    push(cx);
    mul(memoryAGet16(es, di + 4));
    cx = ax;
    dx = memoryAGet16(ss, bp + 12);
    ds = memoryAGet16(ss, bp + 12 + 2);
    ah = bl;
    bx = memoryAGet16(es, di);
    interrupt(0x21);
    cx = pop();
    ds = pop();
    if (flags.carry)
        goto loc_b957;
    dx = 0;
    div(memory16(es, di + 4));
loc_b93e: // 0a08:18be
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = es;
    dx |= di;
    if (!dx)
        goto loc_b94c;
    memoryASet16(es, di, ax);
    goto loc_b968;
loc_b94c: // 0a08:18cc
    if (ax == memoryAGet16(ss, bp + 10))
        goto loc_b968;
    memoryASet16(ds, 0x1056, cx);
    goto loc_b968;
loc_b957: // 0a08:18d7
    memoryASet16(ds, 0x1056, ax);
loc_b95a: // 0a08:18da
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = es;
    dx |= di;
    if (!dx)
        goto loc_b968;
    ax = 0;
    memoryASet16(es, di, ax);
loc_b968: // 0a08:18e8
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 14;
}
void sub_b9b3() // 0a08:1933
{
    push(0x7777); // TODO: FIX STACK GABO!!!
    sub_b9e3();
    assert(ax == 0 && bx == 0 && cx == 0x15b2 && dx == 0);
    if (flags.carry)
        goto loc_b9cb;
    ax = cx;
    dx = bx;
    cx = memoryAGet16(es, di + 4);
    if (cx == 0x0001)
        goto loc_b9cb;
    bx = 0;
    push(cs);
    sub_aa0c();
loc_b9cb: // 0a08:194b
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
// INJECT: Error: cannot inject carry flag in sub_b9e3()!
void sub_b9e3() // 0a08:1963
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    if (memoryAGet16(es, di + 2) != 0xd7b3)
        goto loc_ba1c;
    cx = 0;
    dx = 0;
    bx = memoryAGet16(es, di);
    ax = 0x4201;
    interrupt(0x21);
    push(dx);
    push(ax);
    cx = 0;
    dx = 0;
    bx = memoryAGet16(es, di);
    ax = 0x4202;
    interrupt(0x21);
    bx = pop();
    cx = pop();
    push(dx);
    push(ax);
    dx = bx;
    bx = memoryAGet16(es, di);
    ax = 0x4200;
    interrupt(0x21);
    cx = pop();
    bx = pop();
    flags.carry = false;
    assert(pop() == 0x7777);
    return;
loc_ba1c: // 0a08:199c
    memoryASet16(ds, 0x1056, 0x0067);
    ax = 0;
    dx = 0;
    flags.carry = true;
    assert(pop() == 0x7777);
}
void sub_ba28() // 0a08:19a8
{
    push(0x7777);
    bx = sp;
    dx = ds;
    si = memoryAGet16(ss, bx + 10);
    ds = memoryAGet16(ss, bx + 10 + 2);
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    cx = memoryAGet16(ss, bx + 4);
    flags.direction = false;
    if (si >= di)
        goto loc_ba44;
    si += cx;
    di += cx;
    si--;
    di--;
    flags.direction = true;
loc_ba44: // 0a08:19c4
    rep_movsb<MemAuto, MemAuto, DirAuto>(); // WRITES CODE TO 7fe:0000
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_ba4b() // 0a08:19cb
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    cx = memoryAGet16(ss, bx + 6);
    al = memoryAGet(ss, bx + 4);
    flags.direction = false;
    rep_stosb<MemAuto, DirAuto>();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
