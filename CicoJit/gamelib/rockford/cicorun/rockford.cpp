#include "cicoemu.h"
using namespace CicoContext;

void sub_2d2a5();
void fixReloc(uint16_t seg);

void start()
{
    headerSize = 0x00a0;
    loadAddress = 0x1000;
    cs = 0x2cfb;
    ds = 0x2ceb;
    es = 0x2ceb;
    ss = 0x2cdb;
    sp = 0x0200;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/rockford/dos", "ROCKFORD.EXE", 143040);
    fixReloc(cs);
    sub_2d2a5();
}
void fixReloc(uint16_t seg)
{
    memory16(0x1000 + seg, 0xd2a6) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xda1a) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xdbf2) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xdda2) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xe09c) += seg; // 14db -> 24db
    memory16(0x1000 + seg, 0xe2b9) += seg; // 14db -> 24db
    memory16(0x1000 + seg, 0xed64) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xee70) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xee75) += seg; // 0cda -> 1cda
    memory16(0x1000 + seg, 0xfb91) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xfc39) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xfd4a) += seg; // 0000 -> 1000
    memory16(0x1000 + seg, 0xfd87) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x0908) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x0a8f) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x0ac0) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x0d77) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x0e58) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x0f1d) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x0f2d) += seg; // 14db -> 24db
    memory16(0x2000 + seg, 0x0f5e) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x0f75) += seg; // 14db -> 24db
    memory16(0x2000 + seg, 0x0ffd) += seg; // 14db -> 24db
    memory16(0x2000 + seg, 0x10c8) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x1125) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x1158) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x11c5) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x1222) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x1255) += seg; // 0cda -> 1cda
    memory16(0x2000 + seg, 0x1458) += seg; // 0000 -> 1000
    memory16(0x2000 + seg, 0x1891) += seg; // 0000 -> 1000
}
void sub_2d277();
void sub_2d2a5();
void sub_2d4bf();
void sub_2d4f1();
void sub_2d523();
void sub_2d5ed();
void sub_2d69f();
void sub_2d780();
void sub_2d832();
void sub_2d859();
void sub_2d92f();
void sub_2da06();
void sub_2dff1();
void sub_2e045();
void sub_2e147();
void sub_2e222();
void sub_2e293();
void sub_2e306();
void sub_2e4bc();
void sub_2e59c();
void sub_2e6d0();
void sub_2e84d();
void sub_2e9ca();
void sub_2eb18();
void sub_2ebea();
void sub_2ec26();
void sub_2ec93();
void sub_2ed84();
void sub_2ed94();
void sub_2edc5();
void sub_2ee2d();
void sub_2f112();
void sub_2f126();
void sub_2f8c5();
void sub_2f920();
void sub_2f971();
void sub_2f98b();
void sub_2f9e0();
void sub_2fa13();
void sub_2fa65();
void sub_2fa7b();
void sub_2fabe();
void sub_2fafc();
void sub_2fb0c();
void sub_2fb39();
void sub_2fbda();
void sub_2fc15();
void sub_2fd19();
void sub_2fd41();
void sub_2fd9c();
void sub_2fe63();
void sub_2fe95();
void sub_2fea7();
void sub_2feb9();
void sub_2ff80();
void sub_2ffa5();
void sub_2ffe2();
void sub_3001f();
void sub_30042();
void sub_304bd();
void sub_30509();
void sub_30531();
void sub_30555();
void sub_3057b();
void sub_3059d();
void sub_3061a();
void sub_30629();
void sub_3065f();
void sub_30707();
void sub_3074d();
void sub_3075c();
void sub_308d1();
void sub_308e1();
void sub_30a7e();
void sub_30ab8();
void sub_30ca6();
void sub_30d97();
void sub_30e68();
void sub_30fc7();
void sub_31073();
void sub_31091();
void sub_310a3();
void sub_31177();
void sub_311a5();
void sub_3129c();
void sub_312bb();
void sub_312f4();
void sub_3132a();
void sub_31345();
void sub_31392();
void sub_313dd();
void sub_314b6();
void sub_314ec();
void sub_31671();
void sub_316ec();
void sub_3174f();
void sub_3177d();
void sub_317b1();
void sub_31834();
void sub_31874();
void sub_31a83();
void sub_31a91();
void sub_31a9f();
void sub_31c81();
void sub_31d2e();
void sub_31f15();
void sub_32140();
void sub_32168();
void sub_321c0();
void sub_321c4();
void sub_321c8();
void sub_321e7();
void sub_322c0();
void sub_32394();
void sub_32399();
void sub_3239e();
void sub_323ca();
void sub_323ce();
void sub_32417();
void sub_3241c();
void sub_32421();
void sub_32426();
void sub_3242b();
void sub_32431();
void sub_32436();
void sub_3243b();
void sub_32514();
void sub_325e8();
void sub_325ed();
void sub_325f2();
void sub_32607();
void sub_32613();
void sub_3263f();
void sub_3272e();
void sub_32732();
void sub_32736();
void sub_32760();
void sub_32764();
void sub_328a0();
void sub_328a4();
void sub_328fc();
void sub_32900();
void sub_32904();
void sub_32923();
void sub_32968();
void sub_3296d();
void sub_32970();
void sub_32990();
void sub_32991();
void sub_329a9();
void sub_329c1();
void sub_329d0();
void sub_32a46();
void sub_32b44();
void sub_32b96();
void sub_32bab();
void sub_32bca();
void sub_32be3();
void sub_32bfc();
void sub_32c19();
void sub_32e02();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    assert(seg == 0x2cfb);
    switch (ofs)
    {
        case 0x5237: sub_321e7(); return;
        case 0x53e9: sub_32399(); return;
        case 0x5310: sub_322c0(); return;
        case 0x53e4: sub_32394(); return;
        case 0x5190: sub_32140(); return;
        case 0x59e0: sub_32990(); return;
        case 0x5210: sub_321c0(); return;
        case 0x594c: sub_328fc(); return;
        case 0x59bd: sub_3296d(); return;
        case 0x5782: sub_32732(); return;
        case 0x5486: sub_32436(); return;
        case 0x59c0: sub_32970(); return;
        case 0x5218: sub_321c8(); return;
        case 0x5954: sub_32904(); return;
        case 0x2ff5: sub_2ffa5(); return;
        case 0x541a: sub_323ca(); return;
        case 0x3032: sub_2ffe2(); return;
        case 0x57b0: sub_32760(); return;
        case 0x51b8: sub_32168(); return;
        case 0x58f4: sub_328a4(); return;
        case 0x577e: sub_3272e(); return;
        case 0x58f0: sub_328a0(); return;
        case 0x5a11: sub_329c1(); return;
        case 0x5214: sub_321c4(); return;
        case 0x5950: sub_32900(); return;
        default:
            break;
    }
    assert(seg == 0x2cfb);
    switch (ofs)
    {
        case 0x59e0: sub_32990(); return;
        case 0x5657: sub_32607(); return;
        case 0x5786: sub_32736(); return;
        case 0x53ee: sub_3239e(); return;
        case 0x59bd: sub_3296d(); return;
        case 0x5467: sub_32417(); return;
        case 0x5973: sub_32923(); return;
        case 0x59b8: sub_32968(); return;
        case 0x546c: sub_3241c(); return;
        case 0x5471: sub_32421(); return;
        case 0x5663: sub_32613(); return;
        case 0x59e1: sub_32991(); return;
        case 0x59f9: sub_329a9(); return;
        case 0x568f: sub_3263f(); return;
        case 0x57b4: sub_32764(); return;
        case 0x5642: sub_325f2(); return;
        case 0x5476: sub_32426(); return;
        case 0x547b: sub_3242b(); return;
        case 0x5481: sub_32431(); return;
        case 0x548b: sub_3243b(); return;
        case 0x563d: sub_325ed(); return;
        case 0x5564: sub_32514(); return;
        case 0x5638: sub_325e8(); return;
        case 0x5237: sub_321e7(); return;
        case 0x53e9: sub_32399(); return;
        case 0x5310: sub_322c0(); return;
        case 0x53e4: sub_32394(); return;
        case 0x5190: sub_32140(); return;
        case 0x5210: sub_321c0(); return;
        case 0x594c: sub_328fc(); return;
        case 0x5782: sub_32732(); return;
        case 0x5486: sub_32436(); return;
        case 0x59c0: sub_32970(); return;
        case 0x5218: sub_321c8(); return;
        case 0x5954: sub_32904(); return;
        case 0x2ff5: sub_2ffa5(); return;
        case 0x541a: sub_323ca(); return;
        case 0x3032: sub_2ffe2(); return;
        case 0x57b0: sub_32760(); return;
        case 0x51b8: sub_32168(); return;
        case 0x58f4: sub_328a4(); return;
        case 0x577e: sub_3272e(); return;
        case 0x58f0: sub_328a0(); return;
        case 0x5a11: sub_329c1(); return;
        case 0x5214: sub_321c4(); return;
        case 0x5950: sub_32900(); return;
        default:
            break;
    }
    assert(0);
}
// INJECT: Error: cannot inject carry flag in sub_2edc5()!
// INJECT: Error: cannot inject flag in sub_3001f() because of being label!
void sub_2d277()
{
    push(cx);
    push(dx);
    dx = 0;
loc_2d27b:
    ah = 0x01;
    interrupt(0x21);
    if (al != 0x1b)
        goto loc_2d288;
    dx = 0xffff;
    goto loc_2d2a0;
loc_2d288:
    al -= 0x30;
    if ((char)al < 0)
        goto loc_2d2a0;
    if ((char)al > (char)0x09)
        goto loc_2d2a0;
    cbw();
    push(ax);
    ax = dx;
    cx = 0x000a;
    mul(cx);
    dx = ax;
    ax = pop();
    dx += ax;
    goto loc_2d27b;
loc_2d2a0:
    ax = dx;
    dx = pop();
    cx = pop();
}
void sub_2d2a5()
{
    ax = 0x1000;
    ds = ax;
    memoryASet(cs, 0x0000, 0xff);
    sub_2f9e0();
    sub_2dff1();
    sub_2f971();
    sub_312bb();
    sub_2f920();
    sub_31392();
    if (memoryAGet16(ds, 0x3598) != 0x0001)
        goto loc_2d2d1;
    memoryASet16(ds, 0x46f2, 0xa000);
    goto loc_2d2d7;
loc_2d2d1:
    memoryASet16(ds, 0x46f2, 0xb800);
loc_2d2d7:
    al = 0x0f;
    bl = 0x07;
    sub_32a46();
    sub_2fc15();
    sub_32be3();
    ax = 0;
    sub_32c19();
    memoryASet16(ds, 0x3ce8, 0xffff);
    memoryASet16(ds, 0x3ce0, 0xffff);
    memoryASet16(ds, 0x415a, 0x0005);
    memoryASet(ds, 0x4166, 0x00);
    memoryASet(cs, 0x0027, 0x00);
    memoryASet16(cs, 0x0002, 0x0000);
    memoryASet(ds, 0x3560, 0x00);
    memoryASet(cs, 0x0025, 0x00);
    memoryASet16(ds, 0x35f0, 0xffff);
    memoryASet16(ds, 0x46f4, 0x0000);
    memoryASet16(cs, 0x0033, 0x0000);
loc_2d32b:
    sub_2ed94();
    sub_30ca6();
    sub_30d97();
    memoryASet16(ds, 0x35b8, 0xffff);
    memoryASet(ds, 0x4166, 0x00);
    sub_2d859();
    sub_314ec();
//    if (memoryAGet16(cs, 0x0033) != 0x0000) // gabo
        goto loc_2d352;
    sub_32b96();
    goto loc_2d32b;
loc_2d352:
    memoryASet16(ds, 0x35b8, 0x0000);
    memoryASet(ds, 0x4166, 0xff);
    sub_32bca();
    sub_3057b();
    memoryASet16(ds, 0x4150, 0x0b00);
    sub_2eb18();
loc_2d36c:
    memoryASet(ds, 0x4164, 0x00);
    sub_2e306();
    sub_31c81();
loc_2d377:
    sub_31874();
    if (memoryAGet(ds, 0x35b6) != 0xff)
        goto loc_2d384;
    sub_329d0();
loc_2d384:
    if (memoryAGet16(ds, 0x3582) != 0x0000)
        goto loc_2d38e;
    sub_30042();
loc_2d38e:
    sub_2fd9c();
    sub_2feb9();
    sub_323ce();
    sub_2f126();
    sub_317b1();
    if (memoryAGet16(ds, 0x359a) == 0x0000)
        goto loc_2d3a7;
    goto loc_2d493;
loc_2d3a7:
    memoryASet16(ds, 0x35fa, memoryAGet16(ds, 0x35fa) + 1);
    if (memoryAGet16(ds, 0x359a) == 0x0000)
        goto loc_2d3b5;
    goto loc_2d493;
loc_2d3b5:
    if (memoryAGet(ds, 0x35a6) == 0xff)
        goto loc_2d3bf;
    goto loc_2d425;
loc_2d3bf:
    if ((short)memoryAGet16(ds, 0x3584) > (short)0x0000)
        goto loc_2d422;
    if (memoryAGet(ds, 0x35be) != 0x00)
        goto loc_2d422;
    memoryASet(ds, 0x35da, 0xff);
    if (memoryAGet(ds, 0x4166) == 0x00)
        goto loc_2d3f4;
    memoryASet(ds, 0x4166, 0x00);
    sub_32e02();
    sub_2e045();
    memoryASet16(ds, 0x35b8, 0x0000);
    sub_32bca();
    memoryASet(ds, 0x4166, 0xff);
    goto loc_2d3f7;
loc_2d3f4:
    sub_2e045();
loc_2d3f7:
    if ((short)memoryAGet16(ds, 0x4160) <= (short)0x0000)
        goto loc_2d422;
loc_2d3fe:
    sync();
    sync();
//    if (memoryAGet16(cs, 0x0002) < 0x0004)
//        goto loc_2d3fe;
    memoryASet16(cs, 0x0002, 0x0000);
    memoryASet16(ds, 0x415e, memoryAGet16(ds, 0x415e) + 1);
    sub_3065f();
    memoryASet(ds, 0x4164, 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) - 1);
    sub_30707();
    goto loc_2d3f7;
loc_2d422:
    goto loc_2d36c;
loc_2d425:
    if (memoryAGet(ds, 0x35be) != 0xff)
        goto loc_2d43f;
    ax = 0x0001;
    bx = memoryAGet16(ds, 0x35f6);
    bx -= 0x0102;
    sub_2f8c5();
    memoryASet(ds, 0x35be, 0x00);
loc_2d43f:
    sub_31a9f();
    sub_31671();
    sub_316ec();
    if (memoryAGet16(ds, 0x3582) == 0x0000)
        goto loc_2d490;
    memoryASet16(ds, 0x3582, memoryAGet16(ds, 0x3582) - 1);
    if (memoryAGet16(ds, 0x3582) != 0)
        goto loc_2d468;
    memoryASet(ds, 0x4164, 0x00);
    sub_2e045();
    memoryASet16(ds, 0x35f0, memoryAGet16(ds, 0x35f0) - 1);
    memoryASet16(ds, 0x415a, memoryAGet16(ds, 0x415a) - 1);
    goto loc_2d36c;
loc_2d468:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2d47d;
    ah = 0;
    interrupt(0x16);
    memoryASet16(ds, 0x35f0, memoryAGet16(ds, 0x35f0) - 1);
    memoryASet16(ds, 0x415a, memoryAGet16(ds, 0x415a) - 1);
    goto loc_2d36c;
loc_2d47d:
    if (memoryAGet(cs, 0x0030) == 0x00)
        goto loc_2d490;
    memoryASet16(ds, 0x35f0, memoryAGet16(ds, 0x35f0) - 1);
    memoryASet16(ds, 0x415a, memoryAGet16(ds, 0x415a) - 1);
    goto loc_2d36c;
loc_2d490:
    goto loc_2d377;
loc_2d493:
    sub_2edc5();
    if (!flags.carry)
        goto loc_2d4a1;
    memoryASet16(ds, 0x359a, 0x0000);
    goto loc_2d377;
loc_2d4a1:
    memoryASet(ds, 0x4166, 0x00);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    sub_32bab();
    ax = 0x0002;
    interrupt(0x10);
    sub_31177();
    sub_2fd19();
    ax = 0x4c00;
    interrupt(0x21);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    flags.direction = false;
    si = 0x0;
    dx = 0x0016;
loc_2d4cb:
    cx = 0x0028;
    push(si);
loc_2d4cf:
    lodsw<MemAuto, DirAuto>();
    if (ax < 0xff48)
        goto loc_2d4e2;
    if (ax > 0xff4b)
        goto loc_2d4e2;
    bx = si;
    bx -= 0x0002;
    sub_31073();
loc_2d4e2:
    if (--cx)
        goto loc_2d4cf;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_2d4cb;
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_2d4bf()
{
    push(bx);
    push(cx);
    push(dx);
    push(si);
    flags.direction = false;
    si = 0x0;
    dx = 0x0016;
loc_2d4cb:
    cx = 0x0028;
    push(si);
loc_2d4cf:
    lodsw<MemAuto, DirAuto>();
    if (ax < 0xff48)
        goto loc_2d4e2;
    if (ax > 0xff4b)
        goto loc_2d4e2;
    bx = si;
    bx -= 0x0002;
    sub_31073();
loc_2d4e2:
    if (--cx)
        goto loc_2d4cf;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_2d4cb;
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_2d4f1()
{
    push(bx);
    push(cx);
    push(dx);
    push(si);
    flags.direction = false;
    si = 0x0;
    dx = 0x0016;
loc_2d4fd:
    cx = 0x0028;
    push(si);
loc_2d501:
    lodsw<MemAuto, DirAuto>();
    if (ax < 0xff48)
        goto loc_2d514;
    if (ax > 0xff4b)
        goto loc_2d514;
    bx = si;
    bx -= 0x0002;
    sub_31091();
loc_2d514:
    if (--cx)
        goto loc_2d501;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_2d4fd;
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_2d523()
{
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_2d531;
    goto loc_2d57f;
loc_2d531:
    push(dx);
    dx = 0x03ce;
    ah = 0x05;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    si = memoryAGet16(ds, 0x4884);
    if ((short)si <= (short)0x0004)
        goto loc_2d550;
    si = 0x0004;
loc_2d550:
    si <<= 1;
    si = memoryAGet16(ds, si + 18638);
    si += 0x2000;
    di = 0x0f62;
    push(ds);
    push(es);
    ds = pop();
    dx = 0x0027;
loc_2d563:
    cx = 0x0008;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0020;
    si += 0x0020;
    dx--;
    if (dx != 0)
        goto loc_2d563;
    ds = pop();
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    return;
loc_2d57f:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_2d589;
    goto loc_2d5b7;
loc_2d589:
    si = memoryAGet16(ds, 0x4884);
    if ((short)si <= (short)0x0004)
        goto loc_2d595;
    si = 0x0004;
loc_2d595:
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18766);
    si = memoryAGet16(ds, si + 18764);
    di = 0x0062;
    ax = 0x0048;
    dx = 0x0027;
    memoryASet16(cs, 0x0006, 0x0010);
    sub_2d832();
    return;
loc_2d5b7:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2d5c1;
    return;
loc_2d5c1:
    si = memoryAGet16(ds, 0x4884);
    if ((short)si <= (short)0x0004)
        goto loc_2d5cd;
    si = 0x0004;
loc_2d5cd:
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18902);
    si = memoryAGet16(ds, si + 18900);
    di = 0x0062;
    ax = 0x0024;
    dx = 0x0027;
    memoryASet16(cs, 0x0006, 0x0008);
    sub_2d832();
}
void sub_2d5ed()
{
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_2d5fb;
    goto loc_2d641;
loc_2d5fb:
    push(dx);
    dx = 0x03ce;
    ah = 0x05;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    si = memoryAGet16(ds, si + 18590);
    si += 0x2000;
    di = 0x08d2;
    push(ds);
    push(es);
    ds = pop();
    dx = 0x002a;
loc_2d625:
    cx = 0x0003;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0025;
    si += 0x0025;
    dx--;
    if (dx != 0)
        goto loc_2d625;
    ds = pop();
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    return;
loc_2d641:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_2d64b;
    goto loc_2d671;
loc_2d64b:
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18670);
    si = memoryAGet16(ds, si + 18668);
    di = 0x0038;
    ax = 0x0048;
    dx = 0x002a;
    memoryASet16(cs, 0x0006, 0x0006);
    sub_2d832();
    return;
loc_2d671:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2d67b;
    return;
loc_2d67b:
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18806);
    si = memoryAGet16(ds, si + 18804);
    di = 0x0038;
    ax = 0x0024;
    dx = 0x002a;
    memoryASet16(cs, 0x0006, 0x0003);
    sub_2d832();
}
void sub_2d69f()
{
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_2d6ad;
    goto loc_2d700;
loc_2d6ad:
    push(dx);
    dx = 0x03ce;
    ah = 0x05;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    if (memoryAGet(ds, 0x488a) != 0xff)
        goto loc_2d6d3;
    si = memoryAGet16(ds, si + 18580);
    goto loc_2d6d7;
loc_2d6d3:
    si = memoryAGet16(ds, si + 18610);
loc_2d6d7:
    si += 0x2000;
    di = 0x0a66;
    push(ds);
    push(es);
    ds = pop();
    dx = 0x0017;
loc_2d6e4:
    cx = 0x0006;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0022;
    si += 0x0022;
    dx--;
    if (dx != 0)
        goto loc_2d6e4;
    ds = pop();
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    return;
loc_2d700:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_2d70a;
    goto loc_2d741;
loc_2d70a:
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    si <<= 1;
    if (memoryAGet(ds, 0x488a) != 0xff)
        goto loc_2d723;
    bx = memoryAGet16(ds, si + 18650);
    si = memoryAGet16(ds, si + 18648);
    goto loc_2d72b;
loc_2d723:
    bx = memoryAGet16(ds, si + 18710);
    si = memoryAGet16(ds, si + 18708);
loc_2d72b:
    di = 0x0042;
    ax = 0x0058;
    dx = 0x0017;
    memoryASet16(cs, 0x0006, 0x000c);
    sub_2d832();
    return;
loc_2d741:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2d74b;
    return;
loc_2d74b:
    si = memoryAGet16(ds, 0x4884);
    si <<= 1;
    si <<= 1;
    if (memoryAGet(ds, 0x488a) != 0xff)
        goto loc_2d764;
    bx = memoryAGet16(ds, si + 18786);
    si = memoryAGet16(ds, si + 18784);
    goto loc_2d76c;
loc_2d764:
    bx = memoryAGet16(ds, si + 18846);
    si = memoryAGet16(ds, si + 18844);
loc_2d76c:
    di = 0x0042;
    ax = 0x002c;
    dx = 0x0017;
    memoryASet16(cs, 0x0006, 0x0006);
    sub_2d832();
}
void sub_2d780()
{
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_2d78e;
    goto loc_2d7d4;
loc_2d78e:
    push(dx);
    dx = 0x03ce;
    ah = 0x05;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    si = memoryAGet16(ds, 0x4882);
    si <<= 1;
    si = memoryAGet16(ds, si + 18630);
    si += 0x2000;
    di = 0x1874;
    push(ds);
    push(es);
    ds = pop();
    dx = 0x0018;
loc_2d7b8:
    cx = 0x0004;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0024;
    si += 0x0024;
    dx--;
    if (dx != 0)
        goto loc_2d7b8;
    ds = pop();
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    return;
loc_2d7d4:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_2d7de;
    goto loc_2d804;
loc_2d7de:
    si = memoryAGet16(ds, 0x4882);
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18750);
    si = memoryAGet16(ds, si + 18748);
    di = 0x009c;
    ax = 0x0050;
    dx = 0x0018;
    memoryASet16(cs, 0x0006, 0x0008);
    sub_2d832();
    return;
loc_2d804:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2d80e;
    return;
loc_2d80e:
    si = memoryAGet16(ds, 0x4882);
    si <<= 1;
    si <<= 1;
    bx = memoryAGet16(ds, si + 18886);
    si = memoryAGet16(ds, si + 18884);
    di = 0x009c;
    ax = 0x0028;
    dx = 0x0018;
    memoryASet16(cs, 0x0006, 0x0004);
    sub_2d832();
}
void sub_2d832()
{
    bx += 0x49ea;
loc_2d836:
    push(si);
    push(di);
    si <<= 1;
    si = memoryAGet16(cs, si + 55);
    si += bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += ax;
    cx = memoryAGet16(cs, 0x0006);
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    si = pop();
    di++;
    si++;
    dx--;
    if (dx != 0)
        goto loc_2d836;
}
void sub_2d859()
{
    memoryASet16(ds, 0x4882, 0x0000);
    memoryASet16(ds, 0x4884, 0x0000);
    memoryASet16(ds, 0x4886, 0x0001);
    memoryASet16(ds, 0x4888, 0x0001);
    memoryASet16(cs, 0x0002, 0x0000);
    memoryASet16(ds, 0x35e0, 0x0000);
    ax = 0; interrupt(0x16);
loc_2d87e:
    sync();
//    if (memoryAGet16(cs, 0x0002) < 0x0007)
//        goto loc_2d87e;
    memoryASet16(cs, 0x0002, 0x0000);
    sub_2d523();
    sub_2d5ed();
    sub_2d69f();
    sub_2d780();
    sub_2fbda();
    if (!al)
        goto loc_2d8a3;
    return;
loc_2d8a3:
    ax = memoryAGet16(ds, 0x4884);
    ax += memoryAGet16(ds, 0x4888);
    if (ax != 0x0004)
        goto loc_2d8ca;
    memoryASet(ds, 0x488a, 0x00);
    if (memoryAGet16(ds, 0x4888) != 0xffff)
        goto loc_2d8ca;
    push(ax);
    sub_308d1();
    if (ax & 0x0003)
        goto loc_2d8c9;
    memoryASet(ds, 0x488a, 0xff);
loc_2d8c9:
    ax = pop();
loc_2d8ca:
    if ((short)ax < (short)0x0009)
        goto loc_2d8dd;
    memoryASet16(ds, 0x4884, 0x0008);
    memoryASet16(ds, 0x4888, 0xffff);
    goto loc_2d8f3;
loc_2d8dd:
    if ((short)ax >= (short)0x0000)
        goto loc_2d8f0;
    memoryASet16(ds, 0x4884, 0x0000);
    memoryASet16(ds, 0x4888, 0x0001);
    goto loc_2d8f3;
loc_2d8f0:
    memoryASet16(ds, 0x4884, ax);
loc_2d8f3:
    ax = memoryAGet16(ds, 0x4882);
    ax += memoryAGet16(ds, 0x4886);
    if ((short)ax < (short)0x0004)
        goto loc_2d90d;
    memoryASet16(ds, 0x4882, 0x0002);
    memoryASet16(ds, 0x4886, 0xffff);
    goto loc_2d923;
loc_2d90d:
    if ((short)ax >= (short)0x0000)
        goto loc_2d920;
    memoryASet16(ds, 0x4882, 0x0001);
    memoryASet16(ds, 0x4886, 0x0001);
    goto loc_2d923;
loc_2d920:
    memoryASet16(ds, 0x4882, ax);
loc_2d923:
    if (memoryAGet16(ds, 0x35e0) >= 0x04b0)
        return;
    goto loc_2d87e;
}
void sub_2d92f()
{
    if (memoryAGet(ds, 0x35bc) != 0xff)
        goto loc_2d937;
    return;
loc_2d937:
    memoryASet(ds, 0x4164, 0x80);
    sub_311a5();
    dx = 0x0004;
loc_2d942:
    memoryASet16(cs, 0x0002, 0x0000);
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x06;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x39b2;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3562);
loc_2d963:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2d96e;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2d963;
loc_2d96e:
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x07;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x39be;
    bh = 0x00;
    bl = 0x0f;
loc_2d986:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2d991;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2d986;
loc_2d991:
    if ((short)memoryAGet16(cs, 0x0002) <= (short)0x0006)
        goto loc_2d991;
    memoryASet16(cs, 0x0002, 0x0000);
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x06;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x39be;
    bh = 0x00;
    bl = 0x0f;
loc_2d9b8:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2d9c3;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2d9b8;
loc_2d9c3:
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x07;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x39b2;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3562);
loc_2d9dd:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2d9e8;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2d9dd;
loc_2d9e8:
    if ((short)memoryAGet16(cs, 0x0002) <= (short)0x0006)
        goto loc_2d9e8;
    dx--;
    if (dx == 0)
        goto loc_2d9f6;
    goto loc_2d942;
