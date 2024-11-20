#include "cicoemu.h"
using namespace CicoContext;
#include <stdio.h>
void sub_2ad33();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    cs = 0x2ac2;
    ds = 0x2ab2;
    es = 0x2ab2;
    ss = 0x2aa2;
    sp = 0x0200;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/popcorn/dos", "POPCORN.EXE", 133808);
    sub_2ad33();
}
void sub_2aca5();
void sub_2acb0();
void sub_2acb7();
void sub_2ad26();
void sub_2ad33();
void sub_2afd0();
void sub_2aff1();
void sub_2b06b();
void sub_2b093();
void sub_2b141();
void sub_2b17e();
void sub_2b1b8();
void sub_2b218();
void sub_2b355();
void sub_2b3ab();
void sub_2b4e8();
void sub_2b531();
void sub_2b5e5();
void sub_2b63d();
void sub_2b72b();
void sub_2b884();
void sub_2b8e5();
void sub_2b94e();
void sub_2bcac();
void sub_2bce5();
void sub_2bcf1();
void sub_2bcfe();
void sub_2be32();
void sub_2bf74();
void sub_2bfd8();
void sub_2c0c7();
void sub_2c0d3();
void sub_2c129();
void sub_2c1a1();
void sub_2c234();
void sub_2c262();
void sub_2c26c();
void sub_2c2f2();
void sub_2c3a5();
void sub_2c493();
void sub_2c86f();
void sub_2ca43();
void sub_2ca70();
void sub_2cad9();
void sub_2cbe1();
void sub_2cc54();
void sub_2ccd9();
void sub_2cd29();
void sub_2cd68();
void sub_2cda7();
void sub_2ce3a();
void sub_2cea1();
void sub_2cec9();
void sub_2cefe();
void sub_2cf36();
void sub_2d09f();
void sub_2d16d();
void sub_2d375();
void sub_2d3d7();
void sub_2d3f7();
void sub_2d447();
void sub_2d4a1();
void sub_2d4eb();
void sub_2d5a5();
void sub_2d65f();
void sub_2d693();
void sub_2d6d4();
void sub_2d715();
void sub_2d756();
void sub_2d7bd();
void sub_2d879();
void sub_2d988();
void sub_2d9c0();
void sub_2d9ca();
void sub_2da0f();
void sub_2da23();
void sub_2da36();
void sub_2da3e();
void sub_2da75();
void sub_2db03();
void sub_2dc8b();
void sub_2dcfd();
void sub_2dd39();
void sub_2dd66();
void sub_2dd7b();
void sub_2ddab();
void sub_2de08();
void sub_2de20();
void sub_2de41();
void sub_2de51();
void sub_2de52();
void sub_2de77();
void sub_2de93();
void sub_2dfa6();
void sub_2e181();
void sub_2e27e();
void sub_2e288();
void sub_2e28f();
void sub_2e2b6();
void sub_2e2c1();
void sub_2e316();
void sub_2e31b();
void sub_2e337();
void sub_2e400();
void sub_2e52d();
void sub_2e5c1();
void sub_2e61a();
void sub_2e70e();
void sub_2e74a();
void sub_2e784();
void sub_2e817();
void sub_2e886();
void sub_2e8cf();
void sub_2e913();
void sub_2e95c();
void sub_2e9b5();
void sub_2ea11();
void sub_2eb40();
void sub_2eb6f();
void sub_2ec8a();
void sub_2ece0();
void sub_2ed12();
void sub_2ed5d();
void sub_2edd1();
void sub_2edf4();
void sub_2ee05();
void sub_2f1c1();
void sub_2f498();
void sub_2f4cf();
void sub_2f4ee();
void sub_2f52d();
void sub_2f54f();
void sub_2f577();
void sub_2f5dc();
void sub_2f69a();
void sub_2f700();
void sub_2f76f();
void sub_2f79a();
void sub_2f7c9();
void sub_2f833();
void sub_2f86b();
void sub_2f8e1();
void sub_2f957();
void sub_2f97d();
void sub_2f9b6();
void sub_2f9db();
void sub_2fa0a();
void sub_2fa24();
void sub_2fa3a();
void sub_2fb78();
void sub_2fb93();
void sub_2fbc7();
void sub_2fbf3();
void sub_2fc11();
void sub_2fc39();
void sub_2fc65();
void sub_2fcb9();
void sub_2fcdc();
void sub_2fcff();
void sub_2fd60();
void sub_2fd91();
void sub_2fdb6();
void sub_2fdd6();
void sub_2ff37();
void sub_2ffad();
void sub_2ffe2();
void sub_30068();
void sub_30096();
void sub_300aa();
void sub_300f6();
void sub_30205();
void sub_302a0();
void sub_304d3();
void sub_30560();
void sub_30617();
void sub_30663();
void sub_30676();
void sub_306fd();
void sub_307a0();
void sub_307d5();
void sub_30856();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    if(seg == 0x2ac2)
    switch (ofs)
    {
        case 0x28cb: sub_2d4eb(); return;
        case 0x2985: sub_2d5a5(); return;
        case 0x2a3f: sub_2d65f(); return;
        case 0x3221: sub_2de41(); return;
        case 0x2a73: sub_2d693(); return;
        case 0x2ab4: sub_2d6d4(); return;
        case 0x2af5: sub_2d715(); return;
        case 0x2b36: sub_2d756(); return;
        case 0x2b9d: sub_2d7bd(); return;
        case 0x2c59: sub_2d879(); return;
        case 0x2d68: sub_2d988(); return;
        default:
            break;
    }
    if(seg == 0x2ac2)
    switch (ofs)
    {
        case 0x2daa: sub_2d9ca(); return;
        case 0x2def: sub_2da0f(); return;
        case 0x3231: sub_2de51(); return;
        case 0x2e03: sub_2da23(); return;
        case 0x2e16: sub_2da36(); return;
        case 0x3119: sub_2dd39(); return;
        case 0x315b: sub_2dd7b(); return;
        case 0x318b: sub_2ddab(); return;
        case 0x2da0: sub_2d9c0(); return;
        case 0x31e8: sub_2de08(); return;
        case 0x3200: sub_2de20(); return;
        case 0x2e55: sub_2da75(); return;
        default:
            break;
    }
    switch (seg*0x10000+ofs)
    {
        case 0x2ac216d2: sub_2c2f2(); return;
        case 0x2ac21785: sub_2c3a5(); return;
        case 0x2ac22def: sub_2da0f(); return;
        case 0x2ac23273: sub_2de93(); return;
        case 0x2ac23386: sub_2dfa6(); return;
        case 0x2ac23561: sub_2e181(); return;
        case 0x2ac2365e: sub_2e27e(); return;
        case 0x2ac2366f: sub_2e28f(); return;
        case 0x2ac23696: sub_2e2b6(); return;
        case 0x2ac236a1: sub_2e2c1(); return;
        case 0x2ac236f6: sub_2e316(); return;
        case 0x2ac23717: sub_2e337(); return;
        case 0x2ac237e0: sub_2e400(); return;
        case 0x2ac2390d: sub_2e52d(); return;
        case 0x2ac239fa: sub_2e61a(); return;
        case 0x2ac23aee: sub_2e70e(); return;
        case 0x2ac23b2a: sub_2e74a(); return;
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_2fa0a()!
// INJECT: Error: cannot inject carry flag in sub_2fa24()!
// INJECT: Error: cannot inject carry flag in sub_2fa24()!
void sub_2aca5()
{
    al = 0xb6;
    out(0x43, al);
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
}
void sub_2acb0()
{
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
}
void sub_2acb7()
{
    push(ds);
    ax = 0x2ac2;
    ds = ax;
    al = memoryAGet(ds, 0x00f4);
    if (al)
        goto loc_2ace7;
    memoryASet(ds, 0x00f5, memoryAGet(ds, 0x00f5) - 1);
    if (memoryAGet(ds, 0x00f5) != 0)
        goto loc_2ace5;
loc_2acca:
    si = memoryAGet16(ds, 0x00f6);
    lodsw<MemAuto, DirAuto>();
    if (!ax)
        goto loc_2ad0a;
    memoryASet16(ds, 0x00f6, si);
    memoryASet(ds, 0x00f5, ah);
    ah = al;
    al = 0x01;
    out(0x42, al);
    al = ah;
    out(0x42, al);
loc_2ace5:
    ds = pop();
    return;
loc_2ace7:
    ah = 0;
    al--;
    memoryASet(ds, 0x00f4, ah);
    if (memoryAGet(cs, 0x0084) == 0x00)
        goto loc_2ace5;
    ax <<= 1;
    ax += 0x00f8;
    si = ax;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(ds, 0x00f6, ax);
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
    goto loc_2acca;
loc_2ad0a:
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    al = 0xff;
    goto loc_2ace5;
}
void sub_2ad26()
{
loc_2ad26:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        return;
    ah = 0;
    interrupt(0x16);
    goto loc_2ad26;
}
void sub_2ad33()
{
    ax = 0x2aa2;
    ss = ax;
    sp = 0x0080;
    ax = 0x1000;
    es = ax;
    di = 0x13a0;
    si = 0x0080;
    cx = 0x0020;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = ax;
    sub_302a0();
    ah = 0x19;
//    interrupt(0x21);
//    memoryASet(ds, 0x141b, al);
    al = 2;
//    if (memoryAGet(ds, 0x13a0) == 0x00)
    goto loc_2adaa;
    ch = 0;
    cl = memoryAGet(ds, 0x13a0);
    cl--;
    if (cl == 0)
        goto loc_2adaa;
    si = 0x13a2;
loc_2ad6c:
    lodsb<MemAuto, DirAuto>();
    if (al != 0x20)
        goto loc_2ad77;
    cl--;
    if (cl == 0)
        goto loc_2adaa;
    goto loc_2ad6c;
loc_2ad77:
    si--;
    di = 0x1428;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = 0x1428;
loc_2ad80:
    if (memoryAGet(ds, si) != 0x2e)
        goto loc_2ad88;
    si++;
    goto loc_2ad80;
loc_2ad88:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2ad93;
    if (al == 0x2e)
        goto loc_2ada7;
    goto loc_2ad88;
loc_2ad93:
    si--;
    memoryASet(ds, si, 0x2e);
    memoryASet(ds, si + 1, 0x50);
    memoryASet(ds, si + 2, 0x50);
    memoryASet(ds, si + 3, 0x43);
    memoryASet(ds, si + 4, 0x00);
loc_2ada7:
    sub_2b4e8();
loc_2adaa:
    memoryASet16(ds, 0x2d47, 0x16d2);
    memoryASet(ds, 0x3f1b, 0x00);
    memoryASet(cs, 0x0084, 0x01);
    sub_2f9b6();
    sub_2c0d3();
    ax = 0x0005;
    interrupt(0x10);
    sub_2afd0();
    sub_2b3ab();
    sub_300f6();
    sub_30205();
    sub_2f69a();
    sub_2f5dc();
    ax = 0x1000;
    es = ax;
    sub_2fcb9();
    memoryASet16(ds, 0x1405, sp);
    memoryASet16(ds, 0x2d45, 0x16d2);
    sub_2aff1();
    ah = 0;
    interrupt(0x33);
loc_2adf1:
    sub_2acb0();
loc_2adf4:
    sub_2ad26();
    sub_2fcdc();
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2ae05;
    sub_2f52d();
loc_2ae05:
    push(es);
    memoryASet16(ds, 0x1413, 0x0050);
    sub_30096();
    es = pop();
    memoryASet(ds, 0x13c4, 0x02);
    memoryASet16(ds, 0x13c5, 0x3f1e);
    ax = 0xffff;
    cx = 0x0003;
    di = 0x0000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2ae26:
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_2ae2f;
    goto loc_2aed4;
loc_2ae2f:
    ah = 0x00;
    interrupt(0x16);
    if (ax != 0x4300)
        goto loc_2ae3e;
    memoryASet(cs, 0x0084, memoryAGet(cs, 0x0084) ^ 0x01);
loc_2ae3e:
    if (ax != 0x4200)
        goto loc_2ae49;
    sub_2fdb6();
    goto loc_2aed4;
loc_2ae49:
    if (ax != 0x4100)
        goto loc_2ae59;
    memoryASet(ds, 0x3f1b, 0x00);
    memoryASet16(ds, 0x3f1c, 0x3f0b);
loc_2ae59:
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2ae63;
    sub_2fd91();
loc_2ae63:
    if (ax != 0x4400)
        goto loc_2ae79;
    sub_2f700();
loc_2ae6b:
    ah = 0x00;
    interrupt(0x16);
    if (ax == 0x4400)
        goto loc_2ae6b;
    sub_2f76f();
    goto loc_2ae26;
loc_2ae79:
    if (ax == 0x3b00)
        goto loc_2aef4;
    if (ax != 0x3d00)
        goto loc_2ae94;
    if (memoryAGet16(ds, 0x2d47) == 0x1654)
        goto loc_2ae94;
    memoryASet16(ds, 0x2d47, 0x1654);
    sub_2f52d();
loc_2ae94:
    if (ax != 0x3e00)
        goto loc_2aeaa;
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2aeaa;
    memoryASet16(ds, 0x2d47, 0x16d2);
    sub_2f52d();
loc_2aeaa:
    if (ax != 0x3f00)
        goto loc_2aeb5;
    sub_2c1a1();
    goto loc_2adf1;
loc_2aeb5:
    if (ax != 0x4000)
        goto loc_2aec0;
    sub_2fa3a();
    goto loc_2adf1;
loc_2aec0:
    if (ax == 0x3c00)
        goto loc_2aee8;
    if (ax != 0x011b)
        goto loc_2aed4;
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x4c00;
    interrupt(0x21);
loc_2aed4:
    bx = memoryAGet16(ds, 0x13c5);
    if (memoryAGet(ds, bx) == 0x00)
        goto loc_2aee8;
    push(es);
    sub_2ffe2();
    es = pop();
    sub_2fcff();
    goto loc_2ae26;
loc_2aee8:
    sub_2aca5();
    sub_2be32();
    sub_2c129();
    goto loc_2af15;
loc_2aef4:
    ax = memoryAGet16(ds, 0x2d47);
    memoryASet16(ds, 0x2d45, ax);
    sub_2aca5();
    sub_2bcfe();
    if (al != 0xff)
        goto loc_2af07;
    goto loc_2adf4;
loc_2af07:
    sub_2b8e5();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2af15;
    sub_2afd0();
loc_2af15:
    si = 0x344f;
    di = 0x13d5;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x13cd, 0x3030);
    memoryASet16(ds, 0x13cf, 0x3030);
    memoryASet16(ds, 0x13d1, 0x3030);
    memoryASet16(ds, 0x13d3, 0x3032);
    memoryASet(ds, 0x3f0a, 0x00);
    al = memoryAGet(ds, 0x3f08);
    memoryASet(ds, 0x3f09, al);
    memoryASet(ds, 0x13c9, 0x05);
    dl = 0x1e;
    sub_2ece0();
    al = ah;
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2af59;
    al = 0;
loc_2af59:
    memoryASet(ds, 0x13cc, al);
    dl = 0xb0;
    mul(dl);
    ax += 0x000c;
    memoryASet16(ds, 0x13ca, ax);
    sub_2b72b();
    goto loc_2afb8;
loc_2af6c:
    sub_2cad9();
loc_2af6f:
    sub_2c493();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_2acb0();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (!flags.carry)
        goto loc_2af96;
    sub_2b355();
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2af87;
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) - 1);
loc_2af87:
    if (memoryAGet(ds, 0x2e78) != 0x01)
        goto loc_2af6f;
    sub_2b093();
    sub_2b94e();
    goto loc_2af6c;
loc_2af96:
    sub_2b141();
    memoryASet16(ds, 0x13ca, memoryAGet16(ds, 0x13ca) + 0x00b0);
    memoryASet(ds, 0x13cc, memoryAGet(ds, 0x13cc) + 1);
    if (memoryAGet(ds, 0x13cc) != 0x32)
        goto loc_2afb8;
    memoryASet(ds, 0x13cc, 0x00);
    memoryASet16(ds, 0x13ca, 0x000c);
    sub_30560();
loc_2afb8:
    sub_2b06b();
    si = memoryAGet16(ds, 0x13ca);
    di = 0x2f10;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x00b0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    goto loc_2af6c;
}
void sub_2afd0()
{
    push(es);
    ah = 0x35;
    al = 0x09;
    interrupt(0x21);
    memoryASet16(ds, 0x2d41, bx);
    memoryASet16(ds, 0x2d43, es);
    es = pop();
    push(ds);
    ax = 0x2ac2;
    ds = ax;
    ah = 0x25;
    al = 0x09;
    dx = 0x03e3;
    interrupt(0x21);
    ds = pop();
}
void sub_2aff1()
{
    push(ds);
    dx = memoryAGet16(ds, 0x2d41);
    ax = memoryAGet16(ds, 0x2d43);
    ds = ax;
    ah = 0x25;
    al = 0x09;
    interrupt(0x21);
    ds = pop();
}
void sub_2b06b()
{
    al = memoryAGet(ds, 0x13cc);
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    bp = es;
    si = 0x24a1;
    es = si;
    si = 0x0000;
    si += ax;
    ax = memoryAGet16(es, si);
    memoryASet16(ds, 0x3136, ax);
    al = memoryAGet(es, si + 2);
    memoryASet(ds, 0x3135, al);
    memoryASet(ds, 0x3134, al);
    es = bp;
}
void sub_2b093()
{
    si = 0xa346;
    di = 0x2d8c;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(es);
    ax = 0xb800;
    es = ax;
    dl = 0x08;
    di = 0x1cc2;
loc_2b0a9:
    push(di);
    cx = 0x0018;
    ax = 0;
    rep_stosw<MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b0be;
    di -= 0x1fb0;
    goto loc_2b0c2;
loc_2b0be:
    di += 0x2000;
loc_2b0c2:
    dl--;
    if (dl != 0)
        goto loc_2b0a9;
    es = pop();
    memoryASet(ds, 0x2d3b, 0x01);
    bl = memoryAGet(ds, 0x2d39);
    if (!bl)
        goto loc_2b10b;
    bh = 0;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 11549);
    cl = 0x06;
loc_2b0de:
    push(cx);
    push(si);
    si = memoryAGet16(ds, si);
    dx = 0x03da;
loc_2b0e5:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b0e5;
loc_2b0ea:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b0ea;
    sub_2cda7();
    si = pop();
    si++;
    si++;
    cx = 0x0096;
loc_2b0f8:
    sub_2c26c();
    if (--cx)
        goto loc_2b0f8;
    cx = pop();
    cl--;
    if (cl != 0)
        goto loc_2b0de;
    si = 0x2d8c;
    di = 0x2e57;
    sub_2cea1();
loc_2b10b:
    si = 0x9bb0;
loc_2b10e:
    push(si);
    si = memoryAGet16(ds, si);
    if (!si)
        goto loc_2b132;
    dx = 0x03da;
loc_2b118:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b118;
loc_2b11d:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b11d;
    sub_2cec9();
    cx = 0x0096;
loc_2b128:
    sub_2c26c();
    if (--cx)
        goto loc_2b128;
    si = pop();
    si++;
    si++;
    goto loc_2b10e;
loc_2b132:
    si = pop();
    if (memoryAGet(ds, 0x13c9) != 0x00)
        return;
    sub_2aff1();
    sub_2fdd6();
}
void sub_2b141()
{
    bx = memoryAGet16(ds, 0x3144);
loc_2b145:
    if (bx == 0xffff)
        goto loc_2b174;
    push(bx);
    if (memoryAGet16(ds, bx) != 0x36f6)
        goto loc_2b158;
    sub_2e31b();
    goto loc_2b161;
loc_2b158:
    if (memoryAGet16(ds, bx) != 0x365e)
        goto loc_2b161;
    sub_2e288();
loc_2b161:
    bx = pop();
    cx = memoryAGet16(ds, 0x3138);
    dx = memoryAGet16(ds, bx + 12);
    memoryASet16(ds, bx + 12, cx);
    memoryASet16(ds, 0x3138, bx);
    bx = dx;
    goto loc_2b145;
loc_2b174:
    memoryASet16(ds, 0x3144, 0xffff);
    sub_2b218();
}
void sub_2b17e()
{
    bx = memoryAGet16(ds, 0x3144);
loc_2b182:
    if (bx == 0xffff)
        goto loc_2b1b1;
    push(bx);
    if (memoryAGet16(ds, bx) != 0x36f6)
        goto loc_2b195;
    sub_2e31b();
    goto loc_2b19e;
loc_2b195:
    if (memoryAGet16(ds, bx) != 0x365e)
        goto loc_2b19e;
    sub_2e288();
loc_2b19e:
    bx = pop();
    cx = memoryAGet16(ds, 0x3138);
    dx = memoryAGet16(ds, bx + 12);
    memoryASet16(ds, bx + 12, cx);
    memoryASet16(ds, 0x3138, bx);
    bx = dx;
    goto loc_2b182;
loc_2b1b1:
    memoryASet16(ds, 0x3144, 0xffff);
}
void sub_2b1b8()
{
    si = 0x33d7;
    cl = 0x08;
loc_2b1bd:
    push(cx);
    push(si);
    cl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 3, 0x00);
    al -= 0x0a;
    si = 0x6078;
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2b1e4;
    di += 0x2000;
loc_2b1e4:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    dh = 0x1f;
loc_2b1f4:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2b204;
    di -= 0x1fb0;
    goto loc_2b208;
loc_2b204:
    di += 0x2000;
loc_2b208:
    dh--;
    if (dh != 0)
        goto loc_2b1f4;
    es = pop();
    flags.interrupts = true;
    si = pop();
    si += 0x0004;
    cx = pop();
    cl--;
    if (cl != 0)
        goto loc_2b1bd;
}
void sub_2b218()
{
    si = 0x33d7;
    cl = 0x04;
loc_2b21d:
    push(cx);
    push(si);
    cl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 3, 0x00);
    al -= 0x0a;
    si = 0x6078;
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2b244;
    di += 0x2000;
loc_2b244:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    dh = 0x25;
loc_2b254:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2b264;
    di -= 0x1fb0;
    goto loc_2b268;
loc_2b264:
    di += 0x2000;
loc_2b268:
    dh--;
    if (dh != 0)
        goto loc_2b254;
    es = pop();
    flags.interrupts = true;
    si = pop();
    si += 0x0004;
    cx = pop();
    cl--;
    if (cl != 0)
        goto loc_2b21d;
    push(es);
    ax = 0xb800;
    es = ax;
    ax = 0x0000;
    di = 0x00a2;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = 0x20a2;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    es = pop();
    di = 0x2f18;
    al = 0x06;
    ah = 0x0e;
    push(es);
    dx = 0xb800;
    es = dx;
loc_2b29e:
    ch = 0x0c;
    cl = 0x08;
loc_2b2a2:
    push(ax);
    push(cx);
    bp = di;
    si = 0x3080;
    dh = 0;
    dl = memoryAGet(ds, di);
    if (dl != 0x0c)
        goto loc_2b2b8;
    sub_2f8e1();
    goto loc_2b314;
loc_2b2b8:
    if (dl == 0x04)
        goto loc_2b313;
    dx <<= 1;
    si += dx;
    si = memoryAGet16(ds, si);
    if (dl < 0x30)
        goto loc_2b2ce;
    push(ds);
    di = 0x24a1;
    ds = di;
loc_2b2ce:
    flags.interrupts = false;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2b2df;
    di += 0x2000;
loc_2b2df:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = 0x0008;
loc_2b2f0:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, ax);
    if (di < 0x2000)
        goto loc_2b307;
    di -= 0x1fb0;
    if (--cx)
        goto loc_2b2f0;
    goto loc_2b30d;
loc_2b307:
    di += 0x2000;
    if (--cx)
        goto loc_2b2f0;
loc_2b30d:
    if (dl < 0x30)
        goto loc_2b313;
    ds = pop();
loc_2b313:
    flags.interrupts = true;
loc_2b314:
    di = bp;
    cx = pop();
    ax = pop();
    di++;
    cl += 0x10;
    ch--;
    if (ch == 0)
        goto loc_2b322;
    goto loc_2b2a2;
loc_2b322:
    al += 0x08;
    ah--;
    if (ah == 0)
        goto loc_2b32b;
    goto loc_2b29e;
loc_2b32b:
    di = 0xb800;
    es = di;
    di = 0x1272;
    ax = 0x0000;
    dl = 0x29;
loc_2b338:
    bp = di;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = bp;
    di += 0x2000;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = bp;
    di += 0x0050;
    dl--;
    if (dl != 0)
        goto loc_2b338;
    es = pop();
}
void sub_2b355()
{
    sub_2b06b();
    bx = memoryAGet16(ds, 0x3144);
    memoryASet16(ds, 0x3142, 0x3138);
loc_2b362:
    if (bx == 0xffff)
        goto loc_2b39e;
    if (memoryAGet16(ds, bx) == 0x3abf)
        goto loc_2b3a2;
    push(bx);
    if (memoryAGet16(ds, bx) != 0x36f6)
        goto loc_2b37b;
    sub_2e31b();
    goto loc_2b384;
loc_2b37b:
    if (memoryAGet16(ds, bx) != 0x365e)
        goto loc_2b384;
    sub_2e288();
loc_2b384:
    bx = pop();
    cx = memoryAGet16(ds, 0x3138);
    dx = memoryAGet16(ds, bx + 12);
    memoryASet16(ds, bx + 12, cx);
    memoryASet16(ds, 0x3138, bx);
    si = memoryAGet16(ds, 0x3142);
    memoryASet16(ds, si + 12, dx);
    bx = dx;
    goto loc_2b362;
loc_2b39e:
    sub_2b218();
    return;
loc_2b3a2:
    memoryASet16(ds, 0x3142, bx);
    bx = memoryAGet16(ds, bx + 12);
    goto loc_2b362;
}
void sub_2b3ab()
{
    push(es);
    ax = 0xb800;
    es = ax;
    dl = 0xff;
    di = 0x213f;
    bx = 0x001a;
loc_2b3b9:
    ah = 0;
    dh = 0x04;
loc_2b3bd:
    cx = 0x0032;
loc_2b3c0:
    sub_2c26c();
    if (--cx)
        goto loc_2b3c0;
    cx = 0x0031;
    push(di);
    al = 0x55;
    //TODO: stop(/*74*/);
    flags.carry = true;
    ah = rcl(ah, 0x01);
    //TODO: stop(/*74*/);
    flags.carry = true;
    ah = rcl(ah, 0x01);
    al &= ah;
    push(di);
    push(ax);
    bp = dx;
    dx = 0x03da;
loc_2b3da:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b3da;
loc_2b3df:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b3df;
    dx = bp;
    ax = pop();
loc_2b3e7:
    stosb<MemAuto, DirAuto>();
    di += 0x004f;
    if (--cx)
        goto loc_2b3e7;
    di = pop();
    di -= 0x1fb0;
    cx = 0x0031;
loc_2b3f5:
    stosb<MemAuto, DirAuto>();
    di += 0x004f;
    if (--cx)
        goto loc_2b3f5;
    if (bx != 0x0001)
        goto loc_2b43b;
    di = 0x213f;
    al = 0x55;
    //TODO: stop(/*74*/);
    flags.carry = false;
    dl = rcl(dl, 0x01);
    // TODO: stop(/*74*/);
    flags.carry = false;
    dl = rcl(dl, 0x01);
    al &= dl;
    cx = 0x0031;
    cx = 0x0031;
    push(di);
    push(ax);
    bp = dx;
    dx = 0x03da;
loc_2b41a:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b41a;
loc_2b41f:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b41f;
    dx = bp;
    ax = pop();
loc_2b427:
    stosb<MemAuto, DirAuto>();
    di += 0x004f;
    if (--cx)
        goto loc_2b427;
    di = pop();
    di -= 0x1fb0;
    cx = 0x0031;
loc_2b435:
    stosb<MemAuto, DirAuto>();
    di += 0x004f;
    if (--cx)
        goto loc_2b435;
loc_2b43b:
    di = pop();
    dh--;
    if (dh == 0)
        goto loc_2b443;
    goto loc_2b3bd;
loc_2b443:
    di--;
    bx--;
    if (bx == 0)
        goto loc_2b44a;
    goto loc_2b3b9;
loc_2b44a:
    cx = 0x0032;
loc_2b44d:
    sub_2c26c();
    if (--cx)
        goto loc_2b44d;
    es = pop();
    cx = 0x0001;
loc_2b456:
    push(cx);
    ax = 0x001b;
    mul(cl);
    cx = ax;
    bp = ax;
    si = 0x8318;
    si -= cx;
    di = 0x1aef;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = 0x1aef;
    bx = 0;
loc_2b46f:
    if (bx == bp)
        goto loc_2b49d;
    if (bx >= 0x00bd)
        goto loc_2b49d;
    al = memoryAGet(ds, si);
    ah = 0;
    cl = 0x04;
loc_2b47f:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (flags.carry)
        goto loc_2b48d;
    ah = rcl(ah, 0x01);
    al <<= 1;
    //TODO: stop(/*74*/);
    flags.carry = false;
    ah = rcl(ah, 0x01);
    goto loc_2b493;
loc_2b48d:
    //TODO: stop(/*carry2*/);
    ah = rcl(ah, 0x01);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    ah = rcl(ah, 0x01);
loc_2b493:
    cl--;
    if (cl != 0)
        goto loc_2b47f;
    memoryASet(ds, si, ah);
    si++;
    bx++;
    goto loc_2b46f;
loc_2b49d:
    cx = pop();
    push(cx);
    push(es);
    ax = 0xb800;
    es = ax;
    si = 0x1aef;
    di = 0x0034;
    bx = cx;
    dx = 0x03da;
loc_2b4b0:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b4b0;
loc_2b4b5:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b4b5;
loc_2b4ba:
    push(di);
    cx = 0x001b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b4cd;
    di -= 0x1fb0;
    goto loc_2b4d1;
loc_2b4cd:
    di += 0x2000;
loc_2b4d1:
    bx--;
    if (bx != 0)
        goto loc_2b4ba;
    es = pop();
    cx = 0x0028;
loc_2b4d8:
    sub_2c26c();
    if (--cx)
        goto loc_2b4d8;
    cx = pop();
    cx++;
    if (cx == 0x006a)
        return;
    goto loc_2b456;
}
void sub_2b4e8()
{
    dx = 0x1428;
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2b517;
    bx = ax;
    push(ds);
    push(es);
    ax = 0x1c46;
    ds = ax;
    es = ax;
    dx = 0x0006;
    cx = 0x21b6;
    ah = 0x3f;
    interrupt(0x21);
    si = 0x0000;
    di = 0x0006;
    cx = 0x0006;
    repne_cmpsb<MemData, MemData, DirAuto>();
    es = pop();
    ds = pop();
    if (!flags.zero)
        goto loc_2b524;
    return;
loc_2b517:
    ax = pop();
    dx = 0x2a8f;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
loc_2b524:
    ax = pop();
    dx = 0x2ac3;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    bp = es;
    dx = 0xb800;
    es = dx;
    di = 0x0000;
    cx = 0x0064;
loc_2b53e:
    memoryASet16(es, di, 0x500d);
    memoryASet16(es, di + 50, 0x500d);
    di += 0x0050;
    if (--cx)
        goto loc_2b53e;
    cx = 0x0032;
    di = 0x2000;
loc_2b554:
    memoryASet16(es, di, 0x500d);
    memoryASet16(es, di + 50, 0x500d);
    memoryASet16(es, di + 80, 0x100d);
    memoryASet16(es, di + 130, 0x100d);
    di += 0x00a0;
    if (--cx)
        goto loc_2b554;
    di = 0x0000;
    cx = 0x0019;
    ax = 0xffff;
loc_2b57b:
    stosw<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2b57b;
    di = 0x0050;
    cx = 0x0019;
    ax = 0x1515;
loc_2b587:
    stosw<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2b587;
    di = 0x2000;
    cx = 0x0032;
loc_2b590:
    memoryASet(es, di, 0x55);
    memoryASet(es, di + 80, 0x55);
    di++;
    if (--cx)
        goto loc_2b590;
    di = 0x0000;
    si = 0x48d2;
    al = 0x07;
loc_2b5a4:
    push(di);
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b5b7;
    di -= 0x1fb0;
    goto loc_2b5bb;
loc_2b5b7:
    di += 0x2000;
loc_2b5bb:
    al--;
    if (al != 0)
        goto loc_2b5a4;
    di = 0x0031;
    si = 0x48bd;
    al = 0x07;
loc_2b5c7:
    push(di);
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b5da;
    di -= 0x1fb0;
    goto loc_2b5de;
loc_2b5da:
    di += 0x2000;
loc_2b5de:
    al--;
    if (al != 0)
        goto loc_2b5c7;
    es = bp;
}
void sub_2b531()
{
    bp = es;
    dx = 0xb800;
    es = dx;
    di = 0x0000;
    cx = 0x0064;
loc_2b53e:
    memoryASet16(es, di, 0x500d);
    memoryASet16(es, di + 50, 0x500d);
    di += 0x0050;
    if (--cx)
        goto loc_2b53e;
    cx = 0x0032;
    di = 0x2000;
loc_2b554:
    memoryASet16(es, di, 0x500d);
    memoryASet16(es, di + 50, 0x500d);
    memoryASet16(es, di + 80, 0x100d);
    memoryASet16(es, di + 130, 0x100d);
    di += 0x00a0;
    if (--cx)
        goto loc_2b554;
    di = 0x0000;
    cx = 0x0019;
    ax = 0xffff;
loc_2b57b:
    stosw<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2b57b;
    di = 0x0050;
    cx = 0x0019;
    ax = 0x1515;
loc_2b587:
    stosw<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2b587;
    di = 0x2000;
    cx = 0x0032;
loc_2b590:
    memoryASet(es, di, 0x55);
    memoryASet(es, di + 80, 0x55);
    di++;
    if (--cx)
        goto loc_2b590;
    di = 0x0000;
    si = 0x48d2;
    al = 0x07;
loc_2b5a4:
    push(di);
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b5b7;
    di -= 0x1fb0;
    goto loc_2b5bb;
loc_2b5b7:
    di += 0x2000;
loc_2b5bb:
    al--;
    if (al != 0)
        goto loc_2b5a4;
    di = 0x0031;
    si = 0x48bd;
    al = 0x07;
loc_2b5c7:
    push(di);
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b5da;
    di -= 0x1fb0;
    goto loc_2b5de;
loc_2b5da:
    di += 0x2000;
loc_2b5de:
    al--;
    if (al != 0)
        goto loc_2b5c7;
    es = bp;
}
void sub_2b5e5()
{
    bp = es;
    dx = 0xb800;
    es = dx;
    di = 0x1cc0;
    ch = 0;
loc_2b5f1:
    push(di);
    push(di);
    sub_2b63d();
    di = pop();
    di -= 0x07d0;
    push(di);
    sub_2b63d();
    di = pop();
    di -= 0x0820;
    push(di);
    sub_2b63d();
    di = pop();
    di -= 0x0780;
    push(di);
    sub_2b63d();
    di = pop();
    di = pop();
    if (di < 0x2000)
        goto loc_2b61f;
    di -= 0x2000;
    goto loc_2b623;
loc_2b61f:
    di += 0x1fb0;
loc_2b623:
    push(cx);
    cx = 0x0147;
loc_2b627:
    sub_2c26c();
    if (--cx)
        goto loc_2b627;
    cx = pop();
    ch++;
    if (ch == 0x06)
        goto loc_2b637;
    goto loc_2b5f1;
loc_2b637:
    es = bp;
    sub_2b1b8();
}
void sub_2b63d()
{
    memoryASet16(es, di, 0x4001);
    memoryASet16(es, di + 50, 0x4001);
    if (di < 0x2000)
        goto loc_2b654;
    di -= 0x1fb0;
    goto loc_2b658;
loc_2b654:
    di += 0x2000;
loc_2b658:
    memoryASet16(es, di, 0x500f);
    memoryASet16(es, di + 50, 0x500f);
    if (di < 0x2000)
        goto loc_2b66f;
    di -= 0x1fb0;
    goto loc_2b673;
loc_2b66f:
    di += 0x2000;
loc_2b673:
    memoryASet16(es, di, 0x4435);
    memoryASet16(es, di + 50, 0x4435);
    if (di < 0x2000)
        goto loc_2b68a;
    di -= 0x1fb0;
    goto loc_2b68e;
loc_2b68a:
    di += 0x2000;
loc_2b68e:
    if (!ch)
        goto loc_2b6ce;
    cl = ch;
loc_2b694:
    memoryASet16(es, di, 0xd43f);
    memoryASet16(es, di + 50, 0xd43f);
    if (di < 0x2000)
        goto loc_2b6ab;
    di -= 0x1fb0;
    goto loc_2b6af;
loc_2b6ab:
    di += 0x2000;
loc_2b6af:
    memoryASet16(es, di, 0x1005);
    memoryASet16(es, di + 50, 0x1005);
    if (di < 0x2000)
        goto loc_2b6c6;
    di -= 0x1fb0;
    goto loc_2b6ca;
loc_2b6c6:
    di += 0x2000;
loc_2b6ca:
    cl--;
    if (cl != 0)
        goto loc_2b694;
loc_2b6ce:
    memoryASet16(es, di, 0xd43f);
    memoryASet16(es, di + 50, 0xd43f);
    if (di < 0x2000)
        goto loc_2b6e5;
    di -= 0x1fb0;
    goto loc_2b6e9;
loc_2b6e5:
    di += 0x2000;
loc_2b6e9:
    memoryASet16(es, di, 0x4435);
    memoryASet16(es, di + 50, 0x4435);
    if (di < 0x2000)
        goto loc_2b700;
    di -= 0x1fb0;
    goto loc_2b704;
loc_2b700:
    di += 0x2000;
loc_2b704:
    memoryASet16(es, di, 0x500f);
    memoryASet16(es, di + 50, 0x500f);
    if (di < 0x2000)
        goto loc_2b71b;
    di -= 0x1fb0;
    goto loc_2b71f;
loc_2b71b:
    di += 0x2000;
loc_2b71f:
    memoryASet16(es, di, 0x4001);
    memoryASet16(es, di + 50, 0x4001);
}
void sub_2b72b()
{
    si = 0x13d5;
    di = 0x86ee;
    cl = 0x0c;
loc_2b733:
    lodsb<MemAuto, DirAuto>();
    push(si);
    push(cx);
    push(di);
    si = 0x9020;
    if (al != 0x2d)
        goto loc_2b743;
    al = 0x0b;
    goto loc_2b75b;
loc_2b743:
    if (al != 0x20)
        goto loc_2b74c;
    al = 0;
    goto loc_2b75b;
loc_2b74c:
    if (al > 0x39)
        goto loc_2b755;
    al -= 0x2f;
    goto loc_2b75b;
loc_2b755:
    if (al < 0x41)
        goto loc_2b75b;
    al -= 0x35;
loc_2b75b:
    ah = 0;
    cl = 0x03;
    ax <<= cl;
    bx = ax;
    bx <<= 1;
    bx += ax;
    si += bx;
    cx = 0x000c;
loc_2b76c:
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x001a;
    if (--cx)
        goto loc_2b76c;
    di = pop();
    cx = pop();
    si = pop();
    di++;
    di++;
    cl--;
    if (cl != 0)
        goto loc_2b733;
    si = 0x13cd;
    di = 0x8962;
    cl = 0x06;
loc_2b783:
    lodsb<MemAuto, DirAuto>();
    push(si);
    push(cx);
    push(di);
    si = 0x9020;
    if (al > 0x20)
        goto loc_2b793;
    al = 0;
    goto loc_2b7a7;
loc_2b793:
    if (al > 0x39)
        goto loc_2b79c;
    al -= 0x2f;
    goto loc_2b7a7;
loc_2b79c:
    if (al < 0x41)
        goto loc_2b7a5;
    al -= 0x35;
    goto loc_2b7a7;
loc_2b7a5:
    al = 0x0b;
loc_2b7a7:
    ah = 0;
    cl = 0x03;
    ax <<= cl;
    bx = ax;
    bx <<= 1;
    bx += ax;
    si += bx;
    cx = 0x000c;
loc_2b7b8:
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x001a;
    if (--cx)
        goto loc_2b7b8;
    di = pop();
    cx = pop();
    si = pop();
    di++;
    di++;
    cl--;
    if (cl != 0)
        goto loc_2b783;
    si = 0x48e7;
    di = 0x8cc0;
    dl = 0x01;
loc_2b7cf:
    push(di);
    al = dl;
    al--;
    ah = 0;
    bl = al;
    bl &= 0x03;
    al &= 0xfc;
    di += ax;
    ax = 0x00a8;
    mul(bl);
    di += ax;
    if (dl > memoryAGet(ds, 0x13c9))
        goto loc_2b807;
    push(si);
    al = 0x05;
loc_2b7ef:
    cx = 0x0002;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0018;
    al--;
    if (al != 0)
        goto loc_2b7ef;
    si = pop();
    di = pop();
    dl++;
    if (dl != 0x0d)
        goto loc_2b7cf;
    goto loc_2b825;
loc_2b807:
    push(si);
    al = 0x05;
loc_2b80a:
    cx = 0x0002;
    bp = ax;
    ax = 0;
    rep_stosw<MemAuto, DirAuto>();
    di += 0x0018;
    ax = bp;
    al--;
    if (al != 0)
        goto loc_2b80a;
    si = pop();
    di = pop();
    dl++;
    if (dl != 0x0d)
        goto loc_2b7cf;
loc_2b825:
    bp = es;
    ax = 0xb800;
    es = ax;
    bx = 0x0001;
    di = 0x3f24;
loc_2b832:
    if (bx == 0x005e)
        goto loc_2b881;
    push(bx);
    push(di);
    si = 0x85f0;
    dx = 0x03da;
loc_2b83f:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2b83f;
loc_2b844:
    in(al, dx);
    if (al & 0x08)
        goto loc_2b844;
loc_2b849:
    push(di);
    cx = 0x000e;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2b85c;
    di -= 0x1fb0;
    goto loc_2b860;
loc_2b85c:
    di += 0x2000;
loc_2b860:
    bx--;
    if (bx != 0)
        goto loc_2b849;
    cx = 0x0032;
loc_2b866:
    sub_2c26c();
    if (--cx)
        goto loc_2b866;
    di = pop();
    if (di >= 0x2000)
        goto loc_2b879;
    di += 0x1fb0;
    goto loc_2b87d;
loc_2b879:
    di -= 0x2000;
loc_2b87d:
    bx = pop();
    bx++;
    goto loc_2b832;
loc_2b881:
    es = bp;
}
void sub_2b884()
{
    push(cx);
    push(di);
    si = 0x9020;
    if (al != 0x3a)
        goto loc_2b892;
    al = 0x26;
    goto loc_2b8bc;
loc_2b892:
    if (al != 0xff)
        goto loc_2b89b;
    al = 0x27;
    goto loc_2b8bc;
loc_2b89b:
    if (al != 0x2d)
        goto loc_2b8a4;
    al = 0x0b;
    goto loc_2b8bc;
loc_2b8a4:
    if (al != 0x20)
        goto loc_2b8ad;
    al = 0;
    goto loc_2b8bc;
loc_2b8ad:
    if (al > 0x39)
        goto loc_2b8b6;
    al -= 0x2f;
    goto loc_2b8bc;
loc_2b8b6:
    if (al < 0x41)
        goto loc_2b8a4;
    al -= 0x35;
loc_2b8bc:
    ah = 0;
    cl = 0x03;
    ax <<= cl;
    bx = ax;
    bx <<= 1;
    bx += ax;
    si += bx;
    cx = 0x000c;
loc_2b8cd:
    movsw<MemAuto, MemAuto, DirAuto>();
    di--;
    di--;
    if (di < 0x2000)
        goto loc_2b8dc;
    di -= 0x1fb0;
    goto loc_2b8e0;
loc_2b8dc:
    di += 0x2000;
loc_2b8e0:
    if (--cx)
        goto loc_2b8cd;
    di = pop();
    cx = pop();
}
void sub_2b8e5()
{
    di = 0x344f;
    bl = memoryAGet(ds, 0x3f08);
loc_2b8ec:
    memoryASet(ds, di + 12, 0x05);
    memoryASet16(ds, di + 13, 0x000c);
    memoryASet(ds, di + 15, 0x00);
    memoryASet16(ds, di + 16, 0x3030);
    memoryASet16(ds, di + 18, 0x3030);
    memoryASet16(ds, di + 20, 0x3030);
    push(di);
    si = 0x000c;
    di += 0x0016;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x0058;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    di = pop();
    memoryASet16(ds, di + 198, 0xffff);
    memoryASet16(ds, di + 200, 0xffff);
    memoryASet16(ds, di + 202, 0xffff);
    memoryASet16(ds, di + 204, 0xffff);
    memoryASet16(ds, di + 206, 0xffff);
    memoryASet16(ds, di + 208, 0xffff);
    memoryASet(ds, di + 210, 0x00);
    di += 0x011b;
    bl--;
    if (bl != 0)
        goto loc_2b8ec;
}
void sub_2b94e()
{
    push(0x7777);
    goto loc_2b94e;
loc_2adf1:
    sub_2acb0();
loc_2adf4:
    sub_2ad26();
    sub_2fcdc();
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2ae05;
    sub_2f52d();
loc_2ae05:
    push(es);
    memoryASet16(ds, 0x1413, 0x0050);
    sub_30096();
    es = pop();
    memoryASet(ds, 0x13c4, 0x02);
    memoryASet16(ds, 0x13c5, 0x3f1e);
    ax = 0xffff;
    cx = 0x0003;
    di = 0x0000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2ae26:
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_2ae2f;
    goto loc_2aed4;
loc_2ae2f:
    ah = 0x00;
    interrupt(0x16);
    if (ax != 0x4300)
        goto loc_2ae3e;
    memoryASet(cs, 0x0084, memoryAGet(cs, 0x0084) ^ 0x01);
loc_2ae3e:
    if (ax != 0x4200)
        goto loc_2ae49;
    sub_2fdb6();
    goto loc_2aed4;
loc_2ae49:
    if (ax != 0x4100)
        goto loc_2ae59;
    memoryASet(ds, 0x3f1b, 0x00);
    memoryASet16(ds, 0x3f1c, 0x3f0b);
loc_2ae59:
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2ae63;
    sub_2fd91();
loc_2ae63:
    if (ax != 0x4400)
        goto loc_2ae79;
    sub_2f700();
loc_2ae6b:
    ah = 0x00;
    interrupt(0x16);
    if (ax == 0x4400)
        goto loc_2ae6b;
    sub_2f76f();
    goto loc_2ae26;
loc_2ae79:
    if (ax == 0x3b00)
        goto loc_2aef4;
    if (ax != 0x3d00)
        goto loc_2ae94;
    if (memoryAGet16(ds, 0x2d47) == 0x1654)
        goto loc_2ae94;
    memoryASet16(ds, 0x2d47, 0x1654);
    sub_2f52d();
loc_2ae94:
    if (ax != 0x3e00)
        goto loc_2aeaa;
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2aeaa;
    memoryASet16(ds, 0x2d47, 0x16d2);
    sub_2f52d();
loc_2aeaa:
    if (ax != 0x3f00)
        goto loc_2aeb5;
    sub_2c1a1();
    goto loc_2adf1;
loc_2aeb5:
    if (ax != 0x4000)
        goto loc_2aec0;
    sub_2fa3a();
    goto loc_2adf1;
loc_2aec0:
    if (ax == 0x3c00)
        goto loc_2aee8;
    if (ax != 0x011b)
        goto loc_2aed4;
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x4c00;
    interrupt(0x21);
loc_2aed4:
    bx = memoryAGet16(ds, 0x13c5);
    if (memoryAGet(ds, bx) == 0x00)
        goto loc_2aee8;
    push(es);
    sub_2ffe2();
    es = pop();
    sub_2fcff();
    goto loc_2ae26;
loc_2aee8:
    sub_2aca5();
    sub_2be32();
    sub_2c129();
    goto loc_2af15;
loc_2aef4:
    ax = memoryAGet16(ds, 0x2d47);
    memoryASet16(ds, 0x2d45, ax);
    sub_2aca5();
    sub_2bcfe();
    if (al != 0xff)
        goto loc_2af07;
    goto loc_2adf4;
loc_2af07:
    sub_2b8e5();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2af15;
    sub_2afd0();
loc_2af15:
    si = 0x344f;
    di = 0x13d5;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x13cd, 0x3030);
    memoryASet16(ds, 0x13cf, 0x3030);
    memoryASet16(ds, 0x13d1, 0x3030);
    memoryASet16(ds, 0x13d3, 0x3032);
    memoryASet(ds, 0x3f0a, 0x00);
    al = memoryAGet(ds, 0x3f08);
    memoryASet(ds, 0x3f09, al);
    memoryASet(ds, 0x13c9, 0x05);
    dl = 0x1e;
    sub_2ece0();
    al = ah;
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2af59;
    al = 0;
