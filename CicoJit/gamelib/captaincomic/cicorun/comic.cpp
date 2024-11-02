#include "cicoemu.h"
using namespace CicoContext;

void sub_1ed0();

int sign(int i)
{
    return i >= 0 ? 1 : -1;
}
void start()
{
    headerSize = 0x0200;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x114d;
    sp = 0x07d0;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/captaincomic/dos", "comic.exe", 97488);
    sub_1ed0();
}
void sub_1ed0();
void sub_2173();
void sub_218c();
void sub_2213();
void sub_223d();
void sub_2272();
void sub_22b3();
void sub_22c5();
void sub_2373();
void sub_23ec();
void sub_2465();
void sub_2539();
void sub_25c8();
void sub_277d();
void sub_27a0();
void sub_27da();
void sub_2814();
void sub_2862();
void sub_287a();
void sub_28ac();
void sub_28f1();
void sub_2935();
void sub_2960();
void sub_2975();
void sub_29a3();
void sub_29b8();
void sub_2a4e();
void sub_2acb();
void sub_2b33();
void sub_2b7e();
void sub_2b93();
void sub_2bac();
void sub_2bc4();
void sub_2bd9();
void sub_2bf8();
void sub_2c02();
void sub_2c52();
void sub_2d02();
void sub_2d85();
void sub_2e08();
void sub_2e22();
void sub_2f5d();
void sub_2fc2();
void sub_31e2();
void sub_31f7();
void sub_33b4();
void sub_33c2();
void sub_3410();
void sub_341e();
void sub_34b8();
void sub_39fc();
void sub_3a35();
void sub_3b27();
void sub_3b6a();
void sub_3ba6();
void sub_3bcf();
void sub_3bf4();
void sub_3c1e();
void sub_3c4d();
void sub_3c7b();
void sub_3c90();
void sub_3cf5();
void sub_3d0a();
void sub_3d3b();
void sub_3d83();
void sub_3e89();
void sub_3f80();
void sub_4119();
void sub_4135();
void sub_4159();

void timer()
{
    sub_22c5();
}

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x1ed03a2: sub_2272(); return;
        case 0x1ed03e3: sub_22b3(); return;
        case 0x1ed03f5: sub_22c5(); return;
        case 0x1ed04a3: sub_2373(); return;
        default:
            break;
    }
    assert(0);
}
void sub_1ed0() // 01ed:0000
{
    flags.direction = false;
    ax = 0x0417;
    ds = ax;
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    ax = 0x000d;
    interrupt(0x10);
    ax = 0x0f00;
    interrupt(0x10);
    if (al != 0x0d)
        goto loc_1ef7;
    ax = 0x1200;
    bx = 0x0010;
    interrupt(0x10);
    if ((char)bl >= (char)0x03)
        goto loc_1f08;
loc_1ef7: // 01ed:0027
    ax = 0x0002;
    interrupt(0x10);
    ah = 0x09;
    dx = 0x0;
    interrupt(0x21);
    ah = 0x4c;
    interrupt(0x21);
loc_1f08: // 01ed:0038
    sub_23ec();
    bx = 0x179;
    sub_223d();
    dx = 0x21f;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1f20;
    goto loc_213d;
loc_1f20: // 01ed:0050
    bp = ax;
    push(ds);
    ax = 0xa000;
    ds = ax;
    es = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    sub_2173();
    cx = 0x8000;
    sub_29a3();
    sub_218c();
    ax = 0x000a;
    sub_2213();
    dx = 0x235;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1fae;
    goto loc_213d;
loc_1fae: // 01ed:00de
    bp = ax;
    push(ds);
    ax = 0xa000;
    ds = ax;
    es = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = 0xa000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = 0xa000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = 0xa000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = 0xa000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    dx = 0x22a;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_201f;
    goto loc_213d;
loc_201f: // 01ed:014f
    bp = ax;
    push(ds);
    ax = 0xa000;
    ds = ax;
    es = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = 0x0000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    si = 0;
    di = 0x2000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = 0x0000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    si = 0;
    di = 0x2000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = 0x0000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    si = 0;
    di = 0x2000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = 0x0000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    si = 0;
    di = 0x2000;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    cx = 0xa000;
    sub_29a3();
    sub_218c();
    dx = 0x240;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_20b8;
    goto loc_213d;
loc_20b8: // 01ed:01e8
    bp = ax;
    push(ds);
    ax = 0xa000;
    ds = ax;
    es = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = 0x8000;
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    interrupt(0x16);
    cx = 0x8000;
    sub_29a3();
    ax = 0;
    interrupt(0x16);
    cx = 0x2000;
    sub_29a3();
    goto loc_2140;
loc_213d: // 01ed:026d
    goto loc_2226;
loc_2140: // 01ed:0270
    ax = 0x0002;
    cx = 0x0005;
loc_2147: // 01ed:0277
    ax = 0x0001;
    sub_2213();
    push(cx);
    sub_3b27();
    cx = pop();
    if (--cx)
        goto loc_2147;
    ax = 0x0003;
    ax = 0x0000;
    ax = 0x0003;
    sub_2213();
    sub_3b6a();
    bx = 0x1c5;
    ax = 0x0001;
    cx = 0x0001;
    goto loc_24b2;
    //   gap of 179 bytes
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01) // jump
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
    //   gap of 217 bytes
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
}
void sub_2173() // 01ed:02a3
{
    ax = 0x1000;
    bx = 0x0002;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x000a;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x000c;
    interrupt(0x10);
}
void sub_218c() // 01ed:02bc
{
    ax = 0x1000;
    bx = 0x1802;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x180a;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x180c;
    interrupt(0x10);
    ax = 0x0001;
    sub_2213();
    ax = 0x1000;
    bx = 0x0702;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x070a;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x070c;
    interrupt(0x10);
    ax = 0x0001;
    sub_2213();
    ax = 0x1000;
    bx = 0x0702;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x1f0a;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x1f0c;
    interrupt(0x10);
    ax = 0x0001;
    sub_2213();
    ax = 0x1000;
    bx = 0x0202;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x1a0a;
    interrupt(0x10);
    ax = 0x1000;
    bx = 0x1f0c;
    interrupt(0x10);
    ax = 0x0001;
    sub_2213();
    ax = 0x1000;
    bx = 0x1c0c;
    interrupt(0x10);
    ax = 0x0001;
    sub_2213();
}
void sub_2213() // 01ed:0343
{
loc_2213: // 01ed:0343
    sync(); timer();
    if (memoryAGet(cs, 0x03ea) != 0x01)
        goto loc_2213;
    memoryASet(cs, 0x03ea, 0x00);
    tx = ax;
    ax--;
    if (tx != 1)
        goto loc_2213;
}
void sub_223d() // 01ed:036d
{
loc_223d: // 01ed:036d
    al = memoryAGet(ds, bx);
    bx++;
    al ^= 0x25;
    if (al == 0x1a)
        return;
    push(bx);
    bx = 0x0007;
    ah = 0x0e;
    interrupt(0x10);
    bx = pop();
    goto loc_223d;
}
void sub_2272() // 01ed:03a2
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    in(al, 0x60);
    push(ax);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(cs);
    tx = cs;
    cs = memoryAGet16(cs, 0x0382 + 2);
    callIndirect(memoryAGet16(tx, 0x0382 + 2), memoryAGet16(tx, 0x0382));
    assert(cs == 0x01ed);
    ax = pop();
    dx = 0x0001;
    if (!(al & 0x80))
        goto loc_228c;
    al &= 0x7f;
    dx = 0x0000;
loc_228c: // 01ed:03bc
    if (al == 0x01)
        goto loc_22a5;
    tl = al;
    al -= 0x38;
    if (tl < 0x38)
        goto loc_22aa;
    if (al >= 0x1b)
        goto loc_22aa;
    bx = 0x387;
    ah = 0;
    bx += ax;
    memoryASet(cs, bx, dl);
    goto loc_22aa;
loc_22a5: // 01ed:03d5
    memoryASet(cs, 0x0386, dl);