loc_2d9f6:
    sub_310a3();
    memoryASet(ds, 0x4164, 0x00);
    memoryASet16(ds, 0x415a, memoryAGet16(ds, 0x415a) + 1);
    sub_31c81();
}
void sub_2da06()
{
    if ((short)ax >= (short)cx)
        goto loc_2da10;
    if ((short)bx >= (short)dx)
        goto loc_2da10;
    goto loc_2da11;
loc_2da10:
    return;
loc_2da11:
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ds);
    push(es);
    di = 0x1000;
    ds = di;
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2da2c;
    goto loc_2dbf1;
loc_2da2c:
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2da36;
    goto loc_2dda1;
loc_2da36:
    memoryASet16(ds, 0x485c, ax);
    memoryASet16(ds, 0x485e, bx);
    memoryASet16(ds, 0x4850, cx);
    memoryASet16(ds, 0x4852, dx);
    memoryASet16(ds, 0x484c, si);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x4854, ax);
    ax = memoryAGet16(ds, 0x485c);
    ax &= 0x0007;
    memoryASet16(ds, 0x4856, ax);
    bx = 0x4872;
    al = memoryAGet(ds, bx+al);
    memoryASet(ds, 0x4865, al);
    ax = memoryAGet16(ds, 0x4856);
    bx = 0x486a;
    al = memoryAGet(ds, bx+al);
    memoryASet(ds, 0x4863, al);
    ax = cx;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x4858, ax);
    ax = cx;
    ax &= 0x0007;
    memoryASet16(ds, 0x485a, ax);
    bx = 0x4872;
    al = memoryAGet(ds, bx+al);
    memoryASet(ds, 0x4869, al);
    ax = memoryAGet16(ds, 0x485a);
    bx = 0x487a;
    al = memoryAGet(ds, bx+al);
    memoryASet(ds, 0x4867, al);
    ax = memoryAGet16(ds, 0x4858);
    ax -= memoryAGet16(ds, 0x4854);
    ax--;
    memoryASet16(ds, 0x4860, ax);
    bx = memoryAGet16(ds, 0x485e);
    dx -= bx;
    dx--;
    memoryASet16(ds, 0x484e, dx);
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    di = memoryAGet16(ds, 0x485e);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    dx = 0x03ce;
    al = 0x08;
    ah = memoryAGet(ds, 0x4863);
    out(dx, ax);
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    al = memoryAGet(es, di);
    al = memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    di++;
    cx = memoryAGet16(ds, 0x4860);
    if (cx == 0)
        goto loc_2dafc;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2dafc:
    al = 0x08;
    ah = memoryAGet(ds, 0x4867);
    out(dx, ax);
    al = memoryAGet(es, di);
    al = memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    di = memoryAGet16(ds, 0x485e);
    di++;
    dx = 0x03ce;
    cx = memoryAGet16(ds, 0x484e);
loc_2db1e:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = 0x08;
    ah = memoryAGet(ds, 0x4863);
    if (memoryAGet16(ds, 0x484c) != 0x0000)
        goto loc_2db3b;
    ah = memoryAGet(ds, 0x4865);
loc_2db3b:
    out(dx, ax);
    al = memoryAGet(es, di);
    al = memoryAGet(ds, 0x4865);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    di++;
    if (memoryAGet16(ds, 0x484c) != 0x0000)
        goto loc_2db58;
    di += memoryAGet16(ds, 0x4860);
    goto loc_2db6e;
loc_2db58:
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    push(cx);
    cx = memoryAGet16(ds, 0x4860);
    if (!cx)
        goto loc_2db6d;
loc_2db66:
    memoryASet(es, di, 0x00);
    di++;
    if (--cx)
        goto loc_2db66;
loc_2db6d:
    cx = pop();
loc_2db6e:
    al = 0x08;
    ah = memoryAGet(ds, 0x4867);
    if (memoryAGet16(ds, 0x484c) != 0x0000)
        goto loc_2db7f;
    ah = memoryAGet(ds, 0x4869);
loc_2db7f:
    out(dx, ax);
    al = memoryAGet(es, di);
    al = memoryAGet(ds, 0x4869);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    di = pop();
    di++;
    if (--cx)
        goto loc_2db1e;
    di = memoryAGet16(ds, 0x4852);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    dx = 0x03ce;
    al = 0x08;
    ah = memoryAGet(ds, 0x4863);
    out(dx, ax);
    al = memoryAGet(es, di);
    al = memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    di++;
    cx = memoryAGet16(ds, 0x4860);
    if (cx == 0)
        goto loc_2dbcc;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2dbcc:
    al = 0x08;
    ah = memoryAGet(ds, 0x4867);
    out(dx, ax);
    al = memoryAGet(es, di);
    al = memoryAGet(cs, 0x0000);
    memoryASet(es, di, al);
    al = 0x08;
    ah = 0xff;
    out(dx, ax);
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    memoryASet(cs, 0x0000, 0xff);
    return;
loc_2dbf1:
    di = 0x1000;
    ds = di;
    es = memoryAGet16(ds, 0x46f2);
    memoryASet16(ds, 0x485c, ax);
    memoryASet16(ds, 0x485e, bx);
    memoryASet16(ds, 0x4850, cx);
    memoryASet16(ds, 0x4852, dx);
    memoryASet16(ds, 0x484c, si);
    ax >>= 1;
    memoryASet16(ds, 0x4854, ax);
    ax = memoryAGet16(ds, 0x485c);
    ax &= 0x0001;
    if (ax)
        goto loc_2dc3e;
    memoryASet(ds, 0x4862, 0xf0);
    memoryASet(ds, 0x4863, 0xff);
    memoryASet(ds, 0x4865, 0x0f);
    memoryASet(ds, 0x4864, 0x00);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2dc3c;
    memoryASet(ds, 0x4865, 0x00);
loc_2dc3c:
    goto loc_2dc52;
loc_2dc3e:
    memoryASet(ds, 0x4862, 0x0f);
    memoryASet(ds, 0x4863, 0x0f);
    memoryASet(ds, 0x4865, 0xf0);
    memoryASet(ds, 0x4864, 0xf0);
loc_2dc52:
    al = memoryAGet(ds, 0x4862);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4862, al);
    al = memoryAGet(ds, 0x4863);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4863, al);
    ax = cx;
    ax >>= 1;
    memoryASet16(ds, 0x4858, ax);
    ax = cx;
    ax &= 0x0001;
    if (ax)
        goto loc_2dc8e;
    memoryASet(ds, 0x4866, 0xf0);
    memoryASet(ds, 0x4867, 0xf0);
    memoryASet(ds, 0x4869, 0x0f);
    memoryASet(ds, 0x4868, 0x0f);
    goto loc_2dcae;
loc_2dc8e:
    memoryASet(ds, 0x4866, 0x0f);
    memoryASet(ds, 0x4867, 0xff);
    memoryASet(ds, 0x4869, 0xf0);
    memoryASet(ds, 0x4868, 0x00);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2dcae;
    memoryASet(ds, 0x4869, 0x00);
loc_2dcae:
    al = memoryAGet(ds, 0x4866);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4866, al);
    al = memoryAGet(ds, 0x4867);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4867, al);
    ax = memoryAGet16(ds, 0x4858);
    ax -= memoryAGet16(ds, 0x4854);
    ax--;
    memoryASet16(ds, 0x4860, ax);
    bx = memoryAGet16(ds, 0x485e);
    dx -= bx;
    dx--;
    memoryASet16(ds, 0x484e, dx);
    di = memoryAGet16(ds, 0x485e);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4864);
    al |= memoryAGet(ds, 0x4863);
    stosb<MemAuto, DirAuto>();
    cx = memoryAGet16(ds, 0x4860);
    if ((short)cx <= (short)0x0000)
        goto loc_2dd04;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2dd04:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4868);
    al |= memoryAGet(ds, 0x4867);
    stosb<MemAuto, DirAuto>();
    di = memoryAGet16(ds, 0x485e);
    di++;
    cx = memoryAGet16(ds, 0x484e);
loc_2dd19:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4865);
    al |= memoryAGet(ds, 0x4862);
    stosb<MemAuto, DirAuto>();
    if (memoryAGet16(ds, 0x484c) != 0x0000)
        goto loc_2dd3e;
    di += memoryAGet16(ds, 0x4860);
    goto loc_2dd4c;
loc_2dd3e:
    push(cx);
    cx = memoryAGet16(ds, 0x4860);
    if (!cx)
        goto loc_2dd4b;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
loc_2dd4b:
    cx = pop();
loc_2dd4c:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4869);
    al |= memoryAGet(ds, 0x4866);
    stosb<MemAuto, DirAuto>();
    di = pop();
    di++;
    if (--cx)
        goto loc_2dd19;
    di = memoryAGet16(ds, 0x4852);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4864);
    al |= memoryAGet(ds, 0x4863);
    stosb<MemAuto, DirAuto>();
    cx = memoryAGet16(ds, 0x4860);
    if ((short)cx <= (short)0x0000)
        goto loc_2dd86;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2dd86:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4868);
    al |= memoryAGet(ds, 0x4867);
    stosb<MemAuto, DirAuto>();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    memoryASet(cs, 0x0000, 0xff);
    return;
loc_2dda1:
    di = 0x1000;
    ds = di;
    es = memoryAGet16(ds, 0x46f2);
    memoryASet16(ds, 0x485c, ax);
    memoryASet16(ds, 0x485e, bx);
    memoryASet16(ds, 0x4850, cx);
    memoryASet16(ds, 0x4852, dx);
    memoryASet16(ds, 0x484c, si);
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x4854, ax);
    ax = memoryAGet16(ds, 0x485c);
    ax &= 0x0003;
    if (ax)
        goto loc_2ddf0;
    memoryASet(ds, 0x4862, 0xc0);
    memoryASet(ds, 0x4863, 0xff);
    memoryASet(ds, 0x4865, 0x3f);
    memoryASet(ds, 0x4864, 0x00);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2ddee;
    memoryASet(ds, 0x4865, 0x00);
loc_2ddee:
    goto loc_2de52;
loc_2ddf0:
    if (ax != 0x0001)
        goto loc_2de17;
    memoryASet(ds, 0x4862, 0x30);
    memoryASet(ds, 0x4863, 0x3f);
    memoryASet(ds, 0x4865, 0xcf);
    memoryASet(ds, 0x4864, 0xc0);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2de15;
    memoryASet(ds, 0x4865, 0xc0);
loc_2de15:
    goto loc_2de52;
loc_2de17:
    if (ax != 0x0002)
        goto loc_2de3e;
    memoryASet(ds, 0x4862, 0x0c);
    memoryASet(ds, 0x4863, 0x0f);
    memoryASet(ds, 0x4865, 0xf3);
    memoryASet(ds, 0x4864, 0xf0);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2de3c;
    memoryASet(ds, 0x4865, 0xf0);
loc_2de3c:
    goto loc_2de52;
loc_2de3e:
    memoryASet(ds, 0x4862, 0x03);
    memoryASet(ds, 0x4863, 0x03);
    memoryASet(ds, 0x4865, 0xfc);
    memoryASet(ds, 0x4864, 0xfc);
loc_2de52:
    al = memoryAGet(ds, 0x4862);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4862, al);
    al = memoryAGet(ds, 0x4863);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4863, al);
    ax = cx;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x4858, ax);
    ax = cx;
    ax &= 0x0003;
    if (ax)
        goto loc_2de90;
    memoryASet(ds, 0x4866, 0xc0);
    memoryASet(ds, 0x4867, 0xc0);
    memoryASet(ds, 0x4869, 0x3f);
    memoryASet(ds, 0x4868, 0x3f);
    goto loc_2defe;
loc_2de90:
    if (ax != 0x0001)
        goto loc_2deb7;
    memoryASet(ds, 0x4866, 0x30);
    memoryASet(ds, 0x4867, 0xf0);
    memoryASet(ds, 0x4869, 0xcf);
    memoryASet(ds, 0x4868, 0x0f);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2deb5;
    memoryASet(ds, 0x4869, 0x0f);
loc_2deb5:
    goto loc_2defe;
loc_2deb7:
    if (ax != 0x0002)
        goto loc_2dede;
    memoryASet(ds, 0x4866, 0x0c);
    memoryASet(ds, 0x4867, 0xfc);
    memoryASet(ds, 0x4869, 0xf3);
    memoryASet(ds, 0x4868, 0x03);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2dedc;
    memoryASet(ds, 0x4869, 0x03);
loc_2dedc:
    goto loc_2defe;
loc_2dede:
    memoryASet(ds, 0x4866, 0x03);
    memoryASet(ds, 0x4867, 0xff);
    memoryASet(ds, 0x4869, 0xfc);
    memoryASet(ds, 0x4868, 0x00);
    if (memoryAGet16(ds, 0x484c) == 0x0000)
        goto loc_2defe;
    memoryASet(ds, 0x4869, 0x00);
loc_2defe:
    al = memoryAGet(ds, 0x4866);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4866, al);
    al = memoryAGet(ds, 0x4867);
    al &= memoryAGet(cs, 0x0000);
    memoryASet(ds, 0x4867, al);
    ax = memoryAGet16(ds, 0x4858);
    ax -= memoryAGet16(ds, 0x4854);
    ax--;
    memoryASet16(ds, 0x4860, ax);
    bx = memoryAGet16(ds, 0x485e);
    dx -= bx;
    dx--;
    memoryASet16(ds, 0x484e, dx);
    di = memoryAGet16(ds, 0x485e);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4864);
    al |= memoryAGet(ds, 0x4863);
    stosb<MemAuto, DirAuto>();
    cx = memoryAGet16(ds, 0x4860);
    if ((short)cx <= (short)0x0000)
        goto loc_2df54;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2df54:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4868);
    al |= memoryAGet(ds, 0x4867);
    stosb<MemAuto, DirAuto>();
    di = memoryAGet16(ds, 0x485e);
    di++;
    cx = memoryAGet16(ds, 0x484e);
loc_2df69:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4865);
    al |= memoryAGet(ds, 0x4862);
    stosb<MemAuto, DirAuto>();
    if (memoryAGet16(ds, 0x484c) != 0x0000)
        goto loc_2df8e;
    di += memoryAGet16(ds, 0x4860);
    goto loc_2df9c;
loc_2df8e:
    push(cx);
    cx = memoryAGet16(ds, 0x4860);
    if (!cx)
        goto loc_2df9b;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
loc_2df9b:
    cx = pop();
loc_2df9c:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4869);
    al |= memoryAGet(ds, 0x4866);
    stosb<MemAuto, DirAuto>();
    di = pop();
    di++;
    if (--cx)
        goto loc_2df69;
    di = memoryAGet16(ds, 0x4852);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4854);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4864);
    al |= memoryAGet(ds, 0x4863);
    stosb<MemAuto, DirAuto>();
    cx = memoryAGet16(ds, 0x4860);
    if ((short)cx <= (short)0x0000)
        goto loc_2dfd6;
    al = memoryAGet(cs, 0x0000);
    rep_stosb<MemAuto, DirAuto>();
loc_2dfd6:
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, 0x4868);
    al |= memoryAGet(ds, 0x4867);
    stosb<MemAuto, DirAuto>();
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    memoryASet(cs, 0x0000, 0xff);
}
void sub_2dff1()
{
    push(es);
    push(cs);
    es = pop();
    di = 0x37;
    flags.direction = false;
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2e011;
    ax = 0;
    cx = 0x0064;
loc_2e005:
    stosw<MemAuto, DirAuto>();
    ax += 0x2000;
    stosw<MemAuto, DirAuto>();
    ax -= 0x1fb0;
    if (--cx)
        goto loc_2e005;
    goto loc_2e043;
loc_2e011:
    if (memoryAGet16(ds, 0x3598) != 0x0001)
        goto loc_2e025;
    ax = 0;
    cx = 0x00c8;
loc_2e01d:
    stosw<MemAuto, DirAuto>();
    ax += 0x0028;
    if (--cx)
        goto loc_2e01d;
    goto loc_2e043;
loc_2e025:
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2e043;
    ax = 0;
    cx = 0x0032;
loc_2e031:
    stosw<MemAuto, DirAuto>();
    ax += 0x2000;
    stosw<MemAuto, DirAuto>();
    ax += 0x2000;
    stosw<MemAuto, DirAuto>();
    ax += 0x2000;
    stosw<MemAuto, DirAuto>();
    ax -= 0x5f60;
    if (--cx)
        goto loc_2e031;
loc_2e043:
    es = pop();
}
void sub_2e045()
{
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2e04f;
    goto loc_2e1a9;
loc_2e04f:
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2e059;
    goto loc_2e1e4;
loc_2e059:
    sub_2e222();
    si = memoryAGet16(ds, 0x3548);
    si <<= 1;
    si = memoryAGet16(cs, si + 55);
    ax = memoryAGet16(ds, 0x354a);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += si;
    memoryASet16(ds, 0x3546, ax);
    if (memoryAGet(ds, 0x35da) != 0xff)
        goto loc_2e082;
    bx = 0x4576;
    goto loc_2e093;
loc_2e082:
    if ((short)memoryAGet16(ds, 0x4160) <= (short)0x0000)
        goto loc_2e08f;
    bx = 0x4582;
    goto loc_2e093;
loc_2e08f:
    bx = 0x458e;
loc_2e093:
    if (memoryAGet(ds, 0x35ac) != 0xff)
        goto loc_2e0a8;
    push(ds);
    ax = 0x24db;
    ds = ax;
    si = 0x0;
    sub_2e147();
    ds = pop();
loc_2e0a8:
    memoryASet16(ds, 0x35e2, 0x0000);
    es = memoryAGet16(ds, 0x46f2);
    push(dx);
    dx = 0x03ce;
    ah = 0x01;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    si = 0;
    memoryASet16(cs, 0x0002, 0x0000);
loc_2e0ce:
    sync();
    sync();
//    if (memoryAGet16(cs, 0x0002) < 0x0009)
//        goto loc_2e0ce;
    memoryASet16(cs, 0x0002, 0x0000);
    push(si);
    push(ds);
    si <<= 1;
    si = memoryAGet16(ds, bx + si);
    si += 0x4000;
    if (memoryAGet(ds, 0x35ac) != 0xff) // gabo inf loop anim
        goto loc_2e0f2;
    si -= 0x2000;
loc_2e0f2:
    di = memoryAGet16(ds, 0x3546);
    ds = memoryAGet16(ds, 0x46f2);
    dx = 0x0030;
loc_2e0fd:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0022;
    si += 0x0022;
    dx--;
    if (dx != 0)
        goto loc_2e0fd;
    ds = pop();
    si = pop();
    si++;
    if (si < 0x0006)
        goto loc_2e116;
    si = 0;
loc_2e116:
    al = 0;
    if (memoryAGet16(ds, 0x35e2) < 0x003c)
        goto loc_2e122;
    sub_2fbda();
loc_2e122:
    if (al)
        goto loc_2e12e;
    if (memoryAGet16(ds, 0x35e2) < 0x0168)
        goto loc_2e0ce;
loc_2e12e:
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    if (memoryAGet(ds, 0x35ac) != 0xff)
        goto loc_2e146;
    si = 0x49ea;
    sub_2e147();
loc_2e146:
    return;
    //   gap of 98 bytes
loc_2e1a9:
    sub_2e222();
    memoryASet16(ds, 0x354a, memoryAGet16(ds, 0x354a) >> 1);
    if (memoryAGet(ds, 0x35da) != 0xff)
        goto loc_2e1bd;
    bx = 0x459a;
    goto loc_2e1ce;
loc_2e1bd:
    if ((short)memoryAGet16(ds, 0x4160) <= (short)0x0000)
        goto loc_2e1ca;
    bx = 0x45b2;
    goto loc_2e1ce;
loc_2e1ca:
    bx = 0x45ca;
loc_2e1ce:
    memoryASet16(ds, 0x35e2, 0x0000);
    es = memoryAGet16(ds, 0x46f2);
    memoryASet16(cs, 0x0006, 0x000c);
    flags.direction = false;
    sub_2e293();
    return;
loc_2e1e4:
    sub_2e222();
    memoryASet16(ds, 0x354a, memoryAGet16(ds, 0x354a) >> 1);
    memoryASet16(ds, 0x354a, memoryAGet16(ds, 0x354a) >> 1);
    if (memoryAGet(ds, 0x35da) != 0xff)
        goto loc_2e1fc;
    bx = 0x45e2;
    goto loc_2e20d;
loc_2e1fc:
    if ((short)memoryAGet16(ds, 0x4160) <= (short)0x0000)
        goto loc_2e209;
    bx = 0x45fa;
    goto loc_2e20d;
loc_2e209:
    bx = 0x4612;
loc_2e20d:
    memoryASet16(ds, 0x35e2, 0x0000);
    es = memoryAGet16(ds, 0x46f2);
    memoryASet16(cs, 0x0006, 0x0006);
    sub_2e293();
}
void sub_2e147()
{
    push(ax);
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    ax = 0xa000;
    es = ax;
    di = 0x2000;
    cx = 0x1f40;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = 0x2000;
    cx = 0x1f40;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = 0x2000;
    cx = 0x1f40;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    di = 0x2000;
    cx = 0x1f40;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ax = pop();
}
void sub_2e222()
{
    ax = memoryAGet16(ds, 0x35f6);
    ax -= memoryAGet16(ds, 0x4150);
    ax &= 0x007f;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= 0x0011;
    bx = memoryAGet16(ds, 0x35f6);
    bx -= memoryAGet16(ds, 0x4150);
    bx &= 0xff80;
    bl = bh;
    bh = 0;
    bx <<= 1;
    bx += 0x0003;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx -= 0x0011;
    if ((short)ax >= (short)0x000f)
        goto loc_2e25a;
    ax = 0x000f;
loc_2e25a:
    if ((short)ax <= (short)0x00ff)
        goto loc_2e262;
    ax = 0x00ff;
loc_2e262:
    if ((short)bx >= (short)0x0027)
        goto loc_2e26a;
    bx = 0x0027;
loc_2e26a:
    if ((short)bx <= (short)0x0087)
        goto loc_2e273;
    bx = 0x0087;
loc_2e273:
    memoryASet16(ds, 0x3548, bx);
    memoryASet16(ds, 0x3548, memoryAGet16(ds, 0x3548) + 1);
    memoryASet16(ds, 0x354a, ax);
    memoryASet16(ds, 0x354a, memoryAGet16(ds, 0x354a) + 1);
    cx = ax;
    cx += 0x0031;
    dx = bx;
    dx += 0x0031;
    si = 0x0001;
    sub_2da06();
}
void sub_2e293()
{
    push(bp);
    flags.direction = false;
    si = 0;
loc_2e297:
    if (memoryAGet16(cs, 0x0002) < 0x0009)
        goto loc_2e297;
    memoryASet16(cs, 0x0002, 0x0000);
    push(si);
    push(ds);
    si <<= 1;
    si <<= 1;
    bp = memoryAGet16(ds, bx + si + 2);
    si = memoryAGet16(ds, bx + si);
    di = memoryAGet16(ds, 0x3548);
    ax = memoryAGet16(ds, 0x354a);
    dx = 0x24db;
    ds = dx;
    dx = 0x0030;
loc_2e2c0:
    push(si);
    push(di);
    si <<= 1;
    si = memoryAGet16(cs, si + 55);
    si += bp;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += ax;
    cx = memoryAGet16(cs, 0x0006);
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    di = pop();
    si = pop();
    di++;
    si++;
    dx--;
    if (dx != 0)
        goto loc_2e2c0;
    ds = pop();
    si = pop();
    si++;
    if (si < 0x0006)
        goto loc_2e2ec;
    si = 0;
loc_2e2ec:
    al = 0;
    if (memoryAGet16(ds, 0x35e2) < 0x003c)
        goto loc_2e2f8;
    sub_2fbda();
loc_2e2f8:
    if (al)
        goto loc_2e304;
    if (memoryAGet16(ds, 0x35e2) < 0x0168)
        goto loc_2e297;
loc_2e304:
    bp = pop();
}
void sub_2e306()
{
    memoryASet(ds, 0x3586, 0x00);
    memoryASet16(ds, 0x35f0, memoryAGet16(ds, 0x35f0) + 1);
    if (memoryAGet16(ds, 0x35f0) >= 0x0004)
        goto loc_2e31f;
    if ((short)memoryAGet16(ds, 0x415a) <= (short)0x0000)
        goto loc_2e31f;
    goto loc_2e34a;
loc_2e31f:
    if ((short)memoryAGet16(ds, 0x415a) > (short)0x0000)
        goto loc_2e33b;
    sub_2f98b();
    memoryASet16(ds, 0x415e, 0x0000);
    memoryASet16(ds, 0x3cea, 0x0000);
    memoryASet16(ds, 0x415a, 0x0005);
loc_2e33b:
    memoryASet16(ds, 0x35f0, 0x0000);
    sub_2eb18();
    memoryASet16(ds, 0x3ce8, 0xffff);
loc_2e34a:
    si = memoryAGet16(ds, 0x46f4);
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2e366;
    memoryASet(ds, 0x3568, 0x01);
    memoryASet(ds, 0x3562, 0x02);
    memoryASet(ds, 0x3566, 0x03);
    goto loc_2e37b;
loc_2e366:
    al = memoryAGet(ds, si + 18102);
    memoryASet(ds, 0x3562, al);
    al = memoryAGet(ds, si + 18112);
    memoryASet(ds, 0x3566, al);
    al = memoryAGet(ds, si + 18142);
    memoryASet(ds, 0x3568, al);
loc_2e37b:
    sub_2ed84();
    sub_30a7e();
    sub_2ee2d();
    ax = memoryAGet16(ds, 0x46f4);
    if (ax == memoryAGet16(ds, 0x3ce8))
        goto loc_2e3a0;
    memoryASet16(ds, 0x3ce8, ax);
    sub_30e68();
    si = memoryAGet16(ds, 0x46f4);
    si <<= 1;
    ax = memoryAGet16(ds, si + 17072);
    memoryASet16(ds, 0x3540, ax);
loc_2e3a0:
    push(memoryAGet16(ds, 0x3cee));
    memoryASet16(ds, 0x35f6, pop());
    if (memoryAGet16(ds, 0x46f4) != 0x0004)
        goto loc_2e3be;
    if (memoryAGet16(ds, 0x35f0) != 0x0002)
        goto loc_2e3be;
    memoryASet16(ds, 0x4150, 0x0b0a);
    goto loc_2e3cc;
loc_2e3be:
    ax = memoryAGet16(ds, 0x4150);
    push(ax);
    sub_2e4bc();
    ax = pop();
    if (ax != memoryAGet16(ds, 0x4150))
        goto loc_2e3be;
loc_2e3cc:
    memoryASet(ds, 0x35a6, 0x00);
    si = memoryAGet16(ds, 0x46f4);
    si <<= 1;
    si <<= 1;
    si += memoryAGet16(ds, 0x35f0);
    si <<= 1;
    ax = memoryAGet16(ds, si + 18022);
    ax++;
    memoryASet16(ds, 0x4160, ax);
    ax = memoryAGet16(ds, si + 17542);
    memoryASet16(ds, 0x3584, ax);
    memoryASet16(ds, 0x354e, 0x0000);
    memoryASet16(ds, 0x3556, 0x0000);
    memoryASet16(ds, 0x3582, 0x0000);
    memoryASet16(ds, 0x3cec, 0x0000);
    memoryASet(ds, 0x35da, 0x00);
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x08;
    dh = 0x01;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x3b6e;
    ax = memoryAGet16(ds, 0x46f4);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si += ax;
    si = si;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3566);
loc_2e432:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2e43d;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2e432;
loc_2e43d:
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x14;
    dh = 0x01;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x3bbe;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3566);
