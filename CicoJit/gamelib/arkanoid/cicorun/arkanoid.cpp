#include <stdio.h>
#include "cicoemu.h"
using namespace CicoContext;

void sub_1b0c0(bool resume);

void start()
{
    headerSize = 0x00c0;
    loadAddress = 0x10df;
    cs = 0x1b0c;
    ds = 0x1afc;
    es = 0x1afc;
    ss = 0x10df;
    sp = 0x0190;
    overlay("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/arkanoid/dos", "REVOFDOH.DAT", 86544, 0x1b0c, -0xa390+headerSize*0);
    overlay("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/arkanoid/dos", "MEMDUMP.BIN", 16384, 0x4dd, 0x0000);
   sub_1b0c0(false);
}
void sub_1a1d7();
void sub_1a2f8();
void sub_1a330();
void sub_1a83d();
void sub_1a861();
void sub_1a8e9();
void sub_1a905();
void sub_1aa1a();
void sub_1aa2a();
void sub_1aa3a();
void sub_1aa52();
void sub_1aa64();
void sub_1aac4();
void sub_1ab72();
void sub_1b060();
void sub_1b06b();
void sub_1b07f();
void sub_1b08e();
void sub_1b0b1();
void sub_1b0b6();
void sub_1b0c0(bool resume);
void sub_1b130();
void sub_1b14b();
void sub_1b14f();
void sub_1b159();
void sub_1b160();
void sub_1b1aa();
void sub_1b1c3();
void sub_1b1c6();
void sub_1b1d9();
void sub_1b206();
void sub_1b22b();
void sub_1b23c();
void sub_1b29e();
void sub_1b2b8();
void sub_1b2e6();
void sub_1b308();
void sub_1b382();
void sub_1b3dd();
void sub_1b3f3();
void sub_1b41a();
void sub_1b426();
void sub_1b439();
void sub_1b43e();
void sub_1b45a();
void sub_1b488();
void sub_1b4ac();
void sub_1b4f0();
void sub_1b53a();
void sub_1b562();
void sub_1b59a();
void sub_1b5d0();
void sub_1b764();
void sub_1b970();
void sub_1b978();
void sub_1b994();
void sub_1ba4f();
void sub_1baf1();
void sub_1bb0f();
void sub_1bb5e();
void sub_1bb74();
void sub_1bb85();
void sub_1bbe6();
void sub_1bc14();
void sub_1bc60();
void sub_1bce1();
void sub_1bcf0();
void sub_1bd07();
void sub_1bd95();
void sub_1bdcc();
void sub_1bde4();
void sub_1be22();
void sub_1be3b();
void sub_1be47();
void sub_1be6d();
void sub_1be93();
void sub_1beac();
void sub_1bf26();
void sub_1bf3a();
void sub_1bf80();
void sub_1bf9f();
void sub_1bfad();
void sub_1bfe4();
void sub_1c008();
void sub_1c02d();
void sub_1c045();
void sub_1c064();
void sub_1c0a5();
void sub_1c0f7();
void sub_1c178();
void sub_1c1ac();
void sub_1c1f5();
void sub_1c227();
void sub_1c363();
void sub_1c38c();
void sub_1c3a8();
void sub_1c3fa();
void sub_1c413();
void sub_1c46f();
void sub_1c510();
void sub_1c534();
void sub_1c564();
void sub_1c57c();
void sub_1c592();
void sub_1c601();
void sub_1c750();
void sub_1c78d();
void sub_1c7fc();
void sub_1c831();
void sub_1c843();
void sub_1c849();
void sub_1c84f();
void sub_1c855();
void sub_1c85b();
void sub_1c861();
void sub_1c8de();
void sub_1c8f8();
void sub_1c912();
void sub_1c91e();
void sub_1c939();
void sub_1c957();
void sub_1c97a();
void sub_1c9b6();
void sub_1c9c5();
void sub_1ca4a();
void sub_1ca4d();
void sub_1ca54();
void sub_1ca5b();
void sub_1ca6f();
void sub_1ca85();
void sub_1caa4();
void sub_1cac7();
void sub_1cb1d();
void sub_1cb22();
void sub_1cb54();
void sub_1cb83();
void sub_1cb8f();
void sub_1cbd3();
void sub_1cc31();
void sub_1cc53();
void sub_1cc95();
void sub_1ccb5();
void sub_1ccd8();
void sub_1ccdc();
void sub_1ccfc();
void sub_1cd4c();
void sub_1cdd3();
void sub_1cdef();
void sub_1cdfa();
void sub_1ce35();
void sub_1ce96();
void sub_1cebd();
void sub_1cee6();
void sub_1cf47();
void sub_1cf4d();
void sub_1d042();
void sub_1d04b();
void sub_1d05e();
void sub_1d105();
void sub_1d158();
void sub_1d15f();
void sub_1d1ae();
void sub_1d228();
void sub_1d23b();
void sub_1d250();
void sub_1d28e();
void sub_1d2c8();
void sub_1d2e9();
void sub_1d330();
void sub_1d35e();
void sub_1d37e();
void sub_1d3a1();
void sub_1d3f0();
void sub_1d454();
void sub_1d484();
void sub_1d498();
void sub_1d5a8();
void sub_1d5c7();
void sub_1d5fa();
void sub_1d63f();
void sub_1d67f();
void sub_1d697();
void sub_1d6ad();
void sub_1d6be();
void sub_1d6c5();
void sub_1d6c9();
void sub_1d6cd();
void sub_1d6d1();
void sub_1d6d5();
void sub_1d6db();
void sub_1d6f2();
void sub_1d6f6();
void sub_1d706();
void sub_1d7c8();
void sub_1d7e7();
void sub_1d83e();
void sub_1d877();
void sub_1d88a();
void sub_1d8a1();
void sub_1d8e6();
void sub_1d8ec();
void sub_1d8f2();
void sub_1d918();
void sub_1d931();
void sub_1d94d();
void sub_1d97d();
void sub_1d9f8();
void sub_1da1b();
void sub_1da36();
void sub_1da58();
void sub_1da68();
void sub_1da6f();
void sub_1da8d();
void sub_1dacd();
void sub_1db0d();
void sub_1db56();
void sub_1dbe2();
void sub_1dbef();
void sub_1dc1a();
void sub_1dc26();
void sub_1dc70();
void sub_1dca8();
void sub_1dcc5();
void sub_1dcd4();
void sub_1dcda();
void sub_1dcfe();
void sub_1dd10();
void sub_1dd5e();
void sub_1dd99();
void sub_1dda7();
void sub_1ddb5();
void sub_1ddec();
void sub_1de31();
void sub_1de68();
void sub_1dea0();
void sub_1ded8();
void sub_1df25();
void sub_1df2b();
void sub_1df78();
void sub_1df9d();
void sub_1dfc5();
void sub_1e01c();
void sub_1e093();
void sub_1e0ca();
void sub_1e0fa();
void sub_1e105();
void sub_1e12b();
void sub_1e140();
void sub_1e14e();
void sub_1e1da();
void sub_1e1f9();
void sub_1e211();
void sub_1e266();
void sub_1e2de();
void sub_1e307();
void sub_1f042();
void sub_1f072();
void sub_1f0d2();
void sub_1f129();
void sub_1f158();
void sub_1f286();
void sub_1f293();
void sub_1f2b5();
void sub_1f2bc();
void sub_1f2dc();
void sub_1f2e1();
void sub_1f311();
void sub_1f320(bool resume);
void sub_1f34a();
void sub_1f35f();
void sub_1f364();
void sub_1f36f();
void sub_1f37c_ctxswitch1();
void sub_1f404();
void sub_1f41f_ctxswitch2();
void sub_1f472_ctxswitch3();
void sub_1f4b3();
void sub_1f571();
void sub_1f5da();
void sub_1f5ed();
void sub_1f626();
void sub_1f62d();
void sub_1f64d();
void sub_1f66a();
void sub_1f6b1();
void sub_1f6be();
void sub_1f6d9();
void sub_1f6fc();
void sub_1f7d2();
void sub_1f827();
void sub_1f83b();
void sub_1f854();
void sub_1f87a();
void sub_1f888();
void sub_1f8c5();
void sub_1f8fd();
void sub_1f925();
void sub_1f961();
void sub_1f969();
void sub_1f971();
void sub_1f985();
void sub_1fb27();
void sub_1fb2b();
void sub_1fb2f();
void sub_1fb33();
void sub_1fb37();
void sub_1fb3b();
void sub_1fb42();
void sub_1fb46();
void sub_1fb4c();
void sub_1fb52();
void sub_1fb58();
void sub_1fb60();
void sub_1fb65();
void sub_1fb6d();
void sub_1fb75();
void sub_1fb79();
void sub_1fb7d();
void sub_1fb81();
void sub_1fb85();
void sub_1fb89();
void sub_1fb90();
void sub_1fb94();
void sub_1fb9b();
void sub_1fb9f();
void sub_1fba3();
void sub_1fbeb();
void sub_1fbfe();
void sub_1fc1c();
void sub_1fc33();
void sub_1fc3e();
void sub_1fc8e();
void sub_1fcdb();
void sub_1fd22();
void sub_1fd4b();
void sub_1fda3();
void sub_1fdbe();
void sub_1fe3b();
void sub_1fe3c();
void sub_1fe64();
void sub_1fe9e();
void sub_1feac();
void sub_1fee6();
void sub_1feed();
void sub_1ff51();
void sub_1ff6a();
void sub_1ffbb();
void sub_1ffec();
void sub_20014();
void sub_2001c();
void sub_2002a();
void sub_20049();
void sub_20070();
void sub_20093();
void sub_200b6();
void sub_200e7();
void sub_20113();
void sub_20173();
void sub_20181();
void sub_20366();
void sub_2039b();
void sub_20413();
void sub_20996();
void sub_20b66();
void sub_20be3();
void sub_20be5();
void sub_2127e();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    if(seg == 0x1b0c)
    {
        switch (ofs)
        {
            case 0x4d7b: sub_1fe3b(); return;
            case 0x4aa0: sub_1fb60(); return;
            case 0x4ae3: sub_1fba3(); return;
            case 0x4b5c: sub_1fc1c(); return;
            case 0x4c62: sub_1fd22(); return;
            case 0x4c8b: sub_1fd4b(); return;
            case 0x4cfe: sub_1fdbe(); return;
            case 0x4ce3: sub_1fda3(); return;
            case 0x4d7c: sub_1fe3c(); return;
            case 0x4dec: sub_1feac(); return;
            case 0x4dde: sub_1fe9e(); return;
            case 0x4e91: sub_1ff51(); return;
            case 0x4fb0: sub_20070(); return;
            case 0x4fd3: sub_20093(); return;
            case 0x4b2b: sub_1fbeb(); return;
            case 0x4b3e: sub_1fbfe(); return;
            case 0x5053: sub_20113(); return;
            case 0x4b7e: sub_1fc3e(); return;
            case 0x4bce: sub_1fc8e(); return;
            case 0x50b3: sub_20173(); return;
            default:
                break;
        }
        switch (ofs)
        {
            case 0x1135: sub_1c1f5(); return;
            case 0x4069: sub_1f129(); return;
            case 0x4efb: sub_1ffbb(); return;
            case 0x4f2c: sub_1ffec(); return;
            case 0x43f3: sub_1f4b3(); return;
            case 0x4221: sub_1f2e1(); return;
        }

    }
    if (seg == 0x19ee)
    {
        switch (ofs)
        {
            case 0x0b84: sub_1aa64(); return;
            case 0x0c92: sub_1ab72(); return;
            case 0x02f7: sub_1a1d7(); return;
            case 0x0a09: sub_1a8e9(); return;
            case 0x095d: sub_1a83d(); return; // 19ee:095d
        }
    }
    assert(seg == 0x1b0c);
    switch (ofs)
    {
        case 0x173c: sub_1c7fc(); return;
        case 0x1771: sub_1c831(); return;
        case 0x1789: sub_1c849(); return;
        case 0x178f: sub_1c84f(); return;
        case 0x1795: sub_1c855(); return;
        case 0x179b: sub_1c85b(); return;
        case 0x17a1: sub_1c861(); return;
        case 0x2c1a: sub_1dcda(); return;
        case 0x2edd: sub_1df9d(); return;
        case 0x1783: sub_1c843(); return;
        case 0x31a6: sub_1e266(); return;
        case 0x321e: sub_1e2de(); return;
        case 0x1bd5: sub_1cc95(); return;
        case 0x2615: sub_1d6d5(); return;
        case 0x1bf5: sub_1ccb5(); return;
        case 0x1b93: sub_1cc53(); return;
        case 0x1b13: sub_1cbd3(); return;
        case 0x1c18: sub_1ccd8(); return;
        case 0x1b71: sub_1cc31(); return;
        case 0x1d13: sub_1cdd3(); return;
        case 0x1acf: sub_1cb8f(); return;
        case 0x1d3a: sub_1cdfa(); return;
        case 0x253a: sub_1d5fa(); return;
        case 0x257f: sub_1d63f(); return;
        case 0x3151: sub_1e211(); return;
        case 0x3139: sub_1e1f9(); return;
        case 0x1a07: sub_1cac7(); return;
        case 0x1c1c: sub_1ccdc(); return;
        case 0x1a62: sub_1cb22(); return;
        case 0x25ed: sub_1d6ad(); return;
        default:
            break;
    }
    assert(seg == 0x1b0c);
    switch (ofs)
    {
        case 0x173c: sub_1c7fc(); return;
        case 0x2646: sub_1d706(); return;
        case 0x2c3e: sub_1dcfe(); return;
        case 0x2c14: sub_1dcd4(); return;
        case 0x1a5d: sub_1cb1d(); return;
        case 0x1ac3: sub_1cb83(); return;
        case 0x2b2f: sub_1dbef(); return;
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_1b41a()!
// INJECT: Error: cannot inject flag in sub_1b426() because of being label!
// INJECT: Error: cannot inject carry flag in sub_1f37c()!
// INJECT: Error: cannot inject carry flag in sub_1b41a()!
// INJECT: Error: cannot inject flag in sub_1b426() because of being label!
// INJECT: Error: cannot inject flag in sub_1f35f() because of being label!
// INJECT: Error: cannot inject carry flag in sub_1f37c()!
void sub_1a1d7() // 19ee:02f7
{
    push(cx);
    push(bx);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    si = 0x0000;
    cx = 0x0009;
    flags.interrupts = false;
    memoryASet16(ds, 0x029e, 0x0000);
loc_1a1ea: // 19ee:030a
    memoryASet16(ds, si + 278, 0x0000);
    memoryASet16(ds, si + 296, 0x0000);
    memoryASet16(ds, si + 224, 0x0000);
    memoryASet16(ds, si + 332, 0x0000);
    memoryASet16(ds, si + 242, 0x0000);
    memoryASet16(ds, si + 368, 0x0000);
    memoryASet16(ds, si + 260, 0x0000);
    memoryASet16(ds, si + 386, 0x0000);
    sub_1aa1a();
    si += 0x0002;
    if (--cx)
        goto loc_1a1ea;
    memoryASet(ds, 0x02f6, 0x00);
    flags.interrupts = true;
    ds = pop();
    si = pop();
    bx = pop();
    cx = pop();
    cs = pop();
}
void sub_1a2f8() // 19ee:0418
{
    push(ax);
    push(bx);
    push(cx);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    si = 0x0000;
    cx = 0x0009;
    flags.interrupts = false;
loc_1a306: // 19ee:0426
    push(ax);
    if (memoryAGet(ds, si + 333) & 0x02)
        goto loc_1a323;
    if (al != memoryAGet(ds, si + 332))
        goto loc_1a323;
    memoryASet(ds, si + 333, memoryAGet(ds, si + 333) | 0x02);
    bx = memoryAGet16(ds, 0x0000);
    callIndirect(cs, memoryAGet16(ds, bx + 20));
    sub_1aa1a();
loc_1a323: // 19ee:0443
    ax = pop();
    si += 0x0002;
    if (--cx)
        goto loc_1a306;
    flags.interrupts = true;
    ds = pop();
    si = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cs = pop();
}
void sub_1a330() // 19ee:0450
{
    push(ax);
    push(bx);
    push(cx);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    si = 0x0000;
    cx = 0x0009;
    flags.interrupts = false;
loc_1a33e: // 19ee:045e
    push(ax);
    if (!(memoryAGet(ds, si + 333) & 0x02))
        goto loc_1a35b;
    if (al != memoryAGet(ds, si + 332))
        goto loc_1a35b;
    memoryASet(ds, si + 333, memoryAGet(ds, si + 333) & 0xfd);
    sub_1aa2a();
    bx = memoryAGet16(ds, 0x0000);
    callIndirect(cs, memoryAGet16(ds, bx + 36));
loc_1a35b: // 19ee:047b
    ax = pop();
    si += 0x0002;
    if (--cx)
        goto loc_1a33e;
    flags.interrupts = true;
    ds = pop();
    si = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cs = pop();
}
void sub_1a83d() // 19ee:095d
{
    push(bx);
    push(cx);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    si = 0x0000;
    cx = 0x0009;
    bx = 0;
loc_1a84b: // 19ee:096b
    if (al != memoryAGet(ds, si + 332))
        goto loc_1a855;
    bx |= memoryAGet16(ds, si + 278);
loc_1a855: // 19ee:0975
    si += 0x0002;
    if (--cx)
        goto loc_1a84b;
    ds = pop();
    si = pop();
    cx = pop();
    bx = pop();
    cs = pop();
    flags.zero = true; //check???
}
void sub_1a861() // 19ee:0981
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    memoryASet16(ds, 0x00d4, ax);
    memoryASet(ds, 0x02f5, 0x00);
    memoryASet(ds, 0x02f6, 0x00);
    bx = cx;
    bx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x0000, bx);
    callIndirect(cs, memoryAGet16(ds, bx + 34));
    push(cs);
    cs = 0x19ee;
    sub_1a1d7();
    assert(cs == 0x19ee);
    ds = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cs = pop();
}
void sub_1a8e9() // 19ee:0a09
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(bp);
    push(ds);
    push(es);
    push(cs);
    ds = pop();
    sub_1a905();
    memoryASet(ds, 0x02f6, 0x00);
    flags.interrupts = true;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cs = pop();
}
void sub_1a905() // 19ee:0a25
{
    ah = 0;
    bp = 0x0000;
    cx = ax;
    flags.interrupts = false;
    es = memoryAGet16(ds, 0x00d4);
    cx++;
loc_1a912: // 19ee:0a32
    bx = memoryAGet16(es, bp);
    memoryASet16(ds, 0x00d6, bp);
    if (--cx)
        goto loc_1a93e;
    if (!bx)
        return;
    bx = memoryAGet16(es, bp + 8);
    memoryASet16(ds, 0x00de, bx);
    bx = memoryAGet16(es, bp + 4);
    bx += bp;
    memoryASet16(ds, 0x00da, bx);
    bx = memoryAGet16(es, bp + 2);
    bx += bp;
    memoryASet16(ds, 0x00d8, bx);
    goto loc_1a942;
loc_1a93e: // 19ee:0a5e
    bp += bx;
    goto loc_1a912;
loc_1a942: // 19ee:0a62
    dx = bp;
    bp = bx;
    si = 0x0000;
    cx = 0x0009;
    bx = ax;
loc_1a94e: // 19ee:0a6e
    ax = memoryAGet16(es, bp + si);
    if (!ax)
        goto loc_1a970;
    ax += dx;
    memoryASet16(ds, si + 278, ax);
    memoryASet16(ds, si + 296, ax);
    memoryASet16(ds, si + 224, 0x0001);
    memoryASet16(ds, si + 332, bx);
    ax = memoryAGet16(ds, 0x00da);
    memoryASet16(ds, si + 350, ax);
loc_1a970: // 19ee:0a90
    si += 0x0002;
    if (--cx)
        goto loc_1a94e;
}
void sub_1aa1a() // 19ee:0b3a
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    bx = memoryAGet16(ds, 0x0000);
    callIndirect(cs, memoryAGet16(ds, bx + 30));
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1aa2a() // 19ee:0b4a
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    bx = memoryAGet16(ds, 0x0000);
    callIndirect(cs, memoryAGet16(ds, bx + 32));
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1aa3a() // 19ee:0b5a
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    dx = 0x0388;
    out(dx, al);
    sub_1aa52();
    al = ah;
    dx++;
    out(dx, al);
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1aa52() // 19ee:0b72
{
    push(ax);
    push(cx);
    push(dx);
    dx = 0x0388;
    cx = 0x0006;
loc_1aa5b: // 19ee:0b7b
    in(al, dx);
    if (--cx)
        goto loc_1aa5b;
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_1aa64() // 19ee:0b84
{
    ax = 0x2001;
    sub_1aa3a();
    sub_1aac4();
    ax = 0x0004;
    sub_1aa3a();
    sub_1aac4();
    ax = 0x8004;
    sub_1aa3a();
    sub_1aac4();
    ax = 0x4008;
    sub_1aa3a();
    sub_1aac4();
    ax = 0x00bd;
    sub_1aa3a();
    sub_1aac4();
    cx = 0x0012;
    ah = 0x3f;
loc_1aa96: // 19ee:0bb6
    bx = cx;
    al = memoryAGet(ds, bx + 727);
    al += 0x40;
    sub_1aa3a();
    sub_1aac4();
    if (--cx)
        goto loc_1aa96;
    cx = 0x0009;
    ah = 0;
loc_1aaab: // 19ee:0bcb
    al = cl;
    al--;
    push(ax);
    al += 0xb0;
    sub_1aa3a();
    sub_1aac4();
    ax = pop();
    al += 0xa0;
    sub_1aa3a();
    sub_1aac4();
    if (--cx)
        goto loc_1aaab;
}
void sub_1aac4() // 19ee:0be4
{
    push(cx);
    cx = 0x0006;
loc_1aac8: // 19ee:0be8
    sub_1aa52();
    if (--cx)
        goto loc_1aac8;
    cx = pop();
}
void sub_1ab72() // 19ee:0c92
{
    ax = si;
    al >>= 1;
    memoryASet(ds, si + 405, memoryAGet(ds, si + 405) & 0xdf);
    ah = memoryAGet(ds, si + 405);
    al += 0xb0;
    sub_1aa3a();
    sub_1aac4();
}
void sub_1b060() // 19ee:1180
{
    push(cx);
    cx = 0x0000;
    push(cs);
    cs = 0x19ee;
    sub_1a861();
    assert(cs == 0x19ee);
    cx = pop();
    cs = pop();
}
void sub_1b06b() // 19ee:118b
{
    cs = 0x19ee;
    callIndirect(0x19ee, 0x0a09);
}
void sub_1b07f() // 19ee:119f
{
    cs = 0x19ee;
    callIndirect(0x19ee, 0x2f7);
}
void sub_1b08e() // 19ee:11ae
{
    cs = 0x19ee;
    callIndirect(0x19ee, 0x95d);
    //stop(); // ljmp 0x19ee:0x95d
}
void sub_1b0b1() // 19ee:11d1
{
    cs = 0x19ee;
    callIndirect(0x19ee, 0x418);

//    stop(); // ljmp 0x19ee:0x418
}
void sub_1b0b6() // 19ee:11d6
{
    cs = 0x19ee;
    callIndirect(0x19ee, 0x450);

//    stop(); // ljmp 0x19ee:0x450
}
void sub_1b0c0(bool resume) // 1b0c:0000 @ a390
{
    if (resume)
        goto resumelabel;
//    for (int i=0; i<32; i++)
//        printf("%02x, ", memoryAGet(0x1b0c, i));
//    assert(memoryAGet(0x1b0c, 0x0000) == 0xb8);
    ax = 0x1118;
    ds = ax;
    sub_1b994();
    sub_1b43e();
    sub_1c38c();
    sub_1c178();
    sub_1f87a();
    sub_1f158();
    sub_1f320(false);
resumelabel:
    sub_1f072();
loc_1b0dd: // 1b0c:001d
    sub_1ba4f();
    al = memoryAGet(ds, 0x00c7);
    if (al)
        goto loc_1b10f;
    sub_1baf1();
    sub_1bb74();
    sub_1b970();
    sub_1bcf0();
    sub_1b1aa();
    if (!(ah & 0x01))
        goto loc_1b100;
    bl = 0x31;
    sub_1b1d9();
loc_1b100: // 1b0c:0040
    if (!(ah & 0x02))
        goto loc_1b10a;
    bl = 0x32;
    sub_1b1d9();
loc_1b10a: // 1b0c:004a
    sub_1b29e();
    goto loc_1b0dd;
loc_1b10f: // 1b0c:004f
    al = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0a4d, 0x01);
    sub_1b4f0();
    goto loc_1b0dd;
}
void sub_1b130() // 1b0c:0070
{
    if (memoryAGet(ds, 0x48d3) == 0x00)
        goto loc_1b141;
    al += al;
    stop(); // daa 
    tl = al;
    al = ah;
    ah = tl;
    stop(/*8*/); // inject carry failed
    al += al + flags.carry;
    stop(); // daa 
    tl = al;
    al = ah;
    ah = tl;
loc_1b141: // 1b0c:0081
    sub_1b14b();
    push(si);
    sub_1b160();
    si = pop();
    goto loc_1b185;
    //   gap of 58 bytes
loc_1b185: // 1b0c:00c5
    ax = memoryAGet16(ds, 0x049c);
    if (al > memoryAGet(ds, bx))
        return;
    if (ah > memoryAGet(ds, bx + 1))
        return;
    al = memoryAGet(ds, 0x049e);
    if (al > memoryAGet(ds, bx + 3))
        return;
    bx += 0x0003;
    ax = 0x5000;
    bx = 0x049f;
    flags.carry = false;
    sub_1b14f();
    sub_1dbe2();
}
void sub_1b14b() // 1b0c:008b
{
    bx = 0x0493;
    flags.carry = false;
    sub_1b159();
    al = ah;
    sub_1b159();
    al = 0x00;
    flags.carry = bx == 0;
    bx--;
    al += memoryAGet(ds, bx) + flags.carry;
    stop(); // daa 
    memoryASet(ds, bx, al);
}
void sub_1b14f() // 1b0c:008f
{
    sub_1b159();
    al = ah;
    sub_1b159();
    al = 0x00;
    flags.carry = bx == 0;
    bx--;
    al += memoryAGet(ds, bx) + flags.carry;
    stop(); // daa 
    memoryASet(ds, bx, al);
}
void sub_1b159() // 1b0c:0099
{
    flags.carry = bx == 0;
    bx--;
    al += memoryAGet(ds, bx) + flags.carry;
    stop(); // daa 
    memoryASet(ds, bx, al);
}
void sub_1b160() // 1b0c:00a0
{
    bx = 0x0490;
    si = 0x0a46;
    push(si);
    push(bx);
    sub_1b1c6();
    bx = pop();
    si = pop();
    if (!flags.carry)
        goto loc_1b17f;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si, ax);
    al = memoryAGet(ds, bx + 2);
    memoryASet(ds, si + 2, al);
    memoryASet(ds, 0x002e, 0x01);
    return;