loc_2af59:
    memoryASet(ds, 0x13cc, al);
    dl = 0xb0;
    mul(dl);
    ax += 0x000c;
    memoryASet16(ds, 0x13ca, ax);
    sub_2b72b();
    goto loc_2afb8;
loc_2af6c:
    sub_2cad9();
loc_2af6f:
    sub_2c493();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_2acb0();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (!flags.carry)
        goto loc_2af96;
    sub_2b355();
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2af87;
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) - 1);
loc_2af87:
    if (memoryAGet(ds, 0x2e78) != 0x01)
        goto loc_2af6f;
    sub_2b093();
    sub_2b94e();
    goto loc_2af6c;
loc_2af96:
    sub_2b141();
    memoryASet16(ds, 0x13ca, memoryAGet16(ds, 0x13ca) + 0x00b0);
    memoryASet(ds, 0x13cc, memoryAGet(ds, 0x13cc) + 1);
    if (memoryAGet(ds, 0x13cc) != 0x32)
        goto loc_2afb8;
    memoryASet(ds, 0x13cc, 0x00);
    memoryASet16(ds, 0x13ca, 0x000c);
    sub_30560();
loc_2afb8:
    sub_2b06b();
    si = memoryAGet16(ds, 0x13ca);
    di = 0x2f10;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x00b0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    goto loc_2af6c;
    //   gap of 2430 bytes
loc_2b94e:
    memoryASet(ds, 0x2e78, 0x00);
    if (memoryAGet(ds, 0x13c9) != 0x00)
        goto loc_2b98b;
    memoryASet(ds, 0x2e78, 0x01);
    memoryASet(ds, 0x3f09, memoryAGet(ds, 0x3f09) - 1);
    if (memoryAGet(ds, 0x3f09) != 0)
        goto loc_2b98b;
    ax = pop();
    di = 0x344f;
    bh = 0;
    bl = memoryAGet(ds, 0x3f0a);
    ax = 0x011b;
    mul(bx);
    di += ax;
    ax = memoryAGet16(ds, 0x13cd);
    memoryASet16(ds, di + 16, ax);
    ax = memoryAGet16(ds, 0x13cf);
    memoryASet16(ds, di + 18, ax);
    ax = memoryAGet16(ds, 0x13d1);
    memoryASet16(ds, di + 20, ax);
    goto loc_2bac3;
loc_2b98b:
    if (memoryAGet(ds, 0x3f09) != 0x01)
        goto loc_2b99d;
    if (memoryAGet(ds, 0x2e78) == 0x01)
        goto loc_2b99d;
    ax = pop();
    goto loc_2af6f;
loc_2b99d:
    di = 0x344f;
    bh = 0;
    bl = memoryAGet(ds, 0x3f0a);
    ax = 0x011b;
    mul(bx);
    di += ax;
    bp = di;
    al = memoryAGet(ds, 0x13c9);
    memoryASet(ds, di + 12, al);
    ax = memoryAGet16(ds, 0x13ca);
    memoryASet16(ds, di + 13, ax);
    al = memoryAGet(ds, 0x13cc);
    memoryASet(ds, di + 15, al);
    ax = memoryAGet16(ds, 0x13cd);
    memoryASet16(ds, di + 16, ax);
    ax = memoryAGet16(ds, 0x13cf);
    memoryASet16(ds, di + 18, ax);
    ax = memoryAGet16(ds, 0x13d1);
    memoryASet16(ds, di + 20, ax);
    si = 0x2f10;
    di += 0x0016;
    cx = 0x0058;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bp;
    si = 0x30b0;
    di += 0x00c6;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bp;
    memoryASet(ds, di + 210, 0x00);
    di += 0x00d3;
    bx = memoryAGet16(ds, 0x3144);
loc_2b9fb:
    if (bx == 0xffff)
        goto loc_2ba15;
    push(di);
    di = bp;
    memoryASet(ds, di + 210, memoryAGet(ds, di + 210) + 1);
    di = pop();
    si = bx;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx = memoryAGet16(ds, bx + 12);
    goto loc_2b9fb;
loc_2ba15:
    bx = memoryAGet16(ds, 0x3144);
loc_2ba19:
    if (bx == 0xffff)
        goto loc_2ba31;
    cx = memoryAGet16(ds, 0x3138);
    dx = memoryAGet16(ds, bx + 12);
    memoryASet16(ds, bx + 12, cx);
    memoryASet16(ds, 0x3138, bx);
    bx = dx;
    goto loc_2ba19;
loc_2ba31:
    memoryASet16(ds, 0x3144, 0xffff);
loc_2ba37:
    memoryASet(ds, 0x3f0a, memoryAGet(ds, 0x3f0a) + 1);
    bl = memoryAGet(ds, 0x3f0a);
    if (bl != memoryAGet(ds, 0x3f08))
        goto loc_2ba4c;
    memoryASet(ds, 0x3f0a, 0x00);
    bl = 0;
loc_2ba4c:
    si = 0x344f;
    ax = 0x011b;
    bh = 0;
    mul(bx);
    si += ax;
    if (memoryAGet(ds, si + 12) == 0x00)
        goto loc_2ba37;
    di = 0x13d5;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    memoryASet(ds, 0x13c9, al);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(ds, 0x13ca, ax);
    lodsb<MemAuto, DirAuto>();
    memoryASet(ds, 0x13cc, al);
    di = 0x13cd;
    cx = 0x0003;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x2f10;
    cx = 0x0058;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x30b0;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2baa1;
loc_2ba8f:
    push(ax);
    di = si;
    sub_2de52();
    tx = di;
    di = si;
    si = tx;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ax = pop();
    al--;
    if (al != 0)
        goto loc_2ba8f;
loc_2baa1:
    sub_2b72b();
    sub_2b06b();
    ax = memoryAGet16(ds, 0x13cd);
    ax &= 0x0e0f;
    ah++;
    ah++;
    if (ah < 0x0a)
        goto loc_2baba;
    al++;
    ah = 0;
loc_2baba:
    ax += 0x3030;
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, 0x13d3, ax);
    assert(pop() == 0x7777);
    return;
loc_2bac3:
    if (memoryAGet(ds, 0x3f08) != 0x01)
        goto loc_2bacd;
    goto loc_2bc73;
loc_2bacd:
    di = 0x2f18;
    ax = 0;
    cx = 0x0054;
    rep_stosw<MemAuto, DirAuto>();
    sub_2cad9();
    dl = memoryAGet(ds, 0x3f08);
    di = 0x1aef;
    si = 0x344f;
    push(si);
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x0004;
    cx = 0x0003;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = pop();
    si += 0x011b;
    dl--;
    dh = 0x01;
loc_2bafb:
    push(dx);
    push(di);
    bp = si;
    sub_2bcac();
    si = bp;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x0004;
    cx = 0x0003;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = bp;
    si += 0x011b;
    di = pop();
    di += 0x0012;
    dx = pop();
    dh++;
    dl--;
    if (dl != 0)
        goto loc_2bafb;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x00f2;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = 0x20f2;
    dl = 0x18;
    al = 0x20;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x07;
    al = 0x20;
    sub_2bce5();
    al = 0x43;
    sub_2b884();
    di++;
    di++;
    al = 0x4c;
    sub_2b884();
    di++;
    di++;
    al = 0x41;
    sub_2b884();
    di++;
    di++;
    al = 0x53;
    sub_2b884();
    di++;
    di++;
    al = 0x53;
    sub_2b884();
    di++;
    di++;
    al = 0x45;
    sub_2b884();
    di++;
    di++;
    al = 0x4d;
    sub_2b884();
    di++;
    di++;
    al = 0x45;
    sub_2b884();
    di++;
    di++;
    al = 0x4e;
    sub_2b884();
    di++;
    di++;
    al = 0x54;
    sub_2b884();
    di++;
    di++;
    dl = 0x07;
    al = 0x20;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x05;
    al = 0x20;
    sub_2bce5();
    dl = 0x0e;
    al = 0x2d;
    sub_2bce5();
    al = 0x20;
    dl = 0x05;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x18;
    al = 0x20;
    sub_2bce5();
    di += 0x01b0;
    dl = memoryAGet(ds, 0x3f08);
    si = 0x1aef;
loc_2bbc4:
    push(dx);
    push(si);
    dl = 0x02;
    al = 0x20;
    sub_2bce5();
    si = pop();
    dl = 0x0c;
    sub_2bcf1();
    push(si);
    dl = 0x02;
    al = 0x20;
    sub_2bce5();
    si = pop();
    dl = 0x06;
    sub_2bcf1();
    al = 0x20;
    dl = 0x02;
    push(si);
    sub_2bce5();
    si = pop();
    di += 0x01b0;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2bc05;
    di -= 0x1fb0;
    goto loc_2bc09;
loc_2bc05:
    di += 0x2000;
loc_2bc09:
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2bc1d;
    di -= 0x1fb0;
    goto loc_2bc21;
loc_2bc1d:
    di += 0x2000;
loc_2bc21:
    dx = pop();
    dl--;
    if (dl != 0)
        goto loc_2bbc4;
loc_2bc26:
    if (di == 0x1f42)
        goto loc_2bc49;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2bc43;
    di -= 0x1fb0;
    goto loc_2bc47;
loc_2bc43:
    di += 0x2000;
loc_2bc47:
    goto loc_2bc26;
loc_2bc49:
    es = pop();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2bc55;
    sub_2aff1();
loc_2bc55:
    dl = 0xc8;
loc_2bc57:
    cx = 0x00c8;
loc_2bc5a:
    sub_2c26c();
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2bc6a;
    ah = 0;
    interrupt(0x16);
    goto loc_2bc86;
loc_2bc6a:
    if (--cx)
        goto loc_2bc5a;
    dl--;
    if (dl != 0)
        goto loc_2bc57;
    goto loc_2bc86;
loc_2bc73:
    si = 0x344f;
    di = 0x1aef;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x0004;
    cx = 0x0003;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2bc86:
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2bc91;
    sub_2aff1();
loc_2bc91:
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2bc9f;
    sub_2f957();
    sub_2f9db();
loc_2bc9f:
    sub_2fa3a();
    sub_2b17e();
    sp = memoryAGet16(ds, 0x1405);
    goto loc_2adf1;
}
void sub_2bcac()
{
    si += 0x0010;
    di += 0x000c;
loc_2bcb2:
    push(si);
    push(di);
    di -= 0x0012;
    cl = 0x06;
loc_2bcb9:
    al = memoryAGet(ds, si);
    si++;
    flags.zero = memoryAGet(es, di++) == al;
    if (stop(/*1 - ja loc_2bccb*/))
        goto loc_2bccb;
    if (stop(/*1 - jb loc_2bcc5*/))
        goto loc_2bcc5;
    cl--;
    if (cl != 0)
        goto loc_2bcb9;
loc_2bcc5:
    di = pop();
    si = pop();
    di -= 0x000c;
    return;
loc_2bccb:
    di = pop();
    di -= 0x000c;
    si = di;
    si -= 0x0012;
    cx = 0x0009;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di -= 0x0018;
    si = pop();
    dh--;
    if (dh != 0)
        goto loc_2bcb2;
    di -= 0x000c;
}
void sub_2bce5()
{
loc_2bce5:
    push(ax);
    sub_2b884();
    ax = pop();
    di++;
    di++;
    dl--;
    if (dl != 0)
        goto loc_2bce5;
}
void sub_2bcf1()
{
loc_2bcf1:
    lodsb<MemAuto, DirAuto>();
    push(si);
    sub_2b884();
    si = pop();
    di++;
    di++;
    dl--;
    if (dl != 0)
        goto loc_2bcf1;
}
void sub_2bcfe()
{
    memoryASet(ds, 0x3f08, 0x00);
    sub_2be32();
    sub_2ad26();
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x0142;
loc_2bd12:
    push(di);
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2bd2a;
    di -= 0x1fb0;
    goto loc_2bd2e;
loc_2bd2a:
    di += 0x2000;
loc_2bd2e:
    push(di);
    si = 0x13e1;
    dl = 0x18;
    sub_2bcf1();
    di = pop();
    di += 0x01e0;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = pop();
    push(di);
    if (di < 0x2000)
        goto loc_2bd52;
    di -= 0x1fb0;
    goto loc_2bd56;
loc_2bd52:
    di += 0x2000;
loc_2bd56:
    di += 0x0016;
    sub_2bfd8();
    sync();
    if (!flags.carry)
        goto loc_2bd86;
    di = pop();
    dl = 0x0e;
    ax = 0;
loc_2bd63:
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2bd77;
    di -= 0x1fb0;
    goto loc_2bd7b;
loc_2bd77:
    di += 0x2000;
loc_2bd7b:
    dl--;
    if (dl != 0)
        goto loc_2bd63;
    es = pop();
    memoryASet(ds, 0x13e9, 0x31);
    return;
loc_2bd86:
    if (al != 0xff)
        goto loc_2bd8d;
    goto loc_2be2a;
loc_2bd8d:
    memoryASet(ds, 0x3f08, memoryAGet(ds, 0x3f08) + 1);
    if (memoryAGet(ds, 0x3f08) != 0x09)
        goto loc_2bd9b;
    goto loc_2be2a;
loc_2bd9b:
    di = pop();
    di += 0x0280;
    bp = di;
    al = 0x3f;
    stosb<MemAuto, DirAuto>();
    ax = 0xffff;
    cx = 0x0017;
    rep_stosw<MemAuto, DirAuto>();
    al = 0xfc;
    stosb<MemAuto, DirAuto>();
    di = bp;
    if (di < 0x2000)
        goto loc_2bdbe;
    di -= 0x1fb0;
    goto loc_2bdc2;
loc_2bdbe:
    di += 0x2000;
loc_2bdc2:
    bp = di;
    al = 0xf5;
    stosb<MemAuto, DirAuto>();
    al = 0x55;
    cx = 0x002f;
    rep_stosb<MemAuto, DirAuto>();
    di = bp;
    if (di < 0x2000)
        goto loc_2bddc;
    di -= 0x1fb0;
    goto loc_2bde0;
loc_2bddc:
    di += 0x2000;
loc_2bde0:
    bp = di;
    al = 0xd5;
    stosb<MemAuto, DirAuto>();
    al = 0x15;
    cx = 0x002f;
    rep_stosb<MemAuto, DirAuto>();
    di = bp;
    if (di < 0x2000)
        goto loc_2bdfa;
    di -= 0x1fb0;
    goto loc_2bdfe;
loc_2bdfa:
    di += 0x2000;
loc_2bdfe:
    bp = di;
    al = 0x15;
    stosb<MemAuto, DirAuto>();
    ax = 0x5555;
    cx = 0x0017;
    rep_stosw<MemAuto, DirAuto>();
    al = 0x54;
    stosb<MemAuto, DirAuto>();
    memoryASet(ds, 0x13e9, memoryAGet(ds, 0x13e9) + 1);
    di = bp;
    if (di < 0x2000)
        goto loc_2be20;
    di -= 0x1fb0;
    goto loc_2be24;
loc_2be20:
    di += 0x2000;
loc_2be24:
    di += 0x0050;
    goto loc_2bd12;
loc_2be2a:
    di = pop();
    es = pop();
    memoryASet(ds, 0x13e9, 0x31);
}
void sub_2be32()
{
    memoryASet(cs, 0x5c6d, 0x00);
    push(es);
    dx = 0xb800;
    es = dx;
    di = 0x1e50;
    bp = di;
    ax = 0xffff;
    sub_2bf74();
    di = bp;
    if (di < 0x2000)
        goto loc_2be57;
    di -= 0x1fb0;
    goto loc_2be5b;
loc_2be57:
    di += 0x2000;
loc_2be5b:
    bp = di;
    ax = 0x5555;
    sub_2bf74();
    di = bp;
    if (di < 0x2000)
        goto loc_2be71;
    di -= 0x1fb0;
    goto loc_2be75;
loc_2be71:
    di += 0x2000;
loc_2be75:
    bp = di;
    ax = 0x5454;
    sub_2bf74();
    di = bp;
    if (di < 0x2000)
        goto loc_2be8b;
    di -= 0x1fb0;
    goto loc_2be8f;
loc_2be8b:
    di += 0x2000;
loc_2be8f:
    bp = di;
    ax = 0x5555;
    sub_2bf74();
    di = bp;
    if (di < 0x2000)
        goto loc_2bea5;
    di -= 0x1fb0;
    goto loc_2bea9;
loc_2bea5:
    di += 0x2000;
loc_2bea9:
    bp = di;
    ax = 0x0000;
    sub_2bf74();
    di = bp;
    if (di < 0x2000)
        goto loc_2bebf;
    di -= 0x1fb0;
    goto loc_2bec3;
loc_2bebf:
    di += 0x2000;
loc_2bec3:
    ax = 0x0000;
    sub_2bf74();
    di = 0x3e00;
    push(ds);
    ax = 0xb800;
    ds = ax;
    dl = 0xc2;
loc_2bed4:
    bp = di;
    push(dx);
    dx = 0x03da;
loc_2beda:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2beda;
loc_2bedf:
    in(al, dx);
    if (al & 0x08)
        goto loc_2bedf;
    dx = pop();
    dh = 0x06;
loc_2bee7:
    si = di;
    if (di < 0x2000)
        goto loc_2bef5;
    di -= 0x1fb0;
    goto loc_2bef9;
loc_2bef5:
    di += 0x2000;
loc_2bef9:
    tx = di;
    di = si;
    si = tx;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = si;
    di -= 0x0034;
    dh--;
    if (dh != 0)
        goto loc_2bee7;
    if (di < 0x2000)
        goto loc_2bf15;
    di -= 0x1fb0;
    goto loc_2bf19;
loc_2bf15:
    di += 0x2000;
loc_2bf19:
    al = memoryAGet(cs, 0x5c6d);
    bl = 0x50;
    al &= 0x03;
    if (al != 0)
        goto loc_2bf25;
    bl = 0x10;
loc_2bf25:
    al = 0x0d;
    stosb<MemAuto, DirAuto>();
    al = bl;
    stosb<MemAuto, DirAuto>();
    ax = 0x0000;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    al = 0x0d;
    stosb<MemAuto, DirAuto>();
    al = bl;
    stosb<MemAuto, DirAuto>();
    memoryASet(cs, 0x5c6d, memoryAGet(cs, 0x5c6d) + 1);
    di = bp;
    if (di < 0x2000)
        goto loc_2bf4d;
    di -= 0x2000;
    goto loc_2bf51;
loc_2bf4d:
    di += 0x1fb0;
loc_2bf51:
    cx = 0x05dc;
loc_2bf54:
    if (--cx)
        goto loc_2bf54;
    dl--;
    if (dl == 0)
        goto loc_2bf5d;
    goto loc_2bed4;
loc_2bf5d:
    ds = pop();
    es = pop();
    sub_2b531();
    bx = 0x0005;
loc_2bf65:
    cx = 0x0147;
loc_2bf68:
    sub_2c26c();
    if (--cx)
        goto loc_2bf68;
    bx--;
    if (bx != 0)
        goto loc_2bf65;
    sub_2b5e5();
}
void sub_2bf74()
{
    si = 0x48d2;
    dl = memoryAGet(cs, 0x5c6d);
    dh = dl;
    dl <<= 1;
    dl += dh;
    dh = 0;
    si += dx;
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = 0x0017;
    rep_stosw<MemAuto, DirAuto>();
    si = 0x48bd;
    si += dx;
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    memoryASet(cs, 0x5c6d, memoryAGet(cs, 0x5c6d) + 1);
}
void sub_2bfd8()
{
    goto loc_2bfd8;
loc_2bfa0:
    if (!dh)
        goto loc_2bff2;
    push(si);
    if (dh != 0x0c)
        goto loc_2bfc1;
    al = 0x20;
    sub_2b884();
    di -= 0x0004;
    dh--;
    sub_2c0c7();
    di++;
    di++;
    si = pop();
    si--;
    memoryASet(ds, si, 0x00);
    goto loc_2bff2;
loc_2bfc1:
    al = 0x2d;
    sub_2b884();
    di -= 0x0004;
    dh--;
    sub_2c0c7();
    di++;
    di++;
    si = pop();
    si--;
    memoryASet(ds, si, 0x00);
    goto loc_2bff2;
loc_2bfd8:
    si = 0x344f;
    al = memoryAGet(ds, 0x13e9);
    al -= 0x31;
    ah = 0;
    bx = 0x011b;
    mul(bx);
    si += ax;
    dh = 0;
    di--;
    di--;
    sub_2c0c7();
    di++;
    di++;
loc_2bff2:
    ah = 0x07;
    interrupt(0x21);
    if (al == 0x1b)
        goto loc_2c036;
    if (al == 0x08)
        goto loc_2bfa0;
    if (al == 0x0d)
        goto loc_2c036;
    if (al < 0x60)
        goto loc_2c008;
    al &= 0xdf;
loc_2c008:
    if (al == 0x20)
        goto loc_2c020;
    if (al == 0x2d)
        goto loc_2c020;
    if (al < 0x30)
        goto loc_2bff2;
    if (al > 0x5a)
        goto loc_2bff2;
    if (al >= 0x41)
        goto loc_2c020;
    if (al > 0x39)
        goto loc_2bff2;
loc_2c020:
    if (dh == 0x0c)
        goto loc_2bff2;
    memoryASet(ds, si, al);
    si++;
    dh++;
    push(si);
    sub_2b884();
    sub_2c0c7();
    si = pop();
    di++;
    di++;
    goto loc_2bff2;
loc_2c036:
    if (al == 0x1b)
        goto loc_2c047;
    if (dh)
        goto loc_2c04b;
    if (memoryAGet(ds, 0x3f08) == 0x00)
        goto loc_2c096;
    flags.carry = true;
    return;
loc_2c047:
    al = 0xff;
    flags.carry = false;
    return;
loc_2c04b:
    dl = 0x0d;
    dl -= dh;
    bl = dl;
    bl--;
    push(bx);
loc_2c054:
    memoryASet(ds, si, 0x20);
    push(si);
    al = 0x20;
    sub_2b884();
    si = pop();
    si++;
    di++;
    di++;
    dl--;
    if (dl != 0)
        goto loc_2c054;
    si = 0x344f;
    al = memoryAGet(ds, 0x13e9);
    al -= 0x31;
    ah = 0;
    cx = 0x011b;
    mul(cx);
    si += ax;
    si += 0x000a;
    bx = pop();
    bl >>= 1;
    if (bl == 0)
        goto loc_2c094;
loc_2c07e:
    push(si);
    cl = 0x0b;
loc_2c081:
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 1, al);
    si--;
    cl--;
    if (cl != 0)
        goto loc_2c081;
    memoryASet(ds, si + 1, 0x20);
    si = pop();
    bl--;
    if (bl != 0)
        goto loc_2c07e;
loc_2c094:
    flags.carry = false;
    return;
loc_2c096:
    push(cx);
    push(si);
    si = 0x344f;
    cl = 0x0c;
loc_2c09d:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2c0a8;
    cl--;
    if (cl == 0)
        goto loc_2c0ae;
    goto loc_2c09d;
loc_2c0a8:
    si = pop();
    cx = pop();
    goto loc_2bff2;
    //   gap of 1 bytes
loc_2c0ae:
    push(di);
    si = 0x344f;
    cl = 0x0c;