loc_2e457:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2e462;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2e457;
loc_2e462:
    sub_3065f();
    si = 0;
    ax = 0x0075;
    bx = 0x0005;
    cx = ax;
    cx += 0x001e;
    dx = bx;
    dx += 0x000c;
    sub_2da06();
    ax = 0x00bb;
    bx = 0x0005;
    cx = ax;
    cx += 0x0038;
    dx = bx;
    dx += 0x000c;
    sub_2da06();
    ax = 0x0115;
    bx = 0x0005;
    cx = ax;
    cx += 0x001e;
    dx = bx;
    dx += 0x000c;
    sub_2da06();
    sub_3057b();
    memoryASet16(ds, 0x35e0, 0x0000);
    memoryASet16(ds, 0x35e2, 0x0000);
    memoryASet16(ds, 0x35e4, 0x0000);
    memoryASet16(ds, 0x416c, 0x003c);
}
void sub_2e4bc()
{
    cx = 0;
    dx = 0;
    ax = memoryAGet16(ds, 0x35f6);
    ax &= 0x007f;
    bx = memoryAGet16(ds, 0x4150);
    bx &= 0x007f;
    ax -= bx;
    if ((short)ax >= (short)0x000a)
        goto loc_2e4db;
    memoryASet(ds, 0x35c6, 0xff);
    goto loc_2e4e5;
loc_2e4db:
    if ((short)ax < (short)0x0012)
        goto loc_2e4e5;
    memoryASet(ds, 0x35c6, 0x00);
loc_2e4e5:
    if ((short)ax <= (short)0x001c)
        goto loc_2e4f1;
    memoryASet(ds, 0x35c4, 0xff);
    goto loc_2e4fb;
loc_2e4f1:
    if ((short)ax > (short)0x0012)
        goto loc_2e4fb;
    memoryASet(ds, 0x35c4, 0x00);
loc_2e4fb:
    ax = memoryAGet16(ds, 0x35f6);
    ax &= 0xff80;
    bx = memoryAGet16(ds, 0x4150);
    bx &= 0xff80;
    ax -= bx;
    if ((short)ax >= (short)0x0280)
        goto loc_2e516;
    memoryASet(ds, 0x35c2, 0xff);
    goto loc_2e520;
loc_2e516:
    if ((short)ax < (short)0x0500)
        goto loc_2e520;
    memoryASet(ds, 0x35c2, 0x00);
loc_2e520:
    if ((short)ax <= (short)0x0780)
        goto loc_2e52c;
    memoryASet(ds, 0x35c8, 0xff);
    goto loc_2e536;
loc_2e52c:
    if ((short)ax > (short)0x0500)
        goto loc_2e536;
    memoryASet(ds, 0x35c8, 0x00);
loc_2e536:
    if (memoryAGet(ds, 0x35c6) != 0xff)
        goto loc_2e542;
    cx -= 0x0002;
    goto loc_2e54c;
loc_2e542:
    if (memoryAGet(ds, 0x35c4) != 0xff)
        goto loc_2e54c;
    cx += 0x0002;
loc_2e54c:
    if (memoryAGet(ds, 0x35c2) != 0xff)
        goto loc_2e559;
    dx -= 0x0100;
    goto loc_2e564;
loc_2e559:
    if (memoryAGet(ds, 0x35c8) != 0xff)
        goto loc_2e564;
    dx += 0x0100;
loc_2e564:
    ax = memoryAGet16(ds, 0x4150);
    ax &= 0x007f;
    ax += cx;
    if ((short)ax >= (short)0x0000)
        goto loc_2e574;
    ax = 0x0000;
loc_2e574:
    if (ax <= 0x0028)
        goto loc_2e57c;
    ax = 0x0028;
loc_2e57c:
    bx = memoryAGet16(ds, 0x4150);
    bx &= 0xff80;
    bx += dx;
    if ((short)bx >= (short)0x0000)
        goto loc_2e58d;
    bx = 0x0000;
loc_2e58d:
    if (bx <= 0x0b00)
        goto loc_2e596;
    bx = 0x0b00;
loc_2e596:
    ax += bx;
    memoryASet16(ds, 0x4150, ax);
}
void sub_2e59c()
{
    memoryASet16(ds, 0x4158, 0x000c);
    bx = memoryAGet16(ds, 0x35f6);
    if ((short)memoryAGet16(ds, 0x35f6) <= (short)0x1400)
        goto loc_2e5b1;
    flags.zero = false;
    return;
loc_2e5b1:
    ax = memoryAGet16(ds, bx + 256);
    if (al == 0x00)
        goto loc_2e5c0;
    if (al == 0x1e)
        goto loc_2e5c0;
    goto loc_2e5c3;
loc_2e5c0:
    goto loc_2e6ad;
loc_2e5c3:
    if (al >= 0x20)
        goto loc_2e5ca;
    goto loc_2e5d4;
loc_2e5ca:
    if (al <= 0x2f)
        goto loc_2e5d1;
    goto loc_2e5d4;
loc_2e5d1:
    goto loc_2e6ad;
loc_2e5d4:
    if (ax == 0xff40)
        goto loc_2e5e1;
    if (ax == 0xff42)
        goto loc_2e5e1;
    goto loc_2e5e7;
loc_2e5e1:
    sub_2fabe();
    goto loc_2e6ad;
loc_2e5e7:
    if (ax == 0xff01)
        goto loc_2e5ef;
    goto loc_2e5f2;
loc_2e5ef:
    goto loc_2e6ad;
loc_2e5f2:
    if (ax >= 0xff70)
        goto loc_2e5fa;
    goto loc_2e60f;
loc_2e5fa:
    if (ax <= 0xff73)
        goto loc_2e602;
    goto loc_2e60f;
loc_2e602:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) + 0x0014);
    goto loc_2e6ad;
loc_2e60f:
    if (al >= 0x6c)
        goto loc_2e616;
    goto loc_2e623;
loc_2e616:
    if (al <= 0x6f)
        goto loc_2e61d;
    goto loc_2e623;
loc_2e61d:
    sub_2fafc();
    goto loc_2e6ad;
loc_2e623:
    if (al >= 0x30)
        goto loc_2e62a;
    goto loc_2e639;
loc_2e62a:
    if (al <= 0x33)
        goto loc_2e631;
    goto loc_2e639;
loc_2e631:
    memoryASet(ds, 0x35a6, 0xff);
    goto loc_2e6ad;
loc_2e639:
    if (al == 0x08)
        goto loc_2e640;
    goto loc_2e64d;
loc_2e640:
    memoryASet(ds, 0x35b0, 0xff);
    return;
    //   gap of 3 bytes
loc_2e64d:
    if (al == 0x0c)
        goto loc_2e654;
    goto loc_2e661;
loc_2e654:
    memoryASet(ds, 0x35a4, 0xff);
    return;
    //   gap of 4 bytes
loc_2e661:
    if (al >= 0x78)
        goto loc_2e668;
    goto loc_2e67c;
loc_2e668:
    if (al <= 0x7b)
        goto loc_2e66f;
    goto loc_2e67c;
loc_2e66f:
    memoryASet16(ds, 0x35e2, 0x04b0);
    return;
    //   gap of 3 bytes
loc_2e67c:
    if (al >= 0x7c)
        goto loc_2e683;
    goto loc_2e697;
loc_2e683:
    if (al <= 0x7f)
        goto loc_2e68a;
    goto loc_2e697;
loc_2e68a:
    memoryASet16(ds, 0x35e4, 0x04b0);
    return;
    //   gap of 3 bytes
loc_2e697:
    if (memoryAGet(ds, 0x35dc) == 0xff)
        goto loc_2e6a1;
    goto loc_2e6a9;
loc_2e6a1:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2e6ad;
loc_2e6a9:
    return;
loc_2e6ad:
    bx = memoryAGet16(ds, 0x35f6);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 256, 0x1110);
    memoryASet16(ds, bx + 384, 0x1111);
    memoryASet16(ds, 0x35f6, memoryAGet16(ds, 0x35f6) + 0x0100);
    flags.zero = al == al;
}
void sub_2e6d0()
{
    memoryASet16(ds, 0x4158, 0x0010);
    bx = memoryAGet16(ds, 0x35f6);
    ax = bx;
    ax &= 0x007f;
    if ((short)ax > (short)0x0002)
        goto loc_2e6e7;
    flags.zero = false;
    return;
loc_2e6e7:
    ax = memoryAGet16(ds, bx + 65534);
    if (al == 0x00)
        goto loc_2e6f5;
    if (al == 0x1e)
        goto loc_2e6f5;
    goto loc_2e6f8;
loc_2e6f5:
    goto loc_2e822;
loc_2e6f8:
    if (al >= 0x20)
        goto loc_2e6ff;
    goto loc_2e709;
loc_2e6ff:
    if (al <= 0x2f)
        goto loc_2e706;
    goto loc_2e709;
loc_2e706:
    goto loc_2e822;
loc_2e709:
    if (ax == 0xff40)
        goto loc_2e716;
    if (ax == 0xff42)
        goto loc_2e716;
    goto loc_2e71c;
loc_2e716:
    sub_2fabe();
    goto loc_2e822;
loc_2e71c:
    if (ax == 0xff01)
        goto loc_2e724;
    goto loc_2e727;
loc_2e724:
    goto loc_2e822;
loc_2e727:
    if (ax >= 0xff70)
        goto loc_2e72f;
    goto loc_2e744;
loc_2e72f:
    if (ax <= 0xff73)
        goto loc_2e737;
    goto loc_2e744;
loc_2e737:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) + 0x0014);
    goto loc_2e822;
loc_2e744:
    if (al >= 0x6c)
        goto loc_2e74b;
    goto loc_2e758;
loc_2e74b:
    if (al <= 0x6f)
        goto loc_2e752;
    goto loc_2e758;
loc_2e752:
    sub_2fafc();
    goto loc_2e822;
loc_2e758:
    if (ax == 0xff44)
        goto loc_2e760;
    goto loc_2e797;
loc_2e760:
    if (memoryAGet(ds, 0x35dc) != 0xff)
        goto loc_2e76f;
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2e822;
loc_2e76f:
    sub_308d1();
    if (al < 0x9e)
        goto loc_2e77b;
    goto loc_2e847;
loc_2e77b:
    ax = memoryAGet16(ds, bx + 65532);
    if (ax != 0xff00)
        goto loc_2e78f;
    memoryASet16(ds, bx + 65532, 0xff44);
    memoryASet16(ds, bx + 124, 0xffff);
    goto loc_2e794;
loc_2e78f:
    goto loc_2e847;
loc_2e794:
    goto loc_2e822;
loc_2e797:
    if (al >= 0x30)
        goto loc_2e79e;
    goto loc_2e7ad;
loc_2e79e:
    if (al <= 0x33)
        goto loc_2e7a5;
    goto loc_2e7ad;
loc_2e7a5:
    memoryASet(ds, 0x35a6, 0xff);
    goto loc_2e822;
loc_2e7ad:
    if (al == 0x08)
        goto loc_2e7b4;
    goto loc_2e7c1;
loc_2e7b4:
    memoryASet(ds, 0x35b0, 0xff);
    goto loc_2e847;
    //   gap of 3 bytes
loc_2e7c1:
    if (al == 0x0c)
        goto loc_2e7c8;
    goto loc_2e7d5;
loc_2e7c8:
    memoryASet(ds, 0x35a4, 0xff);
    goto loc_2e847;
    //   gap of 4 bytes
loc_2e7d5:
    if (al >= 0x78)
        goto loc_2e7dc;
    goto loc_2e7f0;
loc_2e7dc:
    if (al <= 0x7b)
        goto loc_2e7e3;
    goto loc_2e7f0;
loc_2e7e3:
    memoryASet16(ds, 0x35e2, 0x04b0);
    goto loc_2e847;
    //   gap of 3 bytes
loc_2e7f0:
    if (al >= 0x7c)
        goto loc_2e7f7;
    goto loc_2e80b;
loc_2e7f7:
    if (al <= 0x7f)
        goto loc_2e7fe;
    goto loc_2e80b;
loc_2e7fe:
    memoryASet16(ds, 0x35e4, 0x04b0);
    goto loc_2e847;
    //   gap of 3 bytes
loc_2e80b:
    if (memoryAGet(ds, 0x35dc) == 0xff)
        goto loc_2e815;
    goto loc_2e81d;
loc_2e815:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2e822;
loc_2e81d:
    goto loc_2e847;
loc_2e822:
    bx = memoryAGet16(ds, 0x35f6);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 65534, 0x1110);
    memoryASet16(ds, bx + 126, 0x1111);
    memoryASet16(ds, 0x35f6, memoryAGet16(ds, 0x35f6) - 0x0002);
    memoryASet16(ds, 0x4158, 0x0000);
    flags.zero = al == al;
loc_2e847:
    memoryASet(ds, 0x358e, 0x00);
}
void sub_2e84d()
{
    memoryASet16(ds, 0x4158, 0x0014);
    bx = memoryAGet16(ds, 0x35f6);
    ax = bx;
    ax &= 0x007f;
    if ((short)ax < (short)0x004c)
        goto loc_2e864;
    flags.zero = false;
    return;
loc_2e864:
    ax = memoryAGet16(ds, bx + 2);
    if (al == 0x00)
        goto loc_2e872;
    if (al == 0x1e)
        goto loc_2e872;
    goto loc_2e875;
loc_2e872:
    goto loc_2e99e;
loc_2e875:
    if (al >= 0x20)
        goto loc_2e87c;
    goto loc_2e886;
loc_2e87c:
    if (al <= 0x2f)
        goto loc_2e883;
    goto loc_2e886;
loc_2e883:
    goto loc_2e99e;
loc_2e886:
    if (ax == 0xff40)
        goto loc_2e893;
    if (ax == 0xff42)
        goto loc_2e893;
    goto loc_2e899;
loc_2e893:
    sub_2fabe();
    goto loc_2e99e;
loc_2e899:
    if (ax == 0xff01)
        goto loc_2e8a1;
    goto loc_2e8a4;
loc_2e8a1:
    goto loc_2e99e;
loc_2e8a4:
    if (ax >= 0xff70)
        goto loc_2e8ac;
    goto loc_2e8c1;
loc_2e8ac:
    if (ax <= 0xff73)
        goto loc_2e8b4;
    goto loc_2e8c1;
loc_2e8b4:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) + 0x0014);
    goto loc_2e99e;
loc_2e8c1:
    if (al >= 0x6c)
        goto loc_2e8c8;
    goto loc_2e8d5;
loc_2e8c8:
    if (al <= 0x6f)
        goto loc_2e8cf;
    goto loc_2e8d5;
loc_2e8cf:
    sub_2fafc();
    goto loc_2e99e;
loc_2e8d5:
    if (ax == 0xff44)
        goto loc_2e8dd;
    goto loc_2e915;
loc_2e8dd:
    if (memoryAGet(ds, 0x35dc) != 0xff)
        goto loc_2e8ec;
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2e99e;
loc_2e8ec:
    sub_308d1();
    if (al < 0x9e)
        goto loc_2e8f8;
    goto loc_2e9c4;
loc_2e8f8:
    ax = memoryAGet16(ds, bx + 4);
    if (ax != 0xff00)
        goto loc_2e90d;
    memoryASet16(ds, bx + 4, 0xff44);
    memoryASet16(ds, bx + 132, 0xffff);
    goto loc_2e912;
loc_2e90d:
    goto loc_2e9c4;
loc_2e912:
    goto loc_2e99e;
loc_2e915:
    if (al >= 0x30)
        goto loc_2e91c;
    goto loc_2e92b;
loc_2e91c:
    if (al <= 0x33)
        goto loc_2e923;
    goto loc_2e92b;
loc_2e923:
    memoryASet(ds, 0x35a6, 0xff);
    goto loc_2e99e;
loc_2e92b:
    if (memoryAGet(ds, 0x35dc) == 0xff)
        goto loc_2e935;
    goto loc_2e93d;
loc_2e935:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2e99e;
loc_2e93d:
    if (al == 0x08)
        goto loc_2e944;
    goto loc_2e950;
loc_2e944:
    memoryASet(ds, 0x35b0, 0xff);
    goto loc_2e9c4;
    //   gap of 3 bytes
loc_2e950:
    if (al == 0x0c)
        goto loc_2e957;
    goto loc_2e963;
loc_2e957:
    memoryASet(ds, 0x35a4, 0xff);
    goto loc_2e9c4;
    //   gap of 3 bytes
loc_2e963:
    if (al >= 0x78)
        goto loc_2e96a;
    goto loc_2e97e;
loc_2e96a:
    if (al <= 0x7b)
        goto loc_2e971;
    goto loc_2e97e;
loc_2e971:
    memoryASet16(ds, 0x35e2, 0x04b0);
    goto loc_2e9c4;
    //   gap of 3 bytes
loc_2e97e:
    if (al >= 0x7c)
        goto loc_2e985;
    goto loc_2e999;
loc_2e985:
    if (al <= 0x7f)
        goto loc_2e98c;
    goto loc_2e999;
loc_2e98c:
    memoryASet16(ds, 0x35e4, 0x04b0);
    goto loc_2e9c4;
    //   gap of 3 bytes
loc_2e999:
    goto loc_2e9c4;
loc_2e99e:
    bx = memoryAGet16(ds, 0x35f6);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 2, 0x1110);
    memoryASet16(ds, bx + 130, 0x1111);
    memoryASet16(ds, 0x35f6, memoryAGet16(ds, 0x35f6) + 0x0002);
    memoryASet16(ds, 0x4158, 0x0008);
    flags.zero = al == al;
loc_2e9c4:
    memoryASet(ds, 0x358e, 0x08);
}
void sub_2e9ca()
{
    memoryASet16(ds, 0x4158, 0x0004);
    bx = memoryAGet16(ds, 0x35f6);
    if ((short)bx >= (short)0x0200)
        goto loc_2e9dd;
    flags.zero = false;
    return;
loc_2e9dd:
    ax = memoryAGet16(ds, bx + 65280);
    if (al == 0x00)
        goto loc_2e9ec;
    if (al == 0x1e)
        goto loc_2e9ec;
    goto loc_2e9ef;
loc_2e9ec:
    goto loc_2eaf6;
loc_2e9ef:
    if (al >= 0x20)
        goto loc_2e9f6;
    goto loc_2ea00;
loc_2e9f6:
    if (al <= 0x2f)
        goto loc_2e9fd;
    goto loc_2ea00;
loc_2e9fd:
    goto loc_2eaf6;
loc_2ea00:
    if (ax == 0xff40)
        goto loc_2ea0d;
    if (ax == 0xff42)
        goto loc_2ea0d;
    goto loc_2ea13;
loc_2ea0d:
    sub_2fabe();
    goto loc_2eaf6;
loc_2ea13:
    if (ax == 0xff01)
        goto loc_2ea1b;
    goto loc_2ea1e;
loc_2ea1b:
    goto loc_2eaf6;
loc_2ea1e:
    if (ax >= 0xff70)
        goto loc_2ea26;
    goto loc_2ea3b;
loc_2ea26:
    if (ax <= 0xff73)
        goto loc_2ea2e;
    goto loc_2ea3b;
loc_2ea2e:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) + 0x0014);
    goto loc_2eaf6;
loc_2ea3b:
    if (al >= 0x6c)
        goto loc_2ea42;
    goto loc_2ea4f;
loc_2ea42:
    if (al <= 0x6f)
        goto loc_2ea49;
    goto loc_2ea4f;
loc_2ea49:
    sub_2fafc();
    goto loc_2eaf6;
loc_2ea4f:
    if (al >= 0x30)
        goto loc_2ea56;
    goto loc_2ea65;
loc_2ea56:
    if (al <= 0x33)
        goto loc_2ea5d;
    goto loc_2ea65;
loc_2ea5d:
    memoryASet(ds, 0x35a6, 0xff);
    goto loc_2eaf6;
loc_2ea65:
    if (memoryAGet(ds, 0x35dc) == 0xff)
        goto loc_2ea6f;
    goto loc_2ea77;
loc_2ea6f:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    goto loc_2eaf6;
loc_2ea77:
    if (al == 0x08)
        goto loc_2ea7e;
    goto loc_2ea8b;
loc_2ea7e:
    memoryASet(ds, 0x35b0, 0xff);
    return;
    //   gap of 3 bytes
loc_2ea8b:
    if (al == 0x0c)
        goto loc_2ea92;
    goto loc_2ea9f;
loc_2ea92:
    memoryASet(ds, 0x35a4, 0xff);
    return;
    //   gap of 4 bytes
loc_2ea9f:
    if (al >= 0x78)
        goto loc_2eaa6;
    goto loc_2eaba;
loc_2eaa6:
    if (al <= 0x7b)
        goto loc_2eaad;
    goto loc_2eaba;
loc_2eaad:
    memoryASet16(ds, 0x35e2, 0x04b0);
    return;
    //   gap of 3 bytes
loc_2eaba:
    if (al >= 0x7c)
        goto loc_2eac1;
    goto loc_2ead5;
loc_2eac1:
    if (al <= 0x7f)
        goto loc_2eac8;
    goto loc_2ead5;
loc_2eac8:
    memoryASet16(ds, 0x35e4, 0x04b0);
    return;
    //   gap of 3 bytes
loc_2ead5:
    if (al == 0x46)
        goto loc_2eae0;
    if (al == 0x42)
        goto loc_2eae0;
    goto loc_2eaf2;
loc_2eae0:
    ax = 0x0001;
    bx -= 0x0102;
    sub_2f8c5();
    return;
    //   gap of 4 bytes
loc_2eaf2:
    return;
