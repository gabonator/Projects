#include "cicoctx.h"
using namespace CicoContext;

void sub_1c276();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    cs = 0x1040;
    ds = 0x1030;
    es = 0x1030;
    ss = 0x1000;
    sp = 0x0400;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/rick2/dos", "MAIN.EXE", 50927);
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
void sub_1c4bd();
void sub_1c4ca();
void sub_1c4e1();
void sub_1c4e2();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    if(seg == 0x1040)
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
        default:
            break;
    }
    if(seg == 0x1040)
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
        default:
            break;
    }
    assert(0);
}
void sub_10524()
{
    ah = 0x0f;
    interrupt(0x10);
    memory(ds, 0x006a) = al;
    ax = 0x000d;
    interrupt(0x10);
}
void sub_10533()
{
    ah = 0x48;
    bx = 0x0200;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1053f;
    goto loc_19731;
loc_1053f:
    memory16(ds, 0x004c) = ax;
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1054e;
    goto loc_19731;
loc_1054e:
    memory16(ds, 0x0062) = ax;
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1055d;
    goto loc_19731;
loc_1055d:
    memory16(ds, 0x0064) = ax;
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1056c;
    goto loc_19731;
loc_1056c:
    memory16(ds, 0x0066) = ax;
    ah = 0x48;
    bx = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1057b;
    goto loc_19731;
loc_1057b:
    memory16(ds, 0x0068) = ax;
    ah = 0x48;
    bx = 0x0080;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1058a;
    goto loc_19731;
loc_1058a:
    memory16(ds, 0x0052) = ax;
    memory16(ds, 0x0056) = 0xa400;
    return;
    //   gap of 37277 bytes
loc_19731:
    ah = 0x09;
    dx = 0x1040;
    ds = dx;
    dx = 0x92b1;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
}
void sub_10594()
{
    ax = memory16(ds, 0x0062);
    cx = 0x4344;
    dx = 0x00cd;
    sub_1a65b();
}
void sub_105a1()
{
    ax = memory16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00e5;
    sub_1a65b();
    cx = 0x0400;
    ax = 0xa680;
    sub_105f7();
    ax = memory16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00f1;
    sub_1a65b();
    cx = 0x0080;
    ax = 0xa700;
    sub_105f7();
}
void sub_105cc()
{
    ax = memory16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00d9;
    sub_1a65b();
    cx = 0x0400;
    ax = 0xa600;
    sub_105f7();
    ax = memory16(ds, 0x004c);
    cx = 0x0000;
    dx = 0x00fd;
    sub_1a65b();
    cx = 0x0180;
    ax = 0xa980;
    sub_105f7();
}
void sub_105f7()
{
    push(ds);
    push(es);
    bp = cx;
    dx = memory16(ds, 0x004c);
    ds = dx;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = pop();
    cx = bp;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10661()
{
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
}
void sub_10702()
{
    memory(ds, 0x0279) = 0x00;
    si = 0x029a;
    di = 0x02ce;
    cx = 0x0033;
    rep_movsb<MemData, MemData, DirForward>();
    ax = 0x1a00;
    interrupt(0x10);
    if ((char)bl <= (char)0x05)
        goto loc_10731;
    if ((char)bl < (char)0x07)
        goto loc_10731;
    if ((char)bl > (char)0x08)
        goto loc_10731;
    si = 0x028a;
    memory(ds, 0x0279) = 0x01;
    goto loc_1073e;
loc_10731:
    si = 0x027a;
    memory(ds, 0x0279) = 0x00;
    memory(ds, 0x0278) = 0x01;
loc_1073e:
    memory(ds, 0x0301) = 0x00;
    cx = 0x0010;
loc_10746:
    ah = 0x10;
    al = 0x00;
    bh = memory(ds, si);
    si++;
    bl = memory(ds, 0x0301);
    memory(ds, 0x0301) = memory(ds, 0x0301) + 1;
    push(si);
    push(cx);
    interrupt(0x10);
    cx = pop();
    si = pop();
    if (--cx)
        goto loc_10746;
    if (memory(ds, 0x0279) != 0x01)
        goto loc_1076a;
    sub_10776();
    sub_1079d();
loc_1076a:
    di = 0x029a;
    si = 0x02ce;
    cx = 0x0033;
    rep_movsb<MemData, MemData, DirForward>();
}
void sub_10776()
{
    si = 0x029a;
    memory(ds, 0x0301) = 0x00;
    cx = 0x0010;
loc_10781:
    push(cx);
    bh = 0x09;
    al = memory(ds, si);
    imul(bh);
    memory(ds, si) = al;
    si++;
    al = memory(ds, si);
    imul(bh);
    memory(ds, si) = al;
    si++;
    al = memory(ds, si);
    imul(bh);
    memory(ds, si) = al;
    si++;
    cx = pop();
    if (--cx)
        goto loc_10781;
}
void sub_1079d()
{
    bx = 0;
    cx = 0x0010;
    dx = 0x029a;
    al = 0x12;
    ah = 0x10;
    interrupt(0x10);
}
void sub_107ac()
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
    es = memory16(ds, 0x005a);
    cx = 0x0027;
    ax = 0xa980;
    ds = ax;
loc_107ce:
    ax = 0;
    al = memory(cs, si);
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
loc_107ee:
    es = pop();
    ds = pop();
}
void sub_107f1()
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
    es = memory16(ds, 0x005a);
    cx = 0x0027;
    ax = 0xa600;
    ds = ax;
loc_10813:
    ax = 0;
    al = memory(cs, si);
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
loc_10833:
    es = pop();
    ds = pop();
}
void sub_10836()
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
    es = memory16(ds, 0x005c);
    cx = 0x0027;
    ax = 0xa600;
    ds = ax;
loc_10858:
    ax = 0;
    al = memory(cs, si);
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
loc_10878:
    es = pop();
    ds = pop();
}
void sub_1087b()
{
    cx = 0x0100;
    ax = 0x0000;
    dx = 0x0008;
    di = 0x2f73;
loc_10887:
    stosw<MemData, DirForward>();
    ax += dx;
    if (--cx)
        goto loc_10887;
}
void sub_1088d()
{
    push(ds);
    push(es);
    es = memory16(ds, 0x0056);
    ax = 0xa680;
    ds = ax;
    cx = 0x0020;
loc_1089b:
    bp = cx;
    ax = 0;
    al = memory(cs, bx);
    if ((short)ax < (short)0x00f8)
        goto loc_108aa;
    sub_19593();
loc_108aa:
    bx++;
    ax <<= 1;
    ax += 0x2f73;
    si = ax;
    si = memory16(cs, si);
    cx = 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += cx;
    movsb<MemVideo, MemVideo, DirForward>();
    di = (di + 0xff20) & 0xffff;
    cx = bp;
    if (--cx)
        goto loc_1089b;
    di += 0x00e0;
    es = pop();
    ds = pop();
}
void sub_108dd()
{
    bx = 0x571c;
    di = 0x1e00;
    sub_1088d();
    di = 0x0000;
    bx = 0x573c;
    cx = 0x001a;
loc_108ef:
    push(cx);
    sub_1088d();
    cx = pop();
    if (--cx)
        goto loc_108ef;
}
void sub_108f7()
{
    if (!ax)
        return;
    push(ds);
    push(es);
    dx = ax;
    bp = 0x0020;
    bx = 0x0008;
    es = memory16(cs, 0x005a);
    ds = memory16(cs, 0x0056);
loc_1090f:
    cx = bp;
    rep_movsb<MemVideo, MemVideo, DirForward>();
    di += bx;
    dx--;
    if (dx != 0)
        goto loc_1090f;
    es = pop();
    ds = pop();
}
void sub_1091b()
{
    dx = memory16(ds, 0x6c45);
    dx += 0x00c0;
    dx &= 0x00ff;
    if ((short)dx > (short)memory16(ds, 0x6c45))
        goto loc_10969;
    ax = dx;
    si = 0x0000;
    di = 0x0144;
    dx = 0x0100;
    dx -= memory16(ds, 0x6c45);
    dx += dx;
    bx = 0x3173;
    bx += dx;
    di += memory16(ds, bx);
    sub_108f7();
    si = 0x0000;
    dx = memory16(ds, 0x6c45);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    di = 0x0144;
    ax = 0x0100;
    ax -= memory16(ds, 0x6c45);
    sub_108f7();
    return;
loc_10969:
    si = 0x0000;
    dx = memory16(ds, 0x6c45);
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
void sub_10986()
{
    bx = 0x573c;
    ax = memory16(ds, 0x6c45);
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
void sub_109a5()
{
    bx = 0x5a5c;
    ax = memory16(ds, 0x6c45);
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
void sub_109c4()
{
    di = 0x3173;
    ax = 0;
    cx = 0x0100;
loc_109cc:
    stosw<MemData, DirForward>();
    ax += 0x0028;
    if (--cx)
        goto loc_109cc;
}
void sub_109d3()
{
    memory16(ds, 0x005a) = 0xa000;
    memory16(ds, 0x005c) = 0xa200;
    memory16(ds, 0x005e) = 0x0000;
    memory16(ds, 0x0060) = 0x2000;
}
void sub_109ee()
{
    push(ds);
    push(es);
    push(ax);
    push(cx);
    push(dx);
    ax = memory16(ds, 0x005a);
    dx = memory16(ds, 0x005c);
    memory16(ds, 0x005c) = ax;
    memory16(ds, 0x005a) = dx;
    ax = memory16(ds, 0x005e);
    dx = memory16(ds, 0x0060);
    memory16(ds, 0x0060) = ax;
    memory16(ds, 0x005e) = dx;
    cx = memory16(ds, 0x0060);
    push(dx);
    push(ax);
    ax = 0x0040;
    es = ax;
    dx = memoryBiosGet16(es, 0x0063);
    dx += 0x0006;
loc_10a22:
    in(al, dx);
    al &= 0x08;
    if (al != 0)
        goto loc_10a22;
loc_10a27:
    in(al, dx);
    al &= 0x08;
    if (al == 0)
        goto loc_10a27;
    dx -= 0x0006;
    flags.interrupts = false;
    al = 0x0c;
    out(dx, al);
    dx++;
    al = ch;
    out(dx, al);
    dx--;
    al = 0x0d;
    out(dx, al);
    dx++;
    al = cl;
    out(dx, al);
    flags.interrupts = true;
    ah = ch;
    ax <<= 1;
    memoryBiosSet16(es, 0x004e, ax);
    ax = 0x0040;
    es = ax;
    dx = memoryBiosGet16(es, 0x0063);
    dx += 0x0006;
loc_10a55:
    in(al, dx);
    al &= 0x08;
    if (al != 0)
        goto loc_10a55;
loc_10a5a:
    in(al, dx);
    al &= 0x08;
    if (al == 0)
        goto loc_10a5a;
    ax = pop();
    dx = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    es = pop();
    ds = pop();
}
void sub_10a67()
{
    if (memory16(ds, 0x9173) != 0x0000)
        goto loc_10a6f;
    return;
loc_10a6f:
    bx = memory16(ds, 0x9175);
    cx = 0x0008;
loc_10a76:
    push(cx);
    al = memory(ds, bx);
    if (!al)
        goto loc_10ad2;
    if (al & 0x80)
        goto loc_10adc;
    dx = 0;
    dl = memory(ds, bx + 1);
    cl = dl;
    cl++;
    cl &= 0x03;
    dl &= 0xfc;
    dl |= cl;
    memory(ds, bx + 1) = dl;
    di = memory16(ds, bx + 4);
    bp = memory16(cs, bx + 6);
    si = 0;
    push(ds);
    push(es);
    es = memory16(ds, 0x0056);
    ax = 0xa700;
    ds = ax;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    si = dx;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x001f;
    movsb<MemVideo, MemVideo, DirForward>();
    es = pop();
    ds = pop();
loc_10ad2:
    bx += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_10a76;
    goto loc_10ae2;
loc_10adc:
    bx = 0x54fa;
    cx = pop();
    if (--cx)
        goto loc_10a76;
loc_10ae2:
    memory16(ds, 0x9175) = bx;
}
void sub_10ae7()
{
    push(ds);
    push(es);
    bx = 0x573c;
    di = 0x0144;
    es = memory16(ds, 0x0056);
    ax = 0xa680;
    ds = ax;
    cx = 0x0018;
    dx = memory16(cs, 0x8bf0);
    dx &= 0x0007;
    if (dx == 0)
        goto loc_10b43;
    si = dx;
    bp = 0x0020;
    dx ^= 0x0007;
loc_10b0d:
    push(si);
    push(di);
    ax = 0;
    al = memory(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    push(dx);
loc_10b1e:
    movsb<MemData, MemData, DirForward>();
    di += 0x0027;
    dx--;
    if ((short)dx >= 0)
        goto loc_10b1e;
    dx = pop();
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp != 0)
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
loc_10b43:
    bp = 0x0020;
loc_10b46:
    push(si);
    push(di);
    ax = 0;
    al = memory(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    movsb<MemVideo, MemVideo, DirForward>();
    di += 0x0027;
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp != 0)
        goto loc_10b46;
    di += 0x0120;
loc_10b80:
    if (--cx)
        goto loc_10b43;
    dx = memory16(cs, 0x8bf0);
    dx &= 0x0007;
    if (dx == 0)
        goto loc_10bae;
    bp = 0x0020;
loc_10b8f:
    push(si);
    push(di);
    ax = 0;
    al = memory(cs, bx);
    bx++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    push(dx);
loc_10ba0:
    movsb<MemData, MemData, DirForward>();
    di += 0x0027;
    dx--;
    if ((short)dx >= 0)
        goto loc_10ba0;
    dx = pop();
    di = pop();
    si = pop();
    di++;
    bp--;
    if (bp != 0)
        goto loc_10b8f;
loc_10bae:
    es = pop();
    ds = pop();
}
void sub_10bb1()
{
    ax = memory16(ds, 0x005a);
    push(ax);
    ax = memory16(ds, 0x0056);
    memory16(ds, 0x005a) = ax;
    callIndirect(cs, memory16(ds, 0x003e));
    ax = pop();
    memory16(ds, 0x005a) = ax;
}
void sub_10bc4()
{
    cx = memory16(ds, 0x96f4);
    push(cx);
    memory16(ds, 0x96f4) = 0x0001;
    push(ax);
    push(dx);
    callIndirect(cs, memory16(ds, 0x0024));
    memory16(ds, 0x0b1c) = 0x0000;
    callIndirect(cs, memory16(ds, 0x003e));
    memory16(ds, 0x0b1c) = 0x0001;
    dx = pop();
    ax = pop();
    sub_19351();
    sub_19214();
    sub_10ae7();
    sub_1618f();
    sub_15fe4();
    memory(ds, 0x5b3e) = 0x01;
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
    sub_10bb1();
    sub_19af6();
    callIndirect(cs, memory16(ds, 0x001c));
    si = 0x0162;
    cx = 0x0010;
loc_10c15:
    push(cx);
    push(si);
    sub_10c98();
    callIndirect(cs, memory16(ds, 0x001c));
    si = pop();
    cx = pop();
    si = (si + 0xfffe) & 0xffff;
    if (--cx)
        goto loc_10c15;
    sub_17047();
    cx = pop();
    memory16(ds, 0x96f4) = cx;
}
void sub_10c2e()
{
    cx = memory16(ds, 0x96f4);
    push(cx);
    memory16(ds, 0x96f4) = 0x0001;
    push(ax);
    push(dx);
    callIndirect(cs, memory16(ds, 0x0024));
    memory16(ds, 0x0b1c) = 0x0000;
    callIndirect(cs, memory16(ds, 0x003e));
    memory16(ds, 0x0b1c) = 0x0001;
    dx = pop();
    ax = pop();
    sub_19351();
    sub_19214();
    sub_1618f();
    sub_10ae7();
    sub_15fe4();
    memory(ds, 0x5b3e) = 0x01;
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
    sub_10bb1();
    sub_19af6();
    callIndirect(cs, memory16(ds, 0x001c));
    si = 0x0144;
    cx = 0x0010;
loc_10c7f:
    push(cx);
    push(si);
    sub_10ccd();
    callIndirect(cs, memory16(ds, 0x001c));
    si = pop();
    cx = pop();
    si += 0x0002;
    if (--cx)
        goto loc_10c7f;
    sub_17047();
    cx = pop();
    memory16(ds, 0x96f4) = cx;
}
void sub_10c98()
{
    push(ds);
    push(es);
    bx = 0x0144;
    di = bx;
    bp = 0x00c0;
    es = memory16(ds, 0x005a);
    ax = memory16(ds, 0x0056);
    dx = memory16(ds, 0x005c);
loc_10cad:
    ds = ax;
    movsb<MemVideo, MemVideo, DirForward>();
    movsb<MemVideo, MemVideo, DirForward>();
    ds = dx;
    push(si);
    si = bx;
    cx = 0x001e;
    rep_movsb<MemVideo, MemVideo, DirForward>();
    bx = si;
    si = pop();
    bx += 0x000a;
    si += 0x0026;
    di += 0x0008;
    bp--;
    if (bp != 0)
        goto loc_10cad;
    es = pop();
    ds = pop();
}
void sub_10ccd()
{
    push(ds);
    push(es);
    bx = 0x0146;
    di = 0x0144;
    bp = 0x00c0;
    es = memory16(ds, 0x005a);
    ax = memory16(ds, 0x0056);
    dx = memory16(ds, 0x005c);
loc_10ce3:
    ds = dx;
    push(si);
    si = bx;
    cx = 0x001e;
    rep_movsb<MemVideo, MemVideo, DirForward>();
    bx = si;
    si = pop();
    ds = ax;
    movsb<MemVideo, MemVideo, DirForward>();
    movsb<MemVideo, MemVideo, DirForward>();
    bx += 0x000a;
    si += 0x0026;
    di += 0x0008;
    bp--;
    if (bp != 0)
        goto loc_10ce3;
    es = pop();
    ds = pop();
}
void sub_10d03()
{
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memory16(cs, 0x005a);
    si = 0x0100;
    lodsb<MemVideo, DirForward>();
    di = 0;
    cx = 0x1f40;
    rep_stosb<MemVideo, DirForward>();
    es = pop();
    ds = pop();
    sub_19b1c();
    callIndirect(cs, memory16(ds, 0x001c));
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memory16(cs, 0x005a);
    si = 0x0100;
    lodsb<MemVideo, DirForward>();
    di = 0;
    cx = 0x1f40;
    rep_stosb<MemVideo, DirForward>();
    es = pop();
    ds = pop();
}
void sub_10d3d()
{
    ax = memory16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x010a;
    sub_1a65b();
    sub_10d5c();
    ax = memory16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x0116;
    sub_1a65b();
    sub_10daa();
}
void sub_10d5c()
{
    push(ds);
    push(es);
    ax = memory16(ds, 0x0062);
    ds = ax;
    ax = 0xa780;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10daa()
{
    push(ds);
    push(es);
    ax = memory16(ds, 0x0062);
    ds = ax;
    ax = 0xa780;
    es = ax;
    si = 0;
    di = 0;
    push(dx);
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = pop();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemVideo, MemData, DirForward>();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(dx);
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    dx = pop();
    es = pop();
    ds = pop();
}
void sub_10df8()
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
    rep_movsb<MemVideo, MemVideo, DirForward>();
    ax = 0xa780;
    ds = ax;
    ax = 0xa200;
    es = ax;
    si = 0;
    di = si;
    cx = 0x1f40;
    rep_movsb<MemVideo, MemVideo, DirForward>();
    es = pop();
    ds = pop();
}
void sub_10e23()
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
void sub_10e40()
{
    push(ds);
    push(es);
    ax = 0xa600;
    ds = ax;
    es = memory16(cs, 0x0056);
loc_10e4c:
    push(cx);
    push(si);
    push(di);
loc_10e4f:
    ax = 0;
    al = memory(cs, si);
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
    if (cl != 0)
        goto loc_10e4f;
    di = pop();
    di += 0x0140;
    si = pop();
    si += 0x0020;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_10e4c;
    es = pop();
    ds = pop();
}
void sub_10e7f()
{
    push(ds);
    push(es);
    es = memory16(ds, 0x005a);
    ds = memory16(ds, 0x0056);
    di = 0x0144;
    si = di;
    bp = 0x00c0;
loc_10e91:
    cx = 0x0020;
    push(si);
    push(di);
    rep_movsb<MemVideo, MemVideo, DirForward>();
    di = pop();
    si = pop();
    si += 0x0028;
    di += 0x0028;
    bp--;
    if (bp != 0)
        goto loc_10e91;
    es = pop();
    ds = pop();
}
void sub_10ea6()
{
    push(ds);
    push(es);
    ax = 0xa700;
    ds = ax;
    es = memory16(cs, 0x0056);
    si = 0x0100;
    lodsb<MemVideo, DirForward>();
    di = 0;
    cx = 0x1f40;
    rep_stosb<MemVideo, DirForward>();
    es = pop();
    ds = pop();
}
void sub_10ec0()
{
    dx = memory16(ds, 0x005a);
    push(dx);
    dx = memory16(ds, 0x0056);
    memory16(ds, 0x005a) = dx;
    callIndirect(cs, memory16(ds, 0x000c));
    dx = pop();
    memory16(ds, 0x005a) = dx;
}
void sub_10ed8()
{
}
void sub_10ee4()
{
}
void sub_10ee5()
{
}
void sub_10ee6()
{
}
void sub_10ee7()
{
}
void sub_10ee8()
{
    ax = memory16(cs, 0x96f4);
    if (ax == 0x0001)
        return;
    ax--;
    memory16(cs, 0x96f4) = ax;
}
void sub_11162()
{
    push(ds);
    push(es);
    es = memory16(ds, 0x005a);
    si = 0x0b00;
    dx = 0x03ce;
    ax = 0x0001;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    ax = 0x0005;
    out(dx, ax);
loc_1117a:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        goto loc_11196;
    if (!ax)
        goto loc_11191;
    if (memory16(ds, si + 10) == 0x00fe)
        goto loc_11191;
    push(ds);
    push(si);
    callIndirect(cs, memory16(ds, 0x0040));
    si = pop();
    ds = pop();
loc_11191:
    si += 0x001c;
    goto loc_1117a;
loc_11196:
    si = 0x0b56;
loc_11199:
    ax = memory16(ds, si);
    if (ah & 0x80)
        goto loc_111b7;
    if (!(al & 0x01))
        goto loc_111b2;
    if (memory16(ds, si + 10) == 0x00fe)
        goto loc_111b2;
    push(ds);
    push(si);
    callIndirect(cs, memory16(ds, 0x0040));
    si = pop();
    ds = pop();
loc_111b2:
    si += 0x0034;
    goto loc_11199;
loc_111b7:
    si = 0x0c28;
loc_111ba:
    ax = memory16(ds, si);
    if (ah & 0x80)
        goto loc_111d8;
    if (!(al & 0x01))
        goto loc_111d3;
    if (memory16(ds, si + 10) == 0x00fe)
        goto loc_111d3;
    push(ds);
    push(si);
    callIndirect(cs, memory16(ds, 0x0040));
    si = pop();
    ds = pop();
loc_111d3:
    si += 0x0034;
    goto loc_111ba;
loc_111d8:
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dl = 0xce;
    ax = 0x0105;
    out(dx, ax);
    ax = 0x0001;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    es = pop();
    ds = pop();
}
void sub_111f1()
{
    bp = 0;
    ax = memory16(ds, si + 4);
    ax -= 0x0038;
    dx = memory16(ds, 0x8bf0);
    dx &= 0x0007;
    ax -= dx;
    if ((short)ax >= (short)0x0008)
        goto loc_1122c;
    cx = 0x0008;
    cx -= ax;
    ax = cx;
    cx = -cx;
    tx = cx;
    cx += 0x0015;
    if ((short)tx + (short)0x0015 > 0)
        goto loc_11218;
    return;
loc_11218:
    ax <<= 1;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    bp = ax;
    ax = 0x0140;
    goto loc_11252;
loc_1122c:
    if ((short)ax <= (short)0x00b3)
        goto loc_11241;
    cx = 0x00b3;
    cx -= ax;
    tx = cx;
    cx += 0x0015;
    if ((short)tx + (short)0x0015 > 0)
        goto loc_1123e;
    return;
loc_1123e:
    goto loc_11244;
loc_11241:
    cx = 0x0015;
loc_11244:
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
loc_11252:
    di = ax;
    ax = memory16(ds, si + 2);
    ax += 0x0020;
    ax &= 0xfff8;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    di += ax;
    ax = memory16(ds, si + 10);
    if ((short)ax < (short)0x0080)
        goto loc_11270;
    ax -= 0x0040;
loc_11270:
    bx = 0x01a4;
    mul(bx);
    bx = memory16(ds, si + 2);
    bx += 0x0020;
    bx &= 0x0006;
    bx += 0x0062;
    ds = memory16(ds, bx);
    si = ax;
    si += bp;
    bp = 0x0024;
    dh = 0x03;
loc_1128d:
    push(cx);
    cx = 0x0004;
loc_11291:
    ah = memory(ds, si);
    if (!ah)
        goto loc_112c9;
    al = 0x08;
    dl = 0xce;
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0f02;
    out(dx, ax);
    ah = memoryVideoGet(es, di);
    ah = 0x01;
    out(dx, ax);
    ah = memory(ds, si + 1);
    memoryVideoSet(es, di, ah);
    ah = 0x02;
    out(dx, ax);
    ah = memory(ds, si + 2);
    memoryVideoSet(es, di, ah);
    ah = 0x04;
    out(dx, ax);
    ah = memory(ds, si + 3);
    memoryVideoSet(es, di, ah);
    ah = 0x08;
    out(dx, ax);
    ah = memory(ds, si + 4);
    memoryVideoSet(es, di, ah);
loc_112c9:
    di++;
    si += 0x0005;
    if (--cx)
        goto loc_11291;
    di += bp;
    cx = pop();
    cx--;
    if (cx != 0)
        goto loc_1128d;
}
void sub_112d6()
{
    push(ds);
    push(es);
    ds = memory16(ds, 0x0062);
    bp = 0x0064;
    di = 0;
    si = 0;
    cx = 0x0888;
loc_112e6:
    push(cx);
    push(si);
    push(di);
    ah = memory(ds, si);
    al = memory(ds, si + 5);
    bh = memory(ds, si + 10);
    bl = 0x00;
    push(bp);
    cx = 0x0003;
loc_112f7:
    flags.carry = false;
    ah = rcr(ah, 0x01);
    al = rcr(al, 0x01);
    bh = rcr(bh, 0x01);
    bl = rcr(bl, 0x01);
    flags.carry = false;
    ah = rcr(ah, 0x01);
    al = rcr(al, 0x01);
    bh = rcr(bh, 0x01);
    bl = rcr(bl, 0x01);
    es = memory16(cs, bp);
    bp++;
    bp++;
    memory(es, di) = ah;
    memory(es, di + 5) = al;
    memory(es, di + 10) = bh;
    memory(es, di + 15) = bl;
    if (--cx)
        goto loc_112f7;
    bp = pop();
    si++;
    di++;
    cx = 0x0004;
loc_11326:
    push(cx);
    ah = memory(ds, si);
    al = memory(ds, si + 5);
    bh = memory(ds, si + 10);
    bl = 0x00;
    push(bp);
    cx = 0x0003;
loc_11335:
    flags.carry = false;
    ah = rcr(ah, 0x01);
    al = rcr(al, 0x01);
    bh = rcr(bh, 0x01);
    bl = rcr(bl, 0x01);
    flags.carry = false;
    ah = rcr(ah, 0x01);
    al = rcr(al, 0x01);
    bh = rcr(bh, 0x01);
    bl = rcr(bl, 0x01);
    es = memory16(cs, bp);
    bp++;
    bp++;
    memory(es, di) = ah;
    memory(es, di + 5) = al;
    memory(es, di + 10) = bh;
    memory(es, di + 15) = bl;
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
    if (cx == 0)
        goto loc_11373;
    goto loc_112e6;
loc_11373:
    es = pop();
    ds = pop();
}
void sub_11376()
{
    push(ds);
    push(es);
    es = memory16(ds, 0x005a);
    si = 0x0b00;
    dx = 0x03ce;
    ax = 0x0001;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    ax = 0x0005;
    out(dx, ax);
    si = 0x9bd6;
loc_11391:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        goto loc_113b0;
    if (!ax)
        goto loc_113aa;
    if (memory16(ds, si + 10) == 0x00fe)
        goto loc_113aa;
    push(bx);
    push(ds);
    push(si);
    callIndirect(cs, memory16(ds, 0x0040));
    si = pop();
    ds = pop();
    bx = pop();
loc_113aa:
    si += 0x001a;
    goto loc_11391;
loc_113b0:
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dl = 0xce;
    ax = 0x0105;
    out(dx, ax);
    ax = 0x0001;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    es = pop();
    ds = pop();
}
void sub_15f40()
{
    if (memory16(ds, 0x762d) != 0x0001)
        goto loc_15f52;
    if (memory16(ds, 0x762f) == 0x0001)
        goto loc_15f51;
    sub_17a31();
loc_15f51:
    return;
loc_15f52:
    bx = memory16(ds, 0x5b3c);
    if (bx)
        goto loc_15f5b;
    return;
loc_15f5b:
    cx = memory16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx += 0x0025;
loc_15f68:
    al = memory(ds, bx);
    if (al)
        goto loc_15f6f;
    return;
loc_15f6f:
    ah = al;
    bx++;
    al = memory(ds, bx);
    if (al < cl)
        goto loc_15f79;
    return;
loc_15f79:
    if (!(ah & 0x80))
        goto loc_15f90;
    bx++;
loc_15f7f:
    bx++;
loc_15f80:
    al = memory(ds, bx);
    bx++;
    al &= 0x03;
    if (al == 0)
        goto loc_15f68;
loc_15f87:
    bx += 0x0004;
    al--;
    if (al != 0)
        goto loc_15f87;
    goto loc_15f68;
loc_15f90:
    bx++;
    if (!(memory(ds, bx) & 0x80))
        goto loc_15fd4;
    al = memory(ds, 0x5b3e);
    if (al)
        goto loc_15fb9;
    push(cx);
    cx = memory16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    ah = cl;
    bx--;
    al = memory(ds, bx);
    bx++;
    al -= ah;
    cx = pop();
    if (al < 0x05)
        goto loc_15fb9;
    if (al < 0x22)
        goto loc_15f7f;
loc_15fb9:
    bx--;
    bx--;
    push(bx);
loc_15fbc:
    si = bx;
    sub_16205();
    bx = pop();
loc_15fc2:
    bx++;
    bx++;
    bx++;
    cx = memory16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx += 0x0025;
    goto loc_15f80;
loc_15fd4:
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
void sub_15fe4()
{
    bx = memory16(ds, 0x8bfc);
    memory16(ds, 0x5b3c) = bx;
    if (bx)
        goto loc_15ff1;
    return;
loc_15ff1:
    al = memory(ds, bx);
    if (al)
        goto loc_15ff8;
    return;
loc_15ff8:
    bx++;
    cx = memory16(ds, 0x8bf0);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    if (cl == memory(ds, bx))
        goto loc_1601c;
    if (cl < memory(ds, bx))
        goto loc_1601c;
    bx += 0x0002;
    al = memory(ds, bx);
    bx++;
    al &= 0x03;
    if (al == 0)
        goto loc_15ff1;
loc_16013:
    bx += 0x0004;
    al--;
    if (al != 0)
        goto loc_16013;
    goto loc_15ff1;
loc_1601c:
    bx--;
    memory16(ds, 0x5b3c) = bx;
}
void sub_16022()
{
    sub_16126();
    if (!flags.carry)
        goto loc_16028;
    return;
loc_16028:
    ax = 0;
    memory16(ds, di + 50) = ax;
    memory16(ds, di + 24) = ax;
    memory16(ds, di + 34) = ax;
    memory16(ds, di + 28) = si;
    cx = 0;
    cl = memory(ds, si);
    cx += cx;
    bx = 0x117e;
    bx += cx;
    bx = memory16(ds, bx);
    al = memory(ds, bx);
    cbw();
    memory16(ds, di + 30) = ax;
    bx++;
    al = memory(ds, bx);
    cbw();
    memory16(ds, di + 32) = ax;
    bx++;
    al = memory(ds, bx);
    al &= 0xc0;
    dl = al;
    ax = 0;
    al = memory(ds, si + 3);
    al &= 0x3c;
    if (al != 0x10)
        goto loc_16072;
    memory16(ds, di + 50) = 0x0060;
    if (!(memory(ds, si + 3) & 0x40))
        goto loc_16072;
    memory16(ds, di + 28) = 0x0000;
loc_16072:
    al |= 0x01;
    al |= dl;
    memory(ds, di) = al;
    al &= 0x3f;
    dl = al;
    ax = 0;
    al = memory(ds, bx);
    al += al;
    al += al;
    al |= dl;
    memory(ds, di + 44) = al;
    bx++;
    ax = memory16(ds, bx);
    bx++;
    bx++;
    memory16(ds, di + 36) = ax;
    ax = memory16(ds, bx);
    bx++;
    bx++;
    memory16(ds, di + 22) = ax;
    ax = memory16(ds, bx);
    bx++;
    bx++;
    memory16(ds, di + 40) = ax;
    ax = memory16(ds, bx);
    memory16(ds, di + 42) = ax;
    al = memory(ds, si + 2);
    ax &= 0x001f;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memory(ds, si + 2) & 0x20))
        goto loc_160ba;
    ax++;
    ax++;
    ax++;
    ax++;
loc_160ba:
    memory16(ds, di + 2) = ax;
    ax = memory16(ds, 0x8bf0);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dl = al;
    al = memory(ds, si + 1);
    al -= dl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memory(ds, si + 2) & 0x40))
        goto loc_160dc;
    ax++;
    ax++;
    ax++;
loc_160dc:
    memory16(ds, di + 4) = ax;
    memory(ds, si) = memory(ds, si) | 0x80;
    al = memory(ds, di);
    al &= 0x3f;
    ah = 0x29;
    if (al != 0x21)
        goto loc_160f2;
    memory(ds, di + 10) = ah;
    return;
loc_160f2:
    ah = 0x27;
    if (al != 0x29)
        goto loc_160fe;
    memory(ds, di + 10) = ah;
    return;
loc_160fe:
    ah = 0x28;
    if (al != 0x2d)
        goto loc_1610a;
    memory(ds, di + 10) = ah;
    return;
loc_1610a:
    push(si);
    push(di);
    push(bx);
    si = di;
    ax = memory16(ds, si + 24);
    push(ax);
    ax = memory16(ds, si + 22);
    push(ax);
    sub_1718e();
    ax = pop();
    memory16(ds, si + 22) = ax;
    ax = pop();
    memory16(ds, si + 24) = ax;
    bx = pop();
    di = pop();
    si = pop();
}
void sub_16126()
{
    di = 0x0c28;
loc_16129:
    ax = memory16(ds, di);
    if (ah & 0x80)
        goto loc_16138;
    if (!(al & 0x01))
        goto loc_1613a;
    di += 0x0034;
    goto loc_16129;
loc_16138:
    flags.carry = true;
    return;
loc_1613a:
    flags.carry = false;
}
void sub_1613c()
{
    push(cx);
    cx = memory16(ds, si + 2);
    if ((short)cx < (short)0x0000)
        goto loc_1615c;
    if ((short)cx > (short)0x00e8)
        goto loc_1615c;
    cx = memory16(ds, si + 4);
    if ((short)cx < (short)0x0000)
        goto loc_1615c;
    if ((short)cx >= (short)0x0128)
        goto loc_1615c;
    cx = pop();
    flags.carry = false;
    return;
loc_1615c:
    cx = pop();
    flags.carry = true;
}
void sub_1615f()
{
    if (!(memory16(ds, si) & 0x0001))
        return;
    bx = memory16(ds, si + 28);
    if (!bx)
        goto loc_1616f;
    memory(ds, bx) = memory(ds, bx) & 0x7f;
loc_1616f:
    memory16(ds, si) = 0x0000;
}
void sub_16174()
{
    if (!(memory16(ds, si) & 0x0001))
        return;
    bx = memory16(ds, si + 28);
    if (!bx)
        goto loc_1618a;
    if (memory(ds, bx + 3) & 0x40)
        goto loc_1618a;
    memory(ds, bx) = memory(ds, bx) & 0x7f;
loc_1618a:
    memory16(ds, si) = 0x0000;
}
void sub_1618f()
{
    push(si);
    si = 0x0b56;
loc_16193:
    if (memory16(ds, si) == 0xffff)
        goto loc_161ad;
    if (!(memory16(ds, si) & 0x0001))
        goto loc_161a8;
    bx = memory16(ds, si + 28);
    memory(ds, bx) = memory(ds, bx) & 0x7f;
    memory16(ds, si) = 0x0000;
loc_161a8:
    si += 0x0034;
    goto loc_16193;
loc_161ad:
    si = 0x0c28;
loc_161b0:
    if (memory16(ds, si) == 0xffff)
        goto loc_161ca;
    if (!(memory16(ds, si) & 0x0001))
        goto loc_161c5;
    bx = memory16(ds, si + 28);
    memory(ds, bx) = memory(ds, bx) & 0x7f;
    memory16(ds, si) = 0x0000;
loc_161c5:
    si += 0x0034;
    goto loc_161b0;
loc_161ca:
    si = pop();
}
void sub_16205()
{
    goto loc_16205;
loc_161ce:
    memory(ds, si) = memory(ds, si) | 0x80;
    memory16(ds, 0x5dcc) = 0x0001;
    memory16(ds, 0x65e1) = 0x0018;
    si = 0x661d;
    di = 0x6624;
    cx = 0x0006;
    rep_movsb<MemData, MemData, DirForward>();
    ax = 0x0013;
    sub_1aecd();
    return;
loc_161ef:
    memory(ds, si) = memory(ds, si) | 0x80;
    memory16(ds, 0x5dcc) = 0x0000;
    si = 0x6624;
    sub_16bc7();
    ax = 0x0001;
    sub_1aecd();
    return;
loc_16205:
    ah = 0;
    al = memory(ds, si);
    if (ax == 0x0078)
        goto loc_161ce;
    if (ax == 0x007c)
        goto loc_161ef;
    if ((short)ax >= (short)0x0075)
        goto loc_1621c;
    sub_16022();
    return;
loc_1621c:
    sub_1691d();
}
void sub_16222()
{
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    al = memory(ds, si + 3);
    al &= 0x03;
    if (al != 0)
        goto loc_1623e;
    flags.carry = false;
    return;
loc_1623e:
    si += 0x0004;
    push(memory16(ds, 0x54f8));
    push(ax);
    memory16(ds, 0x54f8) = pop();
    ax = pop();
    al = memory(ds, si + 2);
    cl = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al &= 0x0f;
    al++;
    ah = al;
    dx = memory16(ds, 0x8bf0);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    al = memory(ds, si + 1);
    al -= dl;
    if ((char)al >= 0)
        goto loc_1627d;
    al += ah;
    if ((char)al >= 0)
        goto loc_16277;
loc_16273:
    flags.carry = false;
    goto loc_163f5;
loc_16277:
    if (al == 0)
        goto loc_16273;
    ah = al;
    al = 0;
loc_1627d:
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
    dh = memory(ds, si);
    push(si);
    al = memory(ds, si + 3);
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
loc_162b8:
    si = pop();
    al = memory(ds, si + 3);
    if (!(al & 0x80))
        goto loc_162c3;
    goto loc_163f5;
loc_162c3:
    al &= 0x40;
    if (al != 0)
        goto loc_162cb;
    memory(ds, si + 3) = memory(ds, si + 3) | 0x80;
loc_162cb:
    flags.carry = true;
    return;
loc_162cd:
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_162ec;
    cl = al;
    if (memory16(ds, 0x0b00) != 0x0001)
        goto loc_162ea;
    push(cx);
    push(bx);
    sub_164a0();
    bx = pop();
    cx = pop();
    if (!flags.carry)
        goto loc_162ea;
    memory(ds, 0x5e20) = 0xff;
    goto loc_162b8;
loc_162ea:
    al = cl;
loc_162ec:
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_1630f;
    cl = al;
    if (memory16(ds, 0x0b38) != 0x0002)
        goto loc_1630d;
    al = memory(ds, 0x0b4a);
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
loc_1630d:
    al = cl;
loc_1630f:
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_1632f;
    cl = al;
    if (memory16(ds, 0x7ecc) != 0x0001)
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
loc_1632d:
    al = cl;
loc_1632f:
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_16389;
    cl = al;
    push(si);
    si = 0x0b56;
loc_16339:
    bp = memory16(cs, si);
    if (bp == 0xffff)
        goto loc_1637d;
    if (!(bp & 0x0001))
        goto loc_16378;
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    push(cx);
    push(bx);
    sub_16519();
    bx = pop();
    cx = pop();
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    if (flags.carry)
        goto loc_16382;
loc_16378:
    si += 0x0034;
    goto loc_16339;
loc_1637d:
    si = pop();
    flags.carry = false;
    goto loc_16387;
loc_16382:
    si = pop();
    flags.carry = true;
    goto loc_162b8;
loc_16387:
    al = cl;
loc_16389:
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_163f0;
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    bx = 0x0c28;
loc_163a4:
    al = memory(ds, bx + 1);
    if (al & 0x80)
        goto loc_163f0;
    al = memory(ds, bx);
    if (!al)
        goto loc_163eb;
    if (bx == dx)
        goto loc_163eb;
    si = bx;
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    push(cx);
    push(bx);
    sub_16555();
    bx = pop();
    cx = pop();
    push(memory16(ds, 0x54f4));
    push(dx);
    memory16(ds, 0x54f4) = pop();
    dx = pop();
    push(memory16(ds, 0x54f6));
    push(bx);
    memory16(ds, 0x54f6) = pop();
    bx = pop();
    if (!flags.carry)
        goto loc_163eb;
    goto loc_162b8;
loc_163eb:
    bx += 0x0034;
    goto loc_163a4;
loc_163f0:
    si = pop();
    memory(ds, si + 3) = memory(ds, si + 3) & 0x7f;
loc_163f5:
    push(memory16(ds, 0x54f8));
    push(ax);
    memory16(ds, 0x54f8) = pop();
    ax = pop();
    flags.carry = al == 0;
    al--;
    if (al == 0)
        return;
    goto loc_1623e;
}
void sub_16407()
{
    if (memory16(ds, 0x7e16) != 0x0001)
        goto loc_16410;
    flags.carry = false;
    return;
loc_16410:
    bp = memory16(ds, 0x0b1e);
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
    bp = memory16(ds, 0x0b20);
    cx = bx;
    if (memory16(ds, 0x7e04) == 0x0001)
        goto loc_16454;
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_1646c;
    bp -= 0x0015;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1646c;
    goto loc_1646a;
loc_16454:
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_1646c;
    bp -= 0x0010;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1646c;
loc_1646a:
    flags.carry = true;
    return;
loc_1646c:
    flags.carry = false;
}
void sub_1646e()
{
    bp = memory16(ds, 0x7ece);
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
    bp = memory16(ds, 0x7ed0);
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_1649e;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx < (short)bp)
        goto loc_1649e;
    flags.carry = true;
    return;