loc_1b17f: // 1b0c:00bf
    memoryASet(ds, 0x002e, 0x00);
}
void sub_1b1aa() // 1b0c:00ea
{
    ah = 0;
    bx = 0x0680;
    sub_1b1c3();
    if (!flags.carry)
        goto loc_1b1b7;
    ah |= 0x01;
loc_1b1b7: // 1b0c:00f7
    bx = 0x0863;
    sub_1b1c3();
    if (!flags.carry)
        return;
    ah |= 0x02;
}
void sub_1b1c3() // 1b0c:0103
{
    si = 0x00c2;
    cx = 0x0003;
loc_1b1c9: // 1b0c:0109
    al = memoryAGet(ds, bx);
    if (al > memoryAGet(ds, si))
        goto loc_1b1d7;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    si++;
    bx++;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    stop(/*e2*/);
    goto loc_1b1c9;
    flags.carry = false;
    return;
loc_1b1d7: // 1b0c:0117
    flags.carry = true;
}
void sub_1b1c6() // 1b0c:0106
{
    cx = 0x0003;
loc_1b1c9: // 1b0c:0109
    al = memoryAGet(ds, bx);
    if (al > memoryAGet(ds, si))
        goto loc_1b1d7;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    si++;
    bx++;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    stop(/*e2*/);
    goto loc_1b1c9;
    flags.carry = false;
    return;
loc_1b1d7: // 1b0c:0117
    flags.carry = true;
}
void sub_1b1d9() // 1b0c:0119
{
    push(ax);
    memoryASet(cs, 0x03c7, 0x00);
    memoryASet(ds, 0x004b, bl);
    sub_1b23c();
    if (flags.carry)
        goto loc_1b204;
    al = 0x01;
    sub_1b2b8();
    bx = 0x0109;
    if (cl != 0x06)
        goto loc_1b1f9;
    bl = 0x0d;
loc_1b1f9: // 1b0c:0139
    sub_1f0d2();
    sub_1b382();
    memoryASet(ds, 0x0004, 0x01);
loc_1b204: // 1b0c:0144
    ax = pop();
}
void sub_1b206() // 1b0c:0146
{
    if (memoryAGet(ds, 0x0004) != 0x01)
        return;
    memoryASet(ds, 0x0004, 0x00);
    al = 0x03;
    sub_1f2dc();
    sub_1f042();
    sub_1b22b();
    sub_1f83b();
    memoryASet(cs, 0x03c7, 0x00);
    sub_1f072();
}
void sub_1b22b() // 1b0c:016b
{
    dx = 0x0068;
    sub_1b41a();
    if (flags.carry)
        return;
    sub_1b426();
    if (flags.carry)
        return;
    sub_1b439();
}
void sub_1b23c() // 1b0c:017c
{
    bx = 0x0680;
    if (bl == 0x31)
        goto loc_1b247;
    bx = 0x0863;
loc_1b247: // 1b0c:0187
    cx = 0x0006;
    dx = 0x0041;
    si = 0x0081;
loc_1b250: // 1b0c:0190
    push(cx);
    push(bx);
    push(si);
    sub_1b1c6();
    si = pop();
    bx = pop();
    cx = pop();
    if (flags.carry)
        goto loc_1b265;
    dx -= 0x000d;
    si += 0x000d;
    if (--cx)
        goto loc_1b250;
    flags.carry = true;
    return;
loc_1b265: // 1b0c:01a5
    push(cx);
    si -= 0x0009;
    if (!dx)
        goto loc_1b280;
    push(es);
    ax = ds;
    es = ax;
    cx = dx;
    si = 0x00b8;
    di = 0x00c5;
    flags.direction = true;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    flags.direction = false;
    es = pop();
    si++;
loc_1b280: // 1b0c:01c0
    al = 0x20;
    cx = 0x0008;
    push(si);
loc_1b286: // 1b0c:01c6
    memoryASet(ds, si, al);
    si++;
    if (--cx)
        goto loc_1b286;
    si++;
    cx = 0x0004;
loc_1b28f: // 1b0c:01cf
    al = memoryAGet(ds, bx);
    memoryASet(ds, si, al);
    bx++;
    si++;
    if (--cx)
        goto loc_1b28f;
    si--;
    memoryASet(ds, si, memoryAGet(ds, si) + 1);
    si = pop();
    cx = pop();
    flags.carry = false;
}
void sub_1b29e() // 1b0c:01de
{
    al = 0;
    sub_1b2b8();
    cx = 0x04b0;
loc_1b2a6: // 1b0c:01e6
    push(cx);
    sub_1f961();
    sub_1c1ac();
    cx = pop();
    if (cl)
        goto loc_1b2b4;
    if (--cx)
        goto loc_1b2a6;
loc_1b2b4: // 1b0c:01f4
    sub_1b206();
}
void sub_1b2b8() // 1b0c:01f8
{
    push(si);
    push(cx);
    push(ax);
    sub_1fb33();
    bx = 0x000a;
    cx = 0x0080;
    dx = 0x008c;
    sub_1fb52();
    bx = 0x0007;
    cx = 0x0020;
    dx = 0x0005;
    sub_1fb52();
    sub_1b308();
    ax = pop();
    sub_1b2e6();
    sub_1fb2b();
    sub_1fb33();
    cx = pop();
    si = pop();
}
void sub_1b2e6() // 1b0c:0226
{
    if (!al)
        goto loc_1b2f9;
    si = 0x0044;
    bx = 0x0010;
    cx = 0x0044;
    al = 0x0f;
    sub_1fb75();
    return;
loc_1b2f9: // 1b0c:0239
    si = 0x002f;
    bx = 0x0050;
    cx = 0x0044;
    al = 0x0f;
    sub_1fb75();
}
void sub_1b308() // 1b0c:0248
{
    si = 0x0078;
    cx = 0x0050;
    ax = 0x060f;
loc_1b311: // 1b0c:0251
    push(ax);
    push(cx);
    push(si);
    bx = 0x0040;
    sub_1fb75();
    si = pop();
    cx = pop();
    ax = pop();
    si += 0x000d;
    cx += 0x0009;
    ah--;
    if (ah != 0)
        goto loc_1b311;
    di = 0x0081;
    dx = 0x0050;
    cx = 0x0006;
loc_1b330: // 1b0c:0270
    push(cx);
    push(dx);
    push(di);
    ax = memoryAGet16(ds, di + 1);
    cl = memoryAGet(ds, di);
    sub_1da36();
    al = 0x0f;
    si = 0x495d;
    bx = 0x0088;
    cx = dx;
    sub_1fb75();
    di = pop();
    dx = pop();
    cx = pop();
    di += 0x000d;
    dx += 0x0009;
    if (--cx)
        goto loc_1b330;
    di = 0x0084;
    dx = 0x0050;
    cx = 0x0006;
    memoryASet(ds, 0x495f, 0x00);
loc_1b361: // 1b0c:02a1
    push(cx);
    push(dx);
    push(di);
    al = memoryAGet(ds, di);
    sub_1b3f3();
    al = 0x0f;
    si = 0x495d;
    bx = 0x00d0;
    cx = dx;
    sub_1fb75();
    di = pop();
    dx = pop();
    cx = pop();
    di += 0x000d;
    dx += 0x0009;
    if (--cx)
        goto loc_1b361;
}
void sub_1b382() // 1b0c:02c2
{
    di = si;
    dx = si;
    dx += 0x0007;
    ch = 0x06;
    ch -= cl;
    al = 0x09;
    mul(ch);
    ax += 0x0050;
    cx = ax;
    memoryASet(ds, di, 0x2a);
    memoryASet(cs, 0x0303, 0x00);
    bp = 0x0040;
loc_1b3a2: // 1b0c:02e2
    push(si);
    push(cx);
    push(di);
    push(dx);
    push(bp);
    al = 0x0d;
    bx = bp;
    sub_1fb75();
    sub_1c413();
    bp = pop();
    dx = pop();
    di = pop();
    cx = pop();
    si = pop();
    if (al == 0x09)
        goto loc_1b3d2;
    if (al == 0x0d)
        goto loc_1b3dd;
    if (al == 0x1b)
        goto loc_1b3e7;
    if (al == 0x2e)
        goto loc_1b3ec;
    memoryASet(ds, di, al);
    if (di == dx)
        goto loc_1b3ec;
    di++;
    memoryASet(ds, di, 0x2a);
    goto loc_1b3a2;
loc_1b3d2: // 1b0c:0312
    if (di == si)
        goto loc_1b3a2;
    di--;
    memoryASet16(ds, di, 0x202a);
    goto loc_1b3a2;
loc_1b3dd: // 1b0c:031d
    if (memoryAGet(ds, di) != 0x2a)
        goto loc_1b3e5;
    memoryASet(ds, di, 0x20);
loc_1b3e5: // 1b0c:0325
    flags.carry = false;
    return;
loc_1b3e7: // 1b0c:0327
    sub_1b3dd();
    flags.carry = true;
    return;
loc_1b3ec: // 1b0c:032c
    push(dx);
    sub_1f293();
    dx = pop();
    goto loc_1b3a2;
}
void sub_1b3dd() // 1b0c:031d
{
    if (memoryAGet(ds, di) != 0x2a)
        goto loc_1b3e5;
    memoryASet(ds, di, 0x20);
loc_1b3e5: // 1b0c:0325
    flags.carry = false;
}
void sub_1b3f3() // 1b0c:0333
{
    bl = 0x2f;
loc_1b3f5: // 1b0c:0335
    bl++;
    tl = al;
    al -= 0x0a;
    if ((char)tl - (char)0x0a >= 0)
        goto loc_1b3f5;
    al += 0x0a;
    if (bl != 0x30)
        goto loc_1b404;
    bl = 0x20;
loc_1b404: // 1b0c:0344
    memoryASet(ds, 0x495d, bl);
    al += 0x30;
    memoryASet(ds, 0x495e, al);
}
// INJECT: Error: cannot inject carry flag in sub_1b41a()!
void sub_1b41a() // 1b0c:035a
{
    sub_1b488();
    cl = 0x00;
    ah = 0x3c;
    interrupt(0x21);
    bx = ax;
    stop(/*inject ret*/);
}
// INJECT: Error: cannot inject flag in sub_1b426() because of being label!
void sub_1b426() // 1b0c:0366
{
    ah = 0x40;
    dx = 0x0078;
    cx = 0x004e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_1b438;
    if (ax == 0x004e)
        goto loc_1b438;
    flags.carry = true;
loc_1b438: // 1b0c:0378
    stop(/*inject ret*/);
}
void sub_1b439() // 1b0c:0379
{
    ah = 0x3e;
    interrupt(0x21);
}
void sub_1b43e() // 1b0c:037e
{
    push(ds);
    ax = 0x3524;
    interrupt(0x21);
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, es);
    ax = cs;
    ds = ax;
    dx = 0x03bb;
    ax = 0x2524;
    interrupt(0x21);
    ds = pop();
}
void sub_1b45a() // 1b0c:039a
{
    ax = memoryAGet16(ds, 0x0000);
    ax |= memoryAGet16(ds, 0x0002);
    if (!ax)
        return;
    push(ds);
    dx = memoryAGet16(ds, 0x0000);
    ds = memoryAGet16(ds, 0x0002);
    ax = 0x2524;
    interrupt(0x21);
    ds = pop();
    ax = 0;
    memoryASet16(ds, 0x0000, ax);
    memoryASet16(ds, 0x0002, ax);
}
void sub_1b488() // 1b0c:03c8
{
    sub_1b4ac();
    if (!flags.carry)
        return;
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    bx = 0x0000;
    cx = 0x00c0;
    al = 0x0f;
    si = 0x0005;
    sub_1fb75();
    sub_1f293();
    sub_1c413();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_1b4ac() // 1b0c:03ec
{
    push(bx);
    push(es);
    interrupt(0x11);
    al &= 0xc0;
    if (al != 0)
        goto loc_1b4ec;
    bx = dx;
    bx--;
loc_1b4b7: // 1b0c:03f7
    bx++;
    al = memoryAGet(ds, bx);
    if (al == 0x3a)
        goto loc_1b4c8;
    if (al)
        goto loc_1b4b7;
    ah = 0x19;
    interrupt(0x21);
    goto loc_1b4d1;
loc_1b4c8: // 1b0c:0408
    if (bx == dx)
        goto loc_1b4ec;
    al = memoryAGet(ds, bx + 65535);
    al -= 0x41;
loc_1b4d1: // 1b0c:0411
    if (al >= 0x02)
        goto loc_1b4ec;
    bx = 0;
    es = bx;
    if (memoryAGet(es, 0x0504) == al)
        goto loc_1b4ec;
    memoryASet(es, 0x0504, al);
    al += 0x41;
    memoryASet(ds, 0x0011, al);
    flags.carry = true;
    goto loc_1b4ed;
loc_1b4ec: // 1b0c:042c
    flags.carry = false;
loc_1b4ed: // 1b0c:042d
    es = pop();
    bx = pop();
}
void sub_1b4f0() // 1b0c:0430
{
    goto loc_1b4f0;
loc_1b0dd: // 1b0c:001d
    sub_1ba4f();
    al = memoryAGet(ds, 0x00c7);
    if (al)
        goto loc_1b10f;
    sub_1baf1();
    sub_1bb74();
loc_1b0ed: // 1b0c:002d
    sub_1b970();
    sub_1bcf0();
    sub_1b1aa();
    if (!(ah & 0x01))
        goto loc_1b100;
    bl = 0x31;
    sub_1b1d9();
loc_1b100: // 1b0c:0040
    if (!(ah & 0x02))
        goto loc_1b10a;
    bl = 0x32;
    sub_1b1d9();
loc_1b10a: // 1b0c:004a
    sub_1b29e();
    goto loc_1b0dd;
loc_1b10f: // 1b0c:004f
    al = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0a4d, 0x01);
    sub_1b4f0();
    goto loc_1b0dd;
    //   gap of 975 bytes
loc_1b4f0: // 1b0c:0430
    bx = 0x0000;
    sub_1f0d2();
    sub_1f2dc();
    al = memoryAGet(ds, 0x0493);
    if (al == 0x10)
        goto loc_1b504;
    if (al != 0x21)
        goto loc_1b508;
loc_1b504: // 1b0c:0444
    memoryASet(ds, 0x0493, memoryAGet(ds, 0x0493) - 1);
loc_1b508: // 1b0c:0448
    memoryASet(ds, 0x00cf, 0x00);
    sub_1b764();
loc_1b510: // 1b0c:0450
    sub_1c227();
    if (memoryAGet(ds, 0x00c7) == 0x00)
        goto loc_1b528;
    sub_1b59a();
    if (bl)
        goto loc_1b523;
    goto loc_1b510;
loc_1b523: // 1b0c:0463
    sub_1b5d0();
    goto loc_1b510;
loc_1b528: // 1b0c:0468
    sub_1fb2b();
    sub_1fb42();
    al = 0;
    memoryASet(ds, 0x48c4, al);
    memoryASet(ds, 0x0a4d, al);
    ax = pop();
    goto loc_1b0ed;
}
void sub_1b53a() // 1b0c:047a
{
    sub_1f961();
    sub_1fb33();
    sub_1bfad();
    sub_1c045();
    sub_1c02d();
    sub_1bfe4();
    sub_1c0f7();
    sub_1c064();
    sub_1b562();
    sub_1fb37();
    sub_1fb2b();
    sub_1fb42();
    sub_1fb2f();
}
void sub_1b562() // 1b0c:04a2
{
    bx = 0x002c;
    cx = 0x00f0;
    dx = 0x0010;
    sub_1fb52();
    bx = 0x000d;
    cx = 0x00e0;
    dx = 0x00a1;
    sub_1fb52();
    sub_1e0fa();
    al = 0x4c;
    if (memoryAGet(ds, 0x0494) == 0x00)
        goto loc_1b588;
    al = 0x52;
loc_1b588: // 1b0c:04c8
    memoryASet(ds, 0x48c4, al);
    al = 0x0f;
    bx = 0x0108;
    cx = 0x0087;
    si = 0x48c2;
    sub_1fb75();
}
void sub_1b59a() // 1b0c:04da
{
    push(bx);
    push(dx);
    push(cx);
    bl = memoryAGet(ds, 0x00cf);
    if (!bl)
        goto loc_1b5b9;
    cx += 0x0004;
    dl += 0x04;
    bh = 0;
    sub_1d5c7();
    memoryASet16(ds, 0x00d0, ax);
    sub_1fb3b();
    sub_1fb4c();
loc_1b5b9: // 1b0c:04f9
    cx = pop();
    dx = pop();
    push(dx);
    push(cx);
    bx = 0x00fc;
    sub_1fb3b();
    sub_1fb4c();
    sub_1fb2b();
    sub_1fb42();
    cx = pop();
    dx = pop();
    bx = pop();
}
void sub_1b5d0() // 1b0c:0510
{
    cx += 0x0004;
    dl += 0x04;
    si = 0x00f6;
loc_1b5d9: // 1b0c:0519
    if (cx < memoryAGet16(ds, si))
        goto loc_1b5fc;
    if (dl < memoryAGet(ds, si + 2))
        goto loc_1b5fc;
    ah = 0;
    al = memoryAGet(ds, si + 3);
    ax += memoryAGet16(ds, si);
    if (cx > ax)
        goto loc_1b5fc;
    ah = 0;
    al = memoryAGet(ds, si + 4);
    al += memoryAGet(ds, si + 2);
    if (dx > ax)
        goto loc_1b5fc;
    stop(/*2*/); // 1b0c:0539 jmp word ptr [si + 5] - jump Indirect memoryAGet16(ds, si + 5)
loc_1b5fc: // 1b0c:053c
    si += 0x0007;
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_1b5d9;
}
void sub_1b764() // 1b0c:06a4
{
    sub_1bf80();
    memoryASet16(ds, 0x00cd, si);
    sub_1bf3a();
    sub_1b53a();
}
void sub_1b970() // 1b0c:08b0
{
    ax = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0490, al);
    memoryASet16(ds, 0x0491, ax);
    memoryASet(ds, 0x0497, 0x03);
    memoryASet(ds, 0x0a49, 0x31);
    memoryASet16(ds, 0x049c, 0x2000);
    memoryASet(ds, 0x049e, 0x00);
}
void sub_1b978() // 1b0c:08b8
{
    memoryASet(ds, 0x0490, al);
    memoryASet16(ds, 0x0491, ax);
    memoryASet(ds, 0x0497, 0x03);
    memoryASet(ds, 0x0a49, 0x31);
    memoryASet16(ds, 0x049c, 0x2000);
    memoryASet(ds, 0x049e, 0x00);
}
void sub_1b994() // 1b0c:08d4
{
    push(es);
    push(ds);
    //interrupt(0x61);
    ax = 0x04dd;
    si = 0x003c;
    es = ax;
    al = memoryAGet(es, si);
    memoryASet(ds, 0x00c7, al);
    al = memoryAGet(es, si + 1);
    memoryASet(ds, 0x47e0, al);
    al = memoryAGet(es, si + 2);
    memoryASet(ds, 0x048f, al);
    al = memoryAGet(es, si + 3);
    memoryASet(ds, 0x0a4a, al);
    al = memoryAGet(es, si + 4);
    memoryASet(ds, 0x0a4b, al);
    al = memoryAGet(es, si + 5);
    memoryASet(ds, 0x049a, al);
    al = memoryAGet(es, si + 6);
    memoryASet(ds, 0x0284, al);
    al = memoryAGet(es, si + 7);
    memoryASet(cs, 0x325b, al);
    al = memoryAGet(es, si + 8);
    memoryASet(ds, 0x5e36, al);
    al = memoryAGet(es, si + 9);
    memoryASet(ds, 0x47e8, al);
    al = memoryAGet(es, si + 10);
    memoryASet(ds, 0x5e35, al);
    ax = memoryAGet16(es, si + 11);
    memoryASet16(ds, 0x47fb, ax);
    ax = memoryAGet16(es, si + 13);
    memoryASet16(ds, 0x47fd, ax);
    ax = memoryAGet16(es, si + 15);
    memoryASet16(ds, 0x47ff, ax);
    ax = memoryAGet16(es, si + 17);
    memoryASet16(ds, 0x4801, ax);
    ax = memoryAGet16(es, si + 19);
    memoryASet16(ds, 0x4803, ax);
    ax = es;
    bx = ds;
    ds = ax;
    es = bx;
    si += 0x0015;
    di = 0x0075;
    cx = 0x0051;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    ax = ds;
    es = ax;
    cx = 0x0003;
    si = 0x0081;
    di = 0x0a46;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = memoryAGet(ds, 0x0075);
    memoryASet(cs, 0x150a, al);
    al = memoryAGet(ds, 0x0076);
    memoryASet(cs, 0x150b, al);
    al = memoryAGet(ds, 0x0077);
    memoryASet(cs, 0x150c, al);
    es = pop();
}
void sub_1ba4f() // 1b0c:098f
{
loc_1ba4f: // 1b0c:098f
    memoryASet(ds, 0x4809, 0x00);
    sub_1fb33();
    bx = 0x0006;
    cx = 0x0060;
    dx = 0x0044;
    sub_1fb52();
    bx = 0x0007;
    cx = 0x0020;
    dx = 0x0005;
    sub_1fb52();
    bx = 0x0008;
    cx = 0x0000;
    dx = 0x0046;
    sub_1fb52();
    bx = 0x0008;
    cx = 0x00e8;
    dx = 0x0046;
    sub_1fb52();
    bx = 0x000d;
    cx = 0x00e0;
    dx = 0x00a1;
    sub_1fb52();
    sub_1fb2b();
    sub_1f311();
    bx = 0x010c;
    sub_1f0d2();
    if (memoryAGet(ds, 0x027d) != 0x00)
        goto loc_1baa9;
    sub_1bc60();
loc_1baa9: // 1b0c:09e9
    cx = 0x03c0;
loc_1baac: // 1b0c:09ec
    push(cx);
    sub_1f961();
    sub_1c1ac();
    cx = pop();
    if (cl)
        return;
    if (--cx)
        goto loc_1baac;
    al = memoryAGet(ds, 0x00c7);
    if (al)
        return;
    al = memoryAGet(cs, 0x325b);
    memoryASet(ds, 0x0282, al);
    memoryASet(cs, 0x325b, memoryAGet(cs, 0x325b) & 0xfc);
    sub_1f2dc();
    memoryASet(ds, 0x0283, 0x00);
    sub_1bc14();
    al = memoryAGet(ds, 0x0282);
    memoryASet(cs, 0x325b, al);
    if (memoryAGet(ds, 0x0283) != 0x00)
        goto loc_1baea;
    goto loc_1ba4f;
loc_1baea: // 1b0c:0a2a
    bx = 0x010c;
    sub_1f0d2();
}
void sub_1baf1() // 1b0c:0a31
{
    memoryASet(ds, 0x4809, 0x00);
    sub_1fb33();
    bx = 0x0009;
    cx = 0x0000;
    dx = 0x006e;
    sub_1fb52();
    sub_1beac();
    sub_1fb2b();
    si = 0x0285;
loc_1bb0f: // 1b0c:0a4f
    al = 0x05;
    bx = 0x0008;
    cx = 0x005c;
    sub_1fb75();
    si++;
    al = memoryAGet(ds, si);
    if (al == 0xff)
        goto loc_1bb40;
    cx = 0x0009;
loc_1bb24: // 1b0c:0a64
    push(cx);
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1fb7d();
    sub_1c1ac();
    cx = pop();
    if (cl)
        return;
    if (--cx)
        goto loc_1bb24;
    goto loc_1bb0f;
loc_1bb40: // 1b0c:0a80
    cx = 0x0064;
loc_1bb43: // 1b0c:0a83
    push(cx);
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1fb7d();
    sub_1c1ac();
    cx = pop();
    if (cl)
        return;
    if (--cx)
        goto loc_1bb43;
}
void sub_1bb0f() // 1b0c:0a4f
{
loc_1bb0f: // 1b0c:0a4f
    al = 0x05;
    bx = 0x0008;
    cx = 0x005c;
    sub_1fb75();
    si++;
    al = memoryAGet(ds, si);
    if (al == 0xff)
        goto loc_1bb40;
    cx = 0x0009;
loc_1bb24: // 1b0c:0a64
    push(cx);
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1fb7d();
    sub_1c1ac();
    cx = pop();
    if (cl)
        return;
    if (--cx)
        goto loc_1bb24;
    goto loc_1bb0f;
loc_1bb40: // 1b0c:0a80
    cx = 0x0064;
loc_1bb43: // 1b0c:0a83
    push(cx);
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1fb7d();
    sub_1c1ac();
    cx = pop();
    if (cl)
        return;
    if (--cx)
        goto loc_1bb43;
}
void sub_1bb5e() // 1b0c:0a9e
{
    sub_1bbe6();
    si = 0x045c;
    cx = 0x6e00;
    dx = 0x9600;
    sub_1bb85();
    si = 0x03bb;
    sub_1bb0f();
}
void sub_1bb74() // 1b0c:0ab4
{
    memoryASet(ds, 0x4809, 0x00);
    sub_1bbe6();
    si = 0x0429;
    cx = 0x1e00;
    dx = 0x1900;
loc_1bb85: // 1b0c:0ac5
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_1bbc0;
loc_1bb8b: // 1b0c:0acb
    cx += memoryAGet16(ds, si + 1);
    dx += memoryAGet16(ds, si + 3);
    bx = 0x00c8;
    push(ax);
    push(cx);
    push(dx);
    push(si);
    cl = ch;
    dl = dh;
    ch = 0;
    dh = ch;
    sub_1fb3b();
    sub_1fb4c();
    sub_1fb2b();
    sub_1fb42();
    sub_1c1ac();
    si = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    if (cl)
        goto loc_1bbdf;
    al--;
    if (al != 0)
        goto loc_1bb8b;
    si += 0x0005;
    goto loc_1bb85;
loc_1bbc0: // 1b0c:0b00
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        goto loc_1bbdf;
    sub_1fb2b();
    sub_1fb42();
loc_1bbce: // 1b0c:0b0e
    ax = 0x0007;
    push(cs);
    cs = 0x19ee;
    sub_1b08e();
    assert(cs == 0x1b0c);
    if (flags.zero)
        goto loc_1bbdf;
    sub_1c1ac();
    if (!cl)
        goto loc_1bbce;
loc_1bbdf: // 1b0c:0b1f
    sub_1fb2b();
    sub_1fb42();
}
void sub_1bb85() // 1b0c:0ac5
{
loc_1bb85: // 1b0c:0ac5
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_1bbc0;
loc_1bb8b: // 1b0c:0acb
    cx += memoryAGet16(ds, si + 1);
    dx += memoryAGet16(ds, si + 3);
    bx = 0x00c8;
    push(ax);
    push(cx);
    push(dx);
    push(si);
    cl = ch;
    dl = dh;
    ch = 0;
    dh = ch;
    sub_1fb3b();
    sub_1fb4c();
    sub_1fb2b();
    sub_1fb42();
    sub_1c1ac();
    si = pop();
    dx = pop();
    cx = pop();
    ax = pop();
    if (cl)
        goto loc_1bbdf;
    al--;
    if (al != 0)
        goto loc_1bb8b;
    si += 0x0005;
    goto loc_1bb85;
loc_1bbc0: // 1b0c:0b00
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        goto loc_1bbdf;
    sub_1fb2b();
    sub_1fb42();
loc_1bbce: // 1b0c:0b0e
    ax = 0x0007;
    push(cs);
    cs = 0x19ee;
    sub_1b08e();
    assert(cs == 0x1b0c);
    if (flags.zero)
        goto loc_1bbdf;
    sub_1c1ac();
    if (!cl)
        goto loc_1bbce;
loc_1bbdf: // 1b0c:0b1f
    sub_1fb2b();
    sub_1fb42();
}
void sub_1bbe6() // 1b0c:0b26
{
    sub_1fb33();
    bx = 0x0009;
    cx = 0x0000;
    dx = 0x006e;
    sub_1fb52();
    bx = 0x0010;
    cx = 0x0010;
    dx = 0x000a;
    sub_1fb52();
    sub_1beac();
    sub_1fb2b();
    sub_1fb2f();
    sub_1f311();
    bx = 0x0108;
    sub_1f0d2();
}
void sub_1bc14() // 1b0c:0b54
{
    al = memoryAGet(ds, 0x0284);
    push(ax);
    al = 0x31;
    memoryASet(ds, 0x0284, al);
    al = memoryAGet(ds, 0x0a4a);
    push(ax);
    al |= 0x80;
    memoryASet(ds, 0x0a4a, al);
    memoryASet16(ds, 0x027e, 0x5460);
    sub_1bce1();
    al &= 0x01;
    memoryASet(ds, 0x0494, al);
loc_1bc34: // 1b0c:0b74
    sub_1bce1();
    al &= 0x3f;
    if (al > 0x21)
        goto loc_1bc34;
    memoryASet(ds, 0x0493, al);
    ax = 0;
    sub_1b978();
    sub_1bcf0();
    ax = pop();
    memoryASet(ds, 0x0a4a, al);
    memoryASet(ds, 0x049a, al);
    ax = pop();
    memoryASet(ds, 0x0284, al);
    sub_1b970();
}
void sub_1bc60() // 1b0c:0ba0
{
    memoryASet(ds, 0x027d, 0x01);
    sub_1f961();
    sub_1f286();
    push(ax);
    cx = 0x0000;
    dx = 0x0000;
    bx = 0x00c8;
    sub_1fb3b();
    sub_1fb3b();
    sub_1fb4c();
    sub_1f286();
    bx = pop();
    bx -= ax;
    push(bx);
    sub_1fb42();
    sub_1f961();
    sub_1f286();
    push(ax);
    cx = 0x0100;
loc_1bc92: // 1b0c:0bd2
    ax = memoryAGet16(ds, 0x0280);
    bx >>= 1;
    bx += ax;
    if (--cx)
        goto loc_1bc92;
    sub_1f286();
    bx = pop();
    bx -= ax;
    ax = pop();
    ax >>= 1;
    bx += ax;
    al = 0x01;
    cx = 0x070f;
    if (bx < 0x122e)
        goto loc_1bcc7;
    memoryASet(cs, 0x1cd0, 0x01);
    cx = 0x0507;
    al = 0x02;
    if (bx < 0x245c)
        goto loc_1bcc7;
    cx = 0x0303;
    al = 0x03;
loc_1bcc7: // 1b0c:0c07
    memoryASet(ds, 0x5870, al);
    al <<= 1;
    ah = 0;
    memoryASet16(ds, 0x586d, ax);
    memoryASet(ds, 0x586b, ch);
    memoryASet(ds, 0x586c, cl);
}
void sub_1bce1() // 1b0c:0c21
{
    ax = memoryAGet16(ds, 0x0280);
    al += 0x97;
    memoryASet16(ds, 0x0280, ax);
}
void sub_1bcf0() // 1b0c:0c30
{
    sub_1bf3a();
    sub_1be22();
loc_1bcf6: // 1b0c:0c36
    sub_1bd07();
    sub_1bdcc();
    if (memoryAGet(ds, 0x0497) != 0x00)
        goto loc_1bcf6;
    sub_1be93();
}
void sub_1bd07() // 1b0c:0c47
{
    goto loc_1bd07;
loc_1b0dd: // 1b0c:001d
    sub_1ba4f();
    al = memoryAGet(ds, 0x00c7);
    if (al)
        goto loc_1b10f;
    sub_1baf1();
    sub_1bb74();
    sub_1b970();
    sub_1bcf0();
    sub_1b1aa();
    if (!(ah & 0x01))
        goto loc_1b100;
    bl = 0x31;
    sub_1b1d9();
loc_1b100: // 1b0c:0040
    if (!(ah & 0x02))
        goto loc_1b10a;
    bl = 0x32;
    sub_1b1d9();
loc_1b10a: // 1b0c:004a
    sub_1b29e();
    goto loc_1b0dd;
loc_1b10f: // 1b0c:004f
    al = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0a4d, 0x01);
loc_1b11c: // 1b0c:005c
    sub_1b4f0();
    goto loc_1b0dd;
    //   gap of 3046 bytes
loc_1bd07: // 1b0c:0c47
    al = memoryAGet(ds, 0x0494);
    memoryASet(ds, 0x0ac2, al);
    sub_1bd95();
    si = 0x58e2;
    sub_1c8f8();
    sub_1f961();
loc_1bd19: // 1b0c:0c59
    sub_1c750();
    if (memoryAGet(ds, 0x0a4c) < 0x01)
        goto loc_1bd19;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_1fb90();
    sub_1fb2b();
    sub_1fb42();
    memoryASet(ds, 0x0a4c, 0x00);
    memoryASet(ds, 0x47e1, 0x00);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    if (stop(/*1 - je loc_1bd41*/))
        goto loc_1bd41;
    memoryASet(ds, 0x0497, memoryAGet(ds, 0x0497) - 1);
    if (memoryAGet(ds, 0x0497) == 0)
        goto loc_1bd5f;
    return;
loc_1bd41: // 1b0c:0c81
    if (memoryAGet(ds, 0x0a4d) == 0x01)
        goto loc_1bd86;
    memoryASet(ds, 0x0493, memoryAGet(ds, 0x0493) + 1);
    sub_1bf3a();
    if (memoryAGet(ds, 0x0493) != 0x22)
        goto loc_1bd07;
    sub_1bb5e();
    memoryASet(ds, 0x0497, 0x00);
    return;
loc_1bd5f: // 1b0c:0c9f
    if (memoryAGet(ds, 0x0a4d) == 0x01)
        goto loc_1bd86;
    bx = 0x0107;
    sub_1f0d2();
    bx = 0x0050;
    cx = 0x00a2;
    al = 0x0f;
    si = 0x0a59;
    sub_1fb79();
    cx = 0x00b4;
loc_1bd7d: // 1b0c:0cbd
    sub_1c46f();
    sub_1f961();
    if (--cx)
        goto loc_1bd7d;
    return;
loc_1bd86: // 1b0c:0cc6
    memoryASet(ds, 0x00c7, 0xff);
    al = memoryAGet(ds, 0x0ac2);
    memoryASet(ds, 0x0494, al);
    ax = pop();
    goto loc_1b11c;
}
void sub_1bd95() // 1b0c:0cd5
{
    sub_1f961();
    sub_1fb33();
    sub_1be6d();
    sub_1c8de();
    sub_1bfad();
    sub_1c045();
    sub_1c02d();
    sub_1bfe4();
    sub_1c0a5();
    sub_1c064();
    sub_1c008();
    sub_1be47();
    sub_1beac();
    sub_1fb37();
    sub_1f969();
    sub_1fb2b();
    sub_1fb2f();
    sub_1fb81();
}
void sub_1bdcc() // 1b0c:0d0c
{
    if (memoryAGet(ds, 0x0284) == 0x31)
        goto loc_1bde0;
    sub_1bde4();
    if (memoryAGet(ds, 0x0497) != 0x00)
        goto loc_1bde0;
    sub_1bde4();
loc_1bde0: // 1b0c:0d20
    sub_1c178();
}
void sub_1bde4() // 1b0c:0d24
{
    push(es);
    ax = ds;
    es = ax;
    di = 0x0680;
    si = 0x0863;
    if (memoryAGet(ds, 0x0a49) == 0x31)
        goto loc_1bdf8;
    tx = di;
    di = si;
    si = tx;
loc_1bdf8: // 1b0c:0d38
    push(si);
    si = 0x0490;
    cx = 0x01e3;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si = pop();
    di = 0x0490;
    cx = 0x01e3;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
    memoryASet(ds, 0x58da, 0x78);
    memoryASet(ds, 0x0a49, memoryAGet(ds, 0x0a49) ^ 0x03);
    if (memoryAGet(ds, 0x0a49) == 0x31)
        return;
    memoryASet(ds, 0x58da, 0x8c);
}
void sub_1be22() // 1b0c:0d62
{
    push(es);
    ax = ds;
    es = ax;
    di = 0x0863;
    al = memoryAGet(ds, 0x0a4b);
    sub_1be3b();
    di = 0x0680;
    al = memoryAGet(ds, 0x0a4a);
    sub_1be3b();
    es = pop();
}
void sub_1be3b() // 1b0c:0d7b
{
    memoryASet(ds, 0x049a, al);
    si = 0x0490;
    cx = 0x01e3;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_1be47() // 1b0c:0d87
{
    al = memoryAGet(ds, 0x0493);
    if (al == 0x10)
        goto loc_1be53;
    if (al == 0x21)
        goto loc_1be60;
    return;
loc_1be53: // 1b0c:0d93
    bx = 0x0017;
    cx = 0x0050;
    dx = 0x0034;
    sub_1fb52();
    return;
loc_1be60: // 1b0c:0da0
    bx = 0x0011;
    cx = 0x0058;
    dx = 0x003c;
    sub_1fb52();
}
void sub_1be6d() // 1b0c:0dad
{
    al = 0;
    memoryASet(ds, 0x48d5, al);
    memoryASet(ds, 0x48e0, al);
    memoryASet(ds, 0x48eb, al);
    memoryASet(ds, 0x48ec, al);
    memoryASet(ds, 0x48d3, al);
    al = memoryAGet(ds, 0x0499);
    if (memoryAGet(ds, 0x048f) != 0x07)
        goto loc_1be90;
    bl = al;
    al >>= 1;
    al >>= 1;
    al += bl;
loc_1be90: // 1b0c:0dd0
    memoryASet(ds, 0x48e8, al);
    bx = 0x0680;
    if (memoryAGet(ds, 0x0a49) == 0x31)
        goto loc_1bea0;
    bx = 0x0863;
loc_1bea0: // 1b0c:0de0
    ax = memoryAGet16(ds, 0x0490);
    memoryASet16(ds, bx, ax);
    ax = memoryAGet16(ds, 0x0492);
    memoryASet16(ds, bx + 2, ax);
}
void sub_1be93() // 1b0c:0dd3
{
    bx = 0x0680;
    if (memoryAGet(ds, 0x0a49) == 0x31)
        goto loc_1bea0;
    bx = 0x0863;
loc_1bea0: // 1b0c:0de0
    ax = memoryAGet16(ds, 0x0490);
    memoryASet16(ds, bx, ax);
    ax = memoryAGet16(ds, 0x0492);
    memoryASet16(ds, bx + 2, ax);
}
void sub_1beac() // 1b0c:0dec
{
    bx = 0x000b;
    cx = 0x00f0;
    dx = 0x0000;
    sub_1fb52();
    bx = 0x000a;
    cx = 0x00f0;
    dx = 0x000e;
    sub_1fb52();
    bx = 0x0008;
    cx = 0x00f0;
    dx = 0x0047;
    sub_1fb52();
    bx = 0x000d;
    cx = 0x00e0;
    dx = 0x00a1;
    sub_1fb52();
    bx = 0x000c;
    cx = 0x00f0;
    dx = 0x005a;
    sub_1fb52();
    bx = 0x000e;
    cx = 0x00f8;
    dx = 0x006e;
    sub_1fb52();
    bx = 0x000f;
    cx = 0x00f8;
    dx = 0x0082;
    sub_1fb52();
    cl = memoryAGet(ds, 0x0680);
    ax = memoryAGet16(ds, 0x0681);
    sub_1da36();
    cx = 0x0078;
    bx = 0x00f0;
    sub_1cdef();
    cl = memoryAGet(ds, 0x0863);
    ax = memoryAGet16(ds, 0x0864);
    sub_1da36();
    cx = 0x008c;
    bx = 0x00f0;
    sub_1cdef();
    cl = memoryAGet(ds, 0x0a46);
    ax = memoryAGet16(ds, 0x0a47);
    sub_1da36();
    cx = 0x0064;
    bx = 0x00f0;
    sub_1cdef();
}
void sub_1bf26() // 1b0c:0e66
{
    cl = memoryAGet(ds, 0x0a46);
    ax = memoryAGet16(ds, 0x0a47);
    sub_1da36();
    cx = 0x0064;
    bx = 0x00f0;
    sub_1cdef();
}
void sub_1bf3a() // 1b0c:0e7a
{
    push(es);
    ax = ds;
    es = ax;
    sub_1bf80();
    al = memoryAGet(ds, si);
    memoryASet(ds, 0x0495, al);
    si++;
    al = memoryAGet(ds, si);
    memoryASet(ds, 0x0496, al);
    si++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, 0x0499, ah);
    si++;
    di = 0x0a4e;
    cx = 0x000a;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = 0x0a4e;
    cl = 0xff;
loc_1bf62: // 1b0c:0ea2
    cl++;
    ah = memoryAGet(ds, di);
    di++;
    if (ah)
        goto loc_1bf62;
    memoryASet(ds, 0x48ed, cl);
    di = 0x049f;
    cx = 0x00ea;
    push(cx);
    rep_stosb<MemAuto, DirAuto>();
    cx = pop();
    di = 0x0589;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_1bf80() // 1b0c:0ec0
{
    bl = memoryAGet(ds, 0x0493);
    bh = 0;
    bx <<= 1;
    si = 0x0ad0;
    al = memoryAGet(ds, 0x0494);
    ah = 0;
    bx += ax;
    al = memoryAGet(ds, bx + si);
    cx = 0x00f7;
    mul(cx);
    si = 0x0b17;
    si += ax;
}
void sub_1bf9f() // 1b0c:0edf
{
    cx = 0x0009;
    dx = 0x0018;
    bp = 0x0020;
    si = 0x0005;
    goto loc_1bfb9;
    //   gap of 12 bytes
loc_1bfb9: // 1b0c:0ef9
    bh = 0;
    bl = memoryAGet(ds, 0x0495);
loc_1bfbf: // 1b0c:0eff
    push(cx);
    push(bp);
    push(si);
    cx = si;
    di = bp;
loc_1bfc6: // 1b0c:0f06
    push(cx);
    cx = di;
    push(bx);
    push(dx);
    push(di);
    sub_1fb52();
    di = pop();
    dx = pop();
    bx = pop();
    di += 0x0020;
    cx = pop();
    if (--cx)
        goto loc_1bfc6;
    si = pop();
    bp = pop();
    cx = pop();
    dx += 0x0012;
    if (--cx)
        goto loc_1bfbf;
    sub_1fb37();
}
void sub_1bfad() // 1b0c:0eed
{
    cx = 0x000b;
    dx = 0x0006;
    bp = 0x0000;
    si = 0x0007;
    bh = 0;
    bl = memoryAGet(ds, 0x0495);
loc_1bfbf: // 1b0c:0eff
    push(cx);
    push(bp);
    push(si);
    cx = si;
    di = bp;
loc_1bfc6: // 1b0c:0f06
    push(cx);
    cx = di;
    push(bx);
    push(dx);
    push(di);
    sub_1fb52();
    di = pop();
    dx = pop();
    bx = pop();
    di += 0x0020;
    cx = pop();
    if (--cx)
        goto loc_1bfc6;
    si = pop();
    bp = pop();
    cx = pop();
    dx += 0x0012;
    if (--cx)
        goto loc_1bfbf;
    sub_1fb37();
}
void sub_1bfe4() // 1b0c:0f24
{
    si = 0x0a62;
    cx = 0x0020;
loc_1bfea: // 1b0c:0f2a
    push(cx);
    bh = 0;
    ch = bh;
    dh = bh;
    bl = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    dl = memoryAGet(ds, si + 2);
    push(si);
    sub_1fb4c();
    si = pop();
    si += 0x0003;
    cx = pop();
    if (--cx)
        goto loc_1bfea;
    sub_1fb37();
}
void sub_1c008() // 1b0c:0f48
{
    al = memoryAGet(ds, 0x0497);
    if (al < 0x06)
        goto loc_1c011;
    al = 0x06;
loc_1c011: // 1b0c:0f51
    al--;
    if (al == 0)
        return;
    cx = 0x000a;
loc_1c018: // 1b0c:0f58
    push(ax);
    push(cx);
    bx = 0x00c8;
    dx = 0x00c3;
    sub_1fb4c();
    cx = pop();
    cx += 0x0010;
    ax = pop();
    al--;
    if (al != 0)
        goto loc_1c018;
}
void sub_1c02d() // 1b0c:0f6d
{
    ax = 0x0001;
    cx = 0x0013;
loc_1c033: // 1b0c:0f73
    push(cx);
    bx = 0x0001;
    cx = 0x001a;
loc_1c03a: // 1b0c:0f7a
    sub_1fb65();
    bx++;
    if (--cx)
        goto loc_1c03a;
    ax++;
    cx = pop();
    if (--cx)
        goto loc_1c033;
}
void sub_1c045() // 1b0c:0f85
{
    bx = 0x0001;
    ax = 0x0001;
    cx = 0x001b;
loc_1c04e: // 1b0c:0f8e
    sub_1fb58();
    ax++;
    if (--cx)
        goto loc_1c04e;
    bx = 0x0002;
    ax = 0x0001;
    cx = 0x0019;
loc_1c05d: // 1b0c:0f9d
    sub_1fb58();
    bx++;
    if (--cx)
        goto loc_1c05d;
}
void sub_1c064() // 1b0c:0fa4
{
    si = 0x0589;
    ax = 0x0002;
    cx = 0x0012;
loc_1c06d: // 1b0c:0fad
    push(cx);
    bx = 0x0002;
    cx = 0x000d;
loc_1c074: // 1b0c:0fb4
    dl = memoryAGet(ds, si);
    dl &= 0x0f;
    if (dl == 0)
        goto loc_1c09b;
    dl = memoryAGet(ds, si + 13);
    dl &= 0x0f;
    if (dl != 0)
        goto loc_1c089;
    sub_1fb58();
    sub_1fb37();
loc_1c089: // 1b0c:0fc9
    dl = memoryAGet(ds, si + 14);
    dl &= 0x0f;
    if (dl != 0)
        goto loc_1c09b;
    if (bx == 0x001a)
        goto loc_1c09b;
    bx++;
    sub_1fb58();
    bx--;
loc_1c09b: // 1b0c:0fdb
    bx++;
    bx++;
    si++;
    if (--cx)
        goto loc_1c074;
    ax++;
    cx = pop();
    if (--cx)
        goto loc_1c06d;
}
void sub_1c0a5() // 1b0c:0fe5
{
    memoryASet(ds, 0x0498, 0x00);
    si = 0x0589;
    cx = 0x0012;
    dx = 0x000a;
loc_1c0b3: // 1b0c:0ff3
    push(cx);
    cx = 0x000d;
    di = 0x0008;
loc_1c0ba: // 1b0c:0ffa
    push(cx);
    bl = memoryAGet(ds, si);
    bl &= 0x0f;
    if (bl == 0)
        goto loc_1c0de;
    if (bl < 0x03)
        goto loc_1c0cb;
    memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) + 1);