loc_2c0b4:
    lodsb<MemAuto, DirAuto>();
    push(si);
    sub_2b884();
    si = pop();
    di++;
    di++;
    cl--;
    if (cl != 0)
        goto loc_2c0b4;
    di = pop();
    si = pop();
    cx = pop();
    dh = 0x0c;
    goto loc_2c094;
}
void sub_2c0c7()
{
    di++;
    di++;
    push(si);
    al = 0xff;
    sub_2b884();
    si = pop();
    di--;
    di--;
}
void sub_2c0d3()
{
    bp = 0x4903;
    dh = 0x04;
loc_2c0d8:
    dl = 0x03;
    si = bp;
loc_2c0dc:
    di = si;
    di += 0x004d;
    push(si);
    push(di);
    cx = 0x004d;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    cl = 0x07;
loc_2c0eb:
    ch = 0x02;
loc_2c0ed:
    flags.carry = memoryAGet(ds, di) & 1;
    memoryASet(ds, di, memoryAGet(ds, di) >> 1);
    memoryASet(ds, di + 1, rcr(memoryAGet(ds, di + 1), 0x01));
    memoryASet(ds, di + 2, rcr(memoryAGet(ds, di + 2), 0x01));
    memoryASet(ds, di + 3, rcr(memoryAGet(ds, di + 3), 0x01));
    memoryASet(ds, di + 4, rcr(memoryAGet(ds, di + 4), 0x01));
    memoryASet(ds, di + 5, rcr(memoryAGet(ds, di + 5), 0x01));
    memoryASet(ds, di + 6, rcr(memoryAGet(ds, di + 6), 0x01));
    memoryASet(ds, di + 7, rcr(memoryAGet(ds, di + 7), 0x01));
    memoryASet(ds, di + 8, rcr(memoryAGet(ds, di + 8), 0x01));
    memoryASet(ds, di + 9, rcr(memoryAGet(ds, di + 9), 0x01));
    memoryASet(ds, di + 10, rcr(memoryAGet(ds, di + 10), 0x01));
    ch--;
    if (ch != 0)
        goto loc_2c0ed;
    di += 0x000b;
    cl--;
    if (cl != 0)
        goto loc_2c0eb;
    si = pop();
    si += 0x004d;
    dl--;
    if (dl != 0)
        goto loc_2c0dc;
    bp += 0x0134;
    dh--;
    if (dh != 0)
        goto loc_2c0d8;
}
void sub_2c129()
{
    memoryASet16(ds, 0x2d45, 0x1785);
    memoryASet(cs, 0x1784, 0xff);
    di = 0x344f;
    push(di);
    si = 0x13f9;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    memoryASet(ds, di + 12, 0x05);
    memoryASet16(ds, di + 13, 0x000c);
    memoryASet(ds, di + 15, 0x00);
    memoryASet16(ds, di + 16, 0x3030);
    memoryASet16(ds, di + 18, 0x3030);
    memoryASet16(ds, di + 20, 0x3030);
    push(di);
    si = 0x000c;
    di += 0x0016;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x0058;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    di = pop();
    memoryASet16(ds, di + 198, 0xffff);
    memoryASet16(ds, di + 200, 0xffff);
    memoryASet16(ds, di + 202, 0xffff);
    memoryASet16(ds, di + 204, 0xffff);
    memoryASet16(ds, di + 206, 0xffff);
    memoryASet16(ds, di + 208, 0xffff);
    memoryASet(ds, di + 211, 0x00);
    memoryASet(ds, 0x3f08, 0x01);
}
void sub_2c1a1()
{
    ax = 0x0001;
    interrupt(0x10);
    ah = 0x01;
    cx = 0xffff;
    interrupt(0x10);
    sub_2afd0();
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0;
    ah = 0x03;
    al = 0xc9;
    stosw<MemAuto, DirAuto>();
    al = 0xcd;
    cx = 0x0026;
    rep_stosw<MemAuto, DirAuto>();
    al = 0xbb;
    stosw<MemAuto, DirAuto>();
    dl = 0x17;
loc_2c1c9:
    al = 0xba;
    stosw<MemAuto, DirAuto>();
    ah = 0x07;
    al = 0x20;
    cx = 0x0026;
    rep_stosw<MemAuto, DirAuto>();
    ah = 0x03;
    al = 0xba;
    stosw<MemAuto, DirAuto>();
    dl--;
    if (dl != 0)
        goto loc_2c1c9;
    al = 0xc8;
    stosw<MemAuto, DirAuto>();
    al = 0xcd;
    cx = 0x0026;
    rep_stosw<MemAuto, DirAuto>();
    al = 0xbc;
    stosw<MemAuto, DirAuto>();
    si = 0x2b03;
    di = 0x0062;
    sub_2c262();
    si = 0x2b1a;
    di = 0x069a;
    sub_2c262();
    memoryASet16(ds, 0x2d4f, 0x0000);
    memoryASet(ds, 0x2d51, 0x00);
    bl = 0;
    si = 0x2d5c;
    di = 0x014c;
loc_2c210:
    push(di);
    sub_2c262();
    push(si);
    memoryASet(ds, 0x2d49, 0x01);
    sub_2c234();
    si = pop();
    di = pop();
    di += 0x00a0;
    bl++;
    if (bl != 0x03)
        goto loc_2c210;
    es = pop();
    sub_2aff1();
    ax = 0x0005;
    interrupt(0x10);
}
void sub_2c234()
{
loc_2c234:
    ah = memoryAGet(ds, 0x2d49);
    ah &= 0x7f;
    bh = bl;
    if (!bh)
        goto loc_2c24d;
    si = 0x2d4f;
loc_2c244:
    if (ah == memoryAGet(ds, si))
        goto loc_2c234;
    si++;
    bh--;
    if (bh != 0)
        goto loc_2c244;
loc_2c24d:
    si = 0x2d52;
loc_2c250:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2c25b;
    if (ah == al)
        goto loc_2c234;
    goto loc_2c250;
loc_2c25b:
    bh = 0;
    memoryASet(ds, bx + 11599, ah);
}
void sub_2c262()
{
loc_2c262:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        return;
    stosb<MemAuto, DirAuto>();
    di++;
    goto loc_2c262;
}
void sub_2c26c()
{
    push(cx);
    cx = 0x0001;
loc_2c270:
    if (--cx)
        goto loc_2c270;
    cx = pop();
}
void sub_2c2f2()
{
    push(0x7777);
    goto loc_2c2f2;
loc_2adf1:
    sub_2acb0();
loc_2adf4:
    sub_2ad26();
    sub_2fcdc();
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2ae05;
    sub_2f52d();
loc_2ae05:
    push(es);
    memoryASet16(ds, 0x1413, 0x0050);
    sub_30096();
    es = pop();
    memoryASet(ds, 0x13c4, 0x02);
    memoryASet16(ds, 0x13c5, 0x3f1e);
    ax = 0xffff;
    cx = 0x0003;
    di = 0x0000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2ae26:
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_2ae2f;
    goto loc_2aed4;
loc_2ae2f:
    ah = 0x00;
    interrupt(0x16);
    if (ax != 0x4300)
        goto loc_2ae3e;
    memoryASet(cs, 0x0084, memoryAGet(cs, 0x0084) ^ 0x01);
loc_2ae3e:
    if (ax != 0x4200)
        goto loc_2ae49;
    sub_2fdb6();
    goto loc_2aed4;
loc_2ae49:
    if (ax != 0x4100)
        goto loc_2ae59;
    memoryASet(ds, 0x3f1b, 0x00);
    memoryASet16(ds, 0x3f1c, 0x3f0b);
loc_2ae59:
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2ae63;
    sub_2fd91();
loc_2ae63:
    if (ax != 0x4400)
        goto loc_2ae79;
    sub_2f700();
loc_2ae6b:
    ah = 0x00;
    interrupt(0x16);
    if (ax == 0x4400)
        goto loc_2ae6b;
    sub_2f76f();
    goto loc_2ae26;
loc_2ae79:
    if (ax == 0x3b00)
        goto loc_2aef4;
    if (ax != 0x3d00)
        goto loc_2ae94;
    if (memoryAGet16(ds, 0x2d47) == 0x1654)
        goto loc_2ae94;
    memoryASet16(ds, 0x2d47, 0x1654);
    sub_2f52d();
loc_2ae94:
    if (ax != 0x3e00)
        goto loc_2aeaa;
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2aeaa;
    memoryASet16(ds, 0x2d47, 0x16d2);
    sub_2f52d();
loc_2aeaa:
    if (ax != 0x3f00)
        goto loc_2aeb5;
    sub_2c1a1();
    goto loc_2adf1;
loc_2aeb5:
    if (ax != 0x4000)
        goto loc_2aec0;
    sub_2fa3a();
    goto loc_2adf1;
loc_2aec0:
    if (ax == 0x3c00)
        goto loc_2aee8;
    if (ax != 0x011b)
        goto loc_2aed4;
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x4c00;
    interrupt(0x21);
loc_2aed4:
    bx = memoryAGet16(ds, 0x13c5);
    if (memoryAGet(ds, bx) == 0x00)
        goto loc_2aee8;
    push(es);
    sub_2ffe2();
    es = pop();
    sub_2fcff();
    goto loc_2ae26;
loc_2aee8:
    sub_2aca5();
    sub_2be32();
    sub_2c129();
    goto loc_2af15;
loc_2aef4:
    ax = memoryAGet16(ds, 0x2d47);
    memoryASet16(ds, 0x2d45, ax);
    sub_2aca5();
    sub_2bcfe();
    if (al != 0xff)
        goto loc_2af07;
    goto loc_2adf4;
loc_2af07:
    sub_2b8e5();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2af15;
    sub_2afd0();
loc_2af15:
    si = 0x344f;
    di = 0x13d5;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x13cd, 0x3030);
    memoryASet16(ds, 0x13cf, 0x3030);
    memoryASet16(ds, 0x13d1, 0x3030);
    memoryASet16(ds, 0x13d3, 0x3032);
    memoryASet(ds, 0x3f0a, 0x00);
    al = memoryAGet(ds, 0x3f08);
    memoryASet(ds, 0x3f09, al);
    memoryASet(ds, 0x13c9, 0x05);
    dl = 0x1e;
    sub_2ece0();
    al = ah;
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2af59;
    al = 0;
loc_2af59:
    memoryASet(ds, 0x13cc, al);
    dl = 0xb0;
    mul(dl);
    ax += 0x000c;
    memoryASet16(ds, 0x13ca, ax);
    sub_2b72b();
    goto loc_2afb8;
loc_2af6c:
    sub_2cad9();
loc_2af6f:
    sub_2c493();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_2acb0();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (stop(/*1 - jae loc_2af96*/))
        goto loc_2af96;
    sub_2b355();
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2af87;
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) - 1);
loc_2af87:
    if (memoryAGet(ds, 0x2e78) != 0x01)
        goto loc_2af6f;
    sub_2b093();
    sub_2b94e();
    goto loc_2af6c;
loc_2af96:
    sub_2b141();
    memoryASet16(ds, 0x13ca, memoryAGet16(ds, 0x13ca) + 0x00b0);
    memoryASet(ds, 0x13cc, memoryAGet(ds, 0x13cc) + 1);
    if (memoryAGet(ds, 0x13cc) != 0x32)
        goto loc_2afb8;
    memoryASet(ds, 0x13cc, 0x00);
    memoryASet16(ds, 0x13ca, 0x000c);
    sub_30560();
loc_2afb8:
    sub_2b06b();
    si = memoryAGet16(ds, 0x13ca);
    di = 0x2f10;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x00b0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    goto loc_2af6c;
    //   gap of 4811 bytes
loc_2c29b:
    sub_2b17e();
    sp = memoryAGet16(ds, 0x1405);
    goto loc_2adf1;
    //   gap of 77 bytes
loc_2c2f2:
    if (memoryAGet(ds, 0x2d49) != 0x01)
        goto loc_2c319;
    sub_2f7c9();
    sub_2aff1();
    ah = 0;
    interrupt(0x16);
    al &= 0xdf;
    if (al == 0x41)
        goto loc_2c317;
    sub_2f833();
    sub_2afd0();
    memoryASet(ds, 0x2d49, 0xff);
    goto loc_2c332;
loc_2c317:
    goto loc_2c29b;
loc_2c319:
    if (memoryAGet(ds, 0x2d49) != 0x44)
        goto loc_2c332;
    sub_2f700();
loc_2c323:
    sync();
    if (memoryAGet(ds, 0x2d49) == 0x44)
        goto loc_2c323;
    sub_2f76f();
    memoryASet(ds, 0x2d49, 0xff);
loc_2c332:
    memoryASet(ds, 0x2d40, memoryAGet(ds, 0x2d40) - 1);
    if (memoryAGet(ds, 0x2d40) == 0x00)
        goto loc_2c33e;
    assert(pop() == 0x7777);
    return;
loc_2c33e:
    if (memoryAGet(ds, 0x2d4b) == 0x01)
        goto loc_2c349;
    memoryASet(ds, 0x2d4b, memoryAGet(ds, 0x2d4b) - 1);
loc_2c349:
    al = memoryAGet(ds, 0x2d4b);
    memoryASet(ds, 0x2d40, al);
    al = memoryAGet(ds, 0x2d4e);
    if (al == memoryAGet(ds, 0x2d4d))
        goto loc_2c380;
    if (al)
        goto loc_2c36e;
loc_2c35c:
    al = memoryAGet(ds, 0x2e54);
    al++;
    if (al <= memoryAGet(ds, 0x2d3f))
        goto loc_2c36a;
    al = memoryAGet(ds, 0x2d3f);
loc_2c36a:
    memoryASet(ds, 0x2e54, al);
    assert(pop() == 0x7777);
    return;
loc_2c36e:
    al = memoryAGet(ds, 0x2e54);
    al--;
    if (al >= memoryAGet(ds, 0x2d3e))
        goto loc_2c37c;
    al = memoryAGet(ds, 0x2d3e);
loc_2c37c:
    memoryASet(ds, 0x2e54, al);
    assert(pop() == 0x7777);
    return;
loc_2c380:
    if (!al)
        goto loc_2c38d;
    if (memoryAGet(ds, 0x2d4a) == 0x00)
        goto loc_2c36e;
    goto loc_2c35c;
loc_2c38d:
    memoryASet(ds, 0x2d40, 0x05);
    memoryASet(ds, 0x2d4b, 0x05);
    al = memoryAGet(ds, 0x2d3f);
    if (memoryAGet(ds, 0x2e54) <= al)
        goto loc_2c3a3;
    memoryASet(ds, 0x2e54, al);
loc_2c3a3:
    assert(pop() == 0x7777);
}
void sub_2c3a5()
{
    push(0x7777);
    goto loc_2c3a5;
loc_2adf1:
    sub_2acb0();
loc_2adf4:
    sub_2ad26();
    sub_2fcdc();
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2ae05;
    sub_2f52d();
loc_2ae05:
    push(es);
    memoryASet16(ds, 0x1413, 0x0050);
    sub_30096();
    es = pop();
    memoryASet(ds, 0x13c4, 0x02);
    memoryASet16(ds, 0x13c5, 0x3f1e);
    ax = 0xffff;
    cx = 0x0003;
    di = 0x0000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2ae26:
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_2ae2f;
    goto loc_2aed4;
loc_2ae2f:
    ah = 0x00;
    interrupt(0x16);
    if (ax != 0x4300)
        goto loc_2ae3e;
    memoryASet(cs, 0x0084, memoryAGet(cs, 0x0084) ^ 0x01);
loc_2ae3e:
    if (ax != 0x4200)
        goto loc_2ae49;
    sub_2fdb6();
    goto loc_2aed4;
loc_2ae49:
    if (ax != 0x4100)
        goto loc_2ae59;
    memoryASet(ds, 0x3f1b, 0x00);
    memoryASet16(ds, 0x3f1c, 0x3f0b);
loc_2ae59:
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2ae63;
    sub_2fd91();
loc_2ae63:
    if (ax != 0x4400)
        goto loc_2ae79;
    sub_2f700();
loc_2ae6b:
    ah = 0x00;
    interrupt(0x16);
    if (ax == 0x4400)
        goto loc_2ae6b;
    sub_2f76f();
    goto loc_2ae26;
loc_2ae79:
    if (ax == 0x3b00)
        goto loc_2aef4;
    if (ax != 0x3d00)
        goto loc_2ae94;
    if (memoryAGet16(ds, 0x2d47) == 0x1654)
        goto loc_2ae94;
    memoryASet16(ds, 0x2d47, 0x1654);
    sub_2f52d();
loc_2ae94:
    if (ax != 0x3e00)
        goto loc_2aeaa;
    if (memoryAGet16(ds, 0x2d47) == 0x16d2)
        goto loc_2aeaa;
    memoryASet16(ds, 0x2d47, 0x16d2);
    sub_2f52d();
loc_2aeaa:
    if (ax != 0x3f00)
        goto loc_2aeb5;
    sub_2c1a1();
    goto loc_2adf1;
loc_2aeb5:
    if (ax != 0x4000)
        goto loc_2aec0;
    sub_2fa3a();
    goto loc_2adf1;
loc_2aec0:
    if (ax == 0x3c00)
        goto loc_2aee8;
    if (ax != 0x011b)
        goto loc_2aed4;
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x4c00;
    interrupt(0x21);
loc_2aed4:
    bx = memoryAGet16(ds, 0x13c5);
    if (memoryAGet(ds, bx) == 0x00)
        goto loc_2aee8;
    push(es);
    sub_2ffe2();
    es = pop();
    sub_2fcff();
    goto loc_2ae26;
loc_2aee8:
    sub_2aca5();
    sub_2be32();
    sub_2c129();
    goto loc_2af15;
loc_2aef4:
    ax = memoryAGet16(ds, 0x2d47);
    memoryASet16(ds, 0x2d45, ax);
    sub_2aca5();
    sub_2bcfe();
    if (al != 0xff)
        goto loc_2af07;
    goto loc_2adf4;
loc_2af07:
    sub_2b8e5();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2af15;
    sub_2afd0();
loc_2af15:
    si = 0x344f;
    di = 0x13d5;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x13cd, 0x3030);
    memoryASet16(ds, 0x13cf, 0x3030);
    memoryASet16(ds, 0x13d1, 0x3030);
    memoryASet16(ds, 0x13d3, 0x3032);
    memoryASet(ds, 0x3f0a, 0x00);
    al = memoryAGet(ds, 0x3f08);
    memoryASet(ds, 0x3f09, al);
    memoryASet(ds, 0x13c9, 0x05);
    dl = 0x1e;
    sub_2ece0();
    al = ah;
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2af59;
    al = 0;
loc_2af59:
    memoryASet(ds, 0x13cc, al);
    dl = 0xb0;
    mul(dl);
    ax += 0x000c;
    memoryASet16(ds, 0x13ca, ax);
    sub_2b72b();
    goto loc_2afb8;
loc_2af6c:
    sub_2cad9();
loc_2af6f:
    sub_2c493();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_2acb0();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (stop(/*1 - jae loc_2af96*/))
        goto loc_2af96;
    sub_2b355();
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2af87;
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) - 1);
loc_2af87:
    if (memoryAGet(ds, 0x2e78) != 0x01)
        goto loc_2af6f;
    sub_2b093();
    sub_2b94e();
    goto loc_2af6c;
loc_2af96:
    sub_2b141();
    memoryASet16(ds, 0x13ca, memoryAGet16(ds, 0x13ca) + 0x00b0);
    memoryASet(ds, 0x13cc, memoryAGet(ds, 0x13cc) + 1);
    if (memoryAGet(ds, 0x13cc) != 0x32)
        goto loc_2afb8;
    memoryASet(ds, 0x13cc, 0x00);
    memoryASet16(ds, 0x13ca, 0x000c);
    sub_30560();
loc_2afb8:
    sub_2b06b();
    si = memoryAGet16(ds, 0x13ca);
    di = 0x2f10;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    cx = 0x00b0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    goto loc_2af6c;
    //   gap of 5077 bytes
loc_2c3a5:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2c3e3;
    ah = 0;
    interrupt(0x16);
    if (ax != 0x4400)
        goto loc_2c3c6;
    sub_2f700();
loc_2c3b7:
    ah = 0x00;
    interrupt(0x16);
    if (ax == 0x4400)
        goto loc_2c3b7;
    sub_2f76f();
    goto loc_2c3e3;
loc_2c3c6:
    if (ax != 0x4300)
        goto loc_2c3d4;
    memoryASet(cs, 0x0084, memoryAGet(cs, 0x0084) ^ 0x01);
    goto loc_2c3e3;
loc_2c3d4:
    sub_304d3();
    if (flags.carry)
        goto loc_2c3e3;
    sub_2b17e();
    sp = memoryAGet16(ds, 0x1405);
    goto loc_2adf1;
loc_2c3e3:
    if (memoryAGet(cs, 0x1784) == 0xff)
        goto loc_2c44d;
    si = 0x2ea1;
    cl = memoryAGet(cs, 0x1784);
    if (!cl)
        goto loc_2c3fe;
loc_2c3f7:
    si += 0x001e;
    cl--;
    if (cl != 0)
        goto loc_2c3f7;
loc_2c3fe:
    if (memoryAGet(ds, si + 1) < 0x82)
        goto loc_2c44d;
    if (memoryAGet(ds, si + 21) == 0x01)
        goto loc_2c44d;
    if (memoryAGet(ds, si + 28) == 0x00)
        goto loc_2c44d;
    memoryASet(ds, 0x2d4c, 0x00);
    if (memoryAGet(ds, 0x2e7e) == 0x00)
        goto loc_2c421;
    memoryASet(ds, 0x2d4c, 0x01);
loc_2c421:
    al = memoryAGet(ds, si);
    bl = memoryAGet(ds, 0x2e54);
    if (al < bl)
        goto loc_2c442;
    bl += memoryAGet(ds, 0x2d3a);
    if (al < bl)
        goto loc_2c44c;
    bl -= memoryAGet(ds, 0x2d3a);
    if (bl == memoryAGet(ds, 0x2d3f))
        goto loc_2c44c;
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) + 1);
    assert(pop() == 0x7777);
    return;
loc_2c442:
    if (bl == memoryAGet(ds, 0x2d3e))
        goto loc_2c44c;
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) - 1);
loc_2c44c:
    assert(pop() == 0x7777);
    return;
loc_2c44d:
    si = 0x2ea1;
    cl = 0;
loc_2c452:
    if (memoryAGet(ds, si + 1) > 0x82)
        goto loc_2c475;
loc_2c458:
    si += 0x001e;
    cl++;
    if (cl != 0x03)
        goto loc_2c452;
    memoryASet(cs, 0x1784, 0xff);
    al = memoryAGet(ds, 0x2d3f);
    if (memoryAGet(ds, 0x2e54) < al)
        goto loc_2c492;
    memoryASet(ds, 0x2e54, al);
    assert(pop() == 0x7777);
    return;
loc_2c475:
    if (memoryAGet(ds, si + 28) == 0x00)
        goto loc_2c458;
    if (memoryAGet(ds, si + 21) == 0x01)
        goto loc_2c458;
    memoryASet(cs, 0x1784, cl);
    al = memoryAGet(ds, 0x2d3f);
    if (memoryAGet(ds, 0x2e54) < al)
        goto loc_2c492;
    memoryASet(ds, 0x2e54, al);
loc_2c492:
    assert(pop() == 0x7777);
}
void sub_2c493()
{
    bp = es;
    ax = 0xb800;
    es = ax;
    al = memoryAGet(ds, 0x13cc);
    al++;
    ah = 0;
    cl = 0x0a;
    div(cl);
    ax += 0x3030;
    memoryASet16(ds, 0x1410, ax);
    di = 0x177e;
    ax = 0xaaaa;
    cx = 0x000c;
    rep_stosw<MemAuto, DirAuto>();
    di = 0x377e;
    push(di);
    si = 0x1407;
    dl = 0x0c;
    sub_2bcf1();
    di = pop();
    di += 0x01e0;
    ax = 0xaaaa;
    cx = 0x000c;
    rep_stosw<MemAuto, DirAuto>();
    es = bp;
    ax = 0;
    interrupt(0x33);
    ax = 0x000f;
    cx = 0x000e;
    dx = 0x000a;
    interrupt(0x33);
    sub_2c86f();
    bp = es;
    ax = 0xb800;
    es = ax;
    di = 0x177e;
    dl = 0x0e;
    ax = 0;
loc_2c4f1:
    cx = 0x000c;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0018;
    if (di < 0x2000)
        goto loc_2c505;
    di -= 0x1fb0;
    goto loc_2c509;
loc_2c505:
    di += 0x2000;
loc_2c509:
    dl--;
    if (dl != 0)
        goto loc_2c4f1;
    es = bp;
    cx = 0x0064;
    dx = 0x00b8;
    memoryASet(ds, 0x2e54, cl);
    memoryASet(ds, 0x2e55, cl);
    ax = 0x0000;
    memoryASet(ds, 0x2d39, al);
    di = 0x2d0d;
    ax = memoryAGet16(ds, di + 2);
    memoryASet(ds, 0x2d3f, 0xac);
    memoryASet(ds, 0x2d3e, 0x08);
    memoryASet(ds, 0x2d40, 0x05);
    memoryASet(ds, 0x2d4b, 0x05);
    memoryASet(ds, 0x2d3a, al);
    cx <<= 1;
    ax = 0x0004;
    interrupt(0x33);
    di = 0x2e57;
    bl = memoryAGet(ds, 0x2e54);
    sub_2cefe();
    si = 0x4903;
    di = 0x2d8c;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet(ds, 0x2e73, 0x01);
    si = 0x48fb;
    di = 0x2ea1;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x1489, 0x01f4);
    memoryASet(ds, 0x2d4d, 0x00);
    memoryASet(ds, 0x2d4e, 0x00);
    memoryASet(ds, 0x2d4b, 0x00);
    memoryASet(ds, 0x2d4c, 0x00);
    memoryASet(ds, 0x1485, 0xfa);
    memoryASet(ds, 0x1486, 0xfa);
    if (memoryAGet(cs, 0x164c) == 0xc3)
        goto loc_2c5a5;
    memoryASet(ds, 0x1485, 0x03);
    memoryASet(ds, 0x1486, 0x03);
loc_2c5a5:
    memoryASet16(ds, 0x148b, 0x4e20);
    memoryASet(ds, 0x313a, 0x00);
    memoryASet(ds, 0x33d5, 0x00);
    memoryASet(ds, 0x33d6, 0x00);
    memoryASet(ds, 0x3384, 0x00);
    memoryASet(ds, 0x2d3b, 0x00);
    memoryASet(ds, 0x2e81, 0x00);
    memoryASet(ds, 0x2e75, 0x00);
    memoryASet(ds, 0x2e78, 0x00);
    memoryASet(ds, 0x2e79, 0x00);
    memoryASet(ds, 0x2e7e, 0x00);
    di = 0x2ea1;
    memoryASet(ds, di, 0x70);
    memoryASet(ds, di + 2, 0x70);
    memoryASet(ds, di + 1, 0xb5);
    memoryASet(ds, di + 3, 0xb5);
    memoryASet(ds, di + 22, 0x01);
    memoryASet(ds, di + 23, 0x02);
    memoryASet(ds, di + 20, 0x00);
    memoryASet(ds, di + 21, 0x01);
    al = memoryAGet(ds, di);
    memoryASet(ds, di + 24, al);
    al = memoryAGet(ds, di + 1);
    memoryASet(ds, di + 25, al);
    memoryASet(ds, di + 26, 0x00);
    memoryASet(ds, di + 27, 0x00);
    memoryASet(ds, di + 28, 0x01);
    memoryASet(ds, di + 29, 0x00);
    memoryASet(ds, di + 58, 0x00);
    memoryASet(ds, di + 88, 0x00);
    si = di;
    si += 0x0004;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    sub_2d4a1();
    ax = 0x0007;
    cx = 0x0010;
    dx = 0x0168;
    interrupt(0x33);
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2c645;
    sub_2aff1();
loc_2c645:
    sub_2ad26();
    if (memoryAGet16(ds, 0x2d45) != 0x16d2)
        goto loc_2c653;
    sub_2afd0();
loc_2c653:
    if (memoryAGet16(ds, 0x2d45) == 0x1785)
        goto loc_2c682;
    memoryASet16(ds, 0x2e7a, 0x07d0);
loc_2c661:
    memoryASet16(ds, 0x2e7a, memoryAGet16(ds, 0x2e7a) - 1);
    if (memoryAGet16(ds, 0x2e7a) == 0)
        goto loc_2c682;
    cx = 0x000f;
loc_2c66a:
    sub_2c26c();
    if (--cx)
        goto loc_2c66a;
    callIndirect(cs, memoryAGet16(ds, 0x2d45));
    if (memoryAGet(ds, 0x2d4c) == 0x01)
        goto loc_2c682;
    si = 0x4903;
    sub_2ce3a();
    goto loc_2c661;
loc_2c682:
    ax = memoryAGet16(ds, 0x1489);
    memoryASet16(ds, 0x1487, ax);
    bp = es;
    si = 0x24a1;
    es = si;
    memoryASet(ds, 0x3134, memoryAGet(ds, 0x3134) - 1);
    if (memoryAGet(ds, 0x3134) != 0)
        goto loc_2c6b2;
    al = memoryAGet(ds, 0x3135);
    memoryASet(ds, 0x3134, al);
    memoryASet16(ds, 0x3136, memoryAGet16(ds, 0x3136) + 0x0002);
    si = memoryAGet16(ds, 0x3136);
    if (memoryAGet16(es, si) != 0xffff)
        goto loc_2c6b2;
    ax = memoryAGet16(es, si + 2);
    memoryASet16(ds, 0x3136, ax);
loc_2c6b2:
    es = bp;
    if (memoryAGet(ds, 0x2e73) != 0x00)
        goto loc_2c6c5;
    sub_2edf4();
    memoryASet(ds, 0x2e78, 0x01);
    flags.carry = true;
    return;
loc_2c6c5:
    if (memoryAGet(ds, 0x2f10) != 0x00)
        goto loc_2c6d1;
    sub_2edf4();
    flags.carry = false;
    return;
loc_2c6d1:
    callIndirect(cs, memoryAGet16(ds, 0x2d45));
    if (memoryAGet(ds, 0x2d3b) != 0x00)
        goto loc_2c6ee;
    bx = 0;
    bl = memoryAGet(ds, 0x2d39);
    bx <<= 1;
    bx <<= 1;
    si = 0x2d0d;
    si = memoryAGet16(ds, bx + si);
    sub_2ce3a();
loc_2c6ee:
    if (memoryAGet(ds, 0x2e7e) == 0x00)
        goto loc_2c6f8;
    sub_2db03();
loc_2c6f8:
    memoryASet16(ds, 0x148b, memoryAGet16(ds, 0x148b) - 1);
    if (memoryAGet16(ds, 0x148b) != 0)
        goto loc_2c715;
    memoryASet16(ds, 0x148b, 0x61a8);
    if (memoryAGet(ds, 0x1486) == 0xff)
        goto loc_2c70f;
    memoryASet(ds, 0x1486, memoryAGet(ds, 0x1486) + 1);
loc_2c70f:
    al = memoryAGet(ds, 0x1486);
    memoryASet(ds, 0x1485, al);
loc_2c715:
    memoryASet(ds, 0x1485, memoryAGet(ds, 0x1485) - 1);
    if (memoryAGet(ds, 0x1485) != 0)
        goto loc_2c724;
    al = memoryAGet(ds, 0x1486);
    memoryASet(ds, 0x1485, al);
    goto loc_2c76d;
loc_2c724:
    cl = 0x03;
    si = 0x2ea1;
loc_2c729:
    push(cx);
    if (memoryAGet(ds, si + 28) == 0x00)
        goto loc_2c765;
    if (memoryAGet(ds, si + 28) >= 0x03)
        goto loc_2c765;
    if (memoryAGet(ds, 0x2e75) != 0x01)
        goto loc_2c742;
    sub_2da3e();
    if (!flags.carry)
        goto loc_2c765;
loc_2c742:
    sub_2d3f7();
    sub_2d447();
    if (!flags.carry)
        goto loc_2c755;
    cx = pop();
    sub_2edf4();
    memoryASet(ds, 0x2e78, 0x01);
    flags.carry = true;
    return;
loc_2c755:
    if (memoryAGet(ds, 0x2f10) != 0x00)
        goto loc_2c762;
    cx = pop();
    sub_2edf4();
    flags.carry = false;
    return;
loc_2c762:
    sub_2d09f();
loc_2c765:
    si += 0x001e;
    cx = pop();
    cl--;
    if (cl != 0)
        goto loc_2c729;
loc_2c76d:
    memoryASet16(ds, 0x3142, 0x3138);
    bx = memoryAGet16(ds, 0x3144);
loc_2c777:
    if (bx == 0xffff)
        goto loc_2c79b;
    push(bx);
    callIndirect(cs, memoryAGet16(ds, bx));
    bx = pop();
    if (memoryAGet(ds, 0x313a) != 0x00)
        goto loc_2c791;
    memoryASet16(ds, 0x3142, bx);
    bx = memoryAGet16(ds, bx + 12);
    goto loc_2c777;
loc_2c791:
    cx = memoryAGet16(ds, bx + 12);
    sub_2de77();
    bx = cx;
    goto loc_2c777;
loc_2c79b:
    if (memoryAGet(ds, 0x2e81) == 0x00)
        goto loc_2c7e4;
    memoryASet(ds, 0x2e84, memoryAGet(ds, 0x2e84) - 1);
    if (memoryAGet(ds, 0x2e84) != 0)
        goto loc_2c7d3;
    bp = es;
    ax = 0xb800;
    es = ax;
    di = memoryAGet16(ds, 0x2e85);
    ax = 0;
    stosw<MemAuto, DirAuto>();
    di--;
    di--;
    if (di < 0x2000)
        goto loc_2c7c4;
    di -= 0x1fb0;
    goto loc_2c7c8;
loc_2c7c4:
    di += 0x2000;
loc_2c7c8:
    memoryASet16(ds, 0x2e85, di);
    memoryASet(ds, 0x2e84, 0xc8);
    es = bp;
loc_2c7d3:
    memoryASet16(ds, 0x2e82, memoryAGet16(ds, 0x2e82) - 1);
    if (memoryAGet16(ds, 0x2e82) != 0)
        goto loc_2c7e4;
    memoryASet(ds, 0x2e81, 0x00);
    dx = 0x1554;
    sub_2dd66();
loc_2c7e4:
    if (memoryAGet(ds, 0x2e79) == 0x00)
        goto loc_2c828;
    memoryASet16(ds, 0x2e7c, memoryAGet16(ds, 0x2e7c) - 1);
    if (memoryAGet16(ds, 0x2e7c) != 0)
        goto loc_2c81d;
    bp = es;
    ax = 0xb800;
    es = ax;
    di = memoryAGet16(ds, 0x2e87);
    ax = 0;
    stosw<MemAuto, DirAuto>();
    di--;
    di--;
    if (di < 0x2000)
        goto loc_2c80d;
    di -= 0x1fb0;
    goto loc_2c811;
loc_2c80d:
    di += 0x2000;
loc_2c811:
    memoryASet16(ds, 0x2e87, di);
    memoryASet16(ds, 0x2e7c, 0x0190);
    es = bp;
loc_2c81d:
    memoryASet16(ds, 0x2e7a, memoryAGet16(ds, 0x2e7a) - 1);
    if (memoryAGet16(ds, 0x2e7a) != 0)
        goto loc_2c828;
    memoryASet(ds, 0x2e79, 0x00);
loc_2c828:
    ah = 0x03;
    ah -= memoryAGet(ds, 0x33d6);
    if (ah == 0)
        goto loc_2c839;
loc_2c830:
    cx = 0x00b4;
loc_2c833:
    if (--cx)
        goto loc_2c833;
    ah--;
    if (ah != 0)
        goto loc_2c830;
loc_2c839:
    if (memoryAGet(ds, 0x2e79) == 0x01)
        goto loc_2c853;
    if (memoryAGet(ds, 0x33d5) == 0x03)
        goto loc_2c853;
    dl = 0x86;
    sub_2ece0();
    if (ah)
        goto loc_2c853;
    sub_2e9b5();
loc_2c853:
    sub_2acb7();
    cx = memoryAGet16(ds, 0x1487);
loc_2c85a:
    if (--cx)
        goto loc_2c85a;
    sub_2c26c();
    goto loc_2c682;
}
void sub_2c86f()
{
    memoryASet(ds, 0x2e54, 0xc8);
    cl = memoryAGet(ds, 0x33f3);
    al = memoryAGet(ds, 0x33f4);
    al--;
    si = 0x770d;
    ch = 0x05;
loc_2c882:
    push(es);
    dx = 0xb800;
    es = dx;
    push(ax);
    push(cx);
    push(si);
    si = memoryAGet16(ds, si);
    flags.interrupts = false;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2c89e;
    di += 0x2000;
loc_2c89e:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cl = 0x13;
loc_2c8ae:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2c8c2;
    di -= 0x1fb0;
    cl--;
    if (cl != 0)
        goto loc_2c8ae;
    goto loc_2c8ca;
loc_2c8c2:
    di += 0x2000;
    cl--;
    if (cl != 0)
        goto loc_2c8ae;
loc_2c8ca:
    flags.interrupts = true;
    si = pop();
    si++;
    si++;
    cx = 0x012c;
loc_2c8d1:
    sub_2c26c();
    if (--cx)
        goto loc_2c8d1;
    cx = pop();
    ax = pop();
    ch--;
    es = pop();
    if (ch != 0)
        goto loc_2c882;
    di = 0x3a7c;
    al = memoryAGet(ds, 0x13c9);
    al--;
    ah = 0;
    bl = al;
    bl &= 0x03;
    al &= 0xfc;
    di += ax;
    if (!bl)
        goto loc_2c8fc;
loc_2c8f4:
    di += 0x00f0;
    bl--;
    if (bl != 0)
        goto loc_2c8f4;
loc_2c8fc:
    bp = es;
    ax = 0xb800;
    es = ax;
    ax = 0;
    dl = 0x05;
loc_2c907:
    cx = 0x0002;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0004;
    if (di < 0x2000)
        goto loc_2c91b;
    di -= 0x1fb0;
    goto loc_2c91f;
loc_2c91b:
    di += 0x2000;
loc_2c91f:
    dl--;
    if (dl != 0)
        goto loc_2c907;
    es = bp;
    memoryASet16(ds, 0x1468, 0x7525);
    memoryASet(ds, 0x2e54, 0xc6);
    cl = 0xc8;
    sub_2ca70();
    memoryASet16(ds, 0x1468, memoryAGet16(ds, 0x1468) + 0x0002);
    al = 0x09;
loc_2c93c:
    push(ax);
    cx = 0x004b;
loc_2c940:
    sub_2c26c();
    if (--cx)
        goto loc_2c940;
    cl = memoryAGet(ds, 0x2e54);
    sub_2ca43();
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) - 1);
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) - 1);
    ax = pop();
    al--;
    if (al != 0)
        goto loc_2c93c;
    cl = memoryAGet(ds, 0x33f3);
    al = memoryAGet(ds, 0x33f4);
    al--;
    si = 0x7717;
    ch = 0x14;
