#include "cicoctx.h"
using namespace CicoContext;
int cdmanStartupLevel = 4;
void sub_13ec7();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    cs = 0x13ec;
    ds = 0x13dc;
    es = 0x13dc;
    ss = 0x1000;
    sp = 0x0200;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/cdman/dos", "CD-MAN.EXE", 33952);
    sub_13ec7();
}
void sub_13ec7();
void sub_13f3d();
void sub_13fee();
void sub_140c1();
void sub_140f6();
void sub_14119();
void sub_141d6();
void sub_1431e();
void sub_14332();
void sub_14396();
void sub_143fa();
void sub_1444f();
void sub_14521();
void sub_1456e();
void sub_14587();
void sub_14601();
void sub_1461b();
void sub_14639();
void sub_14791();
void sub_147ba();
void sub_147e7();
void sub_1487f();
void sub_14ba3();
void sub_14bfa();
void sub_14ce4();
void sub_14d8c();
void sub_14e49();
void sub_14e74();
void sub_14ee9();
void sub_14f52();
void sub_14fb4();
void sub_15079();
void sub_15097();
void sub_150e5();
void sub_1514d();
void sub_15248();
void sub_152b4();
void sub_152c7();
void sub_153f0();
void sub_154aa();
void sub_154e6();
void sub_1556b();
void sub_155c9();
void sub_155e2();
void sub_1564c();
void sub_15666();
void sub_1568b();
void sub_15697();
void sub_156e7();
void sub_158e0();
void sub_158ec();
void sub_158f3();
void sub_159b3();
void sub_15b67();
void sub_15c46();
void sub_15c79();
void sub_15c9a();
void sub_15cb2();
void sub_15cc3();
void sub_15cc8();
void sub_15d2b();
void sub_15d31();
void sub_15d57();
void sub_15d7c();
void sub_15daa();
void sub_15db2();
void sub_15dfa();
void sub_15e6f();
void sub_15ecc();
void sub_15edd();
void sub_15f15();
void sub_15f3a();
void sub_15f62();
void sub_15fa8();
void sub_15fc4();
void sub_1602f();
void sub_1610e();
void sub_16138();
void sub_1616a();
void sub_16184();
void sub_161b6();
void sub_161d8();
void sub_16202();
void sub_16216();
void sub_1622f();
void sub_1623a();
void sub_16299();
void sub_162cc();
void sub_162ff();
void sub_16332();
void sub_16365();
void sub_16398();
void sub_163cb();
void sub_163fe();
void sub_16431();
void sub_164bf();
void sub_165e5();
void sub_16703();
void sub_167c7();
void sub_1680d();
void sub_168f2();
void sub_16919();
void sub_16998();
void sub_16a07();
void sub_16a2a();
void sub_16a4d();
void sub_16ca8();
void sub_16ccd();
void sub_16d16();
void sub_16e1b();
void sub_16e59();
void sub_16f07();
void sub_16f47();
void sub_16f87();
void sub_16fab();
void sub_16fd3();
void sub_17192();
void sub_171af();
void sub_172b1();
void sub_172f7();
void sub_1741f();
void sub_174d1();
void sub_1752c();
void sub_1756c();
void sub_175ac();
void sub_175d0();
void sub_175f8();
void sub_1763f();
void sub_17680();
void sub_1769b();
void sub_176c7();
void sub_176fc();
void sub_17738();
void sub_17772();
void sub_1778e();
void sub_17805();
void sub_1787c();
void sub_17885();
void sub_1793c();
void sub_179e3();
void sub_17a24();
void sub_17a67();
void sub_17a68();
void sub_17a71();
void sub_17a8c();
void sub_17aad();
void sub_17ace();
void sub_17aef();
void sub_17b10();
void sub_17b14();
void sub_17b2a();
void sub_17b46();
void sub_17b62();
void sub_17b7e();
void sub_17b9a();
void sub_17bcb();
void sub_17c31();
void sub_17d17();
void sub_17d32();
void sub_17dd8();
void sub_17e3a();
void sub_17ec6();
void sub_17f06();
void sub_17f1e();
void sub_17f44();
void sub_17f76();
void sub_17f7b();
void sub_180a7();
void sub_180d2();
void sub_180e0();
void sub_1813a();
void sub_181a3();
void sub_181c1();
void sub_181fa();
void sub_1826d();
void sub_16239();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x13ec2356: sub_16216(); return;
        case 0x13ec236f: sub_1622f(); return;
        case 0x13ec2379: sub_16239(); return;
        case 0x13ec2b47: sub_16a07(); return;
        case 0x13ec2b6a: sub_16a2a(); return;
        case 0x13ec3ba7: sub_17a67(); return;
        case 0x13ec3ba8: sub_17a68(); return;
        case 0x13ec3bb1: sub_17a71(); return;
        case 0x13ec3bcc: sub_17a8c(); return;
        case 0x13ec3bed: sub_17aad(); return;
        case 0x13ec3c0e: sub_17ace(); return;
        case 0x13ec3c2f: sub_17aef(); return;
        case 0x13ec3c50: sub_17b10(); return;
        case 0x13ec3c54: sub_17b14(); return;
        case 0x13ec3c6a: sub_17b2a(); return;
        case 0x13ec3c86: sub_17b46(); return;
        case 0x13ec3ca2: sub_17b62(); return;
        case 0x13ec3cbe: sub_17b7e(); return;
        default:
            break;
    }
    assert(0);
}
void sub_16239()
{
}
void sub_13ec7()
{
    push(ds);
    ax = 0x0000;
    push(ax);
    ax = 0x1020;
    ds = ax;
    interrupt(0x12);
    cl = 0x06;
    ax <<= cl;
    bx = cs;
    bx += 0x1000;
    ax -= bx;
    if (ax > 0x1000)
        goto loc_13ef5;
    ax = 0x0003;
    interrupt(0x10);
    dx = 0x377;
    ah = 0x09;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
loc_13ef5:
    memoryASet16(ds, 0x0261, bx);
    ax = 0x024b;
    cl = 0x04;
    ax >>= cl;
    ax++;
    bx += ax;
    memoryASet16(ds, 0x0263, bx);
    ax = 0x0211;
    cl = 0x04;
    ax >>= cl;
    ax++;
    bx += ax;
    memoryASet16(ds, 0x0265, bx);
    bx += ax;
    memoryASet16(ds, 0x0267, bx);
    bx += ax;
    memoryASet16(ds, 0x0269, bx);
    bx += ax;
    memoryASet16(ds, 0x026b, bx);
    sub_181c1();
    memoryASet(ds, 0x111d, 0x00);
    ax = 0x0010;
    interrupt(0x10);
    sub_13f3d();
    ax = 0x0003;
    interrupt(0x10);
    cs = pop();
}
void sub_13f3d()
{
    push(0x7777);
    memoryASet16(ds, 0x0251, sp);
    sub_15cc3();
    memoryASet(ds, 0x1451, ch);
    memoryASet(ds, 0x1452, cl);
    memoryASet(ds, 0x1453, dh);
    ax = memoryAGet16(ds, 0x0261);
    sub_14601();
    sub_140f6();
    sub_15cc8();
    sub_13fee();
    sub_1787c();
    sub_147ba();
loc_13f65:
    ax = 0x0003;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    es = memoryAGet16(ds, 0x024f);
    sub_147ba();
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_13f89;
    sub_153f0();
loc_13f89:
    //sub_1487f(); // skip config screen
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
loc_13f93:
    ax = memoryAGet16(ds, 0x0261);
    sub_1461b();
    ax = 0x0010;
    interrupt(0x10);
    al = memoryAGet(ds, 0x0650);
    memoryASet(ds, 0x064f, al);
    memoryASet(ds, 0x064e, 0x01);
    if (memoryAGet(ds, 0x064f) != 0x01)
        goto loc_13fb6;
    sub_14119();
    goto loc_13fb9;
loc_13fb6:
    sub_141d6();
loc_13fb9:
    sp = memoryAGet16(ds, 0x0251);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_13f93;
    memoryASet(ds, 0x064e, 0x00);
    goto loc_13f65;
loc_13fe7:
    sub_15b67();
    sub_15d57();
    assert(pop() == 0x7777);
}
void sub_13fee()
{
    dx = 0x251a;
    ah = 0x09;
    interrupt(0x21);
    sub_15cc3();
    memoryASet16(ds, 0x2518, dx);
    cx = 0x0010;
loc_14000:
    push(cx);
    cx = 0xfde8;
loc_14004:
    if (--cx)
        goto loc_14004;
    cx = pop();
    if (--cx)
        goto loc_14000;
    sub_140c1();
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx <<= 1;
    dx = memoryAGet16(ds, bx + 9574);
    bx >>= 1;
    if ((short)bx < (short)0x0050)
        goto loc_1403c;
    if ((short)bx < (short)0x03e8)
        goto loc_14028;
    goto loc_140ba;
loc_14028:
    si = 0x009f;
    cx = 0x0050;
loc_1402e:
    cx += 0x0014;
    si++;
    if ((short)cx < (short)bx)
        goto loc_1402e;
    dl = memoryAGet(ds, si + 9574);
    dh = 0x00;
loc_1403c:
    if (memoryAGet(ds, 0x2517) <= 0x01)
        goto loc_14058;
    memoryASet(ds, 0x2517, memoryAGet(ds, 0x2517) - 1);
    ax = memoryAGet16(ds, 0x2513);
    ax -= 0x0006;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) + ax);
    goto loc_14077;
loc_14058:
    if (memoryAGet16(ds, 0x2513) >= 0x000f)
        goto loc_14097;
    memoryASet(ds, 0x2517, 0x0e);
    cx = memoryAGet16(ds, 0x2513);
    cx -= 0x0006;
    cx <<= 1;
    cx <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) + cx);
    memoryASet16(ds, 0x2513, memoryAGet16(ds, 0x2513) + 1);
loc_14077:
    if (memoryAGet16(ds, 0x2513) & 0x0001)
        goto loc_14091;
    if (memoryAGet(ds, 0x2517) != 0x07)
        goto loc_14091;
    memoryASet16(ds, 0x2141, memoryAGet16(ds, 0x2141) + 0x0140);
    memoryASet16(ds, 0x215f, memoryAGet16(ds, 0x215f) + 0x0004);
loc_14091:
    if ((short)dx > (short)memoryAGet16(ds, 0x1120))
        goto loc_1403c;
loc_14097:
    if (memoryAGet16(ds, 0x1120) < 0x0064)
        goto loc_140ba;
    memoryASet(ds, 0x050e, memoryAGet(ds, 0x050e) >> 1);
    if (memoryAGet16(ds, 0x1120) < 0x00c8)
        goto loc_140ba;
    memoryASet(ds, 0x050e, memoryAGet(ds, 0x050e) >> 1);
    if (memoryAGet16(ds, 0x1120) < 0x012c)
        goto loc_140ba;
    memoryASet(ds, 0x050e, memoryAGet(ds, 0x050e) >> 1);
loc_140ba:
    ax = memoryAGet16(ds, 0x1120);
    memoryASet16(ds, 0x0401, ax);
}
void sub_140c1()
{
    sub_15cc3();
    ax = memoryAGet16(ds, 0x2518);
    bh = 0x00;
    bl = dl;
    if (ah == dh)
        goto loc_140f1;
    if ((char)ah < (char)dh)
        goto loc_140da;
    ah = -ah;
    ah += 0x3c;
    dh += ah;
    ah = 0x00;
loc_140da:
    dh--;
    if (ah == dh)
        goto loc_140e5;
    bx += 0x0064;
    goto loc_140da;
loc_140e5:
    ah = 0x00;
    ax = -ax;
    ax += 0x0063;
    bx += ax;
    return;
loc_140f1:
    ah = 0x00;
    bx -= ax;
}
void sub_140f6()
{
    ax = 0x1222;
    di = 0x002c;
    cx = 0x000b;
loc_140ff:
    push(cx);
    cx = 0x0013;
loc_14103:
    memoryASet16(ds, di + 1617, ax);
    ax += 0x0004;
    di += 0x0002;
    if (--cx)
        goto loc_14103;
    ax += 0x0734;
    di += 0x0004;
    cx = pop();
    if (--cx)
        goto loc_140ff;
}
void sub_14119()
{
    push(0x7777);
    goto loc_14119;
loc_13f65:
    ax = 0x0003;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    es = memoryAGet16(ds, 0x024f);
    sub_147ba();
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_13f89;
    sub_153f0();
loc_13f89:
    sub_1487f();
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
loc_13f93:
    ax = memoryAGet16(ds, 0x0261);
    sub_1461b();
    ax = 0x0010;
    interrupt(0x10);
    al = memoryAGet(ds, 0x0650);
    memoryASet(ds, 0x064f, al);
    memoryASet(ds, 0x064e, 0x01);
    if (memoryAGet(ds, 0x064f) != 0x01)
        goto loc_13fb6;
    sub_14119();
    goto loc_13fb9;
loc_13fb6:
    sub_141d6();
loc_13fb9:
    sp = memoryAGet16(ds, 0x0251);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_13f93;
    memoryASet(ds, 0x064e, 0x00);
    goto loc_13f65;
loc_13fe7:
    sub_15b67();
    sub_15d57();
    assert(pop() == 0x7777);
    return;
    //   gap of 299 bytes
loc_14119:
    memoryASet(ds, 0x0253, 0x00);
    memoryASet16(ds, 0x03d3, cdmanStartupLevel);
    memoryASet16(ds, 0x03d7, 0x0000);
    memoryASet(ds, 0x2127, 0x00);
loc_1412f:
    sub_143fa();
    ax = memoryAGet16(ds, 0x0263);
    sub_14601();
    memoryASet16(ds, 0x03d5, 0x0001);
loc_1413e:
    sub_1456e();
    sub_1444f();
    sub_158f3();
loc_14147:
    sub_14587();
    sync();
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_141d0;
    sub_16202();
    if (memoryAGet16(ds, 0x0066) != 0x0000)
        goto loc_14147;
    sub_158f3();
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_141d0;
    if (memoryAGet(ds, 0x0246) == 0x01)
        goto loc_141d0;
    if (memoryAGet16(ds, 0x0224) == 0x0000)
    {
        while (1) sync();
        goto loc_141cb;
    }
    if (memoryAGet(ds, 0x022a) == 0x00)
        goto loc_1417f;
    memoryASet(ds, 0x022a, memoryAGet(ds, 0x022a) - 0x14);
loc_1417f:
    ax = memoryAGet16(ds, 0x0263);
    sub_1461b();
    if (memoryAGet(ds, 0x1449) == 0x01)
        goto loc_141a0;
    if (memoryAGet16(ds, 0x03d5) == 0x0003)
        goto loc_141a0;
    memoryASet16(ds, 0x03d5, memoryAGet16(ds, 0x03d5) + 1);
    bx = memoryAGet16(ds, 0x03d3);
    sub_15db2();
    goto loc_1413e;
loc_141a0:
    if (memoryAGet(ds, 0x1449) != 0x01)
        goto loc_141b1;
    if (memoryAGet16(ds, 0x03d3) != 0x0002)
        goto loc_141b1;
    goto loc_15021;
loc_141b1:
    memoryASet16(ds, 0x03d3, memoryAGet16(ds, 0x03d3) + 0x0002);
    if (memoryAGet16(ds, 0x03d3) != 0x0006)
        goto loc_141c8;
    memoryASet16(ds, 0x03d3, 0x0000);
    memoryASet16(ds, 0x03d7, memoryAGet16(ds, 0x03d7) + 0x0006);
loc_141c8:
    goto loc_1412f;
loc_141cb:
    memoryASet(ds, 0x212a, 0x01);
loc_141d0:
    memoryASet(ds, 0x2127, 0x01);
    assert(pop() == 0x7777);
    return;
    //   gap of 2998 bytes
loc_14d8c:
    if (bx == 0x0000)
        goto loc_14d99;
    dx = bx;
    bx = 0x0004;
    goto loc_14df0;
loc_14d99:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14db7;
    memoryASet(ds, 0x212a, 0x01);
    sub_14791();
    ah = 0x04;
    sub_154e6();
    sub_14791();
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14db7:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14dd2;
    sub_14ee9();
    if (memoryAGet(ds, 0x031f) == 0x01)
        goto loc_14dcc;
    sub_14791();
loc_14dcc:
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14dd2:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14dde;
    sub_14fb4();
    assert(pop() == 0x7777);
    return;
loc_14dde:
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14def;
    memoryASet(ds, 0x2129, 0x01);
    memoryASet(ds, 0x2128, 0x01);
loc_14def:
    assert(pop() == 0x7777);
    return;
loc_14df0:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14e09;
    sub_14e49();
    memoryASet(ds, 0x064e, 0x00);
    memoryASet(ds, 0x0063, 0x01);
    goto loc_13fb9;
    //   gap of 1 bytes
loc_14e09:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14e24;
    if (memoryAGet(ds, 0x064e) == 0x01)
        goto loc_14e1b;
    bx = dx;
    assert(pop() == 0x7777);
    return;
loc_14e1b:
    memoryASet(ds, 0x2128, 0x01);
    sub_14e49();
    assert(pop() == 0x7777);
    return;
loc_14e24:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14e30;
    sub_152c7();
    assert(pop() == 0x7777);
    return;
loc_14e30:
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0065, 0x01);
    memoryASet(ds, 0x2128, 0x01);
    goto loc_13fb9;
    //   gap of 400 bytes
loc_14fd8:
    memoryASet16(ds, 0x310d, 0x0000);
    dx = 0x249;
loc_14fe2:
    sub_150e5();
    if (memoryAGet(ds, 0x0249) != 0x0d)
        goto loc_14fe2;
    memoryASet16(ds, 0x111b, 0x3039);
    memoryASet(ds, 0x111d, 0x00);
    memoryASet(ds, 0x1449, 0x01);
    memoryASet16(ds, 0x2145, 0x0140);
    memoryASet16(ds, 0x2163, 0x0000);
    sub_14e49();
    memoryASet16(ds, 0x2143, 0x0140);
    memoryASet16(ds, 0x2161, 0x0000);
    bx = 0x0004;
    goto loc_14d8c;
    //   gap of 4 bytes
loc_15021:
    memoryASet(ds, 0x1449, 0x00);
    sub_175f8();
    memoryASet(ds, 0x144a, 0x01);
    sub_17885();
    memoryASet(ds, 0x144a, 0x00);
    if (ax == 0xffff)
        goto loc_15052;
    sub_15079();
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0246, 0x01);
    ax = 0xffff;
    assert(pop() == 0x7777);
    return;
