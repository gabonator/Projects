#include "cicoemu.h"
using namespace CicoContext;

void sub_79ed();

void start()
{
    headerSize = 0x08f0;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x0c41;
    sp = 0x364c;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/tuneller/dos", "TUNNELER.EXE", 39552);
    sub_79ed();
}
void sub_1ed0();
void sub_21c4();
void sub_21da();
void sub_21ee();
void sub_2212();
void sub_229e();
void sub_22d4();
void sub_235c();
void sub_23e4();
void sub_243b();
void sub_24c9();
void sub_2502();
void sub_2882();
void sub_28ec();
void sub_2b35();
void sub_2b96();
void sub_2d7a();
void sub_2dee();
void sub_2e2c();
void sub_2ea5();
void sub_2fec();
void sub_30ab();
void sub_3195();
void sub_34cd();
void sub_35ea();
void sub_3734();
void sub_3851();
void sub_3b18();
void sub_3e6c();
void sub_40c4();
void sub_422d();
void sub_42a7();
void sub_4386();
void sub_4504();
void sub_4732();
void sub_4936();
void sub_4bdb();
void sub_54e3();
void sub_563e();
void sub_5f2a();
void sub_64c1();
void sub_6508();
void sub_6a18();
void sub_736f();
void sub_78e5();
void sub_794c();
void sub_79a3();
void sub_79ed();
void sub_7d70();
void sub_7d9c();
void sub_7dfe();
void sub_7ee3();
void sub_7f23();
void sub_7fcc();
void sub_7ff6();
void sub_805a();
void sub_8078();
void sub_8197();
void sub_82c9();
void sub_82fa();
void sub_8350();
void sub_837d();
void sub_8457();
void sub_855c();
void sub_8692();
void sub_86a4();
void sub_86d7();
void sub_8a76();
void sub_8aac();
void sub_8b13();
void sub_8b31();
void sub_8b5a();
void sub_8b69();
void sub_8b8a();
void sub_8b9e();
void sub_8bd0();
void sub_8c00();
void sub_8c40();
void sub_8c6a();
void sub_8d00();
void sub_8d15();
void sub_8d58();
void sub_8d87();
void sub_8db2();
void sub_8e10();
void sub_8e3e();
void sub_8ec9();
void sub_8f2b();
void sub_8f8a();
void sub_8fa0();
void sub_8fc8();
void sub_8fdd();
void sub_901d();
void sub_9070();
void sub_90b4();
void sub_90ce();
void sub_90f9();
void sub_9119();
void sub_9121();
void sub_914e();
void sub_9155();
void sub_9167();
void sub_9189();
void sub_91b4();
void sub_9299();
void sub_92cf();
void sub_92d6();
void sub_932f();
void sub_9350();
void sub_9357();
void sub_935e();
void sub_93fb();
void sub_9463();
void sub_9470();
void sub_962f();
void sub_9660();
void sub_9663();
void sub_971d();
void sub_9730();
void sub_97f7();
void sub_9844();
void sub_99b7();
void sub_99cc();
void sub_9a16();
void sub_9a24();
void sub_9a4f();
void sub_9ac2();
void sub_9b25();
void sub_9b50();
void sub_9c51();
void sub_9c60();
void sub_9c81();
void sub_9cd5();
void sub_9d7d();
void sub_9d81();
void sub_9ed4();
void sub_9f5d();
void sub_9faa();
void sub_9fe9();
void sub_a06b();
void sub_a06f();
void sub_a091();
void sub_a0af();
void sub_a11e();
void sub_a504();
void sub_a552();
void sub_a58a();
void sub_a597();
void sub_a6a9();
void sub_a719();
void sub_a71e();
void sub_a7aa();
void sub_a7b6();
void sub_a7bc();
void sub_a7cd();
void sub_a84b();
void sub_a93e();
void sub_a966();
void sub_a9a3();
void sub_a9ad();
void sub_a9d5();
void sub_aa0b();
void sub_aa15();
void sub_aa62();
void sub_aa7b();
void sub_aabf();
void sub_ab1d();
void sub_aba8();
void sub_abec();
void sub_ac0f();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x8c0006a: sub_8c6a(); return;
        case 0x8e1017a: sub_8f8a(); return;
        case 0x8e103a4: sub_91b4(); return;
        case 0x8e10489: sub_9299(); return;
        case 0x94701bf: sub_962f(); return;
        case 0x94701f0: sub_9660(); return;
        case 0x947135d: sub_a7cd(); return;
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject zero flag in sub_9b25()!
// INJECT: Error: cannot inject zero flag in sub_9f5d()!
// INJECT: Error: cannot inject carry flag in sub_9f5d()!
void sub_1ed0() // 01ed:0000
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0200;
    memoryASet16(ds, 0x12f5, 0x0100);
    al = 0x16;
    push(ax);
    di = 0x12f5;
    push(ds);
    push(di);
    push(cs);
    cs = 0x08d0;
    {static int counter; if (counter++%500 == 0) sync();}
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1307);
    ax &= 0x0040;
    if (ax)
        goto loc_1f39;
    ax = 0;
    memoryASet16(ds, 0x12f5, ax);
    al = 0x16;
    push(ax);
    di = 0x12f5;
    push(ds);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x01ed);
    di = bp - 0x100;
    push(ss);
    push(di);
    al = memoryAGet(ds, 0x12f5);
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9b50(); // 0947:06e0
    assert(cs == 0x01ed);
    di = bp - 0x200;
    push(ss);
    push(di);
    al = memoryAGet(ds, 0x12f6);
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9b50(); // 0947:06e0
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_9ac2(); // 0947:0652
    assert(cs == 0x01ed);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(es);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9a4f(); // 0947:05df
    assert(cs == 0x01ed);
    goto loc_1f4c;
loc_1f39: // 01ed:0069
    di = 0x0068;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(es);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9a4f(); // 0947:05df
    assert(cs == 0x01ed);
loc_1f4c: // 01ed:007c
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_21c4() // 01ed:02f4
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x1311, al);
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_9663(); // 0947:01f3
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_21da() // 01ed:030a
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x08e1;
    sub_901d(); // 08e1:020d
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_21ee() // 01ed:031e
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memoryASet(ss, bp - 17, 0x00);
    memoryASet16(ss, bp - 14, 0x3300);
    memoryASet(ss, bp - 19, 0x02);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2212() // 01ed:0342
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    cx = 0x000c;
    ax <<= cl;
    bx = ax;
    al = memoryAGet(ss, bp + 4);
    ah = 0;
    cx = 0x0008;
    ax <<= cl;
    dx = ax;
    al = memoryAGet(ss, bp + 8);
    ah = 0;
    ax += dx;
    ax += bx;
    memoryASet16(ds, 0x042e, ax);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(ds, 0x0426, ax);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(ds, 0x0428, ax);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ds, 0x042a, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x042c, ax);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(es);
    bx = memoryAGet16(ds, 0x0428);
    bx -= memoryAGet16(ds, 0x0426);
    bx++;
    cx = memoryAGet16(ds, 0x042c);
    cx -= memoryAGet16(ds, 0x042a);
    cx++;
    ax = 0xb800;
    es = ax;
    ax = 0x00a0;
    mul(memoryAGet16(ds, 0x042a));
    ax += memoryAGet16(ds, 0x0426);
    ax += memoryAGet16(ds, 0x0426);
    di = ax;
    ax = memoryAGet16(ds, 0x042e);
loc_2282: // 01ed:03b2
    dx = cx;
    cx = bx;
    push(di);
    rep_stosw<MemVideo, DirForward>();
    di = pop();
    di += 0x00a0;
    cx = dx;
    if (--cx)
        goto loc_2282;
    es = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 14;
}
void sub_229e() // 01ed:03ce
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    ah = 0;
    cx = 0x0008;
    ax <<= cl;
    dx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax += dx;
    bx = ax;
    ax = 0xb800;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    cx = 0x00a0;
    imul(cx);
    ax += memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp + 10);
    di = ax;
    es = pop();
    memoryASet16(es, di, bx);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_22d4() // 01ed:0404
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x0440, ax);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_22f6;
    ax = 0x7530;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ds, 0x043e, ax);
    ax = 0;
    memoryASet16(ds, 0x0442, ax);
    goto loc_2324;
loc_22f6: // 01ed:0426
    di = memoryAGet16(ss, bp + 8);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    ax = di;
    dx = 0;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp + 10);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    dx += bx + flags.carry;
    memoryASet16(ds, 0x043e, ax);
    di = memoryAGet16(ss, bp + 8);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    ax = es;
    memoryASet16(ds, 0x0442, ax);
loc_2324: // 01ed:0454
    push(si);
    push(di);
    push(es);
    push(cx);
    si = memoryAGet16(ds, 0x043e);
    di = 0xb800;
    es = di;
    di = memoryAGet16(ds, 0x0440);
    push(ds);
    cx = memoryAGet16(ds, 0x0442);
    ds = cx ? cx : cs;
    cx = 0x0047;
loc_233f: // 01ed:046f
    push(cx);
    cx = 0x0026;
loc_2343: // 01ed:0473
    movsb<MemVideo, MemData, DirForward>();
    di++;
    if (--cx)
        goto loc_2343;
    cx = pop();
    si += 0x01da;
    di += 0x0054;
    if (--cx)
        goto loc_233f;
    ds = pop();
    cx = pop();
    es = pop();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_235c() // 01ed:048c
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    ax = memoryAGet16(ss, bp + 8);
    ax >>= 1;
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0x0001;
    if (ax != 0x0001)
        goto loc_23b1;
    al = memoryAGet(ss, bp + 4);
    ah = 0;
    cx = 0x0004;
    ax <<= cl;
    dx = ax;
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0x0f;
    ah = 0;
    ax |= dx;
    dl = al;
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, dl);
    goto loc_23de;
loc_23b1: // 01ed:04e1
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0xf0;
    al |= memoryAGet(ss, bp + 4);
    dl = al;
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, dl);
loc_23de: // 01ed:050e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_23e4() // 01ed:0514
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0001;
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0x0001;
    if (ax != 0x0001)
        goto loc_2418;
    ax = memoryAGet16(ss, bp + 6);
    ax >>= 1;
    di = memoryAGet16(ss, bp + 4);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0xf0;
    ah = 0;
    cx = 0x0004;
    ax >>= cl;
    memoryASet(ss, bp - 1, al);
    goto loc_2432;
loc_2418: // 01ed:0548
    ax = memoryAGet16(ss, bp + 6);
    ax >>= 1;
    di = memoryAGet16(ss, bp + 4);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0x0f;
    memoryASet(ss, bp - 1, al);
loc_2432: // 01ed:0562
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_243b() // 01ed:056b
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x0430, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x0432, ax);
    memoryASet16(ds, 0x0434, 0x0007);
    memoryASet16(ds, 0x0436, 0x0007);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x043c, ax);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(es);
    ax = memoryAGet16(ds, 0x0432);
    cl = 0x05;
    ax <<= cl;
    ax += memoryAGet16(ds, 0x0438);
    es = ax;
    dx = memoryAGet16(ds, 0x0430);
    dx += memoryAGet16(ds, 0x043a);
    si = memoryAGet16(ds, 0x043c);
    bx = memoryAGet16(ds, 0x0434);
    cx = memoryAGet16(ds, 0x0436);
loc_2484: // 01ed:05b4
    push(dx);
    push(cx);
    cx = bx;
loc_2488: // 01ed:05b8
    al = memoryAGet(ds, si);
    if (al == 0x10)
        goto loc_24b1;
    di = dx;
    di >>= 1;
    if (!(dx & 0x0001))
        goto loc_24aa;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, di, memoryAGet(es, di) & 0x0f);
    memoryASet(es, di, memoryAGet(es, di) | al);
    goto loc_24b1;
loc_24aa: // 01ed:05da
    memoryASet(es, di, memoryAGet(es, di) & 0xf0);
    memoryASet(es, di, memoryAGet(es, di) | al);
loc_24b1: // 01ed:05e1
    dx++;
    si++;
    if (--cx)
        goto loc_2488;
    cx = pop();
    dx = pop();
    dh += 0x04;
    if (--cx)
        goto loc_2484;
    es = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_24c9() // 01ed:05f9
{
    push(0x7777);
    push(bp);
    bp = sp;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - 0x0003);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - 0x0003);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ss, bp + 4);
    ah = 0;
    dx = 0x0031;
    mul(dx);
    cx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    ax = di + 0xabc;
    push(ax);
    sub_243b(); // 01ed:056b
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_2502() // 01ed:0632
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0029;
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    goto loc_2512;
loc_250f: // 01ed:063f
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_2512: // 01ed:0642
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_251c;
loc_2519: // 01ed:0649
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_251c: // 01ed:064c
    ax = memoryAGet16(ss, bp - 2);
    imul(memoryAGet16(ss, bp - 2));
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    imul(memoryAGet16(ss, bp - 4));
    ax += cx;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(cs);
    cs = 0x0947;
    sub_a06b(); // 0947:0bfb
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_a11e(); // 0947:0cae
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_a06f(); // 0947:0bff
    assert(cs == 0x01ed);
    bl = al;
    ax = memoryAGet16(ss, bp - 2);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000b;
    mul(dx);
    di = ax;
    di += cx;
    memoryASet(ds, di + 4732, bl);
    if (memoryAGet16(ss, bp - 2) != 0x000a)
        goto loc_2519;
    if (memoryAGet16(ss, bp - 4) != 0x000a)
        goto loc_250f;
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_2569;
loc_2566: // 01ed:0696
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_2569: // 01ed:0699
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    goto loc_2573;
loc_2570: // 01ed:06a0
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2573: // 01ed:06a3
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_257d;
loc_257a: // 01ed:06aa
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_257d: // 01ed:06ad
    ax = memoryAGet16(ss, bp - 8);
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    di = ax;
    di += cx;
    al = memoryAGet(ds, di + 49);
    memoryASet(ss, bp - 9, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2748, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 6);
    bx = ax;
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2846, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2944, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    bx = ax;
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 3042, al);
    ax = memoryAGet16(ss, bp - 8);
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    di = ax;
    di += cx;
    al = memoryAGet(ds, di);
    memoryASet(ss, bp - 9, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2797, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2895, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 2993, al);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    ax = 0x0006;
    ax -= memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    memoryASet(ds, di + 3091, al);
    if (memoryAGet16(ss, bp - 6) == 0x0006)
        goto loc_26f8;
    goto loc_257a;
loc_26f8: // 01ed:0828
    if (memoryAGet16(ss, bp - 8) == 0x0006)
        goto loc_2701;
    goto loc_2570;
loc_2701: // 01ed:0831
    if (memoryAGet16(ss, bp - 4) == 0x0002)
        goto loc_270a;
    goto loc_2566;
loc_270a: // 01ed:083a
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    goto loc_2714;
loc_2711: // 01ed:0841
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_2714: // 01ed:0844
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    goto loc_271e;
loc_271b: // 01ed:084b
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_271e: // 01ed:084e
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_2728;
loc_2725: // 01ed:0855
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2728: // 01ed:0858
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0031;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    al = memoryAGet(ds, di + 3532);
    push(ax);
    di = bp - 0x29;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9c51(); // 0947:07e1
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_9cd5(); // 0947:0865
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_278c;
    ax = memoryAGet16(ss, bp - 8);
    bx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0031;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    memoryASet(ds, di + 3532, memoryAGet(ds, di + 3532) + 1);
loc_278c: // 01ed:08bc
    if (memoryAGet16(ss, bp - 6) != 0x0006)
        goto loc_2725;
    if (memoryAGet16(ss, bp - 8) != 0x0006)
        goto loc_271b;
    if (memoryAGet16(ss, bp - 4) == 0x0007)
        goto loc_27a1;
    goto loc_2711;
loc_27a1: // 01ed:08d1
    memoryASet16(ss, bp - 4, 0x0003);
    goto loc_27ab;
loc_27a8: // 01ed:08d8
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_27ab: // 01ed:08db
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_27b5;
loc_27b2: // 01ed:08e2
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_27b5: // 01ed:08e5
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    goto loc_27bf;
loc_27bc: // 01ed:08ec
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_27bf: // 01ed:08ef
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_27c9;
loc_27c6: // 01ed:08f6
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_27c9: // 01ed:08f9
    ax = memoryAGet16(ss, bp - 6);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0007;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0031;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax -= 0x0002;
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    di += ax;
    if (memoryAGet(ds, di + 2748) != 0x10)
        goto loc_282c;
    ax = memoryAGet16(ss, bp - 6);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0007;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0031;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    di += ax;
    memoryASet(ds, di + 2748, 0x10);
    goto loc_285a;
loc_282c: // 01ed:095c
    ax = memoryAGet16(ss, bp - 6);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0007;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0031;
    mul(dx);
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0188;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    ax = pop();
    di += ax;
    memoryASet(ds, di + 2748, 0x00);
loc_285a: // 01ed:098a
    if (memoryAGet16(ss, bp - 6) == 0x0006)
        goto loc_2863;
    goto loc_27c6;
loc_2863: // 01ed:0993
    if (memoryAGet16(ss, bp - 8) == 0x0006)
        goto loc_286c;
    goto loc_27bc;
loc_286c: // 01ed:099c
    if (memoryAGet16(ss, bp - 2) == 0x0007)
        goto loc_2875;
    goto loc_27b2;
loc_2875: // 01ed:09a5
    if (memoryAGet16(ss, bp - 4) == 0x0004)
        goto loc_287e;
    goto loc_27a8;
loc_287e: // 01ed:09ae
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2882() // 01ed:09b2
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_2892;
loc_288f: // 01ed:09bf
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_2892: // 01ed:09c2
    push(cs);
    cs = 0x0947;
    sub_97f7(); // 0947:0387
    assert(cs == 0x01ed);
    if ((short)dx > (short)0x0000)
        goto loc_28a3;
    if ((short)dx < (short)0x0000)
        goto loc_28bb;
    if (ax <= 0x0200)
        goto loc_28bb;
loc_28a3: // 01ed:09d3
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    di <<= 1;
    di += 0x0444;
    push(ds);
    push(di);
    ax = 0x0200;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9730(); // 0947:02c0
    assert(cs == 0x01ed);
    goto loc_28c1;
loc_28bb: // 01ed:09eb
    al = 0x03;
    push(ax);
    sub_21c4(); // 01ed:02f4
loc_28c1: // 01ed:09f1
    if (memoryAGet16(ss, bp - 2) != 0x01ff)
        goto loc_288f;
    di = memoryAGet16(ds, 0x0444);
    es = memoryAGet16(ds, 0x0444 + 2);
    ax = es;
    memoryASet16(ds, 0x0438, ax);
    di = memoryAGet16(ds, 0x0444);
    es = memoryAGet16(ds, 0x0444 + 2);
    ax = di;
    memoryASet16(ds, 0x043a, ax);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_28ec() // 01ed:0a1c
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x0a0e;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    ax = 0;
    memoryASet16(ds, 0x1315, ax);
    ax = 0x0000;
    memoryASet16(ss, bp - 4, ax);
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
loc_2921: // 01ed:0a51
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x20)
        goto loc_2932;
    al = 0x00;
    goto loc_2934;
loc_2932: // 01ed:0a62
    al = 0x01;
loc_2934: // 01ed:0a64
    bl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) <= 0x7a)
        goto loc_2947;
    al = 0x00;
    goto loc_2949;
loc_2947: // 01ed:0a77
    al = 0x01;
loc_2949: // 01ed:0a79
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) >= 0x61)
        goto loc_295c;
    al = 0x00;
    goto loc_295e;
loc_295c: // 01ed:0a8c
    al = 0x01;
loc_295e: // 01ed:0a8e
    al &= dl;
    cl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) <= 0x5a)
        goto loc_2973;
    al = 0x00;
    goto loc_2975;
loc_2973: // 01ed:0aa3
    al = 0x01;
loc_2975: // 01ed:0aa5
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) >= 0x41)
        goto loc_2988;
    al = 0x00;
    goto loc_298a;
loc_2988: // 01ed:0ab8
    al = 0x01;
loc_298a: // 01ed:0aba
    al &= dl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    al = memoryAGet(es, di);
    al &= 0x80;
    if (!al)
        goto loc_29a2;
    al = 0x00;
    goto loc_29a4;
loc_29a2: // 01ed:0ad2
    al = 0x01;
loc_29a4: // 01ed:0ad4
    al &= dl;
    al |= cl;
    al |= bl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x2e)
        goto loc_29bd;
    al = 0x00;
    goto loc_29bf;
loc_29bd: // 01ed:0aed
    al = 0x01;
loc_29bf: // 01ed:0aef
    al |= dl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x2c)
        goto loc_29d4;
    al = 0x00;
    goto loc_29d6;
loc_29d4: // 01ed:0b04
    al = 0x01;
loc_29d6: // 01ed:0b06
    al |= dl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x21)
        goto loc_29eb;
    al = 0x00;
    goto loc_29ed;
loc_29eb: // 01ed:0b1b
    al = 0x01;
loc_29ed: // 01ed:0b1d
    al |= dl;
    if (!al)
        goto loc_29f8;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    goto loc_29fd;
loc_29f8: // 01ed:0b28
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
loc_29fd: // 01ed:0b2d
    if (memoryAGet16(ss, bp - 6) > 0x0006)
        goto loc_2a06;
    goto loc_2afa;
loc_2a06: // 01ed:0b36
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x1315, memoryAGet16(ds, 0x1315) + ax);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 0x0006);
loc_2a11: // 01ed:0b41
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x20)
        goto loc_2a22;
    al = 0x00;
    goto loc_2a24;
loc_2a22: // 01ed:0b52
    al = 0x01;
loc_2a24: // 01ed:0b54
    bl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) <= 0x7a)
        goto loc_2a37;
    al = 0x00;
    goto loc_2a39;
loc_2a37: // 01ed:0b67
    al = 0x01;
loc_2a39: // 01ed:0b69
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) >= 0x61)
        goto loc_2a4c;
    al = 0x00;
    goto loc_2a4e;
loc_2a4c: // 01ed:0b7c
    al = 0x01;
loc_2a4e: // 01ed:0b7e
    al &= dl;
    cl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) <= 0x5a)
        goto loc_2a63;
    al = 0x00;
    goto loc_2a65;
loc_2a63: // 01ed:0b93
    al = 0x01;
loc_2a65: // 01ed:0b95
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) >= 0x41)
        goto loc_2a78;
    al = 0x00;
    goto loc_2a7a;
loc_2a78: // 01ed:0ba8
    al = 0x01;
loc_2a7a: // 01ed:0baa
    al &= dl;
    al |= cl;
    al |= bl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x2e)
        goto loc_2a93;
    al = 0x00;
    goto loc_2a95;
loc_2a93: // 01ed:0bc3
    al = 0x01;
loc_2a95: // 01ed:0bc5
    al |= dl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x2c)
        goto loc_2aaa;
    al = 0x00;
    goto loc_2aac;
loc_2aaa: // 01ed:0bda
    al = 0x01;
loc_2aac: // 01ed:0bdc
    al |= dl;
    dl = al;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    if (memoryAGet(es, di) == 0x21)
        goto loc_2ac1;
    al = 0x00;
    goto loc_2ac3;
loc_2ac1: // 01ed:0bf1
    al = 0x01;
loc_2ac3: // 01ed:0bf3
    al |= dl;
    if (!al)
        goto loc_2af5;
    ax = 0x0000;
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax -= dx;
    cx = 0x0003;
    ax >>= cl;
    ax &= 0x000c;
    dx = ax;
    ax = cs;
    push(ax);
    di = memoryAGet16(ss, bp - 4);
    es = pop();
    al = memoryAGet(es, di);
    ah = 0;
    ax ^= dx;
    memoryASet16(ds, 0x1315, memoryAGet16(ds, 0x1315) + ax);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    goto loc_2a11;
loc_2af5: // 01ed:0c25
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
loc_2afa: // 01ed:0c2a
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    ax = memoryAGet16(ds, 0x1317);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = ax;
    bx = dx;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0;
    if ((short)dx > (short)bx)
        goto loc_2b1a;
    if ((short)dx >= (short)bx)
        goto loc_2b13;
    goto loc_2921;
loc_2b13: // 01ed:0c43
    if (ax > cx)
        goto loc_2b1a;
    goto loc_2921;
loc_2b1a: // 01ed:0c4a
    if (memoryAGet16(ds, 0x1315) != 0x27a2)
        goto loc_2b29;
    memoryASet(ds, 0x1319, 0x01);
    goto loc_2b2e;
loc_2b29: // 01ed:0c59
    memoryASet(ds, 0x1319, 0x00);
loc_2b2e: // 01ed:0c5e
    sub_21da(); // 01ed:030a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2b35() // 01ed:0c65
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    if ((short)memoryAGet16(ss, bp + 6) <= (short)0x000a)
        goto loc_2b45;
    al = 0x00;
    goto loc_2b47;
loc_2b45: // 01ed:0c75
    al = 0x01;
loc_2b47: // 01ed:0c77
    dl = al;
    if ((short)memoryAGet16(ss, bp + 8) <= (short)0x000a)
        goto loc_2b53;
    al = 0x00;
    goto loc_2b55;
loc_2b53: // 01ed:0c83
    al = 0x01;
loc_2b55: // 01ed:0c85
    al &= dl;
    if (!al)
        goto loc_2b77;
    ax = memoryAGet16(ss, bp + 6);
    cx = ax;
    ax = memoryAGet16(ss, bp + 8);
    dx = 0x000b;
    mul(dx);
    di = ax;
    di += cx;
    al = memoryAGet(ds, di + 4732);
    ah = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_2b8d;
loc_2b77: // 01ed:0ca7
    ax = memoryAGet16(ss, bp + 8);
    if ((short)ax <= (short)memoryAGet16(ss, bp + 6))
        goto loc_2b87;
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 2, ax);
    goto loc_2b8d;
loc_2b87: // 01ed:0cb7
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 2, ax);
loc_2b8d: // 01ed:0cbd
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_2b96() // 01ed:0cc6
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    al = memoryAGet(ss, bp + 6);
    if (al != 0x00)
        goto loc_2bde;
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_2bad;
loc_2baa: // 01ed:0cda
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2bad: // 01ed:0cdd
    ax = memoryAGet16(ss, bp - 8);
    cx = 0x0014;
    imul(cx);
    ax += 0x0032;
    dx = ax;
    ax = memoryAGet16(ss, bp - 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    ax += memoryAGet16(ss, di + 55635);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, dx);
    if (memoryAGet16(ss, bp - 8) != 0x0004)
        goto loc_2baa;
    goto loc_2d74;
loc_2bde: // 01ed:0d0e
    if (al != 0x05)
        goto loc_2c30;
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_2bec;
loc_2be9: // 01ed:0d19
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2bec: // 01ed:0d1c
    ax = memoryAGet16(ss, bp - 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    ax += memoryAGet16(ss, di + 55635);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x0028);
    ax = memoryAGet16(ss, bp - 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    ax += memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x002d);
    if (memoryAGet16(ss, bp - 8) != 0x0003)
        goto loc_2be9;
    goto loc_2d74;
loc_2c30: // 01ed:0d60
    if (al != 0x04)
        goto loc_2c50;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x1388);
    goto loc_2d74;
loc_2c50: // 01ed:0d80
    if (al != 0x01)
        goto loc_2c70;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x0028);
    goto loc_2d74;
loc_2c70: // 01ed:0da0
    if (al != 0x02)
        goto loc_2cef;
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_2c7e;
loc_2c7b: // 01ed:0dab
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2c7e: // 01ed:0dae
    memoryASet16(ss, bp - 4, 0x0100);
    ax = 0x0350;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_2c99;
loc_2c96: // 01ed:0dc6
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2c99: // 01ed:0dc9
    ax = memoryAGet16(ss, bp - 6);
    cx = 0x000f;
    imul(cx);
    ax += 0x0028;
    dx = ax;
    al = memoryAGet(ss, bp - 3);
    ah = 0;
    di = memoryAGet16(ss, bp + 4);
    ax += memoryAGet16(ss, di + 55635);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, dx);
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + ax);
    if (memoryAGet16(ss, bp - 6) != 0x0007)
        goto loc_2c96;
    if (memoryAGet16(ss, bp - 8) != 0x0004)
        goto loc_2c7b;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x03e8);
    goto loc_2d74;
loc_2cef: // 01ed:0e1f
    if (al == 0x03)
        goto loc_2cf6;
    goto loc_2d74;
loc_2cf6: // 01ed:0e26
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_2d00;
loc_2cfd: // 01ed:0e2d
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2d00: // 01ed:0e30
    memoryASet16(ss, bp - 4, 0x0100);
    ax = 0x0400;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_2d1b;
loc_2d18: // 01ed:0e48
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2d1b: // 01ed:0e4b
    ax = memoryAGet16(ss, bp - 2);
    cx = 0x0007;
    ax >>= cl;
    imul(memoryAGet16(ss, bp - 6));
    ax += 0x0028;
    dx = ax;
    al = memoryAGet(ss, bp - 3);
    ah = 0;
    di = memoryAGet16(ss, bp + 4);
    ax += memoryAGet16(ss, di + 55635);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, dx);
    ax = memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet16(ss, bp - 6) != 0x0016)
        goto loc_2d18;
    if (memoryAGet16(ss, bp - 8) != 0x0028)
        goto loc_2cfd;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55123, 0x03e8);
loc_2d74: // 01ed:0ea4
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_2d7a() // 01ed:0eaa
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = 0;
    memoryASet16(ss, di + 55123, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax++;
    ah = 0;
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55635, ax);
    di = memoryAGet16(ss, bp + 4);
    if (memoryAGet(ss, di + 55074) == 0x00)
        goto loc_2de8;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    if (memoryAGet16(ss, di + 55123) == 0x0000)
        goto loc_2de3;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55635);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    push(memoryAGet16(ss, di + 55123));
    push(cs);
    cs = 0x08e1;
    sub_9121(); // 08e1:0311
    assert(cs == 0x01ed);
    goto loc_2de8;
loc_2de3: // 01ed:0f13
    push(cs);
    cs = 0x08e1;
    sub_914e(); // 08e1:033e
    assert(cs == 0x01ed);
loc_2de8: // 01ed:0f18
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_2dee() // 01ed:0f1e
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0001;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    sub_23e4(); // 01ed:0514
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0;
    di = ax;
    al = memoryAGet(ds, di + 163);
    di = memoryAGet16(ss, bp + 4);
    if ((char)al <= (char)memoryAGet(ss, di + 65534))
        goto loc_2e26;
    al = memoryAGet(ss, bp - 1);
    ah = 0;
    di = ax;
    al = memoryAGet(ds, di + 163);
    di = memoryAGet16(ss, bp + 4);
    memoryASet(ss, di + 65534, al);
