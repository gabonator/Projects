#include "cico16.h"

void fixReloc(uint16_t seg);
void sub_1ed0();

void start()
{
    headerSize = 0x0060;
    loadAddress = 0x01ed;
    endAddress = 0x1a6d;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1fb7;
    sp = 0x0080;
    load("", "KEEN1.EXE", 100068);
    fixReloc(cs);
    sub_1ed0();
}


void sub_1ed0();
void sub_1fdf();
void sub_1ffe();
void sub_202c();
void sub_2035();
void sub_2078();
void sub_20a5();
void sub_20e8();
void sub_2109();
void sub_2159();
void sub_2195();
void sub_253b();
void sub_26fb();
void sub_2853();
void sub_2b21();
void sub_2c22();
void sub_2c80();
void sub_2d0a();
void sub_30c0();
void sub_3131();
void sub_319f();
void sub_34bb();
void sub_3647();
void sub_36a5();
void sub_3713();
void sub_3750();
void sub_37b3();
void sub_37f0();
void sub_381f();
void sub_38a3();
void sub_43c4();
void sub_46c8();
void sub_4805();
void sub_484e();
void sub_488d();
void sub_490b();
void sub_49b9();
void sub_4a6a();
void sub_4aaf();
void sub_4afa();
void sub_4b3d();
void sub_4b67();
void sub_5166();
void sub_5235();
void sub_52e8();
void sub_5462();
void sub_5482();
void sub_54a2();
void sub_5737();
void sub_5a5b();
void sub_5b69();
void sub_5ce2();
void sub_5d98();
void sub_5f24();
void sub_60c8();
void sub_6130();
void sub_617c();
void sub_61ba();
void sub_658a();
void sub_6a39();
void sub_6e79();
void sub_70ca();
void sub_7290();
void sub_7473();
void sub_75ab();
void sub_76e1();
void sub_777f();
void sub_7909();
void sub_7b0a();
void sub_7b28();
void sub_7b88();
void sub_7c33();
void sub_7cb4();
void sub_7dee();
void sub_7f1e();
void sub_7f5c();
void sub_7f8e();
void sub_7fea();
void sub_801b();
void sub_8138();
void sub_81a2();
void sub_81fa();
void sub_823b();
void sub_8346();
void sub_8487();
void sub_852d();
void sub_8679();
void sub_8754();
void sub_8900();
void sub_8a32();
void sub_8aa4();
void sub_8b19();
void sub_8b5d();
void sub_8bb6();
void sub_9751();
void sub_97e3();
void sub_9ad4();
void sub_9f2e();
void sub_a002();
void sub_a020();
void sub_a05c();
void sub_a7e9();
void sub_a9af();
void sub_adf6();
void sub_ae60();
void sub_aec0();
void sub_b15f();
void sub_b4cd();
void sub_b580();
void sub_b5b2();
void sub_b602();
void sub_b67b();
void sub_b6a3();
void sub_b6c0();
void sub_b71c();
void sub_b73c();
void sub_b8f4();
void sub_b929();
void sub_b984();
void sub_bb1e();
void sub_bc43();
void sub_bc84();
void sub_bd02();
void sub_bd3d();
void sub_be82();
void sub_c0a4();
void sub_c0bb();
void sub_c132();
void sub_c20b();
void sub_c367();
void sub_c436();
void sub_c48c();
void sub_c4e6();
void sub_c965();
void sub_ccec();
void sub_d055();
void sub_d113();
void sub_d234();
void sub_d3af();
void sub_d510();
void sub_d606();
void sub_d620();
void sub_d74c();
void sub_d7b0();
void sub_d809();
void sub_d986();
void sub_d9fd();
void sub_db0b();
void sub_db24();
void sub_db3f();
void sub_db65();
void sub_dc65();
void sub_dc80();
void sub_dc9e();
void sub_dcea();
void sub_dd35();
void sub_dd87();
void sub_ddc3();
void sub_ddfa();
void sub_de14();
void sub_de33();
void sub_de4f();
void sub_de67();
void sub_dee3();
void sub_df2c();
void sub_df7c();
void sub_df9e();
void sub_dfb2();
void sub_dfd4();
void sub_e039();
void sub_e07f();
void sub_e167();
void sub_e1a5();
void sub_e22f();
void sub_e3e3();
void sub_e422();
void sub_e47b();
void sub_e4a7();
void sub_e4ca();
void sub_e548();
void sub_e587();
void sub_e5f4();
void sub_e676();
void sub_e6ac();
void sub_e712();
void sub_e7b5();
void sub_e805();
void sub_e81c();
void sub_e836();
void sub_e94c();
void sub_ea7e();
void sub_eabd();
void sub_eb22();
void sub_ec06();
void sub_ec32();
void sub_edce();
void sub_edf0();
void sub_ee3d();
void sub_ee58();
void sub_ee76();
void sub_eea0();
void sub_eeae();
void sub_ef32();
void sub_ef52();
void sub_f02c();
void sub_f07c();
void sub_f08d();
void sub_f0c5();
void sub_f134();
void sub_f13f();
void sub_f166();
void sub_f1a3();
void sub_f1b4();
void sub_f1dd();
void sub_f25a();
void sub_f29b();
void sub_f2c0();
void sub_f2e1();
void sub_f309();
void sub_f321();
void sub_f343();
void sub_f35c();
void sub_f36e();
void sub_f49b();
void sub_f4e7();
void sub_f4f3();
void sub_f4ff();
void sub_f5b4();
void sub_f5ce();
void sub_f5ea();
void sub_f623();
void sub_f647();
void sub_f679();
void sub_f693();
void sub_f6a0();
void sub_f6a9();
void sub_fb3d();
void sub_fb9c();
void sub_fbfe();
void sub_fc6f();
void sub_fc98();
void sub_fcce();
void sub_fcf7();
void sub_fd58();
void sub_fd91();
void sub_fdb4();
void sub_ff73();
void sub_ff82();
void sub_10021();
void sub_10042();
void sub_10062();
void sub_10083();
void sub_1010b();
void sub_1016b();
void sub_1018a();
void sub_101c0();
void sub_101dd();
void sub_10217();
void sub_10250();
void sub_1026c();
void sub_1028f();
void sub_102ef();
void sub_1032f();
void sub_10358();
void sub_10433();
void sub_1044a();
void sub_10471();
void sub_10500();
void sub_10590();
void sub_105dd();
void sub_12290();


    void callIndirect(int s, int o)
    {
        stop("ind");
    }

    void indirectJump(int s, int o)
    {
        stop("ind");
    }
void sub_1ed0() // 01ed:0000
{
//    sp -= 2;
    dx = 0x14f2;
    memoryASet16(cs, 0x0235, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryAGet16(ds, 0x0002);
    bx = memoryAGet16(ds, 0x002c);
    ds = dx;
    memoryASet16(ds, 0x0090, ax);
    memoryASet16(ds, 0x008e, es);
    memoryASet16(ds, 0x008a, bx);
    memoryASet16(ds, 0x00a6, bp);
    sub_2035();
    di = memoryAGet16(ds, 0x0088); es = memoryAGet16(ds, 0x0088 + 2); /*ggg2*/;
    ax = di;
    bx = ax;
    cx = 0x7fff;
    flags.direction = 0;
loc_1f04: // 01ed:0034
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    if (cx==0)
        goto loc_1f69;
    bx++;
    if (memoryAGet(es, di) != al)
        goto loc_1f04;
    ch |= 0x80;
    cx = -cx;
    memoryASet16(ds, 0x0088, cx);
    cx = 0x0001;
    bx <<= cl;
    bx += 0x0008;
    bx &= 0xfff8;
    memoryASet16(ds, 0x008c, bx);
    dx = ds;
    bp -= dx;
    di = memoryAGet16(ds, 0x554c);
    if (di >= 0x0200)
        goto loc_1f3b;
    di = 0x0200;
    memoryASet16(ds, 0x554c, di);
loc_1f3b: // 01ed:006b
    flags.carry = (di + 0xac46) >= 0x10000;
    di += 0xac46;
    if (flags.carry)
        goto loc_1f69;
    flags.carry = (di + memoryAGet16(ds, 0x5544)) >= 0x10000;
    di += memoryAGet16(ds, 0x5544);
    if (flags.carry)
        goto loc_1f69;
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp < di)
        goto loc_1f69;
    if (memoryAGet16(ds, 0x554c) == 0x0000)
        goto loc_1f5e;
    if (memoryAGet16(ds, 0x5544) != 0x0000)
        goto loc_1f6c;
loc_1f5e: // 01ed:008e
    di = 0x1000;
    if (bp > di)
        goto loc_1f6c;
    di = bp;
    goto loc_1f6c;
loc_1f69: // 01ed:0099
    goto loc_20f0;
loc_1f6c: // 01ed:009c
    bx = di;
    bx += dx;
    memoryASet16(ds, 0x009e, bx);
    memoryASet16(ds, 0x00a2, bx);
    ax = memoryAGet16(ds, 0x008e);
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
    flags.interrupts = 1;
    ax = 0;
    es = memoryAGet16(cs, 0x0235);
    di = 0x563e;
    cx = 0xac46;
    cx -= di;
    flags.direction = 0;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ah = 0x00;
    interrupt(0x1a);
    memoryASet16(ds, 0x0094, dx);
    memoryASet16(ds, 0x0096, cx);
    bp = 0;
    ax = 0x14f0;
    ds = ax;
    si = 0x0000;
    di = 0x0012;
    sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    push(memoryAGet16(ds, 0x0086));
    push(memoryAGet16(ds, 0x0084));
    push(memoryAGet16(ds, 0x0082));
    sub_319f();
    memoryASet(cs, 0x01e7, 0x72);
    memoryASet(cs, 0x01d6, 0x00);
    push(ax);
    sub_e4a7();
    ax = 0x14f1;
    ds = ax;
    si = 0x0002;
    di = 0x0002;
    sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    callIndirect(cs, memoryAGet16(ds, 0x53d0)); // 01ed:0122;
    callIndirect(cs, memoryAGet16(ds, 0x53d2)); // 01ed:0126;
    callIndirect(cs, memoryAGet16(ds, 0x53d4)); // 01ed:012a;
    ds = memoryAGet16(cs, 0x0235);
    sub_2078();
    ax = 0;
    si = ax;
    cx = 0x002d;
loc_200d: // 01ed:013d
    flags.carry = (al + memoryAGet(ds, si)) >= 0x100;
    al += memoryAGet(ds, si);
    ah += 0x00 + flags.carry;
    si++;
    if (--cx)
        goto loc_200d;
    ax -= 0x0ca5;
    if (!ax)
        goto loc_2023;
    cx = 0x0019;
    dx = 0x002d;
    sub_20e8();
loc_2023: // 01ed:0153
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
  // gap 196 bytes
loc_20f0: // 01ed:0220
    cx = 0x001e;
    dx = 0x0054;
    ds = memoryAGet16(cs, 0x0235);
    sub_20e8();
    ax = 0x0003;
    push(ax);
    sub_1ffe();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    memoryASet16(ds, bx + si, memoryAGet16(ds, bx + si) + ax);
    push(bp);
    bp = sp;
    assert(0); ax = 0; // write to cs! 0x14f2
    memoryASet16(ds, 0x6ed8, ax);
    memoryASet16(ds, 0x6ecc, ax);
    memoryASet16(ds, 0x6ebe, ax);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
loc_212f: // 01ed:025f
    ax = memoryAGet16(ds, 0x5135);
    ax -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, ax);
    if (ax < 0x0006)
        goto loc_212f;
    if (ax <= 0x000f)
        goto loc_2149;
    memoryASet16(ds, 0x5b14, 0x000f);
loc_2149: // 01ed:0279
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
    bp = pop();
    stop("stack_unbalanced");
//    sp += 2;
}
void sub_1fdf() // 01ed:010f
{
    sp -= 2;
    ax = 0x14f1;
    ds = ax;
    si = 0x0002;
    di = 0x0002;
    sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    callIndirect(cs, memoryAGet16(ds, 0x53d0)); // 01ed:0122;
    callIndirect(cs, memoryAGet16(ds, 0x53d2)); // 01ed:0126;
    callIndirect(cs, memoryAGet16(ds, 0x53d4)); // 01ed:012a;
    ds = memoryAGet16(cs, 0x0235);
    sub_2078();
    ax = 0;
    si = ax;
    cx = 0x002d;
loc_200d: // 01ed:013d
    flags.carry = (al + memoryAGet(ds, si)) >= 0x100;
    al += memoryAGet(ds, si);
    ah += 0x00 + flags.carry;
    si++;
    if (--cx)
        goto loc_200d;
    ax -= 0x0ca5;
    if (!ax)
        goto loc_2023;
    cx = 0x0019;
    dx = 0x002d;
    sub_20e8();
loc_2023: // 01ed:0153
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
}
void sub_1ffe() // 01ed:012e
{
    sp -= 2;
    ds = memoryAGet16(cs, 0x0235);
    sub_2078();
    ax = 0;
    si = ax;
    cx = 0x002d;
loc_200d: // 01ed:013d
    flags.carry = (al + memoryAGet(ds, si)) >= 0x100;
    al += memoryAGet(ds, si);
    ah += 0x00 + flags.carry;
    si++;
    if (--cx)
        goto loc_200d;
    ax -= 0x0ca5;
    if (!ax)
        goto loc_2023;
    cx = 0x0019;
    dx = 0x002d;
    sub_20e8();
loc_2023: // 01ed:0153
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    stop("terminating");
}
void sub_202c() // 01ed:015c
{
    sp -= 2;
    cx = 0x000e;
    dx = 0x0046;
    goto loc_20f6;
  // gap 193 bytes
loc_20f6: // 01ed:0226
    ds = memoryAGet16(cs, 0x0235);
    sub_20e8();
    ax = 0x0003;
    push(ax);
    sub_1ffe();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    memoryASet16(ds, bx + si, memoryAGet16(ds, bx + si) + ax);
    push(bp);
    bp = sp;
    assert(0); ax = 0;
    memoryASet16(ds, 0x6ed8, ax);
    memoryASet16(ds, 0x6ecc, ax);
    memoryASet16(ds, 0x6ebe, ax);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
loc_212f: // 01ed:025f
    ax = memoryAGet16(ds, 0x5135);
    ax -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, ax);
    if (ax < 0x0006)
        goto loc_212f;
    if (ax <= 0x000f)
        goto loc_2149;
    memoryASet16(ds, 0x5b14, 0x000f);
loc_2149: // 01ed:0279
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
    bp = pop();
    stop("stack_unbalanced");
    sp += 2;
}
void sub_2035() // 01ed:0165
{
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x0072, bx);
    memoryASet16(ds, 0x0074, es);
    ax = 0x3504;
    interrupt(0x21);
    memoryASet16(ds, 0x0076, bx);
    memoryASet16(ds, 0x0078, es);
    ax = 0x3505;
    interrupt(0x21);
    memoryASet16(ds, 0x007a, bx);
    memoryASet16(ds, 0x007c, es);
    ax = 0x3506;
    interrupt(0x21);
    memoryASet16(ds, 0x007e, bx);
    memoryASet16(ds, 0x0080, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x015c;
    interrupt(0x21);
    ds = pop();
}
void sub_2078() // 01ed:01a8
{
    push(ds);
    ax = 0x2500;
    dx = memoryAGet16(ds, 0x0072); ds = memoryAGet16(ds, 0x0072 + 2); /*ggg2*/;
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2504;
    dx = memoryAGet16(ds, 0x0076); ds = memoryAGet16(ds, 0x0076 + 2); /*ggg2*/;
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2505;
    dx = memoryAGet16(ds, 0x007a); ds = memoryAGet16(ds, 0x007a + 2); /*ggg2*/;
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2506;
    dx = memoryAGet16(ds, 0x007e); ds = memoryAGet16(ds, 0x007e + 2); /*ggg2*/;
    interrupt(0x21);
    ds = pop();
}
void sub_20a5() // 01ed:01d5
{
    sp -= 2;
loc_20a5: // 01ed:01d5
    ah = 0xff;
    dx = di;
    bx = si;
loc_20ab: // 01ed:01db
    if (bx == di)
        goto loc_20c3;
    if (memoryAGet(ds, bx) == 0xff)
        goto loc_20be;
    if (memoryAGet(ds, bx + 1) > ah)
        goto loc_20be;
    ah = memoryAGet(ds, bx + 1);
    dx = bx;
loc_20be: // 01ed:01ee
    bx += 0x0006;
    goto loc_20ab;
loc_20c3: // 01ed:01f3
    if (dx == di)
        goto loc_20e7;
    bx = dx;
    push(ds);
    es = pop();
    push(es);
    flags.zero = memoryAGet(ds, bx) == 0x00;
    memoryASet(ds, bx, 0xff);
    ds = memoryAGet16(cs, 0x0235);
    if (flags.zero)
        goto loc_20e0;
    push(cs); cs = memoryAGet16(es, bx + 2 + 2); callIndirect(cs, memoryAGet16(es, bx + 2)); assert(cs == 0x01ed); // 01ed:0209;
    ds = pop();
    goto loc_20a5;
loc_20e0: // 01ed:0210
    switch (memoryAGet16(es, bx + 2))
    {
        case 0xcbed: sub_eabd(); break;
        case 0xd062: sub_ef32(); break;
        case 0xe5a1: sub_10471(); break;
        default:
            stop();
    }
    ds = pop();
    goto loc_20a5;
loc_20e7: // 01ed:0217
    sp += 2;
    return;
}
void sub_20e8() // 01ed:0218
{
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_2109() // 01ed:0239
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x6ed8, ax);
    memoryASet16(ds, 0x6ecc, ax);
    memoryASet16(ds, 0x6ebe, ax);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
loc_212f: // 01ed:025f
//    sync();
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135)+1);
    ax = memoryAGet16(ds, 0x5135);
    ax -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, ax);
    if (ax < 0x0006)
        goto loc_212f;
    if (ax <= 0x000f)
        goto loc_2149;
    memoryASet16(ds, 0x5b14, 0x000f);
loc_2149: // 01ed:0279
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
    bp = pop();
    sp += 2;
}
void sub_2159() // 01ed:0289
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_d620();
    si = 0x5660;
    if (memoryAGet16(ds, 0x5652) == 0x0000)
        goto loc_218c;
    goto loc_2178;
loc_216c: // 01ed:029c
    bx = memoryAGet16(ds, si);
    bx <<= 1;
    memoryASet16(ds, bx + 23318, 0xffff);
    si++;
    si++;
loc_2178: // 01ed:02a8
    if (si < memoryAGet16(ds, 0x5db6))
        goto loc_216c;
    goto loc_2192;
loc_2180: // 01ed:02b0
    bx = memoryAGet16(ds, si);
    bx <<= 1;
    memoryASet16(ds, bx + 23992, 0xffff);
    si++;
    si++;
loc_218c: // 01ed:02bc
    if (si < memoryAGet16(ds, 0x5db6))
        goto loc_2180;
loc_2192: // 01ed:02c2
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_2195() // 01ed:02c5
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0012;
    push(si);
    push(di);
    ax = 0;
    dx = 0x0100;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_ff73();
    push(ax);
    ax = 0;
    dx = 0x0100;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6ed2));
    push(memoryAGet16(ds, 0x6ed0));
    sub_ff73();
    ax &= 0xfff0;
    dx = pop();
    dx -= ax;
    memoryASet16(ss, bp - 10, dx);
    ax = 0;
    dx = 0x0100;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    sub_ff73();
    push(ax);
    ax = 0;
    dx = 0x0100;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6ed6));
    push(memoryAGet16(ds, 0x6ed4));
    sub_ff73();
    ax &= 0xfff0;
    dx = pop();
    dx -= ax;
    memoryASet16(ss, bp - 12, dx);
    if ((short)memoryAGet16(ss, bp - 10) < (short)0xffe0)
        goto loc_220d;
    if ((short)dx < (short)0xffe0)
        goto loc_220d;
    if ((short)memoryAGet16(ss, bp - 10) > (short)0x0150)
        goto loc_220d;
    if ((short)dx <= (short)0x00c7)
        goto loc_2212;
loc_220d: // 01ed:033d
    ax = 0;
    goto loc_23cb;
loc_2212: // 01ed:0342
    ax = memoryAGet16(ss, bp + 12);
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    ax &= 0x0007;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    dx = pop();
    dx += ax;
    memoryASet16(ss, bp - 14, dx);
    ax = 0x8306;
    push(ds);
    push(ax);
    ax = memoryAGet16(ss, bp - 14);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    push(dx);
    push(ax);
    cx = 0x0020;
    sub_1016b();
    ax = memoryAGet16(ss, bp - 10);
    ax += 0x0020;
    bx = 0x0008;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax += 0xfffc;
    memoryASet16(ss, bp - 10, ax);
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 2, ax);
    if ((short)ax >= 0)
        goto loc_2276;
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_2281;
loc_2276: // 01ed:03a6
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x0015)
        goto loc_2281;
    ax = 0;
    goto loc_23cb;
loc_2281: // 01ed:03b1
    ax = memoryAGet16(ss, bp - 10);
    ax += memoryAGet16(ds, 0x8306);
    ax--;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 4, ax);
    if ((short)ax <= (short)0x0015)
        goto loc_229e;
    memoryASet16(ss, bp - 4, 0x0015);
    goto loc_22a9;
loc_229e: // 01ed:03ce
    if ((short)memoryAGet16(ss, bp - 4) >= (short)0x0000)
        goto loc_22a9;
    ax = 0;
    goto loc_23cb;
loc_22a9: // 01ed:03d9
    ax = memoryAGet16(ss, bp - 12);
    bx = 0x0010;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 6, ax);
    if ((short)ax >= 0)
        goto loc_22c0;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_22cb;
loc_22c0: // 01ed:03f0
    if ((short)memoryAGet16(ss, bp - 6) <= (short)0x000e)
        goto loc_22cb;
    ax = 0;
    goto loc_23cb;
loc_22cb: // 01ed:03fb
    ax = memoryAGet16(ss, bp - 12);
    ax += memoryAGet16(ds, 0x8308);
    ax--;
    bx = 0x0010;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 8, ax);
    if ((short)ax <= (short)0x000d)
        goto loc_22e8;
    memoryASet16(ss, bp - 8, 0x000d);
    goto loc_22f3;
loc_22e8: // 01ed:0418
    if ((short)memoryAGet16(ss, bp - 8) >= (short)0x0000)
        goto loc_22f3;
    ax = 0;
    goto loc_23cb;
loc_22f3: // 01ed:0423
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 0x0004);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 0x0020);
    di = memoryAGet16(ss, bp - 6);
    goto loc_23a2;
loc_2301: // 01ed:0431
    si = memoryAGet16(ss, bp - 2);
    goto loc_2399;
loc_2307: // 01ed:0437
    ax = di;
    ax += memoryAGet16(ds, 0x5b12);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = si;
    dx += memoryAGet16(ds, 0x5656);
    dx += ax;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 16, ax);
    bx = memoryAGet16(ss, bp - 16);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1390);
    memoryASet16(ss, bp - 18, ax);
    if ((short)ax < 0)
        goto loc_234d;
    ax = di;
    dx = 0x0015;
    imul16(dx);
    ax += si;
    bx = memoryAGet16(ds, 0x5db6);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, 0x5db6, memoryAGet16(ds, 0x5db6) + 0x0002);
    goto loc_2398;
loc_234d: // 01ed:047d
    ax = si;
    ax <<= 1;
    ax += 0x0004;
    bx = memoryAGet16(ds, 0x7fba);
    memoryASet16(ds, bx, ax);
    ax = di;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0020;
    memoryASet16(ds, bx + 2, ax);
    ax = memoryAGet16(ss, bp - 16);
    memoryASet16(ds, bx + 4, ax);
    if (memoryAGet16(ss, bp - 18) != 0xfffe)
        goto loc_238f;
    ax = memoryAGet16(ds, bx + 4);
    ax |= 0x8000;
    memoryASet16(ds, bx + 4, ax);
    ax = di;
    dx = 0x0015;
    imul16(dx);
    ax += si;
    bx = memoryAGet16(ds, 0x5db6);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, 0x5db6, memoryAGet16(ds, 0x5db6) + 0x0002);
loc_238f: // 01ed:04bf
    memoryASet16(ds, 0x6ed8, memoryAGet16(ds, 0x6ed8) + 1);
    memoryASet16(ds, 0x7fba, memoryAGet16(ds, 0x7fba) + 0x0006);
loc_2398: // 01ed:04c8
    si++;
loc_2399: // 01ed:04c9
    if ((short)si > (short)memoryAGet16(ss, bp - 4))
        goto loc_23a1;
    goto loc_2307;
loc_23a1: // 01ed:04d1
    di++;
loc_23a2: // 01ed:04d2
    if ((short)di > (short)memoryAGet16(ss, bp - 8))
        goto loc_23aa;
    goto loc_2301;
loc_23aa: // 01ed:04da
    bx = memoryAGet16(ds, 0x6ec6);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ds, bx, ax);
    ax = memoryAGet16(ss, bp - 12);
    memoryASet16(ds, bx + 2, ax);
    ax = memoryAGet16(ss, bp - 14);
    memoryASet16(ds, bx + 4, ax);
    memoryASet16(ds, 0x6ebe, memoryAGet16(ds, 0x6ebe) + 1);
    memoryASet16(ds, 0x6ec6, memoryAGet16(ds, 0x6ec6) + 0x0006);
    ax = 0x0001;
loc_23cb: // 01ed:04fb
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_253b() // 01ed:066b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0016;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x8304, ax);
    if ((short)memoryAGet16(ss, bp + 4) >= (short)0x000a)
        goto loc_2565;
    ax = 0x000a;
    push(ax);
    ax = bp - 10;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f25a();
    sp += 0x0006;
    ax = 0x1d4c;
    goto loc_2579;
loc_2565: // 01ed:0695
    ax = 0x000a;
    push(ax);
    ax = bp - 10;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f25a();
    sp += 0x0006;
    ax = 0x1d53;
loc_2579: // 01ed:06a9
    push(ax);
    ax = bp - 22;
    push(ax);
    sub_f623();
    sp += 0x0004;
    ax = bp - 10;
    push(ax);
    ax = bp - 22;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x1d59;
    push(ax);
    ax = bp - 22;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 22;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x8000;
    push(ax);
    ax = bp - 22;
    push(ax);
    sub_f36e();
    sp += 0x0004;
    di = ax;
    push(ax);
    sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, bp - 6, ax);
    push(di);
    sub_e47b();
    sp++;
    sp++;
    ax = 0xffff;
    ax -= memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ds, 0x6eca);
    bx = memoryAGet16(ds, 0x6ec8);
    bx += ax;
    memoryASet16(ss, bp - 4, bx);
    memoryASet16(ss, bp - 2, dx);
    push(dx);
    push(memoryAGet16(ss, bp - 4));
    ax = bp - 22;
    push(ax);
    sub_7b88();
    sp += 0x0006;
    push(memoryAGet16(ds, 0x6eca));
    push(memoryAGet16(ds, 0x6ec8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_9751();
    sp += 0x0008;
    si = 0;
    goto loc_262f;
loc_2609: // 01ed:0739
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 14);
    imul16(si);
    dx = memoryAGet16(ds, 0x6eca);
    bx += ax;
    bx += 0x0020;
    push(dx);
    push(bx);
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = pop();
    memoryASet16(ds, bx + 27720, ax);
    ax = pop();
    memoryASet16(ds, bx + 27722, ax);
    si++;
loc_262f: // 01ed:075f
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    if ((short)memoryAGet16(es, bx + 4) > (short)si)
        goto loc_2609;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x6c08, ax);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x6c58, ax);
    ax = memoryAGet16(ds, 0x6c08);
    ax <<= 1;
    memoryASet16(ds, 0x6c06, ax);
    ax += 0xffd6;
    memoryASet16(ds, 0x5654, ax);
    memoryASet16(ds, 0x564a, 0x2000);
    memoryASet16(ds, 0x564c, 0x0000);
    memoryASet16(ds, 0x564e, 0x2000);
    memoryASet16(ds, 0x5650, 0x0000);
    ax = memoryAGet16(es, bx);
    ax += 0xffea;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x7fbe, ax);
    memoryASet16(ds, 0x7fc0, dx);
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx);
    ax += 0xfffe;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x5642, ax);
    memoryASet16(ds, 0x5644, dx);
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x5646, ax);
    memoryASet16(ds, 0x5648, dx);
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 2);
    ax += 0xfff1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    flags.carry = (ax + 0x0800) >= 0x10000;
    ax += 0x0800;
    dx += 0x0000 + flags.carry;
    memoryASet16(ds, 0x7fc2, ax);
    memoryASet16(ds, 0x7fc4, dx);
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx);
    ax += 0xfffd;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x5dac, ax);
    memoryASet16(ds, 0x5dae, dx);
    bx = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6ec8 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 2);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x5db0, ax);
    memoryASet16(ds, 0x5db2, dx);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_26fb() // 01ed:082b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sub_7b0a();
    if (memoryAGet16(ds, 0x8304) != 0x005a)
        goto loc_273a;
    ax = 0x0001;
    push(ax);
    ax = 0x000c;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x1d5b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, al);
    if (al != 0x59)
        goto loc_2780;
    ax = 0x1d67;
    push(ax);
    sub_3131();
    sp++;
    sp++;
    goto loc_2780;
loc_273a: // 01ed:086a
    ax = 0x0002;
    push(ax);
    ax = 0x0014;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x1d68;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x1d7a;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, al);
    if (al != 0x44)
        goto loc_2773;
    ax = 0x1d83;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_2773: // 01ed:08a3
    if (memoryAGet(ds, 0xa6e2) != 0x54)
        goto loc_2780;
    memoryASet16(ds, 0x6ebc, 0x0001);
loc_2780: // 01ed:08b0
    bp = pop();
    sp += 2;
}
void sub_2853() // 01ed:0983
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    ax = memoryAGet16(ds, 0x6eca);
    dx = memoryAGet16(ds, 0x6ec8);
    dx += 0x8000;
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp + 4));
    sub_7b88();
    sp += 0x0006;
    push(memoryAGet16(ds, 0x6eca));
    push(memoryAGet16(ds, 0x6ec8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_e3e3();
    sp += 0x0008;
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 8, ax);
    ax += 0x0200;
    memoryASet16(ss, bp - 10, ax);
    ax += 0x0200;
    memoryASet16(ss, bp - 12, ax);
    ax += 0x0200;
    memoryASet16(ss, bp - 14, ax);
    di = 0;
    si = 0x0004;
    ax = 0;
    dx = 0;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    sub_2109();
    sub_2159();
    ax = 0x0005;
    push(ax);
    ax = 0x03ce;
    push(ax);
    sub_f4e7();
    sp += 0x0004;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_2995;
loc_28d8: // 01ed:0a08
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x01;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    ax = 0x0028;
    push(ax);
    push(si);
    push(memoryAGet16(ds, 0x35b4));
    push(di);
    push(memoryAGet16(ss, bp - 8));
    sub_f321();
    sp += 0x000a;
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x02;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    ax = 0x0028;
    push(ax);
    push(si);
    push(memoryAGet16(ds, 0x35b4));
    push(di);
    push(memoryAGet16(ss, bp - 10));
    sub_f321();
    sp += 0x000a;
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x04;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    ax = 0x0028;
    push(ax);
    push(si);
    push(memoryAGet16(ds, 0x35b4));
    push(di);
    push(memoryAGet16(ss, bp - 12));
    sub_f321();
    sp += 0x000a;
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x08;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    ax = 0x0028;
    push(ax);
    push(si);
    push(memoryAGet16(ds, 0x35b4));
    push(di);
    push(memoryAGet16(ss, bp - 14));
    sub_f321();
    sp += 0x000a;
    di += 0x0028;
    si += 0x0030;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_2995: // 01ed:0ac5
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x00c8)
        goto loc_299f;
    goto loc_28d8;
loc_299f: // 01ed:0acf
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x0f;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    sub_d606();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2b21() // 01ed:0c51
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    si = 0;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    ax = 0x82ea;
    if (ax)
        goto loc_2b3d;
    goto loc_2c1b;
loc_2b3d: // 01ed:0c6d
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ds, 0x50ac);
    ax &= 0x007f;
    if (ax == 0x003d)
        goto loc_2bca;
    if ((short)ax > (short)0x003d)
        goto loc_2b6c;
    if (ax != 0x0001)
        goto loc_2b5f;
    goto loc_2bf1;
loc_2b5f: // 01ed:0c8f
    if (ax == 0x003b)
        goto loc_2b79;
    if (ax == 0x003c)
        goto loc_2b85;
    goto loc_2bfa;
loc_2b6c: // 01ed:0c9c
    if (ax == 0x003e)
        goto loc_2bd6;
    if (ax == 0x003f)
        goto loc_2be8;
    goto loc_2bfa;
loc_2b79: // 01ed:0ca9
    sub_de14();
    sub_7b0a();
    sub_bc84();
    si++;
    goto loc_2bfc;
loc_2b85: // 01ed:0cb5
    sub_de14();
    sub_7b0a();
    ax = 0x0001;
    push(ax);
    ax = 0x000d;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x1d91;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, al);
    if (al != 0x4e)
        goto loc_2bba;
    memoryASet16(ds, 0x5143, 0x0000);
    goto loc_2bc7;
loc_2bba: // 01ed:0cea
    if (memoryAGet(ds, 0xa6e2) != 0x59)
        goto loc_2bc7;
    memoryASet16(ds, 0x5143, 0x0001);
loc_2bc7: // 01ed:0cf7
    si++;
    goto loc_2bfc;
loc_2bca: // 01ed:0cfa
    sub_de14();
    sub_7b0a();
    sub_7290();
    si++;
    goto loc_2bfc;
loc_2bd6: // 01ed:0d06
    sub_de14();
    sub_7b0a();
    ax = 0x0001;
    push(ax);
    sub_6e79();
    sp++;
    sp++;
    si++;
    goto loc_2bfc;
loc_2be8: // 01ed:0d18
    sub_de14();
    sub_b984();
    si++;
    goto loc_2bfc;
loc_2bf1: // 01ed:0d21
    sub_de14();
    sub_26fb();
    si++;
    goto loc_2bfc;
loc_2bfa: // 01ed:0d2a
    goto loc_2c1b;
loc_2bfc: // 01ed:0d2c
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x5135, dx);
    memoryASet16(ds, 0x5137, ax);
    if (!si)
        goto loc_2c1b;
    sub_7b0a();
    sub_de33();
    sub_d606();
    ax = 0x0001;
    goto loc_2c1d;
loc_2c1b: // 01ed:0d4b
    ax = 0;
loc_2c1d: // 01ed:0d4d
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2c22() // 01ed:0d52
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xaaca) + ax) >= 0x10000;
    memoryASet16(ds, 0xaaca, memoryAGet16(ds, 0xaaca) + ax);
    memoryASet16(ds, 0xaacc, memoryAGet16(ds, 0xaacc) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0xaacc);
    dx = memoryAGet16(ds, 0xaaca);
    flags.carry = dx < memoryAGet16(ds, 0x6ec2);
    dx -= memoryAGet16(ds, 0x6ec2);
    ax = ax - memoryAGet16(ds, 0x6ec4) - flags.carry;
    if ((short)ax < 0)
        goto loc_2c7e;
    if (ax)
        goto loc_2c4c;
    if (dx < 0x4e20)
        goto loc_2c7e;
loc_2c4c: // 01ed:0d7c
    ax = 0x001c;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0;
    dx = 0x4e20;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    sub_ff73();
    push(ax);
    push(dx);
    dx = 0;
    ax = 0x4e20;
    cx = pop();
    bx = pop();
    sub_10433();
    memoryASet16(ds, 0x6ec2, ax);
    memoryASet16(ds, 0x6ec4, dx);
    memoryASet16(ds, 0xaac6, memoryAGet16(ds, 0xaac6) + 1);
loc_2c7e: // 01ed:0dae
    bp = pop();
    sp += 2;
}
void sub_2c80() // 01ed:0db0
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    sub_7b0a();
    ax = 0x0004;
    push(ax);
    ax = 0x001a;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x1d9e;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x1db5;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x1dd1;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x1de9;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    memoryASet16(ds, 0xaa9a, 0x0001);
    memoryASet16(ds, 0xaac8, 0x0064);
    si = 0;
    goto loc_2ce4;
loc_2cd9: // 01ed:0e09
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43678, 0x0001);
    si++;
loc_2ce4: // 01ed:0e14
    if ((short)si < (short)0x0004)
        goto loc_2cd9;
    sub_8138();
    sub_d606();
    sub_2159();
    sub_2159();
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x5135, dx);
    memoryASet16(ds, 0x5137, ax);
    sub_7b0a();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_2d0a() // 01ed:0e3a
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    sub_7b0a();
    ax = 0x000d;
    push(ax);
    ax = 0x001c;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    si = memoryAGet16(ds, 0x8282);
    ax = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, bp - 2, ax);
    ax = 0x1e02;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x000c;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e20;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x1e23;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x000e;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e41;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x000e;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e44;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x000e;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e47;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x1e4a;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x0008;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e68;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    ax = 0x1e6a;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x0008;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e6d;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    ax = 0x1e6f;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x0008;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e72;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    ax = 0x1e74;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x1e77;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    ax = 0x1e81;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = si;
    ax += 0x0008;
    memoryASet16(ds, 0x8282, ax);
    ax = 0x1e84;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    ax = 0x1e86;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x1e89;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x000a;
    push(ax);
    ax = 0x8290;
    push(ax);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    sub_f29b();
    sp += 0x0008;
    ax = 0x8290;
    push(ax);
    sub_f647();
    sp++;
    sp++;
    dx = si;
    dx += 0x000a;
    dx -= ax;
    memoryASet16(ds, 0x8282, dx);
    ax = memoryAGet16(ss, bp - 2);
    ax++;
    memoryASet16(ds, 0x82f8, ax);
    ax = 0x8290;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x000a;
    push(ax);
    ax = 0x8290;
    push(ax);
    ax = memoryAGet16(ds, 0x6ec4);
    dx = memoryAGet16(ds, 0x6ec2);
    flags.carry = (dx + 0x4e20) >= 0x10000;
    dx += 0x4e20;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_f29b();
    sp += 0x0008;
    ax = 0x8290;
    push(ax);
    sub_f647();
    sp++;
    sp++;
    dx = si;
    dx += 0x001a;
    dx -= ax;
    memoryASet16(ds, 0x8282, dx);
    ax = 0x8290;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    di = 0;
    goto loc_2ecf;
loc_2eae: // 01ed:0fde
    ax = 0;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0003;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = di;
    ax <<= 1;
    dx = si;
    dx += ax;
    dx++;
    push(dx);
    sub_d9fd();
    sp += 0x0006;
    di++;
loc_2ecf: // 01ed:0fff
    if ((short)di >= (short)memoryAGet16(ds, 0xaac6))
        goto loc_2eda;
    if ((short)di < (short)0x0006)
        goto loc_2eae;
loc_2eda: // 01ed:100a
    ax = si;
    ax += 0x0010;
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0003;
    memoryASet16(ds, 0x82f8, ax);
    if (memoryAGet16(ds, 0xaa94) == 0x0000)
        goto loc_2ef7;
    ax = 0x01c0;
    goto loc_2efa;
loc_2ef7: // 01ed:1027
    ax = 0x0141;
loc_2efa: // 01ed:102a
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (memoryAGet16(ds, 0xaa9c) == 0x0000)
        goto loc_2f23;
    ax = 0x01c1;
    goto loc_2f26;
loc_2f23: // 01ed:1053
    ax = 0x0142;
loc_2f26: // 01ed:1056
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (memoryAGet16(ds, 0xaa96) == 0x0000)
        goto loc_2f4f;
    ax = 0x01c2;
    goto loc_2f52;
loc_2f4f: // 01ed:107f
    ax = 0x0143;
loc_2f52: // 01ed:1082
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (memoryAGet16(ds, 0xaa98) == 0x0000)
        goto loc_2f7b;
    ax = 0x01c3;
    goto loc_2f7e;
loc_2f7b: // 01ed:10ab
    ax = 0x0144;
loc_2f7e: // 01ed:10ae
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
    ax = si;
    ax += 0x0013;
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0007;
    memoryASet16(ds, 0x82f8, ax);
    if (memoryAGet16(ds, 0xaa9e) == 0x0000)
        goto loc_2fc9;
    ax = 0x01a8;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0003;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
loc_2fc9: // 01ed:10f9
    if (memoryAGet16(ds, 0xaaa0) == 0x0000)
        goto loc_2fee;
    ax = 0x01a9;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax += 0x0004;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_2fee: // 01ed:111e
    if (memoryAGet16(ds, 0xaaa2) == 0x0000)
        goto loc_3010;
    ax = 0x01aa;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0015;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
loc_3010: // 01ed:1140
    if (memoryAGet16(ds, 0xaaa4) == 0x0000)
        goto loc_3035;
    ax = 0x01ab;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0015;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax += 0x0004;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_3035: // 01ed:1165
    ax = 0x019e;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0007;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    ax = si;
    ax += 0x0003;
    push(ax);
    sub_d809();
    sp += 0x0006;
    ax = si;
    ax += 0x0003;
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x000b;
    memoryASet16(ds, 0x82f8, ax);
    push(memoryAGet16(ds, 0xaac8));
    sub_81fa();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0xaa9a) == 0x0000)
        goto loc_3096;
    ax = 0x019f;
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0008;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0004;
    push(ax);
    ax = si;
    ax += 0x000b;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_3096: // 01ed:11c6
    sub_7b0a();
    ax = 0;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    sub_d606();
    sub_2159();
    sub_2159();
    sub_7b0a();
    ax = memoryAGet16(ss, bp - 4);
    dx = memoryAGet16(ss, bp - 6);
    memoryASet16(ds, 0x5135, dx);
    memoryASet16(ds, 0x5137, ax);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_30c0() // 01ed:11f0
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet(ds, 0x505a) == 0x00)
        goto loc_30db;
    if (memoryAGet(ds, 0x5040) == 0x00)
        goto loc_30db;
    if (memoryAGet(ds, 0x5065) == 0x00)
        goto loc_30db;
    sub_2c80();
loc_30db: // 01ed:120b
    if (memoryAGet(ds, 0x504e) == 0x00)
        goto loc_311f;
    if (memoryAGet(ds, 0x5044) == 0x00)
        goto loc_311f;
    if (memoryAGet(ds, 0x504c) == 0x00)
        goto loc_311f;
    sub_7b0a();
    ax = 0x0001;
    push(ax);
    ax = 0x0014;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    memoryASet16(ds, 0x5daa, memoryAGet16(ds, 0x5daa) ^ 0x0001);
    if (!memoryAGet16(ds, 0x5daa))
        goto loc_310e;
    ax = 0x1ea6;
    goto loc_3111;
loc_310e: // 01ed:123e
    ax = 0x1eb7;
loc_3111: // 01ed:1241
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    sub_d606();
    goto loc_312f;
loc_311f: // 01ed:124f
    if (memoryAGet(ds, 0x5065) == 0x00)
        goto loc_312f;
    sub_de14();
    sub_2d0a();
    sub_de33();
loc_312f: // 01ed:125f
    bp = pop();
    sp += 2;
}
void sub_3131() // 01ed:1261
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    ax = 0x0003;
    interrupt(0x10);
    al = memoryAGet(ds, si);
    cbw();
    if (ax)
        goto loc_3149;
    sub_8679();
    goto loc_314f;
loc_3149: // 01ed:1279
    push(si);
    sub_ea7e();
    sp++;
    sp++;
loc_314f: // 01ed:127f
    if (memoryAGet16(ds, 0x7fbc) == 0x0000)
        goto loc_3159;
    sub_dc80();
loc_3159: // 01ed:1289
    if (memoryAGet16(ds, 0x7fc6) == 0x0000)
        goto loc_3163;
    sub_dd87();
loc_3163: // 01ed:1293
    al = memoryAGet(ds, si);
    cbw();
    if (ax)
        goto loc_3186;
    ax = 0x0fa0;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0xb800;
    push(ax);
    ax = 0x0000;
    ax += 0x0007;
    push(ax);
    ax = 0x13f5;
    push(ax);
    sub_f321();
    sp += 0x000a;
loc_3186: // 01ed:12b6
    ax = 0x0017;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_e7b5();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_e4a7();
    sp++;
    sp++;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_319f() // 01ed:12cf
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    ax = 0x1ec9;
    push(ax);
    push(memoryAGet16(ds, 0x2506));
    sub_f623();
    sp += 0x0004;
    ax = 0x1ecd;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    ax = bp - 4;
    push(ax);
    ax = bp - 2;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_76e1();
    sp += 0x0006;
    if ((short)memoryAGet16(ss, bp - 2) >= (short)0x01f4)
        goto loc_31eb;
    ax = 0x1f05;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    memoryASet16(ds, 0x5b10, 0x0001);
    goto loc_31fa;
loc_31eb: // 01ed:131b
    ax = 0x1f17;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    memoryASet16(ds, 0x5b10, 0x0000);
loc_31fa: // 01ed:132a
    memoryASet16(ds, 0x5026, 0x0001);
    if ((short)memoryAGet16(ss, bp + 4) <= (short)0x0001)
        goto loc_3227;
    bx = memoryAGet16(ds, di + 2);
    if (memoryAGet(ds, bx + 1) == 0x4b)
        goto loc_3218;
    bx = memoryAGet16(ds, di + 2);
    if (memoryAGet(ds, bx + 1) != 0x6b)
        goto loc_3227;
loc_3218: // 01ed:1348
    memoryASet16(ds, 0x5026, 0x0000);
    ax = 0x1f2d;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
loc_3227: // 01ed:1357
    sub_e039();
    memoryASet16(ds, 0x9730, ax);
    if (ax != 0x0003)
        goto loc_323b;
    ax = 0x1f53;
    push(ax);
    sub_ea7e();
    goto loc_327f;
loc_323b: // 01ed:136b
    if (memoryAGet16(ds, 0x9730) != 0x0005)
        goto loc_324b;
    ax = 0x1f65;
    push(ax);
    sub_ea7e();
    goto loc_327f;
loc_324b: // 01ed:137b
    ax = 0x1f77;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    ax = 0x1fc2;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    sub_7b0a();
    ax = 0;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    ax &= 0x00ff;
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    si = ax;
    if (ax == 0x0059)
        goto loc_3281;
    ax = 0x0001;
    push(ax);
    sub_e4a7();
loc_327f: // 01ed:13af
    sp++;
    sp++;
loc_3281: // 01ed:13b1
    ax = 0x1feb;
    push(ax);
    sub_ea7e();
    sp++;
    sp++;
    sub_8bb6();
    si = 0;
    goto loc_341e;
loc_3292: // 01ed:13c2
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 168);
    if (ax == 0x0001)
        goto loc_32af;
    if (ax == 0x0002)
        goto loc_32d8;
    if (ax != 0x0004)
        goto loc_32ac;
    goto loc_3334;
loc_32ac: // 01ed:13dc
    goto loc_341d;
loc_32af: // 01ed:13df
    ax = si;
    cl = 0x05;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    goto loc_341d;
loc_32d8: // 01ed:1408
    ax = si;
    cl = 0x05;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0020;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    si++;
    ax = si;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffe0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    goto loc_341d;
loc_3334: // 01ed:1464
    ax = si;
    cl = 0x05;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0020;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0040;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0060;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    si++;
    ax = si;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0020;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0040;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffe0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    si++;
    ax = si;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0x0020;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffc0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffe0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
    si++;
    ax = si;
    ax <<= cl;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 14876, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffa0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16276, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffc0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 17676, ax);
    ax = si;
    ax <<= cl;
    ax += 0xffe0;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 19076, ax);
loc_341d: // 01ed:154d
    si++;
loc_341e: // 01ed:154e
    if ((short)si >= (short)memoryAGet16(ds, 0x8352))
        goto loc_3427;
    goto loc_3292;
loc_3427: // 01ed:1557
    ax = 0x201e;
    push(ax);
    ax = 0x8290;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x8290;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x8290;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0x513f, ax);
    memoryASet16(ds, 0x5141, dx);
    ax = 0x0001;
    push(ax);
    sub_df7c();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_dee3();
    sp++;
    sp++;
    sub_dd35();
    memoryASet16(ds, 0x7fc6, 0x0001);
    sub_dc65();
    memoryASet16(ds, 0x7fbc, 0x0001);
    sub_852d();
    memoryASet16(ds, 0x833e, 0x0000);
    ax = 0x0001;
    dx = 0;
    push(ax);
    push(dx);
    sub_7b28();
    sp += 0x0004;
    memoryASet16(ds, 0x6ec8, ax);
    memoryASet16(ds, 0x6eca, dx);
    memoryASet16(ds, 0x24ce, 0x0017);
    memoryASet16(ds, 0x6c62, 0x0007);
    ax = 0;
    dx = 0;
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
    memoryASet16(ds, 0x5135, dx);
    memoryASet16(ds, 0x5137, ax);
    sub_97e3();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_34bb() // 01ed:15eb
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    push(memoryAGet16(ss, bp + 4));
    sub_253b();
    sp++;
    sp++;
    di = 0;
    goto loc_35ca;
loc_34cf: // 01ed:15ff
    si = 0;
    goto loc_35c0;
loc_34d4: // 01ed:1604
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 2);
    if (bx == 0x0006)
        goto loc_355a;
    if ((short)bx > (short)0x0006)
        goto loc_3504;
    bx--;
    if (bx <= 0x0004)
        goto loc_34fd;
    goto loc_35bf;
loc_34fd: // 01ed:162d
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_3526;
        case 2: goto loc_3531;
        case 4: goto loc_353c;
        case 6: goto loc_3546;
        default:
            stop();
    }
loc_3504: // 01ed:1634
    if (bx == 0x0009)
        goto loc_3583;
    if ((short)bx > (short)0x0009)
        goto loc_3518;
    if (bx == 0x0007)
        goto loc_3567;
    if (bx == 0x0008)
        goto loc_3575;
    goto loc_35bf;
loc_3518: // 01ed:1648
    if (bx == 0x000a)
        goto loc_3591;
    if (bx == 0x00ff)
        goto loc_359b;
    goto loc_35bf;
loc_3526: // 01ed:1656
    push(di);
    push(si);
    sub_3750();
    sp += 0x0004;
    goto loc_35bf;
loc_3531: // 01ed:1661
    push(di);
    push(si);
    sub_3713();
    sp += 0x0004;
    goto loc_35bf;
loc_353c: // 01ed:166c
    push(di);
    push(si);
    sub_36a5();
    sp += 0x0004;
    goto loc_35bf;
loc_3546: // 01ed:1676
    push(di);
    push(si);
    sub_3647();
    sp += 0x0004;
    goto loc_35bf;
  // gap 10 bytes
loc_355a: // 01ed:168a
    ax = 0;
    push(ax);
    push(di);
    push(si);
    sub_37f0();
    sp += 0x0006;
    goto loc_35bf;
loc_3567: // 01ed:1697
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    sub_37f0();
    sp += 0x0006;
    goto loc_35bf;
loc_3575: // 01ed:16a5
    ax = 0x0002;
    push(ax);
    push(di);
    push(si);
    sub_37f0();
    sp += 0x0006;
    goto loc_35bf;
loc_3583: // 01ed:16b3
    ax = 0x0003;
    push(ax);
    push(di);
    push(si);
    sub_37f0();
    sp += 0x0006;
    goto loc_35bf;
loc_3591: // 01ed:16c1
    push(di);
    push(si);
    sub_37b3();
    sp += 0x0004;
    goto loc_35bf;
loc_359b: // 01ed:16cb
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, 0x6ede, ax);
    memoryASet16(ds, 0x6ee0, dx);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    flags.carry = (ax + 0x0800) >= 0x10000;
    ax += 0x0800;
    dx += 0x0000 + flags.carry;
    memoryASet16(ds, 0x6ee2, ax);
    memoryASet16(ds, 0x6ee4, dx);
loc_35bf: // 01ed:16ef
    si++;
loc_35c0: // 01ed:16f0
    if ((short)si >= (short)memoryAGet16(ds, 0x6c08))
        goto loc_35c9;
    goto loc_34d4;
loc_35c9: // 01ed:16f9
    di++;
loc_35ca: // 01ed:16fa
    if ((short)di >= (short)memoryAGet16(ds, 0x6c58))
        goto loc_35d3;
    goto loc_34cf;
loc_35d3: // 01ed:1703
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_3647() // 01ed:1777
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x0005);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, dx);
    memoryASet16(ds, si + 32, 0x005a);
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    if ((short)ax > (short)memoryAGet16(ds, 0x6ee0))
        goto loc_3693;
    if ((short)ax < (short)memoryAGet16(ds, 0x6ee0))
        goto loc_368b;
    if (dx >= memoryAGet16(ds, 0x6ede))
        goto loc_3693;
loc_368b: // 01ed:17bb
    ax = memoryAGet16(ds, si + 32);
    ax = -ax;
    memoryASet16(ds, si + 32, ax);
loc_3693: // 01ed:17c3
    memoryASet16(ds, si + 50, 0x1dc7);
    memoryASet16(ds, si + 52, 0x1e94);
    memoryASet16(ds, si + 40, 0x0060);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_36a5() // 01ed:17d5
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x0004);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, dx);
    memoryASet16(ds, si + 50, 0x1c0e);
    memoryASet16(ds, si + 52, 0x1d6e);
    memoryASet16(ds, si + 36, 0x0003);
    if (memoryAGet16(ds, 0x8304) != 0x0010)
        goto loc_36eb;
    memoryASet16(ds, si + 36, 0x0068);
loc_36eb: // 01ed:181b
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    if ((short)ax < (short)memoryAGet16(ds, 0x6ee0))
        goto loc_3706;
    if ((short)ax > (short)memoryAGet16(ds, 0x6ee0))
        goto loc_36ff;
    if (dx <= memoryAGet16(ds, 0x6ede))
        goto loc_3706;
loc_36ff: // 01ed:182f
    memoryASet16(ds, si + 32, 0xffa6);
    goto loc_370b;
loc_3706: // 01ed:1836
    memoryASet16(ds, si + 32, 0x005a);
loc_370b: // 01ed:183b
    memoryASet16(ds, si + 40, 0x004e);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_3713() // 01ed:1843
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x0003);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, dx);
    memoryASet16(ds, si + 50, 0x1b51);
    memoryASet16(ds, si + 52, 0x1bce);
    memoryASet16(ds, si + 40, 0x003c);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_3750() // 01ed:1880
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x0002);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    flags.carry = (ax + 0x0800) >= 0x10000;
    ax += 0x0800;
    dx += 0x0000 + flags.carry;
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, dx);
    memoryASet16(ds, si + 50, 0x194f);
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    if ((short)ax > (short)memoryAGet16(ds, 0x6ee0))
        goto loc_37a1;
    if ((short)ax < (short)memoryAGet16(ds, 0x6ee0))
        goto loc_379a;
    if (dx >= memoryAGet16(ds, 0x6ede))
        goto loc_37a1;
loc_379a: // 01ed:18ca
    memoryASet16(ds, si + 32, 0x003c);
    goto loc_37a6;
loc_37a1: // 01ed:18d1
    memoryASet16(ds, si + 32, 0xffc4);
loc_37a6: // 01ed:18d6
    memoryASet16(ds, si + 52, 0x1a68);
    memoryASet16(ds, si + 40, 0x0030);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_37b3() // 01ed:18e3
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x0008);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, dx);
    memoryASet16(ds, si + 50, 0x3360);
    memoryASet16(ds, si + 52, 0x22bb);
    memoryASet16(ds, si + 40, 0x0072);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_37f0() // 01ed:1920
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_484e();
    si = ax;
    memoryASet16(ds, si + 8, 0x0003);
    memoryASet16(ds, si + 34, 0x204a);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, si + 10, ax);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, si, ax);
    memoryASet16(ds, si + 2, dx);
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_381f() // 01ed:194f
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x8242) != 0x0000)
        goto loc_3858;
    sub_df9e();
    if (ax >= memoryAGet16(ds, 0x5b14))
        goto loc_3843;
    ax = 0x0080;
    push(ax);
    sub_df2c();
    sp++;
    sp++;
    ax = -ax;
    memoryASet16(ds, 0x8242, ax);
    goto loc_3858;
loc_3843: // 01ed:1973
    sub_df9e();
    if (ax >= memoryAGet16(ds, 0x5b14))
        goto loc_3858;
    memoryASet16(ds, 0x8252, 0x19d3);
    memoryASet16(ds, 0x824a, 0x0000);
loc_3858: // 01ed:1988
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_3867;
    memoryASet16(ds, 0x8248, 0x0034);
    goto loc_386d;
loc_3867: // 01ed:1997
    memoryASet16(ds, 0x8248, 0x0036);
loc_386d: // 01ed:199d
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    ax &= 0x0001;
    dx = memoryAGet16(ds, 0x8248);
    dx += ax;
    memoryASet16(ds, 0x8248, dx);
    sub_4afa();
    sub_4b3d();
    si = ax;
    if (!(ax & 0x0004))
        goto loc_3894;
    memoryASet16(ds, 0x8240, 0xffc4);
loc_3894: // 01ed:19c4
    if (!(si & 0x0001))
        goto loc_38a0;
    memoryASet16(ds, 0x8240, 0x003c);
loc_38a0: // 01ed:19d0
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_38a3() // 01ed:19d3
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x8240, 0x0000);
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x05;
    ax >>= cl;
    ax &= 0x0003;
    ax += 0x0030;
    memoryASet16(ds, 0x8248, ax);
    ax = memoryAGet16(ds, 0x824a);
    ax += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, ax);
    if ((short)ax < (short)0x00c8)
        goto loc_38f4;
    ax = memoryAGet16(ds, 0x8226);
    dx = memoryAGet16(ds, 0x8224);
    if ((short)ax > (short)memoryAGet16(ds, 0x6ee0))
        goto loc_38e8;
    if ((short)ax < (short)memoryAGet16(ds, 0x6ee0))
        goto loc_38e0;
    if (dx >= memoryAGet16(ds, 0x6ede))
        goto loc_38e8;
loc_38e0: // 01ed:1a10
    memoryASet16(ds, 0x8240, 0x003c);
    goto loc_38ee;
loc_38e8: // 01ed:1a18
    memoryASet16(ds, 0x8240, 0xffc4);
loc_38ee: // 01ed:1a1e
    memoryASet16(ds, 0x8252, 0x194f);
loc_38f4: // 01ed:1a24
    sub_4afa();
    sub_4b3d();
    bp = pop();
    sp += 2;
}
void sub_43c4() // 01ed:24f4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0015;
    push(ax);
    sub_7f1e();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x8304);
    bx--;
    bx--;
    if (bx <= 0x000d)
        goto loc_43f3;
    goto loc_457b;
loc_43f3: // 01ed:2523
    bx <<= 1;
    indirectJump(cs, memoryAGet16(cs, bx + 9954)); // 01ed:2525;
  // gap 385 bytes
loc_457b: // 01ed:26ab
    ax = memoryAGet16(ds, 0x24d0);
    ax += 0x0005;
    memoryASet16(ds, 0x82f8, ax);
    ax = 0x240f;
    push(ax);
    sub_8346();
    sp++;
    sp++;
    sub_7b0a();
loc_4590: // 01ed:26c0
    sub_8138();
    ax &= 0x00ff;
    if (ax != 0x000d)
        goto loc_4590;
    sub_d606();
    sub_7b0a();
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x5135, dx);
    memoryASet16(ds, 0x5137, ax);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_46c8() // 01ed:27f8
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = 0x0021;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = memoryAGet16(ss, bp + 6);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1390);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp + 6);
    ax--;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1390);
    memoryASet16(ss, bp - 4, ax);
    if (ax != memoryAGet16(ss, bp - 2))
        goto loc_4723;
    ax = memoryAGet16(ss, bp + 6);
    ax--;
    di = ax;
    goto loc_4726;
loc_4723: // 01ed:2853
    di = memoryAGet16(ss, bp + 6);
loc_4726: // 01ed:2856
    sub_484e();
    si = ax;
    memoryASet16(ds, si + 8, 0x0001);
    memoryASet16(ds, si + 34, 0x273d);
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si, ax);
    memoryASet16(ds, si + 2, dx);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    memoryASet16(ds, si + 4, ax);
    memoryASet16(ds, si + 6, dx);
    memoryASet16(ds, si + 10, 0x0000);
    ax = di;
    ax += 0x0003;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, si + 12, ax);
    ax = di;
    ax++;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, si + 14, ax);
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, si + 16, ax);
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    memoryASet16(ds, bx + 43674, 0x0000);
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    ax = di;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp + 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_4805() // 01ed:2935
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = 0x0001;
    si = 0x6f10;
    goto loc_4816;
loc_4812: // 01ed:2942
    di++;
    si += 0x0036;
loc_4816: // 01ed:2946
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_4821;
    if ((short)di < (short)memoryAGet16(ds, 0x5db4))
        goto loc_4812;
loc_4821: // 01ed:2951
    if ((short)di < (short)memoryAGet16(ds, 0x5db4))
        goto loc_482b;
    memoryASet16(ds, 0x5db4, memoryAGet16(ds, 0x5db4) + 1);
loc_482b: // 01ed:295b
    ax = 0x0036;
    push(ax);
    ax = 0;
    push(ax);
    push(si);
    sub_f309();
    sp += 0x0006;
    memoryASet16(ds, si + 50, 0x2919);
    memoryASet16(ds, si + 52, 0x2927);
    memoryASet16(ds, si + 2, 0x0001);
    ax = si;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_484e() // 01ed:297e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = 0;
    si = 0x7fd6;
    goto loc_485e;
loc_485a: // 01ed:298a
    di++;
    si += 0x0024;
loc_485e: // 01ed:298e
    if (memoryAGet16(ds, si + 8) == 0x0000)
        goto loc_486a;
    if ((short)di < (short)memoryAGet16(ds, 0x8216))
        goto loc_485a;
loc_486a: // 01ed:299a
    if ((short)di < (short)memoryAGet16(ds, 0x8216))
        goto loc_4874;
    memoryASet16(ds, 0x8216, memoryAGet16(ds, 0x8216) + 1);
loc_4874: // 01ed:29a4
    ax = 0x0024;
    push(ax);
    ax = 0;
    push(ax);
    push(si);
    sub_f309();
    sp += 0x0006;
    memoryASet16(ds, si + 34, 0x2919);
    ax = si;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_488d() // 01ed:29bd
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    si = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ds, di + 12);
    ax |= memoryAGet16(ds, di + 14);
    if (!ax)
        goto loc_48a8;
    ax = memoryAGet16(ds, si + 12);
    ax |= memoryAGet16(ds, si + 14);
    if (ax)
        goto loc_48ac;
loc_48a8: // 01ed:29d8
    ax = 0;
    goto loc_4907;
loc_48ac: // 01ed:29dc
    ax = memoryAGet16(ds, di + 22);
    dx = memoryAGet16(ds, di + 20);
    if ((short)ax > (short)memoryAGet16(ds, si + 14))
        goto loc_48c2;
    if ((short)ax < (short)memoryAGet16(ds, si + 14))
        goto loc_48be;
    if (dx >= memoryAGet16(ds, si + 12))
        goto loc_48c2;
loc_48be: // 01ed:29ee
    ax = 0;
    goto loc_4907;
loc_48c2: // 01ed:29f2
    ax = memoryAGet16(ds, di + 26);
    dx = memoryAGet16(ds, di + 24);
    if ((short)ax > (short)memoryAGet16(ds, si + 18))
        goto loc_48d8;
    if ((short)ax < (short)memoryAGet16(ds, si + 18))
        goto loc_48d4;
    if (dx >= memoryAGet16(ds, si + 16))
        goto loc_48d8;
loc_48d4: // 01ed:2a04
    ax = 0;
    goto loc_4907;
loc_48d8: // 01ed:2a08
    ax = memoryAGet16(ds, di + 14);
    dx = memoryAGet16(ds, di + 12);
    if ((short)ax < (short)memoryAGet16(ds, si + 22))
        goto loc_48ee;
    if ((short)ax > (short)memoryAGet16(ds, si + 22))
        goto loc_48ea;
    if (dx <= memoryAGet16(ds, si + 20))
        goto loc_48ee;
loc_48ea: // 01ed:2a1a
    ax = 0;
    goto loc_4907;
loc_48ee: // 01ed:2a1e
    ax = memoryAGet16(ds, di + 18);
    dx = memoryAGet16(ds, di + 16);
    if ((short)ax < (short)memoryAGet16(ds, si + 26))
        goto loc_4904;
    if ((short)ax > (short)memoryAGet16(ds, si + 26))
        goto loc_4900;
    if (dx <= memoryAGet16(ds, si + 24))
        goto loc_4904;
loc_4900: // 01ed:2a30
    ax = 0;
    goto loc_4907;
loc_4904: // 01ed:2a34
    ax = 0x0001;
loc_4907: // 01ed:2a37
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_490b() // 01ed:2a3b
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = 0;
    dx = 0x0004;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8226);
    ax = memoryAGet16(ds, 0x8224);
    cl = 0x09;
    sub_10042();
    push(dx);
    push(ax);
    sub_ff82();
    dx = memoryAGet16(ds, 0x8248);
    dx <<= 1;
    dx <<= 1;
    dx += ax;
    si = dx;
    ax = 0x8306;
    push(ds);
    push(ax);
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    push(dx);
    push(ax);
    cx = 0x0020;
    sub_1016b();
    ax = memoryAGet16(ds, 0x830e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0x8226);
    cx = memoryAGet16(ds, 0x8224);
    flags.carry = (cx + ax) >= 0x10000;
    cx += ax;
    bx += dx + flags.carry;
    memoryASet16(ds, 0x822c, cx);
    memoryASet16(ds, 0x822e, bx);
    ax = memoryAGet16(ds, 0x8312);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0x8226);
    cx = memoryAGet16(ds, 0x8224);
    flags.carry = (cx + ax) >= 0x10000;
    cx += ax;
    bx += dx + flags.carry;
    memoryASet16(ds, 0x8234, cx);
    memoryASet16(ds, 0x8236, bx);
    ax = memoryAGet16(ds, 0x8310);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0x822a);
    cx = memoryAGet16(ds, 0x8228);
    flags.carry = (cx + ax) >= 0x10000;
    cx += ax;
    bx += dx + flags.carry;
    memoryASet16(ds, 0x8230, cx);
    memoryASet16(ds, 0x8232, bx);
    ax = memoryAGet16(ds, 0x8314);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0x822a);
    cx = memoryAGet16(ds, 0x8228);
    flags.carry = (cx + ax) >= 0x10000;
    cx += ax;
    bx += dx + flags.carry;
    memoryASet16(ds, 0x8238, cx);
    memoryASet16(ds, 0x823a, bx);
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_49b9() // 01ed:2ae9
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    ax = 0;
    dx = 0x0004;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, si + 6);
    ax = memoryAGet16(ds, si + 4);
    cl = 0x09;
    sub_10042();
    push(dx);
    push(ax);
    sub_ff82();
    dx = memoryAGet16(ds, si + 40);
    dx <<= 1;
    dx <<= 1;
    dx += ax;
    di = dx;
    ax = 0x8306;
    push(ds);
    push(ax);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    push(dx);
    push(ax);
    cx = 0x0020;
    sub_1016b();
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    push(ax);
    ax = memoryAGet16(ds, 0x830e);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    ax = pop();
    ax += dx + flags.carry;
    memoryASet16(ds, si + 12, bx);
    memoryASet16(ds, si + 14, ax);
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    push(ax);
    ax = memoryAGet16(ds, 0x8312);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    ax = pop();
    ax += dx + flags.carry;
    memoryASet16(ds, si + 20, bx);
    memoryASet16(ds, si + 22, ax);
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    push(ax);
    ax = memoryAGet16(ds, 0x8310);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    ax = pop();
    ax += dx + flags.carry;
    memoryASet16(ds, si + 16, bx);
    memoryASet16(ds, si + 18, ax);
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    push(ax);
    ax = memoryAGet16(ds, 0x8314);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    ax = pop();
    ax += dx + flags.carry;
    memoryASet16(ds, si + 24, bx);
    memoryASet16(ds, si + 26, ax);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_4a6a() // 01ed:2b9a
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    si = 0x0001;
    goto loc_4aa5;
loc_4a77: // 01ed:2ba7
    memoryASet16(ds, 0x8240, memoryAGet16(ds, 0x8240) + di);
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0078)
        goto loc_4a8a;
    memoryASet16(ds, 0x8240, 0x0078);
    goto loc_4a97;
loc_4a8a: // 01ed:2bba
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0xff88)
        goto loc_4a97;
    memoryASet16(ds, 0x8240, 0xff88);
loc_4a97: // 01ed:2bc7
    if (si == memoryAGet16(ds, 0x5b14))
        goto loc_4aa4;
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) + ax);
loc_4aa4: // 01ed:2bd4
    si++;
loc_4aa5: // 01ed:2bd5
    if (si <= memoryAGet16(ds, 0x5b14))
        goto loc_4a77;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_4aaf() // 01ed:2bdf
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    si = 0x0001;
    goto loc_4af0;
loc_4abf: // 01ed:2bef
    ax = dx;
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) + ax);
    if ((short)memoryAGet16(ds, 0x8242) <= (short)di)
        goto loc_4ad1;
    memoryASet16(ds, 0x8242, di);
    goto loc_4ae2;
loc_4ad1: // 01ed:2c01
    ax = di;
    ax = -ax;
    if ((short)ax <= (short)memoryAGet16(ds, 0x8242))
        goto loc_4ae2;
    ax = di;
    ax = -ax;
    memoryASet16(ds, 0x8242, ax);
loc_4ae2: // 01ed:2c12
    if (si == memoryAGet16(ds, 0x5b14))
        goto loc_4aef;
    ax = memoryAGet16(ds, 0x8242);
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + ax);
loc_4aef: // 01ed:2c1f
    si++;
loc_4af0: // 01ed:2c20
    if (si <= memoryAGet16(ds, 0x5b14))
        goto loc_4abf;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_4afa() // 01ed:2c2a
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = 0x0001;
    goto loc_4b34;
loc_4b03: // 01ed:2c33
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) + 0x0003);
    if ((short)memoryAGet16(ds, 0x8242) <= (short)0x00c8)
        goto loc_4b18;
    memoryASet16(ds, 0x8242, 0x00c8);
    goto loc_4b26;
loc_4b18: // 01ed:2c48
    if ((short)memoryAGet16(ds, 0x8242) >= (short)0xfe70)
        goto loc_4b26;
    memoryASet16(ds, 0x8242, 0xfe70);
loc_4b26: // 01ed:2c56
    if (si == memoryAGet16(ds, 0x5b14))
        goto loc_4b33;
    ax = memoryAGet16(ds, 0x8242);
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + ax);
loc_4b33: // 01ed:2c63
    si++;
loc_4b34: // 01ed:2c64
    if (si <= memoryAGet16(ds, 0x5b14))
        goto loc_4b03;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_4b3d() // 01ed:2c6d
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x8240);
    imul16(memoryAGet16(ds, 0x5b14));
    dx = memoryAGet16(ds, 0x823c);
    dx += ax;
    memoryASet16(ds, 0x823c, dx);
    ax = memoryAGet16(ds, 0x8242);
    imul16(memoryAGet16(ds, 0x5b14));
    dx = memoryAGet16(ds, 0x823e);
    dx += ax;
    memoryASet16(ds, 0x823e, dx);
    sub_4b67();
    bp = pop();
    sp += 2;
}
void sub_4b67() // 01ed:2c97
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    memoryASet16(ss, bp - 12, 0x0000);
    if ((short)memoryAGet16(ds, 0x823c) <= (short)0x0f00)
        goto loc_4b84;
    memoryASet16(ds, 0x823c, 0x0f00);
    goto loc_4b92;
loc_4b84: // 01ed:2cb4
    if ((short)memoryAGet16(ds, 0x823c) >= (short)0xf100)
        goto loc_4b92;
    memoryASet16(ds, 0x823c, 0xf100);
loc_4b92: // 01ed:2cc2
    if ((short)memoryAGet16(ds, 0x823e) <= (short)0x0f00)
        goto loc_4ba2;
    memoryASet16(ds, 0x823e, 0x0f00);
    goto loc_4bb0;
loc_4ba2: // 01ed:2cd2
    if ((short)memoryAGet16(ds, 0x823e) >= (short)0xf100)
        goto loc_4bb0;
    memoryASet16(ds, 0x823e, 0xf100);
loc_4bb0: // 01ed:2ce0
    ax = memoryAGet16(ds, 0x823e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8238) + ax) >= 0x10000;
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) + ax);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x823e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8230) + ax) >= 0x10000;
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) + ax);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) + (dx + flags.carry));
    dx = memoryAGet16(ds, 0x822e);
    ax = memoryAGet16(ds, 0x822c);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ds, 0x8236);
    ax = memoryAGet16(ds, 0x8234);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 6, ax);
    if ((short)memoryAGet16(ds, 0x823e) > (short)0x0000)
        goto loc_4bf0;
    goto loc_4ca7;
loc_4bf0: // 01ed:2d20
    dx = memoryAGet16(ds, 0x823a);
    ax = memoryAGet16(ds, 0x8238);
    cl = 0x0c;
    sub_10042();
    push(ax);
    ax = memoryAGet16(ds, 0x823e);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x823a);
    ax = memoryAGet16(ds, 0x8238);
    bx = pop();
    cx = pop();
    flags.carry = ax < cx;
    ax -= cx;
    dx = dx - bx - flags.carry;
    cl = 0x0c;
    sub_10042();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_4c23;
    if (dx != ax)
        goto loc_4c23;
    goto loc_4d64;
loc_4c23: // 01ed:2d53
    dx = memoryAGet16(ds, 0x823a);
    ax = memoryAGet16(ds, 0x8238);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 2, ax);
    goto loc_4c9c;
loc_4c3a: // 01ed:2d6a
    ax = memoryAGet16(ss, bp - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2612) == 0x0000)
        goto loc_4c99;
    memoryASet16(ds, 0x8242, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0x823a);
    dx = memoryAGet16(ds, 0x8238);
    flags.carry = (dx + 0x0001) >= 0x10000;
    dx += 0x0001;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_ff82();
    si = ax;
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) - ax);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8230) < ax;
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) - ax);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) - dx - flags.carry);
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8238) < ax;
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) - ax);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) - dx - flags.carry);
    memoryASet16(ss, bp - 12, 0x0002);
    goto loc_4d64;
loc_4c99: // 01ed:2dc9
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4c9c: // 01ed:2dcc
    ax = memoryAGet16(ss, bp - 2);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 6))
        goto loc_4c3a;
    goto loc_4d64;
loc_4ca7: // 01ed:2dd7
    if ((short)memoryAGet16(ds, 0x823e) < (short)0x0000)
        goto loc_4cb1;
    goto loc_4d64;
loc_4cb1: // 01ed:2de1
    dx = memoryAGet16(ds, 0x8232);
    ax = memoryAGet16(ds, 0x8230);
    cl = 0x0c;
    sub_10042();
    push(ax);
    ax = memoryAGet16(ds, 0x823e);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8232);
    ax = memoryAGet16(ds, 0x8230);
    bx = pop();
    cx = pop();
    flags.carry = ax < cx;
    ax -= cx;
    dx = dx - bx - flags.carry;
    cl = 0x0c;
    sub_10042();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_4ce4;
    if (dx != ax)
        goto loc_4ce4;
    goto loc_4d64;
loc_4ce4: // 01ed:2e14
    dx = memoryAGet16(ds, 0x8232);
    ax = memoryAGet16(ds, 0x8230);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 2, ax);
    goto loc_4d5c;
loc_4cfb: // 01ed:2e2b
    ax = memoryAGet16(ss, bp - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 5056) == 0x0000)
        goto loc_4d59;
    memoryASet16(ds, 0x8242, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8232));
    push(memoryAGet16(ds, 0x8230));
    sub_ff82();
    dx = 0x1000;
    dx -= ax;
    si = dx;
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + dx);
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8230) + ax) >= 0x10000;
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) + ax);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) + (dx + flags.carry));
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8238) + ax) >= 0x10000;
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) + ax);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) + (dx + flags.carry));
    memoryASet16(ss, bp - 12, 0x0008);
    goto loc_4d64;
loc_4d59: // 01ed:2e89
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_4d5c: // 01ed:2e8c
    ax = memoryAGet16(ss, bp - 2);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 6))
        goto loc_4cfb;
loc_4d64: // 01ed:2e94
    ax = memoryAGet16(ds, 0x823c);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x822c) + ax) >= 0x10000;
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) + ax);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x823c);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8234) + ax) >= 0x10000;
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) + ax);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) + (dx + flags.carry));
    dx = memoryAGet16(ds, 0x8232);
    ax = memoryAGet16(ds, 0x8230);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 8, ax);
    dx = memoryAGet16(ds, 0x823a);
    ax = memoryAGet16(ds, 0x8238);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 10, ax);
    if ((short)memoryAGet16(ds, 0x823c) > (short)0x0000)
        goto loc_4da4;
    goto loc_4e52;
loc_4da4: // 01ed:2ed4
    dx = memoryAGet16(ds, 0x8236);
    ax = memoryAGet16(ds, 0x8234);
    cl = 0x0c;
    sub_10042();
    push(ax);
    ax = memoryAGet16(ds, 0x823c);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8236);
    ax = memoryAGet16(ds, 0x8234);
    bx = pop();
    cx = pop();
    flags.carry = ax < cx;
    ax -= cx;
    dx = dx - bx - flags.carry;
    cl = 0x0c;
    sub_10042();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_4dd7;
    if (dx != ax)
        goto loc_4dd7;
    goto loc_4f03;
loc_4dd7: // 01ed:2f07
    dx = memoryAGet16(ds, 0x8236);
    ax = memoryAGet16(ds, 0x8234);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 6, ax);
    di = memoryAGet16(ss, bp - 8);
    goto loc_4e4a;
loc_4deb: // 01ed:2f1b
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 6278) == 0x0000)
        goto loc_4e49;
    memoryASet16(ds, 0x8240, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0x8236);
    dx = memoryAGet16(ds, 0x8234);
    flags.carry = (dx + 0x0001) >= 0x10000;
    dx += 0x0001;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_ff82();
    si = ax;
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) - ax);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x822c) < ax;
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) - ax);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) - dx - flags.carry);
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8234) < ax;
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) - ax);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) - dx - flags.carry);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) | 0x0004);
    goto loc_4f03;
loc_4e49: // 01ed:2f79
    di++;
loc_4e4a: // 01ed:2f7a
    if ((short)di <= (short)memoryAGet16(ss, bp - 10))
        goto loc_4deb;
    goto loc_4f03;
loc_4e52: // 01ed:2f82
    if ((short)memoryAGet16(ds, 0x823c) < (short)0x0000)
        goto loc_4e5c;
    goto loc_4f03;
loc_4e5c: // 01ed:2f8c
    dx = memoryAGet16(ds, 0x822e);
    ax = memoryAGet16(ds, 0x822c);
    cl = 0x0c;
    sub_10042();
    push(ax);
    ax = memoryAGet16(ds, 0x823c);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x822e);
    ax = memoryAGet16(ds, 0x822c);
    bx = pop();
    cx = pop();
    flags.carry = ax < cx;
    ax -= cx;
    dx = dx - bx - flags.carry;
    cl = 0x0c;
    sub_10042();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_4e8c;
    if (dx == ax)
        goto loc_4f03;
loc_4e8c: // 01ed:2fbc
    dx = memoryAGet16(ds, 0x822e);
    ax = memoryAGet16(ds, 0x822c);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 4, ax);
    di = memoryAGet16(ss, bp - 8);
    goto loc_4efe;
loc_4ea0: // 01ed:2fd0
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 4);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 3834) == 0x0000)
        goto loc_4efd;
    memoryASet16(ds, 0x8240, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x822e));
    push(memoryAGet16(ds, 0x822c));
    sub_ff82();
    dx = 0x1000;
    dx -= ax;
    si = dx;
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) + dx);
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x822c) + ax) >= 0x10000;
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) + ax);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) + (dx + flags.carry));
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8234) + ax) >= 0x10000;
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) + ax);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) + (dx + flags.carry));
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) | 0x0001);
    goto loc_4f03;
loc_4efd: // 01ed:302d
    di++;
loc_4efe: // 01ed:302e
    if ((short)di <= (short)memoryAGet16(ss, bp - 10))
        goto loc_4ea0;
loc_4f03: // 01ed:3033
    ax = memoryAGet16(ss, bp - 12);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5166() // 01ed:3296
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    dx = memoryAGet16(ds, 0x8226);
    ax = memoryAGet16(ds, 0x8224);
    cl = 0x0c;
    sub_10042();
    di = ax;
    dx = memoryAGet16(ds, 0x822a);
    ax = memoryAGet16(ds, 0x8228);
    cl = 0x0c;
    sub_10042();
    si = ax;
    if ((short)memoryAGet16(ds, 0x822a) > (short)0x0000)
        goto loc_51a3;
    if ((short)memoryAGet16(ds, 0x822a) < (short)0x0000)
        goto loc_5197;
    if (memoryAGet16(ds, 0x8228) >= 0x0000)
        goto loc_51a3;
loc_5197: // 01ed:32c7
    memoryASet16(ds, 0x8228, 0x0000);
    memoryASet16(ds, 0x822a, 0x0000);
loc_51a3: // 01ed:32d3
    ax = memoryAGet16(ds, 0x8226);
    dx = memoryAGet16(ds, 0x8224);
    if ((short)ax > (short)memoryAGet16(ds, 0x5644))
        goto loc_51dd;
    if (ax != memoryAGet16(ds, 0x5644))
        goto loc_51b8;
    if (dx > memoryAGet16(ds, 0x5642))
        goto loc_51dd;
loc_51b8: // 01ed:32e8
    if ((short)memoryAGet16(ds, 0x8226) < (short)0x0000)
        goto loc_51dd;
    if (memoryAGet16(ds, 0x8226) != 0x0000)
        goto loc_51c8;
    if (memoryAGet16(ds, 0x8224) < 0x0000)
        goto loc_51dd;
loc_51c8: // 01ed:32f8
    ax = memoryAGet16(ds, 0x822a);
    dx = memoryAGet16(ds, 0x8228);
    if ((short)ax < (short)memoryAGet16(ds, 0x5648))
        goto loc_51e8;
    if ((short)ax > (short)memoryAGet16(ds, 0x5648))
        goto loc_51dd;
    if (dx <= memoryAGet16(ds, 0x5646))
        goto loc_51e8;
loc_51dd: // 01ed:330d
    memoryASet16(ds, 0x8220, 0x0000);
    ax = 0x0001;
    goto loc_522c;
loc_51e8: // 01ed:3318
    ax = memoryAGet16(ds, 0x5656);
    ax += 0xfff8;
    if ((short)ax > (short)di)
        goto loc_5210;
    ax = memoryAGet16(ds, 0x5b12);
    ax += 0xfff8;
    if ((short)ax > (short)si)
        goto loc_5210;
    ax = memoryAGet16(ds, 0x5656);
    ax += 0x001c;
    if ((short)ax < (short)di)
        goto loc_5210;
    ax = memoryAGet16(ds, 0x5b12);
    ax += 0x0012;
    if ((short)ax >= (short)si)
        goto loc_522a;
loc_5210: // 01ed:3340
    if ((short)memoryAGet16(ds, 0x8220) >= (short)0x0009)
        goto loc_521f;
    memoryASet16(ds, 0x8222, 0x0000);
    goto loc_5225;
loc_521f: // 01ed:334f
    memoryASet16(ds, 0x8220, 0x0000);
loc_5225: // 01ed:3355
    ax = 0x0001;
    goto loc_522c;
loc_522a: // 01ed:335a
    ax = 0;
loc_522c: // 01ed:335c
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_5235() // 01ed:3365
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x564c);
    dx = memoryAGet16(ds, 0x564a);
    flags.carry = (dx + 0x0008) >= 0x10000;
    dx += 0x0008;
    ax += 0x0000 + flags.carry;
    if ((short)ax < (short)memoryAGet16(ds, 0x8226))
        goto loc_526a;
    if ((short)ax > (short)memoryAGet16(ds, 0x8226))
        goto loc_5253;
    if (dx <= memoryAGet16(ds, 0x8224))
        goto loc_526a;
loc_5253: // 01ed:3383
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x8240, ax);
    ax = memoryAGet16(ds, 0x564c);
    dx = memoryAGet16(ds, 0x564a);
    flags.carry = (dx + 0x0008) >= 0x10000;
    dx += 0x0008;
    ax += 0x0000 + flags.carry;
    goto loc_528e;
loc_526a: // 01ed:339a
    ax = memoryAGet16(ds, 0x8226);
    dx = memoryAGet16(ds, 0x8224);
    if ((short)ax < (short)memoryAGet16(ds, 0x5dae))
        goto loc_5295;
    if ((short)ax > (short)memoryAGet16(ds, 0x5dae))
        goto loc_527f;
    if (dx <= memoryAGet16(ds, 0x5dac))
        goto loc_5295;
loc_527f: // 01ed:33af
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x8240, ax);
    ax = memoryAGet16(ds, 0x5dae);
    dx = memoryAGet16(ds, 0x5dac);
loc_528e: // 01ed:33be
    memoryASet16(ds, 0x8224, dx);
    memoryASet16(ds, 0x8226, ax);
loc_5295: // 01ed:33c5
    ax = memoryAGet16(ds, 0x822a);
    dx = memoryAGet16(ds, 0x8228);
    if ((short)ax > (short)memoryAGet16(ds, 0x5650))
        goto loc_52c2;
    if ((short)ax < (short)memoryAGet16(ds, 0x5650))
        goto loc_52aa;
    if (dx >= memoryAGet16(ds, 0x564e))
        goto loc_52c2;
loc_52aa: // 01ed:33da
    ax = 0;
    memoryASet16(ds, 0x823e, ax);
    memoryASet16(ds, 0x8242, ax);
    ax = memoryAGet16(ds, 0x5650);
    dx = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x8228, dx);
    memoryASet16(ds, 0x822a, ax);
    goto loc_52e6;
loc_52c2: // 01ed:33f2
    ax = memoryAGet16(ds, 0x822a);
    dx = memoryAGet16(ds, 0x8228);
    if ((short)ax < (short)memoryAGet16(ds, 0x5db2))
        goto loc_52e6;
    if ((short)ax > (short)memoryAGet16(ds, 0x5db2))
        goto loc_52d7;
    if (dx <= memoryAGet16(ds, 0x5db0))
        goto loc_52e6;
loc_52d7: // 01ed:3407
    ax = 0x001b;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    sub_de4f();
    sub_617c();
loc_52e6: // 01ed:3416
    bp = pop();
    sp += 2;
}
void sub_52e8() // 01ed:3418
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6f0c) != 0x40ef)
        goto loc_52fb;
    goto loc_545c;
loc_52fb: // 01ed:342b
    if (memoryAGet16(ds, 0x6f0c) != 0x41f8)
        goto loc_5306;
    goto loc_545c;
loc_5306: // 01ed:3436
    ax = memoryAGet16(ds, 0x6ee0);
    dx = memoryAGet16(ds, 0x6ede);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ds, 0x6ee4);
    dx = memoryAGet16(ds, 0x6ee2);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    di = memoryAGet16(ds, 0x6ef6);
    si = memoryAGet16(ds, 0x6ef8);
    if ((short)di <= 0)
        goto loc_5376;
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    flags.carry = dx < memoryAGet16(ds, 0x6ed0);
    dx -= memoryAGet16(ds, 0x6ed0);
    ax = ax - memoryAGet16(ds, 0x6ed2) - flags.carry;
    if ((short)ax < 0)
        goto loc_5376;
    if ((short)ax > 0)
        goto loc_5346;
    if (dx <= 0xb000)
        goto loc_5376;
loc_5346: // 01ed:3476
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed0) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + ax);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc0))
        goto loc_53c2;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc0))
        goto loc_5366;
    if (dx <= memoryAGet16(ds, 0x7fbe))
        goto loc_53c2;
loc_5366: // 01ed:3496
    ax = memoryAGet16(ds, 0x7fc0);
    dx = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    goto loc_53c2;
loc_5376: // 01ed:34a6
    if ((short)di >= 0)
        goto loc_53c2;
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    flags.carry = dx < memoryAGet16(ds, 0x6ed0);
    dx -= memoryAGet16(ds, 0x6ed0);
    ax = ax - memoryAGet16(ds, 0x6ed2) - flags.carry;
    if ((short)ax > 0)
        goto loc_53c2;
    if ((short)ax < 0)
        goto loc_5394;
    if (dx >= 0x9000)
        goto loc_53c2;
loc_5394: // 01ed:34c4
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed0) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + ax);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax > (short)memoryAGet16(ds, 0x564c))
        goto loc_53c2;
    if ((short)ax < (short)memoryAGet16(ds, 0x564c))
        goto loc_53b4;
    if (dx >= memoryAGet16(ds, 0x564a))
        goto loc_53c2;
loc_53b4: // 01ed:34e4
    ax = memoryAGet16(ds, 0x564c);
    dx = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
loc_53c2: // 01ed:34f2
    if ((short)si <= 0)
        goto loc_5410;
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    flags.carry = dx < memoryAGet16(ds, 0x6ed4);
    dx -= memoryAGet16(ds, 0x6ed4);
    ax = ax - memoryAGet16(ds, 0x6ed6) - flags.carry;
    if ((short)ax < 0)
        goto loc_5410;
    if ((short)ax > 0)
        goto loc_53e0;
    if (dx <= 0x7000)
        goto loc_5410;
loc_53e0: // 01ed:3510
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed4) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + ax);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc4))
        goto loc_545c;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc4))
        goto loc_5400;
    if (dx <= memoryAGet16(ds, 0x7fc2))
        goto loc_545c;
loc_5400: // 01ed:3530
    ax = memoryAGet16(ds, 0x7fc4);
    dx = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    goto loc_545c;
loc_5410: // 01ed:3540
    if ((short)si >= 0)
        goto loc_545c;
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    flags.carry = dx < memoryAGet16(ds, 0x6ed4);
    dx -= memoryAGet16(ds, 0x6ed4);
    ax = ax - memoryAGet16(ds, 0x6ed6) - flags.carry;
    if ((short)ax > 0)
        goto loc_545c;
    if ((short)ax < 0)
        goto loc_542e;
    if (dx >= 0x3000)
        goto loc_545c;
loc_542e: // 01ed:355e
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed4) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + ax);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax > (short)memoryAGet16(ds, 0x5650))
        goto loc_545c;
    if ((short)ax < (short)memoryAGet16(ds, 0x5650))
        goto loc_544e;
    if (dx >= memoryAGet16(ds, 0x564e))
        goto loc_545c;
loc_544e: // 01ed:357e
    ax = memoryAGet16(ds, 0x5650);
    dx = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
loc_545c: // 01ed:358c
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5462() // 01ed:3592
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x821e, 0x0001);
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x253b;
    ax = 0x1002;
    interrupt(0x10);
    bp = pop();
    sp += 2;
}
void sub_5482() // 01ed:35b2
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x821e, 0x0000);
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x2519;
    ax = 0x1002;
    interrupt(0x10);
    bp = pop();
    sp += 2;
}
void sub_54a2() // 01ed:35d2
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0012;
    push(si);
    push(di);
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x821a);
    ax += 0x0005;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ds, 0x8218);
    dx += ax;
    dx += 0x0003;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    if (memoryAGet16(es, bx) == 0x01df)
        goto loc_54d8;
    goto loc_558c;
loc_54d8: // 01ed:3608
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, bp - 14, dx);
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, bp - 18, dx);
    memoryASet16(ss, bp - 16, ax);
    si = 0x0001;
    goto loc_555e;
loc_54f7: // 01ed:3627
    sub_2109();
    ax = 0x0040;
    push(ax);
    sub_df2c();
    sp++;
    sp++;
    ax += 0xffe0;
    cl = 0x08;
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ss, bp - 12);
    cx = memoryAGet16(ss, bp - 14);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    memoryASet16(ds, 0x6ed0, cx);
    memoryASet16(ds, 0x6ed2, bx);
    ax = 0x0040;
    push(ax);
    sub_df2c();
    sp++;
    sp++;
    ax += 0xffe0;
    cl = 0x08;
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ss, bp - 16);
    cx = memoryAGet16(ss, bp - 18);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    memoryASet16(ds, 0x6ed4, cx);
    memoryASet16(ds, 0x6ed6, bx);
    push(memoryAGet16(ds, 0x8248));
    push(memoryAGet16(ds, 0x822a));
    push(memoryAGet16(ds, 0x8228));
    push(memoryAGet16(ds, 0x8226));
    push(memoryAGet16(ds, 0x8224));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    si++;
loc_555e: // 01ed:368e
    if ((short)si < (short)0x0050)
        goto loc_54f7;
    ax = 0x0001;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x2444;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x0064;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    memoryASet16(ds, 0x6c60, 0x0003);
    goto loc_5731;
loc_558c: // 01ed:36bc
    ax = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ds, 0x8218);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 4, ax);
    if (ax == 0x010f)
        goto loc_55ea;
    if (ax == 0x01e0)
        goto loc_55b6;
    if (ax == 0x01ed)
        goto loc_55d0;
    goto loc_55fd;
loc_55b6: // 01ed:36e6
    ax = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ds, 0x8218);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x01ed);
    goto loc_55fd;
loc_55d0: // 01ed:3700
    ax = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ds, 0x8218);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x01e0);
    goto loc_55fd;
loc_55ea: // 01ed:371a
    if (memoryAGet16(ds, 0x821e) == 0x0000)
        goto loc_55f7;
    sub_5482();
    goto loc_5731;
loc_55f7: // 01ed:3727
    sub_5462();
    goto loc_5731;
loc_55fd: // 01ed:372d
    ax = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ds, 0x8218);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 2, ax);
    al = memoryAGet(ss, bp - 2);
    al &= 0xff;
    cbw();
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ds, 0x8218);
    ax += memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 2);
    cl = 0x08;
    ax >>= cl;
    cbw();
    dx = memoryAGet16(ds, 0x821a);
    dx += ax;
    memoryASet16(ss, bp - 8, dx);
    si = 0;
    goto loc_5680;
loc_563d: // 01ed:376d
    ax = si;
    dx = 0x0024;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 32734) == 0x0000)
        goto loc_567f;
    ax = si;
    dx = 0x0024;
    imul16(dx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    if (memoryAGet16(ds, bx + 32728) != dx)
        goto loc_567f;
    if (memoryAGet16(ds, bx + 32726) != ax)
        goto loc_567f;
    ax = si;
    dx = 0x0024;
    imul16(dx);
    push(ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = pop();
    if (memoryAGet16(ds, bx + 32732) != dx)
        goto loc_567f;
    if (memoryAGet16(ds, bx + 32730) == ax)
        goto loc_5686;
loc_567f: // 01ed:37af
    si++;
loc_5680: // 01ed:37b0
    if ((short)si < (short)memoryAGet16(ds, 0x8216))
        goto loc_563d;
loc_5686: // 01ed:37b6
    if ((short)si >= (short)memoryAGet16(ds, 0x8216))
        goto loc_56c0;
    ax = si;
    dx = 0x0024;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 32760) != 0x4afa)
        goto loc_56af;
    ax = si;
    dx = 0x0024;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 32760, 0x4a8b);
    goto loc_5731;
loc_56af: // 01ed:37df
    ax = si;
    dx = 0x0024;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 32760, 0x4afa);
    goto loc_5731;
loc_56c0: // 01ed:37f0
    sub_484e();
    di = ax;
    memoryASet16(ds, di + 8, 0x0002);
    memoryASet16(ds, di + 34, 0x4a8b);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, di, ax);
    memoryASet16(ds, di + 2, dx);
    ax = memoryAGet16(ss, bp - 8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, di + 4, ax);
    memoryASet16(ds, di + 6, dx);
    memoryASet16(ds, di + 10, 0x0000);
    ax = memoryAGet16(ss, bp - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ss, bp - 6);
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 6278) == 0x0000)
        goto loc_570f;
    memoryASet16(ds, di + 12, 0xffff);
    goto loc_5714;
loc_570f: // 01ed:383f
    memoryASet16(ds, di + 12, 0x0001);
loc_5714: // 01ed:3844
    ax = memoryAGet16(ss, bp - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, di + 14, ax);
    memoryASet16(ds, di + 16, 0x0000);
loc_5731: // 01ed:3861
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5737() // 01ed:3867
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x8250) == 0x0000)
        goto loc_574b;
    di = 0x0001;
    goto loc_57ab;
loc_574b: // 01ed:387b
    dx = memoryAGet16(ds, 0x822e);
    ax = memoryAGet16(ds, 0x822c);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ds, 0x8236);
    ax = memoryAGet16(ds, 0x8234);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 6, ax);
    dx = memoryAGet16(ds, 0x823a);
    ax = memoryAGet16(ds, 0x8238);
    cl = 0x0c;
    sub_10042();
    ax++;
    memoryASet16(ss, bp - 8, ax);
    di = 0x0001;
    si = memoryAGet16(ss, bp - 4);
    goto loc_57a6;
loc_5781: // 01ed:38b1
    ax = memoryAGet16(ss, bp - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 2612);
    memoryASet16(ss, bp - 10, ax);
    if ((short)ax <= (short)0x0001)
        goto loc_57a5;
    di = ax;
loc_57a5: // 01ed:38d5
    si++;
loc_57a6: // 01ed:38d6
    if ((short)si <= (short)memoryAGet16(ss, bp - 6))
        goto loc_5781;
loc_57ab: // 01ed:38db
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_57e5;
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824e, ax);
    memoryASet16(ds, 0x8240, 0x0000);
    memoryASet16(ds, 0x824c, 0x0000);
    memoryASet16(ds, 0x824a, 0x0000);
    if ((short)memoryAGet16(ds, 0x604c) < (short)0x0000)
        goto loc_57d9;
    memoryASet16(ds, 0x8246, 0x0008);
    goto loc_57df;
loc_57d9: // 01ed:3909
    memoryASet16(ds, 0x8246, 0x000e);
loc_57df: // 01ed:390f
    memoryASet16(ds, 0x8252, 0x3b8b);
loc_57e5: // 01ed:3915
    if ((short)di >= (short)0x0003)
        goto loc_5829;
    bx = memoryAGet16(ds, 0x7fca);
    bx--;
    if (bx > 0x0006)
        goto loc_5829;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_57fb;
        case 2: goto loc_57fb;
        case 4: goto loc_57fb;
        case 6: goto loc_5829;
        case 8: goto loc_5813;
        case 10: goto loc_5813;
        case 12: goto loc_5813;
        default:
            stop();
    }
loc_57fb: // 01ed:392b
    ax = 0x0002;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5829;
    memoryASet16(ds, 0x7fca, 0x0008);
    goto loc_5829;
loc_5813: // 01ed:3943
    ax = 0xfffe;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5829;
    memoryASet16(ds, 0x7fca, 0x0008);
loc_5829: // 01ed:3959
    if (di != 0x0001)
        goto loc_5871;
    if (memoryAGet16(ds, 0x7fca) != 0x0008)
        goto loc_5871;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5854;
    ax = 0xfffd;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5871;
    memoryASet16(ds, 0x8240, 0x0000);
    goto loc_5871;
loc_5854: // 01ed:3984
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5871;
    ax = 0x0003;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5871;
    memoryASet16(ds, 0x8240, 0x0000);
loc_5871: // 01ed:39a1
    if (di != 0x0003)
        goto loc_5892;
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5885;
    memoryASet16(ds, 0x8240, 0x00b4);
    goto loc_5892;
loc_5885: // 01ed:39b5
    if ((short)memoryAGet16(ds, 0x604c) >= (short)0x0000)
        goto loc_5892;
    memoryASet16(ds, 0x8240, 0xff4c);
loc_5892: // 01ed:39c2
    if (memoryAGet16(ds, 0x8240) != 0x0000)
        goto loc_58b0;
    if ((short)memoryAGet16(ds, 0x604c) < (short)0x0000)
        goto loc_58a8;
    memoryASet16(ds, 0x8248, 0x0000);
    goto loc_58ff;
loc_58a8: // 01ed:39d8
    memoryASet16(ds, 0x8248, 0x0004);
    goto loc_58ff;
loc_58b0: // 01ed:39e0
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_58da;
    memoryASet16(ds, 0x8248, 0x0000);
    if ((short)di >= (short)0x0003)
        goto loc_58d8;
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    ax &= 0x0003;
    dx = memoryAGet16(ds, 0x8248);
    dx += ax;
    memoryASet16(ds, 0x8248, dx);
    goto loc_58f9;
loc_58d8: // 01ed:3a08
    goto loc_58f9;
loc_58da: // 01ed:3a0a
    memoryASet16(ds, 0x8248, 0x0004);
    if ((short)di >= (short)0x0003)
        goto loc_58f9;
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    ax &= 0x0003;
    dx = memoryAGet16(ds, 0x8248);
    dx += ax;
    memoryASet16(ds, 0x8248, dx);
loc_58f9: // 01ed:3a29
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, ax);
loc_58ff: // 01ed:3a2f
    if (memoryAGet16(ds, 0x8240) == 0x0000)
        goto loc_5931;
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    if (!(ax & 0x0001))
        goto loc_5931;
    if ((short)di >= (short)0x0003)
        goto loc_5931;
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x05;
    ax >>= cl;
    if (!(ax & 0x0001))
        goto loc_5928;
    ax = 0x001e;
    goto loc_592b;
loc_5928: // 01ed:3a58
    ax = 0x0004;
loc_592b: // 01ed:3a5b
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5931: // 01ed:3a61
    sub_4afa();
    sub_4b3d();
    memoryASet16(ss, bp - 2, ax);
    sub_5235();
    if (memoryAGet16(ss, bp - 2) & 0x0004)
        goto loc_594b;
    if (!(memoryAGet16(ss, bp - 2) & 0x0001))
        goto loc_5960;
loc_594b: // 01ed:3a7b
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    if (!(ax & 0x0001))
        goto loc_5960;
    ax = 0x0005;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5960: // 01ed:3a90
    if (memoryAGet16(ss, bp - 2) & 0x0002)
        goto loc_5980;
    if (memoryAGet16(ds, 0x8250) != 0x0000)
        goto loc_5980;
    memoryASet16(ds, 0x8252, 0x3c99);
    ax = 0x001b;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    goto loc_5a46;
loc_5980: // 01ed:3ab0
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_59ba;
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824e, ax);
    memoryASet16(ds, 0x8240, 0x0000);
    memoryASet16(ds, 0x824c, 0x0000);
    memoryASet16(ds, 0x824a, 0x0000);
    if ((short)memoryAGet16(ds, 0x604c) < (short)0x0000)
        goto loc_59ae;
    memoryASet16(ds, 0x8246, 0x0008);
    goto loc_59b4;
loc_59ae: // 01ed:3ade
    memoryASet16(ds, 0x8246, 0x000e);
loc_59b4: // 01ed:3ae4
    memoryASet16(ds, 0x8252, 0x3b8b);
loc_59ba: // 01ed:3aea
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_59f3;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_59f3;
    if (memoryAGet16(ds, 0x8258) == 0x0000)
        goto loc_59d4;
    sub_54a2();
    goto loc_59f3;
loc_59d4: // 01ed:3b04
    memoryASet16(ds, 0x824a, 0x0000);
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x8240, 0x0000);
    if (memoryAGet16(ds, 0xaa9a) == 0x0000)
        goto loc_59f3;
    memoryASet16(ds, 0x8252, 0x4054);
loc_59f3: // 01ed:3b23
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5a3b;
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5a3b;
    if (memoryAGet16(ds, 0x7fd2) != 0x0000)
        goto loc_5a3b;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_5a3b;
    memoryASet16(ds, 0x8252, 0x3e12);
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8252, 0x3e12);
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5a35;
    memoryASet16(ds, 0x8248, 0x0014);
    goto loc_5a3b;
loc_5a35: // 01ed:3b65
    memoryASet16(ds, 0x8248, 0x0015);
loc_5a3b: // 01ed:3b6b
    if (memoryAGet16(ds, 0x8250) == 0x0000)
        goto loc_5a46;
    memoryASet16(ds, 0x8250, memoryAGet16(ds, 0x8250) - 1);
loc_5a46: // 01ed:3b76
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5a5b() // 01ed:3b8b
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x824a);
    bx = 0x0006;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    dx = memoryAGet16(ds, 0x8246);
    dx += ax;
    memoryASet16(ds, 0x8248, dx);
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5a8c;
    ax = memoryAGet16(ds, 0x5b14);
    dx = 0x0006;
    imul16(dx);
    dx = memoryAGet16(ds, 0x824c);
    dx += ax;
    memoryASet16(ds, 0x824c, dx);
    goto loc_5a9d;
loc_5a8c: // 01ed:3bbc
    if ((short)memoryAGet16(ds, 0x824a) >= (short)0x000c)
        goto loc_5a9d;
    ax = 0x0018;
    ax -= memoryAGet16(ds, 0x824a);
    memoryASet16(ds, 0x824a, ax);
loc_5a9d: // 01ed:3bcd
    bx = memoryAGet16(ds, 0x7fca);
    bx--;
    if (bx > 0x0006)
        goto loc_5ae4;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_5aae;
        case 2: goto loc_5aae;
        case 4: goto loc_5aae;
        case 6: goto loc_5ae4;
        case 8: goto loc_5aca;
        case 10: goto loc_5aca;
        case 12: goto loc_5aca;
        default:
            stop();
    }
loc_5aae: // 01ed:3bde
    ax = memoryAGet16(ds, 0x5b14);
    ax <<= 1;
    dx = memoryAGet16(ds, 0x824e);
    dx += ax;
    memoryASet16(ds, 0x824e, dx);
    if ((short)dx <= (short)0x0078)
        goto loc_5ae4;
    memoryASet16(ds, 0x824e, 0x0078);
    goto loc_5ae4;
loc_5aca: // 01ed:3bfa
    ax = memoryAGet16(ds, 0x5b14);
    ax <<= 1;
    dx = memoryAGet16(ds, 0x824e);
    dx -= ax;
    memoryASet16(ds, 0x824e, dx);
    if ((short)dx >= (short)0xff88)
        goto loc_5ae4;
    memoryASet16(ds, 0x824e, 0xff88);
loc_5ae4: // 01ed:3c14
    memoryASet16(ds, 0x8240, 0x0000);
    ax = memoryAGet16(ds, 0x824a);
    ax += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, ax);
    if ((short)ax < (short)0x0024)
        goto loc_5b15;
    memoryASet16(ds, 0x8252, 0x3c99);
    ax = memoryAGet16(ds, 0x824c);
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) - ax);
    ax = memoryAGet16(ds, 0x824e);
    memoryASet16(ds, 0x8240, ax);
    ax = 0x0006;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5b15: // 01ed:3c45
    sub_4afa();
    sub_4b3d();
    sub_5235();
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5b58;
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5b58;
    memoryASet16(ds, 0x8252, 0x3e12);
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8252, 0x3e12);
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5b52;
    memoryASet16(ds, 0x8248, 0x0014);
    goto loc_5b58;
loc_5b52: // 01ed:3c82
    memoryASet16(ds, 0x8248, 0x0015);
loc_5b58: // 01ed:3c88
    bp = pop();
    sp += 2;
}
void sub_5b69() // 01ed:3c99
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    bx = memoryAGet16(ds, 0x7fca);
    bx--;
    if (bx > 0x0006)
        goto loc_5bac;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_5b7e;
        case 2: goto loc_5b7e;
        case 4: goto loc_5b7e;
        case 6: goto loc_5bac;
        case 8: goto loc_5b96;
        case 10: goto loc_5b96;
        case 12: goto loc_5b96;
        default:
            stop();
    }
loc_5b7e: // 01ed:3cae
    ax = 0x0002;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5bac;
    memoryASet16(ds, 0x7fca, 0x0008);
    goto loc_5bac;
loc_5b96: // 01ed:3cc6
    ax = 0xfffe;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5bac;
    memoryASet16(ds, 0x7fca, 0x0008);
loc_5bac: // 01ed:3cdc
    if (memoryAGet16(ds, 0x7fca) != 0x0008)
        goto loc_5bef;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5bd2;
    ax = 0xffff;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5bef;
    memoryASet16(ds, 0x8240, 0x0000);
    goto loc_5bef;
loc_5bd2: // 01ed:3d02
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5bef;
    ax = 0x0001;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5bef;
    memoryASet16(ds, 0x8240, 0x0000);
loc_5bef: // 01ed:3d1f
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5bfe;
    memoryASet16(ds, 0x8248, 0x000d);
    goto loc_5c04;
loc_5bfe: // 01ed:3d2e
    memoryASet16(ds, 0x8248, 0x0013);
loc_5c04: // 01ed:3d34
    if (memoryAGet16(ds, 0x8240) == 0x0000)
        goto loc_5c11;
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, ax);
loc_5c11: // 01ed:3d41
    sub_4afa();
    sub_4b3d();
    si = ax;
    if (ax & 0x0004)
        goto loc_5c23;
    if (!(ax & 0x0001))
        goto loc_5c38;
loc_5c23: // 01ed:3d53
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    if (!(ax & 0x0001))
        goto loc_5c38;
    ax = 0x0005;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5c38: // 01ed:3d68
    if (!(si & 0x0002))
        goto loc_5c50;
    memoryASet16(ds, 0x8252, 0x3867);
    ax = 0x0007;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    goto loc_5cd1;
loc_5c50: // 01ed:3d80
    if (!(si & 0x0008))
        goto loc_5c5f;
    ax = 0x0015;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5c5f: // 01ed:3d8f
    sub_5235();
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5c89;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_5c89;
    if (memoryAGet16(ds, 0x8258) == 0x0000)
        goto loc_5c7c;
    sub_54a2();
    goto loc_5c89;
loc_5c7c: // 01ed:3dac
    if (memoryAGet16(ds, 0xaa9a) == 0x0000)
        goto loc_5c89;
    memoryASet16(ds, 0x8252, 0x3ec8);
loc_5c89: // 01ed:3db9
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5cd1;
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5cd1;
    if (memoryAGet16(ds, 0x7fd2) != 0x0000)
        goto loc_5cd1;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_5cd1;
    memoryASet16(ds, 0x8252, 0x3e12);
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8252, 0x3e12);
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5ccb;
    memoryASet16(ds, 0x8248, 0x0014);
    goto loc_5cd1;
loc_5ccb: // 01ed:3dfb
    memoryASet16(ds, 0x8248, 0x0015);
loc_5cd1: // 01ed:3e01
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_5ce2() // 01ed:3e12
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x824a);
    ax += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, ax);
    if (memoryAGet16(ds, 0x824c) != 0x0000)
        goto loc_5d36;
    if ((short)ax <= (short)0x0001)
        goto loc_5d36;
    if (memoryAGet16(ds, 0xaac8) == 0x0000)
        goto loc_5d27;
    ax = 0x000c;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, 0xaac8, memoryAGet16(ds, 0xaac8) - 1);
    push(memoryAGet16(ds, 0x822a));
    push(memoryAGet16(ds, 0x8228));
    push(memoryAGet16(ds, 0x8226));
    push(memoryAGet16(ds, 0x8224));
    sub_658a();
    sp += 0x0008;
    goto loc_5d30;
loc_5d27: // 01ed:3e57
    ax = 0x0024;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5d30: // 01ed:3e60
    memoryASet16(ds, 0x824c, 0x0001);
loc_5d36: // 01ed:3e66
    if ((short)memoryAGet16(ds, 0x824a) <= (short)0x001e)
        goto loc_5d51;
    if (memoryAGet16(ds, 0x7fcc) != 0x0000)
        goto loc_5d51;
    if (memoryAGet16(ds, 0x7fce) != 0x0000)
        goto loc_5d51;
    memoryASet16(ds, 0x8252, 0x3867);
loc_5d51: // 01ed:3e81
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5d70;
    ax = 0xffff;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5d8d;
    memoryASet16(ds, 0x8240, 0x0000);
    goto loc_5d8d;
loc_5d70: // 01ed:3ea0
    if ((short)memoryAGet16(ds, 0x8240) >= (short)0x0000)
        goto loc_5d8d;
    ax = 0x0001;
    push(ax);
    sub_4a6a();
    sp++;
    sp++;
    if ((short)memoryAGet16(ds, 0x8240) <= (short)0x0000)
        goto loc_5d8d;
    memoryASet16(ds, 0x8240, 0x0000);
loc_5d8d: // 01ed:3ebd
    sub_4afa();
    sub_4b3d();
    sub_5235();
    bp = pop();
    sp += 2;
}
void sub_5d98() // 01ed:3ec8
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    ax = 0x7fca;
    push(ds);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 6;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 6;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    bx = memoryAGet16(ds, 0x7fca);
    bx--;
    if (bx > 0x0006)
        goto loc_5dfd;
    bx <<= 1;
    indirectJump(cs, memoryAGet16(cs, bx + 16454)); // 01ed:3efa;
  // gap 46 bytes
loc_5dfd: // 01ed:3f2d
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5e19;
    if ((short)memoryAGet16(ds, 0x8242) >= (short)0x0000)
        goto loc_5e19;
    ax = 0xffff;
    push(ax);
    ax = 0x00c8;
    push(ax);
    sub_4aaf();
    sp += 0x0004;
loc_5e19: // 01ed:3f49
    if (memoryAGet16(ds, 0x5daa) == 0x0000)
        goto loc_5e2d;
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5e2d;
    memoryASet16(ds, 0x8242, 0xff38);
loc_5e2d: // 01ed:3f5d
    if (memoryAGet16(ds, 0x8240) == 0x0000)
        goto loc_5e3a;
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, ax);
loc_5e3a: // 01ed:3f6a
    if ((short)memoryAGet16(ds, 0x604c) < (short)0x0000)
        goto loc_5e49;
    memoryASet16(ds, 0x8246, 0x0018);
    goto loc_5e4f;
loc_5e49: // 01ed:3f79
    memoryASet16(ds, 0x8246, 0x001a);
loc_5e4f: // 01ed:3f7f
    ax = memoryAGet16(ds, 0x8246);
    memoryASet16(ds, 0x8248, ax);
    sub_4afa();
    sub_4b3d();
    si = ax;
    if (ax & 0x0004)
        goto loc_5e67;
    if (!(ax & 0x0001))
        goto loc_5e7c;
loc_5e67: // 01ed:3f97
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    if (!(ax & 0x0001))
        goto loc_5e7c;
    ax = 0x0005;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5e7c: // 01ed:3fac
    if (!(si & 0x0002))
        goto loc_5e9a;
    memoryASet16(ds, 0x8252, 0x4054);
    memoryASet16(ds, 0x824a, 0x0000);
    ax = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x8240, 0x0000);
loc_5e9a: // 01ed:3fca
    if (!(si & 0x0008))
        goto loc_5ea9;
    ax = 0x0015;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5ea9: // 01ed:3fd9
    sub_5235();
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5ecc;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_5ecc;
    if (memoryAGet16(ds, 0x8258) == 0x0000)
        goto loc_5ec6;
    sub_54a2();
    goto loc_5ecc;
loc_5ec6: // 01ed:3ff6
    memoryASet16(ds, 0x8252, 0x3c99);
loc_5ecc: // 01ed:3ffc
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5f06;
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5f06;
    memoryASet16(ds, 0x8252, 0x3e12);
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8252, 0x3e12);
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5f00;
    memoryASet16(ds, 0x8248, 0x0014);
    goto loc_5f06;
loc_5f00: // 01ed:4030
    memoryASet16(ds, 0x8248, 0x0015);
loc_5f06: // 01ed:4036
    if (memoryAGet16(ds, 0x8250) == 0x0000)
        goto loc_5f11;
    memoryASet16(ds, 0x8250, memoryAGet16(ds, 0x8250) - 1);
loc_5f11: // 01ed:4041
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_5f24() // 01ed:4054
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x8240, ax);
    memoryASet16(ds, 0x823c, ax);
    ax = memoryAGet16(ds, 0x8246);
    ax++;
    memoryASet16(ds, 0x8248, ax);
    ax = memoryAGet16(ds, 0x824a);
    ax += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, ax);
    if ((short)ax <= (short)0x0016)
        goto loc_5f66;
    memoryASet16(ds, 0x8252, 0x3ec8);
    memoryASet16(ds, 0x8250, 0x0000);
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) - 0x00c8);
    ax = memoryAGet16(ds, 0x824c);
    memoryASet16(ds, 0x8240, ax);
    ax = 0x0006;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_5f66: // 01ed:4096
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5f7a;
    if (memoryAGet16(ds, 0x7fd4) != 0x0000)
        goto loc_5f7a;
    memoryASet16(ds, 0x8252, 0x3867);
loc_5f7a: // 01ed:40aa
    if (memoryAGet16(ds, 0x7fcc) == 0x0000)
        goto loc_5fb4;
    if (memoryAGet16(ds, 0x7fce) == 0x0000)
        goto loc_5fb4;
    memoryASet16(ds, 0x8252, 0x3e12);
    ax = 0;
    memoryASet16(ds, 0x823c, ax);
    memoryASet16(ds, 0x824c, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8252, 0x3e12);
    if ((short)memoryAGet16(ds, 0x604c) <= (short)0x0000)
        goto loc_5fae;
    memoryASet16(ds, 0x8248, 0x0014);
    goto loc_5fb4;
loc_5fae: // 01ed:40de
    memoryASet16(ds, 0x8248, 0x0015);
loc_5fb4: // 01ed:40e4
    sub_4b3d();
    memoryASet16(ds, 0x8250, 0x0000);
    bp = pop();
    sp += 2;
}
void sub_60c8() // 01ed:41f8
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x824a);
    ax += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, ax);
    if ((short)ax < (short)0x00c8)
        goto loc_60ef;
    memoryASet16(ds, 0x824a, 0xfc19);
    sub_df9e();
    ax += 0xff80;
    memoryASet16(ds, 0x8240, ax);
    memoryASet16(ds, 0x8242, 0xfe70);
loc_60ef: // 01ed:421f
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    ax &= 0x0001;
    ax += 0x0016;
    memoryASet16(ds, 0x8248, ax);
    ax = memoryAGet16(ds, 0x8240);
    imul16(memoryAGet16(ds, 0x5b14));
    memoryASet16(ds, 0x823c, ax);
    ax = memoryAGet16(ds, 0x8242);
    imul16(memoryAGet16(ds, 0x5b14));
    memoryASet16(ds, 0x823e, ax);
    ax = memoryAGet16(ds, 0x823a);
    dx = memoryAGet16(ds, 0x8238);
    if ((short)ax > (short)memoryAGet16(ds, 0x6ed6))
        goto loc_612e;
    if ((short)ax < (short)memoryAGet16(ds, 0x6ed6))
        goto loc_6128;
    if (dx >= memoryAGet16(ds, 0x6ed4))
        goto loc_612e;
loc_6128: // 01ed:4258
    memoryASet16(ds, 0x8220, 0x0000);
loc_612e: // 01ed:425e
    bp = pop();
    sp += 2;
}
void sub_6130() // 01ed:4260
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x5daa) != 0x0000)
        goto loc_617a;
    if (memoryAGet16(ds, 0x8256) != 0x0000)
        goto loc_617a;
    memoryASet16(ds, 0x6f0c, 0x41f8);
    memoryASet16(ds, 0x6f0e, 0x3360);
    flags.carry = (memoryAGet16(ds, 0x6ee2) + 0x0800) >= 0x10000;
    memoryASet16(ds, 0x6ee2, memoryAGet16(ds, 0x6ee2) + 0x0800);
    memoryASet16(ds, 0x6ee4, memoryAGet16(ds, 0x6ee4) + (0x0000 + flags.carry));
    ax = 0;
    memoryASet16(ds, 0x6efc, ax);
    memoryASet16(ds, 0x6efa, ax);
    ax = 0;
    memoryASet16(ds, 0x6efc, ax);
    memoryASet16(ds, 0x6efa, ax);
    memoryASet16(ds, 0x6f04, ax);
    memoryASet16(ds, 0x6f02, 0x0016);
    ax = 0x0008;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_617a: // 01ed:42aa
    bp = pop();
    sp += 2;
}
void sub_617c() // 01ed:42ac
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x8252, 0x41f8);
    memoryASet16(ds, 0x8254, 0x3360);
    flags.carry = (memoryAGet16(ds, 0x8228) + 0x0800) >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + 0x0800);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (0x0000 + flags.carry));
    ax = 0;
    memoryASet16(ds, 0x6efc, ax);
    memoryASet16(ds, 0x8240, ax);
    ax = 0;
    memoryASet16(ds, 0x6efc, ax);
    memoryASet16(ds, 0x6efa, ax);
    memoryASet16(ds, 0x824a, ax);
    memoryASet16(ds, 0x8248, 0x0016);
    ax = 0x0008;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_61ba() // 01ed:42ea
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6f0c) != 0x41f8)
        goto loc_61cd;
    goto loc_645a;
loc_61cd: // 01ed:42fd
    memoryASet16(ds, 0x8258, 0x0000);
    dx = memoryAGet16(ds, 0x6ee8);
    ax = memoryAGet16(ds, 0x6ee6);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 2, ax);
    dx = memoryAGet16(ds, 0x6ef0);
    ax = memoryAGet16(ds, 0x6eee);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 6, ax);
    dx = memoryAGet16(ds, 0x6eec);
    ax = memoryAGet16(ds, 0x6eea);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ds, 0x6ef4);
    ax = memoryAGet16(ds, 0x6ef2);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 8, ax);
    di = memoryAGet16(ss, bp - 2);
    goto loc_6452;
loc_6215: // 01ed:4345
    si = memoryAGet16(ss, bp - 4);
    goto loc_6449;
loc_621b: // 01ed:434b
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 12, ax);
    bx = memoryAGet16(ss, bp - 12);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1390);
    memoryASet16(ss, bp - 10, ax);
    if (ax)
        goto loc_6244;
    goto loc_6448;
loc_6244: // 01ed:4374
    bx = memoryAGet16(ss, bp - 10);
    bx--;
    if (bx <= 0x0019)
        goto loc_6250;
    goto loc_6448;
loc_6250: // 01ed:4380
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_6257;
        case 2: goto loc_625d;
        case 4: goto loc_625d;
        case 6: goto loc_625d;
        case 8: goto loc_625d;
        case 10: goto loc_62b2;
        case 12: goto loc_62b2;
        case 14: goto loc_62b2;
        case 16: goto loc_62b2;
        case 18: goto loc_62b2;
        case 20: goto loc_6310;
        case 22: goto loc_6310;
        case 24: goto loc_6310;
        case 26: goto loc_6310;
        case 28: goto loc_636a;
        case 30: goto loc_636a;
        case 32: goto loc_63a2;
        case 34: goto loc_63cf;
        case 36: goto loc_63cf;
        case 38: goto loc_63cf;
        case 40: goto loc_63cf;
        case 42: goto loc_63fa;
        case 44: goto loc_6432;
        case 46: goto loc_6442;
        case 48: goto loc_6432;
        case 50: goto loc_6432;
        default:
            stop();
    }
loc_6257: // 01ed:4387
    sub_6130();
    goto loc_6448;
loc_625d: // 01ed:438d
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43674) == 0x0000)
        goto loc_6274;
    push(si);
    push(di);
    sub_46c8();
    sp += 0x0004;
    goto loc_6448;
loc_6274: // 01ed:43a4
    if ((short)memoryAGet16(ds, 0x6ef6) <= (short)0x0000)
        goto loc_6293;
    ax = memoryAGet16(ds, 0x6ee0);
    dx = memoryAGet16(ds, 0x6ede);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ede, dx);
    memoryASet16(ds, 0x6ee0, ax);
    goto loc_6448;
loc_6293: // 01ed:43c3
    ax = memoryAGet16(ds, 0x6ee0);
    dx = memoryAGet16(ds, 0x6ede);
    flags.carry = (dx + 0x1000) >= 0x10000;
    dx += 0x1000;
    ax += 0x0000 + flags.carry;
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ede, dx);
    memoryASet16(ds, 0x6ee0, ax);
    goto loc_6448;
loc_62b2: // 01ed:43e2
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    push(memoryAGet16(ds, bx + 8218));
    sub_2c22();
    sp++;
    sp++;
    ax = 0x0009;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    if (memoryAGet16(es, bx) >= 0x0131)
        goto loc_62f8;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    goto loc_6448;
loc_62f8: // 01ed:4428
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x0114);
    goto loc_6448;
loc_6310: // 01ed:4440
    if (memoryAGet16(ss, bp - 10) != 0x000b)
        goto loc_631c;
    memoryASet16(ds, 0xaa94, 0x0001);
loc_631c: // 01ed:444c
    if (memoryAGet16(ss, bp - 10) != 0x000c)
        goto loc_6328;
    memoryASet16(ds, 0xaa9c, 0x0001);
loc_6328: // 01ed:4458
    if (memoryAGet16(ss, bp - 10) != 0x000d)
        goto loc_6334;
    memoryASet16(ds, 0xaa96, 0x0001);
loc_6334: // 01ed:4464
    if (memoryAGet16(ss, bp - 10) != 0x000e)
        goto loc_6340;
    memoryASet16(ds, 0xaa98, 0x0001);
loc_6340: // 01ed:4470
    ax = 0x2710;
    push(ax);
    sub_2c22();
    sp++;
    sp++;
    ax = 0x000b;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    goto loc_6448;
loc_636a: // 01ed:449a
    if (memoryAGet16(ss, bp - 10) != 0x000f)
        goto loc_6375;
    memoryASet16(ds, 0xaac8, memoryAGet16(ds, 0xaac8) + 0x0005);
loc_6375: // 01ed:44a5
    if (memoryAGet16(ss, bp - 10) != 0x0010)
        goto loc_6381;
    memoryASet16(ds, 0xaa9a, 0x0001);
loc_6381: // 01ed:44b1
    ax = 0x000a;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    goto loc_6448;
loc_63a2: // 01ed:44d2
    if (memoryAGet16(ds, 0x6f0c) == 0x3867)
        goto loc_63ad;
    goto loc_6448;
loc_63ad: // 01ed:44dd
    ax = 0x000f;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, 0x6f0c, 0x40ef);
    memoryASet16(ds, 0x6f0e, 0x3360);
    ax = di;
    ax++;
    ax++;
    memoryASet16(ds, 0x6f04, ax);
    memoryASet16(ds, 0x6f06, si);
    goto loc_6448;
loc_63cf: // 01ed:44ff
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    memoryASet16(ds, bx + 43642, 0x0001);
    ax = 0x0020;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x008f);
    goto loc_6448;
loc_63fa: // 01ed:452a
    sub_43c4();
    if (memoryAGet16(ds, 0x8304) != 0x000b)
        goto loc_641b;
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x01b2);
    goto loc_6448;
loc_641b: // 01ed:454b
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x013b);
    goto loc_6448;
loc_6432: // 01ed:4562
    memoryASet16(ds, 0x8258, 0x0001);
    memoryASet16(ds, 0x8218, di);
    memoryASet16(ds, 0x821a, si);
    goto loc_6448;
loc_6442: // 01ed:4572
    memoryASet16(ds, 0x6c60, 0x0002);
loc_6448: // 01ed:4578
    si++;
loc_6449: // 01ed:4579
    if ((short)si > (short)memoryAGet16(ss, bp - 8))
        goto loc_6451;
    goto loc_621b;
loc_6451: // 01ed:4581
    di++;
loc_6452: // 01ed:4582
    if ((short)di > (short)memoryAGet16(ss, bp - 6))
        goto loc_645a;
    goto loc_6215;
loc_645a: // 01ed:458a
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_658a() // 01ed:46ba
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    sub_4805();
    si = ax;
    memoryASet16(ds, si, 0x000a);
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    flags.carry = (dx + 0x0900) >= 0x10000;
    dx += 0x0900;
    ax += 0x0000 + flags.carry;
    memoryASet16(ds, si + 8, dx);
    memoryASet16(ds, si + 10, ax);
    memoryASet16(ds, si + 50, 0x4808);
    memoryASet16(ds, si + 34, 0x0000);
    memoryASet16(ds, si + 52, 0x4849);
    memoryASet16(ds, si + 40, 0x006c);
    if ((short)memoryAGet16(ds, 0x604c) < (short)0x0000)
        goto loc_6646;
    memoryASet16(ds, si + 32, 0x0190);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    cl = 0x0c;
    sub_10042();
    dx = memoryAGet16(ss, bp + 10);
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    cl = 0x0c;
    sub_10042();
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += 0x0000 + flags.carry;
    push(ax);
    ax = memoryAGet16(ds, 0x6c08);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = pop();
    bx = pop();
    sub_10433();
    dx = pop();
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 3834) != 0x0000)
        goto loc_6619;
    goto loc_66b5;
loc_6619: // 01ed:4749
    ax = 0x0025;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, si, 0x000d);
    memoryASet16(ds, si + 50, 0x47e8);
    memoryASet16(ds, si + 42, 0x0000);
    sub_df9e();
    if ((short)ax <= (short)0x0080)
        goto loc_663f;
    memoryASet16(ds, si + 40, 0x006e);
    goto loc_66b5;
loc_663f: // 01ed:476f
    memoryASet16(ds, si + 40, 0x006f);
    goto loc_66b5;
loc_6646: // 01ed:4776
    memoryASet16(ds, si + 32, 0xfe70);
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    cl = 0x0c;
    sub_10042();
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += 0x0000 + flags.carry;
    push(ax);
    ax = memoryAGet16(ds, 0x6c08);
    push(dx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = pop();
    bx = pop();
    sub_10433();
    dx = memoryAGet16(ss, bp + 6);
    push(ax);
    ax = memoryAGet16(ss, bp + 4);
    cl = 0x0c;
    sub_10042();
    dx = pop();
    dx += ax;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 6278) == 0x0000)
        goto loc_66b5;
    ax = 0x0025;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, si, 0x000d);
    memoryASet16(ds, si + 50, 0x47e8);
    memoryASet16(ds, si + 42, 0x0000);
    sub_df9e();
    if ((short)ax <= (short)0x0080)
        goto loc_66b0;
    memoryASet16(ds, si + 40, 0x006e);
    goto loc_66b5;
loc_66b0: // 01ed:47e0
    memoryASet16(ds, si + 40, 0x006f);
loc_66b5: // 01ed:47e5
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_6a39() // 01ed:4b69
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0012;
    push(si);
    push(di);
    memoryASet16(ds, 0x6eda, 0x0001);
    memoryASet16(ds, 0x6f0c, 0x3867);
    memoryASet16(ds, 0x6f0e, 0x45c4);
    ax = 0;
    memoryASet16(ds, 0x6efc, ax);
    memoryASet16(ds, 0x6efa, ax);
    memoryASet16(ds, 0x6f02, 0x0004);
    memoryASet16(ds, 0x6edc, 0x0001);
    memoryASet16(ds, 0x5db4, 0x0001);
    memoryASet16(ds, 0x8216, 0x0000);
    memoryASet16(ss, bp - 2, 0x0001);
    memoryASet16(ds, 0x604c, 0x0001);
    ax = 0;
    memoryASet16(ds, 0x5b14, ax);
    dx = 0;
    memoryASet16(ds, 0x563e, ax);
    memoryASet16(ds, 0x5640, dx);
    memoryASet16(ds, 0x5135, ax);
    memoryASet16(ds, 0x5137, dx);
    ax = 0;
    memoryASet16(ds, 0x8256, ax);
    memoryASet16(ds, 0x5daa, ax);
    memoryASet16(ds, 0x6c60, ax);
    push(memoryAGet16(ss, bp + 4));
    sub_34bb();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x6ee0);
    dx = memoryAGet16(ds, 0x6ede);
    flags.carry = (dx + 0x6000) >= 0x10000;
    dx += 0x6000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ds, 0x6ee4);
    dx = memoryAGet16(ds, 0x6ee2);
    flags.carry = (dx + 0xb000) >= 0x10000;
    dx += 0xb000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax > (short)memoryAGet16(ds, 0x564c))
        goto loc_6af3;
    if ((short)ax < (short)memoryAGet16(ds, 0x564c))
        goto loc_6ae5;
    if (dx >= memoryAGet16(ds, 0x564a))
        goto loc_6af3;
loc_6ae5: // 01ed:4c15
    ax = memoryAGet16(ds, 0x564c);
    dx = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
loc_6af3: // 01ed:4c23
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax > (short)memoryAGet16(ds, 0x5650))
        goto loc_6b16;
    if ((short)ax < (short)memoryAGet16(ds, 0x5650))
        goto loc_6b08;
    if (dx >= memoryAGet16(ds, 0x564e))
        goto loc_6b16;
loc_6b08: // 01ed:4c38
    ax = memoryAGet16(ds, 0x5650);
    dx = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
loc_6b16: // 01ed:4c46
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc0))
        goto loc_6b39;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc0))
        goto loc_6b2b;
    if (dx <= memoryAGet16(ds, 0x7fbe))
        goto loc_6b39;
loc_6b2b: // 01ed:4c5b
    ax = memoryAGet16(ds, 0x7fc0);
    dx = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
loc_6b39: // 01ed:4c69
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc4))
        goto loc_6b5c;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc4))
        goto loc_6b4e;
    if (dx <= memoryAGet16(ds, 0x7fc2))
        goto loc_6b5c;
loc_6b4e: // 01ed:4c7e
    ax = memoryAGet16(ds, 0x7fc4);
    dx = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
loc_6b5c: // 01ed:4c8c
    sub_2109();
    sub_8b5d();
    memoryASet16(ds, 0x821e, 0x0001);
    sub_d606();
    sub_2159();
    sub_2159();
    sub_8b19();
    dx = memoryAGet16(ds, 0x6ed2);
    ax = memoryAGet16(ds, 0x6ed0);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5656, ax);
    dx = memoryAGet16(ds, 0x6ed6);
    ax = memoryAGet16(ds, 0x6ed4);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5b12, ax);
loc_6b92: // 01ed:4cc2
    sub_2109();
    ax = 0x7fca;
    push(ds);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 18;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 18;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    si = 0x6eda;
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_6cb9;
loc_6bbf: // 01ed:4cef
    if (memoryAGet16(ds, si) != 0x0000)
        goto loc_6bc7;
    goto loc_6cb3;
loc_6bc7: // 01ed:4cf7
    ax = 0x8220;
    push(ds);
    push(ax);
    push(ds);
    push(si);
    cx = 0x0036;
    sub_1016b();
    if (memoryAGet16(ds, 0x8222) == 0x0000)
        goto loc_6c18;
    if (memoryAGet16(ss, bp - 8) == 0x0000)
        goto loc_6beb;
    sub_5166();
    if (!ax)
        goto loc_6beb;
    goto loc_6ca6;
loc_6beb: // 01ed:4d1b
    sub_490b();
    ax = 0;
    memoryASet16(ds, 0x823e, ax);
    memoryASet16(ds, 0x823c, ax);
    switch (memoryAGet16(ds, 0x8252))
    {
        case 0x19d3: sub_38a3(); break;
        case 0x3867: sub_5737(); break;
        case 0x3b8b: sub_5a5b(); break;
        case 0x3c99: sub_5b69(); break;
        case 0x3e12: sub_5ce2(); break;
        case 0x3ec8: sub_5d98(); break;
        case 0x4054: sub_5f24(); break;
        case 0x41f8: sub_60c8(); break;
        case 0x194f: sub_381f(); break;
        default:
            stop();
    }
    ax = memoryAGet16(ds, 0x823c);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8224) + ax) >= 0x10000;
    memoryASet16(ds, 0x8224, memoryAGet16(ds, 0x8224) + ax);
    memoryASet16(ds, 0x8226, memoryAGet16(ds, 0x8226) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x823e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8228) + ax) >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + ax);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (dx + flags.carry));
    sub_490b();
    goto loc_6ca6;
loc_6c18: // 01ed:4d48
    dx = memoryAGet16(ds, 0x8226);
    ax = memoryAGet16(ds, 0x8224);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ds, 0x822a);
    ax = memoryAGet16(ds, 0x8228);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ds, 0x5656);
    ax += 0xfffe;
    if ((short)ax >= (short)memoryAGet16(ss, bp - 4))
        goto loc_6ca6;
    ax = memoryAGet16(ds, 0x5b12);
    ax += 0xfffe;
    if ((short)ax >= (short)memoryAGet16(ss, bp - 6))
        goto loc_6ca6;
    ax = memoryAGet16(ds, 0x5656);
    ax += 0x0017;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 4))
        goto loc_6ca6;
    ax = memoryAGet16(ds, 0x5b12);
    ax += 0x000c;
    if ((short)ax <= (short)memoryAGet16(ss, bp - 6))
        goto loc_6ca6;
    memoryASet16(ds, 0x8222, 0x0001);
    if (memoryAGet16(ds, 0x8252) != 0x1a2c)
        goto loc_6c7c;
    memoryASet16(ds, 0x8252, 0x19d3);
    memoryASet16(ds, 0x824a, 0x0000);
loc_6c7c: // 01ed:4dac
    sub_490b();
    ax = 0;
    memoryASet16(ds, 0x823e, ax);
    memoryASet16(ds, 0x823c, ax);
    switch (memoryAGet16(ds, 0x8252))
    {
        case 0x19d3: sub_38a3(); break;
        case 0x3867: sub_5737(); break;
        case 0x3b8b: sub_5a5b(); break;
        case 0x3c99: sub_5b69(); break;
        case 0x3e12: sub_5ce2(); break;
        case 0x3ec8: sub_5d98(); break;
        case 0x4054: sub_5f24(); break;
        case 0x41f8: sub_60c8(); break;
        case 0x194f: sub_381f(); break;
        default:
            stop();
    }
    ax = memoryAGet16(ds, 0x823c);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8224) + ax) >= 0x10000;
    memoryASet16(ds, 0x8224, memoryAGet16(ds, 0x8224) + ax);
    memoryASet16(ds, 0x8226, memoryAGet16(ds, 0x8226) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x823e);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x8228) + ax) >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + ax);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (dx + flags.carry));
    sub_490b();
loc_6ca6: // 01ed:4dd6
    push(ds);
    push(si);
    ax = 0x8220;
    push(ds);
    push(ax);
    cx = 0x0036;
    sub_1016b();
loc_6cb3: // 01ed:4de3
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    si += 0x0036;
loc_6cb9: // 01ed:4de9
    ax = memoryAGet16(ss, bp - 8);
    if ((short)ax >= (short)memoryAGet16(ds, 0x5db4))
        goto loc_6cc5;
    goto loc_6bbf;
loc_6cc5: // 01ed:4df5
    sub_52e8();
    si = 0x6eda;
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_6d2f;
loc_6cd2: // 01ed:4e02
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_6d29;
    if (memoryAGet16(ds, si + 2) == 0x0000)
        goto loc_6d29;
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0036;
    imul16(dx);
    ax += 0x6f10;
    di = ax;
    ax = memoryAGet16(ss, bp - 8);
    ax++;
    memoryASet16(ss, bp - 10, ax);
    goto loc_6d20;
loc_6cf3: // 01ed:4e23
    if (memoryAGet16(ds, di) == 0x0000)
        goto loc_6d1a;
    if (memoryAGet16(ds, di + 2) == 0x0000)
        goto loc_6d1a;
    push(di);
    push(si);
    sub_488d();
    sp += 0x0004;
    if (!ax)
        goto loc_6d1a;
    push(di);
    push(si);
    callIndirect(cs, memoryAGet16(ds, si + 52)); // 01ed:4e3c;
    sp += 0x0004;
    push(si);
    push(di);
    callIndirect(cs, memoryAGet16(ds, di + 52)); // 01ed:4e44;
    sp += 0x0004;
loc_6d1a: // 01ed:4e4a
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
    di += 0x0036;
loc_6d20: // 01ed:4e50
    ax = memoryAGet16(ss, bp - 10);
    if ((short)ax < (short)memoryAGet16(ds, 0x5db4))
        goto loc_6cf3;
loc_6d29: // 01ed:4e59
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    si += 0x0036;
loc_6d2f: // 01ed:4e5f
    ax = memoryAGet16(ss, bp - 8);
    if ((short)ax < (short)memoryAGet16(ds, 0x5db4))
        goto loc_6cd2;
    dx = memoryAGet16(ds, 0x6ed2);
    ax = memoryAGet16(ds, 0x6ed0);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5656, ax);
    dx = memoryAGet16(ds, 0x6ed6);
    ax = memoryAGet16(ds, 0x6ed4);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5b12, ax);
    ax = memoryAGet16(ds, 0x5db4);
    dx = 0x0036;
    imul16(dx);
    ax += 0x6ea4;
    si = ax;
    ax = memoryAGet16(ds, 0x5db4);
    ax--;
    memoryASet16(ss, bp - 8, ax);
    goto loc_6d92;
loc_6d6c: // 01ed:4e9c
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_6d8c;
    if (memoryAGet16(ds, si + 2) == 0x0000)
        goto loc_6d8c;
    push(memoryAGet16(ds, si + 40));
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_2195();
    sp += 0x000a;
loc_6d8c: // 01ed:4ebc
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) - 1);
    si -= 0x0036;
loc_6d92: // 01ed:4ec2
    if ((short)memoryAGet16(ss, bp - 8) >= (short)0x0000)
        goto loc_6d6c;
    sub_61ba();
    memoryASet16(ss, bp - 12, 0x7fd6);
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_6dbd;
loc_6da7: // 01ed:4ed7
    bx = memoryAGet16(ss, bp - 12);
    if (memoryAGet16(ds, bx + 8) == 0x0000)
        goto loc_6db6;
    push(bx);
    callIndirect(cs, memoryAGet16(ds, bx + 34)); // 01ed:4ee1;
    sp++;
    sp++;
loc_6db6: // 01ed:4ee6
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 0x0024);
loc_6dbd: // 01ed:4eed
    ax = memoryAGet16(ss, bp - 8);
    if ((short)ax < (short)memoryAGet16(ds, 0x8216))
        goto loc_6da7;
    sub_2159();
    ax = 0x7fd0;
    push(ds);
    push(ax);
    ax = 0x7fca;
    push(ds);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    sub_30c0();
    sub_2b21();
    if (!ax)
        goto loc_6df1;
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
loc_6df1: // 01ed:4f21
    if (memoryAGet16(ds, 0x6ebc) == 0x0000)
        goto loc_6dfc;
    ax = 0;
    goto loc_6e73;
loc_6dfc: // 01ed:4f2c
    if (memoryAGet16(ds, 0x6c60) != 0x0000)
        goto loc_6e0d;
    if (memoryAGet16(ds, 0x6eda) == 0x0000)
        goto loc_6e0d;
    goto loc_6b92;
loc_6e0d: // 01ed:4f3d
    sub_de4f();
    sub_8b5d();
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_6e28;
loc_6e1a: // 01ed:4f4a
    bx = memoryAGet16(ss, bp - 4);
    bx <<= 1;
    memoryASet16(ds, bx + 43678, 0x0000);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_6e28: // 01ed:4f58
    if ((short)memoryAGet16(ss, bp - 4) < (short)0x0004)
        goto loc_6e1a;
    if (memoryAGet16(ds, 0x6c60) != 0x0000)
        goto loc_6e70;
    ax = memoryAGet16(ss, bp + 4);
    if (ax == 0x0008)
        goto loc_6e62;
    if ((short)ax > (short)0x0008)
        goto loc_6e4b;
    if (ax == 0x0003)
        goto loc_6e52;
    if (ax == 0x0004)
        goto loc_6e5a;
    goto loc_6e70;
loc_6e4b: // 01ed:4f7b
    if (ax == 0x0010)
        goto loc_6e6a;
    goto loc_6e70;
loc_6e52: // 01ed:4f82
    memoryASet16(ds, 0xaa9c, 0x0000);
    goto loc_6e70;
loc_6e5a: // 01ed:4f8a
    memoryASet16(ds, 0xaa94, 0x0000);
    goto loc_6e70;
loc_6e62: // 01ed:4f92
    memoryASet16(ds, 0xaa96, 0x0000);
    goto loc_6e70;
loc_6e6a: // 01ed:4f9a
    memoryASet16(ds, 0xaa98, 0x0000);
loc_6e70: // 01ed:4fa0
    ax = memoryAGet16(ds, 0x6c60);
loc_6e73: // 01ed:4fa3
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_6e79() // 01ed:4fa9
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0032;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    ax = 0x0009;
    push(ax);
    ax = 0x001c;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    ax = bp - 8;
    push(ax);
    ax = bp - 6;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_76e1();
    sp += 0x0006;
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x01f4)
        goto loc_6eba;
    memoryASet16(ss, bp - 2, 0x0001);
loc_6eba: // 01ed:4fea
    ax = bp - 8;
    push(ax);
    ax = bp - 6;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_76e1();
    sp += 0x0006;
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x01f4)
        goto loc_6ed8;
    memoryASet16(ss, bp - 2, 0x0002);
loc_6ed8: // 01ed:5008
    ax = 0x2559;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2574;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x258f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x25aa;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x25b7;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    si = 0x0009;
loc_6f08: // 01ed:5038
    push(si);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0003;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    si++;
    ax = si;
    if (ax != 0x000c)
        goto loc_6f31;
    si = 0x0009;
loc_6f31: // 01ed:5061
    ax = bp - 16;
    push(ax);
    ax = bp - 14;
    push(ax);
    push(di);
    sub_76e1();
    sp += 0x0006;
    ax = bp - 26;
    push(ss);
    push(ax);
    push(di);
    push(ss);
    ax = bp - 32;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 32;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet(ds, 0x502d) == 0x00)
        goto loc_6f66;
    goto loc_70c1;
loc_6f66: // 01ed:5096
    if (memoryAGet16(ss, bp - 24) != 0x0001)
        goto loc_6f08;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
loc_6f84: // 01ed:50b4
    ax = bp - 26;
    push(ss);
    push(ax);
    push(di);
    push(ss);
    ax = bp - 38;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 38;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 24) != 0x0000)
        goto loc_6f84;
    ax = 0x0002;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x25d2;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x25f0;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x25fe;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
loc_6fca: // 01ed:50fa
    push(si);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0003;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    si++;
    ax = si;
    if (ax != 0x000c)
        goto loc_6ff3;
    si = 0x0009;
loc_6ff3: // 01ed:5123
    ax = bp - 20;
    push(ax);
    ax = bp - 18;
    push(ax);
    push(di);
    sub_76e1();
    sp += 0x0006;
    ax = bp - 26;
    push(ss);
    push(ax);
    push(di);
    push(ss);
    ax = bp - 44;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 44;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet(ds, 0x502d) == 0x00)
        goto loc_7028;
    goto loc_70c1;
loc_7028: // 01ed:5158
    if (memoryAGet16(ss, bp - 24) != 0x0001)
        goto loc_6fca;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
loc_7046: // 01ed:5176
    ax = bp - 26;
    push(ss);
    push(ax);
    push(di);
    push(ss);
    ax = bp - 50;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 50;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 24) != 0x0000)
        goto loc_7046;
    ax = memoryAGet16(ss, bp - 18);
    ax -= memoryAGet16(ss, bp - 14);
    bx = 0x0004;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 20);
    ax -= memoryAGet16(ss, bp - 16);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet16(ss, bp - 12, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ss, bp - 14);
    ax += memoryAGet16(ss, bp - 10);
    memoryASet16(ds, bx + 33386, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ss, bp - 18);
    ax -= memoryAGet16(ss, bp - 10);
    memoryASet16(ds, bx + 33392, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ss, bp - 16);
    ax += memoryAGet16(ss, bp - 12);
    memoryASet16(ds, bx + 33398, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ss, bp - 20);
    ax -= memoryAGet16(ss, bp - 12);
    memoryASet16(ds, bx + 33404, ax);
    memoryASet16(ds, 0x833e, 0x0002);
loc_70c1: // 01ed:51f1
    sub_7b0a();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_70ca() // 01ed:51fa
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    ax = si;
    ax &= 0x007f;
    si = ax;
    if (ax != 0x0001)
        goto loc_70ec;
    ax = 0x2619;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_70ec: // 01ed:521c
    if (si != 0x000e)
        goto loc_70fd;
    ax = 0x261d;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_70fd: // 01ed:522d
    if (si != 0x000f)
        goto loc_710e;
    ax = 0x2622;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_710e: // 01ed:523e
    if (si != 0x001d)
        goto loc_711f;
    ax = 0x2626;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_711f: // 01ed:524f
    if (si != 0x002a)
        goto loc_7130;
    ax = 0x262b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_7130: // 01ed:5260
    if (si != 0x0039)
        goto loc_7141;
    ax = 0x2632;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_7141: // 01ed:5271
    if (si != 0x003a)
        goto loc_7152;
    ax = 0x2638;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_7152: // 01ed:5282
    if ((short)si < (short)0x003b)
        goto loc_7185;
    if ((short)si > (short)0x0044)
        goto loc_7185;
    ax = 0x263f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x000a;
    push(ax);
    ax = bp - 4;
    push(ax);
    ax = si;
    ax += 0xffc6;
    push(ax);
    sub_f25a();
    sp += 0x0006;
    ax = bp - 4;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_7185: // 01ed:52b5
    if (si != 0x0057)
        goto loc_7196;
    ax = 0x2641;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_7196: // 01ed:52c6
    if (si != 0x0059)
        goto loc_71a7;
    ax = 0x2645;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71a7: // 01ed:52d7
    if (si != 0x0046)
        goto loc_71b8;
    ax = 0x2649;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71b8: // 01ed:52e8
    if (si != 0x001c)
        goto loc_71c9;
    ax = 0x2650;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71c9: // 01ed:52f9
    if (si != 0x0036)
        goto loc_71da;
    ax = 0x2656;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71da: // 01ed:530a
    if (si != 0x0037)
        goto loc_71eb;
    ax = 0x265d;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71eb: // 01ed:531b
    if (si != 0x0038)
        goto loc_71fc;
    ax = 0x2663;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_71fc: // 01ed:532c
    if (si != 0x0047)
        goto loc_720d;
    ax = 0x2667;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
  // gap 1 bytes
loc_720d: // 01ed:533d
    if (si != 0x0049)
        goto loc_721d;
    ax = 0x266c;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_721d: // 01ed:534d
    if (si != 0x004f)
        goto loc_722d;
    ax = 0x2671;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_722d: // 01ed:535d
    if (si != 0x0051)
        goto loc_723d;
    ax = 0x2675;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_723d: // 01ed:536d
    if (si != 0x0052)
        goto loc_724d;
    ax = 0x267a;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_724d: // 01ed:537d
    if (si != 0x0053)
        goto loc_725d;
    ax = 0x267e;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_725d: // 01ed:538d
    if (si != 0x0045)
        goto loc_726d;
    ax = 0x2682;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    goto loc_728b;
loc_726d: // 01ed:539d
    al = memoryAGet(ds, si + 9294);
    cbw();
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(ax);
    sub_d7b0();
    sp += 0x0006;
loc_728b: // 01ed:53bb
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7290() // 01ed:53c0
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    push(di);
    ax = 0x000e;
    push(ax);
    ax = 0x0016;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x2688;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x269b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26ad;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26bb;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26c9;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26d7;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26e5;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x26f3;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2701;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x270f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x271d;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x272b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2739;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, bp - 6, ax);
    di = 0;
    goto loc_7345;
loc_732b: // 01ed:545b
    memoryASet16(ds, 0x8282, 0x001a);
    ax = di;
    ax += 0x0007;
    memoryASet16(ds, 0x82f8, ax);
    al = memoryAGet(ds, di + 33514);
    cbw();
    push(ax);
    sub_70ca();
    sp++;
    sp++;
    di++;
loc_7345: // 01ed:5475
    if ((short)di < (short)0x0008)
        goto loc_732b;
    memoryASet16(ds, 0x8282, 0x001a);
    memoryASet16(ds, 0x82f8, 0x000f);
    al = memoryAGet(ds, 0x8284);
    cbw();
    push(ax);
    sub_70ca();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x001a);
    memoryASet16(ds, 0x82f8, 0x0010);
    al = memoryAGet(ds, 0x8285);
    cbw();
    push(ax);
    sub_70ca();
    sp++;
    sp++;
loc_7376: // 01ed:54a6
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ds, 0x82f8, ax);
    sub_8138();
    bx = 0x0100;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    memoryASet(ss, bp - 1, dl);
    if ((char)dl >= (char)0x30)
        goto loc_7396;
    goto loc_7458;
loc_7396: // 01ed:54c6
    if ((char)dl <= (char)0x39)
        goto loc_739e;
    goto loc_7458;
loc_739e: // 01ed:54ce
    al = memoryAGet(ss, bp - 1);
    cbw();
    ax += 0xffd0;
    si = ax;
    al = memoryAGet(ss, bp - 1);
    cbw();
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    al = memoryAGet(ss, bp - 1);
    cbw();
    ax += 0xffd0;
    si = ax;
    ax = 0x274f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_7b0a();
    memoryASet16(ss, bp - 8, 0xffff);
    goto loc_73f2;
loc_73dc: // 01ed:550c
    if (memoryAGet16(ss, bp - 8) != 0x0079)
        goto loc_73e9;
    memoryASet16(ss, bp - 8, 0xffff);
    goto loc_73f2;
loc_73e9: // 01ed:5519
    if (memoryAGet16(ss, bp - 8) != 0x0029)
        goto loc_73f2;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_73f2: // 01ed:5522
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    bx = memoryAGet16(ss, bp - 8);
    al = memoryAGet(ds, bx + 20524);
    cbw();
    if (!ax)
        goto loc_73dc;
    sub_7b0a();
    ax = 0x2764;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    if ((short)si >= (short)0x0008)
        goto loc_7419;
    al = memoryAGet(ss, bp - 8);
    memoryASet(ds, si + 33514, al);
loc_7419: // 01ed:5549
    if (si != 0x0008)
        goto loc_7424;
    al = memoryAGet(ss, bp - 8);
    memoryASet(ds, 0x8284, al);
loc_7424: // 01ed:5554
    if (si != 0x0009)
        goto loc_742f;
    al = memoryAGet(ss, bp - 8);
    memoryASet(ds, 0x8285, al);
loc_742f: // 01ed:555f
    ax = si;
    ax += 0x0007;
    memoryASet16(ds, 0x82f8, ax);
    memoryASet16(ds, 0x8282, 0x001a);
    ax = 0x2778;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x001a);
    push(memoryAGet16(ss, bp - 8));
    sub_70ca();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, 0x30);
loc_7458: // 01ed:5588
    if ((char)memoryAGet(ss, bp - 1) < (char)0x30)
        goto loc_7467;
    if ((char)memoryAGet(ss, bp - 1) > (char)0x39)
        goto loc_7467;
    goto loc_7376;
loc_7467: // 01ed:5597
    memoryASet16(ds, 0x833e, 0x0000);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7473() // 01ed:55a3
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    di = 0;
    si = 0;
    al = memoryAGet(ds, 0x82ea);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_748f;
    si = 0xffff;
loc_748f: // 01ed:55bf
    al = memoryAGet(ds, 0x82ec);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_749f;
    di = 0x0001;
loc_749f: // 01ed:55cf
    al = memoryAGet(ds, 0x82ee);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_74af;
    si = 0x0001;
loc_74af: // 01ed:55df
    al = memoryAGet(ds, 0x82f0);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_74bf;
    di = 0xffff;
loc_74bf: // 01ed:55ef
    al = memoryAGet(ds, 0x82eb);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_74d2;
    si = 0xffff;
    di = 0x0001;
loc_74d2: // 01ed:5602
    al = memoryAGet(ds, 0x82f1);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_74e5;
    si = 0xffff;
    di = 0xffff;
loc_74e5: // 01ed:5615
    al = memoryAGet(ds, 0x82ed);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_74f8;
    si = 0x0001;
    di = 0x0001;
loc_74f8: // 01ed:5628
    al = memoryAGet(ds, 0x82ef);
    cbw();
    bx = ax;
    if (memoryAGet(ds, bx + 20524) == 0x00)
        goto loc_750b;
    si = 0x0001;
    di = 0xffff;
loc_750b: // 01ed:563b
    ax = si;
    dx = 0x0003;
    imul16(dx);
    ax += di;
    ax -= 0xfffc;
    bx = ax;
    if (bx > 0x0008)
        goto loc_7562;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_7525;
        case 2: goto loc_752c;
        case 4: goto loc_7533;
        case 6: goto loc_753a;
        case 8: goto loc_7541;
        case 10: goto loc_7548;
        case 12: goto loc_754f;
        case 14: goto loc_7556;
        case 16: goto loc_755d;
        default:
            stop();
    }
loc_7525: // 01ed:5655
    memoryASet16(ss, bp - 6, 0x0007);
    goto loc_7562;
loc_752c: // 01ed:565c
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_7562;
loc_7533: // 01ed:5663
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_7562;
loc_753a: // 01ed:566a
    memoryASet16(ss, bp - 6, 0x0006);
    goto loc_7562;
loc_7541: // 01ed:5671
    memoryASet16(ss, bp - 6, 0x0008);
    goto loc_7562;
loc_7548: // 01ed:5678
    memoryASet16(ss, bp - 6, 0x0002);
    goto loc_7562;
loc_754f: // 01ed:567f
    memoryASet16(ss, bp - 6, 0x0005);
    goto loc_7562;
loc_7556: // 01ed:5686
    memoryASet16(ss, bp - 6, 0x0004);
    goto loc_7562;
loc_755d: // 01ed:568d
    memoryASet16(ss, bp - 6, 0x0003);
loc_7562: // 01ed:5692
    al = memoryAGet(ds, 0x8284);
    cbw();
    bx = ax;
    al = memoryAGet(ds, bx + 20524);
    cbw();
    memoryASet16(ss, bp - 4, ax);
    al = memoryAGet(ds, 0x8285);
    cbw();
    bx = ax;
    al = memoryAGet(ds, bx + 20524);
    cbw();
    memoryASet16(ss, bp - 2, ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = bp - 6;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = memoryAGet16(ss, bp + 4);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_75ab() // 01ed:56db
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    ax = 0x0003;
    interrupt(0x33);
    di = cx;
    si = dx;
    ax = bx;
    ax &= 0x0001;
    memoryASet16(ss, bp - 8, ax);
    ax = bx;
    ax &= 0x0002;
    ax >>= 1;
    memoryASet16(ss, bp - 6, ax);
    ax = di;
    ax += 0xfec0;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    if ((short)ax <= (short)memoryAGet16(ds, 0x836c))
        goto loc_75f9;
    memoryASet16(ss, bp - 2, 0x0001);
    ax = memoryAGet16(ds, 0x836c);
    ax <<= 1;
    dx = di;
    dx -= ax;
    goto loc_761c;
loc_75f9: // 01ed:5729
    ax = di;
    ax += 0xfec0;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    dx = memoryAGet16(ds, 0x836c);
    dx = -dx;
    if ((short)ax >= (short)dx)
        goto loc_761e;
    memoryASet16(ss, bp - 2, 0xffff);
    ax = memoryAGet16(ds, 0x836c);
    ax <<= 1;
    dx = di;
    dx += ax;
loc_761c: // 01ed:574c
    di = dx;
loc_761e: // 01ed:574e
    ax = si;
    ax += 0xff9c;
    if ((short)ax <= (short)memoryAGet16(ds, 0x836c))
        goto loc_7636;
    memoryASet16(ss, bp - 4, 0x0001);
    ax = si;
    ax -= memoryAGet16(ds, 0x836c);
    goto loc_7650;
loc_7636: // 01ed:5766
    ax = si;
    ax += 0xff9c;
    dx = memoryAGet16(ds, 0x836c);
    dx = -dx;
    if ((short)ax >= (short)dx)
        goto loc_7652;
    memoryASet16(ss, bp - 4, 0xffff);
    ax = si;
    ax += memoryAGet16(ds, 0x836c);
loc_7650: // 01ed:5780
    si = ax;
loc_7652: // 01ed:5782
    ax = 0x0004;
    cx = di;
    dx = si;
    interrupt(0x33);
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0003;
    imul16(dx);
    ax += memoryAGet16(ss, bp - 2);
    ax -= 0xfffc;
    bx = ax;
    if (bx > 0x0008)
        goto loc_76b4;
    bx <<= 1;
    indirectJump(cs, memoryAGet16(cs, bx + 22527)); // 01ed:57a2;
  // gap 61 bytes
loc_76b4: // 01ed:57e4
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = bp - 10;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = memoryAGet16(ss, bp + 4);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_76e1() // 01ed:5811
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    si = memoryAGet16(ss, bp + 8);
    if (memoryAGet16(ss, bp + 4) != 0x0001)
        goto loc_7701;
    memoryASet16(ss, bp - 8, 0x0001);
    memoryASet16(ss, bp - 10, 0x0002);
    goto loc_770b;
loc_7701: // 01ed:5831
    memoryASet16(ss, bp - 8, 0x0004);
    memoryASet16(ss, bp - 10, 0x0008);
loc_770b: // 01ed:583b
    memoryASet16(ds, di, 0x0000);
    memoryASet16(ds, si, 0x0000);
    ax = 0x0201;
    push(ax);
    sub_f134();
    sp++;
    sp++;
    push(ax);
    ax = 0x0201;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    flags.interrupts = 0;
loc_7728: // 01ed:5858
    ax = 0x0201;
    push(ax);
    sub_f134();
    sp++;
    sp++;
    ah = 0x00;
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 8);
    if (!(memoryAGet16(ss, bp - 2) & ax))
        goto loc_7743;
    ax = 0x0001;
    goto loc_7745;
loc_7743: // 01ed:5873
    ax = 0;
loc_7745: // 01ed:5875
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 10);
    if (!(memoryAGet16(ss, bp - 2) & ax))
        goto loc_7755;
    ax = 0x0001;
    goto loc_7757;
loc_7755: // 01ed:5885
    ax = 0;
loc_7757: // 01ed:5887
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, di, memoryAGet16(ds, di) + ax);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ds, si, memoryAGet16(ds, si) + ax);
    ax = memoryAGet16(ss, bp - 4);
    ax += memoryAGet16(ss, bp - 6);
    if (!ax)
        goto loc_7778;
    if ((short)memoryAGet16(ds, di) >= (short)0x01f4)
        goto loc_7778;
    if ((short)memoryAGet16(ds, si) < (short)0x01f4)
        goto loc_7728;
loc_7778: // 01ed:58a8
    flags.interrupts = 1;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_777f() // 01ed:58af
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 6, 0x0000);
    memoryASet16(ss, bp - 8, 0x0000);
    ax = bp - 4;
    push(ax);
    ax = bp - 2;
    push(ax);
    push(si);
    sub_76e1();
    sp += 0x0006;
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x01f4)
        goto loc_77b9;
    ax = 0x0001;
    goto loc_77bb;
loc_77b9: // 01ed:58e9
    ax = 0;
loc_77bb: // 01ed:58eb
    push(ax);
    if ((short)memoryAGet16(ss, bp - 4) <= (short)0x01f4)
        goto loc_77c8;
    ax = 0x0001;
    goto loc_77ca;
loc_77c8: // 01ed:58f8
    ax = 0;
loc_77ca: // 01ed:58fa
    dx = pop();
    dx |= ax;
    if (!dx)
        goto loc_77e7;
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33386);
    ax++;
    memoryASet16(ss, bp - 2, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33398);
    ax++;
    memoryASet16(ss, bp - 4, ax);
loc_77e7: // 01ed:5917
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33392);
    if ((short)ax >= (short)memoryAGet16(ss, bp - 2))
        goto loc_77fb;
    memoryASet16(ss, bp - 6, 0x0001);
    goto loc_780d;
loc_77fb: // 01ed:592b
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33386);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 2))
        goto loc_780d;
    memoryASet16(ss, bp - 6, 0xffff);
loc_780d: // 01ed:593d
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33404);
    if ((short)ax >= (short)memoryAGet16(ss, bp - 4))
        goto loc_7821;
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_7833;
loc_7821: // 01ed:5951
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 33398);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 4))
        goto loc_7833;
    memoryASet16(ss, bp - 8, 0xffff);
loc_7833: // 01ed:5963
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x0003;
    imul16(dx);
    ax += memoryAGet16(ss, bp - 6);
    ax -= 0xfffc;
    bx = ax;
    if (bx > 0x0008)
        goto loc_788c;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_784f;
        case 2: goto loc_7856;
        case 4: goto loc_785d;
        case 6: goto loc_7864;
        case 8: goto loc_786b;
        case 10: goto loc_7872;
        case 12: goto loc_7879;
        case 14: goto loc_7880;
        case 16: goto loc_7887;
        default:
            stop();
    }
loc_784f: // 01ed:597f
    memoryASet16(ss, bp - 14, 0x0007);
    goto loc_788c;
loc_7856: // 01ed:5986
    memoryASet16(ss, bp - 14, 0x0000);
    goto loc_788c;
loc_785d: // 01ed:598d
    memoryASet16(ss, bp - 14, 0x0001);
    goto loc_788c;
loc_7864: // 01ed:5994
    memoryASet16(ss, bp - 14, 0x0006);
    goto loc_788c;
loc_786b: // 01ed:599b
    memoryASet16(ss, bp - 14, 0x0008);
    goto loc_788c;
loc_7872: // 01ed:59a2
    memoryASet16(ss, bp - 14, 0x0002);
    goto loc_788c;
loc_7879: // 01ed:59a9
    memoryASet16(ss, bp - 14, 0x0005);
    goto loc_788c;
loc_7880: // 01ed:59b0
    memoryASet16(ss, bp - 14, 0x0004);
    goto loc_788c;
loc_7887: // 01ed:59b7
    memoryASet16(ss, bp - 14, 0x0003);
loc_788c: // 01ed:59bc
    ax = 0x0201;
    push(ax);
    sub_f134();
    sp++;
    sp++;
    ah = 0x00;
    di = ax;
    if (si != 0x0001)
        goto loc_78bc;
    if (ax & 0x0010)
        goto loc_78a8;
    ax = 0x0001;
    goto loc_78aa;
loc_78a8: // 01ed:59d8
    ax = 0;
loc_78aa: // 01ed:59da
    memoryASet16(ss, bp - 12, ax);
    if (di & 0x0020)
        goto loc_78b8;
    ax = 0x0001;
    goto loc_78d9;
loc_78b8: // 01ed:59e8
    goto loc_78d7;
  // gap 2 bytes
loc_78bc: // 01ed:59ec
    if (di & 0x0040)
        goto loc_78c7;
    ax = 0x0001;
    goto loc_78c9;
loc_78c7: // 01ed:59f7
    ax = 0;
loc_78c9: // 01ed:59f9
    memoryASet16(ss, bp - 12, ax);
    if (di & 0x0080)
        goto loc_78d7;
    ax = 0x0001;
    goto loc_78d9;
loc_78d7: // 01ed:5a07
    ax = 0;
loc_78d9: // 01ed:5a09
    memoryASet16(ss, bp - 10, ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = bp - 14;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = memoryAGet16(ss, bp + 4);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7909() // 01ed:5a39
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0020;
    if (memoryAGet16(ds, 0x9732) == 0x0000)
        goto loc_7920;
    if (memoryAGet16(ds, 0x9732) == 0x0002)
        goto loc_7920;
    goto loc_79c1;
loc_7920: // 01ed:5a50
    bx = memoryAGet16(ss, bp + 8);
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 33596);
    if (bx > 0x0003)
        goto loc_7997;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_7935;
        case 2: goto loc_794a;
        case 4: goto loc_795f;
        case 6: goto loc_7978;
        default:
            stop();
    }
loc_7935: // 01ed:5a65
    ax = bp - 6;
    push(ss);
    push(ax);
    push(ss);
    ax = bp - 14;
    push(ax);
    sub_7473();
    sp += 0x0004;
    ax = bp - 14;
    goto loc_798f;
loc_794a: // 01ed:5a7a
    ax = bp - 6;
    push(ss);
    push(ax);
    push(ss);
    ax = bp - 20;
    push(ax);
    sub_75ab();
    sp += 0x0004;
    ax = bp - 20;
    goto loc_798f;
loc_795f: // 01ed:5a8f
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 26;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 26;
    goto loc_798f;
loc_7978: // 01ed:5aa8
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0002;
    push(ax);
    push(ss);
    ax = bp - 32;
    push(ax);
    sub_777f();
    sp += 0x0006;
    ax = bp - 32;
loc_798f: // 01ed:5abf
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
loc_7997: // 01ed:5ac7
    if (memoryAGet16(ds, 0x9732) != 0x0002)
        goto loc_79ed;
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = memoryAGet16(ss, bp - 2);
    dx <<= 1;
    ax |= dx;
    ax |= memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ds, 0x8362);
    al = memoryAGet(ss, bp - 8);
    memoryASet(ds, bx, al);
    memoryASet16(ds, 0x8362, memoryAGet16(ds, 0x8362) + 1);
    goto loc_79ed;
loc_79c1: // 01ed:5af1
    bx = memoryAGet16(ds, 0x8362);
    al = memoryAGet(ds, bx);
    cbw();
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ds, 0x8362, memoryAGet16(ds, 0x8362) + 1);
    ax &= 0x0001;
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 8);
    ax &= 0x0002;
    ax = sar16(ax, 0x0001);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp - 8);
    ax &= 0x003c;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet16(ss, bp - 6, ax);
loc_79ed: // 01ed:5b1d
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = bp - 6;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = memoryAGet16(ss, bp + 4);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7b0a() // 01ed:5c3a
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x50ae, ax);
    memoryASet16(ds, 0x50ac, ax);
    ax = 0x0080;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x502c;
    push(ax);
    sub_f309();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_7b28() // 01ed:5c58
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    flags.carry = (dx + 0x000f) >= 0x10000;
    dx += 0x000f;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_fdb4();
    sp += 0x0004;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ds, 0xa6de, ax);
    memoryASet16(ds, 0xa6e0, dx);
    cx = 0;
    bx = 0;
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    sub_1044a();
    if (!flags.zero)
        goto loc_7b69;
    ax = 0x278f;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_7b69: // 01ed:5c99
    si = memoryAGet16(ss, bp - 4);
    if (!si)
        goto loc_7b7c;
    di = memoryAGet16(ss, bp - 2);
    di++;
    si = 0;
    memoryASet16(ss, bp - 4, si);
    memoryASet16(ss, bp - 2, di);
loc_7b7c: // 01ed:5cac
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7b88() // 01ed:5cb8
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 6, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 10, ax);
    memoryASet16(ss, bp - 12, 0x0000);
    memoryASet16(ss, bp - 14, 0x0000);
    dx = memoryAGet16(ss, bp + 4);
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7c1d;
    memoryASet16(ss, bp - 2, ax);
    bx = ax;
    cx = 0;
    dx = 0;
    ax = 0x4202;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7c1d;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 6, dx);
    cx = memoryAGet16(ss, bp - 6);
    cx++;
loc_7bd2: // 01ed:5d02
    push(cx);
    cx = memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ss, bp - 12);
    ax = 0x4200;
    interrupt(0x21);
    push(ds);
    bx = memoryAGet16(ss, bp - 2);
    cx = 0xffff;
    dx = memoryAGet16(ss, bp - 8);
    ax = memoryAGet16(ss, bp - 10);
    ds = ax;
    ah = 0x3f;
    interrupt(0x21);
    ds = pop();
    cx = pop();
    if (flags.carry)
        goto loc_7c1d;
    if (ax != 0xffff)
        goto loc_7c1d;
    push(cx);
    push(ds);
    bx = memoryAGet16(ss, bp - 2);
    cx = 0x0001;
    dx = memoryAGet16(ss, bp - 8);
    dx += 0xffff;
    ax = memoryAGet16(ss, bp - 10);
    ds = ax;
    ah = 0x3f;
    interrupt(0x21);
    ds = pop();
    cx = pop();
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 0x1000);
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) + 1);
    if (--cx)
        goto loc_7bd2;
loc_7c1d: // 01ed:5d4d
    bx = memoryAGet16(ss, bp - 2);
    ah = 0x3e;
    interrupt(0x21);
    dx = memoryAGet16(ss, bp - 6);
    ax = 0;
    flags.carry = (ax + memoryAGet16(ss, bp - 4)) >= 0x10000;
    ax += memoryAGet16(ss, bp - 4);
    dx += 0x0000 + flags.carry;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7c33() // 01ed:5d63
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 8, 0x0000);
    memoryASet16(ss, bp - 10, 0x0000);
    dx = memoryAGet16(ss, bp + 4);
    ax = 0x3c00;
    cx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7ca9;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ss, bp + 12) == 0x0000)
        goto loc_7c93;
loc_7c64: // 01ed:5d94
    push(ds);
    bx = memoryAGet16(ss, bp - 2);
    cx = 0x8000;
    dx = memoryAGet16(ss, bp - 4);
    ax = memoryAGet16(ss, bp - 6);
    ds = ax;
    ah = 0x40;
    interrupt(0x21);
    ds = pop();
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 0x0800);
    flags.carry = memoryAGet16(ss, bp + 10) < 0x8000;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - 0x8000);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) - 0x0000 - flags.carry);
    if (memoryAGet16(ss, bp + 12) > 0x0000)
        goto loc_7c64;
    if (memoryAGet16(ss, bp + 10) >= 0x8000)
        goto loc_7c64;
loc_7c93: // 01ed:5dc3
    push(ds);
    bx = memoryAGet16(ss, bp - 2);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp - 4);
    ax = memoryAGet16(ss, bp - 6);
    ds = ax;
    ah = 0x40;
    interrupt(0x21);
    ds = pop();
    goto loc_7ca9;
loc_7ca9: // 01ed:5dd9
    bx = memoryAGet16(ss, bp - 2);
    ah = 0x3e;
    interrupt(0x21);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7cb4() // 01ed:5de4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    ax = 0x8000;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f36e();
    sp += 0x0004;
    si = ax;
    if (ax == 0xffff)
        goto loc_7d08;
    push(ax);
    sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(dx);
    push(memoryAGet16(ss, bp - 4));
    sub_7b28();
    sp += 0x0004;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
    push(si);
    sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp + 4));
    sub_7b88();
    sp += 0x0006;
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
    goto loc_7d0c;
loc_7d08: // 01ed:5e38
    dx = 0;
    ax = 0;
loc_7d0c: // 01ed:5e3c
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_7dee() // 01ed:5f1e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x8358, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x835e, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x835a, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x8360, ax);
    ax = 0x0001;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_d7b0();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 4);
    ax++;
    si = ax;
    goto loc_7e40;
loc_7e2a: // 01ed:5f5a
    ax = 0x0002;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(si);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_7e40: // 01ed:5f70
    if ((short)si < (short)memoryAGet16(ss, bp + 8))
        goto loc_7e2a;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    sub_d7b0();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    di = ax;
    goto loc_7eb3;
loc_7e64: // 01ed:5f94
    ax = 0x0004;
    push(ax);
    ax = di;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_d7b0();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 4);
    ax++;
    si = ax;
    goto loc_7e97;
loc_7e82: // 01ed:5fb2
    ax = 0x0020;
    push(ax);
    ax = di;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(si);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_7e97: // 01ed:5fc7
    if ((short)si < (short)memoryAGet16(ss, bp + 8))
        goto loc_7e82;
    ax = 0x0005;
    push(ax);
    ax = di;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    sub_d7b0();
    sp += 0x0006;
    di++;
loc_7eb3: // 01ed:5fe3
    if ((short)di < (short)memoryAGet16(ss, bp + 10))
        goto loc_7e64;
    ax = 0x0006;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_d7b0();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 4);
    ax++;
    si = ax;
    goto loc_7eed;
loc_7ed7: // 01ed:6007
    ax = 0x0007;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(si);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_7eed: // 01ed:601d
    if ((short)si < (short)memoryAGet16(ss, bp + 8))
        goto loc_7ed7;
    ax = 0x0008;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    sub_d7b0();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 4);
    ax++;
    memoryASet16(ds, 0x8354, ax);
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    memoryASet16(ds, 0x82f8, ax);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_7f1e() // 01ed:604e
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    dx = memoryAGet16(ds, 0x24ce);
    dx -= ax;
    di = dx;
    ax = memoryAGet16(ss, bp + 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    dx = memoryAGet16(ds, 0x24d0);
    dx -= ax;
    si = dx;
    ax = si;
    ax += memoryAGet16(ss, bp + 6);
    ax++;
    push(ax);
    ax = di;
    ax += memoryAGet16(ss, bp + 4);
    ax++;
    push(ax);
    push(dx);
    push(di);
    sub_7dee();
    sp += 0x0008;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_7f5c() // 01ed:608c
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    goto loc_7f85;
loc_7f66: // 01ed:6096
    si = memoryAGet16(ss, bp + 4);
    goto loc_7f7f;
loc_7f6b: // 01ed:609b
    push(memoryAGet16(ss, bp + 12));
    ax = di;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(si);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_7f7f: // 01ed:60af
    if ((short)si <= (short)memoryAGet16(ss, bp + 8))
        goto loc_7f6b;
    di++;
loc_7f85: // 01ed:60b5
    if ((short)di <= (short)memoryAGet16(ss, bp + 10))
        goto loc_7f66;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_7f8e() // 01ed:60be
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    si = memoryAGet16(ss, bp + 6);
    if ((short)di <= (short)0x0002)
        goto loc_7fc3;
    if ((short)si <= (short)0x0002)
        goto loc_7fb4;
    ax = si;
    ax += 0xfffe;
    push(ax);
    ax = di;
    ax += 0xfffe;
    push(ax);
    sub_7f8e();
    goto loc_7fd2;
loc_7fb4: // 01ed:60e4
    push(si);
    ax = di;
    ax += 0xfffe;
    push(ax);
    sub_7fea();
    sp += 0x0004;
    goto loc_7fd5;
loc_7fc3: // 01ed:60f3
    if ((short)si <= (short)0x0002)
        goto loc_7fd5;
    ax = si;
    ax += 0xfffe;
    push(ax);
    push(di);
    sub_801b();
loc_7fd2: // 01ed:6102
    sp += 0x0004;
loc_7fd5: // 01ed:6105
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    push(si);
    push(di);
    sub_7f1e();
    sp += 0x0004;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_7fea() // 01ed:611a
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si <= (short)0x0002)
        goto loc_8005;
    push(memoryAGet16(ss, bp + 6));
    ax = si;
    ax += 0xfffe;
    push(ax);
    sub_7fea();
    sp += 0x0004;
loc_8005: // 01ed:6135
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    push(memoryAGet16(ss, bp + 6));
    push(si);
    sub_7f1e();
    sp += 0x0004;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_801b() // 01ed:614b
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    if ((short)si <= (short)0x0002)
        goto loc_8036;
    ax = si;
    ax += 0xfffe;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_801b();
    sp += 0x0004;
loc_8036: // 01ed:6166
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    push(si);
    push(memoryAGet16(ss, bp + 4));
    sub_7f1e();
    sp += 0x0004;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8138() // 01ed:6268
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
loc_813d: // 01ed:626d
    si = 0x0009;
    goto loc_8163;
loc_8142: // 01ed:6272
    ax = si;
    si++;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0005;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_8163: // 01ed:6293
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    ax &= 0x00ff;
    di = ax;
    if (ax)
        goto loc_817a;
    if ((short)si < (short)0x000d)
        goto loc_8142;
loc_817a: // 01ed:62aa
    if (!di)
        goto loc_813d;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_81a2() // 01ed:62d2
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    goto loc_81e7;
loc_81a9: // 01ed:62d9
    if (memoryAGet(ss, bp - 1) != 0x0a)
        goto loc_81bb;
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    ax = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, ax);
    goto loc_81e7;
loc_81bb: // 01ed:62eb
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_81c9;
    ax = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, ax);
    goto loc_81e7;
loc_81c9: // 01ed:62f9
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(ax);
    sub_d7b0();
    sp += 0x0006;
loc_81e7: // 01ed:6317
    bx = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 1);
    al = memoryAGet(ds, bx);
    memoryASet(ss, bp - 1, al);
    if (al)
        goto loc_81a9;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_81fa() // 01ed:632a
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x000a;
    push(ax);
    ax = 0x8290;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f25a();
    sp += 0x0006;
    ax = 0x8290;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_823b() // 01ed:636b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    ax = 0x8000;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f36e();
    sp += 0x0004;
    si = ax;
    if (ax != 0xffff)
        goto loc_825c;
    dx = 0;
    ax = 0;
    goto loc_8274;
loc_825c: // 01ed:638c
    push(si);
    sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_e47b();
    sp++;
    sp++;
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
loc_8274: // 01ed:63a4
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8346() // 01ed:6476
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 4));
    sub_f647();
    sp++;
    sp++;
    ax >>= 1;
    dx = memoryAGet16(ds, 0x24ce);
    dx++;
    dx -= ax;
    memoryASet16(ds, 0x8282, dx);
    push(memoryAGet16(ss, bp + 4));
    sub_81a2();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_8487() // 01ed:65b7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    si = 0;
loc_8490: // 01ed:65c0
    sub_8138();
    ax &= 0x00ff;
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    if (al == 0x7f)
        goto loc_84a7;
    if (al != 0x08)
        goto loc_84c8;
loc_84a7: // 01ed:65d7
    if ((short)si <= 0)
        goto loc_84c8;
    si--;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) - 1);
loc_84c8: // 01ed:65f8
    if ((char)memoryAGet(ss, bp - 1) < (char)0x20)
        goto loc_84fc;
    if ((char)memoryAGet(ss, bp - 1) > (char)0x7a)
        goto loc_84fc;
    if ((short)si >= (short)memoryAGet16(ss, bp + 6))
        goto loc_84fc;
    bx = memoryAGet16(ss, bp + 4);
    al = memoryAGet(ss, bp - 1);
    memoryASet(ds, bx + si, al);
    si++;
    cbw();
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(ax);
    sub_d7b0();
    sp += 0x0006;
loc_84fc: // 01ed:662c
    if (memoryAGet(ss, bp - 1) == 0x1b)
        goto loc_850a;
    if (memoryAGet(ss, bp - 1) == 0x0d)
        goto loc_850a;
    goto loc_8490;
loc_850a: // 01ed:663a
    di = si;
    goto loc_8515;
loc_850e: // 01ed:663e
    bx = memoryAGet16(ss, bp + 4);
    memoryASet(ds, bx + di, 0x00);
    di++;
loc_8515: // 01ed:6645
    if ((short)di < (short)memoryAGet16(ss, bp + 6))
        goto loc_850e;
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_8525;
    ax = 0x0001;
    goto loc_8527;
loc_8525: // 01ed:6655
    ax = 0;
loc_8527: // 01ed:6657
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_852d() // 01ed:665d
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = 0x27c4;
    push(ax);
    ax = 0x8290;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x8290;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x0180;
    push(ax);
    ax = 0x8001;
    push(ax);
    ax = 0x8290;
    push(ax);
    sub_f36e();
    sp += 0x0006;
    si = ax;
    if (ax == 0xffff)
        goto loc_8569;
    goto loc_85da;
  // gap 1 bytes
loc_8569: // 01ed:6699
    memoryASet16(ds, 0x5143, 0x0001);
    memoryASet16(ds, 0x833e, 0x0000);
    memoryASet16(ds, 0x8340, 0x0002);
    ax = 0x0014;
    memoryASet16(ds, 0x826e, ax);
    memoryASet16(ds, 0x826c, ax);
    ax = 0x003c;
    memoryASet16(ds, 0x8274, ax);
    memoryASet16(ds, 0x8272, ax);
    ax = 0x0014;
    memoryASet16(ds, 0x827a, ax);
    memoryASet16(ds, 0x8278, ax);
    ax = 0x003c;
    memoryASet16(ds, 0x8280, ax);
    memoryASet16(ds, 0x827e, ax);
    memoryASet16(ds, 0x836c, 0x0005);
    memoryASet(ds, 0x82ea, 0x48);
    memoryASet(ds, 0x82eb, 0x49);
    memoryASet(ds, 0x82ec, 0x4d);
    memoryASet(ds, 0x82ed, 0x51);
    memoryASet(ds, 0x82ee, 0x50);
    memoryASet(ds, 0x82ef, 0x4f);
    memoryASet(ds, 0x82f0, 0x4b);
    memoryASet(ds, 0x82f1, 0x47);
    memoryASet(ds, 0x8284, 0x1d);
    memoryASet(ds, 0x8285, 0x38);
    goto loc_8676;
loc_85da: // 01ed:670a
    ax = 0x0002;
    push(ax);
    ax = 0x5143;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x833c;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x826a;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x8276;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x8270;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x827c;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0002;
    push(ax);
    ax = 0x836c;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0008;
    push(ax);
    ax = 0x82ea;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = 0x8284;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = 0x8285;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    push(si);
    sub_e47b();
    sp++;
    sp++;
loc_8676: // 01ed:67a6
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8679() // 01ed:67a9
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = 0x27ce;
    push(ax);
    ax = 0x8290;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x8290;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x0180;
    push(ax);
    ax = 0x8302;
    push(ax);
    ax = 0x8290;
    push(ax);
    sub_f36e();
    sp += 0x0006;
    si = ax;
    if (ax != 0xffff)
        goto loc_86b5;
    goto loc_8751;
loc_86b5: // 01ed:67e5
    ax = 0x0002;
    push(ax);
    ax = 0x5143;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x833c;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x826a;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x8276;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x8270;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x827c;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0002;
    push(ax);
    ax = 0x836c;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0008;
    push(ax);
    ax = 0x82ea;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = 0x8284;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = 0x8285;
    push(ax);
    push(si);
    sub_ec32();
    sp += 0x0006;
    push(si);
    sub_e47b();
    sp++;
    sp++;
loc_8751: // 01ed:6881
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8754() // 01ed:6884
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0010;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 8, 0x0000);
    memoryASet16(ss, bp - 6, 0x0000);
    ax = 0x8000;
    push(ax);
    push(di);
    sub_f36e();
    sp += 0x0004;
    si = ax;
    ax = 0x0004;
    push(ax);
    ax = bp - 4;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    ax = 0x0002;
    push(ax);
    ax = 0x8326;
    push(ax);
    push(si);
    sub_f4ff();
    sp += 0x0006;
    push(si);
    sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_7b28();
    sp += 0x0004;
    memoryASet16(ds, 0x8328, ax);
    memoryASet16(ds, 0x832a, dx);
    memoryASet16(ss, bp - 12, ax);
    memoryASet16(ss, bp - 10, dx);
    ax = 0x8000;
    push(ax);
    push(di);
    sub_f36e();
    sp += 0x0004;
    si = ax;
    push(ax);
    sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 6, dx);
    push(si);
    sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0x825a, ax);
    memoryASet16(ds, 0x825c, dx);
    memoryASet16(ss, bp - 16, ax);
    memoryASet16(ss, bp - 14, dx);
    cx = 0;
    bx = 0;
    dx = memoryAGet16(ds, 0x825c);
    ax = memoryAGet16(ds, 0x825a);
    sub_1044a();
    if (!flags.zero)
        goto loc_880e;
    ax = 0x27d8;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_880e: // 01ed:693e
    push(memoryAGet16(ds, 0x825c));
    push(memoryAGet16(ds, 0x825a));
    push(di);
    sub_7b88();
    sp += 0x0006;
    ax = memoryAGet16(ds, 0x8326);
    ax += 0xfff8;
    memoryASet16(ds, 0x835c, ax);
    ax = memoryAGet16(ds, 0x8326);
    if (ax == 0x000c)
        goto loc_884a;
    if (ax == 0x000d)
        goto loc_8842;
    if (ax == 0x000e)
        goto loc_883a;
    goto loc_8850;
loc_883a: // 01ed:696a
    memoryASet16(ds, 0x8356, 0x4679);
    goto loc_8850;
loc_8842: // 01ed:6972
    memoryASet16(ds, 0x8356, 0x2345);
    goto loc_8850;
loc_884a: // 01ed:697a
    memoryASet16(ds, 0x8356, 0x139d);
loc_8850: // 01ed:6980
    memoryASet16(ds, 0x96fa, 0x0009);
    ax = 0x0001;
    cl = memoryAGet(ds, 0x96fa);
    ax <<= cl;
    ax--;
    memoryASet16(ds, 0x8348, ax);
    ax = memoryAGet16(ds, 0x8356);
    ax <<= 1;
    dx = 0;
    push(dx);
    push(ax);
    sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0x8266, ax);
    memoryASet16(ds, 0x8268, dx);
    cx = 0;
    bx = 0;
    ax = memoryAGet16(ds, 0x8266);
    sub_1044a();
    if (!flags.zero)
        goto loc_888e;
    ax = 0x2801;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_888e: // 01ed:69be
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8356));
    sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0xa6d6, ax);
    memoryASet16(ds, 0xa6d8, dx);
    cx = 0;
    bx = 0;
    ax = memoryAGet16(ds, 0xa6d6);
    sub_1044a();
    if (!flags.zero)
        goto loc_88b7;
    ax = 0x282a;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_88b7: // 01ed:69e7
    memoryASet16(ds, 0x82f6, 0x0000);
    memoryASet16(ds, 0x82f2, 0x0000);
    memoryASet16(ds, 0x82f4, 0x0000);
    sub_8900();
    push(memoryAGet16(ds, 0x8268));
    push(memoryAGet16(ds, 0x8266));
    sub_fcce();
    sp += 0x0004;
    push(memoryAGet16(ds, 0xa6d8));
    push(memoryAGet16(ds, 0xa6d6));
    sub_fcce();
    sp += 0x0004;
    push(memoryAGet16(ss, bp - 14));
    push(memoryAGet16(ss, bp - 16));
    sub_fcce();
    sp += 0x0004;
    dx = memoryAGet16(ss, bp - 10);
    ax = memoryAGet16(ss, bp - 12);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8900() // 01ed:6a30
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    push(di);
    di = 0x0102;
    memoryASet16(ss, bp - 8, 0x0001);
    cx = 0;
    bx = 0x0006;
    dx = ds;
    ax = 0x825a;
    sub_10083();
    goto loc_8a1e;
loc_8920: // 01ed:6a50
    if (memoryAGet16(ss, bp - 8) == 0x0000)
        goto loc_894e;
    memoryASet16(ss, bp - 8, 0x0000);
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8328); es = memoryAGet16(ds, 0x8328 + 2); /*ggg2*/;
    al = memoryAGet(ss, bp - 4);
    memoryASet(es, bx, al);
    cx = 0;
    bx = 0x0001;
    dx = ds;
    ax = 0x8328;
    sub_10083();
    goto loc_8a1e;
loc_894e: // 01ed:6a7e
    if (memoryAGet16(ss, bp - 2) != 0x0100)
        goto loc_8973;
    memoryASet16(ss, bp - 8, 0x0001);
    memoryASet16(ds, 0x96fa, 0x0009);
    di = 0x0102;
    ax = 0x0001;
    cl = memoryAGet(ds, 0x96fa);
    ax <<= cl;
    ax--;
    memoryASet16(ds, 0x8348, ax);
    goto loc_8a1e;
loc_8973: // 01ed:6aa3
    if (memoryAGet16(ss, bp - 2) < di)
        goto loc_8986;
    al = memoryAGet(ss, bp - 6);
    memoryASet(ds, 0x9734, al);
    push(memoryAGet16(ss, bp - 4));
    ax = 0x9735;
    goto loc_898c;
loc_8986: // 01ed:6ab6
    push(memoryAGet16(ss, bp - 2));
    ax = 0x9734;
loc_898c: // 01ed:6abc
    push(ax);
    sub_8a32();
    sp += 0x0004;
    si = ax;
    al = memoryAGet(ds, si);
    ah = 0x00;
    memoryASet16(ss, bp - 6, ax);
    goto loc_89b5;
loc_899e: // 01ed:6ace
    al = memoryAGet(ds, si);
    bx = memoryAGet16(ds, 0x8328); es = memoryAGet16(ds, 0x8328 + 2); /*ggg2*/;
    memoryASet(es, bx, al);
    si--;
    cx = 0;
    bx = 0x0001;
    dx = ds;
    ax = 0x8328;
    sub_10083();
loc_89b5: // 01ed:6ae5
    if (si >= 0x9734)
        goto loc_899e;
    if (di > memoryAGet16(ds, 0x8348))
        goto loc_8a18;
    bx = di;
    ax = 0;
    flags.carry = !!(bx & 0x8000);
    bx <<= 1;
    ax = rcl16(ax, 0x0001);
    dx = memoryAGet16(ds, 0x8268);
    push(bx);
    push(ax);
    ax = memoryAGet16(ds, 0x8266);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = memoryAGet16(ss, bp - 4);
    es = dx;
    tx = bx; bx = ax; ax = tx;
    memoryASet16(es, bx, ax);
    bx = di;
    cx = 0;
    dx = memoryAGet16(ds, 0xa6d8);
    ax = memoryAGet16(ds, 0xa6d6);
    sub_1010b();
    bl = memoryAGet(ss, bp - 6);
    es = dx;
    tx = bx; bx = ax; ax = tx;
    memoryASet(es, bx, al);
    di++;
    if (di != memoryAGet16(ds, 0x8348))
        goto loc_8a18;
    ax = memoryAGet16(ds, 0x96fa);
    if ((short)ax >= (short)memoryAGet16(ds, 0x8326))
        goto loc_8a18;
    memoryASet16(ds, 0x96fa, memoryAGet16(ds, 0x96fa) + 1);
    cx = memoryAGet16(ds, 0x96fa);
    ax = 0x0001;
    ax <<= cl;
    ax--;
    memoryASet16(ds, 0x8348, ax);
loc_8a18: // 01ed:6b48
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, ax);
loc_8a1e: // 01ed:6b4e
    sub_8aa4();
    memoryASet16(ss, bp - 2, ax);
    if (ax == 0x0101)
        goto loc_8a2c;
    goto loc_8920;
loc_8a2c: // 01ed:6b5c
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_8a32() // 01ed:6b62
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    di = 0;
    goto loc_8a92;
loc_8a3e: // 01ed:6b6e
    bx = memoryAGet16(ss, bp + 6);
    cx = 0;
    dx = memoryAGet16(ds, 0xa6d8);
    ax = memoryAGet16(ds, 0xa6d6);
    sub_1010b();
    bx = ax;
    es = dx;
    al = memoryAGet(es, bx);
    memoryASet(ds, si, al);
    si++;
    bx = memoryAGet16(ss, bp + 6);
    ax = 0;
    flags.carry = !!(bx & 0x8000);
    bx <<= 1;
    ax = rcl16(ax, 0x0001);
    dx = memoryAGet16(ds, 0x8268);
    push(bx);
    push(ax);
    ax = memoryAGet16(ds, 0x8266);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp + 6, ax);
    ax = di;
    di++;
    if ((short)ax < (short)0x0fa0)
        goto loc_8a92;
    ax = 0x2853;
    push(ax);
    sub_e805();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_e4a7();
    sp++;
    sp++;
loc_8a92: // 01ed:6bc2
    if (memoryAGet16(ss, bp + 6) > 0x00ff)
        goto loc_8a3e;
    al = memoryAGet(ss, bp + 6);
    memoryASet(ds, si, al);
    ax = si;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8aa4() // 01ed:6bd4
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    goto loc_8ade;
loc_8aab: // 01ed:6bdb
    bx = memoryAGet16(ds, 0x825a); es = memoryAGet16(ds, 0x825a + 2); /*ggg2*/;
    al = memoryAGet(es, bx);
    cbw();
    ax &= 0x00ff;
    si = ax;
    cx = 0;
    bx = 0x0001;
    dx = ds;
    ax = 0x825a;
    sub_10083();
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x18;
    cl -= memoryAGet(ds, 0x82f6);
    sub_10021();
    memoryASet16(ds, 0x82f2, memoryAGet16(ds, 0x82f2) | ax);
    memoryASet16(ds, 0x82f4, memoryAGet16(ds, 0x82f4) | dx);
    memoryASet16(ds, 0x82f6, memoryAGet16(ds, 0x82f6) + 0x0008);
loc_8ade: // 01ed:6c0e
    if ((short)memoryAGet16(ds, 0x82f6) <= (short)0x0018)
        goto loc_8aab;
    cl = 0x20;
    cl -= memoryAGet(ds, 0x96fa);
    dx = memoryAGet16(ds, 0x82f4);
    ax = memoryAGet16(ds, 0x82f2);
    sub_10062();
    di = ax;
    cl = memoryAGet(ds, 0x96fa);
    dx = memoryAGet16(ds, 0x82f4);
    ax = memoryAGet16(ds, 0x82f2);
    sub_10021();
    memoryASet16(ds, 0x82f2, ax);
    memoryASet16(ds, 0x82f4, dx);
    ax = memoryAGet16(ds, 0x96fa);
    memoryASet16(ds, 0x82f6, memoryAGet16(ds, 0x82f6) - ax);
    ax = di;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_8b19() // 01ed:6c49
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x2508;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x2519;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x253b;
    ax = 0x1002;
    interrupt(0x10);
    bp = pop();
    sp += 2;
}
void sub_8b5d() // 01ed:6c8d
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x253b;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x252a;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x2519;
    ax = 0x1002;
    interrupt(0x10);
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = ds;
    es = ax;
    dx = 0x2508;
    ax = 0x1002;
    interrupt(0x10);
    bp = pop();
    sp += 2;
}
void sub_8bb6() // 01ed:6ce6
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0068;
    push(si);
    push(di);
    push(ss);
    ax = bp - 64;
    push(ax);
    push(ds);
    ax = 0x254c;
    push(ax);
    cx = 0x000d;
    sub_1016b();
    ax = 0x2871;
    push(ax);
    ax = bp - 64;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 64;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = bp - 64;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ss, bp - 32, ax);
    memoryASet16(ss, bp - 30, dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 46);
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(es, bx + 16);
    memoryASet16(ds, 0x836e, ax);
    ax = memoryAGet16(es, bx + 28);
    memoryASet16(ds, 0x8352, ax);
    ax = memoryAGet16(es, bx + 34);
    memoryASet16(ds, 0x8342, ax);
    ax = memoryAGet16(es, bx + 40);
    memoryASet16(ds, 0x972e, ax);
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    push(memoryAGet16(es, bx + 14));
    push(memoryAGet16(es, bx + 12));
    sub_ff73();
    dx = memoryAGet16(ss, bp - 30);
    dx += ax;
    ax = memoryAGet16(ss, bp - 32);
    memoryASet16(ds, 0x834e, ax);
    memoryASet16(ds, 0x8350, dx);
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_8c9a;
loc_8c51: // 01ed:6d81
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = pop();
    imul16(memoryAGet16(es, bx + 2));
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 4) + ax) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (dx + flags.carry));
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_8c9a: // 01ed:6dca
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 40);
    ax <<= 1;
    ax <<= 1;
    if ((short)ax > (short)memoryAGet16(ss, bp - 6))
        goto loc_8c51;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_8cc9;
loc_8cb1: // 01ed:6de1
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_7b28();
    sp += 0x0004;
    bx = memoryAGet16(ss, bp - 6);
    bx <<= 1;
    memoryASet16(ds, bx + 33504, dx);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_8cc9: // 01ed:6df9
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0005)
        goto loc_8cb1;
    ax = 0x287a;
    push(ax);
    ax = bp - 64;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 64;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    if (memoryAGet16(ss, bp - 12) == 0x0000)
        goto loc_8cfa;
    ax = bp - 64;
    push(ax);
    sub_8754();
    goto loc_8d01;
loc_8cfa: // 01ed:6e2a
    ax = bp - 64;
    push(ax);
    sub_7cb4();
loc_8d01: // 01ed:6e31
    sp++;
    sp++;
    memoryASet16(ss, bp - 40, ax);
    memoryASet16(ss, bp - 38, dx);
    ax = memoryAGet16(ds, 0xa6e0);
    dx = memoryAGet16(ds, 0xa6de);
    memoryASet16(ss, bp - 48, dx);
    memoryASet16(ss, bp - 46, ax);
    ax = 0x000d;
    interrupt(0x10);
    memoryASet16(ds, 0x35b4, 0xa000);
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_8d3d;
loc_8d28: // 01ed:6e58
    push(memoryAGet16(ss, bp - 6));
    sub_dfd4();
    sp++;
    sp++;
    es = memoryAGet16(ds, 0x35b4);
    memoryASet(es, 0x2000, 0x00);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_8d3d: // 01ed:6e6d
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0004)
        goto loc_8d28;
    al = 0x13;
    push(ax);
    ax = 0x03d4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x18;
    push(ax);
    ax = 0x03d5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    ax = 0x0005;
    push(ax);
    ax = 0x03ce;
    push(ax);
    sub_f4e7();
    sp += 0x0004;
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_8dcf;
loc_8d72: // 01ed:6ea2
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    cx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    sub_10433();
    push(dx);
    push(ax);
    sub_ff73();
    dx = memoryAGet16(ss, bp - 38);
    dx += ax;
    memoryASet16(ss, bp - 50, dx);
    ax = 0x0001;
    cl = memoryAGet(ss, bp - 6);
    ax <<= cl;
    cl = 0x08;
    ax <<= cl;
    dx = 0x0002;
    dx |= ax;
    push(dx);
    ax = 0x03c4;
    push(ax);
    sub_f4e7();
    sp += 0x0004;
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    push(memoryAGet16(es, bx));
    ax = 0;
    push(ax);
    ax = 0xa700;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp - 50));
    sub_f321();
    sp += 0x000a;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_8dcf: // 01ed:6eff
    if ((short)memoryAGet16(ss, bp - 6) < (short)0x0004)
        goto loc_8d72;
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    push(memoryAGet16(es, bx + 20));
    push(memoryAGet16(es, bx + 18));
    sub_ff73();
    ax += 0xa700;
    memoryASet16(ds, 0x82fe, 0x0000);
    memoryASet16(ds, 0x8300, ax);
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    push(memoryAGet16(es, bx + 32));
    push(memoryAGet16(es, bx + 30));
    sub_ff73();
    ax += 0xa700;
    memoryASet16(ds, 0x8368, 0x0000);
    memoryASet16(ds, 0x836a, ax);
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    push(memoryAGet16(es, bx + 38));
    push(memoryAGet16(es, bx + 36));
    sub_ff73();
    ax += 0xa700;
    memoryASet16(ds, 0x834a, 0x0000);
    memoryASet16(ds, 0x834c, ax);
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    push(memoryAGet16(es, bx + 10));
    push(memoryAGet16(es, bx + 8));
    sub_ff73();
    dx = memoryAGet16(ss, bp - 30);
    dx += ax;
    ax = memoryAGet16(ss, bp - 32);
    memoryASet16(ds, 0x8364, ax);
    memoryASet16(ds, 0x8366, dx);
    push(memoryAGet16(ss, bp - 46));
    push(memoryAGet16(ss, bp - 48));
    sub_fcce();
    sp += 0x0004;
    ah = 0x10;
    al = 0x01;
    bh = 0x03;
    interrupt(0x10);
    ax = 0x000e;
    push(ax);
    ax = 0x004c;
    push(ax);
    ax = 0x000f;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0005;
    push(ax);
    ax = 0x03ce;
    push(ax);
    sub_f4e7();
    sp += 0x0004;
    ax = 0x2884;
    push(ax);
    ax = bp - 64;
    push(ax);
    sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 64;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    if (memoryAGet16(ss, bp - 12) == 0x0000)
        goto loc_8ebb;
    ax = bp - 64;
    push(ax);
    sub_8754();
    goto loc_8ec2;
loc_8ebb: // 01ed:6feb
    ax = bp - 64;
    push(ax);
    sub_7cb4();
loc_8ec2: // 01ed:6ff2
    sp++;
    sp++;
    memoryASet16(ss, bp - 36, ax);
    memoryASet16(ss, bp - 34, dx);
    ax = memoryAGet16(ds, 0xa6e0);
    dx = memoryAGet16(ds, 0xa6de);
    memoryASet16(ss, bp - 44, dx);
    memoryASet16(ss, bp - 42, ax);
    ax = 0;
    dx = 0;
    memoryASet16(ds, 0xa6da, dx);
    memoryASet16(ds, 0xa6dc, ax);
    memoryASet16(ds, 0x825e, dx);
    memoryASet16(ds, 0x8260, ax);
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_9640;
loc_8ef1: // 01ed:7021
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = pop();
    imul16(memoryAGet16(es, bx + 2));
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0xa6da, dx);
    memoryASet16(ds, 0xa6dc, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = memoryAGet16(ds, 0x8260);
    cx = memoryAGet16(ds, 0x825e);
    si = ax;
    es = dx;
    memoryASet16(es, si + 4, cx);
    memoryASet16(es, si + 6, bx);
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_9040;
loc_8fa0: // 01ed:70d0
    ax = 0;
    dx = 0x0010;
    push(ax);
    push(dx);
    bx = memoryAGet16(ss, bp - 32); es = memoryAGet16(ss, bp - 32 + 2); /*ggg2*/;
    cx = memoryAGet16(es, bx + 6);
    bx = memoryAGet16(es, bx + 4);
    ax = memoryAGet16(ss, bp - 8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    sub_10433();
    push(dx);
    push(ax);
    sub_ff73();
    dx = memoryAGet16(ds, 0xa6dc);
    dx += memoryAGet16(ss, bp - 34);
    dx += ax;
    ax = memoryAGet16(ds, 0xa6da);
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    cx = bp - 84;
    bx += cx;
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, dx);
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    si = memoryAGet16(ss, bp - 8);
    si <<= 1;
    ax = memoryAGet16(ds, 0x8260);
    ax += memoryAGet16(ds, si + 33504);
    dx = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    push(memoryAGet16(ss, bp - 14));
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    push(memoryAGet16(ds, bx));
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 102;
    bx += ax;
    push(memoryAGet16(ds, bx));
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 84;
    bx += ax;
    push(memoryAGet16(ds, bx));
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 82;
    bx += ax;
    push(memoryAGet16(ds, bx));
    sub_f321();
    sp += 0x000a;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_9040: // 01ed:7170
    if ((short)memoryAGet16(ss, bp - 8) >= (short)0x0005)
        goto loc_9049;
    goto loc_8fa0;
loc_9049: // 01ed:7179
    ax = memoryAGet16(ds, 0x825e);
    ax += memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, ax);
    memoryASet16(ds, 0x8260, dx);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0020;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0020;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = pop();
    imul16(memoryAGet16(es, bx + 2));
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0020;
    sub_1010b();
    bx = memoryAGet16(ds, 0x8260);
    cx = memoryAGet16(ds, 0x825e);
    si = ax;
    es = dx;
    memoryASet16(es, si + 4, cx);
    memoryASet16(es, si + 6, bx);
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_9231;
loc_90f3: // 01ed:7223
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    si = memoryAGet16(ss, bp - 10);
    si <<= 1;
    ax = memoryAGet16(ds, 0x8260);
    ax += memoryAGet16(ds, si + 33504);
    dx = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 22, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 102;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 20, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 84;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 18, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 82;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 16, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 24, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 26, ax);
    if (memoryAGet16(ss, bp - 10) != 0x0004)
        goto loc_91ae;
    ax = 0x0001;
    goto loc_91b0;
loc_91ae: // 01ed:72de
    ax = 0;
loc_91b0: // 01ed:72e0
    dx = 0x00ff;
    imul16(dx);
    memoryASet(ss, bp - 27, al);
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp - 22);
    si = memoryAGet16(ss, bp - 18);
    bx = memoryAGet16(ss, bp - 24);
    dx = memoryAGet16(ss, bp - 26);
    ax = memoryAGet16(ss, bp - 20);
    es = ax;
    ax = memoryAGet16(ss, bp - 16);
    ds = ax;
    flags.direction = 0;
loc_91d2: // 01ed:7302
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    al = memoryAGet(ss, bp - 27);
    stosb<ES_DI>(al);
    flags.carry = di < bx;
    di -= bx;
    di--;
    cx = bx;
    cx++;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_91e5: // 01ed:7315
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_91e5;
    flags.carry = di < bx;
    di -= bx;
    di--;
    cx = bx;
    cx++;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_91fb: // 01ed:732b
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_91fb;
    dx--;
    if (dx)
        goto loc_91d2;
    ds = pop();
    di = pop();
    si = pop();
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx + 2);
    dx = memoryAGet16(ds, bx);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    cx = bp - 84;
    bx += cx;
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_9231: // 01ed:7361
    if ((short)memoryAGet16(ss, bp - 10) >= (short)0x0005)
        goto loc_923a;
    goto loc_90f3;
loc_923a: // 01ed:736a
    ax = memoryAGet16(ds, 0x825e);
    ax += memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, ax);
    memoryASet16(ds, 0x8260, dx);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0040;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0040;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = pop();
    imul16(memoryAGet16(es, bx + 2));
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0040;
    sub_1010b();
    bx = memoryAGet16(ds, 0x8260);
    cx = memoryAGet16(ds, 0x825e);
    si = ax;
    es = dx;
    memoryASet16(es, si + 4, cx);
    memoryASet16(es, si + 6, bx);
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_942a;
loc_92e4: // 01ed:7414
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    si = memoryAGet16(ss, bp - 10);
    si <<= 1;
    ax = memoryAGet16(ds, 0x8260);
    ax += memoryAGet16(ds, si + 33504);
    dx = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 22, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 102;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 20, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 84;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 18, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 82;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 16, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0040;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 24, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0040;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 26, ax);
    if (memoryAGet16(ss, bp - 10) != 0x0004)
        goto loc_93af;
    ax = 0x0001;
    goto loc_93b1;
loc_93af: // 01ed:74df
    ax = 0;
loc_93b1: // 01ed:74e1
    dx = 0x00ff;
    imul16(dx);
    memoryASet(ss, bp - 27, al);
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp - 22);
    si = memoryAGet16(ss, bp - 18);
    bx = memoryAGet16(ss, bp - 24);
    dx = memoryAGet16(ss, bp - 26);
    ax = memoryAGet16(ss, bp - 20);
    es = ax;
    ax = memoryAGet16(ss, bp - 16);
    ds = ax;
    flags.direction = 0;
loc_93d3: // 01ed:7503
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    flags.carry = di < bx;
    di -= bx;
    cx = bx;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_93e0: // 01ed:7510
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_93e0;
    flags.carry = di < bx;
    di -= bx;
    cx = bx;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_93f4: // 01ed:7524
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_93f4;
    dx--;
    if (dx)
        goto loc_93d3;
    ds = pop();
    di = pop();
    si = pop();
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx + 2);
    dx = memoryAGet16(ds, bx);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    cx = bp - 84;
    bx += cx;
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_942a: // 01ed:755a
    if ((short)memoryAGet16(ss, bp - 10) >= (short)0x0005)
        goto loc_9433;
    goto loc_92e4;
loc_9433: // 01ed:7563
    ax = memoryAGet16(ds, 0x825e);
    ax += memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, ax);
    memoryASet16(ds, 0x8260, dx);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0060;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0060;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = pop();
    imul16(memoryAGet16(es, bx + 2));
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0060;
    sub_1010b();
    bx = memoryAGet16(ds, 0x8260);
    cx = memoryAGet16(ds, 0x825e);
    si = ax;
    es = dx;
    memoryASet16(es, si + 4, cx);
    memoryASet16(es, si + 6, bx);
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_9623;
loc_94dd: // 01ed:760d
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    si = memoryAGet16(ss, bp - 10);
    si <<= 1;
    ax = memoryAGet16(ds, 0x8260);
    ax += memoryAGet16(ds, si + 33504);
    dx = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 22, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 102;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 20, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 84;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 18, ax);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 82;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 16, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0060;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 24, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    ax <<= 1;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x05;
    sub_10021();
    push(ax);
    push(dx);
    dx = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(ds, 0x834e);
    cx = pop();
    bx = pop();
    sub_1010b();
    cx = 0;
    bx = 0x0060;
    sub_1010b();
    bx = ax;
    es = dx;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 26, ax);
    if (memoryAGet16(ss, bp - 10) != 0x0004)
        goto loc_95a8;
    ax = 0x0001;
    goto loc_95aa;
loc_95a8: // 01ed:76d8
    ax = 0;
loc_95aa: // 01ed:76da
    dx = 0x00ff;
    imul16(dx);
    memoryASet(ss, bp - 27, al);
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp - 22);
    si = memoryAGet16(ss, bp - 18);
    bx = memoryAGet16(ss, bp - 24);
    dx = memoryAGet16(ss, bp - 26);
    ax = memoryAGet16(ss, bp - 20);
    es = ax;
    ax = memoryAGet16(ss, bp - 16);
    ds = ax;
    flags.direction = 0;
loc_95cc: // 01ed:76fc
    cx = bx;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    flags.carry = di < bx;
    di -= bx;
    cx = bx;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_95d9: // 01ed:7709
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_95d9;
    flags.carry = di < bx;
    di -= bx;
    cx = bx;
    al = memoryAGet(ss, bp - 27);
    al = rcr8(al, 0x01);
loc_95ed: // 01ed:771d
    al = memoryAGet(es, di);
    al = rcr8(al, 0x01);
    memoryASet(es, di, al);
    di++;
    if (--cx)
        goto loc_95ed;
    dx--;
    if (dx)
        goto loc_95cc;
    ds = pop();
    di = pop();
    si = pop();
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    ax = bp - 104;
    bx += ax;
    ax = memoryAGet16(ds, bx + 2);
    dx = memoryAGet16(ds, bx);
    bx = memoryAGet16(ss, bp - 10);
    bx <<= 1;
    bx <<= 1;
    cx = bp - 84;
    bx += cx;
    memoryASet16(ds, bx, dx);
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_9623: // 01ed:7753
    if ((short)memoryAGet16(ss, bp - 10) >= (short)0x0005)
        goto loc_962c;
    goto loc_94dd;
loc_962c: // 01ed:775c
    ax = memoryAGet16(ds, 0x825e);
    ax += memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, ax);
    memoryASet16(ds, 0x8260, dx);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_9640: // 01ed:7770
    ax = memoryAGet16(ss, bp - 6);
    if ((short)ax >= (short)memoryAGet16(ds, 0x972e))
        goto loc_964c;
    goto loc_8ef1;
loc_964c: // 01ed:777c
    push(memoryAGet16(ss, bp - 42));
    push(memoryAGet16(ss, bp - 44));
    sub_fcce();
    sp += 0x0004;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_9751() // 01ed:7881
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx + 2);
    dx = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    ax = 0;
    dx = 0x0002;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_ff73();
    ax <<= 1;
    dx = memoryAGet16(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    memoryASet16(ss, bp - 10, bx);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 0x0004);
loc_978d: // 01ed:78bd
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2); /*ggg2*/;
    di = memoryAGet16(es, bx);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 0x0002);
    if (di == 0xfefe)
        goto loc_97a9;
    bx = memoryAGet16(ss, bp + 8); es = memoryAGet16(ss, bp + 8 + 2); /*ggg2*/;
    memoryASet16(es, bx, di);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 0x0002);
    goto loc_97d5;
loc_97a9: // 01ed:78d9
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2); /*ggg2*/;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 0x0002);
    bx = memoryAGet16(ss, bp + 4); es = memoryAGet16(ss, bp + 4 + 2); /*ggg2*/;
    di = memoryAGet16(es, bx);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 0x0002);
    si = 0x0001;
    goto loc_97d0;
loc_97c5: // 01ed:78f5
    bx = memoryAGet16(ss, bp + 8); es = memoryAGet16(ss, bp + 8 + 2); /*ggg2*/;
    memoryASet16(es, bx, di);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 0x0002);
    si++;
loc_97d0: // 01ed:7900
    if (si <= memoryAGet16(ss, bp - 6))
        goto loc_97c5;
loc_97d5: // 01ed:7905
    ax = memoryAGet16(ss, bp + 8);
    if (ax < memoryAGet16(ss, bp - 10))
        goto loc_978d;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_97e3() // 01ed:7913
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x003c;
    push(si);
    push(ss);
    ax = bp - 14;
    push(ax);
    push(ds);
    ax = 0x28e2;
    push(ax);
    cx = 0x000d;
    sub_1016b();
    push(ss);
    ax = bp - 60;
    push(ax);
    push(ds);
    ax = 0x28ef;
    push(ax);
    cx = 0x002d;
    sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 14;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x28ae;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x28c8;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x28bb;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    ax = 0x28d5;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = 0x28ae;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xaa90, ax);
    memoryASet16(ds, 0xaa92, dx);
    push(dx);
    push(ax);
    sub_d234();
    sp += 0x0004;
    ax = 0x28c8;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xa70a, ax);
    memoryASet16(ds, 0xa70c, dx);
    push(dx);
    push(ax);
    sub_d234();
    sp += 0x0004;
    ax = 0x28bb;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xaaf0, ax);
    memoryASet16(ds, 0xaaf2, dx);
    push(dx);
    push(ax);
    sub_d234();
    sp += 0x0004;
    ax = 0x28d5;
    push(ax);
    sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xa6e4, ax);
    memoryASet16(ds, 0xa6e6, dx);
    push(dx);
    push(ax);
    sub_d234();
    sp += 0x0004;
    ax = 0x7abb;
    push(ax);
    sub_f0c5();
    sp++;
    sp++;
    memoryASet16(ds, 0xaafc, 0x0000);
    ax = 0;
    push(ax);
    ax = bp - 14;
    push(ax);
    sub_e422();
    sp += 0x0004;
    if (ax)
        goto loc_98d3;
    goto loc_996c;
loc_98d3: // 01ed:7a03
    si = 0;
    goto loc_994d;
  // gap 1 bytes
loc_98d8: // 01ed:7a08
    bx = si;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 43774, 0x0064);
    memoryASet16(ds, bx + 43776, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43872, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43858, 0x0000);
    ax = si;
    bx = 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    bx = 0x000f;
    ax = dx;
    imul16(bx);
    dx = bp - 60;
    ax += dx;
    push(ax);
    ax = si;
    dx = 0x000d;
    imul16(dx);
    ax += 0xab6e;
    push(ax);
    sub_f623();
    sp += 0x0004;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43802, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43816, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43844, 0x0000);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43830, 0x0000);
    si++;
loc_994d: // 01ed:7a7d
    if ((short)si >= (short)0x0007)
        goto loc_9954;
    goto loc_98d8;
loc_9954: // 01ed:7a84
    ax = 0;
    dx = 0x00cc;
    push(ax);
    push(dx);
    push(ds);
    ax = 0xaafe;
    push(ax);
    ax = bp - 14;
    push(ax);
    sub_7c33();
    sp += 0x000a;
    goto loc_997b;
loc_996c: // 01ed:7a9c
    push(ds);
    ax = 0xaafe;
    push(ax);
    ax = bp - 14;
    push(ax);
    sub_7b88();
    sp += 0x0006;
loc_997b: // 01ed:7aab
    sub_8b5d();
loc_997e: // 01ed:7aae
    sub_aec0();
    sub_9ad4();
    goto loc_997e;
}
void sub_9ad4() // 01ed:7c04
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x001e;
    push(si);
    push(di);
    memoryASet16(ss, bp - 6, 0x0000);
    sub_7b0a();
    sub_d606();
    ax = 0x0050;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0xaa8e) != 0x0000)
        goto loc_9b3b;
    ax = 0xaad2;
    push(ax);
    ax = 0xaace;
    push(ax);
    sub_ae60();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0xaad0);
    dx = memoryAGet16(ds, 0xaace);
    flags.carry = (dx + 0x7000) >= 0x10000;
    dx += 0x7000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0xaad6, dx);
    memoryASet16(ds, 0xaad8, ax);
    ax = memoryAGet16(ds, 0xaad4);
    dx = memoryAGet16(ds, 0xaad2);
    flags.carry = (dx + 0xd000) >= 0x10000;
    dx += 0xd000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0xaada, dx);
    memoryASet16(ds, 0xaadc, ax);
    memoryASet16(ds, 0xaaca, 0x0000);
    memoryASet16(ds, 0xaacc, 0x0000);
loc_9b3b: // 01ed:7c6b
    ax = memoryAGet16(ds, 0xaad8);
    dx = memoryAGet16(ds, 0xaad6);
    memoryASet16(ds, 0xa702, dx);
    memoryASet16(ds, 0xa704, ax);
    ax = memoryAGet16(ds, 0xaadc);
    dx = memoryAGet16(ds, 0xaada);
    memoryASet16(ds, 0xa706, dx);
    memoryASet16(ds, 0xa708, ax);
    ax = memoryAGet16(ds, 0xaad0);
    dx = memoryAGet16(ds, 0xaace);
    memoryASet16(ds, 0xa6fa, dx);
    memoryASet16(ds, 0xa6fc, ax);
    ax = memoryAGet16(ds, 0xaad4);
    dx = memoryAGet16(ds, 0xaad2);
    memoryASet16(ds, 0xa6fe, dx);
    memoryASet16(ds, 0xa700, ax);
    memoryASet16(ds, 0xa6e8, 0x8000);
    ax = 0;
    dx = 0x4e20;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    sub_ff73();
    push(ax);
    push(dx);
    dx = 0;
    ax = 0x4e20;
    cx = pop();
    bx = pop();
    sub_10433();
    memoryASet16(ds, 0x6ec2, ax);
    memoryASet16(ds, 0x6ec4, dx);
    memoryASet16(ds, 0x6ebc, 0x0000);
    memoryASet16(ds, 0x5652, 0x0000);
    memoryASet16(ds, 0x6c62, 0x0003);
loc_9bb0: // 01ed:7ce0
    memoryASet16(ss, bp - 2, 0x6eda);
    bx = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, bx + 28, 0x0000);
    memoryASet16(ds, bx + 30, 0x0000);
    memoryASet16(ds, bx + 32, 0x0000);
    memoryASet16(ds, bx + 34, 0x0000);
    memoryASet16(ds, bx + 40, 0x0024);
    memoryASet16(ds, 0x6ec0, 0x0000);
    ax = 0x0050;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    sub_9f2e();
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_9d18;
loc_9beb: // 01ed:7d1b
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    di = memoryAGet16(ds, bx + 42766);
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    si = memoryAGet16(ds, bx + 42768);
    bx = memoryAGet16(ss, bp - 4);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43686) != 0x0000)
        goto loc_9c16;
    goto loc_9d15;
loc_9c16: // 01ed:7d46
    ax = memoryAGet16(ss, bp - 4);
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 42770);
    if (!ax)
        goto loc_9c30;
    if (ax == 0x0001)
        goto loc_9c5d;
    goto loc_9d15;
loc_9c30: // 01ed:7d60
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x0000);
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x004d);
    goto loc_9d15;
loc_9c5d: // 01ed:7d8d
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x0000);
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = di;
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c4c);
    bx += dx;
    memoryASet16(es, bx, 0x0000);
    ax = si;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c);
    bx += ax;
    memoryASet16(es, bx, 0x0000);
    ax = si;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = di;
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c4c);
    bx += dx;
    memoryASet16(es, bx, 0x0000);
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    memoryASet16(es, bx, 0x004e);
    ax = si;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = di;
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += dx;
    memoryASet16(es, bx, 0x004f);
    ax = si;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += ax;
    memoryASet16(es, bx, 0x0050);
    ax = si;
    ax++;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = di;
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48);
    bx += dx;
    memoryASet16(es, bx, 0x0051);
loc_9d15: // 01ed:7e45
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_9d18: // 01ed:7e48
    if ((short)memoryAGet16(ss, bp - 4) >= (short)0x0010)
        goto loc_9d21;
    goto loc_9beb;
loc_9d21: // 01ed:7e51
    bx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ds, 0xa6fc);
    dx = memoryAGet16(ds, 0xa6fa);
    memoryASet16(ds, bx + 4, dx);
    memoryASet16(ds, bx + 6, ax);
    ax = memoryAGet16(ds, 0xa700);
    dx = memoryAGet16(ds, 0xa6fe);
    memoryASet16(ds, bx + 8, dx);
    memoryASet16(ds, bx + 10, ax);
    ax = memoryAGet16(ds, 0xa704);
    dx = memoryAGet16(ds, 0xa702);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ds, 0xa708);
    dx = memoryAGet16(ds, 0xa706);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    sub_2109();
    sub_2159();
    sub_2159();
    if (memoryAGet16(ss, bp - 6) != 0x0000)
        goto loc_9d6c;
    sub_adf6();
loc_9d6c: // 01ed:7e9c
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x0002)
        goto loc_9d75;
    sub_8b19();
loc_9d75: // 01ed:7ea5
    if (memoryAGet16(ss, bp - 6) == 0x0000)
        goto loc_9d7e;
    goto loc_9dfd;
loc_9d7e: // 01ed:7eae
    sub_7b0a();
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_9dcc;
loc_9d88: // 01ed:7eb8
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = bp - 12;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 18;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 18;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 10) != 0x0000)
        goto loc_9dd2;
    if (memoryAGet16(ss, bp - 8) != 0x0000)
        goto loc_9dd2;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (ax)
        goto loc_9dd2;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_9dcc: // 01ed:7efc
    if ((short)memoryAGet16(ss, bp - 4) < (short)0x003c)
        goto loc_9d88;
loc_9dd2: // 01ed:7f02
    ax = bp - 12;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 24;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 24;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 10) != 0x0000)
        goto loc_9dd2;
    if (memoryAGet16(ss, bp - 8) != 0x0000)
        goto loc_9dd2;
loc_9dfd: // 01ed:7f2d
    sub_7b0a();
    sub_d606();
    memoryASet16(ds, 0xaafc, 0x0001);
loc_9e09: // 01ed:7f39
    sub_2109();
    push(memoryAGet16(ss, bp - 2));
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 30;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 30;
    dx = ss;
    cx = 0x0006;
    sub_1018a();
    sub_c965();
    sp += 0x0008;
    sub_2159();
    sub_30c0();
    bx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ds, bx + 6);
    dx = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0xa6fa, dx);
    memoryASet16(ds, 0xa6fc, ax);
    ax = memoryAGet16(ds, bx + 10);
    dx = memoryAGet16(ds, bx + 8);
    memoryASet16(ds, 0xa6fe, dx);
    memoryASet16(ds, 0xa700, ax);
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ds, 0xa702, dx);
    memoryASet16(ds, 0xa704, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ds, 0xa706, dx);
    memoryASet16(ds, 0xa708, ax);
    sub_2b21();
    if (memoryAGet(ds, 0x5065) == 0x00)
        goto loc_9e7b;
    sub_2d0a();
loc_9e7b: // 01ed:7fab
    if (memoryAGet16(ds, 0x6ebc) == 0x0000)
        goto loc_9e85;
    goto loc_9f25;
loc_9e85: // 01ed:7fb5
    si++;
    if (memoryAGet16(ds, 0x6ec0) != 0x0000)
        goto loc_9e90;
    goto loc_9e09;
loc_9e90: // 01ed:7fc0
    memoryASet16(ds, 0xaafc, 0x0000);
    bx = memoryAGet16(ds, 0x6ec0);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43684) != 0x0000)
        goto loc_9f15;
    ax = 0x0003;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x6ec0);
    ax &= 0x00ff;
    push(ax);
    sub_6a39();
    sp++;
    sp++;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ds, 0x6ebc) == 0x0000)
        goto loc_9eca;
    memoryASet16(ds, 0x6ebc, 0x0000);
    goto loc_9f25;
loc_9eca: // 01ed:7ffa
    if (memoryAGet16(ss, bp - 6) == 0x0000)
        goto loc_9f11;
    ax = memoryAGet16(ss, bp - 6);
    if (ax == 0x0001)
        goto loc_9edf;
    if (ax == 0x0002)
        goto loc_9eed;
    goto loc_9ef0;
loc_9edf: // 01ed:800f
    bx = memoryAGet16(ds, 0x6ec0);
    bx <<= 1;
    memoryASet16(ds, bx + 43684, 0x0001);
    goto loc_9ef0;
loc_9eed: // 01ed:801d
    sub_a7e9();
loc_9ef0: // 01ed:8020
    if (memoryAGet16(ds, 0xaa94) == 0x0000)
        goto loc_9f15;
    if (memoryAGet16(ds, 0xaa9c) == 0x0000)
        goto loc_9f15;
    if (memoryAGet16(ds, 0xaa96) == 0x0000)
        goto loc_9f15;
    if (memoryAGet16(ds, 0xaa98) == 0x0000)
        goto loc_9f15;
    sub_a05c();
    goto loc_9f25;
loc_9f11: // 01ed:8041
    memoryASet16(ds, 0xaac6, memoryAGet16(ds, 0xaac6) - 1);
loc_9f15: // 01ed:8045
    if ((short)memoryAGet16(ds, 0xaac6) <= (short)0xffff)
        goto loc_9f1f;
    goto loc_9bb0;
loc_9f1f: // 01ed:804f
    sub_de4f();
    sub_8b19();
loc_9f25: // 01ed:8055
    sub_a9af();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_9f2e() // 01ed:805e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_9f4f;
loc_9f3c: // 01ed:806c
    ax = memoryAGet16(ss, bp - 2);
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 42766, 0x0000);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_9f4f: // 01ed:807f
    if ((short)memoryAGet16(ss, bp - 2) < (short)0x0010)
        goto loc_9f3c;
    cx = 0;
    goto loc_9ff1;
loc_9f5a: // 01ed:808a
    di = 0;
    goto loc_9fe7;
loc_9f5f: // 01ed:808f
    ax = cx;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax &= 0x7fff;
    si = ax;
    if ((short)ax <= 0)
        goto loc_9fe6;
    if ((short)ax >= (short)0x0100)
        goto loc_9fe6;
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 42760) != 0x0000)
        goto loc_9fe6;
    ax = si;
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 42760, di);
    ax = si;
    dx = 0x0006;
    imul16(dx);
    dx = cx;
    bx = ax;
    memoryASet16(ds, bx + 42762, dx);
    ax = si;
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 42764, 0x0000);
    ax = cx;
    imul16(memoryAGet16(ds, 0x6c08));
    dx = di;
    dx += ax;
    dx++;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c4c);
    bx += dx;
    ax = memoryAGet16(es, bx);
    ax &= 0x7fff;
    if (ax != si)
        goto loc_9fe6;
    di++;
    ax = si;
    dx = 0x0006;
    imul16(dx);
    bx = ax;
    memoryASet16(ds, bx + 42764, 0x0001);
loc_9fe6: // 01ed:8116
    di++;
loc_9fe7: // 01ed:8117
    if ((short)di >= (short)memoryAGet16(ds, 0x6c08))
        goto loc_9ff0;
    goto loc_9f5f;
loc_9ff0: // 01ed:8120
    cx++;
loc_9ff1: // 01ed:8121
    ax = cx;
    if ((short)ax >= (short)memoryAGet16(ds, 0x6c58))
        goto loc_9ffc;
    goto loc_9f5a;
loc_9ffc: // 01ed:812c
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_a002() // 01ed:8132
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8360));
    push(memoryAGet16(ds, 0x835a));
    push(memoryAGet16(ds, 0x835e));
    push(memoryAGet16(ds, 0x8358));
    sub_7f5c();
    sp += 0x000a;
    bp = pop();
    sp += 2;
}
void sub_a020() // 01ed:8150
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
    si = 0;
    goto loc_a04c;
loc_a032: // 01ed:8162
    bx = si;
    al = memoryAGet(ds, bx + di);
    memoryASet(ss, bp - 2, al);
    ax = bp - 2;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x0006;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    si++;
loc_a04c: // 01ed:817c
    push(di);
    sub_f647();
    sp++;
    sp++;
    if (ax > si)
        goto loc_a032;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_a05c() // 01ed:818c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0198;
    push(si);
    push(ss);
    ax = bp - 76;
    push(ax);
    push(ds);
    ax = 0x292e;
    push(ax);
    cx = 0x003c;
    sub_1016b();
    push(ss);
    ax = bp - 248;
    push(ax);
    push(ds);
    ax = 0x296a;
    push(ax);
    cx = 0x00ac;
    sub_1016b();
    push(ss);
    ax = bp - 408;
    push(ax);
    push(ds);
    ax = 0x2a16;
    push(ax);
    cx = 0x00a0;
    sub_1016b();
    sub_7b0a();
    ax = 0x0050;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    memoryASet16(ds, 0x6ed0, 0x3000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x3000);
    memoryASet16(ds, 0x6ed6, 0x0002);
    sub_d606();
    sub_2109();
    ax = 0x0028;
    push(ax);
    ax = 0x0002;
    dx = 0x7000;
    push(ax);
    push(dx);
    ax = 0;
    dx = 0xd000;
    push(ax);
    push(dx);
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0014;
    push(ax);
    ax = 0x002a;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    sub_8b19();
    ax = 0x2bd4;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2bf9;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2c1c;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2c41;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x0051;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    ax = 0x00f0;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_8b5d();
    ax = 0;
    dx = 0;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    sub_d606();
    sub_2109();
    sub_2159();
    sub_2159();
    sub_8b19();
    si = 0;
    memoryASet16(ss, bp - 4, 0x6400);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 8, 0x5000);
    memoryASet16(ss, bp - 6, 0x0000);
loc_a16e: // 01ed:829e
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 76;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    cl = 0x08;
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 4) + ax) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (dx + flags.carry));
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 74;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 8) + ax) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + ax);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (dx + flags.carry));
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = 0x0004;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 76;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    bx = si;
    si++;
    bx <<= 1;
    bx <<= 1;
    dx = bp - 74;
    bx += dx;
    ax += memoryAGet16(ds, bx);
    if (!ax)
        goto loc_a1e0;
    goto loc_a16e;
loc_a1e0: // 01ed:8310
    si = 0;
loc_a1e2: // 01ed:8312
    flags.carry = (memoryAGet16(ss, bp - 4) + 0x0300) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0300);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (0x0000 + flags.carry));
    flags.carry = (memoryAGet16(ss, bp - 8) + 0x0100) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0100);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (0x0000 + flags.carry));
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x0014)
        goto loc_a1e2;
    si = 0;
loc_a21a: // 01ed:834a
    flags.carry = (memoryAGet16(ds, 0x6ed0) + 0x0300) >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + 0x0300);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (0x0000 + flags.carry));
    flags.carry = (memoryAGet16(ds, 0x6ed4) + 0x0100) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + 0x0100);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (0x0000 + flags.carry));
    flags.carry = (memoryAGet16(ss, bp - 4) + 0x0300) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0300);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (0x0000 + flags.carry));
    flags.carry = (memoryAGet16(ss, bp - 8) + 0x0100) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0100);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (0x0000 + flags.carry));
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x00c8)
        goto loc_a21a;
    si = 0;
loc_a268: // 01ed:8398
    flags.carry = (memoryAGet16(ss, bp - 8) + 0x0100) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0100);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (0x0000 + flags.carry));
    if ((short)si >= (short)0x0014)
        goto loc_a281;
    flags.carry = (memoryAGet16(ds, 0x6ed4) + 0x0300) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + 0x0300);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (0x0000 + flags.carry));
loc_a281: // 01ed:83b1
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x003c)
        goto loc_a268;
    ax = 0x0014;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    si = 0;
loc_a2b0: // 01ed:83e0
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    ax = 0x0076;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    flags.carry = (dx + 0xf200) >= 0x10000;
    dx += 0xf200;
    ax += 0xffff + flags.carry;
    push(ax);
    push(dx);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    flags.carry = (dx + 0x0600) >= 0x10000;
    dx += 0x0600;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x001e)
        goto loc_a2b0;
    si = 0;
loc_a2fe: // 01ed:842e
    sub_2109();
    flags.carry = memoryAGet16(ss, bp - 4) < 0x0200;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 0x0200);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) - 0x0000 - flags.carry);
    ax = 0x0074;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x0032)
        goto loc_a2fe;
    si = 0;
loc_a32d: // 01ed:845d
    sub_2109();
    ax = 0x0074;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    ax = 0x0075;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    flags.carry = (dx + 0xf200) >= 0x10000;
    dx += 0xf200;
    ax += 0xffff + flags.carry;
    push(ax);
    push(dx);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    flags.carry = (dx + 0x0600) >= 0x10000;
    dx += 0x0600;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = si;
    si++;
    if ((short)ax < (short)0x001e)
        goto loc_a32d;
    si = 0;
loc_a37b: // 01ed:84ab
    sub_2109();
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 408;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    cl = 0x08;
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 4) + ax) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (dx + flags.carry));
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 406;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 8) + ax) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + ax);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (dx + flags.carry));
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 408;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    bx = si;
    si++;
    bx <<= 1;
    bx <<= 1;
    dx = bp - 406;
    bx += dx;
    ax += memoryAGet16(ds, bx);
    if (ax)
        goto loc_a37b;
    ax = 0x003c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_8b5d();
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    ax = 0x2c62;
    push(ax);
    sub_2853();
    sp++;
    sp++;
    ax = 0x0013;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    sub_8b19();
    ax = 0x2c6d;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2c85;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2c99;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x0078;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x003c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x000c;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x0078;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x000d;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0013;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2cab;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2cc0;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2cd5;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x00b4;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x003c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x000c;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x0014;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2ce0;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2cf7;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2d0e;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2d23;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x00f0;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x0012;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2d30;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2d42;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x00b4;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x0013;
    push(ax);
    ax = 0x001d;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2d4c;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2d64;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2d7a;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x00b4;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x0011;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2d92;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x00b4;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0011;
    push(ax);
    ax = 0x001b;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2da6;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x00b4;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_a002();
    ax = 0x003c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x000d;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x000c;
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0015;
    push(ax);
    ax = 0x001d;
    push(ax);
    ax = 0x000f;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x0019;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x2db7;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2dce;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2de7;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2dfc;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x2e13;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_8b5d();
    ax = 0x0051;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    ax = memoryAGet16(ss, bp - 10);
    dx = memoryAGet16(ss, bp - 12);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ss, bp - 14);
    dx = memoryAGet16(ss, bp - 16);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    sub_d606();
    sub_2109();
    ax = 0x0074;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    sub_8b19();
    ax = 0x001e;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    si = 0;
loc_a6f3: // 01ed:8823
    sub_2109();
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 248;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    cl = 0x08;
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 4) + ax) >= 0x10000;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + (dx + flags.carry));
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 246;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    ax <<= cl;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ss, bp - 8) + ax) >= 0x10000;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + ax);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + (dx + flags.carry));
    ax = 0x0074;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 248;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    bx = si;
    si++;
    bx <<= 1;
    bx <<= 1;
    dx = bp - 246;
    bx += dx;
    ax += memoryAGet16(ds, bx);
    if (ax)
        goto loc_a6f3;
    sub_2109();
    ax = 0x0073;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    ax = 0x003c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0005;
    push(ax);
    ax = 0x0020;
    push(ax);
    ax = 0x0003;
    push(ax);
    ax = 0x000c;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x2e22;
    push(ax);
    sub_a020();
    sp++;
    sp++;
    ax = 0x0190;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    sub_2159();
    sub_2159();
    ax = 0x0029;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = 0x0016;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0xaaf2));
    push(memoryAGet16(ds, 0xaaf0));
    sub_be82();
    sp += 0x0008;
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_a7e9() // 01ed:8919
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    ax = 0x0050;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    ax = 0x0012;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    si = 0x6eda;
    memoryASet16(ds, si + 28, 0x0000);
    memoryASet16(ds, si + 30, 0x0000);
    memoryASet16(ds, si + 32, 0x0000);
    memoryASet16(ds, si + 34, 0x0000);
    memoryASet16(ds, si + 40, 0x0024);
    ax = memoryAGet16(ds, 0x28a4);
    dx = memoryAGet16(ds, 0x28a2);
    memoryASet16(ds, 0xa6fa, dx);
    memoryASet16(ds, 0xa6fc, ax);
    memoryASet16(ds, 0xaaf4, dx);
    memoryASet16(ds, 0xaaf6, ax);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ds, 0x28a8);
    dx = memoryAGet16(ds, 0x28a6);
    memoryASet16(ds, 0xa6fe, dx);
    memoryASet16(ds, 0xa700, ax);
    memoryASet16(ds, 0xaaf8, dx);
    memoryASet16(ds, 0xaafa, ax);
    memoryASet16(ds, si + 8, dx);
    memoryASet16(ds, si + 10, ax);
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    flags.carry = (dx + 0x7000) >= 0x10000;
    dx += 0x7000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    memoryASet16(ds, 0xa702, dx);
    memoryASet16(ds, 0xa704, ax);
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    flags.carry = (dx + 0xd000) >= 0x10000;
    dx += 0xd000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    memoryASet16(ds, 0xa706, dx);
    memoryASet16(ds, 0xa708, ax);
    sub_2109();
    sub_d606();
    sub_2159();
    sub_8b19();
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_ff73();
    memoryASet16(ss, bp - 2, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    sub_ff73();
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 8, 0x0152);
    if (memoryAGet16(ds, 0x28aa) == 0x0000)
        goto loc_a8ce;
    memoryASet16(ss, bp - 8, 0x0156);
loc_a8ce: // 01ed:89fe
    di = 0;
    goto loc_a913;
loc_a8d2: // 01ed:8a02
    sub_2109();
    sub_d606();
    ax = di;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    if (dx)
        goto loc_a8f4;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    ax = memoryAGet16(ss, bp - 6);
    if ((short)ax <= (short)0x0003)
        goto loc_a8f4;
    memoryASet16(ss, bp - 6, 0x0000);
loc_a8f4: // 01ed:8a24
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 6);
    ax += memoryAGet16(ss, bp - 8);
    memoryASet16(es, bx, ax);
    sub_2159();
    di++;
loc_a913: // 01ed:8a43
    if ((short)di < (short)0x0010)
        goto loc_a8d2;
    memoryASet16(ss, bp - 8, 0x0145);
    if (memoryAGet16(ds, 0x28aa) == 0x0000)
        goto loc_a929;
    memoryASet16(ss, bp - 8, 0x0063);
loc_a929: // 01ed:8a59
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(es, bx, ax);
loc_a941: // 01ed:8a71
    sub_2109();
    ax = bp - 14;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 20;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 20;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    push(memoryAGet16(ds, si + 40));
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    sub_30c0();
    sub_2b21();
    if (memoryAGet16(ss, bp - 12) != 0x0000)
        goto loc_a941;
    if (memoryAGet16(ss, bp - 10) != 0x0000)
        goto loc_a941;
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ds, 0xa702, dx);
    memoryASet16(ds, 0xa704, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ds, 0xa706, dx);
    memoryASet16(ds, 0xa708, ax);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_a9af() // 01ed:8adf
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x006a;
    push(si);
    push(di);
    push(ss);
    ax = bp - 56;
    push(ax);
    push(ds);
    ax = 0x2ab6;
    push(ax);
    cx = 0x000d;
    sub_1016b();
    push(ss);
    ax = bp - 106;
    push(ax);
    push(ds);
    ax = 0x2ac3;
    push(ax);
    cx = 0x0031;
    sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 56;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    di = 0;
    si = 0;
    goto loc_aa0f;
loc_a9eb: // 01ed:8b1b
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43776);
    dx = memoryAGet16(ds, bx + 43774);
    if ((short)ax > (short)memoryAGet16(ds, 0xaacc))
        goto loc_aa0e;
    if ((short)ax < (short)memoryAGet16(ds, 0xaacc))
        goto loc_aa07;
    if (dx >= memoryAGet16(ds, 0xaaca))
        goto loc_aa0e;
loc_aa07: // 01ed:8b37
    ax = si;
    ax++;
    di = ax;
    goto loc_aa14;
loc_aa0e: // 01ed:8b3e
    si++;
loc_aa0f: // 01ed:8b3f
    if ((short)si < (short)0x0007)
        goto loc_a9eb;
loc_aa14: // 01ed:8b44
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    sub_d606();
    sub_2109();
    sub_2159();
    if (!di)
        goto loc_aa67;
    ax = 0x000d;
    push(ax);
    ax = 0x0020;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, bp - 10, ax);
    goto loc_aa73;
loc_aa67: // 01ed:8b97
    memoryASet16(ds, 0x8282, 0x0007);
    memoryASet16(ds, 0x82f8, 0x000a);
loc_aa73: // 01ed:8ba3
    ax = 0x0007;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax += 0x0009;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0010;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    ax = di;
    di--;
    if (ax)
        goto loc_aaa1;
    goto loc_acf7;
loc_aaa1: // 01ed:8bd1
    ax = memoryAGet16(ss, bp - 8);
    ax++;
    memoryASet16(ds, 0x8354, ax);
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax += 0x0004;
    memoryASet16(ds, 0x82f8, ax);
    ax = 0x2e36;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x000a;
    push(ax);
    ax = bp - 24;
    push(ax);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    sub_f29b();
    sp += 0x0008;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x8354);
    ax += 0x000b;
    memoryASet16(ds, 0x8282, ax);
    if (memoryAGet16(ds, 0xaa94) == 0x0000)
        goto loc_ab06;
    ax = 0x01c0;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0xfffc;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d809();
    sp += 0x0006;
loc_ab06: // 01ed:8c36
    if (memoryAGet16(ds, 0xaa9c) == 0x0000)
        goto loc_ab2c;
    ax = 0x01c1;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0xfffc;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax++;
    ax++;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_ab2c: // 01ed:8c5c
    if (memoryAGet16(ds, 0xaa96) == 0x0000)
        goto loc_ab53;
    ax = 0x01c2;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0xfffc;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax += 0x0004;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_ab53: // 01ed:8c83
    if (memoryAGet16(ds, 0xaa98) == 0x0000)
        goto loc_ab7a;
    ax = 0x01c3;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0xfffc;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    ax += 0x0006;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_ab7a: // 01ed:8caa
    ax = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, ax);
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 0x0004);
    ax = 0x2e46;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2e5f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = di;
    dx = 0x0007;
    imul16(dx);
    dx = bp - 106;
    ax += dx;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2e6d;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    si = 0x0005;
    goto loc_ac51;
loc_abb8: // 01ed:8ce8
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43776);
    dx = memoryAGet16(ds, bx + 43774);
    bx = si;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 43778, dx);
    memoryASet16(ds, bx + 43780, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43858);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43860, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43872);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43874, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43802);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43804, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43816);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43818, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43844);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43846, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43830);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 43832, ax);
    ax = si;
    dx = 0x000d;
    imul16(dx);
    ax += 0xab6e;
    push(ax);
    ax = si;
    dx = 0x000d;
    imul16(dx);
    ax += 0xab7b;
    push(ax);
    sub_f623();
    sp += 0x0004;
    si--;
loc_ac51: // 01ed:8d81
    if ((short)si < (short)di)
        goto loc_ac58;
    goto loc_abb8;
loc_ac58: // 01ed:8d88
    sub_7b0a();
    ax = 0x000c;
    push(ax);
    ax = di;
    dx = 0x000d;
    imul16(dx);
    ax += 0xab6e;
    push(ax);
    sub_8487();
    sp += 0x0004;
    bx = di;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaacc);
    dx = memoryAGet16(ds, 0xaaca);
    memoryASet16(ds, bx + 43774, dx);
    memoryASet16(ds, bx + 43776, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaa94);
    memoryASet16(ds, bx + 43802, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaa9c);
    memoryASet16(ds, bx + 43816, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaa96);
    memoryASet16(ds, bx + 43844, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaa98);
    memoryASet16(ds, bx + 43830, ax);
    ax = 0;
    si = ax;
    memoryASet16(ss, bp - 14, ax);
    goto loc_acc6;
loc_acba: // 01ed:8dea
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 43742);
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) + ax);
    si++;
loc_acc6: // 01ed:8df6
    if ((short)si < (short)0x0008)
        goto loc_acba;
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ss, bp - 14);
    memoryASet16(ds, bx + 43858, ax);
    bx = di;
    bx <<= 1;
    ax = memoryAGet16(ds, 0xaaee);
    memoryASet16(ds, bx + 43872, ax);
    ax = 0;
    dx = 0x00cc;
    push(ax);
    push(dx);
    push(ds);
    ax = 0xaafe;
    push(ax);
    ax = bp - 56;
    push(ax);
    sub_7c33();
    sp += 0x000a;
loc_acf7: // 01ed:8e27
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 30;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 30;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_acf7;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_acf7;
    sub_7b0a();
    if ((short)di >= 0)
        goto loc_ad75;
    si = 0;
    goto loc_ad6f;
loc_ad2d: // 01ed:8e5d
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 36;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 36;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_ad75;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_ad75;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (ax)
        goto loc_ad75;
    si++;
loc_ad6f: // 01ed:8e9f
    if ((short)si < (short)0x0168)
        goto loc_ad2d;
loc_ad75: // 01ed:8ea5
    sub_8b5d();
    sub_7b0a();
    ax = 0x005a;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    sub_b8f4();
    sub_8b19();
    memoryASet16(ss, bp - 12, 0x0960);
    memoryASet16(ds, 0xaafc, 0x0000);
loc_ad95: // 01ed:8ec5
    sub_2109();
    sub_2159();
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 42;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 42;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    sub_2b21();
    if (!ax)
        goto loc_adc4;
    sub_b8f4();
loc_adc4: // 01ed:8ef4
    ax = memoryAGet16(ss, bp - 12);
    ax -= memoryAGet16(ds, 0x5b14);
    memoryASet16(ss, bp - 12, ax);
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_aded;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_aded;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (ax)
        goto loc_aded;
    if ((short)memoryAGet16(ss, bp - 12) > (short)0x0000)
        goto loc_ad95;
loc_aded: // 01ed:8f1d
    sub_8b5d();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_adf6() // 01ed:8f26
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    ax = 0x0004;
    push(ax);
    ax = 0x0010;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, bp - 2, ax);
    ax = 0x2e88;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    di = memoryAGet16(ds, 0xaac6);
    if ((short)di <= (short)0x0006)
        goto loc_ae26;
    di = 0x0006;
loc_ae26: // 01ed:8f56
    si = 0;
    goto loc_ae4d;
loc_ae2a: // 01ed:8f5a
    ax = 0x0090;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x000b;
    push(ax);
    ax = si;
    ax <<= 1;
    dx = memoryAGet16(ss, bp - 2);
    dx += ax;
    dx++;
    push(dx);
    sub_d9fd();
    sp += 0x0006;
    si++;
loc_ae4d: // 01ed:8f7d
    if ((short)si < (short)di)
        goto loc_ae2a;
    ax = 0x0029;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_ae60() // 01ed:8f90
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    di = 0;
    goto loc_aeb4;
loc_ae6b: // 01ed:8f9b
    si = 0;
    goto loc_aead;
loc_ae6f: // 01ed:8f9f
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0x00ff)
        goto loc_aeac;
    ax = si;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    bx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, dx);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cl = 0x0c;
    sub_10021();
    bx = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, dx);
    goto loc_aeba;
loc_aeac: // 01ed:8fdc
    si++;
loc_aead: // 01ed:8fdd
    if ((short)si < (short)memoryAGet16(ds, 0x6c08))
        goto loc_ae6f;
    di++;
loc_aeb4: // 01ed:8fe4
    if ((short)di < (short)memoryAGet16(ds, 0x6c58))
        goto loc_ae6b;
loc_aeba: // 01ed:8fea
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_aec0() // 01ed:8ff0
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0016;
    push(si);
    push(di);
    memoryASet16(ds, 0xaa8e, 0x0000);
    memoryASet16(ds, 0xaac6, 0x0004);
    memoryASet16(ds, 0xaac8, 0x0000);
    memoryASet16(ds, 0xaa9a, 0x0000);
    memoryASet16(ds, 0xaa94, 0x0000);
    memoryASet16(ds, 0xaa9c, 0x0000);
    memoryASet16(ds, 0xaa96, 0x0000);
    memoryASet16(ds, 0xaa98, 0x0000);
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_af0d;
loc_aeff: // 01ed:902f
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    memoryASet16(ds, bx + 43742, 0x0000);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_af0d: // 01ed:903d
    if ((short)memoryAGet16(ss, bp - 8) < (short)0x0008)
        goto loc_aeff;
    memoryASet16(ds, 0xaa9e, 0x0000);
    memoryASet16(ds, 0xaaa0, 0x0000);
    memoryASet16(ds, 0xaaa2, 0x0000);
    memoryASet16(ds, 0xaaa4, 0x0000);
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_af40;
loc_af32: // 01ed:9062
    bx = memoryAGet16(ss, bp - 8);
    bx <<= 1;
    memoryASet16(ds, bx + 43686, 0x0000);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_af40: // 01ed:9070
    if ((short)memoryAGet16(ss, bp - 8) < (short)0x0010)
        goto loc_af32;
loc_af46: // 01ed:9076
    memoryASet16(ds, 0x5652, 0x0000);
    memoryASet16(ds, 0x6c62, 0x0003);
    sub_d606();
    ax = 0x005a;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x28ac) == 0x0000)
        goto loc_afa4;
    ax = 0x005a;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    memoryASet16(ds, 0x6ed0, 0x8000);
    memoryASet16(ds, 0x6ed2, 0x0006);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_2109();
    sub_2159();
    sub_8b19();
    di = 0x0960;
    si = 0x0004;
    sub_c132();
    sub_8b5d();
    memoryASet16(ds, 0x28ac, 0x0000);
loc_afa4: // 01ed:90d4
    di = 0x0960;
    si = 0;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_2109();
    sub_b6a3();
    sub_8b19();
    sub_7b0a();
loc_afd0: // 01ed:9100
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 16;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 16;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    sub_2109();
    sub_2159();
    sub_2b21();
    if (!ax)
        goto loc_b022;
    bx = si;
    if (bx > 0x0003)
        goto loc_b022;
    bx <<= 1;
    indirectJump(cs, memoryAGet16(cs, bx + 37511)); // 01ed:9135;
  // gap 24 bytes
loc_b022: // 01ed:9152
    ax = di;
    ax -= memoryAGet16(ds, 0x5b14);
    di = ax;
    if ((short)ax <= 0)
        goto loc_b031;
    goto loc_b0ff;
loc_b031: // 01ed:9161
    sub_8b5d();
    ax = si;
    if (!ax)
        goto loc_b047;
    if (ax == 0x0001)
        goto loc_b064;
    if (ax == 0x0002)
        goto loc_b081;
    goto loc_b0cb;
loc_b047: // 01ed:9177
    memoryASet16(ds, 0x6ed0, 0xf000);
    memoryASet16(ds, 0x6ed2, 0x0003);
    memoryASet16(ds, 0x6ed4, 0x1c00);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_b71c();
    goto loc_b0cb;
loc_b064: // 01ed:9194
    memoryASet16(ds, 0x6ed0, 0x4000);
    memoryASet16(ds, 0x6ed2, 0x0005);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_b8f4();
    goto loc_b0cb;
loc_b081: // 01ed:91b1
    si++;
    ax = 0x0001;
    push(ax);
    sub_c20b();
    sp++;
    sp++;
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 22;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 22;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (ax)
        goto loc_b0c3;
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_b0c3;
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_b0c8;
loc_b0c3: // 01ed:91f3
    di = 0x0960;
    goto loc_b0ff;
loc_b0c8: // 01ed:91f8
    sub_8b5d();
loc_b0cb: // 01ed:91fb
    di = 0x0960;
    sub_2109();
    sub_2159();
    si++;
    ax = si;
    if (ax != 0x0004)
        goto loc_b0fc;
    si = 0;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_b6a3();
loc_b0fc: // 01ed:922c
    sub_8b19();
loc_b0ff: // 01ed:922f
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (ax)
        goto loc_b122;
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_b122;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_b122;
    if (memoryAGet16(ds, 0xa6f8) != 0x0000)
        goto loc_b122;
    goto loc_afd0;
loc_b122: // 01ed:9252
    memoryASet16(ds, 0xa6f8, 0x0000);
    if (memoryAGet16(ds, 0x6ed2) != 0x0000)
        goto loc_b137;
    if (memoryAGet16(ds, 0x6ed0) == 0x2000)
        goto loc_b13a;
loc_b137: // 01ed:9267
    sub_8b5d();
loc_b13a: // 01ed:926a
    push(si);
    sub_b15f();
    sp++;
    sp++;
    memoryASet16(ss, bp - 10, ax);
    if (ax)
        goto loc_b14a;
    goto loc_af46;
loc_b14a: // 01ed:927a
    sub_7b0a();
    sub_8b5d();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b15f() // 01ed:928f
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0020;
    push(si);
    push(di);
loc_b167: // 01ed:9297
    if (memoryAGet16(ds, 0x6ed2) != 0x0000)
        goto loc_b176;
    if (memoryAGet16(ds, 0x6ed0) == 0x2000)
        goto loc_b17e;
loc_b176: // 01ed:92a6
    sub_b580();
    sub_8b19();
    goto loc_b181;
loc_b17e: // 01ed:92ae
    sub_b580();
loc_b181: // 01ed:92b1
    sub_7b0a();
    ax = 0;
    memoryASet16(ss, bp - 2, ax);
    di = ax;
    memoryASet16(ss, bp - 8, 0x0014);
loc_b190: // 01ed:92c0
    si = 0;
    goto loc_b1c3;
loc_b194: // 01ed:92c4
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = bp - 14;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 20;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 20;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 14) != 0x0008)
        goto loc_b1c8;
    si++;
loc_b1c3: // 01ed:92f3
    if ((short)si < (short)0x0006)
        goto loc_b194;
loc_b1c8: // 01ed:92f8
    ax = di;
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    di++;
    ax = di;
    if ((short)ax <= (short)0x0002)
        goto loc_b1ec;
    di = 0;
loc_b1ec: // 01ed:931c
    ax = memoryAGet16(ss, bp - 14);
    if (!ax)
        goto loc_b1fe;
    if (ax != 0x0004)
        goto loc_b1fb;
    goto loc_b2e1;
loc_b1fb: // 01ed:932b
    goto loc_b3c3;
loc_b1fe: // 01ed:932e
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_b25c;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) - 1);
    si = 0;
    goto loc_b255;
loc_b20b: // 01ed:933b
    ax = di;
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= si;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax -= si;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    di++;
    ax = di;
    if ((short)ax <= (short)0x0002)
        goto loc_b254;
    di = 0;
loc_b254: // 01ed:9384
    si++;
loc_b255: // 01ed:9385
    if ((short)si < (short)0x0008)
        goto loc_b20b;
    goto loc_b279;
loc_b25c: // 01ed:938c
    memoryASet16(ss, bp - 2, 0x0007);
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
loc_b279: // 01ed:93a9
    ax = memoryAGet16(ds, 0xaaf8);
    ax += memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x82f8, ax);
    ax = di;
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    goto loc_b2c6;
loc_b29e: // 01ed:93ce
    ax = bp - 14;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 26;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 26;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_b2c6: // 01ed:93f6
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) - 1);
    if (!ax)
        goto loc_b2d6;
    if (memoryAGet16(ss, bp - 14) != 0x0008)
        goto loc_b29e;
loc_b2d6: // 01ed:9406
    memoryASet16(ss, bp - 8, 0x0014);
    sub_7b0a();
    goto loc_b3cc;
loc_b2e1: // 01ed:9411
    if ((short)memoryAGet16(ss, bp - 2) >= (short)0x0007)
        goto loc_b33f;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
    si = 0;
    goto loc_b338;
loc_b2ee: // 01ed:941e
    ax = di;
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += si;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    di++;
    ax = di;
    if ((short)ax <= (short)0x0002)
        goto loc_b337;
    di = 0;
loc_b337: // 01ed:9467
    si++;
loc_b338: // 01ed:9468
    if ((short)si < (short)0x0008)
        goto loc_b2ee;
    goto loc_b35c;
loc_b33f: // 01ed:946f
    memoryASet16(ss, bp - 2, 0x0000);
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
loc_b35c: // 01ed:948c
    ax = memoryAGet16(ds, 0xaaf8);
    ax += memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x82f8, ax);
    ax = di;
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    goto loc_b3a9;
loc_b381: // 01ed:94b1
    ax = bp - 14;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 32;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 32;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_b3a9: // 01ed:94d9
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) - 1);
    if (!ax)
        goto loc_b3b9;
    if (memoryAGet16(ss, bp - 14) != 0x0008)
        goto loc_b381;
loc_b3b9: // 01ed:94e9
    memoryASet16(ss, bp - 8, 0x0014);
    sub_7b0a();
    goto loc_b3cc;
loc_b3c3: // 01ed:94f3
    sync();
    ax = 0x0007;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_b3cc: // 01ed:94fc
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    ax &= 0x00ff;
    memoryASet16(ss, bp - 6, ax);
    if (!ax)
        goto loc_b3eb;
    if (memoryAGet16(ds, 0x833e) == 0x0000)
        goto loc_b3eb;
    memoryASet16(ss, bp - 12, 0x0001);
loc_b3eb: // 01ed:951b
    if (memoryAGet16(ss, bp - 6) == 0x0020)
        goto loc_b3f7;
    if (memoryAGet16(ss, bp - 6) != 0x000d)
        goto loc_b403;
loc_b3f7: // 01ed:9527
    if (memoryAGet16(ds, 0x833e) != 0x0000)
        goto loc_b403;
    memoryASet16(ss, bp - 12, 0x0001);
loc_b403: // 01ed:9533
    sub_2b21();
    if (!ax)
        goto loc_b416;
    sub_b580();
    ax = memoryAGet16(ds, 0xaaf8);
    ax += memoryAGet16(ss, bp - 2);
    memoryASet16(ds, 0x82f8, ax);
loc_b416: // 01ed:9546
    if (memoryAGet16(ss, bp - 12) != 0x0000)
        goto loc_b425;
    if (memoryAGet16(ss, bp - 10) != 0x0000)
        goto loc_b425;
    goto loc_b190;
loc_b425: // 01ed:9555
    sub_7b0a();
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    bx = memoryAGet16(ss, bp - 2);
    if (bx > 0x0007)
        goto loc_b49a;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_b440;
        case 2: goto loc_b447;
        case 4: goto loc_b44f;
        case 6: goto loc_b459;
        case 8: goto loc_b466;
        case 10: goto loc_b473;
        case 12: goto loc_b485;
        case 14: goto loc_b492;
        default:
            stop();
    }
loc_b440: // 01ed:9570
    memoryASet16(ss, bp - 4, 0x0001);
    goto loc_b49a;
loc_b447: // 01ed:9577
    sub_bb1e();
    memoryASet16(ss, bp - 4, ax);
    goto loc_b49a;
loc_b44f: // 01ed:957f
    memoryASet16(ss, bp - 4, 0x0000);
    sub_bc43();
    goto loc_b49a;
loc_b459: // 01ed:9589
    memoryASet16(ss, bp - 4, 0x0000);
    sub_8b5d();
    sub_b602();
    goto loc_b497;
loc_b466: // 01ed:9596
    memoryASet16(ss, bp - 4, 0x0000);
    sub_8b5d();
    sub_b929();
    goto loc_b497;
loc_b473: // 01ed:95a3
    memoryASet16(ss, bp - 4, 0x0000);
    sub_8b5d();
    ax = 0;
    push(ax);
    sub_c20b();
    sp++;
    sp++;
    goto loc_b497;
loc_b485: // 01ed:95b5
    memoryASet16(ss, bp - 4, 0x0000);
    sub_8b5d();
    sub_b5b2();
    goto loc_b497;
loc_b492: // 01ed:95c2
    memoryASet16(ss, bp - 4, 0x0000);
loc_b497: // 01ed:95c7
    sub_8b5d();
loc_b49a: // 01ed:95ca
    if (memoryAGet16(ss, bp - 2) == 0x0007)
        goto loc_b4a9;
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_b4a9;
    goto loc_b167;
loc_b4a9: // 01ed:95d9
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_b4b4;
    ax = 0x0001;
    goto loc_b4b6;
loc_b4b4: // 01ed:95e4
    ax = 0;
loc_b4b6: // 01ed:95e6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b4cd() // 01ed:95fd
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x000a;
    push(ax);
    ax = 0x0012;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x8282);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf4, ax);
    memoryASet16(ds, 0xaaf6, dx);
    ax = memoryAGet16(ds, 0x82f8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf8, ax);
    memoryASet16(ds, 0xaafa, dx);
    ax = 0x2e96;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2ea3;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2eb5;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2ebf;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2ecf;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2edf;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2ef1;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2eff;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x2f11;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    bx = memoryAGet16(ds, 0x833e);
    if (bx > 0x0003)
        goto loc_b568;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_b555;
        case 2: goto loc_b55a;
        case 4: goto loc_b55f;
        case 6: goto loc_b55f;
        default:
            stop();
    }
loc_b555: // 01ed:9685
    ax = 0x2f1a;
    goto loc_b562;
loc_b55a: // 01ed:968a
    ax = 0x2f21;
    goto loc_b562;
loc_b55f: // 01ed:968f
    ax = 0x2f27;
loc_b562: // 01ed:9692
    push(ax);
    sub_81a2();
    sp++;
    sp++;
loc_b568: // 01ed:9698
    ax = memoryAGet16(ds, 0xaaf4);
    ax++;
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ds, 0xaaf8);
    memoryASet16(ds, 0x82f8, ax);
    bp = pop();
    sp += 2;
}
void sub_b580() // 01ed:96b0
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_b6a3();
    memoryASet16(ds, 0x5658, 0x95fd);
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    bp = pop();
    sp += 2;
}
void sub_b5b2() // 01ed:96e2
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x3116;
    push(ax);
    sub_2853();
    sp++;
    sp++;
    sub_8b19();
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_8b5d();
    ax = 0x3123;
    push(ax);
    sub_2853();
    sp++;
    sp++;
    sub_8b19();
    ax = 0x005a;
    push(ax);
    sub_253b();
    sp++;
    sp++;
    ax = 0x012c;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = 0x0016;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0xa6e6));
    push(memoryAGet16(ds, 0xa6e4));
    sub_be82();
    sp += 0x0008;
    bp = pop();
    sp += 2;
}
void sub_b602() // 01ed:9732
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    memoryASet16(ds, 0x6ed0, 0xf000);
    memoryASet16(ds, 0x6ed2, 0x0003);
    memoryASet16(ds, 0x6ed4, 0x1c00);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_2109();
    sub_b71c();
    sub_8b19();
    sub_7b0a();
loc_b62f: // 01ed:975f
    sub_2109();
    sub_2159();
    sub_2b21();
    if (!ax)
        goto loc_b63f;
    sub_b71c();
loc_b63f: // 01ed:976f
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 12;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 12;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_b677;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_b677;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (!ax)
        goto loc_b62f;
loc_b677: // 01ed:97a7
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b67b() // 01ed:97ab
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0008;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0002;
    push(ax);
    ax = 0x00b6;
    push(ax);
    ax = 0x0010;
    push(ax);
    sub_d986();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_b6a3() // 01ed:97d3
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x5658, 0x97ab);
    sub_2109();
    sub_2159();
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    sub_7b0a();
    bp = pop();
    sp += 2;
}
void sub_b6c0() // 01ed:97f0
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x01b8;
    push(si);
    push(ss);
    ax = bp - 440;
    push(ax);
    push(ds);
    ax = 0x2f30;
    push(ax);
    cx = 0x01b8;
    sub_1016b();
    ax = 0x0001;
    push(ax);
    ax = 0x0017;
    push(ax);
    ax = 0x0011;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0007;
    memoryASet16(ds, 0x8354, ax);
    memoryASet16(ds, 0x8282, ax);
    memoryASet16(ds, 0x82f8, 0x0009);
    si = 0;
    goto loc_b712;
loc_b6fe: // 01ed:982e
    ax = si;
    dx = 0x0028;
    imul16(dx);
    dx = bp - 440;
    ax += dx;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    si++;
loc_b712: // 01ed:9842
    if ((short)si < (short)0x000b)
        goto loc_b6fe;
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b71c() // 01ed:984c
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x5658, 0x97f0);
    sub_d606();
    sub_2109();
    sub_2159();
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    sub_7b0a();
    bp = pop();
    sp += 2;
}
void sub_b73c() // 01ed:986c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0010;
    push(si);
    push(di);
    ax = 0x0003;
    push(ax);
    ax = 0x0007;
    push(ax);
    ax = 0x000f;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0004;
    push(ax);
    ax = 0x002c;
    push(ax);
    ax = 0x0009;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0005;
    push(ax);
    ax = 0x002c;
    push(ax);
    ax = 0x0017;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0006;
    push(ax);
    ax = 0x002c;
    push(ax);
    ax = 0x0021;
    push(ax);
    sub_d986();
    sp += 0x0006;
    si = 0;
    goto loc_b8e6;
loc_b791: // 01ed:98c1
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6ed2));
    push(memoryAGet16(ds, 0x6ed0));
    sub_ff73();
    memoryASet16(ss, bp - 2, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6ed6));
    push(memoryAGet16(ds, 0x6ed4));
    sub_ff73();
    memoryASet16(ss, bp - 4, ax);
    ax = si;
    bx = 0x0004;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    di = dx;
    ax = si;
    ax <<= 1;
    ax += 0x0008;
    memoryASet16(ds, 0x82f8, ax);
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43802) == 0x0000)
        goto loc_b7ff;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax += memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ss, bp - 2);
    dx += ax;
    dx += 0x000e;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    ax = di;
    ax += 0x00dd;
    memoryASet16(es, bx, ax);
loc_b7ff: // 01ed:992f
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43816) == 0x0000)
        goto loc_b832;
    ax = memoryAGet16(ds, 0x82f8);
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax += memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ss, bp - 2);
    dx += ax;
    dx += 0x000f;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    ax = di;
    ax += 0x00ed;
    memoryASet16(es, bx, ax);
loc_b832: // 01ed:9962
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43844) == 0x0000)
        goto loc_b865;
    ax = memoryAGet16(ds, 0x82f8);
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax += memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ss, bp - 2);
    dx += ax;
    dx += 0x0010;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    ax = di;
    ax += 0x00f1;
    memoryASet16(es, bx, ax);
loc_b865: // 01ed:9995
    bx = si;
    bx <<= 1;
    if (memoryAGet16(ds, bx + 43830) == 0x0000)
        goto loc_b898;
    ax = memoryAGet16(ds, 0x82f8);
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    ax += memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    dx = memoryAGet16(ss, bp - 2);
    dx += ax;
    dx += 0x0011;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += dx;
    ax = di;
    ax += 0x00f5;
    memoryASet16(es, bx, ax);
loc_b898: // 01ed:99c8
    ax = 0x000a;
    push(ax);
    ax = bp - 16;
    push(ax);
    bx = si;
    bx <<= 1;
    bx <<= 1;
    push(memoryAGet16(ds, bx + 43776));
    push(memoryAGet16(ds, bx + 43774));
    sub_f29b();
    sp += 0x0008;
    ax = bp - 16;
    push(ax);
    sub_f647();
    sp++;
    sp++;
    dx = 0x001d;
    dx -= ax;
    memoryASet16(ds, 0x8282, dx);
    ax = bp - 16;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x0009);
    ax = si;
    dx = 0x000d;
    imul16(dx);
    ax += 0xab6e;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    si++;
loc_b8e6: // 01ed:9a16
    if ((short)si >= (short)0x0007)
        goto loc_b8ee;
    goto loc_b791;
loc_b8ee: // 01ed:9a1e
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b8f4() // 01ed:9a24
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x6ed0, 0x4000);
    memoryASet16(ds, 0x6ed2, 0x0005);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_2109();
    memoryASet16(ds, 0x5658, 0x986c);
    sub_2159();
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    bp = pop();
    sp += 2;
}
void sub_b929() // 01ed:9a59
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000c;
    sub_b8f4();
    sub_8b19();
    sub_7b0a();
loc_b938: // 01ed:9a68
    sub_2109();
    sub_2159();
    sub_2b21();
    if (!ax)
        goto loc_b948;
    sub_b8f4();
loc_b948: // 01ed:9a78
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 12;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 12;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_b980;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_b980;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (!ax)
        goto loc_b938;
loc_b980: // 01ed:9ab0
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_b984() // 01ed:9ab4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0010;
    push(si);
    si = 0;
    push(ss);
    ax = bp - 16;
    push(ax);
    push(ds);
    ax = 0x30e8;
    push(ax);
    cx = 0x000d;
    sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 16;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    if (memoryAGet16(ds, 0xaafc) != 0x0000)
        goto loc_b9e4;
    ax = 0x0003;
    push(ax);
    ax = 0x0016;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x3130;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3147;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x315f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_7b0a();
    sub_d055();
    goto loc_bb19;
loc_b9e4: // 01ed:9b14
    ax = 0x0003;
    push(ax);
    ax = 0x0014;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x3170;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3185;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x319b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
loc_ba0d: // 01ed:9b3d
    sub_8138();
    al &= 0xff;
    memoryASet(ss, bp - 1, al);
    if (al == 0x1b)
        goto loc_ba21;
    if ((char)al < (char)0x31)
        goto loc_ba0d;
    if ((char)al > (char)0x39)
        goto loc_ba0d;
loc_ba21: // 01ed:9b51
    if (memoryAGet(ss, bp - 1) != 0x1b)
        goto loc_ba2a;
    goto loc_bb19;
loc_ba2a: // 01ed:9b5a
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 11, al);
    ax = 0;
    push(ax);
    ax = bp - 16;
    push(ax);
    sub_e422();
    sp += 0x0004;
    if (ax)
        goto loc_ba97;
    ax = 0x0003;
    push(ax);
    ax = 0x0014;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x31ab;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x31bf;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x31d0;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
loc_ba6a: // 01ed:9b9a
    sub_8138();
    ax &= 0x00ff;
    push(ax);
    sub_ec06();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    if (al == 0x1b)
        goto loc_ba85;
    if (al == 0x59)
        goto loc_ba85;
    if (al != 0x4e)
        goto loc_ba6a;
loc_ba85: // 01ed:9bb5
    if (memoryAGet(ss, bp - 1) != 0x1b)
        goto loc_ba8e;
    goto loc_bb19;
loc_ba8e: // 01ed:9bbe
    if (memoryAGet(ss, bp - 1) != 0x59)
        goto loc_ba98;
    si++;
    goto loc_ba98;
loc_ba97: // 01ed:9bc7
    si++;
loc_ba98: // 01ed:9bc8
    if (si)
        goto loc_ba9f;
    goto loc_b9e4;
loc_ba9f: // 01ed:9bcf
    ax = memoryAGet16(ds, 0xa704);
    dx = memoryAGet16(ds, 0xa702);
    memoryASet16(ds, 0xaad6, dx);
    memoryASet16(ds, 0xaad8, ax);
    ax = memoryAGet16(ds, 0xa708);
    dx = memoryAGet16(ds, 0xa706);
    memoryASet16(ds, 0xaada, dx);
    memoryASet16(ds, 0xaadc, ax);
    ax = memoryAGet16(ds, 0xa6fc);
    dx = memoryAGet16(ds, 0xa6fa);
    memoryASet16(ds, 0xaace, dx);
    memoryASet16(ds, 0xaad0, ax);
    ax = memoryAGet16(ds, 0xa700);
    dx = memoryAGet16(ds, 0xa6fe);
    memoryASet16(ds, 0xaad2, dx);
    memoryASet16(ds, 0xaad4, ax);
    ax = 0;
    dx = 0x005c;
    push(ax);
    push(dx);
    ax = 0xaa94;
    push(ds);
    push(ax);
    ax = bp - 16;
    push(ax);
    sub_7c33();
    sp += 0x000a;
    ax = 0x0003;
    push(ax);
    ax = 0x001d;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x31df;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x31fb;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3219;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
loc_bb19: // 01ed:9c49
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_bb1e() // 01ed:9c4e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(ss);
    ax = bp - 20;
    push(ax);
    push(ds);
    ax = 0x30f5;
    push(ax);
    cx = 0x000d;
    sub_1016b();
    ax = 0x0020;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
loc_bb4c: // 01ed:9c7c
    ax = 0x0002;
    push(ax);
    ax = 0x0019;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x8282);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf4, ax);
    memoryASet16(ds, 0xaaf6, dx);
    ax = memoryAGet16(ds, 0x82f8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf8, ax);
    memoryASet16(ds, 0xaafa, dx);
    ax = 0x3230;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3248;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
loc_bb82: // 01ed:9cb2
    sub_8138();
    al &= 0xff;
    memoryASet(ss, bp - 1, al);
    if ((char)al < (char)0x31)
        goto loc_bb92;
    if ((char)al <= (char)0x39)
        goto loc_bb98;
loc_bb92: // 01ed:9cc2
    if (memoryAGet(ss, bp - 1) != 0x1b)
        goto loc_bb82;
loc_bb98: // 01ed:9cc8
    if (memoryAGet(ss, bp - 1) != 0x1b)
        goto loc_bba3;
    ax = 0;
    goto loc_bc3f;
loc_bba3: // 01ed:9cd3
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 15, al);
    push(memoryAGet16(ds, 0x2506));
    ax = bp - 20;
    push(ax);
    sub_f5ea();
    sp += 0x0004;
    ax = bp - 20;
    push(ax);
    sub_823b();
    sp++;
    sp++;
    memoryASet16(ss, bp - 6, ax);
    memoryASet16(ss, bp - 4, dx);
    ax = memoryAGet16(ss, bp - 6);
    ax |= dx;
    if (ax)
        goto loc_bbf3;
    ax = 0x0002;
    push(ax);
    ax = 0x0019;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x325b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x326f;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    goto loc_bb4c;
loc_bbf3: // 01ed:9d23
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_bc19;
    if (memoryAGet16(ss, bp - 6) != 0x005c)
        goto loc_bc19;
    push(ds);
    ax = 0xaa94;
    push(ax);
    ax = bp - 20;
    push(ax);
    sub_7b88();
    sp += 0x0006;
    memoryASet16(ds, 0xaa8e, 0x0001);
    ax = 0x0001;
    goto loc_bc3f;
loc_bc19: // 01ed:9d49
    ax = 0x0002;
    push(ax);
    ax = 0x0019;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x3282;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x329d;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    sub_8138();
    goto loc_bb4c;
loc_bc3f: // 01ed:9d6f
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_bc43() // 01ed:9d73
{
    sp -= 2;
    push(bp);
    bp = sp;
    sub_8b5d();
    memoryASet16(ds, 0x6ed0, 0xa000);
    memoryASet16(ds, 0x6ed2, 0x0002);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    sub_d606();
    sub_2159();
    sub_8b19();
    ax = 0x0010;
    push(ax);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0xa70c));
    push(memoryAGet16(ds, 0xa70a));
    sub_be82();
    sp += 0x0008;
    sub_8b5d();
    bp = pop();
    sp += 2;
}
void sub_bc84() // 01ed:9db4
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    dx &= 0xf000;
    ax &= 0xffff;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ds, 0xaa92));
    push(memoryAGet16(ds, 0xaa90));
    sub_be82();
    sp += 0x0008;
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_bd02() // 01ed:9e32
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ds, 0x8282);
    si = memoryAGet16(ds, 0x82f8);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x82f8, ax);
    if (memoryAGet16(ss, bp + 4) == 0x0000)
        goto loc_bd29;
    push(memoryAGet16(ss, bp + 10));
    sub_c48c();
    goto loc_bd2f;
loc_bd29: // 01ed:9e59
    push(memoryAGet16(ss, bp + 10));
    sub_81a2();
loc_bd2f: // 01ed:9e5f
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, di);
    memoryASet16(ds, 0x82f8, si);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_bd3d() // 01ed:9e6d
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(memoryAGet16(ds, 0xa6f6));
    ax = 0x002b;
    push(ax);
    push(memoryAGet16(ds, 0xa6f2));
    ax = 0x0004;
    push(ax);
    sub_7dee();
    sp += 0x0008;
    ax = 0x0004;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0004;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = 0x002b;
    push(ax);
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = 0x0004;
    push(ax);
    sub_d7b0();
    sp += 0x0006;
    ax = 0x0003;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = 0x002b;
    push(ax);
    sub_d7b0();
    sp += 0x0006;
    si = 0x0005;
    goto loc_bdda;
loc_bdc2: // 01ed:9ef2
    ax = 0x0002;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    ax++;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(si);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_bdda: // 01ed:9f0a
    if ((short)si < (short)0x002b)
        goto loc_bdc2;
    ax = 0x32b5;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f6);
    ax++;
    push(ax);
    ax = 0x0005;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_bd02();
    sp += 0x0008;
    push(memoryAGet16(ds, 0xa6f4));
    push(memoryAGet16(ds, 0xa6ea));
    push(memoryAGet16(ds, 0xa6ee));
    push(memoryAGet16(ds, 0xa6ec));
    ax = memoryAGet16(ds, 0xa6f2);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0xa6f0));
    sub_d113();
    sp += 0x000c;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_be82() // 01ed:9fb2
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax -= memoryAGet16(ss, bp + 8);
    ax--;
    di = ax;
    ax = 0x00c8;
    push(ax);
    ax = 0x0026;
    push(ax);
    ax = 0xa76e;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_d3af();
    sp += 0x000a;
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ds, 0xa6f0, 0x0005);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0xa6f2, ax);
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xa6ec, dx);
    memoryASet16(ds, 0xa6ee, ax);
    memoryASet16(ds, 0xa6ea, 0xa76e);
    memoryASet16(ds, 0xa6f4, di);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0xa6f6, ax);
    memoryASet16(ds, 0x5658, 0x9e6d);
    sub_2159();
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    si = 0;
    ax = 0x0008;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_bef4: // 01ed:a024
    sync();
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 14;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 14;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet(ds, 0x5074) != 0x00)
        goto loc_bf20;
    if (memoryAGet16(ss, bp - 6) != 0x0000)
        goto loc_bf6a;
loc_bf20: // 01ed:a050
    if ((short)si > 0)
        goto loc_bf27;
    goto loc_bfd1;
loc_bf27: // 01ed:a057
    si--;
    ax = 0x0001;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    sub_d510();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax += 0xa76e;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_d113();
    sp += 0x000c;
    ax = 0x0002;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    goto loc_bfd1;
loc_bf6a: // 01ed:a09a
    if (memoryAGet(ds, 0x507c) != 0x00)
        goto loc_bf77;
    if (memoryAGet16(ss, bp - 6) != 0x0004)
        goto loc_bfd1;
loc_bf77: // 01ed:a0a7
    ax = memoryAGet16(ss, bp - 8);
    ax -= di;
    if ((short)ax < (short)si)
        goto loc_bfd1;
    ax = 0x00c8;
    ax -= di;
    if ((short)ax < (short)si)
        goto loc_bfd1;
    si++;
    ax = 0;
    push(ax);
    ax = memoryAGet16(ss, bp + 10);
    ax--;
    push(ax);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    sub_d510();
    sp += 0x0006;
    ax = 0x0001;
    push(ax);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    dx = di;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax += 0xa76a;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = memoryAGet16(ss, bp + 10);
    ax--;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_d113();
    sp += 0x000c;
    ax = 0x0002;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
loc_bfd1: // 01ed:a101
    if (memoryAGet(ds, 0x5075) == 0x00)
        goto loc_c00f;
    ax = si;
    ax -= di;
    ax++;
    if ((short)ax <= 0)
        goto loc_bfe6;
    ax = di;
    ax--;
    si -= ax;
    goto loc_bfe8;
loc_bfe6: // 01ed:a116
    si = 0;
loc_bfe8: // 01ed:a118
    push(di);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax += 0xa76e;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_d113();
    sp += 0x000c;
loc_c008: // 01ed:a138
    sync();
    if (memoryAGet(ds, 0x5075) != 0x00)
        goto loc_c008;
loc_c00f: // 01ed:a13f
    if (memoryAGet(ds, 0x507d) == 0x00)
        goto loc_c059;
    ax = di;
    ax <<= 1;
    dx = si;
    dx += ax;
    if ((short)dx >= (short)memoryAGet16(ss, bp - 8))
        goto loc_c02a;
    ax = di;
    ax--;
    si += ax;
    goto loc_c032;
loc_c02a: // 01ed:a15a
    ax = memoryAGet16(ss, bp - 8);
    ax -= di;
    ax++;
    si = ax;
loc_c032: // 01ed:a162
    push(di);
    ax = si;
    ax <<= 1;
    ax <<= 1;
    ax += 0xa76e;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_d113();
    sp += 0x000c;
loc_c052: // 01ed:a182
    sync();
    if (memoryAGet(ds, 0x507d) != 0x00)
        goto loc_c052;
loc_c059: // 01ed:a189
    al = memoryAGet(ds, 0x502d);
    cbw();
    if (ax)
        goto loc_c070;
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_c070;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_c070;
    goto loc_bef4;
loc_c070: // 01ed:a1a0
    sync();
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 20;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 20;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_c070;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_c070;
    sub_7b0a();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c0a4() // 01ed:a1d4
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x000a;
    push(ax);
    push(memoryAGet16(ds, 0xa6f0));
    ax = 0x0010;
    push(ax);
    sub_d986();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_c0bb() // 01ed:a1eb
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x0008;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f0);
    ax += 0xfff6;
    push(ax);
    ax = 0x0016;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x000a;
    push(ax);
    push(memoryAGet16(ds, 0xa6f0));
    ax = 0x0010;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0xa6f0);
    ax += 0x0020;
    push(ax);
    ax = 0x0012;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x000f;
    push(ax);
    ax = 0x0063;
    push(ax);
    ax = 0x0015;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0011;
    push(ax);
    ax = 0x0072;
    push(ax);
    ax = 0x0013;
    push(ax);
    sub_d986();
    sp += 0x0006;
    ax = 0x0010;
    push(ax);
    ax = 0x009f;
    push(ax);
    ax = 0x0013;
    push(ax);
    sub_d986();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_c132() // 01ed:a262
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0010;
    push(si);
    push(di);
    memoryASet16(ds, 0x6ed0, 0x8000);
    memoryASet16(ds, 0x6ed2, 0x0006);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    memoryASet16(ss, bp - 8, 0x012c);
    di = 0x00c8;
    si = 0;
    memoryASet16(ss, bp - 10, 0x0000);
    sub_d606();
    sub_7b0a();
    memoryASet16(ds, 0xa6f8, 0x0000);
    goto loc_c1f2;
loc_c170: // 01ed:a2a0
    sub_2109();
    memoryASet16(ds, 0xa6f0, di);
    sub_2159();
    ax = si;
    if (!ax)
        goto loc_c187;
    if (ax == 0x0001)
        goto loc_c1a0;
    goto loc_c1af;
loc_c187: // 01ed:a2b7
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
    ax = memoryAGet16(ss, bp - 10);
    if ((short)ax <= (short)0x001e)
        goto loc_c1af;
    memoryASet16(ss, bp - 10, 0x0000);
    si++;
    memoryASet16(ds, 0x5658, 0xa1d4);
    goto loc_c1af;
loc_c1a0: // 01ed:a2d0
    if ((short)di <= (short)0x0037)
        goto loc_c1a8;
    di--;
    goto loc_c1af;
loc_c1a8: // 01ed:a2d8
    si++;
    memoryASet16(ds, 0x5658, 0xa1eb);
loc_c1af: // 01ed:a2df
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 16;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 16;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_c1e7;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_c1e7;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (!ax)
        goto loc_c1f2;
loc_c1e7: // 01ed:a317
    memoryASet16(ss, bp - 8, 0x0000);
    memoryASet16(ds, 0xa6f8, 0x0001);
loc_c1f2: // 01ed:a322
    ax = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) - 1);
    if (!ax)
        goto loc_c1ff;
    goto loc_c170;
loc_c1ff: // 01ed:a32f
    memoryASet16(ds, 0x5658, 0x0000);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c20b() // 01ed:a33b
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0026;
    push(si);
    push(di);
    push(ss);
    ax = bp - 10;
    push(ax);
    push(ds);
    ax = 0x3102;
    push(ax);
    cx = 0x0004;
    sub_1016b();
    push(ss);
    ax = bp - 18;
    push(ax);
    push(ds);
    ax = 0x3106;
    push(ax);
    cx = 0x0008;
    sub_1016b();
    push(ss);
    ax = bp - 26;
    push(ax);
    push(ds);
    ax = 0x310e;
    push(ax);
    cx = 0x0008;
    sub_1016b();
    di = 0;
    memoryASet16(ss, bp - 28, 0x0000);
    si = 0;
    memoryASet16(ss, bp - 32, 0x0000);
    sub_c436();
    sub_8b19();
    sub_7b0a();
    memoryASet16(ss, bp - 30, 0x0960);
loc_c25f: // 01ed:a38f
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 38;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 38;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    sub_2109();
    ax = memoryAGet16(ss, bp - 32);
    bx = 0x0006;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    if (dx)
        goto loc_c2bc;
    ax = 0x0003;
    push(ax);
    sub_df2c();
    sp++;
    sp++;
    dx = di;
    dx += ax;
    dx += 0xfffe;
    di = dx;
    ax = dx;
    if ((short)ax > (short)0x0007)
        goto loc_c2ab;
    if ((short)dx >= 0)
        goto loc_c2bc;
loc_c2ab: // 01ed:a3db
    ax = 0x0031;
    push(ax);
    sub_df2c();
    sp++;
    sp++;
    bx = 0x0007;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    di = ax;
loc_c2bc: // 01ed:a3ec
    memoryASet16(ss, bp - 28, memoryAGet16(ss, bp - 28) + 1);
    ax = memoryAGet16(ss, bp - 28);
    if ((short)ax <= (short)0x01f4)
        goto loc_c2cf;
    si ^= 0x0001;
    memoryASet16(ss, bp - 28, 0x0000);
loc_c2cf: // 01ed:a3ff
    bx = si;
    bx <<= 1;
    ax = bp - 10;
    bx += ax;
    ax = memoryAGet16(ds, bx);
    ax += di;
    push(ax);
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 18;
    bx += ax;
    ax = memoryAGet16(ds, bx + 2);
    dx = memoryAGet16(ds, bx);
    flags.carry = (dx + memoryAGet16(ds, 0x6ed4)) >= 0x10000;
    dx += memoryAGet16(ds, 0x6ed4);
    ax += memoryAGet16(ds, 0x6ed6) + flags.carry;
    push(ax);
    push(dx);
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = bp - 26;
    bx += ax;
    ax = memoryAGet16(ds, bx + 2);
    dx = memoryAGet16(ds, bx);
    flags.carry = (dx + memoryAGet16(ds, 0x6ed0)) >= 0x10000;
    dx += memoryAGet16(ds, 0x6ed0);
    ax += memoryAGet16(ds, 0x6ed2) + flags.carry;
    push(ax);
    push(dx);
    sub_2195();
    sp += 0x000a;
    sub_2159();
    memoryASet16(ss, bp - 32, memoryAGet16(ss, bp - 32) + 1);
    if (memoryAGet16(ss, bp + 4) == 0x0000)
        goto loc_c32d;
    ax = memoryAGet16(ss, bp - 30);
    ax -= memoryAGet16(ds, 0x5b14);
    memoryASet16(ss, bp - 30, ax);
loc_c32d: // 01ed:a45d
    sub_2b21();
    if (!ax)
        goto loc_c33a;
    sub_7b0a();
    sub_c436();
loc_c33a: // 01ed:a46a
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_c353;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_c353;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (!ax)
        goto loc_c358;
loc_c353: // 01ed:a483
    memoryASet16(ss, bp - 30, 0x0000);
loc_c358: // 01ed:a488
    if ((short)memoryAGet16(ss, bp - 30) <= (short)0x0000)
        goto loc_c361;
    goto loc_c25f;
loc_c361: // 01ed:a491
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c367() // 01ed:a497
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0x000c;
    memoryASet16(ds, 0x8282, ax);
    memoryASet16(ds, 0x8354, ax);
    memoryASet16(ds, 0x82f8, 0x0004);
    ax = 0x32dc;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x32f6;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3311;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3329;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3342;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x335d;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3378;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x0005;
    memoryASet16(ds, 0x8282, ax);
    memoryASet16(ds, 0x8354, ax);
    ax = 0x3393;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) - 1);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8354, ax);
    ax = 0x33bb;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x33e2;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3409;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x342e;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x344e;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x3476;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x349e;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x34c6;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    ax = 0x34f2;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x0000);
    ax = 0x351c;
    push(ax);
    sub_c48c();
    sp++;
    sp++;
    bp = pop();
    sp += 2;
}
void sub_c436() // 01ed:a566
{
    sp -= 2;
    push(bp);
    bp = sp;
    memoryASet16(ds, 0x6ed0, 0x6000);
    memoryASet16(ds, 0x6ed2, 0x0001);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    dx = memoryAGet16(ds, 0x6ed2);
    ax = memoryAGet16(ds, 0x6ed0);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5656, ax);
    dx = memoryAGet16(ds, 0x6ed6);
    ax = memoryAGet16(ds, 0x6ed4);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5b12, ax);
    sub_d606();
    sub_2109();
    memoryASet16(ds, 0x5658, 0xa497);
    sub_2159();
    sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    sub_7b0a();
    bp = pop();
    sp += 2;
}
void sub_c48c() // 01ed:a5bc
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    goto loc_c4d3;
loc_c493: // 01ed:a5c3
    if (memoryAGet(ss, bp - 1) != 0x0a)
        goto loc_c4a5;
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    ax = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, ax);
    goto loc_c4d3;
loc_c4a5: // 01ed:a5d5
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_c4b3;
    ax = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, ax);
    goto loc_c4d3;
loc_c4b3: // 01ed:a5e3
    al = memoryAGet(ss, bp - 1);
    cbw();
    ax += 0x0080;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(ax);
    sub_d7b0();
    sp += 0x0006;
loc_c4d3: // 01ed:a603
    bx = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 1);
    al = memoryAGet(ds, bx);
    memoryASet(ss, bp - 1, al);
    if (al)
        goto loc_c493;
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c4e6() // 01ed:a616
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    if (memoryAGet16(ds, 0x5daa) == 0x0000)
        goto loc_c4fd;
    ax = 0;
    goto loc_c95f;
loc_c4fd: // 01ed:a62d
    ax = memoryAGet16(ds, si + 32);
    imul16(memoryAGet16(ds, 0x5b14));
    dx = memoryAGet16(ds, si + 28);
    dx += ax;
    memoryASet16(ds, si + 28, dx);
    ax = memoryAGet16(ds, si + 34);
    imul16(memoryAGet16(ds, 0x5b14));
    dx = memoryAGet16(ds, si + 30);
    dx += ax;
    memoryASet16(ds, si + 30, dx);
    ax = 0xabca;
    push(ds);
    push(ax);
    push(ds);
    push(si);
    cx = 0x0036;
    sub_1016b();
    memoryASet16(ss, bp - 14, 0x0000);
    ax = memoryAGet16(ds, 0xabe8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabe2) + ax) >= 0x10000;
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) + ax);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0xabe8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabda) + ax) >= 0x10000;
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) + ax);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) + (dx + flags.carry));
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    sub_ff73();
    memoryASet16(ss, bp - 6, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    sub_ff73();
    memoryASet16(ss, bp - 8, ax);
    if ((short)memoryAGet16(ds, 0xabe8) > (short)0x0000)
        goto loc_c579;
    goto loc_c65c;
loc_c579: // 01ed:a6a9
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    sub_ff73();
    push(ax);
    push(dx);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0xabe4);
    cx = memoryAGet16(ds, 0xabe2);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    push(bx);
    push(cx);
    sub_ff73();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_c5b6;
    if (dx != ax)
        goto loc_c5b6;
    goto loc_c745;
loc_c5b6: // 01ed:a6e6
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    sub_ff73();
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ss, bp - 2, ax);
    goto loc_c64e;
  // gap 1 bytes
loc_c5d4: // 01ed:a704
    ax = memoryAGet16(ss, bp - 12);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 2612) != 0x0000)
        goto loc_c60c;
    ax = memoryAGet16(ss, bp - 12);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, bx) & ax))
        goto loc_c64b;
loc_c60c: // 01ed:a73c
    memoryASet16(ds, si + 34, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe4);
    dx = memoryAGet16(ds, 0xabe2);
    flags.carry = (dx + 0x0001) >= 0x10000;
    dx += 0x0001;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_ff82();
    di = ax;
    memoryASet16(ds, si + 30, memoryAGet16(ds, si + 30) - ax);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabda) < ax;
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) - ax);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) - dx - flags.carry);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabe2) < ax;
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) - ax);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) - dx - flags.carry);
    memoryASet16(ss, bp - 14, 0x0001);
    goto loc_c745;
loc_c64b: // 01ed:a77b
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_c64e: // 01ed:a77e
    ax = memoryAGet16(ss, bp - 2);
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_c659;
    goto loc_c5d4;
loc_c659: // 01ed:a789
    goto loc_c745;
loc_c65c: // 01ed:a78c
    if ((short)memoryAGet16(ds, 0xabe8) < (short)0x0000)
        goto loc_c666;
    goto loc_c745;
loc_c666: // 01ed:a796
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    sub_ff73();
    push(ax);
    push(dx);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe8);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0xabdc);
    cx = memoryAGet16(ds, 0xabda);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    push(bx);
    push(cx);
    sub_ff73();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_c6a3;
    if (dx != ax)
        goto loc_c6a3;
    goto loc_c745;
loc_c6a3: // 01ed:a7d3
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    sub_ff73();
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(ss, bp - 2, ax);
    goto loc_c73a;
  // gap 1 bytes
loc_c6c1: // 01ed:a7f1
    ax = memoryAGet16(ss, bp - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 5056) != 0x0000)
        goto loc_c6f9;
    ax = memoryAGet16(ss, bp - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, bx) & ax))
        goto loc_c737;
loc_c6f9: // 01ed:a829
    memoryASet16(ds, si + 34, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    sub_ff82();
    dx = 0x1000;
    dx -= ax;
    di = dx;
    memoryASet16(ds, si + 30, memoryAGet16(ds, si + 30) + dx);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabda) + ax) >= 0x10000;
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) + ax);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) + (dx + flags.carry));
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabe2) + ax) >= 0x10000;
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) + ax);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) + (dx + flags.carry));
    memoryASet16(ss, bp - 14, 0x0001);
    goto loc_c745;
loc_c737: // 01ed:a867
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_c73a: // 01ed:a86a
    ax = memoryAGet16(ss, bp - 2);
    if ((short)ax > (short)memoryAGet16(ss, bp - 8))
        goto loc_c745;
    goto loc_c6c1;
loc_c745: // 01ed:a875
    ax = memoryAGet16(ds, 0xabe6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabd6) + ax) >= 0x10000;
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) + ax);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0xabe6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabde) + ax) >= 0x10000;
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) + ax);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) + (dx + flags.carry));
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    sub_ff73();
    memoryASet16(ss, bp - 10, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    sub_ff73();
    memoryASet16(ss, bp - 12, ax);
    if ((short)memoryAGet16(ds, 0xabe6) > (short)0x0000)
        goto loc_c791;
    goto loc_c874;
loc_c791: // 01ed:a8c1
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    sub_ff73();
    push(ax);
    push(dx);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0xabe0);
    cx = memoryAGet16(ds, 0xabde);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    push(bx);
    push(cx);
    sub_ff73();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_c7ce;
    if (dx != ax)
        goto loc_c7ce;
    goto loc_c95c;
loc_c7ce: // 01ed:a8fe
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    sub_ff73();
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 4, ax);
    goto loc_c866;
  // gap 1 bytes
loc_c7ec: // 01ed:a91c
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 8);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 6278) != 0x0000)
        goto loc_c824;
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 8);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, bx) & ax))
        goto loc_c863;
loc_c824: // 01ed:a954
    memoryASet16(ds, si + 32, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe0);
    dx = memoryAGet16(ds, 0xabde);
    flags.carry = (dx + 0x0001) >= 0x10000;
    dx += 0x0001;
    ax += 0x0000 + flags.carry;
    push(ax);
    push(dx);
    sub_ff82();
    di = ax;
    memoryASet16(ds, si + 28, memoryAGet16(ds, si + 28) - ax);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabd6) < ax;
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) - ax);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) - dx - flags.carry);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabde) < ax;
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) - ax);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) - dx - flags.carry);
    memoryASet16(ss, bp - 14, 0x0001);
    goto loc_c95c;
loc_c863: // 01ed:a993
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_c866: // 01ed:a996
    ax = memoryAGet16(ss, bp - 4);
    if ((short)ax > (short)memoryAGet16(ss, bp - 12))
        goto loc_c871;
    goto loc_c7ec;
loc_c871: // 01ed:a9a1
    goto loc_c95c;
loc_c874: // 01ed:a9a4
    if ((short)memoryAGet16(ds, 0xabe6) < (short)0x0000)
        goto loc_c87e;
    goto loc_c95c;
loc_c87e: // 01ed:a9ae
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    sub_ff73();
    push(ax);
    push(dx);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    ax = memoryAGet16(ds, 0xabe6);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    bx = memoryAGet16(ds, 0xabd8);
    cx = memoryAGet16(ds, 0xabd6);
    flags.carry = cx < ax;
    cx -= ax;
    bx = bx - dx - flags.carry;
    push(bx);
    push(cx);
    sub_ff73();
    bx = pop();
    flags.zero = bx == dx;
    dx = pop();
    if (!flags.zero)
        goto loc_c8bb;
    if (dx != ax)
        goto loc_c8bb;
    goto loc_c95c;
loc_c8bb: // 01ed:a9eb
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    sub_ff73();
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 4, ax);
    goto loc_c951;
  // gap 1 bytes
loc_c8d9: // 01ed:aa09
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 3834) != 0x0000)
        goto loc_c911;
    ax = memoryAGet16(ss, bp - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, bx) & ax))
        goto loc_c94e;
loc_c911: // 01ed:aa41
    memoryASet16(ds, si + 32, 0x0000);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    sub_ff82();
    dx = 0x1000;
    dx -= ax;
    di = dx;
    memoryASet16(ds, si + 28, memoryAGet16(ds, si + 28) + dx);
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabd6) + ax) >= 0x10000;
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) + ax);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) + (dx + flags.carry));
    ax = di;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0xabde) + ax) >= 0x10000;
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) + ax);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) + (dx + flags.carry));
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) | 0x0001);
    goto loc_c95c;
loc_c94e: // 01ed:aa7e
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_c951: // 01ed:aa81
    ax = memoryAGet16(ss, bp - 4);
    if ((short)ax > (short)memoryAGet16(ss, bp - 12))
        goto loc_c95c;
    goto loc_c8d9;
loc_c95c: // 01ed:aa8c
    ax = memoryAGet16(ss, bp - 14);
loc_c95f: // 01ed:aa8f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_c965() // 01ed:aa95
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 10);
    push(si);
    sub_49b9();
    sp++;
    sp++;
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_c985;
    if (memoryAGet16(ss, bp + 8) != 0x0000)
        goto loc_c985;
    goto loc_ca31;
loc_c985: // 01ed:aab5
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 14));
    push(memoryAGet16(ds, si + 12));
    sub_ff73();
    memoryASet16(ss, bp - 4, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 22));
    push(memoryAGet16(ds, si + 20));
    sub_ff73();
    memoryASet16(ss, bp - 8, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 18));
    push(memoryAGet16(ds, si + 16));
    sub_ff73();
    memoryASet16(ss, bp - 6, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 26));
    push(memoryAGet16(ds, si + 24));
    sub_ff73();
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 2, ax);
    goto loc_ca29;
loc_c9d9: // 01ed:ab09
    di = memoryAGet16(ss, bp - 6);
    goto loc_ca21;
loc_c9de: // 01ed:ab0e
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4c + 2); /*ggg2*/;
    bx += ax;
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_ca20;
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 12, ax);
    memoryASet16(ss, bp - 14, di);
    ax = di;
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c4c);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x6ec0, ax);
    if (ax != 0x00ff)
        goto loc_ca20;
    memoryASet16(ds, 0x6ec0, 0x0000);
loc_ca20: // 01ed:ab50
    di++;
loc_ca21: // 01ed:ab51
    if ((short)di <= (short)memoryAGet16(ss, bp - 10))
        goto loc_c9de;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_ca29: // 01ed:ab59
    ax = memoryAGet16(ss, bp - 2);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 8))
        goto loc_c9d9;
loc_ca31: // 01ed:ab61
    ax = 0;
    memoryASet16(ds, si + 30, ax);
    memoryASet16(ds, si + 28, ax);
    bx = memoryAGet16(ss, bp + 4);
    if (bx > 0x0007)
        goto loc_caba;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_ca59;
        case 2: goto loc_ca65;
        case 4: goto loc_ca76;
        case 6: goto loc_ca82;
        case 8: goto loc_ca93;
        case 10: goto loc_ca9f;
        case 12: goto loc_cab0;
        case 14: goto loc_ca48;
        default:
            stop();
    }
loc_ca48: // 01ed:ab78
    memoryASet16(ds, si + 30, 0xfc00);
    memoryASet16(ds, si + 28, 0xfc00);
    memoryASet16(ds, si + 40, 0x002c);
    goto loc_caba;
loc_ca59: // 01ed:ab89
    memoryASet16(ds, si + 30, 0xfc00);
    memoryASet16(ds, si + 40, 0x002c);
    goto loc_caba;
loc_ca65: // 01ed:ab95
    memoryASet16(ds, si + 30, 0xfc00);
    memoryASet16(ds, si + 28, 0x0400);
    memoryASet16(ds, si + 40, 0x002c);
    goto loc_caba;
loc_ca76: // 01ed:aba6
    memoryASet16(ds, si + 28, 0x0400);
    memoryASet16(ds, si + 40, 0x0020);
    goto loc_caba;
loc_ca82: // 01ed:abb2
    memoryASet16(ds, si + 30, 0x0400);
    memoryASet16(ds, si + 28, 0x0400);
    memoryASet16(ds, si + 40, 0x0024);
    goto loc_caba;
loc_ca93: // 01ed:abc3
    memoryASet16(ds, si + 30, 0x0400);
    memoryASet16(ds, si + 40, 0x0024);
    goto loc_caba;
loc_ca9f: // 01ed:abcf
    memoryASet16(ds, si + 30, 0x0400);
    memoryASet16(ds, si + 28, 0xfc00);
    memoryASet16(ds, si + 40, 0x0024);
    goto loc_caba;
loc_cab0: // 01ed:abe0
    memoryASet16(ds, si + 28, 0xfc00);
    memoryASet16(ds, si + 40, 0x0028);
loc_caba: // 01ed:abea
    memoryASet16(ss, bp - 16, 0x0000);
    ax = memoryAGet16(ds, si + 28);
    ax |= memoryAGet16(ds, si + 30);
    if (!ax)
        goto loc_cad9;
    ax = memoryAGet16(ds, 0x5135);
    cl = 0x04;
    ax >>= cl;
    ax &= 0x0003;
    memoryASet16(ss, bp - 18, ax);
    memoryASet16(ss, bp - 16, memoryAGet16(ss, bp - 16) + 1);
    goto loc_cade;
loc_cad9: // 01ed:ac09
    memoryASet16(ss, bp - 18, 0x0000);
loc_cade: // 01ed:ac0e
    memoryASet16(ds, 0xa6e8, 0x8000);
    if (memoryAGet(ds, 0x503b) == 0x00)
        goto loc_caf8;
    if (memoryAGet(ds, 0x5056) == 0x00)
        goto loc_caf8;
    memoryASet16(ds, 0xa6e8, 0x0000);
loc_caf8: // 01ed:ac28
    push(si);
    sub_c4e6();
    sp++;
    sp++;
    memoryASet16(ss, bp - 20, ax);
    ax = memoryAGet16(ds, si + 28);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, si + 4) + ax) >= 0x10000;
    memoryASet16(ds, si + 4, memoryAGet16(ds, si + 4) + ax);
    memoryASet16(ds, si + 6, memoryAGet16(ds, si + 6) + (dx + flags.carry));
    ax = memoryAGet16(ds, si + 30);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, si + 8) + ax) >= 0x10000;
    memoryASet16(ds, si + 8, memoryAGet16(ds, si + 8) + ax);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + (dx + flags.carry));
    if (memoryAGet16(ss, bp - 16) == 0x0000)
        goto loc_cb3d;
    ax = memoryAGet16(ds, 0x5135);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if (ax & 0x0003)
        goto loc_cb3d;
    if (memoryAGet16(ss, bp - 20) == 0x0000)
        goto loc_cb34;
    ax = 0x0002;
    goto loc_cb37;
loc_cb34: // 01ed:ac64
    ax = 0x0001;
loc_cb37: // 01ed:ac67
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
loc_cb3d: // 01ed:ac6d
    if ((short)memoryAGet16(ds, si + 28) <= (short)0x0000)
        goto loc_cb8e;
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    flags.carry = dx < memoryAGet16(ds, 0x6ed0);
    dx -= memoryAGet16(ds, 0x6ed0);
    ax = ax - memoryAGet16(ds, 0x6ed2) - flags.carry;
    if ((short)ax < 0)
        goto loc_cb8e;
    if ((short)ax > 0)
        goto loc_cb5d;
    if (dx <= 0xb000)
        goto loc_cb8e;
loc_cb5d: // 01ed:ac8d
    ax = memoryAGet16(ds, si + 28);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed0) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + ax);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc0))
        goto loc_cbdd;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc0))
        goto loc_cb7e;
    if (dx <= memoryAGet16(ds, 0x7fbe))
        goto loc_cbdd;
loc_cb7e: // 01ed:acae
    ax = memoryAGet16(ds, 0x7fc0);
    dx = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    goto loc_cbdd;
loc_cb8e: // 01ed:acbe
    if ((short)memoryAGet16(ds, si + 28) >= (short)0x0000)
        goto loc_cbdd;
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    flags.carry = dx < memoryAGet16(ds, 0x6ed0);
    dx -= memoryAGet16(ds, 0x6ed0);
    ax = ax - memoryAGet16(ds, 0x6ed2) - flags.carry;
    if ((short)ax > 0)
        goto loc_cbdd;
    if ((short)ax < 0)
        goto loc_cbae;
    if (dx >= 0x9000)
        goto loc_cbdd;
loc_cbae: // 01ed:acde
    ax = memoryAGet16(ds, si + 28);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed0) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + ax);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed2);
    dx = memoryAGet16(ds, 0x6ed0);
    if ((short)ax > (short)memoryAGet16(ds, 0x564c))
        goto loc_cbdd;
    if ((short)ax < (short)memoryAGet16(ds, 0x564c))
        goto loc_cbcf;
    if (dx >= memoryAGet16(ds, 0x564a))
        goto loc_cbdd;
loc_cbcf: // 01ed:acff
    ax = memoryAGet16(ds, 0x564c);
    dx = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
loc_cbdd: // 01ed:ad0d
    if ((short)memoryAGet16(ds, si + 30) <= (short)0x0000)
        goto loc_cc2e;
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    flags.carry = dx < memoryAGet16(ds, 0x6ed4);
    dx -= memoryAGet16(ds, 0x6ed4);
    ax = ax - memoryAGet16(ds, 0x6ed6) - flags.carry;
    if ((short)ax < 0)
        goto loc_cc2e;
    if ((short)ax > 0)
        goto loc_cbfd;
    if (dx <= 0x7000)
        goto loc_cc2e;
loc_cbfd: // 01ed:ad2d
    ax = memoryAGet16(ds, si + 30);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed4) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + ax);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax < (short)memoryAGet16(ds, 0x7fc4))
        goto loc_cc7d;
    if ((short)ax > (short)memoryAGet16(ds, 0x7fc4))
        goto loc_cc1e;
    if (dx <= memoryAGet16(ds, 0x7fc2))
        goto loc_cc7d;
loc_cc1e: // 01ed:ad4e
    ax = memoryAGet16(ds, 0x7fc4);
    dx = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    goto loc_cc7d;
loc_cc2e: // 01ed:ad5e
    if ((short)memoryAGet16(ds, si + 30) >= (short)0x0000)
        goto loc_cc7d;
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    flags.carry = dx < memoryAGet16(ds, 0x6ed4);
    dx -= memoryAGet16(ds, 0x6ed4);
    ax = ax - memoryAGet16(ds, 0x6ed6) - flags.carry;
    if ((short)ax > 0)
        goto loc_cc7d;
    if ((short)ax < 0)
        goto loc_cc4e;
    if (dx >= 0x3000)
        goto loc_cc7d;
loc_cc4e: // 01ed:ad7e
    ax = memoryAGet16(ds, si + 30);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = (memoryAGet16(ds, 0x6ed4) + ax) >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + ax);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (dx + flags.carry));
    ax = memoryAGet16(ds, 0x6ed6);
    dx = memoryAGet16(ds, 0x6ed4);
    if ((short)ax > (short)memoryAGet16(ds, 0x5650))
        goto loc_cc7d;
    if ((short)ax < (short)memoryAGet16(ds, 0x5650))
        goto loc_cc6f;
    if (dx >= memoryAGet16(ds, 0x564e))
        goto loc_cc7d;
loc_cc6f: // 01ed:ad9f
    ax = memoryAGet16(ds, 0x5650);
    dx = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
loc_cc7d: // 01ed:adad
    dx = memoryAGet16(ds, 0x6ed2);
    ax = memoryAGet16(ds, 0x6ed0);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5656, ax);
    dx = memoryAGet16(ds, 0x6ed6);
    ax = memoryAGet16(ds, 0x6ed4);
    cl = 0x0c;
    sub_10042();
    memoryASet16(ds, 0x5b12, ax);
    ax = memoryAGet16(ds, si + 40);
    ax += memoryAGet16(ss, bp - 18);
    push(ax);
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_2195();
    sp += 0x000a;
    if (memoryAGet16(ds, 0x6ec0) == 0x0000)
        goto loc_ccd6;
    push(memoryAGet16(ss, bp - 14));
    push(memoryAGet16(ss, bp - 12));
    push(si);
    push(memoryAGet16(ds, 0x6ec0));
    sub_ccec();
    sp += 0x0008;
    if (!ax)
        goto loc_ccd6;
    memoryASet16(ds, 0x6ec0, 0x0000);
loc_ccd6: // 01ed:ae06
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_ccec() // 01ed:ae1c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0018;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 6);
    if (memoryAGet16(ss, bp + 4) == 0x0014)
        goto loc_cd00;
    goto loc_cde9;
loc_cd00: // 01ed:ae30
    ax = 0x0008;
    push(ax);
    ax = 0x0014;
    push(ax);
    sub_7f8e();
    sp += 0x0004;
    ax = 0x354b;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3572;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = 0x3584;
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x833e);
    if (!ax)
        goto loc_cd32;
    goto loc_cd37;
loc_cd32: // 01ed:ae62
    ax = 0x3590;
    goto loc_cd3a;
loc_cd37: // 01ed:ae67
    ax = 0x3595;
loc_cd3a: // 01ed:ae6a
    push(ax);
    sub_81a2();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0xaa94) != 0x0000)
        goto loc_cd65;
    ax = 0x0141;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax += 0xfffc;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8354);
    ax += 0x0003;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_cd65: // 01ed:ae95
    if (memoryAGet16(ds, 0xaa9c) != 0x0000)
        goto loc_cd8a;
    ax = 0x0142;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax += 0xfffc;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8354);
    ax += 0x0007;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_cd8a: // 01ed:aeba
    if (memoryAGet16(ds, 0xaa96) != 0x0000)
        goto loc_cdaf;
    ax = 0x0143;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax += 0xfffc;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8354);
    ax += 0x000b;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_cdaf: // 01ed:aedf
    if (memoryAGet16(ds, 0xaa98) != 0x0000)
        goto loc_cdd4;
    ax = 0x0144;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax += 0xfffc;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8354);
    ax += 0x000f;
    push(ax);
    sub_d809();
    sp += 0x0006;
loc_cdd4: // 01ed:af04
    ax = 0x000f;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    sub_d055();
    sub_d606();
    ax = 0x0001;
    goto loc_d04f;
loc_cde9: // 01ed:af19
    di = 0;
    goto loc_d045;
loc_cdee: // 01ed:af1e
    ax = memoryAGet16(ss, bp + 4);
    ax &= 0x0020;
    if (ax == 0x0020)
        goto loc_cdfc;
    goto loc_d044;
loc_cdfc: // 01ed:af2c
    ax = memoryAGet16(ss, bp + 4);
    ax &= 0x0003;
    ax--;
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 4);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax &= 0x0003;
    ax--;
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 16, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ss, bp - 18, ax);
    memoryASet16(ss, bp - 14, 0x0152);
    ax = memoryAGet16(ss, bp - 10);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 10390) == 0x0000)
        goto loc_ce3b;
    memoryASet16(ss, bp - 14, 0x0156);
loc_ce3b: // 01ed:af6b
    ax = 0x0012;
    push(ax);
    sub_ddc3();
    sp++;
    sp++;
    di = 0;
    goto loc_ce89;
loc_ce48: // 01ed:af78
    sub_2109();
    sub_d606();
    ax = di;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    if (dx)
        goto loc_ce6a;
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 1);
    ax = memoryAGet16(ss, bp - 12);
    if ((short)ax <= (short)0x0003)
        goto loc_ce6a;
    memoryASet16(ss, bp - 12, 0x0000);
loc_ce6a: // 01ed:af9a
    ax = memoryAGet16(ss, bp - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 16);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 12);
    ax += memoryAGet16(ss, bp - 14);
    memoryASet16(es, bx, ax);
    sub_2159();
    di++;
loc_ce89: // 01ed:afb9
    if ((short)di < (short)0x0010)
        goto loc_ce48;
    memoryASet16(ss, bp - 14, 0x0145);
    ax = memoryAGet16(ss, bp - 10);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 10390) == 0x0000)
        goto loc_cea9;
    memoryASet16(ss, bp - 14, 0x0063);
loc_cea9: // 01ed:afd9
    ax = memoryAGet16(ss, bp - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 16);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 14);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 10384);
    dx = memoryAGet16(ds, bx + 10382);
    memoryASet16(ds, 0xa6fa, dx);
    memoryASet16(ds, 0xa6fc, ax);
    memoryASet16(ds, 0xaaf4, dx);
    memoryASet16(ds, 0xaaf6, ax);
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 6, ax);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    ax = memoryAGet16(ds, bx + 10388);
    dx = memoryAGet16(ds, bx + 10386);
    memoryASet16(ds, 0xa6fe, dx);
    memoryASet16(ds, 0xa700, ax);
    memoryASet16(ds, 0xaaf8, dx);
    memoryASet16(ds, 0xaafa, ax);
    memoryASet16(ds, si + 8, dx);
    memoryASet16(ds, si + 10, ax);
    ax = memoryAGet16(ds, si + 6);
    dx = memoryAGet16(ds, si + 4);
    flags.carry = (dx + 0x7000) >= 0x10000;
    dx += 0x7000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed0, dx);
    memoryASet16(ds, 0x6ed2, ax);
    ax = memoryAGet16(ds, si + 10);
    dx = memoryAGet16(ds, si + 8);
    flags.carry = (dx + 0xd000) >= 0x10000;
    dx += 0xd000;
    ax += 0xffff + flags.carry;
    memoryASet16(ds, 0x6ed4, dx);
    memoryASet16(ds, 0x6ed6, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_ff73();
    memoryASet16(ss, bp - 16, ax);
    ax = 0;
    dx = 0x1000;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    sub_ff73();
    memoryASet16(ss, bp - 18, ax);
    memoryASet16(ss, bp - 14, 0x0152);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 10390) == 0x0000)
        goto loc_cf76;
    memoryASet16(ss, bp - 14, 0x0156);
loc_cf76: // 01ed:b0a6
    di = 0;
    goto loc_cfbb;
loc_cf7a: // 01ed:b0aa
    sub_2109();
    sub_d606();
    ax = di;
    bx = 0x0002;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv16(bx);
    if (dx)
        goto loc_cf9c;
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 1);
    ax = memoryAGet16(ss, bp - 12);
    if ((short)ax <= (short)0x0003)
        goto loc_cf9c;
    memoryASet16(ss, bp - 12, 0x0000);
loc_cf9c: // 01ed:b0cc
    ax = memoryAGet16(ss, bp - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 16);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 12);
    ax += memoryAGet16(ss, bp - 14);
    memoryASet16(es, bx, ax);
    sub_2159();
    di++;
loc_cfbb: // 01ed:b0eb
    if ((short)di < (short)0x0010)
        goto loc_cf7a;
    memoryASet16(ss, bp - 14, 0x0145);
    ax = memoryAGet16(ss, bp - 8);
    dx = 0x000a;
    imul16(dx);
    bx = ax;
    if (memoryAGet16(ds, bx + 10390) == 0x0000)
        goto loc_cfdb;
    memoryASet16(ss, bp - 14, 0x0063);
loc_cfdb: // 01ed:b10b
    ax = memoryAGet16(ss, bp - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    ax += memoryAGet16(ss, bp - 16);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c48 + 2); /*ggg2*/;
    bx += ax;
    ax = memoryAGet16(ss, bp - 14);
    memoryASet16(es, bx, ax);
loc_cff3: // 01ed:b123
    sub_2109();
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 24;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 24;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    push(memoryAGet16(ds, si + 40));
    push(memoryAGet16(ds, si + 10));
    push(memoryAGet16(ds, si + 8));
    push(memoryAGet16(ds, si + 6));
    push(memoryAGet16(ds, si + 4));
    sub_2195();
    sp += 0x000a;
    sub_2159();
    sub_30c0();
    sub_2b21();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_cff3;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_cff3;
    ax = 0x0001;
    goto loc_d04f;
loc_d044: // 01ed:b174
    di++;
loc_d045: // 01ed:b175
    if ((short)di >= (short)0x0003)
        goto loc_d04d;
    goto loc_cdee;
loc_d04d: // 01ed:b17d
    ax = 0;
loc_d04f: // 01ed:b17f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d055() // 01ed:b185
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    memoryASet16(ss, bp - 8, 0x0000);
    di = 0;
loc_d064: // 01ed:b194
    ax = memoryAGet16(ss, bp - 8);
    ax += 0x0009;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    push(memoryAGet16(ds, 0x8282));
    sub_d7b0();
    sp += 0x0006;
    si = 0;
    goto loc_d0c8;
loc_d083: // 01ed:b1b3
    ax = 0x0001;
    push(ax);
    sub_dfb2();
    sp++;
    sp++;
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 20;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 20;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_d0c4;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_d0c4;
    ax = 0x0001;
    push(ax);
    sub_dc9e();
    sp++;
    sp++;
    if (!ax)
        goto loc_d0c7;
loc_d0c4: // 01ed:b1f4
    di++;
    goto loc_d0cd;
loc_d0c7: // 01ed:b1f7
    si++;
loc_d0c8: // 01ed:b1f8
    if ((short)si < (short)0x0006)
        goto loc_d083;
loc_d0cd: // 01ed:b1fd
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    ax = memoryAGet16(ss, bp - 8);
    if ((short)ax <= (short)0x0004)
        goto loc_d0dd;
    memoryASet16(ss, bp - 8, 0x0000);
loc_d0dd: // 01ed:b20d
    if (di)
        goto loc_d0e3;
    goto loc_d064;
loc_d0e3: // 01ed:b213
    sync();
    ax = bp - 6;
    push(ss);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 14;
    push(ax);
    sub_7909();
    sp += 0x0006;
    ax = bp - 14;
    push(ss);
    push(ax);
    cx = 0x0006;
    sub_1016b();
    ax = memoryAGet16(ss, bp - 4);
    ax |= memoryAGet16(ss, bp - 2);
    if (ax)
        goto loc_d0e3;
    sub_7b0a();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d113() // 01ed:b243
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x8282, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x82f8, ax);
    memoryASet16(ss, bp - 6, 0x0000);
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_d223;
loc_d134: // 01ed:b264
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 12);
    bx += ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ss, bp - 4, ax);
    if (ax != 0xffff)
        goto loc_d14d;
    goto loc_d22e;
loc_d14d: // 01ed:b27d
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 12);
    bx += ax;
    di = memoryAGet16(ds, bx + 2);
    bx = memoryAGet16(ss, bp - 4);
    cx = 0;
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    sub_1010b();
    bx = di;
    cx = 0;
    sub_1010b();
    cx = 0xffff;
    bx = 0xffff;
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x0d)
        goto loc_d185;
    di--;
loc_d185: // 01ed:b2b5
    bx = memoryAGet16(ss, bp - 4);
    cx = 0;
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x7e)
        goto loc_d1a8;
    memoryASet16(ss, bp - 6, 0x0080);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    di--;
    goto loc_d1ad;
loc_d1a8: // 01ed:b2d8
    memoryASet16(ss, bp - 6, 0x0000);
loc_d1ad: // 01ed:b2dd
    si = 0;
    goto loc_d1ee;
loc_d1b1: // 01ed:b2e1
    bx = memoryAGet16(ss, bp - 4);
    cx = 0;
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    sub_1010b();
    bx = si;
    cx = 0;
    sub_1010b();
    bx = ax;
    es = dx;
    al = memoryAGet(es, bx);
    cbw();
    ax += memoryAGet16(ss, bp - 6);
    ax &= 0x00ff;
    push(ax);
    ax = memoryAGet16(ds, 0x82f8);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    push(ax);
    ax = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(ax);
    sub_d7b0();
    sp += 0x0006;
    si++;
loc_d1ee: // 01ed:b31e
    if (si < di)
        goto loc_d1b1;
    if ((short)memoryAGet16(ds, 0x8282) >= (short)0x002b)
        goto loc_d216;
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0020;
    push(ax);
    push(memoryAGet16(ds, 0x82f8));
    ax = 0x002a;
    push(ax);
    push(memoryAGet16(ds, 0x82f8));
    push(memoryAGet16(ds, 0x8282));
    sub_7f5c();
    sp += 0x000a;
loc_d216: // 01ed:b346
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x8282, ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_d223: // 01ed:b353
    ax = memoryAGet16(ss, bp - 2);
    if (ax >= memoryAGet16(ss, bp + 14))
        goto loc_d22e;
    goto loc_d134;
loc_d22e: // 01ed:b35e
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d234() // 01ed:b364
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    cx = 0;
    bx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1044a();
    if (!flags.zero)
        goto loc_d253;
    ax = 0x359d;
    push(ax);
    sub_3131();
    sp++;
    sp++;
loc_d253: // 01ed:b383
    di = 0;
    goto loc_d258;
loc_d257: // 01ed:b387
    di++;
loc_d258: // 01ed:b388
    bx = di;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x1a)
        goto loc_d257;
    si = 0;
    goto loc_d38f;
loc_d274: // 01ed:b3a4
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (al != 0x1f)
        goto loc_d2a7;
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    memoryASet(es, bx, 0x0d);
    goto loc_d38e;
loc_d2a7: // 01ed:b3d7
    if (memoryAGet(ss, bp - 1) == 0x0d)
        goto loc_d2b0;
    goto loc_d34d;
loc_d2b0: // 01ed:b3e0
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0002;
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x0d)
        goto loc_d2d2;
    goto loc_d34d;
  // gap 1 bytes
loc_d2d2: // 01ed:b402
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    memoryASet(es, bx, 0x20);
    ax = di;
    ax -= si;
    push(ax);
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0001;
    sub_1010b();
    push(ax);
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0001;
    sub_1010b();
    push(dx);
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0002;
    sub_1010b();
    push(ax);
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0002;
    sub_1010b();
    push(dx);
    sub_f321();
    sp += 0x000a;
    di--;
    goto loc_d38e;
loc_d34d: // 01ed:b47d
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_d38e;
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    cx = 0;
    bx = 0x0002;
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x0d)
        goto loc_d38e;
    goto loc_d376;
loc_d374: // 01ed:b4a4
    si++;
    si++;
loc_d376: // 01ed:b4a6
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) == 0x0d)
        goto loc_d374;
    si--;
loc_d38e: // 01ed:b4be
    si++;
loc_d38f: // 01ed:b4bf
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) == 0x1a)
        goto loc_d3a9;
    goto loc_d274;
loc_d3a9: // 01ed:b4d9
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d3af() // 01ed:b4df
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    di = 0;
    si = 0;
loc_d3c5: // 01ed:b4f5
    memoryASet16(ss, bp - 4, 0x0000);
    ax = di;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ds, bx, ax);
    si = ax;
    goto loc_d46a;
loc_d3df: // 01ed:b50f
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x1a)
        goto loc_d431;
    memoryASet16(ss, bp - 4, 0x0002);
    ax = di;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    ax = si;
    ax -= memoryAGet16(ss, bp - 2);
    memoryASet16(ds, bx + 2, ax);
    ax = di;
    ax++;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    memoryASet16(ds, bx, 0xffff);
    ax = di;
    ax++;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    memoryASet16(ds, bx + 2, 0xffff);
    goto loc_d477;
loc_d431: // 01ed:b561
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x0d)
        goto loc_d469;
    ax = di;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    ax = si;
    ax -= memoryAGet16(ss, bp - 2);
    ax++;
    memoryASet16(ds, bx + 2, ax);
    di++;
    ax = si;
    ax++;
    ax++;
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    goto loc_d477;
loc_d469: // 01ed:b599
    si++;
loc_d46a: // 01ed:b59a
    ax = memoryAGet16(ss, bp - 2);
    ax += memoryAGet16(ss, bp + 10);
    if (ax <= si)
        goto loc_d477;
    goto loc_d3df;
loc_d477: // 01ed:b5a7
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_d4d4;
    goto loc_d4b3;
loc_d47f: // 01ed:b5af
    bx = si;
    cx = 0;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1010b();
    bx = ax;
    es = dx;
    if (memoryAGet(es, bx) != 0x20)
        goto loc_d4b2;
    ax = di;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    ax = si;
    ax -= memoryAGet16(ss, bp - 2);
    memoryASet16(ds, bx + 2, ax);
    di++;
    ax = si;
    ax++;
    memoryASet16(ss, bp - 2, ax);
    goto loc_d4b8;
loc_d4b2: // 01ed:b5e2
    si--;
loc_d4b3: // 01ed:b5e3
    if (si > memoryAGet16(ss, bp - 2))
        goto loc_d47f;
loc_d4b8: // 01ed:b5e8
    if (si != memoryAGet16(ss, bp - 2))
        goto loc_d4d4;
    ax = di;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, bx + 2, ax);
    di++;
    si += ax;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + ax);
loc_d4d4: // 01ed:b604
    if (di != memoryAGet16(ss, bp + 12))
        goto loc_d4ff;
    ax = di;
    ax--;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    memoryASet16(ds, bx, 0xffff);
    ax = di;
    ax--;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 8);
    bx += ax;
    memoryASet16(ds, bx + 2, 0xffff);
    memoryASet16(ss, bp - 4, 0x0002);
loc_d4ff: // 01ed:b62f
    if (memoryAGet16(ss, bp - 4) >= 0x0002)
        goto loc_d508;
    goto loc_d3c5;
loc_d508: // 01ed:b638
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d510() // 01ed:b640
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax -= memoryAGet16(ss, bp + 4);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx = 0x0030;
    imul16(dx);
    memoryASet16(ss, bp - 2, ax);
    ax = memoryAGet16(ss, bp + 8);
    if (!ax)
        goto loc_d53d;
    if (ax != 0x0001)
        goto loc_d53a;
    goto loc_d59d;
  // gap 1 bytes
loc_d53a: // 01ed:b66a
    goto loc_d5ff;
loc_d53d: // 01ed:b66d
    al = 0x05;
    push(ax);
    ax = 0x03ce;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x01;
    push(ax);
    ax = 0x03cf;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x0f;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    dx = 0x0180;
    ax = memoryAGet16(ss, bp + 4);
    imul16(dx);
    memoryASet16(ss, bp + 4, ax);
    push(flagAsReg());
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp + 4);
    si = di;
    si += 0x0180;
    cx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ds, 0x35b4);
    es = ax;
    ds = ax;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
    di = pop();
    si = pop();
    flagsFromReg(pop());
    goto loc_d5ff;
  // gap 1 bytes
loc_d59d: // 01ed:b6cd
    al = 0x05;
    push(ax);
    ax = 0x03ce;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x01;
    push(ax);
    ax = 0x03cf;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x02;
    push(ax);
    ax = 0x03c4;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    al = 0x0f;
    push(ax);
    ax = 0x03c5;
    push(ax);
    sub_f4f3();
    sp += 0x0004;
    dx = 0x0180;
    ax = memoryAGet16(ss, bp + 6);
    imul16(dx);
    memoryASet16(ss, bp + 6, ax);
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) + 0x017f);
    push(flagAsReg());
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp + 6);
    si = di;
    si -= 0x0180;
    cx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ds, 0x35b4);
    es = ax;
    ds = ax;
    flags.direction = 1;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
    di = pop();
    si = pop();
    flagsFromReg(pop());
loc_d5ff: // 01ed:b72f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_d606() // 01ed:b736
{
    push(di);
    cx = 0x0126;
    ax = ds;
    es = ax;
    di = 0x5b16;
    ax = 0xffff;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    cx = 0x0126;
    di = 0x5db8;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = pop();
}
void sub_d620() // 01ed:b750
{
    sp -= 2;
    push(si);
    push(di);
    sub_d74c();
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    flags.direction = 0;
    di = 0;
    memoryASet16(ds, 0x35b6, di);
    ax = memoryAGet16(ds, 0x6ed5);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = memoryAGet16(ds, 0x6c06);
    mul16(bx);
    bx = ax;
    ax = memoryAGet16(ds, 0x6ed1);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax <<= 1;
    bx += ax;
    bx += memoryAGet16(ds, 0x6c48);
    es = memoryAGet16(ds, 0x6c4a);
    bp = memoryAGet16(ds, 0x5135);
    cl = memoryAGet(ds, 0x6c62);
    bp >>= cl;
    bp &= 0x0006;
    bp = memoryAGet16(ss, bp + 20476);
    memoryASet16(ds, 0x35be, bp);
    ax = memoryAGet16(ds, 0x5652);
    if (ax)
        goto loc_d681;
    push(cs); cs = 0x1059; sub_12290(); assert(cs == 0x01ed);
    goto loc_d686;
  // gap 1 bytes
loc_d681: // 01ed:b7b1
    push(cs); cs = 0x1059; sub_105dd(); assert(cs == 0x01ed);
loc_d686: // 01ed:b7b6
    push(memoryAGet16(ds, 0x35b4));
    ax = memoryAGet16(ds, 0x35b2);
    memoryASet16(ds, 0x35b4, ax);
    cx = memoryAGet16(ds, 0x6ebe);
    if (cx==0)
        goto loc_d6b1;
    bp = 0;
loc_d698: // 01ed:b7c8
    push(cx);
    push(memoryAGet16(ss, bp + 24658));
    push(memoryAGet16(ss, bp + 24656));
    push(memoryAGet16(ss, bp + 24654));
    sub_d9fd();
    sp += 0x0006;
    cx = pop();
    bp += 0x0006;
    if (--cx)
        goto loc_d698;
loc_d6b1: // 01ed:b7e1
    cx = memoryAGet16(ds, 0x6ed8);
    if (cx==0)
        goto loc_d6d2;
    bp = 0;
loc_d6b9: // 01ed:b7e9
    push(cx);
    push(memoryAGet16(ss, bp + 27752));
    push(memoryAGet16(ss, bp + 27750));
    push(memoryAGet16(ss, bp + 27748));
    sub_d809();
    sp += 0x0006;
    cx = pop();
    bp += 0x0006;
    if (--cx)
        goto loc_d6b9;
loc_d6d2: // 01ed:b802
    cx = memoryAGet16(ds, 0x6ecc);
    if (cx==0)
        goto loc_d6f3;
    bp = 0;
loc_d6da: // 01ed:b80a
    push(cx);
    push(memoryAGet16(ss, bp + 27662));
    push(memoryAGet16(ss, bp + 27660));
    push(memoryAGet16(ss, bp + 27658));
    sub_d986();
    sp += 0x0006;
    cx = pop();
    bp += 0x0006;
    if (--cx)
        goto loc_d6da;
loc_d6f3: // 01ed:b823
    memoryASet16(ds, 0x35b4, pop());
    cx = memoryAGet16(ds, 0x5658);
    if (cx==0)
        goto loc_d6ff;
    switch (cx)
    {
        case 0xa1d4: sub_c0a4(); break;
        case 0xa1eb: sub_c0bb(); break;
        case 0xa497: sub_c367(); break;
        case 0x95fd: sub_b4cd(); break;
        case 0x97ab: sub_b67b(); break;
        case 0x97f0: sub_b6c0(); break;
        case 0x986c: sub_b73c(); break;
        case 0x9e6d: sub_bd3d(); break;
        default:
            stop();
    }
loc_d6ff: // 01ed:b82f
    cx = memoryAGet16(ds, 0x35ba);
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx++;
    al = ch;
    out8(dx, al);
    dx--;
    al = 0x0d;
    out8(dx, al);
    dx++;
    al = cl;
    out8(dx, al);
loc_d715: // 01ed:b845
    dx = 0x03da;
    al = in8(dx);
    if (al & 0x08)
        goto loc_d715;
    bx = memoryAGet16(ds, 0x35ba);
    dx = 0x03d4;
    al = 0x0c;
    out8(dx, al);
    dx++;
    al = bh;
    out8(dx, al);
    dx--;
    al = 0x0d;
    out8(dx, al);
    dx++;
    al = bl;
    out8(dx, al);
loc_d733: // 01ed:b863
    dx = 0x03da;
    al = in8(dx);
    if (!(al & 0x08))
        goto loc_d733;
    dx = 0x03da;
    al = in8(dx);
    dx = 0x03c0;
    al = 0x33;
//    out8(dx, al);
//    ax = memoryAGet16(ds, 0x35b8);
//    out8(dx, al);
    di = pop();
    si = pop();
    sp += 2;
}
void sub_d74c() // 01ed:b87c
{
    memoryASet16(ds, 0x35ba, 0x0004);
    ax = memoryAGet16(ds, 0x6ed0);
    if (!(ax & 0x0800))
        goto loc_d75e;
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + 1);
loc_d75e: // 01ed:b88e
    ax = memoryAGet16(ds, 0x6ed1);
    ax &= 0x0007;
    memoryASet16(ds, 0x35b8, ax);
    memoryASet16(ds, 0x5652, memoryAGet16(ds, 0x5652) ^ 0x0001);
    if (memoryAGet16(ds, 0x5652) & 0x0001)
        goto loc_d77a;
    cx = 0xa000;
    goto loc_d783;
  // gap 1 bytes
loc_d77a: // 01ed:b8aa
    cx = 0xa300;
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + 0x3000);
loc_d783: // 01ed:b8b3
    memoryASet16(ds, 0x35b2, cx);
    ax = memoryAGet16(ds, 0x6ed5);
    ax &= 0x000f;
    bl = 0x30;
    mul8(bl);
    ax += 0x0600;
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + ax);
    ax = memoryAGet16(ds, 0x35ba);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += 0xa000;
    memoryASet16(ds, 0x35b4, ax);
}
void sub_d7b0() // 01ed:b8e0
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    es = memoryAGet16(ds, 0x35b4);
    di = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    di += memoryAGet16(ds, bx + 14348);
    flags.direction = 0;
    flags.interrupts = 0;
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    si = memoryAGet16(ss, bp + 8);
    si <<= 1;
    si <<= 1;
    si <<= 1;
    bx = si;
    cx = di;
    ax = memoryAGet16(ds, 0x8300);
    ds = ax;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    movsb<ES_DI, DS_SI>();
    di += 0x002f;
    flags.interrupts = 1;
    ax = ss;
    ds = ax;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_d809() // 01ed:b939
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    es = memoryAGet16(ds, 0x35b4);
    di = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    di += memoryAGet16(ds, bx + 14348);
    si = memoryAGet16(ss, bp + 8);
    if ((short)si < 0)
        goto loc_d898;
    si <<= 1;
    si += memoryAGet16(ds, 0x35be);
    si = memoryAGet16(ds, si);
    ax = memoryAGet16(ds, 0x836a);
    ds = ax;
    flags.direction = 0;
    flags.interrupts = 0;
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    flags.interrupts = 1;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += 0x002e;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    ax = ss;
    ds = ax;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
    return;
loc_d898: // 01ed:b9c8
    si &= 0x7fff;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    ax = memoryAGet16(ds, 0x836a);
    ds = ax;
    dx = 0x03ce;
    ax = 0x0005;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0004;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    push(si);
    push(di);
    cx = 0x0010;
loc_d8c5: // 01ed:b9f5
    ax = memoryAGet16(es, di);
    bx = memoryAGet16(ds, si + 32);
    dx = memoryAGet16(ds, si);
    ax &= bx;
    bx ^= 0xffff;
    dx &= bx;
    ax |= dx;
    stosw<ES_DI>(ax);
    si += 0x0002;
    di += 0x002e;
    if (--cx)
        goto loc_d8c5;
    di = pop();
    si = pop();
    dx = 0x03ce;
    ax = 0x0104;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0202;
    out16(dx, ax);
    push(si);
    push(di);
    cx = 0x0010;
loc_d8f4: // 01ed:ba24
    ax = memoryAGet16(es, di);
    bx = memoryAGet16(ds, si + 32);
    dx = memoryAGet16(ds, si);
    ax &= bx;
    bx ^= 0xffff;
    dx &= bx;
    ax |= dx;
    stosw<ES_DI>(ax);
    si += 0x0002;
    di += 0x002e;
    if (--cx)
        goto loc_d8f4;
    di = pop();
    si = pop();
    dx = 0x03ce;
    ax = 0x0204;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0402;
    out16(dx, ax);
    push(si);
    push(di);
    cx = 0x0010;
loc_d923: // 01ed:ba53
    ax = memoryAGet16(es, di);
    bx = memoryAGet16(ds, si + 32);
    dx = memoryAGet16(ds, si);
    ax &= bx;
    bx ^= 0xffff;
    dx &= bx;
    ax |= dx;
    stosw<ES_DI>(ax);
    si += 0x0002;
    di += 0x002e;
    if (--cx)
        goto loc_d923;
    di = pop();
    si = pop();
    dx = 0x03ce;
    ax = 0x0304;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0802;
    out16(dx, ax);
    push(si);
    push(di);
    cx = 0x0010;
loc_d952: // 01ed:ba82
    ax = memoryAGet16(es, di);
    bx = memoryAGet16(ds, si + 32);
    dx = memoryAGet16(ds, si);
    ax &= bx;
    bx ^= 0xffff;
    dx &= bx;
    ax |= dx;
    stosw<ES_DI>(ax);
    si += 0x0002;
    di += 0x002e;
    if (--cx)
        goto loc_d952;
    di = pop();
    si = pop();
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    dx = 0x03c4;
    al = 0x02;
    ah = 0x0f;
    out16(dx, ax);
    flags.interrupts = 1;
    ax = ss;
    ds = ax;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_d986() // 01ed:bab6
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    es = memoryAGet16(ds, 0x8366);
    ax = memoryAGet16(es, si);
    memoryASet16(cs, 0xb8da, ax);
    ax = memoryAGet16(es, si + 2);
    memoryASet16(cs, 0xb8de, ax);
    si = memoryAGet16(es, si + 4);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(cs, 0xb8dc, ax);
    es = memoryAGet16(ds, 0x35b4);
    flags.direction = 0;
    flags.interrupts = 0;
    dx = 0x03c4;
    al = 0x02;
    out8(dx, al);
    al = 0x0f;
    dx++;
    out8(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out8(dx, al);
    al = 0x01;
    dx++;
    out8(dx, al);
    flags.interrupts = 1;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    cx = memoryAGet16(ds, 0x834c);
    ds = cx;
loc_d9da: // 01ed:bb0a
    di = memoryAGet16(ss, bx + 14348);
    bx += 0x0002;
    di += memoryAGet16(cs, 0xb8dc);
    cx = memoryAGet16(cs, 0xb8da);
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    memoryASet16(cs, 0xb8de, memoryAGet16(cs, 0xb8de) - 1);
    if (memoryAGet16(cs, 0xb8de))
        goto loc_d9da;
    ax = ss;
    ds = ax;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_d9fd() // 01ed:bb2d
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    ax += memoryAGet16(ds, bx + 14348);
    memoryASet16(ds, 0x5022, ax);
    bx = memoryAGet16(ss, bp + 8);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    es = memoryAGet16(ds, 0x8350);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x5018, ax);
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x501a, ax);
    bx = memoryAGet16(es, bx);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 20484);
    memoryASet16(ds, 0x5016, ax);
    ax = 0x0003;
    memoryASet16(ds, 0x5024, ax);
    es = memoryAGet16(ds, 0x35b4);
    flags.direction = 0;
    flags.interrupts = 0;
    dx = 0x03ce;
    ax = 0x0005;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0004;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    di = memoryAGet16(ds, 0x5022);
    cx = memoryAGet16(ds, 0x5018);
    si = memoryAGet16(ds, 0x501a);
    bp = memoryAGet16(ds, 0x501e);
    ax = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e0);
    switch (bx)
    {
        case 0: sub_1ed0(); break;
        case 2: sub_db0b(); break;
        case 4: sub_db24(); break;
        case 6: sub_db3f(); break;
        case 8: sub_db65(); break;
        default:
            stop();
    }
    dx = 0x03ce;
    ax = 0x0104;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0202;
    out16(dx, ax);
    di = memoryAGet16(ds, 0x5022);
    cx = memoryAGet16(ds, 0x5018);
    si = memoryAGet16(ds, 0x501a);
    bp = memoryAGet16(ds, 0x501e);
    ax = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e2);
    switch (bx)
    {
        case 0: sub_1ed0(); break;
        case 2: sub_db0b(); break;
        case 4: sub_db24(); break;
        case 6: sub_db3f(); break;
        case 8: sub_db65(); break;
        default:
            stop();
    }
    dx = 0x03ce;
    ax = 0x0204;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0402;
    out16(dx, ax);
    di = memoryAGet16(ds, 0x5022);
    cx = memoryAGet16(ds, 0x5018);
    si = memoryAGet16(ds, 0x501a);
    bp = memoryAGet16(ds, 0x501e);
    ax = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e4);
    switch (bx)
    {
        case 0: sub_1ed0(); break;
        case 2: sub_db0b(); break;
        case 4: sub_db24(); break;
        case 6: sub_db3f(); break;
        case 8: sub_db65(); break;
        default:
            stop();
    }
    dx = 0x03ce;
    ax = 0x0304;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0802;
    out16(dx, ax);
    di = memoryAGet16(ds, 0x5022);
    cx = memoryAGet16(ds, 0x5018);
    si = memoryAGet16(ds, 0x501a);
    bp = memoryAGet16(ds, 0x501e);
    ax = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e6);
    switch (bx)
    {
        case 0: sub_1ed0(); break;
        case 2: sub_db0b(); break;
        case 4: sub_db24(); break;
        case 6: sub_db3f(); break;
        case 8: sub_db65(); break;
        default:
            stop();
    }
    ax = 0x0105;
    dx = 0x03ce;
    out16(dx, ax);
    dx = 0x03c4;
    al = 0x02;
    ah = 0x0f;
    out16(dx, ax);
    flags.interrupts = 1;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_db0b() // 01ed:bc3b
{
    ss = ax;
loc_db0d: // 01ed:bc3d
    al = memoryAGet(es, di);
    al &= memoryAGet(ss, si);
    al |= memoryAGet(ds, si);
    stosb<ES_DI>(al);
    si++;
    di += 0x002f;
    if (--cx)
        goto loc_db0d;
    ax = 0x14f2;
    ds = ax;
    ss = ax;
}
void sub_db24() // 01ed:bc54
{
    ss = ax;
loc_db26: // 01ed:bc56
    ax = memoryAGet16(es, di);
    ax &= memoryAGet16(ss, si);
    ax |= memoryAGet16(ds, si);
    stosw<ES_DI>(ax);
    si += 0x0002;
    di += 0x002e;
    if (--cx)
        goto loc_db26;
    ax = 0x14f2;
    ds = ax;
    ss = ax;
}
void sub_db3f() // 01ed:bc6f
{
    ss = ax;
loc_db41: // 01ed:bc71
    ax = memoryAGet16(es, di);
    ax &= memoryAGet16(ss, si);
    ax |= memoryAGet16(ds, si);
    stosw<ES_DI>(ax);
    al = memoryAGet(es, di);
    al &= memoryAGet(ss, si + 2);
    al |= memoryAGet(ds, si + 2);
    stosb<ES_DI>(al);
    si += 0x0003;
    di += 0x002d;
    if (--cx)
        goto loc_db41;
    ax = 0x14f2;
    ds = ax;
    ss = ax;
}
void sub_db65() // 01ed:bc95
{
    ss = ax;
loc_db67: // 01ed:bc97
    ax = memoryAGet16(es, di);
    ax &= memoryAGet16(ss, si);
    ax |= memoryAGet16(ds, si);
    stosw<ES_DI>(ax);
    ax = memoryAGet16(es, di);
    ax &= memoryAGet16(ss, si + 2);
    ax |= memoryAGet16(ds, si + 2);
    stosw<ES_DI>(ax);
    si += 0x0004;
    di += 0x002c;
    if (--cx)
        goto loc_db67;
    ax = 0x14f2;
    ds = ax;
    ss = ax;
}
void sub_dc65() // 01ed:bd95
{
    ax = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x5028, bx);
    ax = es;
    memoryASet16(ds, 0x502a, ax);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0xbe1a;
    ax = 0x2509;
    interrupt(0x21);
    ds = pop();
}
void sub_dc80() // 01ed:bdb0
{
    push(ds);
    dx = memoryAGet16(ds, 0x5028);
    ds = memoryAGet16(ds, 0x502a);
    ax = 0x2509;
    interrupt(0x21);
    ax = 0x0040;
    ds = ax;
    ax = memoryAGet16(ds, 0x0017);
    ax &= 0xfcf0;
    memoryASet16(ds, 0x0017, ax);
    ds = pop();
}
void sub_dc9e() // 01ed:bdce
{
    sp -= 2;
    push(bp);
    bp = sp;
    bh = 0;
    ax = memoryAGet16(ss, bp + 4);
    if (ax)
        goto loc_dcc8;
loc_dcaa: // 01ed:bdda
    sync();
    bl = memoryAGet(ds, 0x50ac);
    if ((char)bl >= 0)
        goto loc_dcaa;
    bl &= 0x7f;
    memoryASet(ds, 0x50ac, bl);
    ah = bl;
    al = memoryAGet(ds, bx + 20656);
    if (!al)
        goto loc_dcaa;
    memoryASet(ds, 0x50ae, al);
    bp = pop();
    sp += 2;
    return;
loc_dcc8: // 01ed:bdf8
    bl = memoryAGet(ds, 0x50ac);
    if (bl & 0x80)
        goto loc_dcd6;
    ax = 0x0000;
    bp = pop();
    sp += 2;
    return;
loc_dcd6: // 01ed:be06
    bl &= 0x7f;
    ah = bl;
    al = memoryAGet(ds, bx + 20656);
    memoryASet(ds, 0x50ae, al);
    if (al)
        goto loc_dce8;
    ah = 0;
loc_dce8: // 01ed:be18
    bp = pop();
    sp += 2;
}
void sub_dcea() // 01ed:be1a
{
    push(ax);
    push(bx);
    push(ds);
    ax = 0x14f2;
    ds = ax;
    ah = 0;
    al = in8(0x60);
    if ((char)al >= 0)
        goto loc_dd05;
    al &= 0x7f;
    bx = ax;
    memoryASet(ds, bx + 20524, ah);
    goto loc_dd15;
  // gap 1 bytes
loc_dd05: // 01ed:be35
    memoryASet(ds, 0x50ac, al);
    memoryASet(ds, 0x50ac, memoryAGet(ds, 0x50ac) | 0x80);
    bx = ax;
    al = 0x01;
    memoryASet(ds, bx + 20524, al);
loc_dd15: // 01ed:be45
    if (!(memoryAGet16(ds, 0x5026) & 0x0001))
        goto loc_dd2d;
    push(flagAsReg());
    push(cs); cs = memoryAGet16(ds, 0x5028 + 2); callIndirect(cs, memoryAGet16(ds, 0x5028)); assert(cs == 0x01ed); // 01ed:be4e;
    ax = 0x0040;
    ds = ax;
    ax = memoryAGet16(ds, 0x001a);
    memoryASet16(ds, 0x001c, ax);
loc_dd2d: // 01ed:be5d
    al = 0x20;
    out8(0x20, al);
    ds = pop();
    bx = pop();
    ax = pop();
    stop("iret");
}
void sub_dd35() // 01ed:be65
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_dd3e;
    return;
loc_dd3e: // 01ed:be6e
    if (memoryAGet16(ds, 0x513d) & 0xffff)
        goto loc_dd80;
    sub_ddfa();
    ax = 0x3508;
    interrupt(0x21);
    memoryASet16(ds, 0x5145, bx);
    ax = es;
    memoryASet16(ds, 0x5147, ax);
    ax = 0x0008;
    memoryASet(ds, 0x5149, al);
    push(ds);
    push(cs);
    ds = pop();
    dx = 0xbf97;
    ax = 0x2508;
    interrupt(0x21);
    ds = pop();
    bx = 0x2000;
    flags.interrupts = 0;
    al = 0x36;
    out8(0x43, al);
    al = 0x00;
    al = bl;
    out8(0x40, al);
    al = bh;
    out8(0x40, al);
    flags.interrupts = 1;
    memoryASet16(ds, 0x513d, memoryAGet16(ds, 0x513d) + 1);
loc_dd80: // 01ed:beb0
    ax = 0x0001;
    memoryASet16(ds, 0x5143, ax);
}
void sub_dd87() // 01ed:beb7
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_dd90;
    return;
loc_dd90: // 01ed:bec0
    flags.interrupts = 0;
    al = 0x36;
    out8(0x43, al);
    al = 0x00;
    out8(0x40, al);
    out8(0x40, al);
    flags.interrupts = 1;
    ax = memoryAGet16(ds, 0x513d);
    if (ax == 0x0000)
        goto loc_ddc2;
    push(ds);
    dx = memoryAGet16(ds, 0x5145);
    ax = memoryAGet16(ds, 0x5147);
    ds = ax;
    ax = 0x2508;
    interrupt(0x21);
    ds = pop();
    memoryASet16(ds, 0x513d, 0x0000);
    flags.interrupts = 0;
    al = in8(0x61);
    al &= 0xfd;
    out8(0x61, al);
    flags.interrupts = 1;
loc_ddc2: // 01ed:bef2
    return;
}
void sub_ddc3() // 01ed:bef3
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_ddd2;
    si = pop();
    bp = pop();
    sp += 2;
    return;
loc_ddd2: // 01ed:bf02
    ax = memoryAGet16(ss, bp + 4);
    si = ax;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    si <<= 1;
    ax = memoryAGet16(ds, 0x5141);
    es = ax;
    al = memoryAGet(es, si + 2);
    if (al < memoryAGet(ds, 0x514c))
        goto loc_ddf7;
    memoryASet(ds, 0x514c, al);
    ax = memoryAGet16(es, si);
    memoryASet16(ds, 0x514a, ax);
loc_ddf7: // 01ed:bf27
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_ddfa() // 01ed:bf2a
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_de03;
    return;
loc_de03: // 01ed:bf33
    ax = 0;
    memoryASet16(ds, 0x514a, ax);
    memoryASet(ds, 0x514c, al);
    flags.interrupts = 0;
    al = in8(0x61);
    al &= 0xfd;
    out8(0x61, al);
    flags.interrupts = 1;
}
void sub_de14() // 01ed:bf44
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_de1d;
    return;
loc_de1d: // 01ed:bf4d
    ax = memoryAGet16(ds, 0x514a);
    memoryASet16(ds, 0x514d, ax);
    al = memoryAGet(ds, 0x514c);
    memoryASet(ds, 0x514f, al);
    al = memoryAGet(ds, 0x5149);
    memoryASet(ds, 0x5150, al);
    sub_ddfa();
}
void sub_de33() // 01ed:bf63
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_de3c;
    return;
loc_de3c: // 01ed:bf6c
    ax = memoryAGet16(ds, 0x514d);
    memoryASet16(ds, 0x514a, ax);
    al = memoryAGet(ds, 0x514f);
    memoryASet(ds, 0x514c, al);
    al = memoryAGet(ds, 0x5150);
    memoryASet(ds, 0x5149, al);
}
void sub_de4f() // 01ed:bf7f
{
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        goto loc_de58;
    return;
loc_de58: // 01ed:bf88
    push(flagAsReg());
    push(cs);
    sub_de67();
loc_de5e: // 01ed:bf8e
    ax = memoryAGet16(ds, 0x514a);
    if (ax != 0x0000)
        goto loc_de5e;
    stop("stack_unbalanced");
}
void sub_de67() // 01ed:bf97
{
    push(ax);
    push(bx);
    push(cx);
    push(si);
    push(ds);
    push(es);
    ax = 0x14f2;
    ds = ax;
    ax = memoryAGet16(ds, 0x5141);
    es = ax;
    al = 0x20;
    out8(0x20, al);
    flags.carry = (memoryAGet16(ds, 0x5135) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135) + 0x0001);
    memoryASet16(ds, 0x5137, memoryAGet16(ds, 0x5137) + (0x0000 + flags.carry));
    memoryASet(ds, 0x5149, memoryAGet(ds, 0x5149) - 1);
    if (memoryAGet(ds, 0x5149))
        goto loc_de95;
    al = 0x08;
    memoryASet(ds, 0x5149, al);
    push(flagAsReg());
    push(cs); cs = memoryAGet16(ds, 0x5145 + 2); callIndirect(cs, memoryAGet16(ds, 0x5145)); assert(cs == 0x01ed); // 01ed:bfc1;
loc_de95: // 01ed:bfc5
    si = memoryAGet16(ds, 0x514a);
    if (si == 0x0000)
        goto loc_deb9;
    bx = memoryAGet16(es, si);
    memoryASet16(ds, 0x514a, memoryAGet16(ds, 0x514a) + 1);
    memoryASet16(ds, 0x514a, memoryAGet16(ds, 0x514a) + 1);
    if (bx == 0x0000)
        goto loc_deb9;
    if (bx != 0xffff)
        goto loc_dec2;
    sub_ddfa();
    goto loc_dedc;
  // gap 1 bytes
loc_deb9: // 01ed:bfe9
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
    goto loc_dedc;
  // gap 1 bytes
loc_dec2: // 01ed:bff2
    if (!(memoryAGet16(ds, 0x5143) & 0x00ff))
        goto loc_deb9;
    al = 0xb6;
    out8(0x43, al);
    al = bl;
    out8(0x42, al);
    al = bh;
    out8(0x42, al);
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
loc_dedc: // 01ed:c00c
    es = pop();
    ds = pop();
    si = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    stop("iret");
}
void sub_dee3() // 01ed:c013
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = ds;
    es = ax;
    di = 0x525f;
    si = 0x5281;
    cx = 0x0011;
    flags.direction = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    memoryASet16(ds, 0x525d, 0x0000);
    memoryASet16(ds, 0x5259, 0x0022);
    memoryASet16(ds, 0x525b, 0x000a);
    ax = memoryAGet16(ss, bp + 4);
    if (ax == 0x0000)
        goto loc_df20;
    ah = 0x2c;
    interrupt(0x21);
    memoryASet16(ds, 0x527f, dx);
    dx ^= cx;
    memoryASet16(ds, 0x5267, dx);
loc_df20: // 01ed:c050
    ax = 0xffff;
    push(ax);
    sub_df2c();
    ax = pop();
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_df2c() // 01ed:c05c
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = memoryAGet16(ss, bp + 4);
    push(ax);
    dx = 0xffff;
loc_df37: // 01ed:c067
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    if (flags.carry)
        goto loc_df3f;
    dx >>= 1;
    goto loc_df37;
loc_df3f: // 01ed:c06f
    bx = memoryAGet16(ds, 0x5259);
    si = memoryAGet16(ds, 0x525b);
    ax = memoryAGet16(ds, bx + 21085);
    ax += memoryAGet16(ds, si + 21085) + flags.carry;
    memoryASet16(ds, bx + 21085, ax);
    ax += memoryAGet16(ds, 0x525d);
    memoryASet16(ds, 0x525d, ax);
    bx--;
    bx--;
    if (bx)
        goto loc_df61;
    bx = 0x0022;
loc_df61: // 01ed:c091
    si--;
    si--;
    if (si)
        goto loc_df68;
    si = 0x0022;
loc_df68: // 01ed:c098
    memoryASet16(ds, 0x5259, bx);
    memoryASet16(ds, 0x525b, si);
    cx = pop();
    ax &= dx;
    if (ax <= cx)
        goto loc_df79;
    ax >>= 1;
loc_df79: // 01ed:c0a9
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_df7c() // 01ed:c0ac
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    if (ax)
        goto loc_df8e;
    dx = 0x0000;
    goto loc_df96;
  // gap 1 bytes
loc_df8e: // 01ed:c0be
    ah = 0x2c;
    interrupt(0x21);
    dx &= 0x00ff;
loc_df96: // 01ed:c0c6
    memoryASet16(ds, 0x5157, dx);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_df9e() // 01ed:c0ce
{
    bx = memoryAGet16(ds, 0x5157);
    bx++;
    bx &= 0x00ff;
    memoryASet16(ds, 0x5157, bx);
    al = memoryAGet(ds, bx + 20825);
    ah = 0;
}
void sub_dfb2() // 01ed:c0e2
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    cx = memoryAGet16(ss, bp + 4);
loc_dfb9: // 01ed:c0e9
    dx = 0x03da;
    al = in8(dx);
    if (al & 0x08)
        goto loc_dfb9;
loc_dfc1: // 01ed:c0f1
    dx = 0x03da;
    al = in8(dx);
    if (!(al & 0x08))
        goto loc_dfc1;
    bx = 0x0064;
loc_dfcc: // 01ed:c0fc
    bx--;
    if (bx)
        goto loc_dfcc;
    if (--cx)
        goto loc_dfb9;
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_dfd4() // 01ed:c104
{
    sp -= 2;
    push(bp);
    bp = sp;
    flags.interrupts = 0;
    dx = 0x03ce;
    ax = 0x0005;
    out16(dx, ax);
    dx = 0x03ce;
    al = 0x04;
    ah = memoryAGet(ss, bp + 4);
    out16(dx, ax);
    dx = 0x03c4;
    al = 0x02;
    ah = 0x01;
    cl = memoryAGet(ss, bp + 4);
    ah <<= cl;
    out16(dx, ax);
    flags.interrupts = 1;
    bp = pop();
    sp += 2;
}
void sub_e039() // 01ed:c169
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(ds);
    push(si);
    push(di);
    push(cs);
    ds = pop();
    di = 0xc139;
    memoryASet16(ds, di, 0x0000);
    memoryASet16(ds, di + 2, 0x0000);
    memoryASet(ds, 0xc163, 0x01);
    memoryASet(ds, 0xc160, 0x01);
    memoryASet(ds, 0xc166, 0x01);
    cx = 0x0004;
    si = 0xc15d;
loc_e062: // 01ed:c192
    al = lodsb<DS_SI>();
    flags.zero = !(al & al);
    ax = lodsw<DS_SI>();
    if (flags.zero)
        goto loc_e06e;
    push(si);
    push(cx);
    switch (ax)
    {
        case 0xc1af: sub_e07f(); break;
        default:
            stop();
    }
    cx = pop();
    si = pop();
loc_e06e: // 01ed:c19e
    if (--cx)
        goto loc_e062;
    sub_e167();
    al = memoryAGet(ds, 0xc139);
    ah = 0x00;
    di = pop();
    si = pop();
    ds = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_e07f() // 01ed:c1af
{
    ax = 0x1a00;
    interrupt(0x10);
    if (al != 0x1a)
        goto loc_e0ce;
    cx = bx;
    bh = 0;
    if (!ch)
        goto loc_e09f;
    bl = ch;
    bx += bx;
    ax = memoryAGet16(ds, bx + 49475);
    memoryASet16(ds, di + 2, ax);
    bl = cl;
    bh = 0;
loc_e09f: // 01ed:c1cf
    bx += bx;
    ax = memoryAGet16(ds, bx + 49475);
    memoryASet16(ds, di, ax);
    memoryASet(ds, 0xc163, 0x00);
    memoryASet(ds, 0xc160, 0x00);
    memoryASet(ds, 0xc166, 0x00);
    bx = di;
    if (memoryAGet(ds, bx) == 0x01)
        goto loc_e0c5;
    bx = di + 2;
    if (memoryAGet(ds, bx) != 0x01)
        goto loc_e0ce;
loc_e0c5: // 01ed:c1f5
    memoryASet16(ds, bx, 0x0000);
    memoryASet(ds, 0xc166, 0x01);
loc_e0ce: // 01ed:c1fe
    return;
}
void sub_e167() // 01ed:c297
{
    if (memoryAGet16(ds, di + 2) == 0x0000)
        goto loc_e197;
    if ((char)memoryAGet(ds, di) >= (char)0x04)
        goto loc_e197;
    if ((char)memoryAGet(ds, di + 2) >= (char)0x04)
        goto loc_e197;
    ah = 0x0f;
    interrupt(0x10);
    al &= 0x07;
    if (al == 0x07)
        goto loc_e18a;
    if (memoryAGet(ds, di + 1) != 0x01)
        goto loc_e197;
    goto loc_e190;
loc_e18a: // 01ed:c2ba
    if (memoryAGet(ds, di + 1) == 0x01)
        goto loc_e197;
loc_e190: // 01ed:c2c0
    ax = memoryAGet16(ds, di);
    tx = memoryAGet16(ds, di + 2); memoryASet16(ds, di + 2, ax); ax = tx;
    memoryASet16(ds, di, ax);
loc_e197: // 01ed:c2c7
    return;
}
void sub_e1a5() // 01ed:c2d5
{
    memoryASet16(ds, 0x52c5, 0x0000);
    memoryASet16(ds, 0x52c8, 0x0001);
    memoryASet16(ds, 0x52c1, 0x0000);
    memoryASet16(ds, 0x52c3, 0x0000);
    si = memoryAGet16(ds, 0x52bb);
    di = memoryAGet16(ds, 0x52b9);
}
void sub_e22f() // 01ed:c35f
{
    bool temp_cf;

    sub_e1a5();
    tx = di; di = si; si = tx;
    dx = 0x0001;
loc_e237: // 01ed:c367
    es = memoryAGet16(ds, 0x52b7);
    ah = 0;
loc_e23d: // 01ed:c36d
    if (di < 0xfff0)
        goto loc_e266;
    ax = di;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x52b7, memoryAGet16(ds, 0x52b7) + ax);
    di = 0x0000;
    ax = si;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    memoryASet16(ds, 0x52b5, memoryAGet16(ds, 0x52b5) + ax);
    si &= 0x000f;
    goto loc_e237;
loc_e266: // 01ed:c396
    flags.carry = memoryAGet16(ds, 0x52bd) < dx;
    memoryASet16(ds, 0x52bd, memoryAGet16(ds, 0x52bd) - dx);
    temp_cf = memoryAGet16(ds, 0x52bf) < 0x0000 + flags.carry;
    memoryASet16(ds, 0x52bf, memoryAGet16(ds, 0x52bf) - 0x0000 - flags.carry);
    flags.carry = temp_cf;
    if (flags.carry)
        goto loc_e294;
    dx = 0;
    push(ds);
    ds = memoryAGet16(ds, 0x52b5);
    al = lodsb<DS_SI>();
    if (al < 0x80)
        goto loc_e288;
    al -= 0x7f;
    cx = ax;
    dx = ax;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
    goto loc_e23d;
loc_e288: // 01ed:c3b8
    al += 0x03;
    cx = ax;
    dx = ax;
    al = lodsb<DS_SI>();
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    ds = pop();
    goto loc_e23d;
loc_e294: // 01ed:c3c4
    return;
}
void sub_e3e3() // 01ed:c513
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x52b9, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x52b5, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x52bb, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x52b7, ax);
    push(es);
    push(si);
    ax = memoryAGet16(ds, 0x52b5);
    es = ax;
    si = memoryAGet16(ds, 0x52b9);
    ax = memoryAGet16(es, si);
    memoryASet16(ds, 0x52bd, ax);
    ax = memoryAGet16(es, si + 2);
    memoryASet16(ds, 0x52bf, ax);
    si = pop();
    es = pop();
    memoryASet16(ds, 0x52b9, memoryAGet16(ds, 0x52b9) + 0x0004);
    sub_e22f();
    bp = pop();
    sp += 2;
}
void sub_e422() // 01ed:c552
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_ee3d();
    cx = pop();
    cx = pop();
    si = ax;
    if (ax != 0xffff)
        goto loc_e43a;
    goto loc_e454;
loc_e43a: // 01ed:c56a
    if (!(memoryAGet16(ss, bp + 6) & 0x0002))
        goto loc_e447;
    if (si & 0x0001)
        goto loc_e44b;
loc_e447: // 01ed:c577
    ax = 0;
    goto loc_e454;
loc_e44b: // 01ed:c57b
    memoryASet16(ds, 0x0092, 0x0005);
    ax = 0xffff;
loc_e454: // 01ed:c584
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e47b() // 01ed:c5ab
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_e48b;
    if ((short)si < (short)0x0014)
        goto loc_e494;
loc_e48b: // 01ed:c5bb
    ax = 0x0006;
    push(ax);
    sub_f166();
    goto loc_e4a3;
loc_e494: // 01ed:c5c4
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 21784, 0xffff);
    push(si);
    sub_ee58();
    cx = pop();
loc_e4a3: // 01ed:c5d3
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e4a7() // 01ed:c5d7
{
    sp -= 2;
    push(bp);
    bp = sp;
    goto loc_e4b6;
loc_e4ac: // 01ed:c5dc
    bx = memoryAGet16(ds, 0x52cc);
    bx <<= 1;
    callIndirect(cs, memoryAGet16(ds, bx + 44032)); // 01ed:c5e2;
loc_e4b6: // 01ed:c5e6
    ax = memoryAGet16(ds, 0x52cc);
    memoryASet16(ds, 0x52cc, memoryAGet16(ds, 0x52cc) - 1);
    if (ax)
        goto loc_e4ac;
    push(memoryAGet16(ss, bp + 4));
    sub_1fdf();
    cx = pop();
    bp = pop();
    sp += 2;
}
void sub_e4ca() // 01ed:c5fa +stackDrop4
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    si = ax;
    si -= memoryAGet16(ds, 0x008e);
    ax = si;
    ax += 0x003f;
    cl = 0x06;
    ax >>= cl;
    si = ax;
    if (ax != memoryAGet16(ds, 0x53d6))
        goto loc_e4fc;
loc_e4ea: // 01ed:c61a
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x00a0, dx);
    memoryASet16(ds, 0x00a2, ax);
    ax = 0x0001;
    goto loc_e542;
loc_e4fc: // 01ed:c62c
    cl = 0x06;
    si <<= cl;
    di = memoryAGet16(ds, 0x00a6);
    ax = si;
    ax += memoryAGet16(ds, 0x008e);
    if (ax <= di)
        goto loc_e516;
    ax = di;
    ax -= memoryAGet16(ds, 0x008e);
    si = ax;
loc_e516: // 01ed:c646
    push(si);
    push(memoryAGet16(ds, 0x008e));
    sub_f5ce();
    cx = pop();
    cx = pop();
    di = ax;
    if (ax != 0xffff)
        goto loc_e532;
    ax = si;
    cl = 0x06;
    ax >>= cl;
    memoryASet16(ds, 0x53d6, ax);
    goto loc_e4ea;
loc_e532: // 01ed:c662
    ax = memoryAGet16(ds, 0x008e);
    ax += di;
    memoryASet16(ds, 0x00a4, 0x0000);
    memoryASet16(ds, 0x00a6, ax);
    ax = 0;
loc_e542: // 01ed:c672
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
    sp += 4;
}
void sub_e548() // 01ed:c678
{
    sp -= 2;
    push(bp);
    bp = sp;
    cx = memoryAGet16(ds, 0x009e);
    bx = memoryAGet16(ds, 0x009c);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1044a();
    if (flags.carry)
        goto loc_e57e;
    cx = memoryAGet16(ds, 0x00a6);
    bx = memoryAGet16(ds, 0x00a4);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_1044a();
    if (!flags.carry && !flags.zero)
        goto loc_e57e;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_e4ca();
    if (ax)
        goto loc_e583;
loc_e57e: // 01ed:c6ae
    ax = 0xffff;
    goto loc_e585;
loc_e583: // 01ed:c6b3
    ax = 0;
loc_e585: // 01ed:c6b5
    bp = pop();
    sp += 2;
}
void sub_e587() // 01ed:c6b7
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0008;
    dx = memoryAGet16(ds, 0x00a2);
    ax = memoryAGet16(ds, 0x00a0);
    cx = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    sub_1010b();
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    cx = memoryAGet16(ds, 0x009e);
    bx = memoryAGet16(ds, 0x009c);
    ax = memoryAGet16(ss, bp - 4);
    sub_1044a();
    if (flags.carry)
        goto loc_e5c6;
    cx = memoryAGet16(ds, 0x00a6);
    bx = memoryAGet16(ds, 0x00a4);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    sub_1044a();
    if (flags.carry || flags.zero)
        goto loc_e5ce;
loc_e5c6: // 01ed:c6f6
    dx = 0xffff;
    ax = 0xffff;
    goto loc_e5f0;
loc_e5ce: // 01ed:c6fe
    ax = memoryAGet16(ds, 0x00a2);
    dx = memoryAGet16(ds, 0x00a0);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_e4ca();
    if (ax)
        goto loc_e5ea;
    goto loc_e5c6;
loc_e5ea: // 01ed:c71a
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
loc_e5f0: // 01ed:c720
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_e5f4() // 01ed:c724
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    if (si)
        goto loc_e605;
    sub_e676();
    goto loc_e670;
loc_e605: // 01ed:c735
    if (memoryAGet16(ds, si + 14) == si)
        goto loc_e60f;
loc_e60a: // 01ed:c73a
    ax = 0xffff;
    goto loc_e672;
loc_e60f: // 01ed:c73f
    if ((short)memoryAGet16(ds, si) < (short)0x0000)
        goto loc_e63d;
    if (memoryAGet16(ds, si + 2) & 0x0008)
        goto loc_e625;
    ax = si;
    ax += 0x0005;
    if (memoryAGet16(ds, si + 10) != ax)
        goto loc_e63b;
loc_e625: // 01ed:c755
    memoryASet16(ds, si, 0x0000);
    ax = si;
    ax += 0x0005;
    if (memoryAGet16(ds, si + 10) != ax)
        goto loc_e63b;
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 10, ax);
    goto loc_e670;
loc_e63b: // 01ed:c76b
    goto loc_e670;
loc_e63d: // 01ed:c76d
    ax = memoryAGet16(ds, si + 6);
    ax += memoryAGet16(ds, si);
    ax++;
    di = ax;
    ax = memoryAGet16(ds, si);
    ax -= di;
    memoryASet16(ds, si, ax);
    push(di);
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 10, ax);
    push(ax);
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_ec32();
    sp += 0x0006;
    if (ax == di)
        goto loc_e670;
    if (memoryAGet16(ds, si + 2) & 0x0200)
        goto loc_e670;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0010);
    goto loc_e60a;
loc_e670: // 01ed:c7a0
    ax = 0;
loc_e672: // 01ed:c7a2
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e676() // 01ed:c7a6
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    di = 0x0014;
    si = 0x53d8;
    goto loc_e69c;
loc_e68a: // 01ed:c7ba
    if (!(memoryAGet16(ds, si + 2) & 0x0003))
        goto loc_e699;
    push(si);
    sub_e5f4();
    cx = pop();
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_e699: // 01ed:c7c9
    si += 0x0010;
loc_e69c: // 01ed:c7cc
    ax = di;
    di--;
    if (ax)
        goto loc_e68a;
    ax = memoryAGet16(ss, bp - 2);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_e6ac() // 01ed:c7dc +stackDrop2
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 4);
    if ((short)memoryAGet16(ds, bx) >= (short)0x0000)
        goto loc_e6c1;
    ax = memoryAGet16(ds, bx + 6);
    ax += memoryAGet16(ds, bx);
    ax++;
    goto loc_e6cb;
loc_e6c1: // 01ed:c7f1
    bx = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ds, bx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    ax ^= dx;
    ax -= dx;
loc_e6cb: // 01ed:c7fb
    si = ax;
    cx = ax;
    bx = memoryAGet16(ss, bp + 4);
    if (!(memoryAGet16(ds, bx + 2) & 0x0040))
        goto loc_e6db;
    goto loc_e70a;
loc_e6db: // 01ed:c80b
    bx = memoryAGet16(ss, bp + 4);
    di = memoryAGet16(ds, bx + 10);
    if ((short)memoryAGet16(ds, bx) >= (short)0x0000)
        goto loc_e703;
    goto loc_e6f1;
loc_e6e8: // 01ed:c818
    di--;
    bx = di;
    if (memoryAGet(ds, bx) != 0x0a)
        goto loc_e6f1;
    cx++;
loc_e6f1: // 01ed:c821
    ax = si;
    si--;
    if (ax)
        goto loc_e6e8;
    goto loc_e70a;
loc_e6fa: // 01ed:c82a
    bx = di;
    di++;
    if (memoryAGet(ds, bx) != 0x0a)
        goto loc_e703;
    cx++;
loc_e703: // 01ed:c833
    ax = si;
    si--;
    if (ax)
        goto loc_e6fa;
loc_e70a: // 01ed:c83a
    ax = cx;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
    sp += 2;
}
void sub_e712() // 01ed:c842
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e727;
    ax = 0xffff;
    goto loc_e771;
loc_e727: // 01ed:c857
    if (memoryAGet16(ss, bp + 10) != 0x0001)
        goto loc_e73d;
    if ((short)memoryAGet16(ds, si) <= (short)0x0000)
        goto loc_e73d;
    push(si);
    sub_e6ac();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, bp + 6) < ax;
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) - ax);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - dx - flags.carry);
loc_e73d: // 01ed:c86d
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) & 0xfe5f);
    memoryASet16(ds, si, 0x0000);
    ax = memoryAGet16(ds, si + 8);
    memoryASet16(ds, si + 10, ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_f1b4();
    sp += 0x0008;
    if (dx != 0xffff)
        goto loc_e76f;
    if (ax != 0xffff)
        goto loc_e76f;
    ax = 0xffff;
    goto loc_e771;
loc_e76f: // 01ed:c89f
    ax = 0;
loc_e771: // 01ed:c8a1
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e7b5() // 01ed:c8e5
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = memoryAGet(ss, bp + 6);
    al += 0xff;
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ds, 0x554f);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + al);
    al = memoryAGet(ss, bp + 4);
    al += 0xff;
    memoryASet(ss, bp - 2, al);
    al = memoryAGet(ds, 0x554e);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + al);
    al = memoryAGet(ss, bp - 1);
    if (al < memoryAGet(ds, 0x554f))
        goto loc_e801;
    if (al > memoryAGet(ds, 0x5551))
        goto loc_e801;
    al = memoryAGet(ss, bp - 2);
    if (al < memoryAGet(ds, 0x554e))
        goto loc_e801;
    if (al > memoryAGet(ds, 0x5550))
        goto loc_e801;
    dl = memoryAGet(ss, bp - 2);
    dh = memoryAGet(ss, bp - 1);
    ah = 0x02;
    bh = 0x00;
    sub_eeae();
loc_e801: // 01ed:c931
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_e805() // 01ed:c935
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = 0xca7c;
    push(ax);
    ax = 0x53e8;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    ax = bp + 6;
    push(ax);
    sub_f679();
    bp = pop();
    sp += 2;
}
void sub_e81c() // 01ed:c94c
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ds, si);
    ax--;
    memoryASet16(ds, si, ax);
    push(si);
    al = memoryAGet(ss, bp + 4);
    cbw();
    push(ax);
    sub_e836();
    cx = pop();
    cx = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e836() // 01ed:c966
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0xac40, al);
    if ((short)memoryAGet16(ds, si) >= (short)0xffff)
        goto loc_e87f;
    ax = memoryAGet16(ds, si);
    ax++;
    memoryASet16(ds, si, ax);
    bx = memoryAGet16(ds, si + 10);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 1);
    al = memoryAGet(ds, 0xac40);
    memoryASet(ds, bx, al);
    if (!(memoryAGet16(ds, si + 2) & 0x0008))
        goto loc_e87c;
    if (memoryAGet(ds, 0xac40) == 0x0a)
        goto loc_e86d;
    if (memoryAGet(ds, 0xac40) != 0x0d)
        goto loc_e87c;
loc_e86d: // 01ed:c99d
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e87c;
loc_e876: // 01ed:c9a6
    ax = 0xffff;
    goto loc_e935;
loc_e87c: // 01ed:c9ac
    goto loc_e930;
loc_e87f: // 01ed:c9af
    if (memoryAGet16(ds, si + 2) & 0x0090)
        goto loc_e88d;
    if (memoryAGet16(ds, si + 2) & 0x0002)
        goto loc_e894;
loc_e88d: // 01ed:c9bd
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0010);
    goto loc_e876;
loc_e894: // 01ed:c9c4
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0100);
    if (memoryAGet16(ds, si + 6) == 0x0000)
        goto loc_e8e3;
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_e8af;
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e8af;
    goto loc_e876;
loc_e8af: // 01ed:c9df
    ax = memoryAGet16(ds, si + 6);
    ax = -ax;
    memoryASet16(ds, si, ax);
    bx = memoryAGet16(ds, si + 10);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 1);
    al = memoryAGet(ds, 0xac40);
    memoryASet(ds, bx, al);
    if (!(memoryAGet16(ds, si + 2) & 0x0008))
        goto loc_e8e1;
    if (memoryAGet(ds, 0xac40) == 0x0a)
        goto loc_e8d6;
    if (memoryAGet(ds, 0xac40) != 0x0d)
        goto loc_e8e1;
loc_e8d6: // 01ed:ca06
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e8e1;
    goto loc_e876;
loc_e8e1: // 01ed:ca11
    goto loc_e930;
loc_e8e3: // 01ed:ca13
    if (memoryAGet(ds, 0xac40) != 0x0a)
        goto loc_e909;
    if (memoryAGet16(ds, si + 2) & 0x0040)
        goto loc_e909;
    ax = 0x0001;
    push(ax);
    ax = 0x5546;
    push(ax);
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_fb3d();
    sp += 0x0006;
    if (ax != 0x0001)
        goto loc_e921;
loc_e909: // 01ed:ca39
    ax = 0x0001;
    push(ax);
    ax = 0xac40;
    push(ax);
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_fb3d();
    sp += 0x0006;
    if (ax == 0x0001)
        goto loc_e930;
loc_e921: // 01ed:ca51
    if (memoryAGet16(ds, si + 2) & 0x0200)
        goto loc_e930;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0010);
    goto loc_e876;
loc_e930: // 01ed:ca60
    al = memoryAGet(ds, 0xac40);
    ah = 0x00;
loc_e935: // 01ed:ca65
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_e94c() // 01ed:ca7c +stackDrop6
{
    bool temp_cond0;

    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    si = memoryAGet16(ss, bp + 4);
    memoryASet16(ss, bp - 2, di);
    if (!(memoryAGet16(ds, si + 2) & 0x0008))
        goto loc_e989;
    goto loc_e97f;
loc_e965: // 01ed:ca95
    push(si);
    bx = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
    al = memoryAGet(ds, bx);
    cbw();
    push(ax);
    sub_e836();
    cx = pop();
    cx = pop();
    if (ax != 0xffff)
        goto loc_e97f;
loc_e97a: // 01ed:caaa
    ax = 0;
    goto loc_ea76;
loc_e97f: // 01ed:caaf
    ax = di;
    di--;
    if (ax)
        goto loc_e965;
    goto loc_ea73;
loc_e989: // 01ed:cab9
    if (memoryAGet16(ds, si + 2) & 0x0040)
        goto loc_e993;
    goto loc_ea16;
loc_e993: // 01ed:cac3
    if (memoryAGet16(ds, si + 6) == 0x0000)
        goto loc_e9fe;
    if (memoryAGet16(ds, si + 6) >= di)
        goto loc_e9c6;
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_e9ae;
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e9ae;
    goto loc_e97a;
loc_e9ae: // 01ed:cade
    push(di);
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_fb3d();
    sp += 0x0006;
    if (ax >= di)
        goto loc_e9c3;
    goto loc_e97a;
loc_e9c3: // 01ed:caf3
    goto loc_ea73;
loc_e9c6: // 01ed:caf6
    ax = memoryAGet16(ds, si);
    temp_cond0 = (short)ax + (short)di < 0;
    ax += di;
    if (temp_cond0)
        goto loc_e9e6;
    if (memoryAGet16(ds, si) != 0x0000)
        goto loc_e9db;
    ax = 0xffff;
    ax -= memoryAGet16(ds, si + 6);
    memoryASet16(ds, si, ax);
    goto loc_e9e6;
loc_e9db: // 01ed:cb0b
    push(si);
    sub_e5f4();
    cx = pop();
    if (!ax)
        goto loc_e9e6;
    goto loc_e97a;
loc_e9e6: // 01ed:cb16
    push(di);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ds, si + 10));
    sub_f2c0();
    sp += 0x0006;
    ax = memoryAGet16(ds, si);
    ax += di;
    memoryASet16(ds, si, ax);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + di);
    goto loc_ea73;
loc_e9fe: // 01ed:cb2e
    push(di);
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_fb3d();
    sp += 0x0006;
    if (ax >= di)
        goto loc_ea14;
    goto loc_e97a;
loc_ea14: // 01ed:cb44
    goto loc_ea73;
loc_ea16: // 01ed:cb46
    if (memoryAGet16(ds, si + 6) == 0x0000)
        goto loc_ea5d;
    goto loc_ea54;
loc_ea1e: // 01ed:cb4e
    ax = memoryAGet16(ds, si);
    ax++;
    memoryASet16(ds, si, ax);
    if ((short)ax >= 0)
        goto loc_ea3d;
    bx = memoryAGet16(ds, si + 10);
    memoryASet16(ds, si + 10, memoryAGet16(ds, si + 10) + 1);
    push(bx);
    bx = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
    al = memoryAGet(ds, bx);
    bx = pop();
    memoryASet(ds, bx, al);
    ah = 0x00;
    goto loc_ea4c;
loc_ea3d: // 01ed:cb6d
    push(si);
    bx = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
    al = memoryAGet(ds, bx);
    push(ax);
    sub_e81c();
    cx = pop();
    cx = pop();
loc_ea4c: // 01ed:cb7c
    if (ax != 0xffff)
        goto loc_ea54;
    goto loc_e97a;
loc_ea54: // 01ed:cb84
    ax = di;
    di--;
    if (ax)
        goto loc_ea1e;
    goto loc_ea73;
loc_ea5d: // 01ed:cb8d
    push(di);
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ds, si + 4);
    cbw();
    push(ax);
    sub_ec32();
    sp += 0x0006;
    if (ax >= di)
        goto loc_ea73;
    goto loc_e97a;
loc_ea73: // 01ed:cba3
    ax = memoryAGet16(ss, bp - 2);
loc_ea76: // 01ed:cba6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
    sp += 6;
}
void sub_ea7e() // 01ed:cbae
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    push(si);
    sub_f647();
    cx = pop();
    di = ax;
    push(si);
    push(ax);
    ax = 0x53e8;
    push(ax);
    sub_e94c();
    if (ax == di)
        goto loc_ea9f;
    ax = 0xffff;
    goto loc_eab9;
loc_ea9f: // 01ed:cbcf
    ax = 0x53e8;
    push(ax);
    ax = 0x000a;
    push(ax);
    sub_e836();
    cx = pop();
    cx = pop();
    if (ax == 0x000a)
        goto loc_eab6;
    ax = 0xffff;
    goto loc_eab9;
loc_eab6: // 01ed:cbe6
    ax = 0x000a;
loc_eab9: // 01ed:cbe9
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_eabd() // 01ed:cbed
{
    sp -= 2;
    al = memoryAGet(ds, 0x53dc);
    cbw();
    push(ax);
    sub_f1a3();
    cx = pop();
    if (ax)
        goto loc_ead0;
    memoryASet16(ds, 0x53da, memoryAGet16(ds, 0x53da) & 0xfdff);
loc_ead0: // 01ed:cc00
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x53da) & ax))
        goto loc_eadf;
    ax = 0x0001;
    goto loc_eae1;
loc_eadf: // 01ed:cc0f
    ax = 0;
loc_eae1: // 01ed:cc11
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x53d8;
    push(ax);
    sub_eb22();
    sp += 0x0008;
    al = memoryAGet(ds, 0x53ec);
    cbw();
    push(ax);
    sub_f1a3();
    cx = pop();
    if (ax)
        goto loc_eb02;
    memoryASet16(ds, 0x53ea, memoryAGet16(ds, 0x53ea) & 0xfdff);
loc_eb02: // 01ed:cc32
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x53ea) & ax))
        goto loc_eb11;
    ax = 0x0002;
    goto loc_eb13;
loc_eb11: // 01ed:cc41
    ax = 0;
loc_eb13: // 01ed:cc43
    push(ax);
    ax = 0;
    push(ax);
    ax = 0x53e8;
    push(ax);
    sub_eb22();
    sp += 0x0008;
    sp += 2;
}
void sub_eb22() // 01ed:cc52
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 4);
    di = memoryAGet16(ss, bp + 10);
    if (memoryAGet16(ds, si + 14) != si)
        goto loc_eb3e;
    if ((short)memoryAGet16(ss, bp + 8) > (short)0x0002)
        goto loc_eb3e;
    if (di <= 0x7fff)
        goto loc_eb44;
loc_eb3e: // 01ed:cc6e
    ax = 0xffff;
    goto loc_ebea;
loc_eb44: // 01ed:cc74
    if (memoryAGet16(ds, 0x554a) != 0x0000)
        goto loc_eb59;
    if (si != 0x53e8)
        goto loc_eb59;
    memoryASet16(ds, 0x554a, 0x0001);
    goto loc_eb6c;
loc_eb59: // 01ed:cc89
    if (memoryAGet16(ds, 0x5548) != 0x0000)
        goto loc_eb6c;
    if (si != 0x53d8)
        goto loc_eb6c;
    memoryASet16(ds, 0x5548, 0x0001);
loc_eb6c: // 01ed:cc9c
    if (memoryAGet16(ds, si) == 0x0000)
        goto loc_eb82;
    ax = 0x0001;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(si);
    sub_e712();
    sp += 0x0008;
loc_eb82: // 01ed:ccb2
    if (!(memoryAGet16(ds, si + 2) & 0x0004))
        goto loc_eb90;
    push(memoryAGet16(ds, si + 8));
    sub_101c0();
    cx = pop();
loc_eb90: // 01ed:ccc0
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) & 0xfff3);
    memoryASet16(ds, si + 6, 0x0000);
    ax = si;
    ax += 0x0005;
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 10, ax);
    if (memoryAGet16(ss, bp + 8) == 0x0002)
        goto loc_ebe8;
    if (!di)
        goto loc_ebe8;
    memoryASet16(ds, 0x53d0, 0xce51);
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_ebd1;
    push(di);
    sub_1028f();
    cx = pop();
    memoryASet16(ss, bp + 6, ax);
    if (!ax)
        goto loc_ebce;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0004);
    goto loc_ebd1;
loc_ebce: // 01ed:ccfe
    goto loc_eb3e;
loc_ebd1: // 01ed:cd01
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, si + 10, ax);
    memoryASet16(ds, si + 8, ax);
    memoryASet16(ds, si + 6, di);
    if (memoryAGet16(ss, bp + 8) != 0x0001)
        goto loc_ebe8;
    memoryASet16(ds, si + 2, memoryAGet16(ds, si + 2) | 0x0008);
loc_ebe8: // 01ed:cd18
    ax = 0;
loc_ebea: // 01ed:cd1a
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_ec06() // 01ed:cd36
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 4);
    if (dx != 0xffff)
        goto loc_ec16;
    ax = 0xffff;
    goto loc_ec30;
loc_ec16: // 01ed:cd46
    al = dl;
    ah = 0x00;
    bx = ax;
    if (!(memoryAGet(ds, bx + 21199) & 0x08))
        goto loc_ec2c;
    al = dl;
    ah = 0x00;
    ax += 0xffe0;
    goto loc_ec30;
loc_ec2c: // 01ed:cd5c
    al = dl;
    ah = 0x00;
loc_ec30: // 01ed:cd60
    bp = pop();
    sp += 2;
}
void sub_ec32() // 01ed:cd62
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x008a;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    if (ax >= 0x0002)
        goto loc_ec49;
    ax = 0;
    goto loc_ed1b;
loc_ec49: // 01ed:cd79
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 21784) & 0x8000))
        goto loc_ec68;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_fb3d();
    sp += 0x0006;
    goto loc_ed1b;
loc_ec68: // 01ed:cd98
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 21784, memoryAGet16(ds, bx + 21784) & 0xfdff);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 4, ax);
    goto loc_ecd6;
loc_ec81: // 01ed:cdb1
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
    bx = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    al = memoryAGet(ds, bx);
    memoryASet(ss, bp - 5, al);
    if (al != 0x0a)
        goto loc_ec97;
    memoryASet(ds, si, 0x0d);
    si++;
loc_ec97: // 01ed:cdc7
    al = memoryAGet(ss, bp - 5);
    memoryASet(ds, si, al);
    si++;
    ax = bp - 138;
    dx = si;
    dx -= ax;
    if ((short)dx < (short)0x0080)
        goto loc_ecdc;
    dx = si;
    dx -= ax;
    di = dx;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_fb3d();
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax == di)
        goto loc_ecd6;
    if (!stop() /*ggg9*/)
        goto loc_eccc;
loc_ecc7: // 01ed:cdf7
    ax = 0xffff;
    goto loc_ed16;
loc_eccc: // 01ed:cdfc
    ax = memoryAGet16(ss, bp + 8);
    ax -= memoryAGet16(ss, bp - 4);
    goto loc_ed11;
  // gap 2 bytes
loc_ecd6: // 01ed:ce06
    ax = bp - 138;
    si = ax;
loc_ecdc: // 01ed:ce0c
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_ec81;
    ax = bp - 138;
    dx = si;
    dx -= ax;
    di = dx;
    ax = dx;
    if (!ax)
        goto loc_ed18;
    push(dx);
    ax = bp - 138;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_fb3d();
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax == di)
        goto loc_ed18;
    if (!stop() /*ggg9*/)
        goto loc_ed0e;
    goto loc_ecc7;
loc_ed0e: // 01ed:ce3e
    ax = memoryAGet16(ss, bp + 8);
loc_ed11: // 01ed:ce41
    ax += memoryAGet16(ss, bp - 2);
    ax -= di;
loc_ed16: // 01ed:ce46
    goto loc_ed1b;
loc_ed18: // 01ed:ce48
    ax = memoryAGet16(ss, bp + 8);
loc_ed1b: // 01ed:ce4b
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_edce() // 01ed:cefe
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = sp;
    dx -= 0x0200;
    if (ax >= dx)
        goto loc_ede5;
    memoryASet16(ds, 0x009a, ax);
    ax = 0;
    goto loc_edee;
loc_ede5: // 01ed:cf15
    memoryASet16(ds, 0x0092, 0x0008);
    ax = 0xffff;
loc_edee: // 01ed:cf1e
    bp = pop();
    sp += 2;
}
void sub_edf0() // 01ed:cf20
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    flags.carry = (ax + memoryAGet16(ds, 0x009a)) >= 0x10000;
    ax += memoryAGet16(ds, 0x009a);
    dx += 0x0000 + flags.carry;
    cx = ax;
    if (dx)
        goto loc_ee16;
    flags.carry = (cx + 0x0200) >= 0x10000;
    cx += 0x0200;
    if (flags.carry)
        goto loc_ee16;
    if (cx >= sp)
        goto loc_ee16;
    tx = memoryAGet16(ds, 0x009a); memoryASet16(ds, 0x009a, ax); ax = tx;
    goto loc_ee1f;
loc_ee16: // 01ed:cf46
    memoryASet16(ds, 0x0092, 0x0008);
    ax = 0xffff;
loc_ee1f: // 01ed:cf4f
    bp = pop();
    sp += 2;
}
void sub_ee3d() // 01ed:cf6d
{
    sp -= 2;
    push(bp);
    bp = sp;
    cx = memoryAGet16(ss, bp + 8);
    ah = 0x43;
    al = memoryAGet(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_ee52;
    tx = cx; cx = ax; ax = tx;
    goto loc_ee56;
loc_ee52: // 01ed:cf82
    push(ax);
    sub_f166();
loc_ee56: // 01ed:cf86
    bp = pop();
    sp += 2;
}
void sub_ee58() // 01ed:cf88
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x3e;
    bx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_ee70;
    bx <<= 1;
    memoryASet16(ds, bx + 21784, 0xffff);
    ax = 0;
    goto loc_ee74;
loc_ee70: // 01ed:cfa0
    push(ax);
    sub_f166();
loc_ee74: // 01ed:cfa4
    bp = pop();
    sp += 2;
}
void sub_ee76() // 01ed:cfa6
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    goto loc_ee93;
loc_ee7f: // 01ed:cfaf
    bx = memoryAGet16(ss, bp + 6); es = memoryAGet16(ss, bp + 6 + 2); /*ggg2*/;
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) + 1);
    al = memoryAGet(es, bx);
    bx = si;
    si++;
    if (al == memoryAGet(ds, bx))
        goto loc_ee93;
    ax = 0;
    goto loc_ee9b;
loc_ee93: // 01ed:cfc3
    if (memoryAGet(ds, si) != 0x00)
        goto loc_ee7f;
    ax = 0x0001;
loc_ee9b: // 01ed:cfcb
    si = pop();
    bp = pop();
//    stop("stack_below, 0/6");
    sp += 2;
    sp += 6;
}
void sub_eea0() // 01ed:cfd0
{
    ah = 0x12;
    bl = 0x10;
    sub_eeae();
    al = bl;
    al += 0xf0;
    ah = 0x00;
}
void sub_eeae() // 01ed:cfde
{
    push(bp);
    push(ds);
    push(cx);
    cx = 0x0040;
    ds = cx;
    cx = pop();
    if (ah == 0x00)
        goto loc_eec5;
    if (ah == 0x0f)
        goto loc_ef17;
loc_eec1: // 01ed:cff1
    interrupt(0x10);
    goto loc_ef2f;
loc_eec5: // 01ed:cff5
    if (al != 0x03)
        goto loc_eee3;
    ax = 0x1a00;
    interrupt(0x10);
    if (al == 0x1a)
        goto loc_eed7;
    memoryASet(ds, 0x0087, memoryAGet(ds, 0x0087) & 0xfe);
loc_eed7: // 01ed:d007
    ah = 0x01;
    cx = 0x0607;
    interrupt(0x10);
    ax = 0x0003;
    goto loc_eec1;
loc_eee3: // 01ed:d013
    if (al != 0x40)
        goto loc_eec1;
    bl = 0x10;
    ah = 0x12;
    interrupt(0x10);
    if (bl == 0x10)
        goto loc_ef2f;
    ax = 0x1112;
    bl = 0;
    interrupt(0x10);
    ax = 0x1200;
    bl = 0x20;
    interrupt(0x10);
    ax = 0x1a00;
    interrupt(0x10);
    if (al == 0x1a)
        goto loc_ef2f;
    memoryASet(ds, 0x0087, memoryAGet(ds, 0x0087) | 0x01);
    ah = 0x01;
    cx = 0x0600;
    interrupt(0x10);
    goto loc_ef2f;
loc_ef17: // 01ed:d047
    interrupt(0x10);
    if (al != 0x03)
        goto loc_ef2f;
    push(ax);
    sub_eea0();
    flags.zero = !al;
    ax = pop();
    if (flags.zero)
        goto loc_ef2f;
    if (memoryAGet(ds, 0x0084) == 0x18)
        goto loc_ef2f;
    al = 0x40;
loc_ef2f: // 01ed:d05f
    ds = pop();
    bp = pop();
}
void sub_ef32() // 01ed:d062
{
    ah = 0x0f;
    sub_eeae();
    push(ax);
    sub_ef52();
    cx = pop();
    ah = 0x08;
    bh = 0x00;
    sub_eeae();
    al = ah;
    al &= 0x7f;
    ah = al;
    memoryASet(ds, 0x5553, ah);
    memoryASet(ds, 0x5552, ah);
}
void sub_ef52() // 01ed:d082
{
    sp -= 2;
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x5554, al);
    ah = 0x0f;
    sub_eeae();
    memoryASet(ds, 0x5556, ah);
    if (al == memoryAGet(ds, 0x5554))
        goto loc_ef97;
    al = memoryAGet(ds, 0x5554);
    ah = 0x00;
    sub_eeae();
    ah = 0x0f;
    sub_eeae();
    memoryASet(ds, 0x5554, al);
    memoryASet(ds, 0x5556, ah);
    if (memoryAGet(ds, 0x5554) != 0x03)
        goto loc_ef97;
    ax = 0x0040;
    es = ax;
    if ((char)memoryAGet(es, 0x0084) <= (char)0x18)
        goto loc_ef97;
    memoryASet(ds, 0x5554, 0x40);
loc_ef97: // 01ed:d0c7
    if (memoryAGet(ds, 0x5554) <= 0x03)
        goto loc_efb1;
    if (memoryAGet(ds, 0x5554) >= 0x40)
        goto loc_efb1;
    if (memoryAGet(ds, 0x5554) == 0x07)
        goto loc_efb1;
    ax = 0x0001;
    goto loc_efb3;
loc_efb1: // 01ed:d0e1
    ax = 0;
loc_efb3: // 01ed:d0e3
    memoryASet(ds, 0x5557, al);
    if (memoryAGet(ds, 0x5554) == 0x40)
        goto loc_efc1;
    al = 0x19;
    goto loc_efcc;
loc_efc1: // 01ed:d0f1
    ax = 0x0040;
    es = ax;
    al = memoryAGet(es, 0x0084);
    al++;
loc_efcc: // 01ed:d0fc
    memoryASet(ds, 0x5555, al);
    if (memoryAGet(ds, 0x5554) == 0x07)
        goto loc_eff5;
    ax = 0xf000;
    dx = 0xffea;
    push(ax);
    push(dx);
    ax = 0x555f;
    push(ax);
    sub_ee76();
    if (ax)
        goto loc_eff5;
    sub_eea0();
    if (ax)
        goto loc_eff5;
    ax = 0x0001;
    goto loc_eff7;
loc_eff5: // 01ed:d125
    ax = 0;
loc_eff7: // 01ed:d127
    memoryASet(ds, 0x5558, al);
    if (memoryAGet(ds, 0x5554) != 0x07)
        goto loc_f006;
    ax = 0xb000;
    goto loc_f009;
loc_f006: // 01ed:d136
    ax = 0xb800;
loc_f009: // 01ed:d139
    memoryASet16(ds, 0x555b, ax);
    memoryASet16(ds, 0x5559, 0x0000);
    al = 0x00;
    memoryASet(ds, 0x554f, al);
    memoryASet(ds, 0x554e, al);
    al = memoryAGet(ds, 0x5556);
    al += 0xff;
    memoryASet(ds, 0x5550, al);
    al = memoryAGet(ds, 0x5555);
    al += 0xff;
    memoryASet(ds, 0x5551, al);
    bp = pop();
    sp += 2;
}
void sub_f02c() // 01ed:d15c
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = 0x4201;
    bx = memoryAGet16(ss, bp + 4);
    cx = 0;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_f064;
    push(dx);
    push(ax);
    ax = 0x4202;
    cx = 0;
    dx = 0;
    interrupt(0x21);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    dx = pop();
    cx = pop();
    if (flags.carry)
        goto loc_f064;
    ax = 0x4200;
    interrupt(0x21);
    if (flags.carry)
        goto loc_f064;
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    goto loc_f069;
loc_f064: // 01ed:d194
    push(ax);
    sub_f166();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_f069: // 01ed:d199
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_f07c() // 01ed:d1ac
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryAGet(ss, bp + 4);
    push(ds);
    dx = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2); /*ggg2*/;
    interrupt(0x21);
    ds = pop();
    bp = pop();
    sp += 2;
}
void sub_f08d() // 01ed:d1bd
{
    sp -= 2;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(es);
    push(ds);
    push(si);
    push(di);
    push(bp);
    bp = 0x14f2;
    ds = bp;
    bp = sp;
    memoryASet16(ds, 0xac44, sp);
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp));
    push(memoryAGet16(ss, bp + 16));
    ax = memoryAGet16(ss, bp + 2);
    ax &= 0x00ff;
    push(ax);
    callIndirect(cs, memoryAGet16(ds, 0xac42)); // 01ed:d1e1;
    sp += 0x0008;
    memoryASet16(ss, bp + 16, ax);
    bp = pop();
    di = pop();
    si = pop();
    ds = pop();
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    stop("iret");
}
void sub_f0c5() // 01ed:d1f5
{
    sp -= 2;
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xac42, ax);
    push(cs);
    ax = 0xd1bd;
    push(ax);
    ax = 0x0024;
    push(ax);
    sub_f07c();
    sp += 0x0006;
    bp = pop();
    sp += 2;
}
void sub_f134() // 01ed:d264
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 4);
    al = in8(dx);
    ah = 0;
    bp = pop();
    sp += 2;
}
void sub_f13f() // 01ed:d26f
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x44;
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    interrupt(0x21);
    if (flags.carry)
        goto loc_f160;
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_f15e;
    ax = dx;
    goto loc_f164;
loc_f15e: // 01ed:d28e
    goto loc_f164;
loc_f160: // 01ed:d290
    push(ax);
    sub_f166();
loc_f164: // 01ed:d294
    bp = pop();
    sp += 2;
}
void sub_f166() // 01ed:d296 +stackDrop2
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_f186;
    if ((short)si <= (short)0x0058)
        goto loc_f179;
loc_f176: // 01ed:d2a6
    si = 0x0057;
loc_f179: // 01ed:d2a9
    memoryASet16(ds, 0x5566, si);
    al = memoryAGet(ds, si + 21864);
    cbw();
    si = ax;
    goto loc_f197;
loc_f186: // 01ed:d2b6
    ax = si;
    ax = -ax;
    si = ax;
    if ((short)ax > (short)0x0023)
        goto loc_f176;
    memoryASet16(ds, 0x5566, 0xffff);
loc_f197: // 01ed:d2c7
    memoryASet16(ds, 0x0092, si);
    ax = 0xffff;
    si = pop();
    bp = pop();
    sp += 2;
    sp += 2;
}
void sub_f1a3() // 01ed:d2d3
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
void sub_f1b4() // 01ed:d2e4
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 21784, memoryAGet16(ds, bx + 21784) & 0xfdff);
    ah = 0x42;
    al = memoryAGet(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_f1d6;
    goto loc_f1db;
loc_f1d6: // 01ed:d306
    push(ax);
    sub_f166();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_f1db: // 01ed:d30b
    bp = pop();
    sp += 2;
}
void sub_f1dd() // 01ed:d30d +stackDrop12
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0022;
    push(si);
    push(di);
    push(es);
    di = memoryAGet16(ss, bp + 10);
    push(ds);
    es = pop();
    bx = memoryAGet16(ss, bp + 8);
    if (bx > 0x0024)
        goto loc_f24b;
    if (bl < 0x02)
        goto loc_f24b;
    ax = memoryAGet16(ss, bp + 12);
    cx = memoryAGet16(ss, bp + 14);
    if ((short)cx >= 0)
        goto loc_f213;
    if (memoryAGet(ss, bp + 6) == 0x00)
        goto loc_f213;
    memoryASet(ds, di, 0x2d);
    di++;
    cx = -cx;
    ax = -ax;
    cx = cx - 0x0000 - flags.carry;
loc_f213: // 01ed:d343
    si = bp - 34;
    if (cx==0)
        goto loc_f227;
loc_f218: // 01ed:d348
    tx = cx; cx = ax; ax = tx;
    dx = 0;
    div16(bx);
    tx = cx; cx = ax; ax = tx;
    div16(bx);
    memoryASet(ds, si, dl);
    si++;
    if (cx==0)
        goto loc_f22e;
    goto loc_f218;
loc_f227: // 01ed:d357
    dx = 0;
    div16(bx);
    memoryASet(ds, si, dl);
    si++;
loc_f22e: // 01ed:d35e
    if (ax)
        goto loc_f227;
    cx = bp - 34;
    cx = -cx;
    cx += si;
    flags.direction = 0;
loc_f23a: // 01ed:d36a
    si--;
    al = memoryAGet(ds, si);
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_f245;
    al += 0x3a;
    goto loc_f248;
loc_f245: // 01ed:d375
    al += memoryAGet(ss, bp + 4);
loc_f248: // 01ed:d378
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_f23a;
loc_f24b: // 01ed:d37b
    al = 0x00;
    stosb<ES_DI>(al);
    es = pop();
    ax = memoryAGet16(ss, bp + 10);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
    sp += 12;
}
void sub_f25a() // 01ed:d38a
{
    sp -= 2;
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 8) != 0x000a)
        goto loc_f269;
    ax = memoryAGet16(ss, bp + 4);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_f26e;
loc_f269: // 01ed:d399
    ax = memoryAGet16(ss, bp + 4);
    dx = 0;
loc_f26e: // 01ed:d39e
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 8));
    al = 0x01;
    push(ax);
    al = 0x61;
    push(ax);
    sub_f1dd();
    bp = pop();
    sp += 2;
}
void sub_f29b() // 01ed:d3cb
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 10));
    if (memoryAGet16(ss, bp + 10) != 0x000a)
        goto loc_f2b5;
    ax = 0x0001;
    goto loc_f2b7;
loc_f2b5: // 01ed:d3e5
    ax = 0;
loc_f2b7: // 01ed:d3e7
    push(ax);
    al = 0x61;
    push(ax);
    sub_f1dd();
    bp = pop();
    sp += 2;
}
void sub_f2c0() // 01ed:d3f0
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = ds;
    es = ax;
    di = memoryAGet16(ss, bp + 4);
    si = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 8);
    flags.carry = cx & 1;
    cx >>= 1;
    flags.direction = 0;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    if (!flags.carry)
        goto loc_f2da;
    movsb<ES_DI, DS_SI>();
loc_f2da: // 01ed:d40a
    ax = memoryAGet16(ss, bp + 4);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_f2e1() // 01ed:d411
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(di);
    ax = ds;
    es = ax;
    di = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 6);
    al = memoryAGet(ss, bp + 8);
    ah = al;
    flags.direction = 0;
    if (!(di & 0x0001))
        goto loc_f2ff;
    if (cx==0)
        goto loc_f306;
    stosb<ES_DI>(al);
    cx--;
loc_f2ff: // 01ed:d42f
    flags.carry = cx & 1;
    cx >>= 1;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    if (!flags.carry)
        goto loc_f306;
    stosb<ES_DI>(al);
loc_f306: // 01ed:d436
    di = pop();
    bp = pop();
    sp += 2;
}
void sub_f309() // 01ed:d439
{
    sp -= 2;
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 6);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 4));
    sub_f2e1();
    sp += 0x0006;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    sp += 2;
}
void sub_f321() // 01ed:d451
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    flags.direction = 0;
    cx = memoryAGet16(ss, bp + 12);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 8);
    si = memoryAGet16(ss, bp + 6);
    push(ds);
    ds = memoryAGet16(ss, bp + 4);
    flags.carry = cx & 1;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    if (!flags.carry)
        goto loc_f33e;
    movsb<ES_DI, DS_SI>();
loc_f33e: // 01ed:d46e
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_f343() // 01ed:d473 +stackDrop4
{
    sp -= 2;
    push(bp);
    bp = sp;
    cx = memoryAGet16(ss, bp + 4);
    ah = 0x3c;
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_f354;
    goto loc_f358;
loc_f354: // 01ed:d484
    push(ax);
    sub_f166();
loc_f358: // 01ed:d488
    bp = pop();
    sp += 2;
    sp += 4;
}
void sub_f35c() // 01ed:d48c +stackDrop2
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
void sub_f36e() // 01ed:d49e
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 6);
    if (si & 0xc000)
        goto loc_f38b;
    ax = memoryAGet16(ds, 0x5540);
    ax &= 0xc000;
    dx = si;
    dx |= ax;
    si = dx;
loc_f38b: // 01ed:d4bb
    if (!(si & 0x0100))
        goto loc_f40b;
    ax = memoryAGet16(ds, 0x5542);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) & ax);
    ax = memoryAGet16(ss, bp + 8);
    if (ax & 0x0180)
        goto loc_f3a6;
    ax = 0x0001;
    push(ax);
    sub_f166();
loc_f3a6: // 01ed:d4d6
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_ee3d();
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0xffff)
        goto loc_f3e2;
    if (!(memoryAGet16(ss, bp + 8) & 0x0080))
        goto loc_f3c4;
    ax = 0;
    goto loc_f3c7;
loc_f3c4: // 01ed:d4f4
    ax = 0x0001;
loc_f3c7: // 01ed:d4f7
    memoryASet16(ss, bp - 2, ax);
    if (!(si & 0x00f0))
        goto loc_f3f9;
    push(memoryAGet16(ss, bp + 4));
    ax = 0;
    push(ax);
    sub_f343();
    di = ax;
    if ((short)ax >= 0)
        goto loc_f3f2;
    goto loc_f493;
loc_f3e2: // 01ed:d512
    if (!(si & 0x0400))
        goto loc_f40b;
    ax = 0x0050;
    push(ax);
    sub_f166();
    goto loc_f495;
loc_f3f2: // 01ed:d522
    push(di);
    sub_ee58();
    cx = pop();
    goto loc_f410;
loc_f3f9: // 01ed:d529
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp - 2));
    sub_f343();
    di = ax;
    if ((short)ax >= 0)
        goto loc_f472;
    goto loc_f493;
loc_f40b: // 01ed:d53b
    memoryASet16(ss, bp - 2, 0x0000);
loc_f410: // 01ed:d540
    push(si);
    push(memoryAGet16(ss, bp + 4));
    sub_f49b();
    cx = pop();
    cx = pop();
    di = ax;
    if ((short)ax < 0)
        goto loc_f472;
    ax = 0;
    push(ax);
    push(di);
    sub_f13f();
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    if (!(ax & 0x0080))
        goto loc_f44e;
    si |= 0x2000;
    if (!(si & 0x8000))
        goto loc_f458;
    ax &= 0x00ff;
    ax |= 0x0020;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(di);
    sub_f13f();
    sp += 0x0006;
    goto loc_f458;
loc_f44e: // 01ed:d57e
    if (!(si & 0x0200))
        goto loc_f458;
    push(di);
    sub_f35c();
loc_f458: // 01ed:d588
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_f472;
    if (!(si & 0x00f0))
        goto loc_f472;
    ax = 0x0001;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_ee3d();
    sp += 0x0006;
loc_f472: // 01ed:d5a2
    if ((short)di < 0)
        goto loc_f493;
    if (!(si & 0x0300))
        goto loc_f481;
    ax = 0x1000;
    goto loc_f483;
loc_f481: // 01ed:d5b1
    ax = 0;
loc_f483: // 01ed:d5b3
    dx = si;
    dx &= 0xf8ff;
    dx |= ax;
    bx = di;
    bx <<= 1;
    memoryASet16(ds, bx + 21784, dx);
loc_f493: // 01ed:d5c3
    ax = di;
loc_f495: // 01ed:d5c5
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_f49b() // 01ed:d5cb
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = 0x01;
    cx = memoryAGet16(ss, bp + 6);
    if (cx & 0x0002)
        goto loc_f4b5;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_f4b5;
    al = 0x00;
loc_f4b5: // 01ed:d5e5
    dx = memoryAGet16(ss, bp + 4);
    cl = 0xf0;
    cl &= memoryAGet(ss, bp + 6);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    if (flags.carry)
        goto loc_f4df;
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryAGet16(ss, bp + 6);
    ax &= 0xf8ff;
    ax |= 0x8000;
    memoryASet16(ds, bx + 21784, ax);
    ax = memoryAGet16(ss, bp - 2);
    goto loc_f4e3;
loc_f4df: // 01ed:d60f
    push(ax);
    sub_f166();
loc_f4e3: // 01ed:d613
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_f4e7() // 01ed:d617
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, bp + 6);
    out16(dx, ax);
    bp = pop();
    sp += 2;
}
void sub_f4f3() // 01ed:d623
{
    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 4);
    al = memoryAGet(ss, bp + 6);
    out8(dx, al);
    bp = pop();
    sp += 2;
}
void sub_f4ff() // 01ed:d62f
{
    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    if (ax < 0x0002)
        goto loc_f51d;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 21784) & 0x0200))
        goto loc_f522;
loc_f51d: // 01ed:d64d
    ax = 0;
    goto loc_f5ae;
loc_f522: // 01ed:d652
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_f5b4();
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    ax++;
    if (ax < 0x0002)
        goto loc_f547;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 21784) & 0x8000))
        goto loc_f54c;
loc_f547: // 01ed:d677
    ax = memoryAGet16(ss, bp - 2);
    goto loc_f5ae;
loc_f54c: // 01ed:d67c
    cx = memoryAGet16(ss, bp - 2);
    si = memoryAGet16(ss, bp + 6);
    push(ds);
    es = pop();
    di = si;
    bx = si;
    flags.direction = 0;
loc_f559: // 01ed:d689
    al = lodsb<DS_SI>();
    if (al == 0x1a)
        goto loc_f58b;
    if (al == 0x0d)
        goto loc_f567;
    stosb<ES_DI>(al);
    if (--cx)
        goto loc_f559;
    goto loc_f583;
loc_f567: // 01ed:d697
    if (--cx)
        goto loc_f559;
    push(es);
    push(bx);
    ax = 0x0001;
    push(ax);
    ax = bp - 3;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_f5b4();
    sp += 0x0006;
    bx = pop();
    es = pop();
    flags.direction = 0;
    al = memoryAGet(ss, bp - 3);
    stosb<ES_DI>(al);
loc_f583: // 01ed:d6b3
    if (di != bx)
        goto loc_f589;
    goto loc_f522;
loc_f589: // 01ed:d6b9
    goto loc_f5ab;
loc_f58b: // 01ed:d6bb
    push(bx);
    ax = 0x0001;
    push(ax);
    cx = -cx;
    ax = -flags.carry;
    push(ax);
    push(cx);
    push(memoryAGet16(ss, bp + 4));
    sub_f1b4();
    sp += 0x0008;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 21784, memoryAGet16(ds, bx + 21784) | 0x0200);
    bx = pop();
loc_f5ab: // 01ed:d6db
    di -= bx;
    tx = di; di = ax; ax = tx;
loc_f5ae: // 01ed:d6de
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
}
void sub_f5b4() // 01ed:d6e4
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x3f;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_f5c8;
    goto loc_f5cc;
loc_f5c8: // 01ed:d6f8
    push(ax);
    sub_f166();
loc_f5cc: // 01ed:d6fc
    bp = pop();
    sp += 2;
}
void sub_f5ce() // 01ed:d6fe
{
    sp -= 2;
    push(bp);
    bp = sp;
    ah = 0x4a;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_f5e2;
    ax = 0xffff;
    goto loc_f5e8;
loc_f5e2: // 01ed:d712
    push(bx);
    push(ax);
    sub_f166();
    ax = pop();
loc_f5e8: // 01ed:d718
    bp = pop();
    sp += 2;
}
void sub_f5ea() // 01ed:d71a
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    flags.direction = 0;
    di = memoryAGet16(ss, bp + 4);
    push(ds);
    es = pop();
    dx = di;
    al = 0;
    cx = 0xffff;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    si = di + 65535;
    di = memoryAGet16(ss, bp + 6);
    cx = 0xffff;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    cx = ~cx;
    di -= cx;
    tx = di; di = si; si = tx;
    if (!(si & 0x0001))
        goto loc_f617;
    movsb<ES_DI, DS_SI>();
    cx--;
loc_f617: // 01ed:d747
    flags.carry = cx & 1;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    if (!flags.carry)
        goto loc_f61e;
    movsb<ES_DI, DS_SI>();
loc_f61e: // 01ed:d74e
    tx = dx; dx = ax; ax = tx;
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_f623() // 01ed:d753
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = ds;
    es = ax;
    flags.direction = 0;
    di = memoryAGet16(ss, bp + 6);
    si = di;
    al = 0;
    cx = 0xffff;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    cx = ~cx;
    di = memoryAGet16(ss, bp + 4);
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = memoryAGet16(ss, bp + 4);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_f647() // 01ed:d777
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(di);
    ax = ds;
    es = ax;
    di = memoryAGet16(ss, bp + 4);
    ax = 0;
    flags.direction = 0;
    cx = 0xffff;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    tx = cx; cx = ax; ax = tx;
    ax = ~ax;
    ax--;
    di = pop();
    bp = pop();
    sp += 2;
}
void sub_f679() // 01ed:d7a9 +stackDrop8
{
    bool temp_cond0;
    bool temp_cond1;

    sp -= 2;
    push(bp);
    bp = sp;
    sp -= 0x0096;
    push(si);
    push(di);
    memoryASet16(ss, bp - 18, 0x0000);
    memoryASet16(ss, bp - 20, 0x0050);
    memoryASet16(ss, bp - 22, 0x0000);
    goto loc_f6d9;
  // gap 70 bytes
loc_f6d9: // 01ed:d809
    push(es);
    flags.direction = 0;
    di = bp - 150;
    memoryASet16(ss, bp - 4, di);
    di = memoryAGet16(ss, bp - 4);
loc_f6e5: // 01ed:d815
    si = memoryAGet16(ss, bp + 6);
loc_f6e8: // 01ed:d818
    al = lodsb<DS_SI>();
    if (!al)
        goto loc_f6ff;
    if (al == 0x25)
        goto loc_f702;
loc_f6f1: // 01ed:d821
    memoryASet(ss, di, al);
    di++;
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) - 1);
    if ((char)memoryAGet(ss, bp - 20) > 0)
        goto loc_f6e8;
    sub_f6a9();
    goto loc_f6e8;
loc_f6ff: // 01ed:d82f
    goto loc_faed;
loc_f702: // 01ed:d832
    memoryASet16(ss, bp - 16, si);
    al = lodsb<DS_SI>();
    if (al == 0x25)
        goto loc_f6f1;
    memoryASet16(ss, bp - 4, di);
    cx = 0;
    memoryASet16(ss, bp - 14, cx);
    memoryASet16(ss, bp - 2, cx);
    memoryASet(ss, bp - 11, cl);
    memoryASet16(ss, bp - 8, 0xffff);
    memoryASet16(ss, bp - 10, 0xffff);
    goto loc_f725;
loc_f724: // 01ed:d854
    al = lodsb<DS_SI>();
loc_f725: // 01ed:d855
    ah = 0;
    dx = ax;
    bx = ax;
    bl -= 0x20;
    if (bl >= 0x60)
        goto loc_f746;
    bl = memoryAGet(ds, bx + 21961);
    if (bx <= 0x0017)
        goto loc_f73f;
    goto loc_fadd;
loc_f73f: // 01ed:d86f
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_f75f;
        case 2: goto loc_f749;
        case 4: goto loc_f794;
        case 6: goto loc_f754;
        case 8: goto loc_f7c2;
        case 10: goto loc_f7cc;
        case 12: goto loc_f80a;
        case 14: goto loc_f811;
        case 16: goto loc_f816;
        case 18: goto loc_f77d;
        case 20: goto loc_f83f;
        default:
            stop();
    }
loc_f746: // 01ed:d876
    goto loc_fadd;
loc_f749: // 01ed:d879
    if (ch > 0x00)
        goto loc_f746;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0001);
    goto loc_f724;
loc_f754: // 01ed:d884
    if (ch > 0x00)
        goto loc_f746;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0002);
    goto loc_f724;
loc_f75f: // 01ed:d88f
    if (ch > 0x00)
        goto loc_f746;
    if (memoryAGet(ss, bp - 11) == 0x2b)
        goto loc_f76d;
    memoryASet(ss, bp - 11, dl);
loc_f76d: // 01ed:d89d
    goto loc_f724;
  // gap 10 bytes
loc_f779: // 01ed:d8a9
    ch = 0x05;
    goto loc_f724;
loc_f77d: // 01ed:d8ad
    if (ch > 0x00)
        goto loc_f7cc;
    if (memoryAGet16(ss, bp - 2) & 0x0002)
        goto loc_f7b2;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0008);
    ch = 0x01;
    goto loc_f724;
loc_f791: // 01ed:d8c1
    goto loc_fadd;
loc_f794: // 01ed:d8c4
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 0x0002);
    if (ch >= 0x02)
        goto loc_f7b5;
    if ((short)ax >= 0)
        goto loc_f7ad;
    ax = -ax;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0002);
loc_f7ad: // 01ed:d8dd
    memoryASet16(ss, bp - 8, ax);
    ch = 0x03;
loc_f7b2: // 01ed:d8e2
    goto loc_f724;
loc_f7b5: // 01ed:d8e5
    if (ch != 0x04)
        goto loc_f791;
    memoryASet16(ss, bp - 10, ax);
    ch++;
    goto loc_f724;
loc_f7c2: // 01ed:d8f2
    if (ch >= 0x04)
        goto loc_f791;
    ch = 0x04;
    goto loc_f724;
loc_f7cc: // 01ed:d8fc
    tx = dx; dx = ax; ax = tx;
    al -= 0x30;
    cbw();
    if (ch > 0x02)
        goto loc_f7ee;
    ch = 0x02;
    tx = memoryAGet16(ss, bp - 8); memoryASet16(ss, bp - 8, ax); ax = tx;
    if ((short)ax < 0)
        goto loc_f7b2;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + ax);
    goto loc_f724;
loc_f7ee: // 01ed:d91e
    if (ch != 0x04)
        goto loc_f791;
    tx = memoryAGet16(ss, bp - 10); memoryASet16(ss, bp - 10, ax); ax = tx;
    if ((short)ax < 0)
        goto loc_f7b2;
    ax <<= 1;
    dx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += dx;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + ax);
    goto loc_f724;
loc_f80a: // 01ed:d93a
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0010);
    goto loc_f779;
loc_f811: // 01ed:d941
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0100);
loc_f816: // 01ed:d946
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) & 0xffef);
    goto loc_f779;
  // gap 34 bytes
loc_f83f: // 01ed:d96f
    bh = 0x0a;
    memoryASet(ss, bp - 6, 0x01);
    memoryASet(ss, bp - 5, dl);
    di = memoryAGet16(ss, bp + 4);
    ax = memoryAGet16(ss, di);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    di++;
    di++;
    memoryASet16(ss, bp + 6, si);
    if (!(memoryAGet16(ss, bp - 2) & 0x0010))
        goto loc_f860;
    dx = memoryAGet16(ss, di);
    di++;
    di++;
loc_f860: // 01ed:d990
    memoryASet16(ss, bp + 4, di);
    di = bp - 69;
    if (ax)
        goto loc_f899;
    if (dx)
        goto loc_f899;
    if (memoryAGet16(ss, bp - 10) != 0x0000)
        goto loc_f89d;
    di = memoryAGet16(ss, bp - 4);
    cx = memoryAGet16(ss, bp - 8);
    if (cx==0)
        goto loc_f896;
    if (cx == 0xffff)
        goto loc_f896;
    ax = memoryAGet16(ss, bp - 2);
    ax &= 0x0008;
    if (!ax)
        goto loc_f88d;
    dl = 0x30;
    goto loc_f88f;
loc_f88d: // 01ed:d9bd
    dl = 0x20;
loc_f88f: // 01ed:d9bf
    al = dl;
    sub_f6a0();
    if (--cx)
        goto loc_f88f;
loc_f896: // 01ed:d9c6
    goto loc_f6e5;
loc_f899: // 01ed:d9c9
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0004);
loc_f89d: // 01ed:d9cd
    push(dx);
    push(ax);
    push(di);
    al = bh;
    cbw();
    push(ax);
    al = memoryAGet(ss, bp - 6);
    push(ax);
    push(bx);
    sub_f1dd();
    push(ss);
    es = pop();
    dx = memoryAGet16(ss, bp - 10);
    if ((short)dx > 0)
        goto loc_f8b8;
    goto loc_f9a9;
loc_f8b8: // 01ed:d9e8
    goto loc_f9b7;
  // gap 238 bytes
loc_f9a9: // 01ed:dad9
    if (!(memoryAGet16(ss, bp - 2) & 0x0008))
        goto loc_f9c8;
    dx = memoryAGet16(ss, bp - 8);
    if ((short)dx <= 0)
        goto loc_f9c8;
loc_f9b7: // 01ed:dae7
    sub_f693();
    if (memoryAGet(es, di) != 0x2d)
        goto loc_f9c1;
    cx--;
loc_f9c1: // 01ed:daf1
    temp_cond0 = (short)dx - (short)cx <= 0;
    dx -= cx;
    if (temp_cond0)
        goto loc_f9c8;
    memoryASet16(ss, bp - 14, dx);
loc_f9c8: // 01ed:daf8
    al = memoryAGet(ss, bp - 11);
    if (!al)
        goto loc_f9e1;
    if (memoryAGet(es, di) == 0x2d)
        goto loc_f9e1;
    flags.carry = memoryAGet16(ss, bp - 14) < 0x0001;
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) - 0x0001);
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) + (0x0000 + flags.carry));
    di--;
    memoryASet(es, di, al);
loc_f9e1: // 01ed:db11
    sub_f693();
    si = di;
    di = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp - 8);
    ax = 0x0005;
    ax &= memoryAGet16(ss, bp - 2);
    if (ax != 0x0005)
        goto loc_fa0a;
    ah = memoryAGet(ss, bp - 5);
    if (ah != 0x6f)
        goto loc_fa0c;
    if ((short)memoryAGet16(ss, bp - 14) > (short)0x0000)
        goto loc_fa0a;
    memoryASet16(ss, bp - 14, 0x0001);
loc_fa0a: // 01ed:db3a
    goto loc_fa27;
loc_fa0c: // 01ed:db3c
    if (ah == 0x78)
        goto loc_fa16;
    if (ah != 0x58)
        goto loc_fa27;
loc_fa16: // 01ed:db46
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) | 0x0040);
    bx--;
    bx--;
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) - 0x0002);
    temp_cond1 = (short)memoryAGet16(ss, bp - 14) >= 0;
    if (temp_cond1)
        goto loc_fa27;
    memoryASet16(ss, bp - 14, 0x0000);
loc_fa27: // 01ed:db57
    cx += memoryAGet16(ss, bp - 14);
    if (memoryAGet16(ss, bp - 2) & 0x0002)
        goto loc_fa3d;
    goto loc_fa39;
loc_fa33: // 01ed:db63
    al = 0x20;
    sub_f6a0();
    bx--;
loc_fa39: // 01ed:db69
    if ((short)bx > (short)cx)
        goto loc_fa33;
loc_fa3d: // 01ed:db6d
    if (!(memoryAGet16(ss, bp - 2) & 0x0040))
        goto loc_fa4f;
    al = 0x30;
    sub_f6a0();
    al = memoryAGet(ss, bp - 5);
    sub_f6a0();
loc_fa4f: // 01ed:db7f
    dx = memoryAGet16(ss, bp - 14);
    if ((short)dx <= 0)
        goto loc_fa7d;
    cx -= dx;
    bx -= dx;
    al = memoryAGet(es, si);
    if (al == 0x2d)
        goto loc_fa69;
    if (al == 0x20)
        goto loc_fa69;
    if (al != 0x2b)
        goto loc_fa70;
loc_fa69: // 01ed:db99
    al = lodsb<ES_SI>();
    sub_f6a0();
    cx--;
    bx--;
loc_fa70: // 01ed:dba0
    tx = dx; dx = cx; cx = tx;
    if (cx==0)
        goto loc_fa7b;
loc_fa74: // 01ed:dba4
    al = 0x30;
    sub_f6a0();
    if (--cx)
        goto loc_fa74;
loc_fa7b: // 01ed:dbab
    tx = dx; dx = cx; cx = tx;
loc_fa7d: // 01ed:dbad
    if (cx==0)
        goto loc_fa91;
    bx -= cx;
loc_fa81: // 01ed:dbb1
    al = lodsb<ES_SI>();
    memoryASet(ss, di, al);
    di++;
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) - 1);
    if ((char)memoryAGet(ss, bp - 20) > 0)
        goto loc_fa8f;
    sub_f6a9();
loc_fa8f: // 01ed:dbbf
    if (--cx)
        goto loc_fa81;
loc_fa91: // 01ed:dbc1
    if ((short)bx <= 0)
        goto loc_fa9e;
    cx = bx;
loc_fa97: // 01ed:dbc7
    al = 0x20;
    sub_f6a0();
    if (--cx)
        goto loc_fa97;
loc_fa9e: // 01ed:dbce
    goto loc_f6e5;
  // gap 60 bytes
loc_fadd: // 01ed:dc0d
    si = memoryAGet16(ss, bp - 16);
    di = memoryAGet16(ss, bp - 4);
    al = 0x25;
loc_fae5: // 01ed:dc15
    sub_f6a0();
    al = lodsb<DS_SI>();
    if (al)
        goto loc_fae5;
loc_faed: // 01ed:dc1d
    if ((char)memoryAGet(ss, bp - 20) >= (char)0x50)
        goto loc_faf6;
    sub_f6a9();
loc_faf6: // 01ed:dc26
    es = pop();
    if (memoryAGet16(ss, bp - 22) == 0x0000)
        goto loc_fb02;
    ax = 0xffff;
    goto loc_fb05;
loc_fb02: // 01ed:dc32
    ax = memoryAGet16(ss, bp - 18);
loc_fb05: // 01ed:dc35
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    sp += 2;
    sp += 8;
}
void sub_f693() // 01ed:d7c3
{
    push(di);
    cx = 0xffff;
    al = 0;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    cx = ~cx;
    cx--;
    di = pop();
}
void sub_f6a0() // 01ed:d7d0
{
    memoryASet(ss, di, al);
    di++;
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) - 1);
    if ((char)memoryAGet(ss, bp - 20) <= 0 )
        goto loc_f6d8;
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = bp - 150;
    di -= ax;
    ax = bp - 150;
    push(ax);
    push(di);
    push(memoryAGet16(ss, bp + 8));
    callIndirect(cs, memoryAGet16(ss, bp + 10)); // 01ed:d7ec;
    if (ax)
        goto loc_f6c8;
    memoryASet16(ss, bp - 22, 0x0001);
loc_f6c8: // 01ed:d7f8
    memoryASet16(ss, bp - 20, 0x0050);
    memoryASet16(ss, bp - 18, memoryAGet16(ss, bp - 18) + di);
    di = bp - 150;
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
loc_f6d8: // 01ed:d808
    return;
}
void sub_f6a9() // 01ed:d7d9
{
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = bp - 150;
    di -= ax;
    ax = bp - 150;
    push(ax);
    push(di);
    push(memoryAGet16(ss, bp + 8));
    callIndirect(cs, memoryAGet16(ss, bp + 10)); // 01ed:d7ec;
    if (ax)
        goto loc_f6c8;
    memoryASet16(ss, bp - 22, 0x0001);
loc_f6c8: // 01ed:d7f8
    memoryASet16(ss, bp - 20, 0x0050);
    memoryASet16(ss, bp - 18, memoryAGet16(ss, bp - 18) + di);
    di = bp - 150;
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    stop("stack_unbalanced");
}
void sub_fb3d() // 01ed:dc6d
{
    sp -= 2;
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 21784) & 0x0800))
        goto loc_fb60;
    ax = 0x0002;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 4));
    sub_f1b4();
    sp += 0x0008;
loc_fb60: // 01ed:dc90
    ah = 0x40;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_fb7e;
    push(ax);
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 21784, memoryAGet16(ds, bx + 21784) | 0x1000);
    ax = pop();
    goto loc_fb82;
loc_fb7e: // 01ed:dcae
    push(ax);
    sub_f166();
loc_fb82: // 01ed:dcb2
    bp = pop();
    sp += 2;
}
void sub_fb9c() // 01ed:dccc
{
    if (dx == memoryAGet16(cs, 0xdcc0))
        goto loc_fbda;
    ds = dx;
    ds = memoryAGet16(ds, 0x0002);
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_fbb7;
    memoryASet16(cs, 0xdcc2, ds);
    goto loc_fbef;
loc_fbb7: // 01ed:dce7
    ax = ds;
    if (ax == memoryAGet16(cs, 0xdcc0))
        goto loc_fbd5;
    ax = memoryAGet16(ds, 0x0008);
    memoryASet16(cs, 0xdcc2, ax);
    push(ds);
    ax = 0;
    push(ax);
    sub_fc6f();
    ds = memoryAGet16(cs, 0xdcc6);
    goto loc_fbf8;
loc_fbd5: // 01ed:dd05
    dx = memoryAGet16(cs, 0xdcc0);
loc_fbda: // 01ed:dd0a
    memoryASet16(cs, 0xdcc0, 0x0000);
    memoryASet16(cs, 0xdcc2, 0x0000);
    memoryASet16(cs, 0xdcc4, 0x0000);
loc_fbef: // 01ed:dd1f
    ds = memoryAGet16(cs, 0xdcc6);
    push(dx);
    ax = 0;
    push(ax);
loc_fbf8: // 01ed:dd28
    sub_e548();
    ax = pop();
    ax = pop();
}
void sub_fbfe() // 01ed:dd2e
{
    ds = dx;
    push(ds);
    es = memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, 0x0000);
    memoryASet16(ds, 0x0008, es);
    if (dx == memoryAGet16(cs, 0xdcc0))
        goto loc_fc44;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_fc44;
    ax = memoryAGet16(ds, 0x0000);
    bx = pop();
    push(es);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    cx = es;
    dx += ax;
    es = dx;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_fc3d;
    memoryASet16(es, 0x0008, cx);
    goto loc_fc47;
loc_fc3d: // 01ed:dd6d
    memoryASet16(es, 0x0002, cx);
    goto loc_fc47;
loc_fc44: // 01ed:dd74
    sub_fc98();
loc_fc47: // 01ed:dd77
    es = pop();
    ax = es;
    ax += memoryAGet16(es, 0x0000);
    ds = ax;
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_fc59;
    return;
loc_fc59: // 01ed:dd89
    ax = memoryAGet16(ds, 0x0000);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    ax = es;
    bx = ds;
    bx += memoryAGet16(ds, 0x0000);
    es = bx;
    memoryASet16(es, 0x0002, ax);
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_fc90;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xdcc4, ds);
    ds = bx;
    return;
loc_fc90: // 01ed:ddc0
    memoryASet16(cs, 0xdcc4, 0x0000);
}
void sub_fc6f() // 01ed:dd9f
{
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_fc90;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xdcc4, ds);
    ds = bx;
    return;
loc_fc90: // 01ed:ddc0
    memoryASet16(cs, 0xdcc4, 0x0000);
}
void sub_fc98() // 01ed:ddc8
{
    ax = memoryAGet16(cs, 0xdcc4);
    if (!ax)
        goto loc_fcc0;
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
loc_fcc0: // 01ed:ddf0
    memoryASet16(cs, 0xdcc4, ds);
    memoryASet16(ds, 0x0004, ds);
    memoryASet16(ds, 0x0006, ds);
}
void sub_fcce() // 01ed:ddfe
{
    sp -= 2;
    push(bp);
    bp = sp;
    push(si);
    push(di);
    memoryASet16(cs, 0xdcc6, ds);
    dx = memoryAGet16(ss, bp + 6);
    if (!dx)
        goto loc_fcee;
    if (dx != memoryAGet16(cs, 0xdcc2))
        goto loc_fceb;
    sub_fb9c();
    goto loc_fcee;
loc_fceb: // 01ed:de1b
    sub_fbfe();
loc_fcee: // 01ed:de1e
    ds = memoryAGet16(cs, 0xdcc6);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_fcf7() // 01ed:de27
{
    push(ax);
    ds = memoryAGet16(cs, 0xdcc6);
    ax = 0;
    push(ax);
    push(ax);
    sub_e587();
    bx = pop();
    bx = pop();
    ax &= 0x000f;
    if (!ax)
        goto loc_fd1e;
    dx = 0x0010;
    dx -= ax;
    ax = 0;
    ds = memoryAGet16(cs, 0xdcc6);
    push(ax);
    push(dx);
    sub_e587();
    bx = pop();
    bx = pop();
loc_fd1e: // 01ed:de4e
    ax = pop();
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xdcc6);
    push(bx);
    push(ax);
    sub_e587();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_fd54;
    memoryASet16(cs, 0xdcc0, dx);
    memoryASet16(cs, 0xdcc2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, dx);
    ax = 0x0004;
    return;
loc_fd54: // 01ed:de84
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_fd58() // 01ed:de88
{
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xdcc6);
    push(bx);
    push(ax);
    sub_e587();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_fd8d;
    cx = memoryAGet16(cs, 0xdcc2);
    memoryASet16(cs, 0xdcc2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, cx);
    ax = 0x0004;
    return;
loc_fd8d: // 01ed:debd
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_fd91() // 01ed:dec1
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
void sub_fdb4() // 01ed:dee4
{
    bool temp_cf;

    sp -= 2;
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    push(si);
    push(di);
    memoryASet16(cs, 0xdcc6, ds);
    cx = ax;
    cx |= dx;
    if (!cx)
        goto loc_fe28;
    flags.carry = (ax + 0x0013) >= 0x10000;
    ax += 0x0013;
    temp_cf = (dx + 0x0000 + flags.carry) >= 0x10000;
    dx += 0x0000 + flags.carry;
    flags.carry = temp_cf;
    if (flags.carry)
        goto loc_fe13;
    if (dx & 0xfff0)
        goto loc_fe13;
    cl = 0x04;
    ax >>= cl;
    dx <<= cl;
    ah |= dl;
    dx = memoryAGet16(cs, 0xdcc0);
    if (!dx)
        goto loc_fe09;
    dx = memoryAGet16(cs, 0xdcc4);
    if (!dx)
        goto loc_fe04;
    bx = dx;
loc_fdf4: // 01ed:df24
    ds = dx;
    if (memoryAGet16(ds, 0x0000) >= ax)
        goto loc_fe18;
    dx = memoryAGet16(ds, 0x0006);
    if (dx != bx)
        goto loc_fdf4;
loc_fe04: // 01ed:df34
    sub_fd58();
    goto loc_fe28;
loc_fe09: // 01ed:df39
    sub_fcf7();
    goto loc_fe28;
loc_fe0e: // 01ed:df3e
    sub_fd91();
    goto loc_fe28;
loc_fe13: // 01ed:df43
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_fe28;
loc_fe18: // 01ed:df48
    if (memoryAGet16(ds, 0x0000) > ax)
        goto loc_fe0e;
    sub_fc6f();
    bx = memoryAGet16(ds, 0x0008);
    memoryASet16(ds, 0x0002, bx);
    ax = 0x0004;
loc_fe28: // 01ed:df58
    ds = memoryAGet16(cs, 0xdcc6);
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
}
void sub_ff73() // 01ed:e0a3 +stackDrop10 +nearAsFar
{
    sp -= 2;
    cx = pop();
    push(cs);
    push(cx);
    cx = 0;
    goto loc_ff90;
  // gap 22 bytes
loc_ff90: // 01ed:e0c0
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
        goto loc_ffaf;
    if (!dx)
        goto loc_10014;
    if (!bx)
        goto loc_10014;
loc_ffaf: // 01ed:e0df
    if (di & 0x0001)
        goto loc_ffd1;
    if ((short)dx >= 0)
        goto loc_ffc3;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
    di |= 0x000c;
loc_ffc3: // 01ed:e0f3
    if ((short)cx >= 0)
        goto loc_ffd1;
    cx = -cx;
    bx = -bx;
    cx = cx - 0x0000 - flags.carry;
    di ^= 0x0004;
loc_ffd1: // 01ed:e101
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_ffdb: // 01ed:e10b
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl16(dx, 0x0001);
    si = rcl16(si, 0x0001);
    di = rcl16(di, 0x0001);
    if (di < bp)
        goto loc_fff2;
    if (di > bp)
        goto loc_ffed;
    if (si < bx)
        goto loc_fff2;
loc_ffed: // 01ed:e11d
    flags.carry = si < bx;
    si -= bx;
    di = di - bp - flags.carry;
    ax++;
loc_fff2: // 01ed:e122
    if (--cx)
        goto loc_ffdb;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_10001;
    ax = si;
    dx = di;
    bx >>= 1;
loc_10001: // 01ed:e131
    if (!(bx & 0x0004))
        goto loc_1000e;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
loc_1000e: // 01ed:e13e
    di = pop();
    si = pop();
    bp = pop();
    stop("stack_below_retf, 10/6");
    sp += 2;
    cs = pop();
    sp += 8;
    return;
loc_10014: // 01ed:e144
    div16(bx);
    if (!(di & 0x0002))
        goto loc_1001d;
    tx = dx; dx = ax; ax = tx;
loc_1001d: // 01ed:e14d
    dx = 0;
    goto loc_1000e;
}
void sub_ff82() // 01ed:e0b2 +stackDrop8 +nearAsFar
{
    sp -= 2;
    cx = pop();
    push(cs);
    push(cx);
    cx = 0x0002;
    goto loc_ff90;
  // gap 6 bytes
loc_ff90: // 01ed:e0c0
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
        goto loc_ffaf;
    if (!dx)
        goto loc_10014;
    if (!bx)
        goto loc_10014;
loc_ffaf: // 01ed:e0df
    if (di & 0x0001)
        goto loc_ffd1;
    if ((short)dx >= 0)
        goto loc_ffc3;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
    di |= 0x000c;
loc_ffc3: // 01ed:e0f3
    if ((short)cx >= 0)
        goto loc_ffd1;
    cx = -cx;
    bx = -bx;
    cx = cx - 0x0000 - flags.carry;
    di ^= 0x0004;
loc_ffd1: // 01ed:e101
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_ffdb: // 01ed:e10b
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl16(dx, 0x0001);
    si = rcl16(si, 0x0001);
    di = rcl16(di, 0x0001);
    if (di < bp)
        goto loc_fff2;
    if (di > bp)
        goto loc_ffed;
    if (si < bx)
        goto loc_fff2;
loc_ffed: // 01ed:e11d
    flags.carry = si < bx;
    si -= bx;
    di = di - bp - flags.carry;
    ax++;
loc_fff2: // 01ed:e122
    if (--cx)
        goto loc_ffdb;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_10001;
    ax = si;
    dx = di;
    bx >>= 1;
loc_10001: // 01ed:e131
    if (!(bx & 0x0004))
        goto loc_1000e;
    dx = -dx;
    ax = -ax;
    dx = dx - 0x0000 - flags.carry;
loc_1000e: // 01ed:e13e
    di = pop();
    si = pop();
    bp = pop();
    sp += 2;
    cs = pop();
    sp += 8;
    return;
loc_10014: // 01ed:e144
    div16(bx);
    if (!(di & 0x0002))
        goto loc_1001d;
    tx = dx; dx = ax; ax = tx;
loc_1001d: // 01ed:e14d
    dx = 0;
    goto loc_1000e;
}
void sub_10021() // 01ed:e151 +nearAsFar
{
    sp -= 2;
    bx = pop();
    push(cs);
    push(bx);
    if (cl >= 0x10)
        goto loc_10039;
    bx = ax;
    ax <<= cl;
    dx <<= cl;
    cl = -cl;
    cl += 0x10;
    bx >>= cl;
    dx |= bx;
    sp += 2;
    cs = pop();
    return;
loc_10039: // 01ed:e169
    cl -= 0x10;
    tx = dx; dx = ax; ax = tx;
    ax = 0;
    dx <<= cl;
    sp += 2;
    cs = pop();
}
void sub_10042() // 01ed:e172 +nearAsFar
{
    sp -= 2;
    bx = pop();
    push(cs);
    push(bx);
    if (cl >= 0x10)
        goto loc_1005a;
    bx = dx;
    ax >>= cl;
    dx = sar16(dx, cl);
    cl = -cl;
    cl += 0x10;
    bx <<= cl;
    ax |= bx;
    sp += 2;
    cs = pop();
    return;
loc_1005a: // 01ed:e18a
    cl -= 0x10;
    tx = dx; dx = ax; ax = tx;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    ax = sar16(ax, cl);
    sp += 2;
    cs = pop();
}
void sub_10062() // 01ed:e192 +nearAsFar
{
    sp -= 2;
    bx = pop();
    push(cs);
    push(bx);
    if (cl >= 0x10)
        goto loc_1007a;
    bx = dx;
    ax >>= cl;
    dx >>= cl;
    cl = -cl;
    cl += 0x10;
    bx <<= cl;
    ax |= bx;
    sp += 2;
    cs = pop();
    return;
loc_1007a: // 01ed:e1aa
    cl -= 0x10;
    tx = dx; dx = ax; ax = tx;
    dx = 0;
    ax >>= cl;
    sp += 2;
    cs = pop();
}
void sub_10083() // 01ed:e1b3 +nearAsFar
{
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    es = dx;
    tx = bx; bx = ax; ax = tx;
    dx = memoryAGet16(es, bx + 2);
    push(bx);
    bx = memoryAGet16(es, bx);
    if ((short)cx >= 0)
        goto loc_100a1;
    ax = ~ax;
    cx = ~cx;
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    cx += 0x0000 + flags.carry;
    goto loc_100e5;
loc_100a1: // 01ed:e1d1
    flags.carry = (bx + ax) >= 0x10000;
    bx += ax;
    if (!flags.carry)
        goto loc_100a9;
    dx += 0x1000;
loc_100a9: // 01ed:e1d9
    ah = cl;
    cl = 0x04;
    ah <<= cl;
    al = 0;
    dx += ax;
    ch = bl;
    bx >>= cl;
    dx += bx;
    al = ch;
    ax &= 0x000f;
    bx = pop();
    memoryASet16(es, bx, ax);
    memoryASet16(es, bx + 2, dx);
    sp += 2;
    cs = pop();
    return;
  // gap 30 bytes
loc_100e5: // 01ed:e215
    flags.carry = bx < ax;
    bx -= ax;
    if (!flags.carry)
        goto loc_100ed;
    dx -= 0x1000;
loc_100ed: // 01ed:e21d
    ah = cl;
    cl = 0x04;
    ah <<= cl;
    al = 0;
    dx -= ax;
    ch = bl;
    bx >>= cl;
    dx += bx;
    al = ch;
    ax &= 0x000f;
    bx = pop();
    memoryASet16(es, bx, ax);
    memoryASet16(es, bx + 2, dx);
    sp += 2;
    cs = pop();
}
void sub_1010b() // 01ed:e23b +nearAsFar
{
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    if ((short)cx >= 0)
        goto loc_1011e;
    bx = ~bx;
    cx = ~cx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    cx += 0x0000 + flags.carry;
    goto loc_1014d;
loc_1011e: // 01ed:e24e
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    if (!flags.carry)
        goto loc_10126;
    dx += 0x1000;
loc_10126: // 01ed:e256
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
loc_1014d: // 01ed:e27d
    flags.carry = ax < bx;
    ax -= bx;
    if (!flags.carry)
        goto loc_10155;
    dx -= 0x1000;
loc_10155: // 01ed:e285
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
void sub_1016b() // 01ed:e29b +stackDrop8 +nearAsFar
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
    si = memoryAGet16(ss, bp + 6); ds = memoryAGet16(ss, bp + 6 + 2); /*ggg2*/;
    di = memoryAGet16(ss, bp + 10); es = memoryAGet16(ss, bp + 10 + 2); /*ggg2*/;
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
    sp += 2;
    cs = pop();
    sp += 8;
}
void sub_1018a() // 01ed:e2ba
{
    sp -= 2;
    bx = pop(); // ret addr
    //stop("stack_below");
    sp -= cx; // skip 3 args
    push(cs);
    goto loc_10195;
  // gap 5 bytes
loc_10195: // 01ed:e2c5
    push(bx);
    push(di);
    push(ds);
    di = sp;
    di += 0x0008;
    bx = ss;
    es = bx;
    ds = dx;
    tx = si; si = ax; ax = tx;
    flags.direction = 0;
    flags.carry = cx & 1;
    cx >>= 1;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    cx += cx + flags.carry;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    tx = si; si = ax; ax = tx;
    ds = pop();
    di = pop();
//    stop("stack_unbalanced");
    sp += 2;
    cs = pop();
}
void sub_101c0() // 01ed:e2f0
{
    sp -= 2;
    push(si);
    push(di);
    si = sp;
    bx = memoryAGet16(ds, si + 6);
    flags.carry = bx < 0x0004;
    bx -= 0x0004;
    if (flags.carry)
        goto loc_101da;
    if (bx == memoryAGet16(ds, 0x562c))
        goto loc_101d7;
    sub_10217();
    goto loc_101da;
loc_101d7: // 01ed:e307
    sub_101dd();
loc_101da: // 01ed:e30a
    di = pop();
    si = pop();
    sp += 2;
}
void sub_101dd() // 01ed:e30d
{
    if (memoryAGet16(ds, 0x562a) == bx)
        goto loc_10206;
    si = memoryAGet16(ds, bx + 2);
    if (!(memoryAGet(ds, si) & 0x01))
        goto loc_101f1;
    memoryASet16(ds, 0x562c, si);
    goto loc_10211;
loc_101f1: // 01ed:e321
    if (si == memoryAGet16(ds, 0x562a))
        goto loc_10204;
    bx = si;
    sub_10250();
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x562c, ax);
    goto loc_10211;
loc_10204: // 01ed:e334
    bx = si;
loc_10206: // 01ed:e336
    ax = 0;
    memoryASet16(ds, 0x562a, ax);
    memoryASet16(ds, 0x562c, ax);
    memoryASet16(ds, 0x562e, ax);
loc_10211: // 01ed:e341
    push(bx);
    sub_edce();
    bx = pop();
}
void sub_10217() // 01ed:e347
{
    memoryASet16(ds, bx, memoryAGet16(ds, bx) - 1);
    if (bx == memoryAGet16(ds, 0x562a))
        goto loc_10237;
    si = memoryAGet16(ds, bx + 2);
    ax = memoryAGet16(ds, si);
    if (al & 0x01)
        goto loc_10237;
    ax += memoryAGet16(ds, bx);
    memoryASet16(ds, si, ax);
    di = memoryAGet16(ds, bx);
    di += bx;
    memoryASet16(ds, di + 2, si);
    bx = si;
    goto loc_1023a;
loc_10237: // 01ed:e367
    sub_1026c();
loc_1023a: // 01ed:e36a
    di = memoryAGet16(ds, bx);
    di += bx;
    ax = memoryAGet16(ds, di);
    if (!(al & 0x01))
        goto loc_10245;
    return;
loc_10245: // 01ed:e375
    memoryASet16(ds, bx, memoryAGet16(ds, bx) + ax);
    si = di;
    si += ax;
    memoryASet16(ds, si + 2, bx);
    bx = di;
    di = memoryAGet16(ds, bx + 6);
    if (bx == di)
        goto loc_10265;
    memoryASet16(ds, 0x562e, di);
    si = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, di + 4, si);
    memoryASet16(ds, si + 6, di);
    return;
loc_10265: // 01ed:e395
    memoryASet16(ds, 0x562e, 0x0000);
}
void sub_10250() // 01ed:e380
{
    di = memoryAGet16(ds, bx + 6);
    if (bx == di)
        goto loc_10265;
    memoryASet16(ds, 0x562e, di);
    si = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, di + 4, si);
    memoryASet16(ds, si + 6, di);
    return;
loc_10265: // 01ed:e395
    memoryASet16(ds, 0x562e, 0x0000);
}
void sub_1026c() // 01ed:e39c
{
    si = memoryAGet16(ds, 0x562e);
    if (!si)
        goto loc_10284;
    di = memoryAGet16(ds, si + 6);
    memoryASet16(ds, si + 6, bx);
    memoryASet16(ds, di + 4, bx);
    memoryASet16(ds, bx + 6, di);
    memoryASet16(ds, bx + 4, si);
    return;
loc_10284: // 01ed:e3b4
    memoryASet16(ds, 0x562e, bx);
    memoryASet16(ds, bx + 4, bx);
    memoryASet16(ds, bx + 6, bx);
}
void sub_1028f() // 01ed:e3bf
{
    sp -= 2;
    push(si);
    push(di);
    si = sp;
    ax = memoryAGet16(ds, si + 6);
    if (!ax)
        goto loc_102ec;
    flags.carry = (ax + 0x0005) >= 0x10000;
    ax += 0x0005;
    if (flags.carry)
        goto loc_102d5;
    ax &= 0xfffe;
    if (ax >= 0x0008)
        goto loc_102aa;
    ax = 0x0008;
loc_102aa: // 01ed:e3da
    if (memoryAGet16(ds, 0x562a) == 0x0000)
        goto loc_102d0;
    bx = memoryAGet16(ds, 0x562e);
    if (!bx)
        goto loc_102c6;
    dx = bx;
loc_102bb: // 01ed:e3eb
    if (memoryAGet16(ds, bx) >= ax)
        goto loc_102d9;
    bx = memoryAGet16(ds, bx + 6);
    if (bx != dx)
        goto loc_102bb;
loc_102c6: // 01ed:e3f6
    sub_1032f();
    goto loc_102ec;
loc_102cb: // 01ed:e3fb
    sub_10358();
    goto loc_102ec;
loc_102d0: // 01ed:e400
    sub_102ef();
    goto loc_102ec;
loc_102d5: // 01ed:e405
    ax = 0;
    goto loc_102ec;
loc_102d9: // 01ed:e409
    si = ax;
    si += 0x0008;
    if (memoryAGet16(ds, bx) >= si)
        goto loc_102cb;
    sub_10250();
    memoryASet16(ds, bx, memoryAGet16(ds, bx) + 1);
    ax = bx;
    ax += 0x0004;
loc_102ec: // 01ed:e41c
    di = pop();
    si = pop();
    sp += 2;
}
void sub_102ef() // 01ed:e41f
{
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    sub_edf0();
    bx = pop();
    bx = pop();
    ax &= 0x0001;
    if (!ax)
        goto loc_10307;
    dx = 0;
    push(dx);
    push(ax);
    sub_edf0();
    bx = pop();
    bx = pop();
loc_10307: // 01ed:e437
    ax = pop();
    push(ax);
    bx = 0;
    push(bx);
    push(ax);
    sub_edf0();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_1032b;
    bx = ax;
    memoryASet16(ds, 0x562a, bx);
    memoryASet16(ds, 0x562c, bx);
    ax = pop();
    ax++;
    memoryASet16(ds, bx, ax);
    bx += 0x0004;
    ax = bx;
    return;
loc_1032b: // 01ed:e45b
    bx = pop();
    ax = 0;
}
void sub_1032f() // 01ed:e45f
{
    push(ax);
    bx = 0;
    push(bx);
    push(ax);
    sub_edf0();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_10354;
    bx = ax;
    ax = memoryAGet16(ds, 0x562c);
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ds, 0x562c, bx);
    ax = pop();
    ax++;
    memoryASet16(ds, bx, ax);
    bx += 0x0004;
    ax = bx;
    return;
loc_10354: // 01ed:e484
    ax = pop();
    ax = 0;
}
void sub_10358() // 01ed:e488
{
    memoryASet16(ds, bx, memoryAGet16(ds, bx) - ax);
    si = bx;
    si += memoryAGet16(ds, bx);
    di = si;
    di += ax;
    ax++;
    memoryASet16(ds, si, ax);
    memoryASet16(ds, si + 2, bx);
    memoryASet16(ds, di + 2, si);
    si += 0x0004;
    ax = si;
}
void sub_10433() // 01ed:e563
{
    push(si);
    tx = si; si = ax; ax = tx;
    tx = dx; dx = ax; ax = tx;
    if (!ax)
        goto loc_1043c;
    mul16(bx);
loc_1043c: // 01ed:e56c
    if (cx==0)
        goto loc_10443;
    tx = cx; cx = ax; ax = tx;
    mul16(si);
    ax += cx;
loc_10443: // 01ed:e573
    tx = si; si = ax; ax = tx;
    mul16(bx);
    dx += si;
    si = pop();
}
void sub_1044a() // 01ed:e57a +returnCarry +returnZero
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
        goto loc_1046a;
    flags.carry = ax < bx;
    flags.zero = ax == bx;
loc_1046a: // 01ed:e59a
    return;
}
void sub_10471() // 01ed:e5a1
{
    sp -= 2;
    goto loc_10471;
loc_20f0: // 01ed:0220
    cx = 0x001e;
    stop("stack_below");
    dx = 0x0054;
    ds = memoryAGet16(cs, 0x0235);
    sub_20e8();
    ax = 0x0003;
    push(ax);
    sub_1ffe();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    memoryASet16(ds, bx + si, memoryAGet16(ds, bx + si) + ax);
    push(bp);
    bp = sp;
    ax = 0;
    memoryASet16(ds, 0x6ed8, ax);
    memoryASet16(ds, 0x6ecc, ax);
    memoryASet16(ds, 0x6ebe, ax);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
loc_212f: // 01ed:025f
    ax = memoryAGet16(ds, 0x5135);
    ax -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, ax);
    if (ax < 0x0006)
        goto loc_212f;
    if (ax <= 0x000f)
        goto loc_2149;
    memoryASet16(ds, 0x5b14, 0x000f);
loc_2149: // 01ed:0279
    ax = memoryAGet16(ds, 0x5137);
    dx = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, dx);
    memoryASet16(ds, 0x5640, ax);
    bp = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  // gap 58136 bytes
loc_10471: // 01ed:e5a1
    memoryASet16(ds, 0x5634, pop());
    memoryASet16(ds, 0x5636, pop());
    memoryASet16(ds, 0x5638, pop());
    memoryASet16(cs, 0xe59f, ds);
    memoryASet16(ds, 0x563a, si);
    memoryASet16(ds, 0x563c, di);
    flags.direction = 0;
    es = memoryAGet16(ds, 0x008e);
    si = 0x0080;
    ah = 0;
    al = lodsb<ES_SI>();
    ax++;
    bp = es;
    tx = si; si = dx; dx = tx;
    tx = bx; bx = ax; ax = tx;
    si = memoryAGet16(ds, 0x0088);
    si++;
    si++;
    cx = 0x0001;
    if (memoryAGet(ds, 0x0090) < 0x03)
        goto loc_104bd;
    es = memoryAGet16(ds, 0x008a);
    di = si;
    cl = 0x7f;
    al = 0;
    for (flags.zero = 0; cx != 0 && !flags.zero; --cx) scasb_inv<ES_DI>(al);
    if (cx==0)
        goto loc_10528;
    cl ^= 0x7f;
loc_104bd: // 01ed:e5ed
    push(ax);
    ax = cx;
    ax += bx;
    ax++;
    ax &= 0xfffe;
    di = sp;
    flags.carry = di < ax;
    di -= ax;
    if (flags.carry)
        goto loc_10528;
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
loc_104e4: // 01ed:e614
    sub_10500();
    if (!flags.carry && !flags.zero)
        goto loc_104f0;
loc_104e9: // 01ed:e619
    if (flags.carry)
        goto loc_1052b;
    sub_10500();
    if (!flags.carry && !flags.zero)
        goto loc_104e9;
loc_104f0: // 01ed:e620
    if (al == 0x20)
        goto loc_104fc;
    if (al == 0x0d)
        goto loc_104fc;
    if (al != 0x09)
        goto loc_104e4;
loc_104fc: // 01ed:e62c
    al = 0;
    goto loc_104e4;
  // gap 40 bytes
loc_10528: // 01ed:e658
    goto loc_20f0;
    stop("stack_below");
loc_1052b: // 01ed:e65b
    cx = pop();
    cx += dx;
    ds = memoryAGet16(cs, 0xe59f);
    memoryASet16(ds, 0x5630, bx);
    bx++;
    bx += bx;
    si = sp;
    bp = sp;
    flags.carry = bp < bx;
    bp -= bx;
    if (flags.carry)
        goto loc_10528;
    sp = bp;
    memoryASet16(ds, 0x5632, bp);
loc_10548: // 01ed:e678
    if (cx==0)
        goto loc_10558;
    memoryASet16(ss, bp, si);
    bp += 0x0002;
loc_10550: // 01ed:e680
    al = lodsb<SS_SI>();
    if (--cx && al)
        goto loc_10550;
    if (!al)
        goto loc_10548;
loc_10558: // 01ed:e688
    ax = 0;
    memoryASet16(ss, bp, ax);
    ds = memoryAGet16(cs, 0xe59f);
    si = memoryAGet16(ds, 0x563a);
    di = memoryAGet16(ds, 0x563c);
    push(memoryAGet16(ds, 0x5638));
    push(memoryAGet16(ds, 0x5636));
    ax = memoryAGet16(ds, 0x5630);
    memoryASet16(ds, 0x0082, ax);
    ax = memoryAGet16(ds, 0x5632);
    memoryASet16(ds, 0x0084, ax);
//    indirectJump(cs, memoryAGet16(ds, 0x5634)); // 01ed:e6ae;
}
void sub_10500() // 01ed:e630 +returnCarry +returnZero
{
    if (!ax)
        goto loc_1050b;
    dx++;
    stosb<ES_DI>(al);
    if (al)
        goto loc_1050b;
    bx++;
loc_1050b: // 01ed:e63b
    tl = al; al = ah; ah = tl;
    flags.zero = 0;
    al = 0;
    flags.carry = 1;
    if (cx==0)
        goto loc_10527;
    al = lodsb<DS_SI>();
    cx--;
    flags.carry = al < 0x22;
    flags.zero = al == 0x22;
    al -= 0x22;
    if (flags.zero)
        goto loc_10527;
    al += 0x22;
    if (al != 0x5c)
        goto loc_10525;
    if (memoryAGet(ds, si) != 0x22)
        goto loc_10525;
    al = lodsb<DS_SI>();
    cx--;
loc_10525: // 01ed:e655
    flags.carry = 0 /*ggg1*/;
    flags.zero = !si;
loc_10527: // 01ed:e657
    return;
}
void sub_10590() // 1059:0000
{
    es = memoryAGet16(ds, 0x35b2);
    ds = memoryAGet16(ds, 0x836a);
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    di += dx;
    movsb<ES_DI, DS_SI>();
    movsb<ES_DI, DS_SI>();
    ax = ss;
    ds = ax;
    es = cx;
}
void sub_105dd() // 1059:004d +far
{
    dx = 0x002e;
    cx = es;
    si = memoryAGet16(es, bx);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b16))
        goto loc_105f9;
    memoryASet16(ds, 0x5b16, si);
    di = 0x0604;
    sub_10590();
loc_105f9: // 1059:0069
    si = memoryAGet16(es, bx + 2);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b18))
        goto loc_10611;
    memoryASet16(ds, 0x5b18, si);
    di = 0x0606;
    sub_10590();
loc_10611: // 1059:0081
    si = memoryAGet16(es, bx + 4);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b1a))
        goto loc_10629;
    memoryASet16(ds, 0x5b1a, si);
    di = 0x0608;
    sub_10590();
loc_10629: // 1059:0099
    si = memoryAGet16(es, bx + 6);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b1c))
        goto loc_10641;
    memoryASet16(ds, 0x5b1c, si);
    di = 0x060a;
    sub_10590();
loc_10641: // 1059:00b1
    si = memoryAGet16(es, bx + 8);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b1e))
        goto loc_10659;
    memoryASet16(ds, 0x5b1e, si);
    di = 0x060c;
    sub_10590();
loc_10659: // 1059:00c9
    si = memoryAGet16(es, bx + 10);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b20))
        goto loc_10671;
    memoryASet16(ds, 0x5b20, si);
    di = 0x060e;
    sub_10590();
loc_10671: // 1059:00e1
    si = memoryAGet16(es, bx + 12);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b22))
        goto loc_10689;
    memoryASet16(ds, 0x5b22, si);
    di = 0x0610;
    sub_10590();
loc_10689: // 1059:00f9
    si = memoryAGet16(es, bx + 14);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b24))
        goto loc_106a1;
    memoryASet16(ds, 0x5b24, si);
    di = 0x0612;
    sub_10590();
loc_106a1: // 1059:0111
    si = memoryAGet16(es, bx + 16);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b26))
        goto loc_106b9;
    memoryASet16(ds, 0x5b26, si);
    di = 0x0614;
    sub_10590();
loc_106b9: // 1059:0129
    si = memoryAGet16(es, bx + 18);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b28))
        goto loc_106d1;
    memoryASet16(ds, 0x5b28, si);
    di = 0x0616;
    sub_10590();
loc_106d1: // 1059:0141
    si = memoryAGet16(es, bx + 20);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b2a))
        goto loc_106e9;
    memoryASet16(ds, 0x5b2a, si);
    di = 0x0618;
    sub_10590();
loc_106e9: // 1059:0159
    si = memoryAGet16(es, bx + 22);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b2c))
        goto loc_10701;
    memoryASet16(ds, 0x5b2c, si);
    di = 0x061a;
    sub_10590();
loc_10701: // 1059:0171
    si = memoryAGet16(es, bx + 24);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b2e))
        goto loc_10719;
    memoryASet16(ds, 0x5b2e, si);
    di = 0x061c;
    sub_10590();
loc_10719: // 1059:0189
    si = memoryAGet16(es, bx + 26);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b30))
        goto loc_10731;
    memoryASet16(ds, 0x5b30, si);
    di = 0x061e;
    sub_10590();
loc_10731: // 1059:01a1
    si = memoryAGet16(es, bx + 28);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b32))
        goto loc_10749;
    memoryASet16(ds, 0x5b32, si);
    di = 0x0620;
    sub_10590();
loc_10749: // 1059:01b9
    si = memoryAGet16(es, bx + 30);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b34))
        goto loc_10761;
    memoryASet16(ds, 0x5b34, si);
    di = 0x0622;
    sub_10590();
loc_10761: // 1059:01d1
    si = memoryAGet16(es, bx + 32);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b36))
        goto loc_10779;
    memoryASet16(ds, 0x5b36, si);
    di = 0x0624;
    sub_10590();
loc_10779: // 1059:01e9
    si = memoryAGet16(es, bx + 34);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b38))
        goto loc_10791;
    memoryASet16(ds, 0x5b38, si);
    di = 0x0626;
    sub_10590();
loc_10791: // 1059:0201
    si = memoryAGet16(es, bx + 36);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b3a))
        goto loc_107a9;
    memoryASet16(ds, 0x5b3a, si);
    di = 0x0628;
    sub_10590();
loc_107a9: // 1059:0219
    si = memoryAGet16(es, bx + 38);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b3c))
        goto loc_107c1;
    memoryASet16(ds, 0x5b3c, si);
    di = 0x062a;
    sub_10590();
loc_107c1: // 1059:0231
    si = memoryAGet16(es, bx + 40);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b3e))
        goto loc_107d9;
    memoryASet16(ds, 0x5b3e, si);
    di = 0x062c;
    sub_10590();
loc_107d9: // 1059:0249
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 42);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b40))
        goto loc_107f5;
    memoryASet16(ds, 0x5b40, si);
    di = 0x0904;
    sub_10590();
loc_107f5: // 1059:0265
    si = memoryAGet16(es, bx + 44);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b42))
        goto loc_1080d;
    memoryASet16(ds, 0x5b42, si);
    di = 0x0906;
    sub_10590();
loc_1080d: // 1059:027d
    si = memoryAGet16(es, bx + 46);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b44))
        goto loc_10825;
    memoryASet16(ds, 0x5b44, si);
    di = 0x0908;
    sub_10590();
loc_10825: // 1059:0295
    si = memoryAGet16(es, bx + 48);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b46))
        goto loc_1083d;
    memoryASet16(ds, 0x5b46, si);
    di = 0x090a;
    sub_10590();
loc_1083d: // 1059:02ad
    si = memoryAGet16(es, bx + 50);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b48))
        goto loc_10855;
    memoryASet16(ds, 0x5b48, si);
    di = 0x090c;
    sub_10590();
loc_10855: // 1059:02c5
    si = memoryAGet16(es, bx + 52);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b4a))
        goto loc_1086d;
    memoryASet16(ds, 0x5b4a, si);
    di = 0x090e;
    sub_10590();
loc_1086d: // 1059:02dd
    si = memoryAGet16(es, bx + 54);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b4c))
        goto loc_10885;
    memoryASet16(ds, 0x5b4c, si);
    di = 0x0910;
    sub_10590();
loc_10885: // 1059:02f5
    si = memoryAGet16(es, bx + 56);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b4e))
        goto loc_1089d;
    memoryASet16(ds, 0x5b4e, si);
    di = 0x0912;
    sub_10590();
loc_1089d: // 1059:030d
    si = memoryAGet16(es, bx + 58);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b50))
        goto loc_108b5;
    memoryASet16(ds, 0x5b50, si);
    di = 0x0914;
    sub_10590();
loc_108b5: // 1059:0325
    si = memoryAGet16(es, bx + 60);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b52))
        goto loc_108cd;
    memoryASet16(ds, 0x5b52, si);
    di = 0x0916;
    sub_10590();
loc_108cd: // 1059:033d
    si = memoryAGet16(es, bx + 62);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b54))
        goto loc_108e5;
    memoryASet16(ds, 0x5b54, si);
    di = 0x0918;
    sub_10590();
loc_108e5: // 1059:0355
    si = memoryAGet16(es, bx + 64);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b56))
        goto loc_108fd;
    memoryASet16(ds, 0x5b56, si);
    di = 0x091a;
    sub_10590();
loc_108fd: // 1059:036d
    si = memoryAGet16(es, bx + 66);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b58))
        goto loc_10915;
    memoryASet16(ds, 0x5b58, si);
    di = 0x091c;
    sub_10590();
loc_10915: // 1059:0385
    si = memoryAGet16(es, bx + 68);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b5a))
        goto loc_1092d;
    memoryASet16(ds, 0x5b5a, si);
    di = 0x091e;
    sub_10590();
loc_1092d: // 1059:039d
    si = memoryAGet16(es, bx + 70);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b5c))
        goto loc_10945;
    memoryASet16(ds, 0x5b5c, si);
    di = 0x0920;
    sub_10590();
loc_10945: // 1059:03b5
    si = memoryAGet16(es, bx + 72);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b5e))
        goto loc_1095d;
    memoryASet16(ds, 0x5b5e, si);
    di = 0x0922;
    sub_10590();
loc_1095d: // 1059:03cd
    si = memoryAGet16(es, bx + 74);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b60))
        goto loc_10975;
    memoryASet16(ds, 0x5b60, si);
    di = 0x0924;
    sub_10590();
loc_10975: // 1059:03e5
    si = memoryAGet16(es, bx + 76);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b62))
        goto loc_1098d;
    memoryASet16(ds, 0x5b62, si);
    di = 0x0926;
    sub_10590();
loc_1098d: // 1059:03fd
    si = memoryAGet16(es, bx + 78);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b64))
        goto loc_109a5;
    memoryASet16(ds, 0x5b64, si);
    di = 0x0928;
    sub_10590();
loc_109a5: // 1059:0415
    si = memoryAGet16(es, bx + 80);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b66))
        goto loc_109bd;
    memoryASet16(ds, 0x5b66, si);
    di = 0x092a;
    sub_10590();
loc_109bd: // 1059:042d
    si = memoryAGet16(es, bx + 82);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b68))
        goto loc_109d5;
    memoryASet16(ds, 0x5b68, si);
    di = 0x092c;
    sub_10590();
loc_109d5: // 1059:0445
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 84);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b6a))
        goto loc_109f1;
    memoryASet16(ds, 0x5b6a, si);
    di = 0x0c04;
    sub_10590();
loc_109f1: // 1059:0461
    si = memoryAGet16(es, bx + 86);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b6c))
        goto loc_10a09;
    memoryASet16(ds, 0x5b6c, si);
    di = 0x0c06;
    sub_10590();
loc_10a09: // 1059:0479
    si = memoryAGet16(es, bx + 88);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b6e))
        goto loc_10a21;
    memoryASet16(ds, 0x5b6e, si);
    di = 0x0c08;
    sub_10590();
loc_10a21: // 1059:0491
    si = memoryAGet16(es, bx + 90);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b70))
        goto loc_10a39;
    memoryASet16(ds, 0x5b70, si);
    di = 0x0c0a;
    sub_10590();
loc_10a39: // 1059:04a9
    si = memoryAGet16(es, bx + 92);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b72))
        goto loc_10a51;
    memoryASet16(ds, 0x5b72, si);
    di = 0x0c0c;
    sub_10590();
loc_10a51: // 1059:04c1
    si = memoryAGet16(es, bx + 94);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b74))
        goto loc_10a69;
    memoryASet16(ds, 0x5b74, si);
    di = 0x0c0e;
    sub_10590();
loc_10a69: // 1059:04d9
    si = memoryAGet16(es, bx + 96);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b76))
        goto loc_10a81;
    memoryASet16(ds, 0x5b76, si);
    di = 0x0c10;
    sub_10590();
loc_10a81: // 1059:04f1
    si = memoryAGet16(es, bx + 98);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b78))
        goto loc_10a99;
    memoryASet16(ds, 0x5b78, si);
    di = 0x0c12;
    sub_10590();
loc_10a99: // 1059:0509
    si = memoryAGet16(es, bx + 100);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b7a))
        goto loc_10ab1;
    memoryASet16(ds, 0x5b7a, si);
    di = 0x0c14;
    sub_10590();
loc_10ab1: // 1059:0521
    si = memoryAGet16(es, bx + 102);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b7c))
        goto loc_10ac9;
    memoryASet16(ds, 0x5b7c, si);
    di = 0x0c16;
    sub_10590();
loc_10ac9: // 1059:0539
    si = memoryAGet16(es, bx + 104);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b7e))
        goto loc_10ae1;
    memoryASet16(ds, 0x5b7e, si);
    di = 0x0c18;
    sub_10590();
loc_10ae1: // 1059:0551
    si = memoryAGet16(es, bx + 106);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b80))
        goto loc_10af9;
    memoryASet16(ds, 0x5b80, si);
    di = 0x0c1a;
    sub_10590();
loc_10af9: // 1059:0569
    si = memoryAGet16(es, bx + 108);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b82))
        goto loc_10b11;
    memoryASet16(ds, 0x5b82, si);
    di = 0x0c1c;
    sub_10590();
loc_10b11: // 1059:0581
    si = memoryAGet16(es, bx + 110);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b84))
        goto loc_10b29;
    memoryASet16(ds, 0x5b84, si);
    di = 0x0c1e;
    sub_10590();
loc_10b29: // 1059:0599
    si = memoryAGet16(es, bx + 112);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b86))
        goto loc_10b41;
    memoryASet16(ds, 0x5b86, si);
    di = 0x0c20;
    sub_10590();
loc_10b41: // 1059:05b1
    si = memoryAGet16(es, bx + 114);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b88))
        goto loc_10b59;
    memoryASet16(ds, 0x5b88, si);
    di = 0x0c22;
    sub_10590();
loc_10b59: // 1059:05c9
    si = memoryAGet16(es, bx + 116);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b8a))
        goto loc_10b71;
    memoryASet16(ds, 0x5b8a, si);
    di = 0x0c24;
    sub_10590();
loc_10b71: // 1059:05e1
    si = memoryAGet16(es, bx + 118);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b8c))
        goto loc_10b89;
    memoryASet16(ds, 0x5b8c, si);
    di = 0x0c26;
    sub_10590();
loc_10b89: // 1059:05f9
    si = memoryAGet16(es, bx + 120);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b8e))
        goto loc_10ba1;
    memoryASet16(ds, 0x5b8e, si);
    di = 0x0c28;
    sub_10590();
loc_10ba1: // 1059:0611
    si = memoryAGet16(es, bx + 122);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b90))
        goto loc_10bb9;
    memoryASet16(ds, 0x5b90, si);
    di = 0x0c2a;
    sub_10590();
loc_10bb9: // 1059:0629
    si = memoryAGet16(es, bx + 124);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b92))
        goto loc_10bd1;
    memoryASet16(ds, 0x5b92, si);
    di = 0x0c2c;
    sub_10590();
loc_10bd1: // 1059:0641
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 126);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b94))
        goto loc_10bed;
    memoryASet16(ds, 0x5b94, si);
    di = 0x0f04;
    sub_10590();
loc_10bed: // 1059:065d
    si = memoryAGet16(es, bx + 128);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b96))
        goto loc_10c06;
    memoryASet16(ds, 0x5b96, si);
    di = 0x0f06;
    sub_10590();
loc_10c06: // 1059:0676
    si = memoryAGet16(es, bx + 130);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b98))
        goto loc_10c1f;
    memoryASet16(ds, 0x5b98, si);
    di = 0x0f08;
    sub_10590();
loc_10c1f: // 1059:068f
    si = memoryAGet16(es, bx + 132);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b9a))
        goto loc_10c38;
    memoryASet16(ds, 0x5b9a, si);
    di = 0x0f0a;
    sub_10590();
loc_10c38: // 1059:06a8
    si = memoryAGet16(es, bx + 134);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b9c))
        goto loc_10c51;
    memoryASet16(ds, 0x5b9c, si);
    di = 0x0f0c;
    sub_10590();
loc_10c51: // 1059:06c1
    si = memoryAGet16(es, bx + 136);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5b9e))
        goto loc_10c6a;
    memoryASet16(ds, 0x5b9e, si);
    di = 0x0f0e;
    sub_10590();
loc_10c6a: // 1059:06da
    si = memoryAGet16(es, bx + 138);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ba0))
        goto loc_10c83;
    memoryASet16(ds, 0x5ba0, si);
    di = 0x0f10;
    sub_10590();
loc_10c83: // 1059:06f3
    si = memoryAGet16(es, bx + 140);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ba2))
        goto loc_10c9c;
    memoryASet16(ds, 0x5ba2, si);
    di = 0x0f12;
    sub_10590();
loc_10c9c: // 1059:070c
    si = memoryAGet16(es, bx + 142);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ba4))
        goto loc_10cb5;
    memoryASet16(ds, 0x5ba4, si);
    di = 0x0f14;
    sub_10590();
loc_10cb5: // 1059:0725
    si = memoryAGet16(es, bx + 144);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ba6))
        goto loc_10cce;
    memoryASet16(ds, 0x5ba6, si);
    di = 0x0f16;
    sub_10590();
loc_10cce: // 1059:073e
    si = memoryAGet16(es, bx + 146);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ba8))
        goto loc_10ce7;
    memoryASet16(ds, 0x5ba8, si);
    di = 0x0f18;
    sub_10590();
loc_10ce7: // 1059:0757
    si = memoryAGet16(es, bx + 148);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5baa))
        goto loc_10d00;
    memoryASet16(ds, 0x5baa, si);
    di = 0x0f1a;
    sub_10590();
loc_10d00: // 1059:0770
    si = memoryAGet16(es, bx + 150);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bac))
        goto loc_10d19;
    memoryASet16(ds, 0x5bac, si);
    di = 0x0f1c;
    sub_10590();
loc_10d19: // 1059:0789
    si = memoryAGet16(es, bx + 152);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bae))
        goto loc_10d32;
    memoryASet16(ds, 0x5bae, si);
    di = 0x0f1e;
    sub_10590();
loc_10d32: // 1059:07a2
    si = memoryAGet16(es, bx + 154);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bb0))
        goto loc_10d4b;
    memoryASet16(ds, 0x5bb0, si);
    di = 0x0f20;
    sub_10590();
loc_10d4b: // 1059:07bb
    si = memoryAGet16(es, bx + 156);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bb2))
        goto loc_10d64;
    memoryASet16(ds, 0x5bb2, si);
    di = 0x0f22;
    sub_10590();
loc_10d64: // 1059:07d4
    si = memoryAGet16(es, bx + 158);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bb4))
        goto loc_10d7d;
    memoryASet16(ds, 0x5bb4, si);
    di = 0x0f24;
    sub_10590();
loc_10d7d: // 1059:07ed
    si = memoryAGet16(es, bx + 160);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bb6))
        goto loc_10d96;
    memoryASet16(ds, 0x5bb6, si);
    di = 0x0f26;
    sub_10590();
loc_10d96: // 1059:0806
    si = memoryAGet16(es, bx + 162);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bb8))
        goto loc_10daf;
    memoryASet16(ds, 0x5bb8, si);
    di = 0x0f28;
    sub_10590();
loc_10daf: // 1059:081f
    si = memoryAGet16(es, bx + 164);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bba))
        goto loc_10dc8;
    memoryASet16(ds, 0x5bba, si);
    di = 0x0f2a;
    sub_10590();
loc_10dc8: // 1059:0838
    si = memoryAGet16(es, bx + 166);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bbc))
        goto loc_10de1;
    memoryASet16(ds, 0x5bbc, si);
    di = 0x0f2c;
    sub_10590();
loc_10de1: // 1059:0851
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 168);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bbe))
        goto loc_10dfe;
    memoryASet16(ds, 0x5bbe, si);
    di = 0x1204;
    sub_10590();
loc_10dfe: // 1059:086e
    si = memoryAGet16(es, bx + 170);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bc0))
        goto loc_10e17;
    memoryASet16(ds, 0x5bc0, si);
    di = 0x1206;
    sub_10590();
loc_10e17: // 1059:0887
    si = memoryAGet16(es, bx + 172);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bc2))
        goto loc_10e30;
    memoryASet16(ds, 0x5bc2, si);
    di = 0x1208;
    sub_10590();
loc_10e30: // 1059:08a0
    si = memoryAGet16(es, bx + 174);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bc4))
        goto loc_10e49;
    memoryASet16(ds, 0x5bc4, si);
    di = 0x120a;
    sub_10590();
loc_10e49: // 1059:08b9
    si = memoryAGet16(es, bx + 176);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bc6))
        goto loc_10e62;
    memoryASet16(ds, 0x5bc6, si);
    di = 0x120c;
    sub_10590();
loc_10e62: // 1059:08d2
    si = memoryAGet16(es, bx + 178);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bc8))
        goto loc_10e7b;
    memoryASet16(ds, 0x5bc8, si);
    di = 0x120e;
    sub_10590();
loc_10e7b: // 1059:08eb
    si = memoryAGet16(es, bx + 180);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bca))
        goto loc_10e94;
    memoryASet16(ds, 0x5bca, si);
    di = 0x1210;
    sub_10590();
loc_10e94: // 1059:0904
    si = memoryAGet16(es, bx + 182);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bcc))
        goto loc_10ead;
    memoryASet16(ds, 0x5bcc, si);
    di = 0x1212;
    sub_10590();
loc_10ead: // 1059:091d
    si = memoryAGet16(es, bx + 184);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bce))
        goto loc_10ec6;
    memoryASet16(ds, 0x5bce, si);
    di = 0x1214;
    sub_10590();
loc_10ec6: // 1059:0936
    si = memoryAGet16(es, bx + 186);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bd0))
        goto loc_10edf;
    memoryASet16(ds, 0x5bd0, si);
    di = 0x1216;
    sub_10590();
loc_10edf: // 1059:094f
    si = memoryAGet16(es, bx + 188);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bd2))
        goto loc_10ef8;
    memoryASet16(ds, 0x5bd2, si);
    di = 0x1218;
    sub_10590();
loc_10ef8: // 1059:0968
    si = memoryAGet16(es, bx + 190);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bd4))
        goto loc_10f11;
    memoryASet16(ds, 0x5bd4, si);
    di = 0x121a;
    sub_10590();
loc_10f11: // 1059:0981
    si = memoryAGet16(es, bx + 192);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bd6))
        goto loc_10f2a;
    memoryASet16(ds, 0x5bd6, si);
    di = 0x121c;
    sub_10590();
loc_10f2a: // 1059:099a
    si = memoryAGet16(es, bx + 194);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bd8))
        goto loc_10f43;
    memoryASet16(ds, 0x5bd8, si);
    di = 0x121e;
    sub_10590();
loc_10f43: // 1059:09b3
    si = memoryAGet16(es, bx + 196);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bda))
        goto loc_10f5c;
    memoryASet16(ds, 0x5bda, si);
    di = 0x1220;
    sub_10590();
loc_10f5c: // 1059:09cc
    si = memoryAGet16(es, bx + 198);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bdc))
        goto loc_10f75;
    memoryASet16(ds, 0x5bdc, si);
    di = 0x1222;
    sub_10590();
loc_10f75: // 1059:09e5
    si = memoryAGet16(es, bx + 200);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bde))
        goto loc_10f8e;
    memoryASet16(ds, 0x5bde, si);
    di = 0x1224;
    sub_10590();
loc_10f8e: // 1059:09fe
    si = memoryAGet16(es, bx + 202);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5be0))
        goto loc_10fa7;
    memoryASet16(ds, 0x5be0, si);
    di = 0x1226;
    sub_10590();
loc_10fa7: // 1059:0a17
    si = memoryAGet16(es, bx + 204);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5be2))
        goto loc_10fc0;
    memoryASet16(ds, 0x5be2, si);
    di = 0x1228;
    sub_10590();
loc_10fc0: // 1059:0a30
    si = memoryAGet16(es, bx + 206);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5be4))
        goto loc_10fd9;
    memoryASet16(ds, 0x5be4, si);
    di = 0x122a;
    sub_10590();
loc_10fd9: // 1059:0a49
    si = memoryAGet16(es, bx + 208);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5be6))
        goto loc_10ff2;
    memoryASet16(ds, 0x5be6, si);
    di = 0x122c;
    sub_10590();
loc_10ff2: // 1059:0a62
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 210);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5be8))
        goto loc_1100f;
    memoryASet16(ds, 0x5be8, si);
    di = 0x1504;
    sub_10590();
loc_1100f: // 1059:0a7f
    si = memoryAGet16(es, bx + 212);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bea))
        goto loc_11028;
    memoryASet16(ds, 0x5bea, si);
    di = 0x1506;
    sub_10590();
loc_11028: // 1059:0a98
    si = memoryAGet16(es, bx + 214);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bec))
        goto loc_11041;
    memoryASet16(ds, 0x5bec, si);
    di = 0x1508;
    sub_10590();
loc_11041: // 1059:0ab1
    si = memoryAGet16(es, bx + 216);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bee))
        goto loc_1105a;
    memoryASet16(ds, 0x5bee, si);
    di = 0x150a;
    sub_10590();
loc_1105a: // 1059:0aca
    si = memoryAGet16(es, bx + 218);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bf0))
        goto loc_11073;
    memoryASet16(ds, 0x5bf0, si);
    di = 0x150c;
    sub_10590();
loc_11073: // 1059:0ae3
    si = memoryAGet16(es, bx + 220);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bf2))
        goto loc_1108c;
    memoryASet16(ds, 0x5bf2, si);
    di = 0x150e;
    sub_10590();
loc_1108c: // 1059:0afc
    si = memoryAGet16(es, bx + 222);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bf4))
        goto loc_110a5;
    memoryASet16(ds, 0x5bf4, si);
    di = 0x1510;
    sub_10590();
loc_110a5: // 1059:0b15
    si = memoryAGet16(es, bx + 224);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bf6))
        goto loc_110be;
    memoryASet16(ds, 0x5bf6, si);
    di = 0x1512;
    sub_10590();
loc_110be: // 1059:0b2e
    si = memoryAGet16(es, bx + 226);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bf8))
        goto loc_110d7;
    memoryASet16(ds, 0x5bf8, si);
    di = 0x1514;
    sub_10590();
loc_110d7: // 1059:0b47
    si = memoryAGet16(es, bx + 228);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bfa))
        goto loc_110f0;
    memoryASet16(ds, 0x5bfa, si);
    di = 0x1516;
    sub_10590();
loc_110f0: // 1059:0b60
    si = memoryAGet16(es, bx + 230);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bfc))
        goto loc_11109;
    memoryASet16(ds, 0x5bfc, si);
    di = 0x1518;
    sub_10590();
loc_11109: // 1059:0b79
    si = memoryAGet16(es, bx + 232);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5bfe))
        goto loc_11122;
    memoryASet16(ds, 0x5bfe, si);
    di = 0x151a;
    sub_10590();
loc_11122: // 1059:0b92
    si = memoryAGet16(es, bx + 234);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c00))
        goto loc_1113b;
    memoryASet16(ds, 0x5c00, si);
    di = 0x151c;
    sub_10590();
loc_1113b: // 1059:0bab
    si = memoryAGet16(es, bx + 236);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c02))
        goto loc_11154;
    memoryASet16(ds, 0x5c02, si);
    di = 0x151e;
    sub_10590();
loc_11154: // 1059:0bc4
    si = memoryAGet16(es, bx + 238);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c04))
        goto loc_1116d;
    memoryASet16(ds, 0x5c04, si);
    di = 0x1520;
    sub_10590();
loc_1116d: // 1059:0bdd
    si = memoryAGet16(es, bx + 240);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c06))
        goto loc_11186;
    memoryASet16(ds, 0x5c06, si);
    di = 0x1522;
    sub_10590();
loc_11186: // 1059:0bf6
    si = memoryAGet16(es, bx + 242);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c08))
        goto loc_1119f;
    memoryASet16(ds, 0x5c08, si);
    di = 0x1524;
    sub_10590();
loc_1119f: // 1059:0c0f
    si = memoryAGet16(es, bx + 244);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c0a))
        goto loc_111b8;
    memoryASet16(ds, 0x5c0a, si);
    di = 0x1526;
    sub_10590();
loc_111b8: // 1059:0c28
    si = memoryAGet16(es, bx + 246);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c0c))
        goto loc_111d1;
    memoryASet16(ds, 0x5c0c, si);
    di = 0x1528;
    sub_10590();
loc_111d1: // 1059:0c41
    si = memoryAGet16(es, bx + 248);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c0e))
        goto loc_111ea;
    memoryASet16(ds, 0x5c0e, si);
    di = 0x152a;
    sub_10590();
loc_111ea: // 1059:0c5a
    si = memoryAGet16(es, bx + 250);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c10))
        goto loc_11203;
    memoryASet16(ds, 0x5c10, si);
    di = 0x152c;
    sub_10590();
loc_11203: // 1059:0c73
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 252);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c12))
        goto loc_11220;
    memoryASet16(ds, 0x5c12, si);
    di = 0x1804;
    sub_10590();
loc_11220: // 1059:0c90
    si = memoryAGet16(es, bx + 254);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c14))
        goto loc_11239;
    memoryASet16(ds, 0x5c14, si);
    di = 0x1806;
    sub_10590();
loc_11239: // 1059:0ca9
    si = memoryAGet16(es, bx + 256);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c16))
        goto loc_11252;
    memoryASet16(ds, 0x5c16, si);
    di = 0x1808;
    sub_10590();
loc_11252: // 1059:0cc2
    si = memoryAGet16(es, bx + 258);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c18))
        goto loc_1126b;
    memoryASet16(ds, 0x5c18, si);
    di = 0x180a;
    sub_10590();
loc_1126b: // 1059:0cdb
    si = memoryAGet16(es, bx + 260);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c1a))
        goto loc_11284;
    memoryASet16(ds, 0x5c1a, si);
    di = 0x180c;
    sub_10590();
loc_11284: // 1059:0cf4
    si = memoryAGet16(es, bx + 262);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c1c))
        goto loc_1129d;
    memoryASet16(ds, 0x5c1c, si);
    di = 0x180e;
    sub_10590();
loc_1129d: // 1059:0d0d
    si = memoryAGet16(es, bx + 264);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c1e))
        goto loc_112b6;
    memoryASet16(ds, 0x5c1e, si);
    di = 0x1810;
    sub_10590();
loc_112b6: // 1059:0d26
    si = memoryAGet16(es, bx + 266);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c20))
        goto loc_112cf;
    memoryASet16(ds, 0x5c20, si);
    di = 0x1812;
    sub_10590();
loc_112cf: // 1059:0d3f
    si = memoryAGet16(es, bx + 268);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c22))
        goto loc_112e8;
    memoryASet16(ds, 0x5c22, si);
    di = 0x1814;
    sub_10590();
loc_112e8: // 1059:0d58
    si = memoryAGet16(es, bx + 270);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c24))
        goto loc_11301;
    memoryASet16(ds, 0x5c24, si);
    di = 0x1816;
    sub_10590();
loc_11301: // 1059:0d71
    si = memoryAGet16(es, bx + 272);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c26))
        goto loc_1131a;
    memoryASet16(ds, 0x5c26, si);
    di = 0x1818;
    sub_10590();
loc_1131a: // 1059:0d8a
    si = memoryAGet16(es, bx + 274);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c28))
        goto loc_11333;
    memoryASet16(ds, 0x5c28, si);
    di = 0x181a;
    sub_10590();
loc_11333: // 1059:0da3
    si = memoryAGet16(es, bx + 276);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c2a))
        goto loc_1134c;
    memoryASet16(ds, 0x5c2a, si);
    di = 0x181c;
    sub_10590();
loc_1134c: // 1059:0dbc
    si = memoryAGet16(es, bx + 278);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c2c))
        goto loc_11365;
    memoryASet16(ds, 0x5c2c, si);
    di = 0x181e;
    sub_10590();
loc_11365: // 1059:0dd5
    si = memoryAGet16(es, bx + 280);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c2e))
        goto loc_1137e;
    memoryASet16(ds, 0x5c2e, si);
    di = 0x1820;
    sub_10590();
loc_1137e: // 1059:0dee
    si = memoryAGet16(es, bx + 282);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c30))
        goto loc_11397;
    memoryASet16(ds, 0x5c30, si);
    di = 0x1822;
    sub_10590();
loc_11397: // 1059:0e07
    si = memoryAGet16(es, bx + 284);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c32))
        goto loc_113b0;
    memoryASet16(ds, 0x5c32, si);
    di = 0x1824;
    sub_10590();
loc_113b0: // 1059:0e20
    si = memoryAGet16(es, bx + 286);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c34))
        goto loc_113c9;
    memoryASet16(ds, 0x5c34, si);
    di = 0x1826;
    sub_10590();
loc_113c9: // 1059:0e39
    si = memoryAGet16(es, bx + 288);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c36))
        goto loc_113e2;
    memoryASet16(ds, 0x5c36, si);
    di = 0x1828;
    sub_10590();
loc_113e2: // 1059:0e52
    si = memoryAGet16(es, bx + 290);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c38))
        goto loc_113fb;
    memoryASet16(ds, 0x5c38, si);
    di = 0x182a;
    sub_10590();
loc_113fb: // 1059:0e6b
    si = memoryAGet16(es, bx + 292);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c3a))
        goto loc_11414;
    memoryASet16(ds, 0x5c3a, si);
    di = 0x182c;
    sub_10590();
loc_11414: // 1059:0e84
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 294);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c3c))
        goto loc_11431;
    memoryASet16(ds, 0x5c3c, si);
    di = 0x1b04;
    sub_10590();
loc_11431: // 1059:0ea1
    si = memoryAGet16(es, bx + 296);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c3e))
        goto loc_1144a;
    memoryASet16(ds, 0x5c3e, si);
    di = 0x1b06;
    sub_10590();
loc_1144a: // 1059:0eba
    si = memoryAGet16(es, bx + 298);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c40))
        goto loc_11463;
    memoryASet16(ds, 0x5c40, si);
    di = 0x1b08;
    sub_10590();
loc_11463: // 1059:0ed3
    si = memoryAGet16(es, bx + 300);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c42))
        goto loc_1147c;
    memoryASet16(ds, 0x5c42, si);
    di = 0x1b0a;
    sub_10590();
loc_1147c: // 1059:0eec
    si = memoryAGet16(es, bx + 302);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c44))
        goto loc_11495;
    memoryASet16(ds, 0x5c44, si);
    di = 0x1b0c;
    sub_10590();
loc_11495: // 1059:0f05
    si = memoryAGet16(es, bx + 304);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c46))
        goto loc_114ae;
    memoryASet16(ds, 0x5c46, si);
    di = 0x1b0e;
    sub_10590();
loc_114ae: // 1059:0f1e
    si = memoryAGet16(es, bx + 306);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c48))
        goto loc_114c7;
    memoryASet16(ds, 0x5c48, si);
    di = 0x1b10;
    sub_10590();
loc_114c7: // 1059:0f37
    si = memoryAGet16(es, bx + 308);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c4a))
        goto loc_114e0;
    memoryASet16(ds, 0x5c4a, si);
    di = 0x1b12;
    sub_10590();
loc_114e0: // 1059:0f50
    si = memoryAGet16(es, bx + 310);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c4c))
        goto loc_114f9;
    memoryASet16(ds, 0x5c4c, si);
    di = 0x1b14;
    sub_10590();
loc_114f9: // 1059:0f69
    si = memoryAGet16(es, bx + 312);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c4e))
        goto loc_11512;
    memoryASet16(ds, 0x5c4e, si);
    di = 0x1b16;
    sub_10590();
loc_11512: // 1059:0f82
    si = memoryAGet16(es, bx + 314);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c50))
        goto loc_1152b;
    memoryASet16(ds, 0x5c50, si);
    di = 0x1b18;
    sub_10590();
loc_1152b: // 1059:0f9b
    si = memoryAGet16(es, bx + 316);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c52))
        goto loc_11544;
    memoryASet16(ds, 0x5c52, si);
    di = 0x1b1a;
    sub_10590();
loc_11544: // 1059:0fb4
    si = memoryAGet16(es, bx + 318);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c54))
        goto loc_1155d;
    memoryASet16(ds, 0x5c54, si);
    di = 0x1b1c;
    sub_10590();
loc_1155d: // 1059:0fcd
    si = memoryAGet16(es, bx + 320);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c56))
        goto loc_11576;
    memoryASet16(ds, 0x5c56, si);
    di = 0x1b1e;
    sub_10590();
loc_11576: // 1059:0fe6
    si = memoryAGet16(es, bx + 322);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c58))
        goto loc_1158f;
    memoryASet16(ds, 0x5c58, si);
    di = 0x1b20;
    sub_10590();
loc_1158f: // 1059:0fff
    si = memoryAGet16(es, bx + 324);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c5a))
        goto loc_115a8;
    memoryASet16(ds, 0x5c5a, si);
    di = 0x1b22;
    sub_10590();
loc_115a8: // 1059:1018
    si = memoryAGet16(es, bx + 326);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c5c))
        goto loc_115c1;
    memoryASet16(ds, 0x5c5c, si);
    di = 0x1b24;
    sub_10590();
loc_115c1: // 1059:1031
    si = memoryAGet16(es, bx + 328);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c5e))
        goto loc_115da;
    memoryASet16(ds, 0x5c5e, si);
    di = 0x1b26;
    sub_10590();
loc_115da: // 1059:104a
    si = memoryAGet16(es, bx + 330);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c60))
        goto loc_115f3;
    memoryASet16(ds, 0x5c60, si);
    di = 0x1b28;
    sub_10590();
loc_115f3: // 1059:1063
    si = memoryAGet16(es, bx + 332);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c62))
        goto loc_1160c;
    memoryASet16(ds, 0x5c62, si);
    di = 0x1b2a;
    sub_10590();
loc_1160c: // 1059:107c
    si = memoryAGet16(es, bx + 334);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c64))
        goto loc_11625;
    memoryASet16(ds, 0x5c64, si);
    di = 0x1b2c;
    sub_10590();
loc_11625: // 1059:1095
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 336);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c66))
        goto loc_11642;
    memoryASet16(ds, 0x5c66, si);
    di = 0x1e04;
    sub_10590();
loc_11642: // 1059:10b2
    si = memoryAGet16(es, bx + 338);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c68))
        goto loc_1165b;
    memoryASet16(ds, 0x5c68, si);
    di = 0x1e06;
    sub_10590();
loc_1165b: // 1059:10cb
    si = memoryAGet16(es, bx + 340);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c6a))
        goto loc_11674;
    memoryASet16(ds, 0x5c6a, si);
    di = 0x1e08;
    sub_10590();
loc_11674: // 1059:10e4
    si = memoryAGet16(es, bx + 342);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c6c))
        goto loc_1168d;
    memoryASet16(ds, 0x5c6c, si);
    di = 0x1e0a;
    sub_10590();
loc_1168d: // 1059:10fd
    si = memoryAGet16(es, bx + 344);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c6e))
        goto loc_116a6;
    memoryASet16(ds, 0x5c6e, si);
    di = 0x1e0c;
    sub_10590();
loc_116a6: // 1059:1116
    si = memoryAGet16(es, bx + 346);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c70))
        goto loc_116bf;
    memoryASet16(ds, 0x5c70, si);
    di = 0x1e0e;
    sub_10590();
loc_116bf: // 1059:112f
    si = memoryAGet16(es, bx + 348);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c72))
        goto loc_116d8;
    memoryASet16(ds, 0x5c72, si);
    di = 0x1e10;
    sub_10590();
loc_116d8: // 1059:1148
    si = memoryAGet16(es, bx + 350);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c74))
        goto loc_116f1;
    memoryASet16(ds, 0x5c74, si);
    di = 0x1e12;
    sub_10590();
loc_116f1: // 1059:1161
    si = memoryAGet16(es, bx + 352);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c76))
        goto loc_1170a;
    memoryASet16(ds, 0x5c76, si);
    di = 0x1e14;
    sub_10590();
loc_1170a: // 1059:117a
    si = memoryAGet16(es, bx + 354);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c78))
        goto loc_11723;
    memoryASet16(ds, 0x5c78, si);
    di = 0x1e16;
    sub_10590();
loc_11723: // 1059:1193
    si = memoryAGet16(es, bx + 356);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c7a))
        goto loc_1173c;
    memoryASet16(ds, 0x5c7a, si);
    di = 0x1e18;
    sub_10590();
loc_1173c: // 1059:11ac
    si = memoryAGet16(es, bx + 358);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c7c))
        goto loc_11755;
    memoryASet16(ds, 0x5c7c, si);
    di = 0x1e1a;
    sub_10590();
loc_11755: // 1059:11c5
    si = memoryAGet16(es, bx + 360);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c7e))
        goto loc_1176e;
    memoryASet16(ds, 0x5c7e, si);
    di = 0x1e1c;
    sub_10590();
loc_1176e: // 1059:11de
    si = memoryAGet16(es, bx + 362);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c80))
        goto loc_11787;
    memoryASet16(ds, 0x5c80, si);
    di = 0x1e1e;
    sub_10590();
loc_11787: // 1059:11f7
    si = memoryAGet16(es, bx + 364);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c82))
        goto loc_117a0;
    memoryASet16(ds, 0x5c82, si);
    di = 0x1e20;
    sub_10590();
loc_117a0: // 1059:1210
    si = memoryAGet16(es, bx + 366);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c84))
        goto loc_117b9;
    memoryASet16(ds, 0x5c84, si);
    di = 0x1e22;
    sub_10590();
loc_117b9: // 1059:1229
    si = memoryAGet16(es, bx + 368);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c86))
        goto loc_117d2;
    memoryASet16(ds, 0x5c86, si);
    di = 0x1e24;
    sub_10590();
loc_117d2: // 1059:1242
    si = memoryAGet16(es, bx + 370);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c88))
        goto loc_117eb;
    memoryASet16(ds, 0x5c88, si);
    di = 0x1e26;
    sub_10590();
loc_117eb: // 1059:125b
    si = memoryAGet16(es, bx + 372);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c8a))
        goto loc_11804;
    memoryASet16(ds, 0x5c8a, si);
    di = 0x1e28;
    sub_10590();
loc_11804: // 1059:1274
    si = memoryAGet16(es, bx + 374);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c8c))
        goto loc_1181d;
    memoryASet16(ds, 0x5c8c, si);
    di = 0x1e2a;
    sub_10590();
loc_1181d: // 1059:128d
    si = memoryAGet16(es, bx + 376);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c8e))
        goto loc_11836;
    memoryASet16(ds, 0x5c8e, si);
    di = 0x1e2c;
    sub_10590();
loc_11836: // 1059:12a6
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 378);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c90))
        goto loc_11853;
    memoryASet16(ds, 0x5c90, si);
    di = 0x2104;
    sub_10590();
loc_11853: // 1059:12c3
    si = memoryAGet16(es, bx + 380);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c92))
        goto loc_1186c;
    memoryASet16(ds, 0x5c92, si);
    di = 0x2106;
    sub_10590();
loc_1186c: // 1059:12dc
    si = memoryAGet16(es, bx + 382);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c94))
        goto loc_11885;
    memoryASet16(ds, 0x5c94, si);
    di = 0x2108;
    sub_10590();
loc_11885: // 1059:12f5
    si = memoryAGet16(es, bx + 384);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c96))
        goto loc_1189e;
    memoryASet16(ds, 0x5c96, si);
    di = 0x210a;
    sub_10590();
loc_1189e: // 1059:130e
    si = memoryAGet16(es, bx + 386);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c98))
        goto loc_118b7;
    memoryASet16(ds, 0x5c98, si);
    di = 0x210c;
    sub_10590();
loc_118b7: // 1059:1327
    si = memoryAGet16(es, bx + 388);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c9a))
        goto loc_118d0;
    memoryASet16(ds, 0x5c9a, si);
    di = 0x210e;
    sub_10590();
loc_118d0: // 1059:1340
    si = memoryAGet16(es, bx + 390);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c9c))
        goto loc_118e9;
    memoryASet16(ds, 0x5c9c, si);
    di = 0x2110;
    sub_10590();
loc_118e9: // 1059:1359
    si = memoryAGet16(es, bx + 392);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5c9e))
        goto loc_11902;
    memoryASet16(ds, 0x5c9e, si);
    di = 0x2112;
    sub_10590();
loc_11902: // 1059:1372
    si = memoryAGet16(es, bx + 394);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ca0))
        goto loc_1191b;
    memoryASet16(ds, 0x5ca0, si);
    di = 0x2114;
    sub_10590();
loc_1191b: // 1059:138b
    si = memoryAGet16(es, bx + 396);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ca2))
        goto loc_11934;
    memoryASet16(ds, 0x5ca2, si);
    di = 0x2116;
    sub_10590();
loc_11934: // 1059:13a4
    si = memoryAGet16(es, bx + 398);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ca4))
        goto loc_1194d;
    memoryASet16(ds, 0x5ca4, si);
    di = 0x2118;
    sub_10590();
loc_1194d: // 1059:13bd
    si = memoryAGet16(es, bx + 400);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ca6))
        goto loc_11966;
    memoryASet16(ds, 0x5ca6, si);
    di = 0x211a;
    sub_10590();
loc_11966: // 1059:13d6
    si = memoryAGet16(es, bx + 402);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ca8))
        goto loc_1197f;
    memoryASet16(ds, 0x5ca8, si);
    di = 0x211c;
    sub_10590();
loc_1197f: // 1059:13ef
    si = memoryAGet16(es, bx + 404);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5caa))
        goto loc_11998;
    memoryASet16(ds, 0x5caa, si);
    di = 0x211e;
    sub_10590();
loc_11998: // 1059:1408
    si = memoryAGet16(es, bx + 406);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cac))
        goto loc_119b1;
    memoryASet16(ds, 0x5cac, si);
    di = 0x2120;
    sub_10590();
loc_119b1: // 1059:1421
    si = memoryAGet16(es, bx + 408);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cae))
        goto loc_119ca;
    memoryASet16(ds, 0x5cae, si);
    di = 0x2122;
    sub_10590();
loc_119ca: // 1059:143a
    si = memoryAGet16(es, bx + 410);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cb0))
        goto loc_119e3;
    memoryASet16(ds, 0x5cb0, si);
    di = 0x2124;
    sub_10590();
loc_119e3: // 1059:1453
    si = memoryAGet16(es, bx + 412);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cb2))
        goto loc_119fc;
    memoryASet16(ds, 0x5cb2, si);
    di = 0x2126;
    sub_10590();
loc_119fc: // 1059:146c
    si = memoryAGet16(es, bx + 414);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cb4))
        goto loc_11a15;
    memoryASet16(ds, 0x5cb4, si);
    di = 0x2128;
    sub_10590();
loc_11a15: // 1059:1485
    si = memoryAGet16(es, bx + 416);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cb6))
        goto loc_11a2e;
    memoryASet16(ds, 0x5cb6, si);
    di = 0x212a;
    sub_10590();
loc_11a2e: // 1059:149e
    si = memoryAGet16(es, bx + 418);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cb8))
        goto loc_11a47;
    memoryASet16(ds, 0x5cb8, si);
    di = 0x212c;
    sub_10590();
loc_11a47: // 1059:14b7
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 420);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cba))
        goto loc_11a64;
    memoryASet16(ds, 0x5cba, si);
    di = 0x2404;
    sub_10590();
loc_11a64: // 1059:14d4
    si = memoryAGet16(es, bx + 422);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cbc))
        goto loc_11a7d;
    memoryASet16(ds, 0x5cbc, si);
    di = 0x2406;
    sub_10590();
loc_11a7d: // 1059:14ed
    si = memoryAGet16(es, bx + 424);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cbe))
        goto loc_11a96;
    memoryASet16(ds, 0x5cbe, si);
    di = 0x2408;
    sub_10590();
loc_11a96: // 1059:1506
    si = memoryAGet16(es, bx + 426);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cc0))
        goto loc_11aaf;
    memoryASet16(ds, 0x5cc0, si);
    di = 0x240a;
    sub_10590();
loc_11aaf: // 1059:151f
    si = memoryAGet16(es, bx + 428);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cc2))
        goto loc_11ac8;
    memoryASet16(ds, 0x5cc2, si);
    di = 0x240c;
    sub_10590();
loc_11ac8: // 1059:1538
    si = memoryAGet16(es, bx + 430);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cc4))
        goto loc_11ae1;
    memoryASet16(ds, 0x5cc4, si);
    di = 0x240e;
    sub_10590();
loc_11ae1: // 1059:1551
    si = memoryAGet16(es, bx + 432);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cc6))
        goto loc_11afa;
    memoryASet16(ds, 0x5cc6, si);
    di = 0x2410;
    sub_10590();
loc_11afa: // 1059:156a
    si = memoryAGet16(es, bx + 434);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cc8))
        goto loc_11b13;
    memoryASet16(ds, 0x5cc8, si);
    di = 0x2412;
    sub_10590();
loc_11b13: // 1059:1583
    si = memoryAGet16(es, bx + 436);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cca))
        goto loc_11b2c;
    memoryASet16(ds, 0x5cca, si);
    di = 0x2414;
    sub_10590();
loc_11b2c: // 1059:159c
    si = memoryAGet16(es, bx + 438);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ccc))
        goto loc_11b45;
    memoryASet16(ds, 0x5ccc, si);
    di = 0x2416;
    sub_10590();
loc_11b45: // 1059:15b5
    si = memoryAGet16(es, bx + 440);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cce))
        goto loc_11b5e;
    memoryASet16(ds, 0x5cce, si);
    di = 0x2418;
    sub_10590();
loc_11b5e: // 1059:15ce
    si = memoryAGet16(es, bx + 442);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cd0))
        goto loc_11b77;
    memoryASet16(ds, 0x5cd0, si);
    di = 0x241a;
    sub_10590();
loc_11b77: // 1059:15e7
    si = memoryAGet16(es, bx + 444);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cd2))
        goto loc_11b90;
    memoryASet16(ds, 0x5cd2, si);
    di = 0x241c;
    sub_10590();
loc_11b90: // 1059:1600
    si = memoryAGet16(es, bx + 446);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cd4))
        goto loc_11ba9;
    memoryASet16(ds, 0x5cd4, si);
    di = 0x241e;
    sub_10590();
loc_11ba9: // 1059:1619
    si = memoryAGet16(es, bx + 448);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cd6))
        goto loc_11bc2;
    memoryASet16(ds, 0x5cd6, si);
    di = 0x2420;
    sub_10590();
loc_11bc2: // 1059:1632
    si = memoryAGet16(es, bx + 450);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cd8))
        goto loc_11bdb;
    memoryASet16(ds, 0x5cd8, si);
    di = 0x2422;
    sub_10590();
loc_11bdb: // 1059:164b
    si = memoryAGet16(es, bx + 452);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cda))
        goto loc_11bf4;
    memoryASet16(ds, 0x5cda, si);
    di = 0x2424;
    sub_10590();
loc_11bf4: // 1059:1664
    si = memoryAGet16(es, bx + 454);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cdc))
        goto loc_11c0d;
    memoryASet16(ds, 0x5cdc, si);
    di = 0x2426;
    sub_10590();
loc_11c0d: // 1059:167d
    si = memoryAGet16(es, bx + 456);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cde))
        goto loc_11c26;
    memoryASet16(ds, 0x5cde, si);
    di = 0x2428;
    sub_10590();
loc_11c26: // 1059:1696
    si = memoryAGet16(es, bx + 458);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ce0))
        goto loc_11c3f;
    memoryASet16(ds, 0x5ce0, si);
    di = 0x242a;
    sub_10590();
loc_11c3f: // 1059:16af
    si = memoryAGet16(es, bx + 460);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ce2))
        goto loc_11c58;
    memoryASet16(ds, 0x5ce2, si);
    di = 0x242c;
    sub_10590();
loc_11c58: // 1059:16c8
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 462);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ce4))
        goto loc_11c75;
    memoryASet16(ds, 0x5ce4, si);
    di = 0x2704;
    sub_10590();
loc_11c75: // 1059:16e5
    si = memoryAGet16(es, bx + 464);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ce6))
        goto loc_11c8e;
    memoryASet16(ds, 0x5ce6, si);
    di = 0x2706;
    sub_10590();
loc_11c8e: // 1059:16fe
    si = memoryAGet16(es, bx + 466);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ce8))
        goto loc_11ca7;
    memoryASet16(ds, 0x5ce8, si);
    di = 0x2708;
    sub_10590();
loc_11ca7: // 1059:1717
    si = memoryAGet16(es, bx + 468);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cea))
        goto loc_11cc0;
    memoryASet16(ds, 0x5cea, si);
    di = 0x270a;
    sub_10590();
loc_11cc0: // 1059:1730
    si = memoryAGet16(es, bx + 470);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cec))
        goto loc_11cd9;
    memoryASet16(ds, 0x5cec, si);
    di = 0x270c;
    sub_10590();
loc_11cd9: // 1059:1749
    si = memoryAGet16(es, bx + 472);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cee))
        goto loc_11cf2;
    memoryASet16(ds, 0x5cee, si);
    di = 0x270e;
    sub_10590();
loc_11cf2: // 1059:1762
    si = memoryAGet16(es, bx + 474);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cf0))
        goto loc_11d0b;
    memoryASet16(ds, 0x5cf0, si);
    di = 0x2710;
    sub_10590();
loc_11d0b: // 1059:177b
    si = memoryAGet16(es, bx + 476);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cf2))
        goto loc_11d24;
    memoryASet16(ds, 0x5cf2, si);
    di = 0x2712;
    sub_10590();
loc_11d24: // 1059:1794
    si = memoryAGet16(es, bx + 478);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cf4))
        goto loc_11d3d;
    memoryASet16(ds, 0x5cf4, si);
    di = 0x2714;
    sub_10590();
loc_11d3d: // 1059:17ad
    si = memoryAGet16(es, bx + 480);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cf6))
        goto loc_11d56;
    memoryASet16(ds, 0x5cf6, si);
    di = 0x2716;
    sub_10590();
loc_11d56: // 1059:17c6
    si = memoryAGet16(es, bx + 482);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cf8))
        goto loc_11d6f;
    memoryASet16(ds, 0x5cf8, si);
    di = 0x2718;
    sub_10590();
loc_11d6f: // 1059:17df
    si = memoryAGet16(es, bx + 484);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cfa))
        goto loc_11d88;
    memoryASet16(ds, 0x5cfa, si);
    di = 0x271a;
    sub_10590();
loc_11d88: // 1059:17f8
    si = memoryAGet16(es, bx + 486);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cfc))
        goto loc_11da1;
    memoryASet16(ds, 0x5cfc, si);
    di = 0x271c;
    sub_10590();
loc_11da1: // 1059:1811
    si = memoryAGet16(es, bx + 488);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5cfe))
        goto loc_11dba;
    memoryASet16(ds, 0x5cfe, si);
    di = 0x271e;
    sub_10590();
loc_11dba: // 1059:182a
    si = memoryAGet16(es, bx + 490);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d00))
        goto loc_11dd3;
    memoryASet16(ds, 0x5d00, si);
    di = 0x2720;
    sub_10590();
loc_11dd3: // 1059:1843
    si = memoryAGet16(es, bx + 492);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d02))
        goto loc_11dec;
    memoryASet16(ds, 0x5d02, si);
    di = 0x2722;
    sub_10590();
loc_11dec: // 1059:185c
    si = memoryAGet16(es, bx + 494);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d04))
        goto loc_11e05;
    memoryASet16(ds, 0x5d04, si);
    di = 0x2724;
    sub_10590();
loc_11e05: // 1059:1875
    si = memoryAGet16(es, bx + 496);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d06))
        goto loc_11e1e;
    memoryASet16(ds, 0x5d06, si);
    di = 0x2726;
    sub_10590();
loc_11e1e: // 1059:188e
    si = memoryAGet16(es, bx + 498);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d08))
        goto loc_11e37;
    memoryASet16(ds, 0x5d08, si);
    di = 0x2728;
    sub_10590();
loc_11e37: // 1059:18a7
    si = memoryAGet16(es, bx + 500);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d0a))
        goto loc_11e50;
    memoryASet16(ds, 0x5d0a, si);
    di = 0x272a;
    sub_10590();
loc_11e50: // 1059:18c0
    si = memoryAGet16(es, bx + 502);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d0c))
        goto loc_11e69;
    memoryASet16(ds, 0x5d0c, si);
    di = 0x272c;
    sub_10590();
loc_11e69: // 1059:18d9
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 504);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d0e))
        goto loc_11e86;
    memoryASet16(ds, 0x5d0e, si);
    di = 0x2a04;
    sub_10590();
loc_11e86: // 1059:18f6
    si = memoryAGet16(es, bx + 506);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d10))
        goto loc_11e9f;
    memoryASet16(ds, 0x5d10, si);
    di = 0x2a06;
    sub_10590();
loc_11e9f: // 1059:190f
    si = memoryAGet16(es, bx + 508);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d12))
        goto loc_11eb8;
    memoryASet16(ds, 0x5d12, si);
    di = 0x2a08;
    sub_10590();
loc_11eb8: // 1059:1928
    si = memoryAGet16(es, bx + 510);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d14))
        goto loc_11ed1;
    memoryASet16(ds, 0x5d14, si);
    di = 0x2a0a;
    sub_10590();
loc_11ed1: // 1059:1941
    si = memoryAGet16(es, bx + 512);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d16))
        goto loc_11eea;
    memoryASet16(ds, 0x5d16, si);
    di = 0x2a0c;
    sub_10590();
loc_11eea: // 1059:195a
    si = memoryAGet16(es, bx + 514);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d18))
        goto loc_11f03;
    memoryASet16(ds, 0x5d18, si);
    di = 0x2a0e;
    sub_10590();
loc_11f03: // 1059:1973
    si = memoryAGet16(es, bx + 516);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d1a))
        goto loc_11f1c;
    memoryASet16(ds, 0x5d1a, si);
    di = 0x2a10;
    sub_10590();
loc_11f1c: // 1059:198c
    si = memoryAGet16(es, bx + 518);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d1c))
        goto loc_11f35;
    memoryASet16(ds, 0x5d1c, si);
    di = 0x2a12;
    sub_10590();
loc_11f35: // 1059:19a5
    si = memoryAGet16(es, bx + 520);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d1e))
        goto loc_11f4e;
    memoryASet16(ds, 0x5d1e, si);
    di = 0x2a14;
    sub_10590();
loc_11f4e: // 1059:19be
    si = memoryAGet16(es, bx + 522);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d20))
        goto loc_11f67;
    memoryASet16(ds, 0x5d20, si);
    di = 0x2a16;
    sub_10590();
loc_11f67: // 1059:19d7
    si = memoryAGet16(es, bx + 524);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d22))
        goto loc_11f80;
    memoryASet16(ds, 0x5d22, si);
    di = 0x2a18;
    sub_10590();
loc_11f80: // 1059:19f0
    si = memoryAGet16(es, bx + 526);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d24))
        goto loc_11f99;
    memoryASet16(ds, 0x5d24, si);
    di = 0x2a1a;
    sub_10590();
loc_11f99: // 1059:1a09
    si = memoryAGet16(es, bx + 528);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d26))
        goto loc_11fb2;
    memoryASet16(ds, 0x5d26, si);
    di = 0x2a1c;
    sub_10590();
loc_11fb2: // 1059:1a22
    si = memoryAGet16(es, bx + 530);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d28))
        goto loc_11fcb;
    memoryASet16(ds, 0x5d28, si);
    di = 0x2a1e;
    sub_10590();
loc_11fcb: // 1059:1a3b
    si = memoryAGet16(es, bx + 532);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d2a))
        goto loc_11fe4;
    memoryASet16(ds, 0x5d2a, si);
    di = 0x2a20;
    sub_10590();
loc_11fe4: // 1059:1a54
    si = memoryAGet16(es, bx + 534);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d2c))
        goto loc_11ffd;
    memoryASet16(ds, 0x5d2c, si);
    di = 0x2a22;
    sub_10590();
loc_11ffd: // 1059:1a6d
    si = memoryAGet16(es, bx + 536);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d2e))
        goto loc_12016;
    memoryASet16(ds, 0x5d2e, si);
    di = 0x2a24;
    sub_10590();
loc_12016: // 1059:1a86
    si = memoryAGet16(es, bx + 538);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d30))
        goto loc_1202f;
    memoryASet16(ds, 0x5d30, si);
    di = 0x2a26;
    sub_10590();
loc_1202f: // 1059:1a9f
    si = memoryAGet16(es, bx + 540);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d32))
        goto loc_12048;
    memoryASet16(ds, 0x5d32, si);
    di = 0x2a28;
    sub_10590();
loc_12048: // 1059:1ab8
    si = memoryAGet16(es, bx + 542);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d34))
        goto loc_12061;
    memoryASet16(ds, 0x5d34, si);
    di = 0x2a2a;
    sub_10590();
loc_12061: // 1059:1ad1
    si = memoryAGet16(es, bx + 544);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d36))
        goto loc_1207a;
    memoryASet16(ds, 0x5d36, si);
    di = 0x2a2c;
    sub_10590();
loc_1207a: // 1059:1aea
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 546);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d38))
        goto loc_12097;
    memoryASet16(ds, 0x5d38, si);
    di = 0x2d04;
    sub_10590();
loc_12097: // 1059:1b07
    si = memoryAGet16(es, bx + 548);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d3a))
        goto loc_120b0;
    memoryASet16(ds, 0x5d3a, si);
    di = 0x2d06;
    sub_10590();
loc_120b0: // 1059:1b20
    si = memoryAGet16(es, bx + 550);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d3c))
        goto loc_120c9;
    memoryASet16(ds, 0x5d3c, si);
    di = 0x2d08;
    sub_10590();
loc_120c9: // 1059:1b39
    si = memoryAGet16(es, bx + 552);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d3e))
        goto loc_120e2;
    memoryASet16(ds, 0x5d3e, si);
    di = 0x2d0a;
    sub_10590();
loc_120e2: // 1059:1b52
    si = memoryAGet16(es, bx + 554);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d40))
        goto loc_120fb;
    memoryASet16(ds, 0x5d40, si);
    di = 0x2d0c;
    sub_10590();
loc_120fb: // 1059:1b6b
    si = memoryAGet16(es, bx + 556);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d42))
        goto loc_12114;
    memoryASet16(ds, 0x5d42, si);
    di = 0x2d0e;
    sub_10590();
loc_12114: // 1059:1b84
    si = memoryAGet16(es, bx + 558);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d44))
        goto loc_1212d;
    memoryASet16(ds, 0x5d44, si);
    di = 0x2d10;
    sub_10590();
loc_1212d: // 1059:1b9d
    si = memoryAGet16(es, bx + 560);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d46))
        goto loc_12146;
    memoryASet16(ds, 0x5d46, si);
    di = 0x2d12;
    sub_10590();
loc_12146: // 1059:1bb6
    si = memoryAGet16(es, bx + 562);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d48))
        goto loc_1215f;
    memoryASet16(ds, 0x5d48, si);
    di = 0x2d14;
    sub_10590();
loc_1215f: // 1059:1bcf
    si = memoryAGet16(es, bx + 564);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d4a))
        goto loc_12178;
    memoryASet16(ds, 0x5d4a, si);
    di = 0x2d16;
    sub_10590();
loc_12178: // 1059:1be8
    si = memoryAGet16(es, bx + 566);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d4c))
        goto loc_12191;
    memoryASet16(ds, 0x5d4c, si);
    di = 0x2d18;
    sub_10590();
loc_12191: // 1059:1c01
    si = memoryAGet16(es, bx + 568);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d4e))
        goto loc_121aa;
    memoryASet16(ds, 0x5d4e, si);
    di = 0x2d1a;
    sub_10590();
loc_121aa: // 1059:1c1a
    si = memoryAGet16(es, bx + 570);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d50))
        goto loc_121c3;
    memoryASet16(ds, 0x5d50, si);
    di = 0x2d1c;
    sub_10590();
loc_121c3: // 1059:1c33
    si = memoryAGet16(es, bx + 572);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d52))
        goto loc_121dc;
    memoryASet16(ds, 0x5d52, si);
    di = 0x2d1e;
    sub_10590();
loc_121dc: // 1059:1c4c
    si = memoryAGet16(es, bx + 574);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d54))
        goto loc_121f5;
    memoryASet16(ds, 0x5d54, si);
    di = 0x2d20;
    sub_10590();
loc_121f5: // 1059:1c65
    si = memoryAGet16(es, bx + 576);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d56))
        goto loc_1220e;
    memoryASet16(ds, 0x5d56, si);
    di = 0x2d22;
    sub_10590();
loc_1220e: // 1059:1c7e
    si = memoryAGet16(es, bx + 578);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d58))
        goto loc_12227;
    memoryASet16(ds, 0x5d58, si);
    di = 0x2d24;
    sub_10590();
loc_12227: // 1059:1c97
    si = memoryAGet16(es, bx + 580);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d5a))
        goto loc_12240;
    memoryASet16(ds, 0x5d5a, si);
    di = 0x2d26;
    sub_10590();
loc_12240: // 1059:1cb0
    si = memoryAGet16(es, bx + 582);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d5c))
        goto loc_12259;
    memoryASet16(ds, 0x5d5c, si);
    di = 0x2d28;
    sub_10590();
loc_12259: // 1059:1cc9
    si = memoryAGet16(es, bx + 584);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d5e))
        goto loc_12272;
    memoryASet16(ds, 0x5d5e, si);
    di = 0x2d2a;
    sub_10590();
loc_12272: // 1059:1ce2
    si = memoryAGet16(es, bx + 586);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5d60))
        goto loc_1228b;
    memoryASet16(ds, 0x5d60, si);
    di = 0x2d2c;
    sub_10590();
loc_1228b: // 1059:1cfb
    bx += memoryAGet16(ds, 0x5654);
    cs = pop();
}
void sub_12290() // 1059:1d00 +far
{
    dx = 0x002e;
    cx = es;
    si = memoryAGet16(es, bx);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5db8))
        goto loc_122ac;
    memoryASet16(ds, 0x5db8, si);
    di = 0x0604;
    sub_10590();
loc_122ac: // 1059:1d1c
    si = memoryAGet16(es, bx + 2);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dba))
        goto loc_122c4;
    memoryASet16(ds, 0x5dba, si);
    di = 0x0606;
    sub_10590();
loc_122c4: // 1059:1d34
    si = memoryAGet16(es, bx + 4);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dbc))
        goto loc_122dc;
    memoryASet16(ds, 0x5dbc, si);
    di = 0x0608;
    sub_10590();
loc_122dc: // 1059:1d4c
    si = memoryAGet16(es, bx + 6);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dbe))
        goto loc_122f4;
    memoryASet16(ds, 0x5dbe, si);
    di = 0x060a;
    sub_10590();
loc_122f4: // 1059:1d64
    si = memoryAGet16(es, bx + 8);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dc0))
        goto loc_1230c;
    memoryASet16(ds, 0x5dc0, si);
    di = 0x060c;
    sub_10590();
loc_1230c: // 1059:1d7c
    si = memoryAGet16(es, bx + 10);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dc2))
        goto loc_12324;
    memoryASet16(ds, 0x5dc2, si);
    di = 0x060e;
    sub_10590();
loc_12324: // 1059:1d94
    si = memoryAGet16(es, bx + 12);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dc4))
        goto loc_1233c;
    memoryASet16(ds, 0x5dc4, si);
    di = 0x0610;
    sub_10590();
loc_1233c: // 1059:1dac
    si = memoryAGet16(es, bx + 14);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dc6))
        goto loc_12354;
    memoryASet16(ds, 0x5dc6, si);
    di = 0x0612;
    sub_10590();
loc_12354: // 1059:1dc4
    si = memoryAGet16(es, bx + 16);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dc8))
        goto loc_1236c;
    memoryASet16(ds, 0x5dc8, si);
    di = 0x0614;
    sub_10590();
loc_1236c: // 1059:1ddc
    si = memoryAGet16(es, bx + 18);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dca))
        goto loc_12384;
    memoryASet16(ds, 0x5dca, si);
    di = 0x0616;
    sub_10590();
loc_12384: // 1059:1df4
    si = memoryAGet16(es, bx + 20);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dcc))
        goto loc_1239c;
    memoryASet16(ds, 0x5dcc, si);
    di = 0x0618;
    sub_10590();
loc_1239c: // 1059:1e0c
    si = memoryAGet16(es, bx + 22);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dce))
        goto loc_123b4;
    memoryASet16(ds, 0x5dce, si);
    di = 0x061a;
    sub_10590();
loc_123b4: // 1059:1e24
    si = memoryAGet16(es, bx + 24);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dd0))
        goto loc_123cc;
    memoryASet16(ds, 0x5dd0, si);
    di = 0x061c;
    sub_10590();
loc_123cc: // 1059:1e3c
    si = memoryAGet16(es, bx + 26);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dd2))
        goto loc_123e4;
    memoryASet16(ds, 0x5dd2, si);
    di = 0x061e;
    sub_10590();
loc_123e4: // 1059:1e54
    si = memoryAGet16(es, bx + 28);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dd4))
        goto loc_123fc;
    memoryASet16(ds, 0x5dd4, si);
    di = 0x0620;
    sub_10590();
loc_123fc: // 1059:1e6c
    si = memoryAGet16(es, bx + 30);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dd6))
        goto loc_12414;
    memoryASet16(ds, 0x5dd6, si);
    di = 0x0622;
    sub_10590();
loc_12414: // 1059:1e84
    si = memoryAGet16(es, bx + 32);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dd8))
        goto loc_1242c;
    memoryASet16(ds, 0x5dd8, si);
    di = 0x0624;
    sub_10590();
loc_1242c: // 1059:1e9c
    si = memoryAGet16(es, bx + 34);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dda))
        goto loc_12444;
    memoryASet16(ds, 0x5dda, si);
    di = 0x0626;
    sub_10590();
loc_12444: // 1059:1eb4
    si = memoryAGet16(es, bx + 36);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ddc))
        goto loc_1245c;
    memoryASet16(ds, 0x5ddc, si);
    di = 0x0628;
    sub_10590();
loc_1245c: // 1059:1ecc
    si = memoryAGet16(es, bx + 38);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dde))
        goto loc_12474;
    memoryASet16(ds, 0x5dde, si);
    di = 0x062a;
    sub_10590();
loc_12474: // 1059:1ee4
    si = memoryAGet16(es, bx + 40);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5de0))
        goto loc_1248c;
    memoryASet16(ds, 0x5de0, si);
    di = 0x062c;
    sub_10590();
loc_1248c: // 1059:1efc
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 42);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5de2))
        goto loc_124a8;
    memoryASet16(ds, 0x5de2, si);
    di = 0x0904;
    sub_10590();
loc_124a8: // 1059:1f18
    si = memoryAGet16(es, bx + 44);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5de4))
        goto loc_124c0;
    memoryASet16(ds, 0x5de4, si);
    di = 0x0906;
    sub_10590();
loc_124c0: // 1059:1f30
    si = memoryAGet16(es, bx + 46);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5de6))
        goto loc_124d8;
    memoryASet16(ds, 0x5de6, si);
    di = 0x0908;
    sub_10590();
loc_124d8: // 1059:1f48
    si = memoryAGet16(es, bx + 48);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5de8))
        goto loc_124f0;
    memoryASet16(ds, 0x5de8, si);
    di = 0x090a;
    sub_10590();
loc_124f0: // 1059:1f60
    si = memoryAGet16(es, bx + 50);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dea))
        goto loc_12508;
    memoryASet16(ds, 0x5dea, si);
    di = 0x090c;
    sub_10590();
loc_12508: // 1059:1f78
    si = memoryAGet16(es, bx + 52);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dec))
        goto loc_12520;
    memoryASet16(ds, 0x5dec, si);
    di = 0x090e;
    sub_10590();
loc_12520: // 1059:1f90
    si = memoryAGet16(es, bx + 54);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dee))
        goto loc_12538;
    memoryASet16(ds, 0x5dee, si);
    di = 0x0910;
    sub_10590();
loc_12538: // 1059:1fa8
    si = memoryAGet16(es, bx + 56);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5df0))
        goto loc_12550;
    memoryASet16(ds, 0x5df0, si);
    di = 0x0912;
    sub_10590();
loc_12550: // 1059:1fc0
    si = memoryAGet16(es, bx + 58);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5df2))
        goto loc_12568;
    memoryASet16(ds, 0x5df2, si);
    di = 0x0914;
    sub_10590();
loc_12568: // 1059:1fd8
    si = memoryAGet16(es, bx + 60);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5df4))
        goto loc_12580;
    memoryASet16(ds, 0x5df4, si);
    di = 0x0916;
    sub_10590();
loc_12580: // 1059:1ff0
    si = memoryAGet16(es, bx + 62);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5df6))
        goto loc_12598;
    memoryASet16(ds, 0x5df6, si);
    di = 0x0918;
    sub_10590();
loc_12598: // 1059:2008
    si = memoryAGet16(es, bx + 64);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5df8))
        goto loc_125b0;
    memoryASet16(ds, 0x5df8, si);
    di = 0x091a;
    sub_10590();
loc_125b0: // 1059:2020
    si = memoryAGet16(es, bx + 66);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dfa))
        goto loc_125c8;
    memoryASet16(ds, 0x5dfa, si);
    di = 0x091c;
    sub_10590();
loc_125c8: // 1059:2038
    si = memoryAGet16(es, bx + 68);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dfc))
        goto loc_125e0;
    memoryASet16(ds, 0x5dfc, si);
    di = 0x091e;
    sub_10590();
loc_125e0: // 1059:2050
    si = memoryAGet16(es, bx + 70);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5dfe))
        goto loc_125f8;
    memoryASet16(ds, 0x5dfe, si);
    di = 0x0920;
    sub_10590();
loc_125f8: // 1059:2068
    si = memoryAGet16(es, bx + 72);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e00))
        goto loc_12610;
    memoryASet16(ds, 0x5e00, si);
    di = 0x0922;
    sub_10590();
loc_12610: // 1059:2080
    si = memoryAGet16(es, bx + 74);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e02))
        goto loc_12628;
    memoryASet16(ds, 0x5e02, si);
    di = 0x0924;
    sub_10590();
loc_12628: // 1059:2098
    si = memoryAGet16(es, bx + 76);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e04))
        goto loc_12640;
    memoryASet16(ds, 0x5e04, si);
    di = 0x0926;
    sub_10590();
loc_12640: // 1059:20b0
    si = memoryAGet16(es, bx + 78);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e06))
        goto loc_12658;
    memoryASet16(ds, 0x5e06, si);
    di = 0x0928;
    sub_10590();
loc_12658: // 1059:20c8
    si = memoryAGet16(es, bx + 80);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e08))
        goto loc_12670;
    memoryASet16(ds, 0x5e08, si);
    di = 0x092a;
    sub_10590();
loc_12670: // 1059:20e0
    si = memoryAGet16(es, bx + 82);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e0a))
        goto loc_12688;
    memoryASet16(ds, 0x5e0a, si);
    di = 0x092c;
    sub_10590();
loc_12688: // 1059:20f8
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 84);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e0c))
        goto loc_126a4;
    memoryASet16(ds, 0x5e0c, si);
    di = 0x0c04;
    sub_10590();
loc_126a4: // 1059:2114
    si = memoryAGet16(es, bx + 86);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e0e))
        goto loc_126bc;
    memoryASet16(ds, 0x5e0e, si);
    di = 0x0c06;
    sub_10590();
loc_126bc: // 1059:212c
    si = memoryAGet16(es, bx + 88);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e10))
        goto loc_126d4;
    memoryASet16(ds, 0x5e10, si);
    di = 0x0c08;
    sub_10590();
loc_126d4: // 1059:2144
    si = memoryAGet16(es, bx + 90);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e12))
        goto loc_126ec;
    memoryASet16(ds, 0x5e12, si);
    di = 0x0c0a;
    sub_10590();
loc_126ec: // 1059:215c
    si = memoryAGet16(es, bx + 92);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e14))
        goto loc_12704;
    memoryASet16(ds, 0x5e14, si);
    di = 0x0c0c;
    sub_10590();
loc_12704: // 1059:2174
    si = memoryAGet16(es, bx + 94);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e16))
        goto loc_1271c;
    memoryASet16(ds, 0x5e16, si);
    di = 0x0c0e;
    sub_10590();
loc_1271c: // 1059:218c
    si = memoryAGet16(es, bx + 96);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e18))
        goto loc_12734;
    memoryASet16(ds, 0x5e18, si);
    di = 0x0c10;
    sub_10590();
loc_12734: // 1059:21a4
    si = memoryAGet16(es, bx + 98);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e1a))
        goto loc_1274c;
    memoryASet16(ds, 0x5e1a, si);
    di = 0x0c12;
    sub_10590();
loc_1274c: // 1059:21bc
    si = memoryAGet16(es, bx + 100);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e1c))
        goto loc_12764;
    memoryASet16(ds, 0x5e1c, si);
    di = 0x0c14;
    sub_10590();
loc_12764: // 1059:21d4
    si = memoryAGet16(es, bx + 102);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e1e))
        goto loc_1277c;
    memoryASet16(ds, 0x5e1e, si);
    di = 0x0c16;
    sub_10590();
loc_1277c: // 1059:21ec
    si = memoryAGet16(es, bx + 104);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e20))
        goto loc_12794;
    memoryASet16(ds, 0x5e20, si);
    di = 0x0c18;
    sub_10590();
loc_12794: // 1059:2204
    si = memoryAGet16(es, bx + 106);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e22))
        goto loc_127ac;
    memoryASet16(ds, 0x5e22, si);
    di = 0x0c1a;
    sub_10590();
loc_127ac: // 1059:221c
    si = memoryAGet16(es, bx + 108);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e24))
        goto loc_127c4;
    memoryASet16(ds, 0x5e24, si);
    di = 0x0c1c;
    sub_10590();
loc_127c4: // 1059:2234
    si = memoryAGet16(es, bx + 110);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e26))
        goto loc_127dc;
    memoryASet16(ds, 0x5e26, si);
    di = 0x0c1e;
    sub_10590();
loc_127dc: // 1059:224c
    si = memoryAGet16(es, bx + 112);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e28))
        goto loc_127f4;
    memoryASet16(ds, 0x5e28, si);
    di = 0x0c20;
    sub_10590();
loc_127f4: // 1059:2264
    si = memoryAGet16(es, bx + 114);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e2a))
        goto loc_1280c;
    memoryASet16(ds, 0x5e2a, si);
    di = 0x0c22;
    sub_10590();
loc_1280c: // 1059:227c
    si = memoryAGet16(es, bx + 116);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e2c))
        goto loc_12824;
    memoryASet16(ds, 0x5e2c, si);
    di = 0x0c24;
    sub_10590();
loc_12824: // 1059:2294
    si = memoryAGet16(es, bx + 118);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e2e))
        goto loc_1283c;
    memoryASet16(ds, 0x5e2e, si);
    di = 0x0c26;
    sub_10590();
loc_1283c: // 1059:22ac
    si = memoryAGet16(es, bx + 120);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e30))
        goto loc_12854;
    memoryASet16(ds, 0x5e30, si);
    di = 0x0c28;
    sub_10590();
loc_12854: // 1059:22c4
    si = memoryAGet16(es, bx + 122);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e32))
        goto loc_1286c;
    memoryASet16(ds, 0x5e32, si);
    di = 0x0c2a;
    sub_10590();
loc_1286c: // 1059:22dc
    si = memoryAGet16(es, bx + 124);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e34))
        goto loc_12884;
    memoryASet16(ds, 0x5e34, si);
    di = 0x0c2c;
    sub_10590();
loc_12884: // 1059:22f4
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 126);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e36))
        goto loc_128a0;
    memoryASet16(ds, 0x5e36, si);
    di = 0x0f04;
    sub_10590();
loc_128a0: // 1059:2310
    si = memoryAGet16(es, bx + 128);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e38))
        goto loc_128b9;
    memoryASet16(ds, 0x5e38, si);
    di = 0x0f06;
    sub_10590();
loc_128b9: // 1059:2329
    si = memoryAGet16(es, bx + 130);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e3a))
        goto loc_128d2;
    memoryASet16(ds, 0x5e3a, si);
    di = 0x0f08;
    sub_10590();
loc_128d2: // 1059:2342
    si = memoryAGet16(es, bx + 132);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e3c))
        goto loc_128eb;
    memoryASet16(ds, 0x5e3c, si);
    di = 0x0f0a;
    sub_10590();
loc_128eb: // 1059:235b
    si = memoryAGet16(es, bx + 134);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e3e))
        goto loc_12904;
    memoryASet16(ds, 0x5e3e, si);
    di = 0x0f0c;
    sub_10590();
loc_12904: // 1059:2374
    si = memoryAGet16(es, bx + 136);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e40))
        goto loc_1291d;
    memoryASet16(ds, 0x5e40, si);
    di = 0x0f0e;
    sub_10590();
loc_1291d: // 1059:238d
    si = memoryAGet16(es, bx + 138);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e42))
        goto loc_12936;
    memoryASet16(ds, 0x5e42, si);
    di = 0x0f10;
    sub_10590();
loc_12936: // 1059:23a6
    si = memoryAGet16(es, bx + 140);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e44))
        goto loc_1294f;
    memoryASet16(ds, 0x5e44, si);
    di = 0x0f12;
    sub_10590();
loc_1294f: // 1059:23bf
    si = memoryAGet16(es, bx + 142);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e46))
        goto loc_12968;
    memoryASet16(ds, 0x5e46, si);
    di = 0x0f14;
    sub_10590();
loc_12968: // 1059:23d8
    si = memoryAGet16(es, bx + 144);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e48))
        goto loc_12981;
    memoryASet16(ds, 0x5e48, si);
    di = 0x0f16;
    sub_10590();
loc_12981: // 1059:23f1
    si = memoryAGet16(es, bx + 146);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e4a))
        goto loc_1299a;
    memoryASet16(ds, 0x5e4a, si);
    di = 0x0f18;
    sub_10590();
loc_1299a: // 1059:240a
    si = memoryAGet16(es, bx + 148);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e4c))
        goto loc_129b3;
    memoryASet16(ds, 0x5e4c, si);
    di = 0x0f1a;
    sub_10590();
loc_129b3: // 1059:2423
    si = memoryAGet16(es, bx + 150);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e4e))
        goto loc_129cc;
    memoryASet16(ds, 0x5e4e, si);
    di = 0x0f1c;
    sub_10590();
loc_129cc: // 1059:243c
    si = memoryAGet16(es, bx + 152);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e50))
        goto loc_129e5;
    memoryASet16(ds, 0x5e50, si);
    di = 0x0f1e;
    sub_10590();
loc_129e5: // 1059:2455
    si = memoryAGet16(es, bx + 154);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e52))
        goto loc_129fe;
    memoryASet16(ds, 0x5e52, si);
    di = 0x0f20;
    sub_10590();
loc_129fe: // 1059:246e
    si = memoryAGet16(es, bx + 156);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e54))
        goto loc_12a17;
    memoryASet16(ds, 0x5e54, si);
    di = 0x0f22;
    sub_10590();
loc_12a17: // 1059:2487
    si = memoryAGet16(es, bx + 158);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e56))
        goto loc_12a30;
    memoryASet16(ds, 0x5e56, si);
    di = 0x0f24;
    sub_10590();
loc_12a30: // 1059:24a0
    si = memoryAGet16(es, bx + 160);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e58))
        goto loc_12a49;
    memoryASet16(ds, 0x5e58, si);
    di = 0x0f26;
    sub_10590();
loc_12a49: // 1059:24b9
    si = memoryAGet16(es, bx + 162);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e5a))
        goto loc_12a62;
    memoryASet16(ds, 0x5e5a, si);
    di = 0x0f28;
    sub_10590();
loc_12a62: // 1059:24d2
    si = memoryAGet16(es, bx + 164);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e5c))
        goto loc_12a7b;
    memoryASet16(ds, 0x5e5c, si);
    di = 0x0f2a;
    sub_10590();
loc_12a7b: // 1059:24eb
    si = memoryAGet16(es, bx + 166);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e5e))
        goto loc_12a94;
    memoryASet16(ds, 0x5e5e, si);
    di = 0x0f2c;
    sub_10590();
loc_12a94: // 1059:2504
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 168);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e60))
        goto loc_12ab1;
    memoryASet16(ds, 0x5e60, si);
    di = 0x1204;
    sub_10590();
loc_12ab1: // 1059:2521
    si = memoryAGet16(es, bx + 170);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e62))
        goto loc_12aca;
    memoryASet16(ds, 0x5e62, si);
    di = 0x1206;
    sub_10590();
loc_12aca: // 1059:253a
    si = memoryAGet16(es, bx + 172);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e64))
        goto loc_12ae3;
    memoryASet16(ds, 0x5e64, si);
    di = 0x1208;
    sub_10590();
loc_12ae3: // 1059:2553
    si = memoryAGet16(es, bx + 174);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e66))
        goto loc_12afc;
    memoryASet16(ds, 0x5e66, si);
    di = 0x120a;
    sub_10590();
loc_12afc: // 1059:256c
    si = memoryAGet16(es, bx + 176);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e68))
        goto loc_12b15;
    memoryASet16(ds, 0x5e68, si);
    di = 0x120c;
    sub_10590();
loc_12b15: // 1059:2585
    si = memoryAGet16(es, bx + 178);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e6a))
        goto loc_12b2e;
    memoryASet16(ds, 0x5e6a, si);
    di = 0x120e;
    sub_10590();
loc_12b2e: // 1059:259e
    si = memoryAGet16(es, bx + 180);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e6c))
        goto loc_12b47;
    memoryASet16(ds, 0x5e6c, si);
    di = 0x1210;
    sub_10590();
loc_12b47: // 1059:25b7
    si = memoryAGet16(es, bx + 182);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e6e))
        goto loc_12b60;
    memoryASet16(ds, 0x5e6e, si);
    di = 0x1212;
    sub_10590();
loc_12b60: // 1059:25d0
    si = memoryAGet16(es, bx + 184);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e70))
        goto loc_12b79;
    memoryASet16(ds, 0x5e70, si);
    di = 0x1214;
    sub_10590();
loc_12b79: // 1059:25e9
    si = memoryAGet16(es, bx + 186);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e72))
        goto loc_12b92;
    memoryASet16(ds, 0x5e72, si);
    di = 0x1216;
    sub_10590();
loc_12b92: // 1059:2602
    si = memoryAGet16(es, bx + 188);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e74))
        goto loc_12bab;
    memoryASet16(ds, 0x5e74, si);
    di = 0x1218;
    sub_10590();
loc_12bab: // 1059:261b
    si = memoryAGet16(es, bx + 190);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e76))
        goto loc_12bc4;
    memoryASet16(ds, 0x5e76, si);
    di = 0x121a;
    sub_10590();
loc_12bc4: // 1059:2634
    si = memoryAGet16(es, bx + 192);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e78))
        goto loc_12bdd;
    memoryASet16(ds, 0x5e78, si);
    di = 0x121c;
    sub_10590();
loc_12bdd: // 1059:264d
    si = memoryAGet16(es, bx + 194);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e7a))
        goto loc_12bf6;
    memoryASet16(ds, 0x5e7a, si);
    di = 0x121e;
    sub_10590();
loc_12bf6: // 1059:2666
    si = memoryAGet16(es, bx + 196);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e7c))
        goto loc_12c0f;
    memoryASet16(ds, 0x5e7c, si);
    di = 0x1220;
    sub_10590();
loc_12c0f: // 1059:267f
    si = memoryAGet16(es, bx + 198);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e7e))
        goto loc_12c28;
    memoryASet16(ds, 0x5e7e, si);
    di = 0x1222;
    sub_10590();
loc_12c28: // 1059:2698
    si = memoryAGet16(es, bx + 200);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e80))
        goto loc_12c41;
    memoryASet16(ds, 0x5e80, si);
    di = 0x1224;
    sub_10590();
loc_12c41: // 1059:26b1
    si = memoryAGet16(es, bx + 202);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e82))
        goto loc_12c5a;
    memoryASet16(ds, 0x5e82, si);
    di = 0x1226;
    sub_10590();
loc_12c5a: // 1059:26ca
    si = memoryAGet16(es, bx + 204);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e84))
        goto loc_12c73;
    memoryASet16(ds, 0x5e84, si);
    di = 0x1228;
    sub_10590();
loc_12c73: // 1059:26e3
    si = memoryAGet16(es, bx + 206);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e86))
        goto loc_12c8c;
    memoryASet16(ds, 0x5e86, si);
    di = 0x122a;
    sub_10590();
loc_12c8c: // 1059:26fc
    si = memoryAGet16(es, bx + 208);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e88))
        goto loc_12ca5;
    memoryASet16(ds, 0x5e88, si);
    di = 0x122c;
    sub_10590();
loc_12ca5: // 1059:2715
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 210);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e8a))
        goto loc_12cc2;
    memoryASet16(ds, 0x5e8a, si);
    di = 0x1504;
    sub_10590();
loc_12cc2: // 1059:2732
    si = memoryAGet16(es, bx + 212);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e8c))
        goto loc_12cdb;
    memoryASet16(ds, 0x5e8c, si);
    di = 0x1506;
    sub_10590();
loc_12cdb: // 1059:274b
    si = memoryAGet16(es, bx + 214);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e8e))
        goto loc_12cf4;
    memoryASet16(ds, 0x5e8e, si);
    di = 0x1508;
    sub_10590();
loc_12cf4: // 1059:2764
    si = memoryAGet16(es, bx + 216);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e90))
        goto loc_12d0d;
    memoryASet16(ds, 0x5e90, si);
    di = 0x150a;
    sub_10590();
loc_12d0d: // 1059:277d
    si = memoryAGet16(es, bx + 218);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e92))
        goto loc_12d26;
    memoryASet16(ds, 0x5e92, si);
    di = 0x150c;
    sub_10590();
loc_12d26: // 1059:2796
    si = memoryAGet16(es, bx + 220);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e94))
        goto loc_12d3f;
    memoryASet16(ds, 0x5e94, si);
    di = 0x150e;
    sub_10590();
loc_12d3f: // 1059:27af
    si = memoryAGet16(es, bx + 222);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e96))
        goto loc_12d58;
    memoryASet16(ds, 0x5e96, si);
    di = 0x1510;
    sub_10590();
loc_12d58: // 1059:27c8
    si = memoryAGet16(es, bx + 224);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e98))
        goto loc_12d71;
    memoryASet16(ds, 0x5e98, si);
    di = 0x1512;
    sub_10590();
loc_12d71: // 1059:27e1
    si = memoryAGet16(es, bx + 226);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e9a))
        goto loc_12d8a;
    memoryASet16(ds, 0x5e9a, si);
    di = 0x1514;
    sub_10590();
loc_12d8a: // 1059:27fa
    si = memoryAGet16(es, bx + 228);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e9c))
        goto loc_12da3;
    memoryASet16(ds, 0x5e9c, si);
    di = 0x1516;
    sub_10590();
loc_12da3: // 1059:2813
    si = memoryAGet16(es, bx + 230);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5e9e))
        goto loc_12dbc;
    memoryASet16(ds, 0x5e9e, si);
    di = 0x1518;
    sub_10590();
loc_12dbc: // 1059:282c
    si = memoryAGet16(es, bx + 232);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ea0))
        goto loc_12dd5;
    memoryASet16(ds, 0x5ea0, si);
    di = 0x151a;
    sub_10590();
loc_12dd5: // 1059:2845
    si = memoryAGet16(es, bx + 234);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ea2))
        goto loc_12dee;
    memoryASet16(ds, 0x5ea2, si);
    di = 0x151c;
    sub_10590();
loc_12dee: // 1059:285e
    si = memoryAGet16(es, bx + 236);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ea4))
        goto loc_12e07;
    memoryASet16(ds, 0x5ea4, si);
    di = 0x151e;
    sub_10590();
loc_12e07: // 1059:2877
    si = memoryAGet16(es, bx + 238);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ea6))
        goto loc_12e20;
    memoryASet16(ds, 0x5ea6, si);
    di = 0x1520;
    sub_10590();
loc_12e20: // 1059:2890
    si = memoryAGet16(es, bx + 240);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ea8))
        goto loc_12e39;
    memoryASet16(ds, 0x5ea8, si);
    di = 0x1522;
    sub_10590();
loc_12e39: // 1059:28a9
    si = memoryAGet16(es, bx + 242);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eaa))
        goto loc_12e52;
    memoryASet16(ds, 0x5eaa, si);
    di = 0x1524;
    sub_10590();
loc_12e52: // 1059:28c2
    si = memoryAGet16(es, bx + 244);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eac))
        goto loc_12e6b;
    memoryASet16(ds, 0x5eac, si);
    di = 0x1526;
    sub_10590();
loc_12e6b: // 1059:28db
    si = memoryAGet16(es, bx + 246);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eae))
        goto loc_12e84;
    memoryASet16(ds, 0x5eae, si);
    di = 0x1528;
    sub_10590();
loc_12e84: // 1059:28f4
    si = memoryAGet16(es, bx + 248);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eb0))
        goto loc_12e9d;
    memoryASet16(ds, 0x5eb0, si);
    di = 0x152a;
    sub_10590();
loc_12e9d: // 1059:290d
    si = memoryAGet16(es, bx + 250);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eb2))
        goto loc_12eb6;
    memoryASet16(ds, 0x5eb2, si);
    di = 0x152c;
    sub_10590();
loc_12eb6: // 1059:2926
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 252);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eb4))
        goto loc_12ed3;
    memoryASet16(ds, 0x5eb4, si);
    di = 0x1804;
    sub_10590();
loc_12ed3: // 1059:2943
    si = memoryAGet16(es, bx + 254);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eb6))
        goto loc_12eec;
    memoryASet16(ds, 0x5eb6, si);
    di = 0x1806;
    sub_10590();
loc_12eec: // 1059:295c
    si = memoryAGet16(es, bx + 256);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eb8))
        goto loc_12f05;
    memoryASet16(ds, 0x5eb8, si);
    di = 0x1808;
    sub_10590();
loc_12f05: // 1059:2975
    si = memoryAGet16(es, bx + 258);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eba))
        goto loc_12f1e;
    memoryASet16(ds, 0x5eba, si);
    di = 0x180a;
    sub_10590();
loc_12f1e: // 1059:298e
    si = memoryAGet16(es, bx + 260);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ebc))
        goto loc_12f37;
    memoryASet16(ds, 0x5ebc, si);
    di = 0x180c;
    sub_10590();
loc_12f37: // 1059:29a7
    si = memoryAGet16(es, bx + 262);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ebe))
        goto loc_12f50;
    memoryASet16(ds, 0x5ebe, si);
    di = 0x180e;
    sub_10590();
loc_12f50: // 1059:29c0
    si = memoryAGet16(es, bx + 264);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ec0))
        goto loc_12f69;
    memoryASet16(ds, 0x5ec0, si);
    di = 0x1810;
    sub_10590();
loc_12f69: // 1059:29d9
    si = memoryAGet16(es, bx + 266);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ec2))
        goto loc_12f82;
    memoryASet16(ds, 0x5ec2, si);
    di = 0x1812;
    sub_10590();
loc_12f82: // 1059:29f2
    si = memoryAGet16(es, bx + 268);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ec4))
        goto loc_12f9b;
    memoryASet16(ds, 0x5ec4, si);
    di = 0x1814;
    sub_10590();
loc_12f9b: // 1059:2a0b
    si = memoryAGet16(es, bx + 270);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ec6))
        goto loc_12fb4;
    memoryASet16(ds, 0x5ec6, si);
    di = 0x1816;
    sub_10590();
loc_12fb4: // 1059:2a24
    si = memoryAGet16(es, bx + 272);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ec8))
        goto loc_12fcd;
    memoryASet16(ds, 0x5ec8, si);
    di = 0x1818;
    sub_10590();
loc_12fcd: // 1059:2a3d
    si = memoryAGet16(es, bx + 274);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eca))
        goto loc_12fe6;
    memoryASet16(ds, 0x5eca, si);
    di = 0x181a;
    sub_10590();
loc_12fe6: // 1059:2a56
    si = memoryAGet16(es, bx + 276);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ecc))
        goto loc_12fff;
    memoryASet16(ds, 0x5ecc, si);
    di = 0x181c;
    sub_10590();
loc_12fff: // 1059:2a6f
    si = memoryAGet16(es, bx + 278);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ece))
        goto loc_13018;
    memoryASet16(ds, 0x5ece, si);
    di = 0x181e;
    sub_10590();
loc_13018: // 1059:2a88
    si = memoryAGet16(es, bx + 280);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ed0))
        goto loc_13031;
    memoryASet16(ds, 0x5ed0, si);
    di = 0x1820;
    sub_10590();
loc_13031: // 1059:2aa1
    si = memoryAGet16(es, bx + 282);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ed2))
        goto loc_1304a;
    memoryASet16(ds, 0x5ed2, si);
    di = 0x1822;
    sub_10590();
loc_1304a: // 1059:2aba
    si = memoryAGet16(es, bx + 284);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ed4))
        goto loc_13063;
    memoryASet16(ds, 0x5ed4, si);
    di = 0x1824;
    sub_10590();
loc_13063: // 1059:2ad3
    si = memoryAGet16(es, bx + 286);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ed6))
        goto loc_1307c;
    memoryASet16(ds, 0x5ed6, si);
    di = 0x1826;
    sub_10590();
loc_1307c: // 1059:2aec
    si = memoryAGet16(es, bx + 288);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ed8))
        goto loc_13095;
    memoryASet16(ds, 0x5ed8, si);
    di = 0x1828;
    sub_10590();
loc_13095: // 1059:2b05
    si = memoryAGet16(es, bx + 290);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eda))
        goto loc_130ae;
    memoryASet16(ds, 0x5eda, si);
    di = 0x182a;
    sub_10590();
loc_130ae: // 1059:2b1e
    si = memoryAGet16(es, bx + 292);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5edc))
        goto loc_130c7;
    memoryASet16(ds, 0x5edc, si);
    di = 0x182c;
    sub_10590();
loc_130c7: // 1059:2b37
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 294);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ede))
        goto loc_130e4;
    memoryASet16(ds, 0x5ede, si);
    di = 0x1b04;
    sub_10590();
loc_130e4: // 1059:2b54
    si = memoryAGet16(es, bx + 296);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ee0))
        goto loc_130fd;
    memoryASet16(ds, 0x5ee0, si);
    di = 0x1b06;
    sub_10590();
loc_130fd: // 1059:2b6d
    si = memoryAGet16(es, bx + 298);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ee2))
        goto loc_13116;
    memoryASet16(ds, 0x5ee2, si);
    di = 0x1b08;
    sub_10590();
loc_13116: // 1059:2b86
    si = memoryAGet16(es, bx + 300);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ee4))
        goto loc_1312f;
    memoryASet16(ds, 0x5ee4, si);
    di = 0x1b0a;
    sub_10590();
loc_1312f: // 1059:2b9f
    si = memoryAGet16(es, bx + 302);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ee6))
        goto loc_13148;
    memoryASet16(ds, 0x5ee6, si);
    di = 0x1b0c;
    sub_10590();
loc_13148: // 1059:2bb8
    si = memoryAGet16(es, bx + 304);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ee8))
        goto loc_13161;
    memoryASet16(ds, 0x5ee8, si);
    di = 0x1b0e;
    sub_10590();
loc_13161: // 1059:2bd1
    si = memoryAGet16(es, bx + 306);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eea))
        goto loc_1317a;
    memoryASet16(ds, 0x5eea, si);
    di = 0x1b10;
    sub_10590();
loc_1317a: // 1059:2bea
    si = memoryAGet16(es, bx + 308);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eec))
        goto loc_13193;
    memoryASet16(ds, 0x5eec, si);
    di = 0x1b12;
    sub_10590();
loc_13193: // 1059:2c03
    si = memoryAGet16(es, bx + 310);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5eee))
        goto loc_131ac;
    memoryASet16(ds, 0x5eee, si);
    di = 0x1b14;
    sub_10590();
loc_131ac: // 1059:2c1c
    si = memoryAGet16(es, bx + 312);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ef0))
        goto loc_131c5;
    memoryASet16(ds, 0x5ef0, si);
    di = 0x1b16;
    sub_10590();
loc_131c5: // 1059:2c35
    si = memoryAGet16(es, bx + 314);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ef2))
        goto loc_131de;
    memoryASet16(ds, 0x5ef2, si);
    di = 0x1b18;
    sub_10590();
loc_131de: // 1059:2c4e
    si = memoryAGet16(es, bx + 316);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ef4))
        goto loc_131f7;
    memoryASet16(ds, 0x5ef4, si);
    di = 0x1b1a;
    sub_10590();
loc_131f7: // 1059:2c67
    si = memoryAGet16(es, bx + 318);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ef6))
        goto loc_13210;
    memoryASet16(ds, 0x5ef6, si);
    di = 0x1b1c;
    sub_10590();
loc_13210: // 1059:2c80
    si = memoryAGet16(es, bx + 320);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ef8))
        goto loc_13229;
    memoryASet16(ds, 0x5ef8, si);
    di = 0x1b1e;
    sub_10590();
loc_13229: // 1059:2c99
    si = memoryAGet16(es, bx + 322);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5efa))
        goto loc_13242;
    memoryASet16(ds, 0x5efa, si);
    di = 0x1b20;
    sub_10590();
loc_13242: // 1059:2cb2
    si = memoryAGet16(es, bx + 324);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5efc))
        goto loc_1325b;
    memoryASet16(ds, 0x5efc, si);
    di = 0x1b22;
    sub_10590();
loc_1325b: // 1059:2ccb
    si = memoryAGet16(es, bx + 326);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5efe))
        goto loc_13274;
    memoryASet16(ds, 0x5efe, si);
    di = 0x1b24;
    sub_10590();
loc_13274: // 1059:2ce4
    si = memoryAGet16(es, bx + 328);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f00))
        goto loc_1328d;
    memoryASet16(ds, 0x5f00, si);
    di = 0x1b26;
    sub_10590();
loc_1328d: // 1059:2cfd
    si = memoryAGet16(es, bx + 330);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f02))
        goto loc_132a6;
    memoryASet16(ds, 0x5f02, si);
    di = 0x1b28;
    sub_10590();
loc_132a6: // 1059:2d16
    si = memoryAGet16(es, bx + 332);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f04))
        goto loc_132bf;
    memoryASet16(ds, 0x5f04, si);
    di = 0x1b2a;
    sub_10590();
loc_132bf: // 1059:2d2f
    si = memoryAGet16(es, bx + 334);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f06))
        goto loc_132d8;
    memoryASet16(ds, 0x5f06, si);
    di = 0x1b2c;
    sub_10590();
loc_132d8: // 1059:2d48
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 336);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f08))
        goto loc_132f5;
    memoryASet16(ds, 0x5f08, si);
    di = 0x1e04;
    sub_10590();
loc_132f5: // 1059:2d65
    si = memoryAGet16(es, bx + 338);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f0a))
        goto loc_1330e;
    memoryASet16(ds, 0x5f0a, si);
    di = 0x1e06;
    sub_10590();
loc_1330e: // 1059:2d7e
    si = memoryAGet16(es, bx + 340);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f0c))
        goto loc_13327;
    memoryASet16(ds, 0x5f0c, si);
    di = 0x1e08;
    sub_10590();
loc_13327: // 1059:2d97
    si = memoryAGet16(es, bx + 342);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f0e))
        goto loc_13340;
    memoryASet16(ds, 0x5f0e, si);
    di = 0x1e0a;
    sub_10590();
loc_13340: // 1059:2db0
    si = memoryAGet16(es, bx + 344);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f10))
        goto loc_13359;
    memoryASet16(ds, 0x5f10, si);
    di = 0x1e0c;
    sub_10590();
loc_13359: // 1059:2dc9
    si = memoryAGet16(es, bx + 346);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f12))
        goto loc_13372;
    memoryASet16(ds, 0x5f12, si);
    di = 0x1e0e;
    sub_10590();
loc_13372: // 1059:2de2
    si = memoryAGet16(es, bx + 348);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f14))
        goto loc_1338b;
    memoryASet16(ds, 0x5f14, si);
    di = 0x1e10;
    sub_10590();
loc_1338b: // 1059:2dfb
    si = memoryAGet16(es, bx + 350);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f16))
        goto loc_133a4;
    memoryASet16(ds, 0x5f16, si);
    di = 0x1e12;
    sub_10590();
loc_133a4: // 1059:2e14
    si = memoryAGet16(es, bx + 352);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f18))
        goto loc_133bd;
    memoryASet16(ds, 0x5f18, si);
    di = 0x1e14;
    sub_10590();
loc_133bd: // 1059:2e2d
    si = memoryAGet16(es, bx + 354);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f1a))
        goto loc_133d6;
    memoryASet16(ds, 0x5f1a, si);
    di = 0x1e16;
    sub_10590();
loc_133d6: // 1059:2e46
    si = memoryAGet16(es, bx + 356);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f1c))
        goto loc_133ef;
    memoryASet16(ds, 0x5f1c, si);
    di = 0x1e18;
    sub_10590();
loc_133ef: // 1059:2e5f
    si = memoryAGet16(es, bx + 358);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f1e))
        goto loc_13408;
    memoryASet16(ds, 0x5f1e, si);
    di = 0x1e1a;
    sub_10590();
loc_13408: // 1059:2e78
    si = memoryAGet16(es, bx + 360);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f20))
        goto loc_13421;
    memoryASet16(ds, 0x5f20, si);
    di = 0x1e1c;
    sub_10590();
loc_13421: // 1059:2e91
    si = memoryAGet16(es, bx + 362);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f22))
        goto loc_1343a;
    memoryASet16(ds, 0x5f22, si);
    di = 0x1e1e;
    sub_10590();
loc_1343a: // 1059:2eaa
    si = memoryAGet16(es, bx + 364);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f24))
        goto loc_13453;
    memoryASet16(ds, 0x5f24, si);
    di = 0x1e20;
    sub_10590();
loc_13453: // 1059:2ec3
    si = memoryAGet16(es, bx + 366);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f26))
        goto loc_1346c;
    memoryASet16(ds, 0x5f26, si);
    di = 0x1e22;
    sub_10590();
loc_1346c: // 1059:2edc
    si = memoryAGet16(es, bx + 368);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f28))
        goto loc_13485;
    memoryASet16(ds, 0x5f28, si);
    di = 0x1e24;
    sub_10590();
loc_13485: // 1059:2ef5
    si = memoryAGet16(es, bx + 370);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f2a))
        goto loc_1349e;
    memoryASet16(ds, 0x5f2a, si);
    di = 0x1e26;
    sub_10590();
loc_1349e: // 1059:2f0e
    si = memoryAGet16(es, bx + 372);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f2c))
        goto loc_134b7;
    memoryASet16(ds, 0x5f2c, si);
    di = 0x1e28;
    sub_10590();
loc_134b7: // 1059:2f27
    si = memoryAGet16(es, bx + 374);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f2e))
        goto loc_134d0;
    memoryASet16(ds, 0x5f2e, si);
    di = 0x1e2a;
    sub_10590();
loc_134d0: // 1059:2f40
    si = memoryAGet16(es, bx + 376);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f30))
        goto loc_134e9;
    memoryASet16(ds, 0x5f30, si);
    di = 0x1e2c;
    sub_10590();
loc_134e9: // 1059:2f59
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 378);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f32))
        goto loc_13506;
    memoryASet16(ds, 0x5f32, si);
    di = 0x2104;
    sub_10590();
loc_13506: // 1059:2f76
    si = memoryAGet16(es, bx + 380);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f34))
        goto loc_1351f;
    memoryASet16(ds, 0x5f34, si);
    di = 0x2106;
    sub_10590();
loc_1351f: // 1059:2f8f
    si = memoryAGet16(es, bx + 382);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f36))
        goto loc_13538;
    memoryASet16(ds, 0x5f36, si);
    di = 0x2108;
    sub_10590();
loc_13538: // 1059:2fa8
    si = memoryAGet16(es, bx + 384);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f38))
        goto loc_13551;
    memoryASet16(ds, 0x5f38, si);
    di = 0x210a;
    sub_10590();
loc_13551: // 1059:2fc1
    si = memoryAGet16(es, bx + 386);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f3a))
        goto loc_1356a;
    memoryASet16(ds, 0x5f3a, si);
    di = 0x210c;
    sub_10590();
loc_1356a: // 1059:2fda
    si = memoryAGet16(es, bx + 388);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f3c))
        goto loc_13583;
    memoryASet16(ds, 0x5f3c, si);
    di = 0x210e;
    sub_10590();
loc_13583: // 1059:2ff3
    si = memoryAGet16(es, bx + 390);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f3e))
        goto loc_1359c;
    memoryASet16(ds, 0x5f3e, si);
    di = 0x2110;
    sub_10590();
loc_1359c: // 1059:300c
    si = memoryAGet16(es, bx + 392);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f40))
        goto loc_135b5;
    memoryASet16(ds, 0x5f40, si);
    di = 0x2112;
    sub_10590();
loc_135b5: // 1059:3025
    si = memoryAGet16(es, bx + 394);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f42))
        goto loc_135ce;
    memoryASet16(ds, 0x5f42, si);
    di = 0x2114;
    sub_10590();
loc_135ce: // 1059:303e
    si = memoryAGet16(es, bx + 396);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f44))
        goto loc_135e7;
    memoryASet16(ds, 0x5f44, si);
    di = 0x2116;
    sub_10590();
loc_135e7: // 1059:3057
    si = memoryAGet16(es, bx + 398);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f46))
        goto loc_13600;
    memoryASet16(ds, 0x5f46, si);
    di = 0x2118;
    sub_10590();
loc_13600: // 1059:3070
    si = memoryAGet16(es, bx + 400);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f48))
        goto loc_13619;
    memoryASet16(ds, 0x5f48, si);
    di = 0x211a;
    sub_10590();
loc_13619: // 1059:3089
    si = memoryAGet16(es, bx + 402);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f4a))
        goto loc_13632;
    memoryASet16(ds, 0x5f4a, si);
    di = 0x211c;
    sub_10590();
loc_13632: // 1059:30a2
    si = memoryAGet16(es, bx + 404);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f4c))
        goto loc_1364b;
    memoryASet16(ds, 0x5f4c, si);
    di = 0x211e;
    sub_10590();
loc_1364b: // 1059:30bb
    si = memoryAGet16(es, bx + 406);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f4e))
        goto loc_13664;
    memoryASet16(ds, 0x5f4e, si);
    di = 0x2120;
    sub_10590();
loc_13664: // 1059:30d4
    si = memoryAGet16(es, bx + 408);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f50))
        goto loc_1367d;
    memoryASet16(ds, 0x5f50, si);
    di = 0x2122;
    sub_10590();
loc_1367d: // 1059:30ed
    si = memoryAGet16(es, bx + 410);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f52))
        goto loc_13696;
    memoryASet16(ds, 0x5f52, si);
    di = 0x2124;
    sub_10590();
loc_13696: // 1059:3106
    si = memoryAGet16(es, bx + 412);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f54))
        goto loc_136af;
    memoryASet16(ds, 0x5f54, si);
    di = 0x2126;
    sub_10590();
loc_136af: // 1059:311f
    si = memoryAGet16(es, bx + 414);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f56))
        goto loc_136c8;
    memoryASet16(ds, 0x5f56, si);
    di = 0x2128;
    sub_10590();
loc_136c8: // 1059:3138
    si = memoryAGet16(es, bx + 416);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f58))
        goto loc_136e1;
    memoryASet16(ds, 0x5f58, si);
    di = 0x212a;
    sub_10590();
loc_136e1: // 1059:3151
    si = memoryAGet16(es, bx + 418);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f5a))
        goto loc_136fa;
    memoryASet16(ds, 0x5f5a, si);
    di = 0x212c;
    sub_10590();
loc_136fa: // 1059:316a
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 420);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f5c))
        goto loc_13717;
    memoryASet16(ds, 0x5f5c, si);
    di = 0x2404;
    sub_10590();
loc_13717: // 1059:3187
    si = memoryAGet16(es, bx + 422);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f5e))
        goto loc_13730;
    memoryASet16(ds, 0x5f5e, si);
    di = 0x2406;
    sub_10590();
loc_13730: // 1059:31a0
    si = memoryAGet16(es, bx + 424);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f60))
        goto loc_13749;
    memoryASet16(ds, 0x5f60, si);
    di = 0x2408;
    sub_10590();
loc_13749: // 1059:31b9
    si = memoryAGet16(es, bx + 426);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f62))
        goto loc_13762;
    memoryASet16(ds, 0x5f62, si);
    di = 0x240a;
    sub_10590();
loc_13762: // 1059:31d2
    si = memoryAGet16(es, bx + 428);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f64))
        goto loc_1377b;
    memoryASet16(ds, 0x5f64, si);
    di = 0x240c;
    sub_10590();
loc_1377b: // 1059:31eb
    si = memoryAGet16(es, bx + 430);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f66))
        goto loc_13794;
    memoryASet16(ds, 0x5f66, si);
    di = 0x240e;
    sub_10590();
loc_13794: // 1059:3204
    si = memoryAGet16(es, bx + 432);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f68))
        goto loc_137ad;
    memoryASet16(ds, 0x5f68, si);
    di = 0x2410;
    sub_10590();
loc_137ad: // 1059:321d
    si = memoryAGet16(es, bx + 434);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f6a))
        goto loc_137c6;
    memoryASet16(ds, 0x5f6a, si);
    di = 0x2412;
    sub_10590();
loc_137c6: // 1059:3236
    si = memoryAGet16(es, bx + 436);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f6c))
        goto loc_137df;
    memoryASet16(ds, 0x5f6c, si);
    di = 0x2414;
    sub_10590();
loc_137df: // 1059:324f
    si = memoryAGet16(es, bx + 438);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f6e))
        goto loc_137f8;
    memoryASet16(ds, 0x5f6e, si);
    di = 0x2416;
    sub_10590();
loc_137f8: // 1059:3268
    si = memoryAGet16(es, bx + 440);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f70))
        goto loc_13811;
    memoryASet16(ds, 0x5f70, si);
    di = 0x2418;
    sub_10590();
loc_13811: // 1059:3281
    si = memoryAGet16(es, bx + 442);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f72))
        goto loc_1382a;
    memoryASet16(ds, 0x5f72, si);
    di = 0x241a;
    sub_10590();
loc_1382a: // 1059:329a
    si = memoryAGet16(es, bx + 444);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f74))
        goto loc_13843;
    memoryASet16(ds, 0x5f74, si);
    di = 0x241c;
    sub_10590();
loc_13843: // 1059:32b3
    si = memoryAGet16(es, bx + 446);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f76))
        goto loc_1385c;
    memoryASet16(ds, 0x5f76, si);
    di = 0x241e;
    sub_10590();
loc_1385c: // 1059:32cc
    si = memoryAGet16(es, bx + 448);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f78))
        goto loc_13875;
    memoryASet16(ds, 0x5f78, si);
    di = 0x2420;
    sub_10590();
loc_13875: // 1059:32e5
    si = memoryAGet16(es, bx + 450);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f7a))
        goto loc_1388e;
    memoryASet16(ds, 0x5f7a, si);
    di = 0x2422;
    sub_10590();
loc_1388e: // 1059:32fe
    si = memoryAGet16(es, bx + 452);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f7c))
        goto loc_138a7;
    memoryASet16(ds, 0x5f7c, si);
    di = 0x2424;
    sub_10590();
loc_138a7: // 1059:3317
    si = memoryAGet16(es, bx + 454);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f7e))
        goto loc_138c0;
    memoryASet16(ds, 0x5f7e, si);
    di = 0x2426;
    sub_10590();
loc_138c0: // 1059:3330
    si = memoryAGet16(es, bx + 456);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f80))
        goto loc_138d9;
    memoryASet16(ds, 0x5f80, si);
    di = 0x2428;
    sub_10590();
loc_138d9: // 1059:3349
    si = memoryAGet16(es, bx + 458);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f82))
        goto loc_138f2;
    memoryASet16(ds, 0x5f82, si);
    di = 0x242a;
    sub_10590();
loc_138f2: // 1059:3362
    si = memoryAGet16(es, bx + 460);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f84))
        goto loc_1390b;
    memoryASet16(ds, 0x5f84, si);
    di = 0x242c;
    sub_10590();
loc_1390b: // 1059:337b
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 462);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f86))
        goto loc_13928;
    memoryASet16(ds, 0x5f86, si);
    di = 0x2704;
    sub_10590();
loc_13928: // 1059:3398
    si = memoryAGet16(es, bx + 464);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f88))
        goto loc_13941;
    memoryASet16(ds, 0x5f88, si);
    di = 0x2706;
    sub_10590();
loc_13941: // 1059:33b1
    si = memoryAGet16(es, bx + 466);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f8a))
        goto loc_1395a;
    memoryASet16(ds, 0x5f8a, si);
    di = 0x2708;
    sub_10590();
loc_1395a: // 1059:33ca
    si = memoryAGet16(es, bx + 468);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f8c))
        goto loc_13973;
    memoryASet16(ds, 0x5f8c, si);
    di = 0x270a;
    sub_10590();
loc_13973: // 1059:33e3
    si = memoryAGet16(es, bx + 470);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f8e))
        goto loc_1398c;
    memoryASet16(ds, 0x5f8e, si);
    di = 0x270c;
    sub_10590();
loc_1398c: // 1059:33fc
    si = memoryAGet16(es, bx + 472);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f90))
        goto loc_139a5;
    memoryASet16(ds, 0x5f90, si);
    di = 0x270e;
    sub_10590();
loc_139a5: // 1059:3415
    si = memoryAGet16(es, bx + 474);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f92))
        goto loc_139be;
    memoryASet16(ds, 0x5f92, si);
    di = 0x2710;
    sub_10590();
loc_139be: // 1059:342e
    si = memoryAGet16(es, bx + 476);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f94))
        goto loc_139d7;
    memoryASet16(ds, 0x5f94, si);
    di = 0x2712;
    sub_10590();
loc_139d7: // 1059:3447
    si = memoryAGet16(es, bx + 478);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f96))
        goto loc_139f0;
    memoryASet16(ds, 0x5f96, si);
    di = 0x2714;
    sub_10590();
loc_139f0: // 1059:3460
    si = memoryAGet16(es, bx + 480);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f98))
        goto loc_13a09;
    memoryASet16(ds, 0x5f98, si);
    di = 0x2716;
    sub_10590();
loc_13a09: // 1059:3479
    si = memoryAGet16(es, bx + 482);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f9a))
        goto loc_13a22;
    memoryASet16(ds, 0x5f9a, si);
    di = 0x2718;
    sub_10590();
loc_13a22: // 1059:3492
    si = memoryAGet16(es, bx + 484);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f9c))
        goto loc_13a3b;
    memoryASet16(ds, 0x5f9c, si);
    di = 0x271a;
    sub_10590();
loc_13a3b: // 1059:34ab
    si = memoryAGet16(es, bx + 486);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5f9e))
        goto loc_13a54;
    memoryASet16(ds, 0x5f9e, si);
    di = 0x271c;
    sub_10590();
loc_13a54: // 1059:34c4
    si = memoryAGet16(es, bx + 488);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fa0))
        goto loc_13a6d;
    memoryASet16(ds, 0x5fa0, si);
    di = 0x271e;
    sub_10590();
loc_13a6d: // 1059:34dd
    si = memoryAGet16(es, bx + 490);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fa2))
        goto loc_13a86;
    memoryASet16(ds, 0x5fa2, si);
    di = 0x2720;
    sub_10590();
loc_13a86: // 1059:34f6
    si = memoryAGet16(es, bx + 492);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fa4))
        goto loc_13a9f;
    memoryASet16(ds, 0x5fa4, si);
    di = 0x2722;
    sub_10590();
loc_13a9f: // 1059:350f
    si = memoryAGet16(es, bx + 494);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fa6))
        goto loc_13ab8;
    memoryASet16(ds, 0x5fa6, si);
    di = 0x2724;
    sub_10590();
loc_13ab8: // 1059:3528
    si = memoryAGet16(es, bx + 496);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fa8))
        goto loc_13ad1;
    memoryASet16(ds, 0x5fa8, si);
    di = 0x2726;
    sub_10590();
loc_13ad1: // 1059:3541
    si = memoryAGet16(es, bx + 498);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5faa))
        goto loc_13aea;
    memoryASet16(ds, 0x5faa, si);
    di = 0x2728;
    sub_10590();
loc_13aea: // 1059:355a
    si = memoryAGet16(es, bx + 500);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fac))
        goto loc_13b03;
    memoryASet16(ds, 0x5fac, si);
    di = 0x272a;
    sub_10590();
loc_13b03: // 1059:3573
    si = memoryAGet16(es, bx + 502);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fae))
        goto loc_13b1c;
    memoryASet16(ds, 0x5fae, si);
    di = 0x272c;
    sub_10590();
loc_13b1c: // 1059:358c
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 504);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fb0))
        goto loc_13b39;
    memoryASet16(ds, 0x5fb0, si);
    di = 0x2a04;
    sub_10590();
loc_13b39: // 1059:35a9
    si = memoryAGet16(es, bx + 506);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fb2))
        goto loc_13b52;
    memoryASet16(ds, 0x5fb2, si);
    di = 0x2a06;
    sub_10590();
loc_13b52: // 1059:35c2
    si = memoryAGet16(es, bx + 508);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fb4))
        goto loc_13b6b;
    memoryASet16(ds, 0x5fb4, si);
    di = 0x2a08;
    sub_10590();
loc_13b6b: // 1059:35db
    si = memoryAGet16(es, bx + 510);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fb6))
        goto loc_13b84;
    memoryASet16(ds, 0x5fb6, si);
    di = 0x2a0a;
    sub_10590();
loc_13b84: // 1059:35f4
    si = memoryAGet16(es, bx + 512);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fb8))
        goto loc_13b9d;
    memoryASet16(ds, 0x5fb8, si);
    di = 0x2a0c;
    sub_10590();
loc_13b9d: // 1059:360d
    si = memoryAGet16(es, bx + 514);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fba))
        goto loc_13bb6;
    memoryASet16(ds, 0x5fba, si);
    di = 0x2a0e;
    sub_10590();
loc_13bb6: // 1059:3626
    si = memoryAGet16(es, bx + 516);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fbc))
        goto loc_13bcf;
    memoryASet16(ds, 0x5fbc, si);
    di = 0x2a10;
    sub_10590();
loc_13bcf: // 1059:363f
    si = memoryAGet16(es, bx + 518);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fbe))
        goto loc_13be8;
    memoryASet16(ds, 0x5fbe, si);
    di = 0x2a12;
    sub_10590();
loc_13be8: // 1059:3658
    si = memoryAGet16(es, bx + 520);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fc0))
        goto loc_13c01;
    memoryASet16(ds, 0x5fc0, si);
    di = 0x2a14;
    sub_10590();
loc_13c01: // 1059:3671
    si = memoryAGet16(es, bx + 522);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fc2))
        goto loc_13c1a;
    memoryASet16(ds, 0x5fc2, si);
    di = 0x2a16;
    sub_10590();
loc_13c1a: // 1059:368a
    si = memoryAGet16(es, bx + 524);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fc4))
        goto loc_13c33;
    memoryASet16(ds, 0x5fc4, si);
    di = 0x2a18;
    sub_10590();
loc_13c33: // 1059:36a3
    si = memoryAGet16(es, bx + 526);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fc6))
        goto loc_13c4c;
    memoryASet16(ds, 0x5fc6, si);
    di = 0x2a1a;
    sub_10590();
loc_13c4c: // 1059:36bc
    si = memoryAGet16(es, bx + 528);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fc8))
        goto loc_13c65;
    memoryASet16(ds, 0x5fc8, si);
    di = 0x2a1c;
    sub_10590();
loc_13c65: // 1059:36d5
    si = memoryAGet16(es, bx + 530);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fca))
        goto loc_13c7e;
    memoryASet16(ds, 0x5fca, si);
    di = 0x2a1e;
    sub_10590();
loc_13c7e: // 1059:36ee
    si = memoryAGet16(es, bx + 532);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fcc))
        goto loc_13c97;
    memoryASet16(ds, 0x5fcc, si);
    di = 0x2a20;
    sub_10590();
loc_13c97: // 1059:3707
    si = memoryAGet16(es, bx + 534);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fce))
        goto loc_13cb0;
    memoryASet16(ds, 0x5fce, si);
    di = 0x2a22;
    sub_10590();
loc_13cb0: // 1059:3720
    si = memoryAGet16(es, bx + 536);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fd0))
        goto loc_13cc9;
    memoryASet16(ds, 0x5fd0, si);
    di = 0x2a24;
    sub_10590();
loc_13cc9: // 1059:3739
    si = memoryAGet16(es, bx + 538);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fd2))
        goto loc_13ce2;
    memoryASet16(ds, 0x5fd2, si);
    di = 0x2a26;
    sub_10590();
loc_13ce2: // 1059:3752
    si = memoryAGet16(es, bx + 540);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fd4))
        goto loc_13cfb;
    memoryASet16(ds, 0x5fd4, si);
    di = 0x2a28;
    sub_10590();
loc_13cfb: // 1059:376b
    si = memoryAGet16(es, bx + 542);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fd6))
        goto loc_13d14;
    memoryASet16(ds, 0x5fd6, si);
    di = 0x2a2a;
    sub_10590();
loc_13d14: // 1059:3784
    si = memoryAGet16(es, bx + 544);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fd8))
        goto loc_13d2d;
    memoryASet16(ds, 0x5fd8, si);
    di = 0x2a2c;
    sub_10590();
loc_13d2d: // 1059:379d
    bx += memoryAGet16(ds, 0x5654);
    si = memoryAGet16(es, bx + 546);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fda))
        goto loc_13d4a;
    memoryASet16(ds, 0x5fda, si);
    di = 0x2d04;
    sub_10590();
loc_13d4a: // 1059:37ba
    si = memoryAGet16(es, bx + 548);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fdc))
        goto loc_13d63;
    memoryASet16(ds, 0x5fdc, si);
    di = 0x2d06;
    sub_10590();
loc_13d63: // 1059:37d3
    si = memoryAGet16(es, bx + 550);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fde))
        goto loc_13d7c;
    memoryASet16(ds, 0x5fde, si);
    di = 0x2d08;
    sub_10590();
loc_13d7c: // 1059:37ec
    si = memoryAGet16(es, bx + 552);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fe0))
        goto loc_13d95;
    memoryASet16(ds, 0x5fe0, si);
    di = 0x2d0a;
    sub_10590();
loc_13d95: // 1059:3805
    si = memoryAGet16(es, bx + 554);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fe2))
        goto loc_13dae;
    memoryASet16(ds, 0x5fe2, si);
    di = 0x2d0c;
    sub_10590();
loc_13dae: // 1059:381e
    si = memoryAGet16(es, bx + 556);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fe4))
        goto loc_13dc7;
    memoryASet16(ds, 0x5fe4, si);
    di = 0x2d0e;
    sub_10590();
loc_13dc7: // 1059:3837
    si = memoryAGet16(es, bx + 558);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fe6))
        goto loc_13de0;
    memoryASet16(ds, 0x5fe6, si);
    di = 0x2d10;
    sub_10590();
loc_13de0: // 1059:3850
    si = memoryAGet16(es, bx + 560);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fe8))
        goto loc_13df9;
    memoryASet16(ds, 0x5fe8, si);
    di = 0x2d12;
    sub_10590();
loc_13df9: // 1059:3869
    si = memoryAGet16(es, bx + 562);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fea))
        goto loc_13e12;
    memoryASet16(ds, 0x5fea, si);
    di = 0x2d14;
    sub_10590();
loc_13e12: // 1059:3882
    si = memoryAGet16(es, bx + 564);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fec))
        goto loc_13e2b;
    memoryASet16(ds, 0x5fec, si);
    di = 0x2d16;
    sub_10590();
loc_13e2b: // 1059:389b
    si = memoryAGet16(es, bx + 566);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5fee))
        goto loc_13e44;
    memoryASet16(ds, 0x5fee, si);
    di = 0x2d18;
    sub_10590();
loc_13e44: // 1059:38b4
    si = memoryAGet16(es, bx + 568);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ff0))
        goto loc_13e5d;
    memoryASet16(ds, 0x5ff0, si);
    di = 0x2d1a;
    sub_10590();
loc_13e5d: // 1059:38cd
    si = memoryAGet16(es, bx + 570);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ff2))
        goto loc_13e76;
    memoryASet16(ds, 0x5ff2, si);
    di = 0x2d1c;
    sub_10590();
loc_13e76: // 1059:38e6
    si = memoryAGet16(es, bx + 572);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ff4))
        goto loc_13e8f;
    memoryASet16(ds, 0x5ff4, si);
    di = 0x2d1e;
    sub_10590();
loc_13e8f: // 1059:38ff
    si = memoryAGet16(es, bx + 574);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ff6))
        goto loc_13ea8;
    memoryASet16(ds, 0x5ff6, si);
    di = 0x2d20;
    sub_10590();
loc_13ea8: // 1059:3918
    si = memoryAGet16(es, bx + 576);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ff8))
        goto loc_13ec1;
    memoryASet16(ds, 0x5ff8, si);
    di = 0x2d22;
    sub_10590();
loc_13ec1: // 1059:3931
    si = memoryAGet16(es, bx + 578);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ffa))
        goto loc_13eda;
    memoryASet16(ds, 0x5ffa, si);
    di = 0x2d24;
    sub_10590();
loc_13eda: // 1059:394a
    si = memoryAGet16(es, bx + 580);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ffc))
        goto loc_13ef3;
    memoryASet16(ds, 0x5ffc, si);
    di = 0x2d26;
    sub_10590();
loc_13ef3: // 1059:3963
    si = memoryAGet16(es, bx + 582);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x5ffe))
        goto loc_13f0c;
    memoryASet16(ds, 0x5ffe, si);
    di = 0x2d28;
    sub_10590();
loc_13f0c: // 1059:397c
    si = memoryAGet16(es, bx + 584);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x6000))
        goto loc_13f25;
    memoryASet16(ds, 0x6000, si);
    di = 0x2d2a;
    sub_10590();
loc_13f25: // 1059:3995
    si = memoryAGet16(es, bx + 586);
    si <<= 1;
    si = memoryAGet16(ss, bp + si);
    if (si == memoryAGet16(ds, 0x6002))
        goto loc_13f3e;
    memoryASet16(ds, 0x6002, si);
    di = 0x2d2c;
    sub_10590();
loc_13f3e: // 1059:39ae
    bx += memoryAGet16(ds, 0x5654);
    cs = pop();
}
void fixReloc(uint16_t seg)
{
    memoryASet16(seg, 0x0001, memoryAGet16(seg, 0x0001) + seg); // 1305 -> 14f2
    memoryASet16(0x000d + seg, 0x000e, memoryAGet16(0x000d + seg, 0x000e) + seg); // 1303 -> 14f0
    memoryASet16(0x0011 + seg, 0x0000, memoryAGet16(0x0011 + seg, 0x0000) + seg); // 1304 -> 14f1
    memoryASet16(0x012a + seg, 0x000d, memoryAGet16(0x012a + seg, 0x000d) + seg); // 1208 -> 13f5
    memoryASet16(0x0b7a + seg, 0x000c, memoryAGet16(0x0b7a + seg, 0x000c) + seg); // 0e6c -> 1059
    memoryASet16(0x0b7b + seg, 0x0004, memoryAGet16(0x0b7b + seg, 0x0004) + seg); // 0e6c -> 1059
    memoryASet16(0x0bc4 + seg, 0x000d, memoryAGet16(0x0bc4 + seg, 0x000d) + seg); // 1305 -> 14f2
    memoryASet16(0x0bc6 + seg, 0x0008, memoryAGet16(0x0bc6 + seg, 0x0008) + seg); // 1305 -> 14f2
    memoryASet16(0x0bc8 + seg, 0x000e, memoryAGet16(0x0bc8 + seg, 0x000e) + seg); // 1305 -> 14f2
    memoryASet16(0x0bcb + seg, 0x0004, memoryAGet16(0x0bcb + seg, 0x0004) + seg); // 1305 -> 14f2
    memoryASet16(0x0bce + seg, 0x0005, memoryAGet16(0x0bce + seg, 0x0005) + seg); // 1305 -> 14f2
    memoryASet16(0x0bd1 + seg, 0x0006, memoryAGet16(0x0bd1 + seg, 0x0006) + seg); // 1305 -> 14f2
    memoryASet16(0x0bd5 + seg, 0x0002, memoryAGet16(0x0bd5 + seg, 0x0002) + seg); // 1305 -> 14f2
    memoryASet16(0x0bd8 + seg, 0x000e, memoryAGet16(0x0bd8 + seg, 0x000e) + seg); // 1305 -> 14f2
    memoryASet16(0x0be1 + seg, 0x000e, memoryAGet16(0x0be1 + seg, 0x000e) + seg); // 1305 -> 14f2
    memoryASet16(0x0bf9 + seg, 0x000e, memoryAGet16(0x0bf9 + seg, 0x000e) + seg); // 1305 -> 14f2
    memoryASet16(0x0d1c + seg, 0x0007, memoryAGet16(0x0d1c + seg, 0x0007) + seg); // 1305 -> 14f2
}

int GetProcAt(int seg, int ofs)
{
    int map[] = {
        0x1ed0, 0x1ed, 0x0, 0x1ed, 0x15c, 0x1ed0, 0x1ed, 0x220, 0x1ed, 0x288,
        0x1fdf, 0x1ed, 0x10f, 0x1ed, 0x15c, 0x1ffe, 0x1ed, 0x12e, 0x1ed, 0x15c,
        0x202c, 0x1ed, 0x15c, 0x1ed, 0x165, 0x202c, 0x1ed, 0x226, 0x1ed, 0x288,
        0x2035, 0x1ed, 0x165, 0x1ed, 0x1a8, 0x2078, 0x1ed, 0x1a8, 0x1ed, 0x1d5,
        0x20a5, 0x1ed, 0x1d5, 0x1ed, 0x218, 0x20e8, 0x1ed, 0x218, 0x1ed, 0x220,
        0x2109, 0x1ed, 0x239, 0x1ed, 0x289, 0x2159, 0x1ed, 0x289, 0x1ed, 0x2c5,
        0x2195, 0x1ed, 0x2c5, 0x1ed, 0x501, 0x253b, 0x1ed, 0x66b, 0x1ed, 0x82b,
        0x26fb, 0x1ed, 0x82b, 0x1ed, 0x8b2, 0x2853, 0x1ed, 0x983, 0x1ed, 0xaf2,
        0x2b21, 0x1ed, 0xc51, 0x1ed, 0xd52, 0x2c22, 0x1ed, 0xd52, 0x1ed, 0xdb0,
        0x2c80, 0x1ed, 0xdb0, 0x1ed, 0xe3a, 0x2d0a, 0x1ed, 0xe3a, 0x1ed, 0x11f0,
        0x30c0, 0x1ed, 0x11f0, 0x1ed, 0x1261, 0x3131, 0x1ed, 0x1261, 0x1ed, 0x12cf,
        0x319f, 0x1ed, 0x12cf, 0x1ed, 0x15eb, 0x34bb, 0x1ed, 0x15eb, 0x1ed, 0x1680,
        0x34bb, 0x1ed, 0x168a, 0x1ed, 0x1709, 0x3647, 0x1ed, 0x1777, 0x1ed, 0x17d5,
        0x36a5, 0x1ed, 0x17d5, 0x1ed, 0x1843, 0x3713, 0x1ed, 0x1843, 0x1ed, 0x1880,
        0x3750, 0x1ed, 0x1880, 0x1ed, 0x18e3, 0x37b3, 0x1ed, 0x18e3, 0x1ed, 0x1920,
        0x37f0, 0x1ed, 0x1920, 0x1ed, 0x194f, 0x381f, 0x1ed, 0x194f, 0x1ed, 0x19d3,
        0x38a3, 0x1ed, 0x19d3, 0x1ed, 0x1a2c, 0x43c4, 0x1ed, 0x24f4, 0x1ed, 0x252a,
        0x43c4, 0x1ed, 0x26ab, 0x1ed, 0x26e2, 0x46c8, 0x1ed, 0x27f8, 0x1ed, 0x290e,
        0x4805, 0x1ed, 0x2935, 0x1ed, 0x297e, 0x484e, 0x1ed, 0x297e, 0x1ed, 0x29bd,
        0x488d, 0x1ed, 0x29bd, 0x1ed, 0x2a3b, 0x490b, 0x1ed, 0x2a3b, 0x1ed, 0x2ae9,
        0x49b9, 0x1ed, 0x2ae9, 0x1ed, 0x2b9a, 0x4a6a, 0x1ed, 0x2b9a, 0x1ed, 0x2bdf,
        0x4aaf, 0x1ed, 0x2bdf, 0x1ed, 0x2c2a, 0x4afa, 0x1ed, 0x2c2a, 0x1ed, 0x2c6d,
        0x4b3d, 0x1ed, 0x2c6d, 0x1ed, 0x2c97, 0x4b67, 0x1ed, 0x2c97, 0x1ed, 0x303c,
        0x5166, 0x1ed, 0x3296, 0x1ed, 0x3360, 0x5235, 0x1ed, 0x3365, 0x1ed, 0x3418,
        0x52e8, 0x1ed, 0x3418, 0x1ed, 0x3592, 0x5462, 0x1ed, 0x3592, 0x1ed, 0x35b2,
        0x5482, 0x1ed, 0x35b2, 0x1ed, 0x35d2, 0x54a2, 0x1ed, 0x35d2, 0x1ed, 0x3867,
        0x5737, 0x1ed, 0x3867, 0x1ed, 0x3b7c, 0x5a5b, 0x1ed, 0x3b8b, 0x1ed, 0x3c8a,
        0x5b69, 0x1ed, 0x3c99, 0x1ed, 0x3e04, 0x5ce2, 0x1ed, 0x3e12, 0x1ed, 0x3ec8,
        0x5d98, 0x1ed, 0x3ec8, 0x1ed, 0x3eff, 0x5d98, 0x1ed, 0x3f2d, 0x1ed, 0x4046,
        0x5f24, 0x1ed, 0x4054, 0x1ed, 0x40ef, 0x60c8, 0x1ed, 0x41f8, 0x1ed, 0x4260,
        0x6130, 0x1ed, 0x4260, 0x1ed, 0x42ac, 0x617c, 0x1ed, 0x42ac, 0x1ed, 0x42ea,
        0x61ba, 0x1ed, 0x42ea, 0x1ed, 0x4590, 0x658a, 0x1ed, 0x46ba, 0x1ed, 0x47e8,
        0x6a39, 0x1ed, 0x4b69, 0x1ed, 0x4fa9, 0x6e79, 0x1ed, 0x4fa9, 0x1ed, 0x51fa,
        0x70ca, 0x1ed, 0x51fa, 0x1ed, 0x533c, 0x70ca, 0x1ed, 0x533d, 0x1ed, 0x53c0,
        0x7290, 0x1ed, 0x53c0, 0x1ed, 0x55a3, 0x7473, 0x1ed, 0x55a3, 0x1ed, 0x56c8,
        0x75ab, 0x1ed, 0x56db, 0x1ed, 0x57a7, 0x75ab, 0x1ed, 0x57e4, 0x1ed, 0x57fe,
        0x76e1, 0x1ed, 0x5811, 0x1ed, 0x58af, 0x777f, 0x1ed, 0x58af, 0x1ed, 0x59ea,
        0x777f, 0x1ed, 0x59ec, 0x1ed, 0x5a26, 0x7909, 0x1ed, 0x5a39, 0x1ed, 0x5b35,
        0x7b0a, 0x1ed, 0x5c3a, 0x1ed, 0x5c58, 0x7b28, 0x1ed, 0x5c58, 0x1ed, 0x5cb8,
        0x7b88, 0x1ed, 0x5cb8, 0x1ed, 0x5d63, 0x7c33, 0x1ed, 0x5d63, 0x1ed, 0x5de4,
        0x7cb4, 0x1ed, 0x5de4, 0x1ed, 0x5e41, 0x7dee, 0x1ed, 0x5f1e, 0x1ed, 0x604e,
        0x7f1e, 0x1ed, 0x604e, 0x1ed, 0x608c, 0x7f5c, 0x1ed, 0x608c, 0x1ed, 0x60be,
        0x7f8e, 0x1ed, 0x60be, 0x1ed, 0x611a, 0x7fea, 0x1ed, 0x611a, 0x1ed, 0x614b,
        0x801b, 0x1ed, 0x614b, 0x1ed, 0x617c, 0x8138, 0x1ed, 0x6268, 0x1ed, 0x62d2,
        0x81a2, 0x1ed, 0x62d2, 0x1ed, 0x632a, 0x81fa, 0x1ed, 0x632a, 0x1ed, 0x6349,
        0x823b, 0x1ed, 0x636b, 0x1ed, 0x63a9, 0x8346, 0x1ed, 0x6476, 0x1ed, 0x6498,
        0x8487, 0x1ed, 0x65b7, 0x1ed, 0x665d, 0x852d, 0x1ed, 0x665d, 0x1ed, 0x6698,
        0x852d, 0x1ed, 0x6699, 0x1ed, 0x67a9, 0x8679, 0x1ed, 0x67a9, 0x1ed, 0x6884,
        0x8754, 0x1ed, 0x6884, 0x1ed, 0x6a30, 0x8900, 0x1ed, 0x6a30, 0x1ed, 0x6b62,
        0x8a32, 0x1ed, 0x6b62, 0x1ed, 0x6bd4, 0x8aa4, 0x1ed, 0x6bd4, 0x1ed, 0x6c49,
        0x8b19, 0x1ed, 0x6c49, 0x1ed, 0x6c8d, 0x8b5d, 0x1ed, 0x6c8d, 0x1ed, 0x6ce6,
        0x8bb6, 0x1ed, 0x6ce6, 0x1ed, 0x778e, 0x9751, 0x1ed, 0x7881, 0x1ed, 0x7913,
        0x97e3, 0x1ed, 0x7913, 0x1ed, 0x7a07, 0x97e3, 0x1ed, 0x7a08, 0x1ed, 0x7ab6,
        0x9ad4, 0x1ed, 0x7c04, 0x1ed, 0x805e, 0x9f2e, 0x1ed, 0x805e, 0x1ed, 0x8132,
        0xa002, 0x1ed, 0x8132, 0x1ed, 0x8150, 0xa020, 0x1ed, 0x8150, 0x1ed, 0x818c,
        0xa05c, 0x1ed, 0x818c, 0x1ed, 0x8919, 0xa7e9, 0x1ed, 0x8919, 0x1ed, 0x8adf,
        0xa9af, 0x1ed, 0x8adf, 0x1ed, 0x8f26, 0xadf6, 0x1ed, 0x8f26, 0x1ed, 0x8f90,
        0xae60, 0x1ed, 0x8f90, 0x1ed, 0x8ff0, 0xaec0, 0x1ed, 0x8ff0, 0x1ed, 0x913a,
        0xaec0, 0x1ed, 0x9152, 0x1ed, 0x9286, 0xb15f, 0x1ed, 0x928f, 0x1ed, 0x95ec,
        0xb4cd, 0x1ed, 0x95fd, 0x1ed, 0x96a7, 0xb580, 0x1ed, 0x96b0, 0x1ed, 0x96e2,
        0xb5b2, 0x1ed, 0x96e2, 0x1ed, 0x9732, 0xb602, 0x1ed, 0x9732, 0x1ed, 0x97ab,
        0xb67b, 0x1ed, 0x97ab, 0x1ed, 0x97d3, 0xb6a3, 0x1ed, 0x97d3, 0x1ed, 0x97f0,
        0xb6c0, 0x1ed, 0x97f0, 0x1ed, 0x984c, 0xb71c, 0x1ed, 0x984c, 0x1ed, 0x986c,
        0xb73c, 0x1ed, 0x986c, 0x1ed, 0x9a24, 0xb8f4, 0x1ed, 0x9a24, 0x1ed, 0x9a59,
        0xb929, 0x1ed, 0x9a59, 0x1ed, 0x9ab4, 0xb984, 0x1ed, 0x9ab4, 0x1ed, 0x9c4e,
        0xbb1e, 0x1ed, 0x9c4e, 0x1ed, 0x9d73, 0xbc43, 0x1ed, 0x9d73, 0x1ed, 0x9db4,
        0xbc84, 0x1ed, 0x9db4, 0x1ed, 0x9e32, 0xbd02, 0x1ed, 0x9e32, 0x1ed, 0x9e6d,
        0xbd3d, 0x1ed, 0x9e6d, 0x1ed, 0x9f48, 0xbe82, 0x1ed, 0x9fb2, 0x1ed, 0xa1d4,
        0xc0a4, 0x1ed, 0xa1d4, 0x1ed, 0xa1eb, 0xc0bb, 0x1ed, 0xa1eb, 0x1ed, 0xa262,
        0xc132, 0x1ed, 0xa262, 0x1ed, 0xa33b, 0xc20b, 0x1ed, 0xa33b, 0x1ed, 0xa497,
        0xc367, 0x1ed, 0xa497, 0x1ed, 0xa566, 0xc436, 0x1ed, 0xa566, 0x1ed, 0xa5bc,
        0xc48c, 0x1ed, 0xa5bc, 0x1ed, 0xa616, 0xc4e6, 0x1ed, 0xa616, 0x1ed, 0xa703,
        0xc4e6, 0x1ed, 0xa704, 0x1ed, 0xa7f0, 0xc4e6, 0x1ed, 0xa7f1, 0x1ed, 0xa91b,
        0xc4e6, 0x1ed, 0xa91c, 0x1ed, 0xaa08, 0xc4e6, 0x1ed, 0xaa09, 0x1ed, 0xaa95,
        0xc965, 0x1ed, 0xaa95, 0x1ed, 0xae0c, 0xccec, 0x1ed, 0xae1c, 0x1ed, 0xb185,
        0xd055, 0x1ed, 0xb185, 0x1ed, 0xb243, 0xd113, 0x1ed, 0xb243, 0x1ed, 0xb364,
        0xd234, 0x1ed, 0xb364, 0x1ed, 0xb401, 0xd234, 0x1ed, 0xb402, 0x1ed, 0xb4df,
        0xd3af, 0x1ed, 0xb4df, 0x1ed, 0xb640, 0xd510, 0x1ed, 0xb640, 0x1ed, 0xb669,
        0xd510, 0x1ed, 0xb66a, 0x1ed, 0xb6cc, 0xd510, 0x1ed, 0xb6cd, 0x1ed, 0xb735,
        0xd606, 0x1ed, 0xb736, 0x1ed, 0xb750, 0xd620, 0x1ed, 0xb750, 0x1ed, 0xb7b0,
        0xd620, 0x1ed, 0xb7b1, 0x1ed, 0xb87c, 0xd74c, 0x1ed, 0xb87c, 0x1ed, 0xb8a9,
        0xd74c, 0x1ed, 0xb8aa, 0x1ed, 0xb8da, 0xd7b0, 0x1ed, 0xb8e0, 0x1ed, 0xb939,
        0xd809, 0x1ed, 0xb939, 0x1ed, 0xbab6, 0xd986, 0x1ed, 0xbab6, 0x1ed, 0xbb2d,
        0xd9fd, 0x1ed, 0xbb2d, 0x1ed, 0xbc3b, 0xdb0b, 0x1ed, 0xbc3b, 0x1ed, 0xbc54,
        0xdb24, 0x1ed, 0xbc54, 0x1ed, 0xbc6f, 0xdb3f, 0x1ed, 0xbc6f, 0x1ed, 0xbc95,
        0xdb65, 0x1ed, 0xbc95, 0x1ed, 0xbcbb, 0xdc65, 0x1ed, 0xbd95, 0x1ed, 0xbdb0,
        0xdc80, 0x1ed, 0xbdb0, 0x1ed, 0xbdce, 0xdc9e, 0x1ed, 0xbdce, 0x1ed, 0xbe1a,
        0xdcea, 0x1ed, 0xbe1a, 0x1ed, 0xbe34, 0xdcea, 0x1ed, 0xbe35, 0x1ed, 0xbe65,
        0xdd35, 0x1ed, 0xbe65, 0x1ed, 0xbeb7, 0xdd87, 0x1ed, 0xbeb7, 0x1ed, 0xbef3,
        0xddc3, 0x1ed, 0xbef3, 0x1ed, 0xbf2a, 0xddfa, 0x1ed, 0xbf2a, 0x1ed, 0xbf44,
        0xde14, 0x1ed, 0xbf44, 0x1ed, 0xbf63, 0xde33, 0x1ed, 0xbf63, 0x1ed, 0xbf7f,
        0xde4f, 0x1ed, 0xbf7f, 0x1ed, 0xbf96, 0xde67, 0x1ed, 0xbf97, 0x1ed, 0xbfe8,
        0xde67, 0x1ed, 0xbfe9, 0x1ed, 0xbff1, 0xde67, 0x1ed, 0xbff2, 0x1ed, 0xc013,
        0xdee3, 0x1ed, 0xc013, 0x1ed, 0xc05c, 0xdf2c, 0x1ed, 0xc05c, 0x1ed, 0xc0ac,
        0xdf7c, 0x1ed, 0xc0ac, 0x1ed, 0xc0bd, 0xdf7c, 0x1ed, 0xc0be, 0x1ed, 0xc0ce,
        0xdf9e, 0x1ed, 0xc0ce, 0x1ed, 0xc0e2, 0xdfb2, 0x1ed, 0xc0e2, 0x1ed, 0xc104,
        0xdfd4, 0x1ed, 0xc104, 0x1ed, 0xc128, 0xe039, 0x1ed, 0xc169, 0x1ed, 0xc1af,
        0xe07f, 0x1ed, 0xc1af, 0x1ed, 0xc1ff, 0xe167, 0x1ed, 0xc297, 0x1ed, 0xc2c8,
        0xe1a5, 0x1ed, 0xc2d5, 0x1ed, 0xc2f6, 0xe22f, 0x1ed, 0xc35f, 0x1ed, 0xc3c5,
        0xe3e3, 0x1ed, 0xc513, 0x1ed, 0xc552, 0xe422, 0x1ed, 0xc552, 0x1ed, 0xc587,
        0xe47b, 0x1ed, 0xc5ab, 0x1ed, 0xc5d6, 0xe4a7, 0x1ed, 0xc5d7, 0x1ed, 0xc5fa,
        0xe4ca, 0x1ed, 0xc5fa, 0x1ed, 0xc678, 0xe548, 0x1ed, 0xc678, 0x1ed, 0xc6b7,
        0xe587, 0x1ed, 0xc6b7, 0x1ed, 0xc724, 0xe5f4, 0x1ed, 0xc724, 0x1ed, 0xc7a6,
        0xe676, 0x1ed, 0xc7a6, 0x1ed, 0xc7dc, 0xe6ac, 0x1ed, 0xc7dc, 0x1ed, 0xc842,
        0xe712, 0x1ed, 0xc842, 0x1ed, 0xc8a4, 0xe7b5, 0x1ed, 0xc8e5, 0x1ed, 0xc935,
        0xe805, 0x1ed, 0xc935, 0x1ed, 0xc94c, 0xe81c, 0x1ed, 0xc94c, 0x1ed, 0xc966,
        0xe836, 0x1ed, 0xc966, 0x1ed, 0xca68, 0xe94c, 0x1ed, 0xca7c, 0x1ed, 0xcbae,
        0xea7e, 0x1ed, 0xcbae, 0x1ed, 0xcbed, 0xeabd, 0x1ed, 0xcbed, 0x1ed, 0xcc52,
        0xeb22, 0x1ed, 0xcc52, 0x1ed, 0xcd1e, 0xec06, 0x1ed, 0xcd36, 0x1ed, 0xcd62,
        0xec32, 0x1ed, 0xcd62, 0x1ed, 0xce04, 0xec32, 0x1ed, 0xce06, 0x1ed, 0xce51,
        0xedce, 0x1ed, 0xcefe, 0x1ed, 0xcf20, 0xedf0, 0x1ed, 0xcf20, 0x1ed, 0xcf51,
        0xee3d, 0x1ed, 0xcf6d, 0x1ed, 0xcf88, 0xee58, 0x1ed, 0xcf88, 0x1ed, 0xcfa6,
        0xee76, 0x1ed, 0xcfa6, 0x1ed, 0xcfcd, 0xeea0, 0x1ed, 0xcfd0, 0x1ed, 0xcfde,
        0xeeae, 0x1ed, 0xcfde, 0x1ed, 0xd062, 0xef32, 0x1ed, 0xd062, 0x1ed, 0xd082,
        0xef52, 0x1ed, 0xd082, 0x1ed, 0xd15c, 0xf02c, 0x1ed, 0xd15c, 0x1ed, 0xd19d,
        0xf07c, 0x1ed, 0xd1ac, 0x1ed, 0xd1bd, 0xf08d, 0x1ed, 0xd1bd, 0x1ed, 0xd1f5,
        0xf0c5, 0x1ed, 0xd1f5, 0x1ed, 0xd20f, 0xf134, 0x1ed, 0xd264, 0x1ed, 0xd26f,
        0xf13f, 0x1ed, 0xd26f, 0x1ed, 0xd296, 0xf166, 0x1ed, 0xd296, 0x1ed, 0xd2d3,
        0xf1a3, 0x1ed, 0xd2d3, 0x1ed, 0xd2e4, 0xf1b4, 0x1ed, 0xd2e4, 0x1ed, 0xd30d,
        0xf1dd, 0x1ed, 0xd30d, 0x1ed, 0xd38a, 0xf25a, 0x1ed, 0xd38a, 0x1ed, 0xd3b1,
        0xf29b, 0x1ed, 0xd3cb, 0x1ed, 0xd3f0, 0xf2c0, 0x1ed, 0xd3f0, 0x1ed, 0xd411,
        0xf2e1, 0x1ed, 0xd411, 0x1ed, 0xd439, 0xf309, 0x1ed, 0xd439, 0x1ed, 0xd451,
        0xf321, 0x1ed, 0xd451, 0x1ed, 0xd473, 0xf343, 0x1ed, 0xd473, 0x1ed, 0xd48c,
        0xf35c, 0x1ed, 0xd48c, 0x1ed, 0xd49e, 0xf36e, 0x1ed, 0xd49e, 0x1ed, 0xd5cb,
        0xf49b, 0x1ed, 0xd5cb, 0x1ed, 0xd617, 0xf4e7, 0x1ed, 0xd617, 0x1ed, 0xd623,
        0xf4f3, 0x1ed, 0xd623, 0x1ed, 0xd62f, 0xf4ff, 0x1ed, 0xd62f, 0x1ed, 0xd6e4,
        0xf5b4, 0x1ed, 0xd6e4, 0x1ed, 0xd6fe, 0xf5ce, 0x1ed, 0xd6fe, 0x1ed, 0xd71a,
        0xf5ea, 0x1ed, 0xd71a, 0x1ed, 0xd753, 0xf623, 0x1ed, 0xd753, 0x1ed, 0xd777,
        0xf647, 0x1ed, 0xd777, 0x1ed, 0xd791, 0xf679, 0x1ed, 0xd7a9, 0x1ed, 0xd7c3,
        0xf679, 0x1ed, 0xd809, 0x1ed, 0xd89f, 0xf679, 0x1ed, 0xd8a9, 0x1ed, 0xd94d,
        0xf679, 0x1ed, 0xd96f, 0x1ed, 0xd9eb, 0xf679, 0x1ed, 0xdad9, 0x1ed, 0xdbd1,
        0xf679, 0x1ed, 0xdc0d, 0x1ed, 0xdc3d, 0xf693, 0x1ed, 0xd7c3, 0x1ed, 0xd7d0,
        0xf6a0, 0x1ed, 0xd7d0, 0x1ed, 0xd809, 0xf6a9, 0x1ed, 0xd7d9, 0x1ed, 0xd808,
        0xfb3d, 0x1ed, 0xdc6d, 0x1ed, 0xdcb4, 0xfb9c, 0x1ed, 0xdccc, 0x1ed, 0xdd2e,
        0xfbfe, 0x1ed, 0xdd2e, 0x1ed, 0xddc8, 0xfc6f, 0x1ed, 0xdd9f, 0x1ed, 0xddc8,
        0xfc98, 0x1ed, 0xddc8, 0x1ed, 0xddfe, 0xfcce, 0x1ed, 0xddfe, 0x1ed, 0xde27,
        0xfcf7, 0x1ed, 0xde27, 0x1ed, 0xde88, 0xfd58, 0x1ed, 0xde88, 0x1ed, 0xdec1,
        0xfd91, 0x1ed, 0xdec1, 0x1ed, 0xdee4, 0xfdb4, 0x1ed, 0xdee4, 0x1ed, 0xdf61,
        0xff73, 0x1ed, 0xe0a3, 0x1ed, 0xe0aa, 0xff73, 0x1ed, 0xe0c0, 0x1ed, 0xe141,
        0xff73, 0x1ed, 0xe144, 0x1ed, 0xe151, 0xff82, 0x1ed, 0xe0b2, 0x1ed, 0xe0ba,
        0xff82, 0x1ed, 0xe0c0, 0x1ed, 0xe151, 0x10021, 0x1ed, 0xe151, 0x1ed, 0xe172,
        0x10042, 0x1ed, 0xe172, 0x1ed, 0xe192, 0x10062, 0x1ed, 0xe192, 0x1ed, 0xe1b3,
        0x10083, 0x1ed, 0xe1b3, 0x1ed, 0xe1f7, 0x10083, 0x1ed, 0xe215, 0x1ed, 0xe23b,
        0x1010b, 0x1ed, 0xe23b, 0x1ed, 0xe26a, 0x1010b, 0x1ed, 0xe27d, 0x1ed, 0xe29b,
        0x1016b, 0x1ed, 0xe29b, 0x1ed, 0xe2ba, 0x1018a, 0x1ed, 0xe2bb, 0x1ed, 0xe2c0,
        0x1018a, 0x1ed, 0xe2c5, 0x1ed, 0xe2e0, 0x101c0, 0x1ed, 0xe2f0, 0x1ed, 0xe30d,
        0x101dd, 0x1ed, 0xe30d, 0x1ed, 0xe347, 0x10217, 0x1ed, 0xe347, 0x1ed, 0xe39c,
        0x10250, 0x1ed, 0xe380, 0x1ed, 0xe39c, 0x1026c, 0x1ed, 0xe39c, 0x1ed, 0xe3bf,
        0x1028f, 0x1ed, 0xe3bf, 0x1ed, 0xe41f, 0x102ef, 0x1ed, 0xe41f, 0x1ed, 0xe45f,
        0x1032f, 0x1ed, 0xe45f, 0x1ed, 0xe488, 0x10358, 0x1ed, 0xe488, 0x1ed, 0xe4a1,
        0x10433, 0x1ed, 0xe563, 0x1ed, 0xe57a, 0x1044a, 0x1ed, 0xe57a, 0x1ed, 0xe59b,
        0x10471, 0x1ed, 0x223, 0x1ed, 0x288, 0x10471, 0x1ed, 0xe5a1, 0x1ed, 0xe630,
        0x10471, 0x1ed, 0xe65b, 0x1ed, 0xe6b2, 0x10500, 0x1ed, 0xe630, 0x1ed, 0xe658,
        0x10590, 0x1059, 0x0, 0x1059, 0x4d, 0x105dd, 0x1059, 0x4d, 0x1059, 0x1d00,
        0x12290, 0x1059, 0x1d00, 0x1059, 0x39b3,     };
    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs <= map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
/*
{{0x01ed, 0xc5fa}, 4}, // sub_e4ca ret
{{0x01ed, 0xc7dc}, 2}, // sub_e6ac ret
{{0x01ed, 0xca7c}, 6}, // sub_e94c ret
{{0x01ed, 0xcfa6}, 6}, // sub_ee76 ret
{{0x01ed, 0xd296}, 2}, // sub_f166 ret
{{0x01ed, 0xd30d}, 12}, // sub_f1dd ret
{{0x01ed, 0xd473}, 4}, // sub_f343 ret
{{0x01ed, 0xd48c}, 2}, // sub_f35c ret
{{0x01ed, 0xd7a9}, 8}, // sub_f679 ret
{{0x01ed, 0xe0a3}, 10}, // sub_ff73 retf
{{0x01ed, 0xe0b2}, 10}, // sub_ff82 retf
{{0x01ed, 0xe29b}, 10}, // sub_1016b retf
*/