loc_22aa: // 01ed:03da
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    stop(); // iret 
}
void sub_22b3() // 01ed:03e3
{
    goto loc_22b3;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 118 bytes
loc_22b3: // 01ed:03e3
    goto loc_2226;
}
void sub_22c5() // 01ed:03f5
{
    push(ax);
    al = memoryAGet(cs, 0x03eb);
    al++;
    if ((char)al < (char)0x02)
        goto loc_22f0;
    memoryASet(cs, 0x03ea, 0x01);
    if (memoryAGet(cs, 0x038a) != 0x01)
        goto loc_22e2;
    ax = 0x0000;
loc_22e2: // 01ed:0412
    if (memoryAGet(cs, 0x038b) != 0x01)
        goto loc_22ee;
    ax = 0x0002;
loc_22ee: // 01ed:041e
    al = 0;
loc_22f0: // 01ed:0420
    memoryASet(cs, 0x03eb, al);
    push(es);
    push(bx);
    push(dx);
    ax = memoryAGet16(cs, 0x03f3);
    es = ax;
    if (memoryAGet(cs, 0x03ec) != 0x01)
        goto loc_2360;
    tx = memoryAGet16(cs, 0x03f1);
    memoryASet16(cs, 0x03f1, memoryAGet16(cs, 0x03f1) - 1);
    if ((short)tx > 1)
        goto loc_2366;
    bx = memoryAGet16(cs, 0x03ef);
    memoryASet16(cs, 0x03ef, memoryAGet16(cs, 0x03ef) + 0x0002);
    ax = memoryAGet16(es, bx);
    if (!ax)
        goto loc_2354;
    bx = ax;
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    al = 0xb6;
    out(0x43, al);
    al = bl;
    out(0x42, al);
    al = bh;
    out(0x42, al);
    bx = memoryAGet16(cs, 0x03ef);
    memoryASet16(cs, 0x03ef, memoryAGet16(cs, 0x03ef) + 0x0002);
    ax = memoryAGet16(es, bx);
    memoryASet16(cs, 0x03f1, ax);
    if (memoryAGet(cs, 0x03ed) != 0x01)
        goto loc_2366;
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
    goto loc_2366;
loc_2354: // 01ed:0484
    memoryASet(cs, 0x03ec, 0x00);
    memoryASet(cs, 0x03ee, 0x00);
loc_2360: // 01ed:0490
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
loc_2366: // 01ed:0496
    dx = pop();
    bx = pop();
    es = pop();
    ax = pop();
//    stop(); // ljmp cs:[0x3e6]
}
void sub_2373() // 01ed:04a3
{
    if (!al)
        goto loc_23b9;
    if (al == 0x01)
        goto loc_2389;
    if (al == 0x02)
        goto loc_23c3;
    if (al == 0x03)
        goto loc_23cd;
    if (al == 0x04)
        goto loc_23dd;
    goto loc_23eb;
loc_2389: // 01ed:04b9
    if (memoryAGet(cs, 0x03ec) == 0xff)
        goto loc_23eb;
    if ((char)memoryAGet(cs, 0x03ee) > (char)cl)
        goto loc_23eb;
    memoryASet(cs, 0x03ee, cl);
    flags.interrupts = false;
    memoryASet(cs, 0x03ec, 0x01);
    memoryASet16(cs, 0x03ef, bx);
    ax = ds;
    memoryASet16(cs, 0x03f3, ax);
    memoryASet16(cs, 0x03f1, 0x0001);
    flags.interrupts = true;
    goto loc_23eb;
loc_23b9: // 01ed:04e9
    flags.interrupts = false;
    memoryASet(cs, 0x03ed, 0x01);
    flags.interrupts = true;
    goto loc_23e5;
loc_23c3: // 01ed:04f3
    flags.interrupts = false;
    memoryASet(cs, 0x03ed, 0x00);
    flags.interrupts = true;
    goto loc_23e5;
loc_23cd: // 01ed:04fd
    flags.interrupts = false;
    memoryASet(cs, 0x03ec, 0x00);
    memoryASet(cs, 0x03ee, 0x00);
    flags.interrupts = true;
    goto loc_23e5;
loc_23dd: // 01ed:050d
    al = memoryAGet(cs, 0x03ec);
    ah = 0;
    goto loc_23eb;
loc_23e5: // 01ed:0515
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
loc_23eb: // 01ed:051b
//    stop(); // iret
    return;
}
void sub_23ec() // 01ed:051c
{
    push(ds);
    ax = 0;
    ds = ax;
    flags.interrupts = false;
    bx = 0x382;
    ax = memoryAGet16(ds, 0x0026);
    memoryASet16(cs, bx + 2, ax);
    ax = memoryAGet16(ds, 0x0024);
    memoryASet16(cs, bx, ax);
    ax = 0x3a2;
    memoryASet16(ds, 0x0024, ax);
    memoryASet16(ds, 0x0026, cs);
    bx = 0x3e6;
    ax = memoryAGet16(ds, 0x0022);
    memoryASet16(cs, bx + 2, ax);
    ax = memoryAGet16(ds, 0x0020);
    memoryASet16(cs, bx, ax);
    ax = 0x3f5;
    memoryASet16(ds, 0x0020, ax);
    memoryASet16(ds, 0x0022, cs);
    bx = 0x3df;
    ax = memoryAGet16(ds, 0x008e);
    memoryASet16(cs, bx + 2, ax);
    ax = memoryAGet16(ds, 0x008c);
    memoryASet16(cs, bx, ax);
    ax = 0x3e3;
    memoryASet16(ds, 0x008c, ax);
    memoryASet16(ds, 0x008e, cs);
    bx = 0x49f;
    ax = memoryAGet16(ds, 0x000e);
    memoryASet16(cs, bx + 2, ax);
    ax = memoryAGet16(ds, 0x000c);
    memoryASet16(cs, bx, ax);
    ax = 0x4a3;
    memoryASet16(ds, 0x000c, ax);
    memoryASet16(ds, 0x000e, cs);
    flags.interrupts = true;
    ds = pop();
}
void sub_2465() // 01ed:0595
{
    push(ds);
    ax = 0;
    ds = ax;
    flags.interrupts = false;
    bx = 0x382;
    ax = memoryAGet16(cs, bx + 2);
    memoryASet16(ds, 0x0026, ax);
    ax = memoryAGet16(cs, bx);
    memoryASet16(ds, 0x0024, ax);
    bx = 0x3e6;
    ax = memoryAGet16(cs, bx + 2);
    memoryASet16(ds, 0x0022, ax);
    ax = memoryAGet16(cs, bx);
    memoryASet16(ds, 0x0020, ax);
    bx = 0x3df;
    ax = memoryAGet16(cs, bx + 2);
    memoryASet16(ds, 0x008e, ax);
    ax = memoryAGet16(cs, bx);
    memoryASet16(ds, 0x008c, ax);
    bx = 0x49f;
    ax = memoryAGet16(cs, bx + 2);
    memoryASet16(ds, 0x000e, ax);
    ax = memoryAGet16(cs, bx);
    memoryASet16(ds, 0x000c, ax);
    flags.interrupts = true;
    ds = pop();
}
void sub_2539() // 01ed:0669
{
    goto loc_2539;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 698 bytes
loc_24f7: // 01ed:0627
    goto loc_2226;
    //   gap of 63 bytes
loc_2539: // 01ed:0669
    push(cx);
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2544;
    cx = pop();
    goto loc_24f7;
loc_2544: // 01ed:0674
    bx = ax;
    dx = pop();
    cx = 0x0504;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
}
void sub_25c8() // 01ed:06f8
{
    goto loc_25c8;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 698 bytes
loc_24f7: // 01ed:0627
    goto loc_2226;
    //   gap of 206 bytes
loc_25c8: // 01ed:06f8
    push(dx);
    al = memoryAGet(ds, si);
    ah = 0;
    if (memoryAGet(ds, si + 1) == 0x01)
        goto loc_25d5;
    ax <<= 1;
loc_25d5: // 01ed:0705
    bx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax += bx;
    push(ax);
    dx = si + 0x3;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_25ff;
    goto loc_24f7;
loc_25ff: // 01ed:072f
    bx = ax;
    dx = di;
    cx = pop();
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    bx = pop();
    push(bx);
    dx = di;
    cl = memoryAGet(ds, si);
loc_2614: // 01ed:0744
    memoryASet16(ds, bx, dx);
    bx += 0x0002;
    dx += 0x00a0;
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_2614;
    if (memoryAGet(ds, si + 2) == 0x00)
        goto loc_2631;
    dx -= 0x0140;
    memoryASet16(ds, bx, dx);
    dx += 0x0140;
loc_2631: // 01ed:0761
    if (memoryAGet(ds, si + 1) == 0x02)
        goto loc_2639;
    dx = di;
loc_2639: // 01ed:0769
    bx = pop();
    push(bx);
    bx += 0x000a;
    cl = memoryAGet(ds, si);
loc_2640: // 01ed:0770
    memoryASet16(ds, bx, dx);
    bx += 0x0002;
    dx += 0x00a0;
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_2640;
    if (memoryAGet(ds, si + 2) == 0x00)
        goto loc_2659;
    dx -= 0x0140;
    memoryASet16(ds, bx, dx);
loc_2659: // 01ed:0789
    bx = pop();
}
void sub_277d() // 01ed:08ad
{
    push(ax);
    bl = ah;
    bh = 0;
    ah = 0;
    bx >>= 1;
    ax >>= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    bx = memoryAGet16(ds, 0x4264);
    bx += ax;
    ax = pop();
}
void sub_27a0() // 01ed:08d0
{
    cx = ax;
    bl = ah;
    bh = 0;
    ah = 0;
    bx >>= 1;
    ax >>= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    bx = memoryAGet16(ds, 0x4264);
    bx += ax;
    ax = cx;
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_27d8;
    if (!(ah & 0x01))
        goto loc_27d6;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_27d8;
loc_27d6: // 01ed:0906
    flags.carry = false;
    return;
loc_27d8: // 01ed:0908
    flags.carry = true;
}
void sub_27da() // 01ed:090a
{
    cx = ax;
    bl = ah;
    bh = 0;
    ah = 0;
    bx >>= 1;
    ax >>= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    bx = memoryAGet16(ds, 0x4264);
    bx += ax;
    ax = cx;
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_2812;
    if (!(al & 0x01))
        goto loc_2810;
    if ((char)memoryAGet(ds, bx + 128) > (char)cl)
        goto loc_2812;
loc_2810: // 01ed:0940
    flags.carry = false;
    return;
loc_2812: // 01ed:0942
    flags.carry = true;
}
void sub_2814() // 01ed:0944
{
    ax = 0xa000;
    es = ax;
    cx = 0x0a80;
    di = 0x4000;
    si = memoryAGet16(ds, 0x4264);
loc_2823: // 01ed:0953
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    push(si);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = 0x264;
    si += ax;
    ah = 0x01;
    sub_2862();
    ah = 0x02;
    sub_2862();
    ah = 0x04;
    sub_2862();
    ah = 0x08;
    sub_2862();
    di += 0x0002;
    si = pop();
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_2823;
    di += 0x0f00;
    cl = 0x80;
    tl = ch;
    ch--;
    if (tl != 1)
        goto loc_2823;
}
void sub_2862() // 01ed:0992
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    bx = 0x0010;
    push(di);
loc_2870: // 01ed:09a0
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x00fe;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_2870;
    di = pop();
}
void sub_287a() // 01ed:09aa
{
    push(ds);
    si = 0x4000;
    si += memoryAGet16(ds, 0x0041);
    di = memoryAGet16(ds, 0xca30);
    di += 0x0141;
    ax = 0xa000;
    es = ax;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2935();
    ah = 0x02;
    bx++;
    sub_2935();
    ah = 0x04;
    bx++;
    sub_2935();
    ah = 0x08;
    bx++;
    sub_2935();
    ds = pop();
}
void sub_28ac() // 01ed:09dc
{
    si = 0x6be0;
    al = memoryAGet(ds, 0xca39);
    ah = memoryAGet(ds, 0xca3a);
    al += ah;
    ah = 0;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    si += ax;
    cx = 0x0020;
    bp = si;
    bp += 0x0100;
    ax = memoryAGet16(ds, 0x003f);
    dx = memoryAGet16(ds, 0x0041);
    ah -= dl;
    sub_28f1();
}
void sub_28f1() // 01ed:0a21
{
    di = memoryAGet16(ds, 0xca30);
    di += 0x0141;
    dl = ah;
    dh = 0;
    ah = 0;
    bh = al;
    bl = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax += dx;
    di += ax;
    ah = 0x01;
    bx = 0;
    sub_2975();
    ah = 0x02;
    bx = 0x0001;
    sub_2975();
    ah = 0x04;
    bx = 0x0002;
    sub_2975();
    ah = 0x08;
    bx = 0x0003;
    sub_2975();
}
void sub_2935() // 01ed:0a65
{
    push(si);
    push(di);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = bl;
    out(dx, al);
    dx = 0x00a0;
loc_294e: // 01ed:0a7e
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    si += 0x00e8;
    di += 0x0010;
    tx = dx;
    dx--;
    if (tx != 1)
        goto loc_294e;
    di = pop();
    si = pop();
}
void sub_2960() // 01ed:0a90
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = bl;
    out(dx, al);
}
void sub_2975() // 01ed:0aa5
{
    push(di);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = bl;
    out(dx, al);
    bx = bp;
    dx = cx;
loc_298e: // 01ed:0abe
    ax = memoryAGet16(ds, bx);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    lodsw<MemAuto, DirAuto>();
    memoryASet16(es, di, memoryAGet16(es, di) | ax);
    di += 0x0028;
    bx += 0x0002;
    if (--cx)
        goto loc_298e;
    cx = dx;
    di = pop();
}
void sub_29a3() // 01ed:0ad3
{
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx++;
    al = ch;
    out(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out(dx, al);
    dx++;
    al = cl;
    out(dx, al);
}
void sub_29b8() // 01ed:0ae8
{
    push(bx);
    push(cx);
    si = 0x6be0;
    al = memoryAGet(ds, 0xca39);
    ah = memoryAGet(ds, 0xca3a);
    al += ah;
    ah = 0;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    si += ax;
    bp = si;
    bp += 0x0100;
    ax = memoryAGet16(ds, 0x003f);
    dx = memoryAGet16(ds, 0x0041);
    ah -= dl;
    cx = pop();
    di = memoryAGet16(ds, 0xca30);
    di += 0x0141;
    dl = ah;
    dh = 0;
    ah = 0;
    bh = al;
    bl = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax += dx;
    di += ax;
    ah = 0x01;
    bx = 0;
    sub_2975();
    bx = pop();
    si += bx;
    si += bx;
    push(bx);
    ah = 0x02;
    bx = 0x0001;
    sub_2975();
    bx = pop();
    si += bx;
    si += bx;
    push(bx);
    ah = 0x04;
    bx = 0x0002;
    sub_2975();
    bx = pop();
    si += bx;
    si += bx;
    ah = 0x08;
    bx = 0x0003;
    sub_2975();
}
void sub_2a4e() // 01ed:0b7e
{
    ax = memoryAGet16(ds, 0x003f);
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    ah -= 0x01;
    dl = ah;
    dh = 0;
    ah = 0;
    bh = al;
    bl = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax += dx;
    di = 0x0141;
    di += ax;
    memoryASet16(ds, 0xc8f0, di);
    ax = 0x0003;
    sub_2213();
    bx = 0xffffc909;
    ax = 0x0001;
    cx = 0x0004;
    sub_287a();
    sub_2bf8();
    sub_287a();
    sub_2bc4();
    sub_28ac();
    sub_2b33();
    sub_2bf8();
    sub_287a();
    sub_2bc4();
    sub_28ac();
    sub_2bf8();
    sub_287a();
    sub_2b33();
    sub_2bc4();
    sub_2b33();
    sub_28ac();
    sub_2bf8();
    sub_287a();
    sub_28ac();
    sub_2bf8();
}
void sub_2acb() // 01ed:0bfb
{
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    dl = ah;
    dh = 0;
    ah = 0;
    bh = al;
    bl = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax += dx;
    di = 0x0141;
    di += ax;
    memoryASet16(ds, 0xc8f0, di);
    bx = 0xffffc909;
    ax = 0x0001;
    cx = 0x0004;
    sub_287a();
    sub_2bc4();
    sub_2b33();
    sub_28ac();
    sub_2bf8();
    sub_287a();
    sub_2bc4();
    sub_28ac();
    sub_2bf8();
    sub_287a();
    sub_2b33();
    sub_2bc4();
    sub_28ac();
    sub_2b33();
    sub_2bf8();
    sub_287a();
    sub_2bf8();
}
void sub_2b33() // 01ed:0c63
{
    bx = 0x6b30;
    al = memoryAGet(ds, bx);
    sub_2b7e();
    si++;
    di = memoryAGet16(ds, 0xc8f0);
    push(bx);
    sub_2b93();
    bx = pop();
    al = memoryAGet(ds, bx + 1);
    sub_2b7e();
    di = memoryAGet16(ds, 0xc8f0);
    di += 0x0003;
    push(bx);
    sub_2b93();
    bx = pop();
    al = memoryAGet(ds, bx + 2);
    sub_2b7e();
    si++;
    di = memoryAGet16(ds, 0xc8f0);
    di += 0x0280;
    push(bx);
    sub_2b93();
    bx = pop();
    al = memoryAGet(ds, bx + 3);
    sub_2b7e();
    di = memoryAGet16(ds, 0xc8f0);
    di += 0x0283;
    sub_2b93();
}
void sub_2b7e() // 01ed:0cae
{
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = 0x264;
    si += ax;
}
void sub_2b93() // 01ed:0cc3
{
    di += memoryAGet16(ds, 0xca30);
    ah = 0x01;
    sub_2bac();
    ah = 0x02;
    sub_2bac();
    ah = 0x04;
    sub_2bac();
    ah = 0x08;
    sub_2bac();
}
void sub_2bac() // 01ed:0cdc
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    bx = 0x0010;
    push(di);
loc_2bba: // 01ed:0cea
    movsb<MemAuto, MemAuto, DirAuto>();
    si++;
    di += 0x0027;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_2bba;
    di = pop();
}
void sub_2bc4() // 01ed:0cf4
{
    ah = 0x01;
    sub_2bd9();
    ah = 0x02;
    sub_2bd9();
    ah = 0x04;
    sub_2bd9();
    ah = 0x08;
    sub_2bd9();
}
void sub_2bd9() // 01ed:0d09
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    di = memoryAGet16(ds, 0xc8f0);
    di += memoryAGet16(ds, 0xca30);
    cx = 0x0020;
    ax = 0;
