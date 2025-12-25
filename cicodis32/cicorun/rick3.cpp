#if 0
#include "cico16.h"
#include <stdio.h>
void fixReloc(uint16_t seg);
void sub_1c276();

void init()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1c80;
    cs = 0x1040;
    ds = 0x1030;
    es = 0x1030;
    ss = 0x1000;
    sp = 0x0400;
    load("rick2.zip", "RICK2.EXE", 50943);
    fixReloc(loadAddress);
}

void start()
{
    sub_1c276();
}


void sub_10524();
void sub_10533();
void sub_10594();
void sub_105a1();
void sub_105cc();
void sub_105f7();
void sub_10661();
void sub_10702();
void sub_10776();
void sub_1079d();
void sub_107ac();
void sub_107f1();
void sub_10836();
void sub_1087b();
void sub_1088d();
void sub_108dd();
void sub_108f7();
void sub_1091b();
void sub_10986();
void sub_109a5();
void sub_109c4();
void sub_109d3();
void sub_109ee();
void sub_10a67();
void sub_10ae7();
void sub_10bb1();
void sub_10bc4();
void sub_10c2e();
void sub_10c98();
void sub_10ccd();
void sub_10d03();
void sub_10d3d();
void sub_10d5c();
void sub_10daa();
void sub_10df8();
void sub_10e23();
void sub_10e40();
void sub_10e7f();
void sub_10ea6();
void sub_10ec0();
void sub_10ed8();
void sub_10ee4();
void sub_10ee5();
void sub_10ee6();
void sub_10ee7();
void sub_10ee8();
void sub_11162();
void sub_111f1();
void sub_112d6();
void sub_11376();
void sub_15f40();
void sub_15fe4();
void sub_16022();
void sub_16126();
void sub_1613c();
void sub_1615f();
void sub_16174();
void sub_1618f();
void sub_16205();
void sub_16222();
void sub_16407();
void sub_1646e();
void sub_164a0();
void sub_164e1();
void sub_16519();
void sub_16555();
void sub_16591();
void sub_1686f();
void sub_168a8();
void sub_168e4();
void sub_16907();
void sub_1691d();
void sub_169e3();
void sub_16b3b();
void sub_16b9b();
void sub_16bc7();
void sub_16bf7();
void sub_16c27();
void sub_16c3d();
void sub_16c53();
void sub_16c69();
void sub_16cb8();
void sub_16cd7();
void sub_16d69();
void sub_16e16();
void sub_16e39();
void sub_16e66();
void sub_16e74();
void sub_16ea1();
void sub_16eb2();
void sub_16ff5();
void sub_17018();
void sub_17047();
void sub_1705d();
void sub_1709d();
void sub_170e6();
void sub_17132();
void sub_17180();
void sub_1718e();
void sub_17205();
void sub_17222();
void sub_17674();
void sub_176e6();
void sub_176f4();
void sub_17702();
void sub_17723();
void sub_177fb();
void sub_17896();
void sub_17a31();
void sub_17a8b();
void sub_17c64();
void sub_17cf4();
void sub_17d53();
void sub_17d70();
void sub_17dfb();
void sub_17fbf();
void sub_17ff3();
void sub_18014();
void sub_1802d();
void sub_181a4();
void sub_181c6();
void sub_18351();
void sub_18a9a();
void sub_18c83();
void sub_18cbe();
void sub_18d28();
void sub_19214();
void sub_1926d();
void sub_192ae();
void sub_192da();
void sub_1930a();
void sub_1933f();
void sub_19351();
void sub_19420();
void sub_19462();
void sub_194c4();
void sub_19553();
void sub_19577();
void sub_19593();
void sub_195ea();
void sub_1961d();
void sub_196dd();
void sub_196f3();
void sub_19731();
void sub_199c8();
void sub_19af6();
void sub_19b1c();
void sub_19b40();
void sub_19bac();
void sub_19bdc();
void sub_19c05();
void sub_19c43();
void sub_19e18();
void sub_19eb5();
void sub_19ebb();
void sub_19ed0();
void sub_19ee5();
void sub_19f12();
void sub_19f8a();
void sub_1a102();
void sub_1a111();
void sub_1a120();
void sub_1a121();
void sub_1a137();
void sub_1a13f();
void sub_1a155();
void sub_1a168();
void sub_1a1bc();
void sub_1a1d7();
void sub_1a1e4();
void sub_1a1e6();
void sub_1a1fd();
void sub_1a234();
void sub_1a23e();
void sub_1a24c();
void sub_1a257();
void sub_1a2c4();
void sub_1a2f6();
void sub_1a389();
void sub_1a3cf();
void sub_1a437();
void sub_1a44f();
void sub_1a45c();
void sub_1a54a();
void sub_1a56b();
void sub_1a592();
void sub_1a5e3();
void sub_1a5f0();
void sub_1a65b();
void sub_1a67b();
void sub_1a693();
void sub_1a69d();
void sub_1ad6e();
void sub_1adb0();
void sub_1adcb();
void sub_1ae03();
void sub_1ae81();
void sub_1aecd();
void sub_1b95d();
void sub_1bb3f();
void sub_1bc92();
void sub_1bcb7();
void sub_1bf7c();
void sub_1bfa0();
void sub_1c0a8();
void sub_1c164();
void sub_1c1a2();
void sub_1c276();
void sub_1c359();
void sub_1c4bd();
void sub_1c4ca();
void sub_1c4e1();
void sub_1c4e2();

void indirectCall(int seg, int ofs)
{
    if (seg == 0x1040)
    {
        switch (ofs)
        {
            case 0x124: sub_10524(); return;
            case 0x133: sub_10533(); return;
            case 0x194: sub_10594(); return;
            case 0x1a1: sub_105a1(); return;
            case 0x1cc: sub_105cc(); return;
            case 0x302: sub_10702(); return;
            case 0x3f1: sub_107f1(); return;
            case 0x436: sub_10836(); return;
            case 0x47b: sub_1087b(); return;
            case 0x4dd: sub_108dd(); return;
            case 0x586: sub_10986(); return;
            case 0x5a5: sub_109a5(); return;
            case 0x5c4: sub_109c4(); return;
            case 0x5d3: sub_109d3(); return;
            case 0x5ee: sub_109ee(); return;
            case 0x667: sub_10a67(); return;
            case 0x7c4: sub_10bc4(); return;
            case 0x82e: sub_10c2e(); return;
            case 0x51b: sub_1091b(); return;
            case 0x903: sub_10d03(); return;
            case 0x9f8: sub_10df8(); return;
            case 0x93d: sub_10d3d(); return;
            case 0xa23: sub_10e23(); return;
            case 0xa40: sub_10e40(); return;
            case 0xaa6: sub_10ea6(); return;
            case 0xac0: sub_10ec0(); return;
            case 0xa7f: sub_10e7f(); return;
            case 0xad8: sub_10ed8(); return;
            case 0xae4: sub_10ee4(); return;
            case 0xae6: sub_10ee6(); return;
            case 0xae5: sub_10ee5(); return;
            case 0xd62: sub_11162(); return;
            case 0xdf1: sub_111f1(); return;
            case 0xed6: sub_112d6(); return;
            case 0xf76: sub_11376(); return;
            case 0x3ac: sub_107ac(); return;
            case 0xae7: sub_10ee7(); return;
            case 0xae8: sub_10ee8(); return;
        }
    }
    if (seg == 0x1040)
    {
        switch (ofs)
        {
            case 0x9d20: sub_1a120(); return;
            case 0x9d21: sub_1a121(); return;
            case 0x9d37: sub_1a137(); return;
            case 0x9d3f: sub_1a13f(); return;
            case 0x9d55: sub_1a155(); return;
            case 0x9d68: sub_1a168(); return;
            case 0x9dbc: sub_1a1bc(); return;
            case 0x9dd7: sub_1a1d7(); return;
            case 0x9de4: sub_1a1e4(); return;
            case 0x9ef6: sub_1a2f6(); return;
            case 0x9de6: sub_1a1e6(); return;
            case 0x9dfd: sub_1a1fd(); return;
            case 0x9e34: sub_1a234(); return;
            case 0x9e3e: sub_1a23e(); return;
            case 0x9e4c: sub_1a24c(); return;
        }
    }
    stop("ind");
}

void sub_10524() // 1040:0124
{
    ah = 0x0f;
    interrupt(0x10);
    memoryASet(ds, 0x006a, al);
    ax = 0x000d;
    interrupt(0x10);
}
void sub_10533() // 1040:0133
{
    ah = 0x48;
    bx = 0x0200;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1053f;
    sub_19731();
    return;
loc_1053f: // 1040:013f
    memoryASet16(ds, 0x004c, ax);
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1054e;
    sub_19731();
    return;
loc_1054e: // 1040:014e
    memoryASet16(ds, 0x0062, ax);
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1055d;
    sub_19731();
    return;
loc_1055d: // 1040:015d
    memoryASet16(ds, 0x0064, ax);
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1056c;
    sub_19731();
    return;
loc_1056c: // 1040:016c
    memoryASet16(ds, 0x0066, ax);
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1057b;
    sub_19731();
    return;
loc_1057b: // 1040:017b
    memoryASet16(ds, 0x0068, ax);
    ah = 0x48;
    bx = 0x0080;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1058a;
    sub_19731();
    return;
loc_1058a: // 1040:018a
    memoryASet16(ds, 0x0052, ax);
    memoryASet16(ds, 0x0056, 0xa400);
}
void sub_10594() // 1040:0194
{
    ax = memoryAGet16(ds, 0x0062);
    cx = 0x4344;
    dx = 0x00cd;
    sub_1a65b();
}
void sub_105a1() // 1040:01a1
{
    ax = memoryAGet16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00e5;
    sub_1a65b();
    cx = 0x0400;
    ax = 0xa680;
    sub_105f7();
    ax = memoryAGet16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00f1;
    sub_1a65b();
    cx = 0x0080;
    ax = 0xa700;
    sub_105f7();
}
void sub_105cc() // 1040:01cc
{
    ax = memoryAGet16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00d9;
    sub_1a65b();
    cx = 0x0400;
    ax = 0xa600;
    sub_105f7();
    ax = memoryAGet16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00fd;
    sub_1a65b();
    cx = 0x0180;
    ax = 0xa980;
    sub_105f7();
}
void sub_105f7() // 1040:01f7
{
    push(ds);
    push(es);
    bp = cx;
    dx = memoryAGet16(ds, 0x004c);
    ds = dx;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0202;
    out16(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0402;
    out16(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0802;
    out16(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10661() // 1040:0261
{
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
}
void sub_10702() // 1040:0302
{
    memoryASet(ds, 0x0279, 0x00);
    si = 0x029a;
    di = 0x02ce;
    cx = 0x0033;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0x1a00;
    interrupt(0x10);
    if ((char)bl <= (char)0x05)
        goto loc_10731;
    if ((char)bl < (char)0x07)
        goto loc_10731;
    if ((char)bl > (char)0x08)
        goto loc_10731;
    si = 0x028a;
    memoryASet(ds, 0x0279, 0x01);
    goto loc_1073e;
    // gap 1 bytes
loc_10731: // 1040:0331
    si = 0x027a;
    memoryASet(ds, 0x0279, 0x00);
    memoryASet(ds, 0x0278, 0x01);
loc_1073e: // 1040:033e
    memoryASet(ds, 0x0301, 0x00);
    cx = 0x0010;
loc_10746: // 1040:0346
    ah = 0x10;
    al = 0x00;
    bh = memoryAGet(ds, si);
    si++;
    bl = memoryAGet(ds, 0x0301);
    memoryASet(ds, 0x0301, memoryAGet(ds, 0x0301) + 1);
    push(si);
    push(cx);
    interrupt(0x10);
    cx = pop();
    si = pop();
    if (--cx)
        goto loc_10746;
    if (memoryAGet(ds, 0x0279) != 0x01)
        goto loc_1076a;
    sub_10776();
    sub_1079d();
loc_1076a: // 1040:036a
    di = 0x029a;
    si = 0x02ce;
    cx = 0x0033;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
}
void sub_10776() // 1040:0376
{
    si = 0x029a;
    memoryASet(ds, 0x0301, 0x00);
    cx = 0x0010;
loc_10781: // 1040:0381
    push(cx);
    bh = 0x09;
    al = memoryAGet(ds, si);
    ax = ((char)bh * (short)ax) & 0xffff;
    memoryASet(ds, si, al);
    si++;
    al = memoryAGet(ds, si);
    ax = ((char)bh * (short)ax) & 0xffff;
    memoryASet(ds, si, al);
    si++;
    al = memoryAGet(ds, si);
    ax = ((char)bh * (short)ax) & 0xffff;
    memoryASet(ds, si, al);
    si++;
    cx = pop();
    if (--cx)
        goto loc_10781;
}
void sub_1079d() // 1040:039d
{
    bx = 0;
    cx = 0x0010;
    dx = 0x029a;
    al = 0x12;
    ah = 0x10;
    interrupt(0x10);
}
void sub_107ac() // 1040:03ac
{
    dx = 0;
    cx = dx;
    ch = ah;
    dh = ah;
    dx >>= 1;
    dx >>= 1;
    dx += cx;
    ah = 0;
    dx += ax;
    di = dx;
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005a);
    cx = 0x0027;
    ax = 0xa980;
    ds = ax;
loc_107ce: // 1040:03ce
    ax = 0;
    al = memoryAGet(cs, si);
    si++;
    if (al == 0xff)
        goto loc_107ee;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = si;
    si = ax;
    ax = di;
    sub_10661();
    si = bx;
    di = ax;
    di++;
    goto loc_107ce;
loc_107ee: // 1040:03ee
    es = pop();
    ds = pop();
}
void sub_107f1() // 1040:03f1
{
    dx = 0;
    cx = dx;
    ch = ah;
    dh = ah;
    dx >>= 1;
    dx >>= 1;
    dx += cx;
    ah = 0;
    dx += ax;
    di = dx;
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005a);
    cx = 0x0027;
    ax = 0xa600;
    ds = ax;
loc_10813: // 1040:0413
    ax = 0;
    al = memoryAGet(cs, si);
    si++;
    if (al == 0xff)
        goto loc_10833;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = si;
    si = ax;
    ax = di;
    sub_10661();
    si = bx;
    di = ax;
    di++;
    goto loc_10813;
loc_10833: // 1040:0433
    es = pop();
    ds = pop();
}
void sub_10836() // 1040:0436
{
    dx = 0;
    cx = dx;
    ch = ah;
    dh = ah;
    dx >>= 1;
    dx >>= 1;
    dx += cx;
    ah = 0;
    dx += ax;
    di = dx;
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005c);
    cx = 0x0027;
    ax = 0xa600;
    ds = ax;
loc_10858: // 1040:0458
    ax = 0;
    al = memoryAGet(cs, si);
    si++;
    if (al == 0xff)
        goto loc_10878;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = si;
    si = ax;
    ax = di;
    sub_10661();
    si = bx;
    di = ax;
    di++;
    goto loc_10858;
loc_10878: // 1040:0478
    es = pop();
    ds = pop();
}
void sub_1087b() // 1040:047b
{
    cx = 0x0100;
    ax = 0x0000;
    dx = 0x0008;
    di = 0x2f73;
loc_10887: // 1040:0487
    stosw<ES_DI>(ax);
    ax += dx;
    if (--cx)
        goto loc_10887;
}
void sub_1088d() // 1040:048d
{
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x0056);
    ax = 0xa680;
    ds = ax;
    cx = 0x0020;
loc_1089b: // 1040:049b
    bp = cx;
    ax = 0;
    al = memoryAGet(cs, bx);
    if ((short)ax < (short)0x00f8)
        goto loc_108aa;
    sub_19593();
loc_108aa: // 1040:04aa
    bx++;
    ax <<= 1;
    ax += 0x2f73;
    si = ax;
    si = memoryAGet16(cs, si);
    cx = 0x001f;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += cx;
    movsb<ES_DI, DS_SI>();
    di += 0xff20;
    cx = bp;
    if (--cx)
        goto loc_1089b;
    di += 0x00e0;
    es = pop();
    ds = pop();
}
void sub_108dd() // 1040:04dd
{
    bx = 0x571c;
    di = 0x1e00;
    sub_1088d();
    di = 0x0000;
    bx = 0x573c;
    cx = 0x001a;
loc_108ef: // 1040:04ef
    push(cx);
    sub_1088d();
    cx = pop();
    if (--cx)
        goto loc_108ef;
}
void sub_108f7() // 1040:04f7
{
    if (!ax)
        goto loc_1091a;
    push(ds);
    push(es);
    dx = ax;
    bp = 0x0020;
    bx = 0x0008;
    es = memoryAGet16(cs, 0x005a);
    ds = memoryAGet16(cs, 0x0056);
loc_1090f: // 1040:050f
    cx = bp;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di += bx;
    dx--;
    if (dx)
        goto loc_1090f;
    es = pop();
    ds = pop();
loc_1091a: // 1040:051a
    return;
}
void sub_1091b() // 1040:051b
{
    dx = memoryAGet16(ds, 0x6c45);
    dx += 0x00c0;
    dx &= 0x00ff;
    if ((short)dx > (short)memoryAGet16(ds, 0x6c45))
        goto loc_10969;
    ax = dx;
    si = 0x0000;
    di = 0x0144;
    dx = 0x0100;
    dx -= memoryAGet16(ds, 0x6c45);
    dx += dx;
    bx = 0x3173;
    bx += dx;
    di += memoryAGet16(ds, bx);
    sub_108f7();
    si = 0x0000;
    dx = memoryAGet16(ds, 0x6c45);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    di = 0x0144;
    ax = 0x0100;
    ax -= memoryAGet16(ds, 0x6c45);
    sub_108f7();
    return;
loc_10969: // 1040:0569
    si = 0x0000;
    dx = memoryAGet16(ds, 0x6c45);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    di = 0x0144;
    ax = 0x00c0;
    sub_108f7();
}
void sub_10986() // 1040:0586
{
    bx = 0x573c;
    ax = memoryAGet16(ds, 0x6c45);
    ax &= 0x00f8;
    ax -= 0x0008;
    ax &= 0x00ff;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di = ax;
    sub_1088d();
}
void sub_109a5() // 1040:05a5
{
    bx = 0x5a5c;
    ax = memoryAGet16(ds, 0x6c45);
    ax &= 0x00f8;
    ax += 0x00d0;
    ax &= 0x00ff;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di = ax;
    sub_1088d();
}
void sub_109c4() // 1040:05c4
{
    di = 0x3173;
    ax = 0;
    cx = 0x0100;
loc_109cc: // 1040:05cc
    stosw<ES_DI>(ax);
    ax += 0x0028;
    if (--cx)
        goto loc_109cc;
}
void sub_109d3() // 1040:05d3
{
    memoryASet16(ds, 0x005a, 0xa000);
    memoryASet16(ds, 0x005c, 0xa200);
    memoryASet16(ds, 0x005e, 0x0000);
    memoryASet16(ds, 0x0060, 0x2000);
}
void sub_109ee() // 1040:05ee
{
    push(ds);
    push(es);
    push(ax);
    push(cx);
    push(dx);
    ax = memoryAGet16(ds, 0x005a);
    dx = memoryAGet16(ds, 0x005c);
    memoryASet16(ds, 0x005c, ax);
    memoryASet16(ds, 0x005a, dx);
    ax = memoryAGet16(ds, 0x005e);
    dx = memoryAGet16(ds, 0x0060);
    memoryASet16(ds, 0x0060, ax);
    memoryASet16(ds, 0x005e, dx);
    cx = memoryAGet16(ds, 0x0060);
    push(dx);
    push(ax);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    dx += 0x0006;
loc_10a22: // 1040:0622
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_10a22;
loc_10a27: // 1040:0627
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_10a27;
    dx -= 0x0006;
    flags.interrupts = 0;
    al = 0x0c;
    out8(dx, al);
    dx++;
    al = ch;
    out8(dx, al);
    dx--;
    al = 0x0d;
    out8(dx, al);
    dx++;
    al = cl;
    out8(dx, al);
    flags.interrupts = 1;
    ah = ch;
    ax <<= 1;
    memoryASet16(es, 0x004e, ax);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    dx += 0x0006;
loc_10a55: // 1040:0655
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_10a55;
loc_10a5a: // 1040:065a
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_10a5a;
    ax = pop();
    dx = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    es = pop();
    ds = pop();
//    sync();  //GABO sync ds:1c  //X
}
void sub_10a67() // 1040:0667
{
    if (memoryAGet16(ds, 0x9173) != 0x0000)
        goto loc_10a6f;
    return;
loc_10a6f: // 1040:066f
    bx = memoryAGet16(ds, 0x9175);
    cx = 0x0008;
loc_10a76: // 1040:0676
    push(cx);
    al = memoryAGet(ds, bx);
    if (!al)
        goto loc_10ad2;
    if ((char)al < 0)
        goto loc_10adc;
    dx = 0;
    dl = memoryAGet(ds, bx + 1);
    cl = dl;
    cl++;
    cl &= 0x03;
    dl &= 0xfc;
    dl |= cl;
    memoryASet(ds, bx + 1, dl);
    di = memoryAGet16(ds, bx + 4);
    bp = memoryAGet16(cs, bx + 6);
    si = 0;
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x0056);
    ax = 0xa700;
    ds = ax;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    si = dx;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    di += 0x001f;
    movsb<ES_DI, DS_SI>();
    es = pop();
    ds = pop();
loc_10ad2: // 1040:06d2
    bx += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_10a76;
    goto loc_10ae2;
    // gap 1 bytes
loc_10adc: // 1040:06dc
    bx = 0x54fa;
    cx = pop();
    if (--cx)
        goto loc_10a76;
loc_10ae2: // 1040:06e2
    memoryASet16(ds, 0x9175, bx);
}
void sub_10ae7() // 1040:06e7
{
    push(ds);
    push(es);
    bx = 0x573c;
    di = 0x0144;
    es = memoryAGet16(ds, 0x0056);
    ax = 0xa680;
    ds = ax;
    cx = 0x0018;
    dx = memoryAGet16(cs, 0x8bf0);
    dx &= 0x0007;
    if (!dx)
        goto loc_10b43;
    si = dx;
    bp = 0x0020;
    dx ^= 0x0007;
loc_10b0d: // 1040:070d
    push(si);
    push(di);
    ax = 0;
    al = memoryAGet(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    push(dx);
loc_10b1e: // 1040:071e
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    dx--;
    if ((short)dx >= 0)
        goto loc_10b1e;
    dx = pop();
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp)
        goto loc_10b0d;
    dx++;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax = dx;
    dx <<= 1;
    dx <<= 1;
    dx += ax;
    dx += 0xffe0;
    di += dx;
    goto loc_10b80;
    // gap 1 bytes
loc_10b43: // 1040:0743
    bp = 0x0020;
loc_10b46: // 1040:0746
    push(si);
    push(di);
    ax = 0;
    al = memoryAGet(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp)
        goto loc_10b46;
    di += 0x0120;
loc_10b80: // 1040:0780
    if (--cx)
        goto loc_10b43;
    dx = memoryAGet16(cs, 0x8bf0);
    dx &= 0x0007;
    if (!dx)
        goto loc_10bae;
    bp = 0x0020;
loc_10b8f: // 1040:078f
    push(si);
    push(di);
    ax = 0;
    al = memoryAGet(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    push(dx);
loc_10ba0: // 1040:07a0
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    dx--;
    if ((short)dx >= 0)
        goto loc_10ba0;
    dx = pop();
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp)
        goto loc_10b8f;
loc_10bae: // 1040:07ae
    es = pop();
    ds = pop();
}
void sub_10bb1() // 1040:07b1
{
    ax = memoryAGet16(ds, 0x005a);
    push(ax);
    ax = memoryAGet16(ds, 0x0056);
    memoryASet16(ds, 0x005a, ax);
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:07bb;
    ax = pop();
    memoryASet16(ds, 0x005a, ax);
}
void sub_10bc4() // 1040:07c4
{
    cx = memoryAGet16(ds, 0x96f4);
    push(cx);
    memoryASet16(ds, 0x96f4, 0x0001);
    push(ax);
    push(dx);
    indirectCall(cs, memoryAGet16(ds, 0x0024)); // 1040:07d1;
    memoryASet16(ds, 0x0b1c, 0x0000);
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:07db;
    memoryASet16(ds, 0x0b1c, 0x0001);
    dx = pop();
    ax = pop();
    sub_19351();
    sub_19214();
    sub_10ae7();
    sub_1618f();
    sub_15fe4();
    memoryASet(ds, 0x5b3e, 0x01);
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
    sub_10bb1();
    sub_19af6();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:080b;
    si = 0x0162;
    cx = 0x0010;
loc_10c15: // 1040:0815
    push(cx);
    push(si);
    sub_10c98();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:081a;
    si = pop();
    cx = pop();
    si += 0xfffe;
    if (--cx)
        goto loc_10c15;
    sub_17047();
    cx = pop();
    memoryASet16(ds, 0x96f4, cx);
}
void sub_10c2e() // 1040:082e
{
    cx = memoryAGet16(ds, 0x96f4);
    push(cx);
    memoryASet16(ds, 0x96f4, 0x0001);
    push(ax);
    push(dx);
    indirectCall(cs, memoryAGet16(ds, 0x0024)); // 1040:083b;
    memoryASet16(ds, 0x0b1c, 0x0000);
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:0845;
    memoryASet16(ds, 0x0b1c, 0x0001);
    dx = pop();
    ax = pop();
    sub_19351();
    sub_19214();
    sub_1618f();
    sub_10ae7();
    sub_15fe4();
    memoryASet(ds, 0x5b3e, 0x01);
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
    sub_10bb1();
    sub_19af6();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:0875;
    si = 0x0144;
    cx = 0x0010;
loc_10c7f: // 1040:087f
    push(cx);
    push(si);
    sub_10ccd();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:0884;
    si = pop();
    cx = pop();
    si += 0x0002;
    if (--cx)
        goto loc_10c7f;
    sub_17047();
    cx = pop();
    memoryASet16(ds, 0x96f4, cx);
}
void sub_10c98() // 1040:0898
{
    push(ds);
    push(es);
    bx = 0x0144;
    di = bx;
    bp = 0x00c0;
    es = memoryAGet16(ds, 0x005a);
    ax = memoryAGet16(ds, 0x0056);
    dx = memoryAGet16(ds, 0x005c);
loc_10cad: // 1040:08ad
    ds = ax;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    ds = dx;
    push(si);
    si = bx;
    cx = 0x001e;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    bx = si;
    si = pop();
    bx += 0x000a;
    si += 0x0026;
    di += 0x0008;
    bp--;
    if (bp)
        goto loc_10cad;
    es = pop();
    ds = pop();
}
void sub_10ccd() // 1040:08cd
{
    push(ds);
    push(es);
    bx = 0x0146;
    di = 0x0144;
    bp = 0x00c0;
    es = memoryAGet16(ds, 0x005a);
    ax = memoryAGet16(ds, 0x0056);
    dx = memoryAGet16(ds, 0x005c);
loc_10ce3: // 1040:08e3
    ds = dx;
    push(si);
    si = bx;
    cx = 0x001e;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    bx = si;
    si = pop();
    ds = ax;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    bx += 0x000a;
    si += 0x0026;
    di += 0x0008;
    bp--;
    if (bp)
        goto loc_10ce3;
    es = pop();
    ds = pop();
}
void sub_10d03() // 1040:0903
{
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memoryAGet16(cs, 0x005a);
    si = 0x0100;
    al = lodsb<DS_SI>();
    di = 0;
    cx = 0x1f40;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    es = pop();
    ds = pop();
    sub_19b1c();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:091f;
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memoryAGet16(cs, 0x005a);
    si = 0x0100;
    al = lodsb<DS_SI>();
    di = 0;
    cx = 0x1f40;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    es = pop();
    ds = pop();
}
void sub_10d3d() // 1040:093d
{
    ax = memoryAGet16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x010a;
    sub_1a65b();
    sub_10d5c();
    ax = memoryAGet16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x0116;
    sub_1a65b();
    sub_10daa();
}
void sub_10d5c() // 1040:095c
{
    push(ds);
    push(es);
    ax = memoryAGet16(ds, 0x0062);
    ds = ax;
    ax = 0xa780;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0202;
    out16(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10daa() // 1040:09aa
{
    push(ds);
    push(es);
    ax = memoryAGet16(ds, 0x0062);
    ds = ax;
    ax = 0xa780;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0402;
    out16(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0802;
    out16(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10df8() // 1040:09f8
{
    push(ds);
    push(es);
    ax = 0xa780;
    ds = ax;
    ax = 0xa000;
    es = ax;
    si = 0;
    di = si;
    cx = 0x1f40;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0xa780;
    ds = ax;
    ax = 0xa200;
    es = ax;
    si = 0;
    di = si;
    cx = 0x1f40;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    es = pop();
    ds = pop();
}
void sub_10e23() // 1040:0a23
{
    dx = 0;
    dl = ah;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    cx = dx;
    dx <<= 1;
    dx <<= 1;
    dx += cx;
    cl = 0x03;
    dx <<= cl;
    di = dx;
    ah = 0;
    di += ax;
}
void sub_10e40() // 1040:0a40
{
    push(ds);
    push(es);
    ax = 0xa600;
    ds = ax;
    es = memoryAGet16(cs, 0x0056);
loc_10e4c: // 1040:0a4c
    push(cx);
    push(si);
    push(di);
loc_10e4f: // 1040:0a4f
    ax = 0;
    al = memoryAGet(cs, si);
    si++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(si);
    push(di);
    si = ax;
    push(cx);
    cx = 0x0027;
    sub_10661();
    cx = pop();
    di = pop();
    si = pop();
    di++;
    cl--;
    if (cl)
        goto loc_10e4f;
    di = pop();
    di += 0x0140;
    si = pop();
    si += 0x0020;
    cx = pop();
    ch--;
    if (ch)
        goto loc_10e4c;
    es = pop();
    ds = pop();
}
void sub_10e7f() // 1040:0a7f
{
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005a);
    ds = memoryAGet16(ds, 0x0056);
    di = 0x0144;
    si = di;
    bp = 0x00c0;
loc_10e91: // 1040:0a91
    cx = 0x0020;
    push(si);
    push(di);
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di = pop();
    si = pop();
    si += 0x0028;
    di += 0x0028;
    bp--;
    if (bp)
        goto loc_10e91;
    es = pop();
    ds = pop();
}
void sub_10ea6() // 1040:0aa6
{
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memoryAGet16(cs, 0x0056);
    si = 0x0100;
    al = lodsb<DS_SI>();
    di = 0;
    cx = 0x1f40;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    es = pop();
    ds = pop();
}
void sub_10ec0() // 1040:0ac0
{
    dx = memoryAGet16(ds, 0x005a);
    push(dx);
    dx = memoryAGet16(ds, 0x0056);
    memoryASet16(ds, 0x005a, dx);
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:0acd;
    dx = pop();
    memoryASet16(ds, 0x005a, dx);
}
void sub_10ed8() // 1040:0ad8
{
}
void sub_10ee4() // 1040:0ae4
{
}
void sub_10ee5() // 1040:0ae5
{
}
void sub_10ee6() // 1040:0ae6
{
}
void sub_10ee7() // 1040:0ae7
{
}
void sub_10ee8() // 1040:0ae8
{
    ax = memoryAGet16(cs, 0x96f4);
    if (ax == 0x0001)
        goto loc_10ef6;
    ax--;
    memoryASet16(cs, 0x96f4, ax);
loc_10ef6: // 1040:0af6
    return;
}
void sub_11162() // 1040:0d62
{
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005a);
    si = 0x0b00;
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    ax = 0x0003;
    out16(dx, ax);
    ax = 0x0005;
    out16(dx, ax);
loc_1117a: // 1040:0d7a
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_11196;
    if (!ax)
        goto loc_11191;
    if (memoryAGet16(ds, si + 10) == 0x00fe)
        goto loc_11191;
    push(ds);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x0040)); // 1040:0d8b;
    si = pop();
    ds = pop();
loc_11191: // 1040:0d91
    si += 0x001c;
    goto loc_1117a;
loc_11196: // 1040:0d96
    si = 0x0b56;
loc_11199: // 1040:0d99
    ax = memoryAGet16(ds, si);
    if ((char)ah < 0)
        goto loc_111b7;
    if (!(al & 0x01))
        goto loc_111b2;
    if (memoryAGet16(ds, si + 10) == 0x00fe)
        goto loc_111b2;
    push(ds);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x0040)); // 1040:0dac;
    si = pop();
    ds = pop();
loc_111b2: // 1040:0db2
    si += 0x0034;
    goto loc_11199;
loc_111b7: // 1040:0db7
    si = 0x0c28;
loc_111ba: // 1040:0dba
    ax = memoryAGet16(ds, si);
    if ((char)ah < 0)
        goto loc_111d8;
    if (!(al & 0x01))
        goto loc_111d3;
    if (memoryAGet16(ds, si + 10) == 0x00fe)
        goto loc_111d3;
    push(ds);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x0040)); // 1040:0dcd;
    si = pop();
    ds = pop();
loc_111d3: // 1040:0dd3
    si += 0x0034;
    goto loc_111ba;
loc_111d8: // 1040:0dd8
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dl = 0xce;
    ax = 0x0105;
    out16(dx, ax);
    ax = 0x0001;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    es = pop();
    ds = pop();
}
void sub_111f1() // 1040:0df1
{
    bool temp_cond0;
    bool temp_cond1;

    bp = 0;
    ax = memoryAGet16(ds, si + 4);
    ax -= 0x0038;
    dx = memoryAGet16(ds, 0x8bf0);
    dx &= 0x0007;
    ax -= dx;
    if ((short)ax >= (short)0x0008)
        goto loc_1122c;
    cx = 0x0008;
    cx -= ax;
    ax = cx;
    cx = -cx;
    temp_cond0 = (short)cx + (short)0x0015 > 0;
    cx += 0x0015;
    if (temp_cond0)
        goto loc_11218;
    goto loc_112d5;
loc_11218: // 1040:0e18
    ax <<= 1;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    bp = ax;
    ax = 0x0140;
    goto loc_11252;
    // gap 1 bytes
loc_1122c: // 1040:0e2c
    if ((short)ax <= (short)0x00b3)
        goto loc_11241;
    cx = 0x00b3;
    cx -= ax;
    temp_cond1 = (short)cx + (short)0x0015 > 0;
    cx += 0x0015;
    if (temp_cond1)
        goto loc_1123e;
    goto loc_112d5;
loc_1123e: // 1040:0e3e
    goto loc_11244;
    // gap 1 bytes
loc_11241: // 1040:0e41
    cx = 0x0015;
loc_11244: // 1040:0e44
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
loc_11252: // 1040:0e52
    di = ax;
    ax = memoryAGet16(ds, si + 2);
    ax += 0x0020;
    ax &= 0xfff8;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    di += ax;
    ax = memoryAGet16(ds, si + 10);
    if ((short)ax < (short)0x0080)
        goto loc_11270;
    ax -= 0x0040;
loc_11270: // 1040:0e70
    bx = 0x01a4;
    mul16(bx);
    bx = memoryAGet16(ds, si + 2);
    bx += 0x0020;
    bx &= 0x0006;
    bx += 0x0062;
    ds = memoryAGet16(ds, bx);
    si = ax;
    si += bp;
    bp = 0x0024;
    dh = 0x03;
loc_1128d: // 1040:0e8d
    push(cx);
    cx = 0x0004;
loc_11291: // 1040:0e91
    ah = memoryAGet(ds, si);
    if (!ah)
        goto loc_112c9;
    al = 0x08;
    dl = 0xce;
    out16(dx, ax);
    dl = 0xc4;
    ax = 0x0f02;
    out16(dx, ax);
    ah = memoryAGet(es, di);
    ah = 0x01;
    out16(dx, ax);
    ah = memoryAGet(ds, si + 1);
    memoryASet(es, di, ah);
    ah = 0x02;
    out16(dx, ax);
    ah = memoryAGet(ds, si + 2);
    memoryASet(es, di, ah);
    ah = 0x04;
    out16(dx, ax);
    ah = memoryAGet(ds, si + 3);
    memoryASet(es, di, ah);
    ah = 0x08;
    out16(dx, ax);
    ah = memoryAGet(ds, si + 4);
    memoryASet(es, di, ah);
loc_112c9: // 1040:0ec9
    di++;
    si += 0x0005;
    if (--cx)
        goto loc_11291;
    di += bp;
    cx = pop();
    cx--;
    if (cx)
        goto loc_1128d;
loc_112d5: // 1040:0ed5
    return;
}
void sub_112d6() // 1040:0ed6
{
    push(ds);
    push(es);
    ds = memoryAGet16(ds, 0x0062);
    bp = 0x0064;
    di = 0;
    si = 0;
    cx = 0x0888;
loc_112e6: // 1040:0ee6
    push(cx);
    push(si);
    push(di);
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 5);
    bh = memoryAGet(ds, si + 10);
    bl = 0x00;
    push(bp);
    cx = 0x0003;
loc_112f7: // 1040:0ef7
    flags.carry = 0;
    ah = rcr8(ah, 0x01);
    al = rcr8(al, 0x01);
    bh = rcr8(bh, 0x01);
    bl = rcr8(bl, 0x01);
    flags.carry = 0;
    ah = rcr8(ah, 0x01);
    al = rcr8(al, 0x01);
    bh = rcr8(bh, 0x01);
    bl = rcr8(bl, 0x01);
    es = memoryAGet16(cs, bp);
    bp++;
    bp++;
    memoryASet(es, di, ah);
    memoryASet(es, di + 5, al);
    memoryASet(es, di + 10, bh);
    memoryASet(es, di + 15, bl);
    if (--cx)
        goto loc_112f7;
    bp = pop();
    si++;
    di++;
    cx = 0x0004;
loc_11326: // 1040:0f26
    push(cx);
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 5);
    bh = memoryAGet(ds, si + 10);
    bl = 0x00;
    push(bp);
    cx = 0x0003;