loc_2e26: // 01ed:0f56
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_2e2c() // 01ed:0f5c
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    memoryASet(ss, bp - 2, 0x00);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - 0x0003);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - 0x0003);
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_2e48;
loc_2e45: // 01ed:0f75
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2e48: // 01ed:0f78
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    goto loc_2e52;
loc_2e4f: // 01ed:0f7f
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_2e52: // 01ed:0f82
    ax = memoryAGet16(ss, bp - 6);
    bx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0007;
    mul(dx);
    cx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    dx = 0x0031;
    mul(dx);
    di = ax;
    di += cx;
    di += bx;
    if (memoryAGet(ds, di + 3140) == 0x10)
        goto loc_2e8a;
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    push(bp);
    sub_2dee(); // 01ed:0f1e
loc_2e8a: // 01ed:0fba
    if (memoryAGet16(ss, bp - 4) != 0x0006)
        goto loc_2e4f;
    if (memoryAGet16(ss, bp - 6) != 0x0006)
        goto loc_2e45;
    al = memoryAGet(ss, bp - 2);
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_2ea5() // 01ed:0fd5
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    memoryASet16(ss, bp - 2, 0x0001);
loc_2eb0: // 01ed:0fe0
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0147;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dl = memoryAGet(ss, di + 55397);
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 4);
    if ((short)ax <= (short)memoryAGet16(ss, di + 65534))
        goto loc_2ed2;
    al = 0x00;
    goto loc_2ed4;
loc_2ed2: // 01ed:1002
    al = 0x01;
loc_2ed4: // 01ed:1004
    al &= dl;
    if (!al)
        goto loc_2edf;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
    goto loc_2eb0;
loc_2edf: // 01ed:100f
    ax = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp + 4);
    if ((short)ax < (short)memoryAGet16(ss, di + 65534))
        goto loc_2efc;
    di = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ss, di + 65534) >= (short)0x001e)
        goto loc_2efc;
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 65534, memoryAGet16(ss, di + 65534) + 1);
loc_2efc: // 01ed:102c
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x001e)
        goto loc_2f05;
    goto loc_2fe6;
loc_2f05: // 01ed:1035
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0147;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += 0xd865;
    memoryASet16(ss, bp - 8, di);
    memoryASet16(ss, bp - 6, ss);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet(es, di, 0x01);
    ax = memoryAGet16(ss, bp + 6);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, di + 1, ax);
    ax = memoryAGet16(ss, bp + 8);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, di + 3, ax);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    ax = 0;
    memoryASet16(es, di + 5, ax);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, di + 1);
    memoryASet16(ss, bp - 10, ax);
    ax = 0x0001;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 10))
        goto loc_2f55;
    goto loc_2fe6;
loc_2f55: // 01ed:1085
    memoryASet16(ss, bp - 4, ax);
    goto loc_2f5d;
loc_2f5a: // 01ed:108a
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_2f5d: // 01ed:108d
    ax = memoryAGet16(ss, bp + 12);
    cx = 0x0005;
    ax <<= cl;
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    di += ax;
    memoryASet16(es, di + 5, dx);
    ax = memoryAGet16(ss, bp + 10);
    cx = 0x0005;
    ax <<= cl;
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    di += ax;
    memoryASet16(es, di + 85, dx);
    ax = 0x0020;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    push(ax);
    ax = 0x0020;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    dx = pop();
    ax -= dx;
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    di += ax;
    memoryASet16(es, di + 165, dx);
    ax = 0x0020;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    push(ax);
    ax = 0x0020;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    dx = pop();
    ax -= dx;
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    di += ax;
    memoryASet16(es, di + 245, dx);
    ax = memoryAGet16(ss, bp - 4);
    if (ax == memoryAGet16(ss, bp - 10))
        goto loc_2fe6;
    goto loc_2f5a;
loc_2fe6: // 01ed:1116
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_2fec() // 01ed:111c
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ss, di + 55077) < (short)0x0000)
        goto loc_2ffd;
    goto loc_30a5;
loc_2ffd: // 01ed:112d
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    push(memoryAGet16(ss, di + 55710));
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    push(memoryAGet16(ss, di + 55714));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55091);
    ax += 0x0002;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    al = memoryAGet(ss, di + 55718);
    push(ax);
    sub_24c9(); // 01ed:05f9
    al = 0x03;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b96(); // 01ed:0cc6
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0x0018;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0x0014;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0x0010;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0x000c;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55077, 0x0019);
    di = memoryAGet16(ss, bp + 10);
    memoryASet(ds, di + 4729, 0x00);
loc_30a5: // 01ed:11d5
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_30ab() // 01ed:11db
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = memoryAGet16(ss, bp + 8);
    ax >>= 1;
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0x0001;
    if (ax != 0x0001)
        goto loc_312b;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0xf0;
    ah = 0;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ss, bp - 2) == 0x0080)
        goto loc_30e9;
    al = 0x00;
    goto loc_30eb;
loc_30e9: // 01ed:1219
    al = 0x01;
loc_30eb: // 01ed:121b
    dl = al;
    if (memoryAGet16(ss, bp - 2) == 0x0060)
        goto loc_30f7;
    al = 0x00;
    goto loc_30f9;
loc_30f7: // 01ed:1227
    al = 0x01;
loc_30f9: // 01ed:1229
    al |= dl;
    if (!al)
        goto loc_3129;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0x0f;
    dl = al;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, dl);
loc_3129: // 01ed:1259
    goto loc_318f;
loc_312b: // 01ed:125b
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0x0f;
    ah = 0;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ss, bp - 2) == 0x0008)
        goto loc_314f;
    al = 0x00;
    goto loc_3151;
loc_314f: // 01ed:127f
    al = 0x01;
loc_3151: // 01ed:1281
    dl = al;
    if (memoryAGet16(ss, bp - 2) == 0x0006)
        goto loc_315d;
    al = 0x00;
    goto loc_315f;
loc_315d: // 01ed:128d
    al = 0x01;
loc_315f: // 01ed:128f
    al |= dl;
    if (!al)
        goto loc_318f;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    al = memoryAGet(es, di);
    al &= 0xf0;
    dl = al;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, dl);
loc_318f: // 01ed:12bf
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_3195() // 01ed:12c5
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0x0001;
    if (ax == 0x0001)
        goto loc_31a9;
    goto loc_3266;
loc_31a9: // 01ed:12d9
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0002;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0002;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_31ea;
    memoryASet16(ss, bp - 2, ax);
    goto loc_31cf;
loc_31cc: // 01ed:12fc
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_31cf: // 01ed:12ff
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0003;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_31cc;
loc_31ea: // 01ed:131a
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0003;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0003;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_322b;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3210;
loc_320d: // 01ed:133d
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3210: // 01ed:1340
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0002;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_320d;
loc_322b: // 01ed:135b
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax++;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax--;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_3266;
    memoryASet16(ss, bp - 2, ax);
    goto loc_324d;
loc_324a: // 01ed:137a
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_324d: // 01ed:137d
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax--;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_324a;
loc_3266: // 01ed:1396
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0x0004;
    if (ax == 0x0004)
        goto loc_3274;
    goto loc_3331;
loc_3274: // 01ed:13a4
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0002;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0002;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_32b5;
    memoryASet16(ss, bp - 2, ax);
    goto loc_329a;
loc_3297: // 01ed:13c7
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_329a: // 01ed:13ca
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0003;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_3297;
loc_32b5: // 01ed:13e5
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0003;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0003;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_32f6;
    memoryASet16(ss, bp - 2, ax);
    goto loc_32db;
loc_32d8: // 01ed:1408
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_32db: // 01ed:140b
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0002;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_32d8;
loc_32f6: // 01ed:1426
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax++;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax--;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_3331;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3318;
loc_3315: // 01ed:1445
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3318: // 01ed:1448
    push(memoryAGet16(ss, bp - 2));
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax++;
    push(ax);
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_3315;
loc_3331: // 01ed:1461
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0x0002;
    if (ax == 0x0002)
        goto loc_333f;
    goto loc_33fc;
loc_333f: // 01ed:146f
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0002;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0002;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_3380;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3365;
loc_3362: // 01ed:1492
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3365: // 01ed:1495
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0003;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_3362;
loc_3380: // 01ed:14b0
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0003;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0003;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_33c1;
    memoryASet16(ss, bp - 2, ax);
    goto loc_33a6;
loc_33a3: // 01ed:14d3
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_33a6: // 01ed:14d6
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax += 0x0002;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_33a3;
loc_33c1: // 01ed:14f1
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax++;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax--;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_33fc;
    memoryASet16(ss, bp - 2, ax);
    goto loc_33e3;
loc_33e0: // 01ed:1510
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_33e3: // 01ed:1513
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_33e0;
loc_33fc: // 01ed:152c
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0x0008;
    if (ax == 0x0008)
        goto loc_340a;
    goto loc_34c7;
loc_340a: // 01ed:153a
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0002;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0002;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_344b;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3430;
loc_342d: // 01ed:155d
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3430: // 01ed:1560
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0003;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_342d;
loc_344b: // 01ed:157b
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax += 0x0003;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax -= 0x0003;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_348c;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3471;
loc_346e: // 01ed:159e
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3471: // 01ed:15a1
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax -= 0x0002;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_346e;
loc_348c: // 01ed:15bc
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax++;
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55087);
    ax--;
    if ((short)ax > (short)memoryAGet16(ss, bp - 4))
        goto loc_34c7;
    memoryASet16(ss, bp - 2, ax);
    goto loc_34ae;
loc_34ab: // 01ed:15db
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_34ae: // 01ed:15de
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55085);
    ax--;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(bp);
    sub_30ab(); // 01ed:11db
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 4))
        goto loc_34ab;
loc_34c7: // 01ed:15f7
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_34cd() // 01ed:15fd
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_34dd;
loc_34da: // 01ed:160a
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_34dd: // 01ed:160d
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_34e7;
loc_34e4: // 01ed:1614
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_34e7: // 01ed:1617
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    if (memoryAGet16(ss, di + 55635) != 0xffff)
        goto loc_3508;
    goto loc_35d2;
loc_3508: // 01ed:1638
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    push(memoryAGet16(ss, di + 55635));
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    push(memoryAGet16(ss, di + 55659));
    al = 0x00;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 2);
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    bx = memoryAGet16(ds, di + 107);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55635);
    ax -= bx;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    bx = memoryAGet16(ds, di + 123);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55659);
    ax -= bx;
    push(ax);
    al = 0x00;
    push(ax);
    sub_235c(); // 01ed:048c
loc_35d2: // 01ed:1702
    if (memoryAGet16(ss, bp - 2) == 0x0006)
        goto loc_35db;
    goto loc_34e4;
loc_35db: // 01ed:170b
    if (memoryAGet16(ss, bp - 4) == 0x0002)
        goto loc_35e4;
    goto loc_34da;
loc_35e4: // 01ed:1714
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_35ea() // 01ed:171a
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    if ((short)memoryAGet16(ss, di + 55115) <= (short)0x0000)
        goto loc_3618;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55115, memoryAGet16(ss, di + 55115) - 1);
    goto loc_372e;
loc_3618: // 01ed:1748
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    di = ax;
    di <<= 1;
    memoryASet16(ds, di + 4712, memoryAGet16(ds, di + 4712) + 1);
    memoryASet16(ss, bp - 2, 0x0001);
loc_362a: // 01ed:175a
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x0006)
        goto loc_3634;
    al = 0x00;
    goto loc_3636;
loc_3634: // 01ed:1764
    al = 0x01;
loc_3636: // 01ed:1766
    bl = al;
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    if (memoryAGet16(ss, di + 55635) != 0xffff)
        goto loc_365c;
    al = 0x00;
    goto loc_365e;
loc_365c: // 01ed:178c
    al = 0x01;
loc_365e: // 01ed:178e
    al &= bl;
    if (!al)
        goto loc_3669;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
    goto loc_362a;
loc_3669: // 01ed:1799
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x0006)
        goto loc_3672;
    goto loc_371b;
loc_3672: // 01ed:17a2
    al = 0x04;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b96(); // 01ed:0cc6
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    bx = memoryAGet16(ss, di + 55710);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    memoryASet16(ss, di + 55635, bx);
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    bx = memoryAGet16(ss, di + 55714);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    memoryASet16(ss, di + 55659, bx);
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    cl = memoryAGet(ss, di + 55718);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    memoryASet(ss, di + 55630, cl);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55081);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55107, memoryAGet16(ss, di + 55107) - 0x003c);
loc_371b: // 01ed:184b
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55115, 0x0001);
loc_372e: // 01ed:185e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_3734() // 01ed:1864
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_3744;
loc_3741: // 01ed:1871
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_3744: // 01ed:1874
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_374e;
loc_374b: // 01ed:187b
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_374e: // 01ed:187e
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    if (memoryAGet16(ss, di + 55635) != 0xffff)
        goto loc_376f;
    goto loc_3839;
loc_376f: // 01ed:189f
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    push(memoryAGet16(ss, di + 55635));
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    push(memoryAGet16(ss, di + 55659));
    al = 0x0c;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 2);
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    bx = memoryAGet16(ds, di + 107);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55635);
    ax -= bx;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = ax;
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    bx = memoryAGet16(ds, di + 123);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55659);
    ax -= bx;
    push(ax);
    al = 0x04;
    push(ax);
    sub_235c(); // 01ed:048c
loc_3839: // 01ed:1969
    if (memoryAGet16(ss, bp - 2) == 0x0006)
        goto loc_3842;
    goto loc_374b;
loc_3842: // 01ed:1972
    if (memoryAGet16(ss, bp - 4) == 0x0002)
        goto loc_384b;
    goto loc_3741;
loc_384b: // 01ed:197b
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_3851() // 01ed:1981
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000f;
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_3861;
loc_385e: // 01ed:198e
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_3861: // 01ed:1991
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_386b;
loc_3868: // 01ed:1998
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_386b: // 01ed:199b
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    if (memoryAGet16(ss, di + 55635) != 0xffff)
        goto loc_388c;
    goto loc_3b00;
loc_388c: // 01ed:19bc
    ax = memoryAGet16(ss, bp - 4);
    dx = ax;
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 107);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 4);
    dx = ax;
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax += si;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += dx;
    al = memoryAGet(ss, di + 55630);
    ah = 0;
    di = ax;
    di <<= 1;
    ax = memoryAGet16(ds, di + 123);
    memoryASet16(ss, bp - 12, ax);
    memoryASet16(ss, bp - 2, 0x0001);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55635);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    ax = memoryAGet16(ss, di + 55659);
    memoryASet16(ss, bp - 8, ax);
loc_391f: // 01ed:1a4f
    ax = memoryAGet16(ss, bp - 10);
    ax += memoryAGet16(ss, bp - 14);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(ss, bp - 12);
    memoryASet16(ss, bp - 8, ax);
    push(memoryAGet16(ss, bp - 10));
    push(memoryAGet16(ss, bp - 8));
    sub_23e4(); // 01ed:0514
    memoryASet(ss, bp - 15, al);
    if (memoryAGet(ss, bp - 15) != 0x0c)
        goto loc_3947;
    al = 0x00;
    goto loc_3949;
loc_3947: // 01ed:1a77
    al = 0x01;
loc_3949: // 01ed:1a79
    dl = al;
    if (memoryAGet(ss, bp - 15) != 0x00)
        goto loc_3955;
    al = 0x00;
    goto loc_3957;
loc_3955: // 01ed:1a85
    al = 0x01;
loc_3957: // 01ed:1a87
    al &= dl;
    if (al)
        goto loc_3960;
    goto loc_3a9e;
loc_3960: // 01ed:1a90
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55710);
    ax = memoryAGet16(ss, bp - 10);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_397a;
    ax = -ax;
loc_397a: // 01ed:1aaa
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55714);
    ax = memoryAGet16(ss, bp - 8);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_3995;
    ax = -ax;
loc_3995: // 01ed:1ac5
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b35(); // 01ed:0c65
    if ((short)ax > (short)0x0003)
        goto loc_39a4;
    goto loc_3a9e;
loc_39a4: // 01ed:1ad4
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55710);
    ax = memoryAGet16(ss, bp - 10);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_39c1;
    ax = -ax;
loc_39c1: // 01ed:1af1
    push(ax);
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55714);
    ax = memoryAGet16(ss, bp - 8);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_39df;
    ax = -ax;
loc_39df: // 01ed:1b0f
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b35(); // 01ed:0c65
    if ((short)ax < (short)0x0004)
        goto loc_39ee;
    goto loc_3a74;
loc_39ee: // 01ed:1b1e
    di = memoryAGet16(ss, bp - 6);
    di <<= 1;
    memoryASet16(ds, di + 4716, memoryAGet16(ds, di + 4716) + 1);
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55099, memoryAGet16(ss, di + 55099) - 0x0700);
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55079, 0x0002);
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    if ((short)memoryAGet16(ss, di + 55099) <= (short)0x0000)
        goto loc_3a51;
    ax = memoryAGet16(ss, bp - 10);
    ax -= memoryAGet16(ss, bp - 14);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    ax -= memoryAGet16(ss, bp - 12);
    push(ax);
    ax = 0x0007;
    push(ax);
    ax = 0x0014;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    al = 0x02;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b96(); // 01ed:0cc6
    goto loc_3a72;
loc_3a51: // 01ed:1b81
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp - 6);
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    ax += memoryAGet16(ss, bp - 14);
    ax += memoryAGet16(ss, bp - 14);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(ss, bp - 14);
    ax += memoryAGet16(ss, bp - 14);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2fec(); // 01ed:111c
loc_3a72: // 01ed:1ba2
    goto loc_3a99;
loc_3a74: // 01ed:1ba4
    ax = memoryAGet16(ss, bp - 10);
    ax -= memoryAGet16(ss, bp - 14);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    ax -= memoryAGet16(ss, bp - 12);
    push(ax);
    ax = 0x0003;
    push(ax);
    ax = 0x0007;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2ea5(); // 01ed:0fd5
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b96(); // 01ed:0cc6
loc_3a99: // 01ed:1bc9
    memoryASet16(ss, bp - 10, 0xffff);
loc_3a9e: // 01ed:1bce
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
    if (memoryAGet16(ss, bp - 10) == 0xffff)
        goto loc_3aab;
    al = 0x00;
    goto loc_3aad;
loc_3aab: // 01ed:1bdb
    al = 0x01;
loc_3aad: // 01ed:1bdd
    dl = al;
    if ((short)memoryAGet16(ss, bp - 2) > (short)0x0004)
        goto loc_3ab9;
    al = 0x00;
    goto loc_3abb;
loc_3ab9: // 01ed:1be9
    al = 0x01;
loc_3abb: // 01ed:1beb
    al |= dl;
    if (al)
        goto loc_3ac4;
    goto loc_391f;
loc_3ac4: // 01ed:1bf4
    bx = memoryAGet16(ss, bp - 10);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    memoryASet16(ss, di + 55635, bx);
    bx = memoryAGet16(ss, bp - 8);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    memoryASet16(ss, di + 55659, bx);
loc_3b00: // 01ed:1c30
    if (memoryAGet16(ss, bp - 4) == 0x0006)
        goto loc_3b09;
    goto loc_3868;
loc_3b09: // 01ed:1c39
    if (memoryAGet16(ss, bp - 6) == 0x0002)
        goto loc_3b12;
    goto loc_385e;
loc_3b12: // 01ed:1c42
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_3b18() // 01ed:1c48
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    if (memoryAGet16(ds, 0x1332) == 0x0009)
        goto loc_3b29;
    al = 0x00;
    goto loc_3b2b;
loc_3b29: // 01ed:1c59
    al = 0x01;
loc_3b2b: // 01ed:1c5b
    dl = al;
    if (memoryAGet16(ds, 0x1332) == 0x0002)
        goto loc_3b38;
    al = 0x00;
    goto loc_3b3a;
loc_3b38: // 01ed:1c68
    al = 0x01;
loc_3b3a: // 01ed:1c6a
    al |= dl;
    if (!al)
        goto loc_3b47;
    memoryASet16(ss, bp - 2, 0x000d);
    goto loc_3b4c;
loc_3b47: // 01ed:1c77
    memoryASet16(ss, bp - 2, 0x0008);
loc_3b4c: // 01ed:1c7c
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x004f;
    push(ax);
    ax = 0x0063;
    push(ax);
    al = 0xb0;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x01;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0026;
    push(ax);
    ax = 0x0048;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x00;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0x0029;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x004e;
    push(ax);
    ax = 0x0048;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x00;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0;
    memoryASet16(ss, bp - 4, ax);
    ax = 0;
    memoryASet16(ss, bp - 10, ax);
    goto loc_3bad;
loc_3baa: // 01ed:1cda
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_3bad: // 01ed:1cdd
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0003;
    push(ax);
    ax = 0x004a;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0024;
    push(ax);
    ax = 0x0062;
    push(ax);
    al = 0xdd;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0003;
    push(ax);
    ax = 0x004a;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0024;
    push(ax);
    ax = 0x004a;
    push(ax);
    al = 0xb0;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = 0x07;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0003;
    push(ax);
    ax = 0x0062;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0024;
    push(ax);
    ax = 0x0062;
    push(ax);
    al = 0xb1;
    push(ax);
    al = 0x00;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_2212(); // 01ed:0342
    memoryASet16(ss, bp - 8, 0x004b);
    goto loc_3c21;
loc_3c1e: // 01ed:1d4e
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_3c21: // 01ed:1d51
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0003;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb0;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    cx = 0x0004;
    ax <<= cl;
    ax += 0x0007;
    push(ax);
    sub_229e(); // 01ed:03ce
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0024;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb1;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_229e(); // 01ed:03ce
    if (memoryAGet16(ss, bp - 8) != 0x0061)
        goto loc_3c1e;
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000c;
    push(ax);
    ax = 0x004f;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0020;
    push(ax);
    ax = 0x0052;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x00;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000c;
    push(ax);
    ax = 0x005a;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0020;
    push(ax);
    ax = 0x005d;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x00;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    ax = 0x004d;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    ax = 0x004d;
    push(ax);
    al = 0xb0;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = 0x07;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    ax = 0x0058;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    ax = 0x0058;
    push(ax);
    al = 0xb0;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = 0x07;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    ax = 0x0054;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    ax = 0x0054;
    push(ax);
    al = 0xb1;
    push(ax);
    al = 0x00;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_2212(); // 01ed:0342
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    ax = 0x005f;
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    ax = 0x005f;
    push(ax);
    al = 0xb1;
    push(ax);
    al = 0x00;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_2212(); // 01ed:0342
    memoryASet16(ss, bp - 8, 0x004e);
    goto loc_3d31;
loc_3d2e: // 01ed:1e5e
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_3d31: // 01ed:1e61
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb0;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    cx = 0x0004;
    ax <<= cl;
    ax += 0x0007;
    push(ax);
    sub_229e(); // 01ed:03ce
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb1;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_229e(); // 01ed:03ce
    if (memoryAGet16(ss, bp - 8) != 0x0053)
        goto loc_3d2e;
    memoryASet16(ss, bp - 8, 0x0059);
    goto loc_3d71;
loc_3d6e: // 01ed:1e9e
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_3d71: // 01ed:1ea1
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0009;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb0;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    cx = 0x0004;
    ax <<= cl;
    ax += 0x0007;
    push(ax);
    sub_229e(); // 01ed:03ce
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0022;
    push(ax);
    push(memoryAGet16(ss, bp - 8));
    al = 0xb1;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_229e(); // 01ed:03ce
    if (memoryAGet16(ss, bp - 8) != 0x005e)
        goto loc_3d6e;
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_3db1;
loc_3dae: // 01ed:1ede
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_3db1: // 01ed:1ee1
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    goto loc_3dbb;
loc_3db8: // 01ed:1ee8
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_3dbb: // 01ed:1eeb
    ax = memoryAGet16(ss, bp - 8);
    ax += 0x000a;
    ax += memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x004f;
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    ax += 0x000a;
    ax += memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x005a;
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 8) != 0x0005)
        goto loc_3db8;
    if (memoryAGet16(ss, bp - 6) != 0x0002)
        goto loc_3dae;
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    al = 0x5b;
    push(ax);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000a;
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    al = 0x52;
    push(ax);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000f;
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    al = 0x5d;
    push(ax);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0028);
    if (memoryAGet16(ss, bp - 10) == 0x0001)
        goto loc_3e66;
    goto loc_3baa;
loc_3e66: // 01ed:1f96
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_3e6c() // 01ed:1f9c
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    di = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ss, di + 65534) > (short)0x0000)
        goto loc_3e7f;
    goto loc_40be;
loc_3e7f: // 01ed:1faf
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 65534);
    memoryASet16(ss, bp - 8, ax);
    ax = 0x0001;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 8))
        goto loc_3e94;
    goto loc_40be;
loc_3e94: // 01ed:1fc4
    memoryASet16(ss, bp - 4, ax);
    goto loc_3e9c;
loc_3e99: // 01ed:1fc9
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_3e9c: // 01ed:1fcc
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0147;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += 0xd865;
    memoryASet16(ss, bp - 12, di);
    memoryASet16(ss, bp - 10, ss);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet(es, di) != 0x00)
        goto loc_3ebf;
    goto loc_40b3;
loc_3ebf: // 01ed:1fef
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, di + 1);
    memoryASet16(ss, bp - 14, ax);
    ax = 0x0001;
    if ((short)ax > (short)memoryAGet16(ss, bp - 14))
        goto loc_3f20;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3ed9;
loc_3ed6: // 01ed:2006
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3ed9: // 01ed:2009
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    if (memoryAGet16(es, di + 5) == 0xffff)
        goto loc_3f18;
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 5);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 85);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    al = 0x00;
    push(ax);
    sub_235c(); // 01ed:048c
loc_3f18: // 01ed:2048
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 14))
        goto loc_3ed6;
loc_3f20: // 01ed:2050
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, di + 5);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (ax != memoryAGet16(es, di + 3))
        goto loc_3f86;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    memoryASet(es, di, 0x00);
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 4);
    if (ax != memoryAGet16(ss, di + 65534))
        goto loc_3f83;
loc_3f43: // 01ed:2073
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 65534);
    dx = 0x0147;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    if (memoryAGet(ss, di + 55397) == 0x00)
        goto loc_3f60;
    al = 0x00;
    goto loc_3f62;
loc_3f60: // 01ed:2090
    al = 0x01;
loc_3f62: // 01ed:2092
    dl = al;
    di = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ss, di + 65534) > (short)0x0000)
        goto loc_3f72;
    al = 0x00;
    goto loc_3f74;
loc_3f72: // 01ed:20a2
    al = 0x01;
loc_3f74: // 01ed:20a4
    al &= dl;
    if (!al)
        goto loc_3f83;
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 65534, memoryAGet16(ss, di + 65534) - 1);
    goto loc_3f43;
loc_3f83: // 01ed:20b3
    goto loc_40b3;
loc_3f86: // 01ed:20b6
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    memoryASet16(es, di + 5, memoryAGet16(es, di + 5) + 1);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, di + 1);
    memoryASet16(ss, bp - 14, ax);
    ax = 0x0001;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 14))
        goto loc_3fa2;
    goto loc_40b3;
loc_3fa2: // 01ed:20d2
    memoryASet16(ss, bp - 2, ax);
    goto loc_3faa;
loc_3fa7: // 01ed:20d7
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_3faa: // 01ed:20da
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    if (memoryAGet16(es, di + 5) != 0xffff)
        goto loc_3fbe;
    goto loc_40a8;
loc_3fbe: // 01ed:20ee
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    dx = memoryAGet16(es, di + 165);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    memoryASet16(es, di + 5, memoryAGet16(es, di + 5) + dx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    dx = memoryAGet16(es, di + 245);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    memoryASet16(es, di + 85, memoryAGet16(es, di + 85) + dx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 5);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 85);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    sub_23e4(); // 01ed:0514
    ah = 0;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) == 0x000c)
        goto loc_4032;
    al = 0x00;
    goto loc_4034;
loc_4032: // 01ed:2162
    al = 0x01;
loc_4034: // 01ed:2164
    bl = al;
    if (memoryAGet16(ss, bp - 6) == 0x0008)
        goto loc_4040;
    al = 0x00;
    goto loc_4042;
loc_4040: // 01ed:2170
    al = 0x01;
loc_4042: // 01ed:2172
    cl = al;
    if (memoryAGet16(ss, bp - 6) == 0x0006)
        goto loc_404e;
    al = 0x00;
    goto loc_4050;
loc_404e: // 01ed:217e
    al = 0x01;
loc_4050: // 01ed:2180
    dl = al;
    if (memoryAGet16(ss, bp - 6) == 0x0000)
        goto loc_405c;
    al = 0x00;
    goto loc_405e;
loc_405c: // 01ed:218c
    al = 0x01;
loc_405e: // 01ed:218e
    al |= dl;
    al |= cl;
    al |= bl;
    if (!al)
        goto loc_4098;
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 5);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    ax = memoryAGet16(es, di + 85);
    cx = 0x0005;
    ax >>= cl;
    push(ax);
    al = 0x0c;
    push(ax);
    sub_235c(); // 01ed:048c
    goto loc_40a8;
loc_4098: // 01ed:21c8
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    di += ax;
    memoryASet16(es, di + 5, 0xffff);
loc_40a8: // 01ed:21d8
    ax = memoryAGet16(ss, bp - 2);
    if (ax == memoryAGet16(ss, bp - 14))
        goto loc_40b3;
    goto loc_3fa7;
loc_40b3: // 01ed:21e3
    ax = memoryAGet16(ss, bp - 4);
    if (ax == memoryAGet16(ss, bp - 8))
        goto loc_40be;
    goto loc_3e99;
loc_40be: // 01ed:21ee
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_40c4() // 01ed:21f4
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000f;
    if (memoryAGet16(ss, bp + 8) != 0x0001)
        goto loc_40d7;
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    goto loc_40dc;
loc_40d7: // 01ed:2207
    memoryASet16(ss, bp - 8, 0x0050);
loc_40dc: // 01ed:220c
    if (memoryAGet16(ss, bp + 6) != 0x0001)
        goto loc_4133;
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    al = memoryAGet(ss, di + 55108);
    ah = 0;
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    al = memoryAGet(ss, di + 55112);
    ah = 0;
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55107);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55111, dx);
    memoryASet16(ss, bp - 6, 0x004f);
    memoryASet(ss, bp - 13, 0x0e);
    goto loc_4182;
loc_4133: // 01ed:2263
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    al = memoryAGet(ss, di + 55100);
    ah = 0;
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    al = memoryAGet(ss, di + 55104);
    ah = 0;
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55099);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55103, dx);
    memoryASet16(ss, bp - 6, 0x005a);
    memoryASet(ss, bp - 13, 0x0b);