loc_15052:
    goto loc_14fd8;
}
void sub_141d6()
{
    memoryASet(ds, 0x2127, 0x00);
    memoryASet(ds, 0x0217, 0x01);
    memoryASet16(ds, 0x03d3, 0x0000);
    sub_143fa();
    sub_1456e();
    ax = memoryAGet16(ds, 0x0269);
    sub_14601();
    ax = memoryAGet16(ds, 0x0265);
    sub_14601();
    goto loc_141fe;
loc_141fb:
    sub_143fa();
loc_141fe:
    ax = memoryAGet16(ds, 0x0263);
    sub_14601();
    memoryASet16(ds, 0x021a, 0x0001);
loc_1420a:
    sub_1456e();
    sub_1444f();
    sub_158f3();
    ax = memoryAGet16(ds, 0x021a);
    memoryASet16(ds, 0x03d5, ax);
loc_14219:
    sub_14587();
    if (memoryAGet(ds, 0x0063) != 0x01)
        goto loc_14226;
    return;
loc_14226:
    if (memoryAGet(ds, 0x0064) != 0x01)
        goto loc_14233;
    sub_14332();
    goto loc_142a7;
loc_14233:
    sub_16202();
    if (memoryAGet16(ds, 0x0066) != 0x0000)
        goto loc_14219;
    sub_158f3();
    if (memoryAGet(ds, 0x0065) != 0x01)
        goto loc_1424a;
    return;
loc_1424a:
    ax = memoryAGet16(ds, 0x0263);
    sub_1461b();
    if (memoryAGet16(ds, 0x021a) == 0x0003)
        goto loc_14264;
    memoryASet16(ds, 0x021a, memoryAGet16(ds, 0x021a) + 1);
    bx = memoryAGet16(ds, 0x0218);
    sub_15db2();
    goto loc_1420a;
loc_14264:
    memoryASet16(ds, 0x0218, memoryAGet16(ds, 0x0218) + 0x0002);
    memoryASet16(ds, 0x03d3, memoryAGet16(ds, 0x03d3) + 0x0002);
    if (memoryAGet16(ds, 0x0218) != 0x0006)
        goto loc_14286;
    memoryASet16(ds, 0x0218, 0x0000);
    memoryASet16(ds, 0x03d3, 0x0000);
    memoryASet16(ds, 0x021c, memoryAGet16(ds, 0x021c) + 0x0006);
loc_14286:
    goto loc_141fb;
loc_14289:
    sub_143fa();
    ax = memoryAGet16(ds, 0x0265);
    sub_14601();
    memoryASet16(ds, 0x0220, 0x0001);
loc_14298:
    sub_1456e();
    sub_1444f();
    sub_158f3();
    ax = memoryAGet16(ds, 0x0220);
    memoryASet16(ds, 0x03d5, ax);
loc_142a7:
    sub_14587();
    if (memoryAGet(ds, 0x0063) != 0x01)
        goto loc_142b4;
    return;
loc_142b4:
    if (memoryAGet(ds, 0x0064) != 0x01)
        goto loc_142c8;
    sub_14396();
    if (memoryAGet(ds, 0x2127) == 0x01)
        return;
    goto loc_14219;
loc_142c8:
    sub_16202();
    if (memoryAGet16(ds, 0x0066) != 0x0000)
        goto loc_142a7;
    sub_158f3();
    if (memoryAGet(ds, 0x0065) != 0x01)
        goto loc_142df;
    return;
loc_142df:
    ax = memoryAGet16(ds, 0x0265);
    sub_1461b();
    if (memoryAGet16(ds, 0x0220) == 0x0003)
        goto loc_142f9;
    memoryASet16(ds, 0x0220, memoryAGet16(ds, 0x0220) + 1);
    bx = memoryAGet16(ds, 0x021e);
    sub_15db2();
    goto loc_14298;
loc_142f9:
    memoryASet16(ds, 0x021e, memoryAGet16(ds, 0x021e) + 0x0002);
    memoryASet16(ds, 0x03d3, memoryAGet16(ds, 0x03d3) + 0x0002);
    if (memoryAGet16(ds, 0x021e) != 0x0006)
        goto loc_1431b;
    memoryASet16(ds, 0x021e, 0x0000);
    memoryASet16(ds, 0x03d3, 0x0000);
    memoryASet16(ds, 0x0222, memoryAGet16(ds, 0x0222) + 0x0006);
loc_1431b:
    goto loc_14289;
    //   gap of 19 bytes
}
void sub_1431e()
{
    memoryASet(ds, 0x212a, 0x01);
    sub_14639();
}
void sub_14332()
{
    memoryASet(ds, 0x0064, 0x00);
    sub_158f3();
    ax = memoryAGet16(ds, 0x0267);
    sub_14601();
    if (memoryAGet16(ds, 0x0226) != 0x0001)
        goto loc_1434a;
    sub_1431e();
loc_1434a:
    memoryASet16(ds, 0x0226, memoryAGet16(ds, 0x0226) - 1);
    ax = memoryAGet16(ds, 0x0228);
    memoryASet16(ds, 0x0224, ax);
    if (memoryAGet(ds, 0x022b) == 0x00)
        goto loc_14360;
    memoryASet(ds, 0x022b, memoryAGet(ds, 0x022b) - 0x14);
loc_14360:
    al = memoryAGet(ds, 0x022c);
    memoryASet(ds, 0x022a, al);
    ax = memoryAGet16(ds, 0x0211);
    memoryASet16(ds, 0x0213, ax);
    ax = memoryAGet16(ds, 0x0215);
    memoryASet16(ds, 0x0211, ax);
    memoryASet(ds, 0x0217, 0x02);
    sub_158f3();
    ax = memoryAGet16(ds, 0x021e);
    memoryASet16(ds, 0x03d3, ax);
    if (ax == memoryAGet16(ds, 0x0218))
        goto loc_14389;
    sub_143fa();
loc_14389:
    ax = memoryAGet16(ds, 0x0269);
    sub_1461b();
    sub_15dfa();
    sub_1444f();
}
void sub_14396()
{
    goto loc_14396;
loc_14327:
    memoryASet(ds, 0x212a, 0x01);
    memoryASet(ds, 0x2127, 0x01);
    return;
    //   gap of 100 bytes
loc_14396:
    memoryASet(ds, 0x0064, 0x00);
    sub_158f3();
    ax = memoryAGet16(ds, 0x0269);
    sub_14601();
    if (memoryAGet16(ds, 0x0228) != 0x0001)
        goto loc_143ae;
    goto loc_14327;
loc_143ae:
    memoryASet16(ds, 0x0228, memoryAGet16(ds, 0x0228) - 1);
    ax = memoryAGet16(ds, 0x0226);
    memoryASet16(ds, 0x0224, ax);
    if (memoryAGet(ds, 0x022c) == 0x00)
        goto loc_143c4;
    memoryASet(ds, 0x022c, memoryAGet(ds, 0x022c) - 0x14);
loc_143c4:
    al = memoryAGet(ds, 0x022b);
    memoryASet(ds, 0x022a, al);
    ax = memoryAGet16(ds, 0x0211);
    memoryASet16(ds, 0x0215, ax);
    ax = memoryAGet16(ds, 0x0213);
    memoryASet16(ds, 0x0211, ax);
    memoryASet(ds, 0x0217, 0x01);
    sub_158f3();
    ax = memoryAGet16(ds, 0x0218);
    memoryASet16(ds, 0x03d3, ax);
    if (ax == memoryAGet16(ds, 0x021e))
        goto loc_143ed;
    sub_143fa();
loc_143ed:
    ax = memoryAGet16(ds, 0x0267);
    sub_1461b();
    sub_15dfa();
    sub_1444f();
}
void sub_143fa()
{
    bx = memoryAGet16(ds, 0x03d3);
    ax = memoryAGet16(ds, bx + 3801);
    memoryASet16(ds, 0x0203, ax);
    dx = memoryAGet16(ds, bx + 985);
    sub_17f06();
    ax = 0xa6d6;
    sub_17f7b();
    bx = memoryAGet16(ds, 0x03d3);
    dx = memoryAGet16(ds, bx + 995);
    sub_17f06();
    si = 0x110a;
    sub_180a7();
    ax = memoryAGet16(ds, 0x024b);
    sub_17f7b();
    bx = memoryAGet16(ds, 0x03d3);
    sub_15db2();
    bx = memoryAGet16(ds, 0x03d3);
    sub_15e6f();
    bx = memoryAGet16(ds, 0x03d3);
    si = memoryAGet16(ds, bx + 1015);
    sub_180a7();
    es = memoryAGet16(ds, 0x024b);
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
}
void sub_1444f()
{
    es = memoryAGet16(ds, 0x024b);
    sub_167c7();
    if (memoryAGet(ds, 0x064f) == 0x02)
        goto loc_14488;
    sub_1763f();
    di = 0x049c;
    sub_1769b();
    memoryASet16(ds, 0x107f, 0x0c6c);
    sub_16a4d();
    sub_165e5();
    di = 0x003c;
    cx = 0x0005;
    dx = 0x0014;
    memoryASet16(ds, 0x107f, 0x0c6c);
    sub_14521();
    sub_172b1();
    return;
loc_14488:
    si = 0xd890;
    si += 0x0014;
    di = 0x0000;
    if (memoryAGet(ds, 0x0217) != 0x01)
        goto loc_1449e;
    si += 0x0010;
    di += 0x003c;
loc_1449e:
    sub_17680();
    push(memoryAGet16(ds, 0x0217));
    memoryASet(ds, 0x0217, 0x01);
    di = 0x0460;
    sub_1769b();
    memoryASet(ds, 0x0217, 0x02);
    di = 0x049c;
    sub_1769b();
    memoryASet16(ds, 0x0217, pop());
    push(memoryAGet16(ds, 0x0211));
    memoryASet16(ds, 0x107d, 0xd890);
    memoryASet16(ds, 0x107f, 0x0c38);
    ax = memoryAGet16(ds, 0x0213);
    if (memoryAGet(ds, 0x0217) != 0x01)
        goto loc_144e1;
    memoryASet16(ds, 0x107f, memoryAGet16(ds, 0x107f) + 0x0034);
    ax = memoryAGet16(ds, 0x0215);
loc_144e1:
    memoryASet16(ds, 0x0211, ax);
    push(memoryAGet16(ds, 0x0211));
    sub_16a4d();
    memoryASet16(ds, 0x0211, pop());
    sub_176fc();
    memoryASet16(ds, 0x0211, pop());
    sub_165e5();
    di = 0x0000;
    cx = 0x00c8;
    dx = 0x0014;
    memoryASet16(ds, 0x107f, 0x0c38);
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_1451a;
    di += 0x003c;
    dx += 0x0010;
    memoryASet16(ds, 0x107f, memoryAGet16(ds, 0x107f) + 0x0034);
loc_1451a:
    sub_14521();
    sub_172b1();
}
void sub_14521()
{
loc_14521:
    push(cx);
    push(di);
    si = 0xd890;
    si += dx;
    sub_17680();
    memoryASet16(ds, 0x107d, 0xd890);
    sub_176fc();
    memoryASet16(ds, 0x111e, 0x0096);
    sub_17805();
    di = pop();
    push(di);
    push(ax);
    si = 0xd660;
    si += dx;
    sub_17680();
    memoryASet16(ds, 0x107d, 0xd660);
    sub_176fc();
    ax = pop();
    di = pop();
    cx = pop();
    if (memoryAGet(ds, 0x1122) == 0x01)
        return;
    memoryASet16(ds, 0x111e, 0x0096);
    sub_17805();
    if (memoryAGet(ds, 0x1122) == 0x01)
        return;
    if (--cx)
        goto loc_14521;
}
void sub_1456e()
{
    si = memoryAGet16(ds, 0x0203);
    di = 0x18d;
    cx = 0x005c;
    sub_15daa();
    si = 0x1053;
    bx = 0xffff;
    sub_15d7c();
}
void sub_14587()
{
    if (memoryAGet(ds, 0x005a) >= 0x14)
        goto loc_1459b;
    if (memoryAGet(ds, 0x005a) <= 0x08)
        goto loc_1459b;
    sub_16998();
    goto loc_1459e;
loc_1459b:
    sub_16a4d();
loc_1459e:
    sub_15f62();
    if (memoryAGet(ds, 0x0062) == 0x01)
        return;
    sub_15ecc();
    sub_15fa8();
    bx = 0x0000;
loc_145b1:
    memoryASet16(ds, 0x0207, bx);
    if (memoryAGet(ds, bx + 104) == 0x4d)
        goto loc_145de;
    memoryASet(ds, bx + 521, memoryAGet(ds, bx + 521) + 1);
    if (memoryAGet(ds, bx + 521) != 0x0f)
        goto loc_145d5;
    memoryASet(ds, bx + 521, 0x00);
    sub_16fd3();
    sub_15fc4();
    sub_15f15();
loc_145d5:
    sub_16fd3();
    sub_15fc4();
    goto loc_145f7;
loc_145de:
    memoryASet(ds, bx + 525, memoryAGet(ds, bx + 525) + 1);
    if (memoryAGet(ds, bx + 525) != 0x08)
        goto loc_145f1;
    memoryASet(ds, bx + 525, 0x00);
    goto loc_145f7;
loc_145f1:
    sub_16fd3();
    sub_15fc4();
loc_145f7:
    sub_15f15();
    bx++;
    if (bx != 0x0004)
        goto loc_145b1;
}
void sub_14601()
{
    push(es);
    es = ax;
    si = 0x0000;
    di = 0x0000;
    cx = 0x0211;
    if (ax != memoryAGet16(ds, 0x0261))
        goto loc_14616;
    cx = 0x024b;
loc_14616:
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_1461b()
{
    push(ds);
    push(es);
    cx = 0x0211;
    if (ax != memoryAGet16(ds, 0x0261))
        goto loc_14629;
    cx = 0x024b;
loc_14629:
    push(ds);
    es = pop();
    ds = ax;
    si = 0x0000;
    di = 0x0000;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
    ds = pop();
}
void sub_14639()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(es);
    push(ds);
    memoryASet(ds, 0x2127, 0x01);
    sub_158f3();
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
loc_14650:
    es = memoryAGet16(ds, 0x026b);
    ax = 0xa000;
    push(ds);
    ds = ax;
    si = 0;
    di = 0;
    dx = 0x03ce;
    cx = 0x2000;
loc_14664:
    ax = 0x0304;
    out(dx, ax);
    bl = memoryAGet(ds, si);
    memoryASet(es, di, bl);
    ah--;
    out(dx, ax);
    bl = memoryAGet(ds, si);
    memoryASet(es, di + 1, bl);
    ah--;
    out(dx, ax);
    bl = memoryAGet(ds, si);
    memoryASet(es, di + 2, bl);
    ah--;
    out(dx, ax);
    bl = memoryAGet(ds, si);
    memoryASet(es, di + 3, bl);
    si++;
    di += 0x0004;
    if (--cx)
        goto loc_14664;
    if (si > 0x4000)
        goto loc_1469c;
    si = 0x4000;
    cx = 0x18c0;
    goto loc_14664;
loc_1469c:
    ds = pop();
    memoryASet16(ds, 0x026b, memoryAGet16(ds, 0x026b) + 0x0e30);
    ax = 0x0003;
    al |= 0x80;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    sub_147ba();
    es = memoryAGet16(ds, 0x024f);
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_146cf;
    sub_14791();
    sub_153f0();
    goto loc_146dc;
loc_146cf:
    sub_1487f();
    if (memoryAGet(ds, 0x0062) != 0x01)
        goto loc_146dc;
    goto loc_1477a;
loc_146dc:
    ax = 0x0010;
    al |= 0x80;
    interrupt(0x10);
    si = 0x110a;
    sub_180a7();
    memoryASet16(ds, 0x026b, memoryAGet16(ds, 0x026b) - 0x0e30);
    es = memoryAGet16(ds, 0x026b);
    ax = 0xa000;
    push(ds);
    ds = ax;
    si = 0;
    di = 0;
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    ax = 0x0f00;
    out(dx, ax);
    cx = 0x2000;
loc_14710:
    ax = 0x0003;
    out(dx, ax);
    ax = 0x0f01;
    out(dx, ax);
    memoryASet(ds, di, bl);
    ax = 0x0803;
    out(dx, ax);
    ax = 0x0e01;
    out(dx, ax);
    ah = memoryAGet(ds, di);
    bx = memoryAGet16(es, si + 2);
    memoryASet(ds, di, bh);
    ah = 0x0d;
    out(dx, ax);
    ah = memoryAGet(ds, di);
    memoryASet(ds, di, bl);
    ah = 0x0b;
    out(dx, ax);
    ah = memoryAGet(ds, di);
    bx = memoryAGet16(es, si);
    memoryASet(ds, di, bh);
    ah = 0x07;
    out(dx, ax);
    ah = memoryAGet(ds, di);
    memoryASet(ds, di, bl);
    si += 0x0004;
    di++;
    if (--cx)
        goto loc_14710;
    if (di > 0x4000)
        goto loc_14756;
    di = 0x4000;
    cx = 0x18c0;
    goto loc_14710;
loc_14756:
    ds = pop();
    bx = memoryAGet16(ds, 0x03d3);
    si = memoryAGet16(ds, bx + 1015);
    sub_180a7();
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    es = memoryAGet16(ds, 0x024b);
    if (memoryAGet(ds, 0x2129) != 0x01)
        goto loc_1477a;
    sub_181a3();
    goto loc_14650;
loc_1477a:
    sub_158f3();
    memoryASet(ds, 0x2127, 0x00);
    memoryASet(ds, 0x212a, 0x00);
    ds = pop();
    es = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_14791()
{
    push(ax);
    push(si);
    push(di);
    es = memoryAGet16(ds, 0x024f);
    ah = 0x00;
    al = 0x20;
    di = 0;
    cx = 0x07d0;
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_147ae;
    di = 0x0320;
    cx = 0x0640;
loc_147ae:
    memoryASet16(es, di, ax);
    di += 0x0002;
    if (--cx)
        goto loc_147ae;
    di = pop();
    si = pop();
    ax = pop();
}
void sub_147ba()
{
    ax = 0x1110;
    bh = 0x0e;
    bl = 0x01;
    cx = 0x00c6;
    dx = 0x0000;
    push(es);
    push(ds);
    es = pop();
    bp = 0x2639;
    interrupt(0x10);
    es = pop();
    ax = 0x1201;
    bl = 0x30;
    interrupt(0x10);
    si = 0x1093;
    sub_180a7();
    ax = 0x1103;
    bl = 0x04;
    interrupt(0x10);
}
void sub_147e7()
{
    push(ax);
    push(bx);
    es = memoryAGet16(ds, 0x024f);
    if (memoryAGet(ds, 0x212a) == 0x01)
        goto loc_14805;
    ax = 0x0020;
    di = 0x0000;
    cx = 0x0190;
loc_147fd:
    memoryASet16(es, di, ax);
    di += 0x0002;
    if (--cx)
        goto loc_147fd;
loc_14805:
    di = 0x000c;
    ah = 0x08;
    al = 0x0f;
    cx = 0x0003;
loc_1480f:
    push(cx);
    ah++;
    cx = 0x000b;
loc_14815:
    memoryASet16(es, di, ax);
    di += 0x0002;
    al++;
    if (--cx)
        goto loc_14815;
    di += 0x008a;
    cx = pop();
    if (--cx)
        goto loc_1480f;
    di = 0x0032;
    bx = 0x0000;
    al = 0x42;
    cx = 0x0004;
loc_14831:
    push(cx);
    ah = memoryAGet(ds, bx + 9781);
    bx++;
    cx = 0x0021;
loc_1483a:
    memoryASet16(es, di, ax);
    di += 0x0002;
    al++;
    if (--cx)
        goto loc_1483a;
    di += 0x005e;
    cx = pop();
    if (--cx)
        goto loc_14831;
    di = 0x0088;
    ah = 0x0e;
    al = 0x30;
    cx = 0x0003;
loc_14854:
    push(cx);
    cx = 0x0006;
loc_14858:
    memoryASet16(es, di, ax);
    di += 0x0002;
    al++;
    if (--cx)
        goto loc_14858;
    di += 0x0094;
    cx = pop();
    if (--cx)
        goto loc_14854;
    ax = 0x1003;
    bl = 0x00;
    interrupt(0x10);
    memoryASet(es, 0x008d, memoryAGet(es, 0x008d) | 0xf0);
    memoryASet(es, 0x0131, memoryAGet(es, 0x0131) | 0x90);
    bx = pop();
    ax = pop();
}
void sub_1487f()
{
    memoryASet(ds, 0x0062, 0x00);
    memoryASet(ds, 0x2128, 0x00);
    memoryASet(ds, 0x2129, 0x00);
    memoryASet(ds, 0x212a, 0x00);
    sub_14791();
loc_14896:
    sub_147e7();
    memoryASet16(ds, 0x2143, 0x0140);
    memoryASet16(ds, 0x2161, 0x0000);
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_148b8;
    memoryASet16(ds, 0x2143, 0x0280);
    memoryASet16(ds, 0x2161, 0x0004);
loc_148b8:
    bx = 0x0000;
    cx = 0x0005;
loc_148be:
    push(cx);
    ah = 0x07;
    if (bx != 0x0004)
        goto loc_148c8;
    ah = 0x04;
loc_148c8:
    sub_14e74();
    si = memoryAGet16(ds, bx + 8491);
    di = memoryAGet16(ds, bx + 8501);
    dx = 0x0000;
    cx = memoryAGet16(ds, bx + 8531);
loc_148da:
    push(cx);
    ah = 0x04;
    if (bx != 0x0004)
        goto loc_148e4;
    ah = 0x01;
loc_148e4:
    if (dx == 0x0000)
        goto loc_148f1;
    if (dx == memoryAGet16(ds, bx + 8511))
        goto loc_148f1;
    ah = 0x07;
loc_148f1:
    cx = 0x000a;
loc_148f4:
    al = memoryAGet(ds, si);
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_148f4;
    di += 0x012c;
    dx += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_148da;
    bx += 0x0002;
    cx = pop();
    if (--cx)
        goto loc_148be;
    ah = 0x04;
    sub_14bfa();
    bx = 0x0004;
    if (memoryAGet(ds, 0x1449) != 0x01)
        goto loc_14922;
    bx = 0x0000;
loc_14922:
    sub_14ce4();
loc_14925:
    sub_181a3();
    if (al == 0x00)
        goto loc_1492f;
    goto loc_14aed;
loc_1492f:
    if (ah != 0x48)
        goto loc_14942;
    if (bx == 0x0002)
        goto loc_14945;
loc_14939:
    dl = 0x07;
    ax = memoryAGet16(ds, bx + 8511);
    goto loc_1499b;
loc_14942:
    goto loc_149da;
loc_14945:
    if (memoryAGet(ds, 0x2517) >= 0x0e)
        goto loc_14966;
    memoryASet(ds, 0x2517, memoryAGet(ds, 0x2517) + 1);
    ax = memoryAGet16(ds, 0x2513);
    ax -= 0x0006;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) - ax);
    ah = 0x01;
    sub_14bfa();
    goto loc_1498a;
loc_14966:
    if (memoryAGet16(ds, 0x2513) <= 0x0007)
        goto loc_14925;
    memoryASet(ds, 0x2517, 0x01);
    memoryASet16(ds, 0x2513, memoryAGet16(ds, 0x2513) - 1);
    cx = memoryAGet16(ds, 0x2513);
    cx -= 0x0006;
    cx <<= 1;
    cx <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) - cx);
    ah = 0x01;
    sub_14bfa();
loc_1498a:
    if (memoryAGet16(ds, 0x2513) & 0x0001)
        goto loc_14999;
    if (memoryAGet(ds, 0x2517) == 0x08)
        goto loc_14939;
loc_14999:
    goto loc_14925;
loc_1499b:
    di = memoryAGet16(ds, bx + 8501);
    di += ax;
    cx = 0x000a;
    if (bx != 0x0002)
        goto loc_149ac;
    cx = 0x0009;
loc_149ac:
    memoryASet(es, di + 1, dl);
    di += 0x0002;
    if (--cx)
        goto loc_149ac;
    if (dl != 0x01)
        goto loc_149bd;
    goto loc_14922;
loc_149bd:
    ax -= 0x0140;
    memoryASet16(ds, bx + 8541, memoryAGet16(ds, bx + 8541) - 0x0004);
    if ((short)ax >= (short)0x0140)
        goto loc_149d2;
    memoryASet16(ds, bx + 8541, memoryAGet16(ds, bx + 8541) + 0x0004);
    ax += 0x0140;
loc_149d2:
    memoryASet16(ds, bx + 8511, ax);
    dl = 0x01;
    goto loc_1499b;
loc_149da:
    if (ah != 0x50)
        goto loc_149ed;
    if (bx == 0x0002)
        goto loc_149f0;
loc_149e4:
    dl = 0x07;
    ax = memoryAGet16(ds, bx + 8511);
    goto loc_14a47;
loc_149ed:
    goto loc_14a7f;
loc_149f0:
    if (memoryAGet(ds, 0x2517) <= 0x01)
        goto loc_14a11;
    memoryASet(ds, 0x2517, memoryAGet(ds, 0x2517) - 1);
    ax = memoryAGet16(ds, 0x2513);
    ax -= 0x0006;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) + ax);
    ah = 0x01;
    sub_14bfa();
    goto loc_14a35;
loc_14a11:
    if (memoryAGet16(ds, 0x2513) >= 0x000f)
        goto loc_14a44;
    memoryASet(ds, 0x2517, 0x0e);
    cx = memoryAGet16(ds, 0x2513);
    cx -= 0x0006;
    cx <<= 1;
    cx <<= 1;
    memoryASet16(ds, 0x1120, memoryAGet16(ds, 0x1120) + cx);
    memoryASet16(ds, 0x2513, memoryAGet16(ds, 0x2513) + 1);
    ah = 0x01;
    sub_14bfa();
loc_14a35:
    if (memoryAGet16(ds, 0x2513) & 0x0001)
        goto loc_14a44;
    if (memoryAGet(ds, 0x2517) == 0x07)
        goto loc_149e4;
loc_14a44:
    goto loc_14925;
loc_14a47:
    di = memoryAGet16(ds, bx + 8501);
    di += ax;
    cx = 0x0009;
loc_14a50:
    memoryASet(es, di + 1, dl);
    di += 0x0002;
    if (--cx)
        goto loc_14a50;
    if (dl != 0x01)
        goto loc_14a61;
    goto loc_14922;
loc_14a61:
    ax += 0x0140;
    memoryASet16(ds, bx + 8541, memoryAGet16(ds, bx + 8541) + 0x0004);
    if ((short)ax <= (short)memoryAGet16(ds, bx + 8521))
        goto loc_14a77;
    ax -= 0x0140;
    memoryASet16(ds, bx + 8541, memoryAGet16(ds, bx + 8541) - 0x0004);
loc_14a77:
    memoryASet16(ds, bx + 8511, ax);
    dl = 0x01;
    goto loc_14a47;
loc_14a7f:
    if (ah != 0x4b)
        goto loc_14a92;
    if (bx == 0x0000)
        goto loc_14aea;
    memoryASet16(ds, 0x026e, 0xfffe);
    goto loc_14aa2;
loc_14a92:
    if (ah != 0x4d)
        goto loc_14aea;
    if (bx == 0x0008)
        goto loc_14aea;
    memoryASet16(ds, 0x026e, 0x0002);
loc_14aa2:
    dl = 0x04;
    ah = 0x07;
    sub_14e74();
    if (bx != 0x0002)
        goto loc_14ab3;
    ah = 0x04;
    sub_14bfa();
loc_14ab3:
    di = memoryAGet16(ds, bx + 8501);
    bp = memoryAGet16(ds, bx + 8511);
    cx = 0x0009;
loc_14abe:
    memoryASet(es, di + 1, dl);
    memoryASet(es, bp + di + 1, dl);
    di += 0x0002;
    if (--cx)
        goto loc_14abe;
    if (dl != 0x01)
        goto loc_14ad3;
    goto loc_14922;
loc_14ad3:
    dl = 0x01;
    bx += memoryAGet16(ds, 0x026e);
    ah = 0x04;
    sub_14e74();
    if (bx != 0x0002)
        goto loc_14ab3;
    ah = 0x01;
    sub_14bfa();
    goto loc_14ab3;
loc_14aea:
    goto loc_14922;
loc_14aed:
    if (al != 0x0d)
        goto loc_14b21;
    sub_14d8c();
    if (memoryAGet(ds, 0x031f) != 0x01)
        goto loc_14b08;
    memoryASet(ds, 0x031f, 0x00);
    memoryASet(ds, 0x212a, 0x00);
    goto loc_14925;
loc_14b08:
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_14b17;
    memoryASet(ds, 0x212a, 0x00);
    goto loc_14896;
loc_14b17:
    if (memoryAGet(ds, 0x2128) != 0x01)
        goto loc_14aea;
    return;
loc_14b21:
    if ((char)al < (char)0x61)
        goto loc_14b27;
    al -= 0x20;
loc_14b27:
    dx = 0x0000;
    si = bx;
    si >>= 1;
    si += bx;
    si += bx;
    bp = 0x0140;
    cx = 0x0005;
loc_14b38:
    if (al == memoryAGet(ds, si + 8561))
        goto loc_14b4b;
    si++;
    dx += 0x0004;
    bp += 0x0140;
    if (--cx)
        goto loc_14b38;
    goto loc_14922;
loc_14b4b:
    memoryASet16(ds, bx + 8541, dx);
    if (bx != 0x0002)
        goto loc_14b76;
    memoryASet(ds, 0x2517, 0x07);
    di = memoryAGet16(ds, bx + 8541);
    di >>= 1;
    memoryASet16(ds, 0x2513, 0x0007);
    memoryASet16(ds, 0x2513, memoryAGet16(ds, 0x2513) + di);
    di = memoryAGet16(ds, di + 8551);
    memoryASet16(ds, 0x1120, di);
    ah = 0x01;
    sub_14bfa();
loc_14b76:
    sub_14ba3();
    dl = 0x07;
    ax = memoryAGet16(ds, bx + 8511);
loc_14b7f:
    di = memoryAGet16(ds, bx + 8501);
    di += ax;
    cx = 0x0009;
loc_14b88:
    memoryASet(es, di + 1, dl);
    di += 0x0002;
    if (--cx)
        goto loc_14b88;
    if (dl != 0x01)
        goto loc_14b99;
    goto loc_14922;
loc_14b99:
    ax = bp;
    memoryASet16(ds, bx + 8511, bp);
    dl = 0x01;
    goto loc_14b7f;
    //   gap of 86 bytes
}
void sub_14ba3()
{
    if (bx != 0x0004)
        goto loc_14bd0;
    if (al != 0x43)
        return;
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14bbe;
    bp = 0x03c0;
    memoryASet16(ds, bx + 8541, 0x0008);
    return;
loc_14bbe:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        return;
    bp = 0x0280;
    memoryASet16(ds, bx + 8541, 0x0004);
    return;
loc_14bd0:
    if (bx != 0x0008)
        return;
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14be7;
    bp = 0x0280;
    memoryASet16(ds, bx + 8541, 0x0004);
    return;
loc_14be7:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        return;
    bp = 0x0140;
    memoryASet16(ds, bx + 8541, 0x0000);
}
void sub_14bfa()
{
    push(ax);
    push(bx);
    push(es);
    push(di);
    es = memoryAGet16(ds, 0x024f);
    push(ax);
    push(bx);
    push(dx);
    dx = memoryAGet16(ds, 0x2513);
    dl = -dl;
    dl += 0x0f;
    dl <<= 1;
    bl = dl;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dl -= bl;
    dl += memoryAGet(ds, 0x2517);
    di = 0x03f4;
    bx = 0x1079;
loc_14c25:
    al = 0x00;
loc_14c27:
    if ((short)dx < (short)memoryAGet16(ds, bx))
        goto loc_14c31;
    al++;
    dx -= memoryAGet16(ds, bx);
    goto loc_14c27;
loc_14c31:
    al += 0x30;
    memoryASet16(es, di, ax);
    di += 0x0002;
    bx += 0x0002;
    al = 0x0a;
    if (memoryAGet(ds, bx + 65534) != al)
        goto loc_14c25;
    al = dl;
    al += 0x30;
    memoryASet16(es, di, ax);
    dx = pop();
    bx = pop();
    ax = pop();
    ah += 0x08;
    memoryASet16(ds, 0x2515, 0x0000);
    if (memoryAGet16(ds, 0x2513) <= 0x000f)
        goto loc_14c63;
    memoryASet16(ds, 0x2513, 0x000f);
loc_14c63:
    if ((short)memoryAGet16(ds, 0x2513) >= (short)0x0007)
        goto loc_14c70;
    memoryASet16(ds, 0x2513, 0x0007);
loc_14c70:
    if ((short)memoryAGet16(ds, 0x2513) <= (short)0x0007)
        goto loc_14c90;
    cx = memoryAGet16(ds, 0x2513);
    cx -= 0x0007;
    al = 0x00;
    di = 0x0538;
loc_14c83:
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    di += 0x00a0;
    if (--cx)
        goto loc_14c83;
loc_14c90:
    cx = memoryAGet16(ds, 0x2513);
    cx += 0x0001;
    memoryASet16(ds, 0x2515, 0x0000);
loc_14c9d:
    memoryASet16(ds, 0x2515, memoryAGet16(ds, 0x2515) + 0x00a0);
    if (--cx)
        goto loc_14c9d;
    memoryASet16(ds, 0x2515, memoryAGet16(ds, 0x2515) + 0x0038);
    di = memoryAGet16(ds, 0x2515);
    al = memoryAGet(ds, 0x2517);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    if (memoryAGet16(ds, 0x2513) >= 0x000f)
        goto loc_14cdf;
    cx = 0x000f;
    cx -= memoryAGet16(ds, 0x2513);
    al = 0x0e;
    memoryASet16(ds, 0x2515, memoryAGet16(ds, 0x2515) + 0x00a0);
    di = memoryAGet16(ds, 0x2515);
loc_14cd2:
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, ax);
    di += 0x00a0;
    if (--cx)
        goto loc_14cd2;
loc_14cdf:
    di = pop();
    es = pop();
    bx = pop();
    ax = pop();
}
void sub_14ce4()
{
    ah = 0x04;
    al = 0x20;
    di = 0x0d20;
    cx = 0x00f0;
loc_14cee:
    memoryASet16(es, di, ax);
    di += 0x0002;
    if (--cx)
        goto loc_14cee;
    si = memoryAGet16(ds, bx + 8902);
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14d05;
    si = memoryAGet16(ds, bx + 8892);
loc_14d05:
    si += memoryAGet16(ds, bx + 8541);
    push(si);
    push(si);
    push(si);
    si = memoryAGet16(ds, si);
    al = memoryAGet(ds, si);
    si = pop();
    si += 0x0002;
    si = memoryAGet16(ds, si);
    di = 0x0e10;
    if (si == 0x0000)
        goto loc_14d20;
    al += memoryAGet(ds, si);
loc_14d20:
    ah = 0x00;
    di -= ax;
    di >>= 1;
    di <<= 1;
    push(di);
    bp = ax;
    bp <<= 1;
    ah = 0x01;
    di -= 0x00a2;
    memoryASet(es, di + 65534, 0xda);
    memoryASet(es, di + 158, 0xb3);
    memoryASet(es, di + 318, 0xc0);
    memoryASet(es, bp + di + 4, 0xbf);
    memoryASet(es, bp + di + 164, 0xb3);
    memoryASet(es, bp + di + 324, 0xd9);
    bp >>= 1;
    bp += 0x0002;
    cx = 0x0002;
loc_14d5d:
    push(cx);
    cx = bp;
loc_14d60:
    memoryASet(es, di, 0xc4);
    di += 0x0002;
    if (--cx)
        goto loc_14d60;
    di += 0x0140;
    di -= bp;
    di -= bp;
    cx = pop();
    if (--cx)
        goto loc_14d5d;
    di = pop();
    si = pop();
    si = memoryAGet16(ds, si);
    si++;
    sub_15c79();
    si = pop();
    si += 0x0002;
    si = memoryAGet16(ds, si);
    if (si == 0x0000)
        return;
    si++;
    sub_15c79();
}
void sub_14d8c()
{
    push(0x7777);
    goto loc_14d8c;
loc_13f65:
    ax = 0x0003;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    es = memoryAGet16(ds, 0x024f);
    sub_147ba();
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_13f89;
    sub_153f0();
loc_13f89:
    sub_1487f();
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
loc_13f93:
    ax = memoryAGet16(ds, 0x0261);
    sub_1461b();
    ax = 0x0010;
    interrupt(0x10);
    al = memoryAGet(ds, 0x0650);
    memoryASet(ds, 0x064f, al);
    memoryASet(ds, 0x064e, 0x01);
    if (memoryAGet(ds, 0x064f) != 0x01)
        goto loc_13fb6;
    sub_14119();
    goto loc_13fb9;
loc_13fb6:
    sub_141d6();
loc_13fb9:
    sp = memoryAGet16(ds, 0x0251);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_13f93;
    memoryASet(ds, 0x064e, 0x00);
    goto loc_13f65;
loc_13fe7:
    sub_15b67();
    sub_15d57();
    assert(pop() == 0x7777);
    return;
    //   gap of 3486 bytes
loc_14d8c:
    if (bx == 0x0000)
        goto loc_14d99;
    dx = bx;
    bx = 0x0004;
    goto loc_14df0;
loc_14d99:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14db7;
    memoryASet(ds, 0x212a, 0x01);
    sub_14791();
    ah = 0x04;
    sub_154e6();
    sub_14791();
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14db7:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14dd2;
    sub_14ee9();
    if (memoryAGet(ds, 0x031f) == 0x01)
        goto loc_14dcc;
    sub_14791();
loc_14dcc:
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14dd2:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14dde;
    sub_14fb4();
    assert(pop() == 0x7777);
    return;
loc_14dde:
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14def;
    memoryASet(ds, 0x2129, 0x01);
    memoryASet(ds, 0x2128, 0x01);
loc_14def:
    assert(pop() == 0x7777);
    return;
loc_14df0:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14e09;
    sub_14e49();
    memoryASet(ds, 0x064e, 0x00);
    memoryASet(ds, 0x0063, 0x01);
    goto loc_13fb9;
    //   gap of 1 bytes
loc_14e09:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14e24;
    if (memoryAGet(ds, 0x064e) == 0x01)
        goto loc_14e1b;
    bx = dx;
    assert(pop() == 0x7777);
    return;
loc_14e1b:
    memoryASet(ds, 0x2128, 0x01);
    sub_14e49();
    assert(pop() == 0x7777);
    return;
loc_14e24:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14e30;
    sub_152c7();
    assert(pop() == 0x7777);
    return;
loc_14e30:
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0065, 0x01);
    memoryASet(ds, 0x2128, 0x01);
    goto loc_13fb9;
}
void sub_14e49()
{
    bx = 0x0006;
    memoryASet(ds, 0x0650, 0x01);
    if (memoryAGet16(ds, bx + 8511) == 0x0140)
        goto loc_14e5e;
    memoryASet(ds, 0x0650, 0x02);
loc_14e5e:
    bx = 0x0008;
    memoryASet(ds, 0x05a7, 0x01);
    if (memoryAGet16(ds, bx + 8511) == 0x0140)
        return;
    memoryASet(ds, 0x05a7, 0x00);
}
void sub_14e74()
{
    si = 0x2266;
    if (ah != 0x04)
        goto loc_14e81;
    si = 0x2291;
loc_14e81:
    di = memoryAGet16(ds, bx + 8501);
    di -= 0x00a4;
    cx = 0x000e;
loc_14e8c:
    al = memoryAGet(ds, si);
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_14e8c;
    di += 0x0084;
    al = memoryAGet(ds, si + 28);
    memoryASet16(es, di, ax);
    di += 0x001a;
    memoryASet16(es, di, ax);
    di += 0x0086;
    cx = 0x000e;
loc_14eae:
    al = memoryAGet(ds, si);
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_14eae;
    al = memoryAGet(ds, si + 14);
    cx = memoryAGet16(ds, bx + 8531);
    cx--;
    cx <<= 1;
    cx--;
    di -= 0x0002;
loc_14ec7:
    di += 0x0086;
    memoryASet16(es, di, ax);
    di += 0x001a;
    memoryASet16(es, di, ax);
    if (--cx)
        goto loc_14ec7;
    di += 0x0086;
    cx = 0x000e;
loc_14edd:
    al = memoryAGet(ds, si);
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_14edd;
}
void sub_14ee9()
{
    dx = 0x2ff;
    sub_17f06();
    if (memoryAGet(ds, 0x031f) == 0x00)
        goto loc_14eff;
    si = 0x13b0;
    sub_15666();
    return;
loc_14eff:
    si = 0;
    di = 0;
    sub_14f52();
loc_14f06:
    sub_181a3();
    if (al == 0x1b)
        goto loc_14f11;
    if (al != 0x0d)
        goto loc_14f16;
loc_14f11:
    es = memoryAGet16(ds, 0x024f);
    return;
loc_14f16:
    if (al != 0x00)
        goto loc_14f06;
    if (ah != 0x48)
        goto loc_14f22;
    goto loc_14f2a;
loc_14f22:
    if (ah != 0x50)
        goto loc_14f06;
    goto loc_14f47;
loc_14f2a:
    if (bx == 0x0000)
        goto loc_14f06;
    si = bx;
    cx = 0x001a;
loc_14f34:
    tx = si;
    si--;
    if (tx == 1)
        goto loc_14f42;
    if (memoryAGet(es, si) != 0x0d)
        goto loc_14f34;
    if (--cx)
        goto loc_14f34;
    si += 0x0002;
loc_14f42:
    sub_14f52();
    goto loc_14f06;
loc_14f47:
    if (memoryAGet(es, si) == 0x1a)
        goto loc_14f06;
    sub_14f52();
    goto loc_14f06;
}
void sub_14f52()
{
    es = memoryAGet16(ds, 0x024f);
    sub_14791();
    ah = 0x04;
    bx = si;
    cx = 0x0019;
loc_14f60:
    push(di);
loc_14f61:
    es = memoryAGet16(ds, 0x026b);
    al = memoryAGet(es, si);
    si++;
    if (al == 0x0d)
        goto loc_14f79;
    es = memoryAGet16(ds, 0x024f);
    memoryASet16(es, di, ax);
    di += 0x0002;
    goto loc_14f61;
loc_14f79:
    si++;
    di = pop();
    di += 0x00a0;
    if (--cx)
        goto loc_14f60;
    di = 0x13d4;
    if (bx == 0x0000)
        goto loc_14f98;
    di = 0x13fa;
    if (memoryAGet(es, si) != 0x1a)
        goto loc_14f98;
    di = 0x1423;
loc_14f98:
    push(si);
    si = di;
    es = memoryAGet16(ds, 0x024f);
    sub_15666();
    es = memoryAGet16(ds, 0x026b);
    si = pop();
    di = 0;
    push(bx);
    push(dx);
    dx = 0x1a00;
    sub_158ec();
    dx = pop();
    bx = pop();
}
void sub_14fb4()
{
    push(0x7777);
    goto loc_14fb4;
loc_13f65:
    ax = 0x0003;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    es = memoryAGet16(ds, 0x024f);
    sub_147ba();
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_13f89;
    sub_153f0();
loc_13f89:
    sub_1487f();
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
loc_13f93:
    ax = memoryAGet16(ds, 0x0261);
    sub_1461b();
    ax = 0x0010;
    interrupt(0x10);
    al = memoryAGet(ds, 0x0650);
    memoryASet(ds, 0x064f, al);
    memoryASet(ds, 0x064e, 0x01);
    if (memoryAGet(ds, 0x064f) != 0x01)
        goto loc_13fb6;
    sub_14119();
    goto loc_13fb9;
loc_13fb6:
    sub_141d6();
loc_13fb9:
    sp = memoryAGet16(ds, 0x0251);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_13f93;
    memoryASet(ds, 0x064e, 0x00);
    goto loc_13f65;
loc_13fe7:
    sub_15b67();
    sub_15d57();
    assert(pop() == 0x7777);
    return;
    //   gap of 3486 bytes
loc_14d8c:
    if (bx == 0x0000)
        goto loc_14d99;
    dx = bx;
    bx = 0x0004;
    goto loc_14df0;
loc_14d99:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14db7;
    memoryASet(ds, 0x212a, 0x01);
    sub_14791();
    ah = 0x04;
    sub_154e6();
    sub_14791();
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14db7:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14dd2;
    sub_14ee9();
    if (memoryAGet(ds, 0x031f) == 0x01)
        goto loc_14dcc;
    sub_14791();
loc_14dcc:
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14dd2:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14dde;
    sub_14fb4();
    assert(pop() == 0x7777);
    return;
loc_14dde:
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14def;
    memoryASet(ds, 0x2129, 0x01);
    memoryASet(ds, 0x2128, 0x01);
loc_14def:
    assert(pop() == 0x7777);
    return;
loc_14df0:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14e09;
    sub_14e49();
    memoryASet(ds, 0x064e, 0x00);
    memoryASet(ds, 0x0063, 0x01);
    goto loc_13fb9;
    //   gap of 1 bytes
loc_14e09:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14e24;
    if (memoryAGet(ds, 0x064e) == 0x01)
        goto loc_14e1b;
    bx = dx;
    assert(pop() == 0x7777);
    return;
loc_14e1b:
    memoryASet(ds, 0x2128, 0x01);
    sub_14e49();
    assert(pop() == 0x7777);
    return;
loc_14e24:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14e30;
    sub_152c7();
    assert(pop() == 0x7777);
    return;
loc_14e30:
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0065, 0x01);
    memoryASet(ds, 0x2128, 0x01);
    goto loc_13fb9;
    //   gap of 364 bytes