loc_11335: // 1040:0f35
    flags.carry = 0;
    ah = rcr8(ah, 0x01);
    al = rcr8(al, 0x01);
    bh = rcr8(bh, 0x01);
    bl = rcr8(bl, 0x01);
    flags.carry = 0;
    ah = rcr8(ah, 0x01);
    al = rcr8(al, 0x01);
    bh = rcr8(bh, 0x01);
    bl = rcr8(bl, 0x01);
    es = memoryAGet16(cs, bp);
    bp++;
    bp++;
    memoryASet(es, di, ah);
    memoryASet(es, di + 5, al);
    memoryASet(es, di + 10, bh);
    memoryASet(es, di + 15, bl);
    if (--cx)
        goto loc_11335;
    bp = pop();
    si++;
    di++;
    cx = pop();
    if (--cx)
        goto loc_11326;
    di = pop();
    si = pop();
    si += 0x0014;
    di += 0x0014;
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11373;
    goto loc_112e6;
loc_11373: // 1040:0f73
    es = pop();
    ds = pop();
}
void sub_11376() // 1040:0f76
{
    push(ds);
    push(es);
    es = memoryAGet16(ds, 0x005a);
    si = 0x0b00;
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    ax = 0x0003;
    out16(dx, ax);
    ax = 0x0005;
    out16(dx, ax);
    si = 0x9bd6;
loc_11391: // 1040:0f91
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_113b0;
    if (!ax)
        goto loc_113aa;
    if (memoryAGet16(ds, si + 10) == 0x00fe)
        goto loc_113aa;
    push(bx);
    push(ds);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x0040)); // 1040:0fa3;
    si = pop();
    ds = pop();
    bx = pop();
loc_113aa: // 1040:0faa
    si += 0x001a;
    goto loc_11391;
loc_113b0: // 1040:0fb0
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    dl = 0xce;
    ax = 0x0105;
    out16(dx, ax);
    ax = 0x0001;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    es = pop();
    ds = pop();
}
void sub_15f40() // 1040:5b40
{
    if (memoryAGet16(ds, 0x762d) != 0x0001)
        goto loc_15f52;
    if (memoryAGet16(ds, 0x762f) == 0x0001)
        goto loc_15f51;
    sub_17a31();
loc_15f51: // 1040:5b51
    return;
loc_15f52: // 1040:5b52
    bx = memoryAGet16(ds, 0x5b3c);
    if (bx)
        goto loc_15f5b;
    return;
loc_15f5b: // 1040:5b5b
    cx = memoryAGet16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx += 0x0025;
loc_15f68: // 1040:5b68
    al = memoryAGet(ds, bx);
    if (al)
        goto loc_15f6f;
    return;
loc_15f6f: // 1040:5b6f
    ah = al;
    bx++;
    al = memoryAGet(ds, bx);
    if (al < cl)
        goto loc_15f79;
    return;
loc_15f79: // 1040:5b79
    if (!(ah & 0x80))
        goto loc_15f90;
    bx++;
loc_15f7f: // 1040:5b7f
    bx++;
loc_15f80: // 1040:5b80
    al = memoryAGet(ds, bx);
    bx++;
    al &= 0x03;
    if (!al)
        goto loc_15f68;
loc_15f87: // 1040:5b87
    bx += 0x0004;
    al--;
    if (al)
        goto loc_15f87;
    goto loc_15f68;
loc_15f90: // 1040:5b90
    bx++;
    if (!(memoryAGet(ds, bx) & 0x80))
        goto loc_15fd4;
    al = memoryAGet(ds, 0x5b3e);
    if (al)
        goto loc_15fb9;
    push(cx);
    cx = memoryAGet16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    ah = cl;
    bx--;
    al = memoryAGet(ds, bx);
    bx++;
    al -= ah;
    cx = pop();
    if (al < 0x05)
        goto loc_15fb9;
    if (al < 0x22)
        goto loc_15f7f;
loc_15fb9: // 1040:5bb9
    bx--;
    bx--;
    push(bx);
loc_15fbc: // 1040:5bbc
    si = bx;
    sub_16205();
    bx = pop();
loc_15fc2: // 1040:5bc2
    bx++;
    bx++;
    bx++;
    cx = memoryAGet16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx += 0x0025;
    goto loc_15f80;
loc_15fd4: // 1040:5bd4
    bx--;
    bx--;
    push(bx);
    si = bx;
    dx = 0;
    sub_16222();
    bx = pop();
    if (!flags.carry)
        goto loc_15fc2;
    push(bx);
    goto loc_15fbc;
}
void sub_15fe4() // 1040:5be4
{
    bx = memoryAGet16(ds, 0x8bfc);
    memoryASet16(ds, 0x5b3c, bx);
    if (bx)
        goto loc_15ff1;
    return;
loc_15ff1: // 1040:5bf1
    al = memoryAGet(ds, bx);
    if (al)
        goto loc_15ff8;
    return;
loc_15ff8: // 1040:5bf8
    bx++;
    cx = memoryAGet16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    if (cl == memoryAGet(ds, bx))
        goto loc_1601c;
    if (cl < memoryAGet(ds, bx))
        goto loc_1601c;
    bx += 0x0002;
    al = memoryAGet(ds, bx);
    bx++;
    al &= 0x03;
    if (!al)
        goto loc_15ff1;
loc_16013: // 1040:5c13
    bx += 0x0004;
    al--;
    if (al)
        goto loc_16013;
    goto loc_15ff1;
loc_1601c: // 1040:5c1c
    bx--;
    memoryASet16(ds, 0x5b3c, bx);
}
void sub_16022() // 1040:5c22
{
    sub_16126();
    if (!flags.carry)
        goto loc_16028;
    return;
loc_16028: // 1040:5c28
    ax = 0;
    memoryASet16(ds, di + 50, ax);
    memoryASet16(ds, di + 24, ax);
    memoryASet16(ds, di + 34, ax);
    memoryASet16(ds, di + 28, si);
    cx = 0;
    cl = memoryAGet(ds, si);
    cx += cx;
    bx = 0x117e;
    bx += cx;
    bx = memoryAGet16(ds, bx);
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ds, di + 30, ax);
    bx++;
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ds, di + 32, ax);
    bx++;
    al = memoryAGet(ds, bx);
    al &= 0xc0;
    dl = al;
    ax = 0;
    al = memoryAGet(ds, si + 3);
    al &= 0x3c;
    if (al != 0x10)
        goto loc_16072;
    memoryASet16(ds, di + 50, 0x0060);
    if (!(memoryAGet(ds, si + 3) & 0x40))
        goto loc_16072;
    memoryASet16(ds, di + 28, 0x0000);
loc_16072: // 1040:5c72
    al |= 0x01;
    al |= dl;
    memoryASet(ds, di, al);
    al &= 0x3f;
    dl = al;
    ax = 0;
    al = memoryAGet(ds, bx);
    al += al;
    al += al;
    al |= dl;
    memoryASet(ds, di + 44, al);
    bx++;
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    memoryASet16(ds, di + 36, ax);
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    memoryASet16(ds, di + 22, ax);
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    memoryASet16(ds, di + 40, ax);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 42, ax);
    al = memoryAGet(ds, si + 2);
    ax &= 0x001f;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memoryAGet(ds, si + 2) & 0x20))
        goto loc_160ba;
    ax++;
    ax++;
    ax++;
    ax++;
loc_160ba: // 1040:5cba
    memoryASet16(ds, di + 2, ax);
    ax = memoryAGet16(ds, 0x8bf0);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dl = al;
    al = memoryAGet(ds, si + 1);
    al -= dl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memoryAGet(ds, si + 2) & 0x40))
        goto loc_160dc;
    ax++;
    ax++;
    ax++;
loc_160dc: // 1040:5cdc
    memoryASet16(ds, di + 4, ax);
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
    al = memoryAGet(ds, di);
    al &= 0x3f;
    ah = 0x29;
    if (al != 0x21)
        goto loc_160f2;
    memoryASet(ds, di + 10, ah);
    goto loc_16125;
    // gap 1 bytes
loc_160f2: // 1040:5cf2
    ah = 0x27;
    if (al != 0x29)
        goto loc_160fe;
    memoryASet(ds, di + 10, ah);
    goto loc_16125;
    // gap 1 bytes
loc_160fe: // 1040:5cfe
    ah = 0x28;
    if (al != 0x2d)
        goto loc_1610a;
    memoryASet(ds, di + 10, ah);
    goto loc_16125;
    // gap 1 bytes
loc_1610a: // 1040:5d0a
    push(si);
    push(di);
    push(bx);
    si = di;
    ax = memoryAGet16(ds, si + 24);
    push(ax);
    ax = memoryAGet16(ds, si + 22);
    push(ax);
    sub_1718e();
    ax = pop();
    memoryASet16(ds, si + 22, ax);
    ax = pop();
    memoryASet16(ds, si + 24, ax);
    bx = pop();
    di = pop();
    si = pop();
loc_16125: // 1040:5d25
    return;
}
void sub_16126() // 1040:5d26 +returnCarry
{
    di = 0x0c28;
loc_16129: // 1040:5d29
    ax = memoryAGet16(ds, di);
    if ((char)ah < 0)
        goto loc_16138;
    if (!(al & 0x01))
        goto loc_1613a;
    di += 0x0034;
    goto loc_16129;
loc_16138: // 1040:5d38
    flags.carry = 1;
    return;
loc_1613a: // 1040:5d3a
    flags.carry = 0;
}
void sub_1613c() // 1040:5d3c +returnCarry
{
    push(cx);
    cx = memoryAGet16(ds, si + 2);
    if ((short)cx < (short)0x0000)
        goto loc_1615c;
    if ((short)cx > (short)0x00e8)
        goto loc_1615c;
    cx = memoryAGet16(ds, si + 4);
    if ((short)cx < (short)0x0000)
        goto loc_1615c;
    if ((short)cx >= (short)0x0128)
        goto loc_1615c;
    cx = pop();
    flags.carry = 0;
    return;
loc_1615c: // 1040:5d5c
    cx = pop();
    flags.carry = 1;
}
void sub_1615f() // 1040:5d5f
{
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_16173;
    bx = memoryAGet16(ds, si + 28);
    if (!bx)
        goto loc_1616f;
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
loc_1616f: // 1040:5d6f
    memoryASet16(ds, si, 0x0000);
loc_16173: // 1040:5d73
    return;
}
void sub_16174() // 1040:5d74
{
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_1618e;
    bx = memoryAGet16(ds, si + 28);
    if (!bx)
        goto loc_1618a;
    if (memoryAGet(ds, bx + 3) & 0x40)
        goto loc_1618a;
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
loc_1618a: // 1040:5d8a
    memoryASet16(ds, si, 0x0000);
loc_1618e: // 1040:5d8e
    return;
}
void sub_1618f() // 1040:5d8f
{
    push(si);
    si = 0x0b56;
loc_16193: // 1040:5d93
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_161ad;
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_161a8;
    bx = memoryAGet16(ds, si + 28);
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
    memoryASet16(ds, si, 0x0000);
loc_161a8: // 1040:5da8
    si += 0x0034;
    goto loc_16193;
loc_161ad: // 1040:5dad
    si = 0x0c28;
loc_161b0: // 1040:5db0
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_161ca;
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_161c5;
    bx = memoryAGet16(ds, si + 28);
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
    memoryASet16(ds, si, 0x0000);
loc_161c5: // 1040:5dc5
    si += 0x0034;
    goto loc_161b0;
loc_161ca: // 1040:5dca
    si = pop();
}
void sub_16205() // 1040:5e05
{
    goto loc_16205;
loc_161ce: // 1040:5dce
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
    memoryASet16(ds, 0x5dcc, 0x0001);
    memoryASet16(ds, 0x65e1, 0x0018);
    si = 0x661d;
    di = 0x6624;
    cx = 0x0006;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0x0013;
    sub_1aecd();
    return;
loc_161ef: // 1040:5def
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
    memoryASet16(ds, 0x5dcc, 0x0000);
    si = 0x6624;
    sub_16bc7();
    ax = 0x0001;
    sub_1aecd();
    return;
loc_16205: // 1040:5e05
    ah = 0;
    al = memoryAGet(ds, si);
    if (ax == 0x0078)
        goto loc_161ce;
    if (ax == 0x007c)
        goto loc_161ef;
    if ((short)ax >= (short)0x0075)
        goto loc_1621c;
    sub_16022();
    return;
loc_1621c: // 1040:5e1c
    sub_1691d();
}
void sub_16222() // 1040:5e22 +returnCarry
{
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    al = memoryAGet(ds, si + 3);
    flags.carry = 0;
    al &= 0x03;
    if (al)
        goto loc_1623e;
    return;
loc_1623e: // 1040:5e3e
    si += 0x0004;
    push(memoryAGet16(ds, 0x54f8));
    push(ax);
    memoryASet16(ds, 0x54f8, pop());
    ax = pop();
    al = memoryAGet(ds, si + 2);
    cl = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al &= 0x0f;
    al++;
    ah = al;
    dx = memoryAGet16(ds, 0x8bf0);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    al = memoryAGet(ds, si + 1);
    al -= dl;
    if ((char)al >= 0)
        goto loc_1627d;
    al += ah;
    if ((char)al >= 0)
        goto loc_16277;
loc_16273: // 1040:5e73
    flags.carry = 0;
    goto loc_163f5;
loc_16277: // 1040:5e77
    if (!al)
        goto loc_16273;
    ah = al;
    al = 0;
loc_1627d: // 1040:5e7d
    if (al >= 0x20)
        goto loc_16273;
    bx = 0;
    bl = al;
    bx += bx;
    bx += bx;
    bx += bx;
    ah += ah;
    ah += ah;
    ah += ah;
    cl &= 0x0f;
    cl++;
    cl += cl;
    cl += cl;
    cl += cl;
    dl = cl;
    dh = memoryAGet(ds, si);
    push(si);
    al = memoryAGet(ds, si + 3);
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_162cd;
    push(bx);
    cl = al;
    push(cx);
    si = 0x0b1c;
    sub_16407();
    cx = pop();
    al = cl;
    bx = pop();
    if (!flags.carry)
        goto loc_162cd;
loc_162b8: // 1040:5eb8
    si = pop();
    al = memoryAGet(ds, si + 3);
    flags.carry = 0 /*ggg1*/;
    if ((char)al >= 0)
        goto loc_162c3;
    goto loc_163f5;
loc_162c3: // 1040:5ec3
    al &= 0x40;
    if (al)
        goto loc_162cb;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0x80);
loc_162cb: // 1040:5ecb
    flags.carry = 1;
    return;
loc_162cd: // 1040:5ecd
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_162ec;
    cl = al;
    if (memoryAGet16(ds, 0x0b00) != 0x0001)
        goto loc_162ea;
    push(cx);
    push(bx);
    sub_164a0();
    bx = pop();
    cx = pop();
    if (!flags.carry)
        goto loc_162ea;
    memoryASet(ds, 0x5e20, 0xff);
    goto loc_162b8;
loc_162ea: // 1040:5eea
    al = cl;
loc_162ec: // 1040:5eec
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_1630f;
    cl = al;
    if (memoryAGet16(ds, 0x0b38) != 0x0002)
        goto loc_1630d;
    al = memoryAGet(ds, 0x0b4a);
    if ((char)al <= (char)0x01)
        goto loc_1630d;
    if ((char)al > (char)0x04)
        goto loc_1630d;
    push(cx);
    push(bx);
    sub_164e1();
    bx = pop();
    cx = pop();
    if (flags.carry)
        goto loc_162b8;
loc_1630d: // 1040:5f0d
    al = cl;
loc_1630f: // 1040:5f0f
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_1632f;
    cl = al;
    if (memoryAGet16(ds, 0x7ecc) != 0x0001)
        goto loc_1632d;
    push(cx);
    push(bx);
    sub_1646e();
    bx = pop();
    cx = pop();
    if (!flags.carry)
        goto loc_1632d;
    ax = 0x0014;
    sub_1aecd();
    goto loc_162b8;
loc_1632d: // 1040:5f2d
    al = cl;
loc_1632f: // 1040:5f2f
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_16389;
    cl = al;
    push(si);
    si = 0x0b56;
loc_16339: // 1040:5f39
    bp = memoryAGet16(cs, si);
    if (bp == 0xffff)
        goto loc_1637d;
    if (!(bp & 0x0001))
        goto loc_16378;
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    push(cx);
    push(bx);
    sub_16519();
    bx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    if (flags.carry)
        goto loc_16382;
loc_16378: // 1040:5f78
    si += 0x0034;
    goto loc_16339;
loc_1637d: // 1040:5f7d
    si = pop();
    flags.carry = 0;
    goto loc_16387;
    // gap 1 bytes
loc_16382: // 1040:5f82
    si = pop();
    flags.carry = 1;
    goto loc_162b8;
loc_16387: // 1040:5f87
    al = cl;
loc_16389: // 1040:5f89
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_163f0;
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    bx = 0x0c28;
loc_163a4: // 1040:5fa4
    al = memoryAGet(ds, bx + 1);
    if ((char)al < 0)
        goto loc_163f0;
    al = memoryAGet(ds, bx);
    if (!al)
        goto loc_163eb;
    if (bx == dx)
        goto loc_163eb;
    si = bx;
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    push(cx);
    push(bx);
    sub_16555();
    bx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x54f4));
    push(dx);
    memoryASet16(ds, 0x54f4, pop());
    dx = pop();
    push(memoryAGet16(ds, 0x54f6));
    push(bx);
    memoryASet16(ds, 0x54f6, pop());
    bx = pop();
    if (!flags.carry)
        goto loc_163eb;
    goto loc_162b8;
loc_163eb: // 1040:5feb
    bx += 0x0034;
    goto loc_163a4;
loc_163f0: // 1040:5ff0
    si = pop();
    flags.carry = 0;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x7f);
loc_163f5: // 1040:5ff5
    push(memoryAGet16(ds, 0x54f8));
    push(ax);
    memoryASet16(ds, 0x54f8, pop());
    ax = pop();
    al--;
    if (!al)
        goto loc_16406;
    goto loc_1623e;
loc_16406: // 1040:6006
    return;
}
void sub_16407() // 1040:6007 +returnCarry
{
    if (memoryAGet16(ds, 0x7e16) != 0x0001)
        goto loc_16410;
    flags.carry = 0;
    return;
loc_16410: // 1040:6010
    bp = memoryAGet16(ds, 0x0b1e);
    bp += 0x0014;
    cx = 0;
    cl = dh;
    if ((short)cx >= (short)bp)
        goto loc_1646c;
    bp -= 0x0010;
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx <= (short)bp)
        goto loc_1646c;
    bp = memoryAGet16(ds, 0x0b20);
    cx = bx;
    if (memoryAGet16(ds, 0x7e04) == 0x0001)
        goto loc_16454;
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_1646c;
    bp -= 0x0015;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1646c;
    goto loc_1646a;
    // gap 1 bytes
loc_16454: // 1040:6054
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_1646c;
    bp -= 0x0010;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1646c;
loc_1646a: // 1040:606a
    flags.carry = 1;
    return;
loc_1646c: // 1040:606c
    flags.carry = 0;
}
void sub_1646e() // 1040:606e +returnCarry
{
    bp = memoryAGet16(ds, 0x7ece);
    cx = 0;
    cl = dh;
    if ((short)cx > (short)bp)
        goto loc_1649e;
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx < (short)bp)
        goto loc_1649e;
    bp = memoryAGet16(ds, 0x7ed0);
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_1649e;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx < (short)bp)
        goto loc_1649e;
    flags.carry = 1;
    return;
loc_1649e: // 1040:609e
    flags.carry = 0;
}
void sub_164a0() // 1040:60a0 +returnCarry
{
    if (memoryAGet16(ds, 0x0b00) != 0x0001)
        goto loc_164df;
    bp = memoryAGet16(cs, 0x0b02);
    bp += 0x0008;
    cx = 0;
    cl = dh;
    if ((short)cx > (short)bp)
        goto loc_164df;
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx < (short)bp)
        goto loc_164df;
    bp = memoryAGet16(cs, 0x0b04);
    bp += 0x0004;
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_164df;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx < (short)bp)
        goto loc_164df;
    flags.carry = 1;
    return;
loc_164df: // 1040:60df
    flags.carry = 0;
}
void sub_164e1() // 1040:60e1 +returnCarry
{
    bp = memoryAGet16(ds, 0x0b3a);
    bp += 0x000c;
    cx = 0;
    cl = dh;
    if ((short)cx > (short)bp)
        goto loc_16517;
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx < (short)bp)
        goto loc_16517;
    bp = memoryAGet16(ds, 0x0b3c);
    bp += 0x000a;
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_16517;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx < (short)bp)
        goto loc_16517;
    flags.carry = 1;
    return;
loc_16517: // 1040:6117
    flags.carry = 0;
}
void sub_16519() // 1040:6119 +returnCarry
{
    bp = memoryAGet16(ds, si + 2);
    bp += 0x0014;
    cx = 0;
    cl = dh;
    if ((short)cx >= (short)bp)
        goto loc_16553;
    bp -= 0x0010;
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx <= (short)bp)
        goto loc_16553;
    bp = memoryAGet16(ds, si + 4);
    cx = bx;
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_16553;
    bp -= 0x0015;
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx <= (short)bp)
        goto loc_16553;
    flags.carry = 1;
    return;
loc_16553: // 1040:6153
    flags.carry = 0;
}
void sub_16555() // 1040:6155 +returnCarry
{
    bp = memoryAGet16(ds, si + 2);
    bp += memoryAGet16(ds, si + 30);
    cx = 0;
    cl = dh;
    if ((short)cx >= (short)bp)
        goto loc_1658f;
    bp -= memoryAGet16(ds, si + 30);
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx <= (short)bp)
        goto loc_1658f;
    bp = memoryAGet16(ds, si + 4);
    cx = bx;
    bp += memoryAGet16(ds, si + 32);
    if ((short)cx >= (short)bp)
        goto loc_1658f;
    bp -= memoryAGet16(ds, si + 32);
    tl = ah; ah = al; al = tl;
    ah = 0;
    cx += ax;
    tl = ah; ah = al; al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1658f;
    flags.carry = 1;
    return;
loc_1658f: // 1040:618f
    flags.carry = 0;
}
void sub_16591() // 1040:6191
{
    goto loc_16591;
loc_1615f: // 1040:5d5f
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_16173;
    bx = memoryAGet16(ds, si + 28);
    if (!bx)
        goto loc_1616f;
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
loc_1616f: // 1040:5d6f
    memoryASet16(ds, si, 0x0000);
loc_16173: // 1040:5d73
    return;
loc_16174: // 1040:5d74
    if (!(memoryAGet16(ds, si) & 0x0001))
        goto loc_1618e;
    bx = memoryAGet16(ds, si + 28);
    if (!bx)
        goto loc_1618a;
    if (memoryAGet(ds, bx + 3) & 0x40)
        goto loc_1618a;
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
loc_1618a: // 1040:5d8a
    memoryASet16(ds, si, 0x0000);
loc_1618e: // 1040:5d8e
    return;
    // gap 1026 bytes
loc_16591: // 1040:6191
    al = memoryAGet(ds, si);
    al &= 0x3f;
    ah = 0x29;
    if (al != 0x21)
        goto loc_1659e;
    goto loc_167d9;
loc_1659e: // 1040:619e
    ah = 0x27;
    if (al != 0x29)
        goto loc_165a7;
    goto loc_167d9;
loc_165a7: // 1040:61a7
    ah = 0x28;
    if (al != 0x2d)
        goto loc_165b0;
    goto loc_167d9;
loc_165b0: // 1040:61b0
    if (!(al & 0x02))
        goto loc_165b7;
    goto loc_16748;
loc_165b7: // 1040:61b7
    bx = memoryAGet16(ds, si + 36);
loc_165ba: // 1040:61ba
    al = memoryAGet(ds, bx);
    if (al == 0x00)
        goto loc_165cf;
    if (al != 0xff)
        goto loc_16604;
    ax = memoryAGet16(ds, bx + 1);
    sub_1aecd();
    bx += 0x0003;
    goto loc_165ba;
loc_165cf: // 1040:61cf
    bx++;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 36, bx);
    al = memoryAGet(ds, si + 50);
    if (!(al & 0x20))
        goto loc_165df;
    goto loc_16174;
loc_165df: // 1040:61df
    if (!(al & 0x10))
        goto loc_165ba;
    if (!(al & 0x08))
        goto loc_165ee;
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) & 0xf7);
    goto loc_165f2;
    // gap 1 bytes
loc_165ee: // 1040:61ee
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) & 0xef);
loc_165f2: // 1040:61f2
    al = memoryAGet(ds, si);
    al &= 0x1c;
    if (al == 0x14)
        goto loc_165fd;
    goto loc_1679d;
loc_165fd: // 1040:61fd
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) | 0x20);
    goto loc_1679d;
loc_16604: // 1040:6204
    bx++;
    al = memoryAGet(ds, bx);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    if (al != 0x07)
        goto loc_16615;
    al++;
loc_16615: // 1040:6215
    cbw();
    memoryASet16(ds, si + 46, ax);
    if ((short)ax >= 0)
        goto loc_16625;
    flags.carry = (ax + memoryAGet16(ds, si + 2)) >= 0x10000;
    ax += memoryAGet16(ds, si + 2);
    if (flags.carry)
        goto loc_1662a;
    goto loc_1662a;
    // gap 1 bytes
loc_16625: // 1040:6225
    flags.carry = (ax + memoryAGet16(ds, si + 2)) >= 0x10000;
    ax += memoryAGet16(ds, si + 2);
    if (!flags.carry)
        goto loc_1662a;
loc_1662a: // 1040:622a
    memoryASet16(ds, si + 2, ax);
    dh = 0;
    al = memoryAGet(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_1663b;
    dh--;
    al |= 0xf0;
loc_1663b: // 1040:623b
    if (al != 0x07)
        goto loc_16641;
    al++;
loc_16641: // 1040:6241
    dl = al;
    cbw();
    memoryASet16(ds, si + 48, ax);
    cx = bx;
    bx = memoryAGet16(ds, si + 4);
    bx += dx;
    memoryASet16(ds, si + 4, bx);
    sub_1613c();
    if (!flags.carry)
        goto loc_16659;
    goto loc_1615f;
loc_16659: // 1040:6259
    bx = cx;
    bx--;
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ds, si + 34, memoryAGet16(ds, si + 34) + 1);
    if (ax == memoryAGet16(ds, si + 34))
        goto loc_16669;
    if (ax >= memoryAGet16(ds, si + 34))
        goto loc_16673;
loc_16669: // 1040:6269
    memoryASet16(ds, si + 34, 0x0000);
    bx++;
    bx++;
    memoryASet16(ds, si + 36, bx);
loc_16673: // 1040:6273
    sub_1718e();
    if (!(memoryAGet16(ds, si) & 0x0080))
        goto loc_166bd;
    if (memoryAGet16(ds, si) & 0x0040)
        goto loc_16685;
    goto loc_16748;
loc_16685: // 1040:6285
    if (memoryAGet16(ds, 0x0b38) != 0x0001)
        goto loc_166bd;
    bx = memoryAGet16(ds, 0x0b3c);
    dh = memoryAGet(ds, 0x0b3a);
    dh += 0x08;
    dl = 0x08;
    ah = 0x10;
    sub_16555();
    if (!flags.carry)
        goto loc_166bd;
    memoryASet16(ds, 0x0b38, 0x0002);
    memoryASet16(ds, 0x0b50, 0x0000);
    memoryASet16(ds, 0x0b4e, 0x7eb2);
    memoryASet16(ds, 0x0b3c, memoryAGet16(ds, 0x0b3c) - 0x0005);
    memoryASet16(ds, 0x0b4a, 0x0000);
loc_166bd: // 1040:62bd
    if (memoryAGet16(ds, si) & 0x0040)
        goto loc_166c6;
    goto loc_16748;
loc_166c6: // 1040:62c6
    if (memoryAGet16(ds, si + 10) == 0x00fe)
        goto loc_16748;
    di = 0x0b56;
loc_166d3: // 1040:62d3
    ax = memoryAGet16(ds, di);
    if (ax == 0xffff)
        goto loc_16717;
    if (!(al & 0x01))
        goto loc_16712;
    if (memoryAGet16(ds, di + 22) == 0x0001)
        goto loc_16712;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    push(si);
    push(di);
    si = di;
    sub_16519();
    if (!flags.carry)
        goto loc_16710;
    push(si);
    si = 0x6711;
    sub_16bc7();
    si = pop();
    sub_17674();
loc_16710: // 1040:6310
    di = pop();
    si = pop();
loc_16712: // 1040:6312
    di += 0x0034;
    goto loc_166d3;
loc_16717: // 1040:6317
    if (memoryAGet16(ds, 0x7e16) == 0x0001)
        goto loc_16748;
    if (!(memoryAGet(ds, si) & 0x40))
        goto loc_16748;
    ax = memoryAGet16(ds, si + 10);
    if (ax == 0x00fe)
        goto loc_16748;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    sub_16407();
    if (!flags.carry)
        goto loc_16748;
    goto loc_168a8;
loc_16748: // 1040:6348
    al = memoryAGet(ds, si + 50);
    if (!(al & 0x40))
        goto loc_16750;
    return;
loc_16750: // 1040:6350
    if (!(memoryAGet(ds, si + 50) & 0x10))
        goto loc_1675c;
    if (!(memoryAGet(ds, si) & 0x20))
        goto loc_1675c;
    return;
loc_1675c: // 1040:635c
    push(si);
    dx = si;
    si = memoryAGet16(ds, si + 28);
    sub_16222();
    si = pop();
    if (flags.carry)
        goto loc_16774;
    al = memoryAGet(ds, si);
    al &= 0x1c;
    if (al == 0x1c)
        goto loc_16771;
    return;
loc_16771: // 1040:6371
    goto loc_16174;
loc_16774: // 1040:6374
    al = memoryAGet(ds, si);
    al &= 0x1c;
    if (al)
        goto loc_16781;
    al = memoryAGet(ds, si);
    al ^= 0x02;
    memoryASet(ds, si, al);
    return;
loc_16781: // 1040:6381
    if (al != 0x1c)
        goto loc_16786;
    return;
loc_16786: // 1040:6386
    if (al != 0x0c)
        goto loc_1678d;
    goto loc_16174;
loc_1678d: // 1040:638d
    if (!(al & 0x08))
        goto loc_167ca;
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) | 0x40);
    if (!(al & 0x10))
        goto loc_1679d;
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) | 0x20);
loc_1679d: // 1040:639d
    bx = memoryAGet16(ds, si + 40);
    cx = memoryAGet16(ds, si + 36);
    memoryASet16(ds, si + 40, cx);
    memoryASet16(ds, si + 36, bx);
    bx = memoryAGet16(ds, si + 22);
    cx = memoryAGet16(ds, si + 42);
    memoryASet16(ds, si + 22, cx);
    memoryASet16(ds, si + 42, bx);
    memoryASet16(ds, si + 24, 0x0000);
    memoryASet16(ds, si + 18, 0x0000);
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, si + 44);
    memoryASet(ds, si, ah);
    memoryASet(ds, si + 44, al);
    return;
loc_167ca: // 1040:63ca
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) | 0x10);
    if (memoryAGet(ds, si) & 0x20)
        goto loc_167d4;
    return;
loc_167d4: // 1040:63d4
    memoryASet(ds, si + 50, memoryAGet(ds, si + 50) | 0x08);
    return;
loc_167d9: // 1040:63d9
    memoryASet(ds, si, al);
    memoryASet(ds, si + 10, ah);
    memoryASet(ds, si + 11, 0x00);
    memoryASet16(ds, si + 30, 0x0018);
    memoryASet16(ds, si + 32, 0x0015);
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    sub_16407();
    if (!flags.carry)
        goto loc_16803;
    sub_1686f();
    sub_16174();
loc_16803: // 1040:6403
    if (memoryAGet16(ds, 0x0b38) != 0x0002)
        goto loc_1683f;
    al = memoryAGet(ds, 0x0b4a);
    if ((char)al <= (char)0x01)
        goto loc_1683f;
    if ((char)al > (char)0x04)
        goto loc_1683f;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    if (dh >= 0x0f)
        goto loc_1682b;
    dh = 0;
    goto loc_1682e;
    // gap 1 bytes
loc_1682b: // 1040:642b
    dh -= 0x10;
loc_1682e: // 1040:642e
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    sub_164e1();
    if (!flags.carry)
        goto loc_1683f;
    sub_16174();
loc_1683f: // 1040:643f
    if (memoryAGet16(ds, 0x0b00) != 0x0001)
        goto loc_16866;
    al = memoryAGet(ds, si);
    if (al == 0x21)
        goto loc_16866;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    sub_164a0();
    if (!flags.carry)
        goto loc_16866;
    sub_16174();
    memoryASet16(ds, 0x0b00, 0x0000);
loc_16866: // 1040:6466
    sub_1613c();
    if (!flags.carry)
        goto loc_1686e;
    sub_1615f();
loc_1686e: // 1040:646e
    return;
    // gap 57 bytes
loc_168a8: // 1040:64a8
    ax = 0x000b;
    sub_1aecd();
    memoryASet16(ds, 0x7e16, 0x0001);
    memoryASet16(ds, 0x0b24, 0xfb00);
    ax = memoryAGet16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memoryASet16(ds, 0x7e1c, 0xfffe);
    goto loc_168d1;
    // gap 1 bytes
loc_168cb: // 1040:64cb
    memoryASet16(ds, 0x7e1c, 0x0002);
loc_168d1: // 1040:64d1
    ax = memoryAGet16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memoryASet16(ds, 0x6614, memoryAGet16(ds, 0x6614) - 1);
loc_168e3: // 1040:64e3
    return;
}
void sub_1686f() // 1040:646f
{
    al = memoryAGet(ds, si);
    if (al != 0x21)
        goto loc_16884;
    push(si);
    si = 0x6717;
    sub_16bc7();
    si = pop();
    ax = 0x0012;
    sub_1aecd();
    return;
loc_16884: // 1040:6484
    if (al == 0x29)
        goto loc_16898;
    memoryASet16(ds, 0x6612, 0x0006);
    sub_16c3d();
    ax = 0x0011;
    sub_1aecd();
    return;
loc_16898: // 1040:6498
    memoryASet16(ds, 0x6610, 0x0006);
    sub_16c27();
    ax = 0x0011;
    sub_1aecd();
}
void sub_168a8() // 1040:64a8
{
    ax = 0x000b;
    sub_1aecd();
    memoryASet16(ds, 0x7e16, 0x0001);
    memoryASet16(ds, 0x0b24, 0xfb00);
    ax = memoryAGet16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memoryASet16(ds, 0x7e1c, 0xfffe);
    goto loc_168d1;
    // gap 1 bytes
loc_168cb: // 1040:64cb
    memoryASet16(ds, 0x7e1c, 0x0002);
loc_168d1: // 1040:64d1
    ax = memoryAGet16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memoryASet16(ds, 0x6614, memoryAGet16(ds, 0x6614) - 1);
loc_168e3: // 1040:64e3
    return;
}
void sub_168e4() // 1040:64e4
{
    if (memoryAGet16(ds, 0x762d) != 0x0001)
        goto loc_168ef;
    sub_17a8b();
    return;
loc_168ef: // 1040:64ef
    si = 0x0c28;
loc_168f2: // 1040:64f2
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_16906;
    if (!(al & 0x01))
        goto loc_16901;
    push(si);
    sub_16591();
    si = pop();
loc_16901: // 1040:6501
    si += 0x0034;
    goto loc_168f2;
loc_16906: // 1040:6506
    return;
}
void sub_16907() // 1040:6507 +returnCarry
{
    di = 0x0b56;
loc_1690a: // 1040:650a
    ax = memoryAGet16(ds, di);
    if ((char)ah < 0)
        goto loc_16919;
    if (!(al & 0x01))
        goto loc_1691b;
    di += 0x0034;
    goto loc_1690a;
loc_16919: // 1040:6519
    flags.carry = 1;
    return;
loc_1691b: // 1040:651b
    flags.carry = 0;
}
void sub_1691d() // 1040:651d
{
    sub_16907();
    if (!flags.carry)
        goto loc_16923;
    return;
loc_16923: // 1040:6523
    memoryASet16(ds, di + 22, 0x0000);
    memoryASet16(ds, di + 24, 0x0000);
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
    al = memoryAGet(ds, si);
    al &= 0x03;
    memoryASet(ds, di + 49, 0x00);
    memoryASet(ds, di + 48, al);
    memoryASet16(ds, di + 28, si);
    memoryASet16(ds, di, memoryAGet16(ds, di) | 0x0001);
    al = memoryAGet(ds, si);
    if (!(al & 0x04))
        goto loc_16954;
    memoryASet16(ds, di + 10, 0x002a);
    memoryASet16(ds, di + 50, 0x002a);
    goto loc_1695e;
    // gap 1 bytes
loc_16954: // 1040:6554
    memoryASet16(ds, di + 10, 0x0034);
    memoryASet16(ds, di + 50, 0x0034);
loc_1695e: // 1040:655e
    al = memoryAGet(ds, si + 2);
    ax &= 0x001f;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, di + 2, ax);
    ax = memoryAGet16(ds, 0x8bf0);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dl = al;
    al = memoryAGet(ds, si + 1);
    al -= dl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memoryAGet(ds, si + 2) & 0x40))
        goto loc_1698c;
    ax++;
    ax++;
    ax++;
loc_1698c: // 1040:658c
    memoryASet16(ds, di + 4, ax);
    memoryASet16(ds, di + 30, 0x0010);
    memoryASet16(ds, di + 32, 0x0015);
    ax = memoryAGet16(ds, di + 48);
    if (ax != 0x0001)
        goto loc_169b3;
    al = memoryAGet(ds, si + 3);
    al &= 0x3c;
    ax <<= 1;
    ax += 0x0008;
    memoryASet16(ds, di + 18, ax);
    ax = 0;
    memoryASet16(ds, di + 20, ax);