loc_4182: // 01ed:22b2
    if ((short)memoryAGet16(ss, bp - 10) >= (short)0x0001)
        goto loc_418d;
    memoryASet16(ss, bp - 10, 0x0001);
loc_418d: // 01ed:22bd
    ax = memoryAGet16(ss, bp - 12);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 10))
        goto loc_41df;
    ax = memoryAGet16(ss, bp - 12);
    memoryASet16(ss, bp - 15, ax);
    ax = memoryAGet16(ss, bp - 10);
    if ((short)ax > (short)memoryAGet16(ss, bp - 15))
        goto loc_41dd;
    memoryASet16(ss, bp - 4, ax);
    goto loc_41ab;
loc_41a8: // 01ed:22d8
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_41ab: // 01ed:22db
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_41b5;
loc_41b2: // 01ed:22e2
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_41b5: // 01ed:22e5
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0015;
    ax += memoryAGet16(ss, bp - 8);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    al = memoryAGet(ss, bp - 13);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e energy2
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0003)
        goto loc_41b2;
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 15))
        goto loc_41a8;
loc_41dd: // 01ed:230d
    goto loc_4227;
loc_41df: // 01ed:230f
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 15, ax);
    ax = memoryAGet16(ss, bp - 12);
    ax++;
    if ((short)ax > (short)memoryAGet16(ss, bp - 15))
        goto loc_4227;
    memoryASet16(ss, bp - 4, ax);
    goto loc_41f6;
loc_41f3: // 01ed:2323
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_41f6: // 01ed:2326
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_4200;
loc_41fd: // 01ed:232d
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4200: // 01ed:2330
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0015;
    ax += memoryAGet16(ss, bp - 8);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0003)
        goto loc_41fd;
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 15))
        goto loc_41f3;
loc_4227: // 01ed:2357
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_422d() // 01ed:235d
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55079, memoryAGet16(ss, di + 55079) + 1);
    di = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ss, di + 55079) <= (short)0x0002)
        goto loc_424d;
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55079, 0x0001);
loc_424d: // 01ed:237d
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55079);
    if (ax != 0x0001)
        goto loc_427c;
    di = memoryAGet16(ss, bp + 4);
    al = memoryAGet(ss, di + 55110);
    di = memoryAGet16(ss, bp + 4);
    if (al == memoryAGet(ss, di + 55114))
        goto loc_427a;
    ax = 0x0001;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_40c4(); // 01ed:21f4
loc_427a: // 01ed:23aa
    goto loc_42a1;
loc_427c: // 01ed:23ac
    if (ax != 0x0002)
        goto loc_42a1;
    di = memoryAGet16(ss, bp + 4);
    al = memoryAGet(ss, di + 55112);
    di = memoryAGet16(ss, bp + 4);
    if (al == memoryAGet(ss, di + 55116))
        goto loc_42a1;
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_40c4(); // 01ed:21f4
loc_42a1: // 01ed:23d1
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_42a7() // 01ed:23d7
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    memoryASet16(ds, 0x1264, 0x0001);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_42bd;
loc_42ba: // 01ed:23ea
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_42bd: // 01ed:23ed
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 4712, ax);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 4716, ax);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 4720, ax);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 4724, ax);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 4708, ax);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_42ba;
loc_42fa: // 01ed:242a
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_4304;
loc_4301: // 01ed:2431
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4304: // 01ed:2434
    ax = 0x02c0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x00a0;
    dx = ax;
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55695, dx);
    ax = 0x00c0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x00a0;
    dx = ax;
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55699, dx);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_4301;
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55697);
    di = memoryAGet16(ss, bp + 4);
    ax -= memoryAGet16(ss, di + 55699);
    if (!(ax & 0x8000))
        goto loc_435a;
    ax = -ax;
loc_435a: // 01ed:248a
    push(ax);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di + 55701);
    di = memoryAGet16(ss, bp + 4);
    ax -= memoryAGet16(ss, di + 55703);
    if (!(ax & 0x8000))
        goto loc_4371;
    ax = -ax;
loc_4371: // 01ed:24a1
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_2b35(); // 01ed:0c65
    if ((short)ax > (short)0x0064)
        goto loc_4380;
    goto loc_42fa;
loc_4380: // 01ed:24b0
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4386() // 01ed:24b6
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    di = memoryAGet16(ss, bp + 4);
    ax = 0;
    memoryASet16(ss, di + 65534, ax);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_439f;
loc_439c: // 01ed:24cc
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_439f: // 01ed:24cf
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0147;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet(ss, di + 55397, 0x00);
    if (memoryAGet16(ss, bp - 4) != 0x001e)
        goto loc_439c;
    di = memoryAGet16(ss, bp + 4);
    di += 0xd753;
    push(ss);
    push(di);
    ax = 0x0200;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x01ed);
    di = memoryAGet16(ss, bp + 4);
    ax = 0;
    memoryASet16(ss, di + 55635, ax);
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55720, 0x0002);
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55722, 0x0006);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_43f5;
loc_43f2: // 01ed:2522
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_43f5: // 01ed:2525
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55695);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55710, dx);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    dx = memoryAGet16(ss, di + 55699);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55714, dx);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55703, 0xffff);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = 0;
    memoryASet16(ss, di + 55095, ax);
    di = memoryAGet16(ss, bp - 4);
    memoryASet(ds, di + 4729, 0x01);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = 0;
    memoryASet16(ss, di + 55115, ax);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_4476;
loc_4473: // 01ed:25a3
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4476: // 01ed:25a6
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    cx = ax;
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000c;
    mul(dx);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    di += cx;
    memoryASet16(ss, di + 55635, 0xffff);
    if (memoryAGet16(ss, bp - 2) != 0x0006)
        goto loc_4473;
    ax = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet(ss, di + 55709, 0x00);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55107, 0x2c88);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = 0;
    memoryASet16(ss, di + 55111, ax);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    memoryASet16(ss, di + 55099, 0x2c88);
    ax = memoryAGet16(ss, bp - 4);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = 0;
    memoryASet16(ss, di + 55103, ax);
    if (memoryAGet16(ss, bp - 4) == 0x0002)
        goto loc_44f4;
    goto loc_43f2;
loc_44f4: // 01ed:2624
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, di + 55077, 0xffff);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4504() // 01ed:2634
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_4514;
loc_4511: // 01ed:2641
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_4514: // 01ed:2644
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax += 0x0010;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax -= 0x0010;
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_4598;
    memoryASet16(ss, bp - 4, ax);
    goto loc_4548;
loc_4545: // 01ed:2675
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_4548: // 01ed:2678
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0010;
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax -= 0x0010;
    if ((short)ax > (short)memoryAGet16(ss, bp - 10))
        goto loc_4590;
    memoryASet16(ss, bp - 2, ax);
    goto loc_457c;
loc_4579: // 01ed:26a9
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_457c: // 01ed:26ac
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 2));
    al = 0x00;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 10))
        goto loc_4579;
loc_4590: // 01ed:26c0
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_4545;
loc_4598: // 01ed:26c8
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax -= 0x0004;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax -= 0x0011;
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_4614;
    memoryASet16(ss, bp - 4, ax);
    goto loc_45cc;
loc_45c9: // 01ed:26f9
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_45cc: // 01ed:26fc
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax -= 0x0011;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0011;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_45c9;
loc_4614: // 01ed:2744
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax += 0x0004;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax += 0x0011;
    if ((short)ax < (short)memoryAGet16(ss, bp - 8))
        goto loc_4690;
    memoryASet16(ss, bp - 4, ax);
    goto loc_4648;
loc_4645: // 01ed:2775
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
loc_4648: // 01ed:2778
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax -= 0x0011;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    push(memoryAGet16(ss, bp - 4));
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0011;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_4645;
loc_4690: // 01ed:27c0
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0010;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax -= 0x0010;
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_470c;
    memoryASet16(ss, bp - 2, ax);
    goto loc_46c4;
loc_46c1: // 01ed:27f1
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_46c4: // 01ed:27f4
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax -= 0x0011;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax += 0x0011;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0008;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 8))
        goto loc_46c1;
loc_470c: // 01ed:283c
    if (memoryAGet16(ss, bp - 6) == 0x0002)
        goto loc_4715;
    goto loc_4511;
loc_4715: // 01ed:2845
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4732() // 01ed:2862
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    al = 0x05;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x22;
    push(ax);
    al = 0x08;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xda;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_477e;
loc_477b: // 01ed:28ab
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_477e: // 01ed:28ae
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc4;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) != 0x0009)
        goto loc_477b;
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xbf;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x22;
    push(ax);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x284b;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1264);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    di = 0x2854;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x22;
    push(ax);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc0;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_4815;
loc_4812: // 01ed:2942
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_4815: // 01ed:2945
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc4;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) != 0x0009)
        goto loc_4812;
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xd9;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x19;
    push(ax);
    al = 0x10;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x2857;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x1b;
    push(ax);
    al = 0x12;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    ax = memoryAGet16(ds, 0x1266);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x32;
    push(ax);
    al = 0x10;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x285c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x34;
    push(ax);
    al = 0x12;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    ax = memoryAGet16(ds, 0x1268);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_48ec;
loc_48e9: // 01ed:2a19
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_48ec: // 01ed:2a1c
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_48f6;
loc_48f3: // 01ed:2a23
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_48f6: // 01ed:2a26
    ax = memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0006;
    idiv(cx);
    tx = dx;
    dx = ax;
    ax = tx;
    di = ax;
    dl = memoryAGet(ds, di + 98);
    ax = 0xb800;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    ax += 0x0547;
    di = ax;
    es = pop();
    memoryASet(es, di, dl);
    if (memoryAGet16(ss, bp - 2) != 0x0006)
        goto loc_48f3;
    ax = 0x0028;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90f9(); // 08e1:02e9
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 4) != 0x0050)
        goto loc_48e9;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4936() // 01ed:2a66
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0015;
    push(cs);
    cs = 0x07d7;
    sub_8078(); // 07d7:0308
    assert(cs == 0x01ed);
    ax = 0;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x004f;
    push(ax);
    ax = 0x0063;
    push(ax);
    al = 0xb0;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x01;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0x0004;
    push(ax);
    ax = 0x0005;
    push(ax);
    ax = 0x004b;
    push(ax);
    ax = 0x004d;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x00;
    push(ax);
    al = 0x00;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0x0016;
    push(ax);
    ax = 0x0055;
    push(ax);
    ax = 0x0039;
    push(ax);
    ax = 0x005d;
    push(ax);
    al = 0xdd;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    sub_2212(); // 01ed:0342
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
    goto loc_499d;
loc_499a: // 01ed:2aca
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_499d: // 01ed:2acd
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_49a7;
loc_49a4: // 01ed:2ad4
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_49a7: // 01ed:2ad7
    ax = memoryAGet16(ss, bp - 8);
    cx = 0x0007;
    imul(cx);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 6);
    cx = 0x0007;
    imul(cx);
    memoryASet16(ss, bp - 2, ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 2));
    sub_23e4(); // 01ed:0514
    memoryASet(ss, bp - 9, al);
    if (memoryAGet(ss, bp - 9) == 0x0a)
        goto loc_49d3;
    al = 0x00;
    goto loc_49d5;
loc_49d3: // 01ed:2b03
    al = 0x01;
loc_49d5: // 01ed:2b05
    dl = al;
    if (memoryAGet(ss, bp - 9) == 0x09)
        goto loc_49e1;
    al = 0x00;
    goto loc_49e3;
loc_49e1: // 01ed:2b11
    al = 0x01;
loc_49e3: // 01ed:2b13
    al |= dl;
    if (!al)
        goto loc_49ed;
    memoryASet(ss, bp - 9, 0x00);
loc_49ed: // 01ed:2b1d
    ax = memoryAGet16(ss, bp - 8);
    ax += 0x0007;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0005;
    push(ax);
    al = memoryAGet(ss, bp - 9);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 8) != 0x0090)
        goto loc_49a4;
    if (memoryAGet16(ss, bp - 6) != 0x0048)
        goto loc_499a;
    memoryASet16(ss, bp - 11, 0x0001);
    goto loc_4a1b;
loc_4a18: // 01ed:2b48
    memoryASet16(ss, bp - 11, memoryAGet16(ss, bp - 11) + 1);
loc_4a1b: // 01ed:2b4b
    ax = memoryAGet16(ss, bp - 11);
    ax += 0x0008;
    memoryASet(ss, bp - 18, al);
    ax = memoryAGet16(ss, bp - 11);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55695);
    ax += 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    ax += 0x0007;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 11);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    ax += 0x0005;
    ax += 0x0002;
    memoryASet16(ss, bp - 21, ax);
    ax = memoryAGet16(ss, bp - 11);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    ax += 0x0005;
    ax -= 0x0002;
    if ((short)ax > (short)memoryAGet16(ss, bp - 21))
        goto loc_4abe;
    memoryASet16(ss, bp - 6, ax);
    goto loc_4a8e;
loc_4a8b: // 01ed:2bbb
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_4a8e: // 01ed:2bbe
    ax = memoryAGet16(ss, bp - 8);
    ax -= 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 6);
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    ax += 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 6);
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 6);
    if (ax != memoryAGet16(ss, bp - 21))
        goto loc_4a8b;
loc_4abe: // 01ed:2bee
    ax = memoryAGet16(ss, bp - 11);
    ax <<= 1;
    di = memoryAGet16(ss, bp + 4);
    di += ax;
    ax = memoryAGet16(ss, di + 55699);
    ax += 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    ax += 0x0005;
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 8);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0002;
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 11) == 0x0002)
        goto loc_4b39;
    goto loc_4a18;
loc_4b39: // 01ed:2c69
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_4b43;
loc_4b40: // 01ed:2c70
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_4b43: // 01ed:2c73
    al = memoryAGet(ds, 0x00b3);
    ah = 0;
    memoryASet16(ss, bp - 21, ax);
    ax = 0x0001;
    if ((short)ax > (short)memoryAGet16(ss, bp - 21))
        goto loc_4bac;
    memoryASet16(ss, bp - 8, ax);
    goto loc_4b5b;
loc_4b58: // 01ed:2c88
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_4b5b: // 01ed:2c8b
    ax = memoryAGet16(ss, bp - 8);
    cx = ax;
    ax = memoryAGet16(ss, bp - 6);
    dx = 0x0039;
    mul(dx);
    di = ax;
    di += cx;
    if (memoryAGet(ds, di + 122) != 0x2a)
        goto loc_4b79;
    memoryASet(ss, bp - 18, 0x0e);
    goto loc_4b7d;
loc_4b79: // 01ed:2ca9
    memoryASet(ss, bp - 18, 0x01);
loc_4b7d: // 01ed:2cad
    al = memoryAGet(ds, 0x00b3);
    ah = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0002;
    idiv(cx);
    dx = ax;
    ax = 0x0050;
    ax -= dx;
    ax--;
    ax += memoryAGet16(ss, bp - 8);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0056;
    push(ax);
    al = memoryAGet(ss, bp - 18);
    push(ax);
    push(cs);
    cs = 0x07d7;
    sub_7dfe(); // 07d7:008e
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp - 8);
    if (ax != memoryAGet16(ss, bp - 21))
        goto loc_4b58;
loc_4bac: // 01ed:2cdc
    if (memoryAGet16(ss, bp - 6) != 0x0005)
        goto loc_4b40;
loc_4bb2: // 01ed:2ce2
    push(cs);
    cs = 0x08e1;
    sub_9155(); // 08e1:0345
    assert(cs == 0x01ed);
    if (!al)
        goto loc_4bb2;
    push(cs);
    cs = 0x08e1;
    sub_9167(); // 08e1:0357
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 19, al);
    push(cs);
    cs = 0x07d7;
    sub_8197(); // 07d7:0427
    assert(cs == 0x01ed);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90ce(); // 08e1:02be
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x08e1;
    sub_901d(); // 08e1:020d
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_4bdb() // 01ed:2d0b
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x28e2;
    push(bp);
    sub_42a7(); // 01ed:23d7
    push(cs);
    cs = 0x08c0;
    sub_8c00(); // 08c0:0000
    assert(cs == 0x01ed);
    memoryASet(ss, bp + 55076, 0x00);
    memoryASet16(ss, bp + 55121, 0x00a0);
    memoryASet(ss, bp + 55074, 0x01);
loc_4bfb: // 01ed:2d2b
    memoryASet(ss, bp + 55075, 0x00);
    push(bp);
    sub_4386(); // 01ed:24b6
    memoryASet16(ss, bp + 55079, 0x0002);
    push(bp);
    sub_4732(); // 01ed:2862
    push(cs);
    cs = 0x07d7;
    sub_8078(); // 07d7:0308
    assert(cs == 0x01ed);
    push(bp);
    sub_4504(); // 01ed:2634
    push(bp);
    sub_3b18(); // 01ed:1c48
loc_4c1b: // 01ed:2d4b
    if (memoryAGet(ds, 0x14f1) == 0x00)
        goto loc_4c2c;
    memoryASet(ss, bp + 55075, 0x01);
    memoryASet(ss, bp + 55076, 0x01);
loc_4c2c: // 01ed:2d5c
    if (memoryAGet(ds, 0x152b) == 0x00)
        goto loc_4c38;
    memoryASet(ss, bp + 55074, 0x01);
loc_4c38: // 01ed:2d68
    if (memoryAGet(ds, 0x152c) == 0x00)
        goto loc_4c49;
    memoryASet(ss, bp + 55074, 0x00);
    push(cs);
    cs = 0x08e1;
    sub_914e(); // 08e1:033e
    assert(cs == 0x01ed);
loc_4c49: // 01ed:2d79
    memoryASet16(ss, bp + 55081, 0x0001);
    goto loc_4c55;
loc_4c51: // 01ed:2d81
    memoryASet16(ss, bp + 55081, memoryAGet16(ss, bp + 55081) + 1);
loc_4c55: // 01ed:2d85
    di = memoryAGet16(ss, bp + 55081);
    if (memoryAGet(ds, di + 4729) != 0x00)
        goto loc_4c63;
    goto loc_50ee;
loc_4c63: // 01ed:2d93
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, memoryAGet16(ss, bp + di + 55107) - 0x0002);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55099) > (short)0x0000)
        goto loc_4c7f;
    al = 0x00;
    goto loc_4c81;
loc_4c7f: // 01ed:2daf
    al = 0x01;
loc_4c81: // 01ed:2db1
    dl = al;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) > (short)0x0000)
        goto loc_4c94;
    al = 0x00;
    goto loc_4c96;
loc_4c94: // 01ed:2dc4
    al = 0x01;
loc_4c96: // 01ed:2dc6
    al &= dl;
    if (al)
        goto loc_4c9f;
    goto loc_50c7;
loc_4c9f: // 01ed:2dcf
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55710);
    memoryASet16(ss, bp + 55085, ax);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55714);
    memoryASet16(ss, bp + 55087, ax);
    ax = 0;
    memoryASet16(ss, bp + 55083, ax);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 141);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4cdd;
    al = memoryAGet(ss, bp + 55081);
    push(ax);
    push(bp);
    sub_35ea(); // 01ed:171a
    goto loc_4ce9;
loc_4cdd: // 01ed:2e0d
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = 0;
    memoryASet16(ss, bp + di + 55115, ax);
loc_4ce9: // 01ed:2e19
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 145);
    al = memoryAGet(ds, di + 5360);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 149);
    if (al == memoryAGet(ds, di + 5360))
        goto loc_4d3c;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 145);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4d22;
    memoryASet16(ss, bp + 55083, memoryAGet16(ss, bp + 55083) + 1);
    memoryASet16(ss, bp + 55087, memoryAGet16(ss, bp + 55087) - 1);
    goto loc_4d3c;
loc_4d22: // 01ed:2e52
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 149);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4d3c;
    memoryASet16(ss, bp + 55083, memoryAGet16(ss, bp + 55083) + 0x0004);
    memoryASet16(ss, bp + 55087, memoryAGet16(ss, bp + 55087) + 1);
loc_4d3c: // 01ed:2e6c
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 153);
    al = memoryAGet(ds, di + 5360);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 157);
    if (al == memoryAGet(ds, di + 5360))
        goto loc_4d90;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 153);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4d76;
    memoryASet16(ss, bp + 55083, memoryAGet16(ss, bp + 55083) + 0x0002);
    memoryASet16(ss, bp + 55085, memoryAGet16(ss, bp + 55085) + 1);
    goto loc_4d90;
loc_4d76: // 01ed:2ea6
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 157);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4d90;
    memoryASet16(ss, bp + 55083, memoryAGet16(ss, bp + 55083) + 0x0008);
    memoryASet16(ss, bp + 55085, memoryAGet16(ss, bp + 55085) - 1);
loc_4d90: // 01ed:2ec0
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55718);
    memoryASet16(ss, bp + 55089, ax);
    if (memoryAGet16(ss, bp + 55083) != 0x0000)
        goto loc_4da8;
    goto loc_4fc1;
loc_4da8: // 01ed:2ed8
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0001;
    if (ax != 0x0001)
        goto loc_4de4;
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0002;
    if (ax != 0x0002)
        goto loc_4dc8;
    memoryASet16(ss, bp + 55089, 0x0001);
    goto loc_4de2;
loc_4dc8: // 01ed:2ef8
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0008;
    if (ax != 0x0008)
        goto loc_4ddc;
    memoryASet16(ss, bp + 55089, 0x0007);
    goto loc_4de2;
loc_4ddc: // 01ed:2f0c
    ax = 0;
    memoryASet16(ss, bp + 55089, ax);
loc_4de2: // 01ed:2f12
    goto loc_4e3a;
loc_4de4: // 01ed:2f14
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0004;
    if (ax != 0x0004)
        goto loc_4e20;
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0002;
    if (ax != 0x0002)
        goto loc_4e04;
    memoryASet16(ss, bp + 55089, 0x0003);
    goto loc_4e1e;
loc_4e04: // 01ed:2f34
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0008;
    if (ax != 0x0008)
        goto loc_4e18;
    memoryASet16(ss, bp + 55089, 0x0005);
    goto loc_4e1e;
loc_4e18: // 01ed:2f48
    memoryASet16(ss, bp + 55089, 0x0004);
loc_4e1e: // 01ed:2f4e
    goto loc_4e3a;
loc_4e20: // 01ed:2f50
    ax = memoryAGet16(ss, bp + 55083);
    ax &= 0x0002;
    if (ax != 0x0002)
        goto loc_4e34;
    memoryASet16(ss, bp + 55089, 0x0002);
    goto loc_4e3a;
loc_4e34: // 01ed:2f64
    memoryASet16(ss, bp + 55089, 0x0006);
loc_4e3a: // 01ed:2f6a
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55718);
    if (ax == memoryAGet16(ss, bp + 55089))
        goto loc_4e79;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    al = memoryAGet(ss, bp + 55089);
    push(ax);
    push(bp);
    sub_2e2c(); // 01ed:0f5c
    if ((char)al > (char)0x02)
        goto loc_4e79;
    ax = memoryAGet16(ss, bp + 55089);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55718, ax);
loc_4e79: // 01ed:2fa9
    di = memoryAGet16(ss, bp + 55081);
    if (memoryAGet(ss, bp + di + 55709) != 0x00)
        goto loc_4e87;
    goto loc_4fb6;
loc_4e87: // 01ed:2fb7
    push(memoryAGet16(ss, bp + 55085));
    push(memoryAGet16(ss, bp + 55087));
    al = memoryAGet(ss, bp + 55089);
    push(ax);
    push(bp);
    sub_2e2c(); // 01ed:0f5c
    memoryASet(ss, bp + 55072, al);
    if ((char)memoryAGet(ss, bp + 55072) <= (char)0x02)
        goto loc_4ead;
    al = 0x05;
    push(ax);
    push(bp);
    sub_2b96(); // 01ed:0cc6
    goto loc_4fb6;
loc_4ead: // 01ed:2fdd
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp + 55081);
    di = ax;
    di <<= 1;
    dx = memoryAGet16(ss, bp + di + 55710);
    ax = memoryAGet16(ss, bp + 55085);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_4ec8;
    ax = -ax;
loc_4ec8: // 01ed:2ff8
    push(ax);
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp + 55081);
    di = ax;
    di <<= 1;
    dx = memoryAGet16(ss, bp + di + 55714);
    ax = memoryAGet16(ss, bp + 55087);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_4ee4;
    ax = -ax;
loc_4ee4: // 01ed:3014
    push(ax);
    push(bp);
    sub_2b35(); // 01ed:0c65
    if ((short)ax >= (short)0x0006)
        goto loc_4ef1;
    goto loc_4fb6;
loc_4ef1: // 01ed:3021
    if (memoryAGet(ss, bp + 55072) != 0x01)
        goto loc_4f33;
    al = 0x01;
    push(ax);
    push(bp);
    sub_2b96(); // 01ed:0cc6
    push(memoryAGet16(ss, bp + 55085));
    push(memoryAGet16(ss, bp + 55087));
    push(memoryAGet16(ss, bp + 55083));
    push(bp);
    sub_3195(); // 01ed:12c5
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, memoryAGet16(ss, bp + di + 55107) - 0x0002);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ds, di + 4720, memoryAGet16(ds, di + 4720) + 1);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55703, 0x0001);
    goto loc_4fb6;
loc_4f33: // 01ed:3063
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55703) <= (short)0x0000)
        goto loc_4f4c;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55703, memoryAGet16(ss, bp + di + 55703) - 1);
    goto loc_4fb6;
loc_4f4c: // 01ed:307c
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    di = memoryAGet16(ds, di + 141);
    if (memoryAGet(ds, di + 5360) == 0x00)
        goto loc_4f77;
    push(memoryAGet16(ss, bp + 55085));
    push(memoryAGet16(ss, bp + 55087));
    push(memoryAGet16(ss, bp + 55083));
    push(bp);
    sub_3195(); // 01ed:12c5
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ds, di + 4720, memoryAGet16(ds, di + 4720) + 1);
loc_4f77: // 01ed:30a7
    ax = memoryAGet16(ss, bp + 55085);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55710, ax);
    ax = memoryAGet16(ss, bp + 55087);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55714, ax);
    ax = memoryAGet16(ss, bp + 55089);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55718, ax);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, memoryAGet16(ss, bp + di + 55107) - 0x0002);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ds, di + 4724, memoryAGet16(ds, di + 4724) + 1);
loc_4fb6: // 01ed:30e6
    di = memoryAGet16(ss, bp + 55081);
    memoryASet(ss, bp + di + 55709, 0x01);
    goto loc_4fca;
loc_4fc1: // 01ed:30f1
    di = memoryAGet16(ss, bp + 55081);
    memoryASet(ss, bp + di + 55709, 0x00);
loc_4fca: // 01ed:30fa
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55710);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax -= memoryAGet16(ss, bp + di + 55695);
    if (!(ax & 0x8000))
        goto loc_4fe4;
    ax = -ax;
loc_4fe4: // 01ed:3114
    push(ax);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55714);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax -= memoryAGet16(ss, bp + di + 55699);
    if (!(ax & 0x8000))
        goto loc_4fff;
    ax = -ax;
loc_4fff: // 01ed:312f
    push(ax);
    push(bp);
    sub_2b35(); // 01ed:0c65
    if ((short)ax >= (short)0x000f)
        goto loc_5053;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, memoryAGet16(ss, bp + di + 55107) + 0x0050);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) <= (short)0x2c88)
        goto loc_502e;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, 0x2c88);
loc_502e: // 01ed:315e
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55099, memoryAGet16(ss, bp + di + 55099) + 0x0028);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55099) <= (short)0x2c88)
        goto loc_5053;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55099, 0x2c88);
loc_5053: // 01ed:3183
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp + 55081);
    di = ax;
    di <<= 1;
    dx = memoryAGet16(ss, bp + di + 55695);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55710);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_5074;
    ax = -ax;
loc_5074: // 01ed:31a4
    push(ax);
    ax = 0x0003;
    ax -= memoryAGet16(ss, bp + 55081);
    di = ax;
    di <<= 1;
    dx = memoryAGet16(ss, bp + di + 55699);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55714);
    ax -= dx;
    if (!(ax & 0x8000))
        goto loc_5096;
    ax = -ax;
loc_5096: // 01ed:31c6
    push(ax);
    push(bp);
    sub_2b35(); // 01ed:0c65
    if ((short)ax >= (short)0x000f)
        goto loc_50c5;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, memoryAGet16(ss, bp + di + 55107) + 0x001e);
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) <= (short)0x2c88)
        goto loc_50c5;
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, 0x2c88);
loc_50c5: // 01ed:31f5
    goto loc_50e3;
loc_50c7: // 01ed:31f7
    push(memoryAGet16(ss, bp + 55081));
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55081);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    push(bp);
    sub_2fec(); // 01ed:111c
loc_50e3: // 01ed:3213
    if (memoryAGet16(ss, bp + 55081) != 0x0001)
        goto loc_50ee;
    push(bp);
    sub_2d7a(); // 01ed:0eaa
loc_50ee: // 01ed:321e
    if (memoryAGet16(ss, bp + 55081) == 0x0002)
        goto loc_50f8;
    goto loc_4c51;
loc_50f8: // 01ed:3228
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_5104;
loc_5100: // 01ed:3230
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_5104: // 01ed:3234
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) > (short)0x0000)
        goto loc_511d;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    memoryASet16(ss, bp + di + 55107, 0x0001);
loc_511d: // 01ed:324d
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55099) > (short)0x0000)
        goto loc_5136;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    memoryASet16(ss, bp + di + 55099, 0x0001);
loc_5136: // 01ed:3266
    di = memoryAGet16(ss, bp + 55091);
    if (memoryAGet(ds, di + 4729) == 0x00)
        goto loc_5168;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    al = memoryAGet(ss, bp + 55091);
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    al = memoryAGet(ss, bp + di + 55718);
    push(ax);
    sub_24c9(); // 01ed:05f9
loc_5168: // 01ed:3298
    if (memoryAGet16(ss, bp + 55091) != 0x0002)
        goto loc_5100;
    push(bp);
    sub_3851(); // 01ed:1981
    push(bp);
    sub_3734(); // 01ed:1864
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_5183;
loc_517f: // 01ed:32af
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_5183: // 01ed:32b3
    push(bp);
    sub_2d7a(); // 01ed:0eaa
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) >= (short)0x0c80)
        goto loc_51f3;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55107) >= (short)0x0578)
        goto loc_51cc;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55107));
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    if (ax >= 0x0050)
        goto loc_51ca;
    ax = 0x0005;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    memoryASet16(ss, bp + di + 55095, ax);
loc_51ca: // 01ed:32fa
    goto loc_51f3;
loc_51cc: // 01ed:32fc
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55107));
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    if (ax >= 0x0019)
        goto loc_51f3;
    ax = 0x0004;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    memoryASet16(ss, bp + di + 55095, ax);