loc_1649e:
    flags.carry = false;
}
void sub_164a0()
{
    if (memory16(ds, 0x0b00) != 0x0001)
        goto loc_164df;
    bp = memory16(cs, 0x0b02);
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
    bp = memory16(cs, 0x0b04);
    bp += 0x0004;
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_164df;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx < (short)bp)
        goto loc_164df;
    flags.carry = true;
    return;
loc_164df:
    flags.carry = false;
}
void sub_164e1()
{
    bp = memory16(ds, 0x0b3a);
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
    bp = memory16(ds, 0x0b3c);
    bp += 0x000a;
    cx = bx;
    if ((short)cx > (short)bp)
        goto loc_16517;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx < (short)bp)
        goto loc_16517;
    flags.carry = true;
    return;
loc_16517:
    flags.carry = false;
}
void sub_16519()
{
    bp = memory16(ds, si + 2);
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
    bp = memory16(ds, si + 4);
    cx = bx;
    bp += 0x0015;
    if ((short)cx >= (short)bp)
        goto loc_16553;
    bp -= 0x0015;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx <= (short)bp)
        goto loc_16553;
    flags.carry = true;
    return;
loc_16553:
    flags.carry = false;
}
void sub_16555()
{
    bp = memory16(ds, si + 2);
    bp += memory16(ds, si + 30);
    cx = 0;
    cl = dh;
    if ((short)cx >= (short)bp)
        goto loc_1658f;
    bp -= memory16(ds, si + 30);
    al = dh;
    dh = 0;
    cx += dx;
    dh = al;
    if ((short)cx <= (short)bp)
        goto loc_1658f;
    bp = memory16(ds, si + 4);
    cx = bx;
    bp += memory16(ds, si + 32);
    if ((short)cx >= (short)bp)
        goto loc_1658f;
    bp -= memory16(ds, si + 32);
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    cx += ax;
    tl = ah;
    ah = al;
    al = tl;
    if ((short)cx <= (short)bp)
        goto loc_1658f;
    flags.carry = true;
    return;
loc_1658f:
    flags.carry = false;
}
void sub_16591()
{
    goto loc_16591;
loc_1615f:
    if (!(memory16(ds, si) & 0x0001))
        goto loc_16173;
    bx = memory16(ds, si + 28);
    if (!bx)
        goto loc_1616f;
    memory(ds, bx) = memory(ds, bx) & 0x7f;
loc_1616f:
    memory16(ds, si) = 0x0000;
loc_16173:
    return;
loc_16174:
    if (!(memory16(ds, si) & 0x0001))
        goto loc_1618e;
    bx = memory16(ds, si + 28);
    if (!bx)
        goto loc_1618a;
    if (memory(ds, bx + 3) & 0x40)
        goto loc_1618a;
    memory(ds, bx) = memory(ds, bx) & 0x7f;
loc_1618a:
    memory16(ds, si) = 0x0000;
loc_1618e:
    return;
    //   gap of 1026 bytes
loc_16591:
    al = memory(ds, si);
    al &= 0x3f;
    ah = 0x29;
    if (al != 0x21)
        goto loc_1659e;
    goto loc_167d9;
loc_1659e:
    ah = 0x27;
    if (al != 0x29)
        goto loc_165a7;
    goto loc_167d9;
loc_165a7:
    ah = 0x28;
    if (al != 0x2d)
        goto loc_165b0;
    goto loc_167d9;
loc_165b0:
    if (!(al & 0x02))
        goto loc_165b7;
    goto loc_16748;
loc_165b7:
    bx = memory16(ds, si + 36);
loc_165ba:
    al = memory(ds, bx);
    if (al == 0x00)
        goto loc_165cf;
    if (al != 0xff)
        goto loc_16604;
    ax = memory16(ds, bx + 1);
    sub_1aecd();
    bx += 0x0003;
    goto loc_165ba;
loc_165cf:
    bx++;
    bx = memory16(ds, bx);
    memory16(ds, si + 36) = bx;
    al = memory(ds, si + 50);
    if (!(al & 0x20))
        goto loc_165df;
    goto loc_16174;
loc_165df:
    if (!(al & 0x10))
        goto loc_165ba;
    if (!(al & 0x08))
        goto loc_165ee;
    memory(ds, si + 50) = memory(ds, si + 50) & 0xf7;
    goto loc_165f2;
loc_165ee:
    memory(ds, si + 50) = memory(ds, si + 50) & 0xef;
loc_165f2:
    al = memory(ds, si);
    al &= 0x1c;
    if (al == 0x14)
        goto loc_165fd;
    goto loc_1679d;
loc_165fd:
    memory(ds, si + 50) = memory(ds, si + 50) | 0x20;
    goto loc_1679d;
loc_16604:
    bx++;
    al = memory(ds, bx);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    if (al != 0x07)
        goto loc_16615;
    al++;
loc_16615:
    cbw();
    memory16(ds, si + 46) = ax;
    if (!(ax & 0x8000))
        goto loc_16625;
    flags.carry = (ax + memory16(ds, si + 2)) >= 0x10000;
    ax += memory16(ds, si + 2);
    if (flags.carry)
        goto loc_1662a;
    goto loc_1662a;
loc_16625:
    flags.carry = (ax + memory16(ds, si + 2)) >= 0x10000;
    ax += memory16(ds, si + 2);
    if (!flags.carry)
        goto loc_1662a;
loc_1662a:
    memory16(ds, si + 2) = ax;
    dh = 0;
    al = memory(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_1663b;
    dh--;
    al |= 0xf0;
loc_1663b:
    if (al != 0x07)
        goto loc_16641;
    al++;
loc_16641:
    dl = al;
    cbw();
    memory16(ds, si + 48) = ax;
    cx = bx;
    bx = memory16(ds, si + 4);
    bx += dx;
    memory16(ds, si + 4) = bx;
    sub_1613c();
    if (!flags.carry)
        goto loc_16659;
    goto loc_1615f;
loc_16659:
    bx = cx;
    bx--;
    al = memory(ds, bx);
    cbw();
    memory16(ds, si + 34) = memory16(ds, si + 34) + 1;
    if (ax == memory16(ds, si + 34))
        goto loc_16669;
    if (ax >= memory16(ds, si + 34))
        goto loc_16673;
loc_16669:
    memory16(ds, si + 34) = 0x0000;
    bx++;
    bx++;
    memory16(ds, si + 36) = bx;
loc_16673:
    sub_1718e();
    if (!(memory16(ds, si) & 0x0080))
        goto loc_166bd;
    if (memory16(ds, si) & 0x0040)
        goto loc_16685;
    goto loc_16748;
loc_16685:
    if (memory16(ds, 0x0b38) != 0x0001)
        goto loc_166bd;
    bx = memory16(ds, 0x0b3c);
    dh = memory(ds, 0x0b3a);
    dh += 0x08;
    dl = 0x08;
    ah = 0x10;
    sub_16555();
    if (!flags.carry)
        goto loc_166bd;
    memory16(ds, 0x0b38) = 0x0002;
    memory16(ds, 0x0b50) = 0x0000;
    memory16(ds, 0x0b4e) = 0x7eb2;
    memory16(ds, 0x0b3c) = memory16(ds, 0x0b3c) - 0x0005;
    memory16(ds, 0x0b4a) = 0x0000;
loc_166bd:
    if (memory16(ds, si) & 0x0040)
        goto loc_166c6;
    goto loc_16748;
loc_166c6:
    if (memory16(ds, si + 10) == 0x00fe)
        goto loc_16748;
    di = 0x0b56;
loc_166d3:
    ax = memory16(ds, di);
    if (ax == 0xffff)
        goto loc_16717;
    if (!(al & 0x01))
        goto loc_16712;
    if (memory16(ds, di + 22) == 0x0001)
        goto loc_16712;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
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
loc_16710:
    di = pop();
    si = pop();
loc_16712:
    di += 0x0034;
    goto loc_166d3;
loc_16717:
    if (memory16(ds, 0x7e16) == 0x0001)
        goto loc_16748;
    if (!(memory(ds, si) & 0x40))
        goto loc_16748;
    ax = memory16(ds, si + 10);
    if (ax == 0x00fe)
        goto loc_16748;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    sub_16407();
    if (!flags.carry)
        goto loc_16748;
    goto loc_168a8;
loc_16748:
    al = memory(ds, si + 50);
    if (!(al & 0x40))
        goto loc_16750;
    return;
loc_16750:
    if (!(memory(ds, si + 50) & 0x10))
        goto loc_1675c;
    if (!(memory(ds, si) & 0x20))
        goto loc_1675c;
    return;
loc_1675c:
    push(si);
    dx = si;
    si = memory16(ds, si + 28);
    sub_16222();
    si = pop();
    if (flags.carry)
        goto loc_16774;
    al = memory(ds, si);
    al &= 0x1c;
    if (al == 0x1c)
        goto loc_16771;
    return;
loc_16771:
    goto loc_16174;
loc_16774:
    al = memory(ds, si);
    al &= 0x1c;
    if (al != 0)
        goto loc_16781;
    al = memory(ds, si);
    al ^= 0x02;
    memory(ds, si) = al;
    return;
loc_16781:
    if (al != 0x1c)
        goto loc_16786;
    return;
loc_16786:
    if (al != 0x0c)
        goto loc_1678d;
    goto loc_16174;
loc_1678d:
    if (!(al & 0x08))
        goto loc_167ca;
    memory(ds, si + 50) = memory(ds, si + 50) | 0x40;
    if (!(al & 0x10))
        goto loc_1679d;
    memory(ds, si + 50) = memory(ds, si + 50) | 0x20;
loc_1679d:
    bx = memory16(ds, si + 40);
    cx = memory16(ds, si + 36);
    memory16(ds, si + 40) = cx;
    memory16(ds, si + 36) = bx;
    bx = memory16(ds, si + 22);
    cx = memory16(ds, si + 42);
    memory16(ds, si + 22) = cx;
    memory16(ds, si + 42) = bx;
    memory16(ds, si + 24) = 0x0000;
    memory16(ds, si + 18) = 0x0000;
    al = memory(ds, si);
    ah = memory(ds, si + 44);
    memory(ds, si) = ah;
    memory(ds, si + 44) = al;
    return;
loc_167ca:
    memory(ds, si + 50) = memory(ds, si + 50) | 0x10;
    if (memory(ds, si) & 0x20)
        goto loc_167d4;
    return;
loc_167d4:
    memory(ds, si + 50) = memory(ds, si + 50) | 0x08;
    return;
loc_167d9:
    memory(ds, si) = al;
    memory(ds, si + 10) = ah;
    memory(ds, si + 11) = 0x00;
    memory16(ds, si + 30) = 0x0018;
    memory16(ds, si + 32) = 0x0015;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    sub_16407();
    if (!flags.carry)
        goto loc_16803;
    sub_1686f();
    sub_16174();
loc_16803:
    if (memory16(ds, 0x0b38) != 0x0002)
        goto loc_1683f;
    al = memory(ds, 0x0b4a);
    if ((char)al <= (char)0x01)
        goto loc_1683f;
    if ((char)al > (char)0x04)
        goto loc_1683f;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    if (dh >= 0x0f)
        goto loc_1682b;
    dh = 0;
    goto loc_1682e;
loc_1682b:
    dh -= 0x10;
loc_1682e:
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    sub_164e1();
    if (!flags.carry)
        goto loc_1683f;
    sub_16174();
loc_1683f:
    if (memory16(ds, 0x0b00) != 0x0001)
        goto loc_16866;
    al = memory(ds, si);
    if (al == 0x21)
        goto loc_16866;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    sub_164a0();
    if (!flags.carry)
        goto loc_16866;
    sub_16174();
    memory16(ds, 0x0b00) = 0x0000;
loc_16866:
    sub_1613c();
    if (!flags.carry)
        goto loc_1686e;
    sub_1615f();
loc_1686e:
    return;
    //   gap of 57 bytes
loc_168a8:
    ax = 0x000b;
    sub_1aecd();
    memory16(ds, 0x7e16) = 0x0001;
    memory16(ds, 0x0b24) = 0xfb00;
    ax = memory16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memory16(ds, 0x7e1c) = 0xfffe;
    goto loc_168d1;
loc_168cb:
    memory16(ds, 0x7e1c) = 0x0002;
loc_168d1:
    ax = memory16(ds, 0x6614);
    if (!ax)
        return;
    if (memory(ds, 0x9804) == 0x01)
        return;
    memory16(ds, 0x6614) = memory16(ds, 0x6614) - 1;
}
void sub_1686f()
{
    al = memory(ds, si);
    if (al != 0x21)
        goto loc_16884;
    push(si);
    si = 0x6717;
    sub_16bc7();
    si = pop();
    ax = 0x0012;
    sub_1aecd();
    return;
loc_16884:
    if (al == 0x29)
        goto loc_16898;
    memory16(ds, 0x6612) = 0x0006;
    sub_16c3d();
    ax = 0x0011;
    sub_1aecd();
    return;
loc_16898:
    memory16(ds, 0x6610) = 0x0006;
    sub_16c27();
    ax = 0x0011;
    sub_1aecd();
}
void sub_168a8()
{
    ax = 0x000b;
    sub_1aecd();
    memory16(ds, 0x7e16) = 0x0001;
    memory16(ds, 0x0b24) = 0xfb00;
    ax = memory16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memory16(ds, 0x7e1c) = 0xfffe;
    goto loc_168d1;
loc_168cb:
    memory16(ds, 0x7e1c) = 0x0002;
loc_168d1:
    ax = memory16(ds, 0x6614);
    if (!ax)
        return;
    if (memory(ds, 0x9804) == 0x01)
        return;
    memory16(ds, 0x6614) = memory16(ds, 0x6614) - 1;
}
void sub_168e4()
{
    if (memory16(ds, 0x762d) != 0x0001)
        goto loc_168ef;
    sub_17a8b();
    return;
loc_168ef:
    si = 0x0c28;
loc_168f2:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        return;
    if (!(al & 0x01))
        goto loc_16901;
    push(si);
    sub_16591();
    si = pop();
loc_16901:
    si += 0x0034;
    goto loc_168f2;
}
void sub_16907()
{
    di = 0x0b56;
loc_1690a:
    ax = memory16(ds, di);
    if (ah & 0x80)
        goto loc_16919;
    if (!(al & 0x01))
        goto loc_1691b;
    di += 0x0034;
    goto loc_1690a;
loc_16919:
    flags.carry = true;
    return;
loc_1691b:
    flags.carry = false;
}
void sub_1691d()
{
    sub_16907();
    if (!flags.carry)
        goto loc_16923;
    return;
loc_16923:
    memory16(ds, di + 22) = 0x0000;
    memory16(ds, di + 24) = 0x0000;
    memory(ds, si) = memory(ds, si) | 0x80;
    al = memory(ds, si);
    al &= 0x03;
    memory(ds, di + 49) = 0x00;
    memory(ds, di + 48) = al;
    memory16(ds, di + 28) = si;
    memory16(ds, di) = memory16(ds, di) | 0x0001;
    al = memory(ds, si);
    if (!(al & 0x04))
        goto loc_16954;
    memory16(ds, di + 10) = 0x002a;
    memory16(ds, di + 50) = 0x002a;
    goto loc_1695e;
loc_16954:
    memory16(ds, di + 10) = 0x0034;
    memory16(ds, di + 50) = 0x0034;
loc_1695e:
    al = memory(ds, si + 2);
    ax &= 0x001f;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memory16(ds, di + 2) = ax;
    ax = memory16(ds, 0x8bf0);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dl = al;
    al = memory(ds, si + 1);
    al -= dl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    if (!(memory(ds, si + 2) & 0x40))
        goto loc_1698c;
    ax++;
    ax++;
    ax++;
loc_1698c:
    memory16(ds, di + 4) = ax;
    memory16(ds, di + 30) = 0x0010;
    memory16(ds, di + 32) = 0x0015;
    ax = memory16(ds, di + 48);
    if (ax != 0x0001)
        goto loc_169b3;
    al = memory(ds, si + 3);
    al &= 0x3c;
    ax <<= 1;
    ax += 0x0008;
    memory16(ds, di + 18) = ax;
    ax = 0;
    memory16(ds, di + 20) = ax;
loc_169b3:
    memory16(ds, di + 8) = 0x0100;
    memory(ds, di + 6) = 0x00;
    memory16(ds, di + 16) = 0x0000;
    ax = 0x0000;
    memory16(ds, di + 34) = ax;
    memory16(ds, di + 36) = ax;
    memory16(ds, di + 38) = ax;
    memory16(ds, di + 40) = ax;
    memory16(ds, di + 42) = ax;
    memory16(ds, di + 44) = ax;
    memory16(ds, di + 26) = 0x0000;
    memory16(ds, di + 16) = 0x0002;
}
void sub_169e3()
{
    if (memory16(ds, 0x5dcc) == 0x0000)
        return;
    ax = memory16(ds, 0x65e1);
    ax++;
    if (ax != 0x0019)
        goto loc_16a0b;
    si = 0x6624;
    cx = 0x0006;
    al = 0x00;
loc_169fb:
    if (al != memory(ds, si))
        goto loc_16a03;
    si++;
    if (--cx)
        goto loc_169fb;
    return;
loc_16a03:
    si = 0x662b;
    sub_16bf7();
    ax = 0;
loc_16a0b:
    memory16(ds, 0x65e1) = ax;
}
void sub_16b3b()
{
    push(ds);
    push(es);
    push(bx);
    sub_16c53();
    sub_16c27();
    sub_16c3d();
    ax = 0x0004;
    si = 0x6616;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = 0x000d;
    si = 0x66f6;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = 0x0015;
    si = 0x66fd;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = 0x001e;
    si = 0x6704;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = 0x0004;
    si = 0x6616;
    callIndirect(cs, memory16(ds, 0x000e));
    ax = 0x000d;
    si = 0x66f6;
    callIndirect(cs, memory16(ds, 0x000e));
    ax = 0x0015;
    si = 0x66fd;
    callIndirect(cs, memory16(ds, 0x000e));
    ax = 0x001e;
    si = 0x6704;
    callIndirect(cs, memory16(ds, 0x000e));
    bx = pop();
    es = pop();
    ds = pop();
}
void sub_16b9b()
{
    push(0x7777);
    callIndirect(cs, memory16(ds, 0x0026));
    callIndirect(cs, memory16(ds, 0x0028));
    memory(ds, 0x97da) = 0x01;
    cx = 0x01e0;
loc_16bac:
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_16bc4;
    al = memory(ds, 0xb888);
    al &= 0x30;
    if (al == 0x30)
        goto loc_16bc4;
    cx = pop();
    if (--cx)
        goto loc_16bac;
    assert(pop() == 0x7777);
    return;
loc_16bc4:
    goto loc_1c3b0;
    //   gap of 11052 bytes
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2017 bytes
loc_19f12:
    callIndirect(cs, memory16(ds, 0x003a));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0002;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    sub_19ee5();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    goto loc_1c359;
    //   gap of 9250 bytes
loc_1c359:
    sp = memory16(ds, 0xc0df);
    callIndirect(cs, memory16(ds, 0x000a));
    sub_1a592();
    callIndirect(cs, memory16(ds, 0x003a));
    memory16(ds, 0xbdf2) = 0x0003;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
    callIndirect(cs, memory16(ds, 0x0028));
loc_1c378:
    sync();
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
loc_1c382:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395:
    sub_16b9b();
loc_1c398:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab:
    sub_16cd7();
    goto loc_1c382;
loc_1c3b0:
    memory16(ds, 0x6614) = 0x0006;
    sub_199c8();
    sp = memory16(ds, 0xc0df);
    memory16(ds, 0x6610) = 0x0006;
    memory16(ds, 0x6612) = 0x0006;
    memory16(ds, 0x7e00) = 0x0000;
    memory16(ds, 0x762d) = 0x0000;
    memory16(ds, 0x762f) = 0x0000;
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    callIndirect(cs, memory16(ds, 0x0004));
    callIndirect(cs, memory16(ds, 0x0006));
    sub_1a45c();
    sub_1c4e2();
    callIndirect(cs, memory16(ds, 0x0042));
    callIndirect(cs, memory16(ds, 0x0026));
    callIndirect(cs, memory16(ds, 0x003c));
    callIndirect(cs, memory16(ds, 0x0048));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = memory16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memory16(ds, si);
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    callIndirect(cs, memory16(ds, 0x0026));
    sub_19420();
    memory16(ds, 0x973c) = 0x3245;
    memory16(ds, 0x973e) = 0x5432;
loc_1c439:
    memory16(ds, 0x7e16) = 0x0000;
    memory16(ds, 0x7e18) = 0x0000;
loc_1c445:
    sub_16b3b();
    if (memory16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memory16(ds, 0x762f) = 0x0000;
    sub_1618f();
    sub_19462();
    if (memory16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    goto loc_19f12;
loc_1c465:
    goto loc_1c439;
loc_1c467:
    sub_19bac();
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    callIndirect(cs, memory16(ds, 0x001e));
    callIndirect(cs, memory16(ds, 0x0024));
    callIndirect(cs, memory16(ds, 0x003e));
    callIndirect(cs, memory16(ds, 0x001c));
    sub_19af6();
    callIndirect(cs, memory16(ds, 0x0038));
    sub_194c4();
    if (memory(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    goto loc_1c359;
loc_1c4b3:
    if (memory(ds, 0xb888) != 0x01)
        goto loc_1c445;
    goto loc_196f3;
}
void sub_16bc7()
{
    si += 0x0005;
    di = 0x661b;
    bl = 0x00;
    cx = 0x0006;
loc_16bd2:
    al = memory(ds, si);
    ah = memory(ds, di);
    ah += al;
    ah += bl;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    if ((short)ax < (short)0x000a)
        goto loc_16bee;
    bl = 0x01;
    al -= 0x0a;
    memory(ds, di) = al;
    di--;
    si--;
    if (--cx)
        goto loc_16bd2;
    return;
loc_16bee:
    bl = 0x00;
    memory(ds, di) = al;
    di--;
    si--;
    if (--cx)
        goto loc_16bd2;
}
void sub_16bf7()
{
    si += 0x0005;
    di = 0x6629;
    bl = 0x00;
    cx = 0x0006;
loc_16c02:
    al = memory(ds, si);
    ah = memory(ds, di);
    ah += al;
    ah += bl;
    tl = ah;
    ah = al;
    al = tl;
    ah = 0;
    if ((short)ax < (short)0x000a)
        goto loc_16c1e;
    bl = 0x01;
    al -= 0x0a;
    memory(ds, di) = al;
    di--;
    si--;
    if (--cx)
        goto loc_16c02;
    return;
loc_16c1e:
    bl = 0x00;
    memory(ds, di) = al;
    di--;
    si--;
    if (--cx)
        goto loc_16c02;
}
void sub_16c27()
{
    di = 0x66f6;
    cx = 0x0006;
    al = 0x20;
    rep_stosb<MemData, DirForward>();
    cx = memory16(ds, 0x6610);
    di = 0x66f6;
    al = 0x0a;
    rep_stosb<MemData, DirForward>();
}
void sub_16c3d()
{
    di = 0x66fd;
    cx = 0x0006;
    al = 0x20;
    rep_stosb<MemData, DirForward>();
    cx = memory16(ds, 0x6612);
    di = 0x66fd;
    al = 0x0b;
    rep_stosb<MemData, DirForward>();
}
void sub_16c53()
{
    di = 0x6704;
    cx = 0x0006;
    al = 0x20;
    rep_stosb<MemData, DirForward>();
    cx = memory16(ds, 0x6614);
    di = 0x6704;
    al = 0x0c;
    rep_stosb<MemData, DirForward>();
}
void sub_16c69()
{
    cx = 0x0008;
    di = 0x6632;
    bx = 0x668d;
loc_16c72:
    si = 0x6616;
    sub_16cb8();
    if (flags.carry)
        goto loc_16c84;
    bx += 0x000b;
    di += 0x0007;
    if (--cx)
        goto loc_16c72;
    flags.carry = false;
    return;
loc_16c84:
    si = 0x6663;
loc_16c87:
    if (si == di)
        goto loc_16c94;
    al = memory(ds, si + 65535);
    memory(ds, si + 6) = al;
    si--;
    goto loc_16c87;
loc_16c94:
    cx = 0x0007;
    si = 0x6616;
    rep_movsb<MemData, MemData, DirForward>();
    flags.carry = true;
}
void sub_16cb8()
{
    push(cx);
    push(di);
    cx = 0x0006;
loc_16cbd:
    al = memory(ds, si);
    si++;
    ah = memory(ds, di);
    di++;
    if ((char)al < (char)ah)
        goto loc_16ccf;
    if ((char)al > (char)ah)
        goto loc_16cd3;
    if (--cx)
        goto loc_16cbd;
    di = pop();
    cx = pop();
    flags.carry = true;
    return;
loc_16ccf:
    di = pop();
    cx = pop();
    flags.carry = false;
    return;
loc_16cd3:
    di = pop();
    cx = pop();
    flags.carry = true;
}
void sub_16cd7()
{
    push(0x7777);
    callIndirect(cs, memory16(ds, 0x0026));
    ax = 0x0008;
    si = 0x9401;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0108;
    si = 0x9421;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0208;
    si = 0x9441;
    callIndirect(cs, memory16(ds, 0x0046));
    si = 0x668d;
    ax = 0x0617;
    cx = 0x0008;
loc_16d02:
    push(si);
    push(ax);
    push(cx);
    callIndirect(cs, memory16(ds, 0x000c));
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
loc_16d1e:
    push(si);
    push(ax);
    push(cx);
    callIndirect(cs, memory16(ds, 0x000c));
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
loc_16d3a:
    push(si);
    push(ax);
    push(cx);
    callIndirect(cs, memory16(ds, 0x000c));
    cx = pop();
    ax = pop();
    si = pop();
    ah++;
    ah++;
    if (--cx)
        goto loc_16d3a;
    callIndirect(cs, memory16(ds, 0x001c));
    memory(ds, 0x97da) = 0x01;
    cx = 0x01e0;
loc_16d57:
    sync();
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_16d66;
    cx = pop();
    if (--cx)
        goto loc_16d57;
    assert(pop() == 0x7777);
    return;
loc_16d66:
    goto loc_1c3b0;
    //   gap of 10634 bytes
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2017 bytes
loc_19f12:
    callIndirect(cs, memory16(ds, 0x003a));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0002;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    sub_19ee5();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    goto loc_1c359;
    //   gap of 9250 bytes
loc_1c359:
    sp = memory16(ds, 0xc0df);
    callIndirect(cs, memory16(ds, 0x000a));
    sub_1a592();
    callIndirect(cs, memory16(ds, 0x003a));
    memory16(ds, 0xbdf2) = 0x0003;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
    callIndirect(cs, memory16(ds, 0x0028));
loc_1c378:
    sync();
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
loc_1c382:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395:
    sub_16b9b();
loc_1c398:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab:
    sub_16cd7();
    goto loc_1c382;
loc_1c3b0:
    memory16(ds, 0x6614) = 0x0006;
    sub_199c8();
    sp = memory16(ds, 0xc0df);
    memory16(ds, 0x6610) = 0x0006;
    memory16(ds, 0x6612) = 0x0006;
    memory16(ds, 0x7e00) = 0x0000;
    memory16(ds, 0x762d) = 0x0000;
    memory16(ds, 0x762f) = 0x0000;
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    callIndirect(cs, memory16(ds, 0x0004));
    callIndirect(cs, memory16(ds, 0x0006));
    sub_1a45c();
    sub_1c4e2();
    callIndirect(cs, memory16(ds, 0x0042));
    callIndirect(cs, memory16(ds, 0x0026));
    callIndirect(cs, memory16(ds, 0x003c));
    callIndirect(cs, memory16(ds, 0x0048));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = memory16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memory16(ds, si);
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    callIndirect(cs, memory16(ds, 0x0026));
    sub_19420();
    memory16(ds, 0x973c) = 0x3245;
    memory16(ds, 0x973e) = 0x5432;
loc_1c439:
    memory16(ds, 0x7e16) = 0x0000;
    memory16(ds, 0x7e18) = 0x0000;
loc_1c445:
    sub_16b3b();
    if (memory16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memory16(ds, 0x762f) = 0x0000;
    sub_1618f();
    sub_19462();
    if (memory16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    goto loc_19f12;
loc_1c465:
    goto loc_1c439;
loc_1c467:
    sub_19bac();
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    callIndirect(cs, memory16(ds, 0x001e));
    callIndirect(cs, memory16(ds, 0x0024));
    callIndirect(cs, memory16(ds, 0x003e));
    callIndirect(cs, memory16(ds, 0x001c));
    sub_19af6();
    callIndirect(cs, memory16(ds, 0x0038));
    sub_194c4();
    if (memory(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    goto loc_1c359;
loc_1c4b3:
    if (memory(ds, 0xb888) != 0x01)
        goto loc_1c445;
    goto loc_196f3;
}
void sub_16d69()
{
    sub_16c69();
    if (!flags.carry)
        return;
    push(bx);
    sub_16eb2();
    bx = pop();
    cx = 0x000a;
    si = 0x6671;
    di = bx;
    rep_movsb<MemData, MemData, DirForward>();
}
void sub_16e16()
{
    ax = 0;
    dx = memory16(ds, 0x69f0);
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
    al = memory(ds, bx);
}
void sub_16e39()
{
    ax = memory16(ds, 0x69f2);
    si = 0x69ee;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = memory16(ds, 0x69f0);
    si = 0x69ec;
    callIndirect(cs, memory16(ds, 0x000c));
    callIndirect(cs, memory16(ds, 0x001c));
    ax = memory16(ds, 0x69f2);
    si = 0x69ee;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = memory16(ds, 0x69f0);
    si = 0x69ec;
    callIndirect(cs, memory16(ds, 0x000c));
}
void sub_16e66()
{
    ax = memory16(ds, 0x69f0);
    memory16(ds, 0x69f2) = ax;
    memory16(ds, 0x69f0) = dx;
    sub_16e39();
}
void sub_16e74()
{
    ax = memory16(ds, 0x69f6);
    si = 0x69ee;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = memory16(ds, 0x69f4);
    si = 0x69ec;
    callIndirect(cs, memory16(ds, 0x000c));
    callIndirect(cs, memory16(ds, 0x001c));
    ax = memory16(ds, 0x69f6);
    si = 0x69ee;
    callIndirect(cs, memory16(ds, 0x000c));
    ax = memory16(ds, 0x69f4);
    si = 0x69ec;
    callIndirect(cs, memory16(ds, 0x000c));
}
void sub_16ea1()
{
    ax = memory16(ds, 0x69f4);
    memory16(ds, 0x69f6) = ax;
    memory16(ds, 0x69f4) = dx;
    sub_16e74();
}
void sub_16eb2()
{
    ax = 0x090e;
    memory16(ds, 0x69f0) = ax;
    memory16(ds, 0x69f2) = ax;
    ax = 0x150e;
    memory16(ds, 0x69f4) = ax;
    memory16(ds, 0x69f6) = ax;
    di = 0x6671;
    cx = 0x000a;
    al = 0x0e;
    rep_stosb<MemData, DirForward>();
    memory16(ds, 0x6ab0) = 0x6671;
    callIndirect(cs, memory16(ds, 0x0026));
    ax = 0x0005;
    si = 0x93a1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0105;
    si = 0x93c1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0205;
    si = 0x93e1;
    callIndirect(cs, memory16(ds, 0x0046));
    bx = 0x69de;
    sub_19c43();
    ax = 0x140e;
    si = 0x6671;
    callIndirect(cs, memory16(ds, 0x000c));
    callIndirect(cs, memory16(ds, 0x001c));
    ax = 0x0005;
    si = 0x93a1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0105;
    si = 0x93c1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0205;
    si = 0x93e1;
    callIndirect(cs, memory16(ds, 0x0046));
    bx = 0x69de;
    sub_19c43();
    ax = 0x140e;
    si = 0x6671;
    callIndirect(cs, memory16(ds, 0x000c));
    sub_16e39();
    sub_16e74();
loc_16f3e:
    ax = 0x140e;
    si = 0x6671;
    callIndirect(cs, memory16(ds, 0x000c));
    callIndirect(cs, memory16(ds, 0x001c));
    ax = 0x140e;
    si = 0x6671;
    callIndirect(cs, memory16(ds, 0x000c));
    cx = 0x0006;
loc_16f59:
    sub_19b1c();
    if (--cx)
        goto loc_16f59;
    sub_1c4ca();
    if (memory(ds, 0x6aaf) != 0x01)
        goto loc_16f71;
    if (al & 0x10)
        goto loc_16f71;
    memory(ds, 0x6aaf) = 0x00;
loc_16f71:
    dx = memory16(ds, 0x69f0);
    if (!(al & 0x08))
        goto loc_16f7c;
    dh -= 0x02;
loc_16f7c:
    if (!(al & 0x04))
        goto loc_16f83;
    dh += 0x02;
loc_16f83:
    if (!(al & 0x01))
        goto loc_16f8a;
    dl += 0x02;
loc_16f8a:
    if (!(al & 0x02))
        goto loc_16f91;
    dl -= 0x02;
loc_16f91:
    if (al & 0x10)
        goto loc_16fbc;
    if (dl != 0x0c)
        goto loc_16f9f;
    dl = 0x0e;
    goto loc_16fa6;
loc_16f9f:
    if (dl != 0x1a)
        goto loc_16fa6;
    dl = 0x18;
loc_16fa6:
    if (dh != 0x07)
        goto loc_16fb0;
    dh = 0x09;
    goto loc_16fb7;
loc_16fb0:
    if (dh != 0x13)
        goto loc_16fb7;
    dh = 0x11;
loc_16fb7:
    sub_16e66();
    goto loc_16f3e;
loc_16fbc:
    if (memory(ds, 0x6aaf) != 0x01)
        goto loc_16fc6;
    goto loc_16f3e;
loc_16fc6:
    sub_16e16();
    memory(ds, 0x6aaf) = 0x01;
    if (al == 0x11)
        goto loc_16fe2;
    if (al != 0x10)
        goto loc_16fdc;
    sub_16ff5();
    goto loc_16f3e;
loc_16fdc:
    sub_17018();
    goto loc_16f3e;
loc_16fe2:
    si = 0x6671;
    cx = 0x000a;
loc_16fe8:
    al = memory(ds, si);
    if (al != 0x0e)
        goto loc_16ff1;
    memory(ds, si) = 0x20;
loc_16ff1:
    si++;
    if (--cx)
        goto loc_16fe8;
}
void sub_16ff5()
{
    di = memory16(ds, 0x6ab0);
    di--;
    if (di == 0x6670)
        return;
    memory(ds, di) = 0x0e;
    memory16(ds, 0x6ab0) = di;
    dx = memory16(ds, 0x6ab0);
    dx -= 0x6671;
    dh = 0x15;
    dl += 0x0e;
    sub_16ea1();
}
void sub_17018()
{
    di = memory16(ds, 0x6ab0);
    if (di == 0x667b)
        goto loc_17029;
    memory(ds, di) = al;
    di++;
    memory16(ds, 0x6ab0) = di;
loc_17029:
    dx = memory16(ds, 0x6ab0);
    dx -= 0x6671;
    dh = 0x15;
    if (dl != 0x0a)
        goto loc_1703a;
    dl = 0x09;
loc_1703a:
    dl += 0x0e;
    push(ax);
    sub_16ea1();
    ax = pop();
}
void sub_17047()
{
    memory16(ds, 0x6c43) = 0x0000;
    ax = memory16(ds, 0x8bf0);
    memory16(ds, 0x6c45) = ax;
    memory16(ds, 0x6c45) = memory16(ds, 0x6c45) & 0x0007;
    callIndirect(cs, memory16(ds, 0x0012));
}
void sub_1705d()
{
    if (memory16(ds, 0x7e16) != 0x0001)
        goto loc_17065;
    return;
loc_17065:
    ax = memory16(ds, 0x8bf0);
    ax &= 0x0007;
    dx = memory16(ds, 0x0b20);
    dx -= ax;
    if ((short)dx >= (short)0x009b)
        goto loc_17082;
    bx = memory16(ds, 0x6c43);
    if (bx & 0x8000)
        goto loc_17099;
    return;
loc_17082:
    if ((short)dx < (short)0x0086)
        return;
    bx = memory16(ds, 0x6c43);
    if (!bx)
        return;
    if (!(bx & 0x8000))
        goto loc_17095;
    return;
loc_17095:
    sub_170e6();
    return;
loc_17099:
    sub_1709d();
}
void sub_1709d()
{
    ax = memory16(ds, 0x8bf0);
    dx = ax;
    ax += memory16(ds, 0x6c43);
    if ((short)ax >= (short)memory16(ds, 0x8bf2))
        goto loc_170bb;
    cx = memory16(ds, 0x8bf2);
    cx -= memory16(ds, 0x8bf0);
    memory16(ds, 0x6c43) = cx;
    ax = memory16(ds, 0x8bf2);
loc_170bb:
    memory16(ds, 0x8bf0) = ax;
    if (dx == ax)
        goto loc_170e1;
    dx &= 0x0007;
    dx += memory16(ds, 0x6c43);
    if ((short)dx >= 0)
        goto loc_170e2;
    sub_195ea();
    sub_1930a();
    callIndirect(cs, memory16(ds, 0x0014));
    sub_17180();
    dx = 0x0008;
    sub_17132();
    sub_15fe4();
loc_170e1:
    return;
loc_170e2:
    sub_17180();
}
void sub_170e6()
{
    ax = memory16(ds, 0x8bf0);
    dx = ax;
    ax += memory16(ds, 0x6c43);
    if ((short)ax <= (short)memory16(ds, 0x8bf4))
        goto loc_17104;
    cx = memory16(ds, 0x8bf4);
    cx -= memory16(ds, 0x8bf0);
    memory16(ds, 0x6c43) = cx;
    ax = memory16(ds, 0x8bf4);
loc_17104:
    memory16(ds, 0x8bf0) = ax;
    if (dx == ax)
        goto loc_1712d;
    dx &= 0x0007;
    dx += memory16(ds, 0x6c43);
    if ((short)dx <= (short)0x0007)
        goto loc_1712e;
    sub_1961d();
    sub_192da();
    callIndirect(cs, memory16(ds, 0x0016));
    sub_17180();
    dx = 0xfff8;
    sub_17132();
    sub_15fe4();
loc_1712d:
    return;
loc_1712e:
    sub_17180();
}
void sub_17132()
{
    si = 0x0b00;
loc_17135:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        goto loc_17145;
    if (!ax)
        goto loc_17140;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
loc_17140:
    si += 0x001c;
    goto loc_17135;
loc_17145:
    si = 0x0c28;
loc_17148:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        goto loc_17162;
    if (!(al & 0x01))
        goto loc_1715d;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
    sub_1613c();
    if (!flags.carry)
        goto loc_1715d;
    sub_1615f();
loc_1715d:
    si += 0x0034;
    goto loc_17148;
loc_17162:
    si = 0x0b56;
loc_17165:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        return;
    if (!(al & 0x01))
        goto loc_1717a;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
    sub_1613c();
    if (!flags.carry)
        goto loc_1717a;
    sub_1615f();
loc_1717a:
    si += 0x0034;
    goto loc_17165;
}
void sub_17180()
{
    ax = memory16(ds, 0x6c45);
    ax += memory16(ds, 0x6c43);
    ax &= 0x00ff;
    memory16(ds, 0x6c45) = ax;
}
void sub_1718e()
{
    if (memory16(ds, si) & 0xffff)
        goto loc_17196;
    flags.carry = false;
    return;
loc_17196:
    if (!(memory16(ds, si + 24) & 0xffff))
        goto loc_171a2;
    memory16(ds, si + 24) = memory16(ds, si + 24) - 1;
    flags.carry = false;
    return;
loc_171a2:
    push(ax);
    push(bx);
    push(dx);
    dx = 0;
    bx = memory16(ds, si + 22);
loc_171aa:
    ax = memory16(ds, bx);
    if (ax & 0x8000)
        goto loc_171bb;
    memory16(ds, si + 10) = ax;
    bx++;
    bx++;
    memory16(ds, si + 22) = bx;
    goto loc_171f5;
loc_171bb:
    if (ax != 0xffff)
        goto loc_171cd;
    ax = memory16(ds, bx + 2);
    bx += ax;
    memory16(ds, si + 22) = si;
    dx = 0xffff;
    goto loc_171aa;
loc_171cd:
    if (ax != 0xfffd)
        goto loc_171e0;
    ax = memory16(ds, bx + 2);
    sub_1aecd();
    bx += 0x0004;
    memory16(ds, si + 22) = bx;
    goto loc_171aa;
loc_171e0:
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    memory16(ds, si + 24) = memory16(ds, si + 24) - 1;
    ax = memory16(ds, bx + 4);
    memory16(ds, si + 10) = ax;
    bx += 0x0006;
    memory16(ds, si + 22) = bx;
loc_171f5:
    if (dx)
        goto loc_171fe;
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = false;
    return;
loc_171fe:
    dx = pop();
    bx = pop();
    ax = pop();
    flags.carry = true;
}
void sub_17205()
{
    sub_177fb();
    si = 0x0b56;
loc_1720b:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        return;
    if (!(al & 0x01))
        goto loc_1721a;
    push(si);
    sub_17222();
    si = pop();
loc_1721a:
    si += 0x0034;
    goto loc_1720b;
}
void sub_17222()
{
    goto loc_17222;
loc_168a8:
    ax = 0x000b;
    sub_1aecd();
    memory16(ds, 0x7e16) = 0x0001;
    memory16(ds, 0x0b24) = 0xfb00;
    ax = memory16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memory16(ds, 0x7e1c) = 0xfffe;
    goto loc_168d1;
loc_168cb:
    memory16(ds, 0x7e1c) = 0x0002;
loc_168d1:
    ax = memory16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memory(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memory16(ds, 0x6614) = memory16(ds, 0x6614) - 1;
loc_168e3:
    return;
    //   gap of 2366 bytes
loc_17222:
    memory16(ds, 0x6e20) = 0x0000;
    memory16(ds, 0x6e03) = 0x0000;
    if (memory16(ds, si + 24) == 0x0000)
        goto loc_17246;
    memory16(ds, si + 24) = memory16(ds, si + 24) - 1;
    if (memory16(ds, si + 22) != 0x0001)
        goto loc_17240;
    goto loc_176a0;
loc_17240:
    memory16(ds, 0x6e20) = 0x0001;
loc_17246:
    memory16(ds, si + 44) = 0x0000;
    memory16(ds, si + 46) = 0x0000;
    if (memory16(ds, si + 22) != 0x0001)
        goto loc_17259;
    goto loc_176a0;
loc_17259:
    if (memory16(ds, si + 42) != 0x0001)
        goto loc_17262;
    goto loc_17644;
loc_17262:
    memory16(ds, si + 44) = 0x0000;
    memory16(ds, si + 46) = 0x0000;
    memory16(ds, si + 34) = 0x0000;
    memory16(ds, si + 36) = 0x0000;
    memory16(ds, si + 38) = 0x0000;
    memory16(ds, si + 40) = 0x0000;
    memory(ds, 0x796b) = 0x01;
    memory16(ds, 0x6e03) = 0x0000;
    dx = memory16(ds, si + 8);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_1729c;
    dx = 0x0800;
loc_1729c:
    memory16(ds, si + 8) = dx;
    memory16(ds, 0x7961) = dx;
    if (dx & 0x8000)
        goto loc_172ac;
    ch = 0;
    goto loc_172ae;
loc_172ac:
    ch = 0xff;
loc_172ae:
    ax = memory16(ds, si + 4);
    cl = memory(ds, si + 6);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    memory16(ds, 0x795f) = ax;
    dx = memory16(ds, si + 2);
    memory16(ds, 0x795d) = dx;
    memory(ds, 0x796b) = 0x01;
    sub_17dfb();
loc_172cd:
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_172da;
    goto loc_17674;
loc_172da:
    if (!(ch & 0x40))
        goto loc_1733d;
    ax = memory16(ds, 0x7964);
    cl = 0;
    ax -= 0x0015;
    memory16(ds, 0x795f) = ax;
    memory16(ds, si + 4) = ax;
    memory(ds, si + 6) = 0x00;
    memory16(ds, si + 34) = 0x0001;
    push(ax);
    ax = memory16(ds, 0x7966);
    memory16(ds, si + 44) = ax;
    ax = pop();
    memory(ds, 0x796b) = 0x00;
    sub_17dfb();
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_17315;
    goto loc_17674;
loc_17315:
    ch &= 0x06;
    if (ch == 0)
        goto loc_17321;
    ch = memory(ds, 0x7963);
    goto loc_1735c;
loc_17321:
    bp = memory16(cs, si + 44);
    bp |= memory16(cs, si + 46);
    if (!bp)
        goto loc_17333;
    memory16(ds, 0x6e03) = 0x0001;
loc_17333:
    ch = memory(ds, 0x7963);
    dx = 0x0100;
    goto loc_173e4;
loc_1733d:
    if (!(ch & 0x20))
        goto loc_17346;
    goto loc_17674;
loc_17346:
    if (ch & 0x04)
        goto loc_1736d;
    if (ch & 0x02)
        goto loc_17355;
    goto loc_1740e;
loc_17355:
    bp = memory16(ds, si + 8);
    if (!(bp & 0x8000))
        goto loc_1736d;
loc_1735c:
    ax |= 0x0007;
    ax++;
    cl = 0;
    memory16(ds, si + 8) = 0x0100;
    dx = 0x0100;
    goto loc_1740e;
loc_1736d:
    if (memory16(ds, si + 48) != 0x0003)
        goto loc_17394;
    if (!(ch & 0x10))
        goto loc_17394;
    sub_176f4();
    if (flags.carry)
        goto loc_17394;
    bx = memory16(ds, si + 2);
    bx &= 0x001f;
    if (bx != 0x0004)
        goto loc_17394;
    memory16(ds, si + 42) = 0x0001;
    goto loc_1740e;
loc_17394:
    memory16(ds, si + 42) = 0x0000;
    memory16(ds, si + 34) = 0x0001;
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    memory16(ds, si + 4) = ax;
    memory(ds, si + 6) = cl;
    dx = 0x0100;
    if (!(ch & 0x01))
        goto loc_173e4;
    if (memory16(ds, 0x8bec) != 0x0003)
        goto loc_173e4;
    dx = memory16(ds, si + 8);
    if ((short)dx < (short)0x0200)
        goto loc_173d8;
    dx = -dx;
    dx += 0x0060;
    memory16(ds, si + 8) = dx;
    dx = 0xf781;
    goto loc_1740e;
loc_173d8:
    memory16(ds, si + 8) = 0x0100;
    dx = 0xfa00;
    goto loc_1740e;
loc_173e4:
    memory16(ds, si + 8) = dx;
    dx = 0xfa00;
    if (!(ch & 0x01))
        goto loc_1740e;
    if (memory16(ds, 0x8bec) != 0x0001)
        goto loc_173ff;
    dx = 0xfe00;
    goto loc_1740e;
loc_173ff:
    if (memory16(ds, 0x8bec) != 0x0005)
        goto loc_1740e;
    memory16(ds, si + 8) = 0xf781;
    goto loc_1743b;
loc_1740e:
    memory16(ds, si + 4) = ax;
    memory(ds, si + 6) = cl;
    if (memory16(ds, si + 48) != 0x0003)
        goto loc_1743b;
    if (!(ch & 0x08))
        goto loc_1743b;
    if (ch & 0x10)
        goto loc_1743b;
    sub_176f4();
    if (!flags.carry)
        goto loc_1743b;
    bx = memory16(ds, si + 2);
    bx &= 0x001f;
    if (bx != 0x0004)
        goto loc_1743b;
    memory16(ds, si + 42) = 0x0001;
loc_1743b:
    if (memory16(ds, 0x6e03) != 0x0001)
        goto loc_1744d;
    dx = memory16(ds, si + 44);
    bx = memory16(ds, si + 2);
    bx += dx;
    goto loc_17573;
loc_1744d:
    bp = memory16(cs, si + 8);
    if (bp & 0x8000)
        goto loc_1745e;
    if (memory16(ds, si + 34) == 0x0001)
        goto loc_1745e;
    goto loc_1746a;
loc_1745e:
    if (memory16(ds, si + 48) != 0x0003)
        goto loc_17473;
    if (memory16(ds, si + 42) != 0x0001)
        goto loc_17473;
loc_1746a:
    dx = 0x0000;
    bx = memory16(ds, si + 2);
    goto loc_17573;
loc_17473:
    dx = memory16(ds, si + 16);
    if (!(ch & 0x01))
        goto loc_174a3;
    if (memory16(ds, 0x8bec) == 0x0002)
        goto loc_1749e;
    if (memory16(ds, 0x8bec) != 0x0004)
        goto loc_174a3;
    memory16(ds, si + 38) = 0x0001;
    dx = 0x0001;
    if (!(memory16(ds, si + 16) & 0x8000))
        goto loc_174a3;
    dx = -dx;
    goto loc_174a3;
loc_1749e:
    memory16(ds, si + 40) = 0x0001;
loc_174a3:
    if (memory16(ds, si + 48) != 0x0001)
        goto loc_174be;
    memory16(ds, si + 20) = memory16(ds, si + 20) + 1;
    ax = memory16(ds, si + 18);
    if (ax != memory16(ds, si + 20))
        goto loc_174f8;
    ax = 0;
    memory16(ds, si + 20) = ax;
    dx = -dx;
    goto loc_174f8;
loc_174be:
    if (memory16(ds, si + 48) != 0x0002)
        goto loc_174e0;
    ax = memory16(ds, si + 2);
    ax &= 0x000f;
    if (ax != 0x0004)
        goto loc_174f8;
    sub_19b40();
    if (memory(ds, 0x973f) & 0x01)
        goto loc_174f8;
    sub_176e6();
    goto loc_174f8;
loc_174e0:
    ax = memory16(ds, si + 2);
    ax &= 0x000f;
    if (ax != 0x0004)
        goto loc_174f8;
    sub_19b40();
    if (memory(ds, 0x973f) & 0x01)
        goto loc_174f8;
    dx = -dx;
loc_174f8:
    dx += memory16(ds, si + 44);
    bx = memory16(ds, si + 2);
    bx += dx;
    if (!dx)
        goto loc_1751e;
    if (!(dx & 0x8000))
        goto loc_17513;
    if ((short)bx >= (short)0x0000)
        goto loc_1751e;
    bx = 0x0000;
    dx = -dx;
    goto loc_1751e;
loc_17513:
    if ((short)bx < (short)0x00e8)
        goto loc_1751e;
    bx = 0x00e8;
    dx = -dx;
loc_1751e:
    ax = memory16(ds, si + 4);
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x7961) = 0xffff;
    memory16(ds, 0x795d) = bx;
    memory(ds, 0x796b) = 0x01;
    sub_17dfb();
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_17544;
    goto loc_17674;
loc_17544:
    if (!(ch & 0x02))
        goto loc_17573;
    if (!(dx & 0x8000))
        goto loc_17562;
    bx += 0x000c;
    bx &= 0x00f8;
    bx -= 0x0004;
    dx = -dx;
    memory16(ds, si + 20) = 0x0000;
    goto loc_17573;
loc_17562:
    bx += 0x0003;
    bx &= 0x00f8;
    bx -= 0x0004;
    dx = -dx;
    memory16(ds, si + 20) = 0x0000;
loc_17573:
    if (memory16(ds, 0x6e20) == 0x0001)
        goto loc_17584;
    memory16(ds, si + 2) = bx;
    if (!dx)
        goto loc_17584;
    memory16(ds, si + 16) = dx;
loc_17584:
    if (memory16(ds, si + 48) != 0x0003)
        goto loc_17595;
    if (ch & 0x08)
        goto loc_17595;
    memory16(ds, si + 42) = 0x0000;
loc_17595:
    if (memory16(ds, 0x6e03) == 0x0001)
        goto loc_175a6;
    if (memory16(ds, 0x6e20) == 0x0001)
        goto loc_175a6;
    sub_17723();
loc_175a6:
    if (memory16(ds, 0x7ecc) != 0x0001)
        goto loc_175c6;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    sub_1646e();
    if (!flags.carry)
        goto loc_175c6;
    memory16(ds, si + 24) = 0x0028;
    goto loc_175de;
loc_175c6:
    bx = memory16(ds, si + 4);
    bx += 0x0004;
    dh = memory(ds, si + 2);
    dh += 0x04;
    dl = 0x10;
    ah = 0x15;
    sub_16407();
    if (!flags.carry)
        goto loc_175de;
    goto loc_168a8;
loc_175de:
    if (memory16(ds, 0x0b00) != 0x0001)
        goto loc_175ff;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    sub_164a0();
    if (!flags.carry)
        goto loc_175ff;
    memory16(ds, 0x0b00) = 0x0000;
    goto loc_17674;
loc_175ff:
    if (memory16(ds, 0x0b38) != 0x0002)
        goto loc_17643;
    al = memory(ds, 0x0b4a);
    if ((char)al <= (char)0x01)
        goto loc_17643;
    if ((char)al > (char)0x04)
        goto loc_17643;
    bx = memory16(ds, si + 4);
    dh = memory(ds, si + 2);
    dl = memory(ds, si + 30);
    ah = memory(ds, si + 32);
    if (dh >= 0x0f)
        goto loc_17627;
    dh = 0;
    goto loc_1762a;
loc_17627:
    dh -= 0x10;
loc_1762a:
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
loc_17643:
    return;
loc_17644:
    ax = memory16(ds, si + 4);
    cl = 0;
    bp = memory16(ds, 0x0b20);
    bp++;
    bp &= 0x00fe;
    ax &= 0x00fe;
    sub_17702();
    memory16(ds, 0x7961) = bp;
    ax = memory16(ds, si + 4);
    ax += bp;
    memory16(ds, si + 8) = bp;
    memory16(ds, 0x795f) = ax;
    bx = memory16(ds, si + 2);
    memory16(ds, 0x795d) = bx;
    sub_17dfb();
    goto loc_172cd;
loc_17674:
    push(si);
    si = 0x670b;
    sub_16bc7();
    si = pop();
    memory16(ds, si + 22) = 0x0001;
    memory16(ds, si + 8) = 0xfb00;
    ax = 0x000c;
    sub_1aecd();
    ax = memory16(ds, si + 2);
    if ((short)ax < (short)0x0080)
        goto loc_1769a;
    memory16(ds, si + 16) = 0xfffe;
    return;
loc_1769a:
    memory16(ds, si + 16) = 0x0002;
    return;
loc_176a0:
    dx = memory16(ds, si + 8);
    dx += 0x0080;
    memory16(ds, si + 8) = dx;
    if (dx & 0x8000)
        goto loc_176b3;
    ch = 0;
    goto loc_176b5;
loc_176b3:
    ch = 0xff;
loc_176b5:
    ax = memory16(ds, si + 4);
    cl = memory(ds, si + 6);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    if ((short)ax <= (short)0x0110)
        goto loc_176ca;
    sub_16174();
    return;
loc_176ca:
    memory16(ds, si + 4) = ax;
    memory(ds, si + 6) = cl;
    ax = memory16(ds, 0x73ef);
    ax += 0x0006;
    ax += memory16(ds, si + 50);
    memory16(ds, si + 10) = ax;
    ax = memory16(ds, si + 16);
    ax += memory16(ds, si + 2);
    memory16(ds, si + 2) = ax;
}
void sub_17674()
{
    push(si);
    si = 0x670b;
    sub_16bc7();
    si = pop();
    memory16(ds, si + 22) = 0x0001;
    memory16(ds, si + 8) = 0xfb00;
    ax = 0x000c;
    sub_1aecd();
    ax = memory16(ds, si + 2);
    if ((short)ax < (short)0x0080)
        goto loc_1769a;
    memory16(ds, si + 16) = 0xfffe;
    return;
loc_1769a:
    memory16(ds, si + 16) = 0x0002;
}
void sub_176e6()
{
    if ((short)bx <= (short)memory16(ds, 0x0b1e))
        goto loc_176f0;
    dx = 0xfffe;
    return;
loc_176f0:
    dx = 0x0002;
}
void sub_176f4()
{
    if ((short)ax < (short)memory16(ds, 0x0b20))
        goto loc_176fe;
    if (ax == memory16(ds, 0x0b20))
        goto loc_17700;
    flags.carry = true;
    return;
loc_176fe:
    flags.carry = false;
    return;
loc_17700:
    flags.carry = false;
}
void sub_17702()
{
    if (memory16(ds, 0x6e20) != 0x0001)
        goto loc_1770e;
    flags.carry = false;
    bp = 0x0000;
    return;
loc_1770e:
    if ((short)ax < (short)bp)
        goto loc_17719;
    if (ax == bp)
        goto loc_1771e;
    bp = 0xfffe;
    flags.carry = true;
    return;
loc_17719:
    bp = 0x0002;
    flags.carry = false;
    return;
loc_1771e:
    bp = 0x0000;
    flags.carry = false;
}
void sub_17723()
{
    if (memory16(ds, si + 42) == 0x0001)
        goto loc_17756;
    if (memory16(ds, si + 38) == 0x0001)
        goto loc_17770;
    if (memory16(ds, si + 40) == 0x0001)
        goto loc_1778b;
    if (memory16(ds, si + 34) != 0x0001)
        return;
    ax = memory16(ds, si + 16);
    if (ax & 0x8000)
        goto loc_17748;
    ax = 0x0000;
    goto loc_1774b;
loc_17748:
    ax = 0x0003;
loc_1774b:
    ax += memory16(ds, 0x73e7);
    ax += memory16(ds, si + 50);
    memory16(ds, si + 10) = ax;
    return;
loc_17756:
    if (memory16(ds, si + 42) != 0x0001)
        goto loc_17770;
    ax = 0x0008;
    if (memory16(ds, si + 8) == 0x0000)
        goto loc_17769;
    ax += memory16(ds, 0x73ed);
loc_17769:
    ax += memory16(ds, si + 50);
    memory16(ds, si + 10) = ax;
    return;
loc_17770:
    ax = memory16(ds, si + 16);
    if (ax & 0x8000)
        goto loc_1777d;
    ax = 0x0000;
    goto loc_17780;
loc_1777d:
    ax = 0x0003;
loc_17780:
    ax += memory16(ds, 0x73e9);
    ax += memory16(ds, si + 50);
    memory16(ds, si + 10) = ax;
    return;
loc_1778b:
    ax = memory16(ds, si + 16);
    if (ax & 0x8000)
        goto loc_17798;
    ax = 0x0000;
    goto loc_1779b;
loc_17798:
    ax = 0x0003;
loc_1779b:
    ax += memory16(ds, 0x73eb);
    ax += memory16(ds, si + 50);
    memory16(ds, si + 10) = ax;
    return;
}
void sub_177fb()
{
    ax = memory16(ds, 0x73f1);
loc_177fe:
    bx = 0x73a7;
    bx += ax;
    dx = memory16(ds, bx);
    if (dx != 0x00ff)
        goto loc_17810;
    ax = 0x0000;
    goto loc_177fe;
loc_17810:
    memory16(ds, 0x73e7) = dx;
    ax++;
    ax++;
    memory16(ds, 0x73f1) = ax;
    ax = memory16(ds, 0x73f3);
loc_1781c:
    bx = 0x73b5;
    bx += ax;
    dx = memory16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1782e;
    ax = 0x0000;
    goto loc_1781c;
loc_1782e:
    memory16(ds, 0x73e9) = dx;
    ax++;
    ax++;
    memory16(ds, 0x73f3) = ax;
    ax = memory16(ds, 0x73f5);
loc_1783a:
    bx = 0x73cf;
    bx += ax;
    dx = memory16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1784c;
    ax = 0x0000;
    goto loc_1783a;
loc_1784c:
    memory16(ds, 0x73eb) = dx;
    ax++;
    ax++;
    memory16(ds, 0x73f5) = ax;
    ax = memory16(ds, 0x73f7);
loc_17858:
    bx = 0x73d7;
    bx += ax;
    dx = memory16(ds, bx);
    if (dx != 0x00ff)
        goto loc_1786a;
    ax = 0x0000;
    goto loc_17858;
loc_1786a:
    memory16(ds, 0x73ed) = dx;
    ax++;
    ax++;
    memory16(ds, 0x73f7) = ax;
    ax = memory16(ds, 0x73f9);
loc_17876:
    bx = 0x73e1;
    bx += ax;
    dx = memory16(ds, bx);
    if (dx != 0x00ff)
        goto loc_17888;
    ax = 0x0000;
    goto loc_17876;
loc_17888:
    memory16(ds, 0x73ef) = dx;
    ax++;
    ax++;
    memory16(ds, 0x73f9) = ax;
}
void sub_17896()
{
    bx = memory16(ds, si + 16);
    al = memory(ds, bx);
    if (al != 0x00)
        goto loc_178a5;
    bx++;
    bx = memory16(ds, bx);
    memory16(ds, si + 16) = bx;
loc_178a5:
    bx++;
    al = memory(ds, bx);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    if (al != 0x07)
        goto loc_178b6;
    al++;
loc_178b6:
    cbw();
    memory16(ds, 0x7492) = ax;
    al = memory(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_178c4;
    al |= 0xf0;
loc_178c4:
    if (al != 0x07)
        goto loc_178ca;
    al++;
loc_178ca:
    cbw();
    memory16(ds, 0x7494) = ax;
    bx--;
    al = memory(ds, bx);
    cbw();
    memory16(ds, si + 18) = memory16(ds, si + 18) + 1;
    if (ax == memory16(ds, si + 18))
        goto loc_178dc;
    if (ax >= memory16(ds, si + 18))
        goto loc_178e6;
loc_178dc:
    memory16(ds, si + 18) = 0x0000;
    bx++;
    bx++;
    memory16(ds, si + 16) = bx;
loc_178e6:
    ax = memory16(ds, 0x7492);
    dx = memory16(ds, 0x7494);
}
void sub_17a31()
{
    memory16(ds, 0x7629) = 0x0014;
    di = 0x0c28;
    si = 0x74ee;
    cx = 0x0005;
loc_17a40:
    memory16(ds, di) = 0x0001;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 2) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 4) = ax;
    ax = 0;
    memory16(ds, di + 14) = ax;
    memory16(ds, di + 12) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 22) = ax;
    ax = 0;
    memory16(ds, di + 24) = ax;
    push(si);
    push(di);
    push(cx);
    si = di;
    sub_1718e();
    cx = pop();
    di = pop();
    si = pop();
    ax = 0;
    memory16(ds, di + 24) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 16) = ax;
    ax = 0;
    memory16(ds, di + 18) = ax;
    memory16(ds, di + 20) = ax;
    di += 0x0034;
    if (--cx)
        goto loc_17a40;
    memory16(ds, 0x0d2c) = ax;
    memory16(ds, 0x762b) = ax;
    memory16(ds, 0x762f) = 0x0001;
}
void sub_17a8b()
{
    if (memory16(ds, 0x762d) != 0x0001)
        goto loc_17a9c;
    if (memory16(ds, 0x762f) == 0x0001)
        goto loc_17a9d;
loc_17a9c:
    return;
loc_17a9d:
    si = 0x0c28;
    sub_17896();
    cx = 0x0005;
loc_17aa6:
    push(cx);
    memory16(ds, si + 2) = memory16(ds, si + 2) + ax;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
    push(ax);
    push(dx);
    sub_1718e();
    dx = pop();
    ax = pop();
    si += 0x0034;
    cx = pop();
    if (--cx)
        goto loc_17aa6;
    dh = memory(ds, 0x0c2a);
    bx = memory16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    sub_16407();
    if (!flags.carry)
        goto loc_17ad1;
    sub_168a8();
    goto loc_17aeb;
loc_17ad1:
    dh = memory(ds, 0x0c2a);
    dh += 0xec;
    bx = memory16(ds, 0x0c2c);
    bx += 0x0018;
    dl = 0x14;
    ah = 0x20;
    sub_16407();
    if (!flags.carry)
        goto loc_17aeb;
    sub_168a8();
loc_17aeb:
    dh = memory(ds, 0x0c2a);
    bx = memory16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    sub_164a0();
    if (!flags.carry)
        goto loc_17b0d;
    memory16(ds, 0x0b00) = 0x0000;
    sub_17d53();
    if (!flags.carry)
        goto loc_17b0a;
    goto loc_17ba5;
loc_17b0a:
    goto loc_17b2f;
loc_17b0d:
    dh = memory(ds, 0x0c2a);
    dh += 0xec;
    bx = memory16(ds, 0x0c2c);
    bx += 0x0018;
    dl = 0x14;
    ah = 0x20;
    sub_164a0();
    if (!flags.carry)
        goto loc_17b2f;
    memory16(ds, 0x0b00) = 0x0000;
    sub_17d53();
    if (flags.carry)
        goto loc_17ba5;
loc_17b2f:
    dh = memory(ds, 0x0c2a);
    bx = memory16(ds, 0x0c2c);
    dl = 0x1c;
    ah = 0x40;
    dh -= 0x10;
    bx -= 0x000e;
    dl += 0x20;
    ah += 0x1d;
    if (memory16(ds, 0x0b38) != 0x0002)
        goto loc_17b96;
    if ((short)memory16(ds, 0x0b4a) > (short)0x0004)
        goto loc_17b96;
    if ((short)memory16(ds, 0x0b4a) <= (short)0x0001)
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
loc_17b6e:
    dh = memory(ds, 0x0c2a);
    dh += 0xec;
    bx = memory16(ds, 0x0c2c);
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
loc_17b96:
    if (memory16(ds, 0x0d2c) == 0x0001)
        goto loc_17ba1;
    sub_17c64();
    return;
loc_17ba1:
    sub_17cf4();
    return;
loc_17ba5:
    memory16(ds, 0x762d) = 0x0000;
    memory16(ds, 0x762f) = 0x0000;
    memory(ds, 0x5b3e) = 0x01;
    cx = 0x0005;
    si = 0x758b;
    di = 0x0c28;
loc_17bbf:
    memory16(ds, di) = 0x0011;
    memory16(ds, di + 50) = 0x0060;
    memory16(ds, di + 28) = 0x0000;
    memory16(ds, di + 24) = 0x0000;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 22) = ax;
    memory16(ds, di + 18) = 0x0000;
    memory16(ds, di + 20) = 0x0000;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 16) = ax;
    di += 0x0034;
    if (--cx)
        goto loc_17bbf;
    di = 0x0b56;
    memory16(ds, di) = 0x0001;
    ax = memory16(ds, 0x0c2a);
    memory16(ds, di + 2) = ax;
    ax = memory16(ds, 0x0c2c);
    memory16(ds, di + 4) = ax;
    memory16(ds, di + 50) = 0x0034;
    memory16(ds, di + 22) = 0x0001;
    memory16(ds, di + 24) = 0x0000;
    memory16(ds, di + 6) = 0x0000;
    memory16(ds, di + 8) = 0xfb00;
    memory16(ds, di + 16) = 0xfffe;
    memory16(ds, di + 28) = 0x0000;
    memory16(ds, 0x0d2c) = 0x0000;
    if (memory16(ds, 0x8bee) != 0x0001)
        return;
    cx = memory16(ds, 0x6610);
    if (!cx)
        goto loc_17c3e;
loc_17c34:
    si = 0x6729;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c34;
loc_17c3e:
    cx = memory16(ds, 0x6612);
    if (!cx)
        goto loc_17c50;
loc_17c46:
    si = 0x672f;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c46;
loc_17c50:
    cx = memory16(ds, 0x6614);
    cx++;
    if (!cx)
        return;
loc_17c59:
    si = 0x6735;
    push(cx);
    sub_16bc7();
    cx = pop();
    if (--cx)
        goto loc_17c59;
}
void sub_17c64()
{
    if (!(memory16(ds, 0x762b) & 0xffff))
        goto loc_17c71;
    memory16(ds, 0x762b) = memory16(ds, 0x762b) - 1;
    return;
loc_17c71:
    ax = 0x000d;
    sub_1aecd();
    memory16(ds, 0x762b) = 0x0032;
    memory16(ds, 0x0d2c) = 0x0001;
    memory16(ds, 0x0d36) = 0x0055;
    ax = memory16(ds, 0x0b1e);
    ax += 0x000c;
    bx = memory16(ds, 0x0b20);
    bx += 0x000a;
    cx = memory16(ds, 0x0c2a);
    cx += 0xffe4;
    memory16(ds, 0x0d2e) = cx;
    dx = memory16(ds, 0x0c2c);
    dx += 0x002c;
    memory16(ds, 0x0d30) = dx;
    ax -= cx;
    cx = ax;
    bx -= dx;
    dx = bx;
loc_17cb4:
    if ((short)ax > (short)0x0004)
        goto loc_17ccb;
    if ((short)ax < (short)0xfffc)
        goto loc_17ccb;
    if ((short)bx > (short)0x0004)
        goto loc_17ccb;
    if ((short)bx < (short)0xfffc)
        goto loc_17ccb;
    goto loc_17cec;
loc_17ccb:
    ax = sar(ax, 1);
    bx = sar(bx, 1);
    if (ax != 0x0000)
        goto loc_17cb4;
    if (bx != 0x0000)
        goto loc_17cb4;
    ax = 0x0004;
    bx = ax;
    if ((short)cx >= (short)0x0000)
        goto loc_17ce5;
    ax = -ax;
loc_17ce5:
    sync();
    if ((short)dx >= (short)0x0000)
        goto loc_17ce5;
    bx = -bx;
loc_17cec:
    memory16(ds, 0x0d3c) = ax;
    memory16(ds, 0x0d34) = bx;
}
void sub_17cf4()
{
    memory16(ds, 0x762b) = memory16(ds, 0x762b) - 1;
    if ((short)memory16(ds, 0x762b) >= 0)
        goto loc_17d00;
    memory16(ds, 0x762b) = 0x0000;
loc_17d00:
    ax = memory16(ds, 0x0d2e);
    ax += memory16(ds, 0x0d3c);
    memory16(ds, 0x0d2e) = ax;
    dx = memory16(ds, 0x0d30);
    dx += memory16(ds, 0x0d34);
    memory16(ds, 0x0d30) = dx;
    ax += 0x0004;
    if ((short)ax <= (short)0x0004)
        goto loc_17d4c;
    if ((short)ax >= (short)0x00fc)
        goto loc_17d4c;
    dx += 0x0004;
    memory16(ds, 0x795d) = ax;
    memory16(ds, 0x795f) = dx;
    sub_18014();
    ch = memory(ds, 0x7963);
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
        return;
    sub_168a8();
loc_17d4c:
    memory16(ds, 0x0d2c) = 0x0000;
}
void sub_17d53()
{
    memory16(ds, 0x7629) = memory16(ds, 0x7629) - 1;
    if (memory16(ds, 0x7629) == 0)
        goto loc_17d5b;
    flags.carry = false;
    return;
loc_17d5b:
    flags.carry = true;
}
void sub_17d70()
{
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    memory16(ds, 0x796c) = 0x0005;
    memory16(ds, 0x796e) = 0x0010;
    memory16(ds, 0x7964) = 0x7fff;
    memory16(ds, 0x7e02) = 0x0000;
    cx = 0x0003;
    dx = memory16(ds, 0x795f);
    dx &= 0x0007;
    if ((short)dx >= (short)0x0004)
        goto loc_17d9f;
    cx = 0x0002;
loc_17d9f:
    memory(ds, 0x796a) = 0x00;
    bp = 0x0004;
    sub_17ff3();
    dx &= 0x0007;
    if (dx == 0)
        goto loc_17dd7;
    ax = 0;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001d;
    bl &= 0x02;
    if (bl == 0)
        goto loc_17e2f;
    memory16(ds, 0x7e02) = 0x0001;
    goto loc_17e2f;
loc_17dd7:
    ax = 0;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001e;
    bl &= 0x02;
    if (bl != 0)
        goto loc_17df2;
    goto loc_17e8a;
loc_17df2:
    memory16(ds, 0x7e02) = 0x0001;
    goto loc_17e8a;
    //   gap of 52 bytes
loc_17e2f:
    bx = 0;
    ax = 0;
    goto loc_17e4e;
loc_17e36:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bh |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001d;
loc_17e4e:
    if (--cx)
        goto loc_17e36;
    bl &= 0x22;
    bh &= 0x2a;
    memory(ds, 0x796a) = bl;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bh;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bh = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    bl &= 0x27;
    bh &= 0x7f;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bl;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bh;
    al = memory(ds, 0x796a);
    memory(ds, 0x7963) = al;
    goto loc_17ec9;
loc_17e8a:
    bx = 0;
    ax = 0;
    goto loc_17ea2;
loc_17e91:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001e;
loc_17ea2:
    if (--cx)
        goto loc_17e91;
    bl &= 0x2a;
    memory(ds, 0x796a) = bl;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    bl &= 0x7f;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bl;
    al = memory(ds, 0x796a);
    memory(ds, 0x7963) = al;
    goto loc_17ec9;
loc_17ec9:
    ax = memory16(ds, 0x7961);
    if (!(ax & 0x8000))
        goto loc_17ed8;
    al = memory(ds, 0x7963);
    al &= 0xfb;
    memory(ds, 0x7963) = al;
loc_17ed8:
    if (memory(ds, 0x796b) == 0x01)
        goto loc_17ee2;
    goto loc_17fb9;
loc_17ee2:
    si = 0x0c28;
loc_17ee5:
    ax = memory16(ds, si);
    if (ax != 0xffff)
        goto loc_17eef;
    goto loc_17fb9;
loc_17eef:
    if (al)
        goto loc_17ef6;
    goto loc_17fb3;
loc_17ef6:
    if (al & 0x80)
        goto loc_17efd;
    goto loc_17fb3;
loc_17efd:
    if (!(al & 0x40))
        goto loc_17f68;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, si + 32);
    ch = memory(ds, 0x795d);
    ch += 0x04;
    bp = memory16(ds, 0x795f);
    bp += memory16(ds, 0x796c);
    dh = 0x10;
    bh = memory(ds, 0x796e);
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_17f2f;
    goto loc_17fb3;
loc_17f2f:
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x02;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_17f65;
    bx = memory16(ds, 0x795f);
    bx += 0x0014;
    ax = 0;
    al = memory(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_17f65;
    memory16(ds, 0x7964) = di;
    memory16(ds, 0x7966) = 0x0000;
    memory16(ds, 0x7968) = 0x0000;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
loc_17f65:
    goto loc_17fb3;
loc_17f68:
    ax = memory16(ds, 0x7961);
    if (ax & 0x8000)
        goto loc_17fb3;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, 0x7962);
    bl += 0x08;
    ch = memory(ds, 0x795d);
    ch += 0x04;
    bp = memory16(ds, 0x795f);
    bp += 0x0014;
    dh = 0x10;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_17fb3;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_17fb3;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
    memory16(ds, 0x7964) = di;
    ax = memory16(ds, si + 46);
    memory16(ds, 0x7966) = ax;
    ax = memory16(ds, si + 48);
    memory16(ds, 0x7968) = ax;
loc_17fb3:
    si += 0x0034;
    goto loc_17ee5;
loc_17fb9:
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
}
void sub_17dfb()
{
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    memory16(ds, 0x796c) = 0x0000;
    memory16(ds, 0x796e) = 0x0015;
    memory16(ds, 0x7964) = 0x7fff;
    cx = 0x0004;
    dx = memory16(ds, 0x795f);
    dx &= 0x0007;
    if ((short)dx >= (short)0x0004)
        goto loc_17e24;
    cx = 0x0003;
loc_17e24:
    bp = 0x0004;
    sub_17ff3();
    dx &= 0x0007;
    if (dx == 0)
        goto loc_17e8a;
    bx = 0;
    ax = 0;
    goto loc_17e4e;
loc_17e36:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bh |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001d;
loc_17e4e:
    if (--cx)
        goto loc_17e36;
    bl &= 0x22;
    bh &= 0x2a;
    memory(ds, 0x796a) = bl;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bh;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bh = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    bl &= 0x27;
    bh &= 0x7f;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bl;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bh;
    al = memory(ds, 0x796a);
    memory(ds, 0x7963) = al;
    goto loc_17ec9;
loc_17e8a:
    bx = 0;
    ax = 0;
    goto loc_17ea2;
loc_17e91:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001e;
loc_17ea2:
    if (--cx)
        goto loc_17e91;
    bl &= 0x2a;
    memory(ds, 0x796a) = bl;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    bl &= 0x7f;
    memory(ds, 0x796a) = memory(ds, 0x796a) | bl;
    al = memory(ds, 0x796a);
    memory(ds, 0x7963) = al;
    goto loc_17ec9;
loc_17ec9:
    ax = memory16(ds, 0x7961);
    if (!(ax & 0x8000))
        goto loc_17ed8;
    al = memory(ds, 0x7963);
    al &= 0xfb;
    memory(ds, 0x7963) = al;
loc_17ed8:
    if (memory(ds, 0x796b) == 0x01)
        goto loc_17ee2;
    goto loc_17fb9;
loc_17ee2:
    si = 0x0c28;
loc_17ee5:
    ax = memory16(ds, si);
    if (ax != 0xffff)
        goto loc_17eef;
    goto loc_17fb9;
loc_17eef:
    if (al)
        goto loc_17ef6;
    goto loc_17fb3;
loc_17ef6:
    if (al & 0x80)
        goto loc_17efd;
    goto loc_17fb3;
loc_17efd:
    if (!(al & 0x40))
        goto loc_17f68;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, si + 32);
    ch = memory(ds, 0x795d);
    ch += 0x04;
    bp = memory16(ds, 0x795f);
    bp += memory16(ds, 0x796c);
    dh = 0x10;
    bh = memory(ds, 0x796e);
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_17f2f;
    goto loc_17fb3;
loc_17f2f:
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x02;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_17f65;
    bx = memory16(ds, 0x795f);
    bx += 0x0014;
    ax = 0;
    al = memory(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_17f65;
    memory16(ds, 0x7964) = di;
    memory16(ds, 0x7966) = 0x0000;
    memory16(ds, 0x7968) = 0x0000;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
loc_17f65:
    goto loc_17fb3;
loc_17f68:
    ax = memory16(ds, 0x7961);
    if (ax & 0x8000)
        goto loc_17fb3;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, 0x7962);
    bl += 0x08;
    ch = memory(ds, 0x795d);
    ch += 0x04;
    bp = memory16(ds, 0x795f);
    bp += 0x0014;
    dh = 0x10;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_17fb3;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_17fb3;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
    memory16(ds, 0x7964) = di;
    ax = memory16(ds, si + 46);
    memory16(ds, 0x7966) = ax;
    ax = memory16(ds, si + 48);
    memory16(ds, 0x7968) = ax;
loc_17fb3:
    si += 0x0034;
    goto loc_17ee5;
loc_17fb9:
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
}
void sub_17fbf()
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
    flags.carry = true;
    return;
loc_17ff1:
    flags.carry = false;
}
void sub_17ff3()
{
    si = 0x563c;
    dx = memory16(ds, 0x795f);
    dx &= 0xfff8;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    dx = memory16(ds, 0x795d);
    dx += bp;
    bp = dx;
    bp >>= 1;
    bp >>= 1;
    bp >>= 1;
    si += bp;
}
void sub_18014()
{
    push(ax);
    push(dx);
    bp = 0;
    sub_17ff3();
    ax = 0;
    lodsb<MemData, DirForward>();
    di = ax;
    al = memory(ds, di + 21492);
    memory(ds, 0x7963) = al;
    sub_181c6();
    dx = pop();
    ax = pop();
}
void sub_1802d()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    cx = 0x0002;
    ax = memory16(ds, 0x795f);
    ax &= 0x0007;
    if (ax == 0)
        goto loc_1803f;
    cx = 0x0003;
loc_1803f:
    bp = 0x0008;
    sub_17ff3();
    dx &= 0x0007;
    if (dx == 0)
        goto loc_18083;
    bx = 0;
    ax = 0;
    goto loc_18062;
loc_18051:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001e;
loc_18062:
    if (--cx)
        goto loc_18051;
    bl &= 0x23;
    bh = bl;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    bl &= 0x27;
    bh |= bl;
    memory(ds, 0x7963) = bh;
    goto loc_180ae;
loc_18083:
    bx = 0;
    ax = 0;
    goto loc_18094;
loc_1808a:
    lodsb<MemData, DirForward>();
    di = ax;
    bl |= memory(ds, di + 21492);
    si += 0x001f;
loc_18094:
    if (--cx)
        goto loc_1808a;
    bl &= 0x2b;
    bh = bl;
    lodsb<MemData, DirForward>();
    di = ax;
    bl = memory(ds, di + 21492);
    bl &= 0x27;
    bh |= bl;
    memory(ds, 0x7963) = bh;
    goto loc_180ae;
loc_180ae:
    ax = memory16(ds, 0x7961);
    if (!(ax & 0x8000))
        goto loc_180c0;
    bh = memory(ds, 0x7963);
    bh &= 0xfb;
    memory(ds, 0x7963) = bh;
loc_180c0:
    if (memory(ds, 0x796b) == 0x01)
        goto loc_180ca;
    goto loc_1819f;
loc_180ca:
    si = 0x0c28;
loc_180cd:
    ax = memory16(ds, si);
    if (ax != 0xffff)
        goto loc_180d7;
    goto loc_1819f;
loc_180d7:
    if (al)
        goto loc_180de;
    goto loc_18199;
loc_180de:
    if (al & 0x80)
        goto loc_180e5;
    goto loc_18199;
loc_180e5:
    if (!(al & 0x40))
        goto loc_1814e;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, si + 32);
    ch = memory(ds, 0x795d);
    ch += 0x08;
    bp = memory16(ds, 0x795f);
    bp += memory16(ds, 0x796c);
    dh = 0x08;
    bh = 0x10;
    push(si);
    sub_17fbf();
    si = pop();
    if (flags.carry)
        goto loc_18115;
    goto loc_18199;