loc_2eaf6:
    bx = memoryAGet16(ds, 0x35f6);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 65280, 0x1110);
    memoryASet16(ds, bx + 65408, 0x1111);
    memoryASet16(ds, 0x35f6, memoryAGet16(ds, 0x35f6) - 0x0100);
    flags.zero = al == al;
}
void sub_2eb18()
{
    goto loc_2eb18;
loc_2d4a1:
    memoryASet(ds, 0x4166, 0x00);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    sub_32bab();
    ax = 0x0002;
    interrupt(0x10);
    sub_31177();
    sub_2fd19();
    ax = 0x4c00;
    interrupt(0x21);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    flags.direction = false;
    si = 0x0;
    dx = 0x0016;
loc_2d4cb:
    cx = 0x0028;
    push(si);
loc_2d4cf:
    lodsw<MemAuto, DirAuto>();
    if (ax < 0xff48)
        goto loc_2d4e2;
    if (ax > 0xff4b)
        goto loc_2d4e2;
    bx = si;
    bx -= 0x0002;
    sub_31073();
loc_2d4e2:
    if (--cx)
        goto loc_2d4cf;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_2d4cb;
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    return;
    //   gap of 5671 bytes
loc_2eb18:
    sub_2ed94();
    memoryASet16(ds, 0x3ce8, 0xffff);
    sub_2ec93();
    ax = memoryAGet16(ds, 0x3ce0);
    memoryASet16(ds, 0x35ea, 0x0000);
    if (ax == 0xffff)
        goto loc_2eb35;
    memoryASet16(ds, 0x35ea, ax);
loc_2eb35:
    sub_2ec26();
    sub_3057b();
loc_2eb3b:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2eb47;
    ah = 0;
    interrupt(0x16);
    goto loc_2eb3b;
loc_2eb47:
    if (memoryAGet(ds, 0x35b6) != 0xff)
        goto loc_2eb51;
    sub_329d0();
loc_2eb51:
    if (memoryAGet(cs, 0x001c) != 0x00)
        goto loc_2eb63;
    if (memoryAGet(cs, 0x002a) != 0x00)
        goto loc_2eb63;
    goto loc_2eb6f;
loc_2eb63:
    sub_2ebea();
    memoryASet16(ds, 0x35ea, memoryAGet16(ds, 0x35ea) - 1);
    sub_2ec26();
    goto loc_2eb8b;
loc_2eb6f:
    if (memoryAGet(cs, 0x001d) != 0x00)
        goto loc_2eb81;
    if (memoryAGet(cs, 0x002b) != 0x00)
        goto loc_2eb81;
    goto loc_2eb8b;
loc_2eb81:
    sub_2ebea();
    memoryASet16(ds, 0x35ea, memoryAGet16(ds, 0x35ea) + 1);
    sub_2ec26();
loc_2eb8b:
    if (memoryAGet(cs, 0x0022) != 0x00)
        goto loc_2eb9d;
    if (memoryAGet(cs, 0x0030) != 0x00)
        goto loc_2eb9d;
    goto loc_2eb9f;
loc_2eb9d:
    goto loc_2ebc1;
loc_2eb9f:
    sync();
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2ebbf;
    ah = 0;
    interrupt(0x16);
    if (al == 0x0d)
        goto loc_2ebc1;
    if (al == 0x71)
        goto loc_2ebb7;
    if (al == 0x51)
        goto loc_2ebb7;
    goto loc_2ebbf;
loc_2ebb7:
    sub_2edc5();
    if (flags.carry)
        goto loc_2ebbf;
    goto loc_2d4a1;
loc_2ebbf:
    goto loc_2eb47;
loc_2ebc1:
    si = memoryAGet16(ds, 0x35ea);
    memoryASet16(ds, 0x3ce0, si);
    si += 0x0000;
    si <<= 1;
    ax = memoryAGet16(ds, si + 18122);
    memoryASet16(ds, 0x46f4, ax);
}
void sub_2ebea()
{
    memoryASet(ds, 0x4164, 0x02);
    si = memoryAGet16(ds, 0x35ea);
    si <<= 1;
    ax = memoryAGet16(cs, si + 7206);
    bx = 0x002e;
    cx = memoryAGet16(cs, si + 7216);
    dx = 0x0061;
    si = 0;
    memoryASet(cs, 0x0000, 0x00);
    sub_2da06();
    ax -= 0x0002;
    bx -= 0x0002;
    cx += 0x0002;
    dx += 0x0002;
    memoryASet(cs, 0x0000, 0x00);
    sub_2da06();
}
void sub_2ec26()
{
    if ((short)memoryAGet16(ds, 0x35ea) >= (short)0x0000)
        goto loc_2ec33;
    memoryASet16(ds, 0x35ea, 0x0004);
loc_2ec33:
    if ((short)memoryAGet16(ds, 0x35ea) <= (short)0x0004)
        goto loc_2ec40;
    memoryASet16(ds, 0x35ea, 0x0000);
loc_2ec40:
    si = memoryAGet16(ds, 0x35ea);
    si <<= 1;
    ax = memoryAGet16(cs, si + 7206);
    bx = 0x002e;
    cx = memoryAGet16(cs, si + 7216);
    dx = 0x0061;
    si = 0;
    sub_2da06();
    ax -= 0x0002;
    bx -= 0x0002;
    cx += 0x0002;
    dx += 0x0002;
    sub_2da06();
    memoryASet16(cs, 0x0002, 0x0000);
loc_2ec71:
    sync();
    al = memoryAGet(cs, 0x001c);
    al += memoryAGet(cs, 0x001d);
    al += memoryAGet(cs, 0x002a);
    al += memoryAGet(cs, 0x002b);
    if (!al)
        return;
    if (memoryAGet16(cs, 0x0002) >= 0x000a)
        return;
    goto loc_2ec71;
}
void sub_2ec93()
{
    si = 0x39df;
    dx = 0x3cd0;
    sub_3059d();
    bx = ax;
    memoryASet16(ds, 0x35e6, ax);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_2ecad;
    goto loc_2ed35;
loc_2ecad:
    al = 0;
    sub_312f4();
    dx = memoryAGet16(ds, 0x46f2);
    push(ds);
    ds = dx;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2ed13;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2ed13;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2ed13;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
loc_2ed13:
    ds = pop();
    if (!flags.carry)
        goto loc_2ed1b;
    memoryASet(ds, 0x359c, 0xff);
loc_2ed1b:
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_2ed2a;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_2ed2a;
    goto loc_2ed2d;
loc_2ed2a:
    sub_2f112();
loc_2ed2d:
    al = 0x01;
    sub_312f4();
    return;
loc_2ed35:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_2ed3f;
    goto loc_2ed59;
loc_2ed3f:
    al = 0;
    sub_312f4();
    es = memoryAGet16(ds, 0x46f2);
    di = 0;
    bx = memoryAGet16(ds, 0x35e6);
    sub_30ab8();
    al = 0x01;
    sub_312f4();
    return;
loc_2ed59:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2ed63;
    return;
loc_2ed63:
    ax = 0x1000;
    es = ax;
    bx = memoryAGet16(ds, 0x35e6);
    di = 0x49ea;
    sub_308e1();
    flags.direction = false;
    es = memoryAGet16(ds, 0x46f2);
    di = 0;
    si = 0x49ea;
    cx = 0x4000;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_2ed84()
{
    ax = 0xfefe;
    flags.direction = false;
    di = 0x3cf0;
    push(ds);
    es = pop();
    cx = 0x01b8;
    rep_stosw<MemAuto, DirAuto>();
}
void sub_2ed94()
{
    push(es);
    es = memoryAGet16(ds, 0x46f2);
    if (memoryAGet16(ds, 0x3598) != 0x0001)
        goto loc_2edae;
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    cx = 0x1000;
    goto loc_2edbd;
loc_2edae:
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2edba;
    cx = 0x4000;
    goto loc_2edbd;
loc_2edba:
    cx = 0x2000;
loc_2edbd:
    ax = 0;
    di = 0;
    rep_stosw<MemAuto, DirAuto>();
    es = pop();
}
// INJECT: Error: cannot inject carry flag in sub_2edc5()!
void sub_2edc5()
{
    memoryASet(ds, 0x35bc, 0xff);
    push(memoryAGet16(ds, 0x4166));
    memoryASet(ds, 0x4166, 0x00);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    sub_311a5();
    si = 0x3a48;
    memoryASet16(ds, 0x4154, 0x000e);
    memoryASet16(ds, 0x4156, 0x0780);
    al = memoryAGet(ds, 0x3562);
    memoryASet(ds, 0x3564, al);
    sub_3074d();
    si = 0x3a55;
    memoryASet16(ds, 0x4154, 0x000e);
    memoryASet16(ds, 0x4156, 0x08c0);
    sub_3074d();
loc_2ee08:
    ah = 0;
    interrupt(0x16);
    al |= 0x20;
    if (al == 0x79)
        goto loc_2ee18;
    if (al == 0x6e)
        goto loc_2ee18;
    goto loc_2ee08;
loc_2ee18:
    flags.carry = false;
    if (al != 0x6e)
        goto loc_2ee1e;
    flags.carry = true;
loc_2ee1e:
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    sub_310a3();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    memoryASet16(ds, 0x4166, pop());
    memoryASet(ds, 0x35bc, 0x00);
}
void sub_2ee2d()
{
    push(ds);
    push(es);
    memoryASet16(ds, 0x3550, 0x0000);
    memoryASet16(ds, 0x3552, 0x0000);
    memoryASet16(ds, 0x3558, 0x0000);
    memoryASet16(ds, 0x355a, 0x0000);
    memoryASet(ds, 0x35a2, 0x00);
    memoryASet(ds, 0x35a4, 0x00);
    memoryASet(ds, 0x35b0, 0x00);
    memoryASet(ds, 0x35be, 0x00);
    memoryASet(ds, 0x35ce, 0x00);
    flags.direction = false;
    si = 0x0;
    bx = si;
    bx += 0x0370;
    di = 0x0;
    ax = 0x1000;
    es = ax;
    ax = 0x1cda;
    ds = ax;
loc_2ee79:
    cx = 0;
    push(di);
loc_2ee7c:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_2ee84;
    goto loc_2ee93;
loc_2ee84:
    memoryASet16(es, di, 0xff00);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2ee93:
    if (al == 0x01)
        goto loc_2ee9a;
    goto loc_2eea9;
loc_2ee9a:
    memoryASet16(es, di, 0xff01);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2eea9:
    if (al == 0x02)
        goto loc_2eeb0;
    goto loc_2eebf;
loc_2eeb0:
    memoryASet16(es, di, 0xff02);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2eebf:
    if (al == 0x03)
        goto loc_2eec6;
    goto loc_2eed5;
loc_2eec6:
    memoryASet16(es, di, 0xff03);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2eed5:
    if (al == 0x04)
        goto loc_2eedc;
    goto loc_2eeeb;
loc_2eedc:
    memoryASet16(es, di, 0xff74);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2eeeb:
    if (al == 0x08)
        goto loc_2eef2;
    goto loc_2ef01;
loc_2eef2:
    memoryASet16(es, di, 0xff15);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2ef01:
    if (al == 0x0c)
        goto loc_2ef08;
    goto loc_2ef17;
loc_2ef08:
    memoryASet16(es, di, 0xff04);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2ef17:
    if (al == 0x10)
        goto loc_2ef1e;
    goto loc_2ef33;
loc_2ef1e:
    memoryASet16(es, di, 0xff48);
    memoryASet16(es, di + 128, 0xffff);
    memoryASet(es, 0x35a2, 0xff);
    goto loc_2f0ec;
loc_2ef33:
    if (al == 0x20)
        goto loc_2ef3a;
    goto loc_2ef53;
loc_2ef3a:
    memoryASet16(es, di, 0x1110);
    memoryASet16(es, di + 128, 0x1111);
    memoryASet16(es, 0x35f6, di);
    memoryASet16(es, 0x3cee, di);
    goto loc_2f0ec;
loc_2ef53:
    if (al == 0x28)
        goto loc_2ef5a;
    goto loc_2ef69;
loc_2ef5a:
    memoryASet16(es, di, 0xff44);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2ef69:
    if (al >= 0x2c)
        goto loc_2ef70;
    goto loc_2ef8a;
loc_2ef70:
    if (al <= 0x2d)
        goto loc_2ef77;
    goto loc_2ef8a;
loc_2ef77:
    memoryASet(es, di, 0x8c);
    memoryASet(es, di + 1, 0xf8);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2ef8a:
    if (al == 0x2e)
        goto loc_2ef91;
    goto loc_2efa4;
loc_2ef91:
    memoryASet(es, di, 0x8c);
    memoryASet(es, di + 1, 0xfa);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2efa4:
    if (al == 0x30)
        goto loc_2efab;
    goto loc_2efbe;
loc_2efab:
    memoryASet(es, di, 0x8c);
    memoryASet(es, di + 1, 0xfb);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2efbe:
    if (al == 0x34)
        goto loc_2efc5;
    goto loc_2efd8;
loc_2efc5:
    memoryASet(es, di, 0x90);
    memoryASet(es, di + 1, 0xf9);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2efd8:
    if (al == 0x35)
        goto loc_2efdf;
    goto loc_2eff2;
loc_2efdf:
    memoryASet(es, di, 0x90);
    memoryASet(es, di + 1, 0xfa);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2eff2:
    if (al == 0x36)
        goto loc_2eff9;
    goto loc_2f00c;
loc_2eff9:
    memoryASet(es, di, 0x90);
    memoryASet(es, di + 1, 0xfb);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f00c:
    if (al == 0x37)
        goto loc_2f013;
    goto loc_2f026;
loc_2f013:
    memoryASet(es, di, 0x90);
    memoryASet(es, di + 1, 0xf8);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f026:
    if (al == 0x38)
        goto loc_2f02d;
    goto loc_2f03c;
loc_2f02d:
    memoryASet16(es, di, 0xff0c);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f03c:
    if (al == 0x70)
        goto loc_2f043;
    goto loc_2f057;
loc_2f043:
    memoryASet16(es, di, 0xff78);
    memoryASet16(es, di + 128, 0xffff);
    memoryASet16(es, 0x3550, di);
    goto loc_2f0ec;
loc_2f057:
    if (al == 0x74)
        goto loc_2f05e;
    goto loc_2f06d;
loc_2f05e:
    memoryASet16(es, di, 0xff07);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f06d:
    if (al == 0x78)
        goto loc_2f074;
    goto loc_2f083;
loc_2f074:
    memoryASet16(es, di, 0xff6c);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f083:
    if (al == 0x7c)
        goto loc_2f08a;
    goto loc_2f099;
loc_2f08a:
    memoryASet16(es, di, 0xff70);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f099:
    if (al == 0x84)
        goto loc_2f0a0;
    goto loc_2f0b4;
loc_2f0a0:
    memoryASet16(es, di, 0xff7c);
    memoryASet16(es, di + 128, 0xffff);
    memoryASet16(es, 0x3558, di);
    goto loc_2f0ec;
loc_2f0b4:
    if (al == 0x88)
        goto loc_2f0bb;
    goto loc_2f0ca;
loc_2f0bb:
    memoryASet16(es, di, 0xff40);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f0ca:
    if (al == 0xc4)
        goto loc_2f0d1;
    goto loc_2f0e0;
loc_2f0d1:
    memoryASet16(es, di, 0xff08);
    memoryASet16(es, di + 128, 0xffff);
    goto loc_2f0ec;
loc_2f0e0:
    memoryASet16(es, di, 0xff01);
    memoryASet16(es, di + 128, 0xffff);
loc_2f0ec:
    di += 0x0002;
    cx++;
    if (cx >= 0x0028)
        goto loc_2f0f8;
    goto loc_2ee7c;
loc_2f0f8:
    di = pop();
    di += 0x0100;
    if (di >= 0x1600)
        goto loc_2f106;
    goto loc_2ee79;
loc_2f106:
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x46ec, 0x0050);
}
void sub_2f112()
{
    goto loc_2f112;
loc_2d4a1:
    memoryASet(ds, 0x4166, 0x00);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    sub_32bab();
    ax = 0x0002;
    interrupt(0x10);
    sub_31177();
    sub_2fd19();
    ax = 0x4c00;
    interrupt(0x21);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    flags.direction = false;
    si = 0x0;
    dx = 0x0016;
loc_2d4cb:
    cx = 0x0028;
    push(si);
loc_2d4cf:
    lodsw<MemAuto, DirAuto>();
    if (ax < 0xff48)
        goto loc_2d4e2;
    if (ax > 0xff4b)
        goto loc_2d4e2;
    bx = si;
    bx -= 0x0002;
    sub_31073();
loc_2d4e2:
    if (--cx)
        goto loc_2d4cf;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_2d4cb;
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    return;
    //   gap of 7201 bytes
loc_2f112:
    ax = 0x0002;
    interrupt(0x10);
    dx = 0x35fc;
    ah = 0x09;
    interrupt(0x21);
    ah = 0;
    interrupt(0x16);
    goto loc_2d4a1;
}
void sub_2f126()
{
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2f130;
    goto loc_2f2e8;
loc_2f130:
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2f13a;
    goto loc_2f5b4;
loc_2f13a:
    push(bp);
    bp = memoryAGet16(ds, 0x46f2);
    dx = 0x000b;
    si = memoryAGet16(ds, 0x4150);
    si += 0x0a26;
    di = 0x3cf0;
    di += 0x0346;
    memoryASet16(ds, 0x4156, 0x1cc0);
loc_2f158:
    cx = 0x0026;
loc_2f15b:
    ax = memoryAGet16(ds, si);
    si--;
    if (al == 0x11)
        goto loc_2f168;
    if (al >= 0xf8)
        goto loc_2f168;
    goto loc_2f16d;
loc_2f168:
    memoryASet(ds, di, al);
    goto loc_2f2cc;
loc_2f16d:
    if (al < 0x8c)
        goto loc_2f178;
    if (al >= 0x94)
        goto loc_2f178;
    goto loc_2f19c;
loc_2f178:
    if (al < 0x80)
        goto loc_2f185;
    if (al == memoryAGet(ds, di))
        goto loc_2f185;
    memoryASet(ds, di, al);
    goto loc_2f19c;
loc_2f185:
    if (al != 0x10)
        goto loc_2f192;
    sub_3075c();
    memoryASet(ds, di, 0x10);
    goto loc_2f2cc;
loc_2f192:
    if (al == memoryAGet(ds, di))
        goto loc_2f199;
    goto loc_2f271;
loc_2f199:
    goto loc_2f2cc;
loc_2f19c:
    ax = cx;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    if (al == 0x8c)
        goto loc_2f1ad;
    goto loc_2f1cc;
loc_2f1ad:
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    ax += memoryAGet16(ds, si + 129);
    memoryASet(ds, si + 129, memoryAGet(ds, si + 129) ^ 0x01);
    ax += 0x0002;
    ax <<= 1;
    bx = 0x440c;
    bx += ax;
    goto loc_2f26d;
loc_2f1cc:
    if (al == 0x90)
        goto loc_2f1d3;
    goto loc_2f1e4;
loc_2f1d3:
    ax = memoryAGet16(ds, 0x35fa);
    ax &= 0x0003;
    ax <<= 1;
    bx = 0x441c;
    bx += ax;
    goto loc_2f26d;
loc_2f1e4:
    if (al >= 0xa0)
        goto loc_2f1eb;
    goto loc_2f22a;
loc_2f1eb:
    if (al <= 0xa7)
        goto loc_2f1f2;
    goto loc_2f22a;
loc_2f1f2:
    bl = al;
    bl -= 0xa0;
    if (!bl)
        goto loc_2f206;
    if (bl != 0x07)
        goto loc_2f204;
    bl = 0x02;
    goto loc_2f206;
loc_2f204:
    bl = 0x01;
loc_2f206:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4424;
    bx += ax;
    goto loc_2f26d;
loc_2f22a:
    if (al >= 0xb0)
        goto loc_2f231;
    goto loc_2f26d;
loc_2f231:
    if (al <= 0xb7)
        goto loc_2f238;
    goto loc_2f26d;
loc_2f238:
    bl = al;
    bl -= 0xb0;
    if (!bl)
        goto loc_2f24c;
    if (bl != 0x07)
        goto loc_2f24a;
    bl = 0x02;
    goto loc_2f24c;
loc_2f24a:
    bl = 0x01;
loc_2f24c:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4454;
    bx += ax;
loc_2f26d:
    flags.direction = false;
    goto loc_2f286;
loc_2f271:
    flags.direction = false;
    ax = cx;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    ah = 0;
    ax <<= 1;
    bx = 0x430c;
    bx += ax;
loc_2f286:
    push(di);
    push(si);
    push(es);
    es = memoryAGet16(ds, 0x46f2);
    di = memoryAGet16(ds, 0x4156);
    di += memoryAGet16(ds, 0x4154);
    si = memoryAGet16(ds, bx);
    si += 0x2000;
    push(dx);
    dx = 0x03ce;
    ah = 0x01;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(ds);
    push(es);
    ds = pop();
    push(dx);
    dx = 0x0010;
loc_2f2b5:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    si += 0x0026;
    dx--;
    if (dx != 0)
        goto loc_2f2b5;
    dx = 0x03ce;
    ax = 0x0005;
    out(dx, ax);
    dx = pop();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
loc_2f2cc:
    di--;
    di--;
    si--;
    cx--;
    cx--;
    if ((short)cx < 0)
        goto loc_2f2d6;
    goto loc_2f15b;
loc_2f2d6:
    si -= 0x00d8;
    memoryASet16(ds, 0x4156, memoryAGet16(ds, 0x4156) - 0x0280);
    dx--;
    if (dx == 0)
        goto loc_2f2e6;
    goto loc_2f158;
loc_2f2e6:
    bp = pop();
    return;
loc_2f2e8:
    push(bp);
    bp = memoryAGet16(ds, 0x46f2);
    dx = 0x000b;
    si = memoryAGet16(ds, 0x4150);
    si += 0x0a26;
    di = 0x3cf0;
    di += 0x0346;
    memoryASet16(ds, 0x4156, 0x1cc0);
loc_2f306:
    cx = 0x0026;
loc_2f309:
    ax = memoryAGet16(ds, si);
    si--;
    if (al == 0x11)
        goto loc_2f316;
    if (al >= 0xf8)
        goto loc_2f316;
    goto loc_2f31b;
loc_2f316:
    memoryASet(ds, di, al);
    goto loc_2f598;
loc_2f31b:
    if (al < 0x8c)
        goto loc_2f326;
    if (al >= 0x94)
        goto loc_2f326;
    goto loc_2f34a;
loc_2f326:
    if (al < 0x80)
        goto loc_2f333;
    if (al == memoryAGet(ds, di))
        goto loc_2f333;
    memoryASet(ds, di, al);
    goto loc_2f34a;
loc_2f333:
    if (al != 0x10)
        goto loc_2f340;
    sub_3075c();
    memoryASet(ds, di, 0x10);
    goto loc_2f598;
loc_2f340:
    if (al == memoryAGet(ds, di))
        goto loc_2f347;
    goto loc_2f4d1;
loc_2f347:
    goto loc_2f598;
loc_2f34a:
    ax = cx;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    if (al == 0x8c)
        goto loc_2f35d;
    goto loc_2f37c;
loc_2f35d:
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    ax += memoryAGet16(ds, si + 129);
    memoryASet(ds, si + 129, memoryAGet(ds, si + 129) ^ 0x01);
    ax += 0x0002;
    ax <<= 1;
    bx = 0x440c;
    bx += ax;
    goto loc_2f41d;
loc_2f37c:
    if (al == 0x90)
        goto loc_2f383;
    goto loc_2f394;
loc_2f383:
    ax = memoryAGet16(ds, 0x35fa);
    ax &= 0x0003;
    ax <<= 1;
    bx = 0x441c;
    bx += ax;
    goto loc_2f41d;
loc_2f394:
    if (al >= 0xa0)
        goto loc_2f39b;
    goto loc_2f3da;
loc_2f39b:
    if (al <= 0xa7)
        goto loc_2f3a2;
    goto loc_2f3da;
loc_2f3a2:
    bl = al;
    bl -= 0xa0;
    if (!bl)
        goto loc_2f3b6;
    if (bl != 0x07)
        goto loc_2f3b4;
    bl = 0x02;
    goto loc_2f3b6;
loc_2f3b4:
    bl = 0x01;
loc_2f3b6:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4424;
    bx += ax;
    goto loc_2f41d;
loc_2f3da:
    if (al >= 0xb0)
        goto loc_2f3e1;
    goto loc_2f41d;
loc_2f3e1:
    if (al <= 0xb7)
        goto loc_2f3e8;
    goto loc_2f41d;
loc_2f3e8:
    bl = al;
    bl -= 0xb0;
    if (!bl)
        goto loc_2f3fc;
    if (bl != 0x07)
        goto loc_2f3fa;
    bl = 0x02;
    goto loc_2f3fc;
loc_2f3fa:
    bl = 0x01;
loc_2f3fc:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4454;
    bx += ax;
loc_2f41d:
    flags.direction = false;
    push(di);
    push(si);
    push(es);
    es = bp;
    di = memoryAGet16(ds, 0x4156);
    di += memoryAGet16(ds, 0x4154);
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    si = pop();
    di = pop();
    goto loc_2f598;
loc_2f4d1:
    ax = cx;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    ah = 0;
    ax <<= 1;
    flags.direction = false;
    bx = 0x430c;
    bx += ax;
    push(di);
    push(si);
    push(es);
    es = bp;
    di = memoryAGet16(ds, 0x4156);
    di += memoryAGet16(ds, 0x4154);
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    si = pop();
    di = pop();
loc_2f598:
    di--;
    di--;
    si--;
    cx--;
    cx--;
    if ((short)cx < 0)
        goto loc_2f5a2;
    goto loc_2f309;
loc_2f5a2:
    si -= 0x00d8;
    memoryASet16(ds, 0x4156, memoryAGet16(ds, 0x4156) - 0x0280);
    dx--;
    if (dx == 0)
        goto loc_2f5b2;
    goto loc_2f306;
loc_2f5b2:
    bp = pop();
    return;
loc_2f5b4:
    push(bp);
    bp = memoryAGet16(ds, 0x46f2);
    dx = 0x000b;
    si = memoryAGet16(ds, 0x4150);
    si += 0x0a26;
    di = 0x3cf0;
    di += 0x0346;
    memoryASet16(ds, 0x4156, 0x1cc0);
loc_2f5d2:
    cx = 0x0026;
loc_2f5d5:
    ax = memoryAGet16(ds, si);
    si--;
    if (al == 0x11)
        goto loc_2f5e2;
    if (al >= 0xf8)
        goto loc_2f5e2;
    goto loc_2f5e7;
loc_2f5e2:
    memoryASet(ds, di, al);
    goto loc_2f8a8;
loc_2f5e7:
    if (al < 0x8c)
        goto loc_2f5f2;
    if (al >= 0x94)
        goto loc_2f5f2;
    goto loc_2f616;
loc_2f5f2:
    if (al < 0x80)
        goto loc_2f5ff;
    if (al == memoryAGet(ds, di))
        goto loc_2f5ff;
    memoryASet(ds, di, al);
    goto loc_2f616;
loc_2f5ff:
    if (al != 0x10)
        goto loc_2f60c;
    sub_3075c();
    memoryASet(ds, di, 0x10);
    goto loc_2f8a8;
loc_2f60c:
    if (al == memoryAGet(ds, di))
        goto loc_2f613;
    goto loc_2f7bf;
loc_2f613:
    goto loc_2f8a8;
loc_2f616:
    ax = cx;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    if (al == 0x8c)
        goto loc_2f62b;
    goto loc_2f64a;
loc_2f62b:
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    ax += memoryAGet16(ds, si + 129);
    memoryASet(ds, si + 129, memoryAGet(ds, si + 129) ^ 0x01);
    ax += 0x0002;
    ax <<= 1;
    bx = 0x440c;
    bx += ax;
    goto loc_2f6eb;
loc_2f64a:
    if (al == 0x90)
        goto loc_2f651;
    goto loc_2f662;
loc_2f651:
    ax = memoryAGet16(ds, 0x35fa);
    ax &= 0x0003;
    ax <<= 1;
    bx = 0x441c;
    bx += ax;
    goto loc_2f6eb;
loc_2f662:
    if (al >= 0xa0)
        goto loc_2f669;
    goto loc_2f6a8;
loc_2f669:
    if (al <= 0xa7)
        goto loc_2f670;
    goto loc_2f6a8;
loc_2f670:
    bl = al;
    bl -= 0xa0;
    if (!bl)
        goto loc_2f684;
    if (bl != 0x07)
        goto loc_2f682;
    bl = 0x02;
    goto loc_2f684;
loc_2f682:
    bl = 0x01;
loc_2f684:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4424;
    bx += ax;
    goto loc_2f6eb;
loc_2f6a8:
    if (al >= 0xb0)
        goto loc_2f6af;
    goto loc_2f6eb;
loc_2f6af:
    if (al <= 0xb7)
        goto loc_2f6b6;
    goto loc_2f6eb;
loc_2f6b6:
    bl = al;
    bl -= 0xb0;
    if (!bl)
        goto loc_2f6ca;
    if (bl != 0x07)
        goto loc_2f6c8;
    bl = 0x02;
    goto loc_2f6ca;
loc_2f6c8:
    bl = 0x01;
loc_2f6ca:
    bl <<= 1;
    bl <<= 1;
    bl <<= 1;
    al = memoryAGet(ds, si + 2);
    ax &= 0x0003;
    ax <<= 1;
    al += bl;
    bx = memoryAGet16(ds, 0x35fa);
    bx &= 0x0001;
    ax += bx;
    ax <<= 1;
    bx = 0x4454;
    bx += ax;
loc_2f6eb:
    flags.direction = false;
    push(di);
    push(si);
    push(es);
    es = bp;
    di = memoryAGet16(ds, 0x4156);
    di += memoryAGet16(ds, 0x4154);
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    si = pop();
    di = pop();
    goto loc_2f8a8;
loc_2f7bf:
    ax = cx;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di, al);
    ah = 0;
    ax <<= 1;
    flags.direction = false;
    bx = 0x430c;
    bx += ax;
    push(di);
    push(si);
    push(es);
    es = bp;
    di = memoryAGet16(ds, 0x4156);
    di += memoryAGet16(ds, 0x4154);
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    es = pop();
    si = pop();
    di = pop();
loc_2f8a8:
    di--;
    di--;
    si--;
    cx--;
    cx--;
    if ((short)cx < 0)
        goto loc_2f8b2;
    goto loc_2f5d5;
loc_2f8b2:
    si -= 0x00d8;
    memoryASet16(ds, 0x4156, memoryAGet16(ds, 0x4156) - 0x0280);
    dx--;
    if (dx == 0)
        goto loc_2f8c2;
    goto loc_2f5d2;
loc_2f8c2:
    bp = pop();
}
void sub_2f8c5()
{
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    memoryASet16(ds, 0x35a0, ax);
    dx = bx;
    si = 0x42f8;
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x08);
loc_2f8d8:
    bx = dx;
    bx += memoryAGet16(ds, si);
    si += 0x0002;
    if (memoryAGet16(ds, 0x35a0) != 0x0001)
        goto loc_2f8eb;
    sub_31073();
    goto loc_2f909;
loc_2f8eb:
    if (memoryAGet16(ds, bx) == 0xff02)
        goto loc_2f8fd;
    if (memoryAGet16(ds, bx) < 0xff08)
        goto loc_2f8ff;
    if (memoryAGet16(ds, bx) > 0xff0f)
        goto loc_2f8ff;
loc_2f8fd:
    goto loc_2f909;
loc_2f8ff:
    memoryASet16(ds, bx, 0xff1b);
    memoryASet16(ds, bx + 128, 0xffff);
loc_2f909:
    if (bx != memoryAGet16(ds, 0x35f6))
        goto loc_2f915;
    memoryASet16(ds, 0x3582, 0x0008);
loc_2f915:
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_2f8d8;
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_2f920()
{
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_2f954;
    push(ds);
    es = pop();
    flags.direction = false;
    si = 0x4060;
    di = si;
    cx = 0x00ee;
loc_2f933:
    lodsb<MemAuto, DirAuto>();
    if (al < 0x10)
        goto loc_2f93a;
    al -= 0x08;
loc_2f93a:
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2f933;
    si = 0x42c4;
    sub_3177d();
    si = 0x42ee;
    sub_3177d();
    si = 0x430c;
    sub_3177d();
    return;
loc_2f954:
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        return;
    si = 0x42c4;
    sub_3174f();
    si = 0x42ee;
    sub_3174f();
    si = 0x430c;
    sub_3174f();
}
void sub_2f971()
{
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        return;
    push(es);
//    ax = 0;
//    es = ax;
//    al = memoryAGet(es, 0x0410);
//    al &= 0xcf;
//    al |= 0x10;
//    memoryASet(es, 0x0410, al);
    es = pop();
}
void sub_2f98b()
{
    sub_311a5();
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x06;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x39f4;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3562);
loc_2f9a8:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2f9b3;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2f9a8;
loc_2f9b3:
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0e;
    dh = 0x07;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x3a00;
    bh = 0x00;
    bl = memoryAGet(ds, 0x3562);