loc_51f3: // 01ed:3323
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    if ((short)memoryAGet16(ss, bp + di + 55095) > (short)0x0000)
        goto loc_5204;
    al = 0x00;
    goto loc_5206;
loc_5204: // 01ed:3334
    al = 0x01;
loc_5206: // 01ed:3336
    memoryASet(ss, bp + 55073, al);
    if (memoryAGet(ss, bp + 55073) == 0x00)
        goto loc_521b;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    memoryASet16(ss, bp + di + 55095, memoryAGet16(ss, bp + di + 55095) - 1);
loc_521b: // 01ed:334b
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55710);
    ax >>= 1;
    ax -= 0x0013;
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    ax = memoryAGet16(ss, bp + di + 55714);
    ax -= 0x0026;
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ds, di + 137));
    al = memoryAGet(ss, bp + 55073);
    push(ax);
    sub_22d4(); // 01ed:0404
    if (memoryAGet16(ss, bp + 55091) == 0x0002)
        goto loc_5255;
    goto loc_517f;
loc_5255: // 01ed:3385
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_5261;
loc_525d: // 01ed:338d
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_5261: // 01ed:3391
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    ax = memoryAGet16(ss, bp + 55091);
    ax += 0x0002;
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    al = memoryAGet(ss, bp + di + 55718);
    push(ax);
    sub_24c9(); // 01ed:05f9
    if (memoryAGet16(ss, bp + 55091) != 0x0002)
        goto loc_525d;
    push(bp);
    sub_34cd(); // 01ed:15fd
    if ((short)memoryAGet16(ss, bp + 55077) <= (short)0x0000)
        goto loc_52a1;
    memoryASet16(ss, bp + 55077, memoryAGet16(ss, bp + 55077) - 1);
loc_52a1: // 01ed:33d1
    if (memoryAGet16(ss, bp + 55077) != 0x0000)
        goto loc_52ad;
    memoryASet(ss, bp + 55075, 0x01);
loc_52ad: // 01ed:33dd
    push(bp);
    sub_3e6c(); // 01ed:1f9c
    al = memoryAGet(ss, bp + 55102);
    if (al == memoryAGet(ss, bp + 55106))
        goto loc_52ce;
    if ((short)memoryAGet16(ss, bp + 55101) <= (short)0x0000)
        goto loc_52ce;
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    push(bp);
    sub_40c4(); // 01ed:21f4 energy3
loc_52ce: // 01ed:33fe
    al = memoryAGet(ss, bp + 55104);
    if (al == memoryAGet(ss, bp + 55108))
        goto loc_52eb;
    if ((short)memoryAGet16(ss, bp + 55103) <= (short)0x0000)
        goto loc_52eb;
    ax = 0x0002;
    push(ax);
    ax = 0x0002;
    push(ax);
    push(bp);
    sub_40c4(); // 01ed:21f4
loc_52eb: // 01ed:341b
    push(bp);
    sub_422d(); // 01ed:235d
loc_52ef: // 01ed:341f
    sync();
    si = 0x0040;
    es = si;
    ax = memoryAGet16(es, 0x006c);
    if (ax == memoryAGet16(ss, bp + 55070))
        goto loc_52ef;
    si = 0x0040;
    es = si;
    ax = memoryAGet16(es, 0x006c);
    memoryASet16(ss, bp + 55070, ax);
    if (memoryAGet(ds, 0x14f3) == 0x00)
        goto loc_5322;
    ax = 0xb800;
    push(ax);
    ax = memoryAGet16(ss, bp + 55121);
    ax++;
    di = ax;
    es = pop();
    memoryASet(es, di, 0x10);
loc_5322: // 01ed:3452
    ax = memoryAGet16(ss, bp + 55121);
    ax += 0x0002;
    memoryASet16(ss, bp + 55121, ax);
    if ((short)memoryAGet16(ss, bp + 55121) < (short)0x0140)
        goto loc_533b;
    memoryASet16(ss, bp + 55121, 0x00a0);
loc_533b: // 01ed:346b
    if (memoryAGet(ds, 0x14f3) == 0x00)
        goto loc_5352;
    ax = 0xb800;
    push(ax);
    ax = memoryAGet16(ss, bp + 55121);
    ax++;
    di = ax;
    es = pop();
    memoryASet(es, di, 0xff);
loc_5352: // 01ed:3482
    if (memoryAGet(ss, bp + 55075) != 0x00)
        goto loc_535c;
    goto loc_4c1b;
loc_535c: // 01ed:348c
    push(cs);
    cs = 0x08e1;
    sub_914e(); // 08e1:033e
    assert(cs == 0x01ed);
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_536d;
loc_5369: // 01ed:3499
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_536d: // 01ed:349d
    di = memoryAGet16(ss, bp + 55091);
    if (memoryAGet(ds, di + 4729) == 0x00)
        goto loc_539f;
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    al = memoryAGet(ss, bp + 55091);
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    al = memoryAGet(ss, bp + di + 55718);
    push(ax);
    sub_24c9(); // 01ed:05f9
loc_539f: // 01ed:34cf
    if (memoryAGet16(ss, bp + 55091) != 0x0002)
        goto loc_5369;
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_53b2;
loc_53ae: // 01ed:34de
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_53b2: // 01ed:34e2
    ax = memoryAGet16(ss, bp + 55712);
    ax >>= 1;
    ax -= 0x0013;
    push(ax);
    ax = memoryAGet16(ss, bp + 55716);
    ax -= 0x0026;
    push(ax);
    ax = 0x0143;
    push(ax);
    if (memoryAGet(ds, 0x127a) == 0x00)
        goto loc_53d3;
    al = 0x00;
    goto loc_53d5;
loc_53d3: // 01ed:3503
    al = 0x01;
loc_53d5: // 01ed:3505
    push(ax);
    sub_22d4(); // 01ed:0404
    ax = memoryAGet16(ss, bp + 55714);
    ax >>= 1;
    ax -= 0x0013;
    push(ax);
    ax = memoryAGet16(ss, bp + 55718);
    ax -= 0x0026;
    push(ax);
    ax = 0x0193;
    push(ax);
    if (memoryAGet(ds, 0x127b) == 0x00)
        goto loc_53fa;
    al = 0x00;
    goto loc_53fc;
loc_53fa: // 01ed:352a
    al = 0x01;
loc_53fc: // 01ed:352c
    push(ax);
    sub_22d4(); // 01ed:0404
    if (memoryAGet16(ss, bp + 55091) != 0x0014)
        goto loc_53ae;
    push(cs);
    cs = 0x07d7;
    sub_8197(); // 07d7:0427
    assert(cs == 0x01ed);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90ce(); // 08e1:02be
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x08e1;
    sub_901d(); // 08e1:020d
    assert(cs == 0x01ed);
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_5425;
loc_5421: // 01ed:3551
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_5425: // 01ed:3555
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55710));
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    push(memoryAGet16(ss, bp + di + 55714));
    ax = memoryAGet16(ss, bp + 55091);
    ax += 0x0002;
    push(ax);
    di = memoryAGet16(ss, bp + 55091);
    di <<= 1;
    al = memoryAGet(ss, bp + di + 55718);
    push(ax);
    sub_24c9(); // 01ed:05f9
    if (memoryAGet16(ss, bp + 55091) != 0x0002)
        goto loc_5421;
    push(bp);
    sub_34cd(); // 01ed:15fd
    memoryASet16(ss, bp + 55091, 0x0001);
    goto loc_5466;
loc_5462: // 01ed:3592
    memoryASet16(ss, bp + 55091, memoryAGet16(ss, bp + 55091) + 1);
loc_5466: // 01ed:3596
    push(bp);
    sub_3e6c(); // 01ed:1f9c
    if (memoryAGet16(ss, bp + 55091) != 0x0014)
        goto loc_5462;
    memoryASet16(ds, 0x1264, memoryAGet16(ds, 0x1264) + 1);
    if (memoryAGet(ds, 0x127a) != 0x00)
        goto loc_5480;
    memoryASet16(ds, 0x1268, memoryAGet16(ds, 0x1268) + 1);
loc_5480: // 01ed:35b0
    if (memoryAGet(ds, 0x127b) != 0x00)
        goto loc_548b;
    memoryASet16(ds, 0x1266, memoryAGet16(ds, 0x1266) + 1);
loc_548b: // 01ed:35bb
    if ((short)memoryAGet16(ds, 0x1268) >= (short)0x0003)
        goto loc_5496;
    al = 0x00;
    goto loc_5498;
loc_5496: // 01ed:35c6
    al = 0x01;
loc_5498: // 01ed:35c8
    dl = al;
    if ((short)memoryAGet16(ds, 0x1266) >= (short)0x0003)
        goto loc_54a5;
    al = 0x00;
    goto loc_54a7;
loc_54a5: // 01ed:35d5
    al = 0x01;
loc_54a7: // 01ed:35d7
    al |= dl;
    if (!al)
        goto loc_54b2;
    memoryASet(ss, bp + 55076, 0x01);
loc_54b2: // 01ed:35e2
    if (memoryAGet(ss, bp + 55076) != 0x00)
        goto loc_54bc;
    goto loc_4bfb;
loc_54bc: // 01ed:35ec
    push(cs);
    cs = 0x08c0;
    sub_8c40(); // 08c0:0040
    assert(cs == 0x01ed);
    ax = 0x0040;
    push(ax);
    di = 0x0017;
    es = pop();
    al = memoryAGet(es, di);
    al &= 0xf0;
    dl = al;
    ax = 0x0040;
    push(ax);
    di = 0x0017;
    es = pop();
    memoryASet(es, di, dl);
    push(bp);
    sub_4936(); // 01ed:2a66
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_54e3() // 01ed:3613
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0012;
    memoryASet16(ss, bp - 12, 0x0001);
    memoryASet16(ss, bp - 10, 0x0001);
    ax = 0;
    memoryASet16(ss, bp - 8, ax);
    ax = 0;
    memoryASet16(ss, bp - 6, ax);
loc_54fd: // 01ed:362d
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax--;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + ax);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax--;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + ax);
    if ((short)memoryAGet16(ss, bp - 8) <= (short)0x0002)
        goto loc_5522;
    memoryASet16(ss, bp - 8, 0x0002);
loc_5522: // 01ed:3652
    if ((short)memoryAGet16(ss, bp - 6) <= (short)0x0002)
        goto loc_552d;
    memoryASet16(ss, bp - 6, 0x0002);
loc_552d: // 01ed:365d
    if ((short)memoryAGet16(ss, bp - 8) >= (short)0xfffe)
        goto loc_5538;
    memoryASet16(ss, bp - 8, 0xfffe);
loc_5538: // 01ed:3668
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0xfffe)
        goto loc_5543;
    memoryASet16(ss, bp - 6, 0xfffe);
loc_5543: // 01ed:3673
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + ax);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + ax);
    ax = memoryAGet16(ss, bp - 12);
    ax++;
    ax >>= 1;
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 14);
    memoryASet16(ss, bp - 16, ax);
    ax = memoryAGet16(ss, bp - 12);
    ax >>= 1;
    ax = -ax;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 16))
        goto loc_556d;
    goto loc_561c;
loc_556d: // 01ed:369d
    memoryASet16(ss, bp - 4, ax);
    goto loc_5575;
loc_5572: // 01ed:36a2
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_5575: // 01ed:36a5
    ax = memoryAGet16(ss, bp - 4);
    if (!(ax & 0x8000))
        goto loc_557e;
    ax = -ax;
loc_557e: // 01ed:36ae
    dx = ax;
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 14);
    ax -= dx;
    memoryASet16(ss, bp - 18, ax);
    ax = memoryAGet16(ss, bp - 4);
    if (!(ax & 0x8000))
        goto loc_5594;
    ax = -ax;
loc_5594: // 01ed:36c4
    dx = ax;
    ax = memoryAGet16(ss, bp - 14);
    ax -= dx;
    dx = ax;
    ax = memoryAGet16(ss, bp + 8);
    ax -= dx;
    if ((short)ax > (short)memoryAGet16(ss, bp - 18))
        goto loc_5611;
    memoryASet16(ss, bp - 2, ax);
    goto loc_55af;
loc_55ac: // 01ed:36dc
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_55af: // 01ed:36df
    if ((short)memoryAGet16(ss, bp - 2) < (short)0x01ff)
        goto loc_55ba;
    al = 0x00;
    goto loc_55bc;
loc_55ba: // 01ed:36ea
    al = 0x01;
loc_55bc: // 01ed:36ec
    bl = al;
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 4);
    if ((short)ax < (short)0x03ff)
        goto loc_55cd;
    al = 0x00;
    goto loc_55cf;
loc_55cd: // 01ed:36fd
    al = 0x01;
loc_55cf: // 01ed:36ff
    cl = al;
    if ((short)memoryAGet16(ss, bp - 2) > (short)0x0000)
        goto loc_55db;
    al = 0x00;
    goto loc_55dd;
loc_55db: // 01ed:370b
    al = 0x01;
loc_55dd: // 01ed:370d
    dl = al;
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 4);
    if ((short)ax > 0)
        goto loc_55ed;
    al = 0x00;
    goto loc_55ef;
loc_55ed: // 01ed:371d
    al = 0x01;
loc_55ef: // 01ed:371f
    al &= dl;
    al &= cl;
    al &= bl;
    if (!al)
        goto loc_5609;
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 4);
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    al = 0x07;
    push(ax);
    sub_235c(); // 01ed:048c
loc_5609: // 01ed:3739
    ax = memoryAGet16(ss, bp - 2);
    if (ax != memoryAGet16(ss, bp - 18))
        goto loc_55ac;
loc_5611: // 01ed:3741
    ax = memoryAGet16(ss, bp - 4);
    if (ax == memoryAGet16(ss, bp - 16))
        goto loc_561c;
    goto loc_5572;
loc_561c: // 01ed:374c
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + ax);
    ax = memoryAGet16(ss, bp - 12);
    if ((short)ax < (short)memoryAGet16(ss, bp + 6))
        goto loc_562f;
    memoryASet16(ss, bp - 10, 0xffff);
loc_562f: // 01ed:375f
    if ((short)memoryAGet16(ss, bp - 12) <= (short)0x0001)
        goto loc_5638;
    goto loc_54fd;
loc_5638: // 01ed:3768
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_563e() // 01ed:376e
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0306;
    if (memoryAGet16(ds, 0x1323) != 0xfffe)
        goto loc_5652;
    memoryASet16(ds, 0x1323, 0x0001);
loc_5652: // 01ed:3782
    if (memoryAGet16(ds, 0x1323) != 0xffff)
        goto loc_565c;
    goto loc_5e08;
loc_565c: // 01ed:378c
    ax = memoryAGet16(ds, 0x1323);
    if (ax == 0x0001)
        goto loc_5667;
    goto loc_5731;
loc_5667: // 01ed:3797
    ax = 0;
    memoryASet16(ds, 0x1321, ax);
    goto loc_5672;
loc_566e: // 01ed:379e
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_5672: // 01ed:37a2
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax <<= 1;
    ax += 0x0006;
    cx = 0x0004;
    ax <<= cl;
    push(ax);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax <<= 1;
    ax += 0x0006;
    dx = pop();
    ax += dx;
    di = memoryAGet16(ds, 0x1321);
    memoryASet(ss, bp + di + 65018, al);
    if (memoryAGet16(ds, 0x1321) != 0x01d7)
        goto loc_566e;
    memoryASet16(ss, bp - 2, 0xffff);
    memoryASet16(ds, 0x1321, 0x0028);
    goto loc_56b8;
loc_56b4: // 01ed:37e4
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_56b8: // 01ed:37e8
    ax = 0x01ce;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(ss, bp - 2))
        goto loc_56d5;
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0003;
    memoryASet16(ss, bp - 4, ax);
loc_56d5: // 01ed:3805
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 2, ax);
    di = memoryAGet16(ss, bp - 4);
    di = bp+di-0x0206;// stop(); // lea! TODO: CICO!
    push(ss);
    push(di);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += 0x0014;
    push(es);
    push(di);
    ax = 0x01d8;
    ax -= memoryAGet16(ss, bp - 4);
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_abec(); // 0947:177c
    assert(cs == 0x01ed);
    di = bp - 0x206;
    push(ss);
    push(di);
    ax = 0x01ec;
    ax -= memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    push(es);
    push(di);
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x0947;
    sub_abec(); // 0947:177c
    assert(cs == 0x01ed);
    if (memoryAGet16(ds, 0x1321) != 0x01d8)
        goto loc_56b4;
    goto loc_5dfa;
loc_5731: // 01ed:3861
    if (ax != 0x0002)
        goto loc_5755;
    ax = 0;
    memoryASet16(ds, 0x1325, ax);
    ax = 0;
    memoryASet16(ds, 0x1327, ax);
    memoryASet16(ds, 0x1329, 0x6000);
    memoryASet16(ds, 0x132b, 0x6000);
    memoryASet16(ds, 0x131f, 0x0027);
    goto loc_5dfa;
loc_5755: // 01ed:3885
    if (ax == 0x0003)
        goto loc_575d;
    goto loc_59f6;
loc_575d: // 01ed:388d
    ax = memoryAGet16(ds, 0x131f);
    ax++;
    if ((short)ax <= (short)0x01d7)
        goto loc_5769;
    goto loc_59d7;
loc_5769: // 01ed:3899
    memoryASet16(ds, 0x131f, ax);
    goto loc_5772;
loc_576e: // 01ed:389e
    memoryASet16(ds, 0x131f, memoryAGet16(ds, 0x131f) + 1);
loc_5772: // 01ed:38a2
    if ((short)memoryAGet16(ds, 0x131f) > (short)0x01a5)
        goto loc_577e;
    al = 0x00;
    goto loc_5780;
loc_577e: // 01ed:38ae
    al = 0x01;
loc_5780: // 01ed:38b0
    dl = al;
    if ((short)memoryAGet16(ds, 0x131f) < (short)0x005a)
        goto loc_578d;
    al = 0x00;
    goto loc_578f;
loc_578d: // 01ed:38bd
    al = 0x01;
loc_578f: // 01ed:38bf
    al |= dl;
    if (!al)
        goto loc_579f;
    memoryASet16(ds, 0x1325, memoryAGet16(ds, 0x1325) + 0x0032);
    memoryASet16(ds, 0x1327, memoryAGet16(ds, 0x1327) + 0x0032);
loc_579f: // 01ed:38cf
    memoryASet16(ds, 0x1321, 0x0001);
    goto loc_57ab;
loc_57a7: // 01ed:38d7
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_57ab: // 01ed:38db
    ax = 0x0258;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax -= 0x012c;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) + ax);
    ax = 0x0005;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    if (ax != 0x0001)
        goto loc_5805;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4899) <= (short)0x0100)
        goto loc_57f2;
    ax = 0x01f4;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) - ax);
    goto loc_5805;
loc_57f2: // 01ed:3922
    ax = 0x01f4;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) + ax);
loc_5805: // 01ed:3935
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4899);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, memoryAGet16(ds, di + 4903) + ax);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) >= (short)0x2a00)
        goto loc_584d;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) >= (short)0x0af0)
        goto loc_5841;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, 0x2800);
loc_5841: // 01ed:3971
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0x0100);
loc_584d: // 01ed:397d
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) <= (short)0x5e00)
        goto loc_5881;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) <= (short)0x6000)
        goto loc_5875;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, 0x6000);
loc_5875: // 01ed:39a5
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0xff00);
loc_5881: // 01ed:39b1
    if (memoryAGet16(ds, 0x1321) == 0x0002)
        goto loc_588b;
    goto loc_57a7;
loc_588b: // 01ed:39bb
    ax = 0x001e;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x0001)
        goto loc_58d6;
    ax = 0x008c;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    ax += memoryAGet16(ss, bp - 6);
    push(ax);
    push(memoryAGet16(ds, 0x131f));
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    dx = ax;
    ax = 0x0015;
    ax -= dx;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x0006;
    push(ax);
    push(bp);
    sub_54e3(); // 01ed:3613
    goto loc_591a;
loc_58d6: // 01ed:3a06
    if (memoryAGet16(ss, bp - 6) != 0x0002)
        goto loc_591a;
    ax = 0x008c;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x03ff;
    ax -= dx;
    ax -= memoryAGet16(ss, bp - 6);
    push(ax);
    push(memoryAGet16(ds, 0x131f));
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    dx = ax;
    ax = 0x0015;
    ax -= dx;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x0006;
    push(ax);
    push(bp);
    sub_54e3(); // 01ed:3613
loc_591a: // 01ed:3a4a
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    push(ax);
    push(memoryAGet16(ds, 0x131f));
    al = 0x07;
    push(ax);
    sub_235c(); // 01ed:048c
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x03ff;
    ax -= dx;
    push(ax);
    push(memoryAGet16(ds, 0x131f));
    al = 0x07;
    push(ax);
    sub_235c(); // 01ed:048c
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    push(es);
    push(di);
    ax = memoryAGet16(ds, 0x1329);
    ax += 0x0100;
    cx = 0x0009;
    ax >>= cl;
    push(ax);
    al = 0x77;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132b);
    ax += 0x0100;
    cx = 0x0009;
    ax >>= cl;
    dx = ax;
    ax = 0x0200;
    ax -= dx;
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    push(es);
    push(di);
    ax = memoryAGet16(ds, 0x132b);
    ax += 0x0100;
    cx = 0x0009;
    ax >>= cl;
    push(ax);
    al = 0x77;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x01ed);
    di = bp - 0x306;
    push(ss);
    push(di);
    sub_1ed0(); // 01ed:0000
    di = 0x131a;
    push(ds);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9a4f(); // 0947:05df
    assert(cs == 0x01ed);
    di = 0x131a;
    push(ds);
    push(di);
    di = 0x0068;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9b25(); // 0947:06b5
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_59cc;
    if (memoryAGet16(ds, 0x131f) == 0x01d7)
        goto loc_59cc;
    goto loc_5e0e;
loc_59cc: // 01ed:3afc
    if (memoryAGet16(ds, 0x131f) == 0x01d7)
        goto loc_59d7;
    goto loc_576e;
loc_59d7: // 01ed:3b07
    ax = 0;
    memoryASet16(ds, 0x1325, ax);
    ax = 0;
    memoryASet16(ds, 0x1327, ax);
    memoryASet16(ds, 0x1329, 0x4000);
    memoryASet16(ds, 0x132b, 0x4000);
    memoryASet16(ds, 0x131d, 0x0027);
    goto loc_5dfa;
loc_59f6: // 01ed:3b26
    if (ax == 0x0004)
        goto loc_59fe;
    goto loc_5dfa;
loc_59fe: // 01ed:3b2e
    ax = memoryAGet16(ds, 0x131d);
    ax++;
    if ((short)ax <= (short)0x03d7)
        goto loc_5a0a;
    goto loc_5da0;
loc_5a0a: // 01ed:3b3a
    memoryASet16(ds, 0x131d, ax);
    goto loc_5a13;
loc_5a0f: // 01ed:3b3f
    memoryASet16(ds, 0x131d, memoryAGet16(ds, 0x131d) + 1);
loc_5a13: // 01ed:3b43
    memoryASet16(ds, 0x1321, 0x0001);
    goto loc_5a1f;
loc_5a1b: // 01ed:3b4b
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_5a1f: // 01ed:3b4f
    ax = 0x0258;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax -= 0x012c;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) + ax);
    ax = 0x0005;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    if (ax != 0x0001)
        goto loc_5a79;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4899) <= (short)0x0100)
        goto loc_5a66;
    ax = 0x01f4;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) - ax);
    goto loc_5a79;
loc_5a66: // 01ed:3b96
    ax = 0x01f4;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, memoryAGet16(ds, di + 4899) + ax);
loc_5a79: // 01ed:3ba9
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4899) <= (short)0x0500)
        goto loc_5a95;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0x0500);
    goto loc_5aaf;
loc_5a95: // 01ed:3bc5
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4899) >= (short)0xfb00)
        goto loc_5aaf;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0xfb00);
loc_5aaf: // 01ed:3bdf
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4899);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, memoryAGet16(ds, di + 4903) + ax);
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) >= (short)0x2a00)
        goto loc_5af7;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) >= (short)0x0af0)
        goto loc_5aeb;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, 0x2800);
loc_5aeb: // 01ed:3c1b
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0x0100);
loc_5af7: // 01ed:3c27
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) <= (short)0x5e00)
        goto loc_5b2b;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    if ((short)memoryAGet16(ds, di + 4903) <= (short)0x6000)
        goto loc_5b1f;
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4903, 0x6000);
loc_5b1f: // 01ed:3c4f
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    memoryASet16(ds, di + 4899, 0xff00);
loc_5b2b: // 01ed:3c5b
    if (memoryAGet16(ds, 0x1321) == 0x0002)
        goto loc_5b35;
    goto loc_5a1b;
loc_5b35: // 01ed:3c65
    ax = 0x0023;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x0001)
        goto loc_5b7d;
    ax = 0x008c;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    push(memoryAGet16(ds, 0x131d));
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    dx = ax;
    ax = 0x0015;
    ax -= dx;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x0006;
    push(ax);
    push(bp);
    sub_54e3(); // 01ed:3613
    goto loc_5bcb;
loc_5b7d: // 01ed:3cad
    if (memoryAGet16(ss, bp - 6) != 0x0002)
        goto loc_5bcb;
    ax = 0x008c;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 6, ax);
    push(memoryAGet16(ds, 0x131d));
    ax = 0x003c;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    cx = ax;
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x01ff;
    ax -= dx;
    ax -= cx;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x0007;
    idiv(cx);
    dx = ax;
    ax = 0x0015;
    ax -= dx;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_a504(); // 0947:1094
    assert(cs == 0x01ed);
    ax += 0x0006;
    push(ax);
    push(bp);
    sub_54e3(); // 01ed:3613
loc_5bcb: // 01ed:3cfb
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    memoryASet16(ss, bp - 520, ax);
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    ax -= 0x0005;
    if ((short)ax > (short)memoryAGet16(ss, bp - 520))
        goto loc_5c02;
    memoryASet16(ds, 0x1321, ax);
    goto loc_5beb;
loc_5be7: // 01ed:3d17
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_5beb: // 01ed:3d1b
    push(memoryAGet16(ds, 0x131d));
    push(memoryAGet16(ds, 0x1321));
    al = 0x07;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ds, 0x1321);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5be7;
loc_5c02: // 01ed:3d32
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x01ff;
    ax -= dx;
    memoryASet16(ss, bp - 520, ax);
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x0204;
    ax -= dx;
    if ((short)ax < (short)memoryAGet16(ss, bp - 520))
        goto loc_5c44;
    memoryASet16(ds, 0x1321, ax);
    goto loc_5c2d;
loc_5c29: // 01ed:3d59
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) - 1);
loc_5c2d: // 01ed:3d5d
    push(memoryAGet16(ds, 0x131d));
    push(memoryAGet16(ds, 0x1321));
    al = 0x07;
    push(ax);
    sub_235c(); // 01ed:048c
    ax = memoryAGet16(ds, 0x1321);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5c29;
loc_5c44: // 01ed:3d74
    ax = memoryAGet16(ds, 0x131d);
    ax &= 0x0001;
    if (ax == 0x0001)
        goto loc_5c52;
    goto loc_5d63;
loc_5c52: // 01ed:3d82
    ax = memoryAGet16(ds, 0x131d);
    ax >>= 1;
    memoryASet16(ss, bp - 6, ax);
    if ((short)memoryAGet16(ds, 0x1325) >= (short)0xff00)
        goto loc_5c9d;
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    memoryASet16(ss, bp - 520, ax);
    ax = 0x0028;
    if ((short)ax > (short)memoryAGet16(ss, bp - 520))
        goto loc_5c9b;
    memoryASet16(ds, 0x131f, ax);
    goto loc_5c7d;
loc_5c79: // 01ed:3da9
    memoryASet16(ds, 0x131f, memoryAGet16(ds, 0x131f) + 1);
loc_5c7d: // 01ed:3dad
    ax = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, 0x77);
    ax = memoryAGet16(ds, 0x131f);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5c79;
loc_5c9b: // 01ed:3dcb
    goto loc_5cd9;
loc_5c9d: // 01ed:3dcd
    al = memoryAGet(ds, 0x132a);
    ah = 0;
    ax -= 0x0005;
    memoryASet16(ss, bp - 520, ax);
    ax = 0x0028;
    if ((short)ax > (short)memoryAGet16(ss, bp - 520))
        goto loc_5cd9;
    memoryASet16(ds, 0x131f, ax);
    goto loc_5cbb;
loc_5cb7: // 01ed:3de7
    memoryASet16(ds, 0x131f, memoryAGet16(ds, 0x131f) + 1);
loc_5cbb: // 01ed:3deb
    ax = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, 0x77);
    ax = memoryAGet16(ds, 0x131f);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5cb7;
loc_5cd9: // 01ed:3e09
    if ((short)memoryAGet16(ds, 0x1327) >= (short)0xff00)
        goto loc_5d23;
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x01ff;
    ax -= dx;
    memoryASet16(ss, bp - 520, ax);
    ax = 0x01d7;
    if ((short)ax < (short)memoryAGet16(ss, bp - 520))
        goto loc_5d21;
    memoryASet16(ds, 0x131f, ax);
    goto loc_5d03;
loc_5cff: // 01ed:3e2f
    memoryASet16(ds, 0x131f, memoryAGet16(ds, 0x131f) - 1);
loc_5d03: // 01ed:3e33
    ax = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, 0x77);
    ax = memoryAGet16(ds, 0x131f);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5cff;
loc_5d21: // 01ed:3e51
    goto loc_5d63;
loc_5d23: // 01ed:3e53
    al = memoryAGet(ds, 0x132c);
    ah = 0;
    dx = ax;
    ax = 0x0204;
    ax -= dx;
    memoryASet16(ss, bp - 520, ax);
    ax = 0x01d7;
    if ((short)ax < (short)memoryAGet16(ss, bp - 520))
        goto loc_5d63;
    memoryASet16(ds, 0x131f, ax);
    goto loc_5d45;
loc_5d41: // 01ed:3e71
    memoryASet16(ds, 0x131f, memoryAGet16(ds, 0x131f) - 1);
loc_5d45: // 01ed:3e75
    ax = memoryAGet16(ss, bp - 6);
    di = memoryAGet16(ds, 0x131f);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    di += ax;
    memoryASet(es, di, 0x77);
    ax = memoryAGet16(ds, 0x131f);
    if (ax != memoryAGet16(ss, bp - 520))
        goto loc_5d41;