loc_14fb4:
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14fcd;
    si = 0x1178;
    sub_15666();
    di = 0x082c;
    sub_1514d();
    if (al == 0x59)
        goto loc_14fcd;
    assert(pop() == 0x7777);
    return;
loc_14fcd:
    al = memoryAGet(ds, 0x0254);
    memoryASet(ds, 0x0255, al);
    memoryASet(ds, 0x0254, 0x00);
    memoryASet16(ds, 0x310d, 0x0000);
    dx = 0x249;
loc_14fe2:
    sub_150e5();
    if (memoryAGet(ds, 0x0249) != 0x0d)
        goto loc_14fe2;
    memoryASet16(ds, 0x111b, 0x3039);
    memoryASet(ds, 0x111d, 0x00);
    memoryASet(ds, 0x1449, 0x01);
    memoryASet16(ds, 0x2145, 0x0140);
    memoryASet16(ds, 0x2163, 0x0000);
    sub_14e49();
    memoryASet16(ds, 0x2143, 0x0140);
    memoryASet16(ds, 0x2161, 0x0000);
    bx = 0x0004;
    goto loc_14d8c;
}
void sub_15079()
{
    memoryASet(ds, 0x1449, 0x00);
    push(ax);
    push(bx);
    bx = memoryAGet16(ds, 0x031b);
    ah = 0x3e;
    interrupt(0x21);
    memoryASet16(ds, 0x144b, 0x0000);
    al = memoryAGet(ds, 0x0255);
    memoryASet(ds, 0x0254, al);
    bx = pop();
    ax = pop();
}
void sub_15097()
{
    push(0x7777);
    goto loc_15097;
loc_13f65:
    ax = 0x0003;
    interrupt(0x10);
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    bl = 0x00;
    ax = 0x1003;
    interrupt(0x10);
    es = memoryAGet16(ds, 0x024f);
    sub_147ba();
    if (memoryAGet(ds, 0x212a) != 0x01)
        goto loc_13f89;
    sub_153f0();
loc_13f89:
    sub_1487f();
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
loc_13f93:
    ax = memoryAGet16(ds, 0x0261);
    sub_1461b();
    ax = 0x0010;
    interrupt(0x10);
    al = memoryAGet(ds, 0x0650);
    memoryASet(ds, 0x064f, al);
    memoryASet(ds, 0x064e, 0x01);
    if (memoryAGet(ds, 0x064f) != 0x01)
        goto loc_13fb6;
    sub_14119();
    goto loc_13fb9;
loc_13fb6:
    sub_141d6();
loc_13fb9:
    sp = memoryAGet16(ds, 0x0251);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    if (memoryAGet(ds, 0x0065) == 0x01)
        goto loc_13fe7;
    if (memoryAGet(ds, 0x0063) == 0x01)
        goto loc_13f93;
    memoryASet(ds, 0x064e, 0x00);
    goto loc_13f65;
loc_13fe7:
    sub_15b67();
    sub_15d57();
    assert(pop() == 0x7777);
    return;
    //   gap of 3486 bytes
loc_14d8c:
    if (bx == 0x0000)
        goto loc_14d99;
    dx = bx;
    bx = 0x0004;
    goto loc_14df0;
loc_14d99:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14db7;
    memoryASet(ds, 0x212a, 0x01);
    sub_14791();
    ah = 0x04;
    sub_154e6();
    sub_14791();
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14db7:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14dd2;
    sub_14ee9();
    if (memoryAGet(ds, 0x031f) == 0x01)
        goto loc_14dcc;
    sub_14791();
loc_14dcc:
    memoryASet(ds, 0x212a, 0x01);
    assert(pop() == 0x7777);
    return;
loc_14dd2:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14dde;
    sub_14fb4();
    assert(pop() == 0x7777);
    return;
loc_14dde:
    if (memoryAGet(ds, 0x064e) != 0x01)
        goto loc_14def;
    memoryASet(ds, 0x2129, 0x01);
    memoryASet(ds, 0x2128, 0x01);
loc_14def:
    assert(pop() == 0x7777);
    return;
loc_14df0:
    if (memoryAGet16(ds, bx + 8511) != 0x0140)
        goto loc_14e09;
    sub_14e49();
    memoryASet(ds, 0x064e, 0x00);
    memoryASet(ds, 0x0063, 0x01);
    goto loc_13fb9;
    //   gap of 1 bytes
loc_14e09:
    if (memoryAGet16(ds, bx + 8511) != 0x0280)
        goto loc_14e24;
    if (memoryAGet(ds, 0x064e) == 0x01)
        goto loc_14e1b;
    bx = dx;
    assert(pop() == 0x7777);
    return;
loc_14e1b:
    memoryASet(ds, 0x2128, 0x01);
    sub_14e49();
    assert(pop() == 0x7777);
    return;
loc_14e24:
    if (memoryAGet16(ds, bx + 8511) != 0x03c0)
        goto loc_14e30;
    sub_152c7();
    assert(pop() == 0x7777);
    return;
loc_14e30:
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0065, 0x01);
    memoryASet(ds, 0x2128, 0x01);
    goto loc_13fb9;
    //   gap of 400 bytes
loc_14fd8:
    memoryASet16(ds, 0x310d, 0x0000);
    dx = 0x249;
loc_14fe2:
    sub_150e5();
    if (memoryAGet(ds, 0x0249) != 0x0d)
        goto loc_14fe2;
    memoryASet16(ds, 0x111b, 0x3039);
    memoryASet(ds, 0x111d, 0x00);
    memoryASet(ds, 0x1449, 0x01);
    memoryASet16(ds, 0x2145, 0x0140);
    memoryASet16(ds, 0x2163, 0x0000);
    sub_14e49();
    memoryASet16(ds, 0x2143, 0x0140);
    memoryASet16(ds, 0x2161, 0x0000);
    bx = 0x0004;
    goto loc_14d8c;
    //   gap of 1 bytes
loc_1501e:
    dx = pop();
    cx = pop();
    bx = pop();
    memoryASet(ds, 0x1449, 0x00);
    sub_175f8();
    memoryASet(ds, 0x144a, 0x01);
    sub_17885();
    memoryASet(ds, 0x144a, 0x00);
    if (ax == 0xffff)
        goto loc_15052;
    sub_15079();
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0246, 0x01);
    ax = 0xffff;
    assert(pop() == 0x7777);
    return;
loc_15052:
    goto loc_14fd8;
    //   gap of 67 bytes
loc_15097:
    if (ax == 0xffff)
        goto loc_150b3;
    sub_15079();
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    memoryASet(ds, 0x0246, 0x01);
    ax = 0xffff;
    assert(pop() == 0x7777);
    return;
loc_150b3:
    push(bx);
    push(cx);
    push(dx);
    if (memoryAGet16(ds, 0x0247) != 0x0000)
        goto loc_150d3;
    dx = 0x249;
    sub_150e5();
    ax = memoryAGet16(ds, 0x0249);
    if (ax != 0xffff)
        goto loc_150da;
    dx = 0x247;
    sub_150e5();
loc_150d3:
    memoryASet16(ds, 0x0247, memoryAGet16(ds, 0x0247) - 1);
    ax = 0xffff;
loc_150da:
    if (al != 0x1b)
        goto loc_150e1;
    goto loc_1501e;
loc_150e1:
    dx = pop();
    cx = pop();
    bx = pop();
    assert(pop() == 0x7777);
}
void sub_150e5()
{
    push(si);
    push(bx);
    bx = dx;
    si = memoryAGet16(ds, 0x310d);
    memoryASet16(ds, 0x310d, memoryAGet16(ds, 0x310d) + 0x0002);
    ax = memoryAGet16(ds, si + 12559);
    memoryASet16(ds, bx, ax);
    bx = pop();
    si = pop();
}
void sub_1514d()
{
    memoryASet16(ds, 0x026e, di);
    si = 0x0000;
    cx = 0x0004;
loc_15157:
    push(cx);
    cx = 0x0007;
loc_1515b:
    ax = memoryAGet16(es, di);
    memoryASet16(ds, si + 4388, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_1515b;
    di += 0x0092;
    cx = pop();
    if (--cx)
        goto loc_15157;
    ah = 0x04;
    si = 0x0000;
    di = memoryAGet16(ds, 0x026e);
    cx = 0x0004;
loc_1517d:
    push(cx);
    cx = 0x0007;
loc_15181:
    al = memoryAGet(ds, si + 4444);
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_15181;
    di += 0x0092;
    cx = pop();
    if (--cx)
        goto loc_1517d;
    ah = 0x01;
    di = memoryAGet16(ds, 0x026e);
    memoryASet(es, di + 165, ah);
    memoryASet(es, di + 167, ah);
    memoryASet(es, di + 169, ah);
loc_151aa:
    sub_181a3();
    if (al == 0x00)
        goto loc_151cb;
    if (al == 0x1b)
        goto loc_15214;
    if (al == 0x0d)
        goto loc_15219;
    if (al == 0x59)
        goto loc_151d7;
    if (al == 0x79)
        goto loc_151d7;
    if (al == 0x4e)
        goto loc_151e6;
    if (al == 0x6e)
        goto loc_151e6;
    goto loc_151aa;
loc_151cb:
    if (ah == 0x48)
        goto loc_151d7;
    if (ah == 0x50)
        goto loc_151e6;
    goto loc_151aa;
loc_151d7:
    if (memoryAGet(ds, 0x1123) == 0x59)
        goto loc_151aa;
    memoryASet(ds, 0x1123, 0x59);
    goto loc_151f2;
loc_151e6:
    if (memoryAGet(ds, 0x1123) == 0x4e)
        goto loc_151aa;
    memoryASet(ds, 0x1123, 0x4e);
loc_151f2:
    di = memoryAGet16(ds, 0x026e);
    cx = 0x0003;
loc_151f9:
    ah = memoryAGet(es, di + 165);
    al = memoryAGet(es, di + 325);
    memoryASet(es, di + 165, al);
    memoryASet(es, di + 325, ah);
    di += 0x0002;
    if (--cx)
        goto loc_151f9;
    goto loc_151aa;
loc_15214:
    memoryASet(ds, 0x1123, 0x45);
loc_15219:
    al = memoryAGet(ds, 0x1123);
    push(ax);
    memoryASet(ds, 0x1123, 0x59);
    si = 0x0000;
    di = memoryAGet16(ds, 0x026e);
    cx = 0x0004;
loc_1522c:
    push(cx);
    cx = 0x0007;
loc_15230:
    ax = memoryAGet16(ds, si + 4388);
    memoryASet16(es, di, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_15230;
    di += 0x0092;
    cx = pop();
    if (--cx)
        goto loc_1522c;
    ax = pop();
}
void sub_15248()
{
    if (al != 0x45)
        goto loc_1524d;
    return;
loc_1524d:
    if (al != 0x4b)
        goto loc_1525c;
    memoryASet(ds, 0x0254, 0x00);
    memoryASet(ds, 0x11c1, 0x4b);
    return;
loc_1525c:
    dx = 0x0201;
    al = 0x00;
    out(dx, al);
    cx = 0x2710;
loc_15265:
    in(al, dx);
    if (--cx)
        goto loc_15265;
    if (al != 0xff)
        goto loc_15288;
    si = 0x12e9;
    sub_15666();
    di = 0x0af4;
    sub_1514d();
    if (al == 0x59)
        goto loc_15288;
loc_1527d:
    memoryASet(ds, 0x0254, 0x00);
    memoryASet(ds, 0x11c1, 0x4b);
    return;
loc_15288:
    si = 0x132a;
    sub_15666();
loc_1528f:
    sub_181a3();
    if (al == 0x1b)
        goto loc_1527d;
    if (al != 0x0d)
        goto loc_1528f;
    ax = 0;
    ah++;
    sub_152b4();
    memoryASet16(ds, 0x0257, cx);
    ah++;
    sub_152b4();
    memoryASet16(ds, 0x0259, cx);
    memoryASet(ds, 0x0254, 0x01);
}
void sub_152b4()
{
    dx = 0x0201;
    cx = 0x0400;
loc_152ba:
    if (--cx)
        goto loc_152ba;
    al = 0x00;
    out(dx, al);
loc_152bf:
    in(al, dx);
    if (--cx && al & ah)
        goto loc_152bf;
    cx = -cx;
}
void sub_152c7()
{
    al = memoryAGet(ds, 0x11c1);
    memoryASet(ds, 0x11c2, al);
    di = memoryAGet16(ds, 0x11bf);
    si = 0x0000;
    cx = 0x0007;
loc_152d7:
    push(cx);
    cx = 0x000e;
loc_152db:
    ax = memoryAGet16(es, di);
    memoryASet16(ds, si + 4547, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_152db;
    di += 0x0084;
    cx = pop();
    if (--cx)
        goto loc_152d7;
    si = 0x0000;
    di = memoryAGet16(ds, 0x11bf);
    cx = 0x0007;
loc_152fb:
    push(cx);
    cx = 0x000e;
loc_152ff:
    al = memoryAGet(ds, si + 4743);
    ah = 0x04;
    if (al > 0x7b)
        goto loc_1530b;
    ah = 0x01;
loc_1530b:
    memoryASet16(es, di, ax);
    si++;
    di += 0x0002;
    if (--cx)
        goto loc_152ff;
    di += 0x0084;
    cx = pop();
    if (--cx)
        goto loc_152fb;
    cx = 0x0008;
    di = memoryAGet16(ds, 0x11bf);
    di += 0x01e7;
    if (memoryAGet(ds, 0x11c1) == 0x4a)
        goto loc_15331;
    di += 0x0140;
loc_15331:
    memoryASet(es, di, ah);
    di += 0x0002;
    if (--cx)
        goto loc_15331;
    si = 0x1360;
    sub_15666();
loc_15340:
    sub_181a3();
    if (al == 0x00)
        goto loc_15361;
    if (al == 0x1b)
        goto loc_153b8;
    if (al == 0x0d)
        goto loc_153c3;
    if (al == 0x4b)
        goto loc_1536d;
    if (al == 0x6b)
        goto loc_1536d;
    if (al == 0x4a)
        goto loc_15383;
    if (al == 0x6a)
        goto loc_15383;
    goto loc_15340;
loc_15361:
    if (ah == 0x48)
        goto loc_1536d;
    if (ah == 0x50)
        goto loc_15383;
    goto loc_15340;
loc_1536d:
    if (memoryAGet(ds, 0x11c1) == 0x4b)
        goto loc_15340;
    memoryASet(ds, 0x11c1, 0x4b);
    si = 0x1360;
    sub_15666();
    goto loc_15396;
loc_15383:
    if (memoryAGet(ds, 0x11c1) == 0x4a)
        goto loc_15340;
    memoryASet(ds, 0x11c1, 0x4a);
    si = 0x1388;
    sub_15666();
loc_15396:
    di = memoryAGet16(ds, 0x11bf);
    cx = 0x0008;
loc_1539d:
    ah = memoryAGet(es, di + 487);
    al = memoryAGet(es, di + 807);
    memoryASet(es, di + 487, al);
    memoryASet(es, di + 807, ah);
    di += 0x0002;
    if (--cx)
        goto loc_1539d;
    goto loc_15340;
loc_153b8:
    al = memoryAGet(ds, 0x11c2);
    memoryASet(ds, 0x11c1, al);
    al = 0x45;
    goto loc_153c6;
loc_153c3:
    al = memoryAGet(ds, 0x11c1);
loc_153c6:
    push(ax);
    sub_15248();
    si = 0x0000;
    di = memoryAGet16(ds, 0x11bf);
    cx = 0x0007;
loc_153d4:
    push(cx);
    cx = 0x000e;
loc_153d8:
    ax = memoryAGet16(ds, si + 4547);
    memoryASet16(es, di, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_153d8;
    di += 0x0084;
    cx = pop();
    if (--cx)
        goto loc_153d4;
    ax = pop();
}
void sub_153f0()
{
    memoryASet(ds, 0x212a, 0x00);
    memoryASet(ds, 0x2120, 0x08);
    memoryASet16(ds, 0x211e, 0x0500);
    ax = memoryAGet16(ds, 0x0211);
    bx = 0x0000;
loc_15406:
    if ((short)ax <= (short)memoryAGet16(ds, bx + 6712))
        goto loc_1540f;
    goto loc_15496;
loc_1540f:
    memoryASet(ds, 0x2120, memoryAGet(ds, 0x2120) + 1);
    memoryASet16(ds, 0x211e, memoryAGet16(ds, 0x211e) + 0x00a0);
    bx += 0x0002;
    if (bx != 0x0014)
        goto loc_15406;
    if (memoryAGet(ds, 0x064f) == 0x02)
        goto loc_15442;
    memoryASet(ds, 0x1a36, 0x01);
    memoryASet(ds, 0x1e98, 0x20);
    memoryASet(ds, 0x1e99, 0x20);
    di = 0x1ec3;
    bp = 0x194e;
    goto loc_1547f;
loc_15442:
    memoryASet(ds, 0x1a36, 0x02);
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_15468;
    memoryASet(ds, 0x1a37, 0x01);
    memoryASet(ds, 0x1ee2, 0x20);
    memoryASet(ds, 0x1ee3, 0x20);
    di = 0x1f0d;
    bp = 0x1983;
    goto loc_1547f;
loc_15468:
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1f2c, 0x20);
    memoryASet(ds, 0x1f2d, 0x20);
    di = 0x1f57;
    bp = 0x19b8;
loc_1547f:
    memoryASet(ds, 0x1a33, 0x01);
    memoryASet16(ds, 0x1a34, 0x0064);
    sub_156e7();
    ah = 0x04;
    sub_154e6();
    sub_180e0();
    return;
loc_15496:
    memoryASet(ds, 0x1a33, 0x00);
    sub_15697();
    sub_159b3();
    sub_14791();
    ah = 0x04;
    sub_154e6();
}
void sub_154aa()
{
    sub_147e7();
    si = 0x1a4e;
    di = 0x0288;
    sub_15c79();
    si = 0x1e96;
    if (memoryAGet(ds, 0x1a36) == 0x01)
        goto loc_154d4;
    si = 0x1ee0;
    if (memoryAGet(ds, 0x1a37) == 0x01)
        goto loc_154d4;
    sub_15c79();
    si = 0x1f2a;
loc_154d4:
    sub_15c79();
    si = 0x1f74;
    sub_15c79();
    si = 0x24fe;
    sub_1564c();
}
void sub_154e6()
{
    bh = ah;
loc_154e8:
    ah = bh;
    sub_154aa();
    memoryASet(ds, 0x212a, 0x01);
    si = 0x209c;
    sub_15666();
    sub_1556b();
    if (al == 0x00)
        return;
    if (al != 0x20)
        return;
    push(bx);
    sub_15b67();
    sub_155c9();
    bx = pop();
    ah = bh;
    si = 0x14c5;
    di = 0x0008;
    sub_15c79();
    si = 0x170e;
    di = 0x0532;
    sub_15c79();
    si = 0x194b;
    if (memoryAGet(ds, 0x1a36) == 0x01)
        goto loc_1553f;
    si = 0x1980;
    if (memoryAGet(ds, 0x1a37) == 0x01)
        goto loc_1553f;
    sub_15c79();
    si = 0x19b5;
loc_1553f:
    sub_15c79();
    si = 0x19ea;
    sub_15c79();
    si = 0x2508;
    sub_1564c();
    si = 0x20de;
    sub_15666();
    sub_1556b();
    memoryASet(ds, 0x212a, 0x00);
    if (al == 0x00)
        return;
    if (al != 0x20)
        return;
    goto loc_154e8;
}
void sub_1556b()
{
loc_1556b:
    push(bx);
    bl = 0x02;
    memoryASet(ds, 0x2512, memoryAGet(ds, 0x2512) + 1);
    memoryASet(ds, 0x2512, memoryAGet(ds, 0x2512) & 0x3f);
    memoryASet(ds, 0x2512, memoryAGet(ds, 0x2512) | 0x38);
    if (memoryAGet(ds, 0x2512) != 0x38)
        goto loc_15587;
    memoryASet(ds, 0x2512, memoryAGet(ds, 0x2512) + 1);
loc_15587:
    bh = memoryAGet(ds, 0x2512);
    ax = 0x1000;
    interrupt(0x10);
    bx = pop();
    push(memoryAGet16(ds, 0x1120));
    push(memoryAGet16(ds, 0x0401));
    memoryASet16(ds, 0x1120, pop());
    memoryASet16(ds, 0x111e, 0x01f4);
    sub_17805();
    memoryASet16(ds, 0x1120, pop());
    if (memoryAGet(ds, 0x1122) == 0x00)
        goto loc_1556b;
    if (memoryAGet(ds, 0x0256) == 0x00)
        goto loc_155c5;
    if (al == 0x0d)
        return;
    if (al != 0x1b)
        goto loc_1556b;
    al = 0x20;
    return;
loc_155c5:
    sub_180e0();
}
void sub_155c9()
{
    push(bx);
    bp = 0x1a1f;
    di = 0x1525;
    sub_155e2();
    bp = 0x1a29;
    di = 0x156e;
    sub_155e2();
    bx = pop();
}
void sub_155e2()
{
    bx = 0;
    si = 0;
    memoryASet(ds, 0x1456, 0x00);
loc_155eb:
    cx = memoryAGet16(ds, bx + 5207);
    bx += bp;
    dx = memoryAGet16(ds, bx);
    bx -= bp;
    if (dx != 0x0000)
        goto loc_1560f;
    if (memoryAGet(ds, 0x1456) == 0x01)
        goto loc_1560f;
    si += memoryAGet16(ds, bx + 5207);
    al = 0x20;
loc_15607:
    memoryASet(ds, di, al);
    di++;
    if (--cx)
        goto loc_15607;
    goto loc_15643;
loc_1560f:
    push(bx);
    memoryASet(ds, 0x1456, 0x01);
    ax = memoryAGet16(ds, bx + 5223);
    bx = 0x1075;
    bx += ax;
    ah = 0x04;
    push(dx);
    sub_15c46();
    dx = pop();
    bx = pop();
    cx -= memoryAGet16(ds, bx + 5215);
    si += memoryAGet16(ds, bx + 5215);
    di++;
loc_15630:
    al = memoryAGet(ds, si + 5274);
    if (dx != 0x0001)
        goto loc_1563d;
    al = memoryAGet(ds, si + 5231);
loc_1563d:
    memoryASet(ds, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_15630;
loc_15643:
    bx += 0x0002;
    if (bx != 0x0008)
        goto loc_155eb;
}
void sub_1564c()
{
    ah = 0x02;
    di = 0x05a2;
    cx = 0x000a;
loc_15654:
    al = memoryAGet(ds, si);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 154, ax);
    si++;
    di += 0x00a0;
    if (--cx)
        goto loc_15654;
}
void sub_15666()
{
    ah = 0x04;
    al = 0x20;
    cx = 0x00f0;
    di = 0x0dc0;
    bp = 0x0eb0;
    if (si >= 0x13d4)
        goto loc_1567f;
    di = 0x0d20;
    bp = 0x0e10;
loc_1567f:
    memoryASet16(es, di, ax);
    di += 0x0002;
    if (--cx)
        goto loc_1567f;
    sub_1568b();
}
void sub_1568b()
{
    goto loc_1568b;
loc_14d20:
    ah = 0x00;
    di -= ax;
    di >>= 1;
    di <<= 1;
    push(di);
    bp = ax;
    bp <<= 1;
    ah = 0x01;
    di -= 0x00a2;
    memoryASet(es, di + 65534, 0xda);
    memoryASet(es, di + 158, 0xb3);
    memoryASet(es, di + 318, 0xc0);
    memoryASet(es, bp + di + 4, 0xbf);
    memoryASet(es, bp + di + 164, 0xb3);
    memoryASet(es, bp + di + 324, 0xd9);
    bp >>= 1;
    bp += 0x0002;
    cx = 0x0002;
loc_14d5d:
    push(cx);
    cx = bp;
loc_14d60:
    memoryASet(es, di, 0xc4);
    di += 0x0002;
    if (--cx)
        goto loc_14d60;
    di += 0x0140;
    di -= bp;
    di -= bp;
    cx = pop();
    if (--cx)
        goto loc_14d5d;
    di = pop();
    si = pop();
    si = memoryAGet16(ds, si);
    si++;
    sub_15c79();
    si = pop();
    si += 0x0002;
    si = memoryAGet16(ds, si);
    if (si == 0x0000)
        goto loc_14d8b;
    si++;
    sub_15c79();
loc_14d8b:
    return;
    //   gap of 2303 bytes
loc_1568b:
    ax = memoryAGet16(ds, si);
    si += 0x0002;
    push(si);
    push(si);
    di = bp;
    goto loc_14d20;
}
void sub_15697()
{
    push(bx);
    push(ds);
    es = pop();
    si = 0x1a4a;
    di = si;
    di += 0x0002;
    cx = 0x000a;
    bx >>= 1;
    cx -= bx;
    flags.direction = true;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, di, ax);
    si = 0x1dc2;
    di = si;
    di += 0x0049;
    cx = 0x0009;
    cx -= bx;
    if (cx == 0x0000)
        goto loc_156d6;
loc_156c2:
    push(cx);
    push(si);
    push(di);
    cx = 0x003f;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    si = pop();
    si -= 0x0049;
    di -= 0x0049;
    cx = pop();
    if (--cx)
        goto loc_156c2;
loc_156d6:
    memoryASet16(ds, 0x211c, di);
    dl = 0x20;
    cx = 0x0022;
loc_156df:
    memoryASet(ds, di, dl);
    di++;
    if (--cx)
        goto loc_156df;
    di += 0x0003;
    dx = ax;
    bx = 0x1075;
loc_156ed:
    al = 0x00;
loc_156ef:
    if ((short)dx < (short)memoryAGet16(ds, bx))
        goto loc_156f9;
    al++;
    dx -= memoryAGet16(ds, bx);
    goto loc_156ef;
loc_156f9:
    al += 0x30;
    memoryASet(ds, di, al);
    di++;
    bx += 0x0002;
    al = 0x0a;
    if (memoryAGet(ds, bx + 65534) != al)
        goto loc_156ed;
    al = dl;
    al += 0x30;
    memoryASet(ds, di, al);
    di += 0x0005;
    sub_15cb2();
    al = cl;
    sub_15c9a();
    al = dh;
    sub_15c9a();
    al = dl;
    sub_15c9a();
    sub_15cc3();
    di += 0x0002;
    al = ch;
    sub_15c9a();
    al = cl;
    sub_15c9a();
    if (memoryAGet(ds, 0x1a33) != 0x01)
        goto loc_1573d;
    goto loc_159e4;
loc_1573d:
    es = memoryAGet16(ds, 0x024f);
    ah = 0x07;
    sub_154aa();
    di = memoryAGet16(ds, 0x211e);
    memoryASet(es, di + 13, 0x05);
    memoryASet(es, di + 15, 0x05);
    di += 0x0019;
    cx = 0x0022;
loc_1575a:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_1575a;
    di += 0x0006;
    cx = 0x0006;
loc_15769:
    memoryASet(es, di, 0x05);
    di += 0x0002;
    if (--cx)
        goto loc_15769;
    di += 0x0006;
    cx = 0x0008;
loc_15778:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_15778;
    di += 0x0006;
    cx = 0x0005;
loc_15787:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_15787;
    si = 0x1fbe;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_157aa;
    si = 0x1fe2;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_157aa;
    si = 0x2011;
loc_157aa:
    sub_15666();
    si = 0x0000;
    di = memoryAGet16(ds, 0x211c);
    dh = memoryAGet(ds, 0x2120);
    dl = 0x0c;
    sub_158ec();
    cx = 0x0607;
    ah = 0x01;
    interrupt(0x10);
loc_157c4:
    sub_181a3();
    if (al == 0x0d)
        goto loc_1582c;
    if (al == 0x09)
        goto loc_1580d;
    if (al == 0x08)
        goto loc_157df;
    if (al == 0x00)
        goto loc_157da;
    goto loc_158bd;
loc_157da:
    if (ah != 0x53)
        goto loc_157c4;
loc_157df:
    al = 0x20;
    if (dl == memoryAGet(ds, si + 8481))
        goto loc_15806;
    if (dl != memoryAGet(ds, si + 8484))
        goto loc_157f1;
    if (memoryAGet(ds, di) != al)
        goto loc_15806;
loc_157f1:
    di--;
    dl--;
    if (dl == 0x3c)
        goto loc_157f1;
    if (dl == 0x3f)
        goto loc_157f1;
    if (dl == 0x47)
        goto loc_157f1;
    sub_158ec();
loc_15806:
    memoryASet(ds, di, al);
    sub_158e0();
    goto loc_157c4;
loc_1580d:
    si++;
    if (si != 0x0003)
        goto loc_15816;
    si = 0x0000;
loc_15816:
    dl = memoryAGet(ds, si + 8481);
    sub_158ec();
    push(dx);
    dh = 0x00;
    di = memoryAGet16(ds, 0x211c);
    dx -= 0x000c;
    di += dx;
    dx = pop();
    goto loc_157c4;
loc_1582c:
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    si = memoryAGet16(ds, 0x211c);
    si += 0x0025;
    cx = 0x0019;
    memoryASet(ds, 0x1a36, 0x01);
    di = 0x1ec3;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_1586b;
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1a36, 0x02);
    di = 0x1f57;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_1586b;
    memoryASet(ds, 0x1a37, 0x01);
    di = 0x1f0d;
loc_1586b:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si++;
    di++;
    if (--cx)
        goto loc_1586b;
    dx = pop();
    push(dx);
    dx >>= 1;
    dx += 0x0001;
    bx = 0x107b;
    di -= 0x0044;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_158b4;
    if (dx > memoryAGet16(ds, 0x1a34))
        goto loc_158b4;
    if (memoryAGet16(ds, 0x1a34) != 0x000a)
        goto loc_158a2;
    memoryASet(ds, 0x1ee2, 0x20);
    memoryASet(ds, 0x1ee3, 0x20);
    goto loc_158b4;
loc_158a2:
    push(dx);
    push(bx);
    push(di);
    dx = memoryAGet16(ds, 0x1a34);
    dx++;
    di = 0x1ee2;
    sub_15c46();
    di = pop();
    bx = pop();
    dx = pop();
loc_158b4:
    memoryASet16(ds, 0x1a34, dx);
    sub_15c46();
    bx = pop();
    return;
loc_158bd:
    memoryASet(ds, di, al);
    sub_158e0();
    if (dl == memoryAGet(ds, si + 8484))
        goto loc_158dd;
loc_158c8:
    di++;
    dl++;
    if (dl == 0x3c)
        goto loc_158c8;
    if (dl == 0x3f)
        goto loc_158c8;
    if (dl == 0x47)
        goto loc_158c8;
    sub_158ec();
loc_158dd:
    goto loc_157c4;
    //   gap of 260 bytes
loc_159e4:
    si = 0x234;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_159f3;
    si = 0x23d;
loc_159f3:
    al = memoryAGet(ds, si + 6);
    di = bp;
    sub_15c9a();
    al = memoryAGet(ds, si + 7);
    sub_15c9a();
    al = memoryAGet(ds, si + 8);
    sub_15c9a();
    push(si);
    si = 0x3d3;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15a22;
    si = 0x218;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15a22;
    si = 0x21e;
loc_15a22:
    di = bp;
    dx = memoryAGet16(ds, si);
    dx += memoryAGet16(ds, si + 4);
    dx >>= 1;
    dx++;
    di += 0x000b;
    bx = 0x107b;
    sub_15c46();
    dx = memoryAGet16(ds, si + 2);
    di += 0x0003;
    bx = 0x107b;
    sub_15c46();
    si = pop();
    ah = 0x00;
    al = memoryAGet(ds, si + 6);
    if (al <= 0x11)
        goto loc_15a4f;
    al = 0x11;
loc_15a4f:
    cx = 0x0e10;
    mul(cx);
    dx = ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 7);
    cx = 0x003c;
    mul(cx);
    dx += ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 8);
    dx += ax;
    cx = dx;
    ax = 0x0000;
    dx = memoryAGet16(ds, si);
    ah = dl;
    dl = dh;
    dh = 0x00;
    div(cx);
    dx = ax;
    di = bp;
    di += 0x0015;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si);
    di += 0x001e;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si + 2);
    if (dx <= 0x03e7)
        goto loc_15aa2;
    dx = 0x03e7;