loc_2c967:
    push(cx);
    push(ax);
    push(es);
    flags.carry = ch & 1;
    ch >>= 1;
    if (flags.carry)
        goto loc_2c9bb;
    flags.carry = ch & 1;
    ch >>= 1;
    if (flags.carry)
        goto loc_2c9bb;
    dx = 0xb800;
    es = dx;
    push(si);
    si = memoryAGet16(ds, si);
    flags.interrupts = false;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2c98b;
    di += 0x2000;
loc_2c98b:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cl = 0x13;
loc_2c99b:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2c9af;
    di -= 0x1fb0;
    cl--;
    if (cl != 0)
        goto loc_2c99b;
    goto loc_2c9b7;
loc_2c9af:
    di += 0x2000;
    cl--;
    if (cl != 0)
        goto loc_2c99b;
loc_2c9b7:
    flags.interrupts = true;
    si = pop();
    si++;
    si++;
loc_2c9bb:
    cx = 0x004b;
loc_2c9be:
    sub_2c26c();
    if (--cx)
        goto loc_2c9be;
    es = pop();
    push(si);
    cl = memoryAGet(ds, 0x2e54);
    sub_2ca43();
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) - 0x02);
    si = pop();
    ax = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_2c967;
    cx = 0x004b;
loc_2c9db:
    sub_2c26c();
    if (--cx)
        goto loc_2c9db;
loc_2c9e0:
    if (memoryAGet(ds, 0x2e54) < 0x6d)
        goto loc_2c9fd;
    cl = memoryAGet(ds, 0x2e54);
    sub_2ca43();
    memoryASet(ds, 0x2e54, memoryAGet(ds, 0x2e54) - 0x02);
    cx = 0x004b;
loc_2c9f6:
    sub_2c26c();
    if (--cx)
        goto loc_2c9f6;
    goto loc_2c9e0;
loc_2c9fd:
    cx = 0x0000;
loc_2ca00:
    if (--cx)
        goto loc_2ca00;
    si = 0x75db;
    bp = es;
    ax = 0xb800;
    es = ax;
    ah = 0x06;
loc_2ca0e:
    push(si);
    di = 0x1cd9;
    si = memoryAGet16(ds, si);
    al = 0x07;
loc_2ca16:
    push(di);
    cx = 0x0007;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2ca29;
    di -= 0x1fb0;
    goto loc_2ca2d;
loc_2ca29:
    di += 0x2000;
loc_2ca2d:
    al--;
    if (al != 0)
        goto loc_2ca16;
    si = pop();
    si++;
    si++;
    cx = 0x0147;
loc_2ca37:
    sub_2c26c();
    if (--cx)
        goto loc_2ca37;
    ah--;
    if (ah != 0)
        goto loc_2ca0e;
    es = bp;
}
void sub_2ca43()
{
    push(cx);
    cl++;
    cl++;
    memoryASet16(ds, 0x1468, memoryAGet16(ds, 0x1468) - 0x0002);
    sub_2ca70();
    cx = pop();
    memoryASet16(ds, 0x1468, memoryAGet16(ds, 0x1468) + 0x0002);
    sub_2ca70();
    memoryASet16(ds, 0x1468, memoryAGet16(ds, 0x1468) + 0x0002);
    si = memoryAGet16(ds, 0x1468);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_2ca69;
    return;
loc_2ca69:
    memoryASet16(ds, 0x1468, 0x7521);
}
void sub_2ca70()
{
    si = memoryAGet16(ds, 0x1468);
    si = memoryAGet16(ds, si);
    di = 0x146a;
    bp = cx;
    cx = 0x0015;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = bp;
    cl &= 0x03;
    if (cl == 0)
        goto loc_2caa1;
    cl <<= 1;
loc_2ca89:
    si = 0x146a;
    dh = 0x07;
loc_2ca8e:
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    memoryASet(ds, si + 1, rcr(memoryAGet(ds, si + 1), 0x01));
    memoryASet(ds, si + 2, rcr(memoryAGet(ds, si + 2), 0x01));
    si += 0x0003;
    dh--;
    if (dh != 0)
        goto loc_2ca8e;
    cl--;
    if (cl != 0)
        goto loc_2ca89;
loc_2caa1:
    push(es);
    dx = 0xb800;
    es = dx;
    cx = bp;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    di += 0x1cc0;
    si = 0x146a;
    cl = 0x07;
loc_2caba:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 2, memoryAGet(es, di + 2) ^ al);
    if (di < 0x2000)
        goto loc_2cacf;
    di -= 0x1fb0;
    goto loc_2cad3;
loc_2cacf:
    di += 0x2000;
loc_2cad3:
    cl--;
    if (cl != 0)
        goto loc_2caba;
    es = pop();
    sync();
}
void sub_2cad9()
{
    push(es);
    ax = 0xb800;
    es = ax;
    si = 0x6d9f;
    bl = 0x08;
loc_2cae4:
    push(si);
    sub_2cd29();
    si = pop();
    di = 0x3ef2;
    cx = 0x0018;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = 0x07d0;
loc_2caf4:
    if (--cx)
        goto loc_2caf4;
    bl--;
    if (bl != 0)
        goto loc_2cae4;
    si = 0x6d36;
    bl = 0x13;
loc_2cb00:
    push(si);
    sub_2cd29();
    si = pop();
    di = 0x3f08;
    cx = 0x0005;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = 0x08fc;
loc_2cb10:
    if (--cx)
        goto loc_2cb10;
    bl--;
    if (bl != 0)
        goto loc_2cb00;
    es = pop();
    memoryASet(ds, 0x2f0f, 0xc2);
    memoryASet(ds, 0x2f0e, 0xbd);
    memoryASet(ds, 0x2f0d, 0xb8);
    memoryASet(ds, 0x2f0c, 0xb3);
loc_2cb2c:
    if (memoryAGet(ds, 0x2f0c) == 0x0c)
        goto loc_2cb77;
    al = memoryAGet(ds, 0x2f0c);
    al -= 0x07;
    sub_2cbe1();
    cx = 0;
loc_2cb3d:
    push(cx);
    cx <<= 1;
    cx <<= 1;
    si = 0x2efc;
    si += cx;
    memoryASet(ds, si, memoryAGet(ds, si) + 1);
    dl = memoryAGet(ds, si + 1);
    if (dl != memoryAGet(ds, si))
        goto loc_2cb66;
    memoryASet(ds, si, 0x00);
    cx = pop();
    push(cx);
    di = 0x2f0c;
    di += cx;
    memoryASet(ds, di, memoryAGet(ds, di) - 1);
    al = memoryAGet(ds, di);
    bl = 0x60;
    si = memoryAGet16(ds, si + 2);
    sub_2ccd9();
loc_2cb66:
    cx = pop();
    cx++;
    if (cx != 0x0004)
        goto loc_2cb3d;
    cx = 0x000a;
loc_2cb70:
    sub_2c26c();
    if (--cx)
        goto loc_2cb70;
    goto loc_2cb2c;
loc_2cb77:
    if (memoryAGet(ds, 0x2f0c) == 0xb3)
        goto loc_2cbce;
    al = memoryAGet(ds, 0x2f0c);
    al -= 0x06;
    push(ax);
    sub_2cc54();
    ax = pop();
    ax++;
    sub_2cbe1();
    cx = 0x0003;
loc_2cb8f:
    bp = cx;
    cx <<= 1;
    cx <<= 1;
    si = 0x2efc;
    si += cx;
    push(si);
    if (memoryAGet(ds, si) != 0x00)
        goto loc_2cbb8;
    dl = memoryAGet(ds, si + 1);
    memoryASet(ds, si, dl);
    cx = bp;
    di = 0x2f0c;
    di += cx;
    memoryASet(ds, di, memoryAGet(ds, di) + 1);
    al = memoryAGet(ds, di);
    bl = 0x60;
    si = memoryAGet16(ds, si + 2);
    sub_2ccd9();
loc_2cbb8:
    si = pop();
    memoryASet(ds, si, memoryAGet(ds, si) - 1);
    cx = bp;
    cx--;
    if (cx != 0xffff)
        goto loc_2cb8f;
    cx = 0x000a;
loc_2cbc7:
    sub_2c26c();
    if (--cx)
        goto loc_2cbc7;
    goto loc_2cb77;
loc_2cbce:
    cx = 0x001b;
loc_2cbd1:
    push(cx);
    sub_2cd68();
    cx = 0x000c;
loc_2cbd8:
    sub_2c26c();
    if (--cx)
        goto loc_2cbd8;
    cx = pop();
    if (--cx)
        goto loc_2cbd1;
}
void sub_2cbe1()
{
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    di = 0;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2cbf2;
    di += 0x2000;
loc_2cbf2:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    di += 0x0002;
    si = 0x6d95;
    bh = 0;
    bl = memoryAGet(ds, 0x2efb);
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bx <<= 1;
    si += bx;
    si = memoryAGet16(ds, si);
    dh = 0x08;
loc_2cc1a:
    push(di);
    cx = 0x0018;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2cc2d;
    di -= 0x1fb0;
    goto loc_2cc31;
loc_2cc2d:
    di += 0x2000;
loc_2cc31:
    dh--;
    if (dh != 0)
        goto loc_2cc1a;
    es = pop();
    flags.interrupts = true;
    al = memoryAGet(ds, 0x2efb);
    flags.carry = al & 1;
    al >>= 1;
    if (flags.carry)
        goto loc_2cc4f;
    flags.carry = al & 1;
    al >>= 1;
    if (flags.carry)
        goto loc_2cc4f;
    flags.carry = al & 1;
    al >>= 1;
    if (flags.carry)
        goto loc_2cc4f;
    if (al != 0x04)
        goto loc_2cc4f;
    memoryASet(ds, 0x2efb, 0xff);
loc_2cc4f:
    memoryASet(ds, 0x2efb, memoryAGet(ds, 0x2efb) + 1);
}
void sub_2cc54()
{
    flags.interrupts = false;
    push(es);
    push(ax);
    dx = 0xb800;
    es = dx;
    di = 0;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2cc66;
    di += 0x2000;
loc_2cc66:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    di += 0x0002;
    ax = pop();
    al -= 0x06;
    bl = al;
    dl = al;
    dl &= 0x07;
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    si = 0x2f18;
    ah = 0;
    cl = 0x03;
    al >>= cl;
    cl = 0x0c;
    mul(cl);
    si += ax;
    cl = 0x00;
loc_2cc98:
    push(si);
    ah = 0;
    al = memoryAGet(ds, si);
    if (al != 0x0c)
        goto loc_2cca9;
    al = bl;
    sub_2ee05();
    goto loc_2ccce;
loc_2cca9:
    ax <<= 1;
    si = 0x3080;
    si += ax;
    si = memoryAGet16(ds, si);
    if (ax < 0x0030)
        goto loc_2ccbf;
    push(ds);
    push(ax);
    ax = 0x24a1;
    ds = ax;
    ax = pop();
loc_2ccbf:
    si += dx;
    push(cx);
    cx = 0x0002;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    if (ax < 0x0030)
        goto loc_2ccce;
    ds = pop();
loc_2ccce:
    si = pop();
    si++;
    cl++;
    if (cl != 0x0c)
        goto loc_2cc98;
    es = pop();
}
void sub_2ccd9()
{
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    bh = 0;
    di = bx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2ccf0;
    di += 0x2000;
loc_2ccf0:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cl = 0x06;
loc_2cd00:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, ax);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 4, al);
    if (di < 0x2000)
        goto loc_2cd1e;
    di -= 0x1fb0;
    cl--;
    if (cl != 0)
        goto loc_2cd00;
    goto loc_2cd26;
loc_2cd1e:
    di += 0x2000;
    cl--;
    if (cl != 0)
        goto loc_2cd00;
loc_2cd26:
    es = pop();
    flags.interrupts = true;
}
void sub_2cd29()
{
    push(es);
    push(ds);
    ax = 0xb800;
    es = ax;
    ds = ax;
    di = 0x1ae2;
    dl = 0x1b;
loc_2cd37:
    push(di);
    si = di;
    if (si < 0x2000)
        goto loc_2cd47;
    si -= 0x1fb0;
    goto loc_2cd4b;
loc_2cd47:
    si += 0x2000;
loc_2cd4b:
    cx = 0x0018;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2cd5d;
    di -= 0x1fb0;
    goto loc_2cd61;
loc_2cd5d:
    di += 0x2000;
loc_2cd61:
    dl--;
    if (dl != 0)
        goto loc_2cd37;
    ds = pop();
    es = pop();
}
void sub_2cd68()
{
    push(es);
    push(ds);
    ax = 0xb800;
    es = ax;
    ds = ax;
    si = 0x1ef2;
    dl = 0x1b;
loc_2cd76:
    push(si);
    di = si;
    if (di < 0x2000)
        goto loc_2cd85;
    di -= 0x1fb0;
    goto loc_2cd89;
loc_2cd85:
    di += 0x2000;
loc_2cd89:
    cx = 0x0018;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = pop();
    if (si < 0x2000)
        goto loc_2cd9c;
    si -= 0x2000;
    goto loc_2cda0;
loc_2cd9c:
    si += 0x1fb0;
loc_2cda0:
    dl--;
    if (dl != 0)
        goto loc_2cd76;
    ds = pop();
    es = pop();
}
void sub_2cda7()
{
    if (memoryAGet(ds, 0x2d3b) != 0x00)
        goto loc_2cdb8;
    al = memoryAGet(ds, 0x2e55);
    if (memoryAGet(ds, 0x2e54) != al)
        goto loc_2cdb8;
    return;
loc_2cdb8:
    memoryASet16(ds, 0x1487, memoryAGet16(ds, 0x1487) - 0x01f3);
    bp = si;
    di = 0x2e65;
    si = 0x2e57;
    cx = 0x0007;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = 0x2d8c;
    di = 0x2ddc;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x2e57;
    bl = memoryAGet(ds, 0x2e54);
    memoryASet(ds, 0x2e55, bl);
    dl = bl;
    sub_2cefe();
    si = bp;
    di = 0x2d8c;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    dl &= 0x03;
    if (dl == 0)
        goto loc_2ce27;
    dl <<= 1;
loc_2cdf7:
    di = 0x2d8c;
    cl = 0x07;
loc_2cdfc:
    flags.carry = memoryAGet(ds, di) & 1;
    memoryASet(ds, di, memoryAGet(ds, di) >> 1);
    memoryASet(ds, di + 1, rcr(memoryAGet(ds, di + 1), 0x01));
    memoryASet(ds, di + 2, rcr(memoryAGet(ds, di + 2), 0x01));
    memoryASet(ds, di + 3, rcr(memoryAGet(ds, di + 3), 0x01));
    memoryASet(ds, di + 4, rcr(memoryAGet(ds, di + 4), 0x01));
    memoryASet(ds, di + 5, rcr(memoryAGet(ds, di + 5), 0x01));
    memoryASet(ds, di + 6, rcr(memoryAGet(ds, di + 6), 0x01));
    memoryASet(ds, di + 7, rcr(memoryAGet(ds, di + 7), 0x01));
    memoryASet(ds, di + 8, rcr(memoryAGet(ds, di + 8), 0x01));
    memoryASet(ds, di + 9, rcr(memoryAGet(ds, di + 9), 0x01));
    memoryASet(ds, di + 10, rcr(memoryAGet(ds, di + 10), 0x01));
    di += 0x000b;
    cl--;
    if (cl != 0)
        goto loc_2cdfc;
    dl--;
    if (dl != 0)
        goto loc_2cdf7;
loc_2ce27:
    si = 0x2ddc;
    di = 0x2e65;
    sub_2cea1();
    si = 0x2d8c;
    di = 0x2e57;
    sub_2cea1();
}
void sub_2ce3a()
{
    if (memoryAGet(ds, 0x2d3b) != 0x00)
        goto loc_2ce4b;
    al = memoryAGet(ds, 0x2e55);
    if (memoryAGet(ds, 0x2e54) != al)
        goto loc_2ce4b;
    return;
loc_2ce4b:
    memoryASet16(ds, 0x1487, memoryAGet16(ds, 0x1487) - 0x01e0);
    bp = si;
    di = 0x2e65;
    si = 0x2e57;
    cx = 0x0007;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = 0x2d8c;
    di = 0x2ddc;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x2e57;
    bl = memoryAGet(ds, 0x2e54);
    memoryASet(ds, 0x2e55, bl);
    dl = bl;
    sub_2cefe();
    si = bp;
    dl &= 0x03;
    if (dl == 0)
        goto loc_2ce86;
    al = 0x4d;
    mul(dl);
    si += ax;
loc_2ce86:
    di = 0x2d8c;
    cx = 0x0027;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = 0x2ddc;
    di = 0x2e65;
    sub_2cea1();
    si = 0x2d8c;
    di = 0x2e57;
    sub_2cea1();
}
void sub_2cea1()
{
    flags.interrupts = false;
    bp = es;
    ax = 0xb800;
    es = ax;
    cx = 0x0007;
loc_2ceac:
    dx = cx;
    bx = memoryAGet16(ds, di);
    cx = 0x0005;
loc_2ceb3:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, bx, memoryAGet16(es, bx) ^ ax);
    bx++;
    bx++;
    if (--cx)
        goto loc_2ceb3;
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, bx, memoryAGet(es, bx) ^ al);
    di++;
    di++;
    cx = dx;
    if (--cx)
        goto loc_2ceac;
    es = bp;
    flags.interrupts = true;
}
void sub_2cec9()
{
    push(es);
    ax = 0xb800;
    es = ax;
    bl = memoryAGet(ds, 0x2e54);
    bh = 0;
    bl >>= 1;
    bl >>= 1;
    bx += 0x1cc0;
    di = bx;
    dl = 0x10;
loc_2cee1:
    push(di);
    cx = 0x0007;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    if (di < 0x2000)
        goto loc_2cef4;
    di -= 0x1fb0;
    goto loc_2cef8;
loc_2cef4:
    di += 0x2000;
loc_2cef8:
    dl--;
    if (dl != 0)
        goto loc_2cee1;
    es = pop();
}
void sub_2cefe()
{
    al = bl;
    ah = 0;
    al >>= 1;
    al >>= 1;
    ax += 0x1cc0;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax += 0x2000;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax -= 0x1fb0;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax += 0x2000;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax -= 0x1fb0;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax += 0x2000;
    memoryASet16(ds, di, ax);
    di++;
    di++;
    ax -= 0x1fb0;
    memoryASet16(ds, di, ax);
}
void sub_2cf36()
{
    al = memoryAGet(ds, si + 1);
    if (al >= 0xb5)
        goto loc_2cf3e;
loc_2cf3d:
    return;
loc_2cf3e:
    if (al == 0xb5)
        goto loc_2cfbf;
    if (al > 0xbe)
        goto loc_2cf3d;
    if (memoryAGet(ds, si + 21) == 0x01)
        goto loc_2cfbf;
    ah = memoryAGet(ds, 0x2e54);
    ah -= 0x03;
    bl = memoryAGet(ds, si);
    cl = 0x01;
    if (bl == ah)
        goto loc_2cf68;
    bl -= ah;
    ah = memoryAGet(ds, 0x2d3a);
    ah += 0x03;
    if (bl != ah)
        goto loc_2cf3d;
    cl = 0x00;
loc_2cf68:
    al -= 0xb6;
    if (al > 0x05)
        goto loc_2cf74;
    memoryASet(ds, si + 21, 0x01);
    goto loc_2cf78;
loc_2cf74:
    memoryASet(ds, si + 21, 0x00);
loc_2cf78:
    memoryASet(ds, si + 20, cl);
    if (cl)
        goto loc_2cf8b;
    ah = memoryAGet(ds, 0x2e54);
    ah += memoryAGet(ds, 0x2d3a);
    ah++;
    goto loc_2cf92;
loc_2cf8b:
    ah = memoryAGet(ds, 0x2e54);
    ah -= 0x04;
loc_2cf92:
    memoryASet(ds, si + 24, ah);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, ah);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 29, 0x00);
    ah = 0;
    al <<= 1;
    di = 0x2e42;
    di += ax;
    ax = memoryAGet16(ds, di);
    memoryASet(ds, si + 23, ah);
    memoryASet(ds, si + 22, al);
    memoryASet(cs, 0x00f4, 0x01);
loc_2cfbe:
    return;
loc_2cfbf:
    al = memoryAGet(ds, 0x2e54);
    al -= 0x03;
    bl = memoryAGet(ds, si);
    if (bl < al)
        goto loc_2cfbe;
    bl -= al;
    if (bl > 0x0a)
        goto loc_2d018;
    bh = 0;
    bl <<= 1;
    di = 0x2e2c;
    di += bx;
    ax = memoryAGet16(ds, di);
    memoryASet(ds, si + 23, ah);
    memoryASet(ds, si + 22, al);
    memoryASet(ds, si + 20, 0x01);
    ah = memoryAGet(ds, si + 1);
    if (memoryAGet(ds, si + 1) == 0xbe)
        goto loc_2cff7;
    memoryASet(ds, si + 21, 0x01);
    ah--;
    goto loc_2cffd;
loc_2cff7:
    memoryASet(ds, si + 21, 0x00);
    ah++;
loc_2cffd:
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, ah);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 29, 0x00);
    memoryASet(cs, 0x00f4, 0x01);
    return;
loc_2d018:
    al = memoryAGet(ds, 0x2d3a);
    al += 0x03;
    if (bl > al)
        goto loc_2cfbe;
    al -= bl;
    if (al > 0x0a)
        goto loc_2d06d;
    ah = 0;
    al <<= 1;
    di = 0x2e2c;
    di += ax;
    bx = memoryAGet16(ds, di);
    memoryASet(ds, si + 23, bh);
    memoryASet(ds, si + 22, bl);
    memoryASet(ds, si + 20, 0x00);
    ah = memoryAGet(ds, si + 1);
    if (ah == 0xbe)
        goto loc_2d04c;
    memoryASet(ds, si + 21, 0x01);
    ah--;
    goto loc_2d052;
loc_2d04c:
    memoryASet(ds, si + 21, 0x00);
    ah++;
loc_2d052:
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, ah);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 29, 0x00);
    memoryASet(cs, 0x00f4, 0x01);
    return;
loc_2d06d:
    ah = memoryAGet(ds, si + 1);
    if (memoryAGet(ds, si + 1) == 0xbe)
        goto loc_2d07e;
    memoryASet(ds, si + 21, 0x01);
    ah--;
    goto loc_2d084;
loc_2d07e:
    memoryASet(ds, si + 21, 0x00);
    ah++;
loc_2d084:
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, ah);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 29, 0x00);
    memoryASet(cs, 0x00f4, 0x01);
}
void sub_2d09f()
{
    if (memoryAGet(ds, si + 29) < 0x23)
        goto loc_2d0c7;
    memoryASet(ds, si + 29, 0x00);
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, si + 24, ax);
    memoryASet16(ds, si + 26, 0x0000);
    dl = 0x05;
    sub_2ece0();
    ah++;
    memoryASet(ds, si + 22, ah);
    dl = 0x05;
    sub_2ece0();
    ah++;
    memoryASet(ds, si + 23, ah);
loc_2d0c7:
    al = memoryAGet(ds, si);
    bl = memoryAGet(ds, si + 1);
    if (al > 0x08)
        goto loc_2d0de;
    memoryASet(cs, 0x00f4, 0x02);
    memoryASet(ds, si + 20, 0x00);
    dl = 0x09;
    goto loc_2d0ee;
loc_2d0de:
    if (al < 0xc4)
        goto loc_2d0ff;
    memoryASet(cs, 0x00f4, 0x02);
    memoryASet(ds, si + 20, 0x01);
    dl = 0xc3;
loc_2d0ee:
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x00);
    memoryASet(ds, si + 24, dl);
    memoryASet(ds, si + 25, bl);
    memoryASet(ds, si + 29, memoryAGet(ds, si + 29) + 1);
loc_2d0ff:
    if (bl > 0x04)
        goto loc_2d123;
    memoryASet(cs, 0x00f4, 0x02);
    memoryASet(ds, si + 21, 0x00);
    dl = bl;
    dl++;
    memoryASet(ds, si + 29, memoryAGet(ds, si + 29) + 1);
    memoryASet(ds, si + 26, 0x00);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, dl);
loc_2d123:
    sub_2d16d();
    if (memoryAGet(ds, si + 1) == 0xc4)
        goto loc_2d131;
    sub_2cf36();
    flags.carry = false;
    return;
loc_2d131:
    if (memoryAGet(ds, 0x2e81) == 0x01)
        goto loc_2d150;
    bl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 28, 0x00);
    bp = si;
    si += 0x0004;
    sub_2d4a1();
    si = bp;
    memoryASet(ds, 0x2e73, memoryAGet(ds, 0x2e73) - 1);
    return;
loc_2d150:
    memoryASet(cs, 0x00f4, 0x02);
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, 0xc3);
    memoryASet(ds, si + 21, 0x01);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    flags.carry = false;
}
void sub_2d16d()
{
    bp = si;
    memoryASet(ds, 0x2e74, 0x00);
    si = 0x2e89;
    al -= 0x08;
    bl -= 0x06;
    sub_2d375();
    al += 0x03;
    sub_2d375();
    bl += 0x03;
    sub_2d375();
    al -= 0x03;
    sub_2d375();
    si = bp;
    al = memoryAGet(ds, 0x2e74);
    if (al)
        goto loc_2d199;
    return;
loc_2d199:
    if (al != 0x02)
        goto loc_2d1a0;
    goto loc_2d225;
loc_2d1a0:
    if (al == 0x03)
        goto loc_2d1e3;
    di = 0x2e99;
    si = 0x2e89;
loc_2d1aa:
    if (memoryAGet16(ds, si) != 0x0000)
        goto loc_2d1b7;
    si += 0x0004;
    di += 0x0002;
    goto loc_2d1aa;
loc_2d1b7:
    si = bp;
    dx = memoryAGet16(ds, di);
    memoryASet(ds, si + 21, dh);
    memoryASet(ds, si + 20, dl);
    al = memoryAGet(ds, si + 1);
    bl = memoryAGet(ds, si);
    if (!dh)
        goto loc_2d1ce;
    al--;
    goto loc_2d1d0;
loc_2d1ce:
    al++;
loc_2d1d0:
    memoryASet(ds, si + 25, al);
    if (!dl)
        goto loc_2d1db;
    bl--;
    goto loc_2d1dd;
loc_2d1db:
    bl++;
loc_2d1dd:
    memoryASet(ds, si + 24, bl);
    goto loc_2d2fd;
loc_2d1e3:
    if (memoryAGet(ds, si + 20) != 0x00)
        goto loc_2d1f6;
    memoryASet(ds, si + 20, 0x01);
    bl = memoryAGet(ds, si);
    bl--;
    memoryASet(ds, si + 24, bl);
    goto loc_2d201;
loc_2d1f6:
    memoryASet(ds, si + 20, 0x00);
    bl = memoryAGet(ds, si);
    bl++;
    memoryASet(ds, si + 24, bl);
loc_2d201:
    if (memoryAGet(ds, si + 21) != 0x00)
        goto loc_2d216;
    memoryASet(ds, si + 21, 0x01);
    al = memoryAGet(ds, si + 1);
    al--;
    memoryASet(ds, si + 25, al);
    goto loc_2d2fd;
loc_2d216:
    memoryASet(ds, si + 21, 0x00);
    al = memoryAGet(ds, si + 1);
    al++;
    memoryASet(ds, si + 25, al);
    goto loc_2d2fd;
loc_2d225:
    if (memoryAGet16(ds, 0x2e89) == 0x0000)
        goto loc_2d296;
    if (memoryAGet16(ds, 0x2e91) == 0x0000)
        goto loc_2d235;
    goto loc_2d1e3;
loc_2d235:
    if (memoryAGet16(ds, 0x2e8d) == 0x0000)
        goto loc_2d26a;
    if (memoryAGet(ds, si + 21) != 0x00)
        goto loc_2d256;
    memoryASet(ds, si + 21, 0x01);
    al = memoryAGet(ds, si + 1);
    al--;
    memoryASet(ds, si + 25, al);
    bl = memoryAGet(ds, si);
    memoryASet(ds, si + 24, bl);
    goto loc_2d2fd;
loc_2d256:
    memoryASet(ds, si + 21, 0x00);
    al = memoryAGet(ds, si + 1);
    al++;
    memoryASet(ds, si + 25, al);
    bl = memoryAGet(ds, si);
    memoryASet(ds, si + 24, bl);
    goto loc_2d2fd;
loc_2d26a:
    if (memoryAGet(ds, si + 20) != 0x00)
        goto loc_2d283;
    memoryASet(ds, si + 20, 0x01);
    bl = memoryAGet(ds, si);
    bl--;
    memoryASet(ds, si + 24, bl);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, al);
    goto loc_2d2fd;
loc_2d283:
    memoryASet(ds, si + 20, 0x00);
    bl = memoryAGet(ds, si);
    bl++;
    memoryASet(ds, si + 24, bl);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, al);
    goto loc_2d2fd;
loc_2d296:
    if (memoryAGet16(ds, 0x2e8d) == 0x0000)
        goto loc_2d2a7;
    if (memoryAGet16(ds, 0x2e99) == 0x0000)
        goto loc_2d2d3;
    goto loc_2d1e3;
loc_2d2a7:
    if (memoryAGet(ds, si + 21) != 0x00)
        goto loc_2d2c0;
    al = memoryAGet(ds, si + 1);
    al--;
    memoryASet(ds, si + 25, al);
    bl = memoryAGet(ds, si);
    memoryASet(ds, si + 24, bl);
    memoryASet(ds, si + 21, 0x01);
    goto loc_2d2fd;
loc_2d2c0:
    memoryASet(ds, si + 21, 0x00);
    al = memoryAGet(ds, si + 1);
    al++;
    memoryASet(ds, si + 25, al);
    bl = memoryAGet(ds, si);
    memoryASet(ds, si + 24, bl);
    goto loc_2d2fd;
loc_2d2d3:
    if (memoryAGet(ds, si + 20) != 0x00)
        goto loc_2d2ec;
    bl = memoryAGet(ds, si);
    bl--;
    memoryASet(ds, si + 24, bl);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, al);
    memoryASet(ds, si + 20, 0x01);
    goto loc_2d2fd;
loc_2d2ec:
    memoryASet(ds, si + 20, 0x00);
    bl = memoryAGet(ds, si);
    bl++;
    memoryASet(ds, si + 24, bl);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, al);
loc_2d2fd:
    if (memoryAGet(ds, 0x2e74) != 0x03)
        goto loc_2d32e;
    if (memoryAGet16(ds, 0x2e89) == 0x0000)
        goto loc_2d328;
    if (memoryAGet16(ds, 0x2e91) == 0x0000)
        goto loc_2d320;
    memoryASet16(ds, 0x2e8d, 0x0000);
    memoryASet16(ds, 0x2e95, 0x0000);
    goto loc_2d32e;
loc_2d320:
    memoryASet16(ds, 0x2e89, 0x0000);
    goto loc_2d32e;
loc_2d328:
    memoryASet16(ds, 0x2e91, 0x0000);
loc_2d32e:
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    si = 0x2e89;
    cx = 0x0003;
loc_2d33c:
    ax = memoryAGet16(ds, si);
    if (ax)
        goto loc_2d349;
    si += 0x0004;
    if (--cx)
        goto loc_2d33c;
    goto loc_2d351;
loc_2d349:
    sub_2d3d7();
    si += 0x0004;
    if (--cx)
        goto loc_2d33c;
loc_2d351:
    cx = 0x0004;
    si = 0x2e89;
loc_2d357:
    push(cx);
    push(si);
    di = memoryAGet16(ds, si);
    if (!di)
        goto loc_2d36b;
    bh = 0;
    bl = memoryAGet(ds, di);
    bx <<= 1;
    bx += 0x3044;
    callIndirect(cs, memoryAGet16(ds, bx));
loc_2d36b:
    si = pop();
    cx = pop();
    si += 0x0004;
    if (--cx)
        goto loc_2d357;
    si = bp;
}
void sub_2d375()
{
    cx = ax;
    dx = bx;
    if (al > 0xbf)
        goto loc_2d3a7;
    if (bl > 0xc4)
        goto loc_2d3a7;
    bh = 0;
    bl &= 0xf8;
    di = bx;
    bl >>= 1;
    di += bx;
    ah = 0;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    di += ax;
    di += 0x2f18;
    al = memoryAGet(ds, di);
    if (al == 0x0c)
        goto loc_2d3a7;
    if (al)
        goto loc_2d3b3;
loc_2d3a7:
    memoryASet16(ds, si, 0x0000);
    si += 0x0004;
    ax = cx;
    bx = dx;
    return;
loc_2d3b3:
    memoryASet16(ds, si, di);
    memoryASet(ds, 0x2e74, memoryAGet(ds, 0x2e74) + 1);
    ax = cx;
    bx = dx;
    ah = al;
    ah &= 0xf0;
    bh = bl;
    bh &= 0xf8;
    ah += 0x08;
    bh += 0x06;
    memoryASet(ds, si + 2, ah);
    memoryASet(ds, si + 3, bh);
    si += 0x0004;
}
void sub_2d3d7()
{
    dx = cx;
    ax = memoryAGet16(ds, si + 2);
    di = si;
loc_2d3de:
    di += 0x0004;
    if (memoryAGet16(ds, di) == 0x0000)
        goto loc_2d3eb;
    if (memoryAGet16(ds, di + 2) == ax)
        goto loc_2d3f0;
loc_2d3eb:
    if (--cx)
        goto loc_2d3de;
    cx = dx;
    return;
loc_2d3f0:
    memoryASet16(ds, di, 0x0000);
    cx = dx;
}
void sub_2d3f7()
{
    ch = memoryAGet(ds, si + 26);
    cl = memoryAGet(ds, si + 27);
    al = memoryAGet(ds, si + 23);
    if (al < memoryAGet(ds, si + 22))
        goto loc_2d418;
    al = ch;
    bl = memoryAGet(ds, si + 22);
    mul(bl);
    bl = memoryAGet(ds, si + 23);
    div(bl);
    bl = ch;
    memoryASet(ds, si + 26, memoryAGet(ds, si + 26) + 1);
    goto loc_2d42b;
loc_2d418:
    al = cl;
    bl = memoryAGet(ds, si + 23);
    mul(bl);
    bl = memoryAGet(ds, si + 22);
    div(bl);
    bl = al;
    al = cl;
    memoryASet(ds, si + 27, memoryAGet(ds, si + 27) + 1);
loc_2d42b:
    if (memoryAGet(ds, si + 20) == 0x00)
        goto loc_2d433;
    bl = -bl;
loc_2d433:
    if (memoryAGet(ds, si + 21) == 0x00)
        goto loc_2d43b;
    al = -al;
loc_2d43b:
    bl += memoryAGet(ds, si + 24);
    memoryASet(ds, si, bl);
    al += memoryAGet(ds, si + 25);
    memoryASet(ds, si + 1, al);
}
void sub_2d447()
{
    bp = si;
    si += 0x0004;
    di = bp;
    di += 0x000c;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = 0x48fb;
    di = bp;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = bp;
    dl = memoryAGet(ds, si);
    dl &= 0x03;
    if (dl == 0)
        goto loc_2d47f;
    dl <<= 1;
    dh = 0x04;
    di = bp;
    di += 0x0004;
loc_2d475:
    cl = dl;
    memoryASet16(ds, di, ror(memoryAGet16(ds, di), cl));
    di++;
    di++;
    dh--;
    if (dh != 0)
        goto loc_2d475;
loc_2d47f:
    bl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    si += 0x000c;
    sub_2d4a1();
    si = bp;
    bl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 2, bl);
    memoryASet(ds, si + 3, al);
    si += 0x0004;
    sub_2d4a1();
    si = bp;
}
void sub_2d4a1()
{
    flags.interrupts = false;
    dx = es;
    cx = 0xb800;
    es = cx;
    bh = 0;
    di = bx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2d4b9;
    di += 0x2000;
loc_2d4b9:
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = 0x0004;
loc_2d4ce:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    if (di < 0x2000)
        goto loc_2d4e1;
    di -= 0x1fb0;
    if (--cx)
        goto loc_2d4ce;
    es = dx;
    flags.carry = false;
    return;
loc_2d4e1:
    di += 0x2000;
    if (--cx)
        goto loc_2d4ce;
    es = dx;
    flags.interrupts = true;
    flags.carry = false;
    sync();
}

void sub_2d4eb()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0002);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    if (!bp)
        goto loc_2d510;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d510:
    if (memoryAGet(ds, 0x3384) >= 0x03)
        goto loc_2d520;
    dl = 0x03;
    sub_2ece0();
    if (!ah)
        goto loc_2d549;
loc_2d520:
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x3b2a);
    bx = memoryAGet16(ds, di);
    memoryASet(ds, bx, 0x00);
    memoryASet16(ds, si + 2, bx);
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, 0x65fe);
    memoryASet(ds, si + 8, 0x07);
    memoryASet(ds, si + 9, 0x07);
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    return;
loc_2d549:
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x00);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    push(si);
    si = 0x6426;
    sub_2e784();
    si = pop();
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x3561);
    bx = memoryAGet16(ds, di + 2);
    bh++;
    al = bh;
    memoryASet16(ds, si + 2, bx);
    push(ax);
    dl = 0xff;
    sub_2ece0();
    di = 0x33b1;
    al = 0;