loc_169b3: // 1040:65b3
    memoryASet16(ds, di + 8, 0x0100);
    memoryASet(ds, di + 6, 0x00);
    memoryASet16(ds, di + 16, 0x0000);
    ax = 0x0000;
    memoryASet16(ds, di + 34, ax);
    memoryASet16(ds, di + 36, ax);
    memoryASet16(ds, di + 38, ax);
    memoryASet16(ds, di + 40, ax);
    memoryASet16(ds, di + 42, ax);
    memoryASet16(ds, di + 44, ax);
    memoryASet16(ds, di + 26, 0x0000);
    memoryASet16(ds, di + 16, 0x0002);
}
void sub_169e3() // 1040:65e3
{
    if (memoryAGet16(ds, 0x5dcc) == 0x0000)
        goto loc_16a0e;
    ax = memoryAGet16(ds, 0x65e1);
    ax++;
    if (ax != 0x0019)
        goto loc_16a0b;
    si = 0x6624;
    cx = 0x0006;
    al = 0x00;
loc_169fb: // 1040:65fb
    if (al != memoryAGet(ds, si))
        goto loc_16a03;
    si++;
    if (--cx)
        goto loc_169fb;
    return;
loc_16a03: // 1040:6603
    si = 0x662b;
    sub_16bf7();
    ax = 0;
loc_16a0b: // 1040:660b
    memoryASet16(ds, 0x65e1, ax);
loc_16a0e: // 1040:660e
    return;
}
void sub_16b3b() // 1040:673b
{
    push(ds);
    push(es);
    push(bx);
    sub_16c53();
    sub_16c27();
    sub_16c3d();
    ax = 0x0004;
    si = 0x6616;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:674d;
    ax = 0x000d;
    si = 0x66f6;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6757;
    ax = 0x0015;
    si = 0x66fd;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6761;
    ax = 0x001e;
    si = 0x6704;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:676b;
    ax = 0x0004;
    si = 0x6616;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:6775;
    ax = 0x000d;
    si = 0x66f6;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:677f;
    ax = 0x0015;
    si = 0x66fd;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:6789;
    ax = 0x001e;
    si = 0x6704;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:6793;
    bx = pop();
    es = pop();
    ds = pop();
}
void sub_16b9b() // 1040:679b
{
    sp -= 2;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:679b;
    indirectCall(cs, memoryAGet16(ds, 0x0028)); // 1040:679f;
    memoryASet(ds, 0x97da, 0x01);
    cx = 0x01e0;
loc_16bac: // 1040:67ac
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_16bc4;
    al = memoryAGet(ds, 0xb888);
    al &= 0x30;
    if (al == 0x30)
        goto loc_16bc4;
    cx = pop();
    if (--cx)
        goto loc_16bac;
    sp += 2;
    return;
loc_16bc4: // 1040:67c4
    goto loc_1c3b0;
    // gap 22505 bytes
loc_1c3b0: // 1040:bfb0
    memoryASet16(ds, 0x6614, 0x0006);
    sub_199c8();
    sp = memoryAGet16(ds, 0xc0df);
    memoryASet16(ds, 0x6610, 0x0006);
    memoryASet16(ds, 0x6612, 0x0006);
    memoryASet16(ds, 0x7e00, 0x0000);
    memoryASet16(ds, 0x762d, 0x0000);
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    indirectCall(cs, memoryAGet16(ds, 0x0004)); // 1040:bfe3;
    indirectCall(cs, memoryAGet16(ds, 0x0006)); // 1040:bfe7;
    sub_1a45c();
    sub_1c4e2();
    indirectCall(cs, memoryAGet16(ds, 0x0042)); // 1040:bff1;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bff5;
    indirectCall(cs, memoryAGet16(ds, 0x003c)); // 1040:bff9;
    indirectCall(cs, memoryAGet16(ds, 0x0048)); // 1040:bffd;
    ax = 0x0004;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = memoryAGet16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:c026;
    sub_19420();
    memoryASet16(ds, 0x973c, 0x3245);
    memoryASet16(ds, 0x973e, 0x5432);
loc_1c439: // 1040:c039
    memoryASet16(ds, 0x7e16, 0x0000);
    memoryASet16(ds, 0x7e18, 0x0000);
loc_1c445: // 1040:c045
    sub_16b3b();
    if (memoryAGet16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1618f();
    sub_19462();
    if (memoryAGet16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    sub_19f12();
    return;
loc_1c465: // 1040:c065
    goto loc_1c439;
loc_1c467: // 1040:c067
    sub_19bac();
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    indirectCall(cs, memoryAGet16(ds, 0x001e)); // 1040:c087;
    indirectCall(cs, memoryAGet16(ds, 0x0024)); // 1040:c08b;
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:c08f;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:c093;
    sub_19af6();
    indirectCall(cs, memoryAGet16(ds, 0x0038)); // 1040:c09a;
    sub_194c4();
    if (memoryAGet(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    sub_1c359();
    return;
loc_1c4b3: // 1040:c0b3
    if (memoryAGet(ds, 0xb888) != 0x01)
        goto loc_1c445;
    sub_196f3();
    return;
}
void sub_16bc7() // 1040:67c7
{
    si += 0x0005;
    di = 0x661b;
    bl = 0x00;
    cx = 0x0006;
loc_16bd2: // 1040:67d2
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    ah += al;
    ah += bl;
    tl = ah; ah = al; al = tl;
    ah = 0;
    if ((short)ax < (short)0x000a)
        goto loc_16bee;
    bl = 0x01;
    al -= 0x0a;
    memoryASet(ds, di, al);
    di--;
    si--;
    if (--cx)
        goto loc_16bd2;
    return;
loc_16bee: // 1040:67ee
    bl = 0x00;
    memoryASet(ds, di, al);
    di--;
    si--;
    if (--cx)
        goto loc_16bd2;
}
void sub_16bf7() // 1040:67f7
{
    si += 0x0005;
    di = 0x6629;
    bl = 0x00;
    cx = 0x0006;
loc_16c02: // 1040:6802
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    ah += al;
    ah += bl;
    tl = ah; ah = al; al = tl;
    ah = 0;
    if ((short)ax < (short)0x000a)
        goto loc_16c1e;
    bl = 0x01;
    al -= 0x0a;
    memoryASet(ds, di, al);
    di--;
    si--;
    if (--cx)
        goto loc_16c02;
    return;
loc_16c1e: // 1040:681e
    bl = 0x00;
    memoryASet(ds, di, al);
    di--;
    si--;
    if (--cx)
        goto loc_16c02;
}
void sub_16c27() // 1040:6827
{
    di = 0x66f6;
    cx = 0x0006;
    al = 0x20;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = memoryAGet16(ds, 0x6610);
    di = 0x66f6;
    al = 0x0a;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_16c3d() // 1040:683d
{
    di = 0x66fd;
    cx = 0x0006;
    al = 0x20;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = memoryAGet16(ds, 0x6612);
    di = 0x66fd;
    al = 0x0b;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_16c53() // 1040:6853
{
    di = 0x6704;
    cx = 0x0006;
    al = 0x20;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = memoryAGet16(ds, 0x6614);
    di = 0x6704;
    al = 0x0c;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_16c69() // 1040:6869 +returnCarry
{
    cx = 0x0008;
    di = 0x6632;
    bx = 0x668d;
loc_16c72: // 1040:6872
    si = 0x6616;
    sub_16cb8();
    if (flags.carry)
        goto loc_16c84;
    bx += 0x000b;
    di += 0x0007;
    if (--cx)
        goto loc_16c72;
    flags.carry = 0;
    return;
loc_16c84: // 1040:6884
    si = 0x6663;
loc_16c87: // 1040:6887
    if (si == di)
        goto loc_16c94;
    al = memoryAGet(ds, si + 65535);
    memoryASet(ds, si + 6, al);
    si--;
    goto loc_16c87;
loc_16c94: // 1040:6894
    cx = 0x0007;
    si = 0x6616;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    flags.carry = 1;
}
void sub_16cb8() // 1040:68b8 +returnCarry
{
    push(cx);
    push(di);
    cx = 0x0006;
loc_16cbd: // 1040:68bd
    al = memoryAGet(ds, si);
    si++;
    ah = memoryAGet(ds, di);
    di++;
    if ((char)al < (char)ah)
        goto loc_16ccf;
    if ((char)al > (char)ah)
        goto loc_16cd3;
    if (--cx)
        goto loc_16cbd;
    di = pop();
    cx = pop();
    flags.carry = 1;
    return;
loc_16ccf: // 1040:68cf
    di = pop();
    cx = pop();
    flags.carry = 0;
    return;
loc_16cd3: // 1040:68d3
    di = pop();
    cx = pop();
    flags.carry = 1;
}
void sub_16cd7() // 1040:68d7
{
    sp -= 2;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:68d7;
    ax = 0x0008;
    si = 0x9401;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:68e1;
    ax = 0x0108;
    si = 0x9421;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:68eb;
    ax = 0x0208;
    si = 0x9441;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:68f5;
    si = 0x668d;
    ax = 0x0617;
    cx = 0x0008;
loc_16d02: // 1040:6902
    push(si);
    push(ax);
    push(cx);
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6905;
    cx = pop();
    ax = pop();
    si = pop();
    si += 0x000b;
    ah++;
    ah++;
    if (--cx)
        goto loc_16d02;
    si = 0x6632;
    ax = 0x0607;
    cx = 0x0008;
loc_16d1e: // 1040:691e
    push(si);
    push(ax);
    push(cx);
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6921;
    cx = pop();
    ax = pop();
    si = pop();
    si += 0x0007;
    ah++;
    ah++;
    if (--cx)
        goto loc_16d1e;
    si = 0x6682;
    ax = 0x060d;
    cx = 0x0008;
loc_16d3a: // 1040:693a
    push(si);
    push(ax);
    push(cx);
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:693d;
    cx = pop();
    ax = pop();
    si = pop();
    ah++;
    ah++;
    if (--cx)
        goto loc_16d3a;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:694a;
    memoryASet(ds, 0x97da, 0x01);
    cx = 0x01e0;
loc_16d57: // 1040:6957
    sync(); // X Y Z
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_16d66;
    cx = pop();
    if (--cx)
        goto loc_16d57;
    sp += 2;
    return;
loc_16d66: // 1040:6966
    goto loc_1c3b0;
    // gap 22087 bytes
loc_1c3b0: // 1040:bfb0
    memoryASet16(ds, 0x6614, 0x0006);
    sub_199c8();
    sp = memoryAGet16(ds, 0xc0df);
    memoryASet16(ds, 0x6610, 0x0006);
    memoryASet16(ds, 0x6612, 0x0006);
    memoryASet16(ds, 0x7e00, 0x0000);
    memoryASet16(ds, 0x762d, 0x0000);
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    indirectCall(cs, memoryAGet16(ds, 0x0004)); // 1040:bfe3;
    indirectCall(cs, memoryAGet16(ds, 0x0006)); // 1040:bfe7;
    sub_1a45c();
    sub_1c4e2();
    indirectCall(cs, memoryAGet16(ds, 0x0042)); // 1040:bff1;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bff5;
    indirectCall(cs, memoryAGet16(ds, 0x003c)); // 1040:bff9;
    indirectCall(cs, memoryAGet16(ds, 0x0048)); // 1040:bffd;
    ax = 0x0004;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = memoryAGet16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:c026;
    sub_19420();
    memoryASet16(ds, 0x973c, 0x3245);
    memoryASet16(ds, 0x973e, 0x5432);
loc_1c439: // 1040:c039
    memoryASet16(ds, 0x7e16, 0x0000);
    memoryASet16(ds, 0x7e18, 0x0000);
loc_1c445: // 1040:c045
    sub_16b3b();
    if (memoryAGet16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1618f();
    sub_19462();
    if (memoryAGet16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    sub_19f12();
    return;
loc_1c465: // 1040:c065
    goto loc_1c439;
loc_1c467: // 1040:c067
//    sync(); // X
    sub_19bac();
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    indirectCall(cs, memoryAGet16(ds, 0x001e)); // 1040:c087;
    indirectCall(cs, memoryAGet16(ds, 0x0024)); // 1040:c08b;
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:c08f;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:c093;
    sub_19af6();
    indirectCall(cs, memoryAGet16(ds, 0x0038)); // 1040:c09a;
    sub_194c4();
    if (memoryAGet(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    sub_1c359();
    return;
loc_1c4b3: // 1040:c0b3
    if (memoryAGet(ds, 0xb888) != 0x01)
        goto loc_1c445;
    sub_196f3();
    return;
}
void sub_16d69() // 1040:6969
{
    sub_16c69();
    if (!flags.carry)
        goto loc_16d7d;
    push(bx);
    sub_16eb2();
    bx = pop();
    cx = 0x000a;
    si = 0x6671;
    di = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
loc_16d7d: // 1040:697d
    return;
}
void sub_16e16() // 1040:6a16
{
    ax = 0;
    dx = memoryAGet16(ds, 0x69f0);
    al = dh;
    al -= 0x08;
    ax &= 0xfffe;
    bx = ax;
    ax <<= 1;
    bx += ax;
    dh = 0;
    dx -= 0x000e;
    dx >>= 1;
    bx += dx;
    bx += 0x69f8;
    al = memoryAGet(ds, bx);
}
void sub_16e39() // 1040:6a39
{
    ax = memoryAGet16(ds, 0x69f2);
    si = 0x69ee;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a3f;
    ax = memoryAGet16(ds, 0x69f0);
    si = 0x69ec;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a49;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:6a4d;
    ax = memoryAGet16(ds, 0x69f2);
    si = 0x69ee;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a57;
    ax = memoryAGet16(ds, 0x69f0);
    si = 0x69ec;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a61;
}
void sub_16e66() // 1040:6a66
{
    ax = memoryAGet16(ds, 0x69f0);
    memoryASet16(ds, 0x69f2, ax);
    memoryASet16(ds, 0x69f0, dx);
    sub_16e39();
}
void sub_16e74() // 1040:6a74
{
    ax = memoryAGet16(ds, 0x69f6);
    si = 0x69ee;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a7a;
    ax = memoryAGet16(ds, 0x69f4);
    si = 0x69ec;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a84;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:6a88;
    ax = memoryAGet16(ds, 0x69f6);
    si = 0x69ee;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a92;
    ax = memoryAGet16(ds, 0x69f4);
    si = 0x69ec;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6a9c;
}
void sub_16ea1() // 1040:6aa1
{
    ax = memoryAGet16(ds, 0x69f4);
    memoryASet16(ds, 0x69f6, ax);
    memoryASet16(ds, 0x69f4, dx);
    sub_16e74();
}
void sub_16eb2() // 1040:6ab2
{
    ax = 0x090e;
    memoryASet16(ds, 0x69f0, ax);
    memoryASet16(ds, 0x69f2, ax);
    ax = 0x150e;
    memoryASet16(ds, 0x69f4, ax);
    memoryASet16(ds, 0x69f6, ax);
    di = 0x6671;
    cx = 0x000a;
    al = 0x0e;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    memoryASet16(ds, 0x6ab0, 0x6671);
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:6ad4;
    ax = 0x0005;
    si = 0x93a1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6ade;
    ax = 0x0105;
    si = 0x93c1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6ae8;
    ax = 0x0205;
    si = 0x93e1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6af2;
    bx = 0x69de;
    sub_19c43();
    ax = 0x140e;
    si = 0x6671;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6b02;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:6b06;
    ax = 0x0005;
    si = 0x93a1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6b10;
    ax = 0x0105;
    si = 0x93c1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6b1a;
    ax = 0x0205;
    si = 0x93e1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:6b24;
    bx = 0x69de;
    sub_19c43();
    ax = 0x140e;
    si = 0x6671;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6b34;
    sub_16e39();
    sub_16e74();
loc_16f3e: // 1040:6b3e
    ax = 0x140e;
    si = 0x6671;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6b44;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:6b48;
    ax = 0x140e;
    si = 0x6671;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:6b52;
    cx = 0x0006;
loc_16f59: // 1040:6b59
    sub_19b1c();
    if (--cx)
        goto loc_16f59;
    sub_1c4ca();
    if (memoryAGet(ds, 0x6aaf) != 0x01)
        goto loc_16f71;
    if (al & 0x10)
        goto loc_16f71;
    memoryASet(ds, 0x6aaf, 0x00);
loc_16f71: // 1040:6b71
    dx = memoryAGet16(ds, 0x69f0);
    if (!(al & 0x08))
        goto loc_16f7c;
    dh -= 0x02;
loc_16f7c: // 1040:6b7c
    if (!(al & 0x04))
        goto loc_16f83;
    dh += 0x02;
loc_16f83: // 1040:6b83
    if (!(al & 0x01))
        goto loc_16f8a;
    dl += 0x02;
loc_16f8a: // 1040:6b8a
    if (!(al & 0x02))
        goto loc_16f91;
    dl -= 0x02;
loc_16f91: // 1040:6b91
    if (al & 0x10)
        goto loc_16fbc;
    if (dl != 0x0c)
        goto loc_16f9f;
    dl = 0x0e;
    goto loc_16fa6;
    // gap 1 bytes
loc_16f9f: // 1040:6b9f
    if (dl != 0x1a)
        goto loc_16fa6;
    dl = 0x18;
loc_16fa6: // 1040:6ba6
    if (dh != 0x07)
        goto loc_16fb0;
    dh = 0x09;
    goto loc_16fb7;
    // gap 1 bytes
loc_16fb0: // 1040:6bb0
    if (dh != 0x13)
        goto loc_16fb7;
    dh = 0x11;
loc_16fb7: // 1040:6bb7
    sub_16e66();
    goto loc_16f3e;
loc_16fbc: // 1040:6bbc
    if (memoryAGet(ds, 0x6aaf) != 0x01)
        goto loc_16fc6;
    goto loc_16f3e;
loc_16fc6: // 1040:6bc6
    sub_16e16();
    memoryASet(ds, 0x6aaf, 0x01);
    if (al == 0x11)
        goto loc_16fe2;
    if (al != 0x10)
        goto loc_16fdc;
    sub_16ff5();
    goto loc_16f3e;
loc_16fdc: // 1040:6bdc
    sub_17018();
    goto loc_16f3e;
loc_16fe2: // 1040:6be2
    si = 0x6671;
    cx = 0x000a;
loc_16fe8: // 1040:6be8
    al = memoryAGet(ds, si);
    if (al != 0x0e)
        goto loc_16ff1;
    memoryASet(ds, si, 0x20);
loc_16ff1: // 1040:6bf1
    si++;
    if (--cx)
        goto loc_16fe8;
}
void sub_16ff5() // 1040:6bf5
{
    di = memoryAGet16(ds, 0x6ab0);
    di--;
    if (di == 0x6670)
        goto loc_17017;
    memoryASet(ds, di, 0x0e);
    memoryASet16(ds, 0x6ab0, di);
    dx = memoryAGet16(ds, 0x6ab0);
    dx -= 0x6671;
    dh = 0x15;
    dl += 0x0e;
    sub_16ea1();
loc_17017: // 1040:6c17
    return;
}
void sub_17018() // 1040:6c18
{
    di = memoryAGet16(ds, 0x6ab0);
    if (di == 0x667b)
        goto loc_17029;
    memoryASet(ds, di, al);
    di++;
    memoryASet16(ds, 0x6ab0, di);
loc_17029: // 1040:6c29
    dx = memoryAGet16(ds, 0x6ab0);
    dx -= 0x6671;
    dh = 0x15;
    if (dl != 0x0a)
        goto loc_1703a;
    dl = 0x09;
loc_1703a: // 1040:6c3a
    dl += 0x0e;
    push(ax);
    sub_16ea1();
    ax = pop();
}
void sub_17047() // 1040:6c47
{
    memoryASet16(ds, 0x6c43, 0x0000);
    ax = memoryAGet16(ds, 0x8bf0);
    memoryASet16(ds, 0x6c45, ax);
    memoryASet16(ds, 0x6c45, memoryAGet16(ds, 0x6c45) & 0x0007);
    indirectCall(cs, memoryAGet16(ds, 0x0012)); // 1040:6c58;
}
void sub_1705d() // 1040:6c5d
{
    if (memoryAGet16(ds, 0x7e16) != 0x0001)
        goto loc_17065;
    return;
loc_17065: // 1040:6c65
    ax = memoryAGet16(ds, 0x8bf0);
    ax &= 0x0007;
    dx = memoryAGet16(ds, 0x0b20);
    dx -= ax;
    if ((short)dx >= (short)0x009b)
        goto loc_17082;
    bx = memoryAGet16(ds, 0x6c43);
    if ((short)bx < 0)
        goto loc_17099;
    goto loc_1709c;
    // gap 1 bytes
loc_17082: // 1040:6c82
    if ((short)dx < (short)0x0086)
        goto loc_1709c;
    bx = memoryAGet16(ds, 0x6c43);
    if (!bx)
        goto loc_1709c;
    if ((short)bx >= 0)
        goto loc_17095;
    goto loc_1709c;
    // gap 1 bytes
loc_17095: // 1040:6c95
    sub_170e6();
    return;
loc_17099: // 1040:6c99
    sub_1709d();
loc_1709c: // 1040:6c9c
    return;
}
void sub_1709d() // 1040:6c9d
{
    ax = memoryAGet16(ds, 0x8bf0);
    dx = ax;
    ax += memoryAGet16(ds, 0x6c43);
    if ((short)ax >= (short)memoryAGet16(ds, 0x8bf2))
        goto loc_170bb;
    cx = memoryAGet16(ds, 0x8bf2);
    cx -= memoryAGet16(ds, 0x8bf0);
    memoryASet16(ds, 0x6c43, cx);
    ax = memoryAGet16(ds, 0x8bf2);
loc_170bb: // 1040:6cbb
    memoryASet16(ds, 0x8bf0, ax);
    if (dx == ax)
        goto loc_170e1;
    dx &= 0x0007;
    dx += memoryAGet16(ds, 0x6c43);
    if ((short)dx >= 0)
        goto loc_170e2;
    sub_195ea();
    sub_1930a();
    indirectCall(cs, memoryAGet16(ds, 0x0014)); // 1040:6cd1;
    sub_17180();
    dx = 0x0008;
    sub_17132();
    sub_15fe4();
loc_170e1: // 1040:6ce1
    return;
loc_170e2: // 1040:6ce2
    sub_17180();
}
void sub_170e6() // 1040:6ce6
{
    ax = memoryAGet16(ds, 0x8bf0);
    dx = ax;
    ax += memoryAGet16(ds, 0x6c43);
    if ((short)ax <= (short)memoryAGet16(ds, 0x8bf4))
        goto loc_17104;
    cx = memoryAGet16(ds, 0x8bf4);
    cx -= memoryAGet16(ds, 0x8bf0);
    memoryASet16(ds, 0x6c43, cx);
    ax = memoryAGet16(ds, 0x8bf4);
loc_17104: // 1040:6d04
    memoryASet16(ds, 0x8bf0, ax);
    if (dx == ax)
        goto loc_1712d;
    dx &= 0x0007;
    dx += memoryAGet16(ds, 0x6c43);
    if ((short)dx <= (short)0x0007)
        goto loc_1712e;
    sub_1961d();
    sub_192da();
    indirectCall(cs, memoryAGet16(ds, 0x0016)); // 1040:6d1d;
    sub_17180();
    dx = 0xfff8;
    sub_17132();
    sub_15fe4();
loc_1712d: // 1040:6d2d
    return;
loc_1712e: // 1040:6d2e
    sub_17180();
}
void sub_17132() // 1040:6d32
{
    si = 0x0b00;
loc_17135: // 1040:6d35
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_17145;
    if (!ax)
        goto loc_17140;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
loc_17140: // 1040:6d40
    si += 0x001c;
    goto loc_17135;
loc_17145: // 1040:6d45
    si = 0x0c28;
loc_17148: // 1040:6d48
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_17162;
    if (!(al & 0x01))
        goto loc_1715d;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
    sub_1613c();
    if (!flags.carry)
        goto loc_1715d;
    sub_1615f();
loc_1715d: // 1040:6d5d
    si += 0x0034;
    goto loc_17148;
loc_17162: // 1040:6d62
    si = 0x0b56;
loc_17165: // 1040:6d65
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_1717f;
    if (!(al & 0x01))
        goto loc_1717a;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
    sub_1613c();
    if (!flags.carry)
        goto loc_1717a;
    sub_1615f();
loc_1717a: // 1040:6d7a
    si += 0x0034;
    goto loc_17165;
loc_1717f: // 1040:6d7f
    return;
}
void sub_17180() // 1040:6d80
{
    ax = memoryAGet16(ds, 0x6c45);
    ax += memoryAGet16(ds, 0x6c43);
    ax &= 0x00ff;
    memoryASet16(ds, 0x6c45, ax);
}
void sub_1718e() // 1040:6d8e +returnCarry
{
    if (memoryAGet16(ds, si) & 0xffff)
        goto loc_17196;
    flags.carry = 0;
    return;
loc_17196: // 1040:6d96
    if (!(memoryAGet16(ds, si + 24) & 0xffff))
        goto loc_171a2;
    memoryASet16(ds, si + 24, memoryAGet16(ds, si + 24) - 1);
    flags.carry = 0;
    return;
loc_171a2: // 1040:6da2
    push(ax);
    push(bx);
    push(dx);
    dx = 0;
    bx = memoryAGet16(ds, si + 22);
loc_171aa: // 1040:6daa
    ax = memoryAGet16(ds, bx);
    if ((short)ax < 0)
        goto loc_171bb;
    memoryASet16(ds, si + 10, ax);
    bx++;
    bx++;
    memoryASet16(ds, si + 22, bx);
    goto loc_171f5;
    // gap 1 bytes
loc_171bb: // 1040:6dbb
    if (ax != 0xffff)
        goto loc_171cd;
    ax = memoryAGet16(ds, bx + 2);
    bx += ax;
    memoryASet16(ds, si + 22, si);
    dx = 0xffff;
    goto loc_171aa;
loc_171cd: // 1040:6dcd
    if (ax != 0xfffd)
        goto loc_171e0;
    ax = memoryAGet16(ds, bx + 2);
    sub_1aecd();
    bx += 0x0004;
    memoryASet16(ds, si + 22, bx);
    goto loc_171aa;
loc_171e0: // 1040:6de0
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    memoryASet16(ds, si + 24, memoryAGet16(ds, si + 24) - 1);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, si + 10, ax);
    bx += 0x0006;
    memoryASet16(ds, si + 22, bx);
loc_171f5: // 1040:6df5
    if (dx)
        goto loc_171fe;
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = 0;
    return;
loc_171fe: // 1040:6dfe
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = 1;
}
void sub_17205() // 1040:6e05
{
    sub_177fb();
    si = 0x0b56;
loc_1720b: // 1040:6e0b
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_1721f;
    if (!(al & 0x01))
        goto loc_1721a;
    push(si);
    sub_17222();
    si = pop();
loc_1721a: // 1040:6e1a
    si += 0x0034;
    goto loc_1720b;
loc_1721f: // 1040:6e1f
    return;
}
void sub_17222() // 1040:6e22
{
    bool temp_cf;

    goto loc_17222;
loc_168a8: // 1040:64a8
    ax = 0x000b;
    sub_1aecd();
    memoryASet16(ds, 0x7e16, 0x0001);
    memoryASet16(ds, 0x0b24, 0xfb00);
    ax = memoryAGet16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memoryASet16(ds, 0x7e1c, 0xfffe);
    goto loc_168d1;
    // gap 1 bytes
loc_168cb: // 1040:64cb
    memoryASet16(ds, 0x7e1c, 0x0002);
loc_168d1: // 1040:64d1
    ax = memoryAGet16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memoryASet16(ds, 0x6614, memoryAGet16(ds, 0x6614) - 1);
loc_168e3: // 1040:64e3
    return;
    // gap 2366 bytes
loc_17222: // 1040:6e22
    memoryASet16(ds, 0x6e20, 0x0000);
    memoryASet16(ds, 0x6e03, 0x0000);
    if (memoryAGet16(ds, si + 24) == 0x0000)
        goto loc_17246;
    memoryASet16(ds, si + 24, memoryAGet16(ds, si + 24) - 1);
    if (memoryAGet16(ds, si + 22) != 0x0001)
        goto loc_17240;
    goto loc_176a0;
loc_17240: // 1040:6e40
    memoryASet16(ds, 0x6e20, 0x0001);
loc_17246: // 1040:6e46
    memoryASet16(ds, si + 44, 0x0000);
    memoryASet16(ds, si + 46, 0x0000);
    if (memoryAGet16(ds, si + 22) != 0x0001)
        goto loc_17259;
    goto loc_176a0;
loc_17259: // 1040:6e59
    if (memoryAGet16(ds, si + 42) != 0x0001)
        goto loc_17262;
    goto loc_17644;
loc_17262: // 1040:6e62
    memoryASet16(ds, si + 44, 0x0000);
    memoryASet16(ds, si + 46, 0x0000);
    memoryASet16(ds, si + 34, 0x0000);
    memoryASet16(ds, si + 36, 0x0000);
    memoryASet16(ds, si + 38, 0x0000);
    memoryASet16(ds, si + 40, 0x0000);
    memoryASet(ds, 0x796b, 0x01);
    memoryASet16(ds, 0x6e03, 0x0000);
    dx = memoryAGet16(ds, si + 8);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_1729c;
    dx = 0x0800;
loc_1729c: // 1040:6e9c
    memoryASet16(ds, si + 8, dx);
    memoryASet16(ds, 0x7961, dx);
    if ((short)dx < 0)
        goto loc_172ac;
    ch = 0;
    goto loc_172ae;
    // gap 1 bytes
loc_172ac: // 1040:6eac
    ch = 0xff;
loc_172ae: // 1040:6eae
    ax = memoryAGet16(ds, si + 4);
    cl = memoryAGet(ds, si + 6);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    memoryASet16(ds, 0x795f, ax);
    dx = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x795d, dx);
    memoryASet(ds, 0x796b, 0x01);
    sub_17dfb();
loc_172cd: // 1040:6ecd
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_172da;
    goto loc_17674;
loc_172da: // 1040:6eda
    if (!(ch & 0x40))
        goto loc_1733d;
    ax = memoryAGet16(ds, 0x7964);
    cl = 0;
    ax -= 0x0015;
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, si + 6, 0x00);
    memoryASet16(ds, si + 34, 0x0001);
    push(ax);
    ax = memoryAGet16(ds, 0x7966);
    memoryASet16(ds, si + 44, ax);
    ax = pop();
    memoryASet(ds, 0x796b, 0x00);
    sub_17dfb();
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_17315;
    goto loc_17674;
loc_17315: // 1040:6f15
    ch &= 0x06;
    if (!ch)
        goto loc_17321;
    ch = memoryAGet(ds, 0x7963);
    goto loc_1735c;
    // gap 1 bytes
loc_17321: // 1040:6f21
    bp = memoryAGet16(cs, si + 44);
    bp |= memoryAGet16(cs, si + 46);
    if (!bp)
        goto loc_17333;
    memoryASet16(ds, 0x6e03, 0x0001);
loc_17333: // 1040:6f33
    ch = memoryAGet(ds, 0x7963);
    dx = 0x0100;
    goto loc_173e4;
loc_1733d: // 1040:6f3d
    if (!(ch & 0x20))
        goto loc_17346;
    goto loc_17674;
loc_17346: // 1040:6f46
    if (ch & 0x04)
        goto loc_1736d;
    if (ch & 0x02)
        goto loc_17355;
    goto loc_1740e;
loc_17355: // 1040:6f55
    bp = memoryAGet16(ds, si + 8);
    if ((short)bp >= 0)
        goto loc_1736d;
loc_1735c: // 1040:6f5c
    ax |= 0x0007;
    ax++;
    cl = 0;
    memoryASet16(ds, si + 8, 0x0100);
    dx = 0x0100;
    goto loc_1740e;
loc_1736d: // 1040:6f6d
    if (memoryAGet16(ds, si + 48) != 0x0003)
        goto loc_17394;
    if (!(ch & 0x10))
        goto loc_17394;
    sub_176f4();
    if (flags.carry)
        goto loc_17394;
    bx = memoryAGet16(ds, si + 2);
    bx &= 0x001f;
    if (bx != 0x0004)
        goto loc_17394;
    memoryASet16(ds, si + 42, 0x0001);
    goto loc_1740e;
    // gap 1 bytes
loc_17394: // 1040:6f94
    memoryASet16(ds, si + 42, 0x0000);
    memoryASet16(ds, si + 34, 0x0001);
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, si + 6, cl);
    dx = 0x0100;
    if (!(ch & 0x01))
        goto loc_173e4;
    if (memoryAGet16(ds, 0x8bec) != 0x0003)
        goto loc_173e4;
    dx = memoryAGet16(ds, si + 8);
    if ((short)dx < (short)0x0200)
        goto loc_173d8;
    dx = -dx;
    dx += 0x0060;
    memoryASet16(ds, si + 8, dx);
    dx = 0xf781;
    goto loc_1740e;
    // gap 1 bytes
loc_173d8: // 1040:6fd8
    memoryASet16(ds, si + 8, 0x0100);
    dx = 0xfa00;
    goto loc_1740e;
    // gap 1 bytes
loc_173e4: // 1040:6fe4
    memoryASet16(ds, si + 8, dx);
    dx = 0xfa00;
    if (!(ch & 0x01))
        goto loc_1740e;
    if (memoryAGet16(ds, 0x8bec) != 0x0001)
        goto loc_173ff;
    dx = 0xfe00;
    goto loc_1740e;
    // gap 1 bytes
loc_173ff: // 1040:6fff
    if (memoryAGet16(ds, 0x8bec) != 0x0005)
        goto loc_1740e;
    memoryASet16(ds, si + 8, 0xf781);
    goto loc_1743b;
    // gap 1 bytes
loc_1740e: // 1040:700e
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, si + 6, cl);
    if (memoryAGet16(ds, si + 48) != 0x0003)
        goto loc_1743b;
    if (!(ch & 0x08))
        goto loc_1743b;
    if (ch & 0x10)
        goto loc_1743b;
    sub_176f4();
    if (!flags.carry)
        goto loc_1743b;
    bx = memoryAGet16(ds, si + 2);
    bx &= 0x001f;
    if (bx != 0x0004)
        goto loc_1743b;
    memoryASet16(ds, si + 42, 0x0001);
loc_1743b: // 1040:703b
    if (memoryAGet16(ds, 0x6e03) != 0x0001)
        goto loc_1744d;
    dx = memoryAGet16(ds, si + 44);
    bx = memoryAGet16(ds, si + 2);
    bx += dx;
    goto loc_17573;
loc_1744d: // 1040:704d
    bp = memoryAGet16(cs, si + 8);
    if ((short)bp < 0)
        goto loc_1745e;
    if (memoryAGet16(ds, si + 34) == 0x0001)
        goto loc_1745e;
    goto loc_1746a;
    // gap 1 bytes
loc_1745e: // 1040:705e
    if (memoryAGet16(ds, si + 48) != 0x0003)
        goto loc_17473;
    if (memoryAGet16(ds, si + 42) != 0x0001)
        goto loc_17473;
loc_1746a: // 1040:706a
    dx = 0x0000;
    bx = memoryAGet16(ds, si + 2);
    goto loc_17573;
loc_17473: // 1040:7073
    dx = memoryAGet16(ds, si + 16);
    if (!(ch & 0x01))
        goto loc_174a3;
    if (memoryAGet16(ds, 0x8bec) == 0x0002)
        goto loc_1749e;
    if (memoryAGet16(ds, 0x8bec) != 0x0004)
        goto loc_174a3;
    memoryASet16(ds, si + 38, 0x0001);
    dx = 0x0001;
    if (!(memoryAGet16(ds, si + 16) & 0x8000))
        goto loc_174a3;
    dx = -dx;
    goto loc_174a3;
    // gap 1 bytes
loc_1749e: // 1040:709e
    memoryASet16(ds, si + 40, 0x0001);
loc_174a3: // 1040:70a3
    if (memoryAGet16(ds, si + 48) != 0x0001)
        goto loc_174be;
    memoryASet16(ds, si + 20, memoryAGet16(ds, si + 20) + 1);
    ax = memoryAGet16(ds, si + 18);
    if (ax != memoryAGet16(ds, si + 20))
        goto loc_174f8;
    ax = 0;
    memoryASet16(ds, si + 20, ax);
    dx = -dx;
    goto loc_174f8;
    // gap 1 bytes
loc_174be: // 1040:70be
    if (memoryAGet16(ds, si + 48) != 0x0002)
        goto loc_174e0;
    ax = memoryAGet16(ds, si + 2);
    ax &= 0x000f;
    if (ax != 0x0004)
        goto loc_174f8;
    sub_19b40();
    if (memoryAGet(ds, 0x973f) & 0x01)
        goto loc_174f8;
    sub_176e6();
    goto loc_174f8;
    // gap 1 bytes
loc_174e0: // 1040:70e0
    ax = memoryAGet16(ds, si + 2);
    ax &= 0x000f;
    if (ax != 0x0004)
        goto loc_174f8;
    sub_19b40();
    if (memoryAGet(ds, 0x973f) & 0x01)
        goto loc_174f8;
    dx = -dx;
loc_174f8: // 1040:70f8
    dx += memoryAGet16(ds, si + 44);
    bx = memoryAGet16(ds, si + 2);
    bx += dx;
    if (!dx)
        goto loc_1751e;
    if ((short)dx >= 0)
        goto loc_17513;
    if ((short)bx >= (short)0x0000)
        goto loc_1751e;
    bx = 0x0000;
    dx = -dx;
    goto loc_1751e;
    // gap 1 bytes
loc_17513: // 1040:7113
    if ((short)bx < (short)0x00e8)
        goto loc_1751e;
    bx = 0x00e8;
    dx = -dx;
loc_1751e: // 1040:711e
    ax = memoryAGet16(ds, si + 4);
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x7961, 0xffff);
    memoryASet16(ds, 0x795d, bx);
    memoryASet(ds, 0x796b, 0x01);
    sub_17dfb();
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_17544;
    goto loc_17674;
loc_17544: // 1040:7144
    if (!(ch & 0x02))
        goto loc_17573;
    if ((short)dx >= 0)
        goto loc_17562;
    bx += 0x000c;
    bx &= 0x00f8;
    bx -= 0x0004;
    dx = -dx;
    memoryASet16(ds, si + 20, 0x0000);
    goto loc_17573;
    // gap 1 bytes
loc_17562: // 1040:7162
    bx += 0x0003;
    bx &= 0x00f8;
    bx -= 0x0004;
    dx = -dx;
    memoryASet16(ds, si + 20, 0x0000);
loc_17573: // 1040:7173
    if (memoryAGet16(ds, 0x6e20) == 0x0001)
        goto loc_17584;
    memoryASet16(ds, si + 2, bx);
    if (!dx)
        goto loc_17584;
    memoryASet16(ds, si + 16, dx);
loc_17584: // 1040:7184
    if (memoryAGet16(ds, si + 48) != 0x0003)
        goto loc_17595;
    if (ch & 0x08)
        goto loc_17595;
    memoryASet16(ds, si + 42, 0x0000);
loc_17595: // 1040:7195
    if (memoryAGet16(ds, 0x6e03) == 0x0001)
        goto loc_175a6;
    if (memoryAGet16(ds, 0x6e20) == 0x0001)
        goto loc_175a6;
    sub_17723();
loc_175a6: // 1040:71a6
    if (memoryAGet16(ds, 0x7ecc) != 0x0001)
        goto loc_175c6;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    sub_1646e();
    if (!flags.carry)
        goto loc_175c6;
    memoryASet16(ds, si + 24, 0x0028);
    goto loc_175de;
    // gap 1 bytes
loc_175c6: // 1040:71c6
    bx = memoryAGet16(ds, si + 4);
    bx += 0x0004;
    dh = memoryAGet(ds, si + 2);
    dh += 0x04;
    dl = 0x10;
    ah = 0x15;
    sub_16407();
    if (!flags.carry)
        goto loc_175de;
    goto loc_168a8;
loc_175de: // 1040:71de
    if (memoryAGet16(ds, 0x0b00) != 0x0001)
        goto loc_175ff;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    sub_164a0();
    if (!flags.carry)
        goto loc_175ff;
    memoryASet16(ds, 0x0b00, 0x0000);
    goto loc_17674;
    // gap 1 bytes
loc_175ff: // 1040:71ff
    if (memoryAGet16(ds, 0x0b38) != 0x0002)
        goto loc_17643;
    al = memoryAGet(ds, 0x0b4a);
    if ((char)al <= (char)0x01)
        goto loc_17643;
    if ((char)al > (char)0x04)
        goto loc_17643;
    bx = memoryAGet16(ds, si + 4);
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 30);
    ah = memoryAGet(ds, si + 32);
    if (dh >= 0x0f)
        goto loc_17627;
    dh = 0;
    goto loc_1762a;
    // gap 1 bytes
loc_17627: // 1040:7227
    dh -= 0x10;
loc_1762a: // 1040:722a
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    sub_164e1();
    if (!flags.carry)
        goto loc_17643;
    push(si);
    si = 0x670b;
    sub_16bc7();
    si = pop();
    goto loc_17674;
    // gap 1 bytes
loc_17643: // 1040:7243
    return;
loc_17644: // 1040:7244
    ax = memoryAGet16(ds, si + 4);
    cl = 0;
    bp = memoryAGet16(ds, 0x0b20);
    bp++;
    bp &= 0x00fe;
    ax &= 0x00fe;
    sub_17702();
    memoryASet16(ds, 0x7961, bp);
    ax = memoryAGet16(ds, si + 4);
    ax += bp;
    memoryASet16(ds, si + 8, bp);
    memoryASet16(ds, 0x795f, ax);
    bx = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x795d, bx);
    sub_17dfb();
    goto loc_172cd;
loc_17674: // 1040:7274
    push(si);
    si = 0x670b;
    sub_16bc7();
    si = pop();
    memoryASet16(ds, si + 22, 0x0001);
    memoryASet16(ds, si + 8, 0xfb00);
    ax = 0x000c;
    sub_1aecd();
    ax = memoryAGet16(ds, si + 2);
    if ((short)ax < (short)0x0080)
        goto loc_1769a;
    memoryASet16(ds, si + 16, 0xfffe);
    return;
loc_1769a: // 1040:729a
    memoryASet16(ds, si + 16, 0x0002);
    return;
loc_176a0: // 1040:72a0
    dx = memoryAGet16(ds, si + 8);
    dx += 0x0080;
    memoryASet16(ds, si + 8, dx);
    if ((short)dx < 0)
        goto loc_176b3;
    ch = 0;
    goto loc_176b5;
    // gap 1 bytes
loc_176b3: // 1040:72b3
    ch = 0xff;
loc_176b5: // 1040:72b5
    ax = memoryAGet16(ds, si + 4);
    cl = memoryAGet(ds, si + 6);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    if ((short)ax <= (short)0x0110)
        goto loc_176ca;
    sub_16174();
    return;
loc_176ca: // 1040:72ca
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, si + 6, cl);
    ax = memoryAGet16(ds, 0x73ef);
    ax += 0x0006;
    ax += memoryAGet16(ds, si + 50);
    memoryASet16(ds, si + 10, ax);
    ax = memoryAGet16(ds, si + 16);
    ax += memoryAGet16(ds, si + 2);
    memoryASet16(ds, si + 2, ax);
}
void sub_17674() // 1040:7274
{
    push(si);
    si = 0x670b;
    sub_16bc7();
    si = pop();
    memoryASet16(ds, si + 22, 0x0001);
    memoryASet16(ds, si + 8, 0xfb00);
    ax = 0x000c;
    sub_1aecd();
    ax = memoryAGet16(ds, si + 2);
    if ((short)ax < (short)0x0080)
        goto loc_1769a;
    memoryASet16(ds, si + 16, 0xfffe);
    return;
loc_1769a: // 1040:729a
    memoryASet16(ds, si + 16, 0x0002);
}
void sub_176e6() // 1040:72e6
{
    if ((short)bx <= (short)memoryAGet16(ds, 0x0b1e))
        goto loc_176f0;
    dx = 0xfffe;
    return;
loc_176f0: // 1040:72f0
    dx = 0x0002;
}
void sub_176f4() // 1040:72f4 +returnCarry
{
    if ((short)ax < (short)memoryAGet16(ds, 0x0b20))
        goto loc_176fe;
    if (ax == memoryAGet16(ds, 0x0b20))
        goto loc_17700;
    flags.carry = 1;
    return;
loc_176fe: // 1040:72fe
    flags.carry = 0;
    return;
loc_17700: // 1040:7300
    flags.carry = 0;
}
void sub_17702() // 1040:7302
{
    if (memoryAGet16(ds, 0x6e20) != 0x0001)
        goto loc_1770e;
    flags.carry = 0;
    bp = 0x0000;
    return;
loc_1770e: // 1040:730e
    if ((short)ax < (short)bp)
        goto loc_17719;
    if (ax == bp)
        goto loc_1771e;
    bp = 0xfffe;
    flags.carry = 1;
    return;
loc_17719: // 1040:7319
    bp = 0x0002;
    flags.carry = 0;
    return;
loc_1771e: // 1040:731e
    bp = 0x0000;
    flags.carry = 0;
}
void sub_17723() // 1040:7323
{
    if (memoryAGet16(ds, si + 42) == 0x0001)
        goto loc_17756;
    if (memoryAGet16(ds, si + 38) == 0x0001)
        goto loc_17770;
    if (memoryAGet16(ds, si + 40) == 0x0001)
        goto loc_1778b;
    if (memoryAGet16(ds, si + 34) != 0x0001)
        goto loc_177a6;
    ax = memoryAGet16(ds, si + 16);
    if ((short)ax < 0)
        goto loc_17748;
    ax = 0x0000;
    goto loc_1774b;
    // gap 1 bytes
loc_17748: // 1040:7348
    ax = 0x0003;
loc_1774b: // 1040:734b
    ax += memoryAGet16(ds, 0x73e7);
    ax += memoryAGet16(ds, si + 50);
    memoryASet16(ds, si + 10, ax);
    return;
loc_17756: // 1040:7356
    if (memoryAGet16(ds, si + 42) != 0x0001)
        goto loc_17770;
    ax = 0x0008;
    if (memoryAGet16(ds, si + 8) == 0x0000)
        goto loc_17769;
    ax += memoryAGet16(ds, 0x73ed);
loc_17769: // 1040:7369
    ax += memoryAGet16(ds, si + 50);
    memoryASet16(ds, si + 10, ax);
    return;
loc_17770: // 1040:7370
    ax = memoryAGet16(ds, si + 16);
    if ((short)ax < 0)
        goto loc_1777d;
    ax = 0x0000;
    goto loc_17780;
    // gap 1 bytes
loc_1777d: // 1040:737d
    ax = 0x0003;
loc_17780: // 1040:7380
    ax += memoryAGet16(ds, 0x73e9);
    ax += memoryAGet16(ds, si + 50);
    memoryASet16(ds, si + 10, ax);
    return;
loc_1778b: // 1040:738b
    ax = memoryAGet16(ds, si + 16);
    if ((short)ax < 0)
        goto loc_17798;
    ax = 0x0000;
    goto loc_1779b;
    // gap 1 bytes
loc_17798: // 1040:7398
    ax = 0x0003;
loc_1779b: // 1040:739b
    ax += memoryAGet16(ds, 0x73eb);
    ax += memoryAGet16(ds, si + 50);
    memoryASet16(ds, si + 10, ax);
    return;
loc_177a6: // 1040:73a6
    return;
}
void sub_177fb() // 1040:73fb
{
    ax = memoryAGet16(ds, 0x73f1);
loc_177fe: // 1040:73fe
    bx = 0x73a7;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    if (dx != 0x00ff)
        goto loc_17810;
    ax = 0x0000;
    goto loc_177fe;
loc_17810: // 1040:7410
    memoryASet16(ds, 0x73e7, dx);
    ax++;
    ax++;
    memoryASet16(ds, 0x73f1, ax);
    ax = memoryAGet16(ds, 0x73f3);
loc_1781c: // 1040:741c
    bx = 0x73b5;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1782e;
    ax = 0x0000;
    goto loc_1781c;
loc_1782e: // 1040:742e
    memoryASet16(ds, 0x73e9, dx);
    ax++;
    ax++;
    memoryASet16(ds, 0x73f3, ax);
    ax = memoryAGet16(ds, 0x73f5);
loc_1783a: // 1040:743a
    bx = 0x73cf;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1784c;
    ax = 0x0000;
    goto loc_1783a;
loc_1784c: // 1040:744c
    memoryASet16(ds, 0x73eb, dx);
    ax++;
    ax++;
    memoryASet16(ds, 0x73f5, ax);
    ax = memoryAGet16(ds, 0x73f7);
loc_17858: // 1040:7458
    bx = 0x73d7;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1786a;
    ax = 0x0000;
    goto loc_17858;
loc_1786a: // 1040:746a
    memoryASet16(ds, 0x73ed, dx);
    ax++;
    ax++;
    memoryASet16(ds, 0x73f7, ax);
    ax = memoryAGet16(ds, 0x73f9);
loc_17876: // 1040:7476
    bx = 0x73e1;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    if (dx != 0x00ff)
        goto loc_17888;
    ax = 0x0000;
    goto loc_17876;
loc_17888: // 1040:7488
    memoryASet16(ds, 0x73ef, dx);
    ax++;
    ax++;
    memoryASet16(ds, 0x73f9, ax);
}
void sub_17896() // 1040:7496
{
    bx = memoryAGet16(ds, si + 16);
    al = memoryAGet(ds, bx);
    if (al != 0x00)
        goto loc_178a5;
    bx++;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 16, bx);
loc_178a5: // 1040:74a5
    bx++;
    al = memoryAGet(ds, bx);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    if (al != 0x07)
        goto loc_178b6;
    al++;
loc_178b6: // 1040:74b6
    cbw();
    memoryASet16(ds, 0x7492, ax);
    al = memoryAGet(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_178c4;
    al |= 0xf0;
loc_178c4: // 1040:74c4
    if (al != 0x07)
        goto loc_178ca;
    al++;
loc_178ca: // 1040:74ca
    cbw();
    memoryASet16(ds, 0x7494, ax);
    bx--;
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ds, si + 18, memoryAGet16(ds, si + 18) + 1);
    if (ax == memoryAGet16(ds, si + 18))
        goto loc_178dc;
    if (ax >= memoryAGet16(ds, si + 18))
        goto loc_178e6;
loc_178dc: // 1040:74dc
    memoryASet16(ds, si + 18, 0x0000);
    bx++;
    bx++;
    memoryASet16(ds, si + 16, bx);
loc_178e6: // 1040:74e6
    ax = memoryAGet16(ds, 0x7492);
    dx = memoryAGet16(ds, 0x7494);
}
void sub_17a31() // 1040:7631
{
    memoryASet16(ds, 0x7629, 0x0014);
    di = 0x0c28;
    si = 0x74ee;
    cx = 0x0005;
loc_17a40: // 1040:7640
    memoryASet16(ds, di, 0x0001);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 2, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 4, ax);
    ax = 0;
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, di + 12, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 22, ax);
    ax = 0;
    memoryASet16(ds, di + 24, ax);
    push(si);
    push(di);
    push(cx);
    si = di;
    sub_1718e();
    cx = pop();
    di = pop();
    si = pop();
    ax = 0;
    memoryASet16(ds, di + 24, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 16, ax);
    ax = 0;
    memoryASet16(ds, di + 18, ax);
    memoryASet16(ds, di + 20, ax);
    di += 0x0034;
    if (--cx)
        goto loc_17a40;
    memoryASet16(ds, 0x0d2c, ax);
    memoryASet16(ds, 0x762b, ax);
    memoryASet16(ds, 0x762f, 0x0001);
}
void sub_17a8b() // 1040:768b
{
    if (memoryAGet16(ds, 0x762d) != 0x0001)
        goto loc_17a9c;
    if (memoryAGet16(ds, 0x762f) == 0x0001)
        goto loc_17a9d;
loc_17a9c: // 1040:769c
    return;
loc_17a9d: // 1040:769d
    si = 0x0c28;
    sub_17896();
    cx = 0x0005;
loc_17aa6: // 1040:76a6
    push(cx);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
    push(ax);
    push(dx);
    sub_1718e();
    dx = pop();
    ax = pop();
    si += 0x0034;
    cx = pop();
    if (--cx)
        goto loc_17aa6;
    dh = memoryAGet(ds, 0x0c2a);
    bx = memoryAGet16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    sub_16407();
    if (!flags.carry)
        goto loc_17ad1;
    sub_168a8();
    goto loc_17aeb;
    // gap 1 bytes
loc_17ad1: // 1040:76d1
    dh = memoryAGet(ds, 0x0c2a);
    dh += 0xec;
    bx = memoryAGet16(ds, 0x0c2c);
    bx += 0x0018;
    dl = 0x14;
    ah = 0x20;
    sub_16407();
    if (!flags.carry)
        goto loc_17aeb;
    sub_168a8();
loc_17aeb: // 1040:76eb
    dh = memoryAGet(ds, 0x0c2a);
    bx = memoryAGet16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    sub_164a0();
    if (!flags.carry)
        goto loc_17b0d;
    memoryASet16(ds, 0x0b00, 0x0000);
    sub_17d53();
    if (!flags.carry)
        goto loc_17b0a;
    goto loc_17ba5;
loc_17b0a: // 1040:770a
    goto loc_17b2f;
    // gap 1 bytes
loc_17b0d: // 1040:770d
    dh = memoryAGet(ds, 0x0c2a);
    dh += 0xec;
    bx = memoryAGet16(ds, 0x0c2c);
    bx += 0x0018;
    dl = 0x14;
    ah = 0x20;
    sub_164a0();
    if (!flags.carry)
        goto loc_17b2f;
    memoryASet16(ds, 0x0b00, 0x0000);
    sub_17d53();
    if (flags.carry)
        goto loc_17ba5;
loc_17b2f: // 1040:772f
    dh = memoryAGet(ds, 0x0c2a);
    bx = memoryAGet16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    dh -= 0x10;
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    if (memoryAGet16(ds, 0x0b38) != 0x0002)
        goto loc_17b96;
    if ((short)memoryAGet16(ds, 0x0b4a) > (short)0x0004)
        goto loc_17b96;
    if ((short)memoryAGet16(ds, 0x0b4a) <= (short)0x0001)
        goto loc_17b96;
    sub_164e1();
    if (!flags.carry)
        goto loc_17b6e;
    sub_17d53();
    if (flags.carry)
        goto loc_17ba5;
    sub_17d53();
    if (flags.carry)
        goto loc_17ba5;
    goto loc_17b96;
    // gap 1 bytes
loc_17b6e: // 1040:776e
    dh = memoryAGet(ds, 0x0c2a);
    dh += 0xec;
    bx = memoryAGet16(ds, 0x0c2c);
    bx += 0x0018;
    dl = 0x14;
    ah = 0x20;
    dh -= 0x10;
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    sub_164e1();
    if (!flags.carry)
        goto loc_17b96;
    sub_17d53();
    if (flags.carry)
        goto loc_17ba5;
loc_17b96: // 1040:7796
    if (memoryAGet16(ds, 0x0d2c) == 0x0001)
        goto loc_17ba1;
    sub_17c64();
    return;
loc_17ba1: // 1040:77a1
    sub_17cf4();
    return;
loc_17ba5: // 1040:77a5
    memoryASet16(ds, 0x762d, 0x0000);
    memoryASet16(ds, 0x762f, 0x0000);
    memoryASet(ds, 0x5b3e, 0x01);
    cx = 0x0005;
    si = 0x758b;
    di = 0x0c28;
loc_17bbf: // 1040:77bf
    memoryASet16(ds, di, 0x0011);
    memoryASet16(ds, di + 50, 0x0060);
    memoryASet16(ds, di + 28, 0x0000);
    memoryASet16(ds, di + 24, 0x0000);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 22, ax);
    memoryASet16(ds, di + 18, 0x0000);
    memoryASet16(ds, di + 20, 0x0000);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 16, ax);
    di += 0x0034;
    if (--cx)
        goto loc_17bbf;
    di = 0x0b56;
    memoryASet16(ds, di, 0x0001);
    ax = memoryAGet16(ds, 0x0c2a);
    memoryASet16(ds, di + 2, ax);
    ax = memoryAGet16(ds, 0x0c2c);
    memoryASet16(ds, di + 4, ax);
    memoryASet16(ds, di + 50, 0x0034);
    memoryASet16(ds, di + 22, 0x0001);
    memoryASet16(ds, di + 24, 0x0000);
    memoryASet16(ds, di + 6, 0x0000);
    memoryASet16(ds, di + 8, 0xfb00);
    memoryASet16(ds, di + 16, 0xfffe);
    memoryASet16(ds, di + 28, 0x0000);
    memoryASet16(ds, 0x0d2c, 0x0000);
    if (memoryAGet16(ds, 0x8bee) != 0x0001)
        goto loc_17c63;
    cx = memoryAGet16(ds, 0x6610);
    if (!cx)
        goto loc_17c3e;