loc_2f9cd:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_2f9d8;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_2f9cd;
loc_2f9d8:
    ah = 0;
    interrupt(0x16);
    sub_310a3();
}
void sub_2f9e0()
{
    sub_2fa13();
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_2f9fb;
    memoryASet(ds, 0x3568, 0x01);
    memoryASet(ds, 0x3562, 0x02);
    memoryASet(ds, 0x3566, 0x03);
    goto loc_2fa0a;
loc_2f9fb:
    memoryASet(ds, 0x3568, 0x0e);
    memoryASet(ds, 0x3562, 0x0c);
    memoryASet(ds, 0x3566, 0x0f);
loc_2fa0a:
    sub_2fa65();
    memoryASet(ds, 0x35ae, 0x00);
}
void sub_2fa13()
{
    push(es);
    sub_2fa7b();
    if (!al)
        goto loc_2fa31;
    ax = 0xf000;
    es = ax;
    if (memoryAGet(es, 0xc000) != 0x21)
        goto loc_2fa31;
    memoryASet16(ds, 0x3598, 0x0002);
    goto loc_2fa63;
loc_2fa31:
    ax = 0x1200;
    bx = 0xff10;
    cl = 0x0f;
    interrupt(0x10);
    if (bh > 0x01)
        goto loc_2fa47;
    if (bl > 0x03)
        goto loc_2fa47;
    goto loc_2fa4f;
loc_2fa47:
    memoryASet16(ds, 0x3598, 0x0000);
    goto loc_2fa63;
loc_2fa4f:
    memoryASet16(ds, 0x3598, 0x0001);
    memoryASet(ds, 0x35ac, 0x00);
    if (bl)
        goto loc_2fa63;
    memoryASet(ds, 0x35ac, 0xff);
loc_2fa63:
    es = pop();
}
void sub_2fa65()
{
    sub_2fa7b();
    if (!al)
        goto loc_2fa74;
    memoryASet16(ds, 0x35f4, 0x0002);
    return;
loc_2fa74:
    memoryASet16(ds, 0x35f4, 0x0001);
}
void sub_2fa7b()
{
    push(es);
    ax = 0xf000;
    es = ax;
    di = 0xc000;
    cx = 0x3ff0;
    flags.direction = false;
loc_2fa88:
    al = 0x54;
//    repne_scasb<MemAuto, DirAuto>(al);
//    if (stop(/*1*/))
//        goto loc_2fa92;
    al = 0;
    goto loc_2fab6;
loc_2fa92:
    si = 0x416e;
    push(cx);
    cx = 0x0004;
    ah = 0;
loc_2fa9c:
    al = memoryAGet(es, di);
    al |= 0x20;
    if (al == memoryAGet(ds, si))
        goto loc_2faa7;
    ah++;
loc_2faa7:
    di++;
    si++;
    if (--cx)
        goto loc_2fa9c;
    cx = pop();
    if (ah)
        goto loc_2fab4;
    al = 0xff;
    goto loc_2fab6;
loc_2fab4:
    if (--cx)
        goto loc_2fa88;
loc_2fab6:
    if (cx)
        goto loc_2fabc;
    al = 0;
loc_2fabc:
    es = pop();
}
void sub_2fabe()
{
    sub_31f15();
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    tl = memoryAGet16(ds, 0x3584) == 0; // gabo
    memoryASet16(ds, 0x3584, memoryAGet16(ds, 0x3584) - 1);
    if (memoryAGet16(ds, 0x3584) != 0)
        goto loc_2faf3;
    memoryASet(ds, 0x35b2, 0xff);
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_2fae3;
    ax = 0x1000;
    bl = 0x00;
    bh = 0x17;
    interrupt(0x10);
    goto loc_2faf3;
loc_2fae3:
    ah = 0x0b;
    bh = 0;
    bl = memoryAGet(ds, 0x3560);
    bl += 0x04;
    bl &= 0x0f;
    interrupt(0x10);
loc_2faf3:
    if (tl)
        return;
    memoryASet16(ds, 0x3584, 0x0000);
}
void sub_2fafc()
{
    al -= 0x6c;
    ah = 0;
    cx = ax;
    if (!cx)
        return;
loc_2fb06:
    sub_2fabe();
    if (--cx)
        goto loc_2fb06;
}
void sub_2fb0c()
{
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    bx = si;
    bx -= 0x0100;
    sub_2fb39();
    bx = si;
    bx -= 0x0002;
    sub_2fb39();
    bx = si;
    bx += 0x0002;
    sub_2fb39();
    bx = si;
    bx += 0x0100;
    sub_2fb39();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_2fb39()
{
    ax = memoryAGet16(ds, bx);
    if (al == 0x00)
        goto loc_2fb45;
    if (al == 0x01)
        goto loc_2fb45;
    goto loc_2fb5e;
loc_2fb45:
    memoryASet(ds, 0x35d8, 0x00);
    sub_308d1();
    if (al >= 0x02)
        goto loc_2fb5c;
    ax = memoryAGet16(ds, 0x3544);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 128, 0xffff);
loc_2fb5c:
    return;
loc_2fb5e:
    if (al != 0x8c)
        goto loc_2fb73;
    memoryASet(ds, 0x35d8, 0x00);
    bx -= 0x0102;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_2fb73:
    if (al != 0x90)
        return;
    memoryASet(ds, 0x35d8, 0x00);
    bx -= 0x0102;
    ax = 0x0002;
    sub_2f8c5();
}
void sub_2fbda()
{
    sync();
    if (memoryAGet(ds, 0x35b6) != 0xff)
        goto loc_2fbf6;
    assert(0); // joystick
    dx = 0x0201;
    in(al, dx);
    if (al & 0x10)
        goto loc_2fbf6;
    memoryASet16(cs, 0x0033, memoryAGet16(cs, 0x0033) + 1);
loc_2fbee:
    in(al, dx);
    if (!(al & 0x10))
        goto loc_2fbee;
    goto loc_2fc12;
loc_2fbf6:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_2fc03;
    ah = 0;
    interrupt(0x16);
    goto loc_2fc12;
loc_2fc03:
    if (memoryAGet(cs, 0x0022) == 0x00)
        goto loc_2fc0e;
    goto loc_2fc12;
loc_2fc0e:
    al = 0;
    return;
loc_2fc12:
    al = 0xff;
}
void sub_2fc15()
{
    ah = 0x35;
    al = 0x09;
    interrupt(0x21);
    memoryASet16(cs, 0x000c, bx);
    memoryASet16(cs, 0x000e, es);
    ah = 0x25;
    al = 0x09;
    push(ds);
    dx = 0x2c84;
    push(cs);
    ds = pop();
    interrupt(0x21);
    ds = pop();
}
void sub_2fd19()
{
    push(ds);
    ah = 0x25;
    al = 0x09;
    bx = memoryAGet16(cs, 0x000e);
    dx = memoryAGet16(cs, 0x000c);
    ds = bx;
    interrupt(0x21);
    ds = pop();
}
void sub_2fd41()
{
    if (memoryAGet(ds, 0x35ae) != 0x00)
        goto loc_2fd49;
    return;
loc_2fd49:
    ax = 0x1000;
    es = ax;
    ds = memoryAGet16(ds, 0x46f2);
    di = 0x1600;
    dx = 0x03ce;
    ax = 0x0002;
    out(dx, ax);
    push(dx);
    dx = 0x03ce;
    ah = 0x08;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    si = 0x2000;
    cx = 0x1f40;
loc_2fd6d:
    lodsb<MemAuto, DirAuto>();
    al = ~al;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_2fd6d;
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    ax = 0x1000;
    ds = ax;
    es = memoryAGet16(ds, 0x46f2);
    cx = 0x1f40;
    si = 0x1600;
    di = 0x6000;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_2fd9c()
{
    if (memoryAGet16(ds, 0x354e) != 0x0000)
        goto loc_2fda4;
    return;
loc_2fda4:
    memoryASet(ds, 0x35d0, 0x00);
    memoryASet(ds, 0x35d4, 0x00);
    bx = memoryAGet16(ds, 0x3550);
    si = memoryAGet16(ds, 0x354c);
    memoryASet16(ds, 0x46e8, si);
    si <<= 1;
    di = memoryAGet16(ds, si + 13712);
    al = memoryAGet(ds, bx + di);
    if (al == 0x00)
        goto loc_2fdfc;
    sub_2fe63();
    sub_308d1();
    if (!(al & 0x01))
        goto loc_2fde7;
    si = memoryAGet16(ds, 0x354c);
    sub_2fe95();
    if (flags.zero)
        goto loc_2fde5;
    si = memoryAGet16(ds, 0x354c);
    sub_2fea7();
    if (flags.zero)
        goto loc_2fde5;
    goto loc_2fe3d;
loc_2fde5:
    goto loc_2fdfc;
loc_2fde7:
    si = memoryAGet16(ds, 0x354c);
    sub_2fea7();
    if (flags.zero)
        goto loc_2fdfc;
    si = memoryAGet16(ds, 0x354c);
    sub_2fe95();
    if (flags.zero)
        goto loc_2fdfc;
    goto loc_2fe3d;
loc_2fdfc:
    memoryASet16(ds, 0x354e, memoryAGet16(ds, 0x354e) + 1);
    if (memoryAGet16(ds, 0x354e) != 0x0002)
        goto loc_2fe10;
    memoryASet(ds, bx, 0xf3);
    memoryASet16(ds, 0x3552, bx);
    goto loc_2fe25;
loc_2fe10:
    if (memoryAGet16(ds, 0x354e) <= 0x0008)
        goto loc_2fe25;
    si = memoryAGet16(ds, 0x3552);
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, 0x354e, 0x0008);
loc_2fe25:
    ax = memoryAGet16(ds, 0x46e8);
    memoryASet16(ds, 0x354c, ax);
    al |= 0xf8;
    memoryASet(ds, bx + 1, al);
    bx += di;
    memoryASet(ds, bx, 0x4f);
    memoryASet(ds, bx + 1, al);
    memoryASet16(ds, 0x3550, bx);
    return;
loc_2fe3d:
    si = memoryAGet16(ds, 0x3552);
    if (!si)
        goto loc_2fe54;
    memoryASet16(ds, 0x3550, si);
    memoryASet16(ds, 0x3552, bx);
    memoryASet(ds, 0x35d0, 0xff);
    goto loc_2fe59;
loc_2fe54:
    memoryASet(ds, 0x35d4, 0xff);
loc_2fe59:
    sub_308d1();
    ax &= 0x0003;
    memoryASet16(ds, 0x354c, ax);
}
void sub_2fe63()
{
    if (al == 0x40)
        goto loc_2fe6d;
    if (al == 0x42)
        goto loc_2fe6d;
    goto loc_2fe79;
loc_2fe6d:
    memoryASet16(ds, bx + di, 0xff3c);
    memoryASet16(ds, bx + di + 128, 0xffff);
    return;
loc_2fe79:
    if (al == 0x44)
        goto loc_2fe83;
    if (al == 0x46)
        goto loc_2fe83;
    return;
loc_2fe83:
    sub_308d1();
    if (al & 0x07)
        return;
    memoryASet16(ds, bx + di, 0xff38);
    memoryASet16(ds, bx + di + 128, 0xffff);
}
void sub_2fe95()
{
    si--;
    si &= 0x0003;
    memoryASet16(ds, 0x46e8, si);
    si <<= 1;
    di = memoryAGet16(ds, si + 13712);
    flags.zero = memoryAGet(ds, bx + di) == 0x00;
}
void sub_2fea7()
{
    si++;
    si &= 0x0003;
    memoryASet16(ds, 0x46e8, si);
    si <<= 1;
    di = memoryAGet16(ds, si + 13712);
    flags.zero = memoryAGet(ds, bx + di) == 0x00;
}
void sub_2feb9()
{
    if (memoryAGet16(ds, 0x3556) != 0x0000)
        goto loc_2fec1;
    return;
loc_2fec1:
    memoryASet(ds, 0x35d2, 0x00);
    memoryASet(ds, 0x35d6, 0x00);
    bx = memoryAGet16(ds, 0x3558);
    si = memoryAGet16(ds, 0x3554);
    memoryASet16(ds, 0x46e8, si);
    si <<= 1;
    di = memoryAGet16(ds, si + 13712);
    al = memoryAGet(ds, bx + di);
    if (al == 0x00)
        goto loc_2ff19;
    sub_2ff80();
    sub_308d1();
    if (!(al & 0x01))
        goto loc_2ff04;
    si = memoryAGet16(ds, 0x3554);
    sub_2fe95();
    if (flags.zero)
        goto loc_2ff02;
    si = memoryAGet16(ds, 0x3554);
    sub_2fea7();
    if (flags.zero)
        goto loc_2ff02;
    goto loc_2ff5a;
loc_2ff02:
    goto loc_2ff19;
loc_2ff04:
    si = memoryAGet16(ds, 0x3554);
    sub_2fea7();
    if (flags.zero)
        goto loc_2ff19;
    si = memoryAGet16(ds, 0x3554);
    sub_2fe95();
    if (flags.zero)
        goto loc_2ff19;
    goto loc_2ff5a;
loc_2ff19:
    memoryASet16(ds, 0x3556, memoryAGet16(ds, 0x3556) + 1);
    if (memoryAGet16(ds, 0x3556) != 0x0002)
        goto loc_2ff2d;
    memoryASet(ds, bx, 0xf4);
    memoryASet16(ds, 0x355a, bx);
    goto loc_2ff42;
loc_2ff2d:
    if (memoryAGet16(ds, 0x3556) <= 0x0008)
        goto loc_2ff42;
    si = memoryAGet16(ds, 0x355a);
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, 0x3556, 0x0008);
loc_2ff42:
    ax = memoryAGet16(ds, 0x46e8);
    memoryASet16(ds, 0x3554, ax);
    al |= 0xf8;
    memoryASet(ds, bx + 1, al);
    bx += di;
    memoryASet(ds, bx, 0x5f);
    memoryASet(ds, bx + 1, al);
    memoryASet16(ds, 0x3558, bx);
    return;
loc_2ff5a:
    si = memoryAGet16(ds, 0x355a);
    if (!si)
        goto loc_2ff71;
    memoryASet16(ds, 0x3558, si);
    memoryASet16(ds, 0x355a, bx);
    memoryASet(ds, 0x35d2, 0xff);
    goto loc_2ff76;
loc_2ff71:
    memoryASet(ds, 0x35d6, 0xff);
loc_2ff76:
    sub_308d1();
    ax &= 0x0003;
    memoryASet16(ds, 0x3554, ax);
}
void sub_2ff80()
{
    if (al != 0x90)
        goto loc_2ff90;
    memoryASet16(ds, bx + di, 0xff34);
    memoryASet16(ds, bx + di + 128, 0xffff);
    return;
loc_2ff90:
    if (al == 0x44)
        goto loc_2ff9a;
    if (al == 0x46)
        goto loc_2ff9a;
    return;
loc_2ff9a:
    memoryASet16(ds, bx + di, 0xff17);
    memoryASet16(ds, bx + di + 128, 0xffff);
}
void sub_2ffa5()
{
    memoryASet16(ds, 0x3be2, 0x0001);
    al = memoryAGet(ds, si + 1);
    al += 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    push(ax);
    sub_3001f();
    ax = pop();
    if (flags.zero)
        return;
    al -= 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    push(ax);
    sub_3001f();
    ax = pop();
    if (flags.zero)
        return;
    al -= 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    return;
    //   gap of 2 bytes
}
void sub_2ffe2()
{
    memoryASet16(ds, 0x3be2, 0x0002);
    al = memoryAGet(ds, si + 1);
    al -= 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    push(ax);
    sub_3001f();
    ax = pop();
    if (flags.zero)
        return;
    al += 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    push(ax);
    sub_3001f();
    ax = pop();
    if (flags.zero)
        return;
    al += 0x01;
    al &= 0x03;
    memoryASet(ds, si + 1, al);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    return;
    //   gap of 2 bytes
}
// INJECT: Error: cannot inject flag in sub_3001f() because of being label!
void sub_3001f()
{
    if (al != 0x00)
        goto loc_30028;
    sub_30531();
    goto loc_30041;
loc_30028:
    if (al != 0x02)
        goto loc_30031;
    sub_30555();
    goto loc_30041;
loc_30031:
    if (al != 0x01)
        goto loc_3003a;
    sub_304bd();
    goto loc_30041;
loc_3003a:
    if (al != 0x03)
        goto loc_30041;
    sub_30509();
loc_30041:
    return;
}
void sub_30042()
{
    ax = memoryAGet16(ds, 0x4150);
    memoryASet16(ds, 0x4152, ax);
    ah = 0x01;
    interrupt(0x16);
    if (!flags.zero)
        goto loc_30051;
    goto loc_301d0;
loc_30051:
    ah = 0;
    interrupt(0x16);
    if ((char)al <= (char)0x40)
        goto loc_3005b;
    al |= 0x20;
loc_3005b:
    if (ah != 0x01)
        goto loc_30066;
    memoryASet(ds, 0x35bc, 0xff);
    return;
loc_30066:
    if (ah == 0x3b)
        goto loc_30072;
    if (al == 0x68)
        goto loc_30072;
    goto loc_300f1;
loc_30072:
    memoryASet(ds, 0x35bc, 0xff);
    memoryASet(ds, 0x4164, 0x00);
    sub_311a5();
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x0780);
    al = memoryAGet(ds, 0x3566);
    memoryASet(ds, 0x3564, al);
    si = 0x3a62;
    sub_3074d();
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x08c0);
    si = 0x3a78;
    sub_3074d();
    ah = 0;
    interrupt(0x16);
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x0780);
    si = 0x3a8e;
    sub_3074d();
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x08c0);
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_300db;
    si = 0x3aa4;
    goto loc_300df;
loc_300db:
    si = 0x3aba;
loc_300df:
    sub_3074d();
    ah = 0;
    interrupt(0x16);
    sub_310a3();
    memoryASet(ds, 0x35bc, 0x00);
    goto loc_301d0;
loc_300f1:
    if (al == 0x62)
        goto loc_300f8;
    goto loc_3016e;
loc_300f8:
    memoryASet(ds, 0x35bc, 0xff);
    sub_311a5();
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x0780);
    al = memoryAGet(ds, 0x3566);
    memoryASet(ds, 0x3564, al);
    si = 0x3988;
    sub_3074d();
    memoryASet16(ds, 0x4154, 0x0009);
    memoryASet16(ds, 0x4156, 0x08c0);
    si = 0x399f;
    sub_3074d();
    sub_2d277();
    push(ax);
    sub_310a3();
    ax = pop();
    if (ax > 0x000f)
        goto loc_3016a;
    if (memoryAGet16(ds, 0x3598) != 0x0001)
        goto loc_30146;
    if (al < 0x08)
        goto loc_30146;
    al += 0x08;
loc_30146:
    memoryASet(ds, 0x3560, al);
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_30158;
    bl = al;
    ah = 0x0b;
    bh = 0x00;
    goto loc_30160;
loc_30158:
    bh = al;
    ah = 0x10;
    al = 0;
    bl = 0;
loc_30160:
    interrupt(0x10);
    memoryASet(ds, 0x35bc, 0x00);
    return;
    //   gap of 2 bytes
loc_3016a:
    return;
    //   gap of 3 bytes
loc_3016e:
    if (al == 0x63)
        goto loc_30175;
    goto loc_30191;
loc_30175:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_3017f;
    goto loc_30191;
loc_3017f:
    memoryASet(ds, 0x355e, memoryAGet(ds, 0x355e) ^ 0x01);
    ah = 0x0b;
    bh = 0x01;
    bl = memoryAGet(ds, 0x355e);
    interrupt(0x10);
    goto loc_301d0;
loc_30191:
    if (al == 0x71)
        goto loc_30198;
    goto loc_301a2;
loc_30198:
    memoryASet16(ds, 0x359a, 0xffff);
    return;
    //   gap of 3 bytes
loc_301a2:
    if (al == 0x72)
        goto loc_301a9;
    goto loc_301b2;
loc_301a9:
    memoryASet(ds, 0x35be, 0xff);
    return;
    //   gap of 3 bytes
loc_301b2:
    if (al == 0x73)
        goto loc_301b9;
    goto loc_301d0;
loc_301b9:
    memoryASet(ds, 0x4164, 0x00);
    memoryASet(ds, 0x4166, memoryAGet(ds, 0x4166) ^ 0xff);
    if (memoryAGet(ds, 0x4166) != 0x00)
        goto loc_301d0;
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
loc_301d0:
    sub_308d1();
    if (!(al & 0x03))
        goto loc_301df;
    memoryASet16(ds, 0x4158, 0x0018);
    goto loc_301e5;
loc_301df:
    memoryASet16(ds, 0x4158, 0x0020);
loc_301e5:
    memoryASet(ds, 0x3588, 0x00);
    memoryASet(ds, 0x358a, 0x00);
    al = memoryAGet(cs, 0x001a);
    al += memoryAGet(cs, 0x0028);
    if (!al)
        goto loc_30201;
    memoryASet(ds, 0x358a, 0x01);
loc_30201:
    al = memoryAGet(cs, 0x001b);
    al += memoryAGet(cs, 0x0029);
    memoryASet(ds, 0x359e, al);
    if (!al)
        goto loc_30216;
    memoryASet(ds, 0x358a, 0x02);
loc_30216:
    al = memoryAGet(cs, 0x001c);
    al += memoryAGet(cs, 0x002a);
    if (!al)
        goto loc_30228;
    memoryASet(ds, 0x3588, 0x04);
loc_30228:
    al = memoryAGet(cs, 0x001d);
    al += memoryAGet(cs, 0x002b);
    if (!al)
        goto loc_3023a;
    memoryASet(ds, 0x3588, 0x08);
loc_3023a:
    memoryASet16(ds, 0x46f0, 0x0000);
    memoryASet16(ds, 0x35f2, 0x0000);
    bx = memoryAGet16(ds, 0x35f6);
    if (memoryAGet(ds, bx + 65534) == 0x90)
        goto loc_3026b;
    if (memoryAGet(ds, bx + 65280) == 0x90)
        goto loc_3026b;
    if (memoryAGet(ds, bx + 256) == 0x90)
        goto loc_3026b;
    if (memoryAGet(ds, 0x358a) == 0x01)
        goto loc_30278;
    if (memoryAGet(ds, bx + 2) != 0x90)
        goto loc_30278;
loc_3026b:
    ax = 0x0002;
    bx -= 0x0102;
    sub_2f8c5();
    return;
    //   gap of 2 bytes
loc_30278:
    if (memoryAGet(ds, bx + 65534) == 0x8c)
        goto loc_30299;
    if (memoryAGet(ds, bx + 65280) == 0x8c)
        goto loc_30299;
    if (memoryAGet(ds, bx + 256) == 0x8c)
        goto loc_30299;
    if (memoryAGet(ds, 0x358a) == 0x01)
        goto loc_302a4;
    if (memoryAGet(ds, bx + 2) != 0x8c)
        goto loc_302a4;
loc_30299:
    ax = 0x0001;
    bx -= 0x0102;
    sub_2f8c5();
    return;
loc_302a4:
    if (memoryAGet(cs, 0x0022) != 0x00)
        goto loc_302b6;
    if (memoryAGet(cs, 0x0030) != 0x00)
        goto loc_302b6;
    goto loc_302b9;
loc_302b6:
    goto loc_30336;
loc_302b9:
    if (memoryAGet(ds, 0x3588) != 0x04)
        goto loc_302cf;
    sub_2e6d0();
    if (!flags.zero)
        goto loc_302cd;
    memoryASet16(ds, 0x35f2, 0xfffe);
    goto loc_30319;
loc_302cd:
    goto loc_302e3;
loc_302cf:
    if (memoryAGet(ds, 0x3588) != 0x08)
        goto loc_302e3;
    sub_2e84d();
    if (!flags.zero)
        goto loc_302e3;
    memoryASet16(ds, 0x35f2, 0x0002);
    goto loc_30319;
loc_302e3:
    if (memoryAGet(ds, 0x358a) != 0x01)
        goto loc_302ff;
    sub_2e9ca();
    if (!flags.zero)
        goto loc_302fd;
    if ((short)memoryAGet16(ds, 0x35f6) >= (short)0x4000)
        goto loc_302fd;
    memoryASet16(ds, 0x46f0, 0xff00);
loc_302fd:
    goto loc_30319;
loc_302ff:
    if (memoryAGet(ds, 0x358a) != 0x02)
        goto loc_30319;
    sub_2e59c();
    if (!flags.zero)
        goto loc_30319;
    if ((short)memoryAGet16(ds, 0x35f6) < (short)0x0600)
        goto loc_30319;
    memoryASet16(ds, 0x46f0, 0x0100);
loc_30319:
    if (memoryAGet(ds, 0x35a6) != 0xff)
        goto loc_30321;
    return;
loc_30321:
    ax = memoryAGet16(ds, 0x35f6);
    if (ax == memoryAGet16(ds, 0x3ce2))
        goto loc_30332;
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x02);
    memoryASet16(ds, 0x3ce2, ax);
loc_30332:
    sub_2e4bc();
    return;
loc_30336:
    if (memoryAGet(ds, 0x3588) != 0x00)
        goto loc_30346;
    if (memoryAGet(ds, 0x358a) != 0x00)
        goto loc_30346;
    goto loc_3034b;
loc_30346:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x08);
loc_3034b:
    bx = memoryAGet16(ds, 0x35f6);
    if (memoryAGet(ds, 0x3588) != 0x04)
        goto loc_30361;
    bx -= 0x0002;
    memoryASet16(ds, 0x4158, 0x0010);
    goto loc_3038b;
loc_30361:
    if (memoryAGet(ds, 0x3588) != 0x08)
        goto loc_30373;
    bx += 0x0002;
    memoryASet16(ds, 0x4158, 0x0014);
    goto loc_3038b;
loc_30373:
    if (memoryAGet(ds, 0x358a) != 0x01)
        goto loc_30380;
    bx -= 0x0100;
    goto loc_3038b;
loc_30380:
    if (memoryAGet(ds, 0x358a) != 0x02)
        goto loc_3038b;
    bx += 0x0100;
loc_3038b:
    if (bx != memoryAGet16(ds, 0x35f6))
        goto loc_30394;
    return;
loc_30394:
    ax = memoryAGet16(ds, bx);
    if (ax == 0xff40)
        goto loc_303a3;
    if (ax == 0xff42)
        goto loc_303a3;
    goto loc_303b3;
loc_303a3:
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    sub_2fabe();
    return;
loc_303b3:
    if (ax == 0xff01)
        goto loc_303ca;
    if (al == 0x00)
        goto loc_303ca;
    if (al >= 0x20)
        goto loc_303c3;
    goto loc_303d7;
loc_303c3:
    if (al <= 0x2f)
        goto loc_303ca;
    goto loc_303d7;
loc_303ca:
    memoryASet16(ds, bx, 0xff1c);
    memoryASet16(ds, bx + 128, 0xffff);
    return;
loc_303d7:
    if (ax == 0xff44)
        goto loc_303e4;
    if (ax == 0xff46)
        goto loc_303e4;
    goto loc_3042e;
loc_303e4:
    if (memoryAGet(ds, 0x3588) != 0x04)
        goto loc_30408;
    if (memoryAGet16(ds, bx + 65534) != 0xff00)
        goto loc_30408;
    memoryASet16(ds, bx, 0xff1c);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 65534, 0xff44);
    memoryASet16(ds, bx + 126, 0xffff);
    goto loc_3042b;
loc_30408:
    if (memoryAGet(ds, 0x3588) != 0x08)
        goto loc_3042b;
    if (memoryAGet16(ds, bx + 2) != 0xff00)
        goto loc_3042b;
    memoryASet16(ds, bx, 0xff1c);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 2, 0xff44);
    memoryASet16(ds, bx + 130, 0xffff);
loc_3042b:
    return;
loc_3042e:
    if (ax == 0xff08)
        goto loc_30436;
    goto loc_3043e;
loc_30436:
    memoryASet(ds, 0x35b0, 0xff);
    return;
loc_3043e:
    if (ax == 0xff0c)
        goto loc_30446;
    goto loc_3044e;
loc_30446:
    memoryASet(ds, 0x35a4, 0xff);
    return;
loc_3044e:
    if (al >= 0x78)
        goto loc_30455;
    goto loc_30465;
loc_30455:
    if (al <= 0x7b)
        goto loc_3045c;
    goto loc_30465;
loc_3045c:
    memoryASet16(ds, 0x35e2, 0x04b0);
    return;
loc_30465:
    if (al >= 0x7c)
        goto loc_3046c;
    goto loc_3047c;
loc_3046c:
    if (al <= 0x7f)
        goto loc_30473;
    goto loc_3047c;
loc_30473:
    memoryASet16(ds, 0x35e4, 0x04b0);
    return;
loc_3047c:
    if (al >= 0x70)
        goto loc_30483;
    goto loc_304a1;
loc_30483:
    if (al <= 0x73)
        goto loc_3048a;
    goto loc_304a1;
loc_3048a:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x04);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) + 0x0014);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    return;
loc_304a1:
    if (al >= 0x6c)
        goto loc_304a8;
    return;
loc_304a8:
    if (al <= 0x6f)
        goto loc_304af;
    return;