loc_15aa2:
    di += 0x0026;
    bx = 0x1079;
    sub_15c46();
    dx = memoryAGet16(ds, si + 4);
    if (dx <= 0x0063)
        goto loc_15ab7;
    dx = 0x0063;
loc_15ab7:
    di += 0x0004;
    bx = 0x107b;
    sub_15c46();
    if (memoryAGet(ds, 0x1a33) == 0x01)
        goto loc_15b06;
    si = bp;
    bp += 0x0003;
    cx = 0x002f;
    memoryASet(ds, 0x1a36, 0x01);
    di = 0x194e;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1a36, 0x02);
    di = 0x19b8;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x01);
    di = 0x1983;
loc_15afe:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si++;
    di++;
    if (--cx)
        goto loc_15afe;
loc_15b06:
    ax = memoryAGet16(ds, 0x1a2b);
    bx = memoryAGet16(ds, 0x1a2d);
    cx = memoryAGet16(ds, 0x1a2f);
    dx = memoryAGet16(ds, 0x1a31);
    si = 0x23a;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15b24;
    si = 0x243;
loc_15b24:
    dl += memoryAGet(ds, si + 2);
    if (dx < 0x003c)
        goto loc_15b31;
    cl++;
    dx -= 0x003c;
loc_15b31:
    memoryASet16(ds, 0x1a31, dx);
    cl += memoryAGet(ds, si + 1);
    if (cx < 0x003c)
        goto loc_15b42;
    bl++;
    cx -= 0x003c;
loc_15b42:
    memoryASet16(ds, 0x1a2f, cx);
    bl += memoryAGet(ds, si);
loc_15b48:
    if (bx < 0x0018)
        goto loc_15b53;
    bx -= 0x0018;
    ax++;
    goto loc_15b48;
loc_15b53:
    memoryASet16(ds, 0x1a2d, bx);
    if (ax <= 0x0007)
        goto loc_15b63;
    ax -= 0x0007;
    memoryASet16(ds, 0x1a29, memoryAGet16(ds, 0x1a29) + 1);
loc_15b63:
    memoryASet16(ds, 0x1a2b, ax);
}
void sub_156e7()
{
    dx = ax;
    bx = 0x1075;
loc_156ed:
    al = 0x00;
loc_156ef:
    if ((short)dx < (short)memoryAGet16(ds, bx))
        goto loc_156f9;
    al++;
    dx -= memoryAGet16(ds, bx);
    goto loc_156ef;
loc_156f9:
    al += 0x30;
    memoryASet(ds, di, al);
    di++;
    bx += 0x0002;
    al = 0x0a;
    if (memoryAGet(ds, bx + 65534) != al)
        goto loc_156ed;
    al = dl;
    al += 0x30;
    memoryASet(ds, di, al);
    di += 0x0005;
    sub_15cb2();
    al = cl;
    sub_15c9a();
    al = dh;
    sub_15c9a();
    al = dl;
    sub_15c9a();
    sub_15cc3();
    di += 0x0002;
    al = ch;
    sub_15c9a();
    al = cl;
    sub_15c9a();
    if (memoryAGet(ds, 0x1a33) != 0x01)
        goto loc_1573d;
    goto loc_159e4;
loc_1573d:
    es = memoryAGet16(ds, 0x024f);
    ah = 0x07;
    sub_154aa();
    di = memoryAGet16(ds, 0x211e);
    memoryASet(es, di + 13, 0x05);
    memoryASet(es, di + 15, 0x05);
    di += 0x0019;
    cx = 0x0022;
loc_1575a:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_1575a;
    di += 0x0006;
    cx = 0x0006;
loc_15769:
    memoryASet(es, di, 0x05);
    di += 0x0002;
    if (--cx)
        goto loc_15769;
    di += 0x0006;
    cx = 0x0008;
loc_15778:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_15778;
    di += 0x0006;
    cx = 0x0005;
loc_15787:
    memoryASet(es, di, 0x04);
    di += 0x0002;
    if (--cx)
        goto loc_15787;
    si = 0x1fbe;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_157aa;
    si = 0x1fe2;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_157aa;
    si = 0x2011;
loc_157aa:
    sub_15666();
    si = 0x0000;
    di = memoryAGet16(ds, 0x211c);
    dh = memoryAGet(ds, 0x2120);
    dl = 0x0c;
    sub_158ec();
    cx = 0x0607;
    ah = 0x01;
    interrupt(0x10);
loc_157c4:
    sub_181a3();
    if (al == 0x0d)
        goto loc_1582c;
    if (al == 0x09)
        goto loc_1580d;
    if (al == 0x08)
        goto loc_157df;
    if (al == 0x00)
        goto loc_157da;
    goto loc_158bd;
loc_157da:
    if (ah != 0x53)
        goto loc_157c4;
loc_157df:
    al = 0x20;
    if (dl == memoryAGet(ds, si + 8481))
        goto loc_15806;
    if (dl != memoryAGet(ds, si + 8484))
        goto loc_157f1;
    if (memoryAGet(ds, di) != al)
        goto loc_15806;
loc_157f1:
    di--;
    dl--;
    if (dl == 0x3c)
        goto loc_157f1;
    if (dl == 0x3f)
        goto loc_157f1;
    if (dl == 0x47)
        goto loc_157f1;
    sub_158ec();
loc_15806:
    memoryASet(ds, di, al);
    sub_158e0();
    goto loc_157c4;
loc_1580d:
    si++;
    if (si != 0x0003)
        goto loc_15816;
    si = 0x0000;
loc_15816:
    dl = memoryAGet(ds, si + 8481);
    sub_158ec();
    push(dx);
    dh = 0x00;
    di = memoryAGet16(ds, 0x211c);
    dx -= 0x000c;
    di += dx;
    dx = pop();
    goto loc_157c4;
loc_1582c:
    cx = 0x2000;
    ah = 0x01;
    interrupt(0x10);
    si = memoryAGet16(ds, 0x211c);
    si += 0x0025;
    cx = 0x0019;
    memoryASet(ds, 0x1a36, 0x01);
    di = 0x1ec3;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_1586b;
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1a36, 0x02);
    di = 0x1f57;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_1586b;
    memoryASet(ds, 0x1a37, 0x01);
    di = 0x1f0d;
loc_1586b:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si++;
    di++;
    if (--cx)
        goto loc_1586b;
    dx = pop();
    push(dx);
    dx >>= 1;
    dx += 0x0001;
    bx = 0x107b;
    di -= 0x0044;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_158b4;
    if (dx > memoryAGet16(ds, 0x1a34))
        goto loc_158b4;
    if (memoryAGet16(ds, 0x1a34) != 0x000a)
        goto loc_158a2;
    memoryASet(ds, 0x1ee2, 0x20);
    memoryASet(ds, 0x1ee3, 0x20);
    goto loc_158b4;
loc_158a2:
    push(dx);
    push(bx);
    push(di);
    dx = memoryAGet16(ds, 0x1a34);
    dx++;
    di = 0x1ee2;
    sub_15c46();
    di = pop();
    bx = pop();
    dx = pop();
loc_158b4:
    memoryASet16(ds, 0x1a34, dx);
    sub_15c46();
    bx = pop();
    return;
loc_158bd:
    memoryASet(ds, di, al);
    sub_158e0();
    if (dl == memoryAGet(ds, si + 8484))
        goto loc_158dd;
loc_158c8:
    di++;
    dl++;
    if (dl == 0x3c)
        goto loc_158c8;
    if (dl == 0x3f)
        goto loc_158c8;
    if (dl == 0x47)
        goto loc_158c8;
    sub_158ec();
loc_158dd:
    goto loc_157c4;
    //   gap of 260 bytes
loc_159e4:
    si = 0x234;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_159f3;
    si = 0x23d;
loc_159f3:
    al = memoryAGet(ds, si + 6);
    di = bp;
    sub_15c9a();
    al = memoryAGet(ds, si + 7);
    sub_15c9a();
    al = memoryAGet(ds, si + 8);
    sub_15c9a();
    push(si);
    si = 0x3d3;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15a22;
    si = 0x218;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15a22;
    si = 0x21e;
loc_15a22:
    di = bp;
    dx = memoryAGet16(ds, si);
    dx += memoryAGet16(ds, si + 4);
    dx >>= 1;
    dx++;
    di += 0x000b;
    bx = 0x107b;
    sub_15c46();
    dx = memoryAGet16(ds, si + 2);
    di += 0x0003;
    bx = 0x107b;
    sub_15c46();
    si = pop();
    ah = 0x00;
    al = memoryAGet(ds, si + 6);
    if (al <= 0x11)
        goto loc_15a4f;
    al = 0x11;
loc_15a4f:
    cx = 0x0e10;
    mul(cx);
    dx = ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 7);
    cx = 0x003c;
    mul(cx);
    dx += ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 8);
    dx += ax;
    cx = dx;
    ax = 0x0000;
    dx = memoryAGet16(ds, si);
    ah = dl;
    dl = dh;
    dh = 0x00;
    div(cx);
    dx = ax;
    di = bp;
    di += 0x0015;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si);
    di += 0x001e;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si + 2);
    if (dx <= 0x03e7)
        goto loc_15aa2;
    dx = 0x03e7;
loc_15aa2:
    di += 0x0026;
    bx = 0x1079;
    sub_15c46();
    dx = memoryAGet16(ds, si + 4);
    if (dx <= 0x0063)
        goto loc_15ab7;
    dx = 0x0063;
loc_15ab7:
    di += 0x0004;
    bx = 0x107b;
    sub_15c46();
    if (memoryAGet(ds, 0x1a33) == 0x01)
        goto loc_15b06;
    si = bp;
    bp += 0x0003;
    cx = 0x002f;
    memoryASet(ds, 0x1a36, 0x01);
    di = 0x194e;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1a36, 0x02);
    di = 0x19b8;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x01);
    di = 0x1983;
loc_15afe:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si++;
    di++;
    if (--cx)
        goto loc_15afe;
loc_15b06:
    ax = memoryAGet16(ds, 0x1a2b);
    bx = memoryAGet16(ds, 0x1a2d);
    cx = memoryAGet16(ds, 0x1a2f);
    dx = memoryAGet16(ds, 0x1a31);
    si = 0x23a;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15b24;
    si = 0x243;
loc_15b24:
    dl += memoryAGet(ds, si + 2);
    if (dx < 0x003c)
        goto loc_15b31;
    cl++;
    dx -= 0x003c;
loc_15b31:
    memoryASet16(ds, 0x1a31, dx);
    cl += memoryAGet(ds, si + 1);
    if (cx < 0x003c)
        goto loc_15b42;
    bl++;
    cx -= 0x003c;
loc_15b42:
    memoryASet16(ds, 0x1a2f, cx);
    bl += memoryAGet(ds, si);
loc_15b48:
    if (bx < 0x0018)
        goto loc_15b53;
    bx -= 0x0018;
    ax++;
    goto loc_15b48;
loc_15b53:
    memoryASet16(ds, 0x1a2d, bx);
    if (ax <= 0x0007)
        goto loc_15b63;
    ax -= 0x0007;
    memoryASet16(ds, 0x1a29, memoryAGet16(ds, 0x1a29) + 1);
loc_15b63:
    memoryASet16(ds, 0x1a2b, ax);
}
void sub_158e0()
{
    ah = 0x09;
    bh = 0x00;
    bl = 0x04;
    cx = 0x0001;
    interrupt(0x10);
}
void sub_158ec()
{
    ah = 0x02;
    bh = 0x00;
    interrupt(0x10);
}
void sub_158f3()
{
    if (memoryAGet(ds, 0x022d) == 0x01)
        goto loc_1590f;
    memoryASet(ds, 0x022d, 0x01);
    sub_15cc3();
    memoryASet(ds, 0x0230, ch);
    memoryASet(ds, 0x0231, cl);
    memoryASet(ds, 0x0232, dh);
    return;
loc_1590f:
    memoryASet(ds, 0x022d, 0x00);
    memoryASet16(ds, 0x022e, 0x0000);
    sub_15cc3();
    if (dh >= memoryAGet(ds, 0x0232))
        goto loc_15933;
    memoryASet(ds, 0x022e, 0x01);
    al = 0x3c;
    al -= memoryAGet(ds, 0x0232);
    dh += al;
    goto loc_15937;
loc_15933:
    dh -= memoryAGet(ds, 0x0232);
loc_15937:
    if (cl >= memoryAGet(ds, 0x0231))
        goto loc_1594d;
    memoryASet(ds, 0x022f, 0x01);
    al = 0x3c;
    al -= memoryAGet(ds, 0x0231);
    cl += al;
    goto loc_1595a;
loc_1594d:
    cl -= memoryAGet(ds, 0x0231);
    if (memoryAGet(ds, 0x022e) == 0x00)
        goto loc_1595a;
    cl--;
loc_1595a:
    if (ch >= memoryAGet(ds, 0x0230))
        goto loc_15974;
    al = 0x18;
    if (memoryAGet(ds, 0x022e) == 0x00)
        goto loc_1596b;
    al--;
loc_1596b:
    al -= memoryAGet(ds, 0x0230);
    ch += al;
    goto loc_15981;
loc_15974:
    ch -= memoryAGet(ds, 0x0230);
    if (memoryAGet(ds, 0x022f) == 0x00)
        goto loc_15981;
    ch--;
loc_15981:
    si = 0x23a;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15990;
    si = 0x243;
loc_15990:
    dh += memoryAGet(ds, si + 2);
    if (dh < 0x3c)
        goto loc_1599d;
    cl++;
    dh -= 0x3c;
loc_1599d:
    memoryASet(ds, si + 2, dh);
    cl += memoryAGet(ds, si + 1);
    if (cl < 0x3c)
        goto loc_159ad;
    ch++;
    cl -= 0x3c;
loc_159ad:
    memoryASet(ds, si + 1, cl);
    memoryASet(ds, si, memoryAGet(ds, si) + ch);
}
void sub_159b3()
{
    push(ds);
    es = pop();
    si = 0x18b1;
    di = si;
    di += 0x0034;
    cx = 0x0009;
    bx >>= 1;
    cx -= bx;
    if (cx == 0x0000)
        goto loc_159de;
loc_159ca:
    push(cx);
    push(si);
    push(di);
    cx = 0x002e;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    si = pop();
    si -= 0x0034;
    di -= 0x0034;
    cx = pop();
    if (--cx)
        goto loc_159ca;
loc_159de:
    es = memoryAGet16(ds, 0x024f);
    bp = di;
    si = 0x234;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_159f3;
    si = 0x23d;
loc_159f3:
    al = memoryAGet(ds, si + 6);
    di = bp;
    sub_15c9a();
    al = memoryAGet(ds, si + 7);
    sub_15c9a();
    al = memoryAGet(ds, si + 8);
    sub_15c9a();
    push(si);
    si = 0x3d3;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15a22;
    si = 0x218;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15a22;
    si = 0x21e;
loc_15a22:
    di = bp;
    dx = memoryAGet16(ds, si);
    dx += memoryAGet16(ds, si + 4);
    dx >>= 1;
    dx++;
    di += 0x000b;
    bx = 0x107b;
    sub_15c46();
    dx = memoryAGet16(ds, si + 2);
    di += 0x0003;
    bx = 0x107b;
    sub_15c46();
    si = pop();
    ah = 0x00;
    al = memoryAGet(ds, si + 6);
    if (al <= 0x11)
        goto loc_15a4f;
    al = 0x11;
loc_15a4f:
    cx = 0x0e10;
    mul(cx);
    dx = ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 7);
    cx = 0x003c;
    mul(cx);
    dx += ax;
    ah = 0x00;
    al = memoryAGet(ds, si + 8);
    dx += ax;
    cx = dx;
    ax = 0x0000;
    dx = memoryAGet16(ds, si);
    ah = dl;
    dl = dh;
    dh = 0x00;
    div(cx);
    dx = ax;
    di = bp;
    di += 0x0015;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si);
    di += 0x001e;
    bx = 0x1075;
    sub_15c46();
    di = bp;
    dx = memoryAGet16(ds, si + 2);
    if (dx <= 0x03e7)
        goto loc_15aa2;
    dx = 0x03e7;
loc_15aa2:
    di += 0x0026;
    bx = 0x1079;
    sub_15c46();
    dx = memoryAGet16(ds, si + 4);
    if (dx <= 0x0063)
        goto loc_15ab7;
    dx = 0x0063;
loc_15ab7:
    di += 0x0004;
    bx = 0x107b;
    sub_15c46();
    if (memoryAGet(ds, 0x1a33) == 0x01)
        goto loc_15b06;
    si = bp;
    bp += 0x0003;
    cx = 0x002f;
    memoryASet(ds, 0x1a36, 0x01);
    di = 0x194e;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x00);
    memoryASet(ds, 0x1a36, 0x02);
    di = 0x19b8;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_15afe;
    memoryASet(ds, 0x1a37, 0x01);
    di = 0x1983;
loc_15afe:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si++;
    di++;
    if (--cx)
        goto loc_15afe;
loc_15b06:
    ax = memoryAGet16(ds, 0x1a2b);
    bx = memoryAGet16(ds, 0x1a2d);
    cx = memoryAGet16(ds, 0x1a2f);
    dx = memoryAGet16(ds, 0x1a31);
    si = 0x23a;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_15b24;
    si = 0x243;
loc_15b24:
    dl += memoryAGet(ds, si + 2);
    if (dx < 0x003c)
        goto loc_15b31;
    cl++;
    dx -= 0x003c;
loc_15b31:
    memoryASet16(ds, 0x1a31, dx);
    cl += memoryAGet(ds, si + 1);
    if (cx < 0x003c)
        goto loc_15b42;
    bl++;
    cx -= 0x003c;
loc_15b42:
    memoryASet16(ds, 0x1a2f, cx);
    bl += memoryAGet(ds, si);
loc_15b48:
    if (bx < 0x0018)
        goto loc_15b53;
    bx -= 0x0018;
    ax++;
    goto loc_15b48;
loc_15b53:
    memoryASet16(ds, 0x1a2d, bx);
    if (ax <= 0x0007)
        goto loc_15b63;
    ax -= 0x0007;
    memoryASet16(ds, 0x1a29, memoryAGet16(ds, 0x1a29) + 1);