loc_17c34: // 1040:7834
    si = 0x6729;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c34;
loc_17c3e: // 1040:783e
    cx = memoryAGet16(ds, 0x6612);
    if (!cx)
        goto loc_17c50;
loc_17c46: // 1040:7846
    si = 0x672f;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c46;
loc_17c50: // 1040:7850
    cx = memoryAGet16(ds, 0x6614);
    cx++;
    if (!cx)
        goto loc_17c63;
loc_17c59: // 1040:7859
    si = 0x6735;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c59;
loc_17c63: // 1040:7863
    return;
}
void sub_17c64() // 1040:7864
{
    if (!(memoryAGet16(ds, 0x762b) & 0xffff))
        goto loc_17c71;
    memoryASet16(ds, 0x762b, memoryAGet16(ds, 0x762b) - 1);
    return;
loc_17c71: // 1040:7871
    ax = 0x000d;
    sub_1aecd();
    memoryASet16(ds, 0x762b, 0x0032);
    memoryASet16(ds, 0x0d2c, 0x0001);
    memoryASet16(ds, 0x0d36, 0x0055);
    ax = memoryAGet16(ds, 0x0b1e);
    ax += 0x000c;
    bx = memoryAGet16(ds, 0x0b20);
    bx += 0x000a;
    cx = memoryAGet16(ds, 0x0c2a);
    cx += 0xffe4;
    memoryASet16(ds, 0x0d2e, cx);
    dx = memoryAGet16(ds, 0x0c2c);
    dx += 0x002c;
    memoryASet16(ds, 0x0d30, dx);
    ax -= cx;
    cx = ax;
    bx -= dx;
    dx = bx;
loc_17cb4: // 1040:78b4
    if ((short)ax > (short)0x0004)
        goto loc_17ccb;
    if ((short)ax < (short)0xfffc)
        goto loc_17ccb;
    if ((short)bx > (short)0x0004)
        goto loc_17ccb;
    if ((short)bx < (short)0xfffc)
        goto loc_17ccb;
    goto loc_17cec;
    // gap 1 bytes
loc_17ccb: // 1040:78cb
    ax = sar16(ax, 0x0001);
    bx = sar16(bx, 0x0001);
    if (ax != 0x0000)
        goto loc_17cb4;
    if (bx != 0x0000)
        goto loc_17cb4;
    ax = 0x0004;
    bx = ax;
    if ((short)cx >= (short)0x0000)
        goto loc_17ce5;
    ax = -ax;
loc_17ce5: // 1040:78e5
    stop("infinite loop"); // sync Y Z
    if ((short)dx >= (short)0x0000)
        goto loc_17ce5;
    bx = -bx;
loc_17cec: // 1040:78ec
    memoryASet16(ds, 0x0d3c, ax);
    memoryASet16(ds, 0x0d34, bx);
}
void sub_17cf4() // 1040:78f4
{
    memoryASet16(ds, 0x762b, memoryAGet16(ds, 0x762b) - 1);
    if ((short)memoryAGet16(ds, 0x762b) >= 0)
        goto loc_17d00;
    memoryASet16(ds, 0x762b, 0x0000);
loc_17d00: // 1040:7900
    ax = memoryAGet16(ds, 0x0d2e);
    ax += memoryAGet16(ds, 0x0d3c);
    memoryASet16(ds, 0x0d2e, ax);
    dx = memoryAGet16(ds, 0x0d30);
    dx += memoryAGet16(ds, 0x0d34);
    memoryASet16(ds, 0x0d30, dx);
    ax += 0x0004;
    if ((short)ax <= (short)0x0004)
        goto loc_17d4c;
    if ((short)ax >= (short)0x00fc)
        goto loc_17d4c;
    dx += 0x0004;
    memoryASet16(ds, 0x795d, ax);
    memoryASet16(ds, 0x795f, dx);
    sub_18014();
    ch = memoryAGet(ds, 0x7963);
    if (ch & 0x02)
        goto loc_17d4c;
    ax--;
    ax--;
    bx = dx;
    dh = al;
    dl = 0x04;
    ah = 0x04;
    sub_16407();
    if (!flags.carry)
        goto loc_17d52;
    sub_168a8();
loc_17d4c: // 1040:794c
    memoryASet16(ds, 0x0d2c, 0x0000);
loc_17d52: // 1040:7952
    return;
}
void sub_17d53() // 1040:7953 +returnCarry
{
    memoryASet16(ds, 0x7629, memoryAGet16(ds, 0x7629) - 1);
    if (!memoryAGet16(ds, 0x7629))
        goto loc_17d5b;
    flags.carry = 0;
    return;
loc_17d5b: // 1040:795b
    flags.carry = 1;
}
void sub_17d70() // 1040:7970
{
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    memoryASet16(ds, 0x796c, 0x0005);
    memoryASet16(ds, 0x796e, 0x0010);
    memoryASet16(ds, 0x7964, 0x7fff);
    memoryASet16(ds, 0x7e02, 0x0000);
    cx = 0x0003;
    dx = memoryAGet16(ds, 0x795f);
    dx &= 0x0007;
    if ((short)dx >= (short)0x0004)
        goto loc_17d9f;
    cx = 0x0002;
loc_17d9f: // 1040:799f
    memoryASet(ds, 0x796a, 0x00);
    bp = 0x0004;
    sub_17ff3();
    dx &= 0x0007;
    if (!dx)
        goto loc_17dd7;
    ax = 0;
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001d;
    bl &= 0x02;
    if (!bl)
        goto loc_17e2f;
    memoryASet16(ds, 0x7e02, 0x0001);
    goto loc_17e2f;
    // gap 1 bytes
loc_17dd7: // 1040:79d7
    ax = 0;
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001e;
    bl &= 0x02;
    if (bl)
        goto loc_17df2;
    goto loc_17e8a;
loc_17df2: // 1040:79f2
    memoryASet16(ds, 0x7e02, 0x0001);
    goto loc_17e8a;
    // gap 52 bytes
loc_17e2f: // 1040:7a2f
    bx = 0;
    ax = 0;
    goto loc_17e4e;
    // gap 1 bytes
loc_17e36: // 1040:7a36
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bh |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001d;
loc_17e4e: // 1040:7a4e
    if (--cx)
        goto loc_17e36;
    bl &= 0x22;
    bh &= 0x2a;
    memoryASet(ds, 0x796a, bl);
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bh);
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bh = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    bl &= 0x27;
    bh &= 0x7f;
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bl);
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bh);
    al = memoryAGet(ds, 0x796a);
    memoryASet(ds, 0x7963, al);
    goto loc_17ec9;
    // gap 1 bytes
loc_17e8a: // 1040:7a8a
    bx = 0;
    ax = 0;
    goto loc_17ea2;
    // gap 1 bytes
loc_17e91: // 1040:7a91
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001e;
loc_17ea2: // 1040:7aa2
    if (--cx)
        goto loc_17e91;
    bl &= 0x2a;
    memoryASet(ds, 0x796a, bl);
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    bl &= 0x7f;
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bl);
    al = memoryAGet(ds, 0x796a);
    memoryASet(ds, 0x7963, al);
    goto loc_17ec9;
    // gap 1 bytes
loc_17ec9: // 1040:7ac9
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax >= 0)
        goto loc_17ed8;
    al = memoryAGet(ds, 0x7963);
    al &= 0xfb;
    memoryASet(ds, 0x7963, al);
loc_17ed8: // 1040:7ad8
    if (memoryAGet(ds, 0x796b) == 0x01)
        goto loc_17ee2;
    goto loc_17fb9;
loc_17ee2: // 1040:7ae2
    si = 0x0c28;
loc_17ee5: // 1040:7ae5
    ax = memoryAGet16(ds, si);
    if (ax != 0xffff)
        goto loc_17eef;
    goto loc_17fb9;
loc_17eef: // 1040:7aef
    if (al)
        goto loc_17ef6;
    goto loc_17fb3;
loc_17ef6: // 1040:7af6
    if (al & 0x80)
        goto loc_17efd;
    goto loc_17fb3;
loc_17efd: // 1040:7afd
    if (!(al & 0x40))
        goto loc_17f68;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, si + 32);
    ch = memoryAGet(ds, 0x795d);
    ch += 0x04;
    bp = memoryAGet16(ds, 0x795f);
    bp += memoryAGet16(ds, 0x796c);
    dh = 0x10;
    bh = memoryAGet(ds, 0x796e);
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_17f2f;
    goto loc_17fb3;
loc_17f2f: // 1040:7b2f
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x02);
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_17f65;
    bx = memoryAGet16(ds, 0x795f);
    bx += 0x0014;
    ax = 0;
    al = memoryAGet(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_17f65;
    memoryASet16(ds, 0x7964, di);
    memoryASet16(ds, 0x7966, 0x0000);
    memoryASet16(ds, 0x7968, 0x0000);
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
loc_17f65: // 1040:7b65
    goto loc_17fb3;
    // gap 1 bytes
loc_17f68: // 1040:7b68
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax < 0)
        goto loc_17fb3;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, 0x7962);
    bl += 0x08;
    ch = memoryAGet(ds, 0x795d);
    ch += 0x04;
    bp = memoryAGet16(ds, 0x795f);
    bp += 0x0014;
    dh = 0x10;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_17fb3;
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_17fb3;
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
    memoryASet16(ds, 0x7964, di);
    ax = memoryAGet16(ds, si + 46);
    memoryASet16(ds, 0x7966, ax);
    ax = memoryAGet16(ds, si + 48);
    memoryASet16(ds, 0x7968, ax);
loc_17fb3: // 1040:7bb3
    si += 0x0034;
    goto loc_17ee5;
loc_17fb9: // 1040:7bb9
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
}
void sub_17dfb() // 1040:79fb
{
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    memoryASet16(ds, 0x796c, 0x0000);
    memoryASet16(ds, 0x796e, 0x0015);
    memoryASet16(ds, 0x7964, 0x7fff);
    cx = 0x0004;
    dx = memoryAGet16(ds, 0x795f);
    dx &= 0x0007;
    if ((short)dx >= (short)0x0004)
        goto loc_17e24;
    cx = 0x0003;
loc_17e24: // 1040:7a24
    bp = 0x0004;
    sub_17ff3();
    dx &= 0x0007;
    if (!dx)
        goto loc_17e8a;
    bx = 0;
    ax = 0;
    goto loc_17e4e;
    // gap 1 bytes
loc_17e36: // 1040:7a36
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bh |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001d;
loc_17e4e: // 1040:7a4e
    if (--cx)
        goto loc_17e36;
    bl &= 0x22;
    bh &= 0x2a;
    memoryASet(ds, 0x796a, bl);
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bh);
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bh = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    bl &= 0x27;
    bh &= 0x7f;
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bl);
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bh);
    al = memoryAGet(ds, 0x796a);
    memoryASet(ds, 0x7963, al);
    goto loc_17ec9;
    // gap 1 bytes
loc_17e8a: // 1040:7a8a
    bx = 0;
    ax = 0;
    goto loc_17ea2;
    // gap 1 bytes
loc_17e91: // 1040:7a91
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001e;
loc_17ea2: // 1040:7aa2
    if (--cx)
        goto loc_17e91;
    bl &= 0x2a;
    memoryASet(ds, 0x796a, bl);
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    bl &= 0x7f;
    memoryASet(ds, 0x796a, memoryAGet(ds, 0x796a) | bl);
    al = memoryAGet(ds, 0x796a);
    memoryASet(ds, 0x7963, al);
    goto loc_17ec9;
    // gap 1 bytes
loc_17ec9: // 1040:7ac9
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax >= 0)
        goto loc_17ed8;
    al = memoryAGet(ds, 0x7963);
    al &= 0xfb;
    memoryASet(ds, 0x7963, al);
loc_17ed8: // 1040:7ad8
    if (memoryAGet(ds, 0x796b) == 0x01)
        goto loc_17ee2;
    goto loc_17fb9;
loc_17ee2: // 1040:7ae2
    si = 0x0c28;
loc_17ee5: // 1040:7ae5
    ax = memoryAGet16(ds, si);
    if (ax != 0xffff)
        goto loc_17eef;
    goto loc_17fb9;
loc_17eef: // 1040:7aef
    if (al)
        goto loc_17ef6;
    goto loc_17fb3;
loc_17ef6: // 1040:7af6
    if (al & 0x80)
        goto loc_17efd;
    goto loc_17fb3;
loc_17efd: // 1040:7afd
    if (!(al & 0x40))
        goto loc_17f68;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, si + 32);
    ch = memoryAGet(ds, 0x795d);
    ch += 0x04;
    bp = memoryAGet16(ds, 0x795f);
    bp += memoryAGet16(ds, 0x796c);
    dh = 0x10;
    bh = memoryAGet(ds, 0x796e);
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_17f2f;
    goto loc_17fb3;
loc_17f2f: // 1040:7b2f
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x02);
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_17f65;
    bx = memoryAGet16(ds, 0x795f);
    bx += 0x0014;
    ax = 0;
    al = memoryAGet(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_17f65;
    memoryASet16(ds, 0x7964, di);
    memoryASet16(ds, 0x7966, 0x0000);
    memoryASet16(ds, 0x7968, 0x0000);
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
loc_17f65: // 1040:7b65
    goto loc_17fb3;
    // gap 1 bytes
loc_17f68: // 1040:7b68
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax < 0)
        goto loc_17fb3;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, 0x7962);
    bl += 0x08;
    ch = memoryAGet(ds, 0x795d);
    ch += 0x04;
    bp = memoryAGet16(ds, 0x795f);
    bp += 0x0014;
    dh = 0x10;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_17fb3;
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_17fb3;
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
    memoryASet16(ds, 0x7964, di);
    ax = memoryAGet16(ds, si + 46);
    memoryASet16(ds, 0x7966, ax);
    ax = memoryAGet16(ds, si + 48);
    memoryASet16(ds, 0x7968, ax);
loc_17fb3: // 1040:7bb3
    si += 0x0034;
    goto loc_17ee5;
loc_17fb9: // 1040:7bb9
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
}
void sub_17fbf() // 1040:7bbf +returnCarry
{
    ax = 0;
    al = ch;
    si = ax;
    al = dh;
    si += ax;
    al = cl;
    if ((short)si <= (short)ax)
        goto loc_17ff1;
    si = ax;
    al = dl;
    si += ax;
    al = ch;
    if ((short)si <= (short)ax)
        goto loc_17ff1;
    cx = 0;
    cl = bh;
    cx += bp;
    if ((short)cx <= (short)di)
        goto loc_17ff1;
    ax = 0;
    al = bl;
    ax += di;
    if ((short)ax <= (short)bp)
        goto loc_17ff1;
    flags.carry = 1;
    return;
loc_17ff1: // 1040:7bf1
    flags.carry = 0;
}
void sub_17ff3() // 1040:7bf3
{
    si = 0x563c;
    dx = memoryAGet16(ds, 0x795f);
    dx &= 0xfff8;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    dx = memoryAGet16(ds, 0x795d);
    dx += bp;
    bp = dx;
    bp >>= 1;
    bp >>= 1;
    bp >>= 1;
    si += bp;
}
void sub_18014() // 1040:7c14
{
    push(ax);
    push(dx);
    bp = 0;
    sub_17ff3();
    ax = 0;
    al = lodsb<DS_SI>();
    di = ax;
    al = memoryAGet(ds, di + 21492);
    memoryASet(ds, 0x7963, al);
    sub_181c6();
    dx = pop();
    ax = pop();
}
void sub_1802d() // 1040:7c2d
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    cx = 0x0002;
    ax = memoryAGet16(ds, 0x795f);
    ax &= 0x0007;
    if (!ax)
        goto loc_1803f;
    cx = 0x0003;
loc_1803f: // 1040:7c3f
    bp = 0x0008;
    sub_17ff3();
    dx &= 0x0007;
    if (!dx)
        goto loc_18083;
    bx = 0;
    ax = 0;
    goto loc_18062;
    // gap 1 bytes
loc_18051: // 1040:7c51
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001e;
loc_18062: // 1040:7c62
    if (--cx)
        goto loc_18051;
    bl &= 0x23;
    bh = bl;
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    bl &= 0x27;
    bh |= bl;
    memoryASet(ds, 0x7963, bh);
    goto loc_180ae;
    // gap 1 bytes
loc_18083: // 1040:7c83
    bx = 0;
    ax = 0;
    goto loc_18094;
    // gap 1 bytes
loc_1808a: // 1040:7c8a
    al = lodsb<DS_SI>();
    di = ax;
    bl |= memoryAGet(ds, di + 21492);
    si += 0x001f;
loc_18094: // 1040:7c94
    if (--cx)
        goto loc_1808a;
    bl &= 0x2b;
    bh = bl;
    al = lodsb<DS_SI>();
    di = ax;
    bl = memoryAGet(ds, di + 21492);
    bl &= 0x27;
    bh |= bl;
    memoryASet(ds, 0x7963, bh);
    goto loc_180ae;
    // gap 1 bytes
loc_180ae: // 1040:7cae
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax >= 0)
        goto loc_180c0;
    bh = memoryAGet(ds, 0x7963);
    bh &= 0xfb;
    memoryASet(ds, 0x7963, bh);
loc_180c0: // 1040:7cc0
    if (memoryAGet(ds, 0x796b) == 0x01)
        goto loc_180ca;
    goto loc_1819f;
loc_180ca: // 1040:7cca
    si = 0x0c28;
loc_180cd: // 1040:7ccd
    ax = memoryAGet16(ds, si);
    if (ax != 0xffff)
        goto loc_180d7;
    goto loc_1819f;
loc_180d7: // 1040:7cd7
    if (al)
        goto loc_180de;
    goto loc_18199;
loc_180de: // 1040:7cde
    if (al & 0x80)
        goto loc_180e5;
    goto loc_18199;
loc_180e5: // 1040:7ce5
    if (!(al & 0x40))
        goto loc_1814e;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, si + 32);
    ch = memoryAGet(ds, 0x795d);
    ch += 0x08;
    bp = memoryAGet16(ds, 0x795f);
    bp += memoryAGet16(ds, 0x796c);
    dh = 0x08;
    bh = 0x10;
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_18115;
    goto loc_18199;
