#include "cico16.h"

void fixReloc(uint16_t seg);
void sub_1ed0();

void indirectCall(int, int) { stop(); }

void init()
{
    headerSize = 0x1200;
    loadAddress = 0x01ed;
    endAddress = 0x1d8d;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1c49;
    sp = 0x0080;
    load("bumpy.zip", "BUMPY.EXE", 112720);
    fixReloc(loadAddress);
}

void start()
{
    sub_1ed0();
}


void sub_1ed0();
void sub_1fc6();
void sub_1fcf();
void sub_1fe5();
void sub_1fff();
void sub_2042();
void sub_206f();
void sub_20b2();
void sub_20d3();
void sub_2128();
void sub_2152();
void sub_22ba();
void sub_22e6();
void sub_2439();
void sub_24b7();
void sub_24d4();
void sub_250b();
void sub_26c0();
void sub_26e6();
void sub_27a1();
void sub_28d7();
void sub_2960();
void sub_2a58();
void sub_2ac9();
void sub_2ae8();
void sub_2c6d();
void sub_2e4a();
void sub_30bb();
void sub_3219();
void sub_325c();
void sub_3282();
void sub_32af();
void sub_3343();
void sub_33b4();
void sub_3471();
void sub_352e();
void sub_3697();
void sub_3871();
void sub_38b4();
void sub_38f0();
void sub_3937();
void sub_39fb();
void sub_3aa7();
void sub_3b11();
void sub_3b82();
void sub_3bba();
void sub_3bf6();
void sub_3cae();
void sub_3cd2();
void sub_3d0d();
void sub_3d2e();
void sub_3d60();
void sub_3d92();
void sub_3dd3();
void sub_3e0e();
void sub_3e4f();
void sub_3e8e();
void sub_3f4d();
void sub_4008();
void sub_408b();
void sub_40b7();
void sub_4131();
void sub_415d();
void sub_4180();
void sub_4191();
void sub_41a2();
void sub_41cc();
void sub_420a();
void sub_423f();
void sub_425e();
void sub_4286();
void sub_42f3();
void sub_4340();
void sub_435e();
void sub_43a7();
void sub_43da();
void sub_440f();
void sub_447d();
void sub_4504();
void sub_4571();
void sub_45dc();
void sub_4646();
void sub_46ae();
void sub_46e0();
void sub_47b0();
void sub_47c9();
void sub_4835();
void sub_4876();
void sub_48da();
void sub_4948();
void sub_4be4();
void sub_4dc8();
void sub_4e7c();
void sub_4fad();
void sub_50ae();
void sub_515f();
void sub_5180();
void sub_5295();
void sub_5337();
void sub_5475();
void sub_5722();
void sub_5958();
void sub_5982();
void sub_59df();
void sub_5a3c();
void sub_5a99();
void sub_5af6();
void sub_5b1f();
void sub_5b6d();
void sub_5bc7();
void sub_5ccd();
void sub_5d44();
void sub_5d5a();
void sub_5da4();
void sub_5ee5();
void sub_6133();
void sub_61a9();
void sub_61d5();
void sub_61eb();
void sub_6214();
void sub_6231();
void sub_6268();
void sub_6285();
void sub_62a2();
void sub_62bf();
void sub_62dc();
void sub_6307();
void sub_6324();
void sub_635a();
void sub_6390();
void sub_63dc();
void sub_6402();
void sub_644a();
void sub_6470();
void sub_649f();
void sub_64d5();
void sub_650d();
void sub_652e();
void sub_654d();
void sub_656c();
void sub_658b();
void sub_65fd();
void sub_6617();
void sub_669b();
void sub_66d2();
void sub_670c();
void sub_6779();
void sub_67d6();
void sub_682c();
void sub_6865();
void sub_68a7();
void sub_6a1e();
void sub_6a96();
void sub_6ae4();
void sub_6b69();
void sub_6c8f();
void sub_6cca();
void sub_6d14();
void sub_6d4f();
void sub_6d99();
void sub_6dd4();
void sub_6e1e();
void sub_6e59();
void sub_6ea3();
void sub_6ed3();
void sub_6ef5();
void sub_6f0f();
void sub_6f29();
void sub_6f3f();
void sub_6f55();
void sub_6f90();
void sub_6fcb();
void sub_7051();
void sub_70a8();
void sub_722e();
void sub_7551();
void sub_76b1();
void sub_78a3();
void sub_7b57();
void sub_7eab();
void sub_7f0d();
void sub_8000();
void sub_8053();
void sub_816c();
void sub_81d5();
void sub_81f6();
void sub_8242();
void sub_828e();
void sub_82dc();
void sub_832d();
void sub_834e();
void sub_8391();
void sub_83b2();
void sub_83cf();
void sub_83ec();
void sub_8405();
void sub_841e();
void sub_8457();
void sub_84a2();
void sub_84b5();
void sub_84cb();
void sub_84e1();
void sub_84f7();
void sub_8518();
void sub_8569();
void sub_85a8();
void sub_85e7();
void sub_860a();
void sub_8618();
void sub_8659();
void sub_869a();
void sub_86b2();
void sub_86cb();
void sub_86e3();
void sub_8702();
void sub_871b();
void sub_873a();
void sub_8760();
void sub_878b();
void sub_87b6();
void sub_87ce();
void sub_87f2();
void sub_880a();
void sub_882e();
void sub_8857();
void sub_887a();
void sub_8959();
void sub_8a85();
void sub_8aa4();
void sub_8ac4();
void sub_8ae4();
void sub_8b65();
void sub_8bf6();
void sub_8c3a();
void sub_8c64();
void sub_8cb3();
void sub_8ce1();
void sub_8d00();
void sub_8fe1();
void sub_8ff0();
void sub_9105();
void sub_91bf();
void sub_91d7();
void sub_91e9();
void sub_923f();
void sub_932e();
void sub_93a5();
void sub_9402();
void sub_9433();
void sub_944b();
void sub_9472();
void sub_960c();
void sub_96a9();
void sub_9731();
void sub_985a();
void sub_9947();
void sub_9984();
void sub_998b();
void sub_99d1();
void sub_9a1a();
void sub_9a2a();
void sub_9a63();
void sub_9a77();
void sub_9a7d();
void sub_9a8d();
void sub_9a9a();
void sub_9aa7();
void sub_9aad();
void sub_9aca();
void sub_9bae();
void sub_9c82();
void sub_9c89();
void sub_9cc9();
void sub_9ce8();
void sub_9cef();
void sub_9d32();
void sub_9e60();
void sub_9e63();
void sub_9e66();
void sub_9e69();
void sub_9e6a();
void sub_9e80();
void sub_9f5e();
void sub_9f6e();
void sub_9f7c();
void sub_9f8c();
void sub_a485();
void sub_a4ab();
void sub_a4d0();
void sub_a4f6();
void sub_a5b9();
void sub_a5f2();
void sub_a5fe();
void sub_a60c();
void sub_a672();
void sub_a6d9();
void sub_a761();
void sub_a7b5();
void sub_a7ee();
void sub_a847();
void sub_a869();
void sub_a878();
void sub_a8b2();
void sub_a8d7();
void sub_a8f3();
void sub_a945();
void sub_a9a0();
void sub_a9c6();
void sub_a9d4();
void sub_a9dd();
void sub_a9fa();
void sub_aa3b();
void sub_aa51();
void sub_aa98();
void sub_acff();
void sub_ad18();
void sub_ad20();
void sub_ad28();
void sub_ad63();
void sub_ad73();
void sub_adbb();
void sub_ae86();
void sub_aed7();
void sub_af26();
void sub_af2d();
void sub_afe5();
void sub_b09f();
void sub_b0a7();
void sub_b0af();
void sub_b0fc();
void sub_b14c();
void sub_b274();
void sub_b281();
void sub_b288();
void sub_b298();
void sub_b2a8();
void sub_b2d6();
void sub_b2e0();
void sub_b2f4();
void sub_b2fa();
void sub_b304();
void sub_b306();
void sub_b308();
void sub_b310();
void sub_b321();
void sub_b32b();
void sub_b33e();
void sub_b358();
void sub_b3d2();
void sub_b674();
void sub_b67a();
void sub_b695();
void sub_b6a5();
void sub_b6c1();
void sub_b6d4();
void sub_b6e4();
void sub_b6f1();
void sub_b707();
void sub_b734();
void sub_b75e();
void sub_b78a();
void sub_b7ad();
void sub_b82b();
void sub_b86a();
void sub_b8d7();
void sub_b9a3();
void sub_b9e4();
void sub_ba68();
void sub_bb32();
void sub_bba3();
void sub_bcce();
void sub_be68();
void sub_be85();
void sub_bf70();
void sub_bfb9();
void sub_c01f();
void sub_c048();
void sub_c085();
void sub_c096();
void sub_c0bf();
void sub_c0da();
void sub_c0ec();
void sub_c230();
void sub_c27e();
void sub_c336();
void sub_c352();
void sub_c36e();
void sub_c3cc();
void sub_c42e();
void sub_c49f();
void sub_c4c8();
void sub_c4fe();
void sub_c527();
void sub_c588();
void sub_c5c1();
void sub_c5e4();
void sub_c7be();
void sub_c865();
void sub_c8c5();
void sub_c8e4();
void sub_c8fb();
void sub_c91e();
void sub_c9ad();
void sub_ca53();
void sub_ca60();
void sub_ca61();
void sub_ca8b();
void sub_caa7();
void sub_cbd9();
void sub_cc0e();
void sub_cc0f();
void sub_cc10();
void sub_cc41();
void sub_cc5f();
void sub_cc7b();
void sub_cc92();
void sub_cd11();
void sub_cd2e();
void sub_cdb1();
void sub_ce87();
void sub_cf8d();
void sub_d016();
void sub_d02e();
void sub_d02f();
void sub_d065();
void sub_d066();
void sub_d080();
void sub_d0ab();
void sub_d0ac();
void sub_d0ad();
void sub_d0bf();
void sub_d0c1();
void sub_d0c2();
void sub_d0d7();
void sub_d11d();
void sub_d11e();
void sub_d11f();
void sub_d121();
void sub_d250();
void sub_d283();
void sub_d2b8();
void sub_d2f2();
void sub_d37e();
void sub_d37f();
void sub_d387();
void sub_d38f();
void sub_d3a7();
void sub_d3f0();
void sub_d3f1();
void sub_d3f7();
void sub_d3f8();
void sub_d3f9();
void sub_d4d3();
void sub_d500();
void sub_d530();
void sub_d593();
void sub_d59c();
void sub_d65d();
void sub_d665();
void sub_d66d();
void sub_d69e();
void sub_d6df();
void sub_d6e0();
void sub_d6e6();
void sub_d6e7();
void sub_d6e8();
void sub_d7d7();
void sub_d810();
void sub_d840();
void sub_d869();
void sub_d996();
void sub_d99c();
void sub_d99d();
void sub_d99e();
void sub_da88();
void sub_dac0();
void sub_dae7();
void sub_db18();
void sub_dbb6();
void sub_dbb7();
void sub_dbbf();
void sub_dbc7();
void sub_dbf6();
void sub_dc35();
void sub_dc36();
void sub_dc3c();
void sub_dc3d();
void sub_dc3e();
void sub_dcce();
void sub_dd71();
void sub_dd8b();
void sub_dddb();
void sub_de1c();
void sub_de4c();
void sub_de69();
void sub_de82();
void sub_dea1();
void sub_deb8();
void sub_deee();
void sub_df33();
void sub_df4e();
void sub_df4f();
void sub_df5f();
void sub_df8e();
void sub_df8f();
void sub_df90();
void sub_dfbf();
void sub_dfee();
void sub_e01d();
void sub_e066();
void sub_e067();
void sub_e141();
void sub_e142();
void sub_e150();
void sub_e1ce();
void sub_e2e3();
void sub_e2e4();
void sub_e600();
void sub_eb59();
void sub_ec20();
void sub_ec52();
void sub_ec70();
void sub_ecb5();
void sub_ecf9();
void sub_ed20();
void sub_ed3f();
void sub_edfa();
void sub_efb8();
void sub_eff2();
void sub_effd();
void sub_f011();
void sub_f0dc();
void sub_f1b6();
void sub_f21e();
void sub_f9b4();
void sub_f9c4();
void sub_fa07();
void sub_fb7f();
void sub_fbb9();
void sub_fbc4();
void sub_fbd8();
void sub_fce0();
void sub_fdcd();
void sub_fe71();
void sub_113fa();
void sub_11582();
void sub_115cd();
void sub_115fb();
void sub_11606();
void sub_1161a();
void sub_11705();
void sub_117e9();
void sub_11880();
void sub_11a78();
void sub_11a79();
void sub_11a7b();
void sub_11a7c();
void sub_11a7d();
void sub_11aa5();
void sub_11afd();
void sub_11b38();
void sub_11b62();
void sub_11b7d();
void sub_11ec7();
void sub_11f47();
void sub_12190();
void sub_12230();
void sub_12245();
void sub_12253();
void sub_12254();

void sub_1ed0() // 01ed:0000 +entry
{
    sp -= 2;
    dx = 0x1228;
    memoryASet16(cs, 0x01ff, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryAGet16(ds, 0x0002);
    bx = memoryAGet16(ds, 0x002c);
    ds = dx;
    memoryASet16(ds, 0x007b, ax);
    memoryASet16(ds, 0x0079, es);
    memoryASet16(ds, 0x0075, bx);
    memoryASet16(ds, 0x008d, bp);
    sub_1fff();
    di = memoryAGet16(ds, 0x0073); es = memoryAGet16(ds, 0x0073 + 2);
    ax = di;
    bx = ax;
    cx = 0x7fff;
    flags.direction = 0;
loc_1f04: // 01ed:0034
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    if (cx==0)
        goto loc_1f44;
    bx++;
    if (memoryAGet(es, di) != al)
        goto loc_1f04;
    ch |= 0x80;
    cx = -cx;
    memoryASet16(ds, 0x0073, cx);
    cx = 0x0002;
    bx <<= cl;
    bx += 0x0010;
    bx &= 0xfff0;
    memoryASet16(ds, 0x0077, bx);
    dx = ss;
    bp -= dx;
    di = memoryAGet16(ds, 0x6b4c);
    if (di >= 0x0200)
        goto loc_1f3b;
    di = 0x0200;
    memoryASet16(ds, 0x6b4c, di);
loc_1f3b: // 01ed:006b
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp >= di)
        goto loc_1f47;
loc_1f44: // 01ed:0074
    goto loc_20ba;
loc_1f47: // 01ed:0077
    bx = di;
    bx += dx;
    memoryASet16(ds, 0x0085, bx);
    memoryASet16(ds, 0x0089, bx);
    ax = memoryAGet16(ds, 0x0079);
    bx -= ax;
    es = ax;
    ah = 0x4a;
    push(di);
    interrupt(0x21);
    di = pop();
    di <<= cl;
    flags.interrupts = 0;
    ss = dx;
    sp = di;
    memoryASet16(ds, 0x6b4c, di);
    flags.interrupts = 1;
    ax = 0;
    es = memoryAGet16(cs, 0x01ff);
    di = 0x6bba;
    cx = 0xa202;
    cx -= di;
    flags.direction = 0;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ah = 0x00;
    interrupt(0x1a);
    memoryASet16(ds, 0x007f, dx);
    memoryASet16(ds, 0x0081, cx);
    bp = 0;
    ax = 0x1227;
    ds = ax;
    si = 0x0000;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    memoryASet(cs, 0x01b1, 0x72);
    memoryASet(cs, 0x01a0, 0x00);
    push(memoryAGet16(ds, 0x0071));
    push(memoryAGet16(ds, 0x006f));
    push(memoryAGet16(ds, 0x006d));
    push(memoryAGet16(ds, 0x006b));
    push(memoryAGet16(ds, 0x0069));
    sub_20d3();
    push(ax);
    sub_b78a();
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    indirectCall(cs, memoryAGet16(ds, 0x6984)); // 01ed:0109;
    indirectCall(cs, memoryAGet16(ds, 0x6986)); // 01ed:010d;
    indirectCall(cs, memoryAGet16(ds, 0x6988)); // 01ed:0111;
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
    // gap 196 bytes
loc_20ba: // 01ed:01ea
    cx = 0x001e;
    dx = 0x003b;
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    sp += 2;
}
void sub_1fc6() // 01ed:00f6
{
    sp -= 2;
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    indirectCall(cs, memoryAGet16(ds, 0x6984)); // 01ed:0109;
    indirectCall(cs, memoryAGet16(ds, 0x6986)); // 01ed:010d;
    indirectCall(cs, memoryAGet16(ds, 0x6988)); // 01ed:0111;
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
}
void sub_1fcf() // 01ed:00ff
{
    sp -= 2;
    al |= 0x00;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    indirectCall(cs, memoryAGet16(ds, 0x6984)); // 01ed:0109;
    indirectCall(cs, memoryAGet16(ds, 0x6986)); // 01ed:010d;
    indirectCall(cs, memoryAGet16(ds, 0x6988)); // 01ed:0111;
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
}
void sub_1fe5() // 01ed:0115
{
    sp -= 2;
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
}
void sub_1fff() // 01ed:012f
{
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x0059, bx);
    memoryASet16(ds, 0x005b, es);
    ax = 0x3504;
    interrupt(0x21);
    memoryASet16(ds, 0x005d, bx);
    memoryASet16(ds, 0x005f, es);
    ax = 0x3505;
    interrupt(0x21);
    memoryASet16(ds, 0x0061, bx);
    memoryASet16(ds, 0x0063, es);
    ax = 0x3506;
    interrupt(0x21);
    memoryASet16(ds, 0x0065, bx);
    memoryASet16(ds, 0x0067, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x0126;
    interrupt(0x21);
    ds = pop();
}
void sub_2042() // 01ed:0172
{
    push(ds);
    ax = 0x2500;
    dx = memoryAGet16(ds, 0x0059); ds = memoryAGet16(ds, 0x0059 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2504;
    dx = memoryAGet16(ds, 0x005d); ds = memoryAGet16(ds, 0x005d + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2505;
    dx = memoryAGet16(ds, 0x0061); ds = memoryAGet16(ds, 0x0061 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2506;
    dx = memoryAGet16(ds, 0x0065); ds = memoryAGet16(ds, 0x0065 + 2);
    interrupt(0x21);
    ds = pop();
}
void sub_206f() // 01ed:019f
{
loc_206f: // 01ed:019f
    ah = 0xff;
    dx = di;
    bx = si;
loc_2075: // 01ed:01a5
    if (bx == di)
        goto loc_208d;
    if (memoryAGet(ds, bx) == 0xff)
        goto loc_2088;
    if (memoryAGet(ds, bx + 1) > ah)
        goto loc_2088;
    ah = memoryAGet(ds, bx + 1);
    dx = bx;
loc_2088: // 01ed:01b8
    bx += 0x0006;
    goto loc_2075;
loc_208d: // 01ed:01bd
    if (dx == di)
        goto loc_20b1;
    bx = dx;
    push(ds);
    es = pop();
    push(es);
    flags.zero = memoryAGet(ds, bx) == 0x00;
    memoryASet(ds, bx, 0xff);
    ds = memoryAGet16(cs, 0x01ff);
    if (flags.zero)
        goto loc_20aa;
    push(cs); cs = memoryAGet16(es, bx + 2 + 2); indirectCall(cs, memoryAGet16(es, bx + 2)); assert(cs == 0x01ed); // 01ed:01d3;
    ds = pop();
    goto loc_206f;
loc_20aa: // 01ed:01da
    switch (memoryAGet16(es, bx + 2))
    {
        case 0x9c62: sub_bb32(); break;
        case 0xaa4e: sub_c91e(); break;
        default:
            stop("ind 01ed:01da");
    }
    ds = pop();
    goto loc_206f;
loc_20b1: // 01ed:01e1
    return;
}
void sub_20b2() // 01ed:01e2
{
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_20d3() // 01ed:0203
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    sp += 2;
}
void sub_2128() // 01ed:0258
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2134;
    sub_ca53();
loc_2134: // 01ed:0264
    memoryASet(ds, 0x79b2, 0x01);
    sub_722e();
    sub_8cb3();
loc_213f: // 01ed:026f
    sub_2ae8();
    if (memoryAGet(ds, 0x9d30) != 0x00)
        goto loc_213f;
    if (memoryAGet(ds, 0x856d) != 0x00)
        goto loc_213f;
    bp = pop();
    sp += 2;
}
void sub_2152() // 01ed:0282
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_215e;
    sub_ca53();
loc_215e: // 01ed:028e
    ax = 0x06a9;
    push(ax);
    ax = 0x0698;
    push(ax);
    sub_91bf();
    sp += 0x0004;
    push(ds);
    ax = 0x6fac;
    push(ax);
    sub_9a7d();
    sp += 0x0004;
    sub_9bae();
    sub_985a();
    sub_9402();
    sub_b14c();
    push(ds);
    ax = 0x4cd0;
    push(ax);
    al = 0x00;
    push(ax);
    sub_9433();
    sp += 0x0006;
    sub_9aa7();
    sub_b674();
    al = 0x02;
    push(ax);
    sub_9a8d();
    sp++;
    sp++;
    sub_b6c1();
    ax = 0x00c7;
    push(ax);
    ax = 0x013f;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    sub_b6f1();
    sp += 0x0008;
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_b695();
    sp += 0x0004;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    al = 0x00;
    memoryASet(ds, 0x6bec, al);
    ah = 0x00;
    memoryASet16(ds, 0x7310, ax);
    memoryASet(ds, 0x7312, al);
    memoryASet(ds, 0x6bc9, al);
    memoryASet(ds, 0x7314, al);
    al = 0x00;
    memoryASet(ds, 0x731b, al);
    memoryASet(ds, 0x6bba, al);
    memoryASet(ds, 0x75ed, al);
    memoryASet(ds, 0x75ec, al);
    memoryASet(ds, 0x75eb, al);
    memoryASet(ds, 0x75ce, al);
    al = 0x00;
    memoryASet(ds, 0x6c34, al);
    memoryASet(ds, 0x6bc8, al);
    ah = 0x00;
    memoryASet16(ds, 0x6bc2, ax);
    memoryASet16(ds, 0x6bc0, ax);
    memoryASet16(ds, 0x6c40, ax);
    memoryASet16(ds, 0x6c3e, ax);
    memoryASet16(ds, 0x75c8, ax);
    memoryASet(ds, 0x6bc5, 0x01);
    memoryASet(ds, 0x6bc4, 0x14);
    al = 0x00;
    memoryASet(ds, 0x6faa, al);
    memoryASet(ds, 0x75e2, al);
    al = 0x00;
    memoryASet(ds, 0x75cf, al);
    memoryASet(ds, 0x75c6, al);
    memoryASet(ds, 0x6bdf, al);
    memoryASet(ds, 0x6bc6, al);
    ax = 0;
    memoryASet16(ds, 0x6bf8, ax);
    memoryASet16(ds, 0x6bbe, ax);
    memoryASet16(ds, 0x6bbc, ax);
    ax = 0;
    memoryASet16(ds, 0x6bd6, ax);
    memoryASet16(ds, 0x6bce, ax);
    ax = 0;
    memoryASet16(ds, 0x6bdc, ax);
    memoryASet16(ds, 0x6bd0, ax);
    ax = 0;
    memoryASet16(ds, 0x6bda, ax);
    memoryASet16(ds, 0x6bd8, ax);
    al = 0x01;
    memoryASet(ds, 0x6bf6, al);
    memoryASet(ds, 0x6c26, al);
    ax = 0;
    memoryASet16(ds, 0x6be2, ax);
    memoryASet16(ds, 0x6be0, ax);
    memoryASet16(ds, 0x7316, 0x006c);
    al = 0x00;
    memoryASet(ds, 0x6bbb, al);
    memoryASet(ds, 0x6bde, al);
    memoryASet(ds, 0x6bc7, 0x09);
    memoryASet(ds, 0x75ea, 0x00);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x032c;
    imul16(dx);
    dx = memoryAGet16(ds, 0x6bd4);
    bx = memoryAGet16(ds, 0x6bd2);
    bx += ax;
    memoryASet16(ds, 0x6bca, bx);
    memoryASet16(ds, 0x6bcc, dx);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x00c2;
    imul16(dx);
    dx = memoryAGet16(ds, 0x6bf4);
    bx = memoryAGet16(ds, 0x6bf2);
    bx += ax;
    memoryASet16(ds, 0x75d0, bx);
    memoryASet16(ds, 0x75d2, dx);
    sub_22ba();
    bp = pop();
    sp += 2;
}
void sub_22ba() // 01ed:03ea
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_22c6;
    sub_ca53();
loc_22c6: // 01ed:03f6
    sub_b2f4();
    ax = 0x00c7;
    push(ax);
    ax = 0x013f;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    sub_b2d6();
    sp += 0x0008;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_22e6() // 01ed:0416
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_22f4;
    sub_ca53();
loc_22f4: // 01ed:0424
    memoryASet(ss, bp - 1, 0x00);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x07c3;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x75da, ax);
    memoryASet16(ds, 0x75dc, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0898;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6c2c, ax);
    memoryASet16(ds, 0x6c2e, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x7806;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6fa6, ax);
    memoryASet16(ds, 0x6fa8, dx);
    ax |= dx;
    if (ax)
        goto loc_2345;
    memoryASet(ss, bp - 1, 0xff);
loc_2345: // 01ed:0475
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_236e;
    al = 0x01;
    push(ax);
    ax = 0x0001;
    dx = 0x5c70;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0xa0c6, ax);
    memoryASet16(ds, 0xa0c8, dx);
    ax |= dx;
    if (ax)
        goto loc_236e;
    memoryASet(ss, bp - 1, 0xff);
loc_236e: // 01ed:049e
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23a8;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x2f96;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6be8, ax);
    memoryASet16(ds, 0x6bea, dx);
    ax |= dx;
    if (ax)
        goto loc_2398;
    memoryASet(ss, bp - 1, 0xff);
    goto loc_23a8;
loc_2398: // 01ed:04c8
    ax = memoryAGet16(ds, 0x6bea);
    dx = memoryAGet16(ds, 0x6be8);
    dx++;
    dx++;
    memoryASet16(ds, 0x6bd2, dx);
    memoryASet16(ds, 0x6bd4, ax);
loc_23a8: // 01ed:04d8
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23d0;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0500;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6c30, ax);
    memoryASet16(ds, 0x6c32, dx);
    ax |= dx;
    if (ax)
        goto loc_23d0;
    memoryASet(ss, bp - 1, 0xff);
loc_23d0: // 01ed:0500
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23f8;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x7926, ax);
    memoryASet16(ds, 0x7928, dx);
    ax |= dx;
    if (ax)
        goto loc_23f8;
    memoryASet(ss, bp - 1, 0xff);
loc_23f8: // 01ed:0528
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_2432;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0b60;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x75de, ax);
    memoryASet16(ds, 0x75e0, dx);
    ax |= dx;
    if (ax)
        goto loc_2422;
    memoryASet(ss, bp - 1, 0xff);
    goto loc_2432;
loc_2422: // 01ed:0552
    ax = memoryAGet16(ds, 0x75e0);
    dx = memoryAGet16(ds, 0x75de);
    dx++;
    dx++;
    memoryASet16(ds, 0x6bf2, dx);
    memoryASet16(ds, 0x6bf4, ax);
loc_2432: // 01ed:0562
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2439() // 01ed:0569
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2445;
    sub_ca53();
loc_2445: // 01ed:0575
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6c32));
    push(memoryAGet16(ds, 0x6c30));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    sub_9f6e();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_24b7() // 01ed:05e7
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_24c8;
    sub_ca53();
    goto loc_24c8;
loc_24c5: // 01ed:05f5
    sub_b734();
loc_24c8: // 01ed:05f8
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp + 4, memoryAGet(ss, bp + 4) - 1);
    if (al)
        goto loc_24c5;
    bp = pop();
    sp += 2;
}
void sub_24d4() // 01ed:0604
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_24e0;
    sub_ca53();
loc_24e0: // 01ed:0610
    al = memoryAGet(ds, 0x75cf);
    ah = 0x00;
    if (ax)
        goto loc_24f9;
    bx = memoryAGet16(ds, 0x6bca); es = memoryAGet16(ds, 0x6bca + 2);
    if (memoryAGet16(es, bx + 28) == 0x0000)
        goto loc_24f9;
    sub_250b();
    goto loc_24fe;
loc_24f9: // 01ed:0629
    memoryASet(ds, 0x75cf, 0x01);
loc_24fe: // 01ed:062e
    push(ds);
    ax = 0x0578;
    push(ax);
    sub_27a1();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_250b() // 01ed:063b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_251c;
    sub_ca53();
loc_251c: // 01ed:064c
    memoryASet(ss, bp - 1, 0x00);
    goto loc_255c;
loc_2522: // 01ed:0652
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6bca); es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    si = memoryAGet16(es, bx);
    ax = si;
    ax &= 0x00ff;
    cl = 0x08;
    ax <<= cl;
    memoryASet16(ss, bp - 4, ax);
    ax = si;
    ax &= 0xff00;
    ax >>= cl;
    di = ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dx = memoryAGet16(ss, bp - 4);
    dx |= di;
    bx = ax;
    memoryASet16(ds, bx + 1400, dx);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_255c: // 01ed:068c
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_2522;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_26c0() // 01ed:07f0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_26cc;
    sub_ca53();
loc_26cc: // 01ed:07fc
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    sub_b707();
    sp += 0x0004;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b6d4();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_26e6() // 01ed:0816
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_26f5;
    sub_ca53();
loc_26f5: // 01ed:0825
    if (memoryAGet(ss, bp + 8) <= 0x07)
        goto loc_26fe;
    goto loc_278c;
loc_26fe: // 01ed:082e
    memoryASet(ss, bp - 11, 0x00);
    goto loc_2717;
loc_2704: // 01ed:0834
    al = memoryAGet(ss, bp - 11);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x20);
loc_2717: // 01ed:0847
    al = memoryAGet(ss, bp - 11);
    if (al <= memoryAGet(ss, bp + 8))
        goto loc_2704;
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x00);
    goto loc_2776;
loc_2731: // 01ed:0861
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c7be();
    memoryASet16(ss, bp + 4, ax);
    bx = ax;
    memoryASet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryAGet(ss, bp - 1);
    dl -= al;
    memoryASet(ss, bp - 1, dl);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    dl = memoryAGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memoryASet(ss, bx, dl);
loc_2776: // 01ed:08a6
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp + 8, memoryAGet(ss, bp + 8) - 1);
    if (al)
        goto loc_2731;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(ss);
    ax = bp - 10;
    goto loc_2796;
loc_278c: // 01ed:08bc
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(ds);
    ax = 0x062e;
loc_2796: // 01ed:08c6
    push(ax);
    sub_26c0();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_27a1() // 01ed:08d1
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_27b1;
    sub_ca53();
loc_27b1: // 01ed:08e1
    memoryASet16(ss, bp - 4, 0x6c42);
    memoryASet16(ss, bp - 2, ds);
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_27f6;
    memoryASet16(ds, 0x9b96, 0x6c42);
    memoryASet16(ds, 0x9b98, ds);
    memoryASet(ss, bp - 6, 0x00);
    goto loc_27ed;
loc_27d0: // 01ed:0900
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    si = ax;
    al = memoryAGet(ds, si + 1806);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_27ed: // 01ed:091d
    if (memoryAGet(ss, bp - 6) < 0x10)
        goto loc_27d0;
    goto loc_28b9;
loc_27f6: // 01ed:0926
    memoryASet(ss, bp - 5, 0x00);
    goto loc_28b0;
loc_27fd: // 01ed:092d
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    cl = 0x08;
    ax >>= cl;
    memoryASet(ss, bp - 7, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dl = memoryAGet(ds, 0x75eb);
    dh = 0x00;
    dx <<= cl;
    ax -= dx;
    cl = 0x04;
    ax >>= cl;
    memoryASet(ss, bp - 8, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ds, 0x75eb);
    cl = 0x08;
    dl <<= cl;
    bl = memoryAGet(ds, 0x75ec);
    cl = 0x04;
    bl <<= cl;
    dl += bl;
    al -= dl;
    memoryASet(ss, bp - 9, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul16(dx);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 7);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 51, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul16(dx);
    bx = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(ss, bp - 8);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 52, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul16(dx);
    bx = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(ss, bp - 9);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 53, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_28b0: // 01ed:09e0
    if (memoryAGet(ss, bp - 5) >= 0x10)
        goto loc_28b9;
    goto loc_27fd;
loc_28b9: // 01ed:09e9
    ax = 0;
    push(ax);
    push(ds);
    ax = 0x6c42;
    push(ax);
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_28d7() // 01ed:0a07
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_28e4;
    sub_ca53();
loc_28e4: // 01ed:0a14
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00c0));
    push(memoryAGet16(ds, 0x00be));
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    sub_b6a5();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    ax = 0x0009;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00f2));
    push(memoryAGet16(ds, 0x00f0));
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    sub_b2a8();
    sp += 0x0004;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_2960() // 01ed:0a90
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2970;
    sub_ca53();
loc_2970: // 01ed:0aa0
    ax = memoryAGet16(ds, 0x6fa8);
    dx = memoryAGet16(ds, 0x6fa6);
    dx += 0x0006;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0018);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 28, 0x0006);
    memoryASet16(es, bx + 30, 0x0001);
    if (memoryAGet16(ss, bp + 8) != 0x0018)
        goto loc_29b3;
    memoryASet16(es, bx + 32, 0x0001);
    goto loc_29bd;
loc_29b3: // 01ed:0ae3
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 32, 0x0002);
loc_29bd: // 01ed:0aed
    if (memoryAGet(ss, bp + 4) <= 0xf0)
        goto loc_29d1;
    memoryASet(ss, bp - 2, 0x01);
    al = 0xfb;
    al -= memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    goto loc_2a4a;
loc_29d1: // 01ed:0b01
    memoryASet(ss, bp - 2, 0x00);
    memoryASet(ss, bp - 1, 0x01);
    goto loc_2a4a;
loc_29db: // 01ed:0b0b
    ax = memoryAGet16(ss, bp + 6);
    dx = 0x0027;
    imul16(dx);
    bx = memoryAGet16(ds, 0x6bca); es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp + 8);
    ax = sar16(ax, 0x0001);
    dx = 0x0003;
    imul16(dx);
    bx += ax;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 32);
    al += 0xff;
    memoryASet(ss, bp + 4, al);
    ah = 0x00;
    bx = 0x0014;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax <<= 1;
    si = ax;
    dx = 0x000a;
    imul16(dx);
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    dx -= ax;
    di = dx;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_2a4a: // 01ed:0b7a
    al = memoryAGet(ss, bp - 2);
    if (al < memoryAGet(ss, bp - 1))
        goto loc_29db;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2a58() // 01ed:0b88
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2a64;
    sub_ca53();
loc_2a64: // 01ed:0b94
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 14, ax);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    if (memoryAGet16(ss, bp + 6) != 0x0018)
        goto loc_2a97;
    memoryASet16(es, bx + 32, 0x0001);
    goto loc_2aa1;
loc_2a97: // 01ed:0bc7
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 32, 0x0002);
loc_2aa1: // 01ed:0bd1
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_2ac9() // 01ed:0bf9
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2ad5;
    sub_ca53();
loc_2ad5: // 01ed:0c05
    sub_5180();
    sub_4948();
    sub_50ae();
    al = 0x00;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0x856d, al);
    bp = pop();
    sp += 2;
}
void sub_2ae8() // 01ed:0c18
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2af6;
    sub_ca53();
loc_2af6: // 01ed:0c26
    sub_5295();
    sub_4dc8();
loc_2afc: // 01ed:0c2c
    memoryASet(ds, 0x928d, 0x00);
    memoryASet(ds, 0x791a, 0x05);
    al = 0x00;
    memoryASet(ds, 0x79b5, al);
    ah = 0x00;
    memoryASet16(ds, 0xa0d4, ax);
    memoryASet16(ds, 0xa0d6, 0x0000);
    goto loc_2b26;
loc_2b18: // 01ed:0c48
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_2b23;
    sub_7551();
    goto loc_2b26;
loc_2b23: // 01ed:0c53
    sub_2e4a();
loc_2b26: // 01ed:0c56
    sub_5475();
    memoryASet(ss, bp - 1, al);
    if (al)
        goto loc_2b18;
    goto loc_2c5a;
loc_2b33: // 01ed:0c63
    sub_5722();
    if (memoryAGet(ds, 0x928d) != 0xff)
        goto loc_2b42;
    sub_30bb();
    goto loc_2afc;
loc_2b42: // 01ed:0c72
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    memoryASet16(ds, 0x7310, ax);
    sub_5337();
    sub_2ac9();
    al = memoryAGet(ds, 0x8562);
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_7051();
    sp += 0x0004;
    sub_3b82();
    sub_3bba();
    sub_24d4();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    sub_515f();
    sub_3343();
    sub_6a1e();
    sub_325c();
    sub_3282();
    sub_3aa7();
    sub_3b11();
    sub_325c();
    sub_3282();
    sub_3871();
    sub_38b4();
    sub_3343();
    sub_6a1e();
    goto loc_2c19;
loc_2baa: // 01ed:0cda
    sub_b281();
    memoryASet(ds, 0x79b3, al);
    sub_325c();
    sub_3282();
    sub_32af();
    sub_6ae4();
    sub_3343();
    sub_6a1e();
    sub_33b4();
    sub_3471();
    sub_3871();
    sub_38b4();
    sub_38f0();
    sub_352e();
    sub_3697();
    sub_6f55();
    sub_6f90();
    sub_3937();
    sub_39fb();
    sub_3aa7();
    sub_3b11();
    sub_3b82();
    sub_3bba();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    sub_816c();
    sub_3bf6();
    sub_6b69();
    sub_6fcb();
    sub_420a();
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_2c19;
    sub_68a7();
loc_2c19: // 01ed:0d49
    if (memoryAGet(ds, 0x928d) != 0x00)
        goto loc_2c31;
    if (memoryAGet(ds, 0x856d) != 0x00)
        goto loc_2c31;
    if (memoryAGet(ds, 0x9d30) != 0x00)
        goto loc_2c31;
    goto loc_2baa;
loc_2c31: // 01ed:0d61
    if (memoryAGet(ds, 0x928d) != 0xff)
        goto loc_2c40;
    sub_30bb();
    sub_7551();
    goto loc_2c5d;
loc_2c40: // 01ed:0d70
    sub_5d5a();
    if (!al)
        goto loc_2c5d;
    memoryASet(ds, 0x79b2, memoryAGet(ds, 0x79b2) + 1);
    if (memoryAGet(ds, 0x79b2) != 0x0a)
        goto loc_2c57;
    sub_5da4();
    goto loc_2c5d;
loc_2c57: // 01ed:0d87
    sub_2c6d();
loc_2c5a: // 01ed:0d8a
    sub_4be4();
loc_2c5d: // 01ed:0d8d
    al = memoryAGet(ds, 0x928d);
    ah = 0x00;
    if (ax)
        goto loc_2c69;
    goto loc_2b33;
loc_2c69: // 01ed:0d99
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2c6d() // 01ed:0d9d
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2c7e;
    sub_ca53();
loc_2c7e: // 01ed:0dae
    push(ss);
    ax = bp - 4;
    push(ax);
    push(ds);
    ax = 0x119e;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_2d1a;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 13, 0x00);
    goto loc_2d14;
loc_2cf7: // 01ed:0e27
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
loc_2d14: // 01ed:0e44
    if (memoryAGet(ss, bp - 13) < 0x10)
        goto loc_2cf7;
loc_2d1a: // 01ed:0e4a
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ss, bp - 9, 0x04);
    memoryASet(ss, bp - 10, 0x05);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_2da4;
loc_2d64: // 01ed:0e94
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 11) == 0x20)
        goto loc_2d9e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2d9e: // 01ed:0ece
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_2da4: // 01ed:0ed4
    if (memoryAGet(ss, bp - 12) < 0x0d)
        goto loc_2d64;
    memoryASet(ss, bp - 9, 0x07);
    memoryASet(ss, bp - 10, 0x07);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4950);
    dx = memoryAGet16(ds, bx + 4948);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_2e1c;
loc_2de2: // 01ed:0f12
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_2e1c: // 01ed:0f4c
    if (memoryAGet(ss, bp - 12) < 0x06)
        goto loc_2de2;
loc_2e22: // 01ed:0f52
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    cbw();
    if (!(ax & 0x0010))
        goto loc_2e22;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2e4a() // 01ed:0f7a
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0016;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2e5b;
    sub_ca53();
loc_2e5b: // 01ed:0f8b
    push(ss);
    ax = bp - 4;
    push(ax);
    push(ds);
    ax = 0x11a2;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ss);
    ax = bp - 8;
    push(ax);
    push(ds);
    ax = 0x11a6;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ss);
    ax = bp - 12;
    push(ax);
    push(ds);
    ax = 0x11aa;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_2f17;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 22, 0x00);
    goto loc_2f11;
loc_2ef4: // 01ed:1024
    al = memoryAGet(ss, bp - 22);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 22);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 22, memoryAGet(ss, bp - 22) + 1);
loc_2f11: // 01ed:1041
    if (memoryAGet(ss, bp - 22) < 0x10)
        goto loc_2ef4;
loc_2f17: // 01ed:1047
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ss, bp - 17, 0x00);
    memoryASet(ss, bp - 18, 0x01);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_2fa1;
loc_2f61: // 01ed:1091
    al = memoryAGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 19, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 19) == 0x20)
        goto loc_2f9b;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2f9b: // 01ed:10cb
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_2fa1: // 01ed:10d1
    if (memoryAGet(ss, bp - 20) < 0x13)
        goto loc_2f61;
    memoryASet(ss, bp - 17, 0x07);
    memoryASet(ss, bp - 18, 0x0a);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_2ff7;
loc_2fc6: // 01ed:10f6
    memoryASet(ss, bp - 19, 0x41);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    al = memoryAGet(ss, bp - 19);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_2ff7: // 01ed:1127
    if (memoryAGet(ss, bp - 20) < 0x06)
        goto loc_2fc6;
    al = 0x07;
    push(ax);
    al = 0x0a;
    push(ax);
    sub_7b57();
    sp += 0x0004;
    memoryASet(ss, bp - 21, al);
    if (!al)
        goto loc_3024;
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    al = memoryAGet(ss, bp - 21);
    memoryASet(ds, 0x79b2, al);
    goto loc_3035;
loc_3024: // 01ed:1154
    ax = memoryAGet16(ss, bp - 10);
    dx = memoryAGet16(ss, bp - 12);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    memoryASet(ds, 0x79b2, 0x01);
loc_3035: // 01ed:1165
    memoryASet(ss, bp - 17, 0x03);
    memoryASet(ss, bp - 18, 0x06);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_3094;
loc_3054: // 01ed:1184
    al = memoryAGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 19, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 19) == 0x20)
        goto loc_308e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_308e: // 01ed:11be
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_3094: // 01ed:11c4
    if (memoryAGet(ss, bp - 20) < 0x0e)
        goto loc_3054;
    memoryASet(ss, bp - 20, 0x00);
    goto loc_30a6;
loc_30a0: // 01ed:11d0
    sub_5d44();
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_30a6: // 01ed:11d6
    if (memoryAGet(ss, bp - 20) < 0x03)
        goto loc_30a0;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_30bb() // 01ed:11eb
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_30cc;
    sub_ca53();
loc_30cc: // 01ed:11fc
    push(ss);
    ax = bp - 4;
    push(ax);
    push(ds);
    ax = 0x11ae;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_3168;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 13, 0x00);
    goto loc_3162;
loc_3145: // 01ed:1275
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
loc_3162: // 01ed:1292
    if (memoryAGet(ss, bp - 13) < 0x10)
        goto loc_3145;
loc_3168: // 01ed:1298
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    al = 0x06;
    memoryASet(ss, bp - 10, al);
    memoryASet(ss, bp - 9, al);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_31f2;
loc_31b2: // 01ed:12e2
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 11) == 0x20)
        goto loc_31ec;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_31ec: // 01ed:131c
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_31f2: // 01ed:1322
    if (memoryAGet(ss, bp - 12) < 0x09)
        goto loc_31b2;
    memoryASet(ss, bp - 12, 0x00);
    goto loc_3204;
loc_31fe: // 01ed:132e
    sub_5d44();
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_3204: // 01ed:1334
    if (memoryAGet(ss, bp - 12) < 0x02)
        goto loc_31fe;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3219() // 01ed:1349
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3227;
    sub_ca53();
loc_3227: // 01ed:1357
    memoryASet(ss, bp - 2, 0x01);
    if (!(memoryAGet(ds, 0x854f) & 0x01))
        goto loc_3236;
    al = 0x80;
    goto loc_3238;
loc_3236: // 01ed:1366
    al = 0x00;
loc_3238: // 01ed:1368
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_3242;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_3242: // 01ed:1372
    al = memoryAGet(ds, 0x854f);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    al |= memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x854f, al);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_325c() // 01ed:138c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3268;
    sub_ca53();
loc_3268: // 01ed:1398
    ax = memoryAGet16(ds, 0x857a);
    memoryASet16(ds, 0x8882, ax);
    ax = memoryAGet16(ds, 0x857c);
    memoryASet16(ds, 0x8e88, ax);
    ax = memoryAGet16(ds, 0x9d36);
    memoryASet16(ds, 0x857a, ax);
    ax = memoryAGet16(ds, 0x9d38);
    memoryASet16(ds, 0x857c, ax);
    bp = pop();
    sp += 2;
}
void sub_3282() // 01ed:13b2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_328e;
    sub_ca53();
loc_328e: // 01ed:13be
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_32ad;
    ax = memoryAGet16(ds, 0x8558);
    memoryASet16(ds, 0x928e, ax);
    ax = memoryAGet16(ds, 0x855a);
    memoryASet16(ds, 0x9b94, ax);
    ax = memoryAGet16(ds, 0xa0ca);
    memoryASet16(ds, 0x8558, ax);
    ax = memoryAGet16(ds, 0xa0cc);
    memoryASet16(ds, 0x855a, ax);
loc_32ad: // 01ed:13dd
    bp = pop();
    sp += 2;
}
void sub_32af() // 01ed:13df
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_32bb;
    sub_ca53();
loc_32bb: // 01ed:13eb
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_3341;
    if (memoryAGet(ds, 0x824d) == 0x00)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x05)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x0b)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x1c)
        goto loc_3341;
    bx = memoryAGet16(ds, 0xa1ac); es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x824a, ax);
    if (memoryAGet(ds, 0x9bae) == 0x00)
        goto loc_3305;
    ax = memoryAGet16(es, bx + 2);
    ax = -ax;
    dx = memoryAGet16(ds, 0x9290);
    dx += ax;
    memoryASet16(ds, 0x9290, dx);
    ax = dx;
    goto loc_3314;
loc_3305: // 01ed:1435
    bx = memoryAGet16(ds, 0xa1ac); es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x9290, memoryAGet16(ds, 0x9290) + ax);
    ax = memoryAGet16(ds, 0x9290);
loc_3314: // 01ed:1444
    bx = memoryAGet16(ds, 0xa1ac); es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x9292, memoryAGet16(ds, 0x9292) + ax);
    memoryASet16(ds, 0xa1ac, memoryAGet16(ds, 0xa1ac) + 0x0006);
    al = memoryAGet(ds, 0x824d);
    al += 0xff;
    memoryASet(ds, 0x824d, al);
    ah = 0x00;
    if (ax)
        goto loc_333a;
    al = 0x00;
    memoryASet(ds, 0x792a, al);
    goto loc_3341;
loc_333a: // 01ed:146a
    memoryASet(ds, 0x792a, memoryAGet(ds, 0x792a) + 1);
    al = memoryAGet(ds, 0x792a);
loc_3341: // 01ed:1471
    bp = pop();
    sp += 2;
}
void sub_3343() // 01ed:1473
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3351;
    sub_ca53();
loc_3351: // 01ed:1481
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x9290);
    ax -= di;
    cl = 0x04;
    ax = sar16(ax, cl);
    ax--;
    memoryASet16(ds, 0x9d36, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax -= si;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x9d38, ax);
    if ((short)memoryAGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_3387;
    memoryASet16(ds, 0x9d36, 0x0000);
    goto loc_3394;
loc_3387: // 01ed:14b7
    if ((short)memoryAGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_3394;
    memoryASet16(ds, 0x9d36, 0x0012);
loc_3394: // 01ed:14c4
    if ((short)memoryAGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_33a3;
    memoryASet16(ds, 0x9d38, 0x0000);
    goto loc_33b0;
loc_33a3: // 01ed:14d3
    if ((short)memoryAGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_33b0;
    memoryASet16(ds, 0x9d38, 0x0016);
loc_33b0: // 01ed:14e0
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_33b4() // 01ed:14e4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_33c4;
    sub_ca53();
loc_33c4: // 01ed:14f4
    memoryASet(ds, 0x856c, 0x00);
    cl = 0x00;
    goto loc_3464;
loc_33ce: // 01ed:14fe
    al = memoryAGet(ds, 0x856c);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_345e;
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0be, dx);
    memoryASet16(ds, 0xa0c0, ax);
    bx = memoryAGet16(ds, 0xa0be); es = memoryAGet16(ds, 0xa0be + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8578, al);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    memoryASet(es, bx + 6, al);
    if (memoryAGet(ds, 0x8578) != 0xff)
        goto loc_3421;
    memoryASet(es, bx, 0x00);
    goto loc_345e;
loc_3421: // 01ed:1551
    if (memoryAGet(ds, 0x8578) == 0x00)
        goto loc_345e;
    al = memoryAGet(ds, 0x8578);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 15724);
    dx = memoryAGet16(ds, bx + 15722);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, si);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 10, ax);
loc_345e: // 01ed:158e
    memoryASet(ds, 0x856c, memoryAGet(ds, 0x856c) + 1);
    cl++;
loc_3464: // 01ed:1594
    if (cl >= 0x03)
        goto loc_346c;
    goto loc_33ce;
loc_346c: // 01ed:159c
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3471() // 01ed:15a1
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3481;
    sub_ca53();
loc_3481: // 01ed:15b1
    memoryASet(ds, 0x8566, 0x00);
    cl = 0x00;
    goto loc_3521;
loc_348b: // 01ed:15bb
    al = memoryAGet(ds, 0x8566);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_351b;
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0c2, dx);
    memoryASet16(ds, 0xa0c4, ax);
    bx = memoryAGet16(ds, 0xa0c2); es = memoryAGet16(ds, 0xa0c2 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8579, al);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    memoryASet(es, bx + 6, al);
    if (memoryAGet(ds, 0x8579) != 0xff)
        goto loc_34de;
    memoryASet(es, bx, 0x00);
    goto loc_351b;
loc_34de: // 01ed:160e
    if (memoryAGet(ds, 0x8579) == 0x00)
        goto loc_351b;
    al = memoryAGet(ds, 0x8579);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 16552);
    dx = memoryAGet16(ds, bx + 16550);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, si);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 10, ax);
loc_351b: // 01ed:164b
    memoryASet(ds, 0x8566, memoryAGet(ds, 0x8566) + 1);
    cl++;
loc_3521: // 01ed:1651
    if (cl >= 0x04)
        goto loc_3529;
    goto loc_348b;
loc_3529: // 01ed:1659
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_352e() // 01ed:165e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_353f;
    sub_ca53();
loc_353f: // 01ed:166f
    memoryASet(ss, bp - 2, 0x00);
loc_3543: // 01ed:1673
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_356e;
    goto loc_3685;
loc_356e: // 01ed:169e
    if (memoryAGet(ss, bp - 1) != 0xff)
        goto loc_3577;
    goto loc_3685;
loc_3577: // 01ed:16a7
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryAGet16(ds, bx + 12990);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryAGet16(ds, bx + 12992);
    bx = memoryAGet16(ds, 0x08d4); es = memoryAGet16(ds, 0x08d4 + 2);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_35b4;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0600;
    memoryASet16(es, bx + 28, ax);
loc_35b4: // 01ed:16e4
    bx = memoryAGet16(ds, 0x08d4); es = memoryAGet16(ds, 0x08d4 + 2);
    ax = di;
    memoryASet16(es, bx + 20, ax);
    memoryASet16(es, bx + 6, ax);
    ax = si;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 8, ax);
    push(memoryAGet16(ds, 0x08d6));
    push(memoryAGet16(ds, 0x08d4));
    sub_9f8c();
    sp += 0x0004;
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 244);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 246);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, bx + 10);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet16(es, bx + 10) & 0x0200)
        goto loc_363f;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_363f: // 01ed:176f
    bx = memoryAGet16(ds, 0x08e0); es = memoryAGet16(ds, 0x08e0 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul16(dx);
    ax += 0x79be;
    memoryASet16(es, bx + 16, ax);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_3677;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0200;
    memoryASet16(es, bx + 28, ax);
loc_3677: // 01ed:17a7
    push(memoryAGet16(ds, 0x08e2));
    push(memoryAGet16(ds, 0x08e0));
    sub_b288();
    sp += 0x0004;
loc_3685: // 01ed:17b5
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3691;
    goto loc_3543;
loc_3691: // 01ed:17c1
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3697() // 01ed:17c7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_36a8;
    sub_ca53();
loc_36a8: // 01ed:17d8
    memoryASet(ss, bp - 2, 0x00);
loc_36ac: // 01ed:17dc
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_36d7;
    goto loc_385f;
loc_36d7: // 01ed:1807
    if (memoryAGet(ss, bp - 1) != 0xff)
        goto loc_36e0;
    goto loc_385f;
loc_36e0: // 01ed:1810
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryAGet16(ds, bx + 13374);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryAGet16(ds, bx + 13376);
    bx = memoryAGet16(ds, 0x08c8); es = memoryAGet16(ds, 0x08c8 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    push(memoryAGet16(ds, 0x08ca));
    push(memoryAGet16(ds, 0x08c8));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 10, 0x0001);
    ax = 0;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 20, ax);
    memoryASet16(es, bx + 28, 0x0004);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_3760;
    memoryASet16(es, bx + 2, 0x9fba);
    memoryASet16(es, bx + 4, ds);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9eba);
    goto loc_3786;
loc_3760: // 01ed:1890
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9eba);
    memoryASet16(es, bx + 4, ds);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9fba);
loc_3786: // 01ed:18b6
    memoryASet16(es, bx + 4, ds);
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 20, di);
    memoryASet16(es, bx + 22, si);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x8888);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 28, 0x0003);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1012);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1014);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet16(es, bx + 10) & 0x0200)
        goto loc_3831;
    ax = memoryAGet16(es, bx + 10);
    ax += 0x00f1;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3831: // 01ed:1961
    bx = memoryAGet16(ds, 0x08d0); es = memoryAGet16(ds, 0x08d0 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    memoryASet16(es, bx + 16, ax);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x08d2));
    push(memoryAGet16(ds, 0x08d0));
    sub_b288();
    sp += 0x0004;
loc_385f: // 01ed:198f
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_386b;
    goto loc_36ac;
loc_386b: // 01ed:199b
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3871() // 01ed:19a1
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_387d;
    sub_ca53();
loc_387d: // 01ed:19ad
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_38b2;
    bx = memoryAGet16(ds, 0x08e8); es = memoryAGet16(ds, 0x08e8 + 2);
    ax = memoryAGet16(ds, 0x928e);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x9b94);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, 0x9d34);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9d32);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ea));
    push(memoryAGet16(ds, 0x08e8));
    sub_9f8c();
    sp += 0x0004;
loc_38b2: // 01ed:19e2
    bp = pop();
    sp += 2;
}
void sub_38b4() // 01ed:19e4
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_38c0;
    sub_ca53();
loc_38c0: // 01ed:19f0
    bx = memoryAGet16(ds, 0x08c4); es = memoryAGet16(ds, 0x08c4 + 2);
    ax = memoryAGet16(ds, 0x8882);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x8e88);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, 0x9ba4);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9b9c);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08c6));
    push(memoryAGet16(ds, 0x08c4));
    sub_9f8c();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_38f0() // 01ed:1a20
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_38fc;
    sub_ca53();
loc_38fc: // 01ed:1a2c
    if (memoryAGet(ds, 0xa1a8) == 0x00)
        goto loc_3935;
    memoryASet(ds, 0xa1a8, memoryAGet(ds, 0xa1a8) - 1);
    bx = memoryAGet16(ds, 0x08e4); es = memoryAGet16(ds, 0x08e4 + 2);
    ax = memoryAGet16(ds, 0x9b9a);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x9ba2);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9b9a);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x9ba2);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x08e6));
    push(memoryAGet16(ds, 0x08e4));
    sub_9f8c();
    sp += 0x0004;
loc_3935: // 01ed:1a65
    bp = pop();
    sp += 2;
}
void sub_3937() // 01ed:1a67
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3946;
    sub_ca53();
loc_3946: // 01ed:1a76
    memoryASet(ss, bp - 2, 0x00);
loc_394a: // 01ed:1a7a
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_39eb;
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_39eb;
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul16(dx);
    ax += 0x79be;
    bx = memoryAGet16(ds, 0x08c0); es = memoryAGet16(ds, 0x08c0 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet16(es, bx + 4, ds);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12990);
    bx = memoryAGet16(ds, 0x08c0);
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12992);
    bx = memoryAGet16(ds, 0x08c0);
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_39dd;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0400;
    memoryASet16(es, bx + 28, ax);
loc_39dd: // 01ed:1b0d
    push(memoryAGet16(ds, 0x08c2));
    push(memoryAGet16(ds, 0x08c0));
    sub_9f8c();
    sp += 0x0004;
loc_39eb: // 01ed:1b1b
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_39f7;
    goto loc_394a;
loc_39f7: // 01ed:1b27
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_39fb() // 01ed:1b2b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3a0a;
    sub_ca53();
loc_3a0a: // 01ed:1b3a
    memoryASet(ss, bp - 2, 0x00);
loc_3a0e: // 01ed:1b3e
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_3a97;
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3a97;
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    bx = memoryAGet16(ds, 0x08bc); es = memoryAGet16(ds, 0x08bc + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet16(es, bx + 4, ds);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 13374);
    bx = memoryAGet16(ds, 0x08bc);
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 13376);
    bx = memoryAGet16(ds, 0x08bc);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x08be));
    push(memoryAGet16(ds, 0x08bc));
    sub_9f8c();
    sp += 0x0004;
loc_3a97: // 01ed:1bc7
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3aa3;
    goto loc_3a0e;
loc_3aa3: // 01ed:1bd3
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3aa7() // 01ed:1bd7
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3ab3;
    sub_ca53();
loc_3ab3: // 01ed:1be3
    memoryASet16(ds, 0x9ba4, 0x0004);
    if ((short)memoryAGet16(ds, 0x857a) <= (short)0x0010)
        goto loc_3aca;
    ax = 0x0014;
    ax -= memoryAGet16(ds, 0x857a);
    memoryASet16(ds, 0x9ba4, ax);
loc_3aca: // 01ed:1bfa
    memoryASet16(ds, 0x9b9c, 0x0004);
    if ((short)memoryAGet16(ds, 0x857c) <= (short)0x0015)
        goto loc_3ae1;
    ax = 0x0019;
    ax -= memoryAGet16(ds, 0x857c);
    memoryASet16(ds, 0x9b9c, ax);
loc_3ae1: // 01ed:1c11
    bx = memoryAGet16(ds, 0x08b8); es = memoryAGet16(ds, 0x08b8 + 2);
    ax = memoryAGet16(ds, 0x857a);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x857c);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9ba4);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9b9c);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ba));
    push(memoryAGet16(ds, 0x08b8));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_3b11() // 01ed:1c41
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3b1d;
    sub_ca53();
loc_3b1d: // 01ed:1c4d
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_3b80;
    memoryASet16(ds, 0x9d34, 0x0004);
    if ((short)memoryAGet16(ds, 0x8558) <= (short)0x0010)
        goto loc_3b3b;
    ax = 0x0014;
    ax -= memoryAGet16(ds, 0x8558);
    memoryASet16(ds, 0x9d34, ax);
loc_3b3b: // 01ed:1c6b
    memoryASet16(ds, 0x9d32, 0x0004);
    if ((short)memoryAGet16(ds, 0x855a) <= (short)0x0015)
        goto loc_3b52;
    ax = 0x0019;
    ax -= memoryAGet16(ds, 0x855a);
    memoryASet16(ds, 0x9d32, ax);
loc_3b52: // 01ed:1c82
    bx = memoryAGet16(ds, 0x08ec); es = memoryAGet16(ds, 0x08ec + 2);
    ax = memoryAGet16(ds, 0x8558);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x855a);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9d34);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9d32);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ee));
    push(memoryAGet16(ds, 0x08ec));
    sub_b288();
    sp += 0x0004;
loc_3b80: // 01ed:1cb0
    bp = pop();
    sp += 2;
}
void sub_3b82() // 01ed:1cb2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3b8e;
    sub_ca53();
loc_3b8e: // 01ed:1cbe
    if (memoryAGet16(ds, 0x824a) == 0x0064)
        goto loc_3bb8;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0x824a);
    memoryASet16(es, bx + 4, ax);
    ax = memoryAGet16(ds, 0x9290);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ds, 0x9292);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bb8: // 01ed:1ce8
    bp = pop();
    sp += 2;
}
void sub_3bba() // 01ed:1cea
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3bc6;
    sub_ca53();
loc_3bc6: // 01ed:1cf6
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_3bf4;
    bx = memoryAGet16(ds, 0x9b9e); es = memoryAGet16(ds, 0x9b9e + 2);
    ax = memoryAGet16(ds, 0xa0de);
    ax += memoryAGet16(ds, 0x8560);
    memoryASet16(es, bx + 4, ax);
    ax = memoryAGet16(ds, 0x79ba);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ds, 0x79bc);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x795a;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bf4: // 01ed:1d24
    bp = pop();
    sp += 2;
}
void sub_3bf6() // 01ed:1d26
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3c02;
    sub_ca53();
loc_3c02: // 01ed:1d32
    al = 0x3b;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c15;
    memoryASet(ds, 0x854f, 0x00);
    goto loc_3c8b;
loc_3c15: // 01ed:1d45
    al = 0x3c;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c28;
    memoryASet(ds, 0x854f, 0x88);
    goto loc_3c8b;
loc_3c28: // 01ed:1d58
    al = 0x3d;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c3b;
    memoryASet(ds, 0x854f, 0xaa);
    goto loc_3c8b;
loc_3c3b: // 01ed:1d6b
    al = 0x3e;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c4e;
    memoryASet(ds, 0x854f, 0xee);
    goto loc_3c8b;
loc_3c4e: // 01ed:1d7e
    al = 0x3f;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c61;
    memoryASet(ds, 0x854f, 0xff);
    goto loc_3c8b;
loc_3c61: // 01ed:1d91
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c72;
    sub_41cc();
    goto loc_3c8b;
loc_3c72: // 01ed:1da2
    al = 0x44;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c8b;
    memoryASet(ds, 0x928d, 0x01);
    al = 0x00;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0x856d, al);
loc_3c8b: // 01ed:1dbb
    if (memoryAGet(ds, 0xa1aa) == 0x00)
        goto loc_3c97;
    sub_415d();
    goto loc_3cac;
loc_3c97: // 01ed:1dc7
    sub_423f();
    sub_3cae();
    if (memoryAGet(ds, 0x824d) == 0x00)
        goto loc_3ca9;
    sub_425e();
    goto loc_3cac;
loc_3ca9: // 01ed:1dd9
    sub_3cd2();
loc_3cac: // 01ed:1ddc
    bp = pop();
    sp += 2;
}
void sub_3cae() // 01ed:1dde
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3cbc;
    sub_ca53();
loc_3cbc: // 01ed:1dec
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_3cce;
    memoryASet(ds, 0x8244, al);
loc_3cce: // 01ed:1dfe
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3cd2() // 01ed:1e02
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3cde;
    sub_ca53();
loc_3cde: // 01ed:1e0e
    memoryASet(ds, 0x7923, 0x00);
    al = memoryAGet(ds, 0x792c);
    memoryASet(ds, 0x8552, al);
    if (memoryAGet(ds, 0xa0ce) != 0x00)
        goto loc_3cf9;
    al = memoryAGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_3d08;
loc_3cf9: // 01ed:1e29
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    switch (bx)
    {
        case 0: sub_47c9(); break;
        case 2: sub_47c9(); break;
        case 4: sub_47c9(); break;
        case 6: sub_4286(); break;
        case 8: sub_47c9(); break;
        case 10: sub_42f3(); break;
        case 12: sub_47c9(); break;
        case 14: sub_47c9(); break;
        case 16: sub_47c9(); break;
        case 18: sub_47c9(); break;
        case 20: sub_4340(); break;
        case 22: sub_435e(); break;
        case 24: sub_43a7(); break;
        case 26: sub_43da(); break;
        case 28: sub_447d(); break;
        case 30: sub_4286(); break;
        case 32: sub_4180(); break;
        case 34: sub_47c9(); break;
        case 36: sub_47c9(); break;
        case 38: sub_47c9(); break;
        case 40: sub_47c9(); break;
        case 42: sub_47c9(); break;
        case 44: sub_47c9(); break;
        case 46: sub_47c9(); break;
        case 48: sub_47c9(); break;
        case 50: sub_47c9(); break;
        case 52: sub_47c9(); break;
        case 54: sub_47c9(); break;
        case 56: sub_6214(); break;
        case 58: sub_6307(); break;
        case 60: sub_6307(); break;
        case 62: sub_6307(); break;
        case 64: sub_6307(); break;
        case 66: sub_3d2e(); break;
        case 68: sub_3d60(); break;
        case 70: sub_3d92(); break;
        case 72: sub_3e0e(); break;
        case 74: sub_4008(); break;
        case 76: sub_40b7(); break;
        case 78: sub_47c9(); break;
        case 80: sub_47c9(); break;
        case 82: sub_47c9(); break;
        case 84: sub_47c9(); break;
        case 86: sub_47c9(); break;
        case 88: sub_4180(); break;
        case 90: sub_4191(); break;
        case 92: sub_41a2(); break;
        case 94: sub_46e0(); break;
        case 96: sub_3d0d(); break;
        case 98: sub_47c9(); break;
        case 100: sub_47c9(); break;
        case 102: sub_47c9(); break;
        case 104: sub_47c9(); break;
        case 106: sub_47c9(); break;
        case 108: sub_47c9(); break;
        case 110: sub_47c9(); break;
        case 112: sub_47c9(); break;
        case 114: sub_47c9(); break;
        case 116: sub_47c9(); break;
        case 118: sub_47c9(); break;
        case 120: sub_47c9(); break;
        case 122: sub_47c9(); break;
        case 124: sub_47c9(); break;
        case 126: sub_47c9(); break;
        default:
            stop("ind 01ed:1e32");
    }
    goto loc_3d0b;
loc_3d08: // 01ed:1e38
    sub_46ae();
loc_3d0b: // 01ed:1e3b
    bp = pop();
    sp += 2;
}
void sub_3d0d() // 01ed:1e3d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3d19;
    sub_ca53();
loc_3d19: // 01ed:1e49
    al = 0x01;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0xa1a9, al);
    sub_5958();
    bx = memoryAGet16(ds, 0x9baa); es = memoryAGet16(ds, 0x9baa + 2);
    memoryASet(es, bx, 0x01);
    bp = pop();
    sp += 2;
}
void sub_3d2e() // 01ed:1e5e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3d3a;
    sub_ca53();
loc_3d3a: // 01ed:1e6a
    if (memoryAGet(ds, 0x8551) != 0x08)
        goto loc_3d59;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3d4c;
    al = 0x0f;
    goto loc_3d4e;
loc_3d4c: // 01ed:1e7c
    al = 0x2b;
loc_3d4e: // 01ed:1e7e
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    sub_40b7();
    goto loc_3d5e;
loc_3d59: // 01ed:1e89
    memoryASet(ds, 0x792c, 0x24);
loc_3d5e: // 01ed:1e8e
    bp = pop();
    sp += 2;
}
void sub_3d60() // 01ed:1e90
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3d6c;
    sub_ca53();
loc_3d6c: // 01ed:1e9c
    if (memoryAGet(ds, 0x8551) != 0x08)
        goto loc_3d8b;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3d7e;
    al = 0x0f;
    goto loc_3d80;
loc_3d7e: // 01ed:1eae
    al = 0x2b;
loc_3d80: // 01ed:1eb0
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    sub_4008();
    goto loc_3d90;
loc_3d8b: // 01ed:1ebb
    memoryASet(ds, 0x792c, 0x23);
loc_3d90: // 01ed:1ec0
    bp = pop();
    sp += 2;
}
void sub_3d92() // 01ed:1ec2
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3da1;
    sub_ca53();
loc_3da1: // 01ed:1ed1
    memoryASet(ss, bp - 1, 0x0b);
    memoryASet(ss, bp - 2, 0x05);
    memoryASet16(ss, bp - 6, 0x1ca4);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_3dcf;
    sub_3dd3();
loc_3dcf: // 01ed:1eff
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3dd3() // 01ed:1f03
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3ddf;
    sub_ca53();
loc_3ddf: // 01ed:1f0f
    memoryASet(ds, 0x792c, 0x01);
    memoryASet16(ds, 0xa1ac, 0x140c);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x04);
    al = 0x09;
    memoryASet(ds, 0x9bae, al);
    memoryASet(ds, 0x792a, al);
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    al = 0x16;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_3e0e() // 01ed:1f3e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3e1d;
    sub_ca53();
loc_3e1d: // 01ed:1f4d
    memoryASet(ss, bp - 1, 0x0b);
    memoryASet(ss, bp - 2, 0x05);
    memoryASet16(ss, bp - 6, 0x1cba);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_3e4b;
    sub_3e4f();
loc_3e4b: // 01ed:1f7b
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3e4f() // 01ed:1f7f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3e5b;
    sub_ca53();
loc_3e5b: // 01ed:1f8b
    memoryASet(ds, 0x792c, 0x02);
    memoryASet16(ds, 0xa1ac, 0x1460);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x04);
    memoryASet(ds, 0x792a, 0x09);
    memoryASet(ds, 0x9bae, 0x00);
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    al = 0x16;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_3e8e() // 01ed:1fbe
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3e9a;
    sub_ca53();
loc_3e9a: // 01ed:1fca
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3eaa;
    al = 0x02;
    goto loc_3eac;
loc_3eaa: // 01ed:1fda
    al = 0x26;
loc_3eac: // 01ed:1fdc
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_3ec4;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x38;
    goto loc_3f42;
loc_3ec4: // 01ed:1ff4
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17238) != 0x38)
        goto loc_3ee4;
    al = 0x38;
    goto loc_3f42;
loc_3ee4: // 01ed:2014
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3efa;
    al = 0x3a;
    goto loc_3f42;
loc_3efa: // 01ed:202a
    if (memoryAGet(ds, 0x855e) != 0x01)
        goto loc_3f0a;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x34;
    goto loc_3f42;
loc_3f0a: // 01ed:203a
    al = memoryAGet(ds, 0x856e);
    al += 0xfe;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17174) != 0x34)
        goto loc_3f2a;
    al = 0x34;
    goto loc_3f42;
loc_3f2a: // 01ed:205a
    al = memoryAGet(ds, 0x856e);
    al += 0xfe;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3f40;
    al = 0x36;
    goto loc_3f42;
loc_3f40: // 01ed:2070
    al = 0x1a;
loc_3f42: // 01ed:2072
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_3f4d() // 01ed:207d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3f59;
    sub_ca53();
loc_3f59: // 01ed:2089
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3f69;
    al = 0x02;
    goto loc_3f6b;
loc_3f69: // 01ed:2099
    al = 0x26;
loc_3f6b: // 01ed:209b
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_3f81;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x39;
    goto loc_3ffd;
loc_3f81: // 01ed:20b1
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17270) != 0x39)
        goto loc_3f9f;
    al = 0x39;
    goto loc_3ffd;
loc_3f9f: // 01ed:20cf
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3fb5;
    al = 0x3b;
    goto loc_3ffd;
loc_3fb5: // 01ed:20e5
    if (memoryAGet(ds, 0x855e) != 0x06)
        goto loc_3fc5;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x35;
    goto loc_3ffd;
loc_3fc5: // 01ed:20f5
    al = memoryAGet(ds, 0x856e);
    al++;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17206) != 0x35)
        goto loc_3fe5;
    al = 0x35;
    goto loc_3ffd;
loc_3fe5: // 01ed:2115
    al = memoryAGet(ds, 0x856e);
    al += 0x02;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3ffb;
    al = 0x37;
    goto loc_3ffd;
loc_3ffb: // 01ed:212b
    al = 0x1b;
loc_3ffd: // 01ed:212d
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_4008() // 01ed:2138
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4016;
    sub_ca53();
loc_4016: // 01ed:2146
    memoryASet(ds, 0x8551, 0x00);
    if (!(memoryAGet(ds, 0x8244) & 0x12))
        goto loc_403f;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_402d;
    al = 0x15;
    goto loc_402f;
loc_402d: // 01ed:215d
    al = 0x2a;
loc_402f: // 01ed:215f
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x32;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_403f: // 01ed:216f
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_4057;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x27;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_4057: // 01ed:2187
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17110);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x25)
        goto loc_4081;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_4081: // 01ed:21b1
    sub_408b();
loc_4084: // 01ed:21b4
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_408b() // 01ed:21bb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4097;
    sub_ca53();
loc_4097: // 01ed:21c7
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_40ad;
    al = 0x29;
    goto loc_40af;
loc_40ad: // 01ed:21dd
    al = 0x25;
loc_40af: // 01ed:21df
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_40b7() // 01ed:21e7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_40c5;
    sub_ca53();
loc_40c5: // 01ed:21f5
    if (!(memoryAGet(ds, 0x8244) & 0x12))
        goto loc_40e9;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_40d7;
    al = 0x15;
    goto loc_40d9;
loc_40d7: // 01ed:2207
    al = 0x2a;
loc_40d9: // 01ed:2209
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x33;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_40e9: // 01ed:2219
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_40ff;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x28;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_40ff: // 01ed:222f
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17142);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x26)
        goto loc_4127;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_4127: // 01ed:2257
    sub_4131();
loc_412a: // 01ed:225a
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4131() // 01ed:2261
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_413d;
    sub_ca53();
loc_413d: // 01ed:226d
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_4153;
    al = 0x2a;
    goto loc_4155;
loc_4153: // 01ed:2283
    al = 0x26;
loc_4155: // 01ed:2285
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_415d() // 01ed:228d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4169;
    sub_ca53();
loc_4169: // 01ed:2299
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x00;
    memoryASet(ds, 0x792a, al);
    memoryASet(ds, 0xa1aa, al);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_4180() // 01ed:22b0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_418c;
    sub_ca53();
loc_418c: // 01ed:22bc
    sub_41cc();
    bp = pop();
    sp += 2;
}
void sub_4191() // 01ed:22c1
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_419d;
    sub_ca53();
loc_419d: // 01ed:22cd
    sub_41cc();
    bp = pop();
    sp += 2;
}
void sub_41a2() // 01ed:22d2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_41ae;
    sub_ca53();
loc_41ae: // 01ed:22de
    al = memoryAGet(ds, 0xa0ce);
    al++;
    memoryASet(ds, 0xa0ce, al);
    if (al != 0x03)
        goto loc_41bf;
    sub_41cc();
    goto loc_41ca;
loc_41bf: // 01ed:22ef
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_41ca: // 01ed:22fa
    bp = pop();
    sp += 2;
}
void sub_41cc() // 01ed:22fc
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_41d9;
    sub_ca53();
loc_41d9: // 01ed:2309
    memoryASet(ds, 0xa0ce, 0x00);
    si = 0x03e8;
    goto loc_41e7;
loc_41e3: // 01ed:2313
    sub_423f();
    si--;
loc_41e7: // 01ed:2317
    if (si)
        goto loc_41e3;
    memoryASet(ds, 0x856d, 0x01);
    al = memoryAGet(ds, 0x791a);
    ah = 0x00;
    if (ax)
        goto loc_4200;
    al = 0xff;
    memoryASet(ds, 0x928d, al);
    goto loc_4207;
loc_4200: // 01ed:2330
    memoryASet(ds, 0x791a, memoryAGet(ds, 0x791a) - 1);
    al = memoryAGet(ds, 0x791a);
loc_4207: // 01ed:2337
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_420a() // 01ed:233a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4216;
    sub_ca53();
loc_4216: // 01ed:2346
    if (memoryAGet(ds, 0xa1b1) == 0x00)
        goto loc_423d;
    if (memoryAGet(ds, 0x8550) == 0x09)
        goto loc_422a;
    memoryASet(ds, 0x8550, memoryAGet(ds, 0x8550) + 1);
    goto loc_423d;
loc_422a: // 01ed:235a
    memoryASet(ds, 0x8550, 0x00);
    al = memoryAGet(ds, 0x8572);
    memoryASet(ds, 0x856f, al);
    al = 0x5a;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_423d: // 01ed:236d
    bp = pop();
    sp += 2;
}
void sub_423f() // 01ed:236f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_424b;
    sub_ca53();
loc_424b: // 01ed:237b
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x7924, al);
    bp = pop();
    sp += 2;
}
void sub_425e() // 01ed:238e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_426a;
    sub_ca53();
loc_426a: // 01ed:239a
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    dx = 0x0022;
    imul16(dx);
    dl = memoryAGet(ds, 0x792a);
    dh = 0x00;
    dx <<= 1;
    ax += dx;
    bx = ax;
    switch (bx)
    {
        case 0: sub_8518(); break;
        case 2: sub_8fe1(); break;
        case 4: sub_8fe1(); break;
        case 6: sub_8fe1(); break;
        case 8: sub_8fe1(); break;
        case 10: sub_8fe1(); break;
        case 12: sub_8fe1(); break;
        case 14: sub_85e7(); break;
        case 16: sub_841e(); break;
        case 18: sub_8457(); break;
        case 20: sub_8fe1(); break;
        case 22: sub_8fe1(); break;
        case 24: sub_8fe1(); break;
        case 26: sub_84cb(); break;
        case 28: sub_1ed0(); break;
        case 30: sub_1ed0(); break;
        case 32: sub_1ed0(); break;
        case 34: sub_8569(); break;
        case 36: sub_8fe1(); break;
        case 38: sub_8fe1(); break;
        case 40: sub_8fe1(); break;
        case 42: sub_81f6(); break;
        case 44: sub_83ec(); break;
        case 46: sub_85e7(); break;
        case 48: sub_841e(); break;
        case 50: sub_8457(); break;
        case 52: sub_84b5(); break;
        case 54: sub_84f7(); break;
        case 56: sub_8fe1(); break;
        case 58: sub_84cb(); break;
        case 60: sub_1ed0(); break;
        case 62: sub_1ed0(); break;
        case 64: sub_1ed0(); break;
        case 66: sub_1ed0(); break;
        case 68: sub_85a8(); break;
        case 70: sub_8fe1(); break;
        case 72: sub_8fe1(); break;
        case 74: sub_8fe1(); break;
        case 76: sub_8242(); break;
        case 78: sub_8405(); break;
        case 80: sub_85e7(); break;
        case 82: sub_841e(); break;
        case 84: sub_8457(); break;
        case 86: sub_84b5(); break;
        case 88: sub_84f7(); break;
        case 90: sub_8fe1(); break;
        case 92: sub_84cb(); break;
        case 94: sub_1ed0(); break;
        case 96: sub_1ed0(); break;
        case 98: sub_1ed0(); break;
        case 100: sub_1ed0(); break;
        case 102: sub_860a(); break;
        case 104: sub_8fe1(); break;
        case 106: sub_8fe1(); break;
        case 108: sub_83b2(); break;
        case 110: sub_84e1(); break;
        case 112: sub_8fe1(); break;
        case 114: sub_84f7(); break;
        case 116: sub_8fe1(); break;
        case 118: sub_1ed0(); break;
        case 120: sub_1ed0(); break;
        case 122: sub_1ed0(); break;
        case 124: sub_1ed0(); break;
        case 126: sub_1ed0(); break;
        case 128: sub_1ed0(); break;
        case 130: sub_1ed0(); break;
        case 132: sub_1ed0(); break;
        case 134: sub_1ed0(); break;
        case 136: sub_83cf(); break;
        case 138: sub_85e7(); break;
        case 140: sub_841e(); break;
        case 142: sub_8457(); break;
        case 144: sub_84b5(); break;
        case 146: sub_8fe1(); break;
        case 148: sub_84f7(); break;
        case 150: sub_84cb(); break;
        case 152: sub_1ed0(); break;
        case 154: sub_1ed0(); break;
        case 156: sub_1ed0(); break;
        case 158: sub_1ed0(); break;
        case 160: sub_1ed0(); break;
        case 162: sub_1ed0(); break;
        case 164: sub_1ed0(); break;
        case 166: sub_1ed0(); break;
        case 168: sub_1ed0(); break;
        case 170: sub_8fe1(); break;
        case 172: sub_8fe1(); break;
        case 174: sub_8fe1(); break;
        case 176: sub_8fe1(); break;
        case 178: sub_8fe1(); break;
        case 180: sub_8fe1(); break;
        case 182: sub_8fe1(); break;
        case 184: sub_8fe1(); break;
        case 186: sub_8fe1(); break;
        case 188: sub_8fe1(); break;
        case 190: sub_8fe1(); break;
        case 192: sub_8fe1(); break;
        case 194: sub_8fe1(); break;
        case 196: sub_8fe1(); break;
        case 198: sub_8fe1(); break;
        case 200: sub_8fe1(); break;
        case 202: sub_8fe1(); break;
        case 204: sub_860a(); break;
        case 206: sub_84e1(); break;
        case 208: sub_8fe1(); break;
        case 210: sub_85e7(); break;
        case 212: sub_834e(); break;
        case 214: sub_8457(); break;
        case 216: sub_8fe1(); break;
        case 218: sub_8fe1(); break;
        case 220: sub_8fe1(); break;
        case 222: sub_84cb(); break;
        case 224: sub_1ed0(); break;
        case 226: sub_1ed0(); break;
        case 228: sub_1ed0(); break;
        case 230: sub_1ed0(); break;
        case 232: sub_1ed0(); break;
        case 234: sub_1ed0(); break;
        case 236: sub_1ed0(); break;
        case 238: sub_860a(); break;
        case 240: sub_84e1(); break;
        case 242: sub_8fe1(); break;
        case 244: sub_8fe1(); break;
        case 246: sub_85e7(); break;
        case 248: sub_834e(); break;
        case 250: sub_8457(); break;
        case 252: sub_8fe1(); break;
        case 254: sub_8fe1(); break;
        case 256: sub_8fe1(); break;
        case 258: sub_84cb(); break;
        case 260: sub_1ed0(); break;
        case 262: sub_1ed0(); break;
        case 264: sub_1ed0(); break;
        case 266: sub_1ed0(); break;
        case 268: sub_1ed0(); break;
        case 270: sub_1ed0(); break;
        case 272: sub_8618(); break;
        case 274: sub_8fe1(); break;
        case 276: sub_81f6(); break;
        case 278: sub_83ec(); break;
        case 280: sub_85e7(); break;
        case 282: sub_841e(); break;
        case 284: sub_8457(); break;
        case 286: sub_8fe1(); break;
        case 288: sub_84f7(); break;
        case 290: sub_8fe1(); break;
        case 292: sub_84cb(); break;
        case 294: sub_1ed0(); break;
        case 296: sub_1ed0(); break;
        case 298: sub_1ed0(); break;
        case 300: sub_1ed0(); break;
        case 302: sub_1ed0(); break;
        case 304: sub_1ed0(); break;
        case 306: sub_8659(); break;
        case 308: sub_8fe1(); break;
        case 310: sub_8242(); break;
        case 312: sub_8405(); break;
        case 314: sub_85e7(); break;
        case 316: sub_841e(); break;
        case 318: sub_8457(); break;
        case 320: sub_8fe1(); break;
        case 322: sub_84f7(); break;
        case 324: sub_8fe1(); break;
        case 326: sub_84cb(); break;
        case 328: sub_1ed0(); break;
        case 330: sub_1ed0(); break;
        case 332: sub_1ed0(); break;
        case 334: sub_1ed0(); break;
        case 336: sub_1ed0(); break;
        case 338: sub_1ed0(); break;
        case 340: sub_8fe1(); break;
        case 342: sub_8fe1(); break;
        case 344: sub_8fe1(); break;
        case 346: sub_8fe1(); break;
        case 348: sub_8fe1(); break;
        case 350: sub_8fe1(); break;
        case 352: sub_8fe1(); break;
        case 354: sub_8fe1(); break;
        case 356: sub_8fe1(); break;
        case 358: sub_8fe1(); break;
        case 360: sub_8fe1(); break;
        case 362: sub_8fe1(); break;
        case 364: sub_8fe1(); break;
        case 366: sub_8fe1(); break;
        case 368: sub_8fe1(); break;
        case 370: sub_8fe1(); break;
        case 372: sub_8fe1(); break;
        case 374: sub_8fe1(); break;
        case 376: sub_8fe1(); break;
        case 378: sub_8fe1(); break;
        case 380: sub_8fe1(); break;
        case 382: sub_8fe1(); break;
        case 384: sub_8fe1(); break;
        case 386: sub_8fe1(); break;
        case 388: sub_8fe1(); break;
        case 390: sub_8fe1(); break;
        case 392: sub_8fe1(); break;
        case 394: sub_8fe1(); break;
        case 396: sub_8fe1(); break;
        case 398: sub_8fe1(); break;
        case 400: sub_8fe1(); break;
        case 402: sub_8fe1(); break;
        case 404: sub_8fe1(); break;
        case 406: sub_8fe1(); break;
        case 408: sub_8fe1(); break;
        case 410: sub_8fe1(); break;
        case 412: sub_8fe1(); break;
        case 414: sub_8fe1(); break;
        case 416: sub_8fe1(); break;
        case 418: sub_8fe1(); break;
        case 420: sub_8fe1(); break;
        case 422: sub_8fe1(); break;
        case 424: sub_8fe1(); break;
        case 426: sub_8fe1(); break;
        case 428: sub_8fe1(); break;
        case 430: sub_8fe1(); break;
        case 432: sub_8fe1(); break;
        case 434: sub_8fe1(); break;
        case 436: sub_8fe1(); break;
        case 438: sub_8fe1(); break;
        case 440: sub_8fe1(); break;
        case 442: sub_8fe1(); break;
        case 444: sub_8fe1(); break;
        case 446: sub_8fe1(); break;
        case 448: sub_8fe1(); break;
        case 450: sub_8fe1(); break;
        case 452: sub_8fe1(); break;
        case 454: sub_8fe1(); break;
        case 456: sub_8fe1(); break;
        case 458: sub_8fe1(); break;
        case 460: sub_8fe1(); break;
        case 462: sub_8fe1(); break;
        case 464: sub_8fe1(); break;
        case 466: sub_8fe1(); break;
        case 468: sub_8fe1(); break;
        case 470: sub_8fe1(); break;
        case 472: sub_8fe1(); break;
        case 474: sub_8fe1(); break;
        case 476: sub_8fe1(); break;
        case 478: sub_8fe1(); break;
        case 480: sub_8fe1(); break;
        case 482: sub_8fe1(); break;
        case 484: sub_8fe1(); break;
        case 486: sub_8fe1(); break;
        case 488: sub_8fe1(); break;
        case 490: sub_8fe1(); break;
        case 492: sub_8fe1(); break;
        case 494: sub_8fe1(); break;
        case 496: sub_8fe1(); break;
        case 498: sub_8fe1(); break;
        case 500: sub_8fe1(); break;
        case 502: sub_8fe1(); break;
        case 504: sub_8fe1(); break;
        case 506: sub_8fe1(); break;
        case 508: sub_8fe1(); break;
        case 510: sub_8fe1(); break;
        case 512: sub_8fe1(); break;
        case 514: sub_8fe1(); break;
        case 516: sub_8fe1(); break;
        case 518: sub_8fe1(); break;
        case 520: sub_8fe1(); break;
        case 522: sub_8fe1(); break;
        case 524: sub_84cb(); break;
        case 526: sub_84f7(); break;
        case 528: sub_8fe1(); break;
        case 530: sub_8fe1(); break;
        case 532: sub_8fe1(); break;
        case 534: sub_8fe1(); break;
        case 536: sub_8fe1(); break;
        case 538: sub_8fe1(); break;
        case 540: sub_8fe1(); break;
        case 542: sub_8fe1(); break;
        case 544: sub_81d5(); break;
        case 546: sub_8fe1(); break;
        case 548: sub_8fe1(); break;
        case 550: sub_8fe1(); break;
        case 552: sub_8fe1(); break;
        case 554: sub_8fe1(); break;
        case 556: sub_8fe1(); break;
        case 558: sub_8fe1(); break;
        case 560: sub_8fe1(); break;
        case 562: sub_8fe1(); break;
        case 564: sub_8fe1(); break;
        case 566: sub_8fe1(); break;
        case 568: sub_8fe1(); break;
        case 570: sub_8fe1(); break;
        case 572: sub_8fe1(); break;
        case 574: sub_8fe1(); break;
        case 576: sub_8fe1(); break;
        case 578: sub_8518(); break;
        case 580: sub_8fe1(); break;
        case 582: sub_8fe1(); break;
        case 584: sub_8fe1(); break;
        case 586: sub_8fe1(); break;
        case 588: sub_8fe1(); break;
        case 590: sub_841e(); break;
        case 592: sub_8457(); break;
        case 594: sub_8fe1(); break;
        case 596: sub_8fe1(); break;
        case 598: sub_8fe1(); break;
        case 600: sub_84cb(); break;
        case 602: sub_1ed0(); break;
        case 604: sub_1ed0(); break;
        case 606: sub_1ed0(); break;
        case 608: sub_1ed0(); break;
        case 610: sub_1ed0(); break;
        case 612: sub_8569(); break;
        case 614: sub_8fe1(); break;
        case 616: sub_8fe1(); break;
        case 618: sub_8fe1(); break;
        case 620: sub_82dc(); break;
        case 622: sub_841e(); break;
        case 624: sub_8457(); break;
        case 626: sub_84b5(); break;
        case 628: sub_8fe1(); break;
        case 630: sub_8fe1(); break;
        case 632: sub_84cb(); break;
        case 634: sub_1ed0(); break;
        case 636: sub_1ed0(); break;
        case 638: sub_1ed0(); break;
        case 640: sub_1ed0(); break;
        case 642: sub_1ed0(); break;
        case 644: sub_1ed0(); break;
        case 646: sub_85a8(); break;
        case 648: sub_8fe1(); break;
        case 650: sub_8fe1(); break;
        case 652: sub_8fe1(); break;
        case 654: sub_82dc(); break;
        case 656: sub_841e(); break;
        case 658: sub_8457(); break;
        case 660: sub_84b5(); break;
        case 662: sub_8fe1(); break;
        case 664: sub_8fe1(); break;
        case 666: sub_84cb(); break;
        case 668: sub_1ed0(); break;
        case 670: sub_1ed0(); break;
        case 672: sub_1ed0(); break;
        case 674: sub_1ed0(); break;
        case 676: sub_1ed0(); break;
        case 678: sub_1ed0(); break;
        case 680: sub_8618(); break;
        case 682: sub_8fe1(); break;
        case 684: sub_8fe1(); break;
        case 686: sub_82dc(); break;
        case 688: sub_8fe1(); break;
        case 690: sub_8fe1(); break;
        case 692: sub_841e(); break;
        case 694: sub_8457(); break;
        case 696: sub_8fe1(); break;
        case 698: sub_8fe1(); break;
        case 700: sub_8fe1(); break;
        case 702: sub_84cb(); break;
        case 704: sub_1ed0(); break;
        case 706: sub_1ed0(); break;
        case 708: sub_1ed0(); break;
        case 710: sub_1ed0(); break;
        case 712: sub_1ed0(); break;
        case 714: sub_8659(); break;
        case 716: sub_8fe1(); break;
        case 718: sub_8fe1(); break;
        case 720: sub_82dc(); break;
        case 722: sub_8fe1(); break;
        case 724: sub_8fe1(); break;
        case 726: sub_841e(); break;
        case 728: sub_8457(); break;
        case 730: sub_8fe1(); break;
        case 732: sub_8fe1(); break;
        case 734: sub_8fe1(); break;
        case 736: sub_84cb(); break;
        case 738: sub_1ed0(); break;
        case 740: sub_1ed0(); break;
        case 742: sub_1ed0(); break;
        case 744: sub_1ed0(); break;
        case 746: sub_1ed0(); break;
        case 748: sub_8569(); break;
        case 750: sub_8fe1(); break;
        case 752: sub_8fe1(); break;
        case 754: sub_8fe1(); break;
        case 756: sub_81f6(); break;
        case 758: sub_8fe1(); break;
        case 760: sub_832d(); break;
        case 762: sub_8fe1(); break;
        case 764: sub_8fe1(); break;
        case 766: sub_8fe1(); break;
        case 768: sub_841e(); break;
        case 770: sub_8457(); break;
        case 772: sub_84b5(); break;
        case 774: sub_8fe1(); break;
        case 776: sub_8fe1(); break;
        case 778: sub_84cb(); break;
        case 780: sub_8fe1(); break;
        case 782: sub_85a8(); break;
        case 784: sub_8fe1(); break;
        case 786: sub_8fe1(); break;
        case 788: sub_8fe1(); break;
        case 790: sub_8242(); break;
        case 792: sub_8fe1(); break;
        case 794: sub_832d(); break;
        case 796: sub_8fe1(); break;
        case 798: sub_8fe1(); break;
        case 800: sub_8fe1(); break;
        case 802: sub_841e(); break;
        case 804: sub_8457(); break;
        case 806: sub_84b5(); break;
        case 808: sub_8fe1(); break;
        case 810: sub_8fe1(); break;
        case 812: sub_84cb(); break;
        case 814: sub_8fe1(); break;
        case 816: sub_8618(); break;
        case 818: sub_8fe1(); break;
        case 820: sub_81f6(); break;
        case 822: sub_8fe1(); break;
        case 824: sub_832d(); break;
        case 826: sub_8fe1(); break;
        case 828: sub_8fe1(); break;
        case 830: sub_8fe1(); break;
        case 832: sub_8fe1(); break;
        case 834: sub_8fe1(); break;
        case 836: sub_841e(); break;
        case 838: sub_8457(); break;
        case 840: sub_8fe1(); break;
        case 842: sub_8fe1(); break;
        case 844: sub_8fe1(); break;
        case 846: sub_84cb(); break;
        case 848: sub_8fe1(); break;
        case 850: sub_8659(); break;
        case 852: sub_8fe1(); break;
        case 854: sub_8242(); break;
        case 856: sub_8fe1(); break;
        case 858: sub_832d(); break;
        case 860: sub_8fe1(); break;
        case 862: sub_8fe1(); break;
        case 864: sub_8fe1(); break;
        case 866: sub_8fe1(); break;
        case 868: sub_8fe1(); break;
        case 870: sub_841e(); break;
        case 872: sub_8457(); break;
        case 874: sub_8fe1(); break;
        case 876: sub_8fe1(); break;
        case 878: sub_8fe1(); break;
        case 880: sub_84cb(); break;
        case 882: sub_8fe1(); break;
        case 884: sub_84a2(); break;
        case 886: sub_81f6(); break;
        case 888: sub_83ec(); break;
        case 890: sub_87ce(); break;
        case 892: sub_84f7(); break;
        case 894: sub_83ec(); break;
        case 896: sub_85e7(); break;
        case 898: sub_841e(); break;
        case 900: sub_8457(); break;
        case 902: sub_84b5(); break;
        case 904: sub_84f7(); break;
        case 906: sub_8fe1(); break;
        case 908: sub_84cb(); break;
        case 910: sub_1ed0(); break;
        case 912: sub_1ed0(); break;
        case 914: sub_1ed0(); break;
        case 916: sub_1ed0(); break;
        case 918: sub_84a2(); break;
        case 920: sub_8242(); break;
        case 922: sub_8405(); break;
        case 924: sub_880a(); break;
        case 926: sub_84f7(); break;
        case 928: sub_8405(); break;
        case 930: sub_85e7(); break;
        case 932: sub_841e(); break;
        case 934: sub_8457(); break;
        case 936: sub_84b5(); break;
        case 938: sub_84f7(); break;
        case 940: sub_8fe1(); break;
        case 942: sub_84cb(); break;
        case 944: sub_1ed0(); break;
        case 946: sub_1ed0(); break;
        case 948: sub_1ed0(); break;
        case 950: sub_1ed0(); break;
        case 952: sub_8fe1(); break;
        case 954: sub_8fe1(); break;
        case 956: sub_8fe1(); break;
        case 958: sub_8fe1(); break;
        case 960: sub_8fe1(); break;
        case 962: sub_8fe1(); break;
        case 964: sub_8fe1(); break;
        case 966: sub_8fe1(); break;
        case 968: sub_8fe1(); break;
        case 970: sub_8fe1(); break;
        case 972: sub_8fe1(); break;
        case 974: sub_8fe1(); break;
        case 976: sub_8fe1(); break;
        case 978: sub_8fe1(); break;
        case 980: sub_8fe1(); break;
        case 982: sub_8fe1(); break;
        case 984: sub_8fe1(); break;
        case 986: sub_83b2(); break;
        case 988: sub_85e7(); break;
        case 990: sub_8fe1(); break;
        case 992: sub_8fe1(); break;
        case 994: sub_8fe1(); break;
        case 996: sub_8fe1(); break;
        case 998: sub_84f7(); break;
        case 1000: sub_84b5(); break;
        case 1002: sub_1ed0(); break;
        case 1004: sub_1ed0(); break;
        case 1006: sub_1ed0(); break;
        case 1008: sub_1ed0(); break;
        case 1010: sub_1ed0(); break;
        case 1012: sub_1ed0(); break;
        case 1014: sub_1ed0(); break;
        case 1016: sub_1ed0(); break;
        case 1018: sub_1ed0(); break;
        case 1020: sub_83cf(); break;
        case 1022: sub_85e7(); break;
        case 1024: sub_8fe1(); break;
        case 1026: sub_8fe1(); break;
        case 1028: sub_8fe1(); break;
        case 1030: sub_8fe1(); break;
        case 1032: sub_84f7(); break;
        case 1034: sub_84b5(); break;
        case 1036: sub_1ed0(); break;
        case 1038: sub_1ed0(); break;
        case 1040: sub_1ed0(); break;
        case 1042: sub_1ed0(); break;
        case 1044: sub_1ed0(); break;
        case 1046: sub_1ed0(); break;
        case 1048: sub_1ed0(); break;
        case 1050: sub_1ed0(); break;
        case 1052: sub_1ed0(); break;
        case 1054: sub_83ec(); break;
        case 1056: sub_8fe1(); break;
        case 1058: sub_85e7(); break;
        case 1060: sub_8fe1(); break;
        case 1062: sub_8fe1(); break;
        case 1064: sub_8fe1(); break;
        case 1066: sub_8fe1(); break;
        case 1068: sub_8fe1(); break;
        case 1070: sub_84f7(); break;
        case 1072: sub_84b5(); break;
        case 1074: sub_1ed0(); break;
        case 1076: sub_1ed0(); break;
        case 1078: sub_1ed0(); break;
        case 1080: sub_1ed0(); break;
        case 1082: sub_1ed0(); break;
        case 1084: sub_1ed0(); break;
        case 1086: sub_1ed0(); break;
        case 1088: sub_8405(); break;
        case 1090: sub_8fe1(); break;
        case 1092: sub_85e7(); break;
        case 1094: sub_8fe1(); break;
        case 1096: sub_8fe1(); break;
        case 1098: sub_8fe1(); break;
        case 1100: sub_8fe1(); break;
        case 1102: sub_8fe1(); break;
        case 1104: sub_84f7(); break;
        case 1106: sub_84b5(); break;
        case 1108: sub_1ed0(); break;
        case 1110: sub_1ed0(); break;
        case 1112: sub_1ed0(); break;
        case 1114: sub_1ed0(); break;
        case 1116: sub_1ed0(); break;
        case 1118: sub_1ed0(); break;
        case 1120: sub_1ed0(); break;
        case 1122: sub_8569(); break;
        case 1124: sub_8fe1(); break;
        case 1126: sub_8fe1(); break;
        case 1128: sub_8fe1(); break;
        case 1130: sub_8391(); break;
        case 1132: sub_8fe1(); break;
        case 1134: sub_8fe1(); break;
        case 1136: sub_8fe1(); break;
        case 1138: sub_8fe1(); break;
        case 1140: sub_8fe1(); break;
        case 1142: sub_8fe1(); break;
        case 1144: sub_8fe1(); break;
        case 1146: sub_8fe1(); break;
        case 1148: sub_8fe1(); break;
        case 1150: sub_8fe1(); break;
        case 1152: sub_8fe1(); break;
        case 1154: sub_8fe1(); break;
        case 1156: sub_85a8(); break;
        case 1158: sub_8fe1(); break;
        case 1160: sub_8fe1(); break;
        case 1162: sub_8fe1(); break;
        case 1164: sub_8391(); break;
        case 1166: sub_8fe1(); break;
        case 1168: sub_8fe1(); break;
        case 1170: sub_8fe1(); break;
        case 1172: sub_8fe1(); break;
        case 1174: sub_8fe1(); break;
        case 1176: sub_8fe1(); break;
        case 1178: sub_8fe1(); break;
        case 1180: sub_8fe1(); break;
        case 1182: sub_8fe1(); break;
        case 1184: sub_8fe1(); break;
        case 1186: sub_8fe1(); break;
        case 1188: sub_8fe1(); break;
        case 1190: sub_8fe1(); break;
        case 1192: sub_8fe1(); break;
        case 1194: sub_8fe1(); break;
        case 1196: sub_8fe1(); break;
        case 1198: sub_8fe1(); break;
        case 1200: sub_8fe1(); break;
        case 1202: sub_8fe1(); break;
        case 1204: sub_8fe1(); break;
        case 1206: sub_8fe1(); break;
        case 1208: sub_8fe1(); break;
        case 1210: sub_8fe1(); break;
        case 1212: sub_8fe1(); break;
        case 1214: sub_8fe1(); break;
        case 1216: sub_8fe1(); break;
        case 1218: sub_8fe1(); break;
        case 1220: sub_8fe1(); break;
        case 1222: sub_8fe1(); break;
        case 1224: sub_8fe1(); break;
        case 1226: sub_8fe1(); break;
        case 1228: sub_8fe1(); break;
        case 1230: sub_8fe1(); break;
        case 1232: sub_8fe1(); break;
        case 1234: sub_8fe1(); break;
        case 1236: sub_8fe1(); break;
        case 1238: sub_8fe1(); break;
        case 1240: sub_8fe1(); break;
        case 1242: sub_8fe1(); break;
        case 1244: sub_8fe1(); break;
        case 1246: sub_8fe1(); break;
        case 1248: sub_8fe1(); break;
        case 1250: sub_8fe1(); break;
        case 1252: sub_8fe1(); break;
        case 1254: sub_8fe1(); break;
        case 1256: sub_8fe1(); break;
        case 1258: sub_86b2(); break;
        case 1260: sub_84f7(); break;
        case 1262: sub_83ec(); break;
        case 1264: sub_84a2(); break;
        case 1266: sub_8fe1(); break;
        case 1268: sub_1ed0(); break;
        case 1270: sub_1ed0(); break;
        case 1272: sub_1ed0(); break;
        case 1274: sub_1ed0(); break;
        case 1276: sub_1ed0(); break;
        case 1278: sub_1ed0(); break;
        case 1280: sub_1ed0(); break;
        case 1282: sub_1ed0(); break;
        case 1284: sub_1ed0(); break;
        case 1286: sub_1ed0(); break;
        case 1288: sub_1ed0(); break;
        case 1290: sub_1ed0(); break;
        case 1292: sub_86e3(); break;
        case 1294: sub_84f7(); break;
        case 1296: sub_8405(); break;
        case 1298: sub_84a2(); break;
        case 1300: sub_8fe1(); break;
        case 1302: sub_1ed0(); break;
        case 1304: sub_1ed0(); break;
        case 1306: sub_1ed0(); break;
        case 1308: sub_1ed0(); break;
        case 1310: sub_1ed0(); break;
        case 1312: sub_1ed0(); break;
        case 1314: sub_1ed0(); break;
        case 1316: sub_1ed0(); break;
        case 1318: sub_1ed0(); break;
        case 1320: sub_1ed0(); break;
        case 1322: sub_1ed0(); break;
        case 1324: sub_1ed0(); break;
        case 1326: sub_869a(); break;
        case 1328: sub_84f7(); break;
        case 1330: sub_82dc(); break;
        case 1332: sub_85e7(); break;
        case 1334: sub_841e(); break;
        case 1336: sub_8457(); break;
        case 1338: sub_84a2(); break;
        case 1340: sub_81f6(); break;
        case 1342: sub_8fe1(); break;
        case 1344: sub_84cb(); break;
        case 1346: sub_1ed0(); break;
        case 1348: sub_1ed0(); break;
        case 1350: sub_1ed0(); break;
        case 1352: sub_1ed0(); break;
        case 1354: sub_1ed0(); break;
        case 1356: sub_1ed0(); break;
        case 1358: sub_1ed0(); break;
        case 1360: sub_86cb(); break;
        case 1362: sub_84f7(); break;
        case 1364: sub_82dc(); break;
        case 1366: sub_85e7(); break;
        case 1368: sub_841e(); break;
        case 1370: sub_8457(); break;
        case 1372: sub_84a2(); break;
        case 1374: sub_8242(); break;
        case 1376: sub_8fe1(); break;
        case 1378: sub_84cb(); break;
        case 1380: sub_1ed0(); break;
        case 1382: sub_1ed0(); break;
        case 1384: sub_1ed0(); break;
        case 1386: sub_1ed0(); break;
        case 1388: sub_1ed0(); break;
        case 1390: sub_1ed0(); break;
        case 1392: sub_1ed0(); break;
        case 1394: sub_8702(); break;
        case 1396: sub_84f7(); break;
        case 1398: sub_8fe1(); break;
        case 1400: sub_832d(); break;
        case 1402: sub_81f6(); break;
        case 1404: sub_8fe1(); break;
        case 1406: sub_85e7(); break;
        case 1408: sub_841e(); break;
        case 1410: sub_8457(); break;
        case 1412: sub_84a2(); break;
        case 1414: sub_8fe1(); break;
        case 1416: sub_8fe1(); break;
        case 1418: sub_84cb(); break;
        case 1420: sub_1ed0(); break;
        case 1422: sub_1ed0(); break;
        case 1424: sub_1ed0(); break;
        case 1426: sub_1ed0(); break;
        case 1428: sub_871b(); break;
        case 1430: sub_84f7(); break;
        case 1432: sub_8fe1(); break;
        case 1434: sub_832d(); break;
        case 1436: sub_8242(); break;
        case 1438: sub_8fe1(); break;
        case 1440: sub_85e7(); break;
        case 1442: sub_841e(); break;
        case 1444: sub_8457(); break;
        case 1446: sub_84a2(); break;
        case 1448: sub_8fe1(); break;
        case 1450: sub_8fe1(); break;
        case 1452: sub_84cb(); break;
        case 1454: sub_1ed0(); break;
        case 1456: sub_1ed0(); break;
        case 1458: sub_1ed0(); break;
        case 1460: sub_1ed0(); break;
        case 1462: sub_860a(); break;
        case 1464: sub_84e1(); break;
        case 1466: sub_8fe1(); break;
        case 1468: sub_85e7(); break;
        case 1470: sub_834e(); break;
        case 1472: sub_8457(); break;
        case 1474: sub_8fe1(); break;
        case 1476: sub_8fe1(); break;
        case 1478: sub_8fe1(); break;
        case 1480: sub_84cb(); break;
        case 1482: sub_1ed0(); break;
        case 1484: sub_1ed0(); break;
        case 1486: sub_1ed0(); break;
        case 1488: sub_1ed0(); break;
        case 1490: sub_1ed0(); break;
        case 1492: sub_1ed0(); break;
        case 1494: sub_1ed0(); break;
        case 1496: sub_81d5(); break;
        case 1498: sub_8fe1(); break;
        case 1500: sub_8fe1(); break;
        case 1502: sub_8fe1(); break;
        case 1504: sub_8fe1(); break;
        case 1506: sub_8fe1(); break;
        case 1508: sub_8fe1(); break;
        case 1510: sub_8fe1(); break;
        case 1512: sub_8fe1(); break;
        case 1514: sub_8fe1(); break;
        case 1516: sub_8fe1(); break;
        case 1518: sub_8fe1(); break;
        case 1520: sub_8fe1(); break;
        case 1522: sub_8fe1(); break;
        case 1524: sub_8fe1(); break;
        case 1526: sub_8fe1(); break;
        case 1528: sub_8fe1(); break;
        case 1530: sub_8fe1(); break;
        case 1532: sub_8fe1(); break;
        case 1534: sub_8fe1(); break;
        case 1536: sub_8fe1(); break;
        case 1538: sub_8fe1(); break;
        case 1540: sub_8fe1(); break;
        case 1542: sub_8fe1(); break;
        case 1544: sub_8fe1(); break;
        case 1546: sub_8fe1(); break;
        case 1548: sub_8fe1(); break;
        case 1550: sub_8fe1(); break;
        case 1552: sub_8fe1(); break;
        case 1554: sub_8fe1(); break;
        case 1556: sub_8fe1(); break;
        case 1558: sub_8fe1(); break;
        case 1560: sub_8fe1(); break;
        case 1562: sub_8fe1(); break;
        case 1564: sub_8fe1(); break;
        case 1566: sub_8fe1(); break;
        case 1568: sub_8fe1(); break;
        case 1570: sub_8fe1(); break;
        case 1572: sub_8fe1(); break;
        case 1574: sub_8fe1(); break;
        case 1576: sub_8fe1(); break;
        case 1578: sub_8fe1(); break;
        case 1580: sub_8fe1(); break;
        case 1582: sub_8fe1(); break;
        case 1584: sub_8fe1(); break;
        case 1586: sub_8fe1(); break;
        case 1588: sub_8fe1(); break;
        case 1590: sub_8fe1(); break;
        case 1592: sub_8fe1(); break;
        case 1594: sub_8fe1(); break;
        case 1596: sub_8fe1(); break;
        case 1598: sub_8fe1(); break;
        case 1600: sub_8fe1(); break;
        case 1602: sub_8fe1(); break;
        case 1604: sub_8fe1(); break;
        case 1606: sub_8fe1(); break;
        case 1608: sub_8fe1(); break;
        case 1610: sub_8fe1(); break;
        case 1612: sub_8fe1(); break;
        case 1614: sub_8fe1(); break;
        case 1616: sub_8fe1(); break;
        case 1618: sub_8fe1(); break;
        case 1620: sub_8fe1(); break;
        case 1622: sub_8fe1(); break;
        case 1624: sub_8fe1(); break;
        case 1626: sub_8fe1(); break;
        case 1628: sub_8fe1(); break;
        case 1630: sub_8fe1(); break;
        case 1632: sub_8fe1(); break;
        case 1634: sub_8fe1(); break;
        case 1636: sub_8fe1(); break;
        case 1638: sub_8fe1(); break;
        case 1640: sub_8fe1(); break;
        case 1642: sub_8fe1(); break;
        case 1644: sub_8fe1(); break;
        case 1646: sub_8fe1(); break;
        case 1648: sub_8fe1(); break;
        case 1650: sub_8fe1(); break;
        case 1652: sub_8fe1(); break;
        case 1654: sub_8fe1(); break;
        case 1656: sub_8fe1(); break;
        case 1658: sub_8fe1(); break;
        case 1660: sub_8fe1(); break;
        case 1662: sub_8fe1(); break;
        case 1664: sub_8fe1(); break;
        case 1666: sub_8fe1(); break;
        case 1668: sub_8fe1(); break;
        case 1670: sub_8fe1(); break;
        case 1672: sub_8fe1(); break;
        case 1674: sub_8fe1(); break;
        case 1676: sub_8fe1(); break;
        case 1678: sub_8fe1(); break;
        case 1680: sub_8fe1(); break;
        case 1682: sub_8fe1(); break;
        case 1684: sub_8fe1(); break;
        case 1686: sub_8fe1(); break;
        case 1688: sub_8fe1(); break;
        case 1690: sub_8fe1(); break;
        case 1692: sub_8fe1(); break;
        case 1694: sub_8fe1(); break;
        case 1696: sub_8fe1(); break;
        case 1698: sub_8fe1(); break;
        case 1700: sub_8fe1(); break;
        case 1702: sub_84f7(); break;
        case 1704: sub_8fe1(); break;
        case 1706: sub_85e7(); break;
        case 1708: sub_841e(); break;
        case 1710: sub_8457(); break;
        case 1712: sub_84b5(); break;
        case 1714: sub_8fe1(); break;
        case 1716: sub_8fe1(); break;
        case 1718: sub_84cb(); break;
        case 1720: sub_8fe1(); break;
        case 1722: sub_8fe1(); break;
        case 1724: sub_8fe1(); break;
        case 1726: sub_8fe1(); break;
        case 1728: sub_8fe1(); break;
        case 1730: sub_8fe1(); break;
        case 1732: sub_8fe1(); break;
        case 1734: sub_8fe1(); break;
        case 1736: sub_84f7(); break;
        case 1738: sub_8fe1(); break;
        case 1740: sub_85e7(); break;
        case 1742: sub_841e(); break;
        case 1744: sub_8457(); break;
        case 1746: sub_84b5(); break;
        case 1748: sub_8fe1(); break;
        case 1750: sub_8fe1(); break;
        case 1752: sub_84cb(); break;
        case 1754: sub_8fe1(); break;
        case 1756: sub_8fe1(); break;
        case 1758: sub_8fe1(); break;
        case 1760: sub_8fe1(); break;
        case 1762: sub_8fe1(); break;
        case 1764: sub_8fe1(); break;
        case 1766: sub_8fe1(); break;
        case 1768: sub_84a2(); break;
        case 1770: sub_81f6(); break;
        case 1772: sub_83ec(); break;
        case 1774: sub_87b6(); break;
        case 1776: sub_84f7(); break;
        case 1778: sub_8fe1(); break;
        case 1780: sub_82dc(); break;
        case 1782: sub_81f6(); break;
        case 1784: sub_85e7(); break;
        case 1786: sub_841e(); break;
        case 1788: sub_8457(); break;
        case 1790: sub_84b5(); break;
        case 1792: sub_8fe1(); break;
        case 1794: sub_8fe1(); break;
        case 1796: sub_84cb(); break;
        case 1798: sub_8fe1(); break;
        case 1800: sub_8fe1(); break;
        case 1802: sub_84a2(); break;
        case 1804: sub_8242(); break;
        case 1806: sub_8405(); break;
        case 1808: sub_87f2(); break;
        case 1810: sub_84f7(); break;
        case 1812: sub_8fe1(); break;
        case 1814: sub_82dc(); break;
        case 1816: sub_8242(); break;
        case 1818: sub_85e7(); break;
        case 1820: sub_841e(); break;
        case 1822: sub_8457(); break;
        case 1824: sub_84b5(); break;
        case 1826: sub_8fe1(); break;
        case 1828: sub_8fe1(); break;
        case 1830: sub_84cb(); break;
        case 1832: sub_8fe1(); break;
        case 1834: sub_8fe1(); break;
        case 1836: sub_84a2(); break;
        case 1838: sub_81f6(); break;
        case 1840: sub_83ec(); break;
        case 1842: sub_87b6(); break;
        case 1844: sub_84f7(); break;
        case 1846: sub_8fe1(); break;
        case 1848: sub_8fe1(); break;
        case 1850: sub_8fe1(); break;
        case 1852: sub_832d(); break;
        case 1854: sub_8fe1(); break;
        case 1856: sub_85e7(); break;
        case 1858: sub_841e(); break;
        case 1860: sub_8457(); break;
        case 1862: sub_84b5(); break;
        case 1864: sub_8fe1(); break;
        case 1866: sub_8fe1(); break;
        case 1868: sub_84cb(); break;
        case 1870: sub_84a2(); break;
        case 1872: sub_8242(); break;
        case 1874: sub_8405(); break;
        case 1876: sub_87f2(); break;
        case 1878: sub_84f7(); break;
        case 1880: sub_8fe1(); break;
        case 1882: sub_8fe1(); break;
        case 1884: sub_8fe1(); break;
        case 1886: sub_832d(); break;
        case 1888: sub_8fe1(); break;
        case 1890: sub_85e7(); break;
        case 1892: sub_841e(); break;
        case 1894: sub_8457(); break;
        case 1896: sub_84b5(); break;
        case 1898: sub_8fe1(); break;
        case 1900: sub_8fe1(); break;
        case 1902: sub_84cb(); break;
        case 1904: sub_8760(); break;
        case 1906: sub_81f6(); break;
        case 1908: sub_82dc(); break;
        case 1910: sub_8405(); break;
        case 1912: sub_85e7(); break;
        case 1914: sub_841e(); break;
        case 1916: sub_8457(); break;
        case 1918: sub_84b5(); break;
        case 1920: sub_84f7(); break;
        case 1922: sub_8fe1(); break;
        case 1924: sub_84cb(); break;
        case 1926: sub_8fe1(); break;
        case 1928: sub_8fe1(); break;
        case 1930: sub_8fe1(); break;
        case 1932: sub_8fe1(); break;
        case 1934: sub_8fe1(); break;
        case 1936: sub_8fe1(); break;
        case 1938: sub_878b(); break;
        case 1940: sub_8242(); break;
        case 1942: sub_82dc(); break;
        case 1944: sub_83ec(); break;
        case 1946: sub_85e7(); break;
        case 1948: sub_841e(); break;
        case 1950: sub_8457(); break;
        case 1952: sub_84b5(); break;
        case 1954: sub_84f7(); break;
        case 1956: sub_8fe1(); break;
        case 1958: sub_84cb(); break;
        case 1960: sub_8fe1(); break;
        case 1962: sub_8fe1(); break;
        case 1964: sub_8fe1(); break;
        case 1966: sub_8fe1(); break;
        case 1968: sub_8fe1(); break;
        case 1970: sub_8fe1(); break;
        case 1972: sub_8760(); break;
        case 1974: sub_81f6(); break;
        case 1976: sub_84a2(); break;
        case 1978: sub_8fe1(); break;
        case 1980: sub_832d(); break;
        case 1982: sub_8405(); break;
        case 1984: sub_85e7(); break;
        case 1986: sub_841e(); break;
        case 1988: sub_8457(); break;
        case 1990: sub_84b5(); break;
        case 1992: sub_84f7(); break;
        case 1994: sub_8fe1(); break;
        case 1996: sub_84cb(); break;
        case 1998: sub_8fe1(); break;
        case 2000: sub_8fe1(); break;
        case 2002: sub_8fe1(); break;
        case 2004: sub_8fe1(); break;
        case 2006: sub_878b(); break;
        case 2008: sub_8242(); break;
        case 2010: sub_84a2(); break;
        case 2012: sub_8fe1(); break;
        case 2014: sub_832d(); break;
        case 2016: sub_83ec(); break;
        case 2018: sub_85e7(); break;
        case 2020: sub_841e(); break;
        case 2022: sub_8457(); break;
        case 2024: sub_84b5(); break;
        case 2026: sub_84f7(); break;
        case 2028: sub_8fe1(); break;
        case 2030: sub_84cb(); break;
        case 2032: sub_8fe1(); break;
        case 2034: sub_8fe1(); break;
        case 2036: sub_8fe1(); break;
        case 2038: sub_8fe1(); break;
        case 2040: sub_8518(); break;
        case 2042: sub_8fe1(); break;
        case 2044: sub_8fe1(); break;
        case 2046: sub_8fe1(); break;
        case 2048: sub_8fe1(); break;
        case 2050: sub_8fe1(); break;
        case 2052: sub_8fe1(); break;
        case 2054: sub_85e7(); break;
        case 2056: sub_841e(); break;
        case 2058: sub_8457(); break;
        case 2060: sub_8fe1(); break;
        case 2062: sub_8fe1(); break;
        case 2064: sub_8fe1(); break;
        case 2066: sub_84cb(); break;
        case 2068: sub_1ed0(); break;
        case 2070: sub_1ed0(); break;
        case 2072: sub_1ed0(); break;
        case 2074: sub_8518(); break;
        case 2076: sub_8fe1(); break;
        case 2078: sub_8fe1(); break;
        case 2080: sub_8fe1(); break;
        case 2082: sub_8fe1(); break;
        case 2084: sub_8fe1(); break;
        case 2086: sub_8fe1(); break;
        case 2088: sub_85e7(); break;
        case 2090: sub_841e(); break;
        case 2092: sub_8457(); break;
        case 2094: sub_8fe1(); break;
        case 2096: sub_8fe1(); break;
        case 2098: sub_8fe1(); break;
        case 2100: sub_84cb(); break;
        case 2102: sub_1ed0(); break;
        case 2104: sub_1ed0(); break;
        case 2106: sub_1ed0(); break;
        case 2108: sub_8518(); break;
        case 2110: sub_8fe1(); break;
        case 2112: sub_8fe1(); break;
        case 2114: sub_8fe1(); break;
        case 2116: sub_8fe1(); break;
        case 2118: sub_8fe1(); break;
        case 2120: sub_8fe1(); break;
        case 2122: sub_85e7(); break;
        case 2124: sub_841e(); break;
        case 2126: sub_8457(); break;
        case 2128: sub_8fe1(); break;
        case 2130: sub_8fe1(); break;
        case 2132: sub_8fe1(); break;
        case 2134: sub_84cb(); break;
        case 2136: sub_1ed0(); break;
        case 2138: sub_1ed0(); break;
        case 2140: sub_1ed0(); break;
        case 2142: sub_8518(); break;
        case 2144: sub_8fe1(); break;
        case 2146: sub_8fe1(); break;
        case 2148: sub_8fe1(); break;
        case 2150: sub_8fe1(); break;
        case 2152: sub_8fe1(); break;
        case 2154: sub_8fe1(); break;
        case 2156: sub_85e7(); break;
        case 2158: sub_841e(); break;
        case 2160: sub_8457(); break;
        case 2162: sub_8fe1(); break;
        case 2164: sub_8fe1(); break;
        case 2166: sub_8fe1(); break;
        case 2168: sub_84cb(); break;
        default:
            stop("ind 01ed:23b0");
    }
    bp = pop();
    sp += 2;
}
void sub_4286() // 01ed:23b6
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4292;
    sub_ca53();
loc_4292: // 01ed:23c2
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_429e;
    sub_4504();
    goto loc_42f1;
loc_429e: // 01ed:23ce
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_42aa;
    sub_4571();
    goto loc_42f1;
loc_42aa: // 01ed:23da
    if (memoryAGet(ds, 0x856e) < 0x08)
        goto loc_42c9;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 65528) != 0x0e)
        goto loc_42c9;
    goto loc_42ee;
loc_42c9: // 01ed:23f9
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_42ee;
    sub_6617();
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_42e4;
    al = 0x14;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42e4: // 01ed:2414
    al = 0x2a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42ee: // 01ed:241e
    sub_46ae();
loc_42f1: // 01ed:2421
    bp = pop();
    sp += 2;
}
void sub_42f3() // 01ed:2423
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4302;
    sub_ca53();
loc_4302: // 01ed:2432
    memoryASet(ss, bp - 1, 0x21);
    memoryASet(ss, bp - 2, 0x04);
    memoryASet16(ss, bp - 6, 0x14ea);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_4332;
    sub_4504();
    goto loc_433c;
loc_4332: // 01ed:2462
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_433c;
    sub_4571();
loc_433c: // 01ed:246c
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4340() // 01ed:2470
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_434c;
    sub_ca53();
loc_434c: // 01ed:247c
    memoryASet(ds, 0x824c, 0x08);
    al = 0x0b;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_435e() // 01ed:248e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_436d;
    sub_ca53();
loc_436d: // 01ed:249d
    memoryASet(ss, bp - 1, 0x25);
    memoryASet(ss, bp - 2, 0x06);
    memoryASet16(ss, bp - 6, 0x1664);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_43a3;
    al = 0x0c;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_43a3: // 01ed:24d3
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_43a7() // 01ed:24d7
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_43b3;
    sub_ca53();
loc_43b3: // 01ed:24e3
    if (memoryAGet(ds, 0x7924) != 0x00)
        goto loc_43d0;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 8) != 0x0b)
        goto loc_43d5;
loc_43d0: // 01ed:2500
    sub_43da();
    goto loc_43d8;
loc_43d5: // 01ed:2505
    sub_47b0();
loc_43d8: // 01ed:2508
    bp = pop();
    sp += 2;
}
void sub_43da() // 01ed:250a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_43e6;
    sub_ca53();
loc_43e6: // 01ed:2516
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_43f2;
    sub_4504();
    goto loc_440d;
loc_43f2: // 01ed:2522
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_43fe;
    sub_4571();
    goto loc_440d;
loc_43fe: // 01ed:252e
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_440a;
    sub_440f();
    goto loc_440d;
loc_440a: // 01ed:253a
    sub_46ae();
loc_440d: // 01ed:253d
    bp = pop();
    sp += 2;
}
void sub_440f() // 01ed:253f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_441b;
    sub_ca53();
loc_441b: // 01ed:254b
    if (memoryAGet(ds, 0x7924) != 0x0f)
        goto loc_4427;
    sub_66d2();
    goto loc_443a;
loc_4427: // 01ed:2557
    if (memoryAGet(ds, 0x7924) != 0x12)
        goto loc_4430;
    goto loc_4437;
loc_4430: // 01ed:2560
    if (memoryAGet(ds, 0x7924) != 0x1f)
        goto loc_443a;
loc_4437: // 01ed:2567
    sub_4180();
loc_443a: // 01ed:256a
    sub_84cb();
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4448;
    al = 0x14;
    goto loc_444a;
loc_4448: // 01ed:2578
    al = 0x09;
loc_444a: // 01ed:257a
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet(ds, 0x824c, memoryAGet(ds, 0x824c) + 1);
    if (memoryAGet(ds, 0x824c) != 0x09)
        goto loc_4470;
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    al = 0x24;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memoryASet(ds, 0x824c, 0x00);
loc_4470: // 01ed:25a0
    al = 0x0d;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_447d() // 01ed:25ad
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_448b;
    sub_ca53();
loc_448b: // 01ed:25bb
    memoryASet(ss, bp - 2, 0x00);
    al = memoryAGet(ds, 0x856e);
    memoryASet(ss, bp - 1, al);
    goto loc_44f7;
loc_4497: // 01ed:25c7
    al = memoryAGet(ss, bp - 1);
    al++;
    memoryASet(ss, bp - 1, al);
    if (al != 0x30)
        goto loc_44a7;
    memoryASet(ss, bp - 1, 0x00);
loc_44a7: // 01ed:25d7
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0x0f)
        goto loc_44f7;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x856f, al);
    memoryASet(ds, 0x856e, al);
    sub_67d6();
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x000d;
    memoryASet16(ds, 0x9292, ax);
    al = 0x27;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_44e0;
    al = 0x03;
    goto loc_44e2;
loc_44e0: // 01ed:2610
    al = 0x28;
loc_44e2: // 01ed:2612
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x0f;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    memoryASet(ss, bp - 2, 0x01);
loc_44f7: // 01ed:2627
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    if (!ax)
        goto loc_4497;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4504() // 01ed:2634
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4512;
    sub_ca53();
loc_4512: // 01ed:2642
    memoryASet(ds, 0x8551, 0x00);
    sub_828e();
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_452c;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x12;
    goto loc_4564;
loc_452c: // 01ed:265c
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 16982);
    memoryASet(ss, bp - 1, al);
    if (al == 0x01)
        goto loc_454e;
    goto loc_4564;
loc_454e: // 01ed:267e
    al = memoryAGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_4562;
    al = 0x16;
    goto loc_4564;
loc_4562: // 01ed:2692
    al = 0x01;
loc_4564: // 01ed:2694
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4571() // 01ed:26a1
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_457f;
    sub_ca53();
loc_457f: // 01ed:26af
    memoryASet(ds, 0x8551, 0x00);
    sub_828e();
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_4597;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x13;
    goto loc_45cf;
loc_4597: // 01ed:26c7
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17014);
    memoryASet(ss, bp - 1, al);
    if (al == 0x02)
        goto loc_45b7;
    goto loc_45cf;
loc_45b7: // 01ed:26e7
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_45cd;
    al = 0x17;
    goto loc_45cf;
loc_45cd: // 01ed:26fd
    al = 0x02;
loc_45cf: // 01ed:26ff
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_45dc() // 01ed:270c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_45ea;
    sub_ca53();
loc_45ea: // 01ed:271a
    memoryASet(ds, 0x8551, 0x00);
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_4601;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x14;
    goto loc_4639;
loc_4601: // 01ed:2731
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17046);
    memoryASet(ss, bp - 1, al);
    if (al == 0x08)
        goto loc_4623;
    goto loc_4639;
loc_4623: // 01ed:2753
    al = memoryAGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_4637;
    al = 0x18;
    goto loc_4639;
loc_4637: // 01ed:2767
    al = 0x08;
loc_4639: // 01ed:2769
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4646() // 01ed:2776
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4654;
    sub_ca53();
loc_4654: // 01ed:2784
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_4669;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x15;
    goto loc_46a1;
loc_4669: // 01ed:2799
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17078);
    memoryASet(ss, bp - 1, al);
    if (al == 0x09)
        goto loc_4689;
    goto loc_46a1;
loc_4689: // 01ed:27b9
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_469f;
    al = 0x19;
    goto loc_46a1;
loc_469f: // 01ed:27cf
    al = 0x09;
loc_46a1: // 01ed:27d1
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_46ae() // 01ed:27de
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_46ba;
    sub_ca53();
loc_46ba: // 01ed:27ea
    al = 0x00;
    memoryASet(ds, 0x7923, al);
    memoryASet(ds, 0xa1a7, al);
    memoryASet(ds, 0x79b9, 0x0b);
    if (memoryAGet(ds, 0x7924) != 0x11)
        goto loc_46d8;
    al = 0x2f;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_46db;
loc_46d8: // 01ed:2808
    sub_46e0();
loc_46db: // 01ed:280b
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_46e0() // 01ed:2810
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_46ef;
    sub_ca53();
loc_46ef: // 01ed:281f
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_4732;
    if (memoryAGet(ds, 0x8552) == 0x0d)
        goto loc_4732;
    if (memoryAGet(ds, 0x8552) == 0x10)
        goto loc_4732;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4718;
    al = memoryAGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9886);
    goto loc_4723;
loc_4718: // 01ed:2848
    al = memoryAGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9838);
loc_4723: // 01ed:2853
    memoryASet(ss, bp - 4, al);
    if (memoryAGet(ss, bp - 4) == 0x00)
        goto loc_4732;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4732: // 01ed:2862
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_4741;
    al = 0x06;
    push(ax);
    sub_6133();
    goto loc_47aa;
loc_4741: // 01ed:2871
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    memoryASet(ds, 0x79b9, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 1898);
    memoryASet(ss, bp - 2, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 1899);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x792c) != 0x0a)
        goto loc_479d;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4795;
    al = 0x14;
    goto loc_4797;
loc_4795: // 01ed:28c5
    al = 0x09;
loc_4797: // 01ed:28c7
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_479d: // 01ed:28cd
    if (memoryAGet(ss, bp - 3) == 0x00)
        goto loc_47ac;
    al = memoryAGet(ss, bp - 3);
    push(ax);
    sub_887a();
loc_47aa: // 01ed:28da
    sp++;
    sp++;
loc_47ac: // 01ed:28dc
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_47b0() // 01ed:28e0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_47bc;
    sub_ca53();
loc_47bc: // 01ed:28ec
    al = 0x04;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_47c9() // 01ed:28f9
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_47d5;
    sub_ca53();
loc_47d5: // 01ed:2905
    memoryASet(ds, 0x824c, 0x08);
    if (memoryAGet(ds, 0x79b4) != 0x00)
        goto loc_47e8;
    if (memoryAGet(ds, 0x7924) != 0x00)
        goto loc_47fe;
loc_47e8: // 01ed:2918
    memoryASet(ds, 0x79b4, 0x00);
    if (memoryAGet(ds, 0x856e) >= 0x28)
        goto loc_47f9;
    sub_47b0();
    goto loc_4833;
loc_47f9: // 01ed:2929
    sub_61a9();
    goto loc_4833;
loc_47fe: // 01ed:292e
    if (memoryAGet(ds, 0x7924) != 0x20)
        goto loc_4818;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4810;
    al = 0x03;
    goto loc_4812;
loc_4810: // 01ed:2940
    al = 0x28;
loc_4812: // 01ed:2942
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4818: // 01ed:2948
    if (memoryAGet(ds, 0x7924) != 0x16)
        goto loc_4824;
    sub_61d5();
    goto loc_4833;
loc_4824: // 01ed:2954
    if (memoryAGet(ds, 0x7924) != 0x03)
        goto loc_4830;
    sub_650d();
    goto loc_4833;
loc_4830: // 01ed:2960
    sub_4835();
loc_4833: // 01ed:2963
    bp = pop();
    sp += 2;
}
void sub_4835() // 01ed:2965
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4841;
    sub_ca53();
loc_4841: // 01ed:2971
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_484d;
    sub_654d();
    goto loc_4874;
loc_484d: // 01ed:297d
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_4859;
    sub_656c();
    goto loc_4874;
loc_4859: // 01ed:2989
    if (memoryAGet(ds, 0x7924) != 0x0a)
        goto loc_4865;
    sub_669b();
    goto loc_4874;
loc_4865: // 01ed:2995
    if (memoryAGet(ds, 0x7924) != 0x0f)
        goto loc_4871;
    sub_66d2();
    goto loc_4874;
loc_4871: // 01ed:29a1
    sub_4876();
loc_4874: // 01ed:29a4
    bp = pop();
    sp += 2;
}
void sub_4876() // 01ed:29a6
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4882;
    sub_ca53();
loc_4882: // 01ed:29b2
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_488e;
    sub_652e();
    goto loc_48d8;
loc_488e: // 01ed:29be
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx) == 0x0e)
        goto loc_48a9;
    sub_652e();
    goto loc_48d8;
loc_48a9: // 01ed:29d9
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_48b5;
    sub_440f();
    goto loc_48d8;
loc_48b5: // 01ed:29e5
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_48c0;
    al = 0x14;
    goto loc_48c2;
loc_48c0: // 01ed:29f0
    al = 0x09;
loc_48c2: // 01ed:29f2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x24;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    al = 0x0a;
    push(ax);
    sub_6133();
    sp++;
    sp++;
loc_48d8: // 01ed:2a08
    bp = pop();
    sp += 2;
}
void sub_48da() // 01ed:2a0a
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_48ea;
    sub_ca53();
loc_48ea: // 01ed:2a1a
    di = 0;
    goto loc_493d;
loc_48ee: // 01ed:2a1e
    si = 0;
    goto loc_4932;
loc_48f2: // 01ed:2a22
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    sub_2a58();
    sp += 0x0006;
    ax = si;
    dx = 0x0027;
    imul16(dx);
    bx = memoryAGet16(ds, 0x6bca); es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = di;
    ax = sar16(ax, 0x0001);
    dx = 0x0003;
    imul16(dx);
    bx += ax;
    al = memoryAGet(es, bx + 32);
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_4931;
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_2960();
    sp += 0x0008;
loc_4931: // 01ed:2a61
    si++;
loc_4932: // 01ed:2a62
    if ((short)si < (short)0x0014)
        goto loc_48f2;
    ax = di;
    ax++;
    ax++;
    di = ax;
loc_493d: // 01ed:2a6d
    if ((short)di < (short)0x001a)
        goto loc_48ee;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4948() // 01ed:2a78
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4959;
    sub_ca53();
loc_4959: // 01ed:2a89
    memoryASet(ds, 0x4c40, 0x00);
    memoryASet(ds, 0x4c4c, 0x00);
    memoryASet(ds, 0x4c58, 0x00);
    memoryASet(ds, 0x4c80, 0x00);
    memoryASet(ds, 0x4c8c, 0x00);
    memoryASet(ds, 0x4c98, 0x00);
    memoryASet(ds, 0x4ca4, 0x00);
    ax = memoryAGet16(ds, 0x4c72);
    dx = memoryAGet16(ds, 0x4c70);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ds, 0x4cbe);
    dx = memoryAGet16(ds, 0x4cbc);
    memoryASet16(ss, bp - 20, dx);
    memoryASet16(ss, bp - 18, ax);
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x01;
    memoryASet(es, bx, al);
    memoryASet(ds, 0x8e8b, al);
    bx = memoryAGet16(ss, bp - 20); es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x01;
    memoryASet(es, bx, al);
    memoryASet(ds, 0x8e8c, al);
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x01;
    memoryASet(es, bx + 6, al);
    memoryASet(ds, 0x8578, al);
    bx = memoryAGet16(ss, bp - 20); es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x01;
    memoryASet(es, bx + 6, al);
    memoryASet(ds, 0x8579, al);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 144);
    memoryASet(ds, 0x856e, al);
    if (memoryAGet(ds, 0x856e) == 0x00)
        goto loc_49db;
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) - 1);
loc_49db: // 01ed:2b0b
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 145);
    memoryASet(ds, 0x8572, al);
    if (memoryAGet(ds, 0x8572) == 0x00)
        goto loc_49f2;
    memoryASet(ds, 0x8572, memoryAGet(ds, 0x8572) - 1);
loc_49f2: // 01ed:2b22
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 146);
    memoryASet(ds, 0xa0cf, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 147);
    al += 0xff;
    memoryASet(ds, 0x8571, al);
    al = memoryAGet(es, bx + 149);
    memoryASet(ds, 0x7920, al);
    al = memoryAGet(es, bx + 148);
    memoryASet(ds, 0x8562, al);
    al = memoryAGet(es, bx + 150);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 9542);
    memoryASet16(ds, 0xa0de, ax);
    sub_670c();
    memoryASet(ss, bp - 2, 0x00);
    goto loc_4bbd;
loc_4a38: // 01ed:2b68
    memoryASet(ss, bp - 1, 0x00);
    goto loc_4bb1;
loc_4a3f: // 01ed:2b6f
    al = memoryAGet(ss, bp - 2);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al += memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 1);
    dh = 0x00;
    ax += dx;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4abb;
    al = memoryAGet(ds, si + 15674);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 15724);
    dx = memoryAGet16(ds, bx + 15722);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    al = memoryAGet(ss, bp - 3);
    memoryASet(es, bx + 1, al);
    push(es);
    di = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, di);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    memoryASet16(es, bx + 10, ax);
    sub_352e();
    sub_3937();
loc_4abb: // 01ed:2beb
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 48);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4b2b;
    if (memoryAGet(ss, bp - 1) == 0x07)
        goto loc_4b2b;
    al = memoryAGet(ds, si + 16518);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 16552);
    dx = memoryAGet16(ds, bx + 16550);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 20); es = memoryAGet16(ss, bp - 20 + 2);
    al = memoryAGet(ss, bp - 3);
    memoryASet(es, bx + 1, al);
    push(es);
    di = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, di);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 20); es = memoryAGet16(ss, bp - 20 + 2);
    memoryASet16(es, bx + 10, ax);
    sub_3697();
    sub_39fb();
loc_4b2b: // 01ed:2c5b
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 96);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4bae;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx, ax);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    bx = memoryAGet16(ds, 0x8884);
    memoryASet16(es, bx + 2, ax);
    ax = si;
    ax += 0x0179;
    memoryASet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_4bae: // 01ed:2cde
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_4bb1: // 01ed:2ce1
    if (memoryAGet(ss, bp - 1) >= 0x08)
        goto loc_4bba;
    goto loc_4a3f;
loc_4bba: // 01ed:2cea
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_4bbd: // 01ed:2ced
    if (memoryAGet(ss, bp - 2) >= 0x06)
        goto loc_4bc6;
    goto loc_4a38;
loc_4bc6: // 01ed:2cf6
    bx = memoryAGet16(ss, bp - 16); es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x00;
    memoryASet(es, bx + 6, al);
    memoryASet(es, bx, al);
    bx = memoryAGet16(ss, bp - 20); es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x00;
    memoryASet(es, bx + 6, al);
    memoryASet(es, bx, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4be4() // 01ed:2d14
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4bf4;
    sub_ca53();
loc_4bf4: // 01ed:2d24
    memoryASet(ss, bp - 5, 0x01);
    if (memoryAGet(ds, 0x79b2) <= 0x01)
        goto loc_4c0b;
    al = memoryAGet(ds, 0x119a);
    ah = 0x00;
    if (ax)
        goto loc_4c0b;
    sub_5ee5();
loc_4c0b: // 01ed:2d3b
    if (memoryAGet(ds, 0x119a) != 0xff)
        goto loc_4c17;
    memoryASet(ds, 0x79b2, 0x01);
loc_4c17: // 01ed:2d47
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4298);
    dx = memoryAGet16(ds, bx + 4296);
    memoryASet16(ds, 0x8246, dx);
    memoryASet16(ds, 0x8248, ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4334);
    dx = memoryAGet16(ds, bx + 4332);
    memoryASet16(ds, 0x8554, dx);
    memoryASet16(ds, 0x8556, ax);
    memoryASet(ds, 0x854e, 0x01);
    ax = 0x001f;
    memoryASet16(ds, 0x791e, ax);
    memoryASet16(ds, 0x791c, ax);
    if (memoryAGet(ds, 0x79b2) == 0x02)
        goto loc_4c67;
    if (memoryAGet(ds, 0x79b2) != 0x05)
        goto loc_4c86;
loc_4c67: // 01ed:2d97
    memoryASet16(ds, 0x791c, 0x006f);
    goto loc_4c86;
loc_4c6f: // 01ed:2d9f
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    memoryASet(es, bx, 0x00);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_4c86: // 01ed:2db6
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_4c6f;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0090); es = memoryAGet16(ds, 0x0090 + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    bx = memoryAGet16(ds, 0x009a); es = memoryAGet16(ds, 0x009a + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    bx = memoryAGet16(ds, 0x00e0); es = memoryAGet16(ds, 0x00e0 + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    ax = 0x0004;
    push(ax);
    ax = 0;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0098));
    push(memoryAGet16(ds, 0x0096));
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x0098));
    push(memoryAGet16(ds, 0x0096));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    sub_9a2a();
    sp += 0x000c;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00a2));
    push(memoryAGet16(ds, 0x00a0));
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x00a2));
    push(memoryAGet16(ds, 0x00a0));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    sub_9a2a();
    sp += 0x000c;
    ax = 0x0004;
    push(ax);
    ax = 0x0008;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00e8));
    push(memoryAGet16(ds, 0x00e6));
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x00e8));
    push(memoryAGet16(ds, 0x00e6));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    sub_9a2a();
    sp += 0x000c;
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4dc8() // 01ed:2ef8
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4dd8;
    sub_ca53();
loc_4dd8: // 01ed:2f08
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    sub_4e7c();
    ax = 0x0004;
    push(ax);
    ax = 0;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0930));
    push(memoryAGet16(ds, 0x092e));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_b2a8();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x093a));
    push(memoryAGet16(ds, 0x0938));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    sub_70a8();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4e7c() // 01ed:2fac
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4e8d;
    sub_ca53();
loc_4e8d: // 01ed:2fbd
    ax = 0x0004;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0944));
    push(memoryAGet16(ds, 0x0942));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_4f1c;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_4f16;
loc_4ef9: // 01ed:3029
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1594);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_4f16: // 01ed:3046
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_4ef9;
loc_4f1c: // 01ed:304c
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    sub_4fad();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4fad() // 01ed:30dd
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4fbc;
    sub_ca53();
loc_4fbc: // 01ed:30ec
    memoryASet(ss, bp - 1, 0x00);
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0958));
    push(memoryAGet16(ds, 0x0956));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0x0004;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0962));
    push(memoryAGet16(ds, 0x0960));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_508d;
    goto loc_506c;
loc_5027: // 01ed:3157
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_a847();
    sp += 0x000a;
    goto loc_505c;
loc_5043: // 01ed:3173
    ax = memoryAGet16(ds, 0x119c);
    ax += 0x0007;
    memoryASet16(ds, 0x119c, ax);
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (!(al & 0x10))
        goto loc_505c;
    memoryASet(ss, bp - 1, 0x01);
loc_505c: // 01ed:318c
    sub_a869();
    if (!ax)
        goto loc_506c;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5043;
loc_506c: // 01ed:319c
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5027;
    sub_a878();
    if (memoryAGet16(ds, 0x689c) != 0x0000)
        goto loc_50a9;
    ax = 0x0001;
    push(ax);
    sub_9ce8();
    sp++;
    sp++;
    sub_b33e();
    goto loc_50a9;
loc_508d: // 01ed:31bd
    memoryASet(ds, 0x8244, 0x00);
    goto loc_50a0;
loc_5094: // 01ed:31c4
    sync();
    sub_3cae();
    ax = memoryAGet16(ds, 0x119c);
    ax += 0x0007;
    memoryASet16(ds, 0x119c, ax);
loc_50a0: // 01ed:31d0
    al = memoryAGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5094;
loc_50a9: // 01ed:31d9
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_50ae() // 01ed:31de
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_50ba;
    sub_ca53();
loc_50ba: // 01ed:31ea
    memoryASet(ds, 0x8242, 0x00);
    memoryASet(ds, 0x792a, 0x00);
    memoryASet16(ds, 0x824a, 0x0000);
    memoryASet(ds, 0xa0ce, 0x00);
    al = 0x00;
    memoryASet(ds, 0x8578, al);
    memoryASet(ds, 0x8e8b, al);
    al = 0x00;
    memoryASet(ds, 0x8579, al);
    memoryASet(ds, 0x8e8c, al);
    memoryASet(ds, 0x8244, 0x00);
    memoryASet(ds, 0xa1a7, 0x00);
    memoryASet(ds, 0x79b4, 0x00);
    memoryASet(ds, 0x7923, 0x00);
    memoryASet(ds, 0x824c, 0x00);
    memoryASet(ds, 0xa1a8, 0x00);
    memoryASet(ds, 0xa1b1, 0x00);
    memoryASet(ds, 0x8550, 0x00);
    memoryASet(ds, 0x8563, 0x00);
    memoryASet(ds, 0xa1b0, 0x00);
    memoryASet(ds, 0x8243, 0x00);
    memoryASet(ds, 0x79b7, 0x00);
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    sub_67d6();
    sub_6779();
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfff4;
    memoryASet16(ds, 0x9292, ax);
    memoryASet(ds, 0x792c, 0x00);
    memoryASet16(ds, 0xa1ac, 0x1394);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x0a);
    al = 0x04;
    memoryASet(ds, 0x9bae, al);
    memoryASet(ds, 0x792a, al);
    memoryASet(ds, 0xa1a9, 0x00);
    bp = pop();
    sp += 2;
}
void sub_515f() // 01ed:328f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_516b;
    sub_ca53();
loc_516b: // 01ed:329b
    memoryASet(ds, 0x8244, 0x00);
    goto loc_5175;
loc_5172: // 01ed:32a2
    sync();
    sub_3cae();
loc_5175: // 01ed:32a5
    al = memoryAGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5172;
    bp = pop();
    sp += 2;
}
void sub_5180() // 01ed:32b0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_518c;
    sub_ca53();
loc_518c: // 01ed:32bc
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x00c2;
    imul16(dx);
    dx = memoryAGet16(ds, 0x6bf4);
    bx = memoryAGet16(ds, 0x6bf2);
    bx += ax;
    memoryASet16(ds, 0x75d0, bx);
    memoryASet16(ds, 0x75d2, dx);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x032c;
    imul16(dx);
    dx = memoryAGet16(ds, 0x6bd4);
    bx = memoryAGet16(ds, 0x6bd2);
    bx += ax;
    memoryASet16(ds, 0x6bca, bx);
    memoryASet16(ds, 0x6bcc, dx);
    memoryASet16(ds, 0xa0d8, 0xa0e4);
    memoryASet16(ds, 0xa0da, ds);
    cl = 0x00;
    goto loc_5222;
loc_51ce: // 01ed:32fe
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx, al);
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx + 48, al);
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 96);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx + 96, al);
    cl++;
loc_5222: // 01ed:3352
    if (cl < 0x30)
        goto loc_51ce;
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 144);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 144, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 145);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 145, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 146);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 146, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 147);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 147, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 148);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 148, al);
    bx = memoryAGet16(ds, 0x75d0); es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 149);
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 149, al);
    bp = pop();
    sp += 2;
}
void sub_5295() // 01ed:33c5
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_52a1;
    sub_ca53();
loc_52a1: // 01ed:33d1
    memoryASet16(ds, 0x8884, 0x792e);
    memoryASet16(ds, 0x8886, ds);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0xa0c8);
    dx = memoryAGet16(ds, 0xa0c6);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    memoryASet16(ds, 0x9b9e, 0x795a);
    memoryASet16(ds, 0x9ba0, ds);
    bx = memoryAGet16(ds, 0x9b9e); es = memoryAGet16(ds, 0x9b9e + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    memoryASet16(ds, 0xa0d0, 0x7986);
    memoryASet16(ds, 0xa0d2, ds);
    bx = memoryAGet16(ds, 0xa0d0); es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    bp = pop();
    sp += 2;
}
void sub_5337() // 01ed:3467
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0068;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5347;
    sub_ca53();
loc_5347: // 01ed:3477
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet(ss, bp - 2, 0x14);
    memoryASet(ss, bp - 3, 0x19);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5436;
loc_537a: // 01ed:34aa
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 22, ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    memoryASet16(es, bx + 30, ax);
    memoryASet16(es, bx + 32, 0x0001);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0018;
    dx -= ax;
    memoryASet16(es, bx + 22, dx);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryAGet(ss, bp - 2);
    al += 0xfe;
    memoryASet(ss, bp - 2, al);
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 30, 0x0001);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0013;
    dx -= ax;
    memoryASet16(es, bx + 20, dx);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryAGet(ss, bp - 3);
    al += 0xfe;
    memoryASet(ss, bp - 3, al);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5436: // 01ed:3566
    if (memoryAGet(ss, bp - 1) > 0x09)
        goto loc_543f;
    goto loc_537a;
loc_543f: // 01ed:356f
    si = 0;
    goto loc_5452;
loc_5443: // 01ed:3573
    bx = si;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    memoryASet16(ss, bx, 0x0000);
    si++;
loc_5452: // 01ed:3582
    if (si < 0x0032)
        goto loc_5443;
    ax = 0;
    push(ax);
    push(ss);
    ax = bp - 104;
    push(ax);
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5475() // 01ed:35a5
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5486;
    sub_ca53();
loc_5486: // 01ed:35b6
    memoryASet(ss, bp - 5, 0x00);
    memoryASet(ss, bp - 6, 0xff);
    push(ss);
    ax = bp - 10;
    push(ax);
    push(ds);
    ax = 0x11b2;
    push(ax);
    cx = 0x0003;
    sub_c8c5();
    ax = 0x0004;
    push(ax);
    ax = 0x0012;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x09e4));
    push(memoryAGet16(ds, 0x09e2));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_552d;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_5527;
loc_550a: // 01ed:363a
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1610);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
loc_5527: // 01ed:3657
    if (memoryAGet(ss, bp - 11) < 0x10)
        goto loc_550a;
loc_552d: // 01ed:365d
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0x6c2e);
    dx = memoryAGet16(ds, 0x6c2c);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    al = 0x00;
    memoryASet(ds, 0x854f, al);
    memoryASet(ds, 0x8244, al);
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    goto loc_56d9;
loc_55cf: // 01ed:36ff
    al = memoryAGet(ds, 0x79b5);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1888);
    dx = memoryAGet16(ds, bx + 1886);
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0006);
    memoryASet16(es, bx + 12, 0x0002);
    memoryASet16(es, bx + 20, 0x000b);
    memoryASet16(es, bx + 22, 0x0012);
    memoryASet16(es, bx + 30, 0x0006);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0;
    push(ax);
    sub_7051();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, 0x0000);
    memoryASet16(es, bx, 0x0030);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0070;
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sub_b734();
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_5684;
    if (memoryAGet(ss, bp - 5) == 0x00)
        goto loc_5684;
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) - 1);
    goto loc_56c8;
loc_5684: // 01ed:37b4
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_5696;
    if (memoryAGet(ss, bp - 5) >= 0x03)
        goto loc_5696;
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
    goto loc_56c8;
loc_5696: // 01ed:37c6
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_56c8;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = ax;
    if (bx > 0x0003)
        goto loc_56c8;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_56b0;
        case 2: goto loc_56b0;
        case 4: goto loc_56b8;
        case 6: goto loc_56b0;
        default:
            stop("ind 01ed:37db");
    }
loc_56b0: // 01ed:37e0
    al = memoryAGet(ss, bp - 5);
    memoryASet(ss, bp - 6, al);
    goto loc_56c8;
loc_56b8: // 01ed:37e8
    memoryASet(ds, 0x79b5, memoryAGet(ds, 0x79b5) + 1);
    if (memoryAGet(ds, 0x79b5) != 0x03)
        goto loc_56c8;
    memoryASet(ds, 0x79b5, 0x00);
loc_56c8: // 01ed:37f8
    memoryASet(ds, 0x8244, 0x00);
loc_56cd: // 01ed:37fd
    sync();
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (al)
        goto loc_56cd;
loc_56d9: // 01ed:3809
    if (memoryAGet(ss, bp - 6) != 0xff)
        goto loc_56e2;
    goto loc_55cf;
loc_56e2: // 01ed:3812
    al = memoryAGet(ds, 0x79b5);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    al = memoryAGet(ss, bx);
    memoryASet(ds, 0x854f, al);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0xa0c8);
    dx = memoryAGet16(ds, 0xa0c6);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    al = memoryAGet(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5722() // 01ed:3852
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5732;
    sub_ca53();
loc_5732: // 01ed:3862
    memoryASet(ss, bp - 5, 0x00);
    al = memoryAGet(ds, 0x854f);
    memoryASet(ds, 0x8e8a, al);
    memoryASet(ds, 0x854f, 0x00);
    memoryASet(ds, 0x8244, 0x00);
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax += 0x0007;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    push(memoryAGet16(ds, bx + 2422));
    push(memoryAGet16(ds, bx + 2420));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_580c;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1768);
    dx = memoryAGet16(ds, bx + 1766);
    memoryASet16(ss, bp - 10, dx);
    memoryASet16(ss, bp - 8, ax);
    memoryASet(ss, bp - 6, 0x00);
    goto loc_5806;
loc_57e7: // 01ed:3917
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 10); es = memoryAGet16(ss, bp - 10 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ss, bp - 6);
    dh = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += dx;
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_5806: // 01ed:3936
    if (memoryAGet(ss, bp - 6) < 0x10)
        goto loc_57e7;
loc_580c: // 01ed:393c
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0x0008;
    push(ax);
    ax = 0x0001;
    push(ax);
    al = 0x07;
    push(ax);
    push(memoryAGet16(ds, 0xa0d6));
    push(memoryAGet16(ds, 0xa0d4));
    sub_26e6();
    sp += 0x000a;
    sub_8000();
    sub_5b1f();
    al = memoryAGet(ds, 0x79b6);
    memoryASet(ds, 0x854e, al);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = memoryAGet16(ds, 0x791c);
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x791e);
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x0021);
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_7051();
    sp += 0x0004;
    sub_3b82();
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    sub_3343();
    sub_325c();
    sub_3aa7();
    sub_325c();
    sub_5958();
    goto loc_5944;
loc_58ec: // 01ed:3a1c
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_58fb;
    sub_5982();
    goto loc_593f;
loc_58fb: // 01ed:3a2b
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_5907;
    sub_59df();
    goto loc_593f;
loc_5907: // 01ed:3a37
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_5913;
    sub_5a3c();
    goto loc_593f;
loc_5913: // 01ed:3a43
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_591f;
    sub_5a99();
    goto loc_593f;
loc_591f: // 01ed:3a4f
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_592b;
    sub_5bc7();
    goto loc_593c;
loc_592b: // 01ed:3a5b
    sync();
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_593f;
    al = 0xff;
    memoryASet(ds, 0x928d, al);
loc_593c: // 01ed:3a6c
    memoryASet(ss, bp - 5, al);
loc_593f: // 01ed:3a6f
    memoryASet(ds, 0x8244, 0x00);
loc_5944: // 01ed:3a74
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_58ec;
    al = memoryAGet(ds, 0x8e8a);
    memoryASet(ds, 0x854f, al);
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5958() // 01ed:3a88
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5964;
    sub_ca53();
loc_5964: // 01ed:3a94
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    dx = memoryAGet16(ds, 0x8248);
    bx = memoryAGet16(ds, 0x8246);
    bx += ax;
    memoryASet16(ds, 0x9baa, bx);
    memoryASet16(ds, 0x9bac, dx);
    bp = pop();
    sp += 2;
}
void sub_5982() // 01ed:3ab2
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5991;
    sub_ca53();
loc_5991: // 01ed:3ac1
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_59db;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 2);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ss, bp - 1, al);
    goto loc_59d5;
loc_59c6: // 01ed:3af6
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffc;
    memoryASet16(ds, 0x9292, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_59d5: // 01ed:3b05
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_59c6;
loc_59db: // 01ed:3b0b
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_59df() // 01ed:3b0f
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_59ee;
    sub_ca53();
loc_59ee: // 01ed:3b1e
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 3);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5a38;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ss, bp - 1, al);
    goto loc_5a32;
loc_5a23: // 01ed:3b53
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0004;
    memoryASet16(ds, 0x9292, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5a32: // 01ed:3b62
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5a23;
loc_5a38: // 01ed:3b68
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5a3c() // 01ed:3b6c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5a4b;
    sub_ca53();
loc_5a4b: // 01ed:3b7b
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 5);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5a95;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 6);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ss, bp - 1, al);
    goto loc_5a8f;
loc_5a80: // 01ed:3bb0
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfffc;
    memoryASet16(ds, 0x9290, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5a8f: // 01ed:3bbf
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5a80;
loc_5a95: // 01ed:3bc5
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5a99() // 01ed:3bc9
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5aa8;
    sub_ca53();
loc_5aa8: // 01ed:3bd8
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 7);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5af2;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6); es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 8);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ss, bp - 1, al);
    goto loc_5aec;
loc_5add: // 01ed:3c0d
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x0004;
    memoryASet16(ds, 0x9290, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5aec: // 01ed:3c1c
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5add;
loc_5af2: // 01ed:3c22
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5af6() // 01ed:3c26
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b02;
    sub_ca53();
loc_5b02: // 01ed:3c32
    sub_325c();
    sub_3343();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    bp = pop();
    sp += 2;
}
void sub_5b1f() // 01ed:3c4f
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b2d;
    sub_ca53();
loc_5b2d: // 01ed:3c5d
    memoryASet(ss, bp - 1, 0x00);
    al = memoryAGet(ds, 0x854e);
    memoryASet(ds, 0x79b6, al);
    memoryASet(ds, 0x854e, 0x01);
loc_5b3c: // 01ed:3c6c
    sub_5958();
    bx = memoryAGet16(ds, 0x9baa); es = memoryAGet16(ds, 0x9baa + 2);
    if (memoryAGet(es, bx) != 0xff)
        goto loc_5b4f;
    memoryASet(ss, bp - 1, 0x01);
    goto loc_5b5c;
loc_5b4f: // 01ed:3c7f
    bx = memoryAGet16(ds, 0x9baa); es = memoryAGet16(ds, 0x9baa + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_5b5c;
    sub_5b6d();
loc_5b5c: // 01ed:3c8c
    memoryASet(ds, 0x854e, memoryAGet(ds, 0x854e) + 1);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5b3c;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5b6d() // 01ed:3c9d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b79;
    sub_ca53();
loc_5b79: // 01ed:3ca9
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, 0x01da);
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x8554); es = memoryAGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax--;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx, ax);
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax++;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x8554); es = memoryAGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_5bc7() // 01ed:3cf7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5bd6;
    sub_ca53();
loc_5bd6: // 01ed:3d06
    memoryASet(ss, bp - 5, 0x00);
    memoryASet(ds, 0x792c, 0x00);
    sub_5af6();
    sub_5af6();
    sub_5958();
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    ah = 0x00;
    if (!ax)
        goto loc_5c04;
    goto loc_5cc6;
loc_5c04: // 01ed:3d34
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_5c0f;
    al = 0x03;
    goto loc_5c11;
loc_5c0f: // 01ed:3d3f
    al = 0x28;
loc_5c11: // 01ed:3d41
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet(ds, 0x854f, 0xaa);
    ax = memoryAGet16(ds, 0x9292);
    memoryASet16(ds, 0x791e, ax);
    ax = memoryAGet16(ds, 0x9290);
    memoryASet16(ds, 0x791c, ax);
    memoryASet16(ds, 0xa1ac, 0x1114);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x16);
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfff1;
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0003;
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x00cb);
    sub_38b4();
    sub_3b82();
    sub_3aa7();
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x000f;
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffd;
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x0000);
    sub_325c();
    sub_5ccd();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
loc_5c9a: // 01ed:3dca
    sub_325c();
    sub_32af();
    sub_3343();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    if (memoryAGet(ds, 0x824d) != 0x00)
        goto loc_5c9a;
    sub_5d44();
    memoryASet(ss, bp - 5, 0x01);
loc_5cc6: // 01ed:3df6
    al = memoryAGet(ss, bp - 5);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5ccd() // 01ed:3dfd
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5cdb;
    sub_ca53();
loc_5cdb: // 01ed:3e0b
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x9290);
    ax -= di;
    ax += 0x000e;
    cl = 0x04;
    ax = sar16(ax, cl);
    ax--;
    memoryASet16(ds, 0x9d36, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax -= si;
    ax += 0xfff6;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x9d38, ax);
    if ((short)memoryAGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_5d17;
    memoryASet16(ds, 0x9d36, 0x0000);
    goto loc_5d24;
loc_5d17: // 01ed:3e47
    if ((short)memoryAGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_5d24;
    memoryASet16(ds, 0x9d36, 0x0012);
loc_5d24: // 01ed:3e54
    if ((short)memoryAGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_5d33;
    memoryASet16(ds, 0x9d38, 0x0000);
    goto loc_5d40;
loc_5d33: // 01ed:3e63
    if ((short)memoryAGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_5d40;
    memoryASet16(ds, 0x9d38, 0x0016);
loc_5d40: // 01ed:3e70
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_5d44() // 01ed:3e74
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5d50;
    sub_ca53();
loc_5d50: // 01ed:3e80
    al = 0x32;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_5d5a() // 01ed:3e8a
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5d68;
    sub_ca53();
loc_5d68: // 01ed:3e98
    al = 0x01;
    cl = al;
    memoryASet(ss, bp - 1, al);
    goto loc_5d88;
loc_5d71: // 01ed:3ea1
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) & al);
    cl++;
loc_5d88: // 01ed:3eb8
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_5d71;
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5da4() // 01ed:3ed4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5db5;
    sub_ca53();
loc_5db5: // 01ed:3ee5
    sub_7551();
    ax = 0x0004;
    push(ax);
    ax = 0x0011;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x09da));
    push(memoryAGet16(ds, 0x09d8));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_5e47;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_5e41;
loc_5e24: // 01ed:3f54
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1838);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_5e41: // 01ed:3f71
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_5e24;
loc_5e47: // 01ed:3f77
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ds, 0x8244, 0x00);
    sub_515f();
    al = 0x01;
    memoryASet(ds, 0x79b2, al);
    memoryASet(ds, 0x928d, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5ee5() // 01ed:4015
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0036;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5ef6;
    sub_ca53();
loc_5ef6: // 01ed:4026
    memoryASet(ss, bp - 5, 0x00);
    push(ss);
    ax = bp - 38;
    push(ax);
    push(ds);
    ax = 0x11b6;
    push(ax);
    cx = 0x0020;
    sub_c8c5();
    push(ss);
    ax = bp - 54;
    push(ax);
    push(ds);
    ax = 0x11d6;
    push(ax);
    cx = 0x0010;
    sub_c8c5();
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x119c));
    sub_b274();
    sp++;
    sp++;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    di = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    push(di);
    sub_932e();
    sp += 0x000c;
    push(di);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_5fad;
    ax = memoryAGet16(ds, 0x6bea);
    dx = memoryAGet16(ds, 0x6be8);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5fa7;
loc_5f86: // 01ed:40b6
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    push(es);
    push(bx);
    bx = ax;
    al = memoryAGet(ds, bx + 1626);
    bx = pop();
    es = pop();
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5fa7: // 01ed:40d7
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_5f86;
loc_5fad: // 01ed:40dd
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5fd3;
loc_5fb3: // 01ed:40e3
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1854);
    dl = memoryAGet(ss, bp - 1);
    dh = 0x00;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6bca); es = memoryAGet16(ds, 0x6bca + 2);
    bx += dx;
    memoryASet16(es, bx, ax);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5fd3: // 01ed:4103
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_5fb3;
    sub_250b();
    memoryASet(ss, bp - 5, 0x00);
    goto loc_6112;
loc_5fe3: // 01ed:4113
    sub_b281();
    ax &= 0x000f;
    si = ax;
    if ((short)ax < (short)0x0002)
        goto loc_5fe3;
    al = memoryAGet(ss, bp + si + -54);
    memoryASet(ss, bp - 4, al);
    al = 0x00;
    memoryASet(ss, bp - 3, al);
    memoryASet(ss, bp - 2, al);
    memoryASet(ds, 0x119a, 0x01);
    sub_5337();
    push(ds);
    ax = 0x0578;
    push(ax);
    sub_27a1();
    sp += 0x0004;
    bx = si;
    bx <<= 1;
    ax = bp - 38;
    bx += ax;
    ax = memoryAGet16(ss, bx);
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx, 0x0090);
    memoryASet16(es, bx + 2, 0x0064);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    ax = 0x0087;
    push(ax);
    ax = 0x0054;
    push(ax);
    push(ds);
    ax = 0x1331;
    push(ax);
    sub_26c0();
    sp += 0x0008;
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    al = 0x02;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    sub_26e6();
    sp += 0x000a;
    goto loc_60e0;
loc_6069: // 01ed:4199
    memoryASet(ds, 0x8244, 0x00);
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_607e;
    memoryASet(ss, bp - 3, 0x01);
    goto loc_60bf;
loc_607e: // 01ed:41ae
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_609c;
    if (memoryAGet(ss, bp - 2) == 0x00)
        goto loc_609c;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) - 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x134b;
    goto loc_60b8;
loc_609c: // 01ed:41cc
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_60bf;
    if (memoryAGet(ss, bp - 2) >= 0x63)
        goto loc_60bf;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x1350;
loc_60b8: // 01ed:41e8
    push(ax);
    sub_26c0();
    sp += 0x0008;
loc_60bf: // 01ed:41ef
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    al = 0x02;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    sub_26e6();
    sp += 0x000a;
    al = 0x04;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_60e0: // 01ed:4210
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    if (!ax)
        goto loc_6069;
    al = memoryAGet(ss, bp - 2);
    memoryASet(ss, bp - 4, al);
    goto loc_610e;
    // gap 29 bytes
loc_610e: // 01ed:423e
    memoryASet(ss, bp - 5, 0xff);
loc_6112: // 01ed:4242
    if (memoryAGet(ss, bp - 5) >= 0x03)
        goto loc_611b;
    goto loc_5fe3;
loc_611b: // 01ed:424b
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6133() // 01ed:4263
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6142;
    sub_ca53();
loc_6142: // 01ed:4272
    memoryASet(ds, 0x8244, 0x00);
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_61a5;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x792c, al);
    if (memoryAGet(ds, 0x792c) == 0x05)
        goto loc_61a5;
    if (memoryAGet(ds, 0x792c) == 0x0b)
        goto loc_61a5;
    if (memoryAGet(ds, 0x792c) == 0x1c)
        goto loc_61a5;
    memoryASet(ds, 0xa0dc, 0x00);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 8788);
    dx = memoryAGet16(ds, bx + 8786);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x824d, al);
    al = memoryAGet(es, bx + 1);
    memoryASet(ds, 0x9bae, al);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa1ac, dx);
    memoryASet16(ds, 0xa1ae, ax);
loc_61a5: // 01ed:42d5
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_61a9() // 01ed:42d9
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_61b5;
    sub_ca53();
loc_61b5: // 01ed:42e5
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_61c0;
    al = 0x03;
    goto loc_61c2;
loc_61c0: // 01ed:42f0
    al = 0x0d;
loc_61c2: // 01ed:42f2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x2d;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_61d5() // 01ed:4305
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_61e1;
    sub_ca53();
loc_61e1: // 01ed:4311
    memoryASet(ds, 0x792c, 0x1c);
    sub_6231();
    bp = pop();
    sp += 2;
}
void sub_61eb() // 01ed:431b
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_61f7;
    sub_ca53();
loc_61f7: // 01ed:4327
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_6203;
    sub_4504();
    goto loc_6212;
loc_6203: // 01ed:4333
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_620f;
    sub_4571();
    goto loc_6212;
loc_620f: // 01ed:433f
    sub_6231();
loc_6212: // 01ed:4342
    bp = pop();
    sp += 2;
}
void sub_6214() // 01ed:4344
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6220;
    sub_ca53();
loc_6220: // 01ed:4350
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_622c;
    sub_61eb();
    goto loc_622f;
loc_622c: // 01ed:435c
    sub_6268();
loc_622f: // 01ed:435f
    bp = pop();
    sp += 2;
}
void sub_6231() // 01ed:4361
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6240;
    sub_ca53();
loc_6240: // 01ed:4370
    memoryASet(ss, bp - 1, 0x15);
    memoryASet(ss, bp - 2, 0x04);
    memoryASet16(ss, bp - 6, 0x1b70);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6268() // 01ed:4398
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6274;
    sub_ca53();
loc_6274: // 01ed:43a4
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_6280;
    sub_6324();
    goto loc_6283;
loc_6280: // 01ed:43b0
    sub_6285();
loc_6283: // 01ed:43b3
    bp = pop();
    sp += 2;
}
void sub_6285() // 01ed:43b5
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6291;
    sub_ca53();
loc_6291: // 01ed:43c1
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_629d;
    sub_635a();
    goto loc_62a0;
loc_629d: // 01ed:43cd
    sub_62a2();
loc_62a0: // 01ed:43d0
    bp = pop();
    sp += 2;
}
void sub_62a2() // 01ed:43d2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_62ae;
    sub_ca53();
loc_62ae: // 01ed:43de
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_62ba;
    sub_6390();
    goto loc_62bd;
loc_62ba: // 01ed:43ea
    sub_62bf();
loc_62bd: // 01ed:43ed
    bp = pop();
    sp += 2;
}
void sub_62bf() // 01ed:43ef
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_62cb;
    sub_ca53();
loc_62cb: // 01ed:43fb
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_62d7;
    sub_6402();
    goto loc_62da;
loc_62d7: // 01ed:4407
    sub_62dc();
loc_62da: // 01ed:440a
    bp = pop();
    sp += 2;
}
void sub_62dc() // 01ed:440c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_62e8;
    sub_ca53();
loc_62e8: // 01ed:4418
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    sub_423f();
    if (memoryAGet(ds, 0x7924) != 0x16)
        goto loc_62fd;
    sub_61d5();
    goto loc_6305;
loc_62fd: // 01ed:442d
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_6305: // 01ed:4435
    bp = pop();
    sp += 2;
}
void sub_6307() // 01ed:4437
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6313;
    sub_ca53();
loc_6313: // 01ed:4443
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_631f;
    sub_62dc();
    goto loc_6322;
loc_631f: // 01ed:444f
    sub_6268();
loc_6322: // 01ed:4452
    bp = pop();
    sp += 2;
}
void sub_6324() // 01ed:4454
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6330;
    sub_ca53();
loc_6330: // 01ed:4460
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_633c;
    sub_6285();
    goto loc_6358;
loc_633c: // 01ed:446c
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_6350;
    sub_6285();
    goto loc_6358;
loc_6350: // 01ed:4480
    al = 0x1d;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_6358: // 01ed:4488
    bp = pop();
    sp += 2;
}
void sub_635a() // 01ed:448a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6366;
    sub_ca53();
loc_6366: // 01ed:4496
    if (memoryAGet(ds, 0x856e) < 0x28)
        goto loc_6372;
    sub_62a2();
    goto loc_638e;
loc_6372: // 01ed:44a2
    al = memoryAGet(ds, 0x856e);
    al += 0x08;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_6386;
    sub_62a2();
    goto loc_638e;
loc_6386: // 01ed:44b6
    al = 0x1e;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_638e: // 01ed:44be
    bp = pop();
    sp += 2;
}
void sub_6390() // 01ed:44c0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_639c;
    sub_ca53();
loc_639c: // 01ed:44cc
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_63aa;
    sub_62bf();
    goto loc_63da;
loc_63aa: // 01ed:44da
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_63be;
    sub_63dc();
    goto loc_63da;
loc_63be: // 01ed:44ee
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_64d5();
    sp++;
    sp++;
    if (!al)
        goto loc_63d2;
    sub_63dc();
    goto loc_63da;
loc_63d2: // 01ed:4502
    al = 0x1f;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_63da: // 01ed:450a
    bp = pop();
    sp += 2;
}
void sub_63dc() // 01ed:450c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_63e8;
    sub_ca53();
loc_63e8: // 01ed:4518
    if (memoryAGet(ds, 0x7924) == 0x16)
        goto loc_63fd;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_63fd: // 01ed:452d
    sub_4504();
    bp = pop();
    sp += 2;
}
void sub_6402() // 01ed:4532
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_640e;
    sub_ca53();
loc_640e: // 01ed:453e
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_641a;
    sub_62dc();
    goto loc_6448;
loc_641a: // 01ed:454a
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_642e;
    sub_644a();
    goto loc_6448;
loc_642e: // 01ed:455e
    al = memoryAGet(ds, 0x856e);
    push(ax);
    sub_64d5();
    sp++;
    sp++;
    if (!al)
        goto loc_6440;
    sub_644a();
    goto loc_6448;
loc_6440: // 01ed:4570
    al = 0x20;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_6448: // 01ed:4578
    bp = pop();
    sp += 2;
}
void sub_644a() // 01ed:457a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6456;
    sub_ca53();
loc_6456: // 01ed:4586
    if (memoryAGet(ds, 0x7924) == 0x16)
        goto loc_646b;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_646b: // 01ed:459b
    sub_4571();
    bp = pop();
    sp += 2;
}
void sub_6470() // 01ed:45a0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_647c;
    sub_ca53();
loc_647c: // 01ed:45ac
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7924) == 0x00)
        goto loc_649a;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = 0x30;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_649a: // 01ed:45ca
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_649f() // 01ed:45cf
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_64ab;
    sub_ca53();
loc_64ab: // 01ed:45db
    dl = 0x00;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx) == 0x00)
        goto loc_64d1;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    bx += ax;
    if (memoryAGet(es, bx) == 0x19)
        goto loc_64d1;
    dl = 0x01;
loc_64d1: // 01ed:4601
    al = dl;
    bp = pop();
    sp += 2;
}
void sub_64d5() // 01ed:4605
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_64e1;
    sub_ca53();
loc_64e1: // 01ed:4611
    dl = 0x00;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 48) == 0x00)
        goto loc_6509;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    bx += ax;
    if (memoryAGet(es, bx + 48) == 0x13)
        goto loc_6509;
    dl = 0x01;
loc_6509: // 01ed:4639
    al = dl;
    bp = pop();
    sp += 2;
}
void sub_650d() // 01ed:463d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6519;
    sub_ca53();
loc_6519: // 01ed:4649
    memoryASet(ds, 0x8242, memoryAGet(ds, 0x8242) + 1);
    if (memoryAGet(ds, 0x8242) != 0x03)
        goto loc_652c;
    memoryASet(ds, 0x8242, 0x00);
    sub_4835();
loc_652c: // 01ed:465c
    bp = pop();
    sp += 2;
}
void sub_652e() // 01ed:465e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_653a;
    sub_ca53();
loc_653a: // 01ed:466a
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14014);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_654d() // 01ed:467d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6559;
    sub_ca53();
loc_6559: // 01ed:4689
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14062);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_656c() // 01ed:469c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6578;
    sub_ca53();
loc_6578: // 01ed:46a8
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14110);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_658b() // 01ed:46bb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6597;
    sub_ca53();
loc_6597: // 01ed:46c7
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (ax == 0x0008)
        goto loc_65d6;
    if ((short)ax > (short)0x0008)
        goto loc_65b1;
    bx = ax;
    if (bx > 0x0003)
        goto loc_65ea;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_65c2;
        case 2: goto loc_65c7;
        case 4: goto loc_65cc;
        case 6: goto loc_65d1;
        default:
            stop("ind 01ed:46dc");
    }
loc_65b1: // 01ed:46e1
    if (ax == 0x0009)
        goto loc_65db;
    if (ax == 0x001a)
        goto loc_65e0;
    if (ax == 0x001b)
        goto loc_65e5;
    goto loc_65ea;
loc_65c2: // 01ed:46f2
    sub_6617();
    goto loc_65f3;
loc_65c7: // 01ed:46f7
    sub_4504();
    goto loc_65f3;
loc_65cc: // 01ed:46fc
    sub_4571();
    goto loc_65f3;
loc_65d1: // 01ed:4701
    sub_46ae();
    goto loc_65f3;
loc_65d6: // 01ed:4706
    sub_45dc();
    goto loc_65f3;
loc_65db: // 01ed:470b
    sub_4646();
    goto loc_65f3;
loc_65e0: // 01ed:4710
    sub_3e8e();
    goto loc_65f3;
loc_65e5: // 01ed:4715
    sub_3f4d();
    goto loc_65f3;
loc_65ea: // 01ed:471a
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
loc_65f3: // 01ed:4723
    bp = pop();
    sp += 2;
}
void sub_65fd() // 01ed:472d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6609;
    sub_ca53();
loc_6609: // 01ed:4739
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_6617() // 01ed:4747
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6625;
    sub_ca53();
loc_6625: // 01ed:4755
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_6632;
    memoryASet(ss, bp - 2, 0x00);
    goto loc_6653;
loc_6632: // 01ed:4762
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx + 65528);
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14158);
    memoryASet(ss, bp - 2, al);
loc_6653: // 01ed:4783
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    if (ax)
        goto loc_668e;
    if (memoryAGet(ds, 0x79b3) <= 0xeb)
        goto loc_6669;
    memoryASet(ss, bp - 2, 0x3c);
    goto loc_668e;
loc_6669: // 01ed:4799
    if (memoryAGet(ds, 0x79b3) <= 0xd7)
        goto loc_6676;
    memoryASet(ss, bp - 2, 0x3d);
    goto loc_668e;
loc_6676: // 01ed:47a6
    if (memoryAGet(ds, 0x79b3) <= 0xc3)
        goto loc_6683;
    memoryASet(ss, bp - 2, 0x3e);
    goto loc_668e;
loc_6683: // 01ed:47b3
    if (memoryAGet(ds, 0x79b3) <= 0xaf)
        goto loc_668e;
    memoryASet(ss, bp - 2, 0x3f);
loc_668e: // 01ed:47be
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_669b() // 01ed:47cb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_66a7;
    sub_ca53();
loc_66a7: // 01ed:47d7
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_66b3;
    sub_4504();
    goto loc_66d0;
loc_66b3: // 01ed:47e3
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_66bf;
    sub_4571();
    goto loc_66d0;
loc_66bf: // 01ed:47ef
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14206);
    push(ax);
    sub_658b();
    sp++;
    sp++;
loc_66d0: // 01ed:4800
    bp = pop();
    sp += 2;
}
void sub_66d2() // 01ed:4802
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_66de;
    sub_ca53();
loc_66de: // 01ed:480e
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_66e9;
    al = 0x03;
    goto loc_66eb;
loc_66e9: // 01ed:4819
    al = 0x28;
loc_66eb: // 01ed:481b
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = 0x27;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    al = 0x0e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    sp += 2;
}
void sub_670c() // 01ed:483c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6718;
    sub_ca53();
loc_6718: // 01ed:4848
    sub_48da();
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(es, bx + 16, dx);
    memoryASet16(es, bx + 18, ax);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0014);
    memoryASet16(es, bx + 26, 0x0019);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_6779() // 01ed:48a9
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6785;
    sub_ca53();
loc_6785: // 01ed:48b5
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_67d4;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ds, 0x8565, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryAGet(ds, 0x8571);
    dl -= al;
    memoryASet(ds, 0x8564, dl);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    ax += 0x0007;
    memoryASet16(ds, 0x79ba, ax);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax += 0x0007;
    memoryASet16(ds, 0x79bc, ax);
loc_67d4: // 01ed:4904
    bp = pop();
    sp += 2;
}
void sub_67d6() // 01ed:4906
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_67e2;
    sub_ca53();
loc_67e2: // 01ed:4912
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ds, 0x855c, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryAGet(ds, 0x856e);
    dl -= al;
    memoryASet(ds, 0x855e, dl);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    ax += 0x0007;
    memoryASet16(ds, 0x9290, ax);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax += 0x000f;
    memoryASet16(ds, 0x9292, ax);
    bp = pop();
    sp += 2;
}
void sub_682c() // 01ed:495c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6838;
    sub_ca53();
loc_6838: // 01ed:4968
    memoryASet(ds, 0x855d, memoryAGet(ds, 0x855d) + 1);
    al = memoryAGet(ds, 0x855d);
    if (al != memoryAGet(ss, bp + 6))
        goto loc_6856;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_6865();
    sp += 0x0006;
    goto loc_6863;
loc_6856: // 01ed:4986
    al = memoryAGet(ds, 0x855d);
    if (al <= memoryAGet(ss, bp + 6))
        goto loc_6863;
    memoryASet(ds, 0x855d, 0x00);
loc_6863: // 01ed:4993
    bp = pop();
    sp += 2;
}
void sub_6865() // 01ed:4995
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6871;
    sub_ca53();
loc_6871: // 01ed:49a1
    memoryASet(ds, 0x855d, 0x00);
    al = memoryAGet(ds, 0xa0dc);
    ah = 0x00;
    ax++;
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    if ((short)ax >= (short)dx)
        goto loc_688e;
    memoryASet(ds, 0xa0dc, memoryAGet(ds, 0xa0dc) + 1);
    al = memoryAGet(ds, 0xa0dc);
    goto loc_6893;
loc_688e: // 01ed:49be
    al = 0x00;
    memoryASet(ds, 0xa0dc, al);
loc_6893: // 01ed:49c3
    al = memoryAGet(ds, 0xa0dc);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x824a, ax);
    bp = pop();
    sp += 2;
}
void sub_68a7() // 01ed:49d7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_68b5;
    sub_ca53();
loc_68b5: // 01ed:49e5
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx, 0x0000);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 16, 0x9694);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0014);
    memoryASet16(es, bx + 26, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0001);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b288();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0x0007;
    push(ax);
    ax = 0;
    push(ax);
    al = 0x07;
    push(ax);
    push(memoryAGet16(ds, 0xa0d6));
    push(memoryAGet16(ds, 0xa0d4));
    sub_26e6();
    sp += 0x000a;
    sub_8000();
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
loc_6949: // 01ed:4a79
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (al)
        goto loc_6949;
    goto loc_69a2;
loc_6957: // 01ed:4a87
    al = 0x1d;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_69a2;
    al = 0x21;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_69a2;
    memoryASet(ss, bp - 1, 0x01);
    goto loc_698c;
loc_6975: // 01ed:4aa5
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    memoryASet(es, bx, 0x01);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_698c: // 01ed:4abc
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul16(dx);
    bx = memoryAGet16(ds, 0x8246); es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_6975;
loc_69a2: // 01ed:4ad2
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    cbw();
    if (ax)
        goto loc_69bc;
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    cbw();
    if (!ax)
        goto loc_6957;
loc_69bc: // 01ed:4aec
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (al)
        goto loc_69bc;
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (al)
        goto loc_69bc;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, 0x9694);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0001);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6a1e() // 01ed:4b4e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6a2c;
    sub_ca53();
loc_6a2c: // 01ed:4b5c
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_6a92;
    bx = memoryAGet16(ds, 0x9b9e); es = memoryAGet16(ds, 0x9b9e + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x79ba);
    ax -= di;
    cl = 0x04;
    ax = sar16(ax, cl);
    ax--;
    memoryASet16(ds, 0xa0ca, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax -= si;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0xa0cc, ax);
    if ((short)memoryAGet16(ds, 0xa0ca) >= (short)0x0000)
        goto loc_6a69;
    memoryASet16(ds, 0xa0ca, 0x0000);
    goto loc_6a76;
loc_6a69: // 01ed:4b99
    if ((short)memoryAGet16(ds, 0xa0ca) <= (short)0x0012)
        goto loc_6a76;
    memoryASet16(ds, 0xa0ca, 0x0012);
loc_6a76: // 01ed:4ba6
    if ((short)memoryAGet16(ds, 0xa0cc) >= (short)0x0000)
        goto loc_6a85;
    memoryASet16(ds, 0xa0cc, 0x0000);
    goto loc_6a92;
loc_6a85: // 01ed:4bb5
    if ((short)memoryAGet16(ds, 0xa0cc) <= (short)0x0016)
        goto loc_6a92;
    memoryASet16(ds, 0xa0cc, 0x0016);
loc_6a92: // 01ed:4bc2
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_6a96() // 01ed:4bc6
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6aa5;
    sub_ca53();
loc_6aa5: // 01ed:4bd5
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x8562, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 9506);
    dx = memoryAGet16(ds, bx + 9504);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0xa1b0, al);
    al = memoryAGet(es, bx + 1);
    memoryASet(ds, 0x9d2f, al);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0ba, dx);
    memoryASet16(ds, 0xa0bc, ax);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6ae4() // 01ed:4c14
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6af0;
    sub_ca53();
loc_6af0: // 01ed:4c20
    al = memoryAGet(ds, 0x8243);
    al ^= 0x01;
    memoryASet(ds, 0x8243, al);
    if (memoryAGet(ds, 0x8243) == 0x00)
        goto loc_6b67;
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_6b67;
    bx = memoryAGet16(ds, 0xa0ba); es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x8560, ax);
    if (memoryAGet(ds, 0x9d2f) == 0x00)
        goto loc_6b2b;
    ax = memoryAGet16(es, bx + 2);
    ax = -ax;
    dx = memoryAGet16(ds, 0x79ba);
    dx += ax;
    memoryASet16(ds, 0x79ba, dx);
    ax = dx;
    goto loc_6b3a;
loc_6b2b: // 01ed:4c5b
    bx = memoryAGet16(ds, 0xa0ba); es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x79ba, memoryAGet16(ds, 0x79ba) + ax);
    ax = memoryAGet16(ds, 0x79ba);
loc_6b3a: // 01ed:4c6a
    bx = memoryAGet16(ds, 0xa0ba); es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x79bc, memoryAGet16(ds, 0x79bc) + ax);
    memoryASet16(ds, 0xa0ba, memoryAGet16(ds, 0xa0ba) + 0x0006);
    al = memoryAGet(ds, 0xa1b0);
    al += 0xff;
    memoryASet(ds, 0xa1b0, al);
    ah = 0x00;
    if (ax)
        goto loc_6b60;
    al = 0x00;
    memoryASet(ds, 0x8563, al);
    goto loc_6b67;
loc_6b60: // 01ed:4c90
    memoryASet(ds, 0x8563, memoryAGet(ds, 0x8563) + 1);
    al = memoryAGet(ds, 0x8563);
loc_6b67: // 01ed:4c97
    bp = pop();
    sp += 2;
}
void sub_6b69() // 01ed:4c99
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6b75;
    sub_ca53();
loc_6b75: // 01ed:4ca5
    if (memoryAGet(ds, 0x8243) != 0x00)
        goto loc_6b7f;
    goto loc_6c8d;
loc_6b7f: // 01ed:4caf
    if (memoryAGet(ds, 0x8571) != 0xff)
        goto loc_6b89;
    goto loc_6c8d;
loc_6b89: // 01ed:4cb9
    if (memoryAGet(ds, 0xa1b0) == 0x00)
        goto loc_6b96;
    sub_6ed3();
    goto loc_6c8d;
loc_6b96: // 01ed:4cc6
    al = 0x01;
    memoryASet(ds, 0xa1b2, al);
    memoryASet(ds, 0xa0e2, al);
    memoryASet(ds, 0xa0e1, al);
    memoryASet(ds, 0xa0e0, al);
    if (memoryAGet(ds, 0x8571) < 0x08)
        goto loc_6bc9;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx + 65528);
    ah = 0x00;
    if (ax)
        goto loc_6bc9;
    memoryASet(ds, 0xa0e0, 0x00);
loc_6bc9: // 01ed:4cf9
    if (memoryAGet(ds, 0x8571) >= 0x28)
        goto loc_6be9;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    if (ax)
        goto loc_6be9;
    memoryASet(ds, 0xa0e1, 0x00);
loc_6be9: // 01ed:4d19
    if (memoryAGet(ds, 0x8564) == 0x00)
        goto loc_6c21;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 47);
    ah = 0x00;
    if (ax)
        goto loc_6c21;
    memoryASet(ds, 0xa0e2, 0x00);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 65535) != 0x0b)
        goto loc_6c21;
    memoryASet(ds, 0xa0e2, 0x01);
loc_6c21: // 01ed:4d51
    if (memoryAGet(ds, 0x8564) == 0x07)
        goto loc_6c59;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    ah = 0x00;
    if (ax)
        goto loc_6c59;
    memoryASet(ds, 0xa1b2, 0x00);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 1) != 0x0b)
        goto loc_6c59;
    memoryASet(ds, 0xa1b2, 0x01);
loc_6c59: // 01ed:4d89
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    dl = memoryAGet(ds, 0xa0e1);
    dh = 0x00;
    ax += dx;
    dl = memoryAGet(ds, 0xa0e2);
    dh = 0x00;
    ax += dx;
    dl = memoryAGet(ds, 0xa1b2);
    dh = 0x00;
    ax += dx;
    if (ax != 0x0004)
        goto loc_6c80;
    sub_6ea3();
    goto loc_6c8d;
loc_6c80: // 01ed:4db0
    al = memoryAGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    switch (bx)
    {
        case 0: sub_8fe1(); break;
        case 2: sub_6c8f(); break;
        case 4: sub_6d14(); break;
        case 6: sub_6d99(); break;
        case 8: sub_6e1e(); break;
        case 10: sub_6c8f(); break;
        case 12: sub_6c8f(); break;
        case 14: sub_6c8f(); break;
        case 16: sub_6c8f(); break;
        case 18: sub_6c8f(); break;
        case 20: sub_8fe1(); break;
        case 22: sub_1fcf(); break;
        default:
            stop("ind 01ed:4db9");
    }
loc_6c8d: // 01ed:4dbd
    bp = pop();
    sp += 2;
}
void sub_6c8f() // 01ed:4dbf
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6c9b;
    sub_ca53();
loc_6c9b: // 01ed:4dcb
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6ca9;
    sub_6cca();
    goto loc_6cc8;
loc_6ca9: // 01ed:4dd9
    al = memoryAGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6cb7;
    sub_6e59();
    goto loc_6cc8;
loc_6cb7: // 01ed:4de7
    al = memoryAGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6cc5;
    sub_6dd4();
    goto loc_6cc8;
loc_6cc5: // 01ed:4df5
    sub_6d4f();
loc_6cc8: // 01ed:4df8
    bp = pop();
    sp += 2;
}
void sub_6cca() // 01ed:4dfa
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6cd6;
    sub_ca53();
loc_6cd6: // 01ed:4e06
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6ce3;
    al = 0x01;
    goto loc_6d0c;
loc_6ce3: // 01ed:4e13
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6cff;
    if (memoryAGet(ds, 0xa0e2) == 0x00)
        goto loc_6cf5;
    al = 0x01;
    goto loc_6d0c;
loc_6cf5: // 01ed:4e25
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d12;
loc_6cff: // 01ed:4e2f
    if (memoryAGet(ds, 0xa1b2) == 0x00)
        goto loc_6d0a;
    al = 0x01;
    goto loc_6d0c;
loc_6d0a: // 01ed:4e3a
    al = 0x04;
loc_6d0c: // 01ed:4e3c
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d12: // 01ed:4e42
    bp = pop();
    sp += 2;
}
void sub_6d14() // 01ed:4e44
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6d20;
    sub_ca53();
loc_6d20: // 01ed:4e50
    al = memoryAGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6d2e;
    sub_6d4f();
    goto loc_6d4d;
loc_6d2e: // 01ed:4e5e
    al = memoryAGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6d3c;
    sub_6dd4();
    goto loc_6d4d;
loc_6d3c: // 01ed:4e6c
    al = memoryAGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6d4a;
    sub_6e59();
    goto loc_6d4d;
loc_6d4a: // 01ed:4e7a
    sub_6cca();
loc_6d4d: // 01ed:4e7d
    bp = pop();
    sp += 2;
}
void sub_6d4f() // 01ed:4e7f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6d5b;
    sub_ca53();
loc_6d5b: // 01ed:4e8b
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6d68;
    al = 0x02;
    goto loc_6d91;
loc_6d68: // 01ed:4e98
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6d84;
    if (memoryAGet(ds, 0xa0e2) == 0x00)
        goto loc_6d7a;
    al = 0x02;
    goto loc_6d91;
loc_6d7a: // 01ed:4eaa
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d97;
loc_6d84: // 01ed:4eb4
    if (memoryAGet(ds, 0xa1b2) == 0x00)
        goto loc_6d8f;
    al = 0x02;
    goto loc_6d91;
loc_6d8f: // 01ed:4ebf
    al = 0x04;
loc_6d91: // 01ed:4ec1
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d97: // 01ed:4ec7
    bp = pop();
    sp += 2;
}
void sub_6d99() // 01ed:4ec9
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6da5;
    sub_ca53();
loc_6da5: // 01ed:4ed5
    al = memoryAGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6db3;
    sub_6dd4();
    goto loc_6dd2;
loc_6db3: // 01ed:4ee3
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6dc1;
    sub_6cca();
    goto loc_6dd2;
loc_6dc1: // 01ed:4ef1
    al = memoryAGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6dcf;
    sub_6d4f();
    goto loc_6dd2;
loc_6dcf: // 01ed:4eff
    sub_6e59();
loc_6dd2: // 01ed:4f02
    bp = pop();
    sp += 2;
}
void sub_6dd4() // 01ed:4f04
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6de0;
    sub_ca53();
loc_6de0: // 01ed:4f10
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6ded;
    al = 0x03;
    goto loc_6e16;
loc_6ded: // 01ed:4f1d
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6e09;
    if (memoryAGet(ds, 0xa0e0) == 0x00)
        goto loc_6dff;
    al = 0x03;
    goto loc_6e16;
loc_6dff: // 01ed:4f2f
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6e1c;
loc_6e09: // 01ed:4f39
    if (memoryAGet(ds, 0xa0e1) == 0x00)
        goto loc_6e14;
    al = 0x03;
    goto loc_6e16;
loc_6e14: // 01ed:4f44
    al = 0x02;
loc_6e16: // 01ed:4f46
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6e1c: // 01ed:4f4c
    bp = pop();
    sp += 2;
}
void sub_6e1e() // 01ed:4f4e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6e2a;
    sub_ca53();
loc_6e2a: // 01ed:4f5a
    al = memoryAGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6e38;
    sub_6e59();
    goto loc_6e57;
loc_6e38: // 01ed:4f68
    al = memoryAGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6e46;
    sub_6d4f();
    goto loc_6e57;
loc_6e46: // 01ed:4f76
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6e54;
    sub_6cca();
    goto loc_6e57;
loc_6e54: // 01ed:4f84
    sub_6dd4();
loc_6e57: // 01ed:4f87
    bp = pop();
    sp += 2;
}
void sub_6e59() // 01ed:4f89
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6e65;
    sub_ca53();
loc_6e65: // 01ed:4f95
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6e72;
    al = 0x04;
    goto loc_6e9b;
loc_6e72: // 01ed:4fa2
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6e8e;
    if (memoryAGet(ds, 0xa0e0) == 0x00)
        goto loc_6e84;
    al = 0x04;
    goto loc_6e9b;
loc_6e84: // 01ed:4fb4
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6ea1;
loc_6e8e: // 01ed:4fbe
    if (memoryAGet(ds, 0xa0e1) == 0x00)
        goto loc_6e99;
    al = 0x04;
    goto loc_6e9b;
loc_6e99: // 01ed:4fc9
    al = 0x02;
loc_6e9b: // 01ed:4fcb
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6ea1: // 01ed:4fd1
    bp = pop();
    sp += 2;
}
void sub_6ea3() // 01ed:4fd3
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6eb1;
    sub_ca53();
loc_6eb1: // 01ed:4fe1
    al = memoryAGet(ds, 0x79b3);
    al &= 0x03;
    memoryASet(ss, bp - 2, al);
    sub_b281();
    memoryASet(ds, 0x79b3, al);
    al &= 0x01;
    al += memoryAGet(ss, bp - 2);
    al += 0x05;
    memoryASet(ss, bp - 1, al);
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6ed3() // 01ed:5003
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6edf;
    sub_ca53();
loc_6edf: // 01ed:500f
    if (memoryAGet(ds, 0x8563) != 0x05)
        goto loc_6ef3;
    al = memoryAGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    switch (bx)
    {
        case 0: sub_8fe1(); break;
        case 2: sub_6ef5(); break;
        case 4: sub_6f0f(); break;
        case 6: sub_6f29(); break;
        case 8: sub_6f3f(); break;
        case 10: sub_8fe1(); break;
        case 12: sub_8fe1(); break;
        case 14: sub_8fe1(); break;
        case 16: sub_8fe1(); break;
        case 18: sub_8fe1(); break;
        case 20: sub_8fe1(); break;
        case 22: sub_6c8f(); break;
        case 24: sub_6d14(); break;
        case 26: sub_6d99(); break;
        case 28: sub_6e1e(); break;
        case 30: sub_6c8f(); break;
        case 32: sub_6c8f(); break;
        case 34: sub_6c8f(); break;
        case 36: sub_6c8f(); break;
        case 38: sub_6c8f(); break;
        case 40: sub_8fe1(); break;
        default:
            stop("ind 01ed:501f");
    }
loc_6ef3: // 01ed:5023
    bp = pop();
    sp += 2;
}
void sub_6ef5() // 01ed:5025
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f01;
    sub_ca53();
loc_6f01: // 01ed:5031
    al = memoryAGet(ds, 0x8571);
    al += 0xf8;
    memoryASet(ds, 0x8571, al);
    memoryASet(ds, 0x8565, memoryAGet(ds, 0x8565) - 1);
    bp = pop();
    sp += 2;
}
void sub_6f0f() // 01ed:503f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f1b;
    sub_ca53();
loc_6f1b: // 01ed:504b
    al = memoryAGet(ds, 0x8571);
    al += 0x08;
    memoryASet(ds, 0x8571, al);
    memoryASet(ds, 0x8565, memoryAGet(ds, 0x8565) + 1);
    bp = pop();
    sp += 2;
}
void sub_6f29() // 01ed:5059
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f35;
    sub_ca53();
loc_6f35: // 01ed:5065
    memoryASet(ds, 0x8571, memoryAGet(ds, 0x8571) - 1);
    memoryASet(ds, 0x8564, memoryAGet(ds, 0x8564) - 1);
    bp = pop();
    sp += 2;
}
void sub_6f3f() // 01ed:506f
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f4b;
    sub_ca53();
loc_6f4b: // 01ed:507b
    memoryASet(ds, 0x8571, memoryAGet(ds, 0x8571) + 1);
    memoryASet(ds, 0x8564, memoryAGet(ds, 0x8564) + 1);
    bp = pop();
    sp += 2;
}
void sub_6f55() // 01ed:5085
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f61;
    sub_ca53();
loc_6f61: // 01ed:5091
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6f8e;
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfffb;
    memoryASet16(ds, 0x084c, ax);
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x0006;
    memoryASet16(ds, 0x084e, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffb;
    memoryASet16(ds, 0x0850, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0005;
    memoryASet16(ds, 0x0852, ax);
loc_6f8e: // 01ed:50be
    bp = pop();
    sp += 2;
}
void sub_6f90() // 01ed:50c0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f9c;
    sub_ca53();
loc_6f9c: // 01ed:50cc
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6fc9;
    ax = memoryAGet16(ds, 0x79ba);
    ax += 0xfffb;
    memoryASet16(ds, 0x0854, ax);
    ax = memoryAGet16(ds, 0x79ba);
    ax += 0x0006;
    memoryASet16(ds, 0x0856, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax += 0xfffb;
    memoryASet16(ds, 0x0858, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax += 0x0005;
    memoryASet16(ds, 0x085a, ax);
loc_6fc9: // 01ed:50f9
    bp = pop();
    sp += 2;
}
void sub_6fcb() // 01ed:50fb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6fd7;
    sub_ca53();
loc_6fd7: // 01ed:5107
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_704f;
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    al = memoryAGet(ds, 0x856d);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    if (memoryAGet(ds, 0x792c) == 0x30)
        goto loc_704f;
    ax = memoryAGet16(ds, 0x0854);
    if ((short)ax <= (short)memoryAGet16(ds, 0x084e))
        goto loc_7007;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7007: // 01ed:5137
    ax = memoryAGet16(ds, 0x084c);
    if ((short)ax <= (short)memoryAGet16(ds, 0x0856))
        goto loc_7017;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7017: // 01ed:5147
    ax = memoryAGet16(ds, 0x0858);
    if ((short)ax <= (short)memoryAGet16(ds, 0x0852))
        goto loc_7027;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7027: // 01ed:5157
    ax = memoryAGet16(ds, 0x0850);
    if ((short)ax <= (short)memoryAGet16(ds, 0x085a))
        goto loc_7037;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7037: // 01ed:5167
    memoryASet(ds, 0xa1aa, 0x01);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_7047;
    al = 0x03;
    goto loc_7049;
loc_7047: // 01ed:5177
    al = 0x0d;
loc_7049: // 01ed:5179
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_704f: // 01ed:517f
    bp = pop();
    sp += 2;
}
void sub_7051() // 01ed:5181
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_705d;
    sub_ca53();
loc_705d: // 01ed:518d
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(es, bx, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b298();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_70a8() // 01ed:51d8
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_70b4;
    sub_ca53();
loc_70b4: // 01ed:51e4
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x9d3a);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0004);
    memoryASet16(es, bx + 16, 0x9baf);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0008);
    memoryASet16(es, bx + 16, 0x9eba);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0001);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0003);
    memoryASet16(es, bx + 16, 0x9fba);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x000d);
    memoryASet16(es, bx + 16, 0x8b88);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0006);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 30, 0x0006);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0011);
    memoryASet16(es, bx + 16, 0x824e);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0015);
    memoryASet16(es, bx + 16, 0x8582);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_722e() // 01ed:535e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_723a;
    sub_ca53();
loc_723a: // 01ed:536a
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    bx = memoryAGet16(ds, 0x08b8); es = memoryAGet16(ds, 0x08b8 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 16, 0x8e8d);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0004);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08ec); es = memoryAGet16(ds, 0x08ec + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 16, 0x9294);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0004);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08bc); es = memoryAGet16(ds, 0x08bc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0001);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08c0); es = memoryAGet16(ds, 0x08c0 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 12, 0x0002);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0002);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08c4); es = memoryAGet16(ds, 0x08c4 + 2);
    memoryASet16(es, bx + 2, 0x8e8d);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0004);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08e8); es = memoryAGet16(ds, 0x08e8 + 2);
    memoryASet16(es, bx + 2, 0x9294);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0004);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08c8); es = memoryAGet16(ds, 0x08c8 + 2);
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08cc); es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08d0); es = memoryAGet16(ds, 0x08d0 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0001);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08d4); es = memoryAGet16(ds, 0x08d4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 30, 0x0002);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08d8); es = memoryAGet16(ds, 0x08d8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08dc); es = memoryAGet16(ds, 0x08dc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08e0); es = memoryAGet16(ds, 0x08e0 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08e4); es = memoryAGet16(ds, 0x08e4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 32, 0x0002);
    bp = pop();
    sp += 2;
}
void sub_7551() // 01ed:5681
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7562;
    sub_ca53();
loc_7562: // 01ed:5692
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x094e));
    push(memoryAGet16(ds, 0x094c));
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_760a;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_7604;
loc_75e7: // 01ed:5717
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96); es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_7604: // 01ed:5734
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_75e7;
loc_760a: // 01ed:573a
    sub_5337();
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0002);
    sub_76b1();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_76b1() // 01ed:57e1
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_76c0;
    sub_ca53();
loc_76c0: // 01ed:57f0
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    memoryASet(ss, bp - 9, 0x00);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_7879;
loc_76d3: // 01ed:5803
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memoryASet16(ds, 0x8574, ax);
    memoryASet16(ds, 0x8576, ds);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    if (ax <= memoryAGet16(ds, 0xa0d6))
        goto loc_76fd;
    goto loc_77d1;
loc_76fd: // 01ed:582d
    if (ax < memoryAGet16(ds, 0xa0d6))
        goto loc_7708;
    if (dx < memoryAGet16(ds, 0xa0d4))
        goto loc_7708;
    goto loc_77d1;
loc_7708: // 01ed:5838
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    if (!ax)
        goto loc_7714;
    goto loc_77d1;
loc_7714: // 01ed:5844
    memoryASet(ss, bp - 9, 0x01);
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 2, al);
    ax = memoryAGet16(ds, 0x0922);
    dx = memoryAGet16(ds, 0x0920);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    memoryASet(ss, bp - 10, 0x06);
    goto loc_7784;
loc_7731: // 01ed:5861
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 2282);
    dx = memoryAGet16(ds, bx + 2280);
    bl = memoryAGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 2288, dx);
    memoryASet16(ds, bx + 2290, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 2286);
    dx = memoryAGet16(ds, bx + 2284);
    bl = memoryAGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 2292, dx);
    memoryASet16(ds, bx + 2294, ax);
    memoryASet(ss, bp - 10, memoryAGet(ss, bp - 10) - 1);
loc_7784: // 01ed:58b4
    al = memoryAGet(ss, bp - 10);
    if (al > memoryAGet(ss, bp - 1))
        goto loc_7731;
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(ss, bp - 4);
    dx = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, dx);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 10, 0x00);
    goto loc_77b8;
loc_77a3: // 01ed:58d3
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    bx += ax;
    memoryASet(es, bx, 0x41);
    memoryASet(ss, bp - 10, memoryAGet(ss, bp - 10) + 1);
loc_77b8: // 01ed:58e8
    if (memoryAGet(ss, bp - 10) < 0x08)
        goto loc_77a3;
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(ds, 0xa0d6);
    dx = memoryAGet16(ds, 0xa0d4);
    memoryASet16(es, bx + 4, dx);
    memoryASet16(es, bx + 6, ax);
loc_77d1: // 01ed:5901
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 7, 0x00);
    goto loc_784a;
loc_77eb: // 01ed:591b
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 7);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 8, al);
    if (al != 0x2e)
        goto loc_781a;
    if (memoryAGet(ss, bp - 9) == 0x00)
        goto loc_7815;
    al = memoryAGet(ss, bp - 2);
    if (al != memoryAGet(ss, bp - 1))
        goto loc_7815;
    al = 0x5b;
    goto loc_7817;
loc_7815: // 01ed:5945
    al = 0x20;
loc_7817: // 01ed:5947
    memoryASet(ss, bp - 8, al);
loc_781a: // 01ed:594a
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    al = memoryAGet(ss, bp - 8);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 7);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 8) == 0x20)
        goto loc_7847;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7847: // 01ed:5977
    memoryASet(ss, bp - 7, memoryAGet(ss, bp - 7) + 1);
loc_784a: // 01ed:597a
    if (memoryAGet(ss, bp - 7) < 0x08)
        goto loc_77eb;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    push(ax);
    ax = 0x00b0;
    push(ax);
    al = 0x07;
    push(ax);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    sub_7f0d();
    sp += 0x000a;
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_7879: // 01ed:59a9
    if (memoryAGet(ss, bp - 1) >= 0x07)
        goto loc_7882;
    goto loc_76d3;
loc_7882: // 01ed:59b2
    if (memoryAGet(ss, bp - 9) == 0x00)
        goto loc_7893;
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_78a3();
    sp++;
    sp++;
    goto loc_7896;
loc_7893: // 01ed:59c3
    sub_515f();
loc_7896: // 01ed:59c6
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_78a3() // 01ed:59d3
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_78b2;
    sub_ca53();
loc_78b2: // 01ed:59e2
    memoryASet(ss, bp - 2, 0x00);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memoryASet16(ds, 0x8574, ax);
    memoryASet16(ds, 0x8576, ds);
    memoryASet16(ss, bp - 6, 0x01b6);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    memoryASet(es, bx, 0x41);
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax += 0x0008;
    memoryASet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_791a: // 01ed:5a4a
    if (!(memoryAGet(ss, bp - 1) & 0x01))
        goto loc_7984;
    if ((short)memoryAGet16(ss, bp - 6) <= (short)0x01ac)
        goto loc_7984;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) - 1);
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7936;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7936: // 01ed:5a66
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_795e;
    memoryASet16(ss, bp - 6, 0x005b);
loc_795e: // 01ed:5a8e
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7984: // 01ed:5ab4
    if (!(memoryAGet(ss, bp - 1) & 0x02))
        goto loc_79ee;
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x01d0)
        goto loc_79ee;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_79a0;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_79a0: // 01ed:5ad0
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_79c8;
    memoryASet16(ss, bp - 6, 0x005b);
loc_79c8: // 01ed:5af8
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_79ee: // 01ed:5b1e
    if (memoryAGet(ss, bp - 1) & 0x04)
        goto loc_79f7;
    goto loc_7a7b;
loc_79f7: // 01ed:5b27
    if (memoryAGet(ss, bp - 2) == 0x00)
        goto loc_7a7b;
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a09;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7a09: // 01ed:5b39
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) - 1);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_7a4a;
    memoryASet16(ss, bp - 6, 0x005b);
loc_7a4a: // 01ed:5b7a
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7a7b: // 01ed:5bab
    if (memoryAGet(ss, bp - 1) & 0x08)
        goto loc_7a84;
    goto loc_7b07;
loc_7a84: // 01ed:5bb4
    if (memoryAGet(ss, bp - 2) >= 0x07)
        goto loc_7b07;
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a96;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7a96: // 01ed:5bc6
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    bx = memoryAGet16(ds, 0x8574); es = memoryAGet16(ds, 0x8574 + 2);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_7ad7;
    memoryASet16(ss, bp - 6, 0x005b);
loc_7ad7: // 01ed:5c07
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7b07: // 01ed:5c37
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
    if (!(memoryAGet(ss, bp - 3) & 0x08))
        goto loc_7b1d;
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7b25;
loc_7b1d: // 01ed:5c4d
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7b25: // 01ed:5c55
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7b30: // 01ed:5c60
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7b48;
    goto loc_791a;
loc_7b48: // 01ed:5c78
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7b57() // 01ed:5c87
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7b66;
    sub_ca53();
loc_7b66: // 01ed:5c96
    push(ss);
    ax = bp - 10;
    push(ax);
    push(ds);
    ax = 0x256a;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0002);
    al = 0x00;
    memoryASet(ss, bp - 6, al);
    memoryASet(ss, bp - 3, al);
    ax = memoryAGet16(ss, bp - 8);
    dx = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 14, dx);
    memoryASet16(ss, bp - 12, ax);
    memoryASet(ss, bp - 2, 0x00);
    goto loc_7bbd;
loc_7bac: // 01ed:5cdc
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    memoryASet(es, bx, 0x41);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_7bbd: // 01ed:5ced
    if (memoryAGet(ss, bp - 2) < 0x06)
        goto loc_7bac;
    memoryASet16(ss, bp - 20, 0x01b6);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    memoryASet(es, bx, 0x41);
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    memoryASet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c09: // 01ed:5d39
    if (!(memoryAGet(ss, bp - 1) & 0x01))
        goto loc_7c6d;
    if ((short)memoryAGet16(ss, bp - 20) <= (short)0x01ac)
        goto loc_7c6d;
    memoryASet16(ss, bp - 20, memoryAGet16(ss, bp - 20) - 1);
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c25;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7c25: // 01ed:5d55
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7c49;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7c49: // 01ed:5d79
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c6d: // 01ed:5d9d
    if (!(memoryAGet(ss, bp - 1) & 0x02))
        goto loc_7cd1;
    if ((short)memoryAGet16(ss, bp - 20) >= (short)0x01d0)
        goto loc_7cd1;
    memoryASet16(ss, bp - 20, memoryAGet16(ss, bp - 20) + 1);
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c89;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7c89: // 01ed:5db9
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7cad;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7cad: // 01ed:5ddd
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7cd1: // 01ed:5e01
    if (!(memoryAGet(ss, bp - 1) & 0x04))
        goto loc_7d54;
    if (memoryAGet(ss, bp - 3) == 0x00)
        goto loc_7d54;
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7ce9;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7ce9: // 01ed:5e19
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) - 1);
    memoryASet(ss, bp + 6, memoryAGet(ss, bp + 6) - 1);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 20, ax);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7d25;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7d25: // 01ed:5e55
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7d54: // 01ed:5e84
    if (!(memoryAGet(ss, bp - 1) & 0x08))
        goto loc_7dd6;
    if (memoryAGet(ss, bp - 3) >= 0x05)
        goto loc_7dd6;
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7d6c;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7d6c: // 01ed:5e9c
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
    memoryASet(ss, bp + 6, memoryAGet(ss, bp + 6) + 1);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 20, ax);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7da8;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7da8: // 01ed:5ed8
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7dd6: // 01ed:5f06
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
    if (!(memoryAGet(ss, bp - 6) & 0x08))
        goto loc_7dec;
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7df4;
loc_7dec: // 01ed:5f1c
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7df4: // 01ed:5f24
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7dff: // 01ed:5f2f
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7e17;
    goto loc_7c09;
loc_7e17: // 01ed:5f47
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    memoryASet(ss, bp - 4, al);
    memoryASet(ss, bp - 2, al);
    goto loc_7e95;
loc_7e2c: // 01ed:5f5c
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4958);
    dx = memoryAGet16(ds, bx + 4956);
    memoryASet16(ss, bp - 18, dx);
    memoryASet16(ss, bp - 16, ax);
    al = 0x00;
    memoryASet(ss, bp - 5, al);
    memoryASet(ss, bp - 3, al);
    goto loc_7e72;
loc_7e4f: // 01ed:5f7f
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14); es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ss, bp - 3);
    dh = 0x00;
    bx = memoryAGet16(ss, bp - 18); es = memoryAGet16(ss, bp - 18 + 2);
    bx += dx;
    if (al == memoryAGet(es, bx))
        goto loc_7e6f;
    memoryASet(ss, bp - 5, 0x01);
loc_7e6f: // 01ed:5f9f
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
loc_7e72: // 01ed:5fa2
    if (memoryAGet(ss, bp - 3) >= 0x06)
        goto loc_7e81;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_7e4f;
loc_7e81: // 01ed:5fb1
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (ax)
        goto loc_7e92;
    al = memoryAGet(ss, bp - 2);
    al += 0x02;
    memoryASet(ss, bp - 4, al);
loc_7e92: // 01ed:5fc2
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_7e95: // 01ed:5fc5
    if (memoryAGet(ss, bp - 2) >= 0x08)
        goto loc_7ea4;
    al = memoryAGet(ss, bp - 4);
    ah = 0x00;
    if (!ax)
        goto loc_7e2c;
loc_7ea4: // 01ed:5fd4
    al = memoryAGet(ss, bp - 4);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7eab() // 01ed:5fdb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7eb7;
    sub_ca53();
loc_7eb7: // 01ed:5fe7
    bx = memoryAGet16(ds, 0x0574); es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    memoryASet16(es, bx + 2, ax);
    if (memoryAGet(ss, bp + 10) == 0x00)
        goto loc_7f03;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7f03: // 01ed:6033
    al = 0x08;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_7f0d() // 01ed:603d
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    si = memoryAGet16(ss, bp + 10);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7f20;
    sub_ca53();
loc_7f20: // 01ed:6050
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp - 12, al);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_7f3f;
loc_7f2c: // 01ed:605c
    al = memoryAGet(ss, bp - 11);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x20);
loc_7f3f: // 01ed:606f
    al = memoryAGet(ss, bp - 11);
    if (al < memoryAGet(ss, bp + 8))
        goto loc_7f2c;
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x00);
    goto loc_7f9e;
loc_7f59: // 01ed:6089
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c7be();
    memoryASet16(ss, bp + 4, ax);
    bx = ax;
    memoryASet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryAGet(ss, bp - 1);
    dl -= al;
    memoryASet(ss, bp - 1, dl);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    dl = memoryAGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memoryASet(ss, bx, dl);
loc_7f9e: // 01ed:60ce
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp + 8, memoryAGet(ss, bp + 8) - 1);
    if (al)
        goto loc_7f59;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_7ff3;
loc_7fb9: // 01ed:60e9
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    dx = bp - 10;
    ax += dx;
    bx = ax;
    al = memoryAGet(ss, bx);
    ah = 0x00;
    ax += 0x017c;
    bx = memoryAGet16(ds, 0x8884); es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    dx = si;
    dx += ax;
    memoryASet16(es, bx, dx);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
loc_7ff3: // 01ed:6123
    al = memoryAGet(ss, bp - 11);
    if (al < memoryAGet(ss, bp - 12))
        goto loc_7fb9;
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8000() // 01ed:6130
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_800e;
    sub_ca53();
loc_800e: // 01ed:613e
    bx = memoryAGet16(ds, 0xa0d0); es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx + 4, 0x01aa);
    memoryASet16(es, bx + 2, 0x0000);
    al = memoryAGet(ds, 0x791a);
    memoryASet(ss, bp - 1, al);
    goto loc_8049;
loc_8026: // 01ed:6156
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0050;
    bx = memoryAGet16(ds, 0xa0d0); es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x7986;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_8049: // 01ed:6179
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_8026;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8053() // 01ed:6183
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8061;
    sub_ca53();
loc_8061: // 01ed:6191
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    memoryASet(ds, 0xa1a6, 0x00);
    dl = 0x00;
    goto loc_809b;
loc_807c: // 01ed:61ac
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_8099;
    if (cl >= 0x12)
        goto loc_8099;
    memoryASet(ds, 0xa1a6, al);
loc_8099: // 01ed:61c9
    dl++;
loc_809b: // 01ed:61cb
    if (dl >= 0x30)
        goto loc_80a9;
    al = memoryAGet(ds, 0xa1a6);
    ah = 0x00;
    if (!ax)
        goto loc_807c;
loc_80a9: // 01ed:61d9
    if (memoryAGet(ds, 0xa1a6) != 0x00)
        goto loc_80b3;
    goto loc_8168;
loc_80b3: // 01ed:61e3
    al = 0x00;
    memoryASet(ss, bp - 1, al);
    dl = al;
    goto loc_80e2;
loc_80bc: // 01ed:61ec
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_80e0;
    if (cl >= 0x12)
        goto loc_80e0;
    if (al == memoryAGet(ds, 0xa1a6))
        goto loc_80e0;
    memoryASet(ss, bp - 1, 0x01);
loc_80e0: // 01ed:6210
    dl++;
loc_80e2: // 01ed:6212
    if (dl >= 0x30)
        goto loc_80f0;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_80bc;
loc_80f0: // 01ed:6220
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_8168;
    al = 0x00;
    memoryASet(ss, bp - 2, al);
    memoryASet(ss, bp - 1, al);
    dl = 0x00;
    goto loc_812b;
loc_8105: // 01ed:6235
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 48) != 0x05)
        goto loc_8129;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    bx += ax;
    al = dl;
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_8129: // 01ed:6259
    dl++;
loc_812b: // 01ed:625b
    if (dl >= 0x30)
        goto loc_8139;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_8105;
loc_8139: // 01ed:6269
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    bx += ax;
    if (memoryAGet(es, bx) == 0xff)
        goto loc_8168;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6);
    bx += ax;
    memoryASet(es, bx, 0xff);
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    memoryASet(ds, 0x79b7, 0x00);
loc_8168: // 01ed:6298
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_816c() // 01ed:629c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8178;
    sub_ca53();
loc_8178: // 01ed:62a8
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    if (memoryAGet(es, bx) != 0xff)
        goto loc_8196;
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    goto loc_81d3;
loc_8196: // 01ed:62c6
    al = memoryAGet(ds, 0x79b7);
    ah = 0x00;
    if (ax)
        goto loc_81cf;
    memoryASet(ds, 0x79b7, 0x0a);
    bx = memoryAGet16(ds, 0x9ba6); es = memoryAGet16(ds, 0x9ba6 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8570, al);
    al = 0x18;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_81c1;
    al = 0x11;
    goto loc_81c3;
loc_81c1: // 01ed:62f1
    al = 0x0e;
loc_81c3: // 01ed:62f3
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet16(ds, 0x9ba6, memoryAGet16(ds, 0x9ba6) + 1);
    goto loc_81d3;
loc_81cf: // 01ed:62ff
    memoryASet(ds, 0x79b7, memoryAGet(ds, 0x79b7) - 1);
loc_81d3: // 01ed:6303
    bp = pop();
    sp += 2;
}
void sub_81d5() // 01ed:6305
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_81e1;
    sub_ca53();
loc_81e1: // 01ed:6311
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_81ec;
    al = 0x03;
    goto loc_81ee;
loc_81ec: // 01ed:631c
    al = 0x0d;
loc_81ee: // 01ed:631e
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_81f6() // 01ed:6326
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8202;
    sub_ca53();
loc_8202: // 01ed:6332
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_8240;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 47) != 0x0c)
        goto loc_8240;
    memoryASet(ds, 0x792a, 0x00);
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8238;
    al = 0x03;
    goto loc_823a;
loc_8238: // 01ed:6368
    al = 0x0d;
loc_823a: // 01ed:636a
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8240: // 01ed:6370
    bp = pop();
    sp += 2;
}
void sub_8242() // 01ed:6372
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_824e;
    sub_ca53();
loc_824e: // 01ed:637e
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_828c;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 48) != 0x0c)
        goto loc_828c;
    memoryASet(ds, 0x792a, 0x00);
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8284;
    al = 0x03;
    goto loc_8286;
loc_8284: // 01ed:63b4
    al = 0x0d;
loc_8286: // 01ed:63b6
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_828c: // 01ed:63bc
    bp = pop();
    sp += 2;
}
void sub_828e() // 01ed:63be
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_829c;
    sub_ca53();
loc_829c: // 01ed:63cc
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_82d8;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_82d8;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_82be;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9790);
    goto loc_82c9;
loc_82be: // 01ed:63ee
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9742);
loc_82c9: // 01ed:63f9
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_82d8;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_82d8: // 01ed:6408
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_82dc() // 01ed:640c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_82ea;
    sub_ca53();
loc_82ea: // 01ed:641a
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_82fe;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10126);
    goto loc_8309;
loc_82fe: // 01ed:642e
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10094);
loc_8309: // 01ed:6439
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8318;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8318: // 01ed:6448
    if (memoryAGet(ds, 0x8551) < 0x0e)
        goto loc_8329;
    if (memoryAGet(ds, 0x8551) >= 0x12)
        goto loc_8329;
    sub_8053();
loc_8329: // 01ed:6459
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_832d() // 01ed:645d
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8339;
    sub_ca53();
loc_8339: // 01ed:6469
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8344;
    al = 0x0b;
    goto loc_8346;
loc_8344: // 01ed:6474
    al = 0x2c;
loc_8346: // 01ed:6476
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_834e() // 01ed:647e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_835c;
    sub_ca53();
loc_835c: // 01ed:648c
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8370;
    al = memoryAGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9982);
    goto loc_837b;
loc_8370: // 01ed:64a0
    al = memoryAGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9934);
loc_837b: // 01ed:64ab
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_838a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_838a: // 01ed:64ba
    sub_841e();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8391() // 01ed:64c1
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_839d;
    sub_ca53();
loc_839d: // 01ed:64cd
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_83a8;
    al = 0x0e;
    goto loc_83aa;
loc_83a8: // 01ed:64d8
    al = 0x21;
loc_83aa: // 01ed:64da
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_83b2() // 01ed:64e2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83be;
    sub_ca53();
loc_83be: // 01ed:64ee
    sub_84e1();
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856e, al);
    memoryASet(ds, 0x855c, memoryAGet(ds, 0x855c) - 1);
    bp = pop();
    sp += 2;
}
void sub_83cf() // 01ed:64ff
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83db;
    sub_ca53();
loc_83db: // 01ed:650b
    sub_84e1();
    al = memoryAGet(ds, 0x856e);
    al += 0x08;
    memoryASet(ds, 0x856e, al);
    memoryASet(ds, 0x855c, memoryAGet(ds, 0x855c) + 1);
    bp = pop();
    sp += 2;
}
void sub_83ec() // 01ed:651c
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83f8;
    sub_ca53();
loc_83f8: // 01ed:6528
    sub_84e1();
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) - 1);
    memoryASet(ds, 0x855e, memoryAGet(ds, 0x855e) - 1);
    bp = pop();
    sp += 2;
}
void sub_8405() // 01ed:6535
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8411;
    sub_ca53();
loc_8411: // 01ed:6541
    sub_84e1();
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) + 1);
    memoryASet(ds, 0x855e, memoryAGet(ds, 0x855e) + 1);
    bp = pop();
    sp += 2;
}
void sub_841e() // 01ed:654e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_842a;
    sub_ca53();
loc_842a: // 01ed:655a
    al = memoryAGet(ds, 0x7923);
    ah = 0x00;
    if (ax)
        goto loc_8455;
    if (memoryAGet(ds, 0x8244) & 0x10)
        goto loc_8441;
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_8455;
loc_8441: // 01ed:6571
    al = memoryAGet(ds, 0x7924);
    memoryASet(ds, 0x7922, al);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 15578);
    push(ax);
    sub_882e();
    sp++;
    sp++;
loc_8455: // 01ed:6585
    bp = pop();
    sp += 2;
}
void sub_8457() // 01ed:6587
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8463;
    sub_ca53();
loc_8463: // 01ed:6593
    al = memoryAGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_84a0;
    if (memoryAGet(ds, 0x7924) != 0x02)
        goto loc_84a0;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_84a0;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8485;
    al = 0x04;
    goto loc_8487;
loc_8485: // 01ed:65b5
    al = 0x09;
loc_8487: // 01ed:65b7
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    memoryASet(ds, 0x79b4, 0x34);
    al = 0x34;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_84a0: // 01ed:65d0
    bp = pop();
    sp += 2;
}
void sub_84a2() // 01ed:65d2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84ae;
    sub_ca53();
loc_84ae: // 01ed:65de
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    sp += 2;
}
void sub_84b5() // 01ed:65e5
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84c1;
    sub_ca53();
loc_84c1: // 01ed:65f1
    al = memoryAGet(ds, 0x8244);
    al &= 0x10;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    sp += 2;
}
void sub_84cb() // 01ed:65fb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84d7;
    sub_ca53();
loc_84d7: // 01ed:6607
    al = memoryAGet(ds, 0x8244);
    al &= 0x1d;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    sp += 2;
}
void sub_84e1() // 01ed:6611
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84ed;
    sub_ca53();
loc_84ed: // 01ed:661d
    al = memoryAGet(ds, 0x8244);
    al &= 0x0f;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    sp += 2;
}
void sub_84f7() // 01ed:6627
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8503;
    sub_ca53();
loc_8503: // 01ed:6633
    al = memoryAGet(ds, 0x856e);
    push(ax);
    sub_8ac4();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x79b8) == 0x00)
        goto loc_8516;
    sub_8ae4();
loc_8516: // 01ed:6646
    bp = pop();
    sp += 2;
}
void sub_8518() // 01ed:6648
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8526;
    sub_ca53();
loc_8526: // 01ed:6656
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_853a;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9694);
    goto loc_8545;
loc_853a: // 01ed:666a
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9646);
loc_8545: // 01ed:6675
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8554;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8554: // 01ed:6684
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 15626);
    push(ax);
    sub_8857();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8569() // 01ed:6699
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8575;
    sub_ca53();
loc_8575: // 01ed:66a5
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_858e;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_858e;
    push(ds);
    ax = 0x3c7a;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_858e: // 01ed:66be
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_85a6;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13758);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85a6: // 01ed:66d6
    bp = pop();
    sp += 2;
}
void sub_85a8() // 01ed:66d8
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_85b4;
    sub_ca53();
loc_85b4: // 01ed:66e4
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_85cd;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_85cd;
    push(ds);
    ax = 0x3caa;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_85cd: // 01ed:66fd
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_85e5;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13790);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85e5: // 01ed:6715
    bp = pop();
    sp += 2;
}
void sub_85e7() // 01ed:6717
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_85f3;
    sub_ca53();
loc_85f3: // 01ed:6723
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    sub_8bf6();
    if (memoryAGet(ds, 0x856c) != 0x5b)
        goto loc_8608;
    memoryASet(ds, 0xa1b1, 0x00);
loc_8608: // 01ed:6738
    bp = pop();
    sp += 2;
}
void sub_860a() // 01ed:673a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8616;
    sub_ca53();
loc_8616: // 01ed:6746
    bp = pop();
    sp += 2;
}
void sub_8618() // 01ed:6748
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8624;
    sub_ca53();
loc_8624: // 01ed:6754
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_862f;
    al = 0x08;
    goto loc_8631;
loc_862f: // 01ed:675f
    al = 0x2f;
loc_8631: // 01ed:6761
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x18;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_8657;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13822);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8657: // 01ed:6787
    bp = pop();
    sp += 2;
}
void sub_8659() // 01ed:6789
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8665;
    sub_ca53();
loc_8665: // 01ed:6795
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8670;
    al = 0x08;
    goto loc_8672;
loc_8670: // 01ed:67a0
    al = 0x2f;
loc_8672: // 01ed:67a2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x19;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_8698;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13854);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8698: // 01ed:67c8
    bp = pop();
    sp += 2;
}
void sub_869a() // 01ed:67ca
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_86a6;
    sub_ca53();
loc_86a6: // 01ed:67d6
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_86b0;
    sub_86b2();
loc_86b0: // 01ed:67e0
    bp = pop();
    sp += 2;
}
void sub_86b2() // 01ed:67e2
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_86be;
    sub_ca53();
loc_86be: // 01ed:67ee
    push(ds);
    ax = 0x363e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_86cb() // 01ed:67fb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_86d7;
    sub_ca53();
loc_86d7: // 01ed:6807
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_86e1;
    sub_86e3();
loc_86e1: // 01ed:6811
    bp = pop();
    sp += 2;
}
void sub_86e3() // 01ed:6813
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_86ef;
    sub_ca53();
loc_86ef: // 01ed:681f
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ds);
    ax = 0x365e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_8702() // 01ed:6832
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_870e;
    sub_ca53();
loc_870e: // 01ed:683e
    push(ds);
    ax = 0x363e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_871b() // 01ed:684b
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8727;
    sub_ca53();
loc_8727: // 01ed:6857
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ds);
    ax = 0x365e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    sp += 2;
}
void sub_873a() // 01ed:686a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8746;
    sub_ca53();
loc_8746: // 01ed:6876
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    sp += 2;
}
void sub_8760() // 01ed:6890
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_876c;
    sub_ca53();
loc_876c: // 01ed:689c
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_8789;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13822);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
loc_8789: // 01ed:68b9
    bp = pop();
    sp += 2;
}
void sub_878b() // 01ed:68bb
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8797;
    sub_ca53();
loc_8797: // 01ed:68c7
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_87b4;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13854);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
loc_87b4: // 01ed:68e4
    bp = pop();
    sp += 2;
}
void sub_87b6() // 01ed:68e6
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_87c2;
    sub_ca53();
loc_87c2: // 01ed:68f2
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_87cc;
    sub_87ce();
loc_87cc: // 01ed:68fc
    bp = pop();
    sp += 2;
}
void sub_87ce() // 01ed:68fe
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_87da;
    sub_ca53();
loc_87da: // 01ed:690a
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13950);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    sp += 2;
}
void sub_87f2() // 01ed:6922
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_87fe;
    sub_ca53();
loc_87fe: // 01ed:692e
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_8808;
    sub_880a();
loc_8808: // 01ed:6938
    bp = pop();
    sp += 2;
}
void sub_880a() // 01ed:693a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8816;
    sub_ca53();
loc_8816: // 01ed:6946
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13982);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    sp += 2;
}
void sub_882e() // 01ed:695e
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_883a;
    sub_ca53();
loc_883a: // 01ed:696a
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8855;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0xa1a7, al);
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8855: // 01ed:6985
    bp = pop();
    sp += 2;
}
void sub_8857() // 01ed:6987
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8863;
    sub_ca53();
loc_8863: // 01ed:6993
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8878;
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8878: // 01ed:69a8
    bp = pop();
    sp += 2;
}
void sub_887a() // 01ed:69aa
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_888a;
    sub_ca53();
loc_888a: // 01ed:69ba
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12000);
    dx = memoryAGet16(ds, bx + 11998);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    cl = 0x00;
loc_88a5: // 01ed:69d5
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    cl++;
    ah = 0x00;
    if (!ax)
        goto loc_88a5;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8910;
    cl = 0x00;
loc_88d6: // 01ed:6a06
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    cl++;
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8905;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_88d6;
loc_8905: // 01ed:6a35
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (ax)
        goto loc_8954;
    goto loc_891d;
loc_8910: // 01ed:6a40
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx + 1);
    if (al != memoryAGet(ds, 0x856f))
        goto loc_88a5;
loc_891d: // 01ed:6a4d
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(ds, 0x856f);
    memoryASet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, si);
    es = pop();
    memoryASet(es, bx, al);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet(es, bx, 0x01);
loc_8954: // 01ed:6a84
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8959() // 01ed:6a89
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8969;
    sub_ca53();
loc_8969: // 01ed:6a99
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x8566, al);
    if (al)
        goto loc_8976;
    goto loc_8a80;
loc_8976: // 01ed:6aa6
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_898a;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10062);
    goto loc_8995;
loc_898a: // 01ed:6aba
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10030);
loc_8995: // 01ed:6ac5
    memoryASet(ss, bp - 10, al);
    if (memoryAGet(ss, bp - 10) == 0x00)
        goto loc_89a4;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_89a4: // 01ed:6ad4
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12888);
    dx = memoryAGet16(ds, bx + 12886);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    memoryASet(ss, bp - 9, 0x00);
loc_89c1: // 01ed:6af1
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    ah = 0x00;
    if (!ax)
        goto loc_89c1;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8a38;
    memoryASet(ss, bp - 9, 0x00);
loc_89f6: // 01ed:6b26
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8a27;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_89f6;
loc_8a27: // 01ed:6b57
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (!ax)
        goto loc_8a48;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8a80;
    goto loc_8a80;
loc_8a38: // 01ed:6b68
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx + 1);
    if (al == memoryAGet(ds, 0x8570))
        goto loc_8a48;
    goto loc_89c1;
loc_8a48: // 01ed:6b78
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(ds, 0x8570);
    memoryASet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, si);
    es = pop();
    memoryASet(es, bx + 48, al);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8); es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet(es, bx, 0x01);
loc_8a80: // 01ed:6bb0
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8a85() // 01ed:6bb5
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8a91;
    sub_ca53();
loc_8a91: // 01ed:6bc1
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x7921, al);
    bp = pop();
    sp += 2;
}
void sub_8aa4() // 01ed:6bd4
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ab0;
    sub_ca53();
loc_8ab0: // 01ed:6be0
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    memoryASet(ds, 0x8551, al);
    bp = pop();
    sp += 2;
}
void sub_8ac4() // 01ed:6bf4
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ad0;
    sub_ca53();
loc_8ad0: // 01ed:6c00
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 96);
    memoryASet(ds, 0x79b8, al);
    bp = pop();
    sp += 2;
}
void sub_8ae4() // 01ed:6c14
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8af0;
    sub_ca53();
loc_8af0: // 01ed:6c20
    memoryASet(ds, 0x2810, 0x0f);
    sub_8b65();
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8); es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    memoryASet(es, bx + 96, 0x00);
    if (memoryAGet(ds, 0x79b8) == 0x01)
        goto loc_8b63;
    if (memoryAGet(ds, 0x79b8) == 0x23)
        goto loc_8b63;
    memoryASet(ds, 0xa0cf, memoryAGet(ds, 0xa0cf) - 1);
    al = memoryAGet(ds, 0xa0cf);
    ah = 0x00;
    if (ax)
        goto loc_8b50;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8b2e;
    al = 0x0b;
    goto loc_8b30;
loc_8b2e: // 01ed:6c5e
    al = 0x2c;
loc_8b30: // 01ed:6c60
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8572);
    memoryASet(ds, 0x856f, al);
    al = 0x59;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memoryASet(ds, 0xa1b1, 0x01);
    memoryASet(ds, 0x8550, 0xf2);
    goto loc_8b63;
loc_8b50: // 01ed:6c80
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8b5b;
    al = 0x0e;
    goto loc_8b5d;
loc_8b5b: // 01ed:6c8b
    al = 0x21;
loc_8b5d: // 01ed:6c8d
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8b63: // 01ed:6c93
    bp = pop();
    sp += 2;
}
void sub_8b65() // 01ed:6c95
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8b71;
    sub_ca53();
loc_8b71: // 01ed:6ca1
    memoryASet(ds, 0xa1a8, 0x02);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    cl = 0x04;
    ax = sar16(ax, cl);
    memoryASet16(ds, 0x9b9a, ax);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x9ba2, ax);
    if (!(memoryAGet(ds, 0x856e) & 0x01))
        goto loc_8bb0;
    ax = 0x0001;
    goto loc_8bb3;
loc_8bb0: // 01ed:6ce0
    ax = 0x0002;
loc_8bb3: // 01ed:6ce3
    bx = memoryAGet16(ds, 0x08e4); es = memoryAGet16(ds, 0x08e4 + 2);
    memoryASet16(es, bx + 30, ax);
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0x00fa) >= 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0x00fa);
    memoryASet16(ds, 0xa0d6, memoryAGet16(ds, 0xa0d6) + (0x0000 + flags.carry));
    if (memoryAGet(ds, 0x79b8) != 0x23)
        goto loc_8bd3;
    memoryASet(ds, 0x791a, memoryAGet(ds, 0x791a) + 1);
    goto loc_8bf4;
loc_8bd3: // 01ed:6d03
    if (memoryAGet(ds, 0x79b8) != 0x2f)
        goto loc_8be2;
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0x2616) >= 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0x2616);
    goto loc_8bef;
loc_8be2: // 01ed:6d12
    if (memoryAGet(ds, 0x79b8) != 0x30)
        goto loc_8bf4;
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0xc256) >= 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0xc256);
loc_8bef: // 01ed:6d1f
    memoryASet16(ds, 0xa0d6, memoryAGet16(ds, 0xa0d6) + (0x0000 + flags.carry));
loc_8bf4: // 01ed:6d24
    bp = pop();
    sp += 2;
}
void sub_8bf6() // 01ed:6d26
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c04;
    sub_ca53();
loc_8c04: // 01ed:6d34
    al = memoryAGet(ds, 0x856e);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x7921);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17302);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8c36;
    al = memoryAGet(ds, 0x7924);
    memoryASet(ds, 0x7922, al);
    al = memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x7923, al);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_8c36: // 01ed:6d66
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8c3a() // 01ed:6d6a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c46;
    sub_ca53();
loc_8c46: // 01ed:6d76
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_8c62;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    push(ax);
    sub_8857();
    sp++;
    sp++;
loc_8c62: // 01ed:6d92
    bp = pop();
    sp += 2;
}
void sub_8c64() // 01ed:6d94
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c70;
    sub_ca53();
loc_8c70: // 01ed:6da0
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_8cb3() // 01ed:6de3
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8cc0;
    sub_ca53();
loc_8cc0: // 01ed:6df0
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_8cde;
    sub_a7b5();
    si = ax;
    ax = memoryAGet16(ds, 0x689c);
    ax &= si;
    memoryASet16(ds, 0x689c, ax);
    push(memoryAGet16(ds, 0x689c));
    sub_a7ee();
    sp++;
    sp++;
loc_8cde: // 01ed:6e0e
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8ce1() // 01ed:6e11
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ced;
    sub_ca53();
loc_8ced: // 01ed:6e1d
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_8cfe;
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_8d00();
    sp++;
    sp++;
loc_8cfe: // 01ed:6e2e
    bp = pop();
    sp += 2;
}
void sub_8d00() // 01ed:6e30
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8d0c;
    sub_ca53();
loc_8d0c: // 01ed:6e3c
    if (memoryAGet16(ds, 0x689c) != 0x0004)
        goto loc_8d3c;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 10159);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 10158);
    ah = 0x00;
    push(ax);
    sub_a8d7();
    sp += 0x0004;
    goto loc_8fb5;
loc_8d3c: // 01ed:6e6c
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax--;
    bx = ax;
    if (bx <= 0x0014)
        goto loc_8d4c;
    goto loc_8fb5;
loc_8d4c: // 01ed:6e7c
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_8d53;
        case 2: goto loc_8d6a;
        case 4: goto loc_8d85;
        case 6: goto loc_8da3;
        case 8: goto loc_8dc1;
        case 10: goto loc_8ddf;
        case 12: goto loc_8dfd;
        case 14: goto loc_8e1b;
        case 16: goto loc_8e39;
        case 18: goto loc_8e50;
        case 20: goto loc_8e6e;
        case 22: goto loc_8e8f;
        case 24: goto loc_8ea9;
        case 26: goto loc_8ec7;
        case 28: goto loc_8ee4;
        case 30: goto loc_8f02;
        case 32: goto loc_8f1c;
        case 34: goto loc_8f3c;
        case 36: goto loc_8f5c;
        case 38: goto loc_8f76;
        default:
            stop("ind 01ed:6e7e");
    }
loc_8d53: // 01ed:6e83
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x03e8;
    goto loc_8fa6;
loc_8d6a: // 01ed:6e9a
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0xfff6;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0320;
    push(ax);
    ax = 0x0028;
    goto loc_8faa;
loc_8d85: // 01ed:6eb5
    ax = 0xffff;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0xffff;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x0190;
    goto loc_8faa;
loc_8da3: // 01ed:6ed3
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0xffff;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00dc;
    push(ax);
    ax = 0x005a;
    goto loc_8faa;
loc_8dc1: // 01ed:6ef1
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x03e8;
    push(ax);
    ax = 0x0019;
    goto loc_8faa;
loc_8ddf: // 01ed:6f0f
    ax = 0x0005;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x044c;
    push(ax);
    ax = 0x0014;
    goto loc_8faa;
loc_8dfd: // 01ed:6f2d
    ax = 0x0003;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    push(ax);
    ax = 0x000f;
    goto loc_8faa;
loc_8e1b: // 01ed:6f4b
    ax = 0x0005;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0xfffb;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00dc;
    push(ax);
    ax = 0x0028;
    goto loc_8faa;
loc_8e39: // 01ed:6f69
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0032;
    goto loc_8fa6;
loc_8e50: // 01ed:6f80
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x015d;
    push(ax);
    ax = 0x0032;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x000f;
    goto loc_8faa;
loc_8e6e: // 01ed:6f9e
    ax = 0xfffc;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0028;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8e8f: // 01ed:6fbf
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01a4;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    goto loc_8fa6;
loc_8ea9: // 01ed:6fd9
    ax = 0x000f;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x015d;
    push(ax);
    ax = 0x0032;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0014;
    goto loc_8faa;
loc_8ec7: // 01ed:6ff7
    ax = 0;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0032;
    goto loc_8faa;
loc_8ee4: // 01ed:7014
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x012c;
    push(ax);
    ax = 0x0190;
    goto loc_8faa;
loc_8f02: // 01ed:7032
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01a4;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    goto loc_8fa6;
loc_8f1c: // 01ed:704c
    ax = 0xfffc;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0028;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8f3c: // 01ed:706c
    ax = 0xfffc;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x001e;
    push(ax);
    ax = 0x0050;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8f5c: // 01ed:708c
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x012c;
    push(ax);
    ax = 0x0320;
    goto loc_8faa;
loc_8f76: // 01ed:70a6
    ax = 0;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0032;
    goto loc_8faa;
    // gap 20 bytes
loc_8fa6: // 01ed:70d6
    push(ax);
    ax = 0x001e;
loc_8faa: // 01ed:70da
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b358();
    sp += 0x0010;
loc_8fb5: // 01ed:70e5
    bp = pop();
    sp += 2;
}
void sub_8fe1() // 01ed:7111
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8fed;
    sub_ca53();
loc_8fed: // 01ed:711d
    bp = pop();
    sp += 2;
}
void sub_8ff0() // 01ed:7120
{
    sp -= 2;
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    interrupt(0x10);
    bp = pop();
    sp += 2;
}
void sub_9105() // 01ed:7235
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    memoryASet(ss, bp - 1, 0x00);
    si = 0;
    memoryASet16(ss, bp - 6, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_919f;
loc_9120: // 01ed:7250
    if ((short)memoryAGet16(ss, bp + 14) < (short)0x0000)
        goto loc_913d;
    if ((short)memoryAGet16(ss, bp + 14) > (short)0x0000)
        goto loc_912f;
    if (memoryAGet16(ss, bp + 12) <= 0xfa00)
        goto loc_913d;
loc_912f: // 01ed:725f
    di = 0xfa00;
    flags.carry = memoryAGet16(ss, bp + 12) < 0xfa00;
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) - 0xfa00);
    memoryASet16(ss, bp + 14, memoryAGet16(ss, bp + 14) - 0x0000 - flags.carry);
    goto loc_914a;
loc_913d: // 01ed:726d
    di = memoryAGet16(ss, bp + 12);
    memoryASet16(ss, bp + 12, 0x0000);
    memoryASet16(ss, bp + 14, 0x0000);
loc_914a: // 01ed:727a
    push(di);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    switch (memoryAGet16(ss, bp + 4))
    {
        case 0xa3ae: sub_c27e(); break;
        default:
            stop("ind 01ed:7284");
    }
    sp += 0x0008;
    si = ax;
    if (si == di)
        goto loc_9165;
    ax = 0x0001;
    goto loc_9167;
loc_9165: // 01ed:7295
    ax = 0;
loc_9167: // 01ed:7297
    memoryASet(ss, bp - 1, al);
    flags.carry = (memoryAGet16(ss, bp - 6) + si) >= 0x10000;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + si);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + (0x0000 + flags.carry));
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 10, ax);
    memoryASet16(ss, bp - 8, 0x0000);
    flags.carry = (memoryAGet16(ss, bp - 10) + si) >= 0x10000;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + si);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + (0x0000 + flags.carry));
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp + 8, ax);
    memoryASet16(ss, bp - 10, 0x0000);
    ax = memoryAGet16(ss, bp - 10);
    ax |= memoryAGet16(ss, bp - 8);
    if (!ax)
        goto loc_919f;
    flags.carry = (memoryAGet16(ss, bp + 8) + 0x0000) >= 0x10000;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 0x0000);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + (0x1000 + flags.carry));
loc_919f: // 01ed:72cf
    ax = memoryAGet16(ss, bp + 12);
    ax |= memoryAGet16(ss, bp + 14);
    if (!ax)
        goto loc_91b3;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_91b3;
    goto loc_9120;
loc_91b3: // 01ed:72e3
    dx = memoryAGet16(ss, bp - 4);
    ax = memoryAGet16(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_91bf() // 01ed:72ef
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0xa1b8, ax);
    push(memoryAGet16(ss, bp + 4));
    sub_bfb9();
    sp++;
    sp++;
    memoryASet(ds, 0x4ce6, 0x01);
    bp = pop();
    sp += 2;
}
void sub_91d7() // 01ed:7307
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xa1b4, dx);
    memoryASet16(ds, 0xa1b6, ax);
    bp = pop();
    sp += 2;
}
void sub_91e9() // 01ed:7319
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(memoryAGet16(ss, bp + 4));
    sub_b75e();
    sp++;
    sp++;
    si = ax;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_923f() // 01ed:736f
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    memoryASet(ss, bp - 1, 0x00);
    al = memoryAGet(ds, 0x4ce6);
    ah = 0x00;
    if (ax)
        goto loc_925c;
    memoryASet16(ds, 0xa1b8, 0x74d4);
loc_925c: // 01ed:738c
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 4) == 0x7a)
        goto loc_92b9;
loc_9270: // 01ed:73a0
    push(memoryAGet16(ss, bp + 6));
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    push(ax);
    sub_93a5();
    sp += 0x0004;
    si = ax;
    if (!ax)
        goto loc_92ab;
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    indirectCall(cs, memoryAGet16(ds, 0xa1b8)); // 01ed:73d5;
    sp++;
    sp++;
loc_92ab: // 01ed:73db
    if (!si)
        goto loc_92b9;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_9270;
loc_92b9: // 01ed:73e9
    if (memoryAGet(ss, bp - 1) > 0x0a)
        goto loc_9326;
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    memoryASet(ds, 0x4ce7, al);
loc_92d3: // 01ed:7403
    ax = 0x0180;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax |= 0x8004;
    push(ax);
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    sub_c0ec();
    sp += 0x0008;
    si = ax;
    if ((short)ax >= 0)
        goto loc_9318;
    ax = di;
    dx = 0x000a;
    imul16(dx);
    bx = memoryAGet16(ds, 0xa1b4); es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    indirectCall(cs, memoryAGet16(ds, 0xa1b8)); // 01ed:7442;
    sp++;
    sp++;
loc_9318: // 01ed:7448
    if ((short)si >= 0)
        goto loc_9326;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_92d3;
loc_9326: // 01ed:7456
    ax = si;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_932e() // 01ed:745e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = 0xa3ae;
    push(ax);
    sub_9105();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    ax = memoryAGet16(ss, bp - 4);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_93a5() // 01ed:74d5
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = 0x0180;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax |= 0x8004;
    push(ax);
    push(ds);
    ax = 0x4ce8;
    push(ax);
    sub_c0ec();
    sp += 0x0008;
    si = ax;
    if ((short)si <= 0)
        goto loc_93fc;
    ax = 0;
    push(ax);
    dx = 0x0004;
    push(ax);
    push(dx);
    push(ds);
    ax = 0xa1ba;
    push(ax);
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    al = memoryAGet(ds, 0xa1ba);
    ah = 0x00;
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    ax -= dx;
    si = ax;
    if (memoryAGet(ds, 0xa1ba) == 0x7a)
        goto loc_93fa;
    if (memoryAGet(ss, bp + 4) != 0x7a)
        goto loc_93fc;
loc_93fa: // 01ed:752a
    si = 0;
loc_93fc: // 01ed:752c
    ax = si;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_9402() // 01ed:7532
{
    push(flagAsReg());
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    flags.direction = 0;
    di = 0x4cf2;
    cx = 0x0020;
    ax = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    ax = 0x0000;
    sub_96a9();
    ax = 0x0001;
    sub_96a9();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    flagsFromReg(pop());
}
void sub_9433() // 01ed:7563
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    push(es);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    ah = 0;
    si = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    sub_944b();
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    bp = pop();
    sp += 2;
}
void sub_944b() // 01ed:757b
{
    push(ds);
    dx = 0x1228;
    ds = dx;
    if (al < 0x10)
        goto loc_945b;
    dx = 0x7676;
    goto loc_94fa;
loc_945b: // 01ed:758b
    ax += ax;
    ax += ax;
    bx = 0x1228;
    ds = bx;
    bx = 0x4cf2;
    bx += ax;
    memoryASet16(ds, bx, si);
    ax = es;
    memoryASet16(ds, bx + 2, ax);
    ds = pop();
    return;
    // gap 136 bytes
loc_94fa: // 01ed:762a
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502: // 01ed:7632
    goto loc_9502;
}
void sub_9472() // 01ed:75a2
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(ds);
    push(es);
    push(si);
    push(di);
    dx = 0x1228;
    ds = dx;
    ah = 0;
    if (ax < 0x0010)
        goto loc_948f;
    dx = 0x76c8;
    goto loc_94fa;
    // gap 1 bytes
loc_948f: // 01ed:75bf
    ax += ax;
    ax += ax;
    bx = 0x4cf2;
    bx += ax;
    si = memoryAGet16(ds, bx); es = memoryAGet16(ds, bx + 2);
    ax = es;
    ax |= si;
    if (ax)
        goto loc_94a5;
    dx = 0x7634;
    goto loc_94fa;
loc_94a5: // 01ed:75d5
    dx = 0x0000;
loc_94a8: // 01ed:75d8
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94bb;
    push(dx);
    push(si);
    sub_960c();
    si = pop();
    dx = pop();
    dl |= ch;
    goto loc_94a8;
loc_94bb: // 01ed:75eb
    if (al == 0xff)
        goto loc_94f1;
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x4d42);
loc_94c9: // 01ed:75f9
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    dh = al;
loc_94d3: // 01ed:7603
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    al &= 0x7f;
    al = memoryAGet(ds, bx+al);
    if (!al)
        goto loc_94d3;
    dl |= dh;
    goto loc_94d3;
loc_94e6: // 01ed:7616
    if (al == 0xfe)
        goto loc_94f0;
    if (al != 0xff)
        goto loc_94c9;
    goto loc_94f1;
loc_94f0: // 01ed:7620
    ds = pop();
loc_94f1: // 01ed:7621
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    al = dl;
    ah = 0;
    sp += 2;
    return;
loc_94fa: // 01ed:762a
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502: // 01ed:7632
    goto loc_9502;
}
void sub_960c() // 01ed:773c
{
    push(ds);
    bx = 0x1228;
    ds = bx;
    push(ax);
    sub_9731();
    bx = pop();
    ch = 0;
    if (ax == 0xffff)
        goto loc_9665;
    bx &= 0x0001;
    if (!bx)
        goto loc_9667;
    if (ah >= memoryAGet(ds, 0x4d3b))
        goto loc_962e;
    ch |= 0x04;
    goto loc_9637;
loc_962e: // 01ed:775e
    if (ah < memoryAGet(ds, 0x4d3d))
        goto loc_9637;
    ch |= 0x08;
loc_9637: // 01ed:7767
    if (al >= memoryAGet(ds, 0x4d3a))
        goto loc_9642;
    ch |= 0x01;
    goto loc_964b;
loc_9642: // 01ed:7772
    if (al < memoryAGet(ds, 0x4d3c))
        goto loc_964b;
    ch |= 0x02;
loc_964b: // 01ed:777b
    dx = 0x0201;
    al = in8(dx);
    al = ~al;
    if (!(al & 0x40))
        goto loc_9658;
    ch |= 0x10;
loc_9658: // 01ed:7788
    if (!(al & 0x80))
        goto loc_965f;
    ch |= 0x20;
loc_965f: // 01ed:778f
    memoryASet(ds, 0x4d35, ch);
    goto loc_9665;
loc_9665: // 01ed:7795
    ds = pop();
    return;
loc_9667: // 01ed:7797
    if (ah >= memoryAGet(ds, 0x4d37))
        goto loc_9672;
    ch |= 0x04;
    goto loc_967b;
loc_9672: // 01ed:77a2
    if (ah < memoryAGet(ds, 0x4d39))
        goto loc_967b;
    ch |= 0x08;
loc_967b: // 01ed:77ab
    if (al >= memoryAGet(ds, 0x4d36))
        goto loc_9686;
    ch |= 0x01;
    goto loc_968f;
loc_9686: // 01ed:77b6
    if (al < memoryAGet(ds, 0x4d38))
        goto loc_968f;
    ch |= 0x02;
loc_968f: // 01ed:77bf
    dx = 0x0201;
    al = in8(dx);
    al = ~al;
    if (!(al & 0x10))
        goto loc_969c;
    ch |= 0x10;
loc_969c: // 01ed:77cc
    if (!(al & 0x20))
        goto loc_96a3;
    ch |= 0x20;
loc_96a3: // 01ed:77d3
    memoryASet(ds, 0x4d34, ch);
    goto loc_9665;
}
void sub_96a9() // 01ed:77d9
{
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = 0x4dca;
    if (!ax)
        goto loc_96b9;
    bx = 0x4dcb;
loc_96b9: // 01ed:77e9
    cl = 0x01;
    memoryASet(ds, bx, cl);
    bx = ax;
    push(ax);
    push(bx);
    sub_9731();
    bx = pop();
    cx = pop();
    if (ax == 0xffff)
        goto loc_971a;
    if (ah < 0x02)
        goto loc_970e;
    if (al < 0x02)
        goto loc_970e;
    cx = ax;
    al >>= 1;
    ah >>= 1;
    dx = ax;
    cx += cx;
    cx -= dx;
    ax = 0x1228;
    ds = ax;
    bx &= 0x0001;
    if (!bx)
        goto loc_96fc;
    memoryASet(ds, 0x4d3a, dl);
    memoryASet(ds, 0x4d3b, dh);
    memoryASet(ds, 0x4d3c, cl);
    memoryASet(ds, 0x4d3d, ch);
    goto loc_970c;
loc_96fc: // 01ed:782c
    memoryASet(ds, 0x4d36, dl);
    memoryASet(ds, 0x4d37, dh);
    memoryASet(ds, 0x4d38, cl);
    memoryASet(ds, 0x4d39, ch);
loc_970c: // 01ed:783c
    ds = pop();
    return;
loc_970e: // 01ed:783e
    push(cx);
    cx = 0x0000;
loc_9712: // 01ed:7842
    if (--cx)
        goto loc_9712;
    cx = pop();
    ax = 0xffff;
    goto loc_971c;
loc_971a: // 01ed:784a
    al = 0;
loc_971c: // 01ed:784c
    bx = 0x4dca;
    if (!cx)
        goto loc_9726;
    bx = 0x4dcb;
loc_9726: // 01ed:7856
    memoryASet(ds, bx, al);
    goto loc_970c;
}
void sub_9731() // 01ed:7861
{
    push(flagAsReg());
    flags.interrupts = 0;
    push(ds);
    bx = 0x1228;
    ds = bx;
    al &= 0x01;
    if (!al)
        goto loc_9751;
    bx = 0x0408;
    al = memoryAGet(ds, 0x4dcb);
    al--;
    if (!al)
        goto loc_9765;
    al++;
    if (!al)
        goto loc_974e;
    goto loc_97fe;
loc_974e: // 01ed:787e
    goto loc_9837;
loc_9751: // 01ed:7881
    bx = 0x0102;
    al = memoryAGet(ds, 0x4dca);
    al--;
    if (!al)
        goto loc_9765;
    al++;
    if (!al)
        goto loc_9762;
    goto loc_97fe;
loc_9762: // 01ed:7892
    goto loc_9823;
loc_9765: // 01ed:7895
    dx = 0x0201;
    cx = 0;
loc_976a: // 01ed:789a
    al = in8(dx);
    if (--cx && bl & al)
        goto loc_976a;
    if (cx==0)
        goto loc_9775;
    if (--cx && bh & al)
        goto loc_976a;
loc_9775: // 01ed:78a5
    if (cx==0)
        goto loc_9779;
    goto loc_977c;
loc_9779: // 01ed:78a9
    goto loc_97fe;
loc_977c: // 01ed:78ac
    dx = 0x0201;
    out8(dx, al);
    al = in8(dx);
    if (bh & al)
        goto loc_97aa;
    if (bl & al)
        goto loc_97aa;
    al = 0x06;
    out8(0x43, al);
    push(cx);
    cx = 0x0064;
loc_9791: // 01ed:78c1
    if (--cx)
        goto loc_9791;
    cx = pop();
loc_9794: // 01ed:78c4
    al = in8(0x40);
    ah = al;
    al = in8(0x40);
    ah &= 0x10;
    if (!ah)
        goto loc_9794;
loc_979f: // 01ed:78cf
    al = in8(0x40);
    ah = al;
    al = in8(0x40);
    ah &= 0x10;
    if (ah)
        goto loc_979f;
loc_97aa: // 01ed:78da
    cx = 0;
    memoryASet16(ds, 0x4d32, cx);
    cx = 0x03e8;
loc_97b3: // 01ed:78e3
    al = in8(0x40);
    ah = al;
    al = in8(0x40);
    ah &= 0x10;
    if (!ah)
        goto loc_97b3;
    memoryASet16(ds, 0x4d32, memoryAGet16(ds, 0x4d32) + 1);
    al = in8(dx);
    if (!bl)
        goto loc_97cf;
    if (!(bl & al))
        goto loc_97f0;
    if (!bh)
        goto loc_97d3;
loc_97cf: // 01ed:78ff
    if (!(bh & al))
        goto loc_97e2;
loc_97d3: // 01ed:7903
    al = in8(0x40);
    ah = al;
    al = in8(0x40);
    if (ah & 0x10)
        goto loc_97d3;
    if (--cx)
        goto loc_97b3;
    goto loc_97fe;
loc_97e2: // 01ed:7912
    ax = memoryAGet16(ds, 0x4d32);
    memoryASet16(ds, 0x4dc6, ax);
    bh = 0;
    if (!bl)
        goto loc_9803;
    goto loc_97d3;
loc_97f0: // 01ed:7920
    ax = memoryAGet16(ds, 0x4d32);
    memoryASet16(ds, 0x4dc8, ax);
    bl = 0;
    if (!bh)
        goto loc_9803;
    goto loc_97d3;
loc_97fe: // 01ed:792e
    ax = 0xffff;
    goto loc_9820;
loc_9803: // 01ed:7933
    dx = memoryAGet16(ds, 0x4dc6);
    if ((short)dx >= 0)
        goto loc_980d;
    dx = 0;
loc_980d: // 01ed:793d
    cl = 0x01;
    dx >>= cl;
    ax = memoryAGet16(ds, 0x4dc8);
    if ((short)ax >= 0)
        goto loc_981a;
    ax = 0;
loc_981a: // 01ed:794a
    cl = 0x01;
    ax >>= cl;
    ah = dl;
loc_9820: // 01ed:7950
    ds = pop();
    flagsFromReg(pop());
    return;
loc_9823: // 01ed:7953
    dx = 0x0201;
    al = in8(dx);
    al &= 0x03;
    if (al)
        goto loc_97fe;
    al = 0x01;
    memoryASet(ds, 0x4dca, al);
    ax = 0x0000;
    goto loc_9847;
loc_9835: // 01ed:7965
    goto loc_97fe;
loc_9837: // 01ed:7967
    dx = 0x0201;
    al = in8(dx);
    al &= 0x0c;
    if (al)
        goto loc_9835;
    al = 0x01;
    memoryASet(ds, 0x4dcb, al);
    ax = 0x0001;
loc_9847: // 01ed:7977
    push(bx);
    push(ax);
    ax = 0xffff;
    flags.zero = ax == 0xffff;
    ax = pop();
    bx = pop();
    if (flags.zero)
        goto loc_9835;
    push(bx);
    sub_9731();
    bx = pop();
    goto loc_9820;
}
void sub_985a() // 01ed:798a
{
    push(si);
    push(di);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    flags.direction = 0;
    di = memoryAGet16(ds, 0x4d42);
    cx = 0x0040;
    ax = 0x0000;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    es = pop();
    sub_99d1();
    ax = memoryAGet16(ds, 0x4dc4);
    if (ax)
        goto loc_98b2;
    ax++;
    memoryASet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    al = 0x09;
    ah = 0x35;
    interrupt(0x21);
    dx = es;
    ax = 0x01ed;
    es = ax;
    memoryASet16(ds, 0x4d3e, bx);
    memoryASet16(es, 0x7a6d, bx);
    memoryASet16(ds, 0x4d40, dx);
    memoryASet16(es, 0x7a6f, dx);
    dx = 0x79e6;
    bx = 0x01ed;
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
loc_98b2: // 01ed:79e2
    ds = pop();
    di = pop();
    si = pop();
}
void sub_9947() // 01ed:7a77
{
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4dc4);
    if (!ax)
        goto loc_9980;
    ax = 0;
    memoryASet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    dx = memoryAGet16(ds, 0x4d3e);
    bx = memoryAGet16(ds, 0x4d40);
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
    sub_99d1();
loc_9972: // 01ed:7aa2
    ah = 0x0b;
    interrupt(0x21);
    if (!al)
        goto loc_9980;
    ah = 0x07;
    interrupt(0x21);
    goto loc_9972;
loc_9980: // 01ed:7ab0
    ds = pop();
    di = pop();
    si = pop();
}
void sub_9984() // 01ed:7ab4
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryAGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    sp += 2;
}
void sub_998b() // 01ed:7abb +returnZero
{
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryAGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    flags.zero = !ax;
}
void sub_99d1() // 01ed:7b01
{
    push(ds);
    push(ax);
    push(bx);
    ax = 0x0040;
    ds = ax;
    bx = 0x0080;
    ax = memoryAGet16(ds, bx);
    bx = 0x001a;
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, ax);
    bx = pop();
    ax = pop();
    ds = pop();
}
void sub_9a1a() // 01ed:7b4a
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cbd9(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9a2a() // 01ed:7b5a
{
    sp -= 2;
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    si = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 14);
    cx = memoryAGet16(ss, bp + 12);
    bp = pop();
    push(cs); cs = 0x0e15; sub_e150(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9a63() // 01ed:7b93
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 8);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cc41(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9a77() // 01ed:7ba7
{
    push(cs); cs = 0x0ca6; sub_cc5f(); assert(cs == 0x01ed);
}
void sub_9a7d() // 01ed:7bad
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cc7b(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9a8d() // 01ed:7bbd
{
    sp -= 2;
    push(bp);
    bp = sp;
    cl = memoryAGet(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cc92(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9a9a() // 01ed:7bca
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cd11(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9aa7() // 01ed:7bd7
{
    push(cs); cs = 0x0ca6; sub_cd2e(); assert(cs == 0x01ed);
}
void sub_9aad() // 01ed:7bdd
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_cdb1(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9aca() // 01ed:7bfa +far +returnZero +stackDrop2
{
    sub_998b();
    cs = pop();
}
void sub_9bae() // 01ed:7cde
{
    al = memoryAGet(ds, 0x54d4);
    ah = 0;
    if (!al)
        goto loc_9bba;
    goto loc_9c81;
loc_9bba: // 01ed:7cea
    sub_9e80();
    memoryASet16(ds, 0x54d6, ax);
    cx = 0x0006;
loc_9bc3: // 01ed:7cf3
    push(cx);
    ax = 0x0000;
    bx = cx;
    bx--;
    sub_9d32();
    cx = pop();
    if (--cx)
        goto loc_9bc3;
    bx = 0x54f6;
    cx = 0x0010;
    ax = 0;
loc_9bd8: // 01ed:7d08
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9bd8;
    bx = 0x5516;
    cx = 0x0010;
    ax = 0xffff;
loc_9be8: // 01ed:7d18
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9be8;
    cx = 0x0012;
    ax = memoryAGet16(ds, 0x54d6);
    if (!ax)
        goto loc_9c22;
    if (ax >= 0xf800)
        goto loc_9c22;
    if (ax < 0x0951)
        goto loc_9c22;
    cx = ax;
    cx >>= 1;
    cx >>= 1;
    ax = 0xffff;
    dx = 0;
    div16(cx);
    ax += ax;
    cx = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += cx;
    ax >>= 1;
    ax >>= 1;
    cx = ax;
loc_9c22: // 01ed:7d52
    ax = cx;
    bx = 0x0000;
    dx = 0x01ed;
    cx = 0x7e7a;
    sub_9d32();
    ax = 0x0032;
    bx = 0x0001;
    dx = 0x01ed;
    cx = 0x7e80;
    sub_9d32();
    push(es);
    ah = 0x35;
    al = 0x08;
    interrupt(0x21);
    memoryASet16(ds, 0x54d0, bx);
    bx = es;
    memoryASet16(ds, 0x54d2, bx);
    es = pop();
    ax = 0x0001;
    memoryASet(ds, 0x54d4, al);
    push(flagAsReg());
    flags.interrupts = 0;
    push(ds);
    ax = 0x01ed;
    ds = ax;
    dx = 0x7c02;
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    flagsFromReg(pop());
    sub_9c82();
    push(es);
    ax = 0x350f;
    interrupt(0x21);
    memoryASet16(ds, 0x54d8, bx);
    bx = es;
    memoryASet16(ds, 0x54da, bx);
    es = pop();
    ax = 0x0001;
loc_9c81: // 01ed:7db1
    return;
}
void sub_9c82() // 01ed:7db2
{
    ax = 0x0951;
    sub_9e6a();
}
void sub_9c89() // 01ed:7db9
{
    al = memoryAGet(ds, 0x54d4);
    ah = 0;
    if (!al)
        goto loc_9cb7;
    push(ds);
    dx = memoryAGet16(ds, 0x54d8); ds = memoryAGet16(ds, 0x54d8 + 2);
    ah = 0x25;
    al = 0x0f;
    ds = pop();
    ax = memoryAGet16(ds, 0x54d6);
    sub_9e6a();
    push(ds);
    dx = memoryAGet16(ds, 0x54d0); ds = memoryAGet16(ds, 0x54d0 + 2);
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    ax = 0x0000;
    memoryASet(ds, 0x54d4, al);
    ax = 0x0001;
loc_9cb7: // 01ed:7de7
    return;
}
void sub_9cc9() // 01ed:7df9
{
    if ((short)bx < 0)
        goto loc_9ce5;
    if ((short)bx >= (short)0x0004)
        goto loc_9ce5;
    bx += 0x0002;
    if ((short)ax < 0)
        goto loc_9ce5;
    if ((short)ax >= (short)0x01f4)
        goto loc_9ce5;
    sub_9d32();
    ax = 0x0001;
    return;
loc_9ce5: // 01ed:7e15
    ax = 0;
}
void sub_9ce8() // 01ed:7e18
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    bx = ax;
    if ((short)bx < 0)
        goto loc_9d0a;
    if ((short)bx >= (short)0x0004)
        goto loc_9d0a;
    bx += 0x0002;
    ax = 0;
    cx = ax;
    dx = ax;
    sub_9d32();
    ax = 0x0001;
    sp += 2;
    return;
loc_9d0a: // 01ed:7e3a
    ax = 0;
    sp += 2;
}
void sub_9cef() // 01ed:7e1f
{
    bx = ax;
    if ((short)bx < 0)
        goto loc_9d0a;
    if ((short)bx >= (short)0x0004)
        goto loc_9d0a;
    bx += 0x0002;
    ax = 0;
    cx = ax;
    dx = ax;
    sub_9d32();
    ax = 0x0001;
    return;
loc_9d0a: // 01ed:7e3a
    ax = 0;
}
void sub_9d32() // 01ed:7e62
{
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x549c;
    memoryASet16(ds, bx, ax);
    ax = 0;
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ds, bx + 6, cx);
    memoryASet16(ds, bx + 4, dx);
}
void sub_9e60() // 01ed:7f90
{
    sub_9e63();
    sub_9e66();
    sub_9e69();
}
void sub_9e63() // 01ed:7f93
{
    sub_9e66();
    sub_9e69();
}
void sub_9e66() // 01ed:7f96
{
    sub_9e69();
}
void sub_9e69() // 01ed:7f99
{
}
void sub_9e6a() // 01ed:7f9a
{
    push(ax);
    al = 0x36;
    out8(0x43, al);
    sub_9e60();
    ax = pop();
    out8(0x40, al);
    sub_9e60();
    al = ah;
    out8(0x40, al);
    sub_9e60();
}
void sub_9e80() // 01ed:7fb0
{
    push(bx);
    push(cx);
    cx = 0x0019;
    bx = 0;
    al = 0x06;
    out8(0x43, al);
    sub_9e60();
loc_9e8e: // 01ed:7fbe
    flags.interrupts = 0;
    al = in8(0x40);
    ah = al;
    sub_9e60();
    al = in8(0x40);
    flags.interrupts = 1;
    if (al < bh)
        goto loc_9e8e;
    if (al != bh)
        goto loc_9ea3;
    if (bl >= ah)
        goto loc_9ea5;
loc_9ea3: // 01ed:7fd3
    bl = ah;
loc_9ea5: // 01ed:7fd5
    bh = al;
    if (--cx)
        goto loc_9e8e;
    ax = bx;
    cx = pop();
    bx = pop();
}
void sub_9f5e() // 01ed:808e
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ec2; sub_ec20(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9f6e() // 01ed:809e
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs); cs = 0x0ec2; sub_ec52(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9f7c() // 01ed:80ac
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_d4d3(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_9f8c() // 01ed:80bc
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_d7d7(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_a485() // 01ed:85b5
{
    push(bx);
    bx = memoryAGet16(cs, 0x85b3);
    if (bx != 0x0000)
        goto loc_a495;
    sub_afe5();
    goto loc_a4a9;
loc_a495: // 01ed:85c5
    if (bx != 0x0004)
        goto loc_a49f;
    sub_a9a0();
    goto loc_a4a9;
loc_a49f: // 01ed:85cf
    if (bx != 0x0001)
        goto loc_a4a9;
    sub_acff();
    goto loc_a4a9;
loc_a4a9: // 01ed:85d9
    bx = pop();
}
void sub_a4ab() // 01ed:85db
{
    push(ax);
    ax = memoryAGet16(cs, 0x85b3);
    if (ax != 0x0000)
        goto loc_a4ba;
    sub_b09f();
    goto loc_a4ce;
loc_a4ba: // 01ed:85ea
    if (ax != 0x0004)
        goto loc_a4c4;
    sub_a9c6();
    goto loc_a4ce;
loc_a4c4: // 01ed:85f4
    if (ax != 0x0001)
        goto loc_a4ce;
    sub_ad18();
    goto loc_a4ce;
loc_a4ce: // 01ed:85fe
    ax = pop();
}
void sub_a4d0() // 01ed:8600
{
    push(cx);
    cx = memoryAGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a4e0;
    sub_b0a7();
    goto loc_a4f4;
loc_a4e0: // 01ed:8610
    if (cx != 0x0004)
        goto loc_a4ea;
    sub_a9d4();
    goto loc_a4f4;
loc_a4ea: // 01ed:861a
    if (cx != 0x0001)
        goto loc_a4f4;
    sub_ad20();
    goto loc_a4f4;
loc_a4f4: // 01ed:8624
    cx = pop();
}
void sub_a4f6() // 01ed:8626
{
    push(cx);
    cx = memoryAGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a506;
    sub_b0af();
    goto loc_a51a;
loc_a506: // 01ed:8636
    if (cx != 0x0004)
        goto loc_a510;
    sub_a9dd();
    goto loc_a51a;
loc_a510: // 01ed:8640
    if (cx != 0x0001)
        goto loc_a51a;
    sub_ad28();
    goto loc_a51a;
loc_a51a: // 01ed:864a
    cx = pop();
}
void sub_a5b9() // 01ed:86e9
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    ax = memoryAGet16(cs, 0x85a3);
    cx = 0x0f42;
    mul16(cx);
    cx = memoryAGet16(cs, 0x85a5);
    bx = memoryAGet16(cs, 0x85a7);
    cl = ch;
    ch = bl;
    div16(cx);
    cx = ax;
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = cx;
    dx = 0x01ed;
    cx = 0x864c;
    bx = 0x0000;
    sub_9cc9();
    ds = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_a5f2() // 01ed:8722
{
    push(bx);
    push(dx);
    push(ds);
    push(es);
    sub_a5b9();
    es = pop();
    ds = pop();
    dx = pop();
    bx = pop();
}
void sub_a5fe() // 01ed:872e
{
    ah = al;
    sub_a8b2();
loc_a603: // 01ed:8733
    al = lodsb<DS_SI>();
    ah = al;
    sub_a8b2();
    if (--cx)
        goto loc_a603;
}
void sub_a60c() // 01ed:873c
{
    push(cx);
loc_a60d: // 01ed:873d
    al = lodsb<DS_SI>();
    if (al & 0x80)
        goto loc_a615;
    al = lodsb<DS_SI>();
    goto loc_a666;
loc_a615: // 01ed:8745
    ch = 0;
    if ((char)al < (char)0xf0)
        goto loc_a62b;
    if (al == 0xf0)
        goto loc_a626;
    if (al != 0xf7)
        goto loc_a630;
    sub_a4ab();
    goto loc_a666;
loc_a626: // 01ed:8756
    sub_a4d0();
    goto loc_a666;
loc_a62b: // 01ed:875b
    sub_a4f6();
    goto loc_a666;
loc_a630: // 01ed:8760
    ax = lodsw<DS_SI>();
    if (al != 0x51)
        goto loc_a643;
    al = lodsb<DS_SI>();
    memoryASet(cs, 0x85a7, al);
    ax = lodsw<DS_SI>();
    tl = al; al = ah; ah = tl;
    memoryASet16(cs, 0x85a5, ax);
    goto loc_a666;
loc_a643: // 01ed:8773
    if (al != 0x2f)
        goto loc_a654;
    ax = lodsw<DS_SI>();
    ax = 0xffff;
    dx = ax;
    memoryASet16(cs, 0x85a1, memoryAGet16(cs, 0x85a1) - 1);
    goto loc_a670;
loc_a654: // 01ed:8784
    if (al != 0x20)
        goto loc_a660;
    al = lodsb<DS_SI>();
    memoryASet(cs, bx + 128, al);
    goto loc_a666;
loc_a660: // 01ed:8790
    cl = ah;
    si += cx;
    goto loc_a666;
loc_a666: // 01ed:8796
    sub_a761();
    if (!flags.zero)
        goto loc_a66d;
    goto loc_a60d;
loc_a66d: // 01ed:879d
    sub_a8f3();
loc_a670: // 01ed:87a0
    cx = pop();
}
void sub_a672() // 01ed:87a2
{
    cx = memoryAGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a67a: // 01ed:87aa
    si = memoryAGet16(cs, bx); ds = memoryAGet16(cs, bx + 2);
    sub_a761();
    if (!flags.zero)
        goto loc_a685;
    sub_a60c();
loc_a685: // 01ed:87b5
    memoryASet16(cs, bx + 64, ax);
    memoryASet16(cs, bx + 66, dx);
    memoryASet16(cs, bx, si);
    ax = ds;
    memoryASet16(cs, bx + 2, ax);
    bx++;
    bx++;
    bx++;
    bx++;
    if (--cx)
        goto loc_a67a;
}
void sub_a6d9() // 01ed:8809
{
    if (memoryAGet16(ds, si) != 0x544d)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x6468)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x0000)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x0600)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) == 0x0200)
        goto loc_a75e;
    si++;
    si++;
    ax = lodsw<DS_SI>();
    tl = al; al = ah; ah = tl;
    if (ax == 0x0000)
        goto loc_a75e;
    if ((short)ax > (short)0x0010)
        goto loc_a75e;
    memoryASet16(cs, 0x85a1, ax);
    ax = lodsw<DS_SI>();
    tl = al; al = ah; ah = tl;
    if (ah & 0x80)
        goto loc_a75e;
    memoryASet16(cs, 0x85a3, ax);
    cx = memoryAGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a72e: // 01ed:885e
    sub_a8f3();
    ax = lodsw<DS_SI>();
    if (ax != 0x544d)
        goto loc_a75e;
    ax = lodsw<DS_SI>();
    if (ax != 0x6b72)
        goto loc_a75e;
    ax = lodsw<DS_SI>();
    if (ax != 0x0000)
        goto loc_a75e;
    ax = lodsw<DS_SI>();
    memoryASet16(cs, bx, si);
    bx++;
    bx++;
    memoryASet16(cs, bx, ds);
    bx++;
    bx++;
    tl = al; al = ah; ah = tl;
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    if (flags.carry)
        goto loc_a75e;
    if (--cx)
        goto loc_a72e;
    sub_a672();
    ax = 0xffff;
    goto loc_a760;
loc_a75e: // 01ed:888e
    ax = 0;
loc_a760: // 01ed:8890
    return;
}
void sub_a761() // 01ed:8891 +returnZero
{
    ax = 0;
    dx = ax;
    al = lodsb<DS_SI>();
    if (!(al & 0x80))
        goto loc_a7ae;
    ah = al;
    al = lodsb<DS_SI>();
    if (al & 0x80)
        goto loc_a77a;
    ax &= 0x7f7f;
    al <<= 1;
    ax >>= 1;
    goto loc_a7ae;
loc_a77a: // 01ed:88aa
    tx = dx; dx = ax; ax = tx;
    al = lodsb<DS_SI>();
    if (al & 0x80)
        goto loc_a796;
    tl = ah; ah = dl; dl = tl;
    tl = dl; dl = dh; dh = tl;
    dx &= 0x7f7f;
    ax <<= 1;
    al <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr16(ax, 0x0001);
    goto loc_a7ae;
loc_a796: // 01ed:88c6
    ah = al;
    al = lodsb<DS_SI>();
    tx = dx; dx = ax; ax = tx;
    dx &= 0x7f7f;
    dl <<= 1;
    dx >>= 1;
    ax <<= 1;
    al <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr16(ax, 0x0001);
loc_a7ae: // 01ed:88de
    push(bx);
    bx = ax;
    flags.zero = !(bx | dx);
    bx |= dx;
    bx = pop();
}
void sub_a7b5() // 01ed:88e5
{
    cx = 0xffff;
    ax = memoryAGet16(ds, 0x557a);
    if (ax)
        goto loc_a7e9;
    ax = 0x0001;
    memoryASet16(ds, 0x557a, ax);
    cx = 0;
    memoryASet16(ds, 0x5584, ax);
    push(cx);
    sub_a945();
    cx = pop();
    ax = 0x0004;
    if (flags.zero)
        goto loc_a7d6;
    cx |= ax;
loc_a7d6: // 01ed:8906
    push(cx);
    sub_a9fa();
    cx = pop();
    ax = 0x0001;
    if (flags.zero)
        goto loc_a7e2;
    cx |= ax;
loc_a7e2: // 01ed:8912
    memoryASet16(cs, 0x85b3, ax);
    memoryASet16(ds, 0x5586, ax);
loc_a7e9: // 01ed:8919
    ax = cx;
}
void sub_a7ee() // 01ed:891e
{
    sp -= 2;
    cx = 0xffff;
    ax = memoryAGet16(ds, 0x557a);
    if (ax != 0x0001)
        goto loc_a827;
    ax = 0x0002;
    memoryASet16(ds, 0x557a, ax);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    cx = 0x0000;
loc_a809: // 01ed:8939
    flags.carry = ax & 1;
    ax >>= 1;
    if (flags.carry)
        goto loc_a817;
    cx++;
    if (cx != 0x0010)
        goto loc_a809;
    ax = 0;
    goto loc_a82c;
loc_a817: // 01ed:8947
    ax = 0x0000;
    ax = rcl16(ax, 0x0001);
    ax <<= cl;
loc_a81e: // 01ed:894e
    memoryASet16(cs, 0x85b3, ax);
    memoryASet16(ds, 0x5586, ax);
    cx = ax;
loc_a827: // 01ed:8957
    ax = cx;
    sp += 2;
    return;
loc_a82c: // 01ed:895c
    bx = 0x0001;
    ax = 0x0064;
    dx = 0x01ed;
    cx = 0x9136;
    sub_9cc9();
    ax = 0;
    memoryASet(cs, 0x83ee, al);
    memoryASet16(cs, 0x83ef, ax);
    goto loc_a81e;
}
void sub_a847() // 01ed:8977
{
    sp -= 2;
    goto loc_a847;
loc_a69d: // 01ed:87cd
    push(bp);
    bp = sp;
    push(es);
    push(ds);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(cs, 0x8483, ax);
    si = memoryAGet16(ss, bp + 8); es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(ds, 0x5580, si);
    si = es;
    memoryASet16(ds, 0x5582, si);
    si = memoryAGet16(ss, bp + 4); ds = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(cs, 0x8485, si);
    ax = ds;
    memoryASet16(cs, 0x8487, ax);
    sub_a6d9();
    if (!ax)
        goto loc_a6d3;
    sub_a5f2();
    ax = 0x0001;
loc_a6d3: // 01ed:8803
    di = pop();
    si = pop();
    ds = pop();
    es = pop();
    bp = pop();
    sp += 2;
    return;
    // gap 366 bytes
loc_a847: // 01ed:8977
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x5586);
    flags.zero = ax == 0x8000;
    ax = 0x0000;
    if (flags.zero)
        goto loc_a865;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
    goto loc_a69d;
loc_a865: // 01ed:8995
    ds = pop();
    sp += 2;
}
void sub_a869() // 01ed:8999
{
    ax = memoryAGet16(cs, 0x85a1);
    if (ax)
        goto loc_a877;
    ax = memoryAGet16(cs, 0x8483);
loc_a877: // 01ed:89a7
    return;
}
void sub_a878() // 01ed:89a8
{
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
}
void sub_a8b2() // 01ed:89e2
{
    push(cx);
    cx = 0;
    dx = 0x0331;
loc_a8b8: // 01ed:89e8
    al = in8(dx);
    if (--cx && al & 0x40)
        goto loc_a8b8;
    if (al & 0x40)
        goto loc_a8c5;
    dx--;
    al = ah;
    out8(dx, al);
loc_a8c3: // 01ed:89f3
    cx = pop();
    return;
loc_a8c5: // 01ed:89f5
    push(ds);
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x557c, cx);
    ds = pop();
    memoryASet16(cs, 0x85a1, cx);
    goto loc_a8c3;
}
void sub_a8d7() // 01ed:8a07
{
    sp -= 2;
    ah = 0x99;
    goto loc_a8dd;
    // gap 2 bytes
loc_a8dd: // 01ed:8a0d
    push(bp);
    bp = sp;
    push(dx);
    sub_a8b2();
    ah = memoryAGet(ss, bp + 4);
    sub_a8b2();
    ah = memoryAGet(ss, bp + 6);
    sub_a8b2();
    dx = pop();
    bp = pop();
    sp += 2;
}
void sub_a8f3() // 01ed:8a23
{
    push(ax);
    push(bx);
    ax = si;
    si &= 0x000f;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = ds;
    ax += bx;
    ds = ax;
    bx = pop();
    ax = pop();
}
void sub_a945() // 01ed:8a75 +returnZero
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    if (memoryAGet16(ds, 0x557c) == 0x0000)
        goto loc_a996;
    cx = 0x1388;
    dx = 0x0331;
loc_a956: // 01ed:8a86
    al = in8(dx);
    if (--cx && al & 0x40)
        goto loc_a956;
    if (al & 0x40)
        goto loc_a990;
    al = 0xff;
    out8(dx, al);
    bx = 0x0003;
loc_a963: // 01ed:8a93
    cx = 0x1388;
    dx = 0x0331;
loc_a969: // 01ed:8a99
    al = in8(dx);
    if (--cx && al & 0x80)
        goto loc_a969;
    if (al & 0x80)
        goto loc_a98d;
    dx = 0x0330;
    al = in8(dx);
    if (al != 0xfe)
        goto loc_a98d;
    cx = 0x1388;
    dx = 0x0331;
loc_a97e: // 01ed:8aae
    al = in8(dx);
    if (--cx && al & 0x40)
        goto loc_a97e;
    if (al & 0x40)
        goto loc_a990;
    dx = 0x0331;
    al = 0x3f;
    out8(dx, al);
    goto loc_a996;
loc_a98d: // 01ed:8abd
    bx--;
    if (bx)
        goto loc_a963;
loc_a990: // 01ed:8ac0
    memoryASet16(ds, 0x557c, 0x0000);
loc_a996: // 01ed:8ac6
    dx = pop();
    cx = pop();
    bx = pop();
    cx = pop();
    ax = memoryAGet16(ds, 0x557c);
    flags.zero = !ax;
}
void sub_a9a0() // 01ed:8ad0
{
    push(dx);
    push(cx);
    push(bx);
    push(ax);
    bx = 0x9009;
loc_a9a7: // 01ed:8ad7
    cx = 0x007f;
loc_a9aa: // 01ed:8ada
    ah = bh;
    ah += bl;
    sub_a8b2();
    ah = cl;
    sub_a8b2();
    ah = 0;
    sub_a8b2();
    if (--cx)
        goto loc_a9aa;
    bl--;
    if (bl)
        goto loc_a9a7;
    ax = pop();
    bx = pop();
    cx = pop();
    dx = pop();
}
void sub_a9c6() // 01ed:8af6
{
    push(ax);
    push(cx);
    al = lodsb<DS_SI>();
    cl = al;
    al = lodsb<DS_SI>();
    cl--;
    sub_a5fe();
    cx = pop();
    ax = pop();
}
void sub_a9d4() // 01ed:8b04
{
    push(cx);
    cl = memoryAGet(ds, si);
    si++;
    sub_a5fe();
    cx = pop();
}
void sub_a9dd() // 01ed:8b0d
{
    push(cx);
    if (al & 0x0f)
        goto loc_a9e7;
    al |= memoryAGet(cs, bx + 128);
loc_a9e7: // 01ed:8b17
    cx = 0x0002;
    ah = al;
    ah &= 0xf0;
    if (ah != 0xc0)
        goto loc_a9f5;
    cx--;
loc_a9f5: // 01ed:8b25
    sub_a5fe();
    cx = pop();
}
void sub_a9fa() // 01ed:8b2a +returnZero
{
    ax = 0x0001;
    memoryASet16(ds, 0x557e, ax);
    sub_ae86();
    if (flags.zero)
        goto loc_aa0a;
    sub_adbb();
    goto loc_aa10;
loc_aa0a: // 01ed:8b3a
    memoryASet16(ds, 0x557e, 0x0000);
loc_aa10: // 01ed:8b40
    ax = memoryAGet16(ds, 0x557e);
    flags.zero = !ax;
}
void sub_aa3b() // 01ed:8b6b
{
    push(ax);
    push(di);
    push(si);
    push(cx);
    push(ds);
    push(bx);
    push(es);
    bl = al;
    bh = 0;
    sub_aa51();
    es = pop();
    bx = pop();
    ds = pop();
    cx = pop();
    si = pop();
    di = pop();
    ax = pop();
}
void sub_aa51() // 01ed:8b81
{
    push(si);
    push(di);
    push(ds);
    push(es);
    si = 0x1228;
    ds = si;
    si = memoryAGet16(ds, 0x5580); ds = memoryAGet16(ds, 0x5580 + 2);
    di = memoryAGet16(ds, si + 12);
    di += si;
    bx += bx;
    bx += bx;
    cx = bx;
    bx += bx;
    bx += cx;
    di += bx;
    bx = memoryAGet16(ds, di);
    bx += bx;
    di = bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx -= di;
    di = memoryAGet16(ds, si + 16);
    di += si;
    di += bx;
    bx = 0;
    push(ds);
    push(di);
    al = ah;
    di = pop();
    ds = pop();
    ah = 0;
    sub_aa98();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
}
void sub_aa98() // 01ed:8bc8
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(ax);
    ah = 0x08;
    al = 0x00;
    sub_aed7();
    ax = pop();
    dh = memoryAGet(ds, bx + di);
    if (!dh)
        goto loc_aaae;
    goto loc_ac56;
loc_aaae: // 01ed:8bde
    dl = al;
    dl += 0xc0;
    dh = memoryAGet(ds, bx + di + 4);
    dh &= 0x07;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 14);
    ah &= 0x01;
    ah ^= 0x01;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    ah = 0;
    push(ds);
    push(di);
    cx = 0x1228;
    ds = cx;
    di = 0x5593;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    ds = pop();
    dl = al;
    dl += 0x40;
    dh = memoryAGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 2);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x60;
    dh = memoryAGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryAGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryAGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 11);
    if (!ah)
        goto loc_ab5e;
    dh |= 0x80;
loc_ab5e: // 01ed:8c8e
    ah = memoryAGet(ds, bx + di + 12);
    if (!ah)
        goto loc_ab68;
    dh |= 0x40;
loc_ab68: // 01ed:8c98
    ah = memoryAGet(ds, bx + di + 7);
    if (!ah)
        goto loc_ab72;
    dh |= 0x20;
loc_ab72: // 01ed:8ca2
    ah = memoryAGet(ds, bx + di + 13);
    if (!ah)
        goto loc_ab7c;
    dh |= 0x10;
loc_ab7c: // 01ed:8cac
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x43;
    dh = memoryAGet(ds, bx + di + 23);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 15);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x63;
    dh = memoryAGet(ds, bx + di + 18);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 21);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x83;
    dh = memoryAGet(ds, bx + di + 19);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 22);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x23;
    dh = memoryAGet(ds, bx + di + 16);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 24);
    if (!ah)
        goto loc_ac02;
    dh |= 0x80;
loc_ac02: // 01ed:8d32
    ah = memoryAGet(ds, bx + di + 25);
    if (!ah)
        goto loc_ac0c;
    dh |= 0x40;
loc_ac0c: // 01ed:8d3c
    ah = memoryAGet(ds, bx + di + 20);
    if (!ah)
        goto loc_ac16;
    dh |= 0x20;
loc_ac16: // 01ed:8d46
    ah = memoryAGet(ds, bx + di + 26);
    if (!ah)
        goto loc_ac20;
    dh |= 0x10;
loc_ac20: // 01ed:8d50
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe0;
    dh = memoryAGet(ds, bx + di + 28);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe3;
    dh = memoryAGet(ds, bx + di + 29);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
loc_ac51: // 01ed:8d81
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_ac56: // 01ed:8d86
    al = 0x01;
    dl = al;
    dl += 0x40;
    dh = memoryAGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 2);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x60;
    dh = memoryAGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryAGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryAGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 11);
    if (!ah)
        goto loc_acd5;
    dh |= 0x80;
loc_acd5: // 01ed:8e05
    ah = memoryAGet(ds, bx + di + 12);
    if (!ah)
        goto loc_acdf;
    dh |= 0x40;
loc_acdf: // 01ed:8e0f
    ah = memoryAGet(ds, bx + di + 7);
    if (!ah)
        goto loc_ace9;
    dh |= 0x20;
loc_ace9: // 01ed:8e19
    ah = memoryAGet(ds, bx + di + 13);
    if (!ah)
        goto loc_acf3;
    dh |= 0x10;
loc_acf3: // 01ed:8e23
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    goto loc_ac51;
}
void sub_acff() // 01ed:8e2f
{
    push(ax);
    bx = 0x0001;
loc_ad03: // 01ed:8e33
    push(bx);
    ax = 0;
    push(ax);
    push(ax);
    push(ax);
    sub_af2d();
    ax = pop();
    ax = pop();
    ax = pop();
    bx = pop();
    bx++;
    if ((short)bx <= (short)0x0009)
        goto loc_ad03;
    ax = pop();
}
void sub_ad18() // 01ed:8e48
{
    push(ax);
    al = lodsb<DS_SI>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad20() // 01ed:8e50
{
    push(ax);
    al = lodsb<DS_SI>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad28() // 01ed:8e58
{
    push(bx);
    push(cx);
    if (al & 0x0f)
        goto loc_ad33;
    al |= memoryAGet(cs, bx + 128);
loc_ad33: // 01ed:8e63
    ah = al;
    ah &= 0x0f;
    if ((char)ah <= (char)0x08)
        goto loc_ad3f;
    goto loc_ad53;
loc_ad3f: // 01ed:8e6f
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_ad5e;
    if (ah == 0x90)
        goto loc_ad6e;
    if (ah == 0x80)
        goto loc_ad97;
loc_ad53: // 01ed:8e83
    si++;
    al &= 0xf0;
    if (al == 0xc0)
        goto loc_ad5b;
    si++;
loc_ad5b: // 01ed:8e8b
    cx = pop();
    bx = pop();
    return;
loc_ad5e: // 01ed:8e8e
    sub_ad63();
    goto loc_ad5b;
    // gap 11 bytes
loc_ad6e: // 01ed:8e9e
    sub_ad73();
    goto loc_ad5b;
    // gap 36 bytes
loc_ad97: // 01ed:8ec7
    push(ax);
    al &= 0x0f;
    al += 0xb0;
    ah = al;
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += 0x00 + flags.carry;
    al = memoryAGet(ds, bx);
    bx = pop();
    ds = pop();
    al &= 0xdf;
    sub_aed7();
    al = lodsb<DS_SI>();
    al = lodsb<DS_SI>();
    ax = pop();
    goto loc_ad5b;
}
void sub_ad63() // 01ed:8e93
{
    al &= 0x0f;
    ah = al;
    al = memoryAGet(ds, si);
    sub_aa3b();
    si++;
}
void sub_ad73() // 01ed:8ea3
{
    sp -= 2;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(es);
    al &= 0x0f;
    ah = 0;
    push(ax);
    al = lodsb<DS_SI>();
    push(ax);
    al = lodsb<DS_SI>();
    push(ax);
    if (!ax)
        goto loc_ad89;
    ax = 0x0020;
loc_ad89: // 01ed:8eb9
    push(ax);
    sub_af2d();
    sp += 0x0008;
    es = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    sp += 2;
}
void sub_adbb() // 01ed:8eeb
{
    push(ax);
    push(ax);
    ah = 0x40;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x41;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x42;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x48;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x49;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4a;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x50;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x51;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x52;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x43;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x44;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x45;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4b;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4c;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4d;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x53;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x54;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x55;
    al = 0xff;
    sub_aed7();
    ax = pop();
    ax = 0x0100;
loc_ae61: // 01ed:8f91
    sub_aed7();
    ah++;
    if (ah != 0x40)
        goto loc_ae61;
    ax = 0x6000;
loc_ae6e: // 01ed:8f9e
    sub_aed7();
    ah++;
    if (ah != 0xf6)
        goto loc_ae6e;
    ax = 0x0406;
    sub_aed7();
    ax = 0xbd00;
    sub_aed7();
    ax = pop();
}
void sub_ae86() // 01ed:8fb6 +returnZero
{
    push(ax);
    push(cx);
    push(dx);
    ax = 0x0460;
    sub_aed7();
    ax = 0x0480;
    sub_aed7();
    sub_af26();
    push(ax);
    ax = 0x02ff;
    sub_aed7();
    ax = 0x0421;
    sub_aed7();
    cx = 0x00c7;
loc_aea8: // 01ed:8fd8
    sub_af26();
    if (--cx)
        goto loc_aea8;
    sub_af26();
    push(ax);
    ax = 0x0460;
    sub_aed7();
    ax = 0x0480;
    sub_aed7();
    ax = pop();
    dx = pop();
    ah = 0x00;
    al &= 0xe0;
    dl &= 0xe0;
    if (al != 0xc0)
        goto loc_aed1;
    if (dl != 0x00)
        goto loc_aed1;
    ah = 0x01;
loc_aed1: // 01ed:9001
    flags.zero = !(ah & ah);
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_aed7() // 01ed:9007
{
    push(flagAsReg());
    flags.interrupts = 0;
    push(ax);
    push(dx);
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += 0x00 + flags.carry;
    memoryASet(ds, bx, al);
    bx = pop();
    ds = pop();
    dx = 0x0388;
    tl = ah; ah = al; al = tl;
    out8(dx, al);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    dx++;
    tl = ah; ah = al; al = tl;
    out8(dx, al);
    dx--;
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    al = in8(dx);
    dx = pop();
    ax = pop();
    flagsFromReg(pop());
}
void sub_af26() // 01ed:9056
{
    push(dx);
    dx = 0x0388;
    al = in8(dx);
    dx = pop();
}
void sub_af2d() // 01ed:905d
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(bx);
    push(cx);
    push(dx);
    push(ds);
    push(ax);
    ah = 0x08;
    al = 0x00;
    sub_aed7();
    ax = pop();
    push(bx);
    push(ds);
    push(ax);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ss, bp + 10);
    bh = 0;
    dl = memoryAGet(ds, bx + 21907);
    dl += 0x43;
    ah = dl;
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += 0x00 + flags.carry;
    al = memoryAGet(ds, bx);
    bx = pop();
    ds = pop();
    ah = 0x20;
    dh -= memoryAGet(ss, bp + 6);
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh &= 0x3f;
    ah -= dh;
    dh = ah;
    dh &= 0x3f;
    al &= 0xc0;
    dh |= al;
    push(dx);
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dx = pop();
    ax = pop();
    ds = pop();
    bx = pop();
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ss, bp + 8);
    di = 0x55b4;
    cl = memoryAGet(ds, bx + di);
    cl--;
    di = 0x5614;
    al = memoryAGet(ds, bx + di);
    ah = 0;
    bx = ax;
    bx += bx;
    di = 0x559c;
    ax = memoryAGet16(ds, bx + di);
    ax &= 0x03ff;
    push(ax);
    ah = al;
    al = 0xa0;
    al += memoryAGet(ss, bp + 10);
    tl = al; al = ah; ah = tl;
    sub_aed7();
    ax = pop();
    ds = pop();
    al = ah;
    al &= 0x03;
    cl &= 0x07;
    cl <<= 1;
    cl <<= 1;
    al += cl;
    al += memoryAGet(ss, bp + 4);
    ah = 0;
    push(ax);
    ah = al;
    al = 0xb0;
    al += memoryAGet(ss, bp + 10);
    tl = ah; ah = al; al = tl;
    sub_aed7();
    ax = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    bp = pop();
    sp += 2;
}
void sub_afe5() // 01ed:9115
{
    push(ax);
    push(bx);
    push(cx);
    bx = 0x83cc;
    cx = 0x000f;
    al = 0;
loc_aff0: // 01ed:9120
    memoryASet(cs, bx, al);
    bx++;
    if (--cx)
        goto loc_aff0;
    cx = pop();
    bx = pop();
    ax = pop();
    al = 0;
    memoryASet(cs, 0x83ee, al);
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
}
void sub_b09f() // 01ed:91cf
{
    push(ax);
    al = lodsb<DS_SI>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0a7() // 01ed:91d7
{
    push(ax);
    al = lodsb<DS_SI>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0af() // 01ed:91df
{
    push(ax);
    push(bx);
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_b0f7;
    if (al & 0x0f)
        goto loc_b0c4;
    al |= memoryAGet(cs, bx + 128);
loc_b0c4: // 01ed:91f4
    bx = 0x83cc;
    ah = al;
    ah &= 0x0f;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += 0x00 + flags.carry;
    al &= 0xf0;
    if (al == 0x90)
        goto loc_b0e9;
    if (al == 0x80)
        goto loc_b0e0;
    al = lodsb<DS_SI>();
    al = lodsb<DS_SI>();
loc_b0dd: // 01ed:920d
    bx = pop();
    ax = pop();
    return;
loc_b0e0: // 01ed:9210
    al = lodsb<DS_SI>();
    al = lodsb<DS_SI>();
    al = 0;
loc_b0e4: // 01ed:9214
    memoryASet(cs, bx, al);
    goto loc_b0dd;
loc_b0e9: // 01ed:9219
    al = lodsb<DS_SI>();
    ah = al;
    al = lodsb<DS_SI>();
    if (al == 0x00)
        goto loc_b0f5;
    al = ah;
    goto loc_b0e4;
loc_b0f5: // 01ed:9225
    goto loc_b0e4;
loc_b0f7: // 01ed:9227
    sub_b0fc();
    goto loc_b0dd;
}
void sub_b0fc() // 01ed:922c
{
    al &= 0x0f;
    ah = al;
    al = memoryAGet(ds, si);
    push(bx);
    bx = 0x8473;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += 0x00 + flags.carry;
    memoryASet(cs, bx, al);
    bx = pop();
    si++;
}
void sub_b14c() // 01ed:927c
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x0000;
    interrupt(0x33);
    memoryASet(ds, 0x5674, al);
    ax ^= 0xffff;
    push(ax);
    ax = 0x0004;
    cx = 0x0000;
    dx = cx;
    interrupt(0x33);
    ax = 0x0007;
    cx = 0x0000;
    dx = 0x0280;
    interrupt(0x33);
    ax = 0x0008;
    cx = 0x0000;
    dx = 0x00c8;
    interrupt(0x33);
    ax = pop();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
}
void sub_b274() // 01ed:93a4
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ed2; sub_ed20(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b281() // 01ed:93b1
{
    push(cs); cs = 0x0ed2; sub_ed3f(); assert(cs == 0x01ed);
}
void sub_b288() // 01ed:93b8
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_da88(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b298() // 01ed:93c8
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_dcce(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b2a8() // 01ed:93d8
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(cs); cs = 0x0ed9; sub_11a7d(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_b2d6() // 01ed:9406
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(cs); cs = 0x0ed9; sub_11b38(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_b2e0() // 01ed:9410
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(cs); cs = 0x0ed9; sub_11b62(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_b2f4() // 01ed:9424
{
    push(cs); cs = 0x0ed9; sub_11ec7(); assert(cs == 0x01ed);
}
void sub_b2fa() // 01ed:942a
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(cs); cs = 0x0ed9; sub_11f47(); assert(cs == 0x01ed);
    bp = pop();
    sp += 2;
}
void sub_b304()
{
  sub_b306();
}

void sub_b306()
{
  sub_b308();
}

void sub_b308() // 01ed:9438
{
}
void sub_b310() // 01ed:9440
{
    if (memoryAGet16(ds, 0x683e) != 0x0000)
        goto loc_b321;
    al = in8(0x61);
    al |= 0x03;
    sub_b304();
    out8(0x61, al);
    return;
loc_b321: // 01ed:9451
    al = in8(0x61);
    al &= 0xfc;
    sub_b304();
    out8(0x61, al);
}
void sub_b321() // 01ed:9451
{
    al = in8(0x61);
    al &= 0xfc;
    sub_b304();
    out8(0x61, al);
}
void sub_b32b() // 01ed:945b +returnCarry
{
    flags.carry = ax < 0x00ff;
    if (ax == 0x00ff)
        goto loc_b337;
    flags.carry = memoryAGet16(cs, 0x946c) < ax;
    if (flags.carry)
        goto loc_b33b;
loc_b337: // 01ed:9467
    memoryASet16(cs, 0x946c, ax);
loc_b33b: // 01ed:946b
    return;
}
void sub_b33e() // 01ed:946e
{
    ax = memoryAGet16(ds, 0x683e);
    flags.zero = ax == 0x0000;
    ax = 0x00ff;
    if (flags.zero)
        goto loc_b351;
    ax = 0x0000;
    sub_b32b();
    goto loc_b357;
loc_b351: // 01ed:9481
    sub_b32b();
    sub_b321();
loc_b357: // 01ed:9487
    return;
}
void sub_b358() // 01ed:9488
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    push(flagAsReg());
    flags.interrupts = 0;
    ax = memoryAGet16(ss, bp + 4);
    sub_b32b();
    ax = 0xffff;
    if (flags.carry)
        goto loc_b3ca;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(cs, 0x9788, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(cs, 0x978a, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(cs, 0x9796, ax);
    memoryASet16(cs, 0x978c, ax);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(cs, 0x978e, ax);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(cs, 0x9790, ax);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(cs, 0x9792, ax);
    memoryASet16(cs, 0x9798, ax);
    ax = memoryAGet16(ss, bp + 18);
    memoryASet16(cs, 0x9794, ax);
    memoryASet(cs, 0x979a, 0x0f);
    cx = 0x9631;
    memoryASet16(cs, 0x97a1, cx);
    dx = 0x01ed;
    memoryASet16(cs, 0x979f, dx);
    ax = memoryAGet16(ss, bp + 14);
    bx = 0x0002;
    sub_9cc9();
    sub_b310();
    ax = 0;
loc_b3ca: // 01ed:94fa
    flagsFromReg(pop());
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    bp = pop();
    sp += 2;
}
void sub_b3d2() // 01ed:9502
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    push(flagAsReg());
    flags.interrupts = 0;
    ax = memoryAGet16(ss, bp + 4);
    sub_b32b();
    ax = 0xffff;
    if (flags.carry)
        goto loc_b435;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(cs, 0x9788, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(cs, 0x978a, ax);
    ax = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(cs, 0x9790, ax);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(cs, 0x9792, ax);
    memoryASet16(cs, 0x9798, ax);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(cs, 0x9794, ax);
    memoryASet(cs, 0x979a, 0x0f);
    cx = 0x96c4;
    memoryASet16(cs, 0x97a1, cx);
    dx = 0x01ed;
    memoryASet16(cs, 0x979f, dx);
    ax = memoryAGet16(ss, bp + 10);
    bx = 0x0002;
    sub_9cc9();
    sub_b310();
    ax = 0;
loc_b435: // 01ed:9565
    flagsFromReg(pop());
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    bp = pop();
    sp += 2;
}
void sub_b674() // 01ed:97a4
{
    push(cs); cs = 0x1219; sub_12190(); assert(cs == 0x01ed);
}
void sub_b67a() // 01ed:97aa +far +returnZero +stackDrop2
{
    sub_998b();
    cs = pop();
}
void sub_b695() // 01ed:97c5
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_dd71(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b6a5() // 01ed:97d5
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_dd8b(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b6c1() // 01ed:97f1
{
    push(cs); cs = 0x0ca6; sub_dddb(); assert(cs == 0x01ed);
}
void sub_b6d4() // 01ed:9804
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_de4c(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b6e4() // 01ed:9814
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_de69(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b6f1() // 01ed:9821
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 10);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_de82(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b707() // 01ed:9837
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs); cs = 0x0ca6; sub_dea1(); assert(cs == 0x01ed);
    sp += 2;
}
void sub_b734() // 01ed:9864
{
    push(cs); cs = 0x1223; sub_12230(); assert(cs == 0x01ed);
}
void sub_b75e() // 01ed:988e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_b76e;
    if ((short)si < (short)0x0014)
        goto loc_b777;
loc_b76e: // 01ed:989e
    ax = 0x0006;
    push(ax);
    sub_c048();
    goto loc_b786;
loc_b777: // 01ed:98a7
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, 0xffff);
    push(si);
    sub_be85();
    cx = pop();
loc_b786: // 01ed:98b6
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_b78a() // 01ed:98ba
{
    sp -= 2;
    push(bp);
    bp = sp;
    goto loc_b799;
loc_b78f: // 01ed:98bf
    bx = memoryAGet16(ds, 0x6982);
    bx <<= 1;
    indirectCall(cs, memoryAGet16(ds, bx + 41406)); // 01ed:98c5;
loc_b799: // 01ed:98c9
    ax = memoryAGet16(ds, 0x6982);
    memoryASet16(ds, 0x6982, memoryAGet16(ds, 0x6982) - 1);
    if (ax)
        goto loc_b78f;
    push(memoryAGet16(ss, bp + 4));
    sub_1fc6();
    cx = pop();
    bp = pop();
    sp += 2;
}
void sub_b7ad() // 01ed:98dd +stackDrop4
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    si = ax;
    si -= memoryAGet16(ds, 0x0079);
    ax = si;
    ax += 0x003f;
    cl = 0x06;
    ax >>= cl;
    si = ax;
    if (si != memoryAGet16(ds, 0x698a))
        goto loc_b7df;
loc_b7cd: // 01ed:98fd
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x0087, dx);
    memoryASet16(ds, 0x0089, ax);
    ax = 0x0001;
    goto loc_b825;
loc_b7df: // 01ed:990f
    cl = 0x06;
    si <<= cl;
    di = memoryAGet16(ds, 0x008d);
    ax = si;
    ax += memoryAGet16(ds, 0x0079);
    if (ax <= di)
        goto loc_b7f9;
    ax = di;
    ax -= memoryAGet16(ds, 0x0079);
    si = ax;
loc_b7f9: // 01ed:9929
    push(si);
    push(memoryAGet16(ds, 0x0079));
    sub_c352();
    cx = pop();
    cx = pop();
    di = ax;
    if (di != 0xffff)
        goto loc_b815;
    ax = si;
    cl = 0x06;
    ax >>= cl;
    memoryASet16(ds, 0x698a, ax);
    goto loc_b7cd;
loc_b815: // 01ed:9945
    ax = memoryAGet16(ds, 0x0079);
    ax += di;
    memoryASet16(ds, 0x008b, 0x0000);
    memoryASet16(ds, 0x008d, ax);
    ax = 0;
loc_b825: // 01ed:9955
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
    sp += 4;
}
void sub_b82b() // 01ed:995b
{
    sp -= 2;
    push(bp);
    bp = sp;
    cx = memoryAGet16(ds, 0x0085);
    bx = memoryAGet16(ds, 0x0083);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b861;
    cx = memoryAGet16(ds, 0x008d);
    bx = memoryAGet16(ds, 0x008b);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_c8fb();
    if (!flags.carry && !flags.zero)
        goto loc_b861;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b7ad();
    if (ax)
        goto loc_b866;
loc_b861: // 01ed:9991
    ax = 0xffff;
    goto loc_b868;
loc_b866: // 01ed:9996
    ax = 0;
loc_b868: // 01ed:9998
    bp = pop();
    sp += 2;
}
void sub_b86a() // 01ed:999a
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    dx = memoryAGet16(ds, 0x0089);
    ax = memoryAGet16(ds, 0x0087);
    cx = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    sub_c865();
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    cx = memoryAGet16(ds, 0x0085);
    bx = memoryAGet16(ds, 0x0083);
    ax = memoryAGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b8a9;
    cx = memoryAGet16(ds, 0x008d);
    bx = memoryAGet16(ds, 0x008b);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.carry || flags.zero)
        goto loc_b8b1;
loc_b8a9: // 01ed:99d9
    dx = 0xffff;
    ax = 0xffff;
    goto loc_b8d3;
loc_b8b1: // 01ed:99e1
    ax = memoryAGet16(ds, 0x0089);
    dx = memoryAGet16(ds, 0x0087);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_b7ad();
    if (ax)
        goto loc_b8cd;
    goto loc_b8a9;
loc_b8cd: // 01ed:99fd
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
loc_b8d3: // 01ed:9a03
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b8d7() // 01ed:9a07
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = memoryAGet16(ss, bp + 4);
    ax |= memoryAGet16(ss, bp + 6);
    if (ax)
        goto loc_b8e9;
    sub_b9a3();
    goto loc_b99e;
loc_b8e9: // 01ed:9a19
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 18);
    if (ax == memoryAGet16(ss, bp + 4))
        goto loc_b8fb;
loc_b8f5: // 01ed:9a25
    ax = 0xffff;
    goto loc_b9a0;
loc_b8fb: // 01ed:9a2b
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if ((short)memoryAGet16(es, bx) < (short)0x0000)
        goto loc_b952;
    if (memoryAGet16(es, bx + 2) & 0x0008)
        goto loc_b921;
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryAGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryAGet16(es, bx + 12) != dx)
        goto loc_b950;
loc_b921: // 01ed:9a51
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, 0x0000);
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryAGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryAGet16(es, bx + 12) != dx)
        goto loc_b950;
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    goto loc_b99e;
loc_b950: // 01ed:9a80
    goto loc_b99e;
loc_b952: // 01ed:9a82
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    ax += memoryAGet16(es, bx);
    ax++;
    si = ax;
    ax = memoryAGet16(es, bx);
    ax -= si;
    memoryASet16(es, bx, ax);
    push(si);
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    push(ax);
    push(dx);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    sub_bcce();
    sp += 0x0008;
    if (ax == si)
        goto loc_b99e;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0200)
        goto loc_b99e;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    goto loc_b8f5;
loc_b99e: // 01ed:9ace
    ax = 0;
loc_b9a0: // 01ed:9ad0
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_b9a3() // 01ed:9ad3
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    di = 0;
    si = 0x0014;
    memoryASet16(ss, bp - 4, 0x698c);
    memoryASet16(ss, bp - 2, ds);
    goto loc_b9d5;
loc_b9ba: // 01ed:9aea
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0003))
        goto loc_b9d1;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    di++;
loc_b9d1: // 01ed:9b01
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0014);
loc_b9d5: // 01ed:9b05
    ax = si;
    si--;
    if (ax)
        goto loc_b9ba;
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b9e4() // 01ed:9b14 +stackDrop4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_b9ff;
    ax = memoryAGet16(es, bx + 6);
    ax += memoryAGet16(es, bx);
    ax++;
    goto loc_ba0a;
loc_b9ff: // 01ed:9b2f
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    ax ^= dx;
    ax -= dx;
loc_ba0a: // 01ed:9b3a
    si = ax;
    di = ax;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0040))
        goto loc_ba1b;
    goto loc_ba5e;
loc_ba1b: // 01ed:9b4b
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(es, bx + 12);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_ba57;
    goto loc_ba41;
loc_ba34: // 01ed:9b64
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet(es, bx) != 0x0a)
        goto loc_ba41;
    di++;
loc_ba41: // 01ed:9b71
    ax = si;
    si--;
    if (ax)
        goto loc_ba34;
    goto loc_ba5e;
loc_ba4a: // 01ed:9b7a
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    if (memoryAGet(es, bx) != 0x0a)
        goto loc_ba57;
    di++;
loc_ba57: // 01ed:9b87
    ax = si;
    si--;
    if (ax)
        goto loc_ba4a;
loc_ba5e: // 01ed:9b8e
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
    sp += 4;
}
void sub_ba68() // 01ed:9b98
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_ba7f;
    ax = 0xffff;
    goto loc_bae2;
loc_ba7f: // 01ed:9baf
    if (memoryAGet16(ss, bp + 12) != 0x0001)
        goto loc_ba9e;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if ((short)memoryAGet16(es, bx) <= (short)0x0000)
        goto loc_ba9e;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b9e4();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, bp + 8) < ax;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - ax);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - dx - flags.carry);
loc_ba9e: // 01ed:9bce
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfe5f);
    memoryASet16(es, bx, 0x0000);
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    sub_c096();
    sp += 0x0008;
    if (dx != 0xffff)
        goto loc_bae0;
    if (ax != 0xffff)
        goto loc_bae0;
    ax = 0xffff;
    goto loc_bae2;
loc_bae0: // 01ed:9c10
    ax = 0;
loc_bae2: // 01ed:9c12
    bp = pop();
    sp += 2;
}
void sub_bb32() // 01ed:9c62
{
    sp -= 2;
    al = memoryAGet(ds, 0x6990);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb45;
    memoryASet16(ds, 0x698e, memoryAGet16(ds, 0x698e) & 0xfdff);
loc_bb45: // 01ed:9c75
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x698e) & 0x0200))
        goto loc_bb56;
    ax = 0x0001;
    goto loc_bb58;
loc_bb56: // 01ed:9c86
    ax = 0;
loc_bb58: // 01ed:9c88
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(ds);
    ax = 0x698c;
    push(ax);
    sub_bba3();
    sp += 0x000c;
    al = memoryAGet(ds, 0x69a4);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb7d;
    memoryASet16(ds, 0x69a2, memoryAGet16(ds, 0x69a2) & 0xfdff);
loc_bb7d: // 01ed:9cad
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x69a2) & 0x0200))
        goto loc_bb8e;
    ax = 0x0002;
    goto loc_bb90;
loc_bb8e: // 01ed:9cbe
    ax = 0;
loc_bb90: // 01ed:9cc0
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(ds);
    ax = 0x69a0;
    push(ax);
    sub_bba3();
    sp += 0x000c;
    sp += 2;
}
void sub_bba3() // 01ed:9cd3
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 12);
    si = memoryAGet16(ss, bp + 14);
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 18);
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_bbc5;
    if ((short)di > (short)0x0002)
        goto loc_bbc5;
    if (si <= 0x7fff)
        goto loc_bbcb;
loc_bbc5: // 01ed:9cf5
    ax = 0xffff;
    goto loc_bcb2;
loc_bbcb: // 01ed:9cfb
    if (memoryAGet16(ds, 0x6b4a) != 0x0000)
        goto loc_bbe1;
    if (memoryAGet16(ss, bp + 4) != 0x69a0)
        goto loc_bbe1;
    memoryASet16(ds, 0x6b4a, 0x0001);
    goto loc_bbf5;
loc_bbe1: // 01ed:9d11
    if (memoryAGet16(ds, 0x6b48) != 0x0000)
        goto loc_bbf5;
    if (memoryAGet16(ss, bp + 4) != 0x698c)
        goto loc_bbf5;
    memoryASet16(ds, 0x6b48, 0x0001);
loc_bbf5: // 01ed:9d25
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_bc14;
    ax = 0x0001;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_ba68();
    sp += 0x000a;
loc_bc14: // 01ed:9d44
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0004))
        goto loc_bc2c;
    push(memoryAGet16(es, bx + 10));
    push(memoryAGet16(es, bx + 8));
    sub_c4fe();
    cx = pop();
    cx = pop();
loc_bc2c: // 01ed:9d5c
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfff3);
    memoryASet16(es, bx + 6, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    memoryASet16(es, bx + 8, dx);
    memoryASet16(es, bx + 10, ax);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    if (di == 0x0002)
        goto loc_bcb0;
    if (!si)
        goto loc_bcb0;
    memoryASet16(ds, 0x6984, 0x9f25);
    ax = memoryAGet16(ss, bp + 8);
    ax |= memoryAGet16(ss, bp + 10);
    if (ax)
        goto loc_bc88;
    push(si);
    sub_c5e4();
    cx = pop();
    memoryASet16(ss, bp + 8, ax);
    memoryASet16(ss, bp + 10, dx);
    ax |= dx;
    if (!ax)
        goto loc_bc85;
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0004);
    goto loc_bc88;
loc_bc85: // 01ed:9db5
    goto loc_bbc5;
loc_bc88: // 01ed:9db8
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 8, dx);
    memoryASet16(es, bx + 10, ax);
    memoryASet16(es, bx + 6, si);
    if (di != 0x0001)
        goto loc_bcb0;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0008);
loc_bcb0: // 01ed:9de0
    ax = 0;
loc_bcb2: // 01ed:9de2
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_bcce() // 01ed:9dfe
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x008e;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    if (ax >= 0x0002)
        goto loc_bce5;
    ax = 0;
    goto loc_bdef;
loc_bce5: // 01ed:9e15
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x8000))
        goto loc_bd07;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    goto loc_bdef;
loc_bd07: // 01ed:9e37
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) & 0xfdff);
    ax = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ss, bp - 6, ax);
    goto loc_bd9e;
loc_bd26: // 01ed:9e56
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) - 1);
    bx = memoryAGet16(ss, bp - 12); es = memoryAGet16(ss, bp - 12 + 2);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 1);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 7, al);
    if (al != 0x0a)
        goto loc_bd43;
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet(es, bx, 0x0d);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_bd43: // 01ed:9e73
    bx = memoryAGet16(ss, bp - 4); es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(ss, bp - 7);
    memoryASet(es, bx, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    ax = bp - 142;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx = bx - 0x0000 - flags.carry;
    if ((short)bx < 0)
        goto loc_bda8;
    if (bx)
        goto loc_bd69;
    if (dx < 0x0080)
        goto loc_bda8;
loc_bd69: // 01ed:9e99
    ax = bp - 142;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx = bx - 0x0000 - flags.carry;
    si = dx;
    push(si);
    push(ss);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bd9e;
    if (!stop() /*ggg9*/)
        goto loc_bd94;
loc_bd8f: // 01ed:9ebf
    ax = 0xffff;
    goto loc_bdea;
loc_bd94: // 01ed:9ec4
    ax = memoryAGet16(ss, bp + 10);
    ax -= memoryAGet16(ss, bp - 6);
    goto loc_bde6;
    // gap 2 bytes
loc_bd9e: // 01ed:9ece
    ax = bp - 142;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, ss);
loc_bda8: // 01ed:9ed8
    if (memoryAGet16(ss, bp - 6) == 0x0000)
        goto loc_bdb1;
    goto loc_bd26;
loc_bdb1: // 01ed:9ee1
    ax = bp - 142;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx = bx - 0x0000 - flags.carry;
    si = dx;
    ax = dx;
    if (!ax)
        goto loc_bdec;
    push(si);
    push(ss);
    ax = bp - 142;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bdec;
    if (!stop() /*ggg9*/)
        goto loc_bde3;
    goto loc_bd8f;
loc_bde3: // 01ed:9f13
    ax = memoryAGet16(ss, bp + 10);
loc_bde6: // 01ed:9f16
    ax += di;
    ax -= si;
loc_bdea: // 01ed:9f1a
    goto loc_bdef;
loc_bdec: // 01ed:9f1c
    ax = memoryAGet16(ss, bp + 10);
loc_bdef: // 01ed:9f1f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_be68() // 01ed:9f98
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryAGet16(ss, bp + 10);
    ah = 0x43;
    al = memoryAGet(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 4); ds = memoryAGet16(ss, bp + 4 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_be7f;
    tx = cx; cx = ax; ax = tx;
    goto loc_be83;
loc_be7f: // 01ed:9faf
    push(ax);
    sub_c048();
loc_be83: // 01ed:9fb3
    bp = pop();
    sp += 2;
}
void sub_be85() // 01ed:9fb5
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x3e;
    bx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_be9d;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, 0xffff);
    ax = 0;
    goto loc_bea1;
loc_be9d: // 01ed:9fcd
    push(ax);
    sub_c048();
loc_bea1: // 01ed:9fd1
    bp = pop();
    sp += 2;
}
void sub_bf70() // 01ed:a0a0
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryAGet(ss, bp + 4);
    push(ds);
    dx = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    sp += 2;
}
void sub_bfb9() // 01ed:a0e9
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xa1fe, ax);
    push(cs);
    ax = 0xa0b1;
    push(ax);
    ax = 0x0024;
    push(ax);
    sub_bf70();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_c01f() // 01ed:a14f
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x44;
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 12);
    dx = memoryAGet16(ss, bp + 8); ds = memoryAGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c042;
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_c040;
    ax = dx;
    goto loc_c046;
loc_c040: // 01ed:a170
    goto loc_c046;
loc_c042: // 01ed:a172
    push(ax);
    sub_c048();
loc_c046: // 01ed:a176
    bp = pop();
    sp += 2;
}
void sub_c048() // 01ed:a178 +stackDrop2
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_c068;
    if ((short)si <= (short)0x0058)
        goto loc_c05b;
loc_c058: // 01ed:a188
    si = 0x0057;
loc_c05b: // 01ed:a18b
    memoryASet16(ds, 0x6b4e, si);
    al = memoryAGet(ds, si + 27472);
    cbw();
    si = ax;
    goto loc_c079;
loc_c068: // 01ed:a198
    ax = si;
    ax = -ax;
    si = ax;
    if ((short)si > (short)0x0023)
        goto loc_c058;
    memoryASet16(ds, 0x6b4e, 0xffff);
loc_c079: // 01ed:a1a9
    memoryASet16(ds, 0x007d, si);
    ax = 0xffff;
    si = pop();
    bp = pop();
    sp += 2;
    sp += 2;
}
void sub_c085() // 01ed:a1b5
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x4400;
    bx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    tx = dx; dx = ax; ax = tx;
    ax &= 0x0080;
    bp = pop();
    sp += 2;
}
void sub_c096() // 01ed:a1c6
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) & 0xfdff);
    ah = 0x42;
    al = memoryAGet(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c0b8;
    goto loc_c0bd;
loc_c0b8: // 01ed:a1e8
    push(ax);
    sub_c048();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_c0bd: // 01ed:a1ed
    bp = pop();
    sp += 2;
}
void sub_c0bf() // 01ed:a1ef +stackDrop6
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryAGet16(ss, bp + 4);
    ah = 0x3c;
    dx = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c0d2;
    goto loc_c0d6;
loc_c0d2: // 01ed:a202
    push(ax);
    sub_c048();
loc_c0d6: // 01ed:a206
    bp = pop();
    sp += 2;
    sp += 6;
}
void sub_c0da() // 01ed:a20a +stackDrop2
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    cx = 0;
    dx = 0;
    ah = 0x40;
    interrupt(0x21);
    bp = pop();
    sp += 2;
    sp += 2;
}
void sub_c0ec() // 01ed:a21c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    if (si & 0xc000)
        goto loc_c109;
    ax = memoryAGet16(ds, 0x6b44);
    ax &= 0xc000;
    dx = si;
    dx |= ax;
    si = dx;
loc_c109: // 01ed:a239
    if (si & 0x0100)
        goto loc_c112;
    goto loc_c196;
loc_c112: // 01ed:a242
    ax = memoryAGet16(ds, 0x6b46);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) & ax);
    ax = memoryAGet16(ss, bp + 10);
    if (ax & 0x0180)
        goto loc_c127;
    ax = 0x0001;
    push(ax);
    sub_c048();
loc_c127: // 01ed:a257
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0xffff)
        goto loc_c16a;
    if (!(memoryAGet16(ss, bp + 10) & 0x0080))
        goto loc_c149;
    ax = 0;
    goto loc_c14c;
loc_c149: // 01ed:a279
    ax = 0x0001;
loc_c14c: // 01ed:a27c
    memoryASet16(ss, bp - 2, ax);
    if (!(si & 0x00f0))
        goto loc_c181;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = 0;
    push(ax);
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c17a;
    goto loc_c228;
loc_c16a: // 01ed:a29a
    if (!(si & 0x0400))
        goto loc_c196;
    ax = 0x0050;
    push(ax);
    sub_c048();
    goto loc_c22a;
loc_c17a: // 01ed:a2aa
    push(di);
    sub_be85();
    cx = pop();
    goto loc_c19b;
loc_c181: // 01ed:a2b1
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp - 2));
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c207;
    goto loc_c228;
loc_c196: // 01ed:a2c6
    memoryASet16(ss, bp - 2, 0x0000);
loc_c19b: // 01ed:a2cb
    push(si);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c230();
    sp += 0x0006;
    di = ax;
    if ((short)ax < 0)
        goto loc_c207;
    ax = 0;
    push(ax);
    push(di);
    sub_c01f();
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    if (!(ax & 0x0080))
        goto loc_c1e0;
    si |= 0x2000;
    if (!(si & 0x8000))
        goto loc_c1ea;
    ax &= 0x00ff;
    ax |= 0x0020;
    dx = 0;
    push(dx);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(di);
    sub_c01f();
    sp += 0x0008;
    goto loc_c1ea;
loc_c1e0: // 01ed:a310
    if (!(si & 0x0200))
        goto loc_c1ea;
    push(di);
    sub_c0da();
loc_c1ea: // 01ed:a31a
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_c207;
    if (!(si & 0x00f0))
        goto loc_c207;
    ax = 0x0001;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0008;
loc_c207: // 01ed:a337
    if ((short)di < 0)
        goto loc_c228;
    if (!(si & 0x0300))
        goto loc_c216;
    ax = 0x1000;
    goto loc_c218;
loc_c216: // 01ed:a346
    ax = 0;
loc_c218: // 01ed:a348
    dx = si;
    dx &= 0xf8ff;
    dx |= ax;
    bx = di;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, dx);
loc_c228: // 01ed:a358
    ax = di;
loc_c22a: // 01ed:a35a
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c230() // 01ed:a360
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = 0x01;
    cx = memoryAGet16(ss, bp + 8);
    if (cx & 0x0002)
        goto loc_c24a;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_c24a;
    al = 0x00;
loc_c24a: // 01ed:a37a
    push(ds);
    dx = memoryAGet16(ss, bp + 4); ds = memoryAGet16(ss, bp + 4 + 2);
    cl = 0xf0;
    cl &= memoryAGet(ss, bp + 8);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c276;
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0xf8ff;
    ax |= 0x8000;
    memoryASet16(ds, bx + 27420, ax);
    ax = memoryAGet16(ss, bp - 2);
    goto loc_c27a;
loc_c276: // 01ed:a3a6
    push(ax);
    sub_c048();
loc_c27a: // 01ed:a3aa
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c27e() // 01ed:a3ae
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    if (ax < 0x0002)
        goto loc_c29c;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x0200))
        goto loc_c2a1;
loc_c29c: // 01ed:a3cc
    ax = 0;
    goto loc_c330;
loc_c2a1: // 01ed:a3d1
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    memoryASet16(ss, bp - 2, ax);
    ax++;
    if (ax < 0x0002)
        goto loc_c2c9;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x8000))
        goto loc_c2ce;
loc_c2c9: // 01ed:a3f9
    ax = memoryAGet16(ss, bp - 2);
    goto loc_c330;
loc_c2ce: // 01ed:a3fe
    cx = memoryAGet16(ss, bp - 2);
    si = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    di = si;
    bx = si;
    flags.direction = 0;
loc_c2d9: // 01ed:a409
    al = lodsb<ES_SI>();
    if (al == 0x1a)
        goto loc_c30d;
    if (al == 0x0d)
        goto loc_c2e8;
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_c2d9;
    goto loc_c305;
loc_c2e8: // 01ed:a418
    if (--cx)
        goto loc_c2d9;
    push(es);
    push(bx);
    ax = 0x0001;
    push(ax);
    ax = bp - 3;
    push(ss);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    bx = pop();
    es = pop();
    flags.direction = 0;
    al = memoryAGet(ss, bp - 3);
    stosb<ES_DI>(al);
loc_c305: // 01ed:a435
    if (di != bx)
        goto loc_c30b;
    goto loc_c2a1;
loc_c30b: // 01ed:a43b
    goto loc_c32d;
loc_c30d: // 01ed:a43d
    push(bx);
    ax = 0x0001;
    push(ax);
    cx = -cx;
    ax = -flags.carry;
    push(ax);
    push(cx);
    push(memoryAGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) | 0x0200);
    bx = pop();
loc_c32d: // 01ed:a45d
    di -= bx;
    tx = di; di = ax; ax = tx;
loc_c330: // 01ed:a460
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c336() // 01ed:a466
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x3f;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c34c;
    goto loc_c350;
loc_c34c: // 01ed:a47c
    push(ax);
    sub_c048();
loc_c350: // 01ed:a480
    bp = pop();
    sp += 2;
}
void sub_c352() // 01ed:a482
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x4a;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c366;
    ax = 0xffff;
    goto loc_c36c;
loc_c366: // 01ed:a496
    push(bx);
    push(ax);
    sub_c048();
    ax = pop();
loc_c36c: // 01ed:a49c
    bp = pop();
    sp += 2;
}
void sub_c36e() // 01ed:a49e
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x0800))
        goto loc_c391;
    ax = 0x0002;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
loc_c391: // 01ed:a4c1
    push(ds);
    ah = 0x40;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c3b1;
    push(ax);
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) | 0x1000);
    ax = pop();
    goto loc_c3b5;
loc_c3b1: // 01ed:a4e1
    push(ax);
    sub_c048();
loc_c3b5: // 01ed:a4e5
    bp = pop();
    sp += 2;
}
void sub_c3cc() // 01ed:a4fc
{
    if (dx == memoryAGet16(cs, 0xa4f0))
        goto loc_c40a;
    ds = dx;
    ds = memoryAGet16(ds, 0x0002);
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_c3e7;
    memoryASet16(cs, 0xa4f2, ds);
    goto loc_c41f;
loc_c3e7: // 01ed:a517
    ax = ds;
    if (ax == memoryAGet16(cs, 0xa4f0))
        goto loc_c405;
    ax = memoryAGet16(ds, 0x0008);
    memoryASet16(cs, 0xa4f2, ax);
    push(ds);
    ax = 0;
    push(ax);
    sub_c49f();
    ds = memoryAGet16(cs, 0xa4f6);
    goto loc_c428;
loc_c405: // 01ed:a535
    dx = memoryAGet16(cs, 0xa4f0);
loc_c40a: // 01ed:a53a
    memoryASet16(cs, 0xa4f0, 0x0000);
    memoryASet16(cs, 0xa4f2, 0x0000);
    memoryASet16(cs, 0xa4f4, 0x0000);
loc_c41f: // 01ed:a54f
    ds = memoryAGet16(cs, 0xa4f6);
    push(dx);
    ax = 0;
    push(ax);
loc_c428: // 01ed:a558
    sub_b82b();
    ax = pop();
    ax = pop();
}
void sub_c42e() // 01ed:a55e
{
    ds = dx;
    push(ds);
    es = memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, 0x0000);
    memoryASet16(ds, 0x0008, es);
    if (dx == memoryAGet16(cs, 0xa4f0))
        goto loc_c474;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_c474;
    ax = memoryAGet16(ds, 0x0000);
    bx = pop();
    push(es);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    cx = es;
    dx += ax;
    es = dx;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_c46d;
    memoryASet16(es, 0x0008, cx);
    goto loc_c477;
loc_c46d: // 01ed:a59d
    memoryASet16(es, 0x0002, cx);
    goto loc_c477;
loc_c474: // 01ed:a5a4
    sub_c4c8();
loc_c477: // 01ed:a5a7
    es = pop();
    ax = es;
    ax += memoryAGet16(es, 0x0000);
    ds = ax;
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_c489;
    return;
loc_c489: // 01ed:a5b9
    ax = memoryAGet16(ds, 0x0000);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    ax = es;
    bx = ds;
    bx += memoryAGet16(ds, 0x0000);
    es = bx;
    memoryASet16(es, 0x0002, ax);
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0: // 01ed:a5f0
    memoryASet16(cs, 0xa4f4, 0x0000);
}
void sub_c49f() // 01ed:a5cf
{
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0: // 01ed:a5f0
    memoryASet16(cs, 0xa4f4, 0x0000);
}
void sub_c4c8() // 01ed:a5f8
{
    ax = memoryAGet16(cs, 0xa4f4);
    if (!ax)
        goto loc_c4f0;
    bx = ss;
    flags.interrupts = 0;
    ss = ax;
    es = memoryAGet16(ss, 0x0006);
    memoryASet16(ss, 0x0006, ds);
    memoryASet16(ds, 0x0004, ss);
    ss = bx;
    flags.interrupts = 1;
    memoryASet16(es, 0x0004, ds);
    memoryASet16(ds, 0x0006, es);
    return;
loc_c4f0: // 01ed:a620
    memoryASet16(cs, 0xa4f4, ds);
    memoryASet16(ds, 0x0004, ds);
    memoryASet16(ds, 0x0006, ds);
}
void sub_c4fe() // 01ed:a62e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    memoryASet16(cs, 0xa4f6, ds);
    dx = memoryAGet16(ss, bp + 6);
    if (!dx)
        goto loc_c51e;
    if (dx != memoryAGet16(cs, 0xa4f2))
        goto loc_c51b;
    sub_c3cc();
    goto loc_c51e;
loc_c51b: // 01ed:a64b
    sub_c42e();
loc_c51e: // 01ed:a64e
    ds = memoryAGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_c527() // 01ed:a657
{
    push(ax);
    ds = memoryAGet16(cs, 0xa4f6);
    ax = 0;
    push(ax);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    ax &= 0x000f;
    if (!ax)
        goto loc_c54e;
    dx = 0x0010;
    dx -= ax;
    ax = 0;
    ds = memoryAGet16(cs, 0xa4f6);
    push(ax);
    push(dx);
    sub_b86a();
    bx = pop();
    bx = pop();
loc_c54e: // 01ed:a67e
    ax = pop();
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c584;
    memoryASet16(cs, 0xa4f0, dx);
    memoryASet16(cs, 0xa4f2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, dx);
    ax = 0x0004;
    return;
loc_c584: // 01ed:a6b4
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c588() // 01ed:a6b8
{
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c5bd;
    cx = memoryAGet16(cs, 0xa4f2);
    memoryASet16(cs, 0xa4f2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, cx);
    ax = 0x0004;
    return;
loc_c5bd: // 01ed:a6ed
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c5c1() // 01ed:a6f1
{
    bx = dx;
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) - ax);
    dx += memoryAGet16(ds, 0x0000);
    ds = dx;
    memoryASet16(ds, 0x0000, ax);
    memoryASet16(ds, 0x0002, bx);
    bx = dx;
    bx += memoryAGet16(ds, 0x0000);
    ds = bx;
    memoryASet16(ds, 0x0002, dx);
    ax = 0x0004;
}
void sub_c5e4() // 01ed:a714
{
    bool temp_cf;

    sp -= 2;
    push(bp);
    bp = sp;
    dx = 0;
    ax = memoryAGet16(ss, bp + 4);
    goto loc_c5f7;
    // gap 9 bytes
loc_c5f7: // 01ed:a727
    push(si);
    push(di);
    memoryASet16(cs, 0xa4f6, ds);
    cx = ax;
    cx |= dx;
    if (!cx)
        goto loc_c662;
    flags.carry = (ax + 0x0013) >= 0x10000;
    ax += 0x0013;
    temp_cf = (dx + 0x0000 + flags.carry) >= 0x10000;
    dx += 0x0000 + flags.carry;
    flags.carry = temp_cf;
    if (flags.carry)
        goto loc_c64d;
    if (dx & 0xfff0)
        goto loc_c64d;
    cl = 0x04;
    ax >>= cl;
    dx <<= cl;
    ah |= dl;
    dx = memoryAGet16(cs, 0xa4f0);
    if (!dx)
        goto loc_c643;
    dx = memoryAGet16(cs, 0xa4f4);
    if (!dx)
        goto loc_c63e;
    bx = dx;
loc_c62e: // 01ed:a75e
    ds = dx;
    if (memoryAGet16(ds, 0x0000) >= ax)
        goto loc_c652;
    dx = memoryAGet16(ds, 0x0006);
    if (dx != bx)
        goto loc_c62e;
loc_c63e: // 01ed:a76e
    sub_c588();
    goto loc_c662;
loc_c643: // 01ed:a773
    sub_c527();
    goto loc_c662;
loc_c648: // 01ed:a778
    sub_c5c1();
    goto loc_c662;
loc_c64d: // 01ed:a77d
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_c662;
loc_c652: // 01ed:a782
    if (memoryAGet16(ds, 0x0000) > ax)
        goto loc_c648;
    sub_c49f();
    bx = memoryAGet16(ds, 0x0008);
    memoryASet16(ds, 0x0002, bx);
    ax = 0x0004;
loc_c662: // 01ed:a792
    ds = memoryAGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_c7be() // 01ed:a8ee +stackDrop10 +nearAsFar
{
    sp -= 2;
    cx = pop();
    push(cs);
    push(cx);
    cx = 0x0001;
    goto loc_c7d4;
    // gap 14 bytes
loc_c7d4: // 01ed:a904
    push(bp);
    push(si);
    push(di);
    bp = sp;
    di = cx;
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 14);
    cx = memoryAGet16(ss, bp + 16);
    if (cx)
        goto loc_c7f3;
    if (!dx)
        goto loc_c858;
    if (!bx)
        goto loc_c858;
loc_c7f3: // 01ed:a923
    if (di & 0x0001)
        goto loc_c815;
    if ((short)dx >= 0)
        goto loc_c807;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
    di |= 0x000c;
loc_c807: // 01ed:a937
    if ((short)cx >= 0)
        goto loc_c815;
    cx = -cx;
    bx = -bx;
    cx = cx - 0x0000 - flags.carry;
    di ^= 0x0004;
loc_c815: // 01ed:a945
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_c81f: // 01ed:a94f
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl16(dx, 0x0001);
    si = rcl16(si, 0x0001);
    di = rcl16(di, 0x0001);
    if (di < bp)
        goto loc_c836;
    if (di > bp)
        goto loc_c831;
    if (si < bx)
        goto loc_c836;
loc_c831: // 01ed:a961
    flags.carry = si < bx;
    si -= bx;
    di = di - bp - flags.carry;
    ax++;
loc_c836: // 01ed:a966
    if (--cx)
        goto loc_c81f;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_c845;
    ax = si;
    dx = di;
    bx >>= 1;
loc_c845: // 01ed:a975
    if (!(bx & 0x0004))
        goto loc_c852;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
loc_c852: // 01ed:a982
    di = pop();
    si = pop();
    bp = pop();
//    stop("stack_below_retf, 10/6");
    sp += 2;
    cs = pop();
    sp += 8;
    return;
loc_c858: // 01ed:a988
    div16(bx);
    if (!(di & 0x0002))
        goto loc_c861;
    tx = dx; dx = ax; ax = tx;
loc_c861: // 01ed:a991
    dx = 0;
    goto loc_c852;
}
void sub_c865() // 01ed:a995 +stackDrop2 +nearAsFar
{
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    if ((short)cx >= 0)
        goto loc_c878;
    bx = ~bx;
    cx = ~cx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    cx += 0x0000 + flags.carry;
    goto loc_c8a7;
loc_c878: // 01ed:a9a8
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    if (!flags.carry)
        goto loc_c880;
    dx += 0x1000;
loc_c880: // 01ed:a9b0
    ch = cl;
    cl = 0x04;
    ch <<= cl;
    dh += ch;
    ch = al;
    ax >>= cl;
    dx += ax;
    al = ch;
    ax &= 0x000f;
    sp += 2;
    cs = pop();
    return;
    // gap 19 bytes
loc_c8a7: // 01ed:a9d7
    flags.carry = ax < bx;
    ax -= bx;
    if (!flags.carry)
        goto loc_c8af;
    dx -= 0x1000;
loc_c8af: // 01ed:a9df
    bh = cl;
    cl = 0x04;
    bh <<= cl;
    bl = 0;
    dx -= bx;
    ch = al;
    ax >>= cl;
    dx += ax;
    al = ch;
    ax &= 0x000f;
    sp += 2;
    cs = pop();
}
void sub_c8c5() // 01ed:a9f5 +stackDrop10 +nearAsFar
{
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    si = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2);
    di = memoryAGet16(ss, bp + 10); es = memoryAGet16(ss, bp + 10 + 2);
    flags.direction = 0;
    flags.carry = cx & 1;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cx += cx + flags.carry;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    //stop("stack_below_retf, 10/6");
    sp += 2;
    cs = pop();
    sp += 8;
}
void sub_c8e4() // 01ed:aa14
{
    push(si);
    tx = si; si = ax; ax = tx;
    tx = dx; dx = ax; ax = tx;
    if (!ax)
        goto loc_c8ed;
    mul16(bx);
loc_c8ed: // 01ed:aa1d
    if (cx==0)
        goto loc_c8f4;
    tx = cx; cx = ax; ax = tx;
    mul16(si);
    ax += cx;
loc_c8f4: // 01ed:aa24
    tx = si; si = ax; ax = tx;
    mul16(bx);
    dx += si;
    si = pop();
}
void sub_c8fb() // 01ed:aa2b +returnCarry +returnZero
{
    push(cx);
    ch = al;
    cl = 0x04;
    ax >>= cl;
    dx += ax;
    al = ch;
    ah = bl;
    bx >>= cl;
    cx = pop();
    cx += bx;
    bl = ah;
    ax &= 0x000f;
    bx &= 0x000f;
    flags.carry = dx < cx;
    flags.zero = dx == cx;
    if (!flags.zero)
        goto loc_c91b;
    flags.carry = ax < bx;
    flags.zero = ax == bx;
loc_c91b: // 01ed:aa4b
    return;
}
void sub_c91e() // 01ed:aa4e
{
    sp -= 2;
    goto loc_c91e;
loc_20ba: // 01ed:01ea
    cx = 0x001e;
    stop("stack_below", "01ed:01ea");
    dx = 0x003b;
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
    // gap 42998 bytes
loc_c91e: // 01ed:aa4e
    memoryASet16(ds, 0x6bb0, pop());
//    stop("stack_below", "01ed:aa4e");
    memoryASet16(ds, 0x6bb2, pop());
    memoryASet16(ds, 0x6bb4, pop());
    memoryASet16(cs, 0xaa4c, ds);
    memoryASet16(ds, 0x6bb6, si);
    memoryASet16(ds, 0x6bb8, di);
    flags.direction = 0;
    es = memoryAGet16(ds, 0x0079);
    si = 0x0080;
    ah = 0;
    al = lodsb<ES_SI>();
    ax++;
    bp = es;
    tx = si; si = dx; dx = tx;
    tx = bx; bx = ax; ax = tx;
    si = memoryAGet16(ds, 0x0073);
    si++;
    si++;
    cx = 0x0001;
    if (memoryAGet(ds, 0x007b) < 0x03)
        goto loc_c96a;
    es = memoryAGet16(ds, 0x0075);
    di = si;
    cl = 0x7f;
    al = 0;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    if (cx==0)
        goto loc_c9d5;
    cl ^= 0x7f;
loc_c96a: // 01ed:aa9a
    push(ax);
    ax = cx;
    ax += bx;
    ax++;
    ax &= 0xfffe;
    di = sp;
    flags.carry = di < ax;
    di -= ax;
    if (flags.carry)
        goto loc_c9d5;
    sp = di;
    push(es);
    ds = pop();
    push(ss);
    es = pop();
    push(cx);
    cx--;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    al = 0;
    stosb<ES_DI>(al);
    ds = bp;
    tx = dx; dx = si; si = tx;
    tx = cx; cx = bx; bx = tx;
    ax = bx;
    dx = ax;
    bx++;
loc_c991: // 01ed:aac1
    sub_c9ad();
    if (!flags.carry && !flags.zero)
        goto loc_c99d;
loc_c996: // 01ed:aac6
    if (flags.carry)
        goto loc_c9d8;
    sub_c9ad();
    if (!flags.carry && !flags.zero)
        goto loc_c996;
loc_c99d: // 01ed:aacd
    if (al == 0x20)
        goto loc_c9a9;
    if (al == 0x0d)
        goto loc_c9a9;
    if (al != 0x09)
        goto loc_c991;
loc_c9a9: // 01ed:aad9
    al = 0;
    goto loc_c991;
    // gap 40 bytes
loc_c9d5: // 01ed:ab05
    goto loc_20ba;
    stop("stack_below", "01ed:ab05");
loc_c9d8: // 01ed:ab08
    cx = pop();
    cx += dx;
    ds = memoryAGet16(cs, 0xaa4c);
    memoryASet16(ds, 0x6baa, bx);
    bx++;
    bx += bx;
    bx += bx;
    si = sp;
    bp = sp;
    flags.carry = bp < bx;
    bp -= bx;
    if (flags.carry)
        goto loc_c9d5;
    sp = bp;
    memoryASet16(ds, 0x6bac, bp);
    memoryASet16(ds, 0x6bae, ss);
loc_c9fb: // 01ed:ab2b
    if (cx==0)
        goto loc_ca0e;
    memoryASet16(ss, bp, si);
    memoryASet16(ss, bp + 2, ss);
    bp += 0x0004;
loc_ca06: // 01ed:ab36
    al = lodsb<SS_SI>();
    if (--cx && al)
        goto loc_ca06;
    if (!al)
        goto loc_c9fb;
loc_ca0e: // 01ed:ab3e
    ax = 0;
    memoryASet16(ss, bp, ax);
    memoryASet16(ss, bp + 2, ax);
    ds = memoryAGet16(cs, 0xaa4c);
    si = memoryAGet16(ds, 0x6bb6);
    di = memoryAGet16(ds, 0x6bb8);
    push(memoryAGet16(ds, 0x6bb4));
    push(memoryAGet16(ds, 0x6bb2));
    ax = memoryAGet16(ds, 0x6baa);
    memoryASet16(ds, 0x0069, ax);
    ax = memoryAGet16(ds, 0x6bae);
    memoryASet16(ds, 0x006d, ax);
    ax = memoryAGet16(ds, 0x6bac);
    memoryASet16(ds, 0x006b, ax);
//    stop(); //indirectJump(cs, memoryAGet16(ds, 0x6bb0)); return; // 01ed:ab6d;
}
void sub_c9ad() // 01ed:aadd +returnCarry +returnZero
{
    if (!ax)
        goto loc_c9b8;
    dx++;
    stosb<ES_DI>(al);
    if (al)
        goto loc_c9b8;
    bx++;
loc_c9b8: // 01ed:aae8
    tl = al; al = ah; ah = tl;
    flags.zero = 0;
    al = 0;
    flags.carry = 1;
    if (cx==0)
        goto loc_c9d4;
    al = lodsb<DS_SI>();
    cx--;
    flags.carry = al < 0x22;
    flags.zero = al == 0x22;
    al -= 0x22;
    if (flags.zero)
        goto loc_c9d4;
    al += 0x22;
    if (al != 0x5c)
        goto loc_c9d2;
    if (memoryAGet(ds, si) != 0x22)
        goto loc_c9d2;
    al = lodsb<DS_SI>();
    cx--;
loc_c9d2: // 01ed:ab02
    flags.carry = 0 /*ggg1*/;
    flags.zero = !si;
loc_c9d4: // 01ed:ab04
    return;
}
void sub_ca53() // 01ed:ab83
{
    sp -= 2;
    goto loc_ca53;
loc_1fe5: // 01ed:0115
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
    // gap 43613 bytes
loc_ca53: // 01ed:ab83
    push(cs);
    ds = pop();
    dx = 0xab71;
    ah = 0x09;
    interrupt(0x21);
    goto loc_1fe5;
}
void sub_ca60() // 0ca6:0000
{
    si = 0x4de6;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    push(es);
    sub_cf8d();
    ds = pop();
    si = bx;
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 19916);
    ds = pop();
    switch (ax)
    {
        case 0x002b: sub_ca8b(); break;
        default:
            stop("ind 0ca6:0028");
    }
}
void sub_ca61() // 0ca6:0001
{
    out8(0x4d, al);
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    push(es);
    sub_cf8d();
    ds = pop();
    si = bx;
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 19916);
    ds = pop();
    switch (ax)
    {
        case 0x002b: sub_ca8b(); break;
        default:
            stop("ind 0ca6:0028");
    }
}
void sub_ca8b() // 0ca6:002b
{
    bx = 0x0101;
loc_ca8e: // 0ca6:002e
    dx = 0x03c4;
    ah = bh;
    al = 0x02;
    out16(dx, ax);
    sub_d02f();
    sub_caa7();
    bl++;
    bh <<= 1;
    if ((char)bh > (char)0x08)
        goto loc_cad1;
    goto loc_ca8e;
    // gap 42 bytes
loc_cad1: // 0ca6:0071
    return;
}
void sub_caa7() // 0ca6:0047
{
    push(di);
    push(ds);
    bp = 0x1228;
    ds = bp;
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_cabd: // 0ca6:005d
    if (dl == ch)
        goto loc_cacf;
    dl--;
    cx >>= 1;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    cl = dh;
    di -= cx;
    di += bp;
    goto loc_cabd;
loc_cacf: // 0ca6:006f
    di = pop();
}
void sub_cbd9() // 0ca6:0179 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = 0;
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    memoryASet16(es, di + 24, 0x0014);
    memoryASet16(es, di + 26, 0x0019);
    memoryASet(ds, 0x541f, 0x02);
    memoryASet(ds, 0x5420, 0x01);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_cc0e(); break;
        case 2: sub_ca60(); break;
        case 4: sub_ca60(); break;
        case 6: sub_cc0f(); break;
        case 8: sub_cc10(); break;
        case 10: sub_ca60(); break;
        case 12: sub_ca60(); break;
        default:
            stop("ind 0ca6:01a4");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc0e() // 0ca6:01ae
{
}
void sub_cc0f() // 0ca6:01af
{
}
void sub_cc10() // 0ca6:01b0
{
}
void sub_cc41() // 0ca6:01e1 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    switch (bp)
    {
        case 0: sub_d065(); break;
        case 2: sub_d066(); break;
        case 4: sub_d080(); break;
        case 6: sub_d0ab(); break;
        case 8: sub_d0ac(); break;
        case 10: sub_d080(); break;
        case 12: sub_d0c1(); break;
        case 14: sub_d0c2(); break;
        case 16: sub_d0d7(); break;
        case 18: sub_d11d(); break;
        case 20: sub_d11e(); break;
        case 22: sub_d11f(); break;
        case 24: sub_ca60(); break;
        case 26: sub_ca61(); break;
        default:
            stop("ind 0ca6:01f3");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc5f() // 0ca6:01ff +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_cc6e;
        case 2: goto loc_cc6e;
        case 4: goto loc_cc6e;
        case 6: goto loc_cc75;
        case 8: goto loc_cc75;
        case 10: goto loc_cc75;
        default:
            stop("ind 0ca6:020a");
    }
loc_cc6e: // 0ca6:020e
    ax = 0x000d;
    interrupt(0x10);
    goto loc_cc75;
loc_cc75: // 0ca6:0215
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc7b() // 0ca6:021b +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x5313, dx);
    memoryASet16(ds, 0x5311, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc92() // 0ca6:0232 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if (cl != 0x00)
        goto loc_cc9e;
    goto loc_cd0b;
loc_cc9e: // 0ca6:023e
    if ((char)cl > (char)0x02)
        goto loc_cd0b;
    ax = 0x1228;
    ds = ax;
    es = ax;
    push(cx);
    di = 0x5310;
    cx = 0x0001;
    flags.direction = 0;
    al = 0;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cx = pop();
    si = 0x5415;
    ch = 0;
    cl--;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_ccc8;
        case 2: goto loc_ccc8;
        case 4: goto loc_ccc8;
        case 6: goto loc_ccf3;
        case 8: goto loc_ccf3;
        case 10: goto loc_ccc8;
        default:
            stop("ind 0ca6:0264");
    }
loc_ccc8: // 0ca6:0268
    memoryASet16(ds, si + 2, 0xa000);
    memoryASet16(ds, si, 0x0000);
    if (memoryAGet16(ds, 0x541d) != 0x0005)
        goto loc_cce7;
    memoryASet16(ds, si + 6, 0xa400);
    memoryASet16(ds, si + 4, 0x0000);
    sub_d02e();
    goto loc_cd0b;
loc_cce7: // 0ca6:0287
    memoryASet16(ds, si + 6, 0xa200);
    memoryASet16(ds, si + 4, 0x0000);
    goto loc_cd0b;
loc_ccf3: // 0ca6:0293
    if ((char)cl < (char)0x01)
        goto loc_cd0b;
loc_ccf8: // 0ca6:0298
    push(ax);
    push(dx);
    push(cs); cs = 0x0ec2; sub_ec20(); assert(cs == 0x0ca6);
    memoryASet16(ds, si + 2, dx);
    memoryASet16(ds, si, ax);
    si += 0x0004;
    dx = pop();
    ax = pop();
    if (--cx)
        goto loc_ccf8;
loc_cd0b: // 0ca6:02ab
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cd11() // 0ca6:02b1 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    switch (bp)
    {
        case 0: sub_d0c1(); break;
        case 2: sub_d0c2(); break;
        case 4: sub_d0d7(); break;
        case 6: sub_d11d(); break;
        case 8: sub_d11e(); break;
        case 10: sub_d11f(); break;
        default:
            stop("ind 0ca6:02c3");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cd2e() // 0ca6:02ce +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x0002;
    interrupt(0x10);
    si = 0x529c;
    bh = 0;
    dx = 0x0101;
    ah = 0x02;
    interrupt(0x10);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    si = 0x52b4;
    di = 0x548b;
    bh = 0x00;
    cx = 0x0006;
    dx = 0x0a21;
loc_cd5d: // 0ca6:02fd
    if (memoryAGet(ds, di) != 0x01)
        goto loc_cd70;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_cd70: // 0ca6:0310
    si += 0x000f;
    di++;
    if (--cx)
        goto loc_cd5d;
loc_cd76: // 0ca6:0316
    sync();
    al = 0x3c;
    push(cs); cs = 0x01ed; sub_9aca(); assert(cs == 0x0ca6);
    if (!flags.zero)
        goto loc_cd8a;
    al = 0x3d;
    push(cs); cs = 0x01ed; sub_9aca(); assert(cs == 0x0ca6);
    if (!flags.zero)
        goto loc_cd98;
    goto loc_cd76;
loc_cd8a: // 0ca6:032a
    memoryASet16(ds, 0x541d, 0x0001);
    memoryASet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
loc_cd98: // 0ca6:0338
    memoryASet16(ds, 0x541d, 0x0002);
    memoryASet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
    // gap 5 bytes
loc_cdab: // 0ca6:034b
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cdb1() // 0ca6:0351 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if (bx == 0x0000)
        goto loc_cdde;
    if ((short)bx > (short)0x0001)
        goto loc_cdde;
    ax = 0x1228;
    ds = ax;
    cx = 0;
    tl = memoryAGet(ds, bx + 21263); memoryASet(ds, bx + 21263, cl); cl = tl;
    si = 0x5415;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    switch (bp)
    {
        case 0: goto loc_cdd9;
        case 2: goto loc_cdd9;
        case 4: goto loc_cdd9;
        default:
            stop("ind 0ca6:0374");
    }
loc_cdd9: // 0ca6:0379
    sub_d121();
    goto loc_cdde;
loc_cdde: // 0ca6:037e
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ce87() // 0ca6:0427
{
    ax = memoryAGet16(es, di + 6);
    push(cx);
loc_ce8c: // 0ca6:042c
    cx >>= 1;
    if (!cx)
        goto loc_ce94;
    ax <<= 1;
    goto loc_ce8c;
loc_ce94: // 0ca6:0434
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0200))
        goto loc_cea4;
    ax++;
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0xfdff);
loc_cea4: // 0ca6:0444
    memoryASet16(ds, 0x5423, ax);
    ax = 0x0014;
    if (memoryAGet(ds, 0x541f) == 0x01)
        goto loc_ceb5;
    ax = memoryAGet16(es, di + 10);
loc_ceb5: // 0ca6:0455
    push(cx);
loc_ceb6: // 0ca6:0456
    cx >>= 1;
    if (!cx)
        goto loc_cebe;
    ax <<= 1;
    goto loc_ceb6;
loc_cebe: // 0ca6:045e
    cx = pop();
    memoryASet16(ds, 0x542b, ax);
    ax = memoryAGet16(es, di + 20);
    push(cx);
loc_cec7: // 0ca6:0467
    cx >>= 1;
    if (!cx)
        goto loc_cecf;
    ax <<= 1;
    goto loc_cec7;
loc_cecf: // 0ca6:046f
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0400))
        goto loc_cedf;
    ax++;
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0xfbff);
loc_cedf: // 0ca6:047f
    memoryASet16(ds, 0x5421, ax);
    ax = 0x0014;
    if (memoryAGet(ds, 0x5420) == 0x01)
        goto loc_cef0;
    ax = memoryAGet16(es, di + 24);
loc_cef0: // 0ca6:0490
    push(cx);
loc_cef1: // 0ca6:0491
    cx >>= 1;
    if (!cx)
        goto loc_cef9;
    ax <<= 1;
    goto loc_cef1;
loc_cef9: // 0ca6:0499
    cx = pop();
    memoryASet16(ds, 0x5429, ax);
    ax = memoryAGet16(es, di + 30);
    push(cx);
loc_cf02: // 0ca6:04a2
    cx >>= 1;
    if (!cx)
        goto loc_cf0a;
    ax <<= 1;
    goto loc_cf02;
loc_cf0a: // 0ca6:04aa
    cx = pop();
    memoryASet16(ds, 0x5431, ax);
    cx = 0x0008;
    ax = memoryAGet16(es, di + 8);
    push(cx);
loc_cf16: // 0ca6:04b6
    cx >>= 1;
    if (!cx)
        goto loc_cf1e;
    ax <<= 1;
    goto loc_cf16;
loc_cf1e: // 0ca6:04be
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0100))
        goto loc_cf31;
    ax += memoryAGet16(es, di + 38);
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0x00fe);
loc_cf31: // 0ca6:04d1
    memoryASet16(ds, 0x542f, ax);
    ax = 0x0019;
    if (memoryAGet(ds, 0x541f) == 0x01)
        goto loc_cf42;
    ax = memoryAGet16(es, di + 12);
loc_cf42: // 0ca6:04e2
    push(cx);
loc_cf43: // 0ca6:04e3
    cx >>= 1;
    if (!cx)
        goto loc_cf4b;
    ax <<= 1;
    goto loc_cf43;
loc_cf4b: // 0ca6:04eb
    cx = pop();
    memoryASet16(ds, 0x5427, ax);
    ax = memoryAGet16(es, di + 22);
    push(cx);
loc_cf54: // 0ca6:04f4
    cx >>= 1;
    if (!cx)
        goto loc_cf5c;
    ax <<= 1;
    goto loc_cf54;
loc_cf5c: // 0ca6:04fc
    cx = pop();
    memoryASet16(ds, 0x542d, ax);
    ax = 0x0019;
    if (memoryAGet(ds, 0x5420) == 0x01)
        goto loc_cf6e;
    ax = memoryAGet16(es, di + 26);
loc_cf6e: // 0ca6:050e
    push(cx);
loc_cf6f: // 0ca6:050f
    cx >>= 1;
    if (!cx)
        goto loc_cf77;
    ax <<= 1;
    goto loc_cf6f;
loc_cf77: // 0ca6:0517
    cx = pop();
    memoryASet16(ds, 0x5425, ax);
    ax = memoryAGet16(es, di + 32);
    push(cx);
loc_cf80: // 0ca6:0520
    cx >>= 1;
    if (!cx)
        goto loc_cf88;
    ax <<= 1;
    goto loc_cf80;
loc_cf88: // 0ca6:0528
    cx = pop();
    memoryASet16(ds, 0x5433, ax);
}
void sub_cf8d() // 0ca6:052d
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    bx = di;
    if (memoryAGet(ds, 0x541f) == 0x02)
        goto loc_cfd6;
    ax = memoryAGet16(ds, 0x542f);
    mul16(memoryAGet16(ds, 0x542b));
    ax += memoryAGet16(ds, 0x5423);
    si = ax;
    if (memoryAGet(ds, 0x541f) != 0x01)
        goto loc_cfbd;
    bp = memoryAGet16(es, bx);
    bp <<= 1;
    bp <<= 1;
    ax = memoryAGet16(ds, bp + 21525); ds = memoryAGet16(ds, bp + 21525 + 2);
    goto loc_cfc1;
loc_cfbd: // 0ca6:055d
    ax = memoryAGet16(es, bx + 2); ds = memoryAGet16(es, bx + 2 + 2);
loc_cfc1: // 0ca6:0561
    si += ax;
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(bx);
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    bx = pop();
    ds = dx;
    si = ax;
    es = pop();
loc_cfd6: // 0ca6:0576
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x542d);
    mul16(memoryAGet16(ds, 0x5429));
    ax += memoryAGet16(ds, 0x5421);
    di = ax;
    if (memoryAGet(ds, 0x5420) != 0x01)
        goto loc_d000;
    bp = memoryAGet16(es, bx + 14);
    bp <<= 1;
    bp <<= 1;
    ax = memoryAGet16(ds, bp + 21525); es = memoryAGet16(ds, bp + 21525 + 2);
    ds = pop();
    goto loc_d010;
loc_d000: // 0ca6:05a0
    {int tmp1 = memoryAGet16(es, bx + 16); int tmp2 = memoryAGet16(es, bx + 16 + 2); ax = tmp1; es = tmp2; /*ggg2!!check*/};
    ds = pop();
    di += ax;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    es = dx;
    di = ax;
loc_d010: // 0ca6:05b0
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_d016() // 0ca6:05b6
{
    dx = bx;
    dx <<= 1;
    dx <<= 1;
    ax = dx;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx += ax;
    ax <<= 1;
    ax += dx;
    ax -= bx;
}
void sub_d02e() // 0ca6:05ce
{
}
void sub_d02f() // 0ca6:05cf
{
    ax = 0;
    dl = memoryAGet(ds, si + 34);
    if (!(bh & dl))
        goto loc_d03a;
    al = 0x01;
loc_d03a: // 0ca6:05da
    dl = memoryAGet(ds, si + 35);
    if (!(bh & dl))
        goto loc_d043;
    al |= 0x02;
loc_d043: // 0ca6:05e3
    dl = memoryAGet(ds, si + 36);
    if (!(bh & dl))
        goto loc_d04c;
    al |= 0x04;
loc_d04c: // 0ca6:05ec
    dl = memoryAGet(ds, si + 37);
    if (!(bh & dl))
        goto loc_d055;
    al |= 0x08;
loc_d055: // 0ca6:05f5
    dl = al;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    al |= dl;
    ah = al;
}
void sub_d065() // 0ca6:0605
{
}
void sub_d066() // 0ca6:0606
{
    di = 0x5311;
    {int tmp1 = memoryAGet16(ds, di); int tmp2 = memoryAGet16(ds, di + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    si = ax;
    ds = dx;
    sub_d016();
    di += ax;
    di += 0x0023;
    si += 0x0023;
    cx = 0x0008;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
}
void sub_d080() // 0ca6:0620
{
    di = 0x5311;
    {int tmp1 = memoryAGet16(ds, di); int tmp2 = memoryAGet16(ds, di + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    si = ax;
    ds = dx;
    sub_d016();
    di += ax;
    di += 0x0033;
    si += 0x0033;
    push(ds);
    ax = 0x1228;
    ds = ax;
    if (memoryAGet16(ds, 0x541d) != 0x0005)
        goto loc_d0a4;
    di += 0x0030;
loc_d0a4: // 0ca6:0644
    ds = pop();
    cx = 0x0018;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
}
void sub_d0ab() // 0ca6:064b
{
}
void sub_d0ac() // 0ca6:064c
{
}
void sub_d0ad() // 0ca6:064d
{
    dx = 0x03ce;
    cx = 0x0007;
loc_d0b3: // 0ca6:0653
    ax = lodsw<DS_SI>();
    out16(dx, ax);
    if (--cx)
        goto loc_d0b3;
    dx = 0x03c4;
    ax = memoryAGet16(ds, si);
    out16(dx, ax);
}
void sub_d0bf() // 0ca6:065f
{
}
void sub_d0c1() // 0ca6:0661
{
}
void sub_d0c2() // 0ca6:0662
{
    si = 0x5311;
    {int tmp1 = memoryAGet16(ds, si); int tmp2 = memoryAGet16(ds, si + 2); si = tmp1; es = tmp2; /*ggg2!!check*/};
    sub_d016();
    si += ax;
    si += 0x0023;
    dx = si;
    ax = 0x1002;
    interrupt(0x10);
}
void sub_d0d7() // 0ca6:0677
{
    si = 0x5311;
    {int tmp1 = memoryAGet16(ds, si); int tmp2 = memoryAGet16(ds, si + 2); si = tmp1; es = tmp2; /*ggg2!!check*/};
    sub_d016();
    si += ax;
    si += 0x0033;
    dx = 0x03c8;
    al = 0x00;
    out8(dx, al);
    dx++;
    cx = 0x0008;
loc_d0ee: // 0ca6:068e
    al = memoryAGet(es, si);
    out8(dx, al);
    al = memoryAGet(es, si + 1);
    out8(dx, al);
    al = memoryAGet(es, si + 2);
    out8(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d0ee;
    dx--;
    al = 0x10;
    out8(dx, al);
    dx++;
    cx = 0x0008;
loc_d109: // 0ca6:06a9
    al = memoryAGet(es, si);
    out8(dx, al);
    al = memoryAGet(es, si + 1);
    out8(dx, al);
    al = memoryAGet(es, si + 2);
    out8(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d109;
}
void sub_d11d() // 0ca6:06bd
{
}
void sub_d11e() // 0ca6:06be
{
}
void sub_d11f() // 0ca6:06bf
{
}
void sub_d121() // 0ca6:06c1
{
    flags.interrupts = 0;
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx++;
    al = in8(dx);
    ah = 0x20;
    al ^= ah;
    out8(dx, al);
    flags.interrupts = 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, si + 2);
    tx = memoryAGet16(ds, bx + si + 2); memoryASet16(ds, bx + si + 2, ax); ax = tx;
    memoryASet16(ds, si + 2, ax);
}
void sub_d250() // 0ca6:07f0
{
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x542b);
    mul16(memoryAGet16(ds, 0x5427));
    bp = ax;
    ax = memoryAGet16(ds, 0x5429);
    mul16(memoryAGet16(ds, 0x5425));
    bx = ax;
    ax = memoryAGet16(es, di + 28);
    sub_cf8d();
    push(bx);
    push(ds);
    bx = ax;
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 21814);
    ds = pop();
    bx = pop();
    switch (ax)
    {
        case 0x0823: sub_d283(); break;
        case 0x0990: sub_d3f0(); break;
        case 0x091e: sub_d37e(); break;
        case 0x0927: sub_d387(); break;
        case 0x091f: sub_d37f(); break;
        case 0x092f: sub_d38f(); break;
        case 0x0892: sub_d2f2(); break;
        case 0x0991: sub_d3f1(); break;
        case 0x07f0: sub_d250(); break;
        case 0x0997: sub_d3f7(); break;
        case 0x0998: sub_d3f8(); break;
        case 0x0999: sub_d3f9(); break;
        case 0x0ad0: sub_d530(); break;
        case 0x0c7f: sub_d6df(); break;
        case 0x0b3c: sub_d59c(); break;
        case 0x0c05: sub_d665(); break;
        case 0x0bfd: sub_d65d(); break;
        case 0x0c0d: sub_d66d(); break;
        case 0x0b33: sub_d593(); break;
        case 0x0c80: sub_d6e0(); break;
        case 0x0aa0: sub_d500(); break;
        case 0x0c86: sub_d6e6(); break;
        case 0x0c87: sub_d6e7(); break;
        case 0x0c88: sub_d6e8(); break;
        default:
            stop("ind 0ca6:0820");
    }
}
void sub_d283() // 0ca6:0823
{
    flags.direction = 0;
    ax = 0;
loc_d286: // 0ca6:0826
    sub_d2b8();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d2f1;
    si += bp;
    di += bx;
    push(ax);
    push(bx);
    push(dx);
    push(di);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    ds = dx;
    si = ax;
    es = pop();
    di = pop();
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    es = dx;
    di = ax;
    dx = pop();
    bx = pop();
    ax = pop();
    goto loc_d286;
    // gap 57 bytes
loc_d2f1: // 0ca6:0891
    return;
}
void sub_d2b8() // 0ca6:0858
{
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d2d5: // 0ca6:0875
    if (dl == 0x00)
        goto loc_d2ec;
    dl--;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += bp;
    goto loc_d2d5;
loc_d2ec: // 0ca6:088c
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
}
void sub_d2f2() // 0ca6:0892
{
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x5429);
    memoryASet16(cs, 0x0a9c, ax);
    ax = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx==0)
        goto loc_d37d;
loc_d30f: // 0ca6:08af
    if (dl == 0x00)
        goto loc_d37d;
    dl--;
    cx >>= 1;
    push(ax);
    push(dx);
loc_d31a: // 0ca6:08ba
    dx = memoryAGet16(ds, si);
    si += bp;
    di += bx;
    dx |= memoryAGet16(ds, si);
    si += bp;
    di += bx;
    dx |= memoryAGet16(ds, si);
    si += bp;
    di += bx;
    dx |= memoryAGet16(ds, si);
    dx = ~dx;
    ax = memoryAGet16(es, di);
    ax &= dx;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si -= bp;
    di -= bx;
    ax = memoryAGet16(es, di);
    ax &= dx;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si -= bp;
    di -= bx;
    ax = memoryAGet16(es, di);
    ax &= dx;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si -= bp;
    di -= bx;
    ax = memoryAGet16(es, di);
    ax &= dx;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_d31a;
    dx = pop();
    ax = pop();
    cl = dh;
    si -= cx;
    di -= cx;
    si += ax;
    di += memoryAGet16(cs, 0x0a9c);
    goto loc_d30f;
loc_d37d: // 0ca6:091d
    return;
}
void sub_d37e() // 0ca6:091e
{
}
void sub_d37f() // 0ca6:091f
{
    memoryASet(cs, 0x0973, 0x21);
    goto loc_d395;
    // gap 14 bytes
loc_d395: // 0ca6:0935
    ax = 0;
loc_d397: // 0ca6:0937
    sub_d3a7();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d3ef;
    si += bp;
    di += bx;
    goto loc_d397;
    // gap 72 bytes
loc_d3ef: // 0ca6:098f
    return;
}
void sub_d387() // 0ca6:0927
{
    memoryASet(cs, 0x0973, 0x09);
    goto loc_d395;
    // gap 6 bytes
loc_d395: // 0ca6:0935
    ax = 0;
loc_d397: // 0ca6:0937
    sub_d3a7();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d3ef;
    si += bp;
    di += bx;
    goto loc_d397;
    // gap 72 bytes
loc_d3ef: // 0ca6:098f
    return;
}
void sub_d38f() // 0ca6:092f
{
    memoryASet(cs, 0x0973, 0x31);
    ax = 0;
loc_d397: // 0ca6:0937
    sub_d3a7();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d3ef;
    si += bp;
    di += bx;
    goto loc_d397;
    // gap 72 bytes
loc_d3ef: // 0ca6:098f
    return;
}
void sub_d3a7() // 0ca6:0947
{
    push(ax);
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx==0)
        goto loc_d3e9;
loc_d3c7: // 0ca6:0967
    if (dl == 0x00)
        goto loc_d3e9;
    dl--;
    cx >>= 1;
loc_d3d0: // 0ca6:0970
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_d3d0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += bp;
    goto loc_d3c7;
loc_d3e9: // 0ca6:0989
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    ax = pop();
}
void sub_d3f0() // 0ca6:0990
{
}
void sub_d3f1() // 0ca6:0991
{
}
void sub_d3f7() // 0ca6:0997
{
}
void sub_d3f8() // 0ca6:0998
{
}
void sub_d3f9() // 0ca6:0999
{
}
void sub_d4d3() // 0ca6:0a73 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = 0;
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    memoryASet(ds, 0x541f, 0x00);
    memoryASet(ds, 0x5420, 0x00);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_d3f1(); break;
        case 2: sub_d250(); break;
        case 4: sub_d250(); break;
        case 6: sub_d3f7(); break;
        case 8: sub_d3f8(); break;
        case 10: sub_d3f9(); break;
        case 12: sub_d530(); break;
        case 14: sub_d6df(); break;
        case 16: sub_d59c(); break;
        case 18: sub_d665(); break;
        case 20: sub_d65d(); break;
        case 22: sub_d66d(); break;
        case 24: sub_d593(); break;
        case 26: sub_d6e0(); break;
        case 28: sub_d500(); break;
        case 30: sub_d500(); break;
        case 32: sub_d6e6(); break;
        case 34: sub_d6e7(); break;
        case 36: sub_d6e8(); break;
        default:
            stop("ind 0ca6:0a92");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_d500() // 0ca6:0aa0
{
    si = 0x556a;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x542b);
    mul16(memoryAGet16(ds, 0x5427));
    bp = ax;
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 21840);
    ds = pop();
    switch (ax)
    {
        case 0x0ad0: sub_d530(); break;
        case 0x0c7f: sub_d6df(); break;
        case 0x0b3c: sub_d59c(); break;
        case 0x0c05: sub_d665(); break;
        case 0x0bfd: sub_d65d(); break;
        case 0x0c0d: sub_d66d(); break;
        case 0x0b33: sub_d593(); break;
        case 0x0c80: sub_d6e0(); break;
        default:
            stop("ind 0ca6:0acd");
    }
}
void sub_d530() // 0ca6:0ad0
{
    flags.direction = 0;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x01;
loc_d539: // 0ca6:0ad9
    dx = 0x03c5;
    out8(dx, al);
    goto loc_d560;
loc_d53f: // 0ca6:0adf
    al <<= 1;
    if ((char)al > (char)0x08)
        goto loc_d592;
    si += bp;
    push(ax);
    push(bx);
    push(di);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    ds = dx;
    si = ax;
    es = pop();
    di = pop();
    bx = pop();
    ax = pop();
    goto loc_d539;
loc_d560: // 0ca6:0b00
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d577: // 0ca6:0b17
    if (dl == ch)
        goto loc_d58e;
    dl--;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d577;
loc_d58e: // 0ca6:0b2e
    di = pop();
    si = pop();
    goto loc_d53f;
loc_d592: // 0ca6:0b32
    return;
}
void sub_d593() // 0ca6:0b33
{
    memoryASet16(cs, 0x0b81, 0x9090);
    goto loc_d5a3;
    // gap 7 bytes
loc_d5a3: // 0ca6:0b43
    dx = 0x03c4;
    ax = 0x0002;
    out16(dx, ax);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx==0)
        goto loc_d5c3;
    goto loc_d5c6;
loc_d5c3: // 0ca6:0b63
    goto loc_d65c;
loc_d5c6: // 0ca6:0b66
    if (dl != ch)
        goto loc_d5cd;
    goto loc_d65c;
loc_d5cd: // 0ca6:0b6d
    dl--;
    cx >>= 1;
    push(dx);
loc_d5d2: // 0ca6:0b72
    ax = memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    push(si);
//    stop("mark 0ca6:0b81, addr 0ca6:0b80, instr: push si, bytes: 56", "0ca6:0b80");
//    stop("mark 0ca6:0b81, addr 0ca6:0b81, instr: nop , bytes: 90mark 0ca6:0b82, addr 0ca6:0b81, instr: nop , bytes: 90", "0ca6:0b81");
//    stop("mark 0ca6:0b82, addr 0ca6:0b82, instr: nop , bytes: 90", "0ca6:0b82");
    ch = ah;
    ah = al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out8(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    movsb<ES_DI, DS_SI>();
    ah = ch;
    si = pop();
    si++;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out8(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    movsb<ES_DI, DS_SI>();
    cl--;
    if (cl)
        goto loc_d5d2;
    dx = pop();
    ch = 0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d5c6;
loc_d65c: // 0ca6:0bfc
    return;
}
void sub_d59c() // 0ca6:0b3c
{
    memoryASet16(cs, 0x0b81, 0xd0f7);
    dx = 0x03c4;
    ax = 0x0002;
    out16(dx, ax);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx==0)
        goto loc_d5c3;
    goto loc_d5c6;
loc_d5c3: // 0ca6:0b63
    goto loc_d65c;
loc_d5c6: // 0ca6:0b66
    if (dl != ch)
        goto loc_d5cd;
    goto loc_d65c;
loc_d5cd: // 0ca6:0b6d
    dl--;
    cx >>= 1;
    push(dx);
loc_d5d2: // 0ca6:0b72
    ax = memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    push(si);
    stop("mark 0ca6:0b81, addr 0ca6:0b80, instr: push si, bytes: 56", "0ca6:0b80");
    stop("mark 0ca6:0b81, addr 0ca6:0b81, instr: nop , bytes: 90mark 0ca6:0b82, addr 0ca6:0b81, instr: nop , bytes: 90", "0ca6:0b81");
    stop("mark 0ca6:0b82, addr 0ca6:0b82, instr: nop , bytes: 90", "0ca6:0b82");
    ch = ah;
    ah = al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out8(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    movsb<ES_DI, DS_SI>();
    ah = ch;
    si = pop();
    si++;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out8(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out8(dx, al);
    si -= bp;
    movsb<ES_DI, DS_SI>();
    cl--;
    if (cl)
        goto loc_d5d2;
    dx = pop();
    ch = 0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d5c6;
loc_d65c: // 0ca6:0bfc
    return;
}
void sub_d65d() // 0ca6:0bfd
{
    memoryASet(cs, 0x0c63, 0x21);
    goto loc_d673;
    // gap 14 bytes
loc_d673: // 0ca6:0c13
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683: // 0ca6:0c23
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_d69e();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_d6de;
    si += bp;
    goto loc_d683;
    // gap 64 bytes
loc_d6de: // 0ca6:0c7e
    return;
}
void sub_d665() // 0ca6:0c05
{
    memoryASet(cs, 0x0c63, 0x09);
    goto loc_d673;
    // gap 6 bytes
loc_d673: // 0ca6:0c13
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683: // 0ca6:0c23
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_d69e();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_d6de;
    si += bp;
    goto loc_d683;
    // gap 64 bytes
loc_d6de: // 0ca6:0c7e
    return;
}
void sub_d66d() // 0ca6:0c0d
{
    memoryASet(cs, 0x0c63, 0x31);
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683: // 0ca6:0c23
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_d69e();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_d6de;
    si += bp;
    goto loc_d683;
    // gap 64 bytes
loc_d6de: // 0ca6:0c7e
    return;
}
void sub_d69e() // 0ca6:0c3e
{
    push(ax);
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx==0)
        goto loc_d6da;
loc_d6b8: // 0ca6:0c58
    if (dl == ch)
        goto loc_d6da;
    dl--;
    cx >>= 1;
loc_d6c0: // 0ca6:0c60
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_d6c0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d6b8;
loc_d6da: // 0ca6:0c7a
    di = pop();
    si = pop();
    ax = pop();
}
void sub_d6df() // 0ca6:0c7f
{
}
void sub_d6e0() // 0ca6:0c80
{
}
void sub_d6e6() // 0ca6:0c86
{
}
void sub_d6e7() // 0ca6:0c87
{
}
void sub_d6e8() // 0ca6:0c88
{
}
void sub_d7d7() // 0ca6:0d77 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bp = memoryAGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_d802;
    memoryASet(ds, 0x541f, 0x00);
    memoryASet(ds, 0x5420, 0x01);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_d6e0(); break;
        case 2: sub_d500(); break;
        case 4: sub_d500(); break;
        case 6: sub_d6e6(); break;
        case 8: sub_d6e7(); break;
        case 10: sub_d6e8(); break;
        default:
            stop("ind 0ca6:0d9e");
    }
loc_d802: // 0ca6:0da2
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_d810() // 0ca6:0db0
{
    si = 0x56a4;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x5429);
    mul16(memoryAGet16(ds, 0x5425));
    bp = ax;
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 22154);
    ds = pop();
    switch (bx)
    {
        case 0: sub_d840(); break;
        default:
            stop("ind 0ca6:0ddd");
    }
}
void sub_d840() // 0ca6:0de0
{
    flags.direction = 0;
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    al = 0x00;
loc_d849: // 0ca6:0de9
    dx = 0x03cf;
    out8(dx, al);
    sub_d869();
    al++;
    if ((char)al > (char)0x03)
        goto loc_d89b;
    di += bp;
    push(ax);
    push(bx);
    push(dx);
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0ca6);
    es = dx;
    di = ax;
    dx = pop();
    bx = pop();
    ax = pop();
    goto loc_d849;
    // gap 50 bytes
loc_d89b: // 0ca6:0e3b
    return;
}
void sub_d869() // 0ca6:0e09
{
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d880: // 0ca6:0e20
    if (dl == 0x00)
        goto loc_d898;
    dl--;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += bx;
    goto loc_d880;
loc_d898: // 0ca6:0e38
    di = pop();
    si = pop();
}
void sub_d996() // 0ca6:0f36
{
}
void sub_d99c() // 0ca6:0f3c
{
}
void sub_d99d() // 0ca6:0f3d
{
}
void sub_d99e() // 0ca6:0f3e
{
}
void sub_da88() // 0ca6:1028 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bp = memoryAGet16(es, di);
    if ((short)bp > (short)0x0001)
        goto loc_dab2;
    memoryASet(ds, 0x541f, 0x01);
    memoryASet(ds, 0x5420, 0x00);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_d996(); break;
        case 2: sub_d810(); break;
        case 4: sub_d810(); break;
        case 6: sub_d99c(); break;
        case 8: sub_d99d(); break;
        case 10: sub_d99e(); break;
        default:
            stop("ind 0ca6:104e");
    }
loc_dab2: // 0ca6:1052
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_dac0() // 0ca6:1060
{
    si = 0x56ce;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 22196);
    ds = pop();
    switch (ax)
    {
        case 0x1087: sub_dae7(); break;
        case 0x11d5: sub_dc35(); break;
        case 0x1156: sub_dbb6(); break;
        case 0x115f: sub_dbbf(); break;
        case 0x1157: sub_dbb7(); break;
        case 0x1167: sub_dbc7(); break;
        case 0x10b8: sub_db18(); break;
        case 0x11d6: sub_dc36(); break;
        default:
            stop("ind 0ca6:1084");
    }
}
void sub_dae7() // 0ca6:1087
{
    flags.direction = 0;
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    push(ds);
    ax = 0x1228;
    ds = ax;
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_db00: // 0ca6:10a0
    if (dl == 0x00)
        goto loc_db17;
    dl--;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += 0x0028;
    goto loc_db00;
loc_db17: // 0ca6:10b7
    return;
}
void sub_db18() // 0ca6:10b8
{
    dx = 0x03ce;
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    bh = cl;
    ds = pop();
    if (cx==0)
        goto loc_db30;
    goto loc_db33;
loc_db30: // 0ca6:10d0
    goto loc_dbb5;
loc_db33: // 0ca6:10d3
    dx = 0x03ce;
loc_db36: // 0ca6:10d6
    if (bl == 0x00)
        goto loc_dbb5;
    bl--;
    cx >>= 1;
loc_db3f: // 0ca6:10df
    ax = 0x0805;
    out16(dx, ax);
    ax = memoryAGet16(ds, si);
    bp = ax;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0004;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    ax = memoryAGet16(es, di);
    ax &= bp;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    ax = 0x0202;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0104;
    out16(dx, ax);
    ax = memoryAGet16(es, di);
    ax &= bp;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    ax = 0x0204;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0402;
    out16(dx, ax);
    ax = memoryAGet16(es, di);
    ax &= bp;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    ax = 0x0802;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0304;
    out16(dx, ax);
    ax = memoryAGet16(es, di);
    ax &= bp;
    ax |= memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_db3f;
    cl = bh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += 0x0028;
    goto loc_db36;
loc_dbb5: // 0ca6:1155
    return;
}
void sub_dbb6() // 0ca6:1156
{
}
void sub_dbb7() // 0ca6:1157
{
    memoryASet(cs, 0x11b8, 0x21);
    goto loc_dbcd;
    // gap 14 bytes
loc_dbcd: // 0ca6:116d
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_dbdd: // 0ca6:117d
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_dbf6();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_dc34;
    goto loc_dbdd;
    // gap 62 bytes
loc_dc34: // 0ca6:11d4
    return;
}
void sub_dbbf() // 0ca6:115f
{
    memoryASet(cs, 0x11b8, 0x09);
    goto loc_dbcd;
    // gap 6 bytes
loc_dbcd: // 0ca6:116d
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_dbdd: // 0ca6:117d
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_dbf6();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_dc34;
    goto loc_dbdd;
    // gap 62 bytes
loc_dc34: // 0ca6:11d4
    return;
}
void sub_dbc7() // 0ca6:1167
{
    memoryASet(cs, 0x11b8, 0x31);
    dx = 0x03ce;
    al = 0x04;
    out8(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x00;
    ah = 0x01;
loc_dbdd: // 0ca6:117d
    dx = 0x03cf;
    out8(dx, al);
    tl = ah; ah = al; al = tl;
    dx = 0x03c5;
    out8(dx, al);
    tl = al; al = ah; ah = tl;
    sub_dbf6();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_dc34;
    goto loc_dbdd;
    // gap 62 bytes
loc_dc34: // 0ca6:11d4
    return;
}
void sub_dbf6() // 0ca6:1196
{
    push(ax);
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    if (cx==0)
        goto loc_dc30;
    ds = pop();
loc_dc0c: // 0ca6:11ac
    if (dl == 0x00)
        goto loc_dc30;
    dl--;
    cx >>= 1;
loc_dc15: // 0ca6:11b5
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_dc15;
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += 0x0028;
    goto loc_dc0c;
loc_dc30: // 0ca6:11d0
    di = pop();
    si = pop();
    ax = pop();
    stop("stack_unbalanced");
}
void sub_dc35() // 0ca6:11d5
{
}
void sub_dc36() // 0ca6:11d6
{
}
void sub_dc3c() // 0ca6:11dc
{
}
void sub_dc3d() // 0ca6:11dd
{
}
void sub_dc3e() // 0ca6:11de
{
}
void sub_dcce() // 0ca6:126e +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bx = memoryAGet16(es, di);
    if ((short)bx > (short)0x0001)
        goto loc_dd01;
    bp = memoryAGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_dd01;
    memoryASet(ds, 0x541f, 0x01);
    memoryASet(ds, 0x5420, 0x01);
    si = memoryAGet16(ds, 0x541d);
    si <<= 1;
    switch (si)
    {
        case 0: sub_dc36(); break;
        case 2: sub_dac0(); break;
        case 4: sub_dac0(); break;
        case 6: sub_dc3c(); break;
        case 8: sub_dc3d(); break;
        case 10: sub_dc3e(); break;
        default:
            stop("ind 0ca6:129d");
    }
loc_dd01: // 0ca6:12a1
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_dd71() // 0ca6:1311 +nearfar +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_df4e(); break;
        case 2: sub_df4f(); break;
        case 4: sub_df4f(); break;
        case 6: sub_df8f(); break;
        case 8: sub_df8e(); break;
        case 10: sub_df4f(); break;
        default:
            stop("ind 0ca6:1321");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_dd8b() // 0ca6:132b +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x68a4, dx);
    memoryASet16(ds, 0x68a2, ax);
    di = 0x68a2;
    bx = memoryAGet16(ds, di + 2);
    es = bx;
    di = memoryAGet16(ds, di);
    al = memoryAGet(es, di + 3);
    al += 0x02;
    memoryASet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_dddb() // 0ca6:137b +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x000a;
    dx = 0x000a;
    push(cs);
    sub_dea1();
    ax = 0x0000;
    bx = 0x0000;
    cx = 0x013f;
    dx = 0x00c7;
    push(cs);
    sub_de82();
    bx = 0x0000;
    push(cs);
    sub_de69();
    al = 0x08;
    push(cs);
    sub_deb8();
    ax = 0x000f;
    dx = 0x0000;
    push(cs);
    sub_dd71();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de1c() // 0ca6:13bc +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = 0;
    bx = 0x1228;
    ds = bx;
    di = 0x68a2;
    bx = memoryAGet16(ds, di + 2);
    es = bx;
    di = memoryAGet16(ds, di);
    if (al < memoryAGet(es, di))
        goto loc_de46;
    if (al >= memoryAGet(es, di + 1))
        goto loc_de46;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_e066(); break;
        case 2: sub_e067(); break;
        case 4: sub_e067(); break;
        case 6: sub_e142(); break;
        case 8: sub_e141(); break;
        case 10: sub_e067(); break;
        default:
            stop("ind 0ca6:13e2");
    }
loc_de46: // 0ca6:13e6
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de4c() // 0ca6:13ec +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = 0;
    ds = dx;
    si = ax;
loc_de56: // 0ca6:13f6
    al = memoryAGet(ds, si);
    if (al == 0x00)
        goto loc_de63;
    push(cs);
    sub_de1c();
    si++;
    goto loc_de56;
loc_de63: // 0ca6:1403
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de69() // 0ca6:1409 +nearfar +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if ((short)bx > (short)0x0001)
        goto loc_de7c;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x6940, bx);
loc_de7c: // 0ca6:141c
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_de82() // 0ca6:1422 +nearfar +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memoryASet16(ds, 0x6936, ax);
    memoryASet16(ds, 0x6938, bx);
    memoryASet16(ds, 0x693a, cx);
    memoryASet16(ds, 0x693c, dx);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_dea1() // 0ca6:1441 +nearfar +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x6944, dx);
    memoryASet16(ds, 0x6942, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_deb8() // 0ca6:1458 +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_deee() // 0ca6:148e
{
    si = 0x695e;
    memoryASet16(ds, si, 0x68b6);
    memoryASet16(ds, si + 2, ds);
    bp = memoryAGet16(ds, 0x6940);
    bp <<= 1;
    bp <<= 1;
    ax += memoryAGet16(ds, bp + 21525);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, bp + 21527);
    memoryASet16(ds, si + 10, ax);
    ax = 0;
    al = bl;
    memoryASet16(ds, si + 12, ax);
    al = bh;
    memoryASet16(ds, si + 14, ax);
    al = cl;
    memoryASet16(ds, si + 16, ax);
    al = ch;
    memoryASet16(ds, si + 18, ax);
    memoryASet(ds, si + 22, dl);
    dx = ds;
    ax = si;
    push(cs); cs = 0x0ed9; sub_11aa5(); assert(cs == 0x0ca6);
}
void sub_df33() // 0ca6:14d3
{
    al -= memoryAGet(es, di);
    ah = 0;
    ax <<= 1;
    bx = es;
    ds = bx;
    si = di;
    si += 0x0006;
    si += ax;
    ax = memoryAGet16(ds, si);
    tl = al; al = ah; ah = tl;
    ax += di;
    si = ax;
}
void sub_df4e() // 0ca6:14ee
{
}
void sub_df4f() // 0ca6:14ef
{
    si = 0x68a6;
    sub_df5f();
    si = 0x68ae;
    ax = dx;
    sub_df5f();
    goto loc_df8d;
    // gap 46 bytes
loc_df8d: // 0ca6:152d
    return;
}
void sub_df5f() // 0ca6:14ff
{
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 2, 0x0000);
    if (!(ax & 0x0001))
        goto loc_df70;
    memoryASet(ds, si, 0xff);
loc_df70: // 0ca6:1510
    if (!(ax & 0x0002))
        goto loc_df79;
    memoryASet(ds, si + 1, 0xff);
loc_df79: // 0ca6:1519
    if (!(ax & 0x0004))
        goto loc_df84;
    memoryASet(ds, si + 2, 0xff);
    if (!(ax & 0x0004))
        goto loc_df84;
loc_df84: // 0ca6:1524
    if (!(ax & 0x0008))
        goto loc_df8d;
    memoryASet(ds, si + 3, 0xff);
loc_df8d: // 0ca6:152d
    return;
}
void sub_df8e() // 0ca6:152e
{
}
void sub_df8f() // 0ca6:152f
{
}
void sub_df90() // 0ca6:1530 +returnCarry
{
    push(ax);
    push(dx);
    if ((short)ax < (short)memoryAGet16(ds, 0x6936))
        goto loc_dfbb;
    flags.carry = (al + bh) >= 0x100;
    al += bh;
    if (!flags.carry)
        goto loc_df9e;
    ah++;
loc_df9e: // 0ca6:153e
    ax--;
    if ((short)ax > (short)memoryAGet16(ds, 0x693a))
        goto loc_dfbb;
    if ((short)dx < (short)memoryAGet16(ds, 0x6938))
        goto loc_dfbb;
    flags.carry = (dl + bl) >= 0x100;
    dl += bl;
    if (!flags.carry)
        goto loc_dfb1;
    dh++;
loc_dfb1: // 0ca6:1551
    dx--;
    if ((short)dx > (short)memoryAGet16(ds, 0x693c))
        goto loc_dfbb;
    flags.carry = 0;
    goto loc_dfbc;
loc_dfbb: // 0ca6:155b
    flags.carry = 1;
loc_dfbc: // 0ca6:155c
    dx = pop();
    ax = pop();
}
void sub_dfbf() // 0ca6:155f
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    push(di);
    push(si);
    push(ds);
    push(es);
    si = 0x68ae;
    di = 0x68b6;
    cx = 0x0080;
    cx >>= 1;
    cx >>= 1;
loc_dfd5: // 0ca6:1575
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, ax);
    di += 0x0004;
    if (--cx)
        goto loc_dfd5;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_dfee() // 0ca6:158e
{
    sub_dfbf();
    sub_df33();
    al = memoryAGet(es, di + 2);
    bl = memoryAGet(es, di + 3);
    bh = memoryAGet(ds, si);
    cl = bh;
    bh += memoryAGet(es, di + 4);
    dl = memoryAGet(ds, si + 1);
    dh = memoryAGet(ds, si + 2);
    si += 0x0003;
    push(ds);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = 0x68a6;
    di = 0x68b6;
    ds = pop();
}
void sub_e01d() // 0ca6:15bd
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    push(di);
    push(si);
    push(ds);
    push(es);
    ch = 0;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx <<= 1;
    cx <<= 1;
    di += cx;
    cl = bh;
    cl &= 0x07;
    al = 0;
    if (cx==0)
        goto loc_e05c;
loc_e03d: // 0ca6:15dd
    flags.carry = 1;
    al = rcr8(al, 0x01);
    if (--cx)
        goto loc_e03d;
    cx = 0x0004;
loc_e045: // 0ca6:15e5
    if (bl == 0x00)
        goto loc_e05c;
    bl--;
loc_e04c: // 0ca6:15ec
    memoryASet(es, di, memoryAGet(es, di) & al);
    di++;
    if (--cx)
        goto loc_e04c;
    cx = 0x0004;
    di -= cx;
    di += 0x0008;
    goto loc_e045;
loc_e05c: // 0ca6:15fc
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_e066() // 0ca6:1606
{
}
void sub_e067() // 0ca6:1607
{
    sub_dfee();
    if (cl != 0x00)
        goto loc_e072;
    goto loc_e13d;
loc_e072: // 0ca6:1612
    push(ax);
    sub_e01d();
    al = 0x08;
    mul8(dh);
    ah = 0;
    di += ax;
    ch = 0;
    cl--;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx++;
    dh = cl;
    push(bx);
loc_e08c: // 0ca6:162c
    if (dl == 0x00)
        goto loc_e0ea;
    dl--;
    push(di);
    push(dx);
loc_e095: // 0ca6:1635
    al = memoryAGet(ds, si);
    bl = al;
    bh = al;
    ax = memoryAGet16(es, bp);
    ax &= bx;
    dx = ax;
    ax = memoryAGet16(es, bp + 2);
    ax &= bx;
    dx |= ax;
    dh |= dl;
    dl = dh;
    dx = ~dx;
    if (dx == 0xffff)
        goto loc_e0d2;
    ax = memoryAGet16(es, bp);
    ax &= bx;
    memoryASet16(es, di, memoryAGet16(es, di) & dx);
    memoryASet16(es, di, memoryAGet16(es, di) | ax);
    ax = memoryAGet16(es, bp + 2);
    ax &= bx;
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) & dx);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) | ax);
    goto loc_e0db;
loc_e0d2: // 0ca6:1672
    bx = ~bx;
    memoryASet16(es, di, memoryAGet16(es, di) & bx);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) & bx);
loc_e0db: // 0ca6:167b
    si++;
    di += 0x0004;
    if (--cx)
        goto loc_e095;
    dx = pop();
    cl = dh;
    di = pop();
    di += 0x0008;
    goto loc_e08c;
loc_e0ea: // 0ca6:168a
    bx = pop();
    ax = 0x1228;
    ds = ax;
    dx = pop();
    dh = 0;
    dx = -dx;
    dx += memoryAGet16(ds, 0x6944);
    ax = memoryAGet16(ds, 0x6942);
    flags.carry = (memoryAGet(ds, 0x6942) + bh) >= 0x100;
    memoryASet(ds, 0x6942, memoryAGet(ds, 0x6942) + bh);
    if (!flags.carry)
        goto loc_e108;
    memoryASet16(ds, 0x6942, memoryAGet16(ds, 0x6942) + 0x0100);
loc_e108: // 0ca6:16a8
    sub_df90();
    if (flags.carry)
        goto loc_e13d;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    cx = dx;
    cx <<= 1;
    cx <<= 1;
    cx += dx;
    dx = ax;
    dx &= 0x0007;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += cx;
    bh--;
    bh >>= 1;
    bh >>= 1;
    bh >>= 1;
    bh++;
    cl = bh;
    ch = bl;
    bl = 0x02;
    bh = 0x28;
    sub_deee();
loc_e13d: // 0ca6:16dd
    sub_d0bf();
}
void sub_e141() // 0ca6:16e1
{
}
void sub_e142() // 0ca6:16e2
{
}
void sub_e150() // 0e15:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memoryASet16(ds, 0x4e10, di);
    memoryASet16(ds, 0x4e0c, di);
    memoryASet16(ds, 0x4e0e, si);
    memoryASet16(ds, 0x4e0a, si);
    es = di;
    di = si;
    memoryASet16(ds, 0x4e14, bx);
    memoryASet16(ds, 0x4e2a, bx);
    memoryASet16(ds, 0x4e12, ax);
    memoryASet16(ds, 0x4e28, ax);
    bx = dx;
    ax = cx;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e0c, dx);
    memoryASet16(ds, 0x4e0a, ax);
loc_e18c: // 0e15:003c
    sub_eb59();
    if (!flags.carry)
        goto loc_e196;
    ax = 0x0003;
    goto loc_e1c8;
loc_e196: // 0e15:0046
    push(si);
    push(ds);
    bp = 0x1228;
    ds = bp;
    si = memoryAGet16(ds, 0x4e31);
    si &= 0x7fff;
    si--;
    si <<= 1;
    bp = memoryAGet16(ds, si + 20023);
    ds = pop();
    si = pop();
    switch (bp)
    {
        case 0x0193: sub_e2e3(); break;
        case 0x0194: sub_e2e4(); break;
        case 0x04b0: sub_e600(); break;
        default:
            stop("ind 0e15:005e");
    }
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e35);
    memoryASet16(ds, 0x4e2a, ax);
    ax = memoryAGet16(ds, 0x4e33);
    memoryASet16(ds, 0x4e28, ax);
    if ((short)memoryAGet16(ds, 0x4e31) > (short)0x0000)
        goto loc_e18c;
loc_e1c8: // 0e15:0078
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_e1ce() // 0e15:007e
{
    dx = memoryAGet16(ds, 0x4e26);
    memoryASet16(ds, 0x4e14, dx);
    ax = memoryAGet16(ds, 0x4e24);
    memoryASet16(ds, 0x4e12, ax);
    memoryASet(ds, 0x4e12, memoryAGet(ds, 0x4e12) & 0xf0);
    if (dx != memoryAGet16(ds, 0x4e14))
        goto loc_e1ed;
    if (ax == memoryAGet16(ds, 0x4e12))
        goto loc_e1f8;
loc_e1ed: // 0e15:009d
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0010) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0010);
    if (!flags.carry)
        goto loc_e1f8;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_e1f8: // 0e15:00a8
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e18, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e16, ax);
    ax = memoryAGet16(ds, 0x4e18);
    es = ax;
    di = memoryAGet16(ds, 0x4e16);
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs); cs = 0x0ec7; sub_ecb5(); assert(cs == 0x0e15);
    al &= 0xfe;
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4dfc, dx);
    memoryASet16(ds, 0x4dfa, ax);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    bx = 0;
    ax = 0x0010;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    if (dx < memoryAGet16(ds, 0x4dfc))
        goto loc_e285;
    if (dx != memoryAGet16(ds, 0x4dfc))
        goto loc_e278;
    if (ax <= memoryAGet16(ds, 0x4dfa))
        goto loc_e285;
loc_e278: // 0e15:0128
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0002);
    return;
loc_e285: // 0e15:0135
    cx = memoryAGet16(ds, 0x4e14);
    bx = memoryAGet16(ds, 0x4e12);
    ax = memoryAGet16(ds, 0x4dfc);
    es = ax;
    di = memoryAGet16(ds, 0x4dfa);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_e29f: // 0e15:014f
    flags.carry = si < 0x0002;
    si -= 0x0002;
    if (!flags.carry)
        goto loc_e2ac;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e2ac: // 0e15:015c
    flags.carry = di < 0x0002;
    di -= 0x0002;
    if (!flags.carry)
        goto loc_e2b9;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e2b9: // 0e15:0169
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    flags.carry = bx < 0x0002;
    bx -= 0x0002;
    if (!flags.carry)
        goto loc_e2c7;
    bx += 0x0010;
    cx--;
loc_e2c7: // 0e15:0177
    if (cx != 0x0000)
        goto loc_e29f;
    if (bx != 0x0000)
        goto loc_e29f;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0001);
}
void sub_e2e3() // 0e15:0193
{
}
void sub_e2e4() // 0e15:0194
{
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    al = memoryAGet(es, di);
    memoryASet(ds, 0x4e22, al);
    memoryASet16(ds, 0x4e06, memoryAGet16(ds, 0x4e06) + 1);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    bx = memoryAGet16(ds, 0x4e2a);
    ax = memoryAGet16(ds, 0x4e28);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4dfc, dx);
    memoryASet16(ds, 0x4dfa, ax);
    ax = 0x1228;
    es = ax;
    di = 0x4e97;
    bx = 0;
    ax = 0x0400;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e04, dx);
    memoryASet16(ds, 0x4e02, ax);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e2f, dx);
    memoryASet16(ds, 0x4e2d, ax);
    si = memoryAGet16(ds, 0x4dfa);
    ax = memoryAGet16(ds, 0x4dfc);
    ds = ax;
    cx = 0x0400;
loc_e370: // 0e15:0220
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e37d;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e37d: // 0e15:022d
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e38a;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e38a: // 0e15:023a
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    bp = cx;
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3aa;
    if (si == cx)
        goto loc_e3ff;
loc_e3aa: // 0e15:025a
    cx = bp;
    if (--cx)
        goto loc_e370;
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4df8);
    memoryASet16(ds, 0x4e04, ax);
    di = memoryAGet16(ds, 0x4df6);
    memoryASet16(ds, 0x4e02, di);
    es = ax;
    ds = bp;
loc_e3c7: // 0e15:0277
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e3d4;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e3d4: // 0e15:0284
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e3e1;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e3e1: // 0e15:0291
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3c7;
    if (si != cx)
        goto loc_e3c7;
loc_e3ff: // 0e15:02af
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    memoryASet16(ds, 0x4e00, ax);
    ax = memoryAGet16(ds, 0x4e0e);
    memoryASet16(ds, 0x4dfe, ax);
    ax = es;
    ds = ax;
    si = di;
loc_e416: // 0e15:02c6
    al = memoryAGet(ds, si);
    bp = ds;
    bx = 0x1228;
    ds = bx;
    memoryASet(ds, 0x4e2c, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e465;
    if (si != cx)
        goto loc_e465;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e465: // 0e15:0315
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryAGet(ds, 0x4e22);
    ah = memoryAGet(ds, 0x4e2c);
    ds = bp;
    if (al == ah)
        goto loc_e47c;
    goto loc_e565;
loc_e47c: // 0e15:032c
    al = memoryAGet(ds, si);
    ds = bx;
    memoryASet(ds, 0x4e1e, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e4c6;
    if (si != cx)
        goto loc_e4c6;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e4c6: // 0e15:0376
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryAGet(ds, 0x4e22);
    ah = memoryAGet(ds, 0x4e1e);
    ds = bp;
    if (al != ah)
        goto loc_e4dd;
    goto loc_e565;
loc_e4dd: // 0e15:038d
    al = memoryAGet(ds, si);
    ds = bx;
    memoryASet(ds, 0x4e16, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e527;
    if (si != cx)
        goto loc_e527;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e527: // 0e15:03d7
    bp = ds;
    bx = 0x1228;
    ds = bx;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    al = memoryAGet(ds, 0x4e1e);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    if (bp != dx)
        goto loc_e55b;
    if (si != di)
        goto loc_e55b;
    goto loc_e5fe;
loc_e55b: // 0e15:040b
    memoryASet(ds, 0x4e16, memoryAGet(ds, 0x4e16) - 1);
    flags.zero = !memoryAGet(ds, 0x4e16); // cico post
    ds = bp;
    if (!flags.zero)
        goto loc_e527;
    goto loc_e590;
loc_e565: // 0e15:0415
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    al = memoryAGet(ds, 0x4e2c);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    ds = bp;
loc_e590: // 0e15:0440
    bp = ds;
    dx = es;
    if (bp != dx)
        goto loc_e59c;
    if (si == di)
        goto loc_e5fe;
loc_e59c: // 0e15:044c
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e2f);
    cx = memoryAGet16(ds, 0x4e2d);
    ds = bp;
    if (bp == dx)
        goto loc_e5b2;
    goto loc_e416;
loc_e5b2: // 0e15:0462
    if (si == cx)
        goto loc_e5b9;
    goto loc_e416;
loc_e5b9: // 0e15:0469
    ax = 0x1228;
    ds = ax;
    push(di);
    push(es);
    ax = memoryAGet16(ds, 0x4e26);
    es = ax;
    di = memoryAGet16(ds, 0x4e24);
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e26, dx);
    memoryASet16(ds, 0x4e24, ax);
    es = pop();
    di = pop();
    ax = memoryAGet16(ds, 0x4e0e);
    flags.carry = di < ax;
    di -= ax;
    if (!flags.carry)
        goto loc_e5e6;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e5e6: // 0e15:0496
    bx = memoryAGet16(ds, 0x4e10);
    ax = es;
    ax -= bx;
    if (ax != memoryAGet16(ds, 0x4e26))
        goto loc_e5ff;
    if (di != memoryAGet16(ds, 0x4e24))
        goto loc_e5ff;
    ax = 0x0001;
    return;
loc_e5fe: // 0e15:04ae
    return;
loc_e5ff: // 0e15:04af
    return;
}
void sub_e600() // 0e15:04b0
{
    goto loc_e600;
loc_e5fe: // 0e15:04ae
    return;
    // gap 1 bytes
loc_e600: // 0e15:04b0
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    if (dx > memoryAGet16(ds, 0x4e0c))
        goto loc_e5fe;
    if (dx != memoryAGet16(ds, 0x4e0c))
        goto loc_e628;
    if (ax > memoryAGet16(ds, 0x4e0a))
        goto loc_e5fe;
loc_e628: // 0e15:04d8
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    ax = memoryAGet16(es, di);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, 0x4e22, ax);
    memoryASet16(ds, 0x4df6, memoryAGet16(ds, 0x4df6) + 0x0002);
    dx = memoryAGet16(ds, 0x4e26);
    memoryASet16(ds, 0x4e20, dx);
    ax = memoryAGet16(ds, 0x4e24);
    memoryASet16(ds, 0x4e1e, ax);
    memoryASet(ds, 0x4e1e, memoryAGet(ds, 0x4e1e) & 0xe0);
    if (dx != memoryAGet16(ds, 0x4e20))
        goto loc_e679;
    if (ax == memoryAGet16(ds, 0x4e1e))
        goto loc_e67f;
    dx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
loc_e679: // 0e15:0529
    flags.carry = (ax + 0x0020) >= 0x10000;
    ax += 0x0020;
    if (!flags.carry)
        goto loc_e67f;
    dx++;
loc_e67f: // 0e15:052f
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    memoryASet16(ds, 0x4e20, dx);
    memoryASet16(ds, 0x4e1e, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e18, ax);
    di = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e16, di);
    es = ax;
    bx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
    push(cs); cs = 0x0ec7; sub_ecb5(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e18, dx);
    memoryASet16(ds, 0x4e16, ax);
    memoryASet(ds, 0x4e16, memoryAGet(ds, 0x4e16) & 0xfe);
    dx = memoryAGet16(ds, 0x4e18);
    memoryASet16(ds, 0x4dfc, dx);
    ax = memoryAGet16(ds, 0x4e16);
    memoryASet16(ds, 0x4dfa, ax);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    es = dx;
    di = ax;
    ax = memoryAGet16(ds, 0x4e20);
    memoryASet16(ds, 0x4e18, ax);
    ax = memoryAGet16(ds, 0x4e1e);
    memoryASet16(ds, 0x4e16, ax);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_e6e8: // 0e15:0598
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(es, di + 2, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bp = ds;
    di += 0x0004;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = 0x1228;
    ds = ax;
    push(di);
    push(es);
    ax = memoryAGet16(ds, 0x4e18);
    es = ax;
    di = memoryAGet16(ds, 0x4e16);
    bx = 0;
    ax = 0x0004;
    push(cs); cs = 0x0ec7; sub_ecb5(); assert(cs == 0x0e15);
    es = pop();
    di = pop();
    memoryASet16(ds, 0x4e18, dx);
    memoryASet16(ds, 0x4e16, ax);
    ds = bp;
    if (dx != 0x0000)
        goto loc_e6e8;
    if (ax != 0x0000)
        goto loc_e6e8;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4df8, bp);
    memoryASet16(ds, 0x4df6, si);
    ax = es;
    memoryASet16(ds, 0x4e00, ax);
    memoryASet16(ds, 0x4dfe, di);
    ax = memoryAGet16(ds, 0x4e26);
    push(ax);
    ax = memoryAGet16(ds, 0x4e24);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfc);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfa);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e0c, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e0a, ax);
    ax = memoryAGet16(ds, 0x4e2a);
    memoryASet16(ds, 0x4e26, ax);
    ax = memoryAGet16(ds, 0x4e28);
    memoryASet16(ds, 0x4e24, ax);
    sub_e1ce();
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4dfa, ax);
    ax = pop();
    memoryASet16(ds, 0x4dfc, ax);
    ax = pop();
    memoryASet16(ds, 0x4e24, ax);
    ax = pop();
    memoryASet16(ds, 0x4e26, ax);
    if (memoryAGet16(ds, 0x4e14) != 0x0000)
        goto loc_e7bb;
    if (memoryAGet16(ds, 0x4e12) != 0x0002)
        goto loc_e7bb;
    goto loc_e5fe;
loc_e7bb: // 0e15:066b
    ax = memoryAGet16(ds, 0x4e26);
    push(ax);
    ax = memoryAGet16(ds, 0x4e24);
    push(ax);
    ax = memoryAGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e28);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e08);
    es = ax;
    di = memoryAGet16(ds, 0x4e06);
    bx = memoryAGet16(ds, 0x4e2a);
    ax = memoryAGet16(ds, 0x4e28);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e04, dx);
    memoryASet16(ds, 0x4e02, ax);
    bx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    bx = 0;
    ax = 0x000e;
    push(cs); cs = 0x0ec7; sub_ec70(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e00, ax);
    di = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4dfe, di);
    es = ax;
    bx = 0;
    ax = 0x0400;
    push(cs); cs = 0x0ec7; sub_ecb5(); assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e0c, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e0a, ax);
    ax = memoryAGet16(ds, 0x4e10);
    memoryASet16(ds, 0x4df8, ax);
    ax = memoryAGet16(ds, 0x4e0e);
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0000);
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0000);
    memoryASet16(ds, 0x4e18, 0x0000);
    memoryASet16(ds, 0x4e16, 0x0000);
loc_e86d: // 0e15:071d
    memoryASet16(ds, 0x4e16, memoryAGet16(ds, 0x4e16) - 0x0001);
    if ((short)memoryAGet16(ds, 0x4e16) >= (short)0x0000)
        goto loc_e8c2;
    bp = ds;
    si = memoryAGet16(ds, 0x4e0a);
    ax = memoryAGet16(ds, 0x4e0c);
    ds = ax;
    dx = memoryAGet16(ds, si + 2);
    tl = dl; dl = dh; dh = tl;
    ax = memoryAGet16(ds, si);
    tl = al; al = ah; ah = tl;
    push(ax);
    push(dx);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    dx = pop();
    ax = pop();
    cx = ds;
    ds = bp;
    memoryASet16(ds, 0x4e0c, cx);
    memoryASet16(ds, 0x4e0a, si);
    memoryASet16(ds, 0x4e16, 0x001f);
    memoryASet16(ds, 0x4e26, ax);
    memoryASet16(ds, 0x4e24, dx);
loc_e8c2: // 0e15:0772
    dx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl16(dx, 0x0001);
    memoryASet16(ds, 0x4e26, dx);
    memoryASet16(ds, 0x4e24, ax);
    if (!flags.carry)
        goto loc_e8d9;
    goto loc_ea27;
loc_e8d9: // 0e15:0789
    ax = memoryAGet16(ds, 0x4df8);
    es = ax;
    di = memoryAGet16(ds, 0x4df6);
    si = memoryAGet16(ds, 0x4e06);
    ax = memoryAGet16(ds, 0x4e08);
    ds = ax;
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bp = ds;
    di += 0x0001;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e08, bp);
    memoryASet16(ds, 0x4e06, si);
    ax = es;
    memoryASet16(ds, 0x4df8, ax);
    memoryASet16(ds, 0x4df6, di);
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_e937;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_e937: // 0e15:07e7
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_e962;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_e962;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_e962: // 0e15:0812
    dx = memoryAGet16(ds, 0x4e08);
    ax = memoryAGet16(ds, 0x4e06);
    if (dx != memoryAGet16(ds, 0x4e04))
        goto loc_e978;
    if (ax != memoryAGet16(ds, 0x4e02))
        goto loc_e978;
    goto loc_ea84;
loc_e978: // 0e15:0828
    dx = memoryAGet16(ds, 0x4e08);
    ax = memoryAGet16(ds, 0x4e06);
    if (dx <= memoryAGet16(ds, 0x4df8))
        goto loc_e988;
    goto loc_e86d;
loc_e988: // 0e15:0838
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_e993;
    if (ax <= memoryAGet16(ds, 0x4df6))
        goto loc_e993;
    goto loc_e86d;
loc_e993: // 0e15:0843
    if (memoryAGet16(ds, 0x4e1c) == 0x0000)
        goto loc_e99d;
    goto loc_e86d;
loc_e99d: // 0e15:084d
    if (memoryAGet16(ds, 0x4e1a) == 0x0000)
        goto loc_e9a7;
    goto loc_e86d;
loc_e9a7: // 0e15:0857
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4dfc, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4dfa, ax);
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ax = memoryAGet16(ds, 0x4dfc);
    es = ax;
    di = memoryAGet16(ds, 0x4dfa);
    si = memoryAGet16(ds, 0x4e02);
    ax = memoryAGet16(ds, 0x4e04);
    ds = ax;
loc_e9cd: // 0e15:087d
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e9da;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e9da: // 0e15:088a
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e9e7;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e9e7: // 0e15:0897
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    if (dx != ax)
        goto loc_e9cd;
    if (cx != si)
        goto loc_e9cd;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e04, bp);
    memoryASet16(ds, 0x4e02, si);
    ax = es;
    memoryASet16(ds, 0x4dfc, ax);
    memoryASet16(ds, 0x4dfa, di);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e08, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e06, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e04, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e02, ax);
    goto loc_e86d;
loc_ea27: // 0e15:08d7
    ax = memoryAGet16(ds, 0x4df8);
    es = ax;
    di = memoryAGet16(ds, 0x4df6);
    al = memoryAGet(ds, 0x4e22);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = es;
    memoryASet16(ds, 0x4df8, ax);
    memoryASet16(ds, 0x4df6, di);
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_ea56;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_ea56: // 0e15:0906
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_ea81;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_ea81;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_ea81: // 0e15:0931
    goto loc_e978;
loc_ea84: // 0e15:0934
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4e28, ax);
    ax = pop();
    memoryASet16(ds, 0x4e2a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e24, ax);
    ax = pop();
    memoryASet16(ds, 0x4e26, ax);
loc_ea9c: // 0e15:094c
    al = memoryAGet(ds, 0x4e22);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_eab9;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_eab9: // 0e15:0969
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_eae4;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_eae4;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_eae4: // 0e15:0994
    dx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    if (dx > memoryAGet16(ds, 0x4e14))
        goto loc_ea9c;
    if (dx != memoryAGet16(ds, 0x4e14))
        goto loc_eaf9;
    if (ax > memoryAGet16(ds, 0x4e12))
        goto loc_ea9c;
loc_eaf9: // 0e15:09a9
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    cx = 0x0400;
    cx >>= 1;
    cx >>= 1;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_eb1e: // 0e15:09ce
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(es, di + 2, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    di += 0x0004;
    push(cs); cs = 0x0ec7; sub_ecf9(); assert(cs == 0x0e15);
    es = dx;
    di = ax;
    if (--cx)
        goto loc_eb1e;
    ax = 0x1228;
    ds = ax;
    ax = 0x0001;
}
void sub_eb59() // 0e15:0a09 +returnCarry
{
    ax = memoryAGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e28);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    push(ax);
    ax = memoryAGet16(ds, 0x4e0e);
    di = ax;
    push(ax);
    ax = memoryAGet16(es, di);
    tl = al; al = ah; ah = tl;
    bx = memoryAGet16(es, di + 2);
    tl = bl; bl = bh; bh = tl;
    memoryASet16(ds, 0x4e26, ax);
    memoryASet16(ds, 0x4e24, bx);
    memoryASet16(ds, 0x4e35, ax);
    memoryASet16(ds, 0x4e33, bx);
    if (ax > 0x000f)
        goto loc_ec06;
    if (ax != 0x000f)
        goto loc_eba0;
    if (bx > 0xffff)
        goto loc_ec06;
loc_eba0: // 0e15:0a50
    ax = memoryAGet16(es, di + 6);
    tl = al; al = ah; ah = tl;
    bx = memoryAGet16(es, di + 4);
    tl = bl; bl = bh; bh = tl;
    memoryASet16(ds, 0x4e20, ax);
    memoryASet16(ds, 0x4e1e, bx);
    ax = memoryAGet16(es, di + 8);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, 0x4e31, ax);
    si = ax;
    si &= 0x003f;
    if (si > 0x001e)
        goto loc_ec06;
    si += si;
    bx = memoryAGet16(ds, si + 20059);
    tl = bl; bl = bh; bh = tl;
    if ((short)bx < (short)0x0000)
        goto loc_ec06;
    si = ax;
    si &= 0x7f00;
    if (si)
        goto loc_ec06;
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    si = memoryAGet16(ds, 0x4e31);
    si ^= bx;
    si ^= ax;
    memoryASet16(ds, 0x4e26, bx);
    memoryASet16(ds, 0x4e24, ax);
    ax = memoryAGet16(ds, 0x4e20);
    bx = memoryAGet16(ds, 0x4e1e);
    si ^= bx;
    si ^= ax;
    ax = memoryAGet16(es, di + 10);
    tl = al; al = ah; ah = tl;
    flags.carry = si < ax;
    if (si == ax)
        goto loc_ec07;
loc_ec06: // 0e15:0ab6
    flags.carry = 1;
loc_ec07: // 0e15:0ab7
    ax = pop();
    memoryASet16(ds, 0x4e0e, ax);
    ax = pop();
    memoryASet16(ds, 0x4e10, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4e28, ax);
    ax = pop();
    memoryASet16(ds, 0x4e2a, ax);
}
void sub_ec20() // 0ec2:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.carry = (ax + 0x000f) >= 0x10000;
    ax += 0x000f;
    if (!flags.carry)
        goto loc_ec2b;
    dx++;
loc_ec2b: // 0ec2:000b
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr16(ax, 0x0001);
    bx = ax;
    ah = 0x48;
    interrupt(0x21);
    if (flags.carry)
        goto loc_ec48;
    dx = 0;
    tx = dx; dx = ax; ax = tx;
    goto loc_ec4c;
loc_ec48: // 0ec2:0028
    dx = 0;
    ax = 0;
loc_ec4c: // 0ec2:002c
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ec52() // 0ec2:0032 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    es = ax;
    ah = 0x49;
    interrupt(0x21);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ec70() // 0ec7:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    push(ax);
    push(bx);
    push(cs);
    sub_ecf9();
    es = dx;
    di = ax;
    bx = pop();
    ax = pop();
    cx = ax;
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    bx = cx;
    bx &= 0x000f;
    bx += di;
    dx = bx;
    bx = es;
    ax += bx;
    tx = dx; dx = ax; ax = tx;
    if ((short)ax <= (short)0x000f)
        goto loc_ecaf;
    ax &= 0x000f;
    dx++;
loc_ecaf: // 0ec7:003f
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ecb5() // 0ec7:0045 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    push(ax);
    push(bx);
    push(cs);
    sub_ecf9();
    es = dx;
    di = ax;
    bx = pop();
    ax = pop();
    cx = ax;
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr16(ax, 0x0001);
    bx = cx;
    bx &= 0x000f;
    flags.carry = di < bx;
    di -= bx;
    if (!flags.carry)
        goto loc_ecea;
    di += 0x0010;
    ax++;
loc_ecea: // 0ec7:007a
    dx = di;
    bx = es;
    bx -= ax;
    ax = bx;
    tx = dx; dx = ax; ax = tx;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ecf9() // 0ec7:0089 +nearfar +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = di;
    di &= 0x000f;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = es;
    ax += bx;
    dx = ax;
    ax = di;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_ed20() // 0ed2:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x5676, ax);
    memoryASet16(ds, 0x5678, 0x0000);
    memoryASet16(ds, 0x567a, 0x0000);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ed3f() // 0ed2:001f +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x5678);
    bp = memoryAGet16(ds, 0x567a);
    ax = bp;
    ax += 0x2432;
    ax ^= bx;
    ax ^= memoryAGet16(ds, 0x5676);
    bp = ax;
    ax = ror16(ax, 0x0001);
    ax -= memoryAGet16(ds, 0x5676);
    ax ^= bx;
    ax += 0x1c12;
    ax ^= bp;
    ax = ror16(ax, 0x0001);
    flags.carry = (ax + bp) >= 0x10000;
    ax += bp;
    ax = rcr16(ax, 0x0001);
    bx = ax;
    ax = memoryAGet16(ds, 0x5676);
    ax += bp;
    ax ^= 0x3812;
    ax ^= bx;
    memoryASet16(ds, 0x5676, ax);
    memoryASet16(ds, 0x5678, bx);
    memoryASet16(ds, 0x567a, bp);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_edfa() // 0ed9:006a
{
loc_edfa: // 0ed9:006a
    ax = es;
    bx = memoryAGet16(es, di);
    tl = bl; bl = bh; bh = tl;
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    ax += bx;
    cx = bx;
    bx = memoryAGet16(es, di + 2);
    cx |= bx;
    if (!cx)
        goto loc_ee39;
    tl = bl; bl = bh; bh = tl;
    cx = bx;
    cx &= 0x000f;
    cx += 0x0800;
    bx &= 0xfff0;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax += bx;
    memoryASet16(es, di + 2, ax);
    memoryASet16(es, di, cx);
    di += 0x0004;
    goto loc_edfa;
loc_ee39: // 0ed9:00a9
    return;
}
void sub_efb8() // 0ed9:0228
{
    cx = memoryAGet16(ss, bp + 6);
    cx >>= 1;
    cx >>= 1;
    cx += 0x0001;
    cx &= 0xfffe;
    di = memoryAGet16(ss, bp + 4);
    di >>= 1;
    di >>= 1;
    di &= 0xfffe;
    memoryASet16(ds, 0x6815, cx);
    cx -= di;
    memoryASet16(ds, 0x680d, di);
    memoryASet16(ds, 0x680f, cx);
    di = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x6811, di);
    cx = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x6817, cx);
    cx -= di;
    memoryASet16(ds, 0x6813, cx);
}
void sub_eff2() // 0ed9:0262 +stackDrop2
{
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (!bx)
        goto loc_effc;
    sub_effd();
loc_effc: // 0ed9:026c
    cs = pop();
    return;
}
void sub_effd() // 0ed9:026d
{
    memoryASet16(ds, 0x6809, bx);
    si = es;
    memoryASet16(ds, 0x680b, si);
    ax = bx;
    ax |= si;
    if (!ax)
        goto loc_f010;
    sub_f011();
loc_f010: // 0ed9:0280
    return;
}
void sub_f011() // 0ed9:0281
{
    bx = memoryAGet16(ds, 0x6809); es = memoryAGet16(ds, 0x6809 + 2);
loc_f015: // 0ed9:0285
    push(es);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    ax = es;
    ax |= di;
    if (!ax)
        goto loc_f025;
    push(bx);
    si = 0x56e2;
    goto loc_f02b;
loc_f025: // 0ed9:0295
    goto loc_f0a3;
    // gap 1 bytes
loc_f028: // 0ed9:0298
    goto loc_f09b;
    // gap 1 bytes
loc_f02b: // 0ed9:029b
    al = memoryAGet(es, di + 10);
    if (!(al & 0x80))
        goto loc_f028;
    ax = memoryAGet16(es, di);
    ax -= memoryAGet16(es, di + 20);
    bx = ax;
    bx &= 0x0003;
    bx += bx;
    memoryASet(ds, 0x683b, bl);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x6821, ax);
    ax = memoryAGet16(es, di + 2);
    ax -= memoryAGet16(es, di + 22);
    memoryASet16(ds, 0x6823, ax);
    dx = memoryAGet16(ds, 0x6817);
    ax = memoryAGet16(ds, 0x6823);
    if ((short)dx <= (short)ax)
        goto loc_f099;
    dx = memoryAGet16(ds, 0x6815);
    ax = memoryAGet16(ds, 0x6821);
    if ((short)dx <= (short)ax)
        goto loc_f099;
    dx = ax;
    ax = memoryAGet16(es, di + 16);
    dx += ax;
    if ((short)dx < 0)
        goto loc_f028;
    ax = memoryAGet16(ds, 0x680d);
    if ((short)dx <= (short)ax)
        goto loc_f099;
    ax = memoryAGet16(ds, 0x6823);
    dx = ax;
    ax = memoryAGet16(es, di + 18);
    dx += ax;
    if ((short)dx < 0)
        goto loc_f099;
    ax = memoryAGet16(ds, 0x6811);
    if ((short)dx <= (short)ax)
        goto loc_f099;
    push(bx);
    push(di);
    sub_f1b6();
    di = pop();
    bx = pop();
loc_f099: // 0ed9:0309
    goto loc_f028;
loc_f09b: // 0ed9:030b
    bx = pop();
    es = pop();
    bx += 0x0004;
    goto loc_f015;
loc_f0a3: // 0ed9:0313
    es = pop();
}
void sub_f0dc() // 0ed9:034c
{
    memoryASet(ds, 0x683c, 0x00);
    memoryASet16(ds, 0x6819, 0x0000);
    ax = memoryAGet16(ds, 0x680d);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax >= 0)
        goto loc_f0f7;
    ax = -ax;
    memoryASet16(ds, 0x6819, ax);
    ax = 0;
loc_f0f7: // 0ed9:0367
    memoryASet16(ds, 0x681f, ax);
    if (!ax)
        goto loc_f103;
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x02);
loc_f103: // 0ed9:0373
    ax = memoryAGet16(ds, 0x6815);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax < 0)
        goto loc_f128;
    ax -= memoryAGet16(es, di + 16);
    if ((short)ax < 0)
        goto loc_f128;
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x01);
    ax = memoryAGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryAGet16(es, di + 16);
    memoryASet16(ds, 0x6835, ax);
    goto loc_f13a;
loc_f125: // 0ed9:0395
    ax = 0;
    return;
loc_f128: // 0ed9:0398
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x01);
    ax = memoryAGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6815);
    ax -= memoryAGet16(ds, 0x6821);
loc_f13a: // 0ed9:03aa
    memoryASet16(ds, 0x6835, ax);
    memoryASet16(ds, 0x681b, 0x0000);
    ax = memoryAGet16(ds, 0x6811);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax >= 0)
        goto loc_f153;
    ax = -ax;
    memoryASet16(ds, 0x681b, ax);
    ax = 0;
loc_f153: // 0ed9:03c3
    memoryASet16(ds, 0x681d, ax);
    ax = memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax < 0)
        goto loc_f170;
    ax -= memoryAGet16(es, di + 18);
    if ((short)ax < 0)
        goto loc_f170;
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(es, di + 18);
    goto loc_f17d;
loc_f170: // 0ed9:03e0
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
loc_f17d: // 0ed9:03ed
    memoryASet16(ds, 0x6837, ax);
    ax = memoryAGet16(ds, 0x681b);
    ax += memoryAGet16(ds, 0x6811);
    if (!ax)
        goto loc_f18f;
    bl = 0x50;
    mul8(bl);
loc_f18f: // 0ed9:03ff
    ax += si;
    ax += memoryAGet16(ds, 0x6819);
    ax += memoryAGet16(ds, 0x680d);
    memoryASet16(ds, 0x56e8, ax);
    if (memoryAGet16(ds, 0x6835) == 0xffff)
        goto loc_f1b3;
    if ((short)memoryAGet16(ds, 0x6835) < (short)0xffff)
        goto loc_f1b3;
    if (!(memoryAGet16(ds, 0x6837) & 0xffff))
        goto loc_f1b3;
    if (!!(memoryAGet16(ds, 0x6837) & 0xffff & 0x8000))
        goto loc_f1b3;
    ax |= 0x0001;
    return;
loc_f1b3: // 0ed9:0423
    goto loc_f125;
}
void sub_f1b6() // 0ed9:0426
{
    sub_f0dc();
    ax = memoryAGet16(ds, 0x681d);
    if (!ax)
        goto loc_f1c6;
    bl = memoryAGet(es, di + 16);
    mul8(bl);
loc_f1c6: // 0ed9:0436
    ax += memoryAGet16(ds, 0x681f);
    memoryASet16(ds, 0x56e6, ax);
    ax = memoryAGet16(ds, 0x6837);
    memoryASet16(ds, 0x6837, ax);
    ax = memoryAGet16(ds, 0x6835);
    dx = memoryAGet16(es, di + 16);
    memoryASet16(ds, 0x6831, dx);
    cx = 0x0050;
    memoryASet16(ds, 0x6833, cx);
    memoryASet16(ds, 0x6835, ax);
    {int tmp1 = memoryAGet16(ds, di + 12); int tmp2 = memoryAGet16(ds, di + 12 + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    ax = es;
    memoryASet16(ds, 0x6827, ax);
    ax -= memoryAGet16(ds, di + 8);
    ax += memoryAGet16(ds, 0x56ec);
    memoryASet16(ds, 0x682b, ax);
    di += memoryAGet16(ds, 0x56e6);
    memoryASet16(ds, 0x6825, di);
    memoryASet16(ds, 0x6829, di);
    si = memoryAGet16(ds, 0x56e8);
    memoryASet16(ds, 0x682d, si);
    ax = ds;
    memoryASet16(ds, 0x682f, ax);
    si = 0x6825;
    push(es);
    push(di);
    sub_f21e();
    di = pop();
    es = pop();
}
void sub_f21e() // 0ed9:048e
{
    ax = memoryAGet16(ds, si + 18);
    ax--;
    memoryASet16(cs, 0x3213, ax);
    al = memoryAGet(ds, si + 23);
    memoryASet(cs, 0x3215, al);
    bx = memoryAGet16(ds, si + 12);
    ax = memoryAGet16(ds, si + 16);
    bx -= ax;
    memoryASet16(cs, 0x3211, bx);
    bx = memoryAGet16(ds, si + 14);
    bx -= ax;
    memoryASet16(cs, 0x320f, bx);
    bx = 0x0522;
    if (ax & 0x0001)
        goto loc_f24f;
    bx = 0x053e;
loc_f24f: // 0ed9:04bf
    memoryASet16(cs, 0x051e, bx);
    bx = 0x08ba;
    if (ax & 0x0001)
        goto loc_f25f;
    bx = 0x08d6;
loc_f25f: // 0ed9:04cf
    memoryASet16(cs, 0x08b6, bx);
    tx = bx; bx = ax; ax = tx;
    bx &= 0xfffe;
    ax = memoryAGet16(cs, bx + 12823);
    memoryASet16(cs, 0x053f, ax);
    ax = memoryAGet16(cs, bx + 12879);
    memoryASet16(cs, 0x08d7, ax);
    push(memoryAGet16(cs, 0x3213));
    push(ds);
    push(si);
    bp = memoryAGet16(ds, si + 4); es = memoryAGet16(ds, si + 4 + 2);
    bl = memoryAGet(ds, si + 22);
    cl = bl;
    bh = 0;
    di = memoryAGet16(cs, bx + 12935);
    {int tmp1 = memoryAGet16(ds, si + 8); int tmp2 = memoryAGet16(ds, si + 8 + 2); si = tmp1; ds = tmp2; /*ggg2!!check*/};
    dx = di;
    dx = ~dx;
    al = memoryAGet(cs, 0x3215);
    if (!(al & 0x02))
        goto loc_f2ad;
    dl = memoryAGet(es, bp - 1);
    dh = 0xff;
    dx = ror16(dx, cl);
    di = ~di;
    dx &= di;
    di = ~di;
loc_f2ad: // 0ed9:051d
    ax = 0x0000;
    stop(); //indirectJump(cs, ax); return; // 0ed9:0520;
}
void sub_f9b4() // 0ed9:0c24
{
    push(ax);
    ax = 0x0003;
    interrupt(0x10);
    ax = pop();
    dl = al;
    ah = 0x02;
    interrupt(0x21);
    interrupt(0x20);
    stop("terminating");
}
void sub_f9c4() // 0ed9:0c34
{
loc_f9c4: // 0ed9:0c34
    ax = es;
    bx = memoryAGet16(es, di);
    tl = bl; bl = bh; bh = tl;
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    ax += bx;
    cx = bx;
    bx = memoryAGet16(es, di + 2);
    cx |= bx;
    if (!cx)
        goto loc_fa06;
    tl = bl; bl = bh; bh = tl;
    cx = bx;
    cx &= 0x000f;
    cx += 0x0800;
    bx &= 0xfff0;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax += bx;
    memoryASet16(es, di + 2, ax);
    memoryASet16(es, di, cx);
    sub_fa07();
    di += 0x0004;
    goto loc_f9c4;
loc_fa06: // 0ed9:0c76
    return;
}
void sub_fa07() // 0ed9:0c77
{
    push(ds);
    push(di);
    push(si);
    push(ax);
    push(cx);
    ax = memoryAGet16(ds, 0x541d);
    memoryASet16(cs, 0x0ded, ax);
    {int tmp1 = memoryAGet16(es, di); int tmp2 = memoryAGet16(es, di + 2); di = tmp1; ds = tmp2; /*ggg2!!check*/};
    cx = memoryAGet16(ds, di + 65534);
    tl = cl; cl = ch; ch = tl;
    memoryASet16(ds, di + 65534, cx);
    if ((short)cx < 0)
        goto loc_fa26;
    if (!cx)
        goto loc_fa26;
    goto loc_fa29;
loc_fa26: // 0ed9:0c96
    goto loc_fb77;
loc_fa29: // 0ed9:0c99
    ax = memoryAGet16(ds, di + 65532);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, di + 65532, ax);
    ax = memoryAGet16(ds, di + 65530);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, di + 65530, ax);
    ax = memoryAGet16(ds, di + 65528);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, di + 65528, ax);
    ax = memoryAGet16(ds, di + 65524);
    tl = al; al = ah; ah = tl;
    memoryASet16(ds, di + 65524, ax);
    ax = memoryAGet16(ds, di + 65526);
    tl = ah; ah = al; al = tl;
    memoryASet16(ds, di + 65526, ax);
    al &= 0xc0;
    if (al)
        goto loc_fa26;
    si = di;
    ax = memoryAGet16(cs, 0x0ded);
    if (ax == 0x0000)
        goto loc_fa63;
    goto loc_fb3c;
loc_fa63: // 0ed9:0cd3
    ax = memoryAGet16(ds, di + 65532);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fa26;
    if (!dx)
        goto loc_fa26;
loc_fa72: // 0ed9:0ce2
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 1, al);
    al = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 4, ah);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, si + 6);
    ah = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, al);
    al = memoryAGet(ds, si + 5);
    memoryASet(ds, si + 5, ah);
    memoryASet(ds, si + 6, al);
    ax = memoryAGet16(ds, si);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    tl = bl; bl = bh; bh = tl;
    memoryASet16(ds, si, bx);
    ax = memoryAGet16(ds, si + 4);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl16(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl16(bx, 0x0001);
    tl = bl; bl = bh; bh = tl;
    memoryASet16(ds, si + 4, bx);
    ax = 0;
    memoryASet16(ds, si + 2, ax);
    memoryASet16(ds, si + 6, ax);
    si += 0x0008;
    dx--;
    if (dx)
        goto loc_fb36;
    if (--cx)
        goto loc_fb39;
    goto loc_fb77;
loc_fb36: // 0ed9:0da6
    goto loc_fa72;
loc_fb39: // 0ed9:0da9
    goto loc_fa63;
loc_fb3c: // 0ed9:0dac
    ax = memoryAGet16(ds, di + 65532);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fb77;
    if (!dx)
        goto loc_fb77;
loc_fb4b: // 0ed9:0dbb
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 1, al);
    al = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 4, ah);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, si + 6);
    ah = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, al);
    al = memoryAGet(ds, si + 5);
    memoryASet(ds, si + 5, ah);
    memoryASet(ds, si + 6, al);
    si += 0x0008;
    dx--;
    if (dx)
        goto loc_fb4b;
    if (--cx)
        goto loc_fb3c;
loc_fb77: // 0ed9:0de7
    cx = pop();
    ax = pop();
    si = pop();
    di = pop();
    ds = pop();
}
void sub_fb7f() // 0ed9:0def
{
    ax = memoryAGet16(ss, bp + 4);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax &= 0xfffe;
    memoryASet16(ds, 0x680d, ax);
    dx = memoryAGet16(ss, bp + 8);
    dx++;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    dx &= 0xfffe;
    memoryASet16(ds, 0x680f, dx);
    dx -= ax;
    memoryASet16(ds, 0x6815, dx);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x6811, ax);
    dx = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x6813, dx);
    dx -= ax;
    memoryASet16(ds, 0x6817, dx);
}
void sub_fbb9() // 0ed9:0e29
{
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (!bx)
        goto loc_fbc3;
    sub_fbc4();
loc_fbc3: // 0ed9:0e33
    return;
}
void sub_fbc4() // 0ed9:0e34
{
    memoryASet16(ds, 0x6809, bx);
    si = es;
    memoryASet16(ds, 0x680b, si);
    ax = bx;
    ax |= si;
    if (!ax)
        goto loc_fbd7;
    sub_fbd8();
loc_fbd7: // 0ed9:0e47
    return;
}
void sub_fbd8() // 0ed9:0e48
{
    bx = memoryAGet16(ds, 0x6809); es = memoryAGet16(ds, 0x6809 + 2);
loc_fbdc: // 0ed9:0e4c
    push(es);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    ax = es;
    ax |= di;
    if (!ax)
        goto loc_fbe9;
    push(bx);
    goto loc_fbef;
loc_fbe9: // 0ed9:0e59
    goto loc_fc8f;
loc_fbec: // 0ed9:0e5c
    goto loc_fc87;
loc_fbef: // 0ed9:0e5f
    al = memoryAGet(es, di + 10);
    if (!(al & 0x80))
        goto loc_fbec;
    ax = memoryAGet16(es, di);
    if (!(memoryAGet(es, di + 10) & 0x20))
        goto loc_fc11;
    bx = memoryAGet16(es, di + 16);
    bx <<= 1;
    bx <<= 1;
    ax -= bx;
    ax += memoryAGet16(es, di + 20);
    goto loc_fc15;
loc_fc11: // 0ed9:0e81
    ax -= memoryAGet16(es, di + 20);
loc_fc15: // 0ed9:0e85
    if (!(memoryAGet(es, di + 10) & 0x01))
        goto loc_fc22;
    ax += 0x0004;
    ax &= 0xfff8;
loc_fc22: // 0ed9:0e92
    bx = ax;
    bx &= 0x0007;
    memoryASet(cs, 0x3216, bl);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x6821, ax);
    ax = memoryAGet16(es, di + 2);
    ax -= memoryAGet16(es, di + 22);
    memoryASet16(ds, 0x6823, ax);
    dx = memoryAGet16(ds, 0x6813);
    ax = memoryAGet16(ds, 0x6823);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = memoryAGet16(ds, 0x680f);
    ax = memoryAGet16(ds, 0x6821);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = ax;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    dx += ax;
    if ((short)dx < 0)
        goto loc_fbec;
    ax = memoryAGet16(ds, 0x680d);
    if ((short)dx < (short)ax)
        goto loc_fbec;
    ax = memoryAGet16(ds, 0x6823);
    dx = ax;
    ax = memoryAGet16(es, di + 18);
    dx += ax;
    if ((short)dx < 0)
        goto loc_fc87;
    ax = memoryAGet16(ds, 0x6811);
    if ((short)dx < (short)ax)
        goto loc_fc87;
    push(bx);
    push(di);
    sub_fdcd();
    di = pop();
    bx = pop();
    goto loc_fbec;
loc_fc87: // 0ed9:0ef7
    bx = pop();
    es = pop();
    bx += 0x0004;
    goto loc_fbdc;
loc_fc8f: // 0ed9:0eff
    es = pop();
}
void sub_fce0() // 0ed9:0f50
{
    memoryASet(ds, 0x683c, 0x00);
    memoryASet16(ds, 0x6819, 0x0000);
    ax = memoryAGet16(ds, 0x680d);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax >= 0)
        goto loc_fcfb;
    ax = -ax;
    memoryASet16(ds, 0x6819, ax);
    ax = 0;
loc_fcfb: // 0ed9:0f6b
    memoryASet16(ds, 0x681f, ax);
    if (!ax)
        goto loc_fd07;
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x02);
loc_fd07: // 0ed9:0f77
    ax = memoryAGet16(ds, 0x680f);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax < 0)
        goto loc_fd31;
    bx = memoryAGet16(es, di + 16);
    bx >>= 1;
    bx++;
    ax -= bx;
    if ((short)ax < 0)
        goto loc_fd31;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    ax -= memoryAGet16(ds, 0x681f);
    if ((short)ax >= 0)
        goto loc_fd29;
    ax = 0;
loc_fd29: // 0ed9:0f99
    memoryASet16(ds, 0x6835, ax);
    goto loc_fd43;
loc_fd2e: // 0ed9:0f9e
    ax = 0;
    return;
loc_fd31: // 0ed9:0fa1
    ax = memoryAGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryAGet16(ds, 0x680f);
    ax -= memoryAGet16(ds, 0x6821);
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x01);
loc_fd43: // 0ed9:0fb3
    memoryASet16(ds, 0x6835, ax);
    memoryASet16(ds, 0x681b, 0x0000);
    ax = memoryAGet16(ds, 0x6811);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax >= 0)
        goto loc_fd5c;
    ax = -ax;
    memoryASet16(ds, 0x681b, ax);
    ax = 0;
loc_fd5c: // 0ed9:0fcc
    memoryASet16(ds, 0x681d, ax);
    ax = memoryAGet16(ds, 0x6811);
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax -= memoryAGet16(es, di + 18);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(es, di + 18);
    goto loc_fd8e;
loc_fd7d: // 0ed9:0fed
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6811);
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
loc_fd8e: // 0ed9:0ffe
    memoryASet16(ds, 0x6837, ax);
    ax = memoryAGet16(ds, 0x681b);
    ax += memoryAGet16(ds, 0x6811);
    if (!ax)
        goto loc_fda0;
    bl = 0x28;
    mul8(bl);
loc_fda0: // 0ed9:1010
    ax += memoryAGet16(ds, 0x56e2);
    ax += memoryAGet16(ds, 0x6819);
    ax += memoryAGet16(ds, 0x680d);
    memoryASet16(ds, 0x56e8, ax);
    ax = memoryAGet16(ds, 0x6835);
    if (!ax)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    ax = memoryAGet16(ds, 0x6837);
    if (!ax)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    if ((short)ax >= (short)0x0064)
        goto loc_fdca;
    ax |= 0x0001;
    return;
loc_fdca: // 0ed9:103a
    goto loc_fd2e;
}
void sub_fdcd() // 0ed9:103d
{
    sub_fce0();
    ax = memoryAGet16(ds, 0x681d);
    if (!ax)
        goto loc_fddf;
    bl = memoryAGet(es, di + 16);
    bl += bl;
    mul8(bl);
loc_fddf: // 0ed9:104f
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    memoryASet16(ds, 0x56e6, ax);
    ax = memoryAGet16(ds, 0x6835);
    dx = memoryAGet16(es, di + 16);
    dx >>= 1;
    cl = 0x28;
    cl -= al;
    ch = 0;
    dh = ch;
    memoryASet(ds, 0x683a, 0x00);
    goto loc_fe36;
    // gap 44 bytes
loc_fe36: // 0ed9:10a6
    push(es);
    push(di);
    al = memoryAGet(cs, 0x3216);
    memoryASet(ds, 0x683b, al);
    {int tmp1 = memoryAGet16(es, di + 12); int tmp2 = memoryAGet16(es, di + 12 + 2); bp = tmp1; es = tmp2; /*ggg2!!check*/};
    bp += memoryAGet16(ds, 0x56e6);
    memoryASet16(ds, 0x6825, bp);
    ax = es;
    memoryASet16(ds, 0x6827, ax);
    si = memoryAGet16(ds, 0x56e8);
    memoryASet16(ds, 0x682d, si);
    ax = memoryAGet16(ds, 0x56e4);
    memoryASet16(ds, 0x682f, ax);
    memoryASet16(ds, 0x6833, 0x0028);
    memoryASet16(ds, 0x6831, dx);
    si = 0x6825;
    sub_fe71();
    di = pop();
    es = pop();
}
void sub_fe71() // 0ed9:10e1
{
    goto loc_fe71;
loc_f9b4: // 0ed9:0c24
    push(ax);
    ax = 0x0003;
    interrupt(0x10);
    ax = pop();
    dl = al;
    ah = 0x02;
    interrupt(0x21);
    interrupt(0x20);
    stop("terminating");
    // gap 1198 bytes
loc_fe71: // 0ed9:10e1
    push(ds);
    al = memoryAGet(ds, si + 23);
    memoryASet(cs, 0x3215, al);
    al = memoryAGet(ds, si + 22);
    memoryASet(cs, 0x3216, al);
    ax = memoryAGet16(ds, si + 18);
    ax--;
    memoryASet16(cs, 0x3213, ax);
    if ((short)ax >= 0)
        goto loc_fe8d;
    goto loc_10ec9;
loc_fe8d: // 0ed9:10fd
    bx = memoryAGet16(ds, si + 16);
    ax = memoryAGet16(ds, si + 14);
    ax -= bx;
    memoryASet16(cs, 0x320f, ax);
    cx = memoryAGet16(ds, si + 12);
    cx -= bx;
    al = memoryAGet(ds, si + 21);
    push(dx);
    push(ax);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    goto loc_feab;
loc_feab: // 0ed9:111b
    goto loc_fead;
loc_fead: // 0ed9:111d
    dx++;
    al = 0x00;
    out8(dx, al);
    ax = pop();
    dx = pop();
    push(dx);
    push(ax);
    dx = 0x03ce;
    al = 0x03;
    out8(dx, al);
    goto loc_febd;
loc_febd: // 0ed9:112d
    goto loc_febf;
loc_febf: // 0ed9:112f
    dx++;
    al = 0x00;
    out8(dx, al);
    ax = pop();
    dx = pop();
    push(dx);
    push(ax);
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    goto loc_fecf;
loc_fecf: // 0ed9:113f
    goto loc_fed1;
loc_fed1: // 0ed9:1141
    dx++;
    al = 0x0f;
    out8(dx, al);
    ax = pop();
    dx = pop();
    bx += bx;
    ah = 0;
    ax += ax;
    dx = ax;
    ax += ax;
    ax += dx;
    bp = 0x328f;
    bp += ax;
    dx = memoryAGet16(cs, bp + 4);
    di = memoryAGet16(cs, bp);
    ax = memoryAGet16(cs, bx + di);
    memoryASet16(cs, 0x25e2, ax);
    ax = memoryAGet16(cs, bp + 2);
    push(ax);
    push(bx);
    al = memoryAGet(cs, 0x320e);
    bx = 0x11da;
    al &= 0x40;
    if (!al)
        goto loc_ff0b;
    bx = 0x11e2;
loc_ff0b: // 0ed9:117b
    ax = memoryAGet16(cs, bx);
    memoryASet16(cs, 0x11d5, ax);
    al = memoryAGet(cs, bx + 2);
    memoryASet(cs, 0x11d7, al);
    al = memoryAGet(cs, bx + 4);
    memoryASet(cs, 0x11d8, al);
    al = memoryAGet(cs, bx + 6);
    memoryASet(cs, 0x11d9, al);
    bx = pop();
    ax = pop();
    bp = memoryAGet16(ds, si); es = memoryAGet16(ds, si + 2);
    {int tmp1 = memoryAGet16(ds, si + 8); int tmp2 = memoryAGet16(ds, si + 8 + 2); si = tmp1; ds = tmp2; /*ggg2!!check*/};
    bl = memoryAGet(cs, 0x3216);
    bh = 0;
    bx += bx;
    di = memoryAGet16(cs, bx + 13093);
    if (dx == 0x0004)
        goto loc_ff5a;
    if (dx == 0x0002)
        goto loc_ff5c;
    if (dx == 0x0001)
        goto loc_ff58;
    if (dx == 0x0003)
        goto loc_ff58;
loc_ff53: // 0ed9:11c3
    ah = 0x01;
    goto loc_f9b4;
loc_ff58: // 0ed9:11c8
    goto loc_ff53;
loc_ff5a: // 0ed9:11ca
    cx += cx;
loc_ff5c: // 0ed9:11cc
    cx += cx;
    memoryASet16(cs, 0x3211, cx);
    switch (ax)
    {
        case 0x210b: goto loc_10e9b;
        default:
            stop("ind 0ed9:11d3");
    }
    // gap 3441 bytes
loc_10cd6: // 0ed9:1f46
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror16(ax, cl);
    dx = ror16(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out16(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out8(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out8(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out8(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl; bl = bh; bh = tl;
    tl = cl; cl = ch; ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror16(ax, cl);
    dx = ror16(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out16(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out8(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out8(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out8(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl; bl = bh; bh = tl;
    tl = cl; cl = ch; ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10d94: // 0ed9:2004
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror16(ax, cl);
    dx = ror16(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out16(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out8(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out8(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out8(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl; bl = bh; bh = tl;
    tl = cl; cl = ch; ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10df3: // 0ed9:2063
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror16(ax, cl);
    dx = ror16(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out16(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out8(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out8(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out8(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl; bl = bh; bh = tl;
    tl = cl; cl = ch; ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
    al = memoryAGet(cs, 0x3215);
    al &= 0x01;
    if (al)
        goto loc_10e8a;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out16(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out8(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out8(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out8(dx, al);
    memoryASet(ds, si, ch);
loc_10e8a: // 0ed9:20fa
    memoryASet16(cs, 0x3213, memoryAGet16(cs, 0x3213) - 1);
    if ((short)memoryAGet16(cs, 0x3213) < 0)
        goto loc_10ec9;
    bp += memoryAGet16(cs, 0x3211);
    si += memoryAGet16(cs, 0x320f);
loc_10e9b: // 0ed9:210b
    bx = 0;
    cx = 0;
    al = memoryAGet(cs, 0x3215);
    al &= 0x02;
    if (!al)
        goto loc_10ec6;
    bx = memoryAGet16(es, bp - 4);
    ax = memoryAGet16(es, bp - 2);
    cl = memoryAGet(cs, 0x3216);
    bx = ror16(bx, cl);
    ax = ror16(ax, cl);
    cx = ax;
    di = ~di;
    tl = bl; bl = bh; bh = tl;
    tl = cl; cl = ch; ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10ec6: // 0ed9:2136
    goto loc_11371;
loc_10ec9: // 0ed9:2139
    dx = 0x03ce;
    ax = 0xff08;
    out16(dx, ax);
    ds = pop();
    return;
    // gap 1183 bytes
loc_11371: // 0ed9:25e1
    ax = memoryAGet16(cs, 0x25e2);
    switch (ax)
    {
        case 0x2004: goto loc_10d94;
        case 0x2063: goto loc_10df3;
        case 0x1f46: goto loc_10cd6;
        case 0x20fa: goto loc_10e8a;
        default:
            stop("ind 0ed9:25e4");
    }
}
void sub_113fa() // 0ed9:266a
{
    push(ds);
    push(di);
    push(si);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    {int tmp1 = memoryAGet16(es, di); int tmp2 = memoryAGet16(es, di + 2); di = tmp1; ds = tmp2; /*ggg2!!check*/};
    cx = memoryAGet16(ds, di + 65500);
    tl = cl; cl = ch; ch = tl;
    if ((short)cx < 0)
        goto loc_11413;
    if (!cx)
        goto loc_11413;
    si = di;
    goto loc_11416;
loc_11413: // 0ed9:2683
    goto loc_1157e;
loc_11416: // 0ed9:2686
    ax = memoryAGet16(ds, di + 65502);
    tl = al; al = ah; ah = tl;
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_11413;
    if (!dx)
        goto loc_11413;
    ax = memoryAGet16(ds, di + 65514);
    tl = al; al = ah; ah = tl;
    flags.carry = ax < 0x0003;
    if (ax == 0x0003)
        goto loc_11434;
    goto loc_11580;
loc_11434: // 0ed9:26a4
    push(cx);
    push(dx);
    push(di);
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    cx = memoryAGet16(ds, si + 4);
    dx = memoryAGet16(ds, si + 6);
    tl = ah; ah = al; al = tl;
    tl = bh; bh = bl; bl = tl;
    tl = ch; ch = cl; cl = tl;
    tl = dh; dh = dl; dl = tl;
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    tx = di; di = ax; ax = tx;
    tl = ah; ah = al; al = tl;
    memoryASet16(ds, si, ax);
    tx = di; di = ax; ax = tx;
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    tx = di; di = ax; ax = tx;
    tl = ah; ah = al; al = tl;
    memoryASet16(ds, si + 2, ax);
    tx = di; di = ax; ax = tx;
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    tx = di; di = ax; ax = tx;
    tl = ah; ah = al; al = tl;
    memoryASet16(ds, si + 4, ax);
    tx = di; di = ax; ax = tx;
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    dx = rcl16(dx, 0x0001);
    di = rcl16(di, 0x0001);
    cx = rcl16(cx, 0x0001);
    di = rcl16(di, 0x0001);
    bx = rcl16(bx, 0x0001);
    di = rcl16(di, 0x0001);
    ax = rcl16(ax, 0x0001);
    di = rcl16(di, 0x0001);
    tx = di; di = ax; ax = tx;
    tl = ah; ah = al; al = tl;
    memoryASet16(ds, si + 6, ax);
    tx = di; di = ax; ax = tx;
    di = pop();
    dx = pop();
    cx = pop();
    flags.carry = (si + 0x0008) >= 0x10000;
    si += 0x0008;
    dx--;
    if (dx)
        goto loc_1157b;
    if (--cx)
        goto loc_11578;
loc_11570: // 0ed9:27e0
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    si = pop();
    di = pop();
    ds = pop();
    return;
loc_11578: // 0ed9:27e8
    goto loc_11416;
loc_1157b: // 0ed9:27eb
    goto loc_11434;
loc_1157e: // 0ed9:27ee
    goto loc_11570;
loc_11580: // 0ed9:27f0
    goto loc_11570;
}
void sub_11582() // 0ed9:27f2
{
    di = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
loc_11585: // 0ed9:27f5
    ax = es;
    bx = memoryAGet16(es, di);
    if (bx == 0xffff)
        goto loc_115c7;
    tl = bl; bl = bh; bh = tl;
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    bx = ror16(bx, 0x0001);
    ax += bx;
    cx = bx;
    bx = memoryAGet16(es, di + 2);
    cx |= bx;
    if (!cx)
        goto loc_115cc;
    tl = bl; bl = bh; bh = tl;
    cx = bx;
    cx &= 0x000f;
    cx += 0x0800;
    bx &= 0xfff0;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax += bx;
    memoryASet16(es, di + 2, ax);
    memoryASet16(es, di, cx);
    sub_113fa();
loc_115c7: // 0ed9:2837
    di += 0x0004;
    goto loc_11585;
loc_115cc: // 0ed9:283c
    return;
}
void sub_115cd() // 0ed9:283d
{
    cx = memoryAGet16(ss, bp + 6);
    cx >>= 1;
    cx += 0x0001;
    cx &= 0xfffe;
    di = memoryAGet16(ss, bp + 4);
    di >>= 1;
    di &= 0xfffe;
    cx -= di;
    memoryASet16(ds, 0x680d, di);
    memoryASet16(ds, 0x680f, cx);
    di = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x6811, di);
    cx = memoryAGet16(ss, bp + 10);
    cx -= di;
    memoryASet16(ds, 0x6813, cx);
}
void sub_115fb() // 0ed9:286b
{
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    if (!bx)
        goto loc_11605;
    sub_11606();
loc_11605: // 0ed9:2875
    return;
}
void sub_11606() // 0ed9:2876
{
    memoryASet16(ds, 0x6809, bx);
    si = es;
    memoryASet16(ds, 0x680b, si);
    ax = bx;
    ax |= si;
    if (!ax)
        goto loc_11619;
    sub_1161a();
loc_11619: // 0ed9:2889
    return;
}
void sub_1161a() // 0ed9:288a
{
    bx = memoryAGet16(ds, 0x6809); es = memoryAGet16(ds, 0x6809 + 2);
loc_1161e: // 0ed9:288e
    push(es);
    {int tmp1 = memoryAGet16(es, bx); int tmp2 = memoryAGet16(es, bx + 2); di = tmp1; es = tmp2; /*ggg2!!check*/};
    ax = es;
    ax |= di;
    if (!ax)
        goto loc_1162b;
    push(bx);
    goto loc_11631;
loc_1162b: // 0ed9:289b
    goto loc_116bd;
loc_1162e: // 0ed9:289e
    goto loc_116b5;
loc_11631: // 0ed9:28a1
    al = memoryAGet(es, di + 10);
    if (!(al & 0x80))
        goto loc_1162e;
    ax = memoryAGet16(es, di);
    ax -= memoryAGet16(es, di + 20);
    bx = ax;
    bl &= 0x01;
    bl += bl;
    bl += bl;
    memoryASet(cs, 0x3216, bl);
    ax = sar16(ax, 0x0001);
    memoryASet16(ds, 0x6821, ax);
    ax = memoryAGet16(es, di + 2);
    ax -= memoryAGet16(es, di + 22);
    memoryASet16(ds, 0x6823, ax);
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    if (!ax)
        goto loc_1162e;
    ax = memoryAGet16(es, di + 18);
    if (!ax)
        goto loc_1162e;
    dx = memoryAGet16(ds, 0x6817);
    ax = memoryAGet16(ds, 0x6823);
    if ((short)dx <= (short)ax)
        goto loc_1162e;
    dx = memoryAGet16(ds, 0x6815);
    ax = memoryAGet16(ds, 0x6821);
    if ((short)dx <= (short)ax)
        goto loc_1162e;
    dx = ax;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    dx += ax;
    if ((short)dx < 0)
        goto loc_1162e;
    ax = memoryAGet16(ds, 0x680d);
    if ((short)dx <= (short)ax)
        goto loc_1162e;
    ax = memoryAGet16(ds, 0x6823);
    dx = ax;
    ax = memoryAGet16(es, di + 18);
    dx += ax;
    if ((short)dx < 0)
        goto loc_116b5;
    ax = memoryAGet16(ds, 0x6811);
    if ((short)dx <= (short)ax)
        goto loc_116b5;
    push(bx);
    push(di);
    sub_117e9();
    di = pop();
    bx = pop();
    goto loc_1162e;
loc_116b5: // 0ed9:2925
    bx = pop();
    es = pop();
    bx += 0x0004;
    goto loc_1161e;
loc_116bd: // 0ed9:292d
    es = pop();
}
void sub_11705() // 0ed9:2975
{
    memoryASet(ds, 0x683c, 0x00);
    memoryASet16(ds, 0x6819, 0x0000);
    ax = memoryAGet16(ds, 0x680d);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax >= 0)
        goto loc_11720;
    ax = -ax;
    memoryASet16(ds, 0x6819, ax);
    ax = 0;
loc_11720: // 0ed9:2990
    memoryASet16(ds, 0x681f, ax);
    if (!ax)
        goto loc_1172c;
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x02);
loc_1172c: // 0ed9:299c
    ax = memoryAGet16(ds, 0x6815);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax < 0)
        goto loc_11756;
    bx = memoryAGet16(es, di + 16);
    bx >>= 1;
    bx++;
    ax -= bx;
    if ((short)ax < 0)
        goto loc_11756;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    ax -= memoryAGet16(ds, 0x681f);
    if ((short)ax >= 0)
        goto loc_1174e;
    ax = 0;
loc_1174e: // 0ed9:29be
    memoryASet16(ds, 0x6835, ax);
    goto loc_11768;
loc_11753: // 0ed9:29c3
    ax = 0;
    return;
loc_11756: // 0ed9:29c6
    ax = memoryAGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6815);
    ax -= memoryAGet16(ds, 0x6821);
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x01);
loc_11768: // 0ed9:29d8
    memoryASet16(ds, 0x6835, ax);
    memoryASet16(ds, 0x681b, 0x0000);
    ax = memoryAGet16(ds, 0x6811);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax >= 0)
        goto loc_11781;
    ax = -ax;
    memoryASet16(ds, 0x681b, ax);
    ax = 0;
loc_11781: // 0ed9:29f1
    memoryASet16(ds, 0x681d, ax);
    ax = memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax < 0)
        goto loc_1179e;
    ax -= memoryAGet16(es, di + 18);
    if ((short)ax < 0)
        goto loc_1179e;
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(es, di + 18);
    goto loc_117ab;
loc_1179e: // 0ed9:2a0e
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
loc_117ab: // 0ed9:2a1b
    memoryASet16(ds, 0x6837, ax);
    ax = memoryAGet16(ds, 0x681b);
    ax += memoryAGet16(ds, 0x6811);
    if (!ax)
        goto loc_117bd;
    bl = 0xa0;
    mul8(bl);
loc_117bd: // 0ed9:2a2d
    ax += 0x56e2;
    ax += memoryAGet16(ds, 0x6819);
    ax += memoryAGet16(ds, 0x680d);
    memoryASet16(ds, 0x56e8, ax);
    ax = memoryAGet16(ds, 0x6835);
    if (!ax)
        goto loc_117e6;
    if ((short)ax < 0)
        goto loc_117e6;
    ax = memoryAGet16(ds, 0x6837);
    if (!ax)
        goto loc_117e6;
    if ((short)ax < 0)
        goto loc_117e6;
    if ((short)ax >= (short)0x0064)
        goto loc_117e6;
    ax |= 0x0001;
    return;
loc_117e6: // 0ed9:2a56
    goto loc_11753;
}
void sub_117e9() // 0ed9:2a59
{
    sub_11705();
    ax = memoryAGet16(ds, 0x681d);
    if (!ax)
        goto loc_117fb;
    bl = memoryAGet(es, di + 16);
    bl >>= 1;
    mul8(bl);
loc_117fb: // 0ed9:2a6b
    ax += memoryAGet16(ds, 0x681f);
    memoryASet16(ds, 0x56e6, ax);
    ax = memoryAGet16(ds, 0x6835);
    dx = memoryAGet16(es, di + 16);
    dx >>= 1;
    cl = 0xa0;
    cl -= al;
    ch = 0;
    dh = ch;
    memoryASet(ds, 0x683a, 0x00);
    goto loc_11846;
    // gap 44 bytes
loc_11846: // 0ed9:2ab6
    push(es);
    push(di);
    al = memoryAGet(cs, 0x3216);
    memoryASet(ds, 0x683b, al);
    bp = memoryAGet16(ds, di + 12); es = memoryAGet16(ds, di + 12 + 2);
    bp += memoryAGet16(ds, 0x56e6);
    memoryASet16(ds, 0x6825, bp);
    ax = es;
    memoryASet16(ds, 0x6827, ax);
    si = memoryAGet16(ds, 0x56e8);
    memoryASet16(ds, 0x682d, si);
    ax = 0x1228;
    memoryASet16(ds, 0x682f, ax);
    memoryASet16(ds, 0x6833, 0x00a0);
    memoryASet16(ds, 0x6831, dx);
    si = 0x6825;
    sub_11880();
    di = pop();
    es = pop();
}
void sub_11880() // 0ed9:2af0
{
    push(ds);
    al = memoryAGet(ds, si + 23);
    memoryASet(cs, 0x3215, al);
    al = memoryAGet(ds, si + 22);
    memoryASet(cs, 0x3216, al);
    ax = memoryAGet16(ds, si + 18);
    ax--;
    memoryASet16(cs, 0x3213, ax);
    if ((short)ax >= 0)
        goto loc_1189c;
    goto loc_1196f;
loc_1189c: // 0ed9:2b0c
    bx = memoryAGet16(ds, si + 16);
    ax = memoryAGet16(ds, si + 14);
    ax -= bx;
    memoryASet16(cs, 0x320f, ax);
    cx = memoryAGet16(ds, si + 12);
    cx -= bx;
    al = memoryAGet(ds, si + 21);
    dh = bl;
    bx += bx;
    ah = 0;
    ax += ax;
    di = ax;
    ax += ax;
    ax += di;
    bp = 0x3335;
    bp += ax;
    di = memoryAGet16(cs, bp);
    ax = memoryAGet16(cs, bx + di);
    memoryASet16(cs, 0x2be4, ax);
    ax = memoryAGet16(cs, bp + 2);
    bp = memoryAGet16(ds, si); es = memoryAGet16(ds, si + 2);
    {int tmp1 = memoryAGet16(ds, si + 8); int tmp2 = memoryAGet16(ds, si + 8 + 2); si = tmp1; ds = tmp2; /*ggg2!!check*/};
    bl = memoryAGet(cs, 0x3216);
    bh = 0;
    bx = sar16(bx, 0x0001);
    bx = sar16(bx, 0x0001);
    dl = memoryAGet(cs, bx + 13307);
    memoryASet16(cs, 0x3211, cx);
    stop(); //indirectJump(cs, ax); return; // 0ed9:2b5c;
    // gap 129 bytes
loc_1196f: // 0ed9:2bdf
    ds = pop();
}
void sub_11a78() // 0ed9:2ce8
{
}
void sub_11a79() // 0ed9:2ce9
{
}
void sub_11a7b() // 0ed9:2ceb
{
}
void sub_11a7c() // 0ed9:2cec
{
}
void sub_11a7d() // 0ed9:2ced +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x2d09;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    di = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    switch (ax)
    {
        case 0x006a: sub_edfa(); break;
        case 0x0c34: sub_f9c4(); break;
        case 0x27f2: sub_11582(); break;
        case 0x0c24: sub_f9b4(); break;
        case 0x2ce8: sub_11a78(); break;
        default:
            stop("ind 0ed9:2d01");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11aa5() // 0ed9:2d15 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    ds = dx;
    si = ax;
    bx = 0x2d37;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    switch (di)
    {
        case 0: sub_f21e(); break;
        case 2: sub_fe71(); break;
        case 4: sub_fe71(); break;
        case 6: sub_11880(); break;
        case 8: sub_f9b4(); break;
        case 10: sub_11a79(); break;
        default:
            stop("ind 0ed9:2d2f");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11afd() // 0ed9:2d6d +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    push(ds);
    si = memoryAGet16(ds, 0x56de); ds = memoryAGet16(ds, 0x56de + 2);
    {int tmp1 = memoryAGet16(ds, si); int tmp2 = memoryAGet16(ds, si + 2); si = tmp1; ds = tmp2; /*ggg2!!check*/};
    ax = ds;
    ds = pop();
    memoryASet16(ds, 0x56e2, si);
    memoryASet16(ds, 0x56e4, ax);
    bx = 0x2d9c;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    switch (di)
    {
        case 0: sub_eff2(); break;
        case 2: sub_fbb9(); break;
        case 4: sub_fbb9(); break;
        case 6: sub_115fb(); break;
        case 8: sub_f9b4(); break;
        case 10: sub_11a7b(); break;
        default:
            stop("ind 0ed9:2d94");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11b38() // 0ed9:2da8 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x2dc6;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    switch (di)
    {
        case 0: sub_efb8(); break;
        case 2: sub_fb7f(); break;
        case 4: sub_fb7f(); break;
        case 6: sub_115cd(); break;
        case 8: sub_f9b4(); break;
        case 10: sub_11a7c(); break;
        default:
            stop("ind 0ed9:2dbe");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11b62() // 0ed9:2dd2 +far +stackDrop2
{
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ss, bp + 4);
    ax <<= 1;
    ax <<= 1;
    ax += 0x5415;
    memoryASet16(ds, 0x56de, ax);
    ax = 0x1228;
    memoryASet16(ds, 0x56e0, ax);
    ds = pop();
    cs = pop();
}
void sub_11b7d() // 0ed9:2ded +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    si = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(ds, 0x56ee, 0x56f0);
loc_11b90: // 0ed9:2e00
    push(es);
    {int tmp1 = memoryAGet16(es, si); int tmp2 = memoryAGet16(es, si + 2); bx = tmp1; es = tmp2; /*ggg2!!check*/};
    ax = es;
    ax |= bx;
    if (ax)
        goto loc_11ba1;
    es = pop();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
    return;
loc_11ba1: // 0ed9:2e11
    ax = memoryAGet16(es, bx + 4);
    ax <<= 1;
    ax <<= 1;
    di = 0x1228;
    ds = di;
    di = memoryAGet16(es, bx + 6); ds = memoryAGet16(es, bx + 6 + 2);
    di += ax;
    {int tmp1 = memoryAGet16(ds, di); int tmp2 = memoryAGet16(ds, di + 2); di = tmp1; ds = tmp2; /*ggg2!!check*/};
    memoryASet16(es, bx + 12, di);
    ax = ds;
    memoryASet16(es, bx + 14, ax);
    ax |= di;
    if (ax)
        goto loc_11bca;
    memoryASet16(es, bx + 10, 0x0000);
loc_11bca: // 0ed9:2e3a
    ax = memoryAGet16(ds, di + 65534);
    memoryASet16(es, bx + 18, ax);
    ax = memoryAGet16(ds, di + 65532);
    memoryASet16(es, bx + 16, ax);
    ax = memoryAGet16(ds, di + 65530);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, di + 65528);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, di + 65524);
    memoryASet16(es, bx + 24, ax);
    if (ax < 0x0003)
        goto loc_11bf5;
    ax = 0x0003;
loc_11bf5: // 0ed9:2e65
    memoryASet16(es, bx + 24, ax);
    if (!ax)
        goto loc_11c20;
    push(ds);
    push(di);
    push(es);
    push(si);
    push(cx);
    cx = ax;
    si = di + 65524;
    di = bx + 26;
loc_11c0a: // 0ed9:2e7a
    si--;
    si--;
    movsw<ES_DI, DS_SI>();
    si--;
    si--;
    si--;
    si--;
    movsw<ES_DI, DS_SI>();
    si--;
    si--;
    si--;
    si--;
    movsw<ES_DI, DS_SI>();
    si--;
    si--;
    if (--cx)
        goto loc_11c0a;
    cx = pop();
    si = pop();
    es = pop();
    di = pop();
    ds = pop();
loc_11c20: // 0ed9:2e90
    al = memoryAGet(ds, di + 65526);
    memoryASet(es, bx + 11, al);
    al &= 0xc0;
    if (al)
        goto loc_11c32;
loc_11c2b: // 0ed9:2e9b
    si += 0x0004;
    es = pop();
    goto loc_11b90;
loc_11c32: // 0ed9:2ea2
    if (al & 0x40)
        goto loc_11c39;
    goto loc_11df8;
loc_11c39: // 0ed9:2ea9
    push(si);
    push(di);
    dh = memoryAGet(es, bx + 10);
    ax = memoryAGet16(es, 0x56ee);
    si = di;
    si -= 0x000c;
    di = ax;
    ax += 0x000c;
    memoryASet16(es, bx + 12, ax);
    ax = 0x1228;
    memoryASet16(es, bx + 14, ax);
    es = ax;
    cx = 0x0006;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    bx = si;
    al = memoryAGet(ds, si + 65532);
    al >>= 1;
    al >>= 1;
    ah = memoryAGet(ds, si + 65534);
    mul8(ah);
    si += ax;
    cx = ax;
    if (dh & 0x20)
        goto loc_11c79;
    goto loc_11d93;
loc_11c79: // 0ed9:2ee9
    cx = memoryAGet16(ds, bx + 65532);
    bp = cx;
    cx <<= 1;
    di -= cx;
    di -= 0x0008;
    cx = memoryAGet16(ds, bx + 65534);
loc_11c88: // 0ed9:2ef8
    push(cx);
    cx = bp;
    cx <<= 1;
    cx <<= 1;
    di += cx;
    cx = bp;
    cx >>= 1;
    cx >>= 1;
loc_11c97: // 0ed9:2f07
    push(cx);
    cl = memoryAGet(ds, bx);
    bx++;
    push(bx);
    ah = 0;
    al = 0;
    if (!(cl & 0x80))
        goto loc_11cb0;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cb0: // 0ed9:2f20
    ch = al;
    al = 0;
    if (!(cl & 0x40))
        goto loc_11cc4;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cc4: // 0ed9:2f34
    stosb<ES_DI>(al);
    al = 0;
    if (!(cl & 0x20))
        goto loc_11cd7;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cd7: // 0ed9:2f47
    dl = al;
    al = 0;
    if (!(cl & 0x10))
        goto loc_11ceb;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11ceb: // 0ed9:2f5b
    stosb<ES_DI>(al);
    al = 0;
    if (!(cl & 0x08))
        goto loc_11cfe;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cfe: // 0ed9:2f6e
    dh = al;
    al = 0;
    if (!(cl & 0x04))
        goto loc_11d12;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11d12: // 0ed9:2f82
    stosb<ES_DI>(al);
    al = 0;
    if (!(cl & 0x02))
        goto loc_11d25;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11d25: // 0ed9:2f95
    ah = al;
    al = 0;
    if (!(cl & 0x01))
        goto loc_11d3c;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    flags.carry = (bl + al) >= 0x100;
    bl += al;
    bh += 0x00 + flags.carry;
    al = memoryAGet(es, bx);
    si++;
loc_11d3c: // 0ed9:2fac
    stosb<ES_DI>(al);
    cl = ah;
    ax = memoryAGet16(cs, 0x0ded);
    if (ax != 0x0000)
        goto loc_11d60;
    ax = memoryAGet16(es, di + 65534);
    tl = al; al = ah; ah = tl;
    memoryASet16(es, di + 65534, ax);
    ax = memoryAGet16(es, di + 65532);
    tl = al; al = ah; ah = tl;
    memoryASet16(es, di + 65532, ax);
    tl = dl; dl = ch; ch = tl;
    tl = cl; cl = dh; dh = tl;
loc_11d60: // 0ed9:2fd0
    al = ch;
    stosb<ES_DI>(al);
    al = dl;
    stosb<ES_DI>(al);
    al = dh;
    stosb<ES_DI>(al);
    al = cl;
    stosb<ES_DI>(al);
    di -= 0x0010;
    bx = pop();
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d79;
    goto loc_11c97;
loc_11d79: // 0ed9:2fe9
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d82;
    goto loc_11c88;
loc_11d82: // 0ed9:2ff2
    bp <<= 1;
    di += bp;
    di += 0x0008;
    memoryASet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11d93: // 0ed9:3003
    push(cx);
    cl = memoryAGet(ds, bx);
    bx++;
    ax = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da0;
    al = memoryAGet(ds, si);
    si++;
loc_11da0: // 0ed9:3010
    stosb<ES_DI>(al);
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da8;
    ah = memoryAGet(ds, si);
    si++;
loc_11da8: // 0ed9:3018
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11db1;
    al = memoryAGet(ds, si);
    si++;
loc_11db1: // 0ed9:3021
    stosb<ES_DI>(al);
    ch = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dbb;
    ch = memoryAGet(ds, si);
    si++;
loc_11dbb: // 0ed9:302b
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dc4;
    al = memoryAGet(ds, si);
    si++;
loc_11dc4: // 0ed9:3034
    stosb<ES_DI>(al);
    dl = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dce;
    dl = memoryAGet(ds, si);
    si++;
loc_11dce: // 0ed9:303e
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dd7;
    al = memoryAGet(ds, si);
    si++;
loc_11dd7: // 0ed9:3047
    stosb<ES_DI>(al);
    al = ah;
    stosb<ES_DI>(al);
    al = ch;
    stosb<ES_DI>(al);
    al = dl;
    stosb<ES_DI>(al);
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dea;
    al = memoryAGet(ds, si);
    si++;
loc_11dea: // 0ed9:305a
    stosb<ES_DI>(al);
    cx = pop();
    if (--cx)
        goto loc_11d93;
    memoryASet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11df8: // 0ed9:3068
    goto loc_11c2b;
}
void sub_11ec7() // 0ed9:3137 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x66f0;
    cx = 0x0000;
    ax = memoryAGet16(ds, 0x541d);
    if (ax != 0x0000)
        goto loc_11f15;
loc_11edf: // 0ed9:314f
    dl = cl;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr8(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl8(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr8(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl8(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr8(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl8(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr8(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl8(ah, 0x01);
    ax <<= 1;
    memoryASet(ds, bx, ah);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11edf;
    goto loc_11f41;
loc_11f15: // 0ed9:3185
    ah = cl;
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl8(al, 0x01);
    memoryASet(ds, bx, al);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11f15;
loc_11f41: // 0ed9:31b1
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11f47() // 0ed9:31b7 +far +stackDrop2
{
    sp -= 2;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x67f0, ax);
    dx = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x67f2, dx);
    es = dx;
    di = ax;
    al = memoryAGet(es, di + 10);
    memoryASet(cs, 0x320e, al);
    bp = sp;
    ax = 0x1228;
    push(ax);
    ax = 0x67f0;
    push(ax);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    sub_11b7d();
    bp = pop();
    sp = bp;
    bp = sp;
    ax = 0x1228;
    push(ax);
    ax = 0x67f0;
    push(ax);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    sub_11afd();
    bp = pop();
    sp = bp;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    sp += 2;
    cs = pop();
}
void sub_12190() // 1219:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x0002;
    interrupt(0x10);
    si = 0x6840;
    bh = 0;
    dx = 0x0101;
    ah = 0x02;
    interrupt(0x10);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    si = 0x6858;
    di = 0x689e;
    bh = 0x00;
    cx = 0x0004;
    dx = 0x0a21;
loc_121bf: // 1219:002f
    if (memoryAGet(ds, di) != 0x01)
        goto loc_121d2;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_121d2: // 1219:0042
    si += 0x0011;
    di++;
    if (--cx)
        goto loc_121bf;
loc_121d8: // 1219:0048
    sync();
    al = 0x3f;
    push(cs); cs = 0x01ed; sub_b67a(); assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_121fe;
    al = 0x40;
    push(cs); cs = 0x01ed; sub_b67a(); assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_12206;
    al = 0x41;
    push(cs); cs = 0x01ed; sub_b67a(); assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_1220e;
    al = 0x42;
    push(cs); cs = 0x01ed; sub_b67a(); assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_12216;
    goto loc_121d8;
loc_121fe: // 1219:006e
    memoryASet16(ds, 0x689c, 0x8000);
    goto loc_12223;
loc_12206: // 1219:0076
    memoryASet16(ds, 0x689c, 0x0000);
    goto loc_12223;
loc_1220e: // 1219:007e
    memoryASet16(ds, 0x689c, 0x0001);
    goto loc_12223;
loc_12216: // 1219:0086
    memoryASet16(ds, 0x689c, 0x0004);
    goto loc_12223;
    // gap 5 bytes
loc_12223: // 1219:0093
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_12230() // 1223:0000 +far +stackDrop2
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    switch (bx)
    {
        case 0: sub_12245(); break;
        case 2: sub_12245(); break;
        case 4: sub_12245(); break;
        case 6: sub_12253(); break;
        case 8: sub_12254(); break;
        case 10: sub_12245(); break;
        default:
            stop("ind 1223:000b");
    }
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_12245() // 1223:0015
{
    dx = 0x03da;
loc_12248: // 1223:0018
    al = in8(dx);
    if (!(al & 0x08))
        goto loc_12248;
loc_1224d: // 1223:001d
    al = in8(dx);
    if (al & 0x08)
        goto loc_1224d;
}
void sub_12253() // 1223:0023
{
}
void sub_12254() // 1223:0024
{
}
void fixReloc(uint16_t seg)
{
    memoryASet16(seg, 0x0001, memoryAGet16(seg, 0x0001) + seg); // 103b -> 1228; lin=1
    memoryASet16(0x000b + seg, 0x000d, memoryAGet16(0x000b + seg, 0x000d) + seg); // 103a -> 1227; lin=bd
    memoryASet16(0x000f + seg, 0x0007, memoryAGet16(0x000f + seg, 0x0007) + seg); // 103a -> 1227; lin=f7
    memoryASet16(0x0753 + seg, 0x000c, memoryAGet16(0x0753 + seg, 0x000c) + seg); // 103b -> 1228; lin=753c
    memoryASet16(0x0757 + seg, 0x000d, memoryAGet16(0x0757 + seg, 0x000d) + seg); // 103b -> 1228; lin=757d
    memoryASet16(0x0759 + seg, 0x0000, memoryAGet16(0x0759 + seg, 0x0000) + seg); // 103b -> 1228; lin=7590
    memoryASet16(0x075a + seg, 0x000e, memoryAGet16(0x075a + seg, 0x000e) + seg); // 103b -> 1228; lin=75ae
    memoryASet16(0x075f + seg, 0x0001, memoryAGet16(0x075f + seg, 0x0001) + seg); // 103b -> 1228; lin=75f1
    memoryASet16(0x0772 + seg, 0x0001, memoryAGet16(0x0772 + seg, 0x0001) + seg); // 103b -> 1228; lin=7721
    memoryASet16(0x0773 + seg, 0x000e, memoryAGet16(0x0773 + seg, 0x000e) + seg); // 103b -> 1228; lin=773e
    memoryASet16(0x077d + seg, 0x000b, memoryAGet16(0x077d + seg, 0x000b) + seg); // 103b -> 1228; lin=77db
    memoryASet16(0x0781 + seg, 0x0001, memoryAGet16(0x0781 + seg, 0x0001) + seg); // 103b -> 1228; lin=7811
    memoryASet16(0x0786 + seg, 0x0005, memoryAGet16(0x0786 + seg, 0x0005) + seg); // 103b -> 1228; lin=7865
    memoryASet16(0x0798 + seg, 0x000f, memoryAGet16(0x0798 + seg, 0x000f) + seg); // 103b -> 1228; lin=798f
    memoryASet16(0x079b + seg, 0x000c, memoryAGet16(0x079b + seg, 0x000c) + seg); // 0000 -> 01ed; lin=79bc
    memoryASet16(0x079d + seg, 0x0006, memoryAGet16(0x079d + seg, 0x0006) + seg); // 0000 -> 01ed; lin=79d6
    memoryASet16(0x07a2 + seg, 0x000a, memoryAGet16(0x07a2 + seg, 0x000a) + seg); // 103b -> 1228; lin=7a2a
    memoryASet16(0x07a7 + seg, 0x0005, memoryAGet16(0x07a7 + seg, 0x0005) + seg); // 0000 -> 01ed; lin=7a75
    memoryASet16(0x07a7 + seg, 0x000b, memoryAGet16(0x07a7 + seg, 0x000b) + seg); // 103b -> 1228; lin=7a7b
    memoryASet16(0x07ab + seg, 0x000f, memoryAGet16(0x07ab + seg, 0x000f) + seg); // 103b -> 1228; lin=7abf
    memoryASet16(0x07b2 + seg, 0x0000, memoryAGet16(0x07b2 + seg, 0x0000) + seg); // 0000 -> 01ed; lin=7b20
    memoryASet16(0x07b3 + seg, 0x0009, memoryAGet16(0x07b3 + seg, 0x0009) + seg); // 0000 -> 01ed; lin=7b39
    memoryASet16(0x07b5 + seg, 0x0007, memoryAGet16(0x07b5 + seg, 0x0007) + seg); // 0ab9 -> 0ca6; lin=7b57
    memoryASet16(0x07b7 + seg, 0x0003, memoryAGet16(0x07b7 + seg, 0x0003) + seg); // 0c28 -> 0e15; lin=7b73
    memoryASet16(0x07b8 + seg, 0x0003, memoryAGet16(0x07b8 + seg, 0x0003) + seg); // 0ab9 -> 0ca6; lin=7b83
    memoryASet16(0x07b9 + seg, 0x0000, memoryAGet16(0x07b9 + seg, 0x0000) + seg); // 0ab9 -> 0ca6; lin=7b90
    memoryASet16(0x07ba + seg, 0x0003, memoryAGet16(0x07ba + seg, 0x0003) + seg); // 0ab9 -> 0ca6; lin=7ba3
    memoryASet16(0x07ba + seg, 0x000a, memoryAGet16(0x07ba + seg, 0x000a) + seg); // 0ab9 -> 0ca6; lin=7baa
    memoryASet16(0x07bb + seg, 0x000a, memoryAGet16(0x07bb + seg, 0x000a) + seg); // 0ab9 -> 0ca6; lin=7bba
    memoryASet16(0x07bc + seg, 0x0007, memoryAGet16(0x07bc + seg, 0x0007) + seg); // 0ab9 -> 0ca6; lin=7bc7
    memoryASet16(0x07bd + seg, 0x0004, memoryAGet16(0x07bd + seg, 0x0004) + seg); // 0ab9 -> 0ca6; lin=7bd4
    memoryASet16(0x07bd + seg, 0x000a, memoryAGet16(0x07bd + seg, 0x000a) + seg); // 0ab9 -> 0ca6; lin=7bda
    memoryASet16(0x07be + seg, 0x0007, memoryAGet16(0x07be + seg, 0x0007) + seg); // 0ab9 -> 0ca6; lin=7be7
    memoryASet16(0x07bf + seg, 0x0007, memoryAGet16(0x07bf + seg, 0x0007) + seg); // 0ab9 -> 0ca6; lin=7bf7
    memoryASet16(0x07c3 + seg, 0x0005, memoryAGet16(0x07c3 + seg, 0x0005) + seg); // 103b -> 1228; lin=7c35
    memoryASet16(0x07c5 + seg, 0x0004, memoryAGet16(0x07c5 + seg, 0x0004) + seg); // 0000 -> 01ed; lin=7c54
    memoryASet16(0x07c9 + seg, 0x000d, memoryAGet16(0x07c9 + seg, 0x000d) + seg); // 0000 -> 01ed; lin=7c9d
    memoryASet16(0x07ca + seg, 0x000f, memoryAGet16(0x07ca + seg, 0x000f) + seg); // 103b -> 1228; lin=7caf
    memoryASet16(0x07cb + seg, 0x000a, memoryAGet16(0x07cb + seg, 0x000a) + seg); // 103b -> 1228; lin=7cba
    memoryASet16(0x07d5 + seg, 0x0008, memoryAGet16(0x07d5 + seg, 0x0008) + seg); // 0000 -> 01ed; lin=7d58
    memoryASet16(0x07d6 + seg, 0x0007, memoryAGet16(0x07d6 + seg, 0x0007) + seg); // 0000 -> 01ed; lin=7d67
    memoryASet16(0x07d8 + seg, 0x000b, memoryAGet16(0x07d8 + seg, 0x000b) + seg); // 0000 -> 01ed; lin=7d8b
    memoryASet16(0x07ff + seg, 0x0003, memoryAGet16(0x07ff + seg, 0x0003) + seg); // 103b -> 1228; lin=7ff3
    memoryASet16(0x0801 + seg, 0x000f, memoryAGet16(0x0801 + seg, 0x000f) + seg); // 0000 -> 01ed; lin=801f
    memoryASet16(0x0803 + seg, 0x0007, memoryAGet16(0x0803 + seg, 0x0007) + seg); // 103b -> 1228; lin=8037
    memoryASet16(0x0804 + seg, 0x000c, memoryAGet16(0x0804 + seg, 0x000c) + seg); // 103b -> 1228; lin=804c
    memoryASet16(0x0805 + seg, 0x0008, memoryAGet16(0x0805 + seg, 0x0008) + seg); // 0000 -> 01ed; lin=8058
    memoryASet16(0x0806 + seg, 0x0004, memoryAGet16(0x0806 + seg, 0x0004) + seg); // 103b -> 1228; lin=8064
    memoryASet16(0x0807 + seg, 0x0003, memoryAGet16(0x0807 + seg, 0x0003) + seg); // 103b -> 1228; lin=8073
    memoryASet16(0x0809 + seg, 0x000b, memoryAGet16(0x0809 + seg, 0x000b) + seg); // 0cd5 -> 0ec2; lin=809b
    memoryASet16(0x080a + seg, 0x0008, memoryAGet16(0x080a + seg, 0x0008) + seg); // 0cd5 -> 0ec2; lin=80a8
    memoryASet16(0x080b + seg, 0x0009, memoryAGet16(0x080b + seg, 0x0009) + seg); // 0ab9 -> 0ca6; lin=80b9
    memoryASet16(0x080c + seg, 0x0009, memoryAGet16(0x080c + seg, 0x0009) + seg); // 0ab9 -> 0ca6; lin=80c9
    memoryASet16(0x0868 + seg, 0x000f, memoryAGet16(0x0868 + seg, 0x000f) + seg); // 103b -> 1228; lin=868f
    memoryASet16(0x0870 + seg, 0x000a, memoryAGet16(0x0870 + seg, 0x000a) + seg); // 103b -> 1228; lin=870a
    memoryASet16(0x0871 + seg, 0x0001, memoryAGet16(0x0871 + seg, 0x0001) + seg); // 0000 -> 01ed; lin=8711
    memoryASet16(0x0896 + seg, 0x0003, memoryAGet16(0x0896 + seg, 0x0003) + seg); // 0000 -> 01ed; lin=8963
    memoryASet16(0x0897 + seg, 0x0009, memoryAGet16(0x0897 + seg, 0x0009) + seg); // 103b -> 1228; lin=8979
    memoryASet16(0x089a + seg, 0x000a, memoryAGet16(0x089a + seg, 0x000a) + seg); // 103b -> 1228; lin=89aa
    memoryASet16(0x089b + seg, 0x000b, memoryAGet16(0x089b + seg, 0x000b) + seg); // 103b -> 1228; lin=89bb
    memoryASet16(0x089d + seg, 0x0002, memoryAGet16(0x089d + seg, 0x0002) + seg); // 103b -> 1228; lin=89d2
    memoryASet16(0x089f + seg, 0x0007, memoryAGet16(0x089f + seg, 0x0007) + seg); // 103b -> 1228; lin=89f7
    memoryASet16(0x08b8 + seg, 0x0006, memoryAGet16(0x08b8 + seg, 0x0006) + seg); // 103b -> 1228; lin=8b86
    memoryASet16(0x08c0 + seg, 0x0004, memoryAGet16(0x08c0 + seg, 0x0004) + seg); // 103b -> 1228; lin=8c04
    memoryASet16(0x08ed + seg, 0x0001, memoryAGet16(0x08ed + seg, 0x0001) + seg); // 0000 -> 01ed; lin=8ed1
    memoryASet16(0x0900 + seg, 0x000e, memoryAGet16(0x0900 + seg, 0x000e) + seg); // 0000 -> 01ed; lin=900e
    memoryASet16(0x0907 + seg, 0x0001, memoryAGet16(0x0907 + seg, 0x0001) + seg); // 103b -> 1228; lin=9071
    memoryASet16(0x0908 + seg, 0x0006, memoryAGet16(0x0908 + seg, 0x0006) + seg); // 0000 -> 01ed; lin=9086
    memoryASet16(0x090c + seg, 0x0000, memoryAGet16(0x090c + seg, 0x0000) + seg); // 103b -> 1228; lin=90c0
    memoryASet16(0x0924 + seg, 0x0007, memoryAGet16(0x0924 + seg, 0x0007) + seg); // 0000 -> 01ed; lin=9247
    memoryASet16(0x0925 + seg, 0x0007, memoryAGet16(0x0925 + seg, 0x0007) + seg); // 0000 -> 01ed; lin=9257
    memoryASet16(0x0937 + seg, 0x0001, memoryAGet16(0x0937 + seg, 0x0001) + seg); // 0cda -> 0ec7; lin=9371
    memoryASet16(0x0938 + seg, 0x000b, memoryAGet16(0x0938 + seg, 0x000b) + seg); // 0cda -> 0ec7; lin=938b
    memoryASet16(0x0939 + seg, 0x000f, memoryAGet16(0x0939 + seg, 0x000f) + seg); // 0cda -> 0ec7; lin=939f
    memoryASet16(0x093a + seg, 0x000e, memoryAGet16(0x093a + seg, 0x000e) + seg); // 0ce5 -> 0ed2; lin=93ae
    memoryASet16(0x093b + seg, 0x0004, memoryAGet16(0x093b + seg, 0x0004) + seg); // 0ce5 -> 0ed2; lin=93b4
    memoryASet16(0x093c + seg, 0x0005, memoryAGet16(0x093c + seg, 0x0005) + seg); // 0ab9 -> 0ca6; lin=93c5
    memoryASet16(0x093d + seg, 0x0005, memoryAGet16(0x093d + seg, 0x0005) + seg); // 0ab9 -> 0ca6; lin=93d5
    memoryASet16(0x093d + seg, 0x000e, memoryAGet16(0x093d + seg, 0x000e) + seg); // 0cec -> 0ed9; lin=93de
    memoryASet16(0x093e + seg, 0x000f, memoryAGet16(0x093e + seg, 0x000f) + seg); // 0cec -> 0ed9; lin=93ef
    memoryASet16(0x093f + seg, 0x0008, memoryAGet16(0x093f + seg, 0x0008) + seg); // 0cec -> 0ed9; lin=93f8
    memoryASet16(0x0940 + seg, 0x0002, memoryAGet16(0x0940 + seg, 0x0002) + seg); // 0cec -> 0ed9; lin=9402
    memoryASet16(0x0940 + seg, 0x000c, memoryAGet16(0x0940 + seg, 0x000c) + seg); // 0cec -> 0ed9; lin=940c
    memoryASet16(0x0941 + seg, 0x0006, memoryAGet16(0x0941 + seg, 0x0006) + seg); // 0cec -> 0ed9; lin=9416
    memoryASet16(0x0942 + seg, 0x0000, memoryAGet16(0x0942 + seg, 0x0000) + seg); // 0cec -> 0ed9; lin=9420
    memoryASet16(0x0942 + seg, 0x0007, memoryAGet16(0x0942 + seg, 0x0007) + seg); // 0cec -> 0ed9; lin=9427
    memoryASet16(0x0943 + seg, 0x0000, memoryAGet16(0x0943 + seg, 0x0000) + seg); // 0cec -> 0ed9; lin=9430
    memoryASet16(0x094e + seg, 0x0005, memoryAGet16(0x094e + seg, 0x0005) + seg); // 0000 -> 01ed; lin=94e5
    memoryASet16(0x0955 + seg, 0x0000, memoryAGet16(0x0955 + seg, 0x0000) + seg); // 0000 -> 01ed; lin=9550
    memoryASet16(0x0959 + seg, 0x0008, memoryAGet16(0x0959 + seg, 0x0008) + seg); // 0000 -> 01ed; lin=9598
    memoryASet16(0x097a + seg, 0x0007, memoryAGet16(0x097a + seg, 0x0007) + seg); // 102c -> 1219; lin=97a7
    memoryASet16(0x097b + seg, 0x000c, memoryAGet16(0x097b + seg, 0x000c) + seg); // 0ab9 -> 0ca6; lin=97bc
    memoryASet16(0x097c + seg, 0x0002, memoryAGet16(0x097c + seg, 0x0002) + seg); // 0ab9 -> 0ca6; lin=97c2
    memoryASet16(0x097d + seg, 0x0002, memoryAGet16(0x097d + seg, 0x0002) + seg); // 0ab9 -> 0ca6; lin=97d2
    memoryASet16(0x097e + seg, 0x0002, memoryAGet16(0x097e + seg, 0x0002) + seg); // 0ab9 -> 0ca6; lin=97e2
    memoryASet16(0x097e + seg, 0x0008, memoryAGet16(0x097e + seg, 0x0008) + seg); // 0ab9 -> 0ca6; lin=97e8
    memoryASet16(0x097e + seg, 0x000e, memoryAGet16(0x097e + seg, 0x000e) + seg); // 0ab9 -> 0ca6; lin=97ee
    memoryASet16(0x097f + seg, 0x0004, memoryAGet16(0x097f + seg, 0x0004) + seg); // 0ab9 -> 0ca6; lin=97f4
    memoryASet16(0x0980 + seg, 0x0001, memoryAGet16(0x0980 + seg, 0x0001) + seg); // 0ab9 -> 0ca6; lin=9801
    memoryASet16(0x0981 + seg, 0x0001, memoryAGet16(0x0981 + seg, 0x0001) + seg); // 0ab9 -> 0ca6; lin=9811
    memoryASet16(0x0981 + seg, 0x000e, memoryAGet16(0x0981 + seg, 0x000e) + seg); // 0ab9 -> 0ca6; lin=981e
    memoryASet16(0x0983 + seg, 0x0004, memoryAGet16(0x0983 + seg, 0x0004) + seg); // 0ab9 -> 0ca6; lin=9834
    memoryASet16(0x0984 + seg, 0x0004, memoryAGet16(0x0984 + seg, 0x0004) + seg); // 0ab9 -> 0ca6; lin=9844
    memoryASet16(0x0985 + seg, 0x0001, memoryAGet16(0x0985 + seg, 0x0001) + seg); // 0ab9 -> 0ca6; lin=9851
    memoryASet16(0x0986 + seg, 0x0001, memoryAGet16(0x0986 + seg, 0x0001) + seg); // 0ab9 -> 0ca6; lin=9861
    memoryASet16(0x0986 + seg, 0x0007, memoryAGet16(0x0986 + seg, 0x0007) + seg); // 1036 -> 1223; lin=9867
    memoryASet16(0x0a0b + seg, 0x000b, memoryAGet16(0x0a0b + seg, 0x000b) + seg); // 103b -> 1228; lin=a0bb
    memoryASet16(0x0aba + seg, 0x000d, memoryAGet16(0x0aba + seg, 0x000d) + seg); // 103b -> 1228; lin=abad
    memoryASet16(0x0abd + seg, 0x000a, memoryAGet16(0x0abd + seg, 0x000a) + seg); // 103b -> 1228; lin=abda
    memoryASet16(0x0ac2 + seg, 0x0000, memoryAGet16(0x0ac2 + seg, 0x0000) + seg); // 103b -> 1228; lin=ac20
    memoryASet16(0x0ac7 + seg, 0x0007, memoryAGet16(0x0ac7 + seg, 0x0007) + seg); // 103b -> 1228; lin=ac77
    memoryASet16(0x0acd + seg, 0x000a, memoryAGet16(0x0acd + seg, 0x000a) + seg); // 103b -> 1228; lin=acda
    memoryASet16(0x0ad1 + seg, 0x0000, memoryAGet16(0x0ad1 + seg, 0x0000) + seg); // 103b -> 1228; lin=ad10
    memoryASet16(0x0ad6 + seg, 0x0001, memoryAGet16(0x0ad6 + seg, 0x0001) + seg); // 103b -> 1228; lin=ad61
    memoryASet16(0x0ad7 + seg, 0x0007, memoryAGet16(0x0ad7 + seg, 0x0007) + seg); // 103b -> 1228; lin=ad77
    memoryASet16(0x0adb + seg, 0x0001, memoryAGet16(0x0adb + seg, 0x0001) + seg); // 103b -> 1228; lin=adb1
    memoryASet16(0x0add + seg, 0x0004, memoryAGet16(0x0add + seg, 0x0004) + seg); // 103b -> 1228; lin=add4
    memoryASet16(0x0ae2 + seg, 0x000d, memoryAGet16(0x0ae2 + seg, 0x000d) + seg); // 0cd5 -> 0ec2; lin=ae2d
    memoryASet16(0x0ae4 + seg, 0x0007, memoryAGet16(0x0ae4 + seg, 0x0007) + seg); // 103b -> 1228; lin=ae47
    memoryASet16(0x0ae6 + seg, 0x0004, memoryAGet16(0x0ae6 + seg, 0x0004) + seg); // 103b -> 1228; lin=ae64
    memoryASet16(0x0aea + seg, 0x000b, memoryAGet16(0x0aea + seg, 0x000b) + seg); // 0000 -> 01ed; lin=aeab
    memoryASet16(0x0aeb + seg, 0x0004, memoryAGet16(0x0aeb + seg, 0x0004) + seg); // 0000 -> 01ed; lin=aeb4
    memoryASet16(0x0aed + seg, 0x0009, memoryAGet16(0x0aed + seg, 0x0009) + seg); // 0000 -> 01ed; lin=aed9
    memoryASet16(0x0aef + seg, 0x0001, memoryAGet16(0x0aef + seg, 0x0001) + seg); // 103b -> 1228; lin=aef1
    memoryASet16(0x0af1 + seg, 0x000a, memoryAGet16(0x0af1 + seg, 0x000a) + seg); // 103b -> 1228; lin=af1a
    memoryASet16(0x0b0f + seg, 0x000e, memoryAGet16(0x0b0f + seg, 0x000e) + seg); // 0cda -> 0ec7; lin=b0fe
    memoryASet16(0x0b10 + seg, 0x0008, memoryAGet16(0x0b10 + seg, 0x0008) + seg); // 103b -> 1228; lin=b108
    memoryASet16(0x0b13 + seg, 0x000a, memoryAGet16(0x0b13 + seg, 0x000a) + seg); // 0cda -> 0ec7; lin=b13a
    memoryASet16(0x0b1c + seg, 0x0006, memoryAGet16(0x0b1c + seg, 0x0006) + seg); // 103b -> 1228; lin=b1c6
    memoryASet16(0x0b3a + seg, 0x0004, memoryAGet16(0x0b3a + seg, 0x0004) + seg); // 103b -> 1228; lin=b3a4
    memoryASet16(0x0b3d + seg, 0x0002, memoryAGet16(0x0b3d + seg, 0x0002) + seg); // 0cda -> 0ec7; lin=b3d2
    memoryASet16(0x0b3d + seg, 0x000d, memoryAGet16(0x0b3d + seg, 0x000d) + seg); // 0cda -> 0ec7; lin=b3dd
    memoryASet16(0x0b3e + seg, 0x000e, memoryAGet16(0x0b3e + seg, 0x000e) + seg); // 103b -> 1228; lin=b3ee
    memoryASet16(0x0b42 + seg, 0x0004, memoryAGet16(0x0b42 + seg, 0x0004) + seg); // 103b -> 1228; lin=b424
    memoryASet16(0x0b4d + seg, 0x000e, memoryAGet16(0x0b4d + seg, 0x000e) + seg); // 103b -> 1228; lin=b4de
    memoryASet16(0x0b54 + seg, 0x0008, memoryAGet16(0x0b54 + seg, 0x0008) + seg); // 0cda -> 0ec7; lin=b548
    memoryASet16(0x0b55 + seg, 0x0003, memoryAGet16(0x0b55 + seg, 0x0003) + seg); // 0cda -> 0ec7; lin=b553
    memoryASet16(0x0b56 + seg, 0x0004, memoryAGet16(0x0b56 + seg, 0x0004) + seg); // 103b -> 1228; lin=b564
    memoryASet16(0x0b5b + seg, 0x0001, memoryAGet16(0x0b5b + seg, 0x0001) + seg); // 103b -> 1228; lin=b5b1
    memoryASet16(0x0b60 + seg, 0x000a, memoryAGet16(0x0b60 + seg, 0x000a) + seg); // 103b -> 1228; lin=b60a
    memoryASet16(0x0b65 + seg, 0x0002, memoryAGet16(0x0b65 + seg, 0x0002) + seg); // 103b -> 1228; lin=b652
    memoryASet16(0x0b68 + seg, 0x0004, memoryAGet16(0x0b68 + seg, 0x0004) + seg); // 0cda -> 0ec7; lin=b684
    memoryASet16(0x0b69 + seg, 0x0004, memoryAGet16(0x0b69 + seg, 0x0004) + seg); // 103b -> 1228; lin=b694
    memoryASet16(0x0b6d + seg, 0x000c, memoryAGet16(0x0b6d + seg, 0x000c) + seg); // 103b -> 1228; lin=b6dc
    memoryASet16(0x0b7d + seg, 0x0003, memoryAGet16(0x0b7d + seg, 0x0003) + seg); // 103b -> 1228; lin=b7d3
    memoryASet16(0x0b83 + seg, 0x000d, memoryAGet16(0x0b83 + seg, 0x000d) + seg); // 0cda -> 0ec7; lin=b83d
    memoryASet16(0x0b84 + seg, 0x000f, memoryAGet16(0x0b84 + seg, 0x000f) + seg); // 103b -> 1228; lin=b84f
    memoryASet16(0x0b8b + seg, 0x0000, memoryAGet16(0x0b8b + seg, 0x0000) + seg); // 103b -> 1228; lin=b8b0
    memoryASet16(0x0b90 + seg, 0x000d, memoryAGet16(0x0b90 + seg, 0x000d) + seg); // 103b -> 1228; lin=b90d
    memoryASet16(0x0b96 + seg, 0x0002, memoryAGet16(0x0b96 + seg, 0x0002) + seg); // 103b -> 1228; lin=b962
    memoryASet16(0x0b98 + seg, 0x000e, memoryAGet16(0x0b98 + seg, 0x000e) + seg); // 0cda -> 0ec7; lin=b98e
    memoryASet16(0x0b99 + seg, 0x000d, memoryAGet16(0x0b99 + seg, 0x000d) + seg); // 103b -> 1228; lin=b99d
    memoryASet16(0x0b9c + seg, 0x000e, memoryAGet16(0x0b9c + seg, 0x000e) + seg); // 103b -> 1228; lin=b9ce
    memoryASet16(0x0ba8 + seg, 0x0008, memoryAGet16(0x0ba8 + seg, 0x0008) + seg); // 103b -> 1228; lin=ba88
    memoryASet16(0x0bae + seg, 0x000c, memoryAGet16(0x0bae + seg, 0x000c) + seg); // 0cda -> 0ec7; lin=baec
    memoryASet16(0x0baf + seg, 0x000d, memoryAGet16(0x0baf + seg, 0x000d) + seg); // 103b -> 1228; lin=bafd
    memoryASet16(0x0bb5 + seg, 0x0007, memoryAGet16(0x0bb5 + seg, 0x0007) + seg); // 0cda -> 0ec7; lin=bb57
    memoryASet16(0x0bb6 + seg, 0x0008, memoryAGet16(0x0bb6 + seg, 0x0008) + seg); // 103b -> 1228; lin=bb68
    memoryASet16(0x0bbb + seg, 0x000e, memoryAGet16(0x0bbb + seg, 0x000e) + seg); // 103b -> 1228; lin=bbbe
    memoryASet16(0x0bc0 + seg, 0x0009, memoryAGet16(0x0bc0 + seg, 0x0009) + seg); // 103b -> 1228; lin=bc09
    memoryASet16(0x0bc2 + seg, 0x0001, memoryAGet16(0x0bc2 + seg, 0x0001) + seg); // 103b -> 1228; lin=bc21
    memoryASet16(0x0bc4 + seg, 0x000d, memoryAGet16(0x0bc4 + seg, 0x000d) + seg); // 103b -> 1228; lin=bc4d
    memoryASet16(0x0bd2 + seg, 0x000b, memoryAGet16(0x0bd2 + seg, 0x000b) + seg); // 103b -> 1228; lin=bd2b
    memoryASet16(0x0bd7 + seg, 0x0009, memoryAGet16(0x0bd7 + seg, 0x0009) + seg); // 103b -> 1228; lin=bd79
    memoryASet16(0x0bdc + seg, 0x0007, memoryAGet16(0x0bdc + seg, 0x0007) + seg); // 103b -> 1228; lin=bdc7
    memoryASet16(0x0be0 + seg, 0x0004, memoryAGet16(0x0be0 + seg, 0x0004) + seg); // 103b -> 1228; lin=be04
    memoryASet16(0x0be4 + seg, 0x0006, memoryAGet16(0x0be4 + seg, 0x0006) + seg); // 103b -> 1228; lin=be46
    memoryASet16(0x0be6 + seg, 0x000c, memoryAGet16(0x0be6 + seg, 0x000c) + seg); // 103b -> 1228; lin=be6c
    memoryASet16(0x0bea + seg, 0x0007, memoryAGet16(0x0bea + seg, 0x0007) + seg); // 103b -> 1228; lin=bea7
    memoryASet16(0x0bec + seg, 0x0001, memoryAGet16(0x0bec + seg, 0x0001) + seg); // 103b -> 1228; lin=bec1
    memoryASet16(0x0bee + seg, 0x000b, memoryAGet16(0x0bee + seg, 0x000b) + seg); // 103b -> 1228; lin=beeb
    memoryASet16(0x0bef + seg, 0x000e, memoryAGet16(0x0bef + seg, 0x000e) + seg); // 103b -> 1228; lin=befe
    memoryASet16(0x0bf1 + seg, 0x0001, memoryAGet16(0x0bf1 + seg, 0x0001) + seg); // 103b -> 1228; lin=bf11
    memoryASet16(0x0bf5 + seg, 0x0003, memoryAGet16(0x0bf5 + seg, 0x0003) + seg); // 103b -> 1228; lin=bf53
    memoryASet16(0x0bfa + seg, 0x0004, memoryAGet16(0x0bfa + seg, 0x0004) + seg); // 103b -> 1228; lin=bfa4
    memoryASet16(0x0bfb + seg, 0x0008, memoryAGet16(0x0bfb + seg, 0x0008) + seg); // 103b -> 1228; lin=bfb8
    memoryASet16(0x0bfd + seg, 0x0007, memoryAGet16(0x0bfd + seg, 0x0007) + seg); // 103b -> 1228; lin=bfd7
    memoryASet16(0x0bfe + seg, 0x000e, memoryAGet16(0x0bfe + seg, 0x000e) + seg); // 103b -> 1228; lin=bfee
    memoryASet16(0x0c06 + seg, 0x0000, memoryAGet16(0x0c06 + seg, 0x0000) + seg); // 0cec -> 0ed9; lin=c060
    memoryASet16(0x0c13 + seg, 0x000f, memoryAGet16(0x0c13 + seg, 0x000f) + seg); // 103b -> 1228; lin=c13f
    memoryASet16(0x0c21 + seg, 0x000c, memoryAGet16(0x0c21 + seg, 0x000c) + seg); // 103b -> 1228; lin=c21c
    memoryASet16(0x0c28 + seg, 0x0006, memoryAGet16(0x0c28 + seg, 0x0006) + seg); // 103b -> 1228; lin=c286
    memoryASet16(0x0c2b + seg, 0x0003, memoryAGet16(0x0c2b + seg, 0x0003) + seg); // 0cda -> 0ec7; lin=c2b3
    memoryASet16(0x0c2c + seg, 0x0009, memoryAGet16(0x0c2c + seg, 0x0009) + seg); // 103b -> 1228; lin=c2c9
    memoryASet16(0x0c2e + seg, 0x0001, memoryAGet16(0x0c2e + seg, 0x0001) + seg); // 103b -> 1228; lin=c2e1
    memoryASet16(0x0c34 + seg, 0x0007, memoryAGet16(0x0c34 + seg, 0x0007) + seg); // 0cda -> 0ec7; lin=c347
    memoryASet16(0x0c36 + seg, 0x0000, memoryAGet16(0x0c36 + seg, 0x0000) + seg); // 0cda -> 0ec7; lin=c360
    memoryASet16(0x0c37 + seg, 0x000c, memoryAGet16(0x0c37 + seg, 0x000c) + seg); // 0cda -> 0ec7; lin=c37c
    memoryASet16(0x0c39 + seg, 0x0001, memoryAGet16(0x0c39 + seg, 0x0001) + seg); // 0cda -> 0ec7; lin=c391
    memoryASet16(0x0c40 + seg, 0x0002, memoryAGet16(0x0c40 + seg, 0x0002) + seg); // 103b -> 1228; lin=c402
    memoryASet16(0x0c41 + seg, 0x0005, memoryAGet16(0x0c41 + seg, 0x0005) + seg); // 103b -> 1228; lin=c415
    memoryASet16(0x0c42 + seg, 0x000a, memoryAGet16(0x0c42 + seg, 0x000a) + seg); // 0cda -> 0ec7; lin=c42a
    memoryASet16(0x0c45 + seg, 0x0004, memoryAGet16(0x0c45 + seg, 0x0004) + seg); // 0cda -> 0ec7; lin=c454
    memoryASet16(0x0c46 + seg, 0x0007, memoryAGet16(0x0c46 + seg, 0x0007) + seg); // 0cda -> 0ec7; lin=c467
    memoryASet16(0x0c47 + seg, 0x0001, memoryAGet16(0x0c47 + seg, 0x0001) + seg); // 103b -> 1228; lin=c471
    memoryASet16(0x0c48 + seg, 0x0000, memoryAGet16(0x0c48 + seg, 0x0000) + seg); // 0cda -> 0ec7; lin=c480
    memoryASet16(0x0c4c + seg, 0x0004, memoryAGet16(0x0c4c + seg, 0x0004) + seg); // 103b -> 1228; lin=c4c4
    memoryASet16(0x0c4e + seg, 0x0001, memoryAGet16(0x0c4e + seg, 0x0001) + seg); // 103b -> 1228; lin=c4e1
    memoryASet16(0x0c51 + seg, 0x0009, memoryAGet16(0x0c51 + seg, 0x0009) + seg); // 103b -> 1228; lin=c519
    memoryASet16(0x0c53 + seg, 0x0000, memoryAGet16(0x0c53 + seg, 0x0000) + seg); // 103b -> 1228; lin=c530
    memoryASet16(0x0c54 + seg, 0x000b, memoryAGet16(0x0c54 + seg, 0x000b) + seg); // 103b -> 1228; lin=c54b
    memoryASet16(0x0c56 + seg, 0x0005, memoryAGet16(0x0c56 + seg, 0x0005) + seg); // 0cda -> 0ec7; lin=c565
    memoryASet16(0x0c58 + seg, 0x0007, memoryAGet16(0x0c58 + seg, 0x0007) + seg); // 103b -> 1228; lin=c587
    memoryASet16(0x0c59 + seg, 0x0008, memoryAGet16(0x0c59 + seg, 0x0008) + seg); // 103b -> 1228; lin=c598
    memoryASet16(0x0c5c + seg, 0x0006, memoryAGet16(0x0c5c + seg, 0x0006) + seg); // 0cda -> 0ec7; lin=c5c6
    memoryASet16(0x0c5e + seg, 0x0008, memoryAGet16(0x0c5e + seg, 0x0008) + seg); // 103b -> 1228; lin=c5e8
    memoryASet16(0x0c5f + seg, 0x0009, memoryAGet16(0x0c5f + seg, 0x0009) + seg); // 103b -> 1228; lin=c5f9
    memoryASet16(0x0c62 + seg, 0x0007, memoryAGet16(0x0c62 + seg, 0x0007) + seg); // 0cda -> 0ec7; lin=c627
    memoryASet16(0x0c64 + seg, 0x0009, memoryAGet16(0x0c64 + seg, 0x0009) + seg); // 103b -> 1228; lin=c649
    memoryASet16(0x0c65 + seg, 0x000a, memoryAGet16(0x0c65 + seg, 0x000a) + seg); // 103b -> 1228; lin=c65a
    memoryASet16(0x0c67 + seg, 0x0003, memoryAGet16(0x0c67 + seg, 0x0003) + seg); // 0cda -> 0ec7; lin=c673
    memoryASet16(0x0c69 + seg, 0x0008, memoryAGet16(0x0c69 + seg, 0x0008) + seg); // 103b -> 1228; lin=c698
    memoryASet16(0x0c6b + seg, 0x0001, memoryAGet16(0x0c6b + seg, 0x0001) + seg); // 0cda -> 0ec7; lin=c6b1
    memoryASet16(0x0c6c + seg, 0x000d, memoryAGet16(0x0c6c + seg, 0x000d) + seg); // 103b -> 1228; lin=c6cd
    memoryASet16(0x0c6e + seg, 0x000a, memoryAGet16(0x0c6e + seg, 0x000a) + seg); // 103b -> 1228; lin=c6ea
    memoryASet16(0x0c6f + seg, 0x000c, memoryAGet16(0x0c6f + seg, 0x000c) + seg); // 0cda -> 0ec7; lin=c6fc
    memoryASet16(0x0c73 + seg, 0x0001, memoryAGet16(0x0c73 + seg, 0x0001) + seg); // 103b -> 1228; lin=c731
    memoryASet16(0x0c74 + seg, 0x0008, memoryAGet16(0x0c74 + seg, 0x0008) + seg); // 0cda -> 0ec7; lin=c748
    memoryASet16(0x0c76 + seg, 0x0009, memoryAGet16(0x0c76 + seg, 0x0009) + seg); // 0cda -> 0ec7; lin=c769
    memoryASet16(0x0c7d + seg, 0x000c, memoryAGet16(0x0c7d + seg, 0x000c) + seg); // 0cda -> 0ec7; lin=c7dc
    memoryASet16(0x0c83 + seg, 0x0003, memoryAGet16(0x0c83 + seg, 0x0003) + seg); // 0cda -> 0ec7; lin=c833
    memoryASet16(0x0c84 + seg, 0x0004, memoryAGet16(0x0c84 + seg, 0x0004) + seg); // 0cda -> 0ec7; lin=c844
    memoryASet16(0x0c84 + seg, 0x000b, memoryAGet16(0x0c84 + seg, 0x000b) + seg); // 103b -> 1228; lin=c84b
    memoryASet16(0x0c86 + seg, 0x0002, memoryAGet16(0x0c86 + seg, 0x0002) + seg); // 0cda -> 0ec7; lin=c862
    memoryASet16(0x0c87 + seg, 0x000a, memoryAGet16(0x0c87 + seg, 0x000a) + seg); // 103b -> 1228; lin=c87a
    memoryASet16(0x0c91 + seg, 0x0006, memoryAGet16(0x0c91 + seg, 0x0006) + seg); // 0cda -> 0ec7; lin=c916
    memoryASet16(0x0c92 + seg, 0x0009, memoryAGet16(0x0c92 + seg, 0x0009) + seg); // 0cda -> 0ec7; lin=c929
    memoryASet16(0x0c93 + seg, 0x0007, memoryAGet16(0x0c93 + seg, 0x0007) + seg); // 0cda -> 0ec7; lin=c937
    memoryASet16(0x0c95 + seg, 0x0008, memoryAGet16(0x0c95 + seg, 0x0008) + seg); // 0cda -> 0ec7; lin=c958
    memoryASet16(0x0c9c + seg, 0x000e, memoryAGet16(0x0c9c + seg, 0x000e) + seg); // 0cda -> 0ec7; lin=c9ce
    memoryASet16(0x0ca2 + seg, 0x000f, memoryAGet16(0x0ca2 + seg, 0x000f) + seg); // 0cda -> 0ec7; lin=ca2f
    memoryASet16(0x0ca4 + seg, 0x0000, memoryAGet16(0x0ca4 + seg, 0x0000) + seg); // 0cda -> 0ec7; lin=ca40
    memoryASet16(0x0ca4 + seg, 0x0007, memoryAGet16(0x0ca4 + seg, 0x0007) + seg); // 103b -> 1228; lin=ca47
    memoryASet16(0x0ca7 + seg, 0x000b, memoryAGet16(0x0ca7 + seg, 0x000b) + seg); // 103b -> 1228; lin=ca7b
    memoryASet16(0x0cb2 + seg, 0x0007, memoryAGet16(0x0cb2 + seg, 0x0007) + seg); // 103b -> 1228; lin=cb27
    memoryASet16(0x0cb6 + seg, 0x000c, memoryAGet16(0x0cb6 + seg, 0x000c) + seg); // 0cda -> 0ec7; lin=cb6c
    memoryASet16(0x0cb9 + seg, 0x000a, memoryAGet16(0x0cb9 + seg, 0x000a) + seg); // 103b -> 1228; lin=cb9a
    memoryASet16(0x0cbd + seg, 0x0008, memoryAGet16(0x0cbd + seg, 0x0008) + seg); // 0cda -> 0ec7; lin=cbd8
    memoryASet16(0x0cbf + seg, 0x000d, memoryAGet16(0x0cbf + seg, 0x000d) + seg); // 103b -> 1228; lin=cbfd
    memoryASet16(0x0cc2 + seg, 0x000a, memoryAGet16(0x0cc2 + seg, 0x000a) + seg); // 103b -> 1228; lin=cc2a
    memoryASet16(0x0cc6 + seg, 0x0009, memoryAGet16(0x0cc6 + seg, 0x0009) + seg); // 0cda -> 0ec7; lin=cc69
    memoryASet16(0x0cc7 + seg, 0x0008, memoryAGet16(0x0cc7 + seg, 0x0008) + seg); // 0cda -> 0ec7; lin=cc78
    memoryASet16(0x0cc8 + seg, 0x0001, memoryAGet16(0x0cc8 + seg, 0x0001) + seg); // 103b -> 1228; lin=cc81
    memoryASet16(0x0cda + seg, 0x0006, memoryAGet16(0x0cda + seg, 0x0006) + seg); // 103b -> 1228; lin=cda6
    memoryASet16(0x0cde + seg, 0x000b, memoryAGet16(0x0cde + seg, 0x000b) + seg); // 103b -> 1228; lin=cdeb
    memoryASet16(0x0ce5 + seg, 0x0006, memoryAGet16(0x0ce5 + seg, 0x0006) + seg); // 103b -> 1228; lin=ce56
    memoryASet16(0x0ce7 + seg, 0x0005, memoryAGet16(0x0ce7 + seg, 0x0005) + seg); // 103b -> 1228; lin=ce75
    memoryASet16(0x0f99 + seg, 0x0008, memoryAGet16(0x0f99 + seg, 0x0008) + seg); // 103b -> 1228; lin=f998
    memoryASet16(0x0fbd + seg, 0x000b, memoryAGet16(0x0fbd + seg, 0x000b) + seg); // 103b -> 1228; lin=fbdb
    memoryASet16(0x0fc0 + seg, 0x0009, memoryAGet16(0x0fc0 + seg, 0x0009) + seg); // 103b -> 1228; lin=fc09
    memoryASet16(0x0fc3 + seg, 0x0003, memoryAGet16(0x0fc3 + seg, 0x0003) + seg); // 103b -> 1228; lin=fc33
    memoryASet16(0x0fc6 + seg, 0x000e, memoryAGet16(0x0fc6 + seg, 0x000e) + seg); // 103b -> 1228; lin=fc6e
    memoryASet16(0x0fc9 + seg, 0x0004, memoryAGet16(0x0fc9 + seg, 0x0004) + seg); // 103b -> 1228; lin=fc94
    memoryASet16(0x0fca + seg, 0x0006, memoryAGet16(0x0fca + seg, 0x0006) + seg); // 103b -> 1228; lin=fca6
    memoryASet16(0x0fcb + seg, 0x0003, memoryAGet16(0x0fcb + seg, 0x0003) + seg); // 103b -> 1228; lin=fcb3
    memoryASet16(0x0fcd + seg, 0x000a, memoryAGet16(0x0fcd + seg, 0x000a) + seg); // 103b -> 1228; lin=fcda
    memoryASet16(0x0fd8 + seg, 0x0002, memoryAGet16(0x0fd8 + seg, 0x0002) + seg); // 103b -> 1228; lin=fd82
    memoryASet16(0x0ff4 + seg, 0x0000, memoryAGet16(0x0ff4 + seg, 0x0000) + seg); // 103b -> 1228; lin=ff40
    memoryASet16(0x0fff + seg, 0x000d, memoryAGet16(0x0fff + seg, 0x000d) + seg); // 103b -> 1228; lin=fffd
    memoryASet16(0x1007 + seg, 0x000d, memoryAGet16(0x1007 + seg, 0x000d) + seg); // 103b -> 1228; lin=1007d
    memoryASet16(0x1009 + seg, 0x000d, memoryAGet16(0x1009 + seg, 0x000d) + seg); // 103b -> 1228; lin=1009d
    memoryASet16(0x100b + seg, 0x0004, memoryAGet16(0x100b + seg, 0x0004) + seg); // 103b -> 1228; lin=100b4
    memoryASet16(0x102c + seg, 0x0006, memoryAGet16(0x102c + seg, 0x0006) + seg); // 103b -> 1228; lin=102c6
    memoryASet16(0x1030 + seg, 0x000d, memoryAGet16(0x1030 + seg, 0x000d) + seg); // 0000 -> 01ed; lin=1030d
    memoryASet16(0x1031 + seg, 0x0006, memoryAGet16(0x1031 + seg, 0x0006) + seg); // 0000 -> 01ed; lin=10316
    memoryASet16(0x1031 + seg, 0x000f, memoryAGet16(0x1031 + seg, 0x000f) + seg); // 0000 -> 01ed; lin=1031f
    memoryASet16(0x1032 + seg, 0x0008, memoryAGet16(0x1032 + seg, 0x0008) + seg); // 0000 -> 01ed; lin=10328
    memoryASet16(0x1035 + seg, 0x0001, memoryAGet16(0x1035 + seg, 0x0001) + seg); // 0000 -> 01ed; lin=10351
    memoryASet16(0x1044 + seg, 0x0002, memoryAGet16(0x1044 + seg, 0x0002) + seg); // 103b -> 1228; lin=10442
    memoryASet16(0x1044 + seg, 0x000c, memoryAGet16(0x1044 + seg, 0x000c) + seg); // 103b -> 1228; lin=1044c
    memoryASet16(0x1045 + seg, 0x0006, memoryAGet16(0x1045 + seg, 0x0006) + seg); // 103b -> 1228; lin=10456
    memoryASet16(0x1046 + seg, 0x0000, memoryAGet16(0x1046 + seg, 0x0000) + seg); // 103b -> 1228; lin=10460
    memoryASet16(0x1046 + seg, 0x000a, memoryAGet16(0x1046 + seg, 0x000a) + seg); // 103b -> 1228; lin=1046a
    memoryASet16(0x1047 + seg, 0x0004, memoryAGet16(0x1047 + seg, 0x0004) + seg); // 103b -> 1228; lin=10474
    memoryASet16(0x1047 + seg, 0x000e, memoryAGet16(0x1047 + seg, 0x000e) + seg); // 103b -> 1228; lin=1047e
    memoryASet16(0x1048 + seg, 0x0008, memoryAGet16(0x1048 + seg, 0x0008) + seg); // 103b -> 1228; lin=10488
    memoryASet16(0x1049 + seg, 0x0002, memoryAGet16(0x1049 + seg, 0x0002) + seg); // 103b -> 1228; lin=10492
    memoryASet16(0x1049 + seg, 0x000c, memoryAGet16(0x1049 + seg, 0x000c) + seg); // 103b -> 1228; lin=1049c
    memoryASet16(0x1092 + seg, 0x0006, memoryAGet16(0x1092 + seg, 0x0006) + seg); // 103b -> 1228; lin=10926
    memoryASet16(0x10a9 + seg, 0x000c, memoryAGet16(0x10a9 + seg, 0x000c) + seg); // 103b -> 1228; lin=10a9c
    memoryASet16(0x10aa + seg, 0x0000, memoryAGet16(0x10aa + seg, 0x0000) + seg); // 103b -> 1228; lin=10aa0
    memoryASet16(0x10aa + seg, 0x0004, memoryAGet16(0x10aa + seg, 0x0004) + seg); // 103b -> 1228; lin=10aa4
    memoryASet16(0x10aa + seg, 0x0008, memoryAGet16(0x10aa + seg, 0x0008) + seg); // 103b -> 1228; lin=10aa8
    memoryASet16(0x10aa + seg, 0x000c, memoryAGet16(0x10aa + seg, 0x000c) + seg); // 103b -> 1228; lin=10aac
    memoryASet16(0x10ab + seg, 0x0000, memoryAGet16(0x10ab + seg, 0x0000) + seg); // 103b -> 1228; lin=10ab0
    memoryASet16(0x10ab + seg, 0x0004, memoryAGet16(0x10ab + seg, 0x0004) + seg); // 103b -> 1228; lin=10ab4
    memoryASet16(0x10ab + seg, 0x0008, memoryAGet16(0x10ab + seg, 0x0008) + seg); // 103b -> 1228; lin=10ab8
    memoryASet16(0x10ab + seg, 0x000c, memoryAGet16(0x10ab + seg, 0x000c) + seg); // 103b -> 1228; lin=10abc
    memoryASet16(0x10b1 + seg, 0x0000, memoryAGet16(0x10b1 + seg, 0x0000) + seg); // 103b -> 1228; lin=10b10
    memoryASet16(0x10b1 + seg, 0x0004, memoryAGet16(0x10b1 + seg, 0x0004) + seg); // 103b -> 1228; lin=10b14
    memoryASet16(0x10b1 + seg, 0x0008, memoryAGet16(0x10b1 + seg, 0x0008) + seg); // 103b -> 1228; lin=10b18
    memoryASet16(0x10c6 + seg, 0x000a, memoryAGet16(0x10c6 + seg, 0x000a) + seg); // 103b -> 1228; lin=10c6a
    memoryASet16(0x10c6 + seg, 0x000e, memoryAGet16(0x10c6 + seg, 0x000e) + seg); // 103b -> 1228; lin=10c6e
    memoryASet16(0x10c7 + seg, 0x0002, memoryAGet16(0x10c7 + seg, 0x0002) + seg); // 103b -> 1228; lin=10c72
    memoryASet16(0x10c7 + seg, 0x0006, memoryAGet16(0x10c7 + seg, 0x0006) + seg); // 103b -> 1228; lin=10c76
    memoryASet16(0x10c7 + seg, 0x000a, memoryAGet16(0x10c7 + seg, 0x000a) + seg); // 103b -> 1228; lin=10c7a
    memoryASet16(0x10c7 + seg, 0x000e, memoryAGet16(0x10c7 + seg, 0x000e) + seg); // 103b -> 1228; lin=10c7e
    memoryASet16(0x10c8 + seg, 0x0002, memoryAGet16(0x10c8 + seg, 0x0002) + seg); // 103b -> 1228; lin=10c82
    memoryASet16(0x10c8 + seg, 0x0006, memoryAGet16(0x10c8 + seg, 0x0006) + seg); // 103b -> 1228; lin=10c86
    memoryASet16(0x10c8 + seg, 0x000a, memoryAGet16(0x10c8 + seg, 0x000a) + seg); // 103b -> 1228; lin=10c8a
    memoryASet16(0x10c8 + seg, 0x000e, memoryAGet16(0x10c8 + seg, 0x000e) + seg); // 103b -> 1228; lin=10c8e
    memoryASet16(0x10c9 + seg, 0x0002, memoryAGet16(0x10c9 + seg, 0x0002) + seg); // 103b -> 1228; lin=10c92
    memoryASet16(0x10c9 + seg, 0x0006, memoryAGet16(0x10c9 + seg, 0x0006) + seg); // 103b -> 1228; lin=10c96
    memoryASet16(0x10c9 + seg, 0x000a, memoryAGet16(0x10c9 + seg, 0x000a) + seg); // 103b -> 1228; lin=10c9a
    memoryASet16(0x10c9 + seg, 0x000e, memoryAGet16(0x10c9 + seg, 0x000e) + seg); // 103b -> 1228; lin=10c9e
    memoryASet16(0x10ca + seg, 0x0002, memoryAGet16(0x10ca + seg, 0x0002) + seg); // 103b -> 1228; lin=10ca2
    memoryASet16(0x10ca + seg, 0x000a, memoryAGet16(0x10ca + seg, 0x000a) + seg); // 103b -> 1228; lin=10caa
    memoryASet16(0x10cb + seg, 0x0002, memoryAGet16(0x10cb + seg, 0x0002) + seg); // 103b -> 1228; lin=10cb2
    memoryASet16(0x10cb + seg, 0x000a, memoryAGet16(0x10cb + seg, 0x000a) + seg); // 103b -> 1228; lin=10cba
    memoryASet16(0x10cc + seg, 0x0002, memoryAGet16(0x10cc + seg, 0x0002) + seg); // 103b -> 1228; lin=10cc2
    memoryASet16(0x10cc + seg, 0x000a, memoryAGet16(0x10cc + seg, 0x000a) + seg); // 103b -> 1228; lin=10cca
    memoryASet16(0x10cd + seg, 0x0002, memoryAGet16(0x10cd + seg, 0x0002) + seg); // 103b -> 1228; lin=10cd2
    memoryASet16(0x10cd + seg, 0x000a, memoryAGet16(0x10cd + seg, 0x000a) + seg); // 103b -> 1228; lin=10cda
    memoryASet16(0x10ce + seg, 0x0004, memoryAGet16(0x10ce + seg, 0x0004) + seg); // 103b -> 1228; lin=10ce4
    memoryASet16(0x10ce + seg, 0x000e, memoryAGet16(0x10ce + seg, 0x000e) + seg); // 103b -> 1228; lin=10cee
    memoryASet16(0x10cf + seg, 0x0008, memoryAGet16(0x10cf + seg, 0x0008) + seg); // 103b -> 1228; lin=10cf8
    memoryASet16(0x10d0 + seg, 0x0002, memoryAGet16(0x10d0 + seg, 0x0002) + seg); // 103b -> 1228; lin=10d02
    memoryASet16(0x10d0 + seg, 0x000c, memoryAGet16(0x10d0 + seg, 0x000c) + seg); // 103b -> 1228; lin=10d0c
    memoryASet16(0x10d1 + seg, 0x0006, memoryAGet16(0x10d1 + seg, 0x0006) + seg); // 103b -> 1228; lin=10d16
    memoryASet16(0x10d2 + seg, 0x0000, memoryAGet16(0x10d2 + seg, 0x0000) + seg); // 103b -> 1228; lin=10d20
    memoryASet16(0x10d2 + seg, 0x000a, memoryAGet16(0x10d2 + seg, 0x000a) + seg); // 103b -> 1228; lin=10d2a
    memoryASet16(0x10d3 + seg, 0x0004, memoryAGet16(0x10d3 + seg, 0x0004) + seg); // 103b -> 1228; lin=10d34
    memoryASet16(0x10d3 + seg, 0x000e, memoryAGet16(0x10d3 + seg, 0x000e) + seg); // 103b -> 1228; lin=10d3e
    memoryASet16(0x10d4 + seg, 0x0008, memoryAGet16(0x10d4 + seg, 0x0008) + seg); // 103b -> 1228; lin=10d48
    memoryASet16(0x10d5 + seg, 0x0002, memoryAGet16(0x10d5 + seg, 0x0002) + seg); // 103b -> 1228; lin=10d52
    memoryASet16(0x10d5 + seg, 0x000c, memoryAGet16(0x10d5 + seg, 0x000c) + seg); // 103b -> 1228; lin=10d5c
    memoryASet16(0x10d6 + seg, 0x0006, memoryAGet16(0x10d6 + seg, 0x0006) + seg); // 103b -> 1228; lin=10d66
    memoryASet16(0x10d7 + seg, 0x0000, memoryAGet16(0x10d7 + seg, 0x0000) + seg); // 103b -> 1228; lin=10d70
    memoryASet16(0x10d7 + seg, 0x000a, memoryAGet16(0x10d7 + seg, 0x000a) + seg); // 103b -> 1228; lin=10d7a
    memoryASet16(0x10d8 + seg, 0x0004, memoryAGet16(0x10d8 + seg, 0x0004) + seg); // 103b -> 1228; lin=10d84
    memoryASet16(0x10d8 + seg, 0x000e, memoryAGet16(0x10d8 + seg, 0x000e) + seg); // 103b -> 1228; lin=10d8e
    memoryASet16(0x1147 + seg, 0x000e, memoryAGet16(0x1147 + seg, 0x000e) + seg); // 103b -> 1228; lin=1147e
    memoryASet16(0x1148 + seg, 0x0002, memoryAGet16(0x1148 + seg, 0x0002) + seg); // 103b -> 1228; lin=11482
    memoryASet16(0x1148 + seg, 0x0006, memoryAGet16(0x1148 + seg, 0x0006) + seg); // 103b -> 1228; lin=11486
    memoryASet16(0x1148 + seg, 0x000a, memoryAGet16(0x1148 + seg, 0x000a) + seg); // 103b -> 1228; lin=1148a
    memoryASet16(0x1148 + seg, 0x000e, memoryAGet16(0x1148 + seg, 0x000e) + seg); // 103b -> 1228; lin=1148e
    memoryASet16(0x1149 + seg, 0x0002, memoryAGet16(0x1149 + seg, 0x0002) + seg); // 103b -> 1228; lin=11492
    memoryASet16(0x1149 + seg, 0x0006, memoryAGet16(0x1149 + seg, 0x0006) + seg); // 103b -> 1228; lin=11496
    memoryASet16(0x1149 + seg, 0x000a, memoryAGet16(0x1149 + seg, 0x000a) + seg); // 103b -> 1228; lin=1149a
    memoryASet16(0x1149 + seg, 0x000e, memoryAGet16(0x1149 + seg, 0x000e) + seg); // 103b -> 1228; lin=1149e
    memoryASet16(0x114a + seg, 0x0002, memoryAGet16(0x114a + seg, 0x0002) + seg); // 103b -> 1228; lin=114a2
    memoryASet16(0x114a + seg, 0x0006, memoryAGet16(0x114a + seg, 0x0006) + seg); // 103b -> 1228; lin=114a6
    memoryASet16(0x114a + seg, 0x000a, memoryAGet16(0x114a + seg, 0x000a) + seg); // 103b -> 1228; lin=114aa
    memoryASet16(0x114a + seg, 0x000e, memoryAGet16(0x114a + seg, 0x000e) + seg); // 103b -> 1228; lin=114ae
    memoryASet16(0x114b + seg, 0x0002, memoryAGet16(0x114b + seg, 0x0002) + seg); // 103b -> 1228; lin=114b2
    memoryASet16(0x114b + seg, 0x0006, memoryAGet16(0x114b + seg, 0x0006) + seg); // 103b -> 1228; lin=114b6
    memoryASet16(0x114b + seg, 0x000a, memoryAGet16(0x114b + seg, 0x000a) + seg); // 103b -> 1228; lin=114ba
    memoryASet16(0x114b + seg, 0x000e, memoryAGet16(0x114b + seg, 0x000e) + seg); // 103b -> 1228; lin=114be
    memoryASet16(0x114c + seg, 0x0002, memoryAGet16(0x114c + seg, 0x0002) + seg); // 103b -> 1228; lin=114c2
    memoryASet16(0x1155 + seg, 0x0000, memoryAGet16(0x1155 + seg, 0x0000) + seg); // 103b -> 1228; lin=11550
    memoryASet16(0x1155 + seg, 0x0004, memoryAGet16(0x1155 + seg, 0x0004) + seg); // 103b -> 1228; lin=11554
    memoryASet16(0x1155 + seg, 0x0008, memoryAGet16(0x1155 + seg, 0x0008) + seg); // 103b -> 1228; lin=11558
    memoryASet16(0x1155 + seg, 0x000c, memoryAGet16(0x1155 + seg, 0x000c) + seg); // 103b -> 1228; lin=1155c
    memoryASet16(0x1156 + seg, 0x0000, memoryAGet16(0x1156 + seg, 0x0000) + seg); // 103b -> 1228; lin=11560
    memoryASet16(0x1170 + seg, 0x000e, memoryAGet16(0x1170 + seg, 0x000e) + seg); // 103b -> 1228; lin=1170e
    memoryASet16(0x1171 + seg, 0x0002, memoryAGet16(0x1171 + seg, 0x0002) + seg); // 103b -> 1228; lin=11712
    memoryASet16(0x1171 + seg, 0x0006, memoryAGet16(0x1171 + seg, 0x0006) + seg); // 103b -> 1228; lin=11716
    memoryASet16(0x1171 + seg, 0x000a, memoryAGet16(0x1171 + seg, 0x000a) + seg); // 103b -> 1228; lin=1171a
    memoryASet16(0x1171 + seg, 0x000e, memoryAGet16(0x1171 + seg, 0x000e) + seg); // 103b -> 1228; lin=1171e
    memoryASet16(0x1172 + seg, 0x0002, memoryAGet16(0x1172 + seg, 0x0002) + seg); // 103b -> 1228; lin=11722
    memoryASet16(0x1172 + seg, 0x0006, memoryAGet16(0x1172 + seg, 0x0006) + seg); // 103b -> 1228; lin=11726
    memoryASet16(0x1172 + seg, 0x000a, memoryAGet16(0x1172 + seg, 0x000a) + seg); // 103b -> 1228; lin=1172a
    memoryASet16(0x1178 + seg, 0x0004, memoryAGet16(0x1178 + seg, 0x0004) + seg); // 103b -> 1228; lin=11784
    memoryASet16(0x117d + seg, 0x0008, memoryAGet16(0x117d + seg, 0x0008) + seg); // 103b -> 1228; lin=117d8
    memoryASet16(0x1182 + seg, 0x000c, memoryAGet16(0x1182 + seg, 0x000c) + seg); // 103b -> 1228; lin=1182c
    memoryASet16(0x1186 + seg, 0x0002, memoryAGet16(0x1186 + seg, 0x0002) + seg); // 103b -> 1228; lin=11862
    memoryASet16(0x1189 + seg, 0x0008, memoryAGet16(0x1189 + seg, 0x0008) + seg); // 103b -> 1228; lin=11898
    memoryASet16(0x1191 + seg, 0x000c, memoryAGet16(0x1191 + seg, 0x000c) + seg); // 103b -> 1228; lin=1191c
    memoryASet16(0x1196 + seg, 0x0004, memoryAGet16(0x1196 + seg, 0x0004) + seg); // 103b -> 1228; lin=11964
    memoryASet16(0x119a + seg, 0x000c, memoryAGet16(0x119a + seg, 0x000c) + seg); // 103b -> 1228; lin=119ac
    memoryASet16(0x119b + seg, 0x0002, memoryAGet16(0x119b + seg, 0x0002) + seg); // 103b -> 1228; lin=119b2
    memoryASet16(0x11a1 + seg, 0x0002, memoryAGet16(0x11a1 + seg, 0x0002) + seg); // 103b -> 1228; lin=11a12
    memoryASet16(0x11a7 + seg, 0x000a, memoryAGet16(0x11a7 + seg, 0x000a) + seg); // 103b -> 1228; lin=11a7a
    memoryASet16(0x11a8 + seg, 0x000c, memoryAGet16(0x11a8 + seg, 0x000c) + seg); // 103b -> 1228; lin=11a8c
    memoryASet16(0x11b0 + seg, 0x000a, memoryAGet16(0x11b0 + seg, 0x000a) + seg); // 103b -> 1228; lin=11b0a
    memoryASet16(0x11b4 + seg, 0x0006, memoryAGet16(0x11b4 + seg, 0x0006) + seg); // 103b -> 1228; lin=11b46
    memoryASet16(0x11bb + seg, 0x0002, memoryAGet16(0x11bb + seg, 0x0002) + seg); // 103b -> 1228; lin=11bb2
    memoryASet16(0x11c0 + seg, 0x0000, memoryAGet16(0x11c0 + seg, 0x0000) + seg); // 103b -> 1228; lin=11c00
    memoryASet16(0x11c4 + seg, 0x0008, memoryAGet16(0x11c4 + seg, 0x0008) + seg); // 103b -> 1228; lin=11c48
    memoryASet16(0x11c9 + seg, 0x0000, memoryAGet16(0x11c9 + seg, 0x0000) + seg); // 103b -> 1228; lin=11c90
    memoryASet16(0x11cd + seg, 0x000e, memoryAGet16(0x11cd + seg, 0x000e) + seg); // 103b -> 1228; lin=11cde
    memoryASet16(0x11d2 + seg, 0x000c, memoryAGet16(0x11d2 + seg, 0x000c) + seg); // 103b -> 1228; lin=11d2c
    memoryASet16(0x11d9 + seg, 0x0002, memoryAGet16(0x11d9 + seg, 0x0002) + seg); // 103b -> 1228; lin=11d92
    memoryASet16(0x11df + seg, 0x0008, memoryAGet16(0x11df + seg, 0x0008) + seg); // 103b -> 1228; lin=11df8
    memoryASet16(0x11e5 + seg, 0x000e, memoryAGet16(0x11e5 + seg, 0x000e) + seg); // 103b -> 1228; lin=11e5e
    memoryASet16(0x11ec + seg, 0x0004, memoryAGet16(0x11ec + seg, 0x0004) + seg); // 103b -> 1228; lin=11ec4
    memoryASet16(0x11f1 + seg, 0x0008, memoryAGet16(0x11f1 + seg, 0x0008) + seg); // 103b -> 1228; lin=11f18
    memoryASet16(0x11f1 + seg, 0x000e, memoryAGet16(0x11f1 + seg, 0x000e) + seg); // 103b -> 1228; lin=11f1e
    memoryASet16(0x11f8 + seg, 0x0000, memoryAGet16(0x11f8 + seg, 0x0000) + seg); // 103b -> 1228; lin=11f80
    memoryASet16(0x11fb + seg, 0x0006, memoryAGet16(0x11fb + seg, 0x0006) + seg); // 103b -> 1228; lin=11fb6
    memoryASet16(0x11ff + seg, 0x0008, memoryAGet16(0x11ff + seg, 0x0008) + seg); // 103b -> 1228; lin=11ff8
    memoryASet16(0x11ff + seg, 0x000e, memoryAGet16(0x11ff + seg, 0x000e) + seg); // 103b -> 1228; lin=11ffe
    memoryASet16(0x1204 + seg, 0x000c, memoryAGet16(0x1204 + seg, 0x000c) + seg); // 103b -> 1228; lin=1204c
    memoryASet16(0x1205 + seg, 0x0002, memoryAGet16(0x1205 + seg, 0x0002) + seg); // 103b -> 1228; lin=12052
    memoryASet16(0x120a + seg, 0x0002, memoryAGet16(0x120a + seg, 0x0002) + seg); // 103b -> 1228; lin=120a2
    memoryASet16(0x120a + seg, 0x0008, memoryAGet16(0x120a + seg, 0x0008) + seg); // 103b -> 1228; lin=120a8
    memoryASet16(0x120e + seg, 0x000a, memoryAGet16(0x120e + seg, 0x000a) + seg); // 103b -> 1228; lin=120ea
    memoryASet16(0x120f + seg, 0x0000, memoryAGet16(0x120f + seg, 0x0000) + seg); // 103b -> 1228; lin=120f0
    memoryASet16(0x1214 + seg, 0x0004, memoryAGet16(0x1214 + seg, 0x0004) + seg); // 103b -> 1228; lin=12144
    memoryASet16(0x1214 + seg, 0x000a, memoryAGet16(0x1214 + seg, 0x000a) + seg); // 103b -> 1228; lin=1214a
    memoryASet16(0x1218 + seg, 0x000c, memoryAGet16(0x1218 + seg, 0x000c) + seg); // 103b -> 1228; lin=1218c
    memoryASet16(0x1220 + seg, 0x0004, memoryAGet16(0x1220 + seg, 0x0004) + seg); // 103b -> 1228; lin=12204
    memoryASet16(0x122a + seg, 0x0006, memoryAGet16(0x122a + seg, 0x0006) + seg); // 103b -> 1228; lin=122a6
    memoryASet16(0x122d + seg, 0x0000, memoryAGet16(0x122d + seg, 0x0000) + seg); // 103b -> 1228; lin=122d0
    memoryASet16(0x1231 + seg, 0x0002, memoryAGet16(0x1231 + seg, 0x0002) + seg); // 103b -> 1228; lin=12312
    memoryASet16(0x1231 + seg, 0x0008, memoryAGet16(0x1231 + seg, 0x0008) + seg); // 103b -> 1228; lin=12318
    memoryASet16(0x1237 + seg, 0x0008, memoryAGet16(0x1237 + seg, 0x0008) + seg); // 103b -> 1228; lin=12378
    memoryASet16(0x1237 + seg, 0x000e, memoryAGet16(0x1237 + seg, 0x000e) + seg); // 103b -> 1228; lin=1237e
    memoryASet16(0x123e + seg, 0x000a, memoryAGet16(0x123e + seg, 0x000a) + seg); // 103b -> 1228; lin=123ea
    memoryASet16(0x123f + seg, 0x0000, memoryAGet16(0x123f + seg, 0x0000) + seg); // 103b -> 1228; lin=123f0
    memoryASet16(0x1243 + seg, 0x0008, memoryAGet16(0x1243 + seg, 0x0008) + seg); // 103b -> 1228; lin=12438
    memoryASet16(0x1243 + seg, 0x000e, memoryAGet16(0x1243 + seg, 0x000e) + seg); // 103b -> 1228; lin=1243e
    memoryASet16(0x1249 + seg, 0x0002, memoryAGet16(0x1249 + seg, 0x0002) + seg); // 103b -> 1228; lin=12492
    memoryASet16(0x1249 + seg, 0x0008, memoryAGet16(0x1249 + seg, 0x0008) + seg); // 103b -> 1228; lin=12498
    memoryASet16(0x124f + seg, 0x0002, memoryAGet16(0x124f + seg, 0x0002) + seg); // 103b -> 1228; lin=124f2
    memoryASet16(0x1254 + seg, 0x000c, memoryAGet16(0x1254 + seg, 0x000c) + seg); // 103b -> 1228; lin=1254c
    memoryASet16(0x125a + seg, 0x0006, memoryAGet16(0x125a + seg, 0x0006) + seg); // 103b -> 1228; lin=125a6
    memoryASet16(0x1260 + seg, 0x0000, memoryAGet16(0x1260 + seg, 0x0000) + seg); // 103b -> 1228; lin=12600
    memoryASet16(0x1260 + seg, 0x0004, memoryAGet16(0x1260 + seg, 0x0004) + seg); // 103b -> 1228; lin=12604
    memoryASet16(0x1260 + seg, 0x0008, memoryAGet16(0x1260 + seg, 0x0008) + seg); // 103b -> 1228; lin=12608
    memoryASet16(0x1260 + seg, 0x000c, memoryAGet16(0x1260 + seg, 0x000c) + seg); // 103b -> 1228; lin=1260c
    memoryASet16(0x1261 + seg, 0x0000, memoryAGet16(0x1261 + seg, 0x0000) + seg); // 103b -> 1228; lin=12610
    memoryASet16(0x1261 + seg, 0x0004, memoryAGet16(0x1261 + seg, 0x0004) + seg); // 103b -> 1228; lin=12614
    memoryASet16(0x1261 + seg, 0x000c, memoryAGet16(0x1261 + seg, 0x000c) + seg); // 103b -> 1228; lin=1261c
    memoryASet16(0x1262 + seg, 0x0000, memoryAGet16(0x1262 + seg, 0x0000) + seg); // 103b -> 1228; lin=12620
    memoryASet16(0x1262 + seg, 0x0004, memoryAGet16(0x1262 + seg, 0x0004) + seg); // 103b -> 1228; lin=12624
    memoryASet16(0x1262 + seg, 0x0008, memoryAGet16(0x1262 + seg, 0x0008) + seg); // 103b -> 1228; lin=12628
    memoryASet16(0x1262 + seg, 0x000c, memoryAGet16(0x1262 + seg, 0x000c) + seg); // 103b -> 1228; lin=1262c
    memoryASet16(0x1263 + seg, 0x0004, memoryAGet16(0x1263 + seg, 0x0004) + seg); // 103b -> 1228; lin=12634
    memoryASet16(0x1263 + seg, 0x0008, memoryAGet16(0x1263 + seg, 0x0008) + seg); // 103b -> 1228; lin=12638
    memoryASet16(0x1263 + seg, 0x000c, memoryAGet16(0x1263 + seg, 0x000c) + seg); // 103b -> 1228; lin=1263c
    memoryASet16(0x1264 + seg, 0x0000, memoryAGet16(0x1264 + seg, 0x0000) + seg); // 103b -> 1228; lin=12640
    memoryASet16(0x1264 + seg, 0x0004, memoryAGet16(0x1264 + seg, 0x0004) + seg); // 103b -> 1228; lin=12644
    memoryASet16(0x1264 + seg, 0x0008, memoryAGet16(0x1264 + seg, 0x0008) + seg); // 103b -> 1228; lin=12648
    memoryASet16(0x1264 + seg, 0x000c, memoryAGet16(0x1264 + seg, 0x000c) + seg); // 103b -> 1228; lin=1264c
    memoryASet16(0x1265 + seg, 0x0000, memoryAGet16(0x1265 + seg, 0x0000) + seg); // 103b -> 1228; lin=12650
    memoryASet16(0x1265 + seg, 0x0004, memoryAGet16(0x1265 + seg, 0x0004) + seg); // 103b -> 1228; lin=12654
    memoryASet16(0x1265 + seg, 0x0008, memoryAGet16(0x1265 + seg, 0x0008) + seg); // 103b -> 1228; lin=12658
    memoryASet16(0x1265 + seg, 0x000c, memoryAGet16(0x1265 + seg, 0x000c) + seg); // 103b -> 1228; lin=1265c
    memoryASet16(0x1266 + seg, 0x0000, memoryAGet16(0x1266 + seg, 0x0000) + seg); // 103b -> 1228; lin=12660
    memoryASet16(0x1266 + seg, 0x0004, memoryAGet16(0x1266 + seg, 0x0004) + seg); // 103b -> 1228; lin=12664
    memoryASet16(0x1266 + seg, 0x0008, memoryAGet16(0x1266 + seg, 0x0008) + seg); // 103b -> 1228; lin=12668
    memoryASet16(0x1266 + seg, 0x000c, memoryAGet16(0x1266 + seg, 0x000c) + seg); // 103b -> 1228; lin=1266c
    memoryASet16(0x1267 + seg, 0x0000, memoryAGet16(0x1267 + seg, 0x0000) + seg); // 103b -> 1228; lin=12670
    memoryASet16(0x1267 + seg, 0x0008, memoryAGet16(0x1267 + seg, 0x0008) + seg); // 103b -> 1228; lin=12678
    memoryASet16(0x1267 + seg, 0x000c, memoryAGet16(0x1267 + seg, 0x000c) + seg); // 103b -> 1228; lin=1267c
    memoryASet16(0x1268 + seg, 0x0000, memoryAGet16(0x1268 + seg, 0x0000) + seg); // 103b -> 1228; lin=12680
    memoryASet16(0x1268 + seg, 0x0004, memoryAGet16(0x1268 + seg, 0x0004) + seg); // 103b -> 1228; lin=12684
    memoryASet16(0x1268 + seg, 0x0008, memoryAGet16(0x1268 + seg, 0x0008) + seg); // 103b -> 1228; lin=12688
    memoryASet16(0x1268 + seg, 0x000c, memoryAGet16(0x1268 + seg, 0x000c) + seg); // 103b -> 1228; lin=1268c
    memoryASet16(0x1269 + seg, 0x0008, memoryAGet16(0x1269 + seg, 0x0008) + seg); // 103b -> 1228; lin=12698
    memoryASet16(0x1269 + seg, 0x000c, memoryAGet16(0x1269 + seg, 0x000c) + seg); // 103b -> 1228; lin=1269c
    memoryASet16(0x126a + seg, 0x0000, memoryAGet16(0x126a + seg, 0x0000) + seg); // 103b -> 1228; lin=126a0
    memoryASet16(0x126a + seg, 0x0004, memoryAGet16(0x126a + seg, 0x0004) + seg); // 103b -> 1228; lin=126a4
    memoryASet16(0x126a + seg, 0x0008, memoryAGet16(0x126a + seg, 0x0008) + seg); // 103b -> 1228; lin=126a8
    memoryASet16(0x126a + seg, 0x000c, memoryAGet16(0x126a + seg, 0x000c) + seg); // 103b -> 1228; lin=126ac
    memoryASet16(0x126b + seg, 0x0000, memoryAGet16(0x126b + seg, 0x0000) + seg); // 103b -> 1228; lin=126b0
    memoryASet16(0x126b + seg, 0x0004, memoryAGet16(0x126b + seg, 0x0004) + seg); // 103b -> 1228; lin=126b4
    memoryASet16(0x126b + seg, 0x0008, memoryAGet16(0x126b + seg, 0x0008) + seg); // 103b -> 1228; lin=126b8
    memoryASet16(0x126b + seg, 0x000c, memoryAGet16(0x126b + seg, 0x000c) + seg); // 103b -> 1228; lin=126bc
    memoryASet16(0x126c + seg, 0x0000, memoryAGet16(0x126c + seg, 0x0000) + seg); // 103b -> 1228; lin=126c0
    memoryASet16(0x126c + seg, 0x0004, memoryAGet16(0x126c + seg, 0x0004) + seg); // 103b -> 1228; lin=126c4
    memoryASet16(0x126c + seg, 0x0008, memoryAGet16(0x126c + seg, 0x0008) + seg); // 103b -> 1228; lin=126c8
    memoryASet16(0x126c + seg, 0x000c, memoryAGet16(0x126c + seg, 0x000c) + seg); // 103b -> 1228; lin=126cc
    memoryASet16(0x126d + seg, 0x0000, memoryAGet16(0x126d + seg, 0x0000) + seg); // 103b -> 1228; lin=126d0
    memoryASet16(0x126d + seg, 0x0004, memoryAGet16(0x126d + seg, 0x0004) + seg); // 103b -> 1228; lin=126d4
    memoryASet16(0x126d + seg, 0x0008, memoryAGet16(0x126d + seg, 0x0008) + seg); // 103b -> 1228; lin=126d8
    memoryASet16(0x126d + seg, 0x000c, memoryAGet16(0x126d + seg, 0x000c) + seg); // 103b -> 1228; lin=126dc
    memoryASet16(0x126e + seg, 0x0000, memoryAGet16(0x126e + seg, 0x0000) + seg); // 103b -> 1228; lin=126e0
    memoryASet16(0x126e + seg, 0x0004, memoryAGet16(0x126e + seg, 0x0004) + seg); // 103b -> 1228; lin=126e4
    memoryASet16(0x126e + seg, 0x0008, memoryAGet16(0x126e + seg, 0x0008) + seg); // 103b -> 1228; lin=126e8
    memoryASet16(0x126e + seg, 0x000c, memoryAGet16(0x126e + seg, 0x000c) + seg); // 103b -> 1228; lin=126ec
    memoryASet16(0x126f + seg, 0x0000, memoryAGet16(0x126f + seg, 0x0000) + seg); // 103b -> 1228; lin=126f0
    memoryASet16(0x126f + seg, 0x0004, memoryAGet16(0x126f + seg, 0x0004) + seg); // 103b -> 1228; lin=126f4
    memoryASet16(0x126f + seg, 0x0008, memoryAGet16(0x126f + seg, 0x0008) + seg); // 103b -> 1228; lin=126f8
    memoryASet16(0x126f + seg, 0x000c, memoryAGet16(0x126f + seg, 0x000c) + seg); // 103b -> 1228; lin=126fc
    memoryASet16(0x1270 + seg, 0x0000, memoryAGet16(0x1270 + seg, 0x0000) + seg); // 103b -> 1228; lin=12700
    memoryASet16(0x1273 + seg, 0x0006, memoryAGet16(0x1273 + seg, 0x0006) + seg); // 103b -> 1228; lin=12736
    memoryASet16(0x1276 + seg, 0x000c, memoryAGet16(0x1276 + seg, 0x000c) + seg); // 103b -> 1228; lin=1276c
    memoryASet16(0x127a + seg, 0x000e, memoryAGet16(0x127a + seg, 0x000e) + seg); // 103b -> 1228; lin=127ae
    memoryASet16(0x127b + seg, 0x0004, memoryAGet16(0x127b + seg, 0x0004) + seg); // 103b -> 1228; lin=127b4
    memoryASet16(0x127f + seg, 0x0000, memoryAGet16(0x127f + seg, 0x0000) + seg); // 103b -> 1228; lin=127f0
    memoryASet16(0x1282 + seg, 0x000c, memoryAGet16(0x1282 + seg, 0x000c) + seg); // 103b -> 1228; lin=1282c
    memoryASet16(0x1286 + seg, 0x000e, memoryAGet16(0x1286 + seg, 0x000e) + seg); // 103b -> 1228; lin=1286e
    memoryASet16(0x1287 + seg, 0x0004, memoryAGet16(0x1287 + seg, 0x0004) + seg); // 103b -> 1228; lin=12874
    memoryASet16(0x128c + seg, 0x000e, memoryAGet16(0x128c + seg, 0x000e) + seg); // 103b -> 1228; lin=128ce
    memoryASet16(0x128d + seg, 0x0006, memoryAGet16(0x128d + seg, 0x0006) + seg); // 103b -> 1228; lin=128d6
    memoryASet16(0x128d + seg, 0x000a, memoryAGet16(0x128d + seg, 0x000a) + seg); // 103b -> 1228; lin=128da
    memoryASet16(0x128d + seg, 0x000e, memoryAGet16(0x128d + seg, 0x000e) + seg); // 103b -> 1228; lin=128de
    memoryASet16(0x128e + seg, 0x0002, memoryAGet16(0x128e + seg, 0x0002) + seg); // 103b -> 1228; lin=128e2
    memoryASet16(0x128e + seg, 0x0006, memoryAGet16(0x128e + seg, 0x0006) + seg); // 103b -> 1228; lin=128e6
    memoryASet16(0x128e + seg, 0x000a, memoryAGet16(0x128e + seg, 0x000a) + seg); // 103b -> 1228; lin=128ea
    memoryASet16(0x128e + seg, 0x000e, memoryAGet16(0x128e + seg, 0x000e) + seg); // 103b -> 1228; lin=128ee
    memoryASet16(0x128f + seg, 0x0002, memoryAGet16(0x128f + seg, 0x0002) + seg); // 103b -> 1228; lin=128f2
    memoryASet16(0x128f + seg, 0x0006, memoryAGet16(0x128f + seg, 0x0006) + seg); // 103b -> 1228; lin=128f6
    memoryASet16(0x1291 + seg, 0x000c, memoryAGet16(0x1291 + seg, 0x000c) + seg); // 103b -> 1228; lin=1291c
    memoryASet16(0x12bc + seg, 0x000e, memoryAGet16(0x12bc + seg, 0x000e) + seg); // 103b -> 1228; lin=12bce
    memoryASet16(0x12bd + seg, 0x000c, memoryAGet16(0x12bd + seg, 0x000c) + seg); // 103b -> 1228; lin=12bdc
    memoryASet16(0x12bf + seg, 0x0000, memoryAGet16(0x12bf + seg, 0x0000) + seg); // 103b -> 1228; lin=12bf0
    memoryASet16(0x12bf + seg, 0x000c, memoryAGet16(0x12bf + seg, 0x000c) + seg); // 103b -> 1228; lin=12bfc
    memoryASet16(0x12c0 + seg, 0x000a, memoryAGet16(0x12c0 + seg, 0x000a) + seg); // 103b -> 1228; lin=12c0a
    memoryASet16(0x12c1 + seg, 0x0008, memoryAGet16(0x12c1 + seg, 0x0008) + seg); // 103b -> 1228; lin=12c18
    memoryASet16(0x12c2 + seg, 0x000c, memoryAGet16(0x12c2 + seg, 0x000c) + seg); // 103b -> 1228; lin=12c2c
    memoryASet16(0x12c4 + seg, 0x0002, memoryAGet16(0x12c4 + seg, 0x0002) + seg); // 103b -> 1228; lin=12c42
    memoryASet16(0x12c5 + seg, 0x0008, memoryAGet16(0x12c5 + seg, 0x0008) + seg); // 103b -> 1228; lin=12c58
    memoryASet16(0x12c7 + seg, 0x0000, memoryAGet16(0x12c7 + seg, 0x0000) + seg); // 103b -> 1228; lin=12c70
    memoryASet16(0x12c8 + seg, 0x0006, memoryAGet16(0x12c8 + seg, 0x0006) + seg); // 103b -> 1228; lin=12c86
    memoryASet16(0x12c9 + seg, 0x000c, memoryAGet16(0x12c9 + seg, 0x000c) + seg); // 103b -> 1228; lin=12c9c
    memoryASet16(0x12cb + seg, 0x0004, memoryAGet16(0x12cb + seg, 0x0004) + seg); // 103b -> 1228; lin=12cb4
    memoryASet16(0x12cc + seg, 0x000e, memoryAGet16(0x12cc + seg, 0x000e) + seg); // 103b -> 1228; lin=12cce
    memoryASet16(0x12ce + seg, 0x0008, memoryAGet16(0x12ce + seg, 0x0008) + seg); // 103b -> 1228; lin=12ce8
    memoryASet16(0x12d0 + seg, 0x0006, memoryAGet16(0x12d0 + seg, 0x0006) + seg); // 103b -> 1228; lin=12d06
    memoryASet16(0x12d1 + seg, 0x0006, memoryAGet16(0x12d1 + seg, 0x0006) + seg); // 103b -> 1228; lin=12d16
    memoryASet16(0x12d2 + seg, 0x0006, memoryAGet16(0x12d2 + seg, 0x0006) + seg); // 103b -> 1228; lin=12d26
    memoryASet16(0x12d3 + seg, 0x000c, memoryAGet16(0x12d3 + seg, 0x000c) + seg); // 103b -> 1228; lin=12d3c
    memoryASet16(0x12d4 + seg, 0x0008, memoryAGet16(0x12d4 + seg, 0x0008) + seg); // 103b -> 1228; lin=12d48
    memoryASet16(0x12d5 + seg, 0x0004, memoryAGet16(0x12d5 + seg, 0x0004) + seg); // 103b -> 1228; lin=12d54
    memoryASet16(0x12d6 + seg, 0x0002, memoryAGet16(0x12d6 + seg, 0x0002) + seg); // 103b -> 1228; lin=12d62
    memoryASet16(0x12d7 + seg, 0x0000, memoryAGet16(0x12d7 + seg, 0x0000) + seg); // 103b -> 1228; lin=12d70
    memoryASet16(0x12d8 + seg, 0x0004, memoryAGet16(0x12d8 + seg, 0x0004) + seg); // 103b -> 1228; lin=12d84
    memoryASet16(0x12d9 + seg, 0x0008, memoryAGet16(0x12d9 + seg, 0x0008) + seg); // 103b -> 1228; lin=12d98
    memoryASet16(0x12da + seg, 0x000a, memoryAGet16(0x12da + seg, 0x000a) + seg); // 103b -> 1228; lin=12daa
    memoryASet16(0x12db + seg, 0x000c, memoryAGet16(0x12db + seg, 0x000c) + seg); // 103b -> 1228; lin=12dbc
    memoryASet16(0x12dc + seg, 0x0006, memoryAGet16(0x12dc + seg, 0x0006) + seg); // 103b -> 1228; lin=12dc6
    memoryASet16(0x12dd + seg, 0x0000, memoryAGet16(0x12dd + seg, 0x0000) + seg); // 103b -> 1228; lin=12dd0
    memoryASet16(0x12de + seg, 0x0004, memoryAGet16(0x12de + seg, 0x0004) + seg); // 103b -> 1228; lin=12de4
    memoryASet16(0x12df + seg, 0x0006, memoryAGet16(0x12df + seg, 0x0006) + seg); // 103b -> 1228; lin=12df6
    memoryASet16(0x12e0 + seg, 0x0006, memoryAGet16(0x12e0 + seg, 0x0006) + seg); // 103b -> 1228; lin=12e06
    memoryASet16(0x12e1 + seg, 0x000a, memoryAGet16(0x12e1 + seg, 0x000a) + seg); // 103b -> 1228; lin=12e1a
    memoryASet16(0x12e2 + seg, 0x000e, memoryAGet16(0x12e2 + seg, 0x000e) + seg); // 103b -> 1228; lin=12e2e
    memoryASet16(0x12e4 + seg, 0x0006, memoryAGet16(0x12e4 + seg, 0x0006) + seg); // 103b -> 1228; lin=12e46
    memoryASet16(0x12e5 + seg, 0x0006, memoryAGet16(0x12e5 + seg, 0x0006) + seg); // 103b -> 1228; lin=12e56
    memoryASet16(0x12e6 + seg, 0x0004, memoryAGet16(0x12e6 + seg, 0x0004) + seg); // 103b -> 1228; lin=12e64
    memoryASet16(0x12e8 + seg, 0x0000, memoryAGet16(0x12e8 + seg, 0x0000) + seg); // 103b -> 1228; lin=12e80
    memoryASet16(0x12e9 + seg, 0x0002, memoryAGet16(0x12e9 + seg, 0x0002) + seg); // 103b -> 1228; lin=12e92
    memoryASet16(0x12ea + seg, 0x0004, memoryAGet16(0x12ea + seg, 0x0004) + seg); // 103b -> 1228; lin=12ea4
    memoryASet16(0x12eb + seg, 0x0006, memoryAGet16(0x12eb + seg, 0x0006) + seg); // 103b -> 1228; lin=12eb6
    memoryASet16(0x12ec + seg, 0x0006, memoryAGet16(0x12ec + seg, 0x0006) + seg); // 103b -> 1228; lin=12ec6
    memoryASet16(0x12ed + seg, 0x0006, memoryAGet16(0x12ed + seg, 0x0006) + seg); // 103b -> 1228; lin=12ed6
    memoryASet16(0x12ee + seg, 0x000e, memoryAGet16(0x12ee + seg, 0x000e) + seg); // 103b -> 1228; lin=12eee
    memoryASet16(0x12f0 + seg, 0x0002, memoryAGet16(0x12f0 + seg, 0x0002) + seg); // 103b -> 1228; lin=12f02
    memoryASet16(0x12f1 + seg, 0x0000, memoryAGet16(0x12f1 + seg, 0x0000) + seg); // 103b -> 1228; lin=12f10
    memoryASet16(0x12f1 + seg, 0x000e, memoryAGet16(0x12f1 + seg, 0x000e) + seg); // 103b -> 1228; lin=12f1e
    memoryASet16(0x12f3 + seg, 0x0002, memoryAGet16(0x12f3 + seg, 0x0002) + seg); // 103b -> 1228; lin=12f32
    memoryASet16(0x12f3 + seg, 0x000e, memoryAGet16(0x12f3 + seg, 0x000e) + seg); // 103b -> 1228; lin=12f3e
    memoryASet16(0x12f5 + seg, 0x0002, memoryAGet16(0x12f5 + seg, 0x0002) + seg); // 103b -> 1228; lin=12f52
    memoryASet16(0x12f6 + seg, 0x0000, memoryAGet16(0x12f6 + seg, 0x0000) + seg); // 103b -> 1228; lin=12f60
    memoryASet16(0x12f6 + seg, 0x000e, memoryAGet16(0x12f6 + seg, 0x000e) + seg); // 103b -> 1228; lin=12f6e
    memoryASet16(0x12f8 + seg, 0x0002, memoryAGet16(0x12f8 + seg, 0x0002) + seg); // 103b -> 1228; lin=12f82
    memoryASet16(0x12f8 + seg, 0x000e, memoryAGet16(0x12f8 + seg, 0x000e) + seg); // 103b -> 1228; lin=12f8e
    memoryASet16(0x12f9 + seg, 0x000e, memoryAGet16(0x12f9 + seg, 0x000e) + seg); // 103b -> 1228; lin=12f9e
    memoryASet16(0x12fa + seg, 0x000e, memoryAGet16(0x12fa + seg, 0x000e) + seg); // 103b -> 1228; lin=12fae
    memoryASet16(0x12fc + seg, 0x0006, memoryAGet16(0x12fc + seg, 0x0006) + seg); // 103b -> 1228; lin=12fc6
    memoryASet16(0x12fd + seg, 0x0008, memoryAGet16(0x12fd + seg, 0x0008) + seg); // 103b -> 1228; lin=12fd8
    memoryASet16(0x12fe + seg, 0x000e, memoryAGet16(0x12fe + seg, 0x000e) + seg); // 103b -> 1228; lin=12fee
    memoryASet16(0x1300 + seg, 0x0008, memoryAGet16(0x1300 + seg, 0x0008) + seg); // 103b -> 1228; lin=13008
    memoryASet16(0x1302 + seg, 0x0002, memoryAGet16(0x1302 + seg, 0x0002) + seg); // 103b -> 1228; lin=13022
    memoryASet16(0x1302 + seg, 0x000c, memoryAGet16(0x1302 + seg, 0x000c) + seg); // 103b -> 1228; lin=1302c
    memoryASet16(0x1303 + seg, 0x0006, memoryAGet16(0x1303 + seg, 0x0006) + seg); // 103b -> 1228; lin=13036
    memoryASet16(0x1304 + seg, 0x0008, memoryAGet16(0x1304 + seg, 0x0008) + seg); // 103b -> 1228; lin=13048
    memoryASet16(0x1305 + seg, 0x000a, memoryAGet16(0x1305 + seg, 0x000a) + seg); // 103b -> 1228; lin=1305a
    memoryASet16(0x1306 + seg, 0x000c, memoryAGet16(0x1306 + seg, 0x000c) + seg); // 103b -> 1228; lin=1306c
    memoryASet16(0x1307 + seg, 0x000e, memoryAGet16(0x1307 + seg, 0x000e) + seg); // 103b -> 1228; lin=1307e
    memoryASet16(0x1309 + seg, 0x0000, memoryAGet16(0x1309 + seg, 0x0000) + seg); // 103b -> 1228; lin=13090
    memoryASet16(0x130a + seg, 0x0002, memoryAGet16(0x130a + seg, 0x0002) + seg); // 103b -> 1228; lin=130a2
    memoryASet16(0x130b + seg, 0x0004, memoryAGet16(0x130b + seg, 0x0004) + seg); // 103b -> 1228; lin=130b4
    memoryASet16(0x130c + seg, 0x0006, memoryAGet16(0x130c + seg, 0x0006) + seg); // 103b -> 1228; lin=130c6
    memoryASet16(0x130d + seg, 0x0008, memoryAGet16(0x130d + seg, 0x0008) + seg); // 103b -> 1228; lin=130d8
    memoryASet16(0x130e + seg, 0x000a, memoryAGet16(0x130e + seg, 0x000a) + seg); // 103b -> 1228; lin=130ea
    memoryASet16(0x1310 + seg, 0x0000, memoryAGet16(0x1310 + seg, 0x0000) + seg); // 103b -> 1228; lin=13100
    memoryASet16(0x1311 + seg, 0x000a, memoryAGet16(0x1311 + seg, 0x000a) + seg); // 103b -> 1228; lin=1311a
    memoryASet16(0x1313 + seg, 0x0002, memoryAGet16(0x1313 + seg, 0x0002) + seg); // 103b -> 1228; lin=13132
    memoryASet16(0x1314 + seg, 0x0004, memoryAGet16(0x1314 + seg, 0x0004) + seg); // 103b -> 1228; lin=13144
    memoryASet16(0x1315 + seg, 0x0008, memoryAGet16(0x1315 + seg, 0x0008) + seg); // 103b -> 1228; lin=13158
    memoryASet16(0x1316 + seg, 0x000c, memoryAGet16(0x1316 + seg, 0x000c) + seg); // 103b -> 1228; lin=1316c
    memoryASet16(0x1317 + seg, 0x000e, memoryAGet16(0x1317 + seg, 0x000e) + seg); // 103b -> 1228; lin=1317e
    memoryASet16(0x1319 + seg, 0x0000, memoryAGet16(0x1319 + seg, 0x0000) + seg); // 103b -> 1228; lin=13190
    memoryASet16(0x131a + seg, 0x0002, memoryAGet16(0x131a + seg, 0x0002) + seg); // 103b -> 1228; lin=131a2
    memoryASet16(0x131b + seg, 0x0008, memoryAGet16(0x131b + seg, 0x0008) + seg); // 103b -> 1228; lin=131b8
    memoryASet16(0x131c + seg, 0x000a, memoryAGet16(0x131c + seg, 0x000a) + seg); // 103b -> 1228; lin=131ca
    memoryASet16(0x131d + seg, 0x000c, memoryAGet16(0x131d + seg, 0x000c) + seg); // 103b -> 1228; lin=131dc
    memoryASet16(0x131e + seg, 0x000e, memoryAGet16(0x131e + seg, 0x000e) + seg); // 103b -> 1228; lin=131ee
    memoryASet16(0x1320 + seg, 0x0004, memoryAGet16(0x1320 + seg, 0x0004) + seg); // 103b -> 1228; lin=13204
    memoryASet16(0x1321 + seg, 0x000a, memoryAGet16(0x1321 + seg, 0x000a) + seg); // 103b -> 1228; lin=1321a
    memoryASet16(0x1323 + seg, 0x0008, memoryAGet16(0x1323 + seg, 0x0008) + seg); // 103b -> 1228; lin=13238
    memoryASet16(0x1324 + seg, 0x0004, memoryAGet16(0x1324 + seg, 0x0004) + seg); // 103b -> 1228; lin=13244
    memoryASet16(0x1324 + seg, 0x000e, memoryAGet16(0x1324 + seg, 0x000e) + seg); // 103b -> 1228; lin=1324e
    memoryASet16(0x1325 + seg, 0x000c, memoryAGet16(0x1325 + seg, 0x000c) + seg); // 103b -> 1228; lin=1325c
    memoryASet16(0x1326 + seg, 0x000a, memoryAGet16(0x1326 + seg, 0x000a) + seg); // 103b -> 1228; lin=1326a
    memoryASet16(0x1327 + seg, 0x000e, memoryAGet16(0x1327 + seg, 0x000e) + seg); // 103b -> 1228; lin=1327e
    memoryASet16(0x1328 + seg, 0x000c, memoryAGet16(0x1328 + seg, 0x000c) + seg); // 103b -> 1228; lin=1328c
    memoryASet16(0x1329 + seg, 0x0004, memoryAGet16(0x1329 + seg, 0x0004) + seg); // 103b -> 1228; lin=13294
    memoryASet16(0x1329 + seg, 0x0008, memoryAGet16(0x1329 + seg, 0x0008) + seg); // 103b -> 1228; lin=13298
    memoryASet16(0x1329 + seg, 0x000c, memoryAGet16(0x1329 + seg, 0x000c) + seg); // 103b -> 1228; lin=1329c
    memoryASet16(0x132a + seg, 0x0000, memoryAGet16(0x132a + seg, 0x0000) + seg); // 103b -> 1228; lin=132a0
    memoryASet16(0x132a + seg, 0x0004, memoryAGet16(0x132a + seg, 0x0004) + seg); // 103b -> 1228; lin=132a4
    memoryASet16(0x132a + seg, 0x0008, memoryAGet16(0x132a + seg, 0x0008) + seg); // 103b -> 1228; lin=132a8
    memoryASet16(0x132a + seg, 0x000c, memoryAGet16(0x132a + seg, 0x000c) + seg); // 103b -> 1228; lin=132ac
    memoryASet16(0x132b + seg, 0x0000, memoryAGet16(0x132b + seg, 0x0000) + seg); // 103b -> 1228; lin=132b0
    memoryASet16(0x132b + seg, 0x0004, memoryAGet16(0x132b + seg, 0x0004) + seg); // 103b -> 1228; lin=132b4
    memoryASet16(0x132b + seg, 0x0008, memoryAGet16(0x132b + seg, 0x0008) + seg); // 103b -> 1228; lin=132b8
    memoryASet16(0x132b + seg, 0x000c, memoryAGet16(0x132b + seg, 0x000c) + seg); // 103b -> 1228; lin=132bc
    memoryASet16(0x132c + seg, 0x0000, memoryAGet16(0x132c + seg, 0x0000) + seg); // 103b -> 1228; lin=132c0
    memoryASet16(0x132c + seg, 0x0004, memoryAGet16(0x132c + seg, 0x0004) + seg); // 103b -> 1228; lin=132c4
    memoryASet16(0x132c + seg, 0x0008, memoryAGet16(0x132c + seg, 0x0008) + seg); // 103b -> 1228; lin=132c8
    memoryASet16(0x132c + seg, 0x000c, memoryAGet16(0x132c + seg, 0x000c) + seg); // 103b -> 1228; lin=132cc
    memoryASet16(0x132d + seg, 0x0000, memoryAGet16(0x132d + seg, 0x0000) + seg); // 103b -> 1228; lin=132d0
    memoryASet16(0x132d + seg, 0x0004, memoryAGet16(0x132d + seg, 0x0004) + seg); // 103b -> 1228; lin=132d4
    memoryASet16(0x132d + seg, 0x0008, memoryAGet16(0x132d + seg, 0x0008) + seg); // 103b -> 1228; lin=132d8
    memoryASet16(0x132d + seg, 0x000c, memoryAGet16(0x132d + seg, 0x000c) + seg); // 103b -> 1228; lin=132dc
    memoryASet16(0x132e + seg, 0x0000, memoryAGet16(0x132e + seg, 0x0000) + seg); // 103b -> 1228; lin=132e0
    memoryASet16(0x132e + seg, 0x0004, memoryAGet16(0x132e + seg, 0x0004) + seg); // 103b -> 1228; lin=132e4
    memoryASet16(0x132e + seg, 0x0008, memoryAGet16(0x132e + seg, 0x0008) + seg); // 103b -> 1228; lin=132e8
    memoryASet16(0x132e + seg, 0x000c, memoryAGet16(0x132e + seg, 0x000c) + seg); // 103b -> 1228; lin=132ec
    memoryASet16(0x132f + seg, 0x0000, memoryAGet16(0x132f + seg, 0x0000) + seg); // 103b -> 1228; lin=132f0
    memoryASet16(0x132f + seg, 0x0004, memoryAGet16(0x132f + seg, 0x0004) + seg); // 103b -> 1228; lin=132f4
    memoryASet16(0x132f + seg, 0x0008, memoryAGet16(0x132f + seg, 0x0008) + seg); // 103b -> 1228; lin=132f8
    memoryASet16(0x132f + seg, 0x000c, memoryAGet16(0x132f + seg, 0x000c) + seg); // 103b -> 1228; lin=132fc
    memoryASet16(0x1330 + seg, 0x0000, memoryAGet16(0x1330 + seg, 0x0000) + seg); // 103b -> 1228; lin=13300
    memoryASet16(0x1330 + seg, 0x0004, memoryAGet16(0x1330 + seg, 0x0004) + seg); // 103b -> 1228; lin=13304
    memoryASet16(0x1330 + seg, 0x0008, memoryAGet16(0x1330 + seg, 0x0008) + seg); // 103b -> 1228; lin=13308
    memoryASet16(0x1330 + seg, 0x000c, memoryAGet16(0x1330 + seg, 0x000c) + seg); // 103b -> 1228; lin=1330c
    memoryASet16(0x1331 + seg, 0x0000, memoryAGet16(0x1331 + seg, 0x0000) + seg); // 103b -> 1228; lin=13310
    memoryASet16(0x1331 + seg, 0x0004, memoryAGet16(0x1331 + seg, 0x0004) + seg); // 103b -> 1228; lin=13314
    memoryASet16(0x1331 + seg, 0x0008, memoryAGet16(0x1331 + seg, 0x0008) + seg); // 103b -> 1228; lin=13318
    memoryASet16(0x1331 + seg, 0x000c, memoryAGet16(0x1331 + seg, 0x000c) + seg); // 103b -> 1228; lin=1331c
    memoryASet16(0x1332 + seg, 0x0000, memoryAGet16(0x1332 + seg, 0x0000) + seg); // 103b -> 1228; lin=13320
    memoryASet16(0x1332 + seg, 0x0004, memoryAGet16(0x1332 + seg, 0x0004) + seg); // 103b -> 1228; lin=13324
    memoryASet16(0x1332 + seg, 0x0008, memoryAGet16(0x1332 + seg, 0x0008) + seg); // 103b -> 1228; lin=13328
    memoryASet16(0x1332 + seg, 0x000c, memoryAGet16(0x1332 + seg, 0x000c) + seg); // 103b -> 1228; lin=1332c
    memoryASet16(0x1333 + seg, 0x0000, memoryAGet16(0x1333 + seg, 0x0000) + seg); // 103b -> 1228; lin=13330
    memoryASet16(0x1333 + seg, 0x0004, memoryAGet16(0x1333 + seg, 0x0004) + seg); // 103b -> 1228; lin=13334
    memoryASet16(0x1333 + seg, 0x0008, memoryAGet16(0x1333 + seg, 0x0008) + seg); // 103b -> 1228; lin=13338
    memoryASet16(0x1333 + seg, 0x000c, memoryAGet16(0x1333 + seg, 0x000c) + seg); // 103b -> 1228; lin=1333c
    memoryASet16(0x1334 + seg, 0x0000, memoryAGet16(0x1334 + seg, 0x0000) + seg); // 103b -> 1228; lin=13340
    memoryASet16(0x1334 + seg, 0x0004, memoryAGet16(0x1334 + seg, 0x0004) + seg); // 103b -> 1228; lin=13344
    memoryASet16(0x1334 + seg, 0x0008, memoryAGet16(0x1334 + seg, 0x0008) + seg); // 103b -> 1228; lin=13348
    memoryASet16(0x1334 + seg, 0x000c, memoryAGet16(0x1334 + seg, 0x000c) + seg); // 103b -> 1228; lin=1334c
    memoryASet16(0x1335 + seg, 0x0000, memoryAGet16(0x1335 + seg, 0x0000) + seg); // 103b -> 1228; lin=13350
    memoryASet16(0x1335 + seg, 0x0004, memoryAGet16(0x1335 + seg, 0x0004) + seg); // 103b -> 1228; lin=13354
    memoryASet16(0x1335 + seg, 0x0008, memoryAGet16(0x1335 + seg, 0x0008) + seg); // 103b -> 1228; lin=13358
    memoryASet16(0x1335 + seg, 0x000c, memoryAGet16(0x1335 + seg, 0x000c) + seg); // 103b -> 1228; lin=1335c
    memoryASet16(0x1336 + seg, 0x0000, memoryAGet16(0x1336 + seg, 0x0000) + seg); // 103b -> 1228; lin=13360
    memoryASet16(0x1336 + seg, 0x0004, memoryAGet16(0x1336 + seg, 0x0004) + seg); // 103b -> 1228; lin=13364
    memoryASet16(0x1336 + seg, 0x0008, memoryAGet16(0x1336 + seg, 0x0008) + seg); // 103b -> 1228; lin=13368
    memoryASet16(0x1336 + seg, 0x000c, memoryAGet16(0x1336 + seg, 0x000c) + seg); // 103b -> 1228; lin=1336c
    memoryASet16(0x1337 + seg, 0x0000, memoryAGet16(0x1337 + seg, 0x0000) + seg); // 103b -> 1228; lin=13370
    memoryASet16(0x1337 + seg, 0x0004, memoryAGet16(0x1337 + seg, 0x0004) + seg); // 103b -> 1228; lin=13374
    memoryASet16(0x1337 + seg, 0x0008, memoryAGet16(0x1337 + seg, 0x0008) + seg); // 103b -> 1228; lin=13378
    memoryASet16(0x1337 + seg, 0x000c, memoryAGet16(0x1337 + seg, 0x000c) + seg); // 103b -> 1228; lin=1337c
    memoryASet16(0x1338 + seg, 0x0000, memoryAGet16(0x1338 + seg, 0x0000) + seg); // 103b -> 1228; lin=13380
    memoryASet16(0x1338 + seg, 0x0004, memoryAGet16(0x1338 + seg, 0x0004) + seg); // 103b -> 1228; lin=13384
    memoryASet16(0x1338 + seg, 0x0008, memoryAGet16(0x1338 + seg, 0x0008) + seg); // 103b -> 1228; lin=13388
    memoryASet16(0x1338 + seg, 0x000c, memoryAGet16(0x1338 + seg, 0x000c) + seg); // 103b -> 1228; lin=1338c
    memoryASet16(0x1339 + seg, 0x0000, memoryAGet16(0x1339 + seg, 0x0000) + seg); // 103b -> 1228; lin=13390
    memoryASet16(0x1339 + seg, 0x0004, memoryAGet16(0x1339 + seg, 0x0004) + seg); // 103b -> 1228; lin=13394
    memoryASet16(0x1339 + seg, 0x0008, memoryAGet16(0x1339 + seg, 0x0008) + seg); // 103b -> 1228; lin=13398
    memoryASet16(0x1339 + seg, 0x000c, memoryAGet16(0x1339 + seg, 0x000c) + seg); // 103b -> 1228; lin=1339c
    memoryASet16(0x133a + seg, 0x0000, memoryAGet16(0x133a + seg, 0x0000) + seg); // 103b -> 1228; lin=133a0
    memoryASet16(0x133a + seg, 0x0004, memoryAGet16(0x133a + seg, 0x0004) + seg); // 103b -> 1228; lin=133a4
    memoryASet16(0x133a + seg, 0x0008, memoryAGet16(0x133a + seg, 0x0008) + seg); // 103b -> 1228; lin=133a8
    memoryASet16(0x133a + seg, 0x000c, memoryAGet16(0x133a + seg, 0x000c) + seg); // 103b -> 1228; lin=133ac
    memoryASet16(0x133b + seg, 0x0000, memoryAGet16(0x133b + seg, 0x0000) + seg); // 103b -> 1228; lin=133b0
    memoryASet16(0x133b + seg, 0x0004, memoryAGet16(0x133b + seg, 0x0004) + seg); // 103b -> 1228; lin=133b4
    memoryASet16(0x133b + seg, 0x0008, memoryAGet16(0x133b + seg, 0x0008) + seg); // 103b -> 1228; lin=133b8
    memoryASet16(0x133b + seg, 0x000c, memoryAGet16(0x133b + seg, 0x000c) + seg); // 103b -> 1228; lin=133bc
    memoryASet16(0x133c + seg, 0x0000, memoryAGet16(0x133c + seg, 0x0000) + seg); // 103b -> 1228; lin=133c0
    memoryASet16(0x133c + seg, 0x0004, memoryAGet16(0x133c + seg, 0x0004) + seg); // 103b -> 1228; lin=133c4
    memoryASet16(0x133c + seg, 0x0008, memoryAGet16(0x133c + seg, 0x0008) + seg); // 103b -> 1228; lin=133c8
    memoryASet16(0x133c + seg, 0x000c, memoryAGet16(0x133c + seg, 0x000c) + seg); // 103b -> 1228; lin=133cc
    memoryASet16(0x133d + seg, 0x0000, memoryAGet16(0x133d + seg, 0x0000) + seg); // 103b -> 1228; lin=133d0
    memoryASet16(0x133d + seg, 0x0004, memoryAGet16(0x133d + seg, 0x0004) + seg); // 103b -> 1228; lin=133d4
    memoryASet16(0x133d + seg, 0x0008, memoryAGet16(0x133d + seg, 0x0008) + seg); // 103b -> 1228; lin=133d8
    memoryASet16(0x133d + seg, 0x000c, memoryAGet16(0x133d + seg, 0x000c) + seg); // 103b -> 1228; lin=133dc
    memoryASet16(0x133e + seg, 0x0000, memoryAGet16(0x133e + seg, 0x0000) + seg); // 103b -> 1228; lin=133e0
    memoryASet16(0x133e + seg, 0x0004, memoryAGet16(0x133e + seg, 0x0004) + seg); // 103b -> 1228; lin=133e4
    memoryASet16(0x133e + seg, 0x0008, memoryAGet16(0x133e + seg, 0x0008) + seg); // 103b -> 1228; lin=133e8
    memoryASet16(0x133e + seg, 0x000c, memoryAGet16(0x133e + seg, 0x000c) + seg); // 103b -> 1228; lin=133ec
    memoryASet16(0x133f + seg, 0x0000, memoryAGet16(0x133f + seg, 0x0000) + seg); // 103b -> 1228; lin=133f0
    memoryASet16(0x133f + seg, 0x0004, memoryAGet16(0x133f + seg, 0x0004) + seg); // 103b -> 1228; lin=133f4
    memoryASet16(0x133f + seg, 0x0008, memoryAGet16(0x133f + seg, 0x0008) + seg); // 103b -> 1228; lin=133f8
    memoryASet16(0x133f + seg, 0x000c, memoryAGet16(0x133f + seg, 0x000c) + seg); // 103b -> 1228; lin=133fc
    memoryASet16(0x1340 + seg, 0x0000, memoryAGet16(0x1340 + seg, 0x0000) + seg); // 103b -> 1228; lin=13400
    memoryASet16(0x1340 + seg, 0x0004, memoryAGet16(0x1340 + seg, 0x0004) + seg); // 103b -> 1228; lin=13404
    memoryASet16(0x1340 + seg, 0x0008, memoryAGet16(0x1340 + seg, 0x0008) + seg); // 103b -> 1228; lin=13408
    memoryASet16(0x1340 + seg, 0x000c, memoryAGet16(0x1340 + seg, 0x000c) + seg); // 103b -> 1228; lin=1340c
    memoryASet16(0x1341 + seg, 0x000e, memoryAGet16(0x1341 + seg, 0x000e) + seg); // 103b -> 1228; lin=1341e
    memoryASet16(0x1343 + seg, 0x0006, memoryAGet16(0x1343 + seg, 0x0006) + seg); // 103b -> 1228; lin=13436
    memoryASet16(0x1344 + seg, 0x000e, memoryAGet16(0x1344 + seg, 0x000e) + seg); // 103b -> 1228; lin=1344e
    memoryASet16(0x1346 + seg, 0x0006, memoryAGet16(0x1346 + seg, 0x0006) + seg); // 103b -> 1228; lin=13466
    memoryASet16(0x1347 + seg, 0x000a, memoryAGet16(0x1347 + seg, 0x000a) + seg); // 103b -> 1228; lin=1347a
    memoryASet16(0x1348 + seg, 0x000e, memoryAGet16(0x1348 + seg, 0x000e) + seg); // 103b -> 1228; lin=1348e
    memoryASet16(0x134a + seg, 0x0006, memoryAGet16(0x134a + seg, 0x0006) + seg); // 103b -> 1228; lin=134a6
    memoryASet16(0x134b + seg, 0x0004, memoryAGet16(0x134b + seg, 0x0004) + seg); // 103b -> 1228; lin=134b4
    memoryASet16(0x134c + seg, 0x0002, memoryAGet16(0x134c + seg, 0x0002) + seg); // 103b -> 1228; lin=134c2
    memoryASet16(0x134d + seg, 0x000a, memoryAGet16(0x134d + seg, 0x000a) + seg); // 103b -> 1228; lin=134da
    memoryASet16(0x134e + seg, 0x000e, memoryAGet16(0x134e + seg, 0x000e) + seg); // 103b -> 1228; lin=134ee
    memoryASet16(0x1350 + seg, 0x0002, memoryAGet16(0x1350 + seg, 0x0002) + seg); // 103b -> 1228; lin=13502
    memoryASet16(0x1351 + seg, 0x0006, memoryAGet16(0x1351 + seg, 0x0006) + seg); // 103b -> 1228; lin=13516
    memoryASet16(0x1352 + seg, 0x000a, memoryAGet16(0x1352 + seg, 0x000a) + seg); // 103b -> 1228; lin=1352a
    memoryASet16(0x1353 + seg, 0x000e, memoryAGet16(0x1353 + seg, 0x000e) + seg); // 103b -> 1228; lin=1353e
    memoryASet16(0x1354 + seg, 0x000c, memoryAGet16(0x1354 + seg, 0x000c) + seg); // 103b -> 1228; lin=1354c
    memoryASet16(0x1356 + seg, 0x0002, memoryAGet16(0x1356 + seg, 0x0002) + seg); // 103b -> 1228; lin=13562
    memoryASet16(0x1357 + seg, 0x0008, memoryAGet16(0x1357 + seg, 0x0008) + seg); // 103b -> 1228; lin=13578
    memoryASet16(0x1358 + seg, 0x000e, memoryAGet16(0x1358 + seg, 0x000e) + seg); // 103b -> 1228; lin=1358e
    memoryASet16(0x135a + seg, 0x0002, memoryAGet16(0x135a + seg, 0x0002) + seg); // 103b -> 1228; lin=135a2
    memoryASet16(0x135b + seg, 0x0006, memoryAGet16(0x135b + seg, 0x0006) + seg); // 103b -> 1228; lin=135b6
    memoryASet16(0x135d + seg, 0x000a, memoryAGet16(0x135d + seg, 0x000a) + seg); // 103b -> 1228; lin=135da
    memoryASet16(0x135f + seg, 0x0000, memoryAGet16(0x135f + seg, 0x0000) + seg); // 103b -> 1228; lin=135f0
    memoryASet16(0x1360 + seg, 0x0004, memoryAGet16(0x1360 + seg, 0x0004) + seg); // 103b -> 1228; lin=13604
    memoryASet16(0x1360 + seg, 0x000c, memoryAGet16(0x1360 + seg, 0x000c) + seg); // 103b -> 1228; lin=1360c
    memoryASet16(0x1361 + seg, 0x0000, memoryAGet16(0x1361 + seg, 0x0000) + seg); // 103b -> 1228; lin=13610
    memoryASet16(0x1361 + seg, 0x0004, memoryAGet16(0x1361 + seg, 0x0004) + seg); // 103b -> 1228; lin=13614
    memoryASet16(0x1361 + seg, 0x0008, memoryAGet16(0x1361 + seg, 0x0008) + seg); // 103b -> 1228; lin=13618
    memoryASet16(0x1361 + seg, 0x000c, memoryAGet16(0x1361 + seg, 0x000c) + seg); // 103b -> 1228; lin=1361c
    memoryASet16(0x1362 + seg, 0x0000, memoryAGet16(0x1362 + seg, 0x0000) + seg); // 103b -> 1228; lin=13620
    memoryASet16(0x1362 + seg, 0x0004, memoryAGet16(0x1362 + seg, 0x0004) + seg); // 103b -> 1228; lin=13624
    memoryASet16(0x1362 + seg, 0x0008, memoryAGet16(0x1362 + seg, 0x0008) + seg); // 103b -> 1228; lin=13628
    memoryASet16(0x1362 + seg, 0x000c, memoryAGet16(0x1362 + seg, 0x000c) + seg); // 103b -> 1228; lin=1362c
    memoryASet16(0x1363 + seg, 0x0000, memoryAGet16(0x1363 + seg, 0x0000) + seg); // 103b -> 1228; lin=13630
    memoryASet16(0x1363 + seg, 0x0004, memoryAGet16(0x1363 + seg, 0x0004) + seg); // 103b -> 1228; lin=13634
    memoryASet16(0x1363 + seg, 0x0008, memoryAGet16(0x1363 + seg, 0x0008) + seg); // 103b -> 1228; lin=13638
    memoryASet16(0x1363 + seg, 0x000c, memoryAGet16(0x1363 + seg, 0x000c) + seg); // 103b -> 1228; lin=1363c
    memoryASet16(0x1364 + seg, 0x0000, memoryAGet16(0x1364 + seg, 0x0000) + seg); // 103b -> 1228; lin=13640
    memoryASet16(0x1364 + seg, 0x0004, memoryAGet16(0x1364 + seg, 0x0004) + seg); // 103b -> 1228; lin=13644
    memoryASet16(0x1364 + seg, 0x0008, memoryAGet16(0x1364 + seg, 0x0008) + seg); // 103b -> 1228; lin=13648
    memoryASet16(0x1364 + seg, 0x000c, memoryAGet16(0x1364 + seg, 0x000c) + seg); // 103b -> 1228; lin=1364c
    memoryASet16(0x1365 + seg, 0x0000, memoryAGet16(0x1365 + seg, 0x0000) + seg); // 103b -> 1228; lin=13650
    memoryASet16(0x1365 + seg, 0x0004, memoryAGet16(0x1365 + seg, 0x0004) + seg); // 103b -> 1228; lin=13654
    memoryASet16(0x1365 + seg, 0x0008, memoryAGet16(0x1365 + seg, 0x0008) + seg); // 103b -> 1228; lin=13658
    memoryASet16(0x1365 + seg, 0x000c, memoryAGet16(0x1365 + seg, 0x000c) + seg); // 103b -> 1228; lin=1365c
    memoryASet16(0x1366 + seg, 0x0000, memoryAGet16(0x1366 + seg, 0x0000) + seg); // 103b -> 1228; lin=13660
    memoryASet16(0x1366 + seg, 0x0004, memoryAGet16(0x1366 + seg, 0x0004) + seg); // 103b -> 1228; lin=13664
    memoryASet16(0x1366 + seg, 0x0008, memoryAGet16(0x1366 + seg, 0x0008) + seg); // 103b -> 1228; lin=13668
    memoryASet16(0x1412 + seg, 0x0000, memoryAGet16(0x1412 + seg, 0x0000) + seg); // 103b -> 1228; lin=14120
    memoryASet16(0x1412 + seg, 0x0004, memoryAGet16(0x1412 + seg, 0x0004) + seg); // 103b -> 1228; lin=14124
    memoryASet16(0x1412 + seg, 0x0008, memoryAGet16(0x1412 + seg, 0x0008) + seg); // 103b -> 1228; lin=14128
    memoryASet16(0x1412 + seg, 0x000c, memoryAGet16(0x1412 + seg, 0x000c) + seg); // 103b -> 1228; lin=1412c
    memoryASet16(0x1413 + seg, 0x0000, memoryAGet16(0x1413 + seg, 0x0000) + seg); // 103b -> 1228; lin=14130
    memoryASet16(0x1413 + seg, 0x0004, memoryAGet16(0x1413 + seg, 0x0004) + seg); // 103b -> 1228; lin=14134
    memoryASet16(0x1413 + seg, 0x0008, memoryAGet16(0x1413 + seg, 0x0008) + seg); // 103b -> 1228; lin=14138
    memoryASet16(0x1413 + seg, 0x000c, memoryAGet16(0x1413 + seg, 0x000c) + seg); // 103b -> 1228; lin=1413c
    memoryASet16(0x1414 + seg, 0x0000, memoryAGet16(0x1414 + seg, 0x0000) + seg); // 103b -> 1228; lin=14140
    memoryASet16(0x1414 + seg, 0x0004, memoryAGet16(0x1414 + seg, 0x0004) + seg); // 103b -> 1228; lin=14144
    memoryASet16(0x1414 + seg, 0x0008, memoryAGet16(0x1414 + seg, 0x0008) + seg); // 103b -> 1228; lin=14148
    memoryASet16(0x1414 + seg, 0x000c, memoryAGet16(0x1414 + seg, 0x000c) + seg); // 103b -> 1228; lin=1414c
    memoryASet16(0x1415 + seg, 0x0000, memoryAGet16(0x1415 + seg, 0x0000) + seg); // 103b -> 1228; lin=14150
    memoryASet16(0x1415 + seg, 0x0004, memoryAGet16(0x1415 + seg, 0x0004) + seg); // 103b -> 1228; lin=14154
    memoryASet16(0x1415 + seg, 0x0008, memoryAGet16(0x1415 + seg, 0x0008) + seg); // 103b -> 1228; lin=14158
    memoryASet16(0x1415 + seg, 0x000c, memoryAGet16(0x1415 + seg, 0x000c) + seg); // 103b -> 1228; lin=1415c
    memoryASet16(0x1416 + seg, 0x0000, memoryAGet16(0x1416 + seg, 0x0000) + seg); // 103b -> 1228; lin=14160
    memoryASet16(0x1416 + seg, 0x0004, memoryAGet16(0x1416 + seg, 0x0004) + seg); // 103b -> 1228; lin=14164
    memoryASet16(0x1416 + seg, 0x0008, memoryAGet16(0x1416 + seg, 0x0008) + seg); // 103b -> 1228; lin=14168
    memoryASet16(0x1416 + seg, 0x000c, memoryAGet16(0x1416 + seg, 0x000c) + seg); // 103b -> 1228; lin=1416c
    memoryASet16(0x1417 + seg, 0x0000, memoryAGet16(0x1417 + seg, 0x0000) + seg); // 103b -> 1228; lin=14170
    memoryASet16(0x1417 + seg, 0x0004, memoryAGet16(0x1417 + seg, 0x0004) + seg); // 103b -> 1228; lin=14174
    memoryASet16(0x1417 + seg, 0x0008, memoryAGet16(0x1417 + seg, 0x0008) + seg); // 103b -> 1228; lin=14178
    memoryASet16(0x1417 + seg, 0x000c, memoryAGet16(0x1417 + seg, 0x000c) + seg); // 103b -> 1228; lin=1417c
    memoryASet16(0x1418 + seg, 0x0000, memoryAGet16(0x1418 + seg, 0x0000) + seg); // 103b -> 1228; lin=14180
    memoryASet16(0x1418 + seg, 0x0004, memoryAGet16(0x1418 + seg, 0x0004) + seg); // 103b -> 1228; lin=14184
    memoryASet16(0x1418 + seg, 0x0008, memoryAGet16(0x1418 + seg, 0x0008) + seg); // 103b -> 1228; lin=14188
    memoryASet16(0x1418 + seg, 0x000c, memoryAGet16(0x1418 + seg, 0x000c) + seg); // 103b -> 1228; lin=1418c
    memoryASet16(0x1419 + seg, 0x0000, memoryAGet16(0x1419 + seg, 0x0000) + seg); // 103b -> 1228; lin=14190
    memoryASet16(0x1419 + seg, 0x0004, memoryAGet16(0x1419 + seg, 0x0004) + seg); // 103b -> 1228; lin=14194
    memoryASet16(0x1419 + seg, 0x0008, memoryAGet16(0x1419 + seg, 0x0008) + seg); // 103b -> 1228; lin=14198
    memoryASet16(0x1419 + seg, 0x000c, memoryAGet16(0x1419 + seg, 0x000c) + seg); // 103b -> 1228; lin=1419c
    memoryASet16(0x141a + seg, 0x0000, memoryAGet16(0x141a + seg, 0x0000) + seg); // 103b -> 1228; lin=141a0
    memoryASet16(0x141a + seg, 0x0004, memoryAGet16(0x141a + seg, 0x0004) + seg); // 103b -> 1228; lin=141a4
    memoryASet16(0x141a + seg, 0x0008, memoryAGet16(0x141a + seg, 0x0008) + seg); // 103b -> 1228; lin=141a8
    memoryASet16(0x141a + seg, 0x000c, memoryAGet16(0x141a + seg, 0x000c) + seg); // 103b -> 1228; lin=141ac
    memoryASet16(0x141b + seg, 0x0000, memoryAGet16(0x141b + seg, 0x0000) + seg); // 103b -> 1228; lin=141b0
    memoryASet16(0x141b + seg, 0x0004, memoryAGet16(0x141b + seg, 0x0004) + seg); // 103b -> 1228; lin=141b4
    memoryASet16(0x141b + seg, 0x0008, memoryAGet16(0x141b + seg, 0x0008) + seg); // 103b -> 1228; lin=141b8
    memoryASet16(0x141b + seg, 0x000c, memoryAGet16(0x141b + seg, 0x000c) + seg); // 103b -> 1228; lin=141bc
    memoryASet16(0x141c + seg, 0x0000, memoryAGet16(0x141c + seg, 0x0000) + seg); // 103b -> 1228; lin=141c0
    memoryASet16(0x141c + seg, 0x0004, memoryAGet16(0x141c + seg, 0x0004) + seg); // 103b -> 1228; lin=141c4
    memoryASet16(0x141c + seg, 0x0008, memoryAGet16(0x141c + seg, 0x0008) + seg); // 103b -> 1228; lin=141c8
    memoryASet16(0x141c + seg, 0x000c, memoryAGet16(0x141c + seg, 0x000c) + seg); // 103b -> 1228; lin=141cc
    memoryASet16(0x141d + seg, 0x0000, memoryAGet16(0x141d + seg, 0x0000) + seg); // 103b -> 1228; lin=141d0
    memoryASet16(0x141d + seg, 0x0004, memoryAGet16(0x141d + seg, 0x0004) + seg); // 103b -> 1228; lin=141d4
    memoryASet16(0x141d + seg, 0x0008, memoryAGet16(0x141d + seg, 0x0008) + seg); // 103b -> 1228; lin=141d8
    memoryASet16(0x141d + seg, 0x000c, memoryAGet16(0x141d + seg, 0x000c) + seg); // 103b -> 1228; lin=141dc
    memoryASet16(0x141e + seg, 0x0000, memoryAGet16(0x141e + seg, 0x0000) + seg); // 103b -> 1228; lin=141e0
    memoryASet16(0x141e + seg, 0x0004, memoryAGet16(0x141e + seg, 0x0004) + seg); // 103b -> 1228; lin=141e4
    memoryASet16(0x141e + seg, 0x0008, memoryAGet16(0x141e + seg, 0x0008) + seg); // 103b -> 1228; lin=141e8
    memoryASet16(0x141e + seg, 0x000c, memoryAGet16(0x141e + seg, 0x000c) + seg); // 103b -> 1228; lin=141ec
    memoryASet16(0x141f + seg, 0x0000, memoryAGet16(0x141f + seg, 0x0000) + seg); // 103b -> 1228; lin=141f0
    memoryASet16(0x141f + seg, 0x0004, memoryAGet16(0x141f + seg, 0x0004) + seg); // 103b -> 1228; lin=141f4
    memoryASet16(0x141f + seg, 0x0008, memoryAGet16(0x141f + seg, 0x0008) + seg); // 103b -> 1228; lin=141f8
    memoryASet16(0x141f + seg, 0x000c, memoryAGet16(0x141f + seg, 0x000c) + seg); // 103b -> 1228; lin=141fc
    memoryASet16(0x1420 + seg, 0x0000, memoryAGet16(0x1420 + seg, 0x0000) + seg); // 103b -> 1228; lin=14200
    memoryASet16(0x1420 + seg, 0x0004, memoryAGet16(0x1420 + seg, 0x0004) + seg); // 103b -> 1228; lin=14204
    memoryASet16(0x1420 + seg, 0x0008, memoryAGet16(0x1420 + seg, 0x0008) + seg); // 103b -> 1228; lin=14208
    memoryASet16(0x1420 + seg, 0x000c, memoryAGet16(0x1420 + seg, 0x000c) + seg); // 103b -> 1228; lin=1420c
    memoryASet16(0x1421 + seg, 0x0000, memoryAGet16(0x1421 + seg, 0x0000) + seg); // 103b -> 1228; lin=14210
    memoryASet16(0x1421 + seg, 0x0004, memoryAGet16(0x1421 + seg, 0x0004) + seg); // 103b -> 1228; lin=14214
    memoryASet16(0x1421 + seg, 0x0008, memoryAGet16(0x1421 + seg, 0x0008) + seg); // 103b -> 1228; lin=14218
    memoryASet16(0x1421 + seg, 0x000c, memoryAGet16(0x1421 + seg, 0x000c) + seg); // 103b -> 1228; lin=1421c
    memoryASet16(0x1422 + seg, 0x0000, memoryAGet16(0x1422 + seg, 0x0000) + seg); // 103b -> 1228; lin=14220
    memoryASet16(0x1422 + seg, 0x0004, memoryAGet16(0x1422 + seg, 0x0004) + seg); // 103b -> 1228; lin=14224
    memoryASet16(0x1422 + seg, 0x0008, memoryAGet16(0x1422 + seg, 0x0008) + seg); // 103b -> 1228; lin=14228
    memoryASet16(0x1422 + seg, 0x000c, memoryAGet16(0x1422 + seg, 0x000c) + seg); // 103b -> 1228; lin=1422c
    memoryASet16(0x1423 + seg, 0x0000, memoryAGet16(0x1423 + seg, 0x0000) + seg); // 103b -> 1228; lin=14230
    memoryASet16(0x1423 + seg, 0x0004, memoryAGet16(0x1423 + seg, 0x0004) + seg); // 103b -> 1228; lin=14234
    memoryASet16(0x1423 + seg, 0x0008, memoryAGet16(0x1423 + seg, 0x0008) + seg); // 103b -> 1228; lin=14238
    memoryASet16(0x1423 + seg, 0x000c, memoryAGet16(0x1423 + seg, 0x000c) + seg); // 103b -> 1228; lin=1423c
    memoryASet16(0x1424 + seg, 0x0000, memoryAGet16(0x1424 + seg, 0x0000) + seg); // 103b -> 1228; lin=14240
    memoryASet16(0x1424 + seg, 0x0004, memoryAGet16(0x1424 + seg, 0x0004) + seg); // 103b -> 1228; lin=14244
    memoryASet16(0x1424 + seg, 0x0008, memoryAGet16(0x1424 + seg, 0x0008) + seg); // 103b -> 1228; lin=14248
    memoryASet16(0x1424 + seg, 0x000c, memoryAGet16(0x1424 + seg, 0x000c) + seg); // 103b -> 1228; lin=1424c
    memoryASet16(0x1425 + seg, 0x0000, memoryAGet16(0x1425 + seg, 0x0000) + seg); // 103b -> 1228; lin=14250
    memoryASet16(0x1425 + seg, 0x0004, memoryAGet16(0x1425 + seg, 0x0004) + seg); // 103b -> 1228; lin=14254
    memoryASet16(0x1425 + seg, 0x0008, memoryAGet16(0x1425 + seg, 0x0008) + seg); // 103b -> 1228; lin=14258
    memoryASet16(0x1425 + seg, 0x000c, memoryAGet16(0x1425 + seg, 0x000c) + seg); // 103b -> 1228; lin=1425c
    memoryASet16(0x1426 + seg, 0x0000, memoryAGet16(0x1426 + seg, 0x0000) + seg); // 103b -> 1228; lin=14260
    memoryASet16(0x1426 + seg, 0x0004, memoryAGet16(0x1426 + seg, 0x0004) + seg); // 103b -> 1228; lin=14264
    memoryASet16(0x1426 + seg, 0x0008, memoryAGet16(0x1426 + seg, 0x0008) + seg); // 103b -> 1228; lin=14268
    memoryASet16(0x1426 + seg, 0x000c, memoryAGet16(0x1426 + seg, 0x000c) + seg); // 103b -> 1228; lin=1426c
    memoryASet16(0x1427 + seg, 0x0000, memoryAGet16(0x1427 + seg, 0x0000) + seg); // 103b -> 1228; lin=14270
    memoryASet16(0x1427 + seg, 0x0004, memoryAGet16(0x1427 + seg, 0x0004) + seg); // 103b -> 1228; lin=14274
    memoryASet16(0x1427 + seg, 0x0008, memoryAGet16(0x1427 + seg, 0x0008) + seg); // 103b -> 1228; lin=14278
    memoryASet16(0x1427 + seg, 0x000c, memoryAGet16(0x1427 + seg, 0x000c) + seg); // 103b -> 1228; lin=1427c
    memoryASet16(0x1428 + seg, 0x0000, memoryAGet16(0x1428 + seg, 0x0000) + seg); // 103b -> 1228; lin=14280
    memoryASet16(0x1428 + seg, 0x0004, memoryAGet16(0x1428 + seg, 0x0004) + seg); // 103b -> 1228; lin=14284
    memoryASet16(0x1428 + seg, 0x0008, memoryAGet16(0x1428 + seg, 0x0008) + seg); // 103b -> 1228; lin=14288
    memoryASet16(0x1428 + seg, 0x000c, memoryAGet16(0x1428 + seg, 0x000c) + seg); // 103b -> 1228; lin=1428c
    memoryASet16(0x1429 + seg, 0x0000, memoryAGet16(0x1429 + seg, 0x0000) + seg); // 103b -> 1228; lin=14290
    memoryASet16(0x1429 + seg, 0x0004, memoryAGet16(0x1429 + seg, 0x0004) + seg); // 103b -> 1228; lin=14294
    memoryASet16(0x1429 + seg, 0x0008, memoryAGet16(0x1429 + seg, 0x0008) + seg); // 103b -> 1228; lin=14298
    memoryASet16(0x1429 + seg, 0x000c, memoryAGet16(0x1429 + seg, 0x000c) + seg); // 103b -> 1228; lin=1429c
    memoryASet16(0x142a + seg, 0x0000, memoryAGet16(0x142a + seg, 0x0000) + seg); // 103b -> 1228; lin=142a0
    memoryASet16(0x142a + seg, 0x0004, memoryAGet16(0x142a + seg, 0x0004) + seg); // 103b -> 1228; lin=142a4
    memoryASet16(0x142a + seg, 0x0008, memoryAGet16(0x142a + seg, 0x0008) + seg); // 103b -> 1228; lin=142a8
    memoryASet16(0x142a + seg, 0x000c, memoryAGet16(0x142a + seg, 0x000c) + seg); // 103b -> 1228; lin=142ac
    memoryASet16(0x142b + seg, 0x0000, memoryAGet16(0x142b + seg, 0x0000) + seg); // 103b -> 1228; lin=142b0
    memoryASet16(0x142b + seg, 0x0004, memoryAGet16(0x142b + seg, 0x0004) + seg); // 103b -> 1228; lin=142b4
    memoryASet16(0x142b + seg, 0x0008, memoryAGet16(0x142b + seg, 0x0008) + seg); // 103b -> 1228; lin=142b8
    memoryASet16(0x142b + seg, 0x000c, memoryAGet16(0x142b + seg, 0x000c) + seg); // 103b -> 1228; lin=142bc
    memoryASet16(0x142c + seg, 0x0000, memoryAGet16(0x142c + seg, 0x0000) + seg); // 103b -> 1228; lin=142c0
    memoryASet16(0x142c + seg, 0x0004, memoryAGet16(0x142c + seg, 0x0004) + seg); // 103b -> 1228; lin=142c4
    memoryASet16(0x142c + seg, 0x0008, memoryAGet16(0x142c + seg, 0x0008) + seg); // 103b -> 1228; lin=142c8
    memoryASet16(0x142c + seg, 0x000c, memoryAGet16(0x142c + seg, 0x000c) + seg); // 103b -> 1228; lin=142cc
    memoryASet16(0x142d + seg, 0x0000, memoryAGet16(0x142d + seg, 0x0000) + seg); // 103b -> 1228; lin=142d0
    memoryASet16(0x142d + seg, 0x0004, memoryAGet16(0x142d + seg, 0x0004) + seg); // 103b -> 1228; lin=142d4
    memoryASet16(0x142d + seg, 0x0008, memoryAGet16(0x142d + seg, 0x0008) + seg); // 103b -> 1228; lin=142d8
    memoryASet16(0x142d + seg, 0x000c, memoryAGet16(0x142d + seg, 0x000c) + seg); // 103b -> 1228; lin=142dc
    memoryASet16(0x142e + seg, 0x0000, memoryAGet16(0x142e + seg, 0x0000) + seg); // 103b -> 1228; lin=142e0
    memoryASet16(0x142e + seg, 0x0004, memoryAGet16(0x142e + seg, 0x0004) + seg); // 103b -> 1228; lin=142e4
    memoryASet16(0x142e + seg, 0x0008, memoryAGet16(0x142e + seg, 0x0008) + seg); // 103b -> 1228; lin=142e8
    memoryASet16(0x142e + seg, 0x000c, memoryAGet16(0x142e + seg, 0x000c) + seg); // 103b -> 1228; lin=142ec
    memoryASet16(0x142f + seg, 0x0000, memoryAGet16(0x142f + seg, 0x0000) + seg); // 103b -> 1228; lin=142f0
    memoryASet16(0x142f + seg, 0x0004, memoryAGet16(0x142f + seg, 0x0004) + seg); // 103b -> 1228; lin=142f4
    memoryASet16(0x142f + seg, 0x0008, memoryAGet16(0x142f + seg, 0x0008) + seg); // 103b -> 1228; lin=142f8
    memoryASet16(0x142f + seg, 0x000c, memoryAGet16(0x142f + seg, 0x000c) + seg); // 103b -> 1228; lin=142fc
    memoryASet16(0x1430 + seg, 0x0000, memoryAGet16(0x1430 + seg, 0x0000) + seg); // 103b -> 1228; lin=14300
    memoryASet16(0x1430 + seg, 0x0004, memoryAGet16(0x1430 + seg, 0x0004) + seg); // 103b -> 1228; lin=14304
    memoryASet16(0x1430 + seg, 0x0008, memoryAGet16(0x1430 + seg, 0x0008) + seg); // 103b -> 1228; lin=14308
    memoryASet16(0x1430 + seg, 0x000c, memoryAGet16(0x1430 + seg, 0x000c) + seg); // 103b -> 1228; lin=1430c
    memoryASet16(0x1431 + seg, 0x0000, memoryAGet16(0x1431 + seg, 0x0000) + seg); // 103b -> 1228; lin=14310
    memoryASet16(0x1431 + seg, 0x0004, memoryAGet16(0x1431 + seg, 0x0004) + seg); // 103b -> 1228; lin=14314
    memoryASet16(0x1431 + seg, 0x0008, memoryAGet16(0x1431 + seg, 0x0008) + seg); // 103b -> 1228; lin=14318
    memoryASet16(0x1431 + seg, 0x000c, memoryAGet16(0x1431 + seg, 0x000c) + seg); // 103b -> 1228; lin=1431c
    memoryASet16(0x1432 + seg, 0x0000, memoryAGet16(0x1432 + seg, 0x0000) + seg); // 103b -> 1228; lin=14320
    memoryASet16(0x1432 + seg, 0x0004, memoryAGet16(0x1432 + seg, 0x0004) + seg); // 103b -> 1228; lin=14324
    memoryASet16(0x1432 + seg, 0x0008, memoryAGet16(0x1432 + seg, 0x0008) + seg); // 103b -> 1228; lin=14328
    memoryASet16(0x1432 + seg, 0x000c, memoryAGet16(0x1432 + seg, 0x000c) + seg); // 103b -> 1228; lin=1432c
    memoryASet16(0x1433 + seg, 0x0000, memoryAGet16(0x1433 + seg, 0x0000) + seg); // 103b -> 1228; lin=14330
    memoryASet16(0x1433 + seg, 0x0004, memoryAGet16(0x1433 + seg, 0x0004) + seg); // 103b -> 1228; lin=14334
    memoryASet16(0x1433 + seg, 0x0008, memoryAGet16(0x1433 + seg, 0x0008) + seg); // 103b -> 1228; lin=14338
    memoryASet16(0x1433 + seg, 0x000c, memoryAGet16(0x1433 + seg, 0x000c) + seg); // 103b -> 1228; lin=1433c
    memoryASet16(0x1434 + seg, 0x0000, memoryAGet16(0x1434 + seg, 0x0000) + seg); // 103b -> 1228; lin=14340
    memoryASet16(0x1434 + seg, 0x0004, memoryAGet16(0x1434 + seg, 0x0004) + seg); // 103b -> 1228; lin=14344
    memoryASet16(0x1434 + seg, 0x0008, memoryAGet16(0x1434 + seg, 0x0008) + seg); // 103b -> 1228; lin=14348
    memoryASet16(0x1434 + seg, 0x000c, memoryAGet16(0x1434 + seg, 0x000c) + seg); // 103b -> 1228; lin=1434c
    memoryASet16(0x1435 + seg, 0x0000, memoryAGet16(0x1435 + seg, 0x0000) + seg); // 103b -> 1228; lin=14350
    memoryASet16(0x1435 + seg, 0x0004, memoryAGet16(0x1435 + seg, 0x0004) + seg); // 103b -> 1228; lin=14354
    memoryASet16(0x1435 + seg, 0x0008, memoryAGet16(0x1435 + seg, 0x0008) + seg); // 103b -> 1228; lin=14358
    memoryASet16(0x1435 + seg, 0x000c, memoryAGet16(0x1435 + seg, 0x000c) + seg); // 103b -> 1228; lin=1435c
    memoryASet16(0x1436 + seg, 0x0000, memoryAGet16(0x1436 + seg, 0x0000) + seg); // 103b -> 1228; lin=14360
    memoryASet16(0x1436 + seg, 0x0004, memoryAGet16(0x1436 + seg, 0x0004) + seg); // 103b -> 1228; lin=14364
    memoryASet16(0x1436 + seg, 0x0008, memoryAGet16(0x1436 + seg, 0x0008) + seg); // 103b -> 1228; lin=14368
    memoryASet16(0x1436 + seg, 0x000c, memoryAGet16(0x1436 + seg, 0x000c) + seg); // 103b -> 1228; lin=1436c
    memoryASet16(0x1437 + seg, 0x0000, memoryAGet16(0x1437 + seg, 0x0000) + seg); // 103b -> 1228; lin=14370
    memoryASet16(0x1437 + seg, 0x0004, memoryAGet16(0x1437 + seg, 0x0004) + seg); // 103b -> 1228; lin=14374
    memoryASet16(0x1437 + seg, 0x0008, memoryAGet16(0x1437 + seg, 0x0008) + seg); // 103b -> 1228; lin=14378
    memoryASet16(0x1437 + seg, 0x000c, memoryAGet16(0x1437 + seg, 0x000c) + seg); // 103b -> 1228; lin=1437c
    memoryASet16(0x1438 + seg, 0x0000, memoryAGet16(0x1438 + seg, 0x0000) + seg); // 103b -> 1228; lin=14380
    memoryASet16(0x1438 + seg, 0x0004, memoryAGet16(0x1438 + seg, 0x0004) + seg); // 103b -> 1228; lin=14384
    memoryASet16(0x1438 + seg, 0x0008, memoryAGet16(0x1438 + seg, 0x0008) + seg); // 103b -> 1228; lin=14388
    memoryASet16(0x1438 + seg, 0x000c, memoryAGet16(0x1438 + seg, 0x000c) + seg); // 103b -> 1228; lin=1438c
    memoryASet16(0x1439 + seg, 0x0000, memoryAGet16(0x1439 + seg, 0x0000) + seg); // 103b -> 1228; lin=14390
    memoryASet16(0x1439 + seg, 0x0004, memoryAGet16(0x1439 + seg, 0x0004) + seg); // 103b -> 1228; lin=14394
    memoryASet16(0x1439 + seg, 0x0008, memoryAGet16(0x1439 + seg, 0x0008) + seg); // 103b -> 1228; lin=14398
    memoryASet16(0x1439 + seg, 0x000c, memoryAGet16(0x1439 + seg, 0x000c) + seg); // 103b -> 1228; lin=1439c
    memoryASet16(0x143a + seg, 0x0000, memoryAGet16(0x143a + seg, 0x0000) + seg); // 103b -> 1228; lin=143a0
    memoryASet16(0x143a + seg, 0x0004, memoryAGet16(0x143a + seg, 0x0004) + seg); // 103b -> 1228; lin=143a4
    memoryASet16(0x143a + seg, 0x0008, memoryAGet16(0x143a + seg, 0x0008) + seg); // 103b -> 1228; lin=143a8
    memoryASet16(0x143a + seg, 0x000c, memoryAGet16(0x143a + seg, 0x000c) + seg); // 103b -> 1228; lin=143ac
    memoryASet16(0x143b + seg, 0x0000, memoryAGet16(0x143b + seg, 0x0000) + seg); // 103b -> 1228; lin=143b0
    memoryASet16(0x143b + seg, 0x0004, memoryAGet16(0x143b + seg, 0x0004) + seg); // 103b -> 1228; lin=143b4
    memoryASet16(0x143b + seg, 0x0008, memoryAGet16(0x143b + seg, 0x0008) + seg); // 103b -> 1228; lin=143b8
    memoryASet16(0x143b + seg, 0x000c, memoryAGet16(0x143b + seg, 0x000c) + seg); // 103b -> 1228; lin=143bc
    memoryASet16(0x143c + seg, 0x0000, memoryAGet16(0x143c + seg, 0x0000) + seg); // 103b -> 1228; lin=143c0
    memoryASet16(0x143c + seg, 0x0004, memoryAGet16(0x143c + seg, 0x0004) + seg); // 103b -> 1228; lin=143c4
    memoryASet16(0x143c + seg, 0x0008, memoryAGet16(0x143c + seg, 0x0008) + seg); // 103b -> 1228; lin=143c8
    memoryASet16(0x143c + seg, 0x000c, memoryAGet16(0x143c + seg, 0x000c) + seg); // 103b -> 1228; lin=143cc
    memoryASet16(0x143d + seg, 0x0000, memoryAGet16(0x143d + seg, 0x0000) + seg); // 103b -> 1228; lin=143d0
    memoryASet16(0x143d + seg, 0x0004, memoryAGet16(0x143d + seg, 0x0004) + seg); // 103b -> 1228; lin=143d4
    memoryASet16(0x143d + seg, 0x0008, memoryAGet16(0x143d + seg, 0x0008) + seg); // 103b -> 1228; lin=143d8
    memoryASet16(0x143d + seg, 0x000c, memoryAGet16(0x143d + seg, 0x000c) + seg); // 103b -> 1228; lin=143dc
    memoryASet16(0x143e + seg, 0x0000, memoryAGet16(0x143e + seg, 0x0000) + seg); // 103b -> 1228; lin=143e0
    memoryASet16(0x143e + seg, 0x0004, memoryAGet16(0x143e + seg, 0x0004) + seg); // 103b -> 1228; lin=143e4
    memoryASet16(0x143e + seg, 0x0008, memoryAGet16(0x143e + seg, 0x0008) + seg); // 103b -> 1228; lin=143e8
    memoryASet16(0x143e + seg, 0x000c, memoryAGet16(0x143e + seg, 0x000c) + seg); // 103b -> 1228; lin=143ec
    memoryASet16(0x143f + seg, 0x0000, memoryAGet16(0x143f + seg, 0x0000) + seg); // 103b -> 1228; lin=143f0
    memoryASet16(0x143f + seg, 0x0004, memoryAGet16(0x143f + seg, 0x0004) + seg); // 103b -> 1228; lin=143f4
    memoryASet16(0x143f + seg, 0x0008, memoryAGet16(0x143f + seg, 0x0008) + seg); // 103b -> 1228; lin=143f8
    memoryASet16(0x143f + seg, 0x000c, memoryAGet16(0x143f + seg, 0x000c) + seg); // 103b -> 1228; lin=143fc
    memoryASet16(0x1440 + seg, 0x0000, memoryAGet16(0x1440 + seg, 0x0000) + seg); // 103b -> 1228; lin=14400
    memoryASet16(0x1440 + seg, 0x0004, memoryAGet16(0x1440 + seg, 0x0004) + seg); // 103b -> 1228; lin=14404
    memoryASet16(0x1440 + seg, 0x0008, memoryAGet16(0x1440 + seg, 0x0008) + seg); // 103b -> 1228; lin=14408
    memoryASet16(0x1440 + seg, 0x000c, memoryAGet16(0x1440 + seg, 0x000c) + seg); // 103b -> 1228; lin=1440c
    memoryASet16(0x1441 + seg, 0x0000, memoryAGet16(0x1441 + seg, 0x0000) + seg); // 103b -> 1228; lin=14410
    memoryASet16(0x1441 + seg, 0x0004, memoryAGet16(0x1441 + seg, 0x0004) + seg); // 103b -> 1228; lin=14414
    memoryASet16(0x1441 + seg, 0x0008, memoryAGet16(0x1441 + seg, 0x0008) + seg); // 103b -> 1228; lin=14418
    memoryASet16(0x1441 + seg, 0x000c, memoryAGet16(0x1441 + seg, 0x000c) + seg); // 103b -> 1228; lin=1441c
    memoryASet16(0x1442 + seg, 0x0000, memoryAGet16(0x1442 + seg, 0x0000) + seg); // 103b -> 1228; lin=14420
    memoryASet16(0x1442 + seg, 0x0004, memoryAGet16(0x1442 + seg, 0x0004) + seg); // 103b -> 1228; lin=14424
    memoryASet16(0x1442 + seg, 0x0008, memoryAGet16(0x1442 + seg, 0x0008) + seg); // 103b -> 1228; lin=14428
    memoryASet16(0x1442 + seg, 0x000c, memoryAGet16(0x1442 + seg, 0x000c) + seg); // 103b -> 1228; lin=1442c
    memoryASet16(0x1443 + seg, 0x0000, memoryAGet16(0x1443 + seg, 0x0000) + seg); // 103b -> 1228; lin=14430
    memoryASet16(0x1445 + seg, 0x000c, memoryAGet16(0x1445 + seg, 0x000c) + seg); // 103b -> 1228; lin=1445c
    memoryASet16(0x1446 + seg, 0x0000, memoryAGet16(0x1446 + seg, 0x0000) + seg); // 103b -> 1228; lin=14460
    memoryASet16(0x1446 + seg, 0x0004, memoryAGet16(0x1446 + seg, 0x0004) + seg); // 103b -> 1228; lin=14464
    memoryASet16(0x1446 + seg, 0x0008, memoryAGet16(0x1446 + seg, 0x0008) + seg); // 103b -> 1228; lin=14468
    memoryASet16(0x1446 + seg, 0x000c, memoryAGet16(0x1446 + seg, 0x000c) + seg); // 103b -> 1228; lin=1446c
    memoryASet16(0x1447 + seg, 0x0000, memoryAGet16(0x1447 + seg, 0x0000) + seg); // 103b -> 1228; lin=14470
    memoryASet16(0x1447 + seg, 0x0004, memoryAGet16(0x1447 + seg, 0x0004) + seg); // 103b -> 1228; lin=14474
    memoryASet16(0x1447 + seg, 0x0008, memoryAGet16(0x1447 + seg, 0x0008) + seg); // 103b -> 1228; lin=14478
    memoryASet16(0x1447 + seg, 0x000c, memoryAGet16(0x1447 + seg, 0x000c) + seg); // 103b -> 1228; lin=1447c
    memoryASet16(0x1448 + seg, 0x0000, memoryAGet16(0x1448 + seg, 0x0000) + seg); // 103b -> 1228; lin=14480
    memoryASet16(0x1448 + seg, 0x0004, memoryAGet16(0x1448 + seg, 0x0004) + seg); // 103b -> 1228; lin=14484
    memoryASet16(0x1448 + seg, 0x0008, memoryAGet16(0x1448 + seg, 0x0008) + seg); // 103b -> 1228; lin=14488
    memoryASet16(0x1448 + seg, 0x000c, memoryAGet16(0x1448 + seg, 0x000c) + seg); // 103b -> 1228; lin=1448c
    memoryASet16(0x1449 + seg, 0x0000, memoryAGet16(0x1449 + seg, 0x0000) + seg); // 103b -> 1228; lin=14490
    memoryASet16(0x1449 + seg, 0x0004, memoryAGet16(0x1449 + seg, 0x0004) + seg); // 103b -> 1228; lin=14494
    memoryASet16(0x1449 + seg, 0x0008, memoryAGet16(0x1449 + seg, 0x0008) + seg); // 103b -> 1228; lin=14498
    memoryASet16(0x1449 + seg, 0x000c, memoryAGet16(0x1449 + seg, 0x000c) + seg); // 103b -> 1228; lin=1449c
    memoryASet16(0x144a + seg, 0x0000, memoryAGet16(0x144a + seg, 0x0000) + seg); // 103b -> 1228; lin=144a0
    memoryASet16(0x144a + seg, 0x0004, memoryAGet16(0x144a + seg, 0x0004) + seg); // 103b -> 1228; lin=144a4
    memoryASet16(0x144a + seg, 0x0008, memoryAGet16(0x144a + seg, 0x0008) + seg); // 103b -> 1228; lin=144a8
    memoryASet16(0x144a + seg, 0x000c, memoryAGet16(0x144a + seg, 0x000c) + seg); // 103b -> 1228; lin=144ac
    memoryASet16(0x144b + seg, 0x0000, memoryAGet16(0x144b + seg, 0x0000) + seg); // 103b -> 1228; lin=144b0
    memoryASet16(0x144b + seg, 0x0004, memoryAGet16(0x144b + seg, 0x0004) + seg); // 103b -> 1228; lin=144b4
    memoryASet16(0x144b + seg, 0x0008, memoryAGet16(0x144b + seg, 0x0008) + seg); // 103b -> 1228; lin=144b8
    memoryASet16(0x144b + seg, 0x000c, memoryAGet16(0x144b + seg, 0x000c) + seg); // 103b -> 1228; lin=144bc
    memoryASet16(0x144c + seg, 0x0000, memoryAGet16(0x144c + seg, 0x0000) + seg); // 103b -> 1228; lin=144c0
    memoryASet16(0x144c + seg, 0x0004, memoryAGet16(0x144c + seg, 0x0004) + seg); // 103b -> 1228; lin=144c4
    memoryASet16(0x144c + seg, 0x0008, memoryAGet16(0x144c + seg, 0x0008) + seg); // 103b -> 1228; lin=144c8
    memoryASet16(0x144c + seg, 0x000c, memoryAGet16(0x144c + seg, 0x000c) + seg); // 103b -> 1228; lin=144cc
    memoryASet16(0x144d + seg, 0x0000, memoryAGet16(0x144d + seg, 0x0000) + seg); // 103b -> 1228; lin=144d0
    memoryASet16(0x144d + seg, 0x0004, memoryAGet16(0x144d + seg, 0x0004) + seg); // 103b -> 1228; lin=144d4
    memoryASet16(0x144d + seg, 0x0008, memoryAGet16(0x144d + seg, 0x0008) + seg); // 103b -> 1228; lin=144d8
    memoryASet16(0x144d + seg, 0x000c, memoryAGet16(0x144d + seg, 0x000c) + seg); // 103b -> 1228; lin=144dc
    memoryASet16(0x144e + seg, 0x0000, memoryAGet16(0x144e + seg, 0x0000) + seg); // 103b -> 1228; lin=144e0
    memoryASet16(0x144e + seg, 0x0004, memoryAGet16(0x144e + seg, 0x0004) + seg); // 103b -> 1228; lin=144e4
    memoryASet16(0x144e + seg, 0x0008, memoryAGet16(0x144e + seg, 0x0008) + seg); // 103b -> 1228; lin=144e8
    memoryASet16(0x144e + seg, 0x000c, memoryAGet16(0x144e + seg, 0x000c) + seg); // 103b -> 1228; lin=144ec
    memoryASet16(0x144f + seg, 0x0000, memoryAGet16(0x144f + seg, 0x0000) + seg); // 103b -> 1228; lin=144f0
    memoryASet16(0x144f + seg, 0x0004, memoryAGet16(0x144f + seg, 0x0004) + seg); // 103b -> 1228; lin=144f4
    memoryASet16(0x144f + seg, 0x0008, memoryAGet16(0x144f + seg, 0x0008) + seg); // 103b -> 1228; lin=144f8
    memoryASet16(0x144f + seg, 0x000c, memoryAGet16(0x144f + seg, 0x000c) + seg); // 103b -> 1228; lin=144fc
    memoryASet16(0x1450 + seg, 0x0000, memoryAGet16(0x1450 + seg, 0x0000) + seg); // 103b -> 1228; lin=14500
    memoryASet16(0x1450 + seg, 0x0004, memoryAGet16(0x1450 + seg, 0x0004) + seg); // 103b -> 1228; lin=14504
    memoryASet16(0x1450 + seg, 0x0008, memoryAGet16(0x1450 + seg, 0x0008) + seg); // 103b -> 1228; lin=14508
    memoryASet16(0x1450 + seg, 0x000c, memoryAGet16(0x1450 + seg, 0x000c) + seg); // 103b -> 1228; lin=1450c
    memoryASet16(0x1451 + seg, 0x0000, memoryAGet16(0x1451 + seg, 0x0000) + seg); // 103b -> 1228; lin=14510
    memoryASet16(0x1451 + seg, 0x0004, memoryAGet16(0x1451 + seg, 0x0004) + seg); // 103b -> 1228; lin=14514
    memoryASet16(0x1451 + seg, 0x0008, memoryAGet16(0x1451 + seg, 0x0008) + seg); // 103b -> 1228; lin=14518
    memoryASet16(0x1451 + seg, 0x000c, memoryAGet16(0x1451 + seg, 0x000c) + seg); // 103b -> 1228; lin=1451c
    memoryASet16(0x1452 + seg, 0x0000, memoryAGet16(0x1452 + seg, 0x0000) + seg); // 103b -> 1228; lin=14520
    memoryASet16(0x1452 + seg, 0x0004, memoryAGet16(0x1452 + seg, 0x0004) + seg); // 103b -> 1228; lin=14524
    memoryASet16(0x1452 + seg, 0x0008, memoryAGet16(0x1452 + seg, 0x0008) + seg); // 103b -> 1228; lin=14528
    memoryASet16(0x1452 + seg, 0x000c, memoryAGet16(0x1452 + seg, 0x000c) + seg); // 103b -> 1228; lin=1452c
    memoryASet16(0x1453 + seg, 0x0000, memoryAGet16(0x1453 + seg, 0x0000) + seg); // 103b -> 1228; lin=14530
    memoryASet16(0x1453 + seg, 0x0004, memoryAGet16(0x1453 + seg, 0x0004) + seg); // 103b -> 1228; lin=14534
    memoryASet16(0x1453 + seg, 0x0008, memoryAGet16(0x1453 + seg, 0x0008) + seg); // 103b -> 1228; lin=14538
    memoryASet16(0x1453 + seg, 0x000c, memoryAGet16(0x1453 + seg, 0x000c) + seg); // 103b -> 1228; lin=1453c
    memoryASet16(0x1454 + seg, 0x0000, memoryAGet16(0x1454 + seg, 0x0000) + seg); // 103b -> 1228; lin=14540
    memoryASet16(0x1454 + seg, 0x0004, memoryAGet16(0x1454 + seg, 0x0004) + seg); // 103b -> 1228; lin=14544
    memoryASet16(0x1454 + seg, 0x0008, memoryAGet16(0x1454 + seg, 0x0008) + seg); // 103b -> 1228; lin=14548
    memoryASet16(0x1454 + seg, 0x000c, memoryAGet16(0x1454 + seg, 0x000c) + seg); // 103b -> 1228; lin=1454c
    memoryASet16(0x1455 + seg, 0x0000, memoryAGet16(0x1455 + seg, 0x0000) + seg); // 103b -> 1228; lin=14550
    memoryASet16(0x1455 + seg, 0x0004, memoryAGet16(0x1455 + seg, 0x0004) + seg); // 103b -> 1228; lin=14554
    memoryASet16(0x1455 + seg, 0x0008, memoryAGet16(0x1455 + seg, 0x0008) + seg); // 103b -> 1228; lin=14558
    memoryASet16(0x1455 + seg, 0x000c, memoryAGet16(0x1455 + seg, 0x000c) + seg); // 103b -> 1228; lin=1455c
    memoryASet16(0x1456 + seg, 0x0000, memoryAGet16(0x1456 + seg, 0x0000) + seg); // 103b -> 1228; lin=14560
    memoryASet16(0x1456 + seg, 0x0004, memoryAGet16(0x1456 + seg, 0x0004) + seg); // 103b -> 1228; lin=14564
    memoryASet16(0x1456 + seg, 0x0008, memoryAGet16(0x1456 + seg, 0x0008) + seg); // 103b -> 1228; lin=14568
    memoryASet16(0x1456 + seg, 0x000c, memoryAGet16(0x1456 + seg, 0x000c) + seg); // 103b -> 1228; lin=1456c
    memoryASet16(0x1457 + seg, 0x0000, memoryAGet16(0x1457 + seg, 0x0000) + seg); // 103b -> 1228; lin=14570
    memoryASet16(0x1457 + seg, 0x0004, memoryAGet16(0x1457 + seg, 0x0004) + seg); // 103b -> 1228; lin=14574
    memoryASet16(0x1457 + seg, 0x0008, memoryAGet16(0x1457 + seg, 0x0008) + seg); // 103b -> 1228; lin=14578
    memoryASet16(0x1457 + seg, 0x000c, memoryAGet16(0x1457 + seg, 0x000c) + seg); // 103b -> 1228; lin=1457c
    memoryASet16(0x1458 + seg, 0x0000, memoryAGet16(0x1458 + seg, 0x0000) + seg); // 103b -> 1228; lin=14580
    memoryASet16(0x1458 + seg, 0x0004, memoryAGet16(0x1458 + seg, 0x0004) + seg); // 103b -> 1228; lin=14584
    memoryASet16(0x1458 + seg, 0x0008, memoryAGet16(0x1458 + seg, 0x0008) + seg); // 103b -> 1228; lin=14588
    memoryASet16(0x1458 + seg, 0x000c, memoryAGet16(0x1458 + seg, 0x000c) + seg); // 103b -> 1228; lin=1458c
    memoryASet16(0x1459 + seg, 0x0000, memoryAGet16(0x1459 + seg, 0x0000) + seg); // 103b -> 1228; lin=14590
    memoryASet16(0x1459 + seg, 0x0004, memoryAGet16(0x1459 + seg, 0x0004) + seg); // 103b -> 1228; lin=14594
    memoryASet16(0x1459 + seg, 0x0008, memoryAGet16(0x1459 + seg, 0x0008) + seg); // 103b -> 1228; lin=14598
    memoryASet16(0x1459 + seg, 0x000c, memoryAGet16(0x1459 + seg, 0x000c) + seg); // 103b -> 1228; lin=1459c
    memoryASet16(0x145a + seg, 0x0000, memoryAGet16(0x145a + seg, 0x0000) + seg); // 103b -> 1228; lin=145a0
    memoryASet16(0x145a + seg, 0x0004, memoryAGet16(0x145a + seg, 0x0004) + seg); // 103b -> 1228; lin=145a4
    memoryASet16(0x145a + seg, 0x0008, memoryAGet16(0x145a + seg, 0x0008) + seg); // 103b -> 1228; lin=145a8
    memoryASet16(0x145a + seg, 0x000c, memoryAGet16(0x145a + seg, 0x000c) + seg); // 103b -> 1228; lin=145ac
    memoryASet16(0x145b + seg, 0x0000, memoryAGet16(0x145b + seg, 0x0000) + seg); // 103b -> 1228; lin=145b0
    memoryASet16(0x145b + seg, 0x0004, memoryAGet16(0x145b + seg, 0x0004) + seg); // 103b -> 1228; lin=145b4
    memoryASet16(0x145b + seg, 0x0008, memoryAGet16(0x145b + seg, 0x0008) + seg); // 103b -> 1228; lin=145b8
    memoryASet16(0x145b + seg, 0x000c, memoryAGet16(0x145b + seg, 0x000c) + seg); // 103b -> 1228; lin=145bc
    memoryASet16(0x145c + seg, 0x0000, memoryAGet16(0x145c + seg, 0x0000) + seg); // 103b -> 1228; lin=145c0
    memoryASet16(0x145c + seg, 0x0004, memoryAGet16(0x145c + seg, 0x0004) + seg); // 103b -> 1228; lin=145c4
    memoryASet16(0x145c + seg, 0x0008, memoryAGet16(0x145c + seg, 0x0008) + seg); // 103b -> 1228; lin=145c8
    memoryASet16(0x145c + seg, 0x000c, memoryAGet16(0x145c + seg, 0x000c) + seg); // 103b -> 1228; lin=145cc
    memoryASet16(0x145d + seg, 0x0000, memoryAGet16(0x145d + seg, 0x0000) + seg); // 103b -> 1228; lin=145d0
    memoryASet16(0x145d + seg, 0x0004, memoryAGet16(0x145d + seg, 0x0004) + seg); // 103b -> 1228; lin=145d4
    memoryASet16(0x145d + seg, 0x0008, memoryAGet16(0x145d + seg, 0x0008) + seg); // 103b -> 1228; lin=145d8
    memoryASet16(0x145d + seg, 0x000c, memoryAGet16(0x145d + seg, 0x000c) + seg); // 103b -> 1228; lin=145dc
    memoryASet16(0x145e + seg, 0x0000, memoryAGet16(0x145e + seg, 0x0000) + seg); // 103b -> 1228; lin=145e0
    memoryASet16(0x145e + seg, 0x0004, memoryAGet16(0x145e + seg, 0x0004) + seg); // 103b -> 1228; lin=145e4
    memoryASet16(0x145e + seg, 0x0008, memoryAGet16(0x145e + seg, 0x0008) + seg); // 103b -> 1228; lin=145e8
    memoryASet16(0x145e + seg, 0x000c, memoryAGet16(0x145e + seg, 0x000c) + seg); // 103b -> 1228; lin=145ec
    memoryASet16(0x145f + seg, 0x0000, memoryAGet16(0x145f + seg, 0x0000) + seg); // 103b -> 1228; lin=145f0
    memoryASet16(0x145f + seg, 0x0004, memoryAGet16(0x145f + seg, 0x0004) + seg); // 103b -> 1228; lin=145f4
    memoryASet16(0x145f + seg, 0x0008, memoryAGet16(0x145f + seg, 0x0008) + seg); // 103b -> 1228; lin=145f8
    memoryASet16(0x145f + seg, 0x000c, memoryAGet16(0x145f + seg, 0x000c) + seg); // 103b -> 1228; lin=145fc
    memoryASet16(0x1460 + seg, 0x0000, memoryAGet16(0x1460 + seg, 0x0000) + seg); // 103b -> 1228; lin=14600
    memoryASet16(0x1502 + seg, 0x0002, memoryAGet16(0x1502 + seg, 0x0002) + seg); // 103b -> 1228; lin=15022
    memoryASet16(0x1502 + seg, 0x0006, memoryAGet16(0x1502 + seg, 0x0006) + seg); // 103b -> 1228; lin=15026
    memoryASet16(0x1502 + seg, 0x000a, memoryAGet16(0x1502 + seg, 0x000a) + seg); // 103b -> 1228; lin=1502a
    memoryASet16(0x1502 + seg, 0x000e, memoryAGet16(0x1502 + seg, 0x000e) + seg); // 103b -> 1228; lin=1502e
    memoryASet16(0x1506 + seg, 0x000e, memoryAGet16(0x1506 + seg, 0x000e) + seg); // 103b -> 1228; lin=1506e
    memoryASet16(0x1507 + seg, 0x0002, memoryAGet16(0x1507 + seg, 0x0002) + seg); // 103b -> 1228; lin=15072
    memoryASet16(0x1507 + seg, 0x0006, memoryAGet16(0x1507 + seg, 0x0006) + seg); // 103b -> 1228; lin=15076
    memoryASet16(0x1507 + seg, 0x000a, memoryAGet16(0x1507 + seg, 0x000a) + seg); // 103b -> 1228; lin=1507a
    memoryASet16(0x1507 + seg, 0x000e, memoryAGet16(0x1507 + seg, 0x000e) + seg); // 103b -> 1228; lin=1507e
    memoryASet16(0x1584 + seg, 0x0004, memoryAGet16(0x1584 + seg, 0x0004) + seg); // 0000 -> 01ed; lin=15844
    memoryASet16(0x1584 + seg, 0x0008, memoryAGet16(0x1584 + seg, 0x0008) + seg); // 0000 -> 01ed; lin=15848
    memoryASet16(0x1587 + seg, 0x000e, memoryAGet16(0x1587 + seg, 0x000e) + seg); // 103b -> 1228; lin=1587e
    memoryASet16(0x15a9 + seg, 0x0000, memoryAGet16(0x15a9 + seg, 0x0000) + seg); // 103b -> 1228; lin=15a90
}

int GetProcAt(int seg, int ofs)
{
    int marks[] = {
0x0ca6, 0x0b81, 0x0ca6, 0x0b82, 0x0ed9, 0x25e2, 0x0ed9, 0x25e3,     };
    for (int i=0; i<sizeof(marks)/sizeof(marks[0]); i+=2)
        if (seg == marks[i] && ofs == marks[i+1])
            return 0;

    int map[] = {
        0x1ed0, 0x1ed, 0x0, 0x1ed, 0x126, 0x1ed0, 0x1ed, 0x1ea, 0x1ed, 0x258, 
        0x1fc6, 0x1ed, 0xf6, 0x1ed, 0x126, 0x1fcf, 0x1ed, 0xff, 0x1ed, 0x126, 
        0x1fe5, 0x1ed, 0x115, 0x1ed, 0x126, 0x1fff, 0x1ed, 0x12f, 0x1ed, 0x172, 
        0x2042, 0x1ed, 0x172, 0x1ed, 0x19f, 0x206f, 0x1ed, 0x19f, 0x1ed, 0x1e2, 
        0x20b2, 0x1ed, 0x1e2, 0x1ed, 0x1ea, 0x20d3, 0x1ed, 0x203, 0x1ed, 0x258, 
        0x2128, 0x1ed, 0x258, 0x1ed, 0x282, 0x2152, 0x1ed, 0x282, 0x1ed, 0x3ea, 
        0x22ba, 0x1ed, 0x3ea, 0x1ed, 0x416, 0x22e6, 0x1ed, 0x416, 0x1ed, 0x569, 
        0x2439, 0x1ed, 0x569, 0x1ed, 0x5e7, 0x24b7, 0x1ed, 0x5e7, 0x1ed, 0x604, 
        0x24d4, 0x1ed, 0x604, 0x1ed, 0x63b, 0x250b, 0x1ed, 0x63b, 0x1ed, 0x698, 
        0x26c0, 0x1ed, 0x7f0, 0x1ed, 0x816, 0x26e6, 0x1ed, 0x816, 0x1ed, 0x8d1, 
        0x27a1, 0x1ed, 0x8d1, 0x1ed, 0xa07, 0x28d7, 0x1ed, 0xa07, 0x1ed, 0xa90, 
        0x2960, 0x1ed, 0xa90, 0x1ed, 0xb88, 0x2a58, 0x1ed, 0xb88, 0x1ed, 0xbf9, 
        0x2ac9, 0x1ed, 0xbf9, 0x1ed, 0xc18, 0x2ae8, 0x1ed, 0xc18, 0x1ed, 0xd9d, 
        0x2c6d, 0x1ed, 0xd9d, 0x1ed, 0xf7a, 0x2e4a, 0x1ed, 0xf7a, 0x1ed, 0x11eb, 
        0x30bb, 0x1ed, 0x11eb, 0x1ed, 0x1349, 0x3219, 0x1ed, 0x1349, 0x1ed, 0x138c, 
        0x325c, 0x1ed, 0x138c, 0x1ed, 0x13b2, 0x3282, 0x1ed, 0x13b2, 0x1ed, 0x13df, 
        0x32af, 0x1ed, 0x13df, 0x1ed, 0x1473, 0x3343, 0x1ed, 0x1473, 0x1ed, 0x14e4, 
        0x33b4, 0x1ed, 0x14e4, 0x1ed, 0x15a1, 0x3471, 0x1ed, 0x15a1, 0x1ed, 0x165e, 
        0x352e, 0x1ed, 0x165e, 0x1ed, 0x17c7, 0x3697, 0x1ed, 0x17c7, 0x1ed, 0x19a1, 
        0x3871, 0x1ed, 0x19a1, 0x1ed, 0x19e4, 0x38b4, 0x1ed, 0x19e4, 0x1ed, 0x1a20, 
        0x38f0, 0x1ed, 0x1a20, 0x1ed, 0x1a67, 0x3937, 0x1ed, 0x1a67, 0x1ed, 0x1b2b, 
        0x39fb, 0x1ed, 0x1b2b, 0x1ed, 0x1bd7, 0x3aa7, 0x1ed, 0x1bd7, 0x1ed, 0x1c41, 
        0x3b11, 0x1ed, 0x1c41, 0x1ed, 0x1cb2, 0x3b82, 0x1ed, 0x1cb2, 0x1ed, 0x1cea, 
        0x3bba, 0x1ed, 0x1cea, 0x1ed, 0x1d26, 0x3bf6, 0x1ed, 0x1d26, 0x1ed, 0x1dde, 
        0x3cae, 0x1ed, 0x1dde, 0x1ed, 0x1e02, 0x3cd2, 0x1ed, 0x1e02, 0x1ed, 0x1e3d, 
        0x3d0d, 0x1ed, 0x1e3d, 0x1ed, 0x1e5e, 0x3d2e, 0x1ed, 0x1e5e, 0x1ed, 0x1e90, 
        0x3d60, 0x1ed, 0x1e90, 0x1ed, 0x1ec2, 0x3d92, 0x1ed, 0x1ec2, 0x1ed, 0x1f03, 
        0x3dd3, 0x1ed, 0x1f03, 0x1ed, 0x1f3e, 0x3e0e, 0x1ed, 0x1f3e, 0x1ed, 0x1f7f, 
        0x3e4f, 0x1ed, 0x1f7f, 0x1ed, 0x1fbe, 0x3e8e, 0x1ed, 0x1fbe, 0x1ed, 0x207d, 
        0x3f4d, 0x1ed, 0x207d, 0x1ed, 0x2138, 0x4008, 0x1ed, 0x2138, 0x1ed, 0x21bb, 
        0x408b, 0x1ed, 0x21bb, 0x1ed, 0x21e7, 0x40b7, 0x1ed, 0x21e7, 0x1ed, 0x2261, 
        0x4131, 0x1ed, 0x2261, 0x1ed, 0x228d, 0x415d, 0x1ed, 0x228d, 0x1ed, 0x22b0, 
        0x4180, 0x1ed, 0x22b0, 0x1ed, 0x22c1, 0x4191, 0x1ed, 0x22c1, 0x1ed, 0x22d2, 
        0x41a2, 0x1ed, 0x22d2, 0x1ed, 0x22fc, 0x41cc, 0x1ed, 0x22fc, 0x1ed, 0x233a, 
        0x420a, 0x1ed, 0x233a, 0x1ed, 0x236f, 0x423f, 0x1ed, 0x236f, 0x1ed, 0x238e, 
        0x425e, 0x1ed, 0x238e, 0x1ed, 0x23b6, 0x4286, 0x1ed, 0x23b6, 0x1ed, 0x2423, 
        0x42f3, 0x1ed, 0x2423, 0x1ed, 0x2470, 0x4340, 0x1ed, 0x2470, 0x1ed, 0x248e, 
        0x435e, 0x1ed, 0x248e, 0x1ed, 0x24d7, 0x43a7, 0x1ed, 0x24d7, 0x1ed, 0x250a, 
        0x43da, 0x1ed, 0x250a, 0x1ed, 0x253f, 0x440f, 0x1ed, 0x253f, 0x1ed, 0x25ad, 
        0x447d, 0x1ed, 0x25ad, 0x1ed, 0x2634, 0x4504, 0x1ed, 0x2634, 0x1ed, 0x26a1, 
        0x4571, 0x1ed, 0x26a1, 0x1ed, 0x270c, 0x45dc, 0x1ed, 0x270c, 0x1ed, 0x2776, 
        0x4646, 0x1ed, 0x2776, 0x1ed, 0x27de, 0x46ae, 0x1ed, 0x27de, 0x1ed, 0x2810, 
        0x46e0, 0x1ed, 0x2810, 0x1ed, 0x28e0, 0x47b0, 0x1ed, 0x28e0, 0x1ed, 0x28f9, 
        0x47c9, 0x1ed, 0x28f9, 0x1ed, 0x2965, 0x4835, 0x1ed, 0x2965, 0x1ed, 0x29a6, 
        0x4876, 0x1ed, 0x29a6, 0x1ed, 0x2a0a, 0x48da, 0x1ed, 0x2a0a, 0x1ed, 0x2a78, 
        0x4948, 0x1ed, 0x2a78, 0x1ed, 0x2d14, 0x4be4, 0x1ed, 0x2d14, 0x1ed, 0x2ef8, 
        0x4dc8, 0x1ed, 0x2ef8, 0x1ed, 0x2fac, 0x4e7c, 0x1ed, 0x2fac, 0x1ed, 0x30dd, 
        0x4fad, 0x1ed, 0x30dd, 0x1ed, 0x31de, 0x50ae, 0x1ed, 0x31de, 0x1ed, 0x328f, 
        0x515f, 0x1ed, 0x328f, 0x1ed, 0x32b0, 0x5180, 0x1ed, 0x32b0, 0x1ed, 0x33c5, 
        0x5295, 0x1ed, 0x33c5, 0x1ed, 0x3467, 0x5337, 0x1ed, 0x3467, 0x1ed, 0x35a5, 
        0x5475, 0x1ed, 0x35a5, 0x1ed, 0x3849, 0x5722, 0x1ed, 0x3852, 0x1ed, 0x3a88, 
        0x5958, 0x1ed, 0x3a88, 0x1ed, 0x3ab2, 0x5982, 0x1ed, 0x3ab2, 0x1ed, 0x3b0f, 
        0x59df, 0x1ed, 0x3b0f, 0x1ed, 0x3b6c, 0x5a3c, 0x1ed, 0x3b6c, 0x1ed, 0x3bc9, 
        0x5a99, 0x1ed, 0x3bc9, 0x1ed, 0x3c26, 0x5af6, 0x1ed, 0x3c26, 0x1ed, 0x3c4f, 
        0x5b1f, 0x1ed, 0x3c4f, 0x1ed, 0x3c9d, 0x5b6d, 0x1ed, 0x3c9d, 0x1ed, 0x3cf7, 
        0x5bc7, 0x1ed, 0x3cf7, 0x1ed, 0x3dfd, 0x5ccd, 0x1ed, 0x3dfd, 0x1ed, 0x3e74, 
        0x5d44, 0x1ed, 0x3e74, 0x1ed, 0x3e8a, 0x5d5a, 0x1ed, 0x3e8a, 0x1ed, 0x3ed4, 
        0x5da4, 0x1ed, 0x3ed4, 0x1ed, 0x4015, 0x5ee5, 0x1ed, 0x4015, 0x1ed, 0x4221, 
        0x5ee5, 0x1ed, 0x423e, 0x1ed, 0x4263, 0x6133, 0x1ed, 0x4263, 0x1ed, 0x42d9, 
        0x61a9, 0x1ed, 0x42d9, 0x1ed, 0x4305, 0x61d5, 0x1ed, 0x4305, 0x1ed, 0x431b, 
        0x61eb, 0x1ed, 0x431b, 0x1ed, 0x4344, 0x6214, 0x1ed, 0x4344, 0x1ed, 0x4361, 
        0x6231, 0x1ed, 0x4361, 0x1ed, 0x4398, 0x6268, 0x1ed, 0x4398, 0x1ed, 0x43b5, 
        0x6285, 0x1ed, 0x43b5, 0x1ed, 0x43d2, 0x62a2, 0x1ed, 0x43d2, 0x1ed, 0x43ef, 
        0x62bf, 0x1ed, 0x43ef, 0x1ed, 0x440c, 0x62dc, 0x1ed, 0x440c, 0x1ed, 0x4437, 
        0x6307, 0x1ed, 0x4437, 0x1ed, 0x4454, 0x6324, 0x1ed, 0x4454, 0x1ed, 0x448a, 
        0x635a, 0x1ed, 0x448a, 0x1ed, 0x44c0, 0x6390, 0x1ed, 0x44c0, 0x1ed, 0x450c, 
        0x63dc, 0x1ed, 0x450c, 0x1ed, 0x4532, 0x6402, 0x1ed, 0x4532, 0x1ed, 0x457a, 
        0x644a, 0x1ed, 0x457a, 0x1ed, 0x45a0, 0x6470, 0x1ed, 0x45a0, 0x1ed, 0x45cf, 
        0x649f, 0x1ed, 0x45cf, 0x1ed, 0x4605, 0x64d5, 0x1ed, 0x4605, 0x1ed, 0x463d, 
        0x650d, 0x1ed, 0x463d, 0x1ed, 0x465e, 0x652e, 0x1ed, 0x465e, 0x1ed, 0x467d, 
        0x654d, 0x1ed, 0x467d, 0x1ed, 0x469c, 0x656c, 0x1ed, 0x469c, 0x1ed, 0x46bb, 
        0x658b, 0x1ed, 0x46bb, 0x1ed, 0x4725, 0x65fd, 0x1ed, 0x472d, 0x1ed, 0x4747, 
        0x6617, 0x1ed, 0x4747, 0x1ed, 0x47cb, 0x669b, 0x1ed, 0x47cb, 0x1ed, 0x4802, 
        0x66d2, 0x1ed, 0x4802, 0x1ed, 0x483c, 0x670c, 0x1ed, 0x483c, 0x1ed, 0x48a9, 
        0x6779, 0x1ed, 0x48a9, 0x1ed, 0x4906, 0x67d6, 0x1ed, 0x4906, 0x1ed, 0x495c, 
        0x682c, 0x1ed, 0x495c, 0x1ed, 0x4995, 0x6865, 0x1ed, 0x4995, 0x1ed, 0x49d7, 
        0x68a7, 0x1ed, 0x49d7, 0x1ed, 0x4b4e, 0x6a1e, 0x1ed, 0x4b4e, 0x1ed, 0x4bc6, 
        0x6a96, 0x1ed, 0x4bc6, 0x1ed, 0x4c14, 0x6ae4, 0x1ed, 0x4c14, 0x1ed, 0x4c99, 
        0x6b69, 0x1ed, 0x4c99, 0x1ed, 0x4dbf, 0x6c8f, 0x1ed, 0x4dbf, 0x1ed, 0x4dfa, 
        0x6cca, 0x1ed, 0x4dfa, 0x1ed, 0x4e44, 0x6d14, 0x1ed, 0x4e44, 0x1ed, 0x4e7f, 
        0x6d4f, 0x1ed, 0x4e7f, 0x1ed, 0x4ec9, 0x6d99, 0x1ed, 0x4ec9, 0x1ed, 0x4f04, 
        0x6dd4, 0x1ed, 0x4f04, 0x1ed, 0x4f4e, 0x6e1e, 0x1ed, 0x4f4e, 0x1ed, 0x4f89, 
        0x6e59, 0x1ed, 0x4f89, 0x1ed, 0x4fd3, 0x6ea3, 0x1ed, 0x4fd3, 0x1ed, 0x5003, 
        0x6ed3, 0x1ed, 0x5003, 0x1ed, 0x5025, 0x6ef5, 0x1ed, 0x5025, 0x1ed, 0x503f, 
        0x6f0f, 0x1ed, 0x503f, 0x1ed, 0x5059, 0x6f29, 0x1ed, 0x5059, 0x1ed, 0x506f, 
        0x6f3f, 0x1ed, 0x506f, 0x1ed, 0x5085, 0x6f55, 0x1ed, 0x5085, 0x1ed, 0x50c0, 
        0x6f90, 0x1ed, 0x50c0, 0x1ed, 0x50fb, 0x6fcb, 0x1ed, 0x50fb, 0x1ed, 0x5181, 
        0x7051, 0x1ed, 0x5181, 0x1ed, 0x51d8, 0x70a8, 0x1ed, 0x51d8, 0x1ed, 0x535e, 
        0x722e, 0x1ed, 0x535e, 0x1ed, 0x5681, 0x7551, 0x1ed, 0x5681, 0x1ed, 0x57e1, 
        0x76b1, 0x1ed, 0x57e1, 0x1ed, 0x59d3, 0x78a3, 0x1ed, 0x59d3, 0x1ed, 0x5c87, 
        0x7b57, 0x1ed, 0x5c87, 0x1ed, 0x5fdb, 0x7eab, 0x1ed, 0x5fdb, 0x1ed, 0x603d, 
        0x7f0d, 0x1ed, 0x603d, 0x1ed, 0x6130, 0x8000, 0x1ed, 0x6130, 0x1ed, 0x6183, 
        0x8053, 0x1ed, 0x6183, 0x1ed, 0x629c, 0x816c, 0x1ed, 0x629c, 0x1ed, 0x6305, 
        0x81d5, 0x1ed, 0x6305, 0x1ed, 0x6326, 0x81f6, 0x1ed, 0x6326, 0x1ed, 0x6372, 
        0x8242, 0x1ed, 0x6372, 0x1ed, 0x63be, 0x828e, 0x1ed, 0x63be, 0x1ed, 0x640c, 
        0x82dc, 0x1ed, 0x640c, 0x1ed, 0x645d, 0x832d, 0x1ed, 0x645d, 0x1ed, 0x647e, 
        0x834e, 0x1ed, 0x647e, 0x1ed, 0x64c1, 0x8391, 0x1ed, 0x64c1, 0x1ed, 0x64e2, 
        0x83b2, 0x1ed, 0x64e2, 0x1ed, 0x64ff, 0x83cf, 0x1ed, 0x64ff, 0x1ed, 0x651c, 
        0x83ec, 0x1ed, 0x651c, 0x1ed, 0x6535, 0x8405, 0x1ed, 0x6535, 0x1ed, 0x654e, 
        0x841e, 0x1ed, 0x654e, 0x1ed, 0x6587, 0x8457, 0x1ed, 0x6587, 0x1ed, 0x65d2, 
        0x84a2, 0x1ed, 0x65d2, 0x1ed, 0x65e5, 0x84b5, 0x1ed, 0x65e5, 0x1ed, 0x65fb, 
        0x84cb, 0x1ed, 0x65fb, 0x1ed, 0x6611, 0x84e1, 0x1ed, 0x6611, 0x1ed, 0x6627, 
        0x84f7, 0x1ed, 0x6627, 0x1ed, 0x6648, 0x8518, 0x1ed, 0x6648, 0x1ed, 0x6699, 
        0x8569, 0x1ed, 0x6699, 0x1ed, 0x66d8, 0x85a8, 0x1ed, 0x66d8, 0x1ed, 0x6717, 
        0x85e7, 0x1ed, 0x6717, 0x1ed, 0x673a, 0x860a, 0x1ed, 0x673a, 0x1ed, 0x6748, 
        0x8618, 0x1ed, 0x6748, 0x1ed, 0x6789, 0x8659, 0x1ed, 0x6789, 0x1ed, 0x67ca, 
        0x869a, 0x1ed, 0x67ca, 0x1ed, 0x67e2, 0x86b2, 0x1ed, 0x67e2, 0x1ed, 0x67fb, 
        0x86cb, 0x1ed, 0x67fb, 0x1ed, 0x6813, 0x86e3, 0x1ed, 0x6813, 0x1ed, 0x6832, 
        0x8702, 0x1ed, 0x6832, 0x1ed, 0x684b, 0x871b, 0x1ed, 0x684b, 0x1ed, 0x686a, 
        0x873a, 0x1ed, 0x686a, 0x1ed, 0x6890, 0x8760, 0x1ed, 0x6890, 0x1ed, 0x68bb, 
        0x878b, 0x1ed, 0x68bb, 0x1ed, 0x68e6, 0x87b6, 0x1ed, 0x68e6, 0x1ed, 0x68fe, 
        0x87ce, 0x1ed, 0x68fe, 0x1ed, 0x6922, 0x87f2, 0x1ed, 0x6922, 0x1ed, 0x693a, 
        0x880a, 0x1ed, 0x693a, 0x1ed, 0x695e, 0x882e, 0x1ed, 0x695e, 0x1ed, 0x6987, 
        0x8857, 0x1ed, 0x6987, 0x1ed, 0x69aa, 0x887a, 0x1ed, 0x69aa, 0x1ed, 0x6a89, 
        0x8959, 0x1ed, 0x6a89, 0x1ed, 0x6bb5, 0x8a85, 0x1ed, 0x6bb5, 0x1ed, 0x6bd4, 
        0x8aa4, 0x1ed, 0x6bd4, 0x1ed, 0x6bf4, 0x8ac4, 0x1ed, 0x6bf4, 0x1ed, 0x6c14, 
        0x8ae4, 0x1ed, 0x6c14, 0x1ed, 0x6c95, 0x8b65, 0x1ed, 0x6c95, 0x1ed, 0x6d26, 
        0x8bf6, 0x1ed, 0x6d26, 0x1ed, 0x6d6a, 0x8c3a, 0x1ed, 0x6d6a, 0x1ed, 0x6d94, 
        0x8c64, 0x1ed, 0x6d94, 0x1ed, 0x6db1, 0x8cb3, 0x1ed, 0x6de3, 0x1ed, 0x6e11, 
        0x8ce1, 0x1ed, 0x6e11, 0x1ed, 0x6e30, 0x8d00, 0x1ed, 0x6e30, 0x1ed, 0x70c2, 
        0x8d00, 0x1ed, 0x70d6, 0x1ed, 0x70e7, 0x8fe1, 0x1ed, 0x7111, 0x1ed, 0x711f, 
        0x8ff0, 0x1ed, 0x7120, 0x1ed, 0x712c, 0x9105, 0x1ed, 0x7235, 0x1ed, 0x72ef, 
        0x91bf, 0x1ed, 0x72ef, 0x1ed, 0x7307, 0x91d7, 0x1ed, 0x7307, 0x1ed, 0x7319, 
        0x91e9, 0x1ed, 0x7319, 0x1ed, 0x732a, 0x923f, 0x1ed, 0x736f, 0x1ed, 0x745e, 
        0x932e, 0x1ed, 0x745e, 0x1ed, 0x748a, 0x93a5, 0x1ed, 0x74d5, 0x1ed, 0x7531, 
        0x9402, 0x1ed, 0x7532, 0x1ed, 0x7563, 0x9433, 0x1ed, 0x7563, 0x1ed, 0x757b, 
        0x944b, 0x1ed, 0x757b, 0x1ed, 0x75a2, 0x944b, 0x1ed, 0x762a, 0x1ed, 0x7634, 
        0x9472, 0x1ed, 0x75a2, 0x1ed, 0x75be, 0x9472, 0x1ed, 0x75bf, 0x1ed, 0x7634, 
        0x960c, 0x1ed, 0x773c, 0x1ed, 0x77d9, 0x96a9, 0x1ed, 0x77d9, 0x1ed, 0x785a, 
        0x9731, 0x1ed, 0x7861, 0x1ed, 0x798a, 0x985a, 0x1ed, 0x798a, 0x1ed, 0x79e6, 
        0x9947, 0x1ed, 0x7a77, 0x1ed, 0x7ab4, 0x9984, 0x1ed, 0x7ab4, 0x1ed, 0x7ad5, 
        0x998b, 0x1ed, 0x7abb, 0x1ed, 0x7ad5, 0x99d1, 0x1ed, 0x7b01, 0x1ed, 0x7b1a, 
        0x9a1a, 0x1ed, 0x7b4a, 0x1ed, 0x7b5a, 0x9a2a, 0x1ed, 0x7b5a, 0x1ed, 0x7b76, 
        0x9a63, 0x1ed, 0x7b93, 0x1ed, 0x7ba6, 0x9a77, 0x1ed, 0x7ba7, 0x1ed, 0x7bad, 
        0x9a7d, 0x1ed, 0x7bad, 0x1ed, 0x7bbd, 0x9a8d, 0x1ed, 0x7bbd, 0x1ed, 0x7bca, 
        0x9a9a, 0x1ed, 0x7bca, 0x1ed, 0x7bd7, 0x9aa7, 0x1ed, 0x7bd7, 0x1ed, 0x7bdd, 
        0x9aad, 0x1ed, 0x7bdd, 0x1ed, 0x7bea, 0x9aca, 0x1ed, 0x7bfa, 0x1ed, 0x7bfe, 
        0x9bae, 0x1ed, 0x7cde, 0x1ed, 0x7db2, 0x9c82, 0x1ed, 0x7db2, 0x1ed, 0x7db9, 
        0x9c89, 0x1ed, 0x7db9, 0x1ed, 0x7de8, 0x9cc9, 0x1ed, 0x7df9, 0x1ed, 0x7e18, 
        0x9ce8, 0x1ed, 0x7e18, 0x1ed, 0x7e3d, 0x9cef, 0x1ed, 0x7e1f, 0x1ed, 0x7e3d, 
        0x9d32, 0x1ed, 0x7e62, 0x1ed, 0x7e7a, 0x9e60, 0x1ed, 0x7f90, 0x1ed, 0x7f9a, 
        0x9e63, 0x1ed, 0x7f93, 0x1ed, 0x7f9a, 0x9e66, 0x1ed, 0x7f96, 0x1ed, 0x7f9a, 
        0x9e69, 0x1ed, 0x7f99, 0x1ed, 0x7f9a, 0x9e6a, 0x1ed, 0x7f9a, 0x1ed, 0x7fb0, 
        0x9e80, 0x1ed, 0x7fb0, 0x1ed, 0x7fde, 0x9f5e, 0x1ed, 0x808e, 0x1ed, 0x809e, 
        0x9f6e, 0x1ed, 0x809e, 0x1ed, 0x80ab, 0x9f7c, 0x1ed, 0x80ac, 0x1ed, 0x80bc, 
        0x9f8c, 0x1ed, 0x80bc, 0x1ed, 0x80cc, 0xa485, 0x1ed, 0x85b5, 0x1ed, 0x85db, 
        0xa4ab, 0x1ed, 0x85db, 0x1ed, 0x8600, 0xa4d0, 0x1ed, 0x8600, 0x1ed, 0x8626, 
        0xa4f6, 0x1ed, 0x8626, 0x1ed, 0x864c, 0xa5b9, 0x1ed, 0x86e9, 0x1ed, 0x8722, 
        0xa5f2, 0x1ed, 0x8722, 0x1ed, 0x872e, 0xa5fe, 0x1ed, 0x872e, 0x1ed, 0x873c, 
        0xa60c, 0x1ed, 0x873c, 0x1ed, 0x87a2, 0xa672, 0x1ed, 0x87a2, 0x1ed, 0x87cd, 
        0xa6d9, 0x1ed, 0x8809, 0x1ed, 0x8891, 0xa761, 0x1ed, 0x8891, 0x1ed, 0x88e5, 
        0xa7b5, 0x1ed, 0x88e5, 0x1ed, 0x891e, 0xa7ee, 0x1ed, 0x891e, 0x1ed, 0x8977, 
        0xa847, 0x1ed, 0x87cd, 0x1ed, 0x8809, 0xa847, 0x1ed, 0x8977, 0x1ed, 0x8999, 
        0xa869, 0x1ed, 0x8999, 0x1ed, 0x89a8, 0xa878, 0x1ed, 0x89a8, 0x1ed, 0x89b9, 
        0xa8b2, 0x1ed, 0x89e2, 0x1ed, 0x8a07, 0xa8d7, 0x1ed, 0x8a07, 0x1ed, 0x8a0b, 
        0xa8d7, 0x1ed, 0x8a0d, 0x1ed, 0x8a23, 0xa8f3, 0x1ed, 0x8a23, 0x1ed, 0x8a3b, 
        0xa945, 0x1ed, 0x8a75, 0x1ed, 0x8ad0, 0xa9a0, 0x1ed, 0x8ad0, 0x1ed, 0x8af6, 
        0xa9c6, 0x1ed, 0x8af6, 0x1ed, 0x8b04, 0xa9d4, 0x1ed, 0x8b04, 0x1ed, 0x8b0d, 
        0xa9dd, 0x1ed, 0x8b0d, 0x1ed, 0x8b2a, 0xa9fa, 0x1ed, 0x8b2a, 0x1ed, 0x8b46, 
        0xaa3b, 0x1ed, 0x8b6b, 0x1ed, 0x8b81, 0xaa51, 0x1ed, 0x8b81, 0x1ed, 0x8bc8, 
        0xaa98, 0x1ed, 0x8bc8, 0x1ed, 0x8e2f, 0xacff, 0x1ed, 0x8e2f, 0x1ed, 0x8e48, 
        0xad18, 0x1ed, 0x8e48, 0x1ed, 0x8e50, 0xad20, 0x1ed, 0x8e50, 0x1ed, 0x8e58, 
        0xad28, 0x1ed, 0x8e58, 0x1ed, 0x8e93, 0xad28, 0x1ed, 0x8e9e, 0x1ed, 0x8ea3, 
        0xad28, 0x1ed, 0x8ec7, 0x1ed, 0x8eeb, 0xad63, 0x1ed, 0x8e93, 0x1ed, 0x8e9e, 
        0xad73, 0x1ed, 0x8ea3, 0x1ed, 0x8ec7, 0xadbb, 0x1ed, 0x8eeb, 0x1ed, 0x8fb6, 
        0xae86, 0x1ed, 0x8fb6, 0x1ed, 0x9007, 0xaed7, 0x1ed, 0x9007, 0x1ed, 0x9056, 
        0xaf26, 0x1ed, 0x9056, 0x1ed, 0x905d, 0xaf2d, 0x1ed, 0x905d, 0x1ed, 0x9115, 
        0xafe5, 0x1ed, 0x9115, 0x1ed, 0x9136, 0xb09f, 0x1ed, 0x91cf, 0x1ed, 0x91d7, 
        0xb0a7, 0x1ed, 0x91d7, 0x1ed, 0x91df, 0xb0af, 0x1ed, 0x91df, 0x1ed, 0x922c, 
        0xb0fc, 0x1ed, 0x922c, 0x1ed, 0x9241, 0xb14c, 0x1ed, 0x927c, 0x1ed, 0x92b4, 
        0xb274, 0x1ed, 0x93a4, 0x1ed, 0x93b1, 0xb281, 0x1ed, 0x93b1, 0x1ed, 0x93b7, 
        0xb288, 0x1ed, 0x93b8, 0x1ed, 0x93c8, 0xb298, 0x1ed, 0x93c8, 0x1ed, 0x93d8, 
        0xb2a8, 0x1ed, 0x93d8, 0x1ed, 0x93e2, 0xb2d6, 0x1ed, 0x9406, 0x1ed, 0x9410, 
        0xb2e0, 0x1ed, 0x9410, 0x1ed, 0x941a, 0xb2f4, 0x1ed, 0x9424, 0x1ed, 0x942a, 
        0xb2fa, 0x1ed, 0x942a, 0x1ed, 0x9434, 0xb304, 0x1ed, 0x9434, 0x1ed, 0x9436, 
        0xb306, 0x1ed, 0x9436, 0x1ed, 0x9438, 0xb308, 0x1ed, 0x9438, 0x1ed, 0x9439, 
        0xb310, 0x1ed, 0x9440, 0x1ed, 0x945b, 0xb321, 0x1ed, 0x9451, 0x1ed, 0x945b, 
        0xb32b, 0x1ed, 0x945b, 0x1ed, 0x946c, 0xb33e, 0x1ed, 0x946e, 0x1ed, 0x9488, 
        0xb358, 0x1ed, 0x9488, 0x1ed, 0x9502, 0xb3d2, 0x1ed, 0x9502, 0x1ed, 0x956d, 
        0xb674, 0x1ed, 0x97a4, 0x1ed, 0x97aa, 0xb67a, 0x1ed, 0x97aa, 0x1ed, 0x97ae, 
        0xb695, 0x1ed, 0x97c5, 0x1ed, 0x97d5, 0xb6a5, 0x1ed, 0x97d5, 0x1ed, 0x97e5, 
        0xb6c1, 0x1ed, 0x97f1, 0x1ed, 0x97f7, 0xb6d4, 0x1ed, 0x9804, 0x1ed, 0x9814, 
        0xb6e4, 0x1ed, 0x9814, 0x1ed, 0x9821, 0xb6f1, 0x1ed, 0x9821, 0x1ed, 0x9837, 
        0xb707, 0x1ed, 0x9837, 0x1ed, 0x9847, 0xb734, 0x1ed, 0x9864, 0x1ed, 0x986a, 
        0xb75e, 0x1ed, 0x988e, 0x1ed, 0x98b9, 0xb78a, 0x1ed, 0x98ba, 0x1ed, 0x98dd, 
        0xb7ad, 0x1ed, 0x98dd, 0x1ed, 0x995b, 0xb82b, 0x1ed, 0x995b, 0x1ed, 0x999a, 
        0xb86a, 0x1ed, 0x999a, 0x1ed, 0x9a07, 0xb8d7, 0x1ed, 0x9a07, 0x1ed, 0x9ad3, 
        0xb9a3, 0x1ed, 0x9ad3, 0x1ed, 0x9b14, 0xb9e4, 0x1ed, 0x9b14, 0x1ed, 0x9b98, 
        0xba68, 0x1ed, 0x9b98, 0x1ed, 0x9c14, 0xbb32, 0x1ed, 0x9c62, 0x1ed, 0x9cd3, 
        0xbba3, 0x1ed, 0x9cd3, 0x1ed, 0x9de6, 0xbcce, 0x1ed, 0x9dfe, 0x1ed, 0x9ecc, 
        0xbcce, 0x1ed, 0x9ece, 0x1ed, 0x9f25, 0xbe68, 0x1ed, 0x9f98, 0x1ed, 0x9fb5, 
        0xbe85, 0x1ed, 0x9fb5, 0x1ed, 0x9fd3, 0xbf70, 0x1ed, 0xa0a0, 0x1ed, 0xa0b1, 
        0xbfb9, 0x1ed, 0xa0e9, 0x1ed, 0xa103, 0xc01f, 0x1ed, 0xa14f, 0x1ed, 0xa178, 
        0xc048, 0x1ed, 0xa178, 0x1ed, 0xa1b5, 0xc085, 0x1ed, 0xa1b5, 0x1ed, 0xa1c6, 
        0xc096, 0x1ed, 0xa1c6, 0x1ed, 0xa1ef, 0xc0bf, 0x1ed, 0xa1ef, 0x1ed, 0xa20a, 
        0xc0da, 0x1ed, 0xa20a, 0x1ed, 0xa21c, 0xc0ec, 0x1ed, 0xa21c, 0x1ed, 0xa360, 
        0xc230, 0x1ed, 0xa360, 0x1ed, 0xa3ae, 0xc27e, 0x1ed, 0xa3ae, 0x1ed, 0xa466, 
        0xc336, 0x1ed, 0xa466, 0x1ed, 0xa482, 0xc352, 0x1ed, 0xa482, 0x1ed, 0xa49e, 
        0xc36e, 0x1ed, 0xa49e, 0x1ed, 0xa4e7, 0xc3cc, 0x1ed, 0xa4fc, 0x1ed, 0xa55e, 
        0xc42e, 0x1ed, 0xa55e, 0x1ed, 0xa5f8, 0xc49f, 0x1ed, 0xa5cf, 0x1ed, 0xa5f8, 
        0xc4c8, 0x1ed, 0xa5f8, 0x1ed, 0xa62e, 0xc4fe, 0x1ed, 0xa62e, 0x1ed, 0xa657, 
        0xc527, 0x1ed, 0xa657, 0x1ed, 0xa6b8, 0xc588, 0x1ed, 0xa6b8, 0x1ed, 0xa6f1, 
        0xc5c1, 0x1ed, 0xa6f1, 0x1ed, 0xa714, 0xc5e4, 0x1ed, 0xa714, 0x1ed, 0xa71e, 
        0xc5e4, 0x1ed, 0xa727, 0x1ed, 0xa79b, 0xc7be, 0x1ed, 0xa8ee, 0x1ed, 0xa8f6, 
        0xc7be, 0x1ed, 0xa904, 0x1ed, 0xa985, 0xc7be, 0x1ed, 0xa988, 0x1ed, 0xa995, 
        0xc865, 0x1ed, 0xa995, 0x1ed, 0xa9c4, 0xc865, 0x1ed, 0xa9d7, 0x1ed, 0xa9f5, 
        0xc8c5, 0x1ed, 0xa9f5, 0x1ed, 0xaa11, 0xc8e4, 0x1ed, 0xaa14, 0x1ed, 0xaa2b, 
        0xc8fb, 0x1ed, 0xaa2b, 0x1ed, 0xaa4c, 0xc91e, 0x1ed, 0x1ed, 0x1ed, 0x257, 
        0xc91e, 0x1ed, 0xaa52, 0x1ed, 0xaadd, 0xc91e, 0x1ed, 0xab08, 0x1ed, 0xab71, 
        0xc9ad, 0x1ed, 0xaadd, 0x1ed, 0xab05, 0xca53, 0x1ed, 0x115, 0x1ed, 0x126, 
        0xca53, 0x1ed, 0xab83, 0x1ed, 0xab8f, 0xca60, 0xca6, 0x0, 0xca6, 0x2b, 
        0xca61, 0xca6, 0x1, 0xca6, 0x2b, 0xca8b, 0xca6, 0x2b, 0xca6, 0x47, 
        0xca8b, 0xca6, 0x71, 0xca6, 0x72, 0xcaa7, 0xca6, 0x47, 0xca6, 0x71, 
        0xcbd9, 0xca6, 0x179, 0xca6, 0x1ae, 0xcc0e, 0xca6, 0x1ae, 0xca6, 0x1af, 
        0xcc0f, 0xca6, 0x1af, 0xca6, 0x1b0, 0xcc10, 0xca6, 0x1b0, 0xca6, 0x1b1, 
        0xcc41, 0xca6, 0x1e1, 0xca6, 0x1fe, 0xcc5f, 0xca6, 0x1ff, 0xca6, 0x21b, 
        0xcc7b, 0xca6, 0x21b, 0xca6, 0x232, 0xcc92, 0xca6, 0x232, 0xca6, 0x2b1, 
        0xcd11, 0xca6, 0x2b1, 0xca6, 0x2ce, 0xcd2e, 0xca6, 0x2ce, 0xca6, 0x346, 
        0xcd2e, 0xca6, 0x34b, 0xca6, 0x351, 0xcdb1, 0xca6, 0x351, 0xca6, 0x384, 
        0xce87, 0xca6, 0x427, 0xca6, 0x52d, 0xcf8d, 0xca6, 0x52d, 0xca6, 0x5b6, 
        0xd016, 0xca6, 0x5b6, 0xca6, 0x5cd, 0xd02e, 0xca6, 0x5ce, 0xca6, 0x5cf, 
        0xd02f, 0xca6, 0x5cf, 0xca6, 0x604, 0xd065, 0xca6, 0x605, 0xca6, 0x606, 
        0xd066, 0xca6, 0x606, 0xca6, 0x620, 0xd080, 0xca6, 0x620, 0xca6, 0x64b, 
        0xd0ab, 0xca6, 0x64b, 0xca6, 0x64c, 0xd0ac, 0xca6, 0x64c, 0xca6, 0x64d, 
        0xd0ad, 0xca6, 0x64d, 0xca6, 0x65e, 0xd0bf, 0xca6, 0x65f, 0xca6, 0x660, 
        0xd0c1, 0xca6, 0x661, 0xca6, 0x662, 0xd0c2, 0xca6, 0x662, 0xca6, 0x677, 
        0xd0d7, 0xca6, 0x677, 0xca6, 0x6bd, 0xd11d, 0xca6, 0x6bd, 0xca6, 0x6be, 
        0xd11e, 0xca6, 0x6be, 0xca6, 0x6bf, 0xd11f, 0xca6, 0x6bf, 0xca6, 0x6c0, 
        0xd121, 0xca6, 0x6c1, 0xca6, 0x6de, 0xd250, 0xca6, 0x7f0, 0xca6, 0x823, 
        0xd283, 0xca6, 0x823, 0xca6, 0x858, 0xd283, 0xca6, 0x891, 0xca6, 0x892, 
        0xd2b8, 0xca6, 0x858, 0xca6, 0x891, 0xd2f2, 0xca6, 0x892, 0xca6, 0x91e, 
        0xd37e, 0xca6, 0x91e, 0xca6, 0x91f, 0xd37f, 0xca6, 0x91f, 0xca6, 0x927, 
        0xd37f, 0xca6, 0x935, 0xca6, 0x947, 0xd37f, 0xca6, 0x98f, 0xca6, 0x990, 
        0xd387, 0xca6, 0x927, 0xca6, 0x92f, 0xd387, 0xca6, 0x935, 0xca6, 0x947, 
        0xd387, 0xca6, 0x98f, 0xca6, 0x990, 0xd38f, 0xca6, 0x92f, 0xca6, 0x947, 
        0xd38f, 0xca6, 0x98f, 0xca6, 0x990, 0xd3a7, 0xca6, 0x947, 0xca6, 0x98f, 
        0xd3f0, 0xca6, 0x990, 0xca6, 0x991, 0xd3f1, 0xca6, 0x991, 0xca6, 0x992, 
        0xd3f7, 0xca6, 0x997, 0xca6, 0x998, 0xd3f8, 0xca6, 0x998, 0xca6, 0x999, 
        0xd3f9, 0xca6, 0x999, 0xca6, 0x99a, 0xd4d3, 0xca6, 0xa73, 0xca6, 0xa9c, 
        0xd500, 0xca6, 0xaa0, 0xca6, 0xad0, 0xd530, 0xca6, 0xad0, 0xca6, 0xb33, 
        0xd593, 0xca6, 0xb33, 0xca6, 0xb3c, 0xd593, 0xca6, 0xb43, 0xca6, 0xb80, 
        0xd593, 0xca6, 0xb83, 0xca6, 0xbfd, 0xd59c, 0xca6, 0xb3c, 0xca6, 0xb80, 
        0xd59c, 0xca6, 0xb83, 0xca6, 0xbfd, 0xd65d, 0xca6, 0xbfd, 0xca6, 0xc05, 
        0xd65d, 0xca6, 0xc13, 0xca6, 0xc3e, 0xd65d, 0xca6, 0xc7e, 0xca6, 0xc7f, 
        0xd665, 0xca6, 0xc05, 0xca6, 0xc0d, 0xd665, 0xca6, 0xc13, 0xca6, 0xc3e, 
        0xd665, 0xca6, 0xc7e, 0xca6, 0xc7f, 0xd66d, 0xca6, 0xc0d, 0xca6, 0xc3e, 
        0xd66d, 0xca6, 0xc7e, 0xca6, 0xc7f, 0xd69e, 0xca6, 0xc3e, 0xca6, 0xc7e, 
        0xd6df, 0xca6, 0xc7f, 0xca6, 0xc80, 0xd6e0, 0xca6, 0xc80, 0xca6, 0xc81, 
        0xd6e6, 0xca6, 0xc86, 0xca6, 0xc87, 0xd6e7, 0xca6, 0xc87, 0xca6, 0xc88, 
        0xd6e8, 0xca6, 0xc88, 0xca6, 0xc89, 0xd7d7, 0xca6, 0xd77, 0xca6, 0xda8, 
        0xd810, 0xca6, 0xdb0, 0xca6, 0xde0, 0xd840, 0xca6, 0xde0, 0xca6, 0xe09, 
        0xd840, 0xca6, 0xe3b, 0xca6, 0xe3c, 0xd869, 0xca6, 0xe09, 0xca6, 0xe3b, 
        0xd996, 0xca6, 0xf36, 0xca6, 0xf37, 0xd99c, 0xca6, 0xf3c, 0xca6, 0xf3d, 
        0xd99d, 0xca6, 0xf3d, 0xca6, 0xf3e, 0xd99e, 0xca6, 0xf3e, 0xca6, 0xf3f, 
        0xda88, 0xca6, 0x1028, 0xca6, 0x1058, 0xdac0, 0xca6, 0x1060, 0xca6, 0x1087, 
        0xdae7, 0xca6, 0x1087, 0xca6, 0x10b8, 0xdb18, 0xca6, 0x10b8, 0xca6, 0x1156, 
        0xdbb6, 0xca6, 0x1156, 0xca6, 0x1157, 0xdbb7, 0xca6, 0x1157, 0xca6, 0x115f, 
        0xdbb7, 0xca6, 0x116d, 0xca6, 0x1196, 0xdbb7, 0xca6, 0x11d4, 0xca6, 0x11d5, 
        0xdbbf, 0xca6, 0x115f, 0xca6, 0x1167, 0xdbbf, 0xca6, 0x116d, 0xca6, 0x1196, 
        0xdbbf, 0xca6, 0x11d4, 0xca6, 0x11d5, 0xdbc7, 0xca6, 0x1167, 0xca6, 0x1196, 
        0xdbc7, 0xca6, 0x11d4, 0xca6, 0x11d5, 0xdbf6, 0xca6, 0x1196, 0xca6, 0x11d3, 
        0xdc35, 0xca6, 0x11d5, 0xca6, 0x11d6, 0xdc36, 0xca6, 0x11d6, 0xca6, 0x11d7, 
        0xdc3c, 0xca6, 0x11dc, 0xca6, 0x11dd, 0xdc3d, 0xca6, 0x11dd, 0xca6, 0x11de, 
        0xdc3e, 0xca6, 0x11de, 0xca6, 0x11df, 0xdcce, 0xca6, 0x126e, 0xca6, 0x12a7, 
        0xdd71, 0xca6, 0x1311, 0xca6, 0x132b, 0xdd8b, 0xca6, 0x132b, 0xca6, 0x1355, 
        0xdddb, 0xca6, 0x137b, 0xca6, 0x13bc, 0xde1c, 0xca6, 0x13bc, 0xca6, 0x13ec, 
        0xde4c, 0xca6, 0x13ec, 0xca6, 0x1409, 0xde69, 0xca6, 0x1409, 0xca6, 0x1422, 
        0xde82, 0xca6, 0x1422, 0xca6, 0x1441, 0xdea1, 0xca6, 0x1441, 0xca6, 0x1458, 
        0xdeb8, 0xca6, 0x1458, 0xca6, 0x146b, 0xdeee, 0xca6, 0x148e, 0xca6, 0x14d3, 
        0xdf33, 0xca6, 0x14d3, 0xca6, 0x14ee, 0xdf4e, 0xca6, 0x14ee, 0xca6, 0x14ef, 
        0xdf4f, 0xca6, 0x14ef, 0xca6, 0x14ff, 0xdf4f, 0xca6, 0x152d, 0xca6, 0x152e, 
        0xdf5f, 0xca6, 0x14ff, 0xca6, 0x152e, 0xdf8e, 0xca6, 0x152e, 0xca6, 0x152f, 
        0xdf8f, 0xca6, 0x152f, 0xca6, 0x1530, 0xdf90, 0xca6, 0x1530, 0xca6, 0x155f, 
        0xdfbf, 0xca6, 0x155f, 0xca6, 0x158e, 0xdfee, 0xca6, 0x158e, 0xca6, 0x15bd, 
        0xe01d, 0xca6, 0x15bd, 0xca6, 0x1606, 0xe066, 0xca6, 0x1606, 0xca6, 0x1607, 
        0xe067, 0xca6, 0x1607, 0xca6, 0x16e1, 0xe141, 0xca6, 0x16e1, 0xca6, 0x16e2, 
        0xe142, 0xca6, 0x16e2, 0xca6, 0x16e3, 0xe150, 0xe15, 0x0, 0xe15, 0x7e, 
        0xe1ce, 0xe15, 0x7e, 0xe15, 0x193, 0xe2e3, 0xe15, 0x193, 0xe15, 0x194, 
        0xe2e4, 0xe15, 0x194, 0xe15, 0x4b0, 0xe600, 0xe15, 0x4ae, 0xe15, 0x4af, 
        0xe600, 0xe15, 0x4b0, 0xe15, 0xa09, 0xeb59, 0xe15, 0xa09, 0xe15, 0xad0, 
        0xec20, 0xec2, 0x0, 0xec2, 0x32, 0xec52, 0xec2, 0x32, 0xec2, 0x43, 
        0xec70, 0xec7, 0x0, 0xec7, 0x45, 0xecb5, 0xec7, 0x45, 0xec7, 0x89, 
        0xecf9, 0xec7, 0x89, 0xec7, 0xa9, 0xed20, 0xed2, 0x0, 0xed2, 0x1f, 
        0xed3f, 0xed2, 0x1f, 0xed2, 0x6e, 0xedfa, 0xed9, 0x6a, 0xed9, 0xaa, 
        0xefb8, 0xed9, 0x228, 0xed9, 0x262, 0xeff2, 0xed9, 0x262, 0xed9, 0x26d, 
        0xeffd, 0xed9, 0x26d, 0xed9, 0x281, 0xf011, 0xed9, 0x281, 0xed9, 0x297, 
        0xf011, 0xed9, 0x298, 0xed9, 0x29a, 0xf011, 0xed9, 0x29b, 0xed9, 0x315, 
        0xf0dc, 0xed9, 0x34c, 0xed9, 0x426, 0xf1b6, 0xed9, 0x426, 0xed9, 0x48e, 
        0xf21e, 0xed9, 0x48e, 0xed9, 0x522, 0xf9b4, 0xed9, 0xc24, 0xed9, 0xc33, 
        0xf9c4, 0xed9, 0xc34, 0xed9, 0xc77, 0xfa07, 0xed9, 0xc77, 0xed9, 0xded, 
        0xfb7f, 0xed9, 0xdef, 0xed9, 0xe29, 0xfbb9, 0xed9, 0xe29, 0xed9, 0xe34, 
        0xfbc4, 0xed9, 0xe34, 0xed9, 0xe48, 0xfbd8, 0xed9, 0xe48, 0xed9, 0xf01, 
        0xfce0, 0xed9, 0xf50, 0xed9, 0x103d, 0xfdcd, 0xed9, 0x103d, 0xed9, 0x107a, 
        0xfdcd, 0xed9, 0x10a6, 0xed9, 0x10e1, 0xfe71, 0xed9, 0xc24, 0xed9, 0xc33, 
        0xfe71, 0xed9, 0x10e1, 0xed9, 0x11d5, 0xfe71, 0xed9, 0x1f46, 0xed9, 0x2142, 
        0xfe71, 0xed9, 0x25e4, 0xed9, 0x25e6, 0x113fa, 0xed9, 0x266a, 0xed9, 0x27f2, 
        0x11582, 0xed9, 0x27f2, 0xed9, 0x283d, 0x115cd, 0xed9, 0x283d, 0xed9, 0x286b, 
        0x115fb, 0xed9, 0x286b, 0xed9, 0x2876, 0x11606, 0xed9, 0x2876, 0xed9, 0x288a, 
        0x1161a, 0xed9, 0x288a, 0xed9, 0x292f, 0x11705, 0xed9, 0x2975, 0xed9, 0x2a59, 
        0x117e9, 0xed9, 0x2a59, 0xed9, 0x2a8a, 0x117e9, 0xed9, 0x2ab6, 0xed9, 0x2af0, 
        0x11880, 0xed9, 0x2af0, 0xed9, 0x2b5e, 0x11880, 0xed9, 0x2bdf, 0xed9, 0x2be1, 
        0x11a78, 0xed9, 0x2ce8, 0xed9, 0x2ce9, 0x11a79, 0xed9, 0x2ce9, 0xed9, 0x2cea, 
        0x11a7b, 0xed9, 0x2ceb, 0xed9, 0x2cec, 0x11a7c, 0xed9, 0x2cec, 0xed9, 0x2ced, 
        0x11a7d, 0xed9, 0x2ced, 0xed9, 0x2d09, 0x11aa5, 0xed9, 0x2d15, 0xed9, 0x2d37, 
        0x11afd, 0xed9, 0x2d6d, 0xed9, 0x2d9c, 0x11b38, 0xed9, 0x2da8, 0xed9, 0x2dc6, 
        0x11b62, 0xed9, 0x2dd2, 0xed9, 0x2ded, 0x11b7d, 0xed9, 0x2ded, 0xed9, 0x306b, 
        0x11ec7, 0xed9, 0x3137, 0xed9, 0x31b7, 0x11f47, 0xed9, 0x31b7, 0xed9, 0x320e, 
        0x12190, 0x1219, 0x0, 0x1219, 0x8e, 0x12190, 0x1219, 0x93, 0x1219, 0x99, 
        0x12230, 0x1223, 0x0, 0x1223, 0x15, 0x12245, 0x1223, 0x15, 0x1223, 0x23, 
        0x12253, 0x1223, 0x23, 0x1223, 0x24, 0x12254, 0x1223, 0x24, 0x1223, 0x25, 
    };

    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs < map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