loc_2bf0: // 01ed:0d20
    stosw<MemAuto, DirAuto>();
    stosw<MemAuto, DirAuto>();
    di += 0x0024;
    if (--cx)
        goto loc_2bf0;
}
void sub_2bf8() // 01ed:0d28
{
    ax = 0x0001;
    sub_2213();
    sub_31e2();
}
void sub_2c02() // 01ed:0d32
{
    bx = 0xffffc931;
    ax = 0x0001;
    cx = 0x0004;
    cx = 0x0008;
    si = 0x7cc0;
loc_2c14: // 01ed:0d44
    push(cx);
    push(si);
    push(cx);
    sub_287a();
    cx = pop();
    if ((short)cx <= (short)0x0004)
        goto loc_2c23;
    sub_28ac();
loc_2c23: // 01ed:0d53
    sub_34b8();
    si = pop();
    push(si);
    bp = si;
    bp += 0x0100;
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, 0x003f);
    ah -= dl;
    cx = 0x0020;
    sub_28f1();
    sub_31f7();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
    si = pop();
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_2c14;
}
void sub_2c52() // 01ed:0d82
{
    ax = memoryAGet16(ds, 0x003f);
    bx = memoryAGet16(ds, 0x0041);
    dx = bx;
    memoryASet(ds, 0xc8f7, 0x00);
    bl = -bl;
    bl += ah;
    if (memoryAGet(ds, 0xca39) == 0x00)
        goto loc_2c88;
    memoryASet16(ds, 0xc8f8, 0xffff);
    tl = bl;
    bl -= 0x06;
    if (tl < 0x06)
        goto loc_2ce0;
    ah -= 0x06;
    flags.carry = bl < 0x0a;
    bl -= 0x0a;
    if (!flags.carry)
        goto loc_2cae;
    bl = -bl;
    flags.carry = dl < bl;
    dl -= bl;
    if (!flags.carry)
        goto loc_2caa;
    bl += dl;
    goto loc_2caa;
loc_2c88: // 01ed:0db8
    memoryASet16(ds, 0xc8f8, 0x0001);
    if (bl >= 0x11)
        goto loc_2ce0;
    ah += 0x06;
    bl += 0x06;
    tl = bl;
    bl -= 0x0c;
    if ((char)tl - (char)0x0c <= 0)
        goto loc_2cae;
    dl += bl;
    if ((char)dl <= (char)0xe8)
        goto loc_2caa;
    dl -= 0xe8;
    bl -= dl;
loc_2caa: // 01ed:0dda
    memoryASet(ds, 0xc8f7, bl);
loc_2cae: // 01ed:0dde
    cl = memoryAGet(ds, 0x0260);
    al = 0x12;
    ah &= 0xfe;
    sub_277d();
loc_2cba: // 01ed:0dea
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_2ccd;
    bx -= 0x0080;
    al -= 0x02;
    if (al != 0)
        goto loc_2cba;
    goto loc_2ce0;
loc_2cc9: // 01ed:0df9
    if ((char)memoryAGet(ds, bx) <= (char)cl)
        goto loc_2cdb;
loc_2ccd: // 01ed:0dfd
    dx = 0x0002;
loc_2cd0: // 01ed:0e00
    bx -= 0x0080;
    flags.carry = al < 0x02;
    al -= 0x02;
    if (!flags.carry)
        goto loc_2cc9;
    goto loc_2ce0;
loc_2cdb: // 01ed:0e0b
    tx = dx;
    dx--;
    if (tx != 1)
        goto loc_2cd0;
    goto loc_2ce3;
loc_2ce0: // 01ed:0e10
    ax = memoryAGet16(ds, 0x003f);
loc_2ce3: // 01ed:0e13
    memoryASet(ds, 0xc8f2, 0x00);
    memoryASet16(ds, 0xc8f3, ax);
    ax = memoryAGet16(ds, 0x003f);
    memoryASet16(ds, 0xc8f5, ax);
    memoryASet(ds, 0xca34, 0x01);
    bx = 0xffffc959;
    ax = 0x0001;
    cx = 0x0002;
}
void sub_2d02() // 01ed:0e32
{
    if (memoryAGet(ds, 0xc8f7) == 0x00)
        goto loc_2d15;
    bx = memoryAGet16(ds, 0xc8f8);
    memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + bx);
    memoryASet(ds, 0xc8f7, memoryAGet(ds, 0xc8f7) - 1);
loc_2d15: // 01ed:0e45
    sub_287a();
    if (memoryAGet(ds, 0xc8f2) != 0x03)
        goto loc_2d25;
    ax = memoryAGet16(ds, 0xc8f3);
    memoryASet16(ds, 0x003f, ax);
loc_2d25: // 01ed:0e55
    sub_28ac();
    al = memoryAGet(ds, 0xc8f2);
    if (al == 0x05)
        goto loc_2d4e;
    ah = 0;
    ax <<= 1;
    si = 0xffff999a;
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0100;
    ax = memoryAGet16(ds, 0xc8f5);
    ah -= memoryAGet(ds, 0x0041);
    cx = 0x0020;
    sub_28f1();
loc_2d4e: // 01ed:0e7e
    al = memoryAGet(ds, 0xc8f2);
    tl = al;
    al -= 0x01;
    if (tl < 0x01)
        goto loc_2d74;
    ah = 0;
    ax <<= 1;
    si = 0xffff999a;
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0100;
    ax = memoryAGet16(ds, 0xc8f3);
    ah -= memoryAGet(ds, 0x0041);
    cx = 0x0020;
    sub_28f1();
loc_2d74: // 01ed:0ea4
    memoryASet(ds, 0xc8f2, memoryAGet(ds, 0xc8f2) + 1);
    if (memoryAGet(ds, 0xc8f2) != 0x06)
        return;
    memoryASet(ds, 0xca34, 0x00);
}
void sub_2d85() // 01ed:0eb5
{
    goto loc_2d85;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2888 bytes
loc_2d85: // 01ed:0eb5
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffb0e4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    if (al != 0x71)
        goto loc_2dbf;
loc_2dbc: // 01ed:0eec
    goto loc_2226;
loc_2dbf: // 01ed:0eef
    if (al == 0x51)
        goto loc_2dbc;
}
void sub_2e08() // 01ed:0f38
{
    ax = 0xa000;
    es = ax;
    ah = 0x01;
    sub_2e22();
    ah = 0x02;
    sub_2e22();
    ah = 0x04;
    sub_2e22();
    ah = 0x08;
    sub_2e22();
}
void sub_2e22() // 01ed:0f52
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    push(di);
    dx = di;
    bx = memoryAGet16(ds, 0xc8fc);
loc_2e33: // 01ed:0f63
    cx = memoryAGet16(ds, 0xc8fa);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    dx += 0x0028;
    di = dx;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_2e33;
    di = pop();
}
void sub_2f5d() // 01ed:108d
{
    bx = 0xffffc985;
    ax = 0x0001;
    cx = 0x0004;
    sub_287a();
    sub_28ac();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
    cx = 0x000c;
    si = 0xffff8a80;
loc_2f7e: // 01ed:10ae
    push(cx);
    push(si);
    push(cx);
    sub_287a();
    cx = pop();
    if ((short)cx <= (short)0x0006)
        goto loc_2f8d;
    sub_28ac();
loc_2f8d: // 01ed:10bd
    si = pop();
    push(si);
    bp = si;
    bp += 0x0100;
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, 0x003f);
    ah -= dl;
    cx = 0x0020;
    sub_28f1();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
    si = pop();
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_2f7e;
    sub_287a();
    sub_31e2();
    ax = 0x0006;
    sub_2213();
}
void sub_2fc2() // 01ed:10f2
{
    cx = 0x000f;
loc_2fc5: // 01ed:10f5
    push(cx);
    sub_287a();
    sub_31f7();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2fc5;
    ax = 0x0004;
    sub_2373(); // GABO INT!
    if (!ax)
        goto loc_2fe5;
    cx = 0x0001;
    goto loc_2fc5;
loc_2fe5: // 01ed:1115
    bx = 0xffffc985;
    ax = 0x0001;
    cx = 0x0004;
    cx = 0x000c;
    si = 0xffff8a80;
loc_2ff7: // 01ed:1127
    push(cx);
    push(si);
    push(cx);
    sub_287a();
    cx = pop();
    if ((short)cx > (short)0x0006)
        goto loc_3006;
    sub_28ac();
loc_3006: // 01ed:1136
    si = pop();
    push(si);
    bp = si;
    bp += 0x0100;
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, 0x003f);
    ah -= dl;
    cx = 0x0020;
    sub_28f1();
    sub_31f7();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
    si = pop();
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_2ff7;
    sub_287a();
    sub_28ac();
    sub_31f7();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
}
void sub_31e2() // 01ed:1312
{
    cx = memoryAGet16(ds, 0xca30);
    sub_29a3();
    cx -= 0x2000;
    if (cx == 0)
        goto loc_31f2;
    cx = 0x2000;
loc_31f2: // 01ed:1322
    memoryASet16(ds, 0xca30, cx);
}
void sub_31f7() // 01ed:1327
{
    di = memoryAGet16(ds, 0x5172);
    if (memoryAGet(ds, di) == 0xff)
        return;
    bx = 0x51;
    al = memoryAGet(ds, 0x003e);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al += memoryAGet(ds, 0x003d);
    ah = 0;
    bx += ax;
    if (memoryAGet(ds, bx) == 0x01)
        return;
    ax = memoryAGet16(ds, di + 1);
    dx = memoryAGet16(ds, 0x0041);
    ah -= dl;
    if ((char)ah < 0)
        return;
    if ((char)ah > (char)0x16)
        return;
    bl = memoryAGet(ds, di);
    sub_3e89();
}
void sub_33b4() // 01ed:14e4
{
    goto loc_33b4;
loc_2226: // 01ed:x0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01)
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
loc_33b4: // 01ed:14e4
    if (memoryAGet(ds, 0xca39) == 0x05)
        goto loc_33c2;
    memoryASet(ds, 0xca39, 0x05);
    goto loc_340f;
loc_33c2: // 01ed:14f2
    ax = si;
    if (ah)
        goto loc_33da;
    di = memoryAGet16(ds, 0x5172);
    if (memoryAGet(ds, di + 3) == 0xff)
        goto loc_340a;
    ah = 0xfe;
    bl = memoryAGet(ds, di + 3);
    goto loc_346e;
loc_33da: // 01ed:150a
    ah--;
    al += 0x03;
    sub_277d();
    al -= 0x03;
    ch = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)ch)
        goto loc_340a;
    si = ax;
    ch = memoryAGet(ds, 0xca32);
    memoryASet(ds, 0xca3a, ch);
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    if (!bx)
        goto loc_340f;
    if (ah >= 0x0a)
        goto loc_340f;
    memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) - 1);
    goto loc_340f;
loc_340a: // 01ed:153a
    memoryASet(ds, 0xca35, 0x00);
loc_340f: // 01ed:153f
    return;
    //   gap of 94 bytes
loc_346e: // 01ed:159e
    memoryASet16(ds, 0x6bd3, ax);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0x003b, 0xff);
    memoryASet(ds, 0x003e, bl);
    ax = 0x0001;
    bx = 0xffffca3e;
    cx = 0x0004;
    goto loc_265b;
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
}
void sub_33c2() // 01ed:14f2
{
    goto loc_33c2;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01)
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
    //   gap of 14 bytes
loc_33c2: // 01ed:14f2
    ax = si;
    if (ah)
        goto loc_33da;
    di = memoryAGet16(ds, 0x5172);
    if (memoryAGet(ds, di + 3) == 0xff)
        goto loc_340a;
    ah = 0xfe;
    bl = memoryAGet(ds, di + 3);
    goto loc_346e;
loc_33da: // 01ed:150a
    ah--;
    al += 0x03;
    sub_277d();
    al -= 0x03;
    ch = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)ch)
        goto loc_340a;
    si = ax;
    ch = memoryAGet(ds, 0xca32);
    memoryASet(ds, 0xca3a, ch);
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    if (!bx)
        goto loc_340f;
    if (ah >= 0x0a)
        goto loc_340f;
    memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) - 1);
    goto loc_340f;
loc_340a: // 01ed:153a
    memoryASet(ds, 0xca35, 0x00);
loc_340f: // 01ed:153f
    return;
    //   gap of 94 bytes
loc_346e: // 01ed:159e
    memoryASet16(ds, 0x6bd3, ax);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0x003b, 0xff);
    memoryASet(ds, 0x003e, bl);
    ax = 0x0001;
    bx = 0xffffca3e;
    cx = 0x0004;
    goto loc_265b;
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
}
void sub_3410() // 01ed:1540
{
    goto loc_3410;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01)
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
    //   gap of 86 bytes
loc_340a: // 01ed:153a
    memoryASet(ds, 0xca35, 0x00);
loc_340f: // 01ed:153f
    return;
loc_3410: // 01ed:1540
    if (memoryAGet(ds, 0xca39) == 0x00)
        goto loc_341e;
    memoryASet(ds, 0xca39, 0x00);
    goto loc_340f;
loc_341e: // 01ed:154e
    ax = si;
    if (ah != 0xfe)
    {
        flags.zero = false;
        goto loc_3437;
    }
    di = memoryAGet16(ds, 0x5172);
    if (memoryAGet(ds, di + 4) == 0xff)
        goto loc_340a;
    ah = 0;
    bl = memoryAGet(ds, di + 4);
    goto loc_346e;