loc_304af:
    sub_2fafc();
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_304bd()
{
    bx = si;
    al = memoryAGet(ds, bx + 2);
    ah = memoryAGet(ds, bx + 65280);
    if (ah == 0x46)
        goto loc_304d8;
    if (ah == 0x42)
        goto loc_304d8;
    if (al < 0x48)
        goto loc_304e5;
    if (al > 0x4b)
        goto loc_304e5;
loc_304d8:
    ax = memoryAGet16(ds, 0x3be2);
    bx -= 0x0102;
    sub_2f8c5();
    return;
loc_304e5:
    if (memoryAGet(ds, bx + 65280) == 0x00)
        goto loc_304ef;
    return;
loc_304ef:
    ax = memoryAGet16(ds, bx);
    di = memoryAGet16(ds, bx + 128);
    memoryASet16(ds, bx + 65280, ax);
    memoryASet16(ds, bx + 65408, di);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_30509()
{
    bx = si;
    if (memoryAGet(ds, bx + 256) == 0x00)
        goto loc_30515;
    return;
loc_30515:
    ax = memoryAGet16(ds, bx);
    di = memoryAGet16(ds, bx + 128);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    ax++;
    memoryASet16(ds, bx + 256, ax);
    memoryASet16(ds, bx + 384, di);
}
void sub_30531()
{
    bx = si;
    if (memoryAGet(ds, bx + 65534) == 0x00)
        goto loc_3053c;
    return;
loc_3053c:
    ax = memoryAGet16(ds, bx);
    di = memoryAGet16(ds, bx + 128);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 65534, ax);
    memoryASet16(ds, bx + 126, di);
}
void sub_30555()
{
    bx = si;
    if (memoryAGet(ds, bx + 2) == 0x00)
        goto loc_30560;
    return;
loc_30560:
    ax = memoryAGet16(ds, bx);
    di = memoryAGet16(ds, bx + 128);
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 128, 0xffff);
    ax++;
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ds, bx + 130, di);
}
void sub_3057b()
{
    push(es);
    memoryASet(cs, 0x0025, 0xff);
    push(cs);
    es = pop();
    flags.direction = false;
    di = 0x1a;
    cx = 0x000b;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    di = 0x28;
    cx = 0x000b;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    es = pop();
}
void sub_3059d()
{
    push(cx);
    push(di);
    push(si);
    push(es);
    memoryASet16(ds, 0x3cde, dx);
    memoryASet16(ds, 0x3b53, si);
loc_305a9:
    dx = memoryAGet16(ds, 0x3cde);
    ah = 0x3d;
    al = 0x00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_305b8;
    goto loc_30615;
loc_305b8:
    if (al == 0x02)
        goto loc_305bf;
    sub_2f112();
loc_305bf:
    sub_311a5();
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0a;
    dh = 0x06;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = memoryAGet16(ds, 0x3b53);
    bh = 0x00;
    bl = 0x0f;
loc_305da:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_305e5;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_305da;
loc_305e5:
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = 0x0a;
    dh = 0x07;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    si = 0x3a0c;
    bh = 0x00;
    bl = 0x0f;
loc_305fd:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_30608;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_305fd;
loc_30608:
    ah = 0;
    interrupt(0x16);
    if (al != 0x0d)
        goto loc_30608;
    sub_310a3();
    goto loc_305a9;
loc_30615:
    es = pop();
    si = pop();
    di = pop();
    cx = pop();
}
void sub_3061a()
{
    dx = 0x3cc3;
    si = 0x39ca;
    sub_3059d();
    memoryASet16(ds, 0x35e8, ax);
}
void sub_30629()
{
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(ax);
    bx = memoryAGet16(ds, 0x4154);
    ax = memoryAGet16(ds, 0x4156);
    ax >>= 1;
    cl = 0xa0;
    div(cl);
    ah = 0;
    push(ax);
    push(bx);
    push(dx);
    ah = 0x02;
    bh = 0x00;
    dl = bl;
    dh = al;
    interrupt(0x10);
    dx = pop();
    bx = pop();
    ax = pop();
    ax = pop();
    ah = 0x0e;
    bh = 0;
    bl = memoryAGet(ds, 0x3564);
    interrupt(0x10);
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_3065f()
{
    if (memoryAGet16(ds, 0x415e) < 0x2710)
        goto loc_3067c;
    memoryASet16(ds, 0x3cea, memoryAGet16(ds, 0x3cea) + 1);
    if (memoryAGet16(ds, 0x3cea) & 0x0001)
        goto loc_30676;
    sub_2d92f();
loc_30676:
    memoryASet16(ds, 0x415e, memoryAGet16(ds, 0x415e) - 0x2710);
loc_3067c:
    memoryASet16(ds, 0x4154, 0x0018);
    memoryASet16(ds, 0x4156, 0x0140);
    al = memoryAGet(ds, 0x3566);
    memoryASet(ds, 0x3564, al);
    bx = memoryAGet16(ds, 0x3cea);
    if ((short)bx <= (short)0x0063)
        goto loc_3069a;
    bx = 0x0063;
loc_3069a:
    al = 0x30;
loc_3069c:
    if (bx < 0x000a)
        goto loc_306a8;
    al++;
    bx -= 0x000a;
    goto loc_3069c;
loc_306a8:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
    al += bl;
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    bx = memoryAGet16(ds, 0x415e);
    al = 0x30;
loc_306c0:
    if (bx < 0x03e8)
        goto loc_306ce;
    al++;
    bx -= 0x03e8;
    goto loc_306c0;
loc_306ce:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
loc_306d7:
    if (bx < 0x0064)
        goto loc_306e3;
    al++;
    bx -= 0x0064;
    goto loc_306d7;
loc_306e3:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
loc_306ec:
    if (bx < 0x000a)
        goto loc_306f8;
    al++;
    bx -= 0x000a;
    goto loc_306ec;
loc_306f8:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
    al += bl;
    sub_30629();
}
void sub_30707()
{
    bx = memoryAGet16(ds, 0x4160);
    memoryASet16(ds, 0x4154, 0x0023);
    memoryASet16(ds, 0x4156, 0x0140);
    al = memoryAGet(ds, 0x3562);
    memoryASet(ds, 0x3564, al);
    al = 0x20;
    if (bx < 0x0064)
        goto loc_30729;
    al = 0x31;
    bx -= 0x0064;
loc_30729:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
loc_30732:
    if (bx < 0x000a)
        goto loc_3073e;
    al++;
    bx -= 0x000a;
    goto loc_30732;
loc_3073e:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
    al += bl;
    sub_30629();
}
void sub_3074d()
{
loc_3074d:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        return;
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    goto loc_3074d;
}
void sub_3075c()
{
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(es);
    memoryASet16(ds, 0x3cda, di);
    ax = memoryAGet16(ds, 0x35fa);
    if ((short)memoryAGet16(ds, 0x4158) < (short)0x0018)
        goto loc_30776;
    ax &= 0x0007;
    ax >>= 1;
    goto loc_30779;
loc_30776:
    ax &= 0x0001;
loc_30779:
    ax <<= 1;
    ax += memoryAGet16(ds, 0x4158);
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_30789;
    goto loc_307f1;
loc_30789:
    if (memoryAGet16(ds, 0x3598) != 0x0002)
        goto loc_30793;
    goto loc_30847;
loc_30793:
    si = ax;
    si = memoryAGet16(ds, si + 17092);
    ax = cx;
    memoryASet16(ds, 0x4154, ax);
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    flags.direction = false;
    ax = memoryAGet16(ds, 0x4156);
    cl = 0x28;
    div(cl);
    ah = 0;
    di = ax;
    flags.direction = false;
    si += 0x2000;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4154);
    push(dx);
    dx = 0x03ce;
    ah = 0x01;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(ds);
    push(es);
    ds = pop();
    dl = 0x10;
loc_307d7:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    si += 0x0026;
    dl--;
    if (dl != 0)
        goto loc_307d7;
    ds = pop();
    push(dx);
    dx = 0x03ce;
    ah = 0x00;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    goto loc_3089f;
loc_307f1:
    si = ax;
    si = memoryAGet16(ds, si + 17092);
    ax = cx;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    flags.direction = false;
    ax = memoryAGet16(ds, 0x4156);
    cl = 0x28;
    div(cl);
    ah = 0;
    di = ax;
    flags.direction = false;
    bx = di;
    ax = 0x49ea;
    ax += si;
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4154);
    ax -= di;
    dl = 0x10;
loc_30829:
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4154);
    si = di;
    si += ax;
    cx = 0x0002;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    dl--;
    if (dl != 0)
        goto loc_30829;
    goto loc_3089f;
loc_30847:
    si = ax;
    si = memoryAGet16(ds, si + 17092);
    ax = cx;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, 0x4154, ax);
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    flags.direction = false;
    ax = memoryAGet16(ds, 0x4156);
    cl = 0x28;
    div(cl);
    ah = 0;
    di = ax;
    flags.direction = false;
    bx = di;
    ax = 0x49ea;
    ax += si;
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4154);
    ax -= di;
    dl = 0x10;
loc_30881:
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(ds, 0x4154);
    si = di;
    si += ax;
    cx = 0x0004;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    dl--;
    if (dl != 0)
        goto loc_30881;
    goto loc_3089f;
