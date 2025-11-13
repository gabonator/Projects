#include "cico16.h"

void fixReloc(uint16_t seg);
void sub_10205();

void init()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1fa0;
    cs = 0x1020;
    ds = 0x1010;
    es = 0x1010;
    ss = 0x1000;
    sp = 0x0200;
    load("fox.zip", "FOX.EXE", 84992);
    fixReloc(loadAddress);
}

void start()
{
    sub_10205();
}

int savedSp;
void saveSp()
{
    push(0xbebe);
    savedSp = sp;
}

bool dropsSp()
{
    if (savedSp == sp)
    {
        assert(pop() == 0xbebe);
        return false;
    }
    return true;
}

void sub_10205();
void sub_10358();
void sub_10373();
void sub_103d9();
void sub_103f8();
void sub_10444();
void sub_1047b();
void sub_10533();
void sub_1058a();
void sub_105ae();
void sub_105dc();
void sub_105f2();
void sub_10610();
void sub_10623();
void sub_10665();
void sub_10688();
void sub_1070e();
void sub_107b7();
void sub_107c7();
void sub_1085e();
void sub_10891();
void sub_108d4();
void sub_108ea();
void sub_10901();
void sub_109b0();
void sub_10a05();
void sub_10b7b();
void sub_10cbe();
void sub_10e1e();
void sub_10e30();
void sub_10eeb();
void sub_1127d();
void sub_112d3();
void sub_112ff();
void sub_11398();
void sub_113e6();
void sub_11469();
void sub_117a7();
void sub_117de();
void sub_11810();
void sub_1184f();
void sub_119eb();
void sub_119fe();
void sub_11a3f();
void sub_11aaf();
void sub_11b1c();
void sub_11b58();
void sub_11c2a();
void sub_11c59();
void sub_11c8d();
void sub_11d83();
void sub_11db6();
void sub_11e09();
void sub_11e1a();
void sub_11e30();
void sub_11e61();
void sub_126c9();
void sub_1296f();
void sub_129df();
void sub_12a11();
void sub_12acd();
void sub_12af8();
void sub_12b11();
void sub_12b4c();
void sub_12b94();
void sub_12bb5();
void sub_12c0d();
void sub_12cb1();
void sub_12d67();
void sub_12da2();
void sub_12e87();
void sub_12f62();
void sub_12fdc();
void sub_12fe8();
void sub_12ff5();
void sub_13053();
void sub_130b7();
void sub_13176();
void sub_131dd();
void sub_13209();
void sub_1327d();
void sub_13326();
void sub_13360();
void sub_13443();
void sub_13471();
void sub_134dc();
void sub_134f4();
void sub_13811();
void sub_13827();
void sub_1392f();
void sub_1398d();
void sub_139f5();
void sub_13ab5();
void sub_13bc7();
void sub_13f97();
void sub_14028();
void sub_140e8();
void sub_14146();
void sub_14174();
void sub_1423c();
void sub_142fa();
void sub_1434b();
void sub_14684();
void sub_14761();
void sub_14817();
void sub_14831();
void sub_14857();
void sub_14948();
void sub_1496c();
void sub_149b7();
void sub_149d3();
void sub_149fa();
void sub_14a07();
void sub_14a14();
void sub_14a21();
void sub_14a26();
void sub_14a33();
void sub_14acc();
void sub_14ad6();
void sub_14b5b();
void sub_14ce9();
void sub_14d49();
void sub_14d7d();
void sub_14db6();
void sub_14dd0();
void sub_14de8();
void sub_14e12();
void sub_14e2a();
void sub_14e65();
void sub_14ea2();
void sub_14ea8();
void sub_14ed8();
void sub_14ef0();
void sub_14ef6();
void sub_14f0b();
void sub_14f0c();
void sub_14f10();
void sub_14f9a();
void sub_14fb1();
void sub_14fc0();
void sub_14fc9();
void sub_14ff9();
void sub_14ffd();
void sub_15001();
void sub_15013();
void sub_1501c();
void sub_15025();
void sub_1502e();
void sub_15087();
void sub_15088();
void sub_15103();
void sub_1511f();
void sub_15245();
void sub_15295();
void sub_15322();
void sub_15333();
void sub_15353();
void sub_153c6();
void sub_15452();
void sub_154ec();
void sub_15538();
void sub_155a2();
void sub_155c8();
void sub_15677();
void sub_15757();
void sub_1582d();
void sub_15845();
void sub_158cc();
void sub_15937();
void sub_15ab0();
void sub_15ac8();
void sub_15b2d();
void sub_15b45();
void sub_15b6f();
void sub_15ba1();
void sub_15bcc();
void sub_15be7();
void sub_15c03();
void sub_15c04();
void sub_15cb8();
void sub_15d4e();
void sub_15dbb();
void sub_15e60();
void sub_15eca();
void sub_15fce();
void sub_160ca();
void sub_160e4();
void sub_160f2();
void sub_161f9();
void sub_161fe();
void sub_16209();
void sub_1620f();
void sub_162e0();
void sub_1641c();
void sub_1642e();
void sub_164c9();
void sub_165bf();
void sub_165c9();
void sub_165f1();
void sub_16696();
void sub_166df();
void sub_166ef();
void sub_166ff();
void sub_1675c();
void sub_16767();
void sub_16782();
void sub_167be();

void sub_10205() // 1020:0005 +entry
{
    flags.interrupts = 1;
    flags.direction = 0;
    dx = 0xffff;
    si = 0x0080;
    al = lodsb<DS_SI>();
    cbw();
    cx = ax;
    if (cx==0)
        goto loc_1024f;
loc_10213: // 1020:0013
    al = lodsb<DS_SI>();
    if (al == 0x2f)
        goto loc_1021c;
    if (--cx)
        goto loc_10213;
    goto loc_1024f;
loc_1021c: // 1020:001c
    al = lodsb<DS_SI>();
    al &= 0xdf;
    if (al != 0x56)
        goto loc_10225;
    dl = 0x05;
loc_10225: // 1020:0025
    if (al != 0x45)
        goto loc_1022b;
    dl = 0x03;
loc_1022b: // 1020:002b
    if (al != 0x54)
        goto loc_10231;
    dl = 0x02;
loc_10231: // 1020:0031
    if (al != 0x43)
        goto loc_10237;
    dl = 0x01;
loc_10237: // 1020:0037
    if (al != 0x48)
        goto loc_1023d;
    dl = 0x00;
loc_1023d: // 1020:003d
    if (al != 0x42)
        goto loc_10243;
    dh = 0x00;
loc_10243: // 1020:0043
    if (al != 0x46)
        goto loc_1024d;
    memoryASet(cs, 0x0003, 0x00);
loc_1024d: // 1020:004d
    if (--cx)
        goto loc_10213;
loc_1024f: // 1020:004f
    ax = 0x168f;
    ds = ax;
    memoryASet(cs, 0x0001, dl);
    memoryASet(cs, 0x0002, dh);
    ax = 0x8f01;
    cl = 0x04;
    ax >>= cl;
    ax += 0x1690;
    memoryASet16(ds, 0x04c1, ax);
    push(ds);
    ax = 0;
    ds = ax;
    memoryASet16(ds, 0x0090, 0x08d0);
    memoryASet16(ds, 0x0092, cs);
    ds = pop();
    sub_119fe();
    ax = 0x168f;
    ds = ax;
    ax = 0x168f;
    ds = ax;
    sub_1127d();
    sub_10eeb();
    sub_10901();
    sub_1327d();
    sub_13360();
    dx = 0x0000;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x000e, ax);
    sub_11a3f();
    sub_11398();
    ax = 0x4000;
    out8(0x40, al);
    al = ah;
    out8(0x40, al);
    sub_155a2();
    sub_154ec();
    sub_126c9();
    ax = memoryAGet16(ds, 0x04c1);
    memoryASet16(ds, 0x000c, ax);
loc_102c5: // 1020:00c5
    dx = memoryAGet16(ds, 0x000c);
    memoryASet16(ds, 0x04c1, dx);
    if (!ax)
        goto loc_102e9;
    sub_153c6();
    sub_13360();
    memoryASet(ds, 0x041b, 0x02);
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, 0x00);
    sub_10373();
loc_102e9: // 1020:00e9
    sub_13360();
    al = memoryAGet(ds, 0x5250);
    sub_130b7();
    sub_1398d();
    sub_158cc();
    ax = 0x168f;
    ds = ax;
    bl = memoryAGet(ds, 0x5250);
    bh = 0;
    al = memoryAGet(ds, bx + 20620);
    cbw();
    sub_112ff();
    sub_140e8();
    sub_12f62();
    sub_12e87();
    sub_13471();
loc_10317: // 1020:0117
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x64fe, memoryAGet16(ds, 0x64fe) + 1);
    sub_14028();
    sub_13bc7();
    sub_1434b();
    sub_15b45();
    sub_15ac8();
    sub_15937();
    sub_13ab5();
    sub_139f5();
    sub_14146();
    sub_12da2();
    sub_12e87();
    sub_11e61();
    sub_13827();
    if (!flags.carry)
        goto loc_1034c;
    goto loc_102c5;
loc_1034c: // 1020:014c
    sub_107b7();
    sub_10358();
    sub_13471();
    goto loc_10317;
}
void sub_10358() // 1020:0158
{
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(cs, 0x16e4) != 0x03)
        goto loc_10372;
    if (memoryAGet(ds, 0x09b2) != 0x00)
        goto loc_10372;
    ax = memoryAGet16(ds, 0x0913);
    sub_112ff();
loc_10372: // 1020:0172
    return;
}
void sub_10373() // 1020:0173
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    ax = 0x0000;
    sub_112ff();
    sub_12a11();
    sub_103f8();
    if (memoryAGet(ds, 0x041a) < 0x0a)
        goto loc_103c6;
    sub_105f2();
loc_10397: // 1020:0197
    if (memoryAGet(ds, 0x041a) < 0x0a)
        goto loc_103c6;
    dx = 0x000a;
loc_103a1: // 1020:01a1
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) - 1);
    push(dx);
    sub_10444();
    dx = pop();
    cx = 0x000f;
loc_103ad: // 1020:01ad
    sub_13443();
    if (--cx)
        goto loc_103ad;
    dx--;
    if (dx)
        goto loc_103a1;
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) + 1);
    sub_10444();
    cx = 0x000a;
loc_103bf: // 1020:01bf
    sub_13443();
    if (--cx)
        goto loc_103bf;
    goto loc_10397;
loc_103c6: // 1020:01c6
    sub_10444();
    sub_105f2();
    sub_105ae();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_103d9() // 1020:01d9
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    sub_12a11();
    sub_103f8();
    sub_105f2();
    sub_105ae();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_103f8() // 1020:01f8
{
    ax = 0x168f;
    ds = ax;
    sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000d);
    memoryASet16(ds, 0x01f7, 0x0960);
    sub_105dc();
    cl = memoryAGet(ds, 0x5250);
    ch = 0;
    si = 0x5104;
    if (cx==0)
        goto loc_10423;
loc_1041a: // 1020:021a
    al = lodsb<DS_SI>();
    if (al)
        goto loc_1041a;
    si++;
    if (--cx)
        goto loc_1041a;
    si--;
loc_10423: // 1020:0223
    bx = 0;
loc_10425: // 1020:0225
    bx++;
    if (memoryAGet(ds, bx + si) != 0x00)
        goto loc_10425;
    bx--;
    flags.carry = bx & 1;
    bx >>= 1;
    bl += 0x01 + flags.carry;
    memoryASet16(ds, 0x01f5, 0x0014);
    memoryASet16(ds, 0x01f7, 0x0be0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - bx);
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x12c0);
    si = 0x0010;
    sub_10688();
    dl = memoryAGet(ds, 0x041a);
    dh = 0;
    sub_10623();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x14a0);
    si = 0x001e;
    sub_10688();
    dl = memoryAGet(ds, 0x041b);
    dh = 0;
    sub_10623();
}
void sub_10444() // 1020:0244
{
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x12c0);
    si = 0x0010;
    sub_10688();
    dl = memoryAGet(ds, 0x041a);
    dh = 0;
    sub_10623();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x14a0);
    si = 0x001e;
    sub_10688();
    dl = memoryAGet(ds, 0x041b);
    dh = 0;
    sub_10623();
}
void sub_1047b() // 1020:027b +returnCarry
{
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    sub_13360();
    sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000e);
    memoryASet16(ds, 0x01f7, 0x0c80);
    si = 0x002c;
    sub_10688();
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x0004);
    dx = 0;
    cx = 0x0004;
loc_104aa: // 1020:02aa
    memoryASet(ds, 0x04c0, 0x00);
loc_104af: // 1020:02af
    bl = memoryAGet(ds, 0x04c0);
    if (bl & 0x80)
        goto loc_104aa;
    bh = 0;
    al = memoryAGet(ds, bx + 373);
    if (al == 0x2d)
        goto loc_104af;
    ah = al;
    ah -= 0x30;
    if (ah <= 0x09)
        goto loc_104cf;
    ah -= 0x07;
loc_104cf: // 1020:02cf
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dl |= ah;
    sub_1070e();
    if (--cx)
        goto loc_104aa;
    memoryASet16(ds, 0x01f5, 0x000b);
    memoryASet16(ds, 0x01f7, 0x1040);
    cx = 0;
loc_104ec: // 1020:02ec
    ax = cx;
    sub_16782();
    if (ax == dx)
        goto loc_10507;
    cx++;
    if (cx <= 0x0014)
        goto loc_104ec;
loc_104fb: // 1020:02fb
    si = 0x0037;
    sub_10688();
    sub_105f2();
    flags.carry = 1;
    goto loc_1052a;
loc_10507: // 1020:0307
    si = 0x0048;
    sub_10688();
    bx = cx;
    dl = memoryAGet(ds, bx + 21052);
    dh = 0;
    if (dl != 0xff)
        goto loc_10521;
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x0009);
    goto loc_104fb;
loc_10521: // 1020:0321
    push(bx);
    sub_10623();
    sub_105f2();
    ax = pop();
    flags.carry = 0;
loc_1052a: // 1020:032a
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_10533() // 1020:0333
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    sub_12a11();
    sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000d);
    memoryASet16(ds, 0x01f7, 0x1040);
    sub_105dc();
    memoryASet16(ds, 0x01f5, 0x000e);
    memoryASet16(ds, 0x01f7, 0x0c80);
    si = 0x0052;
    sub_10688();
    al = memoryAGet(ds, 0x5250);
    cbw();
    sub_16782();
    dx = ax;
    sub_10665();
    sub_105f2();
    sub_13443();
    sub_105ae();
    sub_1296f();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1058a() // 1020:038a
{
    ax = 0x168f;
    ds = ax;
    es = ax;
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_1059e;
    if (al >= 0x03)
        goto loc_105a5;
    return;
loc_1059e: // 1020:039e
    dx = 0x04c4;
    sub_10610();
    return;
loc_105a5: // 1020:03a5
    dx = 0x04f4;
    ax = 0x1002;
    interrupt(0x10);
}
void sub_105ae() // 1020:03ae
{
    ax = 0x168f;
    ds = ax;
    es = ax;
    sub_129df();
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_105c5;
    if (al >= 0x03)
        goto loc_105d3;
    return;
loc_105c5: // 1020:03c5
    ax = 0x1012;
    bx = 0;
    cx = 0x0010;
    dx = 0x5057;
    interrupt(0x10);
    return;
loc_105d3: // 1020:03d3
    dx = 0x5035;
    ax = 0x1002;
    interrupt(0x10);
}
void sub_105dc() // 1020:03dc
{
    si = 0x0059;
    sub_10688();
    bl = memoryAGet(ds, 0x5250);
    bh = 0;
    dl = memoryAGet(ds, bx + 21052);
    dh = 0;
    sub_10623();
}
void sub_105f2() // 1020:03f2
{
    ax = 0x168f;
    ds = ax;
loc_105f7: // 1020:03f7
    sync();
    sub_10a05();
    al = memoryAGet(ds, 0x047e);
    al |= memoryAGet(ds, 0x042b);
    if (!al)
        goto loc_105f7;
loc_10603: // 1020:0403
    sync();
    sub_10a05();
    al = memoryAGet(ds, 0x042b);
    al |= memoryAGet(ds, 0x047e);
    if (al)
        goto loc_10603;
}
void sub_10610() // 1020:0410
{
    al = memoryAGet(cs, 0x0001);
    if (al != 0x05)
        goto loc_10622;
    ax = 0x1012;
    bx = 0;
    cx = 0x0010;
    interrupt(0x10);
loc_10622: // 1020:0422
    return;
}
void sub_10623() // 1020:0423
{
    memoryASet(ds, 0x0418, 0x00);
    bx = 0x2710;
loc_1062b: // 1020:042b
    al = 0x30;
loc_1062d: // 1020:042d
    if (dx < bx)
        goto loc_10637;
    dx -= bx;
    al++;
    goto loc_1062d;
loc_10637: // 1020:0437
    if (al != 0x30)
        goto loc_1064b;
    if (bx == 0x0001)
        goto loc_1064b;
    if (memoryAGet(ds, 0x0418) != 0x00)
        goto loc_1064b;
    al = 0x20;
    goto loc_10650;
loc_1064b: // 1020:044b
    memoryASet(ds, 0x0418, 0x01);
loc_10650: // 1020:0450
    sub_1070e();
    ax = bx;
    push(dx);
    dx = 0;
    bx = 0x000a;
    div16(bx);
    dx = pop();
    bx = ax;
    if (bx)
        goto loc_1062b;
}
void sub_10665() // 1020:0465
{
    cx = 0x0004;
loc_10668: // 1020:0468
    ax = 0;
    flags.carry = !!(dx & 0x8000);
    dx <<= 1;
    ax = rcl16(ax, 0x0001);
    flags.carry = !!(dx & 0x8000);
    dx <<= 1;
    ax = rcl16(ax, 0x0001);
    flags.carry = !!(dx & 0x8000);
    dx <<= 1;
    ax = rcl16(ax, 0x0001);
    flags.carry = !!(dx & 0x8000);
    dx <<= 1;
    ax = rcl16(ax, 0x0001);
    if (al <= 0x09)
        goto loc_10680;
    al += 0x07;
loc_10680: // 1020:0480
    al += 0x30;
    sub_1070e();
    if (--cx)
        goto loc_10668;
}
void sub_10688() // 1020:0488
{
    push(ax);
loc_10689: // 1020:0489
    al = lodsb<DS_SI>();
    if (!al)
        goto loc_10693;
    sub_1070e();
    goto loc_10689;
loc_10693: // 1020:0493
    ax = pop();
}
void sub_1070e() // 1020:050e
{
    goto loc_1070e;
loc_10695: // 1020:0495
    dl = al;
    if (memoryAGet(ds, 0x043b) != 0x00)
        goto loc_106bd;
    memoryASet(ds, 0x043b, memoryAGet(ds, 0x043b) + 1);
    memoryASet16(cs, 0x6676, 0x0597);
    ds = memoryAGet16(ds, 0x000e);
    si = 0;
    cx = 0x0029;
loc_106b2: // 1020:04b2
    ax = 0x010c;
    sub_167be();
    si += 0x0030;
    if (--cx)
        goto loc_106b2;
loc_106bd: // 1020:04bd
    ax = 0x168f;
    ds = ax;
    di = memoryAGet16(ds, 0x01f5);
    di <<= 1;
    di += memoryAGet16(ds, 0x01f7);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) + 1);
    ax = 0xb800;
    es = ax;
    cx = 0x0006;
    al = dl;
    if (al != 0x20)
        goto loc_106ee;
    ax = 0;
loc_106e0: // 1020:04e0
    stosw<ES_DI>(ax);
    di += 0x1ffe;
    stosw<ES_DI>(ax);
    di -= 0x1fb2;
    if (--cx)
        goto loc_106e0;
    goto loc_1070c;
loc_106ee: // 1020:04ee
    al -= 0x30;
    if (al <= 0x09)
        goto loc_106f6;
    al -= 0x02;
loc_106f6: // 1020:04f6
    ds = memoryAGet16(ds, 0x000e);
    ah = 0x30;
    mul8(ah);
    si = ax;
loc_10700: // 1020:0500
    movsw<ES_DI, DS_SI>();
    di += 0x1ffe;
    movsw<ES_DI, DS_SI>();
    di -= 0x1fb2;
    if (--cx)
        goto loc_10700;
loc_1070c: // 1020:050c
    goto loc_1078d;
loc_1070e: // 1020:050e
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_10722;
    goto loc_10695;
loc_10722: // 1020:0522
    di = memoryAGet16(ds, 0x01f7);
    di += memoryAGet16(ds, 0x01f5);
    di += memoryAGet16(ds, 0x5268);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) + 1);
    if (al != 0x20)
        goto loc_10756;
    ax = 0xa000;
    es = ax;
    sub_134dc();
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    al = 0;
    cx = 0x000c;
loc_1074a: // 1020:054a
    stosb<ES_DI>(al);
    di += 0x0027;
    if (--cx)
        goto loc_1074a;
    di -= 0x01e0;
    goto loc_1078d;
loc_10756: // 1020:0556
    al -= 0x30;
    if (al <= 0x09)
        goto loc_1075e;
    al -= 0x02;
loc_1075e: // 1020:055e
    ds = memoryAGet16(ds, 0x000e);
    ah = 0x30;
    mul8(ah);
    si = ax;
    ax = 0xa000;
    es = ax;
    sub_134dc();
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx++;
    al = 0x01;
loc_10779: // 1020:0579
    out8(dx, al);
    cx = 0x000c;
loc_1077d: // 1020:057d
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    if (--cx)
        goto loc_1077d;
    di -= 0x01e0;
    al <<= 1;
    if (al <= 0x08)
        goto loc_10779;
loc_1078d: // 1020:058d
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_107b7() // 1020:05b7
{
    flags.carry = memoryAGet(ds, 0x6506) < 0x01;
    memoryASet(ds, 0x6506, memoryAGet(ds, 0x6506) - 0x01);
    memoryASet(ds, 0x6506, memoryAGet(ds, 0x6506) + (0x00 + flags.carry));
    if (!memoryAGet(ds, 0x6506))
        goto loc_107c6;
    sub_107c7();
loc_107c6: // 1020:05c6
    return;
}
void sub_107c7() // 1020:05c7
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_10836;
    si = memoryAGet16(ds, 0x526a);
    si += 0x0174;
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dl = 0xce;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0003;
    out16(dx, ax);
    ax = 0x0100;
    out16(dx, ax);
    ax = 0x0f01;
    out16(dx, ax);
    ax = 0xf008;
    out16(dx, ax);
    cl = memoryAGet(ds, 0x0419);
    bl = cl;
    ch = 0;
    ax = 0xa000;
    ds = ax;
    bp = 0x0028;
    if (cx==0)
        goto loc_10819;
loc_10814: // 1020:0614
    sub_10891();
    if (--cx)
        goto loc_10814;
loc_10819: // 1020:0619
    cl = 0x10;
    cl -= bl;
    if (!cl)
        goto loc_10824;
loc_1081f: // 1020:061f
    sub_108ea();
    if (--cx)
        goto loc_1081f;
loc_10824: // 1020:0624
    ax = 0x0001;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
loc_1082c: // 1020:062c
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_10836: // 1020:0636
    bp = 0x004f;
    di = 0x02e8;
    es = memoryAGet16(ds, 0x5262);
    al = 0xff;
    cl = memoryAGet(ds, 0x0419);
    ch = 0;
    if (cx==0)
        goto loc_1084f;
loc_1084a: // 1020:064a
    sub_1085e();
    if (--cx)
        goto loc_1084a;
loc_1084f: // 1020:064f
    cl = 0x10;
    cl -= memoryAGet(ds, 0x0419);
    if (cx==0)
        goto loc_1082c;
loc_10857: // 1020:0657
    sub_108d4();
    if (--cx)
        goto loc_10857;
    goto loc_1082c;
}
void sub_1085e() // 1020:065e
{
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di -= 0x04af;
}
void sub_10891() // 1020:0691
{
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si -= 0x0257;
}
void sub_108d4() // 1020:06d4
{
    di += 0x01e0;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di += bp;
    stosb<ES_DI>(al);
    di -= 0x031f;
}
void sub_108ea() // 1020:06ea
{
    si += 0x00f0;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si += bp;
    memoryASet(ds, si, memoryAGet(ds, si) + al);
    si -= 0x0167;
}
void sub_10901() // 1020:0701
{
    ax = 0x168f;
    ds = ax;
    memoryASet(ds, 0x0428, 0x03);
loc_1090b: // 1020:070b
    memoryASet(ds, 0x041c, 0x00);
    memoryASet16(ds, 0x041d, 0x0320);
    dx = 0x0201;
    cx = 0x0c80;
    ah = 0x03;
    flags.interrupts = 0;
loc_1091f: // 1020:071f
    al = in8(dx);
    if (!(al & 0x03))
        goto loc_10927;
    ah &= 0x02;
loc_10927: // 1020:0727
    if (!(al & 0x0c))
        goto loc_1092e;
    ah &= 0x01;
loc_1092e: // 1020:072e
    if (--cx)
        goto loc_1091f;
    al = 0xff;
    if (!(ah & 0x02))
        goto loc_1093a;
    al = memoryAGet(ds, 0x042a);
loc_1093a: // 1020:073a
    if (!(ah & 0x01))
        goto loc_10942;
    al = memoryAGet(ds, 0x0429);
loc_10942: // 1020:0742
    memoryASet(ds, 0x0427, al);
    sub_109b0();
    if (flags.carry)
        goto loc_10996;
    if (ax >= 0x0320)
        goto loc_10996;
    if (bx >= 0x0320)
        goto loc_10996;
    if (!ax)
        goto loc_10996;
    if (!bx)
        goto loc_10996;
    cl = 0x02;
    bp = ax;
    ax >>= cl;
    ax -= bp;
    ax = -ax;
    memoryASet16(ds, 0x041f, ax);
    ax = bp;
    ax >>= cl;
    ax += bp;
    memoryASet16(ds, 0x0425, ax);
    bp = bx;
    bx >>= cl;
    bx -= bp;
    bx = -bx;
    memoryASet16(ds, 0x0421, bx);
    bx = bp;
    bx >>= cl;
    bx += bp;
    memoryASet16(ds, 0x0423, bx);
    if (ax >= bx)
        goto loc_1098f;
    ax = bx;
loc_1098f: // 1020:078f
    ax <<= 1;
    memoryASet16(ds, 0x041d, ax);
    goto loc_109ae;
loc_10996: // 1020:0796
    memoryASet(ds, 0x0428, memoryAGet(ds, 0x0428) - 1);
    if (!memoryAGet(ds, 0x0428))
        goto loc_109a9;
    al = memoryAGet(ds, 0x0429);
    tl = memoryAGet(ds, 0x042a); memoryASet(ds, 0x042a, al); al = tl;
    memoryASet(ds, 0x0429, al);
    goto loc_1090b;
loc_109a9: // 1020:07a9
    memoryASet(ds, 0x0427, 0xff);
loc_109ae: // 1020:07ae
    flags.interrupts = 1;
}
void sub_109b0() // 1020:07b0 +returnCarry
{
    cl = memoryAGet(ds, 0x0427);
    if ((char)cl < 0)
        goto loc_10a02;
    if (memoryAGet(ds, 0x041c) != 0x00)
        goto loc_10a02;
    dx = 0x0201;
    al = in8(dx);
    al >>= cl;
    if (al & 0x03)
        goto loc_10a02;
    al ^= 0x30;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    bp = 0;
    di = 0;
    bx = 0;
    flags.carry = al & 1;
    al >>= 1;
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) - bh - flags.carry);
    flags.carry = al & 1;
    al >>= 1;
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) - bh - flags.carry);
    si = memoryAGet16(ds, 0x041d);
    flags.interrupts = 0;
    out8(dx, al);
loc_109eb: // 1020:07eb
    al = in8(dx);
    al >>= cl;
    if (!(al & 0x03))
        goto loc_109fd;
    flags.carry = al & 1;
    al >>= 1;
    di += bp + flags.carry;
    flags.carry = al & 1;
    al >>= 1;
    bx += bp + flags.carry;
    si--;
    if (si)
        goto loc_109eb;
loc_109fd: // 1020:07fd
    ax = di;
    flags.interrupts = 1;
    flags.carry = 0;
    return;
loc_10a02: // 1020:0802
    flags.interrupts = 1;
    flags.carry = 1;
}
void sub_10a05() // 1020:0805
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    ax = 0;
    memoryASet(ds, 0x042d, al);
    memoryASet(ds, 0x042e, al);
    memoryASet(ds, 0x042f, al);
    memoryASet(ds, 0x0430, al);
    memoryASet(ds, 0x042b, al);
    memoryASet(ds, 0x042c, al);
    sub_109b0();
    if (flags.carry)
        goto loc_10a5c;
    if (ax > memoryAGet16(ds, 0x041f))
        goto loc_10a39;
    memoryASet(ds, 0x0430, 0xff);
    goto loc_10a44;
loc_10a39: // 1020:0839
    if (ax < memoryAGet16(ds, 0x0425))
        goto loc_10a44;
    memoryASet(ds, 0x042f, 0xff);
loc_10a44: // 1020:0844
    if (bx > memoryAGet16(ds, 0x0421))
        goto loc_10a51;
    memoryASet(ds, 0x042d, 0xff);
    goto loc_10a5c;
loc_10a51: // 1020:0851
    if (bx < memoryAGet16(ds, 0x0423))
        goto loc_10a5c;
    memoryASet(ds, 0x042e, 0xff);
loc_10a5c: // 1020:085c
    al = memoryAGet(ds, 0x0488);
    al |= memoryAGet(ds, 0x04bc);
    al |= memoryAGet(ds, 0x0469);
    al |= memoryAGet(ds, 0x0450);
    memoryASet(ds, 0x042d, memoryAGet(ds, 0x042d) | al);
    al = memoryAGet(ds, 0x0490);
    al |= memoryAGet(ds, 0x04bb);
    al |= memoryAGet(ds, 0x048a);
    al |= memoryAGet(ds, 0x045e);
    memoryASet(ds, 0x042e, memoryAGet(ds, 0x042e) | al);
    al = memoryAGet(ds, 0x048d);
    al |= memoryAGet(ds, 0x04b9);
    al |= memoryAGet(ds, 0x048e);
    al |= memoryAGet(ds, 0x0467);
    memoryASet(ds, 0x042f, memoryAGet(ds, 0x042f) | al);
    al = memoryAGet(ds, 0x048b);
    al |= memoryAGet(ds, 0x04ba);
    al |= memoryAGet(ds, 0x046b);
    al |= memoryAGet(ds, 0x0466);
    memoryASet(ds, 0x0430, memoryAGet(ds, 0x0430) | al);
    al = memoryAGet(ds, 0x045c);
    al |= memoryAGet(ds, 0x0479);
    al |= memoryAGet(ds, 0x04b4);
    al |= memoryAGet(ds, 0x0497);
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) | al);
    al = memoryAGet(ds, 0x0459);
    al |= memoryAGet(ds, 0x0484);
    memoryASet(ds, 0x042c, memoryAGet(ds, 0x042c) | al);
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_10b7b() // 1020:097b
{
    goto loc_10b7b;
loc_10aea: // 1020:08ea
    ax = 0x168f;
    ds = ax;
    ax = 0x0003;
    interrupt(0x10);
    ah = 0x09;
    dx = 0x0077;
    interrupt(0x21);
    goto loc_10b6c;
loc_10afd: // 1020:08fd
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x168f;
    ds = ax;
    ah = 0x09;
    dx = 0x008a;
    interrupt(0x21);
    goto loc_10b6c;
loc_10b10: // 1020:0910
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    ax = 0x0003;
    interrupt(0x10);
    di = dx;
    push(dx);
    if (memoryAGet(ds, 0x0417) == 0x00)
        goto loc_10b2d;
    ah = 0x09;
    dx = 0x009e;
    interrupt(0x21);
    goto loc_10b34;
loc_10b2d: // 1020:092d
    ah = 0x09;
    dx = 0x00b1;
    interrupt(0x21);
loc_10b34: // 1020:0934
    cx = 0x005a;
    ax = 0;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    memoryASet(ds, di, 0x24);
    dx = pop();
    ah = 0x09;
    interrupt(0x21);
    if (memoryAGet(ds, 0x0417) == 0x01)
        goto loc_10b6c;
    memoryASet(ds, 0x04c3, 0x00);
    ah = 0x09;
    dx = 0x00d5;
    interrupt(0x21);
    memoryASet(ds, 0x04c0, 0x00);
loc_10b5b: // 1020:095b
    al = memoryAGet(ds, 0x04c0);
    if (al != 0x1c)
        goto loc_10b5b;
    sub_13360();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    goto loc_10b7b;
loc_10b6c: // 1020:096c
    ah = 0x09;
    dx = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
loc_10b79: // 1020:0979
    goto loc_10b79;
loc_10b7b: // 1020:097b
    ax = 0x168f;
    ds = ax;
    es = ax;
    memoryASet(cs, 0x6bb3, 0x01);
    ax = 0x3d00;
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, 0x00);
    if (!flags.carry)
        goto loc_10b98;
    goto loc_10b10;
loc_10b98: // 1020:0998
    memoryASet16(cs, 0x0af2, ax);
    ax = memoryAGet16(ds, 0x04c1);
    memoryASet16(cs, 0x0af4, ax);
    ds = ax;
    memoryASet(cs, 0x6bb3, 0x01);
    bx = memoryAGet16(cs, 0x0af2);
    cx = 0x0006;
    dx = 0x041a;
    ah = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10bbf;
    goto loc_10afd;
loc_10bbf: // 1020:09bf
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    si = dx;
    ax = lodsw<DS_SI>();
    if (ah != 0x10)
        goto loc_10bcf;
    goto loc_10cf6;
loc_10bcf: // 1020:09cf
    bx = ax;
    ax = lodsw<DS_SI>();
    cx = 0x0004;
loc_10bd5: // 1020:09d5
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    if (--cx)
        goto loc_10bd5;
    ax++;
    cx = memoryAGet16(ds, si);
    ax += memoryAGet16(es, 0x04c1);
    memoryASet16(es, 0x04c1, ax);
    ds = ax;
    ax = memoryAGet16(cs, 0x0af4);
    es = ax;
    memoryASet(cs, 0x6bb3, 0x01);
    bx = memoryAGet16(cs, 0x0af2);
    cx = cx;
    dx = 0x0006;
    ah = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10c08;
    goto loc_10afd;
loc_10c08: // 1020:0a08
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    dl = 0x01;
    memoryASet16(ds, 0x0000, 0x0002);
    di = 0;
loc_10c17: // 1020:0a17
    bx = 0;
    saveSp();
    sub_10cbe();
    if (dropsSp())
        return;
    if (!bh)
        goto loc_10c66;
    if (bl < 0x02)
        goto loc_10c35;
    cl = bl;
    ch = 0;
    bp = ax;
    al = memoryAGet(es, di + 65535);
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ax = bp;
    goto loc_10c6a;
loc_10c35: // 1020:0a35
    if (bl)
        goto loc_10c4c;
    bx = 0;
    sub_10cbe();
    bp = ax;
    cx = bx;
    al = memoryAGet(es, di + 65535);
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ax = bp;
    goto loc_10c6a;
loc_10c4c: // 1020:0a4c
    bx = 0;
    saveSp();
    sub_10cbe();
    if (dropsSp())
        return;
    ch = bl;
    bx = 0;
    saveSp();
    sub_10cbe();
    if (dropsSp())
        return;
    cl = bl;
    bp = ax;
    al = memoryAGet(es, di + 65535);
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ax = bp;
    goto loc_10c6a;
loc_10c66: // 1020:0a66
    memoryASet(es, di, bl);
    di++;
loc_10c6a: // 1020:0a6a
    if (di < 0x4000)
        goto loc_10c17;
    bx = es;
    bx += 0x03ff;
    es = bx;
    di -= 0x3ff0;
    goto loc_10c6a;
    // gap 120 bytes
loc_10cf6: // 1020:0af6
    dx = 0;
    cx = 0;
    ax = 0x4200;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, 0x00);
    ax = 0x168f;
    es = ax;
    ax = memoryAGet16(cs, 0x0af4);
    ds = ax;
    cx = 0x0004;
    dx = 0x000e;
    bx = memoryAGet16(cs, 0x0af2);
    ah = 0x3f;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10d30;
    goto loc_10afd;
loc_10d30: // 1020:0b30
    memoryASet(cs, 0x6bb3, 0x00);
    al = memoryAGet(ds, 0x000f);
    al &= 0xf0;
    if (al == 0x10)
        goto loc_10d42;
    goto loc_10aea;
loc_10d42: // 1020:0b42
    di = 0;
    bx = memoryAGet16(ds, 0x000e);
    ax = memoryAGet16(ds, 0x0010);
    cx = 0x0004;
loc_10d4e: // 1020:0b4e
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    if (--cx)
        goto loc_10d4e;
    ax++;
    ax += memoryAGet16(es, 0x04c1);
    memoryASet16(es, 0x04c1, ax);
    ds = ax;
    ax = memoryAGet16(cs, 0x0af4);
    es = ax;
    memoryASet16(ds, 0x0000, di);
    memoryASet16(ds, 0x0002, di);
loc_10d6e: // 1020:0b6e
    sub_10e1e();
    sub_10e30();
    flags.zero = ax == 0x0101;
    if (flags.zero)
        goto loc_10d8b;
    memoryASet16(ds, 0x0005, ax);
    memoryASet(ds, 0x0004, al);
    stosb<ES_DI>(al);
loc_10d80: // 1020:0b80
    sub_10e30();
    if (ax == 0x0100)
        goto loc_10d6e;
    flags.zero = ax == 0x0101;
loc_10d8b: // 1020:0b8b
    if (flags.zero)
        goto loc_10e02;
    memoryASet16(ds, 0x0007, ax);
    si = 0x4010;
    if (memoryAGet16(ds, 0x000c) > ax)
        goto loc_10da3;
    dl = memoryAGet(ds, 0x0004);
    memoryASet(ds, si, dl);
    si++;
    ax = memoryAGet16(ds, 0x0005);
loc_10da3: // 1020:0ba3
    if (!ah)
        goto loc_10db8;
    bx = ax;
    dl = memoryAGet(ds, bx + 4112);
    memoryASet(ds, si, dl);
    si++;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 8208);
    goto loc_10da3;
loc_10db8: // 1020:0bb8
    memoryASet(ds, si, al);
    si++;
    memoryASet(ds, 0x0004, al);
loc_10dbe: // 1020:0bbe
    si--;
    al = memoryAGet(ds, si);
    stosb<ES_DI>(al);
    if (di < 0x8000)
        goto loc_10dd3;
    ax = es;
    ax += 0x0800;
    es = ax;
    di -= 0x8000;
loc_10dd3: // 1020:0bd3
    if (si != 0x4010)
        goto loc_10dbe;
    bx = memoryAGet16(ds, 0x000c);
    if (bx >= 0x1000)
        goto loc_10df9;
    dl = memoryAGet(ds, 0x0004);
    memoryASet(ds, bx + 4112, dl);
    dx = memoryAGet16(ds, 0x0005);
    bx <<= 1;
    memoryASet16(ds, bx + 8208, dx);
    memoryASet16(ds, 0x000c, memoryAGet16(ds, 0x000c) + 1);
loc_10df9: // 1020:0bf9
    ax = memoryAGet16(ds, 0x0007);
    memoryASet16(ds, 0x0005, ax);
    goto loc_10d80;
loc_10e02: // 1020:0c02
    memoryASet(ds, 0x04c3, 0x01);
    bx = memoryAGet16(cs, 0x0af2);
    ah = 0x3e;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, memoryAGet(ds, 0x04c3) - 1);
    ax = 0x168f;
    ds = ax;
    ax = memoryAGet16(cs, 0x0af4);
}
void sub_10cbe() // 1020:0abe
{
    goto loc_10cbe;
loc_10afd: // 1020:08fd
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x168f;
    ds = ax;
    ah = 0x09;
    dx = 0x008a;
    interrupt(0x21);
    goto loc_10b6c;
    // gap 92 bytes
loc_10b6c: // 1020:096c
    ah = 0x09;
    dx = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
loc_10b79: // 1020:0979
    goto loc_10b79;
    // gap 259 bytes
loc_10c7e: // 1020:0a7e
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) - 0x0002);
    if (memoryAGet16(ds, 0x0000))
        goto loc_10cb9;
    push(bx);
    push(di);
    memoryASet(cs, 0x6bb3, 0x01);
    bx = memoryAGet16(cs, 0x0af2);
    cx = 0x1000;
    dx = 0x041a;
    ah = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10ca1;
    goto loc_10afd;
loc_10ca1: // 1020:0aa1
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    memoryASet16(ds, 0x0000, ax);
    di = pop();
    bx = pop();
    if (!ax)
        goto loc_10cd3;
    flags.carry = ax & 1;
    ax >>= 1;
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) + (0x0000 + flags.carry));
    si = 0x041a;
loc_10cb9: // 1020:0ab9
    ax = lodsw<DS_SI>();
    tl = ah; ah = al; al = tl;
    dl = 0x11;
loc_10cbe: // 1020:0abe
    dl--;
    if (!dl)
        goto loc_10c7e;
    flags.carry = !!(ax & 0x8000);
    ax = rol16(ax, 0x0001);
    if (!flags.carry)
        goto loc_10cc8;
    bx++;
    bx++;
loc_10cc8: // 1020:0ac8
    bx = memoryAGet16(ds, bx + 6);
    if ((char)bh >= 0)
        goto loc_10cbe;
    bh &= 0x7f;
    return;
loc_10cd3: // 1020:0ad3
    ax = pop();
//    stop("stack_below", "1020:0ad3");
    memoryASet(cs, 0x6bb3, 0x01);
    bx = memoryAGet16(cs, 0x0af2);
    ah = 0x3e;
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    ax = 0x168f;
    ds = ax;
    ax = memoryAGet16(cs, 0x0af4);
//    stop("stack_unbalanced");
}
void sub_10e1e() // 1020:0c1e
{
    memoryASet16(ds, 0x000a, 0x0200);
    memoryASet(ds, 0x0009, 0x09);
    memoryASet16(ds, 0x000c, 0x0102);
}
void sub_10e30() // 1020:0c30
{
    goto loc_10e30;
loc_10afd: // 1020:08fd
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x168f;
    ds = ax;
    ah = 0x09;
    dx = 0x008a;
    interrupt(0x21);
    goto loc_10b6c;
    // gap 92 bytes
loc_10b6c: // 1020:096c
    ah = 0x09;
    dx = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
loc_10b79: // 1020:0979
    goto loc_10b79;
    // gap 693 bytes
loc_10e30: // 1020:0c30
    ax = memoryAGet16(ds, 0x000c);
    if (memoryAGet16(ds, 0x000a) != ax)
        goto loc_10e48;
    if (memoryAGet(ds, 0x0009) == 0x0c)
        goto loc_10e48;
    memoryASet(ds, 0x0009, memoryAGet(ds, 0x0009) + 1);
    memoryASet16(ds, 0x000a, memoryAGet16(ds, 0x000a) << 1);
loc_10e48: // 1020:0c48
    bx = memoryAGet16(ds, 0x0002);
    si = bx;
    flags.carry = (bl + memoryAGet(ds, 0x0009)) >= 0x100;
    bl += memoryAGet(ds, 0x0009);
    bh += 0x00 + flags.carry;
    if (memoryAGet16(ds, 0x0000) >= bx)
        goto loc_10eaf;
    cx = 0x1000;
    dx = 0x0010;
    bx = 0x0010;
    bx -= memoryAGet16(ds, 0x0000);
    bx += memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, bx);
    si = bx;
    ax = memoryAGet16(ds, 0x100e);
    memoryASet16(ds, 0x000e, ax);
    bx = memoryAGet16(cs, 0x0af2);
    ah = 0x3f;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10e8c;
    goto loc_10afd;
loc_10e8c: // 1020:0c8c
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x0000, ax);
    push(di);
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    ax = es;
    ax += di;
    es = ax;
    di = pop();
    di &= 0x000f;
loc_10eaf: // 1020:0caf
    cx = si;
    si >>= 1;
    si >>= 1;
    si >>= 1;
    cl &= 0x07;
    ax = memoryAGet16(ds, si + 14);
    tl = ah; ah = al; al = tl;
    dh = 0;
    ax <<= cl;
    ch = 0x10;
    ch -= cl;
    flags.carry = ch < memoryAGet(ds, 0x0009);
    ch -= memoryAGet(ds, 0x0009);
    if (!flags.carry)
        goto loc_10ed8;
    ch = -ch;
    cl = 0x08;
    cl -= ch;
    dh = memoryAGet(ds, si + 16);
    dh >>= cl;
loc_10ed8: // 1020:0cd8
    bl = memoryAGet(ds, 0x0009);
    bh = 0;
    memoryASet16(ds, 0x0002, memoryAGet16(ds, 0x0002) + bx);
    cl = 0x10;
    cl -= bl;
    ax >>= cl;
    al |= dh;
}
void sub_10eeb() // 1020:0ceb
{
    push(ax);
    push(cx);
    push(di);
    push(si);
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    ax = 0;
    es = ax;
    si = 0x0433;
    di = 0x0020;
    cx = 0x0004;
    flags.interrupts = 0;
    flags.direction = 0;
loc_10f05: // 1020:0d05
    ax = memoryAGet16(es, di);
    tx = memoryAGet16(ds, si); memoryASet16(ds, si, ax); ax = tx;
    stosw<ES_DI>(ax);
    si++;
    si++;
    if (--cx)
        goto loc_10f05;
    push(ds);
    es = pop();
    di = 0x0440;
    ax = 0;
    cx = 0x0040;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    flags.interrupts = 1;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    cx = pop();
    ax = pop();
}
void sub_1127d() // 1020:107d
{
    flags.interrupts = 0;
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    ax = 0;
    es = ax;
    push(memoryAGet16(es, 0x0018));
    push(memoryAGet16(es, 0x001a));
    memoryASet16(es, 0x0018, 0x10bc);
    memoryASet16(es, 0x001a, cs);
    al = 0x01;
    cl = 0x20;
    al <<= cl;
    if (al == 0x01)
        goto loc_112b1;
    memoryASet(cs, 0x0004, 0x00);
    goto loc_112c5;
loc_112b1: // 1020:10b1
    ax = 0; //eax = 0;
    memoryASet(cs, 0x0004, 0x03);
    goto loc_112c5;
    // gap 9 bytes
loc_112c5: // 1020:10c5
    memoryASet16(es, 0x001a, pop());
    memoryASet16(es, 0x0018, pop());
    flags.interrupts = 1;
    es = pop();
    ds = pop();
}
void sub_112d3() // 1020:10d3
{
    ax = 0x168f;
    ds = ax;
    memoryASet(ds, 0x651a, 0x00);
loc_112dd: // 1020:10dd
    /*
    ax = memoryAGet16(ds, 0x0431);
    ax -= memoryAGet16(cs, 0x16e0);
    if ((short)ax >= 0)
        goto loc_112e9;
    ax = -ax;
loc_112e9: // 1020:10e9
    if (ax < 0x0002)
        goto loc_112dd;
    if (ax > 0x0002)
        goto loc_112f7;
    sub_13443();
    */
    memoryASet(ds, 0x651a, memoryAGet(ds, 0x651a) + 1);
loc_112f7: // 1020:10f7
    ax = memoryAGet16(cs, 0x16e0);
    memoryASet16(ds, 0x0431, ax);
}
void sub_112ff() // 1020:10ff
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    dx = 0x168f;
    ds = dx;
    es = dx;
    bx = ax;
    if (memoryAGet(ds, bx + 1285) == 0x01)
        goto loc_1131d;
    memoryASet16(ds, 0x0913, ax);
    goto loc_1131d;
loc_1131d: // 1020:111d
    memoryASet(cs, 0x16e4, memoryAGet(cs, 0x16e4) | 0x01);
    flags.interrupts = 0;
    if (memoryAGet(cs, 0x16e3) == 0x01)
        goto loc_11357;
    bx = ax;
    al = memoryAGet(ds, bx + 2466);
    memoryASet(ds, 0x0980, al);
    memoryASet(ds, 0x0981, al);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2434);
    memoryASet(cs, 0x70a2, 0x01);
    memoryASet16(ds, 0x0b07, ax);
    if (!(memoryAGet(cs, 0x16e4) & 0x02))
        goto loc_1138d;
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
    goto loc_1138d;
loc_11357: // 1020:1157
    sub_1184f();
    bx = 0x0515;
    cx = ax;
    if (cx==0)
        goto loc_1136b;
loc_11361: // 1020:1161
    bx++;
    bx++;
    if (memoryAGet16(ds, bx + 65534) != 0xffff)
        goto loc_11361;
    if (--cx)
        goto loc_11361;
loc_1136b: // 1020:116b
    cx = ax;
    ax = bx;
    bx = 0x0675;
    if (cx==0)
        goto loc_1137e;
loc_11374: // 1020:1174
    bx++;
    bx++;
    if (memoryAGet16(ds, bx + 65534) != 0xffff)
        goto loc_11374;
    if (--cx)
        goto loc_11374;
loc_1137e: // 1020:117e
    si = bx;
loc_11380: // 1020:1180
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_11380;
    cx = memoryAGet16(ds, si + 65534);
    sub_11469();
loc_1138d: // 1020:118d
    flags.interrupts = 1;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11398() // 1020:1198
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(cs, 0x0002) == 0x00)
        goto loc_113d2;
    ax = 0x2001;
    sub_117a7();
    sub_11810();
    if (flags.carry)
        goto loc_113d2;
    flags.interrupts = 0;
    ax = 0x0008;
    sub_117a7();
    ax = 0x00bd;
    sub_117a7();
    sub_1184f();
    memoryASet(cs, 0x16e3, 0x01);
    flags.interrupts = 1;
    goto loc_113dc;
loc_113d2: // 1020:11d2
    al = 0xb6;
    out8(0x43, al);
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
loc_113dc: // 1020:11dc
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_113e6() // 1020:11e6
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    bx = 0x168f;
    ds = bx;
    memoryASet16(ds, 0x0172, 0x000f);
    bl = al;
    bh = 0;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 342);
    memoryASet(ds, 0x0174, 0x01);
    flags.interrupts = 0;
    dl = 0x13;
    sub_117de();
    dl -= 0x03;
    bx += 0x0005;
    sub_117de();
    ah = memoryAGet(ds, bx + 5);
    al = 0xc6;
    sub_117a7();
    flags.interrupts = 1;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11469() // 1020:1269
{
    push(ax);
    push(cx);
    push(si);
    push(di);
    memoryASet(cs, 0x16e2, 0x00);
    memoryASet(ds, 0x0981, cl);
    memoryASet(ds, 0x0980, cl);
    memoryASet16(ds, 0x0917, bx);
    di = 0x09b3;
    si = ax;
    ax = 0;
    dx = 0;
    memoryASet(ds, 0x09b2, 0xff);
loc_1148d: // 1020:128d
    cx = 0x0011;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(ds, 0x09b2, memoryAGet(ds, 0x09b2) + 1);
    memoryASet16(ds, di + 65532, cx);
    memoryASet(ds, di + 65524, dl);
    dx++;
    if (cx != 0xffff)
        goto loc_1148d;
    di = pop();
    si = pop();
    cx = pop();
    ax = pop();
}
void sub_117a7() // 1020:15a7
{
    push(dx);
    push(ax);
    push(cx);
    if (memoryAGet(cs, 0x0004) >= 0x03)
        goto loc_117c8;
    dx = 0x0388;
    out8(dx, al);
    cx = 0x0005;
loc_117b9: // 1020:15b9
    if (--cx)
        goto loc_117b9;
    dx++;
    al = ah;
    out8(dx, al);
    cx = 0x0023;
loc_117c2: // 1020:15c2
    if (--cx)
        goto loc_117c2;
    cx = pop();
    ax = pop();
    dx = pop();
    return;
loc_117c8: // 1020:15c8
    dx = 0x0388;
    out8(dx, al);
    cx = 0x0014;
loc_117cf: // 1020:15cf
    if (--cx)
        goto loc_117cf;
    dx++;
    al = ah;
    out8(dx, al);
    cx = 0x008c;
loc_117d8: // 1020:15d8
    if (--cx)
        goto loc_117d8;
    cx = pop();
    ax = pop();
    dx = pop();
}
void sub_117de() // 1020:15de
{
    ah = memoryAGet(ds, bx);
    al = dl;
    al += 0x60;
    sub_117a7();
    ah = memoryAGet(ds, bx + 1);
    al = dl;
    al += 0x80;
    sub_117a7();
    ah = memoryAGet(ds, bx + 2);
    al = dl;
    al += 0x40;
    sub_117a7();
    ah = memoryAGet(ds, bx + 3);
    al = dl;
    al += 0x20;
    sub_117a7();
    ah = memoryAGet(ds, bx + 4);
    al = dl;
    al += 0xe0;
    sub_117a7();
}
void sub_11810() // 1020:1610 +returnCarry
{
    ax = 0x6304;
    sub_117a7();
    dx = 0x0388;
    cx = 0x2000;
loc_1181c: // 1020:161c
    al = in8(dx);
    al &= 0x60;
    if (al)
        goto loc_1184d;
    if (--cx)
        goto loc_1181c;
    ax = 0x2304;
    sub_117a7();
    cx = 0x9fff;
loc_1182c: // 1020:162c
    al = in8(dx);
    al &= 0x60;
    if (al == 0x40)
        goto loc_11837;
    if (--cx)
        goto loc_1182c;
    goto loc_1184d;
loc_11837: // 1020:1637
    ax = 0x4304;
    sub_117a7();
    cx = 0x9fff;
loc_11840: // 1020:1640
    al = in8(dx);
    al &= 0x60;
    if (al == 0x20)
        goto loc_1184b;
    if (--cx)
        goto loc_11840;
    goto loc_1184d;
loc_1184b: // 1020:164b
    flags.carry = 0;
    return;
loc_1184d: // 1020:164d
    flags.carry = 1;
}
void sub_1184f() // 1020:164f
{
    push(ax);
    ax = 0x00b0;
loc_11853: // 1020:1653
    sub_117a7();
    ax++;
    if (al < 0xb9)
        goto loc_11853;
    ax = 0x00a0;
loc_1185e: // 1020:165e
    sub_117a7();
    ax++;
    if (al < 0xb9)
        goto loc_1185e;
    ax = 0x0008;
    sub_117a7();
    ax = 0x00bd;
    sub_117a7();
    ax = 0x3f40;
    sub_117a7();
    ax = 0x3f41;
    sub_117a7();
    ax = 0x3f42;
    sub_117a7();
    ax = 0x3f43;
    sub_117a7();
    ax = 0x3f44;
    sub_117a7();
    ax = 0x3f45;
    sub_117a7();
    ax = 0x3f48;
    sub_117a7();
    ax = 0x3f49;
    sub_117a7();
    ax = 0x3f4a;
    sub_117a7();
    ax = 0x3f4b;
    sub_117a7();
    ax = 0x3f4c;
    sub_117a7();
    ax = 0x3f4d;
    sub_117a7();
    ax = 0x3f50;
    sub_117a7();
    ax = 0x3f51;
    sub_117a7();
    ax = 0x3f52;
    sub_117a7();
    ax = 0x3f53;
    sub_117a7();
    ax = 0x3f54;
    sub_117a7();
    ax = 0x3f55;
    sub_117a7();
    ax = pop();
}
void sub_119eb() // 1020:17eb
{
    sync(); return;
loc_119eb: // 1020:17eb
    al = memoryAGet(cs, 0x16e4);
    al &= 0x03;
    if (al != 0x03)
        goto loc_119fc;
    if (memoryAGet(ds, 0x09b2) != 0x00)
        goto loc_119eb;
loc_119fc: // 1020:17fc
    return;
}
void sub_119fe() // 1020:17fe
{
    ax = 0x168f;
    ds = ax;
    ah = 0x04;
    interrupt(0x1a);
    if (flags.carry)
        goto loc_11a3d;
    push(dx);
    ax = 0;
    bl = 0x04;
    bp = 0x000a;
loc_11a11: // 1020:1811
    mul16(bp);
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    dh = rcl8(dh, 0x01);
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    dh = rcl8(dh, 0x01);
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    dh = rcl8(dh, 0x01);
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    dh = rcl8(dh, 0x01);
    al += dh;
    bl--;
    if (bl)
        goto loc_11a11;
    dx = pop();
    if (ax >= 0x0813)
        goto loc_11a3d;
    if (ax != 0x07c8)
        goto loc_11a3a;
    if (dh >= 0x06)
        goto loc_11a3a;
    ax--;
loc_11a3a: // 1020:183a
    memoryASet16(ds, 0x000a, ax);
loc_11a3d: // 1020:183d
    return;
}
void sub_11a3f() // 1020:183f
{
    goto loc_11a3f;
loc_11a3e: // 1020:183e
    return;
loc_11a3f: // 1020:183f
    ax = 0x168f;
    ds = ax;
    if (memoryAGet16(ds, 0x000a) < 0x07cc)
        goto loc_11a3e;
    sub_129df();
    sub_1058a();
    memoryASet16(ds, 0x01f5, 0x0005);
    memoryASet16(ds, 0x01f7, 0x0960);
    si = 0x4e6e;
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x0000);
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    si = 0x4e7a;
    sub_10688();
    dx = memoryAGet16(ds, 0x000a);
    sub_10623();
    si = 0x4e9a;
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x0001);
    memoryASet16(ds, 0x01f7, 0x1680);
    si = 0x4e9e;
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x0003);
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    si = 0x4ec3;
    sub_10688();
    sub_105f2();
    sub_129df();
}
void sub_11aaf() // 1020:18af
{
    goto loc_11aaf;
loc_11aae: // 1020:18ae
    return;
loc_11aaf: // 1020:18af
    al = memoryAGet(ds, 0x045d);
    al &= memoryAGet(ds, 0x0478);
    ah = al;
    ah &= memoryAGet(ds, 0x0451);
    if (ah)
        goto loc_11ac4;
    al &= memoryAGet(ds, 0x0450);
    if (!al)
        goto loc_11aae;
loc_11ac4: // 1020:18c4
    bx = 0x0001;
    al = 0;
loc_11ac9: // 1020:18c9
    if (bl == 0x10)
        goto loc_11ae3;
    if (bl == 0x11)
        goto loc_11ae3;
    if (bl == 0x1d)
        goto loc_11ae3;
    if (bl == 0x38)
        goto loc_11ae3;
    al |= memoryAGet(ds, bx + 1088);
    if (al)
        goto loc_11aae;
loc_11ae3: // 1020:18e3
    bx++;
    if (bl < 0x7f)
        goto loc_11ac9;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    if (memoryAGet(ds, 0x0450) == 0x00)
        goto loc_11b09;
    if (memoryAGet(ds, 0x041a) < 0x0a)
        goto loc_11b09;
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) + 1);
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) - 0x0a);
loc_11b09: // 1020:1909
    sub_11b58();
    sub_105f2();
    sub_105ae();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11b1c() // 1020:191c
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    sub_13360();
    sub_11b58();
    memoryASet16(ds, 0x043c, 0x0000);
loc_11b36: // 1020:1936
    sub_10a05();
    if (memoryAGet(ds, 0x042b) != 0x00)
        goto loc_11b48;
    if (memoryAGet16(ds, 0x043c) < 0x0168)
        goto loc_11b36;
loc_11b48: // 1020:1948
    memoryASet16(ds, 0x043c, 0x0870);
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11b58() // 1020:1958
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    ax = 0x0009;
    sub_112ff();
    sub_12a11();
    sub_1058a();
    memoryASet16(ds, 0x01f5, 0x0005);
    memoryASet16(ds, 0x01f7, 0x03c0);
    si = 0x4ee3;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f02;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f21;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f40;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f5f;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f7e;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4f9d;
    sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    si = 0x4fbc;
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x000f);
    memoryASet16(ds, 0x01f7, 0x1770);
    si = 0x4fdb;
    sub_10688();
    memoryASet16(ds, 0x01f5, 0x0000);
    memoryASet16(ds, 0x01f7, 0x1a40);
    si = 0x4fe5;
    sub_10688();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11c2a() // 1020:1a2a
{
    goto loc_11c2a;
loc_11c29: // 1020:1a29
    return;
loc_11c2a: // 1020:1a2a
    al = memoryAGet(ds, 0x045d);
    al &= memoryAGet(ds, 0x0478);
    al &= memoryAGet(ds, 0x0452);
    if (!al)
        goto loc_11c29;
    bx = 0x0001;
    al = 0;
loc_11c3c: // 1020:1a3c
    if (bl == 0x12)
        goto loc_11c51;
    if (bl == 0x1d)
        goto loc_11c51;
    if (bl == 0x38)
        goto loc_11c51;
    al |= memoryAGet(ds, bx + 1088);
    if (al)
        goto loc_11c29;
loc_11c51: // 1020:1a51
    bx++;
    if (bl < 0x7f)
        goto loc_11c3c;
    goto loc_11c61;
    // gap 8 bytes
loc_11c61: // 1020:1a61
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    dx = 0x500e;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x4e52, ax);
    sub_11c8d();
    ax = 0x0009;
    sub_112ff();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11c59() // 1020:1a59
{
    goto loc_11c59;
loc_11c29: // 1020:1a29
    return;
    // gap 47 bytes
loc_11c59: // 1020:1a59
    if (memoryAGet16(ds, 0x000a) < 0x07c8)
        goto loc_11c29;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    dx = 0x500e;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x4e52, ax);
    sub_11c8d();
    ax = 0x0009;
    sub_112ff();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_11c8d() // 1020:1a8d
{
    sub_13360();
    if (memoryAGet(cs, 0x0001) != 0x05)
        goto loc_11ce4;
    ax = 0x000d;
    interrupt(0x10);
    ax = 0x168f;
    ds = ax;
    es = ax;
    dx = 0x4e54;
    ax = 0x1002;
    interrupt(0x10);
    dx = 0x03c8;
    al = 0;
    out8(dx, al);
    dx++;
    cx = 0x0010;
    al = 0;
loc_11cb8: // 1020:1ab8
    out8(dx, al);
    goto loc_11cbb;
loc_11cbb: // 1020:1abb
    out8(dx, al);
    goto loc_11cbe;
loc_11cbe: // 1020:1abe
    out8(dx, al);
    al += 0x04;
    if (--cx)
        goto loc_11cb8;
    ax = 0xa000;
    es = ax;
    ds = memoryAGet16(ds, 0x4e52);
    si = 0;
    dx = 0x03c4;
    ax = 0x0102;
loc_11cd4: // 1020:1ad4
    out16(dx, ax);
    cx = 0x0fa0;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ah <<= 1;
    if (ah <= 0x08)
        goto loc_11cd4;
    return;
loc_11ce4: // 1020:1ae4
    if (memoryAGet(cs, 0x0001) == 0x00)
        goto loc_11cf1;
    ax = 0x0006;
    interrupt(0x10);
loc_11cf1: // 1020:1af1
    ax = 0xb800;
    es = ax;
    ax = 0;
    di = 0;
    cx = 0x3e80;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    memoryASet(ds, 0x4e6a, 0x00);
    memoryASet16(ds, 0x4e68, 0x0000);
    memoryASet(ds, 0x4e6d, 0x00);
    memoryASet16(ds, 0x4e6b, 0x0000);
    bx = 0;
loc_11d17: // 1020:1b17
    sub_11db6();
    push(ax);
    bx += ax;
    if ((short)bx < (short)0x0010)
        goto loc_11d30;
    sub_11d83();
    sub_11e09();
    ax &= 0x0001;
    bx -= 0x0010;
    bx += ax;
loc_11d30: // 1020:1b30
    memoryASet16(ds, 0x4e68, memoryAGet16(ds, 0x4e68) + 1);
    ax = pop();
    bx += ax;
    if ((short)bx < (short)0x0010)
        goto loc_11d4a;
    sub_11d83();
    sub_11e09();
    ax &= 0x0001;
    bx -= 0x0010;
    bx += ax;
loc_11d4a: // 1020:1b4a
    memoryASet16(ds, 0x4e68, memoryAGet16(ds, 0x4e68) + 1);
    if (memoryAGet16(ds, 0x4e68) < 0x0280)
        goto loc_11d67;
    memoryASet16(ds, 0x4e68, 0x0000);
    memoryASet(ds, 0x4e6a, memoryAGet(ds, 0x4e6a) + 1);
    if (memoryAGet(ds, 0x4e6a) >= 0xc8)
        goto loc_11d82;
loc_11d67: // 1020:1b67
    if (memoryAGet16(ds, 0x4e6b) < 0x0140)
        goto loc_11d80;
    memoryASet16(ds, 0x4e6b, 0x0000);
    memoryASet(ds, 0x4e6d, memoryAGet(ds, 0x4e6d) + 1);
    if (memoryAGet(ds, 0x4e6d) >= 0xc8)
        goto loc_11d82;
loc_11d80: // 1020:1b80
    goto loc_11d17;
loc_11d82: // 1020:1b82
    return;
}
void sub_11d83() // 1020:1b83
{
    push(ax);
    push(cx);
    push(di);
    al = memoryAGet(ds, 0x4e6a);
    al >>= 1;
    ah = 0x50;
    mul8(ah);
    if (!(memoryAGet(ds, 0x4e6a) & 0x01))
        goto loc_11d99;
    ax += 0x2000;
loc_11d99: // 1020:1b99
    di = ax;
    ax = memoryAGet16(ds, 0x4e68);
    cl = 0x03;
    ax >>= cl;
    di += ax;
    cl = memoryAGet(ds, 0x4e68);
    cl &= 0x07;
    ah = 0x80;
    ah >>= cl;
    memoryASet(es, di, memoryAGet(es, di) | ah);
    di = pop();
    cx = pop();
    ax = pop();
}
void sub_11db6() // 1020:1bb6
{
    push(cx);
    push(di);
    al = memoryAGet(ds, 0x4e6d);
    ah = 0x28;
    mul8(ah);
    di = 0;
    di &= 0xfff0;
    di += ax;
    ax = memoryAGet16(ds, 0x4e6b);
    cl = 0x03;
    ax >>= cl;
    di += ax;
    cl = memoryAGet(ds, 0x4e6b);
    cl &= 0x07;
    ah = 0x80;
    ah >>= cl;
    al = 0;
    push(ds);
    ds = memoryAGet16(ds, 0x4e52);
    if (!(memoryAGet(ds, di) & ah))
        goto loc_11de7;
    al++;
loc_11de7: // 1020:1be7
    if (!(memoryAGet(ds, di + 8000) & ah))
        goto loc_11def;
    al += 0x02;
loc_11def: // 1020:1bef
    if (!(memoryAGet(ds, di + 16000) & ah))
        goto loc_11df7;
    al += 0x04;
loc_11df7: // 1020:1bf7
    if (!(memoryAGet(ds, di + 24000) & ah))
        goto loc_11dff;
    al += 0x08;
loc_11dff: // 1020:1bff
    ds = pop();
    ah = 0;
    memoryASet16(ds, 0x4e6b, memoryAGet16(ds, 0x4e6b) + 1);
    di = pop();
    cx = pop();
}
void sub_11e09() // 1020:1c09
{
    ax = memoryAGet16(ds, 0x4e65);
    ax += 0x9248;
    ax = ror16(ax, 0x0001);
    ax = ror16(ax, 0x0001);
    ax = ror16(ax, 0x0001);
    memoryASet16(ds, 0x4e65, ax);
}
void sub_11e1a() // 1020:1c1a
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_11e2f;
    push(dx);
    push(ax);
    dx = 0x03da;
    al = in8(dx);
    dl = 0xc0;
    al = 0x20;
    out8(dx, al);
    ax = pop();
    dx = pop();
loc_11e2f: // 1020:1c2f
    return;
}
void sub_11e30() // 1020:1c30
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_11e45;
    push(dx);
    push(ax);
    dx = 0x03da;
    al = in8(dx);
    dl = 0xc0;
    al = 0;
    out8(dx, al);
    ax = pop();
    dx = pop();
loc_11e45: // 1020:1c45
    return;
}
void sub_11e61() // 1020:1c61
{
    bool temp_cond0;
    bool temp_cond1;

    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    si = 0x567e;
loc_11e72: // 1020:1c72
    memoryASet16(ds, 0x527a, si);
    if (memoryAGet16(ds, si + 4) != 0xffff)
        goto loc_11e7f;
    goto loc_126a9;
loc_11e7f: // 1020:1c7f
    ax = 0;
    memoryASet(cs, 0x1c49, al);
    memoryASet(cs, 0x1c53, al);
    memoryASet(cs, 0x1c56, al);
    memoryASet(cs, 0x1c57, al);
    memoryASet16(cs, 0x1c46, ax);
    memoryASet(ds, si + 5, memoryAGet(ds, si + 5) & 0xdf);
    bx = memoryAGet16(ds, si + 4);
    flags.carry = !!(bx & 0x8000);
    bx <<= 1;
    memoryASet(cs, 0x1c48, rcl8(memoryAGet(cs, 0x1c48), 0x01));
    al = 0x01;
    if (!(bh & 0x80))
        goto loc_11eaf;
    al = 0x41;
    bh &= 0x7f;
loc_11eaf: // 1020:1caf
    memoryASet(cs, 0x1c5e, al);
    dx = memoryAGet16(ds, bx + 26213);
    al = memoryAGet(ds, bx + 26927);
    if (!(memoryAGet(cs, 0x1c48) & 0x01))
        goto loc_11ec9;
    al -= memoryAGet(ds, bx + 26213);
    al = -al;
loc_11ec9: // 1020:1cc9
    cbw();
    ax = -ax;
    ax += memoryAGet16(ds, si);
    cx = memoryAGet16(ds, 0x5270);
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax -= cx;
    cx = ax;
    memoryASet16(cs, 0x1c50, ax);
    if ((short)ax < (short)0x0140)
        goto loc_11eea;
    goto loc_126a9;
loc_11eea: // 1020:1cea
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    ch += 0x00 + flags.carry;
    if ((char)ch >= 0)
        goto loc_11ef4;
    goto loc_126a9;
loc_11ef4: // 1020:1cf4
    al = memoryAGet(ds, bx + 26928);
    cbw();
    ax += memoryAGet16(ds, si + 2);
    ax++;
    cx = memoryAGet16(ds, 0x5272);
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    temp_cond0 = (short)ax - (short)cx > 0;
    ax -= cx;
    if (temp_cond0)
        goto loc_11f10;
    goto loc_126a9;
loc_11f10: // 1020:1d10
    memoryASet16(ds, 0x5278, ax);
    memoryASet(cs, 0x1c52, dh);
    memoryASet(cs, 0x1c4c, dh);
    flags.carry = al < dh;
    al -= dh;
    ah = ah - 0x00 - flags.carry;
    if ((short)ax < (short)0x00c0)
        goto loc_11f2a;
    goto loc_126a9;
loc_11f2a: // 1020:1d2a
    memoryASet16(cs, 0x1c4e, ax);
    cl = memoryAGet(cs, 0x0000);
    dl >>= cl;
    memoryASet(cs, 0x1c4a, dl);
    memoryASet(cs, 0x1c4b, dl);
    dh = 0;
    cx = 0;
    if ((short)ax >= 0)
        goto loc_11f5a;
    ax = -ax;
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - al);
    mul8(dl);
    cx = ax;
    memoryASet16(cs, 0x1c46, ax);
    di = 0;
    goto loc_11f60;
loc_11f5a: // 1020:1d5a
    mul8(memoryAGet(ds, 0x525c));
    di = ax;
loc_11f60: // 1020:1d60
    di += memoryAGet16(ds, 0x526a);
    memoryASet16(cs, 0x1c58, di);
    ax = memoryAGet16(ds, bx + 24004);
    memoryASet16(cs, 0x1c5c, ax);
    ax = memoryAGet16(ds, bx + 23204);
    ax += cx;
    memoryASet16(cs, 0x1c5a, ax);
    ax = memoryAGet16(ds, 0x5278);
    temp_cond1 = (short)ax - (short)0x00c0 <= 0;
    ax -= 0x00c0;
    if (temp_cond1)
        goto loc_11f8f;
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - al);
    mul8(dl);
    memoryASet16(cs, 0x1c46, memoryAGet16(cs, 0x1c46) + ax);
loc_11f8f: // 1020:1d8f
    ax = memoryAGet16(cs, 0x1c50);
    if ((short)ax >= 0)
        goto loc_11fb0;
    cl = memoryAGet(cs, 0x0000);
    ax = sar16(ax, cl);
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) + al);
    al = -al;
    memoryASet(cs, 0x1c53, al);
    memoryASet(cs, 0x1c49, memoryAGet(cs, 0x1c49) + 1);
    goto loc_11fe8;
loc_11fb0: // 1020:1db0
    cl = memoryAGet(cs, 0x0000);
    ax = sar16(ax, cl);
    memoryASet16(cs, 0x1c58, memoryAGet16(cs, 0x1c58) + ax);
    ax = memoryAGet16(cs, 0x1c50);
    cl = memoryAGet(cs, 0x0000);
    ax >>= cl;
    flags.carry = (al + memoryAGet(cs, 0x1c4a)) >= 0x100;
    al += memoryAGet(cs, 0x1c4a);
    ah += 0x00 + flags.carry;
    flags.carry = ax < memoryAGet16(ds, 0x525c);
    ax -= memoryAGet16(ds, 0x525c);
    if (flags.carry)
        goto loc_11fe8;
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) - al);
    memoryASet(cs, 0x1c49, memoryAGet(cs, 0x1c49) + 1);
    memoryASet(cs, 0x1c56, al);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
loc_11fe8: // 1020:1de8
    memoryASet(ds, si + 5, memoryAGet(ds, si + 5) | 0x20);
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_11ff7;
    goto loc_1223a;
loc_11ff7: // 1020:1df7
    if (memoryAGet(cs, 0x1c5e) == 0x01)
        goto loc_12002;
    goto loc_126a9;
loc_12002: // 1020:1e02
    al = memoryAGet(cs, 0x1c4b);
    mul8(memoryAGet(cs, 0x1c4c));
    memoryASet16(cs, 0x1c5f, ax);
    es = memoryAGet16(ds, 0x5262);
    di = memoryAGet16(cs, 0x1c58);
    ds = memoryAGet16(cs, 0x1c5c);
    bx = memoryAGet16(cs, 0x1c5f);
    si = memoryAGet16(cs, 0x1c5a);
    dl = memoryAGet(cs, 0x1c52);
    if (memoryAGet(cs, 0x1c49) != 0x00)
        goto loc_120a3;
    if (memoryAGet16(cs, 0x1c50) & 0x0003)
        goto loc_120a3;
    dh = memoryAGet(cs, 0x1c4a);
    ch = 0;
    cl = dh;
    if (memoryAGet(cs, 0x1c48) & 0x01)
        goto loc_1206c;
    bp = 0x0050;
    bp -= cx;
loc_12053: // 1020:1e53
    cx >>= 1;
loc_12055: // 1020:1e55
    ax = memoryAGet16(es, di);
    ax &= memoryAGet16(ds, bx + si);
    ax |= memoryAGet16(ds, si);
    stosw<ES_DI>(ax);
    si++;
    si++;
    if (--cx)
        goto loc_12055;
    cl = dh;
    di += bp;
    dl--;
    if (dl)
        goto loc_12053;
    goto loc_126a9;
loc_1206c: // 1020:1e6c
    bp = bx;
    bx = 0x330e;
    di += cx;
    di--;
loc_12074: // 1020:1e74
    cx >>= 1;
loc_12076: // 1020:1e76
    ax = memoryAGet16(ds, bp + si);
    al = memoryAGet(cs, bx+al);
    memoryASet(es, di, memoryAGet(es, di) & al);
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    memoryASet(es, di, memoryAGet(es, di) | al);
    di--;
    al = ah;
    al = memoryAGet(cs, bx+al);
    memoryASet(es, di, memoryAGet(es, di) & al);
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    memoryASet(es, di, memoryAGet(es, di) | al);
    di--;
    if (--cx)
        goto loc_12076;
    cl = dh;
    di += cx;
    di += 0x0050;
    dl--;
    if (dl)
        goto loc_12074;
loc_120a0: // 1020:1ea0
    goto loc_126a9;
loc_120a3: // 1020:1ea3
    if (memoryAGet(cs, 0x1c4a) == 0x00)
        goto loc_120a0;
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x03;
    cl <<= 1;
    ch = 0xff;
    ch <<= cl;
    if (memoryAGet(cs, 0x1c48) & 0x01)
        goto loc_1213e;
loc_120c1: // 1020:1ec1
    al = memoryAGet(cs, 0x1c4a);
    cbw();
    bp = ax;
    al = memoryAGet(cs, 0x1c53);
    cbw();
    si += ax;
    ch = ~ch;
    dx = 0xff00;
    dh &= ch;
    if (!ax)
        goto loc_120e4;
    dh = memoryAGet(ds, bx + si + -1);
    dh &= ch;
    dl = memoryAGet(ds, si + 65535);
    dl &= ch;
loc_120e4: // 1020:1ee4
    ch = ~ch;
loc_120e6: // 1020:1ee6
    al = memoryAGet(ds, bx + si);
    ah = al;
    al &= ch;
    al |= dh;
    al = ror8(al, cl);
    memoryASet(es, di, memoryAGet(es, di) & al);
    al = lodsb<DS_SI>();
    dh = al;
    al &= ch;
    al |= dl;
    al = ror8(al, cl);
    memoryASet(es, di, memoryAGet(es, di) | al);
    ch = ~ch;
    dl = dh;
    dh = ah;
    dl &= ch;
    dh &= ch;
    ch = ~ch;
    di++;
    bp--;
    if (bp)
        goto loc_120e6;
    if (memoryAGet(cs, 0x1c57) != 0x00)
        goto loc_12123;
    dh |= ch;
    dh = ror8(dh, cl);
    dl = ror8(dl, cl);
    memoryASet(es, di, memoryAGet(es, di) & dh);
    memoryASet(es, di, memoryAGet(es, di) | dl);
loc_12123: // 1020:1f23
    al = memoryAGet(cs, 0x1c4a);
    cbw();
    di -= ax;
    di += 0x0050;
    al = memoryAGet(cs, 0x1c56);
    cbw();
    si += ax;
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - 1);
    if (memoryAGet(cs, 0x1c52))
        goto loc_120c1;
    goto loc_126a9;
loc_1213e: // 1020:1f3e
    al = memoryAGet(cs, 0x1c53);
    memoryASet(cs, 0x1c54, al);
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x03;
    cl -= 0x04;
    cl = -cl;
    cl &= 0x03;
    cl <<= 1;
    ch = 0xff;
    ch >>= cl;
    bp = bx;
    bx = 0x330e;
    if (memoryAGet(cs, 0x1c53) == 0x00)
        goto loc_1217d;
    di--;
    if (!(memoryAGet16(cs, 0x1c50) & 0x0003))
        goto loc_1217d;
    memoryASet(cs, 0x1c53, memoryAGet(cs, 0x1c53) - 1);
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) + 1);
loc_1217d: // 1020:1f7d
    if (memoryAGet(cs, 0x1c57) == 0x00)
        goto loc_1219a;
    di--;
    if (!(memoryAGet16(cs, 0x1c50) & 0x0003))
        goto loc_1219a;
    di++;
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) - 1);
    memoryASet(cs, 0x1c56, memoryAGet(cs, 0x1c56) + 1);
loc_1219a: // 1020:1f9a
    al = memoryAGet(cs, 0x1c4a);
    cbw();
    di += ax;
loc_121a1: // 1020:1fa1
    al = memoryAGet(cs, 0x1c4a);
    memoryASet(cs, 0x1c4d, al);
    ch = ~ch;
    dx = 0xff00;
    dh &= ch;
    ch = ~ch;
    if (memoryAGet(cs, 0x1c57) == 0x00)
        goto loc_121d7;
    al = memoryAGet(cs, 0x1c56);
    cbw();
    si += ax;
    al = memoryAGet(ds, bp + si + -1);
    al = memoryAGet(cs, bx+al);
    dh = al;
    al = memoryAGet(ds, si + 65535);
    al = memoryAGet(cs, bx+al);
    dl = al;
    memoryASet(cs, 0x1c4d, memoryAGet(cs, 0x1c4d) + 1);
    goto loc_121fa;
loc_121d7: // 1020:1fd7
    al = memoryAGet(ds, bp + si);
    al = memoryAGet(cs, bx+al);
    ah = al;
    al &= ch;
    al |= dh;
    al = rol8(al, cl);
    memoryASet(es, di, memoryAGet(es, di) & al);
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dh = al;
    al &= ch;
    al |= dl;
    al = rol8(al, cl);
    memoryASet(es, di, memoryAGet(es, di) | al);
    di--;
    dl = dh;
    dh = ah;
loc_121fa: // 1020:1ffa
    ch = ~ch;
    dl &= ch;
    dh &= ch;
    ch = ~ch;
    memoryASet(cs, 0x1c4d, memoryAGet(cs, 0x1c4d) - 1);
    if (memoryAGet(cs, 0x1c4d))
        goto loc_121d7;
    if (memoryAGet(cs, 0x1c54) != 0x00)
        goto loc_1221d;
    dh |= ch;
    dh = rol8(dh, cl);
    dl = rol8(dl, cl);
    memoryASet(es, di, memoryAGet(es, di) & dh);
    memoryASet(es, di, memoryAGet(es, di) | dl);
loc_1221d: // 1020:201d
    al = memoryAGet(cs, 0x1c4a);
    cbw();
    di += ax;
    di += 0x0050;
    al = memoryAGet(cs, 0x1c53);
    si += ax;
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - 1);
    if (!memoryAGet(cs, 0x1c52))
        goto loc_12237;
    goto loc_121a1;
loc_12237: // 1020:2037
    goto loc_126a9;
loc_1223a: // 1020:203a
    sub_134dc();
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x07;
    ch = 0xff;
    ch <<= cl;
    di = memoryAGet16(cs, 0x1c58);
    si = memoryAGet16(cs, 0x1c5a);
    dl = 0xce;
    al = 0x03;
    ah = cl;
    ah |= 0x08;
    out16(dx, ax);
    bh = ch;
    bh = ~bh;
    dh = memoryAGet(cs, 0x1c4a);
    cl = dh;
    al = cl;
    cbw();
    ax -= 0x0028;
    bp = ax;
    dl = memoryAGet(cs, 0x1c52);
    ds = memoryAGet16(cs, 0x1c5c);
    ax = 0xa000;
    es = ax;
    if (memoryAGet(cs, 0x1c48) & 0x01)
        goto loc_12291;
    goto loc_124e9;
loc_12291: // 1020:2091
    memoryASet(cs, 0x1c4c, dl);
    dx = bx;
    bx = 0x340e;
    flags.direction = 1;
    si--;
    if (memoryAGet(cs, 0x1c49) == 0x00)
        goto loc_122a8;
    goto loc_123ef;
loc_122a8: // 1020:20a8
    al = cl;
    cbw();
    si += ax;
    if (ch == 0xff)
        goto loc_122b5;
    goto loc_1233c;
loc_122b5: // 1020:20b5
    ch = 0;
loc_122b7: // 1020:20b7
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    al = ~al;
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
    if (--cx)
        goto loc_122b7;
    cl = memoryAGet(cs, 0x1c4a);
    al = cl;
    cbw();
    si += ax;
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_122b7;
    push(dx);
    dx = 0x03ce;
    ax = 0x1003;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    dx = pop();
loc_122ee: // 1020:20ee
    push(dx);
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    cl = memoryAGet(cs, 0x1c4a);
    dl = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, dl);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
    dx = pop();
loc_12311: // 1020:2111
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
    if (--cx)
        goto loc_12311;
    cl = memoryAGet(cs, 0x1c4a);
    al = cl;
    cbw();
    si += ax;
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_12311;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al < 0x10)
        goto loc_122ee;
    goto loc_126a9;
loc_1233c: // 1020:213c
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    al &= ch;
    al |= ah;
    al = ~al;
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
    dl &= dh;
    ah = dl;
    cl--;
    if (cl)
        goto loc_1233c;
    ah = ~ah;
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = memoryAGet(cs, 0x1c4a);
    al = cl;
    cbw();
    si += ax;
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_1233c;
    push(dx);
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x07;
    dx = 0x03ce;
    al = 0x03;
    ah = cl;
    ah |= 0x10;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    dx = pop();
loc_12390: // 1020:2190
    push(dx);
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    cl = memoryAGet(cs, 0x1c4a);
    dl = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, dl);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
    dx = pop();
    ax = 0;
loc_123b5: // 1020:21b5
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    al &= ch;
    al |= ah;
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
    dl &= dh;
    ah = dl;
    cl--;
    if (cl)
        goto loc_123b5;
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = memoryAGet(cs, 0x1c4a);
    al = cl;
    cbw();
    si += ax;
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_123b5;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al < 0x10)
        goto loc_12390;
    goto loc_126a9;
loc_123ef: // 1020:21ef
    al = memoryAGet(cs, 0x1c4b);
    cbw();
    si += ax;
loc_123f6: // 1020:21f6
    al = memoryAGet(cs, 0x1c53);
    cbw();
    if (!ax)
        goto loc_1240a;
    ax--;
    si -= ax;
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    cx++;
    goto loc_12419;
loc_1240a: // 1020:220a
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    al &= ch;
    al |= ah;
    al = ~al;
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
loc_12419: // 1020:2219
    dl &= dh;
    ah = dl;
    cl--;
    if (cl)
        goto loc_1240a;
    ah = ~ah;
    ah |= memoryAGet(cs, 0x1c57);
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = memoryAGet(cs, 0x1c4a);
    al = memoryAGet(cs, 0x1c4b);
    cbw();
    si += ax;
    al -= memoryAGet(cs, 0x1c56);
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_123f6;
    push(dx);
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x07;
    dx = 0x03ce;
    al = 0x03;
    ah = cl;
    ah |= 0x10;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    dx = pop();
loc_1246a: // 1020:226a
    push(dx);
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    cl = memoryAGet(cs, 0x1c4a);
    dl = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, dl);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
    dx = pop();
loc_1248d: // 1020:228d
    al = memoryAGet(cs, 0x1c53);
    cbw();
    if (!ax)
        goto loc_124a1;
    ax--;
    si -= ax;
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    cx++;
    goto loc_124ae;
loc_124a1: // 1020:22a1
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    dl = al;
    al &= ch;
    al |= ah;
    tl = memoryAGet(es, di); memoryASet(es, di, al); al = tl;
    di++;
loc_124ae: // 1020:22ae
    dl &= dh;
    ah = dl;
    cl--;
    if (cl)
        goto loc_124a1;
    ah &= memoryAGet(cs, 0x1c57);
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = memoryAGet(cs, 0x1c4a);
    al = memoryAGet(cs, 0x1c4b);
    cbw();
    si += ax;
    al -= memoryAGet(cs, 0x1c56);
    si += ax;
    di -= bp;
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        goto loc_1248d;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al >= 0x10)
        goto loc_124e6;
    goto loc_1246a;
loc_124e6: // 1020:22e6
    goto loc_126a9;
loc_124e9: // 1020:22e9
    if (memoryAGet(cs, 0x1c49) == 0x00)
        goto loc_124f4;
    goto loc_125e2;
loc_124f4: // 1020:22f4
    if (ch != 0xff)
        goto loc_12554;
    ch = 0;
loc_124fb: // 1020:22fb
    al = lodsb<DS_SI>();
    al = ~al;
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_124fb;
    cl = dh;
    di -= bp;
    dl--;
    if (dl)
        goto loc_124fb;
    dx = 0x03ce;
    ax = 0x1003;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
loc_1251b: // 1020:231b
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    dh = memoryAGet(cs, 0x1c4a);
    cl = dh;
    dl = memoryAGet(cs, 0x1c52);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
loc_12539: // 1020:2339
    al = lodsb<DS_SI>();
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_12539;
    di -= bp;
    cl = dh;
    dl--;
    if (dl)
        goto loc_12539;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al < 0x10)
        goto loc_1251b;
    goto loc_126a9;
loc_12554: // 1020:2354
    ax = 0;
loc_12556: // 1020:2356
    al = lodsb<DS_SI>();
    bl = al;
    al &= ch;
    al |= ah;
    al = ~al;
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
    bl &= bh;
    ah = bl;
    cl--;
    if (cl)
        goto loc_12556;
    ah = ~ah;
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = dh;
    di -= bp;
    dl--;
    if (dl)
        goto loc_12554;
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x07;
    dx = 0x03ce;
    al = 0x03;
    ah = cl;
    ah |= 0x10;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
loc_12598: // 1020:2398
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    dh = memoryAGet(cs, 0x1c4a);
    cl = dh;
    dl = memoryAGet(cs, 0x1c52);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
loc_125b6: // 1020:23b6
    ax = 0;
loc_125b8: // 1020:23b8
    al = lodsb<DS_SI>();
    bl = al;
    al &= ch;
    al |= ah;
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
    bl &= bh;
    ah = bl;
    cl--;
    if (cl)
        goto loc_125b8;
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    cl = dh;
    di -= bp;
    dl--;
    if (dl)
        goto loc_125b6;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al < 0x10)
        goto loc_12598;
    goto loc_126a9;
loc_125e2: // 1020:23e2
    al = memoryAGet(cs, 0x1c53);
    cbw();
    if (!ax)
        goto loc_125f4;
    ax--;
    cx++;
    si += ax;
    al = lodsb<DS_SI>();
    bl = al;
    goto loc_12600;
loc_125f4: // 1020:23f4
    al = lodsb<DS_SI>();
    bl = al;
    al &= ch;
    al |= ah;
    al = ~al;
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
loc_12600: // 1020:2400
    bl &= bh;
    ah = bl;
    cl--;
    if (cl)
        goto loc_125f4;
    ah = ~ah;
    ah |= memoryAGet(cs, 0x1c57);
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    al = memoryAGet(cs, 0x1c56);
    cbw();
    si += ax;
    cl = memoryAGet(cs, 0x1c4a);
    di -= bp;
    dl--;
    if (dl)
        goto loc_125e2;
    cl = memoryAGet(cs, 0x1c50);
    cl &= 0x07;
    dx = 0x03ce;
    al = 0x03;
    ah = cl;
    ah |= 0x10;
    out16(dx, ax);
    dl = 0xc4;
    al = 0x02;
    out8(dx, al);
    al = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
loc_12645: // 1020:2445
    memoryASet(cs, 0x1c4d, al);
    dx = 0x03c5;
    out8(dx, al);
    cl = memoryAGet(cs, 0x1c4a);
    dl = memoryAGet(cs, 0x1c52);
    di = memoryAGet16(cs, 0x1c58);
    si += memoryAGet16(cs, 0x1c46);
loc_12661: // 1020:2461
    al = memoryAGet(cs, 0x1c53);
    cbw();
    if (!ax)
        goto loc_12673;
    ax--;
    cx++;
    si += ax;
    al = lodsb<DS_SI>();
    bl = al;
    goto loc_1267d;
loc_12673: // 1020:2473
    al = lodsb<DS_SI>();
    bl = al;
    al &= ch;
    al |= ah;
    scasb_inv<ES_DI>(al);
    di--;
    stosb<ES_DI>(al);
loc_1267d: // 1020:247d
    bl &= bh;
    ah = bl;
    cl--;
    if (cl)
        goto loc_12673;
    ah &= memoryAGet(cs, 0x1c57);
    tl = memoryAGet(es, di); memoryASet(es, di, ah); ah = tl;
    al = memoryAGet(cs, 0x1c56);
    cbw();
    si += ax;
    cl = memoryAGet(cs, 0x1c4a);
    di -= bp;
    dl--;
    if (dl)
        goto loc_12661;
    al = memoryAGet(cs, 0x1c4d);
    al <<= 1;
    if (al < 0x10)
        goto loc_12645;
loc_126a9: // 1020:24a9
    flags.direction = 0;
    ax = 0x168f;
    ds = ax;
    si = memoryAGet16(ds, 0x527a);
    si -= 0x0012;
    if (si < 0x527c)
        goto loc_126bf;
    goto loc_11e72;
loc_126bf: // 1020:24bf
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_126c9() // 1020:24c9
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_126f1;
    ax = memoryAGet16(ds, 0x04c1);
    memoryASet16(ds, 0x5262, ax);
    ax += 0x0400;
    memoryASet16(ds, 0x5264, ax);
    memoryASet16(ds, 0x04c1, memoryAGet16(ds, 0x04c1) + 0x0800);
loc_126f1: // 1020:24f1
    si = 0x7255;
    bx = 0;
loc_126f6: // 1020:24f6
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_1271a;
loc_126fc: // 1020:24fc
    if (ax == bx)
        goto loc_12708;
    memoryASet(ds, bx + 28869, 0x00);
    bx++;
    goto loc_126fc;
loc_12708: // 1020:2508
    ax = lodsw<DS_SI>();
loc_12709: // 1020:2509
    memoryASet(ds, bx + 28869, 0x01);
    bx++;
    ax--;
    if (ax)
        goto loc_12709;
    goto loc_126f6;
loc_12714: // 1020:2514
    memoryASet(ds, bx + 28869, 0x00);
    bx++;
loc_1271a: // 1020:251a
    if (bx == 0x0190)
        goto loc_12714;
    dx = 0x501a;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x5260, ax);
    bx = 0;
loc_1272f: // 1020:252f
    al = memoryAGet(ds, bx + 26214);
    if (!al)
        goto loc_12743;
    memoryASet(ds, bx + 26928, memoryAGet(ds, bx + 26928) - al);
    memoryASet(ds, bx + 26928, -memoryAGet(ds, bx + 26928));
    bx++;
    bx++;
    goto loc_1272f;
loc_12743: // 1020:2543
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_1274e;
    goto loc_1283e;
loc_1274e: // 1020:254e
    si = 0;
    memoryASet16(cs, 0x6676, 0x274f);
    ax = memoryAGet16(ds, 0x5260);
    memoryASet16(ds, 0x5268, ax);
    memoryASet16(ds, 0x525e, 0x0000);
    es = memoryAGet16(ds, 0x04c1);
loc_12767: // 1020:2567
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x1ef0;
    ax = 0x168f;
    ds = ax;
    cx = memoryAGet16(ds, 0x525e);
    dx = cx;
    dx >>= 1;
    dx >>= 1;
    di += dx;
    al = 0xc0;
    cl &= 0x03;
    cl <<= 1;
    al >>= cl;
    memoryASet(es, di, memoryAGet(es, di) | al);
    es = pop();
    ax = si;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x5268, memoryAGet16(ds, 0x5268) + ax);
    si &= 0x000f;
    di = 0;
    bx = memoryAGet16(ds, 0x525e);
    memoryASet16(ds, 0x525e, memoryAGet16(ds, 0x525e) + 1);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 26213);
    dx = ax;
    mul8(ah);
    ax >>= 1;
    ax >>= 1;
    if (!ax)
        goto loc_12808;
    cx = ax;
    push(si);
    ds = memoryAGet16(ds, 0x5268);
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    si = pop();
    bx = ax;
    al = dh;
    ah = dl;
    ah >>= 1;
    ah >>= 1;
    ah >>= 1;
    sub_167be();
    si += bx;
    bx >>= 1;
    bp = bx;
    di = 0;
loc_127da: // 1020:25da
    al = memoryAGet(es, di);
    di += bx;
    al |= memoryAGet(es, di);
    di += bx;
    al |= memoryAGet(es, di);
    al |= memoryAGet(es, bx + di);
    di -= bx;
    di -= bx;
    cx = 0x0008;
loc_127f1: // 1020:25f1
    flags.carry = al & 1;
    al >>= 1;
    dx = rcr16(dx, 0x0001);
    dx = sar16(dx, 0x0001);
    if (--cx)
        goto loc_127f1;
    tl = dh; dh = dl; dl = tl;
    dx = ~dx;
    memoryASet16(ds, si, dx);
    si++;
    si++;
    di++;
    bp--;
    if (bp)
        goto loc_127da;
    goto loc_12767;
loc_12808: // 1020:2608
    ax = 0x168f;
    ds = ax;
    di = 0;
    bx = memoryAGet16(ds, 0x5260);
    cx = 0;
loc_12815: // 1020:2615
    memoryASet16(ds, di + 24004, bx);
    memoryASet16(ds, di + 23204, cx);
    ax = memoryAGet16(ds, di + 26213);
    di++;
    di++;
    mul8(ah);
    ax >>= 1;
    if (!ax)
        goto loc_1283b;
    cx += ax;
    if (cx < 0x1000)
        goto loc_12815;
    cx -= 0x1000;
    bx += 0x0100;
    goto loc_12815;
loc_1283b: // 1020:263b
    goto loc_1293d;
loc_1283e: // 1020:263e
    flags.direction = 1;
    ax = memoryAGet16(ds, 0x04c1);
    bx = memoryAGet16(ds, 0x5260);
    ax -= bx;
    bp = ax;
    dx = ax;
    dx >>= 1;
    dx >>= 1;
    dx++;
    ax += dx;
    ax += bx;
    memoryASet16(ds, 0x04c1, ax);
    ax--;
    bx = ax;
    ax -= dx;
loc_1285d: // 1020:265d
    ds = ax;
    es = bx;
    si = 0x000f;
    di = si;
    cx = 0x0010;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax--;
    bx--;
    bp--;
    if (bp)
        goto loc_1285d;
    flags.direction = 0;
    dx = 0x168f;
    ds = dx;
    ax++;
    bx++;
    memoryASet16(ds, 0x5087, ax);
    memoryASet16(ds, 0x5089, bx);
    bx = 0x6665;
    si = 0;
    di = 0;
loc_12886: // 1020:2686
    ax = si;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x5089, memoryAGet16(ds, 0x5089) + ax);
    si &= 0x000f;
    ax = di;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x5087, memoryAGet16(ds, 0x5087) + ax);
    di &= 0x000f;
    ax = memoryAGet16(ds, bx);
    if (!al)
        goto loc_128f2;
    al = ror8(al, 0x01);
    al = ror8(al, 0x01);
    al = ror8(al, 0x01);
    if (!(al & 0xe0))
        goto loc_128bc;
    al &= 0x1f;
    al++;
loc_128bc: // 1020:26bc
    bx++;
    bx++;
    mul8(ah);
    bp = ax;
    es = memoryAGet16(ds, 0x5087);
    ds = memoryAGet16(ds, 0x5089);
    cx = bp;
    push(si);
loc_128cd: // 1020:26cd
    al = memoryAGet(ds, si);
    al |= memoryAGet(ds, bp + si);
    si += bp;
    al |= memoryAGet(ds, bp + si);
    si += bp;
    al |= memoryAGet(ds, bp + si);
    si -= bp;
    si -= bp;
    stosb<ES_DI>(al);
    si++;
    if (--cx)
        goto loc_128cd;
    si = pop();
    cx = bp;
    cx <<= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ax = 0x168f;
    ds = ax;
    goto loc_12886;
loc_128f2: // 1020:26f2
    ax = 0x168f;
    ds = ax;
    es = ax;
    bx = memoryAGet16(ds, 0x5260);
    si = 0x6665;
    di = 0;
    dx = 0;
loc_12904: // 1020:2704
    ax = lodsw<DS_SI>();
    if (!al)
        goto loc_1293d;
    al = ror8(al, 0x01);
    al = ror8(al, 0x01);
    al = ror8(al, 0x01);
    if (!(al & 0xe0))
        goto loc_12917;
    al &= 0x1f;
    al++;
loc_12917: // 1020:2717
    mul8(ah);
    bp = ax;
    ax <<= 1;
    ax <<= 1;
    ax += bp;
    memoryASet16(ds, di + 23204, dx);
    memoryASet16(ds, di + 24004, bx);
    if (dx < 0x1000)
        goto loc_12937;
    dx -= 0x1000;
    bx += 0x0100;
loc_12937: // 1020:2737
    di++;
    di++;
    dx += ax;
    goto loc_12904;
loc_1293d: // 1020:273d
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1296f() // 1020:276f
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    push(ds);
    push(es);
    sub_12e87();
    ax = 0x168f;
    ds = ax;
    sub_129df();
    sub_134f4();
    bp = 0x0002;
    di = 0x0c92;
loc_12989: // 1020:2789
    sub_13443();
    cx = bp;
loc_1298e: // 1020:278e
    sub_12acd();
    di++;
    di++;
    if (--cx)
        goto loc_1298e;
    di--;
    di--;
    cx = bp;
    cx--;
loc_1299a: // 1020:279a
    di += 0x0190;
    sub_12acd();
    if (--cx)
        goto loc_1299a;
    cx = bp;
    cx--;
loc_129a6: // 1020:27a6
    di--;
    di--;
    sub_12acd();
    if (--cx)
        goto loc_129a6;
    cx = bp;
    cx--;
loc_129b0: // 1020:27b0
    di -= 0x0190;
    sub_12acd();
    if (--cx)
        goto loc_129b0;
    bp++;
    bp++;
    di -= 0x0192;
    if (bp < 0x0014)
        goto loc_12989;
    di = memoryAGet16(ds, 0x526a);
    si = memoryAGet16(ds, 0x5268);
    ax = 0xa000;
    es = ax;
    ds = ax;
    cx = 0x1e00;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    es = pop();
    ds = pop();
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_129df() // 1020:27df
{
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_129ec;
    sub_13360();
    goto loc_12a10;
loc_129ec: // 1020:27ec
    push(ax);
    push(cx);
    push(dx);
    push(di);
    push(es);
    sub_134dc();
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    di = memoryAGet16(ds, 0x5268);
    cx = 0x0f00;
    ax = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    es = pop();
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
loc_12a10: // 1020:2810
    return;
}
void sub_12a11() // 1020:2811
{
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_12a1d;
    sub_13360();
    return;
loc_12a1d: // 1020:281d
    push(ax);
    push(cx);
    push(dx);
    push(di);
    push(ds);
    push(es);
    sub_134dc();
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    ax = 0x168f;
    ds = ax;
    di = memoryAGet16(ds, 0x5268);
    cx = 0x0014;
    memoryASet16(cs, 0x274d, 0x0026);
    memoryASet16(cs, 0x274b, 0x1c70);
loc_12a47: // 1020:2847
    sub_13443();
    push(cx);
    push(di);
    memoryASet16(cs, 0x2747, 0x0000);
    memoryASet16(cs, 0x2749, 0x0000);
loc_12a5a: // 1020:285a
    di += memoryAGet16(cs, 0x2749);
    sub_12af8();
    di += memoryAGet16(cs, 0x274b);
    sub_12af8();
    di -= memoryAGet16(cs, 0x274b);
    di -= memoryAGet16(cs, 0x2749);
    if (memoryAGet16(cs, 0x2747) <= 0x1c70)
        goto loc_12a83;
    di += 0x1c70;
    goto loc_12a88;
loc_12a83: // 1020:2883
    di += memoryAGet16(cs, 0x2747);
loc_12a88: // 1020:2888
    sub_12af8();
    di += memoryAGet16(cs, 0x274d);
    sub_12af8();
    di -= memoryAGet16(cs, 0x274d);
    di -= memoryAGet16(cs, 0x2747);
    memoryASet16(cs, 0x2747, memoryAGet16(cs, 0x2747) + 0x0190);
    memoryASet16(cs, 0x2749, memoryAGet16(cs, 0x2749) + 0x0002);
    if (--cx)
        goto loc_12a5a;
    di = pop();
    di += 0x0192;
    memoryASet16(cs, 0x274d, memoryAGet16(cs, 0x274d) - 0x0004);
    memoryASet16(cs, 0x274b, memoryAGet16(cs, 0x274b) - 0x0320);
    cx = pop();
    cx--;
    cx--;
    if (cx)
        goto loc_12a47;
    sub_134dc();
    es = pop();
    ds = pop();
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12acd() // 1020:28cd
{
    push(ax);
    push(cx);
    push(di);
    push(si);
    push(ds);
    push(es);
    si = di;
    si += memoryAGet16(ds, 0x526a);
    di += memoryAGet16(ds, 0x5268);
    ax = 0xa000;
    ds = ax;
    es = ax;
    cx = 0x000a;
loc_12ae7: // 1020:28e7
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x0026;
    si += 0x0026;
    if (--cx)
        goto loc_12ae7;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    cx = pop();
    ax = pop();
}
void sub_12af8() // 1020:28f8
{
    push(ax);
    push(cx);
    push(di);
    push(es);
    ax = 0xa000;
    es = ax;
    cx = 0x000a;
    ax = 0;
loc_12b06: // 1020:2906
    stosw<ES_DI>(ax);
    di += 0x0026;
    if (--cx)
        goto loc_12b06;
    es = pop();
    di = pop();
    cx = pop();
    ax = pop();
}
void sub_12b11() // 1020:2911 +returnCarry
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    ax = 0x168f;
    ds = ax;
    if (memoryAGet16(ds, 0x5272) == 0x0000)
        goto loc_12b46;
    memoryASet16(ds, 0x5272, memoryAGet16(ds, 0x5272) - 1);
    ax = memoryAGet16(ds, 0x5276);
    ax--;
    if ((short)ax >= 0)
        goto loc_12b2e;
    ax = 0x000b;
loc_12b2e: // 1020:292e
    di = 0;
    memoryASet16(ds, 0x5276, ax);
    ax = memoryAGet16(ds, 0x5274);
    sub_12d67();
    ah = memoryAGet(ds, 0x5272);
    al = memoryAGet(ds, 0x5270);
    sub_12c0d();
    flags.carry = 0;
    goto loc_12b47;
loc_12b46: // 1020:2946
    flags.carry = 1;
loc_12b47: // 1020:2947
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12b4c() // 1020:294c +returnCarry
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    ax = 0x168f;
    ds = ax;
    al = memoryAGet(ds, 0x508b);
    ah = 0;
    ax -= 0x000c;
    if (memoryAGet16(ds, 0x5272) >= ax)
        goto loc_12b8e;
    memoryASet16(ds, 0x5272, memoryAGet16(ds, 0x5272) + 1);
    ax = memoryAGet16(ds, 0x5276);
    ax++;
    if (ax < 0x000c)
        goto loc_12b72;
    ax = 0;
loc_12b72: // 1020:2972
    di = 0x1b80;
    memoryASet16(ds, 0x5276, ax);
    ax = memoryAGet16(ds, 0x5274);
    sub_12d67();
    ah = memoryAGet(ds, 0x5272);
    al = memoryAGet(ds, 0x5270);
    ax += 0x0b00;
    sub_12c0d();
    flags.carry = 0;
    goto loc_12b8f;
loc_12b8e: // 1020:298e
    flags.carry = 1;
loc_12b8f: // 1020:298f
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12b94() // 1020:2994 +returnCarry
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    ax = 0x168f;
    ds = ax;
    di = 0;
    if (memoryAGet16(ds, 0x5270) == 0x0000)
        goto loc_12c07;
    memoryASet16(ds, 0x5270, memoryAGet16(ds, 0x5270) - 1);
    ax = memoryAGet16(ds, 0x5274);
    ax--;
    if ((short)ax >= 0)
        goto loc_12bf2;
    ax = 0x0013;
    goto loc_12bf2;
    // gap 61 bytes
loc_12bf2: // 1020:29f2
    memoryASet16(ds, 0x5274, ax);
    sub_12d67();
    ah = memoryAGet(ds, 0x5272);
    al = memoryAGet(ds, 0x5270);
    ax += di;
    sub_12cb1();
    flags.carry = 0;
    goto loc_12c08;
loc_12c07: // 1020:2a07
    flags.carry = 1;
loc_12c08: // 1020:2a08
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12bb5() // 1020:29b5 +returnCarry
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    ax = 0x168f;
    ds = ax;
    ax = memoryAGet16(ds, 0x527c);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax -= 0x0014;
    if ((short)memoryAGet16(ds, 0x7d3d) >= (short)ax)
        goto loc_12bd7;
    ax = 0x00ec;
    goto loc_12bda;
loc_12bd7: // 1020:29d7
    ax = memoryAGet16(ds, 0x7d3d);
loc_12bda: // 1020:29da
    if (memoryAGet16(ds, 0x5270) >= ax)
        goto loc_12c07;
    di = 0x0013;
    memoryASet16(ds, 0x5270, memoryAGet16(ds, 0x5270) + 1);
    ax = memoryAGet16(ds, 0x5274);
    ax++;
    if (ax < 0x0014)
        goto loc_12bf2;
    ax = 0;
loc_12bf2: // 1020:29f2
    memoryASet16(ds, 0x5274, ax);
    sub_12d67();
    ah = memoryAGet(ds, 0x5272);
    al = memoryAGet(ds, 0x5270);
    ax += di;
    sub_12cb1();
    flags.carry = 0;
    goto loc_12c08;
loc_12c07: // 1020:2a07
    flags.carry = 1;
loc_12c08: // 1020:2a08
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12c0d() // 1020:2a0d
{
    push(ax);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    push(ds);
    es = pop();
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_12c6c;
    sub_134f4();
    si = ax;
    di += memoryAGet16(ds, 0x5266);
    dx = memoryAGet16(ds, 0x5274);
    bx = 0x63e4;
    ds = memoryAGet16(ds, 0x526c);
    cx = 0x0014;
loc_12c36: // 1020:2a36
    if (di < 0x5c80)
        goto loc_12c40;
    di -= 0x1e00;
loc_12c40: // 1020:2a40
    al = lodsb<DS_SI>();
    ah = al;
    al = memoryAGet(es, bx+al);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | al);
    al = ah;
    push(es);
    bp = 0xa000;
    es = bp;
    sub_12ff5();
    es = pop();
    dx++;
    if (dx < 0x0014)
        goto loc_12c61;
    di -= 0x0028;
    dx = 0;
loc_12c61: // 1020:2a61
    if (--cx)
        goto loc_12c36;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    return;
loc_12c6c: // 1020:2a6c
    si = ax;
    di <<= 1;
    di += memoryAGet16(ds, 0x5266);
    dx = memoryAGet16(ds, 0x5274);
    bx = 0x63e4;
    ds = memoryAGet16(ds, 0x526c);
    cx = 0x0014;
loc_12c82: // 1020:2a82
    if (di < 0x3c00)
        goto loc_12c8c;
    di -= 0x3c00;
loc_12c8c: // 1020:2a8c
    al = lodsb<DS_SI>();
    ah = al;
    al = memoryAGet(es, bx+al);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | al);
    al = ah;
    sub_13053();
    dx++;
    if (dx < 0x0014)
        goto loc_12ca6;
    di -= 0x0050;
    dx = 0;
loc_12ca6: // 1020:2aa6
    if (--cx)
        goto loc_12c82;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_12cb1() // 1020:2ab1
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_12d0d;
    push(ds);
    push(es);
    push(ds);
    es = pop();
    sub_134f4();
    si = ax;
    ax = di;
    di <<= 1;
    di += memoryAGet16(ds, 0x5266);
    ax += memoryAGet16(ds, 0x5274);
    if (ax < 0x0014)
        goto loc_12cd6;
    di -= 0x0028;
loc_12cd6: // 1020:2ad6
    ds = memoryAGet16(ds, 0x526c);
    cx = 0x000c;
    bx = 0x63e4;
loc_12ce0: // 1020:2ae0
    if (di < 0x5c80)
        goto loc_12cea;
    di -= 0x1e00;
loc_12cea: // 1020:2aea
    al = lodsb<DS_SI>();
    ah = al;
    al = memoryAGet(es, bx+al);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | al);
    al = ah;
    push(es);
    dx = 0xa000;
    es = dx;
    sub_12ff5();
    es = pop();
    si += 0x00ff;
    di += 0x027e;
    if (--cx)
        goto loc_12ce0;
    es = pop();
    ds = pop();
    return;
loc_12d0d: // 1020:2b0d
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    push(ds);
    es = pop();
    si = ax;
    ax = di;
    di <<= 1;
    di <<= 1;
    di += memoryAGet16(ds, 0x5266);
    ax += memoryAGet16(ds, 0x5274);
    if (ax < 0x0014)
        goto loc_12d30;
    di -= 0x0050;
loc_12d30: // 1020:2b30
    ds = memoryAGet16(ds, 0x526c);
    cx = 0x000c;
    bx = 0x63e4;
loc_12d3a: // 1020:2b3a
    if (di < 0x3c00)
        goto loc_12d44;
    di -= 0x3c00;
loc_12d44: // 1020:2b44
    al = lodsb<DS_SI>();
    ah = al;
    al = memoryAGet(es, bx+al);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | al);
    al = ah;
    sub_13053();
    si += 0x00ff;
    di += 0x04fc;
    if (--cx)
        goto loc_12d3a;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_12d67() // 1020:2b67
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_12d88;
    ax <<= 1;
    dh = memoryAGet(ds, 0x5276);
    dl = 0;
    bx = dx;
    bx <<= 1;
    dx >>= 1;
    ax += dx;
    ax += bx;
    ax += 0x3e80;
    memoryASet16(ds, 0x5266, ax);
    return;
loc_12d88: // 1020:2b88
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = 0x0500;
    dl = memoryAGet(ds, 0x5276);
    dh = 0;
    mul16(dx);
    dx = pop();
    ax += dx;
    memoryASet16(ds, 0x5266, ax);
}
void sub_12da2() // 1020:2ba2
{
    goto loc_12da2;
loc_12d9f: // 1020:2b9f
    goto loc_12e7d;
loc_12da2: // 1020:2ba2
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    es = memoryAGet16(ds, 0x526c);
    sub_134f4();
    if (memoryAGet(ds, 0x64f5) == 0x00)
        goto loc_12d9f;
    if (memoryAGet(ds, 0x64fc) & 0x03)
        goto loc_12d9f;
    memoryASet(ds, 0x64f5, 0x00);
    ah = memoryAGet(ds, 0x5272);
    al = memoryAGet(ds, 0x5270);
    si = ax;
    ch = 0x0c;
    bh = 0;
    di = memoryAGet16(ds, 0x5266);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_12e32;
loc_12de3: // 1020:2be3
    dx = memoryAGet16(ds, 0x5274);
    cl = 0x14;
loc_12de9: // 1020:2be9
    bl = memoryAGet(es, si);
    if (memoryAGet(ds, bx + 25572) == 0x00)
        goto loc_12e11;
    memoryASet(ds, 0x64f5, 0x01);
    al = bl;
    bx = memoryAGet16(ds, 0x64f6);
    al = memoryAGet(ds, bx+al);
    bh = 0;
    if (di < 0x3c00)
        goto loc_12e0b;
    di -= 0x3c00;
loc_12e0b: // 1020:2c0b
    sub_13053();
    di -= 0x0004;
loc_12e11: // 1020:2c11
    dx++;
    if (dx < 0x0014)
        goto loc_12e1c;
    di -= 0x0050;
    dx = 0;
loc_12e1c: // 1020:2c1c
    di += 0x0004;
    si++;
    cl--;
    if (cl)
        goto loc_12de9;
    di += 0x0500;
    si += 0x00ec;
    ch--;
    if (ch)
        goto loc_12de3;
    goto loc_12e7d;
loc_12e32: // 1020:2c32
    dx = memoryAGet16(ds, 0x5274);
    cl = 0x14;
loc_12e38: // 1020:2c38
    bl = memoryAGet(es, si);
    if (memoryAGet(ds, bx + 25572) == 0x00)
        goto loc_12e5f;
    memoryASet(ds, 0x64f5, 0x01);
    al = bl;
    bx = memoryAGet16(ds, 0x64f6);
    al = memoryAGet(ds, bx+al);
    bh = 0;
    if (di < 0x5c80)
        goto loc_12e5a;
    di -= 0x1e00;
loc_12e5a: // 1020:2c5a
    sub_12fe8();
    di--;
    di--;
loc_12e5f: // 1020:2c5f
    dx++;
    if (dx < 0x0014)
        goto loc_12e6a;
    di -= 0x0028;
    dx = 0;
loc_12e6a: // 1020:2c6a
    di++;
    di++;
    si++;
    cl--;
    if (cl)
        goto loc_12e38;
    di += 0x0280;
    si += 0x00ec;
    ch--;
    if (ch)
        goto loc_12e32;
loc_12e7d: // 1020:2c7d
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_12e87() // 1020:2c87
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_12efb;
    push(bx);
    push(di);
    push(si);
    push(ds);
    push(es);
    sub_134f4();
    ax = 0x168f;
    ds = ax;
    si = memoryAGet16(ds, 0x5266);
    di = memoryAGet16(ds, 0x526a);
    dl = 0x14;
    dh = memoryAGet(ds, 0x5274);
    dl -= dh;
    dl <<= 1;
    dh <<= 1;
    bp = 0x000c;
    bp -= memoryAGet16(ds, 0x5276);
    cl = 0x04;
    bp <<= cl;
    ax = 0xa000;
    es = ax;
    ds = ax;
    ch = 0;
    ax = 0x0028;
    bx = 0x00c0;
    bx -= bp;
loc_12ecc: // 1020:2ccc
    cl = dl;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= ax;
    cl = dh;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si += ax;
    bp--;
    if (bp)
        goto loc_12ecc;
    if (!bx)
        goto loc_12ef5;
    si = 0x3e80;
    cl = dh;
    si += cx;
loc_12ee6: // 1020:2ce6
    cl = dl;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= ax;
    cl = dh;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si += ax;
    bx--;
    if (bx)
        goto loc_12ee6;
loc_12ef5: // 1020:2cf5
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bx = pop();
    return;
loc_12efb: // 1020:2cfb
    push(bx);
    push(di);
    push(si);
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    si = memoryAGet16(ds, 0x5266);
    di = 0;
    dl = 0x14;
    dh = memoryAGet(ds, 0x5274);
    dl -= dh;
    dl <<= 1;
    dh <<= 1;
    bp = 0x000c;
    bp -= memoryAGet16(ds, 0x5276);
    cl = 0x04;
    bp <<= cl;
    es = memoryAGet16(ds, 0x5262);
    ds = memoryAGet16(ds, 0x5264);
    ch = 0;
    ax = 0x0050;
    bx = 0x00c0;
    bx -= bp;
loc_12f34: // 1020:2d34
    cl = dl;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    si -= ax;
    cl = dh;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    si += ax;
    bp--;
    if (bp)
        goto loc_12f34;
    if (!bx)
        goto loc_12f5c;
    cl = dh;
    si = cx;
    si += cx;
loc_12f4d: // 1020:2d4d
    cl = dl;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    si -= ax;
    cl = dh;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    si += ax;
    bx--;
    if (bx)
        goto loc_12f4d;
loc_12f5c: // 1020:2d5c
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bx = pop();
}
void sub_12f62() // 1020:2d62
{
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    ax = 0;
    sub_12a11();
    memoryASet16(ds, 0x5270, ax);
    memoryASet16(ds, 0x5272, ax);
    memoryASet16(ds, 0x5274, ax);
    memoryASet16(ds, 0x5276, ax);
    sub_12d67();
    di = memoryAGet16(ds, 0x5266);
    es = memoryAGet16(ds, 0x526c);
    si = 0;
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_12faf;
    sub_134f4();
    ch = 0x0c;
loc_12f94: // 1020:2d94
    cl = 0x14;
loc_12f96: // 1020:2d96
    al = memoryAGet(es, si);
    sub_12fe8();
    si++;
    cl--;
    if (cl)
        goto loc_12f96;
    si += 0x00ec;
    di += 0x0258;
    ch--;
    if (ch)
        goto loc_12f94;
    goto loc_12fca;
loc_12faf: // 1020:2daf
    ch = 0x0c;
loc_12fb1: // 1020:2db1
    cl = 0x14;
loc_12fb3: // 1020:2db3
    al = memoryAGet(es, si);
    sub_13053();
    si++;
    cl--;
    if (cl)
        goto loc_12fb3;
    si += 0x00ec;
    di += 0x04b0;
    ch--;
    if (ch)
        goto loc_12fb1;
loc_12fca: // 1020:2dca
    sub_14146();
    al = memoryAGet(ds, 0x6521);
    al |= memoryAGet(ds, 0x6520);
    if (al)
        goto loc_12fca;
    sub_1296f();
    es = pop();
    ds = pop();
}
void sub_12fdc() // 1020:2ddc
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_13053;
    di += 0x3e80;
    push(dx);
    push(es);
    dx = 0xa000;
    es = dx;
    sub_12ff5();
    es = pop();
    dx = pop();
    return;
    // gap 94 bytes
loc_13053: // 1020:2e53
    push(si);
    push(ds);
    push(bp);
    push(es);
    ah = al;
    al = 0;
    ax >>= 1;
    si = ax;
    ax = 0x168f;
    ds = ax;
    es = memoryAGet16(ds, 0x5264);
    ds = memoryAGet16(cs, 0xb95e);
    bp = 0x004c;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di -= 0x04b0;
    es = pop();
    bp = pop();
    ds = pop();
    si = pop();
}
void sub_12fe8() // 1020:2de8
{
    push(dx);
    push(es);
    dx = 0xa000;
    es = dx;
    sub_12ff5();
    es = pop();
    dx = pop();
}
void sub_12ff5() // 1020:2df5
{
    push(si);
    push(ds);
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    si += 0x5dc0;
    push(es);
    ds = pop();
    bp = 0x0026;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += bp;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di -= 0x0258;
    ds = pop();
    si = pop();
}
void sub_13053() // 1020:2e53
{
    push(si);
    push(ds);
    push(bp);
    push(es);
    ah = al;
    al = 0;
    ax >>= 1;
    si = ax;
    ax = 0x168f;
    ds = ax;
    es = memoryAGet16(ds, 0x5264);
    ds = memoryAGet16(cs, 0xb95e);
    bp = 0x004c;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += bp;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di -= 0x04b0;
    es = pop();
    bp = pop();
    ds = pop();
    si = pop();
}
void sub_130b7() // 1020:2eb7
{
    push(ds);
    dx = 0x168f;
    ds = dx;
    es = dx;
    memoryASet(ds, 0x5250, al);
    al += 0x30;
    if (al <= 0x39)
        goto loc_130ca;
    al += 0x07;
loc_130ca: // 1020:2eca
    memoryASet(ds, 0x5256, al);
    di = 0x72a3;
    cx = 0x0bf4;
    al = 0xff;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    di = 0x527c;
    cx = 0x020a;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    sub_134dc();
    dx = 0x5251;
    sub_10b7b();
    memoryASet16(ds, 0x526c, ax);
    push(ax);
    ax = 0x168f;
    ds = ax;
    es = ax;
    al = memoryAGet(ds, 0x5250);
    ah = 0x03;
    mul8(ah);
    si = ax;
    si += 0x50c8;
    di = 0x5081;
    cx = 0x0003;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x5057;
    sub_10610();
    ax = pop();
    sub_13209();
    ax = 0x168f;
    es = ax;
    di = 0x72a3;
    cx = 0x0180;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cx = 0x00f0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cl = 0x03;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cx = 0x0514;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cx = 0x0190;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    cx = 0x008c;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cx = 0x00c8;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    sub_13176();
    sub_131dd();
    ax = memoryAGet16(ds, 0x7695);
    memoryASet16(ds, 0x64e4, ax);
    ax = memoryAGet16(ds, 0x7697);
    memoryASet16(ds, 0x64e6, ax);
    si = 0x7dcb;
    cx = 0x000a;
loc_13157: // 1020:2f57
    if (memoryAGet(es, si + 7) < 0x08)
        goto loc_13164;
    memoryASet16(es, si + 4, 0xffff);
loc_13164: // 1020:2f64
    si += 0x0014;
    if (--cx)
        goto loc_13157;
    si = 0x75a3;
    di = 0x7e97;
    cx = 0x08f4;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
}
void sub_13176() // 1020:2f76
{
    ax = 0x168f;
    ds = ax;
    bx = 0;
    cx = 0x0100;
    dl = 0;
loc_13182: // 1020:2f82
    if (memoryAGet(ds, bx + 29859) & 0x80)
        goto loc_1319c;
    memoryASet(ds, bx + 24804, bl);
    memoryASet(ds, bx + 25060, bl);
    memoryASet(ds, bx + 25316, bl);
    memoryASet(ds, bx + 25572, 0x00);
    goto loc_131d3;
loc_1319c: // 1020:2f9c
    dl = 0x01;
    al = bl;
    memoryASet(ds, bx + 24804, al);
    memoryASet(ds, bx + 25062, al);
    memoryASet(ds, bx + 25317, al);
    ax++;
    memoryASet(ds, bx + 24805, al);
    memoryASet(ds, bx + 25060, al);
    memoryASet(ds, bx + 25318, al);
    ax++;
    memoryASet(ds, bx + 24806, al);
    memoryASet(ds, bx + 25061, al);
    memoryASet(ds, bx + 25316, al);
    memoryASet(ds, bx + 25572, 0x01);
    memoryASet16(ds, bx + 25573, 0x0101);
    bx++;
    bx++;
loc_131d3: // 1020:2fd3
    bx++;
    if (!bh)
        goto loc_13182;
    memoryASet(ds, 0x64f5, dl);
}
void sub_131dd() // 1020:2fdd
{
    push(ax);
    push(cx);
    push(di);
    push(si);
    push(ds);
    push(es);
    ax = 0x168f;
    ds = ax;
    es = memoryAGet16(ds, 0x526c);
    si = 0x7bad;
    cx = 0x0064;
loc_131f2: // 1020:2ff2
    di = memoryAGet16(ds, si + 2);
    if (di == 0xffff)
        goto loc_131fd;
    al = memoryAGet(ds, si);
    stosb<ES_DI>(al);
loc_131fd: // 1020:2ffd
    si += 0x0004;
    if (--cx)
        goto loc_131f2;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    cx = pop();
    ax = pop();
}
void sub_13209() // 1020:3009
{
    bl = memoryAGet(ds, 0x5250);
    bh = memoryAGet(ds, bx + 20640);
    memoryASet(ds, 0x508b, bh);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        goto loc_13244;
    bl = 0;
    cl = 0x04;
    bx >>= cl;
    ax += bx;
    ds = ax;
    si = 0;
    memoryASet16(cs, 0xb95e, ax);
    memoryASet16(cs, 0x6676, 0x66b8);
    cx = 0x0100;
loc_13237: // 1020:3037
    ax = 0x0210;
    sub_167be();
    si += 0x0080;
    if (--cx)
        goto loc_13237;
    return;
loc_13244: // 1020:3044
    bl = 0;
    cl = 0x04;
    bx >>= cl;
    ax += bx;
    memoryASet16(ds, 0x04c1, ax);
    ds = ax;
    si = 0;
    ax = 0xa000;
    es = ax;
    di = 0x5dc0;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx++;
    bx = 0x0100;
loc_13265: // 1020:3065
    al = 0x01;
loc_13267: // 1020:3067
    out8(dx, al);
    cx = 0x0010;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di -= 0x0020;
    al <<= 1;
    if (al < 0x10)
        goto loc_13267;
    di += 0x0020;
    bx--;
    if (bx)
        goto loc_13265;
}
void sub_1327d() // 1020:307d
{
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(cs, 0x0001) == 0xff)
        goto loc_1328d;
    goto loc_13360;
loc_1328d: // 1020:308d
    ax = 0x000d;
    interrupt(0x10);
    dx = 0x03c8;
    al = 0x40;
    out8(dx, al);
    dx++;
    cx = 0x001e;
    si = 0x5057;
loc_1329f: // 1020:309f
    al = lodsb<DS_SI>();
    al &= 0x3f;
    out8(dx, al);
    if (--cx)
        goto loc_1329f;
    cx = 0x001e;
    si -= cx;
    al = 0x40;
    dl = 0xc7;
    out8(dx, al);
    dl = 0xc9;
loc_132b1: // 1020:30b1
    ah = memoryAGet(ds, si);
    si++;
    ah &= 0x3f;
    al = in8(dx);
    if (al != ah)
        goto loc_132ca;
    if (--cx)
        goto loc_132b1;
    sub_13326();
    if (flags.carry)
        goto loc_132e6;
    memoryASet(cs, 0x0001, 0x05);
    return;
loc_132ca: // 1020:30ca
    sub_13326();
    if (flags.carry)
        goto loc_132e6;
    memoryASet(cs, 0x0001, 0x04);
    ah = 0x12;
    bl = 0x10;
    interrupt(0x10);
    if (bl)
        goto loc_13325;
    memoryASet(cs, 0x0001, 0x03);
    return;
loc_132e6: // 1020:30e6
    ax = 0x0003;
    interrupt(0x10);
    ah = 0x0f;
    interrupt(0x10);
    if (ax == 0x5003)
        goto loc_132fb;
    memoryASet(cs, 0x0001, 0x00);
    return;
loc_132fb: // 1020:30fb
    memoryASet(cs, 0x0001, 0x02);
    ax = 0x0009;
    interrupt(0x10);
    ax = 0xb800;
    es = ax;
    memoryASet(es, 0x4000, 0xff);
    al = memoryAGet(es, 0x4000);
    ah = memoryAGet(es, 0x0000);
    if (ax == 0x00ff)
        goto loc_13325;
    memoryASet(cs, 0x0001, 0x01);
loc_13325: // 1020:3125
    return;
    // gap 58 bytes
loc_13360: // 1020:3160
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    al = memoryAGet(cs, 0x0001);
    if (al == 0x01)
        goto loc_133c5;
    if (al == 0x02)
        goto loc_133c5;
    if (al == 0x00)
        goto loc_133e9;
    ax = 0x168f;
    ds = ax;
    es = ax;
    ax = 0x000d;
    interrupt(0x10);
    dx = 0x03d4;
    ax = 0x2411;
    out16(dx, ax);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x526a, 0x1f40);
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_133a4;
    if (al >= 0x03)
        goto loc_133bb;
loc_133a4: // 1020:31a4
    dx = 0x5046;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x1012;
    bx = 0;
    cx = 0x0010;
    dx = 0x5057;
    interrupt(0x10);
    goto loc_133e7;
loc_133bb: // 1020:31bb
    dx = 0x5035;
    ax = 0x1002;
    interrupt(0x10);
    goto loc_133e7;
loc_133c5: // 1020:31c5
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    ax = 0x0004;
    interrupt(0x10);
loc_133e7: // 1020:31e7
    goto loc_13439;
loc_133e9: // 1020:31e9
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    si = 0x5025;
    dx = 0x03bf;
    al = 0x03;
    out8(dx, al);
    dl = 0xb8;
    al = 0x82;
    out8(dx, al);
    dl = 0xb4;
    cx = 0x000e;
    ax = 0;
loc_1341b: // 1020:321b
    al = ah;
    out8(dx, al);
    dx++;
    al = lodsb<DS_SI>();
    out8(dx, al);
    dx--;
    ah++;
    if (--cx)
        goto loc_1341b;
    cx = 0x2000;
    ax = 0xb800;
    es = ax;
    ax = 0;
    di = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    dl = 0xb8;
    al = 0x8a;
    out8(dx, al);
loc_13439: // 1020:3239
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_13326() // 1020:3126 +returnCarry
{
    ax = 0x000d;
    interrupt(0x10);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    dl = 0xce;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0004;
    out16(dx, ax);
    al = 0x51;
    memoryASet(es, 0x2000, al);
    if (memoryAGet(es, 0x2000) != al)
        goto loc_1335e;
    ax = 0x0103;
    out16(dx, ax);
    memoryASet(es, si, 0xaa);
    if (memoryAGet(es, si) != 0x55)
        goto loc_1335e;
    flags.carry = 0;
    return;
loc_1335e: // 1020:315e
    flags.carry = 1;
}
void sub_13360() // 1020:3160
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    al = memoryAGet(cs, 0x0001);
    if (al == 0x01)
        goto loc_133c5;
    if (al == 0x02)
        goto loc_133c5;
    if (al == 0x00)
        goto loc_133e9;
    ax = 0x168f;
    ds = ax;
    es = ax;
    ax = 0x000d;
    interrupt(0x10);
    dx = 0x03d4;
    ax = 0x2411;
    out16(dx, ax);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x526a, 0x1f40);
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_133a4;
    if (al >= 0x03)
        goto loc_133bb;
loc_133a4: // 1020:31a4
    dx = 0x5046;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x1012;
    bx = 0;
    cx = 0x0010;
    dx = 0x5057;
    interrupt(0x10);
    goto loc_133e7;
loc_133bb: // 1020:31bb
    dx = 0x5035;
    ax = 0x1002;
    interrupt(0x10);
    goto loc_133e7;
loc_133c5: // 1020:31c5
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    ax = 0x0004;
    interrupt(0x10);
loc_133e7: // 1020:31e7
    goto loc_13439;
loc_133e9: // 1020:31e9
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    si = 0x5025;
    dx = 0x03bf;
    al = 0x03;
    out8(dx, al);
    dl = 0xb8;
    al = 0x82;
    out8(dx, al);
    dl = 0xb4;
    cx = 0x000e;
    ax = 0;
loc_1341b: // 1020:321b
    al = ah;
    out8(dx, al);
    dx++;
    al = lodsb<DS_SI>();
    out8(dx, al);
    dx--;
    ah++;
    if (--cx)
        goto loc_1341b;
    cx = 0x2000;
    ax = 0xb800;
    es = ax;
    ax = 0;
    di = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    dl = 0xb8;
    al = 0x8a;
    out8(dx, al);
loc_13439: // 1020:3239
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_13443() // 1020:3243
{
    static int counter=0; if (counter++%4==0) sync(); return;
    push(ax);
    push(dx);
    if (memoryAGet(cs, 0x0001) == 0x00)
        goto loc_1345f;
    dx = 0x03da;
    ah = 0x08;
loc_13452: // 1020:3252
    al = in8(dx);
    if (ah & al)
        goto loc_13452;
loc_13457: // 1020:3257
    al = in8(dx);
    if (!(ah & al))
        goto loc_13457;
    dx = pop();
    ax = pop();
    return;
loc_1345f: // 1020:325f
    dx = 0x03ba;
    ah = 0x01;
loc_13464: // 1020:3264
    al = in8(dx);
    if (ah & al)
        goto loc_13464;
loc_13469: // 1020:3269
    al = in8(dx);
    if (!(ah & al))
        goto loc_13469;
    dx = pop();
    ax = pop();
}
void sub_13471() // 1020:3271
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_134a4;
    sub_112d3();
    dx = 0x03d4;
    ax = 0x168f;
    ds = ax;
    bx = memoryAGet16(ds, 0x526a);
    al = 0x0d;
    ah = bl;
    out16(dx, ax);
    ax--;
    ah = bh;
    out16(dx, ax);
    tx = memoryAGet16(ds, 0x5268); memoryASet16(ds, 0x5268, bx); bx = tx;
    memoryASet16(ds, 0x526a, bx);
    if (memoryAGet(ds, 0x651a) == 0x00)
        goto loc_134a3;
    sub_13443();
loc_134a3: // 1020:32a3
    return;
loc_134a4: // 1020:32a4
    push(ds);
    push(es);
    push(si);
    push(di);
    push(dx);
    push(ax);
    push(cx);
    ds = memoryAGet16(ds, 0x5262);
    si = 0;
    ax = 0xb800;
    es = ax;
    di = 0;
    dx = 0x0060;
    ax = 0x0028;
loc_134be: // 1020:32be
    cx = ax;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di += 0x1fb0;
    cx = ax;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di -= 0x2000;
    dx--;
    if (dx)
        goto loc_134be;
    sub_112d3();
    cx = pop();
    ax = pop();
    dx = pop();
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
}
void sub_134dc() // 1020:32dc
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_134f3;
    push(ax);
    push(dx);
    dx = 0x03ce;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0003;
    out16(dx, ax);
    dx = pop();
    ax = pop();
loc_134f3: // 1020:32f3
    return;
}
void sub_134f4() // 1020:32f4
{
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_1350d;
    push(ax);
    push(dx);
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    dl = 0xc4;
    ax = 0x0f02;
    out16(dx, ax);
    dx = pop();
    ax = pop();
loc_1350d: // 1020:330d
    return;
}
void sub_13811() // 1020:3611
{
    bx = memoryAGet16(ds, si + 12);
    bx++;
    bx++;
loc_13816: // 1020:3616
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= 0)
        goto loc_13820;
    bx += ax;
    goto loc_13816;
loc_13820: // 1020:3620
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 12, bx);
}
void sub_13827() // 1020:3627 +returnCarry
{
    goto loc_13827;
loc_1370e: // 1020:350e
    ax = 0x168f;
    ds = ax;
    es = ax;
    memoryASet(ds, 0x5250, 0x00);
    memoryASet(ds, 0x6518, 0x00);
    di = 0x527c;
    cx = 0x003a;
loc_13725: // 1020:3525
    memoryASet16(ds, di + 4, 0xffff);
    di += 0x0012;
    if (--cx)
        goto loc_13725;
    memoryASet16(ds, 0x5280, 0x0157);
    memoryASet16(ds, 0x527c, 0xff9c);
    memoryASet16(ds, 0x527e, 0x00b4);
    memoryASet16(ds, 0x5288, 0x6609);
    memoryASet16(ds, 0x52b6, 0x0151);
    memoryASet16(ds, 0x52b2, 0x01a4);
    memoryASet16(ds, 0x52b4, 0x00b4);
    memoryASet16(ds, 0x52be, 0x65e3);
loc_1375f: // 1020:355f
    sub_14146();
    sub_12da2();
    si = 0x527c;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 0x0003);
    sub_13811();
    si = 0x52b2;
    memoryASet16(ds, si, memoryAGet16(ds, si) - 0x0003);
    sub_13811();
    sub_12e87();
    sub_11e61();
    sub_13471();
    ax = memoryAGet16(ds, 0x527c);
    ax += 0x001c;
    if ((short)memoryAGet16(ds, 0x52b2) > (short)ax)
        goto loc_1375f;
    memoryASet16(ds, 0x52b6, 0x815a);
    memoryASet16(ds, 0x52b2, memoryAGet16(ds, 0x52b2) - 0x0018);
    si = 0x527c;
    memoryASet16(ds, 0x5288, 0x661d);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) - 0x0010);
    cx = 0x0010;
loc_137a8: // 1020:35a8
    push(cx);
    sub_13811();
    sub_14146();
    sub_12da2();
    sub_12e87();
    sub_11e61();
    sub_13471();
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 1);
    cx = pop();
    if (--cx)
        goto loc_137a8;
    memoryASet16(ds, 0x5280, 0x0163);
    si = 0x663f;
loc_137cb: // 1020:35cb
    al = lodsb<DS_SI>();
    ah = 0;
    memoryASet16(ds, 0x527c, ax);
    al = lodsb<DS_SI>();
    ah = 0;
    memoryASet16(ds, 0x527e, ax);
    push(si);
    sub_14146();
    sub_12da2();
    sub_12e87();
    sub_11e61();
    sub_13471();
    sub_10a05();
    si = pop();
    if (memoryAGet(ds, 0x042b) != 0x00)
        goto loc_137fd;
    ax = memoryAGet16(ds, si);
    if (ax != 0xffdc)
        goto loc_137cb;
    si += ax;
    goto loc_137cb;
loc_137fd: // 1020:35fd
    ax = 0x014f;
    dx = 0x0150;
    si = 0x527c;
    sub_1392f();
    sub_11c59();
    ax = 0x0001;
    flags.carry = 1;
    return;
    // gap 22 bytes
loc_13827: // 1020:3627
    ax = 0;
    if (memoryAGet(ds, 0x6519) == 0x01)
        goto loc_1384e;
    ax++;
    if (memoryAGet(ds, 0x6517) != 0x01)
        goto loc_1383b;
    goto loc_13910;
loc_1383b: // 1020:363b
    if (memoryAGet(ds, 0x6516) == 0x01)
        goto loc_13860;
    if (memoryAGet(ds, 0x6518) != 0x01)
        goto loc_1384c;
    goto loc_1370e;
loc_1384c: // 1020:364c
    flags.carry = 0;
    return;
loc_1384e: // 1020:364e
    sub_10373();
    memoryASet(ds, 0x0419, 0x10);
    sub_1398d();
    ax = 0;
    memoryASet16(ds, 0x64fa, ax);
    flags.carry = 1;
    return;
loc_13860: // 1020:3660
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x0001;
    sub_112ff();
    sub_14ce9();
    memoryASet16(ds, 0x5280, 0x000d);
    memoryASet16(ds, 0x528a, 0x000f);
    cx = 0x003c;
loc_13881: // 1020:3681
    push(cx);
    sub_12e87();
    sub_13bc7();
    sub_11e61();
    sub_13471();
    sub_13443();
    ax = memoryAGet16(ds, 0x528a);
    ax--;
    if ((short)ax >= (short)0xfff0)
        goto loc_1389d;
    ax = 0xfff0;
loc_1389d: // 1020:369d
    memoryASet16(ds, 0x528a, ax);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) - ax);
    cx = pop();
    if (--cx)
        goto loc_13881;
    sub_1398d();
    ax = memoryAGet16(ds, 0x64e4);
    memoryASet16(ds, 0x527c, ax);
    ax = memoryAGet16(ds, 0x64e6);
    memoryASet16(ds, 0x527e, ax);
    if (memoryAGet16(ds, 0x64fa) == 0x0000)
        goto loc_138e3;
    si = 0x52a0;
    cx = 0x0028;
loc_138c3: // 1020:36c3
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx -= 0x0038;
    if (bx > 0x0001)
        goto loc_138de;
    ax = memoryAGet16(ds, 0x64f8);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, 0x64fa);
    memoryASet16(ds, si + 2, ax);
    goto loc_138e3;
loc_138de: // 1020:36de
    si += 0x0012;
    if (--cx)
        goto loc_138c3;
loc_138e3: // 1020:36e3
    memoryASet(ds, 0x0419, 0x10);
    sub_119eb();
    ax = 0x0000;
    sub_112ff();
    sub_103d9();
    bl = memoryAGet(ds, 0x5250);
    bh = 0;
    al = memoryAGet(ds, bx + 20620);
    cbw();
    sub_112ff();
    sub_12f62();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    flags.carry = 0;
    return;
loc_13910: // 1020:3710
    ax = 0x0002;
    sub_112ff();
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, 0x00);
    memoryASet16(ds, 0x5280, 0x000d);
    si = 0x528e;
    ax = 0x014d;
    dx = 0x014e;
    di = si + 18;
    cl = 0x04;
    memoryASet16(ds, si + 4, ax);
    ax = memoryAGet16(ds, 0x5270);
    ax <<= cl;
    ax -= 0x0076;
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, 0x5272);
    ax <<= cl;
    ax += 0x0064;
    memoryASet16(ds, si + 2, ax);
    memoryASet16(ds, di + 4, dx);
    ax = memoryAGet16(ds, 0x5270);
    ax <<= cl;
    ax += 0x01b6;
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, 0x5272);
    ax <<= cl;
    ax += 0x0064;
    memoryASet16(ds, di + 2, ax);
    cx = 0x001f;
loc_13967: // 1020:3767
    push(cx);
    sub_12e87();
    sub_11e61();
    sub_13471();
    cx = pop();
    memoryASet16(ds, si, memoryAGet16(ds, si) + 0x0008);
    memoryASet16(ds, di, memoryAGet16(ds, di) - 0x0008);
    if (--cx)
        goto loc_13967;
    sub_11c2a();
    memoryASet(ds, 0x5250, 0x00);
    memoryASet16(ds, 0x64fa, 0x0000);
    ax = 0x0001;
    flags.carry = 1;
}
void sub_1392f() // 1020:372f
{
    di = si + 18;
    cl = 0x04;
    memoryASet16(ds, si + 4, ax);
    ax = memoryAGet16(ds, 0x5270);
    ax <<= cl;
    ax -= 0x0076;
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, 0x5272);
    ax <<= cl;
    ax += 0x0064;
    memoryASet16(ds, si + 2, ax);
    memoryASet16(ds, di + 4, dx);
    ax = memoryAGet16(ds, 0x5270);
    ax <<= cl;
    ax += 0x01b6;
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, 0x5272);
    ax <<= cl;
    ax += 0x0064;
    memoryASet16(ds, di + 2, ax);
    cx = 0x001f;
loc_13967: // 1020:3767
    push(cx);
    sub_12e87();
    sub_11e61();
    sub_13471();
    cx = pop();
    memoryASet16(ds, si, memoryAGet16(ds, si) + 0x0008);
    memoryASet16(ds, di, memoryAGet16(ds, di) - 0x0008);
    if (--cx)
        goto loc_13967;
    sub_11c2a();
    memoryASet(ds, 0x5250, 0x00);
    memoryASet16(ds, 0x64fa, 0x0000);
    ax = 0x0001;
    flags.carry = 1;
}
void sub_1398d() // 1020:378d
{
    push(ax);
    ax = 0x168f;
    ds = ax;
    es = ax;
    di = 0x64fc;
    cx = 0x002b;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    si = 0x7e97;
    di = 0x75a3;
    cx = 0x08f4;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    memoryASet(ds, 0x6504, al);
    memoryASet(ds, 0x6510, al);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x650d, al);
    memoryASet(ds, 0x6512, al);
    memoryASet(ds, 0x6514, al);
    memoryASet(ds, 0x6513, al);
    memoryASet(ds, 0x6505, al);
    memoryASet(ds, 0x650a, al);
    memoryASet(ds, 0x6509, al);
    memoryASet(ds, 0x6502, al);
    memoryASet(ds, 0x6517, al);
    memoryASet(ds, 0x6519, al);
    memoryASet(ds, 0x6516, al);
    memoryASet(ds, 0x651b, al);
    memoryASet(ds, 0x6500, al);
    ax = 0xffff;
    si = 0x5600;
    cx = 0x0004;
loc_139e5: // 1020:37e5
    memoryASet16(ds, si + 4, ax);
    si += 0x0012;
    if (--cx)
        goto loc_139e5;
    sub_158cc();
    sub_140e8();
    ax = pop();
}
void sub_139f5() // 1020:37f5
{
    if (memoryAGet(ds, 0x5287) != 0x00)
        goto loc_13a20;
    if (memoryAGet(ds, 0x651c) != 0x01)
        goto loc_13a20;
    if (memoryAGet16(ds, 0x651e) < 0x008c)
        goto loc_13a20;
    al = 0x1d;
    if (memoryAGet16(ds, 0x651e) < 0x00af)
        goto loc_13a1d;
    al = 0;
    memoryASet16(ds, 0x651e, 0x0000);
loc_13a1d: // 1020:381d
    memoryASet(ds, 0x5280, al);
loc_13a20: // 1020:3820
    si = 0x528e;
    cx = 0x0029;
    bx = memoryAGet16(ds, 0x64fe);
loc_13a2a: // 1020:382a
    ax = memoryAGet16(ds, si + 4);
    if (!(ah & 0x20))
        goto loc_13aab;
    if (ax == 0xffff)
        goto loc_13aab;
    if (bl & 0x07)
        goto loc_13a6f;
    dl = al;
    dl -= 0x38;
    if (!dl)
        goto loc_13a4f;
    if (dl > 0x01)
        goto loc_13a5a;
    if (memoryAGet(ds, 0x64fe) & 0x3f)
        goto loc_13aab;
loc_13a4f: // 1020:384f
    dl ^= 0x01;
    dl += 0x38;
    memoryASet(ds, si + 4, dl);
    goto loc_13aab;
loc_13a5a: // 1020:385a
    dl = al;
    dl -= 0x33;
    if (dl > 0x01)
        goto loc_13a6f;
    dl ^= 0x01;
    dl += 0x33;
    memoryASet(ds, si + 4, dl);
    goto loc_13aab;
loc_13a6f: // 1020:386f
    if (bl & 0x01)
        goto loc_13aab;
    dl = al;
    dl -= 0x36;
    if (dl > 0x01)
        goto loc_13aab;
    dl = 0x37;
    if (memoryAGet(ds, si + 8) == 0x00)
        goto loc_13aa6;
    dh = 0x01;
    if (memoryAGet(ds, 0x6511) <= 0x01)
        goto loc_13a91;
    dh = 0;
loc_13a91: // 1020:3891
    memoryASet(ds, si + 8, memoryAGet(ds, si + 8) & dh);
    dl--;
    if (al == 0x36)
        goto loc_13aa6;
    di = memoryAGet16(ds, si + 9);
    memoryASet16(ds, di + 2, memoryAGet16(ds, di + 2) + 0x0005);
    memoryASet(ds, 0x6511, 0x03);
loc_13aa6: // 1020:38a6
    memoryASet(ds, si + 4, dl);
    goto loc_13aab;
loc_13aab: // 1020:38ab
    si += 0x0012;
    cx--;
    if (!cx)
        goto loc_13ab4;
    goto loc_13a2a;
loc_13ab4: // 1020:38b4
    return;
}
void sub_13ab5() // 1020:38b5
{
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(ds, 0x64fd) != 0x00)
        goto loc_13b37;
    if (memoryAGet(ds, 0x5250) != 0x09)
        goto loc_13ad6;
    ax = memoryAGet16(ds, 0x5292);
    ah &= 0x1f;
    ax -= 0x0038;
    if (ax > 0x0001)
        goto loc_13b37;
loc_13ad6: // 1020:38d6
    if (memoryAGet(ds, 0x5250) != 0x10)
        goto loc_13ae2;
    memoryASet(ds, 0x6518, 0x01);
loc_13ae2: // 1020:38e2
    ax = memoryAGet16(ds, 0x527c);
    al &= 0xf0;
    if (memoryAGet16(ds, 0x7e93) == ax)
        goto loc_13af6;
    ax -= 0x0010;
    if (memoryAGet16(ds, 0x7e93) != ax)
        goto loc_13b37;
loc_13af6: // 1020:38f6
    ax = memoryAGet16(ds, 0x527e);
    al &= 0xf0;
    if (memoryAGet16(ds, 0x7e95) == ax)
        goto loc_13b0a;
    ax -= 0x0010;
    if (memoryAGet16(ds, 0x7e95) != ax)
        goto loc_13b37;
loc_13b0a: // 1020:390a
    ax = 0x0004;
    sub_112ff();
    sub_119eb();
    sub_12a11();
    bl = memoryAGet(ds, 0x5250);
    bh = 0;
    si = 0x523c;
    al = memoryAGet(ds, bx + si);
    ax++;
loc_13b22: // 1020:3922
    if (memoryAGet(ds, si) == al)
        goto loc_13b29;
    si++;
    goto loc_13b22;
loc_13b29: // 1020:3929
    ax = si;
    ax -= 0x523c;
    memoryASet(ds, 0x5250, al);
    memoryASet(ds, 0x6519, 0x01);
    return;
loc_13b37: // 1020:3937
    if (memoryAGet(ds, 0x6510) == 0x00)
        goto loc_13b5d;
    cl = 0x04;
    ax = memoryAGet16(ds, 0x527e);
    ax = sar16(ax, cl);
    dh = al;
    ax = memoryAGet16(ds, 0x527c);
    ax = sar16(ax, cl);
    dl = al;
    si = 0x7d3f;
    cx = 0x0014;
loc_13b54: // 1020:3954
    if (memoryAGet16(ds, si) == dx)
        goto loc_13b5e;
    si += 0x0007;
    if (--cx)
        goto loc_13b54;
loc_13b5d: // 1020:395d
    return;
loc_13b5e: // 1020:395e
    memoryASet16(ds, 0x5282, 0x0000);
    memoryASet16(ds, 0x528a, 0x0000);
    sub_12a11();
    push(memoryAGet16(ds, 0x7d3d));
    push(si);
    memoryASet16(ds, 0x7d3d, 0x00ec);
    ax = memoryAGet16(ds, si + 4);
    cl = 0x04;
    dl = al;
    dh = 0;
    dx <<= cl;
    memoryASet16(ds, 0x527c, dx);
    dl = ah;
    dh = 0;
    dx <<= cl;
    memoryASet16(ds, 0x527e, dx);
    ax = memoryAGet16(ds, si + 2);
loc_13b94: // 1020:3994
    if (memoryAGet(ds, 0x5272) == ah)
        goto loc_13ba6;
    if (memoryAGet(ds, 0x5272) < ah)
        goto loc_13ba1;
    sub_12b11();
    goto loc_13b94;
loc_13ba1: // 1020:39a1
    sub_12b4c();
    goto loc_13b94;
loc_13ba6: // 1020:39a6
    if (memoryAGet(ds, 0x5270) == al)
        goto loc_13bb8;
    if (memoryAGet(ds, 0x5270) < al)
        goto loc_13bb3;
    sub_12b94();
    goto loc_13ba6;
loc_13bb3: // 1020:39b3
    sub_12bb5();
    goto loc_13ba6;
loc_13bb8: // 1020:39b8
    si = pop();
    memoryASet16(ds, 0x7d3d, pop());
    al = memoryAGet(ds, si + 6);
    memoryASet(ds, 0x6502, al);
    sub_1296f();
}
void sub_13bc7() // 1020:39c7
{
    bool temp_cond0;
    bool temp_cond1;

    if (memoryAGet(ds, 0x6511) != 0x00)
        goto loc_13bd1;
    goto loc_13f96;
loc_13bd1: // 1020:39d1
    es = memoryAGet16(ds, 0x526c);
    memoryASet16(ds, 0x64eb, 0x0028);
    si = 0x52a0;
    cl = 0x04;
loc_13be0: // 1020:39e0
    if (memoryAGet16(ds, si + 4) != 0xffff)
        goto loc_13be9;
    goto loc_13f8a;
loc_13be9: // 1020:39e9
    ax = memoryAGet16(ds, si);
    if ((short)ax > (short)0x0008)
        goto loc_13bfa;
    memoryASet16(ds, si + 6, 0x0020);
    memoryASet16(ds, si + 14, 0x0000);
loc_13bfa: // 1020:39fa
    if ((short)ax < (short)0x0ff8)
        goto loc_13c09;
    memoryASet16(ds, si + 6, 0xffe0);
    memoryASet16(ds, si + 14, 0x0000);
loc_13c09: // 1020:3a09
    ah = memoryAGet(ds, si + 4);
    al = ah;
    if (memoryAGet16(ds, 0x64fe) & 0x0003)
        goto loc_13c42;
    if ((short)memoryAGet16(ds, si + 14) <= (short)0x0000)
        goto loc_13c42;
    if (memoryAGet(ds, 0x6503) == 0x02)
        goto loc_13c42;
    al -= 0x31;
    if (!al)
        goto loc_13c30;
    al--;
    if (al)
        goto loc_13c42;
    memoryASet16(ds, si + 6, 0x0000);
loc_13c30: // 1020:3a30
    memoryASet16(ds, si + 6, sar16(memoryAGet16(ds, si + 6), 0x0001));
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + 1);
    memoryASet(ds, 0x6503, 0x01);
    memoryASet(ds, 0x6504, 0xc8);
    goto loc_13c85;
loc_13c42: // 1020:3a42
    ah -= 0x33;
    if (ah > 0x01)
        goto loc_13c85;
    memoryASet(ds, 0x6511, 0x04);
    if (memoryAGet(ds, 0x6503) == 0x00)
        goto loc_13c6f;
    dx = 0;
    memoryASet16(ds, si + 12, dx);
    ax = memoryAGet16(ds, 0x527e);
    ax -= 0x0008;
    if (memoryAGet16(ds, si + 2) == ax)
        goto loc_13c6c;
    dl = 0x10;
    if ((short)memoryAGet16(ds, si + 2) < (short)ax)
        goto loc_13c6c;
    dx = -dx;
loc_13c6c: // 1020:3a6c
    memoryASet16(ds, si + 14, dx);
loc_13c6f: // 1020:3a6f
    if (memoryAGet(ds, 0x6504) != 0x00)
        goto loc_13c85;
    memoryASet16(ds, si + 4, 0x0031);
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet(ds, 0x6503, 0x02);
loc_13c85: // 1020:3a85
    if (memoryAGet16(ds, si + 6) != 0x0000)
        goto loc_13c8e;
    goto loc_13d25;
loc_13c8e: // 1020:3a8e
    ax = memoryAGet16(ds, si + 2);
    ax = sar16(ax, cl);
    if (memoryAGet(ds, si + 2) & 0x0f)
        goto loc_13c9a;
    ax--;
loc_13c9a: // 1020:3a9a
    tl = al; al = ah; ah = tl;
    di = memoryAGet16(ds, si);
    di = sar16(di, cl);
    di += ax;
    bx = 0x72a3;
    al = memoryAGet(es, di);
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (al)
        goto loc_13cde;
    ax = memoryAGet16(ds, si);
    dx = memoryAGet16(ds, si + 6);
    dx = sar16(dx, cl);
    dx += ax;
    dx = sar16(dx, cl);
    ax = sar16(ax, cl);
    if (ax == dx)
        goto loc_13ce8;
    ax = 0x0001;
    if (!(memoryAGet(ds, si + 7) & 0x80))
        goto loc_13cc9;
    ax = -ax;
loc_13cc9: // 1020:3ac9
    di += ax;
    dx = memoryAGet16(ds, si);
    dx = sar16(dx, cl);
    ax += dx;
    if (ax >= 0x0100)
        goto loc_13cde;
    al = memoryAGet(es, di);
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_13ce8;
loc_13cde: // 1020:3ade
    memoryASet16(ds, si + 6, -memoryAGet16(ds, si + 6));
    ax = memoryAGet16(ds, si + 6);
    ax = sar16(ax, cl);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
loc_13ce8: // 1020:3ae8
    memoryASet(ds, 0x6511, 0x04);
    ax = memoryAGet16(ds, si + 14);
    if ((short)ax >= 0)
        goto loc_13cf6;
    ax = -ax;
loc_13cf6: // 1020:3af6
    dx = 0x0003;
    if (ax < 0x0010)
        goto loc_13d00;
    dl = 0x01;
loc_13d00: // 1020:3b00
    ax = memoryAGet16(ds, si + 6);
    if ((short)ax >= 0)
        goto loc_13d09;
    dx = -dx;
loc_13d09: // 1020:3b09
    bp = ax;
    ax = sar16(ax, cl);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    ax = bp;
    ax -= dx;
    dx = ax;
    if ((short)ax >= 0)
        goto loc_13d1b;
    ax = -ax;
loc_13d1b: // 1020:3b1b
    if (ax >= 0x0010)
        goto loc_13d22;
    dx = 0;
loc_13d22: // 1020:3b22
    memoryASet16(ds, si + 6, dx);
loc_13d25: // 1020:3b25
    ax = memoryAGet16(ds, si + 2);
    ax = sar16(ax, cl);
    memoryASet16(ds, 0x64ed, ax);
    tl = al; al = ah; ah = tl;
    di = memoryAGet16(ds, si);
    di = sar16(di, cl);
    di += ax;
    if ((short)memoryAGet16(ds, si + 14) >= (short)0x0000)
        goto loc_13d8a;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    al = memoryAGet(ds, bx + 27640);
    al >>= cl;
    cbw();
    ax++;
    tl = al; al = ah; ah = tl;
    di -= ax;
    bx = 0x74a3;
    al = memoryAGet(es, di);
    al = memoryAGet(ds, bx+al);
    al &= 0x7f;
    if (al)
        goto loc_13d78;
    ax = memoryAGet16(ds, si + 14);
    ax = sar16(ax, cl);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x64ed);
    if (ax)
        goto loc_13d6b;
    goto loc_13f5a;
loc_13d6b: // 1020:3b6b
    al = memoryAGet(es, di + 65280);
    al = memoryAGet(ds, bx+al);
    al &= 0x7f;
    if (al)
        goto loc_13d78;
    goto loc_13f5a;
loc_13d78: // 1020:3b78
    memoryASet16(ds, si + 14, 0x0000);
    push(si);
    sub_15333();
    if (!flags.zero)
        goto loc_13d87;
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
loc_13d87: // 1020:3b87
    goto loc_13f8a;
loc_13d8a: // 1020:3b8a
    ax = memoryAGet16(ds, si + 4);
    dx = ax;
    dh &= 0x1f;
    if (memoryAGet(ds, si + 11) & 0x01)
        goto loc_13da8;
    bx = dx;
    if (!(memoryAGet(ds, bx + 28441) & 0x08))
        goto loc_13db8;
    if ((short)memoryAGet16(ds, si + 14) < (short)0x00a0)
        goto loc_13db8;
loc_13da8: // 1020:3ba8
    if (!(ah & 0x20))
        goto loc_13db0;
    goto loc_13f5a;
loc_13db0: // 1020:3bb0
    memoryASet16(ds, si + 4, 0xffff);
    goto loc_13f8a;
loc_13db8: // 1020:3bb8
    bx = 0x72a3;
    al = memoryAGet(es, di);
    ah = al;
    al = memoryAGet(ds, bx+al);
    tl = ah; ah = al; al = tl;
    bx = 0x73a3;
    al = memoryAGet(ds, bx+al);
    if ((short)memoryAGet16(ds, si + 2) > (short)0x0006)
        goto loc_13dd1;
    al = 0;
    goto loc_13de8;
loc_13dd1: // 1020:3bd1
    dl = memoryAGet(ds, 0x508b);
    dh = 0;
    dx <<= cl;
    if ((short)memoryAGet16(ds, si + 2) < (short)dx)
        goto loc_13de8;
    al = 0;
    dx += 0x0040;
    if ((short)memoryAGet16(ds, si + 2) >= (short)dx)
        goto loc_13dfe;
loc_13de8: // 1020:3be8
    if (al == 0x09)
        goto loc_13dfe;
    if (al != 0x08)
        goto loc_13e03;
    dx = memoryAGet16(ds, si + 4);
    dh &= 0x1f;
    if (dx != 0x0027)
        goto loc_13dfe;
    goto loc_13d78;
loc_13dfe: // 1020:3bfe
    memoryASet16(ds, si + 4, 0xffff);
loc_13e03: // 1020:3c03
    if (al == 0x06)
        goto loc_13e13;
    ah &= 0x01;
    al |= ah;
    al &= 0x07;
    if (!al)
        goto loc_13e13;
    goto loc_13d78;
loc_13e13: // 1020:3c13
    dx = memoryAGet16(ds, si + 14);
    dx = sar16(dx, cl);
    dx += memoryAGet16(ds, si + 2);
    dx = sar16(dx, cl);
    dx -= memoryAGet16(ds, 0x64ed);
    if (!dx)
        goto loc_13e70;
    memoryASet16(ds, 0x64ed, dx);
    push(bx);
    bx = memoryAGet16(ds, si + 4);
    sub_15245();
    bx = pop();
    if (flags.carry)
        goto loc_13e7b;
    dx = memoryAGet16(ds, 0x64ed);
loc_13e35: // 1020:3c35
    di += 0x0100;
    al = memoryAGet(es, di);
    push(bx);
    bx = 0x72a3;
    ah = al;
    al = memoryAGet(ds, bx+al);
    tl = ah; ah = al; al = tl;
    bx = pop();
    al = memoryAGet(ds, bx+al);
    if (al == 0x09)
        goto loc_13dfe;
    if (al != 0x08)
        goto loc_13e5d;
    dx = memoryAGet16(ds, si + 4);
    dh &= 0x1f;
    if (dx != 0x0027)
        goto loc_13e5d;
    goto loc_13eed;
loc_13e5d: // 1020:3c5d
    if (al == 0x06)
        goto loc_13e6d;
    ah &= 0x01;
    al |= ah;
    al &= 0x07;
    if (!al)
        goto loc_13e6d;
    goto loc_13eed;
loc_13e6d: // 1020:3c6d
    dx--;
    if (dx)
        goto loc_13e35;
loc_13e70: // 1020:3c70
    bx = memoryAGet16(ds, si + 4);
    sub_15245();
    if (flags.carry)
        goto loc_13e7b;
    goto loc_13f5a;
loc_13e7b: // 1020:3c7b
    memoryASet16(ds, si + 12, 0x0000);
    di = ax;
    push(si);
    sub_15333();
    if (!flags.zero)
        goto loc_13ed4;
    push(di);
    sub_15333();
    if (!flags.zero)
        goto loc_13e9e;
    memoryASet16(ds, si + 2, dx);
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    goto loc_13f8a;
loc_13e9e: // 1020:3c9e
    memoryASet(ds, di + 8, memoryAGet(ds, di + 8) | 0x01);
    memoryASet16(ds, di + 9, si);
    ax = memoryAGet16(ds, si + 14);
    ax = -ax;
    ax = sar16(ax, 0x0001);
    bx = ax;
    ax += 0x0010;
    if ((short)ax >= 0)
        goto loc_13eb8;
    bx += 0x0020;
    if ((short)bx < 0)
        goto loc_13ec3;
loc_13eb8: // 1020:3cb8
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet16(ds, si + 2, dx);
    goto loc_13f8a;
loc_13ec3: // 1020:3cc3
    memoryASet16(ds, di + 14, bx);
    memoryASet16(ds, si + 14, ax);
    ax = memoryAGet16(ds, si + 6);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, di + 6, ax);
    goto loc_13f5a;
loc_13ed4: // 1020:3cd4
    push(di);
    sub_15333();
    if (!flags.zero)
        goto loc_13eeb;
    memoryASet16(ds, si + 2, dx);
    if (memoryAGet16(ds, si + 14) >= 0x0010)
        goto loc_13f3f;
    memoryASet16(ds, si + 14, 0x0000);
    goto loc_13f8a;
loc_13eeb: // 1020:3ceb
    goto loc_13e9e;
loc_13eed: // 1020:3ced
    push(si);
    sub_15333();
    if (!flags.zero)
        goto loc_13f37;
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 0x0010);
    al = memoryAGet(ds, si + 4);
    al -= 0x31;
    if (al > 0x03)
        goto loc_13f12;
    memoryASet(ds, si + 4, 0x31);
    memoryASet(ds, 0x6503, 0x00);
loc_13f12: // 1020:3d12
    if (!(memoryAGet(ds, si + 5) & 0x20))
        goto loc_13f8a;
    if (memoryAGet16(ds, 0x5292) != 0xffff)
        goto loc_13f8a;
    memoryASet(ds, 0x6505, 0x20);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x5290, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0x528e, ax);
    memoryASet16(ds, 0x5292, 0x002e);
    goto loc_13f8a;
loc_13f37: // 1020:3d37
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 0x0010);
loc_13f3f: // 1020:3d3f
    memoryASet(ds, 0x6511, 0x04);
    memoryASet16(ds, si + 12, 0x0000);
    ax = memoryAGet16(ds, si + 14);
    ax = -ax;
    temp_cond0 = (short)ax + (short)0x0030 < 0;
    ax += 0x0030;
    if (temp_cond0)
        goto loc_13f55;
    ax = 0;
loc_13f55: // 1020:3d55
    memoryASet16(ds, si + 14, ax);
    goto loc_13f8a;
loc_13f5a: // 1020:3d5a
    dl = 0x0f;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    if (bl >= 0x65)
        goto loc_13f6b;
    dl = memoryAGet(ds, bx + 28512);
loc_13f6b: // 1020:3d6b
    ax = memoryAGet16(ds, si + 14);
    ax = sar16(ax, cl);
    if (!ax)
        goto loc_13f77;
    memoryASet(ds, 0x6511, 0x04);
loc_13f77: // 1020:3d77
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if ((char)al >= (char)dl)
        goto loc_13f87;
    temp_cond1 = (short)memoryAGet16(ds, si + 14) + (short)0x0010 <= 0;
    memoryASet16(ds, si + 14, memoryAGet16(ds, si + 14) + 0x0010);
    if (temp_cond1)
        goto loc_13f87;
    memoryASet16(ds, si + 12, memoryAGet16(ds, si + 12) + 1);
loc_13f87: // 1020:3d87
    sub_13f97();
loc_13f8a: // 1020:3d8a
    si += 0x0012;
    memoryASet16(ds, 0x64eb, memoryAGet16(ds, 0x64eb) - 1);
    if (!memoryAGet16(ds, 0x64eb))
        goto loc_13f96;
    goto loc_13be0;
loc_13f96: // 1020:3d96
    return;
}
void sub_13f97() // 1020:3d97
{
    push(ax);
    push(bx);
    push(dx);
    if (memoryAGet16(ds, si + 12) >= 0x000a)
        goto loc_13fa3;
    goto loc_14024;
loc_13fa3: // 1020:3da3
    if ((short)memoryAGet16(ds, 0x528a) >= (short)0x00c0)
        goto loc_14024;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_13fb5;
    ax = -ax;
loc_13fb5: // 1020:3db5
    if (ax >= 0x0020)
        goto loc_14024;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_13fc3;
    ax = -ax;
loc_13fc3: // 1020:3dc3
    if (ax >= 0x0020)
        goto loc_14024;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27639);
    ax = memoryAGet16(ds, si);
    dx = memoryAGet16(ds, 0x527c);
    if ((short)ax <= (short)dx)
        goto loc_13fe1;
    tx = dx; dx = ax; ax = tx;
    bl = 0x18;
loc_13fe1: // 1020:3de1
    bh = 0;
    ax += bx;
    if ((short)ax < (short)dx)
        goto loc_14024;
    ax = memoryAGet16(ds, si + 2);
    dx = memoryAGet16(ds, 0x527e);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27640);
    bl--;
    if ((short)ax >= (short)dx)
        goto loc_14005;
    tx = dx; dx = ax; ax = tx;
    bl = 0x20;
loc_14005: // 1020:3e05
    bh = 0;
    ax -= bx;
    if ((short)ax >= (short)dx)
        goto loc_14024;
    al = 0x05;
    sub_113e6();
    memoryASet(ds, 0x6513, 0x18);
    if (!(memoryAGet(ds, si + 11) & 0x02))
        goto loc_14024;
    sub_15bcc();
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) & 0xfd);
loc_14024: // 1020:3e24
    dx = pop();
    bx = pop();
    ax = pop();
}
void sub_14028() // 1020:3e28
{
    ax = 0x168f;
    ds = ax;
    bp = 0xffff;
    memoryASet16(ds, 0x564c, bp);
    memoryASet16(ds, 0x565e, bp);
    memoryASet16(ds, 0x5670, bp);
    memoryASet16(ds, 0x5682, bp);
    si = 0x7dcb;
    di = 0x5648;
    ax = memoryAGet16(ds, 0x5270);
    dx = memoryAGet16(ds, 0x5272);
    cl = 0x04;
    ax <<= cl;
    dx <<= cl;
    cx = 0x000a;
loc_14056: // 1020:3e56
    if (memoryAGet16(ds, si + 4) == bp)
        goto loc_140c7;
    push(ax);
    push(dx);
    al = memoryAGet(ds, si + 7);
    cbw();
    dl = memoryAGet(ds, si + 6);
    if (dl != 0x00)
        goto loc_1406e;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
    goto loc_140d0;
loc_1406e: // 1020:3e6e
    if (dl != 0x02)
        goto loc_14078;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    goto loc_140d0;
loc_14078: // 1020:3e78
    if (dl != 0x01)
        goto loc_14081;
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    goto loc_140d0;
loc_14081: // 1020:3e81
    if (dl != 0x03)
        goto loc_1408a;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    goto loc_140d0;
loc_1408a: // 1020:3e8a
    dx = pop();
    ax = pop();
    bx = memoryAGet16(ds, si);
    bx += 0x0010;
    flags.carry = bx < ax;
    bx -= ax;
    if (flags.carry)
        goto loc_140c7;
    bx -= 0x0020;
    if ((short)bx > (short)0x0140)
        goto loc_140c7;
    bx = memoryAGet16(ds, si + 2);
    flags.carry = bx < dx;
    bx -= dx;
    if (flags.carry)
        goto loc_140c7;
    bx -= 0x0010;
    if ((short)bx > (short)0x00c0)
        goto loc_140c7;
    bx = memoryAGet16(ds, si + 4);
    bx += 0x001e;
    memoryASet16(ds, di + 4, bx);
    bx = memoryAGet16(ds, si);
    memoryASet16(ds, di, bx);
    bx = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, bx);
    memoryASet16(ds, di + 9, si);
    di += 0x0012;
loc_140c7: // 1020:3ec7
    si += 0x0014;
    cx--;
    if (!cx)
        goto loc_140cf;
    goto loc_14056;
loc_140cf: // 1020:3ecf
    return;
loc_140d0: // 1020:3ed0
    memoryASet16(ds, si + 17, memoryAGet16(ds, si + 17) + 1);
    ax = memoryAGet16(ds, si + 17);
    if (memoryAGet16(ds, si + 10) != ax)
        goto loc_1408a;
    dl ^= 0x02;
    memoryASet16(ds, si + 17, 0x0000);
    memoryASet(ds, si + 6, dl);
    goto loc_1408a;
}
void sub_140e8() // 1020:3ee8
{
    push(bx);
    push(di);
    push(si);
    ax = 0x168f;
    ds = ax;
    es = ax;
    di = 0x527c;
    cx = 0x020a;
    ax = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = 0x527c;
    cx = 0x003a;
loc_14102: // 1020:3f02
    memoryASet16(ds, di + 4, 0xffff);
    di += 0x0012;
    if (--cx)
        goto loc_14102;
    si = 0x52a0;
    di = 0x75a3;
    cx = 0x0028;
loc_14115: // 1020:3f15
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si + 4, ax);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, si + 2, ax);
    memoryASet(ds, si + 11, 0x00);
    si += 0x0012;
    di += 0x0006;
    if (--cx)
        goto loc_14115;
    memoryASet(ds, 0x6511, 0x04);
    ax = memoryAGet16(ds, 0x7695);
    memoryASet16(ds, 0x527c, ax);
    ax = memoryAGet16(ds, 0x7697);
    memoryASet16(ds, 0x527e, ax);
    si = pop();
    di = pop();
    bx = pop();
}
void sub_14146() // 1020:3f46
{
    ax = 0x168f;
    ds = ax;
    memoryASet(ds, 0x64fc, memoryAGet(ds, 0x64fc) + 1);
    if (memoryAGet(ds, 0x64fc) & 0x03)
        goto loc_14166;
    ax = memoryAGet16(ds, 0x64f6);
    ah++;
    if (ax != 0x63e4)
        goto loc_14163;
    ah -= 0x03;
loc_14163: // 1020:3f63
    memoryASet16(ds, 0x64f6, ax);
loc_14166: // 1020:3f66
    if (memoryAGet(ds, 0x6502) != 0x00)
        goto loc_14173;
    sub_1423c();
    sub_14174();
loc_14173: // 1020:3f73
    return;
}
void sub_14174() // 1020:3f74
{
    ax = 0x168f;
    ds = ax;
    if (memoryAGet16(ds, 0x528a) != 0x0000)
        goto loc_14185;
    memoryASet(ds, 0x6521, 0x00);
loc_14185: // 1020:3f85
    dx = memoryAGet16(ds, 0x527e);
    cl = 0x04;
    dx = sar16(dx, cl);
    dx -= memoryAGet16(ds, 0x5272);
    if (memoryAGet(ds, 0x6521) != 0x00)
        goto loc_141cf;
    if (memoryAGet16(ds, 0x528a) != 0x0000)
        goto loc_141a6;
    if (memoryAGet(ds, 0x650d) == 0x00)
        goto loc_141b8;
loc_141a6: // 1020:3fa6
    ax = 0x0003;
    if ((short)dx >= (short)0x000a)
        goto loc_141c8;
    ax = 0x0009;
    if ((short)dx > (short)0x0002)
        goto loc_141cf;
    goto loc_141c8;
loc_141b8: // 1020:3fb8
    ax = 0x000a;
    if ((short)dx >= (short)0x000b)
        goto loc_141c8;
    ax = 0x0009;
    if ((short)dx > (short)0x0002)
        goto loc_141cf;
loc_141c8: // 1020:3fc8
    memoryASet16(ds, 0x6524, ax);
    memoryASet(ds, 0x6521, memoryAGet(ds, 0x6521) + 1);
loc_141cf: // 1020:3fcf
    ax = memoryAGet16(ds, 0x7693);
    ax += 0x000c;
    ax <<= cl;
    if (memoryAGet16(ds, 0x527e) > ax)
        goto loc_141e8;
    bx = memoryAGet16(ds, 0x5272);
    bx--;
    if ((short)memoryAGet16(ds, 0x7693) < (short)bx)
        goto loc_14231;
loc_141e8: // 1020:3fe8
    ax = memoryAGet16(ds, 0x7693);
    ax -= memoryAGet16(ds, 0x5272);
    if (ax >= 0x0005)
        goto loc_14205;
    ax = memoryAGet16(ds, 0x7693);
    ax += 0x000c;
    ax <<= cl;
    ax -= memoryAGet16(ds, 0x527e);
    if (ax < 0x0070)
        goto loc_1422a;
loc_14205: // 1020:4005
    if (memoryAGet(ds, 0x6521) == 0x00)
        goto loc_1423b;
    if (memoryAGet16(ds, 0x6524) == dx)
        goto loc_14236;
    if ((short)memoryAGet16(ds, 0x6524) > (short)dx)
        goto loc_14231;
    ax = memoryAGet16(ds, 0x7693);
    dx = ax;
    dx += 0x000c;
    dx <<= cl;
    if (memoryAGet16(ds, 0x527e) > dx)
        goto loc_1422a;
    if (memoryAGet16(ds, 0x5272) > ax)
        goto loc_14236;
loc_1422a: // 1020:402a
    sub_12b4c();
    if (flags.carry)
        goto loc_14236;
    goto loc_1423b;
loc_14231: // 1020:4031
    sub_12b11();
    if (!flags.carry)
        goto loc_1423b;
loc_14236: // 1020:4036
    memoryASet(ds, 0x6521, 0x00);
loc_1423b: // 1020:403b
    return;
}
void sub_1423c() // 1020:403c
{
    ax = 0x168f;
    ds = ax;
    dx = memoryAGet16(ds, 0x527c);
    cl = 0x04;
    dx = sar16(dx, cl);
    dx -= memoryAGet16(ds, 0x5270);
    if (memoryAGet(ds, 0x6520) == 0x00)
        goto loc_14257;
    goto loc_142d7;
loc_14257: // 1020:4057
    if (memoryAGet16(ds, 0x651e) < 0x0016)
        goto loc_142c6;
    al = memoryAGet(ds, 0x5287);
    al &= 0x0f;
    if (al != 0x01)
        goto loc_142a1;
    ax = memoryAGet16(ds, 0x5282);
    if ((short)ax >= 0)
        goto loc_14270;
    ax = -ax;
loc_14270: // 1020:4070
    if (ax == 0x0040)
        goto loc_1427e;
    if ((short)memoryAGet16(ds, 0x5280) < (short)0x0000)
        goto loc_1429c;
    goto loc_1428a;
loc_1427e: // 1020:407e
    if ((short)memoryAGet16(ds, 0x5282) < (short)0x0000)
        goto loc_14297;
    if ((short)dx < (short)0x000d)
        goto loc_142d7;
loc_1428a: // 1020:408a
    ax = 0x0002;
loc_1428d: // 1020:408d
    memoryASet16(ds, 0x6522, ax);
    memoryASet(ds, 0x6520, 0x01);
    goto loc_142d7;
loc_14297: // 1020:4097
    if ((short)dx > (short)0x0007)
        goto loc_142d7;
loc_1429c: // 1020:409c
    ax = 0x0012;
    goto loc_1428d;
loc_142a1: // 1020:40a1
    ax = memoryAGet16(ds, 0x5282);
    ax |= memoryAGet16(ds, 0x528a);
    if (ax)
        goto loc_142c6;
    if (memoryAGet16(ds, 0x651e) != 0x0021)
        goto loc_142c6;
    sub_142fa();
    memoryASet16(ds, 0x6522, ax);
    goto loc_142bf;
loc_142b9: // 1020:40b9
    memoryASet16(ds, 0x6522, 0x000a);
loc_142bf: // 1020:40bf
    memoryASet(ds, 0x6520, 0x01);
    goto loc_142d7;
loc_142c6: // 1020:40c6
    if (memoryAGet(ds, 0x6520) != 0x00)
        goto loc_142d7;
    if ((short)dx > (short)0x0012)
        goto loc_142b9;
    if ((short)dx < (short)0x0002)
        goto loc_142b9;
loc_142d7: // 1020:40d7
    if (memoryAGet(ds, 0x6520) == 0x00)
        goto loc_142f9;
    if (memoryAGet16(ds, 0x6522) == dx)
        goto loc_142f4;
    if ((short)memoryAGet16(ds, 0x6522) > (short)dx)
        goto loc_142ed;
    sub_12bb5();
    if (flags.carry)
        goto loc_142f4;
    goto loc_142f9;
loc_142ed: // 1020:40ed
    sub_12b94();
    if (flags.carry)
        goto loc_142f4;
    goto loc_142f9;
loc_142f4: // 1020:40f4
    memoryASet(ds, 0x6520, 0x00);
loc_142f9: // 1020:40f9
    return;
}
void sub_142fa() // 1020:40fa
{
    push(bx);
    push(cx);
    push(dx);
    push(si);
    dx = memoryAGet16(ds, 0x527c);
    si = 0x5570;
    cx = 0x0008;
    ax = 0x000a;
loc_1430b: // 1020:410b
    if (memoryAGet16(ds, si + 4) == 0xffff)
        goto loc_14333;
    bx = 0;
    flags.carry = memoryAGet16(ds, si) < dx;
    bl += 0x00 + flags.carry;
    bh = memoryAGet(ds, 0x5281);
    bh = rol8(bh, 0x01);
    bh &= 0x01;
    bl ^= bh;
    if (!bl)
        goto loc_14333;
    bx = memoryAGet16(ds, si);
    bx -= dx;
    if ((short)bx >= 0)
        goto loc_1432d;
    bx = -bx;
loc_1432d: // 1020:412d
    if (bx < 0x00c8)
        goto loc_14346;
loc_14333: // 1020:4133
    si += 0x0012;
    if (--cx)
        goto loc_1430b;
    ax = 0x0003;
    if (!(memoryAGet16(ds, 0x5281) & 0x0080))
        goto loc_14346;
    ax = 0x0011;
loc_14346: // 1020:4146
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_1434b() // 1020:414b
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    if (memoryAGet(ds, 0x6516) != 0x00)
        goto loc_14371;
    if (memoryAGet(ds, 0x047b) == 0x00)
        goto loc_14371;
    sub_14fc0();
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) - 1);
    goto loc_1467a;
loc_14371: // 1020:4171
    if (memoryAGet(ds, 0x047c) == 0x00)
        goto loc_14387;
    memoryASet(ds, 0x6517, 0x01);
loc_1437d: // 1020:417d
    sync();
    if (memoryAGet(ds, 0x047c) == 0x00)
        goto loc_1437d;
    goto loc_1467a;
loc_14387: // 1020:4187
    if (memoryAGet(ds, 0x0452) == 0x00)
        goto loc_14393;
    memoryASet(ds, 0x6506, 0x32);
loc_14393: // 1020:4193
    if (memoryAGet(ds, 0x047e) == 0x00)
        goto loc_143ad;
loc_1439a: // 1020:419a
    sync();
    if (memoryAGet(ds, 0x047e) != 0x00)
        goto loc_1439a;
    sub_129df();
    sub_103f8();
    sub_105f2();
    sub_105ae();
loc_143ad: // 1020:41ad
    sub_11aaf();
    es = memoryAGet16(ds, 0x526c);
    si = 0x527c;
    sub_14d49();
    sub_10a05();
    ax = 0x550b;
    if (memoryAGet(ds, 0x6513) == 0x00)
        goto loc_143ca;
    goto loc_1448a;
loc_143ca: // 1020:41ca
    al = 0x0c;
    al += memoryAGet(ds, 0x6501);
    if (memoryAGet(ds, 0x6514) == 0x00)
        goto loc_143da;
    goto loc_1448a;
loc_143da: // 1020:41da
    memoryASet(ds, 0x6501, 0x00);
    al = 0xaa;
    if (memoryAGet(ds, 0x042f) == 0x00)
        goto loc_143eb;
    ax = 0x0101;
loc_143eb: // 1020:41eb
    if (memoryAGet(ds, 0x0430) == 0x00)
        goto loc_143f5;
    ax = 0xff01;
loc_143f5: // 1020:41f5
    if (memoryAGet(ds, 0x650d) == 0x00)
        goto loc_14400;
    al = 0x06;
    goto loc_14442;
loc_14400: // 1020:4200
    if (memoryAGet(ds, 0x650e) != 0x00)
        goto loc_14415;
    if (memoryAGet(ds, 0x650f) == 0x06)
        goto loc_14420;
    if (memoryAGet(ds, 0x042e) == 0x00)
        goto loc_14420;
loc_14415: // 1020:4215
    if (ah == 0x55)
        goto loc_1441e;
    al = 0x03;
    goto loc_14420;
loc_1441e: // 1020:421e
    al = 0x05;
loc_14420: // 1020:4220
    if (memoryAGet(ds, 0x650e) != 0x00)
        goto loc_14442;
    if (memoryAGet(ds, 0x042d) == 0x00)
        goto loc_14442;
    if (memoryAGet(ds, 0x650f) != 0x00)
        goto loc_14442;
    al = 0x02;
    if (memoryAGet(ds, si + 11) != 0x05)
        goto loc_14442;
    memoryASet(ds, 0x6512, 0x64);
loc_14442: // 1020:4242
    if (al != 0xaa)
        goto loc_14448;
    al = 0;
loc_14448: // 1020:4248
    if (memoryAGet(ds, 0x042b) == 0x00)
        goto loc_14480;
    if (memoryAGet(ds, 0x650e) != 0x00)
        goto loc_14480;
    if (memoryAGet(ds, 0x650a) != 0x00)
        goto loc_1448a;
    if (al == 0x03)
        goto loc_14465;
    if (al != 0x05)
        goto loc_1446e;
loc_14465: // 1020:4265
    memoryASet(ds, 0x650b, 0x00);
    al = 0x07;
    goto loc_1448a;
loc_1446e: // 1020:426e
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_1448a;
    if (memoryAGet(ds, 0x650b) == 0x00)
        goto loc_1448a;
    al = 0x08;
    goto loc_1448a;
loc_14480: // 1020:4280
    memoryASet(ds, 0x650b, 0x01);
    memoryASet(ds, 0x650c, 0x00);
loc_1448a: // 1020:428a
    al += memoryAGet(ds, 0x6509);
    if (ah != 0x55)
        goto loc_14496;
    ah = memoryAGet(ds, si + 10);
loc_14496: // 1020:4296
    dl = memoryAGet(ds, 0x0430);
    dl |= memoryAGet(ds, 0x042f);
    memoryASet(ds, 0x6507, dl);
    dl = memoryAGet(ds, 0x042d);
    dl |= memoryAGet(ds, 0x042e);
    memoryASet(ds, 0x6508, dl);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    dl |= ah;
    if (memoryAGet16(ds, si + 9) == dx)
        goto loc_144c1;
    memoryASet16(ds, si + 9, dx);
loc_144b9: // 1020:42b9
    memoryASet16(ds, 0x651e, 0x0001);
    goto loc_144e1;
loc_144c1: // 1020:42c1
    if (al == 0x01)
        goto loc_144c9;
    if (al != 0x00)
        goto loc_144d2;
loc_144c9: // 1020:42c9
    if (memoryAGet(ds, 0x6512) == 0x00)
        goto loc_144d2;
    al += 0x09;
loc_144d2: // 1020:42d2
    if (memoryAGet(ds, si + 11) != al)
        goto loc_144b9;
    flags.carry = (memoryAGet16(ds, 0x651e) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x651e, memoryAGet16(ds, 0x651e) + 0x0001);
    memoryASet16(ds, 0x651e, memoryAGet16(ds, 0x651e) - 0x0000 - flags.carry);
loc_144e1: // 1020:42e1
    cbw();
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_1496c(); break;
        case 2: sub_149fa(); break;
        case 4: sub_14948(); break;
        case 6: sub_149d3(); break;
        case 10: sub_149b7(); break;
        case 12: sub_14a33(); break;
        case 14: sub_14b5b(); break;
        case 16: sub_14ad6(); break;
        case 18: sub_1496c(); break;
        case 20: sub_14a07(); break;
        case 22: sub_14a14(); break;
        case 24: sub_14a26(); break;
        case 26: sub_14a26(); break;
        case 32: sub_1496c(); break;
        case 34: sub_149fa(); break;
        case 36: sub_14948(); break;
        case 38: sub_149fa(); break;
        case 42: sub_14acc(); break;
        case 44: sub_14a33(); break;
        case 46: sub_14b5b(); break;
        case 48: sub_14ad6(); break;
        case 54: sub_14a21(); break;
        case 56: sub_14a26(); break;
        case 58: sub_14a26(); break;
        default:
            stop("ind 1020:42e6");
    }
    ax = memoryAGet16(ds, si + 6);
    cl = 0x04;
    ax = sar16(ax, cl);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) < (short)0x0008)
        goto loc_144fe;
    if (memoryAGet16(ds, si) < 0x0ff8)
        goto loc_14500;
loc_144fe: // 1020:42fe
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
loc_14500: // 1020:4300
    ax = memoryAGet16(ds, si + 14);
    cl = 0x04;
    ax = sar16(ax, cl);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    sub_14684();
    al = memoryAGet(ds, 0x650a);
    if (!al)
        goto loc_14578;
    cl = 0x04;
    ax = memoryAGet16(ds, 0x5294);
    ax = sar16(ax, cl);
    ax += memoryAGet16(ds, 0x528e);
    if (ax >= 0x1000)
        goto loc_1456b;
    bx = memoryAGet16(ds, 0x5270);
    bx <<= cl;
    bx -= 0x0028;
    if ((short)bx > (short)ax)
        goto loc_1456b;
    bx += 0x0190;
    if ((short)bx < (short)ax)
        goto loc_1456b;
    memoryASet16(ds, 0x528e, ax);
    ax = memoryAGet16(ds, 0x529c);
    ax = sar16(ax, cl);
    ax += memoryAGet16(ds, 0x5290);
    bl = memoryAGet(ds, 0x508b);
    bh = 0;
    bx <<= cl;
    if (ax >= bx)
        goto loc_1456b;
    bx = memoryAGet16(ds, 0x5272);
    bx <<= cl;
    bx -= 0x0014;
    if ((short)bx > (short)ax)
        goto loc_1456b;
    bx += 0x00e8;
    if ((short)bx < (short)ax)
        goto loc_1456b;
    memoryASet16(ds, 0x5290, ax);
    goto loc_14576;
loc_1456b: // 1020:436b
    memoryASet16(ds, 0x5292, 0xffff);
    memoryASet(ds, 0x650a, 0x00);
loc_14576: // 1020:4376
    goto loc_145ea;
loc_14578: // 1020:4378
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_145ea;
    bx = memoryAGet16(ds, 0x5280);
    dx = bx;
    dh &= 0x1f;
    al = memoryAGet(ds, 0x5287);
    if (memoryAGet(ds, 0x650d) != 0x00)
        goto loc_145ab;
    if (al == 0x15)
        goto loc_1459a;
    if (al != 0x17)
        goto loc_145ab;
loc_1459a: // 1020:439a
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0004;
    memoryASet16(ds, 0x5290, ax);
    sub_15322();
    memoryASet16(ds, 0x528e, ax);
    goto loc_145ea;
loc_145ab: // 1020:43ab
    al &= 0x0f;
    if (dx == 0x000e)
        goto loc_145ba;
    if (al == 0x07)
        goto loc_145ea;
    if (al == 0x08)
        goto loc_145ea;
loc_145ba: // 1020:43ba
    ax = memoryAGet16(ds, 0x527c);
    ax++;
    ax++;
    flags.carry = dx < 0x0017;
    dx -= 0x0017;
    if (flags.carry)
        goto loc_145d4;
    if (dx > 0x0001)
        goto loc_145d4;
    ax -= 0x000a;
    if (!(bh & 0x80))
        goto loc_145d4;
    ax += 0x0012;
loc_145d4: // 1020:43d4
    bh &= 0x1f;
    memoryASet16(ds, 0x528e, ax);
    ax = memoryAGet16(ds, 0x527e);
    bx <<= 1;
    flags.carry = al < memoryAGet(ds, bx + 27640);
    al -= memoryAGet(ds, bx + 27640);
    ah = ah - 0x00 - flags.carry;
    ax++;
    memoryASet16(ds, 0x5290, ax);
loc_145ea: // 1020:43ea
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_145fd;
    memoryASet(ds, 0x6515, memoryAGet(ds, 0x6515) - 1);
    if (memoryAGet(ds, 0x6515))
        goto loc_145fd;
    memoryASet16(ds, 0x5292, 0xffff);
loc_145fd: // 1020:43fd
    dx = 0x0001;
    flags.carry = memoryAGet(ds, 0x651b) < dl;
    memoryASet(ds, 0x651b, memoryAGet(ds, 0x651b) - dl);
    memoryASet(ds, 0x651b, memoryAGet(ds, 0x651b) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6516) < dl;
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) - dl);
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6504) < dl;
    memoryASet(ds, 0x6504, memoryAGet(ds, 0x6504) - dl);
    memoryASet(ds, 0x6504, memoryAGet(ds, 0x6504) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6510) < dl;
    memoryASet(ds, 0x6510, memoryAGet(ds, 0x6510) - dl);
    memoryASet(ds, 0x6510, memoryAGet(ds, 0x6510) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6511) < dl;
    memoryASet(ds, 0x6511, memoryAGet(ds, 0x6511) - dl);
    memoryASet(ds, 0x6511, memoryAGet(ds, 0x6511) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6512) < dl;
    memoryASet(ds, 0x6512, memoryAGet(ds, 0x6512) - dl);
    memoryASet(ds, 0x6512, memoryAGet(ds, 0x6512) + (dh + flags.carry));
    flags.carry = memoryAGet(ds, 0x6514) < dl;
    memoryASet(ds, 0x6514, memoryAGet(ds, 0x6514) - dl);
    memoryASet(ds, 0x6514, memoryAGet(ds, 0x6514) + (dh + flags.carry));
    if (memoryAGet16(ds, 0x528a) != 0x0000)
        goto loc_14647;
    flags.carry = memoryAGet(ds, 0x6513) < dl;
    memoryASet(ds, 0x6513, memoryAGet(ds, 0x6513) - dl);
    memoryASet(ds, 0x6513, memoryAGet(ds, 0x6513) + (dh + flags.carry));
loc_14647: // 1020:4447
    ax = memoryAGet16(ds, 0x5282);
    ax |= memoryAGet16(ds, 0x528a);
    if (ax)
        goto loc_14654;
    memoryASet(ds, 0x6514, dh);
loc_14654: // 1020:4454
    flags.carry = memoryAGet(ds, 0x6505) < dl;
    memoryASet(ds, 0x6505, memoryAGet(ds, 0x6505) - dl);
    memoryASet(ds, 0x6505, memoryAGet(ds, 0x6505) + (dh + flags.carry));
    if (!memoryAGet(ds, 0x6505))
        goto loc_1467a;
    if (memoryAGet(ds, 0x6505) & 0x03)
        goto loc_1467a;
    memoryASet16(ds, 0x5292, memoryAGet16(ds, 0x5292) + 1);
    if (memoryAGet(ds, 0x5292) != 0x31)
        goto loc_1467a;
    memoryASet16(ds, 0x5292, 0xffff);
    memoryASet(ds, 0x6505, dh);
loc_1467a: // 1020:447a
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_14684() // 1020:4484
{
    bool temp_cond0;

    push(ax);
    push(cx);
    push(dx);
    si = 0x527c;
    ax = memoryAGet16(ds, 0x527e);
    cl = 0x04;
    ax = sar16(ax, cl);
    ax--;
    tl = al; al = ah; ah = tl;
    bx = memoryAGet16(ds, 0x5280);
    bh &= 0x1f;
    bx <<= 1;
    dh = memoryAGet(ds, bx + 27640);
    bx = 0x0008;
    if ((short)memoryAGet16(ds, 0x5282) > (short)0x0000)
        goto loc_146b1;
    if ((short)memoryAGet16(ds, 0x5282) < (short)0x0000)
        goto loc_146af;
    bx = 0;
loc_146af: // 1020:44af
    bx = -bx;
loc_146b1: // 1020:44b1
    push(ax);
    push(bx);
    bx = memoryAGet16(ds, 0x527c);
    bx = sar16(bx, cl);
    bx += ax;
    if ((short)memoryAGet16(ds, 0x527e) <= (short)0x0000)
        goto loc_146d9;
    al = memoryAGet(ds, 0x508b);
    ah = 0;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if ((short)memoryAGet16(ds, 0x527e) <= (short)ax)
        goto loc_146d9;
    sub_14fc0();
loc_146d9: // 1020:44d9
    memoryASet(ds, 0x6526, 0x00);
    al = memoryAGet(ds, 0x527c);
    al &= 0x0f;
    flags.carry = al < 0x04;
    al -= 0x04;
    bx = bx - 0x0000 - flags.carry;
    bp = bx;
    sub_14761();
    if (memoryAGet(ds, 0x6526) != 0x01)
        goto loc_14739;
    flags.carry = (al + 0x08) >= 0x100;
    al += 0x08;
    bx += 0x0000 + flags.carry;
    flags.carry = al < 0x0f;
    flags.carry = !flags.carry;
    bx += 0x0000 + flags.carry;
    if (bx == bp)
        goto loc_14706;
    sub_14761();
loc_14706: // 1020:4506
    if (memoryAGet(ds, 0x6526) != 0x01)
        goto loc_14739;
    if (memoryAGet(ds, 0x6510) != 0x00)
        goto loc_14736;
    if (memoryAGet(ds, 0x6513) != 0x00)
        goto loc_14736;
    sub_14857();
    if (memoryAGet(ds, 0x6526) != 0x01)
        goto loc_14739;
    sub_1511f();
    if (memoryAGet(ds, 0x6526) == 0x01)
        goto loc_14736;
    memoryASet(ds, 0x5284, 0x00);
    goto loc_14739;
loc_14736: // 1020:4536
    sub_14e65();
loc_14739: // 1020:4539
    bx = pop();
    ax = pop();
    if ((short)memoryAGet16(ds, 0x527e) <= (short)0x0000)
        goto loc_1475d;
    bx += memoryAGet16(ds, 0x527c);
    bx = sar16(bx, cl);
    bx += ax;
    sub_14817();
    goto loc_14752;
loc_1474f: // 1020:454f
    sub_14831();
loc_14752: // 1020:4552
    flags.carry = bx < 0x0100;
    bx -= 0x0100;
    if (flags.carry)
        goto loc_1475d;
    temp_cond0 = dh - 0x10 > 0;
    dh -= 0x10;
    if (temp_cond0)
        goto loc_1474f;
loc_1475d: // 1020:455d
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_14761() // 1020:4561
{
    push(ax);
    push(bx);
    push(bp);
    memoryASet(ds, 0x651c, 0x00);
    memoryASet(ds, 0x650e, 0x00);
    memoryASet(ds, 0x650d, 0x00);
    if ((short)memoryAGet16(ds, 0x527e) > (short)0xffff)
        goto loc_14785;
    sub_14e65();
    memoryASet(ds, 0x6526, 0xff);
    goto loc_14813;
loc_14785: // 1020:4585
    al = memoryAGet(ds, 0x5287);
    al &= 0x0f;
    if (al == 0x02)
        goto loc_147a5;
    push(bx);
    di = bx + 256;
    al = memoryAGet(es, di);
    bx = 0x73a3;
    al = memoryAGet(ds, bx+al);
    ah = 0;
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_14ff9(); break;
        case 2: sub_14ffd(); break;
        case 4: sub_15013(); break;
        case 6: sub_1501c(); break;
        case 8: sub_15025(); break;
        case 10: sub_15001(); break;
        case 12: sub_1502e(); break;
        case 14: sub_14f10(); break;
        case 16: sub_14fc0(); break;
        case 18: sub_14fc0(); break;
        case 20: sub_14fc0(); break;
        case 22: sub_14fb1(); break;
        case 24: sub_14fc9(); break;
        case 26: sub_14f9a(); break;
        case 28: sub_15087(); break;
        case 30: sub_15088(); break;
        case 32: sub_15103(); break;
        case 34: sub_14fc9(); break;
        case 36: sub_14fc0(); break;
        default:
            stop("ind 1020:45a0");
    }
    bx = pop();
loc_147a5: // 1020:45a5
    flags.carry = bx < 0x0100;
    bx -= 0x0100;
    if (flags.carry)
        goto loc_14813;
    if ((short)memoryAGet16(ds, 0x528a) > (short)0x0000)
        goto loc_14813;
    di = bx;
    ah = memoryAGet(es, bx);
    al = memoryAGet(es, bx + 256);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    tl = al; al = ah; ah = tl;
    bx = 0x74a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x7f;
    bl = al;
    bh = 0;
    bx <<= 1;
    push(ax);
    switch (bx)
    {
        case 0: sub_15087(); break;
        case 2: sub_15088(); break;
        case 4: sub_15103(); break;
        case 6: sub_14fc9(); break;
        case 8: sub_14fc0(); break;
        default:
            stop("ind 1020:45cf");
    }
    ax = pop();
    ah &= 0x01;
    if (!ah)
        goto loc_14813;
    if ((short)memoryAGet16(ds, 0x527e) <= (short)0x0000)
        goto loc_14813;
    dx = 0xffff;
    bx = 0x72a3;
    if ((short)memoryAGet16(ds, 0x5282) > (short)0x0000)
        goto loc_147ef;
    dx = -dx;
loc_147ef: // 1020:45ef
    push(di);
    di += dx;
    al = memoryAGet(es, di + 256);
    al = memoryAGet(ds, bx+al);
    if (!al)
        goto loc_1480c;
    dx = -dx;
    di += dx;
    di += dx;
    al = memoryAGet(es, di + 256);
    al = memoryAGet(ds, bx+al);
    if (al)
        goto loc_14812;
loc_1480c: // 1020:460c
    dx <<= 1;
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + dx);
loc_14812: // 1020:4612
    di = pop();
loc_14813: // 1020:4613
    bp = pop();
    bx = pop();
    ax = pop();
}
void sub_14817() // 1020:4617
{
    push(bx);
    push(dx);
    push(di);
    di = bx;
    al = memoryAGet(es, bx);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    ah = 0;
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_14f0b(); break;
        case 2: sub_14f0c(); break;
        case 4: sub_14f10(); break;
        case 6: sub_14fc0(); break;
        case 8: sub_14fb1(); break;
        case 10: sub_14fc9(); break;
        case 12: sub_14f9a(); break;
        case 14: sub_14ff9(); break;
        case 16: sub_14ffd(); break;
        case 18: sub_15013(); break;
        case 20: sub_1501c(); break;
        case 22: sub_15025(); break;
        case 24: sub_15001(); break;
        case 26: sub_1502e(); break;
        default:
            stop("ind 1020:4629");
    }
    di = pop();
    dx = pop();
    bx = pop();
}
void sub_14831() // 1020:4631
{
    push(bx);
    push(dx);
    push(di);
    di = bx;
    al = memoryAGet(es, bx);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    if (al == 0x04)
        goto loc_14845;
    if (al != 0x02)
        goto loc_1484f;
loc_14845: // 1020:4645
    ah = 0;
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_14f0b(); break;
        case 2: sub_14f0c(); break;
        case 4: sub_14f10(); break;
        case 6: sub_14fc0(); break;
        case 8: sub_14fb1(); break;
        case 10: sub_14fc9(); break;
        case 12: sub_14f9a(); break;
        case 14: sub_14ff9(); break;
        case 16: sub_14ffd(); break;
        case 18: sub_15013(); break;
        case 20: sub_1501c(); break;
        case 22: sub_15025(); break;
        case 24: sub_15001(); break;
        case 26: sub_1502e(); break;
        case 28: sub_14f10(); break;
        case 30: sub_14fc0(); break;
        case 32: sub_14fc0(); break;
        case 34: sub_14fc0(); break;
        case 36: sub_14fb1(); break;
        case 38: sub_14fc9(); break;
        case 40: sub_14f9a(); break;
        case 42: sub_15087(); break;
        case 44: sub_15088(); break;
        case 46: sub_15103(); break;
        case 48: sub_14fc9(); break;
        case 50: sub_14fc0(); break;
        default:
            stop("ind 1020:464b");
    }
loc_1484f: // 1020:464f
    di = pop();
    dx = pop();
    bx = pop();
}
void sub_14857() // 1020:4657
{
    goto loc_14857;
loc_14853: // 1020:4653
    return;
loc_14854: // 1020:4654
    goto loc_14935;
loc_14857: // 1020:4657
    if ((short)memoryAGet16(ds, 0x528a) < (short)0x0000)
        goto loc_14853;
    if (memoryAGet(ds, 0x6510) != 0x00)
        goto loc_14853;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    si = 0x5648;
    cx = 0x0004;
loc_14874: // 1020:4674
    if (memoryAGet16(ds, si + 4) == 0xffff)
        goto loc_14854;
    if (!(memoryAGet(ds, si + 5) & 0x20))
        goto loc_14854;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_1488a;
    ax = -ax;
loc_1488a: // 1020:468a
    if (ax >= 0x0040)
        goto loc_14854;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if ((short)ax >= 0)
        goto loc_1489a;
    ax = -ax;
loc_1489a: // 1020:469a
    if (ax >= 0x0010)
        goto loc_14854;
    ax = memoryAGet16(ds, si);
    dx = memoryAGet16(ds, 0x527c);
    flags.carry = dl < memoryAGet(ds, 0x692f);
    dl -= memoryAGet(ds, 0x692f);
    dh = dh - 0x00 - flags.carry;
    bl = memoryAGet(ds, 0x6bf7);
    if ((short)dx < (short)ax)
        goto loc_148c1;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27639);
    tx = dx; dx = ax; ax = tx;
loc_148c1: // 1020:46c1
    bh = 0;
    dx += bx;
    if ((short)dx <= (short)ax)
        goto loc_14935;
    ax = memoryAGet16(ds, si + 2);
    dx = memoryAGet16(ds, 0x527e);
    flags.carry = dl < 0x06;
    dl -= 0x06;
    dh = dh - 0x00 - flags.carry;
    bl = 0x08;
    if ((short)dx < (short)ax)
        goto loc_148e9;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27640);
    tx = dx; dx = ax; ax = tx;
loc_148e9: // 1020:46e9
    bh = 0;
    dx += bx;
    if ((short)dx <= (short)ax)
        goto loc_14935;
    if (memoryAGet16(ds, 0x651e) != 0x000e)
        goto loc_148fe;
    memoryASet16(ds, 0x651e, 0x0010);
loc_148fe: // 1020:46fe
    memoryASet(ds, 0x6526, 0x00);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x527e, ax);
    sub_14ef0();
    bx = memoryAGet16(ds, si + 9);
    al = memoryAGet(ds, bx + 7);
    cbw();
    dl = memoryAGet(ds, bx + 6);
    if (dl == 0x01)
        goto loc_1492f;
    if (dl == 0x02)
        goto loc_14929;
    ax = -ax;
    if (dl == 0x03)
        goto loc_1492f;
    goto loc_1493e;
loc_14929: // 1020:4729
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + ax);
    goto loc_1493e;
loc_1492f: // 1020:472f
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + ax);
    goto loc_1493e;
loc_14935: // 1020:4735
    si += 0x0012;
    cx--;
    if (!cx)
        goto loc_1493e;
    goto loc_14874;
loc_1493e: // 1020:473e
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_14948() // 1020:4748
{
    if (memoryAGet(ds, 0x651d) < 0x03)
        goto loc_14955;
    memoryASet(ds, 0x650f, 0x06);
    return;
loc_14955: // 1020:4755
    memoryASet(ds, 0x651d, memoryAGet(ds, 0x651d) + 1);
    bp = 0x0030;
    sub_14db6();
    bp = 0x0040;
    sub_14d7d();
    sub_14e12();
    sub_14e2a();
}
void sub_1496c() // 1020:476c
{
    push(ax);
    push(bx);
    push(dx);
    memoryASet(ds, 0x5287, al);
    sub_14de8();
    if ((short)ax >= 0)
        goto loc_1497b;
    ax = -ax;
loc_1497b: // 1020:477b
    if (ax < 0x0010)
        goto loc_1499d;
    al = memoryAGet(ds, 0x5281);
    ah = memoryAGet(ds, 0x5283);
    al = rol8(al, 0x01);
    ah = rol8(ah, 0x01);
    ax &= 0x0101;
    if (al != ah)
        goto loc_1499d;
    bl = memoryAGet(ds, 0x6509);
    bh = 0;
    bx += 0x0004;
    bx <<= 1;
loc_1499d: // 1020:479d
    bx = memoryAGet16(ds, bx + 28351);
    memoryASet16(ds, 0x5288, bx);
    ax = memoryAGet16(ds, bx);
    dh = memoryAGet(ds, 0x5285);
    dh &= 0x80;
    ah |= dh;
    memoryASet16(ds, 0x5280, ax);
    dx = pop();
    bx = pop();
    ax = pop();
}
void sub_149b7() // 1020:47b7
{
    sub_14e12();
    sub_14e2a();
    sub_14de8();
    if (memoryAGet16(ds, 0x651e) != 0x000f)
        goto loc_149d2;
    memoryASet(ds, 0x6510, 0x06);
    memoryASet16(ds, 0x528a, 0x0000);
loc_149d2: // 1020:47d2
    return;
}
void sub_149d3() // 1020:47d3
{
    sub_14e12();
    sub_14e2a();
    bp = 0x0020;
    sub_14d7d();
    ax = memoryAGet16(ds, 0x5282);
    if ((short)ax >= 0)
        goto loc_149e8;
    ax = -ax;
loc_149e8: // 1020:47e8
    if (ax >= 0x0020)
        goto loc_149f9;
    al = 0x06;
    ah = memoryAGet(ds, 0x5285);
    ah &= 0x80;
    memoryASet16(ds, 0x5280, ax);
loc_149f9: // 1020:47f9
    return;
}
void sub_149fa() // 1020:47fa
{
    bp = 0x0040;
    sub_14d7d();
    sub_14e12();
    sub_14e2a();
}
void sub_14a07() // 1020:4807
{
    bp = 0x0030;
    sub_14d7d();
    sub_14e12();
    sub_14e2a();
}
void sub_14a14() // 1020:4814
{
    memoryASet16(ds, 0x5282, 0x0000);
    sub_14e12();
    sub_14e2a();
}
void sub_14a21() // 1020:4821
{
    goto loc_14a21;
loc_14a14: // 1020:4814
    memoryASet16(ds, 0x5282, 0x0000);
    sub_14e12();
    sub_14e2a();
    return;
loc_14a21: // 1020:4821
    sub_14ce9();
    goto loc_14a14;
}
void sub_14a26() // 1020:4826
{
    bp = 0x00c0;
    sub_14dd0();
    sub_14e12();
    sub_14e2a();
}
void sub_14a33() // 1020:4833
{
    if (memoryAGet(ds, 0x6507) == 0x00)
        goto loc_14a42;
    bp = 0x0040;
    sub_14d7d();
    goto loc_14a45;
loc_14a42: // 1020:4842
    sub_14de8();
loc_14a45: // 1020:4845
    if (memoryAGet16(ds, 0x651e) > 0x0001)
        goto loc_14a5c;
    ax = 0x000c;
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14a59;
    ax = 0x0017;
loc_14a59: // 1020:4859
    memoryASet16(ds, 0x5280, ax);
loc_14a5c: // 1020:485c
    ax = 0;
    if (memoryAGet(ds, 0x6508) == al)
        goto loc_14ac8;
    al = 0x06;
    al += memoryAGet(ds, 0x6509);
    cbw();
    bx = ax;
    bx <<= 1;
    sub_14e12();
    sub_14e2a();
    memoryASet(ds, 0x527c, memoryAGet(ds, 0x527c) & 0xf0);
    memoryASet(ds, 0x527c, memoryAGet(ds, 0x527c) + 0x08);
    bx = 0x73a3;
    cl = 0x04;
    ax = memoryAGet16(ds, 0x527e);
    al &= 0xf0;
    ax <<= cl;
    di = memoryAGet16(ds, 0x527c);
    di = sar16(di, cl);
    di += ax;
    es = memoryAGet16(ds, 0x526c);
    al = memoryAGet(es, di);
    al = memoryAGet(ds, bx+al);
    if (al == 0x06)
        goto loc_14abc;
    dx = 0xfff0;
    al = memoryAGet(es, di + 65535);
    al = memoryAGet(ds, bx+al);
    if (al == 0x06)
        goto loc_14ab8;
    dx = -dx;
    al = memoryAGet(es, di + 1);
    al = memoryAGet(ds, bx+al);
    if (al == 0x06)
        goto loc_14ab8;
    dx = 0;
loc_14ab8: // 1020:48b8
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + dx);
loc_14abc: // 1020:48bc
    ax = 0x0040;
    if (memoryAGet(ds, 0x042d) == 0x00)
        goto loc_14ac8;
    ax = -ax;
loc_14ac8: // 1020:48c8
    memoryASet16(ds, 0x528a, ax);
}
void sub_14acc() // 1020:48cc
{
    sub_14e12();
    sub_14e2a();
    sub_14de8();
}
void sub_14ad6() // 1020:48d6
{
    sub_14e12();
    sub_14e2a();
    sub_14de8();
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14b5a;
    ax = 0;
    dx = 0xff60;
    if (memoryAGet(ds, 0x042d) != 0x00)
        goto loc_14b0a;
    dx = 0xff20;
    tx = dx; dx = ax; ax = tx;
    if (memoryAGet(ds, 0x5281) & 0x80)
        goto loc_14aff;
    ax = -ax;
loc_14aff: // 1020:48ff
    bx = memoryAGet16(ds, 0x527e);
    bx -= 0x0010;
    memoryASet16(ds, 0x5290, bx);
loc_14b0a: // 1020:490a
    if (dx)
        goto loc_14b21;
    bx = memoryAGet16(ds, 0x5292);
    bh &= 0x1f;
    if (bx >= 0x0065)
        goto loc_14b38;
    if (!(memoryAGet(ds, bx + 28441) & 0x04))
        goto loc_14b38;
loc_14b21: // 1020:4921
    sub_14ce9();
    bx = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, bx + 14, dx);
    dx = ax;
    dx = sar16(dx, 0x0001);
    dx = sar16(dx, 0x0001);
    ax -= dx;
    memoryASet16(ds, bx + 6, ax);
    goto loc_14b49;
loc_14b38: // 1020:4938
    memoryASet(ds, 0x650a, 0x01);
    memoryASet16(ds, 0x5294, ax);
    memoryASet16(ds, 0x529c, dx);
    al = 0x03;
    sub_113e6();
loc_14b49: // 1020:4949
    al = 0x0a;
    ah = memoryAGet(ds, 0x5285);
    ah &= 0x80;
    memoryASet16(ds, 0x5280, ax);
    memoryASet(ds, 0x6509, 0x00);
loc_14b5a: // 1020:495a
    return;
}
void sub_14b5b() // 1020:495b
{
    sub_14e12();
    sub_14e2a();
    sub_14de8();
    if (memoryAGet(ds, 0x650c) != 0x00)
        goto loc_14baf;
    if (memoryAGet16(ds, 0x651e) != 0x0001)
        goto loc_14bb2;
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14bb2;
    sub_14ce9();
    bx = memoryAGet16(ds, 0x64e9);
    ax = memoryAGet16(ds, bx + 2);
    cl = 0x04;
    ax = sar16(ax, cl);
    tl = al; al = ah; ah = tl;
    di = ax;
    ax = memoryAGet16(ds, bx);
    ax = sar16(ax, cl);
    di += ax;
    ax = memoryAGet16(es, di);
    bx = 0x73a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x07;
    if (!al)
        goto loc_14baf;
    dx = 0xffd0;
    al = ah;
    al = memoryAGet(ds, bx+al);
    al &= 0x07;
    if (!al)
        goto loc_14ba8;
    dx = -dx;
loc_14ba8: // 1020:49a8
    bx = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, bx + 6, dx);
loc_14baf: // 1020:49af
    goto loc_14ce3;
loc_14bb2: // 1020:49b2
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14bbc;
    goto loc_14cc1;
loc_14bbc: // 1020:49bc
    di = 0x52a0;
    cx = 0x0030;
    bx = memoryAGet16(ds, 0x527e);
    dx = memoryAGet16(ds, 0x527c);
loc_14bca: // 1020:49ca
    if (memoryAGet16(ds, di + 4) != 0xffff)
        goto loc_14bd3;
    goto loc_14cda;
loc_14bd3: // 1020:49d3
    ax = bx;
    ax -= memoryAGet16(ds, di + 2);
    if ((short)ax >= 0)
        goto loc_14bdc;
    ax = -ax;
loc_14bdc: // 1020:49dc
    if (ax < 0x0014)
        goto loc_14be4;
    goto loc_14cda;
loc_14be4: // 1020:49e4
    ax = dx;
    ax -= memoryAGet16(ds, di);
    if (memoryAGet(ds, 0x5281) & 0x80)
        goto loc_14bf1;
    ax = -ax;
loc_14bf1: // 1020:49f1
    if (ax < 0x0014)
        goto loc_14bf9;
    goto loc_14cda;
loc_14bf9: // 1020:49f9
    if (cx > 0x0008)
        goto loc_14c11;
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    al = memoryAGet(ds, bx + 28538);
    al &= 0x0f;
    if (al != 0x0f)
        goto loc_14c11;
    goto loc_14cd2;
loc_14c11: // 1020:4a11
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27639);
    ax = memoryAGet16(ds, 0x527c);
    if ((short)ax <= (short)dx)
        goto loc_14c27;
    tx = dx; dx = ax; ax = tx;
    bl = 0x20;
loc_14c27: // 1020:4a27
    bh = 0;
    ax += bx;
    if ((short)ax >= (short)dx)
        goto loc_14c32;
    goto loc_14cd2;
loc_14c32: // 1020:4a32
    ax = memoryAGet16(ds, di + 2);
    dx = memoryAGet16(ds, 0x527e);
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27640);
    bl--;
    if ((short)ax >= (short)dx)
        goto loc_14c4e;
    tx = dx; dx = ax; ax = tx;
    bl = 0x0a;
loc_14c4e: // 1020:4a4e
    bh = 0;
    ax -= bx;
    if ((short)ax >= (short)dx)
        goto loc_14cd2;
    if (memoryAGet(ds, di + 4) < 0x65)
        goto loc_14c90;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, di);
    if (!(memoryAGet(ds, di + 5) & 0x80))
        goto loc_14c69;
    ax = -ax;
loc_14c69: // 1020:4a69
    if ((short)ax < 0)
        goto loc_14cd2;
    bx = memoryAGet16(ds, di + 9);
    memoryASet16(ds, bx + 4, 0xffff);
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28538);
    bl &= 0x0f;
    bh = 0;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 28613);
    bx += 0x0065;
    memoryASet16(ds, di + 4, bx);
loc_14c90: // 1020:4a90
    al = 0x09;
    sub_113e6();
    ax = 0;
    memoryASet(ds, 0x6505, al);
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, di + 6, ax);
    memoryASet(ds, 0x6511, 0x04);
    ax = 0xffff;
    tx = memoryAGet16(ds, di + 4); memoryASet16(ds, di + 4, ax); ax = tx;
    memoryASet16(ds, 0x5292, ax);
    memoryASet(ds, 0x6509, 0x10);
    memoryASet(ds, 0x6515, 0x00);
    if (al != 0x31)
        goto loc_14cc1;
    memoryASet(ds, 0x6503, 0x00);
loc_14cc1: // 1020:4ac1
    ax = memoryAGet16(ds, 0x527e);
    ax -= 0x0004;
    memoryASet16(ds, 0x5290, ax);
    sub_15322();
    memoryASet16(ds, 0x528e, ax);
    goto loc_14ce3;
loc_14cd2: // 1020:4ad2
    bx = memoryAGet16(ds, 0x527e);
    dx = memoryAGet16(ds, 0x527c);
loc_14cda: // 1020:4ada
    di += 0x0012;
    cx--;
    if (!cx)
        goto loc_14ce3;
    goto loc_14bca;
loc_14ce3: // 1020:4ae3
    memoryASet(ds, 0x650c, 0x01);
}
void sub_14ce9() // 1020:4ae9
{
    if (memoryAGet16(ds, 0x5292) == 0xffff)
        goto loc_14d48;
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14d48;
    push(ax);
    push(di);
    di = 0x528e;
    ax = 0xffff;
loc_14cff: // 1020:4aff
    di += 0x0012;
    if (memoryAGet16(ds, di + 4) != ax)
        goto loc_14cff;
    tx = memoryAGet16(ds, 0x5292); memoryASet16(ds, 0x5292, ax); ax = tx;
    memoryASet16(ds, di + 4, ax);
    ah &= 0x1f;
    flags.carry = ax < 0x0065;
    al = 0x00;
    if (flags.carry)
        goto loc_14d1a;
    al++;
loc_14d1a: // 1020:4b1a
    memoryASet(ds, di + 11, al);
    ax = memoryAGet16(ds, 0x528e);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, 0x5290);
    memoryASet16(ds, di + 2, ax);
    ax = 0;
    memoryASet(ds, 0x6509, al);
    memoryASet16(ds, di + 12, ax);
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, di + 6, ax);
    memoryASet(ds, di + 8, al);
    ax++;
    memoryASet(ds, 0x650c, al);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet16(ds, 0x64e9, di);
    di = pop();
    ax = pop();
loc_14d48: // 1020:4b48
    return;
}
void sub_14d49() // 1020:4b49
{
    if (memoryAGet(ds, 0x0459) == 0x00)
        goto loc_14d7c;
loc_14d50: // 1020:4b50
    sync();
    if (memoryAGet(ds, 0x0459) != 0x00)
        goto loc_14d50;
    sub_12e87();
    push(memoryAGet16(ds, 0x5280));
    memoryASet16(ds, 0x5280, 0x001d);
    sub_11e61();
    sub_13471();
    memoryASet16(ds, 0x5280, pop());
loc_14d6e: // 1020:4b6e
    sync();
    if (memoryAGet(ds, 0x0459) == 0x00)
        goto loc_14d6e;
loc_14d75: // 1020:4b75
    sync();
    if (memoryAGet(ds, 0x0459) != 0x00)
        goto loc_14d75;
loc_14d7c: // 1020:4b7c
    return;
}
void sub_14d7d() // 1020:4b7d
{
    push(ax);
    push(cx);
    push(dx);
    push(bp);
    ax = 0;
    if (memoryAGet(ds, 0x6507) == 0x00)
        goto loc_14d95;
    ax = memoryAGet16(ds, 0x5285);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
loc_14d95: // 1020:4b95
    cl = memoryAGet(ds, 0x5284);
    ax = sar16(ax, cl);
    dx = memoryAGet16(ds, 0x5282);
    dx += ax;
    if ((short)dx >= (short)bp)
        goto loc_14dad;
    bp = -bp;
    if ((short)dx <= (short)bp)
        goto loc_14dad;
    bp = dx;
loc_14dad: // 1020:4bad
    memoryASet16(ds, 0x5282, bp);
    bp = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_14db6() // 1020:4bb6
{
    push(ax);
    push(cx);
    push(dx);
    dx = memoryAGet16(ds, 0x528a);
    dx += 0xffe0;
    bp = -bp;
    if ((short)dx >= (short)bp)
        goto loc_14dc8;
    bp = dx;
loc_14dc8: // 1020:4bc8
    memoryASet16(ds, 0x528a, bp);
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_14dd0() // 1020:4bd0
{
    push(ax);
    push(cx);
    push(dx);
    dx = memoryAGet16(ds, 0x528a);
    dx += 0x0010;
    if ((short)dx >= (short)bp)
        goto loc_14de0;
    bp = dx;
loc_14de0: // 1020:4be0
    memoryASet16(ds, 0x528a, bp);
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_14de8() // 1020:4be8
{
    push(cx);
    push(dx);
    ch = 0;
    ax = memoryAGet16(ds, 0x5282);
    if ((short)ax >= 0)
        goto loc_14df7;
    ax = -ax;
    ch++;
loc_14df7: // 1020:4bf7
    cl = memoryAGet(ds, 0x5284);
    dx = 0x000c;
    dx >>= cl;
    flags.carry = ax < dx;
    ax -= dx;
    if (!flags.carry)
        goto loc_14e06;
    ax = 0;
loc_14e06: // 1020:4c06
    if (!ch)
        goto loc_14e0c;
    ax = -ax;
loc_14e0c: // 1020:4c0c
    memoryASet16(ds, 0x5282, ax);
    dx = pop();
    cx = pop();
}
void sub_14e12() // 1020:4c12
{
    if (memoryAGet(ds, 0x5287) == al)
        goto loc_14e25;
    memoryASet(ds, 0x5287, al);
    bx = memoryAGet16(ds, bx + 28351);
    memoryASet16(ds, 0x5288, bx);
    goto loc_14e29;
loc_14e25: // 1020:4c25
    bx = memoryAGet16(ds, 0x5288);
loc_14e29: // 1020:4c29
    return;
}
void sub_14e2a() // 1020:4c2a
{
    push(ax);
    push(bx);
    push(dx);
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= 0)
        goto loc_14e37;
    bx += ax;
    ax = memoryAGet16(ds, bx);
loc_14e37: // 1020:4c37
    dh = memoryAGet(ds, 0x5285);
    dh &= 0x80;
    ah |= dh;
    memoryASet16(ds, 0x5280, ax);
    bx++;
    bx++;
    memoryASet16(ds, 0x5288, bx);
    dx = pop();
    bx = pop();
    ax = pop();
}
void sub_14e65() // 1020:4c65
{
    memoryASet(ds, 0x650f, 0x06);
    if (memoryAGet(ds, 0x6514) != 0x00)
        goto loc_14ea1;
    push(ax);
    push(bp);
    bp = 0x0040;
    sub_14d7d();
    bp = 0x00c0;
    sub_14dd0();
    if (memoryAGet(ds, 0x6513) == 0x00)
        goto loc_14e8a;
    al = 0x0f;
    goto loc_14e95;
loc_14e8a: // 1020:4c8a
    al = 0x0a;
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_14e95;
    al = 0x15;
loc_14e95: // 1020:4c95
    ah = memoryAGet(ds, 0x5285);
    ah &= 0x80;
    memoryASet16(ds, 0x5280, ax);
    bp = pop();
    ax = pop();
loc_14ea1: // 1020:4ca1
    return;
}
void sub_14ea2() // 1020:4ca2
{
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
}
void sub_14ea8() // 1020:4ca8
{
    push(ax);
    ax = memoryAGet16(ds, 0x5282);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) - ax);
    memoryASet16(ds, 0x5282, 0x0000);
    if (memoryAGet(ds, 0x6514) == 0x00)
        goto loc_14ed6;
    if (memoryAGet(ds, 0x650f) == 0x06)
        goto loc_14ed6;
    memoryASet(ds, 0x6513, 0x14);
    memoryASet(ds, 0x6514, 0x00);
loc_14ed6: // 1020:4cd6
    ax = pop();
}
void sub_14ed8() // 1020:4cd8
{
    goto loc_14ed8;
loc_14ea2: // 1020:4ca2
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
    return;
    // gap 48 bytes
loc_14ed8: // 1020:4cd8
    memoryASet(ds, 0x651c, 0x01);
    memoryASet(ds, 0x5284, 0x00);
    if ((short)memoryAGet16(ds, 0x528a) >= (short)0x0000)
        goto loc_14eeb;
    goto loc_14ea2;
loc_14eeb: // 1020:4ceb
    memoryASet(ds, 0x527e, memoryAGet(ds, 0x527e) & 0xf0);
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
}
void sub_14ef0() // 1020:4cf0
{
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
}
void sub_14ef6() // 1020:4cf6
{
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
}
void sub_14f0b() // 1020:4d0b
{
}
void sub_14f0c() // 1020:4d0c
{
    sub_14ea8();
}
void sub_14f10() // 1020:4d10 +returnCarry
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    si = 0x7bad;
    cx = 0x0064;
loc_14f1f: // 1020:4d1f
    if (memoryAGet16(ds, si + 2) == di)
        goto loc_14f2b;
    si += 0x0004;
    if (--cx)
        goto loc_14f1f;
    goto loc_14f8f;
loc_14f2b: // 1020:4d2b
    if (memoryAGet(ds, si) < 0xfd)
        goto loc_14f39;
    ax = 0x0006;
    sub_112ff();
    sub_15ba1();
loc_14f39: // 1020:4d39
    al = memoryAGet(ds, si + 1);
    memoryASet(es, di, al);
    bl = 0x50;
    bh = 0x02;
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_14f52;
    sub_134f4();
    bl = 0x28;
    bh = 0x01;
loc_14f52: // 1020:4d52
    ax = di;
    al = ah;
    ah = 0;
    dl = 0x0c;
    div8(dl);
    al = bl;
    mul8(ah);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = di;
    ah = 0;
    dl = 0x14;
    div8(dl);
    al = ah;
    ah = 0;
    cl = bh;
    ax <<= cl;
    di = pop();
    di += ax;
    al = memoryAGet(ds, si + 1);
    sub_12fdc();
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x64f5, 0x01);
    flags.carry = 0;
    goto loc_14f90;
loc_14f8f: // 1020:4d8f
    flags.carry = 1;
loc_14f90: // 1020:4d90
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_14f9a() // 1020:4d9a
{
    ax = 0x0007;
    sub_112ff();
    al = memoryAGet(ds, 0x5250);
    memoryASet(ds, 0x5250, 0x0e);
    push(ax);
    sub_14fb1();
    ax = pop();
    memoryASet(ds, 0x5250, al);
}
void sub_14fb1() // 1020:4db1
{
    ax = 0x0007;
    sub_112ff();
    sub_14f10();
    if (flags.carry)
        goto loc_14fbf;
    sub_10533();
loc_14fbf: // 1020:4dbf
    return;
}
void sub_14fc0() // 1020:4dc0
{
    sub_15be7();
    memoryASet(ds, 0x6516, 0x02);
}
void sub_14fc9() // 1020:4dc9
{
    ax = 0x0005;
    sub_112ff();
    sub_14f10();
    if (flags.carry)
        goto loc_14ff8;
    ax = memoryAGet16(ds, 0x527c);
    memoryASet16(ds, 0x64e4, ax);
    dx = memoryAGet16(ds, 0x527e);
    memoryASet16(ds, 0x64e6, dx);
    bx = memoryAGet16(ds, 0x5292);
    bh &= 0x1f;
    bx -= 0x0038;
    if (bx > 0x0001)
        goto loc_14ff8;
    memoryASet16(ds, 0x64f8, ax);
    memoryASet16(ds, 0x64fa, dx);
loc_14ff8: // 1020:4df8
    return;
}
void sub_14ff9() // 1020:4df9
{
    sub_14ea2();
}
void sub_14ffd() // 1020:4dfd
{
    sub_14ed8();
}
void sub_15001() // 1020:4e01
{
    goto loc_15001;
loc_14ea2: // 1020:4ca2
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
    return;
    // gap 48 bytes
loc_14ed8: // 1020:4cd8
    memoryASet(ds, 0x651c, 0x01);
    memoryASet(ds, 0x5284, 0x00);
    if ((short)memoryAGet16(ds, 0x528a) >= (short)0x0000)
        goto loc_14eeb;
    goto loc_14ea2;
loc_14eeb: // 1020:4ceb
    memoryASet(ds, 0x527e, memoryAGet(ds, 0x527e) & 0xf0);
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
    return;
    // gap 246 bytes
loc_15001: // 1020:4e01
    memoryASet(ds, 0x5284, 0x00);
    if (memoryAGet(ds, 0x6510) != 0x00)
        goto loc_15010;
    goto loc_14ed8;
loc_15010: // 1020:4e10
    goto loc_14ea2;
}
void sub_15013() // 1020:4e13
{
    sub_14ed8();
    memoryASet(ds, 0x5284, 0x01);
}
void sub_1501c() // 1020:4e1c
{
    sub_14ed8();
    memoryASet(ds, 0x5284, 0x02);
}
void sub_15025() // 1020:4e25
{
    sub_14ed8();
    memoryASet(ds, 0x5284, 0x03);
}
void sub_1502e() // 1020:4e2e
{
    goto loc_1502e;
loc_14ff9: // 1020:4df9
    sub_14ea2();
    return;
loc_14ffd: // 1020:4dfd
    sub_14ed8();
    return;
    // gap 45 bytes
loc_1502e: // 1020:4e2e
    if (memoryAGet(ds, 0x6513) != 0x00)
        goto loc_14ff9;
    al = memoryAGet(ds, 0x5287);
    al &= 0x0f;
    if (al == 0x01)
        goto loc_14ffd;
    flags.zero = al == 0x03;
loc_15040: // 1020:4e40
    if (flags.zero)
        goto loc_14ffd;
    if (al == 0x07)
        goto loc_14ffd;
    flags.zero = al == 0x08;
    if (flags.zero)
        goto loc_15040;
    if (al != 0x05)
        goto loc_1505c;
    sub_14ff9();
    memoryASet16(ds, 0x5280, 0x000e);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 0x0008);
loc_1505c: // 1020:4e5c
    push(ds);
    ds = memoryAGet16(ds, 0x526c);
    bl = memoryAGet(ds, di + 65280);
    ds = pop();
    bh = 0;
    ah = memoryAGet(ds, bx + 29603);
    if (ah == 0x06)
        goto loc_1507e;
    flags.zero = al == 0x00;
    if (flags.zero)
        goto loc_15040;
    ah = memoryAGet(ds, 0x042d);
    flags.zero = ax == 0xff06;
    if (flags.zero)
        goto loc_15040;
loc_1507e: // 1020:4e7e
    sub_14ef6();
    memoryASet(ds, 0x650d, 0x01);
}
void sub_15087() // 1020:4e87
{
}
void sub_15088() // 1020:4e88
{
    if (memoryAGet16(ds, 0x528a) == 0x0000)
        goto loc_150a5;
    memoryASet16(ds, 0x528a, 0x0000);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) & 0xfff0);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 0x0010);
    memoryASet(ds, 0x651d, 0xff);
    return;
loc_150a5: // 1020:4ea5
    al = memoryAGet(ds, 0x5280);
    if (al == 0x0a)
        goto loc_15102;
    if (al == 0x15)
        goto loc_15102;
    if (memoryAGet(ds, 0x650f) == 0x06)
        goto loc_15102;
    memoryASet(ds, 0x650e, 0x01);
    if (memoryAGet(ds, 0x6509) == 0x00)
        goto loc_15102;
    sub_14ce9();
    push(bx);
    push(di);
    di = memoryAGet16(ds, 0x64e9);
    cl = 0x04;
    ax = memoryAGet16(ds, di + 2);
    ax = sar16(ax, cl);
    bh = al;
    ax = memoryAGet16(ds, di);
    ax = sar16(ax, cl);
    bl = al;
    di = bx;
    es = memoryAGet16(ds, 0x526c);
    bx = 0x72a3;
    al = memoryAGet(es, di);
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_15100;
    dx = 0x0010;
    al = memoryAGet(es, di + 65535);
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (al)
        goto loc_150fa;
    dx = -dx;
loc_150fa: // 1020:4efa
    di = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, di, memoryAGet16(ds, di) + dx);
loc_15100: // 1020:4f00
    di = pop();
    bx = pop();
loc_15102: // 1020:4f02
    return;
}
void sub_15103() // 1020:4f03
{
    if ((short)memoryAGet16(ds, 0x528a) >= (short)0x0000)
        goto loc_1511b;
    if (memoryAGet16(ds, 0x5282) != 0x0000)
        goto loc_1511b;
    memoryASet(ds, 0x651d, 0x0a);
    memoryASet(ds, 0x650d, 0x01);
loc_1511b: // 1020:4f1b
    return;
}
void sub_1511f() // 1020:4f1f
{
    goto loc_1511f;
loc_1511c: // 1020:4f1c
    goto loc_1523b;
loc_1511f: // 1020:4f1f
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    if ((short)memoryAGet16(ds, si + 14) < (short)0x0000)
        goto loc_1511c;
    si = 0x527c;
    bx = 0;
    sub_15245();
    if (!flags.carry)
        goto loc_1511c;
    memoryASet16(ds, 0x527e, dx);
    di = ax;
    al = memoryAGet(ds, di + 4);
    al -= 0x36;
    if (al > 0x01)
        goto loc_1514e;
    memoryASet(ds, di + 8, memoryAGet(ds, di + 8) | 0x02);
    memoryASet16(ds, di + 9, si);
loc_1514e: // 1020:4f4e
    al = memoryAGet(ds, di + 4);
    al -= 0x33;
    if (al > 0x01)
        goto loc_1517b;
    ax = 0x0060;
    dl = memoryAGet(ds, 0x5281);
    dl &= 0x80;
    if (!dl)
        goto loc_15165;
    ax = -ax;
loc_15165: // 1020:4f65
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) & 0x7f);
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) | dl);
    memoryASet16(ds, di + 6, ax);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x6503, 0x00);
    goto loc_151b9;
loc_1517b: // 1020:4f7b
    if ((short)memoryAGet16(ds, 0x651e) <= (short)0x000a)
        goto loc_151b9;
    if (memoryAGet(ds, 0x5287) & 0x0f)
        goto loc_151b9;
    if (memoryAGet16(ds, 0x528a) != 0x0000)
        goto loc_151b9;
    al = memoryAGet(ds, di + 4);
    if (al == 0x53)
        goto loc_1519b;
    if (al != 0x5e)
        goto loc_151b9;
loc_1519b: // 1020:4f9b
    ax = 0x0030;
    if (!(memoryAGet(ds, 0x5281) & 0x80))
        goto loc_151a7;
    ax = -ax;
loc_151a7: // 1020:4fa7
    memoryASet16(ds, di + 6, ax);
    ah &= 0x80;
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) & 0x7f);
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) | ah);
    memoryASet(ds, 0x6511, 0x04);
loc_151b9: // 1020:4fb9
    dx = 0x0010;
    ax = memoryAGet16(ds, di + 6);
    if (!ax)
        goto loc_151cc;
    if ((short)ax >= 0)
        goto loc_151c7;
    dx = 0;
loc_151c7: // 1020:4fc7
    ax += dx;
    memoryASet16(ds, 0x5282, ax);
loc_151cc: // 1020:4fcc
    if (memoryAGet(ds, 0x6510) != 0x00)
        goto loc_15229;
    if ((short)memoryAGet16(ds, 0x528a) <= (short)0x0030)
        goto loc_15229;
    push(di);
    sub_15333();
    if (flags.zero)
        goto loc_15229;
    ax = memoryAGet16(ds, 0x528a);
    dx = 0xfff0;
    if (memoryAGet(ds, 0x042d) == 0x00)
        goto loc_151f0;
    dx = 0x0030;
loc_151f0: // 1020:4ff0
    if (memoryAGet(ds, 0x042e) != 0x00)
        goto loc_151fb;
    ax += dx;
    if ((short)ax >= 0)
        goto loc_151fd;
loc_151fb: // 1020:4ffb
    ax = 0;
loc_151fd: // 1020:4ffd
    ax = -ax;
    memoryASet16(ds, 0x528a, ax);
    memoryASet16(ds, 0x651e, 0x0000);
    if (memoryAGet16(ds, di + 14) != 0x0000)
        goto loc_1523b;
    al = 0x0c;
    sub_113e6();
    ax = memoryAGet16(ds, 0x528a);
    ax = -ax;
    memoryASet16(ds, di + 14, ax);
    cl = 0x04;
    ax = sar16(ax, cl);
    memoryASet16(ds, di + 2, memoryAGet16(ds, di + 2) - ax);
    memoryASet(ds, 0x6511, 0x04);
    goto loc_1523b;
loc_15229: // 1020:5029
    ax = memoryAGet16(ds, di + 14);
    if (!ax)
        goto loc_15238;
    memoryASet16(ds, 0x528a, ax);
    sub_14ef6();
    goto loc_1523b;
loc_15238: // 1020:5038
    sub_14ef0();
loc_1523b: // 1020:503b
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_15245() // 1020:5045 +returnCarry
{
    push(cx);
    push(di);
    bh &= 0x1f;
    bx <<= 1;
    al = memoryAGet(ds, bx + 27639);
    ah = 0;
    memoryASet16(ds, 0x64ef, ax);
    bl = memoryAGet(ds, bx + 26213);
    bh = 0;
    ax = memoryAGet16(ds, si);
    dx = memoryAGet16(ds, si + 2);
    bx >>= 1;
    ax -= bx;
    memoryASet16(ds, 0x64f1, ax);
    memoryASet16(ds, 0x64f3, dx);
    cx = 0x0028;
    di = 0x52a0;
loc_15271: // 1020:5071
    if (si == di)
        goto loc_1528c;
    bx = memoryAGet16(ds, di + 4);
    if (bx == 0xffff)
        goto loc_1528c;
    bh &= 0x1f;
    if (!(memoryAGet(ds, bx + 28441) & 0x01))
        goto loc_1528c;
    sub_15353();
    if (flags.carry)
        goto loc_15292;
loc_1528c: // 1020:508c
    di += 0x0012;
    if (--cx)
        goto loc_15271;
    flags.carry = 0;
loc_15292: // 1020:5092
    di = pop();
    cx = pop();
}
void sub_15295() // 1020:5095 +returnCarry
{
    push(ax);
    push(bx);
    push(dx);
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, di);
    if ((short)ax >= 0)
        goto loc_152a0;
    ax = -ax;
loc_152a0: // 1020:50a0
    if (ax >= 0x0040)
        goto loc_1531d;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, di + 2);
    if ((short)ax >= 0)
        goto loc_152af;
    ax = -ax;
loc_152af: // 1020:50af
    if (ax >= 0x0046)
        goto loc_1531d;
    ax = memoryAGet16(ds, si + 2);
    dx = memoryAGet16(ds, di + 2);
    bx = memoryAGet16(ds, si + 4);
    if ((short)ax >= (short)dx)
        goto loc_152c5;
    tx = dx; dx = ax; ax = tx;
    bx = memoryAGet16(ds, di + 4);
loc_152c5: // 1020:50c5
    bh &= 0x1f;
    bx <<= 1;
    bl = memoryAGet(ds, bx + 27640);
    bh = 0;
    bx -= 0x0003;
    ax -= bx;
    if ((short)ax >= (short)dx)
        goto loc_1531d;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    bp = bx;
    al = memoryAGet(ds, bx + 26927);
    ah = 0;
    dx = memoryAGet16(ds, si);
    dx -= ax;
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    bx <<= 1;
    ax = memoryAGet16(ds, di);
    flags.carry = al < memoryAGet(ds, bx + 26927);
    al -= memoryAGet(ds, bx + 26927);
    ah = ah - 0x00 - flags.carry;
    bl = memoryAGet(ds, bx + 27639);
    bl >>= 1;
    if ((short)ax < (short)dx)
        goto loc_15310;
    tx = dx; dx = ax; ax = tx;
    bl = memoryAGet(ds, bp + 27639);
    bl >>= 1;
loc_15310: // 1020:5110
    bh = 0;
    ax += bx;
    if ((short)ax <= (short)dx)
        goto loc_1531d;
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = 1;
    return;
loc_1531d: // 1020:511d
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = 0;
}
void sub_15322() // 1020:5122
{
    ax = memoryAGet16(ds, si);
    dx = 0x000c;
    if (!(memoryAGet(ds, si + 5) & 0x80))
        goto loc_15330;
    dx = 0xfff6;
loc_15330: // 1020:5130
    ax += dx;
}
void sub_15333() // 1020:5133 +returnZero +stackDrop2
{
    sp -= 2;
    push(bx);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ds, bx + 4);
    bh &= 0x1f;
    if (bl < 0x65)
        goto loc_15349;
    flags.zero = 0;
    bx = 0;
    goto loc_1534e;
loc_15349: // 1020:5149
    flags.zero = !(memoryAGet(ds, bx + 28441) & 0x02);
loc_1534e: // 1020:514e
    bp = pop();
    bx = pop();
    sp += 2;
    sp += 2;
}
void sub_15353() // 1020:5153 +returnCarry
{
    bx = memoryAGet16(ds, di);
    bx -= ax;
    if ((short)bx >= 0)
        goto loc_1535b;
    bx = -bx;
loc_1535b: // 1020:515b
    if (bx > 0x0040)
        goto loc_153c3;
    bx = memoryAGet16(ds, di + 2);
    bx -= dx;
    if ((short)bx >= 0)
        goto loc_15369;
    bx = -bx;
loc_15369: // 1020:5169
    if (bx > 0x0046)
        goto loc_153c3;
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    bx <<= 1;
    bp = bx;
    bl = memoryAGet(ds, bx + 27639);
    bh = 0;
    push(bx);
    bx >>= 1;
    dx = memoryAGet16(ds, di);
    dx -= bx;
    bx = pop();
    if ((short)dx <= (short)ax)
        goto loc_1538f;
    tx = dx; dx = ax; ax = tx;
    bx = memoryAGet16(ds, 0x64ef);
loc_1538f: // 1020:518f
    dx += bx;
    if ((short)dx <= (short)ax)
        goto loc_153bc;
    bl = memoryAGet(ds, bp + 27640);
    bh = 0;
    bp = bx;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    dx = memoryAGet16(ds, di + 2);
    ax = memoryAGet16(ds, 0x64f3);
    dx -= bx;
    if ((short)dx < (short)ax)
        goto loc_153bc;
    dx += bx;
    dx -= bp;
    if ((short)dx > (short)ax)
        goto loc_153bc;
    ax = di;
    flags.carry = 1;
    return;
loc_153bc: // 1020:51bc
    ax = memoryAGet16(ds, 0x64f1);
    dx = memoryAGet16(ds, 0x64f3);
loc_153c3: // 1020:51c3
    flags.carry = 0;
}
void sub_153c6() // 1020:51c6
{
    ax = 0x168f;
    ds = ax;
    sub_15538();
    memoryASet16(ds, 0x043c, 0x0000);
loc_153d4: // 1020:51d4
    memoryASet(ds, 0x87d4, 0x00);
loc_153d9: // 1020:51d9
    if (memoryAGet16(ds, 0x000a) < 0x07c8)
        goto loc_153f1;
    if (memoryAGet16(ds, 0x043c) < 0x0ca8)
        goto loc_153f1;
    sub_11b1c();
    sub_155c8();
    goto loc_153d4;
loc_153f1: // 1020:51f1
    sync();
    sub_10a05();
    if (memoryAGet(ds, 0x042d) == 0x00)
        goto loc_1540b;
    if (memoryAGet(ds, 0x87d4) == 0x00)
        goto loc_1540b;
    sub_15452();
    memoryASet(ds, 0x87d4, memoryAGet(ds, 0x87d4) - 1);
    goto loc_153d9;
loc_1540b: // 1020:520b
    if (memoryAGet(ds, 0x042e) == 0x00)
        goto loc_15422;
    if (memoryAGet(ds, 0x87d4) != 0x00)
        goto loc_15422;
    sub_15452();
    memoryASet(ds, 0x87d4, memoryAGet(ds, 0x87d4) + 1);
    goto loc_153d9;
loc_15422: // 1020:5222
    if (memoryAGet(ds, 0x042b) != 0x00)
        goto loc_1542b;
    goto loc_153d9;
loc_1542b: // 1020:522b
    if (memoryAGet(ds, 0x87d4) == 0x00)
        goto loc_15444;
    sub_1047b();
    if (flags.carry)
        goto loc_1543a;
    memoryASet(ds, 0x5250, al);
loc_1543a: // 1020:523a
    sub_155c8();
    memoryASet(ds, 0x87d4, 0x00);
    goto loc_153d9;
loc_15444: // 1020:5244
    sync();
    sub_10a05();
    if (memoryAGet(ds, 0x042b) != 0x00)
        goto loc_15444;
    sub_15845();
}
void sub_15452() // 1020:5252
{
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_15460;
    if (al >= 0x03)
        goto loc_1548b;
    goto loc_154bb;
loc_15460: // 1020:5260
    push(ds);
    ax = 0xa000;
    ds = ax;
    si = 0xc878;
    di = 0xd8b8;
    dx = 0x0008;
loc_1546f: // 1020:526f
    cx = 0x0004;
loc_15472: // 1020:5272
    ax = memoryAGet16(ds, di);
    tx = memoryAGet16(ds, si); memoryASet16(ds, si, ax); ax = tx;
    memoryASet16(ds, di, ax);
    si++;
    si++;
    di++;
    di++;
    if (--cx)
        goto loc_15472;
    si += 0x0138;
    di += 0x0138;
    dx--;
    if (dx)
        goto loc_1546f;
    ds = pop();
    return;
loc_1548b: // 1020:528b
    push(ds);
    ax = 0xa000;
    ds = ax;
    sub_134f4();
    cx = 0x0008;
    si = 0x190f;
    di = 0x1b17;
loc_1549d: // 1020:529d
    al = memoryAGet(ds, si);
    memoryASet(ds, 0x0000, al);
    al = memoryAGet(ds, di);
    memoryASet(ds, si, al);
    al = memoryAGet(ds, 0x0000);
    memoryASet(ds, di, al);
    al = memoryAGet(ds, 0x0001);
    memoryASet(ds, 0x0000, al);
    si += 0x0028;
    di += 0x0028;
    if (--cx)
        goto loc_1549d;
    ds = pop();
    return;
loc_154bb: // 1020:52bb
    push(ds);
    push(es);
    ax = 0xb800;
    ds = ax;
    es = ax;
    cx = 0x0005;
    si = 0x191e;
    di = 0x1afe;
loc_154cd: // 1020:52cd
    ax = memoryAGet16(ds, si);
    tx = memoryAGet16(es, di); memoryASet16(es, di, ax); ax = tx;
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, si + 8192);
    tx = memoryAGet16(es, di + 8192); memoryASet16(es, di + 8192, ax); ax = tx;
    memoryASet16(ds, si + 8192, ax);
    si += 0x0050;
    di += 0x0050;
    if (--cx)
        goto loc_154cd;
    es = pop();
    ds = pop();
}
void sub_154ec() // 1020:52ec
{
    ax = 0x168f;
    ds = ax;
    al = memoryAGet(cs, 0x0001);
    if (al != 0x05)
        goto loc_15515;
    push(ds);
    dx = 0x878c;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x526c, ax);
    ax = 0x000f;
    sub_112ff();
    sub_15757();
    ds = pop();
    return;
loc_15515: // 1020:5315
    push(ds);
    dx = 0x8796;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x526c, ax);
    ax = 0x000f;
    sub_112ff();
    memoryASet16(cs, 0x6676, 0x6678);
    sub_15677();
    ds = pop();
}
void sub_15538() // 1020:5338
{
    ax = 0x168f;
    ds = ax;
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_1554b;
    if (al >= 0x03)
        goto loc_15573;
    goto loc_15573;
loc_1554b: // 1020:534b
    push(ds);
    dx = 0x87a3;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x526c, ax);
    if (memoryAGet(ds, 0x87d3) == 0x00)
        goto loc_15566;
    sub_105f2();
loc_15566: // 1020:5366
    memoryASet(ds, 0x87d3, 0x01);
    sub_15845();
    sub_15757();
    ds = pop();
    return;
loc_15573: // 1020:5373
    push(ds);
    dx = 0x87ac;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x526c, ax);
    if (memoryAGet(ds, 0x87d3) == 0x00)
        goto loc_1558e;
    sub_105f2();
loc_1558e: // 1020:538e
    memoryASet(ds, 0x87d3, 0x01);
    sub_11e30();
    memoryASet16(cs, 0x6676, 0x6698);
    sub_15677();
    ds = pop();
}
void sub_155a2() // 1020:53a2
{
    ax = 0x168f;
    ds = ax;
    push(ds);
    dx = 0x87b8;
    push(ds);
    push(es);
    sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, ax);
    memoryASet16(ds, 0x526c, ax);
    sub_15757();
    cx = 0x0046;
loc_155be: // 1020:53be
    sub_13443();
    if (--cx)
        goto loc_155be;
    sub_15845();
    ds = pop();
}
void sub_155c8() // 1020:53c8
{
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_155d9;
    if (al < 0x03)
        goto loc_155d7;
    goto loc_15677;
loc_155d7: // 1020:53d7
    goto loc_15625;
loc_155d9: // 1020:53d9
    push(ds);
    ax = 0x0013;
    interrupt(0x10);
    sub_11e30();
    sub_13443();
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    si = 0;
    ax = 0xa000;
    es = ax;
    dx = 0x03c8;
    al = 0x00;
    out8(dx, al);
    dx++;
    cx = 0x0100;
loc_155ff: // 1020:53ff
    al = lodsb<DS_SI>();
    goto loc_15602;
loc_15602: // 1020:5402
    out8(dx, al);
    al = lodsb<DS_SI>();
    goto loc_15606;
loc_15606: // 1020:5406
    out8(dx, al);
    al = lodsb<DS_SI>();
    goto loc_1560a;
loc_1560a: // 1020:540a
    out8(dx, al);
    if (--cx)
        goto loc_155ff;
    si = ds;
    si += 0x0030;
    ds = si;
    si = 0;
    cx = 0x7d00;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    sub_13443();
    sub_11e1a();
    ds = pop();
    return;
loc_15625: // 1020:5425
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    goto loc_1564d;
loc_15639: // 1020:5439
    sub_13360();
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    si = 0;
    ax = 0x28c8;
    sub_167be();
loc_1564d: // 1020:544d
    si = 0;
    di = 0;
    ax = 0xb800;
    es = ax;
    dx = 0x0064;
loc_15659: // 1020:5459
    cx = 0x0028;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di += 0x1fb0;
    cl = 0x28;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di -= 0x2000;
    dx--;
    if (dx)
        goto loc_15659;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_15677: // 1020:5477
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_15639;
    ax = 0x000d;
    interrupt(0x10);
    sub_11e30();
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    si = 0;
    di = 0;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0102;
loc_156a8: // 1020:54a8
    out16(dx, ax);
    cx = 0x0fa0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di = 0;
    ah <<= 1;
    if (ah < 0x10)
        goto loc_156a8;
    sub_11e1a();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_15677() // 1020:5477
{
    goto loc_15677;
loc_15639: // 1020:5439
    sub_13360();
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    si = 0;
    ax = 0x28c8;
    sub_167be();
    si = 0;
    di = 0;
    ax = 0xb800;
    es = ax;
    dx = 0x0064;
loc_15659: // 1020:5459
    cx = 0x0028;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di += 0x1fb0;
    cl = 0x28;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di -= 0x2000;
    dx--;
    if (dx)
        goto loc_15659;
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_15677: // 1020:5477
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    if (memoryAGet(cs, 0x0001) < 0x03)
        goto loc_15639;
    ax = 0x000d;
    interrupt(0x10);
    sub_11e30();
    ax = 0x168f;
    ds = ax;
    ds = memoryAGet16(ds, 0x526c);
    si = 0;
    di = 0;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0102;
loc_156a8: // 1020:54a8
    out16(dx, ax);
    cx = 0x0fa0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di = 0;
    ah <<= 1;
    if (ah < 0x10)
        goto loc_156a8;
    sub_11e1a();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_15757() // 1020:5557
{
    goto loc_15757;
loc_156c4: // 1020:54c4
    sub_13360();
    sub_1582d();
    bx = 0x66e0;
    ax = 0xb800;
    es = ax;
    di = 0;
    dl = 0xc8;
loc_156d6: // 1020:54d6
    ch = 0x50;
loc_156d8: // 1020:54d8
    ah = 0;
    cl = 0x04;
loc_156dc: // 1020:54dc
    al = lodsb<DS_SI>();
    al = memoryAGet(cs, bx+al);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    ah = rcl8(ah, 0x01);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    ah = rcl8(ah, 0x01);
    cl--;
    if (cl)
        goto loc_156dc;
    memoryASet(es, di, ah);
    di++;
    ch--;
    if (ch)
        goto loc_156d8;
    if ((short)di < (short)0x2000)
        goto loc_156ff;
    di -= 0x2000;
    goto loc_15703;
loc_156ff: // 1020:54ff
    di += 0x1fb0;
loc_15703: // 1020:5503
    dl--;
    if (dl)
        goto loc_156d6;
    return;
loc_15708: // 1020:5508
    ax = 0x000d;
    interrupt(0x10);
    sub_11e30();
    sub_1582d();
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx++;
    bl = 0x01;
loc_1571c: // 1020:551c
    al = bl;
    out8(dx, al);
loc_1571f: // 1020:551f
    ah = 0;
    cl = 0x08;
loc_15723: // 1020:5523
    al = lodsb<DS_SI>();
    flags.carry = 0;
    if (!(bl & al))
        goto loc_15729;
    flags.carry = 1;
loc_15729: // 1020:5529
    ah = rcl8(ah, 0x01);
    cl--;
    if (cl)
        goto loc_15723;
    al = ah;
    stosb<ES_DI>(al);
    if (si < 0xfa00)
        goto loc_1571f;
    di = 0;
    si -= 0xfa00;
    bl <<= 1;
    if (bl < 0x10)
        goto loc_1571c;
    ax = 0x168f;
    es = ax;
    dx = 0x87c2;
    ax = 0x1002;
    interrupt(0x10);
    sub_11e1a();
    return;
    // gap 1 bytes
loc_15757: // 1020:5557
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_15766;
    if (al >= 0x03)
        goto loc_15708;
    goto loc_156c4;
loc_15766: // 1020:5566
    push(ds);
    ax = 0x0013;
    interrupt(0x10);
    sub_11e30();
    sub_13443();
    dx = 0x03c8;
    al = 0x00;
    out8(dx, al);
    dx++;
    cx = 0x0300;
loc_1577c: // 1020:557c
    out8(dx, al);
    if (--cx)
        goto loc_1577c;
    sub_1582d();
    cx = 0x7d00;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    sub_13443();
    sub_11e1a();
    si = ds;
    si -= 0x0030;
    ds = si;
loc_15794: // 1020:5594
    memoryASet(cs, 0x5556, 0x00);
    si = 0;
    bp = 0;
loc_1579e: // 1020:559e
    if (memoryAGet(cs, 0x5556) & 0x0f)
        goto loc_157a9;
    sub_13443();
loc_157a9: // 1020:55a9
    if (memoryAGet(cs, 0x0003) == 0x00)
        goto loc_1581d;
    dx = 0x03c7;
    al = memoryAGet(cs, 0x5556);
    out8(dx, al);
    dl = 0xc9;
    goto loc_157bd;
loc_157bd: // 1020:55bd
    al = in8(dx);
    al &= 0x3f;
    ah = al;
    goto loc_157c4;
loc_157c4: // 1020:55c4
    al = in8(dx);
    al &= 0x3f;
    bl = al;
    goto loc_157cb;
loc_157cb: // 1020:55cb
    al = in8(dx);
    al &= 0x3f;
    bh = al;
    dl = 0xc8;
    al = memoryAGet(cs, 0x5556);
    out8(dx, al);
    dx++;
    al = ah;
    if (memoryAGet(ds, si) <= al)
        goto loc_157e5;
    if (al > 0x3d)
        goto loc_157e5;
    al += 0x02;
    bp++;
loc_157e5: // 1020:55e5
    out8(dx, al);
    al = bl;
    if (memoryAGet(ds, si + 1) <= al)
        goto loc_157f4;
    if (al > 0x3d)
        goto loc_157f4;
    al += 0x02;
    bp++;
loc_157f4: // 1020:55f4
    out8(dx, al);
    al = bh;
    if (memoryAGet(ds, si + 2) <= al)
        goto loc_15803;
    if (al > 0x3d)
        goto loc_15803;
    al += 0x02;
    bp++;
loc_15803: // 1020:5603
    out8(dx, al);
    si += 0x0003;
    memoryASet(cs, 0x5556, memoryAGet(cs, 0x5556) + 1);
    if (memoryAGet(cs, 0x5556) < 0x40)
        goto loc_1579e;
    if (!bp)
        goto loc_1581b;
    goto loc_15794;
loc_1581b: // 1020:561b
    goto loc_1582b;
loc_1581d: // 1020:561d
    dx = 0x03c8;
    al = 0x00;
    out8(dx, al);
    dx++;
    cx = 0x00c0;
loc_15827: // 1020:5627
    al = lodsb<DS_SI>();
    out8(dx, al);
    if (--cx)
        goto loc_15827;
loc_1582b: // 1020:562b
    ds = pop();
}
void sub_1582d() // 1020:562d
{
    ax = 0x168f;
    ds = ax;
    si = memoryAGet16(ds, 0x526c);
    si += 0x0030;
    ds = si;
    si = 0;
    ax = 0xa000;
    es = ax;
    di = 0;
}
void sub_15845() // 1020:5645
{
loc_15845: // 1020:5645
    if (memoryAGet(cs, 0x0003) == 0x00)
        goto loc_158cb;
    al = memoryAGet(cs, 0x0001);
    if (al == 0x05)
        goto loc_15856;
    return;
loc_15856: // 1020:5656
    memoryASet(cs, 0x5556, 0x00);
    bp = 0;
loc_1585e: // 1020:565e
    if (memoryAGet(cs, 0x5556) & 0x0f)
        goto loc_15869;
    sub_13443();
loc_15869: // 1020:5669
    dx = 0x03c7;
    al = memoryAGet(cs, 0x5556);
    out8(dx, al);
    dl = 0xc9;
    goto loc_15875;
loc_15875: // 1020:5675
    al = in8(dx);
    al &= 0x3f;
    ah = al;
    goto loc_1587c;
loc_1587c: // 1020:567c
    al = in8(dx);
    al &= 0x3f;
    bl = al;
    goto loc_15883;
loc_15883: // 1020:5683
    al = in8(dx);
    al &= 0x3f;
    bh = al;
    dl = 0xc8;
    al = memoryAGet(cs, 0x5556);
    out8(dx, al);
    dx++;
    al = ah;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    bp |= ax;
    out8(dx, al);
    al = bl;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    bp |= ax;
    out8(dx, al);
    al = bh;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    flags.carry = al < 0x01;
    al -= 0x01;
    al += 0x00 + flags.carry;
    bp |= ax;
    out8(dx, al);
    memoryASet(cs, 0x5556, memoryAGet(cs, 0x5556) + 1);
    if (memoryAGet(cs, 0x5556) < 0x40)
        goto loc_1585e;
    if (!bp)
        goto loc_158cb;
    goto loc_15845;
loc_158cb: // 1020:56cb
    return;
}
void sub_158cc() // 1020:56cc
{
    push(si);
    push(cx);
    push(bx);
    ax = 0x168f;
    ds = ax;
    si = 0x7699;
    cx = 0x0032;
    memoryASet(ds, 0x64fd, 0x00);
loc_158df: // 1020:56df
    di = 0x87d3;
    ax = memoryAGet16(ds, si + 4);
    if (ax == 0xffff)
        goto loc_15900;
    ah &= 0x1f;
loc_158ed: // 1020:56ed
    di++;
    di++;
    if (memoryAGet16(ds, di) != ax)
        goto loc_158ed;
    memoryASet16(ds, si + 10, di);
    di = ax;
    al = memoryAGet(ds, di + 28869);
    memoryASet(ds, 0x64fd, memoryAGet(ds, 0x64fd) + al);
loc_15900: // 1020:5700
    si += 0x001a;
    if (--cx)
        goto loc_158df;
    si = 0x7dcb;
    cx = 0x000a;
loc_1590b: // 1020:570b
    ax = memoryAGet16(ds, si + 12);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, si + 14);
    memoryASet16(ds, si + 2, ax);
    al = memoryAGet(ds, si + 16);
    memoryASet(ds, si + 6, al);
    memoryASet16(ds, si + 17, 0x0000);
    si += 0x0014;
    if (--cx)
        goto loc_1590b;
    bl = memoryAGet(ds, 0x5250);
    bh = 0;
    al = memoryAGet(ds, bx + 20660);
    memoryASet(ds, 0x64e8, al);
    bx = pop();
    cx = pop();
    si = pop();
}
void sub_15937() // 1020:5737
{
    sp -= 2;
    si = 0x7699;
    di = 0x5570;
    bp = 0xffff;
    memoryASet16(ds, 0x5574, bp);
    memoryASet16(ds, 0x5586, bp);
    memoryASet16(ds, 0x5598, bp);
    memoryASet16(ds, 0x55aa, bp);
    memoryASet16(ds, 0x55bc, bp);
    memoryASet16(ds, 0x55ce, bp);
    memoryASet16(ds, 0x55e0, bp);
    memoryASet16(ds, 0x55f2, bp);
    ax = memoryAGet16(ds, 0x5270);
    dx = memoryAGet16(ds, 0x5272);
    cl = 0x04;
    ax <<= cl;
    dx <<= cl;
    cx = 0x0032;
loc_15970: // 1020:5770
    if (memoryAGet16(ds, si + 4) != bp)
        goto loc_15978;
    goto loc_15aa6;
loc_15978: // 1020:5778
    memoryASet(ds, si + 5, memoryAGet(ds, si + 5) & 0xdf);
    bx = memoryAGet16(ds, si);
    bx += 0x0020;
    flags.carry = bx < ax;
    bx -= ax;
    if (!flags.carry)
        goto loc_15988;
    goto loc_15a9d;
loc_15988: // 1020:5788
    bx -= 0x0040;
    if ((short)bx <= (short)0x0140)
        goto loc_15994;
    goto loc_15a9d;
loc_15994: // 1020:5794
    bx = memoryAGet16(ds, si + 2);
    flags.carry = bx < dx;
    bx -= dx;
    if (!flags.carry)
        goto loc_1599e;
    goto loc_15a9d;
loc_1599e: // 1020:579e
    bx -= 0x0020;
    if ((short)bx <= (short)0x00c0)
        goto loc_159aa;
    goto loc_15a9d;
loc_159aa: // 1020:57aa
    memoryASet(ds, si + 5, memoryAGet(ds, si + 5) | 0x20);
    push(ax);
    push(dx);
    sub_166ff();
    memoryASet16(ds, di + 9, si);
    bx = memoryAGet16(ds, si);
    memoryASet16(ds, di, bx);
    bx = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, bx);
    push(cx);
    push(si);
    if (!(memoryAGet(ds, si + 7) & 0xc0))
        goto loc_159cb;
    goto loc_15a91;
loc_159cb: // 1020:57cb
    if (memoryAGet(ds, 0x6514) != 0x00)
        goto loc_159e8;
    if (memoryAGet16(ds, si + 4) != 0x05aa)
        goto loc_159dc;
    goto loc_15a91;
loc_159dc: // 1020:57dc
    bx = memoryAGet16(ds, si + 6);
    bh &= 0x1f;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_15c04(); break;
        case 2: sub_15c04(); break;
        case 4: sub_15c04(); break;
        case 6: sub_15c04(); break;
        case 8: sub_15c04(); break;
        case 10: sub_15c04(); break;
        case 12: sub_15c04(); break;
        case 14: sub_15c04(); break;
        case 16: sub_15c04(); break;
        case 18: sub_15c04(); break;
        case 20: sub_15c04(); break;
        case 22: sub_15c04(); break;
        case 24: sub_15c04(); break;
        case 26: sub_15c04(); break;
        case 28: sub_15c04(); break;
        case 30: sub_15c03(); break;
        case 32: sub_15c03(); break;
        case 34: sub_15c03(); break;
        case 36: sub_15c04(); break;
        default:
            stop("ind 1020:57e4");
    }
loc_159e8: // 1020:57e8
    if (memoryAGet(ds, 0x6511) == 0x00)
        goto loc_15a25;
    si = 0x52a0;
    cx = 0x0028;
loc_159f5: // 1020:57f5
    if (memoryAGet16(ds, si + 6) != 0x0000)
        goto loc_15a0a;
    ax = memoryAGet16(ds, si + 14);
    if (!ax)
        goto loc_15a20;
    ax = memoryAGet16(ds, si + 12);
    if (ax < 0x000a)
        goto loc_15a20;
loc_15a0a: // 1020:580a
    ax = bx;
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    flags.zero = !(memoryAGet(ds, bx + 28441) & 0x10);
    bx = ax;
    if (!flags.zero)
        goto loc_15a20;
    sub_15295();
    if (flags.carry)
        goto loc_15a4e;
loc_15a20: // 1020:5820
    si += 0x0012;
    if (--cx)
        goto loc_159f5;
loc_15a25: // 1020:5825
    if (memoryAGet(ds, 0x650a) == 0x00)
        goto loc_15a91;
    if (memoryAGet(ds, 0x6509) != 0x00)
        goto loc_15a91;
    si = 0x528e;
    if (memoryAGet16(ds, si + 4) == 0xffff)
        goto loc_15a91;
    sub_15295();
    if (!flags.carry)
        goto loc_15a91;
    memoryASet(ds, 0x651b, 0x00);
    memoryASet16(ds, si + 4, 0xffff);
    sub_15ab0();
loc_15a4e: // 1020:584e
    if (memoryAGet(ds, si + 4) == 0x49)
        goto loc_15a57;
    memoryASet16(ds, si + 6, -memoryAGet16(ds, si + 6));
loc_15a57: // 1020:5857
    al = 0x01;
    sub_113e6();
    memoryASet(ds, 0x650a, 0x00);
    bx = memoryAGet16(ds, di + 4);
    bh &= 0x1f;
    if (memoryAGet(ds, bx + 28768) == 0x00)
        goto loc_15a88;
    if (memoryAGet(ds, 0x651b) != 0x00)
        goto loc_15a91;
    memoryASet(ds, 0x651b, 0x0a);
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) | 0x40);
    memoryASet(ds, 0x64e8, memoryAGet(ds, 0x64e8) - 1);
    if (memoryAGet(ds, 0x64e8))
        goto loc_15a91;
    memoryASet(ds, 0x64fd, memoryAGet(ds, 0x64fd) - 1);
loc_15a88: // 1020:5888
    bp = sp;
    si = memoryAGet16(ss, bp);
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x80);
loc_15a91: // 1020:5891
    si = pop();
    cx = pop();
    bp = 0xffff;
    di += 0x0012;
    dx = pop();
    ax = pop();
    goto loc_15aa6;
loc_15a9d: // 1020:589d
    if (!(memoryAGet(ds, si + 7) & 0xc0))
        goto loc_15aa6;
    memoryASet16(ds, si + 4, bp);
loc_15aa6: // 1020:58a6
    si += 0x001a;
    cx--;
    if (!cx)
        goto loc_15aaf;
    goto loc_15970;
loc_15aaf: // 1020:58af
    sp += 2;
    return;
}
void sub_15ab0() // 1020:58b0
{
    memoryASet16(ds, 0x5292, 0x002d);
    memoryASet16(ds, 0x5294, 0x0000);
    memoryASet16(ds, 0x529c, 0x0000);
    memoryASet(ds, 0x6515, 0x05);
}
void sub_15ac8() // 1020:58c8
{
    si = 0x5600;
    dx = 0x0004;
    cl = 0x04;
loc_15ad0: // 1020:58d0
    if (memoryAGet16(ds, si + 4) == 0xffff)
        goto loc_15b26;
    ax = memoryAGet16(ds, si + 6);
    flags.zero = !ax;
    if (flags.zero)
        goto loc_15af0;
    ax = sar16(ax, cl);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    ax = memoryAGet16(ds, si);
    ax >>= cl;
    flags.carry = ax < memoryAGet16(ds, 0x5270);
    ax -= memoryAGet16(ds, 0x5270);
    if (flags.carry)
        goto loc_15b0a;
    flags.zero = ax == 0x0014;
    if ((short)ax > (short)0x0014)
        goto loc_15b0a;
loc_15af0: // 1020:58f0
    ax = memoryAGet16(ds, si + 14);
    if (flags.zero)
        goto loc_15b11;
    ax = sar16(ax, cl);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    ax = memoryAGet16(ds, si + 2);
    ax >>= cl;
    flags.carry = ax < memoryAGet16(ds, 0x5272);
    ax -= memoryAGet16(ds, 0x5272);
    if (flags.carry)
        goto loc_15b0a;
    if ((short)ax <= (short)0x00c0)
        goto loc_15b11;
loc_15b0a: // 1020:590a
    memoryASet16(ds, si + 4, 0xffff);
    goto loc_15b26;
loc_15b11: // 1020:5911
    di = 0x527c;
    sub_15295();
    if (!flags.carry)
        goto loc_15b26;
    bp = 0x0046;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, si + 6);
    sub_15b6f();
    goto loc_15b0a;
loc_15b26: // 1020:5926
    si += 0x0012;
    dx--;
    if (dx)
        goto loc_15ad0;
}
void sub_15b2d() // 1020:592d +returnCarry
{
    di = 0x5600;
    push(cx);
    cx = 0x0004;
loc_15b34: // 1020:5934
    if (memoryAGet16(ds, di + 4) != 0xffff)
        goto loc_15b3d;
    cx = pop();
    flags.carry = 0;
    return;
loc_15b3d: // 1020:593d
    di += 0x0012;
    if (--cx)
        goto loc_15b34;
    cx = pop();
    flags.carry = 1;
}
void sub_15b45() // 1020:5945
{
    ax = 0x168f;
    ds = ax;
    memoryASet16(ds, 0x8eb3, 0x0032);
    si = 0x7699;
loc_15b53: // 1020:5953
    if (memoryAGet16(ds, si + 4) == 0xffff)
        goto loc_15b65;
    bx = memoryAGet16(ds, si + 6);
    bh &= 0x1f;
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_165bf(); break;
        case 2: sub_165bf(); break;
        case 4: sub_165f1(); break;
        case 6: sub_164c9(); break;
        case 8: sub_164c9(); break;
        case 10: sub_1642e(); break;
        case 12: sub_1642e(); break;
        case 14: sub_162e0(); break;
        case 16: sub_1620f(); break;
        case 18: sub_160f2(); break;
        case 20: sub_15fce(); break;
        case 22: sub_15eca(); break;
        case 24: sub_15e60(); break;
        case 26: sub_15dbb(); break;
        case 28: sub_16209(); break;
        case 30: sub_161f9(); break;
        case 32: sub_161fe(); break;
        case 34: sub_15d4e(); break;
        case 36: sub_15cb8(); break;
        case 38: sub_15c04(); break;
        case 40: sub_15c04(); break;
        case 42: sub_15c04(); break;
        case 44: sub_15c04(); break;
        case 46: sub_15c04(); break;
        case 48: sub_15c04(); break;
        case 50: sub_15c04(); break;
        case 52: sub_15c04(); break;
        case 54: sub_15c04(); break;
        case 56: sub_15c04(); break;
        case 58: sub_15c04(); break;
        case 60: sub_15c04(); break;
        case 62: sub_15c04(); break;
        case 64: sub_15c04(); break;
        case 66: sub_15c04(); break;
        case 68: sub_15c03(); break;
        case 70: sub_15c03(); break;
        case 72: sub_15c03(); break;
        case 74: sub_15c04(); break;
        default:
            stop("ind 1020:5961");
    }
loc_15b65: // 1020:5965
    si += 0x001a;
    memoryASet16(ds, 0x8eb3, memoryAGet16(ds, 0x8eb3) - 1);
    if (memoryAGet16(ds, 0x8eb3))
        goto loc_15b53;
}
void sub_15b6f() // 1020:596f
{
    push(ax);
    al = 0x04;
    sub_113e6();
    ax = pop();
    sub_15bcc();
    sub_15bcc();
    memoryASet(ds, 0x6514, 0x18);
    memoryASet(ds, 0x6513, 0x00);
    memoryASet(ds, 0x5287, 0x00);
    if ((short)memoryAGet16(ds, 0x527c) > (short)ax)
        goto loc_15b93;
    bp = -bp;
loc_15b93: // 1020:5993
    memoryASet16(ds, 0x5282, bp);
    memoryASet16(ds, 0x528a, 0xff80);
    sub_14ce9();
}
void sub_15ba1() // 1020:59a1
{
    memoryASet(ds, 0x6506, 0x32);
    memoryASet(ds, 0x0419, memoryAGet(ds, 0x0419) + 1);
    if (memoryAGet(ds, 0x0419) <= 0x10)
        goto loc_15bba;
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) + 1);
loc_15bba: // 1020:59ba
    return;
}
void sub_15bcc() // 1020:59cc
{
    memoryASet(ds, 0x6506, 0x32);
    if (memoryAGet(ds, 0x6516) != 0x00)
        goto loc_15be6;
    memoryASet(ds, 0x0419, memoryAGet(ds, 0x0419) - 1);
    if ((char)memoryAGet(ds, 0x0419) >= 0)
        goto loc_15be6;
    memoryASet(ds, 0x0419, 0x00);
    sub_15be7();
loc_15be6: // 1020:59e6
    return;
}
void sub_15be7() // 1020:59e7
{
    memoryASet(ds, 0x6516, 0x0a);
    if (memoryAGet(ds, 0x041b) == 0x00)
        goto loc_15bfd;
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) - 1);
    memoryASet(ds, 0x6506, 0x00);
    return;
loc_15bfd: // 1020:59fd
    memoryASet(ds, 0x6517, 0x01);
}
void sub_15c03() // 1020:5a03
{
}
void sub_15c04() // 1020:5a04
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    si = 0x527c;
    sub_15295();
    if (!flags.carry)
        goto loc_15c40;
    bx = memoryAGet16(ds, di + 9);
    if (memoryAGet(ds, bx + 6) == 0x0b)
        goto loc_15c2c;
    ax = memoryAGet16(ds, bx + 4);
    ah &= 0x1f;
    if (ax == 0x00b2)
        goto loc_15c2c;
    memoryASet16(ds, bx + 8, -memoryAGet16(ds, bx + 8));
loc_15c2c: // 1020:5a2c
    ax = memoryAGet16(ds, di + 4);
    ah &= 0x1f;
    ax -= 0x009a;
    if (ax > 0x0002)
        goto loc_15c3f;
    memoryASet(ds, 0x6501, 0x01);
loc_15c3f: // 1020:5a3f
    flags.carry = 1;
loc_15c40: // 1020:5a40
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    if (!flags.carry)
        goto loc_15c57;
    bp = memoryAGet16(ds, si + 12);
    if (!bp)
        goto loc_15c57;
    ax = memoryAGet16(ds, si);
    sub_15b6f();
loc_15c57: // 1020:5a57
    return;
}
void sub_15cb8() // 1020:5ab8
{
    goto loc_15cb8;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
loc_15cb8: // 1020:5ab8
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_15cc1;
    goto loc_15c58;
loc_15cc1: // 1020:5ac1
    ax = memoryAGet16(ds, si + 20);
    dx = memoryAGet16(ds, si + 15);
    ax -= dx;
    if ((short)memoryAGet16(ds, 0x527c) < (short)ax)
        goto loc_15d21;
    ax += dx;
    ax += dx;
    if ((short)memoryAGet16(ds, 0x527c) > (short)ax)
        goto loc_15d21;
    ax = memoryAGet16(ds, si + 22);
    dx = memoryAGet16(ds, si + 17);
    ax -= dx;
    if ((short)memoryAGet16(ds, 0x527e) < (short)ax)
        goto loc_15d21;
    ax += dx;
    ax += dx;
    if ((short)memoryAGet16(ds, 0x527e) > (short)ax)
        goto loc_15d21;
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_15cfa;
    ax = -ax;
loc_15cfa: // 1020:5afa
    dx = memoryAGet16(ds, si);
    if (memoryAGet16(ds, 0x527c) == dx)
        goto loc_15d0b;
    if ((short)memoryAGet16(ds, 0x527c) < (short)dx)
        goto loc_15d06;
    ax = -ax;
loc_15d06: // 1020:5b06
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
loc_15d0b: // 1020:5b0b
    al = memoryAGet(ds, si + 19);
    dx = memoryAGet16(ds, si + 2);
    if (memoryAGet16(ds, 0x527e) == dx)
        goto loc_15d1f;
    if ((short)memoryAGet16(ds, 0x527e) < (short)dx)
        goto loc_15d1b;
    al = -al;
loc_15d1b: // 1020:5b1b
    cbw();
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
loc_15d1f: // 1020:5b1f
    goto loc_15d4d;
loc_15d21: // 1020:5b21
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_15d2a;
    ax = -ax;
loc_15d2a: // 1020:5b2a
    dx = memoryAGet16(ds, si);
    if (memoryAGet16(ds, si + 20) == dx)
        goto loc_15d3a;
    if ((short)memoryAGet16(ds, si + 20) < (short)dx)
        goto loc_15d35;
    ax = -ax;
loc_15d35: // 1020:5b35
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
loc_15d3a: // 1020:5b3a
    al = memoryAGet(ds, si + 19);
    dx = memoryAGet16(ds, si + 2);
    if (memoryAGet16(ds, si + 22) == dx)
        goto loc_15d4d;
    if ((short)memoryAGet16(ds, si + 22) < (short)dx)
        goto loc_15d49;
    al = -al;
loc_15d49: // 1020:5b49
    cbw();
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
loc_15d4d: // 1020:5b4d
    return;
}
void sub_15d4e() // 1020:5b4e
{
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) & 0x3f);
    ax = memoryAGet16(ds, si + 19);
    ax++;
    if (memoryAGet16(ds, si + 17) > ax)
        goto loc_15db7;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_15d65;
    ax = -ax;
loc_15d65: // 1020:5b65
    if (memoryAGet16(ds, si + 15) < ax)
        goto loc_15db5;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)memoryAGet16(ds, si + 21) < (short)ax)
        goto loc_15dba;
    di = 0x528e;
    ax = 0xffff;
loc_15d7b: // 1020:5b7b
    di += 0x0012;
    if (memoryAGet16(ds, di + 4) != ax)
        goto loc_15d7b;
    if (di >= 0x5570)
        goto loc_15db5;
    sub_166df();
    bx = memoryAGet16(ds, si + 10);
    ax = memoryAGet16(ds, bx);
    ah &= 0x1f;
    ah |= 0x80;
    memoryASet16(ds, di + 4, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, ax);
    memoryASet(ds, di + 11, 0x03);
    memoryASet16(ds, di + 14, 0x0000);
    memoryASet(ds, 0x6511, 0x04);
    sub_166ef();
loc_15db5: // 1020:5bb5
    ax = 0;
loc_15db7: // 1020:5bb7
    memoryASet16(ds, si + 19, ax);
loc_15dba: // 1020:5bba
    return;
}
void sub_15dbb() // 1020:5bbb
{
    goto loc_15dbb;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 259 bytes
loc_15dbb: // 1020:5bbb
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_15dc5;
    goto loc_15c58;
loc_15dc5: // 1020:5bc5
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_15e07;
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_15dd5;
    ax = -ax;
loc_15dd5: // 1020:5bd5
    dx = memoryAGet16(ds, 0x527c);
    dx -= memoryAGet16(ds, si);
    if ((short)dx >= 0)
        goto loc_15de1;
    ax = -ax;
    dx = -dx;
loc_15de1: // 1020:5be1
    ax = -ax;
    memoryASet16(ds, si + 8, ax);
    if (memoryAGet16(ds, si + 23) < dx)
        goto loc_15e5f;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_15df5;
    ax = -ax;
loc_15df5: // 1020:5bf5
    if (ax > 0x0028)
        goto loc_15e5f;
    sub_166df();
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    memoryASet16(ds, si + 21, 0x000a);
    goto loc_15e5f;
loc_15e07: // 1020:5c07
    if (al != 0x01)
        goto loc_15e23;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
    memoryASet16(ds, si + 21, memoryAGet16(ds, si + 21) - 1);
    if (memoryAGet16(ds, si + 21))
        goto loc_15e5f;
    sub_166df();
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_15e5f;
loc_15e23: // 1020:5c23
    if (al != 0x02)
        goto loc_15e49;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    memoryASet16(ds, si + 21, memoryAGet16(ds, si + 21) + 1);
    if (memoryAGet16(ds, si + 21) <= 0x000a)
        goto loc_15e5f;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    al = memoryAGet(ds, si + 20);
    memoryASet(ds, si + 21, al);
    goto loc_15e5f;
loc_15e49: // 1020:5c49
    if (al != 0x03)
        goto loc_15e5f;
    memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
    if (memoryAGet(ds, si + 21))
        goto loc_15e5f;
    sub_166ef();
    sub_166ef();
    sub_166ef();
    memoryASet(ds, si + 14, 0x00);
loc_15e5f: // 1020:5c5f
    return;
}
void sub_15e60() // 1020:5c60
{
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) & 0x3f);
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_15e80;
    sub_166df();
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si + 17, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 14, 0x01);
    goto loc_15ec9;
loc_15e80: // 1020:5c80
    if (al != 0x01)
        goto loc_15e95;
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
    memoryASet16(ds, si + 17, memoryAGet16(ds, si + 17) - 1);
    if (memoryAGet16(ds, si + 17))
        goto loc_15ec9;
    memoryASet(ds, si + 14, 0x02);
    goto loc_15ec9;
loc_15e95: // 1020:5c95
    if (al != 0x02)
        goto loc_15ebc;
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    memoryASet16(ds, si + 17, memoryAGet16(ds, si + 17) + 1);
    ax = memoryAGet16(ds, si + 20);
    if ((short)memoryAGet16(ds, si + 2) < (short)ax)
        goto loc_15ec9;
    memoryASet16(ds, si + 2, ax);
    al = memoryAGet(ds, si + 19);
    memoryASet(ds, si + 17, al);
    memoryASet(ds, si + 14, 0x03);
    sub_166ef();
    goto loc_15ec9;
loc_15ebc: // 1020:5cbc
    if (al != 0x03)
        goto loc_15ec9;
    memoryASet(ds, si + 17, memoryAGet(ds, si + 17) - 1);
    if (memoryAGet(ds, si + 17))
        goto loc_15ec9;
    memoryASet(ds, si + 14, 0x00);
loc_15ec9: // 1020:5cc9
    return;
}
void sub_15eca() // 1020:5cca
{
    goto loc_15eca;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 530 bytes
loc_15eca: // 1020:5cca
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_15ed4;
    goto loc_15c58;
loc_15ed4: // 1020:5cd4
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_15f09;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_15ee4;
    ax = -ax;
loc_15ee4: // 1020:5ce4
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_15f01;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_15ef3;
    ax = -ax;
loc_15ef3: // 1020:5cf3
    if (ax > 0x001a)
        goto loc_15f01;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
loc_15f01: // 1020:5d01
    return;
    // gap 7 bytes
loc_15f09: // 1020:5d09
    if (al != 0x01)
        goto loc_15f7a;
    sub_16767();
    if (al)
        goto loc_15f17;
    sub_160ca();
loc_15f17: // 1020:5d17
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_15f2b;
    memoryASet16(ds, si + 8, -memoryAGet16(ds, si + 8));
loc_15f2b: // 1020:5d2b
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_15f39;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_15f39: // 1020:5d39
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_15f42;
    ax = -ax;
loc_15f42: // 1020:5d42
    if (ax < 0x0280)
        goto loc_15f4c;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_15f01;
loc_15f4c: // 1020:5d4c
    flags.carry = memoryAGet(ds, si + 20) < 0x01;
    memoryASet(ds, si + 20, memoryAGet(ds, si + 20) - 0x01);
    memoryASet(ds, si + 20, memoryAGet(ds, si + 20) + (0x00 + flags.carry));
    if (memoryAGet(ds, si + 20))
        goto loc_15fcd;
    if (ax > 0x0040)
        goto loc_15fcd;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_15f65;
    ax = -ax;
loc_15f65: // 1020:5d65
    if (ax > 0x0014)
        goto loc_15fcd;
    sub_1641c();
    memoryASet(ds, si + 14, 0x03);
    sub_166df();
    memoryASet(ds, si + 20, 0x14);
    goto loc_15fcd;
loc_15f7a: // 1020:5d7a
    if (al != 0x02)
        goto loc_15fb0;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 15);
    ax = sar16(ax, cl);
    ax -= memoryAGet16(ds, 0x5270);
    if (ax >= 0x0015)
        goto loc_15f9c;
    ax = memoryAGet16(ds, si + 17);
    ax = sar16(ax, cl);
    ax -= memoryAGet16(ds, 0x5272);
    if (ax <= 0x000d)
        goto loc_15fcd;
loc_15f9c: // 1020:5d9c
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    sub_166ef();
    memoryASet(ds, si + 14, 0x00);
    goto loc_15fcd;
loc_15fb0: // 1020:5db0
    if (al != 0x03)
        goto loc_15fcd;
    if (!(memoryAGet(ds, si + 7) & 0x20))
        goto loc_15fcd;
    sub_15b2d();
    if (flags.carry)
        goto loc_15fc6;
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 0x0004);
    sub_16696();
loc_15fc6: // 1020:5dc6
    sub_166ef();
    memoryASet(ds, si + 14, 0x01);
loc_15fcd: // 1020:5dcd
    return;
}
void sub_15fce() // 1020:5dce
{
    goto loc_15fce;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 790 bytes
loc_15fce: // 1020:5dce
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_15fd8;
    goto loc_15c58;
loc_15fd8: // 1020:5dd8
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_1600e;
    if (memoryAGet(ds, 0x6512) != 0x00)
        goto loc_16044;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_15fef;
    ax = -ax;
loc_15fef: // 1020:5def
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_16044;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_15ffe;
    ax = -ax;
loc_15ffe: // 1020:5dfe
    if (ax > 0x001a)
        goto loc_16044;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
    goto loc_16044;
loc_1600e: // 1020:5e0e
    if (al != 0x01)
        goto loc_1604c;
    if (memoryAGet(ds, 0x6512) != 0x00)
        goto loc_16044;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_16022;
    ax = -ax;
loc_16022: // 1020:5e22
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_16045;
    ax += 0x0032;
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_16044;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_16039;
    ax = -ax;
loc_16039: // 1020:5e39
    if (ax > 0x003c)
        goto loc_16044;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
loc_16044: // 1020:5e44
    return;
loc_16045: // 1020:5e45
    sub_166ef();
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) - 1);
    return;
loc_1604c: // 1020:5e4c
    if (al != 0x02)
        goto loc_16092;
    sub_16767();
    if (al)
        goto loc_1605a;
    sub_160ca();
loc_1605a: // 1020:5e5a
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    sub_160e4();
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_16071;
    sub_160ca();
loc_16071: // 1020:5e71
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_1607f;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_1607f: // 1020:5e7f
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_16088;
    ax = -ax;
loc_16088: // 1020:5e88
    if (ax < 0x0280)
        goto loc_160c9;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_160c9;
loc_16092: // 1020:5e92
    if (al != 0x03)
        goto loc_160c9;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 15);
    ax = sar16(ax, cl);
    ax -= memoryAGet16(ds, 0x5270);
    if (ax >= 0x0015)
        goto loc_160b4;
    ax = memoryAGet16(ds, si + 17);
    ax = sar16(ax, cl);
    ax -= memoryAGet16(ds, 0x5272);
    if (ax <= 0x000d)
        goto loc_160c9;
loc_160b4: // 1020:5eb4
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    sub_166ef();
    sub_166ef();
    memoryASet(ds, si + 14, 0x00);
loc_160c9: // 1020:5ec9
    return;
}
void sub_160ca() // 1020:5eca
{
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_160d5;
    ax = -ax;
loc_160d5: // 1020:5ed5
    dx = memoryAGet16(ds, si);
    if ((short)memoryAGet16(ds, si + 15) <= (short)dx)
        goto loc_160de;
    ax = -ax;
loc_160de: // 1020:5ede
    memoryASet16(ds, si + 8, ax);
    dx = pop();
    ax = pop();
}
void sub_160e4() // 1020:5ee4
{
    ax = 0x0001;
    if ((short)memoryAGet16(ds, si + 8) > (short)0x0000)
        goto loc_160ef;
    ax = -ax;
loc_160ef: // 1020:5eef
    di -= ax;
}
void sub_160f2() // 1020:5ef2
{
    goto loc_160f2;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 1082 bytes
loc_160f2: // 1020:5ef2
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_160fc;
    goto loc_15c58;
loc_160fc: // 1020:5efc
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_1612a;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_1610c;
    ax = -ax;
loc_1610c: // 1020:5f0c
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_16129;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_1611b;
    ax = -ax;
loc_1611b: // 1020:5f1b
    if (ax > 0x003c)
        goto loc_16129;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
loc_16129: // 1020:5f29
    return;
loc_1612a: // 1020:5f2a
    if (al != 0x01)
        goto loc_16198;
    memoryASet(ds, 0x6500, memoryAGet(ds, 0x6500) + 1);
    if (memoryAGet(ds, 0x6500) & 0x04)
        goto loc_16144;
    if (memoryAGet16(ds, 0x64fe) & 0x01ff)
        goto loc_16144;
    sub_166df();
loc_16144: // 1020:5f44
    if (memoryAGet(ds, 0x64fe) & 0x7f)
        goto loc_16155;
    al = 0x03;
    memoryASet(ds, si + 14, al);
    sub_166df();
    goto loc_16198;
loc_16155: // 1020:5f55
    sub_16767();
    if (al)
        goto loc_1615f;
    sub_160ca();
loc_1615f: // 1020:5f5f
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    sub_160e4();
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_16176;
    memoryASet16(ds, si + 8, -memoryAGet16(ds, si + 8));
loc_16176: // 1020:5f76
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_16184;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_16184: // 1020:5f84
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_1618d;
    ax = -ax;
loc_1618d: // 1020:5f8d
    if (ax < 0x0500)
        goto loc_16129;
    memoryASet(ds, si + 14, 0x02);
    goto loc_161f8;
loc_16198: // 1020:5f98
    if (al != 0x02)
        goto loc_161ce;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 17);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5272);
    if (ax > 0x000c)
        goto loc_161ba;
    ax = memoryAGet16(ds, si + 15);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5270);
    if (ax < 0x0019)
        goto loc_161f8;
loc_161ba: // 1020:5fba
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    memoryASet(ds, si + 14, 0x00);
    sub_166ef();
    goto loc_161f8;
loc_161ce: // 1020:5fce
    if (al != 0x03)
        goto loc_161f8;
    if (memoryAGet(ds, si + 5) & 0x20)
        goto loc_161eb;
    sub_166df();
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) - 0x0002);
    sub_166ff();
    sub_1641c();
    memoryASet(ds, si + 14, 0x01);
    goto loc_161f8;
loc_161eb: // 1020:5feb
    if (!(memoryAGet(ds, si + 7) & 0x20))
        goto loc_161f8;
    sub_1641c();
    memoryASet(ds, si + 14, 0x01);
loc_161f8: // 1020:5ff8
    return;
}
void sub_161f9() // 1020:5ff9
{
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) & 0x3f);
}
void sub_161fe() // 1020:5ffe
{
    goto loc_161fe;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 1350 bytes
loc_161fe: // 1020:5ffe
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_16208;
    goto loc_15c58;
loc_16208: // 1020:6008
    return;
}
void sub_16209() // 1020:6009
{
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) & 0x3f);
    goto loc_16219;
    // gap 10 bytes
loc_16219: // 1020:6019
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_1624a;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_1622a;
    ax = -ax;
loc_1622a: // 1020:602a
    if (ax > 0x0154)
        goto loc_1623f;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if ((short)ax >= 0)
        goto loc_1623a;
    ax = -ax;
loc_1623a: // 1020:603a
    if (ax < 0x00e6)
        goto loc_16264;
loc_1623f: // 1020:603f
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
    goto loc_16264;
loc_1624a: // 1020:604a
    if (al != 0x01)
        goto loc_162ab;
    sub_16767();
    if (al)
        goto loc_16265;
    if (memoryAGet16(ds, si + 21) >= 0x0010)
        goto loc_1625e;
    memoryASet16(ds, si + 21, memoryAGet16(ds, si + 21) + 1);
loc_1625e: // 1020:605e
    ax = memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
loc_16264: // 1020:6064
    return;
loc_16265: // 1020:6065
    if (memoryAGet16(ds, si + 21) == 0x0000)
        goto loc_1626e;
    sub_1641c();
loc_1626e: // 1020:606e
    memoryASet16(ds, si + 21, 0x0000);
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    sub_160e4();
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_1628a;
    memoryASet16(ds, si + 8, -memoryAGet16(ds, si + 8));
loc_1628a: // 1020:608a
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_16298;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_16298: // 1020:6098
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_162a1;
    ax = -ax;
loc_162a1: // 1020:60a1
    if (ax < 0x0280)
        goto loc_162df;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_162df;
loc_162ab: // 1020:60ab
    if (al != 0x02)
        goto loc_162df;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 17);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5272);
    if (ax > 0x000c)
        goto loc_162cd;
    ax = memoryAGet16(ds, si + 15);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5270);
    if (ax < 0x0013)
        goto loc_162df;
loc_162cd: // 1020:60cd
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    memoryASet(ds, si + 14, 0x00);
    sub_166ef();
loc_162df: // 1020:60df
    return;
}
void sub_1620f() // 1020:600f
{
    goto loc_1620f;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 1367 bytes
loc_1620f: // 1020:600f
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_16219;
    goto loc_15c58;
loc_16219: // 1020:6019
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_1624a;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_1622a;
    ax = -ax;
loc_1622a: // 1020:602a
    if (ax > 0x0154)
        goto loc_1623f;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if ((short)ax >= 0)
        goto loc_1623a;
    ax = -ax;
loc_1623a: // 1020:603a
    if (ax < 0x00e6)
        goto loc_16264;
loc_1623f: // 1020:603f
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
    goto loc_16264;
loc_1624a: // 1020:604a
    if (al != 0x01)
        goto loc_162ab;
    sub_16767();
    if (al)
        goto loc_16265;
    if (memoryAGet16(ds, si + 21) >= 0x0010)
        goto loc_1625e;
    memoryASet16(ds, si + 21, memoryAGet16(ds, si + 21) + 1);
loc_1625e: // 1020:605e
    ax = memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
loc_16264: // 1020:6064
    return;
loc_16265: // 1020:6065
    if (memoryAGet16(ds, si + 21) == 0x0000)
        goto loc_1626e;
    sub_1641c();
loc_1626e: // 1020:606e
    memoryASet16(ds, si + 21, 0x0000);
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    sub_160e4();
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_1628a;
    memoryASet16(ds, si + 8, -memoryAGet16(ds, si + 8));
loc_1628a: // 1020:608a
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_16298;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_16298: // 1020:6098
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_162a1;
    ax = -ax;
loc_162a1: // 1020:60a1
    if (ax < 0x0280)
        goto loc_162df;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_162df;
loc_162ab: // 1020:60ab
    if (al != 0x02)
        goto loc_162df;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 17);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5272);
    if (ax > 0x000c)
        goto loc_162cd;
    ax = memoryAGet16(ds, si + 15);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5270);
    if (ax < 0x0013)
        goto loc_162df;
loc_162cd: // 1020:60cd
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    memoryASet(ds, si + 14, 0x00);
    sub_166ef();
loc_162df: // 1020:60df
    return;
}
void sub_162e0() // 1020:60e0
{
    goto loc_162e0;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 1576 bytes
loc_162e0: // 1020:60e0
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_162ea;
    goto loc_15c58;
loc_162ea: // 1020:60ea
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_16323;
    ax = memoryAGet16(ds, 0x527e);
    if ((short)memoryAGet16(ds, si + 2) > (short)ax)
        goto loc_16340;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_16303;
    ax = -ax;
loc_16303: // 1020:6103
    if (memoryAGet16(ds, si + 23) < ax)
        goto loc_16340;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if ((short)ax >= 0)
        goto loc_16313;
    ax = -ax;
loc_16313: // 1020:6113
    if (ax > 0x00c8)
        goto loc_16340;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    sub_1641c();
    goto loc_16340;
loc_16323: // 1020:6123
    if (al == 0x01)
        goto loc_1632a;
    goto loc_163d4;
loc_1632a: // 1020:612a
    sub_16767();
    if (al)
        goto loc_16341;
    if (memoryAGet16(ds, si + 21) >= 0x0010)
        goto loc_1633a;
    memoryASet16(ds, si + 21, memoryAGet16(ds, si + 21) + 1);
loc_1633a: // 1020:613a
    ax = memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
loc_16340: // 1020:6140
    return;
loc_16341: // 1020:6141
    if (memoryAGet16(ds, si + 21) == 0x0000)
        goto loc_1634a;
    sub_1641c();
loc_1634a: // 1020:614a
    memoryASet16(ds, si + 21, 0x0000);
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0xf0);
    sub_160e4();
    al = memoryAGet(es, di + 65280);
    bx = 0x72a3;
    al = memoryAGet(ds, bx+al);
    al &= 0x01;
    if (!al)
        goto loc_16366;
    memoryASet16(ds, si + 8, -memoryAGet16(ds, si + 8));
loc_16366: // 1020:6166
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    if ((short)memoryAGet16(ds, si) >= 0)
        goto loc_16374;
    ax = -ax;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet16(ds, si + 8, ax);
loc_16374: // 1020:6174
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_1637d;
    ax = -ax;
loc_1637d: // 1020:617d
    if (ax > 0x0280)
        goto loc_16391;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_1638c;
    ax = -ax;
loc_1638c: // 1020:618c
    if (ax < 0x0190)
        goto loc_16398;
loc_16391: // 1020:6191
    memoryASet(ds, si + 14, 0x02);
    goto loc_1641b;
loc_16398: // 1020:6198
    if (memoryAGet(ds, si + 14) != 0x01)
        goto loc_1641b;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_163a7;
    ax = -ax;
loc_163a7: // 1020:61a7
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bx <<= 1;
    dl = memoryAGet(ds, bx + 26213);
    dh = 0;
    dx += 0x0006;
    if (ax > dx)
        goto loc_1641b;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_163c6;
    ax = -ax;
loc_163c6: // 1020:61c6
    if (ax > 0x0008)
        goto loc_1641b;
    memoryASet(ds, si + 14, 0x03);
    sub_166df();
    goto loc_1641b;
loc_163d4: // 1020:61d4
    if (al != 0x02)
        goto loc_1640a;
    cl = 0x04;
    ax = memoryAGet16(ds, si + 17);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5272);
    if (ax > 0x000d)
        goto loc_163f6;
    ax = memoryAGet16(ds, si + 15);
    ax >>= cl;
    ax -= memoryAGet16(ds, 0x5270);
    if (ax < 0x0015)
        goto loc_1641b;
loc_163f6: // 1020:61f6
    ax = memoryAGet16(ds, si + 17);
    memoryASet16(ds, si + 2, ax);
    ax = memoryAGet16(ds, si + 15);
    memoryASet16(ds, si, ax);
    memoryASet(ds, si + 14, 0x00);
    sub_166ef();
    goto loc_1641b;
loc_1640a: // 1020:620a
    if (al != 0x03)
        goto loc_1641b;
    if (memoryAGet(ds, si + 7) & 0x20)
        goto loc_16417;
    goto loc_1632a;
loc_16417: // 1020:6217
    memoryASet(ds, si + 14, 0x01);
loc_1641b: // 1020:621b
    return;
}
void sub_1641c() // 1020:621c
{
    dl = memoryAGet(ds, si + 19);
    dh = 0;
    ax = memoryAGet16(ds, 0x527c);
    if ((short)memoryAGet16(ds, si) > (short)ax)
        goto loc_1642a;
    dx = -dx;
loc_1642a: // 1020:622a
    memoryASet16(ds, si + 8, dx);
}
void sub_1642e() // 1020:622e
{
    goto loc_1642e;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 1910 bytes
loc_1642e: // 1020:622e
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_16438;
    goto loc_15c58;
loc_16438: // 1020:6238
    sub_165c9();
    if (memoryAGet(ds, si + 5) & 0x20)
        goto loc_16444;
    goto loc_164c8;
loc_16444: // 1020:6244
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_16484;
    dx = 0xfffe;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if ((short)ax >= 0)
        goto loc_1645b;
    ax = -ax;
    dx = -dx;
loc_1645b: // 1020:625b
    cl = memoryAGet(ds, si + 19);
    ch = 0;
    if (ax > cx)
        goto loc_164c8;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_1646e;
    ax = -ax;
loc_1646e: // 1020:626e
    if (ax > 0x0028)
        goto loc_164c8;
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 20, dx);
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    sub_166df();
    goto loc_164c8;
loc_16484: // 1020:6284
    if (al != 0x01)
        goto loc_164ac;
    ax = memoryAGet16(ds, si + 20);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 22);
    if ((short)ax >= 0)
        goto loc_16498;
    ax = -ax;
loc_16498: // 1020:6298
    cl = memoryAGet(ds, si + 19);
    ch = 0;
    if (ax < cx)
        goto loc_164c8;
    memoryASet16(ds, si + 20, -memoryAGet16(ds, si + 20));
    sub_166df();
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    goto loc_164c8;
loc_164ac: // 1020:62ac
    if (al != 0x02)
        goto loc_164c8;
    ax = memoryAGet16(ds, si + 20);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    ax = memoryAGet16(ds, si + 22);
    if (memoryAGet16(ds, si + 2) != ax)
        goto loc_164c8;
    sub_166ef();
    sub_166ef();
    memoryASet(ds, si + 14, 0x00);
loc_164c8: // 1020:62c8
    return;
}
void sub_164c9() // 1020:62c9
{
    goto loc_164c9;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 2065 bytes
loc_164c9: // 1020:62c9
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_164d3;
    goto loc_15c58;
loc_164d3: // 1020:62d3
    al = memoryAGet(ds, si + 14);
    if (al != 0x00)
        goto loc_16542;
    sub_165c9();
    if (!(memoryAGet(ds, si + 5) & 0x20))
        goto loc_16541;
    ax = memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, 0x527e);
    if (ah)
        goto loc_16541;
    if (memoryAGet(ds, si + 19) < al)
        goto loc_16541;
    cl = al;
    dh = 0;
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, 0x527c);
    if ((short)ax >= 0)
        goto loc_16503;
    ax = -ax;
    dh = 0x80;
loc_16503: // 1020:6303
    dl = memoryAGet(ds, si + 5);
    dl &= 0x80;
    if (dl != dh)
        goto loc_16541;
    if ((short)ax >= (short)0x0030)
        goto loc_16541;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si + 15);
    if ((short)ax >= 0)
        goto loc_1651c;
    ax = -ax;
loc_1651c: // 1020:631c
    if (memoryAGet16(ds, si + 17) < ax)
        goto loc_16541;
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    dx = 0;
loc_16526: // 1020:6326
    dl++;
    dh += dl;
    if (cl > dh)
        goto loc_16526;
    al = dl;
    cbw();
    ax = -ax;
    memoryASet16(ds, si + 20, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, si + 22, ax);
    sub_166df();
    goto loc_165be;
loc_16541: // 1020:6341
    return;
loc_16542: // 1020:6342
    if (!(memoryAGet(ds, si + 5) & 0x20))
        goto loc_16541;
    if (al != 0x01)
        goto loc_16591;
    ax = memoryAGet16(ds, si + 8);
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si + 20);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    ax++;
    if (!ax)
        goto loc_1656f;
    memoryASet16(ds, si + 20, ax);
    ax = memoryAGet16(ds, si + 22);
    flags.carry = al < memoryAGet(ds, si + 19);
    al -= memoryAGet(ds, si + 19);
    ah = ah - 0x00 - flags.carry;
    if ((short)memoryAGet16(ds, si + 2) > (short)ax)
        goto loc_165be;
loc_1656f: // 1020:636f
    sub_166df();
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) + 1);
    memoryASet16(ds, si + 20, 0x0000);
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_16583;
    ax = -ax;
loc_16583: // 1020:6383
    dx = memoryAGet16(ds, si + 15);
    if ((short)memoryAGet16(ds, si) <= (short)dx)
        goto loc_1658c;
    ax = -ax;
loc_1658c: // 1020:638c
    memoryASet16(ds, si + 8, ax);
    goto loc_165be;
loc_16591: // 1020:6391
    if (al != 0x02)
        goto loc_165be;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si + 20);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    ax++;
    memoryASet16(ds, si + 20, ax);
    ax = memoryAGet16(ds, si + 22);
    if ((short)memoryAGet16(ds, si + 2) < (short)ax)
        goto loc_165be;
    memoryASet16(ds, si + 2, ax);
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    memoryASet(ds, si + 14, 0x00);
    sub_166ef();
    sub_166ef();
loc_165be: // 1020:63be
    return;
}
void sub_165bf() // 1020:63bf
{
    goto loc_165bf;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 2311 bytes
loc_165bf: // 1020:63bf
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_165c9;
    goto loc_15c58;
loc_165c9: // 1020:63c9
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, si + 15);
    dx = ax;
    if ((short)ax >= 0)
        goto loc_165d9;
    ax = -ax;
loc_165d9: // 1020:63d9
    if (ax <= memoryAGet16(ds, si + 17))
        goto loc_165f0;
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_165e7;
    ax = -ax;
loc_165e7: // 1020:63e7
    if ((short)dx >= 0)
        goto loc_165ed;
    ax = -ax;
loc_165ed: // 1020:63ed
    memoryASet16(ds, si + 8, ax);
loc_165f0: // 1020:63f0
    return;
}
void sub_165c9() // 1020:63c9
{
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    ax = memoryAGet16(ds, si);
    ax -= memoryAGet16(ds, si + 15);
    dx = ax;
    if ((short)ax >= 0)
        goto loc_165d9;
    ax = -ax;
loc_165d9: // 1020:63d9
    if (ax <= memoryAGet16(ds, si + 17))
        goto loc_165f0;
    ax = memoryAGet16(ds, si + 8);
    if ((short)ax >= 0)
        goto loc_165e7;
    ax = -ax;
loc_165e7: // 1020:63e7
    if ((short)dx >= 0)
        goto loc_165ed;
    ax = -ax;
loc_165ed: // 1020:63ed
    memoryASet16(ds, si + 8, ax);
loc_165f0: // 1020:63f0
    return;
}
void sub_165f1() // 1020:63f1
{
    goto loc_165f1;
loc_15c58: // 1020:5a58
    if (al & 0x40)
        goto loc_15c98;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | 0x40);
    bx = memoryAGet16(ds, si + 4);
    bh &= 0x1f;
    bl = memoryAGet(ds, bx + 28639);
    bl &= 0xf0;
    if (bl == 0xf0)
        goto loc_15c8f;
    cl = 0x03;
    bh = 0;
    bx >>= cl;
    ah = memoryAGet(ds, si + 5);
    ax &= 0x8000;
    ax |= memoryAGet16(ds, bx + 28627);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet(ds, si + 14, 0xff);
    return;
loc_15c8f: // 1020:5a8f
    memoryASet16(ds, si + 8, 0xfff6);
    memoryASet(ds, si + 14, 0x00);
loc_15c98: // 1020:5a98
    if (memoryAGet(ds, si + 14) == 0xff)
        goto loc_15cb7;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if (memoryAGet(ds, 0x6515) == 0x00)
        goto loc_15caf;
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + ax);
loc_15caf: // 1020:5aaf
    if ((short)ax >= (short)0x0014)
        goto loc_15cb7;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
loc_15cb7: // 1020:5ab7
    return;
    // gap 2361 bytes
loc_165f1: // 1020:63f1
    al = memoryAGet(ds, si + 7);
    if (!(al & 0xc0))
        goto loc_165fb;
    goto loc_15c58;
loc_165fb: // 1020:63fb
    if (memoryAGet(ds, si + 5) & 0x20)
        goto loc_16604;
    goto loc_16695;
loc_16604: // 1020:6404
    al = memoryAGet(ds, si + 18);
    if (!(al & 0xc0))
        goto loc_16614;
    dx = 0;
    if (al & 0x40)
        goto loc_1661e;
    dx--;
    goto loc_1661e;
loc_16614: // 1020:6414
    dx = 0;
    ax = memoryAGet16(ds, 0x527c);
    if ((short)memoryAGet16(ds, si) >= (short)ax)
        goto loc_1661e;
    dx--;
loc_1661e: // 1020:641e
    memoryASet16(ds, si + 8, dx);
    al = memoryAGet(ds, si + 14);
    if (al)
        goto loc_16676;
    flags.carry = memoryAGet(ds, si + 15) < 0x01;
    memoryASet(ds, si + 15, memoryAGet(ds, si + 15) - 0x01);
    memoryASet(ds, si + 15, memoryAGet(ds, si + 15) + (0x00 + flags.carry));
    if (memoryAGet(ds, si + 15))
        goto loc_16695;
    ax = memoryAGet16(ds, 0x527e);
    ax -= memoryAGet16(ds, si + 2);
    if ((short)ax >= 0)
        goto loc_1663c;
    ax = -ax;
loc_1663c: // 1020:643c
    if (ax > 0x0018)
        goto loc_16695;
    ax = memoryAGet16(ds, 0x527c);
    ax -= memoryAGet16(ds, si);
    if ((short)ax >= 0)
        goto loc_1664a;
    ax = -ax;
loc_1664a: // 1020:644a
    dx = memoryAGet16(ds, si + 17);
    dh &= 0x3f;
    if (dx < ax)
        goto loc_16695;
    al = memoryAGet(ds, si + 18);
    al = rol8(al, 0x01);
    al = rol8(al, 0x01);
    al &= 0x03;
    if (!al)
        goto loc_1666d;
    flags.zero = al == 0x01;
    ax = memoryAGet16(ds, 0x527c);
    dx = memoryAGet16(ds, si);
    if (flags.zero)
        goto loc_16669;
    tx = dx; dx = ax; ax = tx;
loc_16669: // 1020:6469
    if ((short)ax > (short)dx)
        goto loc_16695;
loc_1666d: // 1020:646d
    memoryASet(ds, si + 14, 0x1e);
    sub_166df();
    goto loc_16695;
loc_16676: // 1020:6476
    memoryASet(ds, si + 14, memoryAGet(ds, si + 14) - 1);
    if (!(memoryAGet(ds, si + 7) & 0x20))
        goto loc_16695;
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 0x0004);
    sub_15b2d();
    if (flags.carry)
        goto loc_16691;
    sub_16696();
    al = memoryAGet(ds, si + 16);
    memoryASet(ds, si + 15, al);
loc_16691: // 1020:6491
    memoryASet(ds, si + 14, 0x00);
loc_16695: // 1020:6495
    return;
}
void sub_16696() // 1020:6496
{
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, si + 2);
    bx = memoryAGet16(ds, si + 10);
    bp = bx;
    bx = memoryAGet16(ds, bx + 65534);
    bh = 0;
    tx = bx; bx = ax; ax = tx;
    cbw();
    tx = bx; bx = ax; ax = tx;
    ax -= bx;
    memoryASet16(ds, di + 2, ax);
    bx = memoryAGet16(ds, bp - 4);
    bh &= 0x1f;
    bx += 0x801e;
    dx = 0x00b0;
    ax = memoryAGet16(ds, 0x527c);
    if ((short)memoryAGet16(ds, si) < (short)ax)
        goto loc_166c9;
    dx = -dx;
    bh ^= 0x80;
loc_166c9: // 1020:64c9
    memoryASet16(ds, di + 4, bx);
    memoryASet16(ds, di + 6, dx);
    memoryASet16(ds, di + 14, 0x0000);
    dx = sar16(dx, 0x0001);
    dx = sar16(dx, 0x0001);
    dx = sar16(dx, 0x0001);
    dx = sar16(dx, 0x0001);
    memoryASet16(ds, di, memoryAGet16(ds, di) + dx);
}
void sub_166df() // 1020:64df
{
    bx = memoryAGet16(ds, si + 10);
loc_166e2: // 1020:64e2
    bx++;
    bx++;
    if ((short)memoryAGet16(ds, bx) >= (short)0x0000)
        goto loc_166e2;
    bx++;
    bx++;
    memoryASet16(ds, si + 10, bx);
}
void sub_166ef() // 1020:64ef
{
    bx = memoryAGet16(ds, si + 10);
loc_166f2: // 1020:64f2
    bx--;
    bx--;
    if ((short)memoryAGet16(ds, bx) >= (short)0x0000)
        goto loc_166f2;
    bx--;
    bx--;
    memoryASet16(ds, si + 10, bx);
}
void sub_166ff() // 1020:64ff
{
    if (memoryAGet(ds, si + 7) & 0xc0)
        goto loc_1674b;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) & 0xdf);
    bx = memoryAGet16(ds, si + 10);
loc_1670c: // 1020:650c
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= 0)
        goto loc_16716;
    bx += ax;
    goto loc_1670c;
loc_16716: // 1020:6516
    if (ax != 0x55aa)
        goto loc_16727;
    memoryASet16(ds, di + 4, 0xffff);
    memoryASet16(ds, si + 4, 0x05aa);
    goto loc_1675c;
loc_16727: // 1020:6527
    dh = ah;
    dh &= 0x20;
    ah &= 0xdf;
    memoryASet(ds, si + 7, memoryAGet(ds, si + 7) | dh);
    dh = memoryAGet(ds, si + 9);
    dh &= 0x80;
    ah |= dh;
    memoryASet16(ds, si + 4, ax);
    ax += 0x0065;
    memoryASet16(ds, di + 4, ax);
    sub_1675c();
    memoryASet16(ds, si + 10, bx);
    goto loc_16757;
loc_1674b: // 1020:654b
    ax = memoryAGet16(ds, si + 4);
    ah &= 0xdf;
    ax += 0x0065;
    memoryASet16(ds, di + 4, ax);
loc_16757: // 1020:6557
    memoryASet(ds, si + 5, memoryAGet(ds, si + 5) | 0x20);
    return;
loc_1675c: // 1020:655c
    bx++;
    bx++;
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= 0)
        goto loc_16766;
    bx += ax;
loc_16766: // 1020:6566
    return;
}
void sub_1675c() // 1020:655c
{
    bx++;
    bx++;
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= 0)
        goto loc_16766;
    bx += ax;
loc_16766: // 1020:6566
    return;
}
void sub_16767() // 1020:6567
{
    cl = 0x04;
    ax = memoryAGet16(ds, si + 2);
    al &= 0xf0;
    ax <<= cl;
    di = memoryAGet16(ds, si);
    di >>= cl;
    di += ax;
    es = memoryAGet16(ds, 0x526c);
    al = memoryAGet(es, di);
    bx = 0x73a3;
    al = memoryAGet(ds, bx+al);
}
void sub_16782() // 1020:6582
{
    bool temp_cf;

    push(bx);
    push(cx);
    push(si);
    push(es);
    push(ds);
    bx = ax;
    ax = 0xf000;
    es = ax;
    ax = 0x168f;
    ds = ax;
    si = 0xfff0;
    ax = memoryAGet16(es, bx);
    cl = memoryAGet(cs, 0x0004);
    al += memoryAGet(es, bx + 61440);
    ah -= memoryAGet(es, bx + 61442);
    flags.carry = !!(ax & (1 << (cl-1)));
    ax = ror16(ax, cl);
    cx = 0x0008;
loc_167ad: // 1020:65ad
    temp_cf = (ax + memoryAGet16(es, si) + flags.carry) >= 0x10000;
    ax += memoryAGet16(es, si) + flags.carry;
    flags.carry = temp_cf;
    si++;
    si++;
    if (--cx)
        goto loc_167ad;
    cl = bl;
    ax = rol16(ax, cl);
    ds = pop();
    es = pop();
    si = pop();
    cx = pop();
    bx = pop();
}
void sub_167be() // 1020:65be
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    push(bp);
    push(si);
    memoryASet(cs, 0x66d9, al);
    memoryASet(cs, 0x66da, ah);
    mul8(ah);
    memoryASet16(cs, 0x66dd, ax);
    ax = 0x168f;
    es = ax;
    ax = memoryAGet16(es, 0x04c1);
    ax += 0x07d1;
    es = ax;
    di = 0;
    bp = 0;
loc_167e9: // 1020:65e9
    al = memoryAGet(cs, 0x66da);
    memoryASet(cs, 0x66d8, al);
loc_167f1: // 1020:65f1
    bx = memoryAGet16(cs, 0x66dd);
    ah = memoryAGet(ds, bx + si);
    dx = 0;
    memoryASet16(cs, 0x66db, dx);
    if (memoryAGet(cs, 0x66df) != dl)
        goto loc_16811;
    bx <<= 1;
    dl = memoryAGet(ds, bx + si);
    bx += memoryAGet16(cs, 0x66dd);
    dh = memoryAGet(ds, bx + si);
loc_16811: // 1020:6611
    al = lodsb<DS_SI>();
    cx = 0x0008;
loc_16815: // 1020:6615
    bx = 0;
    flags.carry = !!(dh & 0x80);
    dh <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(dl & 0x80);
    dl <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    bx <<= 1;
    bx += bp;
    bx += memoryAGet16(cs, 0x6676);
    bl = memoryAGet(cs, bx);
    bp ^= 0x0001;
    flags.carry = !!(bl & 0x80);
    bl <<= 1;
    memoryASet16(cs, 0x66db, rcl16(memoryAGet16(cs, 0x66db), 0x01));
    flags.carry = !!(bl & 0x80);
    bl <<= 1;
    memoryASet16(cs, 0x66db, rcl16(memoryAGet16(cs, 0x66db), 0x01));
    if (--cx)
        goto loc_16815;
    ax = memoryAGet16(cs, 0x66db);
    tl = ah; ah = al; al = tl;
    stosw<ES_DI>(ax);
    memoryASet(cs, 0x66d8, memoryAGet(cs, 0x66d8) - 1);
    if (memoryAGet(cs, 0x66d8))
        goto loc_167f1;
    bp ^= 0x0001;
    memoryASet(cs, 0x66d9, memoryAGet(cs, 0x66d9) - 1);
    if (memoryAGet(cs, 0x66d9))
        goto loc_167e9;
    di = pop();
    si = 0;
    push(ds);
    push(es);
    ds = pop();
    es = pop();
    cx = memoryAGet16(cs, 0x66dd);
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    bp = pop();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void fixReloc(uint16_t seg)
{
    memoryASet16(0x0020 + seg, 0x0050, memoryAGet16(0x0020 + seg, 0x0050) + seg); // 068f -> 168f; lin=250
    memoryASet16(0x0020 + seg, 0x0066, memoryAGet16(0x0020 + seg, 0x0066) + seg); // 0690 -> 1690; lin=266
    memoryASet16(0x0020 + seg, 0x007f, memoryAGet16(0x0020 + seg, 0x007f) + seg); // 068f -> 168f; lin=27f
    memoryASet16(0x0020 + seg, 0x0084, memoryAGet16(0x0020 + seg, 0x0084) + seg); // 068f -> 168f; lin=284
    memoryASet16(0x0020 + seg, 0x00f9, memoryAGet16(0x0020 + seg, 0x00f9) + seg); // 068f -> 168f; lin=2f9
    memoryASet16(0x0020 + seg, 0x0118, memoryAGet16(0x0020 + seg, 0x0118) + seg); // 068f -> 168f; lin=318
    memoryASet16(0x0020 + seg, 0x0159, memoryAGet16(0x0020 + seg, 0x0159) + seg); // 068f -> 168f; lin=359
    memoryASet16(0x0020 + seg, 0x017d, memoryAGet16(0x0020 + seg, 0x017d) + seg); // 068f -> 168f; lin=37d
    memoryASet16(0x0020 + seg, 0x01f9, memoryAGet16(0x0020 + seg, 0x01f9) + seg); // 068f -> 168f; lin=3f9
    memoryASet16(0x0020 + seg, 0x0284, memoryAGet16(0x0020 + seg, 0x0284) + seg); // 068f -> 168f; lin=484
    memoryASet16(0x0020 + seg, 0x033d, memoryAGet16(0x0020 + seg, 0x033d) + seg); // 068f -> 168f; lin=53d
    memoryASet16(0x0020 + seg, 0x038b, memoryAGet16(0x0020 + seg, 0x038b) + seg); // 068f -> 168f; lin=58b
    memoryASet16(0x0020 + seg, 0x03af, memoryAGet16(0x0020 + seg, 0x03af) + seg); // 068f -> 168f; lin=5af
    memoryASet16(0x0020 + seg, 0x03f3, memoryAGet16(0x0020 + seg, 0x03f3) + seg); // 068f -> 168f; lin=5f3
    memoryASet16(0x0020 + seg, 0x04be, memoryAGet16(0x0020 + seg, 0x04be) + seg); // 068f -> 168f; lin=6be
    memoryASet16(0x0020 + seg, 0x05d1, memoryAGet16(0x0020 + seg, 0x05d1) + seg); // 068f -> 168f; lin=7d1
    memoryASet16(0x0020 + seg, 0x0702, memoryAGet16(0x0020 + seg, 0x0702) + seg); // 068f -> 168f; lin=902
    memoryASet16(0x0020 + seg, 0x080f, memoryAGet16(0x0020 + seg, 0x080f) + seg); // 068f -> 168f; lin=a0f
    memoryASet16(0x0020 + seg, 0x08d6, memoryAGet16(0x0020 + seg, 0x08d6) + seg); // 068f -> 168f; lin=ad6
    memoryASet16(0x0020 + seg, 0x08eb, memoryAGet16(0x0020 + seg, 0x08eb) + seg); // 068f -> 168f; lin=aeb
    memoryASet16(0x0020 + seg, 0x0903, memoryAGet16(0x0020 + seg, 0x0903) + seg); // 068f -> 168f; lin=b03
    memoryASet16(0x0020 + seg, 0x097c, memoryAGet16(0x0020 + seg, 0x097c) + seg); // 068f -> 168f; lin=b7c
    memoryASet16(0x0020 + seg, 0x0ae9, memoryAGet16(0x0020 + seg, 0x0ae9) + seg); // 068f -> 168f; lin=ce9
    memoryASet16(0x0020 + seg, 0x0b0c, memoryAGet16(0x0020 + seg, 0x0b0c) + seg); // 068f -> 168f; lin=d0c
    memoryASet16(0x0020 + seg, 0x0c15, memoryAGet16(0x0020 + seg, 0x0c15) + seg); // 068f -> 168f; lin=e15
    memoryASet16(0x0020 + seg, 0x0cf2, memoryAGet16(0x0020 + seg, 0x0cf2) + seg); // 068f -> 168f; lin=ef2
    memoryASet16(0x0020 + seg, 0x0d31, memoryAGet16(0x0020 + seg, 0x0d31) + seg); // 068f -> 168f; lin=f31
    memoryASet16(0x0020 + seg, 0x0d56, memoryAGet16(0x0020 + seg, 0x0d56) + seg); // 068f -> 168f; lin=f56
    memoryASet16(0x0020 + seg, 0x0e5b, memoryAGet16(0x0020 + seg, 0x0e5b) + seg); // 068f -> 168f; lin=105b
    memoryASet16(0x0020 + seg, 0x0e93, memoryAGet16(0x0020 + seg, 0x0e93) + seg); // 068f -> 168f; lin=1093
    memoryASet16(0x0020 + seg, 0x1081, memoryAGet16(0x0020 + seg, 0x1081) + seg); // 068f -> 168f; lin=1281
    memoryASet16(0x0020 + seg, 0x10d4, memoryAGet16(0x0020 + seg, 0x10d4) + seg); // 068f -> 168f; lin=12d4
    memoryASet16(0x0020 + seg, 0x1109, memoryAGet16(0x0020 + seg, 0x1109) + seg); // 068f -> 168f; lin=1309
    memoryASet16(0x0020 + seg, 0x11a2, memoryAGet16(0x0020 + seg, 0x11a2) + seg); // 068f -> 168f; lin=13a2
    memoryASet16(0x0020 + seg, 0x11f0, memoryAGet16(0x0020 + seg, 0x11f0) + seg); // 068f -> 168f; lin=13f0
    memoryASet16(0x0020 + seg, 0x1235, memoryAGet16(0x0020 + seg, 0x1235) + seg); // 068f -> 168f; lin=1435
    memoryASet16(0x0020 + seg, 0x12b6, memoryAGet16(0x0020 + seg, 0x12b6) + seg); // 068f -> 168f; lin=14b6
    memoryASet16(0x0020 + seg, 0x1345, memoryAGet16(0x0020 + seg, 0x1345) + seg); // 068f -> 168f; lin=1545
    memoryASet16(0x0020 + seg, 0x16f0, memoryAGet16(0x0020 + seg, 0x16f0) + seg); // 068f -> 168f; lin=18f0
    memoryASet16(0x068f + seg, 0x0435, memoryAGet16(0x068f + seg, 0x0435) + seg); // 0020 -> 1020; lin=6d25
    memoryASet16(0x068f + seg, 0x0439, memoryAGet16(0x068f + seg, 0x0439) + seg); // 0020 -> 1020; lin=6d29
    memoryASet16(0x0020 + seg, 0x17ff, memoryAGet16(0x0020 + seg, 0x17ff) + seg); // 068f -> 168f; lin=19ff
    memoryASet16(0x0020 + seg, 0x1840, memoryAGet16(0x0020 + seg, 0x1840) + seg); // 068f -> 168f; lin=1a40
    memoryASet16(0x0020 + seg, 0x1926, memoryAGet16(0x0020 + seg, 0x1926) + seg); // 068f -> 168f; lin=1b26
    memoryASet16(0x0020 + seg, 0x1962, memoryAGet16(0x0020 + seg, 0x1962) + seg); // 068f -> 168f; lin=1b62
    memoryASet16(0x0020 + seg, 0x1a9e, memoryAGet16(0x0020 + seg, 0x1a9e) + seg); // 068f -> 168f; lin=1c9e
    memoryASet16(0x0020 + seg, 0x1c6b, memoryAGet16(0x0020 + seg, 0x1c6b) + seg); // 068f -> 168f; lin=1e6b
    memoryASet16(0x0020 + seg, 0x24ab, memoryAGet16(0x0020 + seg, 0x24ab) + seg); // 068f -> 168f; lin=26ab
    memoryASet16(0x0020 + seg, 0x24d3, memoryAGet16(0x0020 + seg, 0x24d3) + seg); // 068f -> 168f; lin=26d3
    memoryASet16(0x0020 + seg, 0x2571, memoryAGet16(0x0020 + seg, 0x2571) + seg); // 068f -> 168f; lin=2771
    memoryASet16(0x0020 + seg, 0x2609, memoryAGet16(0x0020 + seg, 0x2609) + seg); // 068f -> 168f; lin=2809
    memoryASet16(0x0020 + seg, 0x2672, memoryAGet16(0x0020 + seg, 0x2672) + seg); // 068f -> 168f; lin=2872
    memoryASet16(0x0020 + seg, 0x26ec, memoryAGet16(0x0020 + seg, 0x26ec) + seg); // 068f -> 168f; lin=28ec
    memoryASet16(0x0020 + seg, 0x26f3, memoryAGet16(0x0020 + seg, 0x26f3) + seg); // 068f -> 168f; lin=28f3
    memoryASet16(0x0020 + seg, 0x2779, memoryAGet16(0x0020 + seg, 0x2779) + seg); // 068f -> 168f; lin=2979
    memoryASet16(0x0020 + seg, 0x282e, memoryAGet16(0x0020 + seg, 0x282e) + seg); // 068f -> 168f; lin=2a2e
    memoryASet16(0x0020 + seg, 0x2916, memoryAGet16(0x0020 + seg, 0x2916) + seg); // 068f -> 168f; lin=2b16
    memoryASet16(0x0020 + seg, 0x2951, memoryAGet16(0x0020 + seg, 0x2951) + seg); // 068f -> 168f; lin=2b51
    memoryASet16(0x0020 + seg, 0x2999, memoryAGet16(0x0020 + seg, 0x2999) + seg); // 068f -> 168f; lin=2b99
    memoryASet16(0x0020 + seg, 0x29ba, memoryAGet16(0x0020 + seg, 0x29ba) + seg); // 068f -> 168f; lin=2bba
    memoryASet16(0x0020 + seg, 0x2bac, memoryAGet16(0x0020 + seg, 0x2bac) + seg); // 068f -> 168f; lin=2dac
    memoryASet16(0x0020 + seg, 0x2c98, memoryAGet16(0x0020 + seg, 0x2c98) + seg); // 068f -> 168f; lin=2e98
    memoryASet16(0x0020 + seg, 0x2d01, memoryAGet16(0x0020 + seg, 0x2d01) + seg); // 068f -> 168f; lin=2f01
    memoryASet16(0x0020 + seg, 0x2d65, memoryAGet16(0x0020 + seg, 0x2d65) + seg); // 068f -> 168f; lin=2f65
    memoryASet16(0x0020 + seg, 0x2e60, memoryAGet16(0x0020 + seg, 0x2e60) + seg); // 068f -> 168f; lin=3060
    memoryASet16(0x0020 + seg, 0x2eb9, memoryAGet16(0x0020 + seg, 0x2eb9) + seg); // 068f -> 168f; lin=30b9
    memoryASet16(0x0020 + seg, 0x2eed, memoryAGet16(0x0020 + seg, 0x2eed) + seg); // 068f -> 168f; lin=30ed
    memoryASet16(0x0020 + seg, 0x2f13, memoryAGet16(0x0020 + seg, 0x2f13) + seg); // 068f -> 168f; lin=3113
    memoryASet16(0x0020 + seg, 0x2f77, memoryAGet16(0x0020 + seg, 0x2f77) + seg); // 068f -> 168f; lin=3177
    memoryASet16(0x0020 + seg, 0x2fe4, memoryAGet16(0x0020 + seg, 0x2fe4) + seg); // 068f -> 168f; lin=31e4
    memoryASet16(0x0020 + seg, 0x307e, memoryAGet16(0x0020 + seg, 0x307e) + seg); // 068f -> 168f; lin=327e
    memoryASet16(0x0020 + seg, 0x317a, memoryAGet16(0x0020 + seg, 0x317a) + seg); // 068f -> 168f; lin=337a
    memoryASet16(0x0020 + seg, 0x31c6, memoryAGet16(0x0020 + seg, 0x31c6) + seg); // 068f -> 168f; lin=33c6
    memoryASet16(0x0020 + seg, 0x31ea, memoryAGet16(0x0020 + seg, 0x31ea) + seg); // 068f -> 168f; lin=33ea
    memoryASet16(0x0020 + seg, 0x3280, memoryAGet16(0x0020 + seg, 0x3280) + seg); // 068f -> 168f; lin=3480
    memoryASet16(0x0020 + seg, 0x350f, memoryAGet16(0x0020 + seg, 0x350f) + seg); // 068f -> 168f; lin=370f
    memoryASet16(0x0020 + seg, 0x378f, memoryAGet16(0x0020 + seg, 0x378f) + seg); // 068f -> 168f; lin=398f
    memoryASet16(0x0020 + seg, 0x38b6, memoryAGet16(0x0020 + seg, 0x38b6) + seg); // 068f -> 168f; lin=3ab6
    memoryASet16(0x0020 + seg, 0x3e29, memoryAGet16(0x0020 + seg, 0x3e29) + seg); // 068f -> 168f; lin=4029
    memoryASet16(0x0020 + seg, 0x3eec, memoryAGet16(0x0020 + seg, 0x3eec) + seg); // 068f -> 168f; lin=40ec
    memoryASet16(0x0020 + seg, 0x3f47, memoryAGet16(0x0020 + seg, 0x3f47) + seg); // 068f -> 168f; lin=4147
    memoryASet16(0x0020 + seg, 0x3f75, memoryAGet16(0x0020 + seg, 0x3f75) + seg); // 068f -> 168f; lin=4175
    memoryASet16(0x0020 + seg, 0x403d, memoryAGet16(0x0020 + seg, 0x403d) + seg); // 068f -> 168f; lin=423d
    memoryASet16(0x0020 + seg, 0x4155, memoryAGet16(0x0020 + seg, 0x4155) + seg); // 068f -> 168f; lin=4355
    memoryASet16(0x0020 + seg, 0x51c7, memoryAGet16(0x0020 + seg, 0x51c7) + seg); // 068f -> 168f; lin=53c7
    memoryASet16(0x0020 + seg, 0x52ed, memoryAGet16(0x0020 + seg, 0x52ed) + seg); // 068f -> 168f; lin=54ed
    memoryASet16(0x0020 + seg, 0x5339, memoryAGet16(0x0020 + seg, 0x5339) + seg); // 068f -> 168f; lin=5539
    memoryASet16(0x0020 + seg, 0x53a3, memoryAGet16(0x0020 + seg, 0x53a3) + seg); // 068f -> 168f; lin=55a3
    memoryASet16(0x0020 + seg, 0x53e6, memoryAGet16(0x0020 + seg, 0x53e6) + seg); // 068f -> 168f; lin=55e6
    memoryASet16(0x0020 + seg, 0x542f, memoryAGet16(0x0020 + seg, 0x542f) + seg); // 068f -> 168f; lin=562f
    memoryASet16(0x0020 + seg, 0x543d, memoryAGet16(0x0020 + seg, 0x543d) + seg); // 068f -> 168f; lin=563d
    memoryASet16(0x0020 + seg, 0x5491, memoryAGet16(0x0020 + seg, 0x5491) + seg); // 068f -> 168f; lin=5691
    memoryASet16(0x0020 + seg, 0x5546, memoryAGet16(0x0020 + seg, 0x5546) + seg); // 068f -> 168f; lin=5746
    memoryASet16(0x0020 + seg, 0x562e, memoryAGet16(0x0020 + seg, 0x562e) + seg); // 068f -> 168f; lin=582e
    memoryASet16(0x0020 + seg, 0x56d0, memoryAGet16(0x0020 + seg, 0x56d0) + seg); // 068f -> 168f; lin=58d0
    memoryASet16(0x0020 + seg, 0x5946, memoryAGet16(0x0020 + seg, 0x5946) + seg); // 068f -> 168f; lin=5b46
    memoryASet16(0x0020 + seg, 0x658f, memoryAGet16(0x0020 + seg, 0x658f) + seg); // 068f -> 168f; lin=678f
    memoryASet16(0x0020 + seg, 0x65d8, memoryAGet16(0x0020 + seg, 0x65d8) + seg); // 068f -> 168f; lin=67d8
}

int GetProcAt(int seg, int ofs)
{
    int map[] = {
        0x10205, 0x1020, 0x5, 0x1020, 0x157, 0x10358, 0x1020, 0x158, 0x1020, 0x173, 
        0x10373, 0x1020, 0x173, 0x1020, 0x1d9, 0x103d9, 0x1020, 0x1d9, 0x1020, 0x1f8, 
        0x103f8, 0x1020, 0x1f8, 0x1020, 0x27b, 0x10444, 0x1020, 0x244, 0x1020, 0x27b, 
        0x1047b, 0x1020, 0x27b, 0x1020, 0x333, 0x10533, 0x1020, 0x333, 0x1020, 0x38a, 
        0x1058a, 0x1020, 0x38a, 0x1020, 0x3ae, 0x105ae, 0x1020, 0x3ae, 0x1020, 0x3dc, 
        0x105dc, 0x1020, 0x3dc, 0x1020, 0x3f2, 0x105f2, 0x1020, 0x3f2, 0x1020, 0x410, 
        0x10610, 0x1020, 0x410, 0x1020, 0x423, 0x10623, 0x1020, 0x423, 0x1020, 0x465, 
        0x10665, 0x1020, 0x465, 0x1020, 0x488, 0x10688, 0x1020, 0x488, 0x1020, 0x495, 
        0x1070e, 0x1020, 0x495, 0x1020, 0x597, 0x107b7, 0x1020, 0x5b7, 0x1020, 0x5c7, 
        0x107c7, 0x1020, 0x5c7, 0x1020, 0x65e, 0x1085e, 0x1020, 0x65e, 0x1020, 0x691, 
        0x10891, 0x1020, 0x691, 0x1020, 0x6d4, 0x108d4, 0x1020, 0x6d4, 0x1020, 0x6ea, 
        0x108ea, 0x1020, 0x6ea, 0x1020, 0x701, 0x10901, 0x1020, 0x701, 0x1020, 0x7b0, 
        0x109b0, 0x1020, 0x7b0, 0x1020, 0x805, 0x10a05, 0x1020, 0x805, 0x1020, 0x8d0, 
        0x10b7b, 0x1020, 0x8ea, 0x1020, 0xa7e, 0x10b7b, 0x1020, 0xaf6, 0x1020, 0xc1e, 
        0x10cbe, 0x1020, 0x8fd, 0x1020, 0x910, 0x10cbe, 0x1020, 0x96c, 0x1020, 0x97b, 
        0x10cbe, 0x1020, 0xa7e, 0x1020, 0xad3, 0x10cbe, 0x1020, 0xad4, 0x1020, 0xaf1, 
        0x10e1e, 0x1020, 0xc1e, 0x1020, 0xc30, 0x10e30, 0x1020, 0x8fd, 0x1020, 0x910, 
        0x10e30, 0x1020, 0x96c, 0x1020, 0x97b, 0x10e30, 0x1020, 0xc30, 0x1020, 0xceb, 
        0x10eeb, 0x1020, 0xceb, 0x1020, 0xd23, 0x1127d, 0x1020, 0x107d, 0x1020, 0x10bc, 
        0x1127d, 0x1020, 0x10c5, 0x1020, 0x10d3, 0x112d3, 0x1020, 0x10d3, 0x1020, 0x10ff, 
        0x112ff, 0x1020, 0x10ff, 0x1020, 0x1198, 0x11398, 0x1020, 0x1198, 0x1020, 0x11e6, 
        0x113e6, 0x1020, 0x11e6, 0x1020, 0x122b, 0x11469, 0x1020, 0x1269, 0x1020, 0x12ab, 
        0x117a7, 0x1020, 0x15a7, 0x1020, 0x15de, 0x117de, 0x1020, 0x15de, 0x1020, 0x1610, 
        0x11810, 0x1020, 0x1610, 0x1020, 0x164f, 0x1184f, 0x1020, 0x164f, 0x1020, 0x16e0, 
        0x119eb, 0x1020, 0x17eb, 0x1020, 0x17fd, 0x119fe, 0x1020, 0x17fe, 0x1020, 0x183e, 
        0x11a3f, 0x1020, 0x183e, 0x1020, 0x18ae, 0x11aaf, 0x1020, 0x18ae, 0x1020, 0x191c, 
        0x11b1c, 0x1020, 0x191c, 0x1020, 0x1958, 0x11b58, 0x1020, 0x1958, 0x1020, 0x1a29, 
        0x11c2a, 0x1020, 0x1a29, 0x1020, 0x1a59, 0x11c2a, 0x1020, 0x1a61, 0x1020, 0x1a8d, 
        0x11c59, 0x1020, 0x1a29, 0x1020, 0x1a2a, 0x11c59, 0x1020, 0x1a59, 0x1020, 0x1a8d, 
        0x11c8d, 0x1020, 0x1a8d, 0x1020, 0x1b83, 0x11d83, 0x1020, 0x1b83, 0x1020, 0x1bb6, 
        0x11db6, 0x1020, 0x1bb6, 0x1020, 0x1c09, 0x11e09, 0x1020, 0x1c09, 0x1020, 0x1c19, 
        0x11e1a, 0x1020, 0x1c1a, 0x1020, 0x1c30, 0x11e30, 0x1020, 0x1c30, 0x1020, 0x1c46, 
        0x11e61, 0x1020, 0x1c61, 0x1020, 0x24c9, 0x126c9, 0x1020, 0x24c9, 0x1020, 0x2747, 
        0x1296f, 0x1020, 0x276f, 0x1020, 0x27df, 0x129df, 0x1020, 0x27df, 0x1020, 0x2811, 
        0x12a11, 0x1020, 0x2811, 0x1020, 0x28cd, 0x12acd, 0x1020, 0x28cd, 0x1020, 0x28f8, 
        0x12af8, 0x1020, 0x28f8, 0x1020, 0x2911, 0x12b11, 0x1020, 0x2911, 0x1020, 0x294c, 
        0x12b4c, 0x1020, 0x294c, 0x1020, 0x2994, 0x12b94, 0x1020, 0x2994, 0x1020, 0x29b5, 
        0x12b94, 0x1020, 0x29f2, 0x1020, 0x2a0d, 0x12bb5, 0x1020, 0x29b5, 0x1020, 0x2a0d, 
        0x12c0d, 0x1020, 0x2a0d, 0x1020, 0x2ab1, 0x12cb1, 0x1020, 0x2ab1, 0x1020, 0x2b67, 
        0x12d67, 0x1020, 0x2b67, 0x1020, 0x2b9f, 0x12da2, 0x1020, 0x2b9f, 0x1020, 0x2c87, 
        0x12e87, 0x1020, 0x2c87, 0x1020, 0x2d62, 0x12f62, 0x1020, 0x2d62, 0x1020, 0x2ddc, 
        0x12fdc, 0x1020, 0x2ddc, 0x1020, 0x2df5, 0x12fdc, 0x1020, 0x2e53, 0x1020, 0x2eb7, 
        0x12fe8, 0x1020, 0x2de8, 0x1020, 0x2df5, 0x12ff5, 0x1020, 0x2df5, 0x1020, 0x2e53, 
        0x13053, 0x1020, 0x2e53, 0x1020, 0x2eb7, 0x130b7, 0x1020, 0x2eb7, 0x1020, 0x2f76, 
        0x13176, 0x1020, 0x2f76, 0x1020, 0x2fdd, 0x131dd, 0x1020, 0x2fdd, 0x1020, 0x3009, 
        0x13209, 0x1020, 0x3009, 0x1020, 0x307d, 0x1327d, 0x1020, 0x307d, 0x1020, 0x3126, 
        0x1327d, 0x1020, 0x3160, 0x1020, 0x3243, 0x13326, 0x1020, 0x3126, 0x1020, 0x3160, 
        0x13360, 0x1020, 0x3160, 0x1020, 0x3243, 0x13443, 0x1020, 0x3243, 0x1020, 0x3271, 
        0x13471, 0x1020, 0x3271, 0x1020, 0x32dc, 0x134dc, 0x1020, 0x32dc, 0x1020, 0x32f4, 
        0x134f4, 0x1020, 0x32f4, 0x1020, 0x330e, 0x13811, 0x1020, 0x3611, 0x1020, 0x3627, 
        0x13827, 0x1020, 0x350e, 0x1020, 0x3611, 0x13827, 0x1020, 0x3627, 0x1020, 0x378d, 
        0x1392f, 0x1020, 0x372f, 0x1020, 0x378d, 0x1398d, 0x1020, 0x378d, 0x1020, 0x37f5, 
        0x139f5, 0x1020, 0x37f5, 0x1020, 0x38b5, 0x13ab5, 0x1020, 0x38b5, 0x1020, 0x39c7, 
        0x13bc7, 0x1020, 0x39c7, 0x1020, 0x3d97, 0x13f97, 0x1020, 0x3d97, 0x1020, 0x3e28, 
        0x14028, 0x1020, 0x3e28, 0x1020, 0x3ee8, 0x140e8, 0x1020, 0x3ee8, 0x1020, 0x3f46, 
        0x14146, 0x1020, 0x3f46, 0x1020, 0x3f74, 0x14174, 0x1020, 0x3f74, 0x1020, 0x403c, 
        0x1423c, 0x1020, 0x403c, 0x1020, 0x40fa, 0x142fa, 0x1020, 0x40fa, 0x1020, 0x414b, 
        0x1434b, 0x1020, 0x414b, 0x1020, 0x4484, 0x14684, 0x1020, 0x4484, 0x1020, 0x4561, 
        0x14761, 0x1020, 0x4561, 0x1020, 0x4617, 0x14817, 0x1020, 0x4617, 0x1020, 0x4631, 
        0x14831, 0x1020, 0x4631, 0x1020, 0x4653, 0x14857, 0x1020, 0x4653, 0x1020, 0x4748, 
        0x14948, 0x1020, 0x4748, 0x1020, 0x476c, 0x1496c, 0x1020, 0x476c, 0x1020, 0x47b7, 
        0x149b7, 0x1020, 0x47b7, 0x1020, 0x47d3, 0x149d3, 0x1020, 0x47d3, 0x1020, 0x47fa, 
        0x149fa, 0x1020, 0x47fa, 0x1020, 0x4807, 0x14a07, 0x1020, 0x4807, 0x1020, 0x4814, 
        0x14a14, 0x1020, 0x4814, 0x1020, 0x4821, 0x14a21, 0x1020, 0x4814, 0x1020, 0x4826, 
        0x14a26, 0x1020, 0x4826, 0x1020, 0x4833, 0x14a33, 0x1020, 0x4833, 0x1020, 0x48cc, 
        0x14acc, 0x1020, 0x48cc, 0x1020, 0x48d6, 0x14ad6, 0x1020, 0x48d6, 0x1020, 0x495b, 
        0x14b5b, 0x1020, 0x495b, 0x1020, 0x4ae9, 0x14ce9, 0x1020, 0x4ae9, 0x1020, 0x4b49, 
        0x14d49, 0x1020, 0x4b49, 0x1020, 0x4b7d, 0x14d7d, 0x1020, 0x4b7d, 0x1020, 0x4bb6, 
        0x14db6, 0x1020, 0x4bb6, 0x1020, 0x4bd0, 0x14dd0, 0x1020, 0x4bd0, 0x1020, 0x4be8, 
        0x14de8, 0x1020, 0x4be8, 0x1020, 0x4c12, 0x14e12, 0x1020, 0x4c12, 0x1020, 0x4c2a, 
        0x14e2a, 0x1020, 0x4c2a, 0x1020, 0x4c4d, 0x14e65, 0x1020, 0x4c65, 0x1020, 0x4ca2, 
        0x14ea2, 0x1020, 0x4ca2, 0x1020, 0x4ca8, 0x14ea8, 0x1020, 0x4ca8, 0x1020, 0x4cd8, 
        0x14ed8, 0x1020, 0x4ca2, 0x1020, 0x4ca8, 0x14ed8, 0x1020, 0x4cd8, 0x1020, 0x4d0b, 
        0x14ef0, 0x1020, 0x4cf0, 0x1020, 0x4d0b, 0x14ef6, 0x1020, 0x4cf6, 0x1020, 0x4d0b, 
        0x14f0b, 0x1020, 0x4d0b, 0x1020, 0x4d0c, 0x14f0c, 0x1020, 0x4d0c, 0x1020, 0x4d10, 
        0x14f10, 0x1020, 0x4d10, 0x1020, 0x4d9a, 0x14f9a, 0x1020, 0x4d9a, 0x1020, 0x4db1, 
        0x14fb1, 0x1020, 0x4db1, 0x1020, 0x4dc0, 0x14fc0, 0x1020, 0x4dc0, 0x1020, 0x4dc9, 
        0x14fc9, 0x1020, 0x4dc9, 0x1020, 0x4df9, 0x14ff9, 0x1020, 0x4df9, 0x1020, 0x4dfd, 
        0x14ffd, 0x1020, 0x4dfd, 0x1020, 0x4e01, 0x15001, 0x1020, 0x4ca2, 0x1020, 0x4ca8, 
        0x15001, 0x1020, 0x4cd8, 0x1020, 0x4d0b, 0x15001, 0x1020, 0x4e01, 0x1020, 0x4e13, 
        0x15013, 0x1020, 0x4e13, 0x1020, 0x4e1c, 0x1501c, 0x1020, 0x4e1c, 0x1020, 0x4e25, 
        0x15025, 0x1020, 0x4e25, 0x1020, 0x4e2e, 0x1502e, 0x1020, 0x4df9, 0x1020, 0x4e01, 
        0x1502e, 0x1020, 0x4e2e, 0x1020, 0x4e87, 0x15087, 0x1020, 0x4e87, 0x1020, 0x4e88, 
        0x15088, 0x1020, 0x4e88, 0x1020, 0x4f03, 0x15103, 0x1020, 0x4f03, 0x1020, 0x4f1c, 
        0x1511f, 0x1020, 0x4f1c, 0x1020, 0x5045, 0x15245, 0x1020, 0x5045, 0x1020, 0x5095, 
        0x15295, 0x1020, 0x5095, 0x1020, 0x5122, 0x15322, 0x1020, 0x5122, 0x1020, 0x5133, 
        0x15333, 0x1020, 0x5133, 0x1020, 0x5153, 0x15353, 0x1020, 0x5153, 0x1020, 0x51c5, 
        0x153c6, 0x1020, 0x51c6, 0x1020, 0x5252, 0x15452, 0x1020, 0x5252, 0x1020, 0x52ec, 
        0x154ec, 0x1020, 0x52ec, 0x1020, 0x5338, 0x15538, 0x1020, 0x5338, 0x1020, 0x53a2, 
        0x155a2, 0x1020, 0x53a2, 0x1020, 0x53c8, 0x155c8, 0x1020, 0x53c8, 0x1020, 0x54c4, 
        0x15677, 0x1020, 0x5439, 0x1020, 0x54c4, 0x15757, 0x1020, 0x54c4, 0x1020, 0x5556, 
        0x15757, 0x1020, 0x5557, 0x1020, 0x562d, 0x1582d, 0x1020, 0x562d, 0x1020, 0x5645, 
        0x15845, 0x1020, 0x5645, 0x1020, 0x56cc, 0x158cc, 0x1020, 0x56cc, 0x1020, 0x5737, 
        0x15937, 0x1020, 0x5737, 0x1020, 0x58b0, 0x15ab0, 0x1020, 0x58b0, 0x1020, 0x58c8, 
        0x15ac8, 0x1020, 0x58c8, 0x1020, 0x592d, 0x15b2d, 0x1020, 0x592d, 0x1020, 0x5945, 
        0x15b45, 0x1020, 0x5945, 0x1020, 0x596f, 0x15b6f, 0x1020, 0x596f, 0x1020, 0x59a1, 
        0x15ba1, 0x1020, 0x59a1, 0x1020, 0x59bb, 0x15bcc, 0x1020, 0x59cc, 0x1020, 0x59e7, 
        0x15be7, 0x1020, 0x59e7, 0x1020, 0x5a03, 0x15c03, 0x1020, 0x5a03, 0x1020, 0x5a04, 
        0x15c04, 0x1020, 0x5a04, 0x1020, 0x5a58, 0x15cb8, 0x1020, 0x5a58, 0x1020, 0x5b4e, 
        0x15d4e, 0x1020, 0x5b4e, 0x1020, 0x5bbb, 0x15dbb, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x15dbb, 0x1020, 0x5bbb, 0x1020, 0x5c60, 0x15e60, 0x1020, 0x5c60, 0x1020, 0x5cca, 
        0x15eca, 0x1020, 0x5a58, 0x1020, 0x5ab8, 0x15eca, 0x1020, 0x5cca, 0x1020, 0x5d02, 
        0x15eca, 0x1020, 0x5d09, 0x1020, 0x5dce, 0x15fce, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x15fce, 0x1020, 0x5dce, 0x1020, 0x5eca, 0x160ca, 0x1020, 0x5eca, 0x1020, 0x5ee4, 
        0x160e4, 0x1020, 0x5ee4, 0x1020, 0x5ef2, 0x160f2, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x160f2, 0x1020, 0x5ef2, 0x1020, 0x5ff9, 0x161f9, 0x1020, 0x5ff9, 0x1020, 0x5ffe, 
        0x161fe, 0x1020, 0x5a58, 0x1020, 0x5ab8, 0x161fe, 0x1020, 0x5ffe, 0x1020, 0x6009, 
        0x16209, 0x1020, 0x6009, 0x1020, 0x600f, 0x16209, 0x1020, 0x6019, 0x1020, 0x60e0, 
        0x1620f, 0x1020, 0x5a58, 0x1020, 0x5ab8, 0x1620f, 0x1020, 0x600f, 0x1020, 0x60e0, 
        0x162e0, 0x1020, 0x5a58, 0x1020, 0x5ab8, 0x162e0, 0x1020, 0x60e0, 0x1020, 0x621c, 
        0x1641c, 0x1020, 0x621c, 0x1020, 0x622e, 0x1642e, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x1642e, 0x1020, 0x622e, 0x1020, 0x62c9, 0x164c9, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x164c9, 0x1020, 0x62c9, 0x1020, 0x63bf, 0x165bf, 0x1020, 0x5a58, 0x1020, 0x5ab8, 
        0x165bf, 0x1020, 0x63bf, 0x1020, 0x63f1, 0x165c9, 0x1020, 0x63c9, 0x1020, 0x63f1, 
        0x165f1, 0x1020, 0x5a58, 0x1020, 0x5ab8, 0x165f1, 0x1020, 0x63f1, 0x1020, 0x6496, 
        0x16696, 0x1020, 0x6496, 0x1020, 0x64df, 0x166df, 0x1020, 0x64df, 0x1020, 0x64ef, 
        0x166ef, 0x1020, 0x64ef, 0x1020, 0x64ff, 0x166ff, 0x1020, 0x64ff, 0x1020, 0x6567, 
        0x1675c, 0x1020, 0x655c, 0x1020, 0x6567, 0x16767, 0x1020, 0x6567, 0x1020, 0x6582, 
        0x16782, 0x1020, 0x6582, 0x1020, 0x65be, 0x167be, 0x1020, 0x65be, 0x1020, 0x6676, 
    };

    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs < map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