loc_1c0cb: // 1b0c:100b
    bh = 0;
    bl += 0x0a;
    cx = di;
    push(di);
    push(si);
    push(dx);
    sub_1fb4c();
    sub_1fb37();
    dx = pop();
    si = pop();
    di = pop();
loc_1c0de: // 1b0c:101e
    si++;
    cx = pop();
    di += 0x0010;
    if (--cx)
        goto loc_1c0ba;
    cx = pop();
    dx += 0x0007;
    if (--cx)
        goto loc_1c0b3;
    if (memoryAGet(ds, 0x0498) != cl)
        return;
    memoryASet(ds, 0x0498, 0x01);
}
void sub_1c0f7() // 1b0c:1037
{
    memoryASet(ds, 0x00c6, 0x00);
    si = 0x0589;
    cx = 0x0012;
    dx = 0x000a;
loc_1c105: // 1b0c:1045
    push(cx);
    cx = 0x000d;
    di = 0x0008;
loc_1c10c: // 1b0c:104c
    push(cx);
    bl = memoryAGet(ds, si);
    bl &= 0x0f;
    if (bl == 0)
        goto loc_1c154;
    bh = 0;
    bl += 0x0a;
    cx = di;
    push(di);
    push(si);
    push(dx);
    sub_1fb4c();
    sub_1fb37();
    dx = pop();
    si = pop();
    di = pop();
    if (!(memoryAGet(ds, si) & 0x10))
        goto loc_1c13a;
    cx = di;
    push(di);
    push(si);
    push(dx);
    bx = 0x00fb;
    sub_1fb4c();
    dx = pop();
    si = pop();
    di = pop();
loc_1c13a: // 1b0c:107a
    if (!(memoryAGet(ds, si) & 0x20))
        goto loc_1c154;
    cx = di;
    push(di);
    push(si);
    push(dx);
    memoryASet(ds, 0x00c6, memoryAGet(ds, 0x00c6) + 1);
    cx += 0x0008;
    bx = 0x00fa;
    sub_1fb4c();
    dx = pop();
    si = pop();
    di = pop();
loc_1c154: // 1b0c:1094
    si++;
    cx = pop();
    di += 0x0010;
    if (--cx)
        goto loc_1c10c;
    cx = pop();
    dx += 0x0007;
    if (--cx)
        goto loc_1c105;
}
void sub_1c178() // 1b0c:10b8
{
    push(bx);
    push(cx);
    al = memoryAGet(ds, 0x049a);
    bx = 0x111a;
    cx = 0x117d;
    if (al & 0x02)
        goto loc_1c1a1;
    bx = 0x112c;
    cx = 0x116e;
    if (al & 0x04)
        goto loc_1c1a1;
    bx = 0x1162;
    cx = 0x1178;
    if (al & 0x10)
        goto loc_1c1a1;
    bx = 0x1135;
    cx = 0x1173;
loc_1c1a1: // 1b0c:10e1
    memoryASet16(ds, 0x47e9, bx);
    memoryASet16(ds, 0x47eb, cx);
    cx = pop();
    bx = pop();
}
void sub_1c1ac() // 1b0c:10ec
{
    sub_1c46f();
    callIndirect(cs, memoryAGet16(ds, 0x47e9));
    if (!(memoryAGet(ds, 0x049a) & 0x80))
        goto loc_1c212;
    if (!cl)
        goto loc_1c1c5;
    memoryASet(ds, 0x0283, 0x01);
    goto loc_1c1cb;
loc_1c1c5: // 1b0c:1105
    memoryASet16(ds, 0x027e, memoryAGet16(ds, 0x027e) - 1);
    if (memoryAGet16(ds, 0x027e) != 0)
        goto loc_1c1d5;
loc_1c1cb: // 1b0c:110b
    memoryASet(ds, 0x0497, 0x01);
    memoryASet(ds, 0x0a4c, 0x02);
loc_1c1d5: // 1b0c:1115
    sub_1dc70();
    goto loc_1c1ff;
    //   gap of 37 bytes
loc_1c1ff: // 1b0c:113f
    if ((short)bx < (short)0x0008)
        goto loc_1c214;
    dl = memoryAGet(ds, 0x48d1);
    dh = 0;
    dx += bx;
    if (dx > 0x00d1)
        goto loc_1c219;
loc_1c212: // 1b0c:1152
    flags.carry = false;
    return;
loc_1c214: // 1b0c:1154
    bx = 0x0008;
    flags.carry = false;
    return;
loc_1c219: // 1b0c:1159
    bx = 0x00d1;
    bl -= memoryAGet(ds, 0x48d1);
    flags.carry = true;
}
void sub_1c1f5() // 1b0c:1135
{
    sub_1c592();
    al = memoryAGet(ds, 0x48d8);
    ah = 0;
    bx += ax;
    if ((short)bx < (short)0x0008)
        goto loc_1c214;
    dl = memoryAGet(ds, 0x48d1);
    dh = 0;
    dx += bx;
    if (dx > 0x00d1)
        goto loc_1c219;
    flags.carry = false;
    return;
loc_1c214: // 1b0c:1154
    bx = 0x0008;
    flags.carry = false;
    return;
loc_1c219: // 1b0c:1159
    bx = 0x00d1;
    bl -= memoryAGet(ds, 0x48d1);
    flags.carry = true;
}
void sub_1c227() // 1b0c:1167
{
    sub_1c46f();
    stop(/*2*/); // 1b0c:116a jmp word ptr [0x47eb] - jump Indirect memoryAGet16(ds, 0x47eb)
}
void sub_1c363() // 1b0c:12a3
{
    push(es);
    ax = 0x0000;
    es = ax;
    ax = memoryAGet16(cs, 0x325d);
    mul(memoryAGet16(ds, 0x595e));
    flags.carry = (memoryAGet16(es, 0x046c) + dx) >= 0x10000;
    memoryASet16(es, 0x046c, memoryAGet16(es, 0x046c) + dx);
    if (!flags.carry)
        goto loc_1c37d;
    memoryASet16(es, 0x046e, memoryAGet16(es, 0x046e) + 1);
loc_1c37d: // 1b0c:12bd
    ax = memoryAGet16(cs, 0x325f);
    mul(memoryAGet16(ds, 0x595e));
    memoryASet16(es, 0x046e, memoryAGet16(es, 0x046e) + dx);
    es = pop();
}
void sub_1c38c() // 1b0c:12cc
{
    push(ds);
    ax = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x480b, bx);
    memoryASet16(ds, 0x480d, es);
    ax = cs;
    ds = ax;
    dx = 0x1309;
    ax = 0x2509;
    interrupt(0x21);
    ds = pop();
}
void sub_1c3a8() // 1b0c:12e8
{
    ax = memoryAGet16(ds, 0x480b);
    ax |= memoryAGet16(ds, 0x480d);
    if (!ax)
        return;
    push(ds);
    dx = memoryAGet16(ds, 0x480b);
    ds = memoryAGet16(ds, 0x480d);
    ax = 0x2509;
    interrupt(0x21);
    ds = pop();
    ax = 0;
    memoryASet16(ds, 0x480b, ax);
    memoryASet16(ds, 0x480d, ax);
}
void sub_1c3fa() // 1b0c:133a
{
    if (memoryAGet16(ds, 0x47e9) != 0x111a)
        return;
    cl = memoryAGet(ds, 0x48d8);
    ch = 0;
    cx <<= 1;
    ax = 0x0004;
    dx = 0x0001;
    interrupt(0x33);
}
void sub_1c413() // 1b0c:1353
{
loc_1c413: // 1b0c:1353
    al = memoryAGet(cs, 0x1339);
    if (!al)
        goto loc_1c413;
    bx = 0;
    memoryASet(cs, 0x1339, bl);
    cx = 0x0022;
loc_1c425: // 1b0c:1365
    if (memoryAGet(ds, bx + 18490) == al)
        goto loc_1c430;
    bx++;
    if (--cx)
        goto loc_1c425;
    goto loc_1c413;
loc_1c430: // 1b0c:1370
    al = memoryAGet(ds, bx + 18524);
}
void sub_1c46f() // 1b0c:13af
{
    goto loc_1c46f;
loc_1c44b: // 1b0c:138b
    memoryASet(cs, 0x1339, 0x00);
    memoryASet(cs, 0x325b, memoryAGet(cs, 0x325b) ^ al);
    if (memoryAGet(cs, 0x325b) & al)
        goto loc_1c460;
    goto loc_1f2dc;
loc_1c460: // 1b0c:13a0
    goto loc_1f2bc;
    //   gap of 12 bytes
loc_1c46f: // 1b0c:13af
    ah = memoryAGet(cs, 0x1339);
    if (ah == 0x3b)
        goto loc_1c4b3;
    if (ah == 0x43)
        goto loc_1c49c;
    al = 0x01;
    if (ah == 0x3c)
        goto loc_1c44b;
    al++;
    if (ah == 0x3d)
        goto loc_1c44b;
    if (ah == 0x44)
        goto loc_1c4da;
    if (ah == 0x30)
        goto loc_1c4a2;
    if (ah == 0x19)
        goto loc_1c500;
loc_1c49b: // 1b0c:13db
    return;
loc_1c49c: // 1b0c:13dc
    memoryASet(ds, 0x00c7, memoryAGet(ds, 0x00c7) ^ 0xff);
    return;
loc_1c4a2: // 1b0c:13e2
    if (memoryAGet(ds, 0x47e0) == 0x00)
        goto loc_1c49b;
    if (memoryAGet(ds, 0x47e1) == 0x00)
        goto loc_1c49b;
    goto loc_1dbc3;
loc_1c4b3: // 1b0c:13f3
    if (memoryAGet(ds, 0x47e1) == 0x00)
        goto loc_1c49b;
    memoryASet(cs, 0x1339, 0x00);
    bl = memoryAGet(cs, 0x325b);
    memoryASet(cs, 0x325b, memoryAGet(cs, 0x325b) & 0xfc);
    sub_1c510();
    memoryASet(cs, 0x325b, bl);
    memoryASet(cs, 0x1339, 0x00);
loc_1c4d9: // 1b0c:1419
    return;
loc_1c4da: // 1b0c:141a
    sub_1c3a8();
    sub_1f042();
    sub_1b45a();
    al = 0x03;
    sub_1f2dc();
    sub_1c363();
    sub_1f8c5();
    ax = 0x1118;
    ds = ax;
    dx = memoryAGet16(ds, 0x480f);
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
loc_1c500: // 1b0c:1440
    if (memoryAGet(ds, 0x47e0) == 0x00)
        goto loc_1c4d9;
    memoryASet(cs, 0x1339, 0x00);
    goto loc_1dbe2;
    //   gap of 5811 bytes
loc_1dbc3: // 1b0c:2b03
    sub_1dca8();
    memoryASet(ds, 0x48e0, 0x01);
    memoryASet(ds, 0x47e1, 0x00);
    bx = 0x590e;
    memoryASet16(ds, bx + 5, 0x7ffe);
    sub_1c939();
    return;
    //   gap of 6 bytes
loc_1dbe2: // 1b0c:2b22
    bx = 0x020b;
    sub_1f0d2();
    memoryASet(ds, 0x0497, memoryAGet(ds, 0x0497) + 1);
    sub_1d6f2();
    cl = memoryAGet(ds, 0x0497);
    if (cl > 0x06)
        goto loc_1dc19;
    push(si);
    ch = 0;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx -= 0x0016;
    bx = 0x00c8;
    dx = 0x00c3;
    push(bx);
    push(cx);
    push(dx);
    sub_1fb4c();
    dx = pop();
    cx = pop();
    bx = pop();
    sub_1fb46();
    si = pop();
loc_1dc19: // 1b0c:2b59
    return;
    //   gap of 5794 bytes
loc_1f2bc: // 1b0c:41fc
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        goto loc_1f2db;
    cl = al;
    bx = 0x5964;
    ax = 0;
loc_1f2cb: // 1b0c:420b
    if (!(memoryAGet(ds, bx) & cl))
        goto loc_1f2d4;
    push(cs);
    cs = 0x19ee;
    sub_1b0b6();
    assert(cs == 0x1b0c);
loc_1f2d4: // 1b0c:4214
    bx++;
    ax++;
    if (ax < 0x0012)
        goto loc_1f2cb;
loc_1f2db: // 1b0c:421b
    return;
loc_1f2dc: // 1b0c:421c
    stop(/*2*/); // 1b0c:421c jmp word ptr cs:[0x3263] - jump Indirect memoryAGet16(cs, 0x3263)
}
void sub_1c510() // 1b0c:1450
{
    push(bx);
    sub_1f2dc();
    sub_1c564();
loc_1c517: // 1b0c:1457
    ah = memoryAGet(cs, 0x1339);
    if (ah == 0x3b)
        goto loc_1c54d;
    if (memoryAGet(cs, 0x3259) < 0x3c)
        goto loc_1c517;
    memoryASet(cs, 0x3259, 0x00);
    sub_1c534();
    goto loc_1c517;
    //   gap of 25 bytes
loc_1c54d: // 1b0c:148d
    sub_1f2bc();
    sub_1c57c();
    sub_1bf26();
    memoryASet(cs, 0x3259, 0x01);
    memoryASet(cs, 0x325a, 0x01);
    bx = pop();
}
void sub_1c534() // 1b0c:1474
{
    cl ^= 0x01;
    push(cx);
    si = 0x487e;
    if (cl)
        goto loc_1c540;
    si = 0x4886;
loc_1c540: // 1b0c:1480
    cx = 0x0064;
    bx = 0x00f0;
    al = 0x0f;
    sub_1fb75();
    cx = pop();
}
void sub_1c564() // 1b0c:14a4
{
    if (memoryAGet16(ds, 0x47e9) != 0x111a)
        goto loc_1c579;
    ax = 0x0003;
    interrupt(0x33);
    memoryASet16(ds, 0x4836, cx);
    memoryASet16(ds, 0x4838, dx);
loc_1c579: // 1b0c:14b9
    cl = 0;
}
void sub_1c57c() // 1b0c:14bc
{
    if (memoryAGet16(ds, 0x47e9) != 0x111a)
        return;
    cx = memoryAGet16(ds, 0x4836);
    dx = memoryAGet16(ds, 0x4838);
    ax = 0x0004;
    interrupt(0x33);
}
void sub_1c592() // 1b0c:14d2
{
    ah = memoryAGet(cs, 0x1339);
    bx = 0xfffd;
    if (ah == memoryAGet(cs, 0x150a))
        goto loc_1c5b5;
    bx = -bx;
    if (ah == memoryAGet(cs, 0x150b))
        goto loc_1c5b5;
    bx = 0;
    cl = 0x01;
    if (ah == memoryAGet(cs, 0x150c))
        goto loc_1c5c6;
loc_1c5b5: // 1b0c:14f5
    cl = 0;
    al = memoryAGet(ds, 0x5870);
    al--;
    if (al == 0)
        goto loc_1c5c6;
    bx += bx;
    al--;
    if (al == 0)
        goto loc_1c5c6;
    bx += bx;
loc_1c5c6: // 1b0c:1506
    sub_1c601();
}
void sub_1c601() // 1b0c:1541
{
    al = memoryAGet(ds, 0x5870);
    if (memoryAGet(ds, 0x4808) == 0x00)
        goto loc_1c618;
    tl = memoryAGet(ds, 0x4809);
    memoryASet(ds, 0x4809, memoryAGet(ds, 0x4809) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1c625;
    memoryASet(ds, 0x4809, 0x0a);
    goto loc_1c63e;
loc_1c618: // 1b0c:1558
    if ((char)memoryAGet(ds, 0x4809) <= (char)0x00)
        goto loc_1c625;
    memoryASet(ds, 0x4809, memoryAGet(ds, 0x4809) - al);
    goto loc_1c632;
loc_1c625: // 1b0c:1565
    if (memoryAGet(ds, 0x480a) == cl)
        goto loc_1c636;
    if (memoryAGet(ds, 0x480a) == 0x00)
        goto loc_1c639;
loc_1c632: // 1b0c:1572
    memoryASet(ds, 0x480a, cl);
loc_1c636: // 1b0c:1576
    cl = 0;
    return;
loc_1c639: // 1b0c:1579
    memoryASet(ds, 0x4809, 0x0f);
loc_1c63e: // 1b0c:157e
    memoryASet(ds, 0x480a, cl);
}
void sub_1c750() // 1b0c:1690
{
    goto loc_1c750;
loc_1b0dd: // 1b0c:001d
    sub_1ba4f();
    al = memoryAGet(ds, 0x00c7);
    if (al)
        goto loc_1b10f;
    sub_1baf1();
    sub_1bb74();
    sub_1b970();
    sub_1bcf0();
    sub_1b1aa();
    if (!(ah & 0x01))
        goto loc_1b100;
    bl = 0x31;
    sub_1b1d9();
loc_1b100: // 1b0c:0040
    if (!(ah & 0x02))
        goto loc_1b10a;
    bl = 0x32;
    sub_1b1d9();
loc_1b10a: // 1b0c:004a
    sub_1b29e();
    goto loc_1b0dd;
loc_1b10f: // 1b0c:004f
    al = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0a4d, 0x01);
loc_1b11c: // 1b0c:005c
    sub_1b4f0();
    goto loc_1b0dd;
    //   gap of 5679 bytes
loc_1c750: // 1b0c:1690
    ch = 0;
loc_1c752: // 1b0c:1692
    sync();
    dh = memoryAGet(cs, 0x325a);
//    if (!dh)
//        goto loc_1c752;
    if (dh <= 0x08)
        goto loc_1c762;
    dh = 0x08;
loc_1c762: // 1b0c:16a2
    memoryASet(cs, 0x325a, ch);
    memoryASet(ds, 0x48f0, dh);
    cl = dh;
loc_1c76d: // 1b0c:16ad
    push(cx);
    si = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1c775: // 1b0c:16b5
    push(cx);
    bl = memoryAGet(ds, si);
    bh = 0;
    callIndirect(cs, memoryAGet16(ds, bx + 18827)); // 1118:498b, 22 ents
    si += 0x000b;
    cx = pop();
    if (--cx)
        goto loc_1c775;
    cx = pop();
    if (--cx)
        goto loc_1c76d;
    si = 0x4d69;
loc_1c78a: // 1b0c:16ca
    sub_1c97a();
loc_1c78d: // 1b0c:16cd
    bl = memoryAGet(ds, si);
    if (bl == 0xff)
        goto loc_1c7b3;
    bh = 0;
    callIndirect(cs, memoryAGet16(ds, bx + 18875));
    si += 0x000b;
    if (memoryAGet(cs, 0x3259) == 0x00)
        goto loc_1c78d;
    memoryASet(ds, 0x48e2, memoryAGet(ds, 0x48e2) ^ 0x01);
    if (!memoryAGet(ds, 0x48e2))
        goto loc_1c78d;
    memoryASet(cs, 0x3259, memoryAGet(cs, 0x3259) - 1);
    goto loc_1c78a;
loc_1c7b3: // 1b0c:16f3
    sub_1fb2b();
    if (memoryAGet(ds, 0x48e5) == 0x00)
        goto loc_1c7ca;
    al = memoryAGet(ds, 0x48e5);
    memoryASet(ds, 0x48e5, 0x00);
    al--;
    sub_1fb9b();
loc_1c7ca: // 1b0c:170a
    memoryASet(ds, 0x48de, memoryAGet(ds, 0x48de) - 1);
    if (memoryAGet(ds, 0x48de) != 0)
        goto loc_1c7d5;
    memoryASet(ds, 0x48da, 0x00);
loc_1c7d5: // 1b0c:1715
    if (memoryAGet(ds, 0x0a4c) != 0x00)
        goto loc_1c7ec;
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1fb85();
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1c9b6();
loc_1c7ec: // 1b0c:172c
    sub_1fb42();
    sub_1c957();
    sub_1c91e();
    if (memoryAGet(ds, 0x00c7) == 0xff)
        goto loc_1c7fd;
    return;
loc_1c7fd: // 1b0c:173d
    ax = pop();
    ax = pop();
    ax = pop();
    if (!(memoryAGet(ds, 0x049a) & 0x80))
        goto loc_1c819;
    ax = pop();
    memoryASet(ds, 0x0a4a, al);
    memoryASet(ds, 0x049a, al);
    ax = pop();
    memoryASet(ds, 0x0284, al);
    al = memoryAGet(ds, 0x0282);
    memoryASet(cs, 0x325b, al);
loc_1c819: // 1b0c:1759
    dl = 0;
    memoryASet(ds, 0x47e1, dl);
    sub_1fb90();
    sub_1fb2b();
    sub_1fb42();
    sub_1fb2b();
    sub_1fb42();
    goto loc_1b11c;
}
void sub_1c78d() // 1b0c:16cd
{
    goto loc_1c78d;
loc_1b0dd: // 1b0c:001d
    sub_1ba4f();
    al = memoryAGet(ds, 0x00c7);
    if (al)
        goto loc_1b10f;
    sub_1baf1();
    sub_1bb74();
    sub_1b970();
    sub_1bcf0();
    sub_1b1aa();
    if (!(ah & 0x01))
        goto loc_1b100;
    bl = 0x31;
    sub_1b1d9();
loc_1b100: // 1b0c:0040
    if (!(ah & 0x02))
        goto loc_1b10a;
    bl = 0x32;
    sub_1b1d9();
loc_1b10a: // 1b0c:004a
    sub_1b29e();
    goto loc_1b0dd;
loc_1b10f: // 1b0c:004f
    al = 0;
    memoryASet(ds, 0x0493, al);
    memoryASet(ds, 0x0494, al);
    memoryASet(ds, 0x0a4d, 0x01);
loc_1b11c: // 1b0c:005c
    sub_1b4f0();
    goto loc_1b0dd;
    //   gap of 5737 bytes
loc_1c78a: // 1b0c:16ca
    sub_1c97a();
loc_1c78d: // 1b0c:16cd
    bl = memoryAGet(ds, si);
    if (bl == 0xff)
        goto loc_1c7b3;
    bh = 0;
    callIndirect(cs, memoryAGet16(ds, bx + 18875));
    si += 0x000b;
    if (memoryAGet(cs, 0x3259) == 0x00)
        goto loc_1c78d;
    memoryASet(ds, 0x48e2, memoryAGet(ds, 0x48e2) ^ 0x01);
    if (!memoryAGet(ds, 0x48e2))
        goto loc_1c78d;
    memoryASet(cs, 0x3259, memoryAGet(cs, 0x3259) - 1);
    goto loc_1c78a;
loc_1c7b3: // 1b0c:16f3
    sub_1fb2b();
    if (memoryAGet(ds, 0x48e5) == 0x00)
        goto loc_1c7ca;
    al = memoryAGet(ds, 0x48e5);
    memoryASet(ds, 0x48e5, 0x00);
    al--;
    sub_1fb9b();
loc_1c7ca: // 1b0c:170a
    memoryASet(ds, 0x48de, memoryAGet(ds, 0x48de) - 1);
    if (memoryAGet(ds, 0x48de) != 0)
        goto loc_1c7d5;
    memoryASet(ds, 0x48da, 0x00);
loc_1c7d5: // 1b0c:1715
    if (memoryAGet(ds, 0x0a4c) != 0x00)
        goto loc_1c7ec;
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1fb85();
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1c9b6();
loc_1c7ec: // 1b0c:172c
    sub_1fb42();
    sub_1c957();
    sub_1c91e();
    if (memoryAGet(ds, 0x00c7) == 0xff)
        goto loc_1c7fd;
    return;
loc_1c7fd: // 1b0c:173d
    ax = pop();
    ax = pop();
    ax = pop();
    if (!(memoryAGet(ds, 0x049a) & 0x80))
        goto loc_1c819;
    ax = pop();
    memoryASet(ds, 0x0a4a, al);
    memoryASet(ds, 0x049a, al);
    ax = pop();
    memoryASet(ds, 0x0284, al);
    al = memoryAGet(ds, 0x0282);
    memoryASet(cs, 0x325b, al);
loc_1c819: // 1b0c:1759
    dl = 0;
    memoryASet(ds, 0x47e1, dl);
    sub_1fb90();
    sub_1fb2b();
    sub_1fb42();
    sub_1fb2b();
    sub_1fb42();
    goto loc_1b11c;
}
void sub_1c7fc() // 1b0c:173c
{
}
void sub_1c831() // 1b0c:1771
{
    sub_1ca4a();
    sub_1ce96();
    if (memoryAGet(ds, si) == 0x00)
        return;
    sub_1ca4a();
    sub_1ce96();
}
void sub_1c843() // 1b0c:1783
{
    sub_1ca4a();
    goto loc_1ce65;
    //   gap of 1564 bytes
loc_1ce65: // 1b0c:1da5
    ah = memoryAGet(ds, si + 4);
    if (ah < 0xb0)
        return;
    if (ah >= 0xb6)
        goto loc_1ce92;
    al = memoryAGet(ds, si + 2);
    bl = memoryAGet(ds, 0x48d8);
    flags.carry = bl < 0x10;
    bl -= 0x10;
    if (!flags.carry)
        goto loc_1ce80;
    bl = 0x04;
loc_1ce80: // 1b0c:1dc0
    if (al < bl)
        return;
    bl += 0x31;
    if (al > bl)
        return;
    sub_1e01c();
    cx = pop();
    cx = pop();
    cx = pop();
    return;
loc_1ce92: // 1b0c:1dd2
    memoryASet(ds, si, 0x00);
}
void sub_1c849() // 1b0c:1789
{
    sub_1ca54();
    goto loc_1d2a2;
    //   gap of 2643 bytes
loc_1d2a2: // 1b0c:21e2
    sub_1d2c8();
    sub_1d2e9();
    ah = memoryAGet(ds, si + 2);
    if (ah < 0x08)
        goto loc_1d2bf;
    if (ah > 0xc8)
        goto loc_1d2b6;
    return;
loc_1d2b6: // 1b0c:21f6
    memoryASet(ds, si + 6, 0xff);
    memoryASet(ds, si + 2, 0xc8);
    return;
loc_1d2bf: // 1b0c:21ff
    memoryASet(ds, si + 6, 0x01);
    memoryASet(ds, si + 2, 0x08);
}
void sub_1c84f() // 1b0c:178f
{
    sub_1ca4d();
    goto loc_1d40d;
    //   gap of 3000 bytes
loc_1d40d: // 1b0c:234d
    al = memoryAGet(ds, si + 4);
    if (al < 0xb4)
        return;
    if (al < 0xba)
        goto loc_1d41c;
    if (al > 0xc1)
        goto loc_1d436;
loc_1d41c: // 1b0c:235c
    al = memoryAGet(ds, si + 2);
    al += 0x0e;
    if (al < memoryAGet(ds, 0x48d8))
        goto loc_1d443;
    al = memoryAGet(ds, 0x48d8);
    al += memoryAGet(ds, 0x48d1);
    if (al < memoryAGet(ds, si + 2))
        return;
    sub_1da8d();
loc_1d436: // 1b0c:2376
    memoryASet(ds, 0x48eb, memoryAGet(ds, 0x48eb) - 1);
    memoryASet(ds, si, 0x00);
    bl = memoryAGet(ds, si + 9);
    bl &= 0xf8;
loc_1d443: // 1b0c:2383
    di = 0x48f2;
    cx = 0x0004;
loc_1d449: // 1b0c:2389
    if (memoryAGet(ds, di) == bl)
        goto loc_1d450;
    di++;
    if (--cx)
        goto loc_1d449;
loc_1d450: // 1b0c:2390
    memoryASet(ds, di, 0x00);
}
void sub_1c855() // 1b0c:1795
{
    sub_1ca5b();
    goto loc_1d326;
    //   gap of 2763 bytes
loc_1d326: // 1b0c:2266
    sub_1d330();
    sub_1d37e();
    sub_1d3a1();
}
void sub_1c85b() // 1b0c:179b
{
    sub_1ca4d();
    goto loc_1d1fb;
    //   gap of 2255 bytes
loc_1d130: // 1b0c:2070
    if (al >= 0x04)
        goto loc_1d141;
    sub_1dd10();
    if (al == 0x01)
        goto loc_1d15e;
    memoryASet(ds, bx + 1183, memoryAGet(ds, bx + 1183) - 1);
    if (memoryAGet(ds, bx + 1183) != 0)
        goto loc_1d15e;
loc_1d141: // 1b0c:2081
    push(ax);
    sub_1d94d();
    ax = pop();
    sub_1d250();
    ch &= 0xf0;
    memoryASet(ds, bx + 1417, ch);
    push(bx);
    bx = 0x0202;
    sub_1f0d2();
    bx = pop();
    sub_1d6db();
    sub_1d6f6();
loc_1d15e: // 1b0c:209e
    return;
    //   gap of 156 bytes
loc_1d1fb: // 1b0c:213b
    bl = memoryAGet(ds, si + 4);
    if (bl < 0x0a)
        goto loc_1d224;
    bh = 0;
    al = memoryAGet(ds, si + 2);
    sub_1d484();
    if (flags.carry)
        goto loc_1d217;
    al = memoryAGet(ds, bx + 1417);
    ch = al;
    al &= 0x0f;
    if (al != 0)
        goto loc_1d21e;
loc_1d217: // 1b0c:2157
    sub_1d15f();
    sub_1d228();
    return;
loc_1d21e: // 1b0c:215e
    memoryASet(ds, si, 0x00);
    goto loc_1d130;
loc_1d224: // 1b0c:2164
    memoryASet(ds, si, 0x00);
}
void sub_1c861() // 1b0c:17a1
{
    push(si);
    if (memoryAGet(ds, 0x0493) != 0x21)
        goto loc_1c86f;
    bx = 0x010f;
    sub_1f0d2();
loc_1c86f: // 1b0c:17af
    memoryASet(ds, si, 0x00);
    bx = 0x010e;
    sub_1f0d2();
    sub_1e093();
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        goto loc_1c889;
    cx = 0x008c;
    sub_1e307();
loc_1c889: // 1b0c:17c9
    sub_1dd5e();
    sub_1ddb5();
    sub_1dd99();
    sub_1ddec();
    sub_1de31();
    cx = 0x0014;
    sub_1e307();
    sub_1dd5e();
    cx = 0x0014;
    sub_1e307();
    sub_1dd99();
    sub_1e105();
    ch = 0;
    memoryASet(cs, 0x3259, ch);
    memoryASet(cs, 0x325a, ch);
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        goto loc_1c8c7;
    cx = 0x001e;
    sub_1e307();
loc_1c8c7: // 1b0c:1807
    sub_1c3fa();
    memoryASet(ds, 0x47e1, 0x01);
    if (memoryAGet(ds, 0x0493) != 0x21)
        goto loc_1c8dc;
    bx = 0x010a;
    sub_1f0d2();
loc_1c8dc: // 1b0c:181c
    si = pop();
}
void sub_1c8de() // 1b0c:181e
{
    ax = 0;
    memoryASet16(ds, 0x48e3, 0x0001);
    memoryASet(ds, 0x4d69, al);
    memoryASet(ds, 0x4d74, 0xff);
    memoryASet(ds, 0x4988, al);
    memoryASet16(ds, 0x4989, 0x49f9);
}
void sub_1c8f8() // 1b0c:1838
{
    di = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1c8ff: // 1b0c:183f
    al = memoryAGet(ds, di);
    if (!al)
        goto loc_1c912;
    di += 0x000b;
    if (--cx)
        goto loc_1c8ff;
    memoryASet16(ds, 0x48e3, memoryAGet16(ds, 0x48e3) + 1);
    memoryASet(ds, di + 11, 0xff);
loc_1c912: // 1b0c:1852
    push(es);
    ax = ds;
    es = ax;
    cx = 0x000b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_1c912() // 1b0c:1852
{
    push(es);
    ax = ds;
    es = ax;
    cx = 0x000b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_1c91e() // 1b0c:185e
{
    ch = 0;
    cl = memoryAGet(ds, 0x4988);
    if (cx == 0)
        return;
    memoryASet(ds, 0x4988, ch);
    si = 0x49f9;
    memoryASet16(ds, 0x4989, si);
loc_1c931: // 1b0c:1871
    push(cx);
    sub_1c8f8();
    cx = pop();
    if (--cx)
        goto loc_1c931;
}
void sub_1c939() // 1b0c:1879
{
    push(si);
    si = bx;
    di = memoryAGet16(ds, 0x4989);
    bx = di;
    push(es);
    ax = ds;
    es = ax;
    cx = 0x000b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
    memoryASet16(ds, 0x4989, di);
    memoryASet(ds, 0x4988, memoryAGet(ds, 0x4988) + 1);
    si = pop();
}
void sub_1c957() // 1b0c:1897
{
    cl = memoryAGet(ds, 0x4985);
    ch = 0;
    if (cx == 0)
        return;
    si = 0x5291;
    memoryASet16(ds, 0x4986, si);
loc_1c966: // 1b0c:18a6
    push(cx);
    bl = memoryAGet(ds, si);
    bh = ch;
    callIndirect(cs, memoryAGet16(ds, bx + 18923));
    si += 0x0003;
    cx = pop();
    if (--cx)
        goto loc_1c966;
    memoryASet(ds, 0x4985, ch);
}
void sub_1c97a() // 1b0c:18ba
{
    if (memoryAGet(ds, 0x0a4c) != 0x00)
        return;
    push(si);
    push(cx);
    memoryASet(ds, 0x586f, memoryAGet(ds, 0x586f) - 1);
    if (memoryAGet(ds, 0x586f) != 0)
        goto loc_1c9b3;
    al = memoryAGet(ds, 0x5870);
    memoryASet(ds, 0x586f, al);
    si = 0x4d5e;
    if (memoryAGet(ds, si) != 0x06)
        goto loc_1c9ad;
    cx = memoryAGet16(ds, 0x586d);
loc_1c99b: // 1b0c:18db
    push(cx);
    sub_1ca4a();
    sub_1ce96();
    cx = pop();
    if (memoryAGet(ds, si) == 0x00)
        goto loc_1c9ad;
    if (--cx)
        goto loc_1c99b;
    sub_1caa4();
loc_1c9ad: // 1b0c:18ed
    sub_1c9c5();
    sub_1ccfc();
loc_1c9b3: // 1b0c:18f3
    cx = pop();
    si = pop();
}
void sub_1c9b6() // 1b0c:18f6
{
    si = 0x4d5e;
    if (memoryAGet(ds, si) != 0x06)
        goto loc_1c9c1;
    sub_1caa4();
loc_1c9c1: // 1b0c:1901
    sub_1ccfc();
}
void sub_1c9c5() // 1b0c:1905
{
    if (memoryAGet(ds, 0x48df) == 0x01)
        goto loc_1ca49;
    bl = memoryAGet(ds, 0x48d8);
    memoryASet(ds, 0x48d9, bl);
    if (memoryAGet(ds, 0x48e0) != 0x02)
        goto loc_1c9e3;
    cl = 0;
    bl += memoryAGet(ds, 0x48dd);
    goto loc_1c9e6;
loc_1c9e3: // 1b0c:1923
    sub_1c1ac();
loc_1c9e6: // 1b0c:1926
    memoryASet(ds, 0x48d8, bl);
    if (memoryAGet(ds, 0x48d9) == bl)
        goto loc_1c9f5;
    memoryASet(ds, 0x48d6, 0x00);
loc_1c9f5: // 1b0c:1935
    memoryASet(ds, 0x48da, memoryAGet(ds, 0x48da) | cl);
    if (!cl)
        goto loc_1ca02;
    memoryASet(ds, 0x48de, 0x04);
loc_1ca02: // 1b0c:1942
    if (memoryAGet(ds, 0x48cf) != 0x0f)
        goto loc_1ca10;
    if (!cl)
        goto loc_1ca10;
    sub_1df78();
loc_1ca10: // 1b0c:1950
    if (memoryAGet(ds, 0x48e0) == 0x00)
        goto loc_1ca49;
    if (bl > 0x09)
        goto loc_1ca28;
    memoryASet(ds, 0x0494, 0x00);
    memoryASet(ds, 0x48dd, 0xff);
    goto loc_1ca3b;
loc_1ca28: // 1b0c:1968
    bl += memoryAGet(ds, 0x48d1);
    if (bl < 0xd0)
        goto loc_1ca49;
    memoryASet(ds, 0x48dd, 0x01);
    memoryASet(ds, 0x0494, 0x01);
loc_1ca3b: // 1b0c:197b
    memoryASet(ds, 0x48df, 0x01);
    ax = 0x1000;
    sub_1b130();
    goto loc_1e10f;
loc_1ca49: // 1b0c:1989
    return;
    //   gap of 5829 bytes
loc_1e10f: // 1b0c:304f
    ax = pop();
    cx = pop();
    si = pop();
    sub_1c78d();
    sub_1d7c8();
    sub_1e12b();
    sub_1c750();
    sub_1c750();
    sub_1e14e();
    memoryASet(ds, 0x48df, 0x00);
    ax = pop();
}
void sub_1ca4a() // 1b0c:198a
{
    sub_1ca54();
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + ax);
}
void sub_1ca4d() // 1b0c:198d
{
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + ax);
}
void sub_1ca54() // 1b0c:1994
{
    ax = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) + ax);
}
void sub_1ca5b() // 1b0c:199b
{
    sub_1ca85();
    ax = memoryAGet16(ds, bx + 1);
    dx = memoryAGet16(ds, bx + 3);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) + ax);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + dx);
    memoryASet(ds, si + 6, memoryAGet(ds, si + 6) - 1);
    if (memoryAGet(ds, si + 6) != 0)
        return;
    bx += 0x0005;
    cl++;
    al = memoryAGet(ds, bx);
    if (al)
        goto loc_1ca7e;
    cl = 0x00;
    al = memoryAGet(ds, di);