loc_18115:
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x02;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_1814b;
    bx = memory16(ds, 0x795f);
    bx += 0x0010;
    ax = 0;
    al = memory(ds, 0x7962);
    cbw();
    ax += 0x0008;
    ax += di;
    if ((short)bx > (short)ax)
        goto loc_1814b;
    memory16(ds, 0x7964) = di;
    memory16(ds, 0x7966) = 0x0000;
    memory16(ds, 0x7968) = 0x0000;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
loc_1814b:
    goto loc_18199;
loc_1814e:
    ax = memory16(ds, 0x7961);
    if (ax & 0x8000)
        goto loc_18199;
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = memory(ds, si + 30);
    bl = memory(ds, 0x7962);
    bl += 0x08;
    ch = memory(ds, 0x795d);
    ch += 0x08;
    bp = memory16(ds, 0x795f);
    bp += 0x000f;
    dh = 0x08;
    bh = 0x01;
    push(si);
    sub_17fbf();
    si = pop();
    if (!flags.carry)
        goto loc_18199;
    if ((short)di > (short)memory16(ds, 0x7964))
        goto loc_18199;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
    memory16(ds, 0x7964) = di;
    ax = memory16(ds, si + 46);
    memory16(ds, 0x7966) = ax;
    ax = memory16(ds, si + 48);
    memory16(ds, 0x7968) = ax;