loc_15b63:
    memoryASet16(ds, 0x1a2b, ax);
}
void sub_15b67()
{
    sub_15cc3();
    push(cx);
    push(dx);
    memoryASet16(ds, 0x1454, 0x0000);
    if (dh >= memoryAGet(ds, 0x1453))
        goto loc_15b88;
    memoryASet(ds, 0x1454, 0x01);
    al = 0x3c;
    al -= memoryAGet(ds, 0x1453);
    dh += al;
    goto loc_15b8c;
loc_15b88:
    dh -= memoryAGet(ds, 0x1453);
loc_15b8c:
    if (cl >= memoryAGet(ds, 0x1452))
        goto loc_15ba2;
    memoryASet(ds, 0x1455, 0x01);
    al = 0x3c;
    al -= memoryAGet(ds, 0x1452);
    cl += al;
    goto loc_15baf;
loc_15ba2:
    cl -= memoryAGet(ds, 0x1452);
    if (memoryAGet(ds, 0x1454) == 0x00)
        goto loc_15baf;
    cl--;
loc_15baf:
    if (ch >= memoryAGet(ds, 0x1451))
        goto loc_15bc9;
    al = 0x18;
    if (memoryAGet(ds, 0x1454) == 0x00)
        goto loc_15bc0;
    al--;
loc_15bc0:
    al -= memoryAGet(ds, 0x1451);
    ch += al;
    goto loc_15bd6;
loc_15bc9:
    ch -= memoryAGet(ds, 0x1451);
    if (memoryAGet(ds, 0x1455) == 0x00)
        goto loc_15bd6;
    ch--;
loc_15bd6:
    memoryASet(ds, 0x1451, ch);
    memoryASet(ds, 0x1452, cl);
    memoryASet(ds, 0x1453, dh);
    ax = memoryAGet16(ds, 0x1a21);
    bx = memoryAGet16(ds, 0x1a23);
    cx = memoryAGet16(ds, 0x1a25);
    dx = memoryAGet16(ds, 0x1a27);
    si = 0x1451;
    dl += memoryAGet(ds, si + 2);
    if (dx < 0x003c)
        goto loc_15c02;
    cl++;
    dx -= 0x003c;
loc_15c02:
    memoryASet16(ds, 0x1a27, dx);
    cl += memoryAGet(ds, si + 1);
    if (cx < 0x003c)
        goto loc_15c13;
    bl++;
    cx -= 0x003c;
loc_15c13:
    memoryASet16(ds, 0x1a25, cx);
    bl += memoryAGet(ds, si);
loc_15c19:
    if (bx < 0x0018)
        goto loc_15c24;
    bx -= 0x0018;
    ax++;
    goto loc_15c19;
loc_15c24:
    memoryASet16(ds, 0x1a23, bx);
    if (ax <= 0x0007)
        goto loc_15c34;
    ax -= 0x0007;
    memoryASet16(ds, 0x1a1f, memoryAGet16(ds, 0x1a1f) + 1);
loc_15c34:
    memoryASet16(ds, 0x1a21, ax);
    dx = pop();
    cx = pop();
    memoryASet(ds, 0x1451, ch);
    memoryASet(ds, 0x1452, cl);
    memoryASet(ds, 0x1453, dh);
}
void sub_15c46()
{
    ah = 0x00;
loc_15c48:
    al = 0x00;
loc_15c4a:
    if ((short)dx < (short)memoryAGet16(ds, bx))
        goto loc_15c54;
    al++;
    dx -= memoryAGet16(ds, bx);
    goto loc_15c4a;
loc_15c54:
    al += 0x30;
    if (al != 0x30)
        goto loc_15c64;
    if (ah != 0x00)
        goto loc_15c66;
    al = 0x20;
    goto loc_15c66;
loc_15c64:
    ah++;
loc_15c66:
    memoryASet(ds, di, al);
    di++;
    bx += 0x0002;
    al = 0x0a;
    if (memoryAGet(ds, bx + 65534) != al)
        goto loc_15c48;
    dl += 0x30;
    memoryASet(ds, di, dl);
}
void sub_15c79()
{
    push(di);
loc_15c7a:
    al = memoryAGet(ds, si);
    si++;
    if (al != 0xff)
        goto loc_15c86;
    memoryASet16(ds, 0x026e, pop());
    return;
loc_15c86:
    if (al != 0x0d)
        goto loc_15c92;
    di = pop();
    di += 0x00a0;
    push(di);
    goto loc_15c7a;
loc_15c92:
    memoryASet16(es, di, ax);
    di += 0x0002;
    goto loc_15c7a;
}
void sub_15c9a()
{
    ah = 0x00;
loc_15c9c:
    if (al < 0x0a)
        goto loc_15ca6;
    al -= 0x0a;
    ah++;
    goto loc_15c9c;
loc_15ca6:
    ax += 0x3030;
    memoryASet(ds, di, ah);
    memoryASet(ds, di + 1, al);
    di += 0x0003;
}
void sub_15cb2()
{
    ah = 0x2a;
    interrupt(0x21);
    cx -= 0x0708;
loc_15cba:
    cx -= 0x0064;
    if (cx >= 0x0064)
        goto loc_15cba;
}
void sub_15cc3()
{
    ah = 0x2c;
    interrupt(0x21);
}
void sub_15cc8()
{
    dx = 0x30c;
    ah = 0x3d;
    al = 0x02;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_15d3c;
    sub_15cb2();
    memoryASet(ds, 0x026d, cl);
    di = 0x1a4e;
    di += 0x015a;
    cx = 0x000a;
loc_15ce6:
    sub_15d2b();
    di += 0x0040;
    if (--cx)
        goto loc_15ce6;
    di += 0x004a;
    sub_15d2b();
    di += 0x0041;
    sub_15d2b();
    di += 0x0041;
    sub_15d2b();
    sub_15cc3();
    dx = cx;
    di = 0x1a4e;
    di += 0x0165;
    cx = 0x000a;
loc_15d10:
    sub_15d31();
    di += 0x0043;
    if (--cx)
        goto loc_15d10;
    di += 0x004a;
    sub_15d31();
    di += 0x0044;
    sub_15d31();
    di += 0x0044;
    sub_15d31();
    return;
    //   gap of 17 bytes
loc_15d3c:
    memoryASet16(ds, 0x0319, ax);
    bx = memoryAGet16(ds, 0x0319);
    cx = 0x08ad;
    dx = 0x170e;
    ah = 0x3f;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x0319);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_15d2b()
{
    al = memoryAGet(ds, 0x026d);
    sub_15c9a();
    al = dh;
    sub_15c9a();
    al = dl;
    sub_15c9a();
}
void sub_15d31()
{
    al = dh;
    sub_15c9a();
    al = dl;
    sub_15c9a();
}
void sub_15d57()
{
    dx = 0x30c;
    ah = 0x3c;
    cl = 0x20;
    interrupt(0x21);
    memoryASet16(ds, 0x0319, ax);
    bx = memoryAGet16(ds, 0x0319);
    cx = 0x08ad;
    dx = 0x170e;
    ah = 0x40;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x0319);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_15d7c()
{
    if (bx == 0xffff)
        goto loc_15d87;
    cx = 0x0001;
    goto loc_15d8d;
loc_15d87:
    bx = 0x0000;
    cx = 0x0004;
loc_15d8d:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, bx + 491, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, bx + 499, ax);
    ax = memoryAGet16(ds, si + 4);
    memoryASet16(ds, bx + 507, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_15d8d;
    bx -= 0x0002;
}
void sub_15daa()
{
    push(es);
    push(ds);
    es = pop();
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_15db2()
{
    bx = memoryAGet16(ds, bx + 1005);
    es = memoryAGet16(ds, 0x024b);
    di = 0x1222;
    bx += 0x0016;
    cx = 0x000b;
loc_15dc3:
    push(cx);
    push(di);
    cx = 0x0013;
loc_15dc8:
    if (memoryAGet(ds, bx) != 0x20)
        goto loc_15de8;
    push(cx);
    si = 0x6da4;
    sub_1610e();
    di -= 0x0780;
    cx = pop();
    goto loc_15de8;
    //   gap of 13 bytes
loc_15de8:
    di += 0x0004;
    bx++;
    if (--cx)
        goto loc_15dc8;
    bx += 0x0002;
    di = pop();
    di += 0x0780;
    cx = pop();
    if (--cx)
        goto loc_15dc3;
}
void sub_15dfa()
{
    bx = 0x0000;
    di = 0x1222;
    bx += 0x0016;
    cx = 0x000b;
loc_15e06:
    push(cx);
    push(di);
    cx = 0x0013;
loc_15e0b:
    si = 0x6da4;
    if (memoryAGet(ds, bx + 124) & 0x08)
        goto loc_15e1f;
    if (!(memoryAGet(ds, bx + 124) & 0x01))
        goto loc_15e28;
    si = 0x6da0;
loc_15e1f:
    push(cx);
    sub_1610e();
    di -= 0x0780;
    cx = pop();
loc_15e28:
    di += 0x0004;
    bx++;
    if (--cx)
        goto loc_15e0b;
    bx += 0x0002;
    di = pop();
    di += 0x0780;
    cx = pop();
    if (--cx)
        goto loc_15e06;
    if (memoryAGet(ds, 0x0034) == 0x00)
        goto loc_15e4b;
    si = memoryAGet16(ds, 0x0012);
    di = memoryAGet16(ds, 0x0037);
    sub_1610e();
loc_15e4b:
    if (memoryAGet(ds, 0x003b) == 0x01)
        goto loc_15e64;
    if (memoryAGet(ds, 0x003c) != 0x01)
        goto loc_15e64;
    si = memoryAGet16(ds, 0x0016);
    di = memoryAGet16(ds, 0x003f);
    sub_1610e();
loc_15e64:
    if (memoryAGet16(ds, 0x03d3) != 0x0000)
        return;
    sub_168f2();
}
void sub_15e6f()
{
    bx = memoryAGet16(ds, bx + 1005);
    memoryASet16(ds, 0x0066, 0x00d1);
    di = 0x92;
    bx += 0x0016;
    cx = 0x000b;
loc_15e83:
    push(cx);
    cx = 0x0013;
loc_15e87:
    al = 0xf9;
    if (memoryAGet(ds, bx) == 0x20)
        goto loc_15e94;
    al &= 0xf6;
    memoryASet16(ds, 0x0066, memoryAGet16(ds, 0x0066) - 1);
loc_15e94:
    if (memoryAGet(ds, bx + 65515) == 0x20)
        goto loc_15e9c;
    al &= 0x7f;
loc_15e9c:
    if (memoryAGet(ds, bx + 21) == 0x20)
        goto loc_15ea4;
    al &= 0xbf;
loc_15ea4:
    if (memoryAGet(ds, bx + 65535) == 0x20)
        goto loc_15eac;
    al &= 0xdf;
loc_15eac:
    if (memoryAGet(ds, bx + 1) == 0x20)
        goto loc_15eb4;
    al &= 0xef;
loc_15eb4:
    memoryASet(ds, di, al);
    bx++;
    di++;
    if (--cx)
        goto loc_15e87;
    bx += 0x0002;
    di += 0x0002;
    cx = pop();
    if (--cx)
        goto loc_15e83;
    di = 0x0073;
    memoryASet(ds, di + 124, memoryAGet(ds, di + 124) | 0x40);
}
void sub_15ecc()
{
    si = memoryAGet16(ds, 0x05aa);
    if (si == 0x05ac)
        goto loc_15eeb;
    ax = memoryAGet16(ds, 0x05a8);
    if (ax != memoryAGet16(ds, si))
        goto loc_15f06;
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
loc_15eeb:
    ax = 0x0000;
    bp = memoryAGet16(ds, 0x0190);
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        goto loc_15f12;
    al = memoryAGet(ds, 0x018f);
    al <<= 1;
    si += ax;
    ax = memoryAGet16(ds, si);
    goto loc_15f12;
loc_15f06:
    si += 0x0002;
    si += ax;
    memoryASet16(ds, 0x05a8, memoryAGet16(ds, 0x05a8) + 0x0002);
    ax = memoryAGet16(ds, si);
loc_15f12:
    sub_15f3a();
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_15f1d;
    return;
loc_15f1d:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
loc_15f23:
    cx = 0x0008;
    if (memoryAGet(ds, 0x0254) == 0x00)
        goto loc_15f30;
    cx = 0x0005;
loc_15f30:
    if (--cx)
        goto loc_15f30;
    cx = bx;
    bx--;
    if (--cx)
        goto loc_15f23;
    cx = pop();
    bx = pop();
}
void sub_15edd()
{
    memoryASet16(ds, 0x05a8, 0x0000);
    si = 0x5ac;
    memoryASet16(ds, 0x05aa, si);
    ax = 0x0000;
    bp = memoryAGet16(ds, 0x0190);
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        goto loc_15f12;
    al = memoryAGet(ds, 0x018f);
    al <<= 1;
    si += ax;
    ax = memoryAGet16(ds, si);
    goto loc_15f12;
    //   gap of 13 bytes
loc_15f12:
    sub_15f3a();
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_15f1d;
    return;
loc_15f1d:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
loc_15f23:
    cx = 0x0008;
    if (memoryAGet(ds, 0x0254) == 0x00)
        goto loc_15f30;
    cx = 0x0005;
loc_15f30:
    if (--cx)
        goto loc_15f30;
    cx = bx;
    bx--;
    if (--cx)
        goto loc_15f23;
    cx = pop();
    bx = pop();
}
void sub_15f15()
{
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_15f1d;
    return;
loc_15f1d:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
loc_15f23:
    cx = 0x0008;
    if (memoryAGet(ds, 0x0254) == 0x00)
        goto loc_15f30;
    cx = 0x0005;
loc_15f30:
    if (--cx)
        goto loc_15f30;
    cx = bx;
    bx--;
    if (--cx)
        goto loc_15f23;
    cx = pop();
    bx = pop();
}
void sub_15f3a()
{
    if (memoryAGet(ds, 0x05a7) == 0x00)
        goto loc_15f5b;
    if (ax == 0x0000)
        goto loc_15f5b;
    push(ax);
    al = 0xb6;
    out(0x43, al);
    ax = pop();
    out(0x42, al);
    al = ah;
    out(0x42, al);
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
    return;
loc_15f5b:
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
}
void sub_15f62()
{
    sub_180e0();
    if (al != 0x00)
        goto loc_15fa0;
    if (ah != 0x48)
        goto loc_15f74;
    memoryASet(ds, 0x018e, 0x18);
    return;
loc_15f74:
    if (ah != 0x50)
        goto loc_15f7f;
    memoryASet(ds, 0x018e, 0x10);
    return;
loc_15f7f:
    if (ah != 0x4b)
        goto loc_15f8a;
    memoryASet(ds, 0x018e, 0x08);
    return;
loc_15f8a:
    if (ah != 0x4d)
        goto loc_15f95;
    memoryASet(ds, 0x018e, 0x00);
    return;
loc_15f95:
    if (ah != 0x3b)
        return;
    memoryASet(ds, 0x0253, memoryAGet(ds, 0x0253) ^ 0x01);
    return;
loc_15fa0:
    if (al != 0x1b)
        return;
    sub_14639();
}
void sub_15fa8()
{
    ax = memoryAGet16(ds, 0x0190);
    bx = 0x0000;
loc_15fae:
    if (ax <= 0x0028)
        goto loc_15fb9;
    ax -= 0x0015;
    bx++;
    goto loc_15fae;
loc_15fb9:
    ax -= 0x0016;
    memoryASet16(ds, 0x1071, ax);
    memoryASet16(ds, 0x1073, bx);
}
void sub_15fc4()
{
    bx = memoryAGet16(ds, 0x0207);
    if (memoryAGet(ds, bx + 414) == 0x07)
        goto loc_15fd0;
    return;
loc_15fd0:
    sub_1826d();
    if (ah > memoryAGet(ds, 0x022a))
        goto loc_1603e;
    memoryASet(ds, 0x106d, 0x00);
    memoryASet(ds, 0x106e, 0x01);
    memoryASet(ds, 0x106f, 0x02);
    memoryASet(ds, 0x1070, 0x03);
    si = 0x0000;
    flags.carry = ah & 1;
    ah >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = ah & 1;
    ah >>= 1;
    si = rcl(si, 0x0001);
    dh = memoryAGet(ds, si + 4205);
    sub_1602f();
    si = 0x0000;
    flags.carry = ah & 1;
    ah >>= 1;
    si = rcl(si, 0x0001);
    if (!(ah & 0x01))
        goto loc_1600c;
    si++;
loc_1600c:
    dl = memoryAGet(ds, si + 4205);
    sub_1602f();
    bh = memoryAGet(ds, 0x106d);
    bl = memoryAGet(ds, 0x106e);
    if (!(ah & 0x02))
        goto loc_1602a;
    memoryASet(ds, 0x026d, bh);
    bh = bl;
    bl = memoryAGet(ds, 0x026d);
loc_1602a:
    ax = dx;
    goto loc_160ac;
    //   gap of 16 bytes
loc_1603e:
    bx <<= 1;
    cx = memoryAGet16(ds, bx + 418);
    dx = 0x0000;
loc_16047:
    if (cx <= 0x0028)
        goto loc_16052;
    cx -= 0x0015;
    dx++;
    goto loc_16047;
loc_16052:
    cx -= 0x0016;
    ax = 0x0103;
    bx = 0x0002;
    si = memoryAGet16(ds, 0x0207);
    if (memoryAGet(ds, si + 104) == 0x47)
        goto loc_1606f;
    memoryASet16(ds, 0x026e, ax);
    ax = bx;
    bx = memoryAGet16(ds, 0x026e);
loc_1606f:
    cx -= memoryAGet16(ds, 0x1071);
    if ((short)cx >= 0)
        goto loc_16081;
    memoryASet(ds, 0x026d, ah);
    ah = bh;
    bh = memoryAGet(ds, 0x026d);
    cx = -cx;
loc_16081:
    dx -= memoryAGet16(ds, 0x1073);
    if ((short)dx >= 0)
        goto loc_16092;
    memoryASet(ds, 0x026d, al);
    al = bl;
    bl = memoryAGet(ds, 0x026d);
    dx = -dx;
loc_16092:
    if (cx > dx)
        goto loc_160a2;
    memoryASet(ds, 0x026d, ah);
    ah = al;
    al = memoryAGet(ds, 0x026d);
    goto loc_160ac;
loc_160a2:
    memoryASet(ds, 0x026d, bh);
    bh = bl;
    bl = memoryAGet(ds, 0x026d);
loc_160ac:
    memoryASet(ds, 0x106d, ah);
    memoryASet(ds, 0x106e, al);
    memoryASet(ds, 0x106f, bh);
    memoryASet(ds, 0x1070, bl);
    bx = memoryAGet16(ds, 0x0207);
    bx <<= 1;
    bp = memoryAGet16(ds, bx + 418);
    bx >>= 1;
    si = 0x0000;
loc_160ca:
    ah = memoryAGet(ds, si + 4205);
    cl = ah;
    al = 0x10;
    al <<= cl;
    al &= memoryAGet(ds, bp + 124);
    if (al == 0)
        goto loc_16101;
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    al = ah;
    al ^= memoryAGet(ds, bx + 406);
    if (al != 0x08)
        goto loc_16109;
    al = memoryAGet(ds, bp + 124);
    dl = 0x00;
    cl = 0x04;
loc_160f4:
    flags.carry = !!(al & 0x80);
    al = rol(al, 0x01);
    if (!flags.carry)
        goto loc_160fa;
    dl++;
loc_160fa:
    if (--cx)
        goto loc_160f4;
    if (dl == 0x01)
        goto loc_16109;
loc_16101:
    si++;
    if (si != 0x0004)
        goto loc_160ca;
    ah = 0xff;
loc_16109:
    memoryASet(ds, bx + 410, ah);
}
void sub_1602f()
{
loc_1602f:
    al = memoryAGet(ds, si + 4206);
    memoryASet(ds, si + 4205, al);
    si++;
    if (si < 0x0004)
        goto loc_1602f;
}
void sub_1610e()
{
    cx = 0x0018;
loc_16111:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16111;
}
void sub_16138()
{
    cx = 0x0018;
loc_1613b:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 4, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_1613b;
}
void sub_1616a()
{
    cx = 0x0030;
loc_1616d:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_1616d;
}
void sub_16184()
{
    cx = 0x0018;
loc_16187:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    al = memoryAGet(es, si + 4);
    memoryASet(es, di + 4, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16187;
}
void sub_161b6()
{
    cx = 0x000c;
loc_161b9:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_161b9;
}
void sub_161d8()
{
    cx = 0x000c;
loc_161db:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_161db;
}
void sub_16202()
{
    sub_164bf();
    sub_16431();
    sub_165e5();
    sub_16919();
    bx = memoryAGet16(ds, 0x03d3);
    callIndirect(cs, memoryAGet16(ds, bx + 1295));
}
void sub_16216()
{
    sub_16703();
    sub_1680d();
    sub_16299();
    sub_16332();
    sub_16365();
    sub_16398();
    sub_163cb();
    sub_163fe();
}
void sub_1622f()
{
    sub_1623a();
    sub_162cc();
    sub_162ff();
}
void sub_1623a()
{
    if (memoryAGet(ds, 0x001b) == 0x00)
        goto loc_16246;
    memoryASet(ds, 0x001b, memoryAGet(ds, 0x001b) - 1);
    return;
loc_16246:
    memoryASet(ds, 0x001b, 0x01);
    si = memoryAGet16(ds, 0x051d);
    si += memoryAGet16(ds, 0x001d);
    di = memoryAGet16(ds, 0x051f);
    cx = 0x000c;
loc_1625a:
    push(cx);
    cx = 0x0008;
loc_1625e:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_1625e;
    si += 0x0048;
    di += 0x0048;
    cx = pop();
    if (--cx)
        goto loc_1625a;
    ax = 0x03c0;
    if (!(memoryAGet(ds, 0x001c) & 0x01))
        goto loc_1627e;
    ax = 0xfc48;
loc_1627e:
    memoryASet16(ds, 0x001d, memoryAGet16(ds, 0x001d) + ax);
    if (memoryAGet(ds, 0x001c) != 0x0a)
        goto loc_16294;
    memoryASet(ds, 0x001c, 0xff);
    memoryASet16(ds, 0x001d, 0x0000);
loc_16294:
    memoryASet(ds, 0x001c, memoryAGet(ds, 0x001c) + 1);
}
void sub_16299()
{
    if (memoryAGet(ds, 0x0018) == 0x00)
        goto loc_162a5;
    memoryASet(ds, 0x0018, memoryAGet(ds, 0x0018) - 1);
    return;
loc_162a5:
    memoryASet(ds, 0x0018, 0x01);
    si = memoryAGet16(ds, 0x0519);
    si += memoryAGet16(ds, 0x0019);
    di = memoryAGet16(ds, 0x051b);
    sub_1610e();
    memoryASet16(ds, 0x0019, memoryAGet16(ds, 0x0019) + 0x0004);
    if (memoryAGet16(ds, 0x0019) != 0x0014)
        return;
    memoryASet16(ds, 0x0019, 0x0000);
}
void sub_162cc()
{
    if (memoryAGet(ds, 0x001f) == 0x00)
        goto loc_162d8;
    memoryASet(ds, 0x001f, memoryAGet(ds, 0x001f) - 1);
    return;
loc_162d8:
    memoryASet(ds, 0x001f, 0x01);
    si = memoryAGet16(ds, 0x0521);
    si += memoryAGet16(ds, 0x0020);
    di = memoryAGet16(ds, 0x0523);
    sub_1610e();
    memoryASet16(ds, 0x0020, memoryAGet16(ds, 0x0020) + 0x0004);
    if (memoryAGet16(ds, 0x0020) != 0x0050)
        return;
    memoryASet16(ds, 0x0020, 0x0000);
}
void sub_162ff()
{
    if (memoryAGet(ds, 0x0022) == 0x00)
        goto loc_1630b;
    memoryASet(ds, 0x0022, memoryAGet(ds, 0x0022) - 1);
    return;
loc_1630b:
    memoryASet(ds, 0x0022, 0x05);
    si = memoryAGet16(ds, 0x0525);
    si += memoryAGet16(ds, 0x0023);
    di = memoryAGet16(ds, 0x0527);
    sub_1610e();
    memoryASet16(ds, 0x0023, memoryAGet16(ds, 0x0023) + 0x0004);
    if (memoryAGet16(ds, 0x0023) != 0x0018)
        return;
    memoryASet16(ds, 0x0023, 0x0000);
}
void sub_16332()
{
    if (memoryAGet(ds, 0x0025) == 0x00)
        goto loc_1633e;
    memoryASet(ds, 0x0025, memoryAGet(ds, 0x0025) - 1);
    return;
loc_1633e:
    memoryASet(ds, 0x0025, 0x01);
    si = memoryAGet16(ds, 0x0529);
    si += memoryAGet16(ds, 0x0026);
    di = memoryAGet16(ds, 0x052b);
    sub_1610e();
    memoryASet16(ds, 0x0026, memoryAGet16(ds, 0x0026) + 0x0004);
    if (memoryAGet16(ds, 0x0026) != 0x0010)
        return;
    memoryASet16(ds, 0x0026, 0x0000);
}
void sub_16365()
{
    if (memoryAGet(ds, 0x0028) == 0x00)
        goto loc_16371;
    memoryASet(ds, 0x0028, memoryAGet(ds, 0x0028) - 1);
    return;
loc_16371:
    memoryASet(ds, 0x0028, 0x01);
    si = memoryAGet16(ds, 0x052d);
    si += memoryAGet16(ds, 0x0029);
    di = memoryAGet16(ds, 0x052f);
    sub_1616a();
    memoryASet16(ds, 0x0029, memoryAGet16(ds, 0x0029) + 0x0002);
    if (memoryAGet16(ds, 0x0029) != 0x000c)
        return;
    memoryASet16(ds, 0x0029, 0x0000);
}
void sub_16398()
{
    if (memoryAGet(ds, 0x002b) == 0x00)
        goto loc_163a4;
    memoryASet(ds, 0x002b, memoryAGet(ds, 0x002b) - 1);
    return;
loc_163a4:
    memoryASet(ds, 0x002b, 0x01);
    si = memoryAGet16(ds, 0x0531);
    si += memoryAGet16(ds, 0x002c);
    di = memoryAGet16(ds, 0x0533);
    sub_16184();
    memoryASet16(ds, 0x002c, memoryAGet16(ds, 0x002c) + 0x0005);
    if (memoryAGet16(ds, 0x002c) != 0x0019)
        return;
    memoryASet16(ds, 0x002c, 0x0000);
}
void sub_163cb()
{
    if (memoryAGet(ds, 0x002e) == 0x00)
        goto loc_163d7;
    memoryASet(ds, 0x002e, memoryAGet(ds, 0x002e) - 1);
    return;
loc_163d7:
    memoryASet(ds, 0x002e, 0x01);
    si = memoryAGet16(ds, 0x0535);
    si += memoryAGet16(ds, 0x002f);
    di = memoryAGet16(ds, 0x0537);
    sub_161b6();
    memoryASet16(ds, 0x002f, memoryAGet16(ds, 0x002f) + 0x0003);
    if (memoryAGet16(ds, 0x002f) != 0x000c)
        return;
    memoryASet16(ds, 0x002f, 0x0000);
}
void sub_163fe()
{
    if (memoryAGet(ds, 0x0031) == 0x00)
        goto loc_1640a;
    memoryASet(ds, 0x0031, memoryAGet(ds, 0x0031) - 1);
    return;
loc_1640a:
    memoryASet(ds, 0x0031, 0x01);
    si = memoryAGet16(ds, 0x0539);
    si += memoryAGet16(ds, 0x0032);
    di = memoryAGet16(ds, 0x053b);
    sub_161d8();
    memoryASet16(ds, 0x0032, memoryAGet16(ds, 0x0032) + 0x0004);
    if (memoryAGet16(ds, 0x0032) != 0x000c)
        return;
    memoryASet16(ds, 0x0032, 0x0000);
}
void sub_16431()
{
    memoryASet16(ds, 0x004e, 0x0044);
    bx = 0x0000;
loc_1643a:
    if (memoryAGet16(ds, bx + 442) == 0x0000)
        goto loc_16478;
    if (memoryAGet16(ds, bx + 442) < 0x0008)
        goto loc_1646b;
    if (memoryAGet16(ds, bx + 442) > 0x002e)
        goto loc_16478;
    if (!(memoryAGet16(ds, bx + 442) & 0x0001))
        return;
    if (memoryAGet16(ds, bx + 442) & 0x0001)
        goto loc_16462;
    memoryASet16(ds, 0x004e, 0x004e);
    goto loc_16478;
loc_16462:
    memoryASet16(ds, 0x004e, 0x0055);
    goto loc_16478;
loc_1646b:
    if (memoryAGet16(ds, 0x004e) == 0x0055)
        goto loc_16478;
    memoryASet16(ds, 0x004e, 0x0044);
loc_16478:
    bx += 0x0002;
    if (bx != 0x0008)
        goto loc_1643a;
    if (memoryAGet16(ds, 0x004e) != 0x0055)
        goto loc_164a3;
    if (memoryAGet16(ds, 0x004c) == 0x0020)
        return;
    memoryASet16(ds, 0x004c, memoryAGet16(ds, 0x004c) + 0x0004);
    si = memoryAGet16(ds, 0x0048);
    si += memoryAGet16(ds, 0x004c);
    di = memoryAGet16(ds, 0x004a);
    sub_1610e();
    return;
loc_164a3:
    if (memoryAGet16(ds, 0x004c) == 0xfffc)
        return;
    si = memoryAGet16(ds, 0x0048);
    si += memoryAGet16(ds, 0x004c);
    di = memoryAGet16(ds, 0x004a);
    sub_1610e();
    memoryASet16(ds, 0x004c, memoryAGet16(ds, 0x004c) - 0x0004);
}
void sub_164bf()
{
    if (memoryAGet(ds, 0x0034) != 0x00)
        goto loc_164c9;
    goto loc_16577;
loc_164c9:
    tx = memoryAGet16(ds, 0x0035);
    memoryASet16(ds, 0x0035, memoryAGet16(ds, 0x0035) - 1);
    if (tx == 1)
        goto loc_16541;
    bp = memoryAGet16(ds, 0x0190);
    if (bp != memoryAGet16(ds, 0x0010))
        goto loc_16540;
    if (memoryAGet(ds, 0x0034) != 0x01)
        goto loc_16540;
    memoryASet(ds, 0x0034, 0x02);
    memoryASet16(ds, 0x0035, 0x0032);
    sub_1826d();
    al = ah;
    ax &= 0x0006;
    si = ax;
    ax = memoryAGet16(ds, si + 1389);
    bx = memoryAGet16(ds, si + 1397);
    si = memoryAGet16(ds, 0x0039);
    ax += memoryAGet16(ds, si + 1357);
    bx += memoryAGet16(ds, si + 1373);
    memoryASet16(ds, 0x0012, ax);
    memoryASet16(ds, 0x0211, memoryAGet16(ds, 0x0211) + bx);
    sub_176fc();
    si = memoryAGet16(ds, 0x0012);
    memoryASet16(ds, 0x0205, si);
    di = memoryAGet16(ds, 0x0037);
    sub_1610e();
    memoryASet16(ds, 0x05a8, 0x0000);
    ax = 0x5d0;
    memoryASet16(ds, 0x05aa, ax);
    di = 0x238;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_1653e;
    di = 0x241;
loc_1653e:
    memoryASet16(ds, di, memoryAGet16(ds, di) + 1);
loc_16540:
    return;
loc_16541:
    memoryASet(ds, 0x0034, 0x00);
    sub_1826d();
    al = ah;
    ax &= 0x007f;
    ax += 0x0150;
    memoryASet16(ds, 0x0035, ax);
    si = 0x6da0;
    bx = memoryAGet16(ds, 0x0010);
    memoryASet(ds, bx + 124, memoryAGet(ds, bx + 124) & 0xfb);
    if (!(memoryAGet(ds, bx + 124) & 0x08))
        goto loc_1656a;
    si = 0x6da4;
loc_1656a:
    di = memoryAGet16(ds, 0x0037);
    sub_1610e();
    memoryASet16(ds, 0x0010, 0x0000);
loc_16577:
    tx = memoryAGet16(ds, 0x0035);
    memoryASet16(ds, 0x0035, memoryAGet16(ds, 0x0035) - 1);
    if (tx == 1)
        goto loc_1657e;
    return;
loc_1657e:
    memoryASet(ds, 0x0034, 0x01);
    sub_1826d();
    al = ah;
    ax &= 0x003f;
    ax += 0x00a8;
    memoryASet16(ds, 0x0035, ax);
    sub_1826d();
    al = ah;
    ax &= 0x000e;
    memoryASet16(ds, 0x0039, ax);
    si = ax;
    ax = memoryAGet16(ds, si + 1341);
    si = memoryAGet16(ds, 0x03d5);
    si--;
    si <<= 1;
    ax += memoryAGet16(ds, si + 1389);
    memoryASet16(ds, 0x0012, ax);
loc_165b0:
    sub_1826d();
    bl = ah;
    bh = 0x00;
    bx += 0x000b;
    if (!(memoryAGet(ds, bx + 124) & 0x01))
        goto loc_165b0;
    if (!(memoryAGet(ds, bx + 124) & 0x02))
        goto loc_165ca;
    goto loc_165b0;
loc_165ca:
    memoryASet16(ds, 0x0010, bx);
    memoryASet(ds, bx + 124, memoryAGet(ds, bx + 124) | 0x04);
    bx <<= 1;
    si = memoryAGet16(ds, 0x0012);
    di = memoryAGet16(ds, bx + 1617);
    memoryASet16(ds, 0x0037, di);
    sub_1610e();
}
void sub_165e5()
{
    bx = 0x0000;
loc_165e8:
    if (memoryAGet16(ds, bx + 108) == 0x0000)
        goto loc_1661b;
    memoryASet16(ds, bx + 108, memoryAGet16(ds, bx + 108) - 1);
    if (memoryAGet16(ds, bx + 108) != 0x0032)
        goto loc_16604;
    si = 0x105f;
    sub_15d7c();
    goto loc_1661b;
loc_16604:
    if (memoryAGet16(ds, bx + 108) != 0x0000)
        goto loc_1661b;
    bx >>= 1;
    memoryASet(ds, bx + 104, 0x47);
    bx <<= 1;
    si = 0x1053;
    sub_15d7c();
loc_1661b:
    if (memoryAGet16(ds, bx + 116) == 0x0000)
        goto loc_1665c;
    memoryASet16(ds, bx + 116, memoryAGet16(ds, bx + 116) - 1);
    if (memoryAGet16(ds, bx + 116) != 0x0000)
        goto loc_1665c;
    bx <<= 1;
    di = memoryAGet16(ds, bx);
    memoryASet16(ds, bx, 0x0000);
    memoryASet16(ds, bx + 2, 0x0000);
    bx >>= 1;
    si = 0x6da0;
    memoryASet(ds, di + 124, memoryAGet(ds, di + 124) & 0xfb);
    if (!(memoryAGet(ds, di + 124) & 0x08))
        goto loc_16653;
    si = 0x6da4;
loc_16653:
    di <<= 1;
    di = memoryAGet16(ds, di + 1617);
    sub_1610e();
loc_1665c:
    bx += 0x0002;
    if (bx != 0x0008)
        goto loc_165e8;
    bx = 0x0000;
loc_16667:
    if (memoryAGet16(ds, bx + 80) != 0x00ff)
        goto loc_16672;
    goto loc_166f7;
loc_16672:
    bp = memoryAGet16(ds, bx + 450);
    if (bp != memoryAGet16(ds, 0x0190))
        goto loc_166d8;
    memoryASet(ds, bp + 124, memoryAGet(ds, bp + 124) & 0xfd);
    memoryASet16(ds, 0x05a8, 0x0000);
    ax = 0x5bc;
    memoryASet16(ds, 0x05aa, ax);
    memoryASet16(ds, bx + 80, 0x00ff);
    memoryASet16(ds, 0x0058, 0x0000);
    bp = 0x0000;
loc_1669e:
    memoryASet(ds, bp + 104, 0x4d);
    sub_1826d();
    al = ah;
    ax &= 0x007f;
    ax += 0x00eb;
    bp <<= 1;
    memoryASet16(ds, bp + 108, ax);
    bp >>= 1;
    bp++;
    if (bp != 0x0004)
        goto loc_1669e;
    si = 0x6da4;
    di = memoryAGet16(ds, bx + 458);
    sub_1610e();
    si = 0x1059;
    bx = 0xffff;
    sub_15d7c();
    si = 0x6da4;
    goto loc_166f7;
loc_166d8:
    memoryASet(ds, bp + 124, memoryAGet(ds, bp + 124) | 0x02);
    memoryASet16(ds, bx + 80, memoryAGet16(ds, bx + 80) + 0x0004);
    memoryASet16(ds, bx + 80, memoryAGet16(ds, bx + 80) & 0x003f);
    si = memoryAGet16(ds, 0x057d);
    si += memoryAGet16(ds, bx + 80);
    di = memoryAGet16(ds, bx + 458);
    sub_1610e();
loc_166f7:
    bx += 0x0002;
    if (bx == 0x0008)
        return;
    goto loc_16667;
}
void sub_16703()
{
    if (memoryAGet(ds, 0x003b) != 0x01)
        goto loc_1670b;
    return;
loc_1670b:
    if (memoryAGet(ds, 0x003c) != 0x00)
        goto loc_16715;
    goto loc_16775;
loc_16715:
    tx = memoryAGet16(ds, 0x003d);
    memoryASet16(ds, 0x003d, memoryAGet16(ds, 0x003d) - 1);
    if (tx == 1)
        goto loc_1673e;
    bp = memoryAGet16(ds, 0x0190);
    if (bp != memoryAGet16(ds, 0x0014))
        goto loc_1673d;
    memoryASet(ds, 0x003b, 0x01);
    sub_167c7();
    memoryASet16(ds, 0x05a8, 0x0000);
    ax = 0x5d0;
    memoryASet16(ds, 0x05aa, ax);
    goto loc_16751;
loc_1673d:
    return;
loc_1673e:
    memoryASet(ds, 0x003c, 0x00);
    sub_1826d();
    al = ah;
    ax &= 0x001f;
    ax += 0x001e;
    memoryASet16(ds, 0x003d, ax);
loc_16751:
    si = 0x6da0;
    bx = memoryAGet16(ds, 0x0014);
    memoryASet(ds, bx + 124, memoryAGet(ds, bx + 124) & 0xfb);
    if (!(memoryAGet(ds, bx + 124) & 0x08))
        goto loc_16767;
    si = 0x6da4;
loc_16767:
    di = memoryAGet16(ds, 0x003f);
    sub_1610e();
    memoryASet16(ds, 0x0014, 0x0000);
    return;
loc_16775:
    tx = memoryAGet16(ds, 0x003d);
    memoryASet16(ds, 0x003d, memoryAGet16(ds, 0x003d) - 1);
    if (tx == 1)
        goto loc_1677c;
    return;
loc_1677c:
    memoryASet(ds, 0x003c, 0x01);
    sub_1826d();
    al = ah;
    ax &= 0x003f;
    ax += 0x00a8;
    memoryASet16(ds, 0x003d, ax);
loc_1678f:
    sub_1826d();
    bl = ah;
    bh = 0x00;
    bx += 0x000b;
    if (!(memoryAGet(ds, bx + 124) & 0x01))
        goto loc_1678f;
    if (!(memoryAGet(ds, bx + 124) & 0x02))
        goto loc_167a9;
    goto loc_1678f;
loc_167a9:
    memoryASet16(ds, 0x0014, bx);
    memoryASet(ds, bx + 124, memoryAGet(ds, bx + 124) | 0x04);
    bx <<= 1;
    si = 0xa996;
    memoryASet16(ds, 0x0016, si);
    di = memoryAGet16(ds, bx + 1617);
    memoryASet16(ds, 0x003f, di);
    sub_1610e();
}
void sub_167c7()
{
    if (memoryAGet16(ds, 0x03d3) == 0x0000)
        goto loc_167cf;
    return;
loc_167cf:
    di = 0x004e;
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_167e3;
    if (memoryAGet(ds, 0x0217) == 0x02)
        goto loc_167e3;
    di = 0x0012;
loc_167e3:
    cx = 0x0007;
    si = 0xd660;
    si += 0x003f;
    if (memoryAGet(ds, 0x003b) != 0x01)
        goto loc_167f6;
    si = 0xd695;
loc_167f6:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_167f6;
}
void sub_1680d()
{
    if (memoryAGet(ds, 0x003b) == 0x01)
        goto loc_16815;
    return;
loc_16815:
    if (memoryAGet(ds, 0x0043) == 0x4f)
        goto loc_1687d;
    if (memoryAGet(ds, 0x0043) != 0x43)
        goto loc_16826;
    goto loc_168b5;
loc_16826:
    ax = memoryAGet16(ds, 0x0190);
    cx = 0x0005;
    if (memoryAGet(ds, 0x0042) == 0x4f)
        goto loc_16841;
    si = 0x593;
loc_16837:
    if (ax == memoryAGet16(ds, si))
        goto loc_1687d;
    si += 0x0002;
    if (--cx)
        goto loc_16837;
    return;
loc_16841:
    bx = 0x0000;
    if (memoryAGet(ds, 0x0041) == 0x01)
        goto loc_16859;
    si = 0x59d;
loc_1684f:
    if (ax == memoryAGet16(ds, si))
        goto loc_16859;
    si += 0x0002;
    if (--cx)
        goto loc_1684f;
    return;
loc_16859:
    ax = memoryAGet16(ds, bx + 418);
    if (ax == 0x0036)
        goto loc_16877;
    if (ax == 0x004b)
        goto loc_16877;
    if (ax == 0x0060)
        goto loc_16877;
    bx += 0x0002;
    if (bx != 0x0008)
        goto loc_16859;
    goto loc_168b5;
loc_16877:
    memoryASet(ds, 0x0041, 0x01);
    return;
loc_1687d:
    tx = memoryAGet16(ds, 0x0046);
    memoryASet16(ds, 0x0046, memoryAGet16(ds, 0x0046) - 1);
    if (tx != 1)
        return;
    memoryASet16(ds, 0x0046, 0x0002);
    memoryASet(ds, 0x0043, 0x4f);
    memoryASet16(ds, 0x0044, memoryAGet16(ds, 0x0044) + 0x0006);
    sub_168f2();
    if (memoryAGet16(ds, 0x0044) != 0x0030)
        return;
    bx = 0x004b;
    memoryASet(ds, bx + 145, memoryAGet(ds, bx + 145) | 0x80);
    memoryASet(ds, bx + 103, memoryAGet(ds, bx + 103) | 0x40);
    memoryASet(ds, 0x0042, 0x4f);
    memoryASet(ds, 0x0043, 0x4e);
    return;
loc_168b5:
    tx = memoryAGet16(ds, 0x0046);
    memoryASet16(ds, 0x0046, memoryAGet16(ds, 0x0046) - 1);
    if (tx != 1)
        return;
    memoryASet16(ds, 0x0046, 0x0002);
    memoryASet(ds, 0x0043, 0x43);
    memoryASet(ds, 0x0041, 0x00);
    memoryASet16(ds, 0x0044, memoryAGet16(ds, 0x0044) - 0x0006);
    sub_168f2();
    bx = 0x004b;
    memoryASet(ds, bx + 145, memoryAGet(ds, bx + 145) & 0x7f);
    memoryASet(ds, bx + 103, memoryAGet(ds, bx + 103) & 0xbf);
    if (memoryAGet16(ds, 0x0044) != 0x0000)
        return;
    memoryASet(ds, 0x0042, 0x43);
    memoryASet(ds, 0x0043, 0x4e);
}
void sub_168f2()
{
    si = memoryAGet16(ds, 0x058f);
    si += memoryAGet16(ds, 0x0044);
    di = memoryAGet16(ds, 0x0591);
    cx = 0x0018;
loc_16901:
    push(cx);
    cx = 0x0006;
loc_16905:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_16905;
    si += 0x004a;
    di += 0x004a;
    cx = pop();
    if (--cx)
        goto loc_16901;
}
void sub_16919()
{
    if (memoryAGet16(ds, 0x0066) != 0x0000)
        return;
    if (memoryAGet(ds, 0x0062) == 0x01)
        return;
    if (memoryAGet(ds, 0x005b) == 0x00)
        goto loc_1694d;
    di = memoryAGet16(ds, 0x005c);
    if (memoryAGet(ds, 0x005a) > 0x0a)
        goto loc_1693f;
    di += 0x0002;
    di &= 0x0002;
loc_1693f:
    di += 0x0004;
    di = memoryAGet16(ds, di + 474);
    memoryASet16(ds, 0x0194, di);
    goto loc_1695d;
loc_1694d:
    if (memoryAGet(ds, 0x018f) & 0x01)
        goto loc_1695d;
    al = memoryAGet(ds, 0x018d);
    memoryASet(ds, 0x018e, al);
    sub_16a4d();
loc_1695d:
    sub_15edd();
    si = 0xb860;
    cx = 0x0010;
loc_16966:
    push(cx);
    push(si);
    di = memoryAGet16(ds, 0x0194);
    sub_1610e();
    if (memoryAGet(ds, 0x0042) == 0x43)
        goto loc_1697e;
    memoryASet(ds, 0x0043, 0x43);
    sub_1680d();
loc_1697e:
    si = pop();
    si += 0x0004;
    memoryASet16(ds, 0x111e, 0x0064);
    sub_1778e();
    cx = pop();
    if (--cx)
        goto loc_16966;
    memoryASet16(ds, 0x111e, 0x05dc);
    sub_1778e();
}
void sub_16998()
{
    if (memoryAGet(ds, 0x005a) != 0x00)
        goto loc_16a02;
    memoryASet(ds, 0x005b, 0x00);
    di = memoryAGet16(ds, 0x0194);
    if (bp != memoryAGet16(ds, 0x01d2))
        goto loc_169d1;
    cl = memoryAGet(ds, 0x01e2);
    if (cl == memoryAGet(ds, 0x018d))
        goto loc_169c2;
    if (cl != memoryAGet(ds, 0x018e))
        return;
    memoryASet(ds, 0x018d, cl);
loc_169c2:
    memoryASet16(ds, 0x005c, 0x0000);
    al = memoryAGet(ds, 0x01e7);
    memoryASet(ds, 0x01e6, al);
    goto loc_169f7;
loc_169d1:
    if (bp != memoryAGet16(ds, 0x01d4))
        return;
    cl = memoryAGet(ds, 0x01e3);
    if (cl == memoryAGet(ds, 0x018d))
        goto loc_169eb;
    if (cl != memoryAGet(ds, 0x018e))
        return;
    memoryASet(ds, 0x018d, cl);
loc_169eb:
    memoryASet16(ds, 0x005c, 0x0002);
    al = memoryAGet(ds, 0x01e8);
    memoryASet(ds, 0x01e6, al);
loc_169f7:
    memoryASet(ds, 0x005a, 0x1b);
    memoryASet(ds, 0x005b, 0x01);
    return;
loc_16a02:
    memoryASet(ds, 0x005a, memoryAGet(ds, 0x005a) - 1);
}
void sub_16a07()
{
    cl = memoryAGet(ds, 0x01e5);
    memoryASet(ds, 0x018e, cl);
    memoryASet(ds, 0x018d, cl);
    bp = memoryAGet16(ds, 0x01dc);
    memoryASet16(ds, 0x0194, bp);
    bp = memoryAGet16(ds, 0x01d8);
    memoryASet16(ds, 0x0190, bp);
    al = memoryAGet(ds, 0x01e8);
    memoryASet(ds, 0x01e6, al);
}
void sub_16a2a()
{
    cl = memoryAGet(ds, 0x01e4);
    memoryASet(ds, 0x018e, cl);
    memoryASet(ds, 0x018d, cl);
    bp = memoryAGet16(ds, 0x01da);
    memoryASet16(ds, 0x0194, bp);
    bp = memoryAGet16(ds, 0x01d6);
    memoryASet16(ds, 0x0190, bp);
    al = memoryAGet(ds, 0x01e7);
    memoryASet(ds, 0x01e6, al);
}
void sub_16a4d()
{
    if (memoryAGet(ds, 0x018e) != 0xff)
        goto loc_16a57;
    goto loc_16c87;
loc_16a57:
    sub_16ca8();
    bp = memoryAGet16(ds, 0x0190);
    bl = memoryAGet(ds, 0x018f);
    bl++;
    bl &= 0x07;
    memoryASet(ds, 0x018f, bl);
    if (bl != 0x00)
        goto loc_16a73;
    goto loc_16b04;
loc_16a73:
    memoryASet(ds, 0x0233, 0x00);
    dh = memoryAGet(ds, 0x018d);
    dl = memoryAGet(ds, 0x018e);
    if (dh == dl)
        goto loc_16a8b;
    dl ^= dh;
    if (!(dl & 0x10))
        goto loc_16aa6;
loc_16a8b:
    if (dh != 0x00)
        goto loc_16a93;
    goto loc_16c1a;
loc_16a93:
    if (dh != 0x08)
        goto loc_16a9b;
    goto loc_16c53;
loc_16a9b:
    if (dh != 0x10)
        goto loc_16aa3;
    goto loc_16bf6;
loc_16aa3:
    goto loc_16bca;
loc_16aa6:
    if (memoryAGet(ds, 0x005b) == 0x00)
        goto loc_16ae6;
    memoryASet(ds, 0x005a, -memoryAGet(ds, 0x005a));
    memoryASet(ds, 0x005a, memoryAGet(ds, 0x005a) + 0x1a);
    dh = memoryAGet(ds, 0x018e);
    memoryASet(ds, 0x018d, dh);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) ^ 0xff);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) + 1);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) & 0x07);
    ax = memoryAGet16(ds, 0x0190);
    bx = memoryAGet16(ds, 0x0192);
    memoryASet16(ds, 0x0190, bx);
    memoryASet16(ds, 0x0192, ax);
    memoryASet16(ds, 0x005c, memoryAGet16(ds, 0x005c) + 0x0002);
    memoryASet16(ds, 0x005c, memoryAGet16(ds, 0x005c) & 0x0002);
    goto loc_16a8b;