loc_18115: // 1040:7d15
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x02);
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_1814b;
    bx = memoryAGet16(ds, 0x795f);
    bx += 0x0010;
    ax = 0;
    al = memoryAGet(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_1814b;
    memoryASet16(ds, 0x7964, di);
    memoryASet16(ds, 0x7966, 0x0000);
    memoryASet16(ds, 0x7968, 0x0000);
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
loc_1814b: // 1040:7d4b
    goto loc_18199;
    // gap 1 bytes
loc_1814e: // 1040:7d4e
    ax = memoryAGet16(ds, 0x7961);
    if ((short)ax < 0)
        goto loc_18199;
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = memoryAGet(ds, si + 30);
    bl = memoryAGet(ds, 0x7962);
    bl += 0x08;
    ch = memoryAGet(ds, 0x795d);
    ch += 0x08;
    bp = memoryAGet16(ds, 0x795f);
    bp += 0x000f;
    dh = 0x08;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_18199;
    if ((short)di > (short)memoryAGet16(ds, 0x7964))
        goto loc_18199;
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
    memoryASet16(ds, 0x7964, di);
    ax = memoryAGet16(ds, si + 46);
    memoryASet16(ds, 0x7966, ax);
    ax = memoryAGet16(ds, si + 48);
    memoryASet16(ds, 0x7968, ax);
loc_18199: // 1040:7d99
    si += 0x0034;
    goto loc_180cd;
loc_1819f: // 1040:7d9f
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_181a4() // 1040:7da4 +returnCarry
{
    al = ch;
    ah = 0;
    ch = 0;
    if ((short)ax < (short)cx)
        goto loc_181c4;
    dh = 0;
    cx += dx;
    if ((short)ax > (short)cx)
        goto loc_181c4;
    if ((short)bp < (short)di)
        goto loc_181c4;
    bh = 0;
    di += bx;
    if ((short)bp > (short)di)
        goto loc_181c4;
    flags.carry = 1;
    return;
loc_181c4: // 1040:7dc4
    flags.carry = 0;
}
void sub_181c6() // 1040:7dc6
{
    si = 0x0c28;
loc_181c9: // 1040:7dc9
    ax = memoryAGet16(ds, si);
    if (ax == 0xffff)
        goto loc_181fd;
    if (!al)
        goto loc_181f8;
    if (!(al & 0x80))
        goto loc_181f8;
    if (!(al & 0x40))
        goto loc_181f8;
    ch = memoryAGet(ds, 0x795d);
    bp = memoryAGet16(ds, 0x795f);
    cl = memoryAGet(ds, si + 2);
    di = memoryAGet16(ds, si + 4);
    dl = 0x18;
    bl = 0x15;
    sub_181a4();
    if (!flags.carry)
        goto loc_181f8;
    memoryASet(ds, 0x7963, memoryAGet(ds, 0x7963) | 0x40);
loc_181f8: // 1040:7df8
    si += 0x0034;
    goto loc_181c9;
loc_181fd: // 1040:7dfd
    return;
}
void sub_18351() // 1040:7f51
{
    bool temp_cf;

    goto loc_18351;
loc_168a8: // 1040:64a8
    ax = 0x000b;
    sub_1aecd();
    memoryASet16(ds, 0x7e16, 0x0001);
    memoryASet16(ds, 0x0b24, 0xfb00);
    ax = memoryAGet16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memoryASet16(ds, 0x7e1c, 0xfffe);
    goto loc_168d1;
    // gap 1 bytes
loc_168cb: // 1040:64cb
    memoryASet16(ds, 0x7e1c, 0x0002);
loc_168d1: // 1040:64d1
    ax = memoryAGet16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memoryASet16(ds, 0x6614, memoryAGet16(ds, 0x6614) - 1);
loc_168e3: // 1040:64e3
    return;
    // gap 6765 bytes
loc_18351: // 1040:7f51
    if (memoryAGet16(ds, 0x7e16) != 0x0001)
        goto loc_1835b;
    goto loc_18f9a;
loc_1835b: // 1040:7f5b
    sub_19c05();
    ax = memoryAGet16(ds, 0x0b20);
    memoryASet16(ds, 0x7dfe, ax);
    memoryASet(ds, 0x90c2, 0x00);
    memoryASet16(ds, 0x7e1a, 0x0000);
    sub_1c4ca();
    if (!(memoryAGet16(ds, 0x7ed2) & 0x00ff))
        goto loc_1837f;
    memoryASet16(ds, 0x7ed2, memoryAGet16(ds, 0x7ed2) - 1);
loc_1837f: // 1040:7f7f
    if (al == memoryAGet(ds, 0x7eca))
        goto loc_18396;
    memoryASet(ds, 0x7eca, 0x00);
    memoryASet16(ds, 0x7ecc, 0x0000);
    memoryASet16(ds, 0x7ed2, 0x0000);
loc_18396: // 1040:7f96
    if (memoryAGet16(ds, 0x7e00) != 0x0001)
        goto loc_183a0;
    goto loc_18b03;
loc_183a0: // 1040:7fa0
    ax = memoryAGet16(ds, 0x7e06);
    if (!ax)
        goto loc_183aa;
    goto loc_18987;
loc_183aa: // 1040:7faa
    memoryASet16(ds, 0x7e08, 0x0000);
    memoryASet16(ds, 0x7e0a, 0x0000);
    memoryASet16(ds, 0x7e0c, 0x0000);
    memoryASet16(ds, 0x7e0e, 0x0000);
    memoryASet16(ds, 0x7e10, 0x0000);
    memoryASet16(ds, 0x7e14, 0x0000);
    memoryASet(ds, 0x796b, 0x01);
    dx = memoryAGet16(ds, 0x0b24);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_183e4;
    dx = 0x0800;
loc_183e4: // 1040:7fe4
    memoryASet16(ds, 0x0b24, dx);
    memoryASet16(ds, 0x7961, dx);
    if ((short)dx < 0)
        goto loc_183f5;
    ch = 0;
    goto loc_183f7;
    // gap 1 bytes
loc_183f5: // 1040:7ff5
    ch = 0xff;
loc_183f7: // 1040:7ff7
    ax = memoryAGet16(ds, 0x0b20);
    cl = memoryAGet(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    memoryASet16(ds, 0x795f, ax);
    dx = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x795d, dx);
    memoryASet(ds, 0x796b, 0x01);
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_18421;
    sub_17d70();
    goto loc_18424;
    // gap 1 bytes
loc_18421: // 1040:8021
    sub_17dfb();
loc_18424: // 1040:8024
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x40))
        goto loc_18485;
    ax = memoryAGet16(ds, 0x7964);
    cl = 0;
    ax -= 0x0015;
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x0b20, ax);
    memoryASet(ds, 0x0b22, 0x00);
    memoryASet16(ds, 0x7e08, 0x0001);
    push(ax);
    ax = memoryAGet16(ds, 0x7966);
    memoryASet16(ds, 0x7e1a, ax);
    ax = pop();
    memoryASet(ds, 0x796b, 0x00);
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_18460;
    sub_17d70();
    goto loc_18463;
    // gap 1 bytes
loc_18460: // 1040:8060
    sub_17dfb();
loc_18463: // 1040:8063
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_1846f;
    goto loc_168a8;
loc_1846f: // 1040:806f
    ch &= 0x06;
    if (!ch)
        goto loc_1847b;
    ch = memoryAGet(ds, 0x7963);
    goto loc_184a3;
    // gap 1 bytes
loc_1847b: // 1040:807b
    ch = memoryAGet(ds, 0x7963);
    dx = 0x0100;
    goto loc_1857c;
loc_18485: // 1040:8085
    if (!(ch & 0x20))
        goto loc_1848d;
    goto loc_168a8;
loc_1848d: // 1040:808d
    if (ch & 0x04)
        goto loc_184da;
    if (ch & 0x02)
        goto loc_1849a;
    goto loc_186a8;
loc_1849a: // 1040:809a
    bp = memoryAGet16(cs, 0x0b24);
    if ((short)bp >= 0)
        goto loc_184da;
loc_184a3: // 1040:80a3
    if (memoryAGet16(ds, 0x7e06) != 0x0001)
        goto loc_184c8;
    bp = memoryAGet16(cs, 0x0b1e);
    bp &= 0x001f;
    if ((short)bp >= (short)0x000a)
        goto loc_184c8;
    bp = memoryAGet16(cs, 0x0b1e);
    bp &= 0x00f0;
    bp |= 0x0004;
    memoryASet16(cs, 0x0b1e, bp);
loc_184c8: // 1040:80c8
    ax |= 0x0007;
    ax++;
    cl = 0;
    memoryASet16(ds, 0x0b24, 0x0100);
    dx = 0x0100;
    goto loc_186a8;
loc_184da: // 1040:80da
    if (!(ch & 0x10))
        goto loc_18524;
    if (memoryAGet(ds, 0xb884) & 0x10)
        goto loc_18524;
    if (memoryAGet16(ds, 0x7e04) == 0x0001)
        goto loc_18524;
    if (memoryAGet16(ds, 0x7e06) != 0x0001)
        goto loc_184f8;
    goto loc_186a8;
loc_184f8: // 1040:80f8
    if (!(memoryAGet(ds, 0xb884) & 0x04))
        goto loc_18524;
    bx = memoryAGet16(ds, 0x0b1e);
    bx &= 0x001f;
    if ((short)bx >= (short)0x000a)
        goto loc_18524;
    bx = memoryAGet16(ds, 0x0b1e);
    bx &= 0x00f0;
    bx |= 0x0004;
    memoryASet16(ds, 0x0b1e, bx);
    memoryASet16(ds, 0x7e06, 0x0001);
    goto loc_186a8;
loc_18524: // 1040:8124
    memoryASet16(ds, 0x7e06, 0x0000);
    memoryASet16(ds, 0x7e08, 0x0001);
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    memoryASet16(ds, 0x0b20, ax);
    memoryASet(ds, 0x0b22, cl);
    dx = 0x0100;
    if (!(ch & 0x01))
        goto loc_1857c;
    if (memoryAGet16(ds, 0x8bec) != 0x0003)
        goto loc_1857c;
    dx = memoryAGet16(ds, 0x0b24);
    if ((short)dx < (short)0x0200)
        goto loc_18570;
    dx = -dx;
    dx += 0x0060;
    memoryASet16(ds, 0x0b24, dx);
    dx = 0xf781;
    ax = 0x0016;
    sub_1aecd();
    goto loc_185ab;
    // gap 1 bytes
loc_18570: // 1040:8170
    memoryASet16(ds, 0x0b24, 0x0100);
    dx = 0xfa00;
    goto loc_185ab;
    // gap 1 bytes
loc_1857c: // 1040:817c
    memoryASet16(ds, 0x0b24, dx);
    dx = 0xfa00;
    if (!(ch & 0x01))
        goto loc_185ab;
    if (memoryAGet16(ds, 0x8bec) != 0x0001)
        goto loc_18595;
    dx = 0xfe00;
    goto loc_185ab;
    // gap 1 bytes
loc_18595: // 1040:8195
    if (memoryAGet16(ds, 0x8bec) != 0x0005)
        goto loc_185ab;
    ax = 0x0017;
    sub_1aecd();
    memoryASet16(ds, 0x0b24, 0xf781);
    goto loc_186c1;
loc_185ab: // 1040:81ab
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_185c5;
    if (memoryAGet16(ds, 0x7e02) != 0x0001)
        goto loc_185bc;
    goto loc_186c1;
loc_185bc: // 1040:81bc
    memoryASet16(ds, 0x7e04, 0x0000);
    goto loc_185f2;
    // gap 1 bytes
loc_185c5: // 1040:81c5
    if (memoryAGet(ds, 0xb884) & 0x10)
        goto loc_18606;
    if (!(memoryAGet(ds, 0xb884) & 0x08))
        goto loc_185f2;
    memoryASet16(ds, 0x0b24, dx);
    if (!(ch & 0x10))
        goto loc_185e1;
    goto loc_186c1;
loc_185e1: // 1040:81e1
    if (ch & 0x08)
        goto loc_185e9;
    goto loc_186c1;
loc_185e9: // 1040:81e9
    memoryASet16(ds, 0x7e06, 0x0001);
    goto loc_186c1;
loc_185f2: // 1040:81f2
    if (memoryAGet(ds, 0xb884) & 0x04)
        goto loc_185fd;
    goto loc_186c1;
loc_185fd: // 1040:81fd
    memoryASet16(ds, 0x7e04, 0x0001);
    goto loc_186c1;
loc_18606: // 1040:8206
    if (!(memoryAGet(ds, 0xb884) & 0x08))
        goto loc_18611;
    goto loc_189c2;
loc_18611: // 1040:8211
    memoryASet16(ds, 0x7e12, 0x0001);
    if (!(memoryAGet(ds, 0xb884) & 0x04))
        goto loc_18622;
    goto loc_189ff;
loc_18622: // 1040:8222
    push(ax);
    al = memoryAGet(ds, 0xb884);
    if (al != memoryAGet(ds, 0x7eca))
        goto loc_18630;
    ax = pop();
    goto loc_189de;
loc_18630: // 1040:8230
    ax = pop();
    if (!(memoryAGet(ds, 0xb884) & 0x02))
        goto loc_1866a;
    memoryASet16(ds, 0x0b36, 0x0001);
    bx = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x7ece, bx);
    memoryASet16(ds, 0x7ed0, ax);
    memoryASet16(ds, 0x7ed0, memoryAGet16(ds, 0x7ed0) + 0x0008);
    memoryASet16(ds, 0x7ecc, 0x0001);
    memoryASet16(ds, 0x7ed2, 0x000a);
    al = memoryAGet(ds, 0xb884);
    memoryASet(ds, 0x7eca, al);
    ax = 0x0022;
    sub_1aecd();
    goto loc_189de;
loc_1866a: // 1040:826a
    if (!(memoryAGet(ds, 0xb884) & 0x01))
        goto loc_186c1;
    memoryASet16(ds, 0x0b36, 0x0000);
    bx = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x7ece, bx);
    memoryASet16(ds, 0x7ece, memoryAGet16(ds, 0x7ece) + 0x0018);
    memoryASet16(ds, 0x7ed0, ax);
    memoryASet16(ds, 0x7ed0, memoryAGet16(ds, 0x7ed0) + 0x0008);
    memoryASet16(ds, 0x7ecc, 0x0001);
    memoryASet16(ds, 0x7ed2, 0x000a);
    al = memoryAGet(ds, 0xb884);
    memoryASet(ds, 0x7eca, al);
    ax = 0x0022;
    sub_1aecd();
    goto loc_189de;
loc_186a8: // 1040:82a8
    memoryASet16(ds, 0x0b20, ax);
    memoryASet(ds, 0x0b22, cl);
    al = memoryAGet(ds, 0xb884);
    al &= 0x0c;
    if (!al)
        goto loc_186c1;
    if (!(ch & 0x08))
        goto loc_186c1;
    memoryASet16(ds, 0x7e06, 0x0001);
loc_186c1: // 1040:82c1
    if (memoryAGet16(ds, 0x7e06) != 0x0001)
        goto loc_186e2;
    if (ch & 0x08)
        goto loc_186e2;
    memoryASet16(ds, 0x7e06, 0x0000);
    bp = memoryAGet16(cs, 0x0b24);
    if ((short)bp >= 0)
        goto loc_186e2;
    memoryASet16(ds, 0x0b24, 0xfe00);
loc_186e2: // 1040:82e2
    if (!(memoryAGet(ds, 0xb884) & 0x02))
        goto loc_1871e;
    memoryASet16(ds, 0x0b36, 0x0001);
    dx = 0xfffe;
    if (ch & 0x01)
        goto loc_186fb;
    goto loc_1878a;
loc_186fb: // 1040:82fb
    if (memoryAGet16(ds, 0x8bec) != 0x0004)
        goto loc_1870e;
    dx = 0xffff;
    memoryASet16(ds, 0x7e0c, 0x0001);
    goto loc_1878a;
    // gap 1 bytes
loc_1870e: // 1040:830e
    if (memoryAGet16(ds, 0x8bec) != 0x0002)
        goto loc_1878a;
    memoryASet16(ds, 0x7e0e, 0x0001);
    goto loc_1878a;
    // gap 1 bytes
loc_1871e: // 1040:831e
    if (!(memoryAGet(ds, 0xb884) & 0x01))
        goto loc_18757;
    memoryASet16(ds, 0x0b36, 0x0000);
    dx = 0x0002;
    if (!(ch & 0x01))
        goto loc_1878a;
    if (memoryAGet16(ds, 0x8bec) != 0x0004)
        goto loc_18747;
    dx = 0x0001;
    memoryASet16(ds, 0x7e0c, 0x0001);
    goto loc_1878a;
    // gap 1 bytes
loc_18747: // 1040:8347
    if (memoryAGet16(ds, 0x8bec) != 0x0002)
        goto loc_1878a;
    memoryASet16(ds, 0x7e0e, 0x0001);
    goto loc_1878a;
    // gap 1 bytes
loc_18757: // 1040:8357
    dx = 0;
    if (ch & 0x01)
        goto loc_18767;
    memoryASet16(ds, 0x0b34, 0xffff);
    goto loc_1878a;
    // gap 1 bytes
loc_18767: // 1040:8367
    if (memoryAGet16(ds, 0x8bec) == 0x0002)
        goto loc_18777;
    memoryASet16(ds, 0x0b34, 0xffff);
    goto loc_1878a;
    // gap 1 bytes
loc_18777: // 1040:8377
    memoryASet16(ds, 0x7e0a, 0x0001);
    dx = 0x0002;
    if (memoryAGet16(ds, 0x0b36) == 0x0000)
        goto loc_1878a;
    dx = 0xfffe;
loc_1878a: // 1040:838a
    dx += memoryAGet16(ds, 0x7e1a);
    bx = memoryAGet16(ds, 0x0b1e);
    bx += dx;
    if (!dx)
        goto loc_187b9;
    if ((short)dx >= 0)
        goto loc_187aa;
    if ((short)bx >= (short)0x0000)
        goto loc_187b9;
    bx = 0;
    memoryASet(ds, 0x90c2, 0x01);
    goto loc_187b9;
    // gap 1 bytes
loc_187aa: // 1040:83aa
    if ((short)bx < (short)0x00e8)
        goto loc_187b9;
    bx = 0x00e8;
    memoryASet(ds, 0x90c2, 0x02);
loc_187b9: // 1040:83b9
    ax = memoryAGet16(ds, 0x0b20);
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x7961, 0xffff);
    memoryASet16(ds, 0x795d, bx);
    memoryASet(ds, 0x796b, 0x01);
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_187db;
    sub_17d70();
    goto loc_187de;
    // gap 1 bytes
loc_187db: // 1040:83db
    sub_17dfb();
loc_187de: // 1040:83de
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_187ea;
    goto loc_168a8;
loc_187ea: // 1040:83ea
    if (!(ch & 0x02))
        goto loc_18815;
    if ((short)dx >= 0)
        goto loc_18804;
    bx += 0x000c;
    bx &= 0x00f8;
    bx -= 0x0004;
    memoryASet16(ds, 0x0b1e, bx);
    goto loc_1882b;
    // gap 1 bytes
loc_18804: // 1040:8404
    bx += 0x0003;
    bx &= 0x00f8;
    bx -= 0x0004;
    memoryASet16(ds, 0x0b1e, bx);
    goto loc_1882b;
    // gap 1 bytes
loc_18815: // 1040:8415
    memoryASet16(ds, 0x0b1e, bx);
    if (memoryAGet16(ds, 0x7e06) != 0x0001)
        goto loc_1882b;
    if (ch & 0x08)
        goto loc_1882b;
    memoryASet16(ds, 0x7e06, 0x0000);
loc_1882b: // 1040:842b
    if (memoryAGet16(ds, 0x7e00) != 0x0001)
        goto loc_1883e;
    memoryASet16(ds, 0x0b26, 0x000c);
    sub_18c83();
    goto loc_18975;
loc_1883e: // 1040:843e
    if (memoryAGet16(ds, 0x7e06) != 0x0001)
        goto loc_18865;
    memoryASet16(ds, 0x0b26, 0x001a);
    bx = memoryAGet16(ds, 0x0b1e);
    ax = memoryAGet16(ds, 0x0b20);
    ax ^= bx;
    ax &= 0x0004;
    if (ax)
        goto loc_1885c;
    goto loc_18a8f;
loc_1885c: // 1040:845c
    memoryASet16(ds, 0x0b26, 0x001b);
    goto loc_18a8f;
loc_18865: // 1040:8465
    if (memoryAGet16(ds, 0x7e08) == 0x0001)
        goto loc_18875;
    memoryASet16(ds, 0x0b26, 0x0008);
    goto loc_18975;
loc_18875: // 1040:8475
    if (!(memoryAGet16(ds, 0x7ed2) & 0x00ff))
        goto loc_18886;
    memoryASet16(ds, 0x0b26, 0x000a);
    goto loc_18975;
loc_18886: // 1040:8486
    if (memoryAGet16(ds, 0x7e10) != 0x0001)
        goto loc_18896;
    memoryASet16(ds, 0x0b26, 0x0009);
    goto loc_18975;
loc_18896: // 1040:8496
    if (memoryAGet16(ds, 0x7e14) != 0x0001)
        goto loc_188b6;
    memoryASet16(ds, 0x0b26, 0x0000);
    if (memoryAGet16(ds, 0x0b52) != 0x0000)
        goto loc_188ad;
    goto loc_18975;
loc_188ad: // 1040:84ad
    memoryASet16(ds, 0x0b26, 0x000b);
    goto loc_18975;
loc_188b6: // 1040:84b6
    if (memoryAGet16(ds, 0x7e0a) != 0x0001)
        goto loc_188d6;
    memoryASet16(ds, 0x0b26, 0x0006);
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_188cd;
    goto loc_18975;
loc_188cd: // 1040:84cd
    memoryASet16(ds, 0x0b26, 0x0000);
    goto loc_18975;
loc_188d6: // 1040:84d6
    if (!(memoryAGet(ds, 0x7eca) & 0xff))
        goto loc_188e6;
    memoryASet16(ds, 0x0b26, 0x0000);
    goto loc_18975;
loc_188e6: // 1040:84e6
    si = 0x7e2c;
    memoryASet16(ds, 0x0b26, 0x0006);
    if (memoryAGet16(ds, 0x7e04) == 0x0001)
        goto loc_188ff;
    si = 0x7e22;
    memoryASet16(ds, 0x0b26, 0x0000);
loc_188ff: // 1040:84ff
    if (memoryAGet16(ds, 0x0b34) != 0xffff)
        goto loc_1890f;
    memoryASet16(ds, 0x0b34, 0x0000);
    goto loc_18975;
    // gap 1 bytes
loc_1890f: // 1040:850f
    ax = 0x0001;
    if (memoryAGet16(ds, 0x7e0c) == 0x0001)
        goto loc_18926;
    ax = 0x0004;
    if (memoryAGet16(ds, 0x7e0e) == 0x0001)
        goto loc_18926;
    ax = 0x0002;
loc_18926: // 1040:8526
    ax += memoryAGet16(ds, 0x0b34);
    if ((short)ax < (short)0x0028)
        goto loc_18932;
    ax -= 0x0028;
loc_18932: // 1040:8532
    memoryASet16(ds, 0x0b34, ax);
    ax >>= 1;
    ax >>= 1;
    if (memoryAGet16(ds, 0x7e04) != 0x0001)
        goto loc_18950;
    if (!(ax & 0x0001))
        goto loc_1896c;
    push(ax);
    ax = 0x0026;
    sub_1aecd();
    ax = pop();
    goto loc_1896c;
    // gap 1 bytes
loc_18950: // 1040:8550
    if (ax == 0x0002)
        goto loc_18964;
    if (ax == 0x0005)
        goto loc_18964;
    if (ax == 0x0007)
        goto loc_18964;
    if (ax != 0x0000)
        goto loc_1896c;
loc_18964: // 1040:8564
    push(ax);
    ax = 0x0025;
    sub_1aecd();
    ax = pop();
loc_1896c: // 1040:856c
    si += ax;
    ax = 0;
    al = memoryAGet(ds, si);
    memoryASet16(ds, 0x0b26, ax);
loc_18975: // 1040:8575
    if (memoryAGet16(ds, 0x0b36) != 0x0000)
        goto loc_1897f;
    goto loc_18a8f;
loc_1897f: // 1040:857f
    memoryASet16(ds, 0x0b26, memoryAGet16(ds, 0x0b26) + 0x000d);
    goto loc_18a8f;
loc_18987: // 1040:8587
    ax = memoryAGet16(ds, 0x0b20);
    cl = 0;
    dx = 0;
    if (!(memoryAGet(ds, 0xb884) & 0x08))
        goto loc_1899c;
    dx = 0xfffe;
    goto loc_189a7;
    // gap 1 bytes
loc_1899c: // 1040:859c
    if (!(memoryAGet(ds, 0xb884) & 0x04))
        goto loc_189a7;
    dx = 0x0002;
loc_189a7: // 1040:85a7
    memoryASet16(ds, 0x0b24, dx);
    ax += dx;
    memoryASet16(ds, 0x7961, dx);
    memoryASet16(ds, 0x795f, ax);
    bx = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x795d, bx);
    sub_17dfb();
    goto loc_18424;
loc_189c2: // 1040:85c2
    memoryASet16(ds, 0x7e10, 0x0001);
    if (memoryAGet16(ds, 0x7e12) == 0x0000)
        goto loc_189de;
    if (!(memoryAGet16(ds, 0x6610) & 0x00ff))
        goto loc_189de;
    if (memoryAGet16(ds, 0x0b00) != 0x0001)
        goto loc_189f9;
loc_189de: // 1040:85de
    if (ch & 0x01)
        goto loc_189e6;
    goto loc_1882b;
loc_189e6: // 1040:85e6
    if (memoryAGet16(ds, 0x8bec) == 0x0002)
        goto loc_189f0;
    goto loc_1882b;
loc_189f0: // 1040:85f0
    memoryASet16(ds, 0x7e0a, 0x0001);
    goto loc_186c1;
loc_189f9: // 1040:85f9
    sub_18a9a();
    goto loc_1882b;
loc_189ff: // 1040:85ff
    memoryASet16(ds, 0x7e14, 0x0001);
    if ((short)memoryAGet16(ds, 0x0b38) >= (short)0x0001)
        goto loc_189de;
    ax = memoryAGet16(ds, 0x6612);
    if (ax)
        goto loc_18a16;
    goto loc_1882b;
loc_18a16: // 1040:8616
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_18a21;
    memoryASet16(ds, 0x6612, memoryAGet16(ds, 0x6612) - 1);
loc_18a21: // 1040:8621
    memoryASet16(ds, 0x0b38, 0x0001);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b3a, ax);
    memoryASet(ds, 0x0b3f, 0x00);
    ax = memoryAGet16(ds, 0x0b20);
    ax += 0x0005;
    memoryASet16(ds, 0x0b3c, ax);
    memoryASet(ds, 0x0b3e, 0x00);
    memoryASet16(ds, 0x0b4a, 0x0000);
    memoryASet16(ds, 0x0b50, 0x0000);
    memoryASet16(ds, 0x0b52, 0x0000);
    memoryASet16(ds, 0x0b40, 0x0100);
    memoryASet16(ds, 0x0b4e, 0x7e36);
    if (!(memoryAGet(ds, 0xb884) & 0x02))
        goto loc_18a75;
    memoryASet16(ds, 0x0b36, 0x0001);
    memoryASet16(ds, 0x0b52, 0xfe00);
    goto loc_1882b;
loc_18a75: // 1040:8675
    if (memoryAGet(ds, 0xb884) & 0x01)
        goto loc_18a80;
    goto loc_1882b;
loc_18a80: // 1040:8680
    memoryASet16(ds, 0x0b36, 0x0000);
    memoryASet16(ds, 0x0b52, 0x0200);
    goto loc_1882b;
loc_18a8f: // 1040:868f
    ax = memoryAGet16(ds, 0x0b20);
    ax -= memoryAGet16(ds, 0x7dfe);
    memoryASet16(ds, 0x6c43, ax);
    return;
    // gap 105 bytes
loc_18b03: // 1040:8703
    memoryASet16(ds, 0x7e08, 0x0000);
    memoryASet16(ds, 0x7e0a, 0x0000);
    memoryASet16(ds, 0x7e0c, 0x0000);
    memoryASet16(ds, 0x7e0e, 0x0000);
    memoryASet16(ds, 0x7e10, 0x0000);
    memoryASet16(ds, 0x7e14, 0x0000);
    memoryASet16(ds, 0x7e06, 0x0000);
    dx = memoryAGet16(ds, 0x0b24);
    dx += 0x0040;
    if ((short)dx <= (short)0x0400)
        goto loc_18b40;
    dx = 0x0400;
loc_18b40: // 1040:8740
    if (!(memoryAGet(ds, 0xb884) & 0x08))
        goto loc_18b5e;
    dx += 0xff40;
    if ((short)dx >= (short)0xfc00)
        goto loc_18b79;
    dx = 0xfc00;
    goto loc_18b79;
    // gap 1 bytes
loc_18b5e: // 1040:875e
    if (!(memoryAGet(ds, 0xb884) & 0x04))
        goto loc_18b79;
    dx += 0x0080;
    if ((short)dx <= (short)0x0400)
        goto loc_18b79;
    dx = 0x0400;
loc_18b79: // 1040:8779
    memoryASet16(ds, 0x0b24, dx);
    memoryASet16(ds, 0x7961, dx);
    if ((short)dx < 0)
        goto loc_18b8d;
    ch = 0;
    goto loc_18b8f;
    // gap 1 bytes
loc_18b8d: // 1040:878d
    ch = 0xff;
loc_18b8f: // 1040:878f
    ax = memoryAGet16(ds, 0x0b20);
    cl = memoryAGet(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    memoryASet16(ds, 0x795f, ax);
    dx = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x795d, dx);
    memoryASet(ds, 0x796b, 0x01);
    sub_17dfb();
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_18bbe;
    goto loc_168a8;
loc_18bbe: // 1040:87be
    if (ch & 0x04)
        goto loc_18beb;
    if (!(ch & 0x02))
        goto loc_18c00;
    bp = memoryAGet16(cs, 0x0b24);
    if ((short)bp >= 0)
        goto loc_18beb;
    ax |= 0x0007;
    ax++;
    dx = 0;
    cl = 0;
    memoryASet16(ds, 0x0b24, 0x0000);
    goto loc_18c00;
    // gap 1 bytes
loc_18beb: // 1040:87eb
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    dx = 0;
    cl = 0;
    memoryASet16(ds, 0x0b24, 0x0000);
loc_18c00: // 1040:8800
    memoryASet16(ds, 0x0b20, ax);
    bp = 0x0000;
    if (!(memoryAGet(ds, 0xb884) & 0x02))
        goto loc_18c1d;
    bp = 0xfffc;
    memoryASet16(ds, 0x0b36, 0x0001);
    goto loc_18c31;
    // gap 1 bytes
loc_18c1d: // 1040:881d
    if (!(memoryAGet(ds, 0xb884) & 0x01))
        goto loc_18c31;
    bp = 0x0004;
    memoryASet16(ds, 0x0b36, 0x0000);
loc_18c31: // 1040:8831
    bx = memoryAGet16(ds, 0x0b1e);
    bx += bp;
    if (!bp)
        goto loc_18c69;
    if ((short)bp >= 0)
        goto loc_18c57;
    if ((short)bx >= (short)0x0000)
        goto loc_18c69;
    bx = 0x0000;
    memoryASet(ds, 0x90c2, 0x01);
    goto loc_18c69;
    // gap 1 bytes
loc_18c57: // 1040:8857
    if ((short)bx < (short)0x00e8)
        goto loc_18c69;
    bx = 0x00e8;
    memoryASet(ds, 0x90c2, 0x02);
loc_18c69: // 1040:8869
    ax = memoryAGet16(ds, 0x0b20);
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x7961, 0xffff);
    memoryASet(ds, 0x796b, 0x01);
    memoryASet16(ds, 0x795d, bx);
    dx = bp;
    goto loc_187db;
    // gap 791 bytes
loc_18f9a: // 1040:8b9a
    dx = memoryAGet16(ds, 0x0b24);
    dx += 0x0080;
    memoryASet16(ds, 0x0b24, dx);
    if ((short)dx < 0)
        goto loc_18faf;
    ch = 0;
    goto loc_18fb1;
    // gap 1 bytes
loc_18faf: // 1040:8baf
    ch = 0xff;
loc_18fb1: // 1040:8bb1
    ax = memoryAGet16(ds, 0x0b20);
    cl = memoryAGet(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    if ((short)ax <= (short)0x0110)
        goto loc_18fca;
    memoryASet16(ds, 0x7e18, 0x0001);
    return;
loc_18fca: // 1040:8bca
    memoryASet16(ds, 0x0b20, ax);
    memoryASet(ds, 0x0b22, cl);
    al = memoryAGet(ds, 0x8b98);
    al = ~al;
    memoryASet(ds, 0x8b98, al);
    al &= 0x01;
    ax += 0x001c;
    memoryASet16(ds, 0x0b26, ax);
    ax = memoryAGet16(ds, 0x7e1c);
    ax += memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b1e, ax);
}
void sub_18a9a() // 1040:869a
{
    ax = memoryAGet16(ds, 0x6610);
    if (!ax)
        goto loc_18ae9;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_18ab2;
    memoryASet16(ds, 0x6610, memoryAGet16(ds, 0x6610) - 1);
loc_18ab2: // 1040:86b2
    ax = 0x000d;
    sub_1aecd();
    memoryASet16(ds, 0x0b00, 0x0001);
    ax = memoryAGet16(ds, 0x0b20);
    ax += 0x0007;
    memoryASet16(ds, 0x0b04, ax);
    if (memoryAGet16(ds, 0x0b36) != 0x0000)
        goto loc_18aea;
    memoryASet16(ds, 0x0b1a, 0x0008);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b02, ax);
    memoryASet16(ds, 0x0b0a, 0x001f);
    memoryASet16(ds, 0x7e12, 0x0000);
loc_18ae9: // 1040:86e9
    return;
loc_18aea: // 1040:86ea
    memoryASet16(ds, 0x0b1a, 0xfff8);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b02, ax);
    memoryASet16(ds, 0x0b0a, 0x001e);
    memoryASet16(ds, 0x7e12, 0x0000);
}
void sub_18c83() // 1040:8883
{
    goto loc_18c83;
loc_18a9a: // 1040:869a
    ax = memoryAGet16(ds, 0x6610);
    if (!ax)
        goto loc_18ae9;
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_18ab2;
    memoryASet16(ds, 0x6610, memoryAGet16(ds, 0x6610) - 1);
loc_18ab2: // 1040:86b2
    ax = 0x000d;
    sub_1aecd();
    memoryASet16(ds, 0x0b00, 0x0001);
    ax = memoryAGet16(ds, 0x0b20);
    ax += 0x0007;
    memoryASet16(ds, 0x0b04, ax);
    if (memoryAGet16(ds, 0x0b36) != 0x0000)
        goto loc_18aea;
    memoryASet16(ds, 0x0b1a, 0x0008);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b02, ax);
    memoryASet16(ds, 0x0b0a, 0x001f);
    memoryASet16(ds, 0x7e12, 0x0000);
loc_18ae9: // 1040:86e9
    return;
loc_18aea: // 1040:86ea
    memoryASet16(ds, 0x0b1a, 0xfff8);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x0b02, ax);
    memoryASet16(ds, 0x0b0a, 0x001e);
    memoryASet16(ds, 0x7e12, 0x0000);
    return;
    // gap 384 bytes
loc_18c83: // 1040:8883
    if (memoryAGet(ds, 0xb884) & 0x10)
        goto loc_18c95;
    memoryASet16(ds, 0x7e12, 0x0001);
    return;
loc_18c95: // 1040:8895
    memoryASet16(ds, 0x7e10, 0x0001);
    if (memoryAGet16(ds, 0x7e12) == 0x0000)
        goto loc_18cbd;
    if (!(memoryAGet16(ds, 0x6610) & 0x00ff))
        goto loc_18cbd;
    if (memoryAGet16(ds, 0x0b00) == 0x0001)
        goto loc_18cbd;
    goto loc_18a9a;
loc_18cbd: // 1040:88bd
    return;
}
void sub_18cbe() // 1040:88be
{
    if (memoryAGet16(ds, 0x0b00) == 0x0001)
        goto loc_18cc9;
    return;
loc_18cc9: // 1040:88c9
    dx = 0x0004;
    ax = memoryAGet16(ds, 0x0b1a);
    if ((short)ax < 0)
        goto loc_18cd9;
    dx = 0x0014;
loc_18cd9: // 1040:88d9
    ax += memoryAGet16(ds, 0x0b02);
    dx += ax;
    if ((short)dx < (short)0x0003)
        goto loc_18d21;
    if ((short)dx > (short)0x00fc)
        goto loc_18d21;
    memoryASet16(ds, 0x795d, dx);
    cx = memoryAGet16(ds, 0x0b04);
    memoryASet16(ds, 0x795f, cx);
    memoryASet16(ds, 0x795f, memoryAGet16(ds, 0x795f) + 0x0004);
    sub_18014();
    push(ax);
    sub_181c6();
    ax = pop();
    ch = memoryAGet(ds, 0x7963);
    if (ch & 0x02)
        goto loc_18d21;
    if (ch & 0x40)
        goto loc_18d21;
    memoryASet16(ds, 0x0b02, ax);
    return;
loc_18d21: // 1040:8921
    memoryASet16(ds, 0x0b00, 0x0000);
}
void sub_18d28() // 1040:8928
{
    bool temp_cf;

    memoryASet16(ds, 0x7e1e, 0x0000);
    if ((short)memoryAGet16(ds, 0x0b38) >= (short)0x0001)
        goto loc_18d39;
    return;
loc_18d39: // 1040:8939
    if ((short)memoryAGet16(ds, 0x0b38) <= (short)0x0001)
        goto loc_18d3e;
    goto loc_18f57;
loc_18d3e: // 1040:893e
    si = 0x0b38;
    sub_1718e();
    if (!flags.carry)
        goto loc_18d49;
    goto loc_18f3a;
loc_18d49: // 1040:8949
    dx = memoryAGet16(ds, 0x0b40);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_18d5a;
    dx = 0x0800;
loc_18d5a: // 1040:895a
    memoryASet16(ds, 0x0b40, dx);
    memoryASet16(ds, 0x7961, dx);
    if ((short)dx < 0)
        goto loc_18d6b;
    ch = 0;
    goto loc_18d6d;
    // gap 1 bytes
loc_18d6b: // 1040:896b
    ch = 0xff;
loc_18d6d: // 1040:896d
    ax = memoryAGet16(ds, 0x0b3c);
    cl = memoryAGet(ds, 0x0b3e);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (al + dh + flags.carry) >= 0x100;
    al += dh + flags.carry;
    flags.carry = temp_cf;
    ah += ch + flags.carry;
    dx = ax;
    if ((short)dx <= (short)0x0171)
        goto loc_18d85;
    goto loc_18f91;
loc_18d85: // 1040:8985
    if ((short)dx >= (short)0x0000)
        goto loc_18d8d;
    goto loc_18f91;
loc_18d8d: // 1040:898d
    memoryASet16(ds, 0x795f, dx);
    ax = memoryAGet16(ds, 0x0b3a);
    memoryASet16(ds, 0x795d, ax);
    memoryASet(ds, 0x796b, 0x01);
    sub_1802d();
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x40))
        goto loc_18dec;
    dx = 0;
    ax = memoryAGet16(ds, 0x7964);
    cl = 0;
    ax -= 0x0010;
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x0b3c, ax);
    memoryASet(ds, 0x0b3e, 0x00);
    push(ax);
    ax = memoryAGet16(ds, 0x7966);
    memoryASet16(ds, 0x7e1e, ax);
    ax = pop();
    memoryASet(ds, 0x796b, 0x00);
    sub_1802d();
    ch = memoryAGet(ds, 0x7963);
    if (ch & 0x20)
        goto loc_18de4;
    if (ch & 0x06)
        goto loc_18e08;
    memoryASet16(ds, 0x0b40, 0x0100);
    goto loc_18e5a;
    // gap 1 bytes