loc_3089f:
    es = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    di = memoryAGet16(ds, 0x3cda);
}
void sub_308d1()
{
    ax = memoryAGet16(ds, 0x4162);
    ax += 0x9248;
    ax = ror(ax, 0x0001);
    ax = ror(ax, 0x0001);
    ax = ror(ax, 0x0001);
    memoryASet16(ds, 0x4162, ax);
}
void sub_308e1()
{
    if (memoryAGet16(ds, 0x3ce8) != 0xffff)
        goto loc_308f3;
    ax = 0;
    memoryASet16(cs, 0x0004, 0x0000);
    goto loc_308fc;
loc_308f3:
    ax = memoryAGet16(ds, 0x46f4);
    ax++;
    ax += memoryAGet16(cs, 0x0004);
loc_308fc:
    sub_31345();
    memoryASet16(cs, 0x0014, di);
    flags.direction = false;
    push(bx);
    push(ds);
    ax = 0x1cda;
    ds = ax;
    si = 0;
    ah = 0x3f;
    cx = 0x7d00;
    dx = si;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_3091c;
    goto loc_30a64;
loc_3091c:
    di = 0;
loc_3091e:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += memoryAGet16(cs, 0x0014);
    cx = 0x0028;
loc_3092e:
    bx = 0;
    dx = 0;
    al = memoryAGet(ds, si);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3093a;
    bh = 0x10;
loc_3093a:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30941;
    bh |= 0x01;
loc_30941:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30947;
    bl = 0x10;
loc_30947:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3094e;
    bl |= 0x01;
loc_3094e:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30954;
    dh = 0x10;
loc_30954:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3095b;
    dh |= 0x01;
loc_3095b:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30961;
    dl = 0x10;
loc_30961:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30968;
    dl |= 0x01;
loc_30968:
    al = memoryAGet(ds, si + 8000);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30973;
    bh |= 0x20;
loc_30973:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3097a;
    bh |= 0x02;
loc_3097a:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30981;
    bl |= 0x20;
loc_30981:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30988;
    bl |= 0x02;
loc_30988:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3098f;
    dh |= 0x20;
loc_3098f:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30996;
    dh |= 0x02;
loc_30996:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_3099d;
    dl |= 0x20;
loc_3099d:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309a4;
    dl |= 0x02;
loc_309a4:
    al = memoryAGet(ds, si + 16000);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309af;
    bh |= 0x40;
loc_309af:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309b6;
    bh |= 0x04;
loc_309b6:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309bd;
    bl |= 0x40;
loc_309bd:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309c4;
    bl |= 0x04;
loc_309c4:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309cb;
    dh |= 0x40;
loc_309cb:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309d2;
    dh |= 0x04;
loc_309d2:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309d9;
    dl |= 0x40;
loc_309d9:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309e0;
    dl |= 0x04;
loc_309e0:
    al = memoryAGet(ds, si + 24000);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309eb;
    bh |= 0x80;
loc_309eb:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309f2;
    bh |= 0x08;
loc_309f2:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_309f9;
    bl |= 0x80;
loc_309f9:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30a00;
    bl |= 0x08;
loc_30a00:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30a07;
    dh |= 0x80;
loc_30a07:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30a0e;
    dh |= 0x08;
loc_30a0e:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30a15;
    dl |= 0x80;
loc_30a15:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30a1c;
    dl |= 0x08;
loc_30a1c:
    push(cx);
    cx = bx;
    bx = 0x1c7;
    al = ch;
    al = memoryAGet(cs, bx+al);
    ah = al;
    al = cl;
    al = memoryAGet(cs, bx+al);
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    al |= ah;
    stosb<MemAuto, DirAuto>();
    al = dh;
    al = memoryAGet(cs, bx+al);
    ah = al;
    al = dl;
    al = memoryAGet(cs, bx+al);
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    ah <<= 1;
    al |= ah;
    stosb<MemAuto, DirAuto>();
    cx = pop();
    si++;
    if (--cx)
        goto loc_30a53;
    goto loc_30a56;
loc_30a53:
    goto loc_3092e;
loc_30a56:
    di = pop();
    di++;
    if (di >= 0x00c8)
        goto loc_30a61;
    goto loc_3091e;
loc_30a61:
    ds = pop();
    goto loc_30a6a;
loc_30a64:
    ds = pop();
    memoryASet(ds, 0x359c, 0xff);
loc_30a6a:
    ah = 0x3e;
    bx = pop();
    interrupt(0x21);
    if (flags.carry)
        goto loc_30a7a;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_30a7a;
    return;
loc_30a7a:
    sub_2f112();
}
void sub_30a7e()
{
    sub_3061a();
    sub_3129c();
    ah = 0x3f;
    bx = memoryAGet16(ds, 0x35e8);
    cx = 0x0370;
    push(ds);
    dx = 0x1cda;
    ds = dx;
    dx = 0x0;
    interrupt(0x21);
    ds = pop();
    if (!flags.carry)
        goto loc_30aa1;
    memoryASet(ds, 0x359c, 0xff);
loc_30aa1:
    bx = memoryAGet16(ds, 0x35e8);
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30ab4;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_30ab4;
    return;
loc_30ab4:
    sub_2f112();
}
void sub_30ab8()
{
    memoryASet16(cs, 0x0014, di);
    flags.direction = false;
    push(ds);
    ax = 0x1cda;
    ds = ax;
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_30ad2;
    goto loc_30c8d;
loc_30ad2:
    si = 0;
    dx = memoryAGet16(cs, 0x0014);
    di = 0;
loc_30adb:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += dx;
    cx = 0x0028;
loc_30ae8:
    lodsb<MemAuto, DirAuto>();
    ah = al;
    al = 0;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30af3;
    al = 0x10;
loc_30af3:
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30af9;
    al |= 0x01;
loc_30af9:
    stosb<MemAuto, DirAuto>();
    al = 0;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b02;
    al = 0x10;
loc_30b02:
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b08;
    al |= 0x01;
loc_30b08:
    stosb<MemAuto, DirAuto>();
    al = 0;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b11;
    al = 0x10;
loc_30b11:
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b17;
    al |= 0x01;
loc_30b17:
    stosb<MemAuto, DirAuto>();
    al = 0;
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b20;
    al = 0x10;
loc_30b20:
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    if (!flags.carry)
        goto loc_30b26;
    al |= 0x01;
loc_30b26:
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_30ae8;
    di = pop();
    di++;
    if (di < 0x00c8)
        goto loc_30adb;
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_30b3f;
    goto loc_30c8d;
loc_30b3f:
    si = 0;
    dx = memoryAGet16(cs, 0x0014);
    di = 0;
loc_30b48:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += dx;
    cx = 0x0028;
loc_30b55:
    lodsb<MemAuto, DirAuto>();
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b5e;
    memoryASet(es, di, memoryAGet(es, di) | 0x20);
loc_30b5e:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b66;
    memoryASet(es, di, memoryAGet(es, di) | 0x02);
loc_30b66:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b6f;
    memoryASet(es, di, memoryAGet(es, di) | 0x20);
loc_30b6f:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b77;
    memoryASet(es, di, memoryAGet(es, di) | 0x02);
loc_30b77:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b80;
    memoryASet(es, di, memoryAGet(es, di) | 0x20);
loc_30b80:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b88;
    memoryASet(es, di, memoryAGet(es, di) | 0x02);
loc_30b88:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b91;
    memoryASet(es, di, memoryAGet(es, di) | 0x20);
loc_30b91:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30b99;
    memoryASet(es, di, memoryAGet(es, di) | 0x02);
loc_30b99:
    di++;
    if (--cx)
        goto loc_30b55;
    di = pop();
    di++;
    if (di < 0x00c8)
        goto loc_30b48;
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_30bb2;
    goto loc_30c8d;
loc_30bb2:
    si = 0;
    dx = memoryAGet16(cs, 0x0014);
    di = 0;
loc_30bbb:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += dx;
    cx = 0x0028;
loc_30bc8:
    lodsb<MemAuto, DirAuto>();
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30bd1;
    memoryASet(es, di, memoryAGet(es, di) | 0x40);
loc_30bd1:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30bd9;
    memoryASet(es, di, memoryAGet(es, di) | 0x04);
loc_30bd9:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30be2;
    memoryASet(es, di, memoryAGet(es, di) | 0x40);
loc_30be2:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30bea;
    memoryASet(es, di, memoryAGet(es, di) | 0x04);
loc_30bea:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30bf3;
    memoryASet(es, di, memoryAGet(es, di) | 0x40);
loc_30bf3:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30bfb;
    memoryASet(es, di, memoryAGet(es, di) | 0x04);
loc_30bfb:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c04;
    memoryASet(es, di, memoryAGet(es, di) | 0x40);
loc_30c04:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c0c;
    memoryASet(es, di, memoryAGet(es, di) | 0x04);
loc_30c0c:
    di++;
    if (--cx)
        goto loc_30bc8;
    di = pop();
    di++;
    if (di < 0x00c8)
        goto loc_30bbb;
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_30c25;
    goto loc_30c8d;
loc_30c25:
    si = 0;
    dx = memoryAGet16(cs, 0x0014);
    di = 0;
loc_30c2e:
    push(di);
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += dx;
    cx = 0x0028;
loc_30c3b:
    lodsb<MemAuto, DirAuto>();
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c44;
    memoryASet(es, di, memoryAGet(es, di) | 0x80);
loc_30c44:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c4c;
    memoryASet(es, di, memoryAGet(es, di) | 0x08);
loc_30c4c:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c55;
    memoryASet(es, di, memoryAGet(es, di) | 0x80);
loc_30c55:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c5d;
    memoryASet(es, di, memoryAGet(es, di) | 0x08);
loc_30c5d:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c66;
    memoryASet(es, di, memoryAGet(es, di) | 0x80);
loc_30c66:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c6e;
    memoryASet(es, di, memoryAGet(es, di) | 0x08);
loc_30c6e:
    di++;
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c77;
    memoryASet(es, di, memoryAGet(es, di) | 0x80);
loc_30c77:
    flags.carry = !!(al & 0x80);
    al <<= 1;
    if (!flags.carry)
        goto loc_30c7f;
    memoryASet(es, di, memoryAGet(es, di) | 0x08);
loc_30c7f:
    di++;
    if (--cx)
        goto loc_30c3b;
    di = pop();
    di++;
    if (di < 0x00c8)
        goto loc_30c2e;
    ds = pop();
    goto loc_30c93;
loc_30c8d:
    ds = pop();
    memoryASet(ds, 0x359c, 0xff);
loc_30c93:
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30ca2;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_30ca2;
    return;
loc_30ca2:
    sub_2f112();
}
void sub_30ca6()
{
    si = 0x39ca;
    dx = 0x3cac;
    sub_3059d();
    bx = ax;
    memoryASet16(ds, 0x35e6, ax);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_30cc0;
    goto loc_30d48;
loc_30cc0:
    al = 0;
    sub_312f4();
    dx = memoryAGet16(ds, 0x46f2);
    push(ds);
    ds = dx;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30d26;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30d26;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30d26;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0;
    interrupt(0x21);
loc_30d26:
    ds = pop();
    if (!flags.carry)
        goto loc_30d2e;
    memoryASet(ds, 0x359c, 0xff);
loc_30d2e:
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30d3d;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_30d3d;
    goto loc_30d40;
loc_30d3d:
    sub_2f112();
loc_30d40:
    al = 0x02;
    sub_312f4();
    return;
loc_30d48:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_30d52;
    goto loc_30d6c;
loc_30d52:
    al = 0;
    sub_312f4();
    es = memoryAGet16(ds, 0x46f2);
    di = 0;
    bx = memoryAGet16(ds, 0x35e6);
    sub_30ab8();
    al = 0x02;
    sub_312f4();
    return;
loc_30d6c:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_30d76;
    return;
loc_30d76:
    ax = 0x1000;
    es = ax;
    bx = memoryAGet16(ds, 0x35e6);
    di = 0x49ea;
    sub_308e1();
    flags.direction = false;
    es = memoryAGet16(ds, 0x46f2);
    di = 0;
    si = 0x49ea;
    cx = 0x4000;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_30d97()
{
    si = 0x39ca;
    dx = 0x3cb6;
    sub_3059d();
    bx = ax;
    memoryASet16(ds, 0x35e6, ax);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_30db1;
    goto loc_30e33;
loc_30db1:
    dx = memoryAGet16(ds, 0x46f2);
    push(ds);
    ds = dx;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0x2000;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30e16;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0x2000;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30e16;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0x2000;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30e16;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    cx = 0x1f40;
    dx = 0x2000;
    interrupt(0x21);
loc_30e16:
    ds = pop();
    if (!flags.carry)
        goto loc_30e1e;
    memoryASet(ds, 0x359c, 0xff);
loc_30e1e:
    ah = 0x3e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_30e2d;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_30e2d;
    goto loc_30e30;
loc_30e2d:
    sub_2f112();
loc_30e30:
    return;
loc_30e33:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_30e3d;
    goto loc_30e4d;
loc_30e3d:
    push(ds);
    es = pop();
    di = 0x49ea;
    bx = memoryAGet16(ds, 0x35e6);
    sub_30ab8();
    return;
loc_30e4d:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_30e57;
    return;
loc_30e57:
    ax = 0x1000;
    es = ax;
    bx = memoryAGet16(ds, 0x35e6);
    di = 0x49ea;
    sub_308e1();
}
void sub_30e68()
{
    si = memoryAGet16(ds, 0x46f4);
    bx = 0x4652;
    si <<= 1;
    dx = memoryAGet16(ds, bx + si);
    di = dx;
    memoryASet16(ds, 0x414e, dx);
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_30e89;
    al = memoryAGet(ds, di);
    memoryASet(ds, 0x3560, al);
    sub_3132a();
loc_30e89:
    sub_311a5();
    si = 0x3b55;
    memoryASet16(ds, 0x4154, 0x000d);
    memoryASet16(ds, 0x4156, 0x0780);
    al = memoryAGet(ds, 0x3566);
    memoryASet(ds, 0x3564, al);
    sub_3074d();
    si = 0x3b60;
    memoryASet16(ds, 0x4154, 0x000d);
    memoryASet16(ds, 0x4156, 0x08c0);
    sub_3074d();
    si = memoryAGet16(ds, 0x46f4);
    bx = 0x462a;
    si <<= 1;
    dx = memoryAGet16(ds, bx + si);
    if ((short)memoryAGet16(ds, 0x46f4) >= (short)0x0003)
        goto loc_30ed1;
    si = 0x39ca;
    goto loc_30ed5;
loc_30ed1:
    si = 0x39df;
loc_30ed5:
    sub_3059d();
    memoryASet16(ds, 0x35e6, ax);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_30ee5;
    goto loc_30f12;
loc_30ee5:
    memoryASet16(cs, 0x0008, 0x2000);
    sub_30fc7();
    si = memoryAGet16(ds, 0x46f4);
    bx = 0x463e;
    si <<= 1;
    dx = memoryAGet16(ds, bx + si);
    si = 0x39df;
    sub_3059d();
    memoryASet16(ds, 0x35e6, ax);
    memoryASet16(cs, 0x0008, 0x4000);
    sub_30fc7();
    goto loc_30f9f;
loc_30f12:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_30f1c;
    goto loc_30f53;
loc_30f1c:
    ax = 0x1000;
    es = ax;
    bx = memoryAGet16(ds, 0x35e6);
    di = 0x49ea;
    sub_30ab8();
    ax = 0x24db;
    es = ax;
    si = memoryAGet16(ds, 0x46f4);
    bx = 0x463e;
    si <<= 1;
    dx = memoryAGet16(ds, bx + si);
    si = 0x39df;
    sub_3059d();
    memoryASet16(ds, 0x35e6, ax);
    bx = ax;
    di = 0x0;
    sub_30ab8();
    goto loc_30f9f;
loc_30f53:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_30f5d;
    goto loc_30f9f;
loc_30f5d:
    ax = 0x1000;
    es = ax;
    bx = memoryAGet16(ds, 0x35e6);
    di = 0x49ea;
    memoryASet16(cs, 0x0004, 0x0000);
    sub_308e1();
    ax = 0x24db;
    es = ax;
    si = memoryAGet16(ds, 0x46f4);
    bx = 0x463e;
    si <<= 1;
    dx = memoryAGet16(ds, bx + si);
    si = 0x39df;
    sub_3059d();
    memoryASet16(ds, 0x35e6, ax);
    bx = ax;
    di = 0x0;
    memoryASet16(cs, 0x0004, 0x000a);
    sub_308e1();
loc_30f9f:
    sub_313dd();
    sub_2fd41();
    ax = 0;
    bx = 0;
    cx = 0x013f;
    dx = 0x0017;
    si = 0x0001;
    sub_2da06();
    ax = 0x0002;
    bx = 0x0002;
    cx = 0x013d;
    dx = 0x0015;
    si = 0;
    sub_2da06();
}
void sub_30fc7()
{
    ah = 0x3f;
    bx = memoryAGet16(ds, 0x35e6);
    push(ds);
    if (memoryAGet16(cs, 0x0008) < 0x2000)
        goto loc_31008;
    if (memoryAGet(ds, 0x35ac) != 0xff)
        goto loc_31008;
    if (memoryAGet16(cs, 0x0008) != 0x2000)
        goto loc_30ff9;
    cx = 0x7d00;
    dx = 0x49ea;
    interrupt(0x21);
    si = 0x49ea;
    if (flags.carry)
        goto loc_30ff7;
    sub_2e147();
loc_30ff7:
    goto loc_31006;
loc_30ff9:
    cx = 0x7d00;
    dx = 0x24db;
    ds = dx;
    dx = 0x0000;
    interrupt(0x21);
loc_31006:
    goto loc_31054;
loc_31008:
    dx = memoryAGet16(ds, 0x46f2);
    ds = dx;
    dx = memoryAGet16(cs, 0x0008);
    cx = 0x1f40;
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    interrupt(0x21);
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    interrupt(0x21);
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    interrupt(0x21);
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    ah = 0x3f;
    interrupt(0x21);
loc_31054:
    ds = pop();
    if (!flags.carry)
        goto loc_3105c;
    memoryASet(ds, 0x359c, 0xff);
loc_3105c:
    ah = 0x3e;
    bx = memoryAGet16(ds, 0x35e6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_3106f;
    if (memoryAGet(ds, 0x359c) == 0xff)
        goto loc_3106f;
    return;
loc_3106f:
    sub_2f112();
}
void sub_31073()
{
    if (memoryAGet16(ds, bx) == 0xff02)
        goto loc_31085;
    if (memoryAGet16(ds, bx) < 0xff08)
        goto loc_31086;
    if (memoryAGet16(ds, bx) > 0xff0f)
        goto loc_31086;
loc_31085:
    return;
loc_31086:
    memoryASet16(ds, bx, 0xff11);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_31091()
{
    if (memoryAGet16(ds, bx) != 0xff02)
        goto loc_31098;
    return;
loc_31098:
    memoryASet16(ds, bx, 0xff46);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_310a3()
{
    push(ds);
    push(es);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_310af;
    goto loc_31111;
loc_310af:
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    si = 0x0;
    cx = 0x0280;
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    ax = 0x1cda;
    ds = ax;
    flags.direction = false;
    di = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    di = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    di = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x08;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    di = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    goto loc_31174;
loc_31111:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_3111b;
    goto loc_31144;
loc_3111b:
    si = 0x0;
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    ax = 0x1cda;
    ds = ax;
    flags.direction = false;
    bx = 0x0028;
loc_3112d:
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    cx = 0x0050;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    if (bx < 0x0048)
        goto loc_3112d;
    goto loc_31174;
loc_31144:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_3114e;
    goto loc_31174;
loc_3114e:
    si = 0x0;
    ax = memoryAGet16(ds, 0x46f2);
    es = ax;
    ax = 0x1cda;
    ds = ax;
    flags.direction = false;
    bx = 0x0028;
loc_31160:
    di = bx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    cx = 0x0028;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    if (bx < 0x0048)
        goto loc_31160;
loc_31174:
    es = pop();
    ds = pop();
}
void sub_31177()
{
    push(ds);
    dx = memoryAGet16(cs, 0x0010);
    ax = memoryAGet16(cs, 0x0012);
    ds = ax;
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    memoryASet16(cs, 0x0010, 0x0000);
    memoryASet16(cs, 0x0012, 0x0000);
    flags.interrupts = false;
    al = 0x36;
    out(0x43, al);
    al = 0;
    out(0x40, al);
    out(0x40, al);
    flags.interrupts = true;
}
void sub_311a5()
{
    push(ds);
    push(es);
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_311b1;
    goto loc_31213;
loc_311b1:
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x00;
    out(dx, al);
    dx = pop();
    di = 0x0;
    cx = 0x0280;
    ax = 0x1cda;
    es = ax;
    ax = memoryAGet16(ds, 0x46f2);
    ds = ax;
    flags.direction = false;
    si = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    si = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    si = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x03;
    out(dx, al);
    dx = pop();
    cx = 0x0280;
    si = 0x0640;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    goto loc_31276;
loc_31213:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_3121d;
    goto loc_31246;
loc_3121d:
    di = 0x0;
    ax = 0x1cda;
    es = ax;
    ax = memoryAGet16(ds, 0x46f2);
    ds = ax;
    flags.direction = false;
    bx = 0x0028;
loc_3122f:
    si = bx;
    si <<= 1;
    si = memoryAGet16(cs, si + 55);
    cx = 0x0050;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    if (bx < 0x0048)
        goto loc_3122f;
    goto loc_31276;
loc_31246:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_31250;
    goto loc_31276;
loc_31250:
    di = 0x0;
    ax = 0x1cda;
    es = ax;
    ax = memoryAGet16(ds, 0x46f2);
    ds = ax;
    flags.direction = false;
    bx = 0x0028;
loc_31262:
    si = bx;
    si <<= 1;
    si = memoryAGet16(cs, si + 55);
    cx = 0x0028;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx++;
    if (bx < 0x0048)
        goto loc_31262;
loc_31276:
    ax = 0x003b;
    bx = 0x0029;
    cx = 0x0104;
    dx = 0x0046;
    si = 0x0001;
    sub_2da06();
    ax = 0x003d;
    bx = 0x002b;
    cx = 0x0102;
    dx = 0x0044;
    si = 0;
    sub_2da06();
    es = pop();
    ds = pop();
}
void sub_3129c()
{
    ax = memoryAGet16(ds, 0x46f4);
    ax <<= 1;
    ax <<= 1;
    ax += memoryAGet16(ds, 0x35f0);
    cx = 0x0370;
    mul(cx);
    dx = ax;
    cx = 0;
    bx = memoryAGet16(ds, 0x35e8);
    ah = 0x42;
    al = 0;
    interrupt(0x21);
}
void sub_312bb()
{
    push(ax);
    push(bx);
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_312c7;
    goto loc_312cf;
loc_312c7:
    ax = 0x0009;
    interrupt(0x10);
    goto loc_312f1;
loc_312cf:
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_312d9;
    goto loc_312e1;
loc_312d9:
    ax = 0x000d;
    interrupt(0x10);
    goto loc_312f1;
loc_312e1:
    ax = 0x0004;
    interrupt(0x10);
    ah = 0x0b;
    bx = 0;
    interrupt(0x10);
    memoryASet(ds, 0x355e, 0x01);
loc_312f1:
    bx = pop();
    ax = pop();
}
void sub_312f4()
{
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_312fc;
    return;
loc_312fc:
    if (al)
        goto loc_31306;
    dx = 0x4071;
    goto loc_31328;
loc_31306:
    if (al != 0x01)
        goto loc_31310;
    dx = 0x4082;
    goto loc_31328;
loc_31310:
    if (al != 0x02)
        goto loc_3131a;
    dx = 0x4093;
    goto loc_31328;
loc_3131a:
    if (al != 0x03)
        goto loc_31324;
    dx = 0x40a4;
    goto loc_31328;
loc_31324:
    dx = 0x40a4;
loc_31328:
    goto loc_3132d;
    //   gap of 3 bytes
loc_3132d:
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_31335;
    return;
loc_31335:
    push(cx);
    push(di);
    push(si);
    push(es);
    ax = 0x1002;
    push(ds);
    es = pop();
    interrupt(0x10);
    es = pop();
    si = pop();
    di = pop();
    cx = pop();
}
void sub_3132a()
{
    sub_2ed94();
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_31335;
    return;
loc_31335:
    push(cx);
    push(di);
    push(si);
    push(es);
    ax = 0x1002;
    push(ds);
    es = pop();
    interrupt(0x10);
    es = pop();
    si = pop();
    di = pop();
    cx = pop();
}
void sub_31345()
{
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    flags.direction = false;
    memoryASet16(ds, 0x35ea, 0x0000);
    push(cs);
    es = pop();
    di = 0x1c7;
    bx = 0x46fc;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx += ax;
loc_31366:
    si = memoryAGet16(ds, 0x35ea);
    al = memoryAGet(ds, bx + si);
    al <<= 1;
    al <<= 1;
    ah = 0;
    dx = ax;
    cx = 0x0010;
    si = bx;
loc_31379:
    lodsb<MemAuto, DirAuto>();
    ax += dx;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_31379;
    memoryASet16(ds, 0x35ea, memoryAGet16(ds, 0x35ea) + 1);
    if (memoryAGet16(ds, 0x35ea) < 0x0010)
        goto loc_31366;
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_31392()
{
    push(ds);
    ah = 0x35;
    al = 0x08;
    interrupt(0x21);
    ax = es;
    if (memoryAGet16(cs, 0x0012) == ax)
        goto loc_313cc;
    memoryASet16(cs, 0x0010, bx);
    memoryASet16(cs, 0x0012, es);
    ah = 0x25;
    al = 0x08;
    push(cs);
    ds = pop();
    dx = 0x48dd;
    interrupt(0x21);
    ah = 0x25;
    al = 0x23;
    dx = 0x2914;
    interrupt(0x21);
    ah = 0x25;
    al = 0x24;
    dx = 0x2bd7;
    interrupt(0x21);
loc_313cc:
    ds = pop();
    flags.interrupts = false;
    al = 0x36;
    out(0x43, al);
    ax = 0x4dae;
    out(0x40, al);
    al = ah;
    out(0x40, al);
    flags.interrupts = true;
}
void sub_313dd()
{
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_313e5;
    return;
loc_313e5:
    push(ds);
    ax = memoryAGet16(ds, 0x46f2);
    ds = ax;
    es = ax;
    flags.direction = false;
    dx = 0x03ce;
    al = 0x03;
    out(dx, al);
    dx++;
    al = 0x04;
    out(dx, al);
    push(dx);
    dx = 0x03ce;
    ax = 0x0004;
    out(dx, ax);
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = pop();
    sub_314b6();
    push(dx);
    dx = 0x03ce;
    ax = 0x0104;
    out(dx, ax);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = pop();
    sub_314b6();
    push(dx);
    dx = 0x03ce;
    ax = 0x0204;
    out(dx, ax);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = pop();
    sub_314b6();
    push(dx);
    dx = 0x03ce;
    ax = 0x0304;
    out(dx, ax);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = pop();
    sub_314b6();
    dx = 0x03ce;
    al = 0x03;
    out(dx, al);
    dx++;
    al = 0;
    out(dx, al);
    ds = pop();
    if (memoryAGet(ds, 0x35ac) != 0xff)
        return;
    push(ds);
    ax = 0x1000;
    es = ax;
    ax = 0xa000;
    ds = ax;
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x00;
    out(dx, al);
    dx = pop();
    si = 0x2000;
    di = 0x49ea;
    cx = 0x1f40;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x01;
    out(dx, al);
    dx = pop();
    si = 0x2000;
    cx = 0x1f40;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x02;
    out(dx, al);
    dx = pop();
    si = 0x2000;
    cx = 0x1f40;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    push(dx);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx++;
    al = 0x03;
    out(dx, al);
    dx = pop();
    si = 0x2000;
    cx = 0x1f40;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
}
void sub_314b6()
{
    flags.direction = false;
    push(ds);
    es = pop();
    dx = 0;
loc_314bb:
    di = dx;
    di <<= 1;
    di = memoryAGet16(cs, di + 55);
    di += 0x2000;
    si = di;
    si++;
    cx = 0x0028;
    if (dx < 0x0018)
        goto loc_314d6;
    cx = 0x0017;
loc_314d6:
    ah = 0;
loc_314d8:
    lodsb<MemAuto, DirAuto>();
    bl = al;
    ax &= 0x0ff0;
    al |= ah;
    stosb<MemAuto, DirAuto>();
    ah = bl;
    if (--cx)
        goto loc_314d8;
    dx++;
    if (dx < 0x002c)
        goto loc_314bb;
}
void sub_314ec()
{
    if (memoryAGet16(ds, 0x3598) != 0x0000)
        goto loc_314ff;
    ah = 0x0b;
    bx = 0x0100;
    interrupt(0x10);
    memoryASet(ds, 0x355e, 0x00);
loc_314ff:
    push(ds);
    es = pop();
    flags.direction = false;
    sub_2ed94();
    ax = 0;
    bx = 0;
    cx = 0x013f;
    dx = 0x00c7;
    si = 0;
    sub_2da06();
    ax = 0x0002;
    bx = 0x0002;
    cx = 0x013d;
    dx = 0x00c5;
    si = 0;
    sub_2da06();
    si = 0x361e;
    memoryASet(ds, 0x46ea, 0x04);
loc_3152e:
    di = si;
    al = 0;
    cx = 0x0028;
    repne_scasb<MemAuto, DirAuto>(al);
    cx++;
    cx >>= 1;
    ah = 0x02;
    bh = 0;
    dl = cl;
    dh = memoryAGet(ds, 0x46ea);
    interrupt(0x10);
    bh = 0;
    bl = 0x05;
loc_3154a:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_31555;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_3154a;
loc_31555:
    if (al)
        goto loc_31560;
    lodsb<MemAuto, DirAuto>();
    memoryASet(ds, 0x46ea, memoryAGet(ds, 0x46ea) + 1);
    goto loc_31555;
loc_31560:
    si--;
    if (al != 0xff)
        goto loc_3152e;
    memoryASet16(cs, 0x0002, 0x0000);
loc_3156c:
    sync();
    sub_2fbda();
    if (al)
        goto loc_3157c;
    if (memoryAGet16(cs, 0x0002) < 0x0258)
        goto loc_3156c;
loc_3157c:
    sub_2ed94();
    ax = 0;
    bx = 0;
    cx = 0x013f;
    dx = 0x00c7;
    si = 0;
    sub_2da06();
    ax = 0x0002;
    bx = 0x0002;
    cx = 0x013d;
    dx = 0x00c5;
    si = 0;
    sub_2da06();
    si = 0x369d;
    memoryASet(ds, 0x46ea, 0x03);
loc_315a8:
    di = si;
    al = 0;
    cx = 0x0028;
    repne_scasb<MemAuto, DirAuto>(al);
    cx++;
    cx >>= 1;
    ah = 0x02;
    bh = 0;
    dl = cl;
    dh = memoryAGet(ds, 0x46ea);
    interrupt(0x10);
    bh = 0;
    bl = 0x05;
loc_315c4:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_315cf;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_315c4;
loc_315cf:
    if (al)
        goto loc_315da;
    lodsb<MemAuto, DirAuto>();
    memoryASet(ds, 0x46ea, memoryAGet(ds, 0x46ea) + 1);
    goto loc_315cf;
loc_315da:
    si--;
    if (al != 0xff)
        goto loc_315a8;
    memoryASet16(cs, 0x0002, 0x0000);
loc_315e6:
    sub_2fbda();
    if (al)
        goto loc_315f6;
    if (memoryAGet16(cs, 0x0002) < 0x0384)
        goto loc_315e6;
loc_315f6:
    sub_2ed94();
    ax = 0;
    bx = 0;
    cx = 0x013f;
    dx = 0x00c7;
    si = 0;
    sub_2da06();
    ax = 0x0002;
    bx = 0x0002;
    cx = 0x013d;
    dx = 0x00c5;
    si = 0;
    sub_2da06();
    si = 0x3824;
    memoryASet(ds, 0x46ea, 0x02);
loc_31622:
    di = si;
    al = 0;
    cx = 0x0028;
    repne_scasb<MemAuto, DirAuto>(al);
    cx++;
    cx >>= 1;
    ah = 0x02;
    bh = 0;
    dl = cl;
    dh = memoryAGet(ds, 0x46ea);
    interrupt(0x10);
    bh = 0;
    bl = 0x02;
loc_3163e:
    lodsb<MemAuto, DirAuto>();
    if (!al)
        goto loc_31649;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_3163e;
loc_31649:
    if (al)
        goto loc_31654;
    lodsb<MemAuto, DirAuto>();
    memoryASet(ds, 0x46ea, memoryAGet(ds, 0x46ea) + 1);
    goto loc_31649;
loc_31654:
    si--;
    if (al != 0xff)
        goto loc_31622;
    memoryASet16(cs, 0x0002, 0x0000);
loc_31660:
    sub_2fbda();
    if (al)
        return;
    if (memoryAGet16(cs, 0x0002) < 0x04b0)
        goto loc_31660;
}
void sub_31671()
{
    if (memoryAGet(ds, 0x35b2) != 0xff)
        goto loc_3169b;
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_3168c;
    ax = 0x1000;
    bl = 0x00;
    bh = memoryAGet(ds, 0x3560);
    interrupt(0x10);
    goto loc_31696;
loc_3168c:
    ah = 0x0b;
    bh = 0;
    bl = memoryAGet(ds, 0x3560);
    interrupt(0x10);
loc_31696:
    memoryASet(ds, 0x35b2, 0x00);
loc_3169b:
    bx = memoryAGet16(ds, 0x3584);
    if (bx != memoryAGet16(ds, 0x3cec))
        goto loc_316a6;
    return;
loc_316a6:
    memoryASet16(ds, 0x3cec, bx);
    memoryASet16(ds, 0x4154, 0x000f);
    memoryASet16(ds, 0x4156, 0x0140);
    al = memoryAGet(ds, 0x3568);
    memoryASet(ds, 0x3564, al);
    al = 0x20;
    if (bx < 0x0064)
        goto loc_316c8;
    al = 0x31;
    bx -= 0x0064;
loc_316c8:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
loc_316d1:
    if (bx < 0x000a)
        goto loc_316dd;
    al++;
    bx -= 0x000a;
    goto loc_316d1;
loc_316dd:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
    al += bl;
    sub_30629();
}
void sub_316ec()
{
    if (memoryAGet16(ds, 0x3582) == 0x0000)
        goto loc_316f4;
    return;
loc_316f4:
    if (memoryAGet16(ds, 0x416c) >= 0x003c)
        goto loc_316fc;
    return;
loc_316fc:
    memoryASet16(ds, 0x416c, 0x0000);
    memoryASet16(ds, 0x4160, memoryAGet16(ds, 0x4160) - 1);
    if ((short)memoryAGet16(ds, 0x4160) >= (short)0x0000)
        goto loc_31727;
    bx = memoryAGet16(ds, 0x35f6);
    bx -= 0x0102;
    ax = 0x0001;
    sub_2f8c5();
    memoryASet16(ds, 0x3582, 0x0008);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) & 0xbf);
    return;
loc_31727:
    sub_30707();
    if (memoryAGet16(ds, 0x4160) >= 0x000a)
        goto loc_31749;
    ax = memoryAGet16(ds, 0x4160);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0200;
    memoryASet16(ds, 0x35de, ax);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x40);
    return;
loc_31749:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) & 0xbf);
}
void sub_3174f()
{
    push(ds);
    es = pop();
    di = si;
loc_31753:
    lodsw<MemAuto, DirAuto>();
    if (ax == 0xffff)
        return;
    bx = ax;
    cl = 0x28;
    div(cl);
    cx = ax;
    al = ah;
    ah = 0;
    bx += ax;
    if (cl < 0x18)
        goto loc_31776;
    if (cl > 0x20)
        goto loc_31777;
    if (ch >= 0x18)
        goto loc_31777;
loc_31776:
    bx++;
loc_31777:
    ax = bx;
    stosw<MemAuto, DirAuto>();
    goto loc_31753;
}
void sub_3177d()
{
    push(ds);
    es = pop();
    di = si;
loc_31781:
    lodsw<MemAuto, DirAuto>();
    if (ax == 0xffff)
        return;
    bx = ax;
    cl = 0x28;
    div(cl);
    cx = ax;
    al = ah;
    ah = 0;
    bx += ax;
    bx += ax;
    bx += ax;
    if (cl < 0x18)
        goto loc_317a8;
    if (cl > 0x20)
        goto loc_317ab;
    if (ch >= 0x18)
        goto loc_317ab;
loc_317a8:
    bx += 0x0002;
loc_317ab:
    ax = bx;
    stosw<MemAuto, DirAuto>();
    goto loc_31781;
}
void sub_317b1()
{
    if (memoryAGet(ds, 0x35bc) == 0xff)
        goto loc_317bb;
    return;
loc_317bb:
    push(memoryAGet16(ds, 0x4166));
    memoryASet(ds, 0x4166, 0x00);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    sub_311a5();
    si = 0x3ad0;
    memoryASet16(ds, 0x4154, 0x000a);
    memoryASet16(ds, 0x4156, 0x0780);
    al = memoryAGet(ds, 0x3568);
    memoryASet(ds, 0x3564, al);
    sub_3074d();
    si = 0x3ade;
    memoryASet16(ds, 0x4154, 0x000a);
    memoryASet16(ds, 0x4156, 0x08c0);
    sub_3074d();
loc_317f9:
    al = memoryAGet(cs, 0x001a);
    al += memoryAGet(cs, 0x001b);
    if (al != 0x02)
        goto loc_31816;
    ah = 0x02;
    interrupt(0x16);
    if (!(al & 0x02))
        goto loc_31816;
    sub_31834();
    if (ah == 0x01)
        goto loc_31827;
loc_31816:
    ah = 0x01;
    interrupt(0x16);
    if (flags.zero)
        goto loc_31825;
    ah = 0;
    interrupt(0x16);
    if (ah == 0x01)
        goto loc_31827;
loc_31825:
    goto loc_317f9;
loc_31827:
    memoryASet(ds, 0x35bc, 0x00);
    sub_310a3();
    memoryASet16(ds, 0x4166, pop());
}
void sub_31834()
{
loc_31834:
    ah = 0;
    interrupt(0x16);
    if (ah != 0x26)
        goto loc_31848;
    memoryASet16(ds, 0x415a, memoryAGet16(ds, 0x415a) + 1);
    sub_31c81();
    ah = 0;
    goto loc_31871;
loc_31848:
    if (ah != 0x31)
        goto loc_3185d;
    memoryASet(ds, 0x35a6, 0xff);
    memoryASet(ds, 0x35be, 0xff);
    ah = 0x01;
    return;
    //   gap of 2 bytes
loc_3185d:
    if (ah != 0x19)
        goto loc_3186f;
    memoryASet16(ds, 0x415e, memoryAGet16(ds, 0x415e) + 0x03e8);
    sub_3065f();
    ah = 0;
    goto loc_31871;
loc_3186f:
    return;
loc_31871:
    goto loc_31834;
}
void sub_31874()
{
loc_31874:
    sync();
    sync();
    sync();
    sync();
//    ax = memoryAGet16(cs, 0x0002);
//    if (ax < 0x0006)
//        goto loc_31874;
    ax = memoryAGet16(cs, 0x0002);
    memoryASet16(ds, 0x46ee, memoryAGet16(ds, 0x46ee) + ax);
    memoryASet16(cs, 0x0002, 0x0000);
}
void sub_31a83()
{
    memoryASet(ds, bx, 0x8c);
    memoryASet(ds, bx + 1, 0xf8);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_31a91()
{
    memoryASet(ds, bx, 0x90);
    memoryASet(ds, bx + 1, 0xf8);
    memoryASet16(ds, bx + 128, 0xffff);
}
void sub_31a9f()
{
    flags.direction = false;
    memoryASet16(ds, 0x35ee, memoryAGet16(ds, 0x35ee) + 1);
    memoryASet16(ds, 0x35ee, memoryAGet16(ds, 0x35ee) & 0x0003);
    si = memoryAGet16(ds, 0x35ee);
    si <<= 1;
    bx = 0x42ee;
    bx += si;
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_31abf;
    goto loc_31afb;
loc_31abf:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x00c0;
    si = memoryAGet16(ds, bx);
    si += 0x2000;
    push(dx);
    dx = 0x03ce;
    ah = 0x01;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(ds);
    push(es);
    ds = pop();
    dx = 0x0010;
loc_31ae5:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    si += 0x0026;
    dx--;
    if (dx != 0)
        goto loc_31ae5;
    dx = 0x03ce;
    ax = 0x0005;
    out(dx, ax);
    ds = pop();
    return;
loc_31afb:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_31b05;
    goto loc_31baf;
loc_31b05:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x00e0;
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    return;
loc_31baf:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_31bb9;
    return;
loc_31bb9:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x0120;
    si = memoryAGet16(ds, bx);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
}
void sub_31c81()
{
    bx = 0x42c4;
    bx += 0x0018;
    memoryASet16(cs, 0x0035, 0x0000);
    if ((short)memoryAGet16(ds, 0x415a) > (short)0x0004)
        goto loc_31c99;
    goto loc_31d12;
loc_31c99:
    push(bx);
    si = 0;
    sub_31d2e();
    si = 0;
    sub_31d2e();
    bx = memoryAGet16(ds, 0x415a);
    bx--;
    if ((short)bx < (short)0x03e8)
        goto loc_31cb2;
    bx = 0x03e7;
loc_31cb2:
    memoryASet16(ds, 0x4154, 0x0001);
    memoryASet16(ds, 0x4156, 0x0140);
    al = memoryAGet(ds, 0x3568);
    memoryASet(ds, 0x3564, al);
    al = 0x30;
    cx = 0;
loc_31cc8:
    if ((short)bx < (short)0x0064)
        goto loc_31cd7;
    al++;
    bx -= 0x0064;
    cx = 0x0001;
    goto loc_31cc8;
loc_31cd7:
    if (cx)
        goto loc_31cdd;
    al = 0x20;
loc_31cdd:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
loc_31ce6:
    if ((short)bx < (short)0x000a)
        goto loc_31cf5;
    al++;
    bx -= 0x000a;
    cx = 0x0001;
    goto loc_31ce6;
loc_31cf5:
    if (cx)
        goto loc_31cfb;
    al = 0x20;
loc_31cfb:
    sub_30629();
    memoryASet16(ds, 0x4154, memoryAGet16(ds, 0x4154) + 1);
    al = 0x30;
    al += bl;
    sub_30629();
    bx = pop();
    si = memoryAGet16(ds, bx);
    sub_31d2e();
    return;
loc_31d12:
    cx = 0x0001;
loc_31d15:
    ax = memoryAGet16(ds, 0x415a);
    if ((short)ax <= (short)cx)
        goto loc_31d20;
    si = memoryAGet16(ds, bx);
    goto loc_31d22;
loc_31d20:
    si = 0;
loc_31d22:
    push(cx);
    sub_31d2e();
    cx = pop();
    cx++;
    if ((short)cx <= (short)0x0003)
        goto loc_31d15;
}
void sub_31d2e()
{
    if (memoryAGet16(ds, 0x3598) == 0x0001)
        goto loc_31d38;
    goto loc_31d7d;
loc_31d38:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x00a1;
    di += memoryAGet16(cs, 0x0035);
    si += 0x2000;
    push(dx);
    dx = 0x03ce;
    ah = 0x01;
    al = 0x05;
    out(dx, ax);
    dx = pop();
    push(dx);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = pop();
    push(ds);
    push(es);
    ds = pop();
    dx = 0x0010;
loc_31d61:
    movsb<MemAuto, MemAuto, DirAuto>();
    movsb<MemAuto, MemAuto, DirAuto>();
    di += 0x0026;
    si += 0x0026;
    dx--;
    if (dx != 0)
        goto loc_31d61;
    dx = 0x03ce;
    ax = 0x0005;
    out(dx, ax);
    ds = pop();
    memoryASet16(cs, 0x0035, memoryAGet16(cs, 0x0035) + 0x0002);
    return;
loc_31d7d:
    if (memoryAGet16(ds, 0x3598) == 0x0000)
        goto loc_31d87;
    goto loc_31e3a;
loc_31d87:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x00a2;
    di += memoryAGet16(cs, 0x0035);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xe04c;
    si += 0xe04c;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ffc;
    si += 0x1ffc;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(cs, 0x0035, memoryAGet16(cs, 0x0035) + 0x0004);
    return;
loc_31e3a:
    if (memoryAGet16(ds, 0x3598) == 0x0002)
        goto loc_31e44;
    return;
loc_31e44:
    es = memoryAGet16(ds, 0x46f2);
    di = 0x00a4;
    di += memoryAGet16(cs, 0x0035);
    ax = 0x49ea;
    si += ax;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0xa098;
    si += 0xa098;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    di += 0x1ff8;
    si += 0x1ff8;
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    movsw<MemAuto, MemAuto, DirAuto>();
    memoryASet16(cs, 0x0035, memoryAGet16(cs, 0x0035) + 0x0008);
}
void sub_31f15()
{
    push(bx);
    push(di);
    bx = 0x44d6;
    if ((short)memoryAGet16(ds, 0x3584) > (short)0x0000)
        goto loc_31f26;
    bx = 0x4526;
loc_31f26:
    di = memoryAGet16(ds, 0x46f4);
    di <<= 1;
    di <<= 1;
    di += memoryAGet16(ds, 0x35f0);
    di <<= 1;
    ax = memoryAGet16(ds, bx + di);
    memoryASet16(ds, 0x415e, memoryAGet16(ds, 0x415e) + ax);
    sub_3065f();
    di = pop();
    bx = pop();
}
void sub_32140()
{
    al++;
    if (al <= 0x4b)
        goto loc_32148;
    al = 0x48;
loc_32148:
    memoryASet(ds, si, al);
    ah = 0xff;
    memoryASet16(ds, 0x3544, ax);
    sub_2fb0c();
    memoryASet16(ds, 0x3542, memoryAGet16(ds, 0x3542) + 1);
    ax = memoryAGet16(ds, 0x3542);
    if (ax < memoryAGet16(ds, 0x3540))
        return;
    sub_2d4f1();
    memoryASet(ds, 0x35a2, 0x00);
}
void sub_32168()
{
    if (memoryAGet(ds, 0x35d0) != 0xff)
        goto loc_3219c;
    if (al != 0xa0)
        goto loc_32177;
    ah = 0xa7;
    goto loc_3218c;
loc_32177:
    if (al != 0xa7)
        goto loc_3217f;
    ah = 0xa0;
    goto loc_3218c;
loc_3217f:
    ah = 0xa0;
    ah += memoryAGet(ds, 0x354e);
    ah--;
    ah -= al;
    ah += 0xa0;
loc_3218c:
    memoryASet(ds, si, ah);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) + 0x02);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0xfb);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    return;
loc_3219c:
    if (memoryAGet(ds, 0x35d4) != 0x00)
        return;
    if (al != 0xa6)
        goto loc_321ab;
    memoryASet16(ds, 0x3552, si);
loc_321ab:
    al++;
    if (al != 0xa8)
        goto loc_321bd;
    if (si == memoryAGet16(ds, 0x3552))
        goto loc_321bb;
    al = 0x00;
    goto loc_321bd;
loc_321bb:
    al = 0xa7;
loc_321bd:
    memoryASet(ds, si, al);
}
void sub_321c0()
{
    memoryASet(ds, si, 0xa0);
}
void sub_321c4()
{
    memoryASet(ds, si, 0xa7);
}
void sub_321c8()
{
    if ((short)memoryAGet16(ds, 0x35e2) < (short)0x04b0)
        goto loc_321dc;
    memoryASet16(ds, si, 0xffa0);
    memoryASet16(ds, 0x354e, 0x0001);
    return;
loc_321dc:
    al++;
    if (al <= 0x7b)
        goto loc_321e4;
    al = 0x78;
loc_321e4:
    memoryASet(ds, si, al);
}
void sub_321e7()
{
    bx = si;
    al = memoryAGet(ds, bx + 256);
    if (al == 0x00)
        goto loc_321f8;
    if (al == 0x1e)
        goto loc_321f8;
    goto loc_321ff;
loc_321f8:
    memoryASet16(ds, bx, 0xff46);
    return;
loc_321ff:
    if (al == 0x44)
        goto loc_32216;
    if (al == 0x46)
        goto loc_32216;
    if (al == 0x03)
        goto loc_32216;
    if (al == 0x42)
        goto loc_32216;
    if (al == 0x40)
        goto loc_32216;
    goto loc_32247;
loc_32216:
    if (memoryAGet(ds, bx + 65534) != 0x00)
        goto loc_3222e;
    if (memoryAGet(ds, bx + 254) != 0x00)
        goto loc_3222e;
    memoryASet16(ds, bx + 65534, 0xff46);
    memoryASet16(ds, bx, 0xff00);
    goto loc_32244;
loc_3222e:
    if (memoryAGet(ds, bx + 2) != 0x00)
        goto loc_32244;
    if (memoryAGet(ds, bx + 258) != 0x00)
        goto loc_32244;
    memoryASet16(ds, bx + 2, 0xff47);
    memoryASet16(ds, bx, 0xff00);
loc_32244:
    return;
loc_32247:
    if (al >= 0x74)
        goto loc_3224e;
    goto loc_32293;
loc_3224e:
    if (al <= 0x77)
        goto loc_32255;
    goto loc_32293;
loc_32255:
    if (memoryAGet(ds, 0x35ce) != 0x00)
        goto loc_32267;
    memoryASet(ds, 0x35ce, 0xff);
    ax = memoryAGet16(ds, 0x35e0);
    memoryASet16(ds, 0x3be0, ax);
loc_32267:
    ax = memoryAGet16(ds, 0x35e0);
    ax -= memoryAGet16(ds, 0x3be0);
    if ((short)ax > (short)0x0e10)
        goto loc_32290;
    memoryASet16(ds, bx, 0xff1e);
    memoryASet16(ds, bx + 128, 0xffff);
    if (memoryAGet(ds, bx + 512) != 0x00)
        goto loc_32290;
    memoryASet16(ds, bx + 512, 0xff43);
    memoryASet16(ds, bx + 640, 0xffff);
loc_32290:
    return;
loc_32293:
    if (al == 0x04)
        goto loc_3229a;
    return;
loc_3229a:
    sub_308d1();
    if (ax >= 0x00b0)
        return;
    if (memoryAGet(ds, bx + 512) != 0x00)
        return;
    memoryASet16(ds, bx, 0xff1e);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 512, 0xff47);
    memoryASet16(ds, bx + 640, 0xffff);
}
void sub_322c0()
{
    bx = si;
    al = memoryAGet(ds, bx + 256);
    if (al == 0x00)
        goto loc_322d1;
    if (al == 0x1e)
        goto loc_322d1;
    goto loc_322de;
loc_322d1:
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 256, 0xff47);
    return;
loc_322de:
    if (al == 0x8c)
        goto loc_322e5;
    goto loc_322f1;
loc_322e5:
    bx -= 0x0002;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_322f1:
    if (al == 0x90)
        goto loc_322f8;
    goto loc_32304;
loc_322f8:
    bx -= 0x0002;
    ax = 0x0002;
    sub_2f8c5();
    return;
loc_32304:
    if (al == 0x10)
        goto loc_3230b;
    goto loc_32317;
loc_3230b:
    bx -= 0x0002;
    ax = 0x0002;
    sub_2f8c5();
    return;