loc_16ae6:
    dh = memoryAGet(ds, 0x018e);
    memoryASet(ds, 0x018d, dh);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) ^ 0xff);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) + 1);
    memoryASet(ds, 0x018f, memoryAGet(ds, 0x018f) & 0x07);
    if (bl >= 0x06)
        goto loc_16b04;
    goto loc_16b8d;
loc_16b04:
    if (memoryAGet(ds, 0x0233) == 0x01)
        goto loc_16b21;
    memoryASet(ds, 0x0233, 0x01);
    si = 0x234;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_16b1f;
    si = 0x23d;
loc_16b1f:
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_16b21:
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        goto loc_16b42;
    memoryASet16(ds, 0x0211, memoryAGet16(ds, 0x0211) + 1);
    sub_176fc();
    memoryASet16(ds, 0x0066, memoryAGet16(ds, 0x0066) - 1);
    memoryASet(ds, bp + 124, memoryAGet(ds, bp + 124) & 0xf7);
    if (bl == 0x00)
        goto loc_16b42;
    goto loc_16b8d;
loc_16b42:
    sub_16998();
    dh = memoryAGet(ds, 0x018d);
    if (memoryAGet(ds, 0x005a) != 0x00)
        goto loc_16b8d;
    cl = memoryAGet(ds, 0x018e);
    dh = cl;
    cl = ror(cl, 0x01);
    cl = ror(cl, 0x01);
    cl = ror(cl, 0x01);
    al = 0x10;
    al = rol(al, cl);
    if (!(memoryAGet(ds, bp + 124) & al))
        goto loc_16b6e;
    memoryASet(ds, 0x018d, dh);
    goto loc_16b8d;
loc_16b6e:
    cl = memoryAGet(ds, 0x018d);
    dh = cl;
    cl = ror(cl, 0x01);
    cl = ror(cl, 0x01);
    cl = ror(cl, 0x01);
    al = 0x10;
    al = rol(al, cl);
    if (memoryAGet(ds, bp + 124) & al)
        goto loc_16b8d;
    memoryASet(ds, 0x018f, 0x07);
    goto loc_16c87;
loc_16b8d:
    memoryASet16(ds, 0x0192, bp);
    if (dh != 0x00)
        goto loc_16ba0;
    memoryASet16(ds, 0x0190, memoryAGet16(ds, 0x0190) + 1);
    sub_16ca8();
    goto loc_16c1a;
loc_16ba0:
    if (dh != 0x08)
        goto loc_16baf;
    memoryASet16(ds, 0x0190, memoryAGet16(ds, 0x0190) - 1);
    sub_16ca8();
    goto loc_16c53;
loc_16baf:
    if (dh != 0x10)
        goto loc_16bbf;
    memoryASet16(ds, 0x0190, memoryAGet16(ds, 0x0190) + 0x0015);
    sub_16ca8();
    goto loc_16bf6;
loc_16bbf:
    memoryASet16(ds, 0x0190, memoryAGet16(ds, 0x0190) - 0x0015);
    sub_16ca8();
    goto loc_16bca;
loc_16bca:
    di = memoryAGet16(ds, 0x0194);
    if (memoryAGet(ds, 0x005a) > 0x0a)
        goto loc_16be3;
    if (memoryAGet(ds, 0x005b) != 0x01)
        goto loc_16be3;
    di -= 0x00f0;
    goto loc_16bee;
loc_16be3:
    di += 0x0690;
    sub_16f07();
    di -= 0x0870;
loc_16bee:
    memoryASet16(ds, 0x0194, di);
    sub_16ccd();
    return;
loc_16bf6:
    di = memoryAGet16(ds, 0x0194);
    if (memoryAGet(ds, 0x005a) > 0x08)
        goto loc_16c0f;
    if (memoryAGet(ds, 0x005b) != 0x01)
        goto loc_16c0f;
    di += 0x00f0;
    goto loc_16c12;
loc_16c0f:
    sub_16f47();
loc_16c12:
    memoryASet16(ds, 0x0194, di);
    sub_16ccd();
    return;
loc_16c1a:
    di = memoryAGet16(ds, 0x0194);
    if (memoryAGet(ds, 0x005a) > 0x08)
        goto loc_16c2c;
    if (memoryAGet(ds, 0x005b) == 0x01)
        goto loc_16c3f;
loc_16c2c:
    if (!(memoryAGet(ds, 0x018f) & 0x01))
        goto loc_16c4f;
    sub_16f87();
    di++;
    memoryASet16(ds, 0x0194, di);
    sub_16ccd();
    return;
loc_16c3f:
    if (!(memoryAGet(ds, 0x018f) & 0x01))
        goto loc_16c4f;
    di++;
    memoryASet16(ds, 0x0194, di);
    sub_16ccd();
    return;
loc_16c4f:
    sub_16e1b();
    return;
loc_16c53:
    di = memoryAGet16(ds, 0x0194);
    if (memoryAGet(ds, 0x005a) > 0x08)
        goto loc_16c65;
    if (memoryAGet(ds, 0x005b) == 0x01)
        goto loc_16c73;
loc_16c65:
    if (!(memoryAGet(ds, 0x018f) & 0x01))
        goto loc_16c7e;
    sub_16fab();
    sub_16ccd();
    return;
loc_16c73:
    if (!(memoryAGet(ds, 0x018f) & 0x01))
        goto loc_16c7e;
    sub_16ccd();
    return;
loc_16c7e:
    di--;
    memoryASet16(ds, 0x0194, di);
    sub_16e1b();
    return;
loc_16c87:
    si = memoryAGet16(ds, 0x01e9);
    di = memoryAGet16(ds, 0x0194);
    cx = 0x0018;
    if (memoryAGet(ds, 0x018f) & 0x01)
        goto loc_16ca4;
    if (memoryAGet(ds, 0x018d) & 0x10)
        goto loc_16ca4;
    sub_16e59();
    return;