loc_18199:
    si += 0x0034;
    goto loc_180cd;
loc_1819f:
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_181a4()
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
    flags.carry = true;
    return;
loc_181c4:
    flags.carry = false;
}
void sub_181c6()
{
    si = 0x0c28;
loc_181c9:
    ax = memory16(ds, si);
    if (ax == 0xffff)
        return;
    if (!al)
        goto loc_181f8;
    if (!(al & 0x80))
        goto loc_181f8;
    if (!(al & 0x40))
        goto loc_181f8;
    ch = memory(ds, 0x795d);
    bp = memory16(ds, 0x795f);
    cl = memory(ds, si + 2);
    di = memory16(ds, si + 4);
    dl = 0x18;
    bl = 0x15;
    sub_181a4();
    if (!flags.carry)
        goto loc_181f8;
    memory(ds, 0x7963) = memory(ds, 0x7963) | 0x40;
loc_181f8:
    si += 0x0034;
    goto loc_181c9;
}
void sub_18351()
{
    goto loc_18351;
loc_168a8:
    ax = 0x000b;
    sub_1aecd();
    memory16(ds, 0x7e16) = 0x0001;
    memory16(ds, 0x0b24) = 0xfb00;
    ax = memory16(ds, 0x0b1e);
    if ((short)ax < (short)0x0080)
        goto loc_168cb;
    memory16(ds, 0x7e1c) = 0xfffe;
    goto loc_168d1;
loc_168cb:
    memory16(ds, 0x7e1c) = 0x0002;
loc_168d1:
    ax = memory16(ds, 0x6614);
    if (!ax)
        goto loc_168e3;
    if (memory(ds, 0x9804) == 0x01)
        goto loc_168e3;
    memory16(ds, 0x6614) = memory16(ds, 0x6614) - 1;
loc_168e3:
    return;
    //   gap of 6765 bytes
loc_18351:
    if (memory16(ds, 0x7e16) != 0x0001)
        goto loc_1835b;
    goto loc_18f9a;
loc_1835b:
    sub_19c05();
    ax = memory16(ds, 0x0b20);
    memory16(ds, 0x7dfe) = ax;
    memory(ds, 0x90c2) = 0x00;
    memory16(ds, 0x7e1a) = 0x0000;
    sub_1c4ca();
    if (!(memory16(ds, 0x7ed2) & 0x00ff))
        goto loc_1837f;
    memory16(ds, 0x7ed2) = memory16(ds, 0x7ed2) - 1;
loc_1837f:
    if (al == memory(ds, 0x7eca))
        goto loc_18396;
    memory(ds, 0x7eca) = 0x00;
    memory16(ds, 0x7ecc) = 0x0000;
    memory16(ds, 0x7ed2) = 0x0000;
loc_18396:
    if (memory16(ds, 0x7e00) != 0x0001)
        goto loc_183a0;
    goto loc_18b03;
loc_183a0:
    ax = memory16(ds, 0x7e06);
    if (!ax)
        goto loc_183aa;
    goto loc_18987;
loc_183aa:
    memory16(ds, 0x7e08) = 0x0000;
    memory16(ds, 0x7e0a) = 0x0000;
    memory16(ds, 0x7e0c) = 0x0000;
    memory16(ds, 0x7e0e) = 0x0000;
    memory16(ds, 0x7e10) = 0x0000;
    memory16(ds, 0x7e14) = 0x0000;
    memory(ds, 0x796b) = 0x01;
    dx = memory16(ds, 0x0b24);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_183e4;
    dx = 0x0800;
loc_183e4:
    memory16(ds, 0x0b24) = dx;
    memory16(ds, 0x7961) = dx;
    if (dx & 0x8000)
        goto loc_183f5;
    ch = 0;
    goto loc_183f7;
loc_183f5:
    ch = 0xff;
loc_183f7:
    ax = memory16(ds, 0x0b20);
    cl = memory(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    memory16(ds, 0x795f) = ax;
    dx = memory16(ds, 0x0b1e);
    memory16(ds, 0x795d) = dx;
    memory(ds, 0x796b) = 0x01;
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_18421;
    sub_17d70();
    goto loc_18424;
loc_18421:
    sub_17dfb();
loc_18424:
    ch = memory(ds, 0x7963);
    if (!(ch & 0x40))
        goto loc_18485;
    ax = memory16(ds, 0x7964);
    cl = 0;
    ax -= 0x0015;
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x0b20) = ax;
    memory(ds, 0x0b22) = 0x00;
    memory16(ds, 0x7e08) = 0x0001;
    push(ax);
    ax = memory16(ds, 0x7966);
    memory16(ds, 0x7e1a) = ax;
    ax = pop();
    memory(ds, 0x796b) = 0x00;
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_18460;
    sub_17d70();
    goto loc_18463;
loc_18460:
    sub_17dfb();
loc_18463:
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_1846f;
    goto loc_168a8;
loc_1846f:
    ch &= 0x06;
    if (ch == 0)
        goto loc_1847b;
    ch = memory(ds, 0x7963);
    goto loc_184a3;
loc_1847b:
    ch = memory(ds, 0x7963);
    dx = 0x0100;
    goto loc_1857c;
loc_18485:
    if (!(ch & 0x20))
        goto loc_1848d;
    goto loc_168a8;
loc_1848d:
    if (ch & 0x04)
        goto loc_184da;
    if (ch & 0x02)
        goto loc_1849a;
    goto loc_186a8;
loc_1849a:
    bp = memory16(cs, 0x0b24);
    if (!(bp & 0x8000))
        goto loc_184da;
loc_184a3:
    if (memory16(ds, 0x7e06) != 0x0001)
        goto loc_184c8;
    bp = memory16(cs, 0x0b1e);
    bp &= 0x001f;
    if ((short)bp >= (short)0x000a)
        goto loc_184c8;
    bp = memory16(cs, 0x0b1e);
    bp &= 0x00f0;
    bp |= 0x0004;
    memory16(cs, 0x0b1e) = bp;
loc_184c8:
    ax |= 0x0007;
    ax++;
    cl = 0;
    memory16(ds, 0x0b24) = 0x0100;
    dx = 0x0100;
    goto loc_186a8;
loc_184da:
    if (!(ch & 0x10))
        goto loc_18524;
    if (memory(ds, 0xb884) & 0x10)
        goto loc_18524;
    if (memory16(ds, 0x7e04) == 0x0001)
        goto loc_18524;
    if (memory16(ds, 0x7e06) != 0x0001)
        goto loc_184f8;
    goto loc_186a8;
loc_184f8:
    if (!(memory(ds, 0xb884) & 0x04))
        goto loc_18524;
    bx = memory16(ds, 0x0b1e);
    bx &= 0x001f;
    if ((short)bx >= (short)0x000a)
        goto loc_18524;
    bx = memory16(ds, 0x0b1e);
    bx &= 0x00f0;
    bx |= 0x0004;
    memory16(ds, 0x0b1e) = bx;
    memory16(ds, 0x7e06) = 0x0001;
    goto loc_186a8;
loc_18524:
    memory16(ds, 0x7e06) = 0x0000;
    memory16(ds, 0x7e08) = 0x0001;
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    memory16(ds, 0x0b20) = ax;
    memory(ds, 0x0b22) = cl;
    dx = 0x0100;
    if (!(ch & 0x01))
        goto loc_1857c;
    if (memory16(ds, 0x8bec) != 0x0003)
        goto loc_1857c;
    dx = memory16(ds, 0x0b24);
    if ((short)dx < (short)0x0200)
        goto loc_18570;
    dx = -dx;
    dx += 0x0060;
    memory16(ds, 0x0b24) = dx;
    dx = 0xf781;
    ax = 0x0016;
    sub_1aecd();
    goto loc_185ab;
loc_18570:
    memory16(ds, 0x0b24) = 0x0100;
    dx = 0xfa00;
    goto loc_185ab;
loc_1857c:
    memory16(ds, 0x0b24) = dx;
    dx = 0xfa00;
    if (!(ch & 0x01))
        goto loc_185ab;
    if (memory16(ds, 0x8bec) != 0x0001)
        goto loc_18595;
    dx = 0xfe00;
    goto loc_185ab;
loc_18595:
    if (memory16(ds, 0x8bec) != 0x0005)
        goto loc_185ab;
    ax = 0x0017;
    sub_1aecd();
    memory16(ds, 0x0b24) = 0xf781;
    goto loc_186c1;
loc_185ab:
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_185c5;
    if (memory16(ds, 0x7e02) != 0x0001)
        goto loc_185bc;
    goto loc_186c1;
loc_185bc:
    memory16(ds, 0x7e04) = 0x0000;
    goto loc_185f2;
loc_185c5:
    if (memory(ds, 0xb884) & 0x10)
        goto loc_18606;
    if (!(memory(ds, 0xb884) & 0x08))
        goto loc_185f2;
    memory16(ds, 0x0b24) = dx;
    if (!(ch & 0x10))
        goto loc_185e1;
    goto loc_186c1;
loc_185e1:
    if (ch & 0x08)
        goto loc_185e9;
    goto loc_186c1;
loc_185e9:
    memory16(ds, 0x7e06) = 0x0001;
    goto loc_186c1;
loc_185f2:
    if (memory(ds, 0xb884) & 0x04)
        goto loc_185fd;
    goto loc_186c1;
loc_185fd:
    memory16(ds, 0x7e04) = 0x0001;
    goto loc_186c1;
loc_18606:
    if (!(memory(ds, 0xb884) & 0x08))
        goto loc_18611;
    goto loc_189c2;
loc_18611:
    memory16(ds, 0x7e12) = 0x0001;
    if (!(memory(ds, 0xb884) & 0x04))
        goto loc_18622;
    goto loc_189ff;
loc_18622:
    push(ax);
    al = memory(ds, 0xb884);
    if (al != memory(ds, 0x7eca))
        goto loc_18630;
    ax = pop();
    goto loc_189de;
loc_18630:
    ax = pop();
    if (!(memory(ds, 0xb884) & 0x02))
        goto loc_1866a;
    memory16(ds, 0x0b36) = 0x0001;
    bx = memory16(ds, 0x0b1e);
    memory16(ds, 0x7ece) = bx;
    memory16(ds, 0x7ed0) = ax;
    memory16(ds, 0x7ed0) = memory16(ds, 0x7ed0) + 0x0008;
    memory16(ds, 0x7ecc) = 0x0001;
    memory16(ds, 0x7ed2) = 0x000a;
    al = memory(ds, 0xb884);
    memory(ds, 0x7eca) = al;
    ax = 0x0022;
    sub_1aecd();
    goto loc_189de;
loc_1866a:
    if (!(memory(ds, 0xb884) & 0x01))
        goto loc_186c1;
    memory16(ds, 0x0b36) = 0x0000;
    bx = memory16(ds, 0x0b1e);
    memory16(ds, 0x7ece) = bx;
    memory16(ds, 0x7ece) = memory16(ds, 0x7ece) + 0x0018;
    memory16(ds, 0x7ed0) = ax;
    memory16(ds, 0x7ed0) = memory16(ds, 0x7ed0) + 0x0008;
    memory16(ds, 0x7ecc) = 0x0001;
    memory16(ds, 0x7ed2) = 0x000a;
    al = memory(ds, 0xb884);
    memory(ds, 0x7eca) = al;
    ax = 0x0022;
    sub_1aecd();
    goto loc_189de;
loc_186a8:
    memory16(ds, 0x0b20) = ax;
    memory(ds, 0x0b22) = cl;
    al = memory(ds, 0xb884);
    al &= 0x0c;
    if (al == 0)
        goto loc_186c1;
    if (!(ch & 0x08))
        goto loc_186c1;
    memory16(ds, 0x7e06) = 0x0001;
loc_186c1:
    if (memory16(ds, 0x7e06) != 0x0001)
        goto loc_186e2;
    if (ch & 0x08)
        goto loc_186e2;
    memory16(ds, 0x7e06) = 0x0000;
    bp = memory16(cs, 0x0b24);
    if (!(bp & 0x8000))
        goto loc_186e2;
    memory16(ds, 0x0b24) = 0xfe00;
loc_186e2:
    if (!(memory(ds, 0xb884) & 0x02))
        goto loc_1871e;
    memory16(ds, 0x0b36) = 0x0001;
    dx = 0xfffe;
    if (ch & 0x01)
        goto loc_186fb;
    goto loc_1878a;
loc_186fb:
    if (memory16(ds, 0x8bec) != 0x0004)
        goto loc_1870e;
    dx = 0xffff;
    memory16(ds, 0x7e0c) = 0x0001;
    goto loc_1878a;
loc_1870e:
    if (memory16(ds, 0x8bec) != 0x0002)
        goto loc_1878a;
    memory16(ds, 0x7e0e) = 0x0001;
    goto loc_1878a;
loc_1871e:
    if (!(memory(ds, 0xb884) & 0x01))
        goto loc_18757;
    memory16(ds, 0x0b36) = 0x0000;
    dx = 0x0002;
    if (!(ch & 0x01))
        goto loc_1878a;
    if (memory16(ds, 0x8bec) != 0x0004)
        goto loc_18747;
    dx = 0x0001;
    memory16(ds, 0x7e0c) = 0x0001;
    goto loc_1878a;
loc_18747:
    if (memory16(ds, 0x8bec) != 0x0002)
        goto loc_1878a;
    memory16(ds, 0x7e0e) = 0x0001;
    goto loc_1878a;
loc_18757:
    dx = 0;
    if (ch & 0x01)
        goto loc_18767;
    memory16(ds, 0x0b34) = 0xffff;
    goto loc_1878a;
loc_18767:
    if (memory16(ds, 0x8bec) == 0x0002)
        goto loc_18777;
    memory16(ds, 0x0b34) = 0xffff;
    goto loc_1878a;
loc_18777:
    memory16(ds, 0x7e0a) = 0x0001;
    dx = 0x0002;
    if (memory16(ds, 0x0b36) == 0x0000)
        goto loc_1878a;
    dx = 0xfffe;
loc_1878a:
    dx += memory16(ds, 0x7e1a);
    bx = memory16(ds, 0x0b1e);
    bx += dx;
    if (!dx)
        goto loc_187b9;
    if (!(dx & 0x8000))
        goto loc_187aa;
    if ((short)bx >= (short)0x0000)
        goto loc_187b9;
    bx = 0;
    memory(ds, 0x90c2) = 0x01;
    goto loc_187b9;
loc_187aa:
    if ((short)bx < (short)0x00e8)
        goto loc_187b9;
    bx = 0x00e8;
    memory(ds, 0x90c2) = 0x02;
loc_187b9:
    ax = memory16(ds, 0x0b20);
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x7961) = 0xffff;
    memory16(ds, 0x795d) = bx;
    memory(ds, 0x796b) = 0x01;
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_187db;
    sub_17d70();
    goto loc_187de;