loc_5d63: // 01ed:3e93
    di = bp - 0x306;
    push(ss);
    push(di);
    sub_1ed0(); // 01ed:0000
    di = 0x131a;
    push(ds);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9a4f(); // 0947:05df
    assert(cs == 0x01ed);
    di = 0x131a;
    push(ds);
    push(di);
    di = 0x0068;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9b25(); // 0947:06b5
    assert(cs == 0x01ed);
    if (flags.zero)
        goto loc_5d95;
    if (memoryAGet16(ds, 0x131d) == 0x03d7)
        goto loc_5d95;
    goto loc_5e0e;
loc_5d95: // 01ed:3ec5
    if (memoryAGet16(ds, 0x131d) == 0x03d7)
        goto loc_5da0;
    goto loc_5a0f;
loc_5da0: // 01ed:3ed0
    ax = 0;
    memoryASet16(ds, 0x1321, ax);
    goto loc_5dab;
loc_5da7: // 01ed:3ed7
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_5dab: // 01ed:3edb
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    push(es);
    push(di);
    ax = 0x0200;
    push(ax);
    al = 0x77;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x01ed);
    if (memoryAGet16(ds, 0x1321) != 0x0027)
        goto loc_5da7;
    memoryASet16(ds, 0x1321, 0x01d8);
    goto loc_5dd8;
loc_5dd4: // 01ed:3f04
    memoryASet16(ds, 0x1321, memoryAGet16(ds, 0x1321) + 1);
loc_5dd8: // 01ed:3f08
    di = memoryAGet16(ds, 0x1321);
    di <<= 1;
    di <<= 1;
    tx = di;
    di = memoryAGet16(ds, tx + 1092);
    es = memoryAGet16(ds, tx + 1092 + 2);
    push(es);
    push(di);
    ax = 0x0200;
    push(ax);
    al = 0x77;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x01ed);
    if (memoryAGet16(ds, 0x1321) != 0x01ff)
        goto loc_5dd4;
loc_5dfa: // 01ed:3f2a
    memoryASet16(ds, 0x1323, memoryAGet16(ds, 0x1323) + 1);
    if ((short)memoryAGet16(ds, 0x1323) >= (short)0x0005)
        goto loc_5e08;
    goto loc_565c;
loc_5e08: // 01ed:3f38
    memoryASet16(ds, 0x1323, 0xffff);
loc_5e0e: // 01ed:3f3e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5f2a() // 01ed:405a
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x18;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    al = 0x0c;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x0022;
    push(ax);
    al = 0x04;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3f42;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x04;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x001e;
    push(ax);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3f4f;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x05;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x001d;
    push(ax);
    al = 0x0b;
    push(ax);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x0036;
    push(ax);
    al = 0x16;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xda;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_5fe0;
loc_5fdd: // 01ed:410d
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_5fe0: // 01ed:4110
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc4;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0014)
        goto loc_5fdd;
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xbf;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3f65;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3f7c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3f93;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3faa;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc0;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_608b;
loc_6088: // 01ed:41b8
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_608b: // 01ed:41bb
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xc4;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0014)
        goto loc_6088;
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xd9;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    memoryASet(ds, 0x1331, 0x00);
    if (memoryAGet16(ds, 0x132f) != 0x0000)
        goto loc_60db;
    goto loc_64ba;
loc_60db: // 01ed:420b
    if (memoryAGet(ds, 0x1319) != 0x00)
        goto loc_60e8;
    al = 0x04;
    push(ax);
    sub_21c4(); // 01ed:02f4
loc_60e8: // 01ed:4218
    al = 0x08;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_60fa;
loc_60f7: // 01ed:4227
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_60fa: // 01ed:422a
    al = 0x28;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0xb3;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0019)
        goto loc_60f7;
    al = 0x2b;
    push(ax);
    al = 0x06;
    push(ax);
    al = 0x4f;
    push(ax);
    al = 0x14;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x0e;
    push(ax);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3fc1;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = memoryAGet(ds, 0x127a);
    if (al != memoryAGet(ds, 0x127b))
        goto loc_6183;
    memoryASet(ds, 0x127a, 0x00);
    memoryASet(ds, 0x127b, 0x00);
loc_6183: // 01ed:42b3
    ax = memoryAGet16(ds, 0x1266);
    if ((short)ax > (short)memoryAGet16(ds, 0x1268))
        goto loc_6190;
    al = 0x00;
    goto loc_6192;
loc_6190: // 01ed:42c0
    al = 0x01;
loc_6192: // 01ed:42c2
    cbw();
    cx = 0x0007;
    ax <<= cl;
    ax++;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3fcc;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1268);
    if ((short)ax > (short)memoryAGet16(ds, 0x1266))
        goto loc_61c3;
    al = 0x00;
    goto loc_61c5;
loc_61c3: // 01ed:42f3
    al = 0x01;
loc_61c5: // 01ed:42f5
    cbw();
    cx = 0x0007;
    ax <<= cl;
    ax += 0x0002;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3fea;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3ff0;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_621e;
loc_621b: // 01ed:434b
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_621e: // 01ed:434e
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4712);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0x0009;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_621b;
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4001;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_627f;
loc_627c: // 01ed:43ac
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_627f: // 01ed:43af
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4716);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0x0009;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_627c;
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4012;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_62e0;
loc_62dd: // 01ed:440d
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_62e0: // 01ed:4410
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    if (memoryAGet16(ds, di + 4712) != 0x0000)
        goto loc_6300;
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    memoryASet16(ds, di + 4712, 0x0001);
loc_6300: // 01ed:4430
    di = 0x1694;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4716);
    cx = 0x0064;
    imul(cx);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(memoryAGet16(ds, di + 4712));
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0x0008;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    al = 0x25;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_62dd;
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4024;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_637c;
loc_6379: // 01ed:44a9
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_637c: // 01ed:44ac
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4720);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0x0009;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_6379;
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4035;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_63dd;
loc_63da: // 01ed:450a
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_63dd: // 01ed:450d
    al = memoryAGet(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = memoryAGet16(ss, bp - 2);
    di <<= 1;
    ax = memoryAGet16(ds, di + 4724);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    ax = 0x0009;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_63da;
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = memoryAGet(ds, 0x127a);
    if (al != memoryAGet(ds, 0x127b))
        goto loc_6435;
    goto loc_64ba;
loc_6435: // 01ed:4565
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4046;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x1266);
    if ((short)ax <= (short)memoryAGet16(ds, 0x1268))
        goto loc_647e;
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4055;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    goto loc_649d;
loc_647e: // 01ed:45ae
    al = 0x02;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x3fea;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
loc_649d: // 01ed:45cd
    al = 0x06;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0x2e;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
loc_64ba: // 01ed:45ea
    sub_21ee(); // 01ed:031e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_64c1() // 01ed:45f1
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_64d1;
loc_64ce: // 01ed:45fe
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_64d1: // 01ed:4601
    ax = 0xb8e6;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    di = ax;
    es = pop();
    memoryASet16(es, di, 0x085f);
    if (memoryAGet16(ss, bp - 2) != 0x004f)
        goto loc_64ce;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6508() // 01ed:4638
{
    push(0x7777);
    push(bp);
    bp = sp;
    sub_64c1(); // 01ed:45f1
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x35;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x0f;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x461c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a18() // 01ed:4b48
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x22;
    push(ax);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4680;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x468d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x46dd;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x472e;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x474d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x475c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x479b;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x47e8;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4831;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x483c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x484c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4851;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4876;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x487c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4885;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x48ae;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x48fc;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4925;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4973;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x497f;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x49c0;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4a0c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4a5d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4aad;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4afc;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    sub_6508(); // 01ed:4638
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_736f() // 01ed:549f
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0009;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x22;
    push(ax);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4e24;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4e30;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4e7d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4ecc;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4f1b;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4f69;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4fb5;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5000;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5017;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5061;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x50ad;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x50f6;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0b;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = bp - 0x6;
    push(ss);
    push(di);
    di = bp - 0x4;
    push(ss);
    push(di);
    di = bp - 0x2;
    push(ss);
    push(di);
    di = bp - 0x2;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8d15(); // 08d0:0015
    assert(cs == 0x01ed);
    al = 0x1b;
    push(ax);
    al = 0x10;
    push(ax);
    al = 0x38;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5127;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 6) < 0x07c4)
        goto loc_751d;
    al = 0x00;
    goto loc_751f;
loc_751d: // 01ed:564d
    al = 0x01;
loc_751f: // 01ed:564f
    cl = al;
    if (memoryAGet16(ss, bp - 4) >= 0x0006)
        goto loc_752b;
    al = 0x00;
    goto loc_752d;
loc_752b: // 01ed:565b
    al = 0x01;
loc_752d: // 01ed:565d
    dl = al;
    if (memoryAGet16(ss, bp - 6) == 0x07c7)
        goto loc_753a;
    al = 0x00;
    goto loc_753c;
loc_753a: // 01ed:566a
    al = 0x01;
loc_753c: // 01ed:566c
    al &= dl;
    dl = al;
    if (memoryAGet16(ss, bp - 6) > 0x07c7)
        goto loc_754b;
    al = 0x00;
    goto loc_754d;
loc_754b: // 01ed:567b
    al = 0x01;
loc_754d: // 01ed:567d
    al |= dl;
    al |= cl;
    if (!al)
        goto loc_7585;
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x513a;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5150;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    goto loc_75b3;
loc_7585: // 01ed:56b5
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5163;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x517e;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
loc_75b3: // 01ed:56e3
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    al = 0x14;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5194;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0f;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x51ba;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x51c5;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x10;
    push(ax);
    al = 0x16;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x51d4;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x520e;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_64c1(); // 01ed:45f1
    al = 0x26;
    push(ax);
    al = 0x04;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x0f;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x524d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
loc_76a5: // 01ed:57d5
    push(cs);
    cs = 0x08e1;
    sub_9155(); // 08e1:0345
    assert(cs == 0x01ed);
    if (!al)
        goto loc_76a5;
    push(cs);
    cs = 0x08e1;
    sub_9167(); // 08e1:0357
    assert(cs == 0x01ed);
    if (al)
        goto loc_76bf;
    push(cs);
    cs = 0x08e1;
    sub_9167(); // 08e1:0357
    assert(cs == 0x01ed);
    memoryASet(ss, bp - 9, al);
loc_76bf: // 01ed:57ef
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x4e;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0f;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5268;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5273;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x10;
    push(ax);
    al = 0x13;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5276;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x52a9;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x52e8;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x0f;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x4e;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5313;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5322;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x0a;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x532d;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_781a;
loc_7817: // 01ed:5947
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_781a: // 01ed:594a
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    if (memoryAGet16(ss, bp - 8) != 0x0004)
        goto loc_7817;
    al = 0x0e;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    al = 0x10;
    push(ax);
    al = 0x11;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5331;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5370;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x53b0;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x53ed;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x542c;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5469;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x17;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_6508(); // 01ed:4638
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_78e5() // 01ed:5a15
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    if (memoryAGet16(ds, 0x132f) == 0x0000)
        goto loc_7923;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    al = 0x28;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    al = 0x20;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
loc_7923: // 01ed:5a53
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x18;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_794c() // 01ed:5a7c
{
    push(0x7777);
    push(bp);
    bp = sp;
    sub_5f2a(); // 01ed:405a
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x0020;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5a6b;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
    memoryASet(ds, 0x132d, 0x00);
    memoryASet16(ds, 0x1323, 0xfffe);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_79a3() // 01ed:5ad3
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_79ed() // 01ed:5b1d
{
    push(0x7777);
    push(cs);
    cs = 0x0947;
    sub_9470(); // 0947:0000
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x08e1;
    sub_8e10(); // 08e1:0000
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x081e;
    sub_8457(); // 081e:0277
    assert(cs == 0x01ed);
    bp = sp;
    sp -= 0x0100;
    memoryASet(ds, 0x1311, 0x01);
    ax = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    dx = es;
    memoryASet16(ds, 0x130d, ax);
    memoryASet16(ds, 0x130f, dx);
    ax = 0x017c;
    dx = cs;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, dx);
    memoryASet(ds, 0x157a, 0x00);
    ax = 0x5ad3;
    memoryASet16(ds, 0x1317, ax);
    ax = memoryAGet16(ds, 0x157e);
    memoryASet16(ds, 0x1312, ax);
    sub_28ec(); // 01ed:0a1c
    push(cs);
    cs = 0x07d7;
    sub_7fcc(); // 07d7:025c
    assert(cs == 0x01ed);
    memoryASet(ds, 0x1314, al);
    ax = 0x0040;
    push(ax);
    di = 0x0017;
    es = pop();
    al = memoryAGet(es, di);
    al &= 0x0c;
    if (al == 0x0c)
        goto loc_7a50;
    goto loc_7ae1;
loc_7a50: // 01ed:5b80
    al = 0x04;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5ada;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_97f7(); // 0947:0387
    assert(cs == 0x01ed);
    push(dx);
    push(ax);
    ax = 0x0007;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    al = 0xb3;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aabf(); // 0947:164f
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5ae0;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    al = memoryAGet(ds, 0x1314);
    ah = 0;
    dx = 0;
    push(dx);
    push(ax);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_aba8(); // 0947:1738
    assert(cs == 0x01ed);
    di = 0x5ae8;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5aec;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62(); // 0947:15f2
    assert(cs == 0x01ed);
    di = 0x1594;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa15(); // 0947:15a5
    assert(cs == 0x01ed);
loc_7ae1: // 01ed:5c11
    sub_21ee(); // 01ed:031e
    al = memoryAGet(ds, 0x1314);
    push(ax);
    di = bp - 0x20;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9c51(); // 0947:07e1
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x02;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x03;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x04;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    al = 0x08;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_9cd5(); // 0947:0865
    assert(cs == 0x01ed);
    if (!flags.zero)
        goto loc_7b2f;
    al = 0x02;
    push(ax);
    sub_21c4(); // 01ed:02f4
loc_7b2f: // 01ed:5c5f
    if (memoryAGet(ds, 0x1319) != 0x00)
        goto loc_7b3c;
    al = 0x04;
    push(ax);
    sub_21c4(); // 01ed:02f4
loc_7b3c: // 01ed:5c6c
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90ce(); // 08e1:02be
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    push(cs);
    cs = 0x0947;
    sub_a58a(); // 0947:111a
    assert(cs == 0x01ed);
    sub_2502(); // 01ed:0632
    sub_2882(); // 01ed:09b2
    memoryASet(ds, 0x132e, 0x00);
    ax = 0;
    memoryASet16(ds, 0x132f, ax);
    memoryASet(ds, 0x1331, 0x01);
loc_7b61: // 01ed:5c91
    sub_794c(); // 01ed:5a7c
    sub_5f2a(); // 01ed:405a
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x0020;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x01;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5afa;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
    memoryASet(ds, 0x132d, 0x00);
    memoryASet16(ds, 0x1323, 0xfffe);
loc_7bb4: // 01ed:5ce4
    if (memoryAGet(ds, 0x132d) == 0x00)
        goto loc_7bd4;
    di = bp - 0x100;
    push(ss);
    push(di);
    sub_1ed0(); // 01ed:0000
    di = 0x131a;
    push(ds);
    push(di);
    ax = 0x0002;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9a4f(); // 0947:05df
    assert(cs == 0x01ed);
    goto loc_7bd7;
loc_7bd4: // 01ed:5d04
    sub_563e(); // 01ed:376e
loc_7bd7: // 01ed:5d07
    if (memoryAGet16(ds, 0x1323) == 0xffff)
        goto loc_7be2;
    al = 0x00;
    goto loc_7be4;
loc_7be2: // 01ed:5d12
    al = 0x01;
loc_7be4: // 01ed:5d14
    dl = al;
    if (memoryAGet(ds, 0x132d) == 0x00)
        goto loc_7bf1;
    al = 0x00;
    goto loc_7bf3;
loc_7bf1: // 01ed:5d21
    al = 0x01;
loc_7bf3: // 01ed:5d23
    al &= dl;
    if (!al)
        goto loc_7c40;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    ax = memoryAGet16(ds, 0x132f);
    ax += 0x0020;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x02;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5b0b;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
    memoryASet(ds, 0x132d, 0x01);
loc_7c40: // 01ed:5d70
    al = memoryAGet(ds, 0x131c);
    push(ax);
    di = bp - 0x20;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9c51(); // 0947:07e1
    assert(cs == 0x01ed);
    al = 0x3b;
    push(ax);
    al = 0x3d;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c81(); // 0947:0811
    assert(cs == 0x01ed);
    al = 0x44;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_9cd5(); // 0947:0865
    assert(cs == 0x01ed);
    if (!flags.zero)
        goto loc_7c6c;
    al = 0x00;
    goto loc_7c6e;
loc_7c6c: // 01ed:5d9c
    al = 0x01;
loc_7c6e: // 01ed:5d9e
    dl = al;
    if (memoryAGet(ds, 0x131b) == 0x1b)
        goto loc_7c7b;
    al = 0x00;
    goto loc_7c7d;
loc_7c7b: // 01ed:5dab
    al = 0x01;
loc_7c7d: // 01ed:5dad
    al |= dl;
    if (al)
        goto loc_7c86;
    goto loc_7bb4;
loc_7c86: // 01ed:5db6
    al = 0x32;
    push(ax);
    al = 0x19;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    if (memoryAGet(ds, 0x131b) != 0x1b)
        goto loc_7ca6;
    sub_5f2a(); // 01ed:405a
    goto loc_7ca9;
loc_7ca6: // 01ed:5dd6
    sub_78e5(); // 01ed:5a15
loc_7ca9: // 01ed:5dd9
    al = memoryAGet(ds, 0x131c);
    if (al != 0x3c)
        goto loc_7cb6;
    sub_6a18(); // 01ed:4b48
    goto loc_7d48;
loc_7cb6: // 01ed:5de6
    if (al != 0x3d)
        goto loc_7cc0;
    sub_736f(); // 01ed:549f
    goto loc_7d48;
loc_7cc0: // 01ed:5df0
    if (al != 0x3b)
        goto loc_7d3f;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x18;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    if ((short)memoryAGet16(ds, 0x1323) <= (short)0x0000)
        goto loc_7d20;
    al = 0x01;
    push(ax);
    al = 0x01;
    push(ax);
    al = 0x50;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fdd(); // 08e1:01cd
    assert(cs == 0x01ed);
    sub_21da(); // 01ed:030a
    al = 0x20;
    push(ax);
    al = 0x19;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_9070(); // 08e1:0260
    assert(cs == 0x01ed);
    al = 0x81;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_90b4(); // 08e1:02a4
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5afa;
    push(cs);
    push(di);
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ab1d(); // 0947:16ad
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b(); // 0947:160b
    assert(cs == 0x01ed);
    sub_21ee(); // 01ed:031e
loc_7d20: // 01ed:5e50
    if (memoryAGet16(ds, 0x1323) == 0xffff)
        goto loc_7d2c;
    sub_563e(); // 01ed:376e
    goto loc_7d20;
loc_7d2c: // 01ed:5e5c
    sub_4bdb(); // 01ed:2d0b energy4
    memoryASet16(ds, 0x132f, 0xffec);
    sub_794c(); // 01ed:5a7c
    memoryASet(ds, 0x132d, 0x00);
    goto loc_7d48;
loc_7d3f: // 01ed:5e6f
    if (al != 0x44)
        goto loc_7d48;
    memoryASet(ds, 0x132e, 0x01);
loc_7d48: // 01ed:5e78
    if (memoryAGet(ds, 0x132e) != 0x00)
        goto loc_7d52;
    goto loc_7bb4;
loc_7d52: // 01ed:5e82
    if (memoryAGet(ds, 0x132e) != 0x00)
        goto loc_7d5c;
    goto loc_7b61;
loc_7d5c: // 01ed:5e8c
    sub_79a3(); // 01ed:5ad3
    sub_21da(); // 01ed:030a
    memoryASet(ds, 0x1311, 0x00);
    sp = bp;
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_9663(); // 0947:01f3
    assert(cs == 0x01ed);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x01ed);
    sp -= 0x0014;
    memoryASet(ss, bp - 17, 0x00);
    memoryASet16(ss, bp - 14, 0x2300);
    memoryASet(ss, bp - 19, 0x02);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7d70() // 07d7:0000
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0014;
    memoryASet(ss, bp - 17, 0x00);
    memoryASet16(ss, bp - 14, 0x2300);
    memoryASet(ss, bp - 19, 0x02);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x07d7);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7d9c() // 07d7:002c
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0003;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0003;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    cx = 0x00a0;
    imul(cx);
    dx = ax;
    al = memoryAGet(ss, bp + 8);
    al &= 0xfe;
    ah = 0;
    ax++;
    ax += dx;
    memoryASet16(ss, bp - 3, ax);
    al = memoryAGet(ss, bp + 8);
    al &= 0x01;
    if (al != 0x01)
        goto loc_7de5;
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 3);
    es = pop();
    al = memoryAGet(es, di);
    al &= 0xf0;
    ah = 0;
    cx = 0x0004;
    ax >>= cl;
    memoryASet(ss, bp - 1, al);
    goto loc_7df5;
loc_7de5: // 07d7:0075
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 3);
    es = pop();
    al = memoryAGet(es, di);
    al &= 0x0f;
    memoryASet(ss, bp - 1, al);
loc_7df5: // 07d7:0085
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_7dfe() // 07d7:008e
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0002;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0002;
    al = memoryAGet(ss, bp + 8);
    ah = 0;
    cx = 0x00a0;
    imul(cx);
    dx = ax;
    al = memoryAGet(ss, bp + 10);
    al &= 0xfe;
    ah = 0;
    ax++;
    ax += dx;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet(ss, bp + 6) <= 0x0f)
        goto loc_7e8b;
    if (memoryAGet(ss, bp + 6) <= 0x2f)
        goto loc_7e51;
    al = memoryAGet(ss, bp + 10);
    push(ax);
    al = memoryAGet(ss, bp + 8);
    push(ax);
    push(cs);
    sub_7d9c(); // 07d7:002c
    dl = al;
    al = memoryAGet(ss, bp + 6);
    al &= 0x0f;
    if (al == dl)
        goto loc_7e4b;
    goto loc_7edd;
loc_7e4b: // 07d7:00db
    memoryASet(ss, bp + 6, 0x00);
    goto loc_7e8b;
loc_7e51: // 07d7:00e1
    if (memoryAGet(ss, bp + 6) <= 0x1f)
        goto loc_7e73;
    al = memoryAGet(ss, bp + 10);
    push(ax);
    al = memoryAGet(ss, bp + 8);
    push(ax);
    push(cs);
    sub_7d9c(); // 07d7:002c
    if (!al)
        goto loc_7e69;
    goto loc_7edd;
loc_7e69: // 07d7:00f9
    al = memoryAGet(ss, bp + 6);
    al &= 0x0f;
    memoryASet(ss, bp + 6, al);
    goto loc_7e8b;
loc_7e73: // 07d7:0103
    al = memoryAGet(ss, bp + 10);
    push(ax);
    al = memoryAGet(ss, bp + 8);
    push(ax);
    push(cs);
    sub_7d9c(); // 07d7:002c
    dl = al;
    al = memoryAGet(ss, bp + 6);
    al &= 0x0f;
    al ^= dl;
    memoryASet(ss, bp + 6, al);
loc_7e8b: // 07d7:011b
    al = memoryAGet(ss, bp + 10);
    al &= 0x01;
    if (al != 0x01)
        goto loc_7ec0;
    al = memoryAGet(ss, bp + 6);
    ah = 0;
    cx = 0x0004;
    ax <<= cl;
    memoryASet(ss, bp + 6, al);
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 2);
    es = pop();
    al = memoryAGet(es, di);
    al &= 0x0f;
    al |= memoryAGet(ss, bp + 6);
    dl = al;
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 2);
    es = pop();
    memoryASet(es, di, dl); // energyB
    sync();
    goto loc_7edd;
loc_7ec0: // 07d7:0150
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 2);
    es = pop();
    al = memoryAGet(es, di);
    al &= 0xf0;
    al |= memoryAGet(ss, bp + 6);
    dl = al;
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = memoryAGet16(ss, bp - 2);
    es = pop();
    memoryASet(es, di, dl); // energy  VIDEO!
    sync();
loc_7edd: // 07d7:016d
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_7ee3() // 07d7:0173
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0014;
    memoryASet16(ss, bp - 20, 0x1010);
    al = memoryAGet(ss, bp + 12);
    ah = 0;
    memoryASet16(ss, bp - 18, ax);
    al = memoryAGet(ss, bp + 10);
    memoryASet(ss, bp - 13, al);
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp - 15, al);
    al = memoryAGet(ss, bp + 6);
    memoryASet(ss, bp - 16, al);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x07d7);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_7f23() // 07d7:01b3
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0002;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0002;
    if (memoryAGet16(ds, 0x1332) == 0x0009)
        goto loc_7f7f;
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_7f42;
loc_7f3f: // 07d7:01cf
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_7f42: // 07d7:01d2
    al = memoryAGet(ss, bp - 2);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 481);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 482);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 483);
    push(ax);
    push(cs);
    sub_7ee3(); // 07d7:0173
    if (memoryAGet16(ss, bp - 2) != 0x000f)
        goto loc_7f3f;
    goto loc_7fc8;
loc_7f7f: // 07d7:020f
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    goto loc_7f89;
loc_7f86: // 07d7:0216
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_7f89: // 07d7:0219
    di = memoryAGet16(ss, bp - 2);
    al = memoryAGet(ds, di + 465);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 481);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 482);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0003;
    mul(dx);
    di = ax;
    al = memoryAGet(ds, di + 483);
    push(ax);
    push(cs);
    sub_7ee3(); // 07d7:0173
    if (memoryAGet16(ss, bp - 2) != 0x000f)
        goto loc_7f86;
loc_7fc8: // 07d7:0258
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7fcc() // 07d7:025c
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0006;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0006;
    di = bp - 0x6;
    push(ss);
    push(di);
    di = bp - 0x4;
    push(ss);
    push(di);
    push(cs);
    cs = 0x081e;
    sub_82c9(); // 081e:00e9
    assert(cs == 0x07d7);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7ff6() // 07d7:0286
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    ax = memoryAGet16(ds, 0x1332);
    if (ax == 0x0001)
        goto loc_8012;
    if (ax == 0x0002)
        goto loc_8012;
    if (ax != 0x0009)
        goto loc_802f;
loc_8012: // 07d7:02a2
    al = memoryAGet(ds, 0x1336);
    cbw();
    cx = 0x0005;
    ax <<= cl;
    dx = ax;
    al = memoryAGet(ss, bp + 4);
    cbw();
    cx = 0x0003;
    ax <<= cl;
    ax++;
    ax += dx;
    dx = 0x03d8;
    out(dx, al);
    goto loc_8054;
loc_802f: // 07d7:02bf
    if (ax == 0xfffe)
        goto loc_8039;
    if (ax != 0x0007)
        goto loc_8054;
loc_8039: // 07d7:02c9
    al = memoryAGet(ds, 0x1336);
    cbw();
    cx = 0x0005;
    ax <<= cl;
    dx = ax;
    al = memoryAGet(ss, bp + 4);
    cbw();
    cx = 0x0003;
    ax <<= cl;
    ax++;
    ax += dx;
    dx = 0x03b8;
    out(dx, al);
loc_8054: // 07d7:02e4
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_805a() // 07d7:02ea
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    al = memoryAGet(ss, bp + 6);
    dx = 0x03d4;
    out(dx, al);
    al = memoryAGet(ss, bp + 4);
    dx = 0x03d5;
    out(dx, al);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_8078() // 07d7:0308
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0034;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0034;
    memoryASet16(ds, 0x1334, 0xb800);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x08e1;
    sub_8fc8(); // 08e1:01b8
    assert(cs == 0x07d7);
    ax = memoryAGet16(ds, 0x1334);
    push(ax);
    di = 0;
    es = pop();
    push(es);
    push(di);
    ax = 0x5dc0;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x07d7);
    memoryASet(ds, 0x01d0, 0x01);
    memoryASet(ds, 0x1336, 0x00);
    push(cs);
    sub_7fcc(); // 07d7:025c
    memoryASet16(ds, 0x1332, ax);
    ax = memoryAGet16(ds, 0x1332);
    if (ax == 0x0001)
        goto loc_80cd;
    if (ax == 0x0002)
        goto loc_80cd;
    if (ax != 0x0008)
        goto loc_80ff;
loc_80cd: // 07d7:035d
    al = 0x00;
    push(ax);
    sub_7ff6(); // 07d7:0286
    al = 0x04;
    push(ax);
    al = 0x7f;
    push(ax);
    sub_805a(); // 07d7:02ea
    al = 0x06;
    push(ax);
    al = 0x64;
    push(ax);
    sub_805a(); // 07d7:02ea
    al = 0x07;
    push(ax);
    al = 0x70;
    push(ax);
    sub_805a(); // 07d7:02ea
    al = 0x09;
    push(ax);
    al = 0x01;
    push(ax);
    sub_805a(); // 07d7:02ea
    al = 0x01;
    push(ax);
    sub_7ff6(); // 07d7:0286
    goto loc_8166;
loc_80ff: // 07d7:038f
    if (ax != 0x0009)
        goto loc_8131;
    al = 0x00;
    push(ax);
    sub_7ff6(); // 07d7:0286
    al = 0x09;
    push(ax);
    al = 0x03;
    push(ax);
    sub_805a(); // 07d7:02ea
    memoryASet16(ss, bp - 20, 0x1003);
    memoryASet(ss, bp - 18, 0x00);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x07d7);
    al = 0x01;
    push(ax);
    sub_7ff6(); // 07d7:0286
    goto loc_8166;
loc_8131: // 07d7:03c1
    if (ax == 0x0003)
        goto loc_813b;
    if (ax != 0x0004)
        goto loc_8166;
loc_813b: // 07d7:03cb
    al = 0x00;
    push(ax);
    sub_7ff6(); // 07d7:0286
    al = 0x09;
    push(ax);
    al = 0x02;
    push(ax);
    sub_805a(); // 07d7:02ea
    memoryASet16(ss, bp - 20, 0x1003);
    memoryASet(ss, bp - 18, 0x00);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x07d7);
    al = 0x01;
    push(ax);
    sub_7ff6(); // 07d7:0286
loc_8166: // 07d7:03f6
    push(cs);
    sub_7d70(); // 07d7:0000
    al = memoryAGet(ds, 0x1332);
    push(ax);
    di = bp - 0x34;
    push(ss);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_9c51(); // 0947:07e1
    assert(cs == 0x07d7);
    al = 0x02;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x07d7);
    al = 0x09;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_9c60(); // 0947:07f0
    assert(cs == 0x07d7);
    push(cs);
    cs = 0x0947;
    sub_9cd5(); // 0947:0865
    assert(cs == 0x07d7);
    if (flags.zero)
        goto loc_8193;
    push(cs);
    sub_7f23(); // 07d7:01b3