loc_18de4: // 1040:89e4
    if (!(ch & 0x20))
        goto loc_18dec;
    goto loc_18f3a;
loc_18dec: // 1040:89ec
    if (ch & 0x04)
        goto loc_18e11;
    if (ch & 0x02)
        goto loc_18e01;
    memoryASet16(ds, 0x0b3c, dx);
    memoryASet(ds, 0x0b3e, cl);
    goto loc_18e5a;
    // gap 1 bytes
loc_18e01: // 1040:8a01
    ax = memoryAGet16(ds, 0x0b40);
    if ((short)ax >= 0)
        goto loc_18e11;
loc_18e08: // 1040:8a08
    dx |= 0x0007;
    dx++;
    cl = 0;
    goto loc_18e18;
    // gap 1 bytes
loc_18e11: // 1040:8a11
    dx--;
    dx &= 0x0ff8;
    cl = 0;
loc_18e18: // 1040:8a18
    memoryASet16(ds, 0x0b3c, dx);
    memoryASet(ds, 0x0b3e, cl);
    if (!(ch & 0x20))
        goto loc_18e28;
    goto loc_18f3a;
loc_18e28: // 1040:8a28
    if (!(ch & 0x01))
        goto loc_18e54;
    if (memoryAGet16(ds, 0x8bec) != 0x0003)
        goto loc_18e47;
    ax = memoryAGet16(ds, 0x0b40);
    if ((short)ax < (short)0x0200)
        goto loc_18e54;
    ax = -ax;
    ax += 0x0060;
    memoryASet16(ds, 0x0b40, ax);
    goto loc_18e5a;
    // gap 1 bytes
loc_18e47: // 1040:8a47
    if (memoryAGet16(ds, 0x8bec) != 0x0005)
        goto loc_18e54;
    ax = 0xf781;
    goto loc_18e57;
    // gap 1 bytes
loc_18e54: // 1040:8a54
    ax = 0x0100;
loc_18e57: // 1040:8a57
    memoryASet16(ds, 0x0b40, ax);
loc_18e5a: // 1040:8a5a
    dx = memoryAGet16(ds, 0x0b52);
    bx = 0x0008;
    if (!(ch & 0x01))
        goto loc_18e7e;
    if (memoryAGet16(ds, 0x8bec) == 0x0001)
        goto loc_18e92;
    if (memoryAGet16(ds, 0x8bec) == 0x0002)
        goto loc_18ead;
    if (memoryAGet16(ds, 0x8bec) != 0x0004)
        goto loc_18e7e;
    bx = 0x0010;
loc_18e7e: // 1040:8a7e
    bp = memoryAGet16(cs, 0x0b52);
    if ((short)bp < 0)
        goto loc_18e8e;
    dx -= bx;
    if ((short)dx >= 0)
        goto loc_18e94;
    goto loc_18e92;
    // gap 1 bytes
loc_18e8e: // 1040:8a8e
    dx += bx;
    if ((short)dx < 0)
        goto loc_18e94;
loc_18e92: // 1040:8a92
    dx = 0;
loc_18e94: // 1040:8a94
    memoryASet16(ds, 0x0b52, dx);
    ax = memoryAGet16(ds, 0x7e1e);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx += ax;
loc_18ead: // 1040:8aad
    bx = memoryAGet16(ds, 0x0b3a);
    cl = memoryAGet(ds, 0x0b3f);
    ax = memoryAGet16(ds, 0x0b3c);
    memoryASet16(ds, 0x795f, ax);
    memoryASet16(ds, 0x7961, 0xffff);
    if ((short)dx < 0)
        goto loc_18eca;
    ch = 0;
    goto loc_18ecc;
    // gap 1 bytes
loc_18eca: // 1040:8aca
    ch = 0xff;
loc_18ecc: // 1040:8acc
    bx = memoryAGet16(ds, 0x0b3a);
    cl = memoryAGet(ds, 0x0b3f);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    temp_cf = (bl + dh + flags.carry) >= 0x100;
    bl += dh + flags.carry;
    flags.carry = temp_cf;
    bh += ch + flags.carry;
    if ((short)bx < (short)0x00e8)
        goto loc_18eee;
    cl = 0;
    bx = 0x00e8;
    memoryASet16(ds, 0x0b52, 0x0000);
    goto loc_18efd;
    // gap 1 bytes
loc_18eee: // 1040:8aee
    if ((short)bx >= (short)0x0000)
        goto loc_18efd;
    cl = 0;
    bx = 0;
    memoryASet16(ds, 0x0b52, 0x0000);
loc_18efd: // 1040:8afd
    memoryASet16(ds, 0x795d, bx);
    memoryASet(ds, 0x796b, 0x01);
    sub_1802d();
    ch = memoryAGet(ds, 0x7963);
    if (!(ch & 0x02))
        goto loc_18f2c;
    cl = 0;
    bp = memoryAGet16(ds, 0x0b52);
    bp += memoryAGet16(ds, 0x7e1e);
    if ((short)bp >= 0)
        goto loc_18f27;
    bx |= 0x0007;
    bx++;
    goto loc_18f2c;
    // gap 1 bytes
loc_18f27: // 1040:8b27
    bx--;
    bx &= 0x00f8;
loc_18f2c: // 1040:8b2c
    memoryASet16(ds, 0x0b3a, bx);
    memoryASet(ds, 0x0b3f, cl);
    if (ch & 0x20)
        goto loc_18f3a;
    return;
loc_18f3a: // 1040:8b3a
    memoryASet16(ds, 0x0b38, 0x0002);
    memoryASet16(ds, 0x0b50, 0x0000);
    memoryASet16(ds, 0x0b4e, 0x7eb2);
    memoryASet16(ds, 0x0b3c, memoryAGet16(ds, 0x0b3c) - 0x0005);
    memoryASet16(ds, 0x0b4a, 0x0000);
loc_18f57: // 1040:8b57
    si = 0x0b38;
    memoryASet16(ds, 0x0b4a, memoryAGet16(ds, 0x0b4a) + 1);
    if ((char)memoryAGet(ds, 0x0b4a) <= (char)0x01)
        goto loc_18f8c;
    if ((char)memoryAGet(ds, 0x0b4a) > (char)0x04)
        goto loc_18f8c;
    dx = memoryAGet16(ds, 0x0b3a);
    dx -= 0x0004;
    if ((short)dx >= 0)
        goto loc_18f77;
    dx = 0;
loc_18f77: // 1040:8b77
    tl = dh; dh = dl; dl = tl;
    bx = memoryAGet16(ds, 0x0b3c);
    bx -= 0x0004;
    dl = 0x20;
    ah = 0x1c;
    sub_16407();
    if (!flags.carry)
        goto loc_18f8c;
    sub_168a8();
loc_18f8c: // 1040:8b8c
    sub_1718e();
    if (!flags.carry)
        goto loc_18f97;
loc_18f91: // 1040:8b91
    memoryASet16(ds, 0x0b38, 0x0000);
loc_18f97: // 1040:8b97
    return;
}
void sub_19214() // 1040:8e14
{
    bx = memoryAGet16(ds, 0x8bf6);
    di = 0x563c;
    cx = 0x000a;
    dx = memoryAGet16(ds, 0x8bf0);
    dx &= 0xfff8;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    ax = dx;
    dx &= 0xfffc;
    dx >>= 1;
    dx >>= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    bx += dx;
    memoryASet16(ds, 0x8bf8, bx);
    ax &= 0x0003;
    memoryASet16(ds, 0x8bfa, ax);
    if (!ax)
        goto loc_19257;
    dx = 0x0004;
    dx -= ax;
    push(cx);
    sub_1926d();
    cx = pop();
    goto loc_1925c;
    // gap 1 bytes
loc_19257: // 1040:8e57
    push(cx);
    sub_192ae();
    cx = pop();
loc_1925c: // 1040:8e5c
    if (--cx)
        goto loc_19257;
    dx = memoryAGet16(ds, 0x8bfa);
    if (!dx)
        goto loc_1926c;
    ax = 0x0000;
    sub_1926d();
loc_1926c: // 1040:8e6c
    return;
}
void sub_1926d() // 1040:8e6d
{
    push(di);
    push(dx);
    ax <<= 1;
    ax <<= 1;
    cx = 0x0008;
loc_19276: // 1040:8e76
    push(cx);
    push(ax);
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    ax <<= 1;
    si = 0x8c14;
    si += ax;
    ax = pop();
    si = memoryAGet16(ds, si);
    si += ax;
    bp = di;
    push(dx);
loc_1928c: // 1040:8e8c
    cx = 0x0004;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di += 0x001c;
    dx--;
    if (dx)
        goto loc_1928c;
    dx = pop();
    di = bp;
    di += 0x0004;
    cx = pop();
    if (--cx)
        goto loc_19276;
    dx = pop();
    di = pop();
    dx--;
    dx &= 0x0003;
    dx++;
    cl = 0x05;
    dx <<= cl;
    di += dx;
}
void sub_192ae() // 1040:8eae
{
    cx = 0x0008;
loc_192b1: // 1040:8eb1
    bp = cx;
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    ax <<= 1;
    si = 0x8c14;
    si += ax;
    si = memoryAGet16(ds, si);
    dx = 0x0004;
loc_192c4: // 1040:8ec4
    cx = 0x0004;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di += 0x001c;
    dx--;
    if (dx)
        goto loc_192c4;
    di += 0xff84;
    cx = bp;
    if (--cx)
        goto loc_192b1;
    di += 0x0060;
}
void sub_192da() // 1040:8eda
{
    di = 0x563c;
    si = 0x565c;
    cx = 0x0270;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, 0x8bfa);
    dx = 0x0001;
    bx = memoryAGet16(ds, 0x8bf8);
    bx += 0x0050;
    di = 0x5b1c;
    sub_1926d();
    memoryASet16(ds, 0x8bfa, memoryAGet16(ds, 0x8bfa) + 0x0001);
    memoryASet16(ds, 0x8bfa, memoryAGet16(ds, 0x8bfa) & 0x0003);
    if (memoryAGet16(ds, 0x8bfa))
        goto loc_19309;
    memoryASet16(ds, 0x8bf8, memoryAGet16(ds, 0x8bf8) + 0x0008);
loc_19309: // 1040:8f09
    return;
}
void sub_1930a() // 1040:8f0a
{
    si = 0x5b1a;
    di = 0x5b3a;
    flags.direction = 1;
    cx = 0x0270;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    flags.direction = 0;
    bx = memoryAGet16(ds, 0x8bf8);
    memoryASet16(ds, 0x8bfa, memoryAGet16(ds, 0x8bfa) - 1);
    memoryASet16(ds, 0x8bfa, memoryAGet16(ds, 0x8bfa) & 0x0003);
    if (memoryAGet16(ds, 0x8bfa) != 0x0003)
        goto loc_19332;
    bx -= 0x0008;
    memoryASet16(ds, 0x8bf8, bx);
loc_19332: // 1040:8f32
    di = 0x563c;
    ax = memoryAGet16(ds, 0x8bfa);
    dx = 0x0001;
    sub_1926d();
}
void sub_1933f() // 1040:8f3f
{
    ax = 0x3c74;
    di = 0x8c14;
    dx = 0x0010;
    cx = 0x0100;
loc_1934b: // 1040:8f4b
    stosw<ES_DI>(ax);
    ax += dx;
    if (--cx)
        goto loc_1934b;
}
void sub_19351() // 1040:8f51
{
    memoryASet16(ds, 0x0b00, 0x0000);
    memoryASet16(ds, 0x0b38, 0x0000);
    push(ax);
    ax = memoryAGet16(ds, 0x0b1e);
    memoryASet16(ds, 0x8c00, ax);
    ax = memoryAGet16(ds, 0x0b20);
    memoryASet16(ds, 0x8c02, ax);
    ax = memoryAGet16(ds, 0x0b24);
    memoryASet16(ds, 0x8c08, ax);
    al = memoryAGet(ds, 0x0b22);
    memoryASet(ds, 0x8c12, al);
    ax = memoryAGet16(ds, 0x7e02);
    memoryASet16(ds, 0x8c0a, ax);
    ax = memoryAGet16(ds, 0x7e04);
    memoryASet16(ds, 0x8c0c, ax);
    ax = memoryAGet16(ds, 0x0b36);
    memoryASet16(ds, 0x8c0e, ax);
    ax = memoryAGet16(ds, 0x7e00);
    memoryASet16(ds, 0x8c10, ax);
    ax = pop();
    memoryASet16(ds, 0x8c04, ax);
    memoryASet16(ds, 0x8c06, dx);
    si = 0x4c74;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    ax = 0;
    ax += memoryAGet16(ds, si);
    si++;
    si++;
    tl = ah; ah = al; al = tl;
    ax += 0x3374;
    memoryASet16(ds, 0x8bf6, ax);
    memoryASet16(ds, 0x8bf2, 0x0000);
    ax = memoryAGet16(ds, si);
    si++;
    si++;
    tl = ah; ah = al; al = tl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x8bf4, ax);
    ax = memoryAGet16(ds, si);
    si++;
    si++;
    tl = ah; ah = al; al = tl;
    ax += 0x4c74;
    memoryASet16(ds, 0x8bfe, ax);
    ax = memoryAGet16(ds, si);
    si++;
    si++;
    tl = ah; ah = al; al = tl;
    ax += 0x4c74;
    memoryASet16(ds, 0x8bfc, ax);
    memoryASet16(ds, 0x8bf0, dx);
    sub_19577();
}
void sub_19420() // 1040:9020
{
    si = 0x8fe4;
    ax = memoryAGet16(ds, 0x8bec);
    ax--;
    ax <<= 1;
    si += ax;
    si = memoryAGet16(ds, si);
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0x0b1e, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x0b20, ax);
    ax = memoryAGet16(ds, si + 4);
    dx = memoryAGet16(ds, si + 6);
    cx = memoryAGet16(ds, si + 8);
    memoryASet16(ds, 0x0b36, cx);
    sub_19351();
    sub_19214();
    sub_19577();
    sub_17047();
    sub_15fe4();
    memoryASet(ds, 0x5b3e, 0x01);
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
}
void sub_19462() // 1040:9062
{
    ax = memoryAGet16(ds, 0x8c00);
    memoryASet16(ds, 0x0b1e, ax);
    ax = memoryAGet16(ds, 0x8c02);
    memoryASet16(ds, 0x0b20, ax);
    ax = memoryAGet16(ds, 0x8c08);
    memoryASet16(ds, 0x0b24, ax);
    al = memoryAGet(ds, 0x8c12);
    memoryASet(ds, 0x0b22, al);
    ax = memoryAGet16(ds, 0x8c0a);
    memoryASet16(ds, 0x7e02, ax);
    ax = memoryAGet16(ds, 0x8c0c);
    memoryASet16(ds, 0x7e04, ax);
    ax = memoryAGet16(ds, 0x8c0e);
    memoryASet16(ds, 0x0b36, ax);
    ax = memoryAGet16(ds, 0x8c10);
    memoryASet16(ds, 0x7e00, ax);
    ax = memoryAGet16(ds, 0x8c04);
    dx = memoryAGet16(ds, 0x8c06);
    sub_19351();
    sub_19214();
    sub_19577();
    sub_17047();
    memoryASet16(ds, 0x6612, 0x0006);
    memoryASet16(ds, 0x6610, 0x0006);
    sub_15fe4();
    memoryASet(ds, 0x5b3e, 0x01);
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
}
void sub_194c4() // 1040:90c4
{
    sp -= 2;
    al = memoryAGet(ds, 0x90c2);
    if (al)
        goto loc_194cc;
    sp += 2;
    return;
loc_194cc: // 1040:90cc
    si = memoryAGet16(ds, 0x8bfe);
loc_194d0: // 1040:90d0
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_19552;
    al &= 0x03;
    if (al != memoryAGet(ds, 0x90c2))
        goto loc_194f6;
    ax = memoryAGet16(ds, 0x8bf0);
    ax &= 0xfff8;
    ax += memoryAGet16(ds, 0x0b20);
    ax += 0x0014;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if (al == memoryAGet(ds, si + 1))
        goto loc_194fb;
loc_194f6: // 1040:90f6
    si += 0x0004;
    goto loc_194d0;
loc_194fb: // 1040:90fb
    al = memoryAGet(ds, si);
    ah = al;
    ah &= 0x90;
    if (ah != 0x90)
        goto loc_1950a;
    goto loc_19650;
loc_1950a: // 1040:910a
    if (!(al & 0x40))
        goto loc_19514;
    memoryASet16(ds, 0x762d, 0x0001);
loc_19514: // 1040:9114
    if (!(al & 0x20))
        goto loc_19521;
    memoryASet16(ds, 0x7e00, 0x0001);
    goto loc_19527;
    // gap 1 bytes
loc_19521: // 1040:9121
    memoryASet16(ds, 0x7e00, 0x0000);
loc_19527: // 1040:9127
    cx = 0;
    al = memoryAGet(ds, si + 2);
    dx = 0;
    dl = memoryAGet(ds, si + 3);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    cx = memoryAGet16(ds, 0x0b20);
    cx += 0x0014;
    cx &= 0xfff8;
    dx -= cx;
    cx = memoryAGet16(ds, 0x8bf0);
    cx &= 0x0007;
    dx &= 0xfff8;
    dx |= cx;
    sub_19553();
loc_19552: // 1040:9152
    sp += 2;
    return;
    // gap 253 bytes
loc_19650: // 1040:9250
    indirectCall(cs, memoryAGet16(ds, 0x003c)); // 1040:9250;
    ax = memoryAGet16(ds, 0x8bec);
    if (ax != 0x0004)
        goto loc_19687;
    if (memoryAGet16(ds, 0x95c4) == 0x0001)
        goto loc_19673;
    if (memoryAGet16(ds, 0x8bee) == 0x0001)
        goto loc_19673;
    ax = 0x0001;
    sub_1a257();
    sub_19f12();
    return;
loc_19673: // 1040:9273
    memoryASet16(ds, 0x8bec, memoryAGet16(ds, 0x8bec) + 1);
    if (memoryAGet16(ds, 0x8bec) != 0x0005)
        goto loc_19684;
    memoryASet16(ds, 0x95c4, 0x0001);
loc_19684: // 1040:9284
    goto loc_1c3b9;
loc_19687: // 1040:9287
    if (memoryAGet16(ds, 0x8bec) != 0x0005)
        goto loc_196a7;
    if (memoryAGet16(ds, 0x8bee) != 0x0001)
        goto loc_19698;
    goto loc_19f37;
loc_19698: // 1040:9298
    memoryASet16(ds, 0x95c4, 0x0001);
    ax = 0x0001;
    sub_1a257();
    sub_19f12();
    return;
loc_196a7: // 1040:92a7
    memoryASet16(ds, 0x8bec, memoryAGet16(ds, 0x8bec) + 1);
    goto loc_1c3b9;
    // gap 2185 bytes
loc_19f37: // 1040:9b37
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:9b37;
    ax = 0x0004;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0006;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0002;
    sub_1a257();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    sub_1c359();
    return;
    // gap 9306 bytes
loc_1c3b9: // 1040:bfb9
    sp = memoryAGet16(ds, 0xc0df);
    memoryASet16(ds, 0x6610, 0x0006);
    memoryASet16(ds, 0x6612, 0x0006);
    memoryASet16(ds, 0x7e00, 0x0000);
    memoryASet16(ds, 0x762d, 0x0000);
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    indirectCall(cs, memoryAGet16(ds, 0x0004)); // 1040:bfe3;
    indirectCall(cs, memoryAGet16(ds, 0x0006)); // 1040:bfe7;
    sub_1a45c();
    sub_1c4e2();
    indirectCall(cs, memoryAGet16(ds, 0x0042)); // 1040:bff1;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bff5;
    indirectCall(cs, memoryAGet16(ds, 0x003c)); // 1040:bff9;
    indirectCall(cs, memoryAGet16(ds, 0x0048)); // 1040:bffd;
    ax = 0x0004;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = memoryAGet16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:c026;
    sub_19420();
    memoryASet16(ds, 0x973c, 0x3245);
    memoryASet16(ds, 0x973e, 0x5432);
loc_1c439: // 1040:c039
    memoryASet16(ds, 0x7e16, 0x0000);
    memoryASet16(ds, 0x7e18, 0x0000);
loc_1c445: // 1040:c045
    sub_16b3b();
    if (memoryAGet16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memoryASet16(ds, 0x762f, 0x0000);
    sub_1618f();
    sub_19462();
    if (memoryAGet16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    sub_19f12();
    return;
loc_1c465: // 1040:c065
    goto loc_1c439;
loc_1c467: // 1040:c067
    sub_19bac();
    sub_15f40();
    memoryASet(ds, 0x5b3e, 0x00);
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    indirectCall(cs, memoryAGet16(ds, 0x001e)); // 1040:c087;
    indirectCall(cs, memoryAGet16(ds, 0x0024)); // 1040:c08b;
    indirectCall(cs, memoryAGet16(ds, 0x003e)); // 1040:c08f;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:c093;
    sub_19af6();
    indirectCall(cs, memoryAGet16(ds, 0x0038)); // 1040:c09a;
    sub_194c4();
    if (memoryAGet(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    sub_1c359();
    return;
loc_1c4b3: // 1040:c0b3
    if (memoryAGet(ds, 0xb888) != 0x01)
        goto loc_1c445;
    sub_196f3();
    return;
}
void sub_19553() // 1040:9153
{
    bx = memoryAGet16(ds, 0x0b1e);
    if (bx)
        goto loc_19568;
    memoryASet16(ds, 0x0b1e, 0x00e8);
    indirectCall(cs, memoryAGet16(ds, 0x0020)); // 1040:9161;
    goto loc_19572;
    // gap 1 bytes
loc_19568: // 1040:9168
    memoryASet16(ds, 0x0b1e, 0x0000);
    indirectCall(cs, memoryAGet16(ds, 0x0022)); // 1040:916e;
loc_19572: // 1040:9172
    return;
}
void sub_19577() // 1040:9177
{
    memoryASet16(ds, 0x9173, 0x0000);
    si = 0x54fa;
    memoryASet16(ds, 0x9175, si);
loc_19584: // 1040:9184
    al = memoryAGet(ds, si);
    if ((char)al < 0)
        goto loc_19592;
    memoryASet(ds, si, 0x00);
    si += 0x0008;
    goto loc_19584;
loc_19592: // 1040:9192
    return;
}
void sub_19593() // 1040:9193
{
    push(ds);
    push(es);
    push(di);
    push(ax);
    push(cs);
    ds = pop();
    if ((short)memoryAGet16(ds, 0x9173) < (short)0x0028)
        goto loc_195a5;
    ax = pop();
    di = pop();
    es = pop();
    ds = pop();
    return;
loc_195a5: // 1040:91a5
    dx = 0;
    dl = al;
    dx -= 0x00f8;
    dx += dx;
    dx += dx;
    ax = 0;
    sub_19b40();
    al = memoryAGet(ds, 0x973f);
    cbw();
    al &= 0x03;
    dx += ax;
    ax = 0;
    si = 0x54fa;
loc_195c3: // 1040:91c3
    al = memoryAGet(ds, si);
    if ((char)al < 0)
        goto loc_195e0;
    if (al)
        goto loc_195e5;
    memoryASet(ds, si, 0x01);
    si++;
    memoryASet(ds, si, dl);
    si++;
    memoryASet16(ds, si, bx);
    si++;
    si++;
    memoryASet16(ds, si, di);
    si++;
    si++;
    memoryASet16(ds, si, bp);
    memoryASet16(ds, 0x9173, memoryAGet16(ds, 0x9173) + 1);
loc_195e0: // 1040:91e0
    ax = pop();
    di = pop();
    es = pop();
    ds = pop();
    return;
loc_195e5: // 1040:91e5
    si += 0x0008;
    goto loc_195c3;
}
void sub_195ea() // 1040:91ea
{
    if (memoryAGet16(ds, 0x9173) != 0x0000)
        goto loc_195f2;
    return;
loc_195f2: // 1040:91f2
    si = 0x54fa;
loc_195f5: // 1040:91f5
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_19617;
    if ((char)al < 0)
        goto loc_1961c;
    ax = memoryAGet16(ds, si + 2);
    ax += 0x0020;
    if ((short)ax < (short)0x5a7c)
        goto loc_19614;
    memoryASet(ds, si, 0x00);
    memoryASet16(ds, 0x9173, memoryAGet16(ds, 0x9173) - 1);
    si += 0x0008;
    goto loc_195f5;
loc_19614: // 1040:9214
    memoryASet16(ds, si + 2, ax);
loc_19617: // 1040:9217
    si += 0x0008;
    goto loc_195f5;
loc_1961c: // 1040:921c
    return;
}
void sub_1961d() // 1040:921d
{
    if (memoryAGet16(ds, 0x9173) != 0x0000)
        goto loc_19625;
    return;
loc_19625: // 1040:9225
    si = 0x54fa;
loc_19628: // 1040:9228
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_1964a;
    if ((char)al < 0)
        goto loc_1964f;
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0020;
    if ((short)ax >= (short)0x573c)
        goto loc_19647;
    memoryASet(ds, si, 0x00);
    memoryASet16(ds, 0x9173, memoryAGet16(ds, 0x9173) - 1);
    si += 0x0008;
    goto loc_19628;
loc_19647: // 1040:9247
    memoryASet16(ds, si + 2, ax);
loc_1964a: // 1040:924a
    si += 0x0008;
    goto loc_19628;
loc_1964f: // 1040:924f
    return;
}
void sub_196dd() // 1040:92dd
{
    indirectCall(cs, memoryAGet16(ds, 0x0000)); // 1040:92dd;
    sub_1933f();
    indirectCall(cs, memoryAGet16(ds, 0x0010)); // 1040:92e4;
    indirectCall(cs, memoryAGet16(ds, 0x0018)); // 1040:92e8;
    sub_1adcb();
    sub_1bc92();
}
void sub_196f3() // 1040:92f3 +isolate
{
    flags.interrupts = 0;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = 1;
    al = memoryAGet(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memoryAGet16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
    // gap 1 bytes
loc_1970f: // 1040:930f
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0000;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
loc_1972d: // 1040:932d
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
}
void sub_19731() // 1040:9331 +isolate
{
    ah = 0x09;
    dx = 0x1040;
    ds = dx;
    dx = 0x92b1;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
}
void sub_199c8() // 1040:95c8
{
    memoryASet(ds, 0x95ad, 0x01);
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:95cd;
    ax = 0x0706;
    memoryASet16(ds, 0x69f0, ax);
    memoryASet16(ds, 0x69f2, ax);
    sub_16e39();
    ax = 0x0008;
    si = 0x9461;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:95e3;
    ax = 0x0108;
    si = 0x9481;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:95ed;
    ax = 0x0208;
    si = 0x94a1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:95f7;
    bx = 0x95b5;
    sub_19c43();
    push(cs);
    ds = pop();
    if (memoryAGet16(ds, 0x95c4) != 0x0001)
        goto loc_19a10;
    bx = 0x95bf;
    sub_19c43();
loc_19a10: // 1040:9610
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9610;
    ax = 0x0008;
    si = 0x9461;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:961a;
    ax = 0x0108;
    si = 0x9481;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:9624;
    ax = 0x0208;
    si = 0x94a1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:962e;
    bx = 0x95b5;
    sub_19c43();
    if (memoryAGet16(ds, 0x95c4) != 0x0001)
        goto loc_19a45;
    bx = 0x95bf;
    sub_19c43();
loc_19a45: // 1040:9645
    memoryASet(ds, 0x97da, 0x01);
loc_19a4b: // 1040:964b
    sync(); // X Y Z
    sub_19bdc();
    if (!(al & 0x10))
        goto loc_19a55;
    goto loc_19ae0;
loc_19a55: // 1040:9655
    if (al == memoryAGet(ds, 0x95c3))
        goto loc_19a4b;
    memoryASet(ds, 0x95c3, al);
    if (!(al & 0x08))
        goto loc_19a9e;
    dx = memoryAGet16(ds, 0x69f0);
    dh--;
    dh--;
    dh--;
    if (memoryAGet16(ds, 0x95c4) == 0x0001)
        goto loc_19a84;
    if (dh != 0x04)
        goto loc_19a95;
    dh = 0x10;
    memoryASet(ds, 0x95ad, 0x04);
    sub_16e66();
    goto loc_19a4b;
loc_19a84: // 1040:9684
    if (dh != 0x04)
        goto loc_19a95;
    dh = 0x13;
    memoryASet(ds, 0x95ad, 0x05);
    sub_16e66();
    goto loc_19a4b;
loc_19a95: // 1040:9695
    memoryASet(ds, 0x95ad, memoryAGet(ds, 0x95ad) - 1);
    sub_16e66();
    goto loc_19a4b;
loc_19a9e: // 1040:969e
    if (!(al & 0x04))
        goto loc_19a4b;
    dx = memoryAGet16(ds, 0x69f0);
    dh++;
    dh++;
    dh++;
    if (memoryAGet16(ds, 0x95c4) == 0x0001)
        goto loc_19ac4;
    if (dh != 0x13)
        goto loc_19ad6;
    dh = 0x07;
    memoryASet(ds, 0x95ad, 0x01);
    sub_16e66();
    goto loc_19a4b;
loc_19ac4: // 1040:96c4
    if (dh != 0x16)
        goto loc_19ad6;
    dh = 0x07;
    memoryASet(ds, 0x95ad, 0x01);
    sub_16e66();
    goto loc_19a4b;
loc_19ad6: // 1040:96d6
    memoryASet(ds, 0x95ad, memoryAGet(ds, 0x95ad) + 1);
    sub_16e66();
    goto loc_19a4b;
loc_19ae0: // 1040:96e0
    al = memoryAGet(ds, 0x95ad);
    cbw();
    ax--;
    si = 0x95af;
    si += ax;
    al = memoryAGet(ds, si);
    cbw();
    memoryASet16(ds, 0x8bec, ax);
    memoryASet16(ds, 0x8bee, ax);
}
void sub_19af6() // 1040:96f6
{
    push(dx);
    push(ax);
    ax = memoryAGet16(ds, 0x96f4);
loc_19afb: // 1040:96fb
    push(ax);
    push(es);
    dx = 0x0040;
    es = dx;
    dx = memoryAGet16(es, 0x0063);
    es = pop();
    dl += 0x06;
loc_19b0b: // 1040:970b
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_19b0b;
loc_19b10: // 1040:9710
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_19b10;
    ax = pop();
    ax--;
    if (ax)
        goto loc_19afb;
    ax = pop();
    dx = pop();
}
void sub_19b1c() // 1040:971c
{
    push(dx);
    push(ax);
    push(ax);
    push(es);
    dx = 0x0040;
    es = dx;
    dx = memoryAGet16(es, 0x0063);
    es = pop();
    dl += 0x06;
loc_19b2e: // 1040:972e
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_19b2e;
loc_19b33: // 1040:9733
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_19b33;
    ax = pop();
    ax = pop();
    dx = pop();
}
void sub_19b40() // 1040:9740
{
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0x973c);
    dx = memoryAGet16(ds, 0x973e);
    tx = dx; dx = ax; ax = tx;
    dx = rol16(dx, 0x0001);
    dx = rol16(dx, 0x0001);
    dx = rol16(dx, 0x0001);
    dx -= 0x0007;
    dx ^= ax;
    memoryASet16(ds, 0x973c, ax);
    memoryASet16(ds, 0x973e, dx);
    dx = pop();
    ax = pop();
}
void sub_19bac() // 1040:97ac
{
    al = 0x11;
    if (memoryAGet(ds, 0x97ab) == 0x01)
        goto loc_19bce;
    if (memoryAGet(ds, 0xb888) == al)
        goto loc_19bbc;
    return;
loc_19bbc: // 1040:97bc
    sync(); // X Y Z
    if (memoryAGet(ds, 0xb888) == al)
        goto loc_19bbc;
loc_19bc2: // 1040:97c2
    sync(); // X Y Z
    if (memoryAGet(ds, 0xb888) != al)
        goto loc_19bc2;
    memoryASet(ds, 0x97ab, 0x01);
    return;
loc_19bce: // 1040:97ce
    if (al == memoryAGet(ds, 0xb888))
        goto loc_19bd9;
    memoryASet(ds, 0x97ab, 0x00);
loc_19bd9: // 1040:97d9
    return;
}
void sub_19bdc() // 1040:97dc
{
    sub_1c4ca();
    if (!(al & 0x10))
        goto loc_19bf0;
    if (memoryAGet(ds, 0x97da) == 0x01)
        goto loc_19bf5;
    memoryASet(ds, 0x97da, 0x01);
    return;
loc_19bf0: // 1040:97f0
    memoryASet(ds, 0x97da, 0x00);
loc_19bf5: // 1040:97f5
    al &= 0xef;
}
void sub_19c05() // 1040:9805
{
    push(flagAsReg());
    push(si);
    push(ax);
    if (memoryAGet(ds, 0x9804) == 0x01)
        goto loc_19c3f;
    si = memoryAGet16(ds, 0x97f8);
    al = memoryAGet(ds, 0xb888);
    if (al & 0x80)
        goto loc_19c39;
    if (!al)
        goto loc_19c39;
    ah = memoryAGet(ds, si);
    if (al != ah)
        goto loc_19c33;
    si++;
    memoryASet16(ds, 0x97f8, si);
    if (memoryAGet(ds, si) != 0xff)
        goto loc_19c39;
    memoryASet(ds, 0x9804, 0x01);
loc_19c33: // 1040:9833
    memoryASet16(ds, 0x97f8, 0x97fa);
loc_19c39: // 1040:9839
    memoryASet(ds, 0xb888, 0x00);
loc_19c3f: // 1040:983f
    ax = pop();
    si = pop();
    flagsFromReg(pop());
}
void sub_19c43() // 1040:9843
{
loc_19c43: // 1040:9843
    si = memoryAGet16(ds, bx);
    if (!si)
        goto loc_19c59;
    al = memoryAGet(ds, si);
    si++;
    ah = memoryAGet(ds, si);
    si++;
    push(bx);
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:9850;
    bx = pop();
    bx++;
    bx++;
    goto loc_19c43;
loc_19c59: // 1040:9859
    return;
}
void sub_19e18() // 1040:9a18 +returnCarry
{
    memoryASet(cs, 0xbda2, 0xc3); flags.carry = false; return;
    memoryASet16(ds, 0x9a16, 0x0000);
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:9a1e;
loc_19e22: // 1040:9a22
    sub_19ebb();
    bx = 0x99b3;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9a2b;
    bx = 0x99b3;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9a35;
    memoryASet(ds, 0xb888, 0x00);
    ax = memoryAGet16(ds, 0x9a16);
    ax <<= 1;
    di = 0x9a0c;
    di += ax;
    di = memoryAGet16(ds, di);
loc_19e4b: // 1040:9a4b
    sub_1bf7c();
    bx &= 0x0003;
    if (bx)
        goto loc_19e6a;
    ah = memoryAGet(ds, 0xb888);
    if ((char)ah < 0)
        goto loc_19e4b;
    if (!ah)
        goto loc_19e4b;
    if (ah != 0x01)
        goto loc_19e6c;
    memoryASet(cs, 0xbda2, 0xc3);
    flags.carry = 0;
    return;
loc_19e6a: // 1040:9a6a
    flags.carry = 1;
    return;
loc_19e6c: // 1040:9a6c
    if (ah != 0x1c)
        goto loc_19e7d;
    sub_19ed0();
    si = 0x9a06;
    sub_19eb5();
    goto loc_19e9b;
    // gap 1 bytes
loc_19e7d: // 1040:9a7d
    si = 0x99e5;
loc_19e80: // 1040:9a80
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_19eb2;
    if (al != ah)
        goto loc_19e80;
    sub_19ed0();
    si--;
    si -= 0x001a;
    al = memoryAGet(ds, si);
    memoryASet(ds, 0x9a00, al);
    si = 0x9a00;
    sub_19eb5();
loc_19e9b: // 1040:9a9b
    memoryASet16(ds, 0x9a16, memoryAGet16(ds, 0x9a16) + 1);
    if (memoryAGet16(ds, 0x9a16) != 0x0005)
        goto loc_19eaf;
    memoryASet16(ds, 0x9a16, 0x0000);
    goto loc_19e22;
loc_19eaf: // 1040:9aaf
    goto loc_19e22;
loc_19eb2: // 1040:9ab2
    goto loc_19e22;
}
void sub_19eb5() // 1040:9ab5
{
    cx = 0x0006;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
}
void sub_19ebb() // 1040:9abb
{
    ax = memoryAGet16(ds, 0x9a16);
    ax <<= 1;
    si = 0x99a9;
    si += ax;
    si = memoryAGet16(ds, si);
    di = 0x9958;
    cx = 0x0005;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
}
void sub_19ed0() // 1040:9ad0
{
    bx = 0xb874;
    cx = memoryAGet16(ds, 0x9a16);
    bx += cx;
    memoryASet(ds, bx, ah);
}
void sub_19ee5() // 1040:9ae5
{
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:9ae5;
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:9ae9;
    sub_16b3b();
    ax = 0x0c0f;
    si = 0x9adc;
    indirectCall(cs, memoryAGet16(ds, 0x000c)); // 1040:9af6;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9afa;
    cx = 0x01e0;
loc_19f01: // 1040:9b01
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_19f10;
    cx = pop();
    if (--cx)
        goto loc_19f01;
    return;
loc_19f10: // 1040:9b10
    cx = pop();
}
void sub_19f12() // 1040:9b12 +isolate
{
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:9b12;
    ax = 0x0004;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    ax = 0x0002;
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    sub_19ee5();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    sub_1c359();
    return;
}
void sub_19f8a() // 1040:9b8a +returnCarry
{
    push(ds);
    push(es);
    ax = 0x0c05;
    si = 0x9b5f;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:9b92;
    ax = 0x0d0e;
    si = 0x9b7d;
    indirectCall(cs, memoryAGet16(ds, 0x000e)); // 1040:9b9c;
    indirectCall(cs, memoryAGet16(ds, 0x0038)); // 1040:9ba0;
loc_19fa4: // 1040:9ba4
    al = memoryAGet(cs, 0xb888);
    if (al != 0x15)
        goto loc_19fb0;
    flags.carry = 1;
    goto loc_19fb5;
    // gap 1 bytes
loc_19fb0: // 1040:9bb0
    if (al != 0x31)
        goto loc_19fa4;
    flags.carry = 0;
loc_19fb5: // 1040:9bb5
    es = pop();
    ds = pop();
}
void sub_1a102() // 1040:9d02
{
    di = 0x9ca8;
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    ax <<= 1;
    di += ax;
    di = memoryAGet16(ds, di);
}
void sub_1a111() // 1040:9d11
{
    di = 0x9cfa;
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    ax <<= 1;
    di += ax;
    di = memoryAGet16(ds, di);
}
void sub_1a120() // 1040:9d20
{
}
void sub_1a121() // 1040:9d21
{
    sub_1a102();
    memoryASet16(ds, di, 0x0001);
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 2, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 4, ax);
}
void sub_1a137() // 1040:9d37
{
    sub_1a102();
    memoryASet16(ds, di, 0x0000);
}
void sub_1a13f() // 1040:9d3f
{
    sub_1a102();
    memoryASet16(ds, di, 0x0002);
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 18, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 20, ax);
}
void sub_1a155() // 1040:9d55
{
    sub_1a102();
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memoryASet16(ds, di + 22, ax);
    ax = 0;
    memoryASet16(ds, di + 24, ax);
}
void sub_1a168() // 1040:9d68
{
    al = memoryAGet(ds, bx);
    bx++;
    if (al)
        goto loc_1a174;
    indirectCall(cs, memoryAGet16(ds, 0x0030)); // 1040:9d6f;
    return;
loc_1a174: // 1040:9d74
    ah = 0;
    ax--;
    ax <<= 1;
    si = 0x2314;
    si = memoryAGet16(ds, si);
    si += 0x2314;
    si += ax;
    si = memoryAGet16(ds, si);
    si += 0x2314;
    si += 0x0008;
    al = memoryAGet(ds, bx);
    bx++;
    ah = memoryAGet(ds, bx);
    bx++;
    indirectCall(cs, memoryAGet16(ds, 0x002c)); // 1040:9d93;
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    si += ax;
    al = memoryAGet(ds, bx);
    bx++;
    cl = 0x05;
    ax <<= cl;
    si += ax;
    cl = memoryAGet(ds, bx);
    bx++;
    ch = memoryAGet(ds, bx);
    bx++;
    push(ax);
    push(bx);
    push(cx);
    push(di);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x002e)); // 1040:9db2;
    si = pop();
    di = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1a1bc() // 1040:9dbc
{
    al = memoryAGet(ds, bx);
    bx++;
    ah = memoryAGet(ds, bx);
    bx++;
    si = bx;
    push(ax);
    push(bx);
    push(si);
    indirectCall(cs, memoryAGet16(ds, 0x0032)); // 1040:9dc7;
    si = pop();
    bx = pop();
    ax = pop();
loc_1a1ce: // 1040:9dce
    al = memoryAGet(ds, bx);
    bx++;
    if (al != 0xff)
        goto loc_1a1ce;
}
void sub_1a1d7() // 1040:9dd7
{
    al = memoryAGet(ds, bx);
    cbw();
    bx++;
    push(bx);
    memoryASet16(ds, 0xbdf2, ax);
    sub_1aecd();
    bx = pop();
}
void sub_1a1e4() // 1040:9de4
{
    bx++;
}
void sub_1a1e6() // 1040:9de6
{
    sub_1a102();
    memoryASet16(ds, di, 0x0003);
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memoryASet16(ds, di + 6, ax);
    ax = 0;
    memoryASet16(ds, di + 8, ax);
}
void sub_1a1fd() // 1040:9dfd
{
    sub_1a111();
    memoryASet16(ds, di, 0x0001);
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 2, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 4, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 6, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 8, ax);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, di + 10, ax);
    memoryASet16(ds, di + 12, 0x0000);
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memoryASet16(ds, di + 14, ax);
}
void sub_1a234() // 1040:9e34
{
    sub_1a111();
    memoryASet16(ds, di, 0x0000);
}
void sub_1a23e() // 1040:9e3e
{
    ax = memoryAGet16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memoryASet16(ds, 0x9e3c, bx);
    bx = ax;
}
void sub_1a24c() // 1040:9e4c
{
    bx = memoryAGet16(ds, 0x9e3c);
}
void sub_1a257() // 1040:9e57
{
    sp -= 2;
    memoryASet16(ds, 0x9e51, sp);
    memoryASet16(ds, 0x8bf0, 0x0000);
    memoryASet16(ds, 0x9e55, ax);
    memoryASet16(ds, 0x9e53, 0x0000);
    sub_1c4ca();
    if (!(al & 0x10))
        goto loc_1a277;
    memoryASet16(ds, 0x9e53, 0x0001);
loc_1a277: // 1040:9e77
    sub_16b3b();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9e7a;
    sub_16b3b();
    ax = memoryAGet16(ds, 0x9e55);
    ax <<= 1;
    bx = 0x2316;
    bx += ax;
    bx = memoryAGet16(ds, bx);
    bx += 0x2314;
    di = 0x9bd6;
    cx = 0x0008;
loc_1a297: // 1040:9e97
    memoryASet16(ds, di, 0x0000);
    di += 0x001a;
    if (--cx)
        goto loc_1a297;
    di = 0x9cb8;
    cx = 0x0004;
loc_1a2a6: // 1040:9ea6
    memoryASet16(ds, di, 0x0000);
    di += 0x0010;
    if (--cx)
        goto loc_1a2a6;
loc_1a2af: // 1040:9eaf
    ax = 0;
    al = memoryAGet(ds, bx);
    bx++;
    if (al == 0x00)
        goto loc_1a2c3;
    ax <<= 1;
    si = 0x9bb8;
    si += ax;
    indirectCall(cs, memoryAGet16(ds, si)); // 1040:9ebf;
    goto loc_1a2af;
loc_1a2c3: // 1040:9ec3
    sp += 2;
    return;
}
void sub_1a2c4() // 1040:9ec4
{
    sp -= 2;
    push(bx);
    sub_1c4ca();
    bx = pop();
    dx = memoryAGet16(ds, 0x9e55);
    if (dx != 0x0000)
        goto loc_1a2d3;
    sp += 2;
    return;
loc_1a2d3: // 1040:9ed3
    if (dx != 0x0001)
        goto loc_1a2f1;
    if (!(al & 0x10))
        goto loc_1a2e8;
    if (memoryAGet16(ds, 0x9e53) == 0x0001)
        goto loc_1a2ee;
    sp = memoryAGet16(ds, 0x9e51);
    stop("stack_unbalanced");
    sp += 2;
    return;
loc_1a2e8: // 1040:9ee8
    memoryASet16(ds, 0x9e53, 0x0000);
loc_1a2ee: // 1040:9eee
    al &= 0xef;
    sp += 2;
    return;
loc_1a2f1: // 1040:9ef1
    al &= 0xef;
    sp += 2;
}
void sub_1a2f6() // 1040:9ef6
{
    sub_16b3b();
    memoryASet16(ds, 0x9ef4, 0x0000);
    cx = 0;
    cl = memoryAGet(ds, bx);
    bx++;
loc_1a304: // 1040:9f04
    push(cx);
    memoryASet16(ds, 0x9ef4, memoryAGet16(ds, 0x9ef4) + 1);
    if (memoryAGet16(ds, 0x9ef4) != 0x0007)
        goto loc_1a316;
    memoryASet16(ds, 0x9ef4, 0x0000);
loc_1a316: // 1040:9f16
    sub_1a389();
    sub_1a437();
    sub_1a2c4();
    if (!(al & 0x10))
        goto loc_1a32a;
    if (memoryAGet16(ds, 0x9ef4) != 0x0000)
        goto loc_1a33d;
loc_1a32a: // 1040:9f2a
    indirectCall(cs, memoryAGet16(ds, 0x0034)); // 1040:9f2a;
    indirectCall(cs, memoryAGet16(ds, 0x0044)); // 1040:9f2e;
    sub_19b1c();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:9f35;
    indirectCall(cs, memoryAGet16(ds, 0x0038)); // 1040:9f39;
    // sync intro X
loc_1a33d: // 1040:9f3d
    cx = pop();
    if (--cx)
        goto loc_1a304;
}
void sub_1a389() // 1040:9f89
{
    si = 0x9bd6;
loc_1a38c: // 1040:9f8c
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_1a3ce;
    if (!ax)
        goto loc_1a3c9;
    if (ax == 0x0001)
        goto loc_1a3c9;
    if (ax != 0x0002)
        goto loc_1a3c2;
    ax = memoryAGet16(ds, si + 18);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if ((short)memoryAGet16(ds, si + 2) < (short)0x00e8)
        goto loc_1a3af;
    memoryASet16(ds, si, 0x0000);
loc_1a3af: // 1040:9faf
    if ((short)memoryAGet16(ds, si + 2) >= (short)0x0000)
        goto loc_1a3b9;
    memoryASet16(ds, si, 0x0000);
loc_1a3b9: // 1040:9fb9
    ax = memoryAGet16(ds, si + 20);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + ax);
    goto loc_1a3c9;
    // gap 1 bytes