loc_1ca7e: // 1b0c:19be
    memoryASet(ds, si + 5, cl);
    memoryASet(ds, si + 6, al);
}
void sub_1ca6f() // 1b0c:19af
{
    bx += 0x0005;
    cl++;
    al = memoryAGet(ds, bx);
    if (al)
        goto loc_1ca7e;
    cl = 0x00;
    al = memoryAGet(ds, di);
loc_1ca7e: // 1b0c:19be
    memoryASet(ds, si + 5, cl);
    memoryASet(ds, si + 6, al);
}
void sub_1ca85() // 1b0c:19c5
{
    bh = 0;
    ch = bh;
    ah = bh;
    bl = memoryAGet(ds, si + 7);
    bl <<= 1;
    bx = memoryAGet16(ds, bx + 21737);
    di = bx;
    cl = memoryAGet(ds, si + 5);
    al = cl;
    ax <<= 1;
    ax <<= 1;
    ax += cx;
    bx += ax;
}
void sub_1caa4() // 1b0c:19e4
{
    bl = 0x17;
    if (memoryAGet(ds, 0x48e9) != 0x00)
        goto loc_1caaf;
    bl = 0x16;
loc_1caaf: // 1b0c:19ef
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb90();
    sub_1fb94();
    sub_1fb46();
    si = pop();
}
void sub_1cac7() // 1b0c:1a07
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1caef;
    bl = memoryAGet(ds, si + 9);
    if (bl != 0x03)
        goto loc_1caf0;
    memoryASet(ds, si + 10, 0x01);
    tl = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1caef;
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) - 1);
    if (memoryAGet(ds, si + 1) == 0)
        goto loc_1caec;
    memoryASet(ds, si + 3, 0x5a);
    goto loc_1df11;
loc_1caec: // 1b0c:1a2c
    memoryASet(ds, si + 9, memoryAGet(ds, si + 9) + 1);
loc_1caef: // 1b0c:1a2f
    return;
loc_1caf0: // 1b0c:1a30
    bl++;
    memoryASet(ds, si + 9, bl);
    memoryASet(ds, si + 10, 0x1e);
    if (bl < 0x05)
        goto loc_1cb09;
    al = 0x08;
    al -= bl;
    if (al != 0)
        goto loc_1cb07;
    memoryASet(ds, si, 0x00);
loc_1cb07: // 1b0c:1a47
    tl = bl;
    bl = al;
    al = tl;
loc_1cb09: // 1b0c:1a49
    bh = 0;
    bx += 0x0012;
    sub_1d6c9();
    cx = 0x0068;
    dx = 0x0065;
    push(si);
    sub_1fb52();
    si = pop();
    return;
    //   gap of 5108 bytes
loc_1df11: // 1b0c:2e51
    bx = 0x5944;
    ah = 0;
    al = memoryAGet(ds, 0x48d8);
    cx = 0x0068;
    ax -= cx;
    memoryASet16(ds, bx + 5, ax);
    sub_1c939();
}
void sub_1cb1d() // 1b0c:1a5d
{
    goto loc_1cb1d;
loc_1cb11: // 1b0c:1a51
    cx = 0x0068;
    dx = 0x0065;
    push(si);
    sub_1fb52();
    si = pop();
    return;
loc_1cb1d: // 1b0c:1a5d
    bx = memoryAGet16(ds, si + 1);
    goto loc_1cb11;
}
void sub_1cb22() // 1b0c:1a62
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        return;
    memoryASet(ds, si + 10, 0x0a);
    memoryASet(ds, si + 9, memoryAGet(ds, si + 9) + 1);
    bl = memoryAGet(ds, si + 9);
    if (bl != 0x03)
        goto loc_1cb4d;
    al = memoryAGet(ds, 0x48ec);
    if (al < memoryAGet(ds, 0x48ed))
        goto loc_1cb4a;
    bl += 0x02;
    memoryASet(ds, si + 9, bl);
    goto loc_1cb4d;
loc_1cb4a: // 1b0c:1a8a
    sub_1df25();
loc_1cb4d: // 1b0c:1a8d
    push(bx);
    bx = si;
    sub_1d6c5();
    bx = pop();
    if (bl < 0x04)
        goto loc_1cb6b;
    al = 0x06;
    al -= bl;
    if (al != 0)
        goto loc_1cb69;
    memoryASet(ds, si, 0x00);
    bh = memoryAGet(ds, si + 6);
    memoryASet(ds, 0x4937, memoryAGet(ds, 0x4937) & bh);
loc_1cb69: // 1b0c:1aa9
    bl = al;
loc_1cb6b: // 1b0c:1aab
    bh = 0;
    ch = bh;
    dh = bh;
    bl += 0x18;
    bl += memoryAGet(ds, si + 5);
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb52();
    si = pop();
}
void sub_1cb54() // 1b0c:1a94
{
    if (bl < 0x04)
        goto loc_1cb6b;
    al = 0x06;
    al -= bl;
    if (al != 0)
        goto loc_1cb69;
    memoryASet(ds, si, 0x00);
    bh = memoryAGet(ds, si + 6);
    memoryASet(ds, 0x4937, memoryAGet(ds, 0x4937) & bh);
loc_1cb69: // 1b0c:1aa9
    bl = al;
loc_1cb6b: // 1b0c:1aab
    bh = 0;
    ch = bh;
    dh = bh;
    bl += 0x18;
    bl += memoryAGet(ds, si + 5);
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb52();
    si = pop();
}
void sub_1cb83() // 1b0c:1ac3
{
    push(si);
    si = memoryAGet16(ds, si + 1);
    bl = memoryAGet(ds, si + 9);
    sub_1cb54();
    si = pop();
}
void sub_1cb8f() // 1b0c:1acf
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        return;
    memoryASet(ds, si + 10, 0x0f);
    memoryASet(ds, si + 9, memoryAGet(ds, si + 9) + 1);
    bl = memoryAGet(ds, si + 9);
    if (bl != 0x04)
        goto loc_1cba9;
    sub_1df2b();
loc_1cba9: // 1b0c:1ae9
    if (bl < 0x05)
        goto loc_1cbb9;
    al = 0x08;
    al -= bl;
    if (al != 0)
        goto loc_1cbb7;
    memoryASet(ds, si, 0x00);
loc_1cbb7: // 1b0c:1af7
    tl = bl;
    bl = al;
    al = tl;
loc_1cbb9: // 1b0c:1af9
    bh = 0;
    bx += 0x0006;
    cx = memoryAGet16(ds, si + 1);
    dx = 0x0003;
    push(si);
    push(bx);
    push(cx);
    push(dx);
    sub_1fb4c();
    dx = pop();
    cx = pop();
    bx = pop();
    sub_1fb46();
    si = pop();
}
void sub_1cbd3() // 1b0c:1b13
{
    cl = memoryAGet(ds, si + 9);
    bl = memoryAGet(ds, si + 7);
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1cc24;
    al = memoryAGet(ds, si + 8);
    ah = al;
    al &= 0x0f;
    if (!(ah & 0x20))
        goto loc_1cc05;
    cl++;
    if (cl != al)
        goto loc_1cc1d;
    if (ah & 0x10)
        goto loc_1cbfc;
    cl = 0x00;
    goto loc_1cc1d;
loc_1cbfc: // 1b0c:1b3c
    cl -= 0x02;
    memoryASet(ds, si + 8, memoryAGet(ds, si + 8) ^ 0x20);
    goto loc_1cc1d;
loc_1cc05: // 1b0c:1b45
    cl--;
    if (cl != 0xff)
        goto loc_1cc1d;
    if (ah & 0x10)
        goto loc_1cc17;
    cl = al;
    cl--;
    goto loc_1cc1d;
loc_1cc17: // 1b0c:1b57
    cl = 0x01;
    memoryASet(ds, si + 8, memoryAGet(ds, si + 8) ^ 0x20);
loc_1cc1d: // 1b0c:1b5d
    memoryASet(ds, si + 9, cl);
    memoryASet(ds, si + 10, 0x0a);
loc_1cc24: // 1b0c:1b64
    bh = 0;
    bl = memoryAGet(ds, bx + 18791);
    bl += cl;
    bl += 0x7a;
    goto loc_1cca0;
    //   gap of 111 bytes
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
}
void sub_1cc31() // 1b0c:1b71
{
    bl = memoryAGet(ds, si + 9);
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1cc4e;
    memoryASet(ds, si + 10, 0x06);
    bl++;
    if (bl != 0x07)
        goto loc_1cc4b;
    memoryASet(ds, si, 0x00);
    return;
loc_1cc4b: // 1b0c:1b8b
    memoryASet(ds, si + 9, bl);
loc_1cc4e: // 1b0c:1b8e
    bl += 0xb3;
    goto loc_1cca0;
    //   gap of 77 bytes
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
}
void sub_1cc53() // 1b0c:1b93
{
    bl = memoryAGet(ds, si + 9);
    if (bl >= 0x68)
        goto loc_1cc67;
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1cc90;
    memoryASet(ds, si + 10, 0x05);
loc_1cc67: // 1b0c:1ba7
    bl++;
    if (bl <= 0x68)
        goto loc_1cc85;
    if (bl != 0x70)
        goto loc_1cc75;
    bl = 0x68;
loc_1cc75: // 1b0c:1bb5
    memoryASet(ds, si + 9, bl);
    bl &= 0x07;
    bl++;
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    goto loc_1cc90;
loc_1cc85: // 1b0c:1bc5
    if (bl & 0x07)
        goto loc_1cc8d;
    bl -= 0x08;
loc_1cc8d: // 1b0c:1bcd
    memoryASet(ds, si + 9, bl);
loc_1cc90: // 1b0c:1bd0
    bl += 0x10;
    goto loc_1cca0;
    //   gap of 11 bytes
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
}
void sub_1cc95() // 1b0c:1bd5
{
    bl = 0x17;
    if (memoryAGet(ds, 0x48e9) != 0x00)
        goto loc_1cca0;
    bl = 0x16;
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
}
void sub_1ccb5() // 1b0c:1bf5
{
    goto loc_1ccb5;
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
    return;
loc_1ccb5: // 1b0c:1bf5
    if (memoryAGet(ds, si + 10) == 0x00)
        goto loc_1cccd;
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1cccd;
    memoryASet(ds, si + 10, 0x00);
    al = memoryAGet(ds, si + 9);
    memoryASet(ds, si + 1, al);
loc_1cccd: // 1b0c:1c0d
    bl = memoryAGet(ds, si + 1);
    bl &= 0x0f;
    bl += 0x0a;
    goto loc_1cca0;
}
void sub_1ccd8() // 1b0c:1c18
{
    goto loc_1ccd8;
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
    return;
    //   gap of 35 bytes
loc_1ccd8: // 1b0c:1c18
    bl = 0x78;
    goto loc_1cca0;
}
void sub_1ccdc() // 1b0c:1c1c
{
    goto loc_1ccdc;
loc_1cca0: // 1b0c:1be0
    bh = 0;
    ch = bh;
    dh = bh;
    cl = memoryAGet(ds, si + 2);
    dl = memoryAGet(ds, si + 4);
    push(si);
    sub_1fb3b();
    sub_1fb4c();
    si = pop();
    return;
    //   gap of 39 bytes
loc_1ccdc: // 1b0c:1c1c
    bl = memoryAGet(ds, si + 9);
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        goto loc_1ccf7;
    memoryASet(ds, si + 10, 0x06);
    bl++;
    if (bl != 0x04)
        goto loc_1ccf4;
    bl = 0;
loc_1ccf4: // 1b0c:1c34
    memoryASet(ds, si + 9, bl);
loc_1ccf7: // 1b0c:1c37
    bl += 0xc4;
    goto loc_1cca0;
}
void sub_1ccfc() // 1b0c:1c3c
{
    ah = 0;
    al = memoryAGet(ds, 0x5870);
    tl = memoryAGet(ds, 0x48d7);
    memoryASet(ds, 0x48d7, memoryAGet(ds, 0x48d7) - al);
    al = memoryAGet(ds, 0x48d4);
    if ((char)tl - (char)al > 0)
        goto loc_1cd1c;
    memoryASet(ds, 0x48d7, memoryAGet(ds, 0x48d7) + 0x14);
    al++;
    if (al < memoryAGet(ds, 0x48d2))
        goto loc_1cd19;
    al = 0;
loc_1cd19: // 1b0c:1c59
    memoryASet(ds, 0x48d4, al);
loc_1cd1c: // 1b0c:1c5c
    bh = 0;
    ch = bh;
    bl = memoryAGet(ds, 0x48cf);
    if (bl == 0x13)
        goto loc_1cd65;
loc_1cd29: // 1b0c:1c69
    bl += 0xc9;
    bx += ax;
    if (al != 0x03)
        goto loc_1cd41;
    memoryASet(ds, 0x48cf, 0x0f);
    memoryASet(ds, 0x48d2, 0x01);
    memoryASet(ds, 0x48d4, 0x00);
loc_1cd41: // 1b0c:1c81
    cl = memoryAGet(ds, 0x48d8);
    if (memoryAGet(ds, 0x48d6) != 0x00)
        goto loc_1cd57;
    memoryASet(ds, 0x48d6, 0x01);
    sub_1fb85();
    sub_1fb89();
loc_1cd57: // 1b0c:1c97
    dx = 0x00bb;
    sub_1fb46();
    return;
loc_1cd5e: // 1b0c:1c9e
    bl = 0x03;
    al = memoryAGet(ds, 0x48d4);
    goto loc_1cd29;
loc_1cd65: // 1b0c:1ca5
    al = memoryAGet(ds, 0x48db);
    tl = al;
    al -= memoryAGet(ds, 0x48d8);
    if (al == 0)
        goto loc_1cd5e;
    memoryASet(ds, 0x48d6, 0x00);
    dh = 0xff;
    if (tl > memoryAGet(ds, 0x48d8))
        goto loc_1cd7d;
    al = -al;
    dh = 0x01;
    bl = 0x21;
loc_1cd7d: // 1b0c:1cbd
    if (al < 0x03)
        goto loc_1cd5e;
    memoryASet(ds, 0x48d4, 0x00);
    memoryASet(ds, 0x48dc, memoryAGet(ds, 0x48dc) - 1);
    if (memoryAGet(ds, 0x48dc) != 0)
        goto loc_1cd95;
    memoryASet(ds, 0x48dc, 0x02);
    memoryASet(ds, 0x48db, memoryAGet(ds, 0x48db) + dh);
loc_1cd95: // 1b0c:1cd5
    if (al <= 0x3a)
        goto loc_1cdae;
    ah = memoryAGet(ds, 0x48d8);
    al = 0x3a;
    if (!(dh & 0x80))
        goto loc_1cda8;
    ah += al;
    goto loc_1cdaa;
loc_1cda8: // 1b0c:1ce8
    ah -= al;
loc_1cdaa: // 1b0c:1cea
    memoryASet(ds, 0x48db, ah);
loc_1cdae: // 1b0c:1cee
    al >>= 1;
    al >>= 1;
    if (!al)
        goto loc_1cdb8;
    al--;
loc_1cdb8: // 1b0c:1cf8
    bl += al;
    cl = memoryAGet(ds, 0x48d8);
    if (dh & 0x80)
        goto loc_1cdcc;
    cl -= al;
    cl -= al;
    cl -= al;
    cl -= 0x02;
loc_1cdcc: // 1b0c:1d0c
    bl += 0xc9;
    sub_1cd4c();
}
void sub_1cd4c() // 1b0c:1c8c
{
    memoryASet(ds, 0x48d6, 0x01);
    sub_1fb85();
    sub_1fb89();
    dx = 0x00bb;
    sub_1fb46();
}
void sub_1cdd3() // 1b0c:1d13
{
    memoryASet(ds, si, 0x00);
    if (memoryAGet(ds, 0x002e) == 0x00)
        goto loc_1cde0;
    sub_1bf26();
loc_1cde0: // 1b0c:1d20
    ax = memoryAGet16(ds, si + 5);
    cl = memoryAGet(ds, si + 7);
    sub_1da36();
    bx = memoryAGet16(ds, si + 1);
    cx = memoryAGet16(ds, si + 3);
    al = 0x0f;
    push(si);
    si = 0x495d;
    sub_1fb75();
    si = pop();
}
void sub_1cdef() // 1b0c:1d2f
{
    al = 0x0f;
    push(si);
    si = 0x495d;
    sub_1fb75();
    si = pop();
}
void sub_1cdfa() // 1b0c:1d3a
{
    ax = memoryAGet16(ds, 0x48f0);
    tx = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - ax);
    if ((short)tx - (short)ax > 0)
        goto loc_1ce1d;
    memoryASet16(ds, si + 5, 0x7d00);
    memoryASet(ds, 0x48e0, 0x02);
    memoryASet(ds, 0x48dd, 0xfe);
    if (memoryAGet(ds, 0x48d8) < 0x64)
        goto loc_1ce1d;
    memoryASet(ds, 0x48dd, 0x02);
loc_1ce1d: // 1b0c:1d5d
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        return;
    memoryASet(ds, si + 10, 0x02);
    bl = memoryAGet(ds, si + 9);
    bl++;
    if (bl != 0x03)
        goto loc_1ce32;
    bl = 0;
loc_1ce32: // 1b0c:1d72
    memoryASet(ds, si + 9, bl);
    push(si);
    bl += 0xba;
    cx = 0x0000;
    dx = 0x00a2;
    push(bx);
    sub_1fb4c();
    bx = pop();
    cx = 0x0000;
    dx = 0x00a2;
    push(bx);
    sub_1fb46();
    bx = pop();
    cx = 0x00d8;
    dx = 0x00a2;
    push(bx);
    sub_1fb4c();
    bx = pop();
    cx = 0x00d8;
    dx = 0x00a2;
    sub_1fb46();
    si = pop();
}
void sub_1ce35() // 1b0c:1d75
{
    push(si);
    bl += 0xba;
    cx = 0x0000;
    dx = 0x00a2;
    push(bx);
    sub_1fb4c();
    bx = pop();
    cx = 0x0000;
    dx = 0x00a2;
    push(bx);
    sub_1fb46();
    bx = pop();
    cx = 0x00d8;
    dx = 0x00a2;
    push(bx);
    sub_1fb4c();
    bx = pop();
    cx = 0x00d8;
    dx = 0x00a2;
    sub_1fb46();
    si = pop();
}
void sub_1ce96() // 1b0c:1dd6
{
    sub_1cee6();
    sub_1d04b();
    sub_1d15f();
    sub_1d1ae();
    sub_1d105();
}
void sub_1cebd() // 1b0c:1dfd
{
    dh = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 4, 0xb3);
    goto loc_1cffd;
    //   gap of 310 bytes
loc_1cffd: // 1b0c:1f3d
    dl = memoryAGet(ds, 0x48d0);
    cl = dl;
    dl >>= 1;
    bl = 0x01;
    if ((char)dh < (char)dl)
        goto loc_1d011;
    cl -= dh;
    dh = cl;
    bl--;
loc_1d011: // 1b0c:1f51
    dl >>= 1;
    dl >>= 1;
    di = 0x4979;
    cx = 0x0004;
loc_1d01b: // 1b0c:1f5b
    di += 0x0002;
    tl = dh;
    dh -= dl;
    if ((char)tl - (char)dl <= 0)
        goto loc_1d024;
    if (--cx)
        goto loc_1d01b;
loc_1d024: // 1b0c:1f64
    cl = memoryAGet(ds, di);
    al = memoryAGet(ds, 0x48e8);
    mul(cl);
    if (!bl)
        goto loc_1d031;
    ax = -ax;
loc_1d031: // 1b0c:1f71
    memoryASet16(ds, si + 5, ax);
    dl = memoryAGet(ds, di + 1);
    al = memoryAGet(ds, 0x48e8);
    mul(dl);
    ax = -ax;
    memoryASet16(ds, si + 7, ax);
}
void sub_1cee6() // 1b0c:1e26
{
    goto loc_1cee6;
loc_1ca4d: // 1b0c:198d
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + ax);
    return;
    //   gap of 1106 bytes
loc_1cea6: // 1b0c:1de6
    if (memoryAGet(ds, 0x48da) != 0x00)
        goto loc_1cebd;
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - 1);
    if (memoryAGet(ds, si + 10) == 0)
        goto loc_1cebd;
    al = memoryAGet(ds, si + 1);
    al += memoryAGet(ds, 0x48d8);
    memoryASet(ds, si + 2, al);
    return;
loc_1cebd: // 1b0c:1dfd
    dh = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 4, 0xb3);
    goto loc_1cffd;
loc_1cec7: // 1b0c:1e07
    push(si);
    si = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1cecf: // 1b0c:1e0f
    if (memoryAGet(ds, si) == 0x06)
        goto loc_1ced9;
    si += 0x000b;
    if (--cx)
        goto loc_1cecf;
loc_1ced9: // 1b0c:1e19
    push(si);
    di = 0x4d5e;
    sub_1c912();
    si = pop();
    memoryASet(ds, si, 0x00);
    si = pop();
    return;
loc_1cee6: // 1b0c:1e26
    if (memoryAGet16(ds, si + 5) == 0x0000)
        goto loc_1cea6;
    dh = memoryAGet(ds, si + 2);
    if (dh > 0xd1)
        goto loc_1ceff;
    if (dh >= 0x08)
        goto loc_1cf09;
    memoryASet(ds, si + 2, 0x08);
    goto loc_1cf03;
loc_1ceff: // 1b0c:1e3f
    memoryASet(ds, si + 2, 0xd1);
loc_1cf03: // 1b0c:1e43
    sub_1dc26();
    sub_1cf4d();
loc_1cf09: // 1b0c:1e49
    ah = memoryAGet(ds, si + 4);
    if (ah < 0x0a)
        goto loc_1cf44;
    if (ah > 0xc1)
        goto loc_1cf21;
    if (ah < 0xb4)
        goto loc_1cf20;
    if (ah <= 0xba)
        goto loc_1cf53;
loc_1cf20: // 1b0c:1e60
    return;
loc_1cf21: // 1b0c:1e61
    memoryASet(ds, si, 0x00);
    memoryASet(ds, 0x48ea, memoryAGet(ds, 0x48ea) - 1);
    if (memoryAGet(ds, 0x48ea) == 0x01)
        goto loc_1cec7;
    if (memoryAGet(ds, 0x48ea) > 0x01)
        goto loc_1cf43;
    sub_1dea0();
    sub_1e01c();
    if (si != 0x4d5e)
        goto loc_1cf42;
    ax = pop();
    ax = pop();
    ax = pop();
    ax = pop();
    ax = pop();
loc_1cf42: // 1b0c:1e82
    ax = pop();
loc_1cf43: // 1b0c:1e83
    return;
loc_1cf44: // 1b0c:1e84
    sub_1dc26();
loc_1cf47: // 1b0c:1e87
    memoryASet16(ds, si + 7, -memoryAGet16(ds, si + 7));
    goto loc_1ca4d;
    //   gap of 6 bytes
loc_1cf53: // 1b0c:1e93
    ah = memoryAGet(ds, 0x48d8);
    ah -= 0x05;
    if (dh < ah)
        goto loc_1cf6f;
    ah += memoryAGet(ds, 0x48d0);
    ah += 0x08;
    if (dh > ah)
        goto loc_1cf8e;
    ah = memoryAGet(ds, 0x48d8);
    goto loc_1cfdb;
loc_1cf6f: // 1b0c:1eaf
    if (memoryAGet(ds, 0x48cf) != 0x13)
        goto loc_1cf43;
    ah = memoryAGet(ds, 0x48d8);
    dl = ah;
    ah -= memoryAGet(ds, 0x48db);
    sub_1d042();
    dl -= ah;
    dl -= 0x03;
    if (dh < dl)
        goto loc_1cf43;
    goto loc_1cfce;
loc_1cf8e: // 1b0c:1ece
    al = memoryAGet(ds, 0x48cf);
    if (al == 0x13)
        goto loc_1cfb4;
    if (al != 0x09)
        goto loc_1cf43;
    ah += 0x08;
    if (dh < ah)
        goto loc_1cf43;
    ah += memoryAGet(ds, 0x48d0);
    ah += 0x08;
    if (dh > ah)
        goto loc_1cf43;
    ah -= memoryAGet(ds, 0x48d0);
    ah -= 0x08;
    goto loc_1cfdb;
loc_1cfb4: // 1b0c:1ef4
    ah = memoryAGet(ds, 0x48db);
    ah -= memoryAGet(ds, 0x48d8);
    sub_1d042();
    ah += memoryAGet(ds, 0x48d8);
    ah += memoryAGet(ds, 0x48d0);
    ah += 0x03;
    if (dh > ah)
        return;
loc_1cfce: // 1b0c:1f0e
    bx = 0x0204;
    sub_1f0d2();
    memoryASet(ds, si + 4, 0xb4);
    goto loc_1cf47;
loc_1cfdb: // 1b0c:1f1b
    dh -= ah;
    if (memoryAGet(ds, 0x48d5) == 0x00)
        goto loc_1cff7;
    ax = 0;
    memoryASet(ds, si + 1, dh);
    memoryASet(ds, si + 4, 0xb5);
    memoryASet16(ds, si + 5, ax);
    memoryASet16(ds, si + 7, ax);
    memoryASet(ds, si + 10, al);
    return;
loc_1cff7: // 1b0c:1f37
    bx = 0x0204;
    sub_1f0d2();
loc_1cffd: // 1b0c:1f3d
    dl = memoryAGet(ds, 0x48d0);
    cl = dl;
    dl >>= 1;
    bl = 0x01;
    if ((char)dh < (char)dl)
        goto loc_1d011;
    cl -= dh;
    dh = cl;
    bl--;
loc_1d011: // 1b0c:1f51
    dl >>= 1;
    dl >>= 1;
    di = 0x4979;
    cx = 0x0004;
loc_1d01b: // 1b0c:1f5b
    di += 0x0002;
    tl = dh;
    dh -= dl;
    if ((char)tl - (char)dl <= 0)
        goto loc_1d024;
    if (--cx)
        goto loc_1d01b;
loc_1d024: // 1b0c:1f64
    cl = memoryAGet(ds, di);
    al = memoryAGet(ds, 0x48e8);
    mul(cl);
    if (!bl)
        goto loc_1d031;
    ax = -ax;
loc_1d031: // 1b0c:1f71
    memoryASet16(ds, si + 5, ax);
    dl = memoryAGet(ds, di + 1);
    al = memoryAGet(ds, 0x48e8);
    mul(dl);
    ax = -ax;
    memoryASet16(ds, si + 7, ax);
}
void sub_1cf47() // 1b0c:1e87
{
    goto loc_1cf47;
loc_1ca4d: // 1b0c:198d
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + ax);
    return;
    //   gap of 1267 bytes
loc_1cf47: // 1b0c:1e87
    memoryASet16(ds, si + 7, -memoryAGet16(ds, si + 7));
    goto loc_1ca4d;
}
void sub_1cf4d() // 1b0c:1e8d
{
    goto loc_1cf4d;
loc_1ca54: // 1b0c:1994
    ax = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) + ax);
    return;
    //   gap of 1266 bytes