loc_3437: // 01ed:1567
    if (flags.zero)
        goto loc_340a;
    ah += 0x02;
    al += 0x03;
    sub_277d();
    al -= 0x03;
    ah--;
    ch = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)ch)
        goto loc_340a;
    si = ax;
    ch = memoryAGet(ds, 0xca32);
    memoryASet(ds, 0xca3a, ch);
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    if ((short)bx >= (short)0x00e8)
        goto loc_340f;
    if ((char)ah <= (char)0x0c)
        goto loc_340f;
    memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + 1);
    goto loc_340f;
loc_346e: // 01ed:159e
    memoryASet16(ds, 0x6bd3, ax);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0x003b, 0xff);
    memoryASet(ds, 0x003e, bl);
    ax = 0x0001;
    bx = 0xffffca3e;
    cx = 0x0004;
    goto loc_265b;
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
}
void sub_341e() // 01ed:154e
{
    goto loc_341e;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01)
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
    //   gap of 86 bytes
loc_340a: // 01ed:153a
    memoryASet(ds, 0xca35, 0x00);
loc_340f: // 01ed:153f
    return;
    //   gap of 14 bytes
loc_341e: // 01ed:154e
    ax = si;
    if (ah != 0xfe)
    {
        flags.zero = false;
        goto loc_3437;
    }
    di = memoryAGet16(ds, 0x5172);
    if (memoryAGet(ds, di + 4) == 0xff)
        goto loc_340a;
    ah = 0;
    bl = memoryAGet(ds, di + 4);
    goto loc_346e;
loc_3437: // 01ed:1567
    if (flags.zero)
        goto loc_340a;
    ah += 0x02;
    al += 0x03;
    sub_277d();
    al -= 0x03;
    ah--;
    ch = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)ch)
        goto loc_340a;
    si = ax;
    ch = memoryAGet(ds, 0xca32);
    memoryASet(ds, 0xca3a, ch);
    bx = memoryAGet16(ds, 0x0041);
    ah -= bl;
    if ((short)bx >= (short)0x00e8)
        goto loc_340f;
    if ((char)ah <= (char)0x0c)
        goto loc_340f;
    memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + 1);
    goto loc_340f;
loc_346e: // 01ed:159e
    memoryASet16(ds, 0x6bd3, ax);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0x003b, 0xff);
    memoryASet(ds, 0x003e, bl);
    ax = 0x0001;
    bx = 0xffffca3e;
    cx = 0x0004;
    goto loc_265b;
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
}
void sub_34b8() // 01ed:15e8
{
    goto loc_34b8;
loc_2226: // 01ed:0356
    ax = 0x0002;
    sub_2465();
    ax = 0x0002;
    interrupt(0x10);
    bx = 0x21d;
    sub_223d();
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 629 bytes
loc_24b2: // 01ed:05e2
    bx = 0x6bc3;
    al = memoryAGet(ds, 0x003d);
    ah = 0;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(ds, bx);
    di = 0x6af8;
    push(ds);
    es = pop();
    ax = 0x10e5;
    ds = ax;
    cx = 0x00cb;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(es);
    ds = pop();
    dx = 0x6af8;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_24e1;
    goto loc_24f7;
loc_24e1: // 01ed:0611
    bx = ax;
    dx = 0x260;
    cx = 0x4000;
    ax = 0x3f00;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    goto loc_24fa;
loc_24f7: // 01ed:0627
    goto loc_2226;
loc_24fa: // 01ed:062a
    if (memoryAGet(ds, 0x003d) != 0x06)
        goto loc_2515;
    if (memoryAGet(ds, 0x004a) == 0x01)
        goto loc_2515;
    push(ds);
    es = pop();
    ax = 0;
    di = 0x264;
    cx = 0x4000;
    rep_stosb<MemAuto, DirAuto>();
loc_2515: // 01ed:0645
    dx = 0x6b06;
    cx = 0x4266;
    sub_2539();
    dx = 0x6b14;
    cx = 0x476a;
    sub_2539();
    dx = 0x6b22;
    cx = 0x4c6e;
    sub_2539();
    goto loc_2555;
    //   gap of 29 bytes
loc_2555: // 01ed:0685
    si = 0x6b34;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x51a8;
    dx = 0x6aa8;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a4, al);
    sub_25c8();
    si = 0x6b45;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x57e8;
    dx = 0x6abc;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a5, al);
    sub_25c8();
    si = 0x6b56;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x5e28;
    dx = 0x6ad0;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a6, al);
    sub_25c8();
    si = 0x6b67;
    if (memoryAGet(ds, si) == 0x00)
        goto loc_25c5;
    di = 0x6468;
    dx = 0x6ae4;
    al = memoryAGet(ds, si);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, 0x51a7, al);
    sub_25c8();
loc_25c5: // 01ed:06f5
    goto loc_265b;
    //   gap of 147 bytes
loc_265b: // 01ed:078b
    al = memoryAGet(ds, 0x003e);
    dx = 0x426a;
    cx = 0x6b78;
    if (!al)
        goto loc_267e;
    dx = 0x476e;
    cx = 0x6b91;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_267e;
    dx = 0x4c72;
    cx = 0x6baa;
loc_267e: // 01ed:07ae
    memoryASet16(ds, 0x4264, dx);
    memoryASet16(ds, 0x5172, cx);
    sub_2814();
    if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
        goto loc_26bb;
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x5;
    al = memoryAGet(ds, 0x003b);
    ah = memoryAGet(ds, 0x003c);
    cx = 0x0003;
loc_26a1: // 01ed:07d1
    if (al != memoryAGet(ds, si + 2))
        goto loc_26ab;
    if (ah == memoryAGet(ds, si + 3))
        goto loc_26b3;
loc_26ab: // 01ed:07db
    si += 0x0004;
    if (--cx)
        goto loc_26a1;
    goto loc_2226;
loc_26b3: // 01ed:07e3
    ax = memoryAGet16(ds, si);
    ah += 0x01;
    memoryASet16(ds, 0x6bd3, ax);
loc_26bb: // 01ed:07eb
    memoryASet(ds, 0xca34, 0x00);
    cx = 0x0005;
    bx = 0xffffca90;
    ax = 0xffff;
loc_26ca: // 01ed:07fa
    memoryASet16(ds, bx, ax);
    bx += 0x0006;
    if (--cx)
        goto loc_26ca;
    ax = memoryAGet16(ds, 0x6bd3);
    memoryASet16(ds, 0x003f, ax);
    al = ah;
    ah = 0;
    flags.carry = ax < 0x000b;
    ax -= 0x000b;
    if (!flags.carry)
        goto loc_26e2;
    ax = 0;
loc_26e2: // 01ed:0812
    if (ax < 0x00e8)
        goto loc_26ea;
    ax = 0x00e8;
loc_26ea: // 01ed:081a
    memoryASet16(ds, 0x0041, ax);
    si = memoryAGet16(ds, 0x5172);
    si = si + 0x11;
    di = 0x5174;
    cx = 0x0004;
loc_26fb: // 01ed:082b
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_2707;
    memoryASet(ds, di + 11, 0xff);
    goto loc_2751;
loc_2707: // 01ed:0837
    push(cx);
    ah = 0;
    cx = ax;
    bx = 0x51a4;
    bx += ax;
    bl = memoryAGet(ds, bx);
    memoryASet(ds, di + 5, bl);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    dx = 0x6aa8;
    dx += ax;
    memoryASet16(ds, di + 7, dx);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 6, al);
    memoryASet(ds, di + 9, 0x00);
    memoryASet(ds, di + 10, 0x00);
    memoryASet(ds, di + 4, 0x14);
    memoryASet(ds, di + 11, 0x00);
    if (al < 0x80)
        goto loc_2750;
    memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
    memoryASet(ds, di + 11, 0x02);
loc_2750: // 01ed:0880
    cx = pop();
loc_2751: // 01ed:0881
    di += 0x000c;
    si += 0x0002;
    if (--cx)
        goto loc_26fb;
    if (memoryAGet(ds, 0x003b) == 0xfe)
        goto loc_2772;
    if (memoryAGet(ds, 0x003b) == 0xff)
        goto loc_276f;
    sub_2a4e();
    memoryASet(ds, 0x003b, 0xff);
loc_276f: // 01ed:089f
    goto loc_3044;
loc_2772: // 01ed:08a2
    sub_2fc2();
    memoryASet(ds, 0x003b, 0xff);
    goto loc_3044;
    //   gap of 1607 bytes
loc_2dc4: // 01ed:0ef4
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_2bf8();
    bx = 0xffffc9e5;
    ax = 0x0001;
    cx = 0x0002;
loc_2df0: // 01ed:0f20
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_3f80();
    goto loc_2226;
    //   gap of 59 bytes
loc_2e43: // 01ed:0f73
    sub_2f5d();
    cx = 0x0014;
loc_2e49: // 01ed:0f79
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e49;
loc_2e63: // 01ed:0f93
    if (memoryAGet(ds, 0x0043) == 0x00)
        goto loc_2e92;
    cx = 0x000a;
loc_2e6d: // 01ed:0f9d
    push(cx);
    bx = 0xffffc979;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x0a;
    sub_3d3b();
    ax = 0x0001;
    sub_2213();
    cx = pop();
    if (--cx)
        goto loc_2e6d;
    sub_3b6a();
    ax = 0x0003;
    sub_2213();
    goto loc_2e63;
loc_2e92: // 01ed:0fc2
    bx = 0x81;
    ax = 0x0001;
    cx = 0x0004;
    dx = 0xffffc8fe;
    ax = 0x3d00;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_2eab;
    goto loc_2226;
loc_2eab: // 01ed:0fdb
    bp = ax;
    push(ds);
    ax = ds;
    es = ax;
    ax = 0xa000;
    ds = ax;
    ah = 0x01;
    bx = 0;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    dx = memoryAGet16(es, 0xca30);
    cx = 0x1f40;
    ax = 0x3f00;
    bx = bp;
    interrupt(0x21);
    ax = 0x3e00;
    interrupt(0x21);
    ds = pop();
    sub_2173();
    sub_31e2();
    sub_218c();
    ax = 0x0014;
    sub_2213();
    ax = 0;
    es = ax;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    ax = 0;
    interrupt(0x16);
    sub_287a();
    memoryASet16(ds, 0xc8fa, 0x0010);
    memoryASet16(ds, 0xc8fc, 0x0030);
    si = 0xffffbce4;
    di = memoryAGet16(ds, 0xca30);
    di += 0x0a05;
    sub_2e08();
    sub_31e2();
    goto loc_2df0;
    //   gap of 231 bytes
loc_3044: // 01ed:1174
    sync(); timer();
    cx = 0;
    es = cx;
    cl = memoryAGet(es, 0x041a);
    memoryASet(es, 0x041c, cl);
    if (memoryAGet(cs, 0x03ea) == 0x01)
        goto loc_3071;
    if (memoryAGet(ds, 0xca33) == 0x01)
        goto loc_3044;
    if (memoryAGet(cs, 0x0388) == 0x01)
        goto loc_3044;
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
    goto loc_3044;
loc_3071: // 01ed:11a1
    memoryASet(cs, 0x03ea, 0x00);
    if (memoryAGet(ds, 0xca3c) == 0x00)
        goto loc_308c;
    memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
    if (memoryAGet(ds, 0xca3c) != 0x01)
        goto loc_308c;
    goto loc_2e43;
loc_308c: // 01ed:11bc
    ch = memoryAGet(ds, 0xca32);
    ch++;
    if (ch != 0x04)
        goto loc_3099;
    ch = 0x01;
loc_3099: // 01ed:11c9
    memoryASet(ds, 0xca32, ch);
    memoryASet(ds, 0xca3a, 0x00);
    if (memoryAGet(ds, 0xca3b) == 0x00)
        goto loc_30b0;
    memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
    sub_3bcf();
loc_30b0: // 01ed:11e0
    if (memoryAGet(ds, 0xca34) == 0x00)
        goto loc_30bd;
    sub_2d02();
    goto loc_31d3;
loc_30bd: // 01ed:11ed
    si = memoryAGet16(ds, 0x003f);
    if (memoryAGet(ds, 0xca33) == 0x00)
        goto loc_30cb;
    goto loc_32b8;
loc_30cb: // 01ed:11fb
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_30e2;
    if (memoryAGet(ds, 0xca37) == 0x01)
        goto loc_30e8;
    memoryASet(ds, 0xca33, 0x01);
    goto loc_32b8;
loc_30e2: // 01ed:1212
    al = memoryAGet(ds, 0x0047);
    memoryASet(ds, 0xca37, al);
loc_30e8: // 01ed:1218
    if (memoryAGet(cs, 0x0387) != 0x01)
        goto loc_311a;
    di = memoryAGet16(ds, 0x5172);
    bx = di + 0x5;
    cx = 0x0003;
    ax = si;
loc_30fc: // 01ed:122c
    dx = memoryAGet16(ds, bx);
    if (al != dl)
        goto loc_3115;
    dh = -dh;
    dh += ah;
    if (dh >= 0x03)
        goto loc_3115;
    if (memoryAGet(ds, 0x0049) != 0x01)
        goto loc_3115;
    goto loc_348d;
loc_3115: // 01ed:1245
    bx += 0x0004;
    if (--cx)
        goto loc_30fc;
loc_311a: // 01ed:124a
    if (memoryAGet(cs, 0x0389) != 0x01)
        goto loc_312e;
    if (memoryAGet(ds, 0x004b) != 0x01)
        goto loc_312e;
    sub_2c52();
    goto loc_30b0;