loc_187db:
    sub_17dfb();
loc_187de:
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_187ea;
    goto loc_168a8;
loc_187ea:
    if (!(ch & 0x02))
        goto loc_18815;
    if (!(dx & 0x8000))
        goto loc_18804;
    bx += 0x000c;
    bx &= 0x00f8;
    bx -= 0x0004;
    memory16(ds, 0x0b1e) = bx;
    goto loc_1882b;
loc_18804:
    bx += 0x0003;
    bx &= 0x00f8;
    bx -= 0x0004;
    memory16(ds, 0x0b1e) = bx;
    goto loc_1882b;
loc_18815:
    memory16(ds, 0x0b1e) = bx;
    if (memory16(ds, 0x7e06) != 0x0001)
        goto loc_1882b;
    if (ch & 0x08)
        goto loc_1882b;
    memory16(ds, 0x7e06) = 0x0000;
loc_1882b:
    if (memory16(ds, 0x7e00) != 0x0001)
        goto loc_1883e;
    memory16(ds, 0x0b26) = 0x000c;
    sub_18c83();
    goto loc_18975;
loc_1883e:
    if (memory16(ds, 0x7e06) != 0x0001)
        goto loc_18865;
    memory16(ds, 0x0b26) = 0x001a;
    bx = memory16(ds, 0x0b1e);
    ax = memory16(ds, 0x0b20);
    ax ^= bx;
    ax &= 0x0004;
    if (ax != 0)
        goto loc_1885c;
    goto loc_18a8f;
loc_1885c:
    memory16(ds, 0x0b26) = 0x001b;
    goto loc_18a8f;
loc_18865:
    if (memory16(ds, 0x7e08) == 0x0001)
        goto loc_18875;
    memory16(ds, 0x0b26) = 0x0008;
    goto loc_18975;
loc_18875:
    if (!(memory16(ds, 0x7ed2) & 0x00ff))
        goto loc_18886;
    memory16(ds, 0x0b26) = 0x000a;
    goto loc_18975;
loc_18886:
    if (memory16(ds, 0x7e10) != 0x0001)
        goto loc_18896;
    memory16(ds, 0x0b26) = 0x0009;
    goto loc_18975;
loc_18896:
    if (memory16(ds, 0x7e14) != 0x0001)
        goto loc_188b6;
    memory16(ds, 0x0b26) = 0x0000;
    if (memory16(ds, 0x0b52) != 0x0000)
        goto loc_188ad;
    goto loc_18975;