loc_2d57e:
    if (memoryAGet(ds, di) >= ah)
        goto loc_2d587;
    al++;
    di++;
    goto loc_2d57e;
loc_2d587:
    memoryASet(ds, si + 4, al);
    ax = pop();
    memoryASet(ds, si + 5, 0x00);
    memoryASet(ds, si + 6, 0x00);
    memoryASet(ds, si + 7, 0x01);
    si = 0x5863;
    cx = 0x0006;
    sub_2ed12();
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) + 1);
}
void sub_2d5a5()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0002);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    if (!bp)
        goto loc_2d5ca;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d5ca:
    if (memoryAGet(ds, 0x3384) >= 0x03)
        goto loc_2d5da;
    dl = 0x03;
    sub_2ece0();
    if (!ah)
        goto loc_2d603;
loc_2d5da:
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x3b2a);
    bx = memoryAGet16(ds, di);
    memoryASet(ds, bx, 0x00);
    memoryASet16(ds, si + 2, bx);
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, 0x6508);
    memoryASet(ds, si + 8, 0x07);
    memoryASet(ds, si + 9, 0x07);
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    return;
loc_2d603:
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x00);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    push(si);
    si = 0x63a6;
    sub_2e784();
    si = pop();
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x3273);
    bx = memoryAGet16(ds, di + 2);
    bh++;
    al = bh;
    memoryASet16(ds, si + 2, bx);
    push(ax);
    dl = 0xff;
    sub_2ece0();
    di = 0x33b1;
    al = 0;
loc_2d638:
    if (memoryAGet(ds, di) >= ah)
        goto loc_2d641;
    al++;
    di++;
    goto loc_2d638;
loc_2d641:
    memoryASet(ds, si + 4, al);
    ax = pop();
    memoryASet(ds, si + 5, 0x00);
    memoryASet(ds, si + 6, 0x00);
    memoryASet(ds, si + 7, 0x01);
    si = 0x4e13;
    cx = 0x0006;
    sub_2ed12();
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) + 1);
}
void sub_2d65f()
{
    memoryASet(cs, 0x00f4, 0x04);
    if (!bp)
        goto loc_2d66e;
    di = bp;
    memoryASet(ds, di + 29, memoryAGet(ds, di + 29) + 1);
loc_2d66e:
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x365e);
    bx = memoryAGet16(ds, di);
    memoryASet(ds, bx, 0x04);
    memoryASet16(ds, si + 2, bx);
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, 0x66f4);
    memoryASet(ds, si + 8, 0x08);
    memoryASet(ds, si + 9, 0x08);
}
void sub_2d693()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0002);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    if (!bp)
        goto loc_2d6b8;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d6b8:
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x06);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    si = 0x6466;
    push(ax);
    push(cx);
    sub_2e784();
    cx = pop();
    ax = pop();
    si = 0x6486;
    sub_2e784();
}
void sub_2d6d4()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0003);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    if (!bp)
        goto loc_2d6f9;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d6f9:
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x07);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    si = 0x6486;
    push(ax);
    push(cx);
    sub_2e784();
    cx = pop();
    ax = pop();
    si = 0x64a6;
    sub_2e784();
}
void sub_2d715()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0005);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    if (!bp)
        goto loc_2d73a;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d73a:
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x08);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    si = 0x64a6;
    push(ax);
    push(cx);
    sub_2e784();
    cx = pop();
    ax = pop();
    si = 0x64c6;
    sub_2e784();
}
void sub_2d756()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0100);
    memoryASet16(ds, 0x1419, 0x0000);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x04);
    if (!bp)
        goto loc_2d77b;
    di = bp;
    memoryASet(ds, di + 29, 0x00);
loc_2d77b:
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x00);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    push(si);
    push(cx);
    push(ax);
    si = 0x64c6;
    sub_2e784();
    ax = pop();
    cx = pop();
    si = 0x681c;
    sub_2e784();
    si = pop();
    di = si;
    sub_2de52();
    memoryASet16(ds, si, 0x366f);
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, 0x67ea);
    memoryASet(ds, si + 8, 0x07);
    memoryASet(ds, si + 9, 0x07);
    memoryASet(ds, si + 2, 0x04);
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
}
void sub_2d7bd()
{
    if (bp)
        goto loc_2d7c2;
    return;
loc_2d7c2:
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0502);
    sub_2ed5d();
    push(si);
    cl = memoryAGet(ds, 0x2f11);
    si = 0x2f12;
loc_2d7df:
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    di = 0x2f18;
    di += ax;
    memoryASet(ds, di, 0x04);
    cl--;
    if (cl != 0)
        goto loc_2d7df;
    si = bp;
    memoryASet(ds, si + 28, 0x03);
    memoryASet(ds, si + 29, 0x00);
    bl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    si += 0x0004;
    sub_2d4a1();
    di = pop();
    sub_2de52();
    memoryASet16(ds, si, 0x3696);
    bx = memoryAGet16(ds, di);
    memoryASet16(ds, si + 2, bx);
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, 0x6abe);
    memoryASet(ds, si + 8, 0x32);
    memoryASet(ds, si + 9, 0x32);
loc_2d823:
    dl = memoryAGet(ds, 0x2f11);
    sub_2ece0();
    al = ah;
    si = 0x2f12;
    ah = 0;
    si += ax;
    al = memoryAGet(ds, si);
    si = 0x2f18;
    si += ax;
    if (si == memoryAGet16(ds, di))
        goto loc_2d823;
    sub_2de52();
    memoryASet16(ds, si, 0x36f6);
    memoryASet16(ds, si + 4, 0x0514);
    sub_2de52();
    memoryASet16(ds, si, 0x36a1);
    memoryASet16(ds, si + 2, bp);
    memoryASet16(ds, si + 6, 0x6ad0);
    memoryASet(ds, si + 8, 0x32);
    memoryASet(ds, si + 9, 0x32);
    cl = 0x0c;
    div(cl);
    cl = 0x04;
    ah <<= cl;
    cl = 0x03;
    al <<= cl;
    al += 0x06;
    ah += 0x08;
    memoryASet(ds, si + 5, al);
    memoryASet(ds, si + 4, ah);
}
void sub_2d879()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0005);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x00);
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    push(cx);
    push(ax);
    si = 0x63e6;
    sub_2e784();
    ax = pop();
    cx = pop();
    if (bp)
        goto loc_2d8b2;
    return;
loc_2d8b2:
    di = bp;
    memoryASet(ds, di + 29, 0x00);
    sub_2de52();
    memoryASet16(ds, si, 0x37e0);
    memoryASet16(ds, si + 2, bp);
    memoryASet16(ds, si + 6, 0x6b88);
    memoryASet(ds, si + 4, cl);
    memoryASet(ds, si + 5, al);
    memoryASet(ds, si + 8, 0x69);
    memoryASet(ds, si + 9, 0x69);
    si = 0x6b9c;
    sub_2eb6f();
    si = bp;
    bl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 28, 0x04);
    si += 0x0004;
    sub_2d4a1();
}
void sub_2d988()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0207);
    sub_2ed5d();
    memoryASet(cs, 0x00f4, 0x03);
    bx = memoryAGet16(ds, si);
    memoryASet(ds, bx, 0x0c);
    memoryASet(ds, 0x2f10, memoryAGet(ds, 0x2f10) - 1);
    cl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    push(ax);
    push(cx);
    si = 0x6406;
    sub_2e784();
    cx = pop();
    ax = pop();
    sub_2f86b();
}
void sub_2d9c0()
{
    sub_2edf4();
    ax = pop();
    ax = pop();
    ax = pop();
    ax = pop();
    goto loc_2ee30;
    //   gap of 5222 bytes
loc_2ee30:
    sub_2acb0();
    sub_2b355();
    dx = 0x03da;
loc_2ee39:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2ee39;
loc_2ee3e:
    in(al, dx);
    if (al & 0x08)
        goto loc_2ee3e;
    sub_2b531();
    ax = 0;
    memoryASet(ds, 0x2d39, al);
    di = 0x2d0d;
    ax = memoryAGet16(ds, di + 2);
    memoryASet(ds, 0x2d3f, 0xac);
    memoryASet(ds, 0x2d3e, 0x08);
    memoryASet(ds, 0x2d3a, al);
    di = 0x2e57;
    si = 0x2d8c;
    sub_2cea1();
    si = 0x20a0;
    dh = 0x70;
    memoryASet(ds, 0x2d3b, 0xff);
loc_2ee71:
    push(si);
    push(es);
    push(ds);
    ax = 0xb800;
    es = ax;
    ds = ax;
    push(dx);
    dx = 0x03da;
loc_2ee7f:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2ee7f;
loc_2ee84:
    in(al, dx);
    if (al & 0x08)
        goto loc_2ee84;
    dx = pop();
    dl = 0x06;
loc_2ee8c:
    push(si);
    di = si;
    if (di < 0x2000)
        goto loc_2ee9b;
    di -= 0x1fb0;
    goto loc_2ee9f;
loc_2ee9b:
    di += 0x2000;
loc_2ee9f:
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = pop();
    if (si < 0x2000)
        goto loc_2eeb2;
    si -= 0x2000;
    goto loc_2eeb6;
loc_2eeb2:
    si += 0x1fb0;
loc_2eeb6:
    dl--;
    if (dl != 0)
        goto loc_2ee8c;
    di = si;
    if (di < 0x2000)
        goto loc_2eec8;
    di -= 0x1fb0;
    goto loc_2eecc;
loc_2eec8:
    di += 0x2000;
loc_2eecc:
    if (dh != 0x70)
        goto loc_2eed4;
    di = 0x0000;
loc_2eed4:
    ax = 0x0000;
    cx = 0x001a;
    rep_stosw<MemAuto, DirAuto>();
    ds = pop();
    es = pop();
    cx = 0x0078;
loc_2eee1:
    sub_2f4cf();
    memoryASet(ds, 0x2d3b, 0x00);
    if (--cx)
        goto loc_2eee1;
    di = pop();
    if (di < 0x2000)
        goto loc_2eef8;
    di -= 0x1fb0;
    goto loc_2eefc;
loc_2eef8:
    di += 0x2000;
loc_2eefc:
    si = di;
    dh--;
    if (dh == 0)
        goto loc_2ef05;
    goto loc_2ee71;
loc_2ef05:
    si = 0x2b39;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2b6d;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x000c;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = memoryAGet16(ds, 0x13ca);
    si += 0x00b8;
    cx = 0x000e;
loc_2ef62:
    push(cx);
    push(es);
    cx = 0xb800;
    es = cx;
    di = 0x3130;
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    dl = 0x0c;
loc_2ef78:
    push(ds);
    cx = 0x1c46;
    ds = cx;
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    ax <<= 1;
    bx = 0x226c;
    bx += ax;
    al = memoryAGet(ds, bx);
    ds = pop();
    stosb<MemAuto, DirAuto>();
    dl--;
    if (dl != 0)
        goto loc_2ef78;
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
    push(si);
    sub_2f498();
    si = pop();
    si -= 0x000c;
    di = 0x3130;
    al = 0;
    push(es);
    cx = 0xb800;
    es = cx;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    dl = 0x0c;
loc_2efb8:
    push(ds);
    cx = 0x1c46;
    ds = cx;
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    ax <<= 1;
    bx = 0x226c;
    bx += ax;
    al = memoryAGet(ds, bx);
    ds = pop();
    stosb<MemAuto, DirAuto>();
    dl--;
    if (dl != 0)
        goto loc_2efb8;
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
    push(si);
    sub_2f498();
    push(es);
    cx = 0xb800;
    es = cx;
    di = 0x3130;
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x000c;
    rep_stosb<MemAuto, DirAuto>();
    al = 0x14;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0013;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = pop();
    cx = pop();
    cx--;
    if (cx == 0)
        goto loc_2f00f;
    goto loc_2ef62;
loc_2f00f:
    si = 0x2ba1;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2bd5;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2c09;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2c3d;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2c71;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2ca5;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    si = 0x2cd9;
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3130;
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    sub_2f498();
    dl = 0x30;
loc_2f0a4:
    di = 0x3130;
    push(es);
    ax = 0xb800;
    es = ax;
    al = 0;
    cx = 0x0017;
    rep_stosb<MemAuto, DirAuto>();
    bl = 0xd5;
    dh = dl;
    dh &= 0x03;
    if (dh != 0)
        goto loc_2f0bf;
    bl = 0xd1;
loc_2f0bf:
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0004;
    rep_stosb<MemAuto, DirAuto>();
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = 0;
    cx = 0x0017;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
    push(dx);
    sub_2f498();
    dx = pop();
    dl--;
    if (dl != 0)
        goto loc_2f0a4;
    di = 0x1198;
    bx = 0xffff;
    cx = 0xffff;
    dl = 0x08;
loc_2f0e8:
    push(di);
    push(es);
    ax = 0xb800;
    es = ax;
    bx <<= 1;
    bx <<= 1;
    cx >>= 1;
    cx >>= 1;
    dh = 0x04;
loc_2f0f9:
    ax = memoryAGet16(es, di);
    ah &= bl;
    al &= bh;
    memoryASet16(es, di, ax);
    ax = memoryAGet16(es, di + 2);
    ah &= cl;
    al &= ch;
    memoryASet16(es, di + 2, ax);
    if (di < 0x2000)
        goto loc_2f11b;
    di -= 0x1fb0;
    goto loc_2f11f;
loc_2f11b:
    di += 0x2000;
loc_2f11f:
    dh--;
    if (dh != 0)
        goto loc_2f0f9;
    es = pop();
    push(bx);
    push(cx);
    sub_2f4cf();
    cx = 0x0028;
loc_2f12c:
    sub_2c26c();
    if (--cx)
        goto loc_2f12c;
    cx = pop();
    bx = pop();
    di = pop();
    dl--;
    if (dl != 0)
        goto loc_2f0e8;
    si = 0x48fb;
    di = 0x2ea1;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x2ea1;
    memoryASet(ds, di, 0x70);
    memoryASet(ds, di + 2, 0x70);
    memoryASet(ds, di + 1, 0xb4);
    memoryASet(ds, di + 3, 0xb4);
    memoryASet(ds, di + 22, 0x01);
    memoryASet(ds, di + 23, 0x02);
    memoryASet(ds, di + 20, 0x00);
    memoryASet(ds, di + 21, 0x01);
    al = memoryAGet(ds, di);
    memoryASet(ds, di + 24, al);
    al = memoryAGet(ds, di + 1);
    memoryASet(ds, di + 25, al);
    memoryASet(ds, di + 26, 0x00);
    memoryASet(ds, di + 27, 0x00);
    memoryASet(ds, di + 28, 0x01);
    si = di;
    si += 0x0004;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    sub_2d4a1();
loc_2f18c:
    sub_2f4cf();
    si = 0x2ea1;
    sub_2d3f7();
    sub_2d447();
    sub_2f1c1();
    sub_2acb7();
    cx = 0x0009;
loc_2f1a1:
    sub_2c26c();
    if (--cx)
        goto loc_2f1a1;
    sub_2acb7();
    cx = 0x0009;
loc_2f1ac:
    sub_2c26c();
    if (--cx)
        goto loc_2f1ac;
    sub_2acb7();
    cx = 0x0009;
loc_2f1b7:
    sub_2c26c();
    if (--cx)
        goto loc_2f1b7;
    sub_2acb7();
    goto loc_2f18c;
}
void sub_2d9ca()
{
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0100);
    memoryASet16(ds, 0x1419, 0x0000);
    sub_2ed5d();
    if (memoryAGet(ds, 0x2e81) != 0x01)
        goto loc_2d9f9;
    dx = 0x1554;
    sub_2dd66();
    memoryASet(ds, 0x2e81, 0x00);
    di = 0x1a77;
    ax = 0;
    sub_2edd1();
loc_2d9f9:
    if (memoryAGet(ds, 0x2e79) == 0x01)
        goto loc_2da01;
    return;
loc_2da01:
    memoryASet(ds, 0x2e79, 0x00);
    di = 0x1a8b;
    ax = 0;
    sub_2edd1();
}
void sub_2da0f()
{
    if (memoryAGet(ds, 0x2e75) == 0x00)
        goto loc_2da17;
    return;
loc_2da17:
    memoryASet(ds, 0x2e75, 0x01);
    memoryASet16(ds, 0x2e76, 0x0230);
}
void sub_2da23()
{
    if (memoryAGet(ds, 0x2e7e) == 0x00)
        goto loc_2da2b;
    return;
loc_2da2b:
    memoryASet(ds, 0x2e7e, 0x01);
    memoryASet(ds, 0x2e7f, 0xb3);
}
void sub_2da36()
{
    sub_2de52();
    memoryASet16(ds, si, 0x3717);
}
void sub_2da3e()
{
    if (memoryAGet(ds, 0x2d3b) == 0x00)
        goto loc_2da47;
    flags.carry = true;
    return;
loc_2da47:
    if (memoryAGet16(ds, 0x2e76) != 0x0230)
        goto loc_2daa3;
    al = memoryAGet(ds, si + 1);
    if (al >= 0xb5)
        goto loc_2da5e;
loc_2da56:
    memoryASet16(ds, 0x2e76, 0x0230);
    flags.carry = true;
    return;
loc_2da5e:
    if (al > 0xbe)
        goto loc_2da56;
    ah = memoryAGet(ds, 0x2e54);
    ah -= 0x03;
    bl = memoryAGet(ds, si);
    if (bl < ah)
        goto loc_2da56;
    bl -= ah;
    ah = memoryAGet(ds, 0x2d3a);
    ah += 0x03;
    if (bl > ah)
        goto loc_2da56;
    memoryASet(ds, si + 1, 0xb5);
    memoryASet(ds, si + 28, 0x02);
    al = memoryAGet(ds, 0x1486);
    ah = 0;
    memoryASet16(ds, 0x2e76, memoryAGet16(ds, 0x2e76) - ax);
    al = memoryAGet(ds, si);
    al -= memoryAGet(ds, 0x2e54);
    memoryASet(ds, 0x2e56, al);
    push(si);
    sub_2d447();
    si = pop();
    memoryASet(cs, 0x00f4, 0x07);
    flags.carry = false;
    return;
loc_2daa3:
    if (memoryAGet(ds, si + 28) == 0x02)
        goto loc_2daab;
    flags.carry = true;
    return;
loc_2daab:
    if (memoryAGet(ds, 0x2d4c) == 0x01)
        goto loc_2dad9;
    memoryASet16(ds, 0x2e76, memoryAGet16(ds, 0x2e76) - 1);
    if (memoryAGet16(ds, 0x2e76) == 0)
        goto loc_2dad9;
    al = memoryAGet(ds, 0x1486);
    al--;
    if (al != memoryAGet(ds, 0x1485))
        goto loc_2dac9;
    memoryASet16(ds, 0x2e76, memoryAGet16(ds, 0x2e76) - 1);
    if (memoryAGet16(ds, 0x2e76) == 0)
        goto loc_2dad9;
loc_2dac9:
    al = memoryAGet(ds, 0x2e54);
    al += memoryAGet(ds, 0x2e56);
    memoryASet(ds, si, al);
    push(si);
    sub_2d447();
    si = pop();
    flags.carry = false;
    return;
loc_2dad9:
    memoryASet16(ds, 0x2e76, 0x0230);
    sub_2d09f();
    memoryASet(ds, si + 21, 0x01);
    memoryASet(ds, si + 1, 0xb4);
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, 0xb4);
    memoryASet16(ds, si + 26, 0x0000);
    memoryASet(ds, si + 28, 0x01);
    push(si);
    sub_2d447();
    si = pop();
    flags.carry = true;
}
void sub_2da75()
{
    goto loc_2da75;
loc_2da56:
    memoryASet16(ds, 0x2e76, 0x0230);
    flags.carry = true;
    return;
    //   gap of 23 bytes
loc_2da75:
    ah += 0x03;
    if (bl > ah)
        goto loc_2da56;
    memoryASet(ds, si + 1, 0xb5);
    memoryASet(ds, si + 28, 0x02);
    al = memoryAGet(ds, 0x1486);
    ah = 0;
    memoryASet16(ds, 0x2e76, memoryAGet16(ds, 0x2e76) - ax);
    al = memoryAGet(ds, si);
    al -= memoryAGet(ds, 0x2e54);
    memoryASet(ds, 0x2e56, al);
    push(si);
    sub_2d447();
    si = pop();
    memoryASet(cs, 0x00f4, 0x07);
    flags.carry = false;
}
void sub_2db03()
{
    if (memoryAGet(ds, 0x2d3b) != 0x00)
        goto loc_2db1b;
    if (memoryAGet(ds, 0x2e7e) != 0x02)
        goto loc_2db14;
    goto loc_2db9f;
loc_2db14:
    if (memoryAGet(ds, 0x2d4c) == 0x01)
        goto loc_2db1c;
loc_2db1b:
    return;
loc_2db1c:
    bl = memoryAGet(ds, 0x2e54);
    bl += 0x04;
    memoryASet(cs, 0x00f4, 0x05);
    memoryASet(ds, 0x2e80, bl);
    al = memoryAGet(ds, 0x2e7f);
    bp = bx;
    si = ax;
    sub_2dcfd();
    push(es);
    dx = 0xb800;
    es = dx;
    if (di < 0x2000)
        goto loc_2db49;
    di -= 0x1fb0;
    goto loc_2db4d;
loc_2db49:
    di += 0x2000;
loc_2db4d:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2db5c;
    di -= 0x1fb0;
    goto loc_2db60;
loc_2db5c:
    di += 0x2000;
loc_2db60:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    ax = si;
    bx = bp;
    bl += 0x13;
    sub_2dcfd();
    if (di < 0x2000)
        goto loc_2db79;
    di -= 0x1fb0;
    goto loc_2db7d;
loc_2db79:
    di += 0x2000;
loc_2db7d:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2db8c;
    di -= 0x1fb0;
    goto loc_2db90;
loc_2db8c:
    di += 0x2000;
loc_2db90:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    es = pop();
    memoryASet(ds, 0x2e7f, 0xb1);
    memoryASet(ds, 0x2e7e, 0x02);
    return;
loc_2db9f:
    bl = memoryAGet(ds, 0x2e80);
    al = memoryAGet(ds, 0x2e7f);
    si = ax;
    bp = bx;
    push(es);
    dx = 0xb800;
    es = dx;
    sub_2dcfd();
    if (di < 0x2000)
        goto loc_2dbbf;
    di -= 0x1fb0;
    goto loc_2dbc3;
loc_2dbbf:
    di += 0x2000;
loc_2dbc3:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di += 0x0050;
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2dbd8;
    di -= 0x1fb0;
    goto loc_2dbdc;
loc_2dbd8:
    di += 0x2000;
loc_2dbdc:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    ax = si;
    bx = bp;
    bl += 0x13;
    sub_2dcfd();
    if (di < 0x2000)
        goto loc_2dbf5;
    di -= 0x1fb0;
    goto loc_2dbf9;
loc_2dbf5:
    di += 0x2000;
loc_2dbf9:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di += 0x0050;
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2dc0e;
    di -= 0x1fb0;
    goto loc_2dc12;
loc_2dc0e:
    di += 0x2000;
loc_2dc12:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    es = pop();
    memoryASet(ds, 0x2e7f, memoryAGet(ds, 0x2e7f) - 1);
    memoryASet(ds, 0x2e7f, memoryAGet(ds, 0x2e7f) - 1);
    ax = si;
    if (al < 0x04)
        goto loc_2dc80;
    ax = si;
    bx = bp;
    tl = al;
    al = bl;
    bl = tl;
    al -= 0x08;
    bl -= 0x06;
    memoryASet(ds, 0x2e74, 0x00);
    si = 0x2e89;
    sub_2d375();
    al += 0x13;
    sub_2d375();
    if (memoryAGet(ds, 0x2e74) == 0x00)
        goto loc_2dc7f;
    bp = 0x0000;
    cl = 0x02;
    si = 0x2e89;
loc_2dc4e:
    push(cx);
    push(si);
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_2dc63;
    di = memoryAGet16(ds, si);
    bh = 0;
    bl = memoryAGet(ds, di);
    bl <<= 1;
    bx += 0x3044;
    callIndirect(cs, memoryAGet16(ds, bx));
loc_2dc63:
    si = pop();
    cx = pop();
    si += 0x0004;
    cl--;
    if (cl != 0)
        goto loc_2dc4e;
    al = memoryAGet(ds, 0x2e7f);
    al++;
    al++;
    bl = memoryAGet(ds, 0x2e80);
    sub_2dc8b();
    memoryASet(ds, 0x2e7f, 0xb3);
loc_2dc7f:
    return;
loc_2dc80:
    bx = bp;
    sub_2dc8b();
    memoryASet(ds, 0x2e7f, 0xb3);
}
void sub_2dc8b()
{
    push(bp);
    push(si);
    push(dx);
    push(cx);
    si = ax;
    bp = bx;
    sub_2dcfd();
    if (di < 0x2000)
        goto loc_2dca2;
    di -= 0x1fb0;
    goto loc_2dca6;
loc_2dca2:
    di += 0x2000;
loc_2dca6:
    push(es);
    dx = 0xb800;
    es = dx;
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2dcbb;
    di -= 0x1fb0;
    goto loc_2dcbf;
loc_2dcbb:
    di += 0x2000;
loc_2dcbf:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    ax = si;
    bx = bp;
    bl += 0x13;
    sub_2dcfd();
    if (di < 0x2000)
        goto loc_2dcd8;
    di -= 0x1fb0;
    goto loc_2dcdc;
loc_2dcd8:
    di += 0x2000;
loc_2dcdc:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    if (di < 0x2000)
        goto loc_2dceb;
    di -= 0x1fb0;
    goto loc_2dcef;
loc_2dceb:
    di += 0x2000;
loc_2dcef:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    es = pop();
    cx = pop();
    dx = pop();
    si = pop();
    bp = pop();
    memoryASet(ds, 0x2e7e, 0x01);
}
void sub_2dcfd()
{
    flags.interrupts = false;
    push(es);
    push(bx);
    dx = 0xb800;
    es = dx;
    bh = 0;
    di = bx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2dd15;
    di += 0x2000;
loc_2dd15:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    bx = pop();
    al = 0xc0;
    ch = 0;
    cl = bl;
    cl &= 0x03;
    cl <<= 1;
    if (cx == 0)
        goto loc_2dd33;
    al >>= cl;
loc_2dd33:
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    es = pop();
    flags.interrupts = true;
}
void sub_2dd39()
{
    if (memoryAGet(ds, 0x2e81) == 0x01)
        goto loc_2dd4b;
    memoryASet(ds, 0x2e81, 0x01);
    dx = 0x1554;
    sub_2dd66();
loc_2dd4b:
    memoryASet16(ds, 0x2e82, 0x1388);
    memoryASet(ds, 0x2e84, 0xc8);
    di = 0x1a77;
    ax = 0xaaaa;
    sub_2edd1();
    memoryASet16(ds, 0x2e85, 0x1a77);
}
void sub_2dd66()
{
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x3ef2;
    cx = 0x0018;
loc_2dd72:
    memoryASet16(es, di, memoryAGet16(es, di) ^ dx);
    di++;
    di++;
    if (--cx)
        goto loc_2dd72;
    es = pop();
}
void sub_2dd7b()
{
    push(si);
    si = 0x2ea1;
    cl = 0x03;
loc_2dd81:
    if (memoryAGet(ds, si + 28) == 0x00)
        goto loc_2dda2;
    if (memoryAGet(ds, si + 21) == 0x01)
        goto loc_2dd94;
    memoryASet(ds, si + 21, 0x01);
    goto loc_2dd98;
loc_2dd94:
    memoryASet(ds, si + 21, 0x00);
loc_2dd98:
    dx = memoryAGet16(ds, si);
    memoryASet16(ds, si + 24, dx);
    memoryASet16(ds, si + 26, 0x0000);
loc_2dda2:
    si += 0x001e;
    cl--;
    if (cl != 0)
        goto loc_2dd81;
    si = pop();
}
void sub_2ddab()
{
    if (memoryAGet(ds, 0x13c9) == 0x0c)
        return;
    push(bx);
    push(cx);
    push(si);
    push(di);
    si = 0x48e7;
    di = 0x3a7c;
    al = memoryAGet(ds, 0x13c9);
    al--;
    ah = 0;
    bl = al;
    bl &= 0x03;
    al &= 0xfc;
    di += ax;
    if (!bl)
        goto loc_2ddd8;
loc_2ddd0:
    di += 0x00f0;
    bl--;
    if (bl != 0)
        goto loc_2ddd0;
loc_2ddd8:
    push(es);
    ax = 0xb800;
    es = ax;
    ax = 0;
    dl = 0x05;
loc_2dde2:
    cx = 0x0002;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di -= 0x0004;
    if (di < 0x2000)
        goto loc_2ddf6;
    di -= 0x1fb0;
    goto loc_2ddfa;
loc_2ddf6:
    di += 0x2000;
loc_2ddfa:
    dl--;
    if (dl != 0)
        goto loc_2dde2;
    es = pop();
    di = pop();
    si = pop();
    cx = pop();
    bx = pop();
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) + 1);
}
void sub_2de08()
{
    al = memoryAGet(ds, 0x1486);
    if (al == 0x02)
        goto loc_2de19;
    memoryASet(ds, 0x1486, memoryAGet(ds, 0x1486) - 1);
    al = memoryAGet(ds, 0x1486);
    memoryASet(ds, 0x1485, al);
loc_2de19:
    memoryASet16(ds, 0x148b, 0x4e20);
}
void sub_2de20()
{
    memoryASet(ds, 0x2e79, 0x01);
    memoryASet16(ds, 0x2e7a, 0x2710);
    memoryASet16(ds, 0x2e7c, 0x0190);
    di = 0x1a8b;
    ax = 0xaaaa;
    sub_2edd1();
    memoryASet16(ds, 0x2e87, 0x1a8b);
}
void sub_2de41()
{
    memoryASet(cs, 0x00f4, 0x02);
    if (!bp)
        return;
    di = bp;
    memoryASet(ds, di + 29, memoryAGet(ds, di + 29) + 1);
}
void sub_2de51()
{
}
void sub_2de52()
{
    si = memoryAGet16(ds, 0x3138);
    dx = memoryAGet16(ds, si + 12);
    memoryASet16(ds, 0x3138, dx);
    push(bx);
    bx = 0x3138;
loc_2de61:
    if (memoryAGet16(ds, bx + 12) == 0xffff)
        goto loc_2de6d;
    bx = memoryAGet16(ds, bx + 12);
    goto loc_2de61;
loc_2de6d:
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, bx + 12, si);
    bx = pop();
}
void sub_2de77()
{
    dx = memoryAGet16(ds, bx + 12);
    si = memoryAGet16(ds, 0x3142);
    memoryASet16(ds, si + 12, dx);
    dx = memoryAGet16(ds, 0x3138);
    memoryASet16(ds, bx + 12, dx);
    memoryASet16(ds, 0x3138, bx);
    memoryASet(ds, 0x313a, 0x00);
}
void sub_2de93()
{
    goto loc_2de93;
loc_2de92:
    return;
loc_2de93:
    memoryASet(ds, bx + 5, memoryAGet(ds, bx + 5) - 1);
    dl = memoryAGet(ds, bx + 5);
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2de92;
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2de92;
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2de92;
    dh = 0;
    dl = memoryAGet(ds, bx + 4);
    dl <<= 1;
    di = 0x3385;
    di += dx;
    di = memoryAGet16(ds, di);
    bp = di;
    dl = memoryAGet(ds, bx + 6);
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    di += dx;
    si = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    push(bx);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, bx + 3, memoryAGet(ds, bx + 3) + 1);
    bl = memoryAGet(ds, bx + 2);
    sub_2ed12();
    bx = pop();
    al = memoryAGet(ds, bx + 3);
    if (al != 0xc5)
        goto loc_2dedd;
    goto loc_2df52;
loc_2dedd:
    if (al >= 0xb6)
        goto loc_2dee4;
    goto loc_2df5c;
loc_2dee4:
    if (al <= 0xbe)
        goto loc_2deeb;
    goto loc_2df5c;
loc_2deeb:
    ch = 0;
    dh = 0;
    dl = memoryAGet(ds, bx + 2);
    dx += 0x000e;
    cl = memoryAGet(ds, 0x2e54);
    if (dx >= cx)
        goto loc_2df00;
    goto loc_2df5c;
loc_2df00:
    dx -= 0x000f;
    flags.carry = (cl + memoryAGet(ds, 0x2d3a)) >= 0x100;
    cl += memoryAGet(ds, 0x2d3a);
    ch += flags.carry;
    if (dx <= cx)
        goto loc_2df11;
    goto loc_2df5c;
loc_2df11:
    al = memoryAGet(ds, 0x2d39);
    memoryASet(ds, bx + 6, al);
    ah = 0;
    al = memoryAGet(ds, bx + 4);
    si = 0x2d2d;
    si += ax;
    al = memoryAGet(ds, si);
    memoryASet(ds, bx + 7, al);
    al = memoryAGet(ds, bx + 4);
    memoryASet(ds, bx + 10, al);
    memoryASet(ds, bx + 2, 0x01);
    memoryASet(ds, bx + 3, 0x06);
    memoryASet16(ds, bx, 0x3386);
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) - 1);
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0302);
    sub_2ed5d();
    return;
loc_2df52:
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) - 1);
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2df5c:
    di = bp;
    dl = memoryAGet(ds, bx + 7);
    memoryASet(ds, bx + 6, dl);
    ah = al;
    ah &= 0x03;
    if (ah != 0x02)
        goto loc_2df7c;
    if (dl != 0x0f)
        goto loc_2df79;
    memoryASet(ds, bx + 7, 0x00);
    goto loc_2df7c;
loc_2df79:
    memoryASet(ds, bx + 7, memoryAGet(ds, bx + 7) + 1);
loc_2df7c:
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    di += dx;
    si = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bl = memoryAGet(ds, bx + 2);
    sub_2ed12();
}
void sub_2dfa6()
{
    goto loc_2dfa6;
loc_2df90:
    push(bx);
    dh = 0;
    dl = memoryAGet(ds, bx + 10);
    dx <<= 1;
    bx = 0x33bc;
    bx += dx;
    callIndirect(cs, memoryAGet16(ds, bx));
    bx = pop();
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2dfa6:
    if (memoryAGet(ds, 0x2d3b) == 0x00)
        goto loc_2dfb0;
    goto loc_2e03b;
loc_2dfb0:
    al = memoryAGet(ds, 0x2d39);
    if (al == memoryAGet(ds, bx + 7))
        goto loc_2df90;
    memoryASet(ds, bx + 6, al);
    memoryASet(ds, 0x2d3b, 0xff);
    memoryASet16(ds, 0x2d3c, bx);
    if (memoryAGet(ds, bx + 7) == 0x02)
        goto loc_2dfe6;
    if (memoryAGet(ds, 0x2e7e) != 0x02)
        goto loc_2dfe1;
    push(bx);
    al = memoryAGet(ds, 0x2e7f);
    al++;
    al++;
    bl = memoryAGet(ds, 0x2e80);
    sub_2dc8b();
    bx = pop();
loc_2dfe1:
    memoryASet(ds, 0x2e7e, 0x00);
loc_2dfe6:
    if (memoryAGet(ds, bx + 7) == 0x03)
        goto loc_2e038;
    memoryASet(ds, 0x2e75, 0x00);
    memoryASet16(ds, 0x2e76, 0x0460);
    push(si);
    push(cx);
    cx = 0x0003;
    si = 0x2ea1;
loc_2dfff:
    if (memoryAGet(ds, si + 28) != 0x02)
        goto loc_2e031;
    push(bx);
    push(cx);
    sub_2d09f();
    memoryASet(ds, si + 21, 0x01);
    memoryASet(ds, si + 1, 0xb4);
    al = memoryAGet(ds, si);
    memoryASet(ds, si + 24, al);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 25, al);
    memoryASet16(ds, si + 26, 0x0000);
    memoryASet(ds, si + 28, 0x01);
    memoryASet(ds, si + 29, 0x00);
    push(si);
    sub_2d447();
    si = pop();
    cx = pop();
    bx = pop();
loc_2e031:
    si += 0x001e;
    if (--cx)
        goto loc_2dfff;
    cx = pop();
    si = pop();
loc_2e038:
    goto loc_2e042;
loc_2e03b:
    if (memoryAGet16(ds, 0x2d3c) == bx)
        goto loc_2e042;
    return;
loc_2e042:
    memoryASet(ds, 0x2d3b, memoryAGet(ds, 0x2d3b) - 1);
    ah = 0;
    al = memoryAGet(ds, 0x2d3b);
    cl = 0x23;
    div(cl);
    if (ah)
        goto loc_2e0c1;
    if (memoryAGet(ds, bx + 3) == 0x06)
        goto loc_2e05c;
    goto loc_2e0f7;
loc_2e05c:
    if (memoryAGet(ds, bx + 2) == 0x00)
        goto loc_2e081;
    si = 0x2d25;
    memoryASet(ds, 0x2d38, 0x00);
    dh = 0;
    dl = memoryAGet(ds, bx + 6);
    if (dl != 0x01)
        goto loc_2e079;
    memoryASet(ds, 0x2d38, 0xfe);