loc_8193: // 07d7:0423
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8197() // 07d7:0427
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x07d7);
    sp -= 0x0014;
    if (memoryAGet(ds, 0x01d0) == 0x00)
        goto loc_81d1;
    memoryASet16(ss, bp - 20, 0x0004);
    al = 0x10;
    push(ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2(); // 08d0:00b2
    assert(cs == 0x07d7);
    push(memoryAGet16(ds, 0x157e));
    push(cs);
    cs = 0x08e1;
    sub_8fc8(); // 08e1:01b8
    assert(cs == 0x07d7);
    memoryASet(ds, 0x01d0, 0x00);
    push(cs);
    cs = 0x081e;
    sub_837d(); // 081e:019d
    assert(cs == 0x07d7);
loc_81d1: // 07d7:0461
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_82c9() // 081e:00e9
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    push(cs);
    sub_8692(); // 081e:04b2
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if ((short)memoryAGet16(es, di) >= (short)0x0000)
        goto loc_82f4;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, di, 0xfffe);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    ax = memoryAGet16(es, di);
    memoryASet16(ds, 0x1472, ax);
loc_82f4: // 081e:0114
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_82fa() // 081e:011a
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x0055;
    dx = cs;
    memoryASet16(ds, 0x147a, ax);
    memoryASet16(ds, 0x147c, dx);
    ax = 0x0055;
    dx = cs;
    memoryASet16(ds, 0x148c, ax);
    memoryASet16(ds, 0x148e, dx);
    ax = 0;
    memoryASet16(ds, 0x147e, ax);
    memoryASet16(ds, 0x1480, ax);
    ax = 0;
    memoryASet16(ds, 0x1490, ax);
    memoryASet16(ds, 0x1492, ax);
    ax = 0;
    memoryASet16(ds, 0x1482, ax);
    memoryASet16(ds, 0x1484, ax);
    ax = 0;
    memoryASet16(ds, 0x1488, ax);
    memoryASet16(ds, 0x148a, ax);
    ax = 0;
    memoryASet16(ds, 0x1462, ax);
    memoryASet16(ds, 0x1464, ax);
    ax = 0;
    memoryASet16(ds, 0x1466, ax);
    ax = 0;
    memoryASet16(ds, 0x13c0, ax);
    memoryASet(ds, 0x14a1, 0x00);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8350() // 081e:0170
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x147e);
    ax |= memoryAGet16(ds, 0x1480);
    if (ax)
        goto loc_8375;
    ax = memoryAGet16(ds, 0x147a);
    es = memoryAGet16(ds, 0x147a + 2);
    dx = es;
    memoryASet16(ds, 0x147e, ax);
    memoryASet16(ds, 0x1480, dx);
    ax = 0x0055;
    dx = cs;
    memoryASet16(ds, 0x147a, ax);
    memoryASet16(ds, 0x147c, dx);
loc_8375: // 081e:0195
    push(cs);
    sub_855c(); // 081e:037c
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_837d() // 081e:019d
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet(ds, 0x14a1) != 0x00)
        goto loc_838d;
    goto loc_843f;
loc_838d: // 081e:01ad
    push(cs);
    sub_8350(); // 081e:0170
    di = 0x1488;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x1429));
    push(cs);
    cs = memoryAGet16(ds, 0x133c + 2);
    callIndirect(memoryAGet16(ds, 0x133c + 2), memoryAGet16(ds, 0x133c));
    assert(cs == 0x081e);
    ax = memoryAGet16(ds, 0x1482);
    ax |= memoryAGet16(ds, 0x1484);
    if (!ax)
        goto loc_83b9;
    di = memoryAGet16(ds, 0x146e);
    di <<= 1;
    di <<= 1;
    ax = 0;
    memoryASet16(ds, di + 5163, ax);
    memoryASet16(ds, di + 5165, ax);
loc_83b9: // 081e:01d9
    di = 0x1482;
    push(ds);
    push(di);
    push(memoryAGet16(ds, 0x1486));
    push(cs);
    cs = memoryAGet16(ds, 0x133c + 2);
    callIndirect(memoryAGet16(ds, 0x133c + 2), memoryAGet16(ds, 0x133c));
    assert(cs == 0x081e);
    sub_82fa(); // 081e:011a
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_83d3;
loc_83d0: // 081e:01f0
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_83d3: // 081e:01f3
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x000f;
    mul(dx);
    di = ax;
    di += 0x0329;
    memoryASet16(ss, bp - 6, di);
    memoryASet16(ss, bp - 4, ds);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    if (memoryAGet(es, di + 10) == 0x00)
        goto loc_8439;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    if (memoryAGet16(es, di + 8) == 0x0000)
        goto loc_8439;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = memoryAGet16(es, di);
    ax |= memoryAGet16(es, di + 2);
    if (!ax)
        goto loc_8439;
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(es);
    push(di);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, di + 8));
    push(cs);
    cs = memoryAGet16(ds, 0x133c + 2);
    callIndirect(memoryAGet16(ds, 0x133c + 2), memoryAGet16(ds, 0x133c));
    assert(cs == 0x081e);
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
loc_8439: // 081e:0259
    if (memoryAGet16(ss, bp - 2) != 0x000a)
        goto loc_83d0;
loc_843f: // 081e:025f
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8457() // 081e:0277
{
    push(0x7777);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x1472, ax);
    memoryASet16(ds, 0x17a2, 0x0100);
    memoryASet16(ds, 0x1429, 0x1000);
    push(cs);
    sub_86d7(); // 081e:04f7
    sub_82fa(); // 081e:011a
    ax = 0x0263;
    dx = cs;
    memoryASet16(ds, 0x17a4, ax);
    memoryASet16(ds, 0x17a6, dx);
    ax = 0x00a5;
    dx = cs;
    memoryASet16(ds, 0x1338, ax);
    memoryASet16(ds, 0x133a, dx);
    ax = 0x00bb;
    dx = cs;
    memoryASet16(ds, 0x133c, ax);
    memoryASet16(ds, 0x133e, dx);
    memoryASet(ds, 0x13c2, 0x00);
    memoryASet(ds, 0x13cb, 0x00);
    di = 0x142b;
    push(ds);
    push(di);
    ax = 0x0018;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x081e);
    sp = bp;
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_855c() // 081e:037c
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet(ds, 0x14ed) == 0xff)
        goto loc_8580;
    ax = 0x0040;
    es = ax;
    bx = 0x0010;
    al = memoryAGet(ds, 0x14ee);
    memoryASet(es, bx, al);
    ah = 0;
    al = memoryAGet(ds, 0x14ed);
    interrupt(0x10);
    memoryASet(ds, 0x14ed, 0xff);
loc_8580: // 081e:03a0
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8692() // 081e:04b2
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ds, 0x14e4));
    sub_86a4(); // 081e:04c4
    memoryASet16(ds, 0x14e4, pop());
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_86a4() // 081e:04c4
{
    push(bp);
    sub_8a76(); // 081e:0896
    bp = pop();
    al = memoryAGet(ds, 0x14e4);
    if (al != 0x02)
        goto loc_86ba;
    al = 0x01;
    memoryASet(ds, 0x14e4, al);
    memoryASet(ds, 0x14e5, 0x02);
loc_86ba: // 081e:04da
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(ds, 0x14e6);
    ah = 0;
    if (al != 0xff)
        goto loc_86c8;
    ah = al;
loc_86c8: // 081e:04e8
    memoryASet16(es, di, ax);
    ah = 0;
    al = memoryAGet(ds, 0x14e5);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, di, ax);
}
void sub_86d7() // 081e:04f7
{
    ax = 0;
    memoryASet(ds, 0x14e4, 0xff);
    memoryASet(ds, 0x14e5, al);
    memoryASet(ds, 0x14e6, al);
    memoryASet(ds, 0x14e7, al);
    memoryASet(ds, 0x14e8, al);
    memoryASet16(ds, 0x14e9, ax);
    memoryASet16(ds, 0x14eb, ax);
    memoryASet(ds, 0x14ed, 0xff);
    memoryASet(ds, 0x14ee, al);
    cs = pop();
}
void sub_8a76() // 081e:0896
{
    memoryASet(ds, 0x14e4, 0xff);
    memoryASet(ds, 0x14e6, 0xff);
    memoryASet(ds, 0x14e5, 0x00);
    sub_8aac(); // 081e:08cc
    bl = memoryAGet(ds, 0x14e6);
    if (bl == 0xff)
        return;
    bh = 0;
    al = memoryAGet(cs, bx + 2162);
    memoryASet(ds, 0x14e4, al);
    al = memoryAGet(cs, bx + 2174);
    memoryASet(ds, 0x14e5, al);
    al = memoryAGet(cs, bx + 2186);
    memoryASet(ds, 0x14e7, al);
}
void sub_8aac() // 081e:08cc
{
    ah = 0x0f;
    interrupt(0x10);
    if (al == 0x07)
        goto loc_8ae5;
    sub_8b8a(); // 081e:09aa
    if (!flags.carry)
        goto loc_8abf;
    memoryASet(ds, 0x14e6, 0x06);
    return;
loc_8abf: // 081e:08df
    sub_8b13(); // 081e:0933
    if (!flags.carry)
        goto loc_8ac8;
loc_8ac4: // 081e:08e4
    sub_8b31(); // 081e:0951
    return;
loc_8ac8: // 081e:08e8
    sub_8bd0(); // 081e:09f0
    if (ax == 0)
        goto loc_8ad5;
    memoryASet(ds, 0x14e6, 0x0a);
    return;
loc_8ad5: // 081e:08f5
    memoryASet(ds, 0x14e6, 0x01);
    sub_8b69(); // 081e:0989
    if (!flags.carry)
        goto loc_8ae4;
    memoryASet(ds, 0x14e6, 0x02);
loc_8ae4: // 081e:0904
    return;
loc_8ae5: // 081e:0905
    sub_8b13(); // 081e:0933
    if (flags.carry)
        goto loc_8ac4;
    sub_8b9e(); // 081e:09be
    if (al == 0)
        goto loc_8af7;
    memoryASet(ds, 0x14e6, 0x07);
    return;
loc_8af7: // 081e:0917
    si = 0xb800;
    es = si;
    si = 0;
    ax = memoryAGet16(es, si);
    ax = ~ax;
    memoryASet16(es, si, ~memoryAGet16(es, si));
    if (ax != memoryAGet16(es, si))
        return;
    memoryASet(ds, 0x14e6, 0x01);
}
void sub_8b13() // 081e:0933+carry
{
    ax = 0x1200;
    bl = 0x10;
    bh = 0xff;
    cl = 0x0f;
    interrupt(0x10);
    if ((char)cl >= (char)0x0c)
        goto loc_8b2f;
    if ((char)bh > (char)0x01)
        goto loc_8b2f;
    if ((char)bl > (char)0x03)
        goto loc_8b2f;
    flags.carry = true;
    return;
loc_8b2f: // 081e:094f
    flags.carry = false;
}
void sub_8b31() // 081e:0951
{
    memoryASet(ds, 0x14e6, 0x04);
    if (bh == 0x01)
        goto loc_8b54;
    sub_8b5a(); // 081e:097a
    if (flags.carry)
        goto loc_8b53;
    if (bl == 0)
        goto loc_8b53;
    memoryASet(ds, 0x14e6, 0x03);
    sub_8b69(); // 081e:0989
    if (!flags.carry)
        goto loc_8b53;
    memoryASet(ds, 0x14e6, 0x09);
loc_8b53: // 081e:0973
    return;
loc_8b54: // 081e:0974
    memoryASet(ds, 0x14e6, 0x05);
}
void sub_8b5a() // 081e:097a+carry
{
    flags.carry = cl < 0x02;
    if (cl < 0x02)
        return;
    flags.carry = cl < 0x06;
    flags.carry = !flags.carry;
    if (!flags.carry)
        return;
    flags.carry = cl < 0x08;
}
void sub_8b69() // 081e:0989+carry
{
    ax = 0x1a00;
    interrupt(0x10);
    if (al != 0x1a)
        goto loc_8b88;
    if (bl == 0x07)
        goto loc_8b86;
    if (bl == 0x08)
        goto loc_8b86;
    if (bl < 0x0b)
        goto loc_8b88;
    if (bl > 0x0c)
        goto loc_8b88;
loc_8b86: // 081e:09a6
    flags.carry = true;
    return;
loc_8b88: // 081e:09a8
    flags.carry = false;
}
void sub_8b8a() // 081e:09aa+carry
{
    flags.carry = false;
    al = 0;
}
void sub_8b9e() // 081e:09be
{
    dx = 0x03ba;
    bl = 0;
    in(al, dx);
    al &= 0x80;
    ah = al;
    cx = 0x8000;
loc_8bab: // 081e:09cb
    in(al, dx);
    al &= 0x80;
    if (al == ah)
        goto loc_8bb9;
    bl++;
    if (bl >= 0x0a)
        goto loc_8bbe;
loc_8bb9: // 081e:09d9
    if (--cx)
        goto loc_8bab;
    al = 0;
    return;
loc_8bbe: // 081e:09de
    cx = 0x8000;
loc_8bc1: // 081e:09e1
    in(al, dx);
    al &= 0x30;
    if (al != 0x10)
        goto loc_8bcd;
    if (--cx)
        goto loc_8bc1;
    al = 0x02;
    return;
loc_8bcd: // 081e:09ed
    al = 0x01;
}
void sub_8bd0() // 081e:09f0
{
    al = 0x06;
    cx = 0;
    dx = 0;
    ah = 0x30;
    interrupt(0x10);
    ax = cx;
    ax |= dx;
    if (!ax)
        goto loc_8bfd;
    push(ds);
    ds = cx;
    bx = dx;
    al = memoryAGet(ds, bx + 2);
    ds = pop();
    if (!al)
        goto loc_8bf1;
    if (al != 0x02)
        goto loc_8bfd;
loc_8bf1: // 081e:0a11
    dx = 0x0188;
    in(al, dx);
    if (!(al & 0x04))
        goto loc_8bfd;
    ax = 0x0001;
    return;
loc_8bfd: // 081e:0a1d
    ax = 0;
}
void sub_8c00() // 08c0:0000
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x08c0);
    al = 0x09;
    push(ax);
    di = 0x1570;
    push(ds);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8d58(); // 08d0:0058
    assert(cs == 0x08c0);
    al = 0x09;
    push(ax);
    ax = 0x006a;
    dx = cs;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x08d0;
    sub_8d87(); // 08d0:0087
    assert(cs == 0x08c0);
    memoryASet(ds, 0x0424, 0x01);
    di = 0x14f0;
    push(ds);
    push(di);
    ax = 0x0080;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x08c0);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8c40() // 08c0:0040
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0;
    push(cs);
    cs = 0x0947;
    sub_971d(); // 0947:02ad
    assert(cs == 0x08c0);
    if (memoryAGet(ds, 0x0424) == 0x00)
        goto loc_8c66;
    al = 0x09;
    push(ax);
    push(memoryAGet16(ds, 0x1572));
    push(memoryAGet16(ds, 0x1570));
    push(cs);
    cs = 0x08d0;
    sub_8d87(); // 08d0:0087
    assert(cs == 0x08c0);
    memoryASet(ds, 0x0424, 0x00);
loc_8c66: // 08c0:0066
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8c6a() // 08c0:006a
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(ds);
    push(es);
    push(bp);
    bp = sp;
    sp -= 0x0001;
    ax = 0x0ac3;
    ds = ax;
    in(al, 0x60);
    memoryASet(ss, bp - 1, al);
    in(al, 0x61);
    al |= 0x80;
    out(0x61, al);
    in(al, 0x61);
    al &= 0x7f;
    out(0x61, al);
    al = memoryAGet(ss, bp - 1);
    al &= 0x80;
    if (al)
        goto loc_8ca5;
    al = memoryAGet(ss, bp - 1);
    ah = 0;
    di = ax;
    memoryASet(ds, di + 5360, 0x01);
    goto loc_8ceb;
loc_8ca5: // 08c0:00a5
    if (memoryAGet(ss, bp - 1) != 0xff)
        goto loc_8cbe;
    di = 0x14f0;
    push(ds);
    push(di);
    ax = 0x0080;
    push(ax);
    al = 0x00;
    push(ax);
    push(cs);
    cs = 0x0947;
    sub_ac0f(); // 0947:179f
    assert(cs == 0x08c0);
    goto loc_8ceb;
loc_8cbe: // 08c0:00be
    if (memoryAGet(ss, bp - 1) != 0xf0)
        goto loc_8cd7;
    in(al, 0x60);
    memoryASet(ss, bp - 1, al);
    in(al, 0x61);
    al |= 0x80;
    out(0x61, al);
    in(al, 0x61);
    al &= 0x7f;
    out(0x61, al);
    goto loc_8cdf;
loc_8cd7: // 08c0:00d7
    al = memoryAGet(ss, bp - 1);
    al &= 0x7f;
    memoryASet(ss, bp - 1, al);
loc_8cdf: // 08c0:00df
    al = memoryAGet(ss, bp - 1);
    ah = 0;
    di = ax;
    memoryASet(ds, di + 5360, 0x00);