loc_16ca4:
    sub_16d16();
}
void sub_16ca8()
{
    memoryASet16(ds, 0x0205, 0x6da0);
    bp = memoryAGet16(ds, 0x0192);
    if (!(memoryAGet(ds, bp + 124) & 0x04))
        goto loc_16cbe;
    sub_17192();
    return;
loc_16cbe:
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        return;
    memoryASet16(ds, 0x0205, 0x6da4);
}
void sub_16ccd()
{
    bh = 0x00;
    bl = memoryAGet(ds, 0x018d);
    bp = memoryAGet16(ds, 0x0190);
    if (memoryAGet(ds, bp + 124) & 0x08)
        goto loc_16cea;
    bx >>= 1;
    bx >>= 1;
    si = memoryAGet16(ds, bx + 4197);
    goto loc_16d08;
loc_16cea:
    si = 0x6d60;
    if (memoryAGet(ds, 0x018f) & 0x01)
        goto loc_16cf7;
    si = 0x74c0;
loc_16cf7:
    bx += bx;
    dh = 0x00;
    dl = memoryAGet(ds, 0x018f);
    dl &= 0xfe;
    bx += dx;
    bx += dx;
    si += bx;
loc_16d08:
    memoryASet16(ds, 0x01e9, si);
    if (memoryAGet(ds, 0x005a) != 0x00)
        goto loc_16d3d;
    cx = 0x0018;
loc_16d16:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16d16;
    return;
loc_16d3d:
    memoryASet(ds, 0x005a, memoryAGet(ds, 0x005a) - 1);
    if (memoryAGet(ds, 0x018f) != 0x07)
        goto loc_16d53;
    si = 0x5e;
    si += memoryAGet16(ds, 0x005c);
    callIndirect(cs, memoryAGet16(ds, si));
    return;
loc_16d53:
    cx = 0x0018;
    bx = 0x0004;
    if (memoryAGet(ds, 0x01e6) > 0x01)
        goto loc_16db8;
    if (memoryAGet(ds, 0x01e6) == 0x01)
        goto loc_16d9a;
    dx = cx;
    cl = memoryAGet(ds, 0x018f);
    cl++;
    if (memoryAGet(ds, 0x005a) > 0x0a)
        goto loc_16d88;
    cl = -cl;
    cl += 0x08;
loc_16d76:
    dl -= 0x03;
    si += 0x00f0;
    di += 0x00f0;
    if (--cx)
        goto loc_16d76;
    cx = dx;
    goto loc_16e00;
loc_16d88:
    dl -= 0x03;
    si += 0x00f0;
    di += 0x00f0;
    if (--cx)
        goto loc_16d88;
    cx = dx;
    goto loc_16e00;
loc_16d9a:
    dl = memoryAGet(ds, 0x018f);
    dl += dl;
    dl += memoryAGet(ds, 0x018f);
    dl += 0x03;
    if (memoryAGet(ds, 0x005a) > 0x0a)
        goto loc_16db3;
    dl = -dl;
    dl += 0x18;
loc_16db3:
    cl -= dl;
    goto loc_16e00;
loc_16db8:
    if (memoryAGet(ds, 0x01e6) == 0x03)
        goto loc_16de9;
    bl = memoryAGet(ds, 0x018f);
    bl >>= 1;
    bl++;
    dx = bx;
    if (memoryAGet(ds, 0x005a) < 0x0a)
        goto loc_16ddc;
    bl = -bl;
    bl += 0x04;
    si += dx;
    di += dx;
    goto loc_16e00;
loc_16ddc:
    si += 0x0004;
    si -= bx;
    di += 0x0004;
    di -= bx;
    goto loc_16e00;
loc_16de9:
    bl = memoryAGet(ds, 0x018f);
    bl >>= 1;
    bl++;
    if (memoryAGet(ds, 0x005a) < 0x0a)
        goto loc_16e00;
    bl = -bl;
    bl += 0x04;
    goto loc_16e00;
loc_16e00:
    push(cx);
    cx = bx;
loc_16e03:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_16e03;
    si += 0x0050;
    si -= bx;
    di += 0x0050;
    di -= bx;
    cx = pop();
    if (--cx)
        goto loc_16e00;
}
void sub_16d16()
{
loc_16d16:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16d16;
}
void sub_16e1b()
{
    bh = 0x00;
    bl = memoryAGet(ds, 0x018d);
    ax = bx;
    bx += bx;
    ax >>= 1;
    bx += ax;
    bp = memoryAGet16(ds, 0x0190);
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        goto loc_16e46;
    dh = 0x00;
    dl = memoryAGet(ds, 0x018f);
    dl &= 0xfe;
    bx += dx;
    bx += dx;
    dx >>= 1;
    bx += dx;
loc_16e46:
    si = 0xc760;
    si += bx;
    memoryASet16(ds, 0x01e9, si);
    if (memoryAGet(ds, 0x005a) != 0x00)
        goto loc_16e88;
    cx = 0x0018;
loc_16e59:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    al = memoryAGet(es, si + 4);
    memoryASet(es, di + 4, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16e59;
    return;
loc_16e88:
    memoryASet(ds, 0x005a, memoryAGet(ds, 0x005a) - 1);
    if (memoryAGet(ds, 0x018f) != 0x07)
        goto loc_16e9e;
    si = 0x5e;
    si += memoryAGet16(ds, 0x005c);
    callIndirect(cs, memoryAGet16(ds, si));
    return;
loc_16e9e:
    cx = 0x0018;
    bx = 0x0005;
    if (memoryAGet(ds, 0x01e6) == 0x03)
        goto loc_16ed5;
    bl = memoryAGet(ds, 0x018f);
    bl >>= 1;
    bl++;
    dx = bx;
    if (memoryAGet(ds, 0x005a) < 0x0a)
        goto loc_16ec8;
    bl = -bl;
    bl += 0x05;
    si += dx;
    di += dx;
    goto loc_16eec;
loc_16ec8:
    si += 0x0005;
    si -= bx;
    di += 0x0005;
    di -= bx;
    goto loc_16eec;
loc_16ed5:
    bl = memoryAGet(ds, 0x018f);
    bl >>= 1;
    bl++;
    if (memoryAGet(ds, 0x005a) <= 0x08)
        goto loc_16eec;
    bl = -bl;
    bl += 0x05;
    goto loc_16eec;
loc_16eec:
    push(cx);
    cx = bx;
loc_16eef:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_16eef;
    si += 0x0050;
    si -= bx;
    di += 0x0050;
    di -= bx;
    cx = pop();
    if (--cx)
        goto loc_16eec;
}
void sub_16e59()
{
loc_16e59:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    al = memoryAGet(es, si + 4);
    memoryASet(es, di + 4, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16e59;
}
void sub_16f07()
{
    si = memoryAGet16(ds, 0x0205);
    si += 0x0780;
    ch = 0x00;
    cl = memoryAGet(ds, 0x018f);
    cl++;
loc_16f17:
    si -= 0x00f0;
    if (--cx)
        goto loc_16f17;
    cx = 0x0003;
loc_16f20:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16f20;
}
void sub_16f47()
{
    si = memoryAGet16(ds, 0x0205);
    ch = 0x00;
    cl = memoryAGet(ds, 0x018f);
    cl++;
    si -= 0x00f0;
loc_16f57:
    si += 0x00f0;
    if (--cx)
        goto loc_16f57;
    cx = 0x0003;
loc_16f60:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_16f60;
}
void sub_16f87()
{
    si = memoryAGet16(ds, 0x0205);
    ch = 0x00;
    cl = memoryAGet(ds, 0x018f);
    cl >>= 1;
    si += cx;
    cx = 0x0018;
loc_16f98:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    di += 0x0050;
    si += 0x0050;
    if (--cx)
        goto loc_16f98;
    di -= 0x0780;
}
void sub_16fab()
{
    si = memoryAGet16(ds, 0x0205);
    si += 0x0003;
    ch = 0x00;
    cl = memoryAGet(ds, 0x018f);
    cl >>= 1;
    si -= cx;
    cx = 0x0018;
loc_16fbf:
    al = memoryAGet(es, si);
    memoryASet(es, di + 4, al);
    di += 0x0050;
    si += 0x0050;
    if (--cx)
        goto loc_16fbf;
    di -= 0x0780;
}
void sub_16fd3()
{
    bx = memoryAGet16(ds, 0x0207);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 442) == 0x0000)
        goto loc_16fec;
    memoryASet16(ds, bx + 442, memoryAGet16(ds, bx + 442) - 1);
    if (memoryAGet16(ds, bx + 442) <= 0x0017)
        goto loc_16fec;
    return;
loc_16fec:
    bx >>= 1;
    al = memoryAGet(ds, bx + 410);
    bx <<= 1;
    if (al != 0xff)
        goto loc_16ffb;
    goto loc_1712d;
loc_16ffb:
    memoryASet16(ds, 0x0205, 0x6da0);
    bp = memoryAGet16(ds, bx + 426);
    bx >>= 1;
    if (memoryAGet(ds, bx + 414) != 0x07)
        goto loc_17016;
    bx <<= 1;
    bp = memoryAGet16(ds, bx + 418);
    bx >>= 1;
loc_17016:
    if (!(memoryAGet(ds, bp + 124) & 0x04))
        goto loc_17024;
    sub_17192();
    goto loc_17032;
loc_17024:
    if (!(memoryAGet(ds, bp + 124) & 0x08))
        goto loc_17032;
    memoryASet16(ds, 0x0205, 0x6da4);
loc_17032:
    bx <<= 1;
    bp = memoryAGet16(ds, bx + 418);
    bx >>= 1;
    al = memoryAGet(ds, bx + 414);
    al++;
    al &= 0x07;
    memoryASet(ds, bx + 414, al);
    al = memoryAGet(ds, bx + 414);
    if (al == 0x00)
        goto loc_17055;
    dh = memoryAGet(ds, bx + 406);
    goto loc_17090;
loc_17055:
    dh = memoryAGet(ds, bx + 410);
    memoryASet(ds, bx + 406, dh);
    bx <<= 1;
    memoryASet16(ds, bx + 426, bp);
    if (dh != 0x00)
        goto loc_1706f;
    memoryASet16(ds, bx + 418, memoryAGet16(ds, bx + 418) + 1);
    goto loc_170e9;
loc_1706f:
    if (dh != 0x08)
        goto loc_1707b;
    memoryASet16(ds, bx + 418, memoryAGet16(ds, bx + 418) - 1);
    goto loc_1710b;
loc_1707b:
    if (dh != 0x10)
        goto loc_17088;
    memoryASet16(ds, bx + 418, memoryAGet16(ds, bx + 418) + 0x0015);
    goto loc_170c6;
loc_17088:
    memoryASet16(ds, bx + 418, memoryAGet16(ds, bx + 418) - 0x0015);
    goto loc_170aa;
loc_17090:
    bx <<= 1;
    if (dh != 0x00)
        goto loc_1709a;
    goto loc_170e9;
loc_1709a:
    if (dh != 0x08)
        goto loc_170a2;
    goto loc_1710b;
loc_170a2:
    if (dh != 0x10)
        goto loc_170aa;
    goto loc_170c6;
loc_170aa:
    di = memoryAGet16(ds, bx + 434);
    di += 0x0690;
    bx >>= 1;
    sub_1752c();
    di -= 0x0870;
    bx <<= 1;
    memoryASet16(ds, bx + 434, di);
    bx >>= 1;
    goto loc_17140;
loc_170c6:
    di = memoryAGet16(ds, bx + 434);
    di += 0x00f0;
    if (memoryAGet16(ds, bx + 442) > 0x000f)
        goto loc_170e0;
    di -= 0x00f0;
    bx >>= 1;
    sub_1756c();
    bx <<= 1;
loc_170e0:
    memoryASet16(ds, bx + 434, di);
    bx >>= 1;
    goto loc_17140;
loc_170e9:
    di = memoryAGet16(ds, bx + 434);
    bx >>= 1;
    if (memoryAGet(ds, bx + 414) & 0x01)
        goto loc_170fc;
    sub_174d1();
    goto loc_17143;
loc_170fc:
    sub_175ac();
    di++;
    bx <<= 1;
    memoryASet16(ds, bx + 434, di);
    bx >>= 1;
    goto loc_17140;
loc_1710b:
    di = memoryAGet16(ds, bx + 434);
    bx >>= 1;
    if (memoryAGet(ds, bx + 414) & 0x01)
        goto loc_17127;
    di--;
    bx <<= 1;
    memoryASet16(ds, bx + 434, di);
    bx >>= 1;
    sub_174d1();
    goto loc_17143;
loc_17127:
    sub_175d0();
    goto loc_17140;
loc_1712d:
    di = memoryAGet16(ds, bx + 434);
    bx >>= 1;
    if (memoryAGet(ds, bx + 414) & 0x01)
        goto loc_17140;
    sub_174d1();
    goto loc_17143;
loc_17140:
    sub_1741f();
loc_17143:
    bx = memoryAGet16(ds, 0x0207);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 434);
    ax += 0x0693;
    ax -= memoryAGet16(ds, 0x0194);
    if (ax <= 0x0d20)
        goto loc_1715a;
    return;
loc_1715a:
    if (ax <= 0x0006)
        goto loc_17181;
    if (ax == 0x0690)
        goto loc_17181;
    if (ax == 0x0696)
        goto loc_17181;
    dx = 0x00f1;
    cx = 0x000e;
loc_1716f:
    if (ax < dx)
        goto loc_17180;
    dx += 0x0004;
    if (ax < dx)
        goto loc_17181;
    dx += 0x00ec;
    if (--cx)
        goto loc_1716f;
loc_17180:
    return;
loc_17181:
    bx >>= 1;
    if (memoryAGet(ds, bx + 104) == 0x4d)
        goto loc_1718e;
    sub_171af();
    return;
loc_1718e:
    sub_172f7();
}
void sub_17192()
{
    push(bx);
    bx = 0x0000;
loc_17196:
    if (bp == memoryAGet16(ds, bx))
        goto loc_171a5;
    bx += 0x0004;
    if (bx != 0x0018)
        goto loc_17196;
    return;
loc_171a5:
    bx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x0205, bx);
    bx = pop();
}
void sub_171af()
{
    bx = 0x0000;
    sub_15dfa();
    si = memoryAGet16(ds, 0x03d3);
    si = memoryAGet16(ds, si + 3801);
    memoryASet16(ds, 0x0203, si);
    si += 0x0009;
    di = 0x196;
    cx = 0x0053;
    cx -= 0x0027;
    sub_15daa();
    si = 0x1053;
    bx = 0xffff;
    sub_15d7c();
    memoryASet16(ds, 0x05a8, 0x0000);
    ax = 0x5e4;
    memoryASet16(ds, 0x05aa, ax);
    si = 0xb0e0;
    di = memoryAGet16(ds, 0x0194);
    cx = 0x0010;
    if (memoryAGet(ds, 0x005b) == 0x00)
        goto loc_17211;
    di = memoryAGet16(ds, 0x005c);
    if (memoryAGet(ds, 0x005a) > 0x0a)
        goto loc_1720a;
    di += 0x0002;
    di &= 0x0002;
loc_1720a:
    di += 0x0004;
    di = memoryAGet16(ds, di + 474);
loc_17211:
    push(cx);
    push(si);
    push(di);
    sub_1610e();
    sub_15ecc();
    sub_16431();
    memoryASet16(ds, 0x111e, 0x0064);
    sub_1778e();
    di = pop();
    si = pop();
    si += 0x0004;
    cx = pop();
    sync();
    if (--cx)
        goto loc_17211;
    cx = 0x0005;
loc_17231:
    push(cx);
    sub_15ecc();
    memoryASet16(ds, 0x111e, 0x0064);
    sub_1778e();
    sync();
    cx = pop();
    if (al == 0x1b)
        return;
    if (--cx)
        goto loc_17231;
    memoryASet16(ds, 0x111e, 0x05dc);
    sub_17805();
    si = 0x6da0;
    bx = memoryAGet16(ds, 0x0190);
    if (!(memoryAGet(ds, bx + 124) & 0x08))
        goto loc_1725f;
    si = 0x6da4;
loc_1725f:
    sub_1610e();
    if (memoryAGet(ds, 0x0034) == 0x00)
        goto loc_17274;
    si = memoryAGet16(ds, 0x0012);
    di = memoryAGet16(ds, 0x0037);
    sub_1610e();
loc_17274:
    if (memoryAGet(ds, 0x064f) != 0x02)
        goto loc_17281;
    memoryASet(ds, 0x0064, 0x01);
    return;
loc_17281:
    if (memoryAGet(ds, 0x0253) == 0x01)
        goto loc_1729a;
    tx = memoryAGet16(ds, 0x0224);
    memoryASet16(ds, 0x0224, memoryAGet16(ds, 0x0224) - 1);
    if (tx != 1)
        goto loc_1729a;
    memoryASet16(ds, 0x0066, 0x0000);
    memoryASet(ds, 0x0062, 0x01);
    return;
loc_1729a:
    sub_1444f();
    if (memoryAGet16(ds, 0x0224) == 0x0000)
    {
        while (1) sync();
        return;
    }
    sub_172b1();
    memoryASet16(ds, 0x111e, 0x0bb8);
    sub_17805();
}
void sub_172b1()
{
    di = 0x0460;
    al = memoryAGet(ds, 0x064f);
    al += memoryAGet(ds, 0x0217);
    if (al == 0x03)
        goto loc_172c2;
    di = 0x049c;
loc_172c2:
    ax = memoryAGet16(ds, 0x0224);
    ax--;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    si = 0xd69f;
    if (memoryAGet16(ds, 0x03d3) != 0x0002)
        goto loc_172d9;
    si = 0xad48;
loc_172d9:
    cx = 0x0001;
    sub_176c7();
}
void sub_172f7()
{
    di = 0x236;
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_17306;
    di = 0x23f;
loc_17306:
    memoryASet16(ds, di, memoryAGet16(ds, di) + 1);
    memoryASet16(ds, 0x05a8, 0x0000);
    ax = 0x610;
    memoryASet16(ds, 0x05aa, ax);
    bx = memoryAGet16(ds, 0x0207);
    memoryASet(ds, bx + 104, 0x47);
    bx <<= 1;
    memoryASet16(ds, bx + 108, 0x0000);
    si = 0x1053;
    push(bx);
    sub_15d7c();
    bx = pop();
    sub_1826d();
    al = ah;
    ax &= 0x00ff;
    ax += 0x0064;
    memoryASet16(ds, bx + 442, ax);
    si = 0x6da0;
    di = memoryAGet16(ds, bx + 434);
    bx >>= 1;
    if (memoryAGet(ds, bx + 414) & 0x01)
        goto loc_1735b;
    if (memoryAGet(ds, bx + 406) & 0x10)
        goto loc_1735b;
    sub_16138();
    goto loc_1735e;
loc_1735b:
    sub_1610e();
loc_1735e:
    bx <<= 1;
    memoryASet16(ds, bx + 116, 0x0032);
    si = memoryAGet16(ds, 0x0058);
    dx = memoryAGet16(ds, si + 1415);
    si = memoryAGet16(ds, si + 1407);
    di = memoryAGet16(ds, bx + 418);
    bx <<= 1;
    bp = memoryAGet16(ds, bx);
    memoryASet(ds, bp + 124, memoryAGet(ds, bp + 124) & 0xfb);
    memoryASet16(ds, bx, di);
    memoryASet16(ds, bx + 2, si);
    bx >>= 1;
    memoryASet(ds, di + 124, memoryAGet(ds, di + 124) | 0x04);
    di <<= 1;
    di = memoryAGet16(ds, di + 1617);
    sub_1610e();
    di = memoryAGet16(ds, bx + 426);
    if (!(memoryAGet(ds, di + 124) & 0x08))
        goto loc_173b1;
    di <<= 1;
    di = memoryAGet16(ds, di + 1617);
    si = 0x6da4;
    sub_1610e();
loc_173b1:
    bx >>= 1;
    cx = 0x0003;
    si = memoryAGet16(ds, 0x0203);
    si += 0x0009;
    di = 0x196;
    di += bx;
loc_173c3:
    al = memoryAGet(ds, si);
    memoryASet(ds, di, al);
    si += 0x0004;
    di += 0x0004;
    if (--cx)
        goto loc_173c3;
    di += bx;
    cx = 0x0003;
loc_173d4:
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    si += 0x0008;
    di += 0x0008;
    if (--cx)
        goto loc_173d4;
    memoryASet16(ds, 0x0211, memoryAGet16(ds, 0x0211) + dx);
    sub_176fc();
    memoryASet16(ds, 0x0058, memoryAGet16(ds, 0x0058) + 0x0002);
    bp = 0x0000;
    if (memoryAGet16(ds, 0x0058) == 0x0008)
        goto loc_173f7;
    return;
loc_173f7:
    memoryASet16(ds, 0x0058, 0x0000);
    memoryASet(ds, bp + 104, 0x47);
    bp <<= 1;
    memoryASet16(ds, bp + 108, 0x0000);
    bp >>= 1;
    bp++;
    if (bp != 0x0004)
        goto loc_173f7;
    si = 0x1053;
    bx = 0xffff;
    sub_15d7c();
}
void sub_1741f()
{
    dh = 0x00;
    dl = memoryAGet(ds, bx + 414);
    bx <<= 1;
    si = memoryAGet16(ds, bx + 491);
    bx >>= 1;
    ah = dh;
    al = memoryAGet(ds, bx + 406);
    if (!(al & 0x10))
        goto loc_17447;
    si += 0x0020;
    if (dl & 0x01)
        goto loc_17447;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 499);
    bx >>= 1;
loc_17447:
    dl &= 0xfe;
    dx <<= 1;
    si += dx;
    al &= 0x08;
    ax <<= 1;
    si += ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 442);
    bx >>= 1;
    if (ax > 0x0010)
        goto loc_1748b;
    cx = 0x0018;
loc_17464:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_17464;
    return;
loc_1748b:
    cx = 0x0018;
    dx = cx;
    cl = memoryAGet(ds, bx + 414);
    cl++;
    cl = -cl;
    cl += 0x08;
loc_1749b:
    dl -= 0x03;
    si += 0x00f0;
    di += 0x00f0;
    if (--cx)
        goto loc_1749b;
    cx = dx;
loc_174aa:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_174aa;
}
void sub_174d1()
{
    ch = 0x00;
    cl = memoryAGet(ds, bx + 406);
    ax = cx;
    cx += cx;
    ax >>= 1;
    cx += ax;
    dh = 0x00;
    dl = memoryAGet(ds, bx + 414);
    dl &= 0xfe;
    cx += dx;
    cx += dx;
    dx >>= 1;
    cx += dx;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 507);
    bx >>= 1;
    si += cx;
    cx = 0x0018;