loc_2e079:
    if (dl)
        goto loc_2e0e5;
    memoryASet(ds, bx + 2, 0x00);
loc_2e081:
    si = 0x2d1d;
    memoryASet(ds, 0x2d38, 0x00);
    dh = 0;
    dl = memoryAGet(ds, bx + 7);
    if (dl != 0x01)
        goto loc_2e098;
    memoryASet(ds, 0x2d38, 0x02);
loc_2e098:
    if (dl)
        goto loc_2e0e5;
    memoryASet(ds, 0x2d39, 0x00);
    memoryASet(ds, 0x2d3a, 0x1b);
    memoryASet(ds, 0x2d3b, 0x00);
    push(bx);
    dh = 0;
    dl = memoryAGet(ds, bx + 10);
    dx <<= 1;
    bx = 0x33bc;
    bx += dx;
    callIndirect(cs, memoryAGet16(ds, bx));
    bx = pop();
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2e0c1:
    al = memoryAGet(ds, 0x2e54);
    if (al != memoryAGet(ds, 0x2e55))
        goto loc_2e0cb;
    return;
loc_2e0cb:
    if (memoryAGet(ds, bx + 3) == 0x06)
        goto loc_2e135;
    si = memoryAGet16(ds, bx + 4);
    dh = 0;
    dl = memoryAGet(ds, bx + 3);
    dx <<= 1;
    si += dx;
    si = memoryAGet16(ds, si);
    push(bx);
    sub_2cda7();
    bx = pop();
    return;
loc_2e0e5:
    dx <<= 1;
    si += dx;
    memoryASet(ds, bx + 3, 0x06);
    memoryASet(ds, 0x2d3b, 0xff);
    dx = memoryAGet16(ds, si);
    memoryASet16(ds, bx + 4, dx);
loc_2e0f7:
    memoryASet(ds, bx + 3, memoryAGet(ds, bx + 3) - 1);
    si = memoryAGet16(ds, bx + 4);
    dh = 0;
    dl = memoryAGet(ds, bx + 3);
    dx <<= 1;
    si += dx;
    si = memoryAGet16(ds, si);
    push(bx);
    sub_2cda7();
    bx = pop();
    al = memoryAGet(ds, 0x2d38);
    memoryASet(ds, 0x2d3a, memoryAGet(ds, 0x2d3a) + al);
    al = -al;
    memoryASet(ds, 0x2d3f, memoryAGet(ds, 0x2d3f) + al);
    if (memoryAGet(ds, bx + 3) == 0x00)
        goto loc_2e121;
    return;
loc_2e121:
    memoryASet(ds, bx + 3, 0x06);
    if (memoryAGet(ds, bx + 2) != 0x01)
        goto loc_2e14c;
    memoryASet(ds, bx + 2, 0x00);
    memoryASet(ds, 0x2d39, 0x00);
    return;
loc_2e135:
    si = 0x2d0d;
    dl = memoryAGet(ds, 0x2d39);
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    si = memoryAGet16(ds, si);
    push(bx);
    sub_2ce3a();
    bx = pop();
    return;
loc_2e14c:
    si = 0x2d0d;
    dh = 0;
    dl = memoryAGet(ds, bx + 7);
    memoryASet(ds, 0x2d39, dl);
    dx <<= 1;
    dx <<= 1;
    si += dx;
    dl = memoryAGet(ds, si + 2);
    memoryASet(ds, 0x2d3a, dl);
    memoryASet(ds, 0x2d3b, 0x00);
    push(bx);
    dh = 0;
    dl = memoryAGet(ds, bx + 10);
    dx <<= 1;
    bx = 0x33bc;
    bx += dx;
    callIndirect(cs, memoryAGet16(ds, bx));
    bx = pop();
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e181()
{
    goto loc_2e181;
loc_2df5c:
    di = bp;
    dl = memoryAGet(ds, bx + 7);
    memoryASet(ds, bx + 6, dl);
    ah = al;
    ah &= 0x03;
    if (ah != 0x02)
        goto loc_2df7c;
    if (dl != 0x0f)
        goto loc_2df79;
    memoryASet(ds, bx + 7, 0x00);
    goto loc_2df7c;
loc_2df79:
    memoryASet(ds, bx + 7, memoryAGet(ds, bx + 7) + 1);
loc_2df7c:
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    di += dx;
    si = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bl = memoryAGet(ds, bx + 2);
    sub_2ed12();
    return;
    //   gap of 496 bytes
loc_2e180:
    return;
loc_2e181:
    memoryASet(ds, bx + 5, memoryAGet(ds, bx + 5) - 1);
    dl = memoryAGet(ds, bx + 5);
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2e180;
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2e180;
    flags.carry = dl & 1;
    dl >>= 1;
    if (flags.carry)
        goto loc_2e180;
    dh = 0;
    dl = memoryAGet(ds, bx + 4);
    dl <<= 1;
    di = 0x339b;
    di += dx;
    di = memoryAGet16(ds, di);
    bp = di;
    dl = memoryAGet(ds, bx + 6);
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    di += dx;
    si = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    push(bx);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, bx + 3, memoryAGet(ds, bx + 3) + 1);
    bl = memoryAGet(ds, bx + 2);
    sub_2ed12();
    bx = pop();
    al = memoryAGet(ds, bx + 3);
    if (al != 0xc5)
        goto loc_2e1cb;
    goto loc_2e240;
loc_2e1cb:
    if (al >= 0xb6)
        goto loc_2e1d2;
    goto loc_2e24a;
loc_2e1d2:
    if (al <= 0xbe)
        goto loc_2e1d9;
    goto loc_2e24a;
loc_2e1d9:
    ch = 0;
    dh = 0;
    dl = memoryAGet(ds, bx + 2);
    dx += 0x000e;
    cl = memoryAGet(ds, 0x2e54);
    if (dx >= cx)
        goto loc_2e1ee;
    goto loc_2e24a;
loc_2e1ee:
    dx -= 0x000f;
    flags.carry = (cl + memoryAGet(ds, 0x2d3a)) >= 0x100;
    cl += memoryAGet(ds, 0x2d3a);
    ch += flags.carry;
    if (dx <= cx)
        goto loc_2e1ff;
    goto loc_2df5c;
loc_2e1ff:
    al = memoryAGet(ds, 0x2d39);
    memoryASet(ds, bx + 6, al);
    ah = 0;
    al = memoryAGet(ds, bx + 4);
    si = 0x2d2d;
    si += ax;
    al = memoryAGet(ds, si);
    memoryASet(ds, bx + 7, al);
    al = memoryAGet(ds, bx + 4);
    memoryASet(ds, bx + 10, al);
    memoryASet(ds, bx + 2, 0x01);
    memoryASet(ds, bx + 3, 0x06);
    memoryASet16(ds, bx, 0x3386);
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) - 1);
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0302);
    sub_2ed5d();
    return;
loc_2e240:
    memoryASet(ds, 0x3384, memoryAGet(ds, 0x3384) - 1);
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2e24a:
    di = bp;
    dl = memoryAGet(ds, bx + 7);
    memoryASet(ds, bx + 6, dl);
    ah = al;
    ah &= 0x03;
    if (ah != 0x02)
        goto loc_2e26a;
    if (dl != 0x0f)
        goto loc_2e267;
    memoryASet(ds, bx + 7, 0x00);
    goto loc_2e26a;
loc_2e267:
    memoryASet(ds, bx + 7, memoryAGet(ds, bx + 7) + 1);
loc_2e26a:
    dh = 0;
    dx <<= 1;
    dx <<= 1;
    di += dx;
    si = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bl = memoryAGet(ds, bx + 2);
    sub_2ed12();
}
void sub_2e27e()
{
    sub_2e74a();
    if (memoryAGet(ds, 0x313a) != 0x01)
        return;
    di = memoryAGet16(ds, bx + 2);
    memoryASet(ds, di, 0x03);
}
void sub_2e288()
{
    di = memoryAGet16(ds, bx + 2);
    memoryASet(ds, di, 0x03);
}
void sub_2e28f()
{
    sub_2e74a();
    if (memoryAGet(ds, 0x313a) != 0x01)
        goto loc_2e2a8;
    memoryASet(ds, bx + 2, memoryAGet(ds, bx + 2) - 1);
    if (memoryAGet(ds, bx + 2) == 0)
        goto loc_2e2a9;
    memoryASet(ds, 0x313a, 0x00);
    memoryASet16(ds, bx + 6, 0x67ea);
loc_2e2a8:
    return;
loc_2e2a9:
    si = 0x681c;
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    sub_2e784();
}
void sub_2e2b6()
{
    sub_2e74a();
    if (memoryAGet(ds, 0x313a) != 0x01)
        return;
}
void sub_2e2c1()
{
    sub_2e74a();
    if (memoryAGet(ds, 0x313a) != 0x01)
        return;
    di = memoryAGet16(ds, bx + 2);
    al = memoryAGet(ds, bx + 4);
    al += 0x08;
    memoryASet(ds, di, al);
    memoryASet(ds, di + 2, al);
    memoryASet(ds, di + 24, al);
    al = memoryAGet(ds, bx + 5);
    al -= 0x04;
    memoryASet(ds, di + 1, al);
    memoryASet(ds, di + 3, al);
    memoryASet(ds, di + 25, al);
    memoryASet(ds, di + 26, 0x00);
    memoryASet(ds, di + 27, 0x00);
    memoryASet(ds, di + 28, 0x01);
    memoryASet(ds, di + 21, 0x01);
    push(di);
    si = 0x48fb;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    push(bx);
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    si = di;
    si += 0x0004;
    sub_2d4a1();
    bx = pop();
}
void sub_2e316()
{
    memoryASet16(ds, bx + 4, memoryAGet16(ds, bx + 4) - 1);
    if (memoryAGet16(ds, bx + 4) != 0)
        return;
    cl = memoryAGet(ds, 0x2f11);
    si = 0x2f12;
loc_2e322:
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    di = 0x2f18;
    di += ax;
    memoryASet(ds, di, 0x09);
    cl--;
    if (cl != 0)
        goto loc_2e322;
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e31b()
{
    cl = memoryAGet(ds, 0x2f11);
    si = 0x2f12;
loc_2e322:
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    di = 0x2f18;
    di += ax;
    memoryASet(ds, di, 0x09);
    cl--;
    if (cl != 0)
        goto loc_2e322;
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e337()
{
    push(ax);
    push(bx);
    if (memoryAGet(ds, 0x2e73) != 0x03)
        goto loc_2e348;
    bx = pop();
    ax = pop();
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2e348:
    di = 0x2ea1;
    cl = 0x03;
loc_2e34d:
    if (memoryAGet(ds, di + 28) != 0x00)
        goto loc_2e35d;
    di += 0x001e;
    cl--;
    if (cl != 0)
        goto loc_2e34d;
    bx = pop();
    ax = pop();
    return;
loc_2e35d:
    memoryASet(ds, 0x2e73, 0x03);
    cl = 0x03;
    si = 0x2ea1;
    dh = memoryAGet(ds, di + 22);
    dl = memoryAGet(ds, di + 23);
    bh = memoryAGet(ds, di);
    bl = memoryAGet(ds, di + 1);
loc_2e372:
    if (memoryAGet(ds, si + 28) != 0x00)
        goto loc_2e3ee;
    memoryASet(ds, si, bh);
    memoryASet(ds, si + 2, bh);
    memoryASet(ds, si + 1, bl);
    memoryASet(ds, si + 3, bl);
    dl += 0x02;
    memoryASet(ds, si + 22, dh);
    memoryASet(ds, si + 23, dl);
    al = memoryAGet(ds, di + 20);
    memoryASet(ds, si + 20, al);
    al = memoryAGet(ds, di + 21);
    memoryASet(ds, si + 21, al);
    memoryASet(ds, si + 24, bh);
    memoryASet(ds, si + 25, bl);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 28, 0x01);
    memoryASet(ds, si + 29, 0x00);
    bp = si;
    push(si);
    push(di);
    push(dx);
    push(bx);
    push(cx);
    si = 0x48fb;
    di = bp;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = bp;
    dl = memoryAGet(ds, si);
    dl &= 0x03;
    if (dl == 0)
        goto loc_2e3de;
    dl <<= 1;
    dh = 0x04;
    di = bp;
    di += 0x0004;
loc_2e3d4:
    cl = dl;
    memoryASet16(ds, di, ror(memoryAGet16(ds, di), cl));
    di++;
    di++;
    dh--;
    if (dh != 0)
        goto loc_2e3d4;
loc_2e3de:
    bl = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    si += 0x0004;
    sub_2d4a1();
    cx = pop();
    bx = pop();
    dx = pop();
    di = pop();
    si = pop();
loc_2e3ee:
    si += 0x001e;
    cl--;
    if (cl == 0)
        goto loc_2e3f8;
    goto loc_2e372;
loc_2e3f8:
    bx = pop();
    ax = pop();
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e400()
{
    al = memoryAGet(ds, bx + 5);
    cl = memoryAGet(ds, bx + 4);
    ah = memoryAGet(ds, bx + 8);
    ah &= 0x0f;
    if (ah != 0x01)
        goto loc_2e417;
    al++;
    if (al == 0xb8)
        goto loc_2e422;
loc_2e417:
    sub_2ea11();
    if (memoryAGet(ds, 0x33d4) != 0x00)
        goto loc_2e498;
    return;
loc_2e422:
    si = memoryAGet16(ds, bx + 6);
    al = memoryAGet(ds, bx + 5);
    cl = memoryAGet(ds, bx + 4);
    si = memoryAGet16(ds, si);
    sub_2eb6f();
    if (memoryAGet(ds, 0x2e81) != 0x01)
        goto loc_2e487;
    di = memoryAGet16(ds, bx + 2);
    memoryASet(ds, 0x313a, 0x01);
    al = memoryAGet(ds, bx + 4);
    al += 0x08;
    memoryASet(ds, di, al);
    memoryASet(ds, di + 2, al);
    memoryASet(ds, di + 24, al);
    al = memoryAGet(ds, bx + 5);
    al += 0x0b;
    memoryASet(ds, di + 1, al);
    memoryASet(ds, di + 3, al);
    memoryASet(ds, di + 25, al);
    memoryASet(ds, di + 26, 0x00);
    memoryASet(ds, di + 27, 0x00);
    memoryASet(ds, di + 28, 0x01);
    memoryASet(ds, di + 21, 0x01);
    push(di);
    si = 0x48fb;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    push(bx);
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    si = di;
    si += 0x0004;
    sub_2d4a1();
    bx = pop();
    return;
loc_2e487:
    memoryASet(ds, 0x2e73, memoryAGet(ds, 0x2e73) - 1);
    di = memoryAGet16(ds, bx + 2);
    memoryASet(ds, di + 28, 0x00);
    memoryASet(ds, 0x313a, 0x01);
    return;
loc_2e498:
    if (memoryAGet(ds, 0x33d4) != 0x02)
        goto loc_2e4a2;
    return;
loc_2e4a2:
    di = memoryAGet16(ds, bx + 2);
    memoryASet(ds, 0x313a, 0x01);
    al = memoryAGet(ds, bx + 4);
    al += 0x08;
    memoryASet(ds, di, al);
    memoryASet(ds, di + 2, al);
    memoryASet(ds, di + 24, al);
    al = memoryAGet(ds, bx + 5);
    if (memoryAGet(ds, 0x33d4) == 0x01)
        goto loc_2e4d5;
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0303);
    al += 0x04;
loc_2e4d5:
    al += 0x0c;
    memoryASet(ds, di + 1, al);
    memoryASet(ds, di + 3, al);
    memoryASet(ds, di + 25, al);
    memoryASet(ds, di + 26, 0x00);
    memoryASet(ds, di + 27, 0x00);
    memoryASet(ds, di + 28, 0x01);
    memoryASet(ds, di + 21, 0x01);
    push(di);
    si = 0x48fb;
    di += 0x0004;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    push(bx);
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    si = di;
    si += 0x0004;
    sub_2d4a1();
    bx = pop();
    if (memoryAGet(ds, 0x33d4) == 0x03)
        goto loc_2e525;
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0005);
loc_2e525:
    sub_2ed5d();
}
void sub_2e52d()
{
    goto loc_2e52d;
loc_2e529:
    memoryASet16(ds, bx + 6, memoryAGet16(ds, bx + 6) - 1);
loc_2e52c:
    return;
loc_2e52d:
    if (memoryAGet(ds, 0x2e79) != 0x00)
        goto loc_2e52c;
    if (memoryAGet16(ds, bx + 6) != 0x0000)
        goto loc_2e529;
    memoryASet16(ds, bx + 8, memoryAGet16(ds, bx + 8) - 1);
    ax = memoryAGet16(ds, bx + 8);
    cl = 0x23;
    div(cl);
    if (ah)
        goto loc_2e52c;
    si = memoryAGet16(ds, bx + 10);
    si = memoryAGet16(ds, si);
    push(si);
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    al -= 0x0a;
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2e56d;
    di += 0x2000;
loc_2e56d:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    dh = 0x25;
loc_2e57d:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2e58d;
    di -= 0x1fb0;
    goto loc_2e591;
loc_2e58d:
    di += 0x2000;
loc_2e591:
    dh--;
    if (dh != 0)
        goto loc_2e57d;
    es = pop();
    flags.interrupts = true;
    si = pop();
    if (si != 0x635c)
        goto loc_2e5a6;
    memoryASet16(ds, bx + 6, 0x012c);
    sub_2e5c1();
loc_2e5a6:
    memoryASet16(ds, bx + 10, memoryAGet16(ds, bx + 10) + 0x0002);
    si = memoryAGet16(ds, bx + 10);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_2e5b4;
    return;
loc_2e5b4:
    si = memoryAGet16(ds, bx + 2);
    memoryASet(ds, si + 3, 0x00);
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e5c1()
{
    memoryASet(ds, 0x33d6, memoryAGet(ds, 0x33d6) + 1);
    sub_2de52();
    memoryASet16(ds, si, 0x39fa);
    memoryASet(ds, si + 2, 0x00);
    dl = 0x3c;
    sub_2ece0();
    ah += 0x09;
    memoryASet(ds, si + 3, ah);
    dl = 0x08;
    sub_2ece0();
    al = ah;
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    di = 0xac60;
    di += ax;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 8, ax);
    al = memoryAGet(ds, bx + 4);
    if (!al)
        goto loc_2e605;
    al -= 0x08;
    memoryASet(ds, si + 2, 0x02);
loc_2e605:
    memoryASet(ds, si + 4, al);
    cl = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, bx + 5);
    memoryASet(ds, si + 5, al);
    si = memoryAGet16(ds, si + 6);
    si = memoryAGet16(ds, si);
    sub_2ec8a();
}
void sub_2e61a()
{
    al = memoryAGet(ds, bx + 5);
    cl = memoryAGet(ds, bx + 4);
    if (memoryAGet(ds, 0x2e79) == 0x01)
        goto loc_2e63a;
    ah = memoryAGet(ds, bx + 8);
    ah &= 0x0f;
    if (ah != 0x01)
        goto loc_2e63a;
    sub_2e817();
    if (ah == 0xff)
        goto loc_2e672;
loc_2e63a:
    sub_2ea11();
    if (memoryAGet(ds, 0x33d4) != 0x00)
        goto loc_2e645;
    return;
loc_2e645:
    if (memoryAGet(ds, 0x33d4) != 0x02)
        goto loc_2e680;
    dl = 0x07;
    sub_2ece0();
    ah++;
    memoryASet(ds, di + 22, ah);
    dl = 0x07;
    sub_2ece0();
    ah++;
    memoryASet(ds, di + 23, ah);
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, di + 24, ax);
    memoryASet16(ds, di + 26, 0x0000);
    memoryASet(ds, di + 20, memoryAGet(ds, di + 20) ^ 0x01);
    memoryASet(ds, di + 21, memoryAGet(ds, di + 21) ^ 0x01);
loc_2e672:
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    si = memoryAGet16(ds, bx + 6);
    si = memoryAGet16(ds, si);
    sub_2eb6f();
loc_2e680:
    if (memoryAGet(ds, 0x33d4) == 0x00)
        goto loc_2e6ca;
loc_2e687:
    memoryASet(cs, 0x00f4, 0x06);
    memoryASet16(ds, bx, 0x3aee);
    memoryASet16(ds, bx + 6, 0xb7a4);
    memoryASet(ds, bx + 8, 0x0f);
    memoryASet(ds, bx + 9, 0x0f);
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0000);
    memoryASet16(ds, 0x1419, 0x0703);
    memoryASet(ds, 0x33d6, memoryAGet(ds, 0x33d6) - 1);
    push(bx);
    si = memoryAGet16(ds, bx + 6);
    si--;
    si--;
    si = memoryAGet16(ds, si);
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    sub_2eb6f();
    sub_2ed5d();
    bx = pop();
    return;
loc_2e6ca:
    if (memoryAGet(ds, 0x2e81) == 0x01)
        goto loc_2e687;
    memoryASet(ds, 0x313a, 0x01);
    memoryASet(ds, 0x33d5, memoryAGet(ds, 0x33d5) - 1);
    memoryASet(ds, 0x33d6, memoryAGet(ds, 0x33d6) - 1);
}
void sub_2e70e()
{
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) - 1);
    if (memoryAGet(ds, bx + 8) == 0)
        goto loc_2e714;
    return;
loc_2e714:
    ah = memoryAGet(ds, bx + 9);
    memoryASet(ds, bx + 8, ah);
    si = memoryAGet16(ds, bx + 6);
    push(si);
    si--;
    si--;
    si = memoryAGet16(ds, si);
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    push(ax);
    push(cx);
    sub_2eb6f();
    cx = pop();
    ax = pop();
    si = pop();
    si = memoryAGet16(ds, si);
    if (si == 0xffff)
        goto loc_2e740;
    sub_2eb6f();
    memoryASet16(ds, bx + 6, memoryAGet16(ds, bx + 6) + 0x0002);
    return;
loc_2e740:
    memoryASet(ds, 0x33d5, memoryAGet(ds, 0x33d5) - 1);
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e74a()
{
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) - 1);
    if (memoryAGet(ds, bx + 8) == 0)
        goto loc_2e750;
    return;
loc_2e750:
    ah = memoryAGet(ds, bx + 9);
    memoryASet(ds, bx + 8, ah);
    si = memoryAGet16(ds, bx + 6);
    push(si);
    si--;
    si--;
    si = memoryAGet16(ds, si);
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    push(ax);
    push(cx);
    sub_2e784();
    cx = pop();
    ax = pop();
    si = pop();
    si = memoryAGet16(ds, si);
    sub_2e784();
    memoryASet16(ds, bx + 6, memoryAGet16(ds, bx + 6) + 0x0002);
    si = memoryAGet16(ds, bx + 6);
    if (memoryAGet16(ds, si) != 0xffff)
        return;
    memoryASet(ds, 0x313a, 0x01);
}
void sub_2e784()
{
    flags.interrupts = false;
    push(es);
    di = 0xb800;
    es = di;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2e79b;
    di += 0x2000;
loc_2e79b:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = 0x0007;
loc_2e7ac:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    if (di < 0x2000)
        goto loc_2e7c3;
    di -= 0x1fb0;
    if (--cx)
        goto loc_2e7ac;
    goto loc_2e7c9;
loc_2e7c3:
    di += 0x2000;
    if (--cx)
        goto loc_2e7ac;
loc_2e7c9:
    es = pop();
    flags.interrupts = true;
}
void sub_2e817()
{
    if (memoryAGet(ds, bx + 2) == 0x04)
        goto loc_2e855;
    memoryASet(ds, bx + 3, memoryAGet(ds, bx + 3) - 1);
    if (memoryAGet(ds, bx + 3) == 0)
        goto loc_2e835;
    bp = bx;
    bl = memoryAGet(ds, bx + 2);
    bh = 0;
    bx <<= 1;
    bx += 0x3447;
    assert(cs == 0x2ac2);
    switch (memoryAGet16(ds, bx))
    {
        case 0x3c66: sub_2e886(); break;
        case 0x3d3c: sub_2e95c(); break;
        case 0x3cf3: sub_2e913(); break;
        case 0x3caf: sub_2e8cf(); break;
        default:
        assert(0);
    }
    bx = bp;
    if (!flags.carry)
        goto loc_2e84e;
loc_2e835:
    push(ax);
    dl = 0x04;
    sub_2ece0();
    memoryASet(ds, bx + 2, ah);
    if (ah == 0x01)
        goto loc_2e84f;
    dl = 0x3c;
    dl++;
    sub_2ece0();
    memoryASet(ds, bx + 3, ah);
    ax = pop();
loc_2e84e:
    return;
loc_2e84f:
    memoryASet(ds, bx + 3, 0xff);
    ax = pop();
    return;
loc_2e855:
    si = memoryAGet16(ds, bx + 10);
    memoryASet16(ds, bx + 10, memoryAGet16(ds, bx + 10) + 0x0002);
    lodsw<MemAuto, DirAuto>();
    cl = memoryAGet(ds, bx + 3);
    push(ax);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_2e86d;
    al = rcr(al, 0x01);
    al = -al;
    if (cl < al)
        goto loc_2e881;
loc_2e86d:
    ax = pop();
    cl += al;
    if (cl <= 0xb8)
        goto loc_2e877;
    cl = 0xb8;
loc_2e877:
    if (cl < 0x08)
        goto loc_2e882;
loc_2e87c:
    al = 0x79;
    al += ah;
    return;
loc_2e881:
    ax = pop();
loc_2e882:
    cl = 0x08;
    goto loc_2e87c;
}
void sub_2e886()
{
    push(cx);
    push(ax);
    if (cl >= 0xb8)
        goto loc_2e8cb;
    al -= 0x06;
    cl += 0x08;
    ah = 0;
    al &= 0xf8;
    di = ax;
    al >>= 1;
    di += ax;
    ch = 0;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    di += cx;
    di += 0x2f18;
    if (memoryAGet(ds, di) != 0x00)
        goto loc_2e8cb;
    if (memoryAGet(ds, di + 12) != 0x00)
        goto loc_2e8cb;
    ax = pop();
    push(ax);
    al -= 0x06;
    al &= 0x07;
    if (al == 0)
        goto loc_2e8c5;
    if (memoryAGet(ds, di + 24) != 0x00)
        goto loc_2e8cb;
loc_2e8c5:
    ax = pop();
    cx = pop();
    cl++;
    flags.carry = false;
    return;
loc_2e8cb:
    ax = pop();
    cx = pop();
    flags.carry = true;
}
void sub_2e8cf()
{
    push(ax);
    push(cx);
    if (al <= 0x06)
        goto loc_2e90f;
    al -= 0x07;
    cl -= 0x08;
    ah = 0;
    al &= 0xf8;
    di = ax;
    al >>= 1;
    di += ax;
    ch = 0;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    di += cx;
    di += 0x2f18;
    if (memoryAGet(ds, di) != 0x00)
        goto loc_2e90f;
    cx = pop();
    push(cx);
    cl -= 0x08;
    cl &= 0x0f;
    if (cl == 0)
        goto loc_2e909;
    if (memoryAGet(ds, di + 1) != 0x00)
        goto loc_2e90f;
loc_2e909:
    cx = pop();
    ax = pop();
    al--;
    flags.carry = false;
    return;
loc_2e90f:
    cx = pop();
    ax = pop();
    flags.carry = true;
}
void sub_2e913()
{
    goto loc_2e913;
loc_2e8cb:
    ax = pop();
    cx = pop();
    flags.carry = true;
    return;
    //   gap of 68 bytes
loc_2e913:
    push(cx);
    push(ax);
    if (cl <= 0x08)
        goto loc_2e8cb;
    al -= 0x06;
    cl -= 0x09;
    ah = 0;
    al &= 0xf8;
    di = ax;
    al >>= 1;
    di += ax;
    ch = 0;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    di += cx;
    di += 0x2f18;
    if (memoryAGet(ds, di) != 0x00)
        goto loc_2e958;
    if (memoryAGet(ds, di + 12) != 0x00)
        goto loc_2e958;
    ax = pop();
    push(ax);
    al -= 0x06;
    al &= 0x07;
    if (al == 0)
        goto loc_2e952;
    if (memoryAGet(ds, di + 24) != 0x00)
        goto loc_2e958;
loc_2e952:
    ax = pop();
    cx = pop();
    cl--;
    flags.carry = false;
    return;
loc_2e958:
    ax = pop();
    cx = pop();
    flags.carry = true;
}
void sub_2e95c()
{
    push(ax);
    push(cx);
    if (al >= 0x78)
        goto loc_2e9a0;
    al += 0x0a;
    cl -= 0x08;
    ah = 0;
    al &= 0xf8;
    di = ax;
    al >>= 1;
    di += ax;
    ch = 0;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    di += cx;
    di += 0x2f18;
    if (memoryAGet(ds, di) != 0x00)
        goto loc_2e99c;
    cx = pop();
    push(cx);
    cl -= 0x08;
    cl &= 0x0f;
    if (cl == 0)
        goto loc_2e996;
    if (memoryAGet(ds, di + 1) != 0x00)
        goto loc_2e99c;
loc_2e996:
    cx = pop();
    ax = pop();
    al++;
    flags.carry = false;
    return;
loc_2e99c:
    cx = pop();
    ax = pop();
    flags.carry = true;
    return;
loc_2e9a0:
    di = bp;
    memoryASet(ds, di + 2, 0x04);
    memoryASet16(ds, di + 10, 0x8320);
    cx = pop();
    memoryASet(ds, di + 3, cl);
    ax = pop();
    al++;
    flags.carry = false;
}
void sub_2e9b5()
{
    goto loc_2e9b5;
loc_2e9b4:
    return;
loc_2e9b5:
    dl = 0x04;
    sub_2ece0();
    al = ah;
    ah = 0;
    al <<= 1;
    al <<= 1;
    si = ax;
    si += 0x33d7;
    if (memoryAGet(ds, si + 3) != 0x00)
        goto loc_2e9b4;
    al = memoryAGet(ds, si + 2);
    di = ax;
    di += 0x2f18;
    if (memoryAGet(ds, di) != 0x00)
        goto loc_2e9b4;
    if (memoryAGet(ds, di + 12) != 0x00)
        goto loc_2e9b4;
    memoryASet(ds, si + 3, 0x01);
    memoryASet(ds, 0x33d5, memoryAGet(ds, 0x33d5) + 1);
    di = si;
    sub_2de52();
    cl = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    memoryASet16(ds, si, 0x390d);
    memoryASet16(ds, si + 2, di);
    memoryASet(ds, si + 4, cl);
    memoryASet(ds, si + 5, al);
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, si + 8, 0x02bc);
    memoryASet16(ds, si + 10, 0x604e);
}
void sub_2ea11()
{
    memoryASet(ds, 0x33d4, 0x00);
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) - 1);
    ah = memoryAGet(ds, bx + 8);
    ah &= 0x0f;
    if (ah != 0)
        goto loc_2ea7a;
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) - 1);
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) & 0xf0);
    ah = memoryAGet(ds, bx + 9);
    ah &= 0x0f;
    memoryASet(ds, bx + 8, memoryAGet(ds, bx + 8) | ah);
    push(ax);
    push(cx);
    si = memoryAGet16(ds, bx + 6);
    push(si);
    si = memoryAGet16(ds, si);
    cl = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    sub_2eb6f();
    si = pop();
    cx = pop();
    ax = pop();
    memoryASet(ds, bx + 4, cl);
    memoryASet(ds, bx + 5, al);
    ah = memoryAGet(ds, bx + 8);
    ch = cl;
    cl = 0x04;
    ah >>= cl;
    cl = ch;
    if (ah)
        goto loc_2ea75;
    ah = memoryAGet(ds, bx + 9);
    memoryASet(ds, bx + 8, ah);
    memoryASet16(ds, bx + 6, memoryAGet16(ds, bx + 6) + 0x0002);
    si = memoryAGet16(ds, bx + 6);
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_2ea75;
    si += 0x0002;
    si = memoryAGet16(ds, si);
    memoryASet16(ds, bx + 6, si);
loc_2ea75:
    si = memoryAGet16(ds, si);
    sub_2eb6f();
loc_2ea7a:
    if (memoryAGet(ds, 0x2e7e) != 0x02)
        goto loc_2eae4;
    al = memoryAGet(ds, 0x2e7f);
    al++;
    al++;
    ah = al;
    al++;
    if (al < memoryAGet(ds, bx + 5))
        goto loc_2eae4;
    al = memoryAGet(ds, bx + 5);
    al += 0x0f;
    if (ah > al)
        goto loc_2eae4;
    al = memoryAGet(ds, 0x2e80);
    ah = memoryAGet(ds, bx + 4);
    if (al < ah)
        goto loc_2eaab;
    ah += 0x0f;
    if (al <= ah)
        goto loc_2eabb;
loc_2eaab:
    ah = memoryAGet(ds, bx + 4);
    al += 0x13;
    if (al < ah)
        goto loc_2eae4;
    ah += 0x0f;
    if (al > ah)
        goto loc_2eae4;
loc_2eabb:
    memoryASet(ds, 0x33d4, 0x03);
    si = memoryAGet16(ds, bx + 6);
    al = memoryAGet(ds, bx + 5);
    cl = memoryAGet(ds, bx + 4);
    si = memoryAGet16(ds, si);
    sub_2eb6f();
    al = memoryAGet(ds, 0x2e7f);
    al++;
    al++;
    push(bx);
    bl = memoryAGet(ds, 0x2e80);
    sub_2dc8b();
    memoryASet(ds, 0x2e7f, 0xb3);
    bx = pop();
    return;
loc_2eae4:
    ah = memoryAGet(ds, bx + 5);
    if (ah > 0xbe)
        goto loc_2eb20;
    ah += 0x0f;
    if (ah < 0xb8)
        goto loc_2eb20;
    ah = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, 0x2e54);
    ah += 0x0f;
    if (ah < al)
        goto loc_2eb20;
    ah -= 0x0f;
    al += memoryAGet(ds, 0x2d3a);
    if (ah > al)
        goto loc_2eb20;
    memoryASet(ds, 0x33d4, 0x01);
    si = memoryAGet16(ds, bx + 6);
    al = memoryAGet(ds, bx + 5);
    cl = memoryAGet(ds, bx + 4);
    si = memoryAGet16(ds, si);
    sub_2eb6f();
    return;
loc_2eb20:
    cl = 0x03;
    si = 0x2ea1;
loc_2eb25:
    if (memoryAGet(ds, si + 28) != 0x01)
        goto loc_2eb35;
    sub_2eb40();
    if (memoryAGet(ds, 0x33d4) == 0x02)
        goto loc_2eb3d;
loc_2eb35:
    si += 0x001e;
    cl--;
    if (cl != 0)
        goto loc_2eb25;
    return;