loc_312e: // 01ed:125e
    memoryASet(ds, 0xca35, 0x00);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3143;
    memoryASet(ds, 0xca35, 0xfb);
    sub_33b4();
loc_3143: // 01ed:1273
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3153;
    memoryASet(ds, 0xca35, 0x05);
    sub_3410();
loc_3153: // 01ed:1283
    ax = si;
    al += 0x04;
    sub_277d();
    cl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_3190;
    if (!(ah & 0x01))
        goto loc_316c;
    if ((char)memoryAGet(ds, bx + 1) > (char)cl)
        goto loc_3190;
loc_316c: // 01ed:129c
    memoryASet(ds, 0xca36, 0x08);
    if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
        goto loc_3181;
    if (memoryAGet(ds, 0xca35) == 0x00)
        goto loc_3186;
    memoryASet(ds, 0xca35, 0x02);
    goto loc_3186;
loc_3181: // 01ed:12b1
    memoryASet(ds, 0xca35, 0xfe);
loc_3186: // 01ed:12b6
    memoryASet(ds, 0xca33, 0x01);
    memoryASet(ds, 0xca37, 0x01);
loc_3190: // 01ed:12c0
    memoryASet16(ds, 0x003f, si);
    if (memoryAGet(cs, 0x0386) != 0x01)
        goto loc_319f;
    sub_2d85();
loc_319f: // 01ed:12cf
    if (memoryAGet(cs, 0x03a1) != 0x01)
        goto loc_31bf;
    if (memoryAGet(ds, 0x0046) == 0x00)
        goto loc_31cd;
    ax = si;
    al++;
    sub_39fc();
    if (memoryAGet(ds, 0xca3d) == 0x01)
        goto loc_31c8;
    sub_3c4d();
loc_31bf: // 01ed:12ef
    tl = memoryAGet(ds, 0xca3d);
    memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
    if (tl != 1)
        goto loc_31cd;
    sub_3c1e();
loc_31c8: // 01ed:12f8
    memoryASet(ds, 0xca3d, 0x02);
loc_31cd: // 01ed:12fd
    sub_287a();
    sub_28ac();
loc_31d3: // 01ed:1303
    sub_34b8();
    sub_3a35();
    sub_31f7();
    sub_31e2();
    goto loc_3044;
    //   gap of 82 bytes
loc_3234: // 01ed:1364
    ax = si;
    memoryASet16(ds, 0x003f, ax);
    if ((char)al > (char)0x13)
        goto loc_3263;
    memoryASet(ds, 0xca3a, 0x04);
    cx = 0x0014;
    cl -= al;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    push(cx);
    sub_287a();
    cx = pop();
    bx = 0x0020;
    bx -= cx;
    sub_29b8();
    sub_31e2();
    ax = 0x0001;
    sub_2213();
loc_3263: // 01ed:1393
    sub_287a();
    sub_31e2();
    ax = 0x0002;
    sub_2213();
    ax = 0x0001;
    bx = 0xffffca5e;
    cx = 0x0004;
    ax = 0x000f;
    sub_2213();
    if (memoryAGet(ds, 0x0043) != 0x00)
        goto loc_328a;
    goto loc_2dc4;
loc_328a: // 01ed:13ba
    sub_3b6a();
    memoryASet(ds, 0xca32, 0x00);
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca35, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    memoryASet(ds, 0xca37, 0x00);
    memoryASet(ds, 0xca3a, 0x00);
    memoryASet(ds, 0xca3b, 0x06);
    memoryASet(ds, 0xca3d, 0x02);
    goto loc_26bb;
loc_32b8: // 01ed:13e8
    tl = memoryAGet(ds, 0xca37);
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
    if (tl == 1)
        goto loc_32cd;
    if (memoryAGet(cs, 0x0388) != 0x01)
        goto loc_32d1;
    memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
    goto loc_32d1;
loc_32cd: // 01ed:13fd
    memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_32d1: // 01ed:1401
    al = memoryAGet(ds, 0xca36);
    cl = al;
    al = sar(al, 1);
    al = sar(al, 1);
    al = sar(al, 1);
    bx = si;
    tl = bl;
    bl += al;
    if ((char)tl + (char)al >= 0)
        goto loc_32e4;
    bl = 0x00;
loc_32e4: // 01ed:1414
    si = bx;
    if (bl < 0x11)
        goto loc_32ee;
    goto loc_3234;
loc_32ee: // 01ed:141e
    if (memoryAGet(ds, 0x003d) != 0x02)
        goto loc_32f8;
    cl -= 0x02;
loc_32f8: // 01ed:1428
    cl += 0x05;
    if ((char)cl < (char)0x18)
        goto loc_3302;
    cl = 0x17;
loc_3302: // 01ed:1432
    memoryASet(ds, 0xca36, cl);
    cl = memoryAGet(ds, 0xca35);
    if (memoryAGet(cs, 0x039a) != 0x01)
        goto loc_3320;
    memoryASet(ds, 0xca39, 0x05);
    cl--;
    if ((char)cl >= (char)0xfb)
        goto loc_3320;
    cl = 0xfb;
loc_3320: // 01ed:1450
    if (memoryAGet(cs, 0x039c) != 0x01)
        goto loc_3336;
    memoryASet(ds, 0xca39, 0x00);
    cl++;
    if ((char)cl <= (char)0x05)
        goto loc_3336;
    cl = 0x05;
loc_3336: // 01ed:1466
    memoryASet(ds, 0xca35, cl);
    if ((char)cl >= 0)
        goto loc_3345;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
    sub_33c2();
loc_3345: // 01ed:1475
    al = memoryAGet(ds, 0xca35);
    if ((char)al <= 0)
        goto loc_3353;
    memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
    sub_341e();
loc_3353: // 01ed:1483
    ax = si;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_336a;
    if (!(ah & 0x01))
        goto loc_336f;
    if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
        goto loc_336f;
loc_336a: // 01ed:149a
    memoryASet(ds, 0xca36, 0x08);
loc_336f: // 01ed:149f
    if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
        goto loc_3391;
    cx = si;
    ax = cx;
    al += 0x05;
    sub_277d();
    dl = memoryAGet(ds, 0x0260);
    if ((char)memoryAGet(ds, bx) > (char)dl)
        goto loc_3399;
    if (!(ah & 0x01))
        goto loc_3391;
    if ((char)memoryAGet(ds, bx + 1) > (char)dl)
        goto loc_3399;
loc_3391: // 01ed:14c1
    memoryASet(ds, 0xca3a, 0x04);
    goto loc_3190;
loc_3399: // 01ed:14c9
    if (cl < 0x0f)
        goto loc_33a0;
    goto loc_3391;
loc_33a0: // 01ed:14d0
    cl++;
    cl &= 0xfe;
    si = cx;
    memoryASet(ds, 0xca33, 0x00);
    memoryASet(ds, 0xca36, 0x00);
    goto loc_3190;
    //   gap of 217 bytes
loc_348d: // 01ed:15bd
    push(bx);
    ax = memoryAGet16(ds, bx);
    sub_2acb();
    bx = pop();
    al = memoryAGet(ds, 0x003d);
    memoryASet(ds, 0x003b, al);
    al = memoryAGet(ds, 0x003e);
    memoryASet(ds, 0x003c, al);
    al = memoryAGet(ds, bx + 3);
    memoryASet(ds, 0x003e, al);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, 0x003d, al);
    if (al == memoryAGet(ds, 0x003b))
        goto loc_34b5;
    goto loc_24b2;
loc_34b5: // 01ed:15e5
    goto loc_265b;
loc_34b8: // 01ed:15e8
    memoryASet(ds, 0xca82, 0x00);
    si = 0x5174;
    cx = 0x0004;
loc_34c4: // 01ed:15f4
    push(cx);
    if (memoryAGet(ds, si + 9) == 0x01)
        goto loc_34dc;
    if (memoryAGet(ds, si + 9) < 0x01)
        goto loc_34d0;
    goto loc_359d;
loc_34d0: // 01ed:1600
    flags.carry = memoryAGet(ds, si + 4) < 0x01;
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 0x01);
    if (!flags.carry)
        goto loc_34d9;
    goto loc_3957;
loc_34d9: // 01ed:1609
    goto loc_3592;
loc_34dc: // 01ed:160c
    al = memoryAGet(ds, si + 4);
    al++;
    if (al != memoryAGet(ds, si + 5))
        goto loc_34e8;
    al = 0;
loc_34e8: // 01ed:1618
    memoryASet(ds, si + 4, al);
    al = memoryAGet(ds, si + 6);
    tl = al;
    al--;
    if (tl == 1)
        goto loc_3505;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_3508;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_350b;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_350e;
    tl = al;
    al--;
    if (tl == 1)
        goto loc_3511;
    goto loc_3592;
loc_3505: // 01ed:1635
    goto loc_3713;
loc_3508: // 01ed:1638
    goto loc_3629;
loc_350b: // 01ed:163b
    goto loc_37b0;
loc_350e: // 01ed:163e
    goto loc_383d;
loc_3511: // 01ed:1641
    goto loc_389e;
loc_3514: // 01ed:1644
    ax = memoryAGet16(ds, si);
    bx = ax;
    dx = memoryAGet16(ds, 0x003f);
    flags.carry = bh < dh;
    bh -= dh;
    if (!flags.carry)
        goto loc_3522;
    bh = -bh;
loc_3522: // 01ed:1652
    if (bh < 0x1e)
        goto loc_352a;
    goto loc_3611;
loc_352a: // 01ed:165a
    if (bh >= 0x02)
        goto loc_3561;
    tl = bl;
    bl -= dl;
    if (tl < dl)
        goto loc_3561;
    if (bl >= 0x04)
        goto loc_3561;
    memoryASet(ds, si + 9, 0x08);
    if (memoryAGet(ds, 0x0044) != 0x00)
        goto loc_355a;
    if (memoryAGet(ds, 0xca83) != 0x00)
        goto loc_355a;
    memoryASet(ds, 0xca83, 0x01);
    sub_2c02();
    memoryASet(ds, 0xca83, 0x00);
    goto loc_3263;
loc_355a: // 01ed:168a
    push(si);
    sub_3bf4();
    si = pop();
    goto loc_359d;
loc_3561: // 01ed:1691
    dx = memoryAGet16(ds, 0x0041);
    ah -= dl;
    if ((char)ah < (char)0x00)
        goto loc_3592;
    if ((char)ah > (char)0x16)
        goto loc_3592;
    push(si);
    push(ax);
    al = memoryAGet(ds, si + 4);
    al += memoryAGet(ds, si + 10);
    ah = 0;
    ax <<= 1;
    si = memoryAGet16(ds, si + 7);
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0080;
    cx = 0x0010;
    ax = pop();
    sub_28f1();
    si = pop();
loc_3592: // 01ed:16c2
    cx = pop();
    si += 0x000c;
    tx = cx;
    cx--;
    if (tx == 1)
        goto loc_359c;
    goto loc_34c4;
loc_359c: // 01ed:16cc
    return;
loc_359d: // 01ed:16cd
    bl = memoryAGet(ds, si + 9);
    if (bl == 0x07)
        goto loc_35af;
    if ((char)bl < (char)0x07)
        goto loc_35b1;
    bl -= 0x06;
    if (bl != 0x07)
        goto loc_35b1;
loc_35af: // 01ed:16df
    goto loc_3611;
loc_35b1: // 01ed:16e1
    ax = memoryAGet16(ds, si);
    dx = memoryAGet16(ds, 0x0041);
    ah -= dl;
    if ((char)ah < (char)0x00)
        goto loc_3611;
    if ((char)ah > (char)0x16)
        goto loc_3611;
    if ((char)bl > (char)0x04)
        goto loc_35eb;
    push(si);
    push(ax);
    al = memoryAGet(ds, si + 4);
    al += memoryAGet(ds, si + 10);
    ah = 0;
    ax <<= 1;
    si = memoryAGet16(ds, si + 7);
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0080;
    cx = 0x0010;
    ax = pop();
    push(ax);
    sub_28f1();
    ax = pop();
    si = pop();
loc_35eb: // 01ed:171b
    push(si);
    push(ax);
    al = memoryAGet(ds, si + 9);
    ah = 0;
    al -= 0x02;
    ax <<= 1;
    si = 0xffff9984;
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0080;
    cx = 0x0010;
    ax = pop();
    sub_28f1();
    si = pop();
    memoryASet(ds, si + 9, memoryAGet(ds, si + 9) + 1);
    goto loc_3592;
loc_3611: // 01ed:1741
    memoryASet(ds, si + 9, 0x00);
    al = memoryAGet(ds, 0xca80);
    memoryASet(ds, si + 4, al);
    al += 0x14;
    if ((char)al < (char)0x78)
        goto loc_3623;
    al = 0x14;
loc_3623: // 01ed:1753
    memoryASet(ds, 0xca80, al);
    goto loc_3592;
loc_3629: // 01ed:1759
    bl = memoryAGet(ds, si + 3);
    if ((char)bl < 0)
        goto loc_3640;
    if ((char)bl > 0)
        goto loc_3657;
    ax = memoryAGet16(ds, si);
    al += 0x02;
    sub_27a0();
    if (flags.carry)
        goto loc_363d;
    goto loc_367b;
loc_363d: // 01ed:176d
    goto loc_36fa;