loc_8ceb: // 08c0:00eb
    al = 0x20;
    out(0x20, al);
    sp = bp;
    bp = pop();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    stop(); // iret 
}
void sub_8d00() // 08d0:0000
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x21;
    push(ax);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(es);
    push(di);
    push(cs);
    sub_8db2(); // 08d0:00b2
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_8d15() // 08d0:0015
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memoryASet(ss, bp - 19, 0x2a);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00(); // 08d0:0000
    ax = memoryAGet16(ss, bp - 16);
    di = memoryAGet16(ss, bp + 18);
    es = memoryAGet16(ss, bp + 18 + 2);
    memoryASet16(es, di, ax);
    al = memoryAGet(ss, bp - 13);
    ah = 0;
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, di, ax);
    al = memoryAGet(ss, bp - 14);
    ah = 0;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, di, ax);
    al = memoryAGet(ss, bp - 20);
    ah = 0;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, di, ax);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 16;
}
void sub_8d58() // 08d0:0058
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memoryASet(ss, bp - 19, 0x35);
    al = memoryAGet(ss, bp + 10);
    memoryASet(ss, bp - 20, al);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00(); // 08d0:0000
    ax = memoryAGet16(ss, bp - 18);
    dx = memoryAGet16(ss, bp - 4);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_8d87() // 08d0:0087
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memoryASet(ss, bp - 19, 0x25);
    al = memoryAGet(ss, bp + 10);
    memoryASet(ss, bp - 20, al);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 6, ax);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00(); // 08d0:0000
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_8db2() // 08d0:00b2
{
    push(0x7777);
    push(bp);
    push(ds);
    bp = sp;
    al = memoryAGet(ss, bp + 12);
    int intval = al;
    memoryASet(cs, 0x00dd, al);
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    flags.direction = false;
    lodsw<MemData, DirForward>();
    push(ax);
    lodsw<MemData, DirForward>();
    bx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    bp = ax;
    lodsw<MemData, DirForward>();
    push(ax);
    lodsw<MemData, DirForward>();
    di = ax;
    lodsw<MemData, DirForward>();
    push(ax);
    lodsw<MemData, DirForward>();
    es = ax;
    ds = pop();
    si = pop();
    ax = pop();
    interrupt(intval);
    tx = flags.carry | (flags.zero * 0x40) | (bp & 0x8000);
    push(tx);
    push(es);
    push(di);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 16);
    es = memoryAGet16(ss, bp + 16 + 2);
    flags.direction = false;
    stosw<MemData, DirForward>();
    ax = bx;
    stosw<MemData, DirForward>();
    ax = cx;
    stosw<MemData, DirForward>();
    ax = dx;
    stosw<MemData, DirForward>();
    ax = pop();
    stosw<MemData, DirForward>();
    ax = si;
    stosw<MemData, DirForward>();
    ax = pop();
    stosw<MemData, DirForward>();
    ax = ds;
    stosw<MemData, DirForward>();
    ax = pop();
    stosw<MemData, DirForward>();
    ax = pop();
    stosw<MemData, DirForward>();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_8e10() // 08e1:0000
{
    push(0x7777);
    bp = sp;
    sub_8e3e(); // 08e1:002e
    di = 0x1594;
    push(ds);
    push(di);
    push(cs);
    sub_9189(); // 08e1:0379
    di = 0x1594;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_a719(); // 0947:12a9
    assert(cs == 0x08e1);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    sub_9189(); // 08e1:0379
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_a71e(); // 0947:12ae
    assert(cs == 0x08e1);
    sp = bp;
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8e3e() // 08e1:002e
{
    ah = 0x0f;
    sub_9463(); // 08e1:0653
    if (al == 0x07)
        goto loc_8e51;
    if (al <= 0x03)
        goto loc_8e51;
    ax = 0x0003;
    sub_8ec9(); // 08e1:00b9
loc_8e51: // 08e1:0041
    sub_8f2b(); // 08e1:011b
    ah = 0x08;
    bh = 0;
    sub_9463(); // 08e1:0653
    al = ah;
    al &= 0x7f;
    memoryASet(ds, 0x1591, al);
    memoryASet(ds, 0x1580, al);
    ax = 0;
    memoryASet(ds, 0x157b, al);
    memoryASet(ds, 0x1592, al);
    memoryASet(ds, 0x1593, al);
    ax++;
    memoryASet(ds, 0x157a, al);
    ax = 0x0040;
    es = ax;
    di = 0x006c;
    al = memoryAGet(es, di);
loc_8e7f: // 08e1:006f
    sync();
    if (al == memoryAGet(es, di))
        goto loc_8e7f;
    al = memoryAGet(es, di);
    cx = 0xffff;
    sub_9119(); // 08e1:0309
    ax = 0x0037;
    tx = cx;
    cx = ax;
    ax = tx;
    ax = ~ax;
    dx = 0;
    div(cx);
    memoryASet16(ds, 0x158d, ax);
    ax = 0x351b;
    interrupt(0x21);
    memoryASet16(ds, 0x1585, bx);
    memoryASet16(ds, 0x1587, es);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x017a;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
    ax = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    memoryASet16(ds, 0x1589, ax);
    memoryASet16(ds, 0x158b, es);
    memoryASet16(ds, 0x17a8, 0x0163);
    memoryASet16(ds, 0x17aa, cs);
}
void sub_8ec9() // 08e1:00b9
{
    dx = 0x0040;
    es = dx;
    memoryASet(es, 0x0087, memoryAGet(es, 0x0087) & 0xfe);
    if (al == 0x07)
        goto loc_8ede;
    if (al < 0x04)
        goto loc_8ede;
    al = 0x03;
loc_8ede: // 08e1:00ce
    push(ax);
    ah = 0x00;
    sub_9463(); // 08e1:0653
    ax = pop();
    if (!ah)
        return;
    ax = 0x1112;
    bl = 0x00;
    sub_9463(); // 08e1:0653
    ax = 0x1130;
    bh = 0x00;
    dl = 0x00;
    sub_9463(); // 08e1:0653
    if (dl != 0x2a)
        return;
    memoryASet(es, 0x0087, memoryAGet(es, 0x0087) | 0x01);
    ax = 0x0100;
    cx = 0x0600;
    sub_9463(); // 08e1:0653
    if (memoryAGet(es, 0x0049) != 0x07)
        goto loc_8f23;
    dx = memoryAGet16(es, 0x0063);
    al = 0x14;
    out(dx, al);
    dx++;
    al = 0x07;
    out(dx, al);
loc_8f23: // 08e1:0113
    ah = 0x12;
    bl = 0x20;
    sub_9463(); // 08e1:0653
}
void sub_8f2b() // 08e1:011b
{
    ah = 0x0f;
    sub_9463(); // 08e1:0653
    push(ax);
    ax = 0x1130;
    bh = 0x00;
    dl = 0x00;
    sub_9463(); // 08e1:0653
    ax = pop();
    cl = 0x00;
    if (dl)
        goto loc_8f4a;
    dl = 0x18;
    if (al > 0x03)
        goto loc_8f4a;
    cl = 0x01;
loc_8f4a: // 08e1:013a
    dh = dl;
    dl = ah;
    dl--;
    ah = 0x00;
    if (dh <= 0x18)
        goto loc_8f59;
    ah = 0x01;
loc_8f59: // 08e1:0149
    memoryASet16(ds, 0x157e, ax);
    memoryASet16(ds, 0x158f, dx);
    memoryASet(ds, 0x157d, cl);
    memoryASet(ds, 0x157c, 0x01);
    ax = 0;
    memoryASet16(ds, 0x1581, ax);
    memoryASet16(ds, 0x1583, dx);
}
void sub_8f8a() // 08e1:017a
{
    push(ax);
    push(ds);
    ax = 0x0ac3;
    ds = ax;
    if (memoryAGet(ds, 0x157a) == 0x00)
        goto loc_8f9d;
    memoryASet(ds, 0x1593, 0x01);
loc_8f9d: // 08e1:018d
    ds = pop();
    ax = pop();
    stop(); // iret 
}
void sub_8fa0() // 08e1:0190
{
//    stop(/*unk call conv*/);
    if (memoryAGet(ds, 0x1593) != 0x00)
    {
        assert(0);
        goto loc_8fa8;
    }
//    stop(/*unk call conv*/);
    return;
loc_8fa8: // 08e1:0198
    memoryASet(ds, 0x1593, 0x00);
loc_8fad: // 08e1:019d
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_8fb9;
    ah = 0x00;
    interrupt(0x16);
    goto loc_8fad;
loc_8fb9: // 08e1:01a9
    al = 0x5e;
    sub_92d6(); // 08e1:04c6
    al = 0x43;
    sub_92d6(); // 08e1:04c6
    sub_92cf(); // 08e1:04bf
    interrupt(0x23);
    bx = sp;
    ax = memoryAGet16(ss, bx + 4);
    sub_8ec9(); // 08e1:00b9
    sub_8f2b(); // 08e1:011b
    al = memoryAGet(ds, 0x1591);
    memoryASet(ds, 0x1580, al);
    stop(/*unk call conv*/);
    sp += 2;
}
void sub_8fc8() // 08e1:01b8
{
    push(0x7777);
    bx = sp;
    ax = memoryAGet16(ss, bx + 4);
    sub_8ec9(); // 08e1:00b9
    sub_8f2b(); // 08e1:011b
    al = memoryAGet(ds, 0x1591);
    memoryASet(ds, 0x1580, al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_8fdd() // 08e1:01cd
{
    push(0x7777);
    bx = sp;
    dl = memoryAGet(ss, bx + 10);
    dh = memoryAGet(ss, bx + 8);
    cl = memoryAGet(ss, bx + 6);
    ch = memoryAGet(ss, bx + 4);
    if (dl > cl)
        goto loc_901a;
    if (dh > ch)
        goto loc_901a;
    dl--;
    if ((char)dl < 0)
        goto loc_901a;
    dh--;
    if ((char)dh < 0)
        goto loc_901a;
    cl--;
    if (cl > memoryAGet(ds, 0x158f))
        goto loc_901a;
    ch--;
    if (ch > memoryAGet(ds, 0x1590))
        goto loc_901a;
    memoryASet16(ds, 0x1581, dx);
    memoryASet16(ds, 0x1583, cx);
    sub_9357(); // 08e1:0547
loc_901a: // 08e1:020a
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_901d() // 08e1:020d
{
    ax = 0x0600;
    bh = memoryAGet(ds, 0x1580);
    cx = memoryAGet16(ds, 0x1581);
    dx = memoryAGet16(ds, 0x1583);
    sub_9463(); // 08e1:0653
    dx = memoryAGet16(ds, 0x1581);
    sub_9357(); // 08e1:0547
    cs = pop();
}
void sub_9070() // 08e1:0260
{
    push(0x7777);
    bx = sp;
    dl = memoryAGet(ss, bx + 6);
    dh = memoryAGet(ss, bx + 4);
    dl--;
    flags.carry = (dl + memoryAGet(ds, 0x1581)) >= 0x100;
    dl += memoryAGet(ds, 0x1581);
    if (flags.carry)
        goto loc_9099;
    if (dl > memoryAGet(ds, 0x1583))
        goto loc_9099;
    dh--;
    flags.carry = (dh + memoryAGet(ds, 0x1582)) >= 0x100;
    dh += memoryAGet(ds, 0x1582);
    if (flags.carry)
        goto loc_9099;
    if (dh > memoryAGet(ds, 0x1584))
        goto loc_9099;
    sub_9357(); // 08e1:0547
loc_9099: // 08e1:0289
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_90b4() // 08e1:02a4
{
    push(0x7777);
    bx = sp;
    al = memoryAGet(ss, bx + 4);
    if (!(al & 0xf0))
        goto loc_90c2;
    al &= 0x0f;
    al |= 0x80;
loc_90c2: // 08e1:02b2
    memoryASet(ds, 0x1580, memoryAGet(ds, 0x1580) & 0x70);
    memoryASet(ds, 0x1580, memoryAGet(ds, 0x1580) | al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_90ce() // 08e1:02be
{
    push(0x7777);
    bx = sp;
    al = memoryAGet(ss, bx + 4);
    al &= 0x07;
    cl = 0x04;
    al <<= cl;
    memoryASet(ds, 0x1580, memoryAGet(ds, 0x1580) & 0x8f);
    memoryASet(ds, 0x1580, memoryAGet(ds, 0x1580) | al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_90f9() // 08e1:02e9
{
    push(0x7777);
    bx = sp;
    dx = memoryAGet16(ss, bx + 4);
    if (!dx)
        goto loc_9116;
    di = 0;
    es = di;
    al = memoryAGet(es, di);
    bx = memoryAGet16(ds, 0x158d);
loc_910e: // 08e1:02fe
    cx = bx;
    sub_9119(); // 08e1:0309
    dx--;
    if (dx != 0)
        goto loc_910e;
loc_9116: // 08e1:0306
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9119() // 08e1:0309
{
loc_9119: // 08e1:0309
    if (al != memoryAGet(es, di))
        return;
    if (--cx)
        goto loc_9119;
}
void sub_9121() // 08e1:0311
{
    push(0x7777);
    bx = sp;
    bx = memoryAGet16(ss, bx + 4);
    ax = 0x34dd;
    dx = 0x0012;
    if (dx >= bx)
        goto loc_914b;
    div(bx);
    bx = ax;
    in(al, 0x61);
    if (al & 0x03)
        goto loc_9143;
    al |= 0x03;
    out(0x61, al);
    al = 0xb6;
    out(0x43, al);
loc_9143: // 08e1:0333
    al = bl;
    out(0x42, al);
    al = bh;
    out(0x42, al);
loc_914b: // 08e1:033b
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_914e() // 08e1:033e
{
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    cs = pop();
}
void sub_9155() // 08e1:0345
{
    if (memoryAGet(ds, 0x1592) != 0x00)
        goto loc_9164;
    ah = 0x01;
    interrupt(0x16);
    al = 0x00;
    if (flags.zero)
        goto loc_9166;
loc_9164: // 08e1:0354
    al = 0x01;
loc_9166: // 08e1:0356
    cs = pop();
}
void sub_9167() // 08e1:0357
{
    al = memoryAGet(ds, 0x1592);
    memoryASet(ds, 0x1592, 0x00);
    if (al)
        goto loc_9185;
    ah = 0;
    interrupt(0x16);
    if (al)
        goto loc_9185;
    memoryASet(ds, 0x1592, ah);
    if (ah)
        goto loc_9185;
    al = 0x03;
loc_9185: // 08e1:0375
    sub_8fa0(); // 08e1:0190
    cs = pop();
}
void sub_9189() // 08e1:0379
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
    memoryASet16(ds, di + 16, 0x03a4);
    memoryASet16(ds, di + 18, cs);
    memoryASet(ds, di + 48, 0x00);
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_91b4() // 08e1:03a4
{
    push(0x7777);
    bx = sp;
    push(ds);
    di = memoryAGet16(ss, bx + 4);
    ds = memoryAGet16(ss, bx + 4 + 2);
    ax = 0x03dc;
    bx = 0x04ba;
    cx = bx;
    if (memoryAGet16(ds, di + 2) == 0xd7b1)
        goto loc_91d4;
    memoryASet16(ds, di + 2, 0xd7b2);
    ax = 0x0489;
    bx = ax;
loc_91d4: // 08e1:03c4
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
void sub_9299() // 08e1:0489
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    cx = memoryAGet16(es, di + 8);
    memoryASet16(es, di + 8, memoryAGet16(es, di + 8) - cx);
    if (cx == 0)
        goto loc_92c2;
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    if (memoryAGet(ds, 0x157c) != 0x00)
        goto loc_92bf;
loc_92b4: // 08e1:04a4
    al = memoryAGet(es, di);
    sub_92d6(); // 08e1:04c6
    di++;
    if (--cx)
        goto loc_92b4;
    goto loc_92c2;
loc_92bf: // 08e1:04af
    sub_935e(); // 08e1:054e
loc_92c2: // 08e1:04b2
    sub_8fa0(); // 08e1:0190
    ax = 0;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_92cf() // 08e1:04bf
{
    al = 0x0d;
    sub_92d6(); // 08e1:04c6
    al = 0x0a;
    push(bx);
    push(cx);
    push(dx);
    push(es);
    push(ax);
    sub_9350(); // 08e1:0540
    ax = pop();
    if (al == 0x07)
        goto loc_930d;
    if (al == 0x08)
        goto loc_9314;
    if (al == 0x0d)
        goto loc_931e;
    if (al == 0x0a)
        goto loc_9324;
    ah = 0x09;
    bl = memoryAGet(ds, 0x1580);
    bh = 0;
    cx = 0x0001;
    push(dx);
    sub_9463(); // 08e1:0653
    dx = pop();
    dl++;
    if (dl <= memoryAGet(ds, 0x1583))
        goto loc_9327;
    dl = memoryAGet(ds, 0x1581);
    goto loc_9324;
loc_930d: // 08e1:04fd
    ah = 0x0e;
    sub_9463(); // 08e1:0653
    goto loc_9327;
loc_9314: // 08e1:0504
    if (dl == memoryAGet(ds, 0x1581))
        goto loc_9327;
    dl--;
    goto loc_9327;
loc_931e: // 08e1:050e
    dl = memoryAGet(ds, 0x1581);
    goto loc_9327;
loc_9324: // 08e1:0514
    sub_932f(); // 08e1:051f
loc_9327: // 08e1:0517
    sub_9357(); // 08e1:0547
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_92d6() // 08e1:04c6
{
    push(bx);
    push(cx);
    push(dx);
    push(es);
    push(ax);
    sub_9350(); // 08e1:0540
    ax = pop();
    if (al == 0x07)
        goto loc_930d;
    if (al == 0x08)
        goto loc_9314;
    if (al == 0x0d)
        goto loc_931e;
    if (al == 0x0a)
        goto loc_9324;
    ah = 0x09;
    bl = memoryAGet(ds, 0x1580);
    bh = 0;
    cx = 0x0001;
    push(dx);
    sub_9463(); // 08e1:0653
    dx = pop();
    dl++;
    if (dl <= memoryAGet(ds, 0x1583))
        goto loc_9327;
    dl = memoryAGet(ds, 0x1581);
    goto loc_9324;
loc_930d: // 08e1:04fd
    ah = 0x0e;
    sub_9463(); // 08e1:0653
    goto loc_9327;
loc_9314: // 08e1:0504
    if (dl == memoryAGet(ds, 0x1581))
        goto loc_9327;
    dl--;
    goto loc_9327;
loc_931e: // 08e1:050e
    dl = memoryAGet(ds, 0x1581);
    goto loc_9327;
loc_9324: // 08e1:0514
    sub_932f(); // 08e1:051f
loc_9327: // 08e1:0517
    sub_9357(); // 08e1:0547
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_932f() // 08e1:051f
{
    dh++;
    if (dh <= memoryAGet(ds, 0x1584))
        return;
    dh--;
    push(cx);
    push(dx);
    ax = 0x0601;
    bh = memoryAGet(ds, 0x1580);
    cx = memoryAGet16(ds, 0x1581);
    dx = memoryAGet16(ds, 0x1583);
    sub_9463(); // 08e1:0653
    dx = pop();
    cx = pop();
}
void sub_9350() // 08e1:0540
{
    ah = 0x03;
    bh = 0;
    goto loc_9463;
    //   gap of 268 bytes
loc_9463: // 08e1:0653
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
void sub_9357() // 08e1:0547
{
    ah = 0x02;
    bh = 0;
    goto loc_9463;
    //   gap of 261 bytes
loc_9463: // 08e1:0653
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
void sub_935e() // 08e1:054e
{
    push(ds);
    ax = 0x0040;
    ds = ax;
    dx = memoryAGet16(ds, 0x0050);
    ds = pop();
    bx = dx;
    si = di;
loc_936d: // 08e1:055d
    al = memoryAGet(es, di);
    if (al == 0x07)
        goto loc_9395;
    if (al == 0x08)
        goto loc_93a4;
    if (al == 0x0a)
        goto loc_93b1;
    if (al == 0x0d)
        goto loc_93b9;
    di++;
    dl++;
    if (dl <= memoryAGet(ds, 0x1583))
        goto loc_93c5;
    sub_93fb(); // 08e1:05eb
    sub_932f(); // 08e1:051f
    dl = memoryAGet(ds, 0x1581);
    goto loc_93c1;
loc_9395: // 08e1:0585
    sub_93fb(); // 08e1:05eb
    push(cx);
    push(dx);
    ax = 0x0e07;
    sub_9463(); // 08e1:0653
    dx = pop();
    cx = pop();
    goto loc_93c0;
loc_93a4: // 08e1:0594
    sub_93fb(); // 08e1:05eb
    if (dl == memoryAGet(ds, 0x1581))
        goto loc_93c0;
    dl--;
    goto loc_93c0;
loc_93b1: // 08e1:05a1
    sub_93fb(); // 08e1:05eb
    sub_932f(); // 08e1:051f
    goto loc_93c0;
loc_93b9: // 08e1:05a9
    sub_93fb(); // 08e1:05eb
    dl = memoryAGet(ds, 0x1581);
loc_93c0: // 08e1:05b0
    di++;
loc_93c1: // 08e1:05b1
    si = di;
    bx = dx;
loc_93c5: // 08e1:05b5
    if (--cx)
        goto loc_936d;
    sub_93fb(); // 08e1:05eb
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
void sub_93fb() // 08e1:05eb
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
    dl = memoryAGet(ds, 0x157d);
    dh = memoryAGet(ds, 0x1580);
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
        goto loc_9438;
    ah = 0xb0;
loc_9438: // 08e1:0628
    push(es);
    ds = pop();
    es = ax;
    flags.direction = false;
    if (!bl)
        goto loc_9457;
loc_9441: // 08e1:0631
    lodsb<MemData, DirForward>();
    bl = al;
loc_9444: // 08e1:0634
    in(al, dx);
    if (al & 0x01)
        goto loc_9444;
    flags.interrupts = false;
loc_944a: // 08e1:063a
    in(al, dx);
    if (!(al & 0x01))
        goto loc_944a;
    ax = bx;
    stosw<MemData, DirForward>();
    flags.interrupts = true;
    if (--cx)
        goto loc_9441;
    goto loc_945d;
loc_9457: // 08e1:0647
    ah = bh;
loc_9459: // 08e1:0649
    lodsb<MemData, DirForward>();
    stosw<MemVideo, DirForward>();
    if (--cx)
        goto loc_9459;
loc_945d: // 08e1:064d
    es = pop();
    ds = pop();
    di = pop();
    dx = pop();
    cx = pop();
}
void sub_9463() // 08e1:0653
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
void sub_9470() // 0947:0000
{
    push(0x7777);
    dx = 0x0ac3;
    ds = dx;
    memoryASet16(ds, 0x1794, es);
    ax = sp;
    ax += 0x0013;
    cl = 0x04;
    ax >>= cl;
    dx = ss;
    ax += dx;
    memoryASet16(ds, 0x1798, ax);
    memoryASet16(ds, 0x179c, ax);
    ax = memoryAGet16(es, 0x0002);
    ax -= 0x1000;
    memoryASet16(ds, 0x17a0, ax);
    memoryASet16(ds, 0x17a4, 0x00dd);
    memoryASet16(ds, 0x17a6, cs);
    memoryASet16(ds, 0x17a8, 0x00e2);
    memoryASet16(ds, 0x17aa, cs);
    memoryASet(ds, 0x17ca, 0x02);
    ax = 0;
    memoryASet16(ds, 0x1796, ax);
    memoryASet16(ds, 0x179a, ax);
    memoryASet16(ds, 0x179e, ax);
    memoryASet16(ds, 0x17a2, ax);
    memoryASet16(ds, 0x17b2, ax);
    memoryASet16(ds, 0x17b4, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x17b6, bx);
    memoryASet16(ds, 0x17b8, es);
    ax = 0x3502;
    interrupt(0x21);
    memoryASet16(ds, 0x17ba, bx);
    memoryASet16(ds, 0x17bc, es);
    ax = 0x3523;
    interrupt(0x21);
    memoryASet16(ds, 0x17be, bx);
    memoryASet16(ds, 0x17c0, es);
    ax = 0x3524;
    interrupt(0x21);
    memoryASet16(ds, 0x17c2, bx);
    memoryASet16(ds, 0x17c4, es);
    ax = 0x3575;
    interrupt(0x21);
    memoryASet16(ds, 0x17c6, bx);
    memoryASet16(ds, 0x17c8, es);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x01e9;
    ax = 0x2500;
    interrupt(0x21);
    dx = 0x01f0;
    ax = 0x2523;
    interrupt(0x21);
    dx = 0x01bf;
    ax = 0x2524;
    interrupt(0x21);
    ds = pop();
    ax = 0x1594;
    push(ds);
    push(ax);
    push(ds);
    push(ax);
    ax = 0x00dc;
    push(cs);
    push(ax);
    push(cs);
    sub_a6a9(); // 0947:1239
    push(cs);
    sub_a719(); // 0947:12a9
    ax = 0x1694;
    push(ds);
    push(ax);
    push(ds);
    push(ax);
    ax = 0x00dc;
    push(cs);
    push(ax);
    push(cs);
    sub_a6a9(); // 0947:1239
    push(cs);
    sub_a71e(); // 0947:12ae
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_962f() // 0947:01bf
{
    flags.interrupts = true;
    sp += 0x0006;
    ax = pop();
    di &= 0x001f;
    di += 0x0096;
    if (ah >= 0x39)
        goto loc_9644;
    di = 0xffff;
loc_9644: // 0947:01d4
    push(di);
    ah = 0x54;
    interrupt(0x21);
    bp = sp;
    memoryASet(ss, bp + 22, memoryAGet(ss, bp + 22) | 0x01);
    ax = pop();
    bx = pop();
    cx = pop();
    dx = pop();
    si = pop();
    di = pop();
    bp = pop();
    ds = pop();
    es = pop();
    stop(); // iret 
}
void sub_9660() // 0947:01f0
{
    ax = 0x00ff;
    cx = 0;
    bx = 0;
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
}
void sub_9663() // 0947:01f3
{
    cx = 0;
    bx = 0;
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
}
void sub_971d() // 0947:02ad
{
    push(0x7777);
    goto loc_971d;
loc_965c: // 0947:01ec
    stop(/*override stack*/); // 0947:01ec
    cx = pop();
    bx = pop();
    goto loc_9667;
    //   gap of 7 bytes
loc_9667: // 0947:01f7
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 64 bytes
loc_971d: // 0947:02ad
    si = sp;
    tx = si;
    si -= ax;
    if (tx < ax)
        goto loc_972a;
    if (si < 0x0200)
        goto loc_972a;
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_972a: // 0947:02ba
    ax = 0x00ca;
    goto loc_965c;
}
void sub_9730() // 0947:02c0
{
    push(0x7777);
    goto loc_9730;
loc_965c: // 0947:01ec
    stop(/*override stack*/); // 0947:01ec
    cx = pop();
    bx = pop();
    goto loc_9667;
    //   gap of 7 bytes
loc_9667: // 0947:01f7
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 83 bytes
loc_9730: // 0947:02c0
    push(bp);
    bp = sp;
loc_9733: // 0947:02c3
    ax = memoryAGet16(ss, bp + 6);
    sub_9844(); // 0947:03d4
    if (!flags.carry)
        goto loc_974d;
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = memoryAGet16(ds, 0x17a4 + 2);
    callIndirect(memoryAGet16(ds, 0x17a4 + 2), memoryAGet16(ds, 0x17a4));
    assert(cs == 0x0947);
    if (!ax)
        goto loc_975b;
    ax--;
    if (ax != 0)
        goto loc_9733;
    cx = 0;
    bx = 0;
loc_974d: // 0947:02dd
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, di, cx);
    memoryASet16(es, di + 2, bx);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
    return;
loc_975b: // 0947:02eb
    bp = pop();
    ax = 0x00cb;
    goto loc_965c;
}
void sub_97f7() // 0947:0387
{
    sub_99cc(); // 0947:055c
    ax = si;
    dx = di;
    di = memoryAGet16(ds, 0x179e);
    es = memoryAGet16(ds, 0x179e + 2);
    dx -= memoryAGet16(ds, 0x179c);
    flags.carry = ax < memoryAGet16(ds, 0x179a);
    ax -= memoryAGet16(ds, 0x179a);
    if (!flags.carry)
        goto loc_983c;
    ax += 0x0010;
    dx--;
    goto loc_983c;
loc_9812: // 0947:03a2
    bx = memoryAGet16(es, di + 6);
    bx -= memoryAGet16(es, di + 2);
    if (bx < dx)
        goto loc_9839;
    cx = memoryAGet16(es, di + 4);
    flags.carry = cx < memoryAGet16(es, di);
    cx -= memoryAGet16(es, di);
    if (!flags.carry)
        goto loc_982b;
    cx += 0x0010;
    bx--;
loc_982b: // 0947:03bb
    if (bx > dx)
        goto loc_9835;
    if (bx < dx)
        goto loc_9839;
    if (cx < ax)
        goto loc_9839;
loc_9835: // 0947:03c5
    ax = cx;
    dx = bx;
loc_9839: // 0947:03c9
    di += 0x0008;
loc_983c: // 0947:03cc
    if (di)
        goto loc_9812;
    sub_9a24(); // 0947:05b4
    cs = pop();
}
void sub_9844() // 0947:03d4+carry
{
    sub_9a16(); // 0947:05a6
    di = memoryAGet16(ds, 0x179e);
    es = memoryAGet16(ds, 0x179e + 2);
    goto loc_985c;
loc_984d: // 0947:03dd
    bx = memoryAGet16(es, di + 6);
    bx -= memoryAGet16(es, di + 2);
    if (bx >= dx)
        goto loc_989d;
loc_9859: // 0947:03e9
    di += 0x0008;
loc_985c: // 0947:03ec
    if (di)
        goto loc_984d;
    sub_99cc(); // 0947:055c
    cx = si;
    bx = di;
    bx -= memoryAGet16(ds, 0x179c);
    flags.carry = cx < memoryAGet16(ds, 0x179a);
    cx -= memoryAGet16(ds, 0x179a);
    if (!flags.carry)
        goto loc_9875;
    cx += 0x0010;
    bx--;
loc_9875: // 0947:0405
    flags.carry = bx < dx;
    if (bx > dx)
        goto loc_987f;
    if (bx < dx)
        goto loc_989c;
    flags.carry = cx < ax;
    if (cx < ax)
        goto loc_989c;
loc_987f: // 0947:040f
    cx = memoryAGet16(ds, 0x179a);
    bx = memoryAGet16(ds, 0x179c);
    dx += bx;
    ax += cx;
    if (ax < 0x0010)
        goto loc_9894;
    ax -= 0x0010;
    dx++;
loc_9894: // 0947:0424
    memoryASet16(ds, 0x179a, ax);
    memoryASet16(ds, 0x179c, dx);
    flags.carry = false;
loc_989c: // 0947:042c
    return;
loc_989d: // 0947:042d
    cx = memoryAGet16(es, di + 4);
    flags.carry = cx < memoryAGet16(es, di);
    cx -= memoryAGet16(es, di);
    if (!flags.carry)
        goto loc_98aa;
    cx += 0x0010;
    bx--;
loc_98aa: // 0947:043a
    if (bx > dx)
        goto loc_98b4;
    if (bx < dx)
        goto loc_9859;
    if (cx < ax)
        goto loc_9859;
loc_98b4: // 0947:0444
    cx = memoryAGet16(es, di);
    bx = memoryAGet16(es, di + 2);
    dx += bx;
    ax += cx;
    if (ax < 0x0010)
        goto loc_98c8;
    ax -= 0x0010;
    dx++;
loc_98c8: // 0947:0458
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 2, dx);
    if (dx != memoryAGet16(es, di + 6))
        goto loc_98de;
    if (ax != memoryAGet16(es, di + 4))
        goto loc_98de;
    sub_99b7(); // 0947:0547
loc_98de: // 0947:046e
    flags.carry = false;
}
void sub_99b7() // 0947:0547
{
    si = memoryAGet16(ds, 0x179e);
    flags.direction = false;
    movsw<MemData, MemData, DirForward>();
    movsw<MemData, MemData, DirForward>();
    movsw<MemData, MemData, DirForward>();
    movsw<MemData, MemData, DirForward>();
    di -= 0x0008;
    memoryASet16(ds, 0x179e, si);
}
void sub_99cc() // 0947:055c
{
    di = memoryAGet16(ds, 0x179e);
    if (di)
        goto loc_99e5;
    di -= memoryAGet16(ds, 0x17a2);
    if (di != 0)
        goto loc_99ed;
    si = 0;
    di = memoryAGet16(ds, 0x17a0);
    di += 0x1000;
    return;
loc_99e5: // 0947:0575
    flags.carry = di < memoryAGet16(ds, 0x17a2);
    di -= memoryAGet16(ds, 0x17a2);
    if (!flags.carry)
        goto loc_99ed;
    di = 0;
loc_99ed: // 0947:057d
    si = di;
    si &= 0x000f;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di += memoryAGet16(ds, 0x17a0);
    if (di > memoryAGet16(ds, 0x179c))
        return;
    if (di < memoryAGet16(ds, 0x179c))
        goto loc_9a0d;
    if (si >= memoryAGet16(ds, 0x179a))
        return;
loc_9a0d: // 0947:059d
    si = memoryAGet16(ds, 0x179a);
    di = memoryAGet16(ds, 0x179c);
}
void sub_9a16() // 0947:05a6
{
    dx = ax;
    ax &= 0x000f;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
}
void sub_9a24() // 0947:05b4
{
    cl = 0x04;
    dx = rol(dx, cl);
    cx = dx;
    cx &= 0xfff0;
    dx &= 0x000f;
    ax |= cx;
}
void sub_9a4f() // 0947:05df
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
    lodsb<MemData, DirForward>();
    if (al <= cl)
        goto loc_9a67;
    al = cl;
loc_9a67: // 0947:05f7
    stosb<MemData, DirForward>();
    cl = al;
    ch = 0;
    rep_movsb<MemData, MemData, DirForward>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_9ac2() // 0947:0652
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
    lodsb<MemData, DirForward>();
    flags.carry = (memoryAGet(es, di) + al) >= 0x100;
    memoryASet(es, di, memoryAGet(es, di) + al);
    if (!flags.carry)
        goto loc_9ae2;
    memoryASet(es, di, 0xff);
    al = cl;
    al = ~al;
loc_9ae2: // 0947:0672
    di += cx;
    di++;
    cl = al;
    rep_movsb<MemData, MemData, DirForward>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
// INJECT: Error: cannot inject zero flag in sub_9b25()!
void sub_9b25() // 0947:06b5+zero
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    dx = ds;
    si = memoryAGet16(ss, bx + 8);
    ds = memoryAGet16(ss, bx + 8 + 2);
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    lodsb<MemData, DirForward>();
    ah = memoryAGet(es, di);
    di++;
    cl = al;
    if (cl <= ah)
        goto loc_9b3f;
    cl = ah;
loc_9b3f: // 0947:06cf
    flags.zero = !cl;
    if (!cl)
        goto loc_9b49;
    ch = 0;
    repe_cmpsb<MemData, MemData, DirForward>();
    if (!flags.zero)
        goto loc_9b4b;
loc_9b49: // 0947:06d9
    flags.zero = al == ah;
loc_9b4b: // 0947:06db
    ds = dx;
    //stop(/*inject ret*/);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_9b50() // 0947:06e0
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    al = 0x01;
    stosb<MemData, DirForward>();
    al = memoryAGet(ss, bx + 4);
    stosb<MemData, DirForward>();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9c51() // 0947:07e1
{
    push(0x7777);
    flags.direction = false;
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    cx = 0x0010;
    ax = 0;
    rep_stosw<MemData, DirForward>();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_9c60() // 0947:07f0
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 6);
    es = memoryAGet16(ss, bx + 6 + 2);
    al = memoryAGet(ss, bx + 4);
    bl = al;
    bh = 0;
    cl = 0x03;
    bx >>= cl;
    cl = al;
    cl &= 0x07;
    al = 0x01;
    al <<= cl;
    memoryASet(es, bx + di, memoryAGet(es, bx + di) | al);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_9c81() // 0947:0811
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    al = memoryAGet(ss, bx + 6);
    dl = memoryAGet(ss, bx + 4);
    tl = dl;
    dl -= al;
    if (tl < al)
        goto loc_9cb2;
    dl++;
    bl = al;
    bh = 0;
    cl = 0x03;
    bx >>= cl;
    cl = al;
    cl &= 0x07;
    al = 0x01;
    al <<= cl;
loc_9ca6: // 0947:0836
    memoryASet(es, bx + di, memoryAGet(es, bx + di) | al);
    flags.carry = !!(al & 0x80);
    al = rol(al, 0x01);
    bx += flags.carry;
    dl--;
    if (dl != 0)
        goto loc_9ca6;
loc_9cb2: // 0947:0842
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_9cd5() // 0947:0865+zero
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
void sub_9d7d() // 0947:090d
{
    di ^= 0x8000;
    if (!cl)
        goto loc_9d8f;
    if (al)
        goto loc_9d90;
loc_9d89: // 0947:0919
    ax = cx;
    bx = si;
    dx = di;
loc_9d8f: // 0947:091f
    return;
loc_9d90: // 0947:0920
    if (al <= cl)
        goto loc_9d99;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = dx;
    dx = tx;
loc_9d99: // 0947:0929
    al -= cl;
    al = -al;
    if (al >= 0x28)
        goto loc_9d89;
    tl = cl;
    cl = al;
    al = tl;
    push(bp);
    bp = di;
    bp ^= dx;
    tx = flags.carry | (flags.zero << 1) | (bp & 0x8000);
    push(tx);
    bp = di;
    dh |= 0x80;
    di |= 0x8000;
loc_9db2: // 0947:0942
    if (cl < 0x10)
        goto loc_9dc2;
    ah = bh;
    bx = dx;
    dx = 0;
    cl -= 0x10;
    goto loc_9db2;
loc_9dc2: // 0947:0952
    if (cl < 0x08)
        goto loc_9dd4;
    ah = bl;
    bl = bh;
    bh = dl;
    dl = dh;
    dh = 0;
    cl -= 0x08;
loc_9dd4: // 0947:0964
    if (!cl)
        goto loc_9de2;
loc_9dd8: // 0947:0968
    flags.carry = dx & 1;
    dx >>= 1;
    bx = rcr(bx, 0x0001);
    ah = rcr(ah, 0x01);
    cl--;
    if (cl != 0)
        goto loc_9dd8;
loc_9de2: // 0947:0972
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (tx & 0x8000)
        goto loc_9dfa;
    flags.carry = (ah + ch) >= 0x100;
    ah += ch;
    tl = flags.carry;
    flags.carry = (bx + si + tl) >= 0x10000;
    bx += si + tl;
    tl = flags.carry;
    flags.carry = (dx + di + tl) >= 0x10000;
    dx += di + tl;
    if (!flags.carry)
        goto loc_9e4c;
    dx = rcr(dx, 0x0001);
    bx = rcr(bx, 0x0001);
    ah = rcr(ah, 0x01);
    al++;
    if (al != 0)
        goto loc_9e4c;
    flags.carry = true;
    bp = pop();
    return;
loc_9dfa: // 0947:098a
    tl = ch;
    ch = ah;
    ah = tl;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = dx;
    dx = tx;
    flags.carry = ah < ch;
    ah -= ch;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = dx < di + flags.carry;
    dx -= di + flags.carry;
    flags.carry = tl;
    if (!flags.carry)
        goto loc_9e1b;
    bp ^= 0x8000;
    ah = ~ah;
    bx = ~bx;
    dx = ~dx;
    flags.carry = (ah + 0x01) >= 0x100;
    ah += 0x01;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    dx += flags.carry;
loc_9e1b: // 0947:09ab
    cl = 0x05;
loc_9e1d: // 0947:09ad
    if (dh)
        goto loc_9e35;
    dh = dl;
    dl = bh;
    bh = bl;
    bl = ah;
    ah = 0;
    tl = al;
    al -= 0x08;
    if (tl <= 0x08)
        goto loc_9e44;
    cl--;
    if (cl != 0)
        goto loc_9e1d;
    goto loc_9e44;
loc_9e35: // 0947:09c5
    if (dh & 0x80)
        goto loc_9e4c;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    al--;
    if (al != 0)
        goto loc_9e35;
loc_9e44: // 0947:09d4
    ax = 0;
    bx = 0;
    dx = 0;
    bp = pop();
    return;
loc_9e4c: // 0947:09dc
    dh &= 0x7f;
    bp &= 0x8000;
    dx ^= bp;
    bp = pop();
}
void sub_9d81() // 0947:0911
{
    if (!cl)
        goto loc_9d8f;
    if (al)
        goto loc_9d90;
loc_9d89: // 0947:0919
    ax = cx;
    bx = si;
    dx = di;
loc_9d8f: // 0947:091f
    return;
loc_9d90: // 0947:0920
    if (al <= cl)
        goto loc_9d99;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = dx;
    dx = tx;
loc_9d99: // 0947:0929
    al -= cl;
    al = -al;
    if (al >= 0x28)
        goto loc_9d89;
    tl = cl;
    cl = al;
    al = tl;
    push(bp);
    bp = di;
    bp ^= dx;
    tx = flags.carry | (flags.zero << 1) | (bp & 0x8000);
    push(tx);
    bp = di;
    dh |= 0x80;
    di |= 0x8000;
loc_9db2: // 0947:0942
    if (cl < 0x10)
        goto loc_9dc2;
    ah = bh;
    bx = dx;
    dx = 0;
    cl -= 0x10;
    goto loc_9db2;
loc_9dc2: // 0947:0952
    if (cl < 0x08)
        goto loc_9dd4;
    ah = bl;
    bl = bh;
    bh = dl;
    dl = dh;
    dh = 0;
    cl -= 0x08;
loc_9dd4: // 0947:0964
    if (!cl)
        goto loc_9de2;
loc_9dd8: // 0947:0968
    flags.carry = dx & 1;
    dx >>= 1;
    bx = rcr(bx, 0x0001);
    ah = rcr(ah, 0x01);
    cl--;
    if (cl != 0)
        goto loc_9dd8;
loc_9de2: // 0947:0972
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (tx & 0x8000)
        goto loc_9dfa;
    flags.carry = (ah + ch) >= 0x100;
    ah += ch;
    tl = flags.carry;
    flags.carry = (bx + si + tl) >= 0x10000;
    bx += si + tl;
    tl = flags.carry;
    flags.carry = (dx + di + tl) >= 0x10000;
    dx += di + tl;
    if (!flags.carry)
        goto loc_9e4c;
    dx = rcr(dx, 0x0001);
    bx = rcr(bx, 0x0001);
    ah = rcr(ah, 0x01);
    al++;
    if (al != 0)
        goto loc_9e4c;
    flags.carry = true;
    bp = pop();
    return;
loc_9dfa: // 0947:098a
    tl = ch;
    ch = ah;
    ah = tl;
    tx = si;
    si = bx;
    bx = tx;
    tx = di;
    di = dx;
    dx = tx;
    flags.carry = ah < ch;
    ah -= ch;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = dx < di + flags.carry;
    dx -= di + flags.carry;
    flags.carry = tl;
    if (!flags.carry)
        goto loc_9e1b;
    bp ^= 0x8000;
    ah = ~ah;
    bx = ~bx;
    dx = ~dx;
    flags.carry = (ah + 0x01) >= 0x100;
    ah += 0x01;
    tl = flags.carry;
    flags.carry = (bx + 0x0000 + tl) >= 0x10000;
    bx += tl;
    dx += flags.carry;
loc_9e1b: // 0947:09ab
    cl = 0x05;
loc_9e1d: // 0947:09ad
    if (dh)
        goto loc_9e35;
    dh = dl;
    dl = bh;
    bh = bl;
    bl = ah;
    ah = 0;
    tl = al;
    al -= 0x08;
    if (tl <= 0x08)
        goto loc_9e44;
    cl--;
    if (cl != 0)
        goto loc_9e1d;
    goto loc_9e44;
loc_9e35: // 0947:09c5
    if (dh & 0x80)
        goto loc_9e4c;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    al--;
    if (al != 0)
        goto loc_9e35;
loc_9e44: // 0947:09d4
    ax = 0;
    bx = 0;
    dx = 0;
    bp = pop();
    return;
loc_9e4c: // 0947:09dc
    dh &= 0x7f;
    bp &= 0x8000;
    dx ^= bp;
    bp = pop();
}
void sub_9ed4() // 0947:0a64
{
    push(0x7777);
    if (!al)
        goto loc_9f17;
    al -= cl;
    flags.carry = !flags.carry;
    sub_9f5d(); // 0947:0aed
    if (flags.zero || flags.carry)
        goto loc_9f17;
    push(bp);
    push(cx);
    sp -= 0x0004;
    push(ax);
    bp = sp;
    bp += 0x0005;
    cl = 0x08;
loc_9eed: // 0947:0a7d
    flags.carry = dx < di;
    if (dx != di)
        goto loc_9ef7;
    flags.carry = bx < si;
    if (bx != si)
        goto loc_9ef7;
loc_9ef7: // 0947:0a87
    if (flags.carry)
        goto loc_9eff;
    flags.carry = ah < ch;
    ah -= ch;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    tl = dx < di + flags.carry; // TODO CICO
    dx -= di + flags.carry;
    flags.carry = tl; // TODO CICO
loc_9eff: // 0947:0a8f
    flags.carry = !flags.carry;
loc_9f00: // 0947:0a90
    al = rcl(al, 0x01);
    cl--;
    if (cl == 0)
        goto loc_9f18;
loc_9f06: // 0947:0a96
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    if (!flags.carry)
        goto loc_9eed;
    flags.carry = ah < ch;
    ah -= ch;
    tl = bx < si + flags.carry;
    bx -= si + flags.carry;
    flags.carry = tl;
    dx -= di + flags.carry;
    flags.carry = true;
    goto loc_9f00;
loc_9f17: // 0947:0aa7
    assert(pop() == 0x7777);
    return;
loc_9f18: // 0947:0aa8
    memoryASet(ss, bp, al);
    cl = 0x08;
    bp--;
    if (bp != sp)
        goto loc_9f06;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    if (flags.carry)
        goto loc_9f35;
    if (dx != di)
        goto loc_9f34;
    if (bx != si)
        goto loc_9f34;
loc_9f34: // 0947:0ac4
    flags.carry = !flags.carry;
loc_9f35: // 0947:0ac5
    si = rcl(si, 0x0001);
    ax = pop();
    bx = pop();
    dx = pop();
    cx = pop();
    bp = pop();
    if (dh & 0x80)
        goto loc_9f4b;
    si = rcr(si, 0x0001);
    ah = rcl(ah, 0x01);
    bx = rcl(bx, 0x0001);
    dx = rcl(dx, 0x0001);
    goto loc_9f50;
loc_9f4b: // 0947:0adb
    al++;
    flags.carry = true;
    if (al == 0)
        goto loc_9f5c;
loc_9f50: // 0947:0ae0
    dh ^= cl;
    if (al)
        goto loc_9f5c;
    ax = 0;
    bx = 0;
    dx = 0;
loc_9f5c: // 0947:0aec
    assert(pop() == 0x7777);
}
// INJECT: Error: cannot inject zero flag in sub_9f5d()!
// INJECT: Error: cannot inject carry flag in sub_9f5d()!
void sub_9f5d() // 0947:0aed+zero
{
    if (flags.carry)
        goto loc_9f6a;
    flags.carry = (al + 0x80) >= 0x100;
    al += 0x80;
    if (flags.carry)
        goto loc_9f6e;
    ax = 0;
    bx = 0;
    flags.carry = false;
    dx = 0;
    flags.zero = true;
    return;
loc_9f6a: // 0947:0afa
    flags.carry = (al + 0x80) >= 0x100;
    al += 0x80;
    if (flags.carry)
        goto loc_9f7f;
loc_9f6e: // 0947:0afe
    tx = di;
    di = ax;
    ax = tx;
    cl = ah;
    cl ^= dh;
    cl = ~cl;
    cl &= 0x80;
    ah |= 0x80;
    dh |= 0x80;
    tx = di;
    di = ax;
    ax = tx;
    flags.zero = false;
loc_9f7f: // 0947:0b0f
    return;
}
void sub_9faa() // 0947:0b3a
{
    bx = ax;
    bx |= dx;
    if (!bx)
        return;
    ch = dh;
    if (!(dx & 0x8000))
        goto loc_9fc0;
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_9fc0: // 0947:0b50
    bx = ax;
    ax = 0x00a0;
    if (dx)
        goto loc_9fd5;
    tx = bx;
    bx = dx;
    dx = tx;
    al = 0x90;
    if (dh)
        goto loc_9fd5;
    tl = dl;
    dl = dh;
    dh = tl;
    al = 0x88;
loc_9fd5: // 0947:0b65
    if (dx & 0x8000)
        goto loc_9fe1;
loc_9fd9: // 0947:0b69
    al--;
    flags.carry = (bx + bx) >= 0x10000;
    bx += bx;
    dx += dx + flags.carry;
    if ((short)dx >= 0)
        goto loc_9fd9;
loc_9fe1: // 0947:0b71
    if (ch & 0x80)
        return;
    dh &= 0x7f;
}
void sub_9fe9() // 0947:0b79+carry
{
    tx = bx;
    bx = ax;
    ax = tx;
    cl = 0x9f;
    tl = cl;
    cl -= bl;
    if (tl < bl)
        goto loc_a03e;
    flags.carry = false;
    if (cl > 0x1f)
        goto loc_a040;
    cl++;
    bh = dh;
    dh |= 0x80;
    if (cl < 0x11)
        goto loc_a008;
    ax = dx;
    dx = 0;
    cl -= 0x10;
loc_a008: // 0947:0b98
    if (cl < 0x09)
        goto loc_a018;
    al = ah;
    ah = dl;
    dl = dh;
    dh = 0;
    cl -= 0x08;
loc_a018: // 0947:0ba8
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = cl == 0;
    cl--;
    if (cl != 0)
        goto loc_a018;
    if (!flags.carry)
        goto loc_a02e;
    if (!ch)
        goto loc_a02e;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    if ((short)dx < 0)
        goto loc_a03e;
loc_a02e: // 0947:0bbe
    if (!(bh & 0x80))
        goto loc_a03c;
    ax = ~ax;
    dx = ~dx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
loc_a03c: // 0947:0bcc
    flags.carry = false;
    return;
loc_a03e: // 0947:0bce
    flags.carry = true;
    return;
loc_a040: // 0947:0bd0
    ax = 0;
    flags.carry = false;
    dx = 0;
}
void sub_a06b() // 0947:0bfb
{
    sub_9faa(); // 0947:0b3a
    cs = pop();
}
void sub_a06f() // 0947:0bff
{
    goto loc_a06f;
loc_965c: // 0947:01ec
    stop(/*override stack*/); // 0947:01ec
    cx = pop();
    bx = pop();
    goto loc_9667;
    //   gap of 7 bytes
loc_9667: // 0947:01f7
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2450 bytes
loc_a06f: // 0947:0bff
    ch = 0x00;
    sub_9fe9(); // 0947:0b79
    if (flags.carry)
        goto loc_a07f;
    cs = pop();
    return;
    //   gap of 8 bytes
loc_a07f: // 0947:0c0f
    ax = 0x00cf;
    goto loc_965c;
}
void sub_a091() // 0947:0c21
{
    push(di);
    push(si);
    push(cx);
    sub_9d81(); // 0947:0911
    cx = pop();
    si = pop();
    di = pop();
}
void sub_a0af() // 0947:0c3f
{
    push(di);
    push(si);
    push(cx);
    sub_9ed4(); // 0947:0a64
    cx = pop();
    si = pop();
    di = pop();
}
void sub_a11e() // 0947:0cae
{
    push(0x7777);
    goto loc_a11e;
loc_965c: // 0947:01ec
    stop(/*override stack*/); // 0947:01ec
    cx = pop();
    bx = pop();
    goto loc_9667;
    //   gap of 7 bytes
loc_9667: // 0947:01f7
    dx = 0x0ac3;
    ds = dx;
    dx = cx;
    dx |= bx;
    if (!dx)
        goto loc_9679;
    bx -= memoryAGet16(ds, 0x1794);
    bx -= 0x0010;
loc_9679: // 0947:0209
    es = memoryAGet16(ds, 0x1794);
    if (memoryAGet(es, 0x0005) == 0xc3)
        goto loc_9692;
    es = memoryAGet16(es, 0x0016);
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_9697;
loc_9692: // 0947:0222
    push(cs);
    cs = memoryAGet16(es, 0x0006 + 2);
    callIndirect(memoryAGet16(es, 0x0006 + 2), memoryAGet16(es, 0x0006));
    assert(cs == 0x0947);
loc_9697: // 0947:0227
    memoryASet16(ds, 0x17ac, ax);
    memoryASet16(ds, 0x17ae, cx);
    memoryASet16(ds, 0x17b0, bx);
    bx = memoryAGet16(ds, 0x17a8);
    es = memoryAGet16(ds, 0x17a8 + 2);
    ax = es;
    ax |= bx;
    if (!ax)
        goto loc_96bf;
    ax = 0;
    memoryASet16(ds, 0x17a8, ax);
    memoryASet16(ds, 0x17aa, ax);
    memoryASet16(ds, 0x17cb, ax);
    ax = 0x0232;
    push(cs);
    push(ax);
    push(es);
    push(bx);
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_96bf: // 0947:024f
    es = memoryAGet16(ds, 0x1794);
    flags.carry = memoryAGet(es, 0x0005) < 0xc3;
    if (memoryAGet(es, 0x0005) != 0xc3)
        goto loc_96d6;
    memoryASet(es, 0x0005, 0x00);
    daa();
loc_96d6: // 0947:0266
    ax = memoryAGet16(ds, 0x17ac);
    ah = 0x4c;
    interrupt(0x21);
    //   gap of 2625 bytes
loc_a11e: // 0947:0cae
    push(bp);
    bp = sp;
    sp -= 0x0008;
    cx = ax;
    si = bx;
    di = dx;
    if (!al)
        goto loc_a16a;
    if (dh & 0x80)
        goto loc_a174;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, bx);
    memoryASet16(ss, bp - 4, dx);
    cl += 0x80;
    cl = sar(cl, 1);
    cl += 0x80;
    al = cl;
    al -= 0x14;
    memoryASet(ss, bp - 2, al);
loc_a14b: // 0947:0cdb
    ax = memoryAGet16(ss, bp - 8);
    bx = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 4);
    sub_a0af(); // 0947:0c3f
    sub_a091(); // 0947:0c21
    al--;
    push(dx);
    push(bx);
    push(ax);
    sub_9d7d(); // 0947:090d
    cx = pop();
    si = pop();
    di = pop();
    if (al >= memoryAGet(ss, bp - 2))
        goto loc_a14b;
loc_a16a: // 0947:0cfa
    ax = cx;
    bx = si;
    dx = di;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_a174: // 0947:0d04
    sp = bp;
    bp = pop();
    ax = 0x00cf;
    goto loc_965c;
}
void sub_a504() // 0947:1094
{
    push(0x7777);
    sub_a552(); // 0947:10e2
    ax = 0;
    bx = sp;
    bx = memoryAGet16(ss, bx + 4);
    if (!bx)
        goto loc_a517;
    tx = dx;
    dx = ax;
    ax = tx;
    div(bx);
    tx = dx;
    dx = ax;
    ax = tx;
loc_a517: // 0947:10a7
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_a552() // 0947:10e2
{
    ax = memoryAGet16(ds, 0x17b2);
    bx = memoryAGet16(ds, 0x17b4);
    cx = ax;
    mul(memoryAGet16(cs, 0x1118));
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
    memoryASet16(ds, 0x17b2, ax);
    memoryASet16(ds, 0x17b4, dx);
}
void sub_a58a() // 0947:111a
{
    ah = 0x2c;
    interrupt(0x21);
    memoryASet16(ds, 0x17b2, cx);
    memoryASet16(ds, 0x17b4, dx);
    cs = pop();
}
void sub_a597() // 0947:1127
{
    push(di);
    flags.direction = false;
    bx = ax;
    if ((short)dx >= 0)
        goto loc_a5ac;
    bx = ~bx;
    dx = ~dx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    dx += flags.carry;
    al = 0x2d;
    stosb<MemData, DirForward>();
loc_a5ac: // 0947:113c
    si = 0x1179;
    cl = 0x09;
loc_a5b1: // 0947:1141
    if (dx < memoryAGet16(cs, si + 2))
        goto loc_a5be;
    if (dx > memoryAGet16(cs, si + 2))
        goto loc_a5c5;
    if (bx >= memoryAGet16(cs, si))
        goto loc_a5c5;
loc_a5be: // 0947:114e
    si += 0x0004;
    cl--;
    if (cl != 0)
        goto loc_a5b1;
loc_a5c5: // 0947:1155
    cl++;
loc_a5c7: // 0947:1157
    al = 0x2f;
loc_a5c9: // 0947:1159
    al++;
    flags.carry = bx < memoryAGet16(cs, si);
    bx -= memoryAGet16(cs, si);
    tl = dx < memoryAGet16(cs, si + 2) + flags.carry;
    dx -= memoryAGet16(cs, si + 2) + flags.carry;
    flags.carry = tl;
    if (!flags.carry)
        goto loc_a5c9;
    flags.carry = (bx + memoryAGet16(cs, si)) >= 0x10000;
    bx += memoryAGet16(cs, si);
    dx += memoryAGet16(cs, si + 2) + flags.carry;
    si += 0x0004;
    stosb<MemData, DirForward>();
    cl--;
    if (cl != 0)
        goto loc_a5c7;
    cx = di;
    di = pop();
    cx -= di;
}
void sub_a6a9() // 0947:1239
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
    stosw<MemData, DirForward>();
    ax = 0xd7b0;
    stosw<MemData, DirForward>();
    ax = 0x0080;
    stosw<MemData, DirForward>();
    ax = 0;
    stosw<MemData, DirForward>();
    stosw<MemData, DirForward>();
    stosw<MemData, DirForward>();
    ax = di + 0x74;
    stosw<MemData, DirForward>();
    ax = es;
    stosw<MemData, DirForward>();
    ax = 0x135d;
    stosw<MemData, DirForward>();
    ax = cs;
    stosw<MemData, DirForward>();
    ax = 0;
    cx = 0x000e;
    rep_stosw<MemData, DirForward>();
    lodsb<MemData, DirForward>();
    if (al <= 0x4f)
        goto loc_a6e1;
    al = 0x4f;
loc_a6e1: // 0947:1271
    cl = al;
    ch = 0;
    rep_movsb<MemData, MemData, DirForward>();
    al = 0;
    stosb<MemData, DirForward>();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_a719() // 0947:12a9
{
    push(0x7777);
    dx = 0xd7b1;
    goto loc_a726;
    //   gap of 8 bytes
loc_a726: // 0947:12b6
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    ax = memoryAGet16(es, di + 2);
    if (ax == 0xd7b1)
        goto loc_a747;
    if (ax == 0xd7b2)
        goto loc_a747;
    if (ax == 0xd7b0)
        goto loc_a74c;
    memoryASet16(ds, 0x17cb, 0x0066);
    goto loc_a768;
loc_a747: // 0947:12d7
    push(dx);
    sub_a7b6(); // 0947:1346
    dx = pop();
loc_a74c: // 0947:12dc
    ax = 0;
    memoryASet16(es, di + 2, dx);
    memoryASet16(es, di + 8, ax);
    memoryASet16(es, di + 10, ax);
    bx = 0x0010;
    sub_a7bc(); // 0947:134c
    if (flags.zero)
        goto loc_a768;
    memoryASet16(es, di + 2, 0xd7b0);
loc_a768: // 0947:12f8
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a71e() // 0947:12ae
{
    push(0x7777);
    dx = 0xd7b2;
    goto loc_a726;
    //   gap of 3 bytes
loc_a726: // 0947:12b6
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    ax = memoryAGet16(es, di + 2);
    if (ax == 0xd7b1)
        goto loc_a747;
    if (ax == 0xd7b2)
        goto loc_a747;
    if (ax == 0xd7b0)
        goto loc_a74c;
    memoryASet16(ds, 0x17cb, 0x0066);
    goto loc_a768;
loc_a747: // 0947:12d7
    push(dx);
    sub_a7b6(); // 0947:1346
    dx = pop();
loc_a74c: // 0947:12dc
    ax = 0;
    memoryASet16(es, di + 2, dx);
    memoryASet16(es, di + 8, ax);
    memoryASet16(es, di + 10, ax);
    bx = 0x0010;
    sub_a7bc(); // 0947:134c
    if (flags.zero)
        goto loc_a768;
    memoryASet16(es, di + 2, 0xd7b0);
loc_a768: // 0947:12f8
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a7aa() // 0947:133a
{
    bx = 0x0014;
    if (memoryAGet16(es, di + 2) == 0xd7b2)
        goto loc_a7bc;
    return;
    //   gap of 6 bytes
loc_a7bc: // 0947:134c
    push(es);
    push(di);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, bx + di + 2);
    callIndirect(memoryAGet16(es, bx + di + 2), memoryAGet16(es, bx + di));
    assert(cs == 0x0947);
    if (!ax)
        goto loc_a7ca;
    memoryASet16(ds, 0x17cb, ax);
loc_a7ca: // 0947:135a
    di = pop();
    es = pop();
}
void sub_a7b6() // 0947:1346
{
    sub_a7aa(); // 0947:133a
    bx = 0x001c;
    push(es);
    push(di);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, bx + di + 2);
    callIndirect(memoryAGet16(es, bx + di + 2), memoryAGet16(es, bx + di));
    assert(cs == 0x0947);
    if (!ax)
        goto loc_a7ca;
    memoryASet16(ds, 0x17cb, ax);
loc_a7ca: // 0947:135a
    di = pop();
    es = pop();
}
void sub_a7bc() // 0947:134c+zero
{
    push(es);
    push(di);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, bx + di + 2);
    callIndirect(memoryAGet16(es, bx + di + 2), memoryAGet16(es, bx + di));
    assert(cs == 0x0947);
    flags.zero = ax == 0;
    if (!ax)
        goto loc_a7ca;
    memoryASet16(ds, 0x17cb, ax);
loc_a7ca: // 0947:135a
    di = pop();
    es = pop();
}
void sub_a7cd() // 0947:135d
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
        goto loc_a7ef;
    al = 0x02;
    memoryASet16(ds, di, memoryAGet16(ds, di) + 1);
    if (memoryAGet16(ds, di + 2) == 0xd7b3)
        goto loc_a7ef;
    ah = 0x3c;
loc_a7ef: // 0947:137f
    if (memoryAGet(ds, di + 48) == 0x00)
        goto loc_a7fe;
    dx = di + 0x30;
    interrupt(0x21);
    if (flags.carry)
        goto loc_a847;
    memoryASet16(ds, di, ax);
loc_a7fe: // 0947:138e
    ax = 0x143a;
    bx = 0x1435;
    if (memoryAGet16(ds, di + 2) == 0xd7b1)
        goto loc_a831;
    bx = memoryAGet16(ds, di);
    ax = 0x4400;
    interrupt(0x21);
    ax = 0x1493;
    bx = ax;
    if (dl & 0x80)
        goto loc_a82c;
    if (memoryAGet16(ds, di + 2) != 0xd7b3)
        goto loc_a826;
    sub_a84b(); // 0947:13db
loc_a826: // 0947:13b6
    ax = 0x146a;
    bx = 0x1435;
loc_a82c: // 0947:13bc
    memoryASet16(ds, di + 2, 0xd7b2);
loc_a831: // 0947:13c1
    memoryASet16(ds, di + 20, ax);
    memoryASet16(ds, di + 22, cs);
    memoryASet16(ds, di + 24, bx);
    memoryASet16(ds, di + 26, cs);
    memoryASet16(ds, di + 28, 0x14b7);
    memoryASet16(ds, di + 30, cs);
    ax = 0;
loc_a847: // 0947:13d7
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_a84b() // 0947:13db
{
    dx = 0;
    cx = 0;
    bx = memoryAGet16(ds, di);
    ax = 0x4202;
    interrupt(0x21);
    flags.carry = ax < 0x0080;
    ax -= 0x0080;
    tl = dx < 0x0000 + flags.carry;
    dx -= flags.carry;
    flags.carry = tl;
    if (!flags.carry)
        goto loc_a862;
    ax = 0;
    dx = 0;
loc_a862: // 0947:13f2
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
        goto loc_a87e;
    ax = 0;
loc_a87e: // 0947:140e
    bx = 0;
loc_a880: // 0947:1410
    if (bx == ax)
        return;
    if (memoryAGet(ds, bx + di + 128) == 0x1a)
        goto loc_a88e;
    bx++;
    goto loc_a880;
loc_a88e: // 0947:141e
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
void sub_a93e() // 0947:14ce+zero
{
    flags.zero = memoryAGet16(es, di + 2) == 0xd7b1;
    if (memoryAGet16(es, di + 2) != 0xd7b1)
        goto loc_a95f;
    flags.zero = memoryAGet16(ds, 0x17cb) == 0x0000;
    if (memoryAGet16(ds, 0x17cb) != 0x0000)
        return;
    si = pop();
    push(ds);
    push(es);
    push(di);
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 10);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    stop(/*2*/); // 0947:14ed jmp si - jump Indirect si
loc_a95f: // 0947:14ef
    memoryASet16(ds, 0x17cb, 0x0068);
}
void sub_a966() // 0947:14f6
{
    if (bx == dx)
        goto loc_a96f;
loc_a96a: // 0947:14fa
    al = memoryAGet(es, bx + di);
    flags.carry = false;
    return;
loc_a96f: // 0947:14ff
    push(cx);
    push(ds);
    push(si);
    ds = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    memoryASet16(es, di + 8, bx);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 20 + 2);
    callIndirect(memoryAGet16(es, di + 20 + 2), memoryAGet16(es, di + 20));
    assert(cs == 0x0947);
    if (!ax)
        goto loc_a989;
    memoryASet16(ds, 0x17cb, ax);
loc_a989: // 0947:1519
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 10);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    si = pop();
    ds = pop();
    cx = pop();
    if (bx != dx)
        goto loc_a96a;
    al = 0x1a;
    flags.carry = true;
}
void sub_a9a3() // 0947:1533
{
    stop(/*override stack*/); // 0947:1533
    si = pop();
    di = pop();
    es = pop();
    ds = pop();
    memoryASet16(es, di + 8, bx);
    stop(/*2*/); // 0947:153b jmp si - jump Indirect si
}
void sub_a9ad() // 0947:153d+zero
{
    flags.zero = memoryAGet16(es, di + 2) == 0xd7b2;
    if (memoryAGet16(es, di + 2) != 0xd7b2)
        goto loc_a9ce;
    flags.zero = memoryAGet16(ds, 0x17cb) == 0x0000;
    if (memoryAGet16(ds, 0x17cb) != 0x0000)
        return;
    si = 0x6ab0; //pop();
    push(ds);
    push(es);
    push(di);
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 4);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    return; //stop(/*2*/); // 0947:155c jmp si - jump Indirect si
loc_a9ce: // 0947:155e
    memoryASet16(ds, 0x17cb, 0x0069);
}
void sub_a9d5() // 0947:1565
{
    memoryASet(es, bx + di, al);
    bx++;
    if (bx == dx)
        goto loc_a9de;
    return;
loc_a9de: // 0947:156e
    push(cx);
    push(ds);
    push(si);
    ds = memoryAGet16(ss, bp - 2);
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    memoryASet16(es, di + 8, bx);
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 20 + 2);
    callIndirect(memoryAGet16(es, di + 20 + 2), memoryAGet16(es, di + 20));
    assert(cs == 0x0947);
    if (!ax)
        goto loc_a9f8;
    memoryASet16(ds, 0x17cb, ax);
loc_a9f8: // 0947:1588
    di = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    bx = memoryAGet16(es, di + 8);
    dx = memoryAGet16(es, di + 4);
    tx = di;
    di = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    si = pop();
    ds = pop();
    cx = pop();
}
void sub_aa0b() // 0947:159b
{
//    stop(/*override stack*/); // 0947:159b
//    si = pop();
    di = pop();
    es = pop();
    ds = pop();
    memoryASet16(es, di + 8, bx);
//    stop(/*2*/); // 0947:15a3 jmp si - jump Indirect si
}
void sub_aa15() // 0947:15a5
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    sub_a93e(); // 0947:14ce
    if (!flags.zero)
        goto loc_aa37;
loc_aa20: // 0947:15b0
    sub_a966(); // 0947:14f6
    if (al == 0x1a)
        goto loc_aa34;
    bx++;
    if (al != 0x0d)
        goto loc_aa20;
    sub_a966(); // 0947:14f6
    if (al != 0x0a)
        goto loc_aa34;
    bx++;
loc_aa34: // 0947:15c4
    sub_a9a3(); // 0947:1533
loc_aa37: // 0947:15c7
    bp = pop();
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    if (memoryAGet16(es, di + 2) != 0xd7b1)
        goto loc_aa5a;
    if (memoryAGet16(ds, 0x17cb) != 0x0000)
        goto loc_aa57;
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 24 + 2);
    callIndirect(memoryAGet16(es, di + 24 + 2), memoryAGet16(es, di + 24));
    assert(cs == 0x0947);
    if (ax)
        goto loc_aa5d;
loc_aa57: // 0947:15e7
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
    return;
loc_aa5a: // 0947:15ea
    ax = 0x0068;
loc_aa5d: // 0947:15ed
    memoryASet16(ds, 0x17cb, ax);
    goto loc_aa57;
}
void sub_aa62() // 0947:15f2
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    sub_a9ad(); // 0947:153d
    if (!flags.zero)
        goto loc_aa7a;
    al = 0x0d;
    sub_a9d5(); // 0947:1565
    al = 0x0a;
    sub_a9d5(); // 0947:1565
    sub_aa0b(); // 0947:159b
loc_aa7a: // 0947:160a
    bp = pop();
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    if (memoryAGet16(es, di + 2) != 0xd7b2)
        goto loc_aa9d;
    if (memoryAGet16(ds, 0x17cb) != 0x0000)
        goto loc_aa9a;
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 24 + 2);
    callIndirect(memoryAGet16(es, di + 24 + 2), memoryAGet16(es, di + 24));
    assert(cs == 0x0947);
    if (ax)
        goto loc_aaa0;
loc_aa9a: // 0947:162a
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
    return;
loc_aa9d: // 0947:162d
    ax = 0x0069;
loc_aaa0: // 0947:1630
    memoryASet16(ds, 0x17cb, ax);
    goto loc_aa9a;
}
void sub_aa7b() // 0947:160b
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 4);
    es = memoryAGet16(ss, bx + 4 + 2);
    if (memoryAGet16(es, di + 2) != 0xd7b2)
        goto loc_aa9d;
    if (memoryAGet16(ds, 0x17cb) != 0x0000)
        goto loc_aa9a;
    push(es);
    push(di);
    push(cs);
    cs = memoryAGet16(es, di + 24 + 2);
    callIndirect(memoryAGet16(es, di + 24 + 2), memoryAGet16(es, di + 24));
    assert(cs == 0x0947);
    if (ax)
        goto loc_aaa0;
loc_aa9a: // 0947:162a
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
    return;
loc_aa9d: // 0947:162d
    ax = 0x0069;
loc_aaa0: // 0947:1630
    memoryASet16(ds, 0x17cb, ax);
    goto loc_aa9a;
}
void sub_aabf() // 0947:164f
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    sub_a9ad(); // 0947:153d
    if (!flags.zero)
        goto loc_aae0;
    cx = memoryAGet16(ss, bp + 6);
    cx--;
    if ((short)cx <= 0)
        goto loc_aad7;
loc_aad0: // 0947:1660
    al = 0x20;
    sub_a9d5(); // 0947:1565
    if (--cx)
        goto loc_aad0;
loc_aad7: // 0947:1667
    al = memoryAGet(ss, bp + 8);
    sub_a9d5(); // 0947:1565
    sub_aa0b(); // 0947:159b
loc_aae0: // 0947:1670
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
void sub_ab1d() // 0947:16ad
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    sub_a9ad(); // 0947:153d
    if (!flags.zero)
        goto loc_ab4d;
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    cx = memoryAGet16(ss, bp + 6);
    flags.direction = false;
    lodsb<MemData, DirForward>();
    ah = 0;
    tx = cx;
    cx -= ax;
    if ((short)tx - (short)ax <= 0)
        goto loc_ab3f;
    push(ax);
loc_ab37: // 0947:16c7
    al = 0x20;
    sub_a9d5(); // 0947:1565
    if (--cx)
        goto loc_ab37;
    ax = pop();
loc_ab3f: // 0947:16cf
    cx = ax;
    if (cx == 0)
        goto loc_ab4a;
loc_ab43: // 0947:16d3
    flags.direction = false;
    lodsb<MemData, DirForward>();
    sub_a9d5(); // 0947:1565
    if (--cx)
        goto loc_ab43;
loc_ab4a: // 0947:16da
    sub_aa0b(); // 0947:159b
loc_ab4d: // 0947:16dd
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_aba8() // 0947:1738
{
    push(0x7777);
    sp -= 0x0020;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 40);
    dx = memoryAGet16(ss, bp + 42);
    di = bp + 0x2;
    push(ss);
    es = pop();
    sub_a597(); // 0947:1127
    di = memoryAGet16(ss, bp + 44);
    es = memoryAGet16(ss, bp + 44 + 2);
    sub_a9ad(); // 0947:153d
    if (!flags.zero)
        goto loc_abe5;
    ax = memoryAGet16(ss, bp + 38);
    tx = ax;
    ax -= cx;
    if ((short)tx - (short)cx <= 0)
        goto loc_abd6;
    push(cx);
    cx = ax;
loc_abce: // 0947:175e
    al = 0x20;
    sub_a9d5(); // 0947:1565
    if (--cx)
        goto loc_abce;
    cx = pop();
loc_abd6: // 0947:1766
    si = bp + 0x2;
    push(ss);
    ds = pop();
loc_abdb: // 0947:176b
    flags.direction = false;
    lodsb<MemData, DirForward>();
    sub_a9d5(); // 0947:1565
    if (--cx)
        goto loc_abdb;
    sub_aa0b(); // 0947:159b
loc_abe5: // 0947:1775
    bp = pop();
    sp += 0x0020;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_abec() // 0947:177c
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
        goto loc_ac08;
    si += cx;
    di += cx;
    si--;
    di--;
    flags.direction = true;
loc_ac08: // 0947:1798
    rep_movsb<MemData, MemData, DirForward>();
    ds = dx;
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_ac0f() // 0947:179f
{
    push(0x7777);
    bx = sp;
    di = memoryAGet16(ss, bx + 8);
    es = memoryAGet16(ss, bx + 8 + 2);
    cx = memoryAGet16(ss, bx + 6);
    al = memoryAGet(ss, bx + 4);
    flags.direction = false;
    if (es == 0xb800)
        rep_stosb<MemVideo, DirForward>();
    else
        rep_stosb<MemData, DirForward>();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
