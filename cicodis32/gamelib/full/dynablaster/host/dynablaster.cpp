#include "cico16.h"

void fixReloc(uint16_t seg);
void sub_1ed0();

void init()
{
    headerSize = 0x26d0;
    loadAddress = 0x01ed;
    endAddress = 0x18cd;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1490;
    sp = 0x1c00;
    load("dos", "dyna.exe", 93440);
    fixReloc(loadAddress);
}

void start()
{
    sub_1ed0();
}

void sub_1ed0();
void sub_1f73();
void sub_2282();
void sub_2318();
void sub_233a();
void sub_236a();
void sub_2397();
void sub_23b5();
void sub_23d3();
void sub_23ec();
void sub_2499();
void sub_24dc();
void sub_251e();
void sub_25ae();
void sub_263d();
void sub_267a();
void sub_26b6();
void sub_273a();
void sub_276b();
void sub_2782();
void sub_27d4();
void sub_2801();
void sub_281e();
void sub_286b();
void sub_2888();
void sub_28b0();
void sub_28b6();
void sub_28cd();
void sub_2922();
void sub_2952();
void sub_29dc();
void sub_2a67();
void sub_2ad4();
void sub_2bfb();
void sub_2c4d();
void sub_2c65();
void sub_2c81();
void sub_2c94();
void sub_2cb3();
void sub_2ce0();
void sub_2cf6();
void sub_2de7();
void sub_2e19();
void sub_2e42();
void sub_2e72();
void sub_2f2c();
void sub_2f35();
void sub_2f7e();
void sub_2fa7();
void sub_2fcb();
void sub_2fdd();
void sub_2fef();
void sub_305b();
void sub_30d4();
void sub_3105();
void sub_3225();
void sub_32e0();
void sub_33d1();
void sub_342c();
void sub_34ad();
void sub_34ae();
void sub_34f3();
void sub_3503();
void sub_350c();
void sub_3522();
void sub_3650();
void sub_377e();
void sub_389e();
void sub_3a0c();
void sub_3ae1();
void sub_3de6();
void sub_3e0f();
void sub_3e5d();
void sub_3ec9();
void sub_3fa2();
void sub_3fb7();
void sub_4052();
void sub_4155();
void sub_4212();
void sub_4241();
void sub_4279();
void sub_4317();
void sub_497f();
void sub_4999();
void sub_49b3();
void sub_49bd();
void sub_4a5f();
void sub_4ac7();
void sub_4bee();
void sub_4c4a();
void sub_4c70();
void sub_4cd0();
void sub_4d17();
void sub_4e4c();
void sub_4e81();
void sub_4ef1();
void sub_4f14();
void sub_4f8b();
void sub_4ffe();
void sub_504e();
void sub_50ca();
void sub_50e9();
void sub_518d();
void sub_51b6();
void sub_51ff();
void sub_521e();
void sub_5264();
void sub_52aa();
void sub_5300();
void sub_532b();
void sub_53d1();
void sub_5429();
void sub_5444();
void sub_544d();
void sub_5476();
void sub_5494();
void sub_54c6();
void sub_54f3();
void sub_552a();
void sub_5639();
void sub_567c();
void sub_56de();
void sub_5718();
void sub_573d();
void sub_576c();
void sub_579c();
void sub_57ae();
void sub_57b4();
void sub_57d2();
void sub_57f1();
void sub_581f();
void sub_5832();
void sub_584c();
void sub_586b();
void sub_587c();
void sub_58a7();
void sub_5901();
void sub_5970();
void sub_59d8();
void sub_5a41();
void sub_5ab3();
void sub_5b29();
void sub_5c33();
void sub_5d66();
void sub_5dce();
void sub_5efa();
void sub_5f24();
void sub_5f43();
void sub_5fd7();
void sub_6037();
void sub_60b0();
void sub_614e();
void sub_6315();
void sub_638f();
void sub_65c6();
void sub_663d();
void sub_6660();
void sub_668b();
void sub_66b6();
void sub_66e1();
void sub_670c();
void sub_6767();
void sub_67c2();
void sub_681d();
void sub_6878();
void sub_68ba();
void sub_68e8();
void sub_6908();
void sub_697c();
void sub_699a();
void sub_6a43();
void sub_6bb9();
void sub_6bda();
void sub_6c50();
void sub_6d4d();
void sub_6d9c();
void sub_6e76();
void sub_6e89();
void sub_6e9c();
void sub_6ebe();
void sub_6f24();
void sub_6f9a();
void sub_701b();
void sub_703a();
void sub_708b();
void sub_7111();
void sub_7165();
void sub_71c6();
void sub_71ea();
void sub_75bc();
void sub_7690();
void sub_76bc();
void sub_76db();
void sub_770c();
void sub_77a9();
void sub_77c8();
void sub_7810();
void sub_783b();
void sub_7891();
void sub_78e1();
void sub_7912();
void sub_7a1b();
void sub_7a2f();
void sub_7a4e();
void sub_7a60();
void sub_7acd();
void sub_7b2a();
void sub_7b7f();
void sub_7bd4();
void sub_7c29();
void sub_7d6b();
void sub_7fd3();
void sub_801a();
void sub_80ca();
void sub_8211();
void sub_8309();
void sub_8428();
void sub_85ad();
void sub_8664();
void sub_86df();
void sub_8758();
void sub_8877();
void sub_893b();
void sub_8b10();
void sub_8b6a();
void sub_8b75();
void sub_8b80();
void sub_8b8b();
void sub_8bba();
void sub_8c10();
void sub_8ca1();
void sub_8d0f();
void sub_8d2a();
void sub_8d5c();
void sub_8d8e();
void sub_8ed2();
void sub_9043();
void sub_90e2();
void sub_9109();
void sub_914f();
void sub_916e();
void sub_9183();
void sub_91c4();
void sub_92d0();
void sub_92fa();
void sub_9392();
void sub_93b3();
void sub_9430();
void sub_9459();
void sub_9479();
void sub_94d5();
void sub_94de();
void sub_9504();
void sub_953a();
void sub_956a();
void sub_95bc();
void sub_95cf();
void sub_95e5();
void sub_9602();
void sub_9612();
void sub_9634();
void sub_9641();
void sub_964e();
void sub_9668();
void sub_96b0();
void sub_9e04();
void sub_a070();
void sub_b17f();

void sub_1ed0() // 01ed:0000 +entry
{
    ax = 0x0b52;
    ds = ax;
    goto loc_1ed8;
    // gap 1 bytes // gap 1 bytes
loc_1ed8: // 01ed:0008
    sub_54c6();
    sub_51b6();
    memoryASet16(ds, 0x4f88, 0x0001);
    sub_342c();
    sub_8bba();
    sub_3105();
    bx = 0x0bde;
    sub_23b5();
    sub_286b();
    sub_34f3();
    sub_8d2a();
    sub_8d5c();
    sub_586b();
    sub_5901();
    memoryASet(ds, 0x0025, 0x00);
loc_1f0b: // 01ed:003b
    memoryASet(ds, 0x0020, 0x00);
    si = 0x3c5e;
    memoryASet16(ds, si + 12, 0x0001);
    memoryASet16(ds, si + 18, 0x0001);
    memoryASet16(ds, 0x3a54, 0x0240);
    memoryASet16(ds, 0x4f8a, 0x0001);
    memoryASet16(ds, 0x4f8c, 0x0002);
    memoryASet16(ds, 0x4f88, 0x0001);
    memoryASet(ds, 0x0026, 0x00);
    sub_4317();
    memoryASet(ds, 0x0027, 0x00);
    if (!memoryAGet16(ds, 0x4f8a))
        goto loc_1f0b;
    if (memoryAGet16(ds, 0x4f88) == 0xffff)
        goto loc_1f66;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_1f61;
    sub_71ea();
    goto loc_1f0b;
loc_1f61: // 01ed:0091
    sub_1f73();
    goto loc_1f0b;
loc_1f66: // 01ed:0096
    sub_8d0f();
    sub_34ae();
    sub_28b0();
    ah = 0x4c;
    interrupt(0x21);
    stop("terminating");
}
void sub_1f73() // 01ed:00a3
{
    memoryASet16(ds, 0x4f88, 0x0000);
    ax = 0x0000;
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    ax = 0x0001;
    sub_77c8();
    ax = 0x0002;
    sub_77c8();
    memoryASet16(ds, 0x4f6e, 0x7fff);
    memoryASet16(ds, 0x4f92, 0x0000);
    memoryASet(ds, 0x0025, 0x00);
    sub_2fcb();
    sub_2fdd();
    ax = 0x3e54;
    memoryASet16(ds, 0x3a52, ax);
    sub_4f14();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x000d;
    sub_8c10();
    if (!memoryAGet(ds, 0x0026))
        goto loc_1fdc;
    memoryASet16(ds, 0x0010, 0x0004);
    memoryASet16(ds, 0x0012, 0x0000);
    memoryASet16(ds, 0x0014, 0x0001);
    goto loc_2000;
    // gap 1 bytes // gap 1 bytes
loc_1fdc: // 01ed:010c
    sub_377e();
    if (memoryAGet(ds, 0x0025))
        goto loc_1ffd;
    sub_3650();
    if (memoryAGet(ds, 0x0025))
        goto loc_1ffd;
    sub_3522();
    if (memoryAGet(ds, 0x0025))
        goto loc_1ffd;
    goto loc_2000;
    // gap 1 bytes // gap 1 bytes
loc_1ffd: // 01ed:012d
    goto loc_2223;
loc_2000: // 01ed:0130
    memoryASet16(ds, 0x0016, 0x0000);
    si = 0x3c5e;
    memoryASet16(ds, si + 30, 0x0000);
    si = 0x3c7e;
    memoryASet16(ds, si + 30, 0x0000);
    si = 0x3c9e;
    memoryASet16(ds, si + 30, 0x0000);
    si = 0x3cbe;
    memoryASet16(ds, si + 30, 0x0000);
    memoryASet16(ds, 0x3a54, 0x0300);
loc_2030: // 01ed:0160
    sub_3a0c();
    if (memoryAGet(ds, 0x0025))
        goto loc_1ffd;
    memoryASet(ds, 0x0023, 0xff);
    si = 0x002a;
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x37ce, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x37d0, ax);
    sub_5494();
    sub_56de();
    sub_2318();
    sub_5494();
    sub_56de();
    si = 0x3c5e;
    memoryASet16(ds, si, 0xffff);
    memoryASet16(ds, si + 32, 0xffff);
    memoryASet16(ds, si + 64, 0xffff);
    memoryASet16(ds, si + 96, 0xffff);
    si = 0x3c5e;
    bx = 0x0036;
    cx = memoryAGet16(ds, 0x0010);
loc_208b: // 01ed:01bb
    push(cx);
    ax = memoryAGet16(ds, bx);
    sub_57d2();
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 12, 0x0001);
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet16(ds, si + 18, 0x0002);
    memoryASet16(ds, si + 20, 0x0000);
    memoryASet16(ds, si + 22, 0x0002);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    memoryASet16(ds, si + 26, 0x0000);
    memoryASet16(ds, si + 28, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 8, 0x0000);
    bx += 0x0004;
    si += 0x0020;
    cx = pop();
    if (--cx)
        goto loc_208b;
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x0046;
    di = 0x0726;
    cx = 0x00c3;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    sub_50e9();
    if (!memoryAGet(ds, 0x0026))
        goto loc_2113;
    sub_697c();
    memoryASet16(ds, 0x000c, 0x5748);
    sub_58a7();
    if (dx != 0xffff)
        goto loc_2113;
    goto loc_2223;
loc_2113: // 01ed:0243
    sub_4f8b();
    ax = 0x0011;
    di = 0x0000;
    sub_2c81();
    sync();
    if (memoryAGet(ds, 0x0026))
        goto loc_2129;
    sub_699a();
loc_2129: // 01ed:0259
    sub_5a41();
    sub_6a43();
    sub_5494();
    sub_56de();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x0000;
    sub_8c10();
    memoryASet16(ds, 0x000a, 0x0000);
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memoryASet16(ds, 0x3c72, 0x0001);
    memoryASet16(ds, 0x3c92, 0x0001);
    memoryASet16(ds, 0x3cb2, 0x0001);
    memoryASet16(ds, 0x3cd2, 0x0001);
    memoryASet(ds, 0x0023, 0x00);
    memoryASet16(ds, 0x204c, 0x0000);
    memoryASet(ds, 0x0020, 0x00);
loc_2186: // 01ed:02b6
    sub_34f3();
    sub_68ba();
    sub_281e();
    if (memoryAGet(ds, 0x0026))
        goto loc_219b;
    sub_552a();
    goto loc_21cb;
loc_219b: // 01ed:02cb
    ax = 0x25f0;
    es = ax;
    si = memoryAGet16(ds, 0x000c);
    ax = 0x0000;
    al = memoryAGet(es, si);
    if (al == 0xff)
        goto loc_21cb;
    memoryASet16(ds, 0x3c78, ax);
    al = memoryAGet(es, si + 1);
    memoryASet16(ds, 0x3c98, ax);
    al = memoryAGet(es, si + 2);
    memoryASet16(ds, 0x3cb8, ax);
    al = memoryAGet(es, si + 3);
    memoryASet16(ds, 0x3cd8, ax);
    memoryASet16(ds, 0x000c, memoryAGet16(ds, 0x000c) + 0x0004);
loc_21cb: // 01ed:02fb
    sub_5efa();
    sub_638f();
    sub_59d8();
    sub_6315();
    sub_6a43();
    sub_5a41();
    sub_708b();
    sub_56de();
    sub_2282();
    if (dx == 0xffff)
        goto loc_2239;
    if (memoryAGet(ds, 0x0020) != 0x19)
        goto loc_21f5;
    sub_75bc();
loc_21f5: // 01ed:0325
    if (!memoryAGet(ds, 0x0023))
        goto loc_2204;
    memoryASet16(ds, 0x000e, 0xffff);
    goto loc_2239;
loc_2204: // 01ed:0334
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_3503();
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_221a;
    goto loc_2223;
    // gap 1 bytes // gap 1 bytes
loc_221a: // 01ed:034a
    sub_8b8b();
    sub_350c();
    goto loc_2186;
loc_2223: // 01ed:0353
    sub_8b80();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    return;
loc_2239: // 01ed:0369
    sub_8b80();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    if (memoryAGet(ds, 0x0026))
        goto loc_2223;
    sub_3ae1();
    if (memoryAGet(ds, 0x0025))
        goto loc_2223;
    if (memoryAGet16(ds, 0x0016))
        goto loc_227c;
    goto loc_2030;
loc_227c: // 01ed:03ac
    sub_389e();
    goto loc_2000;
}
void sub_2282() // 01ed:03b2
{
    si = 0x3c5e;
    cx = memoryAGet16(ds, 0x0010);
    memoryASet16(ds, 0x000e, 0xffff);
loc_228f: // 01ed:03bf
    push(cx);
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_2313;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_22ac;
    if (memoryAGet16(ds, 0x000e) != 0xffff)
        goto loc_2313;
    ax = memoryAGet16(ds, si + 24);
    memoryASet16(ds, 0x000e, ax);
loc_22ac: // 01ed:03dc
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_228f;
    memoryASet16(ds, 0x3c74, 0x0002);
    memoryASet16(ds, 0x3c94, 0x0002);
    memoryASet16(ds, 0x3cb4, 0x0002);
    memoryASet16(ds, 0x3cd4, 0x0002);
    cx = 0x0008;
    si = 0x3cde;
loc_22d0: // 01ed:0400
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_2307;
    si += 0x0016;
    if (--cx)
        goto loc_22d0;
    memoryASet16(ds, 0x000a, memoryAGet16(ds, 0x000a) + 1);
    if (memoryAGet16(ds, 0x000a) == 0x0002)
        goto loc_2308;
    if (memoryAGet16(ds, 0x000a) == 0x0009)
        goto loc_2308;
    if (memoryAGet16(ds, 0x000a) == 0x0010)
        goto loc_2308;
    if (memoryAGet16(ds, 0x000a) < 0x0012)
        goto loc_2307;
    if (memoryAGet16(ds, 0x000e) == 0xffff)
        goto loc_230f;
    dx = 0xffff;
    return;
loc_2307: // 01ed:0437
    return;
loc_2308: // 01ed:0438
    ax = 0x0003;
    sub_8ca1();
    return;
loc_230f: // 01ed:043f
    dx = 0xffff;
    return;
loc_2313: // 01ed:0443
    cx = pop();
    dx = 0x0000;
}
void sub_2318() // 01ed:0448
{
    ax = memoryAGet16(ds, 0x0018);
    dx = memoryAGet16(ds, 0x001a);
    memoryASet16(ds, 0x0018, dx);
    memoryASet16(ds, 0x001a, ax);
    ax = memoryAGet16(ds, 0x0ede);
    dx = memoryAGet16(ds, 0x0ee0);
    memoryASet16(ds, 0x0ede, dx);
    memoryASet16(ds, 0x0ee0, ax);
    memoryASet(ds, 0x0022, ~memoryAGet(ds, 0x0022));
}
void sub_233a() // 01ed:046a
{
loc_233a: // 01ed:046a
    sub_34f3();
    push(si);
    bx = si;
    sub_23b5();
    si = pop();
    ah = 0x00;
    bx = 0x0000;
    cx = 0x0300;
loc_234c: // 01ed:047c
    al = memoryAGet(ds, bx + si);
    if (memoryAGet(ds, bx + di) <= al)
        goto loc_235c;
    ah = 0xff;
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + 1);
loc_235c: // 01ed:048c
    bx++;
    if (--cx)
        goto loc_234c;
    push(ax);
    sub_3503();
    ax = pop();
    if (ah)
        goto loc_233a;
}
void sub_236a() // 01ed:049a
{
loc_236a: // 01ed:049a
    sub_34f3();
    push(si);
    bx = si;
    sub_23b5();
    si = pop();
    ah = 0x00;
    bx = 0x0000;
    cx = 0x0300;
loc_237c: // 01ed:04ac
    if (!memoryAGet(ds, bx + si))
        goto loc_2389;
    ah = 0xff;
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) - 1);
loc_2389: // 01ed:04b9
    bx++;
    if (--cx)
        goto loc_237c;
    push(ax);
    sub_3503();
    ax = pop();
    if (ah)
        goto loc_236a;
}
void sub_2397() // 01ed:04c7
{
    dx = 0x03c8;
    al = al;
    out8(dx, al);
loc_239d: // 01ed:04cd
    al = lodsb<DS_SI>();
    dx = 0x03c9;
    al = al;
    out8(dx, al);
    al = lodsb<DS_SI>();
    dx = 0x03c9;
    al = al;
    out8(dx, al);
    al = lodsb<DS_SI>();
    dx = 0x03c9;
    al = al;
    out8(dx, al);
    if (--cx)
        goto loc_239d;
}
void sub_23b5() // 01ed:04e5
{
    push(ds);
    dx = 0x03c8;
    al = 0x00;
    out8(dx, al);
    ax = 0x0b52;
    ds = ax;
    si = bx;
    cx = 0x0100;
    dx = 0x03c9;
loc_23c9: // 01ed:04f9
    al = lodsb<DS_SI>();
    out8(dx, al);
    al = lodsb<DS_SI>();
    out8(dx, al);
    al = lodsb<DS_SI>();
    out8(dx, al);
    if (--cx)
        goto loc_23c9;
    ds = pop();
}
void sub_23d3() // 01ed:0503
{
    ax = 0x25f0;
    ds = ax;
    si = 0x0030;
    ax = 0x0b52;
    es = ax;
    cx = 0x0300;
loc_23e3: // 01ed:0513
    al = lodsb<DS_SI>();
    al >>= 1;
    al >>= 1;
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_23e3;
}
void sub_23ec() // 01ed:051c
{
    ax = 0x25f0;
    ds = ax;
    si = 0x0000;
loc_23f4: // 01ed:0524
    si++;
    if (memoryAGet(ds, si) != 0x42)
        goto loc_23f4;
    if (memoryAGet(ds, si + 1) != 0x4f)
        goto loc_23f4;
    if (memoryAGet(ds, si + 2) != 0x44)
        goto loc_23f4;
    if (memoryAGet(ds, si + 3) != 0x59)
        goto loc_23f4;
    si += 0x0008;
loc_2414: // 01ed:0544
    push(cx);
    push(di);
    push(es);
    ax = 0x0b52;
    es = ax;
    di = 0x16c2;
    dx = 0x0000;
loc_2422: // 01ed:0552
    ax = 0x0000;
    al = lodsb<DS_SI>();
    if ((char)al < 0x00)
        goto loc_2434;
    cx = ax;
    cx++;
    dx += cx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    goto loc_243e;
    // gap 1 bytes // gap 1 bytes
loc_2434: // 01ed:0564
    al = -al;
    cx = ax;
    cx++;
    dx += cx;
    al = lodsb<DS_SI>();
    for (; cx != 0; --cx) stosb<ES_DI>(al);
loc_243e: // 01ed:056e
    flags.carry = dx < 0x0140;
    if (flags.carry)
        goto loc_2422;
    es = pop();
    di = pop();
    push(ds);
    push(si);
    ax = 0x0b52;
    ds = ax;
    si = 0x16c2;
    cx = 0x0028;
loc_2453: // 01ed:0583
    push(cx);
    cx = 0x0008;
loc_2457: // 01ed:0587
    al = 0x00;
    memoryASet(ds, si + 280, rcl8(memoryAGet(ds, si + 280), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 240, rcl8(memoryAGet(ds, si + 240), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 200, rcl8(memoryAGet(ds, si + 200), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 160, rcl8(memoryAGet(ds, si + 160), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 120, rcl8(memoryAGet(ds, si + 120), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 80, rcl8(memoryAGet(ds, si + 80), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si + 40, rcl8(memoryAGet(ds, si + 40), 0x01));
    al = rcl8(al, 0x01);
    memoryASet(ds, si, rcl8(memoryAGet(ds, si), 0x01));
    al = rcl8(al, 0x01);
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_2457;
    cx = pop();
    si++;
    if (--cx)
        goto loc_2453;
    si = pop();
    ds = pop();
    cx = pop();
    if (--cx)
        goto loc_2496;
    return;
loc_2496: // 01ed:05c6
    goto loc_2414;
}
void sub_2499() // 01ed:05c9
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
loc_24a9: // 01ed:05d9
    push(cx);
    push(si);
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_24a9;
}
void sub_24dc() // 01ed:060c
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
loc_24ec: // 01ed:061c
    push(cx);
    push(si);
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al += al;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_24ec;
}
void sub_251e() // 01ed:064e
{
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol16(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    ax = pop();
    ah = al;
loc_253b: // 01ed:066b
    push(cx);
    push(si);
    push(di);
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_2545: // 01ed:0675
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_254d;
    memoryASet(es, di, al);
loc_254d: // 01ed:067d
    di++;
    if (--cx)
        goto loc_2545;
    di -= bx;
    if (ah != 0x11)
        goto loc_2558;
    di++;
loc_2558: // 01ed:0688
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_255f: // 01ed:068f
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_2567;
    memoryASet(es, di, al);
loc_2567: // 01ed:0697
    di++;
    if (--cx)
        goto loc_255f;
    di -= bx;
    if (ah != 0x11)
        goto loc_2572;
    di++;
loc_2572: // 01ed:06a2
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_2579: // 01ed:06a9
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_2581;
    memoryASet(es, di, al);
loc_2581: // 01ed:06b1
    di++;
    if (--cx)
        goto loc_2579;
    di -= bx;
    if (ah != 0x11)
        goto loc_258c;
    di++;
loc_258c: // 01ed:06bc
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_2593: // 01ed:06c3
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_259b;
    memoryASet(es, di, al);
loc_259b: // 01ed:06cb
    di++;
    if (--cx)
        goto loc_2593;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_253b;
}
void sub_25ae() // 01ed:06de
{
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol16(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    ax = pop();
    ah = al;
loc_25cb: // 01ed:06fb
    push(cx);
    push(si);
    push(di);
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_25d5: // 01ed:0705
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_25dd;
    memoryASet(es, di, al);
loc_25dd: // 01ed:070d
    di++;
    if (--cx)
        goto loc_25d5;
    di -= bx;
    if (ah != 0x11)
        goto loc_25e8;
    di++;
loc_25e8: // 01ed:0718
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_25ef: // 01ed:071f
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_25f7;
    memoryASet(es, di, al);
loc_25f7: // 01ed:0727
    di++;
    if (--cx)
        goto loc_25ef;
    di -= bx;
    if (ah != 0x11)
        goto loc_2602;
    di++;
loc_2602: // 01ed:0732
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_2609: // 01ed:0739
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_2611;
    memoryASet(es, di, al);
loc_2611: // 01ed:0741
    di++;
    if (--cx)
        goto loc_2609;
    di -= bx;
    if (ah != 0x11)
        goto loc_261c;
    di++;
loc_261c: // 01ed:074c
    al = ah;
    out8(dx, al);
    ah = rol8(ah, 0x01);
    cx = bx;
loc_2623: // 01ed:0753
    al = lodsb<DS_SI>();
    if (al == 0x03)
        goto loc_262b;
    memoryASet(es, di, al);
loc_262b: // 01ed:075b
    di++;
    if (--cx)
        goto loc_2623;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_25cb;
}
void sub_263d() // 01ed:076d
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
loc_264d: // 01ed:077d
    push(cx);
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x02;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x04;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x08;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    di += 0x0080;
    cx = pop();
    if (--cx)
        goto loc_264d;
}
void sub_267a() // 01ed:07aa
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
loc_268a: // 01ed:07ba
    push(cx);
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x02;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x04;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    al = 0x08;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di -= bx;
    di += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_268a;
}
void sub_26b6() // 01ed:07e6
{
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_26fc;
    push(ds);
    bx = dx;
    ax = 0xa000;
    ds = ax;
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03cf;
loc_26ce: // 01ed:07fe
    push(cx);
    push(si);
    al = 0x00;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x02;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x03;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    si += 0x0080;
    cx = pop();
    if (--cx)
        goto loc_26ce;
    ds = pop();
    return;
loc_26fc: // 01ed:082c
    push(ds);
    bx = dx;
    ax = 0xa000;
    ds = ax;
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03cf;
loc_270d: // 01ed:083d
    push(cx);
    push(si);
    al = 0x00;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x01;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x02;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si -= bx;
    al = 0x03;
    out8(dx, al);
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    si += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_270d;
    ds = pop();
}
void sub_273a() // 01ed:086a
{
    push(ds);
    cl = 0x03;
    ax <<= cl;
    si = 0x0ee2;
    si += ax;
    if (si >= 0x1532)
        goto loc_2760;
    dx = memoryAGet16(ds, si + 4);
    cx = memoryAGet16(ds, si + 6);
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_2762;
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    sub_2499();
loc_2760: // 01ed:0890
    ds = pop();
    return;
loc_2762: // 01ed:0892
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    sub_24dc();
    ds = pop();
}
void sub_276b() // 01ed:089b
{
    push(cx);
    cl = 0x04;
    ax <<= cl;
    si = 0x180c;
    si += ax;
    if (si >= 0x203c)
        goto loc_2780;
    cx = pop();
    sub_2782();
    return;
loc_2780: // 01ed:08b0
    cx = pop();
}
void sub_2782() // 01ed:08b2
{
    push(ds);
    ax = dx;
    sub_584c();
    di += memoryAGet16(ds, 0x0018);
    push(ax);
    push(si);
    push(di);
    ax = di;
    dx = memoryAGet16(ds, si + 4);
    dx++;
    cx = memoryAGet16(ds, si + 6);
    bx = si + 8;
    if (memoryAGet(ds, 0x0022))
        goto loc_27a7;
    bx += 0x0004;
loc_27a7: // 01ed:08d7
    di = memoryAGet16(ds, bx); es = memoryAGet16(ds, bx + 2);
    si = ax;
    sub_27d4();
    di = pop();
    si = pop();
    ax = pop();
    dx = memoryAGet16(ds, si + 4);
    cx = memoryAGet16(ds, si + 6);
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_27cb;
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    sub_251e();
    ds = pop();
    return;
loc_27cb: // 01ed:08fb
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    sub_25ae();
    ds = pop();
}
void sub_27d4() // 01ed:0904
{
    bx = memoryAGet16(ds, 0x0ede);
    ax = 0x0014;
loc_27db: // 01ed:090b
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_27e9;
    bx += 0x000a;
    ax--;
    if (ax)
        goto loc_27db;
    return;
loc_27e9: // 01ed:0919
    memoryASet16(ds, bx, si);
    memoryASet16(ds, bx + 2, di);
    memoryASet16(ds, bx + 4, es);
    memoryASet16(ds, bx + 6, dx);
    memoryASet16(ds, bx + 8, cx);
    sub_26b6();
}
void sub_2801() // 01ed:0931
{
    si = 0x1532;
    di = 0x15fa;
    ax = 0xffff;
    cx = 0x0014;
loc_280d: // 01ed:093d
    memoryASet16(ds, si, ax);
    memoryASet16(ds, di, ax);
    si += 0x000a;
    di += 0x000a;
    if (--cx)
        goto loc_280d;
}
void sub_281e() // 01ed:094e
{
    si = memoryAGet16(ds, 0x0ede);
    si += 0x00be;
    ax = 0x0014;
loc_2829: // 01ed:0959
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_2837;
loc_2830: // 01ed:0960
    si -= 0x000a;
    ax--;
    if (ax)
        goto loc_2829;
    return;
loc_2837: // 01ed:0967
    push(ax);
    push(si);
    push(ds);
    di = memoryAGet16(ds, si);
    memoryASet16(ds, si, 0xffff);
    dx = memoryAGet16(ds, si + 6);
    cx = memoryAGet16(ds, si + 8);
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_285f;
    tx = memoryAGet16(ds, si + 2); ds = memoryAGet16(ds, si + 4); si = tx;
    sub_263d();
    ds = pop();
    si = pop();
    ax = pop();
    goto loc_2830;
loc_285f: // 01ed:098f
    tx = memoryAGet16(ds, si + 2); ds = memoryAGet16(ds, si + 4); si = tx;
    sub_267a();
    ds = pop();
    si = pop();
    ax = pop();
    goto loc_2830;
}
void sub_286b() // 01ed:099b
{
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    ax = 0xa000;
    es = ax;
    di = 0x0000;
    cx = 0xfa00;
    ax = 0x0000;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_2888() // 01ed:09b8
{
    push(ax);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    dx = 0xa000;
    es = dx;
    di = 0x0000;
    cx = 0xfa00;
    ax = pop();
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_28b0() // 01ed:09e0
{
    ax = 0x0003;
    interrupt(0x10);
}
void sub_28b6() // 01ed:09e6
{
    push(cx);
    cl = 0x04;
    ax <<= cl;
    si = 0x180c;
    si += ax;
    if (si >= 0x203c)
        goto loc_28cb;
    cx = pop();
    sub_28cd();
    return;
loc_28cb: // 01ed:09fb
    cx = pop();
}
void sub_28cd() // 01ed:09fd
{
    push(ds);
    push(bx);
    ax = dx;
    sub_584c();
    di += memoryAGet16(ds, 0x0018);
    push(ax);
    push(si);
    push(di);
    ax = di;
    dx = memoryAGet16(ds, si + 4);
    dx++;
    cx = memoryAGet16(ds, si + 6);
    bx = si + 8;
    if (memoryAGet(ds, 0x0022))
        goto loc_28f3;
    bx += 0x0004;
loc_28f3: // 01ed:0a23
    di = memoryAGet16(ds, bx); es = memoryAGet16(ds, bx + 2);
    si = ax;
    sub_27d4();
    di = pop();
    si = pop();
    ax = pop();
    dx = memoryAGet16(ds, si + 4);
    cx = memoryAGet16(ds, si + 6);
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_2918;
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    bx = pop();
    sub_29dc();
    ds = pop();
    return;
loc_2918: // 01ed:0a48
    tx = memoryAGet16(ds, si); ds = memoryAGet16(ds, si + 2); si = tx;
    bx = pop();
    sub_2952();
    ds = pop();
}
void sub_2922() // 01ed:0a52
{
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out8(dx, al);
    push(ds);
    ax = 0xa000;
    es = ax;
    ds = ax;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out8(dx, al);
}
void sub_2952() // 01ed:0a82
{
    push(bx);
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol16(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    ax = pop();
    dx = pop();
    ah = dl;
    dx = 0x03c5;
loc_2971: // 01ed:0aa1
    push(cx);
    push(si);
    push(di);
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2979: // 01ed:0aa9
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2981;
    memoryASet(es, di, ah);
loc_2981: // 01ed:0ab1
    si++;
    di++;
    if (--cx)
        goto loc_2979;
    di -= bx;
    if (al != 0x11)
        goto loc_298c;
    di++;
loc_298c: // 01ed:0abc
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2991: // 01ed:0ac1
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2999;
    memoryASet(es, di, ah);
loc_2999: // 01ed:0ac9
    si++;
    di++;
    if (--cx)
        goto loc_2991;
    di -= bx;
    if (al != 0x11)
        goto loc_29a4;
    di++;
loc_29a4: // 01ed:0ad4
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_29a9: // 01ed:0ad9
    if (memoryAGet(ds, si) == 0x03)
        goto loc_29b1;
    memoryASet(es, di, ah);
loc_29b1: // 01ed:0ae1
    si++;
    di++;
    if (--cx)
        goto loc_29a9;
    di -= bx;
    if (al != 0x11)
        goto loc_29bc;
    di++;
loc_29bc: // 01ed:0aec
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_29c1: // 01ed:0af1
    if (memoryAGet(ds, si) == 0x03)
        goto loc_29c9;
    memoryASet(es, di, ah);
loc_29c9: // 01ed:0af9
    si++;
    di++;
    if (--cx)
        goto loc_29c1;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_2971;
}
void sub_29dc() // 01ed:0b0c
{
    push(bx);
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol16(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    ax = pop();
    dx = pop();
    ah = dl;
    dx = 0x03c5;
loc_29fb: // 01ed:0b2b
    push(cx);
    push(si);
    push(di);
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2a03: // 01ed:0b33
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2a0b;
    memoryASet(es, di, ah);
loc_2a0b: // 01ed:0b3b
    si++;
    di++;
    if (--cx)
        goto loc_2a03;
    di -= bx;
    if (al != 0x11)
        goto loc_2a16;
    di++;
loc_2a16: // 01ed:0b46
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2a1b: // 01ed:0b4b
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2a23;
    memoryASet(es, di, ah);
loc_2a23: // 01ed:0b53
    si++;
    di++;
    if (--cx)
        goto loc_2a1b;
    di -= bx;
    if (al != 0x11)
        goto loc_2a2e;
    di++;
loc_2a2e: // 01ed:0b5e
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2a33: // 01ed:0b63
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2a3b;
    memoryASet(es, di, ah);
loc_2a3b: // 01ed:0b6b
    si++;
    di++;
    if (--cx)
        goto loc_2a33;
    di -= bx;
    if (al != 0x11)
        goto loc_2a46;
    di++;
loc_2a46: // 01ed:0b76
    out8(dx, al);
    al = rol8(al, 0x01);
    cx = bx;
loc_2a4b: // 01ed:0b7b
    if (memoryAGet(ds, si) == 0x03)
        goto loc_2a53;
    memoryASet(es, di, ah);
loc_2a53: // 01ed:0b83
    si++;
    di++;
    if (--cx)
        goto loc_2a4b;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_29fb;
}
void sub_2a67() // 01ed:0b97
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_2aa5;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_2a76;
    return;
loc_2a76: // 01ed:0ba6
    push(ds);
    di = memoryAGet16(ds, 0x0018);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_24dc();
    ds = pop();
    push(ds);
    di = memoryAGet16(ds, 0x001a);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_24dc();
    ds = pop();
    return;
loc_2aa5: // 01ed:0bd5
    push(ds);
    di = memoryAGet16(ds, 0x0018);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_2499();
    ds = pop();
    push(ds);
    di = memoryAGet16(ds, 0x001a);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_2499();
    ds = pop();
}
void sub_2ad4() // 01ed:0c04
{
    ax = memoryAGet16(ds, 0x203e);
    if (ax == memoryAGet16(ds, 0x1802))
        goto loc_2aef;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_2af2;
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_2aee;
    goto loc_2b7e;
loc_2aee: // 01ed:0c1e
    return;
loc_2aef: // 01ed:0c1f
    memoryASet16(ds, 0x1802, ax);
loc_2af2: // 01ed:0c22
    push(ds);
    cx = memoryAGet16(ds, 0x203e);
    cl &= 0x03;
    al = 0x11;
    al = rol8(al, cl);
    push(ax);
    ax = memoryAGet16(ds, 0x203e);
    ax -= 0x0080;
    ax >>= 1;
    ax >>= 1;
    di = ax;
    di += memoryAGet16(ds, 0x0018);
    ax = 0xa000;
    es = ax;
    ds = ax;
    si = 0xfa00;
    ax = pop();
    bx = ax;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = bl;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x00;
    out8(dx, al);
    sub_2c4d();
    bl = rol8(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b3f;
    di++;
loc_2b3f: // 01ed:0c6f
    dx = 0x03c5;
    al = bl;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x01;
    out8(dx, al);
    sub_2c4d();
    bl = rol8(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b56;
    di++;
loc_2b56: // 01ed:0c86
    dx = 0x03c5;
    al = bl;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x02;
    out8(dx, al);
    sub_2c4d();
    bl = rol8(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b6d;
    di++;
loc_2b6d: // 01ed:0c9d
    dx = 0x03c5;
    al = bl;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x03;
    out8(dx, al);
    sub_2c4d();
    ds = pop();
    return;
loc_2b7e: // 01ed:0cae
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out8(dx, al);
    si = 0x1808;
    if (!memoryAGet(ds, 0x0022))
        goto loc_2ba3;
    si = 0x1804;
loc_2ba3: // 01ed:0cd3
    ax = 0xa000;
    es = ax;
    ax = memoryAGet16(ds, 0x203e);
    ax -= 0x0080;
    cl = 0x06;
    ax <<= cl;
    di = ax;
    di += memoryAGet16(ds, 0x0018);
    push(ds);
    push(di);
    memoryASet16(ds, si, di);
    ax = memoryAGet16(ds, si + 2);
    si = di;
    di = ax;
    ax = 0xa000;
    ds = ax;
    es = ax;
    cx = 0x0600;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di = pop();
    ds = pop();
    push(ds);
    flags.direction = 1;
    si = memoryAGet16(ds, 0x0018);
    si += 0x05ff;
    di += 0x05ff;
    ax = 0xa000;
    ds = ax;
    cx = 0x0600;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    flags.direction = 0;
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out8(dx, al);
}
void sub_2bfb() // 01ed:0d2b
{
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_2c4c;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out8(dx, al);
    si = 0x1808;
    if (!memoryAGet(ds, 0x0022))
        goto loc_2c27;
    si = 0x1804;
loc_2c27: // 01ed:0d57
    ax = 0xa000;
    es = ax;
    push(ds);
    push(si);
    ax = lodsw<DS_SI>();
    di = ax;
    ax = lodsw<DS_SI>();
    si = ax;
    ax = 0xa000;
    ds = ax;
    cx = 0x0600;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out8(dx, al);
loc_2c4c: // 01ed:0d7c
    return;
}
void sub_2c4d() // 01ed:0d7d
{
    cx = 0x0018;
loc_2c50: // 01ed:0d80
    push(cx);
    cx = 0x0040;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_2c50;
    si -= 0x0600;
    di -= 0x0c00;
}
void sub_2c65() // 01ed:0d95
{
    push(ds);
    ax = 0xa000;
    es = ax;
    ax = 0x42fd;
    ds = ax;
    si = 0xb908;
    di = 0xfa00;
    cx = 0x0018;
    dx = 0x0040;
    sub_24dc();
    ds = pop();
}
void sub_2c81() // 01ed:0db1
{
    push(ax);
    push(di);
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    di = pop();
    ax = pop();
    di += memoryAGet16(ds, 0x001a);
    sub_273a();
}
void sub_2c94() // 01ed:0dc4
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    di += memoryAGet16(ds, 0x0018);
    sub_2cb3();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di += memoryAGet16(ds, 0x001a);
    sub_2cb3();
}
void sub_2cb3() // 01ed:0de3
{
    push(ax);
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out8(dx, al);
    ax = 0xa000;
    es = ax;
    dx = pop();
    ax = pop();
loc_2cc8: // 01ed:0df8
    push(cx);
    push(di);
    cx = dx;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    di = pop();
    cx = pop();
    di += 0x0040;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_2cdd;
    di += 0x0040;
loc_2cdd: // 01ed:0e0d
    if (--cx)
        goto loc_2cc8;
}
void sub_2ce0() // 01ed:0e10
{
loc_2ce0: // 01ed:0e10
    push(cx);
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_2cf3;
    di = ax;
    ax = lodsw<DS_SI>();
    push(si);
    sub_2c81();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_2ce0;
    return;
loc_2cf3: // 01ed:0e23
    cx = pop();
}
void sub_2cf6() // 01ed:0e26
{
    si = 0x30e5;
    di = 0x2117;
    bx = 0x0000;
loc_2cff: // 01ed:0e2f
    al = lodsb<DS_SI>();
    sub_2e42();
    if ((char)al < 0x00)
        goto loc_2d5b;
    al &= 0x0f;
    memoryASet(ds, di, al);
    al = lodsb<DS_SI>();
    sub_2e42();
    if ((char)al < 0x00)
        goto loc_2d5b;
    cl = 0x04;
    al <<= cl;
    memoryASet(ds, di, memoryAGet(ds, di) | al);
    di++;
    bx++;
    if (bx != 0x0004)
        goto loc_2cff;
    si = 0x2117;
    al = memoryAGet(ds, si);
    al &= 0xe0;
    bx = 0x0003;
loc_2d30: // 01ed:0e60
    flags.carry = 0;
    al = rcl8(al, 0x01);
    if (!flags.carry)
        goto loc_2d39;
    memoryASet(ds, bx + si, ~memoryAGet(ds, bx + si));
loc_2d39: // 01ed:0e69
    bx--;
    if (bx)
        goto loc_2d30;
    al = memoryAGet(ds, si);
    al &= 0x18;
    if (al != 0x10)
        goto loc_2d5b;
    memoryASet16(ds, 0x2162, 0x0000);
    al = memoryAGet(ds, si);
    al &= 0x07;
    sub_2e19();
    goto loc_2d5e;
    // gap 1 bytes // gap 1 bytes
loc_2d5b: // 01ed:0e8b
    goto loc_2de3;
loc_2d5e: // 01ed:0e8e
    si = 0x20a3;
    di = 0x20b9;
    dx = 0x0004;
    sub_2de7();
    if (!ax)
        goto loc_2d5b;
    if (ax > 0x0008)
        goto loc_2d5b;
    memoryASet16(ds, 0x4f88, ax);
    si = 0x20a7;
    di = 0x20bd;
    dx = 0x0004;
    sub_2de7();
    if (!ax)
        goto loc_2d5b;
    if (ax > 0x0008)
        goto loc_2de3;
    memoryASet16(ds, 0x4f8a, ax);
    si = 0x20ab;
    di = 0x20c1;
    dx = 0x0004;
    sub_2de7();
    memoryASet16(ds, 0x3c6a, ax);
    si = 0x20af;
    di = 0x20c5;
    dx = 0x0004;
    sub_2de7();
    memoryASet16(ds, 0x3c70, ax);
    si = 0x20b3;
    di = 0x20c9;
    dx = 0x0001;
    sub_2de7();
    memoryASet16(ds, 0x3a54, 0x0300);
    if (ax != 0x0001)
        goto loc_2dcb;
    memoryASet16(ds, 0x3a54, 0x03c0);
loc_2dcb: // 01ed:0efb
    ax = memoryAGet16(ds, 0x2162);
    si = 0x20b4;
    di = 0x20ca;
    dx = 0x0001;
    sub_2de7();
    if (ax)
        goto loc_2de3;
    dx = 0x0000;
    return;
loc_2de3: // 01ed:0f13
    dx = 0xffff;
}
void sub_2de7() // 01ed:0f17
{
    bx = 0x0000;
    ah = 0x00;
loc_2dec: // 01ed:0f1c
    push(bx);
    bl = memoryAGet(ds, bx + di);
    bx &= 0x0003;
    bx += 0x2117;
    al = memoryAGet(ds, bx);
    bx = pop();
    ah <<= 1;
    al &= memoryAGet(ds, bx + si);
    if (!al)
        goto loc_2e0e;
    memoryASet16(ds, 0x2162, memoryAGet16(ds, 0x2162) + 1);
    ah |= 0x01;
loc_2e0e: // 01ed:0f3e
    bx++;
    if (bx != dx)
        goto loc_2dec;
    al = ah;
    ax &= 0x00ff;
}
void sub_2e19() // 01ed:0f49
{
    bx = 0x2117;
    memoryASet(ds, 0x2164, al);
    cx = 0x0000;
loc_2e22: // 01ed:0f52
    if (memoryAGet(ds, 0x2164) == cl)
        goto loc_2e41;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    flags.carry = 0;
    dx = rcr16(dx, 0x0001);
    ax = rcr16(ax, 0x0001);
    memoryASet16(ds, bx + 2, dx);
    memoryASet(ds, bx + 1, ah);
    cl++;
    goto loc_2e22;
loc_2e41: // 01ed:0f71
    return;
}
void sub_2e42() // 01ed:0f72
{
    push(bx);
    bx &= 0x0003;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += bx;
    cx = 0x0010;
loc_2e51: // 01ed:0f81
    push(bx);
    bx += 0x20cf;
    ah = memoryAGet(ds, bx);
    bx = pop();
    if (ah == al)
        goto loc_2e68;
    cx--;
    if (!cx)
        goto loc_2e6e;
    bx++;
    goto loc_2e51;
loc_2e68: // 01ed:0f98
    al = 0x10;
    al -= cl;
    bx = pop();
    return;
loc_2e6e: // 01ed:0f9e
    al = 0xff;
    bx = pop();
}
void sub_2e72() // 01ed:0fa2
{
    si = 0x2117;
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 2, 0x0000);
    memoryASet16(ds, 0x2162, 0x0000);
    ax = memoryAGet16(ds, 0x4f88);
    si = 0x20a3;
    di = 0x20b9;
    bx = 0x0004;
    sub_2fa7();
    ax = memoryAGet16(ds, 0x4f8a);
    si = 0x20a7;
    di = 0x20bd;
    bx = 0x0004;
    sub_2fa7();
    ax = memoryAGet16(ds, 0x3c6a);
    si = 0x20ab;
    di = 0x20c1;
    bx = 0x0004;
    sub_2fa7();
    ax = memoryAGet16(ds, 0x3c70);
    si = 0x20af;
    di = 0x20c5;
    bx = 0x0004;
    sub_2fa7();
    ax = 0x0000;
    if (memoryAGet16(ds, 0x3a54) != 0x03c0)
        goto loc_2ed1;
    ax = 0x0001;
loc_2ed1: // 01ed:1001
    si = 0x20b3;
    di = 0x20c9;
    bx = 0x0001;
    sub_2fa7();
    ax = memoryAGet16(ds, 0x2162);
    si = 0x20b4;
    di = 0x20ca;
    bx = 0x0005;
    sub_2fa7();
    ax = 0x0002;
    sub_587c();
    memoryASet(ds, 0x2117, al);
    sub_2f7e();
    ax = 0x0008;
    sub_587c();
    dx = ax;
    cl = 0x05;
    al <<= cl;
    al |= 0x10;
    memoryASet(ds, 0x2117, memoryAGet(ds, 0x2117) | al);
    di = 0x30e5;
    memoryASet(ds, 0x2164, 0x00);
    al = memoryAGet(ds, 0x2117);
    sub_2f35();
    al = memoryAGet(ds, 0x2118);
    sub_2f2c();
    al = memoryAGet(ds, 0x2119);
    sub_2f2c();
    al = memoryAGet(ds, 0x211a);
    sub_2f2c();
}
void sub_2f2c() // 01ed:105c
{
    flags.carry = dx & 1;
    dx = ror16(dx, 0x0001);
    if (!flags.carry)
        goto loc_2f35;
    al ^= 0xff;
    goto loc_2f35;
    // gap 1 bytes // gap 1 bytes
loc_2f35: // 01ed:1065
    push(dx);
    dh = al;
    al &= 0x0f;
    dl = al;
    al = memoryAGet(ds, 0x2164);
    cl = 0x04;
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memoryAGet(ds, bx);
    memoryASet(ds, di, al);
    di++;
    al = dh;
    al &= 0xf0;
    al >>= cl;
    dl = al;
    al = memoryAGet(ds, 0x2164);
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memoryAGet(ds, bx);
    memoryASet(ds, di, al);
    di++;
    memoryASet(ds, 0x2164, memoryAGet(ds, 0x2164) + 1);
    dx = pop();
}
void sub_2f35() // 01ed:1065
{
    push(dx);
    dh = al;
    al &= 0x0f;
    dl = al;
    al = memoryAGet(ds, 0x2164);
    cl = 0x04;
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memoryAGet(ds, bx);
    memoryASet(ds, di, al);
    di++;
    al = dh;
    al &= 0xf0;
    al >>= cl;
    dl = al;
    al = memoryAGet(ds, 0x2164);
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memoryAGet(ds, bx);
    memoryASet(ds, di, al);
    di++;
    memoryASet(ds, 0x2164, memoryAGet(ds, 0x2164) + 1);
    dx = pop();
}
void sub_2f7e() // 01ed:10ae
{
    bx = 0x2117;
    memoryASet(ds, 0x2164, al);
    cx = 0x0000;
loc_2f87: // 01ed:10b7
    if (memoryAGet(ds, 0x2164) == cl)
        goto loc_2fa6;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    flags.carry = 0;
    ax = rcl16(ax, 0x0001);
    dx = rcl16(dx, 0x0001);
    memoryASet16(ds, bx + 2, dx);
    memoryASet(ds, bx + 1, ah);
    cl++;
    goto loc_2f87;
loc_2fa6: // 01ed:10d6
    return;
}
void sub_2fa7() // 01ed:10d7
{
    bx--;
loc_2fa8: // 01ed:10d8
    flags.carry = ax & 1;
    ax = ror16(ax, 0x0001);
    if (!flags.carry)
        goto loc_2fc4;
    memoryASet16(ds, 0x2162, memoryAGet16(ds, 0x2162) + 1);
    push(bx);
    dl = memoryAGet(ds, bx + si);
    bl = memoryAGet(ds, bx + di);
    bh = 0x00;
    bx += 0x2117;
    memoryASet(ds, bx, memoryAGet(ds, bx) | dl);
    bx = pop();
loc_2fc4: // 01ed:10f4
    bx--;
    if (bx != 0xffff)
        goto loc_2fa8;
}
void sub_2fcb() // 01ed:10fb
{
    si = 0x3cde;
    cx = 0x0058;
loc_2fd1: // 01ed:1101
    memoryASet16(ds, si, 0xffff);
    si += 0x0002;
    if (--cx)
        goto loc_2fd1;
}
void sub_2fdd() // 01ed:110d
{
    si = 0x3d8e;
    cx = 0x0028;
loc_2fe3: // 01ed:1113
    memoryASet16(ds, si, 0xffff);
    si += 0x0002;
    if (--cx)
        goto loc_2fe3;
}
void sub_2fef() // 01ed:111f
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_3032;
    if ((short)memoryAGet16(ds, 0x3c68) < 0x0000)
        goto loc_3032;
    if (memoryAGet16(ds, 0x3c5e) == 0xffff)
        goto loc_3032;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_3033;
    si = 0x3c5e;
    bx = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x203e, bx);
    if (memoryAGet16(ds, 0x203e) <= 0x0180)
        goto loc_3024;
    memoryASet16(ds, 0x203e, 0x0180);
loc_3024: // 01ed:1154
    if (memoryAGet16(ds, 0x203e) >= 0x0080)
        goto loc_3032;
    memoryASet16(ds, 0x203e, 0x0080);
loc_3032: // 01ed:1162
    return;
loc_3033: // 01ed:1163
    si = 0x3c5e;
    bx = memoryAGet16(ds, si);
    memoryASet16(ds, 0x203e, bx);
    if (memoryAGet16(ds, 0x203e) <= 0x0180)
        goto loc_304c;
    memoryASet16(ds, 0x203e, 0x0180);
loc_304c: // 01ed:117c
    if (memoryAGet16(ds, 0x203e) >= 0x0080)
        goto loc_305a;
    memoryASet16(ds, 0x203e, 0x0080);
loc_305a: // 01ed:118a
    return;
}
void sub_305b() // 01ed:118b
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_3090;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_30ab;
    bx = memoryAGet16(ds, 0x203e);
    bx -= 0x0080;
    cl = 0x06;
    bx <<= cl;
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx = 0x03d5;
    al = bh;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out8(dx, al);
    dx = 0x03d5;
    al = bl;
    out8(dx, al);
    return;
loc_3090: // 01ed:11c0
    bx = ax;
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx = 0x03d5;
    al = bh;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out8(dx, al);
    dx = 0x03d5;
    al = bl;
    out8(dx, al);
    return;
loc_30ab: // 01ed:11db
    push(ax);
    bx = memoryAGet16(ds, 0x203e);
    bx -= 0x0080;
    bx >>= 1;
    bx >>= 1;
    ax = pop();
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx = 0x03d5;
    al = bh;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out8(dx, al);
    dx = 0x03d5;
    al = bl;
    out8(dx, al);
}
void sub_30d4() // 01ed:1204
{
    if (memoryAGet16(ds, 0x26f2) != 0x0001)
        goto loc_3104;
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c0;
    al = 0x13;
    out8(dx, al);
    ax = memoryAGet16(ds, 0x203e);
    ax &= 0x0003;
    if (memoryAGet(ds, 0x0024) == 0x01)
        goto loc_30f4;
    al += al;
loc_30f4: // 01ed:1224
    dx = 0x03c0;
    al = al;
    out8(dx, al);
    dx = 0x03c0;
    al = 0x20;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
loc_3104: // 01ed:1234
    return;
}
void sub_3105() // 01ed:1235
{
    ax = 0x0012;
    interrupt(0x10);
    dx = 0x03d4;
    al = 0x11;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al &= 0x7f;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    si = 0x2075;
    bx = 0x0000;
    cx = 0x0018;
loc_3125: // 01ed:1255
    dx = 0x03d4;
    al = bl;
    out8(dx, al);
    al = lodsb<DS_SI>();
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    bl++;
    if (--cx)
        goto loc_3125;
    dx = 0x03da;
    al = in8(dx);
    si = 0x208e;
    bx = 0x0000;
    cx = 0x0014;
loc_3143: // 01ed:1273
    dx = 0x03c0;
    al = bl;
    out8(dx, al);
    al = lodsb<DS_SI>();
    dx = 0x03c0;
    al = al;
    out8(dx, al);
    bl++;
    if (--cx)
        goto loc_3143;
    dx = 0x03c0;
    al = 0x20;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c4;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c5;
    al = in8(dx);
    al &= 0xf7;
    dx = 0x03c5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x14;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al &= 0xbf;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x17;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al |= 0x40;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x03;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x82;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x01;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x3f;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x04;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x4c;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x06;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x0b;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x10;
    out8(dx, al);
    dx = 0x03d5;
    al = 0xe2;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x11;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x0c;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x15;
    out8(dx, al);
    dx = 0x03d5;
    al = 0xe7;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x07;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x3e;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x41;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x12;
    out8(dx, al);
    dx = 0x03d5;
    al = 0xcf;
    out8(dx, al);
}
void sub_3225() // 01ed:1355
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    dx = 0x0b52;
    ds = dx;
    memoryASet(ds, 0x204f, 0xff);
    memoryASet16(ds, 0x001c, memoryAGet16(ds, 0x001c) + 1);
    if (memoryAGet(ds, 0x0023))
        goto loc_3287;
    memoryASet16(ds, 0x204c, memoryAGet16(ds, 0x204c) + 1);
    if (memoryAGet16(ds, 0x204c) != 0x0012)
        goto loc_3287;
    memoryASet16(ds, 0x204c, 0x0000);
    dx = memoryAGet16(ds, 0x37ce);
    ax = memoryAGet16(ds, 0x37d0);
    ax--;
    if ((short)ax >= 0x0000)
        goto loc_3280;
    ax = 0x003b;
    dx = memoryAGet16(ds, 0x37ce);
    dx--;
    if ((short)dx >= 0x0000)
        goto loc_3280;
    ax = 0x0000;
    dx = 0x0000;
    memoryASet16(ds, 0x204c, 0xffff);
    memoryASet(ds, 0x0023, 0xff);
loc_3280: // 01ed:13b0
    memoryASet16(ds, 0x37ce, dx);
    memoryASet16(ds, 0x37d0, ax);
loc_3287: // 01ed:13b7
    si = memoryAGet16(ds, 0x704c);
    if (!si)
        goto loc_32b7;
    ax = lodsw<DS_SI>();
    if (!ax)
        goto loc_32ab;
    bx = ax;
    al = 0xb6;
    out8(0x43, al);
    ax = bx;
    out8(0x42, al);
    al = ah;
    out8(0x42, al);
    memoryASet16(ds, 0x704c, si);
    goto loc_32b7;
    // gap 1 bytes // gap 1 bytes
loc_32ab: // 01ed:13db
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
    memoryASet16(ds, 0x704c, 0x0000);
loc_32b7: // 01ed:13e7
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return; // was: goto loc_32c8 (chain to original INT 0x1c)
}
void sub_32e0() // 01ed:1410
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    dx = 0x0b52;
    ds = dx;
    dx = 0x0060;
    al = in8(dx);
    ah = 0x00;
    if ((char)al < 0x00)
        goto loc_3344;
    si = memoryAGet16(ds, 0x203c);
    if (memoryAGet(ds, si) != al)
        goto loc_333e;
    si++;
    if (memoryAGet(ds, si) != 0xff)
        goto loc_3337;
    memoryASet(ds, 0x2050, 0xff);
    memoryASet16(ds, 0x3c6a, 0x0008);
    memoryASet16(ds, 0x3c70, 0x0008);
    memoryASet16(ds, 0x3a54, 0x03c0);
    push(ax);
    al = memoryAGet(ds, 0x4f99);
    push(ax);
    memoryASet(ds, 0x4f99, 0x00);
    ax = 0x0001;
    sub_8ca1();
    ax = pop();
    memoryASet(ds, 0x4f99, al);
    ax = pop();
loc_3337: // 01ed:1467
    memoryASet16(ds, 0x203c, si);
    goto loc_3344;
    // gap 1 bytes // gap 1 bytes
loc_333e: // 01ed:146e
    memoryASet16(ds, 0x203c, 0x2052);
loc_3344: // 01ed:1474
    memoryASet(ds, 0x0020, al);
    bh = memoryAGet(ds, 0x37f7);
    si = 0x205d;
    sub_33d1();
    if (al != memoryAGet(ds, si + 11))
        goto loc_335d;
    memoryASet(ds, 0x204e, 0xff);
loc_335d: // 01ed:148d
    memoryASet(ds, 0x37f7, bh);
    bh = memoryAGet(ds, 0x37f8);
    si = 0x2069;
    sub_33d1();
    memoryASet(ds, 0x37f8, bh);
    if (memoryAGet(ds, 0x0020) != 0x32)
        goto loc_338f;
    memoryASet(ds, 0x4f98, ~memoryAGet(ds, 0x4f98));
    memoryASet(ds, 0x0020, 0x00);
    if (!memoryAGet(ds, 0x4f98))
        goto loc_338c;
    sub_8b75();
    goto loc_338f;
    // gap 1 bytes // gap 1 bytes
loc_338c: // 01ed:14bc
    sub_8b6a();
loc_338f: // 01ed:14bf
    if (memoryAGet(ds, 0x0020) != 0x1f)
        goto loc_339f;
    memoryASet(ds, 0x4f99, ~memoryAGet(ds, 0x4f99));
    memoryASet(ds, 0x0020, 0x00);
loc_339f: // 01ed:14cf
    ah = 0x0c;
    al = 0x00;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return; // was: goto loc_33b6 (chain to original INT 0x09)
}
void sub_33d1() // 01ed:1501
{
    if (al != memoryAGet(ds, si + 1))
        goto loc_33da;
    bh |= 0x01;
loc_33da: // 01ed:150a
    if (al != memoryAGet(ds, si + 3))
        goto loc_33e3;
    bh |= 0x02;
loc_33e3: // 01ed:1513
    if (al != memoryAGet(ds, si + 5))
        goto loc_33ec;
    bh |= 0x04;
loc_33ec: // 01ed:151c
    if (al != memoryAGet(ds, si + 7))
        goto loc_33f5;
    bh |= 0x08;
loc_33f5: // 01ed:1525
    if (al != memoryAGet(ds, si + 9))
        goto loc_33fe;
    bh |= 0x10;
loc_33fe: // 01ed:152e
    if (al != memoryAGet(ds, si))
        goto loc_3407;
    bh &= 0xfe;
loc_3407: // 01ed:1537
    if (al != memoryAGet(ds, si + 2))
        goto loc_3410;
    bh &= 0xfd;
loc_3410: // 01ed:1540
    if (al != memoryAGet(ds, si + 4))
        goto loc_3419;
    bh &= 0xfb;
loc_3419: // 01ed:1549
    if (al != memoryAGet(ds, si + 6))
        goto loc_3422;
    bh &= 0xf7;
loc_3422: // 01ed:1552
    if (al != memoryAGet(ds, si + 8))
        goto loc_342b;
    bh &= 0xef;
loc_342b: // 01ed:155b
    return;
}
void sub_342c() // 01ed:155c
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    ax = 0x351c;
    interrupt(0x21);
    memoryASet16(ds, 0x2042, es);
    memoryASet16(ds, 0x2040, bx);
    dx = es;
    ax = 0x01ed;
    es = ax;
    si = 0x13f0;
    memoryASet16(es, si, bx);
    memoryASet16(es, si + 2, dx);
    ax = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x2046, es);
    memoryASet16(ds, 0x2044, bx);
    dx = es;
    ax = 0x01ed;
    es = ax;
    si = 0x14de;
    memoryASet16(es, si, bx);
    memoryASet16(es, si + 2, dx);
    ax = 0x351b;
    interrupt(0x21);
    memoryASet16(ds, 0x204a, es);
    memoryASet16(ds, 0x2048, bx);
    ax = 0x01ed;
    ds = ax;
    dx = 0x1355;
    ax = 0x251c;
    interrupt(0x21);
    ax = 0x01ed;
    ds = ax;
    dx = 0x1410;
    ax = 0x2509;
    interrupt(0x21);
    ax = 0x01ed;
    ds = ax;
    dx = 0x15dd;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_34ad() // 01ed:15dd
{
    stop("iret"); return;
}
void sub_34ae() // 01ed:15de
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    dx = memoryAGet16(ds, 0x2040);
    ax = memoryAGet16(ds, 0x2042);
    ds = ax;
    ax = 0x251c;
    interrupt(0x21);
    ax = 0x0b52;
    ds = ax;
    dx = memoryAGet16(ds, 0x2044);
    ax = memoryAGet16(ds, 0x2046);
    ds = ax;
    ax = 0x2509;
    interrupt(0x21);
    ax = 0x0b52;
    ds = ax;
    dx = memoryAGet16(ds, 0x2048);
    ax = memoryAGet16(ds, 0x204a);
    ds = ax;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_34f3() // 01ed:1623
{
    push(ds);
    ax = 0x0b52;
    ds = ax;
    dx = 0x03da;
loc_34fc: // 01ed:162c
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_34fc;
    ds = pop();
}
void sub_3503() // 01ed:1633
{
    dx = 0x03da;
loc_3506: // 01ed:1636
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_3506;
}
void sub_350c() // 01ed:163c
{
    sync();
    return;
    if (memoryAGet(ds, 0x204f))
        goto loc_351a;
loc_3513: // 01ed:1643
    sync();
    if (!memoryAGet(ds, 0x204f))
        goto loc_3513;
loc_351a: // 01ed:164a
    memoryASet(ds, 0x204f, 0x00);
}
void sub_3522() // 01ed:1652
{
    al = 0x48;
    sub_2888();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x0603;
    dx = 0x001c;
    cx = 0x0018;
    sub_3fa2();
    si = 0x23ba;
    sub_53d1();
    si = 0x26b0;
    cx = 0x000a;
    sub_2ce0();
    ax = memoryAGet16(ds, 0x0014);
    ax--;
    si = 0x26d8;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_357c: // 01ed:16ac
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_358b;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_3636;
loc_358b: // 01ed:16bb
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al)
        goto loc_35fa;
    al = ah;
    al &= 0x03;
    if (!al)
        goto loc_35ef;
    if (memoryAGet(ds, 0x236c))
        goto loc_357c;
    al = ah;
    al &= 0x01;
    if (!al)
        goto loc_35c2;
    memoryASet(ds, 0x236c, 0xff);
    if (memoryAGet16(ds, 0x0014) != 0x0001)
        goto loc_35bc;
    memoryASet16(ds, 0x0014, 0x0005);
    goto loc_35e1;
loc_35bc: // 01ed:16ec
    memoryASet16(ds, 0x0014, memoryAGet16(ds, 0x0014) - 1);
    goto loc_35e1;
loc_35c2: // 01ed:16f2
    al = ah;
    al &= 0x02;
    if (!al)
        goto loc_35e1;
    memoryASet(ds, 0x236c, 0xff);
    if (memoryAGet16(ds, 0x0014) != 0x0005)
        goto loc_35dd;
    memoryASet16(ds, 0x0014, 0x0001);
    goto loc_35e1;
loc_35dd: // 01ed:170d
    memoryASet16(ds, 0x0014, memoryAGet16(ds, 0x0014) + 1);
loc_35e1: // 01ed:1711
    ax = memoryAGet16(ds, 0x0014);
    ax--;
    si = 0x26d8;
    sub_3de6();
    goto loc_357c;
loc_35ef: // 01ed:171f
    memoryASet(ds, 0x236c, 0x00);
    sub_8b8b();
    goto loc_357c;
loc_35fa: // 01ed:172a
    si = 0x26b0;
    ax = memoryAGet16(ds, 0x0014);
    ax--;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_360e: // 01ed:173e
    push(cx);
    push(si);
    ax = lodsw<DS_SI>();
    di = ax;
    dx = 0x001d;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_360e;
loc_3636: // 01ed:1766
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_3650() // 01ed:1780
{
    al = 0x48;
    sub_2888();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x2f03;
    dx = 0x001c;
    cx = 0x000d;
    sub_3fa2();
    si = 0x23a4;
    sub_53d1();
    si = 0x2690;
    cx = 0x0006;
    sub_2ce0();
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    si = 0x26a8;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_36aa: // 01ed:17da
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_36b9;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_3764;
loc_36b9: // 01ed:17e9
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al)
        goto loc_3728;
    al = ah;
    al &= 0x03;
    if (!al)
        goto loc_371d;
    if (memoryAGet(ds, 0x236c))
        goto loc_36aa;
    al = ah;
    al &= 0x01;
    if (!al)
        goto loc_36f0;
    memoryASet(ds, 0x236c, 0xff);
    if (memoryAGet16(ds, 0x0010) != 0x0002)
        goto loc_36ea;
    memoryASet16(ds, 0x0010, 0x0004);
    goto loc_370f;
loc_36ea: // 01ed:181a
    memoryASet16(ds, 0x0010, memoryAGet16(ds, 0x0010) - 1);
    goto loc_370f;
loc_36f0: // 01ed:1820
    al = ah;
    al &= 0x02;
    if (!al)
        goto loc_370f;
    memoryASet(ds, 0x236c, 0xff);
    if (memoryAGet16(ds, 0x0010) != 0x0004)
        goto loc_370b;
    memoryASet16(ds, 0x0010, 0x0002);
    goto loc_370f;
loc_370b: // 01ed:183b
    memoryASet16(ds, 0x0010, memoryAGet16(ds, 0x0010) + 1);
loc_370f: // 01ed:183f
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    si = 0x26a8;
    sub_3de6();
    goto loc_36aa;
loc_371d: // 01ed:184d
    memoryASet(ds, 0x236c, 0x00);
    sub_8b8b();
    goto loc_36aa;
loc_3728: // 01ed:1858
    si = 0x2690;
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_373c: // 01ed:186c
    push(cx);
    push(si);
    ax = lodsw<DS_SI>();
    di = ax;
    dx = 0x0029;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_373c;
loc_3764: // 01ed:1894
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_377e() // 01ed:18ae
{
    al = 0x48;
    sub_2888();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x2e05;
    dx = 0x001a;
    cx = 0x000c;
    sub_3fa2();
    si = 0x238a;
    sub_53d1();
    si = 0x267a;
    cx = 0x0004;
    sub_2ce0();
    ax = memoryAGet16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memoryASet(ds, 0x236c, 0x00);
loc_37db: // 01ed:190b
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_37ea;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_3884;
loc_37ea: // 01ed:191a
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al)
        goto loc_384b;
    al = ah;
    al &= 0x03;
    if (!al)
        goto loc_3840;
    sync();
    if (memoryAGet(ds, 0x236c))
        goto loc_383e;
    al = ah;
    al &= 0x01;
    if (!al)
        goto loc_3820;
    memoryASet(ds, 0x236c, 0xff);
    memoryASet16(ds, 0x0012, memoryAGet16(ds, 0x0012) - 1);
    memoryASet16(ds, 0x0012, memoryAGet16(ds, 0x0012) & 0x0001);
    ax = memoryAGet16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
    goto loc_383e;
loc_3820: // 01ed:1950
    al = ah;
    al &= 0x02;
    if (!al)
        goto loc_383e;
    memoryASet(ds, 0x236c, 0xff);
    memoryASet16(ds, 0x0012, memoryAGet16(ds, 0x0012) + 1);
    memoryASet16(ds, 0x0012, memoryAGet16(ds, 0x0012) & 0x0001);
    ax = memoryAGet16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
loc_383e: // 01ed:196e
    goto loc_37db;
loc_3840: // 01ed:1970
    memoryASet(ds, 0x236c, 0x00);
    sub_8b8b();
    goto loc_37db;
loc_384b: // 01ed:197b
    si = 0x267a;
    ax = memoryAGet16(ds, 0x0012);
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_385c: // 01ed:198c
    push(cx);
    push(si);
    ax = lodsw<DS_SI>();
    di = ax;
    dx = 0x0020;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_385c;
loc_3884: // 01ed:19b4
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_389e() // 01ed:19ce
{
    al = 0x48;
    sub_2888();
    si = 0x266e;
    cx = 0x0003;
    sub_2ce0();
    di = 0x4b12;
    ax = memoryAGet16(ds, 0x000e);
    ax += 0x0058;
    sub_2c81();
    di = 0x4b2d;
    ax = memoryAGet16(ds, 0x0010);
    ax += ax;
    di -= ax;
    cx = 0x0000;
    ax = 0x005c;
loc_38c8: // 01ed:19f8
    if (cx == memoryAGet16(ds, 0x000e))
        goto loc_38da;
    push(di);
    push(ax);
    push(cx);
    sub_2c81();
    cx = pop();
    ax = pop();
    di = pop();
    di += 0x0005;
loc_38da: // 01ed:1a0a
    ax++;
    cx++;
    if (cx == memoryAGet16(ds, 0x0010))
        goto loc_38e4;
    goto loc_38c8;
loc_38e4: // 01ed:1a14
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x3603;
    dx = 0x001c;
    cx = 0x000c;
    sub_3fa2();
    si = 0x2476;
    memoryASet16(ds, si, 0x008e);
    memoryASet16(ds, si + 2, 0x005e);
    memoryASet16(ds, si + 4, 0x259a);
    memoryASet16(ds, si + 6, 0x0000);
    si = 0x245e;
    memoryASet16(ds, si, 0x0047);
    memoryASet16(ds, si + 2, 0x0096);
    memoryASet16(ds, si + 4, 0x2562);
    if (memoryAGet16(ds, 0x000e) != 0x0002)
        goto loc_3939;
    memoryASet16(ds, si + 4, 0x257e);
loc_3939: // 01ed:1a69
    memoryASet16(ds, si + 6, 0x0000);
    sub_3e0f();
    sub_3e5d();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_281e();
    sub_3e0f();
    sub_3e5d();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0004;
    sub_8c10();
    memoryASet16(ds, 0x2368, 0x0000);
loc_3985: // 01ed:1ab5
    memoryASet16(ds, 0x2368, memoryAGet16(ds, 0x2368) + 1);
    sub_34f3();
    sub_281e();
    sub_3e0f();
    sub_3e5d();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    if (memoryAGet16(ds, 0x2368) != 0x0012)
        goto loc_39ab;
    si = 0x236d;
    sub_53d1();
loc_39ab: // 01ed:1adb
    if (memoryAGet16(ds, 0x2368) != 0x001f)
        goto loc_39b8;
    si = 0x2377;
    sub_53d1();
loc_39b8: // 01ed:1ae8
    if (memoryAGet16(ds, 0x2368) != 0x0029)
        goto loc_39d3;
    memoryASet16(ds, 0x2368, 0x0017);
    di = 0x6197;
    dx = 0x0020;
    cx = 0x0007;
    al = 0x48;
    sub_2c94();
loc_39d3: // 01ed:1b03
    sub_8b8b();
    sub_350c();
    sub_544d();
    if (dx)
        goto loc_39e3;
    goto loc_3985;
loc_39e3: // 01ed:1b13
    sub_8b80();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_3a0c() // 01ed:1b3c
{
    al = 0x48;
    sub_2888();
    di = 0x0f12;
    ax = memoryAGet16(ds, 0x0014);
    ax += 0x004a;
    sub_2c81();
    di = 0x0f16;
    ax = 0x0050;
    sub_2c81();
    di = 0x0f2d;
    ax = 0x0068;
    sub_2c81();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x0603;
    dx = 0x001c;
    cx = 0x0018;
    sub_3fa2();
    si = 0x263e;
    ax = memoryAGet16(ds, 0x0010);
    cx = 0x0003;
    mul16(cx);
    cx = ax;
    sub_2ce0();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0003;
    sub_8c10();
    cx = 0x0005;
loc_3a82: // 01ed:1bb2
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_3a91;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_3ac7;
    // gap 1 bytes // gap 1 bytes
loc_3a91: // 01ed:1bc1
    push(cx);
    sub_34f3();
    di = 0x5510;
    dx = 0x0021;
    cx = 0x0017;
    al = 0x48;
    sub_2c94();
    cx = 0x0005;
    sub_5429();
    sub_34f3();
    di = 0x5510;
    ax = 0x0052;
    sub_2c81();
    di = 0x5520;
    ax = 0x0053;
    sub_2c81();
    cx = 0x0005;
    sub_5429();
    cx = pop();
    if (--cx)
        goto loc_3a82;
loc_3ac7: // 01ed:1bf7
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_3ae1() // 01ed:1c11
{
    al = 0x48;
    sub_2888();
    if (memoryAGet16(ds, 0x000e) != 0xffff)
        goto loc_3af0;
    goto loc_3ced;
loc_3af0: // 01ed:1c20
    di = 0x0792;
    ax = memoryAGet16(ds, 0x0014);
    ax += 0x004a;
    sub_2c81();
    di = 0x0796;
    ax = 0x0050;
    sub_2c81();
    di = 0x07ad;
    ax = 0x0068;
    sub_2c81();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x1a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    memoryASet(ds, 0x236a, 0x40);
    memoryASet(ds, 0x236b, 0x41);
    di = 0x2a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    if (memoryAGet16(ds, 0x0010) == 0x0002)
        goto loc_3b7c;
    memoryASet(ds, 0x236a, 0x40);
    memoryASet(ds, 0x236b, 0x41);
    di = 0x3a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    if (memoryAGet16(ds, 0x0010) == 0x0003)
        goto loc_3b7c;
    memoryASet(ds, 0x236a, 0x40);
    memoryASet(ds, 0x236b, 0x41);
    di = 0x4a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
loc_3b7c: // 01ed:1cac
    di = 0x3c5e;
    cx = memoryAGet16(ds, 0x0010);
loc_3b83: // 01ed:1cb3
    push(cx);
    si = 0x25b6;
    ax = memoryAGet16(ds, di + 24);
    ax += ax;
    si += ax;
    si = memoryAGet16(ds, si);
    push(di);
    cx = memoryAGet16(ds, di + 30);
    cx += 0x0003;
loc_3b9b: // 01ed:1ccb
    push(cx);
    ax = lodsw<DS_SI>();
    di = ax;
    ax = lodsw<DS_SI>();
    push(si);
    sub_2c81();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_3b9b;
    di = pop();
    cx = pop();
    di += 0x0020;
    if (--cx)
        goto loc_3b83;
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0002;
    sub_8c10();
    cx = 0x0026;
    sub_5429();
    if (!memoryAGet(ds, 0x0025))
        goto loc_3be7;
    goto loc_3cd3;
loc_3be7: // 01ed:1d17
    ax = memoryAGet16(ds, 0x000e);
    cx = 0x0020;
    mul16(cx);
    si = 0x3c5e;
    si += ax;
    ax = memoryAGet16(ds, 0x000e);
    ax += ax;
    di = 0x25b6;
    di += ax;
    di = memoryAGet16(ds, di);
    ax = 0x0003;
    bx = memoryAGet16(ds, si + 30);
    push(bx);
    ax += bx;
    ax += ax;
    ax += ax;
    di += ax;
    si = di;
    ax = lodsw<DS_SI>();
    di = ax;
    ax = lodsw<DS_SI>();
    sub_2c81();
    ax = memoryAGet16(ds, 0x000e);
    cx = 0x0014;
    mul16(cx);
    si = 0x23fe;
    si += ax;
    ax = pop();
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    si = 0x248e;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 4, 0x24e6);
    si = 0x24a4;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 4, 0x24e6);
    si = 0x24ba;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 4, 0x24e6);
    si = 0x24d0;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 4, 0x24e6);
    ax = 0x0003;
    sub_8ca1();
loc_3c7f: // 01ed:1daf
    sub_34f3();
    sub_281e();
    sub_3ec9();
    if (dx == 0xffff)
        goto loc_3ca1;
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_3503();
    sub_34f3();
    sub_3503();
    goto loc_3c7f;
loc_3ca1: // 01ed:1dd1
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    ax = memoryAGet16(ds, 0x000e);
    cx = 0x0020;
    mul16(cx);
    si = 0x3c5e;
    si += ax;
    memoryASet16(ds, si + 30, memoryAGet16(ds, si + 30) + 1);
    ax = memoryAGet16(ds, 0x0014);
    if (memoryAGet16(ds, si + 30) != ax)
        goto loc_3ccd;
    memoryASet16(ds, 0x0016, 0x0001);
loc_3ccd: // 01ed:1dfd
    cx = 0x0019;
    sub_5429();
loc_3cd3: // 01ed:1e03
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    return;
loc_3ced: // 01ed:1e1d
    di = 0x1190;
    ax = 0x0051;
    sub_2c81();
    di = 0x11a1;
    ax = 0x0052;
    sub_2c81();
    memoryASet(ds, 0x236a, 0x3a);
    memoryASet(ds, 0x236b, 0x3c);
    di = 0x3d03;
    dx = 0x001c;
    cx = 0x000a;
    sub_3fa2();
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    si = 0x23ce;
    si += ax;
    ax = lodsw<DS_SI>();
    si = ax;
loc_3d27: // 01ed:1e57
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_3d37;
    di = ax;
    ax = lodsw<DS_SI>();
    push(si);
    sub_2c81();
    si = pop();
    goto loc_3d27;
loc_3d37: // 01ed:1e67
    si = 0x2476;
    memoryASet16(ds, si, 0x0060);
    memoryASet16(ds, si + 2, 0x0064);
    memoryASet16(ds, si + 4, 0x259a);
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, 0x2368, 0x0000);
    sub_3e0f();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_3e0f();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0001;
    sub_8c10();
loc_3d8f: // 01ed:1ebf
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_3d9e;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_3dc0;
    // gap 1 bytes // gap 1 bytes
loc_3d9e: // 01ed:1ece
    memoryASet16(ds, 0x2368, memoryAGet16(ds, 0x2368) + 1);
    sub_34f3();
    sub_281e();
    sub_3e0f();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_350c();
    if (memoryAGet16(ds, 0x2368) == 0x0036)
        goto loc_3dc0;
    goto loc_3d8f;
loc_3dc0: // 01ed:1ef0
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_3de6() // 01ed:1f16
{
    push(si);
    push(ax);
loc_3de8: // 01ed:1f18
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_3dff;
    di = ax;
    push(si);
    dx = 0x0008;
    cx = 0x0010;
    al = 0x48;
    sub_2c94();
    si = pop();
    goto loc_3de8;
loc_3dff: // 01ed:1f2f
    ax = pop();
    si = pop();
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    di = ax;
    ax = 0x0067;
    sub_2c81();
}
void sub_3e0f() // 01ed:1f3f
{
    si = 0x2476;
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + 1);
    if (memoryAGet16(ds, si + 6) < 0x0001)
        goto loc_3e3a;
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + 0x0004);
    bx = memoryAGet16(ds, si + 4);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_3e3a;
    bx = 0x259a;
    memoryASet16(ds, si + 4, bx);
loc_3e3a: // 01ed:1f6a
    bx = memoryAGet16(ds, si + 4);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 10, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    si += 0x0008;
    sub_2782();
}
void sub_3e5d() // 01ed:1f8d
{
    si = 0x245e;
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + 1);
    if (memoryAGet16(ds, si + 6) < 0x0003)
        goto loc_3e92;
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + 0x0006);
    bx = memoryAGet16(ds, si + 4);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_3e92;
    bx = 0x2562;
    if (memoryAGet16(ds, 0x000e) != 0x0002)
        goto loc_3e8e;
    bx = 0x257e;
loc_3e8e: // 01ed:1fbe
    memoryASet16(ds, si + 4, bx);
loc_3e92: // 01ed:1fc2
    bx = memoryAGet16(ds, si + 4);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 10, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx += memoryAGet16(ds, bx + 4);
    push(cx);
    push(dx);
    si += 0x0008;
    sub_2782();
    dx = pop();
    cx = pop();
    cx -= 0x0047;
    dx -= 0x0011;
    si = 0x244e;
    sub_2782();
}
void sub_3ec9() // 01ed:1ff9
{
    di = 0x248e;
    dx = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bx = memoryAGet16(ds, di + 4);
    memoryASet16(ds, di + 4, memoryAGet16(ds, di + 4) + 0x0008);
    si = bx;
    ax = lodsw<DS_SI>();
    if (ax != 0xfc18)
        goto loc_3ee8;
    goto loc_3f9e;
loc_3ee8: // 01ed:2018
    memoryASet16(ds, di + 6, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 8, ax);
    ax = lodsw<DS_SI>();
    dx += ax;
    ax = lodsw<DS_SI>();
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24a4;
    dx = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bx = memoryAGet16(ds, di + 4);
    memoryASet16(ds, di + 4, memoryAGet16(ds, di + 4) + 0x0008);
    si = bx;
    ax = lodsw<DS_SI>();
    ax += 0x0010;
    memoryASet16(ds, di + 6, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 8, ax);
    ax = lodsw<DS_SI>();
    ax = -ax;
    dx += ax;
    ax = lodsw<DS_SI>();
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24ba;
    dx = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bx = memoryAGet16(ds, di + 4);
    memoryASet16(ds, di + 4, memoryAGet16(ds, di + 4) + 0x0008);
    si = bx;
    ax = lodsw<DS_SI>();
    ax += 0x0020;
    memoryASet16(ds, di + 6, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 8, ax);
    ax = lodsw<DS_SI>();
    dx += ax;
    ax = lodsw<DS_SI>();
    ax = -ax;
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24d0;
    dx = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    bx = memoryAGet16(ds, di + 4);
    memoryASet16(ds, di + 4, memoryAGet16(ds, di + 4) + 0x0008);
    si = bx;
    ax = lodsw<DS_SI>();
    ax += 0x0030;
    memoryASet16(ds, di + 6, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 8, ax);
    ax = lodsw<DS_SI>();
    ax = -ax;
    dx += ax;
    ax = lodsw<DS_SI>();
    ax = -ax;
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    dx = 0x0000;
    return;
loc_3f9e: // 01ed:20ce
    dx = 0xffff;
}
void sub_3fa2() // 01ed:20d2
{
    push(di);
    push(cx);
    push(dx);
    di += memoryAGet16(ds, 0x0018);
    sub_3fb7();
    dx = pop();
    cx = pop();
    di = pop();
    di += memoryAGet16(ds, 0x001a);
    sub_3fb7();
}
void sub_3fb7() // 01ed:20e7
{
    push(di);
    push(cx);
    push(dx);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    ax = 0x0400;
    cx++;
    mul16(cx);
    memoryASet16(ds, 0x2368, ax);
    push(di);
    ax = 0x0000;
    al = memoryAGet(ds, 0x236a);
    sub_273a();
    di = pop();
    di += memoryAGet16(ds, 0x2368);
    ax = 0x003e;
    sub_273a();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cx = dx;
loc_3fea: // 01ed:211a
    push(cx);
    di += 0x0002;
    push(di);
    ax = 0x003b;
    sub_273a();
    di = pop();
    push(di);
    di += memoryAGet16(ds, 0x2368);
    ax = 0x003b;
    sub_273a();
    di = pop();
    cx = pop();
    if (--cx)
        goto loc_3fea;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    push(di);
    ax = 0x0000;
    al = memoryAGet(ds, 0x236b);
    sub_273a();
    di = pop();
    di += memoryAGet16(ds, 0x2368);
    ax = 0x003f;
    sub_273a();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    dx = pop();
    cx = pop();
    di = pop();
    ax = dx;
    ax += ax;
    memoryASet16(ds, 0x2368, ax);
loc_4034: // 01ed:2164
    push(cx);
    di += 0x0400;
    push(di);
    ax = 0x003d;
    sub_273a();
    di = pop();
    push(di);
    di += memoryAGet16(ds, 0x2368);
    ax = 0x003d;
    sub_273a();
    di = pop();
    cx = pop();
    if (--cx)
        goto loc_4034;
}
void sub_4052() // 01ed:2182
{
    memoryASet16(ds, 0x37c6, 0x5008);
    memoryASet16(ds, 0x37c8, 0x42fd);
    memoryASet16(ds, 0x28fa, 0x5a88);
    memoryASet16(ds, 0x28fc, 0x42fd);
    memoryASet16(ds, 0x26f2, 0x0000);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    ax = 0x0061;
    sub_2888();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    di = 0x0c80;
    dx = 0x0040;
    cx = 0x00be;
    al = 0x60;
    sub_2c94();
    di = 0x4108;
    ax = 0x00c1;
    sub_2c81();
    di = 0x140c;
    ax = 0x00c2;
    sub_2c81();
    di = 0x1416;
    ax = 0x00c3;
    sub_2c81();
    si = 0x3023;
    if (memoryAGet16(ds, 0x4f8e) == 0x0003)
        goto loc_40d2;
    si = 0x3059;
    if (memoryAGet16(ds, 0x4f8e) == 0x0002)
        goto loc_40d2;
    si = 0x308f;
    if (memoryAGet16(ds, 0x4f8e) == 0x0001)
        goto loc_40d2;
    si = 0x30cb;
loc_40d2: // 01ed:2202
    sub_4ef1();
    sub_2e72();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x30e5;
    di = 0x32b5;
    cx = 0x0008;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x30df;
    sub_4ef1();
    ax = 0x0006;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    dx = 0x0002;
    if (memoryAGet16(ds, 0x4f8e))
        goto loc_4126;
    dx = 0x0001;
loc_4126: // 01ed:2256
    sub_4d17();
    if (!dx)
        goto loc_4135;
    if (memoryAGet16(ds, 0x4f8e))
        goto loc_413b;
loc_4135: // 01ed:2265
    memoryASet16(ds, 0x26fc, 0x0001);
loc_413b: // 01ed:226b
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_4155() // 01ed:2285
{
    memoryASet16(ds, 0x26f2, 0x0000);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    ax = 0x0000;
    sub_2888();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x0009;
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    di = 0x0f00;
    ax = 0x00b7;
    sub_2c81();
    di = 0x6415;
    ax = 0x00b8;
    sub_2c81();
    di = 0x64a6;
    ax = 0x00b8;
    ax += memoryAGet16(ds, 0x4f88);
    sub_2c81();
    sub_4241();
    ax = 0x0008;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memoryASet(ds, 0x2700, 0x00);
    cx = 0x006c;
loc_41d4: // 01ed:2304
    push(cx);
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_4212();
    sub_281e();
    sub_4241();
    sub_350c();
    sub_544d();
    cx = pop();
    if (dx)
        goto loc_41f8;
    if (--cx)
        goto loc_41d4;
loc_41f8: // 01ed:2328
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_4212() // 01ed:2342
{
    ax = memoryAGet16(ds, 0x26ee);
    ax += memoryAGet16(ds, 0x001e);
    if (ax < 0x0006)
        goto loc_423c;
    ax = 0x0000;
    si = 0x32be;
    memoryASet(ds, 0x2700, ~memoryAGet(ds, 0x2700));
    if (memoryAGet(ds, 0x2700))
        goto loc_4232;
    si = 0x32c1;
loc_4232: // 01ed:2362
    push(ax);
    al = 0x20;
    cx = 0x0001;
    sub_2397();
    ax = pop();
loc_423c: // 01ed:236c
    memoryASet16(ds, 0x26ee, ax);
}
void sub_4241() // 01ed:2371
{
    ax = memoryAGet16(ds, 0x4f88);
    ax += ax;
    ax += ax;
    si = 0x328b;
    si += ax;
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    ax = memoryAGet16(ds, 0x001c);
    ax <<= 1;
    ax <<= 1;
    ax &= 0x0018;
    di = 0x326b;
    di += ax;
    si = 0x325b;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 2, ax);
    sub_2782();
}
void sub_4279() // 01ed:23a9
{
    memoryASet16(ds, 0x26f2, 0x0000);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    al = 0x61;
    sub_2888();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    di = 0x320f;
    di += memoryAGet16(ds, 0x001a);
    ax = 0x00ac;
    sub_273a();
    di = 0x3223;
    di += memoryAGet16(ds, 0x001a);
    ax = memoryAGet16(ds, 0x4f88);
    ax += 0x00ad;
    sub_273a();
    di = 0x3227;
    di += memoryAGet16(ds, 0x001a);
    ax = memoryAGet16(ds, 0x4f8a);
    ax += 0x00ad;
    sub_273a();
    ax = 0x0003;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    cx = 0x0012;
    sub_5429();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_4317() // 01ed:2447
{
loc_4317: // 01ed:2447
    memoryASet(ds, 0x0027, 0xff);
    memoryASet16(ds, 0x37c6, 0xe2b0);
    memoryASet16(ds, 0x37c8, 0x1650);
    memoryASet16(ds, 0x28fa, 0xe2a8);
    memoryASet16(ds, 0x28fc, 0x1650);
    ax = 0x0008;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x0d;
    sub_2888();
    memoryASet16(ds, 0x26f2, 0x0002);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out8(dx, al);
    memoryASet16(ds, 0x203e, 0x0080);
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x00a1;
    di = 0x3a00;
    sub_2c81();
    bx = 0x34bc;
    sub_23b5();
    ax = 0x0007;
    sub_8c10();
    cx = 0x0095;
loc_437d: // 01ed:24ad
    push(cx);
    sub_34f3();
    memoryASet16(ds, 0x203e, memoryAGet16(ds, 0x203e) + 1);
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_3503();
    cx = pop();
    if (--cx)
        goto loc_437d;
    cx = 0x0002;
loc_4394: // 01ed:24c4
    push(cx);
    push(ds);
    di = 0x2a86;
    di += memoryAGet16(ds, 0x0018);
    si = 0xb680;
    ax = 0x1650;
    ds = ax;
    dx = 0x000a;
    cx = 0x0034;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    push(ds);
    di = 0x2850;
    di += memoryAGet16(ds, 0x0018);
    si = 0xb6a8;
    ax = 0x1650;
    ds = ax;
    dx = 0x000e;
    cx = 0x0033;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    push(ds);
    di = 0x2fd4;
    di += memoryAGet16(ds, 0x0018);
    si = 0xb6e8;
    ax = 0x1650;
    ds = ax;
    dx = 0x002a;
    cx = 0x0022;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    cx = pop();
    if (--cx)
        goto loc_4394;
loc_43f8: // 01ed:2528
    sub_4e4c();
    si = 0x2928;
    sub_4ef1();
    sub_49b3();
    dx = 0x0004;
    sub_4d17();
    if (!memoryAGet(ds, 0x0026))
        goto loc_441a;
    memoryASet16(ds, 0x26fc, 0x0001);
    goto loc_462c;
loc_441a: // 01ed:254a
    if (!dx)
        goto loc_4432;
    si = 0x28d6;
    sub_4e81();
    if (memoryAGet16(ds, 0x26fc) != 0x0002)
        goto loc_442f;
    goto loc_4435;
    // gap 1 bytes // gap 1 bytes
loc_442f: // 01ed:255f
    goto loc_462c;
loc_4432: // 01ed:2562
    goto loc_4673;
loc_4435: // 01ed:2565
    sub_4e4c();
    si = 0x2a24;
    sub_4ef1();
    sub_49b3();
    dx = 0x0005;
    memoryASet(ds, 0x0027, 0x00);
    sub_4d17();
    if (!dx)
        goto loc_4432;
    si = 0x28e6;
    sub_4e81();
    if (memoryAGet16(ds, 0x26fc))
        goto loc_44d3;
    sub_4e4c();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x205d;
    di = 0x3234;
    cx = 0x0016;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    memoryASet16(ds, 0x3232, 0x3234);
    si = 0x205d;
    cx = 0x000b;
loc_4480: // 01ed:25b0
    memoryASet16(ds, si, 0xffff);
    si += 0x0002;
    if (--cx)
        goto loc_4480;
    si = 0x2ac8;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    bx = 0x205d;
    sub_4c70();
    sub_4e4c();
    si = 0x2af4;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    memoryASet16(ds, 0x3232, memoryAGet16(ds, 0x3232) + 0x0002);
    bx = 0x2069;
    sub_4c70();
    sub_4e4c();
    si = 0x2ca6;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    sub_4cd0();
    bx = 0x205d;
    memoryASet16(ds, bx + 10, ax);
    goto loc_4435;
loc_44d3: // 01ed:2603
    if (memoryAGet16(ds, 0x26fc) == 0x0001)
        goto loc_44dd;
    goto loc_456c;
loc_44dd: // 01ed:260d
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    sub_4e4c();
    memoryASet(ds, 0x2701, 0x04);
    memoryASet(ds, 0x2702, 0x05);
    if (memoryAGet(ds, 0x37f9))
        goto loc_4505;
    memoryASet(ds, 0x2701, 0xff);
loc_4505: // 01ed:2635
    if (memoryAGet(ds, 0x37fa))
        goto loc_4512;
    memoryASet(ds, 0x2702, 0xff);
loc_4512: // 01ed:2642
    bx = 0x37fc;
    memoryASet(ds, bx, 0xff);
    memoryASet(ds, bx + 1, 0xff);
    memoryASet(ds, bx + 2, 0xff);
    memoryASet(ds, bx + 3, 0xff);
    si = 0x2d12;
    sub_4ef1();
    si = 0x2d8e;
    sub_4a5f();
    ax = memoryAGet16(ds, 0x26fc);
    memoryASet(ds, bx, al);
    si = 0x2dba;
    sub_4a5f();
    ax = memoryAGet16(ds, 0x26fc);
    memoryASet(ds, bx + 1, al);
    si = 0x2de6;
    sub_4a5f();
    ax = memoryAGet16(ds, 0x26fc);
    memoryASet(ds, bx + 2, al);
    si = 0x2e12;
    sub_4a5f();
    ax = memoryAGet16(ds, 0x26fc);
    memoryASet(ds, bx + 3, al);
    memoryASet16(ds, 0x26fc, 0x0000);
    goto loc_4435;
loc_456c: // 01ed:269c
    if (memoryAGet16(ds, 0x26fc) == 0x0002)
        goto loc_4576;
    goto loc_460d;
loc_4576: // 01ed:26a6
    sub_4e4c();
    si = 0x2f25;
    sub_4ef1();
    di = 0x0000;
    si = 0x39c0;
    cx = 0x2540;
    sub_2922();
    sub_34f3();
    dx = 0x03d4;
    al = 0x07;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al &= 0xef;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al &= 0xbf;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x18;
    out8(dx, al);
    dx = 0x03d5;
    al = 0xa3;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c0;
    al = 0x30;
    out8(dx, al);
    dx = 0x03c0;
    al = 0x61;
    out8(dx, al);
    sub_49bd();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    dx = 0x03d4;
    al = 0x07;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al |= 0x10;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out8(dx, al);
    dx = 0x03d5;
    al = in8(dx);
    al |= 0x40;
    dx = 0x03d5;
    al = al;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x18;
    out8(dx, al);
    dx = 0x03d5;
    al = 0xff;
    out8(dx, al);
    goto loc_4435;
loc_460d: // 01ed:273d
    if (memoryAGet16(ds, 0x26fc) != 0x0003)
        goto loc_4629;
    sub_4e4c();
    si = 0x2fe1;
    sub_4ef1();
    sub_5970();
    cx = 0x0007;
    sub_5429();
    goto loc_4435;
loc_4629: // 01ed:2759
    goto loc_43f8;
loc_462c: // 01ed:275c
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    if (memoryAGet16(ds, 0x26fc) == 0x0003)
        goto loc_469b;
    if (memoryAGet16(ds, 0x26fc) == 0x0001)
        goto loc_467b;
    if (!memoryAGet16(ds, 0x26fc))
        goto loc_4688;
    memoryASet16(ds, 0x4f88, 0xffff);
    memoryASet16(ds, 0x4f8a, 0x0001);
    return;
loc_4673: // 01ed:27a3
    memoryASet16(ds, 0x26fc, 0xffff);
    goto loc_462c;
loc_467b: // 01ed:27ab
    memoryASet16(ds, 0x4f88, 0x0000);
    memoryASet16(ds, 0x4f8a, 0x0001);
    return;
loc_4688: // 01ed:27b8
    memoryASet16(ds, 0x4f88, 0x0001);
    memoryASet16(ds, 0x4f8a, 0x0001);
    sub_8d8e();
    return;
loc_4698: // 01ed:27c8
    goto loc_4957;
loc_469b: // 01ed:27cb
    al = 0x2d;
    sub_2888();
    si = 0x30ee;
    sub_4ef1();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
    memoryASet16(ds, 0x26ea, 0x0000);
    memoryASet16(ds, 0x26ec, 0x0000);
    memoryASet16(ds, 0x26e8, 0x0000);
    si = 0x32af;
    sub_532b();
    sub_2318();
    si = 0x32af;
    sub_532b();
    sub_2318();
    sub_4999();
loc_46ef: // 01ed:281f
    if (memoryAGet(ds, 0x0020) == 0x01)
        goto loc_4698;
    sub_3503();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_5476();
    memoryASet(ds, 0x2700, memoryAGet(ds, 0x2700) + 1);
    if (al & 0x1f)
        goto loc_4719;
    memoryASet(ds, 0x2700, 0x00);
loc_4719: // 01ed:2849
    if ((char)memoryAGet(ds, 0x2700) >= 0x00)
        goto loc_4723;
    goto loc_4861;
loc_4723: // 01ed:2853
    if (!(al & 0x10))
        goto loc_4795;
    if (memoryAGet16(ds, 0x26ec) != 0x0002)
        goto loc_4743;
    if (memoryAGet16(ds, 0x26ea) == 0x0008)
        goto loc_4798;
    if (memoryAGet16(ds, 0x26ea) == 0x0007)
        goto loc_479b;
    if (memoryAGet16(ds, 0x26ea) == 0x0006)
        goto loc_47b4;
loc_4743: // 01ed:2873
    push(ax);
    di = 0x5418;
    ax = memoryAGet16(ds, 0x26e8);
    ax += ax;
    di += ax;
    dx = 0x0002;
    cx = 0x0008;
    al = 0x2d;
    sub_2c94();
    sub_497f();
    ax = memoryAGet16(ds, si + 4);
    si = 0x32b5;
    si += memoryAGet16(ds, 0x26e8);
    memoryASet(ds, si, al);
    si = 0x32af;
    sub_532b();
    sub_2318();
    si = 0x32af;
    sub_532b();
    sub_2318();
    memoryASet(ds, 0x2700, 0xf6);
    if (memoryAGet16(ds, 0x26e8) == 0x0007)
        goto loc_478e;
    memoryASet16(ds, 0x26e8, memoryAGet16(ds, 0x26e8) + 1);
loc_478e: // 01ed:28be
    sub_4999();
    ax = pop();
    goto loc_47cd;
    // gap 1 bytes // gap 1 bytes
loc_4795: // 01ed:28c5
    goto loc_47cd;
    // gap 1 bytes // gap 1 bytes
loc_4798: // 01ed:28c8
    goto loc_48b7;
loc_479b: // 01ed:28cb
    if (memoryAGet16(ds, 0x26e8) == 0x0007)
        goto loc_47cd;
    memoryASet16(ds, 0x26e8, memoryAGet16(ds, 0x26e8) + 1);
    push(ax);
    sub_4999();
    ax = pop();
    memoryASet(ds, 0x2700, 0xf6);
    goto loc_47cd;
    // gap 1 bytes // gap 1 bytes
loc_47b4: // 01ed:28e4
    if (!memoryAGet16(ds, 0x26e8))
        goto loc_47cd;
    memoryASet16(ds, 0x26e8, memoryAGet16(ds, 0x26e8) - 1);
    push(ax);
    sub_4999();
    ax = pop();
    memoryASet(ds, 0x2700, 0xf6);
    goto loc_47cd;
    // gap 1 bytes // gap 1 bytes
loc_47cd: // 01ed:28fd
    if (!(al & 0x08))
        goto loc_47fc;
    if (memoryAGet16(ds, 0x26ec) != 0x0002)
        goto loc_47e5;
    if (memoryAGet16(ds, 0x26ea) != 0x0008)
        goto loc_47f2;
    memoryASet16(ds, 0x26ea, 0xffff);
loc_47e5: // 01ed:2915
    if (memoryAGet16(ds, 0x26ea) != 0x0009)
        goto loc_47f2;
    memoryASet16(ds, 0x26ea, 0xffff);
loc_47f2: // 01ed:2922
    memoryASet16(ds, 0x26ea, memoryAGet16(ds, 0x26ea) + 1);
    memoryASet(ds, 0x2700, 0xf6);
loc_47fc: // 01ed:292c
    if (!(al & 0x04))
        goto loc_4817;
    if (memoryAGet16(ds, 0x26ea))
        goto loc_480d;
    memoryASet16(ds, 0x26ea, 0x000a);
loc_480d: // 01ed:293d
    memoryASet16(ds, 0x26ea, memoryAGet16(ds, 0x26ea) - 1);
    memoryASet(ds, 0x2700, 0xf6);
loc_4817: // 01ed:2947
    if (!(al & 0x01))
        goto loc_4832;
    if (memoryAGet16(ds, 0x26ec))
        goto loc_4828;
    memoryASet16(ds, 0x26ec, 0x0003);
loc_4828: // 01ed:2958
    memoryASet16(ds, 0x26ec, memoryAGet16(ds, 0x26ec) - 1);
    memoryASet(ds, 0x2700, 0xf6);
loc_4832: // 01ed:2962
    if (!(al & 0x02))
        goto loc_484d;
    if (memoryAGet16(ds, 0x26ec) != 0x0002)
        goto loc_4843;
    memoryASet16(ds, 0x26ec, 0xffff);
loc_4843: // 01ed:2973
    memoryASet16(ds, 0x26ec, memoryAGet16(ds, 0x26ec) + 1);
    memoryASet(ds, 0x2700, 0xf6);
loc_484d: // 01ed:297d
    if (memoryAGet16(ds, 0x26ec) != 0x0002)
        goto loc_4861;
    if (memoryAGet16(ds, 0x26ea) != 0x0009)
        goto loc_4861;
    memoryASet16(ds, 0x26ea, 0x0008);
loc_4861: // 01ed:2991
    ax = memoryAGet16(ds, 0x001c);
    ax <<= 1;
    ax &= 0x000c;
    si = 0x315e;
    si += ax;
    di = 0x3222;
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 2, ax);
    sub_497f();
    push(si);
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    cx -= 0x000a;
    dx -= 0x0006;
    si = 0x3222;
    sub_2782();
    si = pop();
    di = 0x3252;
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 2, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 6, ax);
    if (ax != 0x4e45)
        goto loc_48ae;
    memoryASet16(ds, di, memoryAGet16(ds, di) - 0x0004);
loc_48ae: // 01ed:29de
    si = 0x3252;
    sub_532b();
    goto loc_46ef;
loc_48b7: // 01ed:29e7
    si = 0x32b5;
    if (memoryAGet16(ds, si) != 0x2020)
        goto loc_48e3;
    if (memoryAGet16(ds, si + 2) != 0x2020)
        goto loc_48e3;
    if (memoryAGet16(ds, si + 4) != 0x2020)
        goto loc_48e3;
    if (memoryAGet16(ds, si + 6) != 0x2020)
        goto loc_48e3;
    ax = 0x0004;
    sub_8ca1();
    goto loc_46ef;
loc_48e3: // 01ed:2a13
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x32b5;
    di = 0x30e5;
    cx = 0x0008;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    sub_2cf6();
    if (!dx)
        goto loc_4931;
    memoryASet16(ds, 0x26e8, 0x0000);
    push(cx);
    cx = ds;
    es = cx;
    di = 0x32b5;
    cx = 0x0008;
    al = 0x20;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x5418;
    dx = 0x0010;
    cx = 0x0008;
    al = 0x2d;
    sub_2c94();
    sub_4999();
    sub_49b3();
    ax = 0x0004;
    sub_8ca1();
    goto loc_46ef;
loc_4931: // 01ed:2a61
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    return;
loc_4957: // 01ed:2a87
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    goto loc_4317;
}
void sub_497f() // 01ed:2aaf
{
    ax = memoryAGet16(ds, 0x26ec);
    cx = 0x003c;
    mul16(cx);
    push(ax);
    ax = memoryAGet16(ds, 0x26ea);
    cx = 0x0006;
    mul16(cx);
    si = 0x316e;
    si += ax;
    ax = pop();
    si += ax;
}
void sub_4999() // 01ed:2ac9
{
    di = 0x5698;
    ax = 0x00c4;
    sub_2c81();
    di = 0x5698;
    ax = memoryAGet16(ds, 0x26e8);
    ax += ax;
    di += ax;
    ax = 0x00c5;
    sub_2c81();
}
void sub_49b3() // 01ed:2ae3
{
loc_49b3: // 01ed:2ae3
    sub_5476();
    al &= 0x10;
    if (al)
        goto loc_49b3;
}
void sub_49bd() // 01ed:2aed
{
    si = 0x2166;
loc_49c0: // 01ed:2af0
    ax = lodsw<DS_SI>();
    if (ax != 0xffff)
        goto loc_49ca;
    si = 0x2166;
    ax = lodsw<DS_SI>();
loc_49ca: // 01ed:2afa
    push(si);
    push(ax);
    ax >>= 1;
    ax >>= 1;
    bx = 0x2540;
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx = 0x03d5;
    al = bh;
    out8(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out8(dx, al);
    dx = 0x03d5;
    al = bl;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c0;
    al = 0x33;
    out8(dx, al);
    ax = pop();
    ax &= 0x0003;
    if (memoryAGet(ds, 0x0024) == 0x01)
        goto loc_4a04;
    al += al;
loc_4a04: // 01ed:2b34
    dx = 0x03c0;
    al = al;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
    sub_34f3();
    sub_3503();
    sub_5476();
    ah = al;
    ah &= 0x0f;
    if (!ah)
        goto loc_4a35;
    if (memoryAGet(ds, 0x2700) == 0xff)
        goto loc_4a3b;
    memoryASet(ds, 0x0024, memoryAGet(ds, 0x0024) ^ 0x01);
    memoryASet(ds, 0x2700, 0xff);
    goto loc_4a3b;
loc_4a35: // 01ed:2b65
    memoryASet(ds, 0x2700, 0x00);
loc_4a3b: // 01ed:2b6b
    sub_544d();
    si = pop();
    if (dx)
        goto loc_4a47;
    goto loc_49c0;
loc_4a47: // 01ed:2b77
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c0;
    al = 0x33;
    out8(dx, al);
    ax = 0x0000;
    dx = 0x03c0;
    al = al;
    out8(dx, al);
    dx = 0x03da;
    al = in8(dx);
}
void sub_4a5f() // 01ed:2b8f
{
    push(bx);
    ax = memoryAGet16(ds, si + 2);
    push(ax);
    sub_4ef1();
    ax = pop();
    dx = ax;
    dx--;
    si = 0x2e3e;
    di = memoryAGet16(ds, si);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
    di = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
    di = memoryAGet16(ds, si + 4);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
    di = memoryAGet16(ds, si + 6);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
    di = memoryAGet16(ds, si + 8);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
    di = memoryAGet16(ds, si + 10);
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 19, dx);
loc_4ab9: // 01ed:2be9
    sub_5476();
    al &= 0x1f;
    if (al)
        goto loc_4ab9;
    sub_4ac7();
    bx = pop();
}
void sub_4ac7() // 01ed:2bf7
{
    memoryASet16(ds, 0x26fc, 0x0000);
    ax = 0x0009;
    goto loc_4b42;
    // gap 1 bytes // gap 1 bytes
loc_4ad3: // 01ed:2c03
    sub_281e();
    si = 0x2e3e;
    ax = memoryAGet16(ds, 0x26fc);
    if (ax <= 0x0005)
        goto loc_4ae9;
    if ((short)ax >= 0x0000)
        goto loc_4ae9;
    ax = 0x0006;
loc_4ae9: // 01ed:2c19
    ax += ax;
    si += ax;
    si = memoryAGet16(ds, si);
    push(si);
    ax = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx--;
    sub_584c();
    di += memoryAGet16(ds, 0x0018);
    si = di;
    ax = 0x25f0;
    es = ax;
    di = 0x1400;
    dx = 0x0016;
    cx = 0x0009;
    sub_27d4();
    si = pop();
    push(bx);
    sub_532b();
    bx = pop();
    sub_34f3();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
loc_4b27: // 01ed:2c57
    sync();
    sub_5476();
    if (al & 0x10)
        goto loc_4b7b;
    if (memoryAGet(ds, 0x2700))
        goto loc_4b78;
    if (!(al & 0x08))
        goto loc_4b7e;
    memoryASet(ds, 0x2700, 0xff);
    ax = memoryAGet16(ds, 0x26fc);
loc_4b42: // 01ed:2c72
    ax++;
    if (ax < 0x0006)
        goto loc_4b4b;
    ax = 0x0000;
loc_4b4b: // 01ed:2c7b
    bx = 0x37fc;
    if (memoryAGet(ds, bx) == al)
        goto loc_4b42;
    if (memoryAGet(ds, bx + 1) == al)
        goto loc_4b42;
    if (memoryAGet(ds, bx + 2) == al)
        goto loc_4b42;
    if (memoryAGet(ds, bx + 3) == al)
        goto loc_4b42;
    if (memoryAGet(ds, 0x2701) == al)
        goto loc_4b42;
    if (memoryAGet(ds, 0x2702) == al)
        goto loc_4b42;
    memoryASet16(ds, 0x26fc, ax);
    goto loc_4ad3;
loc_4b78: // 01ed:2ca8
    goto loc_4bc4;
    // gap 1 bytes // gap 1 bytes
loc_4b7b: // 01ed:2cab
    goto loc_4bd3;
    // gap 1 bytes // gap 1 bytes
loc_4b7e: // 01ed:2cae
    if (!(al & 0x04))
        goto loc_4bc1;
    memoryASet(ds, 0x2700, 0xff);
    ax = memoryAGet16(ds, 0x26fc);
loc_4b8b: // 01ed:2cbb
    ax--;
    if ((short)ax >= 0x0000)
        goto loc_4b94;
    ax = 0x0005;
loc_4b94: // 01ed:2cc4
    bx = 0x37fc;
    if (memoryAGet(ds, bx) == al)
        goto loc_4b8b;
    if (memoryAGet(ds, bx + 1) == al)
        goto loc_4b8b;
    if (memoryAGet(ds, bx + 2) == al)
        goto loc_4b8b;
    if (memoryAGet(ds, bx + 3) == al)
        goto loc_4b8b;
    if (memoryAGet(ds, 0x2701) == al)
        goto loc_4b8b;
    if (memoryAGet(ds, 0x2702) == al)
        goto loc_4b8b;
    memoryASet16(ds, 0x26fc, ax);
    goto loc_4ad3;
loc_4bc1: // 01ed:2cf1
    goto loc_4b27;
loc_4bc4: // 01ed:2cf4
    al &= 0x0c;
    if (al)
        goto loc_4bd0;
    memoryASet(ds, 0x2700, 0x00);
loc_4bd0: // 01ed:2d00
    goto loc_4b27;
loc_4bd3: // 01ed:2d03
    sub_281e();
    sub_2801();
    sub_2318();
    si = 0x2e3e;
    ax = memoryAGet16(ds, 0x26fc);
    ax += ax;
    si += ax;
    si = memoryAGet16(ds, si);
    sub_4ef1();
}
void sub_4bee() // 01ed:2d1e
{
    push(bx);
    ax = ds;
    es = ax;
    dx = di;
    di += 0x0016;
    al = 0x20;
    cx = 0x0007;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    di = dx;
    di += 0x003d;
    cx = 0x0007;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    bx = memoryAGet16(ds, 0x3232);
    al = memoryAGet(ds, bx + 1);
    memoryASet16(ds, 0x3232, memoryAGet16(ds, 0x3232) + 0x0002);
    si = 0x32c4;
loc_4c19: // 01ed:2d49
    if (memoryAGet(ds, si) == al)
        goto loc_4c2c;
    if (memoryAGet(ds, si) == 0xff)
        goto loc_4c43;
    si += 0x0008;
    goto loc_4c19;
loc_4c2c: // 01ed:2d5c
    si++;
    push(si);
    di = dx;
    di += 0x001e;
    cx = 0x0007;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    di = dx;
    di += 0x0045;
    cx = 0x0007;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
loc_4c43: // 01ed:2d73
    si = dx;
    sub_4ef1();
    bx = pop();
}
void sub_4c4a() // 01ed:2d7a
{
    dx = di;
    ax = ds;
    es = ax;
    si = memoryAGet16(ds, 0x26e6);
    di += 0x0016;
    cx = 0x0007;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di = dx;
    si = memoryAGet16(ds, 0x26e6);
    di += 0x003d;
    cx = 0x0007;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = dx;
    sub_4ef1();
}
void sub_4c70() // 01ed:2da0
{
    di = 0x2b20;
    sub_4bee();
    sub_4cd0();
    memoryASet16(ds, bx, ax);
    di = 0x2b20;
    sub_4c4a();
    di = 0x2b6e;
    sub_4bee();
    sub_4cd0();
    memoryASet16(ds, bx + 2, ax);
    di = 0x2b6e;
    sub_4c4a();
    di = 0x2bbc;
    sub_4bee();
    sub_4cd0();
    memoryASet16(ds, bx + 4, ax);
    di = 0x2bbc;
    sub_4c4a();
    di = 0x2c0a;
    sub_4bee();
    sub_4cd0();
    memoryASet16(ds, bx + 6, ax);
    di = 0x2c0a;
    sub_4c4a();
    di = 0x2c58;
    sub_4bee();
    sub_4cd0();
    memoryASet16(ds, bx + 8, ax);
    di = 0x2c58;
    sub_4c4a();
}
void sub_4cd0() // 01ed:2e00
{
    sync();
    return;
loc_4cd0: // 01ed:2e00
    memoryASet(ds, 0x0020, 0xff);
loc_4cd5: // 01ed:2e05
    sync();
    al = memoryAGet(ds, 0x0020);
    if ((char)al < 0x00)
        goto loc_4cd5;
    if (al == 0x2a)
        goto loc_4cd5;
    si = 0x205e;
    cx = 0x000b;
loc_4ce6: // 01ed:2e16
    if (memoryAGet(ds, si) == al)
        goto loc_4cd0;
    si += 0x0002;
    if (--cx)
        goto loc_4ce6;
    si = 0x32c4;
loc_4cf4: // 01ed:2e24
    if (memoryAGet(ds, si) == al)
        goto loc_4d07;
    if (memoryAGet(ds, si) == 0xff)
        goto loc_4cd0;
    si += 0x0008;
    goto loc_4cf4;
loc_4d07: // 01ed:2e37
    si++;
    memoryASet16(ds, 0x26e6, si);
    ah = al;
    al += 0x80;
loc_4d10: // 01ed:2e40
    sync();
    if (memoryAGet(ds, 0x0020) != al)
        goto loc_4d10;
}
void sub_4d17() // 01ed:2e47
{
    dx--;
    memoryASet16(ds, 0x26fe, dx);
    memoryASet16(ds, 0x26fc, 0x0000);
    memoryASet(ds, 0x0020, 0x00);
    memoryASet16(ds, 0x26e4, 0x0000);
loc_4d2d: // 01ed:2e5d
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    if (memoryAGet(ds, 0x0020) == 0x01)
        goto loc_4dad;
    sub_5476();
    if (memoryAGet16(ds, 0x37e4) == 0xffff)
        goto loc_4d77;
    if (memoryAGet(ds, 0x0020) != 0x48)
        goto loc_4d5b;
    al |= 0x01;
    memoryASet(ds, 0x0020, 0x00);
loc_4d5b: // 01ed:2e8b
    if (memoryAGet(ds, 0x0020) != 0x50)
        goto loc_4d69;
    al |= 0x02;
    memoryASet(ds, 0x0020, 0x00);
loc_4d69: // 01ed:2e99
    if (memoryAGet(ds, 0x0020) != 0x1c)
        goto loc_4d77;
    al |= 0x10;
    memoryASet(ds, 0x0020, 0x00);
loc_4d77: // 01ed:2ea7
    ah = al;
    al &= 0x10;
    if (al)
        goto loc_4db6;
    al = ah;
    al &= 0x03;
    if (!al)
        goto loc_4db9;
    memoryASet16(ds, 0x26e4, 0x0000);
    if (memoryAGet(ds, 0x2700))
        goto loc_4dfc;
    al = ah;
    al &= 0x01;
    if (!al)
        goto loc_4dda;
    memoryASet(ds, 0x2700, 0xff);
    if (memoryAGet16(ds, 0x26fc))
        goto loc_4db0;
    dx = memoryAGet16(ds, 0x26fe);
    memoryASet16(ds, 0x26fc, dx);
    goto loc_4dfc;
loc_4dad: // 01ed:2edd
    goto loc_4e42;
loc_4db0: // 01ed:2ee0
    memoryASet16(ds, 0x26fc, memoryAGet16(ds, 0x26fc) - 1);
    goto loc_4dfc;
loc_4db6: // 01ed:2ee6
    goto loc_4e38;
loc_4db9: // 01ed:2ee9
    memoryASet(ds, 0x2700, 0x00);
    if (!memoryAGet(ds, 0x0027))
        goto loc_4dfc;
    memoryASet16(ds, 0x26e4, memoryAGet16(ds, 0x26e4) + 1);
    if (memoryAGet16(ds, 0x26e4) < 0x021c)
        goto loc_4dfc;
    memoryASet(ds, 0x0026, 0xff);
    goto loc_4e42;
    // gap 1 bytes // gap 1 bytes
loc_4dda: // 01ed:2f0a
    al = ah;
    al &= 0x02;
    if (!al)
        goto loc_4dfc;
    memoryASet(ds, 0x2700, 0xff);
    dx = memoryAGet16(ds, 0x26fe);
    if (memoryAGet16(ds, 0x26fc) != dx)
        goto loc_4df8;
    memoryASet16(ds, 0x26fc, 0x0000);
    goto loc_4dfc;
loc_4df8: // 01ed:2f28
    memoryASet16(ds, 0x26fc, memoryAGet16(ds, 0x26fc) + 1);
loc_4dfc: // 01ed:2f2c
    si = 0x28d6;
    if (memoryAGet16(ds, 0x26fe) != 0x0004)
        goto loc_4e09;
    si = 0x28e6;
loc_4e09: // 01ed:2f39
    if (memoryAGet16(ds, 0x26fe) != 0x0001)
        goto loc_4e13;
    si = 0x324a;
loc_4e13: // 01ed:2f43
    if (memoryAGet16(ds, 0x26fe))
        goto loc_4e1d;
    si = 0x324e;
loc_4e1d: // 01ed:2f4d
    ax = memoryAGet16(ds, 0x26fc);
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    si = 0x28fa;
    sub_2782();
    sub_350c();
    goto loc_4d2d;
loc_4e38: // 01ed:2f68
    memoryASet16(ds, 0x26e4, 0x0000);
    dx = 0xffff;
    return;
loc_4e42: // 01ed:2f72
    memoryASet16(ds, 0x26e4, 0x0000);
    dx = 0x0000;
}
void sub_4e4c() // 01ed:2f7c
{
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memoryAGet16(ds, 0x0018);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0060;
    sub_24dc();
    ds = pop();
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memoryAGet16(ds, 0x001a);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0060;
    sub_24dc();
    ds = pop();
}
void sub_4e81() // 01ed:2fb1
{
    push(si);
    ax = memoryAGet16(ds, 0x26fc);
    si += 0x0002;
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    bx = ax;
    cx = 0x0040;
    mul16(cx);
    di = ax;
    ax = bx;
    ax -= 0x00e8;
    cx = 0x0140;
    mul16(cx);
    si = ax;
    push(ds);
    di += memoryAGet16(ds, 0x0018);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0008;
    sub_24dc();
    ds = pop();
    si = pop();
    cx = 0x0008;
loc_4ebc: // 01ed:2fec
    push(cx);
    push(si);
    sub_34f3();
    sub_281e();
    ax = memoryAGet16(ds, 0x26fc);
    si = pop();
    push(si);
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    si = 0x28fa;
    sub_2782();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    cx = 0x0005;
loc_4ee7: // 01ed:3017
    sub_350c();
    if (--cx)
        goto loc_4ee7;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_4ebc;
}
void sub_4ef1() // 01ed:3021
{
    push(bx);
    push(si);
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_532b();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    si = pop();
    sub_532b();
    bx = pop();
}
void sub_4f14() // 01ed:3044
{
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_4f2f;
    memoryASet16(ds, 0x203e, 0x0080);
    bx = memoryAGet16(ds, 0x4f78);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x26f2, ax);
    goto loc_4f35;
    // gap 1 bytes // gap 1 bytes
loc_4f2f: // 01ed:305f
    memoryASet16(ds, 0x26f2, 0x0000);
loc_4f35: // 01ed:3065
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_4f4a;
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    goto loc_4f56;
loc_4f4a: // 01ed:307a
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out8(dx, al);
loc_4f56: // 01ed:3086
    if (memoryAGet16(ds, 0x26f2))
        goto loc_4f6a;
    memoryASet16(ds, 0x26f4, 0x000f);
    memoryASet16(ds, 0x26f6, 0x000d);
    return;
loc_4f6a: // 01ed:309a
    if (memoryAGet16(ds, 0x26f2) != 0x0001)
        goto loc_4f7e;
    memoryASet16(ds, 0x26f4, 0x001f);
    memoryASet16(ds, 0x26f6, 0x000d);
    return;
loc_4f7e: // 01ed:30ae
    memoryASet16(ds, 0x26f4, 0x000f);
    memoryASet16(ds, 0x26f6, 0x001d);
}
void sub_4f8b() // 01ed:30bb
{
    si = 0x271c;
    ax = memoryAGet16(ds, 0x4f88);
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x26f8, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x26fa, ax);
    si = 0x0726;
    di = 0x0c02;
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_4faf;
    di = 0x0602;
loc_4faf: // 01ed:30df
    cx = memoryAGet16(ds, 0x26f6);
loc_4fb3: // 01ed:30e3
    push(cx);
    push(di);
    cx = memoryAGet16(ds, 0x26f4);
loc_4fb9: // 01ed:30e9
    push(cx);
    al = lodsb<DS_SI>();
    ah = al;
    push(si);
    si = memoryAGet16(ds, 0x26f8);
    bx = 0xfffe;
loc_4fc5: // 01ed:30f5
    bx += 0x0002;
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_4fd1;
    if (ah != al)
        goto loc_4fc5;
loc_4fd1: // 01ed:3101
    si = memoryAGet16(ds, 0x26fa);
    si += bx;
    ax = lodsw<DS_SI>();
    sub_4ffe();
    push(di);
    sub_2c81();
    di = pop();
    di += 0x0004;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_4fb9;
    di = pop();
    cx = pop();
    di += 0x0400;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_4ff8;
    di += 0x0400;
loc_4ff8: // 01ed:3128
    if (--cx)
        goto loc_4fb3;
    sub_504e();
}
void sub_4ffe() // 01ed:312e
{
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_504d;
    if (!ax)
        goto loc_500f;
    if (ax != 0x0069)
        goto loc_504d;
loc_500f: // 01ed:313f
    push(dx);
    push(cx);
    dx = di;
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_5023;
    dx -= 0x0602;
    push(dx);
    cl = 0x0a;
    goto loc_502a;
loc_5023: // 01ed:3153
    dx -= 0x0c02;
    push(dx);
    cl = 0x0b;
loc_502a: // 01ed:315a
    dx >>= cl;
    if (dx == 0x0001)
        goto loc_504a;
    dx &= 0x0001;
    if (!dx)
        goto loc_504a;
    dx = pop();
    push(dx);
    cl = 0x02;
    dx >>= cl;
    dx &= 0x0001;
    if (dx)
        goto loc_504a;
    ax = 0x006a;
loc_504a: // 01ed:317a
    dx = pop();
    cx = pop();
    dx = pop();
loc_504d: // 01ed:317d
    return;
}
void sub_504e() // 01ed:317e
{
    if (memoryAGet16(ds, 0x4f88))
        goto loc_5068;
    di = 0x0c00;
    ax = 0x000f;
    sub_50ca();
    di = 0x0c3e;
    ax = 0x0010;
    sub_50ca();
    return;
loc_5068: // 01ed:3198
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_5092;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_50ae;
    di = 0x0c00;
    ax = 0x0083;
    sub_50ca();
    di = 0x0c3e;
    ax = 0x007c;
    sub_50ca();
    si = 0x290a;
    cx = 0x0002;
    sub_2ce0();
    return;
loc_5092: // 01ed:31c2
    di = 0x0c00;
    ax = 0x0083;
    sub_50ca();
    di = 0x0c7e;
    ax = 0x007c;
    sub_50ca();
    si = 0x2914;
    cx = 0x0002;
    sub_2ce0();
    return;
loc_50ae: // 01ed:31de
    di = 0x0600;
    ax = 0x0083;
    sub_50ca();
    di = 0x063e;
    ax = 0x007c;
    sub_50ca();
    si = 0x291e;
    cx = 0x0002;
    sub_2ce0();
}
void sub_50ca() // 01ed:31fa
{
    cx = memoryAGet16(ds, 0x26f6);
loc_50ce: // 01ed:31fe
    push(cx);
    push(di);
    push(ax);
    sub_2c81();
    ax = pop();
    di = pop();
    cx = pop();
    di += 0x0400;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_50e6;
    di += 0x0400;
loc_50e6: // 01ed:3216
    if (--cx)
        goto loc_50ce;
}
void sub_50e9() // 01ed:3219
{
    if (memoryAGet16(ds, 0x4f88))
        goto loc_5139;
    si = 0x2704;
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    push(si);
    dl = 0x2e;
    dh = 0x41;
    sub_518d();
    si = pop();
    ax = lodsw<DS_SI>();
    cx = ax;
    push(si);
    dl = 0x42;
    dh = 0x41;
    sub_518d();
    si = pop();
    ax = lodsw<DS_SI>();
    cx = ax;
    push(si);
    dl = 0x43;
    dh = 0x41;
    sub_518d();
    si = pop();
    ax = lodsw<DS_SI>();
    cx = ax;
    push(si);
    if (!memoryAGet16(ds, 0x0012))
        goto loc_5137;
    dl = 0x44;
    dh = 0x41;
    sub_518d();
loc_5137: // 01ed:3267
    si = pop();
    return;
loc_5139: // 01ed:3269
    bx = memoryAGet16(ds, 0x26f2);
    bx += bx;
    si = 0x34b6;
    ax = memoryAGet16(ds, bx + si);
    bx = memoryAGet16(ds, 0x4f78);
    cx = memoryAGet16(ds, bx + 2);
    ax -= cx;
    memoryASet16(ds, 0x4f6e, ax);
    dx = 0x452e;
    sub_518d();
    memoryASet16(ds, 0x4f92, 0x0000);
    cx = 0x0001;
    bx = memoryAGet16(ds, 0x4f78);
    dx = memoryAGet16(ds, bx + 4);
    if (dx == 0xffff)
        goto loc_5177;
    dh = 0x45;
    sub_518d();
    memoryASet16(ds, 0x4f92, ax);
loc_5177: // 01ed:32a7
    cx = 0x0001;
    bx = memoryAGet16(ds, 0x4f78);
    dx = memoryAGet16(ds, bx + 6);
    if (dx == 0xffff)
        goto loc_518c;
    dh = 0x45;
    sub_518d();
loc_518c: // 01ed:32bc
    return;
}
void sub_518d() // 01ed:32bd
{
loc_518d: // 01ed:32bd
    push(cx);
    push(dx);
loc_518f: // 01ed:32bf
    push(dx);
    ax = memoryAGet16(ds, 0x26f6);
    ax++;
    sub_587c();
    push(ax);
    ax = memoryAGet16(ds, 0x26f4);
    ax++;
    sub_587c();
    dx = pop();
    ah = dl;
    bx = ax;
    sub_5832();
    dx = pop();
    if (al != dh)
        goto loc_518f;
    ax = bx;
    dx = pop();
    sub_57b4();
    cx = pop();
    if (--cx)
        goto loc_518d;
}
void sub_51b6() // 01ed:32e6
{
    memoryASet(ds, 0x37f9, 0xff);
    memoryASet(ds, 0x37fa, 0xff);
    ah = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    if (flags.carry)
        goto loc_51fe;
    if (!ax)
        goto loc_51e4;
    memoryASet(ds, 0x37f9, 0x00);
    ax &= 0x00ff;
    cx &= 0x00ff;
    memoryASet16(ds, 0x37bc, ax);
    memoryASet16(ds, 0x37be, bx);
loc_51e4: // 01ed:3314
    if (!cx)
        goto loc_51fe;
    memoryASet(ds, 0x37fa, 0x00);
    ax &= 0x00ff;
    cx &= 0x00ff;
    memoryASet16(ds, 0x37c0, cx);
    memoryASet16(ds, 0x37c2, dx);
loc_51fe: // 01ed:332e
    return;
}
void sub_51ff() // 01ed:332f
{
    sub_521e();
    sub_5264();
    sub_52aa();
    sub_5300();
    sub_2318();
    sub_521e();
    sub_5264();
    sub_52aa();
    sub_5300();
    sub_2318();
}
void sub_521e() // 01ed:334e
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_523b;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_5236;
    di = memoryAGet16(ds, 0x0018);
    di += 0x0248;
    goto loc_5242;
loc_5236: // 01ed:3366
    di = 0xfc48;
    goto loc_5242;
loc_523b: // 01ed:336b
    di = 0x0488;
    di += memoryAGet16(ds, 0x0018);
loc_5242: // 01ed:3372
    ax = memoryAGet16(ds, 0x3a50);
    if (!ax)
        goto loc_525a;
    sub_5718();
    ax = 0x0000;
    sub_573d();
    di += 0x0002;
    sub_573d();
    return;
loc_525a: // 01ed:338a
    di += 0x000c;
    ax = 0x0000;
    sub_573d();
}
void sub_5264() // 01ed:3394
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_5281;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_527c;
    di = memoryAGet16(ds, 0x0018);
    di += 0x0270;
    goto loc_5288;
loc_527c: // 01ed:33ac
    di = 0xfc70;
    goto loc_5288;
loc_5281: // 01ed:33b1
    di = 0x04b0;
    di += memoryAGet16(ds, 0x0018);
loc_5288: // 01ed:33b8
    ax = memoryAGet16(ds, 0x4f90);
    if (!ax)
        goto loc_52a0;
    sub_5718();
    ax = 0x0000;
    sub_573d();
    di += 0x0002;
    sub_573d();
    return;
loc_52a0: // 01ed:33d0
    di += 0x000c;
    ax = 0x0000;
    sub_573d();
}
void sub_52aa() // 01ed:33da
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_52c7;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_52c2;
    di = memoryAGet16(ds, 0x0018);
    di += 0x025a;
    goto loc_52ce;
loc_52c2: // 01ed:33f2
    di = 0xfc5a;
    goto loc_52ce;
loc_52c7: // 01ed:33f7
    di = 0x049a;
    di += memoryAGet16(ds, 0x0018);
loc_52ce: // 01ed:33fe
    push(di);
    si = 0x37d4;
    ax = memoryAGet16(ds, 0x37ce);
    sub_57ae();
    ax = memoryAGet16(ds, 0x37d4);
    di = pop();
    push(di);
    sub_573d();
    si = 0x37d4;
    ax = memoryAGet16(ds, 0x37d0);
    sub_579c();
    ax = memoryAGet16(ds, 0x37d4);
    di = pop();
    di += 0x0004;
    push(di);
    sub_573d();
    ax = memoryAGet16(ds, 0x37d5);
    di = pop();
    di += 0x0002;
    sub_573d();
}
void sub_5300() // 01ed:3430
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_531d;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_5318;
    di = memoryAGet16(ds, 0x0018);
    di += 0x0266;
    goto loc_5324;
loc_5318: // 01ed:3448
    di = 0xfc66;
    goto loc_5324;
loc_531d: // 01ed:344d
    di = 0x04a6;
    di += memoryAGet16(ds, 0x0018);
loc_5324: // 01ed:3454
    ax = memoryAGet16(ds, 0x4f8c);
    sub_573d();
}
void sub_532b() // 01ed:345b
{
loc_532b: // 01ed:345b
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    cx = ax;
    ax = dx;
    sub_584c();
    dx = ax;
    ax = lodsw<DS_SI>();
    dh = al;
    memoryASet16(ds, 0x37d2, dx);
loc_533f: // 01ed:346f
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_53a5;
    if (!al)
        goto loc_532b;
    ah = al;
    push(si);
    si = 0x383a;
    bx = 0x0000;
loc_5351: // 01ed:3481
    al = lodsb<DS_SI>();
    if (al == ah)
        goto loc_535b;
    bx += 0x0002;
    goto loc_5351;
loc_535b: // 01ed:348b
    bx += 0x3865;
    push(ds);
    push(di);
    ax = memoryAGet16(ds, 0x37d2);
    di += memoryAGet16(ds, 0x0018);
    si = memoryAGet16(ds, bx);
    si += memoryAGet16(ds, 0x37c6);
    dx = memoryAGet16(ds, 0x37c8);
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_53a6;
    ds = dx;
    push(si);
    push(di);
    push(ax);
    bl = ah;
    dx = 0x0001;
    cx = 0x0007;
    sub_2952();
    ax = pop();
    di = pop();
    si = pop();
    di++;
    bl = ah;
    si += 0x0004;
    dx = 0x0001;
    cx = 0x0007;
    sub_2952();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_533f;
loc_53a5: // 01ed:34d5
    return;
loc_53a6: // 01ed:34d6
    ds = dx;
    push(si);
    push(di);
    push(ax);
    bl = ah;
    dx = 0x0001;
    cx = 0x0007;
    sub_29dc();
    ax = pop();
    di = pop();
    si = pop();
    di++;
    bl = ah;
    si += 0x0004;
    dx = 0x0001;
    cx = 0x0007;
    sub_29dc();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_533f;
}
void sub_53d1() // 01ed:3501
{
    ax = lodsw<DS_SI>();
    di = ax;
loc_53d4: // 01ed:3504
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_5428;
    ah = al;
    push(si);
    si = 0x383a;
    bx = 0x0000;
loc_53e2: // 01ed:3512
    al = lodsb<DS_SI>();
    if (al == ah)
        goto loc_53ec;
    bx += 0x0002;
    goto loc_53e2;
loc_53ec: // 01ed:351c
    bx += 0x3865;
    push(ds);
    push(di);
    di += memoryAGet16(ds, 0x0018);
    ax = memoryAGet16(ds, 0x001a);
    push(ax);
    si = memoryAGet16(ds, bx);
    si += 0xc808;
    ax = 0x335d;
    ds = ax;
    push(si);
    dx = 0x0002;
    cx = 0x0007;
    sub_2499();
    si = pop();
    ax = pop();
    di = pop();
    push(di);
    di += ax;
    dx = 0x0002;
    cx = 0x0007;
    sub_2499();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_53d4;
loc_5428: // 01ed:3558
    return;
}
void sub_5429() // 01ed:3559
{
    sync();
    sync();
    sync();
    sync();
    return;
loc_5429: // 01ed:3559
    ax = memoryAGet16(ds, 0x001c);
loc_542c: // 01ed:355c
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_543b;
    memoryASet(ds, 0x0025, 0xff);
    goto loc_5443;
    // gap 1 bytes // gap 1 bytes
loc_543b: // 01ed:356b
    if (ax == memoryAGet16(ds, 0x001c))
        goto loc_542c;
    if (--cx)
        goto loc_5429;
loc_5443: // 01ed:3573
    return;
}
void sub_5444() // 01ed:3574
{
loc_5444: // 01ed:3574
    sub_544d();
    if (!dx)
        goto loc_5444;
}
void sub_544d() // 01ed:357d
{
    sub_552a();
    al = memoryAGet(ds, 0x37f3);
    al |= memoryAGet(ds, 0x37f4);
    al |= memoryAGet(ds, 0x37f1);
    al |= memoryAGet(ds, 0x37f2);
    if (memoryAGet(ds, 0x37f9))
        goto loc_546a;
    al |= memoryAGet(ds, 0x37f5);
loc_546a: // 01ed:359a
    al &= 0x10;
    if (!al)
        goto loc_5472;
    dx = 0xffff;
    return;
loc_5472: // 01ed:35a2
    dx = 0x0000;
}
void sub_5476() // 01ed:35a6
{
    sync();
    sub_552a();
    al = memoryAGet(ds, 0x37f3);
    al |= memoryAGet(ds, 0x37f4);
    al |= memoryAGet(ds, 0x37f1);
    al |= memoryAGet(ds, 0x37f2);
    if (memoryAGet(ds, 0x37f9))
        goto loc_5493;
    al |= memoryAGet(ds, 0x37f5);
loc_5493: // 01ed:35c3
    return;
}
void sub_5494() // 01ed:35c4
{
    di = 0x049a;
    si = 0x3c5e;
    cx = memoryAGet16(ds, 0x0010);
loc_549e: // 01ed:35ce
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_54bc;
    push(di);
    di += memoryAGet16(ds, 0x0018);
    ax = memoryAGet16(ds, si + 30);
    sub_573d();
    di = pop();
    push(di);
    di += memoryAGet16(ds, 0x001a);
    sub_573d();
    di = pop();
loc_54bc: // 01ed:35ec
    di += 0x0008;
    si += 0x0020;
    cx = pop();
    if (--cx)
        goto loc_549e;
}
void sub_54c6() // 01ed:35f6
{
    ax = 0x0278;
    sub_54f3();
    if (!dx)
        goto loc_54ef;
    ax = 0x0378;
    sub_54f3();
    if (!dx)
        goto loc_54ef;
    ax = 0x03bc;
    sub_54f3();
    if (!dx)
        goto loc_54ef;
    ax = 0xffff;
    memoryASet16(ds, 0x37e4, dx);
    return;
loc_54ef: // 01ed:361f
    memoryASet16(ds, 0x37e4, ax);
}
void sub_54f3() // 01ed:3623
{
    dx = 0;
}
void sub_552a() // 01ed:365a
{
    if (memoryAGet16(ds, 0x37e4) != 0xffff)
        goto loc_5534;
    goto loc_5638;
loc_5534: // 01ed:3664
    al = memoryAGet(ds, 0x37f7);
    memoryASet(ds, 0x37f3, al);
    al = memoryAGet(ds, 0x37f8);
    memoryASet(ds, 0x37f4, al);
    si = 0x37e6;
    ah = 0xff;
    bl = 0x20;
    bh = 0x00;
    sub_567c();
//    memoryASet(ds, 0x37f1, bh);
    si = 0x37eb;
    ah = 0x00;
    bl = 0x80;
    bh = 0x00;
    sub_567c();
//    memoryASet(ds, 0x37f2, bh);
    if (memoryAGet(ds, 0x37f9))
        goto loc_55b4;
    memoryASet(ds, 0x37f0, 0x00);
    ah = 0x84;
    dx = 0x0000;
    interrupt(0x15);
    if (al & 0x10)
        goto loc_557d;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x10);
loc_557d: // 01ed:36ad
    if (al & 0x20)
        goto loc_5596;
    if (memoryAGet(ds, 0x37fb))
        goto loc_559c;
    memoryASet(ds, 0x37fb, 0xff);
    memoryASet(ds, 0x204e, 0xff);
    goto loc_559c;
    // gap 1 bytes // gap 1 bytes
loc_5596: // 01ed:36c6
    memoryASet(ds, 0x37fb, 0x00);
loc_559c: // 01ed:36cc
    al = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    cx = memoryAGet16(ds, 0x37be);
    dx = memoryAGet16(ds, 0x37bc);
    sub_5639();
    al = memoryAGet(ds, 0x37f0);
    memoryASet(ds, 0x37f5, al);
loc_55b4: // 01ed:36e4
    if (memoryAGet(ds, 0x37fa))
        goto loc_55f6;
    memoryASet(ds, 0x37f0, 0x00);
    ah = 0x84;
    dx = 0x0000;
    interrupt(0x15);
    if (al & 0x40)
        goto loc_55d1;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x10);
loc_55d1: // 01ed:3701
    if (al & 0x80)
        goto loc_55da;
    memoryASet(ds, 0x204e, 0xff);
loc_55da: // 01ed:370a
    al = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    ax = cx;
    bx = dx;
    cx = memoryAGet16(ds, 0x37c2);
    dx = memoryAGet16(ds, 0x37c0);
    sub_5639();
    al = memoryAGet(ds, 0x37f0);
    memoryASet(ds, 0x37f6, al);
loc_55f6: // 01ed:3726
    ax = 0x0000;
    si = 0x37fc;
    di = 0x3c5e;
    cx = 0x0004;
loc_5602: // 01ed:3732
    ax = 0x0000;
    al = lodsb<DS_SI>();
    ax += ax;
    bx = 0x3800;
    bx += ax;
    bx = memoryAGet16(ds, bx);
    al = memoryAGet(ds, bx);
    memoryASet16(ds, di + 26, ax);
    di += 0x0020;
    if (--cx)
        goto loc_5602;
    si = 0x3c5e;
    al = memoryAGet(ds, 0x204e);
    if (!al)
        goto loc_5633;
    memoryASet16(ds, si + 26, memoryAGet16(ds, si + 26) | 0x0020);
    memoryASet(ds, 0x204e, 0x00);
    return;
loc_5633: // 01ed:3763
    memoryASet16(ds, si + 26, memoryAGet16(ds, si + 26) & 0xffdf);
loc_5638: // 01ed:3768
    return;
}
void sub_5639() // 01ed:3769
{
    ax &= 0x00ff;
    bx &= 0x00ff;
    dx += 0x0020;
    if (ax <= dx)
        goto loc_564c;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x08);
loc_564c: // 01ed:377c
    dx -= 0x0040;
    if (ax > dx)
        goto loc_5658;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x04);
loc_5658: // 01ed:3788
    cx += 0x0020;
    if (bx <= cx)
        goto loc_5664;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x02);
loc_5664: // 01ed:3794
    cx -= 0x0040;
    if (bx > cx)
        goto loc_5670;
    memoryASet(ds, 0x37f0, memoryAGet(ds, 0x37f0) | 0x01);
loc_5670: // 01ed:37a0
    if (ax)
        goto loc_567b;
    memoryASet(ds, 0x37f0, 0x00);
loc_567b: // 01ed:37ab
    return;
}
void sub_567c() // 01ed:37ac
{
    bx = 0;
}
void sub_56de() // 01ed:380e
{
    si = 0x37d4;
    ax = memoryAGet16(ds, 0x37ce);
    sub_57ae();
    ax = memoryAGet16(ds, 0x37d4);
    di = 0x0488;
    di += memoryAGet16(ds, 0x0018);
    sub_573d();
    si = 0x37d4;
    ax = memoryAGet16(ds, 0x37d0);
    sub_579c();
    ax = memoryAGet16(ds, 0x37d4);
    di = 0x048c;
    di += memoryAGet16(ds, 0x0018);
    sub_573d();
    ax = memoryAGet16(ds, 0x37d5);
    di = 0x048e;
    di += memoryAGet16(ds, 0x0018);
    sub_573d();
}
void sub_5718() // 01ed:3848
{
    si = 0x37d4;
    sub_576c();
    si = 0x37d4;
    cx = 0x0005;
loc_5724: // 01ed:3854
    al = lodsb<DS_SI>();
    if (al)
        goto loc_5731;
    di += 0x0002;
    if (--cx)
        goto loc_5724;
    goto loc_573c;
    // gap 1 bytes // gap 1 bytes
loc_5731: // 01ed:3861
    push(cx);
    sub_573d();
    di += 0x0002;
    al = lodsb<DS_SI>();
    cx = pop();
    if (--cx)
        goto loc_5731;
loc_573c: // 01ed:386c
    return;
}
void sub_573d() // 01ed:386d
{
    bx = memoryAGet16(ds, 0x26f2);
    push(bx);
    if (bx != 0x0001)
        goto loc_574d;
    memoryASet16(ds, 0x26f2, 0x0002);
loc_574d: // 01ed:387d
    push(si);
    push(di);
    push(ax);
    ax &= 0x000f;
    ax += 0x0012;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_5760;
    ax += 0x0090;
loc_5760: // 01ed:3890
    sub_273a();
    ax = pop();
    di = pop();
    si = pop();
    bx = pop();
    memoryASet16(ds, 0x26f2, bx);
}
void sub_576c() // 01ed:389c
{
    cx = 0x2710;
    dx = 0x0000;
    div16(cx);
    memoryASet(ds, si, al);
    si++;
    ax = dx;
    cx = 0x03e8;
    dx = 0x0000;
    div16(cx);
    memoryASet(ds, si, al);
    si++;
    ax = dx;
    dx = 0x0000;
    cx = 0x0064;
    div16(cx);
    memoryASet(ds, si, al);
    si++;
    ax = dx;
    goto loc_579c;
    // gap 1 bytes // gap 1 bytes
loc_579c: // 01ed:38cc
    cx = 0x000a;
    dx = 0x0000;
    div16(cx);
    memoryASet(ds, si, al);
    si++;
    ax = dx;
    goto loc_57ae;
    // gap 1 bytes // gap 1 bytes
loc_57ae: // 01ed:38de
    memoryASet(ds, si, al);
    si++;
}
void sub_579c() // 01ed:38cc
{
    cx = 0x000a;
    dx = 0x0000;
    div16(cx);
    memoryASet(ds, si, al);
    si++;
    ax = dx;
    goto loc_57ae;
    // gap 1 bytes // gap 1 bytes
loc_57ae: // 01ed:38de
    memoryASet(ds, si, al);
    si++;
}
void sub_57ae() // 01ed:38de
{
    memoryASet(ds, si, al);
    si++;
}
void sub_57b4() // 01ed:38e4
{
    push(ax);
    push(si);
    push(dx);
    si = 0x0726;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memoryAGet16(ds, 0x26f4);
    mul16(cx);
    si += ax;
    dx = pop();
    memoryASet(ds, si, dl);
    si = pop();
    ax = pop();
}
void sub_57d2() // 01ed:3902
{
    push(ax);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0008;
    dx = ax;
    ax = pop();
    al = ah;
    ah = 0x00;
    ax <<= cl;
    ax += 0x0018;
    cx = ax;
    dx += 0x0008;
    cx += 0x0008;
}
void sub_57f1() // 01ed:3921
{
    push(ax);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0002;
    di = ax;
    ax = pop();
    al = ah;
    ah = 0x00;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_5814;
    cx = 0x0800;
    mul16(cx);
    ax += 0x0c00;
    di += ax;
    return;
loc_5814: // 01ed:3944
    cx = 0x0400;
    mul16(cx);
    ax += 0x0600;
    di += ax;
}
void sub_581f() // 01ed:394f
{
    push(cx);
    dx -= 0x0008;
    cl = 0x04;
    dx >>= cl;
    al = dl;
    dx = pop();
    dx -= 0x0018;
    dx >>= cl;
    ah = dl;
}
void sub_5832() // 01ed:3962
{
    push(si);
    si = 0x0726;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memoryAGet16(ds, 0x26f4);
    mul16(cx);
    si += ax;
    al = memoryAGet(ds, si);
    si = pop();
}
void sub_584c() // 01ed:397c
{
    push(ax);
    ax = 0x0080;
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_585a;
    ax = 0x0040;
loc_585a: // 01ed:398a
    mul16(cx);
    di = ax;
    ax = pop();
    cx = ax;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    ax &= 0x0003;
}
void sub_586b() // 01ed:399b
{
    ah = 0x2c;
    interrupt(0x21);
    dl ^= ch;
    dl ^= cl;
    dl ^= dh;
    dh = 0x00;
    memoryASet16(ds, 0x37cc, dx);
}
void sub_587c() // 01ed:39ac
{
    push(si);
    cx = ax;
    si = 0x38bb;
    dx = memoryAGet16(ds, 0x37cc);
    si += dx;
    ax = memoryAGet16(ds, si);
    dx += ax;
    dx++;
    dx &= 0x007f;
    memoryASet16(ds, 0x37cc, dx);
    dx = memoryAGet16(ds, si + 1);
    memoryASet16(ds, si, memoryAGet16(ds, si) ^ dx);
    dx = 0x0000;
    div16(cx);
    ax = dx;
    si = pop();
}
void sub_58a7() // 01ed:39d7
{
    ah = 0x3d;
    al = 0x90;
    dx = 0x380c;
    interrupt(0x21);
    if (flags.carry)
        goto loc_58fd;
    memoryASet16(ds, 0x37ca, ax);
    push(ds);
    ah = 0x3f;
    bx = memoryAGet16(ds, 0x37ca);
    cx = 0x2710;
    dx = 0x25f0;
    ds = dx;
    dx = 0x5590;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_58f5;
    ah = 0x3e;
    bx = memoryAGet16(ds, 0x37ca);
    interrupt(0x21);
    push(ds);
    push(es);
    push(cx);
    push(si);
    cx = 0x0b52;
    es = cx;
    cx = 0x25f0;
    ds = cx;
    si = 0x5590;
    di = 0x0726;
    cx = 0x01b8;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    es = pop();
    ds = pop();
    dx = 0x0000;
    return;
loc_58f5: // 01ed:3a25
    ah = 0x3e;
    bx = memoryAGet16(ds, 0x37ca);
    interrupt(0x21);
loc_58fd: // 01ed:3a2d
    dx = 0xffff;
}
void sub_5901() // 01ed:3a31
{
    ah = 0x3d;
    al = 0x90;
    dx = 0x3815;
    interrupt(0x21);
    if (flags.carry)
        goto loc_5966;
    memoryASet16(ds, 0x37ca, ax);
    ah = 0x3f;
    bx = memoryAGet16(ds, 0x37ca);
    cx = 0x001c;
    dx = 0x381e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_5967;
    ah = 0x3e;
    bx = memoryAGet16(ds, 0x37ca);
    interrupt(0x21);
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x381e;
    di = 0x205d;
    cx = 0x000c;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x382a;
    di = 0x2069;
    cx = 0x000a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x3834;
    di = 0x37fc;
    cx = 0x0004;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    al = memoryAGet(ds, 0x3838);
    memoryASet(ds, 0x0024, al);
loc_5966: // 01ed:3a96
    return;
loc_5967: // 01ed:3a97
    ah = 0x3e;
    bx = memoryAGet16(ds, 0x37ca);
    interrupt(0x21);
}
void sub_5970() // 01ed:3aa0
{
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x205d;
    di = 0x381e;
    cx = 0x000c;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x2069;
    di = 0x382a;
    cx = 0x000a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x37fc;
    di = 0x3834;
    cx = 0x0004;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    al = memoryAGet(ds, 0x0024);
    memoryASet(ds, 0x3838, al);
    dx = 0x3815;
    cx = 0x0000;
    ah = 0x3c;
    interrupt(0x21);
    if (flags.carry)
        goto loc_59d6;
    memoryASet16(ds, 0x37ca, ax);
    bx = ax;
    bx = memoryAGet16(ds, 0x37ca);
    dx = 0x381e;
    cx = 0x001c;
    ah = 0x40;
    interrupt(0x21);
    bx = memoryAGet16(ds, 0x37ca);
    ah = 0x3e;
    interrupt(0x21);
loc_59d6: // 01ed:3b06
    return;
}
void sub_59d8() // 01ed:3b08
{
    si = 0x3d8e;
    cx = 0x0008;
loc_59de: // 01ed:3b0e
    push(si);
    push(cx);
    di = memoryAGet16(ds, si);
    if (di == 0xffff)
        goto loc_5a19;
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 4);
    al += dl;
    if (ah > al)
        goto loc_59fe;
    al = 0x00;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 0x0002);
loc_59fe: // 01ed:3b2e
    memoryASet16(ds, si + 4, ax);
    bx = memoryAGet16(ds, si + 2);
    ax = memoryAGet16(ds, bx);
    if (ax == 0xffff)
        goto loc_5a21;
    sub_4ffe();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
loc_5a19: // 01ed:3b49
    cx = pop();
    si = pop();
    si += 0x000a;
    if (--cx)
        goto loc_59de;
    return;
loc_5a21: // 01ed:3b51
    ax = memoryAGet16(ds, si + 8);
    ax += ax;
    ax += ax;
    bx = 0x3a80;
    bx += ax;
    dx = memoryAGet16(ds, bx);
    memoryASet16(ds, si, 0xffff);
    ax = memoryAGet16(ds, si + 6);
    sub_57b4();
    goto loc_5a19;
}
void sub_5a41() // 01ed:3b71
{
    memoryASet(ds, 0x3a5d, 0xff);
    si = 0x3c5e;
    sub_5b29();
    si = 0x3c7e;
    sub_5b29();
    si = 0x3c9e;
    sub_5b29();
    si = 0x3cbe;
    sub_5b29();
    sub_5ab3();
    sub_5c33();
    if (memoryAGet16(ds, 0x4f88) != 0x0001)
        goto loc_5aab;
    if (memoryAGet16(ds, 0x4f8a) != 0x0001)
        goto loc_5aab;
    if (memoryAGet(ds, 0x3a5d) == 0xff)
        goto loc_5aac;
    memoryASet16(ds, 0x4f6c, memoryAGet16(ds, 0x4f6c) - 1);
    if ((short)memoryAGet16(ds, 0x4f6c) >= 0x0000)
        goto loc_5aab;
    memoryASet16(ds, 0x4f6c, 0x7fff);
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x70;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009b;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_5aab: // 01ed:3bdb
    return;
loc_5aac: // 01ed:3bdc
    memoryASet16(ds, 0x4f6c, 0x0ca8);
}
void sub_5ab3() // 01ed:3be3
{
    if (!memoryAGet16(ds, 0x0012))
        goto loc_5b28;
    si = 0x3c5e;
    cx = memoryAGet16(ds, 0x0010);
loc_5ac1: // 01ed:3bf1
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_5b22;
    if (!memoryAGet16(ds, si + 20))
        goto loc_5b22;
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = ax;
    cx = memoryAGet16(ds, 0x0010);
    di = 0x3c5e;
loc_5ae4: // 01ed:3c14
    push(cx);
    if (memoryAGet16(ds, di) == 0xffff)
        goto loc_5b1c;
    ax = memoryAGet16(ds, si + 24);
    if (ax == memoryAGet16(ds, di + 24))
        goto loc_5b1c;
    push(dx);
    dx = memoryAGet16(ds, di);
    cx = memoryAGet16(ds, di + 2);
    sub_581f();
    dx = pop();
    if (ax != dx)
        goto loc_5b1c;
    if (memoryAGet16(ds, di + 22) != 0xffff)
        goto loc_5b1c;
    ax = memoryAGet16(ds, si + 22);
    memoryASet16(ds, di + 22, ax);
    memoryASet16(ds, di + 20, 0x00b4);
loc_5b1c: // 01ed:3c4c
    cx = pop();
    di += 0x0020;
    if (--cx)
        goto loc_5ae4;
loc_5b22: // 01ed:3c52
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_5ac1;
loc_5b28: // 01ed:3c58
    return;
}
void sub_5b29() // 01ed:3c59
{
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_5b6a;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_5b6a;
    if ((short)memoryAGet16(ds, si + 10) < 0x0000)
        goto loc_5b67;
    sub_5d66();
    if (memoryAGet16(ds, 0x4f88))
        goto loc_5b97;
    memoryASet16(ds, 0x3a54, 0x0300);
    ax = memoryAGet16(ds, si + 22);
    if (ax == 0xffff)
        goto loc_5b97;
    if (ax)
        goto loc_5b6d;
    memoryASet16(ds, 0x3a54, 0x0100);
    sub_6037();
    goto loc_5b9a;
loc_5b67: // 01ed:3c97
    goto loc_5ba5;
    // gap 1 bytes // gap 1 bytes
loc_5b6a: // 01ed:3c9a
    goto loc_5ba4;
    // gap 1 bytes // gap 1 bytes
loc_5b6d: // 01ed:3c9d
    if (ax != 0x0001)
        goto loc_5b7d;
    memoryASet16(ds, 0x3a54, 0x0c00);
    sub_6037();
    goto loc_5b9a;
loc_5b7d: // 01ed:3cad
    if (ax != 0x0002)
        goto loc_5b89;
    memoryASet(ds, si + 26, memoryAGet(ds, si + 26) & 0x0f);
    goto loc_5b97;
loc_5b89: // 01ed:3cb9
    if (ax != 0x0003)
        goto loc_5b97;
    ax = memoryAGet16(ds, 0x0022);
    al &= 0x10;
    memoryASet(ds, si + 26, memoryAGet(ds, si + 26) ^ al);
loc_5b97: // 01ed:3cc7
    sub_6037();
loc_5b9a: // 01ed:3cca
    sub_5dce();
    if (memoryAGet16(ds, si + 10) == 0xffff)
        goto loc_5b67;
loc_5ba4: // 01ed:3cd4
    return;
loc_5ba5: // 01ed:3cd5
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    push(si);
    push(cx);
    push(dx);
    si = memoryAGet16(ds, 0x3a46);
    ax = memoryAGet16(ds, 0x001c);
    ax &= 0x0001;
    if (ax)
        goto loc_5bc4;
    memoryASet16(ds, 0x3a46, memoryAGet16(ds, 0x3a46) + 0x0004);
loc_5bc4: // 01ed:3cf4
    di = 0x41c9;
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_5c23;
    memoryASet16(ds, di, ax);
    ax = 0x42fd;
    memoryASet16(ds, di + 2, ax);
    ax = lodsw<DS_SI>();
    dx = 0x0016;
    dx -= ax;
    memoryASet16(ds, di + 6, dx);
    si = 0x41c9;
    dx = pop();
    cx = pop();
    cx += ax;
    push(cx);
    push(dx);
    sub_2782();
    di = 0x41d9;
    si = memoryAGet16(ds, 0x3a48);
    ax = lodsw<DS_SI>();
    if (ax != 0xffff)
        goto loc_5c03;
    si = 0x40ed;
    memoryASet16(ds, 0x3a48, si);
    ax = lodsw<DS_SI>();
loc_5c03: // 01ed:3d33
    memoryASet16(ds, 0x3a48, memoryAGet16(ds, 0x3a48) + 0x0002);
    memoryASet16(ds, di, ax);
    ax = 0x42fd;
    memoryASet16(ds, di + 2, ax);
    dx = pop();
    cx = pop();
    dx -= 0x0004;
    cx -= 0x0008;
    si = 0x41d9;
    sub_2782();
    si = pop();
    return;
loc_5c23: // 01ed:3d53
    dx = pop();
    cx = pop();
    si = pop();
    memoryASet16(ds, 0x4f7c, 0x0002);
    memoryASet16(ds, si, 0xffff);
}
void sub_5c33() // 01ed:3d63
{
    si = 0x3c5e;
    cx = 0x0004;
loc_5c39: // 01ed:3d69
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_5cab;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_5ca8;
    if ((short)memoryAGet16(ds, si + 10) < 0x0000)
        goto loc_5cab;
    push(si);
    bx = 0x3b7a;
    ax = memoryAGet16(ds, si + 8);
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    bx = 0x3e4c;
    dx = memoryAGet16(ds, si + 24);
    dx += dx;
    bx += dx;
    ax += memoryAGet16(ds, bx);
    ax += memoryAGet16(ds, si + 28);
    dx = memoryAGet16(ds, si);
    dx -= 0x000b;
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x000d;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_5cae;
    bx = memoryAGet16(ds, si + 22);
    bx &= 0x0008;
    if (!bx)
        goto loc_5cae;
    bx = memoryAGet16(ds, 0x001c);
    bx &= 0x0002;
    if (bx)
        goto loc_5cae;
    bl = 0xfe;
    sub_28b6();
    si = pop();
    goto loc_5cf4;
    // gap 1 bytes // gap 1 bytes
loc_5ca8: // 01ed:3dd8
    goto loc_5d00;
    // gap 1 bytes // gap 1 bytes
loc_5cab: // 01ed:3ddb
    goto loc_5cfe;
    // gap 1 bytes // gap 1 bytes
loc_5cae: // 01ed:3dde
    sub_276b();
    si = pop();
    if (memoryAGet16(ds, 0x4f88) != 0x0003)
        goto loc_5cf4;
    push(si);
    dx = memoryAGet16(ds, si);
    dx -= 0x0008;
    cx = memoryAGet16(ds, si + 2);
    cx++;
    bx = 0x41a9;
    if (!memoryAGet(ds, 0x3a5d))
        goto loc_5cd5;
    bx = 0x41b9;
loc_5cd5: // 01ed:3e05
    ax = memoryAGet16(ds, 0x001c);
    ax &= 0x000c;
    bx += ax;
    si = 0x41e9;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 2, ax);
    sub_2782();
    si = pop();
loc_5cf4: // 01ed:3e24
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_5cfb;
    return;
loc_5cfb: // 01ed:3e2b
    goto loc_5c39;
loc_5cfe: // 01ed:3e2e
    goto loc_5cf4;
loc_5d00: // 01ed:3e30
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + ax);
    if (memoryAGet16(ds, si + 10) < 0x0009)
        goto loc_5d18;
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) - 1);
loc_5d18: // 01ed:3e48
    bx = 0x3b5e;
    ax = memoryAGet16(ds, si + 8);
    ax = -ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    if (ax == 0xffff)
        goto loc_5d58;
    bx = 0x3e4c;
    dx = memoryAGet16(ds, si + 24);
    dx += dx;
    bx += dx;
    ax += memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, si);
    dx -= 0x0008;
    dx -= 0x0003;
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0008;
    cx -= 0x0005;
    push(si);
    sub_276b();
    si = pop();
    goto loc_5cf4;
loc_5d58: // 01ed:3e88
    memoryASet16(ds, si, 0xffff);
    memoryASet16(ds, si + 8, 0x0000);
    goto loc_5cf4;
}
void sub_5d66() // 01ed:3e96
{
    ax = memoryAGet16(ds, si + 20);
    if (!ax)
        goto loc_5da6;
    ax--;
    memoryASet16(ds, si + 20, ax);
    if (!ax)
        goto loc_5da7;
    dx = ax;
    dx &= 0x0003;
    if (dx)
        goto loc_5da6;
    ax &= 0x0004;
    cl = 0x01;
    ax >>= cl;
    bx = 0x3fac;
    bx += ax;
    ax = memoryAGet16(ds, si + 24);
    ax += ax;
    ax += ax;
    bx += ax;
    push(si);
    si = memoryAGet16(ds, bx);
    ax = lodsw<DS_SI>();
    cx = ax;
    ax = lodsw<DS_SI>();
    sub_2397();
    si = pop();
loc_5da6: // 01ed:3ed6
    return;
loc_5da7: // 01ed:3ed7
    memoryASet16(ds, si + 22, 0xffff);
    push(si);
    bx = 0x3fac;
    ax = memoryAGet16(ds, si + 24);
    ax += ax;
    ax += ax;
    bx += ax;
    si = memoryAGet16(ds, bx);
    ax = lodsw<DS_SI>();
    cx = ax;
    ax = lodsw<DS_SI>();
    sub_2397();
    si = pop();
    memoryASet16(ds, 0x3a54, 0x0300);
}
void sub_5dce() // 01ed:3efe
{
    memoryASet(ds, 0x3a5e, 0x00);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    push(ax);
    sub_5832();
    dx = pop();
    if (al < 0x61)
        goto loc_5e30;
    if (al > 0x75)
        goto loc_5e30;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_5e24;
    if (al == 0x67)
        goto loc_5e4c;
    if (al == 0x66)
        goto loc_5e53;
    if (al == 0x6b)
        goto loc_5e34;
    if (al == 0x6a)
        goto loc_5e31;
    if (al == 0x69)
        goto loc_5e37;
    if (al == 0x6d)
        goto loc_5e40;
    if (al == 0x68)
        goto loc_5e43;
    if (al == 0x6c)
        goto loc_5e46;
    if (al == 0x75)
        goto loc_5e49;
    if (al == 0x73)
        goto loc_5e3a;
    if (al == 0x6f)
        goto loc_5e3d;
    if (al == 0x70)
        goto loc_5e3d;
    return;
loc_5e24: // 01ed:3f54
    if (al == 0x61)
        goto loc_5e4c;
    if (al == 0x62)
        goto loc_5e53;
    if (al == 0x63)
        goto loc_5e5a;
loc_5e30: // 01ed:3f60
    return;
loc_5e31: // 01ed:3f61
    goto loc_5e99;
    // gap 1 bytes // gap 1 bytes
loc_5e34: // 01ed:3f64
    goto loc_5e91;
    // gap 1 bytes // gap 1 bytes
loc_5e37: // 01ed:3f67
    goto loc_5ea1;
    // gap 1 bytes // gap 1 bytes
loc_5e3a: // 01ed:3f6a
    goto loc_5edb;
loc_5e3d: // 01ed:3f6d
    goto loc_5ee4;
loc_5e40: // 01ed:3f70
    goto loc_5ed4;
loc_5e43: // 01ed:3f73
    goto loc_5ec4;
    // gap 1 bytes // gap 1 bytes
loc_5e46: // 01ed:3f76
    goto loc_5ecc;
loc_5e49: // 01ed:3f79
    goto loc_5eec;
loc_5e4c: // 01ed:3f7c
    push(si);
    memoryASet16(ds, si + 12, memoryAGet16(ds, si + 12) + 1);
    goto loc_5e6d;
loc_5e53: // 01ed:3f83
    push(si);
    memoryASet16(ds, si + 18, memoryAGet16(ds, si + 18) + 1);
    goto loc_5e6d;
loc_5e5a: // 01ed:3f8a
    push(dx);
    memoryASet16(ds, si + 20, 0x00b4);
    ax = 0x0004;
    sub_587c();
    memoryASet16(ds, si + 22, ax);
    dx = pop();
    push(si);
loc_5e6d: // 01ed:3f9d
    ax = dx;
    push(ax);
    sub_57f1();
    ax = 0x0000;
    sub_4ffe();
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    ax = pop();
    dl = 0x2e;
    sub_57b4();
    ax = 0x0001;
    sub_8ca1();
    si = pop();
    return;
loc_5e91: // 01ed:3fc1
    push(si);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) | 0x0001);
    goto loc_5e6d;
loc_5e99: // 01ed:3fc9
    push(si);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) | 0x0002);
    goto loc_5e6d;
loc_5ea1: // 01ed:3fd1
    push(si);
    if (memoryAGet16(ds, 0x3a54) != 0x0240)
        goto loc_5eb2;
    memoryASet16(ds, 0x3a54, 0x0300);
    goto loc_5e6d;
loc_5eb2: // 01ed:3fe2
    if (memoryAGet16(ds, 0x3a54) != 0x0300)
        goto loc_5ec2;
    memoryASet16(ds, 0x3a54, 0x03c0);
    goto loc_5e6d;
loc_5ec2: // 01ed:3ff2
    goto loc_5e6d;
loc_5ec4: // 01ed:3ff4
    push(si);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) | 0x0004);
    goto loc_5e6d;
loc_5ecc: // 01ed:3ffc
    push(si);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) | 0x0008);
    goto loc_5e6d;
loc_5ed4: // 01ed:4004
    push(si);
    memoryASet16(ds, 0x4f8c, memoryAGet16(ds, 0x4f8c) + 1);
    goto loc_5e6d;
loc_5edb: // 01ed:400b
    push(si);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x012c);
    goto loc_5e6d;
loc_5ee4: // 01ed:4014
    push(si);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x0064);
    goto loc_5e6d;
loc_5eec: // 01ed:401c
    if (memoryAGet16(ds, 0x4200))
        goto loc_5ef9;
    memoryASet(ds, 0x3a5e, 0xff);
loc_5ef9: // 01ed:4029
    return;
}
void sub_5efa() // 01ed:402a
{
    si = 0x3dde;
    cx = 0x0008;
loc_5f00: // 01ed:4030
    di = memoryAGet16(ds, si);
    if (di == 0xffff)
        goto loc_5f1e;
    memoryASet16(ds, si, 0xffff);
    di += memoryAGet16(ds, 0x0018);
    ax = memoryAGet16(ds, si + 2);
    push(cx);
    push(si);
    sub_273a();
    si = pop();
    cx = pop();
loc_5f1e: // 01ed:404e
    si += 0x0004;
    if (--cx)
        goto loc_5f00;
}
void sub_5f24() // 01ed:4054
{
    push(si);
    si = 0x3dde;
    cx = 0x0008;
loc_5f2b: // 01ed:405b
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_5f39;
    si += 0x0004;
    if (--cx)
        goto loc_5f2b;
    si = pop();
    return;
loc_5f39: // 01ed:4069
    memoryASet16(ds, si, di);
    memoryASet16(ds, si + 2, ax);
    si = pop();
}
void sub_5f43() // 01ed:4073
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    push(si);
    si = 0x0726;
    di = 0x3f94;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memoryAGet16(ds, 0x26f4);
    mul16(cx);
    si += ax;
    bx = memoryAGet16(ds, 0x26f4);
    bx = -bx;
    al = memoryAGet(ds, bx + si - 1);
    memoryASet(ds, di, al);
    al = memoryAGet(ds, bx + si);
    memoryASet(ds, di + 1, al);
    al = memoryAGet(ds, bx + si + 1);
    memoryASet(ds, di + 2, al);
    al = memoryAGet(ds, si - 1);
    memoryASet(ds, di + 7, al);
    al = memoryAGet(ds, si + 1);
    memoryASet(ds, di + 3, al);
    bx = -bx;
    al = memoryAGet(ds, bx + si - 1);
    memoryASet(ds, di + 6, al);
    al = memoryAGet(ds, bx + si);
    memoryASet(ds, di + 5, al);
    al = memoryAGet(ds, bx + si + 1);
    memoryASet(ds, di + 4, al);
    si = pop();
    dx = memoryAGet16(ds, si);
    dx -= 0x0010;
    dx += 0x0008;
    dx &= 0x000f;
    dx -= 0x0008;
    memoryASet16(ds, 0x3a58, dx);
    dx = memoryAGet16(ds, si + 2);
    dx -= 0x0020;
    dx += 0x0008;
    dx &= 0x000f;
    dx -= 0x0008;
    memoryASet16(ds, 0x3a5a, dx);
}
void sub_5fd7() // 01ed:4107
{
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_6033;
    if (!memoryAGet(ds, 0x3a5e))
        goto loc_6033;
    ax = memoryAGet16(ds, si);
    ax -= 0x0010;
    ax &= 0x000f;
    if (ax)
        goto loc_6033;
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0020;
    ax &= 0x000f;
    if (ax)
        goto loc_6033;
    memoryASet16(ds, si, memoryAGet16(ds, si) - 0x000b);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 0x000d);
    memoryASet16(ds, 0x3a46, 0x40f7);
    memoryASet16(ds, 0x3a48, 0x40ed);
    memoryASet16(ds, si + 10, 0xffff);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) | 0x0008);
    ax = 0x000a;
    sub_8c10();
    dx = 0xffff;
    memoryASet(ds, 0x0023, 0xff);
    return;
loc_6033: // 01ed:4163
    dx = 0x0000;
}
void sub_6037() // 01ed:4167
{
    bx = memoryAGet16(ds, si + 26);
    bh = bl;
    bl &= 0x10;
    if (!bl)
        goto loc_6049;
    push(bx);
    sub_60b0();
    bx = pop();
    goto loc_6049;
loc_6049: // 01ed:4179
    bl = bh;
    bl &= 0x01;
    if (!bl)
        goto loc_605e;
    sub_66b6();
    sub_663d();
    memoryASet16(ds, si + 28, 0x0009);
    goto loc_60af;
loc_605e: // 01ed:418e
    bl = bh;
    bl &= 0x02;
    if (!bl)
        goto loc_6073;
    sub_66e1();
    sub_663d();
    memoryASet16(ds, si + 28, 0x0000);
    goto loc_60af;
loc_6073: // 01ed:41a3
    bl = bh;
    bl &= 0x04;
    if (!bl)
        goto loc_6088;
    sub_668b();
    sub_663d();
    memoryASet16(ds, si + 28, 0x0006);
    goto loc_60af;
loc_6088: // 01ed:41b8
    bl = bh;
    bl &= 0x08;
    if (!bl)
        goto loc_609d;
    sub_6660();
    sub_663d();
    memoryASet16(ds, si + 28, 0x0003);
    goto loc_60af;
loc_609d: // 01ed:41cd
    memoryASet(ds, 0x3a5d, 0x00);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
loc_60af: // 01ed:41df
    return;
}
void sub_60b0() // 01ed:41e0
{
    bx = 0x3cde;
    cx = 0x0008;
loc_60b6: // 01ed:41e6
    ax = memoryAGet16(ds, bx);
    if (ax == 0xffff)
        goto loc_60c7;
    bx += 0x0016;
    if (--cx)
        goto loc_60b6;
    goto loc_614d;
loc_60c7: // 01ed:41f7
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = ax;
    push(dx);
    sub_5832();
    dx = pop();
    if (al != 0x2e)
        goto loc_614d;
    ax = memoryAGet16(ds, si + 12);
    if (ax == memoryAGet16(ds, si + 14))
        goto loc_614d;
    memoryASet16(ds, si + 14, memoryAGet16(ds, si + 14) + 1);
    push(si);
    push(bx);
    ax = dx;
    dl = 0x2b;
    push(ax);
    sub_57b4();
    ax = pop();
    push(ax);
    sub_57d2();
    ax = dx;
    cx -= 0x0008;
    ax -= 0x0008;
    sub_584c();
    ax = pop();
    bx = pop();
    si = pop();
    memoryASet16(ds, bx, di);
    memoryASet16(ds, bx + 2, 0x0000);
    memoryASet16(ds, bx + 4, 0x0000);
    memoryASet16(ds, bx + 6, 0x00d2);
    memoryASet16(ds, bx + 8, ax);
    ax = memoryAGet16(ds, si + 24);
    memoryASet16(ds, bx + 18, ax);
    ax = memoryAGet16(ds, 0x3a4e);
    memoryASet16(ds, bx + 20, ax);
    memoryASet16(ds, 0x3a4e, memoryAGet16(ds, 0x3a4e) + 1);
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_614d;
    ax = memoryAGet16(ds, 0x3c74);
    ax &= 0x0004;
    if (!ax)
        goto loc_614d;
    memoryASet16(ds, bx + 6, 0x7fff);
loc_614d: // 01ed:427d
    return;
}
void sub_614e() // 01ed:427e
{
    push(ax);
    ax = memoryAGet16(ds, si + 18);
    bx = 0x3f9e;
    ax += ax;
    bx += ax;
    bx = memoryAGet16(ds, bx);
    bx = memoryAGet16(ds, bx + 18);
    ax = pop();
    cx = 0x0000;
loc_6166: // 01ed:4296
    al += dl;
    ah += dh;
    push(ax);
    push(dx);
    push(cx);
    sub_5832();
    cx = pop();
    dx = pop();
    if (al != 0x2e)
        goto loc_6184;
    ax = pop();
    cx++;
    if (cx == bx)
        goto loc_617e;
    goto loc_6166;
loc_617e: // 01ed:42ae
    cx = -cx;
    return;
loc_6181: // 01ed:42b1
    goto loc_6220;
loc_6184: // 01ed:42b4
    if (al == 0x2b)
        goto loc_6181;
    if (al < 0x41)
        goto loc_6193;
    if (al > 0x54)
        goto loc_6193;
    goto loc_623d;
loc_6193: // 01ed:42c3
    if (al == 0x55)
        goto loc_61a8;
    if (al < 0x61)
        goto loc_61a2;
    if (al > 0x74)
        goto loc_61a2;
    goto loc_62d0;
loc_61a2: // 01ed:42d2
    if (al == 0x75)
        goto loc_61d2;
    ax = pop();
    return;
loc_61a8: // 01ed:42d8
    if (memoryAGet16(ds, 0x4f6e) != 0x0001)
        goto loc_61cf;
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x73;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009e;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_61cf: // 01ed:42ff
    goto loc_623d;
    // gap 1 bytes // gap 1 bytes
loc_61d2: // 01ed:4302
    ax = pop();
    if ((short)memoryAGet16(ds, 0x3c68) < 0x0000)
        goto loc_621f;
    push(cx);
    push(si);
    push(ax);
    ax = 0x0004;
    sub_587c();
    dx = 0x0009;
    if (!ax)
        goto loc_61fe;
    dx = 0x0005;
    if (ax == 0x0001)
        goto loc_61fe;
    dx = 0x0003;
    if (ax == 0x0002)
        goto loc_61fe;
    dx = 0x0004;
loc_61fe: // 01ed:432e
    ax = pop();
    cx = 0x0004;
    sub_6908();
    ax = memoryAGet16(ds, 0x4f92);
    if (!ax)
        goto loc_621d;
    sub_57f1();
    ax = 0x006b;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
loc_621d: // 01ed:434d
    si = pop();
    cx = pop();
loc_621f: // 01ed:434f
    return;
loc_6220: // 01ed:4350
    ax = pop();
    push(cx);
    bx = 0x3cde;
    cx = 0x0008;
loc_6228: // 01ed:4358
    if (ax != memoryAGet16(ds, bx + 8))
        goto loc_6236;
    memoryASet16(ds, bx + 6, 0x0004);
    goto loc_623b;
loc_6236: // 01ed:4366
    bx += 0x0016;
    if (--cx)
        goto loc_6228;
loc_623b: // 01ed:436b
    cx = pop();
    return;
loc_623d: // 01ed:436d
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_6272;
    if (memoryAGet16(ds, 0x4f6e) != 0x0002)
        goto loc_6272;
    if (memoryAGet(ds, 0x4f94))
        goto loc_6272;
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x6f;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009a;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_6272: // 01ed:43a2
    memoryASet16(ds, 0x4f6e, memoryAGet16(ds, 0x4f6e) - 1);
    dx = ax;
    ax = pop();
    if (ax != memoryAGet16(ds, 0x4f92))
        goto loc_6285;
    memoryASet16(ds, 0x4f92, 0x0000);
loc_6285: // 01ed:43b5
    push(cx);
    cx = 0x0008;
    bx = 0x3d8e;
loc_628c: // 01ed:43bc
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_629a;
    bx += 0x000a;
    if (--cx)
        goto loc_628c;
    cx = pop();
    return;
loc_629a: // 01ed:43ca
    dh = 0x00;
    dx -= 0x0041;
    memoryASet16(ds, bx + 8, dx);
    push(dx);
    push(ax);
    sub_57f1();
    ax = pop();
    dx = pop();
    memoryASet16(ds, bx, di);
    memoryASet16(ds, bx + 4, 0x0500);
    memoryASet16(ds, bx + 6, ax);
    dx += dx;
    dx += dx;
    di = 0x3a80;
    di += dx;
    dx = memoryAGet16(ds, di + 2);
    memoryASet16(ds, bx + 2, dx);
    dl = 0x56;
    sub_57b4();
    cx = pop();
    return;
loc_62d0: // 01ed:4400
    ax = pop();
    push(cx);
    bx = 0x3dfe;
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_62f2;
    bx += 0x001a;
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_62f2;
    bx += 0x001a;
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_62f2;
    cx = pop();
    return;
loc_62f2: // 01ed:4422
    memoryASet16(ds, bx + 8, ax);
    sub_57d2();
    dx -= 0x000e;
    cx -= 0x0013;
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, cx);
    memoryASet16(ds, bx + 4, 0x3a60);
    memoryASet16(ds, bx + 6, 0x0000);
    cx = pop();
}
void sub_6315() // 01ed:4445
{
    si = 0x3dfe;
    cx = 0x0003;
loc_631b: // 01ed:444b
    push(cx);
    push(si);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_6364;
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + ax);
    if (memoryAGet16(ds, si + 6) < 0x0008)
        goto loc_633d;
    memoryASet16(ds, si + 6, 0x0000);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + 0x0004);
loc_633d: // 01ed:446d
    bx = memoryAGet16(ds, si + 4);
    ax = memoryAGet16(ds, bx);
    if (ax == 0xffff)
        goto loc_636c;
    memoryASet16(ds, si + 10, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 12, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    si += 0x000a;
    sub_2782();
loc_6364: // 01ed:4494
    si = pop();
    si += 0x001a;
    cx = pop();
    if (--cx)
        goto loc_631b;
    return;
loc_636c: // 01ed:449c
    memoryASet16(ds, si, 0xffff);
    ax = memoryAGet16(ds, si + 8);
    push(ax);
    sub_57f1();
    ax = 0x0000;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    ax = pop();
    dl = 0x2e;
    sub_57b4();
    goto loc_6364;
}
void sub_638f() // 01ed:44bf
{
    memoryASet16(ds, 0x3a4c, 0x7fff);
    ax = 0x3e54;
    memoryASet16(ds, 0x3a52, ax);
    si = 0x3cde;
    cx = 0x0008;
loc_63a1: // 01ed:44d1
    push(cx);
    ax = memoryAGet16(ds, si);
    if (ax != 0xffff)
        goto loc_63ae;
    goto loc_6435;
loc_63ae: // 01ed:44de
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_63dc;
    dx = memoryAGet16(ds, 0x3c74);
    dx &= 0x0004;
    if (!dx)
        goto loc_63dc;
    dx = memoryAGet16(ds, si + 20);
    if (dx > memoryAGet16(ds, 0x3a4c))
        goto loc_63dc;
    memoryASet16(ds, 0x3a4c, dx);
    memoryASet16(ds, 0x3a4a, si);
    goto loc_63dc;
    // gap 1 bytes // gap 1 bytes
loc_63d6: // 01ed:4506
    goto loc_647c;
loc_63d9: // 01ed:4509
    goto loc_64ee;
loc_63dc: // 01ed:450c
    dx = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) - dx);
    if ((short)memoryAGet16(ds, si + 6) < 0x0000)
        goto loc_63d6;
    if ((short)memoryAGet16(ds, si + 2) < 0x0000)
        goto loc_63d9;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
    if (memoryAGet16(ds, si + 4) < 0x000f)
        goto loc_640c;
    memoryASet16(ds, si + 4, 0x0000);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) & 0x0003);
loc_640c: // 01ed:453c
    push(si);
    bx = 0x3b7a;
    ax = memoryAGet16(ds, si + 2);
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_6426;
    ax += 0x0084;
loc_6426: // 01ed:4556
    ax += 0x0009;
    di = memoryAGet16(ds, si);
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    si = pop();
loc_6435: // 01ed:4565
    cx = pop();
    si += 0x0016;
    if (--cx)
        goto loc_6479;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_6478;
    if (memoryAGet16(ds, 0x3a4c) == 0x7fff)
        goto loc_6478;
    memoryASet16(ds, 0x3a4c, 0x7fff);
    dx = memoryAGet16(ds, 0x3c74);
    dx &= 0x0004;
    if (!dx)
        goto loc_6478;
    dx = memoryAGet16(ds, 0x3c78);
    dx &= 0x0020;
    if (!dx)
        goto loc_6478;
    si = memoryAGet16(ds, 0x3a4a);
    memoryASet16(ds, si + 6, 0xffff);
    memoryASet16(ds, si + 20, 0x7fff);
loc_6478: // 01ed:45a8
    return;
loc_6479: // 01ed:45a9
    goto loc_63a1;
loc_647c: // 01ed:45ac
    memoryASet16(ds, si + 4, 0x0000);
    memoryASet16(ds, si + 2, 0xffff);
    memoryASet16(ds, si + 6, 0x7fff);
    ax = memoryAGet16(ds, si + 18);
    ax += ax;
    bx = 0x3f9e;
    bx += ax;
    bx = memoryAGet16(ds, bx);
    memoryASet16(ds, bx + 14, memoryAGet16(ds, bx + 14) - 1);
    ax = memoryAGet16(ds, si + 8);
    dl = 0x2d;
    sub_57b4();
    ax = memoryAGet16(ds, si + 8);
    push(ax);
    dx = 0x0001;
    sub_614e();
    ax = pop();
    memoryASet16(ds, si + 16, cx);
    push(ax);
    dx = 0x0100;
    sub_614e();
    ax = pop();
    memoryASet16(ds, si + 12, cx);
    push(ax);
    dx = 0x00ff;
    sub_614e();
    ax = pop();
    memoryASet16(ds, si + 14, cx);
    push(ax);
    dx = 0xff00;
    sub_614e();
    ax = pop();
    memoryASet16(ds, si + 10, cx);
    push(ax);
    push(si);
    ax = 0x0004;
    sub_8ca1();
    si = pop();
    ax = pop();
    goto loc_6435;
loc_64eb: // 01ed:461b
    goto loc_65b4;
loc_64ee: // 01ed:461e
    dx = memoryAGet16(ds, 0x001e);
    dx = 0x0006;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + dx);
    if (memoryAGet16(ds, si + 4) < 0x0005)
        goto loc_6511;
    memoryASet16(ds, si + 4, 0x0000);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    if (memoryAGet16(ds, si + 2) < 0xfff5)
        goto loc_64eb;
loc_6511: // 01ed:4641
    push(si);
    bx = 0x3b82;
    ax = memoryAGet16(ds, si + 2);
    ax = -ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    ax += 0x0034;
    di = memoryAGet16(ds, si);
    sub_4ffe();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = memoryAGet16(ds, si + 8);
    dx = 0x0001;
    cx = memoryAGet16(ds, si + 16);
    sub_68e8();
    di = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 16);
    dx = 0x0004;
    ax = 0x0090;
    sub_65c6();
    ax = memoryAGet16(ds, si + 8);
    dx = 0x0100;
    cx = memoryAGet16(ds, si + 12);
    sub_68e8();
    di = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 12);
    dx = 0x0800;
    ax = 0x0030;
    sub_65c6();
    ax = memoryAGet16(ds, si + 8);
    dx = 0xff00;
    cx = memoryAGet16(ds, si + 10);
    sub_68e8();
    di = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 10);
    dx = 0xf800;
    ax = 0x0000;
    sub_65c6();
    ax = memoryAGet16(ds, si + 8);
    dx = 0x00ff;
    cx = memoryAGet16(ds, si + 14);
    sub_68e8();
    di = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 14);
    dx = 0xfffc;
    ax = 0x0060;
    sub_65c6();
    goto loc_6435;
loc_65b4: // 01ed:46e4
    memoryASet16(ds, si, 0xffff);
    ax = memoryAGet16(ds, si + 8);
    dl = 0x2e;
    sub_57b4();
    goto loc_6435;
}
void sub_65c6() // 01ed:46f6
{
    if (memoryAGet16(ds, 0x26f2) != 0x0002)
        goto loc_65e5;
    bx = dx;
    bx &= 0x0007;
    if (bx == 0x0004)
        goto loc_65e5;
    if (dx != 0x0800)
        goto loc_65e2;
    dx = 0x0400;
    goto loc_65e5;
loc_65e2: // 01ed:4712
    dx = 0xfc00;
loc_65e5: // 01ed:4715
    bx = 0x3b9e;
    bx += ax;
    ax = memoryAGet16(ds, si + 2);
    ax = -ax;
    ax += ax;
    ax += ax;
    bx += ax;
    push(cx);
    if ((short)cx >= 0x0000)
        goto loc_65ff;
    cx = -cx;
    cx--;
loc_65ff: // 01ed:472f
    ax = memoryAGet16(ds, bx);
    push(bx);
    if (!cx)
        goto loc_6621;
loc_6609: // 01ed:4739
    push(cx);
    push(si);
    di += dx;
    push(di);
    push(ax);
    push(dx);
    sub_4ffe();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    dx = pop();
    ax = pop();
    di = pop();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_6609;
loc_6621: // 01ed:4751
    bx = pop();
    cx = pop();
    if ((short)cx >= 0x0000)
        goto loc_663c;
    push(si);
    di += dx;
    push(di);
    ax = memoryAGet16(ds, bx + 2);
    sub_4ffe();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    di = pop();
    si = pop();
loc_663c: // 01ed:476c
    return;
}
void sub_663d() // 01ed:476d
{
    if ((short)memoryAGet16(ds, si + 10) < 0x0000)
        goto loc_665f;
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 0x0001);
    if (memoryAGet16(ds, si + 10) < 0x000a)
        goto loc_665f;
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + 1);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) & 0x0003);
loc_665f: // 01ed:478f
    return;
}
void sub_6660() // 01ed:4790
{
    bx = memoryAGet16(ds, 0x3a54);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + bx);
    cl = memoryAGet(ds, si + 5);
    ch = 0x00;
    memoryASet(ds, si + 5, 0x00);
loc_6673: // 01ed:47a3
    push(cx);
    sub_5f43();
    sub_670c();
    sub_663d();
    sub_5fd7();
    if (dx)
        goto loc_6689;
    cx = pop();
    if (--cx)
        goto loc_6673;
    return;
loc_6689: // 01ed:47b9
    cx = pop();
}
void sub_668b() // 01ed:47bb
{
    bx = memoryAGet16(ds, 0x3a54);
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + bx);
    cl = memoryAGet(ds, si + 5);
    ch = 0x00;
    memoryASet(ds, si + 5, 0x00);
loc_669e: // 01ed:47ce
    push(cx);
    sub_5f43();
    sub_67c2();
    sub_663d();
    sub_5fd7();
    if (dx)
        goto loc_66b4;
    cx = pop();
    if (--cx)
        goto loc_669e;
    return;
loc_66b4: // 01ed:47e4
    cx = pop();
}
void sub_66b6() // 01ed:47e6
{
    bx = memoryAGet16(ds, 0x3a54);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + bx);
    cl = memoryAGet(ds, si + 7);
    ch = 0x00;
    memoryASet(ds, si + 7, 0x00);
loc_66c9: // 01ed:47f9
    push(cx);
    sub_5f43();
    sub_681d();
    sub_663d();
    sub_5fd7();
    if (dx)
        goto loc_66df;
    cx = pop();
    if (--cx)
        goto loc_66c9;
    return;
loc_66df: // 01ed:480f
    cx = pop();
}
void sub_66e1() // 01ed:4811
{
    bx = memoryAGet16(ds, 0x3a54);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + bx);
    cl = memoryAGet(ds, si + 7);
    ch = 0x00;
    memoryASet(ds, si + 7, 0x00);
loc_66f4: // 01ed:4824
    push(cx);
    sub_5f43();
    sub_6767();
    sub_663d();
    sub_5fd7();
    if (dx)
        goto loc_670a;
    cx = pop();
    if (--cx)
        goto loc_66f4;
    return;
loc_670a: // 01ed:483a
    cx = pop();
}
void sub_670c() // 01ed:483c
{
    ax = memoryAGet16(ds, 0x3a58);
    if (ax)
        goto loc_671e;
    al = memoryAGet(ds, 0x3f97);
    sub_6878();
    if (al != 0x2e)
        goto loc_6736;
loc_671e: // 01ed:484e
    ax = memoryAGet16(ds, 0x3a5a);
    if (!ax)
        goto loc_6762;
    if ((short)ax >= 0x0000)
        goto loc_672f;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_6762;
    // gap 1 bytes // gap 1 bytes
loc_672f: // 01ed:485f
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    goto loc_6762;
    // gap 1 bytes // gap 1 bytes
loc_6736: // 01ed:4866
    ax = memoryAGet16(ds, 0x3a5a);
    if (!ax)
        goto loc_6766;
    if ((short)ax >= 0x0000)
        goto loc_6751;
    al = memoryAGet(ds, 0x3f96);
    sub_6878();
    if (al != 0x2e)
        goto loc_6766;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    goto loc_6766;
    // gap 1 bytes // gap 1 bytes
loc_6751: // 01ed:4881
    al = memoryAGet(ds, 0x3f98);
    sub_6878();
    if (al != 0x2e)
        goto loc_6766;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_6766;
    // gap 1 bytes // gap 1 bytes
loc_6762: // 01ed:4892
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
loc_6766: // 01ed:4896
    return;
}
void sub_6767() // 01ed:4897
{
    ax = memoryAGet16(ds, 0x3a5a);
    if (ax)
        goto loc_6779;
    al = memoryAGet(ds, 0x3f99);
    sub_6878();
    if (al != 0x2e)
        goto loc_6791;
loc_6779: // 01ed:48a9
    ax = memoryAGet16(ds, 0x3a58);
    if (!ax)
        goto loc_67bd;
    if ((short)ax >= 0x0000)
        goto loc_678a;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
    goto loc_67bd;
    // gap 1 bytes // gap 1 bytes
loc_678a: // 01ed:48ba
    memoryASet16(ds, si, memoryAGet16(ds, si) - 1);
    goto loc_67bd;
    // gap 1 bytes // gap 1 bytes
loc_6791: // 01ed:48c1
    ax = memoryAGet16(ds, 0x3a58);
    if (!ax)
        goto loc_67c1;
    if ((short)ax >= 0x0000)
        goto loc_67ac;
    al = memoryAGet(ds, 0x3f9a);
    sub_6878();
    if (al != 0x2e)
        goto loc_67c1;
    memoryASet16(ds, si, memoryAGet16(ds, si) - 1);
    goto loc_67c1;
    // gap 1 bytes // gap 1 bytes
loc_67ac: // 01ed:48dc
    al = memoryAGet(ds, 0x3f98);
    sub_6878();
    if (al != 0x2e)
        goto loc_67c1;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
    goto loc_67c1;
    // gap 1 bytes // gap 1 bytes
loc_67bd: // 01ed:48ed
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
loc_67c1: // 01ed:48f1
    return;
}
void sub_67c2() // 01ed:48f2
{
    ax = memoryAGet16(ds, 0x3a58);
    if (ax)
        goto loc_67d4;
    al = memoryAGet(ds, 0x3f9b);
    sub_6878();
    if (al != 0x2e)
        goto loc_67ec;
loc_67d4: // 01ed:4904
    ax = memoryAGet16(ds, 0x3a5a);
    if (!ax)
        goto loc_6818;
    if ((short)ax >= 0x0000)
        goto loc_67e5;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_6818;
    // gap 1 bytes // gap 1 bytes
loc_67e5: // 01ed:4915
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    goto loc_6818;
    // gap 1 bytes // gap 1 bytes
loc_67ec: // 01ed:491c
    ax = memoryAGet16(ds, 0x3a5a);
    if (!ax)
        goto loc_681c;
    if ((short)ax >= 0x0000)
        goto loc_6807;
    al = memoryAGet(ds, 0x3f94);
    sub_6878();
    if (al != 0x2e)
        goto loc_681c;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
    goto loc_681c;
    // gap 1 bytes // gap 1 bytes
loc_6807: // 01ed:4937
    al = memoryAGet(ds, 0x3f9a);
    sub_6878();
    if (al != 0x2e)
        goto loc_681c;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + 1);
    goto loc_681c;
    // gap 1 bytes // gap 1 bytes
loc_6818: // 01ed:4948
    memoryASet16(ds, si, memoryAGet16(ds, si) - 1);
loc_681c: // 01ed:494c
    return;
}
void sub_681d() // 01ed:494d
{
    ax = memoryAGet16(ds, 0x3a5a);
    if (ax)
        goto loc_682f;
    al = memoryAGet(ds, 0x3f95);
    sub_6878();
    if (al != 0x2e)
        goto loc_6847;
loc_682f: // 01ed:495f
    ax = memoryAGet16(ds, 0x3a58);
    if (!ax)
        goto loc_6873;
    if ((short)ax >= 0x0000)
        goto loc_6840;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
    goto loc_6873;
    // gap 1 bytes // gap 1 bytes
loc_6840: // 01ed:4970
    memoryASet16(ds, si, memoryAGet16(ds, si) - 1);
    goto loc_6873;
    // gap 1 bytes // gap 1 bytes
loc_6847: // 01ed:4977
    ax = memoryAGet16(ds, 0x3a58);
    if (!ax)
        goto loc_6877;
    if ((short)ax >= 0x0000)
        goto loc_6862;
    al = memoryAGet(ds, 0x3f94);
    sub_6878();
    if (al != 0x2e)
        goto loc_6877;
    memoryASet16(ds, si, memoryAGet16(ds, si) - 1);
    goto loc_6877;
    // gap 1 bytes // gap 1 bytes
loc_6862: // 01ed:4992
    al = memoryAGet(ds, 0x3f96);
    sub_6878();
    if (al != 0x2e)
        goto loc_6877;
    memoryASet16(ds, si, memoryAGet16(ds, si) + 1);
    goto loc_6877;
    // gap 1 bytes // gap 1 bytes
loc_6873: // 01ed:49a3
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) - 1);
loc_6877: // 01ed:49a7
    return;
}
void sub_6878() // 01ed:49a8
{
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_68aa;
    dx = memoryAGet16(ds, si + 22);
    dx &= 0x0001;
    if (!dx)
        goto loc_689a;
    if (al == 0x45)
        goto loc_68b6;
    if (al < 0x41)
        goto loc_689a;
    if (al > 0x56)
        goto loc_689a;
    goto loc_68b6;
    // gap 1 bytes // gap 1 bytes
loc_689a: // 01ed:49ca
    dx = memoryAGet16(ds, si + 22);
    dx &= 0x0002;
    if (!dx)
        goto loc_68aa;
    if (al == 0x2b)
        goto loc_68b6;
loc_68aa: // 01ed:49da
    if (al == 0x2d)
        goto loc_68b6;
    if (al < 0x61)
        goto loc_68b9;
    if (al > 0x75)
        goto loc_68b9;
loc_68b6: // 01ed:49e6
    al = 0x2e;
    return;
loc_68b9: // 01ed:49e9
    return;
}
void sub_68ba() // 01ed:49ea
{
    ax = memoryAGet16(ds, 0x3a56);
    ax += memoryAGet16(ds, 0x001e);
    if (ax < 0x0014)
        goto loc_68e4;
    ax = 0x0000;
    si = 0x3fa6;
    memoryASet(ds, 0x3a5c, ~memoryAGet(ds, 0x3a5c));
    if (memoryAGet(ds, 0x3a5c))
        goto loc_68da;
    si = 0x3fa9;
loc_68da: // 01ed:4a0a
    push(ax);
    al = 0x20;
    cx = 0x0001;
    sub_2397();
    ax = pop();
loc_68e4: // 01ed:4a14
    memoryASet16(ds, 0x3a56, ax);
}
void sub_68e8() // 01ed:4a18
{
    if ((short)cx >= 0x0000)
        goto loc_68ef;
    cx = -cx;
loc_68ef: // 01ed:4a1f
    cx++;
    push(si);
    si = memoryAGet16(ds, 0x3a52);
loc_68f5: // 01ed:4a25
    memoryASet16(ds, si, ax);
    si += 0x0002;
    al += dl;
    ah += dh;
    if (--cx)
        goto loc_68f5;
    memoryASet16(ds, 0x3a52, si);
    si = pop();
}
void sub_6908() // 01ed:4a38
{
loc_6908: // 01ed:4a38
    push(cx);
    push(ax);
    push(dx);
    si = 0x4d50;
    cx = 0x000f;
loc_6911: // 01ed:4a41
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_6920;
    si += 0x0024;
    if (--cx)
        goto loc_6911;
    goto loc_6976;
    // gap 1 bytes // gap 1 bytes
loc_6920: // 01ed:4a50
    push(dx);
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0xffe7);
    ax = pop();
    memoryASet16(ds, si + 12, ax);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    di = 0x42d4;
    di += ax;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, si + 14, ax);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    memoryASet16(ds, 0x4200, memoryAGet16(ds, 0x4200) + 1);
loc_6976: // 01ed:4aa6
    dx = pop();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_6908;
}
void sub_697c() // 01ed:4aac
{
    si = 0x4d50;
    cx = 0x000f;
loc_6982: // 01ed:4ab2
    memoryASet16(ds, si, 0xffff);
    memoryASet16(ds, si + 24, 0x0004);
    memoryASet16(ds, si + 26, 0x0012);
    si += 0x0024;
    if (--cx)
        goto loc_6982;
}
void sub_699a() // 01ed:4aca
{
    sub_697c();
    si = 0x4d50;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_69b0;
    bx = memoryAGet16(ds, 0x4f78);
    bx += 0x0008;
    goto loc_69c1;
loc_69b0: // 01ed:4ae0
    bx = 0x42b4;
    ax = memoryAGet16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    bx += ax;
    bx = memoryAGet16(ds, bx);
loc_69c1: // 01ed:4af1
    cx = memoryAGet16(ds, bx);
    if ((short)cx < 0x0000)
        goto loc_6a38;
    if (!cx)
        goto loc_6a38;
    bx += 0x0002;
loc_69cf: // 01ed:4aff
    push(cx);
    push(bx);
    sub_71c6();
    bx = pop();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0x0000);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 12, ax);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    di = 0x42d4;
    di += ax;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, si + 14, ax);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    memoryASet16(ds, 0x4200, memoryAGet16(ds, 0x4200) + 1);
    cx = pop();
    si += 0x0024;
    if (--cx)
        goto loc_69cf;
    bx += 0x0002;
    goto loc_69c1;
loc_6a38: // 01ed:4b68
    if (memoryAGet16(ds, 0x4f8a) != 0x0008)
        goto loc_6a42;
    sub_7912();
loc_6a42: // 01ed:4b72
    return;
}
void sub_6a43() // 01ed:4b73
{
    memoryASet16(ds, 0x4202, 0x0000);
    si = 0x4d50;
    cx = 0x000f;
loc_6a4f: // 01ed:4b7f
    push(cx);
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_6a5a;
    goto loc_6b1a;
loc_6a5a: // 01ed:4b8a
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_6a64;
    goto loc_6b2e;
loc_6a64: // 01ed:4b94
    ax = 0x0100;
    cx = memoryAGet16(ds, si + 14);
    dx = cx;
    dx &= 0x0004;
    if (!dx)
        goto loc_6a85;
    ax = 0x0200;
    dx = cx;
    cx &= 0x000c;
    if (cx != 0x000c)
        goto loc_6a85;
    ax = 0x0300;
loc_6a85: // 01ed:4bb5
    memoryASet16(ds, si + 16, memoryAGet16(ds, si + 16) + ax);
    cl = memoryAGet(ds, si + 17);
    ch = 0x00;
    memoryASet(ds, si + 17, 0x00);
loc_6a94: // 01ed:4bc4
    push(cx);
    sub_6c50();
    cx = pop();
    if (--cx)
        goto loc_6a94;
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_6ac5;
    ah = 0x00;
    bx += 0x0010;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_6ac5;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_6ac5: // 01ed:4bf5
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, si + 10);
    if ((short)ax < 0x0000)
        goto loc_6adc;
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
loc_6adc: // 01ed:4c0c
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 20, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 22, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    if (memoryAGet16(ds, si + 12) != 0x0017)
        goto loc_6b01;
    cx -= 0x0004;
loc_6b01: // 01ed:4c31
    sub_703a();
    if (ax)
        goto loc_6b0f;
    si += 0x0014;
    sub_2782();
loc_6b0f: // 01ed:4c3f
    si = pop();
    if (memoryAGet16(ds, si + 12) == 0x0017)
        goto loc_6b1a;
    sub_6bda();
loc_6b1a: // 01ed:4c4a
    cx = pop();
    si += 0x0024;
    if (--cx)
        goto loc_6b2b;
    if (memoryAGet16(ds, 0x4f8a) != 0x0008)
        goto loc_6b2a;
    sub_7d6b();
loc_6b2a: // 01ed:4c5a
    return;
loc_6b2b: // 01ed:4c5b
    goto loc_6a4f;
loc_6b2e: // 01ed:4c5e
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x0078)
        goto loc_6b93;
    memoryASet16(ds, si + 8, 0x0064);
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_6b93;
    if (memoryAGet16(ds, si + 10) == 0xffff)
        goto loc_6b8b;
    ax = memoryAGet16(ds, si + 10);
    bx = 0x422e;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + ax);
    bx = memoryAGet16(ds, bx + 2);
    if (!bx)
        goto loc_6b8b;
    memoryASet16(ds, si + 10, 0xffff);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 6, bx);
    goto loc_6b93;
loc_6b8b: // 01ed:4cbb
    memoryASet16(ds, si, 0xffff);
    goto loc_6b1a;
loc_6b93: // 01ed:4cc3
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 20, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 22, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0014;
    sub_2782();
    si = pop();
    goto loc_6b1a;
}
void sub_6bb9() // 01ed:4ce9
{
    push(bx);
    bx = 0x3e54;
loc_6bbd: // 01ed:4ced
    dx = memoryAGet16(ds, bx);
    bx += 0x0002;
    if (bx > memoryAGet16(ds, 0x3a52))
        goto loc_6bd0;
    if (dx == ax)
        goto loc_6bd5;
    goto loc_6bbd;
loc_6bd0: // 01ed:4d00
    dx = 0x0000;
    bx = pop();
    return;
loc_6bd5: // 01ed:4d05
    dx = 0xffff;
    bx = pop();
}
void sub_6bda() // 01ed:4d0a
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    dx += 0x0008;
    cx += 0x0008;
    sub_581f();
    sub_6bb9();
    if (dx == 0xffff)
        goto loc_6bf4;
    return;
loc_6bf4: // 01ed:4d24
    bx = 0x42d6;
    ax = memoryAGet16(ds, si + 12);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ds, si + 12);
    cl = 0x04;
    ax <<= cl;
    bx = 0x42d4;
    bx += ax;
    ax = memoryAGet16(ds, bx + 8);
    if (!ax)
        goto loc_6c27;
    ax += memoryAGet16(ds, 0x4202);
loc_6c27: // 01ed:4d57
    memoryASet16(ds, si + 10, ax);
    if (memoryAGet16(ds, 0x4202) < 0x0006)
        goto loc_6c36;
    memoryASet16(ds, 0x4202, memoryAGet16(ds, 0x4202) - 1);
loc_6c36: // 01ed:4d66
    memoryASet16(ds, 0x4202, memoryAGet16(ds, 0x4202) + 1);
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 8, 0x0050);
    memoryASet16(ds, 0x4200, memoryAGet16(ds, 0x4200) - 1);
    memoryASet(ds, 0x4f94, 0xff);
}
void sub_6c50() // 01ed:4d80
{
    if ((short)memoryAGet16(ds, si + 10) < 0x0000)
        goto loc_6c85;
    ax = memoryAGet16(ds, si + 10);
    sub_6f24();
    if (!dx)
        goto loc_6c67;
    memoryASet16(ds, si + 10, ax);
loc_6c67: // 01ed:4d97
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0001;
    if (!ax)
        goto loc_6c88;
    ax = memoryAGet16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (!ax)
        goto loc_6c99;
    goto loc_6d17;
loc_6c85: // 01ed:4db5
    goto loc_6d37;
loc_6c88: // 01ed:4db8
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (!ax)
        goto loc_6c99;
    goto loc_6d17;
loc_6c99: // 01ed:4dc9
    cx = memoryAGet16(ds, si + 14);
    if (!(cx & 0x0040))
        goto loc_6ca6;
    sub_6d4d();
loc_6ca6: // 01ed:4dd6
    ax = memoryAGet16(ds, si + 14);
    ax &= 0x0010;
    if (!ax)
        goto loc_6cc7;
    if (!memoryAGet16(ds, si + 18))
        goto loc_6cbf;
    memoryASet16(ds, si + 18, memoryAGet16(ds, si + 18) - 1);
    goto loc_6cc7;
loc_6cbf: // 01ed:4def
    sub_6d9c();
    if (!dx)
        goto loc_6cf8;
loc_6cc7: // 01ed:4df7
    ax = 0x0064;
    sub_587c();
    dx = memoryAGet16(ds, si + 12);
    cl = 0x04;
    dx <<= cl;
    di = 0x42d4;
    di += dx;
    dx = memoryAGet16(ds, di + 10);
    if (!dx)
        goto loc_6cf8;
    if (dx < ax)
        goto loc_6cf8;
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
    if ((short)ax < 0x0000)
        goto loc_6d37;
    goto loc_6d17;
loc_6cf8: // 01ed:4e28
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6d17;
    memoryASet16(ds, si + 10, ax);
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
    if ((short)ax < 0x0000)
        goto loc_6d37;
loc_6d17: // 01ed:4e47
    ax = memoryAGet16(ds, si + 10);
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + dx);
loc_6d36: // 01ed:4e66
    return;
loc_6d37: // 01ed:4e67
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 1);
    if (memoryAGet16(ds, si + 10))
        goto loc_6d36;
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
}
void sub_6d4d() // 01ed:4e7d
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = memoryAGet16(ds, si + 10);
    bx = 0x4444;
    cl = 0x03;
    dx <<= cl;
    bx += dx;
    dx = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0x41fa, ax);
    memoryASet16(ds, 0x41fc, dx);
loc_6d70: // 01ed:4ea0
    ax = memoryAGet16(ds, 0x41fa);
    dx = memoryAGet16(ds, 0x41fc);
    al += dl;
    ah += dh;
    memoryASet16(ds, 0x41fa, ax);
    memoryASet16(ds, 0x41fc, dx);
    sub_5832();
    if (al == 0x2b)
        goto loc_6d92;
    if (al == 0x2d)
        goto loc_6d92;
    if (al == 0x2e)
        goto loc_6d70;
    return;
loc_6d92: // 01ed:4ec2
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 1);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) & 0x0003);
}
void sub_6d9c() // 01ed:4ecc
{
    dx = memoryAGet16(ds, 0x3c5e);
    cx = memoryAGet16(ds, 0x3c60);
    sub_581f();
    push(ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = pop();
    if (al == dl)
        goto loc_6e27;
    if (ah == dh)
        goto loc_6e0e;
    memoryASet16(ds, 0x41fa, ax);
    memoryASet16(ds, 0x41fc, dx);
    al -= dl;
    if ((char)al >= 0x00)
        goto loc_6dcb;
    al = -al;
loc_6dcb: // 01ed:4efb
    ah -= dh;
    if ((char)ah >= 0x00)
        goto loc_6dd4;
    ah = -ah;
loc_6dd4: // 01ed:4f04
    if (al > ah)
        goto loc_6e40;
    ax = memoryAGet16(ds, 0x41fa);
    dx = memoryAGet16(ds, 0x41fc);
    sub_6e89();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    ax = memoryAGet16(ds, 0x41fa);
    dx = memoryAGet16(ds, 0x41fc);
    sub_6e76();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    memoryASet16(ds, si + 18, 0x0004);
    dx = 0xffff;
    return;
loc_6e0e: // 01ed:4f3e
    sub_6e76();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    memoryASet16(ds, si + 18, 0x0004);
    dx = 0xffff;
loc_6e26: // 01ed:4f56
    return;
loc_6e27: // 01ed:4f57
    sub_6e89();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    memoryASet16(ds, si + 18, 0x0004);
    dx = 0xffff;
    return;
loc_6e40: // 01ed:4f70
    ax = memoryAGet16(ds, 0x41fa);
    dx = memoryAGet16(ds, 0x41fc);
    sub_6e76();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    ax = memoryAGet16(ds, 0x41fa);
    dx = memoryAGet16(ds, 0x41fc);
    sub_6e89();
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_6e26;
    memoryASet16(ds, si + 18, 0x0004);
    dx = 0xffff;
}
void sub_6e76() // 01ed:4fa6
{
    if (al >= dl)
        goto loc_6e82;
    memoryASet16(ds, si + 10, 0x0001);
    goto loc_6e88;
loc_6e82: // 01ed:4fb2
    memoryASet16(ds, si + 10, 0x0003);
loc_6e88: // 01ed:4fb8
    return;
}
void sub_6e89() // 01ed:4fb9
{
    if (ah >= dh)
        goto loc_6e95;
    memoryASet16(ds, si + 10, 0x0002);
    goto loc_6e9b;
loc_6e95: // 01ed:4fc5
    memoryASet16(ds, si + 10, 0x0000);
loc_6e9b: // 01ed:4fcb
    return;
}
void sub_6e9c() // 01ed:4fcc
{
    ax = memoryAGet16(ds, 0x4d4e);
    if (!ax)
        goto loc_6eba;
    ax--;
    if (!ax)
        goto loc_6eae;
    ax++;
    sub_587c();
loc_6eae: // 01ed:4fde
    ax += ax;
    bx = 0x4d3c;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    return;
loc_6eba: // 01ed:4fea
    ax = 0xffff;
}
void sub_6ebe() // 01ed:4fee
{
    if ((short)ax < 0x0000)
        goto loc_6f14;
    push(ax);
    bx = 0x4444;
    ax += ax;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx + 4);
    push(ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    memoryASet16(ds, 0x41fe, ax);
    dx = pop();
    al += dl;
    ah += dh;
    sub_5832();
    dx = pop();
    cx = memoryAGet16(ds, si + 14);
    if (cx & 0x0080)
        goto loc_6eff;
    if (al == 0x2b)
        goto loc_6f14;
loc_6eff: // 01ed:502f
    if (cx & 0x0001)
        goto loc_6f10;
    if (al < 0x41)
        goto loc_6f10;
    if (al > 0x55)
        goto loc_6f10;
    goto loc_6f14;
    // gap 1 bytes // gap 1 bytes
loc_6f10: // 01ed:5040
    if (al != 0x2a)
        goto loc_6f1e;
loc_6f14: // 01ed:5044
    ax = 0x0004;
    sub_587c();
    dx = 0xffff;
    return;
loc_6f1e: // 01ed:504e
    ax = dx;
    dx = 0x0000;
}
void sub_6f24() // 01ed:5054
{
    if ((short)ax < 0x0000)
        goto loc_6f56;
    push(ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    memoryASet16(ds, 0x41fe, ax);
    sub_5832();
    dx = pop();
    cx = memoryAGet16(ds, si + 14);
    if (cx & 0x0080)
        goto loc_6f50;
    if (al == 0x2b)
        goto loc_6f56;
loc_6f50: // 01ed:5080
    ax = dx;
    dx = 0x0000;
    return;
loc_6f56: // 01ed:5086
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    dx -= 0x0008;
    cx -= 0x0018;
    dx += 0x0008;
    cx += 0x0008;
    dx &= 0x000f;
    cx &= 0x000f;
    ax = memoryAGet16(ds, si + 10);
    if (!(ax & 0x0001))
        goto loc_6f87;
    ax = 0x0003;
    if (dx < 0x0008)
        goto loc_6f92;
    ax = 0x0001;
    goto loc_6f92;
    // gap 1 bytes // gap 1 bytes
loc_6f87: // 01ed:50b7
    ax = 0x0000;
    if (cx < 0x0008)
        goto loc_6f92;
    ax = 0x0002;
loc_6f92: // 01ed:50c2
    memoryASet16(ds, si + 10, ax);
    dx = 0xffff;
}
void sub_6f9a() // 01ed:50ca
{
    bx = 0x4d3c;
    memoryASet16(ds, bx + 18, 0x0000);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    di = 0x4444;
    cx = 0x0004;
loc_6fba: // 01ed:50ea
    push(cx);
    push(ax);
    dx = memoryAGet16(ds, di + 4);
    ah += dh;
    al += dl;
    sub_5832();
    if (al == 0x2a)
        goto loc_6fff;
    if (al == 0x2b)
        goto loc_6fff;
    cx = memoryAGet16(ds, si + 14);
    cx &= 0x0001;
    if (cx)
        goto loc_6fe5;
    if (al < 0x41)
        goto loc_6fe5;
    if (al > 0x55)
        goto loc_6fe5;
    goto loc_6fff;
loc_6fe5: // 01ed:5115
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    memoryASet16(ds, 0x4d4e, memoryAGet16(ds, 0x4d4e) + 1);
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    memoryASet16(ds, 0x4d4e, memoryAGet16(ds, 0x4d4e) + 1);
loc_6fff: // 01ed:512f
    ax = pop();
    cx = pop();
    di += 0x0008;
    if (--cx)
        goto loc_6fba;
    cx = memoryAGet16(ds, si + 14);
    if (cx & 0x0002)
        goto loc_701a;
    memoryASet16(ds, bx, 0xfff8);
    memoryASet16(ds, 0x4d4e, memoryAGet16(ds, 0x4d4e) + 1);
loc_701a: // 01ed:514a
    return;
}
void sub_701b() // 01ed:514b
{
    push(si);
    push(ax);
    dx = ax;
    si = 0x4204;
loc_7022: // 01ed:5152
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_702e;
    if (ax == dx)
        goto loc_7034;
    goto loc_7022;
loc_702e: // 01ed:515e
    dx = 0x0000;
    ax = pop();
    si = pop();
    return;
loc_7034: // 01ed:5164
    dx = 0xffff;
    ax = pop();
    si = pop();
}
void sub_703a() // 01ed:516a
{
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_7065;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_7069;
    ax = memoryAGet16(ds, 0x203e);
    bx = memoryAGet16(ds, si);
    bx += 0x0010;
    ax -= 0x0080;
    if (ax > bx)
        goto loc_7087;
    ax = memoryAGet16(ds, 0x203e);
    ax += 0x0080;
    if (ax < memoryAGet16(ds, si))
        goto loc_7087;
loc_7065: // 01ed:5195
    ax = 0x0000;
    return;
loc_7069: // 01ed:5199
    ax = memoryAGet16(ds, 0x203e);
    bx = memoryAGet16(ds, si + 2);
    ax -= 0x007c;
    if (ax > bx)
        goto loc_7087;
    ax = memoryAGet16(ds, 0x203e);
    ax += 0x006c;
    if (ax < memoryAGet16(ds, si + 2))
        goto loc_7087;
    ax = 0x0000;
    return;
loc_7087: // 01ed:51b7
    ax = 0xffff;
}
void sub_708b() // 01ed:51bb
{
    si = 0x3c5e;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_70cb;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_70cb;
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_70b1;
    dx = memoryAGet16(ds, si + 22);
    dx &= 0x0008;
    if (!dx)
        goto loc_70b1;
    goto loc_70b4;
loc_70b1: // 01ed:51e1
    sub_7165();
loc_70b4: // 01ed:51e4
    sub_7111();
    if (!memoryAGet16(ds, 0x4f88))
        goto loc_70cb;
    if ((short)memoryAGet16(ds, si + 8) >= 0x0000)
        goto loc_70cb;
    ax = 0x0005;
    sub_8c10();
loc_70cb: // 01ed:51fb
    si = 0x3c7e;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_70e2;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_70e2;
    sub_7165();
    sub_7111();
loc_70e2: // 01ed:5212
    si = 0x3c9e;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_70f9;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_70f9;
    sub_7165();
    sub_7111();
loc_70f9: // 01ed:5229
    si = 0x3cbe;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_7110;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_7110;
    sub_7165();
    sub_7111();
loc_7110: // 01ed:5240
    return;
}
void sub_7111() // 01ed:5241
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x4d50;
    cx = 0x000f;
loc_7124: // 01ed:5254
    push(cx);
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_714a;
    if ((short)memoryAGet16(ds, bx + 12) < 0x0000)
        goto loc_714a;
    push(dx);
    dx = memoryAGet16(ds, bx);
    dx += 0x0008;
    cx = memoryAGet16(ds, bx + 2);
    cx += 0x0008;
    sub_581f();
    dx = pop();
    if (ax == dx)
        goto loc_7151;
loc_714a: // 01ed:527a
    bx += 0x0024;
    cx = pop();
    if (--cx)
        goto loc_7124;
    return;
loc_7151: // 01ed:5281
    cx = pop();
    memoryASet16(ds, si + 8, 0xffff);
    memoryASet16(ds, si + 10, 0x0000);
    ax = 0x0000;
    sub_8ca1();
}
void sub_7165() // 01ed:5295
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x3e54;
loc_7175: // 01ed:52a5
    ax = memoryAGet16(ds, bx);
    bx += 0x0002;
    if (bx > memoryAGet16(ds, 0x3a52))
        goto loc_7188;
    if (dx == ax)
        goto loc_7189;
    goto loc_7175;
loc_7188: // 01ed:52b8
    return;
loc_7189: // 01ed:52b9
    memoryASet16(ds, si + 8, 0xffff);
    memoryASet16(ds, si + 10, 0x0000);
    ax = 0x0000;
    sub_8ca1();
}
void sub_71c6() // 01ed:52f6
{
loc_71c6: // 01ed:52f6
    ax = memoryAGet16(ds, 0x26f6);
    sub_587c();
    push(ax);
    ax = memoryAGet16(ds, 0x26f4);
    sub_587c();
    dx = pop();
    ah = dl;
    bx = ax;
    sub_5832();
    if (al != 0x2e)
        goto loc_71c6;
    ax = bx;
    sub_701b();
    if (dx)
        goto loc_71c6;
}
void sub_71ea() // 01ed:531a
{
    memoryASet16(ds, 0x4f8e, 0x0003);
    memoryASet16(ds, 0x3a50, 0x0000);
    ax = 0x0005;
    sub_77c8();
    memoryASet(ds, 0x4f97, 0xff);
    ax = 0x0004;
    sub_77c8();
loc_7208: // 01ed:5338
    if (memoryAGet16(ds, 0x4f8a) != 0x0001)
        goto loc_7212;
    sub_4155();
loc_7212: // 01ed:5342
    si = 0x4fbc;
    bx = memoryAGet16(ds, 0x4f88);
    bx += bx;
    si = memoryAGet16(ds, bx + si);
    ax = lodsw<DS_SI>();
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    memoryASet16(ds, 0x0012, 0x0000);
    si = 0x3c5e;
    memoryASet16(ds, si + 22, 0x0000);
loc_723a: // 01ed:536a
    if (memoryAGet16(ds, 0x4f88) != 0x0008)
        goto loc_725b;
    if (memoryAGet16(ds, 0x4f8a) != 0x0008)
        goto loc_725b;
    if (!memoryAGet(ds, 0x4f97))
        goto loc_725b;
    ax = 0x0006;
    sub_77c8();
    memoryASet(ds, 0x4f97, 0x00);
loc_725b: // 01ed:538b
    if (memoryAGet16(ds, 0x4f88) != 0x0008)
        goto loc_726c;
    if (memoryAGet16(ds, 0x4f8a) != 0x0008)
        goto loc_726c;
    goto loc_727f;
    // gap 1 bytes // gap 1 bytes
loc_726c: // 01ed:539c
    if (memoryAGet(ds, 0x4f97))
        goto loc_727f;
    ax = 0x0005;
    sub_77c8();
    memoryASet(ds, 0x4f97, 0xff);
loc_727f: // 01ed:53af
    ax = memoryAGet16(ds, 0x3c6a);
    memoryASet16(ds, 0x4f72, ax);
    ax = memoryAGet16(ds, 0x3c70);
    memoryASet16(ds, 0x4f74, ax);
    ax = memoryAGet16(ds, 0x3a54);
    memoryASet16(ds, 0x4f76, ax);
    si = 0x4fbc;
    bx = memoryAGet16(ds, 0x4f88);
    bx += bx;
    si = memoryAGet16(ds, bx + si);
    si += 0x0002;
    bx = memoryAGet16(ds, 0x4f8a);
    bx += bx;
    ax = memoryAGet16(ds, bx + si);
    memoryASet16(ds, 0x4f78, ax);
    sub_4279();
    sub_2fcb();
    sub_2fdd();
    ax = 0x3e54;
    memoryASet16(ds, 0x3a52, ax);
    sub_4f14();
    si = 0x3c5e;
    memoryASet16(ds, si, 0xffff);
    memoryASet16(ds, si + 32, 0xffff);
    memoryASet16(ds, si + 64, 0xffff);
    memoryASet16(ds, si + 96, 0xffff);
    si = 0x3c5e;
    ax = 0x0101;
    sub_57d2();
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 14, 0x0000);
    memoryASet16(ds, si + 24, 0x0000);
    memoryASet16(ds, si + 26, 0x0000);
    memoryASet16(ds, si + 28, 0x0000);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 8, 0x0000);
    memoryASet16(ds, si + 22, memoryAGet16(ds, si + 22) & 0xfff7);
    memoryASet16(ds, si + 20, 0x0000);
    memoryASet(ds, 0x0023, 0xff);
    ax = 0x0004;
    memoryASet16(ds, 0x37ce, ax);
    ax = 0x0000;
    memoryASet16(ds, 0x37d0, ax);
    memoryASet16(ds, 0x204c, 0xffff);
    ax = memoryAGet16(ds, 0x26f2);
    ax += ax;
    si = 0x4fb6;
    si += ax;
    si = memoryAGet16(ds, si);
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    di = 0x0726;
    cx = 0x01b8;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    sub_50e9();
    sub_4f8b();
    sub_76bc();
    sub_2c65();
    sub_2a67();
    memoryASet16(ds, 0x4200, 0x0000);
    sub_699a();
    memoryASet16(ds, 0x4f6c, 0x0036);
    sub_5a41();
    sub_6a43();
    memoryASet(ds, 0x4f94, 0x00);
    sub_2ad4();
    sub_2318();
    sub_2ad4();
    sub_51ff();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x000c;
    dx = memoryAGet16(ds, 0x4f8a);
    if (dx & 0x0001)
        goto loc_73ac;
    ax = 0x000d;
    if (memoryAGet16(ds, 0x4f8a) != 0x0008)
        goto loc_73ac;
    ax = 0x000b;
    memoryASet(ds, 0x4f94, 0xff);
loc_73ac: // 01ed:54dc
    sub_8c10();
    memoryASet16(ds, 0x4f86, 0x0000);
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memoryASet16(ds, 0x4f80, 0x3039);
    memoryASet16(ds, 0x4f82, 0x3039);
    memoryASet16(ds, 0x4f7e, 0x3039);
    memoryASet16(ds, 0x4f84, 0x3039);
    memoryASet16(ds, 0x3a4e, 0x0000);
    memoryASet16(ds, 0x4f7a, 0x0000);
    memoryASet16(ds, 0x4f7c, 0x0000);
    memoryASet(ds, 0x0023, 0x00);
    memoryASet16(ds, 0x204c, 0x0000);
    memoryASet16(ds, 0x4f6c, 0x0ca8);
    memoryASet(ds, 0x0020, 0x00);
loc_7407: // 01ed:5537
    sub_2bfb();
    sub_281e();
    sub_552a();
    sub_5efa();
    sub_638f();
    sub_59d8();
    sub_6315();
    sub_7690();
    si = 0x3c5e;
    sub_5dce();
    sub_6a43();
    sub_5a41();
    sub_2fef();
    sub_770c();
    sub_2ad4();
    if (memoryAGet(ds, 0x2050))
        goto loc_7441;
    sub_708b();
    goto loc_746d;
    // gap 1 bytes // gap 1 bytes
loc_7441: // 01ed:5571
    ax = 0x0000;
    al = memoryAGet(ds, 0x0020);
    if (al < 0x02)
        goto loc_7459;
    if (al > 0x09)
        goto loc_7459;
    ax--;
    memoryASet16(ds, 0x4f8a, ax);
    memoryASet16(ds, 0x4f7c, 0x0003);
loc_7459: // 01ed:5589
    if (al < 0x3b)
        goto loc_746d;
    if (al > 0x42)
        goto loc_746d;
    ax -= 0x003a;
    memoryASet16(ds, 0x4f88, ax);
    memoryASet16(ds, 0x4f7c, 0x0004);
loc_746d: // 01ed:559d
    if (!memoryAGet16(ds, 0x4f7c))
        goto loc_7477;
    goto loc_74f9;
loc_7477: // 01ed:55a7
    si = 0x3c5e;
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_7492;
    memoryASet16(ds, 0x4f7a, memoryAGet16(ds, 0x4f7a) + 1);
    if (memoryAGet16(ds, 0x4f7a) < 0x0012)
        goto loc_7492;
    memoryASet16(ds, 0x4f7c, 0x0001);
loc_7492: // 01ed:55c2
    if (memoryAGet16(ds, 0x37ce))
        goto loc_74aa;
    if (memoryAGet16(ds, 0x37d0))
        goto loc_74aa;
    if (memoryAGet16(ds, 0x204c) != 0x0011)
        goto loc_74aa;
    sub_76db();
loc_74aa: // 01ed:55da
    sub_3503();
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_30d4();
    if (memoryAGet(ds, 0x0020) != 0x19)
        goto loc_74cd;
    if (memoryAGet16(ds, 0x4f8a) == 0x0008)
        goto loc_74cd;
    sub_75bc();
loc_74cd: // 01ed:55fd
    sub_68ba();
    sub_77a9();
    sub_8b8b();
    sub_350c();
    if (memoryAGet(ds, 0x0020) != 0x01)
        goto loc_74e3;
    goto loc_74e6;
    // gap 1 bytes // gap 1 bytes
loc_74e3: // 01ed:5613
    goto loc_7407;
loc_74e6: // 01ed:5616
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    return;
loc_74f9: // 01ed:5629
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    memoryASet16(ds, 0x203e, 0x0080);
    sub_30d4();
    if (memoryAGet16(ds, 0x4f7c) == 0x0001)
        goto loc_754b;
    if (memoryAGet16(ds, 0x4f7c) == 0x0002)
        goto loc_7591;
    if (memoryAGet16(ds, 0x4f7c) == 0x0003)
        goto loc_7545;
    if (memoryAGet16(ds, 0x4f7c) == 0x0004)
        goto loc_7548;
    goto loc_74e6;
loc_7545: // 01ed:5675
    goto loc_723a;
loc_7548: // 01ed:5678
    goto loc_7208;
loc_754b: // 01ed:567b
    ax = memoryAGet16(ds, 0x4f72);
    memoryASet16(ds, 0x3c6a, ax);
    ax = memoryAGet16(ds, 0x4f74);
    memoryASet16(ds, 0x3c70, ax);
    ax = memoryAGet16(ds, 0x4f76);
    memoryASet16(ds, 0x3a54, ax);
    memoryASet16(ds, 0x3c74, 0x0000);
    if (!memoryAGet16(ds, 0x4f8c))
        goto loc_7571;
    memoryASet16(ds, 0x4f8c, memoryAGet16(ds, 0x4f8c) - 1);
    goto loc_723a;
loc_7571: // 01ed:56a1
    sub_4052();
    if (!memoryAGet16(ds, 0x26fc))
        goto loc_757e;
    goto loc_74e6;
loc_757e: // 01ed:56ae
    memoryASet16(ds, 0x3a50, 0x0000);
    memoryASet16(ds, 0x4f8e, memoryAGet16(ds, 0x4f8e) - 1);
    memoryASet16(ds, 0x4f8c, 0x0002);
    goto loc_723a;
loc_7591: // 01ed:56c1
    if (memoryAGet16(ds, 0x4f8a) == 0x0008)
        goto loc_759f;
    memoryASet16(ds, 0x4f8a, memoryAGet16(ds, 0x4f8a) + 1);
    goto loc_723a;
loc_759f: // 01ed:56cf
    if (memoryAGet16(ds, 0x4f88) == 0x0008)
        goto loc_75b6;
    memoryASet16(ds, 0x4f88, memoryAGet16(ds, 0x4f88) + 1);
    memoryASet16(ds, 0x4f8a, 0x0001);
    goto loc_7208;
    // gap 3 bytes // gap 3 bytes
loc_75b6: // 01ed:56e6
    sub_8ed2();
    goto loc_74e6;
}
void sub_75bc() // 01ed:56ec
{
    memoryASet(ds, 0x0020, 0x00);
    memoryASet(ds, 0x0023, 0xff);
    sub_8b75();
    memoryASet16(ds, 0x4f70, 0x0000);
    if (!memoryAGet16(ds, 0x26f2))
        goto loc_75f9;
    if (memoryAGet16(ds, 0x26f2) == 0x0001)
        goto loc_75ec;
    ax = memoryAGet16(ds, 0x203e);
    ax -= 0x0080;
    cl = 0x06;
    ax <<= cl;
    memoryASet16(ds, 0x4f70, ax);
    goto loc_75f9;
loc_75ec: // 01ed:571c
    ax = memoryAGet16(ds, 0x203e);
    ax -= 0x0080;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x4f70, ax);
loc_75f9: // 01ed:5729
    si = memoryAGet16(ds, 0x001a);
    si += memoryAGet16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    ax = 0x25f0;
    es = ax;
    di = 0x5590;
    sub_26b6();
    di = memoryAGet16(ds, 0x001a);
    di += memoryAGet16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    al = 0x00;
    sub_2cb3();
    di = memoryAGet16(ds, 0x001a);
    di += memoryAGet16(ds, 0x4f70);
    di += 0x021b;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_763c;
    di += 0x0200;
loc_763c: // 01ed:576c
    ax = 0x00c9;
    sub_273a();
loc_7642: // 01ed:5772
    al = memoryAGet(ds, 0x0020);
    if (al == 0x01)
        goto loc_768f;
    if (al == 0x19)
        goto loc_764f;
    goto loc_7642;
loc_764f: // 01ed:577f
    memoryASet(ds, 0x0020, 0x00);
    di = memoryAGet16(ds, 0x001a);
    di += memoryAGet16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    ax = 0x25f0;
    es = ax;
    si = 0x5590;
    if (memoryAGet16(ds, 0x26f2) == 0x0002)
        goto loc_767c;
    push(ds);
    ax = 0x25f0;
    ds = ax;
    sub_263d();
    goto loc_7685;
loc_767c: // 01ed:57ac
    push(ds);
    ax = 0x25f0;
    ds = ax;
    sub_267a();
loc_7685: // 01ed:57b5
    ds = pop();
    memoryASet(ds, 0x0023, 0x00);
    sub_8b6a();
    return;
loc_768f: // 01ed:57bf
    return;
}
void sub_7690() // 01ed:57c0
{
    if (memoryAGet16(ds, 0x4200))
        goto loc_76bb;
    ax = memoryAGet16(ds, 0x4f92);
    if (!ax)
        goto loc_76bb;
    sub_57f1();
    di += memoryAGet16(ds, 0x0018);
    ax = 0x006b;
    dx = memoryAGet16(ds, 0x001c);
    dx &= 0x0008;
    if (!dx)
        goto loc_76b8;
    ax = 0x0085;
loc_76b8: // 01ed:57e8
    sub_273a();
loc_76bb: // 01ed:57eb
    return;
}
void sub_76bc() // 01ed:57ec
{
    bx = 0x0726;
    cx = 0x01b8;
loc_76c2: // 01ed:57f2
    ah = memoryAGet(ds, bx);
    si = 0x4fa0;
loc_76c9: // 01ed:57f9
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_76d7;
    if (ah != al)
        goto loc_76c9;
    memoryASet(ds, bx, 0x2a);
loc_76d7: // 01ed:5807
    bx++;
    if (--cx)
        goto loc_76c2;
}
void sub_76db() // 01ed:580b
{
    if (memoryAGet16(ds, 0x4f8a) == 0x0008)
        goto loc_76ff;
    sub_697c();
    memoryASet16(ds, 0x4200, 0x0000);
    cx = 0x0008;
loc_76ee: // 01ed:581e
    push(cx);
    sub_71c6();
    cx = 0x0001;
    dx = 0x0008;
    sub_6908();
    cx = pop();
    if (--cx)
        goto loc_76ee;
    return;
loc_76ff: // 01ed:582f
    memoryASet16(ds, 0x3c66, 0xffff);
    memoryASet16(ds, 0x3c68, 0x0000);
}
void sub_770c() // 01ed:583c
{
    if (memoryAGet16(ds, 0x3a50) < 0xfa00)
        goto loc_771a;
    memoryASet16(ds, 0x3a50, 0xfa00);
loc_771a: // 01ed:584a
    ax = memoryAGet16(ds, 0x3a50);
    if (memoryAGet16(ds, 0x4f90) >= ax)
        goto loc_7726;
    memoryASet16(ds, 0x4f90, ax);
loc_7726: // 01ed:5856
    if (memoryAGet(ds, 0x4f95) == 0xff)
        goto loc_773f;
    if (memoryAGet16(ds, 0x4f80) == ax)
        goto loc_7748;
    memoryASet16(ds, 0x4f80, ax);
    memoryASet(ds, 0x4f95, 0xff);
    goto loc_7745;
    // gap 1 bytes // gap 1 bytes
loc_773f: // 01ed:586f
    memoryASet(ds, 0x4f95, 0x00);
loc_7745: // 01ed:5875
    sub_521e();
loc_7748: // 01ed:5878
    if (memoryAGet(ds, 0x4f96) == 0xff)
        goto loc_7761;
    if (memoryAGet16(ds, 0x4f84) == ax)
        goto loc_776a;
    memoryASet16(ds, 0x4f84, ax);
    memoryASet(ds, 0x4f96, 0xff);
    goto loc_7767;
    // gap 1 bytes // gap 1 bytes
loc_7761: // 01ed:5891
    memoryASet(ds, 0x4f96, 0x00);
loc_7767: // 01ed:5897
    sub_5264();
loc_776a: // 01ed:589a
    ax = memoryAGet16(ds, 0x37d0);
    if (ax == memoryAGet16(ds, 0x4f7e))
        goto loc_7789;
    if (memoryAGet16(ds, 0x4f7e) == 0xffff)
        goto loc_7783;
    memoryASet16(ds, 0x4f7e, 0xffff);
    goto loc_7786;
    // gap 1 bytes // gap 1 bytes
loc_7783: // 01ed:58b3
    memoryASet16(ds, 0x4f7e, ax);
loc_7786: // 01ed:58b6
    sub_52aa();
loc_7789: // 01ed:58b9
    ax = memoryAGet16(ds, 0x4f8c);
    if (ax == memoryAGet16(ds, 0x4f82))
        goto loc_77a8;
    if (memoryAGet16(ds, 0x4f82) == 0xffff)
        goto loc_77a2;
    memoryASet16(ds, 0x4f82, 0xffff);
    goto loc_77a5;
    // gap 1 bytes // gap 1 bytes
loc_77a2: // 01ed:58d2
    memoryASet16(ds, 0x4f82, ax);
loc_77a5: // 01ed:58d5
    sub_5300();
loc_77a8: // 01ed:58d8
    return;
}
void sub_77a9() // 01ed:58d9
{
    si = 0x4f9a;
    if (memoryAGet16(ds, 0x4200))
        goto loc_77be;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0004))
        goto loc_77be;
    si += 0x0003;
loc_77be: // 01ed:58ee
    al = 0x21;
    cx = 0x0001;
    sub_2397();
}
void sub_77c8() // 01ed:58f8
{
    ax += ax;
    bx = 0x56bc;
    bx += ax;
    si = memoryAGet16(ds, bx);
    push(si);
    push(ds);
    cx = 0xd6d8;
    dx = si;
    dx += 0x0008;
    bx = 0x0000;
    ax = 0x25f0;
    ds = ax;
    sub_78e1();
    ds = pop();
    si = pop();
    push(ds);
    di = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, si + 4);
    es = ax;
    cx = memoryAGet16(ds, si + 2);
    push(si);
    sub_23ec();
    si = pop();
    ds = pop();
    bx = memoryAGet16(ds, si);
    if (bx == 0xffff)
        goto loc_780c;
    sub_783b();
    return;
loc_780c: // 01ed:593c
    sub_7810();
}
void sub_7810() // 01ed:5940
{
    si = 0x0008;
    cx = 0x000a;
loc_7816: // 01ed:5946
    push(cx);
    cx = 0x0014;
loc_781a: // 01ed:594a
    push(cx);
    push(si);
    bx = 0x56b0;
    memoryASet16(ds, bx, si);
    memoryASet16(ds, bx + 2, 0x335d);
    sub_783b();
    si = pop();
    cx = pop();
    si += 0x0010;
    if (--cx)
        goto loc_781a;
    cx = pop();
    si += 0x1540;
    if (--cx)
        goto loc_7816;
}
void sub_783b() // 01ed:596b
{
    push(ds);
    si = bx;
loc_783e: // 01ed:596e
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_7868;
    memoryASet16(ds, 0x56aa, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x56ac, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x56ae, ax);
    ax = lodsw<DS_SI>();
    if (ax == 0xffff)
        goto loc_786a;
    push(si);
    cx = ax;
loc_7858: // 01ed:5988
    push(cx);
    sub_7891();
    memoryASet16(ds, 0x56aa, memoryAGet16(ds, 0x56aa) + 0x0140);
    cx = pop();
    if (--cx)
        goto loc_7858;
    si = pop();
    goto loc_783e;
loc_7868: // 01ed:5998
    ds = pop();
    return;
loc_786a: // 01ed:599a
    push(si);
    bx = 0x56b0;
    ax = memoryAGet16(ds, 0x56aa);
    memoryASet16(ds, bx, ax);
    ax = memoryAGet16(ds, 0x56ac);
    memoryASet16(ds, bx + 2, ax);
    cx = 0x0014;
loc_787f: // 01ed:59af
    push(cx);
    bx = 0x56b0;
    sub_783b();
    memoryASet16(ds, 0x56b0, memoryAGet16(ds, 0x56b0) + 0x0010);
    cx = pop();
    if (--cx)
        goto loc_787f;
    si = pop();
    goto loc_783e;
}
void sub_7891() // 01ed:59c1
{
    ax = memoryAGet16(ds, 0x56aa);
    di = ax;
    ax = memoryAGet16(ds, 0x56ac);
    es = ax;
    cx = memoryAGet16(ds, 0x56ae);
    dx = cx;
    push(ds);
    push(si);
    ax = 0x0b52;
    ds = ax;
    si = 0x16c2;
    bx = 0x0000;
    cx <<= 1;
loc_78b0: // 01ed:59e0
    ax = memoryAGet16(es, bx + di);
    memoryASet16(ds, bx + si, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_78b0;
    dx = memoryAGet16(ds, 0x56ae);
    cx = dx;
    bx = 0x0000;
loc_78c3: // 01ed:59f3
    push(bx);
    al = lodsb<DS_SI>();
    memoryASet(es, bx + di, al);
    bx += dx;
    al = lodsb<DS_SI>();
    memoryASet(es, bx + di, al);
    bx += dx;
    al = lodsb<DS_SI>();
    memoryASet(es, bx + di, al);
    bx += dx;
    al = lodsb<DS_SI>();
    memoryASet(es, bx + di, al);
    bx = pop();
    bx++;
    if (--cx)
        goto loc_78c3;
    si = pop();
    ds = pop();
}
void sub_78e1() // 01ed:5a11
{
    push(ds);
    ax = 0x0b52;
    ds = ax;
    memoryASet(ds, 0x0021, 0x00);
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7907;
    ds = pop();
    push(ds);
    dx = bx;
    bx = ax;
    ax = 0x3f00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7907;
    ds = pop();
    ax = 0x3e00;
    interrupt(0x21);
    return;
loc_7907: // 01ed:5a37
    ax = 0x0b52;
    ds = ax;
    memoryASet(ds, 0x0021, al);
    ds = pop();
}
void sub_7912() // 01ed:5a42
{
    memoryASet(ds, 0x6b79, 0x00);
    memoryASet(ds, 0x6b78, 0x00);
    memoryASet(ds, 0x6b77, 0x00);
    ax = 0x0004;
    dx = 0x0012;
    sub_7a1b();
    sub_7a4e();
    ax = memoryAGet16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_795f;
    if (ax == 0x0002)
        goto loc_7962;
    if (ax == 0x0003)
        goto loc_7965;
    if (ax == 0x0004)
        goto loc_79b2;
    if (ax == 0x0005)
        goto loc_795c;
    if (ax == 0x0006)
        goto loc_79c5;
    if (ax == 0x0007)
        goto loc_79a2;
    if (ax == 0x0008)
        goto loc_7968;
    return;
loc_795c: // 01ed:5a8c
    goto loc_79f5;
loc_795f: // 01ed:5a8f
    goto loc_79d8;
    // gap 1 bytes // gap 1 bytes
loc_7962: // 01ed:5a92
    goto loc_79e8;
loc_7965: // 01ed:5a95
    goto loc_7a02;
loc_7968: // 01ed:5a98
    memoryASet16(ds, 0x6b70, 0x0004);
    memoryASet16(ds, 0x7048, 0xffff);
    memoryASet16(ds, 0x6b72, 0x005a);
    memoryASet(ds, 0x6b79, 0x00);
    memoryASet(ds, 0x6b78, 0xff);
    ax = 0x0004;
    dx = 0x0016;
    sub_7a1b();
    memoryASet16(ds, 0x7460, 0x0008);
    memoryASet16(ds, 0x7462, 0x0020);
    cx = 0x0005;
    sub_7a60();
    return;
loc_79a2: // 01ed:5ad2
    ax = 0x0008;
    dx = 0x001e;
    sub_7a1b();
    cx = 0x0004;
    sub_7acd();
    return;
loc_79b2: // 01ed:5ae2
    ax = 0x0018;
    sub_7a2f();
    cx = 0x0004;
    sub_7b2a();
    cx = 0x0001;
    sub_7b7f();
    return;
loc_79c5: // 01ed:5af5
    ax = 0x0018;
    sub_7a2f();
    cx = 0x0008;
    sub_7b2a();
    cx = 0x0003;
    sub_7b7f();
    return;
loc_79d8: // 01ed:5b08
    ax = 0x0012;
    sub_7a2f();
    ax = 0x0707;
    si = 0x72a4;
    sub_7c29();
    return;
loc_79e8: // 01ed:5b18
    ax = 0x0012;
    sub_7a2f();
    cx = 0x0001;
    sub_7bd4();
    return;
loc_79f5: // 01ed:5b25
    ax = 0x0012;
    sub_7a2f();
    cx = 0x0003;
    sub_7bd4();
    return;
loc_7a02: // 01ed:5b32
    ax = 0x0012;
    sub_7a2f();
    si = 0x72a4;
    ax = 0x0707;
    sub_7c29();
    si = 0x7388;
    ax = 0x0701;
    sub_7c29();
}
void sub_7a1b() // 01ed:5b4b
{
    si = 0x7388;
    cx = 0x0006;
loc_7a21: // 01ed:5b51
    memoryASet16(ds, si + 26, ax);
    memoryASet16(ds, si + 28, dx);
    si += 0x0026;
    if (--cx)
        goto loc_7a21;
}
void sub_7a2f() // 01ed:5b5f
{
    si = 0x7388;
    dx = 0x0004;
    memoryASet16(ds, si + 140, dx);
    memoryASet16(ds, si + 178, dx);
    memoryASet16(ds, si + 216, dx);
    memoryASet16(ds, si + 142, ax);
    memoryASet16(ds, si + 180, ax);
    memoryASet16(ds, si + 218, ax);
}
void sub_7a4e() // 01ed:5b7e
{
    si = 0x72a4;
    cx = 0x000c;
loc_7a54: // 01ed:5b84
    memoryASet16(ds, si, 0xffff);
    si += 0x0026;
    if (--cx)
        goto loc_7a54;
}
void sub_7a60() // 01ed:5b90
{
    ax = 0x71ea;
    memoryASet16(ds, 0x704a, ax);
    di = 0x7388;
    si = 0x702a;
loc_7a6c: // 01ed:5b9c
    push(cx);
    ax = lodsw<DS_SI>();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, di, dx);
    memoryASet16(ds, di + 2, cx);
    memoryASet16(ds, di + 10, 0x0000);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 4, ax);
    memoryASet16(ds, di + 6, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, di + 12, ax);
    ax = 0x000b;
    sub_587c();
    ah = al;
    al = 0x0a;
    memoryASet16(ds, di + 8, ax);
    memoryASet16(ds, di + 14, 0x0003);
    memoryASet16(ds, di + 18, 0x0000);
    memoryASet16(ds, di + 16, 0x0000);
    memoryASet16(ds, di + 20, 0x000e);
    if (memoryAGet16(ds, di + 12) != 0x0001)
        goto loc_7ac6;
    memoryASet16(ds, di + 20, 0x0019);
loc_7ac6: // 01ed:5bf6
    di += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7a6c;
}
void sub_7acd() // 01ed:5bfd
{
    si = 0x72a4;
loc_7ad0: // 01ed:5c00
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0001);
    memoryASet16(ds, si + 20, 0x0019);
    memoryASet16(ds, si + 4, 0x6e24);
    memoryASet16(ds, si + 6, 0x6e24);
    ax = 0x000b;
    sub_587c();
    ah = al;
    al = 0x0a;
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 14, 0x0003);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7ad0;
}
void sub_7b2a() // 01ed:5c5a
{
    si = 0x72a4;
loc_7b2d: // 01ed:5c5d
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0001);
    memoryASet16(ds, si + 20, 0x000f);
    memoryASet16(ds, si + 4, 0x6cc6);
    memoryASet16(ds, si + 6, 0x6cc6);
    memoryASet16(ds, si + 8, 0x000a);
    memoryASet16(ds, si + 14, 0x0003);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7b2d;
}
void sub_7b7f() // 01ed:5caf
{
    si = 0x73fa;
loc_7b82: // 01ed:5cb2
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0000);
    memoryASet16(ds, si + 20, 0x0028);
    memoryASet16(ds, si + 4, 0x6cf6);
    memoryASet16(ds, si + 6, 0x6cf6);
    memoryASet16(ds, si + 8, 0x000a);
    memoryASet16(ds, si + 14, 0x0003);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7b82;
}
void sub_7bd4() // 01ed:5d04
{
    si = 0x73fa;
loc_7bd7: // 01ed:5d07
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 10, 0x0000);
    memoryASet16(ds, si + 12, 0x0008);
    memoryASet16(ds, si + 20, 0x001e);
    memoryASet16(ds, si + 4, 0x6c92);
    memoryASet16(ds, si + 6, 0x6c92);
    memoryASet16(ds, si + 8, 0x000e);
    memoryASet16(ds, si + 14, 0x0083);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_7bd7;
}
void sub_7c29() // 01ed:5d59
{
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, si, dx);
    memoryASet16(ds, si + 2, cx);
    memoryASet16(ds, si + 38, dx);
    memoryASet16(ds, si + 40, cx);
    memoryASet16(ds, si + 76, dx);
    memoryASet16(ds, si + 78, cx);
    memoryASet16(ds, si + 114, dx);
    memoryASet16(ds, si + 116, cx);
    memoryASet16(ds, si + 152, dx);
    memoryASet16(ds, si + 154, cx);
    memoryASet16(ds, si + 190, dx);
    memoryASet16(ds, si + 192, cx);
    memoryASet16(ds, si + 10, 0xffff);
    memoryASet16(ds, si + 48, 0xffff);
    memoryASet16(ds, si + 86, 0xffff);
    memoryASet16(ds, si + 124, 0xffff);
    memoryASet16(ds, si + 162, 0xffff);
    memoryASet16(ds, si + 200, 0xffff);
    memoryASet16(ds, si + 12, 0x0008);
    memoryASet16(ds, si + 50, 0x0008);
    memoryASet16(ds, si + 88, 0x0008);
    memoryASet16(ds, si + 126, 0x0008);
    memoryASet16(ds, si + 164, 0x0008);
    memoryASet16(ds, si + 202, 0x0008);
    memoryASet16(ds, si + 20, 0x0032);
    memoryASet16(ds, si + 58, 0x0032);
    memoryASet16(ds, si + 96, 0x0032);
    memoryASet16(ds, si + 134, 0x0032);
    memoryASet16(ds, si + 172, 0x0032);
    memoryASet16(ds, si + 210, 0x0032);
    memoryASet16(ds, si + 4, 0x6b7a);
    memoryASet16(ds, si + 6, 0x6b7a);
    memoryASet16(ds, si + 42, 0x6bbe);
    memoryASet16(ds, si + 44, 0x6bbe);
    memoryASet16(ds, si + 80, 0x6bbe);
    memoryASet16(ds, si + 82, 0x6bbe);
    memoryASet16(ds, si + 118, 0x6bbe);
    memoryASet16(ds, si + 120, 0x6bbe);
    memoryASet16(ds, si + 156, 0x6bbe);
    memoryASet16(ds, si + 158, 0x6bbe);
    memoryASet16(ds, si + 194, 0x6c02);
    memoryASet16(ds, si + 196, 0x6c02);
    memoryASet16(ds, si + 8, 0x0014);
    memoryASet16(ds, si + 46, 0x0014);
    memoryASet16(ds, si + 84, 0x1014);
    memoryASet16(ds, si + 122, 0x0414);
    memoryASet16(ds, si + 160, 0x0814);
    memoryASet16(ds, si + 198, 0x1014);
    memoryASet16(ds, si + 14, 0x8282);
    memoryASet16(ds, si + 52, 0x8282);
    memoryASet16(ds, si + 90, 0x8282);
    memoryASet16(ds, si + 128, 0x8282);
    memoryASet16(ds, si + 166, 0x8282);
    memoryASet16(ds, si + 204, 0x8282);
    memoryASet16(ds, si + 18, 0x0000);
    memoryASet16(ds, si + 16, 0x0000);
}
void sub_7d6b() // 01ed:5e9b
{
    ax = memoryAGet16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_7de6;
    if (ax == 0x0002)
        goto loc_7d9d;
    if (ax == 0x0003)
        goto loc_7d9a;
    if (ax == 0x0004)
        goto loc_7dca;
    if (ax == 0x0005)
        goto loc_7d9d;
    if (ax == 0x0006)
        goto loc_7dca;
    if (ax == 0x0007)
        goto loc_7da0;
    if (ax == 0x0008)
        goto loc_7d97;
    return;
loc_7d97: // 01ed:5ec7
    goto loc_7e5b;
loc_7d9a: // 01ed:5eca
    goto loc_7e09;
    // gap 1 bytes // gap 1 bytes
loc_7d9d: // 01ed:5ecd
    goto loc_7e48;
loc_7da0: // 01ed:5ed0
    sub_801a();
    ax = 0x0000;
    dx = memoryAGet16(ds, 0x001c);
    if (!(dx & 0x0020))
        goto loc_7db3;
    ax = 0xffff;
loc_7db3: // 01ed:5ee3
    memoryASet(ds, 0x6b78, al);
    if (al)
        goto loc_7dc0;
    si = 0x72a4;
    sub_893b();
loc_7dc0: // 01ed:5ef0
    sub_80ca();
    sub_8b10();
    sub_86df();
    return;
loc_7dca: // 01ed:5efa
    sub_801a();
    si = 0x72a4;
    sub_893b();
    si = 0x7388;
    sub_893b();
    sub_8211();
    sub_8309();
    sub_8b10();
    sub_86df();
    return;
loc_7de6: // 01ed:5f16
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_893b();
    memoryASet(ds, 0x6b76, dl);
    si = 0x72a4;
    sub_8758();
    sub_8b10();
    sub_86df();
    return;
loc_7e09: // 01ed:5f39
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_8877();
    si = 0x7388;
    sub_8877();
    si = 0x7388;
    sub_8877();
    si = 0x72a4;
    sub_893b();
    memoryASet(ds, 0x6b76, dl);
    si = 0x72a4;
    sub_8758();
    si = 0x7388;
    sub_893b();
    memoryASet(ds, 0x6b76, dl);
    si = 0x7388;
    sub_8758();
    sub_8b10();
    sub_86df();
    return;
loc_7e48: // 01ed:5f78
    sub_85ad();
    si = 0x7388;
    sub_893b();
    sub_80ca();
    sub_8b10();
    sub_86df();
    return;
loc_7e5b: // 01ed:5f8b
    if (memoryAGet16(ds, 0x6b70))
        goto loc_7e6e;
    ax = memoryAGet16(ds, 0x001c);
    if (ax & 0x001f)
        goto loc_7e6e;
    memoryASet(ds, 0x6b78, ~memoryAGet(ds, 0x6b78));
loc_7e6e: // 01ed:5f9e
    sub_801a();
    sub_801a();
    sub_8428();
    si = 0x7388;
    sub_893b();
    sub_86df();
    sub_7fd3();
    memoryASet16(ds, 0x6b72, memoryAGet16(ds, 0x6b72) - 1);
    if (!memoryAGet16(ds, 0x6b72))
        goto loc_7efe;
    if (memoryAGet16(ds, 0x7048) != 0xffff)
        goto loc_7e96;
    return;
loc_7e96: // 01ed:5fc6
    di = 0x73ae;
    si = 0x4d50;
    bx = memoryAGet16(ds, 0x7048);
    cx = 0x0004;
loc_7ea3: // 01ed:5fd3
    push(cx);
    push(bx);
    push(si);
    push(di);
    dx = memoryAGet16(ds, di);
    if (dx == 0xffff)
        goto loc_7ecd;
    cx = memoryAGet16(ds, di + 2);
    cx -= 0x0006;
    si += 0x0014;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 2, ax);
    sub_2782();
loc_7ecd: // 01ed:5ffd
    di = pop();
    si = pop();
    bx = pop();
    cx = pop();
    di += 0x0026;
    si += 0x0024;
    if (--cx)
        goto loc_7ea3;
    ax = memoryAGet16(ds, 0x001c);
    if (ax & 0x0001)
        goto loc_7efd;
    memoryASet16(ds, 0x7048, memoryAGet16(ds, 0x7048) + 0x0004);
    bx = memoryAGet16(ds, 0x7048);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_7efd;
    memoryASet16(ds, 0x7048, 0xffff);
    memoryASet(ds, 0x6b79, 0x00);
loc_7efd: // 01ed:602d
    return;
loc_7efe: // 01ed:602e
    if (!memoryAGet(ds, 0x6b79))
        goto loc_7f50;
    memoryASet16(ds, 0x6b72, 0x00b4);
    di = 0x4d50;
    si = 0x73ae;
    cx = 0x0004;
loc_7f14: // 01ed:6044
    ax = memoryAGet16(ds, di);
    if (ax == 0xffff)
        goto loc_7f2c;
    memoryASet16(ds, di, 0xffff);
    ax -= 0x0008;
    ax &= 0xfff0;
    ax += 0x0008;
loc_7f2c: // 01ed:605c
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, di + 2);
    ax -= 0x0018;
    ax &= 0xfff0;
    ax += 0x0018;
    memoryASet16(ds, si + 2, ax);
    di += 0x0024;
    si += 0x0026;
    if (--cx)
        goto loc_7f14;
    memoryASet16(ds, 0x7048, 0x71c4);
    return;
loc_7f50: // 01ed:6080
    memoryASet16(ds, 0x6b72, 0x00b4);
    memoryASet(ds, 0x6b79, 0xff);
    si = 0x73ae;
    di = 0x4d50;
    cx = 0x0004;
loc_7f65: // 01ed:6095
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_7fca;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_7fca;
    ax = memoryAGet16(ds, si);
    if (ax == 0xffff)
        goto loc_7f85;
    ax -= 0x0008;
    ax &= 0xfff0;
    ax += 0x0008;
loc_7f85: // 01ed:60b5
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0xfff0;
    ax += 0x0018;
    memoryASet16(ds, di + 2, ax);
    memoryASet16(ds, di + 4, 0x7182);
    memoryASet16(ds, di + 6, 0x70f2);
    memoryASet16(ds, di + 10, 0xffc0);
    memoryASet16(ds, di + 12, 0x0017);
    memoryASet16(ds, di + 14, 0x008f);
    memoryASet16(ds, di + 16, 0x0000);
    memoryASet16(ds, di + 8, 0x000a);
    memoryASet16(ds, di + 26, 0x0016);
loc_7fca: // 01ed:60fa
    si += 0x0026;
    di += 0x0024;
    if (--cx)
        goto loc_7f65;
}
void sub_7fd3() // 01ed:6103
{
    if (!memoryAGet(ds, 0x6b79))
        goto loc_8019;
    push(si);
    si = 0x4d50;
    cx = 0x0004;
loc_7fe1: // 01ed:6111
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8012;
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    di = 0x3cde;
    cx = 0x0008;
loc_7ffa: // 01ed:612a
    if (memoryAGet16(ds, di + 8) != ax)
        goto loc_800d;
    if ((short)memoryAGet16(ds, di + 2) < 0x0000)
        goto loc_800d;
    memoryASet16(ds, di + 6, 0xffff);
loc_800d: // 01ed:613d
    di += 0x0016;
    if (--cx)
        goto loc_7ffa;
loc_8012: // 01ed:6142
    si += 0x0024;
    cx = pop();
    if (--cx)
        goto loc_7fe1;
    si = pop();
loc_8019: // 01ed:6149
    return;
}
void sub_801a() // 01ed:614a
{
    si = 0x72a4;
    cx = 0x000c;
    if (!memoryAGet(ds, 0x6b79))
        goto loc_802a;
    cx = 0x0007;
loc_802a: // 01ed:615a
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8057;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_8057;
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0001;
    if (!ax)
        goto loc_805a;
    ax = memoryAGet16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (!ax)
        goto loc_806b;
    goto loc_809c;
    // gap 1 bytes // gap 1 bytes
loc_8057: // 01ed:6187
    goto loc_80c0;
    // gap 1 bytes // gap 1 bytes
loc_805a: // 01ed:618a
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (!ax)
        goto loc_806b;
    goto loc_809c;
loc_806b: // 01ed:619b
    ax = 0x0064;
    sub_587c();
    if (ax > 0x0014)
        goto loc_8082;
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
    goto loc_809c;
loc_8082: // 01ed:61b2
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_809c;
    memoryASet16(ds, si + 10, ax);
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
loc_809c: // 01ed:61cc
    ax = memoryAGet16(ds, si + 10);
    if (ax == 0xffff)
        goto loc_80c0;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + dx);
loc_80c0: // 01ed:61f0
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_80c7;
    return;
loc_80c7: // 01ed:61f7
    goto loc_802a;
}
void sub_80ca() // 01ed:61fa
{
    si = 0x72a4;
    cx = 0x000c;
loc_80d0: // 01ed:6200
    push(cx);
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_80db;
    goto loc_81a8;
loc_80db: // 01ed:620b
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_80e5;
    goto loc_81b2;
loc_80e5: // 01ed:6215
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_810f;
    ah = 0x00;
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_810f;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_810f: // 01ed:623f
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    if (memoryAGet16(ds, si + 20) > 0x0010)
        goto loc_8126;
    ax += 0x0040;
loc_8126: // 01ed:6256
    if (memoryAGet16(ds, si + 20) > 0x0008)
        goto loc_8130;
    ax += 0x0040;
loc_8130: // 01ed:6260
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 24, dx);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    if (memoryAGet(ds, 0x6b78))
        goto loc_8163;
    if (!memoryAGet16(ds, si + 18))
        goto loc_8163;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_8163;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_81a7;
loc_8163: // 01ed:6293
    si += 0x0016;
    sub_2782();
    if (!memoryAGet(ds, 0x6b78))
        goto loc_81a7;
    si = pop();
    push(si);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    dx -= 0x0008;
    cx -= 0x0008;
    si += 0x0146;
    memoryASet16(ds, si, 0xb5c0);
    memoryASet16(ds, si + 2, 0x1650);
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_81a4;
    memoryASet16(ds, si, 0xb5e0);
    memoryASet16(ds, si + 2, 0x1650);
loc_81a4: // 01ed:62d4
    sub_2782();
loc_81a7: // 01ed:62d7
    si = pop();
loc_81a8: // 01ed:62d8
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_81af;
    return;
loc_81af: // 01ed:62df
    goto loc_80d0;
loc_81b2: // 01ed:62e2
    memoryASet16(ds, 0x6b6e, si);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_820f;
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x006e)
        goto loc_81ec;
    memoryASet16(ds, si + 8, 0x0064);
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_81ec;
    memoryASet16(ds, si, 0xffff);
    goto loc_820f;
    // gap 1 bytes // gap 1 bytes
loc_81ec: // 01ed:631c
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_820f: // 01ed:633f
    goto loc_81a8;
}
void sub_8211() // 01ed:6341
{
    si = 0x72a4;
    cx = 0x0008;
loc_8217: // 01ed:6347
    push(cx);
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_8222;
    goto loc_82a0;
    // gap 1 bytes // gap 1 bytes
loc_8222: // 01ed:6352
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_822c;
    goto loc_82aa;
    // gap 1 bytes // gap 1 bytes
loc_822c: // 01ed:635c
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_8256;
    ah = 0x00;
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_8256;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_8256: // 01ed:6386
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    if (memoryAGet16(ds, si + 20) > 0x0007)
        goto loc_826d;
    ax += 0x0030;
loc_826d: // 01ed:639d
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 24, dx);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    if (!memoryAGet16(ds, si + 18))
        goto loc_8299;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_8299;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_829f;
loc_8299: // 01ed:63c9
    si += 0x0016;
    sub_2782();
loc_829f: // 01ed:63cf
    si = pop();
loc_82a0: // 01ed:63d0
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_82a7;
    return;
loc_82a7: // 01ed:63d7
    goto loc_8217;
loc_82aa: // 01ed:63da
    memoryASet16(ds, 0x6b6e, si);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8307;
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x006e)
        goto loc_82e4;
    memoryASet16(ds, si + 8, 0x0064);
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_82e4;
    memoryASet16(ds, si, 0xffff);
    goto loc_8307;
    // gap 1 bytes // gap 1 bytes
loc_82e4: // 01ed:6414
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8307: // 01ed:6437
    goto loc_82a0;
}
void sub_8309() // 01ed:6439
{
    si = 0x73fa;
    cx = 0x0003;
loc_830f: // 01ed:643f
    push(cx);
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_831a;
    goto loc_83bc;
loc_831a: // 01ed:644a
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_8324;
    goto loc_83c6;
loc_8324: // 01ed:6454
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_834e;
    ah = 0x00;
    bx += 0x0010;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_834e;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_834e: // 01ed:647e
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
    if (memoryAGet16(ds, si + 20) > 0x001e)
        goto loc_836b;
    bx += 0x0044;
loc_836b: // 01ed:649b
    if (memoryAGet16(ds, si + 20) > 0x0014)
        goto loc_8376;
    bx += 0x0044;
loc_8376: // 01ed:64a6
    if (memoryAGet16(ds, si + 20) > 0x000a)
        goto loc_8381;
    bx += 0x0044;
loc_8381: // 01ed:64b1
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 24, dx);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0008;
    if (!memoryAGet16(ds, si + 18))
        goto loc_83b5;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_83b5;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_83bb;
loc_83b5: // 01ed:64e5
    si += 0x0016;
    sub_2782();
loc_83bb: // 01ed:64eb
    si = pop();
loc_83bc: // 01ed:64ec
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_83c3;
    return;
loc_83c3: // 01ed:64f3
    goto loc_830f;
loc_83c6: // 01ed:64f6
    memoryASet16(ds, 0x6b6e, si);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8426;
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x006e)
        goto loc_8400;
    memoryASet16(ds, si + 8, 0x0064);
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_8400;
    memoryASet16(ds, si, 0xffff);
    goto loc_8426;
    // gap 1 bytes // gap 1 bytes
loc_8400: // 01ed:6530
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0008;
    dx -= 0x0008;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8426: // 01ed:6556
    goto loc_83bc;
}
void sub_8428() // 01ed:6558
{
    si = 0x7388;
    cx = 0x0005;
loc_842e: // 01ed:655e
    push(cx);
    if (!memoryAGet(ds, 0x6b79))
        goto loc_8447;
    if (memoryAGet16(ds, si + 12) == 0x0001)
        goto loc_8447;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_8447;
    goto loc_851b;
loc_8447: // 01ed:6577
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_8451;
    goto loc_851b;
loc_8451: // 01ed:6581
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_845b;
    goto loc_8525;
loc_845b: // 01ed:658b
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_8485;
    ah = 0x00;
    bx += 0x0010;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_8485;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_8485: // 01ed:65b5
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 24, dx);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0006;
    if (!memoryAGet16(ds, si + 18))
        goto loc_84cb;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_84cb;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_84d1;
loc_84cb: // 01ed:65fb
    si += 0x0016;
    sub_2782();
loc_84d1: // 01ed:6601
    si = pop();
    if (memoryAGet16(ds, si + 12) != 0x0001)
        goto loc_851b;
    if (!memoryAGet(ds, 0x6b78))
        goto loc_851b;
    push(si);
    dx = memoryAGet16(ds, si);
    dx -= 0x0008;
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x000a;
    di = memoryAGet16(ds, 0x704a);
    si = 0x745c;
    ax = memoryAGet16(ds, di);
    memoryASet16(ds, si, ax);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, si + 2, ax);
    di += 0x0004;
    if (memoryAGet16(ds, di) != 0xffff)
        goto loc_8513;
    di = 0x71ea;
loc_8513: // 01ed:6643
    memoryASet16(ds, 0x704a, di);
    sub_2782();
    si = pop();
loc_851b: // 01ed:664b
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_8522;
    return;
loc_8522: // 01ed:6652
    goto loc_842e;
loc_8525: // 01ed:6655
    memoryASet16(ds, 0x6b6e, si);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_85aa;
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x006e)
        goto loc_857d;
    memoryASet16(ds, si + 8, 0x0064);
    if (memoryAGet16(ds, 0x6b70))
        goto loc_8555;
    memoryASet16(ds, si + 8, 0x0069);
loc_8555: // 01ed:6685
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_857d;
    memoryASet16(ds, 0x6b70, memoryAGet16(ds, 0x6b70) - 1);
    if (memoryAGet16(ds, 0x6b70) != 0xffff)
        goto loc_8574;
    memoryASet16(ds, 0x4f7c, 0x0002);
loc_8574: // 01ed:66a4
    memoryASet16(ds, si, 0xffff);
    goto loc_85aa;
    // gap 1 bytes // gap 1 bytes
loc_857d: // 01ed:66ad
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    if (!memoryAGet16(ds, 0x6b70))
        goto loc_85a3;
    cx -= 0x0005;
    dx -= 0x0003;
loc_85a3: // 01ed:66d3
    si += 0x0016;
    sub_2782();
    si = pop();
loc_85aa: // 01ed:66da
    goto loc_851b;
}
void sub_85ad() // 01ed:66dd
{
    si = 0x73fa;
    cx = 0x0003;
loc_85b3: // 01ed:66e3
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_85e0;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_85e0;
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0001;
    if (!ax)
        goto loc_85e3;
    ax = memoryAGet16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (!ax)
        goto loc_85f4;
    goto loc_8636;
    // gap 1 bytes // gap 1 bytes
loc_85e0: // 01ed:6710
    goto loc_865a;
    // gap 1 bytes // gap 1 bytes
loc_85e3: // 01ed:6713
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (!ax)
        goto loc_85f4;
    goto loc_8636;
loc_85f4: // 01ed:6724
    if (memoryAGet16(ds, 0x4200) < 0x0008)
        goto loc_8612;
    ax = 0x0064;
    sub_587c();
    if (ax < 0x0014)
        goto loc_8612;
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
    goto loc_862c;
loc_8612: // 01ed:6742
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_862c;
    memoryASet16(ds, si + 10, ax);
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
loc_862c: // 01ed:675c
    if (memoryAGet16(ds, 0x4200) >= 0x0008)
        goto loc_8636;
    sub_8664();
loc_8636: // 01ed:6766
    ax = memoryAGet16(ds, si + 10);
    if (ax == 0xffff)
        goto loc_865a;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + dx);
loc_865a: // 01ed:678a
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_8661;
    return;
loc_8661: // 01ed:6791
    goto loc_85b3;
}
void sub_8664() // 01ed:6794
{
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    di = 0x4d50;
    cx = 0x000f;
loc_8675: // 01ed:67a5
    if (memoryAGet16(ds, di) == 0xffff)
        goto loc_8684;
    di += 0x0024;
    if (--cx)
        goto loc_8675;
    goto loc_86de;
    // gap 1 bytes // gap 1 bytes
loc_8684: // 01ed:67b4
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memoryASet16(ds, di, dx);
    memoryASet16(ds, di + 2, cx);
    memoryASet16(ds, di + 10, 0xffb8);
    ax = 0x000c;
    memoryASet16(ds, di + 12, ax);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x42d4;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, di + 6, ax);
    ax += 0x00c0;
    memoryASet16(ds, di + 4, ax);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, di + 8, ax);
    ax = memoryAGet16(ds, bx + 6);
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, di + 18, 0x0000);
    memoryASet16(ds, di + 16, 0x0000);
    memoryASet16(ds, 0x4200, memoryAGet16(ds, 0x4200) + 1);
loc_86de: // 01ed:680e
    return;
}
void sub_86df() // 01ed:680f
{
    si = 0x3c5e;
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8757;
    if ((short)memoryAGet16(ds, si + 8) < 0x0000)
        goto loc_8757;
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x72a4;
    cx = 0x000c;
loc_8703: // 01ed:6833
    push(cx);
    if (memoryAGet16(ds, bx) == 0xffff)
        goto loc_8729;
    if ((short)memoryAGet16(ds, bx + 12) < 0x0000)
        goto loc_8729;
    push(dx);
    dx = memoryAGet16(ds, bx);
    dx += 0x0008;
    cx = memoryAGet16(ds, bx + 2);
    cx += 0x0008;
    sub_581f();
    dx = pop();
    if (ax == dx)
        goto loc_8730;
loc_8729: // 01ed:6859
    bx += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_8703;
    return;
loc_8730: // 01ed:6860
    cx = pop();
    if (memoryAGet16(ds, bx + 12) == 0x0001)
        goto loc_8745;
    if (!memoryAGet(ds, 0x6b79))
        goto loc_8745;
    bx += 0x0026;
    if (--cx)
        goto loc_8703;
    return;
loc_8745: // 01ed:6875
    memoryASet16(ds, si + 8, 0xffff);
    memoryASet16(ds, si + 10, 0x0000);
    ax = 0x0000;
    sub_8ca1();
loc_8757: // 01ed:6887
    return;
}
void sub_8758() // 01ed:6888
{
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_8762;
    goto loc_8807;
loc_8762: // 01ed:6892
    if ((short)memoryAGet16(ds, si + 12) >= 0x0000)
        goto loc_876c;
    goto loc_880b;
loc_876c: // 01ed:689c
    si += 0x00be;
    cx = 0x0006;
loc_8773: // 01ed:68a3
    push(cx);
    bx = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, 0x001e);
    ax = memoryAGet16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_879e;
    ah = 0x00;
    bx += 0x0010;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_879e;
    bx = memoryAGet16(ds, si + 4);
    memoryASet16(ds, si + 6, bx);
loc_879e: // 01ed:68ce
    memoryASet16(ds, si + 8, ax);
    push(si);
    ax = memoryAGet16(ds, si + 10);
    if ((short)ax < 0x0000)
        goto loc_87b5;
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
loc_87b5: // 01ed:68e5
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    if (memoryAGet16(ds, si + 20) > 0x0021)
        goto loc_87c7;
    ax += 0x2d00;
loc_87c7: // 01ed:68f7
    if (memoryAGet16(ds, si + 20) > 0x0010)
        goto loc_87d1;
    ax += 0x2d00;
loc_87d1: // 01ed:6901
    memoryASet16(ds, si + 22, ax);
    memoryASet16(ds, si + 24, dx);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    if (!memoryAGet(ds, 0x6b76))
        goto loc_87fd;
    ax = memoryAGet16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_87fd;
    bl = 0x69;
    sub_28cd();
    goto loc_8800;
loc_87fd: // 01ed:692d
    sub_2782();
loc_8800: // 01ed:6930
    si = pop();
    cx = pop();
    si -= 0x0026;
    if (--cx)
        goto loc_8808;
loc_8807: // 01ed:6937
    return;
loc_8808: // 01ed:6938
    goto loc_8773;
loc_880b: // 01ed:693b
    memoryASet16(ds, 0x6b6e, si);
    si += 0x00be;
    cx = 0x0006;
loc_8816: // 01ed:6946
    push(cx);
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_8870;
    bx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, 0x001e);
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    if (memoryAGet16(ds, si + 8) < 0x006c)
        goto loc_884d;
    memoryASet16(ds, si + 8, 0x0064);
    bx += 0x0004;
    memoryASet16(ds, si + 6, bx);
    if (memoryAGet16(ds, bx) != 0xffff)
        goto loc_884d;
    memoryASet16(ds, si, 0xffff);
    goto loc_8870;
    // gap 1 bytes // gap 1 bytes
loc_884d: // 01ed:697d
    push(si);
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si + 24, ax);
    dx = memoryAGet16(ds, si);
    cx = memoryAGet16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8870: // 01ed:69a0
    cx = pop();
    si -= 0x0026;
    if (--cx)
        goto loc_8816;
}
void sub_8877() // 01ed:69a7
{
    if (memoryAGet16(ds, si) == 0xffff)
        goto loc_88aa;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_88aa;
    ax = memoryAGet16(ds, si + 10);
    memoryASet16(ds, 0x6b74, ax);
    ax = memoryAGet16(ds, si + 10);
    ax &= 0x0001;
    if (!ax)
        goto loc_88ad;
    ax = memoryAGet16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (!ax)
        goto loc_88be;
    goto loc_890e;
    // gap 1 bytes // gap 1 bytes
loc_88aa: // 01ed:69da
    goto loc_893a;
loc_88ad: // 01ed:69dd
    ax = memoryAGet16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (!ax)
        goto loc_88be;
    goto loc_890e;
loc_88be: // 01ed:69ee
    sub_6d9c();
    if (!dx)
        goto loc_88e0;
    ax = memoryAGet16(ds, si + 10);
    sub_6ebe();
    if (!dx)
        goto loc_88e0;
    memoryASet16(ds, si + 10, ax);
    sub_6f9a();
    sub_6e9c();
    memoryASet16(ds, si + 10, ax);
loc_88e0: // 01ed:6a10
    if ((short)memoryAGet16(ds, si + 10) < 0x0000)
        goto loc_890e;
    ax = memoryAGet16(ds, si + 162);
    memoryASet16(ds, si + 200, ax);
    ax = memoryAGet16(ds, si + 124);
    memoryASet16(ds, si + 162, ax);
    ax = memoryAGet16(ds, si + 86);
    memoryASet16(ds, si + 124, ax);
    ax = memoryAGet16(ds, si + 48);
    memoryASet16(ds, si + 86, ax);
    ax = memoryAGet16(ds, 0x6b74);
    memoryASet16(ds, si + 48, ax);
loc_890e: // 01ed:6a3e
    cx = 0x0006;
loc_8911: // 01ed:6a41
    ax = memoryAGet16(ds, si + 10);
    if ((short)ax < 0x0000)
        goto loc_8938;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) + dx);
    si += 0x0026;
loc_8938: // 01ed:6a68
    if (--cx)
        goto loc_8911;
loc_893a: // 01ed:6a6a
    return;
}
void sub_893b() // 01ed:6a6b
{
    memoryASet16(ds, 0x6b6c, 0x0000);
    memoryASet16(ds, 0x6b6e, si);
    cx = 0x0006;
loc_8948: // 01ed:6a78
    dx = memoryAGet16(ds, si);
    if (dx == 0xffff)
        goto loc_8975;
    if ((short)memoryAGet16(ds, si + 12) < 0x0000)
        goto loc_8975;
    push(cx);
    memoryASet16(ds, si + 18, 0x0000);
    cx = memoryAGet16(ds, si + 2);
    dx += 0x0008;
    cx += 0x0008;
    sub_581f();
    sub_6bb9();
    cx = pop();
    if (dx == 0xffff)
        goto loc_897f;
loc_8975: // 01ed:6aa5
    si += 0x0026;
    if (--cx)
        goto loc_8948;
    dx = memoryAGet16(ds, 0x6b6c);
    return;
loc_897f: // 01ed:6aaf
    if (memoryAGet16(ds, 0x4f88) != 0x0008)
        goto loc_8996;
    if (memoryAGet16(ds, si + 12) != 0x0001)
        goto loc_8996;
    if (!memoryAGet(ds, 0x6b78))
        goto loc_899d;
    goto loc_8975;
loc_8996: // 01ed:6ac6
    if (memoryAGet(ds, 0x6b79))
        goto loc_8975;
loc_899d: // 01ed:6acd
    memoryASet16(ds, si + 18, 0xffff);
    memoryASet16(ds, 0x6b6c, 0xffff);
    memoryASet16(ds, si + 20, memoryAGet16(ds, si + 20) - 1);
    if ((short)memoryAGet16(ds, si + 20) < 0x0000)
        goto loc_89b6;
    goto loc_8975;
loc_89b6: // 01ed:6ae6
    push(si);
    ax = 0x0002;
    sub_8ca1();
    si = pop();
    ax = memoryAGet16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_89ed;
    if (ax == 0x0002)
        goto loc_8a47;
    if (ax == 0x0003)
        goto loc_89ed;
    if (ax == 0x0004)
        goto loc_8a09;
    if (ax == 0x0005)
        goto loc_8a47;
    if (ax == 0x0006)
        goto loc_8a09;
    if (ax == 0x0007)
        goto loc_89f0;
    if (ax == 0x0008)
        goto loc_89ea;
    return;
loc_89ea: // 01ed:6b1a
    goto loc_8ad7;
loc_89ed: // 01ed:6b1d
    goto loc_8a60;
    // gap 1 bytes // gap 1 bytes
loc_89f0: // 01ed:6b20
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 6, 0x6e36);
    memoryASet16(ds, si + 8, 0x0032);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x012c);
    return;
loc_8a09: // 01ed:6b39
    if (memoryAGet16(ds, si + 12) == 0x0001)
        goto loc_8a2f;
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 6, 0x6e06);
    memoryASet16(ds, si + 8, 0x0032);
    memoryASet16(ds, si + 26, 0x0008);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x012c);
    return;
loc_8a2f: // 01ed:6b5f
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 6, 0x6cd8);
    memoryASet16(ds, si + 8, 0x0032);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x000a);
    return;
loc_8a47: // 01ed:6b77
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 6, 0x6ca4);
    memoryASet16(ds, si + 8, 0x0032);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x00c8);
    return;
loc_8a60: // 01ed:6b90
    si = memoryAGet16(ds, 0x6b6e);
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, si + 50, 0xffff);
    memoryASet16(ds, si + 88, 0xffff);
    memoryASet16(ds, si + 126, 0xffff);
    memoryASet16(ds, si + 164, 0xffff);
    memoryASet16(ds, si + 202, 0xffff);
    memoryASet16(ds, si + 6, 0x6c46);
    memoryASet16(ds, si + 44, 0x6c70);
    memoryASet16(ds, si + 82, 0x6c70);
    memoryASet16(ds, si + 120, 0x6c70);
    memoryASet16(ds, si + 158, 0x6c70);
    memoryASet16(ds, si + 196, 0x6c70);
    memoryASet16(ds, si + 8, 0x0032);
    memoryASet16(ds, si + 46, 0x003c);
    memoryASet16(ds, si + 84, 0x0046);
    memoryASet16(ds, si + 122, 0x0050);
    memoryASet16(ds, si + 160, 0x005a);
    memoryASet16(ds, si + 198, 0x0064);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x00c8);
    return;
loc_8ad7: // 01ed:6c07
    ax = memoryAGet16(ds, si + 12);
    ax--;
    ax += ax;
    bx = 0x7020;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 6, ax);
    memoryASet16(ds, si + 8, 0x0032);
    if (memoryAGet16(ds, si + 12) == 0x0001)
        goto loc_8b04;
    memoryASet16(ds, si + 26, 0x0006);
    memoryASet16(ds, si + 28, 0x0016);
loc_8b04: // 01ed:6c34
    memoryASet16(ds, si + 12, 0xffff);
    memoryASet16(ds, 0x3a50, memoryAGet16(ds, 0x3a50) + 0x000a);
}
void sub_8b10() // 01ed:6c40
{
    if (memoryAGet(ds, 0x6b77))
        goto loc_8b68;
    if (memoryAGet16(ds, 0x4200))
        goto loc_8b68;
    si = 0x72a4;
    cx = 0x000c;
loc_8b24: // 01ed:6c54
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_8b68;
    si += 0x0026;
    if (--cx)
        goto loc_8b24;
    cx = 0x0008;
    si = 0x3cde;
loc_8b36: // 01ed:6c66
    if (memoryAGet16(ds, si) != 0xffff)
        goto loc_8b68;
    si += 0x0016;
    if (--cx)
        goto loc_8b36;
    memoryASet(ds, 0x6b77, 0xff);
    sub_71c6();
    push(ax);
    dl = 0x75;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x00a0;
    sub_5f24();
    di += memoryAGet16(ds, 0x0018);
    sub_273a();
    ax = 0x000a;
    sub_8c10();
loc_8b68: // 01ed:6c98
    return;
}
void sub_8b6a() // 01ed:6c9a
{
    if (!memoryAGet(ds, 0x7052))
        goto loc_8b74;
    sub_9641();
loc_8b74: // 01ed:6ca4
    return;
}
void sub_8b75() // 01ed:6ca5
{
    if (!memoryAGet(ds, 0x7052))
        goto loc_8b7f;
    sub_9634();
loc_8b7f: // 01ed:6caf
    return;
}
void sub_8b80() // 01ed:6cb0
{
    if (!memoryAGet(ds, 0x7052))
        goto loc_8b8a;
    sub_9612();
loc_8b8a: // 01ed:6cba
    return;
}
void sub_8b8b() // 01ed:6cbb
{
    sp -= 2;
    if (!memoryAGet(ds, 0x7052))
        goto loc_8b99;
    sub_964e();
    if (!al)
        goto loc_8b9a;
loc_8b99: // 01ed:6cc9
    sp += 2; return;
loc_8b9a: // 01ed:6cca
    ax = memoryAGet16(ds, 0x7050);
    es = ax;
    di = memoryAGet16(ds, 0x704e);
    di += 0x0008;
    ax = memoryAGet16(es, di);
    ax += memoryAGet16(ds, 0x704e);
    dx = memoryAGet16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95bc();
    sp += 0x0004;
    sp += 2;
}
void sub_8bba() // 01ed:6cea
{
    memoryASet(ds, 0x7052, 0x00);
    memoryASet(ds, 0x7053, 0x00);
    sub_92d0();
    if (!al)
        goto loc_8c0f;
    sub_91c4();
    if (!al)
        goto loc_8c0f;
    sub_956a();
    if (!al)
        goto loc_8c0f;
    sub_95e5();
    memoryASet(ds, 0x7052, 0xff);
    sub_9479();
    if (!al)
        goto loc_8c03;
    sub_9479();
    if (!al)
        goto loc_8c03;
    sub_9479();
    if (!al)
        goto loc_8c03;
    sub_9479();
    if (!al)
        goto loc_8c03;
    goto loc_8c0f;
    // gap 1 bytes // gap 1 bytes
loc_8c03: // 01ed:6d33
    memoryASet(ds, 0x7052, 0xff);
    memoryASet(ds, 0x7053, 0xff);
loc_8c0f: // 01ed:6d3f
    return;
}
void sub_8c10() // 01ed:6d40
{
    sp -= 2;
    if (!memoryAGet(ds, 0x7052))
        goto loc_8c1a;
    goto loc_8c1d;
    // gap 1 bytes // gap 1 bytes
loc_8c1a: // 01ed:6d4a
    goto loc_8ca0;
loc_8c1d: // 01ed:6d4d
    push(si);
    push(es);
    push(ax);
    sub_9612();
    ax = pop();
    si = 0x70a2;
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x704e, ax);
    ax = lodsw<DS_SI>();
    memoryASet16(ds, 0x7050, ax);
    es = ax;
    di = memoryAGet16(ds, 0x704e);
    di += 0x000c;
    ax = memoryAGet16(es, di);
    tl = ah; ah = al; al = tl;
    ax >>= 1;
    push(ax);
    sub_9602();
    ax = pop();
    ax = memoryAGet16(ds, 0x7050);
    es = ax;
    di = memoryAGet16(ds, 0x704e);
    di += 0x0024;
    ax = memoryAGet16(es, di);
    push(ax);
    di = memoryAGet16(ds, 0x704e);
    di += 0x0006;
    ax = memoryAGet16(es, di);
    ax += memoryAGet16(ds, 0x704e);
    dx = memoryAGet16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95cf();
    sp += 0x0006;
    ax = memoryAGet16(ds, 0x7050);
    es = ax;
    di = memoryAGet16(ds, 0x704e);
    di += 0x0008;
    ax = memoryAGet16(es, di);
    ax += memoryAGet16(ds, 0x704e);
    dx = memoryAGet16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95bc();
    sp += 0x0004;
    if (!memoryAGet(ds, 0x4f98))
        goto loc_8c9d;
    sub_9634();
loc_8c9d: // 01ed:6dcd
    es = pop();
    si = pop();
    sp += 2; return;
loc_8ca0: // 01ed:6dd0
    sp += 2; return;
}
void sub_8ca1() // 01ed:6dd1
{
    sp -= 2;
    if (memoryAGet(ds, 0x4f99))
        goto loc_8cd5;
    if (!memoryAGet(ds, 0x7053))
        goto loc_8cd6;
    push(si);
    push(es);
    push(ax);
    sub_94d5();
    ax = pop();
    si = 0x70de;
    ax += ax;
    ax += ax;
    si += ax;
    ax = lodsw<DS_SI>();
    dx = ax;
    ax = lodsw<DS_SI>();
    es = dx;
    di = ax;
    ax += memoryAGet16(es, di + 20);
    push(es);
    push(ax);
    sub_9504();
    sp += 0x0004;
    es = pop();
    si = pop();
loc_8cd5: // 01ed:6e05
    sp += 2; return;
loc_8cd6: // 01ed:6e06
    if (ax == 0x0004)
        goto loc_8cf4;
    if (ax == 0x0001)
        goto loc_8ced;
    if (!ax)
        goto loc_8ce6;
    sp += 2; return;
loc_8ce6: // 01ed:6e16
    push(si);
    si = 0x7068;
    goto loc_8cf8;
    // gap 1 bytes // gap 1 bytes
loc_8ced: // 01ed:6e1d
    push(si);
    si = 0x707e;
    goto loc_8cf8;
    // gap 1 bytes // gap 1 bytes
loc_8cf4: // 01ed:6e24
    push(si);
    si = 0x708e;
loc_8cf8: // 01ed:6e28
    al = 0xb6;
    out8(0x43, al);
    ax = lodsw<DS_SI>();
    out8(0x42, al);
    al = ah;
    out8(0x42, al);
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
    memoryASet16(ds, 0x704c, si);
    si = pop();
    sp += 2;
}
void sub_8d0f() // 01ed:6e3f
{
    if (!memoryAGet(ds, 0x7052))
        goto loc_8d19;
    sub_9668();
loc_8d19: // 01ed:6e49
    if (!memoryAGet(ds, 0x7053))
        goto loc_8d23;
    sub_94de();
loc_8d23: // 01ed:6e53
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
}
void sub_8d2a() // 01ed:6e5a
{
    if (!memoryAGet(ds, 0x7052))
        goto loc_8d4b;
    push(ds);
    ax = 0x529d;
    ds = ax;
    cx = 0xaf13;
    dx = 0x7054;
    bx = 0x0008;
    sub_78e1();
    ds = pop();
    if (memoryAGet(ds, 0x0021))
        goto loc_8d4c;
loc_8d4b: // 01ed:6e7b
    return;
loc_8d4c: // 01ed:6e7c
    sub_8d0f();
    memoryASet(ds, 0x7053, 0x00);
    memoryASet(ds, 0x7052, 0x00);
}
void sub_8d5c() // 01ed:6e8c
{
    if (!memoryAGet(ds, 0x7053))
        goto loc_8d7d;
    push(ds);
    ax = 0x5d88;
    ds = ax;
    cx = 0xfe49;
    dx = 0x705e;
    bx = 0x0008;
    sub_78e1();
    ds = pop();
    if (memoryAGet(ds, 0x0021))
        goto loc_8d7e;
loc_8d7d: // 01ed:6ead
    return;
loc_8d7e: // 01ed:6eae
    sub_8d0f();
    memoryASet(ds, 0x7053, 0x00);
    memoryASet(ds, 0x7052, 0x00);
}
void sub_8d8e() // 01ed:6ebe
{
    ax = 0x0013;
    sub_77c8();
    ax = 0x0012;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memoryASet16(ds, 0x26f2, 0x0002);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out8(dx, al);
    memoryASet16(ds, 0x203e, 0x0114);
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    ax = 0x00c7;
    di = 0x2940;
    sub_2c81();
    ax = 0x00c8;
    di = 0x5b40;
    sub_2c81();
    memoryASet16(ds, 0x746c, 0x0000);
    memoryASet16(ds, 0x746e, 0x0094);
    memoryASet16(ds, 0x7474, 0xffff);
    memoryASet16(ds, 0x7476, 0xffff);
    memoryASet16(ds, 0x747a, 0x0000);
    memoryASet(ds, 0x747c, 0x00);
    ax = 0x7620;
    memoryASet16(ds, 0x7478, ax);
    sub_9043();
    sub_2318();
    sub_9043();
    ax = 0x000e;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x08de;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0911;
    cx = 0x0015;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_8e55: // 01ed:6f85
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_9043();
    sub_350c();
    sub_544d();
    if (dx)
        goto loc_8eac;
    if (memoryAGet(ds, 0x747c))
        goto loc_8eac;
    memoryASet16(ds, 0x747a, memoryAGet16(ds, 0x747a) + 1);
    if (memoryAGet16(ds, 0x747a) != 0x00ea)
        goto loc_8eaa;
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x08de;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_8eaa: // 01ed:6fda
    goto loc_8e55;
loc_8eac: // 01ed:6fdc
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_8ed2() // 01ed:7002
{
    ax = 0x0013;
    sub_77c8();
    ax = 0x0011;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memoryASet16(ds, 0x26f2, 0x0001);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out8(dx, al);
    memoryASet16(ds, 0x203e, 0x0100);
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    memoryASet16(ds, 0x746c, 0x0058);
    memoryASet16(ds, 0x746e, 0x0000);
    memoryASet16(ds, 0x7474, 0xffff);
    memoryASet16(ds, 0x7476, 0xffff);
    memoryASet16(ds, 0x747a, 0x0000);
    memoryASet(ds, 0x747c, 0x00);
    ax = 0x86e8;
    memoryASet16(ds, 0x7478, ax);
    ax = 0x00c6;
    di = 0x1420;
    sub_2c81();
    sub_9043();
    sub_2318();
    sub_9043();
    ax = 0x0009;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
loc_8f6d: // 01ed:709d
    sub_2318();
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_9043();
    sub_350c();
    sub_8b8b();
    sub_544d();
    if (dx)
        goto loc_8f96;
    if (memoryAGet(ds, 0x747c))
        goto loc_8f96;
    goto loc_8f6d;
loc_8f96: // 01ed:70c6
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    memoryASet16(ds, 0x37c6, 0xe2b0);
    memoryASet16(ds, 0x37c8, 0x1650);
    ax = 0x0008;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memoryASet16(ds, 0x26f2, 0x0002);
    dx = 0x03d4;
    al = 0x13;
    out8(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out8(dx, al);
    memoryASet16(ds, 0x203e, 0x0080);
    ax = memoryAGet16(ds, 0x001a);
    sub_305b();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
    si = 0x90f8;
    sub_4ef1();
    cx = 0x00b4;
    sub_5429();
    sub_5444();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_9043() // 01ed:7173
{
    si = memoryAGet16(ds, 0x7478);
    memoryASet16(ds, 0x7472, si);
loc_904b: // 01ed:717b
    ax = lodsw<DS_SI>();
    if (ax == 0xfffc)
        goto loc_90ae;
    if (ax == 0xfffd)
        goto loc_9080;
    if (ax == 0xfffe)
        goto loc_90d0;
    if (ax == 0xffff)
        goto loc_9075;
    dx = ax;
    dx += memoryAGet16(ds, 0x746c);
    ax = lodsw<DS_SI>();
    cx = ax;
    cx += memoryAGet16(ds, 0x746e);
    ax = lodsw<DS_SI>();
    push(si);
    sub_276b();
    si = pop();
    goto loc_904b;
loc_9075: // 01ed:71a5
    ax = memoryAGet16(ds, 0x7470);
    memoryASet16(ds, 0x7472, ax);
    memoryASet16(ds, 0x7478, si);
    return;
loc_9080: // 01ed:71b0
    ax = memoryAGet16(ds, 0x7474);
    if (!ax)
        goto loc_90a3;
    if (ax == 0xffff)
        goto loc_9090;
    goto loc_9097;
    // gap 1 bytes // gap 1 bytes
loc_9090: // 01ed:71c0
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, 0x7474, ax);
loc_9097: // 01ed:71c7
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0x7478, ax);
    memoryASet16(ds, 0x7474, memoryAGet16(ds, 0x7474) - 1);
    return;
loc_90a3: // 01ed:71d3
    si += 0x0004;
    memoryASet16(ds, 0x7474, 0xffff);
    goto loc_9075;
loc_90ae: // 01ed:71de
    ax = memoryAGet16(ds, 0x7476);
    if (!ax)
        goto loc_90d7;
    if (ax == 0xffff)
        goto loc_90be;
    goto loc_90c5;
    // gap 1 bytes // gap 1 bytes
loc_90be: // 01ed:71ee
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, 0x7476, ax);
loc_90c5: // 01ed:71f5
    ax = memoryAGet16(ds, 0x7472);
    memoryASet16(ds, 0x7478, ax);
    memoryASet16(ds, 0x7476, memoryAGet16(ds, 0x7476) - 1);
    return;
loc_90d0: // 01ed:7200
    memoryASet(ds, 0x747c, 0xff);
    return;
loc_90d7: // 01ed:7207
    si += 0x0002;
    memoryASet16(ds, 0x7476, 0xffff);
    goto loc_9075;
}
void sub_90e2() // 01ed:7212 +returnCarry
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(cx);
    push(dx);
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x0e;
    cx = 0x0200;
loc_90f6: // 01ed:7226
    al = in8(dx);
    if ((char)al < 0)
        goto loc_9100;
    if (--cx)
        goto loc_90f6;
    flags.carry = 1;
    goto loc_9105;
loc_9100: // 01ed:7230
    dl -= 0x04;
    al = in8(dx);
    flags.carry = 0;
loc_9105: // 01ed:7235
    dx = pop();
    cx = pop();
    ds = pop();
}
void sub_9109() // 01ed:7239 +returnCarry
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(cx);
    push(dx);
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x0c;
    cx = 0x0200;
    ah = al;
loc_911f: // 01ed:724f
    al = in8(dx);
    if ((char)al >= 0)
        goto loc_9129;
    if (--cx)
        goto loc_911f;
    flags.carry = 1;
    goto loc_912d;
loc_9129: // 01ed:7259
    al = ah;
    out8(dx, al);
    flags.carry = 0;
loc_912d: // 01ed:725d
    dx = pop();
    cx = pop();
    ds = pop();
}
void sub_914f() // 01ed:727f
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(dx);
    dx = memoryAGet16(ds, 0x0012);
    dx += 0x000c;
    ah = al;
loc_9161: // 01ed:7291
    al = in8(dx);
    if ((char)al >= 0)
        goto loc_9168;
    goto loc_9161;
loc_9168: // 01ed:7298
    al = ah;
    out8(dx, al);
    dx = pop();
    ds = pop();
}
void sub_916e() // 01ed:729e
{
    push(flagAsReg());
    push(ds);
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = 0;
    push(ax);
    ax = 0;
    ds = ax;
    ax = pop();
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, dx);
    ds = pop();
    flagsFromReg(pop());
}
void sub_9183() // 01ed:72b3
{
    push(flagAsReg());
    push(ds);
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = 0;
    ax = 0;
    ds = ax;
    ax = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    ds = pop();
    flagsFromReg(pop());
}
void sub_91c4() // 01ed:72f4
{
    sp -= 2;
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(bp);
    sp -= 0x0012;
    bp = sp;
    bx = 0x000a;
    sub_9183();
    memoryASet16(ss, bp + 2, ax);
    memoryASet16(ss, bp + 4, dx);
    bx = 0x000a;
    ax = 0x73d9;
    dx = cs;
    sub_916e();
    bx = 0x000b;
    sub_9183();
    memoryASet16(ss, bp + 6, ax);
    memoryASet16(ss, bp + 8, dx);
    bx = 0x000b;
    ax = 0x73bb;
    dx = cs;
    sub_916e();
    bx = 0x000d;
    sub_9183();
    memoryASet16(ss, bp + 10, ax);
    memoryASet16(ss, bp + 12, dx);
    bx = 0x000d;
    ax = 0x73e6;
    dx = cs;
    sub_916e();
    bx = 0x000f;
    sub_9183();
    memoryASet16(ss, bp + 14, ax);
    memoryASet16(ss, bp + 16, dx);
    bx = 0x000f;
    ax = 0x73f3;
    dx = cs;
    sub_916e();
    al = in8(0x21);
    memoryASet(ds, 0x000c, al);
    al &= 0x53;
    out8(0x21, al);
    ax = 0;
    memoryASet16(ds, 0x0014, ax);
    al = 0xf2;
    sub_914f();
    ax = 0;
    cx = ax;
loc_9245: // 01ed:7375
    if (memoryAGet16(ds, 0x0014) != ax)
        goto loc_924d;
    if (--cx)
        goto loc_9245;
loc_924d: // 01ed:737d
    al = memoryAGet(ds, 0x000c);
    out8(0x21, al);
    bx = 0x000f;
    ax = memoryAGet16(ss, bp + 14);
    dx = memoryAGet16(ss, bp + 16);
    sub_916e();
    bx = 0x000d;
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    sub_916e();
    bx = 0x000b;
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 8);
    sub_916e();
    bx = 0x000a;
    ax = memoryAGet16(ss, bp + 2);
    dx = memoryAGet16(ss, bp + 4);
    sub_916e();
    ax = memoryAGet16(ds, 0x0014);
    sp += 0x0012;
    bp = pop();
    ds = pop();
    sp += 2;
}
void sub_92d0() // 01ed:7400
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    push(si);
    si = 0x0220;
loc_92da: // 01ed:740a
    memoryASet16(ds, 0x0012, si);
    sub_92fa();
    if (ax)
        goto loc_92f7;
    si += 0x0010;
    if (si <= 0x0260)
        goto loc_92da;
    memoryASet16(ds, 0x0012, 0x0210);
    sub_92fa();
loc_92f7: // 01ed:7427
    si = pop();
    ds = pop();
}
void sub_92fa() // 01ed:742a
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    bx = 0;
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x06;
    al = 0xc6;
    out8(dx, al);
    al = 0;
    dl += 0x04;
    out8(dx, al);
    al = in8(dx);
    if (al != 0xc6)
        goto loc_932f;
    dl -= 0x04;
    al = 0x39;
    out8(dx, al);
    al = 0;
    dl += 0x04;
    out8(dx, al);
    al = in8(dx);
    if (al != 0x39)
        goto loc_932f;
    bx = 0x0001;
    goto loc_9353;
loc_932f: // 01ed:745f
    sub_953a();
    if (flags.carry)
        goto loc_9353;
    al = 0xe0;
    sub_9109();
    if (flags.carry)
        goto loc_9353;
    al = 0xc6;
    sub_9109();
    if (flags.carry)
        goto loc_9353;
    sub_90e2();
    if (flags.carry)
        goto loc_9353;
    if (al != 0x39)
        goto loc_9353;
    bx = 0x0004;
    push(bx);
    sub_93b3();
    bx = pop();
loc_9353: // 01ed:7483
    ax = 0x0100;
    sub_9430();
    ax = 0x0460;
    sub_9430();
    ax = 0x0480;
    sub_9430();
    al = 0x00;
    sub_9392();
    if (flags.carry)
        goto loc_938e;
    ax = 0x02ff;
    sub_9430();
    ax = 0x0421;
    sub_9430();
    al = 0xc0;
    sub_9392();
    if (flags.carry)
        goto loc_938e;
    ax = 0x0460;
    sub_9430();
    ax = 0x0480;
    sub_9430();
    bx += 0x0002;
loc_938e: // 01ed:74be
    ax = bx;
    ds = pop();
}
void sub_9392() // 01ed:74c2 +returnCarry
{
    push(cx);
    push(dx);
    cx = 0x0040;
    ah = al;
    ah &= 0xe0;
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x08;
loc_93a3: // 01ed:74d3
    al = in8(dx);
    al &= 0xe0;
    if (ah == al)
        goto loc_93af;
    if (--cx)
        goto loc_93a3;
    flags.carry = 1;
    goto loc_93b0;
loc_93af: // 01ed:74df
    flags.carry = 0;
loc_93b0: // 01ed:74e0
    dx = pop();
    cx = pop();
}
void sub_93b3() // 01ed:74e3
{
    sp -= 2;
    push(bp);
    sp -= 0x0004;
    bp = sp;
    bx = 0x0008;
    sub_9183();
    memoryASet16(ss, bp, ax);
    memoryASet16(ss, bp + 2, dx);
    flags.interrupts = 0;
    al = in8(0x21);
    memoryASet16(ds, 0x0016, ax);
    al = 0xfe;
    out8(0x21, al);
    ax = 0x1b58;
    sub_9459();
    bx = 0x0008;
    dx = cs;
    ax = 0x7596;
    sub_916e();
    ax = 0;
    cx = 0;
    flags.interrupts = 1;
loc_93e5: // 01ed:7515
    if (!ax)
        goto loc_93e5;
loc_93e9: // 01ed:7519
    if (ax)
        goto loc_93e9;
loc_93ed: // 01ed:751d
    cx++;
    if (!ax)
        goto loc_93ed;
    flags.interrupts = 0;
    ax = memoryAGet16(ds, 0x0016);
    out8(0x21, al);
    ax = 0xffff;
    sub_9459();
    flags.interrupts = 1;
    bx = 0x0008;
    dx = memoryAGet16(ss, bp + 2);
    ax = memoryAGet16(ss, bp);
    sub_916e();
    ax = cx;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    cl = 0x0a;
    ax >>= cl;
    memoryASet16(ds, 0x0016, ax);
    cx = ax;
    ax <<= 1;
    cx += ax;
    ax <<= 1;
    cx += ax;
    memoryASet16(ds, 0x0018, cx);
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_9430() // 01ed:7560
{
    push(ax);
    push(cx);
    push(dx);
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x08;
    tl = al; al = ah; ah = tl;
    out8(dx, al);
    cx = memoryAGet16(ds, 0x0016);
loc_9441: // 01ed:7571
    cx--;
    if (cx)
        goto loc_9441;
    dx++;
    al = ah;
    out8(dx, al);
    cx = memoryAGet16(ds, 0x0018);
loc_944f: // 01ed:757f
    cx--;
    if (cx)
        goto loc_944f;
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_9459() // 01ed:7589
{
    push(ax);
    al = 0x36;
    out8(0x43, al);
    ax = pop();
    out8(0x40, al);
    al = ah;
    out8(0x40, al);
}
void sub_9479() // 01ed:75a9
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    bx = 0x0001;
    ax = memoryAGet16(ds, 0x0012);
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
    bx = 0x0002;
    ax = memoryAGet16(ds, 0x0014);
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
    bx = 0x0003;
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
    push(es);
    ax = 0x0b51;
    es = ax;
    di = 0x000e;
    bx = 0x0005;
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
    es = pop();
    ds = pop();
}
void sub_94d5() // 01ed:7605
{
    bx = 0x0008;
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
}
void sub_94de() // 01ed:760e
{
    bx = 0x0009;
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
}
void sub_9504() // 01ed:7634
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(es);
    push(di);
    bx = 0x0006;
    di = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 6);
    push(cs); cs = 0x096b; sub_96b0(); assert(cs == 0x01ed);
    di = pop();
    es = pop();
    bp = pop();
    sp += 2;
}
void sub_953a() // 01ed:766a +returnCarry
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    dx = memoryAGet16(ds, 0x0012);
    dl += 0x06;
    al = 0x01;
    out8(dx, al);
    al = 0;
loc_954c: // 01ed:767c
    al--;
    if (al)
        goto loc_954c;
    out8(dx, al);
    cx = 0x0020;
loc_9554: // 01ed:7684
    sub_90e2();
    if (flags.carry)
        goto loc_9561;
    if (al != 0xaa)
        goto loc_9561;
    flags.carry = ax < ax;
    ax = 0;
    goto loc_9567;
loc_9561: // 01ed:7691
    if (--cx)
        goto loc_9554;
    flags.carry = 1;
    ax = 0x0001;
loc_9567: // 01ed:7697
    ds = pop();
}
void sub_956a() // 01ed:769a
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    ax = memoryAGet16(ds, 0x0012);
    bx = 0xfffd;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bx = 0xffff;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    if (flags.carry)
        goto loc_95a1;
    dx = 0x0b51;
    ax = 0x0010;
    bx = 0x0001;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    memoryASet16(cs, 0x76d7, dx);
    memoryASet16(cs, 0x76d5, ax);
    ax = 0x0001;
    goto loc_95a3;
loc_95a1: // 01ed:76d1
    ax = 0;
loc_95a3: // 01ed:76d3
    ds = pop();
}
void sub_95bc() // 01ed:76ec
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bx = 0x0006;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_95cf() // 01ed:76ff
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    bx = 0x0002;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_95e5() // 01ed:7715
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = 0x0008;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_9602() // 01ed:7732
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bx = 0x0004;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_9612() // 01ed:7742
{
    bx = 0x0007;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
}
void sub_9634() // 01ed:7764
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = 0x0009;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_9641() // 01ed:7771
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = 0x000a;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_964e() // 01ed:777e
{
    push(flagAsReg());
    push(ds);
    ax = 0x0b51;
    ds = ax;
    ax = 0;
    flags.interrupts = 0;
    if (!memoryAGet(ds, 0x0010))
        goto loc_9665;
    al = 0xff;
    tl = memoryAGet(ds, 0x0010); memoryASet(ds, 0x0010, al); al = tl;
loc_9665: // 01ed:7795
    ds = pop();
    flagsFromReg(pop());
}
void sub_9668() // 01ed:7798
{
    bx = 0xfffe;
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
    bx = 0x0001;
    dx = memoryAGet16(cs, 0x76d7);
    ax = memoryAGet16(cs, 0x76d5);
    push(cs); cs = 0x0a07; sub_a070(); assert(cs == 0x01ed);
}
void sub_96b0() // 096b:0000 +far
{
    sub_9e04();
}
void sub_9e04() // 096b:0754 +stackDrop2
{
    sp -= 2;
    push(flagAsReg());
    push(ds);
    push(es);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(bp);
    bp = sp;
    push(ax);
    ax = cs;
    ds = ax;
    es = ax;
    ax = pop();
    flags.direction = 0;
    if (bx >= 0x000e)
        goto loc_9e35;
    if (bx < 0x0004)
        goto loc_9e2a;
    if (!memoryAGet(ds, 0x00b1))
        goto loc_9e35;
loc_9e2a: // 096b:077a
    bx <<= 1;
    switch (memoryAGet16(ds, bx + 133))
    {
        default:
            printf("indirect call from 096b:077c to 0x%04x\n", memoryAGet16(ds, bx + 133));
            stop("ind 096b:077c");
    }
    memoryASet16(ss, bp + 12, ax);
    goto loc_9e3a;
loc_9e35: // 096b:0785
    memoryASet16(ss, bp + 12, 0xffff);
loc_9e3a: // 096b:078a
    bp = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    es = pop();
    ds = pop();
    flagsFromReg(pop());
    sp += 2; cs = pop();
}
void sub_a070() // 0a07:0000 +far +returnCarry
{
    sub_b17f();
}
void sub_b17f() // 0a07:110f +stackDrop2
{
    sp -= 2;
    push(ds);
    push(es);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(bp);
    bp = sp;
    ax = cs;
    ds = ax;
    es = ax;
    ax = memoryAGet16(ss, bp + 12);
    if (memoryAGet(ds, 0x01e4))
        goto loc_b1ce;
    memoryASet(ds, 0x01e4, 0x01);
    flags.interrupts = 1;
    flags.direction = 0;
    memoryASet16(ss, bp + 12, 0xffff);
    if ((short)bx < 0)
        goto loc_b1b7;
    if (bx >= 0x000f)
        goto loc_b1c7;
    bx <<= 1;
    switch (memoryAGet16(ds, bx + 609))
    {
        default:
            printf("indirect call from 0a07:1141 to 0x%04x\n", memoryAGet16(ds, bx + 609));
            stop("ind 0a07:1141");
    }
    goto loc_b1c4;
loc_b1b7: // 0a07:1147
    bx = ~bx;
    if (bx >= 0x0003)
        goto loc_b1c7;
    bx <<= 1;
    switch (memoryAGet16(ds, bx + 639))
    {
        default:
            printf("indirect call from 0a07:1150 to 0x%04x\n", memoryAGet16(ds, bx + 639));
            stop("ind 0a07:1150");
    }
loc_b1c4: // 0a07:1154
    memoryASet16(ss, bp + 12, ax);
loc_b1c7: // 0a07:1157
    memoryASet(ds, 0x01e4, 0x00);
    goto loc_b1d3;
loc_b1ce: // 0a07:115e
    memoryASet16(ss, bp + 12, 0xfff8);
loc_b1d3: // 0a07:1163
    bp = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    es = pop();
    ds = pop();
    sp += 2; cs = pop();
}
void fixReloc(uint16_t seg)
{
        memoryASet16(seg, 0x0001, memoryAGet16(seg, 0x0001) + seg); // 0965 -> 0b52; lin=1
        memoryASet16(0x002c + seg, 0x000c, memoryAGet16(0x002c + seg, 0x000c) + seg); // 2403 -> 25f0; lin=2cc
        memoryASet16(0x004e + seg, 0x000d, memoryAGet16(0x004e + seg, 0x000d) + seg); // 0965 -> 0b52; lin=4ed
        memoryASet16(0x0050 + seg, 0x0004, memoryAGet16(0x0050 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=504
        memoryASet16(0x0050 + seg, 0x000c, memoryAGet16(0x0050 + seg, 0x000c) + seg); // 0965 -> 0b52; lin=50c
        memoryASet16(0x0051 + seg, 0x000d, memoryAGet16(0x0051 + seg, 0x000d) + seg); // 2403 -> 25f0; lin=51d
        memoryASet16(0x0054 + seg, 0x0008, memoryAGet16(0x0054 + seg, 0x0008) + seg); // 0965 -> 0b52; lin=548
        memoryASet16(0x0057 + seg, 0x0009, memoryAGet16(0x0057 + seg, 0x0009) + seg); // 0965 -> 0b52; lin=579
        memoryASet16(0x00ba + seg, 0x000f, memoryAGet16(0x00ba + seg, 0x000f) + seg); // 4110 -> 42fd; lin=baf
        memoryASet16(0x00bc + seg, 0x0006, memoryAGet16(0x00bc + seg, 0x0006) + seg); // 4110 -> 42fd; lin=bc6
        memoryASet16(0x00bd + seg, 0x000e, memoryAGet16(0x00bd + seg, 0x000e) + seg); // 4110 -> 42fd; lin=bde
        memoryASet16(0x00bf + seg, 0x0005, memoryAGet16(0x00bf + seg, 0x0005) + seg); // 4110 -> 42fd; lin=bf5
        memoryASet16(0x00d9 + seg, 0x000c, memoryAGet16(0x00d9 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=d9c
        memoryASet16(0x0135 + seg, 0x000e, memoryAGet16(0x0135 + seg, 0x000e) + seg); // 0965 -> 0b52; lin=135e
        memoryASet16(0x013f + seg, 0x0002, memoryAGet16(0x013f + seg, 0x0002) + seg); // 0000 -> 01ed; lin=13f2
        memoryASet16(0x013f + seg, 0x000b, memoryAGet16(0x013f + seg, 0x000b) + seg); // 0965 -> 0b52; lin=13fb
        memoryASet16(0x0140 + seg, 0x0001, memoryAGet16(0x0140 + seg, 0x0001) + seg); // 0000 -> 01ed; lin=1401
        memoryASet16(0x0141 + seg, 0x0009, memoryAGet16(0x0141 + seg, 0x0009) + seg); // 0965 -> 0b52; lin=1419
        memoryASet16(0x014e + seg, 0x0000, memoryAGet16(0x014e + seg, 0x0000) + seg); // 0000 -> 01ed; lin=14e0
        memoryASet16(0x014e + seg, 0x0009, memoryAGet16(0x014e + seg, 0x0009) + seg); // 0965 -> 0b52; lin=14e9
        memoryASet16(0x014e + seg, 0x000f, memoryAGet16(0x014e + seg, 0x000f) + seg); // 0000 -> 01ed; lin=14ef
        memoryASet16(0x0157 + seg, 0x0004, memoryAGet16(0x0157 + seg, 0x0004) + seg); // 0000 -> 01ed; lin=1574
        memoryASet16(0x0159 + seg, 0x0002, memoryAGet16(0x0159 + seg, 0x0002) + seg); // 0000 -> 01ed; lin=1592
        memoryASet16(0x015a + seg, 0x000e, memoryAGet16(0x015a + seg, 0x000e) + seg); // 0000 -> 01ed; lin=15ae
        memoryASet16(0x015b + seg, 0x000b, memoryAGet16(0x015b + seg, 0x000b) + seg); // 0000 -> 01ed; lin=15bb
        memoryASet16(0x015c + seg, 0x0008, memoryAGet16(0x015c + seg, 0x0008) + seg); // 0000 -> 01ed; lin=15c8
        memoryASet16(0x015f + seg, 0x0005, memoryAGet16(0x015f + seg, 0x0005) + seg); // 0965 -> 0b52; lin=15f5
        memoryASet16(0x0160 + seg, 0x0008, memoryAGet16(0x0160 + seg, 0x0008) + seg); // 0965 -> 0b52; lin=1608
        memoryASet16(0x0162 + seg, 0x0005, memoryAGet16(0x0162 + seg, 0x0005) + seg); // 0965 -> 0b52; lin=1625
        memoryASet16(0x0218 + seg, 0x000c, memoryAGet16(0x0218 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=218c
        memoryASet16(0x0219 + seg, 0x0008, memoryAGet16(0x0219 + seg, 0x0008) + seg); // 4110 -> 42fd; lin=2198
        memoryASet16(0x0245 + seg, 0x0006, memoryAGet16(0x0245 + seg, 0x0006) + seg); // 1463 -> 1650; lin=2456
        memoryASet16(0x0246 + seg, 0x0002, memoryAGet16(0x0246 + seg, 0x0002) + seg); // 1463 -> 1650; lin=2462
        memoryASet16(0x024d + seg, 0x0001, memoryAGet16(0x024d + seg, 0x0001) + seg); // 1463 -> 1650; lin=24d1
        memoryASet16(0x024e + seg, 0x000e, memoryAGet16(0x024e + seg, 0x000e) + seg); // 1463 -> 1650; lin=24ee
        memoryASet16(0x0250 + seg, 0x000b, memoryAGet16(0x0250 + seg, 0x000b) + seg); // 1463 -> 1650; lin=250b
        memoryASet16(0x02c3 + seg, 0x0005, memoryAGet16(0x02c3 + seg, 0x0005) + seg); // 2403 -> 25f0; lin=2c35
        memoryASet16(0x02f8 + seg, 0x0008, memoryAGet16(0x02f8 + seg, 0x0008) + seg); // 1463 -> 1650; lin=2f88
        memoryASet16(0x02fa + seg, 0x0002, memoryAGet16(0x02fa + seg, 0x0002) + seg); // 1463 -> 1650; lin=2fa2
        memoryASet16(0x02fd + seg, 0x000a, memoryAGet16(0x02fd + seg, 0x000a) + seg); // 1463 -> 1650; lin=2fda
        memoryASet16(0x0353 + seg, 0x0003, memoryAGet16(0x0353 + seg, 0x0003) + seg); // 3170 -> 335d; lin=3533
        memoryASet16(0x039f + seg, 0x0000, memoryAGet16(0x039f + seg, 0x0000) + seg); // 2403 -> 25f0; lin=39f0
        memoryASet16(0x03a0 + seg, 0x0009, memoryAGet16(0x03a0 + seg, 0x0009) + seg); // 0965 -> 0b52; lin=3a09
        memoryASet16(0x03a0 + seg, 0x000e, memoryAGet16(0x03a0 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=3a0e
        memoryASet16(0x03d0 + seg, 0x0002, memoryAGet16(0x03d0 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=3d02
        memoryASet16(0x03d3 + seg, 0x000d, memoryAGet16(0x03d3 + seg, 0x000d) + seg); // 4110 -> 42fd; lin=3d3d
        memoryASet16(0x0573 + seg, 0x0008, memoryAGet16(0x0573 + seg, 0x0008) + seg); // 2403 -> 25f0; lin=5738
        memoryASet16(0x0579 + seg, 0x0003, memoryAGet16(0x0579 + seg, 0x0003) + seg); // 2403 -> 25f0; lin=5793
        memoryASet16(0x057a + seg, 0x0003, memoryAGet16(0x057a + seg, 0x0003) + seg); // 2403 -> 25f0; lin=57a3
        memoryASet16(0x057a + seg, 0x000e, memoryAGet16(0x057a + seg, 0x000e) + seg); // 2403 -> 25f0; lin=57ae
        memoryASet16(0x0591 + seg, 0x0001, memoryAGet16(0x0591 + seg, 0x0001) + seg); // 2403 -> 25f0; lin=5911
        memoryASet16(0x0595 + seg, 0x0006, memoryAGet16(0x0595 + seg, 0x0006) + seg); // 3170 -> 335d; lin=5956
        memoryASet16(0x059d + seg, 0x0004, memoryAGet16(0x059d + seg, 0x0004) + seg); // 0965 -> 0b52; lin=59d4
        memoryASet16(0x05a1 + seg, 0x0003, memoryAGet16(0x05a1 + seg, 0x0003) + seg); // 0965 -> 0b52; lin=5a13
        memoryASet16(0x05a3 + seg, 0x0008, memoryAGet16(0x05a3 + seg, 0x0008) + seg); // 0965 -> 0b52; lin=5a38
        memoryASet16(0x062b + seg, 0x000d, memoryAGet16(0x062b + seg, 0x000d) + seg); // 1463 -> 1650; lin=62bd
        memoryASet16(0x062d + seg, 0x0001, memoryAGet16(0x062d + seg, 0x0001) + seg); // 1463 -> 1650; lin=62d1
        memoryASet16(0x06e6 + seg, 0x0003, memoryAGet16(0x06e6 + seg, 0x0003) + seg); // 50b0 -> 529d; lin=6e63
        memoryASet16(0x06e9 + seg, 0x0005, memoryAGet16(0x06e9 + seg, 0x0005) + seg); // 5b9b -> 5d88; lin=6e95
        memoryASet16(0x070f + seg, 0x0005, memoryAGet16(0x070f + seg, 0x0005) + seg); // 1463 -> 1650; lin=70f5
        memoryASet16(0x0721 + seg, 0x0005, memoryAGet16(0x0721 + seg, 0x0005) + seg); // 0964 -> 0b51; lin=7215
        memoryASet16(0x0723 + seg, 0x000c, memoryAGet16(0x0723 + seg, 0x000c) + seg); // 0964 -> 0b51; lin=723c
        memoryASet16(0x0726 + seg, 0x0004, memoryAGet16(0x0726 + seg, 0x0004) + seg); // 0964 -> 0b51; lin=7264
        memoryASet16(0x0728 + seg, 0x0002, memoryAGet16(0x0728 + seg, 0x0002) + seg); // 0964 -> 0b51; lin=7282
        memoryASet16(0x072f + seg, 0x0007, memoryAGet16(0x072f + seg, 0x0007) + seg); // 0964 -> 0b51; lin=72f7
        memoryASet16(0x073b + seg, 0x000f, memoryAGet16(0x073b + seg, 0x000f) + seg); // 0964 -> 0b51; lin=73bf
        memoryASet16(0x073d + seg, 0x000d, memoryAGet16(0x073d + seg, 0x000d) + seg); // 0964 -> 0b51; lin=73dd
        memoryASet16(0x073e + seg, 0x000a, memoryAGet16(0x073e + seg, 0x000a) + seg); // 0964 -> 0b51; lin=73ea
        memoryASet16(0x073f + seg, 0x0007, memoryAGet16(0x073f + seg, 0x0007) + seg); // 0964 -> 0b51; lin=73f7
        memoryASet16(0x0740 + seg, 0x0002, memoryAGet16(0x0740 + seg, 0x0002) + seg); // 0964 -> 0b51; lin=7402
        memoryASet16(0x0742 + seg, 0x000d, memoryAGet16(0x0742 + seg, 0x000d) + seg); // 0964 -> 0b51; lin=742d
        memoryASet16(0x075a + seg, 0x0006, memoryAGet16(0x075a + seg, 0x0006) + seg); // 077e -> 096b; lin=75a6
        memoryASet16(0x075a + seg, 0x000b, memoryAGet16(0x075a + seg, 0x000b) + seg); // 0964 -> 0b51; lin=75ab
        memoryASet16(0x075b + seg, 0x0008, memoryAGet16(0x075b + seg, 0x0008) + seg); // 077e -> 096b; lin=75b8
        memoryASet16(0x075c + seg, 0x0003, memoryAGet16(0x075c + seg, 0x0003) + seg); // 077e -> 096b; lin=75c3
        memoryASet16(0x075c + seg, 0x000b, memoryAGet16(0x075c + seg, 0x000b) + seg); // 077e -> 096b; lin=75cb
        memoryASet16(0x075c + seg, 0x000f, memoryAGet16(0x075c + seg, 0x000f) + seg); // 0964 -> 0b51; lin=75cf
        memoryASet16(0x075d + seg, 0x000c, memoryAGet16(0x075d + seg, 0x000c) + seg); // 077e -> 096b; lin=75dc
        memoryASet16(0x075e + seg, 0x000d, memoryAGet16(0x075e + seg, 0x000d) + seg); // 077e -> 096b; lin=75ed
        memoryASet16(0x075f + seg, 0x000f, memoryAGet16(0x075f + seg, 0x000f) + seg); // 077e -> 096b; lin=75ff
        memoryASet16(0x0760 + seg, 0x000b, memoryAGet16(0x0760 + seg, 0x000b) + seg); // 077e -> 096b; lin=760b
        memoryASet16(0x0761 + seg, 0x0004, memoryAGet16(0x0761 + seg, 0x0004) + seg); // 077e -> 096b; lin=7614
        memoryASet16(0x0762 + seg, 0x000e, memoryAGet16(0x0762 + seg, 0x000e) + seg); // 077e -> 096b; lin=762e
        memoryASet16(0x0764 + seg, 0x0002, memoryAGet16(0x0764 + seg, 0x0002) + seg); // 077e -> 096b; lin=7642
        memoryASet16(0x0764 + seg, 0x000e, memoryAGet16(0x0764 + seg, 0x000e) + seg); // 077e -> 096b; lin=764e
        memoryASet16(0x0765 + seg, 0x0007, memoryAGet16(0x0765 + seg, 0x0007) + seg); // 077e -> 096b; lin=7657
        memoryASet16(0x0766 + seg, 0x0006, memoryAGet16(0x0766 + seg, 0x0006) + seg); // 077e -> 096b; lin=7666
        memoryASet16(0x0766 + seg, 0x000c, memoryAGet16(0x0766 + seg, 0x000c) + seg); // 0964 -> 0b51; lin=766c
        memoryASet16(0x0769 + seg, 0x000c, memoryAGet16(0x0769 + seg, 0x000c) + seg); // 0964 -> 0b51; lin=769c
        memoryASet16(0x076a + seg, 0x0009, memoryAGet16(0x076a + seg, 0x0009) + seg); // 081a -> 0a07; lin=76a9
        memoryASet16(0x076b + seg, 0x0001, memoryAGet16(0x076b + seg, 0x0001) + seg); // 081a -> 0a07; lin=76b1
        memoryASet16(0x076b + seg, 0x0006, memoryAGet16(0x076b + seg, 0x0006) + seg); // 0964 -> 0b51; lin=76b6
        memoryASet16(0x076c + seg, 0x0001, memoryAGet16(0x076c + seg, 0x0001) + seg); // 081a -> 0a07; lin=76c1
        memoryASet16(0x076e + seg, 0x0008, memoryAGet16(0x076e + seg, 0x0008) + seg); // 081a -> 0a07; lin=76e8
        memoryASet16(0x076f + seg, 0x000b, memoryAGet16(0x076f + seg, 0x000b) + seg); // 081a -> 0a07; lin=76fb
        memoryASet16(0x0771 + seg, 0x0001, memoryAGet16(0x0771 + seg, 0x0001) + seg); // 081a -> 0a07; lin=7711
        memoryASet16(0x0771 + seg, 0x000e, memoryAGet16(0x0771 + seg, 0x000e) + seg); // 081a -> 0a07; lin=771e
        memoryASet16(0x0772 + seg, 0x000e, memoryAGet16(0x0772 + seg, 0x000e) + seg); // 081a -> 0a07; lin=772e
        memoryASet16(0x0773 + seg, 0x000e, memoryAGet16(0x0773 + seg, 0x000e) + seg); // 081a -> 0a07; lin=773e
        memoryASet16(0x0774 + seg, 0x0008, memoryAGet16(0x0774 + seg, 0x0008) + seg); // 081a -> 0a07; lin=7748
        memoryASet16(0x0775 + seg, 0x0001, memoryAGet16(0x0775 + seg, 0x0001) + seg); // 081a -> 0a07; lin=7751
        memoryASet16(0x0776 + seg, 0x0000, memoryAGet16(0x0776 + seg, 0x0000) + seg); // 081a -> 0a07; lin=7760
        memoryASet16(0x0776 + seg, 0x000d, memoryAGet16(0x0776 + seg, 0x000d) + seg); // 081a -> 0a07; lin=776d
        memoryASet16(0x0777 + seg, 0x000a, memoryAGet16(0x0777 + seg, 0x000a) + seg); // 081a -> 0a07; lin=777a
        memoryASet16(0x0778 + seg, 0x0001, memoryAGet16(0x0778 + seg, 0x0001) + seg); // 0964 -> 0b51; lin=7781
        memoryASet16(0x0779 + seg, 0x000e, memoryAGet16(0x0779 + seg, 0x000e) + seg); // 081a -> 0a07; lin=779e
        memoryASet16(0x077a + seg, 0x000f, memoryAGet16(0x077a + seg, 0x000f) + seg); // 081a -> 0a07; lin=77af
        memoryASet16(0x077b + seg, 0x0008, memoryAGet16(0x077b + seg, 0x0008) + seg); // 081a -> 0a07; lin=77b8
        memoryASet16(0x077c + seg, 0x0002, memoryAGet16(0x077c + seg, 0x0002) + seg); // 081a -> 0a07; lin=77c2
        memoryASet16(0x077d + seg, 0x000b, memoryAGet16(0x077d + seg, 0x000b) + seg); // 081a -> 0a07; lin=77db
        memoryASet16(0x0a53 + seg, 0x0004, memoryAGet16(0x0a53 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a534
        memoryASet16(0x0a53 + seg, 0x000c, memoryAGet16(0x0a53 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a53c
        memoryASet16(0x0a54 + seg, 0x0004, memoryAGet16(0x0a54 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a544
        memoryASet16(0x0a54 + seg, 0x000c, memoryAGet16(0x0a54 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a54c
        memoryASet16(0x0a55 + seg, 0x0004, memoryAGet16(0x0a55 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a554
        memoryASet16(0x0a55 + seg, 0x000c, memoryAGet16(0x0a55 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a55c
        memoryASet16(0x0a56 + seg, 0x0004, memoryAGet16(0x0a56 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a564
        memoryASet16(0x0a56 + seg, 0x000c, memoryAGet16(0x0a56 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a56c
        memoryASet16(0x0a57 + seg, 0x0004, memoryAGet16(0x0a57 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a574
        memoryASet16(0x0a57 + seg, 0x000c, memoryAGet16(0x0a57 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a57c
        memoryASet16(0x0a58 + seg, 0x0004, memoryAGet16(0x0a58 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a584
        memoryASet16(0x0a58 + seg, 0x000c, memoryAGet16(0x0a58 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a58c
        memoryASet16(0x0a59 + seg, 0x0004, memoryAGet16(0x0a59 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a594
        memoryASet16(0x0a59 + seg, 0x000c, memoryAGet16(0x0a59 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a59c
        memoryASet16(0x0a5a + seg, 0x0004, memoryAGet16(0x0a5a + seg, 0x0004) + seg); // 1463 -> 1650; lin=a5a4
        memoryASet16(0x0a5a + seg, 0x000c, memoryAGet16(0x0a5a + seg, 0x000c) + seg); // 1463 -> 1650; lin=a5ac
        memoryASet16(0x0a5b + seg, 0x0004, memoryAGet16(0x0a5b + seg, 0x0004) + seg); // 1463 -> 1650; lin=a5b4
        memoryASet16(0x0a5b + seg, 0x000c, memoryAGet16(0x0a5b + seg, 0x000c) + seg); // 3170 -> 335d; lin=a5bc
        memoryASet16(0x0a5c + seg, 0x0004, memoryAGet16(0x0a5c + seg, 0x0004) + seg); // 3170 -> 335d; lin=a5c4
        memoryASet16(0x0a5c + seg, 0x000c, memoryAGet16(0x0a5c + seg, 0x000c) + seg); // 3170 -> 335d; lin=a5cc
        memoryASet16(0x0a5d + seg, 0x0004, memoryAGet16(0x0a5d + seg, 0x0004) + seg); // 3170 -> 335d; lin=a5d4
        memoryASet16(0x0a5d + seg, 0x000c, memoryAGet16(0x0a5d + seg, 0x000c) + seg); // 3170 -> 335d; lin=a5dc
        memoryASet16(0x0a5e + seg, 0x0004, memoryAGet16(0x0a5e + seg, 0x0004) + seg); // 3170 -> 335d; lin=a5e4
        memoryASet16(0x0a5e + seg, 0x000c, memoryAGet16(0x0a5e + seg, 0x000c) + seg); // 3170 -> 335d; lin=a5ec
        memoryASet16(0x0a5f + seg, 0x0004, memoryAGet16(0x0a5f + seg, 0x0004) + seg); // 3170 -> 335d; lin=a5f4
        memoryASet16(0x0a5f + seg, 0x000c, memoryAGet16(0x0a5f + seg, 0x000c) + seg); // 3170 -> 335d; lin=a5fc
        memoryASet16(0x0a60 + seg, 0x0004, memoryAGet16(0x0a60 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a604
        memoryASet16(0x0a60 + seg, 0x000c, memoryAGet16(0x0a60 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a60c
        memoryASet16(0x0a61 + seg, 0x0004, memoryAGet16(0x0a61 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a614
        memoryASet16(0x0a61 + seg, 0x000c, memoryAGet16(0x0a61 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a61c
        memoryASet16(0x0a62 + seg, 0x0004, memoryAGet16(0x0a62 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a624
        memoryASet16(0x0a62 + seg, 0x000c, memoryAGet16(0x0a62 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a62c
        memoryASet16(0x0a63 + seg, 0x0004, memoryAGet16(0x0a63 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a634
        memoryASet16(0x0a63 + seg, 0x000c, memoryAGet16(0x0a63 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a63c
        memoryASet16(0x0a64 + seg, 0x0004, memoryAGet16(0x0a64 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a644
        memoryASet16(0x0a64 + seg, 0x000c, memoryAGet16(0x0a64 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a64c
        memoryASet16(0x0a65 + seg, 0x0004, memoryAGet16(0x0a65 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a654
        memoryASet16(0x0a65 + seg, 0x000c, memoryAGet16(0x0a65 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a65c
        memoryASet16(0x0a66 + seg, 0x0004, memoryAGet16(0x0a66 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a664
        memoryASet16(0x0a66 + seg, 0x000c, memoryAGet16(0x0a66 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a66c
        memoryASet16(0x0a67 + seg, 0x0004, memoryAGet16(0x0a67 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a674
        memoryASet16(0x0a67 + seg, 0x000c, memoryAGet16(0x0a67 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a67c
        memoryASet16(0x0a68 + seg, 0x0004, memoryAGet16(0x0a68 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a684
        memoryASet16(0x0a68 + seg, 0x000c, memoryAGet16(0x0a68 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a68c
        memoryASet16(0x0a69 + seg, 0x0004, memoryAGet16(0x0a69 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a694
        memoryASet16(0x0a69 + seg, 0x000c, memoryAGet16(0x0a69 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a69c
        memoryASet16(0x0a6a + seg, 0x0004, memoryAGet16(0x0a6a + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6a4
        memoryASet16(0x0a6a + seg, 0x000c, memoryAGet16(0x0a6a + seg, 0x000c) + seg); // 1463 -> 1650; lin=a6ac
        memoryASet16(0x0a6b + seg, 0x0004, memoryAGet16(0x0a6b + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6b4
        memoryASet16(0x0a6b + seg, 0x000c, memoryAGet16(0x0a6b + seg, 0x000c) + seg); // 1463 -> 1650; lin=a6bc
        memoryASet16(0x0a6c + seg, 0x0004, memoryAGet16(0x0a6c + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6c4
        memoryASet16(0x0a6c + seg, 0x000c, memoryAGet16(0x0a6c + seg, 0x000c) + seg); // 1463 -> 1650; lin=a6cc
        memoryASet16(0x0a6d + seg, 0x0004, memoryAGet16(0x0a6d + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6d4
        memoryASet16(0x0a6d + seg, 0x000c, memoryAGet16(0x0a6d + seg, 0x000c) + seg); // 1463 -> 1650; lin=a6dc
        memoryASet16(0x0a6e + seg, 0x0004, memoryAGet16(0x0a6e + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6e4
        memoryASet16(0x0a6e + seg, 0x000c, memoryAGet16(0x0a6e + seg, 0x000c) + seg); // 1463 -> 1650; lin=a6ec
        memoryASet16(0x0a6f + seg, 0x0004, memoryAGet16(0x0a6f + seg, 0x0004) + seg); // 1463 -> 1650; lin=a6f4
        memoryASet16(0x0a6f + seg, 0x000c, memoryAGet16(0x0a6f + seg, 0x000c) + seg); // 3170 -> 335d; lin=a6fc
        memoryASet16(0x0a70 + seg, 0x0004, memoryAGet16(0x0a70 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a704
        memoryASet16(0x0a70 + seg, 0x000c, memoryAGet16(0x0a70 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a70c
        memoryASet16(0x0a71 + seg, 0x0004, memoryAGet16(0x0a71 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a714
        memoryASet16(0x0a71 + seg, 0x000c, memoryAGet16(0x0a71 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a71c
        memoryASet16(0x0a72 + seg, 0x0004, memoryAGet16(0x0a72 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a724
        memoryASet16(0x0a72 + seg, 0x000c, memoryAGet16(0x0a72 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a72c
        memoryASet16(0x0a73 + seg, 0x0004, memoryAGet16(0x0a73 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a734
        memoryASet16(0x0a73 + seg, 0x000c, memoryAGet16(0x0a73 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a73c
        memoryASet16(0x0a74 + seg, 0x0004, memoryAGet16(0x0a74 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a744
        memoryASet16(0x0a74 + seg, 0x000c, memoryAGet16(0x0a74 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a74c
        memoryASet16(0x0a75 + seg, 0x0004, memoryAGet16(0x0a75 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a754
        memoryASet16(0x0a75 + seg, 0x000c, memoryAGet16(0x0a75 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a75c
        memoryASet16(0x0a76 + seg, 0x0004, memoryAGet16(0x0a76 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a764
        memoryASet16(0x0a76 + seg, 0x000c, memoryAGet16(0x0a76 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a76c
        memoryASet16(0x0a77 + seg, 0x0004, memoryAGet16(0x0a77 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a774
        memoryASet16(0x0a77 + seg, 0x000c, memoryAGet16(0x0a77 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a77c
        memoryASet16(0x0a78 + seg, 0x0004, memoryAGet16(0x0a78 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a784
        memoryASet16(0x0a78 + seg, 0x000c, memoryAGet16(0x0a78 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a78c
        memoryASet16(0x0a79 + seg, 0x0004, memoryAGet16(0x0a79 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a794
        memoryASet16(0x0a79 + seg, 0x000c, memoryAGet16(0x0a79 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a79c
        memoryASet16(0x0a7a + seg, 0x0004, memoryAGet16(0x0a7a + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7a4
        memoryASet16(0x0a7a + seg, 0x000c, memoryAGet16(0x0a7a + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7ac
        memoryASet16(0x0a7b + seg, 0x0004, memoryAGet16(0x0a7b + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7b4
        memoryASet16(0x0a7b + seg, 0x000c, memoryAGet16(0x0a7b + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7bc
        memoryASet16(0x0a7c + seg, 0x0004, memoryAGet16(0x0a7c + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7c4
        memoryASet16(0x0a7c + seg, 0x000c, memoryAGet16(0x0a7c + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7cc
        memoryASet16(0x0a7d + seg, 0x0004, memoryAGet16(0x0a7d + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7d4
        memoryASet16(0x0a7d + seg, 0x000c, memoryAGet16(0x0a7d + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7dc
        memoryASet16(0x0a7e + seg, 0x0004, memoryAGet16(0x0a7e + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7e4
        memoryASet16(0x0a7e + seg, 0x000c, memoryAGet16(0x0a7e + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7ec
        memoryASet16(0x0a7f + seg, 0x0004, memoryAGet16(0x0a7f + seg, 0x0004) + seg); // 3170 -> 335d; lin=a7f4
        memoryASet16(0x0a7f + seg, 0x000c, memoryAGet16(0x0a7f + seg, 0x000c) + seg); // 3170 -> 335d; lin=a7fc
        memoryASet16(0x0a80 + seg, 0x0004, memoryAGet16(0x0a80 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a804
        memoryASet16(0x0a80 + seg, 0x000c, memoryAGet16(0x0a80 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a80c
        memoryASet16(0x0a81 + seg, 0x0004, memoryAGet16(0x0a81 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a814
        memoryASet16(0x0a81 + seg, 0x000c, memoryAGet16(0x0a81 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a81c
        memoryASet16(0x0a82 + seg, 0x0004, memoryAGet16(0x0a82 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a824
        memoryASet16(0x0a82 + seg, 0x000c, memoryAGet16(0x0a82 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a82c
        memoryASet16(0x0a83 + seg, 0x0004, memoryAGet16(0x0a83 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a834
        memoryASet16(0x0a83 + seg, 0x000c, memoryAGet16(0x0a83 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a83c
        memoryASet16(0x0a84 + seg, 0x0004, memoryAGet16(0x0a84 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a844
        memoryASet16(0x0a84 + seg, 0x000c, memoryAGet16(0x0a84 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a84c
        memoryASet16(0x0a85 + seg, 0x0004, memoryAGet16(0x0a85 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a854
        memoryASet16(0x0a85 + seg, 0x000c, memoryAGet16(0x0a85 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a85c
        memoryASet16(0x0a86 + seg, 0x0004, memoryAGet16(0x0a86 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a864
        memoryASet16(0x0a86 + seg, 0x000c, memoryAGet16(0x0a86 + seg, 0x000c) + seg); // 3170 -> 335d; lin=a86c
        memoryASet16(0x0a87 + seg, 0x0004, memoryAGet16(0x0a87 + seg, 0x0004) + seg); // 3170 -> 335d; lin=a874
        memoryASet16(0x0a87 + seg, 0x000c, memoryAGet16(0x0a87 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a87c
        memoryASet16(0x0a88 + seg, 0x0004, memoryAGet16(0x0a88 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a884
        memoryASet16(0x0a88 + seg, 0x000c, memoryAGet16(0x0a88 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a88c
        memoryASet16(0x0a89 + seg, 0x0004, memoryAGet16(0x0a89 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a894
        memoryASet16(0x0a89 + seg, 0x000c, memoryAGet16(0x0a89 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a89c
        memoryASet16(0x0a8a + seg, 0x0004, memoryAGet16(0x0a8a + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8a4
        memoryASet16(0x0a8a + seg, 0x000c, memoryAGet16(0x0a8a + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8ac
        memoryASet16(0x0a8b + seg, 0x0004, memoryAGet16(0x0a8b + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8b4
        memoryASet16(0x0a8b + seg, 0x000c, memoryAGet16(0x0a8b + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8bc
        memoryASet16(0x0a8c + seg, 0x0004, memoryAGet16(0x0a8c + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8c4
        memoryASet16(0x0a8c + seg, 0x000c, memoryAGet16(0x0a8c + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8cc
        memoryASet16(0x0a8d + seg, 0x0004, memoryAGet16(0x0a8d + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8d4
        memoryASet16(0x0a8d + seg, 0x000c, memoryAGet16(0x0a8d + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8dc
        memoryASet16(0x0a8e + seg, 0x0004, memoryAGet16(0x0a8e + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8e4
        memoryASet16(0x0a8e + seg, 0x000c, memoryAGet16(0x0a8e + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8ec
        memoryASet16(0x0a8f + seg, 0x0004, memoryAGet16(0x0a8f + seg, 0x0004) + seg); // 1463 -> 1650; lin=a8f4
        memoryASet16(0x0a8f + seg, 0x000c, memoryAGet16(0x0a8f + seg, 0x000c) + seg); // 1463 -> 1650; lin=a8fc
        memoryASet16(0x0a90 + seg, 0x0004, memoryAGet16(0x0a90 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a904
        memoryASet16(0x0a90 + seg, 0x000c, memoryAGet16(0x0a90 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a90c
        memoryASet16(0x0a91 + seg, 0x0004, memoryAGet16(0x0a91 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a914
        memoryASet16(0x0a91 + seg, 0x000c, memoryAGet16(0x0a91 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a91c
        memoryASet16(0x0a92 + seg, 0x0004, memoryAGet16(0x0a92 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a924
        memoryASet16(0x0a92 + seg, 0x000c, memoryAGet16(0x0a92 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a92c
        memoryASet16(0x0a93 + seg, 0x0004, memoryAGet16(0x0a93 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a934
        memoryASet16(0x0a93 + seg, 0x000c, memoryAGet16(0x0a93 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a93c
        memoryASet16(0x0a94 + seg, 0x0004, memoryAGet16(0x0a94 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a944
        memoryASet16(0x0a94 + seg, 0x000c, memoryAGet16(0x0a94 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a94c
        memoryASet16(0x0a95 + seg, 0x0004, memoryAGet16(0x0a95 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a954
        memoryASet16(0x0a95 + seg, 0x000c, memoryAGet16(0x0a95 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a95c
        memoryASet16(0x0a96 + seg, 0x0004, memoryAGet16(0x0a96 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a964
        memoryASet16(0x0a96 + seg, 0x000c, memoryAGet16(0x0a96 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a96c
        memoryASet16(0x0a97 + seg, 0x0004, memoryAGet16(0x0a97 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a974
        memoryASet16(0x0a97 + seg, 0x000c, memoryAGet16(0x0a97 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a97c
        memoryASet16(0x0a98 + seg, 0x0004, memoryAGet16(0x0a98 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a984
        memoryASet16(0x0a98 + seg, 0x000c, memoryAGet16(0x0a98 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a98c
        memoryASet16(0x0a99 + seg, 0x0004, memoryAGet16(0x0a99 + seg, 0x0004) + seg); // 1463 -> 1650; lin=a994
        memoryASet16(0x0a99 + seg, 0x000c, memoryAGet16(0x0a99 + seg, 0x000c) + seg); // 1463 -> 1650; lin=a99c
        memoryASet16(0x0a9a + seg, 0x0004, memoryAGet16(0x0a9a + seg, 0x0004) + seg); // 1463 -> 1650; lin=a9a4
        memoryASet16(0x0a9a + seg, 0x000c, memoryAGet16(0x0a9a + seg, 0x000c) + seg); // 1463 -> 1650; lin=a9ac
        memoryASet16(0x0a9b + seg, 0x0004, memoryAGet16(0x0a9b + seg, 0x0004) + seg); // 1463 -> 1650; lin=a9b4
        memoryASet16(0x0a9b + seg, 0x000c, memoryAGet16(0x0a9b + seg, 0x000c) + seg); // 4110 -> 42fd; lin=a9bc
        memoryASet16(0x0a9c + seg, 0x0004, memoryAGet16(0x0a9c + seg, 0x0004) + seg); // 4110 -> 42fd; lin=a9c4
        memoryASet16(0x0a9c + seg, 0x000c, memoryAGet16(0x0a9c + seg, 0x000c) + seg); // 4110 -> 42fd; lin=a9cc
        memoryASet16(0x0a9d + seg, 0x0004, memoryAGet16(0x0a9d + seg, 0x0004) + seg); // 4110 -> 42fd; lin=a9d4
        memoryASet16(0x0a9d + seg, 0x000c, memoryAGet16(0x0a9d + seg, 0x000c) + seg); // 4110 -> 42fd; lin=a9dc
        memoryASet16(0x0a9e + seg, 0x0004, memoryAGet16(0x0a9e + seg, 0x0004) + seg); // 4110 -> 42fd; lin=a9e4
        memoryASet16(0x0a9e + seg, 0x000c, memoryAGet16(0x0a9e + seg, 0x000c) + seg); // 4110 -> 42fd; lin=a9ec
        memoryASet16(0x0a9f + seg, 0x0004, memoryAGet16(0x0a9f + seg, 0x0004) + seg); // 4110 -> 42fd; lin=a9f4
        memoryASet16(0x0a9f + seg, 0x000c, memoryAGet16(0x0a9f + seg, 0x000c) + seg); // 4110 -> 42fd; lin=a9fc
        memoryASet16(0x0aa0 + seg, 0x0004, memoryAGet16(0x0aa0 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa04
        memoryASet16(0x0aa0 + seg, 0x000c, memoryAGet16(0x0aa0 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa0c
        memoryASet16(0x0aa1 + seg, 0x0004, memoryAGet16(0x0aa1 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa14
        memoryASet16(0x0aa1 + seg, 0x000c, memoryAGet16(0x0aa1 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa1c
        memoryASet16(0x0aa2 + seg, 0x0004, memoryAGet16(0x0aa2 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa24
        memoryASet16(0x0aa2 + seg, 0x000c, memoryAGet16(0x0aa2 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa2c
        memoryASet16(0x0aa3 + seg, 0x0004, memoryAGet16(0x0aa3 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa34
        memoryASet16(0x0aa3 + seg, 0x000c, memoryAGet16(0x0aa3 + seg, 0x000c) + seg); // 1463 -> 1650; lin=aa3c
        memoryASet16(0x0aa4 + seg, 0x0004, memoryAGet16(0x0aa4 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa44
        memoryASet16(0x0aa4 + seg, 0x000c, memoryAGet16(0x0aa4 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa4c
        memoryASet16(0x0aa5 + seg, 0x0004, memoryAGet16(0x0aa5 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa54
        memoryASet16(0x0aa5 + seg, 0x000c, memoryAGet16(0x0aa5 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa5c
        memoryASet16(0x0aa6 + seg, 0x0004, memoryAGet16(0x0aa6 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa64
        memoryASet16(0x0aa6 + seg, 0x000c, memoryAGet16(0x0aa6 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa6c
        memoryASet16(0x0aa7 + seg, 0x0004, memoryAGet16(0x0aa7 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa74
        memoryASet16(0x0aa7 + seg, 0x000c, memoryAGet16(0x0aa7 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa7c
        memoryASet16(0x0aa8 + seg, 0x0004, memoryAGet16(0x0aa8 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa84
        memoryASet16(0x0aa8 + seg, 0x000c, memoryAGet16(0x0aa8 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa8c
        memoryASet16(0x0aa9 + seg, 0x0004, memoryAGet16(0x0aa9 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aa94
        memoryASet16(0x0aa9 + seg, 0x000c, memoryAGet16(0x0aa9 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aa9c
        memoryASet16(0x0aaa + seg, 0x0004, memoryAGet16(0x0aaa + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aaa4
        memoryASet16(0x0aaa + seg, 0x000c, memoryAGet16(0x0aaa + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aaac
        memoryASet16(0x0aab + seg, 0x0004, memoryAGet16(0x0aab + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aab4
        memoryASet16(0x0aab + seg, 0x000c, memoryAGet16(0x0aab + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aabc
        memoryASet16(0x0aac + seg, 0x0004, memoryAGet16(0x0aac + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aac4
        memoryASet16(0x0aac + seg, 0x000c, memoryAGet16(0x0aac + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aacc
        memoryASet16(0x0aad + seg, 0x0004, memoryAGet16(0x0aad + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aad4
        memoryASet16(0x0aad + seg, 0x000c, memoryAGet16(0x0aad + seg, 0x000c) + seg); // 4110 -> 42fd; lin=aadc
        memoryASet16(0x0aae + seg, 0x0004, memoryAGet16(0x0aae + seg, 0x0004) + seg); // 4110 -> 42fd; lin=aae4
        memoryASet16(0x0aae + seg, 0x000c, memoryAGet16(0x0aae + seg, 0x000c) + seg); // 1463 -> 1650; lin=aaec
        memoryASet16(0x0aaf + seg, 0x0004, memoryAGet16(0x0aaf + seg, 0x0004) + seg); // 1463 -> 1650; lin=aaf4
        memoryASet16(0x0aaf + seg, 0x000c, memoryAGet16(0x0aaf + seg, 0x000c) + seg); // 1463 -> 1650; lin=aafc
        memoryASet16(0x0ab0 + seg, 0x0004, memoryAGet16(0x0ab0 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab04
        memoryASet16(0x0ab0 + seg, 0x000c, memoryAGet16(0x0ab0 + seg, 0x000c) + seg); // 1463 -> 1650; lin=ab0c
        memoryASet16(0x0ab1 + seg, 0x0004, memoryAGet16(0x0ab1 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab14
        memoryASet16(0x0ab1 + seg, 0x000c, memoryAGet16(0x0ab1 + seg, 0x000c) + seg); // 1463 -> 1650; lin=ab1c
        memoryASet16(0x0ab2 + seg, 0x0004, memoryAGet16(0x0ab2 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab24
        memoryASet16(0x0ab2 + seg, 0x000c, memoryAGet16(0x0ab2 + seg, 0x000c) + seg); // 1463 -> 1650; lin=ab2c
        memoryASet16(0x0ab3 + seg, 0x0004, memoryAGet16(0x0ab3 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab34
        memoryASet16(0x0ab3 + seg, 0x000c, memoryAGet16(0x0ab3 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=ab3c
        memoryASet16(0x0ab4 + seg, 0x0004, memoryAGet16(0x0ab4 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=ab44
        memoryASet16(0x0ab4 + seg, 0x000c, memoryAGet16(0x0ab4 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=ab4c
        memoryASet16(0x0ab5 + seg, 0x0004, memoryAGet16(0x0ab5 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab54
        memoryASet16(0x0ab5 + seg, 0x000c, memoryAGet16(0x0ab5 + seg, 0x000c) + seg); // 1463 -> 1650; lin=ab5c
        memoryASet16(0x0ab6 + seg, 0x0004, memoryAGet16(0x0ab6 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ab64
        memoryASet16(0x0ab6 + seg, 0x000c, memoryAGet16(0x0ab6 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ab6c
        memoryASet16(0x0ab7 + seg, 0x0004, memoryAGet16(0x0ab7 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ab74
        memoryASet16(0x0ab7 + seg, 0x000c, memoryAGet16(0x0ab7 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=ab7c
        memoryASet16(0x0ae5 + seg, 0x000e, memoryAGet16(0x0ae5 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=ae5e
        memoryASet16(0x0ae6 + seg, 0x0006, memoryAGet16(0x0ae6 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=ae66
        memoryASet16(0x0ae6 + seg, 0x000a, memoryAGet16(0x0ae6 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=ae6a
        memoryASet16(0x0ae6 + seg, 0x000e, memoryAGet16(0x0ae6 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=ae6e
        memoryASet16(0x0ae7 + seg, 0x0006, memoryAGet16(0x0ae7 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=ae76
        memoryASet16(0x0ae7 + seg, 0x000a, memoryAGet16(0x0ae7 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=ae7a
        memoryASet16(0x0ae7 + seg, 0x000e, memoryAGet16(0x0ae7 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=ae7e
        memoryASet16(0x0ae8 + seg, 0x0006, memoryAGet16(0x0ae8 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=ae86
        memoryASet16(0x0ae8 + seg, 0x000a, memoryAGet16(0x0ae8 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=ae8a
        memoryASet16(0x0ae8 + seg, 0x000e, memoryAGet16(0x0ae8 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=ae8e
        memoryASet16(0x0ae9 + seg, 0x0006, memoryAGet16(0x0ae9 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=ae96
        memoryASet16(0x0ae9 + seg, 0x000a, memoryAGet16(0x0ae9 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=ae9a
        memoryASet16(0x0ae9 + seg, 0x000e, memoryAGet16(0x0ae9 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=ae9e
        memoryASet16(0x0aea + seg, 0x0006, memoryAGet16(0x0aea + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aea6
        memoryASet16(0x0aea + seg, 0x000a, memoryAGet16(0x0aea + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aeaa
        memoryASet16(0x0aea + seg, 0x000e, memoryAGet16(0x0aea + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aeae
        memoryASet16(0x0aeb + seg, 0x0006, memoryAGet16(0x0aeb + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aeb6
        memoryASet16(0x0aeb + seg, 0x000a, memoryAGet16(0x0aeb + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aeba
        memoryASet16(0x0aeb + seg, 0x000e, memoryAGet16(0x0aeb + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aebe
        memoryASet16(0x0aec + seg, 0x0006, memoryAGet16(0x0aec + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aec6
        memoryASet16(0x0aec + seg, 0x000a, memoryAGet16(0x0aec + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aeca
        memoryASet16(0x0aec + seg, 0x000e, memoryAGet16(0x0aec + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aece
        memoryASet16(0x0aed + seg, 0x0006, memoryAGet16(0x0aed + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aed6
        memoryASet16(0x0aed + seg, 0x000a, memoryAGet16(0x0aed + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aeda
        memoryASet16(0x0aed + seg, 0x000e, memoryAGet16(0x0aed + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aede
        memoryASet16(0x0aee + seg, 0x0006, memoryAGet16(0x0aee + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aee6
        memoryASet16(0x0aee + seg, 0x000a, memoryAGet16(0x0aee + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aeea
        memoryASet16(0x0aee + seg, 0x000e, memoryAGet16(0x0aee + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aeee
        memoryASet16(0x0aef + seg, 0x0006, memoryAGet16(0x0aef + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aef6
        memoryASet16(0x0aef + seg, 0x000a, memoryAGet16(0x0aef + seg, 0x000a) + seg); // 2403 -> 25f0; lin=aefa
        memoryASet16(0x0aef + seg, 0x000e, memoryAGet16(0x0aef + seg, 0x000e) + seg); // 4110 -> 42fd; lin=aefe
        memoryASet16(0x0af0 + seg, 0x0006, memoryAGet16(0x0af0 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af06
        memoryASet16(0x0af0 + seg, 0x000a, memoryAGet16(0x0af0 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af0a
        memoryASet16(0x0af0 + seg, 0x000e, memoryAGet16(0x0af0 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af0e
        memoryASet16(0x0af1 + seg, 0x0006, memoryAGet16(0x0af1 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af16
        memoryASet16(0x0af1 + seg, 0x000a, memoryAGet16(0x0af1 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af1a
        memoryASet16(0x0af1 + seg, 0x000e, memoryAGet16(0x0af1 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af1e
        memoryASet16(0x0af2 + seg, 0x0006, memoryAGet16(0x0af2 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af26
        memoryASet16(0x0af2 + seg, 0x000a, memoryAGet16(0x0af2 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af2a
        memoryASet16(0x0af2 + seg, 0x000e, memoryAGet16(0x0af2 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af2e
        memoryASet16(0x0af3 + seg, 0x0006, memoryAGet16(0x0af3 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af36
        memoryASet16(0x0af3 + seg, 0x000a, memoryAGet16(0x0af3 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af3a
        memoryASet16(0x0af3 + seg, 0x000e, memoryAGet16(0x0af3 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af3e
        memoryASet16(0x0af4 + seg, 0x0006, memoryAGet16(0x0af4 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af46
        memoryASet16(0x0af4 + seg, 0x000a, memoryAGet16(0x0af4 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af4a
        memoryASet16(0x0af4 + seg, 0x000e, memoryAGet16(0x0af4 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af4e
        memoryASet16(0x0af5 + seg, 0x0006, memoryAGet16(0x0af5 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af56
        memoryASet16(0x0af5 + seg, 0x000a, memoryAGet16(0x0af5 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af5a
        memoryASet16(0x0af5 + seg, 0x000e, memoryAGet16(0x0af5 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af5e
        memoryASet16(0x0af6 + seg, 0x0006, memoryAGet16(0x0af6 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af66
        memoryASet16(0x0af6 + seg, 0x000a, memoryAGet16(0x0af6 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af6a
        memoryASet16(0x0af6 + seg, 0x000e, memoryAGet16(0x0af6 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af6e
        memoryASet16(0x0af7 + seg, 0x0006, memoryAGet16(0x0af7 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af76
        memoryASet16(0x0af7 + seg, 0x000a, memoryAGet16(0x0af7 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af7a
        memoryASet16(0x0af7 + seg, 0x000e, memoryAGet16(0x0af7 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af7e
        memoryASet16(0x0af8 + seg, 0x0006, memoryAGet16(0x0af8 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af86
        memoryASet16(0x0af8 + seg, 0x000a, memoryAGet16(0x0af8 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af8a
        memoryASet16(0x0af8 + seg, 0x000e, memoryAGet16(0x0af8 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af8e
        memoryASet16(0x0af9 + seg, 0x0006, memoryAGet16(0x0af9 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=af96
        memoryASet16(0x0af9 + seg, 0x000a, memoryAGet16(0x0af9 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=af9a
        memoryASet16(0x0af9 + seg, 0x000e, memoryAGet16(0x0af9 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=af9e
        memoryASet16(0x0afa + seg, 0x0006, memoryAGet16(0x0afa + seg, 0x0006) + seg); // 2403 -> 25f0; lin=afa6
        memoryASet16(0x0afa + seg, 0x000a, memoryAGet16(0x0afa + seg, 0x000a) + seg); // 2403 -> 25f0; lin=afaa
        memoryASet16(0x0afa + seg, 0x000e, memoryAGet16(0x0afa + seg, 0x000e) + seg); // 4110 -> 42fd; lin=afae
        memoryASet16(0x0afb + seg, 0x0006, memoryAGet16(0x0afb + seg, 0x0006) + seg); // 2403 -> 25f0; lin=afb6
        memoryASet16(0x0afb + seg, 0x000a, memoryAGet16(0x0afb + seg, 0x000a) + seg); // 2403 -> 25f0; lin=afba
        memoryASet16(0x0afb + seg, 0x000e, memoryAGet16(0x0afb + seg, 0x000e) + seg); // 4110 -> 42fd; lin=afbe
        memoryASet16(0x0afc + seg, 0x0006, memoryAGet16(0x0afc + seg, 0x0006) + seg); // 2403 -> 25f0; lin=afc6
        memoryASet16(0x0afc + seg, 0x000a, memoryAGet16(0x0afc + seg, 0x000a) + seg); // 2403 -> 25f0; lin=afca
        memoryASet16(0x0afc + seg, 0x000e, memoryAGet16(0x0afc + seg, 0x000e) + seg); // 4110 -> 42fd; lin=afce
        memoryASet16(0x0afd + seg, 0x0006, memoryAGet16(0x0afd + seg, 0x0006) + seg); // 2403 -> 25f0; lin=afd6
        memoryASet16(0x0afd + seg, 0x000a, memoryAGet16(0x0afd + seg, 0x000a) + seg); // 2403 -> 25f0; lin=afda
        memoryASet16(0x0afd + seg, 0x000e, memoryAGet16(0x0afd + seg, 0x000e) + seg); // 4110 -> 42fd; lin=afde
        memoryASet16(0x0afe + seg, 0x0006, memoryAGet16(0x0afe + seg, 0x0006) + seg); // 2403 -> 25f0; lin=afe6
        memoryASet16(0x0afe + seg, 0x000a, memoryAGet16(0x0afe + seg, 0x000a) + seg); // 2403 -> 25f0; lin=afea
        memoryASet16(0x0afe + seg, 0x000e, memoryAGet16(0x0afe + seg, 0x000e) + seg); // 4110 -> 42fd; lin=afee
        memoryASet16(0x0aff + seg, 0x0006, memoryAGet16(0x0aff + seg, 0x0006) + seg); // 2403 -> 25f0; lin=aff6
        memoryASet16(0x0aff + seg, 0x000a, memoryAGet16(0x0aff + seg, 0x000a) + seg); // 2403 -> 25f0; lin=affa
        memoryASet16(0x0aff + seg, 0x000e, memoryAGet16(0x0aff + seg, 0x000e) + seg); // 4110 -> 42fd; lin=affe
        memoryASet16(0x0b00 + seg, 0x0006, memoryAGet16(0x0b00 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b006
        memoryASet16(0x0b00 + seg, 0x000a, memoryAGet16(0x0b00 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b00a
        memoryASet16(0x0b00 + seg, 0x000e, memoryAGet16(0x0b00 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b00e
        memoryASet16(0x0b01 + seg, 0x0006, memoryAGet16(0x0b01 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b016
        memoryASet16(0x0b01 + seg, 0x000a, memoryAGet16(0x0b01 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b01a
        memoryASet16(0x0b01 + seg, 0x000e, memoryAGet16(0x0b01 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b01e
        memoryASet16(0x0b02 + seg, 0x0006, memoryAGet16(0x0b02 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b026
        memoryASet16(0x0b02 + seg, 0x000a, memoryAGet16(0x0b02 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b02a
        memoryASet16(0x0b02 + seg, 0x000e, memoryAGet16(0x0b02 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b02e
        memoryASet16(0x0b03 + seg, 0x0006, memoryAGet16(0x0b03 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b036
        memoryASet16(0x0b03 + seg, 0x000a, memoryAGet16(0x0b03 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b03a
        memoryASet16(0x0b03 + seg, 0x000e, memoryAGet16(0x0b03 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b03e
        memoryASet16(0x0b04 + seg, 0x0006, memoryAGet16(0x0b04 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b046
        memoryASet16(0x0b04 + seg, 0x000a, memoryAGet16(0x0b04 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b04a
        memoryASet16(0x0b04 + seg, 0x000e, memoryAGet16(0x0b04 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b04e
        memoryASet16(0x0b05 + seg, 0x0006, memoryAGet16(0x0b05 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b056
        memoryASet16(0x0b05 + seg, 0x000a, memoryAGet16(0x0b05 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b05a
        memoryASet16(0x0b05 + seg, 0x000e, memoryAGet16(0x0b05 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b05e
        memoryASet16(0x0b06 + seg, 0x0006, memoryAGet16(0x0b06 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b066
        memoryASet16(0x0b06 + seg, 0x000a, memoryAGet16(0x0b06 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b06a
        memoryASet16(0x0b06 + seg, 0x000e, memoryAGet16(0x0b06 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b06e
        memoryASet16(0x0b07 + seg, 0x0006, memoryAGet16(0x0b07 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b076
        memoryASet16(0x0b07 + seg, 0x000a, memoryAGet16(0x0b07 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b07a
        memoryASet16(0x0b07 + seg, 0x000e, memoryAGet16(0x0b07 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b07e
        memoryASet16(0x0b08 + seg, 0x0006, memoryAGet16(0x0b08 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b086
        memoryASet16(0x0b08 + seg, 0x000a, memoryAGet16(0x0b08 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b08a
        memoryASet16(0x0b08 + seg, 0x000e, memoryAGet16(0x0b08 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b08e
        memoryASet16(0x0b09 + seg, 0x0006, memoryAGet16(0x0b09 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b096
        memoryASet16(0x0b09 + seg, 0x000a, memoryAGet16(0x0b09 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b09a
        memoryASet16(0x0b09 + seg, 0x000e, memoryAGet16(0x0b09 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b09e
        memoryASet16(0x0b0a + seg, 0x0006, memoryAGet16(0x0b0a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0a6
        memoryASet16(0x0b0a + seg, 0x000a, memoryAGet16(0x0b0a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0aa
        memoryASet16(0x0b0a + seg, 0x000e, memoryAGet16(0x0b0a + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0ae
        memoryASet16(0x0b0b + seg, 0x0006, memoryAGet16(0x0b0b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0b6
        memoryASet16(0x0b0b + seg, 0x000a, memoryAGet16(0x0b0b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0ba
        memoryASet16(0x0b0b + seg, 0x000e, memoryAGet16(0x0b0b + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0be
        memoryASet16(0x0b0c + seg, 0x0006, memoryAGet16(0x0b0c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0c6
        memoryASet16(0x0b0c + seg, 0x000a, memoryAGet16(0x0b0c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0ca
        memoryASet16(0x0b0c + seg, 0x000e, memoryAGet16(0x0b0c + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0ce
        memoryASet16(0x0b0d + seg, 0x0006, memoryAGet16(0x0b0d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0d6
        memoryASet16(0x0b0d + seg, 0x000a, memoryAGet16(0x0b0d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0da
        memoryASet16(0x0b0d + seg, 0x000e, memoryAGet16(0x0b0d + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0de
        memoryASet16(0x0b0e + seg, 0x0006, memoryAGet16(0x0b0e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0e6
        memoryASet16(0x0b0e + seg, 0x000a, memoryAGet16(0x0b0e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0ea
        memoryASet16(0x0b0e + seg, 0x000e, memoryAGet16(0x0b0e + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0ee
        memoryASet16(0x0b0f + seg, 0x0006, memoryAGet16(0x0b0f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b0f6
        memoryASet16(0x0b0f + seg, 0x000a, memoryAGet16(0x0b0f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b0fa
        memoryASet16(0x0b0f + seg, 0x000e, memoryAGet16(0x0b0f + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b0fe
        memoryASet16(0x0b10 + seg, 0x0006, memoryAGet16(0x0b10 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b106
        memoryASet16(0x0b10 + seg, 0x000a, memoryAGet16(0x0b10 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b10a
        memoryASet16(0x0b10 + seg, 0x000e, memoryAGet16(0x0b10 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b10e
        memoryASet16(0x0b11 + seg, 0x0006, memoryAGet16(0x0b11 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b116
        memoryASet16(0x0b11 + seg, 0x000a, memoryAGet16(0x0b11 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b11a
        memoryASet16(0x0b11 + seg, 0x000e, memoryAGet16(0x0b11 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b11e
        memoryASet16(0x0b12 + seg, 0x0006, memoryAGet16(0x0b12 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b126
        memoryASet16(0x0b12 + seg, 0x000a, memoryAGet16(0x0b12 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b12a
        memoryASet16(0x0b12 + seg, 0x000e, memoryAGet16(0x0b12 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b12e
        memoryASet16(0x0b13 + seg, 0x0006, memoryAGet16(0x0b13 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b136
        memoryASet16(0x0b13 + seg, 0x000a, memoryAGet16(0x0b13 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b13a
        memoryASet16(0x0b13 + seg, 0x000e, memoryAGet16(0x0b13 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b13e
        memoryASet16(0x0b14 + seg, 0x0006, memoryAGet16(0x0b14 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b146
        memoryASet16(0x0b14 + seg, 0x000a, memoryAGet16(0x0b14 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b14a
        memoryASet16(0x0b14 + seg, 0x000e, memoryAGet16(0x0b14 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b14e
        memoryASet16(0x0b15 + seg, 0x0006, memoryAGet16(0x0b15 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b156
        memoryASet16(0x0b15 + seg, 0x000a, memoryAGet16(0x0b15 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b15a
        memoryASet16(0x0b15 + seg, 0x000e, memoryAGet16(0x0b15 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b15e
        memoryASet16(0x0b16 + seg, 0x0006, memoryAGet16(0x0b16 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b166
        memoryASet16(0x0b16 + seg, 0x000a, memoryAGet16(0x0b16 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b16a
        memoryASet16(0x0b16 + seg, 0x000e, memoryAGet16(0x0b16 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b16e
        memoryASet16(0x0b17 + seg, 0x0006, memoryAGet16(0x0b17 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b176
        memoryASet16(0x0b17 + seg, 0x000a, memoryAGet16(0x0b17 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b17a
        memoryASet16(0x0b17 + seg, 0x000e, memoryAGet16(0x0b17 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b17e
        memoryASet16(0x0b18 + seg, 0x0006, memoryAGet16(0x0b18 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b186
        memoryASet16(0x0b18 + seg, 0x000a, memoryAGet16(0x0b18 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b18a
        memoryASet16(0x0b18 + seg, 0x000e, memoryAGet16(0x0b18 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b18e
        memoryASet16(0x0b19 + seg, 0x0006, memoryAGet16(0x0b19 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b196
        memoryASet16(0x0b19 + seg, 0x000a, memoryAGet16(0x0b19 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b19a
        memoryASet16(0x0b19 + seg, 0x000e, memoryAGet16(0x0b19 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b19e
        memoryASet16(0x0b1a + seg, 0x0006, memoryAGet16(0x0b1a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1a6
        memoryASet16(0x0b1a + seg, 0x000a, memoryAGet16(0x0b1a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1aa
        memoryASet16(0x0b1a + seg, 0x000e, memoryAGet16(0x0b1a + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1ae
        memoryASet16(0x0b1b + seg, 0x0006, memoryAGet16(0x0b1b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1b6
        memoryASet16(0x0b1b + seg, 0x000a, memoryAGet16(0x0b1b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1ba
        memoryASet16(0x0b1b + seg, 0x000e, memoryAGet16(0x0b1b + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1be
        memoryASet16(0x0b1c + seg, 0x0006, memoryAGet16(0x0b1c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1c6
        memoryASet16(0x0b1c + seg, 0x000a, memoryAGet16(0x0b1c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1ca
        memoryASet16(0x0b1c + seg, 0x000e, memoryAGet16(0x0b1c + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1ce
        memoryASet16(0x0b1d + seg, 0x0006, memoryAGet16(0x0b1d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1d6
        memoryASet16(0x0b1d + seg, 0x000a, memoryAGet16(0x0b1d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1da
        memoryASet16(0x0b1d + seg, 0x000e, memoryAGet16(0x0b1d + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1de
        memoryASet16(0x0b1e + seg, 0x0006, memoryAGet16(0x0b1e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1e6
        memoryASet16(0x0b1e + seg, 0x000a, memoryAGet16(0x0b1e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1ea
        memoryASet16(0x0b1e + seg, 0x000e, memoryAGet16(0x0b1e + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1ee
        memoryASet16(0x0b1f + seg, 0x0006, memoryAGet16(0x0b1f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b1f6
        memoryASet16(0x0b1f + seg, 0x000a, memoryAGet16(0x0b1f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b1fa
        memoryASet16(0x0b1f + seg, 0x000e, memoryAGet16(0x0b1f + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b1fe
        memoryASet16(0x0b20 + seg, 0x0006, memoryAGet16(0x0b20 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b206
        memoryASet16(0x0b20 + seg, 0x000a, memoryAGet16(0x0b20 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b20a
        memoryASet16(0x0b20 + seg, 0x000e, memoryAGet16(0x0b20 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b20e
        memoryASet16(0x0b21 + seg, 0x0006, memoryAGet16(0x0b21 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b216
        memoryASet16(0x0b21 + seg, 0x000a, memoryAGet16(0x0b21 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b21a
        memoryASet16(0x0b21 + seg, 0x000e, memoryAGet16(0x0b21 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b21e
        memoryASet16(0x0b22 + seg, 0x0006, memoryAGet16(0x0b22 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b226
        memoryASet16(0x0b22 + seg, 0x000a, memoryAGet16(0x0b22 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b22a
        memoryASet16(0x0b22 + seg, 0x000e, memoryAGet16(0x0b22 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b22e
        memoryASet16(0x0b23 + seg, 0x0006, memoryAGet16(0x0b23 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b236
        memoryASet16(0x0b23 + seg, 0x000a, memoryAGet16(0x0b23 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b23a
        memoryASet16(0x0b23 + seg, 0x000e, memoryAGet16(0x0b23 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b23e
        memoryASet16(0x0b24 + seg, 0x0006, memoryAGet16(0x0b24 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b246
        memoryASet16(0x0b24 + seg, 0x000a, memoryAGet16(0x0b24 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b24a
        memoryASet16(0x0b24 + seg, 0x000e, memoryAGet16(0x0b24 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b24e
        memoryASet16(0x0b25 + seg, 0x0006, memoryAGet16(0x0b25 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b256
        memoryASet16(0x0b25 + seg, 0x000a, memoryAGet16(0x0b25 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b25a
        memoryASet16(0x0b25 + seg, 0x000e, memoryAGet16(0x0b25 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b25e
        memoryASet16(0x0b26 + seg, 0x0006, memoryAGet16(0x0b26 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b266
        memoryASet16(0x0b26 + seg, 0x000a, memoryAGet16(0x0b26 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b26a
        memoryASet16(0x0b26 + seg, 0x000e, memoryAGet16(0x0b26 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b26e
        memoryASet16(0x0b27 + seg, 0x0006, memoryAGet16(0x0b27 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b276
        memoryASet16(0x0b27 + seg, 0x000a, memoryAGet16(0x0b27 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b27a
        memoryASet16(0x0b27 + seg, 0x000e, memoryAGet16(0x0b27 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b27e
        memoryASet16(0x0b28 + seg, 0x0006, memoryAGet16(0x0b28 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b286
        memoryASet16(0x0b28 + seg, 0x000a, memoryAGet16(0x0b28 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b28a
        memoryASet16(0x0b28 + seg, 0x000e, memoryAGet16(0x0b28 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b28e
        memoryASet16(0x0b29 + seg, 0x0006, memoryAGet16(0x0b29 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b296
        memoryASet16(0x0b29 + seg, 0x000a, memoryAGet16(0x0b29 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b29a
        memoryASet16(0x0b29 + seg, 0x000e, memoryAGet16(0x0b29 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b29e
        memoryASet16(0x0b2a + seg, 0x0006, memoryAGet16(0x0b2a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2a6
        memoryASet16(0x0b2a + seg, 0x000a, memoryAGet16(0x0b2a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2aa
        memoryASet16(0x0b2a + seg, 0x000e, memoryAGet16(0x0b2a + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2ae
        memoryASet16(0x0b2b + seg, 0x0006, memoryAGet16(0x0b2b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2b6
        memoryASet16(0x0b2b + seg, 0x000a, memoryAGet16(0x0b2b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2ba
        memoryASet16(0x0b2b + seg, 0x000e, memoryAGet16(0x0b2b + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2be
        memoryASet16(0x0b2c + seg, 0x0006, memoryAGet16(0x0b2c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2c6
        memoryASet16(0x0b2c + seg, 0x000a, memoryAGet16(0x0b2c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2ca
        memoryASet16(0x0b2c + seg, 0x000e, memoryAGet16(0x0b2c + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2ce
        memoryASet16(0x0b2d + seg, 0x0006, memoryAGet16(0x0b2d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2d6
        memoryASet16(0x0b2d + seg, 0x000a, memoryAGet16(0x0b2d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2da
        memoryASet16(0x0b2d + seg, 0x000e, memoryAGet16(0x0b2d + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2de
        memoryASet16(0x0b2e + seg, 0x0006, memoryAGet16(0x0b2e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2e6
        memoryASet16(0x0b2e + seg, 0x000a, memoryAGet16(0x0b2e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2ea
        memoryASet16(0x0b2e + seg, 0x000e, memoryAGet16(0x0b2e + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2ee
        memoryASet16(0x0b2f + seg, 0x0006, memoryAGet16(0x0b2f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b2f6
        memoryASet16(0x0b2f + seg, 0x000a, memoryAGet16(0x0b2f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b2fa
        memoryASet16(0x0b2f + seg, 0x000e, memoryAGet16(0x0b2f + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b2fe
        memoryASet16(0x0b30 + seg, 0x0006, memoryAGet16(0x0b30 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b306
        memoryASet16(0x0b30 + seg, 0x000a, memoryAGet16(0x0b30 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b30a
        memoryASet16(0x0b30 + seg, 0x000e, memoryAGet16(0x0b30 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b30e
        memoryASet16(0x0b31 + seg, 0x0006, memoryAGet16(0x0b31 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b316
        memoryASet16(0x0b31 + seg, 0x000a, memoryAGet16(0x0b31 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b31a
        memoryASet16(0x0b31 + seg, 0x000e, memoryAGet16(0x0b31 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b31e
        memoryASet16(0x0b32 + seg, 0x0006, memoryAGet16(0x0b32 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b326
        memoryASet16(0x0b32 + seg, 0x000a, memoryAGet16(0x0b32 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b32a
        memoryASet16(0x0b32 + seg, 0x000e, memoryAGet16(0x0b32 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b32e
        memoryASet16(0x0b33 + seg, 0x0006, memoryAGet16(0x0b33 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b336
        memoryASet16(0x0b33 + seg, 0x000a, memoryAGet16(0x0b33 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b33a
        memoryASet16(0x0b33 + seg, 0x000e, memoryAGet16(0x0b33 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b33e
        memoryASet16(0x0b34 + seg, 0x0006, memoryAGet16(0x0b34 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b346
        memoryASet16(0x0b34 + seg, 0x000a, memoryAGet16(0x0b34 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b34a
        memoryASet16(0x0b34 + seg, 0x000e, memoryAGet16(0x0b34 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=b34e
        memoryASet16(0x0b35 + seg, 0x0006, memoryAGet16(0x0b35 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b356
        memoryASet16(0x0b35 + seg, 0x000a, memoryAGet16(0x0b35 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b35a
        memoryASet16(0x0b35 + seg, 0x000e, memoryAGet16(0x0b35 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b35e
        memoryASet16(0x0b36 + seg, 0x0006, memoryAGet16(0x0b36 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b366
        memoryASet16(0x0b36 + seg, 0x000a, memoryAGet16(0x0b36 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b36a
        memoryASet16(0x0b36 + seg, 0x000e, memoryAGet16(0x0b36 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b36e
        memoryASet16(0x0b37 + seg, 0x0006, memoryAGet16(0x0b37 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b376
        memoryASet16(0x0b37 + seg, 0x000a, memoryAGet16(0x0b37 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b37a
        memoryASet16(0x0b37 + seg, 0x000e, memoryAGet16(0x0b37 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b37e
        memoryASet16(0x0b38 + seg, 0x0006, memoryAGet16(0x0b38 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b386
        memoryASet16(0x0b38 + seg, 0x000a, memoryAGet16(0x0b38 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b38a
        memoryASet16(0x0b38 + seg, 0x000e, memoryAGet16(0x0b38 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b38e
        memoryASet16(0x0b39 + seg, 0x0006, memoryAGet16(0x0b39 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b396
        memoryASet16(0x0b39 + seg, 0x000a, memoryAGet16(0x0b39 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b39a
        memoryASet16(0x0b39 + seg, 0x000e, memoryAGet16(0x0b39 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b39e
        memoryASet16(0x0b3a + seg, 0x0006, memoryAGet16(0x0b3a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3a6
        memoryASet16(0x0b3a + seg, 0x000a, memoryAGet16(0x0b3a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3aa
        memoryASet16(0x0b3a + seg, 0x000e, memoryAGet16(0x0b3a + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3ae
        memoryASet16(0x0b3b + seg, 0x0006, memoryAGet16(0x0b3b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3b6
        memoryASet16(0x0b3b + seg, 0x000a, memoryAGet16(0x0b3b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3ba
        memoryASet16(0x0b3b + seg, 0x000e, memoryAGet16(0x0b3b + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3be
        memoryASet16(0x0b3c + seg, 0x0006, memoryAGet16(0x0b3c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3c6
        memoryASet16(0x0b3c + seg, 0x000a, memoryAGet16(0x0b3c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3ca
        memoryASet16(0x0b3c + seg, 0x000e, memoryAGet16(0x0b3c + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3ce
        memoryASet16(0x0b3d + seg, 0x0006, memoryAGet16(0x0b3d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3d6
        memoryASet16(0x0b3d + seg, 0x000a, memoryAGet16(0x0b3d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3da
        memoryASet16(0x0b3d + seg, 0x000e, memoryAGet16(0x0b3d + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3de
        memoryASet16(0x0b3e + seg, 0x0006, memoryAGet16(0x0b3e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3e6
        memoryASet16(0x0b3e + seg, 0x000a, memoryAGet16(0x0b3e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3ea
        memoryASet16(0x0b3e + seg, 0x000e, memoryAGet16(0x0b3e + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3ee
        memoryASet16(0x0b3f + seg, 0x0006, memoryAGet16(0x0b3f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b3f6
        memoryASet16(0x0b3f + seg, 0x000a, memoryAGet16(0x0b3f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b3fa
        memoryASet16(0x0b3f + seg, 0x000e, memoryAGet16(0x0b3f + seg, 0x000e) + seg); // 1463 -> 1650; lin=b3fe
        memoryASet16(0x0b40 + seg, 0x0006, memoryAGet16(0x0b40 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b406
        memoryASet16(0x0b40 + seg, 0x000a, memoryAGet16(0x0b40 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b40a
        memoryASet16(0x0b40 + seg, 0x000e, memoryAGet16(0x0b40 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b40e
        memoryASet16(0x0b41 + seg, 0x0006, memoryAGet16(0x0b41 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b416
        memoryASet16(0x0b41 + seg, 0x000a, memoryAGet16(0x0b41 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b41a
        memoryASet16(0x0b41 + seg, 0x000e, memoryAGet16(0x0b41 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b41e
        memoryASet16(0x0b42 + seg, 0x0006, memoryAGet16(0x0b42 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b426
        memoryASet16(0x0b42 + seg, 0x000a, memoryAGet16(0x0b42 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b42a
        memoryASet16(0x0b42 + seg, 0x000e, memoryAGet16(0x0b42 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b42e
        memoryASet16(0x0b43 + seg, 0x0006, memoryAGet16(0x0b43 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b436
        memoryASet16(0x0b43 + seg, 0x000a, memoryAGet16(0x0b43 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b43a
        memoryASet16(0x0b43 + seg, 0x000e, memoryAGet16(0x0b43 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b43e
        memoryASet16(0x0b44 + seg, 0x0006, memoryAGet16(0x0b44 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b446
        memoryASet16(0x0b44 + seg, 0x000a, memoryAGet16(0x0b44 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b44a
        memoryASet16(0x0b44 + seg, 0x000e, memoryAGet16(0x0b44 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b44e
        memoryASet16(0x0b45 + seg, 0x0006, memoryAGet16(0x0b45 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b456
        memoryASet16(0x0b45 + seg, 0x000a, memoryAGet16(0x0b45 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b45a
        memoryASet16(0x0b45 + seg, 0x000e, memoryAGet16(0x0b45 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b45e
        memoryASet16(0x0b46 + seg, 0x0006, memoryAGet16(0x0b46 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b466
        memoryASet16(0x0b46 + seg, 0x000a, memoryAGet16(0x0b46 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b46a
        memoryASet16(0x0b46 + seg, 0x000e, memoryAGet16(0x0b46 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b46e
        memoryASet16(0x0b47 + seg, 0x0006, memoryAGet16(0x0b47 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b476
        memoryASet16(0x0b47 + seg, 0x000a, memoryAGet16(0x0b47 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b47a
        memoryASet16(0x0b47 + seg, 0x000e, memoryAGet16(0x0b47 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b47e
        memoryASet16(0x0b48 + seg, 0x0006, memoryAGet16(0x0b48 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b486
        memoryASet16(0x0b48 + seg, 0x000a, memoryAGet16(0x0b48 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b48a
        memoryASet16(0x0b48 + seg, 0x000e, memoryAGet16(0x0b48 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b48e
        memoryASet16(0x0b49 + seg, 0x0006, memoryAGet16(0x0b49 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b496
        memoryASet16(0x0b49 + seg, 0x000a, memoryAGet16(0x0b49 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b49a
        memoryASet16(0x0b49 + seg, 0x000e, memoryAGet16(0x0b49 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b49e
        memoryASet16(0x0b4a + seg, 0x0006, memoryAGet16(0x0b4a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4a6
        memoryASet16(0x0b4a + seg, 0x000a, memoryAGet16(0x0b4a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4aa
        memoryASet16(0x0b4a + seg, 0x000e, memoryAGet16(0x0b4a + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4ae
        memoryASet16(0x0b4b + seg, 0x0006, memoryAGet16(0x0b4b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4b6
        memoryASet16(0x0b4b + seg, 0x000a, memoryAGet16(0x0b4b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4ba
        memoryASet16(0x0b4b + seg, 0x000e, memoryAGet16(0x0b4b + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4be
        memoryASet16(0x0b4c + seg, 0x0006, memoryAGet16(0x0b4c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4c6
        memoryASet16(0x0b4c + seg, 0x000a, memoryAGet16(0x0b4c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4ca
        memoryASet16(0x0b4c + seg, 0x000e, memoryAGet16(0x0b4c + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4ce
        memoryASet16(0x0b4d + seg, 0x0006, memoryAGet16(0x0b4d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4d6
        memoryASet16(0x0b4d + seg, 0x000a, memoryAGet16(0x0b4d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4da
        memoryASet16(0x0b4d + seg, 0x000e, memoryAGet16(0x0b4d + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4de
        memoryASet16(0x0b4e + seg, 0x0006, memoryAGet16(0x0b4e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4e6
        memoryASet16(0x0b4e + seg, 0x000a, memoryAGet16(0x0b4e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4ea
        memoryASet16(0x0b4e + seg, 0x000e, memoryAGet16(0x0b4e + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4ee
        memoryASet16(0x0b4f + seg, 0x0006, memoryAGet16(0x0b4f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b4f6
        memoryASet16(0x0b4f + seg, 0x000a, memoryAGet16(0x0b4f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b4fa
        memoryASet16(0x0b4f + seg, 0x000e, memoryAGet16(0x0b4f + seg, 0x000e) + seg); // 1463 -> 1650; lin=b4fe
        memoryASet16(0x0b50 + seg, 0x0006, memoryAGet16(0x0b50 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b506
        memoryASet16(0x0b50 + seg, 0x000a, memoryAGet16(0x0b50 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b50a
        memoryASet16(0x0b50 + seg, 0x000e, memoryAGet16(0x0b50 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b50e
        memoryASet16(0x0b51 + seg, 0x0006, memoryAGet16(0x0b51 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b516
        memoryASet16(0x0b51 + seg, 0x000a, memoryAGet16(0x0b51 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b51a
        memoryASet16(0x0b51 + seg, 0x000e, memoryAGet16(0x0b51 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b51e
        memoryASet16(0x0b52 + seg, 0x0006, memoryAGet16(0x0b52 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b526
        memoryASet16(0x0b52 + seg, 0x000a, memoryAGet16(0x0b52 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b52a
        memoryASet16(0x0b52 + seg, 0x000e, memoryAGet16(0x0b52 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b52e
        memoryASet16(0x0b53 + seg, 0x0006, memoryAGet16(0x0b53 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b536
        memoryASet16(0x0b53 + seg, 0x000a, memoryAGet16(0x0b53 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b53a
        memoryASet16(0x0b53 + seg, 0x000e, memoryAGet16(0x0b53 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b53e
        memoryASet16(0x0b54 + seg, 0x0006, memoryAGet16(0x0b54 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b546
        memoryASet16(0x0b54 + seg, 0x000a, memoryAGet16(0x0b54 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b54a
        memoryASet16(0x0b54 + seg, 0x000e, memoryAGet16(0x0b54 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b54e
        memoryASet16(0x0b55 + seg, 0x0006, memoryAGet16(0x0b55 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b556
        memoryASet16(0x0b55 + seg, 0x000a, memoryAGet16(0x0b55 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b55a
        memoryASet16(0x0b55 + seg, 0x000e, memoryAGet16(0x0b55 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b55e
        memoryASet16(0x0b56 + seg, 0x0006, memoryAGet16(0x0b56 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b566
        memoryASet16(0x0b56 + seg, 0x000a, memoryAGet16(0x0b56 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b56a
        memoryASet16(0x0b56 + seg, 0x000e, memoryAGet16(0x0b56 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b56e
        memoryASet16(0x0b57 + seg, 0x0006, memoryAGet16(0x0b57 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b576
        memoryASet16(0x0b57 + seg, 0x000a, memoryAGet16(0x0b57 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b57a
        memoryASet16(0x0b57 + seg, 0x000e, memoryAGet16(0x0b57 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b57e
        memoryASet16(0x0b58 + seg, 0x0006, memoryAGet16(0x0b58 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b586
        memoryASet16(0x0b58 + seg, 0x000a, memoryAGet16(0x0b58 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b58a
        memoryASet16(0x0b58 + seg, 0x000e, memoryAGet16(0x0b58 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b58e
        memoryASet16(0x0b59 + seg, 0x0006, memoryAGet16(0x0b59 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b596
        memoryASet16(0x0b59 + seg, 0x000a, memoryAGet16(0x0b59 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b59a
        memoryASet16(0x0b59 + seg, 0x000e, memoryAGet16(0x0b59 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b59e
        memoryASet16(0x0b5a + seg, 0x0006, memoryAGet16(0x0b5a + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5a6
        memoryASet16(0x0b5a + seg, 0x000a, memoryAGet16(0x0b5a + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5aa
        memoryASet16(0x0b5a + seg, 0x000e, memoryAGet16(0x0b5a + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5ae
        memoryASet16(0x0b5b + seg, 0x0006, memoryAGet16(0x0b5b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5b6
        memoryASet16(0x0b5b + seg, 0x000a, memoryAGet16(0x0b5b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5ba
        memoryASet16(0x0b5b + seg, 0x000e, memoryAGet16(0x0b5b + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5be
        memoryASet16(0x0b5c + seg, 0x0006, memoryAGet16(0x0b5c + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5c6
        memoryASet16(0x0b5c + seg, 0x000a, memoryAGet16(0x0b5c + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5ca
        memoryASet16(0x0b5c + seg, 0x000e, memoryAGet16(0x0b5c + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5ce
        memoryASet16(0x0b5d + seg, 0x0006, memoryAGet16(0x0b5d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5d6
        memoryASet16(0x0b5d + seg, 0x000a, memoryAGet16(0x0b5d + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5da
        memoryASet16(0x0b5d + seg, 0x000e, memoryAGet16(0x0b5d + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5de
        memoryASet16(0x0b5e + seg, 0x0006, memoryAGet16(0x0b5e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5e6
        memoryASet16(0x0b5e + seg, 0x000a, memoryAGet16(0x0b5e + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5ea
        memoryASet16(0x0b5e + seg, 0x000e, memoryAGet16(0x0b5e + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5ee
        memoryASet16(0x0b5f + seg, 0x0006, memoryAGet16(0x0b5f + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b5f6
        memoryASet16(0x0b5f + seg, 0x000a, memoryAGet16(0x0b5f + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b5fa
        memoryASet16(0x0b5f + seg, 0x000e, memoryAGet16(0x0b5f + seg, 0x000e) + seg); // 1463 -> 1650; lin=b5fe
        memoryASet16(0x0b60 + seg, 0x0006, memoryAGet16(0x0b60 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b606
        memoryASet16(0x0b60 + seg, 0x000a, memoryAGet16(0x0b60 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b60a
        memoryASet16(0x0b60 + seg, 0x000e, memoryAGet16(0x0b60 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b60e
        memoryASet16(0x0b61 + seg, 0x0006, memoryAGet16(0x0b61 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b616
        memoryASet16(0x0b61 + seg, 0x000a, memoryAGet16(0x0b61 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b61a
        memoryASet16(0x0b61 + seg, 0x000e, memoryAGet16(0x0b61 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b61e
        memoryASet16(0x0b62 + seg, 0x0006, memoryAGet16(0x0b62 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b626
        memoryASet16(0x0b62 + seg, 0x000a, memoryAGet16(0x0b62 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b62a
        memoryASet16(0x0b62 + seg, 0x000e, memoryAGet16(0x0b62 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b62e
        memoryASet16(0x0b63 + seg, 0x0006, memoryAGet16(0x0b63 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b636
        memoryASet16(0x0b63 + seg, 0x000a, memoryAGet16(0x0b63 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b63a
        memoryASet16(0x0b63 + seg, 0x000e, memoryAGet16(0x0b63 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b63e
        memoryASet16(0x0b64 + seg, 0x0006, memoryAGet16(0x0b64 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b646
        memoryASet16(0x0b64 + seg, 0x000a, memoryAGet16(0x0b64 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b64a
        memoryASet16(0x0b64 + seg, 0x000e, memoryAGet16(0x0b64 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b64e
        memoryASet16(0x0b65 + seg, 0x0006, memoryAGet16(0x0b65 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b656
        memoryASet16(0x0b65 + seg, 0x000a, memoryAGet16(0x0b65 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b65a
        memoryASet16(0x0b65 + seg, 0x000e, memoryAGet16(0x0b65 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b65e
        memoryASet16(0x0b66 + seg, 0x0006, memoryAGet16(0x0b66 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b666
        memoryASet16(0x0b66 + seg, 0x000a, memoryAGet16(0x0b66 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b66a
        memoryASet16(0x0b66 + seg, 0x000e, memoryAGet16(0x0b66 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b66e
        memoryASet16(0x0b67 + seg, 0x0006, memoryAGet16(0x0b67 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b676
        memoryASet16(0x0b67 + seg, 0x000a, memoryAGet16(0x0b67 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b67a
        memoryASet16(0x0b67 + seg, 0x000e, memoryAGet16(0x0b67 + seg, 0x000e) + seg); // 1463 -> 1650; lin=b67e
        memoryASet16(0x0b68 + seg, 0x0006, memoryAGet16(0x0b68 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=b686
        memoryASet16(0x0b68 + seg, 0x000a, memoryAGet16(0x0b68 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=b68a
        memoryASet16(0x0baa + seg, 0x0000, memoryAGet16(0x0baa + seg, 0x0000) + seg); // 3170 -> 335d; lin=baa0
        memoryASet16(0x0baa + seg, 0x0008, memoryAGet16(0x0baa + seg, 0x0008) + seg); // 2403 -> 25f0; lin=baa8
        memoryASet16(0x0baa + seg, 0x000c, memoryAGet16(0x0baa + seg, 0x000c) + seg); // 2403 -> 25f0; lin=baac
        memoryASet16(0x0bac + seg, 0x0000, memoryAGet16(0x0bac + seg, 0x0000) + seg); // 2403 -> 25f0; lin=bac0
        memoryASet16(0x0bac + seg, 0x0004, memoryAGet16(0x0bac + seg, 0x0004) + seg); // 2403 -> 25f0; lin=bac4
        memoryASet16(0x0bad + seg, 0x0008, memoryAGet16(0x0bad + seg, 0x0008) + seg); // 2403 -> 25f0; lin=bad8
        memoryASet16(0x0bad + seg, 0x000c, memoryAGet16(0x0bad + seg, 0x000c) + seg); // 2403 -> 25f0; lin=badc
        memoryASet16(0x0bae + seg, 0x000e, memoryAGet16(0x0bae + seg, 0x000e) + seg); // 2403 -> 25f0; lin=baee
        memoryASet16(0x0baf + seg, 0x0002, memoryAGet16(0x0baf + seg, 0x0002) + seg); // 2403 -> 25f0; lin=baf2
        memoryASet16(0x0bb0 + seg, 0x0004, memoryAGet16(0x0bb0 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=bb04
        memoryASet16(0x0bb0 + seg, 0x0008, memoryAGet16(0x0bb0 + seg, 0x0008) + seg); // 2403 -> 25f0; lin=bb08
        memoryASet16(0x0bb1 + seg, 0x000a, memoryAGet16(0x0bb1 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=bb1a
        memoryASet16(0x0bb1 + seg, 0x000e, memoryAGet16(0x0bb1 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=bb1e
        memoryASet16(0x0bb3 + seg, 0x0000, memoryAGet16(0x0bb3 + seg, 0x0000) + seg); // 2403 -> 25f0; lin=bb30
        memoryASet16(0x0bb3 + seg, 0x0004, memoryAGet16(0x0bb3 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=bb34
        memoryASet16(0x0bb3 + seg, 0x0008, memoryAGet16(0x0bb3 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb38
        memoryASet16(0x0bb4 + seg, 0x0000, memoryAGet16(0x0bb4 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb40
        memoryASet16(0x0bb4 + seg, 0x0008, memoryAGet16(0x0bb4 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb48
        memoryASet16(0x0bb5 + seg, 0x0000, memoryAGet16(0x0bb5 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb50
        memoryASet16(0x0bb5 + seg, 0x0008, memoryAGet16(0x0bb5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb58
        memoryASet16(0x0bb6 + seg, 0x0000, memoryAGet16(0x0bb6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb60
        memoryASet16(0x0bb6 + seg, 0x0008, memoryAGet16(0x0bb6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb68
        memoryASet16(0x0bb7 + seg, 0x0000, memoryAGet16(0x0bb7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb70
        memoryASet16(0x0bb7 + seg, 0x0008, memoryAGet16(0x0bb7 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb78
        memoryASet16(0x0bb8 + seg, 0x0000, memoryAGet16(0x0bb8 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb80
        memoryASet16(0x0bb8 + seg, 0x0008, memoryAGet16(0x0bb8 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb88
        memoryASet16(0x0bb9 + seg, 0x0000, memoryAGet16(0x0bb9 + seg, 0x0000) + seg); // 3170 -> 335d; lin=bb90
        memoryASet16(0x0bb9 + seg, 0x0008, memoryAGet16(0x0bb9 + seg, 0x0008) + seg); // 3170 -> 335d; lin=bb98
        memoryASet16(0x0bba + seg, 0x0000, memoryAGet16(0x0bba + seg, 0x0000) + seg); // 3170 -> 335d; lin=bba0
        memoryASet16(0x0bba + seg, 0x0008, memoryAGet16(0x0bba + seg, 0x0008) + seg); // 3170 -> 335d; lin=bba8
        memoryASet16(0x0bbb + seg, 0x0004, memoryAGet16(0x0bbb + seg, 0x0004) + seg); // 3170 -> 335d; lin=bbb4
        memoryASet16(0x0bbb + seg, 0x000a, memoryAGet16(0x0bbb + seg, 0x000a) + seg); // 3170 -> 335d; lin=bbba
        memoryASet16(0x0bbc + seg, 0x0000, memoryAGet16(0x0bbc + seg, 0x0000) + seg); // 3170 -> 335d; lin=bbc0
        memoryASet16(0x0bbc + seg, 0x0006, memoryAGet16(0x0bbc + seg, 0x0006) + seg); // 3170 -> 335d; lin=bbc6
        memoryASet16(0x0bbd + seg, 0x0000, memoryAGet16(0x0bbd + seg, 0x0000) + seg); // 3170 -> 335d; lin=bbd0
        memoryASet16(0x0bbd + seg, 0x0006, memoryAGet16(0x0bbd + seg, 0x0006) + seg); // 3170 -> 335d; lin=bbd6
        memoryASet16(0x0bbd + seg, 0x000c, memoryAGet16(0x0bbd + seg, 0x000c) + seg); // 3170 -> 335d; lin=bbdc
        memoryASet16(0x0bbe + seg, 0x0002, memoryAGet16(0x0bbe + seg, 0x0002) + seg); // 3170 -> 335d; lin=bbe2
        memoryASet16(0x0bbe + seg, 0x000c, memoryAGet16(0x0bbe + seg, 0x000c) + seg); // 1463 -> 1650; lin=bbec
        memoryASet16(0x0bbf + seg, 0x0000, memoryAGet16(0x0bbf + seg, 0x0000) + seg); // 1463 -> 1650; lin=bbf0
        memoryASet16(0x0bbf + seg, 0x0004, memoryAGet16(0x0bbf + seg, 0x0004) + seg); // 1463 -> 1650; lin=bbf4
        memoryASet16(0x0bbf + seg, 0x0008, memoryAGet16(0x0bbf + seg, 0x0008) + seg); // 1463 -> 1650; lin=bbf8
        memoryASet16(0x0bbf + seg, 0x000c, memoryAGet16(0x0bbf + seg, 0x000c) + seg); // 1463 -> 1650; lin=bbfc
        memoryASet16(0x0bc0 + seg, 0x0000, memoryAGet16(0x0bc0 + seg, 0x0000) + seg); // 1463 -> 1650; lin=bc00
        memoryASet16(0x0bf5 + seg, 0x0004, memoryAGet16(0x0bf5 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=bf54
        memoryASet16(0x0bf5 + seg, 0x0008, memoryAGet16(0x0bf5 + seg, 0x0008) + seg); // 2403 -> 25f0; lin=bf58
        memoryASet16(0x0c7b + seg, 0x0000, memoryAGet16(0x0c7b + seg, 0x0000) + seg); // 1463 -> 1650; lin=c7b0
        memoryASet16(0x0c7b + seg, 0x0004, memoryAGet16(0x0c7b + seg, 0x0004) + seg); // 1463 -> 1650; lin=c7b4
        memoryASet16(0x0c7b + seg, 0x0008, memoryAGet16(0x0c7b + seg, 0x0008) + seg); // 1463 -> 1650; lin=c7b8
        memoryASet16(0x0c7b + seg, 0x000c, memoryAGet16(0x0c7b + seg, 0x000c) + seg); // 1463 -> 1650; lin=c7bc
        memoryASet16(0x0c87 + seg, 0x000c, memoryAGet16(0x0c87 + seg, 0x000c) + seg); // 2403 -> 25f0; lin=c87c
        memoryASet16(0x0c88 + seg, 0x0000, memoryAGet16(0x0c88 + seg, 0x0000) + seg); // 2403 -> 25f0; lin=c880
        memoryASet16(0x0c8b + seg, 0x0005, memoryAGet16(0x0c8b + seg, 0x0005) + seg); // 2403 -> 25f0; lin=c8b5
        memoryASet16(0x0c8b + seg, 0x0009, memoryAGet16(0x0c8b + seg, 0x0009) + seg); // 2403 -> 25f0; lin=c8b9
        memoryASet16(0x0c8b + seg, 0x000d, memoryAGet16(0x0c8b + seg, 0x000d) + seg); // 1463 -> 1650; lin=c8bd
        memoryASet16(0x0c8c + seg, 0x0005, memoryAGet16(0x0c8c + seg, 0x0005) + seg); // 1463 -> 1650; lin=c8c5
        memoryASet16(0x0c8c + seg, 0x000d, memoryAGet16(0x0c8c + seg, 0x000d) + seg); // 1463 -> 1650; lin=c8cd
        memoryASet16(0x0c8d + seg, 0x0005, memoryAGet16(0x0c8d + seg, 0x0005) + seg); // 1463 -> 1650; lin=c8d5
        memoryASet16(0x0d0b + seg, 0x0002, memoryAGet16(0x0d0b + seg, 0x0002) + seg); // 4110 -> 42fd; lin=d0b2
        memoryASet16(0x0d0b + seg, 0x0006, memoryAGet16(0x0d0b + seg, 0x0006) + seg); // 4110 -> 42fd; lin=d0b6
        memoryASet16(0x0d0b + seg, 0x000a, memoryAGet16(0x0d0b + seg, 0x000a) + seg); // 4110 -> 42fd; lin=d0ba
        memoryASet16(0x0d0b + seg, 0x000e, memoryAGet16(0x0d0b + seg, 0x000e) + seg); // 4110 -> 42fd; lin=d0be
        memoryASet16(0x0d0c + seg, 0x0002, memoryAGet16(0x0d0c + seg, 0x0002) + seg); // 4110 -> 42fd; lin=d0c2
        memoryASet16(0x0d0c + seg, 0x0006, memoryAGet16(0x0d0c + seg, 0x0006) + seg); // 4110 -> 42fd; lin=d0c6
        memoryASet16(0x0d0c + seg, 0x000a, memoryAGet16(0x0d0c + seg, 0x000a) + seg); // 4110 -> 42fd; lin=d0ca
        memoryASet16(0x0d46 + seg, 0x0002, memoryAGet16(0x0d46 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=d462
        memoryASet16(0x0d46 + seg, 0x0006, memoryAGet16(0x0d46 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=d466
        memoryASet16(0x0d47 + seg, 0x000c, memoryAGet16(0x0d47 + seg, 0x000c) + seg); // 2403 -> 25f0; lin=d47c
        memoryASet16(0x0d48 + seg, 0x0000, memoryAGet16(0x0d48 + seg, 0x0000) + seg); // 2403 -> 25f0; lin=d480
        memoryASet16(0x0d49 + seg, 0x0006, memoryAGet16(0x0d49 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=d496
        memoryASet16(0x0d49 + seg, 0x000a, memoryAGet16(0x0d49 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=d49a
        memoryASet16(0x0d7f + seg, 0x000b, memoryAGet16(0x0d7f + seg, 0x000b) + seg); // 3170 -> 335d; lin=d7fb
        memoryASet16(0x0d7f + seg, 0x000f, memoryAGet16(0x0d7f + seg, 0x000f) + seg); // 3170 -> 335d; lin=d7ff
        memoryASet16(0x0d80 + seg, 0x0003, memoryAGet16(0x0d80 + seg, 0x0003) + seg); // 3170 -> 335d; lin=d803
        memoryASet16(0x0d80 + seg, 0x0007, memoryAGet16(0x0d80 + seg, 0x0007) + seg); // 3170 -> 335d; lin=d807
        memoryASet16(0x0d80 + seg, 0x000b, memoryAGet16(0x0d80 + seg, 0x000b) + seg); // 3170 -> 335d; lin=d80b
        memoryASet16(0x0d80 + seg, 0x000f, memoryAGet16(0x0d80 + seg, 0x000f) + seg); // 3170 -> 335d; lin=d80f
        memoryASet16(0x0d81 + seg, 0x0003, memoryAGet16(0x0d81 + seg, 0x0003) + seg); // 3170 -> 335d; lin=d813
        memoryASet16(0x0d81 + seg, 0x0007, memoryAGet16(0x0d81 + seg, 0x0007) + seg); // 3170 -> 335d; lin=d817
        memoryASet16(0x0d82 + seg, 0x0003, memoryAGet16(0x0d82 + seg, 0x0003) + seg); // 2403 -> 25f0; lin=d823
        memoryASet16(0x0d82 + seg, 0x0007, memoryAGet16(0x0d82 + seg, 0x0007) + seg); // 2403 -> 25f0; lin=d827
        memoryASet16(0x0d83 + seg, 0x0003, memoryAGet16(0x0d83 + seg, 0x0003) + seg); // 2403 -> 25f0; lin=d833
        memoryASet16(0x0d83 + seg, 0x0007, memoryAGet16(0x0d83 + seg, 0x0007) + seg); // 2403 -> 25f0; lin=d837
        memoryASet16(0x0d84 + seg, 0x0003, memoryAGet16(0x0d84 + seg, 0x0003) + seg); // 2403 -> 25f0; lin=d843
        memoryASet16(0x0d84 + seg, 0x0007, memoryAGet16(0x0d84 + seg, 0x0007) + seg); // 2403 -> 25f0; lin=d847
        memoryASet16(0x0d8c + seg, 0x0004, memoryAGet16(0x0d8c + seg, 0x0004) + seg); // 3170 -> 335d; lin=d8c4
        memoryASet16(0x0d8c + seg, 0x000a, memoryAGet16(0x0d8c + seg, 0x000a) + seg); // 3170 -> 335d; lin=d8ca
        memoryASet16(0x0d8d + seg, 0x0000, memoryAGet16(0x0d8d + seg, 0x0000) + seg); // 3170 -> 335d; lin=d8d0
        memoryASet16(0x0d8d + seg, 0x0006, memoryAGet16(0x0d8d + seg, 0x0006) + seg); // 3170 -> 335d; lin=d8d6
        memoryASet16(0x0d8d + seg, 0x000c, memoryAGet16(0x0d8d + seg, 0x000c) + seg); // 3170 -> 335d; lin=d8dc
        memoryASet16(0x0d8e + seg, 0x0002, memoryAGet16(0x0d8e + seg, 0x0002) + seg); // 3170 -> 335d; lin=d8e2
        memoryASet16(0x0d8e + seg, 0x0008, memoryAGet16(0x0d8e + seg, 0x0008) + seg); // 3170 -> 335d; lin=d8e8
        memoryASet16(0x0d8e + seg, 0x000e, memoryAGet16(0x0d8e + seg, 0x000e) + seg); // 3170 -> 335d; lin=d8ee
        memoryASet16(0x0d8f + seg, 0x0004, memoryAGet16(0x0d8f + seg, 0x0004) + seg); // 3170 -> 335d; lin=d8f4
        memoryASet16(0x0d8f + seg, 0x000a, memoryAGet16(0x0d8f + seg, 0x000a) + seg); // 3170 -> 335d; lin=d8fa
        memoryASet16(0x0d90 + seg, 0x0000, memoryAGet16(0x0d90 + seg, 0x0000) + seg); // 3170 -> 335d; lin=d900
        memoryASet16(0x0dab + seg, 0x0006, memoryAGet16(0x0dab + seg, 0x0006) + seg); // 4110 -> 42fd; lin=dab6
        memoryASet16(0x0dab + seg, 0x000a, memoryAGet16(0x0dab + seg, 0x000a) + seg); // 4110 -> 42fd; lin=daba
        memoryASet16(0x0dab + seg, 0x000e, memoryAGet16(0x0dab + seg, 0x000e) + seg); // 4110 -> 42fd; lin=dabe
        memoryASet16(0x0dac + seg, 0x0002, memoryAGet16(0x0dac + seg, 0x0002) + seg); // 4110 -> 42fd; lin=dac2
        memoryASet16(0x0dac + seg, 0x0006, memoryAGet16(0x0dac + seg, 0x0006) + seg); // 4110 -> 42fd; lin=dac6
        memoryASet16(0x0dac + seg, 0x000a, memoryAGet16(0x0dac + seg, 0x000a) + seg); // 4110 -> 42fd; lin=daca
        memoryASet16(0x0dac + seg, 0x000e, memoryAGet16(0x0dac + seg, 0x000e) + seg); // 4110 -> 42fd; lin=dace
        memoryASet16(0x0dad + seg, 0x0002, memoryAGet16(0x0dad + seg, 0x0002) + seg); // 4110 -> 42fd; lin=dad2
        memoryASet16(0x0dad + seg, 0x0006, memoryAGet16(0x0dad + seg, 0x0006) + seg); // 4110 -> 42fd; lin=dad6
        memoryASet16(0x0dad + seg, 0x000a, memoryAGet16(0x0dad + seg, 0x000a) + seg); // 4110 -> 42fd; lin=dada
        memoryASet16(0x0dad + seg, 0x000e, memoryAGet16(0x0dad + seg, 0x000e) + seg); // 4110 -> 42fd; lin=dade
        memoryASet16(0x0dae + seg, 0x0002, memoryAGet16(0x0dae + seg, 0x0002) + seg); // 4110 -> 42fd; lin=dae2
        memoryASet16(0x0dae + seg, 0x0006, memoryAGet16(0x0dae + seg, 0x0006) + seg); // 4110 -> 42fd; lin=dae6
        memoryASet16(0x0dae + seg, 0x000a, memoryAGet16(0x0dae + seg, 0x000a) + seg); // 4110 -> 42fd; lin=daea
        memoryASet16(0x0dae + seg, 0x000e, memoryAGet16(0x0dae + seg, 0x000e) + seg); // 4110 -> 42fd; lin=daee
        memoryASet16(0x0daf + seg, 0x0002, memoryAGet16(0x0daf + seg, 0x0002) + seg); // 4110 -> 42fd; lin=daf2
        memoryASet16(0x0daf + seg, 0x000a, memoryAGet16(0x0daf + seg, 0x000a) + seg); // 4110 -> 42fd; lin=dafa
        memoryASet16(0x0daf + seg, 0x000e, memoryAGet16(0x0daf + seg, 0x000e) + seg); // 4110 -> 42fd; lin=dafe
        memoryASet16(0x0db0 + seg, 0x0002, memoryAGet16(0x0db0 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db02
        memoryASet16(0x0db0 + seg, 0x0006, memoryAGet16(0x0db0 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db06
        memoryASet16(0x0db0 + seg, 0x000a, memoryAGet16(0x0db0 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db0a
        memoryASet16(0x0db0 + seg, 0x000e, memoryAGet16(0x0db0 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db0e
        memoryASet16(0x0db1 + seg, 0x0002, memoryAGet16(0x0db1 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db12
        memoryASet16(0x0db1 + seg, 0x0006, memoryAGet16(0x0db1 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db16
        memoryASet16(0x0db1 + seg, 0x000a, memoryAGet16(0x0db1 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db1a
        memoryASet16(0x0db1 + seg, 0x000e, memoryAGet16(0x0db1 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db1e
        memoryASet16(0x0db2 + seg, 0x0002, memoryAGet16(0x0db2 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db22
        memoryASet16(0x0db2 + seg, 0x0006, memoryAGet16(0x0db2 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db26
        memoryASet16(0x0db2 + seg, 0x000a, memoryAGet16(0x0db2 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db2a
        memoryASet16(0x0db2 + seg, 0x000e, memoryAGet16(0x0db2 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db2e
        memoryASet16(0x0db3 + seg, 0x0002, memoryAGet16(0x0db3 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db32
        memoryASet16(0x0db3 + seg, 0x0006, memoryAGet16(0x0db3 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db36
        memoryASet16(0x0db3 + seg, 0x000e, memoryAGet16(0x0db3 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db3e
        memoryASet16(0x0db4 + seg, 0x0002, memoryAGet16(0x0db4 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db42
        memoryASet16(0x0db4 + seg, 0x0006, memoryAGet16(0x0db4 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db46
        memoryASet16(0x0db4 + seg, 0x000a, memoryAGet16(0x0db4 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db4a
        memoryASet16(0x0db4 + seg, 0x000e, memoryAGet16(0x0db4 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db4e
        memoryASet16(0x0db5 + seg, 0x0002, memoryAGet16(0x0db5 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db52
        memoryASet16(0x0db5 + seg, 0x000a, memoryAGet16(0x0db5 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db5a
        memoryASet16(0x0db5 + seg, 0x000e, memoryAGet16(0x0db5 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db5e
        memoryASet16(0x0db6 + seg, 0x0002, memoryAGet16(0x0db6 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=db62
        memoryASet16(0x0db6 + seg, 0x0006, memoryAGet16(0x0db6 + seg, 0x0006) + seg); // 4110 -> 42fd; lin=db66
        memoryASet16(0x0db6 + seg, 0x000a, memoryAGet16(0x0db6 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=db6a
        memoryASet16(0x0db6 + seg, 0x000e, memoryAGet16(0x0db6 + seg, 0x000e) + seg); // 4110 -> 42fd; lin=db6e
        memoryASet16(0x0db7 + seg, 0x0006, memoryAGet16(0x0db7 + seg, 0x0006) + seg); // 3170 -> 335d; lin=db76
        memoryASet16(0x0db7 + seg, 0x000a, memoryAGet16(0x0db7 + seg, 0x000a) + seg); // 3170 -> 335d; lin=db7a
        memoryASet16(0x0db7 + seg, 0x000e, memoryAGet16(0x0db7 + seg, 0x000e) + seg); // 3170 -> 335d; lin=db7e
        memoryASet16(0x0db8 + seg, 0x0002, memoryAGet16(0x0db8 + seg, 0x0002) + seg); // 3170 -> 335d; lin=db82
        memoryASet16(0x0db8 + seg, 0x0006, memoryAGet16(0x0db8 + seg, 0x0006) + seg); // 3170 -> 335d; lin=db86
        memoryASet16(0x0db8 + seg, 0x000a, memoryAGet16(0x0db8 + seg, 0x000a) + seg); // 3170 -> 335d; lin=db8a
        memoryASet16(0x0db8 + seg, 0x000e, memoryAGet16(0x0db8 + seg, 0x000e) + seg); // 3170 -> 335d; lin=db8e
        memoryASet16(0x0db9 + seg, 0x0002, memoryAGet16(0x0db9 + seg, 0x0002) + seg); // 3170 -> 335d; lin=db92
        memoryASet16(0x0db9 + seg, 0x0006, memoryAGet16(0x0db9 + seg, 0x0006) + seg); // 3170 -> 335d; lin=db96
        memoryASet16(0x0db9 + seg, 0x000a, memoryAGet16(0x0db9 + seg, 0x000a) + seg); // 3170 -> 335d; lin=db9a
        memoryASet16(0x0db9 + seg, 0x000e, memoryAGet16(0x0db9 + seg, 0x000e) + seg); // 3170 -> 335d; lin=db9e
        memoryASet16(0x0dba + seg, 0x0002, memoryAGet16(0x0dba + seg, 0x0002) + seg); // 3170 -> 335d; lin=dba2
        memoryASet16(0x0dba + seg, 0x0006, memoryAGet16(0x0dba + seg, 0x0006) + seg); // 3170 -> 335d; lin=dba6
        memoryASet16(0x0dba + seg, 0x000a, memoryAGet16(0x0dba + seg, 0x000a) + seg); // 3170 -> 335d; lin=dbaa
        memoryASet16(0x0dba + seg, 0x000e, memoryAGet16(0x0dba + seg, 0x000e) + seg); // 3170 -> 335d; lin=dbae
        memoryASet16(0x0dbb + seg, 0x0002, memoryAGet16(0x0dbb + seg, 0x0002) + seg); // 3170 -> 335d; lin=dbb2
        memoryASet16(0x0dbb + seg, 0x000a, memoryAGet16(0x0dbb + seg, 0x000a) + seg); // 3170 -> 335d; lin=dbba
        memoryASet16(0x0dbb + seg, 0x000e, memoryAGet16(0x0dbb + seg, 0x000e) + seg); // 3170 -> 335d; lin=dbbe
        memoryASet16(0x0dbc + seg, 0x0002, memoryAGet16(0x0dbc + seg, 0x0002) + seg); // 3170 -> 335d; lin=dbc2
        memoryASet16(0x0dbc + seg, 0x0006, memoryAGet16(0x0dbc + seg, 0x0006) + seg); // 3170 -> 335d; lin=dbc6
        memoryASet16(0x0dbc + seg, 0x000a, memoryAGet16(0x0dbc + seg, 0x000a) + seg); // 3170 -> 335d; lin=dbca
        memoryASet16(0x0dbd + seg, 0x0000, memoryAGet16(0x0dbd + seg, 0x0000) + seg); // 3170 -> 335d; lin=dbd0
        memoryASet16(0x0dbd + seg, 0x0004, memoryAGet16(0x0dbd + seg, 0x0004) + seg); // 3170 -> 335d; lin=dbd4
        memoryASet16(0x0dbd + seg, 0x0008, memoryAGet16(0x0dbd + seg, 0x0008) + seg); // 3170 -> 335d; lin=dbd8
        memoryASet16(0x0dbd + seg, 0x000c, memoryAGet16(0x0dbd + seg, 0x000c) + seg); // 3170 -> 335d; lin=dbdc
        memoryASet16(0x0dbe + seg, 0x0000, memoryAGet16(0x0dbe + seg, 0x0000) + seg); // 3170 -> 335d; lin=dbe0
        memoryASet16(0x0dbe + seg, 0x0004, memoryAGet16(0x0dbe + seg, 0x0004) + seg); // 3170 -> 335d; lin=dbe4
        memoryASet16(0x0dbe + seg, 0x0008, memoryAGet16(0x0dbe + seg, 0x0008) + seg); // 3170 -> 335d; lin=dbe8
        memoryASet16(0x0dbe + seg, 0x000c, memoryAGet16(0x0dbe + seg, 0x000c) + seg); // 3170 -> 335d; lin=dbec
        memoryASet16(0x0dbf + seg, 0x0000, memoryAGet16(0x0dbf + seg, 0x0000) + seg); // 3170 -> 335d; lin=dbf0
        memoryASet16(0x0dbf + seg, 0x0004, memoryAGet16(0x0dbf + seg, 0x0004) + seg); // 3170 -> 335d; lin=dbf4
        memoryASet16(0x0dbf + seg, 0x0008, memoryAGet16(0x0dbf + seg, 0x0008) + seg); // 3170 -> 335d; lin=dbf8
        memoryASet16(0x0dbf + seg, 0x000c, memoryAGet16(0x0dbf + seg, 0x000c) + seg); // 3170 -> 335d; lin=dbfc
        memoryASet16(0x0dc0 + seg, 0x0000, memoryAGet16(0x0dc0 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dc00
        memoryASet16(0x0dc0 + seg, 0x0004, memoryAGet16(0x0dc0 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dc04
        memoryASet16(0x0dc0 + seg, 0x0008, memoryAGet16(0x0dc0 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dc08
        memoryASet16(0x0dc0 + seg, 0x000c, memoryAGet16(0x0dc0 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dc0c
        memoryASet16(0x0dc1 + seg, 0x0004, memoryAGet16(0x0dc1 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dc14
        memoryASet16(0x0dc1 + seg, 0x0008, memoryAGet16(0x0dc1 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dc18
        memoryASet16(0x0dc1 + seg, 0x000c, memoryAGet16(0x0dc1 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dc1c
        memoryASet16(0x0dc2 + seg, 0x0000, memoryAGet16(0x0dc2 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dc20
        memoryASet16(0x0dc2 + seg, 0x0004, memoryAGet16(0x0dc2 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dc24
        memoryASet16(0x0dc2 + seg, 0x0008, memoryAGet16(0x0dc2 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dc28
        memoryASet16(0x0dc2 + seg, 0x000c, memoryAGet16(0x0dc2 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dc2c
        memoryASet16(0x0dc3 + seg, 0x0002, memoryAGet16(0x0dc3 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dc32
        memoryASet16(0x0dc3 + seg, 0x0006, memoryAGet16(0x0dc3 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc36
        memoryASet16(0x0dc3 + seg, 0x000a, memoryAGet16(0x0dc3 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc3a
        memoryASet16(0x0dc3 + seg, 0x000e, memoryAGet16(0x0dc3 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc3e
        memoryASet16(0x0dc4 + seg, 0x0002, memoryAGet16(0x0dc4 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dc42
        memoryASet16(0x0dc4 + seg, 0x0006, memoryAGet16(0x0dc4 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc46
        memoryASet16(0x0dc4 + seg, 0x000a, memoryAGet16(0x0dc4 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc4a
        memoryASet16(0x0dc4 + seg, 0x000e, memoryAGet16(0x0dc4 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc4e
        memoryASet16(0x0dc5 + seg, 0x0002, memoryAGet16(0x0dc5 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dc52
        memoryASet16(0x0dc5 + seg, 0x0006, memoryAGet16(0x0dc5 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc56
        memoryASet16(0x0dc5 + seg, 0x000a, memoryAGet16(0x0dc5 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc5a
        memoryASet16(0x0dc5 + seg, 0x000e, memoryAGet16(0x0dc5 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc5e
        memoryASet16(0x0dc6 + seg, 0x0002, memoryAGet16(0x0dc6 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dc62
        memoryASet16(0x0dc6 + seg, 0x0006, memoryAGet16(0x0dc6 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc66
        memoryASet16(0x0dc6 + seg, 0x000a, memoryAGet16(0x0dc6 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc6a
        memoryASet16(0x0dc6 + seg, 0x000e, memoryAGet16(0x0dc6 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc6e
        memoryASet16(0x0dc7 + seg, 0x0006, memoryAGet16(0x0dc7 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc76
        memoryASet16(0x0dc7 + seg, 0x000a, memoryAGet16(0x0dc7 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc7a
        memoryASet16(0x0dc7 + seg, 0x000e, memoryAGet16(0x0dc7 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc7e
        memoryASet16(0x0dc8 + seg, 0x0002, memoryAGet16(0x0dc8 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dc82
        memoryASet16(0x0dc8 + seg, 0x0006, memoryAGet16(0x0dc8 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dc86
        memoryASet16(0x0dc8 + seg, 0x000a, memoryAGet16(0x0dc8 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dc8a
        memoryASet16(0x0dc8 + seg, 0x000e, memoryAGet16(0x0dc8 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dc8e
        memoryASet16(0x0dc9 + seg, 0x0004, memoryAGet16(0x0dc9 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dc94
        memoryASet16(0x0dc9 + seg, 0x0008, memoryAGet16(0x0dc9 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dc98
        memoryASet16(0x0dc9 + seg, 0x000c, memoryAGet16(0x0dc9 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dc9c
        memoryASet16(0x0dca + seg, 0x0000, memoryAGet16(0x0dca + seg, 0x0000) + seg); // 3170 -> 335d; lin=dca0
        memoryASet16(0x0dca + seg, 0x0004, memoryAGet16(0x0dca + seg, 0x0004) + seg); // 3170 -> 335d; lin=dca4
        memoryASet16(0x0dca + seg, 0x0008, memoryAGet16(0x0dca + seg, 0x0008) + seg); // 3170 -> 335d; lin=dca8
        memoryASet16(0x0dca + seg, 0x000c, memoryAGet16(0x0dca + seg, 0x000c) + seg); // 3170 -> 335d; lin=dcac
        memoryASet16(0x0dcb + seg, 0x0000, memoryAGet16(0x0dcb + seg, 0x0000) + seg); // 3170 -> 335d; lin=dcb0
        memoryASet16(0x0dcb + seg, 0x0004, memoryAGet16(0x0dcb + seg, 0x0004) + seg); // 3170 -> 335d; lin=dcb4
        memoryASet16(0x0dcb + seg, 0x0008, memoryAGet16(0x0dcb + seg, 0x0008) + seg); // 3170 -> 335d; lin=dcb8
        memoryASet16(0x0dcb + seg, 0x000c, memoryAGet16(0x0dcb + seg, 0x000c) + seg); // 3170 -> 335d; lin=dcbc
        memoryASet16(0x0dcc + seg, 0x0000, memoryAGet16(0x0dcc + seg, 0x0000) + seg); // 3170 -> 335d; lin=dcc0
        memoryASet16(0x0dcc + seg, 0x0004, memoryAGet16(0x0dcc + seg, 0x0004) + seg); // 3170 -> 335d; lin=dcc4
        memoryASet16(0x0dcc + seg, 0x0008, memoryAGet16(0x0dcc + seg, 0x0008) + seg); // 3170 -> 335d; lin=dcc8
        memoryASet16(0x0dcc + seg, 0x000c, memoryAGet16(0x0dcc + seg, 0x000c) + seg); // 3170 -> 335d; lin=dccc
        memoryASet16(0x0dcd + seg, 0x0000, memoryAGet16(0x0dcd + seg, 0x0000) + seg); // 3170 -> 335d; lin=dcd0
        memoryASet16(0x0dcd + seg, 0x0008, memoryAGet16(0x0dcd + seg, 0x0008) + seg); // 3170 -> 335d; lin=dcd8
        memoryASet16(0x0dcd + seg, 0x000c, memoryAGet16(0x0dcd + seg, 0x000c) + seg); // 3170 -> 335d; lin=dcdc
        memoryASet16(0x0dce + seg, 0x0000, memoryAGet16(0x0dce + seg, 0x0000) + seg); // 3170 -> 335d; lin=dce0
        memoryASet16(0x0dce + seg, 0x0004, memoryAGet16(0x0dce + seg, 0x0004) + seg); // 3170 -> 335d; lin=dce4
        memoryASet16(0x0dce + seg, 0x0008, memoryAGet16(0x0dce + seg, 0x0008) + seg); // 3170 -> 335d; lin=dce8
        memoryASet16(0x0dce + seg, 0x000c, memoryAGet16(0x0dce + seg, 0x000c) + seg); // 3170 -> 335d; lin=dcec
        memoryASet16(0x0dcf + seg, 0x0000, memoryAGet16(0x0dcf + seg, 0x0000) + seg); // 3170 -> 335d; lin=dcf0
        memoryASet16(0x0dcf + seg, 0x0006, memoryAGet16(0x0dcf + seg, 0x0006) + seg); // 3170 -> 335d; lin=dcf6
        memoryASet16(0x0dcf + seg, 0x000a, memoryAGet16(0x0dcf + seg, 0x000a) + seg); // 3170 -> 335d; lin=dcfa
        memoryASet16(0x0dcf + seg, 0x000e, memoryAGet16(0x0dcf + seg, 0x000e) + seg); // 3170 -> 335d; lin=dcfe
        memoryASet16(0x0dd0 + seg, 0x0002, memoryAGet16(0x0dd0 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd02
        memoryASet16(0x0dd0 + seg, 0x0006, memoryAGet16(0x0dd0 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dd06
        memoryASet16(0x0dd0 + seg, 0x000a, memoryAGet16(0x0dd0 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dd0a
        memoryASet16(0x0dd0 + seg, 0x000e, memoryAGet16(0x0dd0 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dd0e
        memoryASet16(0x0dd1 + seg, 0x0002, memoryAGet16(0x0dd1 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd12
        memoryASet16(0x0dd1 + seg, 0x0006, memoryAGet16(0x0dd1 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dd16
        memoryASet16(0x0dd1 + seg, 0x000a, memoryAGet16(0x0dd1 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dd1a
        memoryASet16(0x0dd1 + seg, 0x000e, memoryAGet16(0x0dd1 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dd1e
        memoryASet16(0x0dd2 + seg, 0x0002, memoryAGet16(0x0dd2 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd22
        memoryASet16(0x0dd2 + seg, 0x0006, memoryAGet16(0x0dd2 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dd26
        memoryASet16(0x0dd2 + seg, 0x000a, memoryAGet16(0x0dd2 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dd2a
        memoryASet16(0x0dd2 + seg, 0x000e, memoryAGet16(0x0dd2 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dd2e
        memoryASet16(0x0dd3 + seg, 0x0002, memoryAGet16(0x0dd3 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd32
        memoryASet16(0x0dd3 + seg, 0x000a, memoryAGet16(0x0dd3 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dd3a
        memoryASet16(0x0dd3 + seg, 0x000e, memoryAGet16(0x0dd3 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dd3e
        memoryASet16(0x0dd4 + seg, 0x0002, memoryAGet16(0x0dd4 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd42
        memoryASet16(0x0dd4 + seg, 0x0006, memoryAGet16(0x0dd4 + seg, 0x0006) + seg); // 3170 -> 335d; lin=dd46
        memoryASet16(0x0dd4 + seg, 0x000a, memoryAGet16(0x0dd4 + seg, 0x000a) + seg); // 3170 -> 335d; lin=dd4a
        memoryASet16(0x0dd4 + seg, 0x000e, memoryAGet16(0x0dd4 + seg, 0x000e) + seg); // 3170 -> 335d; lin=dd4e
        memoryASet16(0x0dd5 + seg, 0x0002, memoryAGet16(0x0dd5 + seg, 0x0002) + seg); // 3170 -> 335d; lin=dd52
        memoryASet16(0x0dd5 + seg, 0x0008, memoryAGet16(0x0dd5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dd58
        memoryASet16(0x0dd5 + seg, 0x000c, memoryAGet16(0x0dd5 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dd5c
        memoryASet16(0x0dd6 + seg, 0x0000, memoryAGet16(0x0dd6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dd60
        memoryASet16(0x0dd6 + seg, 0x0004, memoryAGet16(0x0dd6 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dd64
        memoryASet16(0x0dd6 + seg, 0x0008, memoryAGet16(0x0dd6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dd68
        memoryASet16(0x0dd6 + seg, 0x000c, memoryAGet16(0x0dd6 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dd6c
        memoryASet16(0x0dd7 + seg, 0x0000, memoryAGet16(0x0dd7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dd70
        memoryASet16(0x0dd7 + seg, 0x0004, memoryAGet16(0x0dd7 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dd74
        memoryASet16(0x0dd7 + seg, 0x0008, memoryAGet16(0x0dd7 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dd78
        memoryASet16(0x0dd7 + seg, 0x000c, memoryAGet16(0x0dd7 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dd7c
        memoryASet16(0x0dd8 + seg, 0x0000, memoryAGet16(0x0dd8 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dd80
        memoryASet16(0x0dd8 + seg, 0x0004, memoryAGet16(0x0dd8 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dd84
        memoryASet16(0x0dd8 + seg, 0x0008, memoryAGet16(0x0dd8 + seg, 0x0008) + seg); // 3170 -> 335d; lin=dd88
        memoryASet16(0x0dd8 + seg, 0x000c, memoryAGet16(0x0dd8 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dd8c
        memoryASet16(0x0dd9 + seg, 0x0000, memoryAGet16(0x0dd9 + seg, 0x0000) + seg); // 3170 -> 335d; lin=dd90
        memoryASet16(0x0dd9 + seg, 0x0004, memoryAGet16(0x0dd9 + seg, 0x0004) + seg); // 3170 -> 335d; lin=dd94
        memoryASet16(0x0dd9 + seg, 0x000c, memoryAGet16(0x0dd9 + seg, 0x000c) + seg); // 3170 -> 335d; lin=dd9c
        memoryASet16(0x0dda + seg, 0x0000, memoryAGet16(0x0dda + seg, 0x0000) + seg); // 3170 -> 335d; lin=dda0
        memoryASet16(0x0dda + seg, 0x0004, memoryAGet16(0x0dda + seg, 0x0004) + seg); // 3170 -> 335d; lin=dda4
        memoryASet16(0x0dda + seg, 0x0008, memoryAGet16(0x0dda + seg, 0x0008) + seg); // 3170 -> 335d; lin=dda8
        memoryASet16(0x0dda + seg, 0x000c, memoryAGet16(0x0dda + seg, 0x000c) + seg); // 3170 -> 335d; lin=ddac
        memoryASet16(0x0ddb + seg, 0x0002, memoryAGet16(0x0ddb + seg, 0x0002) + seg); // 3170 -> 335d; lin=ddb2
        memoryASet16(0x0ddb + seg, 0x0006, memoryAGet16(0x0ddb + seg, 0x0006) + seg); // 3170 -> 335d; lin=ddb6
        memoryASet16(0x0ddb + seg, 0x000a, memoryAGet16(0x0ddb + seg, 0x000a) + seg); // 3170 -> 335d; lin=ddba
        memoryASet16(0x0ddb + seg, 0x000e, memoryAGet16(0x0ddb + seg, 0x000e) + seg); // 3170 -> 335d; lin=ddbe
        memoryASet16(0x0ddc + seg, 0x0002, memoryAGet16(0x0ddc + seg, 0x0002) + seg); // 3170 -> 335d; lin=ddc2
        memoryASet16(0x0ddc + seg, 0x0006, memoryAGet16(0x0ddc + seg, 0x0006) + seg); // 3170 -> 335d; lin=ddc6
        memoryASet16(0x0ddc + seg, 0x000a, memoryAGet16(0x0ddc + seg, 0x000a) + seg); // 3170 -> 335d; lin=ddca
        memoryASet16(0x0ddc + seg, 0x000e, memoryAGet16(0x0ddc + seg, 0x000e) + seg); // 3170 -> 335d; lin=ddce
        memoryASet16(0x0ddd + seg, 0x0002, memoryAGet16(0x0ddd + seg, 0x0002) + seg); // 3170 -> 335d; lin=ddd2
        memoryASet16(0x0ddd + seg, 0x0006, memoryAGet16(0x0ddd + seg, 0x0006) + seg); // 3170 -> 335d; lin=ddd6
        memoryASet16(0x0ddd + seg, 0x000a, memoryAGet16(0x0ddd + seg, 0x000a) + seg); // 3170 -> 335d; lin=ddda
        memoryASet16(0x0ddd + seg, 0x000e, memoryAGet16(0x0ddd + seg, 0x000e) + seg); // 3170 -> 335d; lin=ddde
        memoryASet16(0x0dde + seg, 0x0002, memoryAGet16(0x0dde + seg, 0x0002) + seg); // 3170 -> 335d; lin=dde2
        memoryASet16(0x0dde + seg, 0x0006, memoryAGet16(0x0dde + seg, 0x0006) + seg); // 3170 -> 335d; lin=dde6
        memoryASet16(0x0dde + seg, 0x000a, memoryAGet16(0x0dde + seg, 0x000a) + seg); // 3170 -> 335d; lin=ddea
        memoryASet16(0x0dde + seg, 0x000e, memoryAGet16(0x0dde + seg, 0x000e) + seg); // 3170 -> 335d; lin=ddee
        memoryASet16(0x0ddf + seg, 0x0006, memoryAGet16(0x0ddf + seg, 0x0006) + seg); // 3170 -> 335d; lin=ddf6
        memoryASet16(0x0ddf + seg, 0x000a, memoryAGet16(0x0ddf + seg, 0x000a) + seg); // 3170 -> 335d; lin=ddfa
        memoryASet16(0x0ddf + seg, 0x000e, memoryAGet16(0x0ddf + seg, 0x000e) + seg); // 3170 -> 335d; lin=ddfe
        memoryASet16(0x0de0 + seg, 0x0002, memoryAGet16(0x0de0 + seg, 0x0002) + seg); // 3170 -> 335d; lin=de02
        memoryASet16(0x0de0 + seg, 0x0006, memoryAGet16(0x0de0 + seg, 0x0006) + seg); // 3170 -> 335d; lin=de06
        memoryASet16(0x0de0 + seg, 0x000c, memoryAGet16(0x0de0 + seg, 0x000c) + seg); // 3170 -> 335d; lin=de0c
        memoryASet16(0x0de1 + seg, 0x0000, memoryAGet16(0x0de1 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de10
        memoryASet16(0x0de1 + seg, 0x0004, memoryAGet16(0x0de1 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de14
        memoryASet16(0x0de1 + seg, 0x0008, memoryAGet16(0x0de1 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de18
        memoryASet16(0x0de1 + seg, 0x000c, memoryAGet16(0x0de1 + seg, 0x000c) + seg); // 3170 -> 335d; lin=de1c
        memoryASet16(0x0de2 + seg, 0x0000, memoryAGet16(0x0de2 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de20
        memoryASet16(0x0de2 + seg, 0x0004, memoryAGet16(0x0de2 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de24
        memoryASet16(0x0de2 + seg, 0x0008, memoryAGet16(0x0de2 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de28
        memoryASet16(0x0de2 + seg, 0x000c, memoryAGet16(0x0de2 + seg, 0x000c) + seg); // 3170 -> 335d; lin=de2c
        memoryASet16(0x0de3 + seg, 0x0000, memoryAGet16(0x0de3 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de30
        memoryASet16(0x0de3 + seg, 0x0004, memoryAGet16(0x0de3 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de34
        memoryASet16(0x0de3 + seg, 0x0008, memoryAGet16(0x0de3 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de38
        memoryASet16(0x0de3 + seg, 0x000c, memoryAGet16(0x0de3 + seg, 0x000c) + seg); // 3170 -> 335d; lin=de3c
        memoryASet16(0x0de4 + seg, 0x0000, memoryAGet16(0x0de4 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de40
        memoryASet16(0x0de4 + seg, 0x0004, memoryAGet16(0x0de4 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de44
        memoryASet16(0x0de4 + seg, 0x0008, memoryAGet16(0x0de4 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de48
        memoryASet16(0x0de5 + seg, 0x0000, memoryAGet16(0x0de5 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de50
        memoryASet16(0x0de5 + seg, 0x0004, memoryAGet16(0x0de5 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de54
        memoryASet16(0x0de5 + seg, 0x0008, memoryAGet16(0x0de5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de58
        memoryASet16(0x0de5 + seg, 0x000c, memoryAGet16(0x0de5 + seg, 0x000c) + seg); // 3170 -> 335d; lin=de5c
        memoryASet16(0x0de6 + seg, 0x0000, memoryAGet16(0x0de6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=de60
        memoryASet16(0x0de6 + seg, 0x0004, memoryAGet16(0x0de6 + seg, 0x0004) + seg); // 3170 -> 335d; lin=de64
        memoryASet16(0x0de6 + seg, 0x0008, memoryAGet16(0x0de6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=de68
        memoryASet16(0x0de6 + seg, 0x000e, memoryAGet16(0x0de6 + seg, 0x000e) + seg); // 3170 -> 335d; lin=de6e
        memoryASet16(0x0de7 + seg, 0x0002, memoryAGet16(0x0de7 + seg, 0x0002) + seg); // 3170 -> 335d; lin=de72
        memoryASet16(0x0de7 + seg, 0x0006, memoryAGet16(0x0de7 + seg, 0x0006) + seg); // 3170 -> 335d; lin=de76
        memoryASet16(0x0de7 + seg, 0x000a, memoryAGet16(0x0de7 + seg, 0x000a) + seg); // 3170 -> 335d; lin=de7a
        memoryASet16(0x0de7 + seg, 0x000e, memoryAGet16(0x0de7 + seg, 0x000e) + seg); // 3170 -> 335d; lin=de7e
        memoryASet16(0x0de8 + seg, 0x0002, memoryAGet16(0x0de8 + seg, 0x0002) + seg); // 3170 -> 335d; lin=de82
        memoryASet16(0x0de8 + seg, 0x0006, memoryAGet16(0x0de8 + seg, 0x0006) + seg); // 3170 -> 335d; lin=de86
        memoryASet16(0x0de8 + seg, 0x000a, memoryAGet16(0x0de8 + seg, 0x000a) + seg); // 3170 -> 335d; lin=de8a
        memoryASet16(0x0de8 + seg, 0x000e, memoryAGet16(0x0de8 + seg, 0x000e) + seg); // 3170 -> 335d; lin=de8e
        memoryASet16(0x0de9 + seg, 0x0002, memoryAGet16(0x0de9 + seg, 0x0002) + seg); // 3170 -> 335d; lin=de92
        memoryASet16(0x0de9 + seg, 0x0006, memoryAGet16(0x0de9 + seg, 0x0006) + seg); // 3170 -> 335d; lin=de96
        memoryASet16(0x0de9 + seg, 0x000a, memoryAGet16(0x0de9 + seg, 0x000a) + seg); // 3170 -> 335d; lin=de9a
        memoryASet16(0x0de9 + seg, 0x000e, memoryAGet16(0x0de9 + seg, 0x000e) + seg); // 3170 -> 335d; lin=de9e
        memoryASet16(0x0dea + seg, 0x0002, memoryAGet16(0x0dea + seg, 0x0002) + seg); // 3170 -> 335d; lin=dea2
        memoryASet16(0x0dea + seg, 0x0006, memoryAGet16(0x0dea + seg, 0x0006) + seg); // 3170 -> 335d; lin=dea6
        memoryASet16(0x0dea + seg, 0x000a, memoryAGet16(0x0dea + seg, 0x000a) + seg); // 3170 -> 335d; lin=deaa
        memoryASet16(0x0deb + seg, 0x0002, memoryAGet16(0x0deb + seg, 0x0002) + seg); // 3170 -> 335d; lin=deb2
        memoryASet16(0x0deb + seg, 0x0006, memoryAGet16(0x0deb + seg, 0x0006) + seg); // 3170 -> 335d; lin=deb6
        memoryASet16(0x0deb + seg, 0x000a, memoryAGet16(0x0deb + seg, 0x000a) + seg); // 3170 -> 335d; lin=deba
        memoryASet16(0x0deb + seg, 0x000e, memoryAGet16(0x0deb + seg, 0x000e) + seg); // 3170 -> 335d; lin=debe
        memoryASet16(0x0dec + seg, 0x0002, memoryAGet16(0x0dec + seg, 0x0002) + seg); // 3170 -> 335d; lin=dec2
        memoryASet16(0x0dec + seg, 0x0008, memoryAGet16(0x0dec + seg, 0x0008) + seg); // 1463 -> 1650; lin=dec8
        memoryASet16(0x0dec + seg, 0x000c, memoryAGet16(0x0dec + seg, 0x000c) + seg); // 1463 -> 1650; lin=decc
        memoryASet16(0x0ded + seg, 0x0000, memoryAGet16(0x0ded + seg, 0x0000) + seg); // 1463 -> 1650; lin=ded0
        memoryASet16(0x0ded + seg, 0x0004, memoryAGet16(0x0ded + seg, 0x0004) + seg); // 1463 -> 1650; lin=ded4
        memoryASet16(0x0ded + seg, 0x0008, memoryAGet16(0x0ded + seg, 0x0008) + seg); // 1463 -> 1650; lin=ded8
        memoryASet16(0x0ded + seg, 0x000c, memoryAGet16(0x0ded + seg, 0x000c) + seg); // 1463 -> 1650; lin=dedc
        memoryASet16(0x0dee + seg, 0x0000, memoryAGet16(0x0dee + seg, 0x0000) + seg); // 1463 -> 1650; lin=dee0
        memoryASet16(0x0dee + seg, 0x0004, memoryAGet16(0x0dee + seg, 0x0004) + seg); // 1463 -> 1650; lin=dee4
        memoryASet16(0x0dee + seg, 0x0008, memoryAGet16(0x0dee + seg, 0x0008) + seg); // 1463 -> 1650; lin=dee8
        memoryASet16(0x0dee + seg, 0x000c, memoryAGet16(0x0dee + seg, 0x000c) + seg); // 1463 -> 1650; lin=deec
        memoryASet16(0x0def + seg, 0x0000, memoryAGet16(0x0def + seg, 0x0000) + seg); // 1463 -> 1650; lin=def0
        memoryASet16(0x0def + seg, 0x0004, memoryAGet16(0x0def + seg, 0x0004) + seg); // 1463 -> 1650; lin=def4
        memoryASet16(0x0def + seg, 0x0008, memoryAGet16(0x0def + seg, 0x0008) + seg); // 1463 -> 1650; lin=def8
        memoryASet16(0x0def + seg, 0x000c, memoryAGet16(0x0def + seg, 0x000c) + seg); // 1463 -> 1650; lin=defc
        memoryASet16(0x0df0 + seg, 0x0000, memoryAGet16(0x0df0 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df00
        memoryASet16(0x0df0 + seg, 0x0004, memoryAGet16(0x0df0 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df04
        memoryASet16(0x0df0 + seg, 0x0008, memoryAGet16(0x0df0 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df08
        memoryASet16(0x0df0 + seg, 0x000c, memoryAGet16(0x0df0 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df0c
        memoryASet16(0x0df1 + seg, 0x0000, memoryAGet16(0x0df1 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df10
        memoryASet16(0x0df1 + seg, 0x0004, memoryAGet16(0x0df1 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df14
        memoryASet16(0x0df1 + seg, 0x0008, memoryAGet16(0x0df1 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df18
        memoryASet16(0x0df1 + seg, 0x000c, memoryAGet16(0x0df1 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df1c
        memoryASet16(0x0df2 + seg, 0x0000, memoryAGet16(0x0df2 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df20
        memoryASet16(0x0df2 + seg, 0x0004, memoryAGet16(0x0df2 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df24
        memoryASet16(0x0df2 + seg, 0x0008, memoryAGet16(0x0df2 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df28
        memoryASet16(0x0df2 + seg, 0x000c, memoryAGet16(0x0df2 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df2c
        memoryASet16(0x0df3 + seg, 0x0000, memoryAGet16(0x0df3 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df30
        memoryASet16(0x0df3 + seg, 0x0004, memoryAGet16(0x0df3 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df34
        memoryASet16(0x0df3 + seg, 0x0008, memoryAGet16(0x0df3 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df38
        memoryASet16(0x0df3 + seg, 0x000c, memoryAGet16(0x0df3 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df3c
        memoryASet16(0x0df4 + seg, 0x0000, memoryAGet16(0x0df4 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df40
        memoryASet16(0x0df4 + seg, 0x0004, memoryAGet16(0x0df4 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df44
        memoryASet16(0x0df4 + seg, 0x0008, memoryAGet16(0x0df4 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df48
        memoryASet16(0x0df4 + seg, 0x000c, memoryAGet16(0x0df4 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df4c
        memoryASet16(0x0df5 + seg, 0x0000, memoryAGet16(0x0df5 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df50
        memoryASet16(0x0df5 + seg, 0x0004, memoryAGet16(0x0df5 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df54
        memoryASet16(0x0df5 + seg, 0x0008, memoryAGet16(0x0df5 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df58
        memoryASet16(0x0df5 + seg, 0x000c, memoryAGet16(0x0df5 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df5c
        memoryASet16(0x0df6 + seg, 0x0000, memoryAGet16(0x0df6 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df60
        memoryASet16(0x0df6 + seg, 0x0004, memoryAGet16(0x0df6 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df64
        memoryASet16(0x0df6 + seg, 0x0008, memoryAGet16(0x0df6 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df68
        memoryASet16(0x0df6 + seg, 0x000c, memoryAGet16(0x0df6 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df6c
        memoryASet16(0x0df7 + seg, 0x0000, memoryAGet16(0x0df7 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df70
        memoryASet16(0x0df7 + seg, 0x0004, memoryAGet16(0x0df7 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df74
        memoryASet16(0x0df7 + seg, 0x0008, memoryAGet16(0x0df7 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df78
        memoryASet16(0x0df7 + seg, 0x000c, memoryAGet16(0x0df7 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df7c
        memoryASet16(0x0df8 + seg, 0x0000, memoryAGet16(0x0df8 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df80
        memoryASet16(0x0df8 + seg, 0x0004, memoryAGet16(0x0df8 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df84
        memoryASet16(0x0df8 + seg, 0x0008, memoryAGet16(0x0df8 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df88
        memoryASet16(0x0df8 + seg, 0x000c, memoryAGet16(0x0df8 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df8c
        memoryASet16(0x0df9 + seg, 0x0000, memoryAGet16(0x0df9 + seg, 0x0000) + seg); // 1463 -> 1650; lin=df90
        memoryASet16(0x0df9 + seg, 0x0004, memoryAGet16(0x0df9 + seg, 0x0004) + seg); // 1463 -> 1650; lin=df94
        memoryASet16(0x0df9 + seg, 0x0008, memoryAGet16(0x0df9 + seg, 0x0008) + seg); // 1463 -> 1650; lin=df98
        memoryASet16(0x0df9 + seg, 0x000c, memoryAGet16(0x0df9 + seg, 0x000c) + seg); // 1463 -> 1650; lin=df9c
        memoryASet16(0x0dfa + seg, 0x0000, memoryAGet16(0x0dfa + seg, 0x0000) + seg); // 1463 -> 1650; lin=dfa0
        memoryASet16(0x0dfa + seg, 0x0004, memoryAGet16(0x0dfa + seg, 0x0004) + seg); // 1463 -> 1650; lin=dfa4
        memoryASet16(0x0dfa + seg, 0x0008, memoryAGet16(0x0dfa + seg, 0x0008) + seg); // 1463 -> 1650; lin=dfa8
        memoryASet16(0x0dfa + seg, 0x000c, memoryAGet16(0x0dfa + seg, 0x000c) + seg); // 1463 -> 1650; lin=dfac
        memoryASet16(0x0dfb + seg, 0x0000, memoryAGet16(0x0dfb + seg, 0x0000) + seg); // 1463 -> 1650; lin=dfb0
        memoryASet16(0x0dfb + seg, 0x0004, memoryAGet16(0x0dfb + seg, 0x0004) + seg); // 1463 -> 1650; lin=dfb4
        memoryASet16(0x0dfb + seg, 0x0008, memoryAGet16(0x0dfb + seg, 0x0008) + seg); // 1463 -> 1650; lin=dfb8
        memoryASet16(0x0dfb + seg, 0x000c, memoryAGet16(0x0dfb + seg, 0x000c) + seg); // 1463 -> 1650; lin=dfbc
        memoryASet16(0x0dfc + seg, 0x0000, memoryAGet16(0x0dfc + seg, 0x0000) + seg); // 1463 -> 1650; lin=dfc0
        memoryASet16(0x0dfc + seg, 0x0004, memoryAGet16(0x0dfc + seg, 0x0004) + seg); // 1463 -> 1650; lin=dfc4
        memoryASet16(0x0dfc + seg, 0x000c, memoryAGet16(0x0dfc + seg, 0x000c) + seg); // 1463 -> 1650; lin=dfcc
        memoryASet16(0x0dfd + seg, 0x0000, memoryAGet16(0x0dfd + seg, 0x0000) + seg); // 1463 -> 1650; lin=dfd0
        memoryASet16(0x0dfd + seg, 0x0004, memoryAGet16(0x0dfd + seg, 0x0004) + seg); // 1463 -> 1650; lin=dfd4
        memoryASet16(0x0dfd + seg, 0x0008, memoryAGet16(0x0dfd + seg, 0x0008) + seg); // 1463 -> 1650; lin=dfd8
        memoryASet16(0x0dfd + seg, 0x000c, memoryAGet16(0x0dfd + seg, 0x000c) + seg); // 1463 -> 1650; lin=dfdc
        memoryASet16(0x0dfe + seg, 0x0000, memoryAGet16(0x0dfe + seg, 0x0000) + seg); // 1463 -> 1650; lin=dfe0
        memoryASet16(0x0dfe + seg, 0x0004, memoryAGet16(0x0dfe + seg, 0x0004) + seg); // 1463 -> 1650; lin=dfe4
        memoryASet16(0x0dfe + seg, 0x000a, memoryAGet16(0x0dfe + seg, 0x000a) + seg); // 3170 -> 335d; lin=dfea
        memoryASet16(0x0dfe + seg, 0x000e, memoryAGet16(0x0dfe + seg, 0x000e) + seg); // 3170 -> 335d; lin=dfee
        memoryASet16(0x0dff + seg, 0x0002, memoryAGet16(0x0dff + seg, 0x0002) + seg); // 3170 -> 335d; lin=dff2
        memoryASet16(0x0dff + seg, 0x0006, memoryAGet16(0x0dff + seg, 0x0006) + seg); // 3170 -> 335d; lin=dff6
        memoryASet16(0x0dff + seg, 0x000a, memoryAGet16(0x0dff + seg, 0x000a) + seg); // 3170 -> 335d; lin=dffa
        memoryASet16(0x0dff + seg, 0x000e, memoryAGet16(0x0dff + seg, 0x000e) + seg); // 3170 -> 335d; lin=dffe
        memoryASet16(0x0e00 + seg, 0x0002, memoryAGet16(0x0e00 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e002
        memoryASet16(0x0e00 + seg, 0x0006, memoryAGet16(0x0e00 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e006
        memoryASet16(0x0e00 + seg, 0x000a, memoryAGet16(0x0e00 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e00a
        memoryASet16(0x0e00 + seg, 0x000e, memoryAGet16(0x0e00 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e00e
        memoryASet16(0x0e01 + seg, 0x0002, memoryAGet16(0x0e01 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e012
        memoryASet16(0x0e01 + seg, 0x0006, memoryAGet16(0x0e01 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e016
        memoryASet16(0x0e01 + seg, 0x000a, memoryAGet16(0x0e01 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e01a
        memoryASet16(0x0e01 + seg, 0x000e, memoryAGet16(0x0e01 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e01e
        memoryASet16(0x0e02 + seg, 0x0002, memoryAGet16(0x0e02 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e022
        memoryASet16(0x0e02 + seg, 0x0006, memoryAGet16(0x0e02 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e026
        memoryASet16(0x0e02 + seg, 0x000e, memoryAGet16(0x0e02 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e02e
        memoryASet16(0x0e03 + seg, 0x0002, memoryAGet16(0x0e03 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e032
        memoryASet16(0x0e03 + seg, 0x0006, memoryAGet16(0x0e03 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e036
        memoryASet16(0x0e03 + seg, 0x000a, memoryAGet16(0x0e03 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e03a
        memoryASet16(0x0e03 + seg, 0x000e, memoryAGet16(0x0e03 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e03e
        memoryASet16(0x0e04 + seg, 0x0002, memoryAGet16(0x0e04 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e042
        memoryASet16(0x0e04 + seg, 0x0006, memoryAGet16(0x0e04 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e046
        memoryASet16(0x0e04 + seg, 0x000c, memoryAGet16(0x0e04 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e04c
        memoryASet16(0x0e05 + seg, 0x0000, memoryAGet16(0x0e05 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e050
        memoryASet16(0x0e05 + seg, 0x0004, memoryAGet16(0x0e05 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e054
        memoryASet16(0x0e05 + seg, 0x0008, memoryAGet16(0x0e05 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e058
        memoryASet16(0x0e05 + seg, 0x000c, memoryAGet16(0x0e05 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e05c
        memoryASet16(0x0e06 + seg, 0x0000, memoryAGet16(0x0e06 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e060
        memoryASet16(0x0e06 + seg, 0x0004, memoryAGet16(0x0e06 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e064
        memoryASet16(0x0e06 + seg, 0x0008, memoryAGet16(0x0e06 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e068
        memoryASet16(0x0e06 + seg, 0x000c, memoryAGet16(0x0e06 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e06c
        memoryASet16(0x0e07 + seg, 0x0000, memoryAGet16(0x0e07 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e070
        memoryASet16(0x0e07 + seg, 0x0004, memoryAGet16(0x0e07 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e074
        memoryASet16(0x0e07 + seg, 0x0008, memoryAGet16(0x0e07 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e078
        memoryASet16(0x0e07 + seg, 0x000c, memoryAGet16(0x0e07 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e07c
        memoryASet16(0x0e08 + seg, 0x0000, memoryAGet16(0x0e08 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e080
        memoryASet16(0x0e08 + seg, 0x0004, memoryAGet16(0x0e08 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e084
        memoryASet16(0x0e08 + seg, 0x0008, memoryAGet16(0x0e08 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e088
        memoryASet16(0x0e09 + seg, 0x0000, memoryAGet16(0x0e09 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e090
        memoryASet16(0x0e09 + seg, 0x0004, memoryAGet16(0x0e09 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e094
        memoryASet16(0x0e09 + seg, 0x0008, memoryAGet16(0x0e09 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e098
        memoryASet16(0x0e09 + seg, 0x000c, memoryAGet16(0x0e09 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e09c
        memoryASet16(0x0e0a + seg, 0x0000, memoryAGet16(0x0e0a + seg, 0x0000) + seg); // 3170 -> 335d; lin=e0a0
        memoryASet16(0x0e0a + seg, 0x0004, memoryAGet16(0x0e0a + seg, 0x0004) + seg); // 3170 -> 335d; lin=e0a4
        memoryASet16(0x0e0a + seg, 0x0008, memoryAGet16(0x0e0a + seg, 0x0008) + seg); // 3170 -> 335d; lin=e0a8
        memoryASet16(0x0e0a + seg, 0x000e, memoryAGet16(0x0e0a + seg, 0x000e) + seg); // 3170 -> 335d; lin=e0ae
        memoryASet16(0x0e0b + seg, 0x0002, memoryAGet16(0x0e0b + seg, 0x0002) + seg); // 3170 -> 335d; lin=e0b2
        memoryASet16(0x0e0b + seg, 0x0006, memoryAGet16(0x0e0b + seg, 0x0006) + seg); // 3170 -> 335d; lin=e0b6
        memoryASet16(0x0e0b + seg, 0x000a, memoryAGet16(0x0e0b + seg, 0x000a) + seg); // 3170 -> 335d; lin=e0ba
        memoryASet16(0x0e0b + seg, 0x000e, memoryAGet16(0x0e0b + seg, 0x000e) + seg); // 3170 -> 335d; lin=e0be
        memoryASet16(0x0e0c + seg, 0x0002, memoryAGet16(0x0e0c + seg, 0x0002) + seg); // 3170 -> 335d; lin=e0c2
        memoryASet16(0x0e0c + seg, 0x0006, memoryAGet16(0x0e0c + seg, 0x0006) + seg); // 3170 -> 335d; lin=e0c6
        memoryASet16(0x0e0c + seg, 0x000a, memoryAGet16(0x0e0c + seg, 0x000a) + seg); // 3170 -> 335d; lin=e0ca
        memoryASet16(0x0e0c + seg, 0x000e, memoryAGet16(0x0e0c + seg, 0x000e) + seg); // 3170 -> 335d; lin=e0ce
        memoryASet16(0x0e0d + seg, 0x0002, memoryAGet16(0x0e0d + seg, 0x0002) + seg); // 3170 -> 335d; lin=e0d2
        memoryASet16(0x0e0d + seg, 0x0006, memoryAGet16(0x0e0d + seg, 0x0006) + seg); // 3170 -> 335d; lin=e0d6
        memoryASet16(0x0e0d + seg, 0x000a, memoryAGet16(0x0e0d + seg, 0x000a) + seg); // 3170 -> 335d; lin=e0da
        memoryASet16(0x0e0d + seg, 0x000e, memoryAGet16(0x0e0d + seg, 0x000e) + seg); // 3170 -> 335d; lin=e0de
        memoryASet16(0x0e0e + seg, 0x0002, memoryAGet16(0x0e0e + seg, 0x0002) + seg); // 3170 -> 335d; lin=e0e2
        memoryASet16(0x0e0e + seg, 0x0006, memoryAGet16(0x0e0e + seg, 0x0006) + seg); // 3170 -> 335d; lin=e0e6
        memoryASet16(0x0e0e + seg, 0x000a, memoryAGet16(0x0e0e + seg, 0x000a) + seg); // 3170 -> 335d; lin=e0ea
        memoryASet16(0x0e0f + seg, 0x0002, memoryAGet16(0x0e0f + seg, 0x0002) + seg); // 3170 -> 335d; lin=e0f2
        memoryASet16(0x0e0f + seg, 0x0006, memoryAGet16(0x0e0f + seg, 0x0006) + seg); // 3170 -> 335d; lin=e0f6
        memoryASet16(0x0e0f + seg, 0x000a, memoryAGet16(0x0e0f + seg, 0x000a) + seg); // 3170 -> 335d; lin=e0fa
        memoryASet16(0x0e0f + seg, 0x000e, memoryAGet16(0x0e0f + seg, 0x000e) + seg); // 3170 -> 335d; lin=e0fe
        memoryASet16(0x0e10 + seg, 0x0002, memoryAGet16(0x0e10 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e102
        memoryASet16(0x0e10 + seg, 0x0006, memoryAGet16(0x0e10 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e106
        memoryASet16(0x0e10 + seg, 0x000a, memoryAGet16(0x0e10 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e10a
        memoryASet16(0x0e11 + seg, 0x0000, memoryAGet16(0x0e11 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e110
        memoryASet16(0x0e11 + seg, 0x0004, memoryAGet16(0x0e11 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e114
        memoryASet16(0x0e11 + seg, 0x0008, memoryAGet16(0x0e11 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e118
        memoryASet16(0x0e11 + seg, 0x000c, memoryAGet16(0x0e11 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e11c
        memoryASet16(0x0e12 + seg, 0x0000, memoryAGet16(0x0e12 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e120
        memoryASet16(0x0e12 + seg, 0x0004, memoryAGet16(0x0e12 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e124
        memoryASet16(0x0e12 + seg, 0x0008, memoryAGet16(0x0e12 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e128
        memoryASet16(0x0e12 + seg, 0x000c, memoryAGet16(0x0e12 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e12c
        memoryASet16(0x0e13 + seg, 0x0000, memoryAGet16(0x0e13 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e130
        memoryASet16(0x0e13 + seg, 0x0004, memoryAGet16(0x0e13 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e134
        memoryASet16(0x0e13 + seg, 0x0008, memoryAGet16(0x0e13 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e138
        memoryASet16(0x0e13 + seg, 0x000c, memoryAGet16(0x0e13 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e13c
        memoryASet16(0x0e14 + seg, 0x0000, memoryAGet16(0x0e14 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e140
        memoryASet16(0x0e14 + seg, 0x0004, memoryAGet16(0x0e14 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e144
        memoryASet16(0x0e14 + seg, 0x0008, memoryAGet16(0x0e14 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e148
        memoryASet16(0x0e14 + seg, 0x000c, memoryAGet16(0x0e14 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e14c
        memoryASet16(0x0e15 + seg, 0x0004, memoryAGet16(0x0e15 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e154
        memoryASet16(0x0e15 + seg, 0x0008, memoryAGet16(0x0e15 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e158
        memoryASet16(0x0e15 + seg, 0x000c, memoryAGet16(0x0e15 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e15c
        memoryASet16(0x0e16 + seg, 0x0000, memoryAGet16(0x0e16 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e160
        memoryASet16(0x0e16 + seg, 0x0004, memoryAGet16(0x0e16 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e164
        memoryASet16(0x0e16 + seg, 0x0008, memoryAGet16(0x0e16 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e168
        memoryASet16(0x0e16 + seg, 0x000c, memoryAGet16(0x0e16 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e16c
        memoryASet16(0x0e17 + seg, 0x0002, memoryAGet16(0x0e17 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e172
        memoryASet16(0x0e17 + seg, 0x0006, memoryAGet16(0x0e17 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e176
        memoryASet16(0x0e17 + seg, 0x000a, memoryAGet16(0x0e17 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e17a
        memoryASet16(0x0e17 + seg, 0x000e, memoryAGet16(0x0e17 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e17e
        memoryASet16(0x0e18 + seg, 0x0002, memoryAGet16(0x0e18 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e182
        memoryASet16(0x0e18 + seg, 0x0006, memoryAGet16(0x0e18 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e186
        memoryASet16(0x0e18 + seg, 0x000a, memoryAGet16(0x0e18 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e18a
        memoryASet16(0x0e18 + seg, 0x000e, memoryAGet16(0x0e18 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e18e
        memoryASet16(0x0e19 + seg, 0x0002, memoryAGet16(0x0e19 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e192
        memoryASet16(0x0e19 + seg, 0x0006, memoryAGet16(0x0e19 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e196
        memoryASet16(0x0e19 + seg, 0x000a, memoryAGet16(0x0e19 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e19a
        memoryASet16(0x0e19 + seg, 0x000e, memoryAGet16(0x0e19 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e19e
        memoryASet16(0x0e1a + seg, 0x0002, memoryAGet16(0x0e1a + seg, 0x0002) + seg); // 3170 -> 335d; lin=e1a2
        memoryASet16(0x0e1a + seg, 0x0006, memoryAGet16(0x0e1a + seg, 0x0006) + seg); // 3170 -> 335d; lin=e1a6
        memoryASet16(0x0e1a + seg, 0x000a, memoryAGet16(0x0e1a + seg, 0x000a) + seg); // 3170 -> 335d; lin=e1aa
        memoryASet16(0x0e1a + seg, 0x000e, memoryAGet16(0x0e1a + seg, 0x000e) + seg); // 3170 -> 335d; lin=e1ae
        memoryASet16(0x0e1b + seg, 0x0006, memoryAGet16(0x0e1b + seg, 0x0006) + seg); // 3170 -> 335d; lin=e1b6
        memoryASet16(0x0e1b + seg, 0x000a, memoryAGet16(0x0e1b + seg, 0x000a) + seg); // 3170 -> 335d; lin=e1ba
        memoryASet16(0x0e1b + seg, 0x000e, memoryAGet16(0x0e1b + seg, 0x000e) + seg); // 3170 -> 335d; lin=e1be
        memoryASet16(0x0e1c + seg, 0x0002, memoryAGet16(0x0e1c + seg, 0x0002) + seg); // 3170 -> 335d; lin=e1c2
        memoryASet16(0x0e1c + seg, 0x0006, memoryAGet16(0x0e1c + seg, 0x0006) + seg); // 3170 -> 335d; lin=e1c6
        memoryASet16(0x0e1c + seg, 0x000a, memoryAGet16(0x0e1c + seg, 0x000a) + seg); // 3170 -> 335d; lin=e1ca
        memoryASet16(0x0e1c + seg, 0x000e, memoryAGet16(0x0e1c + seg, 0x000e) + seg); // 3170 -> 335d; lin=e1ce
        memoryASet16(0x0e1d + seg, 0x0004, memoryAGet16(0x0e1d + seg, 0x0004) + seg); // 3170 -> 335d; lin=e1d4
        memoryASet16(0x0e1d + seg, 0x0008, memoryAGet16(0x0e1d + seg, 0x0008) + seg); // 3170 -> 335d; lin=e1d8
        memoryASet16(0x0e1d + seg, 0x000c, memoryAGet16(0x0e1d + seg, 0x000c) + seg); // 3170 -> 335d; lin=e1dc
        memoryASet16(0x0e1e + seg, 0x0000, memoryAGet16(0x0e1e + seg, 0x0000) + seg); // 3170 -> 335d; lin=e1e0
        memoryASet16(0x0e1e + seg, 0x0004, memoryAGet16(0x0e1e + seg, 0x0004) + seg); // 3170 -> 335d; lin=e1e4
        memoryASet16(0x0e1e + seg, 0x0008, memoryAGet16(0x0e1e + seg, 0x0008) + seg); // 3170 -> 335d; lin=e1e8
        memoryASet16(0x0e1e + seg, 0x000c, memoryAGet16(0x0e1e + seg, 0x000c) + seg); // 3170 -> 335d; lin=e1ec
        memoryASet16(0x0e1f + seg, 0x0000, memoryAGet16(0x0e1f + seg, 0x0000) + seg); // 3170 -> 335d; lin=e1f0
        memoryASet16(0x0e1f + seg, 0x0004, memoryAGet16(0x0e1f + seg, 0x0004) + seg); // 3170 -> 335d; lin=e1f4
        memoryASet16(0x0e1f + seg, 0x0008, memoryAGet16(0x0e1f + seg, 0x0008) + seg); // 3170 -> 335d; lin=e1f8
        memoryASet16(0x0e1f + seg, 0x000c, memoryAGet16(0x0e1f + seg, 0x000c) + seg); // 3170 -> 335d; lin=e1fc
        memoryASet16(0x0e20 + seg, 0x0000, memoryAGet16(0x0e20 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e200
        memoryASet16(0x0e20 + seg, 0x0004, memoryAGet16(0x0e20 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e204
        memoryASet16(0x0e20 + seg, 0x0008, memoryAGet16(0x0e20 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e208
        memoryASet16(0x0e20 + seg, 0x000c, memoryAGet16(0x0e20 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e20c
        memoryASet16(0x0e21 + seg, 0x0000, memoryAGet16(0x0e21 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e210
        memoryASet16(0x0e21 + seg, 0x0008, memoryAGet16(0x0e21 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e218
        memoryASet16(0x0e21 + seg, 0x000c, memoryAGet16(0x0e21 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e21c
        memoryASet16(0x0e22 + seg, 0x0000, memoryAGet16(0x0e22 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e220
        memoryASet16(0x0e22 + seg, 0x0004, memoryAGet16(0x0e22 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e224
        memoryASet16(0x0e22 + seg, 0x0008, memoryAGet16(0x0e22 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e228
        memoryASet16(0x0e22 + seg, 0x000c, memoryAGet16(0x0e22 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e22c
        memoryASet16(0x0e23 + seg, 0x0000, memoryAGet16(0x0e23 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e230
        memoryASet16(0x0e23 + seg, 0x0006, memoryAGet16(0x0e23 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e236
        memoryASet16(0x0e23 + seg, 0x000a, memoryAGet16(0x0e23 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e23a
        memoryASet16(0x0e23 + seg, 0x000e, memoryAGet16(0x0e23 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e23e
        memoryASet16(0x0e24 + seg, 0x0002, memoryAGet16(0x0e24 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e242
        memoryASet16(0x0e24 + seg, 0x000a, memoryAGet16(0x0e24 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e24a
        memoryASet16(0x0e24 + seg, 0x000e, memoryAGet16(0x0e24 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e24e
        memoryASet16(0x0e25 + seg, 0x0002, memoryAGet16(0x0e25 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e252
        memoryASet16(0x0e25 + seg, 0x0006, memoryAGet16(0x0e25 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e256
        memoryASet16(0x0e25 + seg, 0x000a, memoryAGet16(0x0e25 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e25a
        memoryASet16(0x0e25 + seg, 0x000e, memoryAGet16(0x0e25 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e25e
        memoryASet16(0x0e26 + seg, 0x0002, memoryAGet16(0x0e26 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e262
        memoryASet16(0x0e26 + seg, 0x0008, memoryAGet16(0x0e26 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e268
        memoryASet16(0x0e26 + seg, 0x000c, memoryAGet16(0x0e26 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e26c
        memoryASet16(0x0e27 + seg, 0x0000, memoryAGet16(0x0e27 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e270
        memoryASet16(0x0e27 + seg, 0x0004, memoryAGet16(0x0e27 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e274
        memoryASet16(0x0e27 + seg, 0x0008, memoryAGet16(0x0e27 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e278
        memoryASet16(0x0e27 + seg, 0x000c, memoryAGet16(0x0e27 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e27c
        memoryASet16(0x0e28 + seg, 0x0000, memoryAGet16(0x0e28 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e280
        memoryASet16(0x0e28 + seg, 0x0004, memoryAGet16(0x0e28 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e284
        memoryASet16(0x0e28 + seg, 0x0008, memoryAGet16(0x0e28 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e288
        memoryASet16(0x0e28 + seg, 0x000c, memoryAGet16(0x0e28 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e28c
        memoryASet16(0x0e29 + seg, 0x0000, memoryAGet16(0x0e29 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e290
        memoryASet16(0x0e29 + seg, 0x0004, memoryAGet16(0x0e29 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e294
        memoryASet16(0x0e29 + seg, 0x0008, memoryAGet16(0x0e29 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e298
        memoryASet16(0x0e29 + seg, 0x000c, memoryAGet16(0x0e29 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e29c
        memoryASet16(0x0e2a + seg, 0x0000, memoryAGet16(0x0e2a + seg, 0x0000) + seg); // 3170 -> 335d; lin=e2a0
        memoryASet16(0x0e2a + seg, 0x0004, memoryAGet16(0x0e2a + seg, 0x0004) + seg); // 3170 -> 335d; lin=e2a4
        memoryASet16(0x0e2a + seg, 0x000c, memoryAGet16(0x0e2a + seg, 0x000c) + seg); // 3170 -> 335d; lin=e2ac
        memoryASet16(0x0e2b + seg, 0x0000, memoryAGet16(0x0e2b + seg, 0x0000) + seg); // 3170 -> 335d; lin=e2b0
        memoryASet16(0x0e2b + seg, 0x0004, memoryAGet16(0x0e2b + seg, 0x0004) + seg); // 3170 -> 335d; lin=e2b4
        memoryASet16(0x0e2b + seg, 0x0008, memoryAGet16(0x0e2b + seg, 0x0008) + seg); // 3170 -> 335d; lin=e2b8
        memoryASet16(0x0e2b + seg, 0x000c, memoryAGet16(0x0e2b + seg, 0x000c) + seg); // 3170 -> 335d; lin=e2bc
        memoryASet16(0x0e2c + seg, 0x0000, memoryAGet16(0x0e2c + seg, 0x0000) + seg); // 3170 -> 335d; lin=e2c0
        memoryASet16(0x0e2c + seg, 0x0004, memoryAGet16(0x0e2c + seg, 0x0004) + seg); // 3170 -> 335d; lin=e2c4
        memoryASet16(0x0e2c + seg, 0x000a, memoryAGet16(0x0e2c + seg, 0x000a) + seg); // 3170 -> 335d; lin=e2ca
        memoryASet16(0x0e2c + seg, 0x000e, memoryAGet16(0x0e2c + seg, 0x000e) + seg); // 3170 -> 335d; lin=e2ce
        memoryASet16(0x0e2d + seg, 0x0002, memoryAGet16(0x0e2d + seg, 0x0002) + seg); // 3170 -> 335d; lin=e2d2
        memoryASet16(0x0e2d + seg, 0x0006, memoryAGet16(0x0e2d + seg, 0x0006) + seg); // 3170 -> 335d; lin=e2d6
        memoryASet16(0x0e2d + seg, 0x000a, memoryAGet16(0x0e2d + seg, 0x000a) + seg); // 3170 -> 335d; lin=e2da
        memoryASet16(0x0e2d + seg, 0x000e, memoryAGet16(0x0e2d + seg, 0x000e) + seg); // 3170 -> 335d; lin=e2de
        memoryASet16(0x0e2e + seg, 0x0002, memoryAGet16(0x0e2e + seg, 0x0002) + seg); // 3170 -> 335d; lin=e2e2
        memoryASet16(0x0e2e + seg, 0x0006, memoryAGet16(0x0e2e + seg, 0x0006) + seg); // 3170 -> 335d; lin=e2e6
        memoryASet16(0x0e2e + seg, 0x000a, memoryAGet16(0x0e2e + seg, 0x000a) + seg); // 3170 -> 335d; lin=e2ea
        memoryASet16(0x0e2e + seg, 0x000e, memoryAGet16(0x0e2e + seg, 0x000e) + seg); // 3170 -> 335d; lin=e2ee
        memoryASet16(0x0e2f + seg, 0x0002, memoryAGet16(0x0e2f + seg, 0x0002) + seg); // 3170 -> 335d; lin=e2f2
        memoryASet16(0x0e2f + seg, 0x0006, memoryAGet16(0x0e2f + seg, 0x0006) + seg); // 3170 -> 335d; lin=e2f6
        memoryASet16(0x0e2f + seg, 0x000a, memoryAGet16(0x0e2f + seg, 0x000a) + seg); // 3170 -> 335d; lin=e2fa
        memoryASet16(0x0e2f + seg, 0x000e, memoryAGet16(0x0e2f + seg, 0x000e) + seg); // 3170 -> 335d; lin=e2fe
        memoryASet16(0x0e30 + seg, 0x0002, memoryAGet16(0x0e30 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e302
        memoryASet16(0x0e30 + seg, 0x0006, memoryAGet16(0x0e30 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e306
        memoryASet16(0x0e30 + seg, 0x000e, memoryAGet16(0x0e30 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e30e
        memoryASet16(0x0e31 + seg, 0x0002, memoryAGet16(0x0e31 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e312
        memoryASet16(0x0e31 + seg, 0x0006, memoryAGet16(0x0e31 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e316
        memoryASet16(0x0e31 + seg, 0x000a, memoryAGet16(0x0e31 + seg, 0x000a) + seg); // 3170 -> 335d; lin=e31a
        memoryASet16(0x0e31 + seg, 0x000e, memoryAGet16(0x0e31 + seg, 0x000e) + seg); // 3170 -> 335d; lin=e31e
        memoryASet16(0x0e32 + seg, 0x0002, memoryAGet16(0x0e32 + seg, 0x0002) + seg); // 3170 -> 335d; lin=e322
        memoryASet16(0x0e32 + seg, 0x0006, memoryAGet16(0x0e32 + seg, 0x0006) + seg); // 3170 -> 335d; lin=e326
        memoryASet16(0x0e32 + seg, 0x000c, memoryAGet16(0x0e32 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e32c
        memoryASet16(0x0e33 + seg, 0x0000, memoryAGet16(0x0e33 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e330
        memoryASet16(0x0e33 + seg, 0x0004, memoryAGet16(0x0e33 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e334
        memoryASet16(0x0e33 + seg, 0x0008, memoryAGet16(0x0e33 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e338
        memoryASet16(0x0e33 + seg, 0x000c, memoryAGet16(0x0e33 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e33c
        memoryASet16(0x0e34 + seg, 0x0000, memoryAGet16(0x0e34 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e340
        memoryASet16(0x0e34 + seg, 0x0004, memoryAGet16(0x0e34 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e344
        memoryASet16(0x0e34 + seg, 0x0008, memoryAGet16(0x0e34 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e348
        memoryASet16(0x0e34 + seg, 0x000c, memoryAGet16(0x0e34 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e34c
        memoryASet16(0x0e35 + seg, 0x0000, memoryAGet16(0x0e35 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e350
        memoryASet16(0x0e35 + seg, 0x0004, memoryAGet16(0x0e35 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e354
        memoryASet16(0x0e35 + seg, 0x0008, memoryAGet16(0x0e35 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e358
        memoryASet16(0x0e35 + seg, 0x000c, memoryAGet16(0x0e35 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e35c
        memoryASet16(0x0e36 + seg, 0x0000, memoryAGet16(0x0e36 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e360
        memoryASet16(0x0e36 + seg, 0x0004, memoryAGet16(0x0e36 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e364
        memoryASet16(0x0e36 + seg, 0x0008, memoryAGet16(0x0e36 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e368
        memoryASet16(0x0e37 + seg, 0x0000, memoryAGet16(0x0e37 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e370
        memoryASet16(0x0e37 + seg, 0x0004, memoryAGet16(0x0e37 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e374
        memoryASet16(0x0e37 + seg, 0x0008, memoryAGet16(0x0e37 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e378
        memoryASet16(0x0e37 + seg, 0x000c, memoryAGet16(0x0e37 + seg, 0x000c) + seg); // 3170 -> 335d; lin=e37c
        memoryASet16(0x0e38 + seg, 0x0000, memoryAGet16(0x0e38 + seg, 0x0000) + seg); // 3170 -> 335d; lin=e380
        memoryASet16(0x0e38 + seg, 0x0004, memoryAGet16(0x0e38 + seg, 0x0004) + seg); // 3170 -> 335d; lin=e384
        memoryASet16(0x0e38 + seg, 0x0008, memoryAGet16(0x0e38 + seg, 0x0008) + seg); // 3170 -> 335d; lin=e388
        memoryASet16(0x0e3b + seg, 0x000e, memoryAGet16(0x0e3b + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e3be
        memoryASet16(0x0e3c + seg, 0x0002, memoryAGet16(0x0e3c + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e3c2
        memoryASet16(0x0e3e + seg, 0x0002, memoryAGet16(0x0e3e + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e3e2
        memoryASet16(0x0e3e + seg, 0x0006, memoryAGet16(0x0e3e + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e3e6
        memoryASet16(0x0e40 + seg, 0x0006, memoryAGet16(0x0e40 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e406
        memoryASet16(0x0e40 + seg, 0x000a, memoryAGet16(0x0e40 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e40a
        memoryASet16(0x0e42 + seg, 0x000a, memoryAGet16(0x0e42 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e42a
        memoryASet16(0x0e42 + seg, 0x000e, memoryAGet16(0x0e42 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e42e
        memoryASet16(0x0e44 + seg, 0x000e, memoryAGet16(0x0e44 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e44e
        memoryASet16(0x0e45 + seg, 0x0002, memoryAGet16(0x0e45 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e452
        memoryASet16(0x0e47 + seg, 0x0002, memoryAGet16(0x0e47 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e472
        memoryASet16(0x0e47 + seg, 0x0006, memoryAGet16(0x0e47 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e476
        memoryASet16(0x0e49 + seg, 0x0006, memoryAGet16(0x0e49 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e496
        memoryASet16(0x0e49 + seg, 0x000a, memoryAGet16(0x0e49 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e49a
        memoryASet16(0x0e4b + seg, 0x000a, memoryAGet16(0x0e4b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e4ba
        memoryASet16(0x0e4b + seg, 0x000e, memoryAGet16(0x0e4b + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e4be
        memoryASet16(0x0e4d + seg, 0x000e, memoryAGet16(0x0e4d + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e4de
        memoryASet16(0x0e4e + seg, 0x0002, memoryAGet16(0x0e4e + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e4e2
        memoryASet16(0x0e50 + seg, 0x0002, memoryAGet16(0x0e50 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e502
        memoryASet16(0x0e50 + seg, 0x0006, memoryAGet16(0x0e50 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e506
        memoryASet16(0x0e52 + seg, 0x0006, memoryAGet16(0x0e52 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e526
        memoryASet16(0x0e52 + seg, 0x000a, memoryAGet16(0x0e52 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e52a
        memoryASet16(0x0e54 + seg, 0x000a, memoryAGet16(0x0e54 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e54a
        memoryASet16(0x0e54 + seg, 0x000e, memoryAGet16(0x0e54 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e54e
        memoryASet16(0x0e56 + seg, 0x000e, memoryAGet16(0x0e56 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=e56e
        memoryASet16(0x0e57 + seg, 0x0002, memoryAGet16(0x0e57 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e572
        memoryASet16(0x0e59 + seg, 0x0002, memoryAGet16(0x0e59 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=e592
        memoryASet16(0x0e59 + seg, 0x0006, memoryAGet16(0x0e59 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e596
        memoryASet16(0x0e5b + seg, 0x0006, memoryAGet16(0x0e5b + seg, 0x0006) + seg); // 2403 -> 25f0; lin=e5b6
        memoryASet16(0x0e5b + seg, 0x000a, memoryAGet16(0x0e5b + seg, 0x000a) + seg); // 2403 -> 25f0; lin=e5ba
        memoryASet16(0x0ed0 + seg, 0x0002, memoryAGet16(0x0ed0 + seg, 0x0002) + seg); // 3170 -> 335d; lin=ed02
        memoryASet16(0x0ed3 + seg, 0x0008, memoryAGet16(0x0ed3 + seg, 0x0008) + seg); // 1463 -> 1650; lin=ed38
        memoryASet16(0x0ed4 + seg, 0x000c, memoryAGet16(0x0ed4 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ed4c
        memoryASet16(0x0ed6 + seg, 0x0000, memoryAGet16(0x0ed6 + seg, 0x0000) + seg); // 4110 -> 42fd; lin=ed60
        memoryASet16(0x0ed7 + seg, 0x0004, memoryAGet16(0x0ed7 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ed74
        memoryASet16(0x0ed8 + seg, 0x0008, memoryAGet16(0x0ed8 + seg, 0x0008) + seg); // 4110 -> 42fd; lin=ed88
        memoryASet16(0x0ed9 + seg, 0x000c, memoryAGet16(0x0ed9 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ed9c
        memoryASet16(0x0edb + seg, 0x0000, memoryAGet16(0x0edb + seg, 0x0000) + seg); // 1463 -> 1650; lin=edb0
        memoryASet16(0x0edc + seg, 0x0004, memoryAGet16(0x0edc + seg, 0x0004) + seg); // 1463 -> 1650; lin=edc4
        memoryASet16(0x0edd + seg, 0x0008, memoryAGet16(0x0edd + seg, 0x0008) + seg); // 1463 -> 1650; lin=edd8
        memoryASet16(0x0ede + seg, 0x000b, memoryAGet16(0x0ede + seg, 0x000b) + seg); // 1463 -> 1650; lin=edeb
        memoryASet16(0x0edf + seg, 0x000e, memoryAGet16(0x0edf + seg, 0x000e) + seg); // 1463 -> 1650; lin=edfe
        memoryASet16(0x0ee1 + seg, 0x0001, memoryAGet16(0x0ee1 + seg, 0x0001) + seg); // 1463 -> 1650; lin=ee11
        memoryASet16(0x0ee2 + seg, 0x0004, memoryAGet16(0x0ee2 + seg, 0x0004) + seg); // 1463 -> 1650; lin=ee24
        memoryASet16(0x0ee3 + seg, 0x0007, memoryAGet16(0x0ee3 + seg, 0x0007) + seg); // 1463 -> 1650; lin=ee37
        memoryASet16(0x0ee4 + seg, 0x000a, memoryAGet16(0x0ee4 + seg, 0x000a) + seg); // 1463 -> 1650; lin=ee4a
        memoryASet16(0x0ee5 + seg, 0x000d, memoryAGet16(0x0ee5 + seg, 0x000d) + seg); // 3170 -> 335d; lin=ee5d
        memoryASet16(0x0ee7 + seg, 0x0000, memoryAGet16(0x0ee7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=ee70
        memoryASet16(0x0ee8 + seg, 0x0003, memoryAGet16(0x0ee8 + seg, 0x0003) + seg); // 3170 -> 335d; lin=ee83
        memoryASet16(0x0ee9 + seg, 0x0006, memoryAGet16(0x0ee9 + seg, 0x0006) + seg); // 1463 -> 1650; lin=ee96
        memoryASet16(0x0eea + seg, 0x0008, memoryAGet16(0x0eea + seg, 0x0008) + seg); // 3170 -> 335d; lin=eea8
        memoryASet16(0x0eeb + seg, 0x0002, memoryAGet16(0x0eeb + seg, 0x0002) + seg); // 3170 -> 335d; lin=eeb2
        memoryASet16(0x0eeb + seg, 0x000c, memoryAGet16(0x0eeb + seg, 0x000c) + seg); // 3170 -> 335d; lin=eebc
        memoryASet16(0x0eec + seg, 0x0004, memoryAGet16(0x0eec + seg, 0x0004) + seg); // 3170 -> 335d; lin=eec4
        memoryASet16(0x0eec + seg, 0x000c, memoryAGet16(0x0eec + seg, 0x000c) + seg); // 3170 -> 335d; lin=eecc
        memoryASet16(0x0eed + seg, 0x0004, memoryAGet16(0x0eed + seg, 0x0004) + seg); // 3170 -> 335d; lin=eed4
        memoryASet16(0x0eed + seg, 0x000c, memoryAGet16(0x0eed + seg, 0x000c) + seg); // 3170 -> 335d; lin=eedc
        memoryASet16(0x0eee + seg, 0x0004, memoryAGet16(0x0eee + seg, 0x0004) + seg); // 3170 -> 335d; lin=eee4
        memoryASet16(0x0eee + seg, 0x000c, memoryAGet16(0x0eee + seg, 0x000c) + seg); // 3170 -> 335d; lin=eeec
        memoryASet16(0x0eef + seg, 0x0004, memoryAGet16(0x0eef + seg, 0x0004) + seg); // 3170 -> 335d; lin=eef4
        memoryASet16(0x0eef + seg, 0x000c, memoryAGet16(0x0eef + seg, 0x000c) + seg); // 3170 -> 335d; lin=eefc
        memoryASet16(0x0ef0 + seg, 0x0004, memoryAGet16(0x0ef0 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef04
        memoryASet16(0x0ef0 + seg, 0x000c, memoryAGet16(0x0ef0 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef0c
        memoryASet16(0x0ef1 + seg, 0x0004, memoryAGet16(0x0ef1 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef14
        memoryASet16(0x0ef1 + seg, 0x000c, memoryAGet16(0x0ef1 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef1c
        memoryASet16(0x0ef2 + seg, 0x0004, memoryAGet16(0x0ef2 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef24
        memoryASet16(0x0ef2 + seg, 0x000c, memoryAGet16(0x0ef2 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef2c
        memoryASet16(0x0ef3 + seg, 0x0004, memoryAGet16(0x0ef3 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef34
        memoryASet16(0x0ef3 + seg, 0x000c, memoryAGet16(0x0ef3 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef3c
        memoryASet16(0x0ef4 + seg, 0x0004, memoryAGet16(0x0ef4 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef44
        memoryASet16(0x0ef4 + seg, 0x000c, memoryAGet16(0x0ef4 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef4c
        memoryASet16(0x0ef5 + seg, 0x0004, memoryAGet16(0x0ef5 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef54
        memoryASet16(0x0ef5 + seg, 0x000c, memoryAGet16(0x0ef5 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef5c
        memoryASet16(0x0ef6 + seg, 0x0004, memoryAGet16(0x0ef6 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef64
        memoryASet16(0x0ef6 + seg, 0x000c, memoryAGet16(0x0ef6 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef6c
        memoryASet16(0x0ef7 + seg, 0x0004, memoryAGet16(0x0ef7 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef74
        memoryASet16(0x0ef7 + seg, 0x000c, memoryAGet16(0x0ef7 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef7c
        memoryASet16(0x0ef8 + seg, 0x0004, memoryAGet16(0x0ef8 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef84
        memoryASet16(0x0ef8 + seg, 0x000c, memoryAGet16(0x0ef8 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef8c
        memoryASet16(0x0ef9 + seg, 0x0004, memoryAGet16(0x0ef9 + seg, 0x0004) + seg); // 3170 -> 335d; lin=ef94
        memoryASet16(0x0ef9 + seg, 0x000c, memoryAGet16(0x0ef9 + seg, 0x000c) + seg); // 3170 -> 335d; lin=ef9c
        memoryASet16(0x0efa + seg, 0x0004, memoryAGet16(0x0efa + seg, 0x0004) + seg); // 3170 -> 335d; lin=efa4
        memoryASet16(0x0efa + seg, 0x000c, memoryAGet16(0x0efa + seg, 0x000c) + seg); // 3170 -> 335d; lin=efac
        memoryASet16(0x0efb + seg, 0x0004, memoryAGet16(0x0efb + seg, 0x0004) + seg); // 3170 -> 335d; lin=efb4
        memoryASet16(0x0efb + seg, 0x000c, memoryAGet16(0x0efb + seg, 0x000c) + seg); // 3170 -> 335d; lin=efbc
        memoryASet16(0x0efc + seg, 0x0004, memoryAGet16(0x0efc + seg, 0x0004) + seg); // 3170 -> 335d; lin=efc4
        memoryASet16(0x0efc + seg, 0x000c, memoryAGet16(0x0efc + seg, 0x000c) + seg); // 3170 -> 335d; lin=efcc
        memoryASet16(0x0efd + seg, 0x0004, memoryAGet16(0x0efd + seg, 0x0004) + seg); // 3170 -> 335d; lin=efd4
        memoryASet16(0x0efd + seg, 0x000c, memoryAGet16(0x0efd + seg, 0x000c) + seg); // 3170 -> 335d; lin=efdc
        memoryASet16(0x0efe + seg, 0x0004, memoryAGet16(0x0efe + seg, 0x0004) + seg); // 3170 -> 335d; lin=efe4
        memoryASet16(0x0efe + seg, 0x000c, memoryAGet16(0x0efe + seg, 0x000c) + seg); // 3170 -> 335d; lin=efec
        memoryASet16(0x0eff + seg, 0x0004, memoryAGet16(0x0eff + seg, 0x0004) + seg); // 3170 -> 335d; lin=eff4
        memoryASet16(0x0eff + seg, 0x000e, memoryAGet16(0x0eff + seg, 0x000e) + seg); // 1463 -> 1650; lin=effe
        memoryASet16(0x0f00 + seg, 0x0006, memoryAGet16(0x0f00 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f006
        memoryASet16(0x0f00 + seg, 0x000e, memoryAGet16(0x0f00 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f00e
        memoryASet16(0x0f01 + seg, 0x0006, memoryAGet16(0x0f01 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f016
        memoryASet16(0x0f01 + seg, 0x000e, memoryAGet16(0x0f01 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f01e
        memoryASet16(0x0f02 + seg, 0x0006, memoryAGet16(0x0f02 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f026
        memoryASet16(0x0f02 + seg, 0x000e, memoryAGet16(0x0f02 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f02e
        memoryASet16(0x0f03 + seg, 0x0006, memoryAGet16(0x0f03 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f036
        memoryASet16(0x0f03 + seg, 0x000e, memoryAGet16(0x0f03 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f03e
        memoryASet16(0x0f04 + seg, 0x0006, memoryAGet16(0x0f04 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f046
        memoryASet16(0x0f04 + seg, 0x000e, memoryAGet16(0x0f04 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f04e
        memoryASet16(0x0f05 + seg, 0x0006, memoryAGet16(0x0f05 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f056
        memoryASet16(0x0f05 + seg, 0x000e, memoryAGet16(0x0f05 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f05e
        memoryASet16(0x0f06 + seg, 0x0006, memoryAGet16(0x0f06 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f066
        memoryASet16(0x0f06 + seg, 0x000e, memoryAGet16(0x0f06 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f06e
        memoryASet16(0x0f07 + seg, 0x0006, memoryAGet16(0x0f07 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f076
        memoryASet16(0x0f07 + seg, 0x000e, memoryAGet16(0x0f07 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f07e
        memoryASet16(0x0f08 + seg, 0x0006, memoryAGet16(0x0f08 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f086
        memoryASet16(0x0f08 + seg, 0x000e, memoryAGet16(0x0f08 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f08e
        memoryASet16(0x0f09 + seg, 0x0006, memoryAGet16(0x0f09 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f096
        memoryASet16(0x0f09 + seg, 0x000e, memoryAGet16(0x0f09 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f09e
        memoryASet16(0x0f0a + seg, 0x0006, memoryAGet16(0x0f0a + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0a6
        memoryASet16(0x0f0a + seg, 0x000e, memoryAGet16(0x0f0a + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0ae
        memoryASet16(0x0f0b + seg, 0x0006, memoryAGet16(0x0f0b + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0b6
        memoryASet16(0x0f0b + seg, 0x000e, memoryAGet16(0x0f0b + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0be
        memoryASet16(0x0f0c + seg, 0x0006, memoryAGet16(0x0f0c + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0c6
        memoryASet16(0x0f0c + seg, 0x000e, memoryAGet16(0x0f0c + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0ce
        memoryASet16(0x0f0d + seg, 0x0006, memoryAGet16(0x0f0d + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0d6
        memoryASet16(0x0f0d + seg, 0x000e, memoryAGet16(0x0f0d + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0de
        memoryASet16(0x0f0e + seg, 0x0006, memoryAGet16(0x0f0e + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0e6
        memoryASet16(0x0f0e + seg, 0x000e, memoryAGet16(0x0f0e + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0ee
        memoryASet16(0x0f0f + seg, 0x0006, memoryAGet16(0x0f0f + seg, 0x0006) + seg); // 1463 -> 1650; lin=f0f6
        memoryASet16(0x0f0f + seg, 0x000e, memoryAGet16(0x0f0f + seg, 0x000e) + seg); // 1463 -> 1650; lin=f0fe
        memoryASet16(0x0f10 + seg, 0x0006, memoryAGet16(0x0f10 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f106
        memoryASet16(0x0f10 + seg, 0x000e, memoryAGet16(0x0f10 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f10e
        memoryASet16(0x0f11 + seg, 0x0006, memoryAGet16(0x0f11 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f116
        memoryASet16(0x0f11 + seg, 0x000e, memoryAGet16(0x0f11 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f11e
        memoryASet16(0x0f12 + seg, 0x0006, memoryAGet16(0x0f12 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f126
        memoryASet16(0x0f12 + seg, 0x000e, memoryAGet16(0x0f12 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f12e
        memoryASet16(0x0f13 + seg, 0x0006, memoryAGet16(0x0f13 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f136
        memoryASet16(0x0f13 + seg, 0x000e, memoryAGet16(0x0f13 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f13e
        memoryASet16(0x0f14 + seg, 0x0006, memoryAGet16(0x0f14 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f146
        memoryASet16(0x0f14 + seg, 0x000e, memoryAGet16(0x0f14 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f14e
        memoryASet16(0x0f15 + seg, 0x0006, memoryAGet16(0x0f15 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f156
        memoryASet16(0x0f15 + seg, 0x000e, memoryAGet16(0x0f15 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f15e
        memoryASet16(0x0f16 + seg, 0x0006, memoryAGet16(0x0f16 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f166
        memoryASet16(0x0f16 + seg, 0x000e, memoryAGet16(0x0f16 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f16e
        memoryASet16(0x0f17 + seg, 0x0006, memoryAGet16(0x0f17 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f176
        memoryASet16(0x0f17 + seg, 0x000e, memoryAGet16(0x0f17 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f17e
        memoryASet16(0x0f18 + seg, 0x0006, memoryAGet16(0x0f18 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f186
        memoryASet16(0x0f18 + seg, 0x000e, memoryAGet16(0x0f18 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f18e
        memoryASet16(0x0f19 + seg, 0x0006, memoryAGet16(0x0f19 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f196
        memoryASet16(0x0f19 + seg, 0x000e, memoryAGet16(0x0f19 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f19e
        memoryASet16(0x0f1a + seg, 0x0006, memoryAGet16(0x0f1a + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1a6
        memoryASet16(0x0f1a + seg, 0x000e, memoryAGet16(0x0f1a + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1ae
        memoryASet16(0x0f1b + seg, 0x0006, memoryAGet16(0x0f1b + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1b6
        memoryASet16(0x0f1b + seg, 0x000e, memoryAGet16(0x0f1b + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1be
        memoryASet16(0x0f1c + seg, 0x0006, memoryAGet16(0x0f1c + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1c6
        memoryASet16(0x0f1c + seg, 0x000e, memoryAGet16(0x0f1c + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1ce
        memoryASet16(0x0f1d + seg, 0x0006, memoryAGet16(0x0f1d + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1d6
        memoryASet16(0x0f1d + seg, 0x000e, memoryAGet16(0x0f1d + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1de
        memoryASet16(0x0f1e + seg, 0x0006, memoryAGet16(0x0f1e + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1e6
        memoryASet16(0x0f1e + seg, 0x000e, memoryAGet16(0x0f1e + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1ee
        memoryASet16(0x0f1f + seg, 0x0006, memoryAGet16(0x0f1f + seg, 0x0006) + seg); // 1463 -> 1650; lin=f1f6
        memoryASet16(0x0f1f + seg, 0x000e, memoryAGet16(0x0f1f + seg, 0x000e) + seg); // 1463 -> 1650; lin=f1fe
        memoryASet16(0x0f20 + seg, 0x0006, memoryAGet16(0x0f20 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f206
        memoryASet16(0x0f20 + seg, 0x000e, memoryAGet16(0x0f20 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f20e
        memoryASet16(0x0f21 + seg, 0x0006, memoryAGet16(0x0f21 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f216
        memoryASet16(0x0f21 + seg, 0x000e, memoryAGet16(0x0f21 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f21e
        memoryASet16(0x0f22 + seg, 0x0006, memoryAGet16(0x0f22 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f226
        memoryASet16(0x0f22 + seg, 0x000e, memoryAGet16(0x0f22 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f22e
        memoryASet16(0x0f23 + seg, 0x0006, memoryAGet16(0x0f23 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f236
        memoryASet16(0x0f23 + seg, 0x000e, memoryAGet16(0x0f23 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f23e
        memoryASet16(0x0f24 + seg, 0x0006, memoryAGet16(0x0f24 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f246
        memoryASet16(0x0f24 + seg, 0x000e, memoryAGet16(0x0f24 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f24e
        memoryASet16(0x0f25 + seg, 0x0006, memoryAGet16(0x0f25 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f256
        memoryASet16(0x0f25 + seg, 0x000e, memoryAGet16(0x0f25 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f25e
        memoryASet16(0x0f26 + seg, 0x0006, memoryAGet16(0x0f26 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f266
        memoryASet16(0x0f26 + seg, 0x000e, memoryAGet16(0x0f26 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f26e
        memoryASet16(0x0f27 + seg, 0x0006, memoryAGet16(0x0f27 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f276
        memoryASet16(0x0f27 + seg, 0x000e, memoryAGet16(0x0f27 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f27e
        memoryASet16(0x0f28 + seg, 0x0006, memoryAGet16(0x0f28 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f286
        memoryASet16(0x0f28 + seg, 0x000e, memoryAGet16(0x0f28 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f28e
        memoryASet16(0x0f29 + seg, 0x0006, memoryAGet16(0x0f29 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f296
        memoryASet16(0x0f29 + seg, 0x000e, memoryAGet16(0x0f29 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f29e
        memoryASet16(0x0f2a + seg, 0x0006, memoryAGet16(0x0f2a + seg, 0x0006) + seg); // 1463 -> 1650; lin=f2a6
        memoryASet16(0x0f2a + seg, 0x000e, memoryAGet16(0x0f2a + seg, 0x000e) + seg); // 1463 -> 1650; lin=f2ae
        memoryASet16(0x0f2b + seg, 0x0006, memoryAGet16(0x0f2b + seg, 0x0006) + seg); // 1463 -> 1650; lin=f2b6
        memoryASet16(0x0f2b + seg, 0x000e, memoryAGet16(0x0f2b + seg, 0x000e) + seg); // 1463 -> 1650; lin=f2be
        memoryASet16(0x0f2c + seg, 0x0006, memoryAGet16(0x0f2c + seg, 0x0006) + seg); // 1463 -> 1650; lin=f2c6
        memoryASet16(0x0f2c + seg, 0x000e, memoryAGet16(0x0f2c + seg, 0x000e) + seg); // 1463 -> 1650; lin=f2ce
        memoryASet16(0x0f2d + seg, 0x0006, memoryAGet16(0x0f2d + seg, 0x0006) + seg); // 1463 -> 1650; lin=f2d6
        memoryASet16(0x0f2d + seg, 0x000e, memoryAGet16(0x0f2d + seg, 0x000e) + seg); // 1463 -> 1650; lin=f2de
        memoryASet16(0x0f2e + seg, 0x0006, memoryAGet16(0x0f2e + seg, 0x0006) + seg); // 1463 -> 1650; lin=f2e6
        memoryASet16(0x0f2e + seg, 0x000e, memoryAGet16(0x0f2e + seg, 0x000e) + seg); // 1463 -> 1650; lin=f2ee
        memoryASet16(0x0f2f + seg, 0x0008, memoryAGet16(0x0f2f + seg, 0x0008) + seg); // 1463 -> 1650; lin=f2f8
        memoryASet16(0x0f30 + seg, 0x0000, memoryAGet16(0x0f30 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f300
        memoryASet16(0x0f30 + seg, 0x0008, memoryAGet16(0x0f30 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f308
        memoryASet16(0x0f31 + seg, 0x0000, memoryAGet16(0x0f31 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f310
        memoryASet16(0x0f31 + seg, 0x0008, memoryAGet16(0x0f31 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f318
        memoryASet16(0x0f32 + seg, 0x0000, memoryAGet16(0x0f32 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f320
        memoryASet16(0x0f32 + seg, 0x0008, memoryAGet16(0x0f32 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f328
        memoryASet16(0x0f33 + seg, 0x0000, memoryAGet16(0x0f33 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f330
        memoryASet16(0x0f33 + seg, 0x0008, memoryAGet16(0x0f33 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f338
        memoryASet16(0x0f34 + seg, 0x0000, memoryAGet16(0x0f34 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f340
        memoryASet16(0x0f34 + seg, 0x0008, memoryAGet16(0x0f34 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f348
        memoryASet16(0x0f35 + seg, 0x0000, memoryAGet16(0x0f35 + seg, 0x0000) + seg); // 1463 -> 1650; lin=f350
        memoryASet16(0x0f35 + seg, 0x0008, memoryAGet16(0x0f35 + seg, 0x0008) + seg); // 1463 -> 1650; lin=f358
        memoryASet16(0x0f36 + seg, 0x0002, memoryAGet16(0x0f36 + seg, 0x0002) + seg); // 1463 -> 1650; lin=f362
        memoryASet16(0x0f36 + seg, 0x000a, memoryAGet16(0x0f36 + seg, 0x000a) + seg); // 1463 -> 1650; lin=f36a
        memoryASet16(0x0f37 + seg, 0x0002, memoryAGet16(0x0f37 + seg, 0x0002) + seg); // 1463 -> 1650; lin=f372
        memoryASet16(0x0f37 + seg, 0x000a, memoryAGet16(0x0f37 + seg, 0x000a) + seg); // 1463 -> 1650; lin=f37a
        memoryASet16(0x0f38 + seg, 0x0002, memoryAGet16(0x0f38 + seg, 0x0002) + seg); // 1463 -> 1650; lin=f382
        memoryASet16(0x0f38 + seg, 0x000a, memoryAGet16(0x0f38 + seg, 0x000a) + seg); // 1463 -> 1650; lin=f38a
        memoryASet16(0x0f39 + seg, 0x0002, memoryAGet16(0x0f39 + seg, 0x0002) + seg); // 1463 -> 1650; lin=f392
        memoryASet16(0x0f39 + seg, 0x000a, memoryAGet16(0x0f39 + seg, 0x000a) + seg); // 1463 -> 1650; lin=f39a
        memoryASet16(0x0f3a + seg, 0x0002, memoryAGet16(0x0f3a + seg, 0x0002) + seg); // 1463 -> 1650; lin=f3a2
        memoryASet16(0x0f3a + seg, 0x000a, memoryAGet16(0x0f3a + seg, 0x000a) + seg); // 1463 -> 1650; lin=f3aa
        memoryASet16(0x0f3b + seg, 0x0004, memoryAGet16(0x0f3b + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f3b4
        memoryASet16(0x0f3b + seg, 0x000c, memoryAGet16(0x0f3b + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f3bc
        memoryASet16(0x0f3c + seg, 0x0004, memoryAGet16(0x0f3c + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f3c4
        memoryASet16(0x0f3c + seg, 0x000c, memoryAGet16(0x0f3c + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f3cc
        memoryASet16(0x0f3d + seg, 0x0004, memoryAGet16(0x0f3d + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f3d4
        memoryASet16(0x0f3d + seg, 0x000c, memoryAGet16(0x0f3d + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f3dc
        memoryASet16(0x0f3e + seg, 0x0004, memoryAGet16(0x0f3e + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f3e4
        memoryASet16(0x0f3e + seg, 0x000c, memoryAGet16(0x0f3e + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f3ec
        memoryASet16(0x0f3f + seg, 0x0004, memoryAGet16(0x0f3f + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f3f4
        memoryASet16(0x0f3f + seg, 0x000c, memoryAGet16(0x0f3f + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f3fc
        memoryASet16(0x0f40 + seg, 0x0004, memoryAGet16(0x0f40 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f404
        memoryASet16(0x0f40 + seg, 0x000c, memoryAGet16(0x0f40 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f40c
        memoryASet16(0x0f41 + seg, 0x0004, memoryAGet16(0x0f41 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f414
        memoryASet16(0x0f41 + seg, 0x000c, memoryAGet16(0x0f41 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f41c
        memoryASet16(0x0f42 + seg, 0x0004, memoryAGet16(0x0f42 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f424
        memoryASet16(0x0f42 + seg, 0x000c, memoryAGet16(0x0f42 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f42c
        memoryASet16(0x0f43 + seg, 0x0004, memoryAGet16(0x0f43 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f434
        memoryASet16(0x0f43 + seg, 0x000c, memoryAGet16(0x0f43 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f43c
        memoryASet16(0x0f44 + seg, 0x0004, memoryAGet16(0x0f44 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f444
        memoryASet16(0x0f44 + seg, 0x000c, memoryAGet16(0x0f44 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f44c
        memoryASet16(0x0f45 + seg, 0x0004, memoryAGet16(0x0f45 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f454
        memoryASet16(0x0f45 + seg, 0x000c, memoryAGet16(0x0f45 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f45c
        memoryASet16(0x0f46 + seg, 0x0004, memoryAGet16(0x0f46 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f464
        memoryASet16(0x0f46 + seg, 0x000c, memoryAGet16(0x0f46 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f46c
        memoryASet16(0x0f47 + seg, 0x0004, memoryAGet16(0x0f47 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f474
        memoryASet16(0x0f47 + seg, 0x000c, memoryAGet16(0x0f47 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f47c
        memoryASet16(0x0f48 + seg, 0x0004, memoryAGet16(0x0f48 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f484
        memoryASet16(0x0f48 + seg, 0x000c, memoryAGet16(0x0f48 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f48c
        memoryASet16(0x0f49 + seg, 0x0004, memoryAGet16(0x0f49 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f494
        memoryASet16(0x0f49 + seg, 0x000c, memoryAGet16(0x0f49 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f49c
        memoryASet16(0x0f4a + seg, 0x0004, memoryAGet16(0x0f4a + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4a4
        memoryASet16(0x0f4a + seg, 0x000c, memoryAGet16(0x0f4a + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4ac
        memoryASet16(0x0f4b + seg, 0x0004, memoryAGet16(0x0f4b + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4b4
        memoryASet16(0x0f4b + seg, 0x000c, memoryAGet16(0x0f4b + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4bc
        memoryASet16(0x0f4c + seg, 0x0004, memoryAGet16(0x0f4c + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4c4
        memoryASet16(0x0f4c + seg, 0x000c, memoryAGet16(0x0f4c + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4cc
        memoryASet16(0x0f4d + seg, 0x0004, memoryAGet16(0x0f4d + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4d4
        memoryASet16(0x0f4d + seg, 0x000c, memoryAGet16(0x0f4d + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4dc
        memoryASet16(0x0f4e + seg, 0x0004, memoryAGet16(0x0f4e + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4e4
        memoryASet16(0x0f4e + seg, 0x000c, memoryAGet16(0x0f4e + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4ec
        memoryASet16(0x0f4f + seg, 0x0004, memoryAGet16(0x0f4f + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f4f4
        memoryASet16(0x0f4f + seg, 0x000c, memoryAGet16(0x0f4f + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f4fc
        memoryASet16(0x0f50 + seg, 0x0004, memoryAGet16(0x0f50 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f504
        memoryASet16(0x0f50 + seg, 0x000c, memoryAGet16(0x0f50 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f50c
        memoryASet16(0x0f51 + seg, 0x0004, memoryAGet16(0x0f51 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f514
        memoryASet16(0x0f51 + seg, 0x000c, memoryAGet16(0x0f51 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f51c
        memoryASet16(0x0f52 + seg, 0x0004, memoryAGet16(0x0f52 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f524
        memoryASet16(0x0f52 + seg, 0x000c, memoryAGet16(0x0f52 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f52c
        memoryASet16(0x0f53 + seg, 0x0004, memoryAGet16(0x0f53 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f534
        memoryASet16(0x0f53 + seg, 0x000c, memoryAGet16(0x0f53 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f53c
        memoryASet16(0x0f54 + seg, 0x0004, memoryAGet16(0x0f54 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f544
        memoryASet16(0x0f54 + seg, 0x000c, memoryAGet16(0x0f54 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f54c
        memoryASet16(0x0f55 + seg, 0x0004, memoryAGet16(0x0f55 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f554
        memoryASet16(0x0f55 + seg, 0x000c, memoryAGet16(0x0f55 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f55c
        memoryASet16(0x0f56 + seg, 0x0004, memoryAGet16(0x0f56 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f564
        memoryASet16(0x0f56 + seg, 0x000c, memoryAGet16(0x0f56 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f56c
        memoryASet16(0x0f57 + seg, 0x0004, memoryAGet16(0x0f57 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f574
        memoryASet16(0x0f57 + seg, 0x000c, memoryAGet16(0x0f57 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f57c
        memoryASet16(0x0f58 + seg, 0x0004, memoryAGet16(0x0f58 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f584
        memoryASet16(0x0f58 + seg, 0x000c, memoryAGet16(0x0f58 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f58c
        memoryASet16(0x0f59 + seg, 0x0004, memoryAGet16(0x0f59 + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f594
        memoryASet16(0x0f59 + seg, 0x000c, memoryAGet16(0x0f59 + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f59c
        memoryASet16(0x0f5a + seg, 0x0004, memoryAGet16(0x0f5a + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5a4
        memoryASet16(0x0f5a + seg, 0x000c, memoryAGet16(0x0f5a + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5ac
        memoryASet16(0x0f5b + seg, 0x0004, memoryAGet16(0x0f5b + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5b4
        memoryASet16(0x0f5b + seg, 0x000c, memoryAGet16(0x0f5b + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5bc
        memoryASet16(0x0f5c + seg, 0x0004, memoryAGet16(0x0f5c + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5c4
        memoryASet16(0x0f5c + seg, 0x000c, memoryAGet16(0x0f5c + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5cc
        memoryASet16(0x0f5d + seg, 0x0004, memoryAGet16(0x0f5d + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5d4
        memoryASet16(0x0f5d + seg, 0x000c, memoryAGet16(0x0f5d + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5dc
        memoryASet16(0x0f5e + seg, 0x0004, memoryAGet16(0x0f5e + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5e4
        memoryASet16(0x0f5e + seg, 0x000c, memoryAGet16(0x0f5e + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5ec
        memoryASet16(0x0f5f + seg, 0x0004, memoryAGet16(0x0f5f + seg, 0x0004) + seg); // 4110 -> 42fd; lin=f5f4
        memoryASet16(0x0f5f + seg, 0x000c, memoryAGet16(0x0f5f + seg, 0x000c) + seg); // 4110 -> 42fd; lin=f5fc
        memoryASet16(0x0f60 + seg, 0x0006, memoryAGet16(0x0f60 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f606
        memoryASet16(0x0f60 + seg, 0x000e, memoryAGet16(0x0f60 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f60e
        memoryASet16(0x0f61 + seg, 0x0006, memoryAGet16(0x0f61 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f616
        memoryASet16(0x0f61 + seg, 0x000e, memoryAGet16(0x0f61 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f61e
        memoryASet16(0x0f62 + seg, 0x0006, memoryAGet16(0x0f62 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f626
        memoryASet16(0x0f62 + seg, 0x000e, memoryAGet16(0x0f62 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f62e
        memoryASet16(0x0f63 + seg, 0x0006, memoryAGet16(0x0f63 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f636
        memoryASet16(0x0f63 + seg, 0x000e, memoryAGet16(0x0f63 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f63e
        memoryASet16(0x0f64 + seg, 0x0006, memoryAGet16(0x0f64 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f646
        memoryASet16(0x0f64 + seg, 0x000e, memoryAGet16(0x0f64 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f64e
        memoryASet16(0x0f65 + seg, 0x0006, memoryAGet16(0x0f65 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f656
        memoryASet16(0x0f65 + seg, 0x000e, memoryAGet16(0x0f65 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f65e
        memoryASet16(0x0f66 + seg, 0x0006, memoryAGet16(0x0f66 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f666
        memoryASet16(0x0f66 + seg, 0x000e, memoryAGet16(0x0f66 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f66e
        memoryASet16(0x0f67 + seg, 0x0006, memoryAGet16(0x0f67 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f676
        memoryASet16(0x0f67 + seg, 0x000e, memoryAGet16(0x0f67 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f67e
        memoryASet16(0x0f68 + seg, 0x0006, memoryAGet16(0x0f68 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f686
        memoryASet16(0x0f68 + seg, 0x000e, memoryAGet16(0x0f68 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f68e
        memoryASet16(0x0f69 + seg, 0x0006, memoryAGet16(0x0f69 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f696
        memoryASet16(0x0f69 + seg, 0x000e, memoryAGet16(0x0f69 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f69e
        memoryASet16(0x0f6a + seg, 0x0006, memoryAGet16(0x0f6a + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6a6
        memoryASet16(0x0f6a + seg, 0x000e, memoryAGet16(0x0f6a + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6ae
        memoryASet16(0x0f6b + seg, 0x0006, memoryAGet16(0x0f6b + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6b6
        memoryASet16(0x0f6b + seg, 0x000e, memoryAGet16(0x0f6b + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6be
        memoryASet16(0x0f6c + seg, 0x0006, memoryAGet16(0x0f6c + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6c6
        memoryASet16(0x0f6c + seg, 0x000e, memoryAGet16(0x0f6c + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6ce
        memoryASet16(0x0f6d + seg, 0x0006, memoryAGet16(0x0f6d + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6d6
        memoryASet16(0x0f6d + seg, 0x000e, memoryAGet16(0x0f6d + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6de
        memoryASet16(0x0f6e + seg, 0x0006, memoryAGet16(0x0f6e + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6e6
        memoryASet16(0x0f6e + seg, 0x000e, memoryAGet16(0x0f6e + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6ee
        memoryASet16(0x0f6f + seg, 0x0006, memoryAGet16(0x0f6f + seg, 0x0006) + seg); // 1463 -> 1650; lin=f6f6
        memoryASet16(0x0f6f + seg, 0x000e, memoryAGet16(0x0f6f + seg, 0x000e) + seg); // 1463 -> 1650; lin=f6fe
        memoryASet16(0x0f70 + seg, 0x0006, memoryAGet16(0x0f70 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f706
        memoryASet16(0x0f70 + seg, 0x000e, memoryAGet16(0x0f70 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f70e
        memoryASet16(0x0f71 + seg, 0x0006, memoryAGet16(0x0f71 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f716
        memoryASet16(0x0f71 + seg, 0x000e, memoryAGet16(0x0f71 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f71e
        memoryASet16(0x0f72 + seg, 0x0006, memoryAGet16(0x0f72 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f726
        memoryASet16(0x0f72 + seg, 0x000e, memoryAGet16(0x0f72 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f72e
        memoryASet16(0x0f73 + seg, 0x0006, memoryAGet16(0x0f73 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f736
        memoryASet16(0x0f73 + seg, 0x000e, memoryAGet16(0x0f73 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f73e
        memoryASet16(0x0f74 + seg, 0x0006, memoryAGet16(0x0f74 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f746
        memoryASet16(0x0f74 + seg, 0x000e, memoryAGet16(0x0f74 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f74e
        memoryASet16(0x0f75 + seg, 0x0006, memoryAGet16(0x0f75 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f756
        memoryASet16(0x0f75 + seg, 0x000e, memoryAGet16(0x0f75 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f75e
        memoryASet16(0x0f76 + seg, 0x0006, memoryAGet16(0x0f76 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f766
        memoryASet16(0x0f76 + seg, 0x000e, memoryAGet16(0x0f76 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f76e
        memoryASet16(0x0f77 + seg, 0x0006, memoryAGet16(0x0f77 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f776
        memoryASet16(0x0f77 + seg, 0x000e, memoryAGet16(0x0f77 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f77e
        memoryASet16(0x0f78 + seg, 0x0006, memoryAGet16(0x0f78 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f786
        memoryASet16(0x0f78 + seg, 0x000e, memoryAGet16(0x0f78 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f78e
        memoryASet16(0x0f79 + seg, 0x0006, memoryAGet16(0x0f79 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f796
        memoryASet16(0x0f79 + seg, 0x000e, memoryAGet16(0x0f79 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f79e
        memoryASet16(0x0f7a + seg, 0x0006, memoryAGet16(0x0f7a + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7a6
        memoryASet16(0x0f7a + seg, 0x000e, memoryAGet16(0x0f7a + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7ae
        memoryASet16(0x0f7b + seg, 0x0006, memoryAGet16(0x0f7b + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7b6
        memoryASet16(0x0f7b + seg, 0x000e, memoryAGet16(0x0f7b + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7be
        memoryASet16(0x0f7c + seg, 0x0006, memoryAGet16(0x0f7c + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7c6
        memoryASet16(0x0f7c + seg, 0x000e, memoryAGet16(0x0f7c + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7ce
        memoryASet16(0x0f7d + seg, 0x0006, memoryAGet16(0x0f7d + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7d6
        memoryASet16(0x0f7d + seg, 0x000e, memoryAGet16(0x0f7d + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7de
        memoryASet16(0x0f7e + seg, 0x0006, memoryAGet16(0x0f7e + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7e6
        memoryASet16(0x0f7e + seg, 0x000e, memoryAGet16(0x0f7e + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7ee
        memoryASet16(0x0f7f + seg, 0x0006, memoryAGet16(0x0f7f + seg, 0x0006) + seg); // 1463 -> 1650; lin=f7f6
        memoryASet16(0x0f7f + seg, 0x000e, memoryAGet16(0x0f7f + seg, 0x000e) + seg); // 1463 -> 1650; lin=f7fe
        memoryASet16(0x0f80 + seg, 0x0006, memoryAGet16(0x0f80 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f806
        memoryASet16(0x0f80 + seg, 0x000e, memoryAGet16(0x0f80 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f80e
        memoryASet16(0x0f81 + seg, 0x0006, memoryAGet16(0x0f81 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f816
        memoryASet16(0x0f81 + seg, 0x000e, memoryAGet16(0x0f81 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f81e
        memoryASet16(0x0f82 + seg, 0x0006, memoryAGet16(0x0f82 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f826
        memoryASet16(0x0f82 + seg, 0x000e, memoryAGet16(0x0f82 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f82e
        memoryASet16(0x0f83 + seg, 0x0006, memoryAGet16(0x0f83 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f836
        memoryASet16(0x0f83 + seg, 0x000e, memoryAGet16(0x0f83 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f83e
        memoryASet16(0x0f84 + seg, 0x0006, memoryAGet16(0x0f84 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f846
        memoryASet16(0x0f84 + seg, 0x000e, memoryAGet16(0x0f84 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f84e
        memoryASet16(0x0f85 + seg, 0x0006, memoryAGet16(0x0f85 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f856
        memoryASet16(0x0f85 + seg, 0x000e, memoryAGet16(0x0f85 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f85e
        memoryASet16(0x0f86 + seg, 0x0006, memoryAGet16(0x0f86 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f866
        memoryASet16(0x0f86 + seg, 0x000e, memoryAGet16(0x0f86 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f86e
        memoryASet16(0x0f87 + seg, 0x0006, memoryAGet16(0x0f87 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f876
        memoryASet16(0x0f87 + seg, 0x000e, memoryAGet16(0x0f87 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f87e
        memoryASet16(0x0f88 + seg, 0x0006, memoryAGet16(0x0f88 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f886
        memoryASet16(0x0f88 + seg, 0x000e, memoryAGet16(0x0f88 + seg, 0x000e) + seg); // 1463 -> 1650; lin=f88e
        memoryASet16(0x0f89 + seg, 0x0006, memoryAGet16(0x0f89 + seg, 0x0006) + seg); // 1463 -> 1650; lin=f896
        memoryASet16(0x0f8a + seg, 0x0000, memoryAGet16(0x0f8a + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8a0
        memoryASet16(0x0f8a + seg, 0x0008, memoryAGet16(0x0f8a + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8a8
        memoryASet16(0x0f8b + seg, 0x0000, memoryAGet16(0x0f8b + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8b0
        memoryASet16(0x0f8b + seg, 0x0008, memoryAGet16(0x0f8b + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8b8
        memoryASet16(0x0f8c + seg, 0x0000, memoryAGet16(0x0f8c + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8c0
        memoryASet16(0x0f8c + seg, 0x0008, memoryAGet16(0x0f8c + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8c8
        memoryASet16(0x0f8d + seg, 0x0000, memoryAGet16(0x0f8d + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8d0
        memoryASet16(0x0f8d + seg, 0x0008, memoryAGet16(0x0f8d + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8d8
        memoryASet16(0x0f8e + seg, 0x0000, memoryAGet16(0x0f8e + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8e0
        memoryASet16(0x0f8e + seg, 0x0008, memoryAGet16(0x0f8e + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8e8
        memoryASet16(0x0f8f + seg, 0x0000, memoryAGet16(0x0f8f + seg, 0x0000) + seg); // 3170 -> 335d; lin=f8f0
        memoryASet16(0x0f8f + seg, 0x0008, memoryAGet16(0x0f8f + seg, 0x0008) + seg); // 3170 -> 335d; lin=f8f8
        memoryASet16(0x0f90 + seg, 0x0000, memoryAGet16(0x0f90 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f900
        memoryASet16(0x0f90 + seg, 0x0008, memoryAGet16(0x0f90 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f908
        memoryASet16(0x0f91 + seg, 0x0000, memoryAGet16(0x0f91 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f910
        memoryASet16(0x0f91 + seg, 0x0008, memoryAGet16(0x0f91 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f918
        memoryASet16(0x0f92 + seg, 0x0000, memoryAGet16(0x0f92 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f920
        memoryASet16(0x0f92 + seg, 0x0008, memoryAGet16(0x0f92 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f928
        memoryASet16(0x0f93 + seg, 0x0000, memoryAGet16(0x0f93 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f930
        memoryASet16(0x0f93 + seg, 0x0008, memoryAGet16(0x0f93 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f938
        memoryASet16(0x0f94 + seg, 0x0000, memoryAGet16(0x0f94 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f940
        memoryASet16(0x0f94 + seg, 0x0008, memoryAGet16(0x0f94 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f948
        memoryASet16(0x0f95 + seg, 0x0000, memoryAGet16(0x0f95 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f950
        memoryASet16(0x0f95 + seg, 0x0008, memoryAGet16(0x0f95 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f958
        memoryASet16(0x0f96 + seg, 0x0000, memoryAGet16(0x0f96 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f960
        memoryASet16(0x0f96 + seg, 0x0008, memoryAGet16(0x0f96 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f968
        memoryASet16(0x0f97 + seg, 0x0000, memoryAGet16(0x0f97 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f970
        memoryASet16(0x0f97 + seg, 0x0008, memoryAGet16(0x0f97 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f978
        memoryASet16(0x0f98 + seg, 0x0000, memoryAGet16(0x0f98 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f980
        memoryASet16(0x0f98 + seg, 0x0008, memoryAGet16(0x0f98 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f988
        memoryASet16(0x0f99 + seg, 0x0000, memoryAGet16(0x0f99 + seg, 0x0000) + seg); // 3170 -> 335d; lin=f990
        memoryASet16(0x0f99 + seg, 0x0008, memoryAGet16(0x0f99 + seg, 0x0008) + seg); // 3170 -> 335d; lin=f998
        memoryASet16(0x0f9a + seg, 0x0000, memoryAGet16(0x0f9a + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9a0
        memoryASet16(0x0f9a + seg, 0x0008, memoryAGet16(0x0f9a + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9a8
        memoryASet16(0x0f9b + seg, 0x0000, memoryAGet16(0x0f9b + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9b0
        memoryASet16(0x0f9b + seg, 0x0008, memoryAGet16(0x0f9b + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9b8
        memoryASet16(0x0f9c + seg, 0x0000, memoryAGet16(0x0f9c + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9c0
        memoryASet16(0x0f9c + seg, 0x0008, memoryAGet16(0x0f9c + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9c8
        memoryASet16(0x0f9d + seg, 0x0000, memoryAGet16(0x0f9d + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9d0
        memoryASet16(0x0f9d + seg, 0x0008, memoryAGet16(0x0f9d + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9d8
        memoryASet16(0x0f9e + seg, 0x0000, memoryAGet16(0x0f9e + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9e0
        memoryASet16(0x0f9e + seg, 0x0008, memoryAGet16(0x0f9e + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9e8
        memoryASet16(0x0f9f + seg, 0x0000, memoryAGet16(0x0f9f + seg, 0x0000) + seg); // 3170 -> 335d; lin=f9f0
        memoryASet16(0x0f9f + seg, 0x0008, memoryAGet16(0x0f9f + seg, 0x0008) + seg); // 3170 -> 335d; lin=f9f8
        memoryASet16(0x0fa0 + seg, 0x0000, memoryAGet16(0x0fa0 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa00
        memoryASet16(0x0fa0 + seg, 0x0008, memoryAGet16(0x0fa0 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa08
        memoryASet16(0x0fa1 + seg, 0x0000, memoryAGet16(0x0fa1 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa10
        memoryASet16(0x0fa1 + seg, 0x0008, memoryAGet16(0x0fa1 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa18
        memoryASet16(0x0fa2 + seg, 0x0000, memoryAGet16(0x0fa2 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa20
        memoryASet16(0x0fa2 + seg, 0x0008, memoryAGet16(0x0fa2 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa28
        memoryASet16(0x0fa3 + seg, 0x0000, memoryAGet16(0x0fa3 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa30
        memoryASet16(0x0fa3 + seg, 0x0008, memoryAGet16(0x0fa3 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa38
        memoryASet16(0x0fa4 + seg, 0x0000, memoryAGet16(0x0fa4 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa40
        memoryASet16(0x0fa4 + seg, 0x0008, memoryAGet16(0x0fa4 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa48
        memoryASet16(0x0fa5 + seg, 0x0000, memoryAGet16(0x0fa5 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa50
        memoryASet16(0x0fa5 + seg, 0x0008, memoryAGet16(0x0fa5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa58
        memoryASet16(0x0fa6 + seg, 0x0000, memoryAGet16(0x0fa6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa60
        memoryASet16(0x0fa6 + seg, 0x0008, memoryAGet16(0x0fa6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa68
        memoryASet16(0x0fa7 + seg, 0x0000, memoryAGet16(0x0fa7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa70
        memoryASet16(0x0fa7 + seg, 0x0008, memoryAGet16(0x0fa7 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa78
        memoryASet16(0x0fa8 + seg, 0x0000, memoryAGet16(0x0fa8 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa80
        memoryASet16(0x0fa8 + seg, 0x0008, memoryAGet16(0x0fa8 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa88
        memoryASet16(0x0fa9 + seg, 0x0000, memoryAGet16(0x0fa9 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fa90
        memoryASet16(0x0fa9 + seg, 0x0008, memoryAGet16(0x0fa9 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fa98
        memoryASet16(0x0faa + seg, 0x0000, memoryAGet16(0x0faa + seg, 0x0000) + seg); // 3170 -> 335d; lin=faa0
        memoryASet16(0x0faa + seg, 0x0008, memoryAGet16(0x0faa + seg, 0x0008) + seg); // 3170 -> 335d; lin=faa8
        memoryASet16(0x0fab + seg, 0x0000, memoryAGet16(0x0fab + seg, 0x0000) + seg); // 3170 -> 335d; lin=fab0
        memoryASet16(0x0fab + seg, 0x0008, memoryAGet16(0x0fab + seg, 0x0008) + seg); // 3170 -> 335d; lin=fab8
        memoryASet16(0x0fac + seg, 0x0000, memoryAGet16(0x0fac + seg, 0x0000) + seg); // 3170 -> 335d; lin=fac0
        memoryASet16(0x0fac + seg, 0x0008, memoryAGet16(0x0fac + seg, 0x0008) + seg); // 3170 -> 335d; lin=fac8
        memoryASet16(0x0fad + seg, 0x0000, memoryAGet16(0x0fad + seg, 0x0000) + seg); // 3170 -> 335d; lin=fad0
        memoryASet16(0x0fad + seg, 0x0008, memoryAGet16(0x0fad + seg, 0x0008) + seg); // 3170 -> 335d; lin=fad8
        memoryASet16(0x0fae + seg, 0x0000, memoryAGet16(0x0fae + seg, 0x0000) + seg); // 3170 -> 335d; lin=fae0
        memoryASet16(0x0fae + seg, 0x0008, memoryAGet16(0x0fae + seg, 0x0008) + seg); // 3170 -> 335d; lin=fae8
        memoryASet16(0x0faf + seg, 0x0000, memoryAGet16(0x0faf + seg, 0x0000) + seg); // 3170 -> 335d; lin=faf0
        memoryASet16(0x0faf + seg, 0x0008, memoryAGet16(0x0faf + seg, 0x0008) + seg); // 3170 -> 335d; lin=faf8
        memoryASet16(0x0fb0 + seg, 0x0000, memoryAGet16(0x0fb0 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb00
        memoryASet16(0x0fb0 + seg, 0x0008, memoryAGet16(0x0fb0 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb08
        memoryASet16(0x0fb1 + seg, 0x0000, memoryAGet16(0x0fb1 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb10
        memoryASet16(0x0fb1 + seg, 0x0008, memoryAGet16(0x0fb1 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb18
        memoryASet16(0x0fb2 + seg, 0x0000, memoryAGet16(0x0fb2 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb20
        memoryASet16(0x0fb2 + seg, 0x0008, memoryAGet16(0x0fb2 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb28
        memoryASet16(0x0fb3 + seg, 0x0000, memoryAGet16(0x0fb3 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb30
        memoryASet16(0x0fb3 + seg, 0x0008, memoryAGet16(0x0fb3 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb38
        memoryASet16(0x0fb4 + seg, 0x0000, memoryAGet16(0x0fb4 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb40
        memoryASet16(0x0fb4 + seg, 0x0008, memoryAGet16(0x0fb4 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb48
        memoryASet16(0x0fb5 + seg, 0x0000, memoryAGet16(0x0fb5 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb50
        memoryASet16(0x0fb5 + seg, 0x0008, memoryAGet16(0x0fb5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb58
        memoryASet16(0x0fb6 + seg, 0x0000, memoryAGet16(0x0fb6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb60
        memoryASet16(0x0fb6 + seg, 0x0008, memoryAGet16(0x0fb6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb68
        memoryASet16(0x0fb7 + seg, 0x0000, memoryAGet16(0x0fb7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb70
        memoryASet16(0x0fb7 + seg, 0x0008, memoryAGet16(0x0fb7 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb78
        memoryASet16(0x0fb8 + seg, 0x0000, memoryAGet16(0x0fb8 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb80
        memoryASet16(0x0fb8 + seg, 0x0008, memoryAGet16(0x0fb8 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb88
        memoryASet16(0x0fb9 + seg, 0x0000, memoryAGet16(0x0fb9 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fb90
        memoryASet16(0x0fb9 + seg, 0x0008, memoryAGet16(0x0fb9 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fb98
        memoryASet16(0x0fba + seg, 0x0000, memoryAGet16(0x0fba + seg, 0x0000) + seg); // 3170 -> 335d; lin=fba0
        memoryASet16(0x0fba + seg, 0x0008, memoryAGet16(0x0fba + seg, 0x0008) + seg); // 3170 -> 335d; lin=fba8
        memoryASet16(0x0fbb + seg, 0x0000, memoryAGet16(0x0fbb + seg, 0x0000) + seg); // 3170 -> 335d; lin=fbb0
        memoryASet16(0x0fbb + seg, 0x0008, memoryAGet16(0x0fbb + seg, 0x0008) + seg); // 3170 -> 335d; lin=fbb8
        memoryASet16(0x0fbc + seg, 0x0000, memoryAGet16(0x0fbc + seg, 0x0000) + seg); // 3170 -> 335d; lin=fbc0
        memoryASet16(0x0fbc + seg, 0x0008, memoryAGet16(0x0fbc + seg, 0x0008) + seg); // 3170 -> 335d; lin=fbc8
        memoryASet16(0x0fbd + seg, 0x0000, memoryAGet16(0x0fbd + seg, 0x0000) + seg); // 3170 -> 335d; lin=fbd0
        memoryASet16(0x0fbd + seg, 0x0008, memoryAGet16(0x0fbd + seg, 0x0008) + seg); // 3170 -> 335d; lin=fbd8
        memoryASet16(0x0fbe + seg, 0x0000, memoryAGet16(0x0fbe + seg, 0x0000) + seg); // 3170 -> 335d; lin=fbe0
        memoryASet16(0x0fbe + seg, 0x0008, memoryAGet16(0x0fbe + seg, 0x0008) + seg); // 3170 -> 335d; lin=fbe8
        memoryASet16(0x0fbf + seg, 0x0000, memoryAGet16(0x0fbf + seg, 0x0000) + seg); // 3170 -> 335d; lin=fbf0
        memoryASet16(0x0fbf + seg, 0x0008, memoryAGet16(0x0fbf + seg, 0x0008) + seg); // 3170 -> 335d; lin=fbf8
        memoryASet16(0x0fc0 + seg, 0x0000, memoryAGet16(0x0fc0 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc00
        memoryASet16(0x0fc0 + seg, 0x0008, memoryAGet16(0x0fc0 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc08
        memoryASet16(0x0fc1 + seg, 0x0000, memoryAGet16(0x0fc1 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc10
        memoryASet16(0x0fc1 + seg, 0x0008, memoryAGet16(0x0fc1 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc18
        memoryASet16(0x0fc2 + seg, 0x0000, memoryAGet16(0x0fc2 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc20
        memoryASet16(0x0fc2 + seg, 0x0008, memoryAGet16(0x0fc2 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc28
        memoryASet16(0x0fc3 + seg, 0x0000, memoryAGet16(0x0fc3 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc30
        memoryASet16(0x0fc3 + seg, 0x0008, memoryAGet16(0x0fc3 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc38
        memoryASet16(0x0fc4 + seg, 0x0000, memoryAGet16(0x0fc4 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc40
        memoryASet16(0x0fc4 + seg, 0x0008, memoryAGet16(0x0fc4 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc48
        memoryASet16(0x0fc5 + seg, 0x0000, memoryAGet16(0x0fc5 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc50
        memoryASet16(0x0fc5 + seg, 0x0008, memoryAGet16(0x0fc5 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc58
        memoryASet16(0x0fc6 + seg, 0x0000, memoryAGet16(0x0fc6 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc60
        memoryASet16(0x0fc6 + seg, 0x0008, memoryAGet16(0x0fc6 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc68
        memoryASet16(0x0fc7 + seg, 0x0000, memoryAGet16(0x0fc7 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc70
        memoryASet16(0x0fc7 + seg, 0x0008, memoryAGet16(0x0fc7 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc78
        memoryASet16(0x0fc8 + seg, 0x0000, memoryAGet16(0x0fc8 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc80
        memoryASet16(0x0fc8 + seg, 0x0008, memoryAGet16(0x0fc8 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc88
        memoryASet16(0x0fc9 + seg, 0x0000, memoryAGet16(0x0fc9 + seg, 0x0000) + seg); // 3170 -> 335d; lin=fc90
        memoryASet16(0x0fc9 + seg, 0x0008, memoryAGet16(0x0fc9 + seg, 0x0008) + seg); // 3170 -> 335d; lin=fc98
        memoryASet16(0x0fca + seg, 0x0002, memoryAGet16(0x0fca + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fca2
        memoryASet16(0x0fca + seg, 0x000a, memoryAGet16(0x0fca + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcaa
        memoryASet16(0x0fcb + seg, 0x0002, memoryAGet16(0x0fcb + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fcb2
        memoryASet16(0x0fcb + seg, 0x000a, memoryAGet16(0x0fcb + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcba
        memoryASet16(0x0fcc + seg, 0x0002, memoryAGet16(0x0fcc + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fcc2
        memoryASet16(0x0fcc + seg, 0x000a, memoryAGet16(0x0fcc + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcca
        memoryASet16(0x0fcd + seg, 0x0002, memoryAGet16(0x0fcd + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fcd2
        memoryASet16(0x0fcd + seg, 0x000a, memoryAGet16(0x0fcd + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcda
        memoryASet16(0x0fce + seg, 0x0002, memoryAGet16(0x0fce + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fce2
        memoryASet16(0x0fce + seg, 0x000a, memoryAGet16(0x0fce + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcea
        memoryASet16(0x0fcf + seg, 0x0002, memoryAGet16(0x0fcf + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fcf2
        memoryASet16(0x0fcf + seg, 0x000a, memoryAGet16(0x0fcf + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fcfa
        memoryASet16(0x0fd0 + seg, 0x0002, memoryAGet16(0x0fd0 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd02
        memoryASet16(0x0fd0 + seg, 0x000a, memoryAGet16(0x0fd0 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd0a
        memoryASet16(0x0fd1 + seg, 0x0002, memoryAGet16(0x0fd1 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd12
        memoryASet16(0x0fd1 + seg, 0x000a, memoryAGet16(0x0fd1 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd1a
        memoryASet16(0x0fd2 + seg, 0x0002, memoryAGet16(0x0fd2 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd22
        memoryASet16(0x0fd2 + seg, 0x000a, memoryAGet16(0x0fd2 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd2a
        memoryASet16(0x0fd3 + seg, 0x0002, memoryAGet16(0x0fd3 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd32
        memoryASet16(0x0fd3 + seg, 0x000a, memoryAGet16(0x0fd3 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd3a
        memoryASet16(0x0fd4 + seg, 0x0002, memoryAGet16(0x0fd4 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd42
        memoryASet16(0x0fd4 + seg, 0x000a, memoryAGet16(0x0fd4 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd4a
        memoryASet16(0x0fd5 + seg, 0x0002, memoryAGet16(0x0fd5 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd52
        memoryASet16(0x0fd5 + seg, 0x000a, memoryAGet16(0x0fd5 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd5a
        memoryASet16(0x0fd6 + seg, 0x0002, memoryAGet16(0x0fd6 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd62
        memoryASet16(0x0fd6 + seg, 0x000a, memoryAGet16(0x0fd6 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd6a
        memoryASet16(0x0fd7 + seg, 0x0002, memoryAGet16(0x0fd7 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd72
        memoryASet16(0x0fd7 + seg, 0x000a, memoryAGet16(0x0fd7 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd7a
        memoryASet16(0x0fd8 + seg, 0x0002, memoryAGet16(0x0fd8 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd82
        memoryASet16(0x0fd8 + seg, 0x000a, memoryAGet16(0x0fd8 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd8a
        memoryASet16(0x0fd9 + seg, 0x0002, memoryAGet16(0x0fd9 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fd92
        memoryASet16(0x0fd9 + seg, 0x000a, memoryAGet16(0x0fd9 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fd9a
        memoryASet16(0x0fda + seg, 0x0002, memoryAGet16(0x0fda + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fda2
        memoryASet16(0x0fda + seg, 0x000a, memoryAGet16(0x0fda + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdaa
        memoryASet16(0x0fdb + seg, 0x0002, memoryAGet16(0x0fdb + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fdb2
        memoryASet16(0x0fdb + seg, 0x000a, memoryAGet16(0x0fdb + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdba
        memoryASet16(0x0fdc + seg, 0x0002, memoryAGet16(0x0fdc + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fdc2
        memoryASet16(0x0fdc + seg, 0x000a, memoryAGet16(0x0fdc + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdca
        memoryASet16(0x0fdd + seg, 0x0002, memoryAGet16(0x0fdd + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fdd2
        memoryASet16(0x0fdd + seg, 0x000a, memoryAGet16(0x0fdd + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdda
        memoryASet16(0x0fde + seg, 0x0002, memoryAGet16(0x0fde + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fde2
        memoryASet16(0x0fde + seg, 0x000a, memoryAGet16(0x0fde + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdea
        memoryASet16(0x0fdf + seg, 0x0002, memoryAGet16(0x0fdf + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fdf2
        memoryASet16(0x0fdf + seg, 0x000a, memoryAGet16(0x0fdf + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fdfa
        memoryASet16(0x0fe0 + seg, 0x0002, memoryAGet16(0x0fe0 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe02
        memoryASet16(0x0fe0 + seg, 0x000a, memoryAGet16(0x0fe0 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe0a
        memoryASet16(0x0fe1 + seg, 0x0002, memoryAGet16(0x0fe1 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe12
        memoryASet16(0x0fe1 + seg, 0x000a, memoryAGet16(0x0fe1 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe1a
        memoryASet16(0x0fe2 + seg, 0x0002, memoryAGet16(0x0fe2 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe22
        memoryASet16(0x0fe2 + seg, 0x000a, memoryAGet16(0x0fe2 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe2a
        memoryASet16(0x0fe3 + seg, 0x0002, memoryAGet16(0x0fe3 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe32
        memoryASet16(0x0fe3 + seg, 0x000a, memoryAGet16(0x0fe3 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe3a
        memoryASet16(0x0fe4 + seg, 0x0002, memoryAGet16(0x0fe4 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe42
        memoryASet16(0x0fe4 + seg, 0x000a, memoryAGet16(0x0fe4 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe4a
        memoryASet16(0x0fe5 + seg, 0x0002, memoryAGet16(0x0fe5 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe52
        memoryASet16(0x0fe5 + seg, 0x000a, memoryAGet16(0x0fe5 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe5a
        memoryASet16(0x0fe6 + seg, 0x0002, memoryAGet16(0x0fe6 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe62
        memoryASet16(0x0fe6 + seg, 0x000a, memoryAGet16(0x0fe6 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe6a
        memoryASet16(0x0fe7 + seg, 0x0002, memoryAGet16(0x0fe7 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe72
        memoryASet16(0x0fe7 + seg, 0x000a, memoryAGet16(0x0fe7 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe7a
        memoryASet16(0x0fe8 + seg, 0x0002, memoryAGet16(0x0fe8 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe82
        memoryASet16(0x0fe8 + seg, 0x000a, memoryAGet16(0x0fe8 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe8a
        memoryASet16(0x0fe9 + seg, 0x0002, memoryAGet16(0x0fe9 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fe92
        memoryASet16(0x0fe9 + seg, 0x000a, memoryAGet16(0x0fe9 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fe9a
        memoryASet16(0x0fea + seg, 0x0002, memoryAGet16(0x0fea + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fea2
        memoryASet16(0x0fea + seg, 0x000a, memoryAGet16(0x0fea + seg, 0x000a) + seg); // 4110 -> 42fd; lin=feaa
        memoryASet16(0x0feb + seg, 0x0002, memoryAGet16(0x0feb + seg, 0x0002) + seg); // 4110 -> 42fd; lin=feb2
        memoryASet16(0x0feb + seg, 0x000a, memoryAGet16(0x0feb + seg, 0x000a) + seg); // 4110 -> 42fd; lin=feba
        memoryASet16(0x0fec + seg, 0x0002, memoryAGet16(0x0fec + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fec2
        memoryASet16(0x0fec + seg, 0x000a, memoryAGet16(0x0fec + seg, 0x000a) + seg); // 4110 -> 42fd; lin=feca
        memoryASet16(0x0fed + seg, 0x0002, memoryAGet16(0x0fed + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fed2
        memoryASet16(0x0fed + seg, 0x000a, memoryAGet16(0x0fed + seg, 0x000a) + seg); // 4110 -> 42fd; lin=feda
        memoryASet16(0x0fee + seg, 0x0002, memoryAGet16(0x0fee + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fee2
        memoryASet16(0x0fee + seg, 0x000a, memoryAGet16(0x0fee + seg, 0x000a) + seg); // 4110 -> 42fd; lin=feea
        memoryASet16(0x0fef + seg, 0x0002, memoryAGet16(0x0fef + seg, 0x0002) + seg); // 4110 -> 42fd; lin=fef2
        memoryASet16(0x0fef + seg, 0x000a, memoryAGet16(0x0fef + seg, 0x000a) + seg); // 4110 -> 42fd; lin=fefa
        memoryASet16(0x0ff0 + seg, 0x0002, memoryAGet16(0x0ff0 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff02
        memoryASet16(0x0ff0 + seg, 0x000a, memoryAGet16(0x0ff0 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff0a
        memoryASet16(0x0ff1 + seg, 0x0002, memoryAGet16(0x0ff1 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff12
        memoryASet16(0x0ff1 + seg, 0x000a, memoryAGet16(0x0ff1 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff1a
        memoryASet16(0x0ff2 + seg, 0x0002, memoryAGet16(0x0ff2 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff22
        memoryASet16(0x0ff2 + seg, 0x000a, memoryAGet16(0x0ff2 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff2a
        memoryASet16(0x0ff3 + seg, 0x0002, memoryAGet16(0x0ff3 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff32
        memoryASet16(0x0ff3 + seg, 0x000a, memoryAGet16(0x0ff3 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff3a
        memoryASet16(0x0ff4 + seg, 0x0002, memoryAGet16(0x0ff4 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff42
        memoryASet16(0x0ff4 + seg, 0x000a, memoryAGet16(0x0ff4 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff4a
        memoryASet16(0x0ff5 + seg, 0x0002, memoryAGet16(0x0ff5 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff52
        memoryASet16(0x0ff5 + seg, 0x000a, memoryAGet16(0x0ff5 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff5a
        memoryASet16(0x0ff6 + seg, 0x0002, memoryAGet16(0x0ff6 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff62
        memoryASet16(0x0ff6 + seg, 0x000a, memoryAGet16(0x0ff6 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff6a
        memoryASet16(0x0ff7 + seg, 0x0002, memoryAGet16(0x0ff7 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff72
        memoryASet16(0x0ff7 + seg, 0x000a, memoryAGet16(0x0ff7 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff7a
        memoryASet16(0x0ff8 + seg, 0x0002, memoryAGet16(0x0ff8 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff82
        memoryASet16(0x0ff8 + seg, 0x000a, memoryAGet16(0x0ff8 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff8a
        memoryASet16(0x0ff9 + seg, 0x0002, memoryAGet16(0x0ff9 + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ff92
        memoryASet16(0x0ff9 + seg, 0x000a, memoryAGet16(0x0ff9 + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ff9a
        memoryASet16(0x0ffa + seg, 0x0002, memoryAGet16(0x0ffa + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ffa2
        memoryASet16(0x0ffa + seg, 0x000a, memoryAGet16(0x0ffa + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ffaa
        memoryASet16(0x0ffb + seg, 0x0002, memoryAGet16(0x0ffb + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ffb2
        memoryASet16(0x0ffb + seg, 0x000a, memoryAGet16(0x0ffb + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ffba
        memoryASet16(0x0ffc + seg, 0x0002, memoryAGet16(0x0ffc + seg, 0x0002) + seg); // 4110 -> 42fd; lin=ffc2
        memoryASet16(0x0ffc + seg, 0x000a, memoryAGet16(0x0ffc + seg, 0x000a) + seg); // 4110 -> 42fd; lin=ffca
        memoryASet16(0x0ffd + seg, 0x0004, memoryAGet16(0x0ffd + seg, 0x0004) + seg); // 1463 -> 1650; lin=ffd4
        memoryASet16(0x0ffd + seg, 0x000c, memoryAGet16(0x0ffd + seg, 0x000c) + seg); // 1463 -> 1650; lin=ffdc
        memoryASet16(0x0ffe + seg, 0x0004, memoryAGet16(0x0ffe + seg, 0x0004) + seg); // 1463 -> 1650; lin=ffe4
        memoryASet16(0x0ffe + seg, 0x000c, memoryAGet16(0x0ffe + seg, 0x000c) + seg); // 1463 -> 1650; lin=ffec
        memoryASet16(0x0fff + seg, 0x0004, memoryAGet16(0x0fff + seg, 0x0004) + seg); // 1463 -> 1650; lin=fff4
        memoryASet16(0x0fff + seg, 0x000c, memoryAGet16(0x0fff + seg, 0x000c) + seg); // 1463 -> 1650; lin=fffc
        memoryASet16(0x1000 + seg, 0x0004, memoryAGet16(0x1000 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10004
        memoryASet16(0x1000 + seg, 0x000c, memoryAGet16(0x1000 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1000c
        memoryASet16(0x1001 + seg, 0x0004, memoryAGet16(0x1001 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10014
        memoryASet16(0x1001 + seg, 0x000c, memoryAGet16(0x1001 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1001c
        memoryASet16(0x1002 + seg, 0x0004, memoryAGet16(0x1002 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10024
        memoryASet16(0x1002 + seg, 0x000c, memoryAGet16(0x1002 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1002c
        memoryASet16(0x1003 + seg, 0x0004, memoryAGet16(0x1003 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10034
        memoryASet16(0x1003 + seg, 0x000c, memoryAGet16(0x1003 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1003c
        memoryASet16(0x1004 + seg, 0x0004, memoryAGet16(0x1004 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10044
        memoryASet16(0x1004 + seg, 0x000c, memoryAGet16(0x1004 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1004c
        memoryASet16(0x1005 + seg, 0x0004, memoryAGet16(0x1005 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10054
        memoryASet16(0x1005 + seg, 0x000c, memoryAGet16(0x1005 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1005c
        memoryASet16(0x1006 + seg, 0x0004, memoryAGet16(0x1006 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10064
        memoryASet16(0x1006 + seg, 0x000c, memoryAGet16(0x1006 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1006c
        memoryASet16(0x1007 + seg, 0x0004, memoryAGet16(0x1007 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10074
        memoryASet16(0x1007 + seg, 0x000c, memoryAGet16(0x1007 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1007c
        memoryASet16(0x1008 + seg, 0x0004, memoryAGet16(0x1008 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10084
        memoryASet16(0x1008 + seg, 0x000c, memoryAGet16(0x1008 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1008c
        memoryASet16(0x1009 + seg, 0x0004, memoryAGet16(0x1009 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10094
        memoryASet16(0x1009 + seg, 0x000c, memoryAGet16(0x1009 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1009c
        memoryASet16(0x100a + seg, 0x0004, memoryAGet16(0x100a + seg, 0x0004) + seg); // 1463 -> 1650; lin=100a4
        memoryASet16(0x100a + seg, 0x000c, memoryAGet16(0x100a + seg, 0x000c) + seg); // 1463 -> 1650; lin=100ac
        memoryASet16(0x100b + seg, 0x0004, memoryAGet16(0x100b + seg, 0x0004) + seg); // 1463 -> 1650; lin=100b4
        memoryASet16(0x100b + seg, 0x000c, memoryAGet16(0x100b + seg, 0x000c) + seg); // 1463 -> 1650; lin=100bc
        memoryASet16(0x100c + seg, 0x0004, memoryAGet16(0x100c + seg, 0x0004) + seg); // 1463 -> 1650; lin=100c4
        memoryASet16(0x100c + seg, 0x000c, memoryAGet16(0x100c + seg, 0x000c) + seg); // 1463 -> 1650; lin=100cc
        memoryASet16(0x100d + seg, 0x0004, memoryAGet16(0x100d + seg, 0x0004) + seg); // 1463 -> 1650; lin=100d4
        memoryASet16(0x100d + seg, 0x000c, memoryAGet16(0x100d + seg, 0x000c) + seg); // 1463 -> 1650; lin=100dc
        memoryASet16(0x100e + seg, 0x0004, memoryAGet16(0x100e + seg, 0x0004) + seg); // 1463 -> 1650; lin=100e4
        memoryASet16(0x100e + seg, 0x000c, memoryAGet16(0x100e + seg, 0x000c) + seg); // 1463 -> 1650; lin=100ec
        memoryASet16(0x100f + seg, 0x0004, memoryAGet16(0x100f + seg, 0x0004) + seg); // 1463 -> 1650; lin=100f4
        memoryASet16(0x100f + seg, 0x000c, memoryAGet16(0x100f + seg, 0x000c) + seg); // 1463 -> 1650; lin=100fc
        memoryASet16(0x1010 + seg, 0x0004, memoryAGet16(0x1010 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10104
        memoryASet16(0x1010 + seg, 0x000c, memoryAGet16(0x1010 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1010c
        memoryASet16(0x1011 + seg, 0x0004, memoryAGet16(0x1011 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10114
        memoryASet16(0x1011 + seg, 0x000c, memoryAGet16(0x1011 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1011c
        memoryASet16(0x1012 + seg, 0x0004, memoryAGet16(0x1012 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10124
        memoryASet16(0x1012 + seg, 0x000c, memoryAGet16(0x1012 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1012c
        memoryASet16(0x1013 + seg, 0x0004, memoryAGet16(0x1013 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10134
        memoryASet16(0x1013 + seg, 0x000c, memoryAGet16(0x1013 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1013c
        memoryASet16(0x1014 + seg, 0x0004, memoryAGet16(0x1014 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10144
        memoryASet16(0x1014 + seg, 0x000c, memoryAGet16(0x1014 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1014c
        memoryASet16(0x1015 + seg, 0x0004, memoryAGet16(0x1015 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10154
        memoryASet16(0x1015 + seg, 0x000c, memoryAGet16(0x1015 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1015c
        memoryASet16(0x1016 + seg, 0x0004, memoryAGet16(0x1016 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10164
        memoryASet16(0x1016 + seg, 0x000c, memoryAGet16(0x1016 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1016c
        memoryASet16(0x1017 + seg, 0x0004, memoryAGet16(0x1017 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10174
        memoryASet16(0x1017 + seg, 0x000c, memoryAGet16(0x1017 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1017c
        memoryASet16(0x1018 + seg, 0x0004, memoryAGet16(0x1018 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10184
        memoryASet16(0x1018 + seg, 0x000c, memoryAGet16(0x1018 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1018c
        memoryASet16(0x1019 + seg, 0x0004, memoryAGet16(0x1019 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10194
        memoryASet16(0x1019 + seg, 0x000c, memoryAGet16(0x1019 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1019c
        memoryASet16(0x101a + seg, 0x0004, memoryAGet16(0x101a + seg, 0x0004) + seg); // 1463 -> 1650; lin=101a4
        memoryASet16(0x101a + seg, 0x000c, memoryAGet16(0x101a + seg, 0x000c) + seg); // 1463 -> 1650; lin=101ac
        memoryASet16(0x101b + seg, 0x0004, memoryAGet16(0x101b + seg, 0x0004) + seg); // 1463 -> 1650; lin=101b4
        memoryASet16(0x101c + seg, 0x000c, memoryAGet16(0x101c + seg, 0x000c) + seg); // 1463 -> 1650; lin=101cc
        memoryASet16(0x101d + seg, 0x0000, memoryAGet16(0x101d + seg, 0x0000) + seg); // 1463 -> 1650; lin=101d0
        memoryASet16(0x101d + seg, 0x0004, memoryAGet16(0x101d + seg, 0x0004) + seg); // 1463 -> 1650; lin=101d4
        memoryASet16(0x101d + seg, 0x0008, memoryAGet16(0x101d + seg, 0x0008) + seg); // 1463 -> 1650; lin=101d8
        memoryASet16(0x101d + seg, 0x000c, memoryAGet16(0x101d + seg, 0x000c) + seg); // 1463 -> 1650; lin=101dc
        memoryASet16(0x101e + seg, 0x0000, memoryAGet16(0x101e + seg, 0x0000) + seg); // 1463 -> 1650; lin=101e0
        memoryASet16(0x101e + seg, 0x0004, memoryAGet16(0x101e + seg, 0x0004) + seg); // 1463 -> 1650; lin=101e4
        memoryASet16(0x101e + seg, 0x0008, memoryAGet16(0x101e + seg, 0x0008) + seg); // 1463 -> 1650; lin=101e8
        memoryASet16(0x101e + seg, 0x000c, memoryAGet16(0x101e + seg, 0x000c) + seg); // 1463 -> 1650; lin=101ec
        memoryASet16(0x101f + seg, 0x0000, memoryAGet16(0x101f + seg, 0x0000) + seg); // 1463 -> 1650; lin=101f0
        memoryASet16(0x101f + seg, 0x0004, memoryAGet16(0x101f + seg, 0x0004) + seg); // 1463 -> 1650; lin=101f4
        memoryASet16(0x101f + seg, 0x0008, memoryAGet16(0x101f + seg, 0x0008) + seg); // 1463 -> 1650; lin=101f8
        memoryASet16(0x101f + seg, 0x000c, memoryAGet16(0x101f + seg, 0x000c) + seg); // 1463 -> 1650; lin=101fc
        memoryASet16(0x1020 + seg, 0x0000, memoryAGet16(0x1020 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10200
        memoryASet16(0x1020 + seg, 0x0004, memoryAGet16(0x1020 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10204
        memoryASet16(0x1020 + seg, 0x0008, memoryAGet16(0x1020 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10208
        memoryASet16(0x1021 + seg, 0x0000, memoryAGet16(0x1021 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10210
        memoryASet16(0x1021 + seg, 0x0004, memoryAGet16(0x1021 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10214
        memoryASet16(0x1021 + seg, 0x0008, memoryAGet16(0x1021 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10218
        memoryASet16(0x1021 + seg, 0x000c, memoryAGet16(0x1021 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1021c
        memoryASet16(0x1022 + seg, 0x0000, memoryAGet16(0x1022 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10220
        memoryASet16(0x1022 + seg, 0x0004, memoryAGet16(0x1022 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10224
        memoryASet16(0x1022 + seg, 0x0008, memoryAGet16(0x1022 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10228
        memoryASet16(0x1022 + seg, 0x000c, memoryAGet16(0x1022 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1022c
        memoryASet16(0x1023 + seg, 0x0000, memoryAGet16(0x1023 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10230
        memoryASet16(0x1023 + seg, 0x0004, memoryAGet16(0x1023 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10234
        memoryASet16(0x1023 + seg, 0x0008, memoryAGet16(0x1023 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10238
        memoryASet16(0x1023 + seg, 0x000c, memoryAGet16(0x1023 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1023c
        memoryASet16(0x1024 + seg, 0x0000, memoryAGet16(0x1024 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10240
        memoryASet16(0x1024 + seg, 0x0004, memoryAGet16(0x1024 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10244
        memoryASet16(0x1024 + seg, 0x0008, memoryAGet16(0x1024 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10248
        memoryASet16(0x1024 + seg, 0x000c, memoryAGet16(0x1024 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1024c
        memoryASet16(0x1025 + seg, 0x0004, memoryAGet16(0x1025 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10254
        memoryASet16(0x1025 + seg, 0x0008, memoryAGet16(0x1025 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10258
        memoryASet16(0x1025 + seg, 0x000c, memoryAGet16(0x1025 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1025c
        memoryASet16(0x1026 + seg, 0x0000, memoryAGet16(0x1026 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10260
        memoryASet16(0x1026 + seg, 0x0004, memoryAGet16(0x1026 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10264
        memoryASet16(0x1026 + seg, 0x0008, memoryAGet16(0x1026 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10268
        memoryASet16(0x1026 + seg, 0x000c, memoryAGet16(0x1026 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1026c
        memoryASet16(0x1027 + seg, 0x0000, memoryAGet16(0x1027 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10270
        memoryASet16(0x1027 + seg, 0x0004, memoryAGet16(0x1027 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10274
        memoryASet16(0x1027 + seg, 0x0008, memoryAGet16(0x1027 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10278
        memoryASet16(0x1027 + seg, 0x000c, memoryAGet16(0x1027 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1027c
        memoryASet16(0x1028 + seg, 0x0000, memoryAGet16(0x1028 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10280
        memoryASet16(0x1028 + seg, 0x0004, memoryAGet16(0x1028 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10284
        memoryASet16(0x1028 + seg, 0x0008, memoryAGet16(0x1028 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10288
        memoryASet16(0x1028 + seg, 0x000c, memoryAGet16(0x1028 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1028c
        memoryASet16(0x1029 + seg, 0x0000, memoryAGet16(0x1029 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10290
        memoryASet16(0x1029 + seg, 0x0008, memoryAGet16(0x1029 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10298
        memoryASet16(0x1029 + seg, 0x000c, memoryAGet16(0x1029 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1029c
        memoryASet16(0x102a + seg, 0x0000, memoryAGet16(0x102a + seg, 0x0000) + seg); // 1463 -> 1650; lin=102a0
        memoryASet16(0x102a + seg, 0x0004, memoryAGet16(0x102a + seg, 0x0004) + seg); // 1463 -> 1650; lin=102a4
        memoryASet16(0x102a + seg, 0x0008, memoryAGet16(0x102a + seg, 0x0008) + seg); // 1463 -> 1650; lin=102a8
        memoryASet16(0x102a + seg, 0x000c, memoryAGet16(0x102a + seg, 0x000c) + seg); // 1463 -> 1650; lin=102ac
        memoryASet16(0x102b + seg, 0x0000, memoryAGet16(0x102b + seg, 0x0000) + seg); // 1463 -> 1650; lin=102b0
        memoryASet16(0x102b + seg, 0x0004, memoryAGet16(0x102b + seg, 0x0004) + seg); // 1463 -> 1650; lin=102b4
        memoryASet16(0x102b + seg, 0x0008, memoryAGet16(0x102b + seg, 0x0008) + seg); // 1463 -> 1650; lin=102b8
        memoryASet16(0x102b + seg, 0x000c, memoryAGet16(0x102b + seg, 0x000c) + seg); // 1463 -> 1650; lin=102bc
        memoryASet16(0x102c + seg, 0x0002, memoryAGet16(0x102c + seg, 0x0002) + seg); // 1463 -> 1650; lin=102c2
        memoryASet16(0x102c + seg, 0x0006, memoryAGet16(0x102c + seg, 0x0006) + seg); // 1463 -> 1650; lin=102c6
        memoryASet16(0x102c + seg, 0x000a, memoryAGet16(0x102c + seg, 0x000a) + seg); // 1463 -> 1650; lin=102ca
        memoryASet16(0x102c + seg, 0x000e, memoryAGet16(0x102c + seg, 0x000e) + seg); // 1463 -> 1650; lin=102ce
        memoryASet16(0x102d + seg, 0x0002, memoryAGet16(0x102d + seg, 0x0002) + seg); // 1463 -> 1650; lin=102d2
        memoryASet16(0x102d + seg, 0x0006, memoryAGet16(0x102d + seg, 0x0006) + seg); // 1463 -> 1650; lin=102d6
        memoryASet16(0x102d + seg, 0x000a, memoryAGet16(0x102d + seg, 0x000a) + seg); // 1463 -> 1650; lin=102da
        memoryASet16(0x102d + seg, 0x000e, memoryAGet16(0x102d + seg, 0x000e) + seg); // 1463 -> 1650; lin=102de
        memoryASet16(0x102e + seg, 0x0004, memoryAGet16(0x102e + seg, 0x0004) + seg); // 1463 -> 1650; lin=102e4
        memoryASet16(0x102e + seg, 0x0008, memoryAGet16(0x102e + seg, 0x0008) + seg); // 1463 -> 1650; lin=102e8
        memoryASet16(0x102e + seg, 0x000c, memoryAGet16(0x102e + seg, 0x000c) + seg); // 1463 -> 1650; lin=102ec
        memoryASet16(0x102f + seg, 0x0000, memoryAGet16(0x102f + seg, 0x0000) + seg); // 1463 -> 1650; lin=102f0
        memoryASet16(0x102f + seg, 0x0006, memoryAGet16(0x102f + seg, 0x0006) + seg); // 1463 -> 1650; lin=102f6
        memoryASet16(0x102f + seg, 0x000a, memoryAGet16(0x102f + seg, 0x000a) + seg); // 1463 -> 1650; lin=102fa
        memoryASet16(0x102f + seg, 0x000e, memoryAGet16(0x102f + seg, 0x000e) + seg); // 1463 -> 1650; lin=102fe
        memoryASet16(0x1030 + seg, 0x0002, memoryAGet16(0x1030 + seg, 0x0002) + seg); // 1463 -> 1650; lin=10302
        memoryASet16(0x1030 + seg, 0x0006, memoryAGet16(0x1030 + seg, 0x0006) + seg); // 1463 -> 1650; lin=10306
        memoryASet16(0x1030 + seg, 0x000a, memoryAGet16(0x1030 + seg, 0x000a) + seg); // 1463 -> 1650; lin=1030a
        memoryASet16(0x1030 + seg, 0x000e, memoryAGet16(0x1030 + seg, 0x000e) + seg); // 1463 -> 1650; lin=1030e
        memoryASet16(0x1031 + seg, 0x0002, memoryAGet16(0x1031 + seg, 0x0002) + seg); // 1463 -> 1650; lin=10312
        memoryASet16(0x1031 + seg, 0x0008, memoryAGet16(0x1031 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10318
        memoryASet16(0x1031 + seg, 0x000c, memoryAGet16(0x1031 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1031c
        memoryASet16(0x1032 + seg, 0x0000, memoryAGet16(0x1032 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10320
        memoryASet16(0x1032 + seg, 0x0004, memoryAGet16(0x1032 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10324
        memoryASet16(0x1032 + seg, 0x000a, memoryAGet16(0x1032 + seg, 0x000a) + seg); // 1463 -> 1650; lin=1032a
        memoryASet16(0x1032 + seg, 0x000e, memoryAGet16(0x1032 + seg, 0x000e) + seg); // 1463 -> 1650; lin=1032e
        memoryASet16(0x1033 + seg, 0x0002, memoryAGet16(0x1033 + seg, 0x0002) + seg); // 1463 -> 1650; lin=10332
        memoryASet16(0x1033 + seg, 0x0006, memoryAGet16(0x1033 + seg, 0x0006) + seg); // 1463 -> 1650; lin=10336
        memoryASet16(0x1033 + seg, 0x000a, memoryAGet16(0x1033 + seg, 0x000a) + seg); // 1463 -> 1650; lin=1033a
        memoryASet16(0x1033 + seg, 0x000e, memoryAGet16(0x1033 + seg, 0x000e) + seg); // 1463 -> 1650; lin=1033e
        memoryASet16(0x1034 + seg, 0x0002, memoryAGet16(0x1034 + seg, 0x0002) + seg); // 1463 -> 1650; lin=10342
        memoryASet16(0x1034 + seg, 0x0008, memoryAGet16(0x1034 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10348
        memoryASet16(0x1034 + seg, 0x000c, memoryAGet16(0x1034 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1034c
        memoryASet16(0x1035 + seg, 0x0000, memoryAGet16(0x1035 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10350
        memoryASet16(0x1035 + seg, 0x0004, memoryAGet16(0x1035 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10354
        memoryASet16(0x1035 + seg, 0x0008, memoryAGet16(0x1035 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10358
        memoryASet16(0x1035 + seg, 0x000c, memoryAGet16(0x1035 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1035c
        memoryASet16(0x1036 + seg, 0x0000, memoryAGet16(0x1036 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10360
        memoryASet16(0x1036 + seg, 0x0004, memoryAGet16(0x1036 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10364
        memoryASet16(0x1036 + seg, 0x0008, memoryAGet16(0x1036 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10368
        memoryASet16(0x1036 + seg, 0x000c, memoryAGet16(0x1036 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1036c
        memoryASet16(0x1037 + seg, 0x0000, memoryAGet16(0x1037 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10370
        memoryASet16(0x1037 + seg, 0x0004, memoryAGet16(0x1037 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10374
        memoryASet16(0x1037 + seg, 0x0008, memoryAGet16(0x1037 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10378
        memoryASet16(0x1037 + seg, 0x000c, memoryAGet16(0x1037 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1037c
        memoryASet16(0x1038 + seg, 0x0000, memoryAGet16(0x1038 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10380
        memoryASet16(0x1038 + seg, 0x0004, memoryAGet16(0x1038 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10384
        memoryASet16(0x1038 + seg, 0x000c, memoryAGet16(0x1038 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1038c
        memoryASet16(0x1039 + seg, 0x0000, memoryAGet16(0x1039 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10390
        memoryASet16(0x1039 + seg, 0x0004, memoryAGet16(0x1039 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10394
        memoryASet16(0x1039 + seg, 0x0008, memoryAGet16(0x1039 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10398
        memoryASet16(0x1039 + seg, 0x000c, memoryAGet16(0x1039 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1039c
        memoryASet16(0x103a + seg, 0x0000, memoryAGet16(0x103a + seg, 0x0000) + seg); // 1463 -> 1650; lin=103a0
        memoryASet16(0x103a + seg, 0x0004, memoryAGet16(0x103a + seg, 0x0004) + seg); // 1463 -> 1650; lin=103a4
        memoryASet16(0x103a + seg, 0x0008, memoryAGet16(0x103a + seg, 0x0008) + seg); // 1463 -> 1650; lin=103a8
        memoryASet16(0x103a + seg, 0x000c, memoryAGet16(0x103a + seg, 0x000c) + seg); // 1463 -> 1650; lin=103ac
        memoryASet16(0x103b + seg, 0x0000, memoryAGet16(0x103b + seg, 0x0000) + seg); // 1463 -> 1650; lin=103b0
        memoryASet16(0x103b + seg, 0x0004, memoryAGet16(0x103b + seg, 0x0004) + seg); // 1463 -> 1650; lin=103b4
        memoryASet16(0x103b + seg, 0x0008, memoryAGet16(0x103b + seg, 0x0008) + seg); // 1463 -> 1650; lin=103b8
        memoryASet16(0x103b + seg, 0x000c, memoryAGet16(0x103b + seg, 0x000c) + seg); // 1463 -> 1650; lin=103bc
        memoryASet16(0x103c + seg, 0x0000, memoryAGet16(0x103c + seg, 0x0000) + seg); // 1463 -> 1650; lin=103c0
        memoryASet16(0x103c + seg, 0x0004, memoryAGet16(0x103c + seg, 0x0004) + seg); // 1463 -> 1650; lin=103c4
        memoryASet16(0x103c + seg, 0x0008, memoryAGet16(0x103c + seg, 0x0008) + seg); // 1463 -> 1650; lin=103c8
        memoryASet16(0x103d + seg, 0x0000, memoryAGet16(0x103d + seg, 0x0000) + seg); // 1463 -> 1650; lin=103d0
        memoryASet16(0x103d + seg, 0x0004, memoryAGet16(0x103d + seg, 0x0004) + seg); // 1463 -> 1650; lin=103d4
        memoryASet16(0x103d + seg, 0x0008, memoryAGet16(0x103d + seg, 0x0008) + seg); // 1463 -> 1650; lin=103d8
        memoryASet16(0x103d + seg, 0x000c, memoryAGet16(0x103d + seg, 0x000c) + seg); // 1463 -> 1650; lin=103dc
        memoryASet16(0x103e + seg, 0x0000, memoryAGet16(0x103e + seg, 0x0000) + seg); // 1463 -> 1650; lin=103e0
        memoryASet16(0x103e + seg, 0x0004, memoryAGet16(0x103e + seg, 0x0004) + seg); // 1463 -> 1650; lin=103e4
        memoryASet16(0x103e + seg, 0x0008, memoryAGet16(0x103e + seg, 0x0008) + seg); // 1463 -> 1650; lin=103e8
        memoryASet16(0x103e + seg, 0x000c, memoryAGet16(0x103e + seg, 0x000c) + seg); // 1463 -> 1650; lin=103ec
        memoryASet16(0x103f + seg, 0x0000, memoryAGet16(0x103f + seg, 0x0000) + seg); // 1463 -> 1650; lin=103f0
        memoryASet16(0x103f + seg, 0x0004, memoryAGet16(0x103f + seg, 0x0004) + seg); // 1463 -> 1650; lin=103f4
        memoryASet16(0x103f + seg, 0x0008, memoryAGet16(0x103f + seg, 0x0008) + seg); // 1463 -> 1650; lin=103f8
        memoryASet16(0x103f + seg, 0x000c, memoryAGet16(0x103f + seg, 0x000c) + seg); // 1463 -> 1650; lin=103fc
        memoryASet16(0x1040 + seg, 0x0000, memoryAGet16(0x1040 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10400
        memoryASet16(0x1040 + seg, 0x0004, memoryAGet16(0x1040 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10404
        memoryASet16(0x1040 + seg, 0x0008, memoryAGet16(0x1040 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10408
        memoryASet16(0x1040 + seg, 0x000c, memoryAGet16(0x1040 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1040c
        memoryASet16(0x1041 + seg, 0x0004, memoryAGet16(0x1041 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10414
        memoryASet16(0x1041 + seg, 0x0008, memoryAGet16(0x1041 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10418
        memoryASet16(0x1041 + seg, 0x000c, memoryAGet16(0x1041 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1041c
        memoryASet16(0x1042 + seg, 0x0000, memoryAGet16(0x1042 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10420
        memoryASet16(0x1042 + seg, 0x0004, memoryAGet16(0x1042 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10424
        memoryASet16(0x1042 + seg, 0x0008, memoryAGet16(0x1042 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10428
        memoryASet16(0x1042 + seg, 0x000c, memoryAGet16(0x1042 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1042c
        memoryASet16(0x1043 + seg, 0x0000, memoryAGet16(0x1043 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10430
        memoryASet16(0x1043 + seg, 0x0004, memoryAGet16(0x1043 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10434
        memoryASet16(0x1043 + seg, 0x0008, memoryAGet16(0x1043 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10438
        memoryASet16(0x1043 + seg, 0x000c, memoryAGet16(0x1043 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1043c
        memoryASet16(0x1044 + seg, 0x0000, memoryAGet16(0x1044 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10440
        memoryASet16(0x1044 + seg, 0x0004, memoryAGet16(0x1044 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10444
        memoryASet16(0x1044 + seg, 0x0008, memoryAGet16(0x1044 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10448
        memoryASet16(0x1044 + seg, 0x000c, memoryAGet16(0x1044 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1044c
        memoryASet16(0x1045 + seg, 0x0000, memoryAGet16(0x1045 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10450
        memoryASet16(0x1045 + seg, 0x0008, memoryAGet16(0x1045 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10458
        memoryASet16(0x1045 + seg, 0x000c, memoryAGet16(0x1045 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1045c
        memoryASet16(0x1046 + seg, 0x0000, memoryAGet16(0x1046 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10460
        memoryASet16(0x1046 + seg, 0x0004, memoryAGet16(0x1046 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10464
        memoryASet16(0x1046 + seg, 0x0008, memoryAGet16(0x1046 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10468
        memoryASet16(0x1046 + seg, 0x000c, memoryAGet16(0x1046 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1046c
        memoryASet16(0x1047 + seg, 0x0000, memoryAGet16(0x1047 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10470
        memoryASet16(0x1047 + seg, 0x0006, memoryAGet16(0x1047 + seg, 0x0006) + seg); // 1463 -> 1650; lin=10476
        memoryASet16(0x1047 + seg, 0x000a, memoryAGet16(0x1047 + seg, 0x000a) + seg); // 1463 -> 1650; lin=1047a
        memoryASet16(0x1047 + seg, 0x000e, memoryAGet16(0x1047 + seg, 0x000e) + seg); // 1463 -> 1650; lin=1047e
        memoryASet16(0x1048 + seg, 0x0002, memoryAGet16(0x1048 + seg, 0x0002) + seg); // 1463 -> 1650; lin=10482
        memoryASet16(0x1048 + seg, 0x0008, memoryAGet16(0x1048 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10488
        memoryASet16(0x1048 + seg, 0x000c, memoryAGet16(0x1048 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1048c
        memoryASet16(0x1049 + seg, 0x0000, memoryAGet16(0x1049 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10490
        memoryASet16(0x1049 + seg, 0x0004, memoryAGet16(0x1049 + seg, 0x0004) + seg); // 1463 -> 1650; lin=10494
        memoryASet16(0x1049 + seg, 0x0008, memoryAGet16(0x1049 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10498
        memoryASet16(0x1049 + seg, 0x000c, memoryAGet16(0x1049 + seg, 0x000c) + seg); // 1463 -> 1650; lin=1049c
        memoryASet16(0x104a + seg, 0x0000, memoryAGet16(0x104a + seg, 0x0000) + seg); // 1463 -> 1650; lin=104a0
        memoryASet16(0x104a + seg, 0x0006, memoryAGet16(0x104a + seg, 0x0006) + seg); // 3170 -> 335d; lin=104a6
        memoryASet16(0x104a + seg, 0x000a, memoryAGet16(0x104a + seg, 0x000a) + seg); // 3170 -> 335d; lin=104aa
        memoryASet16(0x104a + seg, 0x000e, memoryAGet16(0x104a + seg, 0x000e) + seg); // 3170 -> 335d; lin=104ae
        memoryASet16(0x104b + seg, 0x0002, memoryAGet16(0x104b + seg, 0x0002) + seg); // 3170 -> 335d; lin=104b2
        memoryASet16(0x104b + seg, 0x0006, memoryAGet16(0x104b + seg, 0x0006) + seg); // 3170 -> 335d; lin=104b6
        memoryASet16(0x104b + seg, 0x000a, memoryAGet16(0x104b + seg, 0x000a) + seg); // 3170 -> 335d; lin=104ba
        memoryASet16(0x104b + seg, 0x000e, memoryAGet16(0x104b + seg, 0x000e) + seg); // 3170 -> 335d; lin=104be
        memoryASet16(0x104c + seg, 0x0002, memoryAGet16(0x104c + seg, 0x0002) + seg); // 3170 -> 335d; lin=104c2
        memoryASet16(0x104c + seg, 0x0006, memoryAGet16(0x104c + seg, 0x0006) + seg); // 3170 -> 335d; lin=104c6
        memoryASet16(0x104c + seg, 0x000a, memoryAGet16(0x104c + seg, 0x000a) + seg); // 3170 -> 335d; lin=104ca
        memoryASet16(0x104c + seg, 0x000e, memoryAGet16(0x104c + seg, 0x000e) + seg); // 3170 -> 335d; lin=104ce
        memoryASet16(0x104d + seg, 0x0002, memoryAGet16(0x104d + seg, 0x0002) + seg); // 3170 -> 335d; lin=104d2
        memoryASet16(0x104d + seg, 0x0006, memoryAGet16(0x104d + seg, 0x0006) + seg); // 3170 -> 335d; lin=104d6
        memoryASet16(0x104d + seg, 0x000a, memoryAGet16(0x104d + seg, 0x000a) + seg); // 3170 -> 335d; lin=104da
        memoryASet16(0x104d + seg, 0x000e, memoryAGet16(0x104d + seg, 0x000e) + seg); // 3170 -> 335d; lin=104de
        memoryASet16(0x104e + seg, 0x0002, memoryAGet16(0x104e + seg, 0x0002) + seg); // 3170 -> 335d; lin=104e2
        memoryASet16(0x104e + seg, 0x0006, memoryAGet16(0x104e + seg, 0x0006) + seg); // 3170 -> 335d; lin=104e6
        memoryASet16(0x104e + seg, 0x000a, memoryAGet16(0x104e + seg, 0x000a) + seg); // 3170 -> 335d; lin=104ea
        memoryASet16(0x104e + seg, 0x000e, memoryAGet16(0x104e + seg, 0x000e) + seg); // 3170 -> 335d; lin=104ee
        memoryASet16(0x104f + seg, 0x0002, memoryAGet16(0x104f + seg, 0x0002) + seg); // 3170 -> 335d; lin=104f2
        memoryASet16(0x104f + seg, 0x0006, memoryAGet16(0x104f + seg, 0x0006) + seg); // 3170 -> 335d; lin=104f6
        memoryASet16(0x104f + seg, 0x000a, memoryAGet16(0x104f + seg, 0x000a) + seg); // 3170 -> 335d; lin=104fa
        memoryASet16(0x104f + seg, 0x000e, memoryAGet16(0x104f + seg, 0x000e) + seg); // 3170 -> 335d; lin=104fe
        memoryASet16(0x1050 + seg, 0x0002, memoryAGet16(0x1050 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10502
        memoryASet16(0x1050 + seg, 0x0006, memoryAGet16(0x1050 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10506
        memoryASet16(0x1050 + seg, 0x000a, memoryAGet16(0x1050 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1050a
        memoryASet16(0x1050 + seg, 0x000e, memoryAGet16(0x1050 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1050e
        memoryASet16(0x1051 + seg, 0x0002, memoryAGet16(0x1051 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10512
        memoryASet16(0x1051 + seg, 0x0006, memoryAGet16(0x1051 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10516
        memoryASet16(0x1051 + seg, 0x000a, memoryAGet16(0x1051 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1051a
        memoryASet16(0x1051 + seg, 0x000e, memoryAGet16(0x1051 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1051e
        memoryASet16(0x1052 + seg, 0x0002, memoryAGet16(0x1052 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10522
        memoryASet16(0x1052 + seg, 0x0008, memoryAGet16(0x1052 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10528
        memoryASet16(0x1052 + seg, 0x000c, memoryAGet16(0x1052 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1052c
        memoryASet16(0x1053 + seg, 0x0000, memoryAGet16(0x1053 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10530
        memoryASet16(0x1053 + seg, 0x0004, memoryAGet16(0x1053 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10534
        memoryASet16(0x1053 + seg, 0x0008, memoryAGet16(0x1053 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10538
        memoryASet16(0x1053 + seg, 0x000c, memoryAGet16(0x1053 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1053c
        memoryASet16(0x1054 + seg, 0x0000, memoryAGet16(0x1054 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10540
        memoryASet16(0x1054 + seg, 0x0004, memoryAGet16(0x1054 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10544
        memoryASet16(0x1054 + seg, 0x0008, memoryAGet16(0x1054 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10548
        memoryASet16(0x1054 + seg, 0x000c, memoryAGet16(0x1054 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1054c
        memoryASet16(0x1055 + seg, 0x0000, memoryAGet16(0x1055 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10550
        memoryASet16(0x1055 + seg, 0x0004, memoryAGet16(0x1055 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10554
        memoryASet16(0x1055 + seg, 0x0008, memoryAGet16(0x1055 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10558
        memoryASet16(0x1055 + seg, 0x000c, memoryAGet16(0x1055 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1055c
        memoryASet16(0x1056 + seg, 0x0000, memoryAGet16(0x1056 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10560
        memoryASet16(0x1056 + seg, 0x0004, memoryAGet16(0x1056 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10564
        memoryASet16(0x1056 + seg, 0x000a, memoryAGet16(0x1056 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1056a
        memoryASet16(0x1056 + seg, 0x000e, memoryAGet16(0x1056 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1056e
        memoryASet16(0x1057 + seg, 0x0002, memoryAGet16(0x1057 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10572
        memoryASet16(0x1057 + seg, 0x0006, memoryAGet16(0x1057 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10576
        memoryASet16(0x1057 + seg, 0x000a, memoryAGet16(0x1057 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1057a
        memoryASet16(0x1057 + seg, 0x000e, memoryAGet16(0x1057 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1057e
        memoryASet16(0x1058 + seg, 0x0002, memoryAGet16(0x1058 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10582
        memoryASet16(0x1058 + seg, 0x0006, memoryAGet16(0x1058 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10586
        memoryASet16(0x1058 + seg, 0x000a, memoryAGet16(0x1058 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1058a
        memoryASet16(0x1058 + seg, 0x000e, memoryAGet16(0x1058 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1058e
        memoryASet16(0x1059 + seg, 0x0002, memoryAGet16(0x1059 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10592
        memoryASet16(0x1059 + seg, 0x0006, memoryAGet16(0x1059 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10596
        memoryASet16(0x1059 + seg, 0x000a, memoryAGet16(0x1059 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1059a
        memoryASet16(0x1059 + seg, 0x000e, memoryAGet16(0x1059 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1059e
        memoryASet16(0x105a + seg, 0x0002, memoryAGet16(0x105a + seg, 0x0002) + seg); // 3170 -> 335d; lin=105a2
        memoryASet16(0x105a + seg, 0x0006, memoryAGet16(0x105a + seg, 0x0006) + seg); // 3170 -> 335d; lin=105a6
        memoryASet16(0x105a + seg, 0x000c, memoryAGet16(0x105a + seg, 0x000c) + seg); // 3170 -> 335d; lin=105ac
        memoryASet16(0x105b + seg, 0x0000, memoryAGet16(0x105b + seg, 0x0000) + seg); // 3170 -> 335d; lin=105b0
        memoryASet16(0x105b + seg, 0x0004, memoryAGet16(0x105b + seg, 0x0004) + seg); // 3170 -> 335d; lin=105b4
        memoryASet16(0x105b + seg, 0x0008, memoryAGet16(0x105b + seg, 0x0008) + seg); // 3170 -> 335d; lin=105b8
        memoryASet16(0x105b + seg, 0x000c, memoryAGet16(0x105b + seg, 0x000c) + seg); // 3170 -> 335d; lin=105bc
        memoryASet16(0x105c + seg, 0x0000, memoryAGet16(0x105c + seg, 0x0000) + seg); // 3170 -> 335d; lin=105c0
        memoryASet16(0x105c + seg, 0x0004, memoryAGet16(0x105c + seg, 0x0004) + seg); // 3170 -> 335d; lin=105c4
        memoryASet16(0x105c + seg, 0x0008, memoryAGet16(0x105c + seg, 0x0008) + seg); // 3170 -> 335d; lin=105c8
        memoryASet16(0x105c + seg, 0x000c, memoryAGet16(0x105c + seg, 0x000c) + seg); // 3170 -> 335d; lin=105cc
        memoryASet16(0x105d + seg, 0x0000, memoryAGet16(0x105d + seg, 0x0000) + seg); // 3170 -> 335d; lin=105d0
        memoryASet16(0x105d + seg, 0x0004, memoryAGet16(0x105d + seg, 0x0004) + seg); // 3170 -> 335d; lin=105d4
        memoryASet16(0x105d + seg, 0x0008, memoryAGet16(0x105d + seg, 0x0008) + seg); // 3170 -> 335d; lin=105d8
        memoryASet16(0x105d + seg, 0x000c, memoryAGet16(0x105d + seg, 0x000c) + seg); // 3170 -> 335d; lin=105dc
        memoryASet16(0x105e + seg, 0x0000, memoryAGet16(0x105e + seg, 0x0000) + seg); // 3170 -> 335d; lin=105e0
        memoryASet16(0x105e + seg, 0x0004, memoryAGet16(0x105e + seg, 0x0004) + seg); // 3170 -> 335d; lin=105e4
        memoryASet16(0x105e + seg, 0x0008, memoryAGet16(0x105e + seg, 0x0008) + seg); // 3170 -> 335d; lin=105e8
        memoryASet16(0x105e + seg, 0x000e, memoryAGet16(0x105e + seg, 0x000e) + seg); // 3170 -> 335d; lin=105ee
        memoryASet16(0x105f + seg, 0x0002, memoryAGet16(0x105f + seg, 0x0002) + seg); // 3170 -> 335d; lin=105f2
        memoryASet16(0x105f + seg, 0x0006, memoryAGet16(0x105f + seg, 0x0006) + seg); // 3170 -> 335d; lin=105f6
        memoryASet16(0x105f + seg, 0x000a, memoryAGet16(0x105f + seg, 0x000a) + seg); // 3170 -> 335d; lin=105fa
        memoryASet16(0x105f + seg, 0x000e, memoryAGet16(0x105f + seg, 0x000e) + seg); // 3170 -> 335d; lin=105fe
        memoryASet16(0x1060 + seg, 0x0002, memoryAGet16(0x1060 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10602
        memoryASet16(0x1060 + seg, 0x0006, memoryAGet16(0x1060 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10606
        memoryASet16(0x1060 + seg, 0x000a, memoryAGet16(0x1060 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1060a
        memoryASet16(0x1060 + seg, 0x000e, memoryAGet16(0x1060 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1060e
        memoryASet16(0x1061 + seg, 0x0002, memoryAGet16(0x1061 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10612
        memoryASet16(0x1061 + seg, 0x0006, memoryAGet16(0x1061 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10616
        memoryASet16(0x1061 + seg, 0x000a, memoryAGet16(0x1061 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1061a
        memoryASet16(0x1061 + seg, 0x000e, memoryAGet16(0x1061 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1061e
        memoryASet16(0x1062 + seg, 0x0002, memoryAGet16(0x1062 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10622
        memoryASet16(0x1062 + seg, 0x0006, memoryAGet16(0x1062 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10626
        memoryASet16(0x1062 + seg, 0x000a, memoryAGet16(0x1062 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1062a
        memoryASet16(0x1063 + seg, 0x0000, memoryAGet16(0x1063 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10630
        memoryASet16(0x1063 + seg, 0x0004, memoryAGet16(0x1063 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10634
        memoryASet16(0x1063 + seg, 0x0008, memoryAGet16(0x1063 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10638
        memoryASet16(0x1063 + seg, 0x000c, memoryAGet16(0x1063 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1063c
        memoryASet16(0x1064 + seg, 0x0000, memoryAGet16(0x1064 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10640
        memoryASet16(0x1064 + seg, 0x0004, memoryAGet16(0x1064 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10644
        memoryASet16(0x1064 + seg, 0x0008, memoryAGet16(0x1064 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10648
        memoryASet16(0x1064 + seg, 0x000c, memoryAGet16(0x1064 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1064c
        memoryASet16(0x1065 + seg, 0x0000, memoryAGet16(0x1065 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10650
        memoryASet16(0x1065 + seg, 0x0004, memoryAGet16(0x1065 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10654
        memoryASet16(0x1065 + seg, 0x0008, memoryAGet16(0x1065 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10658
        memoryASet16(0x1065 + seg, 0x000c, memoryAGet16(0x1065 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1065c
        memoryASet16(0x1066 + seg, 0x0000, memoryAGet16(0x1066 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10660
        memoryASet16(0x1066 + seg, 0x0004, memoryAGet16(0x1066 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10664
        memoryASet16(0x1066 + seg, 0x0008, memoryAGet16(0x1066 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10668
        memoryASet16(0x1066 + seg, 0x000c, memoryAGet16(0x1066 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1066c
        memoryASet16(0x106f + seg, 0x0004, memoryAGet16(0x106f + seg, 0x0004) + seg); // 50b0 -> 529d; lin=106f4
        memoryASet16(0x106f + seg, 0x0008, memoryAGet16(0x106f + seg, 0x0008) + seg); // 50b0 -> 529d; lin=106f8
        memoryASet16(0x106f + seg, 0x000c, memoryAGet16(0x106f + seg, 0x000c) + seg); // 50b0 -> 529d; lin=106fc
        memoryASet16(0x1070 + seg, 0x0000, memoryAGet16(0x1070 + seg, 0x0000) + seg); // 50b0 -> 529d; lin=10700
        memoryASet16(0x1070 + seg, 0x0004, memoryAGet16(0x1070 + seg, 0x0004) + seg); // 50b0 -> 529d; lin=10704
        memoryASet16(0x1070 + seg, 0x0008, memoryAGet16(0x1070 + seg, 0x0008) + seg); // 50b0 -> 529d; lin=10708
        memoryASet16(0x1070 + seg, 0x000c, memoryAGet16(0x1070 + seg, 0x000c) + seg); // 50b0 -> 529d; lin=1070c
        memoryASet16(0x1071 + seg, 0x0000, memoryAGet16(0x1071 + seg, 0x0000) + seg); // 50b0 -> 529d; lin=10710
        memoryASet16(0x1071 + seg, 0x0004, memoryAGet16(0x1071 + seg, 0x0004) + seg); // 50b0 -> 529d; lin=10714
        memoryASet16(0x1071 + seg, 0x0008, memoryAGet16(0x1071 + seg, 0x0008) + seg); // 50b0 -> 529d; lin=10718
        memoryASet16(0x1071 + seg, 0x000c, memoryAGet16(0x1071 + seg, 0x000c) + seg); // 50b0 -> 529d; lin=1071c
        memoryASet16(0x1072 + seg, 0x0000, memoryAGet16(0x1072 + seg, 0x0000) + seg); // 50b0 -> 529d; lin=10720
        memoryASet16(0x1072 + seg, 0x0004, memoryAGet16(0x1072 + seg, 0x0004) + seg); // 50b0 -> 529d; lin=10724
        memoryASet16(0x1072 + seg, 0x0008, memoryAGet16(0x1072 + seg, 0x0008) + seg); // 50b0 -> 529d; lin=10728
        memoryASet16(0x1072 + seg, 0x000c, memoryAGet16(0x1072 + seg, 0x000c) + seg); // 50b0 -> 529d; lin=1072c
        memoryASet16(0x1072 + seg, 0x000e, memoryAGet16(0x1072 + seg, 0x000e) + seg); // 5b9b -> 5d88; lin=1072e
        memoryASet16(0x1073 + seg, 0x0002, memoryAGet16(0x1073 + seg, 0x0002) + seg); // 5b9b -> 5d88; lin=10732
        memoryASet16(0x1073 + seg, 0x0006, memoryAGet16(0x1073 + seg, 0x0006) + seg); // 5b9b -> 5d88; lin=10736
        memoryASet16(0x1073 + seg, 0x000a, memoryAGet16(0x1073 + seg, 0x000a) + seg); // 5b9b -> 5d88; lin=1073a
        memoryASet16(0x1073 + seg, 0x000e, memoryAGet16(0x1073 + seg, 0x000e) + seg); // 5b9b -> 5d88; lin=1073e
        memoryASet16(0x1074 + seg, 0x0004, memoryAGet16(0x1074 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10744
        memoryASet16(0x1074 + seg, 0x0008, memoryAGet16(0x1074 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10748
        memoryASet16(0x1074 + seg, 0x000c, memoryAGet16(0x1074 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1074c
        memoryASet16(0x1075 + seg, 0x0000, memoryAGet16(0x1075 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10750
        memoryASet16(0x1075 + seg, 0x0004, memoryAGet16(0x1075 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10754
        memoryASet16(0x1075 + seg, 0x0008, memoryAGet16(0x1075 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10758
        memoryASet16(0x1075 + seg, 0x000c, memoryAGet16(0x1075 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1075c
        memoryASet16(0x1076 + seg, 0x0000, memoryAGet16(0x1076 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10760
        memoryASet16(0x1076 + seg, 0x0004, memoryAGet16(0x1076 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10764
        memoryASet16(0x1076 + seg, 0x0008, memoryAGet16(0x1076 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10768
        memoryASet16(0x1076 + seg, 0x000c, memoryAGet16(0x1076 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1076c
        memoryASet16(0x1077 + seg, 0x0000, memoryAGet16(0x1077 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10770
        memoryASet16(0x1077 + seg, 0x0004, memoryAGet16(0x1077 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10774
        memoryASet16(0x1077 + seg, 0x0008, memoryAGet16(0x1077 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10778
        memoryASet16(0x1077 + seg, 0x000c, memoryAGet16(0x1077 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1077c
        memoryASet16(0x1078 + seg, 0x0000, memoryAGet16(0x1078 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10780
        memoryASet16(0x1078 + seg, 0x0004, memoryAGet16(0x1078 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10784
        memoryASet16(0x1078 + seg, 0x0008, memoryAGet16(0x1078 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10788
        memoryASet16(0x1078 + seg, 0x000c, memoryAGet16(0x1078 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1078c
        memoryASet16(0x1079 + seg, 0x0000, memoryAGet16(0x1079 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10790
        memoryASet16(0x1079 + seg, 0x0004, memoryAGet16(0x1079 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10794
        memoryASet16(0x1079 + seg, 0x0008, memoryAGet16(0x1079 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10798
        memoryASet16(0x1079 + seg, 0x000c, memoryAGet16(0x1079 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1079c
        memoryASet16(0x107a + seg, 0x0000, memoryAGet16(0x107a + seg, 0x0000) + seg); // 3170 -> 335d; lin=107a0
        memoryASet16(0x107a + seg, 0x0004, memoryAGet16(0x107a + seg, 0x0004) + seg); // 3170 -> 335d; lin=107a4
        memoryASet16(0x107a + seg, 0x0008, memoryAGet16(0x107a + seg, 0x0008) + seg); // 3170 -> 335d; lin=107a8
        memoryASet16(0x107a + seg, 0x000c, memoryAGet16(0x107a + seg, 0x000c) + seg); // 3170 -> 335d; lin=107ac
        memoryASet16(0x107b + seg, 0x0000, memoryAGet16(0x107b + seg, 0x0000) + seg); // 3170 -> 335d; lin=107b0
        memoryASet16(0x107b + seg, 0x0004, memoryAGet16(0x107b + seg, 0x0004) + seg); // 3170 -> 335d; lin=107b4
        memoryASet16(0x107b + seg, 0x0008, memoryAGet16(0x107b + seg, 0x0008) + seg); // 3170 -> 335d; lin=107b8
        memoryASet16(0x107b + seg, 0x000c, memoryAGet16(0x107b + seg, 0x000c) + seg); // 3170 -> 335d; lin=107bc
        memoryASet16(0x107c + seg, 0x0000, memoryAGet16(0x107c + seg, 0x0000) + seg); // 3170 -> 335d; lin=107c0
        memoryASet16(0x107c + seg, 0x0004, memoryAGet16(0x107c + seg, 0x0004) + seg); // 3170 -> 335d; lin=107c4
        memoryASet16(0x107c + seg, 0x0008, memoryAGet16(0x107c + seg, 0x0008) + seg); // 3170 -> 335d; lin=107c8
        memoryASet16(0x107c + seg, 0x000c, memoryAGet16(0x107c + seg, 0x000c) + seg); // 3170 -> 335d; lin=107cc
        memoryASet16(0x107d + seg, 0x0000, memoryAGet16(0x107d + seg, 0x0000) + seg); // 3170 -> 335d; lin=107d0
        memoryASet16(0x107d + seg, 0x0004, memoryAGet16(0x107d + seg, 0x0004) + seg); // 3170 -> 335d; lin=107d4
        memoryASet16(0x107d + seg, 0x0008, memoryAGet16(0x107d + seg, 0x0008) + seg); // 3170 -> 335d; lin=107d8
        memoryASet16(0x107d + seg, 0x000c, memoryAGet16(0x107d + seg, 0x000c) + seg); // 3170 -> 335d; lin=107dc
        memoryASet16(0x107e + seg, 0x0000, memoryAGet16(0x107e + seg, 0x0000) + seg); // 3170 -> 335d; lin=107e0
        memoryASet16(0x107e + seg, 0x0004, memoryAGet16(0x107e + seg, 0x0004) + seg); // 3170 -> 335d; lin=107e4
        memoryASet16(0x107e + seg, 0x0008, memoryAGet16(0x107e + seg, 0x0008) + seg); // 3170 -> 335d; lin=107e8
        memoryASet16(0x107e + seg, 0x000c, memoryAGet16(0x107e + seg, 0x000c) + seg); // 3170 -> 335d; lin=107ec
        memoryASet16(0x107f + seg, 0x0000, memoryAGet16(0x107f + seg, 0x0000) + seg); // 3170 -> 335d; lin=107f0
        memoryASet16(0x107f + seg, 0x0004, memoryAGet16(0x107f + seg, 0x0004) + seg); // 3170 -> 335d; lin=107f4
        memoryASet16(0x107f + seg, 0x0008, memoryAGet16(0x107f + seg, 0x0008) + seg); // 3170 -> 335d; lin=107f8
        memoryASet16(0x107f + seg, 0x000c, memoryAGet16(0x107f + seg, 0x000c) + seg); // 3170 -> 335d; lin=107fc
        memoryASet16(0x1080 + seg, 0x0000, memoryAGet16(0x1080 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10800
        memoryASet16(0x1080 + seg, 0x0004, memoryAGet16(0x1080 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10804
        memoryASet16(0x1080 + seg, 0x0008, memoryAGet16(0x1080 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10808
        memoryASet16(0x1080 + seg, 0x000c, memoryAGet16(0x1080 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1080c
        memoryASet16(0x1081 + seg, 0x0000, memoryAGet16(0x1081 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10810
        memoryASet16(0x1081 + seg, 0x0006, memoryAGet16(0x1081 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10816
        memoryASet16(0x1081 + seg, 0x000a, memoryAGet16(0x1081 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1081a
        memoryASet16(0x1081 + seg, 0x000e, memoryAGet16(0x1081 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1081e
        memoryASet16(0x1082 + seg, 0x0002, memoryAGet16(0x1082 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10822
        memoryASet16(0x1082 + seg, 0x0006, memoryAGet16(0x1082 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10826
        memoryASet16(0x1082 + seg, 0x000a, memoryAGet16(0x1082 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1082a
        memoryASet16(0x1082 + seg, 0x000e, memoryAGet16(0x1082 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1082e
        memoryASet16(0x1083 + seg, 0x0002, memoryAGet16(0x1083 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10832
        memoryASet16(0x1083 + seg, 0x0006, memoryAGet16(0x1083 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10836
        memoryASet16(0x1083 + seg, 0x000c, memoryAGet16(0x1083 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1083c
        memoryASet16(0x1084 + seg, 0x0000, memoryAGet16(0x1084 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10840
        memoryASet16(0x1084 + seg, 0x0004, memoryAGet16(0x1084 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10844
        memoryASet16(0x1084 + seg, 0x0008, memoryAGet16(0x1084 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10848
        memoryASet16(0x1084 + seg, 0x000e, memoryAGet16(0x1084 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1084e
        memoryASet16(0x1085 + seg, 0x0002, memoryAGet16(0x1085 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10852
        memoryASet16(0x1085 + seg, 0x0006, memoryAGet16(0x1085 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10856
        memoryASet16(0x1085 + seg, 0x000a, memoryAGet16(0x1085 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1085a
        memoryASet16(0x1085 + seg, 0x000e, memoryAGet16(0x1085 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1085e
        memoryASet16(0x1086 + seg, 0x0002, memoryAGet16(0x1086 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10862
        memoryASet16(0x1086 + seg, 0x0006, memoryAGet16(0x1086 + seg, 0x0006) + seg); // 3170 -> 335d; lin=10866
        memoryASet16(0x1086 + seg, 0x000a, memoryAGet16(0x1086 + seg, 0x000a) + seg); // 3170 -> 335d; lin=1086a
        memoryASet16(0x1086 + seg, 0x000e, memoryAGet16(0x1086 + seg, 0x000e) + seg); // 3170 -> 335d; lin=1086e
        memoryASet16(0x1087 + seg, 0x0002, memoryAGet16(0x1087 + seg, 0x0002) + seg); // 3170 -> 335d; lin=10872
        memoryASet16(0x1087 + seg, 0x0008, memoryAGet16(0x1087 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10878
        memoryASet16(0x1087 + seg, 0x000c, memoryAGet16(0x1087 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1087c
        memoryASet16(0x1088 + seg, 0x0000, memoryAGet16(0x1088 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10880
        memoryASet16(0x1088 + seg, 0x0004, memoryAGet16(0x1088 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10884
        memoryASet16(0x1088 + seg, 0x0008, memoryAGet16(0x1088 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10888
        memoryASet16(0x1088 + seg, 0x000c, memoryAGet16(0x1088 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1088c
        memoryASet16(0x1089 + seg, 0x0000, memoryAGet16(0x1089 + seg, 0x0000) + seg); // 3170 -> 335d; lin=10890
        memoryASet16(0x1089 + seg, 0x0004, memoryAGet16(0x1089 + seg, 0x0004) + seg); // 3170 -> 335d; lin=10894
        memoryASet16(0x1089 + seg, 0x0008, memoryAGet16(0x1089 + seg, 0x0008) + seg); // 3170 -> 335d; lin=10898
        memoryASet16(0x1089 + seg, 0x000c, memoryAGet16(0x1089 + seg, 0x000c) + seg); // 3170 -> 335d; lin=1089c
        memoryASet16(0x108a + seg, 0x0002, memoryAGet16(0x108a + seg, 0x0002) + seg); // 3170 -> 335d; lin=108a2
        memoryASet16(0x108a + seg, 0x0006, memoryAGet16(0x108a + seg, 0x0006) + seg); // 3170 -> 335d; lin=108a6
        memoryASet16(0x108a + seg, 0x000a, memoryAGet16(0x108a + seg, 0x000a) + seg); // 3170 -> 335d; lin=108aa
        memoryASet16(0x108a + seg, 0x000e, memoryAGet16(0x108a + seg, 0x000e) + seg); // 3170 -> 335d; lin=108ae
        memoryASet16(0x108b + seg, 0x0002, memoryAGet16(0x108b + seg, 0x0002) + seg); // 3170 -> 335d; lin=108b2
        memoryASet16(0x108b + seg, 0x0006, memoryAGet16(0x108b + seg, 0x0006) + seg); // 3170 -> 335d; lin=108b6
        memoryASet16(0x108b + seg, 0x000a, memoryAGet16(0x108b + seg, 0x000a) + seg); // 3170 -> 335d; lin=108ba
        memoryASet16(0x108b + seg, 0x000e, memoryAGet16(0x108b + seg, 0x000e) + seg); // 3170 -> 335d; lin=108be
        memoryASet16(0x108c + seg, 0x0002, memoryAGet16(0x108c + seg, 0x0002) + seg); // 3170 -> 335d; lin=108c2
        memoryASet16(0x108c + seg, 0x0006, memoryAGet16(0x108c + seg, 0x0006) + seg); // 3170 -> 335d; lin=108c6
        memoryASet16(0x108c + seg, 0x000c, memoryAGet16(0x108c + seg, 0x000c) + seg); // 3170 -> 335d; lin=108cc
        memoryASet16(0x108d + seg, 0x0000, memoryAGet16(0x108d + seg, 0x0000) + seg); // 3170 -> 335d; lin=108d0
        memoryASet16(0x108d + seg, 0x0004, memoryAGet16(0x108d + seg, 0x0004) + seg); // 3170 -> 335d; lin=108d4
        memoryASet16(0x108d + seg, 0x0008, memoryAGet16(0x108d + seg, 0x0008) + seg); // 3170 -> 335d; lin=108d8
        memoryASet16(0x108d + seg, 0x000c, memoryAGet16(0x108d + seg, 0x000c) + seg); // 3170 -> 335d; lin=108dc
        memoryASet16(0x108e + seg, 0x0000, memoryAGet16(0x108e + seg, 0x0000) + seg); // 3170 -> 335d; lin=108e0
        memoryASet16(0x108e + seg, 0x0004, memoryAGet16(0x108e + seg, 0x0004) + seg); // 3170 -> 335d; lin=108e4
        memoryASet16(0x108e + seg, 0x0008, memoryAGet16(0x108e + seg, 0x0008) + seg); // 3170 -> 335d; lin=108e8
        memoryASet16(0x108e + seg, 0x000c, memoryAGet16(0x108e + seg, 0x000c) + seg); // 3170 -> 335d; lin=108ec
        memoryASet16(0x108f + seg, 0x0000, memoryAGet16(0x108f + seg, 0x0000) + seg); // 3170 -> 335d; lin=108f0
        memoryASet16(0x1091 + seg, 0x0004, memoryAGet16(0x1091 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=10914
        memoryASet16(0x1091 + seg, 0x0008, memoryAGet16(0x1091 + seg, 0x0008) + seg); // 2403 -> 25f0; lin=10918
        memoryASet16(0x1093 + seg, 0x000a, memoryAGet16(0x1093 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=1093a
        memoryASet16(0x1093 + seg, 0x000e, memoryAGet16(0x1093 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=1093e
        memoryASet16(0x1096 + seg, 0x0000, memoryAGet16(0x1096 + seg, 0x0000) + seg); // 2403 -> 25f0; lin=10960
        memoryASet16(0x1096 + seg, 0x0004, memoryAGet16(0x1096 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=10964
        memoryASet16(0x1098 + seg, 0x0006, memoryAGet16(0x1098 + seg, 0x0006) + seg); // 2403 -> 25f0; lin=10986
        memoryASet16(0x1098 + seg, 0x000a, memoryAGet16(0x1098 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=1098a
        memoryASet16(0x109a + seg, 0x000c, memoryAGet16(0x109a + seg, 0x000c) + seg); // 2403 -> 25f0; lin=109ac
        memoryASet16(0x109b + seg, 0x0000, memoryAGet16(0x109b + seg, 0x0000) + seg); // 2403 -> 25f0; lin=109b0
        memoryASet16(0x109d + seg, 0x0002, memoryAGet16(0x109d + seg, 0x0002) + seg); // 2403 -> 25f0; lin=109d2
        memoryASet16(0x109d + seg, 0x0006, memoryAGet16(0x109d + seg, 0x0006) + seg); // 2403 -> 25f0; lin=109d6
        memoryASet16(0x109f + seg, 0x0008, memoryAGet16(0x109f + seg, 0x0008) + seg); // 2403 -> 25f0; lin=109f8
        memoryASet16(0x109f + seg, 0x000c, memoryAGet16(0x109f + seg, 0x000c) + seg); // 2403 -> 25f0; lin=109fc
        memoryASet16(0x10a1 + seg, 0x000e, memoryAGet16(0x10a1 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=10a1e
        memoryASet16(0x10a2 + seg, 0x0002, memoryAGet16(0x10a2 + seg, 0x0002) + seg); // 2403 -> 25f0; lin=10a22
        memoryASet16(0x10a4 + seg, 0x0004, memoryAGet16(0x10a4 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=10a44
        memoryASet16(0x10a4 + seg, 0x0008, memoryAGet16(0x10a4 + seg, 0x0008) + seg); // 2403 -> 25f0; lin=10a48
        memoryASet16(0x10a6 + seg, 0x000a, memoryAGet16(0x10a6 + seg, 0x000a) + seg); // 2403 -> 25f0; lin=10a6a
        memoryASet16(0x10a6 + seg, 0x000e, memoryAGet16(0x10a6 + seg, 0x000e) + seg); // 2403 -> 25f0; lin=10a6e
        memoryASet16(0x10a9 + seg, 0x0000, memoryAGet16(0x10a9 + seg, 0x0000) + seg); // 2403 -> 25f0; lin=10a90
        memoryASet16(0x10a9 + seg, 0x0004, memoryAGet16(0x10a9 + seg, 0x0004) + seg); // 2403 -> 25f0; lin=10a94
        memoryASet16(0x10ab + seg, 0x0006, memoryAGet16(0x10ab + seg, 0x0006) + seg); // 2403 -> 25f0; lin=10ab6
        memoryASet16(0x10ab + seg, 0x000a, memoryAGet16(0x10ab + seg, 0x000a) + seg); // 2403 -> 25f0; lin=10aba
        memoryASet16(0x10ad + seg, 0x0000, memoryAGet16(0x10ad + seg, 0x0000) + seg); // 1463 -> 1650; lin=10ad0
        memoryASet16(0x10ad + seg, 0x0008, memoryAGet16(0x10ad + seg, 0x0008) + seg); // 1463 -> 1650; lin=10ad8
        memoryASet16(0x10ae + seg, 0x0000, memoryAGet16(0x10ae + seg, 0x0000) + seg); // 1463 -> 1650; lin=10ae0
        memoryASet16(0x10ae + seg, 0x0008, memoryAGet16(0x10ae + seg, 0x0008) + seg); // 1463 -> 1650; lin=10ae8
        memoryASet16(0x10af + seg, 0x0000, memoryAGet16(0x10af + seg, 0x0000) + seg); // 1463 -> 1650; lin=10af0
        memoryASet16(0x10af + seg, 0x0008, memoryAGet16(0x10af + seg, 0x0008) + seg); // 1463 -> 1650; lin=10af8
        memoryASet16(0x10b0 + seg, 0x0000, memoryAGet16(0x10b0 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b00
        memoryASet16(0x10b0 + seg, 0x0008, memoryAGet16(0x10b0 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b08
        memoryASet16(0x10b1 + seg, 0x0000, memoryAGet16(0x10b1 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b10
        memoryASet16(0x10b1 + seg, 0x0008, memoryAGet16(0x10b1 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b18
        memoryASet16(0x10b2 + seg, 0x0000, memoryAGet16(0x10b2 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b20
        memoryASet16(0x10b2 + seg, 0x0008, memoryAGet16(0x10b2 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b28
        memoryASet16(0x10b3 + seg, 0x0000, memoryAGet16(0x10b3 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b30
        memoryASet16(0x10b3 + seg, 0x0008, memoryAGet16(0x10b3 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b38
        memoryASet16(0x10b4 + seg, 0x0000, memoryAGet16(0x10b4 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b40
        memoryASet16(0x10b4 + seg, 0x0008, memoryAGet16(0x10b4 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b48
        memoryASet16(0x10b5 + seg, 0x0000, memoryAGet16(0x10b5 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b50
        memoryASet16(0x10b5 + seg, 0x0008, memoryAGet16(0x10b5 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b58
        memoryASet16(0x10b6 + seg, 0x0000, memoryAGet16(0x10b6 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b60
        memoryASet16(0x10b6 + seg, 0x0008, memoryAGet16(0x10b6 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b68
        memoryASet16(0x10b7 + seg, 0x0000, memoryAGet16(0x10b7 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b70
        memoryASet16(0x10b7 + seg, 0x0008, memoryAGet16(0x10b7 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b78
        memoryASet16(0x10b8 + seg, 0x0000, memoryAGet16(0x10b8 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b80
        memoryASet16(0x10b8 + seg, 0x0008, memoryAGet16(0x10b8 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b88
        memoryASet16(0x10b9 + seg, 0x0000, memoryAGet16(0x10b9 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10b90
        memoryASet16(0x10b9 + seg, 0x0008, memoryAGet16(0x10b9 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10b98
        memoryASet16(0x10ba + seg, 0x0000, memoryAGet16(0x10ba + seg, 0x0000) + seg); // 1463 -> 1650; lin=10ba0
        memoryASet16(0x10ba + seg, 0x0008, memoryAGet16(0x10ba + seg, 0x0008) + seg); // 1463 -> 1650; lin=10ba8
        memoryASet16(0x10bb + seg, 0x0000, memoryAGet16(0x10bb + seg, 0x0000) + seg); // 1463 -> 1650; lin=10bb0
        memoryASet16(0x10bb + seg, 0x0008, memoryAGet16(0x10bb + seg, 0x0008) + seg); // 1463 -> 1650; lin=10bb8
        memoryASet16(0x10bc + seg, 0x0000, memoryAGet16(0x10bc + seg, 0x0000) + seg); // 1463 -> 1650; lin=10bc0
        memoryASet16(0x10bc + seg, 0x0008, memoryAGet16(0x10bc + seg, 0x0008) + seg); // 1463 -> 1650; lin=10bc8
        memoryASet16(0x10bd + seg, 0x0000, memoryAGet16(0x10bd + seg, 0x0000) + seg); // 1463 -> 1650; lin=10bd0
        memoryASet16(0x10bd + seg, 0x0008, memoryAGet16(0x10bd + seg, 0x0008) + seg); // 1463 -> 1650; lin=10bd8
        memoryASet16(0x10be + seg, 0x0000, memoryAGet16(0x10be + seg, 0x0000) + seg); // 1463 -> 1650; lin=10be0
        memoryASet16(0x10be + seg, 0x0008, memoryAGet16(0x10be + seg, 0x0008) + seg); // 1463 -> 1650; lin=10be8
        memoryASet16(0x10bf + seg, 0x0000, memoryAGet16(0x10bf + seg, 0x0000) + seg); // 1463 -> 1650; lin=10bf0
        memoryASet16(0x10bf + seg, 0x0008, memoryAGet16(0x10bf + seg, 0x0008) + seg); // 1463 -> 1650; lin=10bf8
        memoryASet16(0x10c0 + seg, 0x0000, memoryAGet16(0x10c0 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c00
        memoryASet16(0x10c0 + seg, 0x0008, memoryAGet16(0x10c0 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c08
        memoryASet16(0x10c1 + seg, 0x0000, memoryAGet16(0x10c1 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c10
        memoryASet16(0x10c1 + seg, 0x0008, memoryAGet16(0x10c1 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c18
        memoryASet16(0x10c2 + seg, 0x0000, memoryAGet16(0x10c2 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c20
        memoryASet16(0x10c2 + seg, 0x0008, memoryAGet16(0x10c2 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c28
        memoryASet16(0x10c3 + seg, 0x0000, memoryAGet16(0x10c3 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c30
        memoryASet16(0x10c3 + seg, 0x0008, memoryAGet16(0x10c3 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c38
        memoryASet16(0x10c4 + seg, 0x0000, memoryAGet16(0x10c4 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c40
        memoryASet16(0x10c4 + seg, 0x0008, memoryAGet16(0x10c4 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c48
        memoryASet16(0x10c5 + seg, 0x0000, memoryAGet16(0x10c5 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c50
        memoryASet16(0x10c5 + seg, 0x0008, memoryAGet16(0x10c5 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c58
        memoryASet16(0x10c6 + seg, 0x0000, memoryAGet16(0x10c6 + seg, 0x0000) + seg); // 1463 -> 1650; lin=10c60
        memoryASet16(0x10c6 + seg, 0x0008, memoryAGet16(0x10c6 + seg, 0x0008) + seg); // 1463 -> 1650; lin=10c68
}