loc_3640: // 01ed:1770
    dl = bl;
    bl = sar(bl, 1);
    bl = sar(bl, 1);
    bl = sar(bl, 1);
    bl = -bl;
    ax = memoryAGet16(ds, si);
    tl = al;
    al -= bl;
    if (tl < bl)
        goto loc_367e;
    sub_27a0();
    if (flags.carry)
        goto loc_367e;
    goto loc_3680;
loc_3657: // 01ed:1787
    dl = bl;
    bl = sar(bl, 1);
    bl = sar(bl, 1);
    bl = sar(bl, 1);
    ax = memoryAGet16(ds, si);
    al += bl;
    if ((char)al < (char)0x12)
        goto loc_3672;
    memoryASet(ds, si + 9, 0x07);
    al = 0x12;
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_3672: // 01ed:17a2
    al++;
    sub_27a0();
    flags.carry = al == 0;
    al--;
    if (!flags.carry)
        goto loc_3680;
loc_367b: // 01ed:17ab
    dl = memoryAGet(ds, si + 3);
loc_367e: // 01ed:17ae
    ax = memoryAGet16(ds, si);
loc_3680: // 01ed:17b0
    dl += 0x02;
    if ((char)dl < (char)0x18)
        goto loc_368a;
    dl = 0x17;
loc_368a: // 01ed:17ba
    memoryASet(ds, si + 3, dl);
    if (memoryAGet(ds, si + 11) == 0x01)
        goto loc_36da;
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
    dx = memoryAGet16(ds, 0x0041);
    if (memoryAGet(ds, si + 2) != 0x01)
        goto loc_36bf;
    ah += 0x02;
    sub_27da();
    flags.carry = ah == 0;
    ah--;
    if (!flags.carry)
        goto loc_36ae;
    ah--;
    goto loc_36b9;
loc_36ae: // 01ed:17de
    bh = ah;
    tl = bh;
    bh -= dl;
    if (tl < dl)
        goto loc_36de;
    if (bh < 0x16)
        goto loc_36de;
loc_36b9: // 01ed:17e9
    memoryASet(ds, si + 2, 0xff);
    goto loc_36de;
loc_36bf: // 01ed:17ef
    if (!ah)
        goto loc_36d4;
    ah--;
    sub_27da();
    if (!flags.carry)
        goto loc_36ce;
    ah++;
    goto loc_36d4;
loc_36ce: // 01ed:17fe
    bh = ah;
    if (bh > dl)
        goto loc_36de;
loc_36d4: // 01ed:1804
    memoryASet(ds, si + 2, 0x01);
    goto loc_36de;
loc_36da: // 01ed:180a
    memoryASet(ds, si + 11, 0x00);
loc_36de: // 01ed:180e
    dx = ax;
    if ((char)memoryAGet(ds, si + 3) <= (char)0x00)
        goto loc_36ed;
    al += 0x03;
    sub_27a0();
    if (flags.carry)
        goto loc_36ef;
loc_36ed: // 01ed:181d
    goto loc_370e;
loc_36ef: // 01ed:181f
    dl++;
    dl &= 0xfe;
    memoryASet(ds, si + 3, 0x00);
    goto loc_370e;
loc_36fa: // 01ed:182a
    ax = memoryAGet16(ds, 0x003f);
    ch = 0x01;
    dx = memoryAGet16(ds, si);
    if (ah >= dh)
        goto loc_3707;
    ch = 0xff;
loc_3707: // 01ed:1837
    memoryASet(ds, si + 2, ch);
    memoryASet(ds, si + 3, 0xf9);
loc_370e: // 01ed:183e
    memoryASet16(ds, si, dx);
    goto loc_3514;
loc_3713: // 01ed:1843
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, si);
    if ((char)memoryAGet(ds, si + 11) > (char)0x01)
        goto loc_3727;
    if (memoryAGet(ds, si + 11) != 0x01)
        goto loc_3724;
    goto loc_37a7;
loc_3724: // 01ed:1854
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
loc_3727: // 01ed:1857
    if (memoryAGet(ds, si + 2) != 0x01)
        goto loc_3750;
    memoryASet(ds, si + 10, 0x05);
    ah += 0x02;
    sub_27da();
    flags.carry = ah == 0;
    ah--;
    if (!flags.carry)
        goto loc_373f;
    ah--;
    goto loc_374a;
loc_373f: // 01ed:186f
    bh = ah;
    tl = bh;
    bh -= dl;
    if (tl < dl)
        goto loc_376d;
    if (bh < 0x16)
        goto loc_376d;
loc_374a: // 01ed:187a
    memoryASet(ds, si + 2, 0xff);
    goto loc_376d;
loc_3750: // 01ed:1880
    memoryASet(ds, si + 10, 0x00);
    if (!ah)
        goto loc_3769;
    ah--;
    sub_27da();
    if (!flags.carry)
        goto loc_3763;
    ah++;
    goto loc_3769;
loc_3763: // 01ed:1893
    bh = ah;
    if (bh > dl)
        goto loc_376d;
loc_3769: // 01ed:1899
    memoryASet(ds, si + 2, 0x01);
loc_376d: // 01ed:189d
    if (memoryAGet(ds, si + 3) != 0x01)
        goto loc_378e;
    if ((char)al >= (char)0x12)
        goto loc_3788;
    al += 0x02;
    sub_27a0();
    flags.carry = al == 0;
    al--;
    if (!flags.carry)
        goto loc_3784;
    al--;
    goto loc_3788;
loc_3784: // 01ed:18b4
    if ((char)al < (char)0x12)
        goto loc_37ab;
loc_3788: // 01ed:18b8
    memoryASet(ds, si + 3, 0xff);
    goto loc_37ab;
loc_378e: // 01ed:18be
    if (!al)
        goto loc_37a1;
    al--;
    sub_27a0();
    if (!flags.carry)
        goto loc_379d;
    al++;
    goto loc_37a1;
loc_379d: // 01ed:18cd
    if (al)
        goto loc_37ab;
loc_37a1: // 01ed:18d1
    memoryASet(ds, si + 3, 0x01);
    goto loc_37ab;
loc_37a7: // 01ed:18d7
    memoryASet(ds, si + 11, 0x00);
loc_37ab: // 01ed:18db
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_37b0: // 01ed:18e0
    ch = memoryAGet(ds, si + 3);
    if ((char)ch > 0)
        goto loc_37ba;
    goto loc_37cf;
loc_37ba: // 01ed:18ea
    ax = memoryAGet16(ds, si);
    al++;
    if ((char)al < (char)0x11)
        goto loc_37cd;
    memoryASet(ds, si + 9, 0x07);
    al = 0x12;
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_37cd: // 01ed:18fd
    goto loc_37e6;
loc_37cf: // 01ed:18ff
    dx = memoryAGet16(ds, 0x003f);
    ch = 0x01;
    ax = memoryAGet16(ds, si);
    if (dh == ah)
        goto loc_37e1;
    if (dh >= ah)
        goto loc_37e3;
    ch = 0xff;
    goto loc_37e3;
loc_37e1: // 01ed:1911
    ch = 0;
loc_37e3: // 01ed:1913
    memoryASet(ds, si + 2, ch);
loc_37e6: // 01ed:1916
    if (memoryAGet(ds, si + 11) == 0x01)
        goto loc_3814;
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
    dx = memoryAGet16(ds, 0x0041);
    if (memoryAGet(ds, si + 2) == 0x00)
        goto loc_3814;
    if ((char)memoryAGet(ds, si + 2) < (char)0x00)
        goto loc_3809;
    ah += 0x02;
    sub_27da();
    flags.carry = ah == 0;
    ah--;
    if (!flags.carry)
        goto loc_3818;
    ah--;
    goto loc_3818;
loc_3809: // 01ed:1939
    ah--;
    sub_27da();
    if (!flags.carry)
        goto loc_3818;
    ah++;
    goto loc_3818;
loc_3814: // 01ed:1944
    memoryASet(ds, si + 11, 0x00);
loc_3818: // 01ed:1948
    al += 0x03;
    sub_27a0();
    if (flags.carry)
        goto loc_3828;
    al -= 0x03;
    memoryASet(ds, si + 3, 0x01);
    goto loc_3838;
loc_3828: // 01ed:1958
    al -= 0x03;
    if (memoryAGet(ds, si + 3) == 0x00)
        goto loc_3838;
    al++;
    al &= 0xfe;
    memoryASet(ds, si + 3, 0x00);
loc_3838: // 01ed:1968
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_383d: // 01ed:196d
    dx = memoryAGet16(ds, 0x003f);
    ax = memoryAGet16(ds, si);
    if (memoryAGet(ds, si + 11) == 0x01)
        goto loc_3875;
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
    bx = ax;
    flags.carry = bh < dh;
    bh -= dh;
    if (bh == 0)
        goto loc_387e;
    if (!flags.carry)
        goto loc_3866;
    memoryASet(ds, si + 10, 0x05);
    ah += 0x02;
    sub_27da();
    flags.carry = ah == 0;
    ah--;
    if (!flags.carry)
        goto loc_3879;
    ah--;
    goto loc_387e;
loc_3866: // 01ed:1996
    memoryASet(ds, si + 10, 0x00);
    ah--;
    sub_27da();
    if (!flags.carry)
        goto loc_3879;
    ah++;
    goto loc_387e;
loc_3875: // 01ed:19a5
    memoryASet(ds, si + 11, 0x00);
loc_3879: // 01ed:19a9
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_387e: // 01ed:19ae
    bx = ax;
    flags.carry = bl < dl;
    bl -= dl;
    if (bl == 0)
        goto loc_3875;
    if (!flags.carry)
        goto loc_3893;
    al += 0x02;
    sub_27a0();
    flags.carry = al == 0;
    al--;
    if (!flags.carry)
        goto loc_3879;
    al--;
    goto loc_3875;
loc_3893: // 01ed:19c3
    al--;
    sub_27a0();
    if (!flags.carry)
        goto loc_3879;
    al++;
    goto loc_3875;
loc_389e: // 01ed:19ce
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, si);
    if ((char)memoryAGet(ds, si + 11) > (char)0x01)
        goto loc_38b2;
    if (memoryAGet(ds, si + 11) != 0x01)
        goto loc_38af;
    goto loc_394e;
loc_38af: // 01ed:19df
    memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
loc_38b2: // 01ed:19e2
    if (memoryAGet(ds, si + 2) != 0x01)
        goto loc_38db;
    memoryASet(ds, si + 10, 0x05);
    ah += 0x02;
    sub_27da();
    flags.carry = ah == 0;
    ah--;
    if (!flags.carry)
        goto loc_38ca;
    ah--;
    goto loc_38d5;
loc_38ca: // 01ed:19fa
    bh = ah;
    tl = bh;
    bh -= dl;
    if (tl < dl)
        goto loc_38f8;
    if (bh < 0x16)
        goto loc_38f8;
loc_38d5: // 01ed:1a05
    memoryASet(ds, si + 2, 0xff);
    goto loc_38f8;
loc_38db: // 01ed:1a0b
    memoryASet(ds, si + 10, 0x00);
    if (!ah)
        goto loc_38f4;
    ah--;
    sub_27da();
    if (!flags.carry)
        goto loc_38ee;
    ah++;
    goto loc_38f4;
loc_38ee: // 01ed:1a1e
    bh = ah;
    if (bh > dl)
        goto loc_38f8;
loc_38f4: // 01ed:1a24
    memoryASet(ds, si + 2, 0x01);
loc_38f8: // 01ed:1a28
    dx = memoryAGet16(ds, 0x003f);
    tl = dh;
    dh -= ah;
    if (dh == 0)
        goto loc_3914;
    if (tl < ah)
        goto loc_390b;
    if (memoryAGet(ds, 0xca39) != 0x05)
        goto loc_3914;
    goto loc_3935;
loc_390b: // 01ed:1a3b
    if (memoryAGet(ds, 0xca39) != 0x00)
        goto loc_3914;
    goto loc_3935;
loc_3914: // 01ed:1a44
    tl = dl;
    dl -= al;
    if (dl == 0)
        goto loc_3952;
    if (tl < al)
        goto loc_3935;
    if ((char)al >= (char)0x12)
        goto loc_392f;
    al += 0x02;
    sub_27a0();
    flags.carry = al == 0;
    al--;
    if (!flags.carry)
        goto loc_392b;
    al--;
    goto loc_392f;
loc_392b: // 01ed:1a5b
    if ((char)al < (char)0x12)
        goto loc_3952;
loc_392f: // 01ed:1a5f
    memoryASet(ds, si + 3, 0xff);
    goto loc_3952;
loc_3935: // 01ed:1a65
    if (!al)
        goto loc_3948;
    al--;
    sub_27a0();
    if (!flags.carry)
        goto loc_3944;
    al++;
    goto loc_3948;
loc_3944: // 01ed:1a74
    if (al)
        goto loc_3952;
loc_3948: // 01ed:1a78
    memoryASet(ds, si + 3, 0x01);
    goto loc_3952;
loc_394e: // 01ed:1a7e
    memoryASet(ds, si + 11, 0x00);
loc_3952: // 01ed:1a82
    memoryASet16(ds, si, ax);
    goto loc_3514;
loc_3957: // 01ed:1a87
    memoryASet(ds, si + 4, 0x00);
    if (memoryAGet(ds, 0xca82) != 0x00)
        goto loc_3985;
    ax = memoryAGet16(ds, 0x0041);
    ah = memoryAGet(ds, 0xca81);
    ah += 0x02;
    if (ah < 0x1f)
        goto loc_3973;
    ah = 0x18;