loc_32317:
    if (al == 0x44)
        goto loc_3232e;
    if (al == 0x46)
        goto loc_3232e;
    if (al == 0x03)
        goto loc_3232e;
    if (al == 0x42)
        goto loc_3232e;
    if (al == 0x40)
        goto loc_3232e;
    goto loc_3238a;
loc_3232e:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x10);
    if (memoryAGet(ds, bx + 65534) != 0x00)
        goto loc_3235b;
    if (memoryAGet(ds, bx + 254) == 0x00)
        goto loc_32350;
    if (memoryAGet(ds, bx + 254) == 0x8c)
        goto loc_32350;
    if (memoryAGet(ds, bx + 254) == 0x90)
        goto loc_32350;
    goto loc_3235b;
loc_32350:
    memoryASet16(ds, bx + 65534, 0xff46);
    memoryASet16(ds, bx, 0xff00);
    goto loc_32387;
loc_3235b:
    if (memoryAGet(ds, bx + 2) != 0x00)
        goto loc_32383;
    if (memoryAGet(ds, bx + 258) == 0x00)
        goto loc_32378;
    if (memoryAGet(ds, bx + 258) == 0x8c)
        goto loc_32378;
    if (memoryAGet(ds, bx + 258) == 0x90)
        goto loc_32378;
    goto loc_32383;
loc_32378:
    memoryASet16(ds, bx + 2, 0xff47);
    memoryASet16(ds, bx, 0xff00);
    goto loc_32387;
loc_32383:
    memoryASet16(ds, bx, 0xff44);
loc_32387:
    return;
loc_3238a:
    memoryASet16(ds, bx, 0xff44);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x10);
}
void sub_32394()
{
    memoryASet16(ds, si, 0xff46);
}
void sub_32399()
{
    memoryASet16(ds, si, 0xff44);
}
void sub_3239e()
{
    if (memoryAGet(ds, 0x35a4) != 0xff)
        return;
    if (al != 0x0f)
        goto loc_323af;
    memoryASet16(ds, si, 0xff0c);
    goto loc_323b1;
loc_323af:
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_323b1:
    ax = memoryAGet16(ds, 0x35fa);
    ax += 0x0004;
    if (memoryAGet(ds, si + 65280) != 0x00)
        return;
    if (ax & 0x0007)
        return;
    memoryASet16(ds, si + 65280, 0xff2c);
}
void sub_323ca()
{
    memoryASet(ds, si, 0x8c);
}
void sub_323ce()
{
    flags.direction = false;
    memoryASet16(ds, 0x3542, 0x0000);
    memoryASet(ds, 0x35d8, 0xff);
    si = 0x0;
    dx = 0x0016;
loc_323e1:
    cx = 0x0028;
    push(si);
loc_323e5:
    al = memoryAGet(ds, si);
    if (al >= 0x04)
        goto loc_323ed;
    goto loc_323f8;
loc_323ed:
    ah = 0;
    di = ax;
    di <<= 1;
    callIndirect(cs, memoryAGet16(cs, di + 20368));
loc_323f8:
    si += 0x0002;
    if (--cx)
        goto loc_323e5;
    si = pop();
    si += 0x0100;
    dx--;
    if (dx != 0)
        goto loc_323e1;
    if (memoryAGet(ds, 0x35a2) != 0xff)
        return;
    if (memoryAGet(ds, 0x35d8) != 0xff)
        return;
    sub_2d4bf();
}
void sub_32417()
{
    memoryASet16(ds, si, 0xff40);
}
void sub_3241c()
{
    memoryASet16(ds, si, 0xff40);
}
void sub_32421()
{
    memoryASet16(ds, si, 0xff00);
}
void sub_32426()
{
    memoryASet16(ds, si, 0xff44);
}
void sub_3242b()
{
    bx = si;
    sub_31a91();
}
void sub_32431()
{
    memoryASet16(ds, si, 0xff44);
}
void sub_32436()
{
    memoryASet16(ds, si, 0xff70);
}
void sub_3243b()
{
    bx = si;
    al = memoryAGet(ds, bx + 256);
    if (al == 0x00)
        goto loc_3244c;
    if (al == 0x1e)
        goto loc_3244c;
    goto loc_32453;
loc_3244c:
    memoryASet16(ds, bx, 0xff42);
    return;
loc_32453:
    if (al == 0x44)
        goto loc_3246a;
    if (al == 0x46)
        goto loc_3246a;
    if (al == 0x03)
        goto loc_3246a;
    if (al == 0x42)
        goto loc_3246a;
    if (al == 0x40)
        goto loc_3246a;
    goto loc_3249b;
loc_3246a:
    if (memoryAGet(ds, bx + 65534) != 0x00)
        goto loc_32482;
    if (memoryAGet(ds, bx + 254) != 0x00)
        goto loc_32482;
    memoryASet16(ds, bx + 65534, 0xff42);
    memoryASet16(ds, bx, 0xff00);
    goto loc_32498;
loc_32482:
    if (memoryAGet(ds, bx + 2) != 0x00)
        goto loc_32498;
    if (memoryAGet(ds, bx + 258) != 0x00)
        goto loc_32498;
    memoryASet16(ds, bx + 2, 0xff43);
    memoryASet16(ds, bx, 0xff00);
loc_32498:
    return;
loc_3249b:
    if (al >= 0x74)
        goto loc_324a2;
    goto loc_324e7;
loc_324a2:
    if (al <= 0x77)
        goto loc_324a9;
    goto loc_324e7;
loc_324a9:
    if (memoryAGet(ds, 0x35ce) != 0x00)
        goto loc_324bb;
    memoryASet(ds, 0x35ce, 0xff);
    ax = memoryAGet16(ds, 0x35e0);
    memoryASet16(ds, 0x3be0, ax);
loc_324bb:
    ax = memoryAGet16(ds, 0x35e0);
    ax -= memoryAGet16(ds, 0x3be0);
    if ((short)ax > (short)0x0e10)
        goto loc_324e4;
    memoryASet16(ds, bx, 0xff1e);
    memoryASet16(ds, bx + 128, 0xffff);
    if (memoryAGet(ds, bx + 512) != 0x00)
        goto loc_324e4;
    memoryASet16(ds, bx + 512, 0xff47);
    memoryASet16(ds, bx + 640, 0xffff);
loc_324e4:
    return;
loc_324e7:
    if (al == 0x04)
        goto loc_324ee;
    return;
loc_324ee:
    sub_308d1();
    if (ax >= 0x00b0)
        return;
    if (memoryAGet(ds, bx + 512) != 0x00)
        return;
    memoryASet16(ds, bx, 0xff1e);
    memoryASet16(ds, bx + 128, 0xffff);
    memoryASet16(ds, bx + 512, 0xff43);
    memoryASet16(ds, bx + 640, 0xffff);
}
void sub_32514()
{
    bx = si;
    al = memoryAGet(ds, bx + 256);
    if (al == 0x00)
        goto loc_32525;
    if (al == 0x1e)
        goto loc_32525;
    goto loc_32532;
loc_32525:
    memoryASet16(ds, bx, 0xff00);
    memoryASet16(ds, bx + 256, 0xff43);
    return;
loc_32532:
    if (al == 0x8c)
        goto loc_32539;
    goto loc_32545;
loc_32539:
    bx -= 0x0002;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_32545:
    if (al == 0x90)
        goto loc_3254c;
    goto loc_32558;
loc_3254c:
    bx -= 0x0002;
    ax = 0x0002;
    sub_2f8c5();
    return;
loc_32558:
    if (al == 0x10)
        goto loc_3255f;
    goto loc_3256b;
loc_3255f:
    bx -= 0x0002;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_3256b:
    if (al == 0x44)
        goto loc_32582;
    if (al == 0x46)
        goto loc_32582;
    if (al == 0x03)
        goto loc_32582;
    if (al == 0x42)
        goto loc_32582;
    if (al == 0x40)
        goto loc_32582;
    goto loc_325de;
loc_32582:
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x01);
    if (memoryAGet(ds, bx + 65534) != 0x00)
        goto loc_325af;
    if (memoryAGet(ds, bx + 254) == 0x00)
        goto loc_325a4;
    if (memoryAGet(ds, bx + 254) == 0x8c)
        goto loc_325a4;
    if (memoryAGet(ds, bx + 254) == 0x90)
        goto loc_325a4;
    goto loc_325af;
loc_325a4:
    memoryASet16(ds, bx + 65534, 0xff42);
    memoryASet16(ds, bx, 0xff00);
    goto loc_325db;
loc_325af:
    if (memoryAGet(ds, bx + 2) != 0x00)
        goto loc_325d7;
    if (memoryAGet(ds, bx + 258) == 0x00)
        goto loc_325cc;
    if (memoryAGet(ds, bx + 258) == 0x8c)
        goto loc_325cc;
    if (memoryAGet(ds, bx + 258) == 0x90)
        goto loc_325cc;
    goto loc_325d7;
loc_325cc:
    memoryASet16(ds, bx + 2, 0xff43);
    memoryASet16(ds, bx, 0xff00);
    goto loc_325db;
loc_325d7:
    memoryASet16(ds, bx, 0xff40);
loc_325db:
    return;
loc_325de:
    memoryASet16(ds, bx, 0xff40);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x01);
}
void sub_325e8()
{
    memoryASet16(ds, si, 0xff42);
}
void sub_325ed()
{
    memoryASet16(ds, si, 0xff40);
}
void sub_325f2()
{
    if (!(memoryAGet16(ds, 0x35fa) & 0x0001))
        goto loc_325fc;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_325fc:
    if (memoryAGet16(ds, si) <= 0xff33)
        return;
    memoryASet16(ds, si, 0xff30);
}
void sub_32607()
{
    if (memoryAGet16(ds, 0x3584) != 0x0000)
        return;
    memoryASet16(ds, si, 0xff30);
}
void sub_32613()
{
    if (memoryAGet(ds, si + 256) != 0x8c)
        goto loc_32627;
    bx = si;
    bx -= 0x0002;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_32627:
    if (memoryAGet(ds, si + 256) != 0x00)
        goto loc_3263a;
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, si + 256, 0xff1f);
    return;
loc_3263a:
    memoryASet16(ds, si, 0xff24);
}
void sub_3263f()
{
    if (memoryAGet(ds, si + 256) == 0x00)
        goto loc_32649;
    goto loc_32656;
loc_32649:
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, si + 256, 0xff1f);
    return;
loc_32656:
    if (memoryAGet(ds, si + 256) == 0x8c)
        goto loc_32660;
    goto loc_3266e;
loc_32660:
    bx = si;
    bx -= 0x0002;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_3266e:
    if (memoryAGet(ds, si + 1) == 0xf8)
        goto loc_32677;
    goto loc_3267c;
loc_32677:
    goto loc_32691;
    //   gap of 3 bytes
loc_3267c:
    if (memoryAGet(ds, si + 1) == 0xfa)
        goto loc_32685;
    goto loc_3268a;
loc_32685:
    goto loc_326e0;
    //   gap of 3 bytes
loc_3268a:
    sub_308d1();
    if (!(al & 0x01))
        goto loc_326e0;
loc_32691:
    if (memoryAGet(ds, si + 65534) != 0x8c)
        goto loc_326a5;
    bx = si;
    bx -= 0x0104;
    ax = 0x0001;
    sub_2f8c5();
    goto loc_326de;
loc_326a5:
    if (memoryAGet(ds, si + 65534) != 0x00)
        goto loc_326b9;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 65534, 0x28);
    memoryASet(ds, si + 65535, 0xf8);
    goto loc_326de;
loc_326b9:
    if (memoryAGet(ds, si + 2) != 0x00)
        goto loc_326cd;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 2, 0xf0);
    memoryASet(ds, si + 3, 0xfa);
    goto loc_326de;
loc_326cd:
    sub_308d1();
    if (!(al & 0x03))
        goto loc_326da;
    memoryASet16(ds, si, 0xff1e);
    goto loc_326de;
loc_326da:
    memoryASet16(ds, si, 0xff28);
loc_326de:
    return;
loc_326e0:
    if (memoryAGet(ds, si + 2) != 0x8c)
        goto loc_326f4;
    bx = si;
    bx -= 0x0100;
    ax = 0x0001;
    sub_2f8c5();
    return;
loc_326f4:
    if (memoryAGet(ds, si + 2) != 0x00)
        goto loc_32708;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 2, 0xf0);
    memoryASet(ds, si + 3, 0xfa);
    return;
loc_32708:
    if (memoryAGet(ds, si + 65534) != 0x00)
        goto loc_3271c;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 65534, 0x28);
    memoryASet(ds, si + 65535, 0xf8);
    return;
loc_3271c:
    sub_308d1();
    if (!(al & 0x03))
        goto loc_32729;
    memoryASet16(ds, si, 0xff1e);
    return;
loc_32729:
    memoryASet16(ds, si, 0xff28);
}
void sub_3272e()
{
    memoryASet(ds, si, 0x28);
}
void sub_32732()
{
    memoryASet(ds, si, 0x6c);
}
void sub_32736()
{
    if (memoryAGet(ds, 0x35b0) != 0xff)
        return;
    if (al != 0x0b)
        goto loc_32747;
    memoryASet16(ds, si, 0xff08);
    goto loc_32749;
loc_32747:
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_32749:
    if (memoryAGet16(ds, si + 256) != 0xff00)
        return;
    if (memoryAGet16(ds, 0x35fa) & 0x0007)
        return;
    memoryASet16(ds, si + 256, 0xff1f);
}
void sub_32760()
{
    memoryASet(ds, si, 0x90);
}
void sub_32764()
{
    if (memoryAGet(ds, si + 65280) == 0x00)
        goto loc_3276e;
    goto loc_3277b;
loc_3276e:
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, si + 65280, 0xff2c);
    return;
loc_3277b:
    if (memoryAGet(ds, si + 65280) >= 0x20)
        goto loc_32785;
    goto loc_3279e;
loc_32785:
    if (memoryAGet(ds, si + 65280) <= 0x2b)
        goto loc_3278f;
    goto loc_3279e;
loc_3278f:
    bx = si;
    bx -= 0x0102;
    ax = 0x0002;
    sub_2f8c5();
    return;
loc_3279e:
    if (memoryAGet(ds, si + 65280) == 0x40)
        goto loc_327a8;
    goto loc_327b4;
loc_327a8:
    bx = si;
    bx -= 0x0100;
    sub_31a83();
    return;
loc_327b4:
    if (memoryAGet(ds, si + 1) == 0xf8)
        goto loc_327bd;
    goto loc_327c2;
loc_327bd:
    goto loc_327d7;
    //   gap of 3 bytes
loc_327c2:
    if (memoryAGet(ds, si + 1) == 0xfa)
        goto loc_327cb;
    goto loc_327d0;
loc_327cb:
    goto loc_3283c;
    //   gap of 3 bytes
loc_327d0:
    sub_308d1();
    if (!(al & 0x01))
        goto loc_3283c;
loc_327d7:
    if (memoryAGet(ds, si + 65534) != 0x40)
        goto loc_327e7;
    bx = si;
    bx -= 0x0002;
    sub_31a83();
    goto loc_3283a;
loc_327e7:
    if (memoryAGet(ds, si + 65534) != 0x00)
        goto loc_327fb;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 65534, 0x2c);
    memoryASet(ds, si + 65535, 0xf8);
    goto loc_3283a;
loc_327fb:
    if (memoryAGet(ds, si + 2) != 0x00)
        goto loc_3280f;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 2, 0xf1);
    memoryASet(ds, si + 3, 0xfa);
    goto loc_3283a;
loc_3280f:
    if (memoryAGet(ds, si + 65534) < 0x20)
        goto loc_32829;
    if (memoryAGet(ds, si + 65534) > 0x2b)
        goto loc_32829;
    bx = si;
    bx -= 0x0102;
    ax = 0x0002;
    sub_2f8c5();
    goto loc_3283a;
loc_32829:
    sub_308d1();
    if (!(al & 0x03))
        goto loc_32836;
    memoryASet16(ds, si, 0xff1e);
    goto loc_3283a;
loc_32836:
    memoryASet16(ds, si, 0xff2c);
loc_3283a:
    return;
loc_3283c:
    if (memoryAGet(ds, si + 2) != 0x40)
        goto loc_3284c;
    bx = si;
    bx += 0x0002;
    sub_31a83();
    return;
loc_3284c:
    if (memoryAGet(ds, si + 2) != 0x00)
        goto loc_32860;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 2, 0xf1);
    memoryASet(ds, si + 3, 0xfa);
    return;
loc_32860:
    if (memoryAGet(ds, si + 65534) != 0x00)
        goto loc_32874;
    memoryASet16(ds, si, 0xff00);
    memoryASet(ds, si + 65534, 0x2c);
    memoryASet(ds, si + 65535, 0xf8);
    return;
loc_32874:
    if (memoryAGet(ds, si + 2) < 0x20)
        goto loc_3288e;
    if (memoryAGet(ds, si + 2) > 0x2b)
        goto loc_3288e;
    bx = si;
    bx -= 0x0102;
    ax = 0x0002;
    sub_2f8c5();
    return;
loc_3288e:
    sub_308d1();
    if (!(al & 0x03))
        goto loc_3289b;
    memoryASet16(ds, si, 0xff1e);
    return;
loc_3289b:
    memoryASet16(ds, si, 0xff2c);
}
void sub_328a0()
{
    memoryASet(ds, si, 0x2c);
}
void sub_328a4()
{
    if (memoryAGet(ds, 0x35d2) != 0xff)
        goto loc_328d8;
    if (al != 0xb0)
        goto loc_328b3;
    ah = 0xb7;
    goto loc_328c8;
loc_328b3:
    if (al != 0xb7)
        goto loc_328bb;
    ah = 0xb0;
    goto loc_328c8;
loc_328bb:
    ah = 0xb0;
    ah += memoryAGet(ds, 0x3556);
    ah--;
    ah -= al;
    ah += 0xb0;
loc_328c8:
    memoryASet(ds, si, ah);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) + 0x02);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0xfb);
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xf8);
    return;
loc_328d8:
    if (memoryAGet(ds, 0x35d6) != 0x00)
        return;
    if (al != 0xb6)
        goto loc_328e7;
    memoryASet16(ds, 0x355a, si);
loc_328e7:
    al++;
    if (al != 0xb8)
        goto loc_328f9;
    if (si == memoryAGet16(ds, 0x355a))
        goto loc_328f7;
    al = 0x00;
    goto loc_328f9;
loc_328f7:
    al = 0xb7;
loc_328f9:
    memoryASet(ds, si, al);
}
void sub_328fc()
{
    memoryASet(ds, si, 0xb0);
}
void sub_32900()
{
    memoryASet(ds, si, 0xb7);
}
void sub_32904()
{
    if ((short)memoryAGet16(ds, 0x35e4) < (short)0x04b0)
        goto loc_32918;
    memoryASet16(ds, si, 0xffb0);
    memoryASet16(ds, 0x3556, 0x0001);
    return;
loc_32918:
    al++;
    if (al <= 0x7f)
        goto loc_32920;
    al = 0x7c;
loc_32920:
    memoryASet(ds, si, al);
}
void sub_32923()
{
    if (memoryAGet(ds, si + 2) != 0x00)
        goto loc_32941;
    if (memoryAGet(ds, si + 1) & 0x01)
        goto loc_3293b;
    memoryASet16(ds, si + 2, 0xff16);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x20);
    goto loc_3293f;
loc_3293b:
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0xfe);
loc_3293f:
    goto loc_32945;
loc_32941:
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0x01);
loc_32945:
    if (memoryAGet(ds, si + 65534) != 0x00)
        goto loc_32963;
    if (memoryAGet(ds, si + 1) & 0x02)
        goto loc_3295d;
    memoryASet16(ds, si + 65534, 0xfd15);
    memoryASet(ds, 0x4164, memoryAGet(ds, 0x4164) | 0x20);
    goto loc_32961;
loc_3295d:
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0xfd);
loc_32961:
    return;
loc_32963:
    memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0x02);
}
void sub_32968()
{
    memoryASet16(ds, si, 0xfe15);
}
void sub_3296d()
{
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
}
void sub_32970()
{
    if (memoryAGet(ds, 0x35ce) != 0xff)
        return;
    ax = memoryAGet16(ds, 0x35e0);
    ax -= memoryAGet16(ds, 0x3be0);
    if ((short)ax > (short)0x0e10)
        goto loc_32985;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_32985:
    if (memoryAGet16(ds, si) <= 0xff77)
        return;
    memoryASet16(ds, si, 0xff74);
}
void sub_32990()
{
}
void sub_32991()
{
    if (memoryAGet(ds, si + 256) != 0x00)
        goto loc_329a4;
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, si + 256, 0xfff2);
    return;
loc_329a4:
    memoryASet16(ds, si, 0xff25);
}
void sub_329a9()
{
    if (memoryAGet(ds, si + 256) != 0x00)
        goto loc_329bc;
    memoryASet16(ds, si, 0xff00);
    memoryASet16(ds, si + 256, 0xff1f);
    return;
loc_329bc:
    memoryASet16(ds, si, 0xff28);
}
void sub_329c1()
{
    memoryASet16(ds, si, 0xff25);
}
void sub_329d0()
{
    push(cs);
    es = pop();
    flags.direction = false;
    cx = 0x0004;
    di = 0x28;
    ax = 0;
    rep_stosw<MemAuto, DirAuto>();
    sub_32b44();
    bx -= memoryAGet16(ds, 0xca5e);
    cx -= memoryAGet16(ds, 0xca60);
    ax = memoryAGet16(ds, 0xca66);
    ax = -ax;
    if ((short)bx >= (short)ax)
        goto loc_329fa;
    memoryASet(cs, 0x002a, 0x01);
    goto loc_32a06;
loc_329fa:
    if ((short)bx <= (short)memoryAGet16(ds, 0xca66))
        goto loc_32a06;
    memoryASet(cs, 0x002b, 0x01);
loc_32a06:
    ax = memoryAGet16(ds, 0xca68);
    ax = -ax;
    if ((short)cx >= (short)ax)
        goto loc_32a17;
    memoryASet(cs, 0x0028, 0x01);
    goto loc_32a23;
loc_32a17:
    if ((short)cx <= (short)memoryAGet16(ds, 0xca68))
        goto loc_32a23;
    memoryASet(cs, 0x0029, 0x01);
loc_32a23:
    dx = 0x0201;
    in(al, dx);
    if (al & 0x10)
        goto loc_32a3b;
    if (memoryAGet(cs, 0x0030) != 0x00)
        goto loc_32a3b;
    memoryASet(cs, 0x0030, 0x01);
    return;
loc_32a3b:
    if (!(al & 0x10))
        return;
    memoryASet(cs, 0x0030, 0x00);
}
void sub_32a46()
{
    memoryASet(ds, 0xc9f0, al);
    memoryASet(ds, 0xc9f1, bl);
    ax = 0x0030;
    bx = 0x0048;
    cx = 0x010f;
    dx = 0x0067;
    si = 0x0000;
    sub_2da06();
    ax = 0x0032;
    bx = 0x004a;
    cx = 0x010d;
    dx = 0x0065;
    sub_2da06();
    ah = 0x02;
    bh = 0x00;
    dl = memoryAGet(ds, 0xc9f1);
    dh = 0x0a;
    interrupt(0x10);
    si = 0xffffc9f2;
    ah = 0x0e;
    bh = 0x00;
    bl = memoryAGet(ds, 0xc9f0);
loc_32a86:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_32a91;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_32a86;
loc_32a91:
    ah = 0x02;
    bh = 0x00;
    dl = memoryAGet(ds, 0xc9f1);
    dh = 0x0b;
    interrupt(0x10);
    si = 0xffffca0d;
    ah = 0x0e;
    bh = 0x00;
    bl = memoryAGet(ds, 0xc9f0);
loc_32aa9:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_32ab4;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_32aa9;
loc_32ab4:
    ah = 0x00;
    interrupt(0x16);
    al |= 0x20;
    if (al == 0x79)
        goto loc_32ac4;
    if (al == 0x6e)
        goto loc_32ac4;
    goto loc_32ab4;
loc_32ac4:
    memoryASet(ds, 0x35b6, 0x00);
    if (al != 0x79)
        return;
    memoryASet(ds, 0x35b6, 0xff);
    ah = 0x02;
    bh = 0x00;
    dl = memoryAGet(ds, 0xc9f1);
    dh = 0x0a;
    interrupt(0x10);
    si = 0xffffca28;
    ah = 0x0e;
    bh = 0x00;
    bl = memoryAGet(ds, 0xc9f0);
loc_32aea:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_32af5;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_32aea;
loc_32af5:
    ah = 0x02;
    bh = 0x00;
    dl = memoryAGet(ds, 0xc9f1);
    dh = 0x0b;
    interrupt(0x10);
    si = 0xffffca43;
    ah = 0x0e;
    bh = 0x00;
    bl = memoryAGet(ds, 0xc9f0);
loc_32b0d:
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_32b18;
    ah = 0x0e;
    interrupt(0x10);
    goto loc_32b0d;
loc_32b18:
    ah = 0x00;
    interrupt(0x16);
    cx = 0;
loc_32b1e:
    if (--cx)
        goto loc_32b1e;
    sub_32b44();
    memoryASet16(ds, 0xca5e, bx);
    memoryASet16(ds, 0xca60, cx);
    memoryASet16(ds, 0xca66, bx);
    bx >>= 1;
    bx >>= 1;
    memoryASet16(ds, 0xca66, memoryAGet16(ds, 0xca66) - bx);
    memoryASet16(ds, 0xca68, cx);
    cx >>= 1;
    cx >>= 1;
    memoryASet16(ds, 0xca68, memoryAGet16(ds, 0xca68) - cx);
}
void sub_32b44()
{
    flags.interrupts = false;
    dx = 0x0201;
    out(dx, al);
    bx = 0;
    cx = 0;
loc_32b4d:
    in(al, dx);
    bx++;
    cx++;
    if (cx >= 0x03e8)
        goto loc_32b82;
    if (!(al & 0x01))
        goto loc_32b79;
    if (al & 0x02)
        goto loc_32b4d;
loc_32b5e:
    in(al, dx);
    bx++;
    if (bx >= 0x03e8)
        goto loc_32b82;
    if (al & 0x01)
        goto loc_32b5e;
    goto loc_32b82;
loc_32b71:
    in(al, dx);
    cx++;
    if (cx >= 0x03e8)
        goto loc_32b82;
loc_32b79:
    if (al & 0x02)
        goto loc_32b71;
loc_32b82:
    flags.interrupts = true;
}
void sub_32b96()
{
    memoryASet16(cs, 0x5be0, 0x0000);
    memoryASet16(cs, 0x5be2, 0xffff);
    memoryASet16(ds, 0xca72, 0x0000);
}
void sub_32bab()
{
    if (memoryAGet16(ds, 0x35f4) == 0x0002)
        goto loc_32bb3;
    return;
loc_32bb3:
    push(ax);
    push(dx);
    sub_32bca();
    dx = 0x0061;
    al = memoryAGet(cs, 0x5be4);
    out(dx, al);
    dx = pop();
    ax = pop();
}
void sub_32bca()
{
    if (memoryAGet16(ds, 0x35f4) == 0x0002)
        goto loc_32bd2;
    return;
loc_32bd2:
    push(ax);
    push(dx);
    dx = 0x00c0;
    al = 0x9f;
    out(dx, al);
    al = 0xbf;
    out(dx, al);
    al = 0xdf;
    out(dx, al);
    dx = pop();
    ax = pop();
}
void sub_32be3()
{
    push(ax);
    al = 0xb6;
    out(0x43, al);
    if (memoryAGet16(ds, 0x35f4) != 0x0002)
        goto loc_32bfa;
    dx = 0x0061;
    in(al, dx);
    memoryASet(cs, 0x5be4, al);
    al |= 0x60;
    out(dx, al);
loc_32bfa:
    ax = pop();
}
void sub_32bfc()
{
    push(ax);
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
    ax = pop();
}
void sub_32c19()
{
    sub_32bfc();
    if (memoryAGet16(ds, 0x35f4) != 0x0001)
        goto loc_32c39;
    cx = 0x0024;
    bx = 0xffffca78;
loc_32c2a:
    ax = memoryAGet16(ds, bx);
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_32c2a;
    goto loc_32c4f;
loc_32c39:
    cx = 0x0024;
    bx = 0xffffca78;
loc_32c40:
    ax = memoryAGet16(ds, bx);
    ax >>= 1;
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_32c40;
    al = 0xff;
    out(0xc0, al);
loc_32c4f:
    sub_32b96();
}
void sub_32e02()
{
    memoryASet16(cs, 0x5be0, 0x0000);
    memoryASet16(cs, 0x5be2, 0xffff);
    memoryASet16(ds, 0xca72, 0x002c);
    memoryASet16(ds, 0x35b8, 0xffff);
}