loc_1a3c2: // 1040:9fc2
    push(bx);
    push(si);
    sub_1a3cf();
    si = pop();
    bx = pop();
loc_1a3c9: // 1040:9fc9
    si += 0x001a;
    goto loc_1a38c;
loc_1a3ce: // 1040:9fce
    return;
}
void sub_1a3cf() // 1040:9fcf
{
    push(bx);
    bx = memoryAGet16(ds, si + 6);
    al = memoryAGet(ds, bx);
    if (al != 0x00)
        goto loc_1a3df;
    bx++;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 6, bx);
loc_1a3df: // 1040:9fdf
    bx++;
    al = memoryAGet(ds, bx);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    al = sar8(al, 0x01);
    if (al != 0x07)
        goto loc_1a3f0;
    al++;
loc_1a3f0: // 1040:9ff0
    cbw();
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    if ((short)memoryAGet16(ds, si + 2) < (short)0x00e8)
        goto loc_1a3ff;
    memoryASet16(ds, si, 0x0000);
loc_1a3ff: // 1040:9fff
    if ((short)memoryAGet16(ds, si + 2) >= (short)0x0000)
        goto loc_1a409;
    memoryASet16(ds, si, 0x0000);
loc_1a409: // 1040:a009
    al = memoryAGet(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_1a413;
    al |= 0xf0;
loc_1a413: // 1040:a013
    if (al != 0x07)
        goto loc_1a419;
    al++;
loc_1a419: // 1040:a019
    cbw();
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + ax);
    bx--;
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
    if (ax == memoryAGet16(ds, si + 8))
        goto loc_1a42b;
    if (ax >= memoryAGet16(ds, si + 8))
        goto loc_1a435;
loc_1a42b: // 1040:a02b
    memoryASet16(ds, si + 8, 0x0000);
    bx++;
    bx++;
    memoryASet16(ds, si + 6, bx);