loc_188ad:
    memory16(ds, 0x0b26) = 0x000b;
    goto loc_18975;
loc_188b6:
    if (memory16(ds, 0x7e0a) != 0x0001)
        goto loc_188d6;
    memory16(ds, 0x0b26) = 0x0006;
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_188cd;
    goto loc_18975;
loc_188cd:
    memory16(ds, 0x0b26) = 0x0000;
    goto loc_18975;
loc_188d6:
    if (!(memory(ds, 0x7eca) & 0xff))
        goto loc_188e6;
    memory16(ds, 0x0b26) = 0x0000;
    goto loc_18975;
loc_188e6:
    si = 0x7e2c;
    memory16(ds, 0x0b26) = 0x0006;
    if (memory16(ds, 0x7e04) == 0x0001)
        goto loc_188ff;
    si = 0x7e22;
    memory16(ds, 0x0b26) = 0x0000;
loc_188ff:
    if (memory16(ds, 0x0b34) != 0xffff)
        goto loc_1890f;
    memory16(ds, 0x0b34) = 0x0000;
    goto loc_18975;
loc_1890f:
    ax = 0x0001;
    if (memory16(ds, 0x7e0c) == 0x0001)
        goto loc_18926;
    ax = 0x0004;
    if (memory16(ds, 0x7e0e) == 0x0001)
        goto loc_18926;
    ax = 0x0002;
loc_18926:
    ax += memory16(ds, 0x0b34);
    if ((short)ax < (short)0x0028)
        goto loc_18932;
    ax -= 0x0028;
loc_18932:
    memory16(ds, 0x0b34) = ax;
    ax >>= 1;
    ax >>= 1;
    if (memory16(ds, 0x7e04) != 0x0001)
        goto loc_18950;
    if (!(ax & 0x0001))
        goto loc_1896c;
    push(ax);
    ax = 0x0026;
    sub_1aecd();
    ax = pop();
    goto loc_1896c;
loc_18950:
    if (ax == 0x0002)
        goto loc_18964;
    if (ax == 0x0005)
        goto loc_18964;
    if (ax == 0x0007)
        goto loc_18964;
    if (ax != 0x0000)
        goto loc_1896c;
loc_18964:
    push(ax);
    ax = 0x0025;
    sub_1aecd();
    ax = pop();
loc_1896c:
    si += ax;
    ax = 0;
    al = memory(ds, si);
    memory16(ds, 0x0b26) = ax;
loc_18975:
    if (memory16(ds, 0x0b36) != 0x0000)
        goto loc_1897f;
    goto loc_18a8f;
loc_1897f:
    memory16(ds, 0x0b26) = memory16(ds, 0x0b26) + 0x000d;
    goto loc_18a8f;
loc_18987:
    ax = memory16(ds, 0x0b20);
    cl = 0;
    dx = 0;
    if (!(memory(ds, 0xb884) & 0x08))
        goto loc_1899c;
    dx = 0xfffe;
    goto loc_189a7;
loc_1899c:
    if (!(memory(ds, 0xb884) & 0x04))
        goto loc_189a7;
    dx = 0x0002;
loc_189a7:
    memory16(ds, 0x0b24) = dx;
    ax += dx;
    memory16(ds, 0x7961) = dx;
    memory16(ds, 0x795f) = ax;
    bx = memory16(ds, 0x0b1e);
    memory16(ds, 0x795d) = bx;
    sub_17dfb();
    goto loc_18424;
loc_189c2:
    memory16(ds, 0x7e10) = 0x0001;
    if (memory16(ds, 0x7e12) == 0x0000)
        goto loc_189de;
    if (!(memory16(ds, 0x6610) & 0x00ff))
        goto loc_189de;
    if (memory16(ds, 0x0b00) != 0x0001)
        goto loc_189f9;
loc_189de:
    if (ch & 0x01)
        goto loc_189e6;
    goto loc_1882b;
loc_189e6:
    if (memory16(ds, 0x8bec) == 0x0002)
        goto loc_189f0;
    goto loc_1882b;
loc_189f0:
    memory16(ds, 0x7e0a) = 0x0001;
    goto loc_186c1;
loc_189f9:
    sub_18a9a();
    goto loc_1882b;
loc_189ff:
    memory16(ds, 0x7e14) = 0x0001;
    if ((short)memory16(ds, 0x0b38) >= (short)0x0001)
        goto loc_189de;
    ax = memory16(ds, 0x6612);
    if (ax)
        goto loc_18a16;
    goto loc_1882b;
loc_18a16:
    if (memory(ds, 0x9804) == 0x01)
        goto loc_18a21;
    memory16(ds, 0x6612) = memory16(ds, 0x6612) - 1;
loc_18a21:
    memory16(ds, 0x0b38) = 0x0001;
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x0b3a) = ax;
    memory(ds, 0x0b3f) = 0x00;
    ax = memory16(ds, 0x0b20);
    ax += 0x0005;
    memory16(ds, 0x0b3c) = ax;
    memory(ds, 0x0b3e) = 0x00;
    memory16(ds, 0x0b4a) = 0x0000;
    memory16(ds, 0x0b50) = 0x0000;
    memory16(ds, 0x0b52) = 0x0000;
    memory16(ds, 0x0b40) = 0x0100;
    memory16(ds, 0x0b4e) = 0x7e36;
    if (!(memory(ds, 0xb884) & 0x02))
        goto loc_18a75;
    memory16(ds, 0x0b36) = 0x0001;
    memory16(ds, 0x0b52) = 0xfe00;
    goto loc_1882b;
loc_18a75:
    if (memory(ds, 0xb884) & 0x01)
        goto loc_18a80;
    goto loc_1882b;
loc_18a80:
    memory16(ds, 0x0b36) = 0x0000;
    memory16(ds, 0x0b52) = 0x0200;
    goto loc_1882b;
loc_18a8f:
    ax = memory16(ds, 0x0b20);
    ax -= memory16(ds, 0x7dfe);
    memory16(ds, 0x6c43) = ax;
    return;
    //   gap of 105 bytes
loc_18b03:
    memory16(ds, 0x7e08) = 0x0000;
    memory16(ds, 0x7e0a) = 0x0000;
    memory16(ds, 0x7e0c) = 0x0000;
    memory16(ds, 0x7e0e) = 0x0000;
    memory16(ds, 0x7e10) = 0x0000;
    memory16(ds, 0x7e14) = 0x0000;
    memory16(ds, 0x7e06) = 0x0000;
    dx = memory16(ds, 0x0b24);
    dx += 0x0040;
    if ((short)dx <= (short)0x0400)
        goto loc_18b40;
    dx = 0x0400;
loc_18b40:
    if (!(memory(ds, 0xb884) & 0x08))
        goto loc_18b5e;
    dx += 0xff40;
    if ((short)dx >= (short)0xfc00)
        goto loc_18b79;
    dx = 0xfc00;
    goto loc_18b79;
loc_18b5e:
    if (!(memory(ds, 0xb884) & 0x04))
        goto loc_18b79;
    dx += 0x0080;
    if ((short)dx <= (short)0x0400)
        goto loc_18b79;
    dx = 0x0400;
loc_18b79:
    memory16(ds, 0x0b24) = dx;
    memory16(ds, 0x7961) = dx;
    if (dx & 0x8000)
        goto loc_18b8d;
    ch = 0;
    goto loc_18b8f;
loc_18b8d:
    ch = 0xff;
loc_18b8f:
    ax = memory16(ds, 0x0b20);
    cl = memory(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    memory16(ds, 0x795f) = ax;
    dx = memory16(ds, 0x0b1e);
    memory16(ds, 0x795d) = dx;
    memory(ds, 0x796b) = 0x01;
    sub_17dfb();
    ch = memory(ds, 0x7963);
    if (!(ch & 0x20))
        goto loc_18bbe;
    goto loc_168a8;
loc_18bbe:
    if (ch & 0x04)
        goto loc_18beb;
    if (!(ch & 0x02))
        goto loc_18c00;
    bp = memory16(cs, 0x0b24);
    if (!(bp & 0x8000))
        goto loc_18beb;
    ax |= 0x0007;
    ax++;
    dx = 0;
    cl = 0;
    memory16(ds, 0x0b24) = 0x0000;
    goto loc_18c00;
loc_18beb:
    ax += 0x000c;
    ax |= 0x0007;
    ax -= 0x0014;
    cl = 0;
    dx = 0;
    cl = 0;
    memory16(ds, 0x0b24) = 0x0000;
loc_18c00:
    memory16(ds, 0x0b20) = ax;
    bp = 0x0000;
    if (!(memory(ds, 0xb884) & 0x02))
        goto loc_18c1d;
    bp = 0xfffc;
    memory16(ds, 0x0b36) = 0x0001;
    goto loc_18c31;
loc_18c1d:
    if (!(memory(ds, 0xb884) & 0x01))
        goto loc_18c31;
    bp = 0x0004;
    memory16(ds, 0x0b36) = 0x0000;
loc_18c31:
    bx = memory16(ds, 0x0b1e);
    bx += bp;
    if (!bp)
        goto loc_18c69;
    if (!(bp & 0x8000))
        goto loc_18c57;
    if ((short)bx >= (short)0x0000)
        goto loc_18c69;
    bx = 0x0000;
    memory(ds, 0x90c2) = 0x01;
    goto loc_18c69;
loc_18c57:
    if ((short)bx < (short)0x00e8)
        goto loc_18c69;
    bx = 0x00e8;
    memory(ds, 0x90c2) = 0x02;
loc_18c69:
    ax = memory16(ds, 0x0b20);
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x7961) = 0xffff;
    memory(ds, 0x796b) = 0x01;
    memory16(ds, 0x795d) = bx;
    dx = bp;
    goto loc_187db;
    //   gap of 791 bytes
loc_18f9a:
    dx = memory16(ds, 0x0b24);
    dx += 0x0080;
    memory16(ds, 0x0b24) = dx;
    if (dx & 0x8000)
        goto loc_18faf;
    ch = 0;
    goto loc_18fb1;
loc_18faf:
    ch = 0xff;
loc_18fb1:
    ax = memory16(ds, 0x0b20);
    cl = memory(ds, 0x0b22);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    if ((short)ax <= (short)0x0110)
        goto loc_18fca;
    memory16(ds, 0x7e18) = 0x0001;
    return;
loc_18fca:
    memory16(ds, 0x0b20) = ax;
    memory(ds, 0x0b22) = cl;
    al = memory(ds, 0x8b98);
    al = ~al;
    memory(ds, 0x8b98) = al;
    al &= 0x01;
    ax += 0x001c;
    memory16(ds, 0x0b26) = ax;
    ax = memory16(ds, 0x7e1c);
    ax += memory16(ds, 0x0b1e);
    memory16(ds, 0x0b1e) = ax;
}
void sub_18a9a()
{
    ax = memory16(ds, 0x6610);
    if (!ax)
        goto loc_18ae9;
    if (memory(ds, 0x9804) == 0x01)
        goto loc_18ab2;
    memory16(ds, 0x6610) = memory16(ds, 0x6610) - 1;
loc_18ab2:
    ax = 0x000d;
    sub_1aecd();
    memory16(ds, 0x0b00) = 0x0001;
    ax = memory16(ds, 0x0b20);
    ax += 0x0007;
    memory16(ds, 0x0b04) = ax;
    if (memory16(ds, 0x0b36) != 0x0000)
        goto loc_18aea;
    memory16(ds, 0x0b1a) = 0x0008;
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x0b02) = ax;
    memory16(ds, 0x0b0a) = 0x001f;
    memory16(ds, 0x7e12) = 0x0000;
loc_18ae9:
    return;
loc_18aea:
    memory16(ds, 0x0b1a) = 0xfff8;
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x0b02) = ax;
    memory16(ds, 0x0b0a) = 0x001e;
    memory16(ds, 0x7e12) = 0x0000;
}
void sub_18c83()
{
    goto loc_18c83;
loc_18a9a:
    ax = memory16(ds, 0x6610);
    if (!ax)
        goto loc_18ae9;
    if (memory(ds, 0x9804) == 0x01)
        goto loc_18ab2;
    memory16(ds, 0x6610) = memory16(ds, 0x6610) - 1;
loc_18ab2:
    ax = 0x000d;
    sub_1aecd();
    memory16(ds, 0x0b00) = 0x0001;
    ax = memory16(ds, 0x0b20);
    ax += 0x0007;
    memory16(ds, 0x0b04) = ax;
    if (memory16(ds, 0x0b36) != 0x0000)
        goto loc_18aea;
    memory16(ds, 0x0b1a) = 0x0008;
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x0b02) = ax;
    memory16(ds, 0x0b0a) = 0x001f;
    memory16(ds, 0x7e12) = 0x0000;
loc_18ae9:
    return;
loc_18aea:
    memory16(ds, 0x0b1a) = 0xfff8;
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x0b02) = ax;
    memory16(ds, 0x0b0a) = 0x001e;
    memory16(ds, 0x7e12) = 0x0000;
    return;
    //   gap of 384 bytes
loc_18c83:
    if (memory(ds, 0xb884) & 0x10)
        goto loc_18c95;
    memory16(ds, 0x7e12) = 0x0001;
    return;
loc_18c95:
    memory16(ds, 0x7e10) = 0x0001;
    if (memory16(ds, 0x7e12) == 0x0000)
        return;
    if (!(memory16(ds, 0x6610) & 0x00ff))
        return;
    if (memory16(ds, 0x0b00) == 0x0001)
        return;
    goto loc_18a9a;
}
void sub_18cbe()
{
    if (memory16(ds, 0x0b00) == 0x0001)
        goto loc_18cc9;
    return;
loc_18cc9:
    dx = 0x0004;
    ax = memory16(ds, 0x0b1a);
    if (ax & 0x8000)
        goto loc_18cd9;
    dx = 0x0014;
loc_18cd9:
    ax += memory16(ds, 0x0b02);
    dx += ax;
    if ((short)dx < (short)0x0003)
        goto loc_18d21;
    if ((short)dx > (short)0x00fc)
        goto loc_18d21;
    memory16(ds, 0x795d) = dx;
    cx = memory16(ds, 0x0b04);
    memory16(ds, 0x795f) = cx;
    memory16(ds, 0x795f) = memory16(ds, 0x795f) + 0x0004;
    sub_18014();
    push(ax);
    sub_181c6();
    ax = pop();
    ch = memory(ds, 0x7963);
    if (ch & 0x02)
        goto loc_18d21;
    if (ch & 0x40)
        goto loc_18d21;
    memory16(ds, 0x0b02) = ax;
    return;
loc_18d21:
    memory16(ds, 0x0b00) = 0x0000;
}
void sub_18d28()
{
    memory16(ds, 0x7e1e) = 0x0000;
    if ((short)memory16(ds, 0x0b38) >= (short)0x0001)
        goto loc_18d39;
    return;
loc_18d39:
    if ((short)memory16(ds, 0x0b38) <= (short)0x0001)
        goto loc_18d3e;
    goto loc_18f57;
loc_18d3e:
    si = 0x0b38;
    sub_1718e();
    if (!flags.carry)
        goto loc_18d49;
    goto loc_18f3a;
loc_18d49:
    dx = memory16(ds, 0x0b40);
    dx += 0x0080;
    if ((short)dx <= (short)0x0800)
        goto loc_18d5a;
    dx = 0x0800;
loc_18d5a:
    memory16(ds, 0x0b40) = dx;
    memory16(ds, 0x7961) = dx;
    if (dx & 0x8000)
        goto loc_18d6b;
    ch = 0;
    goto loc_18d6d;
loc_18d6b:
    ch = 0xff;
loc_18d6d:
    ax = memory16(ds, 0x0b3c);
    cl = memory(ds, 0x0b3e);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (al + dh + tl) >= 0x100;
    al += dh + tl;
    ah += ch + flags.carry;
    dx = ax;
    if ((short)dx <= (short)0x0171)
        goto loc_18d85;
    goto loc_18f91;
loc_18d85:
    if ((short)dx >= (short)0x0000)
        goto loc_18d8d;
    goto loc_18f91;
loc_18d8d:
    memory16(ds, 0x795f) = dx;
    ax = memory16(ds, 0x0b3a);
    memory16(ds, 0x795d) = ax;
    memory(ds, 0x796b) = 0x01;
    sub_1802d();
    ch = memory(ds, 0x7963);
    if (!(ch & 0x40))
        goto loc_18dec;
    dx = 0;
    ax = memory16(ds, 0x7964);
    cl = 0;
    ax -= 0x0010;
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x0b3c) = ax;
    memory(ds, 0x0b3e) = 0x00;
    push(ax);
    ax = memory16(ds, 0x7966);
    memory16(ds, 0x7e1e) = ax;
    ax = pop();
    memory(ds, 0x796b) = 0x00;
    sub_1802d();
    ch = memory(ds, 0x7963);
    if (ch & 0x20)
        goto loc_18de4;
    if (ch & 0x06)
        goto loc_18e08;
    memory16(ds, 0x0b40) = 0x0100;
    goto loc_18e5a;
loc_18de4:
    if (!(ch & 0x20))
        goto loc_18dec;
    goto loc_18f3a;
loc_18dec:
    if (ch & 0x04)
        goto loc_18e11;
    if (ch & 0x02)
        goto loc_18e01;
    memory16(ds, 0x0b3c) = dx;
    memory(ds, 0x0b3e) = cl;
    goto loc_18e5a;
loc_18e01:
    ax = memory16(ds, 0x0b40);
    if (!(ax & 0x8000))
        goto loc_18e11;
loc_18e08:
    dx |= 0x0007;
    dx++;
    cl = 0;
    goto loc_18e18;
loc_18e11:
    dx--;
    dx &= 0x0ff8;
    cl = 0;
loc_18e18:
    memory16(ds, 0x0b3c) = dx;
    memory(ds, 0x0b3e) = cl;
    if (!(ch & 0x20))
        goto loc_18e28;
    goto loc_18f3a;
loc_18e28:
    if (!(ch & 0x01))
        goto loc_18e54;
    if (memory16(ds, 0x8bec) != 0x0003)
        goto loc_18e47;
    ax = memory16(ds, 0x0b40);
    if ((short)ax < (short)0x0200)
        goto loc_18e54;
    ax = -ax;
    ax += 0x0060;
    memory16(ds, 0x0b40) = ax;
    goto loc_18e5a;
loc_18e47:
    if (memory16(ds, 0x8bec) != 0x0005)
        goto loc_18e54;
    ax = 0xf781;
    goto loc_18e57;
loc_18e54:
    ax = 0x0100;
loc_18e57:
    memory16(ds, 0x0b40) = ax;
loc_18e5a:
    dx = memory16(ds, 0x0b52);
    bx = 0x0008;
    if (!(ch & 0x01))
        goto loc_18e7e;
    if (memory16(ds, 0x8bec) == 0x0001)
        goto loc_18e92;
    if (memory16(ds, 0x8bec) == 0x0002)
        goto loc_18ead;
    if (memory16(ds, 0x8bec) != 0x0004)
        goto loc_18e7e;
    bx = 0x0010;
loc_18e7e:
    bp = memory16(cs, 0x0b52);
    if (bp & 0x8000)
        goto loc_18e8e;
    dx -= bx;
    if ((short)dx >= 0)
        goto loc_18e94;
    goto loc_18e92;
loc_18e8e:
    dx += bx;
    if ((short)dx < 0)
        goto loc_18e94;
loc_18e92:
    dx = 0;
loc_18e94:
    memory16(ds, 0x0b52) = dx;
    ax = memory16(ds, 0x7e1e);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx += ax;
loc_18ead:
    bx = memory16(ds, 0x0b3a);
    cl = memory(ds, 0x0b3f);
    ax = memory16(ds, 0x0b3c);
    memory16(ds, 0x795f) = ax;
    memory16(ds, 0x7961) = 0xffff;
    if (dx & 0x8000)
        goto loc_18eca;
    ch = 0;
    goto loc_18ecc;
loc_18eca:
    ch = 0xff;
loc_18ecc:
    bx = memory16(ds, 0x0b3a);
    cl = memory(ds, 0x0b3f);
    flags.carry = (cl + dl) >= 0x100;
    cl += dl;
    tl = flags.carry;
    flags.carry = (bl + dh + tl) >= 0x100;
    bl += dh + tl;
    bh += ch + flags.carry;
    if ((short)bx < (short)0x00e8)
        goto loc_18eee;
    cl = 0;
    bx = 0x00e8;
    memory16(ds, 0x0b52) = 0x0000;
    goto loc_18efd;
loc_18eee:
    if ((short)bx >= (short)0x0000)
        goto loc_18efd;
    cl = 0;
    bx = 0;
    memory16(ds, 0x0b52) = 0x0000;
loc_18efd:
    memory16(ds, 0x795d) = bx;
    memory(ds, 0x796b) = 0x01;
    sub_1802d();
    ch = memory(ds, 0x7963);
    if (!(ch & 0x02))
        goto loc_18f2c;
    cl = 0;
    bp = memory16(ds, 0x0b52);
    bp += memory16(ds, 0x7e1e);
    if (!(bp & 0x8000))
        goto loc_18f27;
    bx |= 0x0007;
    bx++;
    goto loc_18f2c;
loc_18f27:
    bx--;
    bx &= 0x00f8;
loc_18f2c:
    memory16(ds, 0x0b3a) = bx;
    memory(ds, 0x0b3f) = cl;
    if (ch & 0x20)
        goto loc_18f3a;
    return;
loc_18f3a:
    memory16(ds, 0x0b38) = 0x0002;
    memory16(ds, 0x0b50) = 0x0000;
    memory16(ds, 0x0b4e) = 0x7eb2;
    memory16(ds, 0x0b3c) = memory16(ds, 0x0b3c) - 0x0005;
    memory16(ds, 0x0b4a) = 0x0000;
loc_18f57:
    si = 0x0b38;
    memory16(ds, 0x0b4a) = memory16(ds, 0x0b4a) + 1;
    if ((char)memory(ds, 0x0b4a) <= (char)0x01)
        goto loc_18f8c;
    if ((char)memory(ds, 0x0b4a) > (char)0x04)
        goto loc_18f8c;
    dx = memory16(ds, 0x0b3a);
    dx -= 0x0004;
    if ((short)dx >= 0)
        goto loc_18f77;
    dx = 0;
loc_18f77:
    tl = dh;
    dh = dl;
    dl = tl;
    bx = memory16(ds, 0x0b3c);
    bx -= 0x0004;
    dl = 0x20;
    ah = 0x1c;
    sub_16407();
    if (!flags.carry)
        goto loc_18f8c;
    sub_168a8();
loc_18f8c:
    sub_1718e();
    if (!flags.carry)
        return;
