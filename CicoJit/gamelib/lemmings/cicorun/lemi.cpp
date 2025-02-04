#include "cicoemu.h"
using namespace CicoContext;

const int lemmingsStartupLevel = 0;

void sub_10000();
void fixReloc(uint16_t seg);

void start()
{
    headerSize = 0x0120;
    loadAddress = 0x1000;
    endAddress = 0x2460;
    cs = 0x1000;
    ds = 0x0ff0;
    es = 0x0ff0;
    ss = 0x243e;
    sp = 0x4af4;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/lemmings/dos", "VGALEMMI.EXE", 83194);
    fixReloc(cs);
    sub_10000();
}
void fixReloc(uint16_t seg)
{
    memory16(0x0000 + seg, 0x0001) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x0f73) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x1653) += seg; // 0842 -> 1842
    memory16(0x0000 + seg, 0x16d9) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x17d2) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x18fb) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x194b) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x1c7b) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x1d0c) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x1d36) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x1eb4) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x36a3) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x39c0) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4137) += seg; // 143e -> 243e
    memory16(0x0000 + seg, 0x4c14) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4c50) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x4dbe) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4e81) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4e9f) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4ee4) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4f0d) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4f28) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4f82) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x4fee) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x5884) += seg; // 143e -> 243e
    memory16(0x0000 + seg, 0x5968) += seg; // 0842 -> 1842
    memory16(0x0000 + seg, 0x7bfc) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x7cb8) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x7cff) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x7e73) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x7e93) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x7ea8) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x8229) += seg; // 0000 -> 1000
    memory16(0x0000 + seg, 0x8918) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x8b4c) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x8d70) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9001) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x90a6) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9175) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x944e) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9470) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x94ac) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x94ca) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x94ec) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x950a) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9529) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x95a4) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x95c4) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x95f2) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9610) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x963e) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x965c) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9687) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x971b) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x978e) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x97fa) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9890) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x98af) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x98da) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x98f7) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9918) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9935) += seg; // 09a9 -> 19a9
    memory16(0x0000 + seg, 0x9953) += seg; // 09a9 -> 19a9
}
void sub_10000();
void sub_1031e();
void sub_103c1();
void sub_103d7();
void sub_103e7();
void sub_104f9();
void sub_1054e();
void sub_1060c();
void sub_1062b();
void sub_1063e();
void sub_10659();
void sub_10ec2();
void sub_10f08();
void sub_10f6f();
void sub_10fa0();
void sub_10fb2();
void sub_10ff8();
void sub_11007();
void sub_1106e();
void sub_11194();
void sub_11218();
void sub_11228();
void sub_1123f();
void sub_11293();
void sub_113a8();
void sub_113dc();
void sub_11550();
void sub_11562();
void sub_11582();
void sub_115ad();
void sub_11602();
void sub_11644();
void sub_116a9();
void sub_117c7();
void sub_118b2();
void sub_11916();
void sub_1197d();
void sub_11a7b();
void sub_11b42();
void sub_11b79();
void sub_11ba9();
void sub_11baf();
void sub_11c82();
void sub_11c87();
void sub_11ca3();
void sub_11cb9();
void sub_11cd9();
void sub_11d2e();
void sub_11e1c();
void sub_11e64();
void sub_11ed1();
void sub_11f19();
void sub_1283b();
void sub_12e04();
void sub_12ec0();
void sub_130a6();
void sub_13150();
void sub_13634();
void sub_1368e();
void sub_136ad();
void sub_136b6();
void sub_1378a();
void sub_137c2();
void sub_13839();
void sub_1389f();
void sub_13944();
void sub_1394f();
void sub_139ce();
void sub_13ac8();
void sub_13cde();
void sub_13e6f();
void sub_14085();
void sub_1410f();
void sub_1417b();
void sub_1418c();
void sub_14252();
void sub_14334();
void sub_14359();
void sub_14386();
void sub_143ce();
void sub_14566();
void sub_146a2();
void sub_146b9();
void sub_1482f();
void sub_1488c();
void sub_148bd();
void sub_148f6();
void sub_14ac5();
void sub_14b1c();
void sub_14b5c();
void sub_14b68();
void sub_14bbe();
void sub_14bc2();
void sub_14be7();
void sub_14bf5();
void sub_14c07();
void sub_14c17();
void sub_14c20();
void sub_14c32();
void sub_14c36();
void sub_14c7e();
void sub_14d1a();
void sub_14d4d();
void sub_14d78();
void sub_14dc2();
void sub_14def();
void sub_14df8();
void sub_14e37();
void sub_14ea2();
void sub_14eef();
void sub_14f2b();
void sub_14f4a();
void sub_14f6e();
void sub_14f96();
void sub_14ff8();
void sub_15017();
void sub_15019();
void sub_15028();
void sub_1503b();
void sub_15042();
void sub_151a2();
void sub_152f4();
void sub_1531e();
void sub_15329();
void sub_1534b();
void sub_1536c();
void sub_15377();
void sub_153ca();
void sub_153f6();
void sub_153fc();
void sub_153fe();
void sub_15425();
void sub_15447();
void sub_15473();
void sub_1548c();
void sub_154c4();
void sub_1553d();
void sub_15569();
void sub_1563e();
void sub_1566c();
void sub_15685();
void sub_15696();
void sub_1569b();
void sub_156e2();
void sub_1570c();
void sub_15726();
void sub_157d1();
void sub_15827();
void sub_1587f();
void sub_158d2();
void sub_159bb();
void sub_15ac1();
void sub_15b11();
void sub_15bb0();
void sub_15c06();
void sub_15cc1();
void sub_15cdd();
void sub_15d66();
void sub_15d94();
void sub_15dc6();
void sub_15df8();
void sub_15eba();
void sub_15f0f();
void sub_15fac();
void sub_1606b();
void sub_16141();
void sub_16170();
void sub_164d9();
void sub_165d8();
void sub_166d7();
void sub_16817();
void sub_16957();
void sub_16a97();
void sub_16bdb();
void sub_16cfc();
void sub_16e83();
void sub_16f7b();
void sub_16fe2();
void sub_1706f();
void sub_1715f();
void sub_17218();
void sub_175ef();
void sub_17602();
void sub_1762a();
void sub_17708();
void sub_1780d();
void sub_1789e();
void sub_17900();
void sub_1796f();
void sub_17a25();
void sub_17a39();
void sub_17a5a();
void sub_17bb8();
void sub_17c67();
void sub_17cbc();
void sub_17ce6();
void sub_17d0d();
void sub_17d8d();
void sub_17db7();
void sub_17e65();
void sub_17eb2();
void sub_180fd();
void sub_181cc();
void sub_18238();
void sub_18243();
void sub_18249();
void sub_1824f();
void sub_18343();
void sub_18808();
void sub_18822();
void sub_19967();
void sub_19a15();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x10000f6f: sub_10f6f(); return;
        case 0x100017c7: sub_117c7(); return;
        case 0x10003e6f: sub_13e6f(); return;
        case 0x10004252: sub_14252(); return;
        case 0x1000503b: sub_1503b(); return;
        case 0x10006170: sub_16170(); return;
        case 0x100064d9: sub_164d9(); return;
        case 0x100065d8: sub_165d8(); return;
        case 0x100066d7: sub_166d7(); return;
        case 0x10006817: sub_16817(); return;
        case 0x10006957: sub_16957(); return;
        case 0x10006a97: sub_16a97(); return;
        case 0x10006bdb: sub_16bdb(); return;
        case 0x10006cfc: sub_16cfc(); return;
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_1063e()!
// INJECT: Error: cannot inject carry flag in sub_11d2e()!
// INJECT: Error: cannot inject carry flag in sub_11d2e()!
void sub_10000()
{
    dx = 0x19a9;
    ds = dx;
    push(es);
    sub_18343();
    memoryASet(cs, 0x83b8, al);
    sub_18343();
    memoryASet(cs, 0x83bd, al);
    ah = 0;
    interrupt(0x1a);
    memoryASet16(ds, 0x259e, dx);
    memoryASet16(ds, 0x259c, cx);
    ah = 0x4a;
    bx = 0x1911;
    interrupt(0x21);
    push(ds);
    es = pop();
    di = 0x0000;
    cx = 0x2012;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    memoryASet(ds, 0x1f6b, lemmingsStartupLevel); // level
    ax = pop();
    memoryASet16(ds, 0x1ff6, ax);
    sub_104f9();
    memoryASet16(ds, 0x1f7c, 0x00ff);
    memoryASet(ds, 0x1fc6, 0x0c);
    memoryASet(ds, 0x200f, 0xff);
    sub_11293();
    sub_1106e();
    ax = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x1fbc, es);
    memoryASet16(ds, 0x1fba, bx);
    ax = 0x3508;
    interrupt(0x21);
    memoryASet16(ds, 0x1fbe, bx);
    memoryASet16(ds, 0x1fc0, es);
    ah = 0x35;
    al = memoryAGet(ds, 0x1fc6);
    interrupt(0x21);
    memoryASet16(ds, 0x1fc2, bx);
    memoryASet16(ds, 0x1fc4, es);
    ax = 0x2562;
    push(ds);
    push(es);
    ds = pop();
    dx = bx;
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2524;
    push(cs);
    ds = pop();
    dx = 0x18f8;
    interrupt(0x21);
    ds = pop();
    memoryASet(ds, 0x1fdf, 0x00);
    push(ds);
    ah = 0x1b;
    interrupt(0x21);
    al = memoryAGet(ds, bx);
    ds = pop();
    memoryASet(ds, 0x1fde, al);
    ah = 0x0f;
    interrupt(0x10);
    memoryASet(ds, 0x1fe1, al);
    memoryASet(ds, 0x1fe2, bh);
//    sub_1054e(); // skip adlib
    sub_11007();
    sub_10f08();
    memoryASet(cs, 0x83be, 0xff);
    ax = 0x000d;
    interrupt(0x10);
    ah = 0x09;
    dx = 0x2200;
    interrupt(0x21);
    sub_115ad();
    al = 0x36;
    out(0x43, al);
    al = 0;
    out(0x40, al);
    out(0x40, al);
    sub_158d2();
    sub_11ed1();
    memoryASet(ds, 0x1f75, 0xff);
    sub_1062b();
    sub_11562();
    flags.interrupts = false;
    cx = memoryAGet16(ds, 0x1fc9);
    al = 0x36;
    out(0x43, al);
    al = cl;
    out(0x40, al);
    al = ch;
    out(0x40, al);
    flags.interrupts = true;
    goto loc_143f2;
loc_100fb:
    sub_103e7();
    memoryASet(cs, 0x83be, 0x00);
loc_10105:
    ax = memoryAGet16(ds, 0x1f78);
    tx = memoryAGet16(ds, 0x1f76);
    memoryASet16(ds, 0x1f76, ax);
    ax = tx;
    memoryASet16(ds, 0x1f78, ax);
    ax = memoryAGet16(ds, 0x0028);
    tx = memoryAGet16(ds, 0x0026);
    memoryASet16(ds, 0x0026, ax);
    ax = tx;
    memoryASet16(ds, 0x0028, ax);
    if (memoryAGet(ds, 0x200e) != 0xff)
        goto loc_10164;
loc_10120:
    memoryASet(ds, 0x1fcf, 0x00);
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_1012c:
    in(al, dx);
    if (al & 0x08)
        goto loc_1012c;
    if (memoryAGet(ds, 0x1fcf) != 0xff)
        goto loc_1013f;
loc_10138:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_10138;
    goto loc_10120;
loc_1013f:
    dl -= 0x06;
    flags.interrupts = false;
    bx = memoryAGet16(ds, 0x1f78);
    bx += memoryAGet16(ds, 0x1f7a);
    bx += 0x0002;
    ah = bh;
    al = 0x0c;
    out(dx, ax);
    ah = bl;
    al++;
    out(dx, ax);
    flags.interrupts = true;
    dl += 0x06;
loc_1015c:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_1015c;
    sub_15827();
loc_10164:
    cx = memoryAGet16(ds, 0x1ffe);
    dx = memoryAGet16(ds, 0x2000);
    memoryASet(ds, 0x1fcf, 0x00);
//loc_10171:
//    cx--;
//    if (cx != 0)
//        goto loc_10179;
//    if (dx == 0)
//        goto loc_10183;
//    dx--;
//loc_10179:
//    if (memoryAGet(ds, 0x1fcf) != 0xff)
//        goto loc_10171;
    goto loc_10186;
loc_10183:
    sub_11644();
loc_10186:
//    al = memoryAGet(ds, 0x1fcd);
//    cl = 0x04;
//    if ((char)al <= (char)cl)
//        goto loc_10164;
    memoryASet(ds, 0x1fcd, 0x00);
//    memoryASet(ds, 0x1fd0, 0x00);
    memoryASet(ds, 0x1fd3, memoryAGet(ds, 0x1fd3) + 1);
    sub_1031e();
    sub_14085();
    memoryASet(ds, 0x0052, memoryAGet(ds, 0x0052) + 1);
    sub_180fd();
    sub_17900();
    sub_13150();
    sub_130a6();
    sub_11f19();
    sub_13944();
    sub_17bb8();
    sub_13634();
    sub_13cde();
    sub_13ac8();
    sub_13150();
    if (memoryAGet(ds, 0x004f) != 0xff)
        goto loc_101d2;
    goto loc_102c3;
loc_101d2:
    if (memoryAGet(ds, 0x004a) != 0xff)
        goto loc_101e7;
    cx = 0x0002;
loc_101dc:
    al = memoryAGet(ds, 0x1fcd);
loc_101df:
    sync();
    if (memoryAGet(ds, 0x1fcd) == al)
        goto loc_101df;
    if (--cx)
        goto loc_101dc;
loc_101e7:
    al = memoryAGet(ds, 0x0043);
    if (al != memoryAGet(ds, 0x0047))
        goto loc_101fa;
    al = memoryAGet(ds, 0x0045);
    if (al != 0)
        goto loc_101fa;
    goto loc_102b3;
loc_101fa:
    al = memoryAGet(ds, 0x20a7);
    al |= memoryAGet(ds, 0x20a9);
    al |= memoryAGet(ds, 0x20aa);
    if (al != 0x30)
        goto loc_1020c;
    goto loc_102b3;
loc_1020c:
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_1024a;
    memoryASet(ds, 0x0085, memoryAGet(ds, 0x0085) - 1);
    if (memoryAGet(ds, 0x0085) != 0)
        goto loc_1024a;
    al = memoryAGet(ds, 0x0086);
    memoryASet(ds, 0x0085, al);
    al = memoryAGet(ds, 0x20a7);
    bx = memoryAGet16(ds, 0x20a9);
    bh--;
    if (bh != 0x2f)
        goto loc_10243;
    bh = 0x39;
    bl--;
    if (bl != 0x2f)
        goto loc_10243;
    bl = 0x35;
    al--;
    if (al != 0x2f)
        goto loc_10243;
    al = 0x30;
    bx = 0x3030;
loc_10243:
    memoryASet(ds, 0x20a7, al);
    memoryASet16(ds, 0x20a9, bx);
loc_1024a:
    ax = memoryAGet16(ds, 0x1fc7);
    if (memoryAGet(ds, 0x1f74) != 0xff)
        goto loc_1025c;
    if (!(ax & 0x8000))
        goto loc_1025c;
    goto loc_10314;
loc_1025c:
    if (!(ax & 0x0080))
        goto loc_102a1;
    push(ax);
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_10275;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_10275;
    ax = 0x0100;
    interrupt(0x60);
loc_10275:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_10288;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_10288;
    ax = 0x0000;
    interrupt(0x60);
loc_10288:
    ax = pop();
    memoryASet(ds, 0x25a7, 0x00);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_102a1;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_102a1;
    ax = 0x0200;
    interrupt(0x61);
loc_102a1:
    if (!(ax & 0x0100))
        goto loc_102ab;
    memoryASet(ds, 0x25a7, 0x03);
loc_102ab:
    if (ax & 0x0020)
        goto loc_102b3;
    goto loc_10105;
loc_102b3:
    memoryASet(ds, 0x004f, 0xff);
    al = memoryAGet(ds, 0x004e);
    al |= 0x02;
    memoryASet(ds, 0x004e, al);
    goto loc_10105;
loc_102c3:
    al = memoryAGet(ds, 0x004e);
    if (!(al & 0x02))
        goto loc_102cd;
    goto loc_10105;
loc_102cd:
    sub_15447();
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_102e3;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_102e3;
    ax = 0x0100;
    interrupt(0x60);
loc_102e3:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_102f6;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_102f6;
    ax = 0x0000;
    interrupt(0x60);
loc_102f6:
    memoryASet(ds, 0x002a, 0x00);
    sub_116a9();
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_10311;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_10311;
    ax = 0x0200;
    interrupt(0x61);
loc_10311:
    goto loc_146eb;
loc_10314:
    memoryASet(ds, 0x0040, 0x64);
    sub_15447();
    goto loc_102c3;
    //   gap of 434 bytes
loc_104d0:
    sub_116a9();
    sub_11582();
    sub_10fa0();
    sub_10ff8();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_104ea;
    ax = 0x000c;
    cx = 0;
    interrupt(0x33);
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 16036 bytes
loc_143f2:
    sub_14be7();
    sub_14def();
    sub_15028();
    sub_153fc();
    sub_14ac5();
loc_14401:
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x6d60);
    memoryASet16(ds, 0x1f7a, 0x0000);
    sub_14c32();
    memoryASet(ds, 0x1f6f, 0xff);
    memoryASet(ds, 0x1f72, 0xff);
    memoryASet(ds, 0x1f70, 0x00);
    sub_1531e();
    sub_14def();
    sub_15017();
    sub_17cbc();
    sub_14ff8();
    sub_14eef();
    sub_14f2b();
    si = 0x4ad9;
    sub_14d4d();
    sub_14ea2();
    sub_14e37();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
loc_14453:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_14453;
loc_1445b:
    sub_11550();
    sub_17d0d();
    sub_14f96();
    sub_14ea2();
    sub_14e37();
    sub_14c20();
    ax = memoryAGet16(ds, 0x0014);
    if (!(ax & 0x0007))
        goto loc_14478;
    goto loc_1454c;
loc_14478:
    sub_14d1a();
    if (al != 0x80)
        goto loc_14482;
    goto loc_1454c;
loc_14482:
    if (al == 0x81)
        goto loc_144ad;
    if (al == 0x82)
        goto loc_144b3;
    if (al == 0x83)
        goto loc_144b0;
    if (al != 0x1b)
        goto loc_14495;
    goto loc_104d0;
loc_14495:
    if (al == 0x8a)
        goto loc_144ec;
    if (al == 0x60)
        goto loc_144ec;
    if (al != 0x8b)
        goto loc_144a4;
    goto loc_1451c;
loc_144a4:
    if (al != 0x2d)
        goto loc_144ab;
    goto loc_1451c;
loc_144ab:
    goto loc_1445b;
loc_144ad:
    goto loc_14967;
loc_144b0:
    goto loc_14a01;
loc_144b3:
    if (memoryAGet(ds, 0x1f72) == 0x02)
        goto loc_1445b;
    memoryASet(ds, 0x1f70, memoryAGet(ds, 0x1f70) ^ 0xff);
    al = memoryAGet(ds, 0x1f71);
    al++;
    ah = 0x03;
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_144cf;
    ah = 0x02;
loc_144cf:
    if (al != ah)
        goto loc_144d5;
    al = 0;
loc_144d5:
    memoryASet(ds, 0x1f71, al);
    bl = al;
    bh = 0;
    bx += 0x44e9;
    al = memoryAGet(cs, bx);
    memoryASet(ds, 0x25a7, al);
    goto loc_1445b;
    //   gap of 3 bytes
loc_144ec:
    if (memoryAGet(ds, 0x1f6f) != 0x04)
        goto loc_144f6;
    goto loc_1445b;
loc_144f6:
    al = memoryAGet(ds, 0x1f6e);
    if (al != 0x03)
        goto loc_14500;
    goto loc_1445b;
loc_14500:
    al++;
    memoryASet(ds, 0x1f6e, al);
    al <<= 1;
    ah = al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    memoryASet(ds, 0x1f6b, ah);
    goto loc_1445b;
loc_1451c:
    if (memoryAGet(ds, 0x1f6f) != 0x04)
        goto loc_14526;
    goto loc_1445b;
loc_14526:
    al = memoryAGet(ds, 0x1f6e);
    if (al != 0)
        goto loc_14530;
    goto loc_1445b;
loc_14530:
    al--;
    memoryASet(ds, 0x1f6e, al);
    al <<= 1;
    ah = al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    memoryASet(ds, 0x1f6b, ah);
    goto loc_1445b;
loc_1454c:
    memoryASet(ds, 0x1f6d, 0x00);
loc_14551:
    push(ds);
    es = pop();
    di = 0x0000;
    cx = 0x0fca;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    sub_1197d();
    sub_14566();
    goto loc_100fb;
    //   gap of 389 bytes
loc_146eb:
    sub_14def();
    sub_14be7();
    sub_153fc();
    sub_1531e();
    sub_14def();
    sub_15028();
    sub_15017();
    sub_148bd();
    si = 0x4c19;
    al = memoryAGet(ds, 0x20a7);
    bx = memoryAGet16(ds, 0x20a9);
    bl |= al;
    if (bx == 0x3030)
        goto loc_1471a;
    si = 0x4c2e;
loc_1471a:
    sub_14d4d();
    al = memoryAGet(ds, 0x0040);
    if ((char)al >= (char)memoryAGet(ds, 0x0041))
        goto loc_14729;
    goto loc_14778;
loc_14729:
    memoryASet(ds, 0x1f6d, 0xff);
    memoryASet(ds, 0x1f6b, memoryAGet(ds, 0x1f6b) + 1);
    al = memoryAGet(ds, 0x1f6b);
    ah = 0;
    cl = 0x1e;
    div(cl);
    memoryASet(ds, 0x1f6e, al);
    if (memoryAGet(ds, 0x1f6b) < 0x78)
        goto loc_14748;
    goto loc_147e0;
loc_14748:
    sub_1488c();
    si = 0x4d5d;
    sub_14b68();
    sub_15042();
    si = 0x4d3f;
    sub_14d4d();
    bx = 0x4d75;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14776;
    bx = 0x4da0;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14776;
    bx = 0x4dc2;
loc_14776:
    goto loc_14797;
loc_14778:
    memoryASet(ds, 0x1f6d, 0x00);
    bx = 0x4cd3;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14797;
    bx = 0x4cfe;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14797;
    bx = 0x4d20;
loc_14797:
    push(bx);
    sub_148f6();
    si = pop();
    sub_14d4d();
    si = memoryAGet16(ds, 0x0021);
    sub_14d4d();
    sub_1536c();
loc_147a9:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_147a9;
loc_147b1:
    sync();
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0001)
        goto loc_147d7;
    if (ax & 0x0002)
        goto loc_147cb;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_147cb;
    if (!(ax & 0x0040))
        goto loc_147b1;
loc_147cb:
    sub_1531e();
    sub_14def();
    sub_14be7();
    goto loc_14401;
loc_147d7:
    sub_1531e();
    sub_14def();
    goto loc_14551;
loc_147e0:
    sub_15017();
    si = 0x51cb;
    sub_14d4d();
    si = 0x4ba0;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14804;
    si = 0x4bc3;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14804;
    si = 0x4be5;
loc_14804:
    sub_14d4d();
    sub_1536c();
loc_1480a:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_1481f;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_1481f;
    if (!(ax & 0x0040))
        goto loc_1480a;
loc_1481f:
    sub_1531e();
    memoryASet(ds, 0x1f6b, 0x00);
    memoryASet(ds, 0x1f6e, 0x00);
    goto loc_14401;
    //   gap of 312 bytes
loc_14967:
    sub_14def();
    sub_14bf5();
    sub_1531e();
    sub_14def();
    sub_15017();
    si = 0x4df2;
    cx = 0x000a;
loc_1497d:
    memoryASet(ds, si, 0x2e);
    si++;
    if (--cx)
        goto loc_1497d;
    si = 0x4de1;
    sub_14d4d();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
    sub_14c7e();
    sub_151a2();
    if (!flags.zero)
        goto loc_149ec;
    al = memoryAGet(ds, 0x1f6b);
    sub_1488c();
    push(ax);
    si = 0x4e10;
    sub_14b68();
    ax = pop();
    al = ah;
    di = 0x4e1f;
    si = 0x4c01;
    push(ds);
    es = pop();
    cx = 0x0006;
    mul(cl);
    si += ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = 0x4dfe;
    sub_14d4d();
    sub_14c20();
    cx = 0x0078;
loc_149cf:
    sub_11550();
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_149e9;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_149e9;
    if (ax & 0x0040)
        goto loc_149e9;
    if (--cx)
        goto loc_149cf;
loc_149e9:
    goto loc_14401;
loc_149ec:
    si = 0x4e27;
    sub_14d4d();
    sub_14c20();
    cx = 0x003c;
loc_149f9:
    sub_11550();
    if (--cx)
        goto loc_149f9;
    goto loc_14401;
loc_14a01:
    sub_14def();
    sub_14bf5();
    sub_1531e();
    sub_15017();
    si = 0x4e3a;
    sub_14d4d();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_14a22;
    si = 0x4e6e;
    sub_14d4d();
loc_14a22:
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
loc_14a2e:
    sub_11550();
    sub_14d1a();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_14a3f;
    if (al == 0x31)
        goto loc_14abd;
loc_14a3f:
    if (al == 0x32)
        goto loc_14a4e;
    if (al == 0x33)
        goto loc_14ab5;
    if (al != 0x1b)
        goto loc_14a2e;
    goto loc_14401;
loc_14a4e:
    si = 0x4e85;
    sub_14d4d();
    sub_14c20();
    sub_143ce();
    if (cl == 0x02)
        goto loc_14ab5;
    if (cl == 0x01)
        goto loc_14a7d;
    ax = 0x4334;
    memoryASet16(ds, 0x25a0, ax);
    al = 0x01;
    memoryASet(ds, 0x25a6, al);
    sub_14334();
    memoryASet16(ds, 0x25a2, bx);
    memoryASet16(ds, 0x25a4, cx);
    goto loc_14a95;
loc_14a7d:
    ax = 0x4359;
    memoryASet16(ds, 0x25a0, ax);
    al = 0x01;
    memoryASet(ds, 0x25a6, al);
    sub_14359();
    memoryASet16(ds, 0x25a2, bx);
    memoryASet16(ds, 0x25a4, cx);
loc_14a95:
    si = 0x4ea9;
    sub_14d4d();
    sub_14c20();
loc_14a9f:
    sub_11550();
    sub_14d1a();
    if (al < 0x31)
        goto loc_14a9f;
    if (al > 0x34)
        goto loc_14a9f;
    al -= 0x30;
    memoryASet(ds, 0x2005, al);
    goto loc_14401;
loc_14ab5:
    memoryASet(ds, 0x25a6, 0x02);
    goto loc_14401;
loc_14abd:
    memoryASet(ds, 0x25a6, 0x00);
    goto loc_14401;
}
void sub_1031e()
{
    al = memoryAGet(ds, 0x004e);
    if (!(al & 0x01))
        goto loc_10342;
    if (memoryAGet(ds, 0x200e) != 0xff)
        goto loc_1033d;
loc_1032c:
    sub_103c1();
    push(ax);
    sub_11550();
    sub_1553d();
    ax = pop();
    if (al & 0x01)
        goto loc_1032c;
    goto loc_10361;
loc_1033d:
    sub_103c1();
    goto loc_10361;
loc_10342:
    if (!(al & 0x02))
        goto loc_10361;
    if (memoryAGet(ds, 0x200e) != 0xff)
        goto loc_1035e;
loc_1034d:
    sub_103d7();
    push(ax);
    sub_11550();
    sub_1553d();
    ax = pop();
    if (al & 0x02)
        goto loc_1034d;
    goto loc_10361;
loc_1035e:
    sub_103d7();
loc_10361:
    if (!(al & 0x04))
        goto loc_1037c;
    dl = memoryAGet(ds, 0x0052);
    if (dl == 0x0f)
        goto loc_10380;
    if (dl == 0x23)
        goto loc_10394;
    if (dl == 0x37)
        goto loc_103ad;
    if (dl < 0x37)
        goto loc_1037c;
    al &= 0xfb;
loc_1037c:
    memoryASet(ds, 0x004e, al);
    return;
loc_10380:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_10393;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_10393;
    ax = 0x0403;
    interrupt(0x61);
loc_10393:
    return;
loc_10394:
    memoryASet(ds, 0x0055, 0xff);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_103ac;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_103ac;
    ax = 0x0402;
    interrupt(0x61);
loc_103ac:
    return;
loc_103ad:
    if (!(memoryAGet(ds, 0x25a7) & 0x02))
        return;
    al = memoryAGet(ds, 0x0054);
    ah = 0x03;
    interrupt(0x61);
    ax = 0x0000;
    interrupt(0x61);
    return;
    //   gap of 21 bytes
}
void sub_103c1()
{
    al |= 0x04;
    push(ax);
    bx = 0x0604;
    cx = 0x0010;
    dx = 0x0008;
    sub_1534b();
    ax = pop();
    if (!flags.zero)
        return;
    al &= 0xfe;
}
void sub_103d7()
{
    goto loc_103d7;
loc_103d6:
    return;
loc_103d7:
    push(ax);
    cx = 0x0010;
    dx = 0x0008;
    sub_15329();
    ax = pop();
    if (!flags.zero)
        goto loc_103d6;
    al &= 0xfd;
}
void sub_103e7()
{
    memoryASet16(ds, 0x0000, 0x0218);
    memoryASet16(ds, 0x0002, 0x0043);
    memoryASet(ds, 0x001a, 0x00);
    memoryASet16(ds, 0x0010, 0x0096);
    memoryASet16(ds, 0x0012, 0x0064);
    memoryASet(ds, 0x0047, 0xc8);
    memoryASet(ds, 0x004a, 0x00);
    memoryASet(ds, 0x20a9, 0x30);
    memoryASet(ds, 0x20aa, 0x30);
    memoryASet(ds, 0x0085, 0x11);
    memoryASet(ds, 0x0086, 0x11);
    memoryASet(ds, 0x0082, 0x02);
    memoryASet(ds, 0x0083, 0x03);
    memoryASet(ds, 0x004d, 0x50);
    memoryASet(ds, 0x004e, 0x01);
    al = 0;
    memoryASet(ds, 0x1fd4, al);
    memoryASet(ds, 0x1fd3, al);
    memoryASet(ds, 0x004f, al);
    memoryASet(ds, 0x002a, al);
    memoryASet(ds, 0x0052, al);
    memoryASet(ds, 0x0055, al);
    push(ss);
    es = pop();
    di = 0x0012;
    cx = 0x42a0;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    push(ss);
    es = pop();
    di = 0x42b2;
    cx = 0x0642;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    sub_10fb2();
    sub_152f4();
    sub_115ad();
    sub_136b6();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_10480;
    ax = 0x0004;
    cx = 0x0096;
    dx = 0x0064;
    interrupt(0x33);
loc_10480:
    sub_1410f();
    sub_130a6();
    sub_15377();
    sub_1482f();
    sub_181cc();
    sub_139ce();
    sub_11644();
    sub_13944();
    sub_17bb8();
    sub_17900();
    sub_13ac8();
    cx = 0;
    dx = 0;
    memoryASet(ds, 0x1fcf, 0x00);
loc_104aa:
//    sync();
//    if (memoryAGet(ds, 0x1fcf) != 0xff)
//        goto loc_104aa;
    memoryASet(ds, 0x1fcf, 0x00);
//loc_104b6:
//    cx--;
//    if (cx != 0)
//        goto loc_104ba;
//    dx--;
//loc_104ba:
//    if (memoryAGet(ds, 0x1fcf) != 0xff)
//        goto loc_104b6;
    flags.carry = (cx + cx) >= 0x10000;
    cx += cx;
    dx += dx + flags.carry;
    dx = -dx;
    memoryASet16(ds, 0x1ffe, cx);
    memoryASet16(ds, 0x2000, dx);
}
void sub_104f9()
{
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
}
void sub_1054e()
{
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_10558;
    goto loc_105fc;
loc_10558:
    ah = 0x48;
    bx = 0x5ad8;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10565;
    goto loc_105fc;
loc_10565:
    es = ax;
    ah = 0x49;
    interrupt(0x21);
    ah = 0x48;
    bx = 0x0567;
    interrupt(0x21);
    push(ds);
    ds = ax;
    push(ax);
    ax = 0x2561;
    dx = 0;
    interrupt(0x21);
    ax = pop();
    ds = pop();
    push(ax);
    push(ds);
    es = ax;
    cx = ax;
    di = 0;
    si = 0;
    dx = 0x2573;
    sub_11b79();
    ds = pop();
    memoryASet(ds, 0x25a7, 0x01);
    memoryASet(ds, 0x1f71, 0x01);
    ah = 0x01;
    interrupt(0x61);
    ax = pop();
    if (al == 0)
        goto loc_105b4;
    memoryASet(ds, 0x2010, 0xff);
    memoryASet(ds, 0x25a7, 0x03);
    memoryASet(ds, 0x1f71, 0x02);
    return;
loc_105b4:
    push(ax);
    sub_1060c();
    ax = pop();
    if (al == 0)
        goto loc_105f6;
    push(ds);
    es = ax;
    cx = ax;
    di = 0;
    si = 0;
    dx = 0x257d;
    sub_11b79();
    ds = pop();
    memoryASet(ds, 0x2010, 0xff);
    memoryASet(ds, 0x25a7, 0x03);
    memoryASet(ds, 0x1f71, 0x02);
    al = 0x01;
    ah = 0x03;
    interrupt(0x61);
    ah = 0x00;
    interrupt(0x61);
    al = 0;
    ah = 0x03;
    interrupt(0x61);
    ah = 0x02;
    interrupt(0x61);
    ah = 0x00;
    interrupt(0x61);
    return;
loc_105f6:
    es = ax;
    ah = 0x49;
    interrupt(0x21);
loc_105fc:
    memoryASet(ds, 0x2010, 0x00);
    memoryASet(ds, 0x25a7, 0x01);
    memoryASet(ds, 0x1f71, 0x01);
}
void sub_1060c()
{
    ah = 0x0f;
    interrupt(0x10);
    push(bx);
    bx = 0;
    ax = 0x0580;
    interrupt(0x10);
    ax = pop();
    ah = 0x05;
    tl = al;
    al = ah;
    ah = tl;
    if (bx)
        goto loc_10626;
    interrupt(0x10);
    al = 0;
    return;
loc_10626:
    interrupt(0x10);
    al = 0xff;
}
void sub_1062b()
{
    al = memoryAGet(ds, 0x1fde);
    if (al != 0xf8)
        goto loc_10635;
    goto loc_10e66;
loc_10635:
//    sub_1063e();
    flags.carry = false;
    if (!flags.carry)
        goto loc_1063d;
    goto loc_10edf;
loc_1063d:
    return;
    //   gap of 2088 bytes
loc_10e66:
    dx = 0x258a;
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_10eaa;
    bx = ax;
    ah = 0x3f;
    dx = 0x252a;
    cx = 0x0001;
    interrupt(0x21);
    al = memoryAGet(ds, 0x252a);
    al++;
    if (al < 0x0a)
        goto loc_10e89;
    al = 0;
loc_10e89:
    memoryASet(ds, 0x252a, al);
    push(ax);
    ah = 0x3e;
    interrupt(0x21);
    sub_10ec2();
    ax = pop();
    if (al != 0)
        goto loc_10ea9;
    sub_1063e();
    if (!flags.carry)
        goto loc_10ea9;
    memoryASet(ds, 0x252a, 0x09);
    sub_10ec2();
    goto loc_10edf;
loc_10ea9:
    return;
loc_10eaa:
    al = 0;
    memoryASet(ds, 0x252a, al);
    sub_10ec2();
    sub_1063e();
    if (!flags.carry)
        goto loc_10ea9;
    memoryASet(ds, 0x252a, 0x09);
    sub_10ec2();
    goto loc_10edf;
    //   gap of 30 bytes
loc_10edf:
    sub_116a9();
    sub_11582();
    sub_10fa0();
    sub_10ff8();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_10ef9;
    ax = 0x000c;
    cx = 0;
    interrupt(0x33);
loc_10ef9:
    sub_11582();
    dx = 0x20d4;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_10f64;
    ax = 0;
    interrupt(0x33);
    if (ax == 0)
        goto loc_10f64;
    ax = 0x000f;
    cx = 0x0010;
    dx = 0x0010;
    interrupt(0x33);
    ax = 0x0007;
    cx = 0x0008;
    dx = 0x0148;
    interrupt(0x33);
    ax = 0x0008;
    cx = 0x0008;
    dx = 0x00c8;
    interrupt(0x33);
    ax = 0x0004;
    cx = 0x0096;
    dx = 0x0064;
    interrupt(0x33);
    ax = 0x0002;
    interrupt(0x33);
    ax = 0x000c;
    cx = 0x007f;
    push(cs);
    es = pop();
    dx = 0x0f6f;
    interrupt(0x33);
    ah = 0x25;
    al = memoryAGet(ds, 0x1fc6);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x0f70;
    interrupt(0x21);
    ds = pop();
    return;
loc_10f64:
    memoryASet(ds, 0x25a6, 0x02);
    memoryASet(ds, 0x1f73, 0xff);
}
// INJECT: Error: cannot inject carry flag in sub_1063e()!
void sub_1063e()
{
    dl = 0;
    push(ds);
    push(es);
    push(cx);
    push(si);
    push(di);
    push(bp);
    si = 0;
    ds = si;
loc_1064a:
    push(memoryAGet16(ds, si));
    si += 0x0002;
    if (si != 0x0014)
        goto loc_1064a;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    sub_10659();
    memoryASet16(ds, 0x000c, pop());
    memoryASet16(ds, 0x000c, memoryAGet16(ds, 0x000c) + 0x075a);
    push(cs);
    si = pop();
    memoryASet16(ds, 0x000e, si);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    push(ss);
    ds = pop();
    ds = si;
    memoryASet(ss, bp + di, memoryAGet(ss, bp + di) + bl);
    flags.interrupts = false;
    memoryASet(ss, bp + di, rol(memoryAGet(ss, bp + di), cl));
    stop(/*inject ret*/);
    cs = pop();
}
void sub_10659()
{
    stop(/*override stack*/);
    memoryASet16(ds, 0x000c, pop());
    memoryASet16(ds, 0x000c, memoryAGet16(ds, 0x000c) + 0x075a);
    push(cs);
    si = pop();
    memoryASet16(ds, 0x000e, si);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    push(ss);
    ds = pop();
    ds = si;
    memoryASet(ss, bp + di, memoryAGet(ss, bp + di) + bl);
    flags.interrupts = false;
    memoryASet(ss, bp + di, rol(memoryAGet(ss, bp + di), cl));
    cs = pop();
}
void sub_10ec2()
{
    dx = 0x258a;
    ah = 0x3c;
    cx = 0x0002;
    interrupt(0x21);
    bx = ax;
    ah = 0x40;
    cx = 0x0100;
    dx = 0x252a;
    interrupt(0x21);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_10f08()
{
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_10f64;
    ax = 0;
    interrupt(0x33);
    if (ax == 0)
        goto loc_10f64;
    ax = 0x000f;
    cx = 0x0010;
    dx = 0x0010;
    interrupt(0x33);
    ax = 0x0007;
    cx = 0x0008;
    dx = 0x0148;
    interrupt(0x33);
    ax = 0x0008;
    cx = 0x0008;
    dx = 0x00c8;
    interrupt(0x33);
    ax = 0x0004;
    cx = 0x0096;
    dx = 0x0064;
    interrupt(0x33);
    ax = 0x0002;
    interrupt(0x33);
    ax = 0x000c;
    cx = 0x007f;
    push(cs);
    es = pop();
    dx = 0x0f6f;
    interrupt(0x33);
    ah = 0x25;
    al = memoryAGet(ds, 0x1fc6);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0x0f70;
    interrupt(0x21);
    ds = pop();
    return;
loc_10f64:
    memoryASet(ds, 0x25a6, 0x02);
    memoryASet(ds, 0x1f73, 0xff);
}
void sub_10f6f()
{
    cs = pop();
}
void sub_10fa0()
{
    push(ds);
    ah = 0x25;
    al = memoryAGet(ds, 0x1fc6);
    dx = memoryAGet16(ds, 0x1fc2);
    ds = memoryAGet16(ds, 0x1fc4);
    interrupt(0x21);
    ds = pop();
}
void sub_10fb2()
{
    flags.interrupts = false;
    ax = 0x008d;
    interrupt(0x10);
    dx = memoryAGet16(ds, 0x1fda);
    ax = 0x1613;
    out(dx, ax);
    flags.interrupts = true;
    memoryASet16(ds, 0x002e, 0x6170);
    memoryASet16(ds, 0x0030, 0x64d9);
    memoryASet16(ds, 0x0032, 0x65d8);
    memoryASet16(ds, 0x0034, 0x66d7);
    memoryASet16(ds, 0x0036, 0x6817);
    memoryASet16(ds, 0x0038, 0x6957);
    memoryASet16(ds, 0x003a, 0x6a97);
    memoryASet16(ds, 0x003c, 0x6bdb);
    memoryASet16(ds, 0x003e, 0x6cfc);
}
void sub_10ff8()
{
    al = memoryAGet(ds, 0x1fe1);
    ah = 0;
    interrupt(0x10);
    ah = 0x05;
    al = memoryAGet(ds, 0x1fe2);
    interrupt(0x10);
}
void sub_11007()
{
    goto loc_11007;
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 2745 bytes
loc_11007:
    ah = 0x48;
    bx = 0x5571;
    interrupt(0x21);
    if (flags.carry)
        goto loc_11044;
    memoryASet16(ds, 0x1fe4, ax);
    memoryASet16(ds, 0x1ff0, ax);
    ax += 0x1000;
    memoryASet16(ds, 0x1fe6, ax);
    ax += 0x1d0c;
    memoryASet16(ds, 0x1fe8, ax);
    ax += 0x0166;
    memoryASet16(ds, 0x1fea, ax);
    ax += 0x0090;
    memoryASet16(ds, 0x1fec, ax);
    ax += 0x007c;
    memoryASet16(ds, 0x1fee, ax);
    ax += 0x17f3;
    memoryASet16(ds, 0x1ff2, ax);
    ax += 0x0200;
    memoryASet16(ds, 0x1ff4, ax);
    ax += 0x0c00;
    return;
loc_11044:
    push(ax);
    push(bx);
    sub_10ff8();
    bx = pop();
    ax = bx;
    sub_11228();
    dl = 0x3a;
    ah = 0x02;
    interrupt(0x21);
    dl = 0x20;
    ah = 0x02;
    interrupt(0x21);
    ax = pop();
    dx = 0x21c8;
    if (ax == 0x0007)
        goto loc_11067;
    dx = 0x21ea;
loc_11067:
    ah = 0x09;
    interrupt(0x21);
    goto loc_104ea;
}
void sub_1106e()
{
    ax = 0x0003;
    interrupt(0x10);
    if (memoryAGet16(ds, 0x1f7c) == 0x00ff)
        goto loc_110a3;
    if (memoryAGet(ds, 0x200a) != 0xff)
        goto loc_11085;
    return;
loc_11085:
    if (memoryAGet(ds, 0x200b) != 0xff)
        goto loc_1108f;
    return;
loc_1108f:
    if (memoryAGet(ds, 0x200d) != 0xff)
        goto loc_11099;
    return;
loc_11099:
    if (memoryAGet(ds, 0x200c) != 0xff)
        goto loc_110a3;
    return;
loc_110a3:
    bx = 0x2260;
    sub_11218();
    if (memoryAGet16(ds, 0x1f7c) != 0x00ff)
        goto loc_110db;
    bx = 0x22e1;
    sub_11218();
loc_110b8:
    ah = 0x07;
    interrupt(0x21);
    if (al != 0x1b)
        goto loc_110c3;
    goto loc_1120c;
loc_110c3:
    cx = 0x0004;
    if (al == 0x31)
        goto loc_110d1;
    cx = 0x0002;
    if (al != 0x32)
        goto loc_110b8;
loc_110d1:
    memoryASet16(ds, 0x1f7c, cx);
    dl = al;
    ah = 0x02;
    interrupt(0x21);
loc_110db:
    if (memoryAGet(ds, 0x200a) != 0xff)
        goto loc_110e5;
    goto loc_11194;
loc_110e5:
    if (memoryAGet(ds, 0x200b) != 0xff)
        goto loc_110ef;
    goto loc_11194;
loc_110ef:
    if (memoryAGet(ds, 0x200d) != 0xff)
        goto loc_110f9;
    goto loc_11194;
loc_110f9:
    ah = 0x0f;
    interrupt(0x10);
    ah = 0x02;
    dx = 0x0100;
    interrupt(0x10);
    bx = 0x2384;
    sub_11218();
    bl = 0;
    di = 0x239f;
loc_11110:
    sub_11550();
    push(bx);
    ah = 0x07;
    interrupt(0x21);
    bx = pop();
    if (al != 0)
        goto loc_1113e;
    push(bx);
    ah = 0x07;
    interrupt(0x21);
    bx = pop();
    if (al != 0x48)
        goto loc_11130;
    if (bl == 0)
        goto loc_11110;
    bl--;
    goto loc_111b5;
loc_11130:
    if (al != 0x50)
        goto loc_11110;
    if (bl == 0x04)
        goto loc_11110;
    bl++;
    goto loc_111b5;
loc_1113e:
    if (al != 0x1b)
        goto loc_11145;
    goto loc_1120c;
loc_11145:
    if (al == 0x0d)
        goto loc_1116b;
    if (al == 0x0a)
        goto loc_1116b;
    if (al != 0x31)
        goto loc_11155;
    bl = 0;
    goto loc_1116b;
loc_11155:
    if (al != 0x32)
        goto loc_1115d;
    bl = 0x01;
    goto loc_1116b;
loc_1115d:
    if (al != 0x33)
        goto loc_11165;
    bl = 0x02;
    goto loc_1116b;
loc_11165:
    if (al != 0x34)
        goto loc_11110;
    bl = 0x03;
loc_1116b:
    si = 0x239f;
    if (bl != 0)
        goto loc_11176;
    goto loc_11200;
loc_11176:
    si = 0x240b;
    if (bl == 0x02)
        goto loc_111e2;
    si = 0x2442;
    if (bl == 0x03)
        goto loc_111f4;
    si = 0x23d2;
    if (bl == 0x01)
        goto loc_11194;
    goto loc_1120c;
loc_11194:
    memoryASet16(ds, di, 0x2020);
    memoryASet16(ds, si, 0x3e2d);
    di = si;
    push(di);
    push(bx);
    ah = 0x0f;
    interrupt(0x10);
    ah = 0x02;
    dx = 0x0100;
    interrupt(0x10);
    bx = 0x2384;
    sub_11218();
    bx = pop();
    di = pop();
    return;
loc_111b5:
    si = 0x239f;
    if (bl == 0)
        goto loc_111dc;
    si = 0x240b;
    if (bl == 0x02)
        goto loc_111dc;
    si = 0x2442;
    if (bl == 0x03)
        goto loc_111dc;
    si = 0x23d2;
    if (bl == 0x01)
        goto loc_111dc;
    si = 0x248a;
loc_111dc:
    sub_11194();
    goto loc_11110;
loc_111e2:
    memoryASet(ds, 0x200a, 0xff);
    memoryASet(ds, 0x1fc6, 0x74);
    memoryASet16(ds, 0x1fc9, 0x3468);
    goto loc_11194;
loc_111f4:
    memoryASet(ds, 0x200b, 0xff);
    memoryASet(ds, 0x200e, 0xff);
    goto loc_11194;
loc_11200:
    memoryASet(ds, 0x200e, 0xff);
    memoryASet(ds, 0x200c, 0xff);
    goto loc_11194;
loc_1120c:
    si = 0x248a;
    sub_11194();
    ax = 0x4c00;
    interrupt(0x21);
loc_11218:
    dl = memoryAGet(ds, bx);
    bx++;
    if (dl == 0)
        return;
    push(bx);
    ah = 0x02;
    interrupt(0x21);
    bx = pop();
    goto loc_11218;
}
void sub_11194()
{
    memoryASet16(ds, di, 0x2020);
    memoryASet16(ds, si, 0x3e2d);
    di = si;
    push(di);
    push(bx);
    ah = 0x0f;
    interrupt(0x10);
    ah = 0x02;
    dx = 0x0100;
    interrupt(0x10);
    bx = 0x2384;
    sub_11218();
    bx = pop();
    di = pop();
}
void sub_11218()
{
loc_11218:
    dl = memoryAGet(ds, bx);
    bx++;
    if (dl == 0)
        return;
    push(bx);
    ah = 0x02;
    interrupt(0x21);
    bx = pop();
    goto loc_11218;
}
void sub_11228()
{
    push(ax);
    cl = 0x04;
    ah >>= cl;
    sub_1123f();
    ax = pop();
    sub_1123f();
    ah = al;
    push(ax);
    cl = 0x04;
    ah >>= cl;
    sub_1123f();
    ax = pop();
    ah &= 0x0f;
    bl = ah;
    bh = 0;
    bx += 0x224f;
    dl = memoryAGet(ds, bx);
    memoryASet(ds, si, dl);
    si++;
}
void sub_1123f()
{
    ah &= 0x0f;
    bl = ah;
    bh = 0;
    bx += 0x224f;
    dl = memoryAGet(ds, bx);
    memoryASet(ds, si, dl);
    si++;
}
void sub_11293()
{
    es = memoryAGet16(ds, 0x1ff6);
    si = 0x0080;
    cl = memoryAGet(es, si);
    ch = 0;
    if (cx == 0)
        goto loc_112b0;
    si++;
loc_112a2:
    al = memoryAGet(es, si);
    si++;
    if (al == 0x2d)
        goto loc_112b1;
    if (al == 0x2f)
        goto loc_112b1;
loc_112ae:
    if (--cx)
        goto loc_112a2;
loc_112b0:
    return;
loc_112b1:
    cx--;
    if (cx == 0)
        goto loc_112b0;
    al = memoryAGet(es, si);
    si++;
    if ((char)al < (char)0x41)
        goto loc_112c2;
    if ((char)al > (char)0x5a)
        goto loc_112c2;
    al |= 0x20;
loc_112c2:
    if (al == 0x61)
        goto loc_11303;
    if (al != 0x6d)
        goto loc_112cd;
    goto loc_11377;
loc_112cd:
    if (al != 0x6e)
        goto loc_112d4;
    goto loc_1138b;
loc_112d4:
    if (al != 0x64)
        goto loc_112db;
    goto loc_11358;
loc_112db:
    if (al == 0x65)
        goto loc_1130a;
    if (al == 0x70)
        goto loc_1133a;
    if (al != 0x6f)
        goto loc_112ea;
    goto loc_11364;
loc_112ea:
    if (al == 0x76)
        goto loc_11312;
    if (al == 0x32)
        goto loc_1132a;
    if (al == 0x34)
        goto loc_11332;
    if (al != 0x69)
        goto loc_112fd;
    goto loc_11393;
loc_112fd:
    if (al == 0x78)
        goto loc_11370;
loc_11301:
    goto loc_112ae;
loc_11303:
    memoryASet(ds, 0x2010, 0xff);
    goto loc_11301;
loc_1130a:
    memoryASet16(ds, 0x1f7c, 0x0002);
    goto loc_11301;
loc_11312:
    memoryASet16(ds, 0x1f7c, 0x0004);
    goto loc_11301;
    //   gap of 16 bytes
loc_1132a:
    memoryASet16(ds, 0x2011, 0x00c8);
    goto loc_11301;
loc_11332:
    memoryASet16(ds, 0x2011, 0x0190);
    goto loc_11301;
loc_1133a:
    memoryASet(ds, 0x200a, 0xff);
    memoryASet(ds, 0x1fc6, 0x74);
    memoryASet16(ds, 0x1fc9, 0x3468);
    memoryASet16(ds, 0x1fda, 0x03d4);
    memoryASet16(ds, 0x1fdc, 0x03da);
    goto loc_11301;
loc_11358:
    memoryASet(ds, 0x200b, 0xff);
    memoryASet(ds, 0x200e, 0xff);
    goto loc_11301;
loc_11364:
    memoryASet(ds, 0x200d, 0xff);
    memoryASet(ds, 0x200c, 0xff);
    goto loc_11301;
loc_11370:
    memoryASet(ds, 0x200e, 0xff);
    goto loc_11301;
loc_11377:
    memoryASet(ds, 0x200f, 0xff);
    memoryASet16(ds, 0x1fda, 0x03d4);
    memoryASet16(ds, 0x1fdc, 0x03da);
    goto loc_11301;
loc_1138b:
    memoryASet(ds, 0x1f73, 0xff);
    goto loc_11301;
loc_11393:
    sub_113a8();
    if (bx == 0)
        goto loc_1139e;
    memoryASet16(ds, 0x1fc9, bx);
loc_1139e:
    if (cx != 0)
        goto loc_113a5;
    goto loc_112b0;
loc_113a5:
    goto loc_112ae;
}
void sub_113a8()
{
    goto loc_113a8;
loc_112b0:
    return;
    //   gap of 247 bytes
loc_113a8:
    bx = 0;
    al = memoryAGet(es, si);
    si++;
    cx--;
    if (cx != 0)
        goto loc_113b6;
    goto loc_112b0;
loc_113b6:
    if (al == 0x20)
        goto loc_113a8;
loc_113ba:
    if ((char)al < (char)0x30)
        return;
    if ((char)al > (char)0x39)
        return;
    al -= 0x30;
    ah = 0;
    bx <<= 1;
    dx = bx;
    bx <<= 1;
    bx <<= 1;
    bx += dx;
    bx += ax;
    cx--;
    if (cx == 0)
        return;
    al = memoryAGet(es, si);
    si++;
    goto loc_113ba;
}
void sub_113dc()
{
    di = 0x2006;
    memoryASet16(ds, di, 0x0000);
    memoryASet16(ds, di + 2, 0x0000);
    memoryASet(ds, 0x2019, 0xff);
    memoryASet(ds, 0x2016, 0xff);
    memoryASet(ds, 0x201c, 0xff);
    cx = 0x0004;
    si = 0x2013;
loc_113ff:
    lodsb<MemAuto, DirAuto>();
    lodsw<MemAuto, DirAuto>();
    if (stop(/*70 - je*/))
        goto loc_1140b;
    push(si);
    push(cx);
    callIndirect(cs, ax);
    cx = pop();
    si = pop();
loc_1140b:
    if (--cx)
        goto loc_113ff;
    goto loc_114fa;
    //   gap of 234 bytes
loc_114fa:
    if (memoryAGet16(ds, di + 2) == 0x0000)
        return;
    if ((char)memoryAGet(ds, di) >= (char)0x04)
        return;
    if ((char)memoryAGet(ds, di + 2) >= (char)0x04)
        return;
    ah = 0x0f;
    interrupt(0x10);
    al &= 0x07;
    flags.zero = al == 0x07;
    if (al == 0x07)
        goto loc_11519;
    flags.zero = memoryAGet(ds, di + 1) == 0x01;
loc_11519:
    if (!flags.zero)
        return;
    ax = memoryAGet16(ds, di);
    tx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, di + 2, ax);
    ax = tx;
    memoryASet16(ds, di, ax);
}
void sub_11550()
{
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_11557:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_11557;
loc_1155c:
    in(al, dx);
    if (al & 0x08)
        goto loc_1155c;
}
void sub_11562()
{
    flags.interrupts = false;
    push(ds);
    push(es);
    ax = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x1fbc, es);
    memoryASet16(ds, 0x1fba, bx);
    dx = cs;
    ds = dx;
    dx = 0x16d4;
    ax = 0x2509;
    interrupt(0x21);
    es = pop();
    ds = pop();
    flags.interrupts = true;
}
void sub_11582()
{
    push(ds);
    ax = 0x2509;
    dx = memoryAGet16(ds, 0x1fba);
    ds = memoryAGet16(ds, 0x1fbc);
    interrupt(0x21);
    ds = pop();
}
void sub_115ad()
{
    if (memoryAGet(ds, 0x200e) != 0xff)
        goto loc_115bb;
    memoryASet16(ds, 0x1fc9, 0x4000);
    return;
loc_115bb:
    ax = memoryAGet16(ds, 0x1fc9);
    push(ax);
    bx = 0x0140;
    ax = memoryAGet16(ds, 0x2011);
    if (ax == 0)
        goto loc_115d5;
    if (ax == 0x0190)
        goto loc_115e9;
    bx >>= 1;
    if (ax == 0x00c8)
        goto loc_115e9;
loc_115d5:
    sub_113dc();
    bx = 0x0140;
    di = 0x2006;
    al = memoryAGet(ds, di + 1);
    if ((char)al >= (char)0x03)
        goto loc_115e9;
    bx = 0x00a0;
loc_115e9:
    flags.interrupts = false;
    sub_11602();
    ax = 0xffff;
    ax -= cx;
    bp = ax;
    memoryASet16(ds, 0x1fc9, bp);
    ax = pop();
    if (ax == 0)
        goto loc_11600;
    memoryASet16(ds, 0x1fc9, ax);
loc_11600:
    flags.interrupts = true;
}
void sub_11602()
{
    cx = 0xffff;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_1160c:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_1160c;
loc_11611:
    in(al, dx);
    if (al & 0x08)
        goto loc_11611;
    al = 0x30;
    out(0x43, al);
    al = cl;
    out(0x40, al);
    al = ch;
    out(0x40, al);
    cx = bx;
loc_11624:
    in(al, dx);
    if (al & 0x01)
        goto loc_11624;
loc_11629:
    in(al, dx);
    if (!(al & 0x01))
        goto loc_11629;
    if (--cx)
        goto loc_11624;
    al = 0x06;
    out(0x43, al);
    al = 0x36;
    out(0x43, al);
    in(al, 0x40);
    cl = al;
    in(al, 0x40);
    ch = al;
}
void sub_11644()
{
    flags.interrupts = false;
    push(ds);
    ax = 0x2508;
    push(cs);
    ds = pop();
    dx = 0x17c7;
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x1842;
    ds = ax;
    ax = 0x2560;
    dx = 0x0182;
    interrupt(0x21);
    ds = pop();
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_11667:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_11667;
loc_1166c:
    in(al, dx);
    if (al & 0x08)
        goto loc_1166c;
    flags.interrupts = false;
    cx = memoryAGet16(ds, 0x1fc9);
    al = 0x36;
    out(0x43, al);
    al = cl;
    out(0x40, al);
    al = ch;
    out(0x40, al);
    flags.interrupts = true;
}
void sub_116a9()
{
    push(ds);
    flags.interrupts = false;
    al = 0x36;
    out(0x43, al);
    al = 0;
    out(0x40, al);
    out(0x40, al);
    ax = 0;
    bx = memoryAGet16(ds, 0x1fbe);
    es = memoryAGet16(ds, 0x1fbe + 2);
    ds = ax;
    memoryASet16(ds, 0x0020, bx);
    memoryASet16(ds, 0x0022, es);
    flags.interrupts = true;
    ds = pop();
    cx = memoryAGet16(ds, 0x259c);
    dx = memoryAGet16(ds, 0x259e);
    ah = 0x01;
    interrupt(0x1a);
}
void sub_117c7()
{
    // no return
    push(ax);
    push(ds);
    push(es);
    push(cx);
    push(dx);
    push(bx);
    push(bp);
    push(si);
    push(di);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    ax = 0x19a9;
    ds = ax;
    if (memoryAGet(ds, 0x200e) == 0xff)
        goto loc_1183e;
    sub_15473();
    flags.interrupts = false;
    dx = memoryAGet16(ds, 0x1fda);
    bx = memoryAGet16(ds, 0x1f78);
    bx += memoryAGet16(ds, 0x1f7a);
    bx += 0x0002;
    ah = bh;
    al = 0x0c;
    out(dx, ax);
    ah = bl;
    al++;
    out(dx, ax);
    dl += 0x06;
    flags.interrupts = true;
loc_117fe:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_117fe;
loc_11809:
    in(al, dx);
    if (al & 0x08)
        goto loc_11809;
    flags.interrupts = false;
    cx = memoryAGet16(ds, 0x1fc9);
    al = 0x36;
    out(0x43, al);
    al = cl;
    out(0x40, al);
    al = ch;
    out(0x40, al);
    flags.interrupts = true;
    sub_1553d();
    sub_15827();
loc_1183e:
    dl = 0;
    sub_1418c();
    memoryASet(ds, 0x001c, memoryAGet(ds, 0x001c) + 1);
    al = memoryAGet(ds, 0x001c);
    al &= 0x01;
    if (al == 0)
        goto loc_11861;
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_11861;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_11861;
    ax = 0x0000;
    interrupt(0x60);
loc_11861:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_11874;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_11874;
    ax = 0x0000;
    interrupt(0x61);
loc_11874:
    sub_13e6f();
    if (memoryAGet(ds, 0x2002) != 0x00)
        goto loc_11881;
    sub_1587f();
loc_11881:
    flags.interrupts = false;
    al = memoryAGet(ds, 0x1fe3);
    al++;
    al &= 0x03;
    memoryASet(ds, 0x1fe3, al);
    if (al == 0)
        goto loc_11893;
    sub_118b2();
    goto loc_1189d;
loc_11893:
    ax = 0x189d;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(cs);
    push(ax);
    stop(/*inject carry*/);
    daa();
loc_1189d:
    flags.interrupts = true;
    memoryASet(ds, 0x1fcf, 0xff);
    memoryASet(ds, 0x1fcd, memoryAGet(ds, 0x1fcd) + 1);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    dx = pop();
    cx = pop();
    es = pop();
    ds = pop();
    ax = pop();
    stop(); // iret 
}
void sub_118b2()
{
    al = 0x20;
    out(0x20, al);
}
void sub_11916()
{
    goto loc_11916;
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 5064 bytes
loc_11916:
    push(ds);
    push(es);
    push(ax);
    push(es);
    push(cx);
    memoryASet16(ds, 0x2528, dx);
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_1193a;
    bx = ax;
    ah = 0x3f;
    cx = pop();
    ds = pop();
    dx = pop();
    interrupt(0x21);
    if (flags.carry)
        goto loc_11940;
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_11946;
    es = pop();
    ds = pop();
    return;
loc_1193a:
    dx = 0x2194;
    goto loc_11949;
loc_11940:
    dx = 0x21a5;
    goto loc_11949;
loc_11946:
    dx = 0x21b6;
loc_11949:
    push(dx);
    dx = 0x19a9;
    ds = dx;
    sub_10ff8();
    dx = pop();
    ah = 0x09;
    interrupt(0x21);
    ah = 0x02;
    dl = 0x20;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x2528);
loc_11961:
    dl = memoryAGet(ds, bx);
    if (dl == 0)
        goto loc_1196e;
    bx++;
    ah = 0x02;
    interrupt(0x21);
    goto loc_11961;
loc_1196e:
    dl = 0x0d;
    ah = 0x02;
    interrupt(0x21);
    dl = 0x0a;
    ah = 0x02;
    interrupt(0x21);
    goto loc_104ea;
}
void sub_1197d()
{
    bl = memoryAGet(ds, 0x1f6b);
    bh = 0;
    si = 0x54ee;
    cl = memoryAGet(ds, bx + si);
    cl--;
    ch = 0;
    push(cx);
    cx >>= 1;
    ax = cx;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    cx &= 0x0007;
    si = 0x2551;
    push(cx);
    sub_14bc2();
    cx = pop();
    dx = 0x254c;
    push(ds);
    es = pop();
    di = 0xfcb;
    push(cx);
    cx = es;
    si = di;
    sub_11b79();
    cx = pop();
    if (cx == 0)
        goto loc_119c4;
loc_119b9:
    push(cx);
    di = 0xfcb;
    sub_11ba9();
    cx = pop();
    if (--cx)
        goto loc_119b9;
loc_119c4:
    ah = 0x3e;
    interrupt(0x21);
    ax = pop();
    if (!(ax & 0x0001))
        goto loc_11a00;
    push(ax);
    push(ds);
    es = pop();
    dx = 0x2566;
    ax = 0x5566;
    cx = 0x1180;
    sub_11916();
    ax = pop();
    al >>= 1;
    dh = 0x38;
    mul(dh);
    di = 0xfcb;
    si = 0x5566;
    si += ax;
    cx = 0x000c;
    push(ds);
    es = pop();
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = 0x17ab;
    cx = 0x0010;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_11a00:
    al = memoryAGet(ds, 0x0fe6);
    si = 0x2545;
    al += 0x30;
    memoryASet(ds, si, al);
    dx = 0x253f;
    push(ds);
    es = pop();
    ax = 0x1b4b;
    cx = 0x1000;
    sub_11916();
    al = memoryAGet(ds, 0x0fe6);
    si = 0x2539;
    al += 0x30;
    memoryASet(ds, si, al);
    al = memoryAGet(ds, 0x0fe8);
    if (al == 0)
        goto loc_11a30;
    goto loc_11a5a;
loc_11a30:
    push(ds);
    dx = 0x2534;
    es = memoryAGet16(ds, 0x1ff4);
    di = 0x0010;
    si = 0;
    cx = es;
    sub_11b79();
    ds = pop();
    push(ds);
    di = 0;
    si = 0;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff0);
    sub_11ba9();
    ds = pop();
    ah = 0x3e;
    interrupt(0x21);
    return;
loc_11a5a:
    si = 0x2560;
    al += 0x2f;
    memoryASet(ds, si, al);
    push(ds);
    dx = 0x2559;
    es = memoryAGet16(ds, 0x1ff4);
    si = 0;
    di = 0x0010;
    cx = es;
    sub_11b79();
    ds = pop();
    ah = 0x3e;
    interrupt(0x21);
}
void sub_11a7b()
{
    push(ds);
    cx = 0x0018;
    di = 0x1f23;
    si = 0x0010;
    push(ds);
    es = pop();
    ds = memoryAGet16(ds, 0x1ff4);
    push(di);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    al = 0x1f;
    stosb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    cx = 0x0018;
    di = 0x1f3b;
    di += 0x0018;
    si = 0x0010;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = 0x0008;
    di = 0x1f13;
    di += 0x0008;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = 0x0008;
    di = 0x1f0b;
    push(di);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    al = 0x06;
    stosb<MemAuto, DirAuto>();
    ds = pop();
    push(ds);
    di = 0x8000;
    si = 0x0038;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff4);
    sub_11b42();
    ds = pop();
    push(si);
    sub_18238();
    si = pop();
    push(ds);
    di = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff4);
    sub_11b42();
    ds = pop();
    push(si);
    sub_18243();
    si = pop();
    push(ds);
    di = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff4);
    sub_11b42();
    ds = pop();
    push(si);
    sub_18249();
    si = pop();
    push(ds);
    di = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff4);
    sub_11b42();
    ds = pop();
    push(si);
    sub_1824f();
    si = pop();
    push(ds);
    dx = 0x2534;
    es = memoryAGet16(ds, 0x1ff0);
    di = 0x0010;
    si = 0;
    cx = es;
    sub_11b79();
    ds = pop();
    push(ds);
    di = 0;
    si = 0;
    es = memoryAGet16(ds, 0x1ff0);
    ds = memoryAGet16(ds, 0x1ff0);
    sub_11ba9();
    ds = pop();
    ah = 0x3e;
    interrupt(0x21);
}
void sub_11b42()
{
loc_11b42:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x80)
        return;
    if (al < 0x80)
        goto loc_11b62;
    al = -al;
    al++;
    cl = al;
    ch = 0;
    lodsb<MemAuto, DirAuto>();
loc_11b52:
    stosb<MemAuto, DirAuto>();
    if (di != 0)
        goto loc_11b5e;
    ax = es;
    ax += 0x1000;
    es = ax;
loc_11b5e:
    if (--cx)
        goto loc_11b52;
    goto loc_11b42;
loc_11b62:
    al++;
    cl = al;
    ch = 0;
loc_11b68:
    movsb<MemAuto, MemAuto, DirAuto>();
    if (di != 0)
        goto loc_11b74;
    ax = es;
    ax += 0x1000;
    es = ax;
loc_11b74:
    if (--cx)
        goto loc_11b68;
    goto loc_11b42;
}
void sub_11b79()
{
loc_11b79:
    push(cx);
    sub_11cd9();
    cx = pop();
    if (flags.carry)
        goto loc_11b98;
    if (memoryAGet(ds, 0x1fdf) != 0x00)
        goto loc_11b98;
    sub_11cb9();
    if (memoryAGet(ds, 0x1fdf) != 0x00)
        goto loc_11b98;
    bx = ax;
    ds = cx;
    goto loc_11ba9;
loc_11b98:
    push(dx);
    push(cx);
    push(es);
    push(ds);
    push(di);
    push(si);
    sub_14b1c();
    si = pop();
    di = pop();
    ds = pop();
    es = pop();
    cx = pop();
    dx = pop();
    goto loc_11b79;
loc_11ba9:
    push(ds);
    sub_11baf();
    ds = pop();
}
void sub_11ba9()
{
    push(ds);
    sub_11baf();
    ds = pop();
}
void sub_11baf()
{
    goto loc_11baf;
loc_104d0:
    sub_116a9();
    sub_11582();
    sub_10fa0();
    sub_10ff8();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_104ea;
    ax = 0x000c;
    cx = 0;
    interrupt(0x33);
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 5729 bytes
loc_11baf:
    push(bx);
    flags.direction = true;
    push(bx);
    bp = di;
    cx = 0x000a;
    dx = si;
    sub_11d2e();
    if (!flags.carry)
        goto loc_11bc1;
    goto loc_11c7a;
loc_11bc1:
    ch = memoryAGet(ds, si);
    ch++;
    dh = memoryAGet(ds, si + 1);
    ah = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    bh = memoryAGet(ds, si + 4);
    bl = memoryAGet(ds, si + 5);
    di += bx;
    ax = pop();
    push(cx);
    push(dx);
    ch = memoryAGet(ds, si + 8);
    cl = memoryAGet(ds, si + 9);
    cx -= 0x000a;
    dx = si;
    si += cx;
    bx = ax;
    sub_11d2e();
    if (!flags.carry)
        goto loc_11bf0;
    goto loc_11c7a;
loc_11bf0:
    dx = pop();
    cx = pop();
    si--;
    dl = memoryAGet(ds, si);
    dh ^= dl;
loc_11bf7:
    cl = 0x01;
    sub_11ca3();
    if (ax != 0x0001)
        goto loc_11c47;
    cl = 0x02;
    sub_11ca3();
    if (ax >= 0x0002)
        goto loc_11c1b;
    bx = ax;
    bx += 0x0002;
    cl = al;
    cl += 0x09;
    sub_11c87();
    goto loc_11c6f;
loc_11c1b:
    if (ax != 0x0003)
        goto loc_11c38;
    cl = 0x08;
    sub_11ca3();
    ax += 0x0009;
loc_11c28:
    push(ax);
    cl = 0x08;
    sub_11ca3();
    sub_11c82();
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_11c28;
    goto loc_11c6f;
loc_11c38:
    cl = 0x08;
    sub_11ca3();
    bx = ax;
    cl = 0x0c;
    sub_11c87();
    goto loc_11c6f;
loc_11c47:
    cl = 0x01;
    sub_11ca3();
    if (ax != 0x0001)
        goto loc_11c5c;
    bx = 0x0001;
    cl = 0x08;
    sub_11c87();
    goto loc_11c6f;
loc_11c5c:
    cl = 0x03;
    sub_11ca3();
    ax++;
loc_11c62:
    push(ax);
    cl = 0x08;
    sub_11ca3();
    sub_11c82();
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_11c62;
loc_11c6f:
    if (di <= bp)
        goto loc_11c75;
    goto loc_11bf7;
loc_11c75:
    bx = pop();
    flags.direction = false;
    return;
loc_11c7a:
    ax = 0x19a9;
    ds = ax;
    goto loc_104d0;
}
void sub_11c82()
{
    di--;
    memoryASet(es, di, al);
}
void sub_11c87()
{
    sub_11ca3();
    bx++;
    push(si);
    push(ds);
    push(cx);
    push(es);
    ds = pop();
    cx = bx;
loc_11c92:
    di--;
    si = di;
    si += ax;
    si++;
    bl = memoryAGet(ds, si);
    memoryASet(es, di, bl);
    if (--cx)
        goto loc_11c92;
    cx = pop();
    ds = pop();
    si = pop();
}
void sub_11ca3()
{
    ax = 0;
loc_11ca5:
    ch--;
    if (ch != 0)
        goto loc_11cb0;
    si--;
    dl = memoryAGet(ds, si);
    dh ^= dl;
    ch = 0x08;
loc_11cb0:
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcl(ax, 0x0001);
    cl--;
    if (cl != 0)
        goto loc_11ca5;
}
void sub_11cb9()
{
    push(ds);
    push(dx);
    push(es);
    push(di);
    push(cx);
    push(si);
    if (memoryAGet(ds, 0x1f93) != 0xff)
        goto loc_11ccd;
    if (memoryAGet(ds, 0x1f94) == 0xff)
        goto loc_11cd2;
loc_11ccd:
    ax = 0x3d00;
    interrupt(0x21);
loc_11cd2:
    si = pop();
    cx = pop();
    di = pop();
    es = pop();
    dx = pop();
    ds = pop();
}
void sub_11cd9()
{
    goto loc_11cd9;
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    flags.carry = (dl + 0x06) >= 0x100;
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 5115 bytes
loc_11949:
    push(dx);
    dx = 0x19a9;
    ds = dx;
    sub_10ff8();
    dx = pop();
    ah = 0x09;
    interrupt(0x21);
    ah = 0x02;
    dl = 0x20;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x2528);
loc_11961:
    dl = memoryAGet(ds, bx);
    if (dl == 0)
        goto loc_1196e;
    bx++;
    ah = 0x02;
    interrupt(0x21);
    goto loc_11961;
loc_1196e:
    dl = 0x0d;
    ah = 0x02;
    interrupt(0x21);
    dl = 0x0a;
    ah = 0x02;
    interrupt(0x21);
    goto loc_104ea;
    //   gap of 860 bytes
loc_11cd9:
    push(ds);
    push(dx);
    push(es);
    push(di);
    push(cx);
    push(si);
    if (memoryAGet(ds, 0x1f93) != 0xff)
        goto loc_11cee;
    sub_11e1c();
    sub_11e64();
    if (!flags.carry)
        goto loc_11cfe;
loc_11cee:
    ax = 0x4300;
    cx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_11d05;
    flags.carry = memoryAGet(ds, 0x1fdf) < 0x00;
    if (memoryAGet(ds, 0x1fdf) != 0x00)
        goto loc_11d05;
loc_11cfe:
    si = pop();
    cx = pop();
    di = pop();
    es = pop();
    dx = pop();
    ds = pop();
    return;
loc_11d05:
    push(dx);
    push(cx);
    push(es);
    push(ds);
    push(di);
    push(si);
    ax = 0x19a9;
    ds = ax;
    if (memoryAGet(ds, 0x1f75) == 0x00)
        goto loc_11d22;
    sub_14b1c();
    si = pop();
    di = pop();
    ds = pop();
    es = pop();
    cx = pop();
    dx = pop();
    goto loc_11cee;
loc_11d22:
    si = pop();
    di = pop();
    ds = pop();
    es = pop();
    cx = pop();
    dx = pop();
    dx = 0x2194;
    goto loc_11949;
}
// INJECT: Error: cannot inject carry flag in sub_11d2e()!
// INJECT: Error: cannot inject carry flag in sub_11d2e()!
void sub_11d2e()
{
    push(di);
    push(si);
    push(ds);
    push(bx);
    push(cx);
    push(dx);
    flags.direction = false;
    ax = 0x19a9;
    ds = ax;
    if (memoryAGet(ds, 0x1f93) == 0xff)
        goto loc_11d44;
    goto loc_11e11;
loc_11d44:
    if (memoryAGet(ds, 0x1f94) != 0xff)
        goto loc_11d4e;
    goto loc_11df1;
loc_11d4e:
    ah = 0x23;
    dx = 0x1f95;
    memoryASet16(ds, 0x1fa3, 0x0001);
    interrupt(0x21);
    dx = memoryAGet16(ds, 0x1fb6);
    ax = memoryAGet16(ds, 0x1fb8);
    push(dx);
    flags.carry = ax & 1;
    ax >>= 1;
    dx = rcr(dx, 0x0001);
    flags.carry = ax & 1;
    ax >>= 1;
    dx = rcr(dx, 0x0001);
    flags.carry = ax & 1;
    ax >>= 1;
    dx = rcr(dx, 0x0001);
    flags.carry = ax & 1;
    ax >>= 1;
    dx = rcr(dx, 0x0001);
    ax = pop();
    ax &= 0x000f;
    if (ax != 0)
        goto loc_11d7d;
    goto loc_11d7e;
loc_11d7d:
    dx++;
loc_11d7e:
    if (dx <= memoryAGet16(ds, 0x1f90))
        goto loc_11d87;
    goto loc_11e11;
loc_11d87:
    memoryASet(ds, 0x1f92, memoryAGet(ds, 0x1f92) + 1);
    memoryASet16(ds, 0x1f90, memoryAGet16(ds, 0x1f90) - dx);
    push(ds);
    cx = 0xffff;
    dx = memoryAGet16(ds, 0x1f8a);
    ax = memoryAGet16(ds, 0x1f8c);
    memoryASet16(ds, 0x1f82, dx);
    memoryASet16(ds, 0x1f84, ax);
    memoryASet(ds, 0x1f94, 0xff);
    dx += 0x000d;
    memoryASet16(ds, 0x1f86, dx);
    memoryASet16(ds, 0x1f88, ax);
    push(ax);
    push(dx);
    ds = ax;
    ah = 0x3f;
    interrupt(0x21);
    cx = ax;
    dx = pop();
    ax = pop();
    ds = pop();
    dx += cx;
    push(dx);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    ax += dx;
    dx = pop();
    dx &= 0x000f;
    memoryASet16(ds, 0x1f8a, dx);
    memoryASet16(ds, 0x1f8c, ax);
    di = memoryAGet16(ds, 0x1f82);
    es = memoryAGet16(ds, 0x1f84);
    dx = memoryAGet16(ds, 0x1fb8);
    memoryASet16(es, di + 11, cx);
    si = 0x1f96;
    di += 0x0000;
    cx = 0x000b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
loc_11df1:
    di = pop();
    cx = pop();
    bx = pop();
    es = pop();
    push(es);
    push(di);
    push(ds);
    si = memoryAGet16(ds, 0x1f86);
    ds = memoryAGet16(ds, 0x1f88);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ax = ds;
    ds = pop();
    memoryASet16(ds, 0x1f88, ax);
    memoryASet16(ds, 0x1f86, si);
    dx = pop();
    ds = pop();
    si = pop();
    di = pop();
    stop(/*inject ret*/);
    return;
loc_11e11:
    dx = pop();
    cx = pop();
    bx = pop();
    ds = pop();
    ah = 0x3f;
    interrupt(0x21);
    si = pop();
    di = pop();
}
void sub_11e1c()
{
    push(dx);
    push(es);
    push(ax);
    push(cx);
    push(ds);
    es = pop();
    si = dx;
    cx = 0x0008;
    di = 0x1f96;
loc_11e2b:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x2e)
        goto loc_11e58;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_11e2b;
loc_11e33:
    lodsb<MemAuto, DirAuto>();
    if (al != 0x2e)
        goto loc_11e33;
loc_11e38:
    cx = 0x0003;
    di = 0x1f9e;
loc_11e3f:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        goto loc_11e49;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_11e3f;
    goto loc_11e53;
loc_11e49:
    ax = 0x0002;
    ax -= cx;
    tx = cx;
    cx = ax;
    ax = tx;
    al = 0x20;
    rep_stosb<MemAuto, DirAuto>();
loc_11e53:
    cx = pop();
    ax = pop();
    es = pop();
    dx = pop();
    return;
loc_11e58:
    ax = 0x0007;
    ax -= cx;
    tx = cx;
    cx = ax;
    ax = tx;
    al = 0x20;
    rep_stosb<MemAuto, DirAuto>();
    goto loc_11e38;
}
void sub_11e64()
{
    push(ds);
    cl = memoryAGet(ds, 0x1f92);
    if (cl == 0)
        goto loc_11ea7;
    ch = 0;
    push(ds);
    es = pop();
    ds = memoryAGet16(ds, 0x1f80);
    si = 0;
    di = 0x1f96;
loc_11e7b:
    push(cx);
    push(ds);
    push(si);
    push(di);
    cx = 0x000b;
    repe_cmpsb<MemData, MemData, DirAuto>();
    di = pop();
    si = pop();
    if (cx == 0)
        goto loc_11eaf;
    ds = pop();
    si += memoryAGet16(ds, si + 11);
    si += 0x000d;
    ax = si;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    cx = ds;
    cx += ax;
    ds = cx;
    si &= 0x000f;
    cx = pop();
    if (--cx)
        goto loc_11e7b;
loc_11ea7:
    ds = pop();
    memoryASet(ds, 0x1f94, 0x00);
    flags.carry = true;
    return;
loc_11eaf:
    ax = ds;
    ds = pop();
    cx = pop();
    cx = 0x19a9;
    ds = cx;
    memoryASet16(ds, 0x1f82, si);
    memoryASet16(ds, 0x1f84, ax);
    si += 0x000d;
    memoryASet16(ds, 0x1f86, si);
    memoryASet16(ds, 0x1f88, ax);
    memoryASet(ds, 0x1f94, 0xff);
    ds = pop();
    flags.carry = false;
}
void sub_11ed1()
{
    al = 0;
    memoryASet(ds, 0x1f93, al);
}
void sub_11f19()
{
    if (memoryAGet(ds, 0x002b) != 0xff)
        goto loc_11f23;
    goto loc_11fff;
loc_11f23:
    sub_15d94();
    memoryASet(ds, 0x0050, 0xff);
    si = 0x0088;
    al = memoryAGet(ds, 0x0043);
    memoryASet(ds, 0x0042, al);
    if (al != 0)
        goto loc_11f3b;
    goto loc_11fff;
loc_11f3b:
    push(es);
    if (memoryAGet(ds, si + 38) != 0xff)
        goto loc_11f45;
    goto loc_11feb;
loc_11f45:
    al = memoryAGet(ds, si + 32);
    if (al == 0)
        goto loc_11f54;
    sub_12e04();
    if (!flags.zero)
        goto loc_11f54;
    goto loc_11feb;
loc_11f54:
    al = memoryAGet(ds, si + 36);
    if (!(al & 0x80))
        goto loc_11f5e;
    goto loc_12db5;
loc_11f5e:
    ax = memoryAGet16(ds, si + 8);
    if (ax != 0)
        goto loc_11f68;
    goto loc_12047;
loc_11f68:
    if (!(ax & 0x0002))
        goto loc_11f70;
    goto loc_12350;
loc_11f70:
    if (!(ax & 0x8000))
        goto loc_11f78;
    goto loc_12d0f;
loc_11f78:
    if (!(ax & 0x0004))
        goto loc_11f80;
    goto loc_121b0;
loc_11f80:
    if (!(ax & 0x0400))
        goto loc_11f88;
    goto loc_12a6d;
loc_11f88:
    if (!(ax & 0x0001))
        goto loc_11f90;
    goto loc_122df;
loc_11f90:
    if (!(ax & 0x0008))
        goto loc_11f98;
    goto loc_123bf;
loc_11f98:
    if (!(ax & 0x0010))
        goto loc_11fa0;
    goto loc_123f3;
loc_11fa0:
    if (!(ax & 0x0020))
        goto loc_11fa8;
    goto loc_1254f;
loc_11fa8:
    if (!(ax & 0x0040))
        goto loc_11fb0;
    goto loc_12637;
loc_11fb0:
    if (!(ax & 0x0080))
        goto loc_11fb8;
    goto loc_12693;
loc_11fb8:
    if (!(ax & 0x0100))
        goto loc_11fc0;
    goto loc_127e8;
loc_11fc0:
    if (!(ax & 0x0200))
        goto loc_11fc8;
    goto loc_1287d;
loc_11fc8:
    if (!(ax & 0x0800))
        goto loc_11fd0;
    goto loc_12b35;
loc_11fd0:
    if (!(ax & 0x1000))
        goto loc_11fd8;
    goto loc_122f5;
loc_11fd8:
    if (!(ax & 0x2000))
        goto loc_11fe0;
    goto loc_12326;
loc_11fe0:
    if (!(ax & 0x4000))
        goto loc_11fe8;
    goto loc_12340;
loc_11fe8:
    sub_12ec0();
loc_11feb:
    es = pop();
    si += 0x002d;
    memoryASet(ds, 0x0042, memoryAGet(ds, 0x0042) - 1);
    if (memoryAGet(ds, 0x0042) == 0)
        goto loc_11ff8;
    goto loc_11f3b;
loc_11ff8:
    if (memoryAGet(ds, 0x004b) != 0x00)
        goto loc_12005;
loc_11fff:
    memoryASet(ds, 0x0050, 0x00);
    return;
loc_12005:
    al = memoryAGet(ds, 0x004c);
    if (al == memoryAGet(ds, 0x0043))
        goto loc_1203c;
    cx = 0x002d;
    ah = 0;
    mul(cx);
    ax += 0x0088;
    si = ax;
    if (memoryAGet(ds, si + 32) != 0x00)
        goto loc_12037;
    if (memoryAGet(ds, si + 38) != 0xff)
        goto loc_1202c;
    memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
    goto loc_12005;
loc_1202c:
    if (memoryAGet16(ds, si + 8) & 0x0003)
        goto loc_12037;
    memoryASet(ds, si + 32, 0x4f);
loc_12037:
    memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
    return;
loc_1203c:
    memoryASet(ds, 0x004b, 0x00);
    memoryASet(ds, 0x0050, 0x00);
    return;
loc_12047:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x07;
    memoryASet(ds, si + 40, al);
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) >= (short)0x0010)
        goto loc_1205f;
    goto loc_12142;
loc_1205f:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12068;
    goto loc_12142;
loc_12068:
    sub_15dc6();
    bp = memoryAGet16(ds, si + 2);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_120e9;
    bp++;
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_120d6;
    bp++;
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_120d6;
    bp++;
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_120d6;
    bp++;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
loc_120d6:
    memoryASet16(ds, si + 2, bp);
    if ((short)bp >= (short)0x00b4)
        goto loc_120e2;
    goto loc_11fe8;
loc_120e2:
    memoryASet(ds, si + 38, 0xff);
    goto loc_11feb;
loc_120e9:
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12148;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12148;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12148;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12169;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12169;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12169;
    bp--;
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12169;
    if (memoryAGet(ds, si + 36) & 0x01)
        goto loc_12179;
loc_12142:
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    goto loc_11fe8;
loc_12148:
    memoryASet16(ds, si + 2, bp);
    bp += memoryAGet16(ds, si + 6);
    if ((short)bp <= (short)0x000a)
        goto loc_12156;
    goto loc_11fe8;
loc_12156:
    bp = 0x0009;
    bp -= memoryAGet16(ds, si + 6);
    memoryASet16(ds, si + 2, bp);
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xfff7);
    goto loc_11fe8;
loc_12169:
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0008);
    memoryASet(ds, si + 40, 0x08);
    bp = memoryAGet16(ds, si + 2);
    bp -= 0x0002;
    goto loc_12148;
loc_12179:
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x039a);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0020);
    memoryASet16(ds, si + 16, 0x0048);
    memoryASet16(ds, si + 18, 0x0030);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff4);
    ax = memoryAGet16(ds, 0x0030);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 41, 0x08);
    goto loc_11fe8;
loc_121b0:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x03;
    memoryASet(ds, si + 40, al);
    if (memoryAGet(ds, si + 35) <= 0x10)
        goto loc_12202;
    if (memoryAGet(ds, si + 37) == 0x00)
        goto loc_12202;
    memoryASet16(ds, si + 8, 0x0400);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0baa);
    memoryASet16(ds, si + 16, 0x0080);
    memoryASet16(ds, si + 18, 0x0060);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet16(ds, si + 6, 0xfff0);
    memoryASet(ds, si + 41, 0x08);
    ax = memoryAGet16(ds, 0x003a);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_12202:
    sub_15dc6();
    bp = memoryAGet16(ds, si + 2);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_1224d;
    bp++;
    if ((short)bp < (short)0x00b4)
        goto loc_12219;
    goto loc_120e2;
loc_12219:
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_1224d;
    bp++;
    if ((short)bp < (short)0x00b4)
        goto loc_1222e;
    goto loc_120e2;
loc_1222e:
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_1224d;
    bp++;
    memoryASet(ds, si + 35, memoryAGet(ds, si + 35) + 0x03);
    memoryASet16(ds, si + 2, bp);
    if ((short)bp >= (short)0x00b4)
        goto loc_1224a;
    goto loc_11fe8;
loc_1224a:
    goto loc_120e2;
loc_1224d:
    memoryASet16(ds, si + 2, bp);
    if (memoryAGet(ds, si + 35) <= 0x3c)
        goto loc_122a3;
    memoryASet16(ds, si + 8, 0x0001);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0c2a);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 39, 0x00);
    memoryASet(ds, si + 32, 0x00);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_122a0;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_122a0;
    ax = 0x0408;
    interrupt(0x61);
loc_122a0:
    goto loc_11fe8;
loc_122a3:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_122df:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x0f;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_122ee;
    goto loc_11feb;
loc_122ee:
    memoryASet(ds, si + 38, 0xff);
    goto loc_11feb;
loc_122f5:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x0f;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_12323;
    al = memoryAGet(ds, si + 39);
    cbw();
    push(ax);
    ax += ax;
    ax += ax;
    ax += ax;
    cx = memoryAGet16(ds, si);
    cx += ax;
    bx = memoryAGet16(ds, si + 2);
    sub_16141();
    bx = pop();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12320;
    memoryASet16(ds, si, memoryAGet16(ds, si) + bx);
loc_12320:
    goto loc_11feb;
loc_12323:
    goto loc_120e2;
loc_12326:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x07;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_12335;
    goto loc_11feb;
loc_12335:
    memoryASet(ds, 0x0046, memoryAGet(ds, 0x0046) + 1);
    memoryASet(ds, si + 38, 0xff);
    goto loc_11feb;
loc_12340:
    memoryASet(ds, si + 40, memoryAGet(ds, si + 40) + 1);
    al = memoryAGet(ds, si + 40);
    if (al != 0x0e)
        goto loc_1234d;
    goto loc_120e2;
loc_1234d:
    goto loc_11feb;
loc_12350:
    al = memoryAGet(ds, si + 40);
    al++;
    memoryASet(ds, si + 40, al);
    if (al != 0x34)
        goto loc_1235f;
    goto loc_120e2;
loc_1235f:
    al--;
    if (al == 0)
        goto loc_12366;
    goto loc_11feb;
loc_12366:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_12379;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_12379;
    ax = 0x030c;
    interrupt(0x60);
loc_12379:
    if (memoryAGet16(ds, si + 8) & 0x0100)
        goto loc_12383;
    goto loc_12386;
loc_12383:
    sub_1283b();
loc_12386:
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    al = memoryAGet(ss, bx);
    al &= 0x0f;
    if (al != 0x09)
        goto loc_123b2;
    goto loc_11feb;
loc_123b2:
    if (al != 0x05)
        goto loc_123b9;
    goto loc_11feb;
loc_123b9:
    sub_15df8();
    goto loc_11feb;
loc_123bf:
    sub_15dc6();
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_123e4;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_123e4;
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_123e4:
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xfff7);
    memoryASet(ds, si + 40, 0x00);
    bp = memoryAGet16(ds, si + 2);
    bp++;
    goto loc_12148;
loc_123f3:
    if (memoryAGet(ds, si + 40) != 0x11)
        goto loc_123fc;
    goto loc_1250c;
loc_123fc:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x0f;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_1240f;
    if (al == 0x08)
        goto loc_1240f;
    goto loc_11feb;
loc_1240f:
    bp = memoryAGet16(ds, si);
    ax = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    push(memoryAGet16(ds, si));
    sub_15dc6();
    memoryASet16(ds, si, bp);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    cx = pop();
    bp = memoryAGet16(ds, si + 2);
    if ((short)bp < (short)0x00b4)
        goto loc_1242d;
    goto loc_120e2;
loc_1242d:
    bx = 0x0ff8;
    dl = 0x00;
    cx &= 0x0007;
    if (cx == 0)
        goto loc_1243d;
loc_12437:
    flags.carry = bx & 1;
    bx >>= 1;
    dl = rcr(dl, 0x01);
    if (--cx)
        goto loc_12437;
loc_1243d:
    cl = dl;
    push(bx);
    push(cx);
    sub_15eba();
    ax = pop();
    dx = pop();
    if (dx & bx)
        goto loc_12491;
    if (ax & cx)
        goto loc_12491;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xffef);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_12491:
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    al = memoryAGet(ss, bx);
    al &= 0x0f;
    if (al == 0x09)
        goto loc_124bd;
    goto loc_11fe8;
loc_124bd:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_124d0;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_124d0;
    ax = 0x040a;
    interrupt(0x61);
loc_124d0:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_1250c:
    push(memoryAGet16(ds, si));
    push(memoryAGet16(ds, si + 2));
    ax = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 0x0002);
    sub_15dc6();
    cx = memoryAGet16(ds, si);
    memoryASet16(ds, si + 2, pop());
    memoryASet16(ds, si, pop());
    bx = 0x0ff8;
    dl = 0x00;
    cx &= 0x0007;
    if (cx == 0)
        goto loc_12534;
loc_1252e:
    flags.carry = bx & 1;
    bx >>= 1;
    dl = rcr(dl, 0x01);
    if (--cx)
        goto loc_1252e;
loc_12534:
    cl = dl;
    push(di);
    push(cx);
    push(bx);
    push(bp);
    sub_15eba();
    bp = pop();
    bx = pop();
    cx = pop();
    di = pop();
    di += memoryAGet16(ds, 0x0004);
    sub_15eba();
    memoryASet(ds, si + 40, 0x00);
    goto loc_1240f;
loc_1254f:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x07;
    memoryASet(ds, si + 40, al);
    if ((char)al > (char)0x03)
        goto loc_12560;
    goto loc_125e1;
loc_12560:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    ax = memoryAGet16(ds, si + 2);
    ax += memoryAGet16(ds, si + 6);
    if (ax <= 0x000a)
        goto loc_12591;
    bp = memoryAGet16(ds, si);
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) - ax);
    sub_15dc6();
    memoryASet16(ds, si, bp);
    dx = memoryAGet16(ds, 0x0004);
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    di -= dx;
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12591;
    goto loc_11fe8;
loc_12591:
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xffdf);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    al = memoryAGet(ds, si + 39);
    al = -al;
    memoryASet(ds, si + 39, al);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    goto loc_11fe8;
loc_125e1:
    bp = memoryAGet16(ds, si + 2);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 0x0007);
    ah = 0;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
    sub_15dc6();
    memoryASet16(ds, si + 2, bp);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_125fd;
    goto loc_11fe8;
loc_125fd:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 0x0002);
    al = memoryAGet(ds, si + 40);
    ah = 0;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - ax);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xffdf);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0040);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x06b2);
    memoryASet16(ds, si + 16, 0x0048);
    memoryASet16(ds, si + 18, 0x0030);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 41, 0x08);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_12637:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x07;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_12654;
    if ((char)al < (char)0x05)
        goto loc_1264a;
    goto loc_11feb;
loc_1264a:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 0x0002);
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_12654:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_12693:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x0f;
    memoryASet(ds, si + 40, al);
    if (al != 0)
        goto loc_126a2;
    goto loc_126e4;
loc_126a2:
    if (al != 0x0a)
        goto loc_126d7;
    al = memoryAGet(ds, si + 33);
    if (al > 0x03)
        goto loc_126d7;
    push(ax);
    push(es);
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_126c2;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_126c2;
    ax = 0x0313;
    interrupt(0x60);
loc_126c2:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_126d5;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_126d5;
    ax = 0x0412;
    interrupt(0x61);
loc_126d5:
    es = pop();
    ax = pop();
loc_126d7:
    if (al == 0x09)
        goto loc_126de;
    goto loc_11fe8;
loc_126de:
    sub_15f0f();
    goto loc_11feb;
loc_126e4:
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    bp = ax;
    if ((short)memoryAGet16(ds, si) > (short)0x0010)
        goto loc_126f7;
    goto loc_12763;
loc_126f7:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12700;
    goto loc_12763;
loc_12700:
    sub_15dc6();
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12763;
    memoryASet16(ds, si, memoryAGet16(ds, si) + bp);
    sub_15dc6();
    di -= memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12763;
    memoryASet(ds, si + 33, memoryAGet(ds, si + 33) - 1);
    if (memoryAGet(ds, si + 33) != 0)
        goto loc_12726;
    goto loc_127a5;
loc_12726:
    push(memoryAGet16(ds, si));
    memoryASet16(ds, si, memoryAGet16(ds, si) + bp);
    memoryASet16(ds, si, memoryAGet16(ds, si) + bp);
    sub_15dc6();
    memoryASet16(ds, si, pop());
    push(ax);
    ax = memoryAGet16(ds, 0x0004);
    di -= ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di -= ax;
    ax = pop();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12763;
    if ((short)memoryAGet16(ds, si) <= (short)0x0010)
        goto loc_12763;
    if ((short)memoryAGet16(ds, si) >= (short)0x0680)
        goto loc_12763;
    ax = memoryAGet16(ds, si + 2);
    ax += memoryAGet16(ds, si + 6);
    if ((short)ax <= (short)0x000a)
        goto loc_12760;
    goto loc_11fe8;
loc_12760:
    goto loc_12766;
loc_12763:
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
loc_12766:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_127a5:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0008);
    memoryASet16(ds, si + 12, 0x126b);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x08);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) | 0x80);
    bp = memoryAGet16(ds, si + 2);
    goto loc_12148;
loc_127e8:
    memoryASet(ds, si + 40, memoryAGet(ds, si + 40) + 1);
    memoryASet(ds, si + 40, memoryAGet(ds, si + 40) & 0x0f);
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_127fc;
    goto loc_11feb;
loc_127fc:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    sub_1283b();
    goto loc_11feb;
    //   gap of 66 bytes
loc_1287d:
    memoryASet(ds, si + 40, memoryAGet(ds, si + 40) + 1);
    memoryASet(ds, si + 40, memoryAGet(ds, si + 40) & 0x1f);
    al = memoryAGet(ds, si + 40);
    al &= 0x0f;
    if ((char)al < (char)0x0b)
        goto loc_12890;
    goto loc_1293a;
loc_12890:
    if ((char)al >= (char)0x02)
        goto loc_12897;
    goto loc_11feb;
loc_12897:
    if ((char)al <= (char)0x05)
        goto loc_1289e;
    goto loc_11feb;
loc_1289e:
    al -= 0x02;
    cbw();
    sub_15fac();
    al = memoryAGet(ds, si + 40);
    if (al == 0x05)
        goto loc_128ae;
    goto loc_11feb;
loc_128ae:
    cx = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    bx -= 0x0006;
    al = memoryAGet(ds, si + 39);
    cbw();
    bp = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    cx += ax;
    sub_16141();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_128d1;
    goto loc_11feb;
loc_128d1:
    cx += bp;
    sub_16141();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_128e0;
    goto loc_11feb;
loc_128e0:
    cx += bp;
    sub_16141();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_128ef;
    goto loc_11feb;
loc_128ef:
    cx += bp;
    sub_16141();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_128fe;
    goto loc_11feb;
loc_128fe:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11feb;
loc_1293a:
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) < (short)0x0010)
        goto loc_129c1;
    if ((short)memoryAGet16(ds, si) >= (short)0x0680)
        goto loc_129c1;
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12958;
    goto loc_12a00;
loc_12958:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12969;
    goto loc_12a00;
loc_12969:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_1297a;
    goto loc_12a00;
loc_1297a:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xfdff);
    goto loc_11fe8;
loc_129c1:
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_12a00:
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    bx -= 0x0340;
    al = memoryAGet(ds, si + 39);
    cbw();
    bx += ax;
    bx += ax;
    al = memoryAGet(ss, bx);
    al &= 0x0f;
    if (al == 0x09)
        goto loc_12a57;
    if (al != 0x07)
        goto loc_12a43;
    al = memoryAGet(ds, si + 39);
    if ((char)al >= 0)
        goto loc_129c1;
    goto loc_11fe8;
loc_12a43:
    if (al == 0x08)
        goto loc_12a4a;
    goto loc_11fe8;
loc_12a4a:
    al = memoryAGet(ds, si + 39);
    if ((char)al >= 0)
        goto loc_12a54;
    goto loc_129c1;
loc_12a54:
    goto loc_11fe8;
loc_12a57:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12a6a;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12a6a;
    ax = 0x040a;
    interrupt(0x61);
loc_12a6a:
    goto loc_129c1;
loc_12a6d:
    bx = 0x2698;
    bx += memoryAGet16(ds, si + 14);
    al = memoryAGet(ds, bx);
    memoryASet(ds, si + 40, al);
    al = memoryAGet(ds, bx + 1);
    memoryASet16(ds, si + 14, memoryAGet16(ds, si + 14) + 0x0002);
    cbw();
    if (al == 0x03)
        goto loc_12a92;
    if (al == 0x02)
        goto loc_12abe;
    if (al == 0x01)
        goto loc_12adc;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + ax);
    goto loc_12b28;
loc_12a92:
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_12b28;
loc_12abe:
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_12b28;
loc_12adc:
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12aec;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_12b28;
loc_12aec:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_12b28:
    if ((short)memoryAGet16(ds, si + 2) >= (short)0x00b4)
        goto loc_12b32;
    goto loc_11fe8;
loc_12b32:
    goto loc_120e2;
loc_12b35:
    al = memoryAGet(ds, si + 40);
    al++;
    if (al != 0x18)
        goto loc_12b40;
    al = 0;
loc_12b40:
    memoryASet(ds, si + 40, al);
    if (al != 0)
        goto loc_12b4a;
    goto loc_12be1;
loc_12b4a:
    if (al != 0x0f)
        goto loc_12b51;
    goto loc_12b66;
loc_12b51:
    if (al != 0x03)
        goto loc_12b58;
    goto loc_12bf1;
loc_12b58:
    if ((char)al < (char)0x03)
        goto loc_12b5d;
    goto loc_11feb;
loc_12b5d:
    al--;
    cbw();
    sub_1606b();
    goto loc_11feb;
loc_12b66:
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) >= (short)0x0010)
        goto loc_12b74;
    goto loc_12cbb;
loc_12b74:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12b7d;
    goto loc_12cbb;
loc_12b7d:
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) >= (short)0x0010)
        goto loc_12b87;
    goto loc_12cbb;
loc_12b87:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12b90;
    goto loc_12cbb;
loc_12b90:
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12b9d;
    goto loc_12c76;
loc_12b9d:
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xf7ff);
    goto loc_11fe8;
loc_12be1:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    if ((short)memoryAGet16(ds, si + 2) < (short)0x00b4)
        goto loc_12bee;
    goto loc_120e2;
loc_12bee:
    goto loc_11fe8;
loc_12bf1:
    al = memoryAGet(ds, si + 39);
    cbw();
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) >= (short)0x0010)
        goto loc_12bff;
    goto loc_12cbb;
loc_12bff:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12c08;
    goto loc_12cbb;
loc_12c08:
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    if ((short)memoryAGet16(ds, si) >= (short)0x0010)
        goto loc_12c12;
    goto loc_12cbb;
loc_12c12:
    if ((short)memoryAGet16(ds, si) < (short)0x0680)
        goto loc_12c1b;
    goto loc_12cbb;
loc_12c1b:
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    if ((short)memoryAGet16(ds, si + 2) < (short)0x00b4)
        goto loc_12c28;
    goto loc_120e2;
loc_12c28:
    sub_15dc6();
    al = memoryAGet(es, di);
    al &= ah;
    if (al != 0)
        goto loc_12c76;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xf7ff);
    goto loc_11fe8;
loc_12c76:
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    al = memoryAGet(ss, bx);
    al &= 0x0f;
    if (al == 0x09)
        goto loc_12cfa;
    if (al != 0x07)
        goto loc_12cad;
    al = memoryAGet(ds, si + 39);
    if ((char)al >= 0)
        goto loc_12cbb;
    goto loc_11fe8;
loc_12cad:
    if (al == 0x08)
        goto loc_12cb4;
    goto loc_11fe8;
loc_12cb4:
    al = memoryAGet(ds, si + 39);
    if ((char)al >= 0)
        goto loc_12cbb;
loc_12cbb:
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_11fe8;
loc_12cfa:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12d0d;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12d0d;
    ax = 0x040a;
    interrupt(0x61);
loc_12d0d:
    goto loc_12cbb;
loc_12d0f:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x0f;
    memoryASet(ds, si + 40, al);
    if (al != 0)
        goto loc_12d78;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0002);
    memoryASet16(ds, si + 10, 0x0008);
    memoryASet16(ds, si + 12, 0x180b);
    memoryASet16(ds, si + 16, 0x0280);
    memoryASet16(ds, si + 18, 0x01e0);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 6, 0xffe7);
    memoryASet16(ds, si + 4, 0xfff0);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x003c);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 34, 0x0f);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12d6a;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12d6a;
    ax = 0x040c;
    interrupt(0x61);
loc_12d6a:
    if (!(memoryAGet16(ds, si + 8) & 0x0004))
        goto loc_12d75;
    memoryASet(ds, si + 34, 0x00);
loc_12d75:
    goto loc_11feb;
loc_12d78:
    if (al != 0x05)
        goto loc_12d83;
    if (memoryAGet(ds, 0x004b) != 0xff)
        goto loc_12d83;
loc_12d83:
    sub_15dc6();
    bp = memoryAGet16(ds, si + 2);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12d93;
    goto loc_120d6;
loc_12d93:
    bp++;
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12da2;
    goto loc_120d6;
loc_12da2:
    bp++;
    di += memoryAGet16(ds, 0x0004);
    al = memoryAGet(es, di);
    al &= ah;
    if (al == 0)
        goto loc_12db1;
    goto loc_120d6;
loc_12db1:
    bp++;
    goto loc_120d6;
loc_12db5:
    al = memoryAGet(ds, si + 40);
    al++;
    al &= 0x07;
    memoryASet(ds, si + 40, al);
    if (al == 0)
        goto loc_12dc4;
    goto loc_11feb;
loc_12dc4:
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x09);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x7f);
    goto loc_11fe8;
}
void sub_1283b()
{
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    ax -= 0x0004;
    bx -= 0x0006;
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    push(si);
    push(di);
    push(es);
    push(ss);
    es = pop();
    di = bx;
    si += 0x0016;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x019d;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x019d;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
    di = pop();
    si = pop();
}
void sub_12e04()
{
    al = 0x01;
    memoryASet(ds, si + 32, memoryAGet(ds, si + 32) - 1);
    if (memoryAGet(ds, si + 32) != 0)
        goto loc_12e60;
    if (memoryAGet16(ds, si + 8) & 0x5404)
        goto loc_12e63;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x8000);
    memoryASet16(ds, si + 10, 0x0008);
    memoryASet16(ds, si + 12, 0x153b);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12e5e;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12e5e;
    ax = 0x0405;
    interrupt(0x61);
loc_12e5e:
    al = 0;
loc_12e60:
    flags.zero = al == 0;
    return;
loc_12e63:
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0002);
    memoryASet16(ds, si + 10, 0x0008);
    memoryASet16(ds, si + 12, 0x180b);
    memoryASet16(ds, si + 16, 0x0280);
    memoryASet16(ds, si + 18, 0x01e0);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 6, 0xffe7);
    memoryASet16(ds, si + 4, 0xfff0);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x003c);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 34, 0x0f);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12eb2;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12eb2;
    ax = 0x040c;
    interrupt(0x61);
loc_12eb2:
    if (!(memoryAGet16(ds, si + 8) & 0x0004))
        goto loc_12ebd;
    memoryASet(ds, si + 34, 0x00);
loc_12ebd:
    al = 0;
    flags.zero = true;
}
void sub_12ec0()
{
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    if ((short)bx >= (short)0x00b0)
        goto loc_12f3a;
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    al = memoryAGet(ss, bx);
    push(ax);
    memoryASet(ds, si + 44, al);
    al = memoryAGet(ds, si + 39);
    cbw();
    bx -= 0x0340;
    bx += ax;
    bx += ax;
    al = memoryAGet(ss, bx);
    memoryASet(ds, si + 43, al);
    ax = pop();
    ah = al;
    al &= 0x0f;
    ah >>= 1;
    ah >>= 1;
    ah >>= 1;
    ah >>= 1;
    ah &= 0x0f;
    if (al == 0)
        goto loc_12f3a;
    al--;
    if (al == 0)
        goto loc_12f3b;
    al--;
    if (al != 0)
        goto loc_12f1e;
    goto loc_12fa2;
loc_12f1e:
    al--;
    if (al != 0)
        goto loc_12f25;
    goto loc_12fac;
loc_12f25:
    al--;
    if (al != 0)
        goto loc_12f2c;
    goto loc_12fb6;
loc_12f2c:
    al--;
    if (al != 0)
        goto loc_12f33;
    goto loc_12ff8;
loc_12f33:
    al--;
    if (al != 0)
        goto loc_12f3a;
    goto loc_1304f;
loc_12f3a:
    return;
loc_12f3b:
    if (memoryAGet16(ds, si + 8) & 0x0004)
        goto loc_12f3a;
    memoryASet16(ds, si + 8, 0x2000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0efa);
    memoryASet16(ds, si + 16, 0x004e);
    memoryASet16(ds, si + 18, 0x0034);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff3);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x0032);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_12f8e;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_12f8e;
    ax = 0x0302;
    interrupt(0x60);
loc_12f8e:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_12fa1;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_12fa1;
    ax = 0x0410;
    interrupt(0x61);
loc_12fa1:
    return;
loc_12fa2:
    if (memoryAGet(ds, si + 39) == 0xff)
        goto loc_12f3a;
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    return;
loc_12fac:
    if (memoryAGet(ds, si + 39) == 0x01)
        goto loc_12f3a;
    memoryASet(ds, si + 39, -memoryAGet(ds, si + 39));
    return;
loc_12fb6:
    al = ah;
    ah = 0;
    dx = 0x001c;
    mul(dx);
    di = ax;
    di += 0x17cb;
    if (!(memoryAGet16(ds, di) & 0x0002))
        goto loc_12fce;
    goto loc_12f3a;
loc_12fce:
    memoryASet16(ds, di, memoryAGet16(ds, di) | 0x0002);
    memoryASet(ds, si + 38, 0xff);
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_12fdf;
    goto loc_12f3a;
loc_12fdf:
    if (memoryAGet(ds, 0x25a7) & 0x03)
        goto loc_12fe9;
    goto loc_12f3a;
loc_12fe9:
    al = memoryAGet(ds, di + 27);
    if (al != 0)
        goto loc_12ff3;
    goto loc_12f3a;
loc_12ff3:
    ah = 0x04;
    interrupt(0x61);
    return;
loc_12ff8:
    if (!(memoryAGet16(ds, si + 8) & 0x1000))
        goto loc_13002;
    goto loc_12f3a;
loc_13002:
    memoryASet16(ds, si + 8, 0x1000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x03e2);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_1304e;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_1304e;
    ax = 0x0411;
    interrupt(0x61);
loc_1304e:
    return;
loc_1304f:
    if (!(memoryAGet16(ds, si + 8) & 0x4000))
        goto loc_13059;
    goto loc_12f3a;
loc_13059:
    memoryASet16(ds, si + 8, 0x4000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0f21);
    memoryASet16(ds, si + 16, 0x008c);
    memoryASet16(ds, si + 18, 0x0070);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff2);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x003e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    if (memoryAGet(ds, 0x2010) != 0xff)
        return;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        return;
    ax = 0x040d;
    interrupt(0x61);
}
void sub_130a6()
{
    if (memoryAGet(ds, 0x002b) != 0xff)
        goto loc_130b0;
    return;
loc_130b0:
    if (memoryAGet(ds, 0x0055) == 0xff)
        goto loc_130ba;
    return;
loc_130ba:
    memoryASet(ds, 0x0048, memoryAGet(ds, 0x0048) - 1);
    if (memoryAGet(ds, 0x0048) == 0)
        goto loc_130c3;
    return;
loc_130c3:
    al = memoryAGet(ds, 0x0049);
    memoryASet(ds, 0x0048, al);
    si = 0x0088;
    al = memoryAGet(ds, 0x0047);
    ah = memoryAGet(ds, 0x0043);
    if (al == ah)
        return;
    bl = ah;
    bh = 0;
    bx &= 0x0003;
    bx <<= 1;
    bx <<= 1;
    bx += 0x0e98;
    cl = 0x2d;
    al = ah;
    mul(cl);
    si += ax;
    cx = 0x002d;
    di = si;
loc_130f3:
    memoryASet(ds, di, 0x00);
    di++;
    if (--cx)
        goto loc_130f3;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 2, ax);
    memoryASet(ds, si + 39, 0x01);
    memoryASet(ds, si + 37, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0004);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0a42);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 35, 0x03);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 41, 0x04);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet(ds, 0x0043, memoryAGet(ds, 0x0043) + 1);
}
void sub_13150()
{
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_131bd;
    if (memoryAGet(ds, 0x0050) != 0xff)
        goto loc_13161;
    goto loc_131bd;
loc_13161:
    if (memoryAGet(ds, 0x0063) == 0x00)
        goto loc_131bd;
    ax = memoryAGet16(ds, 0x0014);
    ax &= 0x0001;
    if (ax == 0)
        goto loc_131be;
    if (memoryAGet(ds, 0x0061) == 0xff)
        goto loc_131bd;
    memoryASet(ds, 0x0061, 0xff);
    si = memoryAGet16(ds, 0x0058);
    al = memoryAGet(ds, 0x0082);
    if ((char)al < (char)0x02)
        goto loc_131bd;
    if (al != 0x02)
        goto loc_1318c;
    goto loc_1329b;
loc_1318c:
    if (al != 0x03)
        goto loc_13193;
    goto loc_13557;
loc_13193:
    if (al != 0x04)
        goto loc_1319a;
    goto loc_131c4;
loc_1319a:
    if (al != 0x05)
        goto loc_131a1;
    goto loc_13336;
loc_131a1:
    if (al != 0x06)
        goto loc_131a8;
    goto loc_132bd;
loc_131a8:
    if (al != 0x07)
        goto loc_131af;
    goto loc_134ce;
loc_131af:
    if (al != 0x08)
        goto loc_131b6;
    goto loc_13598;
loc_131b6:
    if (al != 0x09)
        goto loc_131bd;
    goto loc_1320d;
loc_131bd:
    return;
loc_131be:
    memoryASet(ds, 0x0061, 0x00);
    return;
loc_131c4:
    if (memoryAGet(ds, 0x0070) == 0x00)
        goto loc_1320c;
    if (memoryAGet(ds, si + 32) != 0x00)
        goto loc_1320c;
    if (memoryAGet16(ds, si + 8) & 0xc003)
        goto loc_1320c;
    memoryASet(ds, 0x0070, memoryAGet(ds, 0x0070) - 1);
    memoryASet(ds, 0x0072, 0x00);
    memoryASet(ds, si + 32, 0x4f);
loc_131e5:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_131f8;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_131f8;
    ax = 0x0313;
    interrupt(0x60);
loc_131f8:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_1320b;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_1320b;
    ax = 0x0404;
    interrupt(0x61);
loc_1320b:
    return;
loc_1320c:
    return;
loc_1320d:
    if (memoryAGet(ds, 0x007f) == 0x00)
        goto loc_13285;
    al = memoryAGet(ds, si + 44);
    al &= 0x0f;
    if (al == 0x09)
        goto loc_13285;
    if (memoryAGet16(ds, si + 8) & 0xf57f)
        goto loc_13271;
loc_13224:
    memoryASet(ds, 0x007f, memoryAGet(ds, 0x007f) - 1);
    memoryASet(ds, 0x0081, 0x00);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xf57f);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0010);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x032a);
    memoryASet16(ds, si + 16, 0x0070);
    memoryASet16(ds, si + 18, 0x0054);
    memoryASet(ds, si + 40, 0x11);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff4);
    memoryASet(ds, si + 41, 0x00);
    ax = memoryAGet16(ds, 0x0038);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 31, 0x08);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_131e5;
loc_13271:
    if (memoryAGet(ds, 0x005f) == 0xff)
        goto loc_13285;
    si = memoryAGet16(ds, 0x005a);
    if (memoryAGet16(ds, si + 8) & 0xf57f)
        goto loc_13285;
    goto loc_13224;
loc_13285:
    goto loc_1320c;
loc_13287:
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_1329a;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_1329a;
    ax = 0x0412;
    interrupt(0x61);
loc_1329a:
    return;
loc_1329b:
    if (memoryAGet(ds, 0x006a) == 0x00)
        goto loc_132ba;
    if (memoryAGet(ds, si + 36) & 0x01)
        goto loc_132ba;
    if (memoryAGet16(ds, si + 8) & 0x0103)
        goto loc_132ba;
    memoryASet(ds, 0x006a, memoryAGet(ds, 0x006a) - 1);
    memoryASet(ds, si + 36, 0x01);
    goto loc_131e5;
loc_132ba:
    goto loc_1320c;
loc_132bd:
    if (memoryAGet(ds, 0x0076) == 0x00)
        goto loc_1331f;
    ax = memoryAGet16(ds, si + 2);
    ax += memoryAGet16(ds, si + 6);
    if (ax <= 0x000a)
        goto loc_1331f;
    if (memoryAGet16(ds, si + 8) & 0xf5ef)
        goto loc_13322;
loc_132d6:
    memoryASet(ds, 0x0076, memoryAGet(ds, 0x0076) - 1);
    memoryASet(ds, 0x0078, 0x00);
    memoryASet16(ds, si + 8, 0x0080);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff3);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 33, 0x0c);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x06fa);
    memoryASet16(ds, si + 16, 0x0068);
    memoryASet16(ds, si + 18, 0x004e);
    memoryASet(ds, si + 41, 0x10);
    ax = memoryAGet16(ds, 0x0036);
    memoryASet(ds, si + 42, 0xff);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_131e5;
loc_1331f:
    goto loc_1320c;
loc_13322:
    if (memoryAGet(ds, 0x005f) == 0xff)
        goto loc_1331f;
    si = memoryAGet16(ds, 0x005a);
    if (memoryAGet16(ds, si + 8) & 0xf5ef)
        goto loc_1331f;
    goto loc_132d6;
loc_13336:
    if (memoryAGet(ds, 0x0073) == 0x00)
        goto loc_13345;
    ax = memoryAGet16(ds, si + 8);
    ax &= 0xf56f;
    if (ax == 0)
        goto loc_13348;
loc_13345:
    goto loc_1320c;
loc_13348:
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    ax -= 0x0004;
    bx -= 0x0006;
    bx -= 0x0010;
    ax >>= 1;
    ax >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(ax);
    push(dx);
    ax = bx;
    dx = 0x01a0;
    mul(dx);
    dx = pop();
    bx = pop();
    bx += ax;
    bx += 0x0012;
    ax = memoryAGet16(ss, bx);
    if (al == 0x02)
        goto loc_13345;
    if (al == 0x0a)
        goto loc_13345;
    if (al == 0x03)
        goto loc_13345;
    if (ah == 0x02)
        goto loc_13345;
    if (ah == 0x0a)
        goto loc_13345;
    if (ah == 0x03)
        goto loc_13345;
    al = memoryAGet(ss, bx + 2);
    if (al == 0x02)
        goto loc_13345;
    if (al == 0x0a)
        goto loc_13345;
    if (al == 0x03)
        goto loc_13345;
    ax = memoryAGet16(ss, bx + 416);
    if (al == 0x02)
        goto loc_13345;
    if (al == 0x0a)
        goto loc_13345;
    if (al == 0x03)
        goto loc_13345;
    if (ah == 0x02)
        goto loc_13345;
    if (ah == 0x0a)
        goto loc_13345;
    if (ah == 0x03)
        goto loc_13345;
    al = memoryAGet(ss, bx + 418);
    if (al != 0x02)
        goto loc_133c8;
    goto loc_13345;
loc_133c8:
    if (al != 0x0a)
        goto loc_133cf;
    goto loc_134cb;
loc_133cf:
    if (al != 0x03)
        goto loc_133d6;
    goto loc_134cb;
loc_133d6:
    ax = memoryAGet16(ss, bx + 832);
    if (al != 0x02)
        goto loc_133e2;
    goto loc_134cb;
loc_133e2:
    if (al != 0x0a)
        goto loc_133e9;
    goto loc_134cb;
loc_133e9:
    if (al != 0x03)
        goto loc_133f0;
    goto loc_134cb;
loc_133f0:
    if (ah != 0x02)
        goto loc_133f8;
    goto loc_134cb;
loc_133f8:
    if (ah != 0x0a)
        goto loc_13400;
    goto loc_134cb;
loc_13400:
    if (ah != 0x03)
        goto loc_13408;
    goto loc_134cb;
loc_13408:
    al = memoryAGet(ss, bx + 834);
    if (al != 0x02)
        goto loc_13414;
    goto loc_134cb;
loc_13414:
    if (al != 0x0a)
        goto loc_1341b;
    goto loc_134cb;
loc_1341b:
    if (al != 0x03)
        goto loc_13422;
    goto loc_134cb;
loc_13422:
    memoryASet(ds, 0x0073, memoryAGet(ds, 0x0073) - 1);
    memoryASet(ds, 0x0075, 0x00);
    memoryASet16(ds, si + 8, 0x0100);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 10, 0x0008);
    memoryASet16(ds, si + 12, 0x0f9b);
    memoryASet16(ds, si + 16, 0x005a);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 41, 0x00);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    ax = memoryAGet16(ds, 0x002e);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0x00);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    push(si);
    push(ds);
    es = pop();
    di = bx;
    si += 0x0016;
    tx = si;
    si = di;
    di = tx;
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x02);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x0a);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x03);
    si++;
    stosb<MemAuto, DirAuto>();
    si += 0x019d;
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x02);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x0a);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x03);
    si++;
    stosb<MemAuto, DirAuto>();
    si += 0x019d;
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x02);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x0a);
    si++;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(ss, si);
    memoryASet(ss, si, 0x03);
    si++;
    stosb<MemAuto, DirAuto>();
    si = pop();
    goto loc_131e5;
loc_134cb:
    goto loc_1320c;
loc_134ce:
    if (memoryAGet(ds, 0x0079) == 0x00)
        goto loc_13540;
    if (memoryAGet16(ds, si + 8) & 0xf76f)
        goto loc_13543;
loc_134dc:
    al = memoryAGet(ds, si + 43);
    al &= 0x0f;
    ah = 0x07;
    if (memoryAGet(ds, si + 39) == 0x01)
        goto loc_134eb;
    ah = 0x08;
loc_134eb:
    if (al == ah)
        goto loc_13540;
    if (al != 0x09)
        goto loc_134f6;
    goto loc_13287;
loc_134f6:
    memoryASet(ds, 0x0079, memoryAGet(ds, 0x0079) - 1);
    memoryASet(ds, 0x007b, 0x00);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xf56f);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0200);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff6);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x07ca);
    memoryASet16(ds, si + 16, 0x0050);
    memoryASet16(ds, si + 18, 0x003c);
    memoryASet(ds, si + 41, 0x20);
    memoryASet(ds, si + 42, 0xff);
    ax = memoryAGet16(ds, 0x0034);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    goto loc_131e5;
loc_13540:
    goto loc_1320c;
loc_13543:
    if (memoryAGet(ds, 0x005f) == 0xff)
        goto loc_13540;
    si = memoryAGet16(ds, 0x005a);
    if (memoryAGet16(ds, si + 8) & 0xf76f)
        goto loc_13540;
    goto loc_134dc;
loc_13557:
    if (memoryAGet(ds, 0x006d) == 0x00)
        goto loc_1357b;
    if (memoryAGet(ds, si + 37) != 0x00)
        goto loc_1357b;
    if (memoryAGet16(ds, si + 8) & 0x0103)
        goto loc_1357b;
    memoryASet(ds, si + 37, 0xff);
    memoryASet(ds, 0x006d, memoryAGet(ds, 0x006d) - 1);
    memoryASet(ds, 0x006f, 0x00);
    goto loc_131e5;
loc_1357b:
    goto loc_1320c;
    //   gap of 26 bytes
loc_13598:
    if (memoryAGet(ds, 0x007c) != 0x00)
        goto loc_135a2;
    goto loc_1361c;
loc_135a2:
    if (!(memoryAGet16(ds, si + 8) & 0xfd6f))
        goto loc_135ac;
    goto loc_1361f;
loc_135ac:
    al = memoryAGet(ds, si + 44);
    al &= 0x0f;
    if (al == 0x09)
        goto loc_1361c;
    al = memoryAGet(ds, si + 43);
    al &= 0x0f;
    ah = 0x07;
    if (memoryAGet(ds, si + 39) == 0x01)
        goto loc_135c4;
    ah = 0x08;
loc_135c4:
    if (al == ah)
        goto loc_1361c;
    if (al != 0x09)
        goto loc_135cf;
    goto loc_13287;
loc_135cf:
    memoryASet(ds, 0x007c, memoryAGet(ds, 0x007c) - 1);
    memoryASet(ds, 0x007e, 0x00);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0xfd6f);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) | 0x0800);
    memoryASet16(ds, si + 4, 0xfff8);
    memoryASet16(ds, si + 6, 0xfff3);
    memoryASet(ds, si + 40, 0x00);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x090a);
    memoryASet16(ds, si + 16, 0x0068);
    memoryASet16(ds, si + 18, 0x004e);
    memoryASet(ds, si + 41, 0x18);
    ax = memoryAGet16(ds, 0x0036);
    memoryASet16(ds, si + 20, ax);
    memoryASet(ds, si + 42, 0xff);
    memoryASet(ds, si + 36, memoryAGet(ds, si + 36) & 0x01);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_131e5;
loc_1361c:
    goto loc_1320c;
loc_1361f:
    if (memoryAGet(ds, 0x005f) == 0xff)
        goto loc_1361c;
    si = memoryAGet16(ds, 0x005a);
    if (memoryAGet16(ds, si + 8) & 0xfd6f)
        goto loc_1361c;
    goto loc_135ac;
}
void sub_13634()
{
    di = 0x0088;
    cl = memoryAGet(ds, 0x0043);
    if (cl == 0)
        goto loc_1368d;
    ch = 0;
    memoryASet(ds, 0x0045, ch);
loc_13645:
    push(cx);
    push(di);
    if (memoryAGet(ds, di + 38) == 0xff)
        goto loc_1367d;
    memoryASet(ds, 0x0045, memoryAGet(ds, 0x0045) + 1);
    sub_16fe2();
    sub_15726();
    ax = memoryAGet16(ds, 0x003c);
    if (ax != memoryAGet16(ds, di + 20))
        goto loc_13670;
    al = memoryAGet(ds, di + 40);
    if ((char)al < (char)0x01)
        goto loc_13670;
    push(di);
    tx = si;
    si = di;
    di = tx;
    sub_16e83();
    di = pop();
    goto loc_1367d;
loc_13670:
    memoryASet(ds, 0x0050, 0xff);
    sub_1706f();
    memoryASet(ds, 0x0050, 0x00);
loc_1367d:
    di = pop();
    cx = pop();
    di += 0x002d;
    if (--cx)
        goto loc_13645;
    al = memoryAGet(ds, 0x0045);
    si = 0x2095;
    goto loc_14b68;
loc_1368d:
    return;
    //   gap of 5338 bytes
loc_14b68:
    memoryASet(ds, si, 0x20);
    memoryASet(ds, si + 1, 0x20);
    memoryASet(ds, si + 2, 0x20);
    ah = 0;
    bl = 0;
loc_14b77:
    ah++;
    flags.carry = al < 0x64;
    al -= 0x64;
    if (!flags.carry)
        goto loc_14b77;
    al += 0x64;
    ah--;
    if (ah != 0)
        goto loc_14b89;
    ah = 0x20;
    goto loc_14b91;
loc_14b89:
    ah += 0x30;
    bl++;
    memoryASet(ds, si, ah);
    si++;
loc_14b91:
    memoryASet(ds, si, 0x20);
    memoryASet(ds, si + 1, 0x20);
    ah = 0;
loc_14b9a:
    ah++;
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_14b9a;
    al += 0x0a;
    ah--;
    if (ah != 0)
        goto loc_14bb0;
    if (bl != 0)
        goto loc_14bb0;
    ah = 0x20;
    goto loc_14bb8;
loc_14bb0:
    ah += 0x30;
    bl++;
    memoryASet(ds, si, ah);
    si++;
loc_14bb8:
    al += 0x30;
    memoryASet(ds, si, al);
    si++;
}
void sub_1368e()
{
    di = 0x4a40;
    cx = 0x8880;
    sub_14df8();
    ax = 0x0680;
    bx = 0x00a4;
    dx = 0x4a40;
    push(cs);
    cs = 0x1000;
    sub_18808();
    assert(cs == 0x1000);
    ax = memoryAGet16(ds, 0x1ff4);
    ax++;
    memoryASet16(ds, 0x1fe4, ax);
}
void sub_136ad()
{
    di = 0xcc40;
    cx = 0x0340;
    goto loc_14df8;
    //   gap of 5954 bytes
loc_14df8:
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_136b6()
{
    sub_1368e();
    di = 0x0fcb;
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    memoryASet(ds, 0x0064, al);
    memoryASet(ds, 0x0067, al);
    ah = memoryAGet(ds, di + 2);
    al = memoryAGet(ds, di + 3);
    memoryASet(ds, 0x0047, al);
    ah = memoryAGet(ds, di + 4);
    al = memoryAGet(ds, di + 5);
    memoryASet(ds, 0x0044, al);
    ah = memoryAGet(ds, di + 6);
    al = memoryAGet(ds, di + 7);
    ax += 0x0030;
    memoryASet(ds, 0x20a7, al);
    ah = memoryAGet(ds, di + 8);
    al = memoryAGet(ds, di + 9);
    memoryASet(ds, 0x006a, al);
    ah = memoryAGet(ds, di + 10);
    al = memoryAGet(ds, di + 11);
    memoryASet(ds, 0x006d, al);
    ah = memoryAGet(ds, di + 12);
    al = memoryAGet(ds, di + 13);
    memoryASet(ds, 0x0070, al);
    ah = memoryAGet(ds, di + 14);
    al = memoryAGet(ds, di + 15);
    memoryASet(ds, 0x0073, al);
    ah = memoryAGet(ds, di + 16);
    al = memoryAGet(ds, di + 17);
    memoryASet(ds, 0x0076, al);
    ah = memoryAGet(ds, di + 18);
    al = memoryAGet(ds, di + 19);
    memoryASet(ds, 0x0079, al);
    ah = memoryAGet(ds, di + 20);
    al = memoryAGet(ds, di + 21);
    memoryASet(ds, 0x007c, al);
    ah = memoryAGet(ds, di + 22);
    al = memoryAGet(ds, di + 23);
    memoryASet(ds, 0x007f, al);
    ah = memoryAGet(ds, di + 24);
    al = memoryAGet(ds, di + 25);
    ax += 0x0010;
    memoryASet16(ds, 0x0000, ax);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x0002, ax);
    al = memoryAGet(ds, 0x0fe8);
    if (al == 0)
        goto loc_1374f;
    sub_11a7b();
    goto loc_1376a;
loc_1374f:
    si = 0x10eb;
loc_13752:
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    si += 0x0004;
    if (ax == 0xffff)
        goto loc_1376a;
    sub_17c67();
    goto loc_13752;
loc_1376a:
    sub_1378a();
    sub_13839();
    sub_137c2();
    sub_1389f();
    sub_136ad();
    cx = 0x000d;
loc_1377c:
    push(cx);
    sub_1796f();
    cx = pop();
    if (--cx)
        goto loc_1377c;
    ax = memoryAGet16(ds, 0x1ff0);
    memoryASet16(ds, 0x1fe4, ax);
}
void sub_1378a()
{
    push(ds);
    es = pop();
    bx = 0xfeb;
    si = 0x1b4b;
    di = 0x17cb;
    cx = 0x0020;
loc_1379b:
    ah = memoryAGet(ds, bx);
    al = memoryAGet(ds, bx + 1);
    if (ax == 0)
        goto loc_137b9;
    ah = memoryAGet(ds, bx + 4);
    al = memoryAGet(ds, bx + 5);
    push(si);
    push(cx);
    push(di);
    cx = 0x001c;
    mul(cx);
    si += ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    si = pop();
loc_137b9:
    bx += 0x0008;
    di += 0x001c;
    if (--cx)
        goto loc_1379b;
}
void sub_137c2()
{
    di = 0xfeb;
    cx = 0x0010;
    bp = 0;
loc_137cb:
    ah = memoryAGet(ds, di + 4);
    al = memoryAGet(ds, di + 5);
    dx = 0x001c;
    mul(dx);
    si = 0x1b4b;
    si += ax;
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    if (ax == 0)
        goto loc_1382f;
    ax >>= 1;
    ax >>= 1;
    ax += memoryAGet16(ds, si + 14);
    bh = memoryAGet(ds, di + 2);
    bl = memoryAGet(ds, di + 3);
    bx >>= 1;
    bx >>= 1;
    bx += memoryAGet16(ds, si + 16);
    bx--;
    push(ax);
    ax = 0x01a0;
    mul(bx);
    bx = ax;
    ax = pop();
    bx += ax;
    bx += 0x0012;
    ax = bp;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    al |= memoryAGet(ds, si + 20);
    dh = memoryAGet(ds, si + 18);
    dl = memoryAGet(ds, si + 19);
loc_1381b:
    push(dx);
    push(bx);
loc_1381d:
    memoryASet(ss, bx, al);
    bx++;
    dh--;
    if (dh != 0)
        goto loc_1381d;
    bx = pop();
    dx = pop();
    bx += 0x01a0;
    dl--;
    if (dl != 0)
        goto loc_1381b;
loc_1382f:
    di += 0x0008;
    bp++;
    cx--;
    if (cx == 0)
        return;
    goto loc_137cb;
}
void sub_13839()
{
    di = 0x172b;
    cx = 0x0020;
loc_13840:
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    dh = memoryAGet(ds, di + 2);
    dl = memoryAGet(ds, di + 3);
    bx = ax;
    bx |= dx;
    if (!bx)
        goto loc_13899;
    dl = dh;
    dl &= 0x0f;
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh &= 0x0f;
    push(dx);
    bl = al;
    bh = 0;
    bl &= 0x7f;
    dl = al;
    al = ah;
    ah = 0;
    flags.carry = !!(dl & 0x80);
    dl = rol(dl, 0x01);
    ax = rcl(ax, 0x0001);
    push(ax);
    ax = 0x01a0;
    mul(bx);
    bx = pop();
    bx += ax;
    bx += 0x0012;
    dx = pop();
    dx += 0x0101;
loc_13884:
    push(dx);
    push(bx);
loc_13886:
    memoryASet(ss, bx, 0x09);
    bx++;
    dh--;
    if (dh != 0)
        goto loc_13886;
    bx = pop();
    dx = pop();
    bx += 0x01a0;
    dl--;
    if (dl != 0)
        goto loc_13884;
loc_13899:
    di += 0x0004;
    if (--cx)
        goto loc_13840;
}
void sub_1389f()
{
    si = 0xfeb;
    bx = 0xe98;
    cx = 0x0020;
    bp = 0;
loc_138ac:
    ah = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 5);
    if (ax != 0x0001)
        goto loc_138d1;
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    ax += 0x0018;
    memoryASet16(ds, bx, ax);
    ah = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, si + 3);
    ax += 0x001e;
    memoryASet16(ds, bx + 2, ax);
    bx += 0x0004;
    bp++;
loc_138d1:
    si += 0x0008;
    if (--cx)
        goto loc_138ac;
    if (bp == 0)
        goto loc_13926;
    if (bp == 0x0001)
        goto loc_138ea;
    if (bp == 0x0002)
        goto loc_13902;
    if (bp == 0x0003)
        goto loc_1391a;
    return;
loc_138ea:
    ax = memoryAGet16(ds, bx + 65532);
    cx = memoryAGet16(ds, bx + 65534);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, cx);
    memoryASet16(ds, bx + 4, ax);
    memoryASet16(ds, bx + 6, cx);
    memoryASet16(ds, bx + 8, ax);
    memoryASet16(ds, bx + 10, cx);
    return;
loc_13902:
    ax = memoryAGet16(ds, bx + 65532);
    cx = memoryAGet16(ds, bx + 65534);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, cx);
    ax = memoryAGet16(ds, bx + 65528);
    cx = memoryAGet16(ds, bx + 65530);
    memoryASet16(ds, bx + 4, ax);
    memoryASet16(ds, bx + 6, cx);
    return;
loc_1391a:
    ax = memoryAGet16(ds, bx + 65528);
    cx = memoryAGet16(ds, bx + 65530);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, cx);
    return;
loc_13926:
    ax = 0x0100;
    cx = 0x0010;
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, cx);
    memoryASet16(ds, bx + 4, ax);
    memoryASet16(ds, bx + 6, cx);
    memoryASet16(ds, bx + 8, ax);
    memoryASet16(ds, bx + 10, cx);
    memoryASet16(ds, bx + 10, ax);
    memoryASet16(ds, bx + 14, cx);
}
void sub_13944()
{
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_1394e;
    goto loc_17c0a;
loc_1394e:
    return;
    //   gap of 17083 bytes
loc_17c0a:
    si = 0x17cb;
    di = 0xfeb;
    cx = 0x0020;
loc_17c15:
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    if (ax == 0)
        goto loc_17c5c;
    dl = memoryAGet(ds, di + 5);
    if (dl != 0x01)
        goto loc_17c2d;
    if (memoryAGet(ds, 0x0055) != 0xff)
        goto loc_17c5e;
loc_17c2d:
    bx = memoryAGet16(ds, si);
    if (!(bx & 0x0002))
        goto loc_17c5c;
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 3);
    al++;
    if (al != ah)
        goto loc_17c4c;
    al = 0;
    if (!(bx & 0x0001))
        goto loc_17c4c;
    bx &= 0xfffd;
loc_17c4c:
    memoryASet(ds, si + 2, al);
    ah = 0;
    bp = memoryAGet16(ds, si + 6);
    mul(bp);
    ax += memoryAGet16(ds, si + 21);
    memoryASet16(ds, si + 23, ax);
loc_17c5c:
    memoryASet16(ds, si, bx);
loc_17c5e:
    di += 0x0008;
    si += 0x001c;
    if (--cx)
        goto loc_17c15;
}
void sub_1394f()
{
    sub_1368e();
    al = memoryAGet(ds, 0x0fe8);
    if (al == 0)
        goto loc_1395f;
    sub_11a7b();
    goto loc_1397a;
loc_1395f:
    si = 0x10eb;
loc_13962:
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    si += 0x0004;
    if (ax == 0xffff)
        goto loc_1397a;
    sub_17c67();
    goto loc_13962;
loc_1397a:
    sub_1378a();
    si = 0x17cb;
    di = 0xfeb;
    cx = 0x0020;
    ax = memoryAGet16(ds, 0x1ff0);
    memoryASet16(ds, 0x1fe4, ax);
loc_1398e:
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    if (ax == 0)
        goto loc_139c5;
    push(cx);
    push(di);
    push(si);
    bh = memoryAGet(ds, di + 2);
    bl = memoryAGet(ds, di + 3);
    dh = memoryAGet(ds, di + 6);
    dl = memoryAGet(ds, di + 7);
    bp = dx;
    bp &= 0xfffe;
    dl = memoryAGet(ds, si + 4);
    dh = 0;
    cl = memoryAGet(ds, si + 5);
    di = memoryAGet16(ds, si + 8);
    si = memoryAGet16(ds, si + 23);
    di += si;
    ch = 0x04;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    si = pop();
    di = pop();
    cx = pop();
loc_139c5:
    di += 0x0008;
    si += 0x001c;
    if (--cx)
        goto loc_1398e;
}
void sub_139ce()
{
    sub_175ef();
    memoryASet(ds, 0x0048, 0x14);
    al = 0x63;
    al -= memoryAGet(ds, 0x0067);
    al >>= 1;
    al = -al;
    al += 0x35;
    al = -al;
    al += 0x39;
    memoryASet(ds, 0x0049, al);
    memoryASet(ds, 0x0066, 0x00);
    memoryASet(ds, 0x0069, 0x00);
    memoryASet(ds, 0x0072, 0x00);
    memoryASet(ds, 0x0081, 0x00);
    memoryASet(ds, 0x006c, 0x00);
    memoryASet(ds, 0x0078, 0x00);
    memoryASet(ds, 0x0075, 0x00);
    memoryASet(ds, 0x007b, 0x00);
    memoryASet(ds, 0x006f, 0x00);
    memoryASet(ds, 0x007e, 0x00);
    memoryASet(ds, 0x0084, 0x00);
    memoryASet(ds, 0x0065, 0xff);
    memoryASet(ds, 0x0068, 0xff);
    memoryASet(ds, 0x0071, 0xff);
    memoryASet(ds, 0x0080, 0xff);
    memoryASet(ds, 0x006b, 0xff);
    memoryASet(ds, 0x0077, 0xff);
    memoryASet(ds, 0x0074, 0xff);
    memoryASet(ds, 0x007a, 0xff);
    memoryASet(ds, 0x006e, 0xff);
    memoryASet(ds, 0x007d, 0xff);
    memoryASet(ds, 0x0083, 0x03);
    ah = memoryAGet(ds, 0x0064);
    al = 0;
    sub_1762a();
    ah = memoryAGet(ds, 0x0067);
    al = 0x01;
    sub_1762a();
    ah = memoryAGet(ds, 0x0070);
    al = 0x04;
    sub_1762a();
    ah = memoryAGet(ds, 0x007f);
    al = 0x09;
    sub_1762a();
    ah = memoryAGet(ds, 0x006a);
    al = 0x02;
    sub_1762a();
    ah = memoryAGet(ds, 0x0076);
    al = 0x06;
    sub_1762a();
    ah = memoryAGet(ds, 0x0073);
    al = 0x05;
    sub_1762a();
    ah = memoryAGet(ds, 0x0079);
    al = 0x07;
    sub_1762a();
    ah = memoryAGet(ds, 0x006d);
    al = 0x03;
    sub_1762a();
    ah = memoryAGet(ds, 0x007c);
    al = 0x08;
    sub_1762a();
    al = memoryAGet(ds, 0x0045);
    si = 0x2095;
    sub_14b68();
    si = 0x209d;
    memoryASet(ds, si + 65535, 0x20);
    al = memoryAGet(ds, 0x0082);
    sub_1780d();
}
void sub_13ac8()
{
    sub_1796f();
    sub_17a5a();
    al = memoryAGet(ds, 0x0046);
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    cx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    cx += ax;
    ax <<= 1;
    ax += cx;
    cl = memoryAGet(ds, 0x0047);
    if (cl == 0)
        goto loc_13aef;
    div(cl);
loc_13aef:
    si = 0x209d;
    ah = 0;
    memoryASet(ds, 0x0040, al);
    if (al != 0x64)
        goto loc_13b09;
    memoryASet(ds, si + 65535, 0x31);
    memoryASet(ds, si, 0x30);
    memoryASet(ds, si + 1, 0x30);
    goto loc_13b21;
loc_13b09:
    ah++;
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_13b09;
    al += 0x3a;
    ah--;
    if (ah != 0)
        goto loc_13b19;
    ah = 0xf0;
loc_13b19:
    ah += 0x30;
    memoryASet(ds, si, ah);
    memoryASet(ds, si + 1, al);
loc_13b21:
    ah = 0;
    si = 0x2083;
    sub_1417b();
    ah = memoryAGet(ds, 0x0082);
    if (memoryAGet(ds, 0x0083) == ah)
        goto loc_13b57;
    al = memoryAGet(ds, 0x0082);
    sub_1780d();
    al = memoryAGet(ds, 0x0083);
    sub_1789e();
    if (memoryAGet(ds, 0x0084) != 0x02)
        goto loc_13b53;
    ah = memoryAGet(ds, 0x0082);
    memoryASet(ds, 0x0083, ah);
    memoryASet(ds, 0x0084, 0xff);
loc_13b53:
    memoryASet(ds, 0x0084, memoryAGet(ds, 0x0084) + 1);
loc_13b57:
    ah = memoryAGet(ds, 0x0064);
    if (ah == 0)
        goto loc_13b65;
    if (memoryAGet(ds, 0x0065) == ah)
        goto loc_13b7e;
loc_13b65:
    if (memoryAGet(ds, 0x0066) != 0x02)
        goto loc_13b75;
    memoryASet(ds, 0x0065, ah);
    memoryASet(ds, 0x0066, 0xff);
loc_13b75:
    memoryASet(ds, 0x0066, memoryAGet(ds, 0x0066) + 1);
    al = 0x00;
    sub_1762a();
loc_13b7e:
    ah = memoryAGet(ds, 0x0067);
    if (ah == 0)
        goto loc_13b8c;
    if (memoryAGet(ds, 0x0068) == ah)
        goto loc_13ba5;
loc_13b8c:
    if (memoryAGet(ds, 0x0069) != 0x02)
        goto loc_13b9c;
    memoryASet(ds, 0x0068, ah);
    memoryASet(ds, 0x0069, 0xff);
loc_13b9c:
    memoryASet(ds, 0x0069, memoryAGet(ds, 0x0069) + 1);
    al = 0x01;
    sub_1762a();
loc_13ba5:
    ah = memoryAGet(ds, 0x0070);
    if (ah == 0)
        goto loc_13bb3;
    if (memoryAGet(ds, 0x0071) == ah)
        goto loc_13bcc;
loc_13bb3:
    if (memoryAGet(ds, 0x0072) != 0x02)
        goto loc_13bc3;
    memoryASet(ds, 0x0071, ah);
    memoryASet(ds, 0x0072, 0xff);
loc_13bc3:
    memoryASet(ds, 0x0072, memoryAGet(ds, 0x0072) + 1);
    al = 0x04;
    sub_1762a();
loc_13bcc:
    ah = memoryAGet(ds, 0x007f);
    if (ah == 0)
        goto loc_13bda;
    if (memoryAGet(ds, 0x0080) == ah)
        goto loc_13bf3;
loc_13bda:
    if (memoryAGet(ds, 0x0081) != 0x02)
        goto loc_13bea;
    memoryASet(ds, 0x0080, ah);
    memoryASet(ds, 0x0081, 0xff);
loc_13bea:
    memoryASet(ds, 0x0081, memoryAGet(ds, 0x0081) + 1);
    al = 0x09;
    sub_1762a();
loc_13bf3:
    ah = memoryAGet(ds, 0x006a);
    if (ah == 0)
        goto loc_13c01;
    if (memoryAGet(ds, 0x006b) == ah)
        goto loc_13c1a;
loc_13c01:
    if (memoryAGet(ds, 0x006c) != 0x02)
        goto loc_13c11;
    memoryASet(ds, 0x006b, ah);
    memoryASet(ds, 0x006c, 0xff);
loc_13c11:
    memoryASet(ds, 0x006c, memoryAGet(ds, 0x006c) + 1);
    al = 0x02;
    sub_1762a();
loc_13c1a:
    ah = memoryAGet(ds, 0x0076);
    if (ah == 0)
        goto loc_13c28;
    if (memoryAGet(ds, 0x0077) == ah)
        goto loc_13c41;
loc_13c28:
    if (memoryAGet(ds, 0x0078) != 0x02)
        goto loc_13c38;
    memoryASet(ds, 0x0077, ah);
    memoryASet(ds, 0x0078, 0xff);
loc_13c38:
    memoryASet(ds, 0x0078, memoryAGet(ds, 0x0078) + 1);
    al = 0x06;
    sub_1762a();
loc_13c41:
    ah = memoryAGet(ds, 0x0073);
    if (ah == 0)
        goto loc_13c4f;
    if (memoryAGet(ds, 0x0074) == ah)
        goto loc_13c68;
loc_13c4f:
    if (memoryAGet(ds, 0x0075) != 0x02)
        goto loc_13c5f;
    memoryASet(ds, 0x0074, ah);
    memoryASet(ds, 0x0075, 0xff);
loc_13c5f:
    memoryASet(ds, 0x0075, memoryAGet(ds, 0x0075) + 1);
    al = 0x05;
    sub_1762a();
loc_13c68:
    ah = memoryAGet(ds, 0x0079);
    if (ah == 0)
        goto loc_13c76;
    if (memoryAGet(ds, 0x007a) == ah)
        goto loc_13c8f;
loc_13c76:
    if (memoryAGet(ds, 0x007b) != 0x02)
        goto loc_13c86;
    memoryASet(ds, 0x007a, ah);
    memoryASet(ds, 0x007b, 0xff);
loc_13c86:
    memoryASet(ds, 0x007b, memoryAGet(ds, 0x007b) + 1);
    al = 0x07;
    sub_1762a();
loc_13c8f:
    ah = memoryAGet(ds, 0x006d);
    if (ah == 0)
        goto loc_13c9d;
    if (memoryAGet(ds, 0x006e) == ah)
        goto loc_13cb6;
loc_13c9d:
    if (memoryAGet(ds, 0x006f) != 0x02)
        goto loc_13cad;
    memoryASet(ds, 0x006e, ah);
    memoryASet(ds, 0x006f, 0xff);
loc_13cad:
    memoryASet(ds, 0x006f, memoryAGet(ds, 0x006f) + 1);
    al = 0x03;
    sub_1762a();
loc_13cb6:
    ah = memoryAGet(ds, 0x007c);
    if (ah == 0)
        goto loc_13cc4;
    if (memoryAGet(ds, 0x007d) == ah)
        return;
loc_13cc4:
    if (memoryAGet(ds, 0x007e) != 0x02)
        goto loc_13cd4;
    memoryASet(ds, 0x007d, ah);
    memoryASet(ds, 0x007e, 0xff);
loc_13cd4:
    memoryASet(ds, 0x007e, memoryAGet(ds, 0x007e) + 1);
    al = 0x08;
    sub_1762a();
}
void sub_13cde()
{
    cl = memoryAGet(ds, 0x0043);
    if (cl != 0)
        goto loc_13ce9;
    goto loc_13e62;
loc_13ce9:
    si = 0x2083;
    ah = 0x0b;
loc_13cee:
    memoryASet(ds, si, 0x20);
    si++;
    ah--;
    if (ah != 0)
        goto loc_13cee;
    memoryASet(ds, 0x0063, 0x00);
    memoryASet(ds, 0x005e, 0xff);
    memoryASet(ds, 0x0060, 0xff);
    memoryASet(ds, 0x005f, 0xff);
    ax = memoryAGet16(ds, 0x0000);
    ax -= 0x0010;
    ax += memoryAGet16(ds, 0x0010);
    bx = memoryAGet16(ds, 0x0012);
    bx += 0x0008;
    si = 0x0088;
loc_13d1e:
    if (memoryAGet(ds, si + 38) != 0xff)
        goto loc_13d27;
    goto loc_13da5;
loc_13d27:
    bp = memoryAGet16(ds, si);
    bp += memoryAGet16(ds, si + 4);
    bp -= 0x0004;
    if ((short)bp >= 0)
        goto loc_13d33;
    bp = 0;
loc_13d33:
    di = memoryAGet16(ds, si + 2);
    di += memoryAGet16(ds, si + 6);
    di--;
    if ((short)di >= 0)
        goto loc_13d3e;
    di = 0;
loc_13d3e:
    if ((short)ax >= (short)bp)
        goto loc_13d45;
    goto loc_13da5;
loc_13d45:
    if ((short)bx >= (short)di)
        goto loc_13d4c;
    goto loc_13da5;
loc_13d4c:
    bp += 0x000c;
    if ((short)bp >= (short)0x0680)
        goto loc_13d58;
    goto loc_13d5b;
loc_13d58:
    bp = 0x00d0;
loc_13d5b:
    di += 0x000c;
    if ((short)di >= (short)0x00b0)
        goto loc_13d67;
    goto loc_13d6a;
loc_13d67:
    di = 0x00b0;
loc_13d6a:
    if ((short)ax <= (short)bp)
        goto loc_13d71;
    goto loc_13da5;
loc_13d71:
    if ((short)bx <= (short)di)
        goto loc_13d78;
    goto loc_13da5;
loc_13d78:
    push(ax);
    if (memoryAGet(ds, si + 36) & 0x80)
        goto loc_13d86;
    if (!(memoryAGet16(ds, si + 8) & 0x8b90))
        goto loc_13d94;
loc_13d86:
    al = memoryAGet(ds, 0x0043);
    al -= cl;
    memoryASet(ds, 0x0060, al);
    memoryASet16(ds, 0x005c, si);
    goto loc_13da0;
loc_13d94:
    al = memoryAGet(ds, 0x0043);
    al -= cl;
    memoryASet(ds, 0x005f, al);
    memoryASet16(ds, 0x005a, si);
loc_13da0:
    ax = pop();
    memoryASet(ds, 0x0063, memoryAGet(ds, 0x0063) + 1);
loc_13da5:
    si += 0x002d;
    cl--;
    if (cl == 0)
        goto loc_13daf;
    goto loc_13d1e;
loc_13daf:
    memoryASet(ds, 0x001a, 0x00);
    ax = memoryAGet16(ds, 0x0014);
    if (!(ax & 0x0002))
        goto loc_13dcc;
loc_13dbc:
    al = memoryAGet(ds, 0x005f);
    si = memoryAGet16(ds, 0x005a);
    memoryASet(ds, 0x005e, al);
    memoryASet16(ds, 0x0058, si);
    goto loc_13dde;
loc_13dcc:
    al = memoryAGet(ds, 0x0060);
    if (al == 0xff)
        goto loc_13dbc;
    si = memoryAGet16(ds, 0x005c);
    memoryASet(ds, 0x005e, al);
    memoryASet16(ds, 0x0058, si);
loc_13dde:
    if (memoryAGet(ds, 0x005e) != 0xff)
        goto loc_13de8;
    goto loc_13e62;
loc_13de8:
    memoryASet(ds, 0x001a, 0xff);
    si = 0x208b;
    al = memoryAGet(ds, 0x0063);
    sub_14b68();
    si = memoryAGet16(ds, 0x0058);
    bx = 0x48db;
    al = memoryAGet(ds, si + 36);
    if (al & 0x80)
        goto loc_13e53;
    bx = 0x48bf;
    if (al & 0x01)
        goto loc_13e63;
    bx = 0x48c6;
    if (memoryAGet(ds, si + 37) != 0x00)
        goto loc_13e53;
    bx = 0x48d4;
    if (memoryAGet16(ds, si + 8) & 0x0100)
        goto loc_13e53;
    bx = 0x48db;
    if (memoryAGet16(ds, si + 8) & 0x0080)
        goto loc_13e53;
    bx = 0x48e2;
    if (memoryAGet16(ds, si + 8) & 0x0200)
        goto loc_13e53;
    bx = 0x48e9;
    if (memoryAGet16(ds, si + 8) & 0x0800)
        goto loc_13e53;
    bx = 0x48f0;
    if (memoryAGet16(ds, si + 8) & 0x0010)
        goto loc_13e53;
    bx = 0x48fe;
    if (memoryAGet16(ds, si + 8) & 0x0004)
        goto loc_13e53;
    bx = 0x48f7;
loc_13e53:
    si = 0x2083;
    ah = 0x07;
loc_13e58:
    al = memoryAGet(ds, bx);
    memoryASet(ds, si, al);
    si++;
    bx++;
    ah--;
    if (ah != 0)
        goto loc_13e58;
loc_13e62:
    return;
loc_13e63:
    if (memoryAGet(ds, si + 37) == 0x00)
        goto loc_13e53;
    bx = 0x490c;
    goto loc_13e53;
}
void sub_13e6f()
{
    al = memoryAGet(ds, 0x1fd0);
    if (al != 0x3b)
        goto loc_13e79;
    goto loc_14068;
loc_13e79:
    if (al != 0x3c)
        goto loc_13e80;
    goto loc_1403d;
loc_13e80:
    if (al != 0x4e)
        goto loc_13e87;
    goto loc_14018;
loc_13e87:
    if (al != 0x57)
        goto loc_13e8e;
    goto loc_14018;
loc_13e8e:
    if (al != 0x58)
        goto loc_13e95;
    goto loc_13fef;
loc_13e95:
    if (al != 0x53)
        goto loc_13e9c;
    goto loc_13fef;
loc_13e9c:
    ah = al;
    al = 0x02;
    if (ah != 0x3d)
        goto loc_13ea8;
    goto loc_13f5c;
loc_13ea8:
    al++;
    if (ah != 0x3e)
        goto loc_13eb2;
    goto loc_13f5c;
loc_13eb2:
    al++;
    if (ah != 0x3f)
        goto loc_13ebc;
    goto loc_13f5c;
loc_13ebc:
    al++;
    if (ah != 0x40)
        goto loc_13ec6;
    goto loc_13f5c;
loc_13ec6:
    al++;
    if (ah != 0x41)
        goto loc_13ed0;
    goto loc_13f5c;
loc_13ed0:
    al++;
    if (ah != 0x42)
        goto loc_13eda;
    goto loc_13f5c;
loc_13eda:
    al++;
    if (ah != 0x43)
        goto loc_13ee4;
    goto loc_13f5c;
loc_13ee4:
    al++;
    if (ah != 0x44)
        goto loc_13eee;
    goto loc_13f5c;
loc_13eee:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0001)
        goto loc_13ef9;
    goto loc_13fe3;
loc_13ef9:
    ax = memoryAGet16(ds, 0x0012);
    ax += 0x0008;
    if ((short)ax >= (short)0x00c0)
        goto loc_13f07;
    goto loc_13fe9;
loc_13f07:
    ax = memoryAGet16(ds, 0x0010);
    ax += 0xfff8;
    if ((short)ax < (short)0x00d0)
        goto loc_13f15;
    goto loc_13f92;
loc_13f15:
    if (memoryAGet(ds, 0x0084) == 0x00)
        goto loc_13f1f;
    goto loc_13fe9;
loc_13f1f:
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if ((char)al >= (char)0x02)
        goto loc_13f2e;
    goto loc_14032;
loc_13f2e:
    if (memoryAGet(ds, 0x0062) != 0xff)
        goto loc_13f38;
    goto loc_13fe9;
loc_13f38:
    memoryASet(ds, 0x0062, 0xff);
    if (al != 0x0a)
        goto loc_13f44;
    goto loc_14018;
loc_13f44:
    if (al != 0x0b)
        goto loc_13f4b;
    goto loc_13fef;
loc_13f4b:
    if (al != 0x0c)
        goto loc_13f52;
    goto loc_13fee;
loc_13f52:
    if (memoryAGet(ds, 0x002b) != 0xff)
        goto loc_13f5c;
    goto loc_13fe9;
loc_13f5c:
    if (memoryAGet(ds, 0x0084) == 0x00)
        goto loc_13f66;
    goto loc_13fe9;
loc_13f66:
    memoryASet(ds, 0x0082, al);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_13f7c;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_13f7c;
    ax = 0x0401;
    interrupt(0x61);
loc_13f7c:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_13f8f;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_13f8f;
    ax = 0x0313;
    interrupt(0x60);
loc_13f8f:
    goto loc_13fe9;
loc_13f92:
    memoryASet(ds, 0x0062, 0xff);
    if (memoryAGet(ds, 0x1fcf) != 0x00)
        goto loc_13fee;
    bx = memoryAGet16(ds, 0x0000);
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx += 0x00d0;
    if ((short)ax >= (short)bx)
        goto loc_13fbe;
    bx += 0x0018;
    if ((short)ax < (short)bx)
        goto loc_13fbe;
    if ((short)ax < (short)0x00d0)
        goto loc_13fe9;
loc_13fbe:
    ax -= 0x00da;
    if ((short)ax >= 0)
        goto loc_13fc5;
    ax = 0;
loc_13fc5:
    if ((short)ax <= (short)0x004f)
        goto loc_13fcd;
    ax = 0x004f;
loc_13fcd:
    ax <<= 1;
    ax += 0x0002;
    memoryASet16(ds, 0x0002, ax);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x0000, ax);
    sub_1410f();
    goto loc_13fe9;
loc_13fe3:
    memoryASet(ds, 0x0062, 0x00);
    return;
loc_13fe9:
    memoryASet(ds, 0x0062, 0xff);
loc_13fee:
    return;
loc_13fef:
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_13fee;
    memoryASet(ds, 0x1fd0, 0x00);
    al = memoryAGet(ds, 0x1fd3);
    ah = memoryAGet(ds, 0x1fd4);
    memoryASet(ds, 0x1fd4, al);
    al -= ah;
    if ((char)al > (char)0x05)
        goto loc_13fee;
    memoryASet(ds, 0x004b, 0xff);
    al = memoryAGet(ds, 0x0043);
    memoryASet(ds, 0x0047, al);
    goto loc_13fee;
loc_14018:
    al = memoryAGet(ds, 0x0052);
    bl = al;
    bl -= memoryAGet(ds, 0x0053);
    if (bl >= 0x02)
        goto loc_14028;
    goto loc_13fee;
loc_14028:
    memoryASet(ds, 0x002b, memoryAGet(ds, 0x002b) ^ 0xff);
    memoryASet(ds, 0x0053, al);
    goto loc_13fee;
loc_14032:
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_13fee;
    if (al == 0)
        goto loc_14068;
loc_1403d:
    if (memoryAGet(ds, 0x0069) == 0x00)
        goto loc_14046;
    goto loc_13fe9;
loc_14046:
    if (memoryAGet(ds, 0x0067) != 0x63)
        goto loc_1404f;
    goto loc_13fe9;
loc_1404f:
    memoryASet(ds, 0x0067, memoryAGet(ds, 0x0067) + 1);
loc_14053:
    al = 0x63;
    al -= memoryAGet(ds, 0x0067);
    al >>= 1;
    al = -al;
    al += 0x35;
    al = -al;
    al += 0x39;
    memoryASet(ds, 0x0049, al);
    goto loc_13fe9;
loc_14068:
    bl = memoryAGet(ds, 0x0064);
    if (memoryAGet(ds, 0x0069) == 0x00)
        goto loc_14076;
    goto loc_13fe9;
loc_14076:
    if (memoryAGet(ds, 0x0067) != bl)
        goto loc_1407f;
    goto loc_13fe9;
loc_1407f:
    memoryASet(ds, 0x0067, memoryAGet(ds, 0x0067) - 1);
    goto loc_14053;
}
void sub_14085()
{
    al = memoryAGet(ds, 0x1fd0);
    if (al != 0x2c)
        goto loc_1408f;
    goto loc_140b5;
loc_1408f:
    if (al != 0x2d)
        goto loc_14096;
    goto loc_140cd;
loc_14096:
    ax = memoryAGet16(ds, 0x0012);
    ax += 0x0008;
    if ((short)ax >= (short)0x00c0)
        goto loc_140b4;
    ax = memoryAGet16(ds, 0x0010);
    if (ax != 0x0008)
        goto loc_140ac;
    goto loc_1414f;
loc_140ac:
    if (ax != 0x0148)
        goto loc_140b4;
    goto loc_140e5;
loc_140b4:
    return;
loc_140b5:
    if (memoryAGet(ds, 0x0084) != 0x00)
        goto loc_140cc;
    memoryASet(ds, 0x0082, memoryAGet(ds, 0x0082) - 1);
    if (memoryAGet(ds, 0x0082) != 0x01)
        goto loc_140cc;
    memoryASet(ds, 0x0082, 0x09);
loc_140cc:
    return;
loc_140cd:
    if (memoryAGet(ds, 0x0084) != 0x00)
        goto loc_140cc;
    memoryASet(ds, 0x0082, memoryAGet(ds, 0x0082) + 1);
    if (memoryAGet(ds, 0x0082) != 0x0a)
        goto loc_140cc;
    memoryASet(ds, 0x0082, 0x02);
    return;
loc_140e5:
    ax = memoryAGet16(ds, 0x0000);
    if (ax == 0x0500)
        goto loc_1410f;
    ax += 0x0008;
    if (!(memoryAGet16(ds, 0x0014) & 0x0002))
        goto loc_14100;
    if (ax == 0x0500)
        goto loc_14100;
    ax += 0x0008;
loc_14100:
    memoryASet16(ds, 0x0000, ax);
    dx = ax;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    memoryASet16(ds, 0x0002, dx);
loc_1410f:
    push(ds);
    es = pop();
    ax = 0;
    di = 0x0ea8;
    cx = 0x0068;
    rep_stosw<MemAuto, DirAuto>();
    di = memoryAGet16(ds, 0x0000);
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di--;
    di--;
    di += 0x0ea8;
    cx = 0x0029;
    ax = 0x0101;
    rep_stosb<MemAuto, DirAuto>();
    flags.interrupts = false;
    ax = es;
    cx = 0x243e;
    es = cx;
    bx = memoryAGet16(ds, 0x0026);
    memoryASet(es, bx, 0xff);
    bx = memoryAGet16(ds, 0x0028);
    memoryASet(es, bx, 0xff);
    es = ax;
    flags.interrupts = true;
    return;
loc_1414f:
    ax = memoryAGet16(ds, 0x0000);
    if ((short)ax <= (short)0x0010)
        goto loc_14179;
    ax -= 0x0008;
    if (!(memoryAGet16(ds, 0x0014) & 0x0002))
        goto loc_1416a;
    if ((short)ax <= (short)0x0010)
        goto loc_14179;
    ax -= 0x0008;
loc_1416a:
    memoryASet16(ds, 0x0000, ax);
    dx = ax;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    memoryASet16(ds, 0x0002, dx);
loc_14179:
    goto loc_1410f;
}
void sub_1410f()
{
    push(ds);
    es = pop();
    ax = 0;
    di = 0x0ea8;
    cx = 0x0068;
    rep_stosw<MemAuto, DirAuto>();
    di = memoryAGet16(ds, 0x0000);
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di--;
    di--;
    di += 0x0ea8;
    cx = 0x0029;
    ax = 0x0101;
    rep_stosb<MemAuto, DirAuto>();
    flags.interrupts = false;
    ax = es;
    cx = 0x243e;
    es = cx;
    bx = memoryAGet16(ds, 0x0026);
    memoryASet(es, bx, 0xff);
    bx = memoryAGet16(ds, 0x0028);
    memoryASet(es, bx, 0xff);
    es = ax;
    flags.interrupts = true;
}
void sub_1417b()
{
loc_1417b:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        return;
    push(ax);
    push(si);
    sub_17708();
    si = pop();
    ax = pop();
    ah++;
    goto loc_1417b;
}
void sub_1418c()
{
    if (memoryAGet(ds, 0x25a6) != 0x00)
        goto loc_14196;
    goto loc_14252;
loc_14196:
    if (memoryAGet(ds, 0x25a6) != 0x01)
        goto loc_141a0;
    goto loc_142a1;
loc_141a0:
    bx = memoryAGet16(ds, 0x0016);
    cx = memoryAGet16(ds, 0x0018);
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0c03)
        goto loc_141b5;
    cx = 0x0010;
    goto loc_141d1;
loc_141b5:
    if (!(ax & 0x0401))
        goto loc_141c1;
    cx -= 0x0001;
    if ((short)cx >= 0)
        goto loc_141c1;
    cx = 0;
loc_141c1:
    if (!(ax & 0x0802))
        goto loc_141d1;
    cx += 0x0001;
    if ((short)cx <= (short)0x0020)
        goto loc_141d1;
    cx = 0x0020;
loc_141d1:
    if (ax & 0x300c)
        goto loc_141db;
    bx = 0x0010;
    goto loc_141f7;
loc_141db:
    if (!(ax & 0x1004))
        goto loc_141e7;
    bx -= 0x0001;
    if ((short)bx >= 0)
        goto loc_141e7;
    bx = 0;
loc_141e7:
    if (!(ax & 0x2008))
        goto loc_141f7;
    bx += 0x0001;
    if ((short)bx <= (short)0x0020)
        goto loc_141f7;
    bx = 0x0020;
loc_141f7:
    memoryASet16(ds, 0x0016, bx);
    memoryASet16(ds, 0x0018, cx);
    bx >>= 1;
    cx >>= 1;
    bx >>= 1;
    cx >>= 1;
    bx -= 0x0004;
    cx -= 0x0004;
    bx += memoryAGet16(ds, 0x0010);
    if ((short)bx > (short)0x0008)
        goto loc_1421b;
    bx = 0x0008;
    goto loc_14224;
loc_1421b:
    if ((short)bx <= (short)0x0148)
        goto loc_14224;
    bx = 0x0148;
loc_14224:
    memoryASet16(ds, 0x0010, bx);
    cx += memoryAGet16(ds, 0x0012);
    if ((short)cx > (short)0x0008)
        goto loc_14236;
    cx = 0x0008;
    goto loc_1423f;
loc_14236:
    if ((short)cx <= (short)0x00c8)
        goto loc_1423f;
    cx = 0x00c8;
loc_1423f:
    memoryASet16(ds, 0x0012, cx);
    bx = 0;
    if (!(ax & 0x4010))
        goto loc_1424d;
    bx |= 0x0001;
loc_1424d:
    memoryASet16(ds, 0x0014, bx);
    return;
loc_14252:
    push(es);
    push(ds);
    push(bp);
    push(si);
    push(di);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(ds);
    ax = 0x0003;
    interrupt(0x33);
    ds = pop();
    if (memoryAGet(ds, 0x200b) == 0xff)
        goto loc_1426d;
    memoryASet16(ds, 0x0014, bx);
loc_1426d:
    if ((short)cx >= (short)0x0008)
        goto loc_14275;
    cx = 0x0008;
loc_14275:
    if ((short)cx <= (short)0x0148)
        goto loc_1427e;
    cx = 0x0148;
loc_1427e:
    memoryASet16(ds, 0x0010, cx);
    if ((short)dx >= (short)0x0008)
        goto loc_1428a;
    dx = 0x0008;
loc_1428a:
    if ((short)dx <= (short)0x00c8)
        goto loc_14293;
    dx = 0x00c8;
loc_14293:
    memoryASet16(ds, 0x0012, dx);
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di = pop();
    si = pop();
    bp = pop();
    ds = pop();
    es = pop();
    return;
loc_142a1:
    ax = memoryAGet16(ds, 0x25a0);
    push(dx);
    callIndirect(cs, ax);
    dx = pop();
    if (dl != 0xff)
        goto loc_142b0;
    return;
loc_142b0:
    bx -= memoryAGet16(ds, 0x25a2);
    cx -= memoryAGet16(ds, 0x25a4);
    al = memoryAGet(ds, 0x2005);
    if ((short)bx > (short)0x0008)
        goto loc_142c5;
    if ((short)bx >= (short)0xfff8)
        goto loc_142f8;
loc_142c5:
    if (al == 0x02)
        goto loc_142d3;
    if (al == 0x03)
        goto loc_142d7;
    if (al == 0x04)
        goto loc_142d9;
    bx = sar(bx, 1);
loc_142d3:
    bx = sar(bx, 1);
    bx = sar(bx, 1);
loc_142d7:
    bx = sar(bx, 1);
loc_142d9:
    bx = sar(bx, 1);
    bx = sar(bx, 1);
    bx += memoryAGet16(ds, 0x0010);
    if ((short)bx > (short)0x0008)
        goto loc_142eb;
    bx = 0x0008;
    goto loc_142f4;
loc_142eb:
    if ((short)bx <= (short)0x0148)
        goto loc_142f4;
    bx = 0x0148;
loc_142f4:
    memoryASet16(ds, 0x0010, bx);
loc_142f8:
    if ((short)cx > (short)0x0008)
        goto loc_14302;
    if ((short)cx >= (short)0xfff8)
        return;
loc_14302:
    if (al == 0x02)
        goto loc_14310;
    if (al == 0x03)
        goto loc_14314;
    if (al == 0x04)
        goto loc_14316;
    cx = sar(cx, 1);
loc_14310:
    cx = sar(cx, 1);
    cx = sar(cx, 1);
loc_14314:
    cx = sar(cx, 1);
loc_14316:
    cx = sar(cx, 1);
    cx += memoryAGet16(ds, 0x0012);
    if ((short)cx > (short)0x0008)
        goto loc_14326;
    cx = 0x0008;
    goto loc_1432f;
loc_14326:
    if ((short)cx <= (short)0x00c8)
        goto loc_1432f;
    cx = 0x00c8;
loc_1432f:
    memoryASet16(ds, 0x0012, cx);
}
void sub_14252()
{
    push(es);
    push(ds);
    push(bp);
    push(si);
    push(di);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(ds);
    ax = 0x0003;
    interrupt(0x33);
    ds = pop();
    if (memoryAGet(ds, 0x200b) == 0xff)
        goto loc_1426d;
    memoryASet16(ds, 0x0014, bx);
loc_1426d:
    if ((short)cx >= (short)0x0008)
        goto loc_14275;
    cx = 0x0008;
loc_14275:
    if ((short)cx <= (short)0x0148)
        goto loc_1427e;
    cx = 0x0148;
loc_1427e:
    memoryASet16(ds, 0x0010, cx);
    if ((short)dx >= (short)0x0008)
        goto loc_1428a;
    dx = 0x0008;
loc_1428a:
    if ((short)dx <= (short)0x00c8)
        goto loc_14293;
    dx = 0x00c8;
loc_14293:
    memoryASet16(ds, 0x0012, dx);
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di = pop();
    si = pop();
    bp = pop();
    ds = pop();
    es = pop();
}
void sub_14334()
{
    memoryASet(ds, 0x0051, 0x03);
    if (dl == 0xff)
        goto loc_14341;
    sub_14386();
loc_14341:
    flags.interrupts = false;
    dx = 0x0201;
    in(al, dx);
    flags.interrupts = true;
    al = ~al;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x03;
    ah = 0;
    memoryASet16(ds, 0x0014, ax);
}
void sub_14359()
{
    memoryASet(ds, 0x0051, 0x0c);
    if (dl == 0xff)
        goto loc_1436a;
    sub_14386();
    bx = si;
    cx = di;
loc_1436a:
    flags.interrupts = false;
    dx = 0x0201;
    in(al, dx);
    flags.interrupts = true;
    al = ~al;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x03;
    ah = 0;
    memoryASet16(ds, 0x0014, ax);
}
void sub_14386()
{
    flags.interrupts = false;
    bx = 0;
    cx = 0;
    si = 0;
    di = 0;
    dx = 0x0201;
    out(dx, al);
    goto loc_14396;
loc_14396:
    goto loc_14399;
loc_14399:
    in(al, dx);
    al &= memoryAGet(ds, 0x0051);
    ah = 0;
    bp = ax;
    ax &= 0x0001;
    bx += ax;
    ax = bp;
    ax &= 0x0002;
    cx += ax;
    ax = bp;
    ax &= 0x0004;
    ax >>= 1;
    ax >>= 1;
    si += ax;
    ax = bp;
    ax &= 0x0008;
    ax >>= 1;
    ax >>= 1;
    di += ax;
    if (bp)
        goto loc_14399;
    flags.interrupts = true;
    cx = sar(cx, 1);
    di = sar(di, 1);
}
void sub_143ce()
{
loc_143ce:
    al = memoryAGet(ds, 0x1fd0);
    if (al == 0)
        goto loc_143d9;
    if (al == 0x77)
        goto loc_143ee;
loc_143d9:
    flags.interrupts = false;
    dx = 0x0201;
    in(al, dx);
    flags.interrupts = true;
    al = ~al;
    if (!(al & 0xf0))
        goto loc_143ce;
    cl = 0;
    if (al & 0x30)
        goto loc_143ed;
    cl++;
loc_143ed:
    return;
loc_143ee:
    cl = 0x02;
    goto loc_143ed;
}
void sub_14566()
{
    goto loc_14566;
loc_100fb:
    sub_103e7();
    memoryASet(cs, 0x83be, 0x00);
loc_10105:
    ax = memoryAGet16(ds, 0x1f78);
    tx = memoryAGet16(ds, 0x1f76);
    memoryASet16(ds, 0x1f76, ax);
    ax = tx;
    memoryASet16(ds, 0x1f78, ax);
    ax = memoryAGet16(ds, 0x0028);
    tx = memoryAGet16(ds, 0x0026);
    memoryASet16(ds, 0x0026, ax);
    ax = tx;
    memoryASet16(ds, 0x0028, ax);
    if (memoryAGet(ds, 0x200e) != 0xff)
        goto loc_10164;
loc_10120:
    memoryASet(ds, 0x1fcf, 0x00);
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_1012c:
    in(al, dx);
    if (al & 0x08)
        goto loc_1012c;
    if (memoryAGet(ds, 0x1fcf) != 0xff)
        goto loc_1013f;
loc_10138:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_10138;
    goto loc_10120;
loc_1013f:
    dl -= 0x06;
    flags.interrupts = false;
    bx = memoryAGet16(ds, 0x1f78);
    bx += memoryAGet16(ds, 0x1f7a);
    bx += 0x0002;
    ah = bh;
    al = 0x0c;
    out(dx, ax);
    ah = bl;
    al++;
    out(dx, ax);
    flags.interrupts = true;
    dl += 0x06;
loc_1015c:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_1015c;
    sub_15827();
loc_10164:
    cx = memoryAGet16(ds, 0x1ffe);
    dx = memoryAGet16(ds, 0x2000);
    memoryASet(ds, 0x1fcf, 0x00);
loc_10171:
    cx--;
    if (cx != 0)
        goto loc_10179;
    if (dx == 0)
        goto loc_10183;
    dx--;
loc_10179:
    if (memoryAGet(ds, 0x1fcf) != 0xff)
        goto loc_10171;
    goto loc_10186;
loc_10183:
    sub_11644();
loc_10186:
    al = memoryAGet(ds, 0x1fcd);
    cl = 0x04;
    if ((char)al <= (char)cl)
        goto loc_10164;
    memoryASet(ds, 0x1fcd, 0x00);
    memoryASet(ds, 0x1fd0, 0x00);
    memoryASet(ds, 0x1fd3, memoryAGet(ds, 0x1fd3) + 1);
    sub_1031e();
    sub_14085();
    memoryASet(ds, 0x0052, memoryAGet(ds, 0x0052) + 1);
    sub_180fd();
    sub_17900();
    sub_13150();
    sub_130a6();
    sub_11f19();
    sub_13944();
    sub_17bb8();
    sub_13634();
    sub_13cde();
    sub_13ac8();
    sub_13150();
    if (memoryAGet(ds, 0x004f) != 0xff)
        goto loc_101d2;
    goto loc_102c3;
loc_101d2:
    if (memoryAGet(ds, 0x004a) != 0xff)
        goto loc_101e7;
    cx = 0x0002;
loc_101dc:
    al = memoryAGet(ds, 0x1fcd);
loc_101df:
    sync();
    if (memoryAGet(ds, 0x1fcd) == al)
        goto loc_101df;
    if (--cx)
        goto loc_101dc;
loc_101e7:
    al = memoryAGet(ds, 0x0043);
    if (al != memoryAGet(ds, 0x0047))
        goto loc_101fa;
    al = memoryAGet(ds, 0x0045);
    if (al != 0)
        goto loc_101fa;
    goto loc_102b3;
loc_101fa:
    al = memoryAGet(ds, 0x20a7);
    al |= memoryAGet(ds, 0x20a9);
    al |= memoryAGet(ds, 0x20aa);
    if (al != 0x30)
        goto loc_1020c;
    goto loc_102b3;
loc_1020c:
    if (memoryAGet(ds, 0x002b) == 0xff)
        goto loc_1024a;
    memoryASet(ds, 0x0085, memoryAGet(ds, 0x0085) - 1);
    if (memoryAGet(ds, 0x0085) != 0)
        goto loc_1024a;
    al = memoryAGet(ds, 0x0086);
    memoryASet(ds, 0x0085, al);
    al = memoryAGet(ds, 0x20a7);
    bx = memoryAGet16(ds, 0x20a9);
    bh--;
    if (bh != 0x2f)
        goto loc_10243;
    bh = 0x39;
    bl--;
    if (bl != 0x2f)
        goto loc_10243;
    bl = 0x35;
    al--;
    if (al != 0x2f)
        goto loc_10243;
    al = 0x30;
    bx = 0x3030;
loc_10243:
    memoryASet(ds, 0x20a7, al);
    memoryASet16(ds, 0x20a9, bx);
loc_1024a:
    ax = memoryAGet16(ds, 0x1fc7);
    if (memoryAGet(ds, 0x1f74) != 0xff)
        goto loc_1025c;
    if (!(ax & 0x8000))
        goto loc_1025c;
    goto loc_10314;
loc_1025c:
    if (!(ax & 0x0080))
        goto loc_102a1;
    push(ax);
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_10275;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_10275;
    ax = 0x0100;
    interrupt(0x60);
loc_10275:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_10288;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_10288;
    ax = 0x0000;
    interrupt(0x60);
loc_10288:
    ax = pop();
    memoryASet(ds, 0x25a7, 0x00);
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_102a1;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_102a1;
    ax = 0x0200;
    interrupt(0x61);
loc_102a1:
    if (!(ax & 0x0100))
        goto loc_102ab;
    memoryASet(ds, 0x25a7, 0x03);
loc_102ab:
    if (ax & 0x0020)
        goto loc_102b3;
    goto loc_10105;
loc_102b3:
    memoryASet(ds, 0x004f, 0xff);
    al = memoryAGet(ds, 0x004e);
    al |= 0x02;
    memoryASet(ds, 0x004e, al);
    goto loc_10105;
loc_102c3:
    al = memoryAGet(ds, 0x004e);
    if (!(al & 0x02))
        goto loc_102cd;
    goto loc_10105;
loc_102cd:
    sub_15447();
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_102e3;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_102e3;
    ax = 0x0100;
    interrupt(0x60);
loc_102e3:
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_102f6;
    if (!(memoryAGet(ds, 0x25a7) & 0x01))
        goto loc_102f6;
    ax = 0x0000;
    interrupt(0x60);
loc_102f6:
    memoryASet(ds, 0x002a, 0x00);
    sub_116a9();
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_10311;
    if (!(memoryAGet(ds, 0x25a7) & 0x03))
        goto loc_10311;
    ax = 0x0200;
    interrupt(0x61);
loc_10311:
    goto loc_146eb;
loc_10314:
    memoryASet(ds, 0x0040, 0x64);
    sub_15447();
    goto loc_102c3;
    //   gap of 434 bytes
loc_104d0:
    sub_116a9();
    sub_11582();
    sub_10fa0();
    sub_10ff8();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_104ea;
    ax = 0x000c;
    cx = 0;
    interrupt(0x33);
loc_104ea:
    sub_11582();
    dx = 0x20ac;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    ax = 0x0040;
    es = ax;
    dx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x1fda, dx);
    dl += 0x06;
    memoryASet16(ds, 0x1fdc, dx);
    ax = 0x0002;
    memoryASet16(ss, 0x0008, ax);
    ax = 0x0000;
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0002;
    memoryASet16(ss, 0x0004, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0f07;
    memoryASet16(ss, 0x0006, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x0010, ax);
    return;
    //   gap of 16051 bytes
loc_14401:
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x6d60);
    memoryASet16(ds, 0x1f7a, 0x0000);
    sub_14c32();
    memoryASet(ds, 0x1f6f, 0xff);
    memoryASet(ds, 0x1f72, 0xff);
    memoryASet(ds, 0x1f70, 0x00);
    sub_1531e();
    sub_14def();
    sub_15017();
    sub_17cbc();
    sub_14ff8();
    sub_14eef();
    sub_14f2b();
    si = 0x4ad9;
    sub_14d4d();
    sub_14ea2();
    sub_14e37();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
loc_14453:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_14453;
loc_1445b:
    sub_11550();
    sub_17d0d();
    sub_14f96();
    sub_14ea2();
    sub_14e37();
    sub_14c20();
    ax = memoryAGet16(ds, 0x0014);
    if (!(ax & 0x0007))
        goto loc_14478;
    goto loc_1454c;
loc_14478:
    sub_14d1a();
    if (al != 0x80)
        goto loc_14482;
    goto loc_1454c;
loc_14482:
    if (al == 0x81)
        goto loc_144ad;
    if (al == 0x82)
        goto loc_144b3;
    if (al == 0x83)
        goto loc_144b0;
    if (al != 0x1b)
        goto loc_14495;
    goto loc_104d0;
loc_14495:
    if (al == 0x8a)
        goto loc_144ec;
    if (al == 0x60)
        goto loc_144ec;
    if (al != 0x8b)
        goto loc_144a4;
    goto loc_1451c;
loc_144a4:
    if (al != 0x2d)
        goto loc_144ab;
    goto loc_1451c;
loc_144ab:
    goto loc_1445b;
loc_144ad:
    goto loc_14967;
loc_144b0:
    goto loc_14a01;
loc_144b3:
    if (memoryAGet(ds, 0x1f72) == 0x02)
        goto loc_1445b;
    memoryASet(ds, 0x1f70, memoryAGet(ds, 0x1f70) ^ 0xff);
    al = memoryAGet(ds, 0x1f71);
    al++;
    ah = 0x03;
    if (memoryAGet(ds, 0x2010) == 0xff)
        goto loc_144cf;
    ah = 0x02;
loc_144cf:
    if (al != ah)
        goto loc_144d5;
    al = 0;
loc_144d5:
    memoryASet(ds, 0x1f71, al);
    bl = al;
    bh = 0;
    bx += 0x44e9;
    al = memoryAGet(cs, bx);
    memoryASet(ds, 0x25a7, al);
    goto loc_1445b;
    //   gap of 3 bytes
loc_144ec:
    if (memoryAGet(ds, 0x1f6f) != 0x04)
        goto loc_144f6;
    goto loc_1445b;
loc_144f6:
    al = memoryAGet(ds, 0x1f6e);
    if (al != 0x03)
        goto loc_14500;
    goto loc_1445b;
loc_14500:
    al++;
    memoryASet(ds, 0x1f6e, al);
    al <<= 1;
    ah = al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    memoryASet(ds, 0x1f6b, ah);
    goto loc_1445b;
loc_1451c:
    if (memoryAGet(ds, 0x1f6f) != 0x04)
        goto loc_14526;
    goto loc_1445b;
loc_14526:
    al = memoryAGet(ds, 0x1f6e);
    if (al != 0)
        goto loc_14530;
    goto loc_1445b;
loc_14530:
    al--;
    memoryASet(ds, 0x1f6e, al);
    al <<= 1;
    ah = al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    memoryASet(ds, 0x1f6b, ah);
    goto loc_1445b;
loc_1454c:
    memoryASet(ds, 0x1f6d, 0x00);
loc_14551:
    push(ds);
    es = pop();
    di = 0x0000;
    cx = 0x0fca;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    sub_1197d();
    sub_14566();
    goto loc_100fb;
loc_14566:
    al = memoryAGet(ds, 0x1f6e);
    al <<= 1;
    ah = al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al <<= 1;
    ah += al;
    al = memoryAGet(ds, 0x1f6b);
    al++;
    al -= ah;
    si = 0x4b13;
    sub_14bbe();
    al = memoryAGet(ds, 0x0fce);
    si = 0x4b50;
    sub_14b68();
    al = memoryAGet(ds, 0x0fd0);
    cl = 0x64;
    mul(cl);
    cl = memoryAGet(ds, 0x0fce);
    div(cl);
    memoryASet(ds, 0x0041, al);
    si = 0x4b57;
    sub_14b5c();
    al = memoryAGet(ds, 0x0fcc);
    si = 0x4b78;
    sub_14bbe();
    al = memoryAGet(ds, 0x0fd2);
    al += 0x30;
    memoryASet(ds, 0x4b83, al);
    ah = 0x73;
    if (al != 0x31)
        goto loc_145c2;
    ah = 0x20;
loc_145c2:
    memoryASet(ds, 0x4b8b, ah);
    si = 0x17ab;
    di = 0x4b19;
    push(ds);
    es = pop();
    cx = 0x0010;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    al = memoryAGet(ds, 0x1f6e);
    ah = 0;
    cx = 0x0006;
    mul(cx);
    bx = ax;
    si = 0x4b98;
loc_145e5:
    al = memoryAGet(ds, bx + 19457);
    memoryASet(ds, si, al);
    bx++;
    si++;
    if (--cx)
        goto loc_145e5;
    sub_14def();
loc_145f2:
    cx = 0x0010;
    dx = 0x0010;
    sub_15329();
    if (!flags.zero)
        goto loc_145f2;
    al = 0x01;
    sub_153fe();
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x0000);
    sub_14c20();
    sub_1394f();
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f7a, 0x0000);
    sub_17eb2();
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f7a, 0x0000);
    sub_14c17();
    sub_14c07();
    bx = 0x004e;
    sub_15019();
    si = 0x4b0a;
    sub_14d4d();
    si = 0x4ba0;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_1465d;
    si = 0x4bc3;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_1465d;
    si = 0x4be5;
loc_1465d:
    sub_14d4d();
loc_14660:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_14660;
loc_14668:
    sub_146b9();
    al = 0x00;
    sub_153ca();
    cx = 0x0010;
    dx = 0x0010;
    bx = 0x0302;
    sub_1534b();
    if (!flags.zero)
        goto loc_14668;
loc_14680:
    sync();
    sub_146b9();
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_146a2;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_1469b;
    if (!(ax & 0x0040))
        goto loc_14680;
    goto loc_146a2;
loc_1469b:
    sub_146a2();
    ax = pop();
    goto loc_14401;
loc_146a2:
    sub_146b9();
    al = 0x00;
    sub_153ca();
    cx = 0x0010;
    dx = 0x0010;
    sub_15329();
    if (!flags.zero)
        goto loc_146a2;
    goto loc_14def;
    //   gap of 50 bytes
loc_146eb:
    sub_14def();
    sub_14be7();
    sub_153fc();
    sub_1531e();
    sub_14def();
    sub_15028();
    sub_15017();
    sub_148bd();
    si = 0x4c19;
    al = memoryAGet(ds, 0x20a7);
    bx = memoryAGet16(ds, 0x20a9);
    bl |= al;
    if (bx == 0x3030)
        goto loc_1471a;
    si = 0x4c2e;
loc_1471a:
    sub_14d4d();
    al = memoryAGet(ds, 0x0040);
    if ((char)al >= (char)memoryAGet(ds, 0x0041))
        goto loc_14729;
    goto loc_14778;
loc_14729:
    memoryASet(ds, 0x1f6d, 0xff);
    memoryASet(ds, 0x1f6b, memoryAGet(ds, 0x1f6b) + 1);
    al = memoryAGet(ds, 0x1f6b);
    ah = 0;
    cl = 0x1e;
    div(cl);
    memoryASet(ds, 0x1f6e, al);
    if (memoryAGet(ds, 0x1f6b) < 0x78)
        goto loc_14748;
    goto loc_147e0;
loc_14748:
    sub_1488c();
    si = 0x4d5d;
    sub_14b68();
    sub_15042();
    si = 0x4d3f;
    sub_14d4d();
    bx = 0x4d75;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14776;
    bx = 0x4da0;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14776;
    bx = 0x4dc2;
loc_14776:
    goto loc_14797;
loc_14778:
    memoryASet(ds, 0x1f6d, 0x00);
    bx = 0x4cd3;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14797;
    bx = 0x4cfe;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14797;
    bx = 0x4d20;
loc_14797:
    push(bx);
    sub_148f6();
    si = pop();
    sub_14d4d();
    si = memoryAGet16(ds, 0x0021);
    sub_14d4d();
    sub_1536c();
loc_147a9:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_147a9;
loc_147b1:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0001)
        goto loc_147d7;
    if (ax & 0x0002)
        goto loc_147cb;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_147cb;
    if (!(ax & 0x0040))
        goto loc_147b1;
loc_147cb:
    sub_1531e();
    sub_14def();
    sub_14be7();
    goto loc_14401;
loc_147d7:
    sub_1531e();
    sub_14def();
    goto loc_14551;
loc_147e0:
    sub_15017();
    si = 0x51cb;
    sub_14d4d();
    si = 0x4ba0;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_14804;
    si = 0x4bc3;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_14804;
    si = 0x4be5;
loc_14804:
    sub_14d4d();
    sub_1536c();
loc_1480a:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_1481f;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_1481f;
    if (!(ax & 0x0040))
        goto loc_1480a;
loc_1481f:
    sub_1531e();
    memoryASet(ds, 0x1f6b, 0x00);
    memoryASet(ds, 0x1f6e, 0x00);
    goto loc_14401;
    //   gap of 312 bytes
loc_14967:
    sub_14def();
    sub_14bf5();
    sub_1531e();
    sub_14def();
    sub_15017();
    si = 0x4df2;
    cx = 0x000a;
loc_1497d:
    memoryASet(ds, si, 0x2e);
    si++;
    if (--cx)
        goto loc_1497d;
    si = 0x4de1;
    sub_14d4d();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
    sub_14c7e();
    sub_151a2();
    if (!flags.zero)
        goto loc_149ec;
    al = memoryAGet(ds, 0x1f6b);
    sub_1488c();
    push(ax);
    si = 0x4e10;
    sub_14b68();
    ax = pop();
    al = ah;
    di = 0x4e1f;
    si = 0x4c01;
    push(ds);
    es = pop();
    cx = 0x0006;
    mul(cl);
    si += ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = 0x4dfe;
    sub_14d4d();
    sub_14c20();
    cx = 0x0078;
loc_149cf:
    sub_11550();
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_149e9;
    ax = memoryAGet16(ds, 0x1fc7);
    if (ax & 0x0020)
        goto loc_149e9;
    if (ax & 0x0040)
        goto loc_149e9;
    if (--cx)
        goto loc_149cf;
loc_149e9:
    goto loc_14401;
loc_149ec:
    si = 0x4e27;
    sub_14d4d();
    sub_14c20();
    cx = 0x003c;
loc_149f9:
    sub_11550();
    if (--cx)
        goto loc_149f9;
    goto loc_14401;
loc_14a01:
    sub_14def();
    sub_14bf5();
    sub_1531e();
    sub_15017();
    si = 0x4e3a;
    sub_14d4d();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_14a22;
    si = 0x4e6e;
    sub_14d4d();
loc_14a22:
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
loc_14a2e:
    sub_11550();
    sub_14d1a();
    if (memoryAGet(ds, 0x1f73) == 0xff)
        goto loc_14a3f;
    if (al == 0x31)
        goto loc_14abd;
loc_14a3f:
    if (al == 0x32)
        goto loc_14a4e;
    if (al == 0x33)
        goto loc_14ab5;
    if (al != 0x1b)
        goto loc_14a2e;
    goto loc_14401;
loc_14a4e:
    si = 0x4e85;
    sub_14d4d();
    sub_14c20();
    sub_143ce();
    if (cl == 0x02)
        goto loc_14ab5;
    if (cl == 0x01)
        goto loc_14a7d;
    ax = 0x4334;
    memoryASet16(ds, 0x25a0, ax);
    al = 0x01;
    memoryASet(ds, 0x25a6, al);
    sub_14334();
    memoryASet16(ds, 0x25a2, bx);
    memoryASet16(ds, 0x25a4, cx);
    goto loc_14a95;
loc_14a7d:
    ax = 0x4359;
    memoryASet16(ds, 0x25a0, ax);
    al = 0x01;
    memoryASet(ds, 0x25a6, al);
    sub_14359();
    memoryASet16(ds, 0x25a2, bx);
    memoryASet16(ds, 0x25a4, cx);
loc_14a95:
    si = 0x4ea9;
    sub_14d4d();
    sub_14c20();
loc_14a9f:
    sub_11550();
    sub_14d1a();
    if (al < 0x31)
        goto loc_14a9f;
    if (al > 0x34)
        goto loc_14a9f;
    al -= 0x30;
    memoryASet(ds, 0x2005, al);
    goto loc_14401;
loc_14ab5:
    memoryASet(ds, 0x25a6, 0x02);
    goto loc_14401;
loc_14abd:
    memoryASet(ds, 0x25a6, 0x00);
    goto loc_14401;
    //   gap of 810 bytes
loc_14def:
    di = 0x0000;
    cx = 0x6d60;
    goto loc_14df8;
loc_14df8:
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_146a2()
{
loc_146a2:
    sub_146b9();
    al = 0x00;
    sub_153ca();
    cx = 0x0010;
    dx = 0x0010;
    sub_15329();
    if (!flags.zero)
        goto loc_146a2;
    goto loc_14def;
    //   gap of 1846 bytes
loc_14def:
    di = 0x0000;
    cx = 0x6d60;
    goto loc_14df8;
loc_14df8:
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_146b9()
{
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
loc_146c0:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_146c0;
loc_146c5:
    in(al, dx);
    if (al & 0x08)
        goto loc_146c5;
    flags.interrupts = false;
    push(dx);
    al = 0x00;
    sub_153f6();
    dx = pop();
    flags.interrupts = false;
    cx = 0x003c;
loc_146d7:
    in(al, dx);
    if (al & 0x01)
        goto loc_146d7;
loc_146dc:
    in(al, dx);
    if (!(al & 0x01))
        goto loc_146dc;
    if (--cx)
        goto loc_146d7;
    al = 0x07;
    sub_153f6();
    flags.interrupts = true;
}
void sub_1482f()
{
    if (memoryAGet(ds, 0x2010) == 0x00)
        goto loc_14865;
    al = memoryAGet(ds, 0x0fe8);
    if (al == 0)
        goto loc_14840;
    goto loc_14866;
loc_14840:
    if (memoryAGet(ds, 0x1f6d) == 0x00)
        goto loc_14855;
    al = memoryAGet(ds, 0x1f6c);
    al++;
    if (al != 0x11)
        goto loc_14852;
    al = 0;
loc_14852:
    memoryASet(ds, 0x1f6c, al);
loc_14855:
    ah = 0;
    push(ax);
    bx = 0x4877;
    bx += ax;
    al = memoryAGet(cs, bx);
    memoryASet(ds, 0x0054, al);
    ax = pop();
loc_14865:
    return;
loc_14866:
    al--;
    ah = 0;
    bx = 0x4888;
    bx += ax;
    al = memoryAGet(cs, bx);
    memoryASet(ds, 0x0054, al);
}
void sub_1488c()
{
    push(cx);
    cl = 0x1e;
    al = memoryAGet(ds, 0x1f6b);
    al++;
    ah = 0;
    div(cl);
    ch = al;
    mul(cl);
    cl = memoryAGet(ds, 0x1f6b);
    cl++;
    cl -= al;
    ax = cx;
    if (al != 0)
        goto loc_148ae;
    al = 0x1e;
    ah--;
loc_148ae:
    cx = pop();
}
void sub_148bd()
{
    al = memoryAGet(ds, 0x0040);
    si = 0x4c5d;
    sub_14b5c();
    al = memoryAGet(ds, 0x0041);
    si = 0x4c71;
    sub_14b5c();
    si = 0x4c77;
    if (memoryAGet(ds, 0x25a6) == 0x00)
        goto loc_148eb;
    si = 0x4c9d;
    if (memoryAGet(ds, 0x25a6) == 0x01)
        goto loc_148eb;
    si = 0x4cb9;
loc_148eb:
    memoryASet16(ds, 0x0021, si);
    si = 0x4c4e;
    goto loc_14d4d;
    //   gap of 1111 bytes
loc_14d4d:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        return;
    cl = al;
    cl--;
    lodsb<MemAuto, DirAuto>();
    ch = al;
    lodsb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_14d63;
    bp = 0x0002;
    goto loc_14d65;
loc_14d63:
    bp = 0;
loc_14d65:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x0d)
        goto loc_14d4d;
    push(cx);
    push(bx);
    push(si);
    sub_14d78();
    si = pop();
    bx = pop();
    cx = pop();
    cl++;
    goto loc_14d65;
}
void sub_148f6()
{
    al = memoryAGet(ds, 0x0040);
    ah = 0;
    dl = memoryAGet(ds, 0x0041);
    dh = 0;
    bx = 0x0010;
    if (ax == 0x0064)
        goto loc_1494d;
    bx = 0;
    if (ax == 0)
        goto loc_1494d;
    bx += 0x0002;
    cx = dx;
    cx >>= 1;
    if ((short)ax < (short)cx)
        goto loc_1494d;
    bx += 0x0002;
    cx = dx;
    cx -= 0x0005;
    if ((short)ax < (short)cx)
        goto loc_1494d;
    bx += 0x0002;
    cx = dx;
    cx--;
    if ((short)ax < (short)cx)
        goto loc_1494d;
    bx += 0x0002;
    if (ax == cx)
        goto loc_1494d;
    bx += 0x0002;
    if (ax == dx)
        goto loc_1494d;
    bx += 0x0002;
    cx = dx;
    cx += 0x0014;
    if ((short)ax < (short)cx)
        goto loc_1494d;
    bx += 0x0002;
loc_1494d:
    si = memoryAGet16(cs, bx + 18773);
    goto loc_14d4d;
    //   gap of 1016 bytes
loc_14d4d:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        return;
    cl = al;
    cl--;
    lodsb<MemAuto, DirAuto>();
    ch = al;
    lodsb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_14d63;
    bp = 0x0002;
    goto loc_14d65;
loc_14d63:
    bp = 0;
loc_14d65:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x0d)
        goto loc_14d4d;
    push(cx);
    push(bx);
    push(si);
    sub_14d78();
    si = pop();
    bx = pop();
    cx = pop();
    cl++;
    goto loc_14d65;
}
void sub_14ac5()
{
    if (memoryAGet(ds, 0x1fde) != 0xfd)
        return;
    sub_1531e();
loc_14acf:
    sub_14def();
    sub_15017();
    si = 0x4f00;
    sub_14d4d();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
    memoryASet(ds, 0x1fd0, 0x00);
loc_14aed:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_14afd;
    ah = memoryAGet(ds, 0x1fd0);
    if (ah == 0)
        goto loc_14aed;
loc_14afd:
    dx = 0x2534;
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_14acf;
    bx = ax;
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_14acf;
    sub_1531e();
    sub_14def();
    memoryASet(ds, 0x1fdf, 0x00);
}
void sub_14b1c()
{
    sub_14be7();
    sub_1531e();
    sub_14def();
    sub_15017();
    si = 0x4ecf;
    sub_14d4d();
    sub_14dc2();
    sub_11550();
    sub_14c32();
    sub_1536c();
    memoryASet(ds, 0x1fd0, 0x00);
loc_14b40:
    ax = memoryAGet16(ds, 0x0014);
    if (ax & 0x0007)
        goto loc_14b50;
    ah = memoryAGet(ds, 0x1fd0);
    if (ah == 0)
        goto loc_14b40;
loc_14b50:
    sub_1531e();
    sub_14def();
    memoryASet(ds, 0x1fdf, 0x00);
}
void sub_14b5c()
{
    memoryASet(ds, si + 3, 0x20);
    sub_14b68();
    memoryASet(ds, si, 0x25);
    si++;
}
void sub_14b68()
{
    memoryASet(ds, si, 0x20);
    memoryASet(ds, si + 1, 0x20);
    memoryASet(ds, si + 2, 0x20);
    ah = 0;
    bl = 0;
loc_14b77:
    ah++;
    flags.carry = al < 0x64;
    al -= 0x64;
    if (!flags.carry)
        goto loc_14b77;
    al += 0x64;
    ah--;
    if (ah != 0)
        goto loc_14b89;
    ah = 0x20;
    goto loc_14b91;
loc_14b89:
    ah += 0x30;
    bl++;
    memoryASet(ds, si, ah);
    si++;
loc_14b91:
    memoryASet(ds, si, 0x20);
    memoryASet(ds, si + 1, 0x20);
    ah = 0;
loc_14b9a:
    ah++;
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_14b9a;
    al += 0x0a;
    ah--;
    if (ah != 0)
        goto loc_14bb0;
    if (bl != 0)
        goto loc_14bb0;
    ah = 0x20;
    goto loc_14bb8;
loc_14bb0:
    ah += 0x30;
    bl++;
    memoryASet(ds, si, ah);
    si++;
loc_14bb8:
    al += 0x30;
    memoryASet(ds, si, al);
    si++;
}
void sub_14bbe()
{
    goto loc_14bbe;
loc_14b91:
    memoryASet(ds, si, 0x20);
    memoryASet(ds, si + 1, 0x20);
    ah = 0;
loc_14b9a:
    ah++;
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_14b9a;
    al += 0x0a;
    ah--;
    if (ah != 0)
        goto loc_14bb0;
    if (bl != 0)
        goto loc_14bb0;
    ah = 0x20;
    goto loc_14bb8;
loc_14bb0:
    ah += 0x30;
    bl++;
    memoryASet(ds, si, ah);
    si++;
loc_14bb8:
    al += 0x30;
    memoryASet(ds, si, al);
    si++;
    return;
loc_14bbe:
    bl = 0;
    goto loc_14b91;
}
void sub_14bc2()
{
    ah = 0;
loc_14bc4:
    ah++;
    flags.carry = al < 0x64;
    al -= 0x64;
    if (!flags.carry)
        goto loc_14bc4;
    al += 0x64;
    ah += 0x2f;
    memoryASet(ds, si, ah);
    si++;
    ah = 0;
loc_14bd4:
    ah++;
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_14bd4;
    al += 0x0a;
    ah += 0x2f;
    memoryASet(ds, si, ah);
    si++;
    al += 0x30;
    memoryASet(ds, si, al);
}
void sub_14be7()
{
    memoryASet(cs, 0x83be, 0xff);
    flags.interrupts = false;
    ax = 0x0090;
    interrupt(0x10);
    flags.interrupts = true;
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x6d60);
    memoryASet16(ds, 0x1f7a, 0x0000);
    ax = 0x0280;
    bx = 0x015e;
    dx = memoryAGet16(ds, 0x1f76);
    push(cs);
    cs = 0x1000;
    sub_18808();
    assert(cs == 0x1000);
}
void sub_14bf5()
{
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x6d60);
    memoryASet16(ds, 0x1f7a, 0x0000);
    ax = 0x0280;
    bx = 0x015e;
    dx = memoryAGet16(ds, 0x1f76);
    push(cs);
    cs = 0x1000;
    sub_18808();
    assert(cs == 0x1000);
}
void sub_14c07()
{
    ax = 0x0280;
    bx = 0x015e;
    dx = memoryAGet16(ds, 0x1f76);
    push(cs);
    cs = 0x1000;
    sub_18808();
    assert(cs == 0x1000);
}
void sub_14c17()
{
    di = 0x15e0;
    cx = 0x5780;
    goto loc_14df8;
    //   gap of 472 bytes
loc_14df8:
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_14c20()
{
    bx = memoryAGet16(ds, 0x1f76);
    sub_14c36();
    ax = memoryAGet16(ds, 0x1f76);
    tx = memoryAGet16(ds, 0x1f78);
    memoryASet16(ds, 0x1f78, ax);
    ax = tx;
    memoryASet16(ds, 0x1f76, ax);
}
void sub_14c32()
{
    bx = memoryAGet16(ds, 0x1f78);
    flags.interrupts = false;
    dx = memoryAGet16(ds, 0x1fda);
    ah = bh;
    al = 0x0c;
    out(dx, ax);
    ah = bl;
    al++;
    out(dx, ax);
    flags.interrupts = true;
}
void sub_14c36()
{
    flags.interrupts = false;
    dx = memoryAGet16(ds, 0x1fda);
    ah = bh;
    al = 0x0c;
    out(dx, ax);
    ah = bl;
    al++;
    out(dx, ax);
    flags.interrupts = true;
}
void sub_14c7e()
{
    // no return
    si = 0x4df2;
    cx = 0x000a;
    bx = 0x5a41;
    bp = 0x503b;
    di = si;
    dx = si;
    dx += cx;
    cx = 0x5f2e;
    memoryASet(ds, 0x491e, 0x14);
loc_14c9a:
    push(si);
    push(di);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
loc_14ca0:
    push(di);
    push(si);
    push(cx);
    push(dx);
    push(bp);
    sub_11550();
    bp = pop();
    dx = pop();
    cx = pop();
    si = pop();
    di = pop();
    memoryASet(ds, 0x491e, memoryAGet(ds, 0x491e) - 1);
    if (memoryAGet(ds, 0x491e) != 0)
        goto loc_14cc4;
    memoryASet(ds, 0x491e, 0x14);
    al = memoryAGet(ds, di);
    if (al == cl)
        goto loc_14cc2;
    memoryASet(ds, di, cl);
    goto loc_14cc4;
loc_14cc2:
    memoryASet(ds, di, ch);
loc_14cc4:
    push(di);
    push(si);
    push(cx);
    push(dx);
    push(bp);
    callIndirect(cs, bp);
    sub_14c20();
    sub_14d1a();
    bp = pop();
    dx = pop();
    cx = pop();
    si = pop();
    di = pop();
    if (al == 0xff)
        goto loc_14ca0;
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    di = pop();
    si = pop();
    if (al == 0x7f)
        goto loc_14d02;
    if (al == 0x0d)
        goto loc_14d10;
    if ((char)al < (char)bl)
        goto loc_14c9a;
    if ((char)al > (char)bh)
        goto loc_14c9a;
    if (di == dx)
        goto loc_14c9a;
    memoryASet(ds, di, al);
    di++;
    cl = memoryAGet(ds, di);
    if (di != dx)
        goto loc_14c9a;
    di--;
    cl = memoryAGet(ds, di);
    goto loc_14c9a;
loc_14d02:
    memoryASet(ds, di, 0x2e);
    cl = 0x2e;
    if (di == si)
        goto loc_14c9a;
    di--;
    cl = memoryAGet(ds, di);
    goto loc_14c9a;
loc_14d10:
    memoryASet16(ds, 0x1fc7, 0x0000);
    memoryASet(ds, di, cl);
    stop(/*2*/); // 1000:4d18 jmp bp - jump Indirect bp
}
void sub_14d1a()
{
    si = 0xf78;
    bx = 0;
    cx = 0x0053;
loc_14d23:
    if (memoryAGet(ds, bx + si) & 0x80)
        goto loc_14d2e;
loc_14d28:
    bx++;
    if (--cx)
        goto loc_14d23;
    al = 0xff;
    return;
loc_14d2e:
    al = memoryAGet(ds, bx + si);
    al &= 0x7f;
    al--;
    if (al == 0)
        goto loc_14d42;
    al |= 0x80;
    memoryASet(ds, bx + si, al);
    if (al == 0x93)
        goto loc_14d45;
    goto loc_14d28;
loc_14d42:
    memoryASet(ds, bx + si, 0x86);
loc_14d45:
    al = bl;
    bx = 0x202e;
    al = memoryAGet(ds, bx+al);
}
void sub_14d4d()
{
loc_14d4d:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        return;
    cl = al;
    cl--;
    lodsb<MemAuto, DirAuto>();
    ch = al;
    lodsb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_14d63;
    bp = 0x0002;
    goto loc_14d65;
loc_14d63:
    bp = 0;
loc_14d65:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x0d)
        goto loc_14d4d;
    push(cx);
    push(bx);
    push(si);
    sub_14d78();
    si = pop();
    bx = pop();
    cx = pop();
    cl++;
    goto loc_14d65;
}
void sub_14d78()
{
    if (al == 0x20)
        return;
    al -= 0x21;
    ah = 0;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    si = ax;
    ax += ax;
    si += ax;
    si += 0x5bc0;
    di = si;
    di += 0x0040;
    bx = memoryAGet16(ds, 0x1fee);
    bx += 0x1000;
    memoryASet16(ds, 0x1fe4, bx);
    bl = ch;
    bh = 0;
    al = cl;
    ah = 0;
    cl = 0x04;
    bx <<= cl;
    ax <<= cl;
    cl = 0x10;
    ch = 0x03;
    dx = 0x0010;
    push(bp);
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    bp = pop();
}
void sub_14dc2()
{
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    push(ds);
    si = memoryAGet16(ds, 0x1f76);
    di = memoryAGet16(ds, 0x1f78);
    ax = 0xa000;
    ds = ax;
    es = ax;
    cx = 0x6d60;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
}
void sub_14def()
{
    di = 0x0000;
    cx = 0x6d60;
    goto loc_14df8;
loc_14df8:
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_14df8()
{
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_14e37()
{
    al = memoryAGet(ds, 0x1f72);
    if (al != 0x02)
        goto loc_14e46;
    al = memoryAGet(ds, 0x1f70);
    memoryASet(ds, 0x1f72, al);
    goto loc_14e51;
loc_14e46:
    if (memoryAGet(ds, 0x1f70) == al)
        goto loc_14e83;
    memoryASet(ds, 0x1f72, 0x02);
loc_14e51:
    ax = memoryAGet16(ds, 0x1fee);
    memoryASet16(ds, 0x1fe4, ax);
    si = 0xee30;
    al = memoryAGet(ds, 0x25a7);
    if (!(al & 0x03))
        goto loc_14e84;
    if (!(al & 0x02))
        goto loc_14e6f;
    if (memoryAGet(ds, 0x2010) != 0xff)
        goto loc_14e6f;
    si = 0xea50;
loc_14e6f:
    ax = 0x015f;
    bx = 0x0092;
    dx = 0x0040;
    cx = 0x041f;
    bp = 0x0001;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
loc_14e83:
    return;
loc_14e84:
    bx = 0x0078;
    ax = 0x0144;
    si = 0xb120;
    bp = 0x0003;
    cx = 0x043d;
    dx = 0x0078;
    di = si;
    di += 0x0ab9;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_14ea2()
{
    al = memoryAGet(ds, 0x1f6f);
    if (al != 0x04)
        goto loc_14eb1;
    al = memoryAGet(ds, 0x1f6e);
    memoryASet(ds, 0x1f6f, al);
    goto loc_14ebc;
loc_14eb1:
    if (memoryAGet(ds, 0x1f6e) == al)
        return;
    memoryASet(ds, 0x1f6f, 0x04);
loc_14ebc:
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x1000;
    memoryASet16(ds, 0x1fe4, ax);
    bl = memoryAGet(ds, 0x1f6e);
    bh = 0;
    bx <<= 1;
    si = memoryAGet16(cs, bx + 20199);
    ax = 0x01e6;
    bx = 0x0091;
    dx = 0x0048;
    cx = 0x041b;
    bp = 0x0001;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_14eef()
{
    ax = memoryAGet16(ds, 0x1fee);
    memoryASet16(ds, 0x1fe4, ax);
    ax = 0;
    bx = 0x0014;
    bp = 0x0f42;
    cl = 0x5e;
    ch = 0x04;
    dx = 0x0278;
    si = 0x2080;
    di = 0x7786;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    ax = 0x0008;
    bx = 0x000a;
    bp = 0x0002;
    cl = 0x5e;
    ch = 0x04;
    dx = 0x0278;
    si = 0x2080;
    di = 0x7786;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_14f2b()
{
    ax = memoryAGet16(ds, 0x1fee);
    memoryASet16(ds, 0x1fe4, ax);
    bx = 0x0078;
    ax = 0x0044;
    cx = 0x0004;
    di = 0x4f8a;
    sub_14f4a();
    bx = 0x00c5;
    ax = 0x00c4;
    cx = 0x0002;
loc_14f4a:
    push(cx);
    si = memoryAGet16(cs, di);
    di += 0x0002;
    bp = 0x0f43;
    push(ax);
    push(bx);
    ax -= 0x0008;
    bx += 0x0008;
    sub_14f6e();
    bx = pop();
    ax = pop();
    bp = 0x0003;
    sub_14f6e();
    cx = pop();
    ax += 0x0080;
    if (--cx)
        goto loc_14f4a;
}
void sub_14f4a()
{
loc_14f4a:
    push(cx);
    si = memoryAGet16(cs, di);
    di += 0x0002;
    bp = 0x0f43;
    push(ax);
    push(bx);
    ax -= 0x0008;
    bx += 0x0008;
    sub_14f6e();
    bx = pop();
    ax = pop();
    bp = 0x0003;
    sub_14f6e();
    cx = pop();
    ax += 0x0080;
    if (--cx)
        goto loc_14f4a;
}
void sub_14f6e()
{
    push(ax);
    push(bx);
    push(bp);
    push(si);
    push(di);
    cx = 0x043d;
    dx = 0x0078;
    di = si;
    di += 0x0ab9;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    ax = pop();
}
void sub_14f96()
{
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x0800;
    memoryASet16(ds, 0x1fe4, ax);
    si = 0x4960;
    cx = 0x000a;
loc_14fa6:
    push(cx);
    ax = memoryAGet16(ds, si);
    if (ax == 0x8000)
        goto loc_14ff1;
    ax--;
    memoryASet16(ds, si, ax);
    if (ax != 0xffef)
        goto loc_14fbd;
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, si, ax);
    goto loc_14ff1;
loc_14fbd:
    if ((short)ax >= 0)
        goto loc_14ff1;
    ax = -ax;
    ax--;
    ax >>= 1;
    tl = al;
    al = ah;
    ah = tl;
    bp = memoryAGet16(ds, si + 8);
    ax >>= 1;
    bp += ax;
    ax >>= 1;
    bp += ax;
    ax = memoryAGet16(ds, si + 4);
    bx = memoryAGet16(ds, si + 6);
    push(si);
    si = bp;
    di = si;
    di += 0x0090;
    bp = 0x0001;
    cx = 0x040c;
    dx = 0x0020;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    si = pop();
loc_14ff1:
    cx = pop();
    si += 0x000b;
    if (--cx)
        goto loc_14fa6;
}
void sub_14ff8()
{
    si = 0x4960;
    cx = 0x000a;
    bx = 0x0028;
loc_15002:
    ax = memoryAGet16(ds, si + 2);
    if (ax == 0x8000)
        goto loc_1500c;
    ax = bx;
loc_1500c:
    memoryASet16(ds, si, ax);
    bx += 0x0028;
    si += 0x000b;
    if (--cx)
        goto loc_15002;
}
void sub_15017()
{
    bx = 0;
    goto loc_17e76;
    //   gap of 11866 bytes
loc_17e76:
    ax = memoryAGet16(ds, 0x1fee);
    memoryASet16(ds, 0x1fe4, ax);
    cx = 0x0004;
loc_17e7f:
    push(bx);
    push(cx);
    push(bx);
    ax = 0;
    bp = 0x000c;
    dx = 0x0140;
    cx = 0x0268;
    si = 0x0000;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    ax = 0x0140;
    bx = pop();
    bp = 0x000c;
    dx = 0x0140;
    cx = 0x0268;
    si = 0x0000;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    cx = pop();
    bx = pop();
    bx += 0x0068;
    if (--cx)
        goto loc_17e7f;
}
void sub_15019()
{
    goto loc_17e76;
    //   gap of 11866 bytes
loc_17e76:
    ax = memoryAGet16(ds, 0x1fee);
    memoryASet16(ds, 0x1fe4, ax);
    cx = 0x0004;
loc_17e7f:
    push(bx);
    push(cx);
    push(bx);
    ax = 0;
    bp = 0x000c;
    dx = 0x0140;
    cx = 0x0268;
    si = 0x0000;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    ax = 0x0140;
    bx = pop();
    bp = 0x000c;
    dx = 0x0140;
    cx = 0x0268;
    si = 0x0000;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    cx = pop();
    bx = pop();
    bx += 0x0068;
    if (--cx)
        goto loc_17e7f;
}
void sub_15028()
{
    flags.interrupts = false;
    push(ds);
    ax = 0;
    ds = ax;
    memoryASet16(ds, 0x0020, 0x4c47);
    memoryASet16(ds, 0x0022, cs);
    ds = pop();
    flags.interrupts = true;
}
void sub_1503b()
{
    goto loc_1503b;
loc_14d4d:
    lodsb<MemAuto, DirAuto>();
    if (al == 0)
        goto loc_14d77;
    cl = al;
    cl--;
    lodsb<MemAuto, DirAuto>();
    ch = al;
    lodsb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_14d63;
    bp = 0x0002;
    goto loc_14d65;
loc_14d63:
    bp = 0;
loc_14d65:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x0d)
        goto loc_14d4d;
    push(cx);
    push(bx);
    push(si);
    sub_14d78();
    si = pop();
    bx = pop();
    cx = pop();
    cl++;
    goto loc_14d65;
loc_14d77:
    return;
    //   gap of 707 bytes
loc_1503b:
    si = 0x4def;
    goto loc_14d4d;
}
void sub_15042()
{
    dl = memoryAGet(ds, 0x1f6b);
    dh = memoryAGet(ds, 0x491d);
    cl = memoryAGet(ds, 0x0040);
    si = 0x4913;
    di = 0x4d68;
    ax = dx;
    ch = cl;
    ax &= 0x0101;
    ch &= 0x01;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    ah <<= 1;
    ch <<= 1;
    ch <<= 1;
    al |= memoryAGet(ds, si);
    al |= ah;
    al |= ch;
    memoryASet(ds, di, al);
    al = dl;
    ch = cl;
    al &= 0x02;
    ch &= 0x02;
    al <<= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 1);
    al |= ch;
    memoryASet(ds, di + 1, al);
    ax = dx;
    ch = cl;
    ax &= 0x0204;
    ch &= 0x04;
    ah >>= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 2);
    al |= ah;
    al |= ch;
    memoryASet(ds, di + 2, al);
    al = dl;
    ch = cl;
    al &= 0x08;
    ch &= 0x08;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ch >>= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 3);
    al |= ch;
    memoryASet(ds, di + 3, al);
    ax = dx;
    ch = cl;
    ax &= 0x0410;
    ch &= 0x10;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah >>= 1;
    ah >>= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 4);
    al |= ah;
    al |= ch;
    memoryASet(ds, di + 4, al);
    ax = dx;
    ch = cl;
    al &= 0x20;
    ah &= 0x08;
    ch &= 0x20;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah >>= 1;
    ah >>= 1;
    ch >>= 1;
    ch >>= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 5);
    al |= ah;
    al |= ch;
    memoryASet(ds, di + 5, al);
    al = dl;
    ch = cl;
    al &= 0xc0;
    ch &= 0x40;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ch >>= 1;
    ch >>= 1;
    ch >>= 1;
    ch >>= 1;
    ch >>= 1;
    ch >>= 1;
    al |= memoryAGet(ds, si + 6);
    al |= ch;
    memoryASet(ds, di + 6, al);
    al = dl;
    al &= 0x0f;
    al += memoryAGet(ds, si + 7);
    memoryASet(ds, di + 7, al);
    al = dl;
    al &= 0xf0;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al += memoryAGet(ds, si + 8);
    memoryASet(ds, di + 8, al);
    al = 0;
    al += memoryAGet(ds, di);
    al += memoryAGet(ds, di + 1);
    al += memoryAGet(ds, di + 2);
    al += memoryAGet(ds, di + 3);
    al += memoryAGet(ds, di + 4);
    al += memoryAGet(ds, di + 5);
    al += memoryAGet(ds, di + 6);
    al += memoryAGet(ds, di + 7);
    al += memoryAGet(ds, di + 8);
    al &= 0x0f;
    al += memoryAGet(ds, si + 9);
    memoryASet(ds, di + 9, al);
    dh = 0x07;
    dl &= dh;
    dh -= dl;
    si = 0x4d6e;
loc_15175:
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, si + 65535);
    memoryASet(ds, si, ah);
    ah = memoryAGet(ds, si + 65534);
    memoryASet(ds, si + 65535, ah);
    ah = memoryAGet(ds, si + 65533);
    memoryASet(ds, si + 65534, ah);
    ah = memoryAGet(ds, si + 65532);
    memoryASet(ds, si + 65533, ah);
    ah = memoryAGet(ds, si + 65531);
    memoryASet(ds, si + 65532, ah);
    ah = memoryAGet(ds, si + 65530);
    memoryASet(ds, si + 65531, ah);
    memoryASet(ds, si + 65530, al);
    dh--;
    if ((char)dh >= 0)
        goto loc_15175;
}
void sub_151a2()
{
    si = 0x4df2;
    if (memoryAGet16(ds, si) != 0x4942)
        goto loc_151cd;
    if (memoryAGet16(ds, si + 2) != 0x4c4c)
        goto loc_151cd;
    if (memoryAGet16(ds, si + 4) != 0x4e41)
        goto loc_151cd;
    if (memoryAGet16(ds, si + 6) != 0x5444)
        goto loc_151cd;
    if (memoryAGet16(ds, si + 8) != 0x4445)
        goto loc_151cd;
    memoryASet(ds, 0x1f74, 0xff);
loc_151cd:
    di = 0x4913;
    cx = 0x0009;
    al = 0;
    push(si);
loc_151d7:
    al += memoryAGet(ds, si);
    si++;
    if (--cx)
        goto loc_151d7;
    si = pop();
    al &= 0x0f;
    ah = memoryAGet(ds, si + 9);
    ah -= al;
    flags.zero = memoryAGet(ds, di + 9) == ah;
    if (memoryAGet(ds, di + 9) == ah)
        goto loc_151ec;
    return;
loc_151ec:
    al = memoryAGet(ds, si + 7);
    al -= memoryAGet(ds, di + 7);
    ah = memoryAGet(ds, si + 8);
    ah -= memoryAGet(ds, di + 8);
    ax &= 0x0f0f;
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    al |= ah;
    memoryASet(ds, 0x1f6b, al);
    dh = 0x07;
    al &= dh;
    dh -= al;
loc_1520e:
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si, ah);
    ah = memoryAGet(ds, si + 2);
    memoryASet(ds, si + 1, ah);
    ah = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 2, ah);
    ah = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 3, ah);
    ah = memoryAGet(ds, si + 5);
    memoryASet(ds, si + 4, ah);
    ah = memoryAGet(ds, si + 6);
    memoryASet(ds, si + 5, ah);
    memoryASet(ds, si + 6, al);
    dh--;
    if ((char)dh >= 0)
        goto loc_1520e;
    ah = 0;
    al = memoryAGet(ds, si);
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al &= 0x01;
    ah |= al;
    al = memoryAGet(ds, si + 1);
    al >>= 1;
    al &= 0x02;
    ah |= al;
    al = memoryAGet(ds, si + 2);
    al &= 0x04;
    ah |= al;
    al = memoryAGet(ds, si + 3);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al &= 0x08;
    ah |= al;
    al = memoryAGet(ds, si + 4);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al &= 0x10;
    ah |= al;
    al = memoryAGet(ds, si + 5);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al &= 0x20;
    ah |= al;
    al = memoryAGet(ds, si + 6);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al &= 0xc0;
    ah |= al;
    flags.zero = ah == memoryAGet(ds, 0x1f6b);
    if (ah != memoryAGet(ds, 0x1f6b))
        return;
    al = memoryAGet(ds, 0x1f6b);
    ah = 0;
    cl = 0x1e;
    div(cl);
    memoryASet(ds, 0x1f6e, al);
    ah = 0;
    al = memoryAGet(ds, si);
    al >>= 1;
    al &= 0x01;
    ah |= al;
    al = memoryAGet(ds, si + 2);
    al <<= 1;
    al &= 0x02;
    ah |= al;
    al = memoryAGet(ds, si + 4);
    al <<= 1;
    al <<= 1;
    al &= 0x04;
    ah |= al;
    al = memoryAGet(ds, si + 5);
    al <<= 1;
    al <<= 1;
    al &= 0x08;
    ah |= al;
    memoryASet(ds, 0x491d, ah);
    ah = 0;
    flags.zero = true;
}
void sub_152f4()
{
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15309;
    si = 0x52d4;
    si = memoryAGet16(cs, si + 2);
    cx = 0x0010;
    goto loc_15425;
loc_15309:
    si = 0x52e4;
    si = memoryAGet16(cs, si + 2);
    cx = 0x0008;
    sub_1548c();
    cx = 0x1008;
    goto loc_1548c;
    //   gap of 264 bytes
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 69 bytes
loc_1548c:
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154a1;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154a1:
    dx = 0x03c8;
    al = ch;
    ch = 0;
    out(dx, al);
    ah = al;
    dx++;
loc_154ac:
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    ah++;
    if (--cx)
        goto loc_154ac;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154c2;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_154c2:
    flags.interrupts = true;
}
void sub_1531e()
{
    al = 0;
    cx = 0x0010;
    bx = 0x0100;
    goto loc_155b7;
    //   gap of 654 bytes
loc_155b7:
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15601;
    push(es);
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52d4;
    di += ax;
    di = memoryAGet16(cs, di);
loc_155df:
    push(cx);
    push(si);
    sub_15425();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    push(di);
    sub_1563e();
    if (flags.zero)
        goto loc_155fc;
    sub_11550();
    sub_11550();
    sub_11550();
    di = pop();
    si = pop();
    cx = pop();
    goto loc_155df;
loc_155fc:
    di = pop();
    si = pop();
    cx = pop();
    es = pop();
    return;
loc_15601:
    push(es);
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52e4;
    di += ax;
    di = memoryAGet16(cs, di);
loc_15622:
    push(cx);
    push(si);
    sub_154c4();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    push(di);
    sub_156e2();
    if (flags.zero)
        goto loc_15639;
    sub_11550();
    di = pop();
    si = pop();
    cx = pop();
    goto loc_15622;
loc_15639:
    di = pop();
    si = pop();
    cx = pop();
    es = pop();
}
void sub_15329()
{
    push(dx);
    bx = 0x0100;
    sub_15569();
    bl = 0x01;
    if (!flags.zero)
        goto loc_15336;
    bl--;
loc_15336:
    cx = pop();
    push(bx);
    cx = 0x0010;
    bx = 0x0107;
    sub_15569();
    al = 0x01;
    if (!flags.zero)
        goto loc_15347;
    al--;
loc_15347:
    bx = pop();
    al |= bl;
    flags.zero = al == 0;
}
void sub_1534b()
{
    push(bx);
    push(dx);
    bl = 0x00;
    sub_15569();
    cx = pop();
    bx = pop();
    dl = 0x01;
    if (!flags.zero)
        goto loc_1535a;
    dl--;
loc_1535a:
    push(dx);
    bh = bl;
    bl = 0x07;
    sub_15569();
    al = 0x01;
    if (!flags.zero)
        goto loc_15368;
    al--;
loc_15368:
    bx = pop();
    al |= bl;
    flags.zero = al == 0;
}
void sub_1536c()
{
    al = 0;
    cx = 0x0010;
    bx = 0x0200;
    goto loc_155b7;
    //   gap of 576 bytes
loc_155b7:
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15601;
    push(es);
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52d4;
    di += ax;
    di = memoryAGet16(cs, di);
loc_155df:
    push(cx);
    push(si);
    sub_15425();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    push(di);
    sub_1563e();
    if (flags.zero)
        goto loc_155fc;
    sub_11550();
    sub_11550();
    sub_11550();
    di = pop();
    si = pop();
    cx = pop();
    goto loc_155df;
loc_155fc:
    di = pop();
    si = pop();
    cx = pop();
    es = pop();
    return;
loc_15601:
    push(es);
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52e4;
    di += ax;
    di = memoryAGet16(cs, di);
loc_15622:
    push(cx);
    push(si);
    sub_154c4();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    push(di);
    sub_156e2();
    if (flags.zero)
        goto loc_15639;
    sub_11550();
    di = pop();
    si = pop();
    cx = pop();
    goto loc_15622;
loc_15639:
    di = pop();
    si = pop();
    cx = pop();
    es = pop();
}
void sub_15377()
{
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_153a1;
    push(ds);
    es = pop();
    si = 0x52d4;
    di = memoryAGet16(cs, si + 12);
    si = memoryAGet16(cs, si + 10);
    al = memoryAGet(ds, si);
    memoryASet(ds, di + 7, al);
    di += 0x0008;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    if (memoryAGet(ds, 0x200e) != 0xff)
        return;
    return;
loc_153a1:
    push(ds);
    es = pop();
    si = 0x52e4;
    di = memoryAGet16(cs, si + 12);
    si = memoryAGet16(cs, si + 10);
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di + 21, ax);
    al = memoryAGet(ds, si + 2);
    memoryASet(ds, di + 23, al);
    di += 0x0018;
    cx = 0x000c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    if (memoryAGet(ds, 0x200e) != 0xff)
        return;
}
void sub_153ca()
{
    cx = 0x0808;
    ah = 0;
    ax += ax;
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_153e7;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    si += 0x0008;
    goto loc_15425;
loc_153e7:
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    si += 0x0018;
    goto loc_154c4;
    //   gap of 47 bytes
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 125 bytes
loc_154c4:
    push(di);
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154da;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154da:
    dx = 0x03c8;
    al = ch;
    ah = 0;
    di = 0x5507;
    di += ax;
    ch = 0;
loc_154e9:
    al = memoryAGet(cs, di);
    di++;
    out(dx, al);
    dx++;
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    dx--;
    if (--cx)
        goto loc_154e9;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_15504;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_15504:
    flags.interrupts = true;
    di = pop();
}
void sub_153f6()
{
    cx = 0x0008;
    goto loc_15401;
    //   gap of 6 bytes
loc_15401:
    ah = 0;
    ax += ax;
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15418;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_15425;
loc_15418:
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_154c4;
    //   gap of 1 bytes
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 125 bytes
loc_154c4:
    push(di);
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154da;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154da:
    dx = 0x03c8;
    al = ch;
    ah = 0;
    di = 0x5507;
    di += ax;
    ch = 0;
loc_154e9:
    al = memoryAGet(cs, di);
    di++;
    out(dx, al);
    dx++;
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    dx--;
    if (--cx)
        goto loc_154e9;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_15504;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_15504:
    flags.interrupts = true;
    di = pop();
}
void sub_153fc()
{
    al = 0x02;
    cx = 0x0010;
    ah = 0;
    ax += ax;
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15418;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_15425;
loc_15418:
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_154c4;
    //   gap of 1 bytes
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 125 bytes
loc_154c4:
    push(di);
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154da;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154da:
    dx = 0x03c8;
    al = ch;
    ah = 0;
    di = 0x5507;
    di += ax;
    ch = 0;
loc_154e9:
    al = memoryAGet(cs, di);
    di++;
    out(dx, al);
    dx++;
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    dx--;
    if (--cx)
        goto loc_154e9;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_15504;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_15504:
    flags.interrupts = true;
    di = pop();
}
void sub_153fe()
{
    cx = 0x0010;
    ah = 0;
    ax += ax;
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15418;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_15425;
loc_15418:
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    goto loc_154c4;
    //   gap of 1 bytes
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 125 bytes
loc_154c4:
    push(di);
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154da;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154da:
    dx = 0x03c8;
    al = ch;
    ah = 0;
    di = 0x5507;
    di += ax;
    ch = 0;
loc_154e9:
    al = memoryAGet(cs, di);
    di++;
    out(dx, al);
    dx++;
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    dx--;
    if (--cx)
        goto loc_154e9;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_15504;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_15504:
    flags.interrupts = true;
    di = pop();
}
void sub_15425()
{
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
}
void sub_15447()
{
    goto loc_15447;
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
loc_15447:
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15456;
    if (memoryAGet16(ds, 0x1f7c) == 0x0002)
        goto loc_1546a;
    return;
loc_15456:
    si = 0x2608;
    cx = 0x0008;
    sub_1548c();
    si = 0x2608;
    cx = 0x1008;
    goto loc_1548c;
loc_1546a:
    si = 0x2608;
    cx = 0x0010;
    goto loc_15425;
    //   gap of 25 bytes
loc_1548c:
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154a1;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154a1:
    dx = 0x03c8;
    al = ch;
    ch = 0;
    out(dx, al);
    ah = al;
    dx++;
loc_154ac:
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    ah++;
    if (--cx)
        goto loc_154ac;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154c2;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_154c2:
    flags.interrupts = true;
}
void sub_15473()
{
    goto loc_15473;
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 44 bytes
loc_15473:
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15485;
    if (memoryAGet16(ds, 0x1f7c) != 0x0002)
        goto loc_15484;
    goto loc_15533;
loc_15484:
    return;
loc_15485:
    si = 0x2668;
    cx = 0x1008;
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154a1;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154a1:
    dx = 0x03c8;
    al = ch;
    ch = 0;
    out(dx, al);
    ah = al;
    dx++;
loc_154ac:
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    ah++;
    if (--cx)
        goto loc_154ac;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154c2;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_154c2:
    flags.interrupts = true;
    return;
    //   gap of 111 bytes
loc_15533:
    si = 0x2668;
    cx = 0x0808;
    goto loc_15425;
}
void sub_1548c()
{
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154a1;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154a1:
    dx = 0x03c8;
    al = ch;
    ch = 0;
    out(dx, al);
    ah = al;
    dx++;
loc_154ac:
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    ah++;
    if (--cx)
        goto loc_154ac;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154c2;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_154c2:
    flags.interrupts = true;
}
void sub_154c4()
{
    push(di);
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154da;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154da:
    dx = 0x03c8;
    al = ch;
    ah = 0;
    di = 0x5507;
    di += ax;
    ch = 0;
loc_154e9:
    al = memoryAGet(cs, di);
    di++;
    out(dx, al);
    dx++;
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    dx--;
    if (--cx)
        goto loc_154e9;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_15504;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_15504:
    flags.interrupts = true;
    di = pop();
}
void sub_1553d()
{
    goto loc_1553d;
loc_15425:
    flags.interrupts = false;
    bl = ch;
    ch = 0;
    dx = memoryAGet16(ds, 0x1fda);
    dl += 0x06;
    in(al, dx);
    push(dx);
    dl = 0xc0;
loc_15435:
    al = bl;
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_15435;
    dx = pop();
    in(al, dx);
    dl = 0xc0;
    al = 0x20;
    out(dx, al);
    flags.interrupts = true;
    return;
    //   gap of 69 bytes
loc_1548c:
    flags.interrupts = false;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154a1;
    dx = 0x03c4;
    al = 0x01;
    out(dx, al);
    dx++;
    in(al, dx);
    al |= 0x20;
    out(dx, al);
    push(ax);
    push(dx);
loc_154a1:
    dx = 0x03c8;
    al = ch;
    ch = 0;
    out(dx, al);
    ah = al;
    dx++;
loc_154ac:
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    lodsb<MemAuto, DirAuto>();
    out(dx, al);
    ah++;
    if (--cx)
        goto loc_154ac;
    if (memoryAGet(ds, 0x200c) == 0xff)
        goto loc_154c2;
    dx = pop();
    ax = pop();
    al &= 0xdf;
    out(dx, al);
loc_154c2:
    flags.interrupts = true;
    return;
    //   gap of 121 bytes
loc_1553d:
    ax = memoryAGet16(ds, 0x1f7c);
    if (ax == 0x0004)
        goto loc_1554b;
    if (ax == 0x0002)
        goto loc_1555f;
    return;
loc_1554b:
    si = 0x2638;
    cx = 0x0008;
    sub_1548c();
    si = 0x2650;
    cx = 0x1008;
    goto loc_1548c;
loc_1555f:
    si = 0x2638;
    cx = 0x0010;
    goto loc_15425;
}
void sub_15569()
{
    if (memoryAGet16(ds, 0x1f7c) == 0x0004)
        goto loc_15593;
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52d4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52d4;
    di += ax;
    di = memoryAGet16(cs, di);
    goto loc_1563e;
loc_15593:
    push(ds);
    es = pop();
    al = bl;
    ah = 0;
    ax += ax;
    si = 0x52e4;
    si += ax;
    si = memoryAGet16(cs, si);
    al = bh;
    ah = 0;
    ax += ax;
    di = 0x52e4;
    di += ax;
    di = memoryAGet16(cs, di);
    goto loc_156e2;
    //   gap of 136 bytes
loc_1563e:
    bp = 0;
    ch = 0;
loc_15642:
    push(cx);
    dl = memoryAGet(ds, si);
    cl = memoryAGet(ds, di);
    bl = cl;
    al = dl;
    sub_1566c();
    dh = al;
    al = dl;
    bl = cl;
    sub_15685();
    dh |= al;
    al = dl;
    bl = cl;
    sub_15696();
    dh |= al;
    memoryASet(ds, si, dh);
    cx = pop();
    si++;
    di++;
    if (--cx)
        goto loc_15642;
    flags.zero = bp == 0;
    return;
    //   gap of 118 bytes
loc_156e2:
    bl = 0;
    ch = 0;
loc_156e6:
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    if (--cx)
        goto loc_156e6;
    flags.zero = bl == 0;
}
void sub_1563e()
{
    bp = 0;
    ch = 0;
loc_15642:
    push(cx);
    dl = memoryAGet(ds, si);
    cl = memoryAGet(ds, di);
    bl = cl;
    al = dl;
    sub_1566c();
    dh = al;
    al = dl;
    bl = cl;
    sub_15685();
    dh |= al;
    al = dl;
    bl = cl;
    sub_15696();
    dh |= al;
    memoryASet(ds, si, dh);
    cx = pop();
    si++;
    di++;
    if (--cx)
        goto loc_15642;
    flags.zero = bp == 0;
}
void sub_1566c()
{
    al >>= 1;
    bl >>= 1;
    al >>= 1;
    bl >>= 1;
    al &= 0x09;
    bl &= 0x09;
    sub_1569b();
    al <<= 1;
    bl <<= 1;
    al <<= 1;
    bl <<= 1;
}
void sub_15685()
{
    al >>= 1;
    bl >>= 1;
    al &= 0x09;
    bl &= 0x09;
    sub_1569b();
    al <<= 1;
    bl <<= 1;
}
void sub_15696()
{
    al &= 0x09;
    bl &= 0x09;
    ah = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah <<= 1;
    ah &= 0x02;
    al &= 0x01;
    al |= ah;
    bh = bl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh <<= 1;
    bh &= 0x02;
    bl &= 0x01;
    bl |= bh;
    if (al == bl)
        goto loc_156d0;
    if (al > bl)
        goto loc_156cb;
    al++;
    bp = 0x00ff;
    goto loc_156d0;
loc_156cb:
    al--;
    bp = 0x00ff;
loc_156d0:
    ah = al;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    ah >>= 1;
    al &= 0x08;
    ah &= 0x01;
    al |= ah;
}
void sub_1569b()
{
    ah = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah <<= 1;
    ah &= 0x02;
    al &= 0x01;
    al |= ah;
    bh = bl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh <<= 1;
    bh &= 0x02;
    bl &= 0x01;
    bl |= bh;
    if (al == bl)
        goto loc_156d0;
    if (al > bl)
        goto loc_156cb;
    al++;
    bp = 0x00ff;
    goto loc_156d0;
loc_156cb:
    al--;
    bp = 0x00ff;
loc_156d0:
    ah = al;
    al <<= 1;
    al <<= 1;
    al <<= 1;
    ah >>= 1;
    al &= 0x08;
    ah &= 0x01;
    al |= ah;
}
void sub_156e2()
{
    bl = 0;
    ch = 0;
loc_156e6:
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    al = memoryAGet(ds, si);
    ah = memoryAGet(ds, di);
    sub_1570c();
    memoryASet(ds, si, al);
    si++;
    di++;
    if (--cx)
        goto loc_156e6;
    flags.zero = bl == 0;
}
void sub_1570c()
{
    if (al == ah)
        goto loc_1571e;
    if ((char)al > (char)ah)
        goto loc_1571f;
    al++;
loc_15714:
    bl = 0xff;
    if (al == ah)
        goto loc_1571e;
    if ((char)al > (char)ah)
        goto loc_15723;
    al++;
loc_1571e:
    return;
loc_1571f:
    al--;
    goto loc_15714;
loc_15723:
    al--;
}
void sub_15726()
{
    bx = memoryAGet16(ds, di);
    bx += memoryAGet16(ds, di + 4);
    if ((short)bx >= 0)
        goto loc_15731;
    bx += 0x0160;
loc_15731:
    ax = bx;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    si = 0xea8;
    if (memoryAGet(ds, bx + si) == 0x01)
        goto loc_15745;
    return;
loc_15745:
    ax -= memoryAGet16(ds, 0x0000);
    if ((short)ax >= 0)
        goto loc_1574d;
    ax = 0;
loc_1574d:
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += memoryAGet16(ds, 0x0026);
    bp = memoryAGet16(ds, 0x0026);
    bp += 0x0321;
    ax++;
    si = ax;
    cx = memoryAGet16(ds, di + 6);
    cx -= 0x0008;
    ax = memoryAGet16(ds, di + 2);
    if (memoryAGet(ds, di + 32) == 0x00)
        goto loc_15774;
    cx -= 0x0008;
loc_15774:
    ax += cx;
    ax -= 0x0010;
    if ((short)ax >= 0)
        goto loc_15788;
loc_1577b:
    cx += 0x0008;
    ax += 0x0008;
    if ((short)ax < 0)
        goto loc_1577b;
    ax = 0;
    cx -= 0x0008;
loc_15788:
    cx = -cx;
    dx = ax;
    ax &= 0xfff8;
    si += ax;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    ch = 0x03;
    if (!(memoryAGet16(ds, di + 8) & 0x0002))
        goto loc_157a2;
    ch = 0x05;
loc_157a2:
    al = cl;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    if (!(dl & 0x07))
        goto loc_157b1;
    cl++;
loc_157b1:
    if (!(al & 0x07))
        goto loc_157b7;
    cl++;
loc_157b7:
    al = 0x01;
loc_157b9:
    push(cx);
    push(si);
loc_157bb:
    memoryASet(ss, si, al);
    si++;
    ch--;
    if (ch != 0)
        goto loc_157bb;
    si = pop();
    cx = pop();
    si += 0x0028;
    if (si >= bp)
        return;
    cl--;
    if (cl != 0)
        goto loc_157b9;
}
void sub_157d1()
{
    push(ax);
    dx = 0xa000;
    es = dx;
    dx = 0x03ce;
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = pop();
    dx = 0x0102;
loc_157fe:
    push(di);
    push(cx);
    push(ax);
    push(dx);
    ax = dx;
    dx = 0x03c4;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    ax = pop();
loc_1580e:
    push(cx);
    push(di);
    push(bx);
    ch = 0;
    cl = bl;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    bx = pop();
    di = pop();
    cx = pop();
    di += ax;
    if (--cx)
        goto loc_1580e;
    cx = pop();
    di = pop();
    dh <<= 1;
    bh--;
    if (bh != 0)
        goto loc_157fe;
}
void sub_15827()
{
    sub_1715f();
    bx = memoryAGet16(ds, 0x0010);
    cl = memoryAGet(ds, 0x1fe0);
    ch = 0;
    bx += cx;
    bl &= 0x07;
    bh = 0;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    si = bx;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    si += bx;
    if (memoryAGet(ds, 0x001a) != 0xff)
        goto loc_15858;
    si += 0x0480;
loc_15858:
    bx = si;
    bx += 0x0060;
    di = memoryAGet16(ds, 0x000c);
    push(ds);
    ds = memoryAGet16(ds, 0x1fea);
    sub_17218();
    ds = pop();
    ax = memoryAGet16(ds, 0x000c);
    tx = memoryAGet16(ds, 0x000e);
    memoryASet16(ds, 0x000e, ax);
    ax = tx;
    memoryASet16(ds, 0x000c, ax);
    ax = memoryAGet16(ds, 0x0008);
    tx = memoryAGet16(ds, 0x000a);
    memoryASet16(ds, 0x000a, ax);
    ax = tx;
    memoryASet16(ds, 0x0008, ax);
}
void sub_1587f()
{
    flags.interrupts = false;
    push(cx);
    cx = es;
    ax = 0x243e;
    es = ax;
    dx = 0x03c4;
    ax = memoryAGet16(es, 0x0008);
    al = 0x02;
    out(dx, ax);
    dx = 0x03ce;
    ax = memoryAGet16(es, 0x0000);
    al = 0x05;
    out(dx, ax);
    ax = memoryAGet16(es, 0x0002);
    al = 0x03;
    out(dx, ax);
    ax = memoryAGet16(es, 0x0004);
    al = 0x02;
    out(dx, ax);
    ax = memoryAGet16(es, 0x0006);
    al = 0x07;
    out(dx, ax);
    ax = memoryAGet16(es, 0x000a);
    al = 0;
    out(dx, ax);
    ax = memoryAGet16(es, 0x000c);
    al = 0x01;
    out(dx, ax);
    ax = memoryAGet16(es, 0x000e);
    al = 0x08;
    out(dx, ax);
    ax = memoryAGet16(es, 0x0010);
    al = 0x04;
    out(dx, ax);
    es = cx;
    cx = pop();
    flags.interrupts = true;
}
void sub_158d2()
{
    push(ds);
    dx = 0x252b;
    es = memoryAGet16(ds, 0x1fe4);
    di = 0;
    si = 0;
    cx = es;
    sub_11b79();
    ds = pop();
    push(bx);
    sub_159bb();
    sub_15cc1();
    bx = pop();
    push(ds);
    di = 0;
    si = 0;
    es = memoryAGet16(ds, 0x1fe4);
    ds = memoryAGet16(ds, 0x1fe4);
    sub_11ba9();
    ds = pop();
    push(bx);
    sub_15ac1();
    bx = pop();
    push(ds);
    di = 0;
    si = 0;
    es = memoryAGet16(ds, 0x1fe4);
    ds = memoryAGet16(ds, 0x1fe4);
    sub_11ba9();
    ds = pop();
    push(bx);
    push(ds);
    di = 0xf91f;
    si = 0;
    cx = 0x0028;
    ax = 0x002c;
    bx = 0x0428;
    ds = memoryAGet16(ds, 0x1fe4);
    sub_157d1();
    ds = pop();
    push(ds);
    si = 0x1900;
    di = 0;
    es = memoryAGet16(ds, 0x1fec);
    ds = memoryAGet16(ds, 0x1fe4);
    cx = 0x03e0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    bx = pop();
    push(ds);
    di = 0;
    si = 0;
    es = memoryAGet16(ds, 0x1fee);
    ds = memoryAGet16(ds, 0x1fee);
    sub_11ba9();
    ds = pop();
    push(ds);
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x0f21;
    es = ax;
    ds = ax;
    di = 0;
    si = 0;
    sub_11ba9();
    ds = pop();
    push(bx);
    bx = pop();
    push(ds);
    ax = 0x1842;
    es = ax;
    ds = ax;
    di = 0;
    si = 0;
    sub_11ba9();
    ds = pop();
    if (memoryAGet(ds, 0x200e) != 0xff)
        return;
    push(ds);
    es = memoryAGet16(ds, 0x1fe4);
    ds = memoryAGet16(ds, 0x1fe4);
    di = 0;
    si = 0;
    sub_11ba9();
    ds = pop();
    push(ds);
    di = 0xf91f;
    si = 0;
    cx = 0x0028;
    ax = 0x002c;
    bx = 0x0428;
    ds = memoryAGet16(ds, 0x1fe4);
    sub_157d1();
    ds = pop();
    push(ds);
    di = 0x00a0;
    si = 0x1900;
    es = memoryAGet16(ds, 0x1fec);
    ds = memoryAGet16(ds, 0x1fe4);
    cx = 0x0720;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
}
void sub_159bb()
{
    push(ds);
    es = memoryAGet16(ds, 0x1fe6);
    ds = memoryAGet16(ds, 0x1fe4);
    si = 0;
    di = 0;
    cx = 0x0012;
loc_159cb:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_159cb;
    cx = 0x0010;
loc_159db:
    push(cx);
    dx = 0x030e;
    sub_15bb0();
    cx = pop();
    si += 0x0054;
    if (--cx)
        goto loc_159db;
    cx = 0x0010;
loc_159eb:
    push(cx);
    dx = 0x020c;
    sub_15bb0();
    cx = pop();
    si += 0x0030;
    if (--cx)
        goto loc_159eb;
    cx = 0x0010;
loc_159fb:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_159fb;
    cx = 0x0010;
loc_15a0b:
    push(cx);
    dx = 0x020c;
    sub_15bb0();
    cx = pop();
    si += 0x0030;
    if (--cx)
        goto loc_15a0b;
    cx = 0x0020;
loc_15a1b:
    push(cx);
    dx = 0x030d;
    sub_15bb0();
    cx = pop();
    si += 0x004e;
    if (--cx)
        goto loc_15a1b;
    cx = 0x0040;
loc_15a2b:
    push(cx);
    dx = 0x030a;
    sub_15bb0();
    cx = pop();
    si += 0x003c;
    if (--cx)
        goto loc_15a2b;
    cx = 0x0030;
loc_15a3b:
    push(cx);
    dx = 0x030d;
    sub_15bb0();
    cx = pop();
    si += 0x004e;
    if (--cx)
        goto loc_15a3b;
    cx = 0x0008;
loc_15a4b:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_15a4b;
    cx = 0x0010;
loc_15a5b:
    push(cx);
    dx = 0x0310;
    sub_15bb0();
    cx = pop();
    si += 0x0060;
    if (--cx)
        goto loc_15a5b;
    cx = 0x0010;
loc_15a6b:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_15a6b;
    cx = 0x0008;
loc_15a7b:
    push(cx);
    dx = 0x020d;
    sub_15bb0();
    cx = pop();
    si += 0x0034;
    if (--cx)
        goto loc_15a7b;
    cx = 0x000e;
loc_15a8b:
    push(cx);
    dx = 0x040e;
    sub_15bb0();
    cx = pop();
    si += 0x0070;
    if (--cx)
        goto loc_15a8b;
    cx = 0x0010;
loc_15a9b:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_15a9b;
    cx = 0x0020;
loc_15aab:
    push(cx);
    dx = 0x020a;
    sub_15b11();
    cx = pop();
    si += 0x0028;
    if (--cx)
        goto loc_15aab;
    sub_15c06();
    si += 0x0180;
    ds = pop();
}
void sub_15ac1()
{
    push(ds);
    es = memoryAGet16(ds, 0x1fe8);
    ds = memoryAGet16(ds, 0x1fe4);
    si = 0;
    di = 0;
    cx = 0x0008;
loc_15ad1:
    push(cx);
    cx = 0x000a;
    bl = 0x01;
    sub_15cdd();
    si += 0x0014;
    cx = pop();
    if (--cx)
        goto loc_15ad1;
    cx = 0x0004;
loc_15ae3:
    push(cx);
    cx = 0x000d;
    bl = 0x01;
    sub_15cdd();
    si += 0x001a;
    cx = pop();
    if (--cx)
        goto loc_15ae3;
    cx = 0x0016;
    bl = 0x01;
    sub_15cdd();
    si += 0x002c;
    cx = 0x000a;
loc_15b00:
    push(cx);
    cx = 0x0008;
    bl = 0x01;
    sub_15d66();
    si += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_15b00;
    ds = pop();
}
void sub_15b11()
{
    cl = 0;
loc_15b13:
    push(cx);
    push(si);
    bp = di;
    ch = dh;
loc_15b19:
    push(cx);
    ch = dl;
loc_15b1c:
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    si += 0x0002;
    bl = 0;
    if (cl == 0)
        goto loc_15b36;
    bh = cl;
loc_15b2c:
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcr(al, 0x01);
    bl = rcr(bl, 0x01);
    bh--;
    if (bh != 0)
        goto loc_15b2c;
loc_15b36:
    memoryASet(es, di, ah);
    memoryASet(es, di + 1, al);
    memoryASet(es, di + 2, bl);
    di += 0x0003;
    ch--;
    if (ch != 0)
        goto loc_15b1c;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_15b19;
    si = bp;
    ch = dl;
loc_15b51:
    push(si);
    push(cx);
    ch = dh;
    push(dx);
    dh = 0;
    bp = dx;
    dx += dx;
    bp += dx;
    dx = pop();
    ax = 0;
    bl = 0;
loc_15b63:
    ah |= memoryAGet(es, si);
    al |= memoryAGet(es, si + 1);
    bl |= memoryAGet(es, si + 2);
    si += bp;
    ch--;
    if (ch != 0)
        goto loc_15b63;
    memoryASet(es, di, ah);
    memoryASet(es, di + 1, al);
    memoryASet(es, di + 2, bl);
    di += 0x0003;
    cx = pop();
    si = pop();
    si += 0x0003;
    ch--;
    if (ch != 0)
        goto loc_15b51;
    si = pop();
    cx = pop();
    cl++;
    if (cl == 0x08)
        goto loc_15b97;
    goto loc_15b13;
loc_15b97:
    if ((short)di < (short)0x0010)
        return;
    ax = di;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    cx = es;
    ax += cx;
    es = ax;
    di &= 0x000f;
}
void sub_15bb0()
{
    push(si);
    bp = di;
    ch = dh;
loc_15bb5:
    push(cx);
    cl = dl;
    ch = 0;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_15bb5;
    si = bp;
    ch = dl;
loc_15bc5:
    push(si);
    push(cx);
    ch = dh;
    al = dl;
    ah = 0;
    ax <<= 1;
    bp = ax;
    ax = 0;
    bl = 0;
loc_15bd5:
    al |= memoryAGet(es, si);
    ah |= memoryAGet(es, si + 1);
    si += bp;
    ch--;
    if (ch != 0)
        goto loc_15bd5;
    stosw<MemAuto, DirAuto>();
    cx = pop();
    si = pop();
    si += 0x0002;
    ch--;
    if (ch != 0)
        goto loc_15bc5;
    si = pop();
    if ((short)di < (short)0x0010)
        return;
    ax = di;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    cx = es;
    ax += cx;
    es = ax;
    di &= 0x000f;
}
void sub_15c06()
{
    cl = 0;
loc_15c08:
    push(cx);
    push(si);
    push(di);
    ch = 0x03;
loc_15c0d:
    push(cx);
    ch = 0x20;
loc_15c10:
    ah = memoryAGet(ds, si);
    al = memoryAGet(ds, si + 1);
    bp = ax;
    dh = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 3);
    si += 0x0004;
    bl = 0;
    if (cl == 0)
        goto loc_15c32;
    bh = cl;
loc_15c28:
    flags.carry = bp & 1;
    bp >>= 1;
    dx = rcr(dx, 0x0001);
    bl = rcr(bl, 0x01);
    bh--;
    if (bh != 0)
        goto loc_15c28;
loc_15c32:
    ax = bp;
    memoryASet(es, di, ah);
    memoryASet(es, di + 1, al);
    memoryASet(es, di + 2, dh);
    memoryASet(es, di + 3, dl);
    memoryASet(es, di + 4, bl);
    di += 0x0005;
    ch--;
    if (ch != 0)
        goto loc_15c10;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_15c0d;
    si = pop();
    ch = 0x20;
loc_15c56:
    push(si);
    push(cx);
    bh = 0x03;
    cx = 0;
    ax = 0;
    dx = 0;
    bl = 0;
loc_15c62:
    ah |= memoryAGet(es, si);
    al |= memoryAGet(es, si + 1);
    ch |= memoryAGet(es, si + 2);
    cl |= memoryAGet(es, si + 3);
    dh |= memoryAGet(es, si + 4);
    si += 0x00a0;
    bh--;
    if (bh != 0)
        goto loc_15c62;
    memoryASet(es, di, ah);
    memoryASet(es, di + 1, al);
    memoryASet(es, di + 2, ch);
    memoryASet(es, di + 3, cl);
    memoryASet(es, di + 4, dh);
    di += 0x0005;
    cx = pop();
    si = pop();
    si += 0x0005;
    ch--;
    if (ch != 0)
        goto loc_15c56;
    si = pop();
    cx = pop();
    cl++;
    if (cl == 0x08)
        goto loc_15ca8;
    goto loc_15c08;
loc_15ca8:
    if ((short)di < (short)0x0010)
        return;
    ax = di;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    cx = es;
    ax += cx;
    es = ax;
    di &= 0x000f;
}
void sub_15cc1()
{
    si = 0x52bc;
    es = memoryAGet16(ds, 0x1fea);
    di = 0;
    cx = 0x0010;
    bl = 0x03;
    sub_15cdd();
    si = 0x531c;
    di = 0x0480;
    bl = 0x03;
    cx = 0x0010;
    dh = 0;
loc_15cdf:
    push(dx);
    push(bx);
    push(si);
loc_15ce2:
    push(bx);
    push(cx);
loc_15ce4:
    push(cx);
    lodsw<MemAuto, DirAuto>();
    dl = 0;
    if (dh == 0)
        goto loc_15cf8;
    bh = dh;
loc_15cee:
    flags.carry = al & 1;
    al >>= 1;
    ah = rcr(ah, 0x01);
    dl = rcr(dl, 0x01);
    bh--;
    if (bh != 0)
        goto loc_15cee;
loc_15cf8:
    memoryASet(es, di, al);
    di++;
    memoryASet(es, di, ah);
    di++;
    memoryASet(es, di, dl);
    di++;
    cx = pop();
    if (--cx)
        goto loc_15ce4;
    cx = pop();
    bx = pop();
    bl--;
    if (bl != 0)
        goto loc_15ce2;
    si = pop();
    bx = pop();
    dx = pop();
    dh++;
    if (dh != 0x08)
        goto loc_15cdf;
}
void sub_15cdd()
{
    dh = 0;
loc_15cdf:
    push(dx);
    push(bx);
    push(si);
loc_15ce2:
    push(bx);
    push(cx);
loc_15ce4:
    push(cx);
    lodsw<MemAuto, DirAuto>();
    dl = 0;
    if (dh == 0)
        goto loc_15cf8;
    bh = dh;
loc_15cee:
    flags.carry = al & 1;
    al >>= 1;
    ah = rcr(ah, 0x01);
    dl = rcr(dl, 0x01);
    bh--;
    if (bh != 0)
        goto loc_15cee;
loc_15cf8:
    memoryASet(es, di, al);
    di++;
    memoryASet(es, di, ah);
    di++;
    memoryASet(es, di, dl);
    di++;
    cx = pop();
    if (--cx)
        goto loc_15ce4;
    cx = pop();
    bx = pop();
    bl--;
    if (bl != 0)
        goto loc_15ce2;
    si = pop();
    bx = pop();
    dx = pop();
    dh++;
    if (dh != 0x08)
        goto loc_15cdf;
}
void sub_15d66()
{
    dh = 0;
loc_15d68:
    push(dx);
    push(bx);
    push(si);
loc_15d6b:
    push(bx);
    push(cx);
loc_15d6d:
    push(cx);
    lodsb<MemAuto, DirAuto>();
    ah = 0;
    if (dh == 0)
        goto loc_15d7f;
    bh = dh;
loc_15d77:
    flags.carry = al & 1;
    al >>= 1;
    ah = rcr(ah, 0x01);
    bh--;
    if (bh != 0)
        goto loc_15d77;
loc_15d7f:
    stosw<MemAuto, DirAuto>();
    cx = pop();
    if (--cx)
        goto loc_15d6d;
    cx = pop();
    bx = pop();
    bl--;
    if (bl != 0)
        goto loc_15d6b;
    si = pop();
    bx = pop();
    dx = pop();
    dh++;
    if (dh != 0x08)
        goto loc_15d68;
}
void sub_15d94()
{
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    memoryASet16(ds, 0x0004, 0x00d0);
}
void sub_15dc6()
{
    ax = 0xa000;
    es = ax;
    di = memoryAGet16(ds, si + 2);
    di -= 0x0010;
    if ((short)di >= 0)
        goto loc_15dd5;
    di = 0;
loc_15dd5:
    push(dx);
    ax = 0x00d0;
    mul(di);
    dx = pop();
    di = ax;
    cx = memoryAGet16(ds, si);
    bx = cx;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    di += 0x4a40;
    bx &= 0x0007;
    bx += 0x547c;
    ah = memoryAGet(ds, bx);
}
void sub_15df8()
{
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    cx = 0x0016;
    bx = 0;
    di = memoryAGet16(ds, si + 2);
    di -= 0x001e;
    if ((short)di >= 0)
        goto loc_15e34;
    cx += di;
    di = -di;
    if (di <= 0x0015)
        goto loc_15e30;
    return;
loc_15e30:
    bx = di;
    di = 0;
loc_15e34:
    push(cx);
    push(bx);
    ax = 0x00d0;
    push(dx);
    mul(di);
    di = ax;
    dx = pop();
    cx = memoryAGet16(ds, si);
    cx -= 0x0008;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    di += 0x4a40;
    ax = pop();
    bx = ax;
    ax += ax;
    ax += bx;
    bx = ax;
    cx = pop();
    push(si);
    ax = memoryAGet16(ds, si);
    ax -= 0x0008;
    ax &= 0x0007;
    ax <<= 1;
    si = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    si += 0x0c60;
    si += bx;
    push(ds);
    ds = memoryAGet16(ds, 0x1fe8);
    flags.interrupts = false;
loc_15e7f:
    lodsw<MemAuto, DirAuto>();
    bx = ax;
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = bh;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    di += 0x00cd;
    if (--cx)
        goto loc_15e7f;
    flags.interrupts = true;
    ds = pop();
    si = pop();
}
void sub_15eba()
{
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    tl = bh;
    bh = al;
    al = tl;
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    tl = bl;
    bl = al;
    al = tl;
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    tl = cl;
    cl = al;
    al = tl;
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
}
void sub_15f0f()
{
    flags.interrupts = false;
    dx = 0x03c4;
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0800;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0801;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(memoryAGet16(ds, si + 2));
    push(memoryAGet16(ds, si));
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    if ((char)memoryAGet(ds, si + 39) >= 0)
        goto loc_15f4e;
    ax -= 0x0004;
loc_15f4e:
    memoryASet16(ds, si, ax);
    push(ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    sub_15dc6();
    cx = pop();
    memoryASet16(ds, si, pop());
    memoryASet16(ds, si + 2, pop());
    bx = 0x00fc;
    dl = 0x00;
    cx &= 0x0007;
    if (cx == 0)
        goto loc_15f6d;
loc_15f67:
    flags.carry = bx & 1;
    bx >>= 1;
    dl = rcr(dl, 0x01);
    if (--cx)
        goto loc_15f67;
loc_15f6d:
    cl = dl;
    dx = 0x03ce;
    al = memoryAGet(es, di);
    ah = bh;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    ah = bl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    ah = cl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    flags.interrupts = true;
}
void sub_15fac()
{
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= dx;
    push(ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    di = memoryAGet16(ds, si + 2);
    di += memoryAGet16(ds, si + 6);
    di -= 0x0010;
    ax = 0x00d0;
    push(dx);
    mul(di);
    di = ax;
    dx = pop();
    cx = memoryAGet16(ds, si);
    cx += memoryAGet16(ds, si + 4);
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    di += 0x4a40;
    bx = pop();
    push(si);
    if (memoryAGet(ds, si + 39) != 0xff)
        goto loc_1600f;
    bx += 0x03c0;
loc_1600f:
    ax = memoryAGet16(ds, si);
    ax += memoryAGet16(ds, si + 4);
    ax &= 0x0007;
    ax <<= 1;
    si = ax;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si -= ax;
    si += bx;
    push(ds);
    ds = memoryAGet16(ds, 0x1fe8);
    cx = 0x000a;
    flags.interrupts = false;
loc_16030:
    lodsw<MemAuto, DirAuto>();
    bx = ax;
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = bh;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    di += 0x00cd;
    if (--cx)
        goto loc_16030;
    flags.interrupts = true;
    ds = pop();
    si = pop();
}
void sub_1606b()
{
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx += ax;
    ax <<= 1;
    bx += ax;
    ax <<= 1;
    ax <<= 1;
    ax -= bx;
    ax += 0x0780;
    push(ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    cx = memoryAGet16(ds, si);
    di = memoryAGet16(ds, si + 2);
    if (memoryAGet(ds, si + 40) != 0x02)
        goto loc_160ba;
    di++;
    al = memoryAGet(ds, si + 39);
    cbw();
    cx += ax;
loc_160ba:
    di += memoryAGet16(ds, si + 6);
    di -= 0x0010;
    ax = 0x00d0;
    push(dx);
    mul(di);
    di = ax;
    dx = pop();
    cx += memoryAGet16(ds, si + 4);
    bp = cx;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    di += 0x4a40;
    bx = pop();
    push(si);
    if (memoryAGet(ds, si + 39) != 0xff)
        goto loc_160e6;
    bx += 0x0270;
loc_160e6:
    bp &= 0x0007;
    si = bp;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    cx = si;
    cx -= bp;
    si <<= 1;
    si <<= 1;
    si += cx;
    si += bx;
    push(ds);
    ds = memoryAGet16(ds, 0x1fe8);
    cx = 0x000d;
    flags.interrupts = false;
loc_16106:
    lodsw<MemAuto, DirAuto>();
    bx = ax;
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = bh;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    di += 0x00cd;
    if (--cx)
        goto loc_16106;
    flags.interrupts = true;
    ds = pop();
    si = pop();
}
void sub_16141()
{
    push(bx);
    push(cx);
    ax = 0xa000;
    es = ax;
    di = bx;
    di -= 0x0010;
    push(dx);
    ax = 0x00d0;
    mul(di);
    dx = pop();
    di = ax;
    bx = cx;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    di += 0x4a40;
    bx &= 0x0007;
    bx += 0x547c;
    ah = memoryAGet(ds, bx);
    cx = pop();
    bx = pop();
}
void sub_16170()
{
    push(ds);
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ds = cx;
    cx = 0xa000;
    es = cx;
    bp = di;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    di = bp;
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ds = pop();
}
void sub_164d9()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    bp = 0x000c;
loc_16514:
    push(bp);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16538;
loc_1652c:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_1652c;
loc_16538:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    bp = pop();
    bp--;
    if (bp != 0)
        goto loc_16514;
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000c;
loc_165a5:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_165ba;
loc_165b2:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_165b2;
loc_165ba:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_165a5;
    ds = pop();
}
void sub_165d8()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    bp = 0x000d;
loc_16613:
    push(bp);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16637;
loc_1662b:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_1662b;
loc_16637:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    bp = pop();
    bp--;
    if (bp != 0)
        goto loc_16613;
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000d;
loc_166a4:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_166b9;
loc_166b1:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_166b1;
loc_166b9:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_166a4;
    ds = pop();
}
void sub_166d7()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    bp = 0x000a;
loc_16712:
    push(bp);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16736;
loc_1672a:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_1672a;
loc_16736:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    bp = pop();
    bp--;
    if (bp != 0)
        goto loc_16712;
    di = pop();
    push(di);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000a;
loc_167a4:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_167b9;
loc_167b1:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_167b1;
loc_167b9:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_167a4;
    di = pop();
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000a;
loc_167e4:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_167f9;
loc_167f1:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_167f1;
loc_167f9:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_167e4;
    ds = pop();
}
void sub_16817()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    bp = 0x000d;
loc_16852:
    push(bp);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16876;
loc_1686a:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_1686a;
loc_16876:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    bp = pop();
    bp--;
    if (bp != 0)
        goto loc_16852;
    di = pop();
    push(di);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000d;
loc_168e4:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_168f9;
loc_168f1:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_168f1;
loc_168f9:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_168e4;
    di = pop();
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000d;
loc_16924:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16939;
loc_16931:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16931;
loc_16939:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_16924;
    ds = pop();
}
void sub_16957()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    bp = 0x000e;
loc_16992:
    push(bp);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_169b6;
loc_169aa:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_169aa;
loc_169b6:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    bp = pop();
    bp--;
    if (bp != 0)
        goto loc_16992;
    di = pop();
    push(di);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000e;
loc_16a24:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16a39;
loc_16a31:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16a31;
loc_16a39:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_16a24;
    di = pop();
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    bp = 0x000e;
loc_16a64:
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16a79;
loc_16a71:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16a71;
loc_16a79:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    bp--;
    if (bp != 0)
        goto loc_16a64;
    ds = pop();
}
void sub_16a97()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    ax = 0x0010;
loc_16ad2:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16af6;
loc_16aea:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16aea;
loc_16af6:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16ad2;
    di = pop();
    push(di);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    ax = 0x0010;
loc_16b64:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16b7a;
loc_16b72:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16b72;
loc_16b7a:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16b64;
    di = pop();
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    ax = 0x0010;
loc_16ba6:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16bbc;
loc_16bb4:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16bb4;
loc_16bbc:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16ba6;
    ds = pop();
}
void sub_16bdb()
{
    push(ds);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    memoryASet16(ss, 0x0008, ax);
    dx = 0x03ce;
    ax = 0;
    out(dx, ax);
    memoryASet16(ss, 0x000a, ax);
    ax = 0x0e01;
    out(dx, ax);
    memoryASet16(ss, 0x000c, ax);
    ax = 0x0005;
    out(dx, ax);
    memoryASet16(ss, 0x0000, ax);
    ax = 0x0003;
    out(dx, ax);
    memoryASet16(ss, 0x0002, ax);
    ds = cx;
    cx = 0xa000;
    es = cx;
    bp = di;
    cx = 0x0020;
loc_16c15:
    push(cx);
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    cl = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0027;
    cx = pop();
    cx--;
    if (cx == 0)
        goto loc_16c7c;
    goto loc_16c15;
loc_16c7c:
    di = bp;
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    cx = 0x0020;
loc_16ca3:
    push(cx);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0027;
    cx = pop();
    if (--cx)
        goto loc_16ca3;
    di = bp;
    dl = 0xc4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    cx = 0x0020;
loc_16cd6:
    push(cx);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0027;
    cx = pop();
    if (--cx)
        goto loc_16cd6;
    ds = pop();
}
void sub_16cfc()
{
    push(ds);
    ds = cx;
    tx = dx;
    dx = cx;
    cx = tx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    push(di);
    ax = 0x000e;
loc_16d37:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    push(si);
    tl = al;
    al = ah;
    ah = tl;
    si = ax;
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    tl = al;
    al = ah;
    ah = tl;
    bp = ax;
    ch = cl;
    ax = 0;
    if (ch == 0)
        goto loc_16d5b;
loc_16d4f:
    flags.carry = si & 1;
    si >>= 1;
    al = rcr(al, 0x01);
    flags.carry = bp & 1;
    bp >>= 1;
    ah = rcr(ah, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16d4f;
loc_16d5b:
    push(bx);
    push(cx);
    bx = bp;
    cx = si;
    bp = ax;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = bp;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    cx = pop();
    bx = pop();
    si = pop();
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16d37;
    di = pop();
    push(di);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    ax = 0x000e;
loc_16dc9:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16ddf;
loc_16dd7:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16dd7;
loc_16ddf:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16dc9;
    di = pop();
    push(di);
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    ax = 0x000e;
loc_16e0c:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16e22;
loc_16e1a:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16e1a;
loc_16e22:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16e0c;
    di = pop();
    dx = 0x03c4;
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    ax = 0x000e;
loc_16e4e:
    push(ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    bx = ax;
    ch = cl;
    al = 0;
    if (ch == 0)
        goto loc_16e64;
loc_16e5c:
    flags.carry = bx & 1;
    bx >>= 1;
    al = rcr(al, 0x01);
    ch--;
    if (ch != 0)
        goto loc_16e5c;
loc_16e64:
    ch = al;
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0029;
    ax = pop();
    ax--;
    if (ax != 0)
        goto loc_16e4e;
    ds = pop();
}
void sub_16e83()
{
    al = memoryAGet(ds, si + 40);
    al -= 0x01;
    bl = 0xa0;
    mul(bl);
    bx = 0x2788;
    bx += ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    bp = memoryAGet16(ds, si);
    bp -= memoryAGet16(ds, 0x0000);
    bp += 0x0010;
    dx = memoryAGet16(ds, si + 2);
    dx -= 0x0010;
    cl = memoryAGet(ds, 0x004d);
    ch = 0;
loc_16ed2:
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    if (al != 0x80)
        goto loc_16ede;
    goto loc_16f74;
loc_16ede:
    push(bp);
    push(dx);
    push(bx);
    push(ax);
    cbw();
    bp += ax;
    ax = pop();
    if ((short)bp >= 0)
        goto loc_16eeb;
    goto loc_16f71;
loc_16eeb:
    tl = al;
    al = ah;
    ah = tl;
    cbw();
    dx += ax;
    if ((short)dx < 0)
        goto loc_16f71;
    if ((short)bp >= (short)0x0150)
        goto loc_16f71;
    if ((short)dx >= (short)0x00a0)
        goto loc_16f71;
    push(dx);
    push(bp);
    push(si);
    si = memoryAGet16(ds, 0x0026);
    si++;
    bp -= 0x0010;
    if ((short)bp >= 0)
        goto loc_16f0d;
    bp = 0;
loc_16f0d:
    bp >>= 1;
    bp >>= 1;
    bp >>= 1;
    si += bp;
    dx &= 0xfff8;
    si += dx;
    dx <<= 1;
    dx <<= 1;
    si += dx;
    memoryASet(ss, si, 0x01);
    si = pop();
    bp = pop();
    dx = pop();
    ax = 0x002c;
    mul(dx);
    di = ax;
    ax = bp;
    bp >>= 1;
    bp >>= 1;
    bp >>= 1;
    di += bp;
    di += memoryAGet16(ds, 0x1f76);
    di += memoryAGet16(ds, 0x1f7a);
    ax &= 0x0007;
    bx = 0x547c;
    bx += ax;
    ah = memoryAGet(ds, bx);
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    dx = 0x03ce;
    out(dx, ax);
    push(ax);
    bx = cx;
    bx &= 0x000f;
    bx += 0x2778;
    ah = memoryAGet(ds, bx);
    al = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = pop();
    flags.interrupts = false;
    al = memoryAGet(es, di);
    memoryASet(es, di, ah);
    flags.interrupts = true;
loc_16f71:
    bx = pop();
    dx = pop();
    bp = pop();
loc_16f74:
    cx--;
    if (cx == 0)
        return;
    goto loc_16ed2;
}
void sub_16f7b()
{
    flags.interrupts = false;
    push(ds);
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0300;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ds = cx;
    cx = 0xa000;
    es = cx;
    bp = di;
    cx = 0x0008;
loc_16fb7:
    push(cx);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    cx = ax;
    ah = al;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = 0x08;
    ah = ch;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = ah;
    stosb<MemAuto, DirAuto>();
    di += 0x002a;
    cx = pop();
    if (--cx)
        goto loc_16fb7;
    flags.interrupts = true;
    ds = pop();
}
void sub_16fe2()
{
    ax = memoryAGet16(ds, di + 2);
    if ((short)ax < (short)0x00b0)
        goto loc_16fed;
    return;
loc_16fed:
    ax -= 0x0020;
    if ((short)ax < 0)
        return;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dx = 0x002c;
    mul(dx);
    si = ax;
    ax = memoryAGet16(ds, di);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    push(ax);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    si += ax;
    si += memoryAGet16(ds, 0x1f76);
    si += 0x2172;
    si += 0x0002;
    si += 0x002c;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0200;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    ax = pop();
    bx = 0x547c;
    ax &= 0x0007;
    bx += ax;
    ah = memoryAGet(ds, bx);
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, si);
    memoryASet(es, si, ah);
    flags.interrupts = true;
}
void sub_1706f()
{
    push(di);
    bx = memoryAGet16(ds, di);
    bx += memoryAGet16(ds, di + 4);
    if ((short)bx >= 0)
        goto loc_1707b;
    bx += 0x0160;
loc_1707b:
    dx = bx;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    si = 0x0ea8;
    if (memoryAGet(ds, bx + si) == 0x01)
        goto loc_1708e;
    goto loc_1715d;
loc_1708e:
    ax = memoryAGet16(ds, 0x0000);
    ax -= 0x0010;
    dx -= ax;
    if ((short)dx >= 0)
        goto loc_1709c;
    dx += 0x0160;
loc_1709c:
    bx = dx;
    bx &= 0x0007;
    push(bx);
    al = memoryAGet(ds, di + 40);
    if (memoryAGet(ds, di + 39) == 0x01)
        goto loc_170ae;
    al += memoryAGet(ds, di + 41);
loc_170ae:
    ah = 0;
    if (memoryAGet(ds, di + 42) == 0xff)
        goto loc_170be;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
loc_170be:
    push(dx);
    cx = memoryAGet16(ds, di + 16);
    mul(cx);
    bp = ax;
    flags.carry = dx & 1;
    dx >>= 1;
    bp = rcr(bp, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    bp = rcr(bp, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    bp = rcr(bp, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    bp = rcr(bp, 0x0001);
    bp += memoryAGet16(ds, di + 12);
    ax &= 0x000f;
    dx = pop();
    si = ax;
    si += memoryAGet16(ds, di + 10);
    bx = si;
    bx += memoryAGet16(ds, di + 18);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    cx = memoryAGet16(ds, di + 6);
    push(memoryAGet16(ds, di + 20));
    al = memoryAGet(ds, di + 32);
    di = memoryAGet16(ds, di + 2);
    di += cx;
    if ((short)di >= 0)
        goto loc_170ff;
    di = 0;
loc_170ff:
    push(ax);
    push(dx);
    ax = di;
    di = 0x002c;
    mul(di);
    di = ax;
    dx = pop();
    ax = pop();
    di += dx;
    di += memoryAGet16(ds, 0x1f76);
    cx = memoryAGet16(ds, 0x1fe6);
    cx += bp;
    if (al == 0)
        goto loc_17159;
    bp = ax;
    ax = pop();
    dx = pop();
    push(dx);
    push(ax);
    push(di);
    push(cx);
    push(si);
    push(bx);
    cx = memoryAGet16(ds, 0x1fe8);
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dh = 0;
    ax = bp;
    ah = al;
    ah &= 0xf0;
    al = 0x40;
    al -= ah;
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x1070;
    ax += dx;
    si = ax;
    di -= 0x015f;
    sub_16f7b();
    bx = pop();
    si = pop();
    cx = pop();
    di = pop();
loc_17159:
    ax = pop();
    dx = pop();
    callIndirect(cs, ax);
loc_1715d:
    di = pop();
}
void sub_1715f()
{
    bp = ds;
    flags.interrupts = false;
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    out(dx, ax);
    di = memoryAGet16(ds, 0x000e);
    si = memoryAGet16(ds, 0x000a);
    dx = 0xa000;
    es = dx;
    ds = dx;
    cx = 0x0010;
loc_17182:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0029;
    if (--cx)
        goto loc_17182;
    ds = bp;
    dl = memoryAGet(ds, 0x1fe0);
    dh = 0;
    dx += memoryAGet16(ds, 0x0010);
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    si = memoryAGet16(ds, 0x0012);
    push(dx);
    ax = si;
    si = 0x002c;
    mul(si);
    si = ax;
    dx = pop();
    si += dx;
    si += memoryAGet16(ds, 0x1f78);
    memoryASet16(ds, 0x000c, si);
    di = memoryAGet16(ds, 0x0008);
    push(es);
    ds = pop();
    cx = 0x0010;
loc_171be:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    si += 0x0029;
    if (--cx)
        goto loc_171be;
    flags.interrupts = true;
    ds = bp;
}
void sub_17218()
{
    flags.interrupts = false;
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    out(dx, ax);
    ax = 0x0e01;
    out(dx, ax);
    ax = 0x0005;
    out(dx, ax);
    ax = 0x0003;
    out(dx, ax);
    cx = 0xa000;
    es = cx;
    bp = di;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    cx = memoryAGet16(ds, bx);
    bx++;
    bx++;
    al = 0x08;
    ah = cl;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    tl = ch;
    ch = ah;
    ah = tl;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    di = bp;
    ax = 0x0001;
    out(dx, ax);
    ax = 0x1003;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    al = memoryAGet(es, di);
    lodsw<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    di += 0x0029;
    flags.interrupts = true;
}
void sub_175ef()
{
    di = memoryAGet16(ds, 0x1f76);
    di += 0x1e42;
    sub_17602();
    di = memoryAGet16(ds, 0x1f78);
    di += 0x1e42;
    push(ds);
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    si = 0xf91f;
    dx = 0xa000;
    es = dx;
    ds = dx;
    cx = 0x06e0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
}
void sub_17602()
{
    push(ds);
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    si = 0xf91f;
    dx = 0xa000;
    es = dx;
    ds = dx;
    cx = 0x06e0;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
}
void sub_1762a()
{
    push(ds);
    push(ax);
    ah = 0;
    ax += ax;
    di = ax;
    di += 0x212c;
    di += memoryAGet16(ds, 0x1f76);
    di += 0x0002;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0c01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0f08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = pop();
    if (ah == 0)
        goto loc_176db;
    al = 0;
loc_1767e:
    al++;
    flags.carry = ah < 0x0a;
    ah -= 0x0a;
    if (!flags.carry)
        goto loc_1767e;
    al--;
    ah += 0x0a;
    push(ax);
    ah = 0;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += 0x0000;
    si = ax;
    ds = memoryAGet16(ds, 0x1fec);
    push(di);
    cx = 0x0008;
loc_176a2:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_176a2;
    di = pop();
    di++;
    ax = pop();
    al = ah;
    ah = 0;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += 0x0008;
    si = ax;
    ax = 0xf008;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x0008;
loc_176cd:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_176cd;
    ds = pop();
    return;
loc_176db:
    push(di);
    al = 0xff;
    cx = 0x0008;
loc_176e1:
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_176e1;
    di = pop();
    di++;
    ax = 0xf008;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = 0xff;
    cx = 0x0008;
loc_176fb:
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_176fb;
    ds = pop();
}
void sub_17708()
{
    push(ds);
    push(ax);
    al = ah;
    ah = 0;
    di = ax;
    di += 0x1e40;
    di += memoryAGet16(ds, 0x1f76);
    di += 0x0002;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = pop();
    if (al != 0x20)
        goto loc_1775d;
    goto loc_177fe;
loc_1775d:
    if (al != 0x25)
        goto loc_17766;
    si = 0;
    goto loc_177a8;
loc_17766:
    if (al != 0x3a)
        goto loc_17770;
    si = 0x0210;
    goto loc_177a8;
loc_17770:
    if ((char)al >= (char)0x30)
        goto loc_17777;
    goto loc_177fc;
loc_17777:
    if ((char)al > (char)0x39)
        goto loc_17793;
    al -= 0x30;
    si = 0x0030;
loc_17780:
    ah = 0;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    ax <<= 1;
    si += ax;
    goto loc_177a8;
loc_17793:
    if ((char)al >= (char)0x41)
        goto loc_1779a;
    goto loc_177fc;
loc_1779a:
    if ((char)al <= (char)0x5a)
        goto loc_177a1;
    goto loc_177fc;
loc_177a1:
    al -= 0x41;
    si = 0x0240;
    goto loc_17780;
loc_177a8:
    si += 0x00a0;
    ds = memoryAGet16(ds, 0x1fec);
    push(di);
    cx = 0x0010;
loc_177b4:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_177b4;
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dx = 0x03c4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    cx = 0x0010;
loc_177d8:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_177d8;
    di = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    cx = 0x0010;
loc_177f0:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_177f0;
loc_177fc:
    ds = pop();
    return;
loc_177fe:
    al = 0;
    cx = 0x0010;
loc_17803:
    flags.interrupts = false;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x002b;
    if (--cx)
        goto loc_17803;
    ds = pop();
}
void sub_1780d()
{
    ah = 0;
    ax += ax;
    di = ax;
    di += 0x2100;
    di += memoryAGet16(ds, 0x1f76);
    di += 0x0002;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0c01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = 0xff;
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    di += 0x002a;
    cx = 0x0016;
loc_17869:
    ax = 0x8008;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ah = memoryAGet(es, di);
    al = 0x80;
    stosb<MemAuto, DirAuto>();
    ax = 0x0108;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ah = memoryAGet(es, di);
    al = 0x01;
    stosb<MemAuto, DirAuto>();
    di += 0x002a;
    if (--cx)
        goto loc_17869;
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = 0xff;
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    ah = memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
}
void sub_1789e()
{
    if ((char)al >= (char)0x0a)
        goto loc_178b3;
    bl = al;
    bl += bl;
    bl += al;
    bh = 0;
    bx += 0x0064;
    memoryASet16(ds, bx + 1, 0x0000);
loc_178b3:
    push(ds);
    ah = 0;
    ax += ax;
    di = ax;
    push(di);
    di += 0x2100;
    di += memoryAGet16(ds, 0x1f76);
    di += 0x0002;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    si = pop();
    si += 0x02c0;
    si += 0xf91f;
    dx = 0xa000;
    es = dx;
    ds = dx;
    cx = 0x0018;
loc_178f4:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x002a;
    si += 0x002a;
    if (--cx)
        goto loc_178f4;
    ds = pop();
}
void sub_17900()
{
    bp = ds;
    di = memoryAGet16(ds, 0x1f76);
    di += 0x2172;
    di += 0x0002;
    si = 0xd320;
    dx = 0xa000;
    es = dx;
    ds = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0f01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = 0;
    cx = 0x000d;
    rep_stosb<MemAuto, DirAuto>();
    di += 0x001f;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    dx = 0x0013;
loc_17961:
    cx = 0x000d;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x001f;
    dx--;
    if (dx != 0)
        goto loc_17961;
    ds = bp;
}
void sub_1796f()
{
    push(ds);
    di = 0xffff83c1;
    cx = 0x000a;
    ax = 0;
    push(cs);
    es = pop();
    rep_stosw<MemAuto, DirAuto>();
    si = memoryAGet16(ds, 0x0056);
    si += 0x0010;
    if ((short)si < (short)0x00d0)
        goto loc_1798c;
    si = 0;
loc_1798c:
    memoryASet16(ds, 0x0056, si);
    di = si;
    si += 0x0d00;
    si += 0x4a40;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di += 0xd320;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0600;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0801;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x0014;
    bx = 0xffff83c1;
loc_179f8:
    sub_17a25();
    si += 0x0680;
    bx++;
    if (--cx)
        goto loc_179f8;
    dx = 0x03ce;
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    cx = 0x0013;
    bx = 0xffff83c1;
loc_17a14:
    ah = memoryAGet(cs, bx);
    al = memoryAGet(es, di);
    memoryASet(es, di, ah);
    di += 0x000d;
    bx++;
    if (--cx)
        goto loc_17a14;
    ds = pop();
}
void sub_17a25()
{
    push(cx);
    push(si);
    dl = 0x80;
    cx = 0x0008;
loc_17a2c:
    sub_17a39();
    si += 0x0002;
    dl >>= 1;
    if (--cx)
        goto loc_17a2c;
    si = pop();
    cx = pop();
}
void sub_17a39()
{
    push(cx);
    ah = memoryAGet(es, si);
    al = memoryAGet(es, si + 1);
    cx = 0x0010;
    dh = 0;
loc_17a46:
    flags.carry = ax & 1;
    ax >>= 1;
    if (!flags.carry)
        goto loc_17a4c;
    dh++;
loc_17a4c:
    if (--cx)
        goto loc_17a46;
    if ((char)dh > (char)0x08)
        goto loc_17a55;
    cx = pop();
    return;
loc_17a55:
    memoryASet(cs, bx, memoryAGet(cs, bx) | dl);
    cx = pop();
}
void sub_17a5a()
{
    di = memoryAGet16(ds, 0x0000);
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di >>= 1;
    di += 0x2172;
    di += memoryAGet16(ds, 0x1f76);
    di += 0x0002;
    dx = 0xa000;
    es = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0c01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    cx = 0xffff;
    bx = 0xff00;
    ax = memoryAGet16(ds, 0x0000);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax &= 0x0007;
    push(ax);
    if (ax == 0)
        goto loc_17ac8;
loc_17ac0:
    flags.carry = cx & 1;
    cx >>= 1;
    bx = rcr(bx, 0x0001);
    al--;
    if (al != 0)
        goto loc_17ac0;
loc_17ac8:
    al = 0x08;
    ah = ch;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di += 0x0340;
    al = 0x08;
    ah = ch;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    ah = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di -= 0x0030;
    cx = 0x8000;
    bx = 0x0100;
    ax = pop();
    if (ax == 0)
        goto loc_17b6a;
loc_17b62:
    flags.carry = cx & 1;
    cx >>= 1;
    bx = rcr(bx, 0x0001);
    al--;
    if (al != 0)
        goto loc_17b62;
loc_17b6a:
    bp = 0x0012;
loc_17b6d:
    al = 0x08;
    ah = ch;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = ch;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = cl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = cl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bh;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bh;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    al = 0x08;
    ah = bl;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = bl;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    di -= 0x0030;
    bp--;
    if (bp != 0)
        goto loc_17b6d;
}
void sub_17bb8()
{
    si = 0x17cb;
    di = 0xfeb;
    cx = 0x0020;
loc_17bc3:
    ah = memoryAGet(ds, di);
    al = memoryAGet(ds, di + 1);
    if (ax == 0)
        goto loc_17c01;
    push(cx);
    push(di);
    push(si);
    ax -= memoryAGet16(ds, 0x0000);
    ax += 0x0010;
    bh = memoryAGet(ds, di + 2);
    bl = memoryAGet(ds, di + 3);
    dh = memoryAGet(ds, di + 6);
    dl = memoryAGet(ds, di + 7);
    bp = dx;
    bp &= 0xfffe;
    dl = memoryAGet(ds, si + 4);
    dh = 0;
    cl = memoryAGet(ds, si + 5);
    di = memoryAGet16(ds, si + 8);
    si = memoryAGet16(ds, si + 23);
    di += si;
    ch = 0x04;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    si = pop();
    di = pop();
    cx = pop();
loc_17c01:
    di += 0x0008;
    si += 0x001c;
    if (--cx)
        goto loc_17bc3;
}
void sub_17c67()
{
    push(si);
    dx = ax;
    cl = 0x07;
    dx >>= cl;
    dx &= 0x00c0;
    dx |= 0x000f;
    flags.carry = false;
    if (!(dx & 0x0040))
        goto loc_17c7f;
    dx |= 0x0f00;
loc_17c7f:
    ax = rcl(ax, 0x0001);
    if (!flags.carry)
        goto loc_17c87;
    dx |= 0x8000;
loc_17c87:
    ax >>= 1;
    bp = dx;
    dx = bx;
    dx &= 0x003f;
    bx = sar(bx, cl);
    bx -= 0x0004;
    ax &= 0x1fff;
    push(bx);
    push(ax);
    ax = 0x0008;
    mul(dx);
    ax += 0x1d0b;
    bx = ax;
    dl = memoryAGet(ds, bx);
    dh = 0;
    cl = memoryAGet(ds, bx + 1);
    si = memoryAGet16(ds, bx + 2);
    di = memoryAGet16(ds, bx + 4);
    ax = pop();
    bx = pop();
    ch = 0x04;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    si = pop();
}
void sub_17cbc()
{
    ax = 0x49ce;
    memoryASet16(ds, 0x001d, ax);
    memoryASet16(ds, 0x001f, ax);
    memoryASet16(ds, 0x0021, 0x0004);
    memoryASet16(ds, 0x0023, 0x0000);
    es = memoryAGet16(ds, 0x1ff0);
    al = 0;
    cx = 0x0023;
loc_17cdb:
    push(cx);
    push(ax);
    sub_17d8d();
    ax = pop();
    cx = pop();
    al++;
    if (--cx)
        goto loc_17cdb;
    ax = memoryAGet16(ds, 0x1ff0);
    memoryASet16(ds, 0x1fe4, ax);
    bp = 0;
    ax = 0x0030;
    bx = 0x014e;
    dx = 0x0230;
    cx = 0x0410;
    si = 0;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x1000;
    memoryASet16(ds, 0x1fe4, ax);
    goto loc_17e2f;
    //   gap of 290 bytes
loc_17e2f:
    si = 0x1c10;
    ax = memoryAGet16(ds, 0x0021);
    ax >>= 1;
    ax >>= 1;
    ax &= 0x000f;
    tl = al;
    al = ah;
    ah = tl;
    si += ax;
    ax >>= 1;
    si += ax;
    ax = 0;
    sub_17e65();
    si = 0x1c10;
    ax = memoryAGet16(ds, 0x0021);
    ax >>= 1;
    ax >>= 1;
    ax &= 0x000f;
    tl = al;
    al = ah;
    ah = tl;
    si += ax;
    ax >>= 1;
    si += ax;
    si += 0x1800;
    ax = 0x0250;
    bp = 0;
    dx = 0x0030;
    cx = 0x0410;
    bx = 0x014e;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_17ce6()
{
    ax = memoryAGet16(ds, 0x1ff0);
    memoryASet16(ds, 0x1fe4, ax);
    bp = 0;
    ax = 0x0030;
    bx = 0x014e;
    dx = 0x0230;
    cx = 0x0410;
    si = 0;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x1000;
    memoryASet16(ds, 0x1fe4, ax);
    goto loc_17e2f;
    //   gap of 290 bytes
loc_17e2f:
    si = 0x1c10;
    ax = memoryAGet16(ds, 0x0021);
    ax >>= 1;
    ax >>= 1;
    ax &= 0x000f;
    tl = al;
    al = ah;
    ah = tl;
    si += ax;
    ax >>= 1;
    si += ax;
    ax = 0;
    sub_17e65();
    si = 0x1c10;
    ax = memoryAGet16(ds, 0x0021);
    ax >>= 1;
    ax >>= 1;
    ax &= 0x000f;
    tl = al;
    al = ah;
    ah = tl;
    si += ax;
    ax >>= 1;
    si += ax;
    si += 0x1800;
    ax = 0x0250;
    bp = 0;
    dx = 0x0030;
    cx = 0x0410;
    bx = 0x014e;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_17d0d()
{
    sub_17ce6();
    ax = memoryAGet16(ds, 0x0023);
    if (ax == 0)
        goto loc_17d1c;
    memoryASet16(ds, 0x0023, memoryAGet16(ds, 0x0023) - 1);
    return;
loc_17d1c:
    es = memoryAGet16(ds, 0x1ff0);
    ax = memoryAGet16(ds, 0x0021);
    ax += 0x0004;
    memoryASet16(ds, 0x0021, ax);
    ax &= 0x000f;
    if (ax != 0)
        goto loc_17d54;
    al = 0x22;
    sub_17d8d();
    si = memoryAGet16(ds, 0x001f);
    lodsb<MemAuto, DirAuto>();
    if (al != 0xff)
        goto loc_17d44;
    memoryASet16(ds, 0x0023, 0x0064);
    goto loc_17d4c;
loc_17d44:
    if (al != 0x0d)
        goto loc_17d4d;
    si = memoryAGet16(ds, 0x001d);
loc_17d4c:
    lodsb<MemAuto, DirAuto>();
loc_17d4d:
    memoryASet16(ds, 0x001f, si);
    sub_17db7();
loc_17d54:
    di = 0x0045;
    cx = 0x0004;
loc_17d5a:
    push(cx);
    push(di);
    cx = 0x0010;
loc_17d5f:
    push(cx);
    push(di);
    cx = 0x0046;
    bl = 0;
loc_17d66:
    al = memoryAGet(es, di);
    ah = 0;
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    ax = rcl(ax, 0x0001);
    ax = rcl(ax, 0x0001);
    ax = rcl(ax, 0x0001);
    al |= bl;
    memoryASet(es, di, al);
    bl = ah;
    di--;
    if (--cx)
        goto loc_17d66;
    di = pop();
    cx = pop();
    di += 0x0046;
    if (--cx)
        goto loc_17d5f;
    di = pop();
    cx = pop();
    di += 0x0460;
    if (--cx)
        goto loc_17d5a;
}
void sub_17d8d()
{
    push(ds);
    si = 0x4c10;
    ah = 0;
    ax += ax;
    di = ax;
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x1000;
    ds = ax;
    cx = 0x0004;
loc_17da2:
    push(cx);
    push(di);
    cx = 0x0010;
loc_17da7:
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x0044;
    if (--cx)
        goto loc_17da7;
    di = pop();
    cx = pop();
    di += 0x0460;
    if (--cx)
        goto loc_17da2;
    ds = pop();
}
void sub_17db7()
{
    push(ds);
    if (al == 0x20)
        goto loc_17e2d;
    al -= 0x21;
    ah = 0;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    si = ax;
    ax += ax;
    si += ax;
    si += 0x5bc0;
    bx = si;
    bx += 0x0040;
    ax = memoryAGet16(ds, 0x1fee);
    ax += 0x1000;
    ds = ax;
    di = 0x0044;
    cx = 0x0003;
loc_17de7:
    push(cx);
    push(di);
    push(bx);
    cx = 0x0010;
loc_17ded:
    al = memoryAGet(ds, bx);
    al = ~al;
    al &= memoryAGet(es, di);
    al |= memoryAGet(ds, si);
    stosb<MemAuto, DirAuto>();
    si++;
    bx++;
    al = memoryAGet(ds, bx);
    al = ~al;
    al &= memoryAGet(es, di);
    al |= memoryAGet(ds, si);
    stosb<MemAuto, DirAuto>();
    si++;
    bx++;
    di += 0x0044;
    if (--cx)
        goto loc_17ded;
    bx = pop();
    di = pop();
    cx = pop();
    di += 0x0460;
    if (--cx)
        goto loc_17de7;
    cx = 0x0010;
loc_17e16:
    al = memoryAGet(ds, bx);
    al = ~al;
    al &= memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    bx++;
    al = memoryAGet(ds, bx);
    al = ~al;
    al &= memoryAGet(es, di);
    stosb<MemAuto, DirAuto>();
    bx++;
    di += 0x0044;
    if (--cx)
        goto loc_17e16;
loc_17e2d:
    ds = pop();
}
void sub_17e65()
{
    bp = 0;
    dx = 0x0030;
    cx = 0x0410;
    bx = 0x014e;
    push(cs);
    cs = 0x1000;
    sub_18822();
    assert(cs == 0x1000);
}
void sub_17eb2()
{
    push(ds);
    di = memoryAGet16(ds, 0x1f76);
    di += memoryAGet16(ds, 0x1f7a);
    di += 0x064f;
    si = 0x4f22;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0xa000;
    es = ax;
    ds = ax;
    cx = 0x0027;
loc_17f01:
    push(cx);
    push(si);
    push(di);
    cx = 0x0034;
loc_17f07:
    push(cx);
    push(dx);
    dx = 0x03c4;
    ax = 0x0102;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    ax = 0x0004;
    memoryASet16(ss, 0x0010, ax);
    out(dx, ax);
    ch = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    al = ch;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x80;
    ah = al;
    al = ch;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x40;
    ah |= al;
    al = cl;
    al &= 0x20;
    ah |= al;
    al = cl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x10;
    ah |= al;
    al = bh;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x08;
    ah |= al;
    al = bh;
    al = rol(al, 0x01);
    al &= 0x04;
    ah |= al;
    al = bl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x02;
    ah |= al;
    al = bl;
    al = ror(al, 0x01);
    al &= 0x01;
    ah |= al;
    flags.interrupts = false;
    al = memoryAGet(ds, di);
    memoryASet(ds, di, ah);
    flags.interrupts = true;
    push(dx);
    dx = 0x03c4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    ax = 0x0104;
    memoryASet16(ss, 0x0010, ax);
    out(dx, ax);
    ch = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    al = ch;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x80;
    ah = al;
    al = ch;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x40;
    ah |= al;
    al = cl;
    al &= 0x20;
    ah |= al;
    al = cl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x10;
    ah |= al;
    al = bh;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x08;
    ah |= al;
    al = bh;
    al = rol(al, 0x01);
    al &= 0x04;
    ah |= al;
    al = bl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x02;
    ah |= al;
    al = bl;
    al = ror(al, 0x01);
    al &= 0x01;
    ah |= al;
    flags.interrupts = false;
    al = memoryAGet(ds, di);
    memoryASet(ds, di, ah);
    flags.interrupts = true;
    push(dx);
    dx = 0x03c4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    ax = 0x0204;
    memoryASet16(ss, 0x0010, ax);
    out(dx, ax);
    ch = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    al = ch;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x80;
    ah = al;
    al = ch;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x40;
    ah |= al;
    al = cl;
    al &= 0x20;
    ah |= al;
    al = cl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x10;
    ah |= al;
    al = bh;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x08;
    ah |= al;
    al = bh;
    al = rol(al, 0x01);
    al &= 0x04;
    ah |= al;
    al = bl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x02;
    ah |= al;
    al = bl;
    al = ror(al, 0x01);
    al &= 0x01;
    ah |= al;
    flags.interrupts = false;
    al = memoryAGet(ds, di);
    memoryASet(ds, di, ah);
    flags.interrupts = true;
    push(dx);
    dx = 0x03c4;
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    ax = 0x0304;
    memoryASet16(ss, 0x0010, ax);
    out(dx, ax);
    ch = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    bh = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, si + 3);
    al = ch;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x80;
    ah = al;
    al = ch;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x40;
    ah |= al;
    al = cl;
    al &= 0x20;
    ah |= al;
    al = cl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x10;
    ah |= al;
    al = bh;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al &= 0x08;
    ah |= al;
    al = bh;
    al = rol(al, 0x01);
    al &= 0x04;
    ah |= al;
    al = bl;
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al = rol(al, 0x01);
    al &= 0x02;
    ah |= al;
    al = bl;
    al = ror(al, 0x01);
    al &= 0x01;
    ah |= al;
    flags.interrupts = false;
    al = memoryAGet(ds, di);
    memoryASet(ds, di, ah);
    flags.interrupts = true;
    di++;
    si += 0x0004;
    cx = pop();
    cx--;
    if (cx == 0)
        goto loc_180eb;
    goto loc_17f07;
loc_180eb:
    di = pop();
    si = pop();
    di += 0x0050;
    si += 0x0340;
    cx = pop();
    cx--;
    if (cx == 0)
        goto loc_180fb;
    goto loc_17f01;
loc_180fb:
    ds = pop();
}
void sub_180fd()
{
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    push(ss);
    es = pop();
    di = memoryAGet16(ds, 0x0026);
    al = memoryAGet(es, di);
    if (al == 0)
        goto loc_18123;
    goto loc_1819d;
loc_18123:
    push(ds);
    di++;
    bp = memoryAGet16(ds, 0x1f76);
    bp += 0x02c2;
    si = 0x4a40;
    ax = memoryAGet16(ds, 0x0002);
    si += ax;
    dx = 0xa000;
    ds = dx;
    al = 0x01;
    cx = 0x0014;
loc_1813f:
    push(cx);
    cx = 0x0028;
loc_18143:
    repne_scasb<MemAuto, DirAuto>(al);
    if (flags.zero)
        goto loc_18160;
loc_18147:
    cx = pop();
    bp += 0x0160;
    si += 0x0680;
    if (--cx)
        goto loc_1813f;
    ds = pop();
    di = memoryAGet16(ds, 0x0026);
    di++;
    cx = 0x0320;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    return;
loc_18160:
    push(cx);
    repne_scasb<MemAuto, DirAuto>(al);
    bx = pop();
    bx++;
    push(cx);
    push(di);
    push(si);
    push(bp);
    push(ax);
    push(es);
    di = bp;
    ax = 0x0028;
    ax -= bx;
    si += ax;
    di += ax;
    bx -= cx;
    cx = bx;
    dx = bx;
    dx += 0xffd4;
    bx += 0xff30;
    push(ds);
    es = pop();
    al = 0x08;
loc_18187:
    push(cx);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    si -= bx;
    di -= dx;
    al--;
    if (al != 0)
        goto loc_18187;
    es = pop();
    ax = pop();
    bp = pop();
    si = pop();
    di = pop();
    cx = pop();
    if (cx == 0)
        goto loc_18147;
    goto loc_18143;
loc_1819d:
    memoryASet(es, di, 0x00);
    bp = ds;
    di = memoryAGet16(ds, 0x1f76);
    di += 0x02c2;
    si = 0x4a40;
    ax = memoryAGet16(ds, 0x0002);
    si += ax;
    dx = 0xa000;
    es = dx;
    ds = dx;
    dx = 0x00a0;
loc_181bd:
    cx = 0x002c;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si += 0x00a4;
    dx--;
    if (dx != 0)
        goto loc_181bd;
    ds = bp;
}
void sub_181cc()
{
    memoryASet16(ds, 0x1f76, 0x0000);
    memoryASet16(ds, 0x1f78, 0x2520);
    memoryASet16(ds, 0x1f7a, 0x02c0);
    memoryASet16(ds, 0x0026, 0x42b2);
    memoryASet16(ds, 0x0028, 0x45d3);
    bx = memoryAGet16(ds, 0x0026);
    memoryASet(ss, bx, 0xff);
    bx = memoryAGet16(ds, 0x0028);
    memoryASet(ss, bx, 0xff);
    memoryASet(ds, 0x002a, 0xff);
    sub_180fd();
    ax = memoryAGet16(ds, 0x1f78);
    tx = memoryAGet16(ds, 0x1f76);
    memoryASet16(ds, 0x1f76, ax);
    ax = tx;
    memoryASet16(ds, 0x1f78, ax);
    ax = memoryAGet16(ds, 0x0028);
    tx = memoryAGet16(ds, 0x0026);
    memoryASet16(ds, 0x0026, ax);
    ax = tx;
    memoryASet16(ds, 0x0028, ax);
    sub_139ce();
    sub_180fd();
    ax = 0x0160;
    bx = 0x00a0;
    dx = memoryAGet16(ds, 0x1f76);
    push(cs);
    cs = 0x1000;
    sub_18808();
    assert(cs == 0x1000);
    memoryASet16(ds, 0x0008, 0xd2c0);
    memoryASet16(ds, 0x000a, 0xd2f0);
}
void sub_18238()
{
    ax = memoryAGet16(ds, 0x1ff0);
    memoryASet16(ds, 0x1fe4, ax);
    bx = 0;
    goto loc_18252;
    //   gap of 16 bytes
loc_18252:
    di = 0xb840;
    si = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    cx = 0x0960;
loc_1825f:
    ax = memoryAGet16(es, si);
    ax |= memoryAGet16(es, si + 4800);
    ax |= memoryAGet16(es, si + 9600);
    stosw<MemAuto, DirAuto>();
    si += 0x0002;
    if (--cx)
        goto loc_1825f;
    ax = 0x00d0;
    mul(bx);
    di = ax;
    di += 0x4a40;
    di += 0x0028;
    si = 0x8000;
    push(ds);
    ds = memoryAGet16(ds, 0x1ff0);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x2878;
    push(di);
    push(cx);
loc_182c7:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182cb:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182cb;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_182dc;
    goto loc_182c7;
loc_182dc:
    cx = pop();
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_182f2:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182f6:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182f6;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_182f2;
    cx = pop();
    di = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_18311:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18315:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18315;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_18311;
    cx = pop();
    di = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_1832e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18332:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18332;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1832e;
    ds = pop();
}
void sub_18243()
{
    bx = 0x0028;
    goto loc_18252;
    //   gap of 10 bytes
loc_18252:
    di = 0xb840;
    si = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    cx = 0x0960;
loc_1825f:
    ax = memoryAGet16(es, si);
    ax |= memoryAGet16(es, si + 4800);
    ax |= memoryAGet16(es, si + 9600);
    stosw<MemAuto, DirAuto>();
    si += 0x0002;
    if (--cx)
        goto loc_1825f;
    ax = 0x00d0;
    mul(bx);
    di = ax;
    di += 0x4a40;
    di += 0x0028;
    si = 0x8000;
    push(ds);
    ds = memoryAGet16(ds, 0x1ff0);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x2878;
    push(di);
    push(cx);
loc_182c7:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182cb:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182cb;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_182dc;
    goto loc_182c7;
loc_182dc:
    cx = pop();
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_182f2:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182f6:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182f6;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_182f2;
    cx = pop();
    di = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_18311:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18315:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18315;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_18311;
    cx = pop();
    di = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_1832e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18332:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18332;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1832e;
    ds = pop();
}
void sub_18249()
{
    bx = 0x0050;
    goto loc_18252;
    //   gap of 4 bytes
loc_18252:
    di = 0xb840;
    si = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    cx = 0x0960;
loc_1825f:
    ax = memoryAGet16(es, si);
    ax |= memoryAGet16(es, si + 4800);
    ax |= memoryAGet16(es, si + 9600);
    stosw<MemAuto, DirAuto>();
    si += 0x0002;
    if (--cx)
        goto loc_1825f;
    ax = 0x00d0;
    mul(bx);
    di = ax;
    di += 0x4a40;
    di += 0x0028;
    si = 0x8000;
    push(ds);
    ds = memoryAGet16(ds, 0x1ff0);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x2878;
    push(di);
    push(cx);
loc_182c7:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182cb:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182cb;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_182dc;
    goto loc_182c7;
loc_182dc:
    cx = pop();
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_182f2:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182f6:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182f6;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_182f2;
    cx = pop();
    di = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_18311:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18315:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18315;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_18311;
    cx = pop();
    di = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_1832e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18332:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18332;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1832e;
    ds = pop();
}
void sub_1824f()
{
    bx = 0x0078;
    di = 0xb840;
    si = 0x8000;
    es = memoryAGet16(ds, 0x1ff0);
    cx = 0x0960;
loc_1825f:
    ax = memoryAGet16(es, si);
    ax |= memoryAGet16(es, si + 4800);
    ax |= memoryAGet16(es, si + 9600);
    stosw<MemAuto, DirAuto>();
    si += 0x0002;
    if (--cx)
        goto loc_1825f;
    ax = 0x00d0;
    mul(bx);
    di = ax;
    di += 0x4a40;
    di += 0x0028;
    si = 0x8000;
    push(ds);
    ds = memoryAGet16(ds, 0x1ff0);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    cx = 0x2878;
    push(di);
    push(cx);
loc_182c7:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182cb:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182cb;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_182dc;
    goto loc_182c7;
loc_182dc:
    cx = pop();
    di = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_182f2:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_182f6:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_182f6;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_182f2;
    cx = pop();
    di = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(cx);
loc_18311:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18315:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18315;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_18311;
    cx = pop();
    di = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_1832e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_18332:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_18332;
    flags.interrupts = true;
    di += 0x0058;
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1832e;
    ds = pop();
}
void sub_18343()
{
    push(ds);
    push(cs);
    ds = pop();
    bx = 0x188f;
    cx = 0x000a;
    al = 0;
    memoryASet(cs, 0x83b9, al);
    memoryASet(cs, 0x83ba, al);
    memoryASet16(cs, 0x83bb, bx);
loc_1835b:
    al ^= memoryAGet(cs, bx);
    bx++;
    if (--cx)
        goto loc_1835b;
    ds = pop();
}
void sub_18808()
{
    memoryASet16(ds, 0x66f2, ax);
    memoryASet16(ds, 0x66f0, bx);
    memoryASet16(ds, 0x1f76, dx);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x66f4, ax);
    mul(bx);
    memoryASet16(ds, 0x66f6, ax);
    cs = pop();
}
void sub_18822()
{
    push(ax);
    push(dx);
    push(cx);
    ax = dx;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x66fa, ax);
    ch = 0;
    mul(cx);
    memoryASet16(ds, 0x66f8, ax);
    cx = pop();
    dx = pop();
    ax = pop();
    memoryASet16(ds, 0x66fe, 0x0000);
    memoryASet16(ds, 0x66fc, 0x0000);
    if (!(bp & 0x000c))
        goto loc_18853;
    sub_19967();
    if ((short)ax < 0)
        goto loc_188ab;
loc_18853:
    if (memoryAGet(ds, 0x002a) != 0xff)
        goto loc_1885e;
    sub_19a15();
loc_1885e:
    tx = bx;
    bx = ax;
    ax = tx;
    push(bx);
    bx &= 0x0007;
    memoryASet(ds, 0xa948, bl);
    bx = pop();
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    push(dx);
    mul(memoryAGet16(ds, 0x66f4));
    dx = pop();
    bx += ax;
    bx += memoryAGet16(ds, 0x1f76);
    bx += memoryAGet16(ds, 0x1f7a);
    tx = di;
    di = bx;
    bx = tx;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    ax = dx;
    ax -= memoryAGet16(ds, 0x66f4);
    ax = -ax;
    memoryASet16(ds, 0x6700, ax);
    memoryASet16(ds, 0x6704, ax);
    dh = ch;
    ch = cl;
    cl = dl;
    ax = memoryAGet16(ds, 0x66f8);
    if (bp & 0x0001)
        goto loc_188a6;
    goto loc_1939e;
loc_188a6:
    if (!(bp & 0x0001))
        goto loc_188ab;
    goto loc_188ac;
loc_188ab:
    cs = pop();
    return;
loc_188ac:
    if (memoryAGet(ds, 0xa948) != 0x00)
        goto loc_188b6;
    goto loc_1939e;
loc_188b6:
    if (bp & 0x0002)
        goto loc_188bf;
    goto loc_19140;
loc_188bf:
    ax = bp;
    push(bp);
    bp = memoryAGet16(ds, 0x66fc);
    if (!(ax & 0x0080))
        goto loc_188e5;
    ax = memoryAGet16(ds, 0x66f8);
    ax -= memoryAGet16(ds, 0x66fe);
    ax -= memoryAGet16(ds, 0x66fe);
    bx += ax;
    si += ax;
    ax = memoryAGet16(ds, 0x66fa);
    bx -= ax;
    si -= ax;
    bp -= ax;
    bp -= ax;
loc_188e5:
    memoryASet16(ds, 0x6702, bp);
    bp = pop();
    if (!(bp & 0x4000))
        goto loc_188f3;
    goto loc_18d66;
loc_188f3:
    if (!(bp & 0x8000))
        goto loc_188fc;
    goto loc_18b42;
loc_188fc:
    if (!(bp & 0x0020))
        goto loc_18905;
    goto loc_18ff7;
loc_18905:
    if (!(bp & 0x0040))
        goto loc_1890e;
    goto loc_1909c;
loc_1890e:
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_18952:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(cx);
    push(di);
    ch = 0;
    si = bx;
    di = 0x6748;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    bx = 0x6748;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18989:
    push(si);
    push(bx);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18993:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18993;
    cx = pop();
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, bx) & 1;
    memoryASet(ds, bx, memoryAGet(ds, bx) >> 1);
    bx++;
loc_189a3:
    memoryASet(ds, bx, rcr(memoryAGet(ds, bx), 0x01));
    bx++;
    if (--cx)
        goto loc_189a3;
    cx = pop();
    bx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18989;
    ch = 0;
    cl++;
loc_189b5:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_189b5;
    bx = pop();
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    bx += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_189df;
    goto loc_18952;
loc_189df:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_189e8;
    goto loc_18b40;
loc_189e8:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_18a12:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18a33:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18a3c:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18a3c;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18a33;
    ch = 0;
    cl++;
loc_18a4d:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_18a4d;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18a12;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18a70;
    goto loc_18b40;
loc_18a70:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_18a80:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18aa1:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18aaa:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18aaa;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18aa1;
    ch = 0;
    cl++;
loc_18abb:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_18abb;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18a80;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18ade;
    goto loc_18b40;
loc_18ade:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_18aeb:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18b0c:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18b15:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18b15;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18b0c;
    ch = 0;
    cl++;
loc_18b26:
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_18b26;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18aeb;
loc_18b40:
    ds = pop();
    cs = pop();
    return;
loc_18b42:
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0102;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_18b96:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18bb7:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18bc0:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18bc0;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18bb7;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_18bd2:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18bd2;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_18bf6;
    goto loc_18b96;
loc_18bf6:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18bff;
    goto loc_18d64;
loc_18bff:
    si += memoryAGet16(es, 0x66f8);
    push(dx);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    push(di);
    push(si);
    push(cx);
loc_18c13:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18c34:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18c3d:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18c3d;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18c34;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_18c4f:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18c4f;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18c13;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18c7a;
    goto loc_18d64;
loc_18c7a:
    si += memoryAGet16(es, 0x66f8);
    push(dx);
    dl = 0xc4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    push(di);
    push(si);
    push(cx);
loc_18c8e:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18caf:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18cb8:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18cb8;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18caf;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_18cca:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18cca;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18c8e;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18cf5;
    goto loc_18d64;
loc_18cf5:
    si += memoryAGet16(es, 0x66f8);
    push(dx);
    dl = 0xc4;
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
loc_18d06:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18d27:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18d30:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18d30;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18d27;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_18d42:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18d42;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_18d06;
loc_18d64:
    ds = pop();
    cs = pop();
    return;
loc_18d66:
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    flags.interrupts = false;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    push(cx);
    push(bp);
    push(di);
    push(si);
    bp = 0x6748;
loc_18dc0:
    push(cx);
    push(ds);
    push(es);
    push(cx);
    push(di);
    ch = 0;
    di = bp;
    si = bx;
    bx = bp;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    bp = di;
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    al = memoryAGet(ds, 0xa948);
loc_18de1:
    push(bx);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, bx) & 1;
    memoryASet(ds, bx, memoryAGet(ds, bx) >> 1);
    bx++;
loc_18dea:
    memoryASet(ds, bx, rcr(memoryAGet(ds, bx), 0x01));
    bx++;
    if (--cx)
        goto loc_18dea;
    cx = pop();
    bx = pop();
    al--;
    if (al != 0)
        goto loc_18de1;
    ch = 0;
    cl++;
loc_18dfb:
    al = memoryAGet(es, di);
    memoryASet(ds, bx, memoryAGet(ds, bx) & al);
    bx++;
    di++;
    if (--cx)
        goto loc_18dfb;
    bx = pop();
    bx += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    es = pop();
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_18dc0;
    si = pop();
    di = pop();
    bp = pop();
    cx = pop();
    bx = 0x6748;
    push(di);
    push(si);
    push(cx);
    push(bx);
loc_18e20:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18e41:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18e4a:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18e4a;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18e41;
    ch = 0;
    cl++;
loc_18e5b:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    al &= ah;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18e5b;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_18e80;
    goto loc_18e20;
loc_18e80:
    bx = pop();
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18e8a;
    goto loc_18ff4;
loc_18e8a:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
    push(bx);
loc_18eb5:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18ed6:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18edf:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18edf;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18ed6;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_18ef1:
    ah = memoryAGet(es, di);
    ah = memoryAGet(ds, bx);
    bx++;
    lodsb<MemAuto, DirAuto>();
    al &= ah;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18ef1;
    flags.interrupts = true;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_18f10;
    goto loc_18eb5;
loc_18f10:
    bx = pop();
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18f1a;
    goto loc_18ff4;
loc_18f1a:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
    push(bx);
loc_18f2b:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18f4c:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18f55:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18f55;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18f4c;
    ch = 0;
    cl++;
loc_18f66:
    ah = memoryAGet(es, di);
    ah = memoryAGet(ds, bx);
    bx++;
    lodsb<MemAuto, DirAuto>();
    al &= ah;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18f66;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_18f84;
    goto loc_18f2b;
loc_18f84:
    bx = pop();
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_18f8e;
    goto loc_18ff4;
loc_18f8e:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_18f9b:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_18fbc:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_18fc5:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_18fc5;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_18fbc;
    ch = 0;
    cl++;
loc_18fd6:
    al = memoryAGet(es, di);
    ah = memoryAGet(ds, bx);
    bx++;
    lodsb<MemAuto, DirAuto>();
    al &= ah;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18fd6;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_18ff4;
    goto loc_18f9b;
loc_18ff4:
    flags.interrupts = true;
    ds = pop();
    cs = pop();
    return;
loc_18ff7:
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0f00;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = bp;
    ah &= 0x0f;
    al = 0x01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    si = bx;
loc_19039:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6748;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    bx = 0x6748;
    al = memoryAGet(ds, 0xa948);
loc_1905a:
    push(bx);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, bx) & 1;
    memoryASet(ds, bx, memoryAGet(ds, bx) >> 1);
    bx++;
loc_19063:
    memoryASet(ds, bx, rcr(memoryAGet(ds, bx), 0x01));
    bx++;
    if (--cx)
        goto loc_19063;
    cx = pop();
    bx = pop();
    al--;
    if (al != 0)
        goto loc_1905a;
    ch = 0;
    cl++;
loc_19074:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = 0xff;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_19074;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_1909a;
    goto loc_19039;
loc_1909a:
    ds = pop();
    cs = pop();
    return;
loc_1909c:
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = bp;
    ah &= 0x0f;
    al = 0x01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    si = bx;
loc_190dd:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6748;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    bx = 0x6748;
    al = memoryAGet(ds, 0xa948);
loc_190fe:
    push(bx);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, bx) & 1;
    memoryASet(ds, bx, memoryAGet(ds, bx) >> 1);
    bx++;
loc_19107:
    memoryASet(ds, bx, rcr(memoryAGet(ds, bx), 0x01));
    bx++;
    if (--cx)
        goto loc_19107;
    cx = pop();
    bx = pop();
    al--;
    if (al != 0)
        goto loc_190fe;
    ch = 0;
    cl++;
loc_19118:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = 0xff;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_19118;
    si = pop();
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_1913e;
    goto loc_190dd;
loc_1913e:
    ds = pop();
    cs = pop();
    return;
loc_19140:
    ax = bp;
    push(bp);
    bp = memoryAGet16(ds, 0x66fc);
    if (!(ax & 0x0080))
        goto loc_19166;
    ax = memoryAGet16(ds, 0x66f8);
    ax -= memoryAGet16(ds, 0x66fe);
    ax -= memoryAGet16(ds, 0x66fe);
    bx += ax;
    si += ax;
    ax = memoryAGet16(ds, 0x66fa);
    bx -= ax;
    si -= ax;
    bp -= ax;
    bp -= ax;
loc_19166:
    memoryASet16(ds, 0x6702, bp);
    bp = pop();
    memoryASet16(ds, 0x6704, memoryAGet16(ds, 0x6704) - 1);
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0x19a9;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_191af:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(cx);
    push(di);
    ch = 0;
    al = 0xff;
    di = 0x6748;
    rep_stosb<MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    bx = 0x6748;
    al = memoryAGet(ds, 0xa948);
loc_191e5:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_191ee:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_191ee;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_191e5;
    al = memoryAGet(ds, 0xa948);
loc_191fe:
    push(bx);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, bx) & 1;
    memoryASet(ds, bx, memoryAGet(ds, bx) >> 1);
    bx++;
loc_19207:
    memoryASet(ds, bx, rcr(memoryAGet(ds, bx), 0x01));
    bx++;
    if (--cx)
        goto loc_19207;
    cx = pop();
    bx = pop();
    al--;
    if (al != 0)
        goto loc_191fe;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_19219:
    al = 0x08;
    ah = memoryAGet(ds, bx);
    bx++;
    out(dx, ax);
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_19219;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch == 0)
        goto loc_1923b;
    goto loc_191af;
loc_1923b:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_19244;
    goto loc_1939c;
loc_19244:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_1926e:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_1928f:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_19298:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_19298;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_1928f;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_192aa:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_192aa;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_1926e;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_192cc;
    goto loc_1939c;
loc_192cc:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_192dc:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_192fd:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_19306:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_19306;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_192fd;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_19318:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_19318;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_192dc;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_1933a;
    goto loc_1939c;
loc_1933a:
    si += memoryAGet16(es, 0x66f8);
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_19347:
    push(ds);
    push(es);
    push(cx);
    push(cx);
    push(di);
    ch = 0;
    di = 0x6706;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    di = pop();
    cx = pop();
    push(si);
    push(es);
    ds = pop();
    ax = 0xa000;
    es = ax;
    si = 0x6706;
    al = memoryAGet(ds, 0xa948);
loc_19368:
    push(si);
    push(cx);
    ch = 0;
    flags.carry = memoryAGet(ds, si) & 1;
    memoryASet(ds, si, memoryAGet(ds, si) >> 1);
    si++;
loc_19371:
    memoryASet(ds, si, rcr(memoryAGet(ds, si), 0x01));
    si++;
    if (--cx)
        goto loc_19371;
    cx = pop();
    si = pop();
    al--;
    if (al != 0)
        goto loc_19368;
    ch = 0;
    cl++;
    flags.interrupts = false;
loc_19383:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_19383;
    flags.interrupts = true;
    si = pop();
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    cx = pop();
    es = pop();
    ds = pop();
    ch--;
    if (ch != 0)
        goto loc_19347;
loc_1939c:
    ds = pop();
    cs = pop();
    return;
loc_1939e:
    if (bp & 0x0002)
        goto loc_193a7;
    goto loc_19810;
loc_193a7:
    ax = bp;
    push(bp);
    bp = memoryAGet16(ds, 0x66fc);
    if (!(ax & 0x0080))
        goto loc_193cd;
    ax = memoryAGet16(ds, 0x66f8);
    ax -= memoryAGet16(ds, 0x66fe);
    ax -= memoryAGet16(ds, 0x66fe);
    bx += ax;
    si += ax;
    ax = memoryAGet16(ds, 0x66fa);
    bx -= ax;
    si -= ax;
    bp -= ax;
    bp -= ax;
loc_193cd:
    memoryASet16(ds, 0x6702, bp);
    bp = pop();
    if (!(bp & 0x4000))
        goto loc_193db;
    goto loc_1969c;
loc_193db:
    if (!(bp & 0x8000))
        goto loc_193e4;
    goto loc_1953e;
loc_193e4:
    if (!(bp & 0x0020))
        goto loc_193ed;
    goto loc_19737;
loc_193ed:
    if (!(bp & 0x0040))
        goto loc_193f6;
    goto loc_197a4;
loc_193f6:
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_19436:
    push(cx);
    ch = 0;
loc_19439:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_19439;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    bx += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_19465;
    goto loc_19436;
loc_19465:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_1946e;
    goto loc_1953c;
loc_1946e:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_1949e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_194a2:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_194a2;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1949e;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_194c8;
    goto loc_1953c;
loc_194c8:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_194de:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_194e2:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_194e2;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_194de;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_19508;
    goto loc_1953c;
loc_19508:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_1951b:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_1951f:
    al = memoryAGet(es, di);
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_1951f;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1951b;
loc_1953c:
    ds = pop();
    cs = pop();
    return;
loc_1953e:
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0102;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x1003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_1958e:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_19592:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_19592;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_195b9;
    goto loc_1958e;
loc_195b9:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_195c2;
    goto loc_1969a;
loc_195c2:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    push(dx);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    push(di);
    push(si);
    push(cx);
loc_195dc:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_195e0:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_195e0;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_195dc;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_1960e;
    goto loc_1969a;
loc_1960e:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    push(dx);
    dl = 0xc4;
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
    push(di);
    push(si);
    push(cx);
loc_19628:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_1962c:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_1962c;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_19628;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_1965a;
    goto loc_1969a;
loc_1965a:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    push(dx);
    dl = 0xc4;
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = pop();
loc_19671:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_19675:
    ah = memoryAGet(es, di);
    ah = ~ah;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_19675;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    ax = memoryAGet16(ds, 0x6702);
    si += ax;
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_19671;
loc_1969a:
    ds = pop();
    cs = pop();
    return;
loc_1969c:
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0400;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0x0805;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0802;
    memoryASet16(ss, 0x0004, ax);
    out(dx, ax);
    ax = 0x0807;
    memoryASet16(ss, 0x0006, ax);
    out(dx, ax);
    ax = 0x0804;
    memoryASet16(ss, 0x0010, ax);
    out(dx, ax);
    push(cx);
    push(si);
    push(di);
    push(bx);
loc_196f6:
    push(cx);
    flags.interrupts = false;
    push(dx);
    al = 0x05;
    out(dx, al);
    dx++;
    in(al, dx);
    if (al == 0x08)
        goto loc_19703;
loc_19703:
    dx = pop();
    ch = 0;
loc_19706:
    ah = memoryAGet(es, di);
    ah &= memoryAGet(ds, bx);
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    movsb<MemAuto, MemAuto, DirAuto>();
    bx++;
    if (--cx)
        goto loc_19706;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    bx += memoryAGet16(ds, 0x6702);
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_196f6;
    bx = pop();
    di = pop();
    si = pop();
    cx = pop();
    ds = pop();
    cs = pop();
    return;
loc_19737:
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0f00;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = bp;
    ah &= 0x0f;
    al = 0x01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    si = bx;
loc_19775:
    push(cx);
    ch = 0;
loc_19778:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = 0xff;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_19778;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_197a2;
    goto loc_19775;
loc_197a2:
    ds = pop();
    cs = pop();
    return;
loc_197a4:
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = bp;
    ah &= 0x0f;
    al = 0x01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    si = bx;
loc_197e1:
    push(cx);
    ch = 0;
loc_197e4:
    ah = memoryAGet(ds, bx);
    bx++;
    al = 0x08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    flags.interrupts = false;
    al = memoryAGet(es, di);
    al = 0xff;
    stosb<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_197e4;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    bx += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_1980e;
    goto loc_197e1;
loc_1980e:
    ds = pop();
    cs = pop();
    return;
loc_19810:
    ax = bp;
    push(bp);
    bp = memoryAGet16(ds, 0x66fc);
    if (!(ax & 0x0080))
        goto loc_19836;
    ax = memoryAGet16(ds, 0x66f8);
    ax -= memoryAGet16(ds, 0x66fe);
    ax -= memoryAGet16(ds, 0x66fe);
    bx += ax;
    si += ax;
    ax = memoryAGet16(ds, 0x66fa);
    bx -= ax;
    si -= ax;
    bp -= ax;
    bp -= ax;
loc_19836:
    memoryASet16(ds, 0x6702, bp);
    bp = pop();
    push(ds);
    ds = memoryAGet16(ds, 0x1fe4);
    ax = 0xa000;
    es = ax;
    tl = dl;
    dl = dh;
    dh = tl;
    dh = 0;
    bp = dx;
    dx = 0x03c4;
    ax = 0x0f02;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    dx = 0x03ce;
    ax = 0;
    memoryASet16(ss, 0x000a, ax);
    out(dx, ax);
    ax = 0x0e01;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    ax = 0x0005;
    memoryASet16(ss, 0x0000, ax);
    out(dx, ax);
    ax = 0x0003;
    memoryASet16(ss, 0x0002, ax);
    out(dx, ax);
    ax = 0xff08;
    memoryASet16(ss, 0x000e, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_19883:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_19887:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_19887;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch == 0)
        goto loc_198a4;
    goto loc_19883;
loc_198a4:
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_198ad;
    goto loc_19965;
loc_198ad:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0001;
    memoryASet16(ss, 0x000c, ax);
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0202;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_198cd:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_198d1:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_198d1;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_198cd;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_198f5;
    goto loc_19965;
loc_198f5:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0402;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
    push(di);
    push(si);
    push(cx);
loc_1990b:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_1990f:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_1990f;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_1990b;
    cx = pop();
    si = pop();
    di = pop();
    bp--;
    if (bp != 0)
        goto loc_19933;
    goto loc_19965;
loc_19933:
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x66f8);
    ds = pop();
    ax = 0x0802;
    memoryASet16(ss, 0x0008, ax);
    out(dx, ax);
loc_19946:
    push(cx);
    ch = 0;
    flags.interrupts = false;
loc_1994a:
    al = memoryAGet(es, di);
    movsb<MemAuto, MemAuto, DirAuto>();
    if (--cx)
        goto loc_1994a;
    flags.interrupts = true;
    push(ds);
    ax = 0x19a9;
    ds = ax;
    si += memoryAGet16(ds, 0x6702);
    di += memoryAGet16(ds, 0x6704);
    ds = pop();
    cx = pop();
    ch--;
    if (ch != 0)
        goto loc_19946;
loc_19965:
    ds = pop();
    cs = pop();
}
void sub_19967()
{
    push(bp);
    memoryASet(ds, 0xa949, ch);
    ch = 0;
    if (!(bp & 0x0004))
        goto loc_199b4;
    bp = ax;
    if ((short)bp >= 0)
        goto loc_19997;
    bp += dx;
    if ((short)bp >= 0)
        goto loc_19981;
    goto loc_19a0c;
loc_19981:
    si += 0x0001;
    di += 0x0001;
    memoryASet16(ds, 0x66fc, memoryAGet16(ds, 0x66fc) + 0x0001);
    dx -= 0x0008;
    ax += 0x0008;
    if ((short)ax < 0)
        goto loc_19981;
    goto loc_199b4;
loc_19997:
    if ((short)ax >= (short)memoryAGet16(ds, 0x66f2))
        goto loc_19a0c;
    bp = ax;
    bp += dx;
loc_199a1:
    if ((short)bp < (short)memoryAGet16(ds, 0x66f2))
        goto loc_199b4;
    memoryASet16(ds, 0x66fc, memoryAGet16(ds, 0x66fc) + 0x0001);
    dx -= 0x0008;
    bp -= 0x0008;
    goto loc_199a1;
loc_199b4:
    bp = pop();
    push(bp);
    if (!(bp & 0x0008))
        goto loc_199e2;
    bp = bx;
    if ((short)bp >= 0)
        goto loc_199e8;
    bp += cx;
    if ((short)bp < 0)
        goto loc_19a0c;
    cx += bx;
    bx = -bx;
    bp = memoryAGet16(ds, 0x66fa);
    push(ax);
    push(dx);
    ax = bx;
    mul(bp);
    bp = ax;
    dx = pop();
    ax = pop();
    si += bp;
    di += bp;
    memoryASet16(ds, 0x66fe, bp);
    bx = 0;
loc_199e2:
    ch = memoryAGet(ds, 0xa949);
    bp = pop();
    return;
loc_199e8:
    if ((short)bx >= (short)memoryAGet16(ds, 0x66f0))
        goto loc_19a0c;
    bp = bx;
    bp += cx;
    if ((short)bp < (short)memoryAGet16(ds, 0x66f0))
        goto loc_199fe;
    cx = memoryAGet16(ds, 0x66f0);
    cx -= bx;
loc_199fe:
    if (dx == 0)
        goto loc_19a0c;
    if (cx == 0)
        goto loc_19a0c;
    ch = memoryAGet(ds, 0xa949);
    bp = pop();
    return;
loc_19a0c:
    ax = 0xffff;
    ch = memoryAGet(ds, 0xa949);
    bp = pop();
}
void sub_19a15()
{
    push(si);
    push(di);
    push(bp);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    ax -= 0x0010;
    if ((short)ax >= 0)
        goto loc_19a23;
    ax = 0;
loc_19a23:
    si = memoryAGet16(ds, 0x0026);
    bp = si;
    bp += 0x0321;
    si++;
    if (!(ax & 0x0007))
        goto loc_19a36;
    dx += 0x0008;
loc_19a36:
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    si += ax;
    if (!(bx & 0x0007))
        goto loc_19a47;
    cl += 0x08;
loc_19a47:
    bx &= 0xfff8;
    si += bx;
    bx <<= 1;
    bx <<= 1;
    si += bx;
    if (!(cl & 0x07))
        goto loc_19a5a;
    cl += 0x08;
loc_19a5a:
    ch = 0;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    if (!(dx & 0x0007))
        goto loc_19a6b;
    dx += 0x0008;
loc_19a6b:
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    al = 0x01;
loc_19a73:
    push(dx);
    push(si);
loc_19a75:
    memoryASet(ss, si, al);
    si++;
    dx--;
    if (dx != 0)
        goto loc_19a75;
    si = pop();
    dx = pop();
    si += 0x0028;
    if (si >= bp)
        goto loc_19a87;
    if (--cx)
        goto loc_19a73;
loc_19a87:
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    bp = pop();
    di = pop();
    si = pop();
}