loc_3973: // 01ed:1aa3
    memoryASet(ds, 0xca81, ah);
    if (memoryAGet(ds, 0xca39) == 0x00)
        goto loc_3987;
    ah -= 0x16;
    flags.carry = al < ah;
    al -= ah;
    if (!flags.carry)
        goto loc_398b;
loc_3985: // 01ed:1ab5
    goto loc_39f9;
loc_3987: // 01ed:1ab7
    flags.carry = sign((int8_t)al) != sign((int8_t)(al+ah));
    al += ah;
    if (flags.carry) // jxxx cico
        goto loc_39f9;
//    stop(); // jo loc_39f9
loc_398b: // 01ed:1abb
    ah = al;
    al = memoryAGet(ds, 0x003f);
    al &= 0xfe;
    al += 0x04;
    cl = memoryAGet(ds, 0x0260);
    sub_277d();
loc_399b: // 01ed:1acb
    if ((char)memoryAGet(ds, bx) > (char)cl)
        goto loc_39ae;
    bx -= 0x0080;
    al -= 0x02;
    if (al != 0)
        goto loc_399b;
    goto loc_3592;
loc_39aa: // 01ed:1ada
    if ((char)memoryAGet(ds, bx) <= (char)cl)
        goto loc_39b9;
loc_39ae: // 01ed:1ade
    bx -= 0x0080;
    flags.carry = al < 0x02;
    al -= 0x02;
    if (!flags.carry)
        goto loc_39aa;
    goto loc_3592;
loc_39b9: // 01ed:1ae9
    memoryASet(ds, 0xca82, 0x01);
    memoryASet16(ds, si, ax);
    memoryASet(ds, si + 9, 0x01);
    if (memoryAGet(ds, si + 6) == 0x01)
        goto loc_39e6;
    if (memoryAGet(ds, si + 6) == 0x05)
        goto loc_39e6;
    if (memoryAGet(ds, si + 6) != 0x7f)
        goto loc_39f1;
    memoryASet(ds, 0xca82, 0x00);
    memoryASet(ds, si + 9, 0x00);
    memoryASet(ds, si + 4, 0x64);
    goto loc_3592;
loc_39e6: // 01ed:1b16
    memoryASet(ds, si + 2, 0xff);
    memoryASet(ds, si + 3, 0xff);
    goto loc_3592;
loc_39f1: // 01ed:1b21
    memoryASet(ds, si + 2, 0x00);
    memoryASet(ds, si + 3, 0x00);
loc_39f9: // 01ed:1b29
    goto loc_3592;
}
void sub_39fc() // 01ed:1b2c
{
    cl = memoryAGet(ds, 0x0045);
    if (!cl)
        return;
    ch = 0;
    si = 0xffffca90;
loc_3a0a: // 01ed:1b3a
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_3a2f;
    memoryASet16(ds, si, ax);
    al = 0x02;
    if (memoryAGet(ds, 0xca39) == 0x00)
        goto loc_3a1c;
    al = 0xfe;
loc_3a1c: // 01ed:1b4c
    memoryASet(ds, si + 2, al);
    memoryASet(ds, si + 3, 0x02);
    ax = 0x0001;
    bx = 0xffffcaae;
    cx = 0x0000;
    return;
loc_3a2f: // 01ed:1b5f
    si += 0x0006;
    if (--cx)
        goto loc_3a0a;
}
void sub_3a35() // 01ed:1b65
{
    cl = memoryAGet(ds, 0x0045);
    if (cl)
        goto loc_3a3e;
    return;
loc_3a3e: // 01ed:1b6e
    ch = 0;
    si = 0xffffca90;
loc_3a44: // 01ed:1b74
    push(cx);
    ax = memoryAGet16(ds, si);
    if (ax == 0xffff)
        goto loc_3abf;
    dl = memoryAGet(ds, si + 2);
    if ((char)dl > 0)
        goto loc_3a5b;
    dl = -dl;
    tl = ah;
    ah -= dl;
    if (tl < dl)
        goto loc_3a6c;
    goto loc_3a5d;
loc_3a5b: // 01ed:1b8b
    ah += dl;
loc_3a5d: // 01ed:1b8d
    dx = memoryAGet16(ds, 0x0041);
    dh = ah;
    tl = dh;
    dh -= dl;
    if (tl < dl)
        goto loc_3a6c;
    if ((char)dh <= (char)0x16)
        goto loc_3a72;
loc_3a6c: // 01ed:1b9c
    memoryASet16(ds, si, 0xffff);
    goto loc_3abf;
loc_3a72: // 01ed:1ba2
    if (memoryAGet(ds, 0x0048) != 0x01)
        goto loc_3a88;
    tl = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 1);
    if (tl == 1)
        goto loc_3a82;
    al++;
    goto loc_3a88;
loc_3a82: // 01ed:1bb2
    al--;
    memoryASet(ds, si + 3, 0x02);
loc_3a88: // 01ed:1bb8
    memoryASet16(ds, si, ax);
    al = memoryAGet(ds, si + 4);
    al++;
    if (al != memoryAGet(ds, si + 5))
        goto loc_3a96;
    al = 0;
loc_3a96: // 01ed:1bc6
    memoryASet(ds, si + 4, al);
    dx = memoryAGet16(ds, 0x0041);
    ax = memoryAGet16(ds, si);
    ah -= dl;
    push(si);
    push(ax);
    al = memoryAGet(ds, si + 4);
    ah = 0;
    ax <<= 1;
    si = 0xffff9980;
    si += ax;
    si = memoryAGet16(ds, si);
    bp = si;
    bp += 0x0040;
    cx = 0x0008;
    ax = pop();
    sub_28f1();
    si = pop();
loc_3abf: // 01ed:1bef
    cx = pop();
    si += 0x0006;
    tx = cx;
    cx--;
    if (tx == 1)
        goto loc_3ac9;
    goto loc_3a44;
loc_3ac9: // 01ed:1bf9
    si = 0xffffca90;
    cx = 0x0005;
loc_3ad0: // 01ed:1c00
    push(cx);
    dx = memoryAGet16(ds, si);
    if (dx == 0xffff)
        goto loc_3b02;
    di = 0x5174;
    cx = 0x0004;
loc_3adf: // 01ed:1c0f
    if (memoryAGet(ds, di + 9) != 0x01)
        goto loc_3afd;
    ax = memoryAGet16(ds, di);
    bx = dx;
    tl = bl;
    bl -= al;
    if (tl < al)
        goto loc_3afd;
    if ((char)bl > (char)0x01)
        goto loc_3afd;
    flags.carry = bh < ah;
    bh -= ah;
    if (!flags.carry)
        goto loc_3af8;
    bh = -bh;
loc_3af8: // 01ed:1c28
    if ((char)bh <= (char)0x01)
        goto loc_3b09;
loc_3afd: // 01ed:1c2d
    di += 0x000c;
    if (--cx)
        goto loc_3adf;
loc_3b02: // 01ed:1c32
    cx = pop();
    si += 0x0006;
    if (--cx)
        goto loc_3ad0;
    return;
loc_3b09: // 01ed:1c39
    memoryASet(ds, di + 9, 0x02);
    memoryASet16(ds, si, 0xffff);
    push(si);
    push(di);
    al = 0x03;
    sub_3d3b();
    di = pop();
    si = pop();
    ax = 0x0001;
    bx = 0xffffcaba;
    cx = 0x0001;
    goto loc_3b02;
}
void sub_3b27() // 01ed:1c57
{
    ax = 0x0001;
    bx = 0xffffcaf5;
    cx = 0x0004;
    al = memoryAGet(ds, 0x0043);
    if (al == 0x05)
        goto loc_3b55;
    al++;
    memoryASet(ds, 0x0043, al);
    bx = 0xa000;
    es = bx;
    di = 0x1c23;
    ah = 0;
    di += ax;
    di += ax;
    di += ax;
    si = 0xffffa304;
    goto loc_3b91;
loc_3b55: // 01ed:1c85
    memoryASet(ds, 0xca3b, 0x06);
    al = 0x4b;
    sub_3d3b();
    al = 0x4b;
    sub_3d3b();
    al = 0x4b;
    sub_3d3b();
    return;
    //   gap of 39 bytes
loc_3b91: // 01ed:1cc1
    ah = 0x01;
    sub_3ba6();
    ah = 0x02;
    sub_3ba6();
    ah = 0x04;
    sub_3ba6();
    ah = 0x08;
    sub_3ba6();
}
void sub_3b6a() // 01ed:1c9a
{
    al = memoryAGet(ds, 0x0043);
    if (al == 0x00)
        goto loc_3b90;
    memoryASet(ds, 0x0043, memoryAGet(ds, 0x0043) - 1);
    bx = 0xa000;
    es = bx;
    di = 0x1c23;
    ah = 0;
    di += ax;
    di += ax;
    di += ax;
    si = 0xffffa304;
    si += 0x0a00;
    goto loc_3b91;
loc_3b90: // 01ed:1cc0
    return;
loc_3b91: // 01ed:1cc1
    ah = 0x01;
    sub_3ba6();
    ah = 0x02;
    sub_3ba6();
    ah = 0x04;
    sub_3ba6();
    ah = 0x08;
    sub_3ba6();
}
void sub_3ba6() // 01ed:1cd6
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    bx = 0x0010;
    push(si);
    push(di);
loc_3bb5: // 01ed:1ce5
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3bb5;
    di = pop();
    si = pop();
    bx = 0x0010;
    push(di);
    di += 0x2000;
loc_3bc6: // 01ed:1cf6
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3bc6;
    di = pop();
}
void sub_3bcf() // 01ed:1cff
{
    al = memoryAGet(ds, 0x0044);
    if (al == 0x06)
        goto loc_3bee;
    al++;
    memoryASet(ds, 0x0044, al);
    bx = 0xa000;
    es = bx;
    di = 0x0cee;
    ah = 0;
    di += ax;
    si = 0xffffb0a4;
    goto loc_3c7b;
loc_3bee: // 01ed:1d1e
    al = 0x12;
    sub_3d3b();
    return;
    //   gap of 135 bytes
loc_3c7b: // 01ed:1dab
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
}
void sub_3bf4() // 01ed:1d24
{
    bx = 0xffffcad1;
    ax = 0x0001;
    cx = 0x0002;
    al = memoryAGet(ds, 0x0044);
    if (al == 0x00)
        goto loc_3c1d;
    memoryASet(ds, 0x0044, memoryAGet(ds, 0x0044) - 1);
    bx = 0xa000;
    es = bx;
    di = 0x0cee;
    ah = 0;
    di += ax;
    si = 0xffffb024;
    goto loc_3c7b;
loc_3c1d: // 01ed:1d4d
    return;
    //   gap of 93 bytes
loc_3c7b: // 01ed:1dab
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
}
void sub_3c1e() // 01ed:1d4e
{
    al = memoryAGet(ds, 0x0046);
    if (al == 0x0c)
        goto loc_3c4c;
    al++;
    memoryASet(ds, 0x0046, al);
    ah = al;
    al++;
    al >>= 1;
    bx = 0xa000;
    es = bx;
    di = 0x088e;
    si = 0xffffb064;
    if (ah & 0x01)
        goto loc_3c45;
    si = 0xffffb0a4;
loc_3c45: // 01ed:1d75
    ah = 0;
    di += ax;
    goto loc_3c7b;
loc_3c4c: // 01ed:1d7c
    return;
    //   gap of 46 bytes
loc_3c7b: // 01ed:1dab
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
}
void sub_3c4d() // 01ed:1d7d
{
    al = memoryAGet(ds, 0x0046);
    if (al == 0x00)
        goto loc_3c7a;
    memoryASet(ds, 0x0046, memoryAGet(ds, 0x0046) - 1);
    ah = al;
    al++;
    al >>= 1;
    bx = 0xa000;
    es = bx;
    di = 0x088e;
    si = 0xffffb064;
    if (!(ah & 0x01))
        goto loc_3c73;
    si = 0xffffb024;
loc_3c73: // 01ed:1da3
    ah = 0;
    di += ax;
    goto loc_3c7b;
loc_3c7a: // 01ed:1daa
    return;
loc_3c7b: // 01ed:1dab
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
}
void sub_3c7b() // 01ed:1dab
{
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
}
void sub_3c90() // 01ed:1dc0
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    bx = 0x0010;
    push(si);
    push(di);
loc_3c9f: // 01ed:1dcf
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0027;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3c9f;
    di = pop();
    si = pop();
    bx = 0x0010;
    push(di);
    di += 0x2000;
loc_3cb0: // 01ed:1de0
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0027;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3cb0;
    di = pop();
}
void sub_3cf5() // 01ed:1e25
{
    ah = 0x01;
    sub_3d0a();
    ah = 0x02;
    sub_3d0a();
    ah = 0x04;
    sub_3d0a();
    ah = 0x08;
    sub_3d0a();
}
void sub_3d0a() // 01ed:1e3a
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = ah;
    out(dx, al);
    bx = 0x0010;
    push(si);
    push(di);
loc_3d19: // 01ed:1e49
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3d19;
    di = pop();
    si = pop();
    bx = 0x0010;
    push(di);
    di += 0x2000;
    si += 0x0a00;