loc_1a435: // 1040:a035
    bx = pop();
}
void sub_1a437() // 1040:a037
{
    si = 0x9bd6;
loc_1a43a: // 1040:a03a
    ax = memoryAGet16(ds, si);
    if ((short)ax < 0)
        goto loc_1a44e;
    if (!ax)
        goto loc_1a449;
    push(bx);
    push(si);
    sub_1718e();
    si = pop();
    bx = pop();
loc_1a449: // 1040:a049
    si += 0x001a;
    goto loc_1a43a;
loc_1a44e: // 1040:a04e
    return;
}
void sub_1a44f() // 1040:a04f
{
    ax = memoryAGet16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x00c1;
    sub_1a65b();
}
void sub_1a45c() // 1040:a05c
{
    ax = 0x1040;
    cx = 0x3374;
    dx = 0x006b;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x3974;
    dx = 0x0077;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x3c74;
    dx = 0x0084;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x4c74;
    dx = 0x0091;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x53f4;
    dx = 0x009d;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x1180;
    dx = 0x00aa;
    sub_1a65b();
    ax = 0x1040;
    cx = 0x2314;
    dx = 0x00b6;
    sub_1a65b();
}
void sub_1a54a() // 1040:a14a
{
    si = 0x006b;
    ax = memoryAGet16(ds, 0x8bec);
    ax--;
    ax += 0x0031;
loc_1a554: // 1040:a154
    ah = memoryAGet(ds, si);
    if (ah == 0xff)
        goto loc_1a56a;
    if ((char)ah < (char)0x31)
        goto loc_1a567;
    if ((char)ah > (char)0x35)
        goto loc_1a567;
    memoryASet(ds, si, al);
loc_1a567: // 1040:a167
    si++;
    goto loc_1a554;
loc_1a56a: // 1040:a16a
    return;
}
void sub_1a56b() // 1040:a16b
{
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:a16b;
    ax = 0x0a0c;
    si = 0x94c1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:a175;
    ax = 0x0b0c;
    si = 0x94e1;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:a17f;
    ax = 0x0c0c;
    si = 0x9501;
    indirectCall(cs, memoryAGet16(ds, 0x0046)); // 1040:a189;
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:a18d;
}
void sub_1a592() // 1040:a192
{
    push(cs);
    ds = pop();
    di = 0x66f6;
    cx = 0x0006;
    al = 0x0a;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    memoryASet16(ds, 0x6610, 0x0006);
    di = 0x66fd;
    cx = 0x0006;
    al = 0x0b;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    memoryASet16(ds, 0x6612, 0x0006);
    di = 0x6704;
    cx = 0x0006;
    al = 0x0c;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    memoryASet16(ds, 0x6614, 0x0006);
    sub_1a5f0();
    indirectCall(cs, memoryAGet16(ds, 0x001a)); // 1040:a1c7;
    memoryASet16(ds, 0x8bec, 0x0001);
    memoryASet16(ds, 0x7e16, 0x0000);
    memoryASet16(ds, 0x7e18, 0x0000);
    memoryASet16(ds, 0x7e00, 0x0000);
    push(cs);
    ds = pop();
    di = 0x6616;
    cx = 0x0006;
    al = 0;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_1a5e3() // 1040:a1e3
{
    push(cs);
    ds = pop();
    di = 0x6616;
    cx = 0x0006;
    al = 0;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_1a5f0() // 1040:a1f0
{
    ax = 0;
    memoryASet16(ds, 0x0b00, ax);
    memoryASet16(ds, 0x0b38, ax);
    ax++;
    memoryASet16(ds, 0x0b1c, ax);
    ax--;
    di = 0x0b56;
loc_1a600: // 1040:a200
    dx = memoryAGet16(ds, di);
    if ((short)dx < 0)
        goto loc_1a60c;
    stosw<ES_DI>(ax);
    di += 0x0032;
    goto loc_1a600;
loc_1a60c: // 1040:a20c
    di = 0x0c28;
loc_1a60f: // 1040:a20f
    dx = memoryAGet16(ds, di);
    if ((short)dx < 0)
        goto loc_1a61b;
    stosw<ES_DI>(ax);
    di += 0x0032;
    goto loc_1a60f;
loc_1a61b: // 1040:a21b
    return;
}
void sub_1a65b() // 1040:a25b
{
    memoryASet16(ds, 0xa255, ax);
    memoryASet16(ds, 0xa257, cx);
    sub_1a67b();
    push(ds);
    bx = memoryAGet16(ds, 0xa259);
    ax = memoryAGet16(ds, 0xa255);
    dx = memoryAGet16(ds, 0xa257);
    ds = ax;
    sub_1a693();
    ds = pop();
    sub_1a69d();
}
void sub_1a67b() // 1040:a27b
{
    ah = 0x3d;
    al = 0x00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_1a6fb;
    push(ds);
    push(ax);
    ax = 0x1040;
    ds = ax;
    ax = pop();
    memoryASet16(ds, 0xa259, ax);
    ds = pop();
    return;
    // gap 104 bytes
loc_1a6fb: // 1040:a2fb
    push(ds);
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x1040;
    ds = ax;
    dx = 0xa21c;
    ah = 0x09;
    interrupt(0x21);
    ds = pop();
    ax = 0x1040;
    ds = ax;
    memoryASet(ds, 0xb888, 0x00);
loc_1a719: // 1040:a319
    al = memoryAGet(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    sub_196f3();
    return;
}
void sub_1a693() // 1040:a293
{
    ah = 0x3f;
    cx = 0xffff;
    interrupt(0x21);
    if (flags.carry)
        goto loc_1a6fb;
    return;
    // gap 94 bytes
loc_1a6fb: // 1040:a2fb
    push(ds);
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x1040;
    ds = ax;
    dx = 0xa21c;
    ah = 0x09;
    interrupt(0x21);
    ds = pop();
    ax = 0x1040;
    ds = ax;
    memoryASet(ds, 0xb888, 0x00);
loc_1a719: // 1040:a319
    al = memoryAGet(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    sub_196f3();
    return;
}
void sub_1a69d() // 1040:a29d
{
    ah = 0x3e;
    bx = memoryAGet16(ds, 0xa259);
    interrupt(0x21);
    if (flags.carry)
        goto loc_1a6fb;
    return;
    // gap 83 bytes
loc_1a6fb: // 1040:a2fb
    push(ds);
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x1040;
    ds = ax;
    dx = 0xa21c;
    ah = 0x09;
    interrupt(0x21);
    ds = pop();
    ax = 0x1040;
    ds = ax;
    memoryASet(ds, 0xb888, 0x00);
loc_1a719: // 1040:a319
    al = memoryAGet(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    sub_196f3();
    return;
}
void sub_1ad6e() // 1040:a96e
{
    ah = 0;
    ax <<= 1;
    bx = ax;
    ax <<= 1;
    ax += bx;
    bx = 0xa64d;
    bx += ax;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, 0xa854, bx);
    memoryASet(ds, 0xa852, 0x01);
    memoryASet(ds, 0xa84e, 0x00);
    memoryASet16(ds, 0xa850, 0x0001);
    memoryASet16(ds, 0xa856, 0x0000);
    memoryASet16(ds, 0xa858, 0x0000);
    memoryASet(ds, 0xa85a, 0x00);
    memoryASet16(ds, 0xa85c, 0x0000);
    memoryASet(ds, 0xa85e, 0xff);
}
void sub_1adb0() // 1040:a9b0
{
    al = in8(0x61);
    al &= 0xfd;
    out8(0x61, al);
}
void sub_1adcb() // 1040:a9cb
{
    push(ds);
    push(es);
    ah = 0x35;
    al = 0x08;
    interrupt(0x21);
    push(ax);
    ax = 0x1040;
    ds = ax;
    ax = pop();
    memoryASet16(ds, 0xb88e, es);
    memoryASet16(cs, 0xaa7b, es);
    memoryASet16(ds, 0xb890, bx);
    memoryASet16(cs, 0xaa79, bx);
    ah = 0x25;
    al = 0x08;
    push(cs);
    ds = pop();
    dx = 0xaa28;
    interrupt(0x21);
    ax = 0x4000;
    out8(0x40, al);
    al = ah;
    out8(0x40, al);
    es = pop();
    ds = pop();
}
void sub_1ae03() // 1040:aa03
{
    push(ds);
    push(ax);
    ax = 0x0000;
    out8(0x40, al);
    al = ah;
    out8(0x40, al);
    ax = 0x1040;
    ds = ax;
    dx = memoryAGet16(ds, 0xb890);
    ds = memoryAGet16(ds, 0xb88e);
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ax = pop();
    ds = pop();
}
void sub_1ae81() // 1040:aa81
{
    bool temp_cf;

    al = memoryAGet(ds, 0xaa26);
loc_1ae84: // 1040:aa84
    sync(); // X Y Z
    if (al == memoryAGet(ds, 0xaa26))
        goto loc_1ae84;
    al = memoryAGet(ds, 0xaa26);
loc_1ae8d: // 1040:aa8d
    flags.carry = (memoryAGet(ds, 0xaa7d) + 0x01) >= 0x100;
    memoryASet(ds, 0xaa7d, memoryAGet(ds, 0xaa7d) + 0x01);
    temp_cf = (memoryAGet(ds, 0xaa7e) + 0x00 + flags.carry) >= 0x100;
    memoryASet(ds, 0xaa7e, memoryAGet(ds, 0xaa7e) + (0x00 + flags.carry));
    flags.carry = temp_cf;
    temp_cf = (memoryAGet(ds, 0xaa7f) + 0x00 + flags.carry) >= 0x100;
    memoryASet(ds, 0xaa7f, memoryAGet(ds, 0xaa7f) + (0x00 + flags.carry));
    flags.carry = temp_cf;
    memoryASet(ds, 0xaa80, memoryAGet(ds, 0xaa80) + (0x00 + flags.carry));
    if (al == memoryAGet(ds, 0xaa26))
        goto loc_1ae8d;
    ax = memoryAGet16(ds, 0xaa7d);
    if ((short)ax < (short)0x0b00)
        goto loc_1aeb6;
    memoryASet16(ds, 0x96f4, 0x0003);
    return;
loc_1aeb6: // 1040:aab6
    if ((short)ax < (short)0x0700)
        goto loc_1aec2;
    memoryASet16(ds, 0x96f4, 0x0002);
    return;
loc_1aec2: // 1040:aac2
    memoryASet16(ds, 0x96f4, 0x0001);
    indirectCall(cs, memoryAGet16(ds, 0x004a)); // 1040:aac8;
}
void sub_1aecd() // 1040:aacd
{
    if ((short)ax < (short)0x000b)
        goto loc_1aed5;
    goto loc_1bb82;
loc_1aed5: // 1040:aad5
    if (memoryAGet16(ds, 0xab2b) == 0x0001)
        goto loc_1aee0;
    sub_1ad6e();
    return;
loc_1aee0: // 1040:aae0
    bx = ax;
    sub_1b95d();
    return;
    // gap 3228 bytes
loc_1bb82: // 1040:b782
    push(si);
    push(di);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    ds = bx;
    es = bx;
    ax -= 0x000b;
    if (memoryAGet16(ds, 0xab2b) == 0x0001)
        goto loc_1bb9e;
    goto loc_1bc4a;
loc_1bb9e: // 1040:b79e
    if (memoryAGet(ds, 0xa85e) != 0xff)
        goto loc_1bba8;
    goto loc_1bc40;
loc_1bba8: // 1040:b7a8
    ax += ax;
    ax += ax;
    si = 0xb181;
    si += ax;
    ax = memoryAGet16(ds, 0xab27);
    ax--;
    if ((short)ax >= 0)
        goto loc_1bbba;
    ax = 0x0005;
loc_1bbba: // 1040:b7ba
    memoryASet16(ds, 0xab27, ax);
    ax = memoryAGet16(ds, si + 2);
    push(ax);
    si = memoryAGet16(ds, si);
    push(si);
    ax = memoryAGet16(ds, 0xab27);
    memoryASet16(ds, 0xb3a7, ax);
    si++;
    si++;
    memoryASet16(ds, 0xb3a9, si);
    memoryASet16(ds, 0xb3ab, ds);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0015;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    ax = memoryAGet16(ds, 0xab27);
    memoryASet16(ds, 0xb3a7, ax);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0014;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    ax = memoryAGet16(ds, 0xab27);
    memoryASet16(ds, 0xb3a7, ax);
    si = pop();
    ax = pop();
    cbw();
    memoryASet16(ds, 0xb3a9, ax);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0013;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
loc_1bc40: // 1040:b840
    es = pop();
    ds = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di = pop();
    si = pop();
    return;
loc_1bc4a: // 1040:b84a
    if (memoryAGet(ds, 0xa85e) != 0xff)
        goto loc_1bc53;
    goto loc_1bc40;
loc_1bc53: // 1040:b853
    dx = memoryAGet16(ds, 0xab29);
    if (!dx)
        goto loc_1bc65;
    if (ax == 0x001a)
        goto loc_1bc40;
    if (ax == 0x001b)
        goto loc_1bc40;
loc_1bc65: // 1040:b865
    ax += ax;
    si = 0xb32d;
    si += ax;
    si = memoryAGet16(ds, si);
    memoryASet16(ds, 0xab29, si);
    goto loc_1bc40;
}
void sub_1b95d() // 1040:b55d
{
    ax = cs;
    ds = ax;
    memoryASet16(ds, 0xb55b, 0x0001);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0000;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    memoryASet16(ds, 0xb3a7, 0x0001);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0006;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    bx += bx;
    ax = bx;
    bx += bx;
    bx += ax;
    bx += 0xa64d;
    di = 0xb369;
    memoryASet16(ds, di, 0x00ff);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 2, ax);
    ax = 0;
    memoryASet16(ds, di + 16, ax);
    memoryASet16(ds, di + 12, ax);
    memoryASet16(ds, di + 18, ax);
    push(bx);
    sub_1bb3f();
    bx = pop();
    bx++;
    bx++;
    di = 0xb37d;
    memoryASet16(ds, di, 0x00ff);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 2, ax);
    ax = 0;
    memoryASet16(ds, di + 16, ax);
    ax = 0x0001;
    memoryASet16(ds, di + 12, ax);
    memoryASet16(ds, di + 18, ax);
    push(bx);
    sub_1bb3f();
    bx = pop();
    bx++;
    bx++;
    di = 0xb391;
    memoryASet16(ds, di, 0x00ff);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 2, ax);
    ax = 0;
    memoryASet16(ds, di + 16, ax);
    ax = 0x0002;
    memoryASet16(ds, di + 12, ax);
    memoryASet16(ds, di + 18, ax);
    sub_1bb3f();
    memoryASet16(ds, 0xb55b, 0x0000);
}
void sub_1bb3f() // 1040:b73f
{
    goto loc_1bb3f;
loc_1ba58: // 1040:b658
    al = memoryAGet(ds, si);
    if ((char)al >= 0)
        goto loc_1bac7;
    if (al != 0xff)
        goto loc_1ba72;
    memoryASet16(ds, di + 10, memoryAGet16(ds, di + 10) - 1);
    if (memoryAGet16(ds, di + 10))
        goto loc_1ba6a;
    goto loc_1bb3f;
loc_1ba6a: // 1040:b66a
    si = memoryAGet16(ds, di + 4);
    memoryASet16(ds, di + 6, si);
    goto loc_1ba58;
loc_1ba72: // 1040:b672
    al &= 0x7f;
    al--;
    al += al;
    ah = 0;
    bx = ax;
    bx += 0xb3b3;
    bx = memoryAGet16(ds, bx);
    al = memoryAGet(ds, bx);
    if (!al)
        goto loc_1ba90;
    al = memoryAGet(ds, bx + 1);
    ah = 0;
    memoryASet16(ds, di + 18, ax);
loc_1ba90: // 1040:b690
    bx += 0x0002;
    memoryASet16(ds, 0xb3a9, bx);
    ax = cs;
    memoryASet16(ds, 0xb3ab, ax);
    ax = memoryAGet16(ds, di + 18);
    memoryASet16(ds, 0xb3a7, ax);
    push(di);
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0015;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
    di = pop();
    si++;
    goto loc_1ba58;
loc_1bac7: // 1040:b6c7
    memoryASet16(ds, di + 8, 0x0000);
    memoryASet16(ds, di + 6, si);
    al -= 0x20;
    cbw();
    ax += memoryAGet16(ds, di + 16);
    memoryASet16(ds, 0xb3a9, ax);
    ax = memoryAGet16(ds, di + 14);
    memoryASet16(ds, 0xb3a7, ax);
    ax = cs;
    es = ax;
    bx = 0xb3a7;
    push(di);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0014;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di = pop();
    ax = memoryAGet16(ds, 0xb3a9);
    ax -= memoryAGet16(ds, di + 16);
    if (ax == 0x001d)
        goto loc_1bb3e;
    ax = memoryAGet16(ds, di + 18);
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, 0xb3a7, ax);
    ax = cs;
    es = ax;
    bx = 0xb3a7;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    bx = cs;
    es = bx;
    si = 0x0013;
    bx = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
loc_1bb3e: // 1040:b73e
    return;
loc_1bb3f: // 1040:b73f
    memoryASet16(ds, di + 10, 0x0001);
    si = memoryAGet16(ds, di + 2);
loc_1bb47: // 1040:b747
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_1bb52;
    memoryASet16(ds, di, 0x0000);
    return;
loc_1bb52: // 1040:b752
    if ((char)al >= 0)
        goto loc_1bb6c;
    if (al != 0xc0)
        goto loc_1bb64;
    si++;
    al = memoryAGet(ds, si);
    cbw();
    memoryASet16(ds, di + 16, ax);
    si++;
    goto loc_1bb47;
loc_1bb64: // 1040:b764
    al &= 0x7f;
    memoryASet(ds, di + 10, al);
    si++;
    goto loc_1bb47;
loc_1bb6c: // 1040:b76c
    si++;
    memoryASet16(ds, di + 2, si);
    ah = 0;
    ax += ax;
    bx = ax;
    bx += 0xa5e1;
    si = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 4, si);
    goto loc_1ba58;
}
void sub_1bc92() // 1040:b892
{
    push(ds);
    push(es);
    ah = 0x35;
    al = 0x09;
    interrupt(0x21);
    ax = 0x1040;
    ds = ax;
    memoryASet16(ds, 0xb88a, es);
    memoryASet16(ds, 0xb88c, bx);
    ah = 0x25;
    al = 0x09;
    dx = cs;
    ds = dx;
    dx = 0xb8cd;
    interrupt(0x21);
    es = pop();
    ds = pop();
}
void sub_1bcb7() // 1040:b8b7
{
    push(ds);
    ax = 0x1040;
    ds = ax;
    dx = memoryAGet16(ds, 0xb88c);
    ds = memoryAGet16(ds, 0xb88a);
    ah = 0x25;
    al = 0x09;
    interrupt(0x21);
    ds = pop();
}
void sub_1bf7c() // 1040:bb7c
{
    dx = 0x0201;
    ax = 0;
    cx = 0;
    al = in8(dx);
    ax &= 0x0030;
    if (ax == 0x0030)
        goto loc_1bf8f;
    cx = 0xffff;
loc_1bf8f: // 1040:bb8f
    push(cx);
    bl = 0x01;
    sub_1bfa0();
    push(cx);
    bl = 0x02;
    sub_1bfa0();
    dx = cx;
    cx = pop();
    bx = pop();
}
void sub_1bfa0() // 1040:bba0
{
    return;
    push(dx);
    flags.interrupts = 0;
    al = 0x00;
    out8(0x43, al);
    goto loc_1bfa8;
loc_1bfa8: // 1040:bba8
    al = in8(0x40);
    ah = al;
    goto loc_1bfae;
loc_1bfae: // 1040:bbae
    al = in8(0x40);
    tl = al; al = ah; ah = tl;
    push(ax);
    cx = 0x04ff;
    out8(dx, al);
    goto loc_1bfb9;
loc_1bfb9: // 1040:bbb9
    al = in8(dx);
    if (--cx && bl & al)
        goto loc_1bfb9;
    flags.zero = cx == 0x0000;
    cx = pop();
    if (!flags.zero)
        goto loc_1bfc9;
    cx = 0;
    goto loc_1bff7;
    // gap 1 bytes
loc_1bfc9: // 1040:bbc9
    al = 0x00;
    out8(0x43, al);
    goto loc_1bfcf;
loc_1bfcf: // 1040:bbcf
    al = in8(0x40);
    ah = al;
    goto loc_1bfd5;
loc_1bfd5: // 1040:bbd5
    al = in8(0x40);
    tl = al; al = ah; ah = tl;
    if (cx >= ax)
        goto loc_1bfe9;
    push(dx);
    dx = 0xffff;
    dx -= ax;
    cx += dx;
    dx = pop();
    goto loc_1bfeb;
    // gap 1 bytes
loc_1bfe9: // 1040:bbe9
    cx -= ax;
loc_1bfeb: // 1040:bbeb
    cx &= 0x1ff0;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
loc_1bff7: // 1040:bbf7
    flags.interrupts = 1;
    dx = 0x0201;
    push(cx);
    push(ax);
    cx = 0x04ff;
loc_1c000: // 1040:bc00
    al = in8(dx);
    if (--cx && al & 0x0f)
        goto loc_1c000;
    ax = pop();
    cx = pop();
    dx = pop();
}
void sub_1c0a8() // 1040:bca8
{
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bca8;
    bx = 0xbc80;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bcb2;
    bx = 0xbc80;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bcbc;
loc_1c0c0: // 1040:bcc0
    sub_1bf7c();
    bx &= 0x0003;
    if (bx)
        goto loc_1c0c0;
loc_1c0c8: // 1040:bcc8
    sub_1bf7c();
    bx &= 0x0003;
    if (!bx)
        goto loc_1c0c8;
    memoryASet16(ds, 0xbc98, cx);
    memoryASet16(ds, 0xbc9a, dx);
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bcd8;
    bx = 0xbc88;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bce2;
    bx = 0xbc88;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bcec;
loc_1c0f0: // 1040:bcf0
    sub_1bf7c();
    bx &= 0x0003;
    if (bx)
        goto loc_1c0f0;
loc_1c0f8: // 1040:bcf8
    sub_1bf7c();
    bx &= 0x0003;
    if (!bx)
        goto loc_1c0f8;
    memoryASet16(ds, 0xbc9c, cx);
    memoryASet16(ds, 0xbc9e, dx);
    indirectCall(cs, memoryAGet16(ds, 0x0026)); // 1040:bd08;
    bx = 0xbc90;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bd12;
    bx = 0xbc90;
    sub_19c43();
    indirectCall(cs, memoryAGet16(ds, 0x001c)); // 1040:bd1c;
loc_1c120: // 1040:bd20
    sub_1bf7c();
    bx &= 0x0003;
    if (bx)
        goto loc_1c120;
loc_1c128: // 1040:bd28
    sub_1bf7c();
    bx &= 0x0003;
    if (!bx)
        goto loc_1c128;
    memoryASet16(ds, 0xbca0, cx);
    memoryASet16(ds, 0xbca2, dx);
    ax = memoryAGet16(ds, 0xbc9c);
    ax -= memoryAGet16(ds, 0xbc98);
    bx = memoryAGet16(ds, 0xbc9e);
    bx -= memoryAGet16(ds, 0xbc9a);
    dl = 0x06;
    idiv8(dl);
    ax &= 0x00ff;
    cbw();
    push(ax);
    ax = bx;
    dl = 0x06;
    idiv8(dl);
    al &= 0xff;
    cbw();
    bx = ax;
    ax = pop();
    memoryASet16(ds, 0xbca4, ax);
    memoryASet16(ds, 0xbca6, bx);
}
void sub_1c164() // 1040:bd64
{
    sub_1c0a8();
    sub_1bf7c();
    cx |= dx;
    if (cx)
        goto loc_1c175;
    memoryASet(cs, 0xbda2, 0xc3);
    return;
loc_1c175: // 1040:bd75
    ax = memoryAGet16(ds, 0xbca0);
    dx = memoryAGet16(ds, 0xbca4);
    ax += dx;
    memoryASet16(ds, 0xb87e, ax);
    ax = memoryAGet16(ds, 0xbca0);
    dx = -dx;
    ax += dx;
    memoryASet16(ds, 0xb880, ax);
    ax = memoryAGet16(ds, 0xbca2);
    dx = memoryAGet16(ds, 0xbca6);
    ax += dx;
    memoryASet16(ds, 0xb87c, ax);
    ax = memoryAGet16(ds, 0xbca2);
    dx = -dx;
    ax += dx;
    memoryASet16(ds, 0xb87a, ax);
}
void sub_1c1a2() // 1040:bda2
{
    return;
    ax = 0x1040;
    ds = ax;
    sub_1bf7c();
    bx &= 0x0003;
    if (!bx)
        goto loc_1c1b7;
    bx = 0;
    bl |= 0x10;
    goto loc_1c1b9;
    // gap 1 bytes
loc_1c1b7: // 1040:bdb7
    bx = 0;
loc_1c1b9: // 1040:bdb9
    if (cx < memoryAGet16(ds, 0xb87e))
        goto loc_1c1c5;
    bl |= 0x01;
    goto loc_1c1ce;
    // gap 1 bytes
loc_1c1c5: // 1040:bdc5
    if (cx >= memoryAGet16(ds, 0xb880))
        goto loc_1c1ce;
    bl |= 0x02;
loc_1c1ce: // 1040:bdce
    if (dx >= memoryAGet16(ds, 0xb87a))
        goto loc_1c1da;
    bl |= 0x08;
    goto loc_1c1e3;
    // gap 1 bytes
loc_1c1da: // 1040:bdda
    if (dx < memoryAGet16(ds, 0xb87c))
        goto loc_1c1e3;
    bl |= 0x04;
loc_1c1e3: // 1040:bde3
    memoryASet(ds, 0xb882, bl);
    bh = memoryAGet(ds, 0xb886);
    bl |= bh;
    memoryASet(ds, 0xb884, bl);
}
void sub_1c276() // 1040:be76 +entry
{
    sp -= 2;
    flags.direction = 0;
    ah = 0x4a;
    bx = 0x0e00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1c283;
    sub_19731();
    return;
loc_1c283: // 1040:be83
    ax = cs;
    es = ax;
    si = 0x0080;
    di = 0x1040;
    es = di;
    di = 0xbdf6;
    cl = memoryAGet(ds, si);
    ch = 0;
    cx++;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    push(es);
    ds = pop();
    si = 0xbdf6;
    cx = 0x0080;
loc_1c2a2: // 1040:bea2
    al = memoryAGet(ds, si);
    si++;
    if (al == 0x2f)
        goto loc_1c2ae;
loc_1c2a9: // 1040:bea9
    if (--cx)
        goto loc_1c2a2;
    goto loc_1c2e2;
    // gap 1 bytes
loc_1c2ae: // 1040:beae
    al = memoryAGet(ds, si);
    if (al == 0x63)
        goto loc_1c2d3;
    if (al == 0x43)
        goto loc_1c2d3;
    if (al == 0x65)
        goto loc_1c2ca;
    if (al == 0x45)
        goto loc_1c2ca;
    if (al == 0x74)
        goto loc_1c2e5;
    if (al == 0x54)
        goto loc_1c2e5;
    goto loc_1c2a9;
loc_1c2ca: // 1040:beca
    memoryASet16(ds, 0x2f67, 0x2f4f);
    goto loc_1c2e2;
    // gap 1 bytes
loc_1c2d3: // 1040:bed3
    memoryASet16(ds, 0x2f67, 0x2f57);
    goto loc_1c2e2;
    // gap 7 bytes
loc_1c2e2: // 1040:bee2
    if (0)
    sub_1c4bd();
loc_1c2e5: // 1040:bee5
    indirectCall(cs, memoryAGet16(ds, 0x0002)); // 1040:bee5;
    si = 0xbdf6;
    cx = 0x0080;
loc_1c2ef: // 1040:beef
    al = memoryAGet(ds, si);
    si++;
    if (al == 0x2f)
        goto loc_1c308;
    if (--cx)
        goto loc_1c2ef;
    push(ds);
    ax = 0x1040;
    ds = ax;
    memoryASet16(ds, 0xab2b, 0x0000);
    ds = pop();
    goto loc_1c31f;
    // gap 1 bytes
loc_1c308: // 1040:bf08
    al = memoryAGet(ds, si);
    if (al == 0x61)
        goto loc_1c312;
    if (al != 0x41)
        goto loc_1c31f;
loc_1c312: // 1040:bf12
    ax = 0x1040;
    ds = ax;
    es = ax;
    memoryASet16(ds, 0xab2b, 0x0001);
loc_1c31f: // 1040:bf1f
    sub_196dd();
    if (0)
    sub_1ae81();
    memoryASet(ds, 0xa860, 0x01);
    sub_1c4e1();
    indirectCall(cs, memoryAGet16(ds, 0x002a)); // 1040:bf2d;
    indirectCall(cs, memoryAGet16(ds, 0x0008)); // 1040:bf31;
    sub_1a44f();
    indirectCall(cs, memoryAGet16(ds, 0x000a)); // 1040:bf38;
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:bf3c;
    sub_1a592();
    sub_19e18();
    if (!flags.carry)
        goto loc_1c34b;
    sub_1c164();
loc_1c34b: // 1040:bf4b
    memoryASet16(ds, 0x95c4, 0x0000);
    indirectCall(cs, memoryAGet16(ds, 0x003c)); // 1040:bf51;
    memoryASet16(ds, 0xc0df, sp);
    sp = memoryAGet16(ds, 0xc0df);
    indirectCall(cs, memoryAGet16(ds, 0x000a)); // 1040:bf5d;
    sub_1a592();
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:bf64;
    memoryASet16(ds, 0xbdf2, 0x0003);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
    indirectCall(cs, memoryAGet16(ds, 0x0028)); // 1040:bf74;
loc_1c378: // 1040:bf78
    sync(); // X Y Z Z Z
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
    // gap 1 bytes
loc_1c382: // 1040:bf82
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memoryASet16(ds, 0xbdf2, 0x0000);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395: // 1040:bf95
    sub_16b9b();
loc_1c398: // 1040:bf98
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memoryASet16(ds, 0xbdf2, 0x0000);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab: // 1040:bfab
    sub_16cd7();
    goto loc_1c382;
}
void sub_1c359() // 1040:bf59 +isolate
{
    sp = memoryAGet16(ds, 0xc0df);
    indirectCall(cs, memoryAGet16(ds, 0x000a)); // 1040:bf5d;
    sub_1a592();
    indirectCall(cs, memoryAGet16(ds, 0x003a)); // 1040:bf64;
    memoryASet16(ds, 0xbdf2, 0x0003);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
    indirectCall(cs, memoryAGet16(ds, 0x0028)); // 1040:bf74;
loc_1c378: // 1040:bf78
    sync(); // X Y Z
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
    // gap 1 bytes
loc_1c382: // 1040:bf82
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memoryASet16(ds, 0xbdf2, 0x0000);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395: // 1040:bf95
    sub_16b9b();
loc_1c398: // 1040:bf98
    if (memoryAGet(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memoryASet16(ds, 0xbdf2, 0x0000);
    ax = memoryAGet16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab: // 1040:bfab
    sub_16cd7();
    goto loc_1c382;
}
void sub_1c4bd() // 1040:c0bd
{
    ax = cs;
    cx = 0x0000;
    dx = memoryAGet16(ds, 0x2f67);
    sub_1a65b();
}
void sub_1c4ca() // 1040:c0ca
{
    sub_1c1a2();
    al = memoryAGet(ds, 0xb884);
}
void sub_1c4e1() // 1040:c0e1
{
}
void sub_1c4e2() // 1040:c0e2
{
    ax = memoryAGet16(ds, 0x6614);
    ax++;
    if ((short)ax > (short)0x0006)
        goto loc_1c4ee;
    memoryASet16(ds, 0x6614, ax);
loc_1c4ee: // 1040:c0ee
    return;
}
void fixReloc(uint16_t seg)
{
    memoryASet16(0x0040 + seg, 0x9334, memoryAGet16(0x0040 + seg, 0x9334) + seg); // 0040 -> 1040; lin=9734
    memoryASet16(0x0040 + seg, 0xa05d, memoryAGet16(0x0040 + seg, 0xa05d) + seg); // 0040 -> 1040; lin=a45d
    memoryASet16(0x0040 + seg, 0xa069, memoryAGet16(0x0040 + seg, 0xa069) + seg); // 0040 -> 1040; lin=a469
    memoryASet16(0x0040 + seg, 0xa075, memoryAGet16(0x0040 + seg, 0xa075) + seg); // 0040 -> 1040; lin=a475
    memoryASet16(0x0040 + seg, 0xa081, memoryAGet16(0x0040 + seg, 0xa081) + seg); // 0040 -> 1040; lin=a481
    memoryASet16(0x0040 + seg, 0xa08d, memoryAGet16(0x0040 + seg, 0xa08d) + seg); // 0040 -> 1040; lin=a48d
    memoryASet16(0x0040 + seg, 0xa099, memoryAGet16(0x0040 + seg, 0xa099) + seg); // 0040 -> 1040; lin=a499
    memoryASet16(0x0040 + seg, 0xa0a5, memoryAGet16(0x0040 + seg, 0xa0a5) + seg); // 0040 -> 1040; lin=a4a5
    memoryASet16(0x0040 + seg, 0xa289, memoryAGet16(0x0040 + seg, 0xa289) + seg); // 0040 -> 1040; lin=a689
    memoryASet16(0x0040 + seg, 0xa2d0, memoryAGet16(0x0040 + seg, 0xa2d0) + seg); // 0040 -> 1040; lin=a6d0
    memoryASet16(0x0040 + seg, 0xa2e1, memoryAGet16(0x0040 + seg, 0xa2e1) + seg); // 0040 -> 1040; lin=a6e1
    memoryASet16(0x0040 + seg, 0xa2f1, memoryAGet16(0x0040 + seg, 0xa2f1) + seg); // 0040 -> 1040; lin=a6f1
    memoryASet16(0x0040 + seg, 0xa302, memoryAGet16(0x0040 + seg, 0xa302) + seg); // 0040 -> 1040; lin=a702
    memoryASet16(0x0040 + seg, 0xa30f, memoryAGet16(0x0040 + seg, 0xa30f) + seg); // 0040 -> 1040; lin=a70f
    memoryASet16(0x0040 + seg, 0xa864, memoryAGet16(0x0040 + seg, 0xa864) + seg); // 0040 -> 1040; lin=ac64
    memoryASet16(0x0040 + seg, 0xa86e, memoryAGet16(0x0040 + seg, 0xa86e) + seg); // 0040 -> 1040; lin=ac6e
    memoryASet16(0x0040 + seg, 0xa9d5, memoryAGet16(0x0040 + seg, 0xa9d5) + seg); // 0040 -> 1040; lin=add5
    memoryASet16(0x0040 + seg, 0xaa0f, memoryAGet16(0x0040 + seg, 0xaa0f) + seg); // 0040 -> 1040; lin=ae0f
    memoryASet16(0x0040 + seg, 0xaa33, memoryAGet16(0x0040 + seg, 0xaa33) + seg); // 0040 -> 1040; lin=ae33
    memoryASet16(0x0040 + seg, 0xaa7b, memoryAGet16(0x0040 + seg, 0xaa7b) + seg); // 0040 -> 1040; lin=ae7b
    memoryASet16(0x0040 + seg, 0xaae7, memoryAGet16(0x0040 + seg, 0xaae7) + seg); // 0040 -> 1040; lin=aee7
    memoryASet16(0x0040 + seg, 0xb53c, memoryAGet16(0x0040 + seg, 0xb53c) + seg); // 0040 -> 1040; lin=b93c
    memoryASet16(0x0040 + seg, 0xb89b, memoryAGet16(0x0040 + seg, 0xb89b) + seg); // 0040 -> 1040; lin=bc9b
    memoryASet16(0x0040 + seg, 0xb8b9, memoryAGet16(0x0040 + seg, 0xb8b9) + seg); // 0040 -> 1040; lin=bcb9
    memoryASet16(0x0040 + seg, 0xb8d2, memoryAGet16(0x0040 + seg, 0xb8d2) + seg); // 0040 -> 1040; lin=bcd2
    memoryASet16(0x0040 + seg, 0xbda3, memoryAGet16(0x0040 + seg, 0xbda3) + seg); // 0040 -> 1040; lin=c1a3
    memoryASet16(0x0040 + seg, 0xbe8b, memoryAGet16(0x0040 + seg, 0xbe8b) + seg); // 0040 -> 1040; lin=c28b
    memoryASet16(0x0040 + seg, 0xbefa, memoryAGet16(0x0040 + seg, 0xbefa) + seg); // 0040 -> 1040; lin=c2fa
    memoryASet16(0x0040 + seg, 0xbf13, memoryAGet16(0x0040 + seg, 0xbf13) + seg); // 0040 -> 1040; lin=c313
}

int GetProcAt(int seg, int ofs)
{
    int map[] = {
        0x10524, 0x1040, 0x124, 0x1040, 0x133, 0x10533, 0x1040, 0x133, 0x1040, 0x194,
        0x10594, 0x1040, 0x194, 0x1040, 0x1a1, 0x105a1, 0x1040, 0x1a1, 0x1040, 0x1cc,
        0x105cc, 0x1040, 0x1cc, 0x1040, 0x1f7, 0x105f7, 0x1040, 0x1f7, 0x1040, 0x261,
        0x10661, 0x1040, 0x261, 0x1040, 0x278, 0x10702, 0x1040, 0x302, 0x1040, 0x330,
        0x10702, 0x1040, 0x331, 0x1040, 0x376, 0x10776, 0x1040, 0x376, 0x1040, 0x39d,
        0x1079d, 0x1040, 0x39d, 0x1040, 0x3ac, 0x107ac, 0x1040, 0x3ac, 0x1040, 0x3f1,
        0x107f1, 0x1040, 0x3f1, 0x1040, 0x436, 0x10836, 0x1040, 0x436, 0x1040, 0x47b,
        0x1087b, 0x1040, 0x47b, 0x1040, 0x48d, 0x1088d, 0x1040, 0x48d, 0x1040, 0x4dd,
        0x108dd, 0x1040, 0x4dd, 0x1040, 0x4f7, 0x108f7, 0x1040, 0x4f7, 0x1040, 0x51b,
        0x1091b, 0x1040, 0x51b, 0x1040, 0x586, 0x10986, 0x1040, 0x586, 0x1040, 0x5a5,
        0x109a5, 0x1040, 0x5a5, 0x1040, 0x5c4, 0x109c4, 0x1040, 0x5c4, 0x1040, 0x5d3,
        0x109d3, 0x1040, 0x5d3, 0x1040, 0x5ec, 0x109ee, 0x1040, 0x5ee, 0x1040, 0x667,
        0x10a67, 0x1040, 0x667, 0x1040, 0x6db, 0x10a67, 0x1040, 0x6dc, 0x1040, 0x6e7,
        0x10ae7, 0x1040, 0x6e7, 0x1040, 0x742, 0x10ae7, 0x1040, 0x743, 0x1040, 0x7b1,
        0x10bb1, 0x1040, 0x7b1, 0x1040, 0x7c4, 0x10bc4, 0x1040, 0x7c4, 0x1040, 0x82e,
        0x10c2e, 0x1040, 0x82e, 0x1040, 0x898, 0x10c98, 0x1040, 0x898, 0x1040, 0x8cd,
        0x10ccd, 0x1040, 0x8cd, 0x1040, 0x903, 0x10d03, 0x1040, 0x903, 0x1040, 0x93d,
        0x10d3d, 0x1040, 0x93d, 0x1040, 0x95c, 0x10d5c, 0x1040, 0x95c, 0x1040, 0x9aa,
        0x10daa, 0x1040, 0x9aa, 0x1040, 0x9f8, 0x10df8, 0x1040, 0x9f8, 0x1040, 0xa23,
        0x10e23, 0x1040, 0xa23, 0x1040, 0xa40, 0x10e40, 0x1040, 0xa40, 0x1040, 0xa7f,
        0x10e7f, 0x1040, 0xa7f, 0x1040, 0xaa6, 0x10ea6, 0x1040, 0xaa6, 0x1040, 0xac0,
        0x10ec0, 0x1040, 0xac0, 0x1040, 0xad7, 0x10ed8, 0x1040, 0xad8, 0x1040, 0xae4,
        0x10ee4, 0x1040, 0xae4, 0x1040, 0xae5, 0x10ee5, 0x1040, 0xae5, 0x1040, 0xae6,
        0x10ee6, 0x1040, 0xae6, 0x1040, 0xae7, 0x10ee7, 0x1040, 0xae7, 0x1040, 0xae8,
        0x10ee8, 0x1040, 0xae8, 0x1040, 0xaf7, 0x11162, 0x1040, 0xd62, 0x1040, 0xdf0,
        0x111f1, 0x1040, 0xdf1, 0x1040, 0xe2b, 0x111f1, 0x1040, 0xe2c, 0x1040, 0xe40,
        0x111f1, 0x1040, 0xe41, 0x1040, 0xed6, 0x112d6, 0x1040, 0xed6, 0x1040, 0xf76,
        0x11376, 0x1040, 0xf76, 0x1040, 0xfc8, 0x15f40, 0x1040, 0x5b40, 0x1040, 0x5be4,
        0x15fe4, 0x1040, 0x5be4, 0x1040, 0x5c22, 0x16022, 0x1040, 0x5c22, 0x1040, 0x5cf1,
        0x16022, 0x1040, 0x5cf2, 0x1040, 0x5cfd, 0x16022, 0x1040, 0x5cfe, 0x1040, 0x5d09,
        0x16022, 0x1040, 0x5d0a, 0x1040, 0x5d26, 0x16126, 0x1040, 0x5d26, 0x1040, 0x5d3c,
        0x1613c, 0x1040, 0x5d3c, 0x1040, 0x5d5f, 0x1615f, 0x1040, 0x5d5f, 0x1040, 0x5d74,
        0x16174, 0x1040, 0x5d74, 0x1040, 0x5d8f, 0x1618f, 0x1040, 0x5d8f, 0x1040, 0x5dcc,
        0x16205, 0x1040, 0x5dce, 0x1040, 0x5e20, 0x16222, 0x1040, 0x5e22, 0x1040, 0x5f81,
        0x16222, 0x1040, 0x5f82, 0x1040, 0x6007, 0x16407, 0x1040, 0x6007, 0x1040, 0x6053,
        0x16407, 0x1040, 0x6054, 0x1040, 0x606e, 0x1646e, 0x1040, 0x606e, 0x1040, 0x60a0,
        0x164a0, 0x1040, 0x60a0, 0x1040, 0x60e1, 0x164e1, 0x1040, 0x60e1, 0x1040, 0x6119,
        0x16519, 0x1040, 0x6119, 0x1040, 0x6155, 0x16555, 0x1040, 0x6155, 0x1040, 0x6191,
        0x16591, 0x1040, 0x5d5f, 0x1040, 0x5d8f, 0x16591, 0x1040, 0x6191, 0x1040, 0x61ed,
        0x16591, 0x1040, 0x61ee, 0x1040, 0x6224, 0x16591, 0x1040, 0x6225, 0x1040, 0x642a,
        0x16591, 0x1040, 0x642b, 0x1040, 0x646f, 0x16591, 0x1040, 0x64a8, 0x1040, 0x64ca,
        0x16591, 0x1040, 0x64cb, 0x1040, 0x64e4, 0x1686f, 0x1040, 0x646f, 0x1040, 0x64a8,
        0x168a8, 0x1040, 0x64a8, 0x1040, 0x64ca, 0x168a8, 0x1040, 0x64cb, 0x1040, 0x64e4,
        0x168e4, 0x1040, 0x64e4, 0x1040, 0x6507, 0x16907, 0x1040, 0x6507, 0x1040, 0x651d,
        0x1691d, 0x1040, 0x651d, 0x1040, 0x6553, 0x1691d, 0x1040, 0x6554, 0x1040, 0x65e1,
        0x169e3, 0x1040, 0x65e3, 0x1040, 0x660f, 0x16b3b, 0x1040, 0x673b, 0x1040, 0x679b,
        0x16b9b, 0x1040, 0x679b, 0x1040, 0x67c7, 0x16b9b, 0x1040, 0xbfb0, 0x1040, 0xc0bd,
        0x16bc7, 0x1040, 0x67c7, 0x1040, 0x67f7, 0x16bf7, 0x1040, 0x67f7, 0x1040, 0x6827,
        0x16c27, 0x1040, 0x6827, 0x1040, 0x683d, 0x16c3d, 0x1040, 0x683d, 0x1040, 0x6853,
        0x16c53, 0x1040, 0x6853, 0x1040, 0x6869, 0x16c69, 0x1040, 0x6869, 0x1040, 0x689e,
        0x16cb8, 0x1040, 0x68b8, 0x1040, 0x68d7, 0x16cd7, 0x1040, 0x68d7, 0x1040, 0x6969,
        0x16cd7, 0x1040, 0xbfb0, 0x1040, 0xc0bd, 0x16d69, 0x1040, 0x6969, 0x1040, 0x697e,
        0x16e16, 0x1040, 0x6a16, 0x1040, 0x6a39, 0x16e39, 0x1040, 0x6a39, 0x1040, 0x6a66,
        0x16e66, 0x1040, 0x6a66, 0x1040, 0x6a74, 0x16e74, 0x1040, 0x6a74, 0x1040, 0x6aa1,
        0x16ea1, 0x1040, 0x6aa1, 0x1040, 0x6aaf, 0x16eb2, 0x1040, 0x6ab2, 0x1040, 0x6b9e,
        0x16eb2, 0x1040, 0x6b9f, 0x1040, 0x6baf, 0x16eb2, 0x1040, 0x6bb0, 0x1040, 0x6bf5,
        0x16ff5, 0x1040, 0x6bf5, 0x1040, 0x6c18, 0x17018, 0x1040, 0x6c18, 0x1040, 0x6c43,
        0x17047, 0x1040, 0x6c47, 0x1040, 0x6c5d, 0x1705d, 0x1040, 0x6c5d, 0x1040, 0x6c81,
        0x1705d, 0x1040, 0x6c82, 0x1040, 0x6c94, 0x1705d, 0x1040, 0x6c95, 0x1040, 0x6c9d,
        0x1709d, 0x1040, 0x6c9d, 0x1040, 0x6ce6, 0x170e6, 0x1040, 0x6ce6, 0x1040, 0x6d32,
        0x17132, 0x1040, 0x6d32, 0x1040, 0x6d80, 0x17180, 0x1040, 0x6d80, 0x1040, 0x6d8e,
        0x1718e, 0x1040, 0x6d8e, 0x1040, 0x6dba, 0x1718e, 0x1040, 0x6dbb, 0x1040, 0x6e03,
        0x17205, 0x1040, 0x6e05, 0x1040, 0x6e20, 0x17222, 0x1040, 0x64a8, 0x1040, 0x64ca,
        0x17222, 0x1040, 0x64cb, 0x1040, 0x64e4, 0x17222, 0x1040, 0x6e22, 0x1040, 0x6eab,
        0x17222, 0x1040, 0x6eac, 0x1040, 0x6f20, 0x17222, 0x1040, 0x6f21, 0x1040, 0x6f93,
        0x17222, 0x1040, 0x6f94, 0x1040, 0x6fd7, 0x17222, 0x1040, 0x6fd8, 0x1040, 0x6fe3,
        0x17222, 0x1040, 0x6fe4, 0x1040, 0x6ffe, 0x17222, 0x1040, 0x6fff, 0x1040, 0x700d,
        0x17222, 0x1040, 0x700e, 0x1040, 0x705d, 0x17222, 0x1040, 0x705e, 0x1040, 0x709d,
        0x17222, 0x1040, 0x709e, 0x1040, 0x70bd, 0x17222, 0x1040, 0x70be, 0x1040, 0x70df,
        0x17222, 0x1040, 0x70e0, 0x1040, 0x7112, 0x17222, 0x1040, 0x7113, 0x1040, 0x7161,
        0x17222, 0x1040, 0x7162, 0x1040, 0x71c5, 0x17222, 0x1040, 0x71c6, 0x1040, 0x71fe,
        0x17222, 0x1040, 0x71ff, 0x1040, 0x7226, 0x17222, 0x1040, 0x7227, 0x1040, 0x7242,
        0x17222, 0x1040, 0x7243, 0x1040, 0x72b2, 0x17222, 0x1040, 0x72b3, 0x1040, 0x72e6,
        0x17674, 0x1040, 0x7274, 0x1040, 0x72a0, 0x176e6, 0x1040, 0x72e6, 0x1040, 0x72f4,
        0x176f4, 0x1040, 0x72f4, 0x1040, 0x7302, 0x17702, 0x1040, 0x7302, 0x1040, 0x7323,
        0x17723, 0x1040, 0x7323, 0x1040, 0x7347, 0x17723, 0x1040, 0x7348, 0x1040, 0x737c,
        0x17723, 0x1040, 0x737d, 0x1040, 0x7397, 0x17723, 0x1040, 0x7398, 0x1040, 0x73a7,
        0x177fb, 0x1040, 0x73fb, 0x1040, 0x7492, 0x17896, 0x1040, 0x7496, 0x1040, 0x74ee,
        0x17a31, 0x1040, 0x7631, 0x1040, 0x768b, 0x17a8b, 0x1040, 0x768b, 0x1040, 0x76d0,
        0x17a8b, 0x1040, 0x76d1, 0x1040, 0x770c, 0x17a8b, 0x1040, 0x770d, 0x1040, 0x776d,
        0x17a8b, 0x1040, 0x776e, 0x1040, 0x7864, 0x17c64, 0x1040, 0x7864, 0x1040, 0x78ca,
        0x17c64, 0x1040, 0x78cb, 0x1040, 0x78f4, 0x17cf4, 0x1040, 0x78f4, 0x1040, 0x7953,
        0x17d53, 0x1040, 0x7953, 0x1040, 0x795d, 0x17d70, 0x1040, 0x7970, 0x1040, 0x79d6,
        0x17d70, 0x1040, 0x79d7, 0x1040, 0x79fb, 0x17d70, 0x1040, 0x7a2f, 0x1040, 0x7a35,
        0x17d70, 0x1040, 0x7a36, 0x1040, 0x7a89, 0x17d70, 0x1040, 0x7a8a, 0x1040, 0x7a90,
        0x17d70, 0x1040, 0x7a91, 0x1040, 0x7ac8, 0x17d70, 0x1040, 0x7ac9, 0x1040, 0x7b67,
        0x17d70, 0x1040, 0x7b68, 0x1040, 0x7bbf, 0x17dfb, 0x1040, 0x79fb, 0x1040, 0x7a35,
        0x17dfb, 0x1040, 0x7a36, 0x1040, 0x7a89, 0x17dfb, 0x1040, 0x7a8a, 0x1040, 0x7a90,
        0x17dfb, 0x1040, 0x7a91, 0x1040, 0x7ac8, 0x17dfb, 0x1040, 0x7ac9, 0x1040, 0x7b67,
        0x17dfb, 0x1040, 0x7b68, 0x1040, 0x7bbf, 0x17fbf, 0x1040, 0x7bbf, 0x1040, 0x7bf3,
        0x17ff3, 0x1040, 0x7bf3, 0x1040, 0x7c14, 0x18014, 0x1040, 0x7c14, 0x1040, 0x7c2d,
        0x1802d, 0x1040, 0x7c2d, 0x1040, 0x7c50, 0x1802d, 0x1040, 0x7c51, 0x1040, 0x7c82,
        0x1802d, 0x1040, 0x7c83, 0x1040, 0x7c89, 0x1802d, 0x1040, 0x7c8a, 0x1040, 0x7cad,
        0x1802d, 0x1040, 0x7cae, 0x1040, 0x7d4d, 0x1802d, 0x1040, 0x7d4e, 0x1040, 0x7da4,
        0x181a4, 0x1040, 0x7da4, 0x1040, 0x7dc6, 0x181c6, 0x1040, 0x7dc6, 0x1040, 0x7dfe,
        0x18351, 0x1040, 0x64a8, 0x1040, 0x64ca, 0x18351, 0x1040, 0x64cb, 0x1040, 0x64e4,
        0x18351, 0x1040, 0x7f51, 0x1040, 0x7ff4, 0x18351, 0x1040, 0x7ff5, 0x1040, 0x8020,
        0x18351, 0x1040, 0x8021, 0x1040, 0x805f, 0x18351, 0x1040, 0x8060, 0x1040, 0x807a,
        0x18351, 0x1040, 0x807b, 0x1040, 0x816f, 0x18351, 0x1040, 0x8170, 0x1040, 0x817b,
        0x18351, 0x1040, 0x817c, 0x1040, 0x8194, 0x18351, 0x1040, 0x8195, 0x1040, 0x81c4,
        0x18351, 0x1040, 0x81c5, 0x1040, 0x830d, 0x18351, 0x1040, 0x830e, 0x1040, 0x831d,
        0x18351, 0x1040, 0x831e, 0x1040, 0x8346, 0x18351, 0x1040, 0x8347, 0x1040, 0x8356,
        0x18351, 0x1040, 0x8357, 0x1040, 0x8366, 0x18351, 0x1040, 0x8367, 0x1040, 0x8376,
        0x18351, 0x1040, 0x8377, 0x1040, 0x83a9, 0x18351, 0x1040, 0x83aa, 0x1040, 0x83da,
        0x18351, 0x1040, 0x83db, 0x1040, 0x8403, 0x18351, 0x1040, 0x8404, 0x1040, 0x8414,
        0x18351, 0x1040, 0x8415, 0x1040, 0x850e, 0x18351, 0x1040, 0x850f, 0x1040, 0x854f,
        0x18351, 0x1040, 0x8550, 0x1040, 0x859b, 0x18351, 0x1040, 0x859c, 0x1040, 0x869a,
        0x18351, 0x1040, 0x8703, 0x1040, 0x875d, 0x18351, 0x1040, 0x875e, 0x1040, 0x878c,
        0x18351, 0x1040, 0x878d, 0x1040, 0x87ea, 0x18351, 0x1040, 0x87eb, 0x1040, 0x881c,
        0x18351, 0x1040, 0x881d, 0x1040, 0x8856, 0x18351, 0x1040, 0x8857, 0x1040, 0x8883,
        0x18351, 0x1040, 0x8b9a, 0x1040, 0x8bae, 0x18351, 0x1040, 0x8baf, 0x1040, 0x8bec,
        0x18a9a, 0x1040, 0x869a, 0x1040, 0x8703, 0x18c83, 0x1040, 0x869a, 0x1040, 0x8703,
        0x18c83, 0x1040, 0x8883, 0x1040, 0x88be, 0x18cbe, 0x1040, 0x88be, 0x1040, 0x8928,
        0x18d28, 0x1040, 0x8928, 0x1040, 0x896a, 0x18d28, 0x1040, 0x896b, 0x1040, 0x89e3,
        0x18d28, 0x1040, 0x89e4, 0x1040, 0x8a00, 0x18d28, 0x1040, 0x8a01, 0x1040, 0x8a10,
        0x18d28, 0x1040, 0x8a11, 0x1040, 0x8a46, 0x18d28, 0x1040, 0x8a47, 0x1040, 0x8a53,
        0x18d28, 0x1040, 0x8a54, 0x1040, 0x8a8d, 0x18d28, 0x1040, 0x8a8e, 0x1040, 0x8ac9,
        0x18d28, 0x1040, 0x8aca, 0x1040, 0x8aed, 0x18d28, 0x1040, 0x8aee, 0x1040, 0x8b26,
        0x18d28, 0x1040, 0x8b27, 0x1040, 0x8b98, 0x19214, 0x1040, 0x8e14, 0x1040, 0x8e56,
        0x19214, 0x1040, 0x8e57, 0x1040, 0x8e6d, 0x1926d, 0x1040, 0x8e6d, 0x1040, 0x8eae,
        0x192ae, 0x1040, 0x8eae, 0x1040, 0x8eda, 0x192da, 0x1040, 0x8eda, 0x1040, 0x8f0a,
        0x1930a, 0x1040, 0x8f0a, 0x1040, 0x8f3f, 0x1933f, 0x1040, 0x8f3f, 0x1040, 0x8f51,
        0x19351, 0x1040, 0x8f51, 0x1040, 0x8fe4, 0x19420, 0x1040, 0x9020, 0x1040, 0x9062,
        0x19462, 0x1040, 0x9062, 0x1040, 0x90c2, 0x194c4, 0x1040, 0x90c4, 0x1040, 0x9120,
        0x194c4, 0x1040, 0x9121, 0x1040, 0x9153, 0x194c4, 0x1040, 0x9250, 0x1040, 0x92ae,
        0x194c4, 0x1040, 0x9b37, 0x1040, 0x9b5f, 0x194c4, 0x1040, 0xbfb9, 0x1040, 0xc0bd,
        0x19553, 0x1040, 0x9153, 0x1040, 0x9167, 0x19553, 0x1040, 0x9168, 0x1040, 0x9173,
        0x19577, 0x1040, 0x9177, 0x1040, 0x9193, 0x19593, 0x1040, 0x9193, 0x1040, 0x91ea,
        0x195ea, 0x1040, 0x91ea, 0x1040, 0x921d, 0x1961d, 0x1040, 0x921d, 0x1040, 0x9250,
        0x196dd, 0x1040, 0x92dd, 0x1040, 0x92f3, 0x196f3, 0x1040, 0x92f3, 0x1040, 0x930e,
        0x196f3, 0x1040, 0x930f, 0x1040, 0x9331, 0x19731, 0x1040, 0x9331, 0x1040, 0x9341,
        0x199c8, 0x1040, 0x95c8, 0x1040, 0x96f4, 0x19af6, 0x1040, 0x96f6, 0x1040, 0x971c,
        0x19b1c, 0x1040, 0x971c, 0x1040, 0x973c, 0x19b40, 0x1040, 0x9740, 0x1040, 0x975f,
        0x19bac, 0x1040, 0x97ac, 0x1040, 0x97da, 0x19bdc, 0x1040, 0x97dc, 0x1040, 0x97f8,
        0x19c05, 0x1040, 0x9805, 0x1040, 0x9843, 0x19c43, 0x1040, 0x9843, 0x1040, 0x985a,
        0x19e18, 0x1040, 0x9a18, 0x1040, 0x9a7c, 0x19e18, 0x1040, 0x9a7d, 0x1040, 0x9ab5,
        0x19eb5, 0x1040, 0x9ab5, 0x1040, 0x9abb, 0x19ebb, 0x1040, 0x9abb, 0x1040, 0x9ad0,
        0x19ed0, 0x1040, 0x9ad0, 0x1040, 0x9adc, 0x19ee5, 0x1040, 0x9ae5, 0x1040, 0x9b12,
        0x19f12, 0x1040, 0x9b12, 0x1040, 0x9b37, 0x19f8a, 0x1040, 0x9b8a, 0x1040, 0x9baf,
        0x19f8a, 0x1040, 0x9bb0, 0x1040, 0x9bb8, 0x1a102, 0x1040, 0x9d02, 0x1040, 0x9d11,
        0x1a111, 0x1040, 0x9d11, 0x1040, 0x9d20, 0x1a120, 0x1040, 0x9d20, 0x1040, 0x9d21,
        0x1a121, 0x1040, 0x9d21, 0x1040, 0x9d37, 0x1a137, 0x1040, 0x9d37, 0x1040, 0x9d3f,
        0x1a13f, 0x1040, 0x9d3f, 0x1040, 0x9d55, 0x1a155, 0x1040, 0x9d55, 0x1040, 0x9d68,
        0x1a168, 0x1040, 0x9d68, 0x1040, 0x9dbc, 0x1a1bc, 0x1040, 0x9dbc, 0x1040, 0x9dd6,
        0x1a1d7, 0x1040, 0x9dd7, 0x1040, 0x9de4, 0x1a1e4, 0x1040, 0x9de4, 0x1040, 0x9de6,
        0x1a1e6, 0x1040, 0x9de6, 0x1040, 0x9dfd, 0x1a1fd, 0x1040, 0x9dfd, 0x1040, 0x9e34,
        0x1a234, 0x1040, 0x9e34, 0x1040, 0x9e3c, 0x1a23e, 0x1040, 0x9e3e, 0x1040, 0x9e4c,
        0x1a24c, 0x1040, 0x9e4c, 0x1040, 0x9e51, 0x1a257, 0x1040, 0x9e57, 0x1040, 0x9ec4,
        0x1a2c4, 0x1040, 0x9ec4, 0x1040, 0x9ee7, 0x1a2c4, 0x1040, 0x9ee8, 0x1040, 0x9ef4,
        0x1a2f6, 0x1040, 0x9ef6, 0x1040, 0x9f41, 0x1a389, 0x1040, 0x9f89, 0x1040, 0x9fc1,
        0x1a389, 0x1040, 0x9fc2, 0x1040, 0x9fcf, 0x1a3cf, 0x1040, 0x9fcf, 0x1040, 0xa037,
        0x1a437, 0x1040, 0xa037, 0x1040, 0xa04f, 0x1a44f, 0x1040, 0xa04f, 0x1040, 0xa05c,
        0x1a45c, 0x1040, 0xa05c, 0x1040, 0xa0b1, 0x1a54a, 0x1040, 0xa14a, 0x1040, 0xa16b,
        0x1a56b, 0x1040, 0xa16b, 0x1040, 0xa192, 0x1a592, 0x1040, 0xa192, 0x1040, 0xa1f0,
        0x1a5e3, 0x1040, 0xa1e3, 0x1040, 0xa1f0, 0x1a5f0, 0x1040, 0xa1f0, 0x1040, 0xa21c,
        0x1a65b, 0x1040, 0xa25b, 0x1040, 0xa27b, 0x1a67b, 0x1040, 0xa27b, 0x1040, 0xa293,
        0x1a67b, 0x1040, 0xa2fb, 0x1040, 0xa323, 0x1a693, 0x1040, 0xa293, 0x1040, 0xa29d,
        0x1a693, 0x1040, 0xa2fb, 0x1040, 0xa323, 0x1a69d, 0x1040, 0xa29d, 0x1040, 0xa2a8,
        0x1a69d, 0x1040, 0xa2fb, 0x1040, 0xa323, 0x1ad6e, 0x1040, 0xa96e, 0x1040, 0xa9b0,
        0x1adb0, 0x1040, 0xa9b0, 0x1040, 0xa9b7, 0x1adcb, 0x1040, 0xa9cb, 0x1040, 0xaa03,
        0x1ae03, 0x1040, 0xaa03, 0x1040, 0xaa24, 0x1ae81, 0x1040, 0xaa81, 0x1040, 0xaacd,
        0x1aecd, 0x1040, 0xaacd, 0x1040, 0xaae6, 0x1aecd, 0x1040, 0xb782, 0x1040, 0xb874,
        0x1b95d, 0x1040, 0xb55d, 0x1040, 0xb618, 0x1bb3f, 0x1040, 0xb658, 0x1040, 0xb782,
        0x1bc92, 0x1040, 0xb892, 0x1040, 0xb8b7, 0x1bcb7, 0x1040, 0xb8b7, 0x1040, 0xb8cd,
        0x1bf7c, 0x1040, 0xbb7c, 0x1040, 0xbba0, 0x1bfa0, 0x1040, 0xbba0, 0x1040, 0xbbc8,
        0x1bfa0, 0x1040, 0xbbc9, 0x1040, 0xbbe8, 0x1bfa0, 0x1040, 0xbbe9, 0x1040, 0xbc09,
        0x1c0a8, 0x1040, 0xbca8, 0x1040, 0xbd64, 0x1c164, 0x1040, 0xbd64, 0x1040, 0xbda2,
        0x1c1a2, 0x1040, 0xbda2, 0x1040, 0xbdb6, 0x1c1a2, 0x1040, 0xbdb7, 0x1040, 0xbdc4,
        0x1c1a2, 0x1040, 0xbdc5, 0x1040, 0xbdd9, 0x1c1a2, 0x1040, 0xbdda, 0x1040, 0xbdf2,
        0x1c276, 0x1040, 0xbe76, 0x1040, 0xbead, 0x1c276, 0x1040, 0xbeae, 0x1040, 0xbed2,
        0x1c276, 0x1040, 0xbed3, 0x1040, 0xbedb, 0x1c276, 0x1040, 0xbee2, 0x1040, 0xbf07,
        0x1c276, 0x1040, 0xbf08, 0x1040, 0xbf81, 0x1c276, 0x1040, 0xbf82, 0x1040, 0xbfb0,
        0x1c359, 0x1040, 0xbf59, 0x1040, 0xbf81, 0x1c359, 0x1040, 0xbf82, 0x1040, 0xbfb0,
        0x1c4bd, 0x1040, 0xc0bd, 0x1040, 0xc0ca, 0x1c4ca, 0x1040, 0xc0ca, 0x1040, 0xc0d1,
        0x1c4e1, 0x1040, 0xc0e1, 0x1040, 0xc0e2, 0x1c4e2, 0x1040, 0xc0e2, 0x1040, 0xc0ef,
    };

    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs < map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
#endif