loc_1cf4d: // 1b0c:1e8d
    memoryASet16(ds, si + 5, -memoryAGet16(ds, si + 5));
    goto loc_1ca54;
}
void sub_1d042() // 1b0c:1f82
{
    ah >>= 1;
    al = ah;
    ah >>= 1;
    ah += al;
}
void sub_1d04b() // 1b0c:1f8b
{
    cl = memoryAGet(ds, 0x0493);
    if (cl == 0x10)
        goto loc_1d05a;
    if (cl == 0x21)
        goto loc_1d05e;
    return;
loc_1d05a: // 1b0c:1f9a
    sub_1d05e();
    return;
loc_1d05e: // 1b0c:1f9e
    bl = memoryAGet(ds, si + 4);
    if (bl < 0x38)
        goto loc_1d0b0;
    if (bl > 0x88)
        goto loc_1d0b0;
    bh = memoryAGet(ds, si + 2);
    if (bh < 0x56)
        goto loc_1d0b0;
    if (bh > 0x88)
        goto loc_1d0b0;
    if (bh > 0x83)
        goto loc_1d082;
    if (bh >= 0x5b)
        goto loc_1d085;
loc_1d082: // 1b0c:1fc2
    sub_1cf4d();
loc_1d085: // 1b0c:1fc5
    if (bl > 0x83)
        goto loc_1d08f;
    if (bl >= 0x3d)
        goto loc_1d092;
loc_1d08f: // 1b0c:1fcf
    sub_1cf47();
loc_1d092: // 1b0c:1fd2
    sub_1dc26();
    bx = 0x0203;
    sub_1f0d2();
    memoryASet(ds, 0x4938, memoryAGet(ds, 0x4938) + 1);
    al = 0x10;
    if (memoryAGet(ds, 0x4938) == al)
        goto loc_1d0b1;
    memoryASet(ds, 0x48e5, 0x02);
    sub_1d6be();
    ax = pop();
loc_1d0b0: // 1b0c:1ff0
    return;
loc_1d0b1: // 1b0c:1ff1
    push(si);
    sub_1d7c8();
    sub_1c8de();
    bx = 0x587c;
    sub_1c939();
    sub_1fb42();
    sub_1fb2b();
    sub_1fb42();
    sub_1fb2b();
    sub_1ccfc();
    cx = 0x003c;
loc_1d0d0: // 1b0c:2010
    push(cx);
    sub_1f961();
    al = 0x01;
    sub_1fb9b();
    sub_1f961();
    al = 0;
    sub_1fb9b();
    cx = pop();
    if (--cx)
        goto loc_1d0d0;
    sub_1bf9f();
    bx = 0x0205;
    sub_1f0d2();
    cx = 0x0034;
loc_1d0f0: // 1b0c:2030
    push(cx);
    sub_1f961();
    sub_1fb9f();
    cx = pop();
    cx++;
    if (cx != 0x0099)
        goto loc_1d0f0;
    sub_1d28e();
    si = pop();
    ax = pop();
}
void sub_1d05e() // 1b0c:1f9e
{
    bl = memoryAGet(ds, si + 4);
    if (bl < 0x38)
        goto loc_1d0b0;
    if (bl > 0x88)
        goto loc_1d0b0;
    bh = memoryAGet(ds, si + 2);
    if (bh < 0x56)
        goto loc_1d0b0;
    if (bh > 0x88)
        goto loc_1d0b0;
    if (bh > 0x83)
        goto loc_1d082;
    if (bh >= 0x5b)
        goto loc_1d085;
loc_1d082: // 1b0c:1fc2
    sub_1cf4d();
loc_1d085: // 1b0c:1fc5
    if (bl > 0x83)
        goto loc_1d08f;
    if (bl >= 0x3d)
        goto loc_1d092;
loc_1d08f: // 1b0c:1fcf
    sub_1cf47();
loc_1d092: // 1b0c:1fd2
    sub_1dc26();
    bx = 0x0203;
    sub_1f0d2();
    memoryASet(ds, 0x4938, memoryAGet(ds, 0x4938) + 1);
    al = 0x10;
    if (memoryAGet(ds, 0x4938) == al)
        goto loc_1d0b1;
    memoryASet(ds, 0x48e5, 0x02);
    sub_1d6be();
    ax = pop();
loc_1d0b0: // 1b0c:1ff0
    return;
loc_1d0b1: // 1b0c:1ff1
    push(si);
    sub_1d7c8();
    sub_1c8de();
    bx = 0x587c;
    sub_1c939();
    sub_1fb42();
    sub_1fb2b();
    sub_1fb42();
    sub_1fb2b();
    sub_1ccfc();
    cx = 0x003c;
loc_1d0d0: // 1b0c:2010
    push(cx);
    sub_1f961();
    al = 0x01;
    sub_1fb9b();
    sub_1f961();
    al = 0;
    sub_1fb9b();
    cx = pop();
    if (--cx)
        goto loc_1d0d0;
    sub_1bf9f();
    bx = 0x0205;
    sub_1f0d2();
    cx = 0x0034;
loc_1d0f0: // 1b0c:2030
    push(cx);
    sub_1f961();
    sub_1fb9f();
    cx = pop();
    cx++;
    if (cx != 0x0099)
        goto loc_1d0f0;
    sub_1d28e();
    si = pop();
    ax = pop();
}
void sub_1d105() // 1b0c:2045
{
    bl = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 2);
    bh = 0;
    al += 0x04;
    bl += 0x04;
    sub_1d484();
    if (flags.carry)
        return;
    al = memoryAGet(ds, bx + 1417);
    al &= 0x0f;
    if (al == 0)
        return;
    ch = memoryAGet(ds, bx + 1417);
    if (memoryAGet(ds, 0x48e9) != 0x00)
        goto loc_1d141;
    sub_1dc1a();
    sub_1d8a1();
    if (al >= 0x04)
        goto loc_1d141;
    sub_1dd10();
    if (al == 0x01)
        return;
    memoryASet(ds, bx + 1183, memoryAGet(ds, bx + 1183) - 1);
    if (memoryAGet(ds, bx + 1183) != 0)
        return;
loc_1d141: // 1b0c:2081
    push(ax);
    sub_1d94d();
    ax = pop();
    sub_1d250();
    ch &= 0xf0;
    memoryASet(ds, bx + 1417, ch);
    push(bx);
    bx = 0x0202;
    sub_1f0d2();
    bx = pop();
    sub_1d6db();
    sub_1d6f6();
}
void sub_1d158() // 1b0c:2098
{
    sub_1d6db();
    sub_1d6f6();
}
void sub_1d15f() // 1b0c:209f
{
    di = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 4);
    ax += 0x0505;
loc_1d16f: // 1b0c:20af
    bl = memoryAGet(ds, di);
    if (bl == 0x0a)
        goto loc_1d181;
    if (bl == 0x0e)
        goto loc_1d186;
loc_1d17b: // 1b0c:20bb
    di += 0x000b;
    if (--cx)
        goto loc_1d16f;
    return;
loc_1d181: // 1b0c:20c1
    dx = 0x0c15;
    goto loc_1d189;
loc_1d186: // 1b0c:20c6
    dx = 0x0b0b;
loc_1d189: // 1b0c:20c9
    bl = memoryAGet(ds, di + 2);
    if (al < bl)
        goto loc_1d17b;
    bl += dl;
    if (al > bl)
        goto loc_1d17b;
    bh = memoryAGet(ds, di + 4);
    if (ah < bh)
        goto loc_1d17b;
    bh += dh;
    if (ah > bh)
        goto loc_1d17b;
    if (dl == 0x15)
        goto loc_1d1ab;
    cl = 0x02;
    return;
loc_1d1ab: // 1b0c:20eb
    cl = 0x01;
}
void sub_1d1ae() // 1b0c:20ee
{
    goto loc_1d1ae;
loc_1ca4d: // 1b0c:198d
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) + ax);
    return;
loc_1ca54: // 1b0c:1994
    ax = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) + ax);
    return;
    //   gap of 1260 bytes
loc_1cf47: // 1b0c:1e87
    memoryASet16(ds, si + 7, -memoryAGet16(ds, si + 7));
    goto loc_1ca4d;
loc_1cf4d: // 1b0c:1e8d
    memoryASet16(ds, si + 5, -memoryAGet16(ds, si + 5));
    goto loc_1ca54;
    //   gap of 603 bytes
loc_1d1ae: // 1b0c:20ee
    if (cl < 0x01)
        goto loc_1d1c4;
    if (cl == 0x01)
        goto loc_1d1c5;
    sub_1d23b();
    if (!(memoryAGet(ds, si + 8) & 0x80))
        goto loc_1d1c1;
    goto loc_1cf47;
loc_1d1c1: // 1b0c:2101
    goto loc_1cf4d;
loc_1d1c4: // 1b0c:2104
    return;
loc_1d1c5: // 1b0c:2105
    ch = memoryAGet(ds, di + 9);
    al = ch;
    al &= 0x0f;
    if (memoryAGet(ds, 0x48e9) != 0x00)
        goto loc_1d1f0;
    bl -= dl;
    bh -= dh;
    bl -= al;
    bh -= ah;
    tx = dx;
    dx = bx;
    bx = tx;
    sub_1d88a();
    if (al >= 0x04)
        goto loc_1d1f0;
    sub_1dcc5();
    if (al == 0x01)
        goto loc_1d1c4;
    memoryASet(ds, di + 8, memoryAGet(ds, di + 8) - 1);
    if (memoryAGet(ds, di + 8) != 0)
        goto loc_1d1c4;
loc_1d1f0: // 1b0c:2130
    memoryASet(ds, di, 0x00);
    push(ax);
    sub_1d931();
    ax = pop();
    goto loc_1d250;
    //   gap of 86 bytes
loc_1d250: // 1b0c:2190
    if (al < 0x02)
        goto loc_1d266;
    if (al == 0x02)
        goto loc_1d272;
    memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) - 1);
    if (memoryAGet(ds, 0x0498) != 0)
        goto loc_1d266;
    push(cx);
    push(bx);
    sub_1d7c8();
    sub_1d28e();
    bx = pop();
    cx = pop();
loc_1d266: // 1b0c:21a6
    sub_1d454();
    push(bx);
    bx = 0x0202;
    sub_1f0d2();
    bx = pop();
    return;
loc_1d272: // 1b0c:21b2
    push(bx);
    memoryASet16(ds, 0x58ff, bx);
    memoryASet(ds, 0x5901, al);
    sub_1d5a8();
    memoryASet(ds, 0x58f9, bl);
    memoryASet(ds, 0x58fb, dl);
    bx = 0x58f8;
    sub_1c939();
    bx = pop();
    goto loc_1d266;
}
void sub_1d228() // 1b0c:2168
{
    goto loc_1d228;
loc_1d1c4: // 1b0c:2104
    return;
    //   gap of 27 bytes
loc_1d1e0: // 1b0c:2120
    if (al >= 0x04)
        goto loc_1d1f0;
    sub_1dcc5();
    if (al == 0x01)
        goto loc_1d1c4;
    memoryASet(ds, di + 8, memoryAGet(ds, di + 8) - 1);
    if (memoryAGet(ds, di + 8) != 0)
        goto loc_1d1c4;
loc_1d1f0: // 1b0c:2130
    memoryASet(ds, di, 0x00);
    push(ax);
    sub_1d931();
    ax = pop();
    goto loc_1d250;
    //   gap of 46 bytes
loc_1d228: // 1b0c:2168
    if (cl < 0x01)
        goto loc_1d24f;
    memoryASet(ds, si, 0x00);
    if (cl != 0x01)
        goto loc_1d23b;
    ch = memoryAGet(ds, di + 9);
    al = ch;
    al &= 0x0f;
    goto loc_1d1e0;
loc_1d23b: // 1b0c:217b
    al = memoryAGet(ds, di + 7);
    if (al == 0x04)
        goto loc_1d24f;
    push(si);
    si = di;
    sub_1d35e();
    si = pop();
    ax = 0x0010;
    sub_1b130();
loc_1d24f: // 1b0c:218f
    return;
loc_1d250: // 1b0c:2190
    if (al < 0x02)
        goto loc_1d266;
    if (al == 0x02)
        goto loc_1d272;
    memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) - 1);
    if (memoryAGet(ds, 0x0498) != 0)
        goto loc_1d266;
    push(cx);
    push(bx);
    sub_1d7c8();
    sub_1d28e();
    bx = pop();
    cx = pop();
loc_1d266: // 1b0c:21a6
    sub_1d454();
    push(bx);
    bx = 0x0202;
    sub_1f0d2();
    bx = pop();
    return;
loc_1d272: // 1b0c:21b2
    push(bx);
    memoryASet16(ds, 0x58ff, bx);
    memoryASet(ds, 0x5901, al);
    sub_1d5a8();
    memoryASet(ds, 0x58f9, bl);
    memoryASet(ds, 0x58fb, dl);
    bx = 0x58f8;
    sub_1c939();
    bx = pop();
    goto loc_1d266;
}
void sub_1d23b() // 1b0c:217b
{
    al = memoryAGet(ds, di + 7);
    if (al == 0x04)
        return;
    push(si);
    si = di;
    sub_1d35e();
    si = pop();
    ax = 0x0010;
    sub_1b130();
}
void sub_1d250() // 1b0c:2190
{
    if (al < 0x02)
        goto loc_1d266;
    if (al == 0x02)
        goto loc_1d272;
    memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) - 1);
    if (memoryAGet(ds, 0x0498) != 0)
        goto loc_1d266;
    push(cx);
    push(bx);
    sub_1d7c8();
    sub_1d28e();
    bx = pop();
    cx = pop();
loc_1d266: // 1b0c:21a6
    sub_1d454();
    push(bx);
    bx = 0x0202;
    sub_1f0d2();
    bx = pop();
    return;
loc_1d272: // 1b0c:21b2
    push(bx);
    memoryASet16(ds, 0x58ff, bx);
    memoryASet(ds, 0x5901, al);
    sub_1d5a8();
    memoryASet(ds, 0x58f9, bl);
    memoryASet(ds, 0x58fb, dl);
    bx = 0x58f8;
    sub_1c939();
    bx = pop();
    goto loc_1d266;
}
void sub_1d28e() // 1b0c:21ce
{
    sub_1dca8();
    memoryASet(ds, 0x48e0, 0x01);
    bx = 0x590e;
    memoryASet16(ds, bx + 5, 0x0258);
    sub_1c939();
}
void sub_1d2c8() // 1b0c:2208
{
    goto loc_1d2c8;
loc_1ca54: // 1b0c:1994
    ax = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) + ax);
    return;
    //   gap of 1266 bytes
loc_1cf4d: // 1b0c:1e8d
    memoryASet16(ds, si + 5, -memoryAGet16(ds, si + 5));
    goto loc_1ca54;
    //   gap of 885 bytes
loc_1d2c8: // 1b0c:2208
    bh = 0;
    bl = memoryAGet(ds, si + 3);
    al = memoryAGet(ds, si + 2);
    sub_1d498();
    ah = memoryAGet(ds, bx + 1417);
    ah &= 0x0f;
    if (ah != 0)
        goto loc_1d2e6;
    ah = memoryAGet(ds, bx + 1418);
    ah &= 0x0f;
    if (ah != 0)
        goto loc_1d2e6;
    return;
loc_1d2e6: // 1b0c:2226
    goto loc_1cf4d;
}
void sub_1d2e9() // 1b0c:2229
{
    di = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 4);
loc_1d2f6: // 1b0c:2236
    bl = memoryAGet(ds, di);
    if (bl != 0x0a)
        goto loc_1d320;
    if (si == di)
        goto loc_1d320;
    if (ah != memoryAGet(ds, di + 4))
        goto loc_1d320;
    bl = memoryAGet(ds, di + 2);
    if (al < bl)
        goto loc_1d316;
    bl += 0x0f;
    if (al > bl)
        goto loc_1d320;
    goto loc_1d31d;
loc_1d316: // 1b0c:2256
    bl -= 0x0f;
    if (al < bl)
        goto loc_1d320;
loc_1d31d: // 1b0c:225d
    sub_1cf4d();
loc_1d320: // 1b0c:2260
    di += 0x000b;
    if (--cx)
        goto loc_1d2f6;
}
void sub_1d330() // 1b0c:2270
{
    al = memoryAGet(ds, si + 2);
    if (al >= 0xcc)
        goto loc_1d347;
    if (al <= 0x08)
        goto loc_1d34d;
    al = memoryAGet(ds, si + 4);
    if (al < 0x0a)
        goto loc_1d353;
    if (al > 0xb4)
        goto loc_1d35e;
    return;
loc_1d347: // 1b0c:2287
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) - 0x02);
    goto loc_1d357;
loc_1d34d: // 1b0c:228d
    memoryASet(ds, si + 2, memoryAGet(ds, si + 2) + 0x02);
    goto loc_1d357;
loc_1d353: // 1b0c:2293
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 0x02);
loc_1d357: // 1b0c:2297
    sub_1ca85();
    sub_1ca6f();
    return;
loc_1d35e: // 1b0c:229e
    ax = memoryAGet16(ds, si + 1);
    memoryASet16(ds, 0x58cd, ax);
    ax = memoryAGet16(ds, si + 3);
    memoryASet16(ds, 0x58cf, ax);
    bx = 0x58cc;
    sub_1c939();
    bx = 0x0205;
    sub_1f0d2();
    memoryASet(ds, 0x48ec, memoryAGet(ds, 0x48ec) - 1);
    memoryASet(ds, si, 0x00);
}
void sub_1d35e() // 1b0c:229e
{
    ax = memoryAGet16(ds, si + 1);
    memoryASet16(ds, 0x58cd, ax);
    ax = memoryAGet16(ds, si + 3);
    memoryASet16(ds, 0x58cf, ax);
    bx = 0x58cc;
    sub_1c939();
    bx = 0x0205;
    sub_1f0d2();
    memoryASet(ds, 0x48ec, memoryAGet(ds, 0x48ec) - 1);
    memoryASet(ds, si, 0x00);
}
void sub_1d37e() // 1b0c:22be
{
    al = memoryAGet(ds, 0x0493);
    if (al == 0x10)
        goto loc_1d386;
    return;
loc_1d386: // 1b0c:22c6
    al = memoryAGet(ds, si + 4);
    if (al < 0x2a)
        goto loc_1d39f;
    if (al > 0x91)
        goto loc_1d39f;
    al = memoryAGet(ds, si + 2);
    if (al < 0x43)
        goto loc_1d39f;
    if (al > 0x90)
        goto loc_1d39f;
    sub_1d3f0();
loc_1d39f: // 1b0c:22df
    ax = pop();
}
void sub_1d3a1() // 1b0c:22e1
{
    cl = memoryAGet(ds, si + 4);
    ch = memoryAGet(ds, si + 2);
    bh = 0;
    bl = cl;
    al = ch;
    sub_1d484();
    if (flags.carry)
        goto loc_1d3cb;
    al = memoryAGet(ds, bx + 1417);
    al &= 0x0f;
    if (al != 0)
        goto loc_1d3f0;
    bl = cl;
    al = ch;
    al += 0x09;
    sub_1d484();
    al = memoryAGet(ds, bx + 1417);
    al &= 0x0f;
    if (al != 0)
        goto loc_1d3f0;
loc_1d3cb: // 1b0c:230b
    cl += 0x09;
    bl = cl;
    al = ch;
    sub_1d484();
    if (flags.carry)
        return;
    al = memoryAGet(ds, bx + 1417);
    al &= 0x0f;
    if (al != 0)
        goto loc_1d3f0;
    bl = cl;
    al = ch;
    al += 0x09;
    sub_1d484();
    al = memoryAGet(ds, bx + 1417);
    al &= 0x0f;
    if (al == 0)
        return;
loc_1d3f0: // 1b0c:2330
    sub_1ca85();
    al = memoryAGet(ds, si + 6);
    if (al != memoryAGet(ds, bx))
        goto loc_1d3fd;
    bx -= 0x0005;
loc_1d3fd: // 1b0c:233d
    ax = memoryAGet16(ds, bx + 1);
    dx = memoryAGet16(ds, bx + 3);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) - ax);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) - dx);
    sub_1ca6f();
}
void sub_1d3f0() // 1b0c:2330
{
    sub_1ca85();
    al = memoryAGet(ds, si + 6);
    if (al != memoryAGet(ds, bx))
        goto loc_1d3fd;
    bx -= 0x0005;
loc_1d3fd: // 1b0c:233d
    ax = memoryAGet16(ds, bx + 1);
    dx = memoryAGet16(ds, bx + 3);
    memoryASet16(ds, si + 1, memoryAGet16(ds, si + 1) - ax);
    memoryASet16(ds, si + 3, memoryAGet16(ds, si + 3) - dx);
    sub_1ca6f();
}
void sub_1d454() // 1b0c:2394
{
    push(bx);
    bl = ch;
    bl &= 0x0f;
    bh = 0;
    al = memoryAGet(ds, bx + 18769);
    ah = bh;
    if (bl > 0x03)
        goto loc_1d47f;
    bl = memoryAGet(ds, 0x0493);
    bh = 0;
loc_1d46d: // 1b0c:23ad
    if (bl < 0x0a)
        goto loc_1d47a;
    bh += 0x10;
    bl -= 0x0a;
    goto loc_1d46d;
loc_1d47a: // 1b0c:23ba
    bh += bl;
    al += bh;
    stop(); // daa 
loc_1d47f: // 1b0c:23bf
    sub_1b130();
    bx = pop();
}
void sub_1d484() // 1b0c:23c4
{
    if (bl > 0x88)
        goto loc_1d4aa;
    tl = bl;
    bl -= 0x0b;
    if (tl < 0x0b)
        goto loc_1d4aa;
    dh = memoryAGet(cs, bx + 9322);
    bl = memoryAGet(cs, bx + 9196);
    al -= 0x08;
    dl = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah = al;
    bl += al;
    flags.carry = false;
    return;
loc_1d4aa: // 1b0c:23ea
    flags.carry = true;
}
void sub_1d498() // 1b0c:23d8
{
    al -= 0x08;
    dl = al;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    ah = al;
    bl += al;
    flags.carry = false;
}
void sub_1d5a8() // 1b0c:24e8
{
    dl = 0x03;
    bp = 0xfff3;
loc_1d5ad: // 1b0c:24ed
    bp += 0x000d;
    dl += 0x07;
    tx = bx;
    bx -= 0x000d;
    if ((short)tx - (short)0x000d >= 0)
        goto loc_1d5ad;
    bl += 0x0d;
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    bl += 0x08;
}
void sub_1d5c7() // 1b0c:2507
{
    if (cx < 0x0008)
        goto loc_1d5f4;
    if (cx >= 0x00d8)
        goto loc_1d5f4;
    if (dl < 0x0b)
        goto loc_1d5f4;
    if (dl >= 0x89)
        goto loc_1d5f4;
    push(bx);
    al = cl;
    bl = dl;
    sub_1d484();
    bh = 0;
    push(bx);
    sub_1d5a8();
    dh = 0;
    ch = dh;
    cl = bl;
    ax = pop();
    bx = pop();
    flags.carry = false;
    return;
loc_1d5f4: // 1b0c:2534
    cx &= 0x01f0;
    flags.carry = true;
}
void sub_1d5fa() // 1b0c:253a
{
    if (memoryAGet(ds, 0x48ea) >= 0x03)
        return;
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - 1);
    if (memoryAGet(ds, si + 10) == 0)
        goto loc_1d63b;
    memoryASet(ds, 0x48ea, memoryAGet(ds, 0x48ea) + 1);
    push(si);
    si = 0x4d5e;
    cx = memoryAGet16(ds, 0x48e3);
    cx++;
loc_1d613: // 1b0c:2553
    if (memoryAGet(ds, si) == 0x06)
        goto loc_1d61d;
    si += 0x000b;
    if (--cx)
        goto loc_1d613;
loc_1d61d: // 1b0c:255d
    sub_1d697();
    dx = 0x0008;
    if (!(memoryAGet(ds, si + 6) & 0x80))
        goto loc_1d62b;
    dx = -dx;
loc_1d62b: // 1b0c:256b
    ax += dx;
    memoryASet16(ds, bx + 5, ax);
    memoryASet16(ds, bx + 7, bp);
    sub_1c939();
    sub_1d67f();
    si = pop();
    return;