loc_2eb3d:
    di = si;
}
void sub_2eb40()
{
    ah = memoryAGet(ds, bx + 5);
    al = memoryAGet(ds, si + 1);
    al += 0x03;
    if (ah > al)
        return;
    ah += 0x0f;
    if (ah < memoryAGet(ds, si + 1))
        return;
    ah = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, si);
    ah += 0x0f;
    if (ah < al)
        return;
    ah -= 0x0f;
    al += 0x03;
    if (ah > al)
        return;
    memoryASet(ds, 0x33d4, 0x02);
}
void sub_2eb6f()
{
    push(ax);
    dx = cx;
    di = 0x33f7;
    cx = 0x0028;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = dx;
    push(cx);
    cl &= 0x03;
    if (cl != 0)
        goto loc_2eb85;
    goto loc_2ec81;
loc_2eb85:
    ch = 0;
    cl <<= 1;
    di = 0x33f7;
loc_2eb8c:
    flags.carry = memoryAGet(ds, di) & 1;
    memoryASet(ds, di, memoryAGet(ds, di) >> 1);
    memoryASet(ds, di + 1, rcr(memoryAGet(ds, di + 1), 0x01));
    memoryASet(ds, di + 2, rcr(memoryAGet(ds, di + 2), 0x01));
    memoryASet(ds, di + 3, rcr(memoryAGet(ds, di + 3), 0x01));
    memoryASet(ds, di + 4, rcr(memoryAGet(ds, di + 4), 0x01));
    flags.carry = memoryAGet(ds, di + 5) & 1;
    memoryASet(ds, di + 5, memoryAGet(ds, di + 5) >> 1);
    memoryASet(ds, di + 6, rcr(memoryAGet(ds, di + 6), 0x01));
    memoryASet(ds, di + 7, rcr(memoryAGet(ds, di + 7), 0x01));
    memoryASet(ds, di + 8, rcr(memoryAGet(ds, di + 8), 0x01));
    memoryASet(ds, di + 9, rcr(memoryAGet(ds, di + 9), 0x01));
    flags.carry = memoryAGet(ds, di + 10) & 1;
    memoryASet(ds, di + 10, memoryAGet(ds, di + 10) >> 1);
    memoryASet(ds, di + 11, rcr(memoryAGet(ds, di + 11), 0x01));
    memoryASet(ds, di + 12, rcr(memoryAGet(ds, di + 12), 0x01));
    memoryASet(ds, di + 13, rcr(memoryAGet(ds, di + 13), 0x01));
    memoryASet(ds, di + 14, rcr(memoryAGet(ds, di + 14), 0x01));
    flags.carry = memoryAGet(ds, di + 15) & 1;
    memoryASet(ds, di + 15, memoryAGet(ds, di + 15) >> 1);
    memoryASet(ds, di + 16, rcr(memoryAGet(ds, di + 16), 0x01));
    memoryASet(ds, di + 17, rcr(memoryAGet(ds, di + 17), 0x01));
    memoryASet(ds, di + 18, rcr(memoryAGet(ds, di + 18), 0x01));
    memoryASet(ds, di + 19, rcr(memoryAGet(ds, di + 19), 0x01));
    flags.carry = memoryAGet(ds, di + 20) & 1;
    memoryASet(ds, di + 20, memoryAGet(ds, di + 20) >> 1);
    memoryASet(ds, di + 21, rcr(memoryAGet(ds, di + 21), 0x01));
    memoryASet(ds, di + 22, rcr(memoryAGet(ds, di + 22), 0x01));
    memoryASet(ds, di + 23, rcr(memoryAGet(ds, di + 23), 0x01));
    memoryASet(ds, di + 24, rcr(memoryAGet(ds, di + 24), 0x01));
    flags.carry = memoryAGet(ds, di + 25) & 1;
    memoryASet(ds, di + 25, memoryAGet(ds, di + 25) >> 1);
    memoryASet(ds, di + 26, rcr(memoryAGet(ds, di + 26), 0x01));
    memoryASet(ds, di + 27, rcr(memoryAGet(ds, di + 27), 0x01));
    memoryASet(ds, di + 28, rcr(memoryAGet(ds, di + 28), 0x01));
    memoryASet(ds, di + 29, rcr(memoryAGet(ds, di + 29), 0x01));
    flags.carry = memoryAGet(ds, di + 30) & 1;
    memoryASet(ds, di + 30, memoryAGet(ds, di + 30) >> 1);
    memoryASet(ds, di + 31, rcr(memoryAGet(ds, di + 31), 0x01));
    memoryASet(ds, di + 32, rcr(memoryAGet(ds, di + 32), 0x01));
    memoryASet(ds, di + 33, rcr(memoryAGet(ds, di + 33), 0x01));
    memoryASet(ds, di + 34, rcr(memoryAGet(ds, di + 34), 0x01));
    flags.carry = memoryAGet(ds, di + 35) & 1;
    memoryASet(ds, di + 35, memoryAGet(ds, di + 35) >> 1);
    memoryASet(ds, di + 36, rcr(memoryAGet(ds, di + 36), 0x01));
    memoryASet(ds, di + 37, rcr(memoryAGet(ds, di + 37), 0x01));
    memoryASet(ds, di + 38, rcr(memoryAGet(ds, di + 38), 0x01));
    memoryASet(ds, di + 39, rcr(memoryAGet(ds, di + 39), 0x01));
    flags.carry = memoryAGet(ds, di + 40) & 1;
    memoryASet(ds, di + 40, memoryAGet(ds, di + 40) >> 1);
    memoryASet(ds, di + 41, rcr(memoryAGet(ds, di + 41), 0x01));
    memoryASet(ds, di + 42, rcr(memoryAGet(ds, di + 42), 0x01));
    memoryASet(ds, di + 43, rcr(memoryAGet(ds, di + 43), 0x01));
    memoryASet(ds, di + 44, rcr(memoryAGet(ds, di + 44), 0x01));
    flags.carry = memoryAGet(ds, di + 45) & 1;
    memoryASet(ds, di + 45, memoryAGet(ds, di + 45) >> 1);
    memoryASet(ds, di + 46, rcr(memoryAGet(ds, di + 46), 0x01));
    memoryASet(ds, di + 47, rcr(memoryAGet(ds, di + 47), 0x01));
    memoryASet(ds, di + 48, rcr(memoryAGet(ds, di + 48), 0x01));
    memoryASet(ds, di + 49, rcr(memoryAGet(ds, di + 49), 0x01));
    flags.carry = memoryAGet(ds, di + 50) & 1;
    memoryASet(ds, di + 50, memoryAGet(ds, di + 50) >> 1);
    memoryASet(ds, di + 51, rcr(memoryAGet(ds, di + 51), 0x01));
    memoryASet(ds, di + 52, rcr(memoryAGet(ds, di + 52), 0x01));
    memoryASet(ds, di + 53, rcr(memoryAGet(ds, di + 53), 0x01));
    memoryASet(ds, di + 54, rcr(memoryAGet(ds, di + 54), 0x01));
    flags.carry = memoryAGet(ds, di + 55) & 1;
    memoryASet(ds, di + 55, memoryAGet(ds, di + 55) >> 1);
    memoryASet(ds, di + 56, rcr(memoryAGet(ds, di + 56), 0x01));
    memoryASet(ds, di + 57, rcr(memoryAGet(ds, di + 57), 0x01));
    memoryASet(ds, di + 58, rcr(memoryAGet(ds, di + 58), 0x01));
    memoryASet(ds, di + 59, rcr(memoryAGet(ds, di + 59), 0x01));
    flags.carry = memoryAGet(ds, di + 60) & 1;
    memoryASet(ds, di + 60, memoryAGet(ds, di + 60) >> 1);
    memoryASet(ds, di + 61, rcr(memoryAGet(ds, di + 61), 0x01));
    memoryASet(ds, di + 62, rcr(memoryAGet(ds, di + 62), 0x01));
    memoryASet(ds, di + 63, rcr(memoryAGet(ds, di + 63), 0x01));
    memoryASet(ds, di + 64, rcr(memoryAGet(ds, di + 64), 0x01));
    flags.carry = memoryAGet(ds, di + 65) & 1;
    memoryASet(ds, di + 65, memoryAGet(ds, di + 65) >> 1);
    memoryASet(ds, di + 66, rcr(memoryAGet(ds, di + 66), 0x01));
    memoryASet(ds, di + 67, rcr(memoryAGet(ds, di + 67), 0x01));
    memoryASet(ds, di + 68, rcr(memoryAGet(ds, di + 68), 0x01));
    memoryASet(ds, di + 69, rcr(memoryAGet(ds, di + 69), 0x01));
    flags.carry = memoryAGet(ds, di + 70) & 1;
    memoryASet(ds, di + 70, memoryAGet(ds, di + 70) >> 1);
    memoryASet(ds, di + 71, rcr(memoryAGet(ds, di + 71), 0x01));
    memoryASet(ds, di + 72, rcr(memoryAGet(ds, di + 72), 0x01));
    memoryASet(ds, di + 73, rcr(memoryAGet(ds, di + 73), 0x01));
    memoryASet(ds, di + 74, rcr(memoryAGet(ds, di + 74), 0x01));
    flags.carry = memoryAGet(ds, di + 75) & 1;
    memoryASet(ds, di + 75, memoryAGet(ds, di + 75) >> 1);
    memoryASet(ds, di + 76, rcr(memoryAGet(ds, di + 76), 0x01));
    memoryASet(ds, di + 77, rcr(memoryAGet(ds, di + 77), 0x01));
    memoryASet(ds, di + 78, rcr(memoryAGet(ds, di + 78), 0x01));
    memoryASet(ds, di + 79, rcr(memoryAGet(ds, di + 79), 0x01));
    cx--;
    if (cx == 0)
        goto loc_2ec81;
    goto loc_2eb8c;
loc_2ec81:
    si = 0x33f7;
    cx = pop();
    ax = pop();
    sub_2ec8a();
}
void sub_2ec8a()
{
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2eca1;
    di += 0x2000;
loc_2eca1:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    dh = 0x10;
loc_2ecb1:
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 1, memoryAGet(es, di + 1) ^ al);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 2, memoryAGet(es, di + 2) ^ al);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 3, memoryAGet(es, di + 3) ^ al);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 4, memoryAGet(es, di + 4) ^ al);
    if (di < 0x2000)
        goto loc_2ecd5;
    di -= 0x1fb0;
    goto loc_2ecd9;
loc_2ecd5:
    di += 0x2000;
loc_2ecd9:
    dh--;
    if (dh != 0)
        goto loc_2ecb1;
    es = pop();
    flags.interrupts = true;
}
void sub_2ece0()
{
    push(es);
    ax = 0x0000;
    es = ax;
    ax = memoryAGet16(es, 0x046c);
    ax += memoryAGet16(es, 0x046e);
    es = pop();
    push(si);
    push(dx);
    si = 0x3164;
    dh = 0x0a;
loc_2ecf7:
    ax += memoryAGet16(ds, si);
    si++;
    si++;
    dh--;
    if (dh != 0)
        goto loc_2ecf7;
    ax += memoryAGet16(ds, 0x33d2);
    memoryASet16(ds, 0x33d2, memoryAGet16(ds, 0x33d2) + 0x5ec5);
    al += ah;
    ah = 0;
    div(dl);
    dx = pop();
    si = pop();
}
void sub_2ed12()
{
    flags.interrupts = false;
    push(es);
    dx = 0xb800;
    es = dx;
    bh = 0;
    di = bx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2ed29;
    di += 0x2000;
loc_2ed29:
    push(cx);
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = pop();
loc_2ed39:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    if (di < 0x2000)
        goto loc_2ed52;
    di -= 0x1fb0;
    cl--;
    if (cl != 0)
        goto loc_2ed39;
    goto loc_2ed5a;
loc_2ed52:
    di += 0x2000;
    cl--;
    if (cl != 0)
        goto loc_2ed39;
loc_2ed5a:
    es = pop();
    flags.interrupts = true;
}
void sub_2ed5d()
{
    push(si);
    push(di);
    si = 0x13d2;
    di = 0x141a;
    bl = 0;
    cl = 0x06;
loc_2ed69:
    al = memoryAGet(ds, si);
    al &= 0x0f;
    flags.carry = false;
    if (!bl)
        goto loc_2ed73;
    flags.carry = true;
loc_2ed73:
    al += memoryAGet(ds, di) + flags.carry;
    bl = al;
    bl &= 0xf0;
    ah = al;
    ah &= 0x0f;
    al += 0x06;
    bl |= al;
    al &= 0x0f;
    bl &= 0xf0;
    if (bl != 0)
        goto loc_2ed8c;
    al = ah;
loc_2ed8c:
    al |= 0x30;
    memoryASet(ds, si, al);
    si--;
    di--;
    cl--;
    if (cl != 0)
        goto loc_2ed69;
    si = 0x13cd;
    di = 0x15d2;
    cl = 0x06;
loc_2ed9e:
    lodsb<MemAuto, DirAuto>();
    push(si);
    push(es);
    si = 0xb800;
    es = si;
    sub_2b884();
    es = pop();
    si = pop();
    di++;
    di++;
    cl--;
    if (cl != 0)
        goto loc_2ed9e;
    ax = memoryAGet16(ds, 0x13d3);
    bx = memoryAGet16(ds, 0x13cd);
    tl = bl;
    bl = bh;
    bh = tl;
    if (bx < ax)
        goto loc_2edce;
    ax++;
    ax++;
    if (al < 0x3a)
        goto loc_2edc8;
    ah++;
    al = 0x30;
loc_2edc8:
    memoryASet16(ds, 0x13d3, ax);
    sub_2ddab();
loc_2edce:
    di = pop();
    si = pop();
}
void sub_2edd1()
{
    push(es);
    push(cx);
    cx = 0xb800;
    es = cx;
    cx = 0x0019;
loc_2eddb:
    stosw<MemAuto, DirAuto>();
    di--;
    di--;
    if (di < 0x2000)
        goto loc_2edea;
    di -= 0x1fb0;
    goto loc_2edee;
loc_2edea:
    di += 0x2000;
loc_2edee:
    cx--;
    if (cx != 0)
        goto loc_2eddb;
    cx = pop();
    es = pop();
}
void sub_2edf4()
{
    di = 0x1a77;
    ax = 0;
    sub_2edd1();
    di = 0x1a8b;
    ax = 0;
    sub_2edd1();
}
void sub_2ee05()
{
    push(ds);
    push(cx);
    si = 0x1c46;
    ds = si;
    ah = 0;
    ch = cl;
    cl = 0x04;
    ax <<= cl;
    si = ax;
    ax <<= 1;
    si += ax;
    si += 0x28f0;
    cl = ch;
    ch = 0;
    cx <<= 1;
    cx <<= 1;
    si += cx;
    cx = 0x0002;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    ds = pop();
}
void sub_2f1c1()
{
    al = memoryAGet(ds, si);
    bl = memoryAGet(ds, si + 1);
    if (al > 0x08)
        goto loc_2f1d2;
    memoryASet(ds, si + 20, 0x00);
    dl = 0x09;
    goto loc_2f1dc;
loc_2f1d2:
    if (al < 0xc4)
        goto loc_2f1f0;
    memoryASet(ds, si + 20, 0x01);
    dl = 0xc3;
loc_2f1dc:
    memoryASet(cs, 0x00f4, 0x02);
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x00);
    memoryASet(ds, si + 24, dl);
    memoryASet(ds, si + 25, bl);
loc_2f1f0:
    if (bl > 0x74)
        goto loc_2f221;
    if (bl == 0x74)
        goto loc_2f1fa;
    goto loc_2f345;
loc_2f1fa:
    if (al < 0x60)
        goto loc_2f202;
    if (al < 0x6c)
        goto loc_2f221;
loc_2f202:
    memoryASet(ds, si + 21, 0x00);
    dl = bl;
    dl++;
    memoryASet(ds, si + 29, memoryAGet(ds, si + 29) + 1);
    memoryASet(ds, si + 26, 0x00);
    memoryASet(ds, si + 27, 0x01);
    memoryASet(ds, si + 24, al);
    memoryASet(ds, si + 25, dl);
    memoryASet(cs, 0x00f4, 0x02);
loc_2f221:
    if (memoryAGet(ds, si + 1) == 0xc4)
        goto loc_2f22b;
    sub_2cf36();
    return;
loc_2f22b:
    ax = pop();
    sub_2acb0();
    si = 0x2d8c;
    di = 0x2e57;
    sub_2cea1();
    bl = memoryAGet(ds, 0x2ea1);
    al = memoryAGet(ds, 0x2ea2);
    si = 0x2ea5;
    sub_2d4a1();
    if (memoryAGet(ds, 0x3f1b) == 0x01)
        goto loc_2f250;
    memoryASet(ds, 0x13c9, memoryAGet(ds, 0x13c9) + 1);
loc_2f250:
    memoryASet(ds, 0x2f0c, 0x75);
    push(es);
    bp = ds;
    di = 0xb800;
    es = di;
    ds = di;
    di = 0x1198;
    memoryASet16(es, di, 0xffff);
    memoryASet16(es, di + 2, 0xffff);
    di += 0x2000;
    memoryASet16(es, di, 0x5555);
    memoryASet16(es, di + 2, 0x5555);
    di -= 0x1fb0;
    memoryASet16(es, di, 0x1515);
    memoryASet16(es, di + 2, 0x1515);
    di += 0x2000;
    memoryASet16(es, di, 0x5555);
    memoryASet16(es, di + 2, 0x5555);
    di = 0x3130;
    ah = 0x70;
loc_2f29f:
    push(di);
    si = di;
    dx = si;
    if (di < 0x2000)
        goto loc_2f2b0;
    di -= 0x1fb0;
    goto loc_2f2b4;
loc_2f2b0:
    di += 0x2000;
loc_2f2b4:
    tx = di;
    di = si;
    si = tx;
    al = 0x07;
loc_2f2b8:
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = dx;
    si = di;
    if (di < 0x2000)
        goto loc_2f2cd;
    di -= 0x1fb0;
    goto loc_2f2d1;
loc_2f2cd:
    di += 0x2000;
loc_2f2d1:
    tx = di;
    di = si;
    si = tx;
    dx = si;
    al--;
    if (al != 0)
        goto loc_2f2b8;
    memoryASet(es, di, 0x0d);
    bl = 0x50;
    bh = ah;
    bh &= 0x03;
    if (bh != 0)
        goto loc_2f2e8;
    bl = 0x10;
loc_2f2e8:
    memoryASet(es, di + 1, bl);
    di++;
    di++;
    push(ax);
    push(ds);
    ds = bp;
    al = memoryAGet(ds, 0x2f0c);
    push(bx);
    sub_2cc54();
    bx = pop();
    ds = pop();
    ax = pop();
    memoryASet(es, di, 0x0d);
    memoryASet(es, di + 1, bl);
    di = pop();
    if (di >= 0x2000)
        goto loc_2f312;
    di += 0x1fb0;
    goto loc_2f316;
loc_2f312:
    di -= 0x2000;
loc_2f316:
    cx = 0x000f;
loc_2f319:
    sub_2c26c();
    if (--cx)
        goto loc_2f319;
    push(ds);
    ds = bp;
    memoryASet(ds, 0x2f0c, memoryAGet(ds, 0x2f0c) - 1);
    ds = pop();
    ah--;
    if (ah == 0)
        goto loc_2f32d;
    goto loc_2f29f;
loc_2f32d:
    es = pop();
    ds = bp;
    dx = 0x03da;
loc_2f333:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2f333;
loc_2f338:
    in(al, dx);
    if (al & 0x08)
        goto loc_2f338;
    sub_2b531();
    sub_2b5e5();
    flags.carry = true;
    return;
loc_2f345:
    if (bl == 0x3c)
        goto loc_2f375;
    if (al > 0x60)
        goto loc_2f356;
    memoryASet(ds, si + 20, 0x00);
    dl = 0x61;
    goto loc_2f360;
loc_2f356:
    if (al < 0x6c)
        goto loc_2f374;
    memoryASet(ds, si + 20, 0x01);
    dl = 0x6b;
loc_2f360:
    memoryASet(ds, si + 26, 0x01);
    memoryASet(ds, si + 27, 0x00);
    memoryASet(ds, si + 24, dl);
    memoryASet(ds, si + 25, bl);
    memoryASet(cs, 0x00f4, 0x02);
loc_2f374:
    return;
loc_2f375:
    sub_2acb0();
    ax = pop();
    bl = memoryAGet(ds, 0x2ea1);
    al = memoryAGet(ds, 0x2ea2);
    si = 0x2ea5;
    sub_2d4a1();
    si = 0x6abe;
loc_2f389:
    cx = 0x0147;
loc_2f38c:
    sub_2c26c();
    if (--cx)
        goto loc_2f38c;
    push(si);
    si--;
    si--;
    si = memoryAGet16(ds, si);
    cl = 0x60;
    al = 0x38;
    push(ax);
    push(cx);
    sub_2e784();
    cx = pop();
    ax = pop();
    si = pop();
    push(si);
    si = memoryAGet16(ds, si);
    sub_2e784();
    si = pop();
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_2f389;
    sub_2f4ee();
    push(ds);
    push(es);
    di = 0xb800;
    es = di;
    ds = di;
    di = 0x1198;
    memoryASet16(es, di, 0xffff);
    memoryASet16(es, di + 2, 0xffff);
    di += 0x2000;
    memoryASet16(es, di, 0x5555);
    memoryASet16(es, di + 2, 0x5555);
    di -= 0x1fb0;
    memoryASet16(es, di, 0x1515);
    memoryASet16(es, di + 2, 0x1515);
    di += 0x2000;
    memoryASet16(es, di, 0x5555);
    memoryASet16(es, di + 2, 0x5555);
    di = 0x3130;
    ah = 0x70;
loc_2f3fd:
    push(di);
    si = di;
    dx = si;
    if (di < 0x2000)
        goto loc_2f40e;
    di -= 0x1fb0;
    goto loc_2f412;
loc_2f40e:
    di += 0x2000;
loc_2f412:
    tx = di;
    di = si;
    si = tx;
    al = 0x07;
loc_2f416:
    cx = 0x001a;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = dx;
    si = di;
    if (di < 0x2000)
        goto loc_2f42b;
    di -= 0x1fb0;
    goto loc_2f42f;
loc_2f42b:
    di += 0x2000;
loc_2f42f:
    tx = di;
    di = si;
    si = tx;
    dx = si;
    al--;
    if (al != 0)
        goto loc_2f416;
    memoryASet(ds, di, 0x0d);
    bl = 0x50;
    bh = ah;
    bh &= 0x03;
    if (bh != 0)
        goto loc_2f445;
    bl = 0x10;
loc_2f445:
    memoryASet(ds, di + 1, bl);
    di++;
    di++;
    push(ax);
    ax = 0;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    ax = pop();
    memoryASet(ds, di, 0x0d);
    memoryASet(ds, di + 1, bl);
    di = pop();
    if (di >= 0x2000)
        goto loc_2f467;
    di += 0x1fb0;
    goto loc_2f46b;
loc_2f467:
    di -= 0x2000;
loc_2f46b:
    cx = 0x000c;
loc_2f46e:
    sub_2c26c();
    if (--cx)
        goto loc_2f46e;
    ah--;
    if (ah != 0)
        goto loc_2f3fd;
    es = pop();
    ds = pop();
    dx = 0x03da;
loc_2f47c:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2f47c;
loc_2f481:
    in(al, dx);
    if (al & 0x08)
        goto loc_2f481;
    sub_2b531();
    sub_2b5e5();
    di = 0x2f18;
    ax = 0;
    cx = 0x0054;
    rep_stosw<MemAuto, DirAuto>();
    flags.carry = false;
}
void sub_2f498()
{
    push(ds);
    push(es);
    si = 0xb800;
    es = si;
    ds = si;
    di = 0x0013;
    ax = 0x006f;
loc_2f4a7:
    si = di;
    if (si < 0x2000)
        goto loc_2f4b6;
    si -= 0x1fb0;
    goto loc_2f4ba;
loc_2f4b6:
    si += 0x2000;
loc_2f4ba:
    cx = 0x0007;
    dx = si;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = dx;
    ax--;
    if (ax != 0)
        goto loc_2f4a7;
    es = pop();
    ds = pop();
    sub_2c26c();
    sub_2f4cf();
}
void sub_2f4cf()
{
    push(cx);
    push(dx);
    push(si);
    push(di);
    callIndirect(cs, memoryAGet16(ds, 0x2d45));
    bx = 0;
    bl = memoryAGet(ds, 0x2d39);
    bx <<= 1;
    bx <<= 1;
    si = 0x2d0d;
    si = memoryAGet16(ds, bx + si);
    sub_2ce3a();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
}
void sub_2f4ee()
{
    si = 0x2f18;
    cx = 0x00a8;
loc_2f4f4:
    push(cx);
    lodsb<MemAuto, DirAuto>();
    push(si);
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    si = 0x30bc;
    si += ax;
    memoryASet16(ds, 0x1415, 0x0000);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(ds, 0x1417, ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(ds, 0x1419, ax);
    sub_2ed5d();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_2f4f4;
    memoryASet16(ds, 0x1415, 0x0000);
    memoryASet16(ds, 0x1417, 0x0001);
    memoryASet16(ds, 0x1419, 0x0000);
    sub_2ed5d();
}
void sub_2f52d()
{
    push(ax);
    push(es);
    ax = 0xb800;
    es = ax;
    di = 0x0bfe;
    sub_2f54f();
    di = 0x0bfe;
    sub_2f577();
    di = 0x088e;
    sub_2f577();
    di = 0x088e;
    sub_2f54f();
    es = pop();
    ax = pop();
}
void sub_2f54f()
{
    si = 0x4890;
    dl = 0x09;
loc_2f554:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di + 4, memoryAGet(es, di + 4) ^ al);
    if (di < 0x2000)
        goto loc_2f56e;
    di -= 0x1fb0;
    goto loc_2f572;
loc_2f56e:
    di += 0x2000;
loc_2f572:
    dl--;
    if (dl != 0)
        goto loc_2f554;
}
void sub_2f577()
{
    ax = 0;
    dl = 0x04;
loc_2f57b:
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    memoryASet(es, di + 4, memoryAGet(es, di + 4) ^ al);
    if (di < 0x2000)
        goto loc_2f592;
    di -= 0x1fb0;
    goto loc_2f596;
loc_2f592:
    di += 0x2000;
loc_2f596:
    dl--;
    if (dl != 0)
        goto loc_2f57b;
    ax = 0x5555;
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    memoryASet(es, di + 4, memoryAGet(es, di + 4) ^ al);
    if (di < 0x2000)
        goto loc_2f5b4;
    di -= 0x1fb0;
    goto loc_2f5b8;
loc_2f5b4:
    di += 0x2000;
loc_2f5b8:
    ax = 0;
    dl = 0x04;
loc_2f5bc:
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    memoryASet(es, di + 4, memoryAGet(es, di + 4) ^ al);
    if (di < 0x2000)
        goto loc_2f5d3;
    di -= 0x1fb0;
    goto loc_2f5d7;
loc_2f5d3:
    di += 0x2000;
loc_2f5d7:
    dl--;
    if (dl != 0)
        goto loc_2f5bc;
}
void sub_2f5dc()
{
    ax = 0xb800;
    es = ax;
    bp = 0x490a;
    bh = 0x01;
loc_2f5e6:
    si = bp;
    bl = 0x04;
loc_2f5ea:
    push(si);
    dx = 0x03da;
loc_2f5ee:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2f5ee;
loc_2f5f3:
    in(al, dx);
    if (al & 0x08)
        goto loc_2f5f3;
    di = 0x1900;
    dl = 0x07;
loc_2f5fd:
    ch = 0;
    cl = bh;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cl = bh;
    di -= cx;
    si -= cx;
    si += 0x000b;
    if (di < 0x2000)
        goto loc_2f618;
    di -= 0x1fb0;
    goto loc_2f61c;
loc_2f618:
    di += 0x2000;
loc_2f61c:
    dl--;
    if (dl != 0)
        goto loc_2f5fd;
    cx = 0x0019;
loc_2f623:
    sub_2c26c();
    if (--cx)
        goto loc_2f623;
    si = pop();
    si += 0x004d;
    bl--;
    if (bl != 0)
        goto loc_2f5ea;
    bh++;
    bp--;
    if (bp != 0x4902)
        goto loc_2f5e6;
    bp = 0x4903;
    bh = 0;
loc_2f63e:
    si = bp;
    bl = 0x04;
loc_2f642:
    push(si);
    dx = 0x03da;
loc_2f646:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2f646;
loc_2f64b:
    in(al, dx);
    if (al & 0x08)
        goto loc_2f64b;
    di = 0x1900;
    ch = 0;
    cl = bh;
    di += cx;
    dl = 0x07;
loc_2f65b:
    cx = 0x0008;
    al = 0x00;
    stosb<MemAuto, DirAuto>();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cl = bh;
    di -= 0x0009;
    si -= 0x0008;
    si += 0x000b;
    if (di < 0x2000)
        goto loc_2f67a;
    di -= 0x1fb0;
    goto loc_2f67e;
loc_2f67a:
    di += 0x2000;
loc_2f67e:
    dl--;
    if (dl != 0)
        goto loc_2f65b;
    cx = 0x0019;
loc_2f685:
    sub_2c26c();
    if (--cx)
        goto loc_2f685;
    si = pop();
    si += 0x004d;
    bl--;
    if (bl != 0)
        goto loc_2f642;
    bh++;
    if (bh != 0x16)
        goto loc_2f63e;
}
void sub_2f69a()
{
    ax = 0xb800;
    es = ax;
    bl = 0x1a;
    bp = 0x488a;
loc_2f6a4:
    ax = 0xb800;
    ds = ax;
    bh = 0x19;
    di = 0x1b33;
    dx = 0x03da;
loc_2f6b1:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_2f6b1;
loc_2f6b6:
    in(al, dx);
    if (al & 0x08)
        goto loc_2f6b6;
loc_2f6bb:
    si = di;
    if (di < 0x2000)
        goto loc_2f6c9;
    di -= 0x1fb0;
    goto loc_2f6cd;
loc_2f6c9:
    di += 0x2000;
loc_2f6cd:
    tx = di;
    di = si;
    si = tx;
    cx = 0x0031;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si -= 0x0031;
    di = si;
    bh--;
    if (bh != 0)
        goto loc_2f6bb;
    ax = 0x1c46;
    ds = ax;
    si = bp;
    di = 0x3ef3;
    cx = 0x0031;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    bp = si;
    cx = 0x0019;
loc_2f6f1:
    sub_2c26c();
    if (--cx)
        goto loc_2f6f1;
    bl--;
    if (bl != 0)
        goto loc_2f6a4;
    ax = 0x1000;
    ds = ax;
}
void sub_2f700()
{
    push(ax);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(ds);
    push(es);
    sub_2acb0();
    ax = 0xb800;
    ds = ax;
    ax = 0x1000;
    es = ax;
    si = 0;
    di = 0x1aef;
    cx = 0x07d0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    dx = 0x03d8;
    al = 0x09;
    out(dx, al);
    si = 0x4b91;
    sub_2f79a();
    ax = 0x1c46;
    ds = ax;
    ax = 0xb800;
    es = ax;
    cx = 0xffff;
    ah = 0x01;
    interrupt(0x10);
    di = 0;
    si = 0x2298;
    ah = 0x07;
loc_2f742:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2f75e;
    if (al != 0x5b)
        goto loc_2f74f;
    ah = 0x70;
    goto loc_2f742;
loc_2f74f:
    if (al != 0x9c)
        goto loc_2f757;
    ah = 0x07;
    goto loc_2f742;
loc_2f757:
    if (al == 0x24)
        goto loc_2f766;
    stosw<MemAuto, DirAuto>();
    goto loc_2f742;
loc_2f75e:
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    return;
loc_2f766:
    cx = 0x0008;
    al = 0x20;
    rep_stosw<MemAuto, DirAuto>();
    goto loc_2f742;
}
void sub_2f76f()
{
    push(es);
    push(ax);
    push(cx);
    push(dx);
    push(si);
    push(di);
    dx = 0x03d8;
    al = 0x0e;
    out(dx, al);
    si = 0x4b9d;
    sub_2f79a();
    ax = 0xb800;
    es = ax;
    di = 0;
    si = 0x1aef;
    cx = 0x07d0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    sub_2aca5();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    es = pop();
}
void sub_2f79a()
{
    dx = 0x03d0;
    ah = 0;
    cx = 0x000c;
loc_2f7a2:
    al = ah;
    out(dx, al);
    dx++;
    ah++;
    al = memoryAGet(cs, si);
    out(dx, al);
    si++;
    dx--;
    if (--cx)
        goto loc_2f7a2;
}
void sub_2f7c9()
{
    push(ax);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(es);
    sub_2acb0();
    ax = 0xb800;
    cx = ds;
    ds = ax;
    es = cx;
    si = 0x1900;
    di = 0x1aef;
    dl = 0x14;
loc_2f7e3:
    cx = 0x0019;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x001e;
    dl--;
    if (dl != 0)
        goto loc_2f7e3;
    si = 0x3900;
    dl = 0x14;
loc_2f7f4:
    cx = 0x0019;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x001e;
    dl--;
    if (dl != 0)
        goto loc_2f7f4;
    ax = es;
    cx = ds;
    ds = ax;
    es = cx;
    di = 0x1900;
    si = 0x93e0;
    dl = 0x26;
loc_2f810:
    cx = 0x0032;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di -= 0x0032;
    if (di < 0x2000)
        goto loc_2f824;
    di -= 0x1fb0;
    goto loc_2f828;
loc_2f824:
    di += 0x2000;
loc_2f828:
    dl--;
    if (dl != 0)
        goto loc_2f810;
    es = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_2f833()
{
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(es);
    cx = 0xb800;
    es = cx;
    di = 0x1900;
    si = 0x1aef;
    dl = 0x14;
loc_2f845:
    cx = 0x0019;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x001e;
    dl--;
    if (dl != 0)
        goto loc_2f845;
    di = 0x3900;
    dl = 0x14;
loc_2f856:
    cx = 0x0019;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x001e;
    dl--;
    if (dl != 0)
        goto loc_2f856;
    sub_2aca5();
    es = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
}
void sub_2f86b()
{
    flags.interrupts = false;
    push(es);
    push(ds);
    push(ax);
    push(cx);
    ah = 0;
    al -= 0x06;
    ch = cl;
    cl = 0x04;
    ax <<= cl;
    si = ax;
    ax <<= 1;
    si += ax;
    si += 0x28f0;
    cl = ch;
    ch = 0;
    cx >>= 1;
    cx >>= 1;
    cx--;
    cx--;
    si += cx;
    ax = 0xb800;
    es = ax;
    ax = 0x1c46;
    ds = ax;
    cx = pop();
    ax = pop();
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2f8ac;
    di += 0x2000;
loc_2f8ac:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = 0x0008;
loc_2f8bd:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ ax);
    si += 0x002c;
    if (di < 0x2000)
        goto loc_2f8d7;
    di -= 0x1fb0;
    if (--cx)
        goto loc_2f8bd;
    goto loc_2f8dd;
loc_2f8d7:
    di += 0x2000;
    if (--cx)
        goto loc_2f8bd;
loc_2f8dd:
    ds = pop();
    es = pop();
    flags.interrupts = true;
}
void sub_2f8e1()
{
    flags.interrupts = false;
    push(es);
    push(ds);
    push(ax);
    push(cx);
    ah = 0;
    al -= 0x06;
    ch = cl;
    cl = 0x04;
    ax <<= cl;
    si = ax;
    ax <<= 1;
    si += ax;
    si += 0x28f0;
    cl = ch;
    ch = 0;
    cx >>= 1;
    cx >>= 1;
    cx--;
    cx--;
    si += cx;
    ax = 0xb800;
    es = ax;
    ax = 0x1c46;
    ds = ax;
    cx = pop();
    ax = pop();
    ch = 0;
    di = cx;
    di >>= 1;
    di >>= 1;
    flags.carry = al & 1;
    al >>= 1;
    if (!flags.carry)
        goto loc_2f922;
    di += 0x2000;
loc_2f922:
    ah = 0;
    cl = 0x04;
    ax <<= cl;
    di += ax;
    ax <<= 1;
    ax <<= 1;
    di += ax;
    cx = 0x0008;
loc_2f933:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, ax);
    si += 0x002c;
    if (di < 0x2000)
        goto loc_2f94d;
    di -= 0x1fb0;
    if (--cx)
        goto loc_2f933;
    goto loc_2f953;
loc_2f94d:
    di += 0x2000;
    if (--cx)
        goto loc_2f933;
