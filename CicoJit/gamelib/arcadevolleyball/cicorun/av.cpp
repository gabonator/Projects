#include "cicoemu.h"
using namespace CicoContext;

class CStackGuard
{
    uint16_t minit;
    bool uses;
public:
    CStackGuard(int ofs, bool use):minit(sp+ofs),uses(use) { if (!uses) push(0xabcd);}
    ~CStackGuard() {
        if (!uses)
            assert(pop() == 0xabcd);
        assert(minit == sp);
    }
};

class CStackGuardFar
{
    uint16_t minit;
public:
    CStackGuardFar(int ofs, bool use):minit(sp+ofs) {}
    ~CStackGuardFar() { assert(minit == sp-2); }
};

void sub_1ed0();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x0b0f;
    sp = 0x0080;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/arcadevolleyball/dos", "av.exe", 37382);
    sub_1ed0();
}
void sub_1ed0();
void sub_1fe5();
void sub_2025();
void sub_2041();
void sub_204d();
void sub_2055();
void sub_2075();
void sub_21d0();
void sub_2215();
void sub_22ea();
void sub_230a();
void sub_250f();
void sub_25f4();
void sub_2649();
void sub_2835();
void sub_287f();
void sub_2abe();
void sub_2c20();
void sub_2cb9();
void sub_2d4a();
void sub_2ed6();
void sub_2ff1();
void sub_329a();
void sub_3322();
void sub_353f();
void sub_3617();
void sub_386b();
void sub_38c4();
void sub_3bba();
void sub_3ed8();
void sub_418f();
void sub_41a0();
void sub_421e();
void sub_42b2();
void sub_43e0();
void sub_43e0_jump();
void sub_43f0();
void sub_43f5();
void sub_4430();
void sub_444c();
void sub_4452();
void sub_4464();
void sub_446a();
void sub_4479();
void sub_447f();
void sub_449d();
void sub_44be();
void sub_44c3();
void sub_44dd();
void sub_45b7();
void sub_4611();
void sub_4622();
void sub_4628();
void sub_4666();
void sub_4677();
void sub_467f();
void sub_4693();
void sub_46a2();
void sub_46f2();
void sub_473c();
void sub_4778();
void sub_47b2();
void sub_4862();
void sub_4918();
void sub_4928();
void sub_4a42();
void sub_4a8b();
void sub_4b1c();
void sub_4bd1();
void sub_4bde();
void sub_4cba();
void sub_4d0d();
void sub_4d35();
void sub_4d37();
void sub_4e2a();
void sub_4e62();
void sub_4ec3();
void sub_4eec();
void sub_4f1a();
void sub_4fb2();
void sub_5263();
void sub_5331();
void sub_538c();
void sub_53bc();
void sub_53d5();
void sub_5635();
void sub_5650();
void sub_565b();
void sub_566e();
void sub_5684();
void sub_570e();
void sub_572d();
void sub_5782();
void sub_57a1();
void sub_583e();
void sub_586a();
void sub_5891();
void sub_58ae();
void sub_5909();
void sub_5923();
void sub_5953();
void sub_5975();
void sub_59d3();
void sub_5a25();
void sub_5af1();
void sub_5b0b();
void sub_5b1f();
void sub_5b3f();
void sub_5b71();
void sub_5b8d();
void sub_5baf();
void sub_5d06();
void sub_5d1c();
void sub_5d42();
void sub_5d53();
void sub_5d62();
void sub_5d7f();
void sub_5e4a();
void sub_5ea5();
void sub_5eff();
void sub_5f2e();
void sub_5fd4();
void sub_600c();
void sub_601c();
void sub_602d();
void sub_6039();
void sub_6045();
void sub_6053();
void sub_60a3();
void sub_60dc();
void sub_6100();
void sub_6125();
void sub_61c2();
void sub_61fb();
void sub_620d();
void sub_628c();
void sub_6309();
void sub_636f();
void sub_6388();
void sub_6424();
void sub_64c4();
void sub_651e();
void sub_653c();
void sub_6568();
void sub_658a();
void sub_66f2();
void sub_672f();
void sub_6762();
void sub_6828();
void sub_6863();
void sub_68ab();
void sub_68c6();
void sub_694f();
void sub_69b1();
void sub_69fb();
void sub_6a27();
void sub_6a2e();
void sub_6f15();
void sub_6f38();
void sub_6fb0();
void sub_7010();
void sub_702f();
void sub_704a();
void sub_7078();
void sub_7088();
void sub_7091();
void sub_70d8();
void sub_726d();
void sub_7285();
void sub_72a8();
void sub_72d9();
void sub_7311();
void sub_734d();
void sub_73e3();
void sub_753d();
void sub_75cb();
void sub_7649();
void sub_76cd();
void sub_7714();
void sub_7813();
void sub_78c2();
void sub_7972();
void sub_7b86();
void sub_7bb3();
void sub_7c50();
void sub_7c68();
void sub_7d6e();
void sub_7e5b();
void sub_7e9a();
void sub_7f05();
void sub_7f5c();
void sub_7fae();
void sub_7ff9();
void sub_8067();
void sub_81ca();
void sub_81f4();
void sub_82c4();
void sub_830d();
void sub_834d();
void sub_853c();
void sub_858c();
void sub_858f();
void sub_85c1();
void sub_85f1();
void sub_8651();
void sub_86d9();
void sub_870c();
void sub_8729();
void sub_877b();
void sub_87ee();
void sub_8810();
void sub_8835();
void sub_884c();
void sub_8886();
void sub_88e9();
void sub_894b();
void sub_89d4();
void sub_89f5();
void sub_8a74();
void sub_8ae2();
void sub_8b12();
void sub_8b48();
void sub_8b8e();
void sub_8bb4();
void sub_8c43();
void sub_8cc7();
void sub_8cfd();
void sub_8d64();
void sub_8d82();
void sub_8dab();
void sub_8dba();
void sub_8ddb();
void sub_8dde();
void sub_8e10();
void sub_8e60();
void sub_8ed9();
void sub_8eda();
void sub_8edf();
void sub_8f20();
void sub_8f2c();
void sub_8f3c();
void sub_8f4c();
void sub_8f68();
void sub_8f74();
void sub_8f7d();
void sub_8f86();
void sub_8f8f();
void sub_8fa0();
void sub_8fa9();
void sub_8fb6();
void sub_9005();
void sub_9014();
void sub_901a();
void sub_9028();
void sub_9032();
void sub_9082();
void sub_90c8();
void sub_90d3();
void sub_90e2();
void sub_90f6();
void sub_9112();
void sub_922d();
void sub_9234();
void sub_9278();
void sub_9295();
void sub_9dbc();
void sub_9e07();
void sub_9eff();
void sub_9f2b();
void sub_9f40();
void sub_9f51();
void sub_9f62();
void sub_9fa0();
void sub_9fae();
void sub_9fd7();
void sub_9fea();
void sub_a01d();
void sub_a081();
void sub_a09a();
void sub_a0cc();
void sub_a0fd();
void sub_a123();
void sub_a189();
void sub_a210();
void sub_a225();
void sub_a231();
void sub_a273();
void sub_a301();
void sub_a42f();
void sub_a446();
void sub_a465();
void sub_a4b8();
void sub_a4c4();
void sub_a4f3();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x1ed017d: sub_204d(); return;
        case 0x43e0000: sub_43e0(); return;
        case 0x43e0482: sub_4862(); return;
        case 0x43e0538: sub_4918(); return;
        case 0x43e0548: sub_4928(); return;
        case 0x43e07f1: sub_4bd1(); return;
        case 0x1ed3e92: sub_5d62(); return;
        case 0x8e60000: sub_8e60(); return;
        case 0x0a57ff9a:
            ctx->_cs = pop(); // retf
            ctx->a.r16 = 0xffff;
            ctx->b.r16 = 3;
            return; //0A57:0000FF9A int 33
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_5635()!
// INJECT: Error: cannot inject carry flag in sub_5635()!
// INJECT: Error: cannot inject carry flag in sub_5650()!
// INJECT: Error: cannot inject carry flag in sub_5650()!
// INJECT: Error: cannot inject flag in sub_694f() because of being label!
// INJECT: Error: cannot inject flag in sub_8dab() because of being label!
// INJECT: Error: cannot inject zero flag in sub_8ddb() because no traceback!
// INJECT: Error: cannot inject carry flag in sub_9dbc()!
// INJECT: Error: cannot inject flag in sub_9f62() because of being label!
// INJECT: Error: cannot inject carry flag in sub_a42f()!
// INJECT: Error: cannot inject flag in sub_a446() because of being label!
// INJECT: Error: cannot inject carry flag in sub_5635()!
// INJECT: Error: cannot inject carry flag in sub_5635()!
// INJECT: Error: cannot inject carry flag in sub_5650()!
// INJECT: Error: cannot inject carry flag in sub_5650()!
// INJECT: Error: cannot inject flag in sub_694f() because of being label!
// INJECT: Error: cannot inject flag in sub_8dab() because of being label!
// INJECT: Error: cannot inject zero flag in sub_8ddb() because no traceback!
// INJECT: Error: cannot inject carry flag in sub_9dbc()!
// INJECT: Error: cannot inject flag in sub_9f62() because of being label!
// INJECT: Error: cannot inject carry flag in sub_a42f()!
// INJECT: Error: cannot inject flag in sub_a446() because of being label!
void sub_1ed0() // 01ed:0000
{
    CStackGuard sg(0, true);
    push(0x7777);
    flags.interrupts = true;
    dx = 0x0a57;
    memoryASet16(cs, 0x01a3, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryAGet16(ds, 0x0002);
    bx = memoryAGet16(ds, 0x002c);
    ds = dx;
    memoryASet16(ds, 0x0086, ax);
    memoryASet16(ds, 0x0084, es);
    memoryASet16(ds, 0x0080, bx);
    memoryASet16(ds, 0x009c, bp);
    memoryASet16(ds, 0x008a, 0xffff);
    sub_2025();
    di = memoryAGet16(ds, 0x007e);
    es = memoryAGet16(ds, 0x007e + 2);
    ax = di;
    bx = ax;
    cx = 0x7fff;
loc_1f0a: // 01ed:003a
    if (memoryAGet16(es, di) != 0x3738)
        goto loc_1f2a;
    dx = memoryAGet16(es, di + 2);
    if (dl != 0x3d)
        goto loc_1f2a;
    dh &= 0xdf;
    memoryASet16(ds, 0x008a, memoryAGet16(ds, 0x008a) + 1);
    if (dh != 0x59)
        goto loc_1f2a;
    memoryASet16(ds, 0x008a, memoryAGet16(ds, 0x008a) + 1);
loc_1f2a: // 01ed:005a
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_1f95;
    bx++;
    if (memoryAGet(es, di) != al)
        goto loc_1f0a;
    ch |= 0x80;
    cx = -cx;
    memoryASet16(ds, 0x007e, cx);
    cx = 0x0001;
    bx <<= cl;
    bx += 0x0008;
    bx &= 0xfff8;
    memoryASet16(ds, 0x0082, bx);
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x0958)); // 01ed:007e
    dx = ds;
    bp -= dx;
    di = memoryAGet16(ds, 0x047e);
    if (di >= 0x0100)
        goto loc_1f67;
    di = 0x0100;
    memoryASet16(ds, 0x047e, di);
loc_1f67: // 01ed:0097
    flags.carry = (di + 0x0b75) >= 0x10000;
    di += 0x0b75;
    if (flags.carry)
        goto loc_1f95;
    flags.carry = (di + memoryAGet16(ds, 0x041a)) >= 0x10000;
    di += memoryAGet16(ds, 0x041a);
    if (flags.carry)
        goto loc_1f95;
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp < di)
        goto loc_1f95;
    if (memoryAGet16(ds, 0x047e) == 0x0000)
        goto loc_1f8a;
    if (memoryAGet16(ds, 0x041a) != 0x0000)
        goto loc_1f98;
loc_1f8a: // 01ed:00ba
    di = 0x1000;
    if (bp > di)
        goto loc_1f98;
    di = bp;
    goto loc_1f98;
loc_1f95: // 01ed:00c5
    goto loc_205d;
loc_1f98: // 01ed:00c8
    bx = di;
    bx += dx;
    memoryASet16(ds, 0x0094, bx);
    memoryASet16(ds, 0x0098, bx);
    ax = memoryAGet16(ds, 0x0084);
    bx -= ax;
    es = ax;
    ah = 0x4a;
    push(di);
    interrupt(0x21);
    di = pop();
    di <<= cl;
    di &= 0xffff;
    ss = dx;
    sp = di;
    sub_68c6();
    sub_69b1();
    ax = 0;
    es = memoryAGet16(cs, 0x01a3);
    di = 0x0966;
    cx = 0x0b75;
    cx -= di;
    rep_stosb<MemAuto, DirAuto>();
    callIndirect(cs, memoryAGet16(ds, 0x095c)); // 01ed:00fe
    push(memoryAGet16(ds, 0x007c));
    push(memoryAGet16(ds, 0x007a));
    push(memoryAGet16(ds, 0x0078));
    sub_2075();
    push(ax);
    sub_5eff();
    ds = memoryAGet16(cs, 0x01a3);
    sub_2041();
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x095a)); // 01ed:011e
    ax = 0;
    si = ax;
    cx = 0x002f;
    flags.direction = false;
loc_1ffb: // 01ed:012b
    flags.carry = (al + memoryAGet(ds, si)) >= 0x100;
    al += memoryAGet(ds, si);
    ah += flags.carry;
    si++;
    if (--cx)
        goto loc_1ffb;
    ax -= 0x0d36;
    if (ax == 0)
        goto loc_2013;
    cx = 0x0019;
    dx = 0x002f;
    sub_2055();
loc_2013: // 01ed:0143
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x0048;
    goto loc_2064;
    //   gap of 56 bytes
loc_205d: // 01ed:018d
    cx = 0x001e;
    dx = 0x0056;
loc_2064: // 01ed:0194
    ds = memoryAGet16(cs, 0x01a3);
    sub_2055();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0003);
    ax = 0x2470;
    push(ax);
    sub_60dc();
    sp++;
    sp++;
    if ((short)ax >= 0)
        goto loc_209d;
    ax = 0x0001;
    push(ax);
    sub_5eff();
    sp++;
    sp++;
loc_209d: // 01ed:01cd
    push(ds);
    ax = 0x02b2;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7972();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(cs);
    cs = 0x01ed;
    sub_726d();
    assert(cs == 0x01ed);
    if ((short)ax >= 0)
        goto loc_20c9;
    ax = 0x02b3;
    push(ax);
    sub_5d06();
    sp++;
    sp++;
    goto loc_21ca;
loc_20c9: // 01ed:01f9
    sub_230a();
    if (ax)
        goto loc_20d3;
    goto loc_21c5;
loc_20d3: // 01ed:0203
    ax = 0;
    memoryASet16(ds, 0x024e, ax);
    memoryASet16(ds, 0x09d8, ax);
    sub_21d0();
    if (ax)
        goto loc_2124;
    di = 0x0001;
    goto loc_211f;
loc_20e7: // 01ed:0217
    si = 0;
    goto loc_210c;
loc_20eb: // 01ed:021b
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_210c: // 01ed:023c
    if ((short)si < (short)0x000e)
        goto loc_20eb;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_211f: // 01ed:024f
    if ((short)di < (short)0x0003)
        goto loc_20e7;
loc_2124: // 01ed:0254
    sub_5af1();
    if (!(ax & 0x0001))
        goto loc_2133;
    sub_25f4();
    if (ax)
        goto loc_2195;
loc_2133: // 01ed:0263
    di = 0x0001;
    goto loc_2190;
loc_2138: // 01ed:0268
    si = 0;
    goto loc_217d;
loc_213c: // 01ed:026c
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 202);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 188, al);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_217d: // 01ed:02ad
    if ((short)si < (short)0x000e)
        goto loc_213c;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_2190: // 01ed:02c0
    if ((short)di < (short)0x0003)
        goto loc_2138;
loc_2195: // 01ed:02c5
    sub_2abe();
    memoryASet16(ds, 0x098c, 0x0040);
    memoryASet16(ds, 0x098e, 0x00e2);
    memoryASet16(ds, 0x09e4, 0x00ad);
    memoryASet16(ds, 0x09e6, 0x00ad);
loc_21b0: // 01ed:02e0
    sub_287f();
    if (!ax)
        goto loc_21c5;
    sub_3ed8();
    ax = memoryAGet16(ds, 0x09d8);
    ax ^= 0x0001;
    memoryASet16(ds, 0x09d8, ax);
    goto loc_21b0;
loc_21c5: // 01ed:02f5
    push(cs);
    cs = 0x01ed;
    sub_7bb3();
    assert(cs == 0x01ed);
loc_21ca: // 01ed:02fa
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_1fe5() // 01ed:0115
{
    CStackGuard sg(0, true);
    push(0x7777);
    ds = memoryAGet16(cs, 0x01a3);
    sub_2041();
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x095a)); // 01ed:011e
    ax = 0;
    si = ax;
    cx = 0x002f;
    flags.direction = false;
loc_1ffb: // 01ed:012b
    flags.carry = (al + memoryAGet(ds, si)) >= 0x100;
    al += memoryAGet(ds, si);
    ah += flags.carry;
    si++;
    if (--cx)
        goto loc_1ffb;
    ax -= 0x0d36;
    if (ax == 0)
        goto loc_2013;
    cx = 0x0019;
    dx = 0x002f;
    sub_2055();
loc_2013: // 01ed:0143
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x0048;
    goto loc_2064;
    //   gap of 63 bytes
loc_2064: // 01ed:0194
    ds = memoryAGet16(cs, 0x01a3);
    sub_2055();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0003);
    ax = 0x2470;
    push(ax);
    sub_60dc();
    sp++;
    sp++;
    if ((short)ax >= 0)
        goto loc_209d;
    ax = 0x0001;
    push(ax);
    sub_5eff();
    sp++;
    sp++;
loc_209d: // 01ed:01cd
    push(ds);
    ax = 0x02b2;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7972();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(cs);
    cs = 0x01ed;
    sub_726d();
    assert(cs == 0x01ed);
    if ((short)ax >= 0)
        goto loc_20c9;
    ax = 0x02b3;
    push(ax);
    sub_5d06();
    sp++;
    sp++;
    goto loc_21ca;
loc_20c9: // 01ed:01f9
    sub_230a();
    if (ax)
        goto loc_20d3;
    goto loc_21c5;
loc_20d3: // 01ed:0203
    ax = 0;
    memoryASet16(ds, 0x024e, ax);
    memoryASet16(ds, 0x09d8, ax);
    sub_21d0();
    if (ax)
        goto loc_2124;
    di = 0x0001;
    goto loc_211f;
loc_20e7: // 01ed:0217
    si = 0;
    goto loc_210c;
loc_20eb: // 01ed:021b
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_210c: // 01ed:023c
    if ((short)si < (short)0x000e)
        goto loc_20eb;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_211f: // 01ed:024f
    if ((short)di < (short)0x0003)
        goto loc_20e7;
loc_2124: // 01ed:0254
    sub_5af1();
    if (!(ax & 0x0001))
        goto loc_2133;
    sub_25f4();
    if (ax)
        goto loc_2195;
loc_2133: // 01ed:0263
    di = 0x0001;
    goto loc_2190;
loc_2138: // 01ed:0268
    si = 0;
    goto loc_217d;
loc_213c: // 01ed:026c
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 202);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 188, al);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_217d: // 01ed:02ad
    if ((short)si < (short)0x000e)
        goto loc_213c;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_2190: // 01ed:02c0
    if ((short)di < (short)0x0003)
        goto loc_2138;
loc_2195: // 01ed:02c5
    sub_2abe();
    memoryASet16(ds, 0x098c, 0x0040);
    memoryASet16(ds, 0x098e, 0x00e2);
    memoryASet16(ds, 0x09e4, 0x00ad);
    memoryASet16(ds, 0x09e6, 0x00ad);
loc_21b0: // 01ed:02e0
    sub_287f();
    if (!ax)
        goto loc_21c5;
    sub_3ed8();
    ax = memoryAGet16(ds, 0x09d8);
    ax ^= 0x0001;
    memoryASet16(ds, 0x09d8, ax);
    goto loc_21b0;
loc_21c5: // 01ed:02f5
    push(cs);
    cs = 0x01ed;
    sub_7bb3();
    assert(cs == 0x01ed);
loc_21ca: // 01ed:02fa
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2025() // 01ed:0155
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x0074, bx);
    memoryASet16(ds, 0x0076, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x014c;
    interrupt(0x21);
    ds = pop();
}
void sub_2041() // 01ed:0171
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x2500;
    dx = memoryAGet16(ds, 0x0074);
    ds = memoryAGet16(ds, 0x0074 + 2);
    interrupt(0x21);
    ds = pop();
}
void sub_204d() // 01ed:017d
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0x008a, 0x0000);
    cs = pop();
}
void sub_2055() // 01ed:0185
{
    CStackGuard sg(0, false);
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_2075() // 01ed:01a5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0003);
    ax = 0x2470;
    push(ax);
    sub_60dc();
    sp++;
    sp++;
    if ((short)ax >= 0)
        goto loc_209d;
    ax = 0x0001;
    push(ax);
    sub_5eff();
    sp++;
    sp++;
loc_209d: // 01ed:01cd
    push(ds);
    ax = 0x02b2;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7972();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(cs);
    cs = 0x01ed;
    sub_726d();
    assert(cs == 0x01ed);
    if ((short)ax >= 0)
        goto loc_20c9;
    ax = 0x02b3;
    push(ax);
    sub_5d06();
    sp++;
    sp++;
    goto loc_21ca;
loc_20c9: // 01ed:01f9
    sub_230a();
    if (ax)
        goto loc_20d3;
    goto loc_21c5;
loc_20d3: // 01ed:0203
    ax = 0;
    memoryASet16(ds, 0x024e, ax);
    memoryASet16(ds, 0x09d8, ax);
    sub_21d0();
    if (ax)
        goto loc_2124;
    di = 0x0001;
    goto loc_211f;
loc_20e7: // 01ed:0217
    si = 0;
    goto loc_210c;
loc_20eb: // 01ed:021b
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_210c: // 01ed:023c
    if ((short)si < (short)0x000e)
        goto loc_20eb;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_211f: // 01ed:024f
    if ((short)di < (short)0x0003)
        goto loc_20e7;
loc_2124: // 01ed:0254
    sub_5af1();
    if (!(ax & 0x0001))
        goto loc_2133;
    sub_25f4();
    if (ax)
        goto loc_2195;
loc_2133: // 01ed:0263
    di = 0x0001;
    goto loc_2190;
loc_2138: // 01ed:0268
    si = 0;
    goto loc_217d;
loc_213c: // 01ed:026c
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 202);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 188, al);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_217d: // 01ed:02ad
    if ((short)si < (short)0x000e)
        goto loc_213c;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_2190: // 01ed:02c0
    if ((short)di < (short)0x0003)
        goto loc_2138;
loc_2195: // 01ed:02c5
    sub_2abe();
    memoryASet16(ds, 0x098c, 0x0040);
    memoryASet16(ds, 0x098e, 0x00e2);
    memoryASet16(ds, 0x09e4, 0x00ad);
    memoryASet16(ds, 0x09e6, 0x00ad);
loc_21b0: // 01ed:02e0
    sub_287f();
    if (!ax)
        goto loc_21c5;
    sub_3ed8();
    ax = memoryAGet16(ds, 0x09d8);
    ax ^= 0x0001;
    memoryASet16(ds, 0x09d8, ax);
    goto loc_21b0;
loc_21c5: // 01ed:02f5
    push(cs);
    cs = 0x01ed;
    sub_7bb3();
    assert(cs == 0x01ed);
loc_21ca: // 01ed:02fa
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_21d0() // 01ed:0300
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0010;
    memoryASet16(ss, bp - 16, 0x0000);
    ax = bp - 0x10;
    push(ax);
    ax = bp - 0x10;
    push(ax);
    ax = 0x0033;
    push(ax);
    sub_6100();
    sp += 0x0006;
    if (memoryAGet16(ss, bp - 16) != 0x0000)
        goto loc_21f7;
    ax = 0;
    goto loc_2211;
loc_21f7: // 01ed:0327
    memoryASet16(ss, bp - 16, 0x0002);
    ax = bp - 0x10;
    push(ax);
    ax = bp - 0x10;
    push(ax);
    ax = 0x0033;
    push(ax);
    sub_6100();
    sp += 0x0006;
    ax = 0x0001;
loc_2211: // 01ed:0341
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2215() // 01ed:0345
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    bx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ds, bx);
    ax = memoryAGet16(ds, bx);
    ax += 0x0004;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ds, bx);
    ax = memoryAGet16(ds, bx + 2);
    ax++;
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_22db;
loc_2242: // 01ed:0372
    bx = memoryAGet16(ss, bp - 6);
    bx <<= 1;
    bx += memoryAGet16(ss, bp + 8);
    si = memoryAGet16(ds, bx);
    ax = memoryAGet16(ss, bp - 2);
    ax--;
    push(ax);
    push(memoryAGet16(ds, si));
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_81f4();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(ax);
    sub_6388();
    sp++;
    sp++;
    bx = memoryAGet16(ss, bp - 6);
    bx++;
    bx <<= 1;
    bx += memoryAGet16(ss, bp + 8);
    memoryASet16(ds, bx, ax);
    bx = memoryAGet16(ss, bp - 6);
    bx++;
    bx <<= 1;
    bx += memoryAGet16(ss, bp + 8);
    di = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_228b;
loc_2282: // 01ed:03b2
    al = memoryAGet(ds, si);
    memoryASet(ds, di, al);
    si++;
    di++;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_228b: // 01ed:03bb
    if ((short)memoryAGet16(ss, bp - 8) < (short)0x0004)
        goto loc_2282;
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_22d0;
loc_2298: // 01ed:03c8
    memoryASet16(ss, bp - 12, 0x0000);
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_22c5;
loc_22a4: // 01ed:03d4
    al = memoryAGet(ds, si);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    al += memoryAGet(ss, bp - 12);
    memoryASet(ds, di, al);
    di++;
    al = memoryAGet(ds, si);
    ah = 0x00;
    ax &= 0x0003;
    cx = 0x0006;
    ax <<= cl;
    memoryASet16(ss, bp - 12, ax);
    si++;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_22c5: // 01ed:03f5
    ax = memoryAGet16(ss, bp - 10);
    if ((short)ax < (short)memoryAGet16(ss, bp - 4))
        goto loc_22a4;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_22d0: // 01ed:0400
    ax = memoryAGet16(ss, bp - 8);
    if ((short)ax < (short)memoryAGet16(ss, bp - 2))
        goto loc_2298;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_22db: // 01ed:040b
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x0003)
        goto loc_22e4;
    goto loc_2242;
loc_22e4: // 01ed:0414
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_22ea() // 01ed:041a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    sub_6388();
    sp = bp;
    si = ax;
    push(memoryAGet16(ss, bp + 6));
    push(si);
    push(memoryAGet16(ds, 0x0a50));
    sub_651e();
    sp = bp;
    ax = si;
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_230a() // 01ed:043a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    ax = 0x0001;
    push(ax);
    ax = 0x02cb;
    push(ax);
    sub_64c4();
    sp += 0x0004;
    memoryASet16(ds, 0x0a50, ax);
    if (ax != 0xffff)
        goto loc_2333;
    push(ds);
    ax = 0x02d2;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_82c4();
    assert(cs == 0x01ed);
    sp += 0x0004;
    ax = 0;
    goto loc_250d;
loc_2333: // 01ed:0463
    ax = 0x0046;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09da, ax);
    ax = 0x0046;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a38, ax);
    ax = 0x001a;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09ba, ax);
    ax = 0x010a;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09ee, ax);
    ax = 0x010a;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09f6, ax);
    ax = 0x0132;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09fe, ax);
    ax = 0x0132;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a06, ax);
    ax = 0x010a;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0994, ax);
    ax = 0x010a;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x099c, ax);
    ax = 0x0132;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09a4, ax);
    ax = 0x0132;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09ac, ax);
    ax = 0x00ca;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x09b4, ax);
    ax = 0x0146;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a18, ax);
    ax = 0x0146;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a20, ax);
    ax = 0x0146;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a28, ax);
    ax = 0x0146;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a30, ax);
    ax = 0x00b6;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0966, ax);
    ax = 0x00b6;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x096e, ax);
    ax = 0x00b6;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x0976, ax);
    ax = 0x00b6;
    push(ax);
    sub_22ea();
    sp++;
    sp++;
    memoryASet16(ds, 0x097e, ax);
    push(memoryAGet16(ds, 0x0a50));
    sub_5b8d();
    sp++;
    sp++;
    si = 0;
    goto loc_2475;
loc_2430: // 01ed:0560
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0994;
    push(ax);
    sub_2215();
    sp++;
    sp++;
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x09ee;
    push(ax);
    sub_2215();
    sp++;
    sp++;
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0a18;
    push(ax);
    sub_2215();
    sp++;
    sp++;
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0966;
    push(ax);
    sub_2215();
    sp++;
    sp++;
    si++;
loc_2475: // 01ed:05a5
    if ((short)si < (short)0x0004)
        goto loc_2430;
    ax = 0x000f;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7f05();
    assert(cs == 0x01ed);
    sp += 0x0004;
    ax = 0x0007;
    push(ax);
    ax = 0x0070;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_81f4();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(ax);
    sub_6388();
    sp++;
    sp++;
    memoryASet16(ds, 0x09c2, ax);
    sub_418f();
    ax = 0x0007;
    push(ax);
    ax = 0x0070;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_88e9();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = memoryAGet16(ds, 0x09c2);
    dx = ds;
    push(dx);
    push(ax);
    ax = 0x0007;
    push(ax);
    ax = 0x0070;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8c43();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(memoryAGet16(ds, 0x09c2));
    ax = 0;
    push(ax);
    push(ax);
    sub_42b2();
    sp += 0x0006;
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7f05();
    assert(cs == 0x01ed);
    sp += 0x0004;
    ax = 0x0007;
    push(ax);
    ax = 0x0070;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_88e9();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0001;
loc_250d: // 01ed:063d
    si = pop();
    assert(pop() == 0x7777);
}
void sub_250f() // 01ed:063f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
loc_2511: // 01ed:0641
    sync();
    sub_61fb();
    if (!ax)
        goto loc_251b;
    goto loc_25ee;
loc_251b: // 01ed:064b
    memoryASet16(ds, 0x09e2, memoryAGet16(ds, 0x09e2) + 1);
    bx = memoryAGet16(ds, 0x09d6);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2536) != 0xffff)
        goto loc_2553;
    ax = memoryAGet16(ds, 0x09d6);
    dx = 0x0006;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 2508, 0x0000);
    ax = 0x0001;
    ax -= memoryAGet16(ds, 0x09d6);
    memoryASet16(ds, 0x09d6, ax);
    dx = 0x0006;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 2508, 0x0001);
loc_2553: // 01ed:0683
    sub_2d4a();
    si = memoryAGet16(ds, 0x098c);
    di = memoryAGet16(ds, 0x098e);
    sub_418f();
    bx = memoryAGet16(ds, 0x09be);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = si;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2452));
    push(memoryAGet16(ds, 0x09e4));
    push(si);
    sub_41a0();
    sp += 0x0006;
    bx = memoryAGet16(ds, 0x09c0);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = di;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2542));
    push(memoryAGet16(ds, 0x09e6));
    push(di);
    sub_41a0();
    sp += 0x0006;
    if ((short)si >= (short)0x0006)
        goto loc_25be;
    push(memoryAGet16(ds, 0x09da));
    ax = memoryAGet16(ds, 0x09e4);
    ax += 0xfffe;
    push(ax);
    ax = 0;
    push(ax);
    sub_41a0();
    sp += 0x0006;
loc_25be: // 01ed:06ee
    if ((short)di <= (short)0x0113)
        goto loc_25d9;
    push(memoryAGet16(ds, 0x0a38));
    ax = memoryAGet16(ds, 0x09e6);
    ax += 0xfffe;
    push(ax);
    ax = 0x0138;
    push(ax);
    sub_41a0();
    sp += 0x0006;
loc_25d9: // 01ed:0709
    push(memoryAGet16(ds, 0x09b4));
    ax = 0x0067;
    push(ax);
    ax = 0x009e;
    push(ax);
    sub_41a0();
    sp += 0x0006;
    goto loc_2511;
loc_25ee: // 01ed:071e
    sub_5fd4();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_25f4() // 01ed:0724
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    di = 0x0201;
    memoryASet16(ds, 0x0a42, 0x7d00);
    si = 0;
    al = 0x7f;
    dx = di;
    out(dx, al);
loc_2606: // 01ed:0736
    dx = di;
    in(al, dx);
    if (al & 0x01)
        goto loc_2617;
    if ((short)si >= (short)memoryAGet16(ds, 0x0a42))
        goto loc_2617;
    si++;
    goto loc_2606;
loc_2617: // 01ed:0747
    if ((short)si < 0)
        goto loc_2632;
    si = 0;
loc_261d: // 01ed:074d
    dx = di;
    in(al, dx);
    if (!(al & 0x01))
        goto loc_262e;
    if ((short)si >= (short)memoryAGet16(ds, 0x0a42))
        goto loc_262e;
    si++;
    goto loc_261d;
loc_262e: // 01ed:075e
    if ((short)si >= 0)
        goto loc_2636;
loc_2632: // 01ed:0762
    ax = 0;
    goto loc_2646;
loc_2636: // 01ed:0766
    memoryASet16(ds, 0x0a44, si);
    ax = si;
    ax = sar(ax, 1);
    ax += si;
    memoryASet16(ds, 0x0a42, ax);
    ax = 0x0001;
loc_2646: // 01ed:0776
    di = pop();
    si = pop();
}
void sub_2649() // 01ed:0779
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    memoryASet16(ss, bp - 6, 0x0068);
    memoryASet16(ss, bp - 4, 0x0070);
    di = 0x0028;
    si = 0;
    goto loc_267b;
loc_2662: // 01ed:0792
    push(memoryAGet16(ds, 0x09c2));
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    sub_42b2();
    sp += 0x0006;
    si++;
loc_267b: // 01ed:07ab
    if ((short)si < (short)0x0007)
        goto loc_2662;
    sub_418f();
    si = 0;
    goto loc_26c4;
loc_2687: // 01ed:07b7
    ax = si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 170);
    dx = 0x000e;
    mul(dx);
    push(ax);
    ax = si;
    dx = 0x003c;
    mul(dx);
    dx = ax;
    ax = pop();
    ax += dx;
    ax += 0x00ae;
    dx = ds;
    push(dx);
    push(ax);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    si++;
loc_26c4: // 01ed:07f4
    if ((short)si < (short)0x0007)
        goto loc_2687;
    push(memoryAGet16(ds, 0x09c2));
    push(di);
    push(memoryAGet16(ss, bp - 6));
    sub_421e();
    sp += 0x0006;
    si = 0;
    memoryASet(ss, bp - 1, 0x00);
loc_26dd: // 01ed:080d
    sub_250f();
    memoryASet(ss, bp - 1, al);
    if (al == 0x0d)
        goto loc_2752;
    sub_61fb();
    if (!ax)
        goto loc_26f5;
    sub_5fd4();
    memoryASet(ss, bp - 1, al);
loc_26f5: // 01ed:0825
    ax = 0x0fa0;
    push(ax);
    sub_69fb();
    sp++;
    sp++;
    sub_6a27();
    sub_418f();
    push(memoryAGet16(ds, 0x09c2));
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    sub_421e();
    sp += 0x0006;
    if (memoryAGet(ss, bp - 1) == 0x32)
        goto loc_2728;
    if (memoryAGet(ss, bp - 1) != 0x50)
        goto loc_2733;
loc_2728: // 01ed:0858
    si++;
    ax = si;
    bx = 0x0007;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    si = dx;
loc_2733: // 01ed:0863
    if (memoryAGet(ss, bp - 1) == 0x38)
        goto loc_2742;
    if (memoryAGet(ss, bp - 1) == 0x48)
        goto loc_2742;
    goto loc_27e9;
loc_2742: // 01ed:0872
    ax = si;
    ax += 0x0006;
    bx = 0x0007;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    si = dx;
    goto loc_27e9;
loc_2752: // 01ed:0882
    ax = si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    if ((short)memoryAGet16(ds, bx + 172) > (short)0x0000)
        goto loc_2765;
    goto loc_2804;
loc_2765: // 01ed:0895
    ax = si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 170, memoryAGet16(ds, bx + 170) + 1);
    ax = memoryAGet16(ds, bx + 170);
    push(ax);
    ax = si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = pop();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(memoryAGet16(ds, bx + 172));
    ax = si;
    bx = 0x003c;
    push(dx);
    mul(bx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 170, ax);
    push(memoryAGet16(ds, 0x09c2));
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    sub_42b2();
    sp += 0x0006;
    ax = si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 170);
    dx = 0x000e;
    mul(dx);
    push(ax);
    ax = si;
    dx = 0x003c;
    mul(dx);
    dx = ax;
    ax = pop();
    ax += dx;
    ax += 0x00ae;
    dx = ds;
    push(dx);
    push(ax);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
loc_27e9: // 01ed:0919
    push(memoryAGet16(ds, 0x09c2));
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    sub_421e();
    sp += 0x0006;
    goto loc_26dd;
loc_2804: // 01ed:0934
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_2827;
loc_280b: // 01ed:093b
    push(memoryAGet16(ds, 0x09c2));
    ax = memoryAGet16(ss, bp - 8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += di;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    sub_42b2();
    sp += 0x0006;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_2827: // 01ed:0957
    if ((short)memoryAGet16(ss, bp - 8) < (short)0x0007)
        goto loc_280b;
    ax = si;
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2835() // 01ed:0965
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ds);
    ax = 0x02b0;
    push(ax);
    cx = 0x0002;
    push(cs);
    cs = 0x01ed;
    sub_653c();
    assert(cs == 0x01ed);
    ax = 0;
    push(ax);
    sub_5b0b();
    sp++;
    sp++;
    si = ax;
    ax = si;
    al &= 0xff;
    memoryASet(ss, bp - 2, al);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    ax = 0x00c8;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = si;
    cx = 0x0008;
    ax = sar(ax, cl);
    sp = bp;
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_287f() // 01ed:09af
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    bx = memoryAGet16(ds, 0x09be);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x098c);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2452));
    push(memoryAGet16(ds, 0x09e4));
    push(memoryAGet16(ds, 0x098c));
    sub_42b2();
    sp += 0x0006;
    bx = memoryAGet16(ds, 0x09c0);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x098e);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2542));
    push(memoryAGet16(ds, 0x09e6));
    push(memoryAGet16(ds, 0x098e));
    sub_42b2();
    sp += 0x0006;
    ax = 0x00c7;
    push(ax);
    ax = 0x0138;
    push(ax);
    ax = 0x000b;
    push(ax);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7e9a();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(memoryAGet16(ds, 0x09b4));
    ax = 0x0067;
    push(ax);
    ax = 0x009e;
    push(ax);
    sub_41a0();
    sp += 0x0006;
    si = 0;
    goto loc_294b;
loc_2900: // 01ed:0a30
    ax = 0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, ax);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2504, ax);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2506, ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 2508, si);
    ax = si;
    ax--;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2536, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2532, 0x00ad);
    si++;
loc_294b: // 01ed:0a7b
    if ((short)si < (short)0x0002)
        goto loc_2900;
    memoryASet16(ds, 0x09d6, 0x0001);
loc_2956: // 01ed:0a86
    sub_2649();
    memoryASet16(ss, bp - 2, ax);
    if (ax == 0x0004)
        goto loc_2964;
    goto loc_2a52;
loc_2964: // 01ed:0a94
    di = 0x009e;
    push(ds);
    ax = 0x02ed;
    push(ax);
    ax = 0x0028;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0028;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di, ax);
    push(ds);
    ax = 0x02fa;
    push(ax);
    ax = 0x0030;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0030;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di + 2, ax);
    push(ds);
    ax = 0x0307;
    push(ax);
    ax = 0x0038;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0038;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di + 4, ax);
    di = 0x00a4;
    push(ds);
    ax = 0x0314;
    push(ax);
    ax = 0x0040;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0040;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di, ax);
    push(ds);
    ax = 0x0321;
    push(ax);
    ax = 0x0048;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0048;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di + 2, ax);
    push(ds);
    ax = 0x032e;
    push(ax);
    ax = 0x0050;
    push(ax);
    ax = 0x0068;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x0050;
    push(ax);
    sub_2835();
    sp++;
    sp++;
    memoryASet16(ds, di + 4, ax);
    si = 0;
    goto loc_2a4d;
loc_2a32: // 01ed:0b62
    push(memoryAGet16(ds, 0x09c2));
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0028;
    push(ax);
    ax = 0x0068;
    push(ax);
    sub_42b2();
    sp += 0x0006;
    si++;
loc_2a4d: // 01ed:0b7d
    if ((short)si < (short)0x0007)
        goto loc_2a32;
loc_2a52: // 01ed:0b82
    if (memoryAGet16(ss, bp - 2) != 0x0005)
        goto loc_2a93;
    push(ds);
    ax = 0x033b;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    sub_5fd4();
    sub_25f4();
    si = 0;
    goto loc_2a8e;
loc_2a74: // 01ed:0ba4
    push(memoryAGet16(ds, 0x09c2));
    ax = 0x0028;
    push(ax);
    ax = si;
    dx = 0x002a;
    mul(dx);
    ax += 0x0028;
    push(ax);
    sub_42b2();
    sp += 0x0006;
    si++;
loc_2a8e: // 01ed:0bbe
    if ((short)si < (short)0x0004)
        goto loc_2a74;
loc_2a93: // 01ed:0bc3
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x0000)
        goto loc_2aa2;
    if ((short)memoryAGet16(ss, bp - 2) >= (short)0x0006)
        goto loc_2aa2;
    goto loc_2956;
loc_2aa2: // 01ed:0bd2
    if (memoryAGet16(ss, bp - 2) != 0x0006)
        goto loc_2aac;
    ax = 0;
    goto loc_2ab8;
loc_2aac: // 01ed:0bdc
    ax = memoryAGet16(ds, 0x015e);
    ax ^= 0x0001;
    memoryASet16(ds, 0x024e, ax);
    ax = 0x0001;
loc_2ab8: // 01ed:0be8
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2abe() // 01ed:0bee
{
    CStackGuard sg(0, true);
    push(0x7777);
    sub_418f();
    push(cs);
    cs = 0x01ed;
    sub_7c50();
    assert(cs == 0x01ed);
    ax = 0x00c7;
    push(ax);
    ax = 0x0138;
    push(ax);
    ax = 0x000b;
    push(ax);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7e9a();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(memoryAGet16(ds, 0x09b4));
    ax = 0x0067;
    push(ax);
    ax = 0x009e;
    push(ax);
    sub_41a0();
    sp += 0x0006;
    push(ds);
    ax = 0x035a;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x005a;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(ds);
    ax = 0x036c;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x0028;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(ds);
    ax = 0x036e;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x010e;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    assert(pop() == 0x7777);
}
void sub_2c20() // 01ed:0d50
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    di = 0x0201;
    si = 0;
    dx = di;
    in(al, dx);
    if (al & 0x10)
        goto loc_2c37;
    ax = 0x0001;
    goto loc_2c39;
loc_2c37: // 01ed:0d67
    ax = 0;
loc_2c39: // 01ed:0d69
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2508, ax);
    al = 0xff;
    dx = di;
    out(dx, al);
loc_2c4e: // 01ed:0d7e
    dx = di;
    in(al, dx);
    if (al & 0x01)
        goto loc_2c5f;
    if ((short)si >= (short)memoryAGet16(ds, 0x0a42))
        goto loc_2c5f;
    si++;
    goto loc_2c4e;
loc_2c5f: // 01ed:0d8f
    si = 0;
loc_2c61: // 01ed:0d91
    dx = di;
    in(al, dx);
    if (!(al & 0x01))
        goto loc_2c72;
    if ((short)si >= (short)memoryAGet16(ds, 0x0a42))
        goto loc_2c72;
    si++;
    goto loc_2c61;
loc_2c72: // 01ed:0da2
    ax = memoryAGet16(ds, 0x0a44);
    ax = sar(ax, 1);
    if ((short)ax >= (short)si)
        goto loc_2c80;
    ax = 0x0001;
    goto loc_2c82;
loc_2c80: // 01ed:0db0
    ax = 0;
loc_2c82: // 01ed:0db2
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2506, ax);
    if ((short)si >= (short)memoryAGet16(ds, 0x0a42))
        goto loc_2c9f;
    ax = 0x0001;
    goto loc_2ca1;
loc_2c9f: // 01ed:0dcf
    ax = 0;
loc_2ca1: // 01ed:0dd1
    ax = -ax;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2504, ax);
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2cb9() // 01ed:0de9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0010;
    di = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 16, 0x0003);
    ax = bp - 0x10;
    push(ax);
    ax = bp - 0x10;
    push(ax);
    ax = 0x0033;
    push(ax);
    sub_6100();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp - 14);
    ax &= 0x0001;
    push(ax);
    ax = di;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2508, ax);
    memoryASet16(ss, bp - 16, 0x000b);
    ax = bp - 0x10;
    push(ax);
    ax = bp - 0x10;
    push(ax);
    ax = 0x0033;
    push(ax);
    sub_6100();
    sp += 0x0006;
    si = memoryAGet16(ss, bp - 12);
    if ((short)si <= 0)
        goto loc_2d13;
    ax = 0x0001;
    goto loc_2d15;
loc_2d13: // 01ed:0e43
    ax = 0;
loc_2d15: // 01ed:0e45
    ax <<= 1;
    push(ax);
    ax = di;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2506, ax);
    if ((short)si >= 0)
        goto loc_2d2f;
    ax = 0x0001;
    goto loc_2d31;
loc_2d2f: // 01ed:0e5f
    ax = 0;
loc_2d31: // 01ed:0e61
    ax = -ax;
    ax <<= 1;
    push(ax);
    ax = di;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2504, ax);
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2d4a() // 01ed:0e7a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    si = 0;
    goto loc_2ec8;
loc_2d57: // 01ed:0e87
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 2508) == 0x0000)
        goto loc_2d7c;
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2536) != 0xffff)
        goto loc_2d7c;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2536, 0x0000);
loc_2d7c: // 01ed:0eac
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    di = memoryAGet16(ds, bx + 2504);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    di += memoryAGet16(ds, bx + 2506);
    memoryASet16(ss, bp - 4, di);
    bx = si;
    bx <<= 1;
    di += memoryAGet16(ds, bx + 2444);
    ax = si;
    dx = 0x009b;
    mul(dx);
    ax += 0x0003;
    memoryASet16(ss, bp - 2, ax);
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x0000)
        goto loc_2dcb;
    ax += 0x0077;
    if ((short)ax > (short)di)
        goto loc_2dd0;
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0077;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2444, ax);
    goto loc_2de5;
loc_2dcb: // 01ed:0efb
    if ((short)di <= (short)memoryAGet16(ss, bp - 2))
        goto loc_2dda;
loc_2dd0: // 01ed:0f00
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2444, di);
    goto loc_2de5;
loc_2dda: // 01ed:0f0a
    ax = memoryAGet16(ss, bp - 2);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2444, ax);
loc_2de5: // 01ed:0f15
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2536) != 0xfffe)
        goto loc_2e0e;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2532, 0x00ad);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2536, 0xffff);
loc_2e0e: // 01ed:0f3e
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2536) != 0xffff)
        goto loc_2e65;
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_2e59;
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2448);
    bx = si;
    bx <<= 1;
    ax -= memoryAGet16(ds, bx + 2444);
    if ((short)ax >= 0)
        goto loc_2e35;
    ax = -ax;
loc_2e35: // 01ed:0f65
    if ((short)ax > (short)0x0004)
        goto loc_2e3d;
    goto loc_2ec7;
loc_2e3d: // 01ed:0f6d
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, memoryAGet16(ds, bx + 2494) ^ 0x0001);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2444);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2448, ax);
    goto loc_2ec7;
loc_2e59: // 01ed:0f89
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, 0x0000);
    goto loc_2ec7;
loc_2e65: // 01ed:0f95
    bx = si;
    bx <<= 1;
    if ((short)memoryAGet16(ds, bx + 2536) <= (short)0x0012)
        goto loc_2e75;
    ax = 0x0001;
    goto loc_2e77;
loc_2e75: // 01ed:0fa5
    ax = 0;
loc_2e77: // 01ed:0fa7
    ax += 0x0002;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, ax);
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2536) != 0x0013)
        goto loc_2e96;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2532, memoryAGet16(ds, bx + 2532) - 0x0004);
loc_2e96: // 01ed:0fc6
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2536);
    memoryASet16(ds, bx + 2536, memoryAGet16(ds, bx + 2536) + 1);
    bx = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 612);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2532, memoryAGet16(ds, bx + 2532) + ax);
    bx = si;
    bx <<= 1;
    if ((short)memoryAGet16(ds, bx + 2536) <= (short)0x0025)
        goto loc_2ec7;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2536, 0xfffe);
loc_2ec7: // 01ed:0ff7
    si++;
loc_2ec8: // 01ed:0ff8
    if ((short)si >= (short)0x0002)
        goto loc_2ed0;
    goto loc_2d57;
loc_2ed0: // 01ed:1000
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2ed6() // 01ed:1006
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    di = memoryAGet16(ds, 0x0988);
    si = memoryAGet16(ds, 0x09b6);
    if ((short)di <= (short)0x013f)
        goto loc_2eee;
    di = 0x013f;
loc_2eee: // 01ed:101e
    if ((short)di >= (short)0xfec1)
        goto loc_2ef7;
    di = 0xfec1;
loc_2ef7: // 01ed:1027
    if ((short)si <= (short)0x013f)
        goto loc_2f00;
    si = 0x013f;
loc_2f00: // 01ed:1030
    if ((short)si >= (short)0xfec1)
        goto loc_2f09;
    si = 0xfec1;
loc_2f09: // 01ed:1039
    ax = memoryAGet16(ds, 0x09c6);
    memoryASet16(ds, 0x0a3a, ax);
    ax = memoryAGet16(ds, 0x098a);
    memoryASet16(ds, 0x09c4, ax);
    memoryASet16(ds, 0x0a40, memoryAGet16(ds, 0x0a40) + di);
    memoryASet16(ds, 0x09ec, memoryAGet16(ds, 0x09ec) + si);
    if ((short)memoryAGet16(ds, 0x0a40) >= (short)0x0140)
        goto loc_2f53;
    memoryASet16(ds, 0x0a40, 0x0140);
    ax = di;
    ax = -ax;
    di = ax;
    ax = di;
    cx = 0x0004;
    ax = sar(ax, cl);
    di -= ax;
    ax = si;
    ax = sar(ax, cl);
    si -= ax;
    if (memoryAGet16(ds, 0x09d6) != 0x0001)
        goto loc_2f53;
    memoryASet16(ds, 0x09d6, 0x0002);
    memoryASet16(ds, 0x09dc, 0x0000);
loc_2f53: // 01ed:1083
    if ((short)memoryAGet16(ds, 0x0a40) <= (short)0x46c0)
        goto loc_2f89;
    memoryASet16(ds, 0x0a40, 0x46c0);
    ax = di;
    ax = -ax;
    di = ax;
    ax = di;
    cx = 0x0004;
    ax = sar(ax, cl);
    di -= ax;
    ax = si;
    ax = sar(ax, cl);
    si -= ax;
    if (memoryAGet16(ds, 0x09d6) != 0x0000)
        goto loc_2f89;
    memoryASet16(ds, 0x09d6, 0x0002);
    memoryASet16(ds, 0x09dc, 0x0000);
loc_2f89: // 01ed:10b9
    if ((short)memoryAGet16(ds, 0x09ec) >= (short)0x0340)
        goto loc_2fac;
    memoryASet16(ds, 0x09ec, 0x0340);
    ax = si;
    ax = -ax;
    si = ax;
    ax = di;
    cx = 0x0004;
    ax = sar(ax, cl);
    di -= ax;
    ax = si;
    ax = sar(ax, cl);
    si -= ax;
loc_2fac: // 01ed:10dc
    if ((short)memoryAGet16(ds, 0x09ec) <= (short)0x2c80)
        goto loc_2fc7;
    memoryASet16(ds, 0x09ec, 0x2c80);
    ax = si;
    ax = -ax;
    si = ax;
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_2fcc;
loc_2fc7: // 01ed:10f7
    memoryASet16(ss, bp - 2, 0x0001);
loc_2fcc: // 01ed:10fc
    si++;
    ax = memoryAGet16(ds, 0x0a40);
    cx = 0x0006;
    ax = sar(ax, cl);
    memoryASet16(ds, 0x09c6, ax);
    ax = memoryAGet16(ds, 0x09ec);
    ax = sar(ax, cl);
    memoryASet16(ds, 0x098a, ax);
    memoryASet16(ds, 0x0988, di);
    memoryASet16(ds, 0x09b6, si);
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_2ff1() // 01ed:1121
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    si = 0;
    goto loc_312c;
loc_2ffe: // 01ed:112e
    bx = si;
    bx <<= 1;
    di = memoryAGet16(ds, 0x09c6);
    ax = memoryAGet16(ds, bx + 2444);
    di -= ax;
    ax = si;
    dx = 0x0007;
    mul(dx);
    di -= ax;
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x098a);
    dx = memoryAGet16(ds, bx + 2532);
    ax -= dx;
    ax = sar(ax, 1);
    memoryASet16(ss, bp - 6, ax);
    ax = di;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    mul(di);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    mul(memoryAGet16(ss, bp - 6));
    dx = pop();
    dx += ax;
    memoryASet16(ss, bp - 4, dx);
    if ((short)dx < (short)0x006e)
        goto loc_3044;
    goto loc_3113;
loc_3044: // 01ed:1174
    ax = memoryAGet16(ds, 0x09e2);
    ax &= 0x000f;
    dx = 0x0008;
    dx -= ax;
    memoryASet16(ss, bp - 2, dx);
    bx = si;
    bx <<= 1;
    if ((short)memoryAGet16(ds, bx + 2536) <= (short)0xffff)
        goto loc_308a;
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_3066;
    ax = -ax;
loc_3066: // 01ed:1196
    ax = -ax;
    bx = si;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 2536);
    bx <<= 1;
    dx = memoryAGet16(ds, bx + 612);
    bx = 0x0003;
    cx = memoryAGet16(ds, 0x09bc);
    bx <<= cl;
    cx = bx;
    dx <<= cl;
    ax += dx;
    memoryASet16(ds, 0x09b6, ax);
    goto loc_3098;
loc_308a: // 01ed:11ba
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_3093;
    ax = -ax;
loc_3093: // 01ed:11c3
    ax = -ax;
    memoryASet16(ds, 0x09b6, ax);
loc_3098: // 01ed:11c8
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x09b6, memoryAGet16(ds, 0x09b6) + ax);
    ax = di;
    if ((short)ax >= 0)
        goto loc_30a7;
    ax = -ax;
loc_30a7: // 01ed:11d7
    mul(di);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 2506);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    ax += memoryAGet16(ds, bx + 2504);
    cx = memoryAGet16(ds, 0x09bc);
    cx += 0x0004;
    ax <<= cl;
    dx = pop();
    dx += ax;
    dx += memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x0988, memoryAGet16(ds, 0x0988) + dx);
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2526) != 0x0000)
        goto loc_312b;
    memoryASet16(ds, 0x0a4d, 0x00c8);
    memoryASet16(ds, 0x0a4b, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2526, 0x0001);
    ax = memoryAGet16(ds, 0x09d6);
    if (ax == si)
        goto loc_310d;
    memoryASet16(ds, 0x09d6, si);
    memoryASet16(ds, 0x09dc, 0x0000);
    goto loc_312b;
loc_310d: // 01ed:123d
    memoryASet16(ds, 0x09dc, memoryAGet16(ds, 0x09dc) + 1);
    goto loc_312b;
loc_3113: // 01ed:1243
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2526) == 0x0000)
        goto loc_312b;
    ax = 0;
    memoryASet16(ds, 0x09bc, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2526, ax);
loc_312b: // 01ed:125b
    si++;
loc_312c: // 01ed:125c
    if ((short)si >= (short)0x0002)
        goto loc_3134;
    goto loc_2ffe;
loc_3134: // 01ed:1264
    si = 0x0001;
    if ((short)memoryAGet16(ds, 0x098a) <= (short)0x005b)
        goto loc_318b;
    if ((short)memoryAGet16(ds, 0x0a3a) >= (short)0x0080)
        goto loc_3165;
    if ((short)memoryAGet16(ds, 0x09c6) <= (short)0x007f)
        goto loc_3165;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3156;
    ax = -ax;
loc_3156: // 01ed:1286
    ax = -ax;
    ax = sar(ax, 1);
    memoryASet16(ds, 0x0988, ax);
    memoryASet16(ds, 0x0a40, 0x1fc0);
    goto loc_3189;
loc_3165: // 01ed:1295
    if ((short)memoryAGet16(ds, 0x0a3a) <= (short)0x009f)
        goto loc_318b;
    if ((short)memoryAGet16(ds, 0x09c6) >= (short)0x00a0)
        goto loc_318b;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_317e;
    ax = -ax;
loc_317e: // 01ed:12ae
    ax = sar(ax, 1);
    memoryASet16(ds, 0x0988, ax);
    memoryASet16(ds, 0x0a40, 0x2800);
loc_3189: // 01ed:12b9
    si = 0;
loc_318b: // 01ed:12bb
    if (si)
        goto loc_3192;
    goto loc_3294;
loc_3192: // 01ed:12c2
    if ((short)memoryAGet16(ds, 0x098a) > (short)0x0051)
        goto loc_319c;
    goto loc_3294;
loc_319c: // 01ed:12cc
    if ((short)memoryAGet16(ds, 0x09c6) > (short)0x007f)
        goto loc_31a6;
    goto loc_3294;
loc_31a6: // 01ed:12d6
    if ((short)memoryAGet16(ds, 0x09c6) < (short)0x00a0)
        goto loc_31b1;
    goto loc_3294;
loc_31b1: // 01ed:12e1
    if ((short)memoryAGet16(ds, 0x098a) <= (short)0x005b)
        goto loc_31e0;
    if ((short)memoryAGet16(ds, 0x09c6) >= (short)0x0094)
        goto loc_31d1;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_31c9;
    ax = -ax;
loc_31c9: // 01ed:12f9
    ax = -ax;
    memoryASet16(ds, 0x0988, ax);
    goto loc_3294;
loc_31d1: // 01ed:1301
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_31da;
    ax = -ax;
loc_31da: // 01ed:130a
    memoryASet16(ds, 0x0988, ax);
    goto loc_3294;
loc_31e0: // 01ed:1310
    if ((short)memoryAGet16(ds, 0x09c6) <= (short)0x0093)
        goto loc_3200;
    bx = 0x005b;
    bx -= memoryAGet16(ds, 0x098a);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 592);
    dx = 0x00a1;
    dx -= memoryAGet16(ds, 0x09c6);
    if ((short)ax <= (short)dx)
        goto loc_3227;
loc_3200: // 01ed:1330
    if ((short)memoryAGet16(ds, 0x09c6) < (short)0x0094)
        goto loc_320b;
    goto loc_3294;
loc_320b: // 01ed:133b
    bx = 0x005b;
    bx -= memoryAGet16(ds, 0x098a);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 592);
    dx = memoryAGet16(ds, 0x09c6);
    dx += 0xff7b;
    if ((short)ax <= (short)dx)
        goto loc_3227;
    goto loc_3294;
loc_3227: // 01ed:1357
    if ((short)memoryAGet16(ds, 0x09b6) <= (short)0x0000)
        goto loc_3268;
    di = memoryAGet16(ds, 0x09c6);
    di += 0xff6f;
    if ((short)di >= (short)0xfffb)
        goto loc_3249;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3244;
    ax = -ax;
loc_3244: // 01ed:1374
    ax = -ax;
    memoryASet16(ds, 0x0988, ax);
loc_3249: // 01ed:1379
    if ((short)di <= (short)0x0005)
        goto loc_325a;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3257;
    ax = -ax;
loc_3257: // 01ed:1387
    memoryASet16(ds, 0x0988, ax);
loc_325a: // 01ed:138a
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_3263;
    ax = -ax;
loc_3263: // 01ed:1393
    ax = -ax;
    memoryASet16(ds, 0x09b6, ax);
loc_3268: // 01ed:1398
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3271;
    ax = -ax;
loc_3271: // 01ed:13a1
    if ((short)ax <= (short)0x0020)
        goto loc_327e;
    ax = memoryAGet16(ds, 0x0988);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x0988, ax);
loc_327e: // 01ed:13ae
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_3287;
    ax = -ax;
loc_3287: // 01ed:13b7
    if ((short)ax <= (short)0x0020)
        goto loc_3294;
    ax = memoryAGet16(ds, 0x09b6);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x09b6, ax);
loc_3294: // 01ed:13c4
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_329a() // 01ed:13ca
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 8);
    si += 0xfffc;
    di = memoryAGet16(ss, bp + 10);
    di += 0xfffb;
    if ((short)si >= (short)0x0004)
        goto loc_32b3;
    si = 0x0004;
loc_32b3: // 01ed:13e3
    if ((short)si <= (short)0x0110)
        goto loc_32bc;
    si = 0x0110;
loc_32bc: // 01ed:13ec
    if ((short)di >= (short)0x000b)
        goto loc_32c4;
    di = 0x000b;
loc_32c4: // 01ed:13f4
    if ((short)di <= (short)0x00a7)
        goto loc_32cd;
    di = 0x00a7;
loc_32cd: // 01ed:13fd
    if ((short)memoryAGet16(ss, bp + 8) >= (short)0x0008)
        goto loc_32e0;
    push(memoryAGet16(ds, 0x09da));
    push(di);
    ax = 0;
    push(ax);
    sub_41a0();
    sp = bp;
loc_32e0: // 01ed:1410
    if ((short)memoryAGet16(ss, bp + 8) <= (short)0x0117)
        goto loc_32f5;
    push(memoryAGet16(ds, 0x0a38));
    push(di);
    ax = 0x0138;
    push(ax);
    sub_41a0();
    sp = bp;
loc_32f5: // 01ed:1425
    if ((short)memoryAGet16(ss, bp + 10) >= (short)0x0011)
        goto loc_3309;
    push(memoryAGet16(ds, 0x09ba));
    ax = 0x000b;
    push(ax);
    push(si);
    sub_41a0();
    sp = bp;
loc_3309: // 01ed:1439
    if ((short)memoryAGet16(ss, bp + 10) <= (short)0x00ab)
        goto loc_331e;
    push(memoryAGet16(ds, 0x09ba));
    ax = 0x00c7;
    push(ax);
    push(si);
    sub_41a0();
    sp = bp;
loc_331e: // 01ed:144e
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_3322() // 01ed:1452
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    si = memoryAGet16(ds, 0x098c);
    di = memoryAGet16(ds, 0x098e);
    ax = memoryAGet16(ds, 0x09c6);
    ax -= si;
    if ((short)ax >= 0)
        goto loc_333c;
    ax = -ax;
loc_333c: // 01ed:146c
    if ((short)ax >= (short)0x0029)
        goto loc_3353;
    ax = memoryAGet16(ds, 0x098a);
    ax -= memoryAGet16(ds, 0x09e4);
    if ((short)ax >= 0)
        goto loc_334e;
    ax = -ax;
loc_334e: // 01ed:147e
    if ((short)ax < (short)0x0021)
        goto loc_337d;
loc_3353: // 01ed:1483
    ax = memoryAGet16(ds, 0x09c6);
    ax -= di;
    if ((short)ax >= 0)
        goto loc_335e;
    ax = -ax;
loc_335e: // 01ed:148e
    if ((short)ax >= (short)0x0029)
        goto loc_3375;
    ax = memoryAGet16(ds, 0x098a);
    ax -= memoryAGet16(ds, 0x09e6);
    if ((short)ax >= 0)
        goto loc_3370;
    ax = -ax;
loc_3370: // 01ed:14a0
    if ((short)ax < (short)0x0021)
        goto loc_337d;
loc_3375: // 01ed:14a5
    if ((short)memoryAGet16(ds, 0x09c4) <= (short)0x00ab)
        goto loc_3382;
loc_337d: // 01ed:14ad
    ax = 0x0001;
    goto loc_3384;
loc_3382: // 01ed:14b2
    ax = 0;
loc_3384: // 01ed:14b4
    memoryASet16(ss, bp - 2, ax);
    sub_418f();
    if (memoryAGet16(ds, 0x0a0e) == 0x0000)
        goto loc_33b9;
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x0a3a);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2406));
    push(memoryAGet16(ds, 0x09c4));
    push(memoryAGet16(ds, 0x0a3a));
    sub_42b2();
    sp += 0x0006;
    goto loc_33fc;
loc_33b9: // 01ed:14e9
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_33fc;
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x0a3a);
    ax += 0xfffc;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2584));
    ax = memoryAGet16(ds, 0x09c4);
    ax += 0xfffb;
    push(ax);
    ax = memoryAGet16(ds, 0x0a3a);
    ax += 0xfffc;
    push(ax);
    sub_42b2();
    sp += 0x0006;
    push(memoryAGet16(ds, 0x09c4));
    push(memoryAGet16(ds, 0x0a3a));
    sub_329a();
    sp += 0x0004;
loc_33fc: // 01ed:152c
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x0a0e, ax);
    ax = memoryAGet16(ds, 0x0986);
    memoryASet16(ds, 0x0986, memoryAGet16(ds, 0x0986) - 1);
    if (ax)
        goto loc_3443;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3416;
    ax = -ax;
loc_3416: // 01ed:1546
    dx = memoryAGet16(ds, 0x09b6);
    if ((short)dx >= 0)
        goto loc_3420;
    dx = -dx;
loc_3420: // 01ed:1550
    ax += dx;
    cx = 0x0006;
    ax = sar(ax, cl);
    dx = 0x000c;
    dx -= ax;
    if ((short)dx >= 0)
        goto loc_3432;
    dx = -dx;
loc_3432: // 01ed:1562
    memoryASet16(ds, 0x0986, dx);
    memoryASet16(ds, 0x0a3c, memoryAGet16(ds, 0x0a3c) + 1);
    ax = memoryAGet16(ds, 0x0a3c);
    ax &= 0x0003;
    memoryASet16(ds, 0x0a3c, ax);
loc_3443: // 01ed:1573
    bx = memoryAGet16(ds, 0x09be);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = si;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2452));
    push(memoryAGet16(ds, 0x09e4));
    push(si);
    sub_41a0();
    sp += 0x0006;
    bx = memoryAGet16(ds, 0x09c0);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = di;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2542));
    push(memoryAGet16(ds, 0x09e6));
    push(di);
    sub_41a0();
    sp += 0x0006;
    if (memoryAGet16(ds, 0x0a0e) == 0x0000)
        goto loc_34b6;
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x09c6);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2406));
    push(memoryAGet16(ds, 0x098a));
    push(memoryAGet16(ds, 0x09c6));
    sub_421e();
    sp += 0x0006;
    goto loc_34e5;
loc_34b6: // 01ed:15e6
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfffc;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2584));
    ax = memoryAGet16(ds, 0x098a);
    ax += 0xfffb;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfffc;
    push(ax);
    sub_41a0();
    sp += 0x0006;
loc_34e5: // 01ed:1615
    push(memoryAGet16(ds, 0x098a));
    push(memoryAGet16(ds, 0x09c6));
    sub_329a();
    sp += 0x0004;
    if ((short)si >= (short)0x0006)
        goto loc_350c;
    push(memoryAGet16(ds, 0x09da));
    ax = memoryAGet16(ds, 0x09e4);
    ax += 0xfffe;
    push(ax);
    ax = 0;
    push(ax);
    sub_41a0();
    sp += 0x0006;
loc_350c: // 01ed:163c
    if ((short)di <= (short)0x0113)
        goto loc_3527;
    push(memoryAGet16(ds, 0x0a38));
    ax = memoryAGet16(ds, 0x09e6);
    ax += 0xfffe;
    push(ax);
    ax = 0x0138;
    push(ax);
    sub_41a0();
    sp += 0x0006;
loc_3527: // 01ed:1657
    push(memoryAGet16(ds, 0x09b4));
    ax = 0x0067;
    push(ax);
    ax = 0x009e;
    push(ax);
    sub_41a0();
    sp += 0x0006;
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_353f() // 01ed:166f
{
    CStackGuard sg(0, true);
    push(0x7777);
    sub_418f();
    if (memoryAGet16(ds, 0x0a0e) == 0x0000)
        goto loc_3571;
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x09c6);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2406));
    push(memoryAGet16(ds, 0x098a));
    push(memoryAGet16(ds, 0x09c6));
    sub_42b2();
    sp += 0x0006;
    goto loc_35a0;
loc_3571: // 01ed:16a1
    bx = memoryAGet16(ds, 0x0a3c);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfffc;
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2584));
    ax = memoryAGet16(ds, 0x098a);
    ax += 0xfffb;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfffc;
    push(ax);
    sub_42b2();
    sp += 0x0006;
loc_35a0: // 01ed:16d0
    bx = memoryAGet16(ds, 0x09be);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x098c);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2452));
    push(memoryAGet16(ds, 0x09e4));
    push(memoryAGet16(ds, 0x098c));
    sub_41a0();
    sp += 0x0006;
    bx = memoryAGet16(ds, 0x09c0);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0x098e);
    ax &= 0x0003;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(ds, bx + 2542));
    push(memoryAGet16(ds, 0x09e6));
    push(memoryAGet16(ds, 0x098e));
    sub_41a0();
    sp += 0x0006;
    ax = 0x00c7;
    push(ax);
    ax = 0x0138;
    push(ax);
    ax = 0x000b;
    push(ax);
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7e9a();
    assert(cs == 0x01ed);
    sp += 0x0008;
    push(memoryAGet16(ds, 0x09b4));
    ax = 0x0067;
    push(ax);
    ax = 0x009e;
    push(ax);
    sub_41a0();
    sp += 0x0006;
    assert(pop() == 0x7777);
}
void sub_3617() // 01ed:1747
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    if ((short)memoryAGet16(ds, 0x09dc) <= (short)0x0002)
        goto loc_362f;
    si = 0x0001;
    si -= memoryAGet16(ds, 0x09d6);
    goto loc_363e;
loc_362f: // 01ed:175f
    if ((short)memoryAGet16(ds, 0x09c6) >= (short)0x0096)
        goto loc_363c;
    si = 0x0001;
    goto loc_363e;
loc_363c: // 01ed:176c
    si = 0;
loc_363e: // 01ed:176e
    sub_3322();
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_364a;
    ax = -ax;
loc_364a: // 01ed:177a
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_365c;
    ax = -ax;
loc_365c: // 01ed:178c
    di = ax;
    di = sar(di, 1);
    di = sar(di, 1);
    di = sar(di, 1);
    memoryASet16(ss, bp - 8, 0x0014);
loc_3669: // 01ed:1799
    ax = 0;
    memoryASet16(ds, 0x09d2, ax);
    memoryASet16(ds, 0x09cc, ax);
    sub_6a27();
    sub_2d4a();
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3680;
    ax = -ax;
loc_3680: // 01ed:17b0
    if ((short)ax <= (short)di)
        goto loc_3698;
    if ((short)memoryAGet16(ds, 0x0988) >= (short)0x0000)
        goto loc_3694;
    ax = di;
    ax = -ax;
    memoryASet16(ds, 0x0988, ax);
    goto loc_3698;
loc_3694: // 01ed:17c4
    memoryASet16(ds, 0x0988, di);
loc_3698: // 01ed:17c8
    ax = memoryAGet16(ds, 0x09b6);
    if ((short)ax >= 0)
        goto loc_36a1;
    ax = -ax;
loc_36a1: // 01ed:17d1
    if ((short)ax <= (short)memoryAGet16(ss, bp - 6))
        goto loc_36bd;
    if ((short)memoryAGet16(ds, 0x09b6) >= (short)0x0000)
        goto loc_36b7;
    ax = memoryAGet16(ss, bp - 6);
    ax = -ax;
    memoryASet16(ds, 0x09b6, ax);
    goto loc_36bd;
loc_36b7: // 01ed:17e7
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ds, 0x09b6, ax);
loc_36bd: // 01ed:17ed
    sub_2ff1();
    if (memoryAGet16(ds, 0x024e) == 0x0000)
        goto loc_36e1;
    if (si != memoryAGet16(ds, 0x0a14))
        goto loc_36d8;
    ax = 0x1388;
    push(ax);
    sub_69fb();
    sp++;
    sp++;
    goto loc_36e1;
loc_36d8: // 01ed:1808
    ax = 0x0064;
    push(ax);
    sub_69fb();
    sp++;
    sp++;
loc_36e1: // 01ed:1811
    sub_2ed6();
    sub_3322();
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) - 1);
    if ((short)ax <= 0)
        goto loc_36f4;
    goto loc_3669;
loc_36f4: // 01ed:1824
    if (memoryAGet16(ds, 0x09e8) == 0xffff)
        goto loc_36fe;
    goto loc_3669;
loc_36fe: // 01ed:182e
    if (memoryAGet16(ds, 0x09ea) == 0xffff)
        goto loc_3708;
    goto loc_3669;
loc_3708: // 01ed:1838
    sub_6a27();
    ax = si;
    dx = 0x00e6;
    mul(dx);
    ax += 0x0028;
    memoryASet16(ss, bp - 10, ax);
    if (si != memoryAGet16(ds, 0x0a14))
        goto loc_378f;
    ax = 0x0007;
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    ax += 0x000f;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp - 10));
    push(cs);
    cs = 0x01ed;
    sub_88e9();
    assert(cs == 0x01ed);
    sp += 0x0008;
    ax = 0x000a;
    push(ax);
    ax = bp - 0x4;
    push(ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2576, memoryAGet16(ds, bx + 2576) + 1);
    ax = memoryAGet16(ds, bx + 2576);
    push(ax);
    sub_6309();
    sp += 0x0006;
    dx = ds;
    push(dx);
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp - 10));
    push(cs);
    cs = 0x01ed;
    sub_8b12();
    assert(cs == 0x01ed);
    sp += 0x0008;
    bx = si;
    bx <<= 1;
    if ((short)memoryAGet16(ds, bx + 2576) <= (short)0x000e)
        goto loc_37dd;
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2576);
    bx = 0x0001;
    bx -= si;
    bx <<= 1;
    ax -= memoryAGet16(ds, bx + 2576);
    if ((short)ax <= (short)0x0001)
        goto loc_37dd;
    memoryASet16(ds, 0x09d4, 0x0001);
    goto loc_37dd;
loc_378f: // 01ed:18bf
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_89d4();
    assert(cs == 0x01ed);
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0x0003;
    push(ax);
    ax = 0x0001;
    ax -= si;
    dx = 0x00e6;
    mul(dx);
    ax += 0x0023;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7ff9();
    assert(cs == 0x01ed);
    sp += 0x0006;
    ax = 0x000f;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_89d4();
    assert(cs == 0x01ed);
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    ax += 0xfffb;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7ff9();
    assert(cs == 0x01ed);
    sp += 0x0006;
    memoryASet16(ds, 0x0a14, si);
loc_37dd: // 01ed:190d
    ax = 0x0064;
    push(ax);
    sub_5e4a();
    sp++;
    sp++;
    sub_353f();
    ax = si;
    dx = 0x00a5;
    mul(dx);
    ax += 0x0040;
    memoryASet16(ds, 0x0a3a, ax);
    memoryASet16(ds, 0x09c6, ax);
    cx = 0x0006;
    ax <<= cl;
    memoryASet16(ds, 0x0a40, ax);
    ax = 0x0087;
    memoryASet16(ds, 0x09c4, ax);
    memoryASet16(ds, 0x098a, ax);
    ax <<= cl;
    memoryASet16(ds, 0x09ec, ax);
    ax = 0;
    memoryASet16(ds, 0x09e0, ax);
    memoryASet16(ds, 0x09de, ax);
    memoryASet16(ds, 0x09dc, ax);
    memoryASet16(ds, 0x09b6, ax);
    memoryASet16(ds, 0x0988, ax);
    memoryASet16(ds, 0x0a0e, ax);
    memoryASet16(ds, 0x0a3c, ax);
    memoryASet16(ds, 0x0986, cx);
    ax = 0x0001;
    memoryASet16(ds, 0x09bc, ax);
    memoryASet16(ds, 0x0a4b, ax);
    memoryASet16(ds, 0x09d6, 0x0002);
    ax = memoryAGet16(ds, 0x09e2);
    if ((short)ax >= 0)
        goto loc_3842;
    ax = -ax;
loc_3842: // 01ed:1972
    bx = 0x0005;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    memoryASet16(ds, 0x0a3e, dx);
    bx = memoryAGet16(ds, 0x0a14);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2576) != 0x000e)
        goto loc_385f;
    memoryASet16(ds, 0x0a3e, 0x0005);
loc_385f: // 01ed:198f
    memoryASet16(ds, 0x09b8, 0x0000);
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_386b() // 01ed:199b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    dx = 0x0006;
    mul(dx);
    si = ax;
    si += 0x09c8;
    bx = memoryAGet16(ss, bp + 8);
    bx <<= 1;
    di = memoryAGet16(ds, bx + 2444);
    ax = di;
    ax -= memoryAGet16(ss, bp + 10);
    if ((short)ax >= 0)
        goto loc_3892;
    ax = -ax;
loc_3892: // 01ed:19c2
    if ((short)ax >= (short)memoryAGet16(ss, bp + 12))
        goto loc_38a5;
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 2, 0x0000);
    ax = 0x0001;
    goto loc_38c0;
loc_38a5: // 01ed:19d5
    if ((short)di >= (short)memoryAGet16(ss, bp + 10))
        goto loc_38b5;
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 2, 0x0002);
    goto loc_38be;
loc_38b5: // 01ed:19e5
    memoryASet16(ds, si, 0xfffe);
    memoryASet16(ds, si + 2, 0x0000);
loc_38be: // 01ed:19ee
    ax = 0;
loc_38c0: // 01ed:19f0
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_38c4() // 01ed:19f4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    memoryASet16(ds, 0x09cc, 0x0000);
    ax = memoryAGet16(ds, 0x098a);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0a4d))
        goto loc_38de;
    memoryASet16(ds, 0x0a4d, ax);
loc_38de: // 01ed:1a0e
    ax = memoryAGet16(ds, 0x09e2);
    bx = 0x000a;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    ax = 0x0005;
    ax -= dx;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ds, 0x0a4b) != 0x0000)
        goto loc_38f9;
    goto loc_3a0e;
loc_38f9: // 01ed:1a29
    if (!(memoryAGet16(ds, 0x0a14) & 0x0001))
        goto loc_3904;
    goto loc_3a0e;
loc_3904: // 01ed:1a34
    ax = memoryAGet16(ds, 0x0a3e);
    if (ax <= 0x0005)
        goto loc_390f;
    goto loc_3a07;
loc_390f: // 01ed:1a3f
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_3924;
        case 2: goto loc_393a;
        case 4: goto loc_3950;
        case 6: goto loc_3966;
        case 8: goto loc_398b;
        case 10: goto loc_39c6;
        default:
        assert(0);
    }
    //   gap of 12 bytes
loc_3924: // 01ed:1a54
    ax = 0x0002;
    push(ax);
    ax = 0x0037;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3a07;
loc_393a: // 01ed:1a6a
    ax = 0x0002;
    push(ax);
    ax = 0x0054;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3a07;
loc_3950: // 01ed:1a80
    ax = 0x0002;
    push(ax);
    ax = 0x0050;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3a07;
loc_3966: // 01ed:1a96
    if (memoryAGet16(ds, 0x09b8) != 0x0000)
        goto loc_39b3;
    ax = 0x0002;
    push(ax);
    ax = 0x002c;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    ax = si;
    if (ax)
        goto loc_3989;
    goto loc_3a07;
loc_3989: // 01ed:1ab9
    goto loc_39ab;
loc_398b: // 01ed:1abb
    if (memoryAGet16(ds, 0x09b8) != 0x0000)
        goto loc_39b3;
    ax = 0x0002;
    push(ax);
    ax = 0x005a;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    ax = si;
    if (!ax)
        goto loc_3a07;
loc_39ab: // 01ed:1adb
    memoryASet16(ds, 0x09b8, 0x0001);
    goto loc_3a07;
loc_39b3: // 01ed:1ae3
    ax = 0x0002;
    push(ax);
    ax = 0x003a;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3a04;
loc_39c6: // 01ed:1af6
    if (memoryAGet16(ds, 0x09b8) != 0x0000)
        goto loc_39ec;
    ax = 0x0002;
    push(ax);
    ax = 0x0003;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    if (!ax)
        goto loc_39e8;
    memoryASet16(ds, 0x09b8, 0x0001);
loc_39e8: // 01ed:1b18
    si = 0;
    goto loc_3a07;
loc_39ec: // 01ed:1b1c
    ax = 0x0001;
    push(ax);
    ax = memoryAGet16(ds, 0x09b8);
    memoryASet16(ds, 0x09b8, memoryAGet16(ds, 0x09b8) + 1);
    ax += 0x0008;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
loc_3a04: // 01ed:1b34
    si = 0x0001;
loc_3a07: // 01ed:1b37
    memoryASet16(ds, 0x09cc, si);
    goto loc_3bb4;
loc_3a0e: // 01ed:1b3e
    if ((short)memoryAGet16(ds, 0x09b6) > (short)0x0000)
        goto loc_3a18;
    goto loc_3ba3;
loc_3a18: // 01ed:1b48
    if ((short)memoryAGet16(ds, 0x09c6) < (short)0x008c)
        goto loc_3a23;
    goto loc_3ba3;
loc_3a23: // 01ed:1b53
    ax = memoryAGet16(ds, 0x09b6);
    cx = 0x0006;
    ax = sar(ax, cl);
    if (ax)
        goto loc_3a36;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_3a4c;
loc_3a36: // 01ed:1b66
    ax = 0x008c;
    ax -= memoryAGet16(ds, 0x098a);
    bx = memoryAGet16(ds, 0x09b6);
    cx = 0x0006;
    bx = sar(bx, cl);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    memoryASet16(ss, bp - 6, ax);
loc_3a4c: // 01ed:1b7c
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0001)
        goto loc_3a5e;
    ax = memoryAGet16(ds, 0x0988);
    cx = 0x0006;
    ax = sar(ax, cl);
    if (ax)
        goto loc_3a64;
loc_3a5e: // 01ed:1b8e
    di = memoryAGet16(ds, 0x09c6);
    goto loc_3a78;
loc_3a64: // 01ed:1b94
    ax = memoryAGet16(ds, 0x0988);
    cx = 0x0006;
    ax = sar(ax, cl);
    mul(memoryAGet16(ss, bp - 6));
    di = ax;
    di += memoryAGet16(ds, 0x09c6);
    di += 0xfffc;
loc_3a78: // 01ed:1ba8
    ax = memoryAGet16(ds, 0x098c);
    ax -= memoryAGet16(ds, 0x09c6);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3a8b;
    ax = -ax;
loc_3a8b: // 01ed:1bbb
    if ((short)ax >= (short)0x0080)
        goto loc_3ae8;
    if ((short)memoryAGet16(ds, 0x0a4d) >= (short)0x004b)
        goto loc_3ae8;
    if ((short)memoryAGet16(ds, 0x098a) >= (short)0x009e)
        goto loc_3aa4;
    ax = 0x0001;
    goto loc_3aa6;
loc_3aa4: // 01ed:1bd4
    ax = 0;
loc_3aa6: // 01ed:1bd6
    push(ax);
    if ((short)memoryAGet16(ds, 0x0988) >= (short)0x0000)
        goto loc_3ab3;
    ax = 0x0001;
    goto loc_3ab5;
loc_3ab3: // 01ed:1be3
    ax = 0;
loc_3ab5: // 01ed:1be5
    dx = pop();
    dx ^= ax;
    if (!dx)
        goto loc_3ad1;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfff1;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3bb4;
loc_3ad1: // 01ed:1c01
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0x000f;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3bb4;
loc_3ae8: // 01ed:1c18
    if ((short)memoryAGet16(ds, 0x098a) > (short)0x0082)
        goto loc_3af3;
    goto loc_3b76;
loc_3af3: // 01ed:1c23
    ax = memoryAGet16(ss, bp - 4);
    if ((short)ax >= 0)
        goto loc_3afc;
    ax = -ax;
loc_3afc: // 01ed:1c2c
    if ((short)ax <= (short)0x0006)
        goto loc_3b32;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3b0a;
    ax = -ax;
loc_3b0a: // 01ed:1c3a
    if ((short)ax >= (short)0x0400)
        goto loc_3b32;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x098c);
    ax += 0xffc4;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    dx = memoryAGet16(ds, 0x09c6);
    dx -= ax;
    push(dx);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3bb4;
loc_3b32: // 01ed:1c62
    ax = 0x000a;
    push(ax);
    ax = memoryAGet16(ds, 0x098c);
    ax += 0xffc4;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    dx = memoryAGet16(ds, 0x09c6);
    dx += memoryAGet16(ss, bp - 2);
    ax += dx;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    if ((short)memoryAGet16(ds, 0x098c) >= (short)0x0069)
        goto loc_3b6f;
    if (memoryAGet16(ds, 0x09d6) != 0x0000)
        goto loc_3b6a;
    if ((short)memoryAGet16(ds, 0x09dc) >= (short)0x0002)
        goto loc_3b6f;
loc_3b6a: // 01ed:1c9a
    ax = 0x0001;
    goto loc_3b71;
loc_3b6f: // 01ed:1c9f
    ax = 0;
loc_3b71: // 01ed:1ca1
    memoryASet16(ds, 0x09cc, ax);
    goto loc_3bb4;
loc_3b76: // 01ed:1ca6
    if ((short)di >= (short)0x0003)
        goto loc_3b82;
    ax = 0x0006;
    ax -= di;
    di = ax;
loc_3b82: // 01ed:1cb2
    if ((short)di <= (short)0x007b)
        goto loc_3b8e;
    ax = 0x00f6;
    ax -= di;
    di = ax;
loc_3b8e: // 01ed:1cbe
    ax = 0x0003;
    push(ax);
    ax = di;
    ax += memoryAGet16(ss, bp - 2);
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3bb4;
loc_3ba3: // 01ed:1cd3
    ax = 0x0008;
    push(ax);
    ax = 0x0038;
    push(ax);
    ax = 0;
    push(ax);
    sub_386b();
    sp += 0x0006;
loc_3bb4: // 01ed:1ce4
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_3bba() // 01ed:1cea
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    memoryASet16(ds, 0x09d2, 0x0000);
    ax = memoryAGet16(ds, 0x098a);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0a4d))
        goto loc_3bd4;
    memoryASet16(ds, 0x0a4d, ax);
loc_3bd4: // 01ed:1d04
    ax = memoryAGet16(ds, 0x09e2);
    bx = 0x000a;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    ax = 0x0005;
    ax -= dx;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ds, 0x0a4b) != 0x0000)
        goto loc_3bef;
    goto loc_3d26;
loc_3bef: // 01ed:1d1f
    ax = memoryAGet16(ds, 0x0a14);
    ax &= 0x0001;
    if (ax == 0x0001)
        goto loc_3bfd;
    goto loc_3d26;
loc_3bfd: // 01ed:1d2d
    ax = memoryAGet16(ds, 0x0a3e);
    if (ax <= 0x0005)
        goto loc_3c08;
    goto loc_3d1f;
loc_3c08: // 01ed:1d38
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_3c1d;
        case 2: goto loc_3c34;
        case 4: goto loc_3c4b;
        case 6: goto loc_3c62;
        case 8: goto loc_3c9d;
        default:
        assert(0);
    }
    //   gap of 12 bytes
loc_3c1d: // 01ed:1d4d
    ax = 0x0002;
    push(ax);
    ax = 0x00e8;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3d1f;
loc_3c34: // 01ed:1d64
    ax = 0x0002;
    push(ax);
    ax = 0x00ca;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3d1f;
loc_3c4b: // 01ed:1d7b
    ax = 0x0002;
    push(ax);
    ax = 0x00d0;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    goto loc_3d1f;
loc_3c62: // 01ed:1d92
    if (memoryAGet16(ds, 0x09b8) != 0x0000)
        goto loc_3c88;
    ax = 0x0002;
    push(ax);
    ax = 0x00fa;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    ax = si;
    if (ax)
        goto loc_3c86;
    goto loc_3d1f;
loc_3c86: // 01ed:1db6
    goto loc_3cbe;
loc_3c88: // 01ed:1db8
    ax = 0x0002;
    push(ax);
    ax = 0x00dc;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3d1c;
loc_3c9d: // 01ed:1dcd
    if (memoryAGet16(ds, 0x09b8) != 0x0000)
        goto loc_3cc6;
    ax = 0x0002;
    push(ax);
    ax = 0x00be;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    si = ax;
    ax = si;
    if (!ax)
        goto loc_3d1f;
loc_3cbe: // 01ed:1dee
    memoryASet16(ds, 0x09b8, 0x0001);
    goto loc_3d1f;
loc_3cc6: // 01ed:1df6
    ax = 0x0002;
    push(ax);
    ax = 0x00e6;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3d1c;
    //   gap of 66 bytes
loc_3d1c: // 01ed:1e4c
    si = 0x0001;
loc_3d1f: // 01ed:1e4f
    memoryASet16(ds, 0x09d2, si);
    goto loc_3ed2;
loc_3d26: // 01ed:1e56
    if ((short)memoryAGet16(ds, 0x09b6) > (short)0x0000)
        goto loc_3d30;
    goto loc_3ec0;
loc_3d30: // 01ed:1e60
    if ((short)memoryAGet16(ds, 0x09c6) > (short)0x007d)
        goto loc_3d3a;
    goto loc_3ec0;
loc_3d3a: // 01ed:1e6a
    ax = memoryAGet16(ds, 0x09b6);
    cx = 0x0006;
    ax = sar(ax, cl);
    if (ax)
        goto loc_3d4d;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_3d63;
loc_3d4d: // 01ed:1e7d
    ax = 0x008c;
    ax -= memoryAGet16(ds, 0x098a);
    bx = memoryAGet16(ds, 0x09b6);
    cx = 0x0006;
    bx = sar(bx, cl);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    memoryASet16(ss, bp - 6, ax);
loc_3d63: // 01ed:1e93
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0001)
        goto loc_3d75;
    ax = memoryAGet16(ds, 0x0988);
    cx = 0x0006;
    ax = sar(ax, cl);
    if (ax)
        goto loc_3d7b;
loc_3d75: // 01ed:1ea5
    di = memoryAGet16(ds, 0x09c6);
    goto loc_3d8f;
loc_3d7b: // 01ed:1eab
    ax = memoryAGet16(ds, 0x0988);
    cx = 0x0006;
    ax = sar(ax, cl);
    mul(memoryAGet16(ss, bp - 6));
    di = ax;
    di += memoryAGet16(ds, 0x09c6);
    di += 0xfffc;
loc_3d8f: // 01ed:1ebf
    ax = memoryAGet16(ds, 0x098e);
    ax -= memoryAGet16(ds, 0x09c6);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3da2;
    ax = -ax;
loc_3da2: // 01ed:1ed2
    if ((short)ax >= (short)0x0080)
        goto loc_3e01;
    if ((short)memoryAGet16(ds, 0x0a4d) >= (short)0x004b)
        goto loc_3e01;
    if ((short)memoryAGet16(ds, 0x098a) >= (short)0x009e)
        goto loc_3dbb;
    ax = 0x0001;
    goto loc_3dbd;
loc_3dbb: // 01ed:1eeb
    ax = 0;
loc_3dbd: // 01ed:1eed
    push(ax);
    if ((short)memoryAGet16(ds, 0x0988) >= (short)0x0000)
        goto loc_3dca;
    ax = 0x0001;
    goto loc_3dcc;
loc_3dca: // 01ed:1efa
    ax = 0;
loc_3dcc: // 01ed:1efc
    dx = pop();
    dx ^= ax;
    if (!dx)
        goto loc_3de9;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0x000f;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3ed2;
loc_3de9: // 01ed:1f19
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x09c6);
    ax += 0xfff1;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3ed2;
loc_3e01: // 01ed:1f31
    if ((short)memoryAGet16(ds, 0x098a) > (short)0x0082)
        goto loc_3e0c;
    goto loc_3e90;
loc_3e0c: // 01ed:1f3c
    ax = memoryAGet16(ss, bp - 4);
    if ((short)ax >= 0)
        goto loc_3e15;
    ax = -ax;
loc_3e15: // 01ed:1f45
    if ((short)ax <= (short)0x0006)
        goto loc_3e4a;
    ax = memoryAGet16(ds, 0x0988);
    if ((short)ax >= 0)
        goto loc_3e23;
    ax = -ax;
loc_3e23: // 01ed:1f53
    if ((short)ax >= (short)0x0400)
        goto loc_3e4a;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x098e);
    ax += 0xff26;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax += memoryAGet16(ds, 0x09c6);
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3ed2;
loc_3e4a: // 01ed:1f7a
    ax = 0x000a;
    push(ax);
    ax = memoryAGet16(ds, 0x098e);
    ax += 0xff26;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    dx = memoryAGet16(ds, 0x09c6);
    dx -= memoryAGet16(ss, bp - 2);
    dx -= ax;
    push(dx);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    if ((short)memoryAGet16(ds, 0x098e) <= (short)0x00af)
        goto loc_3e89;
    if (memoryAGet16(ds, 0x09d6) != 0x0001)
        goto loc_3e84;
    if ((short)memoryAGet16(ds, 0x09dc) >= (short)0x0002)
        goto loc_3e89;
loc_3e84: // 01ed:1fb4
    ax = 0x0001;
    goto loc_3e8b;
loc_3e89: // 01ed:1fb9
    ax = 0;
loc_3e8b: // 01ed:1fbb
    memoryASet16(ds, 0x09d2, ax);
    goto loc_3ed2;
loc_3e90: // 01ed:1fc0
    if ((short)di >= (short)0x009e)
        goto loc_3e9d;
    ax = 0x013c;
    ax -= di;
    di = ax;
loc_3e9d: // 01ed:1fcd
    if ((short)di <= (short)0x0115)
        goto loc_3eaa;
    ax = 0x022a;
    ax -= di;
    di = ax;
loc_3eaa: // 01ed:1fda
    ax = 0x0003;
    push(ax);
    ax = di;
    ax -= memoryAGet16(ss, bp - 2);
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
    goto loc_3ed2;
loc_3ec0: // 01ed:1ff0
    ax = 0x0008;
    push(ax);
    ax = 0x00d3;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_386b();
    sp += 0x0006;
loc_3ed2: // 01ed:2002
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_3ed8() // 01ed:2008
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = 0;
    memoryASet16(ds, 0x09b6, ax);
    memoryASet16(ds, 0x0988, ax);
    memoryASet16(ds, 0x0a0e, ax);
    memoryASet16(ds, 0x0a3c, ax);
    memoryASet16(ds, 0x09dc, ax);
    memoryASet16(ds, 0x0986, 0x0006);
    memoryASet16(ds, 0x0a4d, 0x00c8);
    si = ax;
    goto loc_3fbc;
loc_3f02: // 01ed:2032
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2444);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2448, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2532, 0x00ad);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2536, 0xffff);
    ax = 0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2494, ax);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2508, ax);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2504, ax);
    push(ax);
    ax = si;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    ax = pop();
    memoryASet16(ds, bx + 2506, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2576, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 2526, ax);
    ax = si;
    ax++;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 170);
    push(ax);
    ax = si;
    ax++;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 172);
    ax--;
    dx = pop();
    if ((short)dx >= (short)ax)
        goto loc_3fbb;
    ax = 0x0002;
    ax -= si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 170);
    push(ax);
    ax = 0x0002;
    ax -= si;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 172);
    ax--;
    dx = pop();
    if (dx != ax)
        goto loc_3fbb;
    memoryASet16(ds, 0x09d8, si);
loc_3fbb: // 01ed:20eb
    si++;
loc_3fbc: // 01ed:20ec
    if ((short)si >= (short)0x0002)
        goto loc_3fc4;
    goto loc_3f02;
loc_3fc4: // 01ed:20f4
    ax = memoryAGet16(ds, 0x0a44);
    ax = sar(ax, 1);
    ax += memoryAGet16(ds, 0x0a44);
    memoryASet16(ds, 0x0a42, ax);
    ax = memoryAGet16(ds, 0x09d8);
    dx = 0x00a5;
    mul(dx);
    ax += 0x0040;
    memoryASet16(ds, 0x0a3a, ax);
    memoryASet16(ds, 0x09c6, ax);
    cx = 0x0006;
    ax <<= cl;
    memoryASet16(ds, 0x0a40, ax);
    ax = 0x0087;
    memoryASet16(ds, 0x09c4, ax);
    memoryASet16(ds, 0x098a, ax);
    ax <<= cl;
    memoryASet16(ds, 0x09ec, ax);
    ax = memoryAGet16(ds, 0x09d8);
    ax += 0x0002;
    memoryASet16(ds, 0x0a14, ax);
    memoryASet16(ds, 0x09d6, 0x0002);
    ax = 0x0001;
    memoryASet16(ds, 0x09bc, ax);
    memoryASet16(ds, 0x0a4b, ax);
    memoryASet16(ds, 0x09d4, 0x0000);
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ds, 0x00e6);
    dx = 0x000e;
    mul(dx);
    bx = ax;
    al = memoryAGet(ds, bx + 238);
    ah = 0x00;
    if (ax == 0x0020)
        goto loc_4045;
    if (ax == 0x0043)
        goto loc_404c;
    if (ax == 0x004a)
        goto loc_403e;
    goto loc_4051;
loc_403e: // 01ed:216e
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_4051;
loc_4045: // 01ed:2175
    memoryASet16(ss, bp - 4, 0x0002);
    goto loc_4051;
loc_404c: // 01ed:217c
    memoryASet16(ss, bp - 4, 0x0003);
loc_4051: // 01ed:2181
    ax = memoryAGet16(ds, 0x0122);
    dx = 0x000e;
    mul(dx);
    bx = ax;
    al = memoryAGet(ds, bx + 298);
    ah = 0x00;
    if (ax == 0x0020)
        goto loc_4079;
    if (ax == 0x0043)
        goto loc_4080;
    if (ax == 0x004a)
        goto loc_4072;
    goto loc_4085;
loc_4072: // 01ed:21a2
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_4085;
loc_4079: // 01ed:21a9
    memoryASet16(ss, bp - 2, 0x0002);
    goto loc_4085;
loc_4080: // 01ed:21b0
    memoryASet16(ss, bp - 2, 0x0003);
loc_4085: // 01ed:21b5
    ax = 0x0009;
    push(ax);
    sub_600c();
    sp++;
    sp++;
    memoryASet16(ds, 0x0a49, dx);
    memoryASet16(ds, 0x0a47, ax);
    ax = 0x0c5d;
    dx = cs;
    push(dx);
    push(ax);
    ax = 0x0009;
    push(ax);
    sub_601c();
    sp += 0x0006;
    sub_2abe();
    si = 0;
loc_40ab: // 01ed:21db
    sync();
    if (memoryAGet16(ds, 0x09d4) == 0x0000)
        goto loc_40b5;
    goto loc_4168;
loc_40b5: // 01ed:21e5
    ax = memoryAGet16(ds, 0x09e2);
    dx = 0x0005;
    mul(dx);
    ax++;
    memoryASet16(ds, 0x09e2, ax);
    ax = memoryAGet16(ss, bp - 4);
    ax--;
    if (ax > 0x0002)
        goto loc_40f4;
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_40d9;
        case 2: goto loc_40e3;
        case 4: goto loc_40f1;
        default:
        assert(0);
    }
    //   gap of 6 bytes
loc_40d9: // 01ed:2209
    ax = 0;
    push(ax);
    sub_2c20();
    sp++;
    sp++;
    goto loc_40f4;
loc_40e3: // 01ed:2213
    if (!si)
        goto loc_40f4;
    ax = 0;
    push(ax);
    sub_2cb9();
    sp++;
    sp++;
    goto loc_40f4;
loc_40f1: // 01ed:2221
    sub_38c4();
loc_40f4: // 01ed:2224
    ax = memoryAGet16(ss, bp - 2);
    ax--;
    if (ax > 0x0002)
        goto loc_4129;
    bx = ax;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_410c;
        case 2: goto loc_4117;
        case 4: goto loc_4126;
        default:
        assert(0);
    }
    //   gap of 6 bytes
loc_410c: // 01ed:223c
    ax = 0x0001;
    push(ax);
    sub_2c20();
    sp++;
    sp++;
    goto loc_4129;
loc_4117: // 01ed:2247
    if (!si)
        goto loc_4129;
    ax = 0x0001;
    push(ax);
    sub_2cb9();
    sp++;
    sp++;
    goto loc_4129;
loc_4126: // 01ed:2256
    sub_3bba();
loc_4129: // 01ed:2259
    ax = 0x0001;
    ax -= si;
    si = ax;
    sub_2d4a();
    if (memoryAGet16(ds, 0x0a4b) == 0x0000)
        goto loc_4145;
    sub_2ff1();
    sub_3322();
    di = 0x0001;
    goto loc_4154;
loc_4145: // 01ed:2275
    sync();
    if (!di)
        goto loc_4154;
    sub_2ff1();
    sub_2ed6();
    di = ax;
    sub_3322();
loc_4154: // 01ed:2284
    if (!di)
        goto loc_4162;
    if ((short)memoryAGet16(ds, 0x09dc) > (short)0x0002)
        goto loc_4162;
    goto loc_40ab;
loc_4162: // 01ed:2292
    sub_3617();
    goto loc_40ab;
loc_4168: // 01ed:2298
    sub_353f();
    push(memoryAGet16(ds, 0x0a49));
    push(memoryAGet16(ds, 0x0a47));
    ax = 0x0009;
    push(ax);
    sub_601c();
    sp += 0x0006;
loc_417d: // 01ed:22ad
    sub_61fb();
    if (!ax)
        goto loc_4189;
    sub_5fd4();
    goto loc_417d;
loc_4189: // 01ed:22b9
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_418f() // 01ed:22bf
{
    CStackGuard sg(0, false);
    dx = 0x03da;
loc_4192: // 01ed:22c2
    in(al, dx);
    if (al & 0x08)
        goto loc_4192;
    dx = 0x03da;
loc_419a: // 01ed:22ca
    in(al, dx);
    if (!(al & 0x08))
        goto loc_419a;
}
void sub_41a0() // 01ed:22d0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    dx = 0xb800;
    es = dx;
    ax = memoryAGet16(ss, bp + 10);
    cl = al;
    al &= 0xfe;
    dx = 0x0028;
    mul(dx);
    di = memoryAGet16(ss, bp + 8);
    di >>= 1;
    di >>= 1;
    di += ax;
    si = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ds, si);
    bx += 0x0004;
    bx >>= 1;
    bx >>= 1;
    ax = memoryAGet16(ds, si + 2);
    al++;
    al >>= 1;
    si += 0x0004;
    dx = 0x0050;
    dx -= bx;
    if (!(cl & 0x01))
        goto loc_4200;
    di += 0x2000;
loc_41e6: // 01ed:2316
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di ^= 0x2000;
    di += dx;
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di -= bx;
    di ^= 0x2000;
    tl = al;
    al--;
    if ((char)tl > 1)
        goto loc_41e6;
    goto loc_4218;
loc_4200: // 01ed:2330
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di -= bx;
    di ^= 0x2000;
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di ^= 0x2000;
    di += dx;
    tl = al;
    al--;
    if ((char)tl > 1)
        goto loc_4200;
loc_4218: // 01ed:2348
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_421e() // 01ed:234e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    dx = 0xb800;
    es = dx;
    ax = memoryAGet16(ss, bp + 10);
    cl = al;
    al &= 0xfe;
    dx = 0x0028;
    mul(dx);
    di = memoryAGet16(ss, bp + 8);
    di >>= 1;
    di >>= 1;
    di += ax;
    si = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ds, si);
    bx += 0x0004;
    bx >>= 1;
    bl >>= 1;
    ax = memoryAGet16(ds, si + 2);
    al++;
    al >>= 1;
    ah = al;
    si += 0x0004;
    dx = 0x0050;
    dx -= bx;
    if (!(cl & 0x01))
        goto loc_428a;
    di += 0x2000;
loc_4266: // 01ed:2396
    cl = bl;
loc_4268: // 01ed:2398
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di++;
    if (--cx)
        goto loc_4268;
    di ^= 0x2000;
    di += dx;
    cl = bl;
loc_4277: // 01ed:23a7
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di++;
    if (--cx)
        goto loc_4277;
    di -= bx;
    di ^= 0x2000;
    tl = ah;
    ah--;
    if ((char)tl > 1)
        goto loc_4266;
    goto loc_42ac;
loc_428a: // 01ed:23ba
    cl = bl;
loc_428c: // 01ed:23bc
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di++;
    if (--cx)
        goto loc_428c;
    di -= bx;
    di ^= 0x2000;
    cl = bl;
loc_429b: // 01ed:23cb
    lodsb<MemAuto, DirAuto>();
    memoryASet(es, di, memoryAGet(es, di) ^ al);
    di++;
    if (--cx)
        goto loc_429b;
    di ^= 0x2000;
    di += dx;
    tl = ah;
    ah--;
    if ((char)tl > 1)
        goto loc_428a;
loc_42ac: // 01ed:23dc
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_42b2() // 01ed:23e2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    dx = 0xb800;
    es = dx;
    ax = memoryAGet16(ss, bp + 10);
    cl = al;
    al &= 0xfe;
    dx = 0x0028;
    mul(dx);
    di = memoryAGet16(ss, bp + 8);
    di >>= 1;
    di >>= 1;
    di += ax;
    si = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ds, si);
    bx += 0x0004;
    bx >>= 1;
    bx >>= 1;
    ax = memoryAGet16(ds, si + 2);
    al++;
    al >>= 1;
    ah = al;
    al = 0;
    dx = 0x0050;
    dx -= bx;
    if (!(cl & 0x01))
        goto loc_4313;
    di += 0x2000;
loc_42f9: // 01ed:2429
    cx = bx;
    rep_stosb<MemAuto, DirAuto>();
    di ^= 0x2000;
    di += dx;
    cx = bx;
    rep_stosb<MemAuto, DirAuto>();
    di -= bx;
    di ^= 0x2000;
    tl = ah;
    ah--;
    if ((char)tl > 1)
        goto loc_42f9;
    goto loc_432b;
loc_4313: // 01ed:2443
    cx = bx;
    rep_stosb<MemAuto, DirAuto>();
    di -= bx;
    di ^= 0x2000;
    cx = bx;
    rep_stosb<MemAuto, DirAuto>();
    di ^= 0x2000;
    di += dx;
    tl = ah;
    ah--;
    if ((char)tl > 1)
        goto loc_4313;
loc_432b: // 01ed:245b
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_43e0()
{
    push(0x7777);
    sub_43e0_jump();
}

void sub_43e0_jump()
{
    cs = 0x43e;
    push(ds);
    push(cs);
    ds = pop();
    flags.direction = false;
    push(bp);
    switch (si)
    {
        case 0: sub_45b7(); break;
        case 2: sub_4611(); break;
        case 4: sub_4628(); break;
        case 6: sub_43f5(); break;
        case 8: sub_4677(); break;
        case 10: sub_467f(); break;
        case 12: sub_4693(); break;
        case 14: sub_43f0(); break;
        case 16: sub_43f0(); break;
        case 18: sub_4bde(); break;
        case 20: sub_43f0(); break;
        case 22: sub_43f0(); break;
        case 24: sub_43f5(); break;
        case 26: sub_449d(); break;
        case 28: sub_44be(); break;
        case 30: sub_4666(); break;
        case 32: sub_44c3(); break;
        case 34: sub_47b2(); break;
        case 36: sub_4778(); break;
        case 38: sub_473c(); break;
        case 40: sub_44dd(); break;
        case 42: sub_43f5(); break;
        case 44: sub_447f(); break;
        case 46: sub_53bc(); break;
        case 48: sub_53d5(); break;
        case 50: sub_444c(); break;
        case 52: sub_4464(); break;
        case 54: sub_4479(); break;
        case 56: sub_4430(); break;
        default:
        assert(0);
    }
    bp = pop();
    ds = pop();
    int check = pop();
    assert(check== 0x7777 || check == 0xbcde);
    cs = pop();
}
void sub_43f0() // 043e:0010
{
    CStackGuard sg(0, false);
}
void sub_43f5() // 043e:0015
{
    CStackGuard sg(0, false);
}
void sub_4430() // 043e:0050
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x03fc, ax);
    memoryASet16(ds, 0x03fe, bx);
    memoryASet16(ds, 0x0400, cx);
    memoryASet16(ds, 0x0402, dx);
}
void sub_444c() // 043e:006c
{
    CStackGuard sg(0, false);
    push(cs);
    es = pop();
    bx = 0x0060;
}
void sub_4452() // 043e:0072
{
    CStackGuardFar sg(0, false);
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_445e;
    ax = 0x0002;
    cs = pop();
    return;
loc_445e: // 043e:007e
    ax = 0x0001;
    cs = pop();
}
void sub_4464() // 043e:0084
{
    CStackGuard sg(0, false);
    sub_446a();
    goto loc_51f5;
    //   gap of 3467 bytes
loc_51f5: // 043e:0e15
    cx -= si;
    dx -= di;
    dx++;
    memoryASet16(ds, 0x0e12, dx);
    push(cx);
    push(es);
    push(bx);
    sub_4d35();
    memoryASet(ds, 0x0e14, bl);
    flags.direction = false;
    push(es);
    ds = pop();
    si = di;
    di = pop();
    es = pop();
    cl = al;
    bx = pop();
    dx = bx;
    sub_538c();
    bl++;
    dx >>= 1;
    dx >>= 1;
    if (memoryAGet(cs, 0x010a) == 0x00)
        goto loc_5229;
    bl--;
    dx >>= 1;
loc_5229: // 043e:0e49
    bl = memoryAGet(cs, bx + 2377);
    al = memoryAGet(cs, 0x0e14);
loc_5232: // 043e:0e52
    push(ax);
    push(dx);
    push(si);
    sub_5263();
    si = pop();
    dx = pop();
    ax = pop();
    tx = si;
    si = bx;
    bx = tx;
    if (memoryAGet(cs, 0x010b) < 0x04)
        goto loc_5250;
    push(es);
    callIndirect(cs, memoryAGet16(cs, 0x051e)); // 043e:0e66
    push(es);
    ds = pop();
    es = pop();
    goto loc_5255;
loc_5250: // 043e:0e70
    callIndirect(cs, memoryAGet16(cs, 0x051e)); // 043e:0e70
loc_5255: // 043e:0e75
    tx = si;
    si = bx;
    bx = tx;
    tx = memoryAGet16(cs, 0x0e12);
    memoryASet16(cs, 0x0e12, memoryAGet16(cs, 0x0e12) - 1);
    if (tx != 1)
        goto loc_5232;
    bx = di;
    push(cs);
    ds = pop();
}
void sub_446a() // 043e:008a
{
    CStackGuard sg(0, false);
    si = cx;
    di = dx;
    cx += memoryAGet16(es, bx);
    bx++;
    bx++;
    dx += memoryAGet16(es, bx);
    bx++;
    bx++;
}
void sub_4479() // 043e:0099
{
    CStackGuard sg(0, false);
    sub_446a();
    goto loc_52ad;
    //   gap of 3630 bytes
loc_52ad: // 043e:0ecd
    dx -= di;
    dx++;
    memoryASet16(ds, 0x0e12, dx);
    push(bx);
    bh = 0;
    bl = al;
    bl <<= 1;
    bx += 0x0ea2;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x0e9f, bx);
    bx = si;
    ax = cx;
    ax -= bx;
    memoryASet(ds, 0x0ea1, al);
    ax >>= 1;
    ax >>= 1;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_52db;
    ax >>= 1;
loc_52db: // 043e:0efb
    ax++;
    bx = pop();
    push(ax);
    push(si);
    push(cx);
    push(es);
    push(bx);
    sub_4d35();
    memoryASet(ds, 0x0e14, bl);
    flags.direction = false;
    si = pop();
    ds = pop();
    cl = al;
    bx = pop();
    sub_538c();
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_52fc;
    bl++;
loc_52fc: // 043e:0f1c
    ch = memoryAGet(cs, bx + 2377);
    bx = pop();
    sub_538c();
    bh = memoryAGet(cs, bx + 2369);
    bl = ch;
    dx = pop();
    al = memoryAGet(cs, 0x0e14);
loc_5311: // 043e:0f31
    push(ax);
    push(bx);
    push(dx);
    push(di);
    sub_5331();
    di = pop();
    dx = pop();
    bx = pop();
    ax = pop();
    tx = di;
    di = bx;
    bx = tx;
    callIndirect(cs, memoryAGet16(cs, 0x051e)); // 043e:0f3e
    tx = di;
    di = bx;
    bx = tx;
    tx = memoryAGet16(cs, 0x0e12);
    memoryASet16(cs, 0x0e12, memoryAGet16(cs, 0x0e12) - 1);
    if (tx != 1)
        goto loc_5311;
    bx = si;
    push(cs);
    ds = pop();
}
void sub_447f() // 043e:009f
{
    CStackGuard sg(0, true);
    push(0x7777);
    si = ax;
    di = bx;
    dl = 0xff;
    al = memoryAGet(ds, 0x02be);
    if (al >= 0x02)
        goto loc_4496;
    dl = 0;
    if (al == 0)
        goto loc_4496;
    dl = memoryAGet(ds, 0x010d);
loc_4496: // 043e:00b6
    dh = cl;
    bl = 0;
    goto loc_552b;
    //   gap of 4238 bytes
loc_552b: // 043e:114b
    push(cs);
    ds = pop();
    sub_59d3();
    sub_5953();
    if (dl == 0xff)
        goto loc_554d;
    if (dl < 0x04)
        goto loc_553f;
    dl = 0x03;
loc_553f: // 043e:115f
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_554d;
    if (dl < 0x02)
        goto loc_554d;
    dl = 0x01;
loc_554d: // 043e:116d
    memoryASet(ds, 0x0e02, dl);
    bh = al;
    memoryASet16(ds, 0x0e03, bx);
    memoryASet16(ds, 0x0dee, sp);
    memoryASet(ds, 0x0e0a, 0x00);
    bp = sp;
    bp -= 0x0080;
    bl = dh;
    bx &= 0x0003;
    dh = memoryAGet(ds, bx + 2385);
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_557d;
    if (dh == 0)
        goto loc_557d;
    dh = 0xff;
loc_557d: // 043e:119d
    push(dx);
    ax = 0xffff;
    bp--;
    bp--;
    memoryASet16(ss, bp, ax);
    ax = memoryAGet16(ds, 0x03fa);
    ax -= di;
    bp--;
    bp--;
    memoryASet16(ss, bp, ax);
    memoryASet16(ds, 0x0df6, ax);
    memoryASet16(ds, 0x0dfa, 0x0000);
    ax = memoryAGet16(ds, 0x0400);
    memoryASet16(ds, 0x0dfe, ax);
    bp--;
    bp--;
    memoryASet16(ss, bp, si);
    memoryASet(ds, 0x0e06, 0x00);
    sub_5975();
    bp--;
    bp--;
    memoryASet16(ss, bp, di);
    cl = ~cl;
    dx = pop();
    sub_5923();
    sub_58ae();
    al = memoryAGet(es, di);
    al &= cl;
    ah = dh;
    ah &= cl;
    if (al == ah)
        goto loc_55e6;
    ch = 0;
    goto loc_55f0;
loc_55cb: // 043e:11eb
    bx = pop();
    memoryASet16(ds, 0x0df6, bx);
    ax = memoryAGet16(ds, 0x0df2);
    memoryASet16(ds, 0x0dfa, ax);
    ax = memoryAGet16(ds, 0x0df0);
    memoryASet16(ds, 0x0dfe, ax);
    cx = memoryAGet16(ss, bp);
    bp++;
    bp++;
    if (cx != 0xffff)
        goto loc_55f0;
loc_55e6: // 043e:1206
    sp = memoryAGet16(ds, 0x0dee);
    al = memoryAGet(ds, 0x0e0a);
    al = ror(al, 0x01);
    assert(pop() == 0x7777);
    return;
loc_55f0: // 043e:1210
    di = memoryAGet16(ss, bp);
    bp++;
    bp++;
    si = memoryAGet16(ss, bp);
    bp++;
    bp++;
    bx = memoryAGet16(ss, bp);
    bp++;
    bp++;
    sub_5a25();
    push(bx);
    al = ch;
    push(ax);
    sub_572d();
    sub_5684();
    ax = pop();
    if (!(al & 0x02))
        goto loc_5617;
    if (al & 0x80)
        goto loc_5623;
    goto loc_5630;
loc_5617: // 043e:1237
    if (memoryAGet(ds, 0x0e06) != 0x00)
        goto loc_562d;
    sub_5635();
    if (!flags.carry)
        goto loc_5628;
loc_5623: // 043e:1243
    sub_565b();
    goto loc_55cb;
loc_5628: // 043e:1248
    sub_5650();
    if (flags.carry)
        goto loc_5630;
loc_562d: // 043e:124d
    sub_565b();
loc_5630: // 043e:1250
    sub_566e();
    goto loc_55cb;
}
void sub_449d() // 043e:00bd
{
    CStackGuard sg(0, false);
    bh = bl;
    bl = al;
    if (al == 0xff)
        goto loc_44aa;
    if (bl == 0)
        goto loc_44aa;
    return;
loc_44aa: // 043e:00ca
    bh &= 0x0f;
    if (memoryAGet(ds, 0x0110) != 0x00)
        goto loc_44b7;
    bh |= 0x10;
loc_44b7: // 043e:00d7
    memoryASet(ds, 0x010f, bh);
    goto loc_4873;
    //   gap of 949 bytes
loc_4873: // 043e:0493
    if (memoryAGet(ds, 0x03f2) == 0x04)
        return;
    al = memoryAGet(ds, 0x010f);
    ah = 0x0b;
    bh = 0;
    al &= 0x1f;
    bl = al;
    interrupt(0x10);
}
void sub_44be() // 043e:00de
{
    CStackGuard sg(0, false);
    goto loc_44be;
loc_44aa: // 043e:00ca
    bh &= 0x0f;
    if (memoryAGet(ds, 0x0110) != 0x00)
        goto loc_44b7;
    bh |= 0x10;
loc_44b7: // 043e:00d7
    memoryASet(ds, 0x010f, bh);
    goto loc_4873;
loc_44be: // 043e:00de
    bh = memoryAGet(es, bx);
    goto loc_44aa;
    //   gap of 944 bytes
loc_4873: // 043e:0493
    if (memoryAGet(ds, 0x03f2) == 0x04)
        return;
    al = memoryAGet(ds, 0x010f);
    ah = 0x0b;
    bh = 0;
    al &= 0x1f;
    bl = al;
    interrupt(0x10);
}
void sub_44c3() // 043e:00e3
{
    CStackGuard sg(0, false);
    if (al != 0xff)
        goto loc_44d9;
    cx = 0x0008;
    di = 0x0a30;
loc_44cd: // 043e:00ed
    al = memoryAGet(es, bx);
    memoryASet(ds, di, al);
    di++;
    bx++;
    if (--cx)
        goto loc_44cd;
    ax = 0x0c0c;
loc_44d9: // 043e:00f9
    sub_46a2();
}
void sub_44dd() // 043e:00fd
{
    CStackGuard sg(0, false);
    ax = cx;
    mul(memoryAGet16(ds, 0x0115));
    bx = ax;
    cx = memoryAGet16(ds, 0x0117);
}
void sub_45b7() // 043e:01d7
{
    CStackGuard sg(0, false);
    if (al != 0x01)
        goto loc_45c0;
    cx = memoryAGet16(ds, 0x0189);
    return;
loc_45c0: // 043e:01e0
    push(cs);
    es = pop();
    if (al != 0x02)
        goto loc_45d3;
    al = 0x13;
    mul(cl);
    bl = al;
    bh = 0;
    bx += 0x018b;
    return;
loc_45d3: // 043e:01f3
    al = ch;
    ah = 0;
    ax++;
    memoryASet16(ds, 0x0189, ax);
    al = cl;
    bl = 0;
    if (al >= 0x04)
        goto loc_45e9;
    if (al < 0x02)
        goto loc_45eb;
    bl++;
loc_45e9: // 043e:0209
    al -= 0x02;
loc_45eb: // 043e:020b
    memoryASet(ds, 0x0110, bl);
    cl = al;
    memoryASet(ds, 0x010b, al);
    memoryASet(ds, 0x010a, 0xff);
    if (al >= 0x02)
        goto loc_4602;
    memoryASet(ds, 0x010a, 0x00);
loc_4602: // 043e:0222
    bl = cl;
    bl <<= 1;
    bh = 0;
    bx = memoryAGet16(ds, bx + 385);
    memoryASet16(ds, 0x0127, bx);
}
void sub_4611() // 043e:0231
{
    CStackGuard sg(0, false);
    al = memoryAGet(es, bx);
    al &= 0x0f;
    if (memoryAGet(ds, 0x0110) != 0x00)
        goto loc_461f;
    al |= 0x10;
loc_461f: // 043e:023f
    memoryASet(ds, 0x010f, al);
    al = memoryAGet(ds, 0x010b);
    goto loc_482a;
    //   gap of 514 bytes
loc_482a: // 043e:044a
    if (al < 0x07)
        goto loc_4830;
    al = 0x02;
loc_4830: // 043e:0450
    memoryASet(ds, 0x03f2, al);
    ah = 0x0a;
    mul(ah);
    bx = ax;
    bx += 0x0404;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x03f8, ax);
    memoryASet16(ds, 0x0400, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x03fa, ax);
    memoryASet16(ds, 0x0402, ax);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0x03f3, ax);
    ax = memoryAGet16(ds, bx + 6);
    memoryASet16(ds, 0x03f0, ax);
    callIndirect(cs, memoryAGet16(ds, bx + 8)); // 043e:047a
}
void sub_4622() // 043e:0242
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x010b);
    goto loc_482a;
    //   gap of 514 bytes
loc_482a: // 043e:044a
    if (al < 0x07)
        goto loc_4830;
    al = 0x02;
loc_4830: // 043e:0450
    memoryASet(ds, 0x03f2, al);
    ah = 0x0a;
    mul(ah);
    bx = ax;
    bx += 0x0404;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x03f8, ax);
    memoryASet16(ds, 0x0400, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x03fa, ax);
    memoryASet16(ds, 0x0402, ax);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0x03f3, ax);
    ax = memoryAGet16(ds, bx + 6);
    memoryASet16(ds, 0x03f0, ax);
    callIndirect(cs, memoryAGet16(ds, bx + 8)); // 043e:047a
}
void sub_4628() // 043e:0248
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x03f2);
    if (al < 0x03)
        goto loc_4647;
    if (al == 0x03)
        goto loc_4656;
    push(memoryAGet16(ds, 0x0400));
    push(memoryAGet16(ds, 0x0402));
    sub_4622();
    memoryASet16(ds, 0x0402, pop());
    memoryASet16(ds, 0x0400, pop());
    return;
loc_4647: // 043e:0267
    cx = 0;
    dh = 0x18;
    dl = 0x4f;
    bh = 0;
    al = 0;
    ah = 0x06;
    interrupt(0x10);
    return;
loc_4656: // 043e:0276
    ax = 0xa000;
    es = ax;
    cx = 0x4b00;
    flags.direction = false;
    ax = 0;
    di = ax;
    rep_stosw<MemAuto, DirAuto>();
}
void sub_4666() // 043e:0286
{
    CStackGuard sg(0, false);
    ax &= 0x0303;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4673;
    ax &= 0x0101;
loc_4673: // 043e:0293
    memoryASet16(ds, 0x010c, ax);
}
void sub_4677() // 043e:0297
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0111, ax);
    memoryASet16(ds, 0x0113, bx);
}
void sub_467f() // 043e:029f
{
    CStackGuard sg(0, false);
    push(cx);
    push(dx);
    cx = ax;
    dx = bx;
    tx = memoryAGet16(ds, 0x0111);
    memoryASet16(ds, 0x0111, ax);
    ax = tx;
    tx = memoryAGet16(ds, 0x0113);
    memoryASet16(ds, 0x0113, bx);
    bx = tx;
    sub_4693();
    dx = pop();
    cx = pop();
}
void sub_4693() // 043e:02b3
{
    CStackGuard sg(0, true);
    push(0x7777);
    si = memoryAGet16(ds, 0x010c);
    di = memoryAGet16(ds, 0x03c6);
    goto loc_49b8;
    //   gap of 794 bytes
loc_49b8: // 043e:05d8
    if (ax > memoryAGet16(ds, 0x03f8))
        goto loc_49d0;
    if (cx > memoryAGet16(ds, 0x03f8))
        goto loc_49d0;
    if (bx > memoryAGet16(ds, 0x03fa))
        goto loc_49d0;
    if (dx <= memoryAGet16(ds, 0x03fa))
        goto loc_49d1;
loc_49d0: // 043e:05f0
    assert(pop() == 0x7777);
    return;
loc_49d1: // 043e:05f1
    bp = sp;
    sp -= 0x0014;
    memoryASet16(ss, bp - 2, si);
    memoryASet16(ds, 0x03f6, di);
    if (ax < cx)
        goto loc_49e4;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = dx;
    dx = bx;
    bx = tx;
loc_49e4: // 043e:0604
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 6, bx);
    memoryASet(ss, bp - 20, 0x00);
    if (bx < dx)
        goto loc_49f8;
    tx = dx;
    dx = bx;
    bx = tx;
    memoryASet(ss, bp - 20, 0x80);
loc_49f8: // 043e:0618
    tx = cx;
    cx = ax;
    ax = tx;
    ax -= cx;
    memoryASet16(ss, bp - 12, ax);
    tx = dx;
    dx = bx;
    bx = tx;
    bx -= dx;
    memoryASet16(ss, bp - 14, bx);
    sub_4b1c();
    ax = memoryAGet16(ss, bp - 12);
    bx = memoryAGet16(ss, bp - 14);
    if (ax < bx)
        goto loc_4a2a;
    memoryASet16(ss, bp - 10, ax);
    bx <<= 1;
    memoryASet16(ss, bp - 14, bx);
    bx -= ax;
    memoryASet16(ss, bp - 8, bx);
    bx -= ax;
    memoryASet16(ss, bp - 12, bx);
    sub_4a42();
    goto loc_4aa8;
loc_4a2a: // 043e:064a
    memoryASet16(ss, bp - 10, bx);
    ax <<= 1;
    memoryASet16(ss, bp - 12, ax);
    ax -= bx;
    memoryASet16(ss, bp - 8, ax);
    ax -= bx;
    memoryASet16(ss, bp - 14, ax);
    sub_4a42();
    goto loc_4ae2;
    //   gap of 102 bytes
loc_4aa8: // 043e:06c8
    tx = bp;
    bp--;
    if (tx != 1)
        goto loc_4aaf;
    sp += 0x0014;
    assert(pop() == 0x7777);
    return;
loc_4aaf: // 043e:06cf
    if (dh & 0x80)
        goto loc_4abc;
    dx += di;
    callIndirect(cs, memoryAGet16(ds, 0x051e)); // 043e:06d6
    goto loc_4abe;
loc_4abc: // 043e:06dc
    dx += si;
loc_4abe: // 043e:06de
    if (al & 0x40)
        goto loc_4ac6;
    ah = ror(ah, 0x01);
    ch = ror(ch, 0x01);
loc_4ac6: // 043e:06e6
    ah = ror(ah, 0x01);
    ch = ror(ch, 0x01);
    if (ch & 0x80)
        goto loc_4ad0;
    bx++;
loc_4ad0: // 043e:06f0
    flags.carry = !!(memoryAGet16(ds, 0x03f6) & 0x8000);
    memoryASet16(ds, 0x03f6, rol(memoryAGet16(ds, 0x03f6), 0x0001));
    if (!flags.carry)
        goto loc_4ae0;
    cl = memoryAGet(es, bx);
    cl &= ch;
    cl |= ah;
    memoryASet(es, bx, cl);
loc_4ae0: // 043e:0700
    goto loc_4aa8;
loc_4ae2: // 043e:0702
    tx = bp;
    bp--;
    if (tx != 1)
        goto loc_4ae9;
    sp += 0x0014;
    assert(pop() == 0x7777);
    return;
loc_4ae9: // 043e:0709
    if (dh & 0x80)
        goto loc_4b04;
    dx += si;
    if (al & 0x40)
        goto loc_4af8;
    ah = ror(ah, 0x01);
    ch = ror(ch, 0x01);
loc_4af8: // 043e:0718
    ah = ror(ah, 0x01);
    ch = ror(ch, 0x01);
    if (ch & 0x80)
        goto loc_4b02;
    bx++;
loc_4b02: // 043e:0722
    goto loc_4b06;
loc_4b04: // 043e:0724
    dx += di;
loc_4b06: // 043e:0726
    callIndirect(cs, memoryAGet16(ds, 0x051e)); // 043e:0726
    flags.carry = !!(memoryAGet16(ds, 0x03f6) & 0x8000);
    memoryASet16(ds, 0x03f6, rol(memoryAGet16(ds, 0x03f6), 0x0001));
    if (!flags.carry)
        goto loc_4b1a;
    cl = memoryAGet(es, bx);
    cl &= ch;
    cl |= ah;
    memoryASet(es, bx, cl);
loc_4b1a: // 043e:073a
    goto loc_4ae2;
}
void sub_46a2() // 043e:02c2
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x02be, ax);
    bl = memoryAGet(ds, 0x010d);
    push(cs);
    es = pop();
    flags.direction = false;
    if (al < 0x02)
        goto loc_4705;
    al -= 0x02;
    ah = 0;
    cl = 0x03;
    ax <<= cl;
    si = 0x09e0;
    si += ax;
    di = 0x034c;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_46d3;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(ds, 0x034a, 0x0008);
    return;
loc_46d3: // 043e:02f3
    memoryASet16(ds, 0x034a, 0x0010);
    bh = memoryAGet(ds, 0x010d);
    cx = 0x0008;
loc_46e0: // 043e:0300
    lodsb<MemAuto, DirAuto>();
    sub_46f2();
    tl = al;
    al = dl;
    dl = tl;
    stosb<MemAuto, DirAuto>();
    al = dl;
    sub_46f2();
    al = dl;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_46e0;
    return;
    //   gap of 19 bytes
loc_4705: // 043e:0325
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4713;
    if (bl == 0)
        goto loc_4713;
    bx = 0x0003;
loc_4713: // 043e:0333
    if (al == 0x01)
        goto loc_4719;
    bx = 0;
loc_4719: // 043e:0339
    bx &= 0x0003;
    al = memoryAGet(ds, bx + 2385);
    di = 0x034c;
    cx = 0x0010;
    rep_stosb<MemAuto, DirAuto>();
}
void sub_46f2() // 043e:0312
{
    CStackGuard sg(0, false);
    dl = 0;
    bl = 0x04;
loc_46f6: // 043e:0316
    dl = rol(dl, 0x01);
    flags.carry = !!(dl & 0x80);
    dl = rol(dl, 0x01);
    al = rcl(al, 0x01);
    if (!flags.carry)
        goto loc_4700;
    dl |= bh;
loc_4700: // 043e:0320
    tl = bl;
    bl--;
    if (tl != 1)
        goto loc_46f6;
}
void sub_473c() // 043e:035c
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x011a) != 0x01)
        goto loc_4746;
    bx += cx;
    bx--;
loc_4746: // 043e:0366
    al = memoryAGet(es, bx);
    if (al == 0)
        return;
    push(es);
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x0111);
    cx = memoryAGet16(ds, 0x0113);
    sub_4e62();
    cx = pop();
    bx = pop();
    es = pop();
    dx = memoryAGet16(ds, 0x0115);
    if (memoryAGet(ds, 0x011a) != 0x01)
        goto loc_4770;
    memoryASet16(ds, 0x0113, memoryAGet16(ds, 0x0113) + dx);
    bx--;
    goto loc_4775;
loc_4770: // 043e:0390
    memoryASet16(ds, 0x0111, memoryAGet16(ds, 0x0111) + dx);
    bx++;
loc_4775: // 043e:0395
    if (--cx)
        goto loc_4746;
}
void sub_4778() // 043e:0398
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x0119, al);
    memoryASet(ds, 0x011a, ah);
    bx &= 0x00f8;
    memoryASet16(ds, 0x0115, bx);
    cx &= 0x00f8;
    memoryASet16(ds, 0x0117, cx);
    push(bx);
    push(cx);
    al = memoryAGet(ds, 0x010c);
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    sub_4e2a();
    cx = pop();
    bx = pop();
}
void sub_47b2() // 043e:03d2
{
    CStackGuard sg(0, false);
    if (al == 0x04)
        goto loc_47c0;
    ah = 0;
    al <<= 1;
    bx = ax;
    bx = memoryAGet16(ds, bx + 970);
loc_47c0: // 043e:03e0
    memoryASet16(ds, 0x03c6, bx);
    memoryASet16(ds, 0x03c8, cx);
}
void sub_4862() // 043e:0482
{
    CStackGuard sg(0, false);
    al = 0x01;
    push(ax);
    ax = 0x0004;
    interrupt(0x10);
    ax = pop();
    bh = 0x01;
    bl = al;
    ah = 0x0b;
    interrupt(0x10);
    if (memoryAGet(ds, 0x03f2) == 0x04)
        return;
    al = memoryAGet(ds, 0x010f);
    ah = 0x0b;
    bh = 0;
    al &= 0x1f;
    bl = al;
    interrupt(0x10);
}
void sub_4918() // 043e:0538
{
    CStackGuard sg(0, false);
    al ^= 0x01;
    if (!(al & 0x01))
        goto loc_4923;
    bx += 0x2000;
    return;
loc_4923: // 043e:0543
    bx -= 0x1fb0;
}
void sub_4928() // 043e:0548
{
    CStackGuard sg(0, false);
    al ^= 0x01;
    if (!(al & 0x01))
        goto loc_4933;
    bx += 0x1fb0;
    return;
loc_4933: // 043e:0553
    bx -= 0x2000;
}
void sub_4a42() // 043e:0662
{
    CStackGuard sg(0, false);
    bx = memoryAGet16(ss, bp - 16);
    dx = memoryAGet16(ss, bp - 8);
    di = memoryAGet16(ss, bp - 12);
    si = memoryAGet16(ss, bp - 14);
    ax = memoryAGet16(ss, bp - 6);
    al &= 0x03;
    if (memoryAGet(ds, 0x010b) >= 0x04)
        goto loc_4a5c;
    al &= 0x01;
loc_4a5c: // 043e:067c
    al |= memoryAGet(ss, bp - 20);
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4a68;
    al |= 0x40;
loc_4a68: // 043e:0688
    if (memoryAGet(ds, 0x03f5) == 0x00)
        goto loc_4a71;
    al |= 0x20;
loc_4a71: // 043e:0691
    ah = memoryAGet(ss, bp - 2);
    ch = memoryAGet(ss, bp - 18);
    bp = memoryAGet16(ss, bp - 10);
    bp++;
    flags.carry = !!(memoryAGet16(ds, 0x03f6) & 0x8000);
    memoryASet16(ds, 0x03f6, rol(memoryAGet16(ds, 0x03f6), 0x0001));
    if (!flags.carry)
        goto loc_4a8b;
    cl = memoryAGet(es, bx);
    cl &= ch;
    cl |= ah;
    memoryASet(es, bx, cl);
loc_4a8b: // 043e:06ab
    push(bx);
    bl = memoryAGet(ds, 0x010b);
    bl <<= 1;
    bl <<= 1;
    bh = 0;
    bx += 0x0520;
    if ((char)al >= 0)
        goto loc_4aa0;
    bx++;
    bx++;
loc_4aa0: // 043e:06c0
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x051e, bx);
    bx = pop();
}
void sub_4a8b() // 043e:06ab
{
    CStackGuard sg(0, false);
    push(bx);
    bl = memoryAGet(ds, 0x010b);
    bl <<= 1;
    bl <<= 1;
    bh = 0;
    bx += 0x0520;
    if ((char)al >= 0)
        goto loc_4aa0;
    bx++;
    bx++;
loc_4aa0: // 043e:06c0
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x051e, bx);
    bx = pop();
}
void sub_4b1c() // 043e:073c
{
    CStackGuard sg(0, false);
    cx = memoryAGet16(ss, bp - 4);
    dx = memoryAGet16(ss, bp - 6);
    al = memoryAGet(ds, 0x010b);
    if (al >= 0x03)
        goto loc_4b2d;
    dx &= 0x00fe;
loc_4b2d: // 043e:074d
    if (al < 0x04)
        goto loc_4b35;
    dx >>= 1;
    dx >>= 1;
loc_4b35: // 043e:0755
    ax = memoryAGet16(ds, 0x03f3);
    mul(dx);
    si = ax;
    dx = cx;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4b4c;
    cx = 0x0703;
    al = 0xfe;
    goto loc_4b51;
loc_4b4c: // 043e:076c
    cx = 0x0302;
    al = 0xfc;
loc_4b51: // 043e:0771
    ch &= dl;
    dx >>= cl;
    si += dx;
    ch++;
    ah = memoryAGet(ss, bp - 2);
    dh = al;
    al = memoryAGet(ds, 0x010a);
loc_4b61: // 043e:0781
    ah = ror(ah, 0x01);
    dh = ror(dh, 0x01);
    if (al != 0)
        goto loc_4b6d;
    ah = ror(ah, 0x01);
    dh = ror(dh, 0x01);
loc_4b6d: // 043e:078d
    tl = ch;
    ch--;
    if (tl != 1)
        goto loc_4b61;
    al = memoryAGet(ds, 0x010b);
    memoryASet(ss, bp - 2, ah);
    memoryASet(ss, bp - 18, dh);
    bx = si;
    if (al >= 0x03)
        goto loc_4b8b;
    if (!(memoryAGet16(ss, bp - 6) & 0x0001))
        goto loc_4b8b;
    bx += 0x2000;
loc_4b8b: // 043e:07ab
    memoryASet16(ss, bp - 16, bx);
    es = memoryAGet16(ds, 0x03f0);
    if (al < 0x04)
        return;
    bx = memoryAGet16(ss, bp - 6);
    bx &= 0x0003;
    bx <<= 1;
    es = memoryAGet16(ds, bx + 1380);
    if (al != 0x05)
        return;
    es = memoryAGet16(ds, bx + 1438);
}
void sub_4bd1() // 043e:07f1
{
    CStackGuard sg(0, false);
    al &= bl;
    bl = ~bl;
    bl &= memoryAGet(es, di);
    al |= bl;
    memoryASet(es, di, al);
}
void sub_4bde() // 043e:07fe
{
    CStackGuard sg(0, false);
    if (ax < cx)
        goto loc_4be3;
    tx = cx;
    cx = ax;
    ax = tx;
loc_4be3: // 043e:0803
    if (bx < dx)
        goto loc_4be9;
    tx = dx;
    dx = bx;
    bx = tx;
loc_4be9: // 043e:0809
    si = ax;
    memoryASet(ds, 0x07d2, al);
    di = bx;
    al = 0x03;
    push(cs);
    es = pop();
    bx &= 0x0007;
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_4c01;
    bx <<= 1;
loc_4c01: // 043e:0821
    bx += 0x034c;
    dx -= di;
    dx++;
    memoryASet16(ds, 0x07cc, dx);
    push(bx);
    bh = 0;
    bl = al;
    bl <<= 1;
    bx += 0x07d3;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x07cf, bx);
    bx = si;
    ax = cx;
    ax -= bx;
    memoryASet(ds, 0x07d1, al);
    ax >>= 1;
    ax >>= 1;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4c33;
    ax >>= 1;
loc_4c33: // 043e:0853
    ax++;
    bx = pop();
    push(ax);
    push(si);
    push(cx);
    push(es);
    push(bx);
    sub_4d35();
    memoryASet(ds, 0x07ce, bl);
    flags.direction = false;
    si = pop();
    ds = pop();
    cl = al;
    bx = pop();
    sub_4d0d();
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_4c54;
    bl++;
loc_4c54: // 043e:0874
    ch = memoryAGet(cs, bx + 2377);
    bx = pop();
    sub_4d0d();
    bh = memoryAGet(cs, bx + 2369);
    bl = ch;
    bp = pop();
    al = memoryAGet(cs, 0x07ce);
loc_4c69: // 043e:0889
    push(ax);
    push(bx);
    push(bp);
    push(di);
    if (memoryAGet(cs, 0x010a) == 0x00)
        goto loc_4c7a;
    lodsb<MemAuto, DirAuto>();
    ah = al;
    goto loc_4c85;
loc_4c7a: // 043e:089a
    lodsw<MemAuto, DirAuto>();
    if (memoryAGet(cs, 0x07d2) & 0x04)
        goto loc_4c85;
    tl = al;
    al = ah;
    ah = tl;
loc_4c85: // 043e:08a5
    push(si);
    dx = ax;
    sub_4cba();
    si = pop();
    ax = 0x0010;
    if (memoryAGet(cs, 0x010a) == 0x00)
        goto loc_4c9a;
    ax = 0x0008;
loc_4c9a: // 043e:08ba
    ax += 0x034c;
    if (si < ax)
        goto loc_4ca4;
    si = 0x034c;
loc_4ca4: // 043e:08c4
    di = pop();
    bp = pop();
    bx = pop();
    ax = pop();
    tx = di;
    di = bx;
    bx = tx;
    callIndirect(cs, memoryAGet16(ds, 0x051e)); // 043e:08ca
    tx = di;
    di = bx;
    bx = tx;
    tx = memoryAGet16(cs, 0x07cc);
    memoryASet16(cs, 0x07cc, memoryAGet16(cs, 0x07cc) - 1);
    if (tx != 1)
        goto loc_4c69;
    push(cs);
    ds = pop();
}
void sub_4cba() // 043e:08da
{
    CStackGuard sg(0, false);
    push(bx);
    al = dl;
    bp--;
    bl = bh;
    if (bp == 0)
        goto loc_4cd3;
loc_4cc4: // 043e:08e4
    callIndirect(cs, memoryAGet16(cs, 0x07cf)); // 043e:08e4
    bl = 0xff;
    di++;
    tl = dl;
    dl = dh;
    dh = tl;
    al = dl;
    tx = bp;
    bp--;
    if (tx != 1)
        goto loc_4cc4;
loc_4cd3: // 043e:08f3
    ah = dh;
    dh = 0x03;
    if (memoryAGet(cs, 0x010a) == 0x00)
        goto loc_4ce1;
    dh = 0x07;
loc_4ce1: // 043e:0901
    dl = memoryAGet(cs, 0x07d1);
    dl &= dh;
    dh -= dl;
    dl = cl;
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_4cf6;
    dl >>= 1;
loc_4cf6: // 043e:0916
    dx = pop();
    if ((char)dh >= (char)dl)
        goto loc_4d05;
    callIndirect(cs, memoryAGet16(cs, 0x07cf)); // 043e:091b
    di++;
    al = ah;
    bl = 0xff;
loc_4d05: // 043e:0925
    bl &= dl;
    callIndirect(cs, memoryAGet16(cs, 0x07cf)); // 043e:0927
}
void sub_4d0d() // 043e:092d
{
    CStackGuard sg(0, false);
    bx &= 0x0007;
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_4d1e;
    bl &= 0x03;
    bl <<= 1;
loc_4d1e: // 043e:093e
    al = bl;
}
void sub_4d35() // 043e:0955
{
    CStackGuard sg(0, false);
    al = 0;
    sub_4a8b();
    dx = di;
    push(di);
    al = memoryAGet(ds, 0x010b);
    if (al >= 0x03)
        goto loc_4d48;
    dx &= 0x00fe;
loc_4d48: // 043e:0968
    if (al < 0x04)
        goto loc_4d50;
    dx >>= 1;
    dx >>= 1;
loc_4d50: // 043e:0970
    ax = memoryAGet16(ds, 0x03f3);
    mul(dx);
    bx = ax;
    dx = si;
    cx = 0x0302;
    al = 0x3f;
    ah = memoryAGet(ds, 0x010a);
    if (ah == 0)
        goto loc_4d6b;
    cx = 0x0703;
    al = 0x7f;
loc_4d6b: // 043e:098b
    ch &= dl;
    dx >>= cl;
    bx += dx;
    if (ah != 0)
        goto loc_4d77;
    ch <<= 1;
loc_4d77: // 043e:0997
    cl = ch;
    al = ror(al, cl);
    tl = cl;
    cl = al;
    al = tl;
    di = bx;
    es = memoryAGet16(ds, 0x03f0);
    bx = pop();
    ah = memoryAGet(ds, 0x010b);
    if (ah >= 0x03)
        goto loc_4d97;
    bl &= 0x01;
    if (bl == 0)
        goto loc_4d96;
    di += 0x2000;
loc_4d96: // 043e:09b6
    return;
loc_4d97: // 043e:09b7
    if (ah < 0x04)
        return;
    bx &= 0x0003;
    bl <<= 1;
    es = memoryAGet16(ds, bx + 1380);
    if (ah != 0x05)
        goto loc_4daf;
    es = memoryAGet16(ds, bx + 1438);
loc_4daf: // 043e:09cf
    bl >>= 1;
}
void sub_4d37() // 043e:0957
{
    CStackGuard sg(0, false);
    sub_4a8b();
    dx = di;
    push(di);
    al = memoryAGet(ds, 0x010b);
    if (al >= 0x03)
        goto loc_4d48;
    dx &= 0x00fe;
loc_4d48: // 043e:0968
    if (al < 0x04)
        goto loc_4d50;
    dx >>= 1;
    dx >>= 1;
loc_4d50: // 043e:0970
    ax = memoryAGet16(ds, 0x03f3);
    mul(dx);
    bx = ax;
    dx = si;
    cx = 0x0302;
    al = 0x3f;
    ah = memoryAGet(ds, 0x010a);
    if (ah == 0)
        goto loc_4d6b;
    cx = 0x0703;
    al = 0x7f;
loc_4d6b: // 043e:098b
    ch &= dl;
    dx >>= cl;
    bx += dx;
    if (ah != 0)
        goto loc_4d77;
    ch <<= 1;
loc_4d77: // 043e:0997
    cl = ch;
    al = ror(al, cl);
    tl = cl;
    cl = al;
    al = tl;
    di = bx;
    es = memoryAGet16(ds, 0x03f0);
    bx = pop();
    ah = memoryAGet(ds, 0x010b);
    if (ah >= 0x03)
        goto loc_4d97;
    bl &= 0x01;
    if (bl == 0)
        goto loc_4d96;
    di += 0x2000;
loc_4d96: // 043e:09b6
    return;
loc_4d97: // 043e:09b7
    if (ah < 0x04)
        return;
    bx &= 0x0003;
    bl <<= 1;
    es = memoryAGet16(ds, bx + 1380);
    if (ah != 0x05)
        goto loc_4daf;
    es = memoryAGet16(ds, bx + 1438);
loc_4daf: // 043e:09cf
    bl >>= 1;
}
void sub_4e2a() // 043e:0a4a
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x0a45, ah);
    ah = al;
    ah &= 0x80;
    memoryASet(ds, 0x0a40, ah);
    al &= 0x03;
    if (bl != 0)
        goto loc_4e3f;
    bl++;
loc_4e3f: // 043e:0a5f
    memoryASet(ds, 0x0a41, bl);
    if (cl != 0)
        goto loc_4e49;
    cl++;
loc_4e49: // 043e:0a69
    memoryASet(ds, 0x0a42, cl);
    al = 0x08;
    mul(bl);
    ax -= 0x0002;
    memoryASet16(ds, 0x0a46, ax);
    al = 0x08;
    mul(cl);
    ax -= 0x0002;
    memoryASet16(ds, 0x0a48, ax);
}
void sub_4e62() // 043e:0a82
{
    CStackGuard sg(0, false);
    goto loc_4e62;
loc_4e61: // 043e:0a81
    return;
loc_4e62: // 043e:0a82
    if ((short)bx < 0)
        goto loc_4e61;
    di = memoryAGet16(ds, 0x0400);
    di -= memoryAGet16(ds, 0x0a46);
    if (bx >= di)
        goto loc_4e61;
    if ((short)cx < 0)
        goto loc_4e61;
    di = memoryAGet16(ds, 0x0402);
    di -= memoryAGet16(ds, 0x0a48);
    if (cx >= di)
        goto loc_4e61;
    push(ds);
    push(bx);
    push(cx);
    sub_4f1a();
    di = pop();
    si = pop();
    push(es);
    sub_4fb2();
    es = pop();
    memoryASet(cs, 0x0a44, 0x08);
loc_4e95: // 043e:0ab5
    ch = memoryAGet(cs, 0x0a42);
loc_4e9a: // 043e:0aba
    push(ax);
    push(bx);
    dl = memoryAGet(es, bp);
    di = 0x0008;
loc_4ea3: // 043e:0ac3
    cl = memoryAGet(cs, 0x0a41);
    sub_4ec3();
    dl = rol(dl, 0x01);
    tx = di;
    di--;
    if (tx != 1)
        goto loc_4ea3;
    bx = pop();
    sub_4eec();
    ax = pop();
    tl = ch;
    ch--;
    if (tl != 1)
        goto loc_4e9a;
    bp++;
    tl = memoryAGet(cs, 0x0a44);
    memoryASet(cs, 0x0a44, memoryAGet(cs, 0x0a44) - 1);
    if (tl != 1)
        goto loc_4e95;
    ds = pop();
}
void sub_4ec3() // 043e:0ae3
{
    CStackGuard sg(0, false);
loc_4ec3: // 043e:0ae3
    if (dl & 0x80)
        goto loc_4eca;
    goto loc_4ed2;
loc_4eca: // 043e:0aea
    dh = memoryAGet(ds, bx);
    dh &= ah;
    dh |= al;
    memoryASet(ds, bx, dh);
loc_4ed2: // 043e:0af2
    al = ror(al, 0x01);
    ah = ror(ah, 0x01);
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_4ee2;
    al = ror(al, 0x01);
    ah = ror(ah, 0x01);
loc_4ee2: // 043e:0b02
    if ((char)ah < 0)
        goto loc_4ee7;
    bx++;
loc_4ee7: // 043e:0b07
    tl = cl;
    cl--;
    if (tl != 1)
        goto loc_4ec3;
}
void sub_4eec() // 043e:0b0c
{
    CStackGuard sg(0, false);
    al = memoryAGet(cs, 0x0a43);
    if (memoryAGet(cs, 0x010b) >= 0x04)
        goto loc_4f02;
    callIndirect(cs, memoryAGet16(cs, 0x051e)); // 043e:0b18
    memoryASet(cs, 0x0a43, al);
    return;
loc_4f02: // 043e:0b22
    push(es);
    callIndirect(cs, memoryAGet16(cs, 0x051e)); // 043e:0b23
    memoryASet(cs, 0x0a43, al);
    ax = es;
    ds = ax;
    es = pop();
}
void sub_4f1a() // 043e:0b3a
{
    CStackGuard sg(0, false);
    if (al != 0x30)
        goto loc_4f20;
    al = 0x4f;
loc_4f20: // 043e:0b40
    ah = 0;
    bp = ax;
    bp <<= 1;
    bp <<= 1;
    bp <<= 1;
    if (al < 0x41)
        goto loc_4f32;
    if (al < 0x7b)
        goto loc_4f63;
loc_4f32: // 043e:0b52
    if (al < 0x80)
        goto loc_4f58;
    ax = 0x0000;
    es = ax;
    bx = 0x007c;
    bp -= 0x0400;
    ax = memoryAGet16(es, bx);
    if (ax == 0)
        goto loc_4f55;
    bp += ax;
    ax = memoryAGet16(es, bx + 2);
    es = ax;
    if (ax != 0)
        goto loc_4f69;
loc_4f55: // 043e:0b75
    bp = 0x0100;
loc_4f58: // 043e:0b78
    bp += 0xfa6e;
    ax = 0xf000;
    es = ax;
    goto loc_4f69;
loc_4f63: // 043e:0b83
    push(cs);
    es = pop();
    bp += 0x09f9;
loc_4f69: // 043e:0b89
    if (memoryAGet(ds, 0x0a45) == 0x00)
        return;
    ax = memoryAGet16(es, bp);
    bx = memoryAGet16(es, bp + 2);
    cx = memoryAGet16(es, bp + 4);
    dx = memoryAGet16(es, bp + 6);
    push(cs);
    es = pop();
    di = 0x0b32;
    bp = 0x0008;
loc_4f88: // 043e:0ba8
    flags.carry = al & 1;
    al >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = ah & 1;
    ah >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = bl & 1;
    bl >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = bh & 1;
    bh >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = cl & 1;
    cl >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = ch & 1;
    ch >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = dl & 1;
    dl >>= 1;
    si = rcl(si, 0x0001);
    flags.carry = dh & 1;
    dh >>= 1;
    si = rcl(si, 0x0001);
    tx = si;
    si = ax;
    ax = tx;
    stosb<MemAuto, DirAuto>();
    tx = si;
    si = ax;
    ax = tx;
    tx = bp;
    bp--;
    if (tx != 1)
        goto loc_4f88;
    bp = 0x0b32;
}
void sub_4fb2() // 043e:0bd2
{
    CStackGuard sg(0, false);
    sub_4d35();
    memoryASet(ds, 0x0a43, bl);
    al = 0xff;
    bl = memoryAGet(ds, 0x010c);
    bx &= 0x0003;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_4fd0;
    if (bl == 0)
        goto loc_4fd0;
    bl = 0x03;
loc_4fd0: // 043e:0bf0
    al = memoryAGet(ds, bx + 2385);
    ah = cl;
    ah = ~ah;
    al &= ah;
    push(es);
    ds = pop();
    ah = cl;
    bx = di;
}
void sub_5263() // 043e:0e83
{
    CStackGuard sg(0, false);
    lodsb<MemAuto, DirAuto>();
    ah = al;
loc_5266: // 043e:0e86
    lodsb<MemAuto, DirAuto>();
    ch = al;
    ax <<= cl;
    if (dx == 0)
        goto loc_5278;
    memoryASet(es, di, ah);
    di++;
    ah = ch;
    dx--;
    goto loc_5266;
loc_5278: // 043e:0e98
    ah &= bl;
    memoryASet(es, di, ah);
    di++;
}
void sub_5331() // 043e:0f51
{
    CStackGuard sg(0, false);
    push(bx);
    lodsb<MemAuto, DirAuto>();
    dx--;
    ah = 0;
    ch = al;
    bl = bh;
loc_533a: // 043e:0f5a
    ax >>= cl;
    if (dx == 0)
        goto loc_5350;
    callIndirect(cs, memoryAGet16(cs, 0x0e9f)); // 043e:0f60
    bl = 0xff;
    di++;
    ah = ch;
    lodsb<MemAuto, DirAuto>();
    ch = al;
    dx--;
    goto loc_533a;
loc_5350: // 043e:0f70
    dh = 0x03;
    if (memoryAGet(cs, 0x010a) == 0x00)
        goto loc_535c;
    dh = 0x07;
loc_535c: // 043e:0f7c
    dl = memoryAGet(cs, 0x0ea1);
    dl &= dh;
    dh -= dl;
    dl = cl;
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_5371;
    dl >>= 1;
loc_5371: // 043e:0f91
    dx = pop();
    if ((char)dh >= (char)dl)
        goto loc_5384;
    callIndirect(cs, memoryAGet16(cs, 0x0e9f)); // 043e:0f96
    di++;
    ah = ch;
    al = 0;
    ax >>= cl;
    bl = 0xff;
loc_5384: // 043e:0fa4
    bl &= dl;
    callIndirect(cs, memoryAGet16(cs, 0x0e9f)); // 043e:0fa6
}
void sub_538c() // 043e:0fac
{
    CStackGuard sg(0, false);
    bx &= 0x0007;
    if (memoryAGet(cs, 0x010a) != 0x00)
        goto loc_539d;
    bl &= 0x03;
    bl <<= 1;
loc_539d: // 043e:0fbd
    al = bl;
}
void sub_53bc() // 043e:0fdc
{
    CStackGuard sg(0, false);
    si = ax;
    di = bx;
    es = memoryAGet16(ds, 0x03f0);
    bl = memoryAGet(ds, 0x03f2);
    bh = 0;
    bl <<= 1;
    callIndirect(cs, memoryAGet16(ds, bx + 4046)); // 043e:0fec
    dl = al;
    dh = 0;
}
void sub_53d5() // 043e:0ff5
{
    dx &= 0x0003;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_53e3;
    dl &= 0x01;
loc_53e3: // 043e:1003
    si = ax;
    di = bx;
    es = memoryAGet16(ds, 0x03f0);
    bl = memoryAGet(ds, 0x03f2);
    bh = 0;
    bl <<= 1;
    callIndirect(cs, memoryAGet16(ds, bx + 4032)); // 043e:1013
}
// INJECT: Error: cannot inject carry flag in sub_5635()!
// INJECT: Error: cannot inject carry flag in sub_5635()!
void sub_5635() // 043e:1255
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x0df6);
    ax++;
    if (ax != bx)
        goto loc_5658;
    ax = memoryAGet16(ds, 0x0dfa);
    ax--;
    if ((short)memoryAGet16(ds, 0x0df2) <= (short)ax)
        goto loc_5658;
    ax = memoryAGet16(ds, 0x0dfe);
    ax++;
    stop(/*inject ret*/);
    return;
    //   gap of 8 bytes
loc_5658: // 043e:1278
    al = 0;
    stop(/*inject ret*/);
}
// INJECT: Error: cannot inject carry flag in sub_5650()!
// INJECT: Error: cannot inject carry flag in sub_5650()!
void sub_5650() // 043e:1270
{
    CStackGuard sg(0, false);
    goto loc_5650;
loc_563d: // 043e:125d
    ax = memoryAGet16(ds, 0x0dfa);
    ax--;
    if ((short)memoryAGet16(ds, 0x0df2) <= (short)ax)
        goto loc_5658;
    ax = memoryAGet16(ds, 0x0dfe);
    ax++;
    stop(/*inject ret*/);
    return;
loc_5650: // 043e:1270
    ax = memoryAGet16(ds, 0x0df6);
    ax--;
    if (ax == bx)
        goto loc_563d;
loc_5658: // 043e:1278
    al = 0;
    stop(/*inject ret*/);
}
void sub_565b() // 043e:127b
{
    CStackGuard sg(0, false);
    if (bx >= memoryAGet16(ds, 0x0dea))
        return;
    callIndirect(cs, memoryAGet16(ds, 0x0de2)); // 043e:1281
    sub_58ae();
    ch = 0x80;
    sub_57a1();
}
void sub_566e() // 043e:128e
{
    CStackGuard sg(0, false);
    sub_5909();
    if (bx == memoryAGet16(ds, 0x0de8))
        return;
    callIndirect(cs, memoryAGet16(ds, 0x0de0)); // 043e:1297
    sub_58ae();
    ch = 0;
    sub_57a1();
}
void sub_5684() // 043e:12a4
{
    CStackGuard sg(0, false);
    ch = memoryAGet(es, di);
    if (si == memoryAGet16(ds, 0x03fc))
        goto loc_56a6;
    si--;
    cl = rol(cl, 0x01);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_5699;
    cl = rol(cl, 0x01);
loc_5699: // 043e:12b9
    if (!(cl & 0x01))
        goto loc_56a6;
    di--;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    ch = memoryAGet(es, di);
loc_56a6: // 043e:12c6
    al = ch;
    al &= cl;
    ah = dh;
    ah &= cl;
    if (al == ah)
        goto loc_56ea;
    al = dl;
    al &= cl;
    ah = cl;
    ah = ~ah;
    ch &= ah;
    ch |= al;
    if (si == memoryAGet16(ds, 0x03fc))
        goto loc_56ea;
    si--;
    cl = rol(cl, 0x01);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_56d0;
    cl = rol(cl, 0x01);
loc_56d0: // 043e:12f0
    if (!(cl & 0x01))
        goto loc_56e0;
    memoryASet(es, di, ch);
    di--;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    ch = memoryAGet(es, di);
loc_56e0: // 043e:1300
    if (!(cl & 0x01))
        goto loc_56a6;
    sub_570e();
    goto loc_56a6;
loc_56ea: // 043e:130a
    memoryASet(es, di, ch);
    si++;
    cl = ror(cl, 0x01);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_56f9;
    cl = ror(cl, 0x01);
loc_56f9: // 043e:1319
    if (!(cl & 0x80))
        goto loc_5706;
    di++;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    ch = memoryAGet(es, di);
loc_5706: // 043e:1326
    memoryASet16(ds, 0x0df2, si);
    sub_5891();
}
void sub_570e() // 043e:132e
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x0e05);
loc_5711: // 043e:1331
    ch = memoryAGet(es, di);
    if (ch != al)
        return;
    memoryASet(es, di, dl);
    if ((short)si < (short)memoryAGet16(ds, 0x0de4))
        return;
    si -= memoryAGet16(ds, 0x0dec);
    di--;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    goto loc_5711;
}
void sub_572d() // 043e:134d
{
    CStackGuard sg(0, false);
    sub_5891();
    ch = memoryAGet(es, di);
loc_5733: // 043e:1353
    al = ch;
    al &= cl;
    ah = dh;
    ah &= cl;
    if (al == ah)
        goto loc_5777;
    al = dl;
    al &= cl;
    ah = cl;
    ah = ~ah;
    ch &= ah;
    ch |= al;
    if ((short)si >= (short)memoryAGet16(ds, 0x0400))
        goto loc_5777;
    si++;
    cl = ror(cl, 0x01);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_575d;
    cl = ror(cl, 0x01);
loc_575d: // 043e:137d
    if (!(cl & 0x80))
        goto loc_576d;
    memoryASet(es, di, ch);
    di++;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    ch = memoryAGet(es, di);
loc_576d: // 043e:138d
    if (!(cl & 0x80))
        goto loc_5733;
    sub_5782();
    goto loc_5733;
loc_5777: // 043e:1397
    memoryASet(es, di, ch);
    si--;
    memoryASet16(ds, 0x0df0, si);
    goto loc_5909;
    //   gap of 391 bytes
loc_5909: // 043e:1529
    si = memoryAGet16(ds, 0x0e0b);
    bx = memoryAGet16(ds, 0x0e0d);
    di = memoryAGet16(ds, 0x0e0f);
    cl = memoryAGet(ds, 0x0e11);
    ax = memoryAGet16(ds, 0x0e08);
    memoryASet(ds, 0x0e07, ah);
    dl = al;
}
void sub_5782() // 043e:13a2
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x0e05);
loc_5785: // 043e:13a5
    ch = memoryAGet(es, di);
    if (ch != al)
        return;
    memoryASet(es, di, dl);
    if (si >= memoryAGet16(ds, 0x0de6))
        return;
    si += memoryAGet16(ds, 0x0dec);
    di++;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    goto loc_5785;
}
void sub_57a1() // 043e:13c1
{
    CStackGuard sg(0, false);
    ch &= 0x80;
    goto loc_57bf;
loc_57a6: // 043e:13c6
    si++;
    cl = ror(cl, 0x01);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_57b2;
    cl = ror(cl, 0x01);
loc_57b2: // 043e:13d2
    if (!(cl & 0x80))
        goto loc_57bf;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    di++;
    sub_586a();
loc_57bf: // 043e:13df
    al = memoryAGet(es, di);
    al &= cl;
    ah = dh;
    ah &= cl;
    if (al != ah)
        goto loc_57d1;
    ch &= 0xfe;
    goto loc_582f;
loc_57d1: // 043e:13f1
    if (memoryAGet(ds, 0x0e02) != 0xff)
        goto loc_57e0;
    ah = dl;
    ah |= memoryAGet(ds, 0x0e07);
    if (!ah)
        goto loc_57ed;
loc_57e0: // 043e:1400
    if (memoryAGet(ds, 0x0e03) == 0x00)
        goto loc_57f7;
    if (dl != memoryAGet(ds, 0x0e04))
        goto loc_57f7;
loc_57ed: // 043e:140d
    ch |= 0x02;
    memoryASet(ds, 0x0e06, 0xff);
    goto loc_580e;
loc_57f7: // 043e:1417
    if (!(cl & 0x80))
        goto loc_5806;
    sub_583e();
    if (!flags.zero)
        goto loc_5806;
    ch &= 0xfe;
    goto loc_582f;
loc_5806: // 043e:1426
    ah = dl;
    ah &= cl;
    if (ah == al)
        goto loc_582f;
loc_580e: // 043e:142e
    if (ch & 0x01)
        goto loc_582f;
    ch |= 0x01;
    if (bp < 0x000e)
        goto loc_5838;
    bp--;
    bp--;
    memoryASet16(ss, bp, bx);
    bp--;
    bp--;
    memoryASet16(ss, bp, si);
    bp--;
    bp--;
    memoryASet16(ss, bp, di);
    bp--;
    bp--;
    memoryASet16(ss, bp, cx);
loc_582f: // 043e:144f
    if (si >= memoryAGet16(ds, 0x0df0))
        return;
    goto loc_57a6;
loc_5838: // 043e:1458
    memoryASet(ds, 0x0e0a, 0xff);
}
void sub_583e() // 043e:145e
{
    CStackGuard sg(0, false);
    flags.zero = dl == memoryAGet(es, di);
    if (dl != memoryAGet(es, di))
        return;
    ax = memoryAGet16(ds, 0x0df0);
    ax -= memoryAGet16(ds, 0x0dec);
loc_584a: // 043e:146a
    if (dl != memoryAGet(es, di))
        goto loc_585e;
    if ((short)si > (short)ax)
        goto loc_585e;
    si += memoryAGet16(ds, 0x0dec);
    di++;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    goto loc_584a;
loc_585e: // 043e:147e
    al = memoryAGet(es, di);
    al &= cl;
    ah = dh;
    ah &= cl;
    flags.zero = ah == al;
}
void sub_586a() // 043e:148a
{
    CStackGuard sg(0, false);
    if (!(ch & 0x01))
        return;
    ax = memoryAGet16(ds, 0x0df0);
    ax -= memoryAGet16(ds, 0x0dec);
    push(cx);
    ch = memoryAGet(ds, 0x0e05);
loc_587b: // 043e:149b
    if (ch != memoryAGet(es, di))
        goto loc_588f;
    if (si >= ax)
        goto loc_588f;
    si += memoryAGet16(ds, 0x0dec);
    di++;
    tl = memoryAGet(ds, 0x0e07);
    memoryASet(ds, 0x0e07, dl);
    dl = tl;
    goto loc_587b;
loc_588f: // 043e:14af
    cx = pop();
}
void sub_5891() // 043e:14b1
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0e0b, si);
    memoryASet16(ds, 0x0e0d, bx);
    memoryASet16(ds, 0x0e0f, di);
    memoryASet(ds, 0x0e11, cl);
    sub_58ae();
    al = dl;
    ah = memoryAGet(ds, 0x0e07);
    memoryASet16(ds, 0x0e08, ax);
}
void sub_58ae() // 043e:14ce
{
    CStackGuard sg(0, false);
    ax = bx;
    bl = memoryAGet(ds, 0x0e02);
    if (bl == 0xff)
        goto loc_58d5;
    bx &= 0x0003;
    dl = memoryAGet(ds, bx + 2385);
    bx = ax;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_58d0;
    if (dl == 0)
        goto loc_58d0;
    dl = 0xff;
loc_58d0: // 043e:14f0
    memoryASet(ds, 0x0e07, dl);
    return;
loc_58d5: // 043e:14f5
    push(ax);
    push(dx);
    ax = -ax;
    ax += memoryAGet16(ds, 0x03fa);
    ax &= 0x0007;
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_58e9;
    ax <<= 1;
loc_58e9: // 043e:1509
    bx = ax;
    dx = pop();
    ax = memoryAGet16(ds, bx + 844);
    dl = al;
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_58fb;
    ah = al;
loc_58fb: // 043e:151b
    if (si & 0x0004)
        goto loc_5903;
    tl = dl;
    dl = ah;
    ah = tl;
loc_5903: // 043e:1523
    memoryASet(ds, 0x0e07, ah);
    bx = pop();
}
void sub_5909() // 043e:1529
{
    CStackGuard sg(0, false);
    si = memoryAGet16(ds, 0x0e0b);
    bx = memoryAGet16(ds, 0x0e0d);
    di = memoryAGet16(ds, 0x0e0f);
    cl = memoryAGet(ds, 0x0e11);
    ax = memoryAGet16(ds, 0x0e08);
    memoryASet(ds, 0x0e07, ah);
    dl = al;
}
void sub_5923() // 043e:1543
{
    CStackGuard sg(0, false);
    al = memoryAGet(es, di);
    if (memoryAGet(ds, 0x010a) != 0x00)
        goto loc_5945;
    memoryASet(ds, 0x0e05, al);
    al ^= dh;
    ah = 0x03;
loc_5934: // 043e:1554
    if (!(ah & al))
        goto loc_5949;
    ah <<= 1;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_5934;
    return;
loc_593f: // 043e:155f
    memoryASet(ds, 0x0e05, 0x00);
    return;
loc_5945: // 043e:1565
    if (al == 0)
        goto loc_593f;
loc_5949: // 043e:1569
    if (dh != 0)
        goto loc_593f;
    memoryASet(ds, 0x0e05, 0xff);
}
void sub_5953() // 043e:1573
{
    CStackGuard sg(0, false);
    if (dl != 0xff)
        return;
    push(bx);
    push(cx);
    push(ax);
    bx = 0x034c;
    cx = memoryAGet16(ds, 0x034a);
    if (cx == 0)
        goto loc_596f;
    al = 0;
loc_5966: // 043e:1586
    al |= memoryAGet(ds, bx);
    bx++;
    if (--cx)
        goto loc_5966;
    if (al != 0)
        goto loc_5971;
loc_596f: // 043e:158f
    dl = 0;
loc_5971: // 043e:1591
    ax = pop();
    cx = pop();
    bx = pop();
}
void sub_5975() // 043e:1595
{
    CStackGuard sg(0, false);
    sub_4d37();
    push(ax);
    memoryASet16(ds, 0x0dec, 0x0004);
    if (memoryAGet(ds, 0x010a) == 0x00)
        goto loc_598c;
    memoryASet16(ds, 0x0dec, 0x0008);
loc_598c: // 043e:15ac
    ax = memoryAGet16(ds, 0x03fc);
    ax += memoryAGet16(ds, 0x0dec);
    memoryASet16(ds, 0x0de4, ax);
    ax = memoryAGet16(ds, 0x0400);
    ax -= memoryAGet16(ds, 0x0dec);
    ax++;
    memoryASet16(ds, 0x0de6, ax);
    ax = memoryAGet16(ds, 0x03fa);
    ax -= memoryAGet16(ds, 0x0402);
    memoryASet16(ds, 0x0de8, ax);
    ax = memoryAGet16(ds, 0x03fa);
    ax -= memoryAGet16(ds, 0x03fe);
    memoryASet16(ds, 0x0dea, ax);
    ax = pop();
}
void sub_59d3() // 043e:15f3
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    bl = memoryAGet(ds, 0x03f2);
    bl <<= 1;
    bl <<= 1;
    bh = 0;
    bx += 0x15d7;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x0de0, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x0de2, ax);
    bx = pop();
    ax = pop();
}
void sub_5a25() // 043e:1645
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x03f2);
    if (al < 0x04)
        goto loc_5a52;
    if (al >= 0x06)
        goto loc_5a52;
    push(bx);
    bl = ~bl;
    bx &= 0x0003;
    if (al == 0x05)
        goto loc_5a72;
    goto loc_5a4a;
    //   gap of 13 bytes
loc_5a4a: // 043e:166a
    bl <<= 1;
    es = memoryAGet16(cs, bx + 1380);
    bx = pop();
loc_5a52: // 043e:1672
    return;
    //   gap of 31 bytes
loc_5a72: // 043e:1692
    bl <<= 1;
    es = memoryAGet16(cs, bx + 1438);
    bx = pop();
}
void sub_5af1() // 01ed:3c21
{
    CStackGuard sg(0, false);
    interrupt(0x11);
}
void sub_5b0b() // 01ed:3c3b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = memoryAGet(ss, bp + 4);
    interrupt(0x16);
    if (!flags.zero)
        goto loc_5b1d;
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_5b1d;
    ax = 0;
loc_5b1d: // 01ed:3c4d
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b1f() // 01ed:3c4f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = sp;
    dx -= 0x0100;
    if (ax >= dx)
        goto loc_5b34;
    memoryASet16(ds, 0x008e, ax);
    goto loc_5b3d;
loc_5b34: // 01ed:3c64
    memoryASet16(ds, 0x0088, 0x0008);
    ax = 0xffff;
loc_5b3d: // 01ed:3c6d
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b3f() // 01ed:3c6f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    flags.carry = (ax + memoryAGet16(ds, 0x008e)) >= 0x10000;
    ax += memoryAGet16(ds, 0x008e);
    dx += flags.carry;
    cx = ax;
    flags.carry = (cx + 0x0100) >= 0x10000;
    cx += 0x0100;
    dx += flags.carry;
    if (dx)
        goto loc_5b66;
    if (cx >= sp)
        goto loc_5b66;
    tx = memoryAGet16(ds, 0x008e);
    memoryASet16(ds, 0x008e, ax);
    ax = tx;
    goto loc_5b6f;
loc_5b66: // 01ed:3c96
    memoryASet16(ds, 0x0088, 0x0008);
    ax = 0xffff;
loc_5b6f: // 01ed:3c9f
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b71() // 01ed:3ca1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 4));
    sub_5b1f();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b8d() // 01ed:3cbd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 6);
    ah = 0x3e;
    bx = si;
    interrupt(0x21);
    if (flags.carry)
        goto loc_5ba8;
    bx <<= 1;
    memoryASet16(ds, bx + 1000, 0xffff);
    ax = 0;
    goto loc_5bac;
loc_5ba8: // 01ed:3cd8
    push(ax);
    sub_61c2();
loc_5bac: // 01ed:3cdc
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_5baf() // 01ed:3cdf
{
    CStackGuard sg(6, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet(ss, bp - 3, 0x00);
    sub_6fb0();
    ah = 0x00;
    si = ax;
    sub_6fb0();
    cx = 0x0008;
    ax >>= cl;
    ah = 0x00;
    di = ax;
loc_5bce: // 01ed:3cfe
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - 1);
    if (ax)
        goto loc_5bdb;
    goto loc_5cd4;
loc_5bdb: // 01ed:3d0b
    bx = memoryAGet16(ss, bp + 12);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    al = memoryAGet(ds, bx);
    memoryASet(ss, bp - 3, al);
    ah = 0x00;
    if (ax > 0x000d)
        goto loc_5c40;
    bx = ax;
    bx <<= 1;
    callIndirect(cs, memoryAGet16(cs, bx + 15654)); // 01ed:3d21
    return;
    //   gap of 74 bytes
loc_5c40: // 01ed:3d70
    if (memoryAGet(ds, 0x037b) != 0x00)
        goto loc_5c73;
    if (memoryAGet16(ds, 0x0381) == 0x0000)
        goto loc_5c73;
    ah = memoryAGet(ds, 0x0376);
    al = memoryAGet(ss, bp - 3);
    memoryASet16(ss, bp - 2, ax);
    ax = si;
    ax++;
    push(ax);
    ax = di;
    ax++;
    push(ax);
    sub_6f15();
    push(dx);
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_6f38();
    goto loc_5c93;
loc_5c73: // 01ed:3da3
    ax = si;
    dl = al;
    ax = di;
    dh = al;
    ah = 0x02;
    bh = 0x00;
    sub_5d53();
    bl = memoryAGet(ds, 0x0376);
    al = memoryAGet(ss, bp - 3);
    ah = 0x09;
    bh = 0x00;
    cx = 0x0001;
    sub_5d53();
loc_5c93: // 01ed:3dc3
    si++;
    al = memoryAGet(ds, 0x0374);
    ah = 0x00;
    if ((short)ax < (short)si)
        goto loc_5ca0;
    goto loc_5bce;
loc_5ca0: // 01ed:3dd0
    al = memoryAGet(ds, 0x0372);
    ah = 0x00;
    si = ax;
    di++;
    ax = di;
    dl = memoryAGet(ds, 0x0375);
    dh = 0x00;
    if ((short)ax > (short)dx)
        goto loc_5cb7;
    goto loc_5bce;
loc_5cb7: // 01ed:3de7
    al = 0x06;
    push(ax);
    push(memoryAGet16(ds, 0x0372));
    push(memoryAGet16(ds, 0x0373));
    push(memoryAGet16(ds, 0x0374));
    push(memoryAGet16(ds, 0x0375));
    al = 0x01;
    push(ax);
    sub_658a();
    di--;
    goto loc_5bce;
loc_5cd4: // 01ed:3e04
    ax = si;
    dl = al;
    ax = di;
    dh = al;
    ah = 0x02;
    bh = 0x00;
    sub_5d53();
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_5d06() // 01ed:3e36
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp + 4));
    sub_6a2e();
    cx = pop();
    push(ax);
    ax = 0;
    push(ax);
    sub_5baf();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5d1c() // 01ed:3e4c
{
    CStackGuard sg(6, true);
    push(0x7777);
    push(bp);
    bp = sp;
loc_5d1f: // 01ed:3e4f
    bx = memoryAGet16(ss, bp + 4);
    if (memoryAGet(ds, bx) == 0x00)
        goto loc_5d3b;
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 1);
    al = memoryAGet(ds, bx);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) + 1);
    if (al == memoryAGet(es, bx))
        goto loc_5d1f;
    ax = 0;
    goto loc_5d3e;
loc_5d3b: // 01ed:3e6b
    ax = 0x0001;
loc_5d3e: // 01ed:3e6e
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_5d42() // 01ed:3e72
{
    CStackGuard sg(0, false);
    ax = 0x1130;
    bh = 0x00;
    dl = 0xff;
    sub_5d53();
    al = dl;
    al++;
    ah = 0x00;
}
void sub_5d53() // 01ed:3e83
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    memoryASet16(ds, 0x0a92, bp);
    interrupt(0x10);
    bp = memoryAGet16(ds, 0x0a92);
    di = pop();
    si = pop();
}
void sub_5d62() // 01ed:3e92
{
    CStackGuard sg(0, false);
    ah = 0x0f;
    sub_5d53();
    push(ax);
    sub_5d7f();
    cx = pop();
    ah = 0x08;
    bh = 0x00;
    sub_5d53();
    ah &= 0x7f;
    memoryASet(ds, 0x0377, ah);
    memoryASet(ds, 0x0376, ah);
}
void sub_5d7f() // 01ed:3eaf
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    if (al <= 0x03)
        goto loc_5d8f;
    if (al == 0x07)
        goto loc_5d8f;
    al = 0x03;
loc_5d8f: // 01ed:3ebf
    memoryASet(ds, 0x0378, al);
    ah = 0x0f;
    sub_5d53();
    al = al;
    if (al == memoryAGet(ds, 0x0378))
        goto loc_5daf;
    al = memoryAGet(ds, 0x0378);
    ah = 0x00;
    sub_5d53();
    ah = 0x0f;
    sub_5d53();
    memoryASet(ds, 0x0378, al);
loc_5daf: // 01ed:3edf
    memoryASet(ds, 0x037a, ah);
    if (memoryAGet(ds, 0x0378) <= 0x03)
        goto loc_5dc6;
    if (memoryAGet(ds, 0x0378) == 0x07)
        goto loc_5dc6;
    ax = 0x0001;
    goto loc_5dc8;
loc_5dc6: // 01ed:3ef6
    ax = 0;
loc_5dc8: // 01ed:3ef8
    memoryASet(ds, 0x037b, al);
    memoryASet(ds, 0x0379, 0x19);
    if (memoryAGet(ds, 0x0378) == 0x07)
        goto loc_5df6;
    dx = 0xf000;
    ax = 0xffea;
    push(dx);
    push(ax);
    ax = 0x0383;
    push(ax);
    sub_5d1c();
    if (ax)
        goto loc_5df6;
    sub_5d42();
    if (ax)
        goto loc_5df6;
    ax = 0x0001;
    goto loc_5df8;
loc_5df6: // 01ed:3f26
    ax = 0;
loc_5df8: // 01ed:3f28
    memoryASet(ds, 0x037c, al);
    if (memoryAGet(ds, 0x0378) != 0x07)
        goto loc_5e07;
    ax = 0xb000;
    goto loc_5e0a;
loc_5e07: // 01ed:3f37
    ax = 0xb800;
loc_5e0a: // 01ed:3f3a
    memoryASet16(ds, 0x037f, ax);
    memoryASet16(ds, 0x037d, 0x0000);
    al = 0x00;
    memoryASet(ds, 0x0373, al);
    memoryASet(ds, 0x0372, al);
    al = memoryAGet(ds, 0x037a);
    al += 0xff;
    memoryASet(ds, 0x0374, al);
    memoryASet(ds, 0x0375, 0x18);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5e4a() // 01ed:3f7a
{
    CStackGuard sg(0, true);
    push(0x7777);
    sp--;
    sp--;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    push(es);
    cx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(cs, 0x3f78);
    if (ax)
        goto loc_5e81;
    ax = 0x0040;
    es = ax;
    bx = memoryAGet16(es, 0x006c);
    sub_5ea5();
    bx -= memoryAGet16(es, 0x006c);
    bx = -bx;
    ax = 0x0037;
    mul(bx);
    if (cx <= ax)
        goto loc_5e99;
    cx -= ax;
    ax = memoryAGet16(cs, 0x3f78);
loc_5e81: // 01ed:3fb1
    bx = 0;
    es = bx;
    dl = memoryAGet(es, bx);
    if (cx == 0)
        goto loc_5e99;
loc_5e8a: // 01ed:3fba
    si = cx;
    cx = ax;
loc_5e8e: // 01ed:3fbe
    if (dl != memoryAGet(es, bx))
        goto loc_5e93;
loc_5e93: // 01ed:3fc3
    if (--cx)
        goto loc_5e8e;
    cx = si;
    if (--cx)
        goto loc_5e8a;
loc_5e99: // 01ed:3fc9
    ax = memoryAGet16(cs, 0x3f78);
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    sp++;
    sp++;
    assert(pop() == 0x7777);
}
void sub_5ea5() // 01ed:3fd5
{
    CStackGuard sg(0, false);
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = 0x0040;
    es = ax;
    bx = 0x006c;
    al = memoryAGet(es, bx);
    cx = 0xffff;
loc_5eb7: // 01ed:3fe7
    dl = memoryAGet(es, bx);
    if (al == dl)
        goto loc_5eb7;
loc_5ebe: // 01ed:3fee
    if (dl != memoryAGet(es, bx))
        goto loc_5ec5;
    if (--cx)
        goto loc_5ebe;
loc_5ec5: // 01ed:3ff5
    cx = -cx;
    cx--;
    ax = 0x0037;
    tx = cx;
    cx = ax;
    ax = tx;
    dx = 0;
    div(cx);
    memoryASet16(cs, 0x3f78, ax);
loc_5ed4: // 01ed:4004
    al = memoryAGet(es, bx);
    cx = 0xffff;
loc_5eda: // 01ed:400a
    dl = memoryAGet(es, bx);
    if (al == dl)
        goto loc_5eda;
    push(bx);
    push(dx);
    ax = 0x0037;
    push(ax);
    sub_5e4a();
    ax = pop();
    dx = pop();
    bx = pop();
    if (dl == memoryAGet(es, bx))
        goto loc_5ef9;
    memoryASet16(cs, 0x3f78, memoryAGet16(cs, 0x3f78) - 1);
    goto loc_5ed4;
loc_5ef9: // 01ed:4029
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_5eff() // 01ed:402f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
loc_5f02: // 01ed:4032
    ax = memoryAGet16(ds, 0x0370);
    memoryASet16(ds, 0x0370, memoryAGet16(ds, 0x0370) - 1);
    if (!ax)
        goto loc_5f19;
    bx = memoryAGet16(ds, 0x0370);
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, bx + 2642)); // 01ed:4043
    goto loc_5f02;
loc_5f19: // 01ed:4049
    callIndirect(cs, memoryAGet16(ds, 0x03e2)); // 01ed:4049
    callIndirect(cs, memoryAGet16(ds, 0x03e4)); // 01ed:404d
    callIndirect(cs, memoryAGet16(ds, 0x03e6)); // 01ed:4051
    push(memoryAGet16(ss, bp + 4));
    sub_1fe5();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5f2e() // 01ed:405e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 8) != 0x0000)
        goto loc_5f3c;
    goto loc_5fd0;
loc_5f3c: // 01ed:406c
    di = memoryAGet16(ss, bp + 8);
    di += 0xfffe;
    si = memoryAGet16(ds, 0x047c);
    goto loc_5f5d;
loc_5f48: // 01ed:4078
    ax = memoryAGet16(ds, si + 2);
    if (ax > si)
        goto loc_5f5a;
    if (di > si)
        goto loc_5f68;
    ax = memoryAGet16(ds, si + 2);
    if (ax > di)
        goto loc_5f68;
loc_5f5a: // 01ed:408a
    si = memoryAGet16(ds, si + 2);
loc_5f5d: // 01ed:408d
    if (di <= si)
        goto loc_5f48;
    ax = memoryAGet16(ds, si + 2);
    if (ax <= di)
        goto loc_5f48;
loc_5f68: // 01ed:4098
    ax = memoryAGet16(ds, di);
    ax += di;
    if (ax != memoryAGet16(ds, si + 2))
        goto loc_5f83;
    bx = memoryAGet16(ds, si + 2);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di, memoryAGet16(ds, di) + ax);
    bx = memoryAGet16(ds, si + 2);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, di + 2, ax);
    goto loc_5f89;
loc_5f83: // 01ed:40b3
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, ax);
loc_5f89: // 01ed:40b9
    ax = memoryAGet16(ds, si);
    ax += si;
    if (ax != di)
        goto loc_5f9f;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 2, ax);
    di = si;
    goto loc_5fa2;
loc_5f9f: // 01ed:40cf
    memoryASet16(ds, si + 2, di);
loc_5fa2: // 01ed:40d2
    ax = 0;
    push(ax);
    push(ax);
    sub_5b3f();
    sp = bp;
    dx = memoryAGet16(ds, di);
    dx += di;
    if (ax != dx)
        goto loc_5fcc;
    si = di;
    goto loc_5fba;
loc_5fb7: // 01ed:40e7
    si = memoryAGet16(ds, si + 2);
loc_5fba: // 01ed:40ea
    ax = memoryAGet16(ds, si + 2);
    if (ax != di)
        goto loc_5fb7;
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 2, ax);
    push(di);
    sub_5b71();
    cx = pop();
loc_5fcc: // 01ed:40fc
    memoryASet16(ds, 0x047c, si);
loc_5fd0: // 01ed:4100
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_5fd4() // 01ed:4104
{
    CStackGuard sg(0, false);
    ax = 0x0700;
    tl = memoryAGet(ds, 0x0410);
    memoryASet(ds, 0x0410, al);
    al = tl;
    if (al)
        goto loc_5fe1;
    interrupt(0x21);
loc_5fe1: // 01ed:4111
    ah = 0;
}
void sub_600c() // 01ed:413c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x35;
    al = memoryAGet(ss, bp + 4);
    interrupt(0x21);
    ax = bx;
    dx = es;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_601c() // 01ed:414c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryAGet(ss, bp + 4);
    push(ds);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_602d() // 01ed:415d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    sub_5eff();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_6039() // 01ed:4169
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    sub_5f2e();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_6045() // 01ed:4175
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    sub_6388();
    cx = pop();
    dx = ds;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_6053() // 01ed:4183
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 14));
    sub_6863();
    if (ax)
        goto loc_606f;
    ax = 0;
    goto loc_609f;
loc_606f: // 01ed:419f
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp + 8);
    di++;
    si = memoryAGet16(ss, bp + 10);
    goto loc_6097;
loc_607b: // 01ed:41ab
    ax = memoryAGet16(ss, bp + 16);
    dx = ds;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(si);
    sub_6f15();
    push(dx);
    push(ax);
    push(di);
    sub_6828();
    ax = di;
    ax <<= 1;
    memoryASet16(ss, bp + 16, memoryAGet16(ss, bp + 16) + ax);
    si++;
loc_6097: // 01ed:41c7
    if ((short)si <= (short)memoryAGet16(ss, bp + 14))
        goto loc_607b;
    ax = 0x0001;
loc_609f: // 01ed:41cf
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_60a3() // 01ed:41d3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp + 8);
    di++;
    si = memoryAGet16(ss, bp + 10);
    goto loc_60d0;
loc_60b4: // 01ed:41e4
    push(memoryAGet16(ss, bp + 8));
    push(si);
    sub_6f15();
    push(dx);
    push(ax);
    ax = memoryAGet16(ss, bp + 16);
    dx = ds;
    push(dx);
    push(ax);
    push(di);
    sub_6828();
    ax = di;
    ax <<= 1;
    memoryASet16(ss, bp + 16, memoryAGet16(ss, bp + 16) + ax);
    si++;
loc_60d0: // 01ed:4200
    if ((short)si <= (short)memoryAGet16(ss, bp + 14))
        goto loc_60b4;
    ax = 0x0001;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_60dc() // 01ed:420c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = cs;
    push(dx);
    push(ax);
    push(cs);
    sub_734d();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6100() // 01ed:4230
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    ax = bp - 0x8;
    push(ax);
    sub_68ab();
    cx = pop();
    ax = bp - 0x8;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_6125();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6125() // 01ed:4255
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(ds);
    cx = bp - 0xa;
    memoryASet16(ss, bp - 14, cx);
    memoryASet16(ss, bp - 12, ss);
    memoryASet(ss, bp - 10, 0x55);
    memoryASet(ss, bp - 9, 0xcd);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet(ss, bp - 8, al);
    memoryASet16(ss, bp - 7, 0xcb5d);
    if (al < 0x25)
        goto loc_6163;
    if (al > 0x26)
        goto loc_6163;
    memoryASet(ss, bp - 7, 0x36);
    memoryASet16(ss, bp - 6, 0x068f);
    memoryASet16(ss, bp - 4, cx);
    memoryASet16(ss, bp - 2, 0xcb5d);
loc_6163: // 01ed:4293
    si = memoryAGet16(ss, bp + 14);
    push(memoryAGet16(ds, si));
    push(memoryAGet16(ds, si + 6));
    si = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    cx = memoryAGet16(ds, si + 4);
    dx = memoryAGet16(ds, si + 6);
    di = memoryAGet16(ds, si + 10);
    si = memoryAGet16(ds, si + 8);
    ds = pop();
    es = pop();
    push(cs);
    cs = memoryAGet16(ss, bp - 14 + 2);
    callIndirect(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14));
    assert(cs == 0x01ed);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(si);
    push(ds);
    push(es);
    ds = memoryAGet16(ss, bp - 16);
    si = memoryAGet16(ss, bp + 14);
    memoryASet16(ds, si, pop());
    memoryASet16(ds, si + 6, pop());
    si = memoryAGet16(ss, bp + 12);
    memoryASet16(ds, si + 8, pop());
    memoryASet16(ds, si + 14, pop());
    memoryASet16(ds, si + 12, pop());
    memoryASet16(ds, si + 12, memoryAGet16(ds, si + 12) & 0x0001);
    memoryASet16(ds, si + 10, di);
    memoryASet16(ds, si + 6, dx);
    memoryASet16(ds, si + 4, cx);
    memoryASet16(ds, si + 2, bx);
    memoryASet16(ds, si, ax);
    ds = pop();
    if (memoryAGet16(ds, si + 12) == 0)
        goto loc_61bc;
    push(ax);
    push(ax);
    sub_61c2();
    ax = pop();
loc_61bc: // 01ed:42ec
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_61c2() // 01ed:42f2
{
    CStackGuard sg(2, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 6);
    if ((short)si < 0)
        goto loc_61e1;
    if (si <= 0x0058)
        goto loc_61d5;
loc_61d2: // 01ed:4302
    si = 0x0057;
loc_61d5: // 01ed:4305
    memoryASet16(ds, 0x041c, si);
    al = memoryAGet(ds, si + 1054);
    cbw();
    tx = si;
    si = ax;
    ax = tx;
    goto loc_61ee;
loc_61e1: // 01ed:4311
    si = -si;
    if (si > 0x0022)
        goto loc_61d2;
    memoryASet16(ds, 0x041c, 0xffff);
loc_61ee: // 01ed:431e
    ax = si;
    memoryASet16(ds, 0x0088, ax);
    ax = 0xffff;
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_61fb() // 01ed:432b
{
    CStackGuard sg(0, false);
    ah = 0x0b;
    interrupt(0x21);
    cbw();
}
void sub_620d() // 01ed:433d
{
    CStackGuardFar sg(8, true);
    push(0x7777);
    cx = 0;
    push(bp);
    push(si);
    push(di);
    bp = sp;
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 14);
    bp = memoryAGet16(ss, bp + 16);
    si = 0;
    if (cl & 0x01)
        goto loc_6246;
    if (!(dx & 0x8000))
        goto loc_6234;
    dx = -dx;
    stop(/*74*/);
    ax = -ax;
    dx -= si + flags.carry;
    cl |= 0x04;
loc_6234: // 01ed:4364
    if (!(bp & 0x8000))
        goto loc_6246;
    bp = -bp;
    stop(/*74*/);
    bx = -bx;
    bp -= si + flags.carry;
    if (cl & 0x02)
        goto loc_6246;
    cl ^= 0x04;
loc_6246: // 01ed:4376
    di = bp;
    di |= dx;
    if (di)
        goto loc_6252;
    div(bx);
    tx = dx;
    dx = si;
    si = tx;
    goto loc_6272;
loc_6252: // 01ed:4382
    push(cx);
    cx = 0x0020;
    di = si;
loc_6258: // 01ed:4388
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    si = rcl(si, 0x0001);
    di = rcl(di, 0x0001);
    if (di < bp)
        goto loc_626f;
    if (di > bp)
        goto loc_626a;
    if (si < bx)
        goto loc_626f;
loc_626a: // 01ed:439a
    flags.carry = si < bx;
    si -= bx;
    di -= bp + flags.carry;
    ax++;
loc_626f: // 01ed:439f
    if (--cx)
        goto loc_6258;
    cx = pop();
loc_6272: // 01ed:43a2
    if (!(cl & 0x02))
        goto loc_627a;
    tx = si;
    si = ax;
    ax = tx;
    dx = di;
loc_627a: // 01ed:43aa
    if (!(cl & 0x04))
        goto loc_6286;
    dx = -dx;
    stop(/*74*/);
    ax = -ax;
    dx -= flags.carry;
loc_6286: // 01ed:43b6
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_628c() // 01ed:43bc
{
    CStackGuard sg(12, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0022;
    push(es);
    di = memoryAGet16(ss, bp + 14);
    push(ds);
    es = pop();
    bx = memoryAGet16(ss, bp + 12);
    if (bx > 0x0024)
        goto loc_62fa;
    if (bl < 0x02)
        goto loc_62fa;
    ax = memoryAGet16(ss, bp + 16);
    cx = memoryAGet16(ss, bp + 18);
    if ((short)cx >= 0)
        goto loc_62c2;
    if (memoryAGet(ss, bp + 10) == 0x00)
        goto loc_62c2;
    memoryASet(ds, di, 0x2d);
    di++;
    cx = -cx;
    stop(/*74*/);
    ax = -ax;
    cx -= flags.carry;
loc_62c2: // 01ed:43f2
    si = bp - 0x22;
    if (cx == 0)
        goto loc_62d6;
loc_62c7: // 01ed:43f7
    tx = cx;
    cx = ax;
    ax = tx;
    dx = 0;
    div(bx);
    tx = cx;
    cx = ax;
    ax = tx;
    div(bx);
    memoryASet(ds, si, dl);
    si++;
    if (cx == 0)
        goto loc_62dd;
    goto loc_62c7;
loc_62d6: // 01ed:4406
    dx = 0;
    div(bx);
    memoryASet(ds, si, dl);
    si++;
loc_62dd: // 01ed:440d
    if (ax)
        goto loc_62d6;
    cx = bp - 0x22;
    cx = -cx;
    cx += si;
    flags.direction = false;
loc_62e9: // 01ed:4419
    si--;
    al = memoryAGet(ds, si);
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_62f4;
    al += 0x3a;
    goto loc_62f7;
loc_62f4: // 01ed:4424
    al += memoryAGet(ss, bp + 8);
loc_62f7: // 01ed:4427
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_62e9;
loc_62fa: // 01ed:442a
    al = 0x00;
    stosb<MemAuto, DirAuto>();
    es = pop();
    ax = memoryAGet16(ss, bp + 14);
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_6309() // 01ed:4439
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 8) != 0x000a)
        goto loc_6318;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_631d;
loc_6318: // 01ed:4448
    ax = memoryAGet16(ss, bp + 4);
    dx = 0;
loc_631d: // 01ed:444d
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 8));
    al = 0x01;
    push(ax);
    al = 0x61;
    push(ax);
    sub_628c();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_636f() // 01ed:449f
{
    CStackGuardFar sg(0, false);
    push(si);
    tx = si;
    si = ax;
    ax = tx;
    tx = dx;
    dx = ax;
    ax = tx;
    if (!(ax & ax))
        goto loc_6378;
    mul(bx);
loc_6378: // 01ed:44a8
    tx = cx;
    cx = ax;
    ax = tx;
    if (!(ax & ax))
        goto loc_6381;
    mul(si);
    cx += ax;
loc_6381: // 01ed:44b1
    tx = si;
    si = ax;
    ax = tx;
    mul(bx);
    dx += cx;
    si = pop();
    cs = pop();
}
void sub_6388() // 01ed:44b8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    di = memoryAGet16(ss, bp + 8);
    if (di)
        goto loc_639c;
    ax = 0;
    goto loc_641e;
loc_639c: // 01ed:44cc
    ax = di;
    ax += 0x0005;
    ax &= 0xfffe;
    di = ax;
    ax = memoryAGet16(ds, 0x047c);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 4);
    si = memoryAGet16(ds, bx + 2);
loc_63b2: // 01ed:44e2
    ax = memoryAGet16(ds, si);
    if (ax < di)
        goto loc_63e5;
    ax = memoryAGet16(ds, si);
    dx = di;
    dx += 0x0004;
    if (ax > dx)
        goto loc_63ce;
    ax = memoryAGet16(ds, si + 2);
    bx = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, bx + 2, ax);
    goto loc_63d8;
loc_63ce: // 01ed:44fe
    memoryASet16(ds, si, memoryAGet16(ds, si) - di);
    ax = memoryAGet16(ds, si);
    ax += si;
    si = ax;
    memoryASet16(ds, si, di);
loc_63d8: // 01ed:4508
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x047c, ax);
    ax = si;
    ax += 0x0002;
    goto loc_641e;
loc_63e5: // 01ed:4515
    if (si != memoryAGet16(ds, 0x047c))
        goto loc_63ed;
    goto loc_63f5;
loc_63ed: // 01ed:451d
    memoryASet16(ss, bp - 4, si);
    si = memoryAGet16(ds, si + 2);
    goto loc_63b2;
loc_63f5: // 01ed:4525
    ax = di;
    dx = 0;
    ax &= 0xffff;
    dx &= 0x0000;
    push(dx);
    push(ax);
    sub_5b3f();
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ss, bp - 2) != 0xffff)
        goto loc_6414;
    ax = 0;
    goto loc_641e;
loc_6414: // 01ed:4544
    si = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, si, di);
    ax = si;
    ax += 0x0002;
loc_641e: // 01ed:454e
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_6424() // 01ed:4554
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    si = memoryAGet16(ss, bp + 10);
    push(memoryAGet16(ss, bp + 8));
    push(si);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 14));
    sub_6863();
    if (!ax)
        goto loc_6460;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 18));
    ax = memoryAGet16(ss, bp + 12);
    ax -= memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 16);
    push(ax);
    ax = memoryAGet16(ss, bp + 14);
    ax -= si;
    ax += memoryAGet16(ss, bp + 18);
    push(ax);
    sub_6863();
    if (ax)
        goto loc_6464;
loc_6460: // 01ed:4590
    ax = 0;
    goto loc_64be;
loc_6464: // 01ed:4594
    memoryASet16(ss, bp - 6, si);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, 0x0001);
    if ((short)si >= (short)memoryAGet16(ss, bp + 18))
        goto loc_6485;
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, si);
    memoryASet16(ss, bp - 2, 0xffff);
loc_6485: // 01ed:45b5
    di = memoryAGet16(ss, bp - 6);
    goto loc_64b1;
loc_648a: // 01ed:45ba
    push(memoryAGet16(ss, bp + 16));
    ax = di;
    ax -= si;
    ax += memoryAGet16(ss, bp + 18);
    push(ax);
    sub_6f15();
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(di);
    sub_6f15();
    push(dx);
    push(ax);
    ax = memoryAGet16(ss, bp + 12);
    ax -= memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    sub_6828();
    di += memoryAGet16(ss, bp - 2);
loc_64b1: // 01ed:45e1
    ax = memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 2);
    if (ax != di)
        goto loc_648a;
    ax = 0x0001;
loc_64be: // 01ed:45ee
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_64c4() // 01ed:45f4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    al = 0x01;
    cx = memoryAGet16(ss, bp + 8);
    if (cx & 0x0002)
        goto loc_64dd;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_64dd;
    al = 0x00;
loc_64dd: // 01ed:460d
    dx = memoryAGet16(ss, bp + 6);
    cl = 0xf0;
    cl &= memoryAGet(ss, bp + 8);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    if (flags.carry)
        goto loc_6504;
    si = ax;
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0xf8ff;
    ax |= 0x8000;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 1000, ax);
    ax = si;
    goto loc_6508;
loc_6504: // 01ed:4634
    push(ax);
    sub_61c2();
loc_6508: // 01ed:4638
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_651e() // 01ed:464e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x3f;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_6532;
    goto loc_6536;
loc_6532: // 01ed:4662
    push(ax);
    sub_61c2();
loc_6536: // 01ed:4666
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_653c() // 01ed:466c
{
    CStackGuardFar sg(8, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    ax = ds;
    dx = es;
    if (ax > dx)
        goto loc_655f;
    if (si > di)
        goto loc_655f;
    flags.direction = false;
loc_6555: // 01ed:4685
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    flags.direction = false;
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
    return;
loc_655f: // 01ed:468f
    si += cx;
    di += cx;
    si--;
    di--;
    flags.direction = true;
    goto loc_6555;
}
void sub_6568() // 01ed:4698
{
    CStackGuard sg(6, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 10);
    cx = memoryAGet16(ds, si);
    cl = 0x20;
    goto loc_657d;
loc_6575: // 01ed:46a5
    memoryASet16(ds, si, cx);
    si += 0x0002;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
loc_657d: // 01ed:46ad
    ax = memoryAGet16(ss, bp + 8);
    if ((short)ax <= (short)memoryAGet16(ss, bp + 6))
        goto loc_6575;
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_658a() // 01ed:46ba
{
    CStackGuard sg(12, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x00a0;
    if (memoryAGet(ds, 0x037b) == 0x00)
        goto loc_659b;
    goto loc_66d3;
loc_659b: // 01ed:46cb
    if (memoryAGet16(ds, 0x0381) != 0x0000)
        goto loc_65a5;
    goto loc_66d3;
loc_65a5: // 01ed:46d5
    if (memoryAGet(ss, bp + 4) == 0x01)
        goto loc_65ae;
    goto loc_66d3;
loc_65ae: // 01ed:46de
    memoryASet(ss, bp + 12, memoryAGet(ss, bp + 12) + 1);
    memoryASet(ss, bp + 10, memoryAGet(ss, bp + 10) + 1);
    memoryASet(ss, bp + 8, memoryAGet(ss, bp + 8) + 1);
    memoryASet(ss, bp + 6, memoryAGet(ss, bp + 6) + 1);
    if (memoryAGet(ss, bp + 14) == 0x06)
        goto loc_65c3;
    goto loc_664b;
loc_65c3: // 01ed:46f3
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    ax++;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_6424();
    sp += 0x000c;
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_6053();
    sp += 0x000a;
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    sub_6568();
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_60a3();
    sp += 0x000a;
    goto loc_66d1;
loc_664b: // 01ed:477b
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    ax++;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    ax--;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_6424();
    sp += 0x000c;
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_6053();
    sp += 0x000a;
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    sub_6568();
    ax = bp - 0xa0;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 12);
    ah = 0x00;
    push(ax);
    sub_60a3();
    sp += 0x000a;
loc_66d1: // 01ed:4801
    goto loc_66ec;
loc_66d3: // 01ed:4803
    bh = memoryAGet(ds, 0x0376);
    ah = memoryAGet(ss, bp + 14);
    al = memoryAGet(ss, bp + 4);
    ch = memoryAGet(ss, bp + 10);
    cl = memoryAGet(ss, bp + 12);
    dh = memoryAGet(ss, bp + 6);
    dl = memoryAGet(ss, bp + 8);
    sub_5d53();
loc_66ec: // 01ed:481c
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_66f2() // 01ed:4822
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    si = memoryAGet16(ss, bp + 6);
    si >>= 1;
    ax = si;
    dl = memoryAGet(ds, 0x037a);
    dh = 0x00;
    bx = dx;
    dx = 0;
    div(bx);
    memoryASet(ss, bp - 2, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dl = memoryAGet(ds, 0x037a);
    dh = 0x00;
    mul(dx);
    dx = si;
    dl -= al;
    memoryASet(ss, bp - 1, dl);
    ah = memoryAGet(ss, bp - 2);
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_672f() // 01ed:485f
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ss, bp + 6);
    if (ax == memoryAGet16(ds, bx))
        goto loc_6748;
    dx = memoryAGet16(ds, si);
    bh = 0x00;
    ah = 0x02;
    sub_5d53();
loc_6748: // 01ed:4878
    bx = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, bx, dx);
    dl++;
    al = dl;
    if (al < memoryAGet(ds, 0x037a))
        goto loc_675b;
    dh++;
    dl = 0x00;
loc_675b: // 01ed:488b
    memoryASet16(ds, si, dx);
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_6762() // 01ed:4892
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    sub_6fb0();
    di = ax;
    ax = di;
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp + 16);
    if (ax != memoryAGet16(ds, 0x037f))
        goto loc_6782;
    ax = 0x0001;
    goto loc_6784;
loc_6782: // 01ed:48b2
    ax = 0;
loc_6784: // 01ed:48b4
    memoryASet16(ss, bp - 4, ax);
    if (!ax)
        goto loc_6797;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    sub_66f2();
    memoryASet16(ss, bp - 10, ax);
loc_6797: // 01ed:48c7
    ax = memoryAGet16(ss, bp + 12);
    if (ax != memoryAGet16(ds, 0x037f))
        goto loc_67a5;
    ax = 0x0001;
    goto loc_67a7;
loc_67a5: // 01ed:48d5
    ax = 0;
loc_67a7: // 01ed:48d7
    memoryASet16(ss, bp - 2, ax);
    if (!ax)
        goto loc_67ba;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    sub_66f2();
    memoryASet16(ss, bp - 8, ax);
loc_67ba: // 01ed:48ea
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - 1);
    if (!ax)
        goto loc_6817;
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_67e0;
    ax = bp - 0x8;
    push(ax);
    ax = bp - 0x6;
    push(ax);
    sub_672f();
    bh = 0x00;
    ah = 0x08;
    sub_5d53();
    si = ax;
    goto loc_67ea;
loc_67e0: // 01ed:4910
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    si = memoryAGet16(es, bx);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + 0x0002);
loc_67ea: // 01ed:491a
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_680b;
    ax = bp - 0xa;
    push(ax);
    ax = bp - 0x6;
    push(ax);
    sub_672f();
    ax = si;
    bl = ah;
    cx = 0x0001;
    bh = 0x00;
    ah = 0x09;
    sub_5d53();
    goto loc_6815;
loc_680b: // 01ed:493b
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, bx, si);
    memoryASet16(ss, bp + 14, memoryAGet16(ss, bp + 14) + 0x0002);
loc_6815: // 01ed:4945
    goto loc_67ba;
loc_6817: // 01ed:4947
    dx = di;
    bh = 0x00;
    ah = 0x02;
    sub_5d53();
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_6828() // 01ed:4958
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet(ds, 0x037b) != 0x00)
        goto loc_684d;
    if (memoryAGet16(ds, 0x0381) == 0x0000)
        goto loc_684d;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_6f38();
    goto loc_685f;
loc_684d: // 01ed:497d
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_6762();
loc_685f: // 01ed:498f
    bp = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_6863() // 01ed:4993
{
    CStackGuard sg(8, true);
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ds, 0x037a);
    ah = 0x00;
    cx = ax;
    al = memoryAGet(ds, 0x0379);
    ah = 0x00;
    dx = ax;
    ax = memoryAGet16(ss, bp + 10);
    if (ax > cx)
        goto loc_68a5;
    ax = memoryAGet16(ss, bp + 6);
    if (ax > cx)
        goto loc_68a5;
    ax = memoryAGet16(ss, bp + 10);
    if ((short)ax > (short)memoryAGet16(ss, bp + 6))
        goto loc_68a5;
    ax = memoryAGet16(ss, bp + 8);
    if (ax > dx)
        goto loc_68a5;
    ax = memoryAGet16(ss, bp + 4);
    if (ax > dx)
        goto loc_68a5;
    ax = memoryAGet16(ss, bp + 8);
    if ((short)ax > (short)memoryAGet16(ss, bp + 4))
        goto loc_68a5;
    ax = 0x0001;
    goto loc_68a7;
loc_68a5: // 01ed:49d5
    ax = 0;
loc_68a7: // 01ed:49d7
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_68ab() // 01ed:49db
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, si, es);
    memoryASet16(ds, si + 2, cs);
    memoryASet16(ds, si + 4, ss);
    memoryASet16(ds, si + 6, ds);
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_68c6() // 01ed:49f6
{
    CStackGuard sg(-20, true);
    push(0x7777);
    goto loc_68c6;
loc_205d: // 01ed:018d
    cx = 0x001e;
    dx = 0x0056;
    ds = memoryAGet16(cs, 0x01a3);
    sub_2055();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0003);
    ax = 0x2470;
    push(ax);
    sub_60dc();
    sp++;
    sp++;
    if ((short)ax >= 0)
        goto loc_209d;
    ax = 0x0001;
    push(ax);
    sub_5eff();
    sp++;
    sp++;
loc_209d: // 01ed:01cd
    push(ds);
    ax = 0x02b2;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7972();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(cs);
    cs = 0x01ed;
    sub_726d();
    assert(cs == 0x01ed);
    if ((short)ax >= 0)
        goto loc_20c9;
    ax = 0x02b3;
    push(ax);
    sub_5d06();
    sp++;
    sp++;
    goto loc_21ca;
loc_20c9: // 01ed:01f9
    sub_230a();
    if (ax)
        goto loc_20d3;
    goto loc_21c5;
loc_20d3: // 01ed:0203
    ax = 0;
    memoryASet16(ds, 0x024e, ax);
    memoryASet16(ds, 0x09d8, ax);
    sub_21d0();
    if (ax)
        goto loc_2124;
    di = 0x0001;
    goto loc_211f;
loc_20e7: // 01ed:0217
    si = 0;
    goto loc_210c;
loc_20eb: // 01ed:021b
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_210c: // 01ed:023c
    if ((short)si < (short)0x000e)
        goto loc_20eb;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_211f: // 01ed:024f
    if ((short)di < (short)0x0003)
        goto loc_20e7;
loc_2124: // 01ed:0254
    sub_5af1();
    if (!(ax & 0x0001))
        goto loc_2133;
    sub_25f4();
    if (ax)
        goto loc_2195;
loc_2133: // 01ed:0263
    di = 0x0001;
    goto loc_2190;
loc_2138: // 01ed:0268
    si = 0;
    goto loc_217d;
loc_213c: // 01ed:026c
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 202);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 188, al);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_217d: // 01ed:02ad
    if ((short)si < (short)0x000e)
        goto loc_213c;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_2190: // 01ed:02c0
    if ((short)di < (short)0x0003)
        goto loc_2138;
loc_2195: // 01ed:02c5
    sub_2abe();
    memoryASet16(ds, 0x098c, 0x0040);
    memoryASet16(ds, 0x098e, 0x00e2);
    memoryASet16(ds, 0x09e4, 0x00ad);
    memoryASet16(ds, 0x09e6, 0x00ad);
loc_21b0: // 01ed:02e0
    sub_287f();
    if (!ax)
        goto loc_21c5;
    sub_3ed8();
    ax = memoryAGet16(ds, 0x09d8);
    ax ^= 0x0001;
    memoryASet16(ds, 0x09d8, ax);
    goto loc_21b0;
loc_21c5: // 01ed:02f5
    push(cs);
    cs = 0x01ed;
    sub_7bb3();
    assert(cs == 0x01ed);
loc_21ca: // 01ed:02fa
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 18166 bytes
loc_68c6: // 01ed:49f6
    memoryASet16(cs, 0x49f0, pop());
    memoryASet16(cs, 0x49f2, ds);
    flags.direction = false;
    es = memoryAGet16(ds, 0x0084);
    si = 0x0080;
    ax = 0;
    lodsb_es<MemAuto, DirAuto>();
    ax++;
    bp = es;
    tx = si;
    si = dx;
    dx = tx;
    tx = bx;
    bx = ax;
    ax = tx;
    si = memoryAGet16(ds, 0x007e);
    si += 0x0002;
    cx = 0x0001;
    if (memoryAGet(ds, 0x0086) < 0x03)
        goto loc_6904;
    es = memoryAGet16(ds, 0x0080);
    di = si;
    cl = 0x7f;
    al = 0;
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_6977;
    cl ^= 0x7f;
loc_6904: // 01ed:4a34
    sp -= 0x0002;
    ax = 0x0001;
    ax += bx;
    ax += cx;
    ax &= 0xfffe;
    di = sp;
    tx = di;
    di -= ax;
    if (tx < ax)
        goto loc_6977;
    sp = di;
    ax = es;
    ds = ax;
    ax = ss;
    es = ax;
    push(cx);
    cx--;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    ds = bp;
    tx = dx;
    dx = si;
    si = tx;
    tx = cx;
    cx = bx;
    bx = tx;
    ax = bx;
    dx = ax;
    bx++;
loc_6933: // 01ed:4a63
    sub_694f();
    if (!flags.zero && !flags.carry)
        goto loc_693f;
loc_6938: // 01ed:4a68
    if (flags.carry)
        goto loc_697a;
    sub_694f();
    if (!flags.zero && !flags.carry)
        goto loc_6938;
loc_693f: // 01ed:4a6f
    if (al == 0x20)
        goto loc_694b;
    if (al == 0x0d)
        goto loc_694b;
    if (al != 0x09)
        goto loc_6933;
loc_694b: // 01ed:4a7b
    al = 0;
    goto loc_6933;
    //   gap of 40 bytes
loc_6977: // 01ed:4aa7
    goto loc_205d;
loc_697a: // 01ed:4aaa
    cx = pop();
    cx += dx;
    ds = memoryAGet16(cs, 0x49f2);
    memoryASet16(ds, 0x0078, bx);
    bx++;
    bx += bx;
    si = sp;
    bp = sp;
    tx = bp;
    bp -= bx;
    if (tx < bx)
        goto loc_6977;
    sp = bp;
    memoryASet16(ds, 0x007a, bp);
loc_6997: // 01ed:4ac7
    if (cx == 0)
        goto loc_69a7;
    memoryASet16(ss, bp, si);
    bp += 0x0002;
loc_699f: // 01ed:4acf
    lodsb_ss<MemAuto, DirAuto>();
    if (--cx && al)
        goto loc_699f;
    if (!al)
        goto loc_6997;
loc_69a7: // 01ed:4ad7
    ax = 0;
    memoryASet16(ss, bp, ax);
//    callIndirect(cs, memoryAGet16(cs, 0x49f0)); // 01ed:4adc - GABO CICO
}
// INJECT: Error: cannot inject flag in sub_694f() because of being label!
void sub_694f() // 01ed:4a7f
{
    CStackGuard sg(0, false);
    if (!ax)
        goto loc_695a;
    dx++;
    stosb<MemAuto, DirAuto>();
    if (al)
        goto loc_695a;
    bx++;
loc_695a: // 01ed:4a8a
    tl = al;
    al = ah;
    ah = tl;
    al = 0;
    flags.carry = true;
    if (cx == 0)
        goto loc_6976;
    lodsb<MemAuto, DirAuto>();
    cx--;
    al -= 0x22;
    if (al == 0)
    {
        flags.zero = true;
        goto loc_6976;
    }
    al += 0x22;
    if (al != 0x5c)
    {
        flags.zero = false;
        goto loc_6974;
    }
    if (memoryAGet(ds, si) != 0x22)
    {
        flags.zero = false;
        goto loc_6974;
    }
    lodsb<MemAuto, DirAuto>();
    cx--;
    flags.zero = cx == 0;
loc_6974: // 01ed:4aa4
    flags.carry = false;
loc_6976: // 01ed:4aa6
    return;
}
void sub_69b1() // 01ed:4ae1
{
    CStackGuard sg(0, true);
    push(0x7777);
    goto loc_69b1;
loc_205d: // 01ed:018d
    cx = 0x001e;
    dx = 0x0056;
    ds = memoryAGet16(cs, 0x01a3);
    sub_2055();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0003);
    ax = 0x2470;
    push(ax);
    sub_60dc();
    sp++;
    sp++;
    if ((short)ax >= 0)
        goto loc_209d;
    ax = 0x0001;
    push(ax);
    sub_5eff();
    sp++;
    sp++;
loc_209d: // 01ed:01cd
    push(ds);
    ax = 0x02b2;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_7972();
    assert(cs == 0x01ed);
    sp += 0x000c;
    push(cs);
    cs = 0x01ed;
    sub_726d();
    assert(cs == 0x01ed);
    if ((short)ax >= 0)
        goto loc_20c9;
    ax = 0x02b3;
    push(ax);
    sub_5d06();
    sp++;
    sp++;
    goto loc_21ca;
loc_20c9: // 01ed:01f9
    sub_230a();
    if (ax)
        goto loc_20d3;
    goto loc_21c5;
loc_20d3: // 01ed:0203
    ax = 0;
    memoryASet16(ds, 0x024e, ax);
    memoryASet16(ds, 0x09d8, ax);
    sub_21d0();
    if (ax)
        goto loc_2124;
    di = 0x0001;
    goto loc_211f;
loc_20e7: // 01ed:0217
    si = 0;
    goto loc_210c;
loc_20eb: // 01ed:021b
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_210c: // 01ed:023c
    if ((short)si < (short)0x000e)
        goto loc_20eb;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_211f: // 01ed:024f
    if ((short)di < (short)0x0003)
        goto loc_20e7;
loc_2124: // 01ed:0254
    sub_5af1();
    if (!(ax & 0x0001))
        goto loc_2133;
    sub_25f4();
    if (ax)
        goto loc_2195;
loc_2133: // 01ed:0263
    di = 0x0001;
    goto loc_2190;
loc_2138: // 01ed:0268
    si = 0;
    goto loc_217d;
loc_213c: // 01ed:026c
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 202);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 188, al);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    al = memoryAGet(ds, bx + 216);
    push(ax);
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    bx += si;
    ax = pop();
    memoryASet(ds, bx + 202, al);
    si++;
loc_217d: // 01ed:02ad
    if ((short)si < (short)0x000e)
        goto loc_213c;
    ax = di;
    dx = 0x003c;
    mul(dx);
    bx = ax;
    memoryASet16(ds, bx + 172, memoryAGet16(ds, bx + 172) - 1);
    di++;
loc_2190: // 01ed:02c0
    if ((short)di < (short)0x0003)
        goto loc_2138;
loc_2195: // 01ed:02c5
    sub_2abe();
    memoryASet16(ds, 0x098c, 0x0040);
    memoryASet16(ds, 0x098e, 0x00e2);
    memoryASet16(ds, 0x09e4, 0x00ad);
    memoryASet16(ds, 0x09e6, 0x00ad);
loc_21b0: // 01ed:02e0
    sub_287f();
    if (!ax)
        goto loc_21c5;
    sub_3ed8();
    ax = memoryAGet16(ds, 0x09d8);
    ax ^= 0x0001;
    memoryASet16(ds, 0x09d8, ax);
    goto loc_21b0;
loc_21c5: // 01ed:02f5
    push(cs);
    cs = 0x01ed;
    sub_7bb3();
    assert(cs == 0x01ed);
loc_21ca: // 01ed:02fa
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 18401 bytes
loc_69b1: // 01ed:4ae1
    cx = memoryAGet16(ds, 0x007e);
    push(cx);
    sub_6388();
    cx = pop();
    di = ax;
    if (!ax)
        goto loc_69e4;
    push(ds);
    push(ds);
    es = pop();
    ds = memoryAGet16(ds, 0x0080);
    si = 0;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    di = ax;
    push(es);
    push(memoryAGet16(ds, 0x0082));
    sub_6388();
    sp += 0x0002;
    bx = ax;
    es = pop();
    memoryASet16(ds, 0x007c, ax);
    if (ax)
        goto loc_69e7;
loc_69e4: // 01ed:4b14
    goto loc_205d;
loc_69e7: // 01ed:4b17
    ax = 0;
    cx = 0xffff;
loc_69ec: // 01ed:4b1c
    memoryASet16(ds, bx, di);
    bx += 0x0002;
    repne_scasb<MemAuto, DirAuto>(al);
    if (memoryAGet(es, di) != al)
        goto loc_69ec;
    memoryASet16(ds, bx, ax);
    assert(pop() == 0x7777);
}
void sub_69fb() // 01ed:4b2b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    ax = 0x34dd;
    dx = 0x0012;
    if (dx >= bx)
        goto loc_6a25;
    div(bx);
    bx = ax;
    in(al, 0x61);
    if (al & 0x03)
        goto loc_6a1d;
    al |= 0x03;
    out(0x61, al);
    al = 0xb6;
    out(0x43, al);
loc_6a1d: // 01ed:4b4d
    al = bl;
    out(0x42, al);
    al = bh;
    out(0x42, al);
loc_6a25: // 01ed:4b55
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a27() // 01ed:4b57
{
    CStackGuard sg(0, false);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
}
void sub_6a2e() // 01ed:4b5e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    ax = ds;
    es = ax;
    flags.direction = false;
    di = memoryAGet16(ss, bp + 8);
    al = 0;
    cx = 0xffff;
    repne_scasb<MemAuto, DirAuto>(al);
    ax = cx;
    ax = ~ax;
    ax--;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
}
void sub_6f15() // 01ed:5045
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    ax--;
    dl = memoryAGet(ds, 0x037a);
    dh = 0x00;
    mul(dx);
    ax += memoryAGet16(ds, 0x037d);
    dx = memoryAGet16(ss, bp + 6);
    dx--;
    ax += dx;
    ax <<= 1;
    dx = memoryAGet16(ds, 0x037f);
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_6f38() // 01ed:5068
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = memoryAGet(ds, 0x037c);
    ah = 0x00;
    memoryASet16(ss, bp - 2, ax);
    push(ds);
    cx = memoryAGet16(ss, bp + 8);
    if (cx == 0)
        goto loc_6fa7;
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    si = memoryAGet16(ss, bp + 10);
    ds = memoryAGet16(ss, bp + 10 + 2);
    flags.direction = false;
    if (si >= di)
        goto loc_6f62;
    ax = cx;
    ax--;
    ax <<= 1;
    si += ax;
    di += ax;
    flags.direction = true;
loc_6f62: // 01ed:5092
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_6f6c;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    goto loc_6fa7;
loc_6f6c: // 01ed:509c
    dx = 0x03da;
    ax = es;
    bx = ds;
    if (ax == bx)
        goto loc_6f88;
loc_6f77: // 01ed:50a7
    flags.interrupts = false;
loc_6f78: // 01ed:50a8
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (flags.carry)
        goto loc_6f78;
loc_6f7d: // 01ed:50ad
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (!flags.carry)
        goto loc_6f7d;
    movsw<MemAuto, MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_6f77;
    goto loc_6fa7;
loc_6f88: // 01ed:50b8
    flags.interrupts = false;
loc_6f89: // 01ed:50b9
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (flags.carry)
        goto loc_6f89;
loc_6f8e: // 01ed:50be
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (!flags.carry)
        goto loc_6f8e;
    lodsw<MemAuto, DirAuto>();
    flags.interrupts = true;
    bx = ax;
loc_6f97: // 01ed:50c7
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (flags.carry)
        goto loc_6f97;
loc_6f9c: // 01ed:50cc
    in(al, dx);
    flags.carry = al & 1;
    al = ror(al, 0x01);
    if (!flags.carry)
        goto loc_6f9c;
    ax = bx;
    stosw<MemAuto, DirAuto>();
    flags.interrupts = true;
    if (--cx)
        goto loc_6f88;
loc_6fa7: // 01ed:50d7
    ds = pop();
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_6fb0() // 01ed:50e0
{
    CStackGuard sg(0, false);
    ah = 0x03;
    bh = 0x00;
    sub_5d53();
    ax = dx;
}
void sub_7010() // 01ed:5140
{
    CStackGuard sg(8, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    push(ds);
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
loc_701c: // 01ed:514c
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_701c;
    ds = pop();
    dx = memoryAGet16(ss, bp + 14);
    ax = memoryAGet16(ss, bp + 12);
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_702f() // 01ed:515f
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    cx = 0xffff;
    al = 0;
    flags.direction = false;
    repne_scasb<MemAuto, DirAuto>(al);
    di--;
    ax = di;
    dx = es;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_704a() // 01ed:517a
{
    CStackGuard sg(12, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    push(ds);
    di = memoryAGet16(ss, bp + 16);
    es = memoryAGet16(ss, bp + 16 + 2);
    si = memoryAGet16(ss, bp + 12);
    ds = memoryAGet16(ss, bp + 12 + 2);
    ax = ds;
    ax |= si;
    if (!ax)
        goto loc_7063;
loc_705c: // 01ed:518c
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_705c;
    di--;
loc_7063: // 01ed:5193
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
loc_7066: // 01ed:5196
    lodsb<MemAuto, DirAuto>();
    stosb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_7066;
    di--;
    ds = pop();
    ax = di;
    dx = es;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_7078() // 01ed:51a8
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    dx = memoryAGet16(ss, bp + 4);
    ds = memoryAGet16(ss, bp + 4 + 2);
    ah = 0x09;
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_7088() // 01ed:51b8
{
    CStackGuard sg(0, false);
    bx = memoryAGet16(ds, 0x0aac);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_7091() // 01ed:51c1
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    push(ds);
    dx = memoryAGet16(ss, bp + 14);
    ds = memoryAGet16(ss, bp + 14 + 2);
    ax = 0x3d00;
    interrupt(0x21);
    ds = pop();
    if (!flags.carry)
        goto loc_70a7;
    ax = 0xfffd;
    goto loc_70d2;
loc_70a7: // 01ed:51d7
    memoryASet16(ds, 0x0aac, ax);
    bx = ax;
    cx = 0;
    dx = 0;
    ax = 0x4202;
    interrupt(0x21);
    if (flags.carry)
        goto loc_70c4;
    if (ax == 0)
        goto loc_70c4;
    if (dx != 0)
        goto loc_70c4;
    if (ax <= 0x3c00)
        goto loc_70cc;
loc_70c4: // 01ed:51f4
    sub_7088();
    ax = memoryAGet16(ss, bp + 8);
    goto loc_70d2;
loc_70cc: // 01ed:51fc
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    stosw<MemAuto, DirAuto>();
    ax = 0;
loc_70d2: // 01ed:5202
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_70d8() // 01ed:5208
{
    CStackGuard sg(8, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ds, 0x0aac);
    cx = 0;
    dx = memoryAGet16(ss, bp + 10);
    ax = 0x4200;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7101;
    push(ds);
    bx = memoryAGet16(ds, 0x0aac);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 4);
    ds = memoryAGet16(ss, bp + 4 + 2);
    ah = 0x3f;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_7101;
    ax = 0;
    goto loc_710d;
loc_7101: // 01ed:5231
    sub_7088();
    memoryASet16(ds, 0x0a9e, 0xfff4);
    ax = 0x0001;
loc_710d: // 01ed:523d
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_726d() // 01ed:539d
{
    CStackGuardFar sg(0, false);
    push(ds);
    push(si);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    si = memoryAGet16(ds, 0x0a9e);
    memoryASet16(ds, 0x0a9e, 0x0000);
    ax = si;
    bp = pop();
    si = pop();
    ds = pop();
    cs = pop();
}
void sub_7285() // 01ed:53b5
{
    CStackGuardFar sg(0, false);
    if (memoryAGet16(ds, 0x0616) == 0x0000)
        goto loc_7296;
    push(ds);
    ax = 0x08e3;
    push(ax);
    sub_7078();
    goto loc_729e;
loc_7296: // 01ed:53c6
    push(ds);
    ax = 0x0907;
    push(ax);
    sub_7078();
loc_729e: // 01ed:53ce
    ax = 0x0001;
    push(ax);
    push(cs);
    sub_602d();
    cx = pop();
    cs = pop();
}
void sub_72a8() // 01ed:53d8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_6045();
    cx = pop();
    cx = ax;
    cx |= dx;
    if (!cx)
        goto loc_72c7;
    if (ax)
        goto loc_72c7;
    bx = ds;
    if (bx != dx)
        goto loc_72c7;
    cx = 0;
    dx = 0;
loc_72c7: // 01ed:53f7
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, ax);
    memoryASet16(es, bx + 2, dx);
    ax = 0x0001;
    if (cx == 0)
        goto loc_72d7;
    ax--;
loc_72d7: // 01ed:5407
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_72d9() // 01ed:5409
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx);
    ax |= memoryAGet16(es, bx + 2);
    if (!ax)
        goto loc_7301;
    if (memoryAGet16(ss, bp + 8) == 0x0000)
        goto loc_7301;
    push(memoryAGet16(ss, bp + 8));
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_6039();
    sp = bp;
loc_7301: // 01ed:5431
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, 0x0000);
    memoryASet16(es, bx, 0x0000);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7311() // 01ed:5441
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(si);
    push(di);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 14);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    si += memoryAGet16(es, bx);
    ax = si;
    ax &= 0x000f;
    memoryASet16(es, bx, memoryAGet16(es, bx) - ax);
    dx = memoryAGet16(ss, bp + 16);
    ax = si;
    cl = 0x04;
    ax >>= cl;
    dx += ax;
    si &= 0x000f;
    if (si == 0)
        goto loc_7345;
    cx = memoryAGet16(ss, bp + 8);
    push(ds);
    ds = dx;
    es = dx;
    di = 0;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
loc_7345: // 01ed:5475
    ax = 0;
    bp = pop();
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_734d() // 01ed:547d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x0616) == 0x0000)
        goto loc_736b;
    ax = 0xfff5;
    memoryASet16(ds, 0x0a9e, ax);
    goto loc_73dc;
loc_736b: // 01ed:549b
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if (memoryAGet16(es, bx) != 0x6b70)
        goto loc_73ac;
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    cx = 0xffff;
    al = 0x1a;
    flags.direction = false;
    repne_scasb<MemAuto, DirAuto>(al);
    memoryASet16(ss, bp - 6, di);
    memoryASet16(ss, bp - 4, es);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet(es, bx + 6) < 0x01)
        goto loc_73ac;
    if (ax <= 0x0005)
        goto loc_739b;
    goto loc_73ac;
loc_739b: // 01ed:54cb
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    if (memoryAGet(es, bx + 6) < 0x01)
        goto loc_73ac;
    if (memoryAGet(es, bx + 8) <= 0x01)
        goto loc_73b4;
loc_73ac: // 01ed:54dc
    ax = 0xfffc;
    memoryASet16(ds, 0x0a9e, ax);
    goto loc_73dc;
loc_73b4: // 01ed:54e4
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, bx + 4));
    sub_7311();
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 1566, dx);
    memoryASet16(ds, bx + 1564, ax);
    ax = memoryAGet16(ss, bp - 2);
loc_73dc: // 01ed:550c
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_73e3() // 01ed:5513
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    sp -= 0x0012;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if (memoryAGet16(es, bx) != 0x4b50)
        goto loc_741d;
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    cx = 0xffff;
    al = 0x1a;
    flags.direction = false;
    repne_scasb<MemAuto, DirAuto>(al);
    memoryASet16(ss, bp - 16, di);
    memoryASet16(ss, bp - 14, es);
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    if (memoryAGet(es, bx + 8) < 0x01)
        goto loc_741d;
    if (memoryAGet(es, bx + 10) <= 0x01)
        goto loc_7426;
loc_741d: // 01ed:554d
    ax = 0xfff3;
    memoryASet16(ds, 0x0a9e, ax);
    goto loc_750d;
loc_7426: // 01ed:5556
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    bx += 0x0002;
    memoryASet16(ss, bp - 10, es);
    memoryASet16(ss, bp - 12, bx);
    memoryASet16(ss, bp - 8, 0x056b);
    memoryASet16(ss, bp - 2, 0xffff);
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_7481;
loc_7443: // 01ed:5573
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ss, bp - 8);
    push(dx);
    push(ax);
    push(ds);
    es = pop();
    ax = pop();
    dx = pop();
    if (dx != memoryAGet16(es, bx + 2))
        goto loc_7461;
    if (ax == memoryAGet16(es, bx))
        goto loc_7487;
loc_7461: // 01ed:5591
    if (memoryAGet16(ss, bp - 2) >= 0x0000)
        goto loc_747a;
    bx = memoryAGet16(ss, bp - 8);
    if (memoryAGet(ds, bx) != 0x00)
        goto loc_747a;
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 2, ax);
    ax = bx;
    memoryASet16(ss, bp - 6, ax);
loc_747a: // 01ed:55aa
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x000f);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_7481: // 01ed:55b1
    if (memoryAGet16(ss, bp - 4) < 0x000a)
        goto loc_7443;
loc_7487: // 01ed:55b7
    if (memoryAGet16(ss, bp - 4) < 0x000a)
        goto loc_74bc;
    if (memoryAGet16(ss, bp - 2) != 0xffff)
        goto loc_749c;
    ax = 0xfff5;
    memoryASet16(ds, 0x0a9e, ax);
    goto loc_750d;
loc_749c: // 01ed:55cc
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ss, bp - 6);
    push(dx);
    push(ax);
    push(ds);
    es = pop();
    ax = pop();
    dx = pop();
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, ax);
loc_74bc: // 01ed:55ec
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x000f;
    mul(dx);
    ax += 0x0561;
    memoryASet16(ss, bp - 18, ax);
    bx = ax;
    push(memoryAGet16(ds, bx + 8));
    dx = ds;
    push(dx);
    push(ax);
    sub_72d9();
    sp += 0x0006;
    bx = memoryAGet16(ss, bp - 18);
    memoryASet16(ds, bx + 2, 0x0000);
    memoryASet16(ds, bx, 0x0000);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp - 14));
    push(memoryAGet16(ss, bp - 16));
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    push(memoryAGet16(es, bx + 6));
    sub_7311();
    bx = memoryAGet16(ss, bp - 18);
    memoryASet16(ds, bx + 6, dx);
    memoryASet16(ds, bx + 4, ax);
    memoryASet16(ds, bx + 8, 0x0000);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
loc_750d: // 01ed:563d
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_753d() // 01ed:566d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, bx, 0x0000);
    ax = memoryAGet16(ss, bp + 8);
    ax--;
    if (ax > 0x0009)
        goto loc_75b8;
    bx = ax;
    bx <<= 1;
    assert(bx == 0); // gabo??
loc_7574:
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, bx, 0x0004);
    goto loc_75c8;
    //   gap of 88 bytes
loc_75b8: // 01ed:56e8
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, bx, 0xffff);
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    memoryASet16(es, bx, 0xffff);
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_75c8:
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();

}
void sub_75cb() // 01ed:56fb
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_753d();
    sp += 0x000a;
    if (memoryAGet16(ss, bp + 6) == 0x0000)
        goto loc_7610;
    ax = memoryAGet16(ss, bp + 4);
    if ((short)ax < (short)memoryAGet16(ss, bp - 2))
        goto loc_75f8;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 4))
        goto loc_7610;
loc_75f8: // 01ed:5728
    if ((short)memoryAGet16(ss, bp - 4) >= (short)0x0000)
        goto loc_7606;
    memoryASet16(ds, 0x0a9e, 0xfff1);
    goto loc_760c;
loc_7606: // 01ed:5736
    memoryASet16(ds, 0x0a9e, 0xfff6);
loc_760c: // 01ed:573c
    ax = 0;
    goto loc_7613;
loc_7610: // 01ed:5740
    ax = 0x0001;
loc_7613: // 01ed:5743
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_7649() // 01ed:5779
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0418, cs);
    memoryASet16(ds, 0x0416, 0x53b5);
    memoryASet16(ds, 0x0414, cs);
    memoryASet16(ds, 0x0412, 0x53b5);
    memoryASet16(ds, 0x05f9, 0x0000);
    memoryASet16(ds, 0x05f7, 0x0000);
    memoryASet16(ds, 0x0607, 0x0000);
    memoryASet16(ds, 0x0605, 0x0000);
    memoryASet16(ds, 0x05fd, 0x0000);
    memoryASet16(ds, 0x05fb, 0x0000);
    memoryASet16(ds, 0x0603, 0x0000);
    memoryASet16(ds, 0x0601, 0x0000);
    memoryASet16(ds, 0x0b5f, 0x0000);
    memoryASet16(ds, 0x0b5d, 0x0000);
    memoryASet16(ds, 0x0b61, 0x0000);
    memoryASet16(ds, 0x061a, 0x0000);
    memoryASet16(ds, 0x0616, 0x0000);
}
void sub_76cd() // 01ed:57fd
{
    CStackGuard sg(14, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0064;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, 0x0000);
    push(ss);
    ax = bp - 0x64;
    push(ax);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    sub_704a();
    push(ss);
    ax = bp - 0x64;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_7091();
    memoryASet16(ds, 0x0a9e, ax);
    if (!ax)
        goto loc_770c;
    ax = 0x0001;
    goto loc_770e;
loc_770c: // 01ed:583c
    ax = 0;
loc_770e: // 01ed:583e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 14;
}
void sub_7714() // 01ed:5844
{
    CStackGuard sg(6, true);
    push(0x7777);
    push(si);
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 10);
    push(ds);
    ax = 0x0501;
    push(ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1588);
    dx = ds;
    push(dx);
    push(ax);
    push(ds);
    ax = 0x0941;
    push(ax);
    sub_704a();
    bx = si;
    bx <<= 1;
    bx <<= 1;
    dx = memoryAGet16(ds, bx + 1566);
    ax = memoryAGet16(ds, bx + 1564);
    memoryASet16(ds, 0x0418, dx);
    memoryASet16(ds, 0x0416, ax);
    dx |= ax;
    if (!dx)
        goto loc_7762;
    memoryASet16(ds, 0x05fd, 0x0000);
    memoryASet16(ds, 0x05fb, 0x0000);
    memoryASet16(ds, 0x05ff, 0x0000);
    goto loc_780b;
loc_7762: // 01ed:5892
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(ds);
    ax = 0x0501;
    push(ax);
    push(ds);
    ax = 0x05ff;
    push(ax);
    ax = 0xfffc;
    push(ax);
    sub_76cd();
    if (!ax)
        goto loc_7796;
    ax = 0;
    push(ax);
    push(ax);
    push(ds);
    ax = 0x0501;
    push(ax);
    push(ds);
    ax = 0x05ff;
    push(ax);
    ax = 0xfffc;
    push(ax);
    sub_76cd();
    if (ax)
        goto loc_77f2;
loc_7796: // 01ed:58c6
    push(memoryAGet16(ds, 0x05ff));
    push(ds);
    ax = 0x05fb;
    push(ax);
    sub_72a8();
    sp = bp;
    if (!ax)
        goto loc_77b3;
    sub_7088();
    memoryASet16(ds, 0x0a9e, 0xfffb);
    goto loc_77f2;
loc_77b3: // 01ed:58e3
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x05ff));
    push(memoryAGet16(ds, 0x05fd));
    push(memoryAGet16(ds, 0x05fb));
    sub_70d8();
    if (ax)
        goto loc_77e4;
    push(memoryAGet16(ds, 0x05fd));
    push(memoryAGet16(ds, 0x05fb));
    push(cs);
    sub_734d();
    sp = bp;
    if (ax == si)
        goto loc_77f6;
    sub_7088();
    memoryASet16(ds, 0x0a9e, 0xfffc);
loc_77e4: // 01ed:5914
    push(memoryAGet16(ds, 0x05ff));
    push(ds);
    ax = 0x05fb;
    push(ax);
    sub_72d9();
    sp = bp;
loc_77f2: // 01ed:5922
    ax = 0;
    goto loc_780e;
loc_77f6: // 01ed:5926
    bx = si;
    bx <<= 1;
    bx <<= 1;
    tx = bx;
    bx = memoryAGet16(ds, tx + 1564);
    es = memoryAGet16(ds, tx + 1564 + 2);
    memoryASet16(ds, 0x0418, es);
    memoryASet16(ds, 0x0416, bx);
    sub_7088();
loc_780b: // 01ed:593b
    ax = 0x0001;
loc_780e: // 01ed:593e
    bp = pop();
    si = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_7813() // 01ed:5943
{
    CStackGuard sg(0, false);
    push(si);
    ax = memoryAGet16(ds, 0x0ac3);
    ax--;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    bx += memoryAGet16(ds, 0x0b4f);
    al = memoryAGet(ds, bx + 1600);
    ah = 0x00;
    si = ax;
    ax = memoryAGet16(ds, 0x0ac3);
    ax -= 0x0003;
    if (ax > 0x0002)
        goto loc_788d;
    bx = ax;
    bx <<= 1;
    callIndirect(cs, memoryAGet16(cs, bx + 22895)); // 01ed:596a
    return;
    //   gap of 78 bytes
loc_788d: // 01ed:59bd
    if (si == 0x0001)
        goto loc_7897;
    if (si != 0x0004)
        goto loc_78aa;
loc_7897: // 01ed:59c7
    bx = 0x0b3e;
    push(ds);
    push(bx);
    bx = 0x06fc;
    push(ds);
    push(bx);
    cx = 0x0011;
    push(cs);
    sub_653c();
    goto loc_78bb;
loc_78aa: // 01ed:59da
    bx = 0x0b3e;
    push(ds);
    push(bx);
    bx = 0x06b8;
    push(ds);
    push(bx);
    cx = 0x0011;
    push(cs);
    sub_653c();
loc_78bb: // 01ed:59eb
    ax = si;
    memoryASet(ds, 0x0b3e, al);
    si = pop();
}
void sub_78c2() // 01ed:59f2
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    if (memoryAGet16(ds, 0x0616) != 0x0000)
        goto loc_78d4;
    push(cs);
    sub_7285();
loc_78d4: // 01ed:5a04
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ds, 0x0b2d));
    push(memoryAGet16(ds, 0x0b2b));
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_7c68();
    sp += 0x000a;
    sub_7813();
    if (memoryAGet(ds, 0x0b3e) == 0x01)
        goto loc_78fd;
    ax = 0;
    push(ax);
    push(cs);
    sub_8067();
    cx = pop();
loc_78fd: // 01ed:5a2d
    memoryASet(ds, 0x060f, 0x00);
    push(cs);
    sub_81ca();
    push(ax);
    push(cs);
    sub_89d4();
    cx = pop();
    push(cs);
    sub_81ca();
    push(ax);
    push(ds);
    ax = 0x070d;
    push(ax);
    push(cs);
    sub_7f5c();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    push(ax);
    push(ax);
    push(ax);
    push(cs);
    sub_853c();
    sp += 0x0008;
    push(cs);
    sub_81ca();
    push(ax);
    ax = 0x0001;
    push(ax);
    push(cs);
    sub_7f05();
    cx = pop();
    cx = pop();
    ax = 0x0001;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_7e5b();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_834d();
    sp += 0x0006;
    ax = 0x0002;
    push(ax);
    ax = 0;
    push(ax);
    push(cs);
    sub_830d();
    cx = pop();
    cx = pop();
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_7d6e();
    cx = pop();
    cx = pop();
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7972() // 01ed:5aa2
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    sp -= 0x0008;
    memoryASet16(ss, bp - 2, cs);
    memoryASet16(ss, bp - 4, 0x6f70);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    dx = memoryAGet16(es, bx);
    dx += bx;
    cx = 0x0004;
    dx >>= cl;
    ax = cs;
    dx += ax;
    ax = 0;
    memoryASet16(ds, 0x0414, dx);
    memoryASet16(ds, 0x0412, ax);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    push(memoryAGet16(es, bx));
    bx = memoryAGet16(ss, bp + 16);
    es = memoryAGet16(ss, bp + 16 + 2);
    push(memoryAGet16(es, bx));
    sub_75cb();
    if (ax)
        goto loc_79b8;
    goto loc_7a5e;
loc_79b8: // 01ed:5ae8
    push(memoryAGet16(ss, bp + 18));
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(ds);
    ax = 0x0b3c;
    push(ax);
    push(cs);
    sub_877b();
    sp += 0x000c;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_79e7;
    memoryASet16(ds, 0x0a9e, 0xfffe);
    memoryASet16(es, bx, 0xfffe);
    goto loc_7ac3;
loc_79e7: // 01ed:5b17
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x0ac3, ax);
    bx = memoryAGet16(ss, bp + 16);
    es = memoryAGet16(ss, bp + 16 + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x0b4f, ax);
    ax = memoryAGet16(ss, bp + 20);
    ax |= memoryAGet16(ss, bp + 22);
    if (ax)
        goto loc_7a08;
    memoryASet(ds, 0x050e, 0x00);
    goto loc_7a4e;
loc_7a08: // 01ed:5b38
    push(ds);
    ax = 0x050e;
    push(ax);
    push(memoryAGet16(ss, bp + 22));
    push(memoryAGet16(ss, bp + 20));
    sub_7010();
    if (memoryAGet(ds, 0x050e) == 0x00)
        goto loc_7a4e;
    push(ds);
    ax = 0x050e;
    push(ax);
    sub_702f();
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    bx--;
    if (memoryAGet(es, bx) == 0x3a)
        goto loc_7a4e;
    bx = ax;
    bx--;
    if (memoryAGet(es, bx) == 0x5c)
        goto loc_7a4e;
    bx = ax;
    memoryASet(es, bx, 0x5c);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    bx = memoryAGet16(ss, bp - 8);
    memoryASet(es, bx, 0x00);
loc_7a4e: // 01ed:5b7e
    push(memoryAGet16(ds, 0x0b3c));
    push(ds);
    ax = 0x050e;
    push(ax);
    sub_7714();
    if (ax)
        goto loc_7a6a;
loc_7a5e: // 01ed:5b8e
    ax = memoryAGet16(ds, 0x0a9e);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx, ax);
    goto loc_7ac3;
loc_7a6a: // 01ed:5b9a
    push(cs);
    sub_85c1();
    push(si);
    push(di);
    push(ds);
    es = pop();
    di = 0x0b29;
    si = memoryAGet16(ds, 0x0609);
    ds = memoryAGet16(ds, 0x060b);
    cx = 0x0013;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = 0x0b51;
    cx = 0x0016;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    ax = es;
    ds = ax;
    di = pop();
    si = pop();
    push(memoryAGet16(ds, 0x055f));
    push(ds);
    ax = 0x0b5d;
    push(ax);
    sub_72a8();
    sp += 0x0006;
    if (!ax)
        goto loc_7ac8;
    memoryASet16(ds, 0x0a9e, 0xfffb);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx, 0xfffb);
    push(memoryAGet16(ds, 0x05ff));
    push(ds);
    ax = 0x05fb;
    push(ax);
    sub_72d9();
    sp += 0x0006;
loc_7ac3: // 01ed:5bf3
    sub_7649();
    goto loc_7aff;
loc_7ac8: // 01ed:5bf8
    bx = memoryAGet16(ds, 0x0b5d);
    es = memoryAGet16(ds, 0x0b5d + 2);
    memoryASet16(ds, 0x0603, es);
    memoryASet16(ds, 0x0601, bx);
    ax = memoryAGet16(ds, 0x055f);
    memoryASet16(ds, 0x0b61, ax);
    memoryASet16(ds, 0x0b65, ds);
    memoryASet16(ds, 0x0b63, 0x0a9e);
    push(ds);
    ax = 0x0b51;
    push(ax);
    push(cs);
    sub_8810();
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x0616, 0x0001);
    push(cs);
    sub_78c2();
    memoryASet16(ds, 0x0a9e, 0x0000);
loc_7aff: // 01ed:5c2f
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7b86() // 01ed:5cb6
{
    CStackGuardFar sg(0, false);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    push(cs);
    sub_8651();
    ax = memoryAGet16(ds, 0x05f7);
    ax |= memoryAGet16(ds, 0x05f9);
    if (ax)
        goto loc_7bb0;
    bx = memoryAGet16(ds, 0x0412);
    es = memoryAGet16(ds, 0x0412 + 2);
    memoryASet16(ds, 0x05f9, es);
    memoryASet16(ds, 0x05f7, bx);
    memoryASet16(ds, 0x0414, cs);
    memoryASet16(ds, 0x0412, 0x53b5);
loc_7bb0: // 01ed:5ce0
    bp = pop();
    ds = pop();
    cs = pop();
}
void sub_7bb3() // 01ed:5ce3
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    if (memoryAGet16(ds, 0x0616) != 0x0000)
        goto loc_7bc6;
    goto loc_7c4b;
loc_7bc6: // 01ed:5cf6
    push(cs);
    sub_7b86();
    push(memoryAGet16(ds, 0x055f));
    push(ds);
    ax = 0x0601;
    push(ax);
    sub_72d9();
    sp += 0x0006;
    ax = memoryAGet16(ds, 0x05fb);
    ax |= memoryAGet16(ds, 0x05fd);
    if (!ax)
        goto loc_7c05;
    push(memoryAGet16(ds, 0x05ff));
    push(ds);
    ax = 0x05fb;
    push(ax);
    sub_72d9();
    sp += 0x0006;
    bx = memoryAGet16(ds, 0x0b3c);
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 1566, 0x0000);
    memoryASet16(ds, bx + 1564, 0x0000);
loc_7c05: // 01ed:5d35
    sub_7649();
    di = 0;
    si = 0x0561;
    goto loc_7c46;
loc_7c0f: // 01ed:5d3f
    if (memoryAGet(ds, si + 10) == 0x00)
        goto loc_7c42;
    if (memoryAGet16(ds, si + 8) == 0x0000)
        goto loc_7c42;
    push(memoryAGet16(ds, si + 8));
    ax = si;
    dx = ds;
    push(dx);
    push(ax);
    sub_72d9();
    sp += 0x0006;
    memoryASet16(ds, si + 2, 0x0000);
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, si + 4, 0x0000);
    memoryASet16(ds, si + 8, 0x0000);
loc_7c42: // 01ed:5d72
    di++;
    si += 0x000f;
loc_7c46: // 01ed:5d76
    if (di < 0x000a)
        goto loc_7c0f;
loc_7c4b: // 01ed:5d7b
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7c50() // 01ed:5d80
{
    CStackGuardFar sg(0, false);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    push(cs);
    sub_8835();
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_7d6e();
    cx = pop();
    cx = pop();
    bp = pop();
    ds = pop();
    cs = pop();
}
void sub_7c68() // 01ed:5d98
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    di = memoryAGet16(ss, bp + 14);
    si = memoryAGet16(ss, bp + 12);
    if ((short)si < 0)
        goto loc_7ca1;
    if ((short)di < 0)
        goto loc_7ca1;
    ax = memoryAGet16(ss, bp + 16);
    if (ax > memoryAGet16(ds, 0x0b2b))
        goto loc_7ca1;
    ax = memoryAGet16(ss, bp + 18);
    if (ax > memoryAGet16(ds, 0x0b2d))
        goto loc_7ca1;
    ax = memoryAGet16(ss, bp + 16);
    if ((short)ax < (short)si)
        goto loc_7ca1;
    ax = memoryAGet16(ss, bp + 18);
    if ((short)ax >= (short)di)
        goto loc_7ca9;
loc_7ca1: // 01ed:5dd1
    memoryASet16(ds, 0x0a9e, 0xfff5);
    goto loc_7cdc;
loc_7ca9: // 01ed:5dd9
    memoryASet16(ds, 0x0a94, si);
    memoryASet16(ds, 0x0a96, di);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(ds, 0x0a98, ax);
    ax = memoryAGet16(ss, bp + 18);
    memoryASet16(ds, 0x0a9a, ax);
    ax = memoryAGet16(ss, bp + 20);
    memoryASet16(ds, 0x0a9c, ax);
    push(ax);
    push(memoryAGet16(ss, bp + 18));
    push(memoryAGet16(ss, bp + 16));
    push(di);
    push(si);
    push(cs);
    sub_85f1();
    sp = bp;
    ax = 0;
    push(ax);
    push(ax);
    push(cs);
    sub_7d6e();
    sp = bp;
loc_7cdc: // 01ed:5e0c
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7d6e() // 01ed:5e9e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_884c();
    sp = bp;
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x0612, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x0614, ax);
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7e5b() // 01ed:5f8b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    di = memoryAGet16(ss, bp + 16);
    si = memoryAGet16(ss, bp + 12);
    if (si > 0x0004)
        goto loc_7e76;
    if (di <= 0x0003)
        goto loc_7e7e;
loc_7e76: // 01ed:5fa6
    memoryASet16(ds, 0x0a9e, 0xfff5);
    goto loc_7e95;
loc_7e7e: // 01ed:5fae
    memoryASet16(ds, 0x0b67, si);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ds, 0x0b69, ax);
    memoryASet16(ds, 0x0b6b, di);
    push(di);
    push(ax);
    push(si);
    push(cs);
    sub_8a74();
    sp = bp;
loc_7e95: // 01ed:5fc5
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7e9a() // 01ed:5fca
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    di = memoryAGet16(ss, bp + 14);
    si = memoryAGet16(ss, bp + 12);
    push(di);
    push(memoryAGet16(ss, bp + 16));
    push(di);
    push(si);
    push(cs);
    sub_8886();
    sp = bp;
    push(memoryAGet16(ss, bp + 18));
    push(memoryAGet16(ss, bp + 16));
    push(di);
    push(memoryAGet16(ss, bp + 16));
    push(cs);
    sub_8886();
    sp = bp;
    push(memoryAGet16(ss, bp + 18));
    push(si);
    push(memoryAGet16(ss, bp + 18));
    push(memoryAGet16(ss, bp + 16));
    push(cs);
    sub_8886();
    sp = bp;
    push(di);
    push(si);
    push(memoryAGet16(ss, bp + 18));
    push(si);
    push(cs);
    sub_8886();
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7f05() // 01ed:6035
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    di = memoryAGet16(ss, bp + 14);
    si = memoryAGet16(ss, bp + 12);
    if (si > 0x000b)
        goto loc_7f1f;
    if ((short)di >= 0)
        goto loc_7f27;
loc_7f1f: // 01ed:604f
    memoryASet16(ds, 0x0a9e, 0xfff5);
    goto loc_7f37;
loc_7f27: // 01ed:6057
    memoryASet16(ds, 0x0aae, si);
    memoryASet16(ds, 0x0ab0, di);
    push(di);
    push(si);
    push(cs);
    sub_8ae2();
    sp = bp;
loc_7f37: // 01ed:6067
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7f5c() // 01ed:608c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    push(cs);
    sub_81ca();
    if (ax >= memoryAGet16(ss, bp + 16))
        goto loc_7f78;
    memoryASet16(ds, 0x0a9e, 0xfff5);
    goto loc_7fa9;
loc_7f78: // 01ed:60a8
    memoryASet16(ds, 0x0aae, 0x000c);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(ds, 0x0ab0, ax);
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 12);
    ds = memoryAGet16(ss, bp + 12 + 2);
    ax = ds;
    es = ax;
    di = 0x0b6d;
    cx = 0x0008;
    flags.direction = false;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = ax;
    di = pop();
    si = pop();
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(cs);
    sub_86d9();
    sp = bp;
loc_7fa9: // 01ed:60d9
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_7fae() // 01ed:60de
{
    CStackGuard sg(2, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = 0;
    ax = 0x2710;
    push(dx);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = 0;
    bx = memoryAGet16(ds, 0x0b37);
    cx = 0;
    push(cs);
    sub_636f();
    push(dx);
    push(ax);
    push(cs);
    sub_620d();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_7ff9() // 01ed:6129
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    push(memoryAGet16(ss, bp + 12));
    sub_7fae();
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    ax = 0x0168;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_894b();
    sp = bp;
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8067() // 01ed:6197
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    si = memoryAGet16(ss, bp + 10);
    if (si > 0x000f)
        goto loc_809a;
    ax = si;
    memoryASet(ds, 0x060f, al);
    if (si)
        goto loc_8089;
    memoryASet(ds, 0x0b3f, 0x00);
    goto loc_8090;
loc_8089: // 01ed:61b9
    al = memoryAGet(ds, si + 2879);
    memoryASet(ds, 0x0b3f, al);
loc_8090: // 01ed:61c0
    al = memoryAGet(ds, 0x0b3f);
    cbw();
    push(ax);
    push(cs);
    sub_89f5();
    cx = pop();
loc_809a: // 01ed:61ca
    bp = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_81ca() // 01ed:62fa
{
    CStackGuardFar sg(0, false);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    if (memoryAGet16(ds, 0x0616) == 0x0000)
        goto loc_81ef;
    ax = memoryAGet16(ds, 0x0ac3);
    ax--;
    dx = 0x0006;
    mul(dx);
    bx = ax;
    bx += memoryAGet16(ds, 0x0b4f);
    al = memoryAGet(ds, bx + 1660);
    ah = 0x00;
    goto loc_81f1;
loc_81ef: // 01ed:631f
    ax = 0;
loc_81f1: // 01ed:6321
    bp = pop();
    ds = pop();
    cs = pop();
}
void sub_81f4() // 01ed:6324
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_8729();
    sp = bp;
    si = ax;
    ax = si;
    if (ax != 0xffff)
        goto loc_8223;
    memoryASet16(ds, 0x0a9e, 0xfff5);
    ax = 0;
    goto loc_8225;
loc_8223: // 01ed:6353
    ax = si;
loc_8225: // 01ed:6355
    bp = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_82c4() // 01ed:63f4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ds, 0x0614));
    push(memoryAGet16(ds, 0x0612));
    push(cs);
    sub_8b12();
    sp = bp;
    if (memoryAGet16(ds, 0x0abf) != 0x0000)
        goto loc_830a;
    if (memoryAGet16(ds, 0x0abb) != 0x0000)
        goto loc_830a;
    push(memoryAGet16(ds, 0x0614));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_8bb4();
    cx = pop();
    cx = pop();
    ax += memoryAGet16(ds, 0x0612);
    push(ax);
    push(cs);
    sub_7d6e();
    sp = bp;
loc_830a: // 01ed:643a
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_830d() // 01ed:643d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    di = memoryAGet16(ss, bp + 14);
    si = memoryAGet16(ss, bp + 12);
    if ((short)si < 0)
        goto loc_8330;
    if ((short)si > (short)0x0002)
        goto loc_8330;
    if ((short)di < 0)
        goto loc_8330;
    if ((short)di <= (short)0x0002)
        goto loc_8338;
loc_8330: // 01ed:6460
    memoryASet16(ds, 0x0a9e, 0xfff5);
    goto loc_8348;
loc_8338: // 01ed:6468
    memoryASet16(ds, 0x0abf, si);
    memoryASet16(ds, 0x0ac1, di);
    push(di);
    push(si);
    push(cs);
    sub_870c();
    sp = bp;
loc_8348: // 01ed:6478
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_834d() // 01ed:647d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(si);
    push(di);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    sp -= 0x000c;
    si = memoryAGet16(ss, bp + 12);
    if ((short)si > (short)0x000a)
        goto loc_837c;
    if ((short)si < 0)
        goto loc_837c;
    if (!si)
        goto loc_8385;
    ax = si;
    ax--;
    dx = 0x000f;
    mul(dx);
    bx = ax;
    if (memoryAGet(ds, bx + 1387) != 0x00)
        goto loc_8385;
loc_837c: // 01ed:64ac
    memoryASet16(ds, 0x0a9e, 0xfff2);
    goto loc_8512;
loc_8385: // 01ed:64b5
    if (si)
        goto loc_838c;
    goto loc_8519;
loc_838c: // 01ed:64bc
    if (si != memoryAGet16(ds, 0x0ab9))
        goto loc_8395;
    goto loc_8519;
loc_8395: // 01ed:64c5
    ax = si;
    ax--;
    dx = 0x000f;
    mul(dx);
    di = ax;
    di += 0x0561;
    if (si != memoryAGet16(ds, 0x061a))
        goto loc_83ac;
    goto loc_84ff;
loc_83ac: // 01ed:64dc
    if (memoryAGet16(ds, 0x061a) == 0x0000)
        goto loc_83fe;
    ax = memoryAGet16(ds, 0x061a);
    ax--;
    dx = 0x000f;
    mul(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 1385) == 0x0000)
        goto loc_83fe;
    ax = memoryAGet16(ds, 0x061a);
    ax--;
    dx = 0x000f;
    mul(dx);
    ax += 0x0561;
    memoryASet16(ss, bp - 2, ax);
    bx = ax;
    push(memoryAGet16(ds, bx + 8));
    dx = ds;
    push(dx);
    push(ax);
    sub_72d9();
    sp += 0x0006;
    bx = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, bx + 2, 0x0000);
    memoryASet16(ds, bx, 0x0000);
    memoryASet16(ds, bx + 6, 0x0000);
    memoryASet16(ds, bx + 4, 0x0000);
    memoryASet16(ds, bx + 8, 0x0000);
loc_83fe: // 01ed:652e
    ax = memoryAGet16(ds, di + 4);
    ax |= memoryAGet16(ds, di + 6);
    if (!ax)
        goto loc_8409;
    goto loc_84fb;
loc_8409: // 01ed:6539
    push(ds);
    ax = 0x04f8;
    push(ax);
    ax = di;
    ax += 0x000a;
    dx = ds;
    push(dx);
    push(ax);
    push(ds);
    ax = 0x0946;
    push(ax);
    sub_704a();
    push(ds);
    ax = 0x050e;
    push(ax);
    push(ds);
    ax = 0x04f8;
    push(ax);
    push(ss);
    ax = bp - 0xc;
    push(ax);
    ax = 0xfff3;
    push(ax);
    sub_76cd();
    if (!ax)
        goto loc_8465;
    ax = 0;
    push(ax);
    push(ax);
    push(ds);
    ax = 0x04f8;
    push(ax);
    push(ss);
    ax = bp - 0xc;
    push(ax);
    ax = 0xfff3;
    push(ax);
    sub_76cd();
    if (!ax)
        goto loc_8465;
    if (memoryAGet16(ds, 0x0a9e) == 0xfffd)
        goto loc_845c;
    goto loc_8512;
loc_845c: // 01ed:658c
    memoryASet16(ds, 0x0a9e, 0xfff8);
    goto loc_8512;
loc_8465: // 01ed:6595
    ax = memoryAGet16(ss, bp - 12);
    ax += 0x0010;
    push(ax);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    sub_72a8();
    sp += 0x0006;
    if (!ax)
        goto loc_8487;
    sub_7088();
    memoryASet16(ds, 0x0a9e, 0xfff7);
    goto loc_8512;
loc_8487: // 01ed:65b7
    dx = memoryAGet16(ss, bp - 8);
    ax = memoryAGet16(ss, bp - 10);
    ax += 0x000f;
    cx = 0x0004;
    ax >>= cl;
    dx += ax;
    ax = 0;
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 6, ax);
    push(ax);
    push(memoryAGet16(ss, bp - 12));
    push(dx);
    push(ax);
    sub_70d8();
    if (!ax)
        goto loc_84c0;
    ax = memoryAGet16(ss, bp - 12);
    ax += 0x0010;
    push(ax);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    sub_72d9();
    sp += 0x0006;
    goto loc_8512;
loc_84c0: // 01ed:65f0
    sub_7088();
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    sub_73e3();
    cx = pop();
    cx = pop();
    if (ax == si)
        goto loc_84e7;
    ax = memoryAGet16(ss, bp - 12);
    ax += 0x0010;
    push(ax);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    sub_72d9();
    sp += 0x0006;
    goto loc_850c;
loc_84e7: // 01ed:6617
    dx = memoryAGet16(ss, bp - 8);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ds, di + 2, dx);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ss, bp - 12);
    ax += 0x0010;
    memoryASet16(ds, di + 8, ax);
loc_84fb: // 01ed:662b
    memoryASet16(ds, 0x061a, si);
loc_84ff: // 01ed:662f
    bx = memoryAGet16(ds, di + 4);
    es = memoryAGet16(ds, di + 4 + 2);
    memoryASet16(ds, 0x0607, es);
    memoryASet16(ds, 0x0605, bx);
    goto loc_8519;
loc_850c: // 01ed:663c
    memoryASet16(ds, 0x0a9e, 0xfff3);
loc_8512: // 01ed:6642
    si = 0;
    memoryASet16(ss, bp + 16, 0x0001);
loc_8519: // 01ed:6649
    memoryASet16(ds, 0x0ab9, si);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(ds, 0x0abb, ax);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(ds, 0x0abd, ax);
    push(ax);
    push(memoryAGet16(ss, bp + 14));
    push(si);
    push(cs);
    sub_8b48();
    sp += 0x0006;
    sp = bp;
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_853c() // 01ed:666c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    push(bp);
    ds = memoryAGet16(cs, 0x01a3);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    if (ax > memoryAGet16(ds, 0x0b2b))
        goto loc_8579;
    ax = memoryAGet16(ss, bp + 10);
    if (ax > memoryAGet16(ds, 0x0b2b))
        goto loc_8579;
    ax = memoryAGet16(ss, bp + 12);
    if (ax > memoryAGet16(ds, 0x0b2d))
        goto loc_8579;
    ax = memoryAGet16(ss, bp + 14);
    if (ax > memoryAGet16(ds, 0x0b2d))
        goto loc_8579;
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_8b8e();
    sp = bp;
loc_8579: // 01ed:66a9
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_858c() // 01ed:66bc
{
    assert(es == 0x043e && bx == 0x0072);
//    push(es);
//    push(bx);
    push(cs);
    cs = es;
    sub_4452();
    cs = pop();
}
void sub_858f() // 01ed:66bf
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x0955) != 0xff)
        return;
    ah = 0x0f;
    interrupt(0x10);
    memoryASet(ds, 0x0955, al);
    ax = 0x0040;
    es = ax;
    bx = 0x0010;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x0956, al);
    if (memoryAGet(ds, 0x094e) == 0x05)
        return;
    if (memoryAGet(ds, 0x094e) == 0x07)
        return;
    al &= 0xcf;
    al |= 0x10;
    memoryASet(es, bx, al);
}
void sub_85c1() // 01ed:66f1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    memoryASet(ds, 0x0955, 0xff);
    al = 0;
    ch = 0;
    cl = memoryAGet(ds, 0x094d);
    bx = memoryAGet16(ds, 0x0416);
    es = memoryAGet16(ds, 0x0416 + 2);
    si = 0x0000;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    memoryASet16(ds, 0x060b, es);
    memoryASet16(ds, 0x0609, bx);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_85f1() // 01ed:6721
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    if (memoryAGet(ss, bp + 14) != 0x00)
        goto loc_8611;
    ah |= 0x80;
loc_8611: // 01ed:6741
    si = 0x0038;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8651() // 01ed:6781
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    if (memoryAGet(ds, 0x0955) == 0xff)
        goto loc_8684;
    si = 0x0006;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    ax = 0x0040;
    es = ax;
    bx = 0x0010;
    al = memoryAGet(ds, 0x0956);
    memoryASet(es, bx, al);
    ah = 0;
    al = memoryAGet(ds, 0x0955);
    interrupt(0x10);
    memoryASet(ds, 0x0955, 0xff);
loc_8684: // 01ed:67b4
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_86d9() // 01ed:6809
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ah = memoryAGet(ss, bp + 10);
    memoryASet(ds, 0x060e, ah);
    al = memoryAGet(ds, 0x060d);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    memoryASet(ds, 0x0611, 0x0c);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = 0xffff;
    si = 0x0020;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_870c() // 01ed:683c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ah = memoryAGet(ss, bp + 6);
    al = memoryAGet(ss, bp + 8);
    si = 0x002a;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8729() // 01ed:6859
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax -= memoryAGet16(ss, bp + 6);
    if ((short)ax >= 0)
        goto loc_873e;
    ax = -ax;
loc_873e: // 01ed:686e
    ax++;
    ax += 0x0007;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    push(ax);
    si = 0x0032;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    bx = memoryAGet16(es, bx + 8);
    push(cs);
    sub_858c();
    bx = pop();
    mul(bx);
    cx = memoryAGet16(ss, bp + 12);
    cx -= memoryAGet16(ss, bp + 8);
    if ((short)cx >= 0)
        goto loc_8765;
    cx = -cx;
loc_8765: // 01ed:6895
    cx++;
    mul(cx);
    flags.carry = (ax + 0x0006) >= 0x10000;
    ax += 0x0006;
    if (flags.carry)
        goto loc_8771;
    if (dx == 0)
        goto loc_8776;
loc_8771: // 01ed:68a1
    ax = 0xffff;
    dx = ax;
loc_8776: // 01ed:68a6
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_877b() // 01ed:68ab
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    memoryASet(ds, 0x094c, 0xff);
    memoryASet(ds, 0x094d, 0x00);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(es, di);
    memoryASet(ds, 0x094e, al);
    if (al != 0)
        goto loc_87ab;
    bp += 0x0004;
    sub_87ee();
    bp -= 0x0004;
    al = memoryAGet(ds, 0x094c);
    goto loc_87c6;
loc_87ab: // 01ed:68db
    di = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    al = memoryAGet(es, di);
    memoryASet(ds, 0x094d, al);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bl = memoryAGet(es, di);
    bh = 0;
    bx += 0x6dd3;
    al = memoryAGet(cs, bx);
    memoryASet(ds, 0x094c, al);
loc_87c6: // 01ed:68f6
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ah = 0;
    memoryASet16(es, di, ax);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_87ee() // 01ed:691e
{
    CStackGuard sg(0, false);
    push(bp);
    sub_8cc7();
    bp = pop();
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(ds, 0x094e);
    ah = 0;
    if (al != 0xff)
        goto loc_8801;
    ah = al;
loc_8801: // 01ed:6931
    memoryASet16(es, di, ax);
    ah = 0;
    al = memoryAGet(ds, 0x094d);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet16(es, di, ax);
}
void sub_8810() // 01ed:6940
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    sub_858f();
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ds, 0x0951, bx);
    memoryASet16(ds, 0x0953, es);
    si = 0x0002;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8835() // 01ed:6965
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    si = 0x0004;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_884c() // 01ed:697c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8886() // 01ed:69b6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    si = 0x000c;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_88e9() // 01ed:6a19
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    si = 0x0012;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_894b() // 01ed:6a7b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    ax = memoryAGet16(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 12);
    cx = memoryAGet16(ss, bp + 14);
    dx = memoryAGet16(ss, bp + 16);
    si = 0x0014;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_89d4() // 01ed:6b04
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x060d, al);
    ah = memoryAGet(ds, 0x060e);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_89f5() // 01ed:6b25
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    bl = memoryAGet(ss, bp + 6);
    bh = 0;
    ax = 0xffff;
    si = 0x001a;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8a74() // 01ed:6ba4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet(ds, 0x0610, al);
    bx = memoryAGet16(ss, bp + 8);
    cl = memoryAGet(ss, bp + 10);
    memoryASet(ds, 0x0950, cl);
    ch = 0;
    si = 0x0022;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8ae2() // 01ed:6c12
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ah = memoryAGet(ss, bp + 8);
    memoryASet(ds, 0x060e, ah);
    al = memoryAGet(ds, 0x060d);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, 0x0611, al);
    ah = al;
    si = 0x0020;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8b12() // 01ed:6c42
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    di = bx;
    al = 0;
    cx = 0xffff;
    flags.direction = false;
    repne_scasb<MemAuto, DirAuto>(al);
    cx = di;
    cx -= bx;
    cx--;
    si = 0x0026;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8b48() // 01ed:6c78
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    bx = memoryAGet16(ds, 0x0609);
    es = memoryAGet16(ds, 0x0609 + 2);
    bx = memoryAGet16(es, bx + 16);
    bx &= 0x7f7f;
    dl = memoryAGet(ss, bp + 10);
    al = bh;
    mul(dl);
    cx = ax;
    al = bl;
    mul(dl);
    bx = ax;
    al = memoryAGet(ss, bp + 6);
    ah = memoryAGet(ss, bp + 8);
    if (al == 0)
        goto loc_8b82;
    cl = dl;
    ch = 0;
    bx = cx;
    dx = memoryAGet16(ds, 0x0607);
loc_8b82: // 01ed:6cb2
    si = 0x0024;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8b8e() // 01ed:6cbe
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    ah |= 0x80;
    si = 0x0024;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8bb4() // 01ed:6ce4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    di = bx;
    al = 0;
    cx = 0xffff;
    flags.direction = false;
    repne_scasb<MemAuto, DirAuto>(al);
    cx = di;
    cx -= bx;
    cx--;
    si = 0x0028;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    ax = bx;
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8c43() // 01ed:6d73
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ds = memoryAGet16(cs, 0x01a3);
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    cx = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 8);
    si = memoryAGet16(ss, bp + 10);
    di = memoryAGet16(ss, bp + 12);
    if (cx < si)
        goto loc_8c63;
    tx = cx;
    cx = si;
    si = tx;
loc_8c63: // 01ed:6d93
    if (dx < di)
        goto loc_8c69;
    tx = dx;
    dx = di;
    di = tx;
loc_8c69: // 01ed:6d99
    si -= cx;
    memoryASet16(es, bx, si);
    di -= dx;
    memoryASet16(es, bx + 2, di);
    si = 0x0034;
    push(cs);
    cs = memoryAGet16(ds, 0x0412 + 2);
    callIndirect(memoryAGet16(ds, 0x0412 + 2), memoryAGet16(ds, 0x0412));
    assert(cs == 0x01ed);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_8cc7() // 01ed:6df7
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x094c, 0xff);
    memoryASet(ds, 0x094e, 0xff);
    memoryASet(ds, 0x094d, 0x00);
    sub_8cfd();
    bl = memoryAGet(ds, 0x094e);
    if (bl == 0xff)
        return;
    bh = 0;
    al = memoryAGet(cs, bx + 28115);
    memoryASet(ds, 0x094c, al);
    al = memoryAGet(cs, bx + 28127);
    memoryASet(ds, 0x094d, al);
    al = memoryAGet(cs, bx + 28139);
    memoryASet(ds, 0x094f, al);
}
void sub_8cfd() // 01ed:6e2d
{
    CStackGuard sg(0, false);
    ah = 0x0f;
    interrupt(0x10);
    if (al == 0x07)
        goto loc_8d36;
    sub_8ddb();
    if (!flags.carry)
        goto loc_8d10;
    memoryASet(ds, 0x094e, 0x06);
    return;
loc_8d10: // 01ed:6e40
    sub_8d64();
    if (!flags.carry)
        goto loc_8d19;
loc_8d15: // 01ed:6e45
    sub_8d82();
    return;
loc_8d19: // 01ed:6e49
    sub_8e10();
    if (ax == 0)
        goto loc_8d26;
    memoryASet(ds, 0x094e, 0x0a);
    return;
loc_8d26: // 01ed:6e56
    memoryASet(ds, 0x094e, 0x01);
    sub_8dba();
    if (!flags.carry)
        goto loc_8d35;
    memoryASet(ds, 0x094e, 0x02);
loc_8d35: // 01ed:6e65
    return;
loc_8d36: // 01ed:6e66
    sub_8d64();
    if (flags.carry)
        goto loc_8d15;
    sub_8dde();
    if (al == 0)
        goto loc_8d48;
    memoryASet(ds, 0x094e, 0x07);
    return;
loc_8d48: // 01ed:6e78
    si = 0xb800;
    es = si;
    si = 0;
    ax = memoryAGet16(es, si);
    ax = ~ax;
    memoryASet16(es, si, ~memoryAGet16(es, si));
    if (ax != memoryAGet16(es, si))
        return;
    memoryASet(ds, 0x094e, 0x01);
}
void sub_8d64() // 01ed:6e94
{
    CStackGuard sg(0, false);
    ax = 0x1200;
    bl = 0x10;
    bh = 0xff;
    cl = 0x0f;
    interrupt(0x10);
    if ((char)cl >= (char)0x0c)
        goto loc_8d80;
    if ((char)bh > (char)0x01)
        goto loc_8d80;
    if ((char)bl > (char)0x03)
        goto loc_8d80;
    flags.carry = true;
    return;
loc_8d80: // 01ed:6eb0
    flags.carry = false;
}
void sub_8d82() // 01ed:6eb2
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x094e, 0x04);
    if (bh == 0x01)
        goto loc_8da5;
    sub_8dab();
    if (flags.carry)
        goto loc_8da4;
    if (bl == 0)
        goto loc_8da4;
    memoryASet(ds, 0x094e, 0x03);
    sub_8dba();
    if (!flags.carry)
        goto loc_8da4;
    memoryASet(ds, 0x094e, 0x09);
loc_8da4: // 01ed:6ed4
    return;
loc_8da5: // 01ed:6ed5
    memoryASet(ds, 0x094e, 0x05);
}
// INJECT: Error: cannot inject flag in sub_8dab() because of being label!
void sub_8dab() // 01ed:6edb
{
    CStackGuard sg(0, false);
    if (cl < 0x02)
        goto loc_8db9;
    flags.carry = !flags.carry;
    if (stop(/*1 - jae loc_8db9*/))
        goto loc_8db9;
loc_8db9: // 01ed:6ee9
    stop(/*inject ret*/);
}
void sub_8dba() // 01ed:6eea
{
    CStackGuard sg(0, false);
    ax = 0x1a00;
    interrupt(0x10);
    if (al != 0x1a)
        goto loc_8dd9;
    if (bl == 0x07)
        goto loc_8dd7;
    if (bl == 0x08)
        goto loc_8dd7;
    if (bl < 0x0b)
        goto loc_8dd9;
    if (bl > 0x0c)
        goto loc_8dd9;
loc_8dd7: // 01ed:6f07
    flags.carry = true;
    return;
loc_8dd9: // 01ed:6f09
    flags.carry = false;
}
// INJECT: Error: cannot inject zero flag in sub_8ddb() because no traceback!
void sub_8ddb() // 01ed:6f0b
{
    CStackGuard sg(0, false);
    al = 0;
    stop(/*inject ret*/);
}
void sub_8dde() // 01ed:6f0e
{
    CStackGuard sg(0, false);
    dx = 0x03ba;
    bl = 0;
    in(al, dx);
    al &= 0x80;
    ah = al;
    cx = 0x8000;
loc_8deb: // 01ed:6f1b
    in(al, dx);
    al &= 0x80;
    if (al == ah)
        goto loc_8df9;
    bl++;
    if (bl >= 0x0a)
        goto loc_8dfe;
loc_8df9: // 01ed:6f29
    if (--cx)
        goto loc_8deb;
    al = 0;
    return;
loc_8dfe: // 01ed:6f2e
    cx = 0x8000;
loc_8e01: // 01ed:6f31
    in(al, dx);
    al &= 0x30;
    if (al != 0x10)
        goto loc_8e0d;
    if (--cx)
        goto loc_8e01;
    al = 0x02;
    return;
loc_8e0d: // 01ed:6f3d
    al = 0x01;
}
void sub_8e10() // 01ed:6f40
{
    CStackGuard sg(0, false);
    al = 0x06;
    cx = 0;
    dx = 0;
    ah = 0x30;
    interrupt(0x10);
    ax = cx;
    ax |= dx;
    if (!ax)
        goto loc_8e3d;
    push(ds);
    ds = cx;
    bx = dx;
    al = memoryAGet(ds, bx + 2);
    ds = pop();
    if (!al)
        goto loc_8e31;
    if (al != 0x02)
        goto loc_8e3d;
loc_8e31: // 01ed:6f61
    dx = 0x0188;
    in(al, dx);
    if (!(al & 0x04))
        goto loc_8e3d;
    ax = 0x0001;
    return;
loc_8e3d: // 01ed:6f6d
    ax = 0;
}
void sub_8e60() // 08e6:0000
{
    push(0xbcde);
    push(ds);
    push(cs);
    ds = pop();
    push(si);
    int oldsp = sp;
    switch (si)
    {
        case 0: sub_9032(); break;
        case 2: sub_9082(); break;
        case 4: sub_8ed9(); break;
        case 6: sub_8ed9(); break;
        case 8: sub_8f3c(); break;
        case 10: sub_8f4c(); break;
        case 12: sub_8f86(); break;
        case 14: sub_8eda(); break;
        case 16: sub_8f7d(); break;
        case 18: 
            sub_8fa0(); break;
        case 20: sub_8fa9(); break;
        case 22: sub_8ed9(); break;
        case 24: sub_8ed9(); break;
        case 26: sub_8ed9(); break;
        case 28: sub_8ed9(); break;
        case 30: sub_90d3(); break;
        case 32: sub_90e2(); break;
        case 34: sub_9112(); break;
        case 36: sub_8fb6(); break;
        case 38: sub_9014(); break;
        case 40: sub_901a(); break;
        case 42: sub_9028(); break;
        case 44: sub_8f68(); break;
        case 46: sub_8f7d(); break;
        case 48: sub_8f68(); break;
        case 50: sub_8ed9(); break;
        case 52: sub_8f74(); break;
        case 54: sub_8f74(); break;
        case 56: sub_8edf(); break;
        default:
        assert(0);
    }
    if (sp - oldsp != 0)
    {
        assert(sp - oldsp == 4);
        assert(pop() == 0xbcde);
        cs = pop();
        return;
    }

    si = pop();
    ds = pop();
    switch (memoryAGet16(cs, 0x49+2)*16+memoryAGet16(cs, 0x49))
    {
        case 0x43e0: sub_43e0_jump(); break;
        default:
            assert(0);
    }
}
void sub_8ed9() // 08e6:0079
{
    CStackGuard sg(0, false);
}
void sub_8eda() // 08e6:007a
{
    CStackGuardFar sg(0, false);
    goto loc_8eda;
loc_8ed5: // 08e6:0075
    stop(/*override stack*/);
    si = pop();
    si = pop();
    ds = pop();
    cs = pop();
    return;
    //   gap of 1 bytes
loc_8eda: // 08e6:007a
    sub_9295();
    goto loc_8ed5;
}
void sub_8edf() // 08e6:007f
{
    CStackGuard sg(0, false);
    push(ax);
    memoryASet16(ds, 0x005d, 0x0000);
    memoryASet16(ds, 0x005f, 0x0000);
    ah &= 0x7f;
    if (ax < cx)
        goto loc_8ef4;
    tx = cx;
    cx = ax;
    ax = tx;
loc_8ef4: // 08e6:0094
    if (bx < dx)
        goto loc_8efa;
    tx = dx;
    dx = bx;
    bx = tx;
loc_8efa: // 08e6:009a
    if ((short)ax < 0)
        goto loc_8f1f;
    if ((short)bx < 0)
        goto loc_8f1f;
    if ((short)cx < (short)0x0001)
        goto loc_8f1f;
    if ((short)dx < (short)0x0001)
        goto loc_8f1f;
    memoryASet16(ds, 0x005d, ax);
    memoryASet16(ds, 0x005f, bx);
    sub_8f2c();
    ax = pop();
    if ((char)ah >= 0)
        goto loc_8f1e;
    sub_8f20();
loc_8f1e: // 08e6:00be
    return;
loc_8f1f: // 08e6:00bf
    ax = pop();
    ax = 0;
    bx = ax;
    cx = memoryAGet16(ds, 0x0056);
    dx = memoryAGet16(ds, 0x0058);
    memoryASet16(ds, 0x0061, ax);
    memoryASet16(ds, 0x0063, bx);
    memoryASet16(ds, 0x0065, cx);
    memoryASet16(ds, 0x0067, dx);
}
void sub_8f20() // 08e6:00c0
{
    CStackGuard sg(0, false);
    ax = 0;
    bx = ax;
    cx = memoryAGet16(ds, 0x0056);
    dx = memoryAGet16(ds, 0x0058);
    memoryASet16(ds, 0x0061, ax);
    memoryASet16(ds, 0x0063, bx);
    memoryASet16(ds, 0x0065, cx);
    memoryASet16(ds, 0x0067, dx);
}
void sub_8f2c() // 08e6:00cc
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0061, ax);
    memoryASet16(ds, 0x0063, bx);
    memoryASet16(ds, 0x0065, cx);
    memoryASet16(ds, 0x0067, dx);
}
void sub_8f3c() // 08e6:00dc
{
    CStackGuard sg(0, false);
    ax += memoryAGet16(ds, 0x005d);
    bx += memoryAGet16(ds, 0x005f);
    memoryASet16(ds, 0x02ba, ax);
    memoryASet16(ds, 0x02bc, bx);
}
void sub_8f4c() // 08e6:00ec
{
    stop(/*unk call conv*/);
    goto loc_8f4c;
loc_8ed5: // 08e6:0075
    stop(/*override stack*/);
    si = pop();
    si = pop();
    ds = pop();
    stop(/*unk call conv*/);
    return;
    //   gap of 115 bytes
loc_8f4c: // 08e6:00ec
    cx = memoryAGet16(ds, 0x02ba);
    dx = memoryAGet16(ds, 0x02bc);
    sub_8f3c();
    sub_9dbc();
    if (!flags.carry)
        goto loc_8f71;
    push(cx);
    push(dx);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
    bx = pop();
    ax = pop();
    stop(/*unk call conv*/);
    return;
    //   gap of 9 bytes
loc_8f71: // 08e6:0111
    goto loc_8ed5;
}
void sub_8f68() // 08e6:0108
{
    stop(/*unk call conv*/);
    goto loc_8f68;
loc_8ed5: // 08e6:0075
    stop(/*override stack*/);
    si = pop();
    si = pop();
    ds = pop();
    stop(/*unk call conv*/);
    return;
    //   gap of 143 bytes
loc_8f68: // 08e6:0108
    sub_8f7d();
    sub_9fae();
    if (!flags.carry)
        goto loc_8f71;
    stop(/*unk call conv*/);
    return;
loc_8f71: // 08e6:0111
    goto loc_8ed5;
}
void sub_8f74() // 08e6:0114
{
    CStackGuard sg(0, false);
    cx += memoryAGet16(ds, 0x005d);
    dx += memoryAGet16(ds, 0x005f);
}
void sub_8f7d() // 08e6:011d
{
    CStackGuard sg(0, false);
    ax += memoryAGet16(ds, 0x005d);
    bx += memoryAGet16(ds, 0x005f);
}
void sub_8f86() // 08e6:0126
{
    push(0x7788);
    goto loc_8f86;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0x7788);
    si = pop();
    ds = pop();
    return;
    //   gap of 173 bytes
loc_8f86: // 08e6:0126
    sub_8f8f();
    sub_922d();
    goto loc_8ed5;
}
void sub_8f8f() // 08e6:012f
{
    CStackGuard sg(0, false);
    ax += memoryAGet16(ds, 0x005d);
    bx += memoryAGet16(ds, 0x005f);
    cx += memoryAGet16(ds, 0x005d);
    dx += memoryAGet16(ds, 0x005f);
}
void sub_8fa0() // 08e6:0140
{
    CStackGuard sg(0, false);
    goto loc_8fa0;
loc_8ed5: // 08e6:0075
    assert(0);
    si = pop(); assert(pop() == 0x7788);
    si = pop();
    ds = pop();
    return;
    //   gap of 152 bytes
loc_8f71: // 08e6:0111
    goto loc_8ed5;
    //   gap of 44 bytes
loc_8fa0: // 08e6:0140
    sub_8f8f();
    sub_9f62();
    if (!flags.carry)
        goto loc_8f71;
}
void sub_8fa9() // 08e6:0149
{
    push(0x7788);
    goto loc_8fa9;
loc_8ed5: // 08e6:0075
    si = pop(); assert(pop() == 0x7788);
    si = pop();
    ds = pop();
    return;
    //   gap of 198 bytes
loc_8f9f: // 08e6:013f
    assert(pop() == 0x7788);
    return;
    //   gap of 9 bytes
loc_8fa9: // 08e6:0149
    if (ax != 0xffff)
        goto loc_8f9f;
    push(cs);
    es = pop();
    bx = 0x02be;
    goto loc_8ed5;
}
void sub_8fb6() // 08e6:0156
{
    push(0xaacc);
    goto loc_8fb6;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0xaacc);
    si = pop();
    ds = pop();
    return;
    //   gap of 221 bytes
loc_8fb6: // 08e6:0156
    if ((char)ah >= 0)
        goto loc_8fc0;
    ah &= 0x7f;
    goto loc_a179;
loc_8fc0: // 08e6:0160
    memoryASet16(ds, 0x116a, ax);
    memoryASet16(ds, 0x116e, bx);
    memoryASet16(ds, 0x1170, cx);
    memoryASet16(ds, 0x1172, 0x0008);
    memoryASet(ds, 0x0072, 0x00);
    memoryASet16(ds, 0x1174, 0x0000);
    memoryASet16(ds, 0x1313, 0x0000);
    if (al == 0)
        goto loc_8fff;
    sub_9005();
    if (memoryAGet16(ds, 0x1313) == 0x0000)
        goto loc_8fff;
    memoryASet(ds, 0x0072, 0xff);
    memoryASet16(ds, 0x1174, 0xffff);
    memoryASet16(ds, 0x1172, bx);
loc_8fff: // 08e6:019f
    sub_a01d();
    goto loc_8ed5;
    //   gap of 4468 bytes
loc_a179: // 08e6:1319
    memoryASet16(ds, 0x12f5, ax);
    memoryASet16(ds, 0x12f7, bx);
    memoryASet16(ds, 0x12f9, cx);
    memoryASet16(ds, 0x12fb, dx);
    assert(pop() == 0xaacc);
}
void sub_9005() // 08e6:01a5
{
    CStackGuard sg(0, false);
    es = dx;
    si = 0;
    if (memoryAGet(es, si) != 0x2b)
        return;
    memoryASet16(ds, 0x1313, dx);
}
void sub_9014() // 08e6:01b4
{
    push(0xddbb);
    goto loc_9014;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0xddbb);
    si = pop();
    ds = pop();
    return;
    //   gap of 315 bytes
loc_9014: // 08e6:01b4
    sub_9fd7();
    goto loc_8ed5;
}
void sub_901a() // 08e6:01ba
{
    stop(/*unk call conv*/);
    goto loc_901a;
loc_8ed5: // 08e6:0075
    stop(/*override stack*/);
    si = pop();
    si = pop();
    ds = pop();
    stop(/*unk call conv*/);
    return;
    //   gap of 321 bytes
loc_901a: // 08e6:01ba
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_9027;
    sub_a225();
    goto loc_8ed5;
loc_9027: // 08e6:01c7
    stop(/*unk call conv*/);
}
void sub_9028() // 08e6:01c8
{
    push(0xaaee);
    goto loc_9028;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0xaaee);
    si = pop();
    ds = pop();
//    cs = pop();
    return;
    //   gap of 335 bytes
loc_9028: // 08e6:01c8
    memoryASet(ds, 0x116c, ah);
    memoryASet(ds, 0x116d, al);
    goto loc_8ed5;
}
void sub_9032() // 08e6:01d2
{
    push(0xaabb);
    goto loc_9032;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0xaabb);
    si = pop();
    ds = pop();
    return;
    //   gap of 345 bytes
loc_9032: // 08e6:01d2
    if (al == 0)
        goto loc_9037;
    stop(/*unk call conv*/);
    return;
loc_9037: // 08e6:01d7
    memoryASet16(ds, 0x0049, bx);
    memoryASet16(ds, 0x004b, es);
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
    memoryASet16(ds, 0x004d, bx);
    memoryASet16(ds, 0x004f, es);
    push(es);
    push(bx);
    di = memoryAGet16(ds, 0x0049);
    es = memoryAGet16(ds, 0x0049 + 2);
    di += 0x0010;
    al = 0x9a;
    flags.direction = false;
    stosb<MemAuto, DirAuto>();
    ax = 0x02fc;
    stosw<MemAuto, DirAuto>();
    ax = cs;
    stosw<MemAuto, DirAuto>();
    si = memoryAGet16(cs, 0x004d);
    es = memoryAGet16(cs, 0x004d + 2);
    si += 0x0002;
    ax = memoryAGet16(es, si);
    memoryASet16(ds, 0x0056, ax);
    si = memoryAGet16(cs, 0x004d);
    es = memoryAGet16(cs, 0x004d + 2);
    si += 0x0004;
    ax = memoryAGet16(es, si);
    memoryASet16(ds, 0x0058, ax);
    bx = pop();
    es = pop();
    goto loc_8ed5;
}
void sub_9082() // 08e6:0222
{
    push(0xaacc);
    goto loc_9082;
loc_8ed5: // 08e6:0075
    si = pop(); assert(si == 0xaacc);
    si = pop();
    ds = pop();
//    cs = pop();
    return;
    //   gap of 425 bytes
loc_9082: // 08e6:0222
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = memoryAGet16(es, bx + 12);
    ax++;
    ax++;
    memoryASet16(ds, 0x042b, ax);
    ax = memoryAGet16(es, bx + 14);
    memoryASet16(ds, 0x042d, ax);
    ax = memoryAGet16(es, bx + 16);
    memoryASet16(ds, 0x0220, ax);
    dx = 0;
    cx = 0x0006;
    div(cx);
    memoryASet16(ds, 0x0427, ax);
    tx = bx;
    bx = memoryAGet16(es, tx + 18);
    es = memoryAGet16(es, tx + 18 + 2);
    memoryASet16(ds, 0x0051, bx);
    memoryASet16(ds, 0x0053, es);
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
    memoryASet(ds, 0x0072, 0x00);
    sub_9fea();
    goto loc_8ed5;
}
void sub_90c8() // 08e6:0268
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0073, ax);
    si = 0x001e;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
}
void sub_90d3() // 08e6:0273
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x0073, ax);
}
void sub_90e2() // 08e6:0282
{
    CStackGuard sg(0, false);
    if (al != 0xff)
        goto loc_90ed;
    memoryASet16(ds, 0x0069, 0x0c0c);
    return;
loc_90ed: // 08e6:028d
    memoryASet16(ds, 0x0069, ax);
}
void sub_90f6() // 08e6:0296
{
    CStackGuard sg(0, false);
    cx = 0x0001;
    goto loc_9100;
    //   gap of 5 bytes
loc_9100: // 08e6:02a0
    memoryASet(ds, 0x0291, al);
    memoryASet(ds, 0x0292, cl);
    cx = 0x0001;
    si = 0x0022;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
}
void sub_9112() // 08e6:02b2
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x0291, al);
    memoryASet(ds, 0x0292, cl);
}
void sub_922d() // 08e6:03cd
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x0292) >= 0x03)
        goto loc_9241;
    sub_9dbc();
    if (!flags.carry)
        goto loc_9240;
    si = 0x000c;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
loc_9240: // 08e6:03e0
    return;
loc_9241: // 08e6:03e1
    sub_9278();
    di = ax;
    di -= cx;
    if ((short)di >= 0)
        goto loc_924c;
    di = -di;
loc_924c: // 08e6:03ec
    si = bx;
    si -= dx;
    if ((short)si >= 0)
        goto loc_9254;
    si = -si;
loc_9254: // 08e6:03f4
    tx = di;
    di = memoryAGet16(ds, 0x097d);
    if (stop("check inject: cmp di, si") && tx >= si)
        goto loc_926b;
    ax -= di;
    cx -= di;
    sub_9278();
    di <<= 1;
    ax += di;
    cx += di;
    goto loc_9278;
loc_926b: // 08e6:040b
    bx -= di;
    dx -= di;
    sub_9278();
    di <<= 1;
    bx += di;
    dx += di;
loc_9278: // 08e6:0418
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    sub_9234();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_9234() // 08e6:03d4
{
    CStackGuard sg(0, false);
    sub_9dbc();
    if (!flags.carry)
        return;
    si = 0x000c;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
}
void sub_9278() // 08e6:0418
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    sub_9234();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_9295() // 08e6:0435
{
    if (al < 0x08)
        goto loc_929b;
    al = 0x05;
loc_929b: // 08e6:043b
    ah = 0;
    al <<= 1;
    di = ax;
    callIndirect(cs, memoryAGet16(ds, di + 1093)); // 08e6:0441
}
// INJECT: Error: cannot inject carry flag in sub_9dbc()!
void sub_9dbc() // 08e6:0f5c
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x005c, 0x01);
    sub_9fae();
    if (!flags.carry)
        goto loc_9dd2;
    tx = cx;
    cx = ax;
    ax = tx;
    tx = dx;
    dx = bx;
    bx = tx;
    sub_9fae();
    tx = cx;
    cx = ax;
    ax = tx;
    tx = dx;
    dx = bx;
    bx = tx;
    if (!flags.carry)
        goto loc_9dd2;
    return;
loc_9dd2: // 08e6:0f72
    memoryASet16(ds, 0x0f54, ax);
    memoryASet16(ds, 0x0f56, bx);
    memoryASet16(ds, 0x0f58, cx);
    memoryASet16(ds, 0x0f5a, dx);
    sub_9e07();
    if (memoryAGet(ds, 0x005c) == 0x00)
        goto loc_9dfc;
    ax = memoryAGet16(ds, 0x0f54);
    bx = memoryAGet16(ds, 0x0f56);
    cx = memoryAGet16(ds, 0x0f58);
    dx = memoryAGet16(ds, 0x0f5a);
    flags.carry = true;
    return;
loc_9dfc: // 08e6:0f9c
    ax = 0xffff;
    bx = ax;
    cx = ax;
    dx = ax;
    flags.carry = false;
}
void sub_9e07() // 08e6:0fa7
{
    CStackGuard sg(0, false);
    bx = 0x0f54;
    sub_9eff();
    ch = al;
    bx = 0x0f58;
    sub_9eff();
    al |= ch;
    if (al)
        goto loc_9e1a;
    return;
loc_9e1a: // 08e6:0fba
    ax = memoryAGet16(ds, 0x0f58);
    ax -= memoryAGet16(ds, 0x0f54);
    memoryASet16(ds, 0x0f50, ax);
    if (ax == 0)
        goto loc_9e30;
    ax = memoryAGet16(ds, 0x0f5a);
    ax -= memoryAGet16(ds, 0x0f56);
    memoryASet16(ds, 0x0f52, ax);
loc_9e30: // 08e6:0fd0
    bx = 0x0f54;
    sub_9eff();
    ch = al;
    bx = 0x0f58;
    sub_9eff();
    dl = al;
    al |= ch;
    if (al)
        goto loc_9e45;
    return;
loc_9e45: // 08e6:0fe5
    dl &= ch;
    if (dl == 0)
        goto loc_9e4f;
    memoryASet(ds, 0x005c, 0x00);
    return;
loc_9e4f: // 08e6:0fef
    if (ch != 0)
        goto loc_9e56;
    sub_9f2b();
loc_9e56: // 08e6:0ff6
    memoryASet(ds, 0x005c, 0x02);
    if (memoryAGet16(ds, 0x0f50) != 0x0000)
        goto loc_9e80;
    ax = memoryAGet16(ds, 0x0f56);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0063))
        goto loc_9e71;
    ax = memoryAGet16(ds, 0x0063);
    memoryASet16(ds, 0x0f56, ax);
loc_9e71: // 08e6:1011
    ax = memoryAGet16(ds, 0x0067);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0f56))
        goto loc_9e7d;
    memoryASet16(ds, 0x0f56, ax);
loc_9e7d: // 08e6:101d
    goto loc_9ef5;
loc_9e80: // 08e6:1020
    if (memoryAGet16(ds, 0x0f52) != 0x0000)
        goto loc_9ea5;
    ax = memoryAGet16(ds, 0x0f54);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0061))
        goto loc_9e96;
    ax = memoryAGet16(ds, 0x0061);
    memoryASet16(ds, 0x0f54, ax);
loc_9e96: // 08e6:1036
    ax = memoryAGet16(ds, 0x0065);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0f54))
        goto loc_9ea2;
    memoryASet16(ds, 0x0f54, ax);
loc_9ea2: // 08e6:1042
    goto loc_9ef5;
loc_9ea5: // 08e6:1045
    ax = memoryAGet16(ds, 0x0f54);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0061))
        goto loc_9ebb;
    ax = memoryAGet16(ds, 0x0061);
    push(ax);
    sub_9f51();
    memoryASet16(ds, 0x0f54, pop());
    goto loc_9ef5;
loc_9ebb: // 08e6:105b
    ax = memoryAGet16(ds, 0x0065);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0f54))
        goto loc_9ece;
    push(ax);
    sub_9f51();
    memoryASet16(ds, 0x0f54, pop());
    goto loc_9ef5;
loc_9ece: // 08e6:106e
    ax = memoryAGet16(ds, 0x0f56);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0063))
        goto loc_9ee4;
    ax = memoryAGet16(ds, 0x0063);
    push(ax);
    sub_9f40();
    memoryASet16(ds, 0x0f56, pop());
    goto loc_9ef5;
loc_9ee4: // 08e6:1084
    ax = memoryAGet16(ds, 0x0067);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0f56))
        goto loc_9ef5;
    push(ax);
    sub_9f40();
    memoryASet16(ds, 0x0f56, pop());
loc_9ef5: // 08e6:1095
    if (ch != 0)
        goto loc_9efc;
    sub_9f2b();
loc_9efc: // 08e6:109c
    goto loc_9e30;
}
void sub_9eff() // 08e6:109f
{
    CStackGuard sg(0, false);
    dl = 0;
    ax = memoryAGet16(ds, bx);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0061))
        goto loc_9f0b;
    dl = 0x01;
loc_9f0b: // 08e6:10ab
    if ((short)ax <= (short)memoryAGet16(ds, 0x0065))
        goto loc_9f13;
    dl = 0x02;
loc_9f13: // 08e6:10b3
    ax = memoryAGet16(ds, bx + 2);
    if ((short)ax >= (short)memoryAGet16(ds, 0x0063))
        goto loc_9f1f;
    dl += 0x04;
loc_9f1f: // 08e6:10bf
    if ((short)ax <= (short)memoryAGet16(ds, 0x0067))
        goto loc_9f28;
    dl += 0x08;
loc_9f28: // 08e6:10c8
    al = dl;
}
void sub_9f2b() // 08e6:10cb
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x0f54);
    tx = memoryAGet16(ds, 0x0f58);
    memoryASet16(ds, 0x0f58, ax);
    ax = tx;
    memoryASet16(ds, 0x0f54, ax);
    ax = memoryAGet16(ds, 0x0f56);
    tx = memoryAGet16(ds, 0x0f5a);
    memoryASet16(ds, 0x0f5a, ax);
    ax = tx;
    memoryASet16(ds, 0x0f56, ax);
}
void sub_9f40() // 08e6:10e0
{
    CStackGuard sg(0, false);
    ax -= memoryAGet16(ds, 0x0f56);
    imul(memoryAGet16(ds, 0x0f50));
    idiv(memoryAGet16(ds, 0x0f52));
    memoryASet16(ds, 0x0f54, memoryAGet16(ds, 0x0f54) + ax);
}
void sub_9f51() // 08e6:10f1
{
    CStackGuard sg(0, false);
    ax -= memoryAGet16(ds, 0x0f54);
    imul(memoryAGet16(ds, 0x0f52));
    idiv(memoryAGet16(ds, 0x0f50));
    memoryASet16(ds, 0x0f56, memoryAGet16(ds, 0x0f56) + ax);
}
// INJECT: Error: cannot inject flag in sub_9f62() because of being label!
void sub_9f62() // 08e6:1102
{
    CStackGuard sg(0, false);
    sub_9fae();
    if (flags.carry)
        goto loc_9f7c;
    tx = dx;
    dx = bx;
    bx = tx;
    sub_9fae();
    if (flags.carry)
        goto loc_9f7c;
    tx = cx;
    cx = ax;
    ax = tx;
    sub_9fae();
    if (flags.carry)
        goto loc_9f7c;
    tx = dx;
    dx = bx;
    bx = tx;
    sub_9fae();
    tx = cx;
    cx = ax;
    ax = tx;
    if (stop(/*1 - jae loc_9f9f*/))
        goto loc_9f9f;
loc_9f7c: // 08e6:111c
    di = memoryAGet16(ds, 0x0061);
    si = memoryAGet16(ds, 0x0065);
    sub_9fa0();
    tx = cx;
    cx = ax;
    ax = tx;
    sub_9fa0();
    tx = cx;
    cx = ax;
    ax = tx;
    di = memoryAGet16(ds, 0x0063);
    si = memoryAGet16(ds, 0x0067);
    tx = bx;
    bx = ax;
    ax = tx;
    sub_9fa0();
    tx = bx;
    bx = ax;
    ax = tx;
    tx = dx;
    dx = ax;
    ax = tx;
    sub_9fa0();
    tx = dx;
    dx = ax;
    ax = tx;
    flags.carry = true;
loc_9f9f: // 08e6:113f
    return;
}
void sub_9fa0() // 08e6:1140
{
    CStackGuard sg(0, false);
    if ((short)ax >= (short)di)
        goto loc_9fa7;
    ax = di;
    return;
loc_9fa7: // 08e6:1147
    if (ax <= si)
        return;
    ax = si;
}
void sub_9fae() // 08e6:114e
{
    CStackGuard sg(0, false);
    if (ax > memoryAGet16(ds, 0x0065))
        goto loc_9fc8;
    if (bx > memoryAGet16(ds, 0x0067))
        goto loc_9fc8;
    if ((short)ax < (short)memoryAGet16(ds, 0x0061))
        goto loc_9fc8;
    if ((short)bx < (short)memoryAGet16(ds, 0x0063))
        goto loc_9fc8;
    flags.carry = true;
    return;
loc_9fc8: // 08e6:1168
    flags.carry = false;
}
void sub_9fd7() // 08e6:1177
{
    CStackGuard sg(0, false);
    ch = 0;
    if (cx == 0)
        return;
    push(bx);
    push(es);
    memoryASet(ds, 0x1176, cl);
    sub_a09a();
    es = pop();
    bx = pop();
    sub_a0cc();
}
void sub_9fea() // 08e6:118a
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a005;
    al = 0;
    ah = 0;
    if (al != 0)
        goto loc_9ffb;
    al = 0x04;
loc_9ffb: // 08e6:119b
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a005;
    memoryASet16(ds, 0x1172, ax);
loc_a005: // 08e6:11a5
    memoryASet(ds, 0x116c, 0x00);
    memoryASet(ds, 0x116d, 0x02);
    ax = 0;
    memoryASet16(ds, 0x116a, ax);
    ax = memoryAGet16(ds, 0x1172);
    memoryASet16(ds, 0x116e, ax);
    memoryASet16(ds, 0x1170, ax);
    bx = memoryAGet16(ds, 0x116e);
    cx = memoryAGet16(ds, 0x1170);
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a02f;
    sub_a081();
loc_a02f: // 08e6:11cf
    ax = memoryAGet16(ds, 0x116a);
    dx = memoryAGet16(ds, 0x116c);
    if (memoryAGet(ds, 0x0055) != 0x00)
        goto loc_a049;
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a049;
    sub_a189();
    goto loc_a059;
loc_a049: // 08e6:11e9
    if (bx)
        goto loc_a052;
    bx = 0x0008;
    cx = bx;
loc_a052: // 08e6:11f2
    si = 0x0024;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
loc_a059: // 08e6:11f9
    memoryASet16(ds, 0x116e, bx);
    memoryASet16(ds, 0x1170, cx);
}
void sub_a01d() // 08e6:11bd
{
    CStackGuard sg(0, false);
    bx = memoryAGet16(ds, 0x116e);
    cx = memoryAGet16(ds, 0x1170);
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a02f;
    sub_a081();
loc_a02f: // 08e6:11cf
    ax = memoryAGet16(ds, 0x116a);
    dx = memoryAGet16(ds, 0x116c);
    if (memoryAGet(ds, 0x0055) != 0x00)
        goto loc_a049;
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a049;
    sub_a189();
    goto loc_a059;
loc_a049: // 08e6:11e9
    if (bx)
        goto loc_a052;
    bx = 0x0008;
    cx = bx;
loc_a052: // 08e6:11f2
    si = 0x0024;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
loc_a059: // 08e6:11f9
    memoryASet16(ds, 0x116e, bx);
    memoryASet16(ds, 0x1170, cx);
}
void sub_a081() // 08e6:1221
{
    CStackGuard sg(0, false);
    bx = memoryAGet16(ds, 0x1172);
    if (bx < 0x000a)
        goto loc_a08d;
    bx = 0x000a;
loc_a08d: // 08e6:122d
    bl <<= 1;
    bx = memoryAGet16(ds, bx + 4610);
    cl = bh;
    ch = 0;
    bh = 0;
}
void sub_a09a() // 08e6:123a
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x02ba);
    bx = memoryAGet16(ds, 0x02bc);
    push(bx);
    bx = ax;
    if (memoryAGet(ds, 0x1174) != 0x00)
        goto loc_a0ae;
    sub_a0fd();
loc_a0ae: // 08e6:124e
    ax = pop();
    push(bx);
    bx = ax;
    if (memoryAGet(ds, 0x1175) != 0x00)
        goto loc_a0bc;
    sub_a123();
loc_a0bc: // 08e6:125c
    ax = pop();
    memoryASet16(ds, 0x02ba, ax);
    memoryASet16(ds, 0x02bc, bx);
    si = 0x0008;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
}
void sub_a0cc() // 08e6:126c
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x1174) != 0x00)
        goto loc_a0db;
    ax = memoryAGet16(ds, 0x02ba);
    if ((short)ax >= 0)
        goto loc_a0db;
    return;
loc_a0db: // 08e6:127b
    cl = memoryAGet(ds, 0x1176);
    ch = 0;
    ax = memoryAGet16(ds, 0x116c);
    if (memoryAGet(ds, 0x0055) != 0x00)
        goto loc_a0f5;
    if (memoryAGet(ds, 0x0072) == 0x00)
        goto loc_a0f5;
    goto loc_a46c;
loc_a0f5: // 08e6:1295
    si = 0x0026;
    push(cs);
    cs = memoryAGet16(ds, 0x0049 + 2);
    callIndirect(memoryAGet16(ds, 0x0049 + 2), memoryAGet16(ds, 0x0049));
    assert(cs == 0x08e6);
    return;
    //   gap of 879 bytes
loc_a46c: // 08e6:160c
    if (memoryAGet(ds, 0x12eb) == 0xff)
        return;
    if (cx == 0)
        return;
    push(memoryAGet16(ds, 0x0291));
    memoryASet16(ds, 0x160a, ax);
    push(es);
    push(bx);
    sub_a4b8();
    push(cx);
    al = 0;
    cx = 0x0001;
    sub_90f6();
    if (memoryAGet(ds, 0x1304) == 0x00)
        goto loc_a499;
    ax = memoryAGet16(ds, 0x0073);
    tl = ah;
    ah = al;
    al = tl;
    sub_90c8();
loc_a499: // 08e6:1639
    cx = pop();
    bx = pop();
    es = pop();
loc_a49c: // 08e6:163c
    al = memoryAGet(es, bx);
    al &= 0x7f;
    if (al == 0)
        goto loc_a4af;
    push(es);
    push(bx);
    push(cx);
    sub_a273();
    cx = pop();
    bx = pop();
    es = pop();
    bx++;
    if (--cx)
        goto loc_a49c;
loc_a4af: // 08e6:164f
    ax = pop();
    cl = ah;
    ch = 0;
    sub_90f6();
}
void sub_a0fd() // 08e6:129d
{
    CStackGuard sg(0, false);
    al = 0x01;
    if (memoryAGet(ds, 0x116b) == 0x01)
        goto loc_a110;
    if (memoryAGet(ds, 0x116c) == 0x00)
        return;
    al = memoryAGet(ds, 0x1176);
loc_a110: // 08e6:12b0
    ah = 0;
    mul(memoryAGet16(ds, 0x116e));
    if (memoryAGet(ds, 0x116c) != 0x01)
        goto loc_a120;
    ax >>= 1;
    ax--;
loc_a120: // 08e6:12c0
    bx -= ax;
}
void sub_a123() // 08e6:12c3
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x116b) != 0x01)
        goto loc_a135;
    al = memoryAGet(ds, 0x1176);
    ah = 0;
    mul(memoryAGet16(ds, 0x1170));
    goto loc_a138;
loc_a135: // 08e6:12d5
    ax = memoryAGet16(ds, 0x1170);
loc_a138: // 08e6:12d8
    if (memoryAGet(ds, 0x116d) == 0x02)
        return;
    if (memoryAGet(ds, 0x116d) != 0x01)
        goto loc_a148;
    ax >>= 1;
loc_a148: // 08e6:12e8
    bx -= ax;
}
void sub_a189() // 08e6:1329
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x0055) == 0x03)
        goto loc_a1ab;
    memoryASet(ds, 0x12ec, ah);
    if (al == memoryAGet(ds, 0x12eb))
        goto loc_a1ac;
    memoryASet(ds, 0x12eb, al);
    push(bx);
    push(cx);
    sub_a42f();
    cx = pop();
    bx = pop();
    if (flags.carry)
        goto loc_a1ac;
    memoryASet(ds, 0x12eb, 0xff);
loc_a1ab: // 08e6:134b
    return;
loc_a1ac: // 08e6:134c
    if (bx != 0)
        goto loc_a1d4;
    ax = memoryAGet16(ds, 0x12f5);
    memoryASet16(ds, 0x12ed, ax);
    ax = memoryAGet16(ds, 0x12f9);
    memoryASet16(ds, 0x12f1, ax);
    ax = memoryAGet16(ds, 0x12f7);
    if (ax != 0)
        goto loc_a1c4;
    ax++;
loc_a1c4: // 08e6:1364
    memoryASet16(ds, 0x12ef, ax);
    ax = memoryAGet16(ds, 0x12fb);
    if (ax != 0)
        goto loc_a1cf;
    ax++;
loc_a1cf: // 08e6:136f
    memoryASet16(ds, 0x12f3, ax);
    goto loc_a205;
loc_a1d4: // 08e6:1374
    memoryASet16(ds, 0x12ed, bx);
    memoryASet16(ds, 0x12f1, bx);
    memoryASet16(ds, 0x12ef, cx);
    memoryASet16(ds, 0x12f3, cx);
    if (memoryAGet(ds, 0x12ec) != 0x00)
        goto loc_a205;
    bx = memoryAGet16(ds, 0x005a);
    cx = 0x2710;
    if (bx >= cx)
        goto loc_a205;
    mul(cx);
    div(bx);
    bx = ax;
    if (bx != 0)
        goto loc_a201;
    bx++;
loc_a201: // 08e6:13a1
    memoryASet16(ds, 0x12ed, bx);
loc_a205: // 08e6:13a5
    sub_a210();
    bx = memoryAGet16(ds, 0x1315);
    cx = bx;
    flags.carry = true;
}
void sub_a210() // 08e6:13b0
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x1305);
    al -= memoryAGet(ds, 0x1307);
    ah = 0;
    mul(memoryAGet16(ds, 0x12f1));
    div(memory16(ds, 0x12f3));
    memoryASet16(ds, 0x1315, ax);
}
void sub_a225() // 08e6:13c5
{
    CStackGuard sg(0, false);
    sub_a231();
    bx = memoryAGet16(ds, 0x1317);
    cx = memoryAGet16(ds, 0x1315);
}
void sub_a231() // 08e6:13d1
{
    CStackGuard sg(0, false);
    push(bx);
    push(cx);
    sub_a210();
    memoryASet16(ds, 0x1317, 0x0000);
    ax = memoryAGet16(ds, 0x12fe);
    ax <<= 1;
    ax += 0x0010;
    di = memoryAGet16(ds, 0x1311);
    ds = memoryAGet16(ds, 0x1311 + 2);
    di += ax;
loc_a24a: // 08e6:13ea
    al = memoryAGet(es, bx);
    bx++;
    al -= memoryAGet(cs, 0x1301);
    ah = 0;
    si = di;
    si += ax;
    lodsb<MemAuto, DirAuto>();
    mul(memoryAGet16(cs, 0x12ed));
    div(memory16(cs, 0x12ef));
    memoryASet16(cs, 0x1317, memoryAGet16(cs, 0x1317) + ax);
    if (--cx)
        goto loc_a24a;
    push(cs);
    ds = pop();
    ax = memoryAGet16(ds, 0x1317);
    cx = pop();
    bx = pop();
}
void sub_a273() // 08e6:1413
{
    memoryASet16(ds, 0x130d, 0x0000);
    memoryASet16(ds, 0x130f, 0x0000);
    al -= memoryAGet(ds, 0x1301);
    al <<= 1;
    ah = 0;
    di = memoryAGet16(ds, 0x1311);
    es = memoryAGet16(ds, 0x1311 + 2);
    bx = di;
    bx += 0x0010;
    bx += ax;
    di += memoryAGet16(es, bx);
    di += memoryAGet16(ds, 0x1302);
    if (memoryAGet(ds, 0x1304) == 0x00)
        goto loc_a2a5;
    goto loc_a319;
    //   gap of 3 bytes
loc_a2a5: // 08e6:1445
    sub_a301();
    push(es);
    push(di);
    al <<= 1;
    ah = 0;
    di = ax;
    callIndirect(cs, memoryAGet16(ds, di + 5204)); // 08e6:1450
    return;
    //   gap of 101 bytes
loc_a319: // 08e6:14b9
    push(es);
    push(di);
    ax = 0;
    sub_9295();
    di = pop();
    es = pop();
loc_a322: // 08e6:14c2
    sub_a301();
    push(es);
    push(di);
    al <<= 1;
    ah = 0;
    di = ax;
    callIndirect(cs, memoryAGet16(ds, di + 5333)); // 08e6:14cd
    di = pop();
    es = pop();
    goto loc_a322;
}
void sub_a301() // 08e6:14a1
{
    CStackGuard sg(0, false);
    cx = memoryAGet16(es, di);
    tl = cl;
    cl = ch;
    ch = tl;
    di++;
    di++;
    al = 0;
    if (!(ch & 0x80))
        goto loc_a311;
    al += 0x02;
loc_a311: // 08e6:14b1
    if (!(cl & 0x80))
        return;
    al++;
}
// INJECT: Error: cannot inject carry flag in sub_a42f()!
void sub_a42f() // 08e6:15cf
{
    CStackGuard sg(0, false);
    sub_a465();
    if (ax != 0)
        goto loc_a43c;
    memoryASet(ds, 0x12eb, 0xff);
    stop(/*inject ret*/);
    return;
loc_a43c: // 08e6:15dc
    memoryASet16(ds, 0x1311, 0x0000);
    sub_a446();
}
// INJECT: Error: cannot inject flag in sub_a446() because of being label!
void sub_a446() // 08e6:15e6
{
    CStackGuard sg(0, false);
    si = memoryAGet16(ds, 0x1311);
    ds = memoryAGet16(ds, 0x1311 + 2);
    cx = 0x0010;
    di = 0x12fd;
    push(cs);
    es = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(cs);
    ds = pop();
    memoryASet(ds, 0x1304, 0x00);
    flags.carry = true;
    if (stop(/*70*/))
        goto loc_a464;
    flags.carry = !flags.carry;
loc_a464: // 08e6:1604
    stop(/*inject ret*/);
}
void sub_a465() // 08e6:1605
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x1313);
}
void sub_a4b8() // 08e6:1658
{
    CStackGuard sg(0, false);
    push(cx);
    sub_a231();
    sub_a4c4();
    sub_a4f3();
    cx = pop();
}
void sub_a4c4() // 08e6:1664
{
    CStackGuard sg(0, false);
    if (memoryAGet(ds, 0x160a) == 0x00)
        return;
    ax = memoryAGet16(ds, 0x1315);
    if (memoryAGet(ds, 0x12ec) != 0x00)
        goto loc_a4d8;
    ax = memoryAGet16(ds, 0x1317);
loc_a4d8: // 08e6:1678
    if (memoryAGet(ds, 0x160a) != 0x01)
        goto loc_a4e2;
    ax >>= 1;
    ax--;
loc_a4e2: // 08e6:1682
    if (memoryAGet(ds, 0x006b) == 0x00)
        goto loc_a4ee;
    memoryASet16(ds, 0x02bc, memoryAGet16(ds, 0x02bc) + ax);
    return;
loc_a4ee: // 08e6:168e
    memoryASet16(ds, 0x02ba, memoryAGet16(ds, 0x02ba) - ax);
}
void sub_a4f3() // 08e6:1693
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x1317);
    if (memoryAGet(ds, 0x12ec) != 0x00)
        goto loc_a500;
    ax = memoryAGet16(ds, 0x1315);
loc_a500: // 08e6:16a0
    if (memoryAGet(ds, 0x160b) == 0x00)
        return;
    if (memoryAGet(ds, 0x160b) != 0x01)
        goto loc_a510;
    ax >>= 1;
loc_a510: // 08e6:16b0
    if (memoryAGet(ds, 0x006b) == 0x00)
        goto loc_a51c;
    memoryASet16(ds, 0x02ba, memoryAGet16(ds, 0x02ba) + ax);
    return;
loc_a51c: // 08e6:16bc
    memoryASet16(ds, 0x02bc, memoryAGet16(ds, 0x02bc) + ax);
}