loc_3d2e: // 01ed:1e5e
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    tx = bx;
    bx--;
    if (tx != 1)
        goto loc_3d2e;
    si -= 0x0a00;
    di = pop();
}
void sub_3d3b() // 01ed:1e6b
{
    bx = 0xa000;
    es = bx;
    di = 0x03e1;
    bx = 0x4d;
    push(bx);
loc_3d48: // 01ed:1e78
    ah = memoryAGet(ds, bx);
    ah += al;
    al = 0;
    if (ah < 0x64)
        goto loc_3d58;
    al++;
    ah -= 0x64;
loc_3d58: // 01ed:1e88
    memoryASet(ds, bx, ah);
    push(ax);
    push(bx);
    sub_3d83();
    bx = pop();
    ax = pop();
    bx++;
    di -= 0x0002;
    if (al)
        goto loc_3d48;
    ax = pop();
    ax++;
    tx = bx;
    bx -= ax;
    if ((short)tx - (short)ax <= 0)
        return;
    memoryASet(ds, 0x0050, memoryAGet(ds, 0x0050) + 1);
    if ((char)memoryAGet(ds, 0x0050) < (char)0x05)
        return;
    memoryASet(ds, 0x0050, 0x00);
    sub_3b27();
}
void sub_3d83() // 01ed:1eb3
{
    goto loc_3d83;
loc_3c7b: // 01ed:1dab
    ah = 0x01;
    sub_3c90();
    ah = 0x02;
    sub_3c90();
    ah = 0x04;
    sub_3c90();
    ah = 0x08;
    sub_3c90();
    return;
    //   gap of 243 bytes
loc_3d83: // 01ed:1eb3
    di++;
    al = 0;
loc_3d86: // 01ed:1eb6
    tl = ah;
    ah -= 0x0a;
    if (tl < 0x0a)
        goto loc_3d8f;
    al++;
    goto loc_3d86;
loc_3d8f: // 01ed:1ebf
    ah += 0x0a;
    push(ax);
    al = ah;
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = 0xffffada4;
    si += ax;
    sub_3c7b();
    di--;
    ax = pop();
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = 0xffffada4;
    si += ax;
    goto loc_3c7b;
}
void sub_3e89() // 01ed:1fb9
{
    goto loc_3e89;
loc_3cb9: // 01ed:1de9
    al = memoryAGet(ds, 0x0045);
    if (al == 0x05)
        goto loc_3cf4;
    al++;
    memoryASet(ds, 0x0045, al);
    bx = 0xa000;
    es = bx;
    di = 0x119d;
    si = 0xffff9ea4;
    ah = 0;
    bx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax += bx;
    si += ax;
    goto loc_3cf5;
loc_3cf4: // 01ed:1e24
    return;
loc_3cf5: // 01ed:1e25
    ah = 0x01;
    sub_3d0a();
    ah = 0x02;
    sub_3d0a();
    ah = 0x04;
    sub_3d0a();
    ah = 0x08;
    sub_3d0a();
    return;
    //   gap of 187 bytes
loc_3dc5: // 01ed:1ef5
    memoryASet(ds, 0x0048, 0x01);
    bx = 0xa000;
    es = bx;
    di = 0x11a0;
    si = 0xffff99a4;
    goto loc_3cf5;
loc_3dd9: // 01ed:1f09
    memoryASet(ds, 0x0049, 0x01);
    bx = 0xa000;
    es = bx;
    di = 0x11a3;
    si = 0xffff9a44;
    goto loc_3cf5;
loc_3ded: // 01ed:1f1d
    memoryASet(ds, 0x0047, 0x05);
    bx = 0xa000;
    es = bx;
    di = 0x155d;
    si = 0xffff9ae4;
    goto loc_3cf5;
loc_3e01: // 01ed:1f31
    memoryASet(ds, 0x004a, 0x01);
    bx = 0xa000;
    es = bx;
    di = 0x1560;
    si = 0xffff9b84;
    goto loc_3cf5;
loc_3e15: // 01ed:1f45
    memoryASet(ds, 0x004b, 0x01);
    bx = 0xa000;
    es = bx;
    di = 0x1563;
    si = 0xffff9c24;
    goto loc_3cf5;
loc_3e29: // 01ed:1f59
    sub_3b27();
    memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
    bx = 0xa000;
    es = bx;
    di = 0x191d;
    si = 0xffff9cc4;
    sub_3cf5();
    if (memoryAGet(ds, 0x004c) == 0x03)
        goto loc_3e65;
    return;
loc_3e47: // 01ed:1f77
    sub_3b27();
    memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
    bx = 0xa000;
    es = bx;
    di = 0x1920;
    si = 0xffff9d64;
    sub_3cf5();
    if (memoryAGet(ds, 0x004c) == 0x03)
        goto loc_3e65;
    return;
loc_3e65: // 01ed:1f95
    memoryASet(ds, 0xca3c, 0x14);
    return;
loc_3e6b: // 01ed:1f9b
    sub_3b27();
    memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
    bx = 0xa000;
    es = bx;
    di = 0x1923;
    si = 0xffff9e04;
    sub_3cf5();
    if (memoryAGet(ds, 0x004c) == 0x03)
        goto loc_3e65;
    return;
loc_3e89: // 01ed:1fb9
    push(ax);
    push(bx);
    bx = ax;
    ax = memoryAGet16(ds, 0x0041);
    bh += al;
    dx = memoryAGet16(ds, 0x003f);
    flags.carry = bh < dh;
    bh -= dh;
    if (!flags.carry)
        goto loc_3e9c;
    bh = -bh;
loc_3e9c: // 01ed:1fcc
    if (bh >= 0x02)
        goto loc_3ead;
    tl = bl;
    bl -= dl;
    if (tl < dl)
        goto loc_3ead;
    if (bl >= 0x04)
        goto loc_3ead;
    goto loc_3ef4;
loc_3ead: // 01ed:1fdd
    bx = pop();
    bh = 0;
    ax = bx;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax += bx;
    si = 0xffff99a4;
    memoryASet(ds, 0xcad0, memoryAGet(ds, 0xcad0) + 1);
    if (memoryAGet(ds, 0xcad0) != 0x02)
        goto loc_3ee4;
    memoryASet(ds, 0xcad0, 0x00);
    si += 0x0a00;
loc_3ee4: // 01ed:2014
    si += ax;
    bp = si;
    bp += 0x0080;
    cx = 0x0010;
    ax = pop();
    sub_28f1();
    return;
loc_3ef4: // 01ed:2024
    bx = 0xffffcae1;
    ax = 0x0001;
    cx = 0x0003;
    al = 0x14;
    sub_3d3b();
    bx = 0x51;
    al = memoryAGet(ds, 0x003e);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al += memoryAGet(ds, 0x003d);
    ah = 0;
    bx += ax;
    memoryASet(ds, bx, 0x01);
    bx = pop();
    ax = pop();
    if (bl != 0x0e)
        goto loc_3f36;
    if (memoryAGet(ds, 0x0044) != 0x06)
        goto loc_3f30;
    sub_3b27();
    return;
loc_3f30: // 01ed:2060
    memoryASet(ds, 0xca3b, 0x06);
    return;
loc_3f36: // 01ed:2066
    if (bx)
        goto loc_3f3d;
    goto loc_3dc5;
loc_3f3d: // 01ed:206d
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f44;
    goto loc_3dd9;
loc_3f44: // 01ed:2074
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f4b;
    goto loc_3ded;
loc_3f4b: // 01ed:207b
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f52;
    goto loc_3e01;
loc_3f52: // 01ed:2082
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f59;
    goto loc_3e15;
loc_3f59: // 01ed:2089
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f60;
    goto loc_3e29;
loc_3f60: // 01ed:2090
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f67;
    goto loc_3e47;
loc_3f67: // 01ed:2097
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_3f6e;
    goto loc_3e6b;
loc_3f6e: // 01ed:209e
    goto loc_3cb9;
}
void sub_3f80() // 01ed:20b0
{
    ax = 0x000d;
    interrupt(0x10);
    flags.direction = false;
    ax = 0x11ca;
    ds = ax;
    ax = 0xa000;
    es = ax;
    si = 0x0;
    ah = 0x01;
    bx = 0x0000;
    sub_2960();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x02;
    bx = 0x0001;
    sub_2960();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x04;
    bx = 0x0002;
    sub_2960();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0x08;
    bx = 0x0003;
    sub_2960();
    cx = 0x0fa0;
    di = 0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ah = 0;
    sub_2960();
    ax = 0x0417;
    ds = ax;
    es = ax;
    goto loc_3fe2;
loc_3fde: // 01ed:210e
    ah = 0x4c;
    interrupt(0x21);
loc_3fe2: // 01ed:2112
    ax = 0x3d00;
    dx = 0xffffcb10;
    interrupt(0x21);
    if (flags.carry)
        goto loc_3fde;
    bx = ax;
    cx = 0x00b4;
    dx = 0xffffcb25;
    ah = 0x3f;
    interrupt(0x21);
    ah = 0x3e;
    interrupt(0x21);
    si = 0xffffcb25;
    cx = 0x000a;
loc_4005: // 01ed:2135
    push(cx);
    push(si);
    si += 0x0010;
    di = 0x4f;
    cx = 0x0003;
loc_4011: // 01ed:2141
    al = memoryAGet(ds, si);
    if ((char)al < (char)memoryAGet(ds, di))
        goto loc_4027;
    if ((char)al > (char)memoryAGet(ds, di))
        goto loc_401d;
    si--;
    di--;
    if (--cx)
        goto loc_4011;
loc_401d: // 01ed:214d
    si = pop();
    si += 0x0012;
    cx = pop();
    if (--cx)
        goto loc_4005;
    goto loc_40d5;
loc_4027: // 01ed:2157
    si = pop();
    cx = pop();
    push(si);
    ax = 0x0012;
    mul(cl);
    cx = ax;
    di = 0xffffcbd9;
    push(si);
    push(di);
    push(cx);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    si = pop();
    di = pop();
    di += 0x0012;
    cx -= 0x0012;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    push(di);
    di += 0x000e;
    si = 0x4d;
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ah = 0x02;
    bh = 0x00;
    dx = 0x0a0e;
    interrupt(0x10);
    bx = 0x0009;
    dx = 0xffffcc9c;
    sub_4159();
    ah = 0x02;
    bh = 0x00;
    dx = 0x0b05;
    interrupt(0x10);
    bx = 0x000a;
    dx = 0xffffcca9;
    sub_4159();
    dx = 0xffffcc8d;
    ah = 0x0a;
    interrupt(0x21);
    cl = memoryAGet(ds, 0xcc8e);
    ch = 0;
    si = 0xffffcc8f;
    di = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    memoryASet(ds, di, 0x24);
    ah = 0x02;
    bh = 0x00;
    dx = 0x0a05;
    interrupt(0x10);
    bx = 0x0001;
    dx = 0xffffccbe;
    sub_4159();
    ah = 0x02;
    bh = 0x00;
    dx = 0x0b05;
    interrupt(0x10);
    bx = 0x0002;
    dx = 0xffffccbe;
    sub_4159();
    ax = 0x3c00;
    cx = 0;
    dx = 0xffffcb10;
    interrupt(0x21);
    if (flags.carry)
        goto loc_40d5;
    bx = ax;
    cx = 0x00b4;
    dx = 0xffffcb25;
    ah = 0x40;
    interrupt(0x21);
    ah = 0x3e;
    interrupt(0x21);
loc_40d5: // 01ed:2205
    cx = 0x000a;
    si = 0xffffcb25;
    dh = 0x07;
loc_40de: // 01ed:220e
    push(cx);
    push(dx);
    dl = 0x08;
    ah = 0x02;
    bh = 0x00;
    interrupt(0x10);
    bx = 0x000b;
    dx = si;
    sub_4159();
    dx = pop();
    push(dx);
    dl = 0x18;
    ah = 0x02;
    bh = 0x00;
    interrupt(0x10);
    bx = si;
    bx += 0x000e;
    sub_4119();
    dx = pop();
    cx = pop();
    dh += 0x01;
    if (cx != 0x000a)
        goto loc_410f;
    dh += 0x01;
loc_410f: // 01ed:223f
    si += 0x0012;
    if (--cx)
        goto loc_40de;
    ax = 0;
    interrupt(0x16);
}
void sub_4119() // 01ed:2249
{
    al = memoryAGet(ds, bx + 2);
    sub_4135();
    al = memoryAGet(ds, bx + 1);
    sub_4135();
    al = memoryAGet(ds, bx);
    sub_4135();
    dx = 0xffffccbb;
    bx = 0x000c;
    sub_4159();
}
void sub_4135() // 01ed:2265
{
    push(bx);
    cl = al;
    al = 0;
loc_413a: // 01ed:226a
    tl = cl;
    cl -= 0x0a;
    if ((char)tl - (char)0x0a < 0)
        goto loc_4143;
    al++;
    goto loc_413a;
loc_4143: // 01ed:2273
    al += 0x30;
    cl += 0x0a;
    push(cx);
    ah = 0x0e;
    bx = 0x000c;
    interrupt(0x10);
    ax = pop();
    al += 0x30;
    ah = 0x0e;
    interrupt(0x10);
    bx = pop();
}
void sub_4159() // 01ed:2289
{
    push(si);
    push(ax);
    si = dx;
    ah = 0x0e;
loc_415f: // 01ed:228f
    lodsb<MemAuto, DirAuto>();
    if (al == 0x24)
        goto loc_4168;
    interrupt(0x10);
    goto loc_415f;
loc_4168: // 01ed:2298
    ax = pop();
    si = pop();
}