loc_18f91:
    memory16(ds, 0x0b38) = 0x0000;
}
void sub_19214()
{
    bx = memory16(ds, 0x8bf6);
    di = 0x563c;
    cx = 0x000a;
    dx = memory16(ds, 0x8bf0);
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
    memory16(ds, 0x8bf8) = bx;
    ax &= 0x0003;
    memory16(ds, 0x8bfa) = ax;
    if (!ax)
        goto loc_19257;
    dx = 0x0004;
    dx -= ax;
    push(cx);
    sub_1926d();
    cx = pop();
    goto loc_1925c;
loc_19257:
    push(cx);
    sub_192ae();
    cx = pop();
loc_1925c:
    if (--cx)
        goto loc_19257;
    dx = memory16(ds, 0x8bfa);
    if (!dx)
        return;
    ax = 0x0000;
    sub_1926d();
}
void sub_1926d()
{
    push(di);
    push(dx);
    ax <<= 1;
    ax <<= 1;
    cx = 0x0008;
loc_19276:
    push(cx);
    push(ax);
    ax = 0;
    al = memory(ds, bx);
    bx++;
    ax <<= 1;
    si = 0x8c14;
    si += ax;
    ax = pop();
    si = memory16(ds, si);
    si += ax;
    bp = di;
    push(dx);
loc_1928c:
    cx = 0x0004;
    rep_movsb<MemData, MemData, DirForward>();
    di += 0x001c;
    dx--;
    if (dx != 0)
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
void sub_192ae()
{
    cx = 0x0008;
loc_192b1:
    bp = cx;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    ax <<= 1;
    si = 0x8c14;
    si += ax;
    si = memory16(ds, si);
    dx = 0x0004;
loc_192c4:
    cx = 0x0004;
    rep_movsb<MemData, MemData, DirForward>();
    di += 0x001c;
    dx--;
    if (dx != 0)
        goto loc_192c4;
    di = (di + 0xff84) & 0xffff;
    cx = bp;
    if (--cx)
        goto loc_192b1;
    di += 0x0060;
}
void sub_192da()
{
    di = 0x563c;
    si = 0x565c;
    cx = 0x0270;
    rep_movsw<MemData, MemData, DirForward>();
    ax = memory16(ds, 0x8bfa);
    dx = 0x0001;
    bx = memory16(ds, 0x8bf8);
    bx += 0x0050;
    di = 0x5b1c;
    sub_1926d();
    memory16(ds, 0x8bfa) = memory16(ds, 0x8bfa) + 0x0001;
    memory16(ds, 0x8bfa) = memory16(ds, 0x8bfa) & 0x0003;
    if (memory16(ds, 0x8bfa) != 0)
        return;
    memory16(ds, 0x8bf8) = memory16(ds, 0x8bf8) + 0x0008;
}
void sub_1930a()
{
    si = 0x5b1a;
    di = 0x5b3a;
    flags.direction = true;
    cx = 0x0270;
    rep_movsw<MemData, MemData, DirBackward>();
    flags.direction = false;
    bx = memory16(ds, 0x8bf8);
    memory16(ds, 0x8bfa) = memory16(ds, 0x8bfa) - 1;
    memory16(ds, 0x8bfa) = memory16(ds, 0x8bfa) & 0x0003;
    if (memory16(ds, 0x8bfa) != 0x0003)
        goto loc_19332;
    bx -= 0x0008;
    memory16(ds, 0x8bf8) = bx;
loc_19332:
    di = 0x563c;
    ax = memory16(ds, 0x8bfa);
    dx = 0x0001;
    sub_1926d();
}
void sub_1933f()
{
    ax = 0x3c74;
    di = 0x8c14;
    dx = 0x0010;
    cx = 0x0100;
loc_1934b:
    stosw<MemData, DirForward>();
    ax += dx;
    if (--cx)
        goto loc_1934b;
}
void sub_19351()
{
    memory16(ds, 0x0b00) = 0x0000;
    memory16(ds, 0x0b38) = 0x0000;
    push(ax);
    ax = memory16(ds, 0x0b1e);
    memory16(ds, 0x8c00) = ax;
    ax = memory16(ds, 0x0b20);
    memory16(ds, 0x8c02) = ax;
    ax = memory16(ds, 0x0b24);
    memory16(ds, 0x8c08) = ax;
    al = memory(ds, 0x0b22);
    memory(ds, 0x8c12) = al;
    ax = memory16(ds, 0x7e02);
    memory16(ds, 0x8c0a) = ax;
    ax = memory16(ds, 0x7e04);
    memory16(ds, 0x8c0c) = ax;
    ax = memory16(ds, 0x0b36);
    memory16(ds, 0x8c0e) = ax;
    ax = memory16(ds, 0x7e00);
    memory16(ds, 0x8c10) = ax;
    ax = pop();
    memory16(ds, 0x8c04) = ax;
    memory16(ds, 0x8c06) = dx;
    si = 0x4c74;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    ax = 0;
    ax += memory16(ds, si);
    si++;
    si++;
    tl = ah;
    ah = al;
    al = tl;
    ax += 0x3374;
    memory16(ds, 0x8bf6) = ax;
    memory16(ds, 0x8bf2) = 0x0000;
    ax = memory16(ds, si);
    si++;
    si++;
    tl = ah;
    ah = al;
    al = tl;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memory16(ds, 0x8bf4) = ax;
    ax = memory16(ds, si);
    si++;
    si++;
    tl = ah;
    ah = al;
    al = tl;
    ax += 0x4c74;
    memory16(ds, 0x8bfe) = ax;
    ax = memory16(ds, si);
    si++;
    si++;
    tl = ah;
    ah = al;
    al = tl;
    ax += 0x4c74;
    memory16(ds, 0x8bfc) = ax;
    memory16(ds, 0x8bf0) = dx;
    sub_19577();
}
void sub_19420()
{
    si = 0x8fe4;
    ax = memory16(ds, 0x8bec);
    ax--;
    ax <<= 1;
    si += ax;
    si = memory16(ds, si);
    ax = memory16(ds, si);
    memory16(ds, 0x0b1e) = ax;
    ax = memory16(ds, si + 2);
    memory16(ds, 0x0b20) = ax;
    ax = memory16(ds, si + 4);
    dx = memory16(ds, si + 6);
    cx = memory16(ds, si + 8);
    memory16(ds, 0x0b36) = cx;
    sub_19351();
    sub_19214();
    sub_19577();
    sub_17047();
    sub_15fe4();
    memory(ds, 0x5b3e) = 0x01;
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
}
void sub_19462()
{
    ax = memory16(ds, 0x8c00);
    memory16(ds, 0x0b1e) = ax;
    ax = memory16(ds, 0x8c02);
    memory16(ds, 0x0b20) = ax;
    ax = memory16(ds, 0x8c08);
    memory16(ds, 0x0b24) = ax;
    al = memory(ds, 0x8c12);
    memory(ds, 0x0b22) = al;
    ax = memory16(ds, 0x8c0a);
    memory16(ds, 0x7e02) = ax;
    ax = memory16(ds, 0x8c0c);
    memory16(ds, 0x7e04) = ax;
    ax = memory16(ds, 0x8c0e);
    memory16(ds, 0x0b36) = ax;
    ax = memory16(ds, 0x8c10);
    memory16(ds, 0x7e00) = ax;
    ax = memory16(ds, 0x8c04);
    dx = memory16(ds, 0x8c06);
    sub_19351();
    sub_19214();
    sub_19577();
    sub_17047();
    memory16(ds, 0x6612) = 0x0006;
    memory16(ds, 0x6610) = 0x0006;
    sub_15fe4();
    memory(ds, 0x5b3e) = 0x01;
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
}
void sub_194c4()
{
    push(0x7777);
    al = memory(ds, 0x90c2);
    if (al)
        goto loc_194cc;
    assert(pop() == 0x7777);
    return;
loc_194cc:
    si = memory16(ds, 0x8bfe);
loc_194d0:
    al = memory(ds, si);
    if (!al)
        goto loc_19552;
    al &= 0x03;
    if (al != memory(ds, 0x90c2))
        goto loc_194f6;
    ax = memory16(ds, 0x8bf0);
    ax &= 0xfff8;
    ax += memory16(ds, 0x0b20);
    ax += 0x0014;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if (al == memory(ds, si + 1))
        goto loc_194fb;
loc_194f6:
    si += 0x0004;
    goto loc_194d0;
loc_194fb:
    al = memory(ds, si);
    ah = al;
    ah &= 0x90;
    if (ah != 0x90)
        goto loc_1950a;
    goto loc_19650;
loc_1950a:
    if (!(al & 0x40))
        goto loc_19514;
    memory16(ds, 0x762d) = 0x0001;
loc_19514:
    if (!(al & 0x20))
        goto loc_19521;
    memory16(ds, 0x7e00) = 0x0001;
    goto loc_19527;
loc_19521:
    memory16(ds, 0x7e00) = 0x0000;
loc_19527:
    cx = 0;
    al = memory(ds, si + 2);
    dx = 0;
    dl = memory(ds, si + 3);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    cx = memory16(ds, 0x0b20);
    cx += 0x0014;
    cx &= 0xfff8;
    dx -= cx;
    cx = memory16(ds, 0x8bf0);
    cx &= 0x0007;
    dx &= 0xfff8;
    dx |= cx;
    sub_19553();
loc_19552:
    assert(pop() == 0x7777);
    return;
    //   gap of 253 bytes
loc_19650:
    callIndirect(cs, memory16(ds, 0x003c));
    ax = memory16(ds, 0x8bec);
    if (ax != 0x0004)
        goto loc_19687;
    if (memory16(ds, 0x95c4) == 0x0001)
        goto loc_19673;
    if (memory16(ds, 0x8bee) == 0x0001)
        goto loc_19673;
    ax = 0x0001;
    sub_1a257();
    goto loc_19f12;
loc_19673:
    memory16(ds, 0x8bec) = memory16(ds, 0x8bec) + 1;
    if (memory16(ds, 0x8bec) != 0x0005)
        goto loc_19684;
    memory16(ds, 0x95c4) = 0x0001;
loc_19684:
    goto loc_1c3b9;
loc_19687:
    if (memory16(ds, 0x8bec) != 0x0005)
        goto loc_196a7;
    if (memory16(ds, 0x8bee) != 0x0001)
        goto loc_19698;
    goto loc_19f37;
loc_19698:
    memory16(ds, 0x95c4) = 0x0001;
    ax = 0x0001;
    sub_1a257();
    goto loc_19f12;
loc_196a7:
    memory16(ds, 0x8bec) = memory16(ds, 0x8bec) + 1;
    goto loc_1c3b9;
    //   gap of 69 bytes
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2017 bytes
loc_19f12:
    callIndirect(cs, memory16(ds, 0x003a));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0002;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    sub_19ee5();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    goto loc_1c359;
loc_19f37:
    callIndirect(cs, memory16(ds, 0x003a));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0006;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0002;
    sub_1a257();
    sub_16d69();
    sub_1a5e3();
    sub_16cd7();
    goto loc_1c359;
    //   gap of 9210 bytes
loc_1c359:
    sp = memory16(ds, 0xc0df);
    callIndirect(cs, memory16(ds, 0x000a));
    sub_1a592();
    callIndirect(cs, memory16(ds, 0x003a));
    memory16(ds, 0xbdf2) = 0x0003;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
    callIndirect(cs, memory16(ds, 0x0028));
loc_1c378:
    sync();
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
loc_1c382:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395:
    sub_16b9b();
loc_1c398:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab:
    sub_16cd7();
    goto loc_1c382;
    //   gap of 9 bytes
loc_1c3b9:
    sp = memory16(ds, 0xc0df);
    memory16(ds, 0x6610) = 0x0006;
    memory16(ds, 0x6612) = 0x0006;
    memory16(ds, 0x7e00) = 0x0000;
    memory16(ds, 0x762d) = 0x0000;
    memory16(ds, 0x762f) = 0x0000;
    sub_1a54a();
    push(cs);
    ds = pop();
    sub_1a56b();
    callIndirect(cs, memory16(ds, 0x0004));
    callIndirect(cs, memory16(ds, 0x0006));
    sub_1a45c();
    sub_1c4e2();
    callIndirect(cs, memory16(ds, 0x0042));
    callIndirect(cs, memory16(ds, 0x0026));
    callIndirect(cs, memory16(ds, 0x003c));
    callIndirect(cs, memory16(ds, 0x0048));
    ax = 0x0004;
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = memory16(ds, 0x8bec);
    ax--;
    ax += ax;
    si = 0x2f69;
    si += ax;
    ax = memory16(ds, si);
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    ax = 0x0000;
    sub_1a257();
    sub_1a5f0();
    callIndirect(cs, memory16(ds, 0x0026));
    sub_19420();
    memory16(ds, 0x973c) = 0x3245;
    memory16(ds, 0x973e) = 0x5432;
loc_1c439:
    memory16(ds, 0x7e16) = 0x0000;
    memory16(ds, 0x7e18) = 0x0000;
loc_1c445:
    sub_16b3b();
    if (memory16(ds, 0x7e18) != 0x0001)
        goto loc_1c467;
    memory16(ds, 0x762f) = 0x0000;
    sub_1618f();
    sub_19462();
    if (memory16(ds, 0x6614) != 0x0000)
        goto loc_1c465;
    goto loc_19f12;
loc_1c465:
    goto loc_1c439;
loc_1c467:
    sub_19bac();
    sub_15f40();
    memory(ds, 0x5b3e) = 0x00;
    sub_169e3();
    sub_168e4();
    sub_17205();
    sub_18351();
    sub_18cbe();
    sub_18d28();
    sub_1705d();
    callIndirect(cs, memory16(ds, 0x001e));
    callIndirect(cs, memory16(ds, 0x0024));
    callIndirect(cs, memory16(ds, 0x003e));
    callIndirect(cs, memory16(ds, 0x001c));
    sub_19af6();
    callIndirect(cs, memory16(ds, 0x0038));
    sub_194c4();
    if (memory(ds, 0xb888) != 0x10)
        goto loc_1c4b3;
    sub_19f8a();
    if (!flags.carry)
        goto loc_1c4b3;
    goto loc_1c359;
loc_1c4b3:
    if (memory(ds, 0xb888) != 0x01)
        goto loc_1c445;
    goto loc_196f3;
}
void sub_19553()
{
    bx = memory16(ds, 0x0b1e);
    if (bx)
        goto loc_19568;
    memory16(ds, 0x0b1e) = 0x00e8;
    callIndirect(cs, memory16(ds, 0x0020));
    return;
loc_19568:
    memory16(ds, 0x0b1e) = 0x0000;
    callIndirect(cs, memory16(ds, 0x0022));
}
void sub_19577()
{
    memory16(ds, 0x9173) = 0x0000;
    si = 0x54fa;
    memory16(ds, 0x9175) = si;
loc_19584:
    al = memory(ds, si);
    if (al & 0x80)
        return;
    memory(ds, si) = 0x00;
    si += 0x0008;
    goto loc_19584;
}
void sub_19593()
{
    push(ds);
    push(es);
    push(di);
    push(ax);
    push(cs);
    ds = pop();
    if ((short)memory16(ds, 0x9173) < (short)0x0028)
        goto loc_195a5;
    ax = pop();
    di = pop();
    es = pop();
    ds = pop();
    return;
loc_195a5:
    dx = 0;
    dl = al;
    dx -= 0x00f8;
    dx += dx;
    dx += dx;
    ax = 0;
    sub_19b40();
    al = memory(ds, 0x973f);
    cbw();
    al &= 0x03;
    dx += ax;
    ax = 0;
    si = 0x54fa;
loc_195c3:
    al = memory(ds, si);
    if (al & 0x80)
        goto loc_195e0;
    if (al)
        goto loc_195e5;
    memory(ds, si) = 0x01;
    si++;
    memory(ds, si) = dl;
    si++;
    memory16(ds, si) = bx;
    si++;
    si++;
    memory16(ds, si) = di;
    si++;
    si++;
    memory16(ds, si) = bp;
    memory16(ds, 0x9173) = memory16(ds, 0x9173) + 1;
loc_195e0:
    ax = pop();
    di = pop();
    es = pop();
    ds = pop();
    return;
loc_195e5:
    si += 0x0008;
    goto loc_195c3;
}
void sub_195ea()
{
    if (memory16(ds, 0x9173) != 0x0000)
        goto loc_195f2;
    return;
loc_195f2:
    si = 0x54fa;
loc_195f5:
    al = memory(ds, si);
    if (!al)
        goto loc_19617;
    if (al & 0x80)
        return;
    ax = memory16(ds, si + 2);
    ax += 0x0020;
    if ((short)ax < (short)0x5a7c)
        goto loc_19614;
    memory(ds, si) = 0x00;
    memory16(ds, 0x9173) = memory16(ds, 0x9173) - 1;
    si += 0x0008;
    goto loc_195f5;
loc_19614:
    memory16(ds, si + 2) = ax;
loc_19617:
    si += 0x0008;
    goto loc_195f5;
}
void sub_1961d()
{
    if (memory16(ds, 0x9173) != 0x0000)
        goto loc_19625;
    return;
loc_19625:
    si = 0x54fa;
loc_19628:
    al = memory(ds, si);
    if (!al)
        goto loc_1964a;
    if (al & 0x80)
        return;
    ax = memory16(ds, si + 2);
    ax -= 0x0020;
    if ((short)ax >= (short)0x573c)
        goto loc_19647;
    memory(ds, si) = 0x00;
    memory16(ds, 0x9173) = memory16(ds, 0x9173) - 1;
    si += 0x0008;
    goto loc_19628;
loc_19647:
    memory16(ds, si + 2) = ax;
loc_1964a:
    si += 0x0008;
    goto loc_19628;
}
void sub_196dd()
{
    callIndirect(cs, memory16(ds, 0x0000));
    sub_1933f();
    callIndirect(cs, memory16(ds, 0x0010));
    callIndirect(cs, memory16(ds, 0x0018));
    sub_1adcb();
    sub_1bc92();
}
void sub_199c8()
{
    memory(ds, 0x95ad) = 0x01;
    callIndirect(cs, memory16(ds, 0x0026));
    ax = 0x0706;
    memory16(ds, 0x69f0) = ax;
    memory16(ds, 0x69f2) = ax;
    sub_16e39();
    ax = 0x0008;
    si = 0x9461;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0108;
    si = 0x9481;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0208;
    si = 0x94a1;
    callIndirect(cs, memory16(ds, 0x0046));
    bx = 0x95b5;
    sub_19c43();
    push(cs);
    ds = pop();
    if (memory16(ds, 0x95c4) != 0x0001)
        goto loc_19a10;
    bx = 0x95bf;
    sub_19c43();
loc_19a10:
    callIndirect(cs, memory16(ds, 0x001c));
    ax = 0x0008;
    si = 0x9461;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0108;
    si = 0x9481;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0208;
    si = 0x94a1;
    callIndirect(cs, memory16(ds, 0x0046));
    bx = 0x95b5;
    sub_19c43();
    if (memory16(ds, 0x95c4) != 0x0001)
        goto loc_19a45;
    bx = 0x95bf;
    sub_19c43();
loc_19a45:
    memory(ds, 0x97da) = 0x01;
loc_19a4b:
    sync();
    sub_19bdc();
    if (!(al & 0x10))
        goto loc_19a55;
    goto loc_19ae0;
loc_19a55:
    if (al == memory(ds, 0x95c3))
        goto loc_19a4b;
    memory(ds, 0x95c3) = al;
    if (!(al & 0x08))
        goto loc_19a9e;
    dx = memory16(ds, 0x69f0);
    dh--;
    dh--;
    dh--;
    if (memory16(ds, 0x95c4) == 0x0001)
        goto loc_19a84;
    if (dh != 0x04)
        goto loc_19a95;
    dh = 0x10;
    memory(ds, 0x95ad) = 0x04;
    sub_16e66();
    goto loc_19a4b;
loc_19a84:
    if (dh != 0x04)
        goto loc_19a95;
    dh = 0x13;
    memory(ds, 0x95ad) = 0x05;
    sub_16e66();
    goto loc_19a4b;
loc_19a95:
    memory(ds, 0x95ad) = memory(ds, 0x95ad) - 1;
    sub_16e66();
    goto loc_19a4b;
loc_19a9e:
    if (!(al & 0x04))
        goto loc_19a4b;
    dx = memory16(ds, 0x69f0);
    dh++;
    dh++;
    dh++;
    if (memory16(ds, 0x95c4) == 0x0001)
        goto loc_19ac4;
    if (dh != 0x13)
        goto loc_19ad6;
    dh = 0x07;
    memory(ds, 0x95ad) = 0x01;
    sub_16e66();
    goto loc_19a4b;
loc_19ac4:
    if (dh != 0x16)
        goto loc_19ad6;
    dh = 0x07;
    memory(ds, 0x95ad) = 0x01;
    sub_16e66();
    goto loc_19a4b;
loc_19ad6:
    memory(ds, 0x95ad) = memory(ds, 0x95ad) + 1;
    sub_16e66();
    goto loc_19a4b;
loc_19ae0:
    al = memory(ds, 0x95ad);
    cbw();
    ax--;
    si = 0x95af;
    si += ax;
    al = memory(ds, si);
    cbw();
    memory16(ds, 0x8bec) = ax;
    memory16(ds, 0x8bee) = ax;
}
void sub_19af6()
{
    return;
    push(dx);
    push(ax);
    ax = memory16(ds, 0x96f4);
loc_19afb:
    push(ax);
    push(es);
    dx = 0x0040;
    es = dx;
    dx = memoryBiosGet16(es, 0x0063);
    es = pop();
    dl += 0x06;
loc_19b0b:
    in(al, dx);
    al &= 0x08;
    if (al != 0)
        goto loc_19b0b;
loc_19b10:
    in(al, dx);
    al &= 0x08;
    if (al == 0)
        goto loc_19b10;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_19afb;
    ax = pop();
    dx = pop();
}
void sub_19b1c()
{
    push(dx);
    push(ax);
    push(ax);
    push(es);
    dx = 0x0040;
    es = dx;
    dx = memoryBiosGet16(es, 0x0063);
    es = pop();
    dl += 0x06;
loc_19b2e:
    in(al, dx);
    al &= 0x08;
    if (al != 0)
        goto loc_19b2e;
loc_19b33:
    in(al, dx);
    al &= 0x08;
    if (al == 0)
        goto loc_19b33;
    ax = pop();
    ax = pop();
    dx = pop();
}
void sub_19b40()
{
    push(ax);
    push(dx);
    ax = memory16(ds, 0x973c);
    dx = memory16(ds, 0x973e);
    tx = dx;
    dx = ax;
    ax = tx;
    dx = rol(dx, 0x0001);
    dx = rol(dx, 0x0001);
    dx = rol(dx, 0x0001);
    dx -= 0x0007;
    dx ^= ax;
    memory16(ds, 0x973c) = ax;
    memory16(ds, 0x973e) = dx;
    dx = pop();
    ax = pop();
}
void sub_19bac()
{
    al = 0x11;
    if (memory(ds, 0x97ab) == 0x01)
        goto loc_19bce;
    if (memory(ds, 0xb888) == al)
        goto loc_19bbc;
    return;
loc_19bbc:
    sync();
    if (memory(ds, 0xb888) == al)
        goto loc_19bbc;
loc_19bc2:
    sync();
    if (memory(ds, 0xb888) != al)
        goto loc_19bc2;
    memory(ds, 0x97ab) = 0x01;
    return;
loc_19bce:
    if (al == memory(ds, 0xb888))
        return;
    memory(ds, 0x97ab) = 0x00;
}
void sub_19bdc()
{
    sub_1c4ca();
    if (!(al & 0x10))
        goto loc_19bf0;
    if (memory(ds, 0x97da) == 0x01)
        goto loc_19bf5;
    memory(ds, 0x97da) = 0x01;
    return;
loc_19bf0:
    memory(ds, 0x97da) = 0x00;
loc_19bf5:
    al &= 0xef;
}
void sub_19c05()
{
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(si);
    push(ax);
    if (memory(ds, 0x9804) == 0x01)
        goto loc_19c3f;
    si = memory16(ds, 0x97f8);
    al = memory(ds, 0xb888);
    if (al & 0x80)
        goto loc_19c39;
    if (!al)
        goto loc_19c39;
    ah = memory(ds, si);
    if (al != ah)
        goto loc_19c33;
    si++;
    memory16(ds, 0x97f8) = si;
    if (memory(ds, si) != 0xff)
        goto loc_19c39;
    memory(ds, 0x9804) = 0x01;
loc_19c33:
    memory16(ds, 0x97f8) = 0x97fa;
loc_19c39:
    memory(ds, 0xb888) = 0x00;
loc_19c3f:
    ax = pop();
    si = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_19c43()
{
loc_19c43:
    si = memory16(ds, bx);
    if (!si)
        return;
    al = memory(ds, si);
    si++;
    ah = memory(ds, si);
    si++;
    push(bx);
    callIndirect(cs, memory16(ds, 0x000c));
    bx = pop();
    bx++;
    bx++;
    goto loc_19c43;
}
void sub_19e18()
{
    memory(cs, 0xbda2) = 0xc3;
    flags.carry = false;
    return; // gabo skip joystick

    memory16(ds, 0x9a16) = 0x0000;
    callIndirect(cs, memory16(ds, 0x0026));
loc_19e22:
    sub_19ebb();
    bx = 0x99b3;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
    bx = 0x99b3;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
    memory(ds, 0xb888) = 0x00;
    ax = memory16(ds, 0x9a16);
    ax <<= 1;
    di = 0x9a0c;
    di += ax;
    di = memory16(ds, di);
loc_19e4b:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx != 0)
        goto loc_19e6a;
    ah = memory(ds, 0xb888);
    if (ah & 0x80)
        goto loc_19e4b;
    if (!ah)
        goto loc_19e4b;
    if (ah != 0x01)
        goto loc_19e6c;
    memory(cs, 0xbda2) = 0xc3;
    flags.carry = false;
    return;
loc_19e6a:
    flags.carry = true;
    return;
loc_19e6c:
    if (ah != 0x1c)
        goto loc_19e7d;
    sub_19ed0();
    si = 0x9a06;
    sub_19eb5();
    goto loc_19e9b;
loc_19e7d:
    si = 0x99e5;
loc_19e80:
    lodsb<MemData, DirForward>();
    if (al == 0xff)
        goto loc_19eb2;
    if (al != ah)
        goto loc_19e80;
    sub_19ed0();
    si--;
    si -= 0x001a;
    al = memory(ds, si);
    memory(ds, 0x9a00) = al;
    si = 0x9a00;
    sub_19eb5();
loc_19e9b:
    memory16(ds, 0x9a16) = memory16(ds, 0x9a16) + 1;
    if (memory16(ds, 0x9a16) != 0x0005)
        goto loc_19eaf;
    memory16(ds, 0x9a16) = 0x0000;
    goto loc_19e22;
loc_19eaf:
    goto loc_19e22;
loc_19eb2:
    goto loc_19e22;
}
void sub_19eb5()
{
    cx = 0x0006;
    rep_movsb<MemData, MemData, DirForward>();
}
void sub_19ebb()
{
    ax = memory16(ds, 0x9a16);
    ax <<= 1;
    si = 0x99a9;
    si += ax;
    si = memory16(ds, si);
    di = 0x9958;
    cx = 0x0005;
    rep_movsb<MemData, MemData, DirForward>();
}
void sub_19ed0()
{
    bx = 0xb874;
    cx = memory16(ds, 0x9a16);
    bx += cx;
    memory(ds, bx) = ah;
}
void sub_19ee5()
{
    callIndirect(cs, memory16(ds, 0x003a));
    callIndirect(cs, memory16(ds, 0x0026));
    sub_16b3b();
    ax = 0x0c0f;
    si = 0x9adc;
    callIndirect(cs, memory16(ds, 0x000c));
    callIndirect(cs, memory16(ds, 0x001c));
    cx = 0x01e0;
loc_19f01:
    push(cx);
    sub_19b1c();
    sub_19bdc();
    if (al & 0x10)
        goto loc_19f10;
    cx = pop();
    if (--cx)
        goto loc_19f01;
    return;
loc_19f10:
    cx = pop();
}
void sub_19f8a()
{
    push(ds);
    push(es);
    ax = 0x0c05;
    si = 0x9b5f;
    callIndirect(cs, memory16(ds, 0x000e));
    ax = 0x0d0e;
    si = 0x9b7d;
    callIndirect(cs, memory16(ds, 0x000e));
    callIndirect(cs, memory16(ds, 0x0038));
loc_19fa4:
    al = memory(cs, 0xb888);
    if (al != 0x15)
        goto loc_19fb0;
    flags.carry = true;
    goto loc_19fb5;
loc_19fb0:
    if (al != 0x31)
        goto loc_19fa4;
    flags.carry = false;
loc_19fb5:
    es = pop();
    ds = pop();
}
void sub_1a102()
{
    di = 0x9ca8;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    ax <<= 1;
    di += ax;
    di = memory16(ds, di);
}
void sub_1a111()
{
    di = 0x9cfa;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    ax <<= 1;
    di += ax;
    di = memory16(ds, di);
}
void sub_1a120()
{
}
void sub_1a121()
{
    sub_1a102();
    memory16(ds, di) = 0x0001;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 2) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 4) = ax;
}
void sub_1a137()
{
    sub_1a102();
    memory16(ds, di) = 0x0000;
}
void sub_1a13f()
{
    sub_1a102();
    memory16(ds, di) = 0x0002;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 18) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 20) = ax;
}
void sub_1a155()
{
    sub_1a102();
    ax = memory16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memory16(ds, di + 22) = ax;
    ax = 0;
    memory16(ds, di + 24) = ax;
}
void sub_1a168()
{
    al = memory(ds, bx);
    bx++;
    if (al)
        goto loc_1a174;
    callIndirect(cs, memory16(ds, 0x0030));
    return;
loc_1a174:
    ah = 0;
    ax--;
    ax <<= 1;
    si = 0x2314;
    si = memory16(ds, si);
    si += 0x2314;
    si += ax;
    si = memory16(ds, si);
    si += 0x2314;
    si += 0x0008;
    al = memory(ds, bx);
    bx++;
    ah = memory(ds, bx);
    bx++;
    callIndirect(cs, memory16(ds, 0x002c));
    ax = 0;
    al = memory(ds, bx);
    bx++;
    si += ax;
    al = memory(ds, bx);
    bx++;
    cl = 0x05;
    ax <<= cl;
    si += ax;
    cl = memory(ds, bx);
    bx++;
    ch = memory(ds, bx);
    bx++;
    push(ax);
    push(bx);
    push(cx);
    push(di);
    push(si);
    callIndirect(cs, memory16(ds, 0x002e));
    si = pop();
    di = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1a1bc()
{
    al = memory(ds, bx);
    bx++;
    ah = memory(ds, bx);
    bx++;
    si = bx;
    push(ax);
    push(bx);
    push(si);
    callIndirect(cs, memory16(ds, 0x0032));
    si = pop();
    bx = pop();
    ax = pop();
loc_1a1ce:
    al = memory(ds, bx);
    bx++;
    if (al != 0xff)
        goto loc_1a1ce;
}
void sub_1a1d7()
{
    al = memory(ds, bx);
    cbw();
    bx++;
    push(bx);
    memory16(ds, 0xbdf2) = ax;
    sub_1aecd();
    bx = pop();
}
void sub_1a1e4()
{
    bx++;
}
void sub_1a1e6()
{
    sub_1a102();
    memory16(ds, di) = 0x0003;
    ax = memory16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memory16(ds, di + 6) = ax;
    ax = 0;
    memory16(ds, di + 8) = ax;
}
void sub_1a1fd()
{
    sub_1a111();
    memory16(ds, di) = 0x0001;
    ax = 0;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 2) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 4) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 6) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 8) = ax;
    al = memory(ds, bx);
    bx++;
    memory16(ds, di + 10) = ax;
    memory16(ds, di + 12) = 0x0000;
    ax = memory16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memory16(ds, di + 14) = ax;
}
void sub_1a234()
{
    sub_1a111();
    memory16(ds, di) = 0x0000;
}
void sub_1a23e()
{
    ax = memory16(ds, bx);
    bx++;
    bx++;
    ax += 0x2314;
    memory16(ds, 0x9e3c) = bx;
    bx = ax;
}
void sub_1a24c()
{
    bx = memory16(ds, 0x9e3c);
}
void sub_1a257()
{
    push(0x7777);
    memory16(ds, 0x9e51) = sp;
    memory16(ds, 0x8bf0) = 0x0000;
    memory16(ds, 0x9e55) = ax;
    memory16(ds, 0x9e53) = 0x0000;
    sub_1c4ca();
    if (!(al & 0x10))
        goto loc_1a277;
    memory16(ds, 0x9e53) = 0x0001;
loc_1a277:
    sub_16b3b();
    callIndirect(cs, memory16(ds, 0x001c));
    sub_16b3b();
    ax = memory16(ds, 0x9e55);
    ax <<= 1;
    bx = 0x2316;
    bx += ax;
    bx = memory16(ds, bx);
    bx += 0x2314;
    di = 0x9bd6;
    cx = 0x0008;
loc_1a297:
    memory16(ds, di) = 0x0000;
    di += 0x001a;
    if (--cx)
        goto loc_1a297;
    di = 0x9cb8;
    cx = 0x0004;
loc_1a2a6:
    memory16(ds, di) = 0x0000;
    di += 0x0010;
    if (--cx)
        goto loc_1a2a6;
loc_1a2af:
    ax = 0;
    al = memory(ds, bx);
    bx++;
    if (al == 0x00)
        goto loc_1a2c3;
    ax <<= 1;
    si = 0x9bb8;
    si += ax;
    callIndirect(cs, memory16(ds, si));
    goto loc_1a2af;
loc_1a2c3:
    assert(pop() == 0x7777);
}
void sub_1a2c4()
{
    push(0x7777);
    push(bx);
    sub_1c4ca();
    bx = pop();
    dx = memory16(ds, 0x9e55);
    if (dx != 0x0000)
        goto loc_1a2d3;
    assert(pop() == 0x7777);
    return;
loc_1a2d3:
    if (dx != 0x0001)
        goto loc_1a2f1;
    if (!(al & 0x10))
        goto loc_1a2e8;
    if (memory16(ds, 0x9e53) == 0x0001)
        goto loc_1a2ee;
    sp = memory16(ds, 0x9e51);
    assert(pop() == 0x7777);
    return;
loc_1a2e8:
    memory16(ds, 0x9e53) = 0x0000;
loc_1a2ee:
    al &= 0xef;
    assert(pop() == 0x7777);
    return;
loc_1a2f1:
    al &= 0xef;
    assert(pop() == 0x7777);
}
void sub_1a2f6()
{
    sub_16b3b();
    memory16(ds, 0x9ef4) = 0x0000;
    cx = 0;
    cl = memory(ds, bx);
    bx++;
loc_1a304:
    push(cx);
    memory16(ds, 0x9ef4) = memory16(ds, 0x9ef4) + 1;
    if (memory16(ds, 0x9ef4) != 0x0007)
        goto loc_1a316;
    memory16(ds, 0x9ef4) = 0x0000;
loc_1a316:
    sub_1a389();
    sub_1a437();
    sub_1a2c4();
    if (!(al & 0x10))
        goto loc_1a32a;
    if (memory16(ds, 0x9ef4) != 0x0000)
        goto loc_1a33d;
loc_1a32a:
    callIndirect(cs, memory16(ds, 0x0034));
    callIndirect(cs, memory16(ds, 0x0044));
    sub_19b1c();
    callIndirect(cs, memory16(ds, 0x001c));
    callIndirect(cs, memory16(ds, 0x0038));
loc_1a33d:
    cx = pop();
    if (--cx)
        goto loc_1a304;
}
void sub_1a389()
{
    si = 0x9bd6;
loc_1a38c:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        return;
    if (!ax)
        goto loc_1a3c9;
    if (ax == 0x0001)
        goto loc_1a3c9;
    if (ax != 0x0002)
        goto loc_1a3c2;
    ax = memory16(ds, si + 18);
    memory16(ds, si + 2) = memory16(ds, si + 2) + ax;
    if ((short)memory16(ds, si + 2) < (short)0x00e8)
        goto loc_1a3af;
    memory16(ds, si) = 0x0000;
loc_1a3af:
    if ((short)memory16(ds, si + 2) >= (short)0x0000)
        goto loc_1a3b9;
    memory16(ds, si) = 0x0000;
loc_1a3b9:
    ax = memory16(ds, si + 20);
    memory16(ds, si + 4) = memory16(ds, si + 4) + ax;
    goto loc_1a3c9;
loc_1a3c2:
    push(bx);
    push(si);
    sub_1a3cf();
    si = pop();
    bx = pop();
loc_1a3c9:
    si += 0x001a;
    goto loc_1a38c;
}
void sub_1a3cf()
{
    push(bx);
    bx = memory16(ds, si + 6);
    al = memory(ds, bx);
    if (al != 0x00)
        goto loc_1a3df;
    bx++;
    bx = memory16(ds, bx);
    memory16(ds, si + 6) = bx;
loc_1a3df:
    bx++;
    al = memory(ds, bx);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    if (al != 0x07)
        goto loc_1a3f0;
    al++;
loc_1a3f0:
    cbw();
    memory16(ds, si + 2) = memory16(ds, si + 2) + ax;
    if ((short)memory16(ds, si + 2) < (short)0x00e8)
        goto loc_1a3ff;
    memory16(ds, si) = 0x0000;
loc_1a3ff:
    if ((short)memory16(ds, si + 2) >= (short)0x0000)
        goto loc_1a409;
    memory16(ds, si) = 0x0000;
loc_1a409:
    al = memory(ds, bx);
    al &= 0x0f;
    if (!(al & 0x08))
        goto loc_1a413;
    al |= 0xf0;
loc_1a413:
    if (al != 0x07)
        goto loc_1a419;
    al++;
loc_1a419:
    cbw();
    memory16(ds, si + 4) = memory16(ds, si + 4) + ax;
    bx--;
    al = memory(ds, bx);
    cbw();
    memory16(ds, si + 8) = memory16(ds, si + 8) + 1;
    if (ax == memory16(ds, si + 8))
        goto loc_1a42b;
    if (ax >= memory16(ds, si + 8))
        goto loc_1a435;
loc_1a42b:
    memory16(ds, si + 8) = 0x0000;
    bx++;
    bx++;
    memory16(ds, si + 6) = bx;
loc_1a435:
    bx = pop();
}
void sub_1a437()
{
    si = 0x9bd6;
loc_1a43a:
    ax = memory16(ds, si);
    if (ax & 0x8000)
        return;
    if (!ax)
        goto loc_1a449;
    push(bx);
    push(si);
    sub_1718e();
    si = pop();
    bx = pop();
loc_1a449:
    si += 0x001a;
    goto loc_1a43a;
}
void sub_1a44f()
{
    ax = memory16(ds, 0x0062);
    cx = 0x0000;
    dx = 0x00c1;
    sub_1a65b();
}
void sub_1a45c()
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
void sub_1a54a()
{
    si = 0x006b;
    ax = memory16(ds, 0x8bec);
    ax--;
    ax += 0x0031;
loc_1a554:
    ah = memory(ds, si);
    if (ah == 0xff)
        return;
    if ((char)ah < (char)0x31)
        goto loc_1a567;
    if ((char)ah > (char)0x35)
        goto loc_1a567;
    memory(ds, si) = al;
loc_1a567:
    si++;
    goto loc_1a554;
}
void sub_1a56b()
{
    callIndirect(cs, memory16(ds, 0x0026));
    ax = 0x0a0c;
    si = 0x94c1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0b0c;
    si = 0x94e1;
    callIndirect(cs, memory16(ds, 0x0046));
    ax = 0x0c0c;
    si = 0x9501;
    callIndirect(cs, memory16(ds, 0x0046));
    callIndirect(cs, memory16(ds, 0x001c));
}
void sub_1a592()
{
    push(cs);
    ds = pop();
    di = 0x66f6;
    cx = 0x0006;
    al = 0x0a;
    rep_stosb<MemData, DirForward>();
    memory16(ds, 0x6610) = 0x0006;
    di = 0x66fd;
    cx = 0x0006;
    al = 0x0b;
    rep_stosb<MemData, DirForward>();
    memory16(ds, 0x6612) = 0x0006;
    di = 0x6704;
    cx = 0x0006;
    al = 0x0c;
    rep_stosb<MemData, DirForward>();
    memory16(ds, 0x6614) = 0x0006;
    sub_1a5f0();
    callIndirect(cs, memory16(ds, 0x001a));
    memory16(ds, 0x8bec) = 0x0001;
    memory16(ds, 0x7e16) = 0x0000;
    memory16(ds, 0x7e18) = 0x0000;
    memory16(ds, 0x7e00) = 0x0000;
    push(cs);
    ds = pop();
    di = 0x6616;
    cx = 0x0006;
    al = 0;
    rep_stosb<MemData, DirForward>();
}
void sub_1a5e3()
{
    push(cs);
    ds = pop();
    di = 0x6616;
    cx = 0x0006;
    al = 0;
    rep_stosb<MemData, DirForward>();
}
void sub_1a5f0()
{
    ax = 0;
    memory16(ds, 0x0b00) = ax;
    memory16(ds, 0x0b38) = ax;
    ax++;
    memory16(ds, 0x0b1c) = ax;
    ax--;
    di = 0x0b56;
loc_1a600:
    dx = memory16(ds, di);
    if (dx & 0x8000)
        goto loc_1a60c;
    stosw<MemData, DirForward>();
    di += 0x0032;
    goto loc_1a600;
loc_1a60c:
    di = 0x0c28;
loc_1a60f:
    dx = memory16(ds, di);
    if (dx & 0x8000)
        return;
    stosw<MemData, DirForward>();
    di += 0x0032;
    goto loc_1a60f;
}
void sub_1a65b()
{
    memory16(ds, 0xa255) = ax;
    memory16(ds, 0xa257) = cx;
    sub_1a67b();
    push(ds);
    bx = memory16(ds, 0xa259);
    ax = memory16(ds, 0xa255);
    dx = memory16(ds, 0xa257);
    ds = ax;
    sub_1a693();
    ds = pop();
    sub_1a69d();
}
void sub_1a67b()
{
    goto loc_1a67b;
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3914 bytes
loc_1a67b:
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
    memory16(ds, 0xa259) = ax;
    ds = pop();
    return;
    //   gap of 104 bytes
loc_1a6fb:
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
    memory(ds, 0xb888) = 0x00;
loc_1a719:
    al = memory(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    goto loc_196f3;
}
void sub_1a693()
{
    goto loc_1a693;
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3938 bytes
loc_1a693:
    ah = 0x3f;
    cx = 0xffff;
    interrupt(0x21);
    if (flags.carry)
        goto loc_1a6fb;
    return;
    //   gap of 94 bytes
loc_1a6fb:
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
    memory(ds, 0xb888) = 0x00;
loc_1a719:
    al = memory(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    goto loc_196f3;
}
void sub_1a69d()
{
    goto loc_1a69d;
loc_196f3:
    flags.interrupts = false;
    sub_1ae03();
    sub_1bcb7();
    flags.interrupts = true;
    al = memory(ds, 0x006a);
    ah = 0;
    interrupt(0x10);
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1970f;
    sub_1adb0();
    goto loc_1972d;
loc_1970f:
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
loc_1972d:
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 3948 bytes
loc_1a69d:
    ah = 0x3e;
    bx = memory16(ds, 0xa259);
    interrupt(0x21);
    if (flags.carry)
        goto loc_1a6fb;
    return;
    //   gap of 83 bytes
loc_1a6fb:
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
    memory(ds, 0xb888) = 0x00;
loc_1a719:
    al = memory(ds, 0xb888);
    if (al == 0x00)
        goto loc_1a719;
    goto loc_196f3;
}
void sub_1ad6e()
{
    ah = 0;
    ax <<= 1;
    bx = ax;
    ax <<= 1;
    ax += bx;
    bx = 0xa64d;
    bx += ax;
    bx = memory16(ds, bx);
    memory16(ds, 0xa854) = bx;
    memory(ds, 0xa852) = 0x01;
    memory(ds, 0xa84e) = 0x00;
    memory16(ds, 0xa850) = 0x0001;
    memory16(ds, 0xa856) = 0x0000;
    memory16(ds, 0xa858) = 0x0000;
    memory(ds, 0xa85a) = 0x00;
    memory16(ds, 0xa85c) = 0x0000;
    memory(ds, 0xa85e) = 0xff;
}
void sub_1adb0()
{
    in(al, 0x61);
    al &= 0xfd;
    out(0x61, al);
}
void sub_1adcb()
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
    memory16(ds, 0xb88e) = es;
    memory16(cs, 0xaa7b) = es;
    memory16(ds, 0xb890) = bx;
    memory16(cs, 0xaa79) = bx;
    ah = 0x25;
    al = 0x08;
    push(cs);
    ds = pop();
    dx = 0xaa28;
    interrupt(0x21);
    ax = 0x4000;
    out(0x40, al);
    al = ah;
    out(0x40, al);
    es = pop();
    ds = pop();
}
void sub_1ae03()
{
    push(ds);
    push(ax);
    ax = 0x0000;
    out(0x40, al);
    al = ah;
    out(0x40, al);
    ax = 0x1040;
    ds = ax;
    dx = memory16(ds, 0xb890);
    ds = memory16(ds, 0xb88e);
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ax = pop();
    ds = pop();
}
void sub_1ae81()
{
    al = memory(ds, 0xaa26);
loc_1ae84:
    sync();
    if (al == memory(ds, 0xaa26))
        goto loc_1ae84;
    al = memory(ds, 0xaa26);
loc_1ae8d:
    flags.carry = (memory(ds, 0xaa7d) + 0x01) >= 0x100;
    memory(ds, 0xaa7d) = memory(ds, 0xaa7d) + 0x01;
    tl = flags.carry;
    flags.carry = (memory(ds, 0xaa7e) + 0x00 + tl) >= 0x100;
    memory(ds, 0xaa7e) = memory(ds, 0xaa7e) + tl;
    tl = flags.carry;
    flags.carry = (memory(ds, 0xaa7f) + 0x00 + tl) >= 0x100;
    memory(ds, 0xaa7f) = memory(ds, 0xaa7f) + tl;
    memory(ds, 0xaa80) = memory(ds, 0xaa80) + flags.carry;
    if (al == memory(ds, 0xaa26))
        goto loc_1ae8d;
    ax = memory16(ds, 0xaa7d);
    if ((short)ax < (short)0x0b00)
        goto loc_1aeb6;
    memory16(ds, 0x96f4) = 0x0003;
    return;
loc_1aeb6:
    if ((short)ax < (short)0x0700)
        goto loc_1aec2;
    memory16(ds, 0x96f4) = 0x0002;
    return;
loc_1aec2:
    memory16(ds, 0x96f4) = 0x0001;
    callIndirect(cs, memory16(ds, 0x004a));
}
void sub_1aecd()
{
    if ((short)ax < (short)0x000b)
        goto loc_1aed5;
    goto loc_1bb82;
loc_1aed5:
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1aee0;
    sub_1ad6e();
    return;
loc_1aee0:
    bx = ax;
    sub_1b95d();
    return;
    //   gap of 3228 bytes
loc_1bb82:
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
    if (memory16(ds, 0xab2b) == 0x0001)
        goto loc_1bb9e;
    goto loc_1bc4a;
loc_1bb9e:
    if (memory(ds, 0xa85e) != 0xff)
        goto loc_1bba8;
    goto loc_1bc40;
loc_1bba8:
    ax += ax;
    ax += ax;
    si = 0xb181;
    si += ax;
    ax = memory16(ds, 0xab27);
    ax--;
    if ((short)ax >= 0)
        goto loc_1bbba;
    ax = 0x0005;
loc_1bbba:
    memory16(ds, 0xab27) = ax;
    ax = memory16(ds, si + 2);
    push(ax);
    si = memory16(ds, si);
    push(si);
    ax = memory16(ds, 0xab27);
    memory16(ds, 0xb3a7) = ax;
    si++;
    si++;
    memory16(ds, 0xb3a9) = si;
    memory16(ds, 0xb3ab) = ds;
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
    ax = memory16(ds, 0xab27);
    memory16(ds, 0xb3a7) = ax;
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
    ax = memory16(ds, 0xab27);
    memory16(ds, 0xb3a7) = ax;
    si = pop();
    ax = pop();
    cbw();
    memory16(ds, 0xb3a9) = ax;
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
loc_1bc40:
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
loc_1bc4a:
    if (memory(ds, 0xa85e) != 0xff)
        goto loc_1bc53;
    goto loc_1bc40;
loc_1bc53:
    dx = memory16(ds, 0xab29);
    if (!dx)
        goto loc_1bc65;
    if (ax == 0x001a)
        goto loc_1bc40;
    if (ax == 0x001b)
        goto loc_1bc40;
loc_1bc65:
    ax += ax;
    si = 0xb32d;
    si += ax;
    si = memory16(ds, si);
    memory16(ds, 0xab29) = si;
    goto loc_1bc40;
}
void sub_1b95d()
{
    ax = cs;
    ds = ax;
    memory16(ds, 0xb55b) = 0x0001;
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
    memory16(ds, 0xb3a7) = 0x0001;
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
    memory16(ds, di) = 0x00ff;
    ax = memory16(ds, bx);
    memory16(ds, di + 2) = ax;
    ax = 0;
    memory16(ds, di + 16) = ax;
    memory16(ds, di + 12) = ax;
    memory16(ds, di + 18) = ax;
    push(bx);
    sub_1bb3f();
    bx = pop();
    bx++;
    bx++;
    di = 0xb37d;
    memory16(ds, di) = 0x00ff;
    ax = memory16(ds, bx);
    memory16(ds, di + 2) = ax;
    ax = 0;
    memory16(ds, di + 16) = ax;
    ax = 0x0001;
    memory16(ds, di + 12) = ax;
    memory16(ds, di + 18) = ax;
    push(bx);
    sub_1bb3f();
    bx = pop();
    bx++;
    bx++;
    di = 0xb391;
    memory16(ds, di) = 0x00ff;
    ax = memory16(ds, bx);
    memory16(ds, di + 2) = ax;
    ax = 0;
    memory16(ds, di + 16) = ax;
    ax = 0x0002;
    memory16(ds, di + 12) = ax;
    memory16(ds, di + 18) = ax;
    sub_1bb3f();
    memory16(ds, 0xb55b) = 0x0000;
}
void sub_1bb3f()
{
    goto loc_1bb3f;
loc_1ba58:
    al = memory(ds, si);
    if (!(al & 0x80))
        goto loc_1bac7;
    if (al != 0xff)
        goto loc_1ba72;
    memory16(ds, di + 10) = memory16(ds, di + 10) - 1;
    if (memory16(ds, di + 10) != 0)
        goto loc_1ba6a;
    goto loc_1bb3f;
loc_1ba6a:
    si = memory16(ds, di + 4);
    memory16(ds, di + 6) = si;
    goto loc_1ba58;
loc_1ba72:
    al &= 0x7f;
    al--;
    al += al;
    ah = 0;
    bx = ax;
    bx += 0xb3b3;
    bx = memory16(ds, bx);
    al = memory(ds, bx);
    if (!al)
        goto loc_1ba90;
    al = memory(ds, bx + 1);
    ah = 0;
    memory16(ds, di + 18) = ax;
loc_1ba90:
    bx += 0x0002;
    memory16(ds, 0xb3a9) = bx;
    ax = cs;
    memory16(ds, 0xb3ab) = ax;
    ax = memory16(ds, di + 18);
    memory16(ds, 0xb3a7) = ax;
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
loc_1bac7:
    memory16(ds, di + 8) = 0x0000;
    memory16(ds, di + 6) = si;
    al -= 0x20;
    cbw();
    ax += memory16(ds, di + 16);
    memory16(ds, 0xb3a9) = ax;
    ax = memory16(ds, di + 14);
    memory16(ds, 0xb3a7) = ax;
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
    ax = memory16(ds, 0xb3a9);
    ax -= memory16(ds, di + 16);
    if (ax == 0x001d)
        goto loc_1bb3e;
    ax = memory16(ds, di + 18);
    memory16(ds, di + 14) = ax;
    memory16(ds, 0xb3a7) = ax;
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
loc_1bb3e:
    return;
loc_1bb3f:
    memory16(ds, di + 10) = 0x0001;
    si = memory16(ds, di + 2);
loc_1bb47:
    al = memory(ds, si);
    if (al != 0xff)
        goto loc_1bb52;
    memory16(ds, di) = 0x0000;
    return;
loc_1bb52:
    if (!(al & 0x80))
        goto loc_1bb6c;
    if (al != 0xc0)
        goto loc_1bb64;
    si++;
    al = memory(ds, si);
    cbw();
    memory16(ds, di + 16) = ax;
    si++;
    goto loc_1bb47;
loc_1bb64:
    al &= 0x7f;
    memory(ds, di + 10) = al;
    si++;
    goto loc_1bb47;
loc_1bb6c:
    si++;
    memory16(ds, di + 2) = si;
    ah = 0;
    ax += ax;
    bx = ax;
    bx += 0xa5e1;
    si = memory16(ds, bx);
    memory16(ds, di + 4) = si;
    goto loc_1ba58;
}
void sub_1bc92()
{
    push(ds);
    push(es);
    ah = 0x35;
    al = 0x09;
    interrupt(0x21);
    ax = 0x1040;
    ds = ax;
    memory16(ds, 0xb88a) = es;
    memory16(ds, 0xb88c) = bx;
    ah = 0x25;
    al = 0x09;
    dx = cs;
    ds = dx;
    dx = 0xb8cd;
    interrupt(0x21);
    es = pop();
    ds = pop();
}
void sub_1bcb7()
{
    push(ds);
    ax = 0x1040;
    ds = ax;
    dx = memory16(ds, 0xb88c);
    ds = memory16(ds, 0xb88a);
    ah = 0x25;
    al = 0x09;
    interrupt(0x21);
    ds = pop();
}
void sub_1bf7c()
{
    dx = 0x0201;
    ax = 0;
    cx = 0;
    in(al, dx);
    ax &= 0x0030;
    if (ax == 0x0030)
        goto loc_1bf8f;
    cx = 0xffff;
loc_1bf8f:
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
void sub_1bfa0()
{
    return; // gabo
    push(dx);
    flags.interrupts = false;
    al = 0x00;
    out(0x43, al);
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    tl = al;
    al = ah;
    ah = tl;
    push(ax);
    cx = 0x04ff;
    out(dx, al);
loc_1bfb9:
    in(al, dx);
    if (--cx && bl & al)
        goto loc_1bfb9;
    cx = pop();
    if (cx != 0x0000)
        goto loc_1bfc9;
    cx = 0;
    goto loc_1bff7;
loc_1bfc9:
    al = 0x00;
    out(0x43, al);
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    tl = al;
    al = ah;
    ah = tl;
    if (cx >= ax)
        goto loc_1bfe9;
    push(dx);
    dx = 0xffff;
    dx -= ax;
    cx += dx;
    dx = pop();
    goto loc_1bfeb;
loc_1bfe9:
    cx -= ax;
loc_1bfeb:
    cx &= 0x1ff0;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
loc_1bff7:
    flags.interrupts = true;
    dx = 0x0201;
    push(cx);
    push(ax);
    cx = 0x04ff;
loc_1c000:
    in(al, dx);
    if (--cx && al & 0x0f)
        goto loc_1c000;
    ax = pop();
    cx = pop();
    dx = pop();
}
void sub_1c0a8()
{
    callIndirect(cs, memory16(ds, 0x0026));
    bx = 0xbc80;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
    bx = 0xbc80;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
loc_1c0c0:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx != 0)
        goto loc_1c0c0;
loc_1c0c8:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx == 0)
        goto loc_1c0c8;
    memory16(ds, 0xbc98) = cx;
    memory16(ds, 0xbc9a) = dx;
    callIndirect(cs, memory16(ds, 0x0026));
    bx = 0xbc88;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
    bx = 0xbc88;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
loc_1c0f0:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx != 0)
        goto loc_1c0f0;