loc_174fd:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    al = memoryAGet(es, si + 4);
    memoryASet(es, di + 4, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_174fd;
}
void sub_1752c()
{
    si = memoryAGet16(ds, 0x0205);
    si += 0x0780;
    ch = 0x00;
    cl = memoryAGet(ds, bx + 414);
    cl++;
loc_1753c:
    si -= 0x00f0;
    if (--cx)
        goto loc_1753c;
    cx = 0x0003;
loc_17545:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_17545;
}
void sub_1756c()
{
    si = memoryAGet16(ds, 0x0205);
    ch = 0x00;
    cl = memoryAGet(ds, bx + 414);
    cl++;
    si -= 0x00f0;
loc_1757c:
    si += 0x00f0;
    if (--cx)
        goto loc_1757c;
    cx = 0x0003;
loc_17585:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    al = memoryAGet(es, si + 3);
    memoryASet(es, di + 3, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_17585;
}
void sub_175ac()
{
    si = memoryAGet16(ds, 0x0205);
    ch = 0x00;
    cl = memoryAGet(ds, bx + 414);
    cl >>= 1;
    si += cx;
    cx = 0x0018;
loc_175bd:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    di += 0x0050;
    si += 0x0050;
    if (--cx)
        goto loc_175bd;
    di -= 0x0780;
}
void sub_175d0()
{
    si = memoryAGet16(ds, 0x0205);
    si += 0x0003;
    ch = 0x00;
    cl = memoryAGet(ds, bx + 414);
    cl >>= 1;
    si -= cx;
    cx = 0x0018;
loc_175e4:
    al = memoryAGet(es, si);
    memoryASet(es, di + 4, al);
    di += 0x0050;
    si += 0x0050;
    if (--cx)
        goto loc_175e4;
    di -= 0x0780;
}
void sub_175f8()
{
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    ax = 0x0000;
    out(dx, ax);
    ax = 0x0001;
    out(dx, ax);
    ax = 0x0002;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    ax = 0x0004;
    out(dx, ax);
    ax = 0x0f07;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    es = memoryAGet16(ds, 0x024b);
    di = 0;
    dx = 0x03ce;
    ah = 0x0f;
    al = 0x00;
    out(dx, ax);
    ax = 0x0f01;
    out(dx, ax);
    cx = 0x36b0;
    flags.direction = false;
    rep_stosw<MemAuto, DirAuto>();
    ax = 0x0001;
    out(dx, ax);
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
}
void sub_1763f()
{
    si = 0xd890;
    si += 0x0034;
    di = 0x0001;
    cx = 0x0007;
loc_1764b:
    push(cx);
    cx = 0x0012;
loc_1764f:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_1764f;
    si += 0x003e;
    di += 0x003e;
    cx = pop();
    if (--cx)
        goto loc_1764b;
    push(memoryAGet16(ds, 0x0211));
    ax = memoryAGet16(ds, 0x1a38);
    memoryASet16(ds, 0x0211, ax);
    memoryASet16(ds, 0x107d, 0xd890);
    memoryASet16(ds, 0x107f, 0x0c38);
    sub_176fc();
    memoryASet16(ds, 0x0211, pop());
}
void sub_17680()
{
    cx = 0x0007;
loc_17683:
    push(cx);
    cx = 0x0010;
loc_17687:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_17687;
    si += 0x0040;
    di += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_17683;
}
void sub_1769b()
{
    cx = memoryAGet16(ds, 0x0224);
    if (memoryAGet(ds, 0x064f) == 0x01)
        goto loc_176b5;
    cx = memoryAGet16(ds, 0x0226);
    if (memoryAGet(ds, 0x0217) == 0x01)
        goto loc_176b5;
    cx = memoryAGet16(ds, 0x0228);
loc_176b5:
    if (cx == 0x0000)
        return;
    si = 0xd6a7;
    if (memoryAGet16(ds, 0x03d3) != 0x0002)
        goto loc_176c7;
    si = 0xad50;
loc_176c7:
    push(cx);
    cx = 0x0002;
loc_176cb:
    push(cx);
    cx = 0x0009;
loc_176cf:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_176cf;
    si += 0xfd34;
    cx = pop();
    if (--cx)
        goto loc_176cb;
    di += 0xfa64;
    cx = pop();
    if (--cx)
        goto loc_176b5;
}
void sub_176c7()
{
    goto loc_176c7;
loc_176b5:
    if (cx == 0x0000)
        return;
    si = 0xd6a7;
    if (memoryAGet16(ds, 0x03d3) != 0x0002)
        goto loc_176c7;
    si = 0xad50;
loc_176c7:
    push(cx);
    cx = 0x0002;
loc_176cb:
    push(cx);
    cx = 0x0009;
loc_176cf:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    al = memoryAGet(es, si + 2);
    memoryASet(es, di + 2, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_176cf;
    si += 0xfd34;
    cx = pop();
    if (--cx)
        goto loc_176cb;
    di += 0xfa64;
    cx = pop();
    if (--cx)
        goto loc_176b5;
}
void sub_176fc()
{
    push(ax);
    push(bx);
    push(dx);
    dx = memoryAGet16(ds, 0x0211);
    di = memoryAGet16(ds, 0x107f);
    bx = 0x1075;
loc_1770b:
    al = 0x00;
loc_1770d:
    if ((short)dx < (short)memoryAGet16(ds, bx))
        goto loc_17717;
    al++;
    dx -= memoryAGet16(ds, bx);
    goto loc_1770d;
loc_17717:
    sub_17738();
    di += 0x0002;
    bx += 0x0002;
    al = 0x0a;
    if (memoryAGet(ds, bx + 65534) != al)
        goto loc_1770b;
    al = dl;
    sub_17738();
    di += 0x0002;
    al = 0x00;
    sub_17738();
    dx = pop();
    bx = pop();
    ax = pop();
}
void sub_17738()
{
    push(ax);
    ax = es;
    ax = pop();
    if (ax == memoryAGet16(ds, 0x024f))
        goto loc_1776a;
    si = memoryAGet16(ds, 0x107d);
    ah = 0x00;
    al += al;
    si += ax;
    cx = 0x0007;
loc_1774f:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    al = memoryAGet(es, si + 1);
    memoryASet(es, di + 1, al);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_1774f;
    di -= 0x0230;
    return;
loc_1776a:
    ah = 0x04;
    al += 0x30;
    memoryASet16(es, di, ax);
}
void sub_17772()
{
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_1777a;
    return;
loc_1777a:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
loc_17780:
    cx = memoryAGet16(ds, 0x111e);
loc_17784:
    if (--cx)
        goto loc_17784;
    cx = bx;
    bx--;
    if (--cx)
        goto loc_17780;
    cx = pop();
    bx = pop();
}
void sub_1778e()
{
    memoryASet(ds, 0x1122, 0x00);
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_177ae;
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_177aa;
    memoryASet(ds, 0x1122, 0x01);
    ah = 0x00;
    interrupt(0x16);
    return;
loc_177aa:
    ax = 0xffff;
    return;
loc_177ae:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
    if (memoryAGet(ds, 0x0254) == 0x00)
        goto loc_177c6;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx++;
loc_177c6:
    cx = memoryAGet16(ds, 0x111e);
loc_177ca:
    if (--cx)
        goto loc_177ca;
    if (memoryAGet(ds, 0x1449) == 0x00)
        goto loc_177dc;
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_177fd;
    goto loc_177e4;
loc_177dc:
    sub_180e0();
    if (ax != 0xffff)
        goto loc_177ec;
loc_177e4:
    cx = bx;
    bx--;
    if (--cx)
        goto loc_177c6;
    goto loc_17802;
loc_177ec:
    if (al != 0x1b)
        goto loc_177e4;
    if (memoryAGet(ds, 0x2127) != 0x00)
        goto loc_177fd;
    sub_14639();
    goto loc_17802;
loc_177fd:
    memoryASet(ds, 0x1122, 0x01);
loc_17802:
    cx = pop();
    bx = pop();
}
void sub_17805()
{
    memoryASet(ds, 0x1122, 0x00);
    if (memoryAGet16(ds, 0x1120) > 0x0001)
        goto loc_17825;
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_17821;
    memoryASet(ds, 0x1122, 0x01);
    ah = 0x00;
    interrupt(0x16);
    return;
loc_17821:
    ax = 0xffff;
    return;
loc_17825:
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x1120);
    if (memoryAGet(ds, 0x0254) == 0x00)
        goto loc_1783d;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx++;
loc_1783d:
    cx = memoryAGet16(ds, 0x111e);
loc_17841:
    if (--cx)
        goto loc_17841;
    sync();
    if (memoryAGet(ds, 0x1449) == 0x00)
        goto loc_17853;
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_17874;
    goto loc_1785b;
loc_17853:
    sub_180d2();
    if (ax != 0xffff)
        goto loc_17863;
loc_1785b:
    cx = bx;
    bx--;
    if (--cx)
        goto loc_1783d;
    goto loc_17879;
loc_17863:
    if (al != 0x1b)
        goto loc_17874;
    if (memoryAGet(ds, 0x2127) != 0x00)
        goto loc_17874;
    sub_14639();
    goto loc_17879;
loc_17874:
    memoryASet(ds, 0x1122, 0x01);
loc_17879:
    cx = pop();
    bx = pop();
}
void sub_1787c()
{
    sub_180e0();
    if (ax == 0xffff)
        goto loc_17885;
    return;
loc_17885:
    ax = memoryAGet16(ds, 0x03ff);
    memoryASet16(ds, 0x111e, ax);
    ax = memoryAGet16(ds, 0x0401);
    bx = memoryAGet16(ds, 0x1120);
    memoryASet16(ds, 0x0401, bx);
    memoryASet16(ds, 0x1120, ax);
    dx = 0x270;
    sub_17f06();
    ax = memoryAGet16(ds, 0x024d);
    sub_17f7b();
    si = 0x110a;
    sub_180a7();
    sub_175f8();
    sub_1793c();
    si = 0x10b5;
    sub_180a7();
    es = memoryAGet16(ds, 0x024b);
    memoryASet16(ds, 0x0405, 0x7fd0);
    memoryASet16(ds, 0x0407, 0x9286);
    memoryASet16(ds, 0x0409, 0x2d5d);
    memoryASet16(ds, 0x040b, 0x2d89);
    memoryASet16(ds, 0x0411, 0x0091);
    memoryASet16(ds, 0x0413, 0x0007);
    memoryASet16(ds, 0x040d, 0x0050);
    memoryASet16(ds, 0x040f, 0xffb0);
    sub_17c31();
    si = 0xb720;
    di = 0x2a9e;
    sub_17d32();
    if (ax != 0xffff)
        goto loc_1791f;
loc_178ff:
    sub_17a24();
    sub_17c31();
    sub_180e0();
    sync();
    if (ax != 0xffff)
        goto loc_1791f;
    if (memoryAGet(ds, 0x144a) != 0x01)
        goto loc_178ff;
    if (memoryAGet16(ds, 0x0411) != 0x0091)
        goto loc_178ff;
    ax = 0xffff;
loc_1791f:
    bx = memoryAGet16(ds, 0x111e);
    memoryASet16(ds, 0x03ff, bx);
    bx = memoryAGet16(ds, 0x0401);
    cx = memoryAGet16(ds, 0x1120);
    memoryASet16(ds, 0x0401, cx);
    memoryASet16(ds, 0x1120, bx);
    dx = 0x270;
}
void sub_17885()
{
    ax = memoryAGet16(ds, 0x03ff);
    memoryASet16(ds, 0x111e, ax);
    ax = memoryAGet16(ds, 0x0401);
    bx = memoryAGet16(ds, 0x1120);
    memoryASet16(ds, 0x0401, bx);
    memoryASet16(ds, 0x1120, ax);
    dx = 0x270;
    sub_17f06();
    ax = memoryAGet16(ds, 0x024d);
    sub_17f7b();
    si = 0x110a;
    sub_180a7();
    sub_175f8();
    sub_1793c();
    si = 0x10b5;
    sub_180a7();
    es = memoryAGet16(ds, 0x024b);
    memoryASet16(ds, 0x0405, 0x7fd0);
    memoryASet16(ds, 0x0407, 0x9286);
    memoryASet16(ds, 0x0409, 0x2d5d);
    memoryASet16(ds, 0x040b, 0x2d89);
    memoryASet16(ds, 0x0411, 0x0091);
    memoryASet16(ds, 0x0413, 0x0007);
    memoryASet16(ds, 0x040d, 0x0050);
    memoryASet16(ds, 0x040f, 0xffb0);
    sub_17c31();
    si = 0xb720;
    di = 0x2a9e;
    sub_17d32();
    if (ax != 0xffff)
        goto loc_1791f;
loc_178ff:
    sub_17a24();
    sub_17c31();
    sub_180e0();
    if (ax != 0xffff)
        goto loc_1791f;
    if (memoryAGet(ds, 0x144a) != 0x01)
        goto loc_178ff;
    if (memoryAGet16(ds, 0x0411) != 0x0091)
        goto loc_178ff;
    ax = 0xffff;
loc_1791f:
    bx = memoryAGet16(ds, 0x111e);
    memoryASet16(ds, 0x03ff, bx);
    bx = memoryAGet16(ds, 0x0401);
    cx = memoryAGet16(ds, 0x1120);
    memoryASet16(ds, 0x0401, cx);
    memoryASet16(ds, 0x1120, bx);
    dx = 0x270;
}
void sub_1793c()
{
    sub_179e3();
    si = 0xbaa4;
    di = 0x19b7;
    cx = 0x0033;
loc_17948:
    push(cx);
    cx = 0x0022;
loc_1794c:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_1794c;
    si += 0x002e;
    di += 0x002e;
    cx = pop();
    if (--cx)
        goto loc_17948;
    bx = 0;
    cx = 0x000a;
loc_17964:
    push(cx);
    si = 0xbad0;
    di = memoryAGet16(ds, bx + 1045);
    bx += 0x0002;
    cx = 0x0042;
loc_17972:
    push(cx);
    cx = 0x000c;
loc_17976:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_17976;
    si += 0x0044;
    di += 0x0044;
    cx = pop();
    if (--cx)
        goto loc_17972;
    cx = pop();
    if (--cx)
        goto loc_17964;
    si = 0xd200;
    di = 0x46b8;
    cx = 0x0003;
loc_17995:
    push(cx);
    cx = 0x0009;
loc_17999:
    push(cx);
    cx = 0x0020;
loc_1799d:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_1799d;
    si += 0x0030;
    di += 0x0030;
    cx = pop();
    if (--cx)
        goto loc_17999;
    di += 0x0f00;
    cx = pop();
    if (--cx)
        goto loc_17995;
    di = 0x4988;
    cx = 0x0002;
loc_179bd:
    push(cx);
    si = 0xcbe0;
    cx = 0x0030;
loc_179c4:
    push(cx);
    cx = 0x0020;
loc_179c8:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_179c8;
    si += 0x0030;
    di += 0x0030;
    cx = pop();
    if (--cx)
        goto loc_179c4;
    di += 0x02d0;
    cx = pop();
    if (--cx)
        goto loc_179bd;
}
void sub_179e3()
{
    si = 0xd062;
    di = 0x6901;
    cx = 0x000d;
loc_179ec:
    push(cx);
    cx = 0x000b;
loc_179f0:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_179f0;
    si += 0x0045;
    di += 0x0045;
    cx = pop();
    if (--cx)
        goto loc_179ec;
    si = 0xd602;
    di = 0x6948;
    cx = 0x000d;
loc_17a0c:
    push(cx);
    cx = 0x0007;
loc_17a10:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_17a10;
    si += 0x0049;
    di += 0x0049;
    cx = pop();
    if (--cx)
        goto loc_17a0c;
}
void sub_17a24()
{
    dx = 0x03ce;
    ax = 0x0205;
    out(dx, ax);
    bx = 0x0000;
loc_17a2e:
    memoryASet16(ds, 0x0429, bx);
    di = memoryAGet16(ds, bx + 1171);
    di = memoryAGet16(ds, di + 1224);
    push(bx);
    ax = memoryAGet16(ds, bx + 1119);
    bx = memoryAGet16(ds, bx + 1067);
    callIndirect(cs, di);
    bx = pop();
    memoryASet16(ds, bx + 1171, memoryAGet16(ds, bx + 1171) + 0x0002);
    if (memoryAGet16(ds, bx + 1171) <= 0x0040)
        goto loc_17a58;
    memoryASet16(ds, bx + 1171, 0x0000);
loc_17a58:
    bx += 0x0002;
    if (bx <= 0x0032)
        goto loc_17a2e;
    dx = 0x03ce;
    ax = 0x0105;
    out(dx, ax);
}
void sub_17a67()
{
}
void sub_17a68()
{
    memoryASet(ds, 0x04c7, 0x00);
    sub_17b9a();
}
void sub_17a71()
{
    memoryASet(ds, 0x04c7, 0x00);
    ax--;
    sub_17b9a();
    ax += 0x0002;
    sub_17b9a();
    ax--;
    bx--;
    sub_17b9a();
    bx += 0x0002;
    sub_17b9a();
}
void sub_17a8c()
{
    memoryASet(ds, 0x04c7, 0x09);
    ax += 0x0002;
    sub_17b9a();
    ax -= 0x0004;
    sub_17b9a();
    ax += 0x0002;
    bx += 0x0002;
    sub_17b9a();
    bx -= 0x0004;
    sub_17b9a();
}
void sub_17aad()
{
    memoryASet(ds, 0x04c7, 0x09);
    ax += 0x0003;
    sub_17b9a();
    ax -= 0x0006;
    sub_17b9a();
    ax += 0x0003;
    bx += 0x0003;
    sub_17b9a();
    bx -= 0x0006;
    sub_17b9a();
}
void sub_17ace()
{
    memoryASet(ds, 0x04c7, 0x06);
    ax += 0x0004;
    sub_17b9a();
    ax -= 0x0008;
    sub_17b9a();
    ax += 0x0004;
    bx += 0x0004;
    sub_17b9a();
    bx -= 0x0008;
    sub_17b9a();
}
void sub_17aef()
{
    memoryASet(ds, 0x04c7, 0x06);
    ax += 0x0005;
    sub_17b9a();
    ax -= 0x000a;
    sub_17b9a();
    ax += 0x0005;
    bx += 0x0005;
    sub_17b9a();
    bx -= 0x000a;
    sub_17b9a();
}
void sub_17b10()
{
    sub_17bcb();
}
void sub_17b14()
{
    ax--;
    sub_17bcb();
    ax += 0x0002;
    sub_17bcb();
    ax--;
    bx--;
    sub_17bcb();
    bx += 0x0002;
    sub_17bcb();
}
void sub_17b2a()
{
    ax += 0x0002;
    sub_17bcb();
    ax -= 0x0004;
    sub_17bcb();
    ax += 0x0002;
    bx += 0x0002;
    sub_17bcb();
    bx -= 0x0004;
    sub_17bcb();
}
void sub_17b46()
{
    ax += 0x0003;
    sub_17bcb();
    ax -= 0x0006;
    sub_17bcb();
    ax += 0x0003;
    bx += 0x0003;
    sub_17bcb();
    bx -= 0x0006;
    sub_17bcb();
}
void sub_17b62()
{
    ax += 0x0004;
    sub_17bcb();
    ax -= 0x0008;
    sub_17bcb();
    ax += 0x0004;
    bx += 0x0004;
    sub_17bcb();
    bx -= 0x0008;
    sub_17bcb();
}
void sub_17b7e()
{
    ax += 0x0005;
    sub_17bcb();
    ax -= 0x000a;
    sub_17bcb();
    ax += 0x0005;
    bx += 0x0005;
    sub_17bcb();
    bx -= 0x000a;
    sub_17bcb();
}
void sub_17b9a()
{
    push(ax);
    push(bx);
    cl = bl;
    dx = 0x0050;
    mul(dx);
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx += ax;
    cl &= 0x07;
    cl ^= 0x07;
    ah = 0x01;
    ah <<= cl;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    al = memoryAGet(es, bx);
    al = memoryAGet(ds, 0x04c7);
    memoryASet(es, bx, al);
    bx = pop();
    ax = pop();
}
void sub_17bcb()
{
    push(ax);
    push(bx);
    cl = bl;
    dx = 0x0050;
    mul(dx);
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx += ax;
    cl &= 0x07;
    cl ^= 0x07;
    ah = 0x01;
    push(ax);
    push(bx);
    push(cx);
    bx += 0xa0ed;
    if (memoryAGet16(ds, 0x0429) <= 0x0024)
        goto loc_17bf6;
    bx += 0xeb95;
loc_17bf6:
    ch = ah;
    ch <<= cl;
    si = bx;
    bl = 0;
    dx = 0x03ce;
    ax = 0x0304;
loc_17c04:
    out(dx, ax);
    bh = memoryAGet(es, si);
    bh &= ch;
    bh = -bh;
    bx = rol(bx, 0x0001);
    tl = ah;
    ah--;
    if ((char)tl >= 1)
        goto loc_17c04;
    memoryASet(ds, 0x04c7, bl);
    cx = pop();
    bx = pop();
    ax = pop();
    ah <<= cl;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    al = memoryAGet(es, bx);
    al = memoryAGet(ds, 0x04c7);
    memoryASet(es, bx, al);
    bx = pop();
    ax = pop();
}
void sub_17c31()
{
    sub_17772();
    si = memoryAGet16(ds, 0x0405);
    di = memoryAGet16(ds, 0x0409);
    sub_17d17();
    si = memoryAGet16(ds, 0x0407);
    di = memoryAGet16(ds, 0x040b);
    sub_17d17();
    memoryASet16(ds, 0x0411, memoryAGet16(ds, 0x0411) + 1);
    memoryASet16(ds, 0x0413, memoryAGet16(ds, 0x0413) + 1);
    if (memoryAGet16(ds, 0x0411) != 0x0123)
        goto loc_17c68;
    memoryASet16(ds, 0x0411, 0x0000);
    memoryASet16(ds, 0x040d, -memoryAGet16(ds, 0x040d));
    memoryASet16(ds, 0x040f, -memoryAGet16(ds, 0x040f));
loc_17c68:
    si = memoryAGet16(ds, 0x040d);
    di = memoryAGet16(ds, 0x040f);
    memoryASet16(ds, 0x0409, memoryAGet16(ds, 0x0409) + si);
    memoryASet16(ds, 0x040b, memoryAGet16(ds, 0x040b) + di);
    ax = memoryAGet16(ds, 0x0413);
    if (ax != 0x001f)
        goto loc_17cf7;
    memoryASet16(ds, 0x0413, 0xffff);
    memoryASet16(ds, 0x0405, 0x6d60);
    memoryASet16(ds, 0x0407, 0xa4f6);
    if (memoryAGet(ds, 0x0404) == 0x00)
        return;
    if (memoryAGet(ds, 0x0404) == 0x02)
        goto loc_17cd0;
    if (memoryAGet(ds, 0x0404) == 0x03)
        goto loc_17ceb;
    memoryASet16(ds, 0x111e, memoryAGet16(ds, 0x111e) - 1);
    sub_140c1();
    al = 0x41;
    if (bx >= 0x0078)
        goto loc_17cbc;
    al = 0x42;
    memoryASet16(ds, 0x111e, memoryAGet16(ds, 0x111e) + 0x0002);
loc_17cbc:
    if (al != memoryAGet(ds, 0x0403))
        goto loc_17cca;
    sub_15cc3();
    memoryASet16(ds, 0x2518, dx);
    return;
loc_17cca:
    memoryASet(ds, 0x0404, 0x00);
    return;
loc_17cd0:
    memoryASet16(ds, 0x111e, memoryAGet16(ds, 0x111e) - 1);
    sub_140c1();
    memoryASet(ds, 0x0403, 0x41);
    if (bx >= 0x0078)
        goto loc_17ceb;
    memoryASet(ds, 0x0403, 0x42);
    memoryASet16(ds, 0x111e, memoryAGet16(ds, 0x111e) + 0x0002);
loc_17ceb:
    memoryASet(ds, 0x0404, memoryAGet(ds, 0x0404) - 1);
    sub_15cc3();
    memoryASet16(ds, 0x2518, dx);
    return;
loc_17cf7:
    ax &= 0x0007;
    if (ax != 0x0007)
        goto loc_17d0c;
    memoryASet16(ds, 0x0405, memoryAGet16(ds, 0x0405) + 0x122a);
    memoryASet16(ds, 0x0407, memoryAGet16(ds, 0x0407) - 0x122a);
    return;
loc_17d0c:
    memoryASet16(ds, 0x0405, memoryAGet16(ds, 0x0405) + 0x000a);
    memoryASet16(ds, 0x0407, memoryAGet16(ds, 0x0407) - 0x000a);
}
void sub_17d17()
{
    cx = 0x003b;
loc_17d1a:
    push(cx);
    cx = 0x000a;
loc_17d1e:
    al = memoryAGet(es, si);
    memoryASet(es, di, al);
    si++;
    di++;
    if (--cx)
        goto loc_17d1e;
    si += 0x0046;
    di += 0x0046;
    cx = pop();
    if (--cx)
        goto loc_17d1a;
}
void sub_17d32()
{
    ax = 0x0205;
    dx = 0x03ce;
    out(dx, ax);
    al = 0x03;
    ah = 0x00;
    out(dx, ax);
    memoryASet16(ds, 0x050a, 0x01fe);
    memoryASet16(ds, 0x050c, 0x00ff);
    push(di);
    push(dx);
    sub_17dd8();
    sub_17e3a();
    dx = pop();
    di = pop();
    cl = memoryAGet(ds, 0x050e);
    cx |= 0x0010;
loc_17d5b:
    flags.carry = cl & 1;
    cl >>= 1;
    if (!flags.carry)
        goto loc_17d5b;
loc_17d5f:
    push(cx);
    cl = memoryAGet(ds, 0x050e);
    memoryASet16(ds, 0x050a, memoryAGet16(ds, 0x050a) >> cl);
    memoryASet16(ds, 0x050a, memoryAGet16(ds, 0x050a) & 0xfffe);
    memoryASet16(ds, 0x050c, memoryAGet16(ds, 0x050c) >> cl);
    bp = 0x3660;
    cx = 0x06cc;
loc_17d77:
    sub_180e0();
    if (ax == 0xffff)
        goto loc_17d81;
    cx = pop();
    return;
loc_17d81:
    push(cx);
    push(di);
    es = memoryAGet16(ds, 0x026b);
    di += memoryAGet16(es, bp);
    si = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    cx = 0x0008;
    memoryASet(ds, 0x1081, 0x80);
loc_17d9a:
    es = memoryAGet16(ds, 0x026b);
    push(si);
    sub_17ec6();
    bl = 0x0f;
    if (si > 0x365f)
        goto loc_17dad;
    bl = memoryAGet(es, si);
loc_17dad:
    si = pop();
    si++;
    es = memoryAGet16(ds, 0x024b);
    al = 0x08;
    ah = memoryAGet(ds, 0x1081);
    out(dx, ax);
    memoryASet(ds, 0x1081, memoryAGet(ds, 0x1081) >> 1);
    al = memoryAGet(es, di);
    memoryASet(es, di, bl);
    if (--cx)
        goto loc_17d9a;
    di = pop();
    cx = pop();
    if (--cx)
        goto loc_17d77;
    sync();
    cx = pop();
    if (--cx)
        goto loc_17d5f;
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    ax = 0xffff;
}
void sub_17dd8()
{
    di = 0x0000;
    cx = 0x0057;
loc_17dde:
    push(cx);
    cx = 0x0014;
loc_17de2:
    push(cx);
    es = memoryAGet16(ds, 0x024b);
    dx = 0x03ce;
    ax = 0x0304;
    out(dx, ax);
    bh = memoryAGet(es, si);
    dx = 0x03ce;
    ax = 0x0204;
    out(dx, ax);
    bl = memoryAGet(es, si);
    dx = 0x03ce;
    ax = 0x0104;
    out(dx, ax);
    ch = memoryAGet(es, si);
    dx = 0x03ce;
    ax = 0x0004;
    out(dx, ax);
    cl = memoryAGet(es, si);
    ax = cx;
    es = memoryAGet16(ds, 0x026b);
    cx = 0x0008;
loc_17e18:
    flags.carry = !!(bh & 0x80);
    bh <<= 1;
    memoryASet(es, di, rcl(memoryAGet(es, di), 1));
    flags.carry = !!(bl & 0x80);
    bl <<= 1;
    memoryASet(es, di, rcl(memoryAGet(es, di), 1));
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    memoryASet(es, di, rcl(memoryAGet(es, di), 1));
    flags.carry = !!(al & 0x80);
    al <<= 1;
    memoryASet(es, di, rcl(memoryAGet(es, di), 1));
    di++;
    if (--cx)
        goto loc_17e18;
    si++;
    cx = pop();
    if (--cx)
        goto loc_17de2;
    si += 0x003c;
    cx = pop();
    if (--cx)
        goto loc_17dde;
}
void sub_17e3a()
{
    es = memoryAGet16(ds, 0x026b);
    bp = 0x0000;
    di = 0x0000;
    ax = 0x0000;
    cx = 0x0057;
loc_17e4a:
    push(cx);
    cx = 0x0014;
loc_17e4e:
    memoryASet16(es, di + 20880, bp);
    di += 0x0002;
    memoryASet16(es, di + 20880, ax);
    di += 0x0002;
    ax += 0x0008;
    bp++;
    if (--cx)
        goto loc_17e4e;
    bp += 0x003c;
    cx = pop();
    if (--cx)
        goto loc_17e4a;
    bp = 0x6cbc;
    di = 0x3660;
loc_17e70:
    sub_181fa();
    ah &= 0x07;
    if (ax <= 0x06cb)
        goto loc_17e7e;
    ax -= 0x0134;
loc_17e7e:
    ax <<= 1;
    ax <<= 1;
    bx = ax;
loc_17e84:
    ax = memoryAGet16(es, bx + 20880);
    if (ax != 0xffff)
        goto loc_17e95;
    bx >>= 1;
    bl &= 0xfc;
    goto loc_17e84;
loc_17e95:
    memoryASet16(es, di, ax);
    dx = memoryAGet16(es, bx + 20882);
    memoryASet16(es, di + 2, dx);
    di += 0x0004;
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    memoryASet16(es, bx + 20880, ax);
    memoryASet16(es, bx + 20882, dx);
    memoryASet16(es, bp, 0xffff);
    bp -= 0x0004;
    if (di != 0x5190)
        goto loc_17e70;
}
void sub_17ec6()
{
    push(cx);
    bx = memoryAGet16(ds, 0x050a);
    cx = memoryAGet16(ds, 0x050c);
    sub_181fa();
    push(ax);
    ax &= bx;
    si += ax;
    si -= cx;
    ax = pop();
    memoryASet(ds, 0x026d, bl);
    bl = bh;
    bh = memoryAGet(ds, 0x026d);
    ax &= bx;
    ax >>= 1;
    si += ax;
    ax >>= 1;
    ax >>= 1;
    si += ax;
    memoryASet(ds, 0x026d, cl);
    cl = ch;
    ch = memoryAGet(ds, 0x026d);
    cx >>= 1;
    si -= cx;
    cx >>= 1;
    cx >>= 1;
    si -= cx;
    cx = pop();
}
void sub_17f06()
{
    sub_17f1e();
    if (memoryAGet(ds, 0x031f) == 0x01)
        return;
    memoryASet16(ds, 0x0319, ax);
    sub_17f44();
    bx = memoryAGet16(ds, 0x0319);
    sub_17f76();
}
void sub_17f1e()
{
    ah = 0x3d;
    al = 0x02;
    interrupt(0x21);
    if (flags.carry)
        goto loc_17f27;
    return;
loc_17f27:
    if (dx != 0x02ff)
        goto loc_17f33;
    memoryASet(ds, 0x031f, 0x01);
    return;
loc_17f33:
    ax = 0x0003;
    interrupt(0x10);
    dx = 0x320;
    ah = 0x09;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
}
void sub_17f44()
{
    ah = 0x42;
    al = 0x02;
    cx = 0x0000;
    dx = 0x0000;
    bx = memoryAGet16(ds, 0x0319);
    interrupt(0x21);
    memoryASet16(ds, 0x031d, ax);
    ah = 0x42;
    al = 0x00;
    dx = 0x0000;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x0319);
    cx = memoryAGet16(ds, 0x031d);
    dx = 0x0000;
    ah = 0x3f;
    push(ds);
    ds = memoryAGet16(ds, 0x026b);
    interrupt(0x21);
    ds = pop();
}
void sub_17f76()
{
    ah = 0x3e;
    interrupt(0x21);
}
void sub_17f7b()
{
    push(ds);
    ds = memoryAGet16(ds, 0x026b);
    es = ax;
    si = 0;
    di = 0;
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    ax = 0x0000;
    out(dx, ax);
    ax = 0x0f01;
    out(dx, ax);
    cx = 0x6d60;
    flags.direction = false;
    rep_stosb<MemAuto, DirAuto>();
    di = 0;
    ax = 0x0000;
    out(dx, ax);
    ax = 0x1003;
    out(dx, ax);
    ax = 0x0701;
    out(dx, ax);
    bh = 0x01;
    cx = 0x0050;
loc_17fb6:
    push(cx);
    cx = 0x015e;
loc_17fba:
    bh--;
    if (!(bh & 0x7f))
        goto loc_17fcc;
    if (bh & 0x80)
        goto loc_17fd2;
    bl = memoryAGet(ds, si);
    si++;
    goto loc_17fd2;
loc_17fcc:
    bh = memoryAGet(ds, si);
    si++;
    bl = memoryAGet(ds, si);
    si++;
loc_17fd2:
    al = memoryAGet(es, di);
    memoryASet(es, di, bl);
    di += 0x0050;
    if (--cx)
        goto loc_17fba;
    di -= 0x6d5f;
    cx = pop();
    if (--cx)
        goto loc_17fb6;
    di = 0x0000;
    bh = 0x01;
    ax = 0x1003;
    out(dx, ax);
    ax = 0x0b01;
    out(dx, ax);
    cx = 0x0050;
loc_17ff4:
    push(cx);
    cx = 0x015e;
loc_17ff8:
    bh--;
    if (!(bh & 0x7f))
        goto loc_1800a;
    if (bh & 0x80)
        goto loc_18010;
    bl = memoryAGet(ds, si);
    si++;
    goto loc_18010;
loc_1800a:
    bh = memoryAGet(ds, si);
    si++;
    bl = memoryAGet(ds, si);
    si++;
loc_18010:
    al = memoryAGet(es, di);
    memoryASet(es, di, bl);
    di += 0x0050;
    if (--cx)
        goto loc_17ff8;
    di -= 0x6d5f;
    cx = pop();
    if (--cx)
        goto loc_17ff4;
    di = 0x0000;
    bh = 0x01;
    ax = 0x1003;
    out(dx, ax);
    ax = 0x0d01;
    out(dx, ax);
    cx = 0x0050;
loc_18032:
    push(cx);
    cx = 0x015e;
loc_18036:
    bh--;
    if (!(bh & 0x7f))
        goto loc_18048;
    if (bh & 0x80)
        goto loc_1804e;
    bl = memoryAGet(ds, si);
    si++;
    goto loc_1804e;
loc_18048:
    bh = memoryAGet(ds, si);
    si++;
    bl = memoryAGet(ds, si);
    si++;
loc_1804e:
    al = memoryAGet(es, di);
    memoryASet(es, di, bl);
    di += 0x0050;
    if (--cx)
        goto loc_18036;
    di -= 0x6d5f;
    cx = pop();
    if (--cx)
        goto loc_18032;
    di = 0x0000;
    bh = 0x01;
    ax = 0x1003;
    out(dx, ax);
    ax = 0x0e01;
    out(dx, ax);
    cx = 0x0050;
loc_18070:
    push(cx);
    cx = 0x015e;
loc_18074:
    bh--;
    if (!(bh & 0x7f))
        goto loc_18086;
    if (bh & 0x80)
        goto loc_1808c;
    bl = memoryAGet(ds, si);
    si++;
    goto loc_1808c;
loc_18086:
    bh = memoryAGet(ds, si);
    si++;
    bl = memoryAGet(ds, si);
    si++;
loc_1808c:
    al = memoryAGet(es, di);
    memoryASet(es, di, bl);
    di += 0x0050;
    if (--cx)
        goto loc_18074;
    di -= 0x6d5f;
    cx = pop();
    if (--cx)
        goto loc_18070;
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    ds = pop();
}
void sub_180a7()
{
    ax = 0x0040;
    es = ax;
    dx = memoryBiosGet16(es, 0x0063);
    dl += 0x06;
    push(dx);
    flags.interrupts = false;
    in(al, dx);
    dl = 0xc0;
    bx = 0x0000;
loc_180bc:
    al = bl;
    out(dx, al);
    al = memoryAGet(ds, bx + si);
    out(dx, al);
    bl++;
    if (bl != 0x10)
        goto loc_180bc;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
}
void sub_180d2()
{
    memoryASet(ds, 0x0256, 0x00);
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_180f5;
    goto loc_180ff;
    //   gap of 22 bytes
loc_180f5:
    if (memoryAGet(ds, 0x0254) != 0x00)
        goto loc_1810a;
    ax = 0xffff;
loc_180ff:
    if (memoryAGet(ds, 0x1449) == 0x00)
        goto loc_18109;
    sub_15097();
loc_18109:
    return;
loc_1810a:
    push(bx);
    push(cx);
    push(dx);
    memoryASet(ds, 0x0256, 0x01);
    dx = 0x0201;
    in(al, dx);
    if (al & 0x10)
        goto loc_1811f;
    al = 0x0d;
    goto loc_1819f;
loc_1811f:
    if (al & 0x20)
        goto loc_18128;
    al = 0x1b;
    goto loc_1819f;
loc_18128:
    sub_1813a();
    push(ax);
    sub_1813a();
    bx = pop();
    if (ax == bx)
        goto loc_18137;
    ax = 0xffff;
loc_18137:
    goto loc_1819f;
    //   gap of 102 bytes
loc_1819f:
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_180e0()
{
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_180f5;
loc_180e6:
    ah = 0x00;
    interrupt(0x16);
    push(ax);
    ah = 0x01;
    interrupt(0x16);
    ax = pop();
    if (!flags.zero)
        goto loc_180e6;
    goto loc_180ff;
loc_180f5:
    if (memoryAGet(ds, 0x0254) != 0x00)
        goto loc_1810a;
    ax = 0xffff;
loc_180ff:
    if (memoryAGet(ds, 0x1449) == 0x00)
        goto loc_18109;
    sub_15097();
loc_18109:
    return;
loc_1810a:
    push(bx);
    push(cx);
    push(dx);
    memoryASet(ds, 0x0256, 0x01);
    dx = 0x0201;
    in(al, dx);
    if (al & 0x10)
        goto loc_1811f;
    al = 0x0d;
    goto loc_1819f;
loc_1811f:
    if (al & 0x20)
        goto loc_18128;
    al = 0x1b;
    goto loc_1819f;
loc_18128:
    sub_1813a();
    push(ax);
    sub_1813a();
    bx = pop();
    if (ax == bx)
        goto loc_18137;
    ax = 0xffff;
loc_18137:
    goto loc_1819f;
    //   gap of 102 bytes
loc_1819f:
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_1813a()
{
    ax = 0;
    ah++;
    sub_152b4();
    bx = cx;
    ah++;
    sub_152b4();
    if (bx >= memoryAGet16(ds, 0x0257))
        goto loc_18159;
    bx = -bx;
    bx += memoryAGet16(ds, 0x0257);
    dh = 0x02;
    goto loc_1815f;
loc_18159:
    bx -= memoryAGet16(ds, 0x0257);
    dh = 0x00;
loc_1815f:
    if (bx >= 0x0064)
        goto loc_18167;
    bx = 0x0000;
loc_18167:
    if (cx >= memoryAGet16(ds, 0x0259))
        goto loc_18178;
    cx = -cx;
    cx += memoryAGet16(ds, 0x0259);
    dl = 0x00;
    goto loc_1817e;
loc_18178:
    cx -= memoryAGet16(ds, 0x0259);
    dl = 0x08;
loc_1817e:
    if (cx >= 0x0064)
        goto loc_1818b;
    if (bx == 0x0000)
        goto loc_1819b;
    cx = 0x0000;
loc_1818b:
    al = 0x00;
    if (bx < cx)
        goto loc_18196;
    ah = 0x4d;
    ah -= dh;
    return;
loc_18196:
    ah = 0x48;
    ah += dl;
    return;
loc_1819b:
    ax = 0xffff;
}
void sub_181a3()
{
loc_181a3:
    sync();
    sub_180e0();
    if (ax != 0xffff)
        goto loc_181b0;
    memoryASet16(ds, 0x025f, ax);
    goto loc_181a3;
loc_181b0:
    if (memoryAGet(ds, 0x0256) == 0x00)
        return;
    if (ax == memoryAGet16(ds, 0x025f))
        goto loc_181a3;
    memoryASet16(ds, 0x025f, ax);
}
void sub_181c1()
{
    ah = 0x00;
    interrupt(0x1a);
    dx |= 0x0001;
    memoryASet16(ds, 0x111b, dx);
    if (memoryAGet(ds, 0x1449) != 0x01)
        return;
    memoryASet16(ds, 0x111b, 0x3039);
}
void sub_181fa()
{
    push(bx);
    push(dx);
    bx = memoryAGet16(ds, 0x111b);
    dx = bx;
    bx += bx;
    bx += bx;
    bx += dx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += dx;
    al = bh;
    dx = bx;
    bx += bx;
    bx += bx;
    bx += dx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += dx;
    memoryASet16(ds, 0x111b, bx);
    ah = bh;
    dx = pop();
    bx = pop();
}
void sub_1826d()
{
    push(bx);
    push(dx);
    ah = memoryAGet(ds, 0x111d);
    ah++;
    if ((char)ah < (char)0x64)
        goto loc_1827f;
    ah = 0x00;
    sub_181c1();
loc_1827f:
    memoryASet(ds, 0x111d, ah);
    ax = memoryAGet16(ds, 0x111b);
    bx = ax;
    ax += ax;
    ax += ax;
    ax += bx;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += bx;
    memoryASet16(ds, 0x111b, ax);
    dx = pop();
    bx = pop();
}