loc_1d63b: // 1b0c:257b
    memoryASet(ds, si, 0x00);
}
void sub_1d63f() // 1b0c:257f
{
    ch = 0;
    cl = memoryAGet(ds, si + 10);
    memoryASet(ds, 0x48ea, memoryAGet(ds, 0x48ea) + cl);
    sub_1d697();
    dx = 0x0008;
    if (!(memoryAGet(ds, si + 6) & 0x80))
        goto loc_1d656;
    dx = -dx;
loc_1d656: // 1b0c:2596
    di = 0x0002;
    if (!(memoryAGet(ds, si + 8) & 0x80))
        goto loc_1d661;
    di = -di;
loc_1d661: // 1b0c:25a1
    ax += dx;
    bp += di;
    push(cx);
    push(ax);
    push(bp);
    push(dx);
    push(di);
    push(bx);
    memoryASet16(ds, bx + 5, ax);
    memoryASet16(ds, bx + 7, bp);
    sub_1c939();
    bx = pop();
    di = pop();
    dx = pop();
    bp = pop();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_1d661;
    memoryASet(ds, si, 0x00);
    push(si);
    bx = 0x4d5e;
    if (memoryAGet(ds, bx) != 0x06)
        goto loc_1d695;
    push(bx);
    sub_1c939();
    bx = pop();
    memoryASet(ds, bx, 0x00);
    dl = 0;
    sub_1fb90();
loc_1d695: // 1b0c:25d5
    si = pop();
}
void sub_1d67f() // 1b0c:25bf
{
    push(si);
    bx = 0x4d5e;
    if (memoryAGet(ds, bx) != 0x06)
        goto loc_1d695;
    push(bx);
    sub_1c939();
    bx = pop();
    memoryASet(ds, bx, 0x00);
    dl = 0;
    sub_1fb90();
loc_1d695: // 1b0c:25d5
    si = pop();
}
void sub_1d697() // 1b0c:25d7
{
    bx = 0x5887;
    ax = memoryAGet16(ds, si + 1);
    memoryASet16(ds, bx + 1, ax);
    ax = memoryAGet16(ds, si + 3);
    memoryASet16(ds, bx + 3, ax);
    ax = memoryAGet16(ds, si + 5);
    bp = memoryAGet16(ds, si + 7);
}
void sub_1d6ad() // 1b0c:25ed
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) - al);
    if ((char)tl - (char)al > 0)
        return;
    memoryASet(ds, si, 0x00);
    memoryASet(ds, 0x48e5, 0x01);
}
void sub_1d6be() // 1b0c:25fe
{
    bx = 0x595a;
    sub_1c939();
}
void sub_1d6c5() // 1b0c:2605
{
    al = 0x0a;
    goto loc_1d6dd;
    //   gap of 20 bytes
loc_1d6dd: // 1b0c:261d
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6c9() // 1b0c:2609
{
    al = 0x08;
    goto loc_1d6dd;
    //   gap of 16 bytes
loc_1d6dd: // 1b0c:261d
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6cd() // 1b0c:260d
{
    al = 0x06;
    goto loc_1d6dd;
    //   gap of 12 bytes
loc_1d6dd: // 1b0c:261d
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6d1() // 1b0c:2611
{
    al = 0x04;
    goto loc_1d6dd;
    //   gap of 8 bytes
loc_1d6dd: // 1b0c:261d
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6d5() // 1b0c:2615
{
    memoryASet(ds, si, 0x00);
    bx = memoryAGet16(ds, si + 1);
    al = 0x02;
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6db() // 1b0c:261b
{
    al = 0x02;
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
}
void sub_1d6f2() // 1b0c:2632
{
    goto loc_1d6f2;
loc_1d6dd: // 1b0c:261d
    memoryASet(ds, 0x4985, memoryAGet(ds, 0x4985) + 1);
    di = memoryAGet16(ds, 0x4986);
    memoryASet(ds, di, al);
    memoryASet16(ds, di + 1, bx);
    di += 0x0003;
    memoryASet16(ds, 0x4986, di);
    return;
loc_1d6f2: // 1b0c:2632
    al = 0x0c;
    goto loc_1d6dd;
}
void sub_1d6f6() // 1b0c:2636
{
    push(bx);
    memoryASet16(ds, 0x589e, bx);
    bx = 0x589d;
    sub_1c939();
    bx = pop();
}
void sub_1d706() // 1b0c:2646
{
    bx = memoryAGet16(ds, si + 1);
    push(si);
    sub_1d83e();
    di = bx;
    ax = 0;
loc_1d711: // 1b0c:2651
    al++;
    tx = bx;
    bx -= 0x000d;
    if ((short)tx - (short)0x000d >= 0)
        goto loc_1d711;
    bx += 0x000d;
    bl <<= 1;
    bl++;
    sub_1fb6d();
    if (bl == 0x01)
        goto loc_1d737;
    if (al == 0x01)
        goto loc_1d737;
    cl = memoryAGet(ds, di + 1403);
    cl &= 0x0f;
    if (cl == 0)
        goto loc_1d737;
    sub_1fb58();
loc_1d737: // 1b0c:2677
    bl++;
    sub_1fb6d();
    if (al == 0x01)
        goto loc_1d74c;
    cl = memoryAGet(ds, di + 1404);
    cl &= 0x0f;
    if (cl == 0)
        goto loc_1d74c;
    sub_1fb58();
loc_1d74c: // 1b0c:268c
    al++;
    cl = memoryAGet(ds, di + 1430);
    cl &= 0x0f;
    if (cl != 0)
        goto loc_1d75a;
    sub_1fb6d();
loc_1d75a: // 1b0c:269a
    if (bl == 0x1a)
        goto loc_1d76d;
    bl++;
    cl = memoryAGet(ds, di + 1431);
    cl &= 0x0f;
    if (cl != 0)
        goto loc_1d76d;
    sub_1fb6d();
loc_1d76d: // 1b0c:26ad
    si = pop();
}
void sub_1d7c8() // 1b0c:2708
{
    push(si);
    dl = 0;
    sub_1fb90();
    si = pop();
    ah = 0;
    ch = ah;
    cl = memoryAGet(ds, 0x4988);
    if (cx == 0)
        goto loc_1d7df;
    bx = 0x49f9;
    sub_1d7e7();
loc_1d7df: // 1b0c:271f
    bx = 0x4d5e;
    cx = memoryAGet16(ds, 0x48e3);
    cx++;
loc_1d7e7: // 1b0c:2727
    al = memoryAGet(ds, bx);
    if (al == 0x06)
        goto loc_1d829;
    if (al == 0x10)
        goto loc_1d829;
    if (al == 0x20)
        goto loc_1d829;
    if (al == 0x22)
        goto loc_1d829;
    if (al == 0x0c)
        goto loc_1d829;
    if (al == 0x24)
        goto loc_1d829;
    if (al == 0x26)
        goto loc_1d829;
    if (al == 0x2a)
        goto loc_1d829;
    if (al == 0x0e)
        goto loc_1d829;
    if (al == 0x1c)
        goto loc_1d829;
    if (al == 0x2c)
        goto loc_1d829;
    if (al == 0x28)
        goto loc_1d829;
    if (al == 0x12)
        goto loc_1d829;
    if (al == 0x0a)
        goto loc_1d831;
    if (al == 0x04)
        goto loc_1d838;
    if (al != 0x02)
        goto loc_1d82b;
loc_1d829: // 1b0c:2769
    memoryASet(ds, bx, ah);
loc_1d82b: // 1b0c:276b
    bx += 0x000b;
    if (--cx)
        goto loc_1d7e7;
    return;
loc_1d831: // 1b0c:2771
    memoryASet16(ds, bx + 5, 0x0000);
    goto loc_1d82b;
loc_1d838: // 1b0c:2778
    memoryASet(ds, bx + 10, 0x01);
    goto loc_1d82b;
}
void sub_1d7e7() // 1b0c:2727
{
loc_1d7e7: // 1b0c:2727
    al = memoryAGet(ds, bx);
    if (al == 0x06)
        goto loc_1d829;
    if (al == 0x10)
        goto loc_1d829;
    if (al == 0x20)
        goto loc_1d829;
    if (al == 0x22)
        goto loc_1d829;
    if (al == 0x0c)
        goto loc_1d829;
    if (al == 0x24)
        goto loc_1d829;
    if (al == 0x26)
        goto loc_1d829;
    if (al == 0x2a)
        goto loc_1d829;
    if (al == 0x0e)
        goto loc_1d829;
    if (al == 0x1c)
        goto loc_1d829;
    if (al == 0x2c)
        goto loc_1d829;
    if (al == 0x28)
        goto loc_1d829;
    if (al == 0x12)
        goto loc_1d829;
    if (al == 0x0a)
        goto loc_1d831;
    if (al == 0x04)
        goto loc_1d838;
    if (al != 0x02)
        goto loc_1d82b;
loc_1d829: // 1b0c:2769
    memoryASet(ds, bx, ah);
loc_1d82b: // 1b0c:276b
    bx += 0x000b;
    if (--cx)
        goto loc_1d7e7;
    return;
loc_1d831: // 1b0c:2771
    memoryASet16(ds, bx + 5, 0x0000);
    goto loc_1d82b;
loc_1d838: // 1b0c:2778
    memoryASet(ds, bx + 10, 0x01);
    goto loc_1d82b;
}
void sub_1d83e() // 1b0c:277e
{
    si = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
    sub_1d877();
    si = 0x49f9;
    cl = memoryAGet(ds, 0x4988);
    if (cx == 0)
        goto loc_1d854;
    sub_1d877();
loc_1d854: // 1b0c:2794
    cl = memoryAGet(ds, 0x4985);
    if (cx == 0)
        return;
    si = 0x5291;
loc_1d85d: // 1b0c:279d
    if (memoryAGet(ds, si) == 0x06)
        goto loc_1d867;
    if (memoryAGet(ds, si) != 0x04)
        goto loc_1d871;
loc_1d867: // 1b0c:27a7
    di = memoryAGet16(ds, si + 1);
    if (bx != memoryAGet16(ds, di + 5))
        goto loc_1d871;
    memoryASet(ds, si, ch);
loc_1d871: // 1b0c:27b1
    si += 0x0003;
    if (--cx)
        goto loc_1d85d;
}
void sub_1d877() // 1b0c:27b7
{
loc_1d877: // 1b0c:27b7
    if (memoryAGet(ds, si) != 0x18)
        goto loc_1d884;
    if (memoryAGet16(ds, si + 5) != bx)
        goto loc_1d884;
    memoryASet(ds, si, 0x00);
loc_1d884: // 1b0c:27c4
    si += 0x000b;
    if (--cx)
        goto loc_1d877;
}
void sub_1d88a() // 1b0c:27ca
{
    sub_1d8f2();
    if (!(ah & 0x03))
        goto loc_1d8e6;
    if (!(ah & 0x0c))
        goto loc_1d8ec;
    sub_1d918();
    if (!flags.zero)
        goto loc_1d8b3;
    sub_1d8e6();
    goto loc_1d8ec;
    //   gap of 18 bytes
loc_1d8b3: // 1b0c:27f3
    ah &= 0x0c;
    cl &= 0x0c;
    if (ah == cl)
        goto loc_1d8e6;
    goto loc_1d8ec;
    //   gap of 39 bytes
loc_1d8e6: // 1b0c:2826
    push(ax);
    sub_1cf47();
    ax = pop();
    return;
loc_1d8ec: // 1b0c:282c
    push(ax);
    sub_1cf4d();
    ax = pop();
}
void sub_1d8a1() // 1b0c:27e1
{
    sub_1d8f2();
    if (!(ah & 0x03))
        goto loc_1d8e6;
    if (!(ah & 0x0c))
        goto loc_1d8ec;
    sub_1d918();
    if (flags.zero)
        goto loc_1d8bf;
    ah &= 0x0c;
    cl &= 0x0c;
    if (ah == cl)
        goto loc_1d8e6;
    goto loc_1d8ec;
loc_1d8bf: // 1b0c:27ff
    cl = memoryAGet(ds, bx + 1430);
    if ((char)ah >= (char)0x08)
        goto loc_1d8cc;
    cl = memoryAGet(ds, bx + 1404);
loc_1d8cc: // 1b0c:280c
    cl &= 0x0f;
    if (cl == 0)
        goto loc_1d8e6;
    cl = memoryAGet(ds, bx + 1418);
    if (!(ah & 0x01))
        goto loc_1d8de;
    cl = memoryAGet(ds, bx + 1416);
loc_1d8de: // 1b0c:281e
    cl &= 0x0f;
    if (cl == 0)
        goto loc_1d8ec;
    sub_1d8ec();
loc_1d8e6: // 1b0c:2826
    push(ax);
    sub_1cf47();
    ax = pop();
    return;
loc_1d8ec: // 1b0c:282c
    push(ax);
    sub_1cf4d();
    ax = pop();
}
void sub_1d8e6() // 1b0c:2826
{
    push(ax);
    sub_1cf47();
    ax = pop();
}
void sub_1d8ec() // 1b0c:282c
{
    push(ax);
    sub_1cf4d();
    ax = pop();
}
void sub_1d8f2() // 1b0c:2832
{
    ah = 0;
    dl &= 0x0f;
    if (dl > 0x02)
        goto loc_1d8ff;
    ah |= 0x01;
loc_1d8ff: // 1b0c:283f
    if (dl < 0x0d)
        goto loc_1d907;
    ah |= 0x02;
loc_1d907: // 1b0c:2847
    if (dh > 0x02)
        goto loc_1d90f;
    ah |= 0x04;
loc_1d90f: // 1b0c:284f
    if (dh < 0x05)
        return;
    ah |= 0x08;
}
void sub_1d918() // 1b0c:2858
{
    cl = 0x0a;
    if (memoryAGet(ds, si + 8) & 0x80)
        goto loc_1d922;
    cl = 0x06;
loc_1d922: // 1b0c:2862
    if (memoryAGet(ds, si + 6) & 0x80)
        goto loc_1d92e;
    cl &= 0x0c;
    cl |= 0x01;
loc_1d92e: // 1b0c:286e
    flags.zero = ah == cl;
}
void sub_1d931() // 1b0c:2871
{
    if (!(ch & 0x10))
        return;
    if (memoryAGet(ds, 0x48eb) >= 0x04)
        return;
    memoryASet(ds, 0x48eb, memoryAGet(ds, 0x48eb) + 1);
    push(bx);
    bl = memoryAGet(ds, di + 2);
    bl &= 0xf8;
    dl = memoryAGet(ds, di + 4);
    goto loc_1d961;
    //   gap of 20 bytes
loc_1d961: // 1b0c:28a1
    memoryASet(ds, 0x58ad, bl);
    memoryASet(ds, 0x58af, dl);
    sub_1d97d();
    memoryASet(ds, 0x58b4, ch);
    bx = 0x58ab;
    sub_1c939();
    bx = pop();
}
void sub_1d94d() // 1b0c:288d
{
    if (!(ch & 0x10))
        return;
    if (memoryAGet(ds, 0x48eb) >= 0x04)
        return;
    memoryASet(ds, 0x48eb, memoryAGet(ds, 0x48eb) + 1);
    push(bx);
    sub_1d5a8();
    memoryASet(ds, 0x58ad, bl);
    memoryASet(ds, 0x58af, dl);
    sub_1d97d();
    memoryASet(ds, 0x58b4, ch);
    bx = 0x58ab;
    sub_1c939();
    bx = pop();
}
void sub_1d97d() // 1b0c:28bd
{
loc_1d97d: // 1b0c:28bd
    sub_1bce1();
    di = 0x48f5;
    bx = 0;
    ch = bh;
loc_1d987: // 1b0c:28c7
    ch += 0x08;
    bl += 0x02;
    di++;
    if (al > memoryAGet(ds, di))
        goto loc_1d987;
    if (ch == 0x08)
        goto loc_1d9a5;
    if (ch == 0x68)
        goto loc_1d9ab;
loc_1d99c: // 1b0c:28dc
    sub_1d9f8();
    if (flags.carry)
        goto loc_1d97d;
    stop(/*2*/); // 1b0c:28e1 jmp word ptr [bx + 0x4901] - jump Indirect memoryAGet16(ds, bx + 18689)
loc_1d9a5: // 1b0c:28e5
    bl = 0x1a;
    ch = 0x68;
    goto loc_1d99c;
loc_1d9ab: // 1b0c:28eb
    bl = 0x02;
    ch = 0x08;
    goto loc_1d99c;
}
void sub_1d9f8() // 1b0c:2938
{
    cl = 0x04;
    di = 0x48f2;
loc_1d9fd: // 1b0c:293d
    if (ch == memoryAGet(ds, di))
        goto loc_1da19;
    di++;
    cl--;
    if (cl != 0)
        goto loc_1d9fd;
    cl = 0x04;
    di = 0x48f2;
loc_1da0b: // 1b0c:294b
    if (memoryAGet(ds, di) == 0x00)
        goto loc_1da15;
    di++;
    cl--;
    if (cl != 0)
        goto loc_1da0b;
loc_1da15: // 1b0c:2955
    memoryASet(ds, di, ch);
    flags.carry = false;
    return;
loc_1da19: // 1b0c:2959
    flags.carry = true;
}
void sub_1da1b() // 1b0c:295b
{
    bl = 0x2f;
loc_1da1d: // 1b0c:295d
    bl++;
    tl = al;
    al -= 0x0a;
    if ((char)tl - (char)0x0a >= 0)
        goto loc_1da1d;
    al += 0x0a;
    if (bl != 0x30)
        goto loc_1da2c;
    bl = 0x20;
loc_1da2c: // 1b0c:296c
    memoryASet(ds, 0x48c2, bl);
    al += 0x30;
    memoryASet(ds, 0x48c3, al);
}
void sub_1da36() // 1b0c:2976
{
    di = 0x495d;
    push(di);
    sub_1da58();
    cl = al;
    sub_1da58();
    cl = ah;
    sub_1da58();
    di = pop();
    cx = 0x0006;
    bx = 0x2030;
loc_1da4e: // 1b0c:298e
    if (bl != memoryAGet(ds, di))
        return;
    memoryASet(ds, di, bh);
    di++;
    if (--cx)
        goto loc_1da4e;
}
void sub_1da58() // 1b0c:2998
{
    push(cx);
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    cl >>= 1;
    sub_1da68();
    cx = pop();
    cl &= 0x0f;
    cl += 0x30;
    memoryASet(ds, di, cl);
    di++;
}
void sub_1da68() // 1b0c:29a8
{
    cl += 0x30;
    memoryASet(ds, di, cl);
    di++;
}
void sub_1da6f() // 1b0c:29af
{
    push(si);
    si = 0x4d5e;
    cx = memoryAGet16(ds, 0x48e3);
    cx++;
loc_1da78: // 1b0c:29b8
    if (memoryAGet(ds, si) != 0x06)
        goto loc_1da86;
    if (memoryAGet16(ds, si + 5) != 0x0000)
        goto loc_1da86;
    sub_1cebd();
loc_1da86: // 1b0c:29c6
    si += 0x000b;
    if (--cx)
        goto loc_1da78;
    si = pop();
}
void sub_1da8d() // 1b0c:29cd
{
    sub_1da6f();
    ax = 0x0100;
    sub_1b130();
    bl = memoryAGet(ds, si + 9);
    bl >>= 1;
    bl >>= 1;
    bl &= 0xfe;
    bh = 0;
    if (bl >= 0x1c)
        goto loc_1daab;
    stop(/*2*/); // 1b0c:29e7 jmp word ptr [bx + 0x491b] - jump Indirect memoryAGet16(ds, bx + 18715)
loc_1daab: // 1b0c:29eb
    if (memoryAGet(ds, 0x48ea) > 0x01)
        goto loc_1dad2;
    if (memoryAGet(ds, 0x48cf) == 0x0f)
        goto loc_1dacd;
    sub_1bce1();
    if (al < 0x50)
        goto loc_1dad2;
    if (al < 0xa0)
        goto loc_1dacd;
    sub_1dacd();
    memoryASet(ds, 0x48e9, 0x01);
    return;
loc_1dacd: // 1b0c:2a0d
    al = memoryAGet(ds, 0x586c);
    goto loc_1dae5;
loc_1dad2: // 1b0c:2a12
    sub_1db56();
    memoryASet(ds, 0x4808, 0x01);
    return;
    //   gap of 10 bytes
loc_1dae5: // 1b0c:2a25
    memoryASet(ds, 0x592e, al);
    di = memoryAGet16(ds, 0x4d5f);
    bp = memoryAGet16(ds, 0x4d61);
    cx = memoryAGet16(ds, 0x4d63);
    ax = memoryAGet16(ds, 0x4d65);
    memoryASet16(ds, 0x5925, di);
    memoryASet16(ds, 0x5927, bp);
    memoryASet16(ds, 0x5929, cx);
    memoryASet16(ds, 0x592b, ax);
    bx = 0x5924;
    sub_1c939();
}
void sub_1dacd() // 1b0c:2a0d
{
    al = memoryAGet(ds, 0x586c);
    goto loc_1dae5;
    //   gap of 19 bytes
loc_1dae5: // 1b0c:2a25
    memoryASet(ds, 0x592e, al);
    di = memoryAGet16(ds, 0x4d5f);
    bp = memoryAGet16(ds, 0x4d61);
    cx = memoryAGet16(ds, 0x4d63);
    ax = memoryAGet16(ds, 0x4d65);
    memoryASet16(ds, 0x5925, di);
    memoryASet16(ds, 0x5927, bp);
    memoryASet16(ds, 0x5929, cx);
    memoryASet16(ds, 0x592b, ax);
    bx = 0x5924;
    sub_1c939();
}
void sub_1db0d() // 1b0c:2a4d
{
    bx = 0x2a52;
    goto loc_1db59;
    //   gap of 71 bytes
loc_1db59: // 1b0c:2a99
    di = 0x48cf;
    cx = 0x0005;
loc_1db5f: // 1b0c:2a9f
    al = memoryAGet(cs, bx);
    memoryASet(ds, di, al);
    di++;
    bx++;
    if (--cx)
        goto loc_1db5f;
    memoryASet16(ds, di, cx);
    memoryASet16(ds, di + 2, cx);
    memoryASet(ds, 0x4808, cl);
    memoryASet(ds, 0x48e9, cl);
}
void sub_1db56() // 1b0c:2a96
{
    bx = 0x2ab6;
    di = 0x48cf;
    cx = 0x0005;
loc_1db5f: // 1b0c:2a9f
    al = memoryAGet(cs, bx);
    memoryASet(ds, di, al);
    di++;
    bx++;
    if (--cx)
        goto loc_1db5f;
    memoryASet16(ds, di, cx);
    memoryASet16(ds, di + 2, cx);
    memoryASet(ds, 0x4808, cl);
    memoryASet(ds, 0x48e9, cl);
}
void sub_1dbe2() // 1b0c:2b22
{
    bx = 0x020b;
    sub_1f0d2();
    memoryASet(ds, 0x0497, memoryAGet(ds, 0x0497) + 1);
    sub_1d6f2();
    cl = memoryAGet(ds, 0x0497);
    if (cl > 0x06)
        return;
    push(si);
    ch = 0;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx -= 0x0016;
    bx = 0x00c8;
    dx = 0x00c3;
    push(bx);
    push(cx);
    push(dx);
    sub_1fb4c();
    dx = pop();
    cx = pop();
    bx = pop();
    sub_1fb46();
    si = pop();
}
void sub_1dbef() // 1b0c:2b2f
{
    cl = memoryAGet(ds, 0x0497);
    if (cl > 0x06)
        return;
    push(si);
    ch = 0;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx -= 0x0016;
    bx = 0x00c8;
    dx = 0x00c3;
    push(bx);
    push(cx);
    push(dx);
    sub_1fb4c();
    dx = pop();
    cx = pop();
    bx = pop();
    sub_1fb46();
    si = pop();
}
void sub_1dc1a() // 1b0c:2b5a
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    sub_1dc26();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1dc26() // 1b0c:2b66
{
    memoryASet(ds, 0x48e7, memoryAGet(ds, 0x48e7) - 1);
    if (memoryAGet(ds, 0x48e7) != 0)
        return;
    bp = 0x0009;
    if (memoryAGet(ds, 0x48e8) >= 0x28)
        goto loc_1dc3e;
    memoryASet(ds, 0x48e8, memoryAGet(ds, 0x48e8) + 0x04);
    bp = 0x0020;
loc_1dc3e: // 1b0c:2b7e
    memoryASet(ds, 0x48e7, 0x28);
    bx = 0x4d5e;
    cx = memoryAGet16(ds, 0x48e3);
    cx++;
loc_1dc4b: // 1b0c:2b8b
    if (memoryAGet(ds, bx) != 0x06)
        goto loc_1dc6a;
    dx = bp;
    if (!(memoryAGet(ds, bx + 6) & 0x80))
        goto loc_1dc5a;
    dx = -dx;
loc_1dc5a: // 1b0c:2b9a
    memoryASet16(ds, bx + 5, memoryAGet16(ds, bx + 5) + dx);
    dx = bp;
    if (!(memoryAGet(ds, bx + 8) & 0x80))
        goto loc_1dc67;
    dx = -dx;
loc_1dc67: // 1b0c:2ba7
    memoryASet16(ds, bx + 7, memoryAGet16(ds, bx + 7) + dx);
loc_1dc6a: // 1b0c:2baa
    bx += 0x000b;
    if (--cx)
        goto loc_1dc4b;
}
void sub_1dc70() // 1b0c:2bb0
{
    di = 0x4d5e;
    cx = memoryAGet16(ds, 0x48e3);
    cx++;
    bh = 0;
loc_1dc7a: // 1b0c:2bba
    if (memoryAGet(ds, di) == 0x06)
        goto loc_1dc89;
    di += 0x000b;
    if (--cx)
        goto loc_1dc7a;
loc_1dc84: // 1b0c:2bc4
    bl = memoryAGet(ds, 0x48d8);
    return;
loc_1dc89: // 1b0c:2bc9
    cl = 0;
    sub_1bce1();
    if (al > 0x08)
        goto loc_1dc94;
    cl++;
loc_1dc94: // 1b0c:2bd4
    if (memoryAGet(ds, di + 4) > 0xb0)
        goto loc_1dc84;
    bl = memoryAGet(ds, di + 2);
    bl -= 0x0c;
    if (bl < 0xf0)
        return;
    bl = 0x04;
}
void sub_1dca8() // 1b0c:2be8
{
    if (memoryAGet(ds, 0x48e0) == 0x00)
        goto loc_1dcc0;
    bx = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1dcb6: // 1b0c:2bf6
    if (memoryAGet(ds, bx) == 0x1e)
        goto loc_1dcc1;
    bx += 0x000b;
    if (--cx)
        goto loc_1dcb6;
loc_1dcc0: // 1b0c:2c00
    return;
loc_1dcc1: // 1b0c:2c01
    memoryASet(ds, bx, 0x00);
}
void sub_1dcc5() // 1b0c:2c05
{
    bx = 0x0203;
    sub_1f0d2();
    memoryASet(ds, di + 10, 0x14);
    memoryASet(ds, di + 1, 0x05);
}
void sub_1dcd4() // 1b0c:2c14
{
    push(si);
    si = memoryAGet16(ds, si + 1);
    goto loc_1dceb;
    //   gap of 17 bytes
loc_1dceb: // 1b0c:2c2b
    cx = memoryAGet16(ds, si + 1);
    dx = memoryAGet16(ds, si + 3);
    bl = memoryAGet(ds, si + 9);
    bh = 0;
    bl += 0x0a;
    sub_1fb4c();
    si = pop();
}
void sub_1dcda() // 1b0c:2c1a
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if (tl > al)
        return;
    push(si);
    memoryASet(ds, si, 0x00);
    bx = si;
    sub_1d6cd();
    cx = memoryAGet16(ds, si + 1);
    dx = memoryAGet16(ds, si + 3);
    bl = memoryAGet(ds, si + 9);
    bh = 0;
    bl += 0x0a;
    sub_1fb4c();
    si = pop();
}
void sub_1dcfe() // 1b0c:2c3e
{
    push(si);
    di = memoryAGet16(ds, si + 1);
    cx = memoryAGet16(ds, di + 1);
    dx = memoryAGet16(ds, di + 3);
    bx = 0x000f;
    sub_1fb4c();
    si = pop();
}
void sub_1dd10() // 1b0c:2c50
{
    if (memoryAGet(ds, bx + 1183) == 0x01)
        return;
    push(cx);
    push(bx);
    push(ax);
    push(si);
    if (!(ch & 0x20))
        goto loc_1dd2c;
    si = bx;
    sub_1d5a8();
    di = bx;
    sub_1de68();
    goto loc_1dd59;
loc_1dd2c: // 1b0c:2c6c
    memoryASet16(ds, 0x58f2, bx);
    sub_1d5a8();
    cl = bl;
    ch = 0;
    dh = ch;
    memoryASet16(ds, 0x58ee, cx);
    memoryASet16(ds, 0x58f0, dx);
    memoryASet(ds, 0x58f6, al);
    bx = 0x000f;
    sub_1fb4c();
    bx = 0x58ed;
    sub_1c939();
    sub_1d6d1();
    bx = 0x0203;
    sub_1f0d2();
loc_1dd59: // 1b0c:2c99
    si = pop();
    ax = pop();
    bx = pop();
    cx = pop();
}
void sub_1dd5e() // 1b0c:2c9e
{
    si = 0x0589;
    cx = 0x0012;
    dx = 0x000a;
loc_1dd67: // 1b0c:2ca7
    push(cx);
    cx = 0x000d;
    di = 0x0008;
loc_1dd6e: // 1b0c:2cae
    push(cx);
    bh = 0x00;
    bl = memoryAGet(ds, si);
    bl &= 0x0f;
    if (bl == 0)
        goto loc_1dd8b;
    if (bl > 0x03)
        goto loc_1dd8b;
    sub_1dda7();
    cx = di;
    push(di);
    push(si);
    push(dx);
    sub_1fb46();
    dx = pop();
    si = pop();
    di = pop();
loc_1dd8b: // 1b0c:2ccb
    si++;
    cx = pop();
    di += 0x0010;
    if (--cx)
        goto loc_1dd6e;
    cx = pop();
    dx += 0x0007;
    if (--cx)
        goto loc_1dd67;
}
void sub_1dd99() // 1b0c:2cd9
{
    memoryASet(ds, 0x48e1, 0x01);
    sub_1dd5e();
    memoryASet(ds, 0x48e1, 0x00);
}
void sub_1dda7() // 1b0c:2ce7
{
    if (memoryAGet(ds, 0x48e1) == 0x00)
        goto loc_1ddb2;
    bl += 0x0a;
    return;
loc_1ddb2: // 1b0c:2cf2
    bl = 0x0f;
}
void sub_1ddb5() // 1b0c:2cf5
{
    sub_1db0d();
    memoryASet(ds, 0x48d8, 0x64);
    memoryASet(ds, 0x48d7, 0x14);
    bx = 0x00d9;
    cl = 0x64;
    sub_1fb89();
loc_1ddca: // 1b0c:2d0a
    sub_1ccfc();
    sub_1f961();
    sub_1c46f();
    sync();
//    if (memoryAGet(ds, 0x48d4) != 0x02)
//        goto loc_1ddca;
//    al = memoryAGet(ds, 0x5870);
//    if (memoryAGet(ds, 0x48d7) > al)
//        goto loc_1ddca;
    memoryASet(ds, 0x48cf, 0x03);
    sub_1ccfc();
}
void sub_1ddec() // 1b0c:2d2c
{
    al = memoryAGet(ds, 0x0493);
    bx = 0x592f;
    if (al == 0x10)
        goto loc_1de00;
    bx = 0x5934;
    if (al == 0x21)
        goto loc_1de00;
    bx = 0x5871;
loc_1de00: // 1b0c:2d40
    sub_1c939();
    si = 0x5892;
    di = 0x4d5e;
    sub_1c912();
    bx = 0x587c;
    sub_1c939();
    memoryASet(ds, 0x48ea, 0x01);
    ax = 0;
    memoryASet(ds, 0x48da, al);
    memoryASet16(ds, 0x48f2, ax);
    memoryASet16(ds, 0x48f4, ax);
    memoryASet(ds, 0x48e9, al);
    memoryASet(ds, 0x4937, al);
    memoryASet(ds, 0x4938, al);
    memoryASet(ds, 0x48e7, 0x28);
}
void sub_1de31() // 1b0c:2d71
{
    si = 0;
    cx = 0x0012;
    dl = 0x0a;
    bp = 0x0000;
loc_1de3b: // 1b0c:2d7b
    push(cx);
    cx = 0x000d;
    di = 0x0008;
loc_1de42: // 1b0c:2d82
    push(cx);
    if (!(memoryAGet(ds, si + 1417) & 0x20))
        goto loc_1de57;
    al = memoryAGet(ds, si + 1417);
    al &= 0x0f;
    if (al <= 0x03)
        goto loc_1de57;
    sub_1de68();
loc_1de57: // 1b0c:2d97
    si++;
    cx = pop();
    di += 0x0010;
    if (--cx)
        goto loc_1de42;
    cx = pop();
    bp += 0x000d;
    dl += 0x07;
    if (--cx)
        goto loc_1de3b;
}
void sub_1de68() // 1b0c:2da8
{
    al = memoryAGet(ds, si + 1417);
    memoryASet(ds, si + 1417, 0x00);
    memoryASet(ds, 0x58a9, al);
    memoryASet(ds, 0x58a1, al);
    ax = di;
    memoryASet(ds, 0x58a2, al);
    memoryASet(ds, 0x58a4, dl);
    memoryASet16(ds, 0x58a7, si);
    al = memoryAGet(ds, si + 1183);
    memoryASet(ds, 0x58a8, al);
    ax = bp;
    memoryASet(ds, 0x58a3, al);
    bx = 0x58a0;
    push(dx);
    push(di);
    sub_1c939();
    bx = si;
    sub_1d158();
    di = pop();
    dx = pop();
}
void sub_1dea0() // 1b0c:2de0
{
    bx = 0x4d69;
    ah = 0;
    cx = memoryAGet16(ds, 0x48e3);
loc_1dea9: // 1b0c:2de9
    al = memoryAGet(ds, bx);
    if (al == 0x1a)
        goto loc_1dece;
    if (al != 0x0a)
        goto loc_1dec8;
    al = memoryAGet(ds, bx + 7);
    di = ax;
    al = memoryAGet(ds, bx + 9);
    al |= 0x20;
    memoryASet(ds, di + 1417, al);
loc_1dec1: // 1b0c:2e01
    al = memoryAGet(ds, 0x0496);
    memoryASet(ds, di + 1183, al);
loc_1dec8: // 1b0c:2e08
    bx += 0x000b;
    if (--cx)
        goto loc_1dea9;
    return;
loc_1dece: // 1b0c:2e0e
    di = memoryAGet16(ds, bx + 7);
    memoryASet(ds, di + 1417, 0x02);
    goto loc_1dec1;
}
void sub_1ded8() // 1b0c:2e18
{
    if (memoryAGet(ds, 0x48e6) == 0x00)
        return;
    memoryASet(ds, 0x48e6, memoryAGet(ds, 0x48e6) - 1);
    di = 0x4d69;
    ah = 0;
    cx = memoryAGet16(ds, 0x48e3);
loc_1deec: // 1b0c:2e2c
    if (memoryAGet(ds, di) != 0x0a)
        goto loc_1df0b;
    push(cx);
    bh = ch;
    dh = ch;
    bl = memoryAGet(ds, di + 1);
    bl &= 0x0f;
    bl += 0x0a;
    cl = memoryAGet(ds, di + 2);
    dl = memoryAGet(ds, di + 4);
    push(di);
    sub_1fb4c();
    di = pop();
    cx = pop();
loc_1df0b: // 1b0c:2e4b
    di += 0x000b;
    if (--cx)
        goto loc_1deec;
}
void sub_1df25() // 1b0c:2e65
{
    al = memoryAGet(ds, si + 3);
    goto loc_1df2d;
    //   gap of 3 bytes
loc_1df2d: // 1b0c:2e6d
    memoryASet(ds, 0x58ba, al);
    push(bx);
    al = memoryAGet(ds, si + 1);
    al += 0x08;
    memoryASet(ds, 0x58b8, al);
    bx = memoryAGet16(ds, 0x48ee);
    bx++;
    if (bl < memoryAGet(ds, 0x48ed))
        goto loc_1df46;
    bx = 0;
loc_1df46: // 1b0c:2e86
    memoryASet16(ds, 0x48ee, bx);
    bl = memoryAGet(ds, bx + 2638);
    bl--;
    memoryASet(ds, 0x58bd, bl);
    al = memoryAGet(ds, bx + 18800);
    memoryASet(ds, 0x58be, al);
    sub_1bce1();
    ah = 0x0f;
    if (bl != 0x04)
        goto loc_1df67;
    ah = 0x7f;
loc_1df67: // 1b0c:2ea7
    al &= ah;
    memoryASet(ds, 0x58bb, al);
    bx = 0x58b6;
    sub_1c939();
    memoryASet(ds, 0x48ec, memoryAGet(ds, 0x48ec) + 1);
    bx = pop();
}
void sub_1df2b() // 1b0c:2e6b
{
    al = 0x0b;
    memoryASet(ds, 0x58ba, al);
    push(bx);
    al = memoryAGet(ds, si + 1);
    al += 0x08;
    memoryASet(ds, 0x58b8, al);
    bx = memoryAGet16(ds, 0x48ee);
    bx++;
    if (bl < memoryAGet(ds, 0x48ed))
        goto loc_1df46;
    bx = 0;
loc_1df46: // 1b0c:2e86
    memoryASet16(ds, 0x48ee, bx);
    bl = memoryAGet(ds, bx + 2638);
    bl--;
    memoryASet(ds, 0x58bd, bl);
    al = memoryAGet(ds, bx + 18800);
    memoryASet(ds, 0x58be, al);
    sub_1bce1();
    ah = 0x0f;
    if (bl != 0x04)
        goto loc_1df67;
    ah = 0x7f;
loc_1df67: // 1b0c:2ea7
    al &= ah;
    memoryASet(ds, 0x58bb, al);
    bx = 0x58b6;
    sub_1c939();
    memoryASet(ds, 0x48ec, memoryAGet(ds, 0x48ec) + 1);
    bx = pop();
}
void sub_1df78() // 1b0c:2eb8
{
    push(bx);
    cl = bl;
    cl += 0x05;
    bx = 0x58c1;
    memoryASet(ds, bx + 2, cl);
    push(cx);
    sub_1c939();
    cx = pop();
    cl += 0x13;
    bx = 0x58c1;
    memoryASet(ds, bx + 2, cl);
    sub_1c939();
    bx = 0x0201;
    sub_1f0d2();
    bx = pop();
}
void sub_1df9d() // 1b0c:2edd
{
    ax = memoryAGet16(ds, 0x48f0);
    tx = memoryAGet16(ds, si + 5);
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - ax);
    if (tx > ax)
        return;
    bx = memoryAGet16(ds, si + 7);
    push(bx);
    sub_1dfc5();
    bx = pop();
    if (flags.carry)
        goto loc_1dfbf;
    memoryASet(ds, bx + 1417, 0x02);
    al = memoryAGet(ds, 0x0496);
    memoryASet(ds, bx + 1183, al);
    sub_1dcda();
    return;
loc_1dfbf: // 1b0c:2eff
    memoryASet16(ds, si + 5, 0x003c);
}
void sub_1dfc5() // 1b0c:2f05
{
    sub_1d5a8();
    di = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1dfcf: // 1b0c:2f0f
    al = memoryAGet(ds, di);
    if (al == 0x0a)
        goto loc_1dff9;
    if (al != 0x0e)
        goto loc_1e013;
    al = memoryAGet(ds, di + 4);
    al -= 0x07;
    if (al > dl)
        goto loc_1e013;
    al += 0x17;
    if (al < dl)
        goto loc_1e013;
    al = memoryAGet(ds, di + 2);
    al -= 0x10;
    if (al > bl)
        goto loc_1e013;
    al += 0x20;
    if (al < bl)
        goto loc_1e013;
    goto loc_1e01a;
loc_1dff9: // 1b0c:2f39
    if (dl != memoryAGet(ds, di + 4))
        goto loc_1e013;
    al = memoryAGet(ds, di + 2);
    if (bl < al)
        goto loc_1e00d;
    al += 0x10;
    if (bl > al)
        goto loc_1e013;
    goto loc_1e01a;
loc_1e00d: // 1b0c:2f4d
    al -= 0x10;
    if (bl > al)
        goto loc_1e01a;
loc_1e013: // 1b0c:2f53
    di += 0x000b;
    if (--cx)
        goto loc_1dfcf;
    flags.carry = false;
    return;
loc_1e01a: // 1b0c:2f5a
    flags.carry = true;
}
void sub_1e01c() // 1b0c:2f5c
{
    push(si);
    if (memoryAGet(ds, 0x48d8) < 0xba)
        goto loc_1e029;
    memoryASet(ds, 0x48d8, 0xba);
loc_1e029: // 1b0c:2f69
    memoryASet(ds, 0x48e6, 0x02);
    bx = 0x0206;
    sub_1f0d2();
    sub_1fb42();
    sub_1ded8();
    sub_1e1da();
    sub_1fb2b();
    sub_1fb42();
    sub_1ded8();
    bx = 0x00cc;
    ch = 0;
    cl = memoryAGet(ds, 0x48d8);
    dx = 0x00bb;
    sub_1fb89();
    sub_1fb46();
    cx = 0x0003;
    bx = 0x00db;
loc_1e05e: // 1b0c:2f9e
    push(cx);
    push(bx);
    cx = 0x001e;
loc_1e063: // 1b0c:2fa3
    sub_1f961();
    if (--cx)
        goto loc_1e063;
    cl = memoryAGet(ds, 0x48d8);
    dx = 0x00bb;
    sub_1fb85();
    sub_1fb46();
    bx = pop();
    cx = pop();
    bx--;
    if (--cx)
        goto loc_1e05e;
    cx = 0x001e;
loc_1e07d: // 1b0c:2fbd
    sub_1f961();
    if (--cx)
        goto loc_1e07d;
    cl = memoryAGet(ds, 0x48d8);
    dx = 0x00bb;
    sub_1fb85();
    memoryASet(ds, 0x0a4c, 0x02);
    si = pop();
}
void sub_1e093() // 1b0c:2fd3
{
    sub_1e0ca();
    cx = 0x0058;
    dx = 0x0092;
    sub_1fb46();
    bx = 0x0058;
    cx = 0x00a2;
    al = 0x0f;
    si = 0x48c6;
    sub_1fb79();
    al = 0x0f;
    bx = 0x0058;
    cx = 0x00aa;
    si = 0x48bc;
    sub_1fb79();
    al = 0x0f;
    bx = 0x00f0;
    cx = 0x0096;
    si = 0x48bc;
    sub_1fb75();
}
void sub_1e0ca() // 1b0c:300a
{
    al = memoryAGet(ds, 0x0a49);
    memoryASet(ds, 0x48cd, al);
    sub_1e0fa();
    ah = 0;
    if (al == 0x00)
        goto loc_1e0f4;
    if (al == 0x11)
        goto loc_1e0f4;
    ah++;
    if (al == 0x10)
        goto loc_1e0f4;
    if (al == 0x21)
        goto loc_1e0f4;
    ah++;
    if (al < 0x10)
        goto loc_1e0f0;
    ah += 0x02;
loc_1e0f0: // 1b0c:3030
    ah += memoryAGet(ds, 0x0494);
loc_1e0f4: // 1b0c:3034
    bx = 0x00be;
    bl += ah;
}
void sub_1e0fa() // 1b0c:303a
{
    al = memoryAGet(ds, 0x0493);
    push(ax);
    al++;
    sub_1da1b();
    ax = pop();
}
void sub_1e105() // 1b0c:3045
{
    sub_1fb2b();
    sub_1fb2f();
    sub_1ccfc();
}
void sub_1e12b() // 1b0c:306b
{
    cl = memoryAGet(ds, 0x4988);
    ch = 0;
    if (cx == 0)
        goto loc_1e139;
    si = 0x49f9;
    sub_1e140();
loc_1e139: // 1b0c:3079
    si = 0x4d69;
    cx = memoryAGet16(ds, 0x48e3);
loc_1e140: // 1b0c:3080
    if (memoryAGet(ds, si) != 0x1e)
        goto loc_1e148;
    memoryASet(ds, si, 0x00);
loc_1e148: // 1b0c:3088
    si += 0x000b;
    if (--cx)
        goto loc_1e140;
}
void sub_1e140() // 1b0c:3080
{
loc_1e140: // 1b0c:3080
    if (memoryAGet(ds, si) != 0x1e)
        goto loc_1e148;
    memoryASet(ds, si, 0x00);
loc_1e148: // 1b0c:3088
    si += 0x000b;
    if (--cx)
        goto loc_1e140;
}
void sub_1e14e() // 1b0c:308e
{
    memoryASet(ds, 0x0a4c, 0x01);
    bx = 0x0210;
    sub_1f0d2();
    sub_1e1da();
    memoryASet(ds, 0x48e6, 0x02);
    bx = 0x0003;
    sub_1ce35();
    cx = 0x0028;
    if (memoryAGet(ds, 0x48d8) < 0x64)
        goto loc_1e177;
    cl = 0xe0;
    cl -= memoryAGet(ds, 0x48d8);
loc_1e177: // 1b0c:30b7
    push(cx);
    dx = 0x00bb;
    cl = memoryAGet(ds, 0x48dd);
    cl += memoryAGet(ds, 0x48d8);
    memoryASet(ds, 0x48d8, cl);
    if (cl < 0xe6)
        goto loc_1e1af;
    if (memoryAGet(ds, 0x048f) == 0x07)
        goto loc_1e1d7;
    al = 0xfe;
    if (memoryAGet(ds, 0x048f) == 0x04)
        goto loc_1e1a7;
    al = 0xfc;
    if (memoryAGet(ds, 0x048f) == 0x09)
        goto loc_1e1a7;
    al = 0xff;
loc_1e1a7: // 1b0c:30e7
    dl += al;
    ch = 0xff;
    cx += 0x0140;
loc_1e1af: // 1b0c:30ef
    bx = 0x00cc;
    sub_1fb3b();
    sub_1fb4c();
    bx = 0x000d;
    cx = 0x00e0;
    dx = 0x00a1;
    sub_1fb52();
    memoryASet(cs, 0x325a, 0x00);
    sub_1c750();
    sub_1f961();
    sub_1f961();
    cx = pop();
    if (--cx)
        goto loc_1e177;
loc_1e1d6: // 1b0c:3116
    return;
loc_1e1d7: // 1b0c:3117
    cx = pop();
    goto loc_1e1d6;
}
void sub_1e1da() // 1b0c:311a
{
    dl = 0;
    sub_1fb90();
    sub_1fb85();
    if (memoryAGet(ds, 0x0493) == 0x10)
        goto loc_1e1f1;
    if (memoryAGet(ds, 0x0493) == 0x21)
        goto loc_1e1f1;
    return;
loc_1e1f1: // 1b0c:3131
    sub_1f969();
    al = 0x00;
    goto loc_1fb9b;
    //   gap of 6562 bytes
loc_1fb9b: // 1b0c:4adb
    stop(/*2*/); // 1b0c:4adb jmp word ptr [0x6413] - jump Indirect memoryAGet16(ds, 0x6413)
}
void sub_1e1f9() // 1b0c:3139
{
    ax = memoryAGet16(ds, si + 1);
    ax += memoryAGet16(ds, 0x48f0);
    if (ax < memoryAGet16(ds, si + 3))
        goto loc_1e20d;
    bx = 0x5939;
    sub_1c939();
    ax = 0;
loc_1e20d: // 1b0c:314d
    memoryASet16(ds, si + 1, ax);
}
void sub_1e211() // 1b0c:3151
{
    goto loc_1e211;
loc_1e208: // 1b0c:3148
    sub_1c939();
    ax = 0;
loc_1e20d: // 1b0c:314d
    memoryASet16(ds, si + 1, ax);
    return;
loc_1e211: // 1b0c:3151
    ax = memoryAGet16(ds, si + 1);
    ax += memoryAGet16(ds, 0x48f0);
    if (ax < memoryAGet16(ds, si + 3))
        goto loc_1e20d;
loc_1e21d: // 1b0c:315d
    sub_1bce1();
    di = 0x4939;
    ah = 0x10;
    cx = 0x0004;
loc_1e228: // 1b0c:3168
    ah >>= 1;
    if (al <= memoryAGet(ds, di))
        goto loc_1e233;
    di += 0x0005;
    if (--cx)
        goto loc_1e228;
loc_1e233: // 1b0c:3173
    if (memoryAGet(ds, 0x4937) & ah)
        goto loc_1e21d;
    memoryASet(ds, 0x4937, memoryAGet(ds, 0x4937) | ah);
    ah ^= 0xff;
    memoryASet(ds, 0x5955, ah);
    ax = memoryAGet16(ds, di + 1);
    dx = memoryAGet16(ds, di + 3);
    memoryASet(ds, 0x5951, al);
    memoryASet(ds, 0x5953, ah);
    memoryASet(ds, 0x5950, dl);
    memoryASet(ds, 0x5952, dh);
    cl <<= 1;
    cl <<= 1;
    memoryASet(ds, 0x5954, cl);
    bx = 0x594f;
    goto loc_1e208;
}
void sub_1e266() // 1b0c:31a6
{
    al = memoryAGet(ds, 0x48ec);
    if (al >= memoryAGet(ds, 0x48ed))
        return;
    ax = memoryAGet16(ds, si + 1);
    ax += memoryAGet16(ds, 0x48f0);
    if (ax < memoryAGet16(ds, si + 5))
        goto loc_1e2a3;
    al = memoryAGet(ds, 0x058b);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2a1;
    al = memoryAGet(ds, 0x058c);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2a1;
    al = memoryAGet(ds, 0x0598);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2a1;
    al = memoryAGet(ds, 0x0599);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2a1;
    bx = 0x5903;
    memoryASet(ds, bx + 1, 0x28);
    sub_1c939();
loc_1e2a1: // 1b0c:31e1
    ax = 0;
loc_1e2a3: // 1b0c:31e3
    memoryASet16(ds, si + 1, ax);
    ax = memoryAGet16(ds, si + 3);
    ax += memoryAGet16(ds, 0x48f0);
    if (ax < memoryAGet16(ds, si + 7))
        goto loc_1e2da;
    al = memoryAGet(ds, 0x0592);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2d8;
    al = memoryAGet(ds, 0x0593);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2d8;
    al = memoryAGet(ds, 0x059f);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2d8;
    al = memoryAGet(ds, 0x05a0);
    al &= 0x0f;
    if (al != 0)
        goto loc_1e2d8;
    bx = 0x5903;
    memoryASet(ds, bx + 1, 0xa0);
    sub_1c939();
loc_1e2d8: // 1b0c:3218
    ax = 0;
loc_1e2da: // 1b0c:321a
    memoryASet16(ds, si + 3, ax);
}
void sub_1e2de() // 1b0c:321e
{
    al = memoryAGet(ds, 0x48f0);
    tl = memoryAGet(ds, si + 10);
    memoryASet(ds, si + 10, memoryAGet(ds, si + 10) - al);
    if ((char)tl - (char)al > 0)
        return;
    memoryASet(ds, si + 10, 0x3c);
    ax = memoryAGet16(ds, 0x0491);
    if (memoryAGet16(ds, 0x4965) == ax)
        return;
    memoryASet16(ds, 0x4965, ax);
    cl = memoryAGet(ds, 0x0490);
    bx = 0x58d7;
    memoryASet16(ds, bx + 5, ax);
    memoryASet(ds, bx + 7, cl);
    sub_1c939();
}
void sub_1e307() // 1b0c:3247
{
loc_1e307: // 1b0c:3247
    sub_1f961();
    if (--cx)
        goto loc_1e307;
}
void sub_1f042() // 1b0c:3f82
{
    ax = memoryAGet16(ds, 0x5960);
    ax |= memoryAGet16(ds, 0x5962);
    if (!ax)
        goto loc_1f062;
    push(ds);
    dx = memoryAGet16(ds, 0x5960);
    ds = memoryAGet16(ds, 0x5962);
    ax = 0x2508;
    interrupt(0x21);
    ds = pop();
    ax = 0;
    memoryASet16(ds, 0x5960, ax);
    memoryASet16(ds, 0x5962, ax);
loc_1f062: // 1b0c:3fa2
    al = 0x36;
    out(0x43, al);
    al = 0;
    out(0x40, al);
    out(0x40, al);
    ax = 0;
    memoryASet16(ds, 0x595e, ax);
}
void sub_1f072() // 1b0c:3fb2
{
    push(ds);
    ax = 0x40e5;
    bx = 0x4239;
    cx = 0x4069;
    if (memoryAGet(cs, 0x325b) & 0x10)
        goto loc_1f09e;
    ax = 0x4133;
    bx = 0x4228;
    cx = 0x403a;
    if (memoryAGet(cs, 0x325b) & 0x08)
        goto loc_1f09e;
    ax = 0x40eb;
    bx = 0x4221;
    cx = 0x4021;
loc_1f09e: // 1b0c:3fde
    memoryASet16(cs, 0x3261, ax);
    memoryASet16(cs, 0x3263, bx);
    memoryASet16(cs, 0x3265, cx);
    ax = 0x3508;
    interrupt(0x21);
    memoryASet16(ds, 0x5960, bx);
    memoryASet16(ds, 0x5962, es);
    ax = cs;
    ds = ax;
    dx = 0x40ab;
    ax = 0x2508;
    interrupt(0x21);
    ds = pop();
    sub_1f971();
    ax = memoryAGet16(ds, 0x595c);
    memoryASet16(ds, 0x595e, ax);
    bx = 0x0000;
    push(ax);
    memoryASet(cs, 0x325c, bh);
    al = bh;
    bh = 0;
    callIndirect(cs, memoryAGet16(cs, 0x3265));
}
void sub_1f0d2() // 1b0c:4012
{
    push(ax);
    memoryASet(cs, 0x325c, bh);
    al = bh;
    bh = 0;
    callIndirect(cs, memoryAGet16(cs, 0x3265));
}
void sub_1f129() // 1b0c:4069
{
    if (!bl)
        goto loc_1f151;
    memoryASet(ds, bx + 22883, al);
    tx = bx;
    bx = ax;
    ax = tx;
    ax--;
    if (!(memoryAGet(cs, 0x325b) & bl))
        goto loc_1f141;
    push(cs);
    cs = 0x19ee;
    sub_1b06b();
    assert(cs == 0x1b0c);
    ax = pop();
    return;
loc_1f141: // 1b0c:4081
    if (al != 0x0d)
        goto loc_1f14f;
    push(cs);
    cs = 0x19ee;
    sub_1b06b();
    assert(cs == 0x1b0c);
    push(cs);
    cs = 0x19ee;
    sub_1b0b1();
    assert(cs == 0x1b0c);
loc_1f14f: // 1b0c:408f
    ax = pop();
    return;
loc_1f151: // 1b0c:4091
    push(cs);
    cs = 0x19ee;
    sub_1b07f();
    assert(cs == 0x1b0c);
    ax = pop();
}
void sub_1f158() // 1b0c:4098
{
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        return;
    ax = 0x1766;
    push(cs);
    cs = 0x19ee;
    sub_1b060();
    assert(cs == 0x1b0c);
}
void sub_1f286() // 1b0c:41c6
{
    al = 0x06;
    out(0x43, al);
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    tl = al;
    al = ah;
    ah = tl;
}
void sub_1f293() // 1b0c:41d3
{
    bx = 0x04b0;
    sub_1f2b5();
    al = 0xb6;
    out(0x43, al);
    al = bl;
    out(0x42, al);
    al = bh;
    out(0x42, al);
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f961();
    sub_1f2e1();
}
void sub_1f2b5() // 1b0c:41f5
{
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
}
void sub_1f2bc() // 1b0c:41fc
{
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        return;
    cl = al;
    bx = 0x5964;
    ax = 0;
loc_1f2cb: // 1b0c:420b
    if (!(memoryAGet(ds, bx) & cl))
        goto loc_1f2d4;
    push(cs);
    cs = 0x19ee;
    sub_1b0b6();
    assert(cs == 0x1b0c);
loc_1f2d4: // 1b0c:4214
    bx++;
    ax++;
    if (ax < 0x0012)
        goto loc_1f2cb;
}
void sub_1f2dc() // 1b0c:421c
{
    callIndirect(cs, memoryAGet16(cs, 0x3263));
//    stop(/*2*/); // 1b0c:421c jmp word ptr cs:[0x3263] - jump Indirect memoryAGet16(cs, 0x3263)
}
void sub_1f2e1() // 1b0c:4221
{
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
}
void sub_1f311() // 1b0c:4251
{
    if (!(memoryAGet(cs, 0x325b) & 0x10))
        return;
    push(cs);
    cs = 0x19ee;
    sub_1b07f();
    assert(cs == 0x1b0c);
}
void sub_1f320(bool resume) // 1b0c:4260
{
    if (resume)
        goto resume_1b0c_4269;
    goto loc_1f320;
loc_1c4d9: // 1b0c:1419
    return;
loc_1c4da: // 1b0c:141a
    sub_1c3a8();
    sub_1f042();
    sub_1b45a();
    al = 0x03;
    sub_1f2dc();
    sub_1c363();
    sub_1f8c5();
    ax = 0x1118;
    ds = ax;
    dx = memoryAGet16(ds, 0x480f);
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
    if (memoryAGet(ds, 0x47e0) == 0x00)
        goto loc_1c4d9;
    memoryASet(cs, 0x1339, 0x00);
    goto loc_1dbe2;
    //   gap of 5842 bytes
loc_1dbe2: // 1b0c:2b22
    bx = 0x020b;
    sub_1f0d2();
    memoryASet(ds, 0x0497, memoryAGet(ds, 0x0497) + 1);
    sub_1d6f2();
    cl = memoryAGet(ds, 0x0497);
    if (cl > 0x06)
        goto loc_1dc19;
    push(si);
    ch = 0;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    cx -= 0x0016;
    bx = 0x00c8;
    dx = 0x00c3;
    push(bx);
    push(cx);
    push(dx);
    sub_1fb4c();
    dx = pop();
    cx = pop();
    bx = pop();
    sub_1fb46();
    si = pop();
loc_1dc19: // 1b0c:2b59
    return;
    //   gap of 5894 bytes
loc_1f320: // 1b0c:4260
    sub_1f6d9();
    sub_1f6b1();
    sub_1f64d(); //seq1
resume_1b0c_4269:
    if (flags.carry) // resume seq10 1b0c:4269
        goto loc_1f341;
    sub_1f66a();
    sub_1f6be();
loc_1f331: // 1b0c:4271
    push(cx);
    sub_1f961();
    sub_1c1ac();
    cx = pop();
    if (--cx && !cl)
        goto loc_1f331;
    sub_1f83b();
    if (resume)
    {
        sub_1b0c0(true);
        assert(0);
    }
    return;
loc_1f341: // 1b0c:4281
    ax = 0x5d95;
    memoryASet16(ds, 0x480f, ax);
    goto loc_1c4da;
}
void sub_1f34a() // 1b0c:428a
{
    flags.carry = (bx + 0x000f) >= 0x10000;
    bx += 0x000f;
    bx = rcr(bx, 0x0001);
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax += bx;
    memoryASet16(cs, 0x429d, ax);
    flags.carry = false;
}
// INJECT: Error: cannot inject flag in sub_1f35f() because of being label!
void sub_1f35f() // 1b0c:429f
{
//    assert(0);
//    printf("skip ctx switch\n");
//    flags.carry = true;
//    return;
    push(ax);
    push(bx);
    sub_1f37c_ctxswitch1(); // seq3
    bx = pop();
    ax = pop();
    if (flags.carry)
        goto loc_1f377;
    cx = 0;
    dx = 0;
    sub_1f41f_ctxswitch2();
    push(cx);
    push(dx);
    sub_1f404();
    dx = pop();
    cx = pop();
    flags.carry = false;
loc_1f377: // 1b0c:42b7
    return;
}
void sub_1f364() // 1b0c:42a4
{
//    stop(/*override stack*/);
    bx = pop();
    ax = pop();
    if (flags.carry)
        return;
    cx = 0;
    dx = 0;
    sub_1f41f_ctxswitch2(); // seq5
    push(cx);
    push(dx);
    sub_1f404();
    dx = pop();
    cx = pop();
    flags.carry = false;
}
void sub_1f36f() // 1b0c:42af   ---seq5 resume!
{
    push(cx);
    push(dx);
    sub_1f404();
    dx = pop();
    cx = pop();
    flags.carry = false;
    // continues 1b0c:45a9?
    //continues 1b0c:4269
    sub_1f320(true);
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_1f37c()!
void sub_1f37c_ctxswitch1() // 1b0c:42bc
{
    push(0x7777);
    sub_1f404();
    ah = 0x3d;
    al = 0;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_1f388;
    stop(/*inject ret*/);
    assert(pop() == 0x7777);
    return;
loc_1f388: // 1b0c:42c8
    memoryASet16(cs, 0x42ba, ax);
    ax = 0x1118;
    es = ax;
    memoryASet16(es, 0x5d82, 0x0000);
    memoryASet16(es, 0x5d84, 0x0000);
    memoryASet16(es, 0x5d86, 0x0000);
    memoryASet16(es, 0x5d88, 0x0102);
    memoryASet16(es, 0x5d8a, 0x0000);
    memoryASet16(es, 0x5d8c, 0x0009);
    memoryASet16(es, 0x5d8e, 0x0200);
    memoryASet(es, 0x5d90, 0x00);
    memoryASet(es, 0x5d91, 0x00);
    memoryASet16(es, 0x5d80, 0x0000);
    cx = ss;
    dx = sp;
    flags.interrupts = false;
    ax = 0x10f8;
    ss = ax;
    sp = 0x01fe;
    flags.interrupts = true;
    ax = 0x43f3;
    push(ax);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    ax = 0x1118;
    push(ax);
    push(ax);
    memoryASet16(cs, 0x43ef, ss);
    memoryASet16(cs, 0x43f1, sp);
    flags.interrupts = false;
    ss = cx;
    sp = dx;
    flags.interrupts = true;
    flags.carry = false;
    assert(pop() == 0x7777);
    //assert(0);
    // continues 1b0c:42a4
    //ggggggg
    sub_1f364(); // seq4 todo check from stack
    assert(0);
}
void sub_1f404() // 1b0c:4344
{
    if (memoryAGet16(cs, 0x42ba) == 0xffff)
        goto loc_1f41d;
    ah = 0x3e;
    bx = memoryAGet16(cs, 0x42ba);
    interrupt(0x21); // close file
    memoryASet16(cs, 0x42ba, 0xffff);
    return;
loc_1f41d: // 1b0c:435d
    flags.carry = false;
}
void sub_1f41f_ctxswitch2() // 1b0c:435f ctx switch - seq5
{
//    assert(0);
//    push(0x7777);
    memoryASet16(cs, 0x455e, ax);
    memoryASet16(cs, 0x4560, bx);
    memoryASet16(cs, 0x43ae, cx);
    memoryASet16(cs, 0x43b0, dx);
    ax = 0;
    bx = 0;
    flags.carry = ax < cx;
    ax -= cx;
    bx -= dx + flags.carry;
    memoryASet16(cs, 0x4562, ax);
    memoryASet16(cs, 0x4564, bx);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    memoryASet16(cs, 0x43aa, ss);
    memoryASet16(cs, 0x43ac, sp);
    flags.interrupts = false;
    ss = memoryAGet16(cs, 0x43ef);
    sp = memoryAGet16(cs, 0x43f1);
    flags.interrupts = true;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
//    assert(pop() == 0x7777);
    // TODO: stack override
    printf("stack override!!!\n");
  //  callIndirect(cs, pop()); // 1b0c:43f3
    //assert(0);
    // ctx switch back 1b0c:43f3
    sub_1f4b3(); // seq6
}
void sub_1f472_ctxswitch3() // 1b0c:43b2 ctx switch seq7
{
 //   assert(0);
//    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    memoryASet16(cs, 0x43ef, ss);
    memoryASet16(cs, 0x43f1, sp);
    flags.interrupts = false;
    printf("stack override\n");
    ss = memoryAGet16(cs, 0x43aa);
    sp = memoryAGet16(cs, 0x43ac);
    flags.interrupts = true;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    cx = memoryAGet16(cs, 0x43ae);
    dx = memoryAGet16(cs, 0x43b0);
    flags.carry = (cx + memoryAGet16(cs, 0x4562)) >= 0x10000;
    assert(memoryAGet16(cs, 0x4562) == 0x556e);
    cx += memoryAGet16(cs, 0x4562);
    dx += memoryAGet16(cs, 0x4564) + flags.carry;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
//    assert(pop() == 0x7777);
    // ctx continues 1b0c:42af gggg seq8
    //assert(0);
    sub_1f36f(); // seq8
}
void sub_1f4b3() // 1b0c:43f3 - seq6 noexit???
{
    ah = 0x3f;
    bx = memoryAGet16(cs, 0x42ba);
    cx = 0x0400;
    dx = 0x597e;
    interrupt(0x21);
loc_1f4c2: // 1b0c:4402
    sub_1f571();
    if (ax != 0x0101)
        goto loc_1f4ce;
    flags.carry = false;
    sub_1f472_ctxswitch3(); // <-- seq7 ctx switch
loc_1f4ce: // 1b0c:440e
    if (ax != 0x0100)
        goto loc_1f4ed;
    sub_1f5da();
    sub_1f571();
    memoryASet16(ds, 0x5d82, ax);
    memoryASet16(ds, 0x5d84, ax);
    memoryASet(ds, 0x5d91, al);
    memoryASet(ds, 0x5d90, al);
    al = memoryAGet(ds, 0x5d91);
    sub_1f5ed();
    goto loc_1f4c2;
loc_1f4ed: // 1b0c:442d
    memoryASet16(ds, 0x5d82, ax);
    memoryASet16(ds, 0x5d86, ax);
    es = memoryAGet16(cs, 0x429d);
    if ((short)ax < (short)memoryAGet16(ds, 0x5d88))
        goto loc_1f50c;
    ax = memoryAGet16(ds, 0x5d84);
    memoryASet16(ds, 0x5d82, ax);
    al = memoryAGet(ds, 0x5d90);
    push(ax);
    memoryASet16(ds, 0x5d8a, memoryAGet16(ds, 0x5d8a) + 1);
loc_1f50c: // 1b0c:444c
    if ((short)memoryAGet16(ds, 0x5d82) <= (short)0x00ff)
        goto loc_1f52c;
    bx = memoryAGet16(ds, 0x5d82);
    sub_1f626();
    al = memoryAGet(es, bx + 2);
    push(ax);
    memoryASet16(ds, 0x5d8a, memoryAGet16(ds, 0x5d8a) + 1);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x5d82, ax);
    goto loc_1f50c;
loc_1f52c: // 1b0c:446c
    push(ds);
    es = pop();
    ax = memoryAGet16(ds, 0x5d82);
    memoryASet(ds, 0x5d90, al);
    memoryASet(ds, 0x5d91, al);
    push(ax);
    memoryASet16(ds, 0x5d8a, memoryAGet16(ds, 0x5d8a) + 1);
    cx = memoryAGet16(ds, 0x5d8a);
    if (cx == 0)
        goto loc_1f548;
loc_1f542: // 1b0c:4482
    ax = pop();
    sub_1f5ed();
    if (--cx)
        goto loc_1f542;
loc_1f548: // 1b0c:4488
    memoryASet16(ds, 0x5d8a, cx);
    sub_1f62d();
    ax = memoryAGet16(ds, 0x5d86);
    memoryASet16(ds, 0x5d84, ax);
    bx = memoryAGet16(ds, 0x5d88);
    if ((short)bx < (short)memoryAGet16(ds, 0x5d8e))
        goto loc_1f56e;
    if (memoryAGet16(ds, 0x5d8c) == 0x000c)
        goto loc_1f56e;
    memoryASet16(ds, 0x5d8c, memoryAGet16(ds, 0x5d8c) + 1);
    memoryASet16(ds, 0x5d8e, memoryAGet16(ds, 0x5d8e) << 1);
loc_1f56e: // 1b0c:44ae
    goto loc_1f4c2;
}
void sub_1f571() // 1b0c:44b1
{
    ax = memoryAGet16(ds, 0x5d80);
    ax += memoryAGet16(ds, 0x5d8c);
    tx = memoryAGet16(ds, 0x5d80);
    memoryASet16(ds, 0x5d80, ax);
    ax = tx;
    dx = ax;
    dx &= 0x0007;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if ((short)ax < (short)0x03fd)
        goto loc_1f5b7;
    push(dx);
    dx += memoryAGet16(ds, 0x5d8c);
    memoryASet16(ds, 0x5d80, dx);
    cx = 0x0400;
    bp = ax;
    cx -= ax;
    ax += 0x597e;
    si = ax;
    di = 0x597e;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ah = 0x3f;
    bx = memoryAGet16(cs, 0x42ba);
    cx = bp;
    dx = di;
    interrupt(0x21);
    ax = 0;
    dx = pop();
loc_1f5b7: // 1b0c:44f7
    ax += 0x597e;
    si = ax;
    lodsw<MemAuto, DirAuto>();
    bx = ax;
    lodsb<MemAuto, DirAuto>();
    cx = dx;
    if (cx == 0)
        goto loc_1f5ca;
loc_1f5c4: // 1b0c:4504
    flags.carry = al & 1;
    al >>= 1;
    bx = rcr(bx, 0x0001);
    if (--cx)
        goto loc_1f5c4;
loc_1f5ca: // 1b0c:450a
    ax = bx;
    bx = memoryAGet16(ds, 0x5d8c);
    bx -= 0x0009;
    bx <<= 1;
    ax &= memoryAGet16(ds, bx + 22902);
}
void sub_1f5da() // 1b0c:451a
{
    memoryASet16(ds, 0x5d8c, 0x0009);
    memoryASet16(ds, 0x5d8e, 0x0200);
    memoryASet16(ds, 0x5d88, 0x0102);
}
void sub_1f5ed() // 1b0c:452d
{
    push(es);
    es = memoryAGet16(cs, 0x455e);
    di = memoryAGet16(cs, 0x4560);
    memoryASet(es, di, al);
    di++;
    if (di != 0)
        goto loc_1f605;
    memoryASet16(cs, 0x455e, memoryAGet16(cs, 0x455e) + 0x1000);
loc_1f605: // 1b0c:4545
    memoryASet16(cs, 0x4560, di);
    es = pop();
    memoryASet16(cs, 0x4562, memoryAGet16(cs, 0x4562) + 1);
    if (memoryAGet16(cs, 0x4562) != 0)
        return;
    memoryASet16(cs, 0x4564, memoryAGet16(cs, 0x4564) + 1);
    if (memoryAGet16(cs, 0x4564) != 0)
        return;
    flags.carry = false;
    sub_1f472_ctxswitch3();
}
void sub_1f626() // 1b0c:4566
{
    bp = bx;
    bx <<= 1;
    bx += bp;
}
void sub_1f62d() // 1b0c:456d
{
    bx = memoryAGet16(ds, 0x5d88);
    sub_1f626();
    push(es);
    es = memoryAGet16(cs, 0x429d);
    al = memoryAGet(ds, 0x5d91);
    memoryASet(es, bx + 2, al);
    ax = memoryAGet16(ds, 0x5d84);
    memoryASet16(es, bx, ax);
    es = pop();
    memoryASet16(ds, 0x5d88, memoryAGet16(ds, 0x5d88) + 1);
}
void sub_1f64d() // 1b0c:458d
{
    ax = memoryAGet16(ds, 0x5e39);
    ax += memoryAGet16(ds, 0x5dba);
    memoryASet16(ds, 0x5e3f, ax);
    bx = 0x0000;
    sub_1f34a();
    ax = memoryAGet16(ds, 0x5e39);
    bx = 0x0000;
    dx = 0x5dac;
    sub_1f35f(); //seq2
}
void sub_1f66a() // 1b0c:45aa
{
    push(es);
    dx = memoryAGet16(ds, 0x5e39);
    es = dx;
    bx = memoryAGet16(es, 0x018e);
    ax = memoryAGet16(es, bx + 2);
    if (!(al & 0x0f))
        goto loc_1f681;
    ax += 0x0010;
loc_1f681: // 1b0c:45c1
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dx += ax;
    memoryASet16(ds, 0x5e3b, dx);
    bx = memoryAGet16(es, 0x01f8);
    es = dx;
    ax = memoryAGet16(es, bx + 2);
    if (!(al & 0x0f))
        goto loc_1f6a1;
    ax += 0x0010;
loc_1f6a1: // 1b0c:45e1
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    dx += ax;
    memoryASet16(ds, 0x5e3d, dx);
    es = pop();
}
void sub_1f6b1() // 1b0c:45f1 - chk1 l847124
{
    ah = 0;
    interrupt(0x1a);
    memoryASet16(ds, 0x615b, dx);
    memoryASet16(ds, 0x615d, cx);
}
void sub_1f6be() // 1b0c:45fe
{
    ah = 0;
    interrupt(0x1a);
    flags.carry = dx < memoryAGet16(ds, 0x615b);
    dx -= memoryAGet16(ds, 0x615b);
    cx -= memoryAGet16(ds, 0x615d) + flags.carry;
    if (dx > 0x005b)
        goto loc_1f6d5;
    cx = 0x005c;
    cx -= dx;
    return;
loc_1f6d5: // 1b0c:4615
    cx = 0x0001;
}
void sub_1f6d9() // 1b0c:4619
{
    push(es);
    push(ds);
    sub_1f827();
    bl = memoryAGet(ds, 0x048f);
    ax--;
    es = ax;
    ds = ax;
    si = 0x6ba0;
    si &= 0x000f;
    di = 0x4e20;
    sub_1f854();
    sub_1f6fc();
    ds = pop();
    sub_1fb2b();
    es = pop();
    sync();
}
void sub_1f6fc() // 1b0c:463c
{
    push(bx);
    push(ds);
    bx = ds;
    bx += 0x14b4;
    ax = 0x1118;
    ds = ax;
    memoryASet16(ds, 0x5e3f, bx);
    sub_1fb33();
    ax = bx;
    ds = pop();
    bx = pop();
    si = 0x4e20;
    if (bl == 0x04)
        goto loc_1f79b;
    if (bl == 0x09)
        goto loc_1f729;
    if (bl == 0x0d)
        goto loc_1f749;
    goto loc_1f7eb;
loc_1f729: // 1b0c:4669
    ax = 0xb800;
    es = ax;
    bx = 0x0000;
    cx = 0x00c8;
loc_1f734: // 1b0c:4674
    push(bx);
    push(cx);
    cx = 0x0000;
    sub_2127e();
    di = ax;
    cx = 0x0050;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    bx = pop();
    bx++;
    if (--cx)
        goto loc_1f734;
    return;
loc_1f749: // 1b0c:4689
    ax = 0x1118;
    es = ax;
    bp = memoryAGet16(es, 0x5e37);
    ax = 0xa000;
    es = ax;
    bl = 0x01;
    dx = 0x03c4;
loc_1f75d: // 1b0c:469d
    al = 0x02;
    ah = bl;
    out(dx, ax);
    di = bp;
    si = 0x4e20;
    cx = 0x1f40;
loc_1f76a: // 1b0c:46aa
    push(cx);
    bh = 0;
    cx = 0x0004;
loc_1f770: // 1b0c:46b0
    bh <<= 1;
    bh <<= 1;
    lodsb<MemAuto, DirAuto>();
    if (!(bl & al))
        goto loc_1f77c;
    bh |= 0x01;
loc_1f77c: // 1b0c:46bc
    al >>= 1;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    if (!(bl & al))
        goto loc_1f78b;
    bh |= 0x02;
loc_1f78b: // 1b0c:46cb
    if (--cx)
        goto loc_1f770;
    cx = pop();
    al = bh;
    stosb<MemAuto, DirAuto>(); // draw first splash
    if (--cx)
        goto loc_1f76a;
    bl <<= 1;
    if ((char)bl < (char)0x09)
        goto loc_1f75d;
    return;
loc_1f79b: // 1b0c:46db
    es = ax;
    ax = 0x0020;
    sub_20366();
    cx = 0x0000;
loc_1f7a6: // 1b0c:46e6
    push(cx);
    bx = 0x0000;
    sub_20996();
    di = bx;
    cx = 0x0050;
    bh = 0;
loc_1f7b4: // 1b0c:46f4
    push(cx);
    cx = 0x0002;
    dl = ch;
loc_1f7ba: // 1b0c:46fa
    lodsb<MemAuto, DirAuto>();
    sub_1f7d2();
    sub_1f7d2();
    if (--cx)
        goto loc_1f7ba;
    al = dl;
    stosb<MemAuto, DirAuto>();
    cx = pop();
    if (--cx)
        goto loc_1f7b4;
    cx = pop();
    cx++;
    if (cx != 0x00c8)
        goto loc_1f7a6;
    return;
    //   gap of 25 bytes
loc_1f7eb: // 1b0c:472b
    es = ax;
    cx = 0x0000;
    di = 0x0000;
loc_1f7f3: // 1b0c:4733
    push(cx);
    cx = 0x0050;
    bh = 0;
loc_1f7f9: // 1b0c:4739
    push(cx);
    cx = 0x0002;
    dl = ch;
loc_1f7ff: // 1b0c:473f
    lodsb<MemAuto, DirAuto>();
    sub_1f7d2();
    sub_1f7d2();
    if (--cx)
        goto loc_1f7ff;
    al = dl;
    stosb<MemAuto, DirAuto>();
    cx = pop();
    if (--cx)
        goto loc_1f7f9;
    cx = pop();
    cx++;
    if (cx != 0x00c8)
        goto loc_1f7f3;
}
void sub_1f7d2() // 1b0c:4712
{
    dl <<= 1;
    dl <<= 1;
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    al = ror(al, 0x01);
    bl = al;
    bl &= 0x0f;
    ah = memoryAGet(cs, bx + 18263);
    dl |= ah;
}
void sub_1f827() // 1b0c:4767
{
    ax = 0x6ba0;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax++;
    cx = cs;
    ax += cx;
    memoryASet16(ds, 0x5e39, ax);
}
void sub_1f83b() // 1b0c:477b
{
    push(es);
    push(ax);
    push(cx);
    ax = 0;
    es = ax;
    al++;
    memoryASet(es, 0x0440, al);
    cx = 0x000a;
loc_1f84b: // 1b0c:478b
    sub_1f961();
    if (--cx)
        goto loc_1f84b;
    cx = pop();
    ax = pop();
    es = pop();
}
void sub_1f854() // 1b0c:4794
{
    dx = 0x7d00;
    cx = 0;
    bp = cx;
loc_1f85b: // 1b0c:479b
    cl = memoryAGet(ds, si);
    si++;
    if (!(cl & 0x80))
        goto loc_1f86e;
    cl &= 0x7f;
    cl++;
    bp += cx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    goto loc_1f875;
loc_1f86e: // 1b0c:47ae
    cl++;
    bp += cx;
    lodsb<MemAuto, DirAuto>();
    rep_stosb<MemAuto, DirAuto>();
loc_1f875: // 1b0c:47b5
    if (bp < dx)
        goto loc_1f85b;
}
void sub_1f87a() // 1b0c:47ba
{
    bh = memoryAGet(ds, 0x048f);
    sub_1f888();
    sub_1f8fd();
    sub_1fb27();
}
void sub_1f888() // 1b0c:47c8
{
    al = 0xff;
    if (!(bh & 0x02))
        goto loc_1f894;
    al = 0x07;
    si = 0x6479;
loc_1f894: // 1b0c:47d4
    if (!(bh & 0x04))
        goto loc_1f89e;
    al = 0x04;
    si = 0x644b;
loc_1f89e: // 1b0c:47de
    if (!(bh & 0x80))
        goto loc_1f8a8;
    al = 0x09;
    si = 0x64a7;
loc_1f8a8: // 1b0c:47e8
    if (!(bh & 0x18))
        goto loc_1f8b2;
    al = 0x0d;
    si = 0x641d;
loc_1f8b2: // 1b0c:47f2
    memoryASet(ds, 0x048f, al);
    push(es);
    ax = ds;
    es = ax;
    cx = 0x002e;
    di = 0x63ef;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
    flags.carry = false;
}
void sub_1f8c5() // 1b0c:4805
{
    if (!(memoryAGet(ds, 0x5e36) & 0x80))
        goto loc_1f8d2;
    sub_20b66();
    goto loc_1f8f6;
loc_1f8d2: // 1b0c:4812
    push(es);
    bx = 0x0040;
    es = bx;
    ax = memoryAGet16(ds, 0x5d92);
    memoryASet16(es, 0x0063, ax);
    es = pop();
    if (memoryAGet(ds, 0x5d94) != 0x01)
        goto loc_1f8f6;
    al = 0x62;
    if (memoryAGet(ds, 0x5e36) & 0x10)
        goto loc_1f8f2;
    al = 0x22;
loc_1f8f2: // 1b0c:4832
    dx = 0x03c2;
    out(dx, al);
loc_1f8f6: // 1b0c:4836
    al = memoryAGet(ds, 0x5e35);
    sub_1f925();
}
void sub_1f8fd() // 1b0c:483d
{
    if (!(memoryAGet(ds, 0x5e36) & 0x18))
        goto loc_1f922;
    if (memoryAGet(ds, 0x048f) == 0x0d)
        goto loc_1f912;
    if (memoryAGet(ds, 0x048f) != 0x04)
        goto loc_1f922;
loc_1f912: // 1b0c:4852
    ah = 0x12;
    bl = 0x10;
    interrupt(0x10);
    if (bh == 0x00)
        goto loc_1f922;
    memoryASet(ds, 0x5d94, 0x01);
loc_1f922: // 1b0c:4862
    al = memoryAGet(ds, 0x048f);
    push(es);
    bx = 0x0040;
    es = bx;
    bx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x5d92, bx);
    bl = memoryAGet(es, 0x0010);
    bl &= 0xcf;
    if (al != 0x07)
        goto loc_1f94c;
    memoryASet16(es, 0x0063, 0x03b4);
    bl |= 0x30;
    goto loc_1f956;
loc_1f94c: // 1b0c:488c
    memoryASet16(es, 0x0063, 0x03d4);
    bl |= 0x20;
loc_1f956: // 1b0c:4896
    memoryASet(es, 0x0010, bl);
    ah = 0x00;
    interrupt(0x10);
    es = pop();
}
void sub_1f925() // 1b0c:4865
{
    push(es);
    bx = 0x0040;
    es = bx;
    bx = memoryAGet16(es, 0x0063);
    memoryASet16(ds, 0x5d92, bx);
    bl = memoryAGet(es, 0x0010);
    bl &= 0xcf;
    if (al != 0x07)
        goto loc_1f94c;
    memoryASet16(es, 0x0063, 0x03b4);
    bl |= 0x30;
    goto loc_1f956;
loc_1f94c: // 1b0c:488c
    memoryASet16(es, 0x0063, 0x03d4);
    bl |= 0x20;
loc_1f956: // 1b0c:4896
    memoryASet(es, 0x0010, bl);
    ah = 0x00;
    interrupt(0x10);
    es = pop();
}
void sub_1f961() // 1b0c:48a1
{
    dx = 0x03da;
loc_1f964: // 1b0c:48a4
    in(al, dx);
    if (al & 0x08)
        goto loc_1f964;
    dx = 0x03da;
loc_1f96c: // 1b0c:48ac
    in(al, dx);
    if (!(al & 0x08))
        goto loc_1f96c;
    al = 0x36;
    out(0x43, al);
    ax = memoryAGet16(ds, 0x595c);
    out(0x40, al);
    al = ah;
    out(0x40, al);
    memoryASet(cs, 0x3259, 0x00);
}
void sub_1f969() // 1b0c:48a9
{
    dx = 0x03da;
loc_1f96c: // 1b0c:48ac
    in(al, dx);
    if (!(al & 0x08))
        goto loc_1f96c;
    al = 0x36;
    out(0x43, al);
    ax = memoryAGet16(ds, 0x595c);
    out(0x40, al);
    al = ah;
    out(0x40, al);
    memoryASet(cs, 0x3259, 0x00);
}
void sub_1f971() // 1b0c:48b1
{
    al = 0x36;
    out(0x43, al);
    ax = memoryAGet16(ds, 0x595c);
    out(0x40, al);
    al = ah;
    out(0x40, al);
    memoryASet(cs, 0x3259, 0x00);
}
void sub_1f985() // 1b0c:48c5
{
    push(bx);
    bx = 0x48dc;
    cx = 0x002b;
    bp = 0x4907;
loc_1f98f: // 1b0c:48cf
    if (ah == memoryAGet(cs, bx))
        goto loc_1f99a;
    bx++;
    bp += 0x0008;
    if (--cx)
        goto loc_1f98f;
loc_1f99a: // 1b0c:48da
    bx = pop();
}
void sub_1fb27() // 1b0c:4a67
{
    callIndirect(cs, memoryAGet16(ds, 0x63ef));
}
void sub_1fb2b() // 1b0c:4a6b
{
    callIndirect(cs, memoryAGet16(ds, 0x6407));
}
void sub_1fb2f() // 1b0c:4a6f
{
    callIndirect(cs, memoryAGet16(ds, 0x6409));
}
void sub_1fb33() // 1b0c:4a73
{
    callIndirect(cs, memoryAGet16(ds, 0x63f1));
}
void sub_1fb37() // 1b0c:4a77
{
    callIndirect(cs, memoryAGet16(ds, 0x640b));

//    stop(/*2*/); // 1b0c:4a77 jmp word ptr [0x640b] - jump Indirect memoryAGet16(ds, 0x640b)
}
void sub_1fb3b() // 1b0c:4a7b
{
    push(bx);
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, 0x63f7));
}
void sub_1fb42() // 1b0c:4a82
{
    callIndirect(cs, memoryAGet16(ds, 0x63fb));
//    stop(/*2*/); // 1b0c:4a82 jmp word ptr [0x63fb] - jump Indirect memoryAGet16(ds, 0x63fb)
}
void sub_1fb46() // 1b0c:4a86
{
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, 0x63ff));
//    stop(/*2*/); // 1b0c:4a88 jmp word ptr [0x63ff] - jump Indirect memoryAGet16(ds, 0x63ff)
}
void sub_1fb4c() // 1b0c:4a8c
{
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, 0x63fd));
}
void sub_1fb52() // 1b0c:4a92
{
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, 0x6401));
}
void sub_1fb58() // 1b0c:4a98
{
    push(ax);
    push(bx);
    push(cx);
    push(ds);
    callIndirect(cs, memoryAGet16(ds, 0x6417));
//    stop(/*2*/); // 1b0c:4a9c jmp word ptr [0x6417] - jump Indirect memoryAGet16(ds, 0x6417)
}
void sub_1fb60() // 1b0c:4aa0
{
    stop(/*override stack*/);
    ds = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_1fb65() // 1b0c:4aa5
{
    push(ax);
    push(bx);
    push(cx);
    push(ds);
    callIndirect(cs, memoryAGet16(ds, 0x6419));
//    stop(/*2*/); // 1b0c:4aa9 jmp word ptr [0x6419] - jump Indirect memoryAGet16(ds, 0x6419)
}
void sub_1fb6d() // 1b0c:4aad
{
    push(ax);
    push(bx);
    push(cx);
    push(ds);
    callIndirect(cs, memoryAGet16(ds, 0x641b));

//    stop(/*2*/); // 1b0c:4ab1 jmp word ptr [0x641b] - jump Indirect memoryAGet16(ds, 0x641b)
}
void sub_1fb75() // 1b0c:4ab5
{
//    stop(/*2*/);  1b0c:4ab5 jmp word ptr [0x6403] - jump Indirect memoryAGet16(ds, 0x6403)
    callIndirect(cs, memoryAGet16(ds, 0x6403));

}
void sub_1fb79() // 1b0c:4ab9
{
//    stop(/*2*/); // 1b0c:4ab9 jmp word ptr [0x6405] - jump Indirect memoryAGet16(ds, 0x6405)
    callIndirect(cs, memoryAGet16(ds, 0x6405));
}
void sub_1fb7d() // 1b0c:4abd
{
//    stop(/*2*/); // 1b0c:4abd jmp word ptr [0x640d] - jump Indirect memoryAGet16(ds, 0x640d)
    callIndirect(cs, memoryAGet16(ds, 0x640d));

}
void sub_1fb81() // 1b0c:4ac1
{
//    stop(/*2*/); // 1b0c:4ac1 jmp word ptr [0x63f3] - jump Indirect memoryAGet16(ds, 0x63f3)
    callIndirect(cs, memoryAGet16(ds, 0x63f3));

}
void sub_1fb85() // 1b0c:4ac5
{
//    stop(/*2*/); // 1b0c:4ac5 jmp word ptr [0x63f5] - jump Indirect memoryAGet16(ds, 0x63f5)
    callIndirect(cs, memoryAGet16(ds, 0x63f5));
}
void sub_1fb89() // 1b0c:4ac9
{
    push(bx);
    bx <<= 1;
//    stop(/*2*/); // 1b0c:4acc jmp word ptr [0x63f9] - jump Indirect memoryAGet16(ds, 0x63f9)
    callIndirect(cs, memoryAGet16(ds, 0x63f9));

}
void sub_1fb90() // 1b0c:4ad0
{
//    stop(/*2*/); // 1b0c:4ad0 jmp word ptr [0x6411] - jump Indirect memoryAGet16(ds, 0x6411)
    callIndirect(cs, memoryAGet16(ds, 0x6411));
}
void sub_1fb94() // 1b0c:4ad4
{
    push(bx);
    bx <<= 1;
//    stop(/*2*/); // 1b0c:4ad7 jmp word ptr [0x640f] - jump Indirect memoryAGet16(ds, 0x640f)
    callIndirect(cs, memoryAGet16(ds, 0x640f));

}
void sub_1fb9b() // 1b0c:4adb
{
//    stop(/*2*/); // 1b0c:4adb jmp word ptr [0x6413] - jump Indirect memoryAGet16(ds, 0x6413)
    callIndirect(cs, memoryAGet16(ds, 0x6413));
}
void sub_1fb9f() // 1b0c:4adf
{
//    stop(/*2*/); // 1b0c:4adf jmp word ptr [0x6415] - jump Indirect memoryAGet16(ds, 0x6415)
    callIndirect(cs, memoryAGet16(ds, 0x6415));

}
void sub_1fba3() // 1b0c:4ae3
{
    al = 0x06;
    if (!(memoryAGet(ds, 0x5e36) & 0x10))
        goto loc_1fbb4;
    memoryASet16(ds, 0x595c, 0x4074);
    al++;
loc_1fbb4: // 1b0c:4af4
    memoryASet(cs, 0x40a9, al);
    if (memoryAGet(ds, 0x5d94) != 0x01)
        goto loc_1fbce;
    al = 0x63;
    if (memoryAGet(ds, 0x5e36) & 0x10)
        goto loc_1fbca;
    al = 0x23;
loc_1fbca: // 1b0c:4b0a
    dx = 0x03c2;
    out(dx, al);
loc_1fbce: // 1b0c:4b0e
    sub_20014();
    ax = 0x0003;
    out(dx, ax);
    ax = 0xff08;
    out(dx, ax);
    ax = 0x200c;
    dl = 0xd4;
    out(dx, ax);
    memoryASet(ds, 0x5db5, 0x45);
    ax = memoryAGet16(ds, 0x5dbc);
    memoryASet16(ds, 0x5dba, ax);
}
void sub_1fbeb() // 1b0c:4b2b
{
    ah = memoryAGet(ds, 0x5e38);
    al = 0x0c;
    dx = 0x03d4;
    out(dx, ax);
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1f969();
}
void sub_1fbfe() // 1b0c:4b3e
{
    push(ds);
    sub_2001c();
    si = memoryAGet16(ds, 0x5e37);
    di = si;
    si ^= 0x2000;
    ax = 0xa000;
    ds = ax;
    cx = 0x2000;
    sub_20413();
    sub_20014();
    ds = pop();
}
void sub_1fc1c() // 1b0c:4b5c
{
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = 0xa000;
    if (!(memoryAGet(ds, 0x5e38) & 0x20))
        goto loc_1fc30;
    dh += 0x02;
loc_1fc30: // 1b0c:4b70
    cx = 0x0fa0;
    push(es);
    es = dx;
    ax = 0;
    di = ax;
    // draw pixel
        di += cx*2;
//    rep_stosw<MemAuto, DirAuto>();
    es = pop();
}
void sub_1fc33() // 1b0c:4b73
{
    push(es);
    es = dx;
    ax = 0;
    di = ax;
    rep_stosw<MemAuto, DirAuto>();
    es = pop();
}
void sub_1fc3e() // 1b0c:4b7e
{
    push(es);
    push(cx);
    push(dx);
    ax = memoryAGet16(ds, 0x5e39);
    es = ax;
    si = memoryAGet16(es, bx);
    bx = dx;
    sub_20181();
    ah ^= 0x20;
    memoryASet16(ds, 0x5e4a, ax);
    bl = memoryAGet(es, si);
    memoryASet(ds, 0x5e4c, bl);
    cl = memoryAGet(es, si + 1);
    memoryASet(ds, 0x5e4d, cl);
    si = ax;
    di = memoryAGet16(ds, 0x5e48);
    bh = 0;
    ch = bh;
    ax = 0xa000;
    push(ds);
    ds = ax;
    es = ax;
    sub_2001c();
loc_1fc78: // 1b0c:4bb8
    push(si);
    push(cx);
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    si = pop();
    si += 0x0028;
    if (--cx)
        goto loc_1fc78;
    sub_20014();
    ds = pop();
    dx = pop();
    cx = pop();
    es = pop();
    bx = pop();
}
void sub_1fc8e() // 1b0c:4bce
{
    push(bx);
    push(cx);
    cl = memoryAGet(ds, 0x5e4d);
    if (!cl)
        goto loc_1fcd8;
    push(dx);
    bl = memoryAGet(ds, 0x5e4c);
    di = memoryAGet16(ds, 0x5e4a);
    si = memoryAGet16(ds, 0x5e48);
    bh = 0;
    ch = bh;
    ax = 0xa000;
    push(ds);
    push(es);
    ds = ax;
    es = ax;
    sub_2001c();
loc_1fcb5: // 1b0c:4bf5
    push(di);
    push(cx);
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    di = pop();
    di += 0x0028;
    if (--cx)
        goto loc_1fcb5;
    es = pop();
    ds = pop();
    memoryASet(ds, 0x5e4d, cl);
    dx = pop();
    cx = pop();
    push(cx);
    push(dx);
    if (dl <= 0xb5)
        goto loc_1fcd4;
    sub_1fcdb();
loc_1fcd4: // 1b0c:4c14
    sub_20014();
    dx = pop();
loc_1fcd8: // 1b0c:4c18
    cx = pop();
    bx = pop();
}
void sub_1fcdb() // 1b0c:4c1b
{
    push(ds);
    push(es);
    di = 0x1d39;
    bx = di;
    bx ^= memoryAGet16(ds, 0x5e37);
    if (bh & 0x20)
        goto loc_1fcef;
    di ^= 0x2000;
loc_1fcef: // 1b0c:4c2f
    si = 0x9000;
    bl = cl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bl--;
    bh = 0;
    di += bx;
    si += bx;
    cx = 0x0007;
    ax = 0xa000;
    es = ax;
    ds = ax;
loc_1fd0c: // 1b0c:4c4c
    push(si);
    push(di);
    push(cx);
    cx = 0x0002;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    di = pop();
    si = pop();
    di += 0x0028;
    si += 0x001b;
    if (--cx)
        goto loc_1fd0c;
    es = pop();
    ds = pop();
}
void sub_1fd22() // 1b0c:4c62
{
    push(es);
    push(ds);
    cx = 0x0007;
    si = 0x1d39;
    di = 0x9000;
    ax = 0xa000;
    ds = ax;
    es = ax;
    sub_2001c();
loc_1fd37: // 1b0c:4c77
    push(si);
    push(cx);
    cx = 0x001b;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    si = pop();
    si += 0x0028;
    if (--cx)
        goto loc_1fd37;
    sub_20014();
    ds = pop();
    es = pop();
}
void sub_1fd4b() // 1b0c:4c8b
{
    push(bx);
    push(cx);
    push(dx);
    push(ds);
    push(es);
    di = 0x1d39;
    bx = di;
    bx ^= memoryAGet16(ds, 0x5e37);
    if (bh & 0x20)
        goto loc_1fd62;
    di ^= 0x2000;
loc_1fd62: // 1b0c:4ca2
    si = 0x9000;
    bl = memoryAGet(ds, 0x5e43);
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bl--;
    bh = 0;
    di += bx;
    si += bx;
    bl = memoryAGet(ds, 0x5e41);
    cx = 0x0007;
    ax = 0xa000;
    ds = ax;
    es = ax;
    sub_2001c();
loc_1fd88: // 1b0c:4cc8
    push(si);
    push(di);
    push(cx);
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    di = pop();
    si = pop();
    di += 0x0028;
    si += 0x001b;
    if (--cx)
        goto loc_1fd88;
    sub_20014();
    es = pop();
    ds = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_1fda3() // 1b0c:4ce3
{
    push(es);
    ax = memoryAGet16(ds, 0x5e39);
    es = ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ds, 0x5e3b);
    es = ax;
    al = memoryAGet(es, di);
    memoryASet(ds, 0x5e41, al);
    memoryASet(ds, 0x5e43, cl);
    es = pop();
    bx = pop();
}
void sub_1fdbe() // 1b0c:4cfe
{
    push(es);
    push(cx);
    push(dx);
    ax = memoryAGet16(ds, 0x5e39);
    es = ax;
    si = memoryAGet16(es, bx);
    if (bx < 0x0190)
        goto loc_1fdd4;
    ax = memoryAGet16(ds, 0x5e3b);
    es = ax;
loc_1fdd4: // 1b0c:4d14
    bp = 0;
    if (!(memoryAGet(ds, 0x5e38) & 0x20))
        goto loc_1fde0;
    bp = 0x0005;
loc_1fde0: // 1b0c:4d20
    memoryASet(ds, bp + 24143, memoryAGet(ds, bp + 24143) + 1);
    di = memoryAGet16(ds, bp + 24144);
    bx = dx;
    sub_20181();
    memoryASet16(ds, di + 2, ax);
    bl = memoryAGet(es, si);
    memoryASet(ds, di, bl);
    cl = memoryAGet(es, si + 1);
    memoryASet(ds, di + 1, cl);
    si = ax;
    ax = memoryAGet16(ds, bp + 24146);
    memoryASet16(ds, di + 4, ax);
    di += 0x0006;
    memoryASet16(ds, bp + 24144, di);
    di = ax;
    bh = 0;
    ch = bh;
    ax = 0xa000;
    push(ds);
    ds = ax;
    es = ax;
    sub_2001c();
loc_1fe21: // 1b0c:4d61
    push(si);
    push(cx);
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    si = pop();
    si += 0x0028;
    if (--cx)
        goto loc_1fe21;
    sub_20014();
    ds = pop();
    dx = pop();
    cx = pop();
    es = pop();
    memoryASet16(ds, bp + 24146, di);
    bx = pop();
}
void sub_1fe3b() // 1b0c:4d7b
{
}
void sub_1fe3c() // 1b0c:4d7c
{
    bp = 0;
    if (!(memoryAGet(ds, 0x5e38) & 0x20))
        goto loc_1fe48;
    bp = 0x0005;
loc_1fe48: // 1b0c:4d88
    ch = 0;
    cl = memoryAGet(ds, bp + 24143);
    if (cx == 0)
        return;
    sub_2001c();
loc_1fe54: // 1b0c:4d94
    push(cx);
    sub_1fe64();
    cx = pop();
    if (--cx)
        goto loc_1fe54;
    memoryASet(ds, bp + 24143, cl);
    sub_20014();
}
void sub_1fe64() // 1b0c:4da4
{
    si = memoryAGet16(ds, bp + 24144);
    si -= 0x0006;
    memoryASet16(ds, bp + 24144, si);
    bl = memoryAGet(ds, si);
    cl = memoryAGet(ds, si + 1);
    di = memoryAGet16(ds, si + 2);
    si = memoryAGet16(ds, si + 4);
    memoryASet16(ds, bp + 24146, si);
    bh = 0;
    ch = bh;
    ax = 0xa000;
    push(ds);
    push(es);
    ds = ax;
    es = ax;
loc_1fe8e: // 1b0c:4dce
    push(di);
    push(cx);
    cx = bx;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cx = pop();
    di = pop();
    di += 0x0028;
    if (--cx)
        goto loc_1fe8e;
    es = pop();
    ds = pop();
}
void sub_1fe9e() // 1b0c:4dde
{
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
    sub_1feac();
    memoryASet(ds, 0x5e38, memoryAGet(ds, 0x5e38) ^ 0x20);
}
void sub_1feac() // 1b0c:4dec
{
    if (bx > 0x0015)
        goto loc_1fec1;
    if (bx < 0x000b)
        goto loc_1fec1;
    if (cx < 0x0008)
        return;
    if (cx > 0x00dc)
        return;
loc_1fec1: // 1b0c:4e01
    push(es);
    push(ds);
    ax = memoryAGet16(ds, 0x5e39);
    es = ax;
    bp = memoryAGet16(es, bx);
    tx = dx;
    dx = bx;
    bx = tx;
    if (dx >= 0x0190)
        goto loc_1fed9;
    sub_1fee6();
    ds = pop();
    es = pop();
    return;
loc_1fed9: // 1b0c:4e19
    sub_20181();
    dx = memoryAGet16(ds, 0x5e3b);
    sub_1feed();
    ds = pop();
    es = pop();
}
void sub_1fee6() // 1b0c:4e26
{
    sub_20181();
    dx = memoryAGet16(ds, 0x5e39);
    push(ax);
    ds = dx;
    ax = 0xa000;
    es = ax;
    bx &= 0x0007;
    bx <<= 1;
    bx <<= 1;
    di = bx;
    bx = bp;
    ch = memoryAGet(ds, bx);
    cl = memoryAGet(ds, bx + 1);
    si = memoryAGet16(ds, bx + di + 4);
    di = memoryAGet16(ds, bx + di + 6);
    bp = pop();
    bl = ch;
    ch = 0;
    bh = 0x00;
    ax = 0x0102;
    dh = 0x03;
loc_1ff17: // 1b0c:4e57
    push(ax);
    dl = 0xc4;
    out(dx, ax);
    dl = 0xce;
    al = 0x04;
    ah = bh;
    out(dx, ax);
    push(cx);
    push(bp);
    push(di);
loc_1ff25: // 1b0c:4e65
    push(cx);
    push(bp);
    ch = 0;
    cl = bl;
loc_1ff2b: // 1b0c:4e6b
    ah = memoryAGet(es, bp);
    ah &= memoryAGet(ds, di);
    ah |= memoryAGet(ds, si);
    //draw pixel post second splash//    ah =0xff;
    memoryASet(es, bp, ah);
    bp++;
    si++;
    di++;
    if (--cx)
        goto loc_1ff2b;
    bp = pop();
    cx = pop();
    bp += 0x0028;
    if (--cx)
        goto loc_1ff25;
    di = pop();
    bp = pop();
    cx = pop();
    ax = pop();
    ah <<= 1;
    bh++;
    if (bh != 0x04)
        goto loc_1ff17;
}
void sub_1feed() // 1b0c:4e2d
{
    push(ax);
    ds = dx;
    ax = 0xa000;
    es = ax;
    bx &= 0x0007;
    bx <<= 1;
    bx <<= 1;
    di = bx;
    bx = bp;
    ch = memoryAGet(ds, bx);
    cl = memoryAGet(ds, bx + 1);
    si = memoryAGet16(ds, bx + di + 4);
    di = memoryAGet16(ds, bx + di + 6);
    bp = pop();
    bl = ch;
    ch = 0;
    bh = 0x00;
    ax = 0x0102;
    dh = 0x03;
loc_1ff17: // 1b0c:4e57
    push(ax);
    dl = 0xc4;
    out(dx, ax);
    dl = 0xce;
    al = 0x04;
    ah = bh;
    out(dx, ax);
    push(cx);
    push(bp);
    push(di);
loc_1ff25: // 1b0c:4e65
    push(cx);
    push(bp);
    ch = 0;
    cl = bl;
loc_1ff2b: // 1b0c:4e6b
    ah = memoryAGet(es, bp);
    ah &= memoryAGet(ds, di);
    ah |= memoryAGet(ds, si);
    memoryASet(es, bp, ah);
    bp++;
    si++;
    di++;
    if (--cx)
        goto loc_1ff2b;
    bp = pop();
    cx = pop();
    bp += 0x0028;
    if (--cx)
        goto loc_1ff25;
    di = pop();
    bp = pop();
    cx = pop();
    ax = pop();
    ah <<= 1;
    bh++;
    if (bh != 0x04)
        goto loc_1ff17;
}
void sub_1ff51() // 1b0c:4e91
{
    push(es);
    push(ds);
    ax = memoryAGet16(ds, 0x5e39);
    es = ax;
    bp = memoryAGet16(es, bx + 506);
    bx = dx;
    ax = 0xa000;
    es = ax;
    sub_1ff6a();
    ds = pop();
    es = pop();
}
void sub_1ff6a() // 1b0c:4eaa
{
    sub_20181();
    push(ax);
    ax = memoryAGet16(ds, 0x5e3d);
    ds = ax;
    bx &= 0x0007;
    bx <<= 1;
    bx <<= 1;
    di = bx;
    bx = bp;
    ch = memoryAGet(ds, bx);
    cl = memoryAGet(ds, bx + 1);
    si = memoryAGet16(ds, bx + di + 4);
    di = pop();
    bl = ch;
    ch = 0;
    bh = 0x00;
    ax = 0x0102;
    dh = 0x03;
loc_1ff92: // 1b0c:4ed2
    push(ax);
    dl = 0xc4;
    out(dx, ax);
    dl = 0xce;
    al = 0x04;
    ah = bh;
    out(dx, ax);
    push(cx); // gabo draw pixel?
    push(di);
loc_1ff9f: // 1b0c:4edf
    push(cx);
    push(di);
    ch = 0;
    cl = bl;
    assert(cx);
    // DRAW SECOND SPLASH!
//    printf("setpix %04x:%04x <= %04x:%04x = (%02d, cnt=%d)\n", es, di, ds, si, memoryAGet(ds, si), cx);
    rep_movsb<MemAuto, MemAuto, DirAuto>(); // draw pixel ? 1b0c:4ee5
    di = pop();
    cx = pop();
    di += 0x0028;
    if (--cx)
        goto loc_1ff9f;
    di = pop();
    cx = pop();
    ax = pop();
    ah <<= 1;
    bh++;
    if (bh != 0x04)
        goto loc_1ff92;
}
void sub_1ffbb() // 1b0c:4efb
{
    goto loc_1ffbb;
loc_1fb60: // 1b0c:4aa0
//    printf("Check stack!!\n");
   // stop(/*override stack*/);
    ds = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
    //   gap of 1110 bytes
loc_1ffbb: // 1b0c:4efb
    sub_20049();
    dx = 0x03ce;
loc_1ffc1: // 1b0c:4f01
    ax = 0x0304;
    out(dx, ax);
    dl = 0xc4;
    ax = 0x0802;
    out(dx, ax);
    ah = memoryAGet(ds, bx);
    push(ax);
    memoryASet(ds, bx, 0x00);
    ax = 0x0702;
    out(dx, ax);
    dl = 0xce;
    ax = pop();
    al = 0x08;
    ah ^= 0xff;
    out(dx, ax);
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x00);
    ah = 0xff;
    out(dx, ax);
    bx += 0x0028;
    if (--cx)
        goto loc_1ffc1;
    goto loc_1fb60;
}
void sub_1ffec() // 1b0c:4f2c
{
    goto loc_1ffec;
loc_1fb60: // 1b0c:4aa0
//    stop(/*override stack*/);
    ds = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
    //   gap of 1159 bytes
loc_1ffec: // 1b0c:4f2c
    sub_2002a();
    di = si;
    push(es);
    es = ax;
loc_1fff4: // 1b0c:4f34
    al = memoryAGet(ds, bx);
    stosb<MemAuto, DirAuto>();
    bx += 0x0028;
    if (--cx)
        goto loc_1fff4;
    es = pop();
    sub_20014();
    goto loc_1fb60;
}
void sub_20014() // 1b0c:4f54
{
    ax = 0x0005;
    dx = 0x03ce;
    out(dx, ax);
}
void sub_2001c() // 1b0c:4f5c
{
    ax = 0x0105;
    dx = 0x03ce;
    out(dx, ax);
    dl = 0xc4;
    ax = 0xff02;
    out(dx, ax);
}
void sub_2002a() // 1b0c:4f6a
{
    push(ax);
    push(bx);
    al--;
    dl = 0xb6;
    mul(dl);
    bx--;
    dx = bx;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx -= dx;
    ax += bx;
    ax += 0x8000;
    si = ax;
    sub_2001c();
    bx = pop();
    ax = pop();
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= dx;
    ax += 0x0003;
    ax <<= 1;
    push(bx);
    bx = ax;
    ax = memoryAGet16(cs, bx + 20695);
    bx = pop();
    ax += memoryAGet16(ds, 0x5e37);
    bx += ax;
    ax = 0xa000;
    ds = ax;
    cx = 0x0007;
}
void sub_20049() // 1b0c:4f89
{
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= dx;
    ax += 0x0003;
    ax <<= 1;
    push(bx);
    bx = ax;
    ax = memoryAGet16(cs, bx + 20695);
    bx = pop();
    ax += memoryAGet16(ds, 0x5e37);
    bx += ax;
    ax = 0xa000;
    ds = ax;
    cx = 0x0007;
}
void sub_20070() // 1b0c:4fb0
{
    push(bp);
    push(es);
    push(ax);
    tx = cx;
    cx = bx;
    bx = tx;
    sub_20181();
    ah &= 0xdf;
    di = ax;
    ax = 0xa000;
    es = ax;
    bx = pop();
loc_20083: // 1b0c:4fc3
    ah = memoryAGet(ds, si);
    if (!ah)
        goto loc_20090;
    sub_200b6();
    si++;
    di++;
    goto loc_20083;
loc_20090: // 1b0c:4fd0
    es = pop();
    bp = pop();
}
void sub_20093() // 1b0c:4fd3
{
    push(bp);
    push(es);
    push(ax);
    tx = cx;
    cx = bx;
    bx = tx;
    sub_20181();
    ah ^= 0x20;
    di = ax;
    ax = 0xa000;
    es = ax;
    bx = pop();
loc_200a6: // 1b0c:4fe6
    ah = memoryAGet(ds, si);
    if (!ah)
        goto loc_200b3;
    sub_200e7();
    si++;
    di++;
    goto loc_200a6;
loc_200b3: // 1b0c:4ff3
    es = pop();
    bp = pop();
}
void sub_200b6() // 1b0c:4ff6
{
    sub_1f985();
    dx = 0x03c4;
    ax = 0x0102;
loc_200bf: // 1b0c:4fff
    push(di);
    push(bp);
    out(dx, ax);
    cx = 0x0008;
loc_200c5: // 1b0c:5005
    bh = memoryAGet(cs, bp);
    if (ah & bl)
        goto loc_200cf;
    bh = 0x00;
loc_200cf: // 1b0c:500f
    memoryASet(es, di, bh);
    memoryASet(es, di + 8192, bh);
    bp++;
    di += 0x0028;
    if (--cx)
        goto loc_200c5;
    bp = pop();
    di = pop();
    ah <<= 1;
    if ((char)ah < (char)0x09)
        goto loc_200bf;
}
void sub_200e7() // 1b0c:5027
{
    sub_1f985();
    dx = 0x03c4;
    ax = 0x0102;
loc_200f0: // 1b0c:5030
    push(di);
    push(bp);
    out(dx, ax);
    cx = 0x0008;
loc_200f6: // 1b0c:5036
    bh = memoryAGet(cs, bp);
    if (ah & bl)
        goto loc_20100;
    bh = 0x00;
loc_20100: // 1b0c:5040
    memoryASet(es, di, bh);
    bp++;
    di += 0x0028;
    if (--cx)
        goto loc_200f6;
    bp = pop();
    di = pop();
    ah <<= 1;
    if ((char)ah < (char)0x09)
        goto loc_200f0;
}
void sub_20113() // 1b0c:5053
{
    push(si);
    push(di);
    push(ds);
    push(es);
    cx = 0x0000;
    bx = 0x0000;
    sub_20181();
    ah ^= 0x20;
    di = ax;
    ax += 0x0028;
    si = ax;
    ax = 0xa000;
    es = ax;
    ds = ax;
    sub_2001c();
    cx = 0x0064;
loc_20137: // 1b0c:5077
    push(cx);
    cx = 0x001d;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    si += 0x000b;
    di += 0x000b;
    cx = pop();
    if (--cx)
        goto loc_20137;
    sub_20014();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
}
void sub_20173() // 1b0c:50b3
{
    ax = 0x0505;
    if (!al)
        goto loc_2017d;
    ax = 0x0507;
loc_2017d: // 1b0c:50bd
    sub_2039b();
}
void sub_20181() // 1b0c:50c1
{
    bx <<= 1;
    ax = memoryAGet16(cs, bx + 20695);
    bx = cx;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    ax += cx;
    ax += memoryAGet16(ds, 0x5e37);
}
void sub_20366() // 1b0c:52a6
{
    if (!(memoryAGet(ds, 0x5e36) & 0x18))
        goto loc_203ad;
    bl = al;
    al &= 0x1f;
    ah = 0;
    sub_2039b();
    al = bl;
    al &= 0xf0;
    al |= 0x02;
    if (!(bl & 0x20))
        goto loc_20383;
    al |= 0x03;
loc_20383: // 1b0c:52c3
    bl = al;
    ah = 0x01;
    sub_2039b();
    bl += 0x02;
    al = bl;
    ah = 0x02;
    sub_2039b();
    bl += 0x02;
    al = bl;
    ah = 0x03;
    push(ax);
    dx = 0x03da;
    in(al, dx);
    ax = pop();
    tl = al;
    al = ah;
    ah = tl;
    dl = 0xc0;
    out(dx, al);
    tl = al;
    al = ah;
    ah = tl;
    out(dx, al);
    al = 0x20;
    out(dx, al);
    return;
loc_203ad: // 1b0c:52ed
    dx = 0x03d9;
    out(dx, al);
}
void sub_2039b() // 1b0c:52db
{
    push(ax);
    dx = 0x03da;
    in(al, dx);
    ax = pop();
    tl = al;
    al = ah;
    ah = tl;
    dl = 0xc0;
    out(dx, al);
    tl = al;
    al = ah;
    ah = tl;
    out(dx, al);
    al = 0x20;
    out(dx, al);
}
void sub_20413() // 1b0c:5353
{
    push(es);
    es = ax;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    es = pop();
}
void sub_20996() // 1b0c:58d6
{
    tx = cx;
    cx = bx;
    bx = tx;
    push(cx);
    bx <<= 1;
    bx = memoryAGet16(cs, bx + 22765);
    cx >>= 1;
    cx >>= 1;
    bx += cx;
    cx = pop();
    cl &= 0x03;
    cl <<= 1;
}
void sub_20b66() // 1b0c:5aa6
{
    al = 0xd0;
    sub_20be5();
    sub_20be3();
}
void sub_20be3() // 1b0c:5b23
{
    al = 0xc2;
    dx = 0x03df;
    out(dx, al);
    dx = 0xb800;
    cx = 0x4000;
    sub_1fc33();
}
void sub_20be5() // 1b0c:5b25
{
    dx = 0x03df;
    out(dx, al);
    dx = 0xb800;
    cx = 0x4000;
    sub_1fc33();
}
void sub_2127e() // 1b0c:61be
{
    bx <<= 1;
    ax = memoryAGet16(cs, bx + 25036);
    bx = cx;
    cx >>= 1;
    ax += cx;
}