loc_1c0f8:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx == 0)
        goto loc_1c0f8;
    memory16(ds, 0xbc9c) = cx;
    memory16(ds, 0xbc9e) = dx;
    callIndirect(cs, memory16(ds, 0x0026));
    bx = 0xbc90;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
    bx = 0xbc90;
    sub_19c43();
    callIndirect(cs, memory16(ds, 0x001c));
loc_1c120:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx != 0)
        goto loc_1c120;
loc_1c128:
    sub_1bf7c();
    bx &= 0x0003;
    if (bx == 0)
        goto loc_1c128;
    memory16(ds, 0xbca0) = cx;
    memory16(ds, 0xbca2) = dx;
    ax = memory16(ds, 0xbc9c);
    ax -= memory16(ds, 0xbc98);
    bx = memory16(ds, 0xbc9e);
    bx -= memory16(ds, 0xbc9a);
    dl = 0x06;
    idiv(dl);
    ax &= 0x00ff;
    cbw();
    push(ax);
    ax = bx;
    dl = 0x06;
    idiv(dl);
    al &= 0xff;
    cbw();
    bx = ax;
    ax = pop();
    memory16(ds, 0xbca4) = ax;
    memory16(ds, 0xbca6) = bx;
}
void sub_1c164()
{
    sub_1c0a8();
    sub_1bf7c();
    cx |= dx;
    if (cx)
        goto loc_1c175;
    memory(cs, 0xbda2) = 0xc3;
    return;
loc_1c175:
    ax = memory16(ds, 0xbca0);
    dx = memory16(ds, 0xbca4);
    ax += dx;
    memory16(ds, 0xb87e) = ax;
    ax = memory16(ds, 0xbca0);
    dx = -dx;
    ax += dx;
    memory16(ds, 0xb880) = ax;
    ax = memory16(ds, 0xbca2);
    dx = memory16(ds, 0xbca6);
    ax += dx;
    memory16(ds, 0xb87c) = ax;
    ax = memory16(ds, 0xbca2);
    dx = -dx;
    ax += dx;
    memory16(ds, 0xb87a) = ax;
}
void sub_1c1a2()
{
    if (memory(0x1040, 0xBDA2) == 0xC3)
        return; // gabo
    assert(0);
    ax = 0x1040;
    ds = ax;
    sub_1bf7c();
    bx &= 0x0003;
    if (bx == 0)
        goto loc_1c1b7;
    bx = 0;
    bl |= 0x10;
    goto loc_1c1b9;
loc_1c1b7:
    bx = 0;
loc_1c1b9:
    if (cx < memory16(ds, 0xb87e))
        goto loc_1c1c5;
    bl |= 0x01;
    goto loc_1c1ce;
loc_1c1c5:
    if (cx >= memory16(ds, 0xb880))
        goto loc_1c1ce;
    bl |= 0x02;
loc_1c1ce:
    if (dx >= memory16(ds, 0xb87a))
        goto loc_1c1da;
    bl |= 0x08;
    goto loc_1c1e3;
loc_1c1da:
    if (dx < memory16(ds, 0xb87c))
        goto loc_1c1e3;
    bl |= 0x04;
loc_1c1e3:
    memory(ds, 0xb882) = bl;
    bh = memory(ds, 0xb886);
    bl |= bh;
    memory(ds, 0xb884) = bl;
}
void sub_1c276()
{
    goto loc_1c276;
loc_19731:
    ah = 0x09;
    dx = 0x1040;
    ds = dx;
    dx = 0x92b1;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 11061 bytes
loc_1c276:
    flags.direction = false;
    ah = 0x4a;
    bx = 0x0e00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1c283;
    goto loc_19731;
loc_1c283:
    ax = cs;
    es = ax;
    si = 0x0080;
    di = 0x1040;
    es = di;
    di = 0xbdf6;
    cl = memory(ds, si);
    ch = 0;
    cx++;
    flags.direction = false;
    rep_movsb<MemData, MemData, DirForward>();
    push(es);
    ds = pop();
    si = 0xbdf6;
    cx = 0x0080;
loc_1c2a2:
    al = memory(ds, si);
    si++;
    if (al == 0x2f)
        goto loc_1c2ae;
loc_1c2a9:
    if (--cx)
        goto loc_1c2a2;
    goto loc_1c2e2;
loc_1c2ae:
    al = memory(ds, si);
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
loc_1c2ca:
    memory16(ds, 0x2f67) = 0x2f4f;
    goto loc_1c2e2;
loc_1c2d3:
    memory16(ds, 0x2f67) = 0x2f57;
    goto loc_1c2e2;
    //   gap of 7 bytes
loc_1c2e2:
    //sub_1c4bd(); // gabo: skip cga driver
loc_1c2e5:
    callIndirect(cs, memory16(ds, 0x0002));
    si = 0xbdf6;
    cx = 0x0080;
loc_1c2ef:
    al = memory(ds, si);
    si++;
    if (al == 0x2f)
        goto loc_1c308;
    if (--cx)
        goto loc_1c2ef;
    push(ds);
    ax = 0x1040;
    ds = ax;
    memory16(ds, 0xab2b) = 0x0000;
    ds = pop();
    goto loc_1c31f;
loc_1c308:
    al = memory(ds, si);
    if (al == 0x61)
        goto loc_1c312;
    if (al != 0x41)
        goto loc_1c31f;
loc_1c312:
    ax = 0x1040;
    ds = ax;
    es = ax;
    memory16(ds, 0xab2b) = 0x0001;
loc_1c31f:
    sub_196dd();
//    sub_1ae81(); // gabo skip
    memory(ds, 0xa860) = 0x01;
    sub_1c4e1();
    callIndirect(cs, memory16(ds, 0x002a));
    callIndirect(cs, memory16(ds, 0x0008));
    sub_1a44f();
    callIndirect(cs, memory16(ds, 0x000a));
    callIndirect(cs, memory16(ds, 0x003a));
    sub_1a592();
    sub_19e18();
    if (!flags.carry)
        goto loc_1c34b;
    sub_1c164();
loc_1c34b:
    memory16(ds, 0x95c4) = 0x0000;
    callIndirect(cs, memory16(ds, 0x003c));
    memory16(ds, 0xc0df) = sp;
    sp = memory16(ds, 0xc0df);
    callIndirect(cs, memory16(ds, 0x000a));
    sub_1a592();
    callIndirect(cs, memory16(ds, 0x003a));
    memory16(ds, 0xbdf2) = 0x0003;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
    callIndirect(cs, memory16(ds, 0x0028));
loc_1c378:
    sync();
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c378;
    goto loc_1c398;
loc_1c382:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c395;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c395:
    sub_16b9b();
loc_1c398:
    if (memory(ds, 0xa85e) == 0xff)
        goto loc_1c3ab;
    memory16(ds, 0xbdf2) = 0x0000;
    ax = memory16(ds, 0xbdf2);
    sub_1aecd();
loc_1c3ab:
    sub_16cd7();
    goto loc_1c382;
}
void sub_1c4bd()
{
    ax = cs;
    cx = 0x0000;
    dx = memory16(ds, 0x2f67);
    sub_1a65b();
}
void sub_1c4ca()
{
    sub_1c1a2();
    al = memory(ds, 0xb884);
}
void sub_1c4e1()
{
}
void sub_1c4e2()
{
    ax = memory16(ds, 0x6614);
    ax++;
    if ((short)ax > (short)0x0006)
        return;
    memory16(ds, 0x6614) = ax;
}