loc_2f953:
    ds = pop();
    es = pop();
    flags.interrupts = true;
}
void sub_2f957()
{
    dl = memoryAGet(ds, 0x3f08);
    di = 0x3ef6;
    si = 0x1aef;
    dh = 0x0a;
loc_2f963:
    push(dx);
    push(di);
    bp = si;
    sub_2f97d();
    si = bp;
    cx = 0x0009;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = bp;
    si += 0x0012;
    di = pop();
    dx = pop();
    dl--;
    if (dl != 0)
        goto loc_2f963;
}
void sub_2f97d()
{
    si += 0x000c;
    di += 0x000c;
loc_2f983:
    push(si);
    push(di);
    di -= 0x0012;
    cl = 0x06;
loc_2f98a:
    al = memoryAGet(ds, si);
    si++;
    flags.zero = memoryAGet(es, di++) == al;
    if (stop(/*1 - ja loc_2f99c*/))
        goto loc_2f99c;
    if (stop(/*1 - jb loc_2f996*/))
        goto loc_2f996;
    cl--;
    if (cl != 0)
        goto loc_2f98a;
loc_2f996:
    di = pop();
    si = pop();
    di -= 0x000c;
    return;
loc_2f99c:
    di = pop();
    di -= 0x000c;
    si = di;
    si -= 0x0012;
    cx = 0x0009;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di -= 0x0018;
    si = pop();
    dh--;
    if (dh != 0)
        goto loc_2f983;
    di -= 0x000c;
}
void sub_2f9b6()
{
    al = memoryAGet(ds, 0x141b);
//    sub_2fa0a();
    if (!flags.carry)
        goto loc_2f9bf;
loc_2f9be:
    return;
loc_2f9bf:
    ah = 0x3d;
    al = 0;
    dx = 0x141c;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2f9be;
    bx = ax;
    ah = 0x3f;
    dx = 0x3e42;
    cx = 0x00b4;
    interrupt(0x21);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_2f9db()
{
    al = memoryAGet(ds, 0x141b);
    sub_2fa24();
    if (!flags.carry)
        goto loc_2f9e4;
loc_2f9e3:
    return;
loc_2f9e4:
    ah = 0x3d;
    al = 0x01;
    dx = 0x141c;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2f9e3;
    bx = ax;
    ah = 0x42;
    al = 0x00;
    cx = 0;
    dx = 0;
    interrupt(0x21);
    ah = 0x40;
    dx = 0x3e42;
    cx = 0x00b4;
    interrupt(0x21);
    ah = 0x3e;
    interrupt(0x21);
}
// INJECT: Error: cannot inject carry flag in sub_2fa0a()!
void sub_2fa0a()
{
    push(bp);
    push(ax);
    ah = 0x00;
    interrupt(0x13);
    ah = 0x0d;
    interrupt(0x21);
    ax = pop();
    push(ax);
    dx = 0;
    cx = 0x0001;
    bx = 0x0000;
    interrupt(0x25);
    cx = pop();
    ax = pop();
    bp = pop();
    stop(/*inject ret*/);
}
// INJECT: Error: cannot inject carry flag in sub_2fa24()!
// INJECT: Error: cannot inject carry flag in sub_2fa24()!
void sub_2fa24()
{
    sub_2fa0a();
    if (!flags.carry)
        goto loc_2fa2a;
    stop(/*inject ret*/);
    return;
loc_2fa2a:
    push(ax);
    push(bp);
    dx = 0;
    cx = 0x0001;
    bx = 0x0000;
    interrupt(0x26);
    cx = pop();
    bp = pop();
    ax = pop();
    stop(/*inject ret*/);
}
void sub_2fa3a()
{
    push(es);
    ax = 0xb800;
    es = ax;
    sub_2fb93();
    di = 0x0142;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di = 0x2142;
    dl = 0x07;
    al = 0x20;
    sub_2bce5();
    al = 0x48;
    sub_2b884();
    di++;
    di++;
    al = 0x49;
    sub_2b884();
    di++;
    di++;
    al = 0x47;
    sub_2b884();
    di++;
    di++;
    al = 0x48;
    sub_2b884();
    di++;
    di++;
    al = 0x20;
    sub_2b884();
    di++;
    di++;
    al = 0x53;
    sub_2b884();
    di++;
    di++;
    al = 0x43;
    sub_2b884();
    di++;
    di++;
    al = 0x4f;
    sub_2b884();
    di++;
    di++;
    al = 0x52;
    sub_2b884();
    di++;
    di++;
    al = 0x45;
    sub_2b884();
    di++;
    di++;
    dl = 0x07;
    al = 0x20;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x05;
    al = 0x20;
    sub_2bce5();
    dl = 0x0e;
    al = 0x2d;
    sub_2bce5();
    al = 0x20;
    dl = 0x05;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x18;
    al = 0x20;
    sub_2bce5();
    di += 0x01b0;
    dl = 0x0a;
    si = 0x3e42;
loc_2fad2:
    push(dx);
    push(si);
    dl = 0x02;
    al = 0x20;
    sub_2bce5();
    si = pop();
    dl = 0x0c;
    sub_2bcf1();
    push(si);
    dl = 0x02;
    al = 0x20;
    sub_2bce5();
    si = pop();
    dl = 0x06;
    sub_2bcf1();
    al = 0x20;
    dl = 0x02;
    push(si);
    sub_2bce5();
    si = pop();
    di += 0x01b0;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2fb13;
    di -= 0x1fb0;
    goto loc_2fb17;
loc_2fb13:
    di += 0x2000;
loc_2fb17:
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2fb2b;
    di -= 0x1fb0;
    goto loc_2fb2f;
loc_2fb2b:
    di += 0x2000;
loc_2fb2f:
    dx = pop();
    dl--;
    if (dl != 0)
        goto loc_2fad2;
loc_2fb34:
    if (di == 0x1e02)
        goto loc_2fb57;
    ax = 0xaaaa;
    cx = 0x0018;
    rep_stosw<MemAuto, DirAuto>();
    di -= 0x0030;
    if (di < 0x2000)
        goto loc_2fb51;
    di -= 0x1fb0;
    goto loc_2fb55;
loc_2fb51:
    di += 0x2000;
loc_2fb55:
    goto loc_2fb34;
loc_2fb57:
    dl = 0xff;
loc_2fb59:
    cx = 0x0181;
loc_2fb5c:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2fb68;
    ah = 0;
    interrupt(0x16);
    es = pop();
    return;
loc_2fb68:
    sub_2c26c();
    if (--cx)
        goto loc_2fb5c;
    push(dx);
    sub_2fb78();
    dx = pop();
    dl--;
    if (dl != 0)
        goto loc_2fb59;
    es = pop();
}
void sub_2fb78()
{
    si = 0x507d;
    dh = 0x0e;
loc_2fb7d:
    di = memoryAGet16(cs, si);
    sub_2fc11();
    sub_2fbc7();
    sub_2fbf3();
    memoryASet16(cs, si, di);
    si++;
    si++;
    dh--;
    if (dh != 0)
        goto loc_2fb7d;
}
void sub_2fb93()
{
    di = 0;
    sub_2fc39();
    di = 0x1e00;
    sub_2fc39();
    di = 0x0140;
    sub_2fc65();
    di = 0x0172;
    sub_2fc65();
    di = 0;
    si = 0x507d;
    cl = 0x0e;
loc_2fbb1:
    memoryASet16(cs, si, di);
    si++;
    si++;
    sub_2fbf3();
    ch = 0x07;
loc_2fbbb:
    sub_2fbc7();
    ch--;
    if (ch != 0)
        goto loc_2fbbb;
    cl--;
    if (cl != 0)
        goto loc_2fbb1;
}
void sub_2fbc7()
{
    ax = di;
    bl = 0x50;
    div(bl);
    if (!al)
        goto loc_2fbe6;
    if (al != 0x60)
        goto loc_2fbdc;
    if (!ah)
        goto loc_2fbee;
    di--;
    di--;
    return;
loc_2fbdc:
    if (ah != 0x32)
        goto loc_2fbee;
loc_2fbe1:
    di += 0x0140;
    return;
loc_2fbe6:
    if (ah == 0x32)
        goto loc_2fbe1;
    di++;
    di++;
    return;
loc_2fbee:
    di -= 0x0140;
}
void sub_2fbf3()
{
    push(di);
    dl = 0x08;
    ax = 0;
loc_2fbf8:
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2fc07;
    di -= 0x1fb0;
    goto loc_2fc0b;
loc_2fc07:
    di += 0x2000;
loc_2fc0b:
    dl--;
    if (dl != 0)
        goto loc_2fbf8;
    di = pop();
}
void sub_2fc11()
{
    push(si);
    push(di);
    si = 0x506d;
    dl = 0x08;
    ax = 0;
loc_2fc1a:
    ax = memoryAGet16(cs, si);
    si++;
    si++;
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2fc2e;
    di -= 0x1fb0;
    goto loc_2fc32;
loc_2fc2e:
    di += 0x2000;
loc_2fc32:
    dl--;
    if (dl != 0)
        goto loc_2fc1a;
    di = pop();
    si = pop();
}
void sub_2fc39()
{
    bl = 0x1a;
loc_2fc3b:
    si = 0x506d;
    push(di);
    cl = 0x08;
loc_2fc41:
    ax = memoryAGet16(cs, si);
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2fc53;
    di -= 0x1fb0;
    goto loc_2fc57;
loc_2fc53:
    di += 0x2000;
loc_2fc57:
    si++;
    si++;
    cl--;
    if (cl != 0)
        goto loc_2fc41;
    di = pop();
    di++;
    di++;
    bl--;
    if (bl != 0)
        goto loc_2fc3b;
}
void sub_2fc65()
{
    bl = 0x17;
loc_2fc67:
    si = 0x506d;
    cl = 0x08;
loc_2fc6c:
    ax = memoryAGet16(cs, si);
    memoryASet16(es, di, ax);
    if (di < 0x2000)
        goto loc_2fc7e;
    di -= 0x1fb0;
    goto loc_2fc82;
loc_2fc7e:
    di += 0x2000;
loc_2fc82:
    si++;
    si++;
    cl--;
    if (cl != 0)
        goto loc_2fc6c;
    bl--;
    if (bl != 0)
        goto loc_2fc67;
}
void sub_2fcb9()
{
    push(ds);
    push(es);
    ax = 0x1c46;
    es = ax;
    ax = 0xb800;
    ds = ax;
    flags.interrupts = false;
    di = 0x3df0;
    si = 0;
    cx = 0x0fa0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si = 0x2000;
    cx = 0x0fa0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    flags.interrupts = true;
    es = pop();
    ds = pop();
}
void sub_2fcdc()
{
    push(ds);
    push(es);
    ax = 0x1c46;
    ds = ax;
    ax = 0xb800;
    es = ax;
    flags.interrupts = false;
    si = 0x3df0;
    di = 0;
    cx = 0x0fa0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x2000;
    cx = 0x0fa0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    flags.interrupts = true;
    es = pop();
    ds = pop();
}
void sub_2fcff()
{
    if (memoryAGet(ds, 0x13c4) != 0x02)
        goto loc_2fd2a;
    memoryASet(ds, 0x13c4, 0x80);
    memoryASet16(ds, 0x13c5, memoryAGet16(ds, 0x13c5) + 1);
    si = memoryAGet16(ds, 0x13c5);
    al = memoryAGet(ds, si);
    al ^= 0xaa;
    al -= 0x20;
    cl = 0x06;
    mul(cl);
    ax += 0xa3c0;
    si = ax;
    di = 0x0000;
    cx = 0x0003;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_2fd2a:
    push(es);
    ax = 0xb800;
    es = ax;
    sub_2fd60();
    si = 0x0000;
    di = 0x38a9;
    cl = 0x06;
loc_2fd3b:
    lodsb<MemAuto, DirAuto>();
    al &= memoryAGet(ds, 0x13c4);
    if (al == 0)
        goto loc_2fd46;
    memoryASet(es, di, memoryAGet(es, di) ^ 0x03);
loc_2fd46:
    if (di < 0x2000)
        goto loc_2fd52;
    di -= 0x1fb0;
    goto loc_2fd56;
loc_2fd52:
    di += 0x2000;
loc_2fd56:
    cl--;
    if (cl != 0)
        goto loc_2fd3b;
    memoryASet(ds, 0x13c4, memoryAGet(ds, 0x13c4) >> 1);
    es = pop();
}
void sub_2fd60()
{
    ch = 0x06;
    di = 0x38a9;
loc_2fd65:
    cl = 0x02;
loc_2fd67:
    push(di);
    flags.carry = memoryAGet(es, di) >> 7;
    memoryASet(es, di, memoryAGet(es, di) << 1);
    di--;
    bl = 0x0d;
loc_2fd6f:
    //TODO: stop(/*carry2*/); - scrolling text
    memoryASet(es, di, rcl(memoryAGet(es, di), 1));
    di--;
    bl--;
    if (bl != 0)
        goto loc_2fd6f;
    di = pop();
    cl--;
    if (cl != 0)
        goto loc_2fd67;
    if (di < 0x2000)
        goto loc_2fd88;
    di -= 0x1fb0;
    goto loc_2fd8c;
loc_2fd88:
    di += 0x2000;
loc_2fd8c:
    ch--;
    if (ch != 0)
        goto loc_2fd65;
}
void sub_2fd91()
{
    push(ax);
    bx = memoryAGet16(ds, 0x3f1c);
    bl = memoryAGet(ds, bx);
    if (al != bl)
        goto loc_2fdae;
    if (bl != 0x0d)
        goto loc_2fda8;
    memoryASet(ds, 0x3f1b, 0x01);
    ax = pop();
    return;
loc_2fda8:
    memoryASet16(ds, 0x3f1c, memoryAGet16(ds, 0x3f1c) + 1);
    ax = pop();
    return;
loc_2fdae:
    memoryASet16(ds, 0x3f1c, 0x3f0b);
    ax = pop();
}
void sub_2fdb6()
{
    memoryASet(ds, 0x13c8, memoryAGet(ds, 0x13c8) + 0x10);
    if (memoryAGet(ds, 0x13c8) != 0x00)
        goto loc_2fdce;
    memoryASet(ds, 0x13c7, memoryAGet(ds, 0x13c7) ^ 0x04);
    al = memoryAGet(ds, 0x13c7);
    dx = 0x03d8;
    out(dx, al);
loc_2fdce:
    al = memoryAGet(ds, 0x13c8);
    dx = 0x03d9;
    out(dx, al);
}
void sub_2fdd6()
{
    push(es);
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xb800;
    ds = ax;
    di = 0x0000;
    si = 0x0008;
    cx = 0x0096;
loc_2fdea:
    bp = cx;
    cx = 0x0021;
    bx = si;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = bx;
    if (si < 0x2000)
        goto loc_2fe01;
    si -= 0x1fb0;
    goto loc_2fe05;
loc_2fe01:
    si += 0x2000;
loc_2fe05:
    cx = bp;
    if (--cx)
        goto loc_2fdea;
    ax = 0x1000;
    ds = ax;
    memoryASet16(ds, 0x13c0, 0x0008);
    memoryASet16(ds, 0x13c2, 0x0021);
    cx = 0x0087;
loc_2fe1d:
    push(cx);
    ax = 0x1000;
    es = ax;
    ds = ax;
    di = 0x1aef;
    si = memoryAGet16(ds, 0x13c2);
    cx = 0x01ef;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = 0xa6d0;
    di = 0x1aef;
    cx = 0x01ef;
loc_2fe3a:
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, di);
    bh = al;
    dx = ax;
    al &= 0xc0;
    if (al != 0)
        goto loc_2fe4d;
    ah &= 0xc0;
    bh += ah;
    ah = dh;
loc_2fe4d:
    al = dl;
    al &= 0x30;
    if (al != 0)
        goto loc_2fe5a;
    ah &= 0x30;
    bh += ah;
    ah = dh;
loc_2fe5a:
    al = dl;
    al &= 0x0c;
    if (al != 0)
        goto loc_2fe67;
    ah &= 0x0c;
    bh += ah;
    ah = dh;
loc_2fe67:
    al = dl;
    al &= 0x03;
    if (al != 0)
        goto loc_2fe72;
    ah &= 0x03;
    bh += ah;
loc_2fe72:
    memoryASet(ds, di, bh);
    di++;
    si++;
    if (--cx)
        goto loc_2fe3a;
    ax = 0xb800;
    es = ax;
    di = memoryAGet16(ds, 0x13c0);
    si = memoryAGet16(ds, 0x13c2);
    cx = 0x0021;
    si -= cx;
    bx = di;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di < 0x2000)
        goto loc_2fe9c;
    di -= 0x1fb0;
    goto loc_2fea0;
loc_2fe9c:
    di += 0x2000;
loc_2fea0:
    memoryASet16(ds, 0x13c0, di);
    si = 0x1aef;
    cx = 0x000f;
loc_2feaa:
    bp = cx;
    cx = 0x0021;
    bx = di;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di < 0x2000)
        goto loc_2fec1;
    di -= 0x1fb0;
    goto loc_2fec5;
loc_2fec1:
    di += 0x2000;
loc_2fec5:
    cx = bp;
    if (--cx)
        goto loc_2feaa;
    memoryASet16(ds, 0x13c2, memoryAGet16(ds, 0x13c2) + 0x0021);
    cx = pop();
    cx--;
    if (cx == 0)
        goto loc_2fed5;
    goto loc_2fe1d;
loc_2fed5:
    cx = 0x1c20;
loc_2fed8:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2fee5;
    ah = 0x00;
    interrupt(0x16);
    goto loc_2ff34;
loc_2fee5:
    sub_2c26c();
    if (--cx)
        goto loc_2fed8;
    ds = pop();
    ax = 0xb800;
    es = ax;
    bx = 0xa8bf;
    di = 0x34f0;
    dh = 0x07;
loc_2fef8:
    push(di);
    di += memoryAGet16(ds, bx);
    bp = di;
    bx++;
    bx++;
    si = memoryAGet16(ds, bx);
    bx++;
    bx++;
    sub_2ffad();
    if (flags.carry)
        goto loc_2ff2c;
    di = bp;
    sub_2ffad();
    di = bp;
    si = 0xabab;
    sub_2ffad();
    if (flags.carry)
        goto loc_2ff2c;
    di = bp;
    sub_2ffad();
    if (flags.carry)
        goto loc_2ff2c;
    di = bp;
    sub_2ffad();
    if (flags.carry)
        goto loc_2ff2c;
    di = pop();
    dh--;
    if (dh == 0)
        goto loc_2ff2d;
    goto loc_2fef8;
loc_2ff2c:
    di = pop();
loc_2ff2d:
    if (stop(/*1 - jb loc_2ff32*/))
        goto loc_2ff32;
    sub_2ff37();
loc_2ff32:
    es = pop();
    return;
loc_2ff34:
    ds = pop();
    es = pop();
}
void sub_2ff37()
{
    di = 0x34f8;
    dh = 0x08;
loc_2ff3c:
    bx = 0xb7a2;
loc_2ff3f:
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_2ff7f;
    push(di);
    si = memoryAGet16(ds, bx);
    ch = 0x0f;
loc_2ff4a:
    bp = di;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    si++;
    di = bp;
    if (di < 0x2000)
        goto loc_2ff5d;
    di -= 0x1fb0;
    goto loc_2ff61;
loc_2ff5d:
    di += 0x2000;
loc_2ff61:
    ch--;
    if (ch != 0)
        goto loc_2ff4a;
    di = pop();
    bx++;
    bx++;
    cx = 0x0064;
loc_2ff6b:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2ff78;
    ah = 0;
    interrupt(0x16);
    return;
loc_2ff78:
    sub_2c26c();
    if (--cx)
        goto loc_2ff6b;
    goto loc_2ff3f;
loc_2ff7f:
    ax = 0;
    push(di);
    ch = 0x0f;
loc_2ff84:
    bp = di;
    stosw<MemAuto, DirAuto>();
    stosw<MemAuto, DirAuto>();
    di = bp;
    if (di < 0x2000)
        goto loc_2ff96;
    di -= 0x1fb0;
    goto loc_2ff9a;
loc_2ff96:
    di += 0x2000;
loc_2ff9a:
    ch--;
    if (ch != 0)
        goto loc_2ff84;
    di = pop();
    if (dh != 0x05)
        goto loc_2ffa5;
    di++;
loc_2ffa5:
    di += 0x0004;
    dh--;
    if (dh != 0)
        goto loc_2ff3c;
}
void sub_2ffad()
{
    cl = 0x0f;
loc_2ffaf:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di + 2, ax);
    if (di < 0x2000)
        goto loc_2ffc4;
    di -= 0x1fb0;
    goto loc_2ffc8;
loc_2ffc4:
    di += 0x2000;
loc_2ffc8:
    cl--;
    if (cl != 0)
        goto loc_2ffaf;
    cx = 0x04b0;
loc_2ffcf:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2ffdc;
    ah = 0;
    interrupt(0x16);
    goto loc_2ffe0;
loc_2ffdc:
    if (--cx)
        goto loc_2ffcf;
    flags.carry = false;
    return;
loc_2ffe0:
    flags.carry = true;
}
void sub_2ffe2()
{
    si = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_2ffe9:
    bp = cx;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_3000f;
    cx = ax;
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_3000f;
    dx = ax;
    ax = 0x0c83;
    interrupt(0x10);
loc_3000f:
    dx = 0;
    ax = memoryAGet16(ds, si + 12);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + ax);
    cx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, si + 14);
    imul(cx);
    imul(cx);
    cx = 0x0064;
    idiv(cx);
    memoryASet16(ds, si + 8, ax);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_3004a;
    dx = ax;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_3004a;
    cx = ax;
    ax = 0x0c83;
    interrupt(0x10);
loc_3004a:
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_30063;
loc_30058:
    si += 0x0010;
    cx = bp;
    sub_2c26c();
    if (--cx)
        goto loc_2ffe9;
    return;
loc_30063:
    sub_300aa();
    goto loc_30058;
}
void sub_30068()
{
    di = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_3006f:
    ax += memoryAGet16(ds, di);
    di++;
    di++;
    if (--cx)
        goto loc_3006f;
    cx = ds;
    bx = 0;
    ds = bx;
    ax += memoryAGet16(ds, 0x046c);
    ax += memoryAGet16(ds, 0x046e);
    ds = cx;
    ax += memoryAGet16(ds, 0x1acd);
    cx = dx;
    dx = 0;
    div(cx);
    memoryASet16(ds, 0x1acd, memoryAGet16(ds, 0x1acd) + ax);
    ax = dx;
}
void sub_30096()
{
    si = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_3009d:
    bp = cx;
    sub_300aa();
    si += 0x0010;
    cx = bp;
    if (--cx)
        goto loc_3009d;
}
void sub_300aa()
{
    memoryASet16(ds, si, 0x0068);
    memoryASet16(ds, si + 2, 0x00a0);
    dx = 0x0006;
    sub_30068();
    ax += 0x0008;
    memoryASet16(ds, si + 14, ax);
    dx = 0x0046;
    sub_30068();
    ax -= 0x0023;
    if (ax != 0)
        goto loc_300cd;
    ax = 0x000a;
loc_300cd:
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, ax);
    dx = 0xffff;
    if (ax < 0x8000)
        goto loc_300de;
    dx = 0x0001;
loc_300de:
    memoryASet16(ds, si + 12, dx);
    ax = memoryAGet16(ds, si + 14);
    imul(memoryAGet16(ds, si + 4));
    imul(memoryAGet16(ds, si + 4));
    cx = 0x0064;
    idiv(cx);
    memoryASet16(ds, si + 10, ax);
    memoryASet16(ds, si + 8, ax);
}
void sub_300f6()
{
    push(ds);
    ax = 0x1c46;
    ds = ax;
    ax = 0xb800;
    es = ax;
    flags.direction = true;
    si = 0x7c6e;
    di = 0x3f3f;
    cx = 0x005b;
loc_3010b:
    bp = cx;
    bx = di;
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di > 0x2000)
        goto loc_30122;
    di += 0x1fb0;
    goto loc_30126;
loc_30122:
    di -= 0x2000;
loc_30126:
    bx = di;
    ax = 0xffff;
    cx = 0x000a;
    di -= 0x0004;
    rep_stosw<MemAuto, DirAuto>();
    di = bx;
    cx = 0x0032;
loc_30138:
    sub_2c26c();
    if (--cx)
        goto loc_30138;
    cx = bp;
    if (--cx)
        goto loc_3010b;
    si = 0x7c6e;
    di = 0x3f3f;
    cx = 0x005a;
loc_3014a:
    bp = cx;
    bx = di;
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di > 0x2000)
        goto loc_30161;
    di += 0x1fb0;
    goto loc_30165;
loc_30161:
    di -= 0x2000;
loc_30165:
    bx = di;
    ax = 0xffff;
    cx = 0x000a;
    di -= 0x0004;
loc_30170:
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di--;
    di--;
    if (--cx)
        goto loc_30170;
    di = bx;
    cx = 0x0032;
loc_3017c:
    sub_2c26c();
    if (--cx)
        goto loc_3017c;
    cx = bp;
    if (--cx)
        goto loc_3014a;
    flags.direction = false;
    si = 0x6b60;
    di = 0x3119;
    cx = 0x005b;
loc_3018f:
    bp = cx;
    bx = di;
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di > 0x2000)
        goto loc_301a6;
    di += 0x2000;
    goto loc_301aa;
loc_301a6:
    di -= 0x1fb0;
loc_301aa:
    bx = di;
    ax = 0xffff;
    cx = 0x000a;
    rep_stosw<MemAuto, DirAuto>();
    di = bx;
    cx = 0x0032;
loc_301b9:
    sub_2c26c();
    if (--cx)
        goto loc_301b9;
    cx = bp;
    if (--cx)
        goto loc_3018f;
    si = 0x6b60;
    di = 0x1119;
    cx = 0x005c;
loc_301cb:
    bp = cx;
    bx = di;
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = bx;
    if (di > 0x2000)
        goto loc_301e2;
    di += 0x2000;
    goto loc_301e6;
loc_301e2:
    di -= 0x1fb0;
loc_301e6:
    bx = di;
    ax = 0xffff;
    cx = 0x000a;
loc_301ee:
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di++;
    di++;
    if (--cx)
        goto loc_301ee;
    di = bx;
    cx = 0x0032;
loc_301fa:
    sub_2c26c();
    if (--cx)
        goto loc_301fa;
    cx = bp;
    if (--cx)
        goto loc_301cb;
    ds = pop();
}
void sub_30205()
{
    dl = 0x34;
    di = 0x0230;
loc_3020a:
    bx = di;
    al = 0xc0;
    dh = 0x04;
loc_30210:
    al &= 0x55;
    bp = di;
    cl = 0x07;
loc_30216:
    memoryASet(es, di, al);
    di += 0x0370;
    cl--;
    if (cl != 0)
        goto loc_30216;
    cx = 0x0019;
loc_30224:
    sub_2c26c();
    if (--cx)
        goto loc_30224;
    flags.carry = true;
    al = rcr(al, 0x01);
    flags.carry = true;
    al = rcr(al, 0x01);
    di = bp;
    dh--;
    if (dh != 0)
        goto loc_30210;
    di = bx;
    di++;
    dl--;
    if (dl != 0)
        goto loc_3020a;
    push(ds);
    ax = 0x1c46;
    ds = ax;
    si = 0x4db7;
    bp = 0x00a0;
    dh = 0x07;
loc_3024a:
    push(si);
    bx = 0x0001;
loc_3024e:
    push(si);
    di = bp;
    push(dx);
    dx = 0x03da;
loc_30255:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_30255;
loc_3025a:
    in(al, dx);
    if (al & 0x08)
        goto loc_3025a;
    dx = pop();
    dl = 0x15;
loc_30262:
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si -= bx;
    si += 0x0034;
    di -= bx;
    if (di < 0x2000)
        goto loc_30279;
    di -= 0x1fb0;
    goto loc_3027d;
loc_30279:
    di += 0x2000;
loc_3027d:
    dl--;
    if (dl != 0)
        goto loc_30262;
    si = pop();
    si--;
    cx = 0x000a;
loc_30286:
    sub_2c26c();
    if (--cx)
        goto loc_30286;
    bx++;
    if (bx != 0x0035)
        goto loc_3024e;
    si = pop();
    si += 0x0444;
    bp += 0x0370;
    dh--;
    if (dh != 0)
        goto loc_3024a;
    ds = pop();
}
void sub_302a0()
{
    push(es);
    ax = 0x3568;
    interrupt(0x21);
    if (bx == 0x0001)
        goto loc_302b4;
    if (bx)
        goto loc_302ba;
    bx = 0x006f;
    goto loc_302ba;
loc_302b4:
    memoryASet(cs, 0x164c, 0xc3);
loc_302ba:
    bx--;
    memoryASet16(cs, 0x164e, bx);
    es = pop();
}
void sub_304d3()
{
    push(si);
    si = memoryAGet16(cs, 0x56a2);
    al ^= 0xaa;
    if (al != memoryAGet(cs, si))
        goto loc_304f3;
    memoryASet(cs, 0x56a4, al);
    memoryASet16(cs, 0x56a2, memoryAGet16(cs, 0x56a2) + 1);
    if (memoryAGet(cs, si + 1) == 0xaa)
        goto loc_3050c;
    si = pop();
    flags.carry = true;
    return;
loc_304f3:
    si = pop();
    if (memoryAGet(cs, 0x56a4) == al)
        goto loc_3050a;
    memoryASet16(cs, 0x56a2, 0x56a5);
    memoryASet(cs, 0x56a4, 0x00);
    flags.carry = false;
    return;
loc_3050a:
    flags.carry = true;
    return;
loc_3050c:
    ax = 0x0003;
    interrupt(0x10);
    push(dx);
    push(di);
    push(ds);
    push(es);
    ax = 0xb800;
    es = ax;
    ax = 0x2ac2;
    ds = ax;
    ah = 0x20;
    si = 0x56b5;
    di = 0;
    dx = 0;
loc_30528:
    lodsb<MemAuto, DirAuto>();
    al ^= ah;
    al ^= 0xaa;
    ah = al;
    if (!al)
        goto loc_30543;
    if (al == 0x5c)
        goto loc_3053b;
    stosb<MemAuto, DirAuto>();
    di++;
    goto loc_30528;
loc_3053b:
    dx += 0x00a0;
    di = dx;
    goto loc_30528;
loc_30543:
    es = pop();
    ds = pop();
    di = pop();
    dx = pop();
    ah = 0;
    interrupt(0x16);
    ax = 0x0005;
    interrupt(0x10);
    memoryASet16(cs, 0x56a2, 0x56a5);
    memoryASet(cs, 0x56a4, 0xff);
    si = pop();
    flags.carry = false;
}
void sub_30560()
{
    dl = 0x32;
loc_30562:
    cx = 0x00c8;
loc_30565:
    sub_2c26c();
    if (--cx)
        goto loc_30565;
    dl--;
    if (dl != 0)
        goto loc_30562;
    di = 0x2f18;
    ax = 0;
    cx = 0x0054;
    rep_stosw<MemAuto, DirAuto>();
    sub_2cad9();
    push(es);
    push(ds);
    ax = 0xb800;
    es = ax;
    ax = 0x1c46;
    ds = ax;
    bh = 0x01;
    bp = 0x3ef2;
loc_3058c:
    bl = bh;
    di = bp;
    si = 0x7c70;
    dx = 0x03da;
loc_30596:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_30596;
loc_3059b:
    in(al, dx);
    if (al & 0x08)
        goto loc_3059b;
loc_305a0:
    cx = 0x000d;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di -= 0x001a;
    if (di < 0x2000)
        goto loc_305b4;
    di -= 0x1fb0;
    goto loc_305b8;
loc_305b4:
    di += 0x2000;
loc_305b8:
    bl--;
    if (bl != 0)
        goto loc_305a0;
    if (bp < 0x2000)
        goto loc_305c8;
    bp -= 0x2000;
    goto loc_305cc;
loc_305c8:
    bp += 0x1fb0;
loc_305cc:
    cx = 0x0005;
loc_305cf:
    sub_2c26c();
    if (--cx)
        goto loc_305cf;
    bh++;
    if (bh != 0x5c)
        goto loc_3058c;
    si = 0x2825;
    bh = 0;
loc_305e0:
    bl = 0x05;
loc_305e2:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_305f1;
    push(bx);
    push(si);
    sub_307a0();
    si = pop();
    bx = pop();
    sub_307d5();
loc_305f1:
    bl--;
    if (bl != 0)
        goto loc_305e2;
    bh++;
    if (bh != 0x18)
        goto loc_305e0;
    ds = pop();
    sub_2aff1();
    sub_30663();
loc_30603:
    sub_30676();
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_30613;
    ah = 0;
    interrupt(0x16);
    goto loc_30615;
loc_30613:
    goto loc_30603;
loc_30615:
    es = pop();
}
void sub_30617()
{
    memoryASet16(ds, si, 0x0068);
    memoryASet16(ds, si + 2, 0x0098);
    dx = 0x0003;
    sub_30068();
    ax += 0x0008;
    memoryASet16(ds, si + 14, ax);
    dx = 0x0046;
    sub_30068();
    ax -= 0x0023;
    if (ax != 0)
        goto loc_3063a;
    ax = 0x000a;
loc_3063a:
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, ax);
    dx = 0xffff;
    if (ax < 0x8000)
        goto loc_3064b;
    dx = 0x0001;
loc_3064b:
    memoryASet16(ds, si + 12, dx);
    ax = memoryAGet16(ds, si + 14);
    imul(memoryAGet16(ds, si + 4));
    imul(memoryAGet16(ds, si + 4));
    cx = 0x0064;
    idiv(cx);
    memoryASet16(ds, si + 10, ax);
    memoryASet16(ds, si + 8, ax);
}
void sub_30663()
{
    si = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_3066a:
    bp = cx;
    sub_30617();
    si += 0x0010;
    cx = bp;
    if (--cx)
        goto loc_3066a;
    ax = 0xb800;
    es = ax;
    si = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_30682:
    bp = cx;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_306a6;
    cx = ax;
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306a6;
    dx = ax;
    sub_306fd();
loc_306a6:
    dx = 0;
    ax = memoryAGet16(ds, si + 12);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + ax);
    cx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, si + 14);
    imul(cx);
    imul(cx);
    cx = 0x0064;
    idiv(cx);
    memoryASet16(ds, si + 8, ax);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306df;
    dx = ax;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_306df;
    cx = ax;
    sub_306fd();
loc_306df:
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306f8;
loc_306ed:
    si += 0x0010;
    cx = bp;
    sub_2c26c();
    if (--cx)
        goto loc_30682;
    return;
loc_306f8:
    sub_30617();
    goto loc_306ed;
}
void sub_30676()
{
    ax = 0xb800;
    es = ax;
    si = 0x148d;
    cx = memoryAGet16(ds, 0x1413);
loc_30682:
    bp = cx;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_306a6;
    cx = ax;
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306a6;
    dx = ax;
    sub_306fd();
loc_306a6:
    dx = 0;
    ax = memoryAGet16(ds, si + 12);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + ax);
    cx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, si + 14);
    imul(cx);
    imul(cx);
    cx = 0x0064;
    idiv(cx);
    memoryASet16(ds, si + 8, ax);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306df;
    dx = ax;
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax -= memoryAGet16(ds, si + 6);
    if (ax > 0x013f)
        goto loc_306df;
    cx = ax;
    sub_306fd();
loc_306df:
    ax = memoryAGet16(ds, si + 8);
    ax += memoryAGet16(ds, si + 2);
    ax -= memoryAGet16(ds, si + 10);
    if (ax > 0x00c7)
        goto loc_306f8;
loc_306ed:
    si += 0x0010;
    cx = bp;
    sub_2c26c();
    if (--cx)
        goto loc_30682;
    return;
loc_306f8:
    sub_30617();
    goto loc_306ed;
}
void sub_306fd()
{
    flags.carry = dx & 1;
    dx >>= 1;
    if (flags.carry)
        goto loc_30750;
    di = 0;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax = dx;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    ax <<= 1;
    di += ax;
    ax = 0;
    flags.carry = cx & 1;
    cx >>= 1;
    ax += ax + flags.carry;
    flags.carry = cx & 1;
    cx >>= 1;
    if (!flags.carry)
        goto loc_30722;
    ax += 0x0002;
loc_30722:
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di += cx;
    ax += 0x1acf;
    dx = si;
    si = ax;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di += 0x2000;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di -= 0x1fb0;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di += 0x2000;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    si = dx;
    return;
loc_30750:
    di = 0x2000;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax = dx;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    ax <<= 1;
    di += ax;
    ax = 0;
    flags.carry = cx & 1;
    cx >>= 1;
    ax += ax + flags.carry;
    flags.carry = cx & 1;
    cx >>= 1;
    if (!flags.carry)
        goto loc_30772;
    ax += 0x0002;
loc_30772:
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di += cx;
    ax += 0x1acf;
    dx = si;
    si = ax;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di -= 0x1fb0;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di += 0x2000;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    di -= 0x1fb0;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    si = dx;
}
void sub_307a0()
{
    dx = 0;
    si = 0x289d;
loc_307a5:
    cx = 0x000f;
loc_307a8:
    sub_2c26c();
    if (--cx)
        goto loc_307a8;
    lodsw<MemAuto, DirAuto>();
    if (!ax)
        return;
    bp = ax;
    push(dx);
    dx = 0x03da;
loc_307b8:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_307b8;
loc_307bd:
    in(al, dx);
    if (al & 0x08)
        goto loc_307bd;
    dx = pop();
    ax = bp;
    sub_30856();
    ax = bp;
    tx = dx;
    dx = ax;
    ax = tx;
    if (!ax)
        goto loc_307a5;
    sub_30856();
    goto loc_307a5;
}
void sub_307d5()
{
    push(bx);
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    bh = 0x50;
    bh -= bl;
    memoryASet(ds, 0x2823, bh);
loc_307e4:
    if (dh == memoryAGet(ds, 0x2823))
        goto loc_30815;
    ax = dx;
    ah -= 0x04;
    cx = 0x000f;
loc_307f2:
    sub_2c26c();
    if (--cx)
        goto loc_307f2;
    bp = ax;
    push(dx);
    dx = 0x03da;
loc_307fd:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_307fd;
loc_30802:
    in(al, dx);
    if (al & 0x08)
        goto loc_30802;
    dx = pop();
    ax = bp;
    sub_30856();
    ax = bp;
    tx = dx;
    dx = ax;
    ax = tx;
    sub_30856();
    goto loc_307e4;
loc_30815:
    bx = pop();
    push(bx);
    bh <<= 1;
    bh <<= 1;
    bh <<= 1;
    bh += 0x08;
    memoryASet(ds, 0x2823, bh);
loc_30824:
    if (dl == memoryAGet(ds, 0x2823))
        goto loc_30854;
    ax = dx;
    al -= 0x04;
    cx = 0x000f;
loc_30831:
    sub_2c26c();
    if (--cx)
        goto loc_30831;
    bp = ax;
    push(dx);
    dx = 0x03da;
loc_3083c:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_3083c;
loc_30841:
    in(al, dx);
    if (al & 0x08)
        goto loc_30841;
    dx = pop();
    ax = bp;
    sub_30856();
    ax = bp;
    tx = dx;
    dx = ax;
    ax = tx;
    sub_30856();
    goto loc_30824;
loc_30854:
    bx = pop();
}
void sub_30856()
{
    al >>= 1;
    al >>= 1;
    bl = ah;
    ah = 0;
    di = ax;
    flags.carry = bl & 1;
    bl >>= 1;
    if (!flags.carry)
        goto loc_30868;
    di += 0x2000;
loc_30868:
    al = 0x50;
    mul(bl);
    di += ax;
    push(si);
    si = 0x28d9;
    cx = 0x0008;
loc_30875:
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
    if (di < 0x2000)
        goto loc_30885;
    di -= 0x1fb0;
    goto loc_30889;
loc_30885:
    di += 0x2000;
loc_30889:
    if (--cx)
        goto loc_30875;
    si = pop();
}
