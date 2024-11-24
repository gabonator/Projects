
function* start() {
    headerSize = 0x08f0;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x0c41;
    sp = 0x364c;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/tunneler/dos", "TUNNELER.EXE", 39552);
    yield* sub_79ed();
}
function callIndirect(seg, ofs) {
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
var sub_1ed0_counter = 0;
function* sub_1ed0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0200;
        memory16set(ds, 0x12f5, 0x0100);
        r8[al] = 0x16;
        push(r16[ax]);
        di = 0x12f5;
        push(ds);
        push(di);
        push(cs);
        cs = 0x08d0;
    {if (sub_1ed0_counter++%500 == 0) yield* sync();}
        sub_8db2();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x1307);
        r16[ax] &= 0x0040;
        if (r16[ax]) {
            pc = 0x1f39;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x12f5, r16[ax]);
        r8[al] = 0x16;
        push(r16[ax]);
        di = 0x12f5;
        push(ds);
        push(di);
        push(cs);
        cs = 0x08d0;
        sub_8db2();
        assert(cs == 0x01ed);
        di = bp - 0x100;
        push(ss);
        push(di);
        r8[al] = memory[ds*16 + 0x12f5];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9b50();
        assert(cs == 0x01ed);
        di = bp - 0x200;
        push(ss);
        push(di);
        r8[al] = memory[ds*16 + 0x12f6];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9b50();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_9ac2();
        assert(cs == 0x01ed);
        di = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        push(es);
        push(di);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9a4f();
        assert(cs == 0x01ed);
        pc = 0x1f4c;
        break;
    case 0x1f39:
        di = 0x0068;
        push(ds);
        push(di);
        di = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        push(es);
        push(di);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9a4f();
        assert(cs == 0x01ed);
    case 0x1f4c:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_21c4() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = memory[ss*16 + bp + 4];
    memory[ds*16 + 0x1311] = r8[al];
    r16[ax] = 0;
    push(cs);
    cs = 0x0947;
    sub_9663();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
function sub_21da() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = 0x00;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x08e1;
    sub_901d();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_21ee() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memory[ss*16 + bp - 17] = 0x00;
    memory16set(ss, bp - 14, 0x3300);
    memory[ss*16 + bp - 19] = 0x02;
    r8[al] = 0x10;
    push(r16[ax]);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2();
    assert(cs == 0x01ed);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_2212() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[cx] = 0x000c;
        r16[ax] <<= r8[cl];
        r16[bx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0;
        r16[cx] = 0x0008;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0;
        r16[ax] += r16[dx];
        r16[ax] += r16[bx];
        memory16set(ds, 0x042e, r16[ax]);
        r16[ax] = memory16get(ss, bp + 16);
        memory16set(ds, 0x0426, r16[ax]);
        r16[ax] = memory16get(ss, bp + 12);
        memory16set(ds, 0x0428, r16[ax]);
        r16[ax] = memory16get(ss, bp + 14);
        memory16set(ds, 0x042a, r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        memory16set(ds, 0x042c, r16[ax]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(es);
        r16[bx] = memory16get(ds, 0x0428);
        r16[bx] -= memory16get(ds, 0x0426);
        r16[bx]++;
        r16[cx] = memory16get(ds, 0x042c);
        r16[cx] -= memory16get(ds, 0x042a);
        r16[cx]++;
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[ax] = 0x00a0;
        mul16(memory16get(ds, 0x042a));
        r16[ax] += memory16get(ds, 0x0426);
        r16[ax] += memory16get(ds, 0x0426);
        di = r16[ax];
        r16[ax] = memory16get(ds, 0x042e);
    case 0x2282:
        r16[dx] = r16[cx];
        r16[cx] = r16[bx];
        push(di);
        rep_stosw_video_forward();
        di = pop();
        di += 0x00a0;
        r16[cx] = r16[dx];
        if (--r16[cx]) {
            pc = 0x2282;
            break;
        }
        es = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 14;
        return;
    } while (1);
}
function sub_229e() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = memory[ss*16 + bp + 4];
    r8[ah] = 0;
    r16[cx] = 0x0008;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax];
    r8[al] = memory[ss*16 + bp + 6];
    r8[ah] = 0;
    r16[ax] += r16[dx];
    r16[bx] = r16[ax];
    r16[ax] = 0xb800;
    push(r16[ax]);
    r16[ax] = memory16get(ss, bp + 8);
    r16[cx] = 0x00a0;
    imul16(r16[cx]);
    r16[ax] += memory16get(ss, bp + 10);
    r16[ax] += memory16get(ss, bp + 10);
    di = r16[ax];
    es = pop();
    videoSet16(es, di, r16[bx]);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
function sub_22d4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(ds, 0x0440, r16[ax]);
        if (memory[ss*16 + bp + 4] == 0x00) {
            pc = 0x22f6;
            break;
        }
        r16[ax] = 0x7530;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ds, 0x043e, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x0442, r16[ax]);
        pc = 0x2324;
        break;
    case 0x22f6:
        di = memory16get(ss, bp + 8);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        r16[ax] = di;
        r16[dx] = 0;
        r16[cx] = r16[ax];
        r16[bx] = r16[dx];
        r16[ax] = memory16get(ss, bp + 10);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        flags.carry = (r16[ax] + r16[cx]) >= 0x10000;
        r16[ax] += r16[cx];
        r16[dx] += r16[bx] + flags.carry;
        memory16set(ds, 0x043e, r16[ax]);
        di = memory16get(ss, bp + 8);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        r16[ax] = es;
        memory16set(ds, 0x0442, r16[ax]);
    case 0x2324:
        push(si);
        push(di);
        push(es);
        push(r16[cx]);
        si = memory16get(ds, 0x043e);
        di = 0xb800;
        es = di;
        di = memory16get(ds, 0x0440);
        push(ds);
        r16[cx] = memory16get(ds, 0x0442);
        ds = r16[cx] ? r16[cx] : cs;
        r16[cx] = 0x0047;
    case 0x233f:
        push(r16[cx]);
        r16[cx] = 0x0026;
    case 0x2343:
        si &= 0xffff;
        movsb_video_data_forward();
        di++;
        if (--r16[cx]) {
            pc = 0x2343;
            break;
        }
        r16[cx] = pop();
        si += 0x01da;
        di += 0x0054;
        if (--r16[cx]) {
            pc = 0x233f;
            break;
        }
        ds = pop();
        r16[cx] = pop();
        es = pop();
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 8;
        return;
    } while (1);
}
function sub_235c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] >>= 1;
        memory16set(ss, bp - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] &= 0x0001;
        if (r16[ax] != 0x0001) {
            pc = 0x23b1;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0;
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x0f;
        r8[ah] = 0;
        r16[ax] |= r16[dx];
        r8[dl] = r8[al];
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = r8[dl];
        pc = 0x23de;
        break;
    case 0x23b1:
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0xf0;
        r8[al] |= memory[ss*16 + bp + 4];
        r8[dl] = r8[al];
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = r8[dl];
    case 0x23de:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_23e4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0001;
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] &= 0x0001;
        if (r16[ax] != 0x0001) {
            pc = 0x2418;
            break;
        }
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] >>= 1;
        di = memory16get(ss, bp + 4);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0xf0;
        r8[ah] = 0;
        r16[cx] = 0x0004;
        r16[ax] >>= r8[cl];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x2432;
        break;
    case 0x2418:
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] >>= 1;
        di = memory16get(ss, bp + 4);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x0f;
        memory[ss*16 + bp - 1] = r8[al];
    case 0x2432:
        r8[al] = memory[ss*16 + bp - 1];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 4;
        return;
    } while (1);
}
function sub_243b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(ds, 0x0430, r16[ax]);
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(ds, 0x0432, r16[ax]);
        memory16set(ds, 0x0434, 0x0007);
        memory16set(ds, 0x0436, 0x0007);
        r16[ax] = memory16get(ss, bp + 4);
        memory16set(ds, 0x043c, r16[ax]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(es);
        r16[ax] = memory16get(ds, 0x0432);
        r8[cl] = 0x05;
        r16[ax] <<= r8[cl];
        r16[ax] += memory16get(ds, 0x0438);
        es = r16[ax];
        r16[dx] = memory16get(ds, 0x0430);
        r16[dx] += memory16get(ds, 0x043a);
        si = memory16get(ds, 0x043c);
        r16[bx] = memory16get(ds, 0x0434);
        r16[cx] = memory16get(ds, 0x0436);
    case 0x2484:
        push(r16[dx]);
        push(r16[cx]);
        r16[cx] = r16[bx];
    case 0x2488:
        r8[al] = memory[ds*16 + si];
        if (r8[al] == 0x10) {
            pc = 0x24b1;
            break;
        }
        di = r16[dx];
        di >>= 1;
        if (!(r16[dx] & 0x0001)) {
            pc = 0x24aa;
            break;
        }
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        memory[es*16 + di] = memory[es*16 + di] & 0x0f;
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
        pc = 0x24b1;
        break;
    case 0x24aa:
        memory[es*16 + di] = memory[es*16 + di] & 0xf0;
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
    case 0x24b1:
        r16[dx]++;
        si++;
        if (--r16[cx]) {
            pc = 0x2488;
            break;
        }
        r16[cx] = pop();
        r16[dx] = pop();
        r8[dh] += 0x04;
        if (--r16[cx]) {
            pc = 0x2484;
            break;
        }
        es = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_24c9() {
    push(0x7777);
    push(bp);
    bp = sp;
    memory16set(ss, bp + 10, memory16get(ss, bp + 10) - 0x0003);
    memory16set(ss, bp + 8, memory16get(ss, bp + 8) - 0x0003);
    push(memory16get(ss, bp + 10));
    push(memory16get(ss, bp + 8));
    r8[al] = memory[ss*16 + bp + 4];
    r8[ah] = 0;
    r16[dx] = 0x0031;
    mul16(r16[dx]);
    r16[cx] = r16[ax];
    r8[al] = memory[ss*16 + bp + 6];
    r8[ah] = 0;
    r16[dx] = 0x0188;
    mul16(r16[dx]);
    di = r16[ax];
    di += r16[cx];
    r16[ax] = di + 0xabc;
    push(r16[ax]);
    sub_243b();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
function sub_2502() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0029;
        r16[ax] = 0;
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x2512;
        break;
    case 0x250f:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x2512:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x251c;
        break;
    case 0x2519:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x251c:
        r16[ax] = memory16get(ss, bp - 2);
        imul16(memory16get(ss, bp - 2));
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        imul16(memory16get(ss, bp - 4));
        r16[ax] += r16[cx];
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(cs);
        cs = 0x0947;
        sub_a06b();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_a11e();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_a06f();
        assert(cs == 0x01ed);
        r8[bl] = r8[al];
        r16[ax] = memory16get(ss, bp - 2);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000b;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        memory[ds*16 + di + 4732] = r8[bl];
        if (memory16get(ss, bp - 2) != 0x000a) {
            pc = 0x2519;
            break;
        }
        if (memory16get(ss, bp - 4) != 0x000a) {
            pc = 0x250f;
            break;
        }
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x2569;
        break;
    case 0x2566:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x2569:
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x2573;
        break;
    case 0x2570:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x2573:
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x257d;
        break;
    case 0x257a:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x257d:
        r16[ax] = memory16get(ss, bp - 8);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        r8[al] = memory[ds*16 + di + 49];
        memory[ss*16 + bp - 9] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2748] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2846] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2944] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 3042] = r8[al];
        r16[ax] = memory16get(ss, bp - 8);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        r8[al] = memory[ds*16 + di];
        memory[ss*16 + bp - 9] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2797] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2895] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 2993] = r8[al];
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        r16[ax] = 0x0006;
        r16[ax] -= memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        memory[ds*16 + di + 3091] = r8[al];
        if (memory16get(ss, bp - 6) == 0x0006) {
            pc = 0x26f8;
            break;
        }
        pc = 0x257a;
        break;
    case 0x26f8:
        if (memory16get(ss, bp - 8) == 0x0006) {
            pc = 0x2701;
            break;
        }
        pc = 0x2570;
        break;
    case 0x2701:
        if (memory16get(ss, bp - 4) == 0x0002) {
            pc = 0x270a;
            break;
        }
        pc = 0x2566;
        break;
    case 0x270a:
        r16[ax] = 0;
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x2714;
        break;
    case 0x2711:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x2714:
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x271e;
        break;
    case 0x271b:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x271e:
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x2728;
        break;
    case 0x2725:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x2728:
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r8[al] = memory[ds*16 + di + 3532];
        push(r16[ax]);
        di = bp - 0x29;
        push(ss);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9c51();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x09;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_9cd5();
        assert(cs == 0x01ed);
        if (flags.zero) {
            pc = 0x278c;
            break;
        }
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        memory[ds*16 + di + 3532] += 1;
    case 0x278c:
        if (memory16get(ss, bp - 6) != 0x0006) {
            pc = 0x2725;
            break;
        }
        if (memory16get(ss, bp - 8) != 0x0006) {
            pc = 0x271b;
            break;
        }
        if (memory16get(ss, bp - 4) == 0x0007) {
            pc = 0x27a1;
            break;
        }
        pc = 0x2711;
        break;
    case 0x27a1:
        memory16set(ss, bp - 4, 0x0003);
        pc = 0x27ab;
        break;
    case 0x27a8:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x27ab:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x27b5;
        break;
    case 0x27b2:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x27b5:
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x27bf;
        break;
    case 0x27bc:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x27bf:
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x27c9;
        break;
    case 0x27c6:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x27c9:
        r16[ax] = memory16get(ss, bp - 6);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] -= 0x0002;
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        di += r16[ax];
        if (memory[ds*16 + di + 2748] != 0x10) {
            pc = 0x282c;
            break;
        }
        r16[ax] = memory16get(ss, bp - 6);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        di += r16[ax];
        memory[ds*16 + di + 2748] = 0x10;
        pc = 0x285a;
        break;
    case 0x282c:
        r16[ax] = memory16get(ss, bp - 6);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0188;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        r16[ax] = pop();
        di += r16[ax];
        memory[ds*16 + di + 2748] = 0x00;
    case 0x285a:
        if (memory16get(ss, bp - 6) == 0x0006) {
            pc = 0x2863;
            break;
        }
        pc = 0x27c6;
        break;
    case 0x2863:
        if (memory16get(ss, bp - 8) == 0x0006) {
            pc = 0x286c;
            break;
        }
        pc = 0x27bc;
        break;
    case 0x286c:
        if (memory16get(ss, bp - 2) == 0x0007) {
            pc = 0x2875;
            break;
        }
        pc = 0x27b2;
        break;
    case 0x2875:
        if (memory16get(ss, bp - 4) == 0x0004) {
            pc = 0x287e;
            break;
        }
        pc = 0x27a8;
        break;
    case 0x287e:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_2882() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x2892;
        break;
    case 0x288f:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x2892:
        push(cs);
        cs = 0x0947;
        sub_97f7();
        assert(cs == 0x01ed);
        if (r16s[dx] > signed16(0x0000)) {
            pc = 0x28a3;
            break;
        }
        if (r16s[dx] < signed16(0x0000)) {
            pc = 0x28bb;
            break;
        }
        if (r16[ax] <= 0x0200) {
            pc = 0x28bb;
            break;
        }
    case 0x28a3:
        di = memory16get(ss, bp - 2);
        di <<= 1;
        di <<= 1;
        di += 0x0444;
        push(ds);
        push(di);
        r16[ax] = 0x0200;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9730();
        assert(cs == 0x01ed);
        pc = 0x28c1;
        break;
    case 0x28bb:
        r8[al] = 0x03;
        push(r16[ax]);
        sub_21c4();
    case 0x28c1:
        if (memory16get(ss, bp - 2) != 0x01ff) {
            pc = 0x288f;
            break;
        }
        di = memory16get(ds, 0x0444);
        es = memory16get(ds, 0x0444 + 2);
        r16[ax] = es;
        memory16set(ds, 0x0438, r16[ax]);
        di = memory16get(ds, 0x0444);
        es = memory16get(ds, 0x0444 + 2);
        r16[ax] = di;
        memory16set(ds, 0x043a, r16[ax]);
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_28ec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x0a0e;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r16[ax] = 0;
        memory16set(ds, 0x1315, r16[ax]);
        r16[ax] = 0x0000;
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
    case 0x2921:
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x20) {
            pc = 0x2932;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2934;
        break;
    case 0x2932:
        r8[al] = 0x01;
    case 0x2934:
        r8[bl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] <= 0x7a) {
            pc = 0x2947;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2949;
        break;
    case 0x2947:
        r8[al] = 0x01;
    case 0x2949:
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] >= 0x61) {
            pc = 0x295c;
            break;
        }
        r8[al] = 0x00;
        pc = 0x295e;
        break;
    case 0x295c:
        r8[al] = 0x01;
    case 0x295e:
        r8[al] &= r8[dl];
        r8[cl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] <= 0x5a) {
            pc = 0x2973;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2975;
        break;
    case 0x2973:
        r8[al] = 0x01;
    case 0x2975:
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] >= 0x41) {
            pc = 0x2988;
            break;
        }
        r8[al] = 0x00;
        pc = 0x298a;
        break;
    case 0x2988:
        r8[al] = 0x01;
    case 0x298a:
        r8[al] &= r8[dl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x80;
        if (!r8[al]) {
            pc = 0x29a2;
            break;
        }
        r8[al] = 0x00;
        pc = 0x29a4;
        break;
    case 0x29a2:
        r8[al] = 0x01;
    case 0x29a4:
        r8[al] &= r8[dl];
        r8[al] |= r8[cl];
        r8[al] |= r8[bl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x2e) {
            pc = 0x29bd;
            break;
        }
        r8[al] = 0x00;
        pc = 0x29bf;
        break;
    case 0x29bd:
        r8[al] = 0x01;
    case 0x29bf:
        r8[al] |= r8[dl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x2c) {
            pc = 0x29d4;
            break;
        }
        r8[al] = 0x00;
        pc = 0x29d6;
        break;
    case 0x29d4:
        r8[al] = 0x01;
    case 0x29d6:
        r8[al] |= r8[dl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x21) {
            pc = 0x29eb;
            break;
        }
        r8[al] = 0x00;
        pc = 0x29ed;
        break;
    case 0x29eb:
        r8[al] = 0x01;
    case 0x29ed:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x29f8;
            break;
        }
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
        pc = 0x29fd;
        break;
    case 0x29f8:
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
    case 0x29fd:
        if (memory16get(ss, bp - 6) > 0x0006) {
            pc = 0x2a06;
            break;
        }
        pc = 0x2afa;
        break;
    case 0x2a06:
        r16[ax] = memory16get(ss, bp - 4);
        memory16set(ds, 0x1315, memory16get(ds, 0x1315) + r16[ax]);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) - 0x0006);
    case 0x2a11:
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x20) {
            pc = 0x2a22;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a24;
        break;
    case 0x2a22:
        r8[al] = 0x01;
    case 0x2a24:
        r8[bl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] <= 0x7a) {
            pc = 0x2a37;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a39;
        break;
    case 0x2a37:
        r8[al] = 0x01;
    case 0x2a39:
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] >= 0x61) {
            pc = 0x2a4c;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a4e;
        break;
    case 0x2a4c:
        r8[al] = 0x01;
    case 0x2a4e:
        r8[al] &= r8[dl];
        r8[cl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] <= 0x5a) {
            pc = 0x2a63;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a65;
        break;
    case 0x2a63:
        r8[al] = 0x01;
    case 0x2a65:
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] >= 0x41) {
            pc = 0x2a78;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a7a;
        break;
    case 0x2a78:
        r8[al] = 0x01;
    case 0x2a7a:
        r8[al] &= r8[dl];
        r8[al] |= r8[cl];
        r8[al] |= r8[bl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x2e) {
            pc = 0x2a93;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2a95;
        break;
    case 0x2a93:
        r8[al] = 0x01;
    case 0x2a95:
        r8[al] |= r8[dl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x2c) {
            pc = 0x2aaa;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2aac;
        break;
    case 0x2aaa:
        r8[al] = 0x01;
    case 0x2aac:
        r8[al] |= r8[dl];
        r8[dl] = r8[al];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        if (memory[es*16 + di] == 0x21) {
            pc = 0x2ac1;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2ac3;
        break;
    case 0x2ac1:
        r8[al] = 0x01;
    case 0x2ac3:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x2af5;
            break;
        }
        r16[ax] = 0x0000;
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] -= r16[dx];
        r16[cx] = 0x0003;
        r16[ax] >>= r8[cl];
        r16[ax] &= 0x000c;
        r16[dx] = r16[ax];
        r16[ax] = cs;
        push(r16[ax]);
        di = memory16get(ss, bp - 4);
        es = pop();
        r8[al] = memory[es*16 + di];
        r8[ah] = 0;
        r16[ax] ^= r16[dx];
        memory16set(ds, 0x1315, memory16get(ds, 0x1315) + r16[ax]);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
        pc = 0x2a11;
        break;
    case 0x2af5:
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
    case 0x2afa:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
        r16[ax] = memory16get(ds, 0x1317);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = r16[ax];
        r16[bx] = r16[dx];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0;
        if (r16s[dx] > r16s[bx]) {
            pc = 0x2b1a;
            break;
        }
        if (r16s[dx] >= r16s[bx]) {
            pc = 0x2b13;
            break;
        }
        pc = 0x2921;
        break;
    case 0x2b13:
        if (r16[ax] > r16[cx]) {
            pc = 0x2b1a;
            break;
        }
        pc = 0x2921;
        break;
    case 0x2b1a:
        if (memory16get(ds, 0x1315) != 0x27a2) {
            pc = 0x2b29;
            break;
        }
        memory[ds*16 + 0x1319] = 0x01;
        pc = 0x2b2e;
        break;
    case 0x2b29:
        memory[ds*16 + 0x1319] = 0x00;
    case 0x2b2e:
        sub_21da();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_2b35() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        if (memory16gets(ss, bp + 6) <= signed16(0x000a)) {
            pc = 0x2b45;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2b47;
        break;
    case 0x2b45:
        r8[al] = 0x01;
    case 0x2b47:
        r8[dl] = r8[al];
        if (memory16gets(ss, bp + 8) <= signed16(0x000a)) {
            pc = 0x2b53;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2b55;
        break;
    case 0x2b53:
        r8[al] = 0x01;
    case 0x2b55:
        r8[al] &= r8[dl];
        if (!r8[al]) {
            pc = 0x2b77;
            break;
        }
        r16[ax] = memory16get(ss, bp + 6);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp + 8);
        r16[dx] = 0x000b;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        r8[al] = memory[ds*16 + di + 4732];
        r8[ah] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x2b8d;
        break;
    case 0x2b77:
        r16[ax] = memory16get(ss, bp + 8);
        if (r16s[ax] <= memory16gets(ss, bp + 6)) {
            pc = 0x2b87;
            break;
        }
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x2b8d;
        break;
    case 0x2b87:
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(ss, bp - 2, r16[ax]);
    case 0x2b8d:
        r16[ax] = memory16get(ss, bp - 2);
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_2b96() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        r8[al] = memory[ss*16 + bp + 6];
        if (r8[al] != 0x00) {
            pc = 0x2bde;
            break;
        }
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x2bad;
        break;
    case 0x2baa:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x2bad:
        r16[ax] = memory16get(ss, bp - 8);
        r16[cx] = 0x0014;
        imul16(r16[cx]);
        r16[ax] += 0x0032;
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        r16[ax] += memory16get(ss, di - 9901);
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, r16[dx]);
        if (memory16get(ss, bp - 8) != 0x0004) {
            pc = 0x2baa;
            break;
        }
        pc = 0x2d74;
        break;
    case 0x2bde:
        if (r8[al] != 0x05) {
            pc = 0x2c30;
            break;
        }
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x2bec;
        break;
    case 0x2be9:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x2bec:
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        r16[ax] += memory16get(ss, di - 9901);
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x0028);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        r16[ax] += memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x002d);
        if (memory16get(ss, bp - 8) != 0x0003) {
            pc = 0x2be9;
            break;
        }
        pc = 0x2d74;
        break;
    case 0x2c30:
        if (r8[al] != 0x04) {
            pc = 0x2c50;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x1388);
        pc = 0x2d74;
        break;
    case 0x2c50:
        if (r8[al] != 0x01) {
            pc = 0x2c70;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x0028);
        pc = 0x2d74;
        break;
    case 0x2c70:
        if (r8[al] != 0x02) {
            pc = 0x2cef;
            break;
        }
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x2c7e;
        break;
    case 0x2c7b:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x2c7e:
        memory16set(ss, bp - 4, 0x0100);
        r16[ax] = 0x0350;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, r16[ax]);
        memory16set(ss, bp - 6, 0x0001);
        pc = 0x2c99;
        break;
    case 0x2c96:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x2c99:
        r16[ax] = memory16get(ss, bp - 6);
        r16[cx] = 0x000f;
        imul16(r16[cx]);
        r16[ax] += 0x0028;
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0;
        di = memory16get(ss, bp + 4);
        r16[ax] += memory16get(ss, di - 9901);
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, r16[dx]);
        r16[ax] = memory16get(ss, bp - 2);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + r16[ax]);
        if (memory16get(ss, bp - 6) != 0x0007) {
            pc = 0x2c96;
            break;
        }
        if (memory16get(ss, bp - 8) != 0x0004) {
            pc = 0x2c7b;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x03e8);
        pc = 0x2d74;
        break;
    case 0x2cef:
        if (r8[al] == 0x03) {
            pc = 0x2cf6;
            break;
        }
        pc = 0x2d74;
        break;
    case 0x2cf6:
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x2d00;
        break;
    case 0x2cfd:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x2d00:
        memory16set(ss, bp - 4, 0x0100);
        r16[ax] = 0x0400;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, r16[ax]);
        memory16set(ss, bp - 6, 0x0001);
        pc = 0x2d1b;
        break;
    case 0x2d18:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x2d1b:
        r16[ax] = memory16get(ss, bp - 2);
        r16[cx] = 0x0007;
        r16[ax] >>= r8[cl];
        imul16(memory16get(ss, bp - 6));
        r16[ax] += 0x0028;
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0;
        di = memory16get(ss, bp + 4);
        r16[ax] += memory16get(ss, di - 9901);
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, r16[dx]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += memory16get(ss, bp - 2);
        memory16set(ss, bp - 4, r16[ax]);
        if (memory16get(ss, bp - 6) != 0x0016) {
            pc = 0x2d18;
            break;
        }
        if (memory16get(ss, bp - 8) != 0x0028) {
            pc = 0x2cfd;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10413, 0x03e8);
    case 0x2d74:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 4;
        return;
    } while (1);
}
function sub_2d7a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = 0;
        memory16set(ss, di - 10413, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax]++;
        r8[ah] = 0;
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 9901, r16[ax]);
        di = memory16get(ss, bp + 4);
        if (memory[ss*16 + di - 10462] == 0x00) {
            pc = 0x2de8;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        if (memory16get(ss, di - 10413) == 0x0000) {
            pc = 0x2de3;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        push(memory16get(ss, di - 10413));
        push(cs);
        cs = 0x08e1;
        sub_9121();
        assert(cs == 0x01ed);
        pc = 0x2de8;
        break;
    case 0x2de3:
        push(cs);
        cs = 0x08e1;
        sub_914e();
        assert(cs == 0x01ed);
    case 0x2de8:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_2dee() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0001;
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        sub_23e4();
        memory[ss*16 + bp - 1] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 163];
        di = memory16get(ss, bp + 4);
        if (r8s[al] <= memorys[ss*16 + di - 2]) {
            pc = 0x2e26;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 163];
        di = memory16get(ss, bp + 4);
        memory[ss*16 + di - 2] = r8[al];
    case 0x2e26:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_2e2c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        memory[ss*16 + bp - 2] = 0x00;
        memory16set(ss, bp + 10, memory16get(ss, bp + 10) - 0x0003);
        memory16set(ss, bp + 8, memory16get(ss, bp + 8) - 0x0003);
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x2e48;
        break;
    case 0x2e45:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x2e48:
        r16[ax] = 0;
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x2e52;
        break;
    case 0x2e4f:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x2e52:
        r16[ax] = memory16get(ss, bp - 6);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0007;
        mul16(r16[dx]);
        r16[cx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[dx] = 0x0031;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        di += r16[bx];
        if (memory[ds*16 + di + 3140] == 0x10) {
            pc = 0x2e8a;
            break;
        }
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        push(bp);
        sub_2dee();
    case 0x2e8a:
        if (memory16get(ss, bp - 4) != 0x0006) {
            pc = 0x2e4f;
            break;
        }
        if (memory16get(ss, bp - 6) != 0x0006) {
            pc = 0x2e45;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        memory[ss*16 + bp - 1] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 8;
        return;
    } while (1);
}
function sub_2ea5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        memory16set(ss, bp - 2, 0x0001);
    case 0x2eb0:
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0147;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[dl] = memory[ss*16 + di - 10139];
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 4);
        if (r16s[ax] <= memory16gets(ss, di - 2)) {
            pc = 0x2ed2;
            break;
        }
        r8[al] = 0x00;
        pc = 0x2ed4;
        break;
    case 0x2ed2:
        r8[al] = 0x01;
    case 0x2ed4:
        r8[al] &= r8[dl];
        if (!r8[al]) {
            pc = 0x2edf;
            break;
        }
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
        pc = 0x2eb0;
        break;
    case 0x2edf:
        r16[ax] = memory16get(ss, bp - 2);
        di = memory16get(ss, bp + 4);
        if (r16s[ax] < memory16gets(ss, di - 2)) {
            pc = 0x2efc;
            break;
        }
        di = memory16get(ss, bp + 4);
        if (memory16gets(ss, di - 2) >= signed16(0x001e)) {
            pc = 0x2efc;
            break;
        }
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 2, memory16get(ss, di - 2) + 1);
    case 0x2efc:
        if (memory16gets(ss, bp - 2) <= signed16(0x001e)) {
            pc = 0x2f05;
            break;
        }
        pc = 0x2fe6;
        break;
    case 0x2f05:
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0147;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += 0xd865;
        memory16set(ss, bp - 8, di);
        memory16set(ss, bp - 6, ss);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory[es*16 + di] = 0x01;
        r16[ax] = memory16get(ss, bp + 6);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, di + 1, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, di + 3, r16[ax]);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[ax] = 0;
        memory16set(es, di + 5, r16[ax]);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[ax] = memory16get(es, di + 1);
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = 0x0001;
        if (r16s[ax] <= memory16gets(ss, bp - 10)) {
            pc = 0x2f55;
            break;
        }
        pc = 0x2fe6;
        break;
    case 0x2f55:
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x2f5d;
        break;
    case 0x2f5a:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x2f5d:
        r16[ax] = memory16get(ss, bp + 12);
        r16[cx] = 0x0005;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        di += r16[ax];
        memory16set(es, di + 5, r16[dx]);
        r16[ax] = memory16get(ss, bp + 10);
        r16[cx] = 0x0005;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        di += r16[ax];
        memory16set(es, di + 85, r16[dx]);
        r16[ax] = 0x0020;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        push(r16[ax]);
        r16[ax] = 0x0020;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[dx] = pop();
        r16[ax] -= r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        di += r16[ax];
        memory16set(es, di + 165, r16[dx]);
        r16[ax] = 0x0020;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        push(r16[ax]);
        r16[ax] = 0x0020;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[dx] = pop();
        r16[ax] -= r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        di += r16[ax];
        memory16set(es, di + 245, r16[dx]);
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] == memory16get(ss, bp - 10)) {
            pc = 0x2fe6;
            break;
        }
        pc = 0x2f5a;
        break;
    case 0x2fe6:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 10;
        return;
    } while (1);
}
function sub_2fec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 4);
        if (memory16gets(ss, di - 10459) < signed16(0x0000)) {
            pc = 0x2ffd;
            break;
        }
        pc = 0x30a5;
        break;
    case 0x2ffd:
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        push(memory16get(ss, di - 9826));
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        push(memory16get(ss, di - 9822));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10445);
        r16[ax] += 0x0002;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[al] = memory[ss*16 + di - 9818];
        push(r16[ax]);
        sub_24c9();
        r8[al] = 0x03;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b96();
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        r16[ax] = 0x0018;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        r16[ax] = 0x0014;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        r16[ax] = 0x000c;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 10459, 0x0019);
        di = memory16get(ss, bp + 10);
        memory[ds*16 + di + 4729] = 0x00;
    case 0x30a5:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 8;
        return;
    } while (1);
}
function sub_30ab() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] >>= 1;
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] &= 0x0001;
        if (r16[ax] != 0x0001) {
            pc = 0x312b;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0xf0;
        r8[ah] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        if (memory16get(ss, bp - 2) == 0x0080) {
            pc = 0x30e9;
            break;
        }
        r8[al] = 0x00;
        pc = 0x30eb;
        break;
    case 0x30e9:
        r8[al] = 0x01;
    case 0x30eb:
        r8[dl] = r8[al];
        if (memory16get(ss, bp - 2) == 0x0060) {
            pc = 0x30f7;
            break;
        }
        r8[al] = 0x00;
        pc = 0x30f9;
        break;
    case 0x30f7:
        r8[al] = 0x01;
    case 0x30f9:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x3129;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x0f;
        r8[dl] = r8[al];
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = r8[dl];
    case 0x3129:
        pc = 0x318f;
        break;
    case 0x312b:
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x0f;
        r8[ah] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        if (memory16get(ss, bp - 2) == 0x0008) {
            pc = 0x314f;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3151;
        break;
    case 0x314f:
        r8[al] = 0x01;
    case 0x3151:
        r8[dl] = r8[al];
        if (memory16get(ss, bp - 2) == 0x0006) {
            pc = 0x315d;
            break;
        }
        r8[al] = 0x00;
        pc = 0x315f;
        break;
    case 0x315d:
        r8[al] = 0x01;
    case 0x315f:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x318f;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        r8[al] = memory[es*16 + di];
        r8[al] &= 0xf0;
        r8[dl] = r8[al];
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 6);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = r8[dl];
    case 0x318f:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_3195() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0001) {
            pc = 0x31a9;
            break;
        }
        pc = 0x3266;
        break;
    case 0x31a9:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0002;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0002;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x31ea;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x31cf;
        break;
    case 0x31cc:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x31cf:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0003;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x31cc;
            break;
        }
    case 0x31ea:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0003;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0003;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x322b;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3210;
        break;
    case 0x320d:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3210:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0002;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x320d;
            break;
        }
    case 0x322b:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]++;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]--;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x3266;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x324d;
        break;
    case 0x324a:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x324d:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]--;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x324a;
            break;
        }
    case 0x3266:
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] &= 0x0004;
        if (r16[ax] == 0x0004) {
            pc = 0x3274;
            break;
        }
        pc = 0x3331;
        break;
    case 0x3274:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0002;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0002;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x32b5;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x329a;
        break;
    case 0x3297:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x329a:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0003;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x3297;
            break;
        }
    case 0x32b5:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0003;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0003;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x32f6;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x32db;
        break;
    case 0x32d8:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x32db:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0002;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x32d8;
            break;
        }
    case 0x32f6:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]++;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]--;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x3331;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3318;
        break;
    case 0x3315:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3318:
        push(memory16get(ss, bp - 2));
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]++;
        push(r16[ax]);
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x3315;
            break;
        }
    case 0x3331:
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] &= 0x0002;
        if (r16[ax] == 0x0002) {
            pc = 0x333f;
            break;
        }
        pc = 0x33fc;
        break;
    case 0x333f:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0002;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0002;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x3380;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3365;
        break;
    case 0x3362:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3365:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0003;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x3362;
            break;
        }
    case 0x3380:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0003;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0003;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x33c1;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x33a6;
        break;
    case 0x33a3:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x33a6:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] += 0x0002;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x33a3;
            break;
        }
    case 0x33c1:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]++;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]--;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x33fc;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x33e3;
        break;
    case 0x33e0:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x33e3:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]++;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x33e0;
            break;
        }
    case 0x33fc:
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] &= 0x0008;
        if (r16[ax] == 0x0008) {
            pc = 0x340a;
            break;
        }
        pc = 0x34c7;
        break;
    case 0x340a:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0002;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0002;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x344b;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3430;
        break;
    case 0x342d:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3430:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0003;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x342d;
            break;
        }
    case 0x344b:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] += 0x0003;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax] -= 0x0003;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x348c;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3471;
        break;
    case 0x346e:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3471:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax] -= 0x0002;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x346e;
            break;
        }
    case 0x348c:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]++;
        memory16set(ss, bp - 4, r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10449);
        r16[ax]--;
        if (r16s[ax] > memory16gets(ss, bp - 4)) {
            pc = 0x34c7;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x34ae;
        break;
    case 0x34ab:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x34ae:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10451);
        r16[ax]--;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        push(bp);
        sub_30ab();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 4)) {
            pc = 0x34ab;
            break;
        }
    case 0x34c7:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 8;
        return;
    } while (1);
}
function sub_34cd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x34dd;
        break;
    case 0x34da:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x34dd:
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x34e7;
        break;
    case 0x34e4:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x34e7:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        if (memory16get(ss, di - 9901) != 0xffff) {
            pc = 0x3508;
            break;
        }
        pc = 0x35d2;
        break;
    case 0x3508:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        push(memory16get(ss, di - 9901));
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        push(memory16get(ss, di - 9877));
        r8[al] = 0x00;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[bx] = memory16get(ds, di + 107);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax] -= r16[bx];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[bx] = memory16get(ds, di + 123);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9877);
        r16[ax] -= r16[bx];
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_235c();
    case 0x35d2:
        if (memory16get(ss, bp - 2) == 0x0006) {
            pc = 0x35db;
            break;
        }
        pc = 0x34e4;
        break;
    case 0x35db:
        if (memory16get(ss, bp - 4) == 0x0002) {
            pc = 0x35e4;
            break;
        }
        pc = 0x34da;
        break;
    case 0x35e4:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_35ea() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        if (memory16gets(ss, di - 10421) <= signed16(0x0000)) {
            pc = 0x3618;
            break;
        }
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10421, memory16get(ss, di - 10421) - 1);
        pc = 0x372e;
        break;
    case 0x3618:
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        memory16set(ds, di + 4712, memory16get(ds, di + 4712) + 1);
        memory16set(ss, bp - 2, 0x0001);
    case 0x362a:
        if (memory16gets(ss, bp - 2) <= signed16(0x0006)) {
            pc = 0x3634;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3636;
        break;
    case 0x3634:
        r8[al] = 0x01;
    case 0x3636:
        r8[bl] = r8[al];
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        if (memory16get(ss, di - 9901) != 0xffff) {
            pc = 0x365c;
            break;
        }
        r8[al] = 0x00;
        pc = 0x365e;
        break;
    case 0x365c:
        r8[al] = 0x01;
    case 0x365e:
        r8[al] &= r8[bl];
        if (!r8[al]) {
            pc = 0x3669;
            break;
        }
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
        pc = 0x362a;
        break;
    case 0x3669:
        if (memory16gets(ss, bp - 2) <= signed16(0x0006)) {
            pc = 0x3672;
            break;
        }
        pc = 0x371b;
        break;
    case 0x3672:
        r8[al] = 0x04;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b96();
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[bx] = memory16get(ss, di - 9826);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        memory16set(ss, di - 9901, r16[bx]);
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[bx] = memory16get(ss, di - 9822);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        memory16set(ss, di - 9877, r16[bx]);
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[cl] = memory[ss*16 + di - 9818];
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        memory[ss*16 + di - 9906] = r8[cl];
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10455);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10429, memory16get(ss, di - 10429) - 0x003c);
    case 0x371b:
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10421, 0x0001);
    case 0x372e:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 4;
        return;
    } while (1);
}
function sub_3734() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x3744;
        break;
    case 0x3741:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x3744:
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x374e;
        break;
    case 0x374b:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x374e:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        if (memory16get(ss, di - 9901) != 0xffff) {
            pc = 0x376f;
            break;
        }
        pc = 0x3839;
        break;
    case 0x376f:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        push(memory16get(ss, di - 9901));
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        push(memory16get(ss, di - 9877));
        r8[al] = 0x0c;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[bx] = memory16get(ds, di + 107);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9901);
        r16[ax] -= r16[bx];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[bx] = memory16get(ds, di + 123);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9877);
        r16[ax] -= r16[bx];
        push(r16[ax]);
        r8[al] = 0x04;
        push(r16[ax]);
        sub_235c();
    case 0x3839:
        if (memory16get(ss, bp - 2) == 0x0006) {
            pc = 0x3842;
            break;
        }
        pc = 0x374b;
        break;
    case 0x3842:
        if (memory16get(ss, bp - 4) == 0x0002) {
            pc = 0x384b;
            break;
        }
        pc = 0x3741;
        break;
    case 0x384b:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_3851() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000f;
        memory16set(ss, bp - 6, 0x0001);
        pc = 0x3861;
        break;
    case 0x385e:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x3861:
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x386b;
        break;
    case 0x3868:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x386b:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        if (memory16get(ss, di - 9901) != 0xffff) {
            pc = 0x388c;
            break;
        }
        pc = 0x3b00;
        break;
    case 0x388c:
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[ax] = memory16get(ds, di + 107);
        memory16set(ss, bp - 14, r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += si;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[dx];
        r8[al] = memory[ss*16 + di - 9906];
        r8[ah] = 0;
        di = r16[ax];
        di <<= 1;
        r16[ax] = memory16get(ds, di + 123);
        memory16set(ss, bp - 12, r16[ax]);
        memory16set(ss, bp - 2, 0x0001);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9901);
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        r16[ax] = memory16get(ss, di - 9877);
        memory16set(ss, bp - 8, r16[ax]);
    case 0x391f:
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] += memory16get(ss, bp - 14);
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += memory16get(ss, bp - 12);
        memory16set(ss, bp - 8, r16[ax]);
        push(memory16get(ss, bp - 10));
        push(memory16get(ss, bp - 8));
        sub_23e4();
        memory[ss*16 + bp - 15] = r8[al];
        if (memory[ss*16 + bp - 15] != 0x0c) {
            pc = 0x3947;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3949;
        break;
    case 0x3947:
        r8[al] = 0x01;
    case 0x3949:
        r8[dl] = r8[al];
        if (memory[ss*16 + bp - 15] != 0x00) {
            pc = 0x3955;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3957;
        break;
    case 0x3955:
        r8[al] = 0x01;
    case 0x3957:
        r8[al] &= r8[dl];
        if (r8[al]) {
            pc = 0x3960;
            break;
        }
        pc = 0x3a9e;
        break;
    case 0x3960:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9826);
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x397a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x397a:
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9822);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x3995;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3995:
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b35();
        if (r16s[ax] > signed16(0x0003)) {
            pc = 0x39a4;
            break;
        }
        pc = 0x3a9e;
        break;
    case 0x39a4:
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9826);
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x39c1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x39c1:
        push(r16[ax]);
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9822);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x39df;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x39df:
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b35();
        if (r16s[ax] < signed16(0x0004)) {
            pc = 0x39ee;
            break;
        }
        pc = 0x3a74;
        break;
    case 0x39ee:
        di = memory16get(ss, bp - 6);
        di <<= 1;
        memory16set(ds, di + 4716, memory16get(ds, di + 4716) + 1);
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10437, memory16get(ss, di - 10437) - 0x0700);
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 10457, 0x0002);
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        if (memory16gets(ss, di - 10437) <= signed16(0x0000)) {
            pc = 0x3a51;
            break;
        }
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] -= memory16get(ss, bp - 14);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] -= memory16get(ss, bp - 12);
        push(r16[ax]);
        r16[ax] = 0x0007;
        push(r16[ax]);
        r16[ax] = 0x0014;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        r8[al] = 0x02;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b96();
        pc = 0x3a72;
        break;
    case 0x3a51:
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 6);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] += memory16get(ss, bp - 14);
        r16[ax] += memory16get(ss, bp - 14);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += memory16get(ss, bp - 14);
        r16[ax] += memory16get(ss, bp - 14);
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2fec();
    case 0x3a72:
        pc = 0x3a99;
        break;
    case 0x3a74:
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] -= memory16get(ss, bp - 14);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] -= memory16get(ss, bp - 12);
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        r16[ax] = 0x0007;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2ea5();
        r8[al] = 0x00;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b96();
    case 0x3a99:
        memory16set(ss, bp - 10, 0xffff);
    case 0x3a9e:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
        if (memory16get(ss, bp - 10) == 0xffff) {
            pc = 0x3aab;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3aad;
        break;
    case 0x3aab:
        r8[al] = 0x01;
    case 0x3aad:
        r8[dl] = r8[al];
        if (memory16gets(ss, bp - 2) > signed16(0x0004)) {
            pc = 0x3ab9;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3abb;
        break;
    case 0x3ab9:
        r8[al] = 0x01;
    case 0x3abb:
        r8[al] |= r8[dl];
        if (r8[al]) {
            pc = 0x3ac4;
            break;
        }
        pc = 0x391f;
        break;
    case 0x3ac4:
        r16[bx] = memory16get(ss, bp - 10);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        memory16set(ss, di - 9901, r16[bx]);
        r16[bx] = memory16get(ss, bp - 8);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        memory16set(ss, di - 9877, r16[bx]);
    case 0x3b00:
        if (memory16get(ss, bp - 4) == 0x0006) {
            pc = 0x3b09;
            break;
        }
        pc = 0x3868;
        break;
    case 0x3b09:
        if (memory16get(ss, bp - 6) == 0x0002) {
            pc = 0x3b12;
            break;
        }
        pc = 0x385e;
        break;
    case 0x3b12:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_3b18() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        if (memory16get(ds, 0x1332) == 0x0009) {
            pc = 0x3b29;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3b2b;
        break;
    case 0x3b29:
        r8[al] = 0x01;
    case 0x3b2b:
        r8[dl] = r8[al];
        if (memory16get(ds, 0x1332) == 0x0002) {
            pc = 0x3b38;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3b3a;
        break;
    case 0x3b38:
        r8[al] = 0x01;
    case 0x3b3a:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x3b47;
            break;
        }
        memory16set(ss, bp - 2, 0x000d);
        pc = 0x3b4c;
        break;
    case 0x3b47:
        memory16set(ss, bp - 2, 0x0008);
    case 0x3b4c:
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x0063;
        push(r16[ax]);
        r8[al] = 0xb0;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0026;
        push(r16[ax]);
        r16[ax] = 0x0048;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0x0029;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x004e;
        push(r16[ax]);
        r16[ax] = 0x0048;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0;
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = 0;
        memory16set(ss, bp - 10, r16[ax]);
        pc = 0x3bad;
        break;
    case 0x3baa:
        memory16set(ss, bp - 10, memory16get(ss, bp - 10) + 1);
    case 0x3bad:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0003;
        push(r16[ax]);
        r16[ax] = 0x004a;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0024;
        push(r16[ax]);
        r16[ax] = 0x0062;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0003;
        push(r16[ax]);
        r16[ax] = 0x004a;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0024;
        push(r16[ax]);
        r16[ax] = 0x004a;
        push(r16[ax]);
        r8[al] = 0xb0;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0003;
        push(r16[ax]);
        r16[ax] = 0x0062;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0024;
        push(r16[ax]);
        r16[ax] = 0x0062;
        push(r16[ax]);
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_2212();
        memory16set(ss, bp - 8, 0x004b);
        pc = 0x3c21;
        break;
    case 0x3c1e:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x3c21:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0003;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb0;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0007;
        push(r16[ax]);
        sub_229e();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0024;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_229e();
        if (memory16get(ss, bp - 8) != 0x0061) {
            pc = 0x3c1e;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000c;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0020;
        push(r16[ax]);
        r16[ax] = 0x0052;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000c;
        push(r16[ax]);
        r16[ax] = 0x005a;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0020;
        push(r16[ax]);
        r16[ax] = 0x005d;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        r16[ax] = 0x004d;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        r16[ax] = 0x004d;
        push(r16[ax]);
        r8[al] = 0xb0;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        r16[ax] = 0x0058;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        r16[ax] = 0x0058;
        push(r16[ax]);
        r8[al] = 0xb0;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        r16[ax] = 0x0054;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        r16[ax] = 0x0054;
        push(r16[ax]);
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_2212();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        r16[ax] = 0x005f;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        r16[ax] = 0x005f;
        push(r16[ax]);
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_2212();
        memory16set(ss, bp - 8, 0x004e);
        pc = 0x3d31;
        break;
    case 0x3d2e:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x3d31:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb0;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0007;
        push(r16[ax]);
        sub_229e();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_229e();
        if (memory16get(ss, bp - 8) != 0x0053) {
            pc = 0x3d2e;
            break;
        }
        memory16set(ss, bp - 8, 0x0059);
        pc = 0x3d71;
        break;
    case 0x3d6e:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x3d71:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0009;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb0;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0007;
        push(r16[ax]);
        sub_229e();
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0022;
        push(r16[ax]);
        push(memory16get(ss, bp - 8));
        r8[al] = 0xb1;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        sub_229e();
        if (memory16get(ss, bp - 8) != 0x005e) {
            pc = 0x3d6e;
            break;
        }
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x3db1;
        break;
    case 0x3dae:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x3db1:
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x3dbb;
        break;
    case 0x3db8:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x3dbb:
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += 0x000a;
        r16[ax] += memory16get(ss, bp - 4);
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x004f;
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += 0x000a;
        r16[ax] += memory16get(ss, bp - 4);
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x005a;
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        r8[al] = 0x0b;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 8) != 0x0005) {
            pc = 0x3db8;
            break;
        }
        if (memory16get(ss, bp - 6) != 0x0002) {
            pc = 0x3dae;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000a;
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000a;
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r8[al] = 0x5b;
        push(r16[ax]);
        r8[al] = 0x0b;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000a;
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r8[al] = 0x52;
        push(r16[ax]);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x000f;
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        r8[al] = 0x5d;
        push(r16[ax]);
        r8[al] = 0x0b;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 0x0028);
        if (memory16get(ss, bp - 10) == 0x0001) {
            pc = 0x3e66;
            break;
        }
        pc = 0x3baa;
        break;
    case 0x3e66:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_3e6c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000e;
        di = memory16get(ss, bp + 4);
        if (memory16gets(ss, di - 2) > signed16(0x0000)) {
            pc = 0x3e7f;
            break;
        }
        pc = 0x40be;
        break;
    case 0x3e7f:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 2);
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = 0x0001;
        if (r16s[ax] <= memory16gets(ss, bp - 8)) {
            pc = 0x3e94;
            break;
        }
        pc = 0x40be;
        break;
    case 0x3e94:
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x3e9c;
        break;
    case 0x3e99:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x3e9c:
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0147;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += 0xd865;
        memory16set(ss, bp - 12, di);
        memory16set(ss, bp - 10, ss);
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        if (memory[es*16 + di] != 0x00) {
            pc = 0x3ebf;
            break;
        }
        pc = 0x40b3;
        break;
    case 0x3ebf:
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, di + 1);
        memory16set(ss, bp - 14, r16[ax]);
        r16[ax] = 0x0001;
        if (r16s[ax] > memory16gets(ss, bp - 14)) {
            pc = 0x3f20;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3ed9;
        break;
    case 0x3ed6:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3ed9:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        if (memory16get(es, di + 5) == 0xffff) {
            pc = 0x3f18;
            break;
        }
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 5);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 85);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_235c();
    case 0x3f18:
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 14)) {
            pc = 0x3ed6;
            break;
        }
    case 0x3f20:
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, di + 5);
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        if (r16[ax] != memory16get(es, di + 3)) {
            pc = 0x3f86;
            break;
        }
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        memory[es*16 + di] = 0x00;
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 4);
        if (r16[ax] != memory16get(ss, di - 2)) {
            pc = 0x3f83;
            break;
        }
    case 0x3f43:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 2);
        r16[dx] = 0x0147;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        if (memory[ss*16 + di - 10139] == 0x00) {
            pc = 0x3f60;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3f62;
        break;
    case 0x3f60:
        r8[al] = 0x01;
    case 0x3f62:
        r8[dl] = r8[al];
        di = memory16get(ss, bp + 4);
        if (memory16gets(ss, di - 2) > signed16(0x0000)) {
            pc = 0x3f72;
            break;
        }
        r8[al] = 0x00;
        pc = 0x3f74;
        break;
    case 0x3f72:
        r8[al] = 0x01;
    case 0x3f74:
        r8[al] &= r8[dl];
        if (!r8[al]) {
            pc = 0x3f83;
            break;
        }
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 2, memory16get(ss, di - 2) - 1);
        pc = 0x3f43;
        break;
    case 0x3f83:
        pc = 0x40b3;
        break;
    case 0x3f86:
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        memory16set(es, di + 5, memory16get(es, di + 5) + 1);
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, di + 1);
        memory16set(ss, bp - 14, r16[ax]);
        r16[ax] = 0x0001;
        if (r16s[ax] <= memory16gets(ss, bp - 14)) {
            pc = 0x3fa2;
            break;
        }
        pc = 0x40b3;
        break;
    case 0x3fa2:
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x3faa;
        break;
    case 0x3fa7:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x3faa:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        if (memory16get(es, di + 5) != 0xffff) {
            pc = 0x3fbe;
            break;
        }
        pc = 0x40a8;
        break;
    case 0x3fbe:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[dx] = memory16get(es, di + 165);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        memory16set(es, di + 5, memory16get(es, di + 5) + r16[dx]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[dx] = memory16get(es, di + 245);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        memory16set(es, di + 85, memory16get(es, di + 85) + r16[dx]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 5);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 85);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        sub_23e4();
        r8[ah] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16get(ss, bp - 6) == 0x000c) {
            pc = 0x4032;
            break;
        }
        r8[al] = 0x00;
        pc = 0x4034;
        break;
    case 0x4032:
        r8[al] = 0x01;
    case 0x4034:
        r8[bl] = r8[al];
        if (memory16get(ss, bp - 6) == 0x0008) {
            pc = 0x4040;
            break;
        }
        r8[al] = 0x00;
        pc = 0x4042;
        break;
    case 0x4040:
        r8[al] = 0x01;
    case 0x4042:
        r8[cl] = r8[al];
        if (memory16get(ss, bp - 6) == 0x0006) {
            pc = 0x404e;
            break;
        }
        r8[al] = 0x00;
        pc = 0x4050;
        break;
    case 0x404e:
        r8[al] = 0x01;
    case 0x4050:
        r8[dl] = r8[al];
        if (memory16get(ss, bp - 6) == 0x0000) {
            pc = 0x405c;
            break;
        }
        r8[al] = 0x00;
        pc = 0x405e;
        break;
    case 0x405c:
        r8[al] = 0x01;
    case 0x405e:
        r8[al] |= r8[dl];
        r8[al] |= r8[cl];
        r8[al] |= r8[bl];
        if (!r8[al]) {
            pc = 0x4098;
            break;
        }
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 5);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        r16[ax] = memory16get(es, di + 85);
        r16[cx] = 0x0005;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r8[al] = 0x0c;
        push(r16[ax]);
        sub_235c();
        pc = 0x40a8;
        break;
    case 0x4098:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        di += r16[ax];
        memory16set(es, di + 5, 0xffff);
    case 0x40a8:
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] == memory16get(ss, bp - 14)) {
            pc = 0x40b3;
            break;
        }
        pc = 0x3fa7;
        break;
    case 0x40b3:
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] == memory16get(ss, bp - 8)) {
            pc = 0x40be;
            break;
        }
        pc = 0x3e99;
        break;
    case 0x40be:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_40c4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000f;
        if (memory16get(ss, bp + 8) != 0x0001) {
            pc = 0x40d7;
            break;
        }
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x40dc;
        break;
    case 0x40d7:
        memory16set(ss, bp - 8, 0x0050);
    case 0x40dc:
        if (memory16get(ss, bp + 6) != 0x0001) {
            pc = 0x4133;
            break;
        }
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[al] = memory[ss*16 + di - 10428];
        r8[ah] = 0;
        memory16set(ss, bp - 12, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[al] = memory[ss*16 + di - 10424];
        r8[ah] = 0;
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 10429);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10425, r16[dx]);
        memory16set(ss, bp - 6, 0x004f);
        memory[ss*16 + bp - 13] = 0x0e;
        pc = 0x4182;
        break;
    case 0x4133:
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[al] = memory[ss*16 + di - 10436];
        r8[ah] = 0;
        memory16set(ss, bp - 12, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r8[al] = memory[ss*16 + di - 10432];
        r8[ah] = 0;
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 10437);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10433, r16[dx]);
        memory16set(ss, bp - 6, 0x005a);
        memory[ss*16 + bp - 13] = 0x0b;
    case 0x4182:
        if (memory16gets(ss, bp - 10) >= signed16(0x0001)) {
            pc = 0x418d;
            break;
        }
        memory16set(ss, bp - 10, 0x0001);
    case 0x418d:
        r16[ax] = memory16get(ss, bp - 12);
        if (r16s[ax] <= memory16gets(ss, bp - 10)) {
            pc = 0x41df;
            break;
        }
        r16[ax] = memory16get(ss, bp - 12);
        memory16set(ss, bp - 15, r16[ax]);
        r16[ax] = memory16get(ss, bp - 10);
        if (r16s[ax] > memory16gets(ss, bp - 15)) {
            pc = 0x41dd;
            break;
        }
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x41ab;
        break;
    case 0x41a8:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x41ab:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x41b5;
        break;
    case 0x41b2:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x41b5:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0015;
        r16[ax] += memory16get(ss, bp - 8);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 13];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0003) {
            pc = 0x41b2;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 15)) {
            pc = 0x41a8;
            break;
        }
    case 0x41dd:
        pc = 0x4227;
        break;
    case 0x41df:
        r16[ax] = memory16get(ss, bp - 10);
        memory16set(ss, bp - 15, r16[ax]);
        r16[ax] = memory16get(ss, bp - 12);
        r16[ax]++;
        if (r16s[ax] > memory16gets(ss, bp - 15)) {
            pc = 0x4227;
            break;
        }
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x41f6;
        break;
    case 0x41f3:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x41f6:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x4200;
        break;
    case 0x41fd:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x4200:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0015;
        r16[ax] += memory16get(ss, bp - 8);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0003) {
            pc = 0x41fd;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 15)) {
            pc = 0x41f3;
            break;
        }
    case 0x4227:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function sub_422d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 10457, memory16get(ss, di - 10457) + 1);
        di = memory16get(ss, bp + 4);
        if (memory16gets(ss, di - 10457) <= signed16(0x0002)) {
            pc = 0x424d;
            break;
        }
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 10457, 0x0001);
    case 0x424d:
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 10457);
        if (r16[ax] != 0x0001) {
            pc = 0x427c;
            break;
        }
        di = memory16get(ss, bp + 4);
        r8[al] = memory[ss*16 + di - 10426];
        di = memory16get(ss, bp + 4);
        if (r8[al] == memory[ss*16 + di - 10422]) {
            pc = 0x427a;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_40c4();
    case 0x427a:
        pc = 0x42a1;
        break;
    case 0x427c:
        if (r16[ax] != 0x0002) {
            pc = 0x42a1;
            break;
        }
        di = memory16get(ss, bp + 4);
        r8[al] = memory[ss*16 + di - 10424];
        di = memory16get(ss, bp + 4);
        if (r8[al] == memory[ss*16 + di - 10420]) {
            pc = 0x42a1;
            break;
        }
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_40c4();
    case 0x42a1:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_42a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        memory16set(ds, 0x1264, 0x0001);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x42bd;
        break;
    case 0x42ba:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x42bd:
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 4712, r16[ax]);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 4716, r16[ax]);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 4720, r16[ax]);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 4724, r16[ax]);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 4708, r16[ax]);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x42ba;
            break;
        }
    case 0x42fa:
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x4304;
        break;
    case 0x4301:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x4304:
        r16[ax] = 0x02c0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x00a0;
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 9841, r16[dx]);
        r16[ax] = 0x00c0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x00a0;
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 9837, r16[dx]);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x4301;
            break;
        }
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9839);
        di = memory16get(ss, bp + 4);
        r16[ax] -= memory16get(ss, di - 9837);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x435a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x435a:
        push(r16[ax]);
        di = memory16get(ss, bp + 4);
        r16[ax] = memory16get(ss, di - 9835);
        di = memory16get(ss, bp + 4);
        r16[ax] -= memory16get(ss, di - 9833);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x4371;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4371:
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        sub_2b35();
        if (r16s[ax] > signed16(0x0064)) {
            pc = 0x4380;
            break;
        }
        pc = 0x42fa;
        break;
    case 0x4380:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_4386() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        di = memory16get(ss, bp + 4);
        r16[ax] = 0;
        memory16set(ss, di - 2, r16[ax]);
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x439f;
        break;
    case 0x439c:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x439f:
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x0147;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory[ss*16 + di - 10139] = 0x00;
        if (memory16get(ss, bp - 4) != 0x001e) {
            pc = 0x439c;
            break;
        }
        di = memory16get(ss, bp + 4);
        di += 0xd753;
        push(ss);
        push(di);
        r16[ax] = 0x0200;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x01ed);
        di = memory16get(ss, bp + 4);
        r16[ax] = 0;
        memory16set(ss, di - 9901, r16[ax]);
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 9816, 0x0002);
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 9814, 0x0006);
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x43f5;
        break;
    case 0x43f2:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x43f5:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9841);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 9826, r16[dx]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[dx] = memory16get(ss, di - 9837);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 9822, r16[dx]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 9833, 0xffff);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = 0;
        memory16set(ss, di - 10441, r16[ax]);
        di = memory16get(ss, bp - 4);
        memory[ds*16 + di + 4729] = 0x01;
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = 0;
        memory16set(ss, di - 10421, r16[ax]);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x4476;
        break;
    case 0x4473:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x4476:
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = 0x000c;
        mul16(r16[dx]);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        di += r16[cx];
        memory16set(ss, di - 9901, 0xffff);
        if (memory16get(ss, bp - 2) != 0x0006) {
            pc = 0x4473;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory[ss*16 + di - 9827] = 0x00;
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10429, 0x2c88);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = 0;
        memory16set(ss, di - 10425, r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        memory16set(ss, di - 10437, 0x2c88);
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = 0;
        memory16set(ss, di - 10433, r16[ax]);
        if (memory16get(ss, bp - 4) == 0x0002) {
            pc = 0x44f4;
            break;
        }
        pc = 0x43f2;
        break;
    case 0x44f4:
        di = memory16get(ss, bp + 4);
        memory16set(ss, di - 10459, 0xffff);
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_4504() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        memory16set(ss, bp - 6, 0x0001);
        pc = 0x4514;
        break;
    case 0x4511:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x4514:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] += 0x0010;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] -= 0x0010;
        if (r16s[ax] > memory16gets(ss, bp - 8)) {
            pc = 0x4598;
            break;
        }
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x4548;
        break;
    case 0x4545:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x4548:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0010;
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] -= 0x0010;
        if (r16s[ax] > memory16gets(ss, bp - 10)) {
            pc = 0x4590;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x457c;
        break;
    case 0x4579:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x457c:
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 2));
        r8[al] = 0x00;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 10)) {
            pc = 0x4579;
            break;
        }
    case 0x4590:
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 8)) {
            pc = 0x4545;
            break;
        }
    case 0x4598:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] -= 0x0004;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] -= 0x0011;
        if (r16s[ax] > memory16gets(ss, bp - 8)) {
            pc = 0x4614;
            break;
        }
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x45cc;
        break;
    case 0x45c9:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x45cc:
        push(memory16get(ss, bp - 4));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] -= 0x0011;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        push(memory16get(ss, bp - 4));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0011;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 8)) {
            pc = 0x45c9;
            break;
        }
    case 0x4614:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] += 0x0004;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] += 0x0011;
        if (r16s[ax] < memory16gets(ss, bp - 8)) {
            pc = 0x4690;
            break;
        }
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x4648;
        break;
    case 0x4645:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) - 1);
    case 0x4648:
        push(memory16get(ss, bp - 4));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] -= 0x0011;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        push(memory16get(ss, bp - 4));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0011;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 8)) {
            pc = 0x4645;
            break;
        }
    case 0x4690:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0010;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] -= 0x0010;
        if (r16s[ax] > memory16gets(ss, bp - 8)) {
            pc = 0x470c;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x46c4;
        break;
    case 0x46c1:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x46c4:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] -= 0x0011;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] += 0x0011;
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0008;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 8)) {
            pc = 0x46c1;
            break;
        }
    case 0x470c:
        if (memory16get(ss, bp - 6) == 0x0002) {
            pc = 0x4715;
            break;
        }
        pc = 0x4511;
        break;
    case 0x4715:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_4732() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        r8[al] = 0x05;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x22;
        push(r16[ax]);
        r8[al] = 0x08;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xda;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x477e;
        break;
    case 0x477b:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x477e:
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc4;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 4) != 0x0009) {
            pc = 0x477b;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xbf;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x22;
        push(r16[ax]);
        r8[al] = 0x09;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x284b;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x1264);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        di = 0x2854;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x22;
        push(r16[ax]);
        r8[al] = 0x0a;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc0;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x4815;
        break;
    case 0x4812:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x4815:
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc4;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 4) != 0x0009) {
            pc = 0x4812;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xd9;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x09;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x19;
        push(r16[ax]);
        r8[al] = 0x10;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x2857;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x1b;
        push(r16[ax]);
        r8[al] = 0x12;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r16[ax] = memory16get(ds, 0x1266);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x0a;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x32;
        push(r16[ax]);
        r8[al] = 0x10;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x285c;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x34;
        push(r16[ax]);
        r8[al] = 0x12;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r16[ax] = memory16get(ds, 0x1268);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_21ee();
        memory16set(ss, bp - 4, 0x0001);
        pc = 0x48ec;
        break;
    case 0x48e9:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x48ec:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x48f6;
        break;
    case 0x48f3:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x48f6:
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += memory16get(ss, bp - 2);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0006;
        idiv16(r16[cx]);
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        di = r16[ax];
        r8[dl] = memory[ds*16 + di + 98];
        r16[ax] = 0xb800;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        r16[ax] += 0x0547;
        di = r16[ax];
        es = pop();
        videoSet(es, di, r8[dl]);
        if (memory16get(ss, bp - 2) != 0x0006) {
            pc = 0x48f3;
            break;
        }
        r16[ax] = 0x0028;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90f9();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 4) != 0x0050) {
            pc = 0x48e9;
            break;
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_4936() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0015;
        push(cs);
        cs = 0x07d7;
        sub_8078();
        assert(cs == 0x01ed);
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x0063;
        push(r16[ax]);
        r8[al] = 0xb0;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0005;
        push(r16[ax]);
        r16[ax] = 0x004b;
        push(r16[ax]);
        r16[ax] = 0x004d;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0x0016;
        push(r16[ax]);
        r16[ax] = 0x0055;
        push(r16[ax]);
        r16[ax] = 0x0039;
        push(r16[ax]);
        r16[ax] = 0x005d;
        push(r16[ax]);
        r8[al] = 0xdd;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_2212();
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x499d;
        break;
    case 0x499a:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x499d:
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x49a7;
        break;
    case 0x49a4:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x49a7:
        r16[ax] = memory16get(ss, bp - 8);
        r16[cx] = 0x0007;
        imul16(r16[cx]);
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[cx] = 0x0007;
        imul16(r16[cx]);
        memory16set(ss, bp - 2, r16[ax]);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 2));
        sub_23e4();
        memory[ss*16 + bp - 9] = r8[al];
        if (memory[ss*16 + bp - 9] == 0x0a) {
            pc = 0x49d3;
            break;
        }
        r8[al] = 0x00;
        pc = 0x49d5;
        break;
    case 0x49d3:
        r8[al] = 0x01;
    case 0x49d5:
        r8[dl] = r8[al];
        if (memory[ss*16 + bp - 9] == 0x09) {
            pc = 0x49e1;
            break;
        }
        r8[al] = 0x00;
        pc = 0x49e3;
        break;
    case 0x49e1:
        r8[al] = 0x01;
    case 0x49e3:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x49ed;
            break;
        }
        memory[ss*16 + bp - 9] = 0x00;
    case 0x49ed:
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += 0x0007;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0005;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 9];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 8) != 0x0090) {
            pc = 0x49a4;
            break;
        }
        if (memory16get(ss, bp - 6) != 0x0048) {
            pc = 0x499a;
            break;
        }
        memory16set(ss, bp - 11, 0x0001);
        pc = 0x4a1b;
        break;
    case 0x4a18:
        memory16set(ss, bp - 11, memory16get(ss, bp - 11) + 1);
    case 0x4a1b:
        r16[ax] = memory16get(ss, bp - 11);
        r16[ax] += 0x0008;
        memory[ss*16 + bp - 18] = r8[al];
        r16[ax] = memory16get(ss, bp - 11);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9841);
        r16[ax] += 0x0003;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[ax] += 0x0007;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = memory16get(ss, bp - 11);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0003;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[ax] += 0x0005;
        r16[ax] += 0x0002;
        memory16set(ss, bp - 21, r16[ax]);
        r16[ax] = memory16get(ss, bp - 11);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0003;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[ax] += 0x0005;
        r16[ax] -= 0x0002;
        if (r16s[ax] > memory16gets(ss, bp - 21)) {
            pc = 0x4abe;
            break;
        }
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0x4a8e;
        break;
    case 0x4a8b:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x4a8e:
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] -= 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 6);
        if (r16[ax] != memory16get(ss, bp - 21)) {
            pc = 0x4a8b;
            break;
        }
    case 0x4abe:
        r16[ax] = memory16get(ss, bp - 11);
        r16[ax] <<= 1;
        di = memory16get(ss, bp + 4);
        di += r16[ax];
        r16[ax] = memory16get(ss, di - 9837);
        r16[ax] += 0x0003;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[ax] += 0x0005;
        memory16set(ss, bp - 6, r16[ax]);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax]--;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] -= 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax]--;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax]++;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] -= 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax]++;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0002;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 11) == 0x0002) {
            pc = 0x4b39;
            break;
        }
        pc = 0x4a18;
        break;
    case 0x4b39:
        memory16set(ss, bp - 6, 0x0001);
        pc = 0x4b43;
        break;
    case 0x4b40:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
    case 0x4b43:
        r8[al] = memory[ds*16 + 0x00b3];
        r8[ah] = 0;
        memory16set(ss, bp - 21, r16[ax]);
        r16[ax] = 0x0001;
        if (r16s[ax] > memory16gets(ss, bp - 21)) {
            pc = 0x4bac;
            break;
        }
        memory16set(ss, bp - 8, r16[ax]);
        pc = 0x4b5b;
        break;
    case 0x4b58:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x4b5b:
        r16[ax] = memory16get(ss, bp - 8);
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = 0x0039;
        mul16(r16[dx]);
        di = r16[ax];
        di += r16[cx];
        if (memory[ds*16 + di + 122] != 0x2a) {
            pc = 0x4b79;
            break;
        }
        memory[ss*16 + bp - 18] = 0x0e;
        pc = 0x4b7d;
        break;
    case 0x4b79:
        memory[ss*16 + bp - 18] = 0x01;
    case 0x4b7d:
        r8[al] = memory[ds*16 + 0x00b3];
        r8[ah] = 0;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0002;
        idiv16(r16[cx]);
        r16[dx] = r16[ax];
        r16[ax] = 0x0050;
        r16[ax] -= r16[dx];
        r16[ax]--;
        r16[ax] += memory16get(ss, bp - 8);
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0056;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        push(r16[ax]);
        push(cs);
        cs = 0x07d7;
        sub_7dfe();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ss, bp - 8);
        if (r16[ax] != memory16get(ss, bp - 21)) {
            pc = 0x4b58;
            break;
        }
    case 0x4bac:
        if (memory16get(ss, bp - 6) != 0x0005) {
            pc = 0x4b40;
            break;
        }
    case 0x4bb2:
        push(cs);
        cs = 0x08e1;
        sub_9155();
        assert(cs == 0x01ed);
        if (!r8[al]) {
            pc = 0x4bb2;
            break;
        }
        push(cs);
        cs = 0x08e1;
        sub_9167();
        assert(cs == 0x01ed);
        memory[ss*16 + bp - 19] = r8[al];
        push(cs);
        cs = 0x07d7;
        sub_8197();
        assert(cs == 0x01ed);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90ce();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x08e1;
        sub_901d();
        assert(cs == 0x01ed);
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function* sub_4bdb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x28e2;
        push(bp);
        sub_42a7();
        push(cs);
        cs = 0x08c0;
        sub_8c00();
        assert(cs == 0x01ed);
        memory[ss*16 + bp - 10460] = 0x00;
        memory16set(ss, bp - 10415, 0x00a0);
        memory[ss*16 + bp - 10462] = 0x01;
    case 0x4bfb:
        memory[ss*16 + bp - 10461] = 0x00;
        push(bp);
        sub_4386();
        memory16set(ss, bp - 10457, 0x0002);
        push(bp);
        sub_4732();
        push(cs);
        cs = 0x07d7;
        sub_8078();
        assert(cs == 0x01ed);
        push(bp);
        sub_4504();
        push(bp);
        sub_3b18();
    case 0x4c1b:
        if (memory[ds*16 + 0x14f1] == 0x00) {
            pc = 0x4c2c;
            break;
        }
        memory[ss*16 + bp - 10461] = 0x01;
        memory[ss*16 + bp - 10460] = 0x01;
    case 0x4c2c:
        if (memory[ds*16 + 0x152b] == 0x00) {
            pc = 0x4c38;
            break;
        }
        memory[ss*16 + bp - 10462] = 0x01;
    case 0x4c38:
        if (memory[ds*16 + 0x152c] == 0x00) {
            pc = 0x4c49;
            break;
        }
        memory[ss*16 + bp - 10462] = 0x00;
        push(cs);
        cs = 0x08e1;
        sub_914e();
        assert(cs == 0x01ed);
    case 0x4c49:
        memory16set(ss, bp - 10455, 0x0001);
        pc = 0x4c55;
        break;
    case 0x4c51:
        memory16set(ss, bp - 10455, memory16get(ss, bp - 10455) + 1);
    case 0x4c55:
        di = memory16get(ss, bp - 10455);
        if (memory[ds*16 + di + 4729] != 0x00) {
            pc = 0x4c63;
            break;
        }
        pc = 0x50ee;
        break;
    case 0x4c63:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, memory16get(ss, bp + di - 10429) - 0x0002);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10437) > signed16(0x0000)) {
            pc = 0x4c7f;
            break;
        }
        r8[al] = 0x00;
        pc = 0x4c81;
        break;
    case 0x4c7f:
        r8[al] = 0x01;
    case 0x4c81:
        r8[dl] = r8[al];
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) > signed16(0x0000)) {
            pc = 0x4c94;
            break;
        }
        r8[al] = 0x00;
        pc = 0x4c96;
        break;
    case 0x4c94:
        r8[al] = 0x01;
    case 0x4c96:
        r8[al] &= r8[dl];
        if (r8[al]) {
            pc = 0x4c9f;
            break;
        }
        pc = 0x50c7;
        break;
    case 0x4c9f:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9826);
        memory16set(ss, bp - 10451, r16[ax]);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9822);
        memory16set(ss, bp - 10449, r16[ax]);
        r16[ax] = 0;
        memory16set(ss, bp - 10453, r16[ax]);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 141);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4cdd;
            break;
        }
        r8[al] = memory[ss*16 + bp - 10455];
        push(r16[ax]);
        push(bp);
        sub_35ea();
        pc = 0x4ce9;
        break;
    case 0x4cdd:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = 0;
        memory16set(ss, bp + di - 10421, r16[ax]);
    case 0x4ce9:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 145);
        r8[al] = memory[ds*16 + di + 5360];
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 149);
        if (r8[al] == memory[ds*16 + di + 5360]) {
            pc = 0x4d3c;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 145);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4d22;
            break;
        }
        memory16set(ss, bp - 10453, memory16get(ss, bp - 10453) + 1);
        memory16set(ss, bp - 10449, memory16get(ss, bp - 10449) - 1);
        pc = 0x4d3c;
        break;
    case 0x4d22:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 149);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4d3c;
            break;
        }
        memory16set(ss, bp - 10453, memory16get(ss, bp - 10453) + 0x0004);
        memory16set(ss, bp - 10449, memory16get(ss, bp - 10449) + 1);
    case 0x4d3c:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 153);
        r8[al] = memory[ds*16 + di + 5360];
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 157);
        if (r8[al] == memory[ds*16 + di + 5360]) {
            pc = 0x4d90;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 153);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4d76;
            break;
        }
        memory16set(ss, bp - 10453, memory16get(ss, bp - 10453) + 0x0002);
        memory16set(ss, bp - 10451, memory16get(ss, bp - 10451) + 1);
        pc = 0x4d90;
        break;
    case 0x4d76:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 157);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4d90;
            break;
        }
        memory16set(ss, bp - 10453, memory16get(ss, bp - 10453) + 0x0008);
        memory16set(ss, bp - 10451, memory16get(ss, bp - 10451) - 1);
    case 0x4d90:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9818);
        memory16set(ss, bp - 10447, r16[ax]);
        if (memory16get(ss, bp - 10453) != 0x0000) {
            pc = 0x4da8;
            break;
        }
        pc = 0x4fc1;
        break;
    case 0x4da8:
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0001;
        if (r16[ax] != 0x0001) {
            pc = 0x4de4;
            break;
        }
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0002;
        if (r16[ax] != 0x0002) {
            pc = 0x4dc8;
            break;
        }
        memory16set(ss, bp - 10447, 0x0001);
        pc = 0x4de2;
        break;
    case 0x4dc8:
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0008;
        if (r16[ax] != 0x0008) {
            pc = 0x4ddc;
            break;
        }
        memory16set(ss, bp - 10447, 0x0007);
        pc = 0x4de2;
        break;
    case 0x4ddc:
        r16[ax] = 0;
        memory16set(ss, bp - 10447, r16[ax]);
    case 0x4de2:
        pc = 0x4e3a;
        break;
    case 0x4de4:
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0004;
        if (r16[ax] != 0x0004) {
            pc = 0x4e20;
            break;
        }
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0002;
        if (r16[ax] != 0x0002) {
            pc = 0x4e04;
            break;
        }
        memory16set(ss, bp - 10447, 0x0003);
        pc = 0x4e1e;
        break;
    case 0x4e04:
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0008;
        if (r16[ax] != 0x0008) {
            pc = 0x4e18;
            break;
        }
        memory16set(ss, bp - 10447, 0x0005);
        pc = 0x4e1e;
        break;
    case 0x4e18:
        memory16set(ss, bp - 10447, 0x0004);
    case 0x4e1e:
        pc = 0x4e3a;
        break;
    case 0x4e20:
        r16[ax] = memory16get(ss, bp - 10453);
        r16[ax] &= 0x0002;
        if (r16[ax] != 0x0002) {
            pc = 0x4e34;
            break;
        }
        memory16set(ss, bp - 10447, 0x0002);
        pc = 0x4e3a;
        break;
    case 0x4e34:
        memory16set(ss, bp - 10447, 0x0006);
    case 0x4e3a:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9818);
        if (r16[ax] == memory16get(ss, bp - 10447)) {
            pc = 0x4e79;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        r8[al] = memory[ss*16 + bp - 10447];
        push(r16[ax]);
        push(bp);
        sub_2e2c();
        if (r8s[al] > signed8(0x02)) {
            pc = 0x4e79;
            break;
        }
        r16[ax] = memory16get(ss, bp - 10447);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9818, r16[ax]);
    case 0x4e79:
        di = memory16get(ss, bp - 10455);
        if (memory[ss*16 + bp + di - 9827] != 0x00) {
            pc = 0x4e87;
            break;
        }
        pc = 0x4fb6;
        break;
    case 0x4e87:
        push(memory16get(ss, bp - 10451));
        push(memory16get(ss, bp - 10449));
        r8[al] = memory[ss*16 + bp - 10447];
        push(r16[ax]);
        push(bp);
        sub_2e2c();
        memory[ss*16 + bp - 10464] = r8[al];
        if (memorys[ss*16 + bp - 10464] <= signed8(0x02)) {
            pc = 0x4ead;
            break;
        }
        r8[al] = 0x05;
        push(r16[ax]);
        push(bp);
        sub_2b96();
        pc = 0x4fb6;
        break;
    case 0x4ead:
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 10455);
        di = r16[ax];
        di <<= 1;
        r16[dx] = memory16get(ss, bp + di - 9826);
        r16[ax] = memory16get(ss, bp - 10451);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x4ec8;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4ec8:
        push(r16[ax]);
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 10455);
        di = r16[ax];
        di <<= 1;
        r16[dx] = memory16get(ss, bp + di - 9822);
        r16[ax] = memory16get(ss, bp - 10449);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x4ee4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4ee4:
        push(r16[ax]);
        push(bp);
        sub_2b35();
        if (r16s[ax] >= signed16(0x0006)) {
            pc = 0x4ef1;
            break;
        }
        pc = 0x4fb6;
        break;
    case 0x4ef1:
        if (memory[ss*16 + bp - 10464] != 0x01) {
            pc = 0x4f33;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        push(bp);
        sub_2b96();
        push(memory16get(ss, bp - 10451));
        push(memory16get(ss, bp - 10449));
        push(memory16get(ss, bp - 10453));
        push(bp);
        sub_3195();
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, memory16get(ss, bp + di - 10429) - 0x0002);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ds, di + 4720, memory16get(ds, di + 4720) + 1);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9833, 0x0001);
        pc = 0x4fb6;
        break;
    case 0x4f33:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 9833) <= signed16(0x0000)) {
            pc = 0x4f4c;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9833, memory16get(ss, bp + di - 9833) - 1);
        pc = 0x4fb6;
        break;
    case 0x4f4c:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        di = memory16get(ds, di + 141);
        if (memory[ds*16 + di + 5360] == 0x00) {
            pc = 0x4f77;
            break;
        }
        push(memory16get(ss, bp - 10451));
        push(memory16get(ss, bp - 10449));
        push(memory16get(ss, bp - 10453));
        push(bp);
        sub_3195();
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ds, di + 4720, memory16get(ds, di + 4720) + 1);
    case 0x4f77:
        r16[ax] = memory16get(ss, bp - 10451);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9826, r16[ax]);
        r16[ax] = memory16get(ss, bp - 10449);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9822, r16[ax]);
        r16[ax] = memory16get(ss, bp - 10447);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 9818, r16[ax]);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, memory16get(ss, bp + di - 10429) - 0x0002);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ds, di + 4724, memory16get(ds, di + 4724) + 1);
    case 0x4fb6:
        di = memory16get(ss, bp - 10455);
        memory[ss*16 + bp + di - 9827] = 0x01;
        pc = 0x4fca;
        break;
    case 0x4fc1:
        di = memory16get(ss, bp - 10455);
        memory[ss*16 + bp + di - 9827] = 0x00;
    case 0x4fca:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9826);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] -= memory16get(ss, bp + di - 9841);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x4fe4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4fe4:
        push(r16[ax]);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9822);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] -= memory16get(ss, bp + di - 9837);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x4fff;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4fff:
        push(r16[ax]);
        push(bp);
        sub_2b35();
        if (r16s[ax] >= signed16(0x000f)) {
            pc = 0x5053;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, memory16get(ss, bp + di - 10429) + 0x0050);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) <= signed16(0x2c88)) {
            pc = 0x502e;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, 0x2c88);
    case 0x502e:
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10437, memory16get(ss, bp + di - 10437) + 0x0028);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10437) <= signed16(0x2c88)) {
            pc = 0x5053;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10437, 0x2c88);
    case 0x5053:
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 10455);
        di = r16[ax];
        di <<= 1;
        r16[dx] = memory16get(ss, bp + di - 9841);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9826);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x5074;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5074:
        push(r16[ax]);
        r16[ax] = 0x0003;
        r16[ax] -= memory16get(ss, bp - 10455);
        di = r16[ax];
        di <<= 1;
        r16[dx] = memory16get(ss, bp + di - 9837);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9822);
        r16[ax] -= r16[dx];
        if (!(r16[ax] & 0x8000)) {
            pc = 0x5096;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5096:
        push(r16[ax]);
        push(bp);
        sub_2b35();
        if (r16s[ax] >= signed16(0x000f)) {
            pc = 0x50c5;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, memory16get(ss, bp + di - 10429) + 0x001e);
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) <= signed16(0x2c88)) {
            pc = 0x50c5;
            break;
        }
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        memory16set(ss, bp + di - 10429, 0x2c88);
    case 0x50c5:
        pc = 0x50e3;
        break;
    case 0x50c7:
        push(memory16get(ss, bp - 10455));
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10455);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        push(bp);
        sub_2fec();
    case 0x50e3:
        if (memory16get(ss, bp - 10455) != 0x0001) {
            pc = 0x50ee;
            break;
        }
        push(bp);
        sub_2d7a();
    case 0x50ee:
        if (memory16get(ss, bp - 10455) == 0x0002) {
            pc = 0x50f8;
            break;
        }
        pc = 0x4c51;
        break;
    case 0x50f8:
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x5104;
        break;
    case 0x5100:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x5104:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) > signed16(0x0000)) {
            pc = 0x511d;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        memory16set(ss, bp + di - 10429, 0x0001);
    case 0x511d:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10437) > signed16(0x0000)) {
            pc = 0x5136;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        memory16set(ss, bp + di - 10437, 0x0001);
    case 0x5136:
        di = memory16get(ss, bp - 10445);
        if (memory[ds*16 + di + 4729] == 0x00) {
            pc = 0x5168;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        r8[al] = memory[ss*16 + bp - 10445];
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r8[al] = memory[ss*16 + bp + di - 9818];
        push(r16[ax]);
        sub_24c9();
    case 0x5168:
        if (memory16get(ss, bp - 10445) != 0x0002) {
            pc = 0x5100;
            break;
        }
        push(bp);
        sub_3851();
        push(bp);
        sub_3734();
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x5183;
        break;
    case 0x517f:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x5183:
        push(bp);
        sub_2d7a();
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) >= signed16(0x0c80)) {
            pc = 0x51f3;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10429) >= signed16(0x0578)) {
            pc = 0x51cc;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 10429));
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        if (r16[ax] >= 0x0050) {
            pc = 0x51ca;
            break;
        }
        r16[ax] = 0x0005;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        memory16set(ss, bp + di - 10441, r16[ax]);
    case 0x51ca:
        pc = 0x51f3;
        break;
    case 0x51cc:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 10429));
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        if (r16[ax] >= 0x0019) {
            pc = 0x51f3;
            break;
        }
        r16[ax] = 0x0004;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        memory16set(ss, bp + di - 10441, r16[ax]);
    case 0x51f3:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        if (memory16gets(ss, bp + di - 10441) > signed16(0x0000)) {
            pc = 0x5204;
            break;
        }
        r8[al] = 0x00;
        pc = 0x5206;
        break;
    case 0x5204:
        r8[al] = 0x01;
    case 0x5206:
        memory[ss*16 + bp - 10463] = r8[al];
        if (memory[ss*16 + bp - 10463] == 0x00) {
            pc = 0x521b;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        memory16set(ss, bp + di - 10441, memory16get(ss, bp + di - 10441) - 1);
    case 0x521b:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9826);
        r16[ax] >>= 1;
        r16[ax] -= 0x0013;
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r16[ax] = memory16get(ss, bp + di - 9822);
        r16[ax] -= 0x0026;
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ds, di + 137));
        r8[al] = memory[ss*16 + bp - 10463];
        push(r16[ax]);
        sub_22d4();
        if (memory16get(ss, bp - 10445) == 0x0002) {
            pc = 0x5255;
            break;
        }
        pc = 0x517f;
        break;
    case 0x5255:
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x5261;
        break;
    case 0x525d:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x5261:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        r16[ax] = memory16get(ss, bp - 10445);
        r16[ax] += 0x0002;
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r8[al] = memory[ss*16 + bp + di - 9818];
        push(r16[ax]);
        sub_24c9();
        if (memory16get(ss, bp - 10445) != 0x0002) {
            pc = 0x525d;
            break;
        }
        push(bp);
        sub_34cd();
        if (memory16gets(ss, bp - 10459) <= signed16(0x0000)) {
            pc = 0x52a1;
            break;
        }
        memory16set(ss, bp - 10459, memory16get(ss, bp - 10459) - 1);
    case 0x52a1:
        if (memory16get(ss, bp - 10459) != 0x0000) {
            pc = 0x52ad;
            break;
        }
        memory[ss*16 + bp - 10461] = 0x01;
    case 0x52ad:
        push(bp);
        sub_3e6c();
        r8[al] = memory[ss*16 + bp - 10434];
        if (r8[al] == memory[ss*16 + bp - 10430]) {
            pc = 0x52ce;
            break;
        }
        if (memory16gets(ss, bp - 10435) <= signed16(0x0000)) {
            pc = 0x52ce;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(bp);
        sub_40c4();
    case 0x52ce:
        r8[al] = memory[ss*16 + bp - 10432];
        if (r8[al] == memory[ss*16 + bp - 10428]) {
            pc = 0x52eb;
            break;
        }
        if (memory16gets(ss, bp - 10433) <= signed16(0x0000)) {
            pc = 0x52eb;
            break;
        }
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(bp);
        sub_40c4();
    case 0x52eb:
        push(bp);
        sub_422d();
    case 0x52ef:
        yield* sync();
//        si = 0x0040;
//        es = si;
//        r16[ax] = memoryBiosGet16(es, 0x006c);
//        if (r16[ax] == memory16get(ss, bp - 10466)) {
//            pc = 0x52ef;
//            break;
//        }
        si = 0x0040;
        es = si;
        r16[ax] = memoryBiosGet16(es, 0x006c);
        memory16set(ss, bp - 10466, r16[ax]);
        if (memory[ds*16 + 0x14f3] == 0x00) {
            pc = 0x5322;
            break;
        }
        r16[ax] = 0xb800;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 10415);
        r16[ax]++;
        di = r16[ax];
        es = pop();
        memory[es*16 + di] = 0x10;
    case 0x5322:
        r16[ax] = memory16get(ss, bp - 10415);
        r16[ax] += 0x0002;
        memory16set(ss, bp - 10415, r16[ax]);
        if (memory16gets(ss, bp - 10415) < signed16(0x0140)) {
            pc = 0x533b;
            break;
        }
        memory16set(ss, bp - 10415, 0x00a0);
    case 0x533b:
        if (memory[ds*16 + 0x14f3] == 0x00) {
            pc = 0x5352;
            break;
        }
        r16[ax] = 0xb800;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 10415);
        r16[ax]++;
        di = r16[ax];
        es = pop();
        memory[es*16 + di] = 0xff;
    case 0x5352:
        if (memory[ss*16 + bp - 10461] != 0x00) {
            pc = 0x535c;
            break;
        }
        pc = 0x4c1b;
        break;
    case 0x535c:
        push(cs);
        cs = 0x08e1;
        sub_914e();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x536d;
        break;
    case 0x5369:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x536d:
        di = memory16get(ss, bp - 10445);
        if (memory[ds*16 + di + 4729] == 0x00) {
            pc = 0x539f;
            break;
        }
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        r8[al] = memory[ss*16 + bp - 10445];
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r8[al] = memory[ss*16 + bp + di - 9818];
        push(r16[ax]);
        sub_24c9();
    case 0x539f:
        if (memory16get(ss, bp - 10445) != 0x0002) {
            pc = 0x5369;
            break;
        }
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x53b2;
        break;
    case 0x53ae:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x53b2:
        r16[ax] = memory16get(ss, bp - 9824);
        r16[ax] >>= 1;
        r16[ax] -= 0x0013;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 9820);
        r16[ax] -= 0x0026;
        push(r16[ax]);
        r16[ax] = 0x0143;
        push(r16[ax]);
        if (memory[ds*16 + 0x127a] == 0x00) {
            pc = 0x53d3;
            break;
        }
        r8[al] = 0x00;
        pc = 0x53d5;
        break;
    case 0x53d3:
        r8[al] = 0x01;
    case 0x53d5:
        push(r16[ax]);
        sub_22d4();
        r16[ax] = memory16get(ss, bp - 9822);
        r16[ax] >>= 1;
        r16[ax] -= 0x0013;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 9818);
        r16[ax] -= 0x0026;
        push(r16[ax]);
        r16[ax] = 0x0193;
        push(r16[ax]);
        if (memory[ds*16 + 0x127b] == 0x00) {
            pc = 0x53fa;
            break;
        }
        r8[al] = 0x00;
        pc = 0x53fc;
        break;
    case 0x53fa:
        r8[al] = 0x01;
    case 0x53fc:
        push(r16[ax]);
        sub_22d4();
        if (memory16get(ss, bp - 10445) != 0x0014) {
            pc = 0x53ae;
            break;
        }
        push(cs);
        cs = 0x07d7;
        sub_8197();
        assert(cs == 0x01ed);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90ce();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x08e1;
        sub_901d();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x5425;
        break;
    case 0x5421:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x5425:
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9826));
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        push(memory16get(ss, bp + di - 9822));
        r16[ax] = memory16get(ss, bp - 10445);
        r16[ax] += 0x0002;
        push(r16[ax]);
        di = memory16get(ss, bp - 10445);
        di <<= 1;
        r8[al] = memory[ss*16 + bp + di - 9818];
        push(r16[ax]);
        sub_24c9();
        if (memory16get(ss, bp - 10445) != 0x0002) {
            pc = 0x5421;
            break;
        }
        push(bp);
        sub_34cd();
        memory16set(ss, bp - 10445, 0x0001);
        pc = 0x5466;
        break;
    case 0x5462:
        memory16set(ss, bp - 10445, memory16get(ss, bp - 10445) + 1);
    case 0x5466:
        push(bp);
        sub_3e6c();
        if (memory16get(ss, bp - 10445) != 0x0014) {
            pc = 0x5462;
            break;
        }
        memory16set(ds, 0x1264, memory16get(ds, 0x1264) + 1);
        if (memory[ds*16 + 0x127a] != 0x00) {
            pc = 0x5480;
            break;
        }
        memory16set(ds, 0x1268, memory16get(ds, 0x1268) + 1);
    case 0x5480:
        if (memory[ds*16 + 0x127b] != 0x00) {
            pc = 0x548b;
            break;
        }
        memory16set(ds, 0x1266, memory16get(ds, 0x1266) + 1);
    case 0x548b:
        if (memory16gets(ds, 0x1268) >= signed16(0x0003)) {
            pc = 0x5496;
            break;
        }
        r8[al] = 0x00;
        pc = 0x5498;
        break;
    case 0x5496:
        r8[al] = 0x01;
    case 0x5498:
        r8[dl] = r8[al];
        if (memory16gets(ds, 0x1266) >= signed16(0x0003)) {
            pc = 0x54a5;
            break;
        }
        r8[al] = 0x00;
        pc = 0x54a7;
        break;
    case 0x54a5:
        r8[al] = 0x01;
    case 0x54a7:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x54b2;
            break;
        }
        memory[ss*16 + bp - 10460] = 0x01;
    case 0x54b2:
        if (memory[ss*16 + bp - 10460] != 0x00) {
            pc = 0x54bc;
            break;
        }
        pc = 0x4bfb;
        break;
    case 0x54bc:
        push(cs);
        cs = 0x08c0;
        sub_8c40();
        assert(cs == 0x01ed);
        r16[ax] = 0x0040;
        push(r16[ax]);
        di = 0x0017;
        es = pop();
        r8[al] = memoryBiosGet(es, di);
        r8[al] &= 0xf0;
        r8[dl] = r8[al];
        r16[ax] = 0x0040;
        push(r16[ax]);
        di = 0x0017;
        es = pop();
        memoryBiosSet(es, di, r8[dl]);
        push(bp);
        sub_4936();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_54e3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0012;
        memory16set(ss, bp - 12, 0x0001);
        memory16set(ss, bp - 10, 0x0001);
        r16[ax] = 0;
        memory16set(ss, bp - 8, r16[ax]);
        r16[ax] = 0;
        memory16set(ss, bp - 6, r16[ax]);
    case 0x54fd:
        r16[ax] = 0x0003;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax]--;
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax]--;
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + r16[ax]);
        if (memory16gets(ss, bp - 8) <= signed16(0x0002)) {
            pc = 0x5522;
            break;
        }
        memory16set(ss, bp - 8, 0x0002);
    case 0x5522:
        if (memory16gets(ss, bp - 6) <= signed16(0x0002)) {
            pc = 0x552d;
            break;
        }
        memory16set(ss, bp - 6, 0x0002);
    case 0x552d:
        if (memory16gets(ss, bp - 8) >= signed16(0xfffe)) {
            pc = 0x5538;
            break;
        }
        memory16set(ss, bp - 8, 0xfffe);
    case 0x5538:
        if (memory16gets(ss, bp - 6) >= signed16(0xfffe)) {
            pc = 0x5543;
            break;
        }
        memory16set(ss, bp - 6, 0xfffe);
    case 0x5543:
        r16[ax] = memory16get(ss, bp - 8);
        memory16set(ss, bp + 10, memory16get(ss, bp + 10) + r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        memory16set(ss, bp + 8, memory16get(ss, bp + 8) + r16[ax]);
        r16[ax] = memory16get(ss, bp - 12);
        r16[ax]++;
        r16[ax] >>= 1;
        memory16set(ss, bp - 14, r16[ax]);
        r16[ax] = memory16get(ss, bp - 14);
        memory16set(ss, bp - 16, r16[ax]);
        r16[ax] = memory16get(ss, bp - 12);
        r16[ax] >>= 1;
        r16[ax] = -r16[ax];
        if (r16s[ax] <= memory16gets(ss, bp - 16)) {
            pc = 0x556d;
            break;
        }
        pc = 0x561c;
        break;
    case 0x556d:
        memory16set(ss, bp - 4, r16[ax]);
        pc = 0x5575;
        break;
    case 0x5572:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0x5575:
        r16[ax] = memory16get(ss, bp - 4);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x557e;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x557e:
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] += memory16get(ss, bp - 14);
        r16[ax] -= r16[dx];
        memory16set(ss, bp - 18, r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        if (!(r16[ax] & 0x8000)) {
            pc = 0x5594;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5594:
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp - 14);
        r16[ax] -= r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] -= r16[dx];
        if (r16s[ax] > memory16gets(ss, bp - 18)) {
            pc = 0x5611;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x55af;
        break;
    case 0x55ac:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x55af:
        if (memory16gets(ss, bp - 2) < signed16(0x01ff)) {
            pc = 0x55ba;
            break;
        }
        r8[al] = 0x00;
        pc = 0x55bc;
        break;
    case 0x55ba:
        r8[al] = 0x01;
    case 0x55bc:
        r8[bl] = r8[al];
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] += memory16get(ss, bp - 4);
        if (r16s[ax] < signed16(0x03ff)) {
            pc = 0x55cd;
            break;
        }
        r8[al] = 0x00;
        pc = 0x55cf;
        break;
    case 0x55cd:
        r8[al] = 0x01;
    case 0x55cf:
        r8[cl] = r8[al];
        if (memory16gets(ss, bp - 2) > signed16(0x0000)) {
            pc = 0x55db;
            break;
        }
        r8[al] = 0x00;
        pc = 0x55dd;
        break;
    case 0x55db:
        r8[al] = 0x01;
    case 0x55dd:
        r8[dl] = r8[al];
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] += memory16get(ss, bp - 4);
        if (r16s[ax] > 0) {
            pc = 0x55ed;
            break;
        }
        r8[al] = 0x00;
        pc = 0x55ef;
        break;
    case 0x55ed:
        r8[al] = 0x01;
    case 0x55ef:
        r8[al] &= r8[dl];
        r8[al] &= r8[cl];
        r8[al] &= r8[bl];
        if (!r8[al]) {
            pc = 0x5609;
            break;
        }
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] += memory16get(ss, bp - 4);
        push(r16[ax]);
        push(memory16get(ss, bp - 2));
        r8[al] = 0x07;
        push(r16[ax]);
        sub_235c();
    case 0x5609:
        r16[ax] = memory16get(ss, bp - 2);
        if (r16[ax] != memory16get(ss, bp - 18)) {
            pc = 0x55ac;
            break;
        }
    case 0x5611:
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] == memory16get(ss, bp - 16)) {
            pc = 0x561c;
            break;
        }
        pc = 0x5572;
        break;
    case 0x561c:
        r16[ax] = memory16get(ss, bp - 10);
        memory16set(ss, bp - 12, memory16get(ss, bp - 12) + r16[ax]);
        r16[ax] = memory16get(ss, bp - 12);
        if (r16s[ax] < memory16gets(ss, bp + 6)) {
            pc = 0x562f;
            break;
        }
        memory16set(ss, bp - 10, 0xffff);
    case 0x562f:
        if (memory16gets(ss, bp - 12) <= signed16(0x0001)) {
            pc = 0x5638;
            break;
        }
        pc = 0x54fd;
        break;
    case 0x5638:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 8;
        return;
    } while (1);
}
function* sub_563e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0306;
        if (memory16get(ds, 0x1323) != 0xfffe) {
            pc = 0x5652;
            break;
        }
        memory16set(ds, 0x1323, 0x0001);
    case 0x5652:
        if (memory16get(ds, 0x1323) != 0xffff) {
            pc = 0x565c;
            break;
        }
        pc = 0x5e08;
        break;
    case 0x565c:
        r16[ax] = memory16get(ds, 0x1323);
        if (r16[ax] == 0x0001) {
            pc = 0x5667;
            break;
        }
        pc = 0x5731;
        break;
    case 0x5667:
        r16[ax] = 0;
        memory16set(ds, 0x1321, r16[ax]);
        pc = 0x5672;
        break;
    case 0x566e:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x5672:
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] <<= 1;
        r16[ax] += 0x0006;
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] <<= 1;
        r16[ax] += 0x0006;
        r16[dx] = pop();
        r16[ax] += r16[dx];
        di = memory16get(ds, 0x1321);
        memory[ss*16 + bp + di - 518] = r8[al];
        if (memory16get(ds, 0x1321) != 0x01d7) {
            pc = 0x566e;
            break;
        }
        memory16set(ss, bp - 2, 0xffff);
        memory16set(ds, 0x1321, 0x0028);
        pc = 0x56b8;
        break;
    case 0x56b4:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x56b8:
        r16[ax] = 0x01ce;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = memory16get(ss, bp - 4);
        if (r16[ax] != memory16get(ss, bp - 2)) {
            pc = 0x56d5;
            break;
        }
        r16[ax] = memory16get(ss, bp - 4);
        r16[ax] += 0x0003;
        memory16set(ss, bp - 4, r16[ax]);
    case 0x56d5:
        r16[ax] = memory16get(ss, bp - 4);
        memory16set(ss, bp - 2, r16[ax]);
        di = memory16get(ss, bp - 4);
        di = bp+di-0x0206;
        push(ss);
        push(di);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += 0x0014;
        push(es);
        push(di);
        r16[ax] = 0x01d8;
        r16[ax] -= memory16get(ss, bp - 4);
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_abec();
        assert(cs == 0x01ed);
        di = bp - 0x206;
        push(ss);
        push(di);
        r16[ax] = 0x01ec;
        r16[ax] -= memory16get(ss, bp - 4);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        push(es);
        push(di);
        push(memory16get(ss, bp - 4));
        push(cs);
        cs = 0x0947;
        sub_abec();
        assert(cs == 0x01ed);
        if (memory16get(ds, 0x1321) != 0x01d8) {
            pc = 0x56b4;
            break;
        }
        pc = 0x5dfa;
        break;
    case 0x5731:
        if (r16[ax] != 0x0002) {
            pc = 0x5755;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x1325, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x1327, r16[ax]);
        memory16set(ds, 0x1329, 0x6000);
        memory16set(ds, 0x132b, 0x6000);
        memory16set(ds, 0x131f, 0x0027);
        pc = 0x5dfa;
        break;
    case 0x5755:
        if (r16[ax] == 0x0003) {
            pc = 0x575d;
            break;
        }
        pc = 0x59f6;
        break;
    case 0x575d:
        r16[ax] = memory16get(ds, 0x131f);
        r16[ax]++;
        if (r16s[ax] <= signed16(0x01d7)) {
            pc = 0x5769;
            break;
        }
        pc = 0x59d7;
        break;
    case 0x5769:
        memory16set(ds, 0x131f, r16[ax]);
        pc = 0x5772;
        break;
    case 0x576e:
        memory16set(ds, 0x131f, memory16get(ds, 0x131f) + 1);
    case 0x5772:
        if (memory16gets(ds, 0x131f) > signed16(0x01a5)) {
            pc = 0x577e;
            break;
        }
        r8[al] = 0x00;
        pc = 0x5780;
        break;
    case 0x577e:
        r8[al] = 0x01;
    case 0x5780:
        r8[dl] = r8[al];
        if (memory16gets(ds, 0x131f) < signed16(0x005a)) {
            pc = 0x578d;
            break;
        }
        r8[al] = 0x00;
        pc = 0x578f;
        break;
    case 0x578d:
        r8[al] = 0x01;
    case 0x578f:
        r8[al] |= r8[dl];
        if (!r8[al]) {
            pc = 0x579f;
            break;
        }
        memory16set(ds, 0x1325, memory16get(ds, 0x1325) + 0x0032);
        memory16set(ds, 0x1327, memory16get(ds, 0x1327) + 0x0032);
    case 0x579f:
        memory16set(ds, 0x1321, 0x0001);
        pc = 0x57ab;
        break;
    case 0x57a7:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x57ab:
        r16[ax] = 0x0258;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] -= 0x012c;
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) + r16[ax]);
        r16[ax] = 0x0005;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        if (r16[ax] != 0x0001) {
            pc = 0x5805;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4899) <= signed16(0x0100)) {
            pc = 0x57f2;
            break;
        }
        r16[ax] = 0x01f4;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) - r16[ax]);
        pc = 0x5805;
        break;
    case 0x57f2:
        r16[ax] = 0x01f4;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) + r16[ax]);
    case 0x5805:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4899);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, memory16get(ds, di + 4903) + r16[ax]);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) >= signed16(0x2a00)) {
            pc = 0x584d;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) >= signed16(0x0af0)) {
            pc = 0x5841;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, 0x2800);
    case 0x5841:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0x0100);
    case 0x584d:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) <= signed16(0x5e00)) {
            pc = 0x5881;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) <= signed16(0x6000)) {
            pc = 0x5875;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, 0x6000);
    case 0x5875:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0xff00);
    case 0x5881:
        if (memory16get(ds, 0x1321) == 0x0002) {
            pc = 0x588b;
            break;
        }
        pc = 0x57a7;
        break;
    case 0x588b:
        r16[ax] = 0x001e;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16get(ss, bp - 6) != 0x0001) {
            pc = 0x58d6;
            break;
        }
        r16[ax] = 0x008c;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        r16[ax] += memory16get(ss, bp - 6);
        push(r16[ax]);
        push(memory16get(ds, 0x131f));
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[dx] = r16[ax];
        r16[ax] = 0x0015;
        r16[ax] -= r16[dx];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x0006;
        push(r16[ax]);
        push(bp);
        sub_54e3();
        pc = 0x591a;
        break;
    case 0x58d6:
        if (memory16get(ss, bp - 6) != 0x0002) {
            pc = 0x591a;
            break;
        }
        r16[ax] = 0x008c;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x03ff;
        r16[ax] -= r16[dx];
        r16[ax] -= memory16get(ss, bp - 6);
        push(r16[ax]);
        push(memory16get(ds, 0x131f));
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[dx] = r16[ax];
        r16[ax] = 0x0015;
        r16[ax] -= r16[dx];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x0006;
        push(r16[ax]);
        push(bp);
        sub_54e3();
    case 0x591a:
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x131f));
        r8[al] = 0x07;
        push(r16[ax]);
        sub_235c();
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x03ff;
        r16[ax] -= r16[dx];
        push(r16[ax]);
        push(memory16get(ds, 0x131f));
        r8[al] = 0x07;
        push(r16[ax]);
        sub_235c();
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        push(es);
        push(di);
        r16[ax] = memory16get(ds, 0x1329);
        r16[ax] += 0x0100;
        r16[cx] = 0x0009;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r8[al] = 0x77;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132b);
        r16[ax] += 0x0100;
        r16[cx] = 0x0009;
        r16[ax] >>= r8[cl];
        r16[dx] = r16[ax];
        r16[ax] = 0x0200;
        r16[ax] -= r16[dx];
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        push(es);
        push(di);
        r16[ax] = memory16get(ds, 0x132b);
        r16[ax] += 0x0100;
        r16[cx] = 0x0009;
        r16[ax] >>= r8[cl];
        push(r16[ax]);
        r8[al] = 0x77;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x01ed);
        di = bp - 0x306;
        push(ss);
        push(di);
        yield* sub_1ed0();
        di = 0x131a;
        push(ds);
        push(di);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9a4f();
        assert(cs == 0x01ed);
        di = 0x131a;
        push(ds);
        push(di);
        di = 0x0068;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9b25();
        assert(cs == 0x01ed);
        if (flags.zero) {
            pc = 0x59cc;
            break;
        }
        if (memory16get(ds, 0x131f) == 0x01d7) {
            pc = 0x59cc;
            break;
        }
        pc = 0x5e0e;
        break;
    case 0x59cc:
        if (memory16get(ds, 0x131f) == 0x01d7) {
            pc = 0x59d7;
            break;
        }
        pc = 0x576e;
        break;
    case 0x59d7:
        r16[ax] = 0;
        memory16set(ds, 0x1325, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x1327, r16[ax]);
        memory16set(ds, 0x1329, 0x4000);
        memory16set(ds, 0x132b, 0x4000);
        memory16set(ds, 0x131d, 0x0027);
        pc = 0x5dfa;
        break;
    case 0x59f6:
        if (r16[ax] == 0x0004) {
            pc = 0x59fe;
            break;
        }
        pc = 0x5dfa;
        break;
    case 0x59fe:
        r16[ax] = memory16get(ds, 0x131d);
        r16[ax]++;
        if (r16s[ax] <= signed16(0x03d7)) {
            pc = 0x5a0a;
            break;
        }
        pc = 0x5da0;
        break;
    case 0x5a0a:
        memory16set(ds, 0x131d, r16[ax]);
        pc = 0x5a13;
        break;
    case 0x5a0f:
        memory16set(ds, 0x131d, memory16get(ds, 0x131d) + 1);
    case 0x5a13:
        memory16set(ds, 0x1321, 0x0001);
        pc = 0x5a1f;
        break;
    case 0x5a1b:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x5a1f:
        r16[ax] = 0x0258;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] -= 0x012c;
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) + r16[ax]);
        r16[ax] = 0x0005;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        if (r16[ax] != 0x0001) {
            pc = 0x5a79;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4899) <= signed16(0x0100)) {
            pc = 0x5a66;
            break;
        }
        r16[ax] = 0x01f4;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) - r16[ax]);
        pc = 0x5a79;
        break;
    case 0x5a66:
        r16[ax] = 0x01f4;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, memory16get(ds, di + 4899) + r16[ax]);
    case 0x5a79:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4899) <= signed16(0x0500)) {
            pc = 0x5a95;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0x0500);
        pc = 0x5aaf;
        break;
    case 0x5a95:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4899) >= signed16(0xfb00)) {
            pc = 0x5aaf;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0xfb00);
    case 0x5aaf:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4899);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, memory16get(ds, di + 4903) + r16[ax]);
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) >= signed16(0x2a00)) {
            pc = 0x5af7;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) >= signed16(0x0af0)) {
            pc = 0x5aeb;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, 0x2800);
    case 0x5aeb:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0x0100);
    case 0x5af7:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) <= signed16(0x5e00)) {
            pc = 0x5b2b;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        if (memory16gets(ds, di + 4903) <= signed16(0x6000)) {
            pc = 0x5b1f;
            break;
        }
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4903, 0x6000);
    case 0x5b1f:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        memory16set(ds, di + 4899, 0xff00);
    case 0x5b2b:
        if (memory16get(ds, 0x1321) == 0x0002) {
            pc = 0x5b35;
            break;
        }
        pc = 0x5a1b;
        break;
    case 0x5b35:
        r16[ax] = 0x0023;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16get(ss, bp - 6) != 0x0001) {
            pc = 0x5b7d;
            break;
        }
        r16[ax] = 0x008c;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        push(memory16get(ds, 0x131d));
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[dx] = r16[ax];
        r16[ax] = 0x0015;
        r16[ax] -= r16[dx];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x0006;
        push(r16[ax]);
        push(bp);
        sub_54e3();
        pc = 0x5bcb;
        break;
    case 0x5b7d:
        if (memory16get(ss, bp - 6) != 0x0002) {
            pc = 0x5bcb;
            break;
        }
        r16[ax] = 0x008c;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 6, r16[ax]);
        push(memory16get(ds, 0x131d));
        r16[ax] = 0x003c;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[cx] = r16[ax];
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x01ff;
        r16[ax] -= r16[dx];
        r16[ax] -= r16[cx];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[cx] = 0x0007;
        idiv16(r16[cx]);
        r16[dx] = r16[ax];
        r16[ax] = 0x0015;
        r16[ax] -= r16[dx];
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_a504();
        assert(cs == 0x01ed);
        r16[ax] += 0x0006;
        push(r16[ax]);
        push(bp);
        sub_54e3();
    case 0x5bcb:
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        memory16set(ss, bp - 520, r16[ax]);
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        r16[ax] -= 0x0005;
        if (r16s[ax] > memory16gets(ss, bp - 520)) {
            pc = 0x5c02;
            break;
        }
        memory16set(ds, 0x1321, r16[ax]);
        pc = 0x5beb;
        break;
    case 0x5be7:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x5beb:
        push(memory16get(ds, 0x131d));
        push(memory16get(ds, 0x1321));
        r8[al] = 0x07;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ds, 0x1321);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5be7;
            break;
        }
    case 0x5c02:
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x01ff;
        r16[ax] -= r16[dx];
        memory16set(ss, bp - 520, r16[ax]);
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x0204;
        r16[ax] -= r16[dx];
        if (r16s[ax] < memory16gets(ss, bp - 520)) {
            pc = 0x5c44;
            break;
        }
        memory16set(ds, 0x1321, r16[ax]);
        pc = 0x5c2d;
        break;
    case 0x5c29:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) - 1);
    case 0x5c2d:
        push(memory16get(ds, 0x131d));
        push(memory16get(ds, 0x1321));
        r8[al] = 0x07;
        push(r16[ax]);
        sub_235c();
        r16[ax] = memory16get(ds, 0x1321);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5c29;
            break;
        }
    case 0x5c44:
        r16[ax] = memory16get(ds, 0x131d);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0001) {
            pc = 0x5c52;
            break;
        }
        pc = 0x5d63;
        break;
    case 0x5c52:
        r16[ax] = memory16get(ds, 0x131d);
        r16[ax] >>= 1;
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16gets(ds, 0x1325) >= signed16(0xff00)) {
            pc = 0x5c9d;
            break;
        }
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        memory16set(ss, bp - 520, r16[ax]);
        r16[ax] = 0x0028;
        if (r16s[ax] > memory16gets(ss, bp - 520)) {
            pc = 0x5c9b;
            break;
        }
        memory16set(ds, 0x131f, r16[ax]);
        pc = 0x5c7d;
        break;
    case 0x5c79:
        memory16set(ds, 0x131f, memory16get(ds, 0x131f) + 1);
    case 0x5c7d:
        r16[ax] = memory16get(ss, bp - 6);
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = 0x77;
        r16[ax] = memory16get(ds, 0x131f);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5c79;
            break;
        }
    case 0x5c9b:
        pc = 0x5cd9;
        break;
    case 0x5c9d:
        r8[al] = memory[ds*16 + 0x132a];
        r8[ah] = 0;
        r16[ax] -= 0x0005;
        memory16set(ss, bp - 520, r16[ax]);
        r16[ax] = 0x0028;
        if (r16s[ax] > memory16gets(ss, bp - 520)) {
            pc = 0x5cd9;
            break;
        }
        memory16set(ds, 0x131f, r16[ax]);
        pc = 0x5cbb;
        break;
    case 0x5cb7:
        memory16set(ds, 0x131f, memory16get(ds, 0x131f) + 1);
    case 0x5cbb:
        r16[ax] = memory16get(ss, bp - 6);
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = 0x77;
        r16[ax] = memory16get(ds, 0x131f);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5cb7;
            break;
        }
    case 0x5cd9:
        if (memory16gets(ds, 0x1327) >= signed16(0xff00)) {
            pc = 0x5d23;
            break;
        }
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x01ff;
        r16[ax] -= r16[dx];
        memory16set(ss, bp - 520, r16[ax]);
        r16[ax] = 0x01d7;
        if (r16s[ax] < memory16gets(ss, bp - 520)) {
            pc = 0x5d21;
            break;
        }
        memory16set(ds, 0x131f, r16[ax]);
        pc = 0x5d03;
        break;
    case 0x5cff:
        memory16set(ds, 0x131f, memory16get(ds, 0x131f) - 1);
    case 0x5d03:
        r16[ax] = memory16get(ss, bp - 6);
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = 0x77;
        r16[ax] = memory16get(ds, 0x131f);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5cff;
            break;
        }
    case 0x5d21:
        pc = 0x5d63;
        break;
    case 0x5d23:
        r8[al] = memory[ds*16 + 0x132c];
        r8[ah] = 0;
        r16[dx] = r16[ax];
        r16[ax] = 0x0204;
        r16[ax] -= r16[dx];
        memory16set(ss, bp - 520, r16[ax]);
        r16[ax] = 0x01d7;
        if (r16s[ax] < memory16gets(ss, bp - 520)) {
            pc = 0x5d63;
            break;
        }
        memory16set(ds, 0x131f, r16[ax]);
        pc = 0x5d45;
        break;
    case 0x5d41:
        memory16set(ds, 0x131f, memory16get(ds, 0x131f) - 1);
    case 0x5d45:
        r16[ax] = memory16get(ss, bp - 6);
        di = memory16get(ds, 0x131f);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        di += r16[ax];
        memory[es*16 + di] = 0x77;
        r16[ax] = memory16get(ds, 0x131f);
        if (r16[ax] != memory16get(ss, bp - 520)) {
            pc = 0x5d41;
            break;
        }
    case 0x5d63:
        di = bp - 0x306;
        push(ss);
        push(di);
        yield* sub_1ed0();
        di = 0x131a;
        push(ds);
        push(di);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9a4f();
        assert(cs == 0x01ed);
        di = 0x131a;
        push(ds);
        push(di);
        di = 0x0068;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9b25();
        assert(cs == 0x01ed);
        if (flags.zero) {
            pc = 0x5d95;
            break;
        }
        if (memory16get(ds, 0x131d) == 0x03d7) {
            pc = 0x5d95;
            break;
        }
        pc = 0x5e0e;
        break;
    case 0x5d95:
        if (memory16get(ds, 0x131d) == 0x03d7) {
            pc = 0x5da0;
            break;
        }
        pc = 0x5a0f;
        break;
    case 0x5da0:
        r16[ax] = 0;
        memory16set(ds, 0x1321, r16[ax]);
        pc = 0x5dab;
        break;
    case 0x5da7:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x5dab:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        push(es);
        push(di);
        r16[ax] = 0x0200;
        push(r16[ax]);
        r8[al] = 0x77;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x01ed);
        if (memory16get(ds, 0x1321) != 0x0027) {
            pc = 0x5da7;
            break;
        }
        memory16set(ds, 0x1321, 0x01d8);
        pc = 0x5dd8;
        break;
    case 0x5dd4:
        memory16set(ds, 0x1321, memory16get(ds, 0x1321) + 1);
    case 0x5dd8:
        di = memory16get(ds, 0x1321);
        di <<= 1;
        di <<= 1;
        r16[tx] = di;
        di = memory16get(ds, r16[tx] + 1092);
        es = memory16get(ds, r16[tx] + 1092 + 2);
        push(es);
        push(di);
        r16[ax] = 0x0200;
        push(r16[ax]);
        r8[al] = 0x77;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x01ed);
        if (memory16get(ds, 0x1321) != 0x01ff) {
            pc = 0x5dd4;
            break;
        }
    case 0x5dfa:
        memory16set(ds, 0x1323, memory16get(ds, 0x1323) + 1);
        if (memory16gets(ds, 0x1323) >= signed16(0x0005)) {
            pc = 0x5e08;
            break;
        }
        pc = 0x565c;
        break;
    case 0x5e08:
        memory16set(ds, 0x1323, 0xffff);
    case 0x5e0e:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_5f2a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x18;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        r8[al] = 0x0c;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x0022;
        push(r16[ax]);
        r8[al] = 0x04;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3f42;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x04;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x001e;
        push(r16[ax]);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3f4f;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x05;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x001d;
        push(r16[ax]);
        r8[al] = 0x0b;
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x0036;
        push(r16[ax]);
        r8[al] = 0x16;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xda;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x5fe0;
        break;
    case 0x5fdd:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x5fe0:
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc4;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0014) {
            pc = 0x5fdd;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xbf;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3f65;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3f7c;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3f93;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3faa;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc0;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x608b;
        break;
    case 0x6088:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x608b:
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xc4;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0014) {
            pc = 0x6088;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xd9;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        memory[ds*16 + 0x1331] = 0x00;
        if (memory16get(ds, 0x132f) != 0x0000) {
            pc = 0x60db;
            break;
        }
        pc = 0x64ba;
        break;
    case 0x60db:
        if (memory[ds*16 + 0x1319] != 0x00) {
            pc = 0x60e8;
            break;
        }
        r8[al] = 0x04;
        push(r16[ax]);
        sub_21c4();
    case 0x60e8:
        r8[al] = 0x08;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x60fa;
        break;
    case 0x60f7:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x60fa:
        r8[al] = 0x28;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0xb3;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0019) {
            pc = 0x60f7;
            break;
        }
        r8[al] = 0x2b;
        push(r16[ax]);
        r8[al] = 0x06;
        push(r16[ax]);
        r8[al] = 0x4f;
        push(r16[ax]);
        r8[al] = 0x14;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x0b;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x0e;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3fc1;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = memory[ds*16 + 0x127a];
        if (r8[al] != memory[ds*16 + 0x127b]) {
            pc = 0x6183;
            break;
        }
        memory[ds*16 + 0x127a] = 0x00;
        memory[ds*16 + 0x127b] = 0x00;
    case 0x6183:
        r16[ax] = memory16get(ds, 0x1266);
        if (r16s[ax] > memory16gets(ds, 0x1268)) {
            pc = 0x6190;
            break;
        }
        r8[al] = 0x00;
        pc = 0x6192;
        break;
    case 0x6190:
        r8[al] = 0x01;
    case 0x6192:
        cbw();
        r16[cx] = 0x0007;
        r16[ax] <<= r8[cl];
        r16[ax]++;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3fcc;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x1268);
        if (r16s[ax] > memory16gets(ds, 0x1266)) {
            pc = 0x61c3;
            break;
        }
        r8[al] = 0x00;
        pc = 0x61c5;
        break;
    case 0x61c3:
        r8[al] = 0x01;
    case 0x61c5:
        cbw();
        r16[cx] = 0x0007;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3fea;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3ff0;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x621e;
        break;
    case 0x621b:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x621e:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4712);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x621b;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4001;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x627f;
        break;
    case 0x627c:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x627f:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4716);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x627c;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4012;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x62e0;
        break;
    case 0x62dd:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x62e0:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        if (memory16get(ds, di + 4712) != 0x0000) {
            pc = 0x6300;
            break;
        }
        di = memory16get(ss, bp - 2);
        di <<= 1;
        memory16set(ds, di + 4712, 0x0001);
    case 0x6300:
        di = 0x1694;
        push(ds);
        push(di);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4716);
        r16[cx] = 0x0064;
        imul16(r16[cx]);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        idiv16(memory16get(ds, di + 4712));
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        r8[al] = 0x25;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x62dd;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4024;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x637c;
        break;
    case 0x6379:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x637c:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4720);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x6379;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4035;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x63dd;
        break;
    case 0x63da:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x63dd:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = memory16get(ss, bp - 2);
        di <<= 1;
        r16[ax] = memory16get(ds, di + 4724);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 2) != 0x0002) {
            pc = 0x63da;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = memory[ds*16 + 0x127a];
        if (r8[al] != memory[ds*16 + 0x127b]) {
            pc = 0x6435;
            break;
        }
        pc = 0x64ba;
        break;
    case 0x6435:
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4046;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x1266);
        if (r16s[ax] <= memory16gets(ds, 0x1268)) {
            pc = 0x647e;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4055;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        pc = 0x649d;
        break;
    case 0x647e:
        r8[al] = 0x02;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x3fea;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
    case 0x649d:
        r8[al] = 0x06;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0x2e;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
    case 0x64ba:
        sub_21ee();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_64c1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x64d1;
        break;
    case 0x64ce:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x64d1:
        r16[ax] = 0xb8e6;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[ax] <<= 1;
        di = r16[ax];
        es = pop();
        memory16set(es, di, 0x085f);
        if (memory16get(ss, bp - 2) != 0x004f) {
            pc = 0x64ce;
            break;
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_6508() {
    push(0x7777);
    push(bp);
    bp = sp;
    sub_64c1();
    r8[al] = 0x01;
    push(r16[ax]);
    r8[al] = 0x01;
    push(r16[ax]);
    r8[al] = 0x50;
    push(r16[ax]);
    r8[al] = 0x19;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_8fdd();
    assert(cs == 0x01ed);
    r8[al] = 0x35;
    push(r16[ax]);
    r8[al] = 0x19;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_9070();
    assert(cs == 0x01ed);
    r8[al] = 0x0f;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x461c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    sub_21ee();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_6a18() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = 0x0e;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    r8[al] = 0x22;
    push(r16[ax]);
    r8[al] = 0x01;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_9070();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4680;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x468d;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x46dd;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x472e;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    r8[al] = 0x0b;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x474d;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x475c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x479b;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x47e8;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4831;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    r8[al] = 0x0b;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x483c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    r8[al] = 0x09;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x484c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4851;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x0a;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4876;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x487c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4885;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x48ae;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x48fc;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4925;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    r8[al] = 0x0b;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4973;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    r8[al] = 0x03;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x497f;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x49c0;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4a0c;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4a5d;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4aad;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x4afc;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa62();
    assert(cs == 0x01ed);
    sub_6508();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_736f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0009;
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x0a;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x22;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4e24;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4e30;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4e7d;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4ecc;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4f1b;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4f69;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x4fb5;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5000;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5017;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5061;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x50ad;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x50f6;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0b;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
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
        sub_8d15();
        assert(cs == 0x01ed);
        r8[al] = 0x1b;
        push(r16[ax]);
        r8[al] = 0x10;
        push(r16[ax]);
        r8[al] = 0x38;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5127;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 6) < 0x07c4) {
            pc = 0x751d;
            break;
        }
        r8[al] = 0x00;
        pc = 0x751f;
        break;
    case 0x751d:
        r8[al] = 0x01;
    case 0x751f:
        r8[cl] = r8[al];
        if (memory16get(ss, bp - 4) >= 0x0006) {
            pc = 0x752b;
            break;
        }
        r8[al] = 0x00;
        pc = 0x752d;
        break;
    case 0x752b:
        r8[al] = 0x01;
    case 0x752d:
        r8[dl] = r8[al];
        if (memory16get(ss, bp - 6) == 0x07c7) {
            pc = 0x753a;
            break;
        }
        r8[al] = 0x00;
        pc = 0x753c;
        break;
    case 0x753a:
        r8[al] = 0x01;
    case 0x753c:
        r8[al] &= r8[dl];
        r8[dl] = r8[al];
        if (memory16get(ss, bp - 6) > 0x07c7) {
            pc = 0x754b;
            break;
        }
        r8[al] = 0x00;
        pc = 0x754d;
        break;
    case 0x754b:
        r8[al] = 0x01;
    case 0x754d:
        r8[al] |= r8[dl];
        r8[al] |= r8[cl];
        if (!r8[al]) {
            pc = 0x7585;
            break;
        }
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x513a;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5150;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        pc = 0x75b3;
        break;
    case 0x7585:
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5163;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x517e;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
    case 0x75b3:
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x14;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5194;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0f;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x51ba;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x51c5;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x10;
        push(r16[ax]);
        r8[al] = 0x16;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x51d4;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x520e;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_64c1();
        r8[al] = 0x26;
        push(r16[ax]);
        r8[al] = 0x04;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        r8[al] = 0x0f;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x524d;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_21ee();
    case 0x76a5:
        push(cs);
        cs = 0x08e1;
        sub_9155();
        assert(cs == 0x01ed);
        if (!r8[al]) {
            pc = 0x76a5;
            break;
        }
        push(cs);
        cs = 0x08e1;
        sub_9167();
        assert(cs == 0x01ed);
        if (r8[al]) {
            pc = 0x76bf;
            break;
        }
        push(cs);
        cs = 0x08e1;
        sub_9167();
        assert(cs == 0x01ed);
        memory[ss*16 + bp - 9] = r8[al];
    case 0x76bf:
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x4e;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0f;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5268;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0a;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5273;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x10;
        push(r16[ax]);
        r8[al] = 0x13;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5276;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x52a9;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x52e8;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x0f;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x4e;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5313;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5322;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x0a;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x532d;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        memory16set(ss, bp - 8, 0x0001);
        pc = 0x781a;
        break;
    case 0x7817:
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + 1);
    case 0x781a:
        di = 0x1694;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        if (memory16get(ss, bp - 8) != 0x0004) {
            pc = 0x7817;
            break;
        }
        r8[al] = 0x0e;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        r8[al] = 0x10;
        push(r16[ax]);
        r8[al] = 0x11;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5331;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5370;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x53b0;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x53ed;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x542c;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5469;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x17;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_6508();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_78e5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0002;
        if (memory16get(ds, 0x132f) == 0x0000) {
            pc = 0x7923;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r8[al] = 0x28;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        r8[al] = 0x20;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
    case 0x7923:
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x18;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_794c() {
    push(0x7777);
    push(bp);
    bp = sp;
    sub_5f2a();
    r8[al] = 0x01;
    push(r16[ax]);
    r8[al] = 0x01;
    push(r16[ax]);
    r8[al] = 0x50;
    push(r16[ax]);
    r8[al] = 0x19;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_8fdd();
    assert(cs == 0x01ed);
    r16[ax] = memory16get(ds, 0x132f);
    r16[ax] += 0x0020;
    push(r16[ax]);
    r8[al] = 0x19;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_9070();
    assert(cs == 0x01ed);
    r8[al] = 0x01;
    push(r16[ax]);
    push(cs);
    cs = 0x08e1;
    sub_90b4();
    assert(cs == 0x01ed);
    di = 0x1694;
    push(ds);
    push(di);
    di = 0x5a6b;
    push(cs);
    push(di);
    r16[ax] = 0;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ab1d();
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x0947;
    sub_aa7b();
    assert(cs == 0x01ed);
    sub_21ee();
    memory[ds*16 + 0x132d] = 0x00;
    memory16set(ds, 0x1323, 0xfffe);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_79a3() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_79ed() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(cs);
        cs = 0x0947;
        sub_9470();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x08e1;
        yield* sub_8e10();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x081e;
        sub_8457();
        assert(cs == 0x01ed);
        bp = sp;
        sp -= 0x0100;
        memory[ds*16 + 0x1311] = 0x01;
        r16[ax] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[dx] = es;
        memory16set(ds, 0x130d, r16[ax]);
        memory16set(ds, 0x130f, r16[dx]);
        r16[ax] = 0x017c;
        r16[dx] = cs;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[dx]);
        memory[ds*16 + 0x157a] = 0x00;
        r16[ax] = 0x5ad3;
        memory16set(ds, 0x1317, r16[ax]);
        r16[ax] = memory16get(ds, 0x157e);
        memory16set(ds, 0x1312, r16[ax]);
        sub_28ec();
        push(cs);
        cs = 0x07d7;
        sub_7fcc();
        assert(cs == 0x01ed);
        memory[ds*16 + 0x1314] = r8[al];
        r16[ax] = 0x0040;
        push(r16[ax]);
        di = 0x0017;
        es = pop();
        r8[al] = memoryBiosGet(es, di);
        r8[al] &= 0x0c;
        if (r8[al] == 0x0c) {
            pc = 0x7a50;
            break;
        }
        pc = 0x7ae1;
        break;
    case 0x7a50:
        r8[al] = 0x04;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5ada;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_97f7();
        assert(cs == 0x01ed);
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0007;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        r8[al] = 0xb3;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aabf();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5ae0;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        r8[al] = memory[ds*16 + 0x1314];
        r8[ah] = 0;
        r16[dx] = 0;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_aba8();
        assert(cs == 0x01ed);
        di = 0x5ae8;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5aec;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa62();
        assert(cs == 0x01ed);
        di = 0x1594;
        push(ds);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_aa15();
        assert(cs == 0x01ed);
    case 0x7ae1:
        sub_21ee();
        r8[al] = memory[ds*16 + 0x1314];
        push(r16[ax]);
        di = bp - 0x20;
        push(ss);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9c51();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x02;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x03;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x04;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x09;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        r8[al] = 0x08;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_9cd5();
        assert(cs == 0x01ed);
        if (!flags.zero) {
            pc = 0x7b2f;
            break;
        }
        r8[al] = 0x02;
        push(r16[ax]);
        sub_21c4();
    case 0x7b2f:
        if (memory[ds*16 + 0x1319] != 0x00) {
            pc = 0x7b3c;
            break;
        }
        r8[al] = 0x04;
        push(r16[ax]);
        sub_21c4();
    case 0x7b3c:
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90ce();
        assert(cs == 0x01ed);
        sub_21da();
        push(cs);
        cs = 0x0947;
        sub_a58a();
        assert(cs == 0x01ed);
        sub_2502();
        sub_2882();
        memory[ds*16 + 0x132e] = 0x00;
        r16[ax] = 0;
        memory16set(ds, 0x132f, r16[ax]);
        memory[ds*16 + 0x1331] = 0x01;
    case 0x7b61:
        sub_794c();
        sub_5f2a();
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x0020;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        r8[al] = 0x01;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5afa;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_21ee();
        memory[ds*16 + 0x132d] = 0x00;
        memory16set(ds, 0x1323, 0xfffe);
    case 0x7bb4:
        if (memory[ds*16 + 0x132d] == 0x00) {
            pc = 0x7bd4;
            break;
        }
        di = bp - 0x100;
        push(ss);
        push(di);
        yield* sub_1ed0();
        di = 0x131a;
        push(ds);
        push(di);
        r16[ax] = 0x0002;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9a4f();
        assert(cs == 0x01ed);
        pc = 0x7bd7;
        break;
    case 0x7bd4:
        yield* sub_563e();
    case 0x7bd7:
        if (memory16get(ds, 0x1323) == 0xffff) {
            pc = 0x7be2;
            break;
        }
        r8[al] = 0x00;
        pc = 0x7be4;
        break;
    case 0x7be2:
        r8[al] = 0x01;
    case 0x7be4:
        r8[dl] = r8[al];
        if (memory[ds*16 + 0x132d] == 0x00) {
            pc = 0x7bf1;
            break;
        }
        r8[al] = 0x00;
        pc = 0x7bf3;
        break;
    case 0x7bf1:
        r8[al] = 0x01;
    case 0x7bf3:
        r8[al] &= r8[dl];
        if (!r8[al]) {
            pc = 0x7c40;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        r16[ax] = memory16get(ds, 0x132f);
        r16[ax] += 0x0020;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        r8[al] = 0x02;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5b0b;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_21ee();
        memory[ds*16 + 0x132d] = 0x01;
    case 0x7c40:
        r8[al] = memory[ds*16 + 0x131c];
        push(r16[ax]);
        di = bp - 0x20;
        push(ss);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9c51();
        assert(cs == 0x01ed);
        r8[al] = 0x3b;
        push(r16[ax]);
        r8[al] = 0x3d;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c81();
        assert(cs == 0x01ed);
        r8[al] = 0x44;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_9cd5();
        assert(cs == 0x01ed);
        if (!flags.zero) {
            pc = 0x7c6c;
            break;
        }
        r8[al] = 0x00;
        pc = 0x7c6e;
        break;
    case 0x7c6c:
        r8[al] = 0x01;
    case 0x7c6e:
        r8[dl] = r8[al];
        if (memory[ds*16 + 0x131b] == 0x1b) {
            pc = 0x7c7b;
            break;
        }
        r8[al] = 0x00;
        pc = 0x7c7d;
        break;
    case 0x7c7b:
        r8[al] = 0x01;
    case 0x7c7d:
        r8[al] |= r8[dl];
        if (r8[al]) {
            pc = 0x7c86;
            break;
        }
        pc = 0x7bb4;
        break;
    case 0x7c86:
        r8[al] = 0x32;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        if (memory[ds*16 + 0x131b] != 0x1b) {
            pc = 0x7ca6;
            break;
        }
        sub_5f2a();
        pc = 0x7ca9;
        break;
    case 0x7ca6:
        sub_78e5();
    case 0x7ca9:
        r8[al] = memory[ds*16 + 0x131c];
        if (r8[al] != 0x3c) {
            pc = 0x7cb6;
            break;
        }
        sub_6a18();
        pc = 0x7d48;
        break;
    case 0x7cb6:
        if (r8[al] != 0x3d) {
            pc = 0x7cc0;
            break;
        }
        sub_736f();
        pc = 0x7d48;
        break;
    case 0x7cc0:
        if (r8[al] != 0x3b) {
            pc = 0x7d3f;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x18;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        if (memory16gets(ds, 0x1323) <= signed16(0x0000)) {
            pc = 0x7d20;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        r8[al] = 0x50;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fdd();
        assert(cs == 0x01ed);
        sub_21da();
        r8[al] = 0x20;
        push(r16[ax]);
        r8[al] = 0x19;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_9070();
        assert(cs == 0x01ed);
        r8[al] = 0x81;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_90b4();
        assert(cs == 0x01ed);
        di = 0x1694;
        push(ds);
        push(di);
        di = 0x5afa;
        push(cs);
        push(di);
        r16[ax] = 0;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ab1d();
        assert(cs == 0x01ed);
        push(cs);
        cs = 0x0947;
        sub_aa7b();
        assert(cs == 0x01ed);
        sub_21ee();
    case 0x7d20:
        if (memory16get(ds, 0x1323) == 0xffff) {
            pc = 0x7d2c;
            break;
        }
        yield* sub_563e();
        pc = 0x7d20;
        break;
    case 0x7d2c:
        yield* sub_4bdb();
        memory16set(ds, 0x132f, 0xffec);
        sub_794c();
        memory[ds*16 + 0x132d] = 0x00;
        pc = 0x7d48;
        break;
    case 0x7d3f:
        if (r8[al] != 0x44) {
            pc = 0x7d48;
            break;
        }
        memory[ds*16 + 0x132e] = 0x01;
    case 0x7d48:
        if (memory[ds*16 + 0x132e] != 0x00) {
            pc = 0x7d52;
            break;
        }
        pc = 0x7bb4;
        break;
    case 0x7d52:
        if (memory[ds*16 + 0x132e] != 0x00) {
            pc = 0x7d5c;
            break;
        }
        pc = 0x7b61;
        break;
    case 0x7d5c:
        sub_79a3();
        sub_21da();
        memory[ds*16 + 0x1311] = 0x00;
        sp = bp;
        r16[ax] = 0;
        push(cs);
        cs = 0x0947;
        sub_9663();
        assert(cs == 0x01ed);
        push(bp);
        bp = sp;
        r16[ax] = 0x0014;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x01ed);
        sp -= 0x0014;
        memory[ss*16 + bp - 17] = 0x00;
        memory16set(ss, bp - 14, 0x2300);
        memory[ss*16 + bp - 19] = 0x02;
        r8[al] = 0x10;
        push(r16[ax]);
        di = bp - 0x14;
        push(ss);
        push(di);
        push(cs);
        cs = 0x08d0;
        sub_8db2();
        assert(cs == 0x01ed);
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_7d70() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d();
    assert(cs == 0x07d7);
    sp -= 0x0014;
    memory[ss*16 + bp - 17] = 0x00;
    memory16set(ss, bp - 14, 0x2300);
    memory[ss*16 + bp - 19] = 0x02;
    r8[al] = 0x10;
    push(r16[ax]);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2();
    assert(cs == 0x07d7);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_7d9c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0x0003;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        sp -= 0x0003;
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[cx] = 0x00a0;
        imul16(r16[cx]);
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 8];
        r8[al] &= 0xfe;
        r8[ah] = 0;
        r16[ax]++;
        r16[ax] += r16[dx];
        memory16set(ss, bp - 3, r16[ax]);
        r8[al] = memory[ss*16 + bp + 8];
        r8[al] &= 0x01;
        if (r8[al] != 0x01) {
            pc = 0x7de5;
            break;
        }
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 3);
        es = pop();
        r8[al] = memory[es*16 + di];
        r8[al] &= 0xf0;
        r8[ah] = 0;
        r16[cx] = 0x0004;
        r16[ax] >>= r8[cl];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x7df5;
        break;
    case 0x7de5:
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 3);
        es = pop();
        r8[al] = memory[es*16 + di];
        r8[al] &= 0x0f;
        memory[ss*16 + bp - 1] = r8[al];
    case 0x7df5:
        r8[al] = memory[ss*16 + bp - 1];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_7dfe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0x0002;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        sp -= 0x0002;
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0;
        r16[cx] = 0x00a0;
        imul16(r16[cx]);
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 10];
        r8[al] &= 0xfe;
        r8[ah] = 0;
        r16[ax]++;
        r16[ax] += r16[dx];
        memory16set(ss, bp - 2, r16[ax]);
        if (memory[ss*16 + bp + 6] <= 0x0f) {
            pc = 0x7e8b;
            break;
        }
        if (memory[ss*16 + bp + 6] <= 0x2f) {
            pc = 0x7e51;
            break;
        }
        r8[al] = memory[ss*16 + bp + 10];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 8];
        push(r16[ax]);
        push(cs);
        sub_7d9c();
        r8[dl] = r8[al];
        r8[al] = memory[ss*16 + bp + 6];
        r8[al] &= 0x0f;
        if (r8[al] == r8[dl]) {
            pc = 0x7e4b;
            break;
        }
        pc = 0x7edd;
        break;
    case 0x7e4b:
        memory[ss*16 + bp + 6] = 0x00;
        pc = 0x7e8b;
        break;
    case 0x7e51:
        if (memory[ss*16 + bp + 6] <= 0x1f) {
            pc = 0x7e73;
            break;
        }
        r8[al] = memory[ss*16 + bp + 10];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 8];
        push(r16[ax]);
        push(cs);
        sub_7d9c();
        if (!r8[al]) {
            pc = 0x7e69;
            break;
        }
        pc = 0x7edd;
        break;
    case 0x7e69:
        r8[al] = memory[ss*16 + bp + 6];
        r8[al] &= 0x0f;
        memory[ss*16 + bp + 6] = r8[al];
        pc = 0x7e8b;
        break;
    case 0x7e73:
        r8[al] = memory[ss*16 + bp + 10];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 8];
        push(r16[ax]);
        push(cs);
        sub_7d9c();
        r8[dl] = r8[al];
        r8[al] = memory[ss*16 + bp + 6];
        r8[al] &= 0x0f;
        r8[al] ^= r8[dl];
        memory[ss*16 + bp + 6] = r8[al];
    case 0x7e8b:
        r8[al] = memory[ss*16 + bp + 10];
        r8[al] &= 0x01;
        if (r8[al] != 0x01) {
            pc = 0x7ec0;
            break;
        }
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0;
        r16[cx] = 0x0004;
        r16[ax] <<= r8[cl];
        memory[ss*16 + bp + 6] = r8[al];
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 2);
        es = pop();
        r8[al] = videoGet(es, di);
        r8[al] &= 0x0f;
        r8[al] |= memory[ss*16 + bp + 6];
        r8[dl] = r8[al];
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 2);
        es = pop();
        videoSet(es, di, r8[dl]);
        pc = 0x7edd;
        break;
    case 0x7ec0:
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 2);
        es = pop();
        r8[al] = videoGet(es, di);
        r8[al] &= 0xf0;
        r8[al] |= memory[ss*16 + bp + 6];
        r8[dl] = r8[al];
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = memory16get(ss, bp - 2);
        es = pop();
        videoSet(es, di, r8[dl]);
    case 0x7edd:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 6;
        return;
    } while (1);
}
function sub_7ee3() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0x0014;
    push(cs);
    cs = 0x0947;
    sub_971d();
    assert(cs == 0x07d7);
    sp -= 0x0014;
    memory16set(ss, bp - 20, 0x1010);
    r8[al] = memory[ss*16 + bp + 12];
    r8[ah] = 0;
    memory16set(ss, bp - 18, r16[ax]);
    r8[al] = memory[ss*16 + bp + 10];
    memory[ss*16 + bp - 13] = r8[al];
    r8[al] = memory[ss*16 + bp + 8];
    memory[ss*16 + bp - 15] = r8[al];
    r8[al] = memory[ss*16 + bp + 6];
    memory[ss*16 + bp - 16] = r8[al];
    r8[al] = 0x10;
    push(r16[ax]);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8db2();
    assert(cs == 0x07d7);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
function sub_7f23() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0x0002;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        sp -= 0x0002;
        if (memory16get(ds, 0x1332) == 0x0009) {
            pc = 0x7f7f;
            break;
        }
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x7f42;
        break;
    case 0x7f3f:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x7f42:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 481];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 482];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 483];
        push(r16[ax]);
        push(cs);
        sub_7ee3();
        if (memory16get(ss, bp - 2) != 0x000f) {
            pc = 0x7f3f;
            break;
        }
        pc = 0x7fc8;
        break;
    case 0x7f7f:
        r16[ax] = 0;
        memory16set(ss, bp - 2, r16[ax]);
        pc = 0x7f89;
        break;
    case 0x7f86:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x7f89:
        di = memory16get(ss, bp - 2);
        r8[al] = memory[ds*16 + di + 465];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 481];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 482];
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x0003;
        mul16(r16[dx]);
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 483];
        push(r16[ax]);
        push(cs);
        sub_7ee3();
        if (memory16get(ss, bp - 2) != 0x000f) {
            pc = 0x7f86;
            break;
        }
    case 0x7fc8:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_7fcc() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0x0006;
    push(cs);
    cs = 0x0947;
    sub_971d();
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
    sub_82c9();
    assert(cs == 0x07d7);
    r16[ax] = memory16get(ss, bp - 6);
    memory16set(ss, bp - 2, r16[ax]);
    r16[ax] = memory16get(ss, bp - 2);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_7ff6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        r16[ax] = memory16get(ds, 0x1332);
        if (r16[ax] == 0x0001) {
            pc = 0x8012;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x8012;
            break;
        }
        if (r16[ax] != 0x0009) {
            pc = 0x802f;
            break;
        }
    case 0x8012:
        r8[al] = memory[ds*16 + 0x1336];
        cbw();
        r16[cx] = 0x0005;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 4];
        cbw();
        r16[cx] = 0x0003;
        r16[ax] <<= r8[cl];
        r16[ax]++;
        r16[ax] += r16[dx];
        r16[dx] = 0x03d8;
        out8(r16[dx], r8[al]);
        pc = 0x8054;
        break;
    case 0x802f:
        if (r16[ax] == 0xfffe) {
            pc = 0x8039;
            break;
        }
        if (r16[ax] != 0x0007) {
            pc = 0x8054;
            break;
        }
    case 0x8039:
        r8[al] = memory[ds*16 + 0x1336];
        cbw();
        r16[cx] = 0x0005;
        r16[ax] <<= r8[cl];
        r16[dx] = r16[ax];
        r8[al] = memory[ss*16 + bp + 4];
        cbw();
        r16[cx] = 0x0003;
        r16[ax] <<= r8[cl];
        r16[ax]++;
        r16[ax] += r16[dx];
        r16[dx] = 0x03b8;
        out8(r16[dx], r8[al]);
    case 0x8054:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function sub_805a() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0;
    push(cs);
    cs = 0x0947;
    sub_971d();
    assert(cs == 0x07d7);
    r8[al] = memory[ss*16 + bp + 6];
    r16[dx] = 0x03d4;
    out8(r16[dx], r8[al]);
    r8[al] = memory[ss*16 + bp + 4];
    r16[dx] = 0x03d5;
    out8(r16[dx], r8[al]);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
function sub_8078() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0x0034;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        sp -= 0x0034;
        memory16set(ds, 0x1334, 0xb800);
        r16[ax] = 0x0003;
        push(r16[ax]);
        push(cs);
        cs = 0x08e1;
        sub_8fc8();
        assert(cs == 0x07d7);
        r16[ax] = memory16get(ds, 0x1334);
        push(r16[ax]);
        di = 0;
        es = pop();
        push(es);
        push(di);
        r16[ax] = 0x5dc0;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x07d7);
        memory[ds*16 + 0x01d0] = 0x01;
        memory[ds*16 + 0x1336] = 0x00;
        push(cs);
        sub_7fcc();
        memory16set(ds, 0x1332, r16[ax]*0+9); // lazy to find out
        r16[ax] = memory16get(ds, 0x1332);
        if (r16[ax] == 0x0001) {
            pc = 0x80cd;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x80cd;
            break;
        }
        if (r16[ax] != 0x0008) {
            pc = 0x80ff;
            break;
        }
    case 0x80cd:
        r8[al] = 0x00;
        push(r16[ax]);
        sub_7ff6();
        r8[al] = 0x04;
        push(r16[ax]);
        r8[al] = 0x7f;
        push(r16[ax]);
        sub_805a();
        r8[al] = 0x06;
        push(r16[ax]);
        r8[al] = 0x64;
        push(r16[ax]);
        sub_805a();
        r8[al] = 0x07;
        push(r16[ax]);
        r8[al] = 0x70;
        push(r16[ax]);
        sub_805a();
        r8[al] = 0x09;
        push(r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_805a();
        r8[al] = 0x01;
        push(r16[ax]);
        sub_7ff6();
        pc = 0x8166;
        break;
    case 0x80ff:
        if (r16[ax] != 0x0009) {
            pc = 0x8131;
            break;
        }
        r8[al] = 0x00;
        push(r16[ax]);
        sub_7ff6();
        r8[al] = 0x09;
        push(r16[ax]);
        r8[al] = 0x03;
        push(r16[ax]);
        sub_805a();
        memory16set(ss, bp - 20, 0x1003);
        memory[ss*16 + bp - 18] = 0x00;
        r8[al] = 0x10;
        push(r16[ax]);
        di = bp - 0x14;
        push(ss);
        push(di);
        push(cs);
        cs = 0x08d0;
        sub_8db2();
        assert(cs == 0x07d7);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_7ff6();
        pc = 0x8166;
        break;
    case 0x8131:
        if (r16[ax] == 0x0003) {
            pc = 0x813b;
            break;
        }
        if (r16[ax] != 0x0004) {
            pc = 0x8166;
            break;
        }
    case 0x813b:
        r8[al] = 0x00;
        push(r16[ax]);
        sub_7ff6();
        r8[al] = 0x09;
        push(r16[ax]);
        r8[al] = 0x02;
        push(r16[ax]);
        sub_805a();
        memory16set(ss, bp - 20, 0x1003);
        memory[ss*16 + bp - 18] = 0x00;
        r8[al] = 0x10;
        push(r16[ax]);
        di = bp - 0x14;
        push(ss);
        push(di);
        push(cs);
        cs = 0x08d0;
        sub_8db2();
        assert(cs == 0x07d7);
        r8[al] = 0x01;
        push(r16[ax]);
        sub_7ff6();
    case 0x8166:
        push(cs);
        sub_7d70();
        r8[al] = memory[ds*16 + 0x1332];
        push(r16[ax]);
        di = bp - 0x34;
        push(ss);
        push(di);
        push(cs);
        cs = 0x0947;
        sub_9c51();
        assert(cs == 0x07d7);
        r8[al] = 0x02;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x07d7);
        r8[al] = 0x09;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_9c60();
        assert(cs == 0x07d7);
        push(cs);
        cs = 0x0947;
        sub_9cd5();
        assert(cs == 0x07d7);
        if (flags.zero) {
            pc = 0x8193;
            break;
        }
        push(cs);
        sub_7f23();
    case 0x8193:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_8197() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0x0014;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x07d7);
        sp -= 0x0014;
        if (memory[ds*16 + 0x01d0] == 0x00) {
            pc = 0x81d1;
            break;
        }
        memory16set(ss, bp - 20, 0x0004);
        r8[al] = 0x10;
        push(r16[ax]);
        di = bp - 0x14;
        push(ss);
        push(di);
        push(cs);
        cs = 0x08d0;
        sub_8db2();
        assert(cs == 0x07d7);
        push(memory16get(ds, 0x157e));
        push(cs);
        cs = 0x08e1;
        sub_8fc8();
        assert(cs == 0x07d7);
        memory[ds*16 + 0x01d0] = 0x00;
        push(cs);
        cs = 0x081e;
        sub_837d();
        assert(cs == 0x07d7);
    case 0x81d1:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_82c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        push(es);
        push(di);
        di = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        push(es);
        push(di);
        push(cs);
        sub_8692();
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        if (memory16gets(es, di) >= signed16(0x0000)) {
            pc = 0x82f4;
            break;
        }
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        memory16set(es, di, 0xfffe);
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        r16[ax] = memory16get(es, di);
        memory16set(ds, 0x1472, r16[ax]);
    case 0x82f4:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 8;
        return;
    } while (1);
}
function sub_82fa() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0x0055;
    r16[dx] = cs;
    memory16set(ds, 0x147a, r16[ax]);
    memory16set(ds, 0x147c, r16[dx]);
    r16[ax] = 0x0055;
    r16[dx] = cs;
    memory16set(ds, 0x148c, r16[ax]);
    memory16set(ds, 0x148e, r16[dx]);
    r16[ax] = 0;
    memory16set(ds, 0x147e, r16[ax]);
    memory16set(ds, 0x1480, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x1490, r16[ax]);
    memory16set(ds, 0x1492, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x1482, r16[ax]);
    memory16set(ds, 0x1484, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x1488, r16[ax]);
    memory16set(ds, 0x148a, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x1462, r16[ax]);
    memory16set(ds, 0x1464, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x1466, r16[ax]);
    r16[ax] = 0;
    memory16set(ds, 0x13c0, r16[ax]);
    memory[ds*16 + 0x14a1] = 0x00;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function sub_8350() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ds, 0x147e);
        r16[ax] |= memory16get(ds, 0x1480);
        if (r16[ax]) {
            pc = 0x8375;
            break;
        }
        r16[ax] = memory16get(ds, 0x147a);
        es = memory16get(ds, 0x147a + 2);
        r16[dx] = es;
        memory16set(ds, 0x147e, r16[ax]);
        memory16set(ds, 0x1480, r16[dx]);
        r16[ax] = 0x0055;
        r16[dx] = cs;
        memory16set(ds, 0x147a, r16[ax]);
        memory16set(ds, 0x147c, r16[dx]);
    case 0x8375:
        push(cs);
        sub_855c();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_837d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory[ds*16 + 0x14a1] != 0x00) {
            pc = 0x838d;
            break;
        }
        pc = 0x843f;
        break;
    case 0x838d:
        push(cs);
        sub_8350();
        di = 0x1488;
        push(ds);
        push(di);
        push(memory16get(ds, 0x1429));
        push(cs);
        cs = memory16get(ds, 0x133c + 2);
        callIndirect(memory16get(ds, 0x133c + 2), memory16get(ds, 0x133c));
        assert(cs == 0x081e);
        r16[ax] = memory16get(ds, 0x1482);
        r16[ax] |= memory16get(ds, 0x1484);
        if (!r16[ax]) {
            pc = 0x83b9;
            break;
        }
        di = memory16get(ds, 0x146e);
        di <<= 1;
        di <<= 1;
        r16[ax] = 0;
        memory16set(ds, di + 5163, r16[ax]);
        memory16set(ds, di + 5165, r16[ax]);
    case 0x83b9:
        di = 0x1482;
        push(ds);
        push(di);
        push(memory16get(ds, 0x1486));
        push(cs);
        cs = memory16get(ds, 0x133c + 2);
        callIndirect(memory16get(ds, 0x133c + 2), memory16get(ds, 0x133c));
        assert(cs == 0x081e);
        sub_82fa();
        memory16set(ss, bp - 2, 0x0001);
        pc = 0x83d3;
        break;
    case 0x83d0:
        memory16set(ss, bp - 2, memory16get(ss, bp - 2) + 1);
    case 0x83d3:
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = 0x000f;
        mul16(r16[dx]);
        di = r16[ax];
        di += 0x0329;
        memory16set(ss, bp - 6, di);
        memory16set(ss, bp - 4, ds);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        if (memory[es*16 + di + 10] == 0x00) {
            pc = 0x8439;
            break;
        }
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        if (memory16get(es, di + 8) == 0x0000) {
            pc = 0x8439;
            break;
        }
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[ax] = memory16get(es, di);
        r16[ax] |= memory16get(es, di + 2);
        if (!r16[ax]) {
            pc = 0x8439;
            break;
        }
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        push(es);
        push(di);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        push(memory16get(es, di + 8));
        push(cs);
        cs = memory16get(ds, 0x133c + 2);
        callIndirect(memory16get(ds, 0x133c + 2), memory16get(ds, 0x133c));
        assert(cs == 0x081e);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[ax] = 0;
        memory16set(es, di + 8, r16[ax]);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[ax] = 0;
        memory16set(es, di, r16[ax]);
        memory16set(es, di + 2, r16[ax]);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[ax] = 0;
        memory16set(es, di + 4, r16[ax]);
        memory16set(es, di + 6, r16[ax]);
    case 0x8439:
        if (memory16get(ss, bp - 2) != 0x000a) {
            pc = 0x83d0;
            break;
        }
    case 0x843f:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_8457() {
    push(0x7777);
    bp = sp;
    r16[ax] = 0;
    memory16set(ds, 0x1472, r16[ax]);
    memory16set(ds, 0x17a2, 0x0100);
    memory16set(ds, 0x1429, 0x1000);
    push(cs);
    sub_86d7();
    sub_82fa();
    r16[ax] = 0x0263;
    r16[dx] = cs;
    memory16set(ds, 0x17a4, r16[ax]);
    memory16set(ds, 0x17a6, r16[dx]);
    r16[ax] = 0x00a5;
    r16[dx] = cs;
    memory16set(ds, 0x1338, r16[ax]);
    memory16set(ds, 0x133a, r16[dx]);
    r16[ax] = 0x00bb;
    r16[dx] = cs;
    memory16set(ds, 0x133c, r16[ax]);
    memory16set(ds, 0x133e, r16[dx]);
    memory[ds*16 + 0x13c2] = 0x00;
    memory[ds*16 + 0x13cb] = 0x00;
    di = 0x142b;
    push(ds);
    push(di);
    r16[ax] = 0x0018;
    push(r16[ax]);
    r8[al] = 0x00;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ac0f();
    assert(cs == 0x081e);
    sp = bp;
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_855c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory[ds*16 + 0x14ed] == 0xff) {
            pc = 0x8580;
            break;
        }
        r16[ax] = 0x0040;
        es = r16[ax];
        r16[bx] = 0x0010;
        r8[al] = memory[ds*16 + 0x14ee];
        memory[es*16 + r16[bx]] = r8[al];
        r8[ah] = 0;
        r8[al] = memory[ds*16 + 0x14ed];
        interrupt(0x10);
        memory[ds*16 + 0x14ed] = 0xff;
    case 0x8580:
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_8692() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(memory16get(ds, 0x14e4));
    sub_86a4();
    memory16set(ds, 0x14e4, pop());
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
function sub_86a4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        sub_8a76();
        bp = pop();
        r8[al] = memory[ds*16 + 0x14e4];
        if (r8[al] != 0x02) {
            pc = 0x86ba;
            break;
        }
        r8[al] = 0x01;
        memory[ds*16 + 0x14e4] = r8[al];
        memory[ds*16 + 0x14e5] = 0x02;
    case 0x86ba:
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        r8[al] = memory[ds*16 + 0x14e6];
        r8[ah] = 0;
        if (r8[al] != 0xff) {
            pc = 0x86c8;
            break;
        }
        r8[ah] = r8[al];
    case 0x86c8:
        memory16set(es, di, r16[ax]);
        r8[ah] = 0;
        r8[al] = memory[ds*16 + 0x14e5];
        di = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        memory16set(es, di, r16[ax]);
        return;
    } while (1);
}
function sub_86d7() {
    r16[ax] = 0;
    memory[ds*16 + 0x14e4] = 0xff;
    memory[ds*16 + 0x14e5] = r8[al];
    memory[ds*16 + 0x14e6] = r8[al];
    memory[ds*16 + 0x14e7] = r8[al];
    memory[ds*16 + 0x14e8] = r8[al];
    memory16set(ds, 0x14e9, r16[ax]);
    memory16set(ds, 0x14eb, r16[ax]);
    memory[ds*16 + 0x14ed] = 0xff;
    memory[ds*16 + 0x14ee] = r8[al];
    cs = pop();
}
function sub_8a76() {
    memory[ds*16 + 0x14e4] = 0xff;
    memory[ds*16 + 0x14e6] = 0xff;
    memory[ds*16 + 0x14e5] = 0x00;
    sub_8aac();
    r8[bl] = memory[ds*16 + 0x14e6];
    if (r8[bl] == 0xff)
        return;
    r8[bh] = 0;
    r8[al] = memory[cs*16 + r16[bx] + 2162];
    memory[ds*16 + 0x14e4] = r8[al];
    r8[al] = memory[cs*16 + r16[bx] + 2174];
    memory[ds*16 + 0x14e5] = r8[al];
    r8[al] = memory[cs*16 + r16[bx] + 2186];
    memory[ds*16 + 0x14e7] = r8[al];
}
function sub_8aac() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x0f;
        interrupt(0x10);
        if (r8[al] == 0x07) {
            pc = 0x8ae5;
            break;
        }
        sub_8b8a();
        if (!flags.carry) {
            pc = 0x8abf;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x06;
        return;
    case 0x8abf:
        sub_8b13();
        if (!flags.carry) {
            pc = 0x8ac8;
            break;
        }
    case 0x8ac4:
        sub_8b31();
        return;
    case 0x8ac8:
        sub_8bd0();
        if (r16[ax] == 0) {
            pc = 0x8ad5;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x0a;
        return;
    case 0x8ad5:
        memory[ds*16 + 0x14e6] = 0x01;
        sub_8b69();
        if (!flags.carry) {
            pc = 0x8ae4;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x02;
    case 0x8ae4:
        return;
    case 0x8ae5:
        sub_8b13();
        if (flags.carry) {
            pc = 0x8ac4;
            break;
        }
        sub_8b9e();
        if (r8[al] == 0) {
            pc = 0x8af7;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x07;
        return;
    case 0x8af7:
        si = 0xb800;
        es = si;
        si = 0;
        r16[ax] = memory16get(es, si);
        r16[ax] = ~ax;
        memory16set(es, si, ~memory16get(es, si));
        if (r16[ax] != memory16get(es, si))
            return;
        memory[ds*16 + 0x14e6] = 0x01;
        return;
    } while (1);
}
function sub_8b13() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x1200;
        r8[bl] = 0x10;
        r8[bh] = 0xff;
        r8[cl] = 0x0f;
        interrupt(0x10);
        if (r8s[cl] >= signed8(0x0c)) {
            pc = 0x8b2f;
            break;
        }
        if (r8s[bh] > signed8(0x01)) {
            pc = 0x8b2f;
            break;
        }
        if (r8s[bl] > signed8(0x03)) {
            pc = 0x8b2f;
            break;
        }
        flags.carry = true;
        return;
    case 0x8b2f:
        flags.carry = false;
        return;
    } while (1);
}
function sub_8b31() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x14e6] = 0x04;
        if (r8[bh] == 0x01) {
            pc = 0x8b54;
            break;
        }
        sub_8b5a();
        if (flags.carry) {
            pc = 0x8b53;
            break;
        }
        if (r8[bl] == 0) {
            pc = 0x8b53;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x03;
        sub_8b69();
        if (!flags.carry) {
            pc = 0x8b53;
            break;
        }
        memory[ds*16 + 0x14e6] = 0x09;
    case 0x8b53:
        return;
    case 0x8b54:
        memory[ds*16 + 0x14e6] = 0x05;
        return;
    } while (1);
}
function sub_8b5a() {
    flags.carry = r8[cl] < 0x02;
    if (r8[cl] < 0x02)
        return;
    flags.carry = r8[cl] < 0x06;
    flags.carry = !flags.carry;
    if (!flags.carry)
        return;
    flags.carry = r8[cl] < 0x08;
}
function sub_8b69() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x1a00;
        interrupt(0x10);
        if (r8[al] != 0x1a) {
            pc = 0x8b88;
            break;
        }
        if (r8[bl] == 0x07) {
            pc = 0x8b86;
            break;
        }
        if (r8[bl] == 0x08) {
            pc = 0x8b86;
            break;
        }
        if (r8[bl] < 0x0b) {
            pc = 0x8b88;
            break;
        }
        if (r8[bl] > 0x0c) {
            pc = 0x8b88;
            break;
        }
    case 0x8b86:
        flags.carry = true;
        return;
    case 0x8b88:
        flags.carry = false;
        return;
    } while (1);
}
function sub_8b8a() {
    flags.carry = false;
    r8[al] = 0;
}
function sub_8b9e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ba;
        r8[bl] = 0;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x80;
        r8[ah] = r8[al];
        r16[cx] = 0x8000;
    case 0x8bab:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x80;
        if (r8[al] == r8[ah]) {
            pc = 0x8bb9;
            break;
        }
        r8[bl]++;
        if (r8[bl] >= 0x0a) {
            pc = 0x8bbe;
            break;
        }
    case 0x8bb9:
        if (--r16[cx]) {
            pc = 0x8bab;
            break;
        }
        r8[al] = 0;
        return;
    case 0x8bbe:
        r16[cx] = 0x8000;
    case 0x8bc1:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x30;
        if (r8[al] != 0x10) {
            pc = 0x8bcd;
            break;
        }
        if (--r16[cx]) {
            pc = 0x8bc1;
            break;
        }
        r8[al] = 0x02;
        return;
    case 0x8bcd:
        r8[al] = 0x01;
        return;
    } while (1);
}
function sub_8bd0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x06;
        r16[cx] = 0;
        r16[dx] = 0;
        r8[ah] = 0x30;
        interrupt(0x10);
        r16[ax] = r16[cx];
        r16[ax] |= r16[dx];
        if (!r16[ax]) {
            pc = 0x8bfd;
            break;
        }
        push(ds);
        ds = r16[cx];
        r16[bx] = r16[dx];
        r8[al] = memory[ds*16 + r16[bx] + 2];
        ds = pop();
        if (!r8[al]) {
            pc = 0x8bf1;
            break;
        }
        if (r8[al] != 0x02) {
            pc = 0x8bfd;
            break;
        }
    case 0x8bf1:
        r16[dx] = 0x0188;
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x04)) {
            pc = 0x8bfd;
            break;
        }
        r16[ax] = 0x0001;
        return;
    case 0x8bfd:
        r16[ax] = 0;
        return;
    } while (1);
}
function sub_8c00() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0;
    push(cs);
    cs = 0x0947;
    sub_971d();
    assert(cs == 0x08c0);
    r8[al] = 0x09;
    push(r16[ax]);
    di = 0x1570;
    push(ds);
    push(di);
    push(cs);
    cs = 0x08d0;
    sub_8d58();
    assert(cs == 0x08c0);
    r8[al] = 0x09;
    push(r16[ax]);
    r16[ax] = 0x006a;
    r16[dx] = cs;
    push(r16[dx]);
    push(r16[ax]);
    push(cs);
    cs = 0x08d0;
    sub_8d87();
    assert(cs == 0x08c0);
    memory[ds*16 + 0x0424] = 0x01;
    di = 0x14f0;
    push(ds);
    push(di);
    r16[ax] = 0x0080;
    push(r16[ax]);
    r8[al] = 0x00;
    push(r16[ax]);
    push(cs);
    cs = 0x0947;
    sub_ac0f();
    assert(cs == 0x08c0);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_8c40() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = 0;
        push(cs);
        cs = 0x0947;
        sub_971d();
        assert(cs == 0x08c0);
        if (memory[ds*16 + 0x0424] == 0x00) {
            pc = 0x8c66;
            break;
        }
        r8[al] = 0x09;
        push(r16[ax]);
        push(memory16get(ds, 0x1572));
        push(memory16get(ds, 0x1570));
        push(cs);
        cs = 0x08d0;
        sub_8d87();
        assert(cs == 0x08c0);
        memory[ds*16 + 0x0424] = 0x00;
    case 0x8c66:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function sub_8c6a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(ds);
        push(es);
        push(bp);
        bp = sp;
        sp -= 0x0001;
        r16[ax] = 0x0ac3;
        ds = r16[ax];
        r8[al] = in8(0x60);
        memory[ss*16 + bp - 1] = r8[al];
        r8[al] = in8(0x61);
        r8[al] |= 0x80;
        out8(0x61, r8[al]);
        r8[al] = in8(0x61);
        r8[al] &= 0x7f;
        out8(0x61, r8[al]);
        r8[al] = memory[ss*16 + bp - 1];
        r8[al] &= 0x80;
        if (r8[al]) {
            pc = 0x8ca5;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0;
        di = r16[ax];
        memory[ds*16 + di + 5360] = 0x01;
        pc = 0x8ceb;
        break;
    case 0x8ca5:
        if (memory[ss*16 + bp - 1] != 0xff) {
            pc = 0x8cbe;
            break;
        }
        di = 0x14f0;
        push(ds);
        push(di);
        r16[ax] = 0x0080;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        push(cs);
        cs = 0x0947;
        sub_ac0f();
        assert(cs == 0x08c0);
        pc = 0x8ceb;
        break;
    case 0x8cbe:
        if (memory[ss*16 + bp - 1] != 0xf0) {
            pc = 0x8cd7;
            break;
        }
        r8[al] = in8(0x60);
        memory[ss*16 + bp - 1] = r8[al];
        r8[al] = in8(0x61);
        r8[al] |= 0x80;
        out8(0x61, r8[al]);
        r8[al] = in8(0x61);
        r8[al] &= 0x7f;
        out8(0x61, r8[al]);
        pc = 0x8cdf;
        break;
    case 0x8cd7:
        r8[al] = memory[ss*16 + bp - 1];
        r8[al] &= 0x7f;
        memory[ss*16 + bp - 1] = r8[al];
    case 0x8cdf:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0;
        di = r16[ax];
        memory[ds*16 + di + 5360] = 0x00;
    case 0x8ceb:
        r8[al] = 0x20;
        out8(0x20, r8[al]);
        sp = bp;
        bp = pop();
        es = pop();
        ds = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        stop();
        return;
    } while (1);
}
function sub_8d00() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = 0x21;
    push(r16[ax]);
    di = memory16get(ss, bp + 6);
    es = memory16get(ss, bp + 6 + 2);
    push(es);
    push(di);
    push(cs);
    sub_8db2();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
function sub_8d15() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memory[ss*16 + bp - 19] = 0x2a;
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00();
    r16[ax] = memory16get(ss, bp - 16);
    di = memory16get(ss, bp + 18);
    es = memory16get(ss, bp + 18 + 2);
    memory16set(es, di, r16[ax]);
    r8[al] = memory[ss*16 + bp - 13];
    r8[ah] = 0;
    di = memory16get(ss, bp + 14);
    es = memory16get(ss, bp + 14 + 2);
    memory16set(es, di, r16[ax]);
    r8[al] = memory[ss*16 + bp - 14];
    r8[ah] = 0;
    di = memory16get(ss, bp + 10);
    es = memory16get(ss, bp + 10 + 2);
    memory16set(es, di, r16[ax]);
    r8[al] = memory[ss*16 + bp - 20];
    r8[ah] = 0;
    di = memory16get(ss, bp + 6);
    es = memory16get(ss, bp + 6 + 2);
    memory16set(es, di, r16[ax]);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 16;
}
function sub_8d58() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memory[ss*16 + bp - 19] = 0x35;
    r8[al] = memory[ss*16 + bp + 10];
    memory[ss*16 + bp - 20] = r8[al];
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00();
    r16[ax] = memory16get(ss, bp - 18);
    r16[dx] = memory16get(ss, bp - 4);
    di = memory16get(ss, bp + 6);
    es = memory16get(ss, bp + 6 + 2);
    memory16set(es, di, r16[ax]);
    memory16set(es, di + 2, r16[dx]);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
function sub_8d87() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    memory[ss*16 + bp - 19] = 0x25;
    r8[al] = memory[ss*16 + bp + 10];
    memory[ss*16 + bp - 20] = r8[al];
    r16[ax] = memory16get(ss, bp + 6);
    memory16set(ss, bp - 14, r16[ax]);
    r16[ax] = memory16get(ss, bp + 8);
    memory16set(ss, bp - 6, r16[ax]);
    di = bp - 0x14;
    push(ss);
    push(di);
    push(cs);
    sub_8d00();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
function sub_8db2() {
    push(0x7777);
    push(bp);
    push(ds);
    bp = sp;
    r8[al] = memory[ss*16 + bp + 12];
    var intval = r8[al];
    memory[cs*16 + 0x00dd] = r8[al];
    si = memory16get(ss, bp + 8);
    ds = memory16get(ss, bp + 8 + 2);
    flags.direction = false;
    lodsw_data_forward();
    push(r16[ax]);
    lodsw_data_forward();
    r16[bx] = r16[ax];
    lodsw_data_forward();
    r16[cx] = r16[ax];
    lodsw_data_forward();
    r16[dx] = r16[ax];
    lodsw_data_forward();
    bp = r16[ax];
    lodsw_data_forward();
    push(r16[ax]);
    lodsw_data_forward();
    di = r16[ax];
    lodsw_data_forward();
    push(r16[ax]);
    lodsw_data_forward();
    es = r16[ax];
    ds = pop();
    si = pop();
    r16[ax] = pop();
    interrupt(intval);
    r16[tx] = flags.carry | (flags.zero * 0x40) | (bp & 0x8000);
    push(r16[tx]);
    push(es);
    push(di);
    push(bp);
    bp = sp;
    di = memory16get(ss, bp + 16);
    es = memory16get(ss, bp + 16 + 2);
    flags.direction = false;
    stosw_data_forward();
    r16[ax] = r16[bx];
    stosw_data_forward();
    r16[ax] = r16[cx];
    stosw_data_forward();
    r16[ax] = r16[dx];
    stosw_data_forward();
    r16[ax] = pop();
    stosw_data_forward();
    r16[ax] = si;
    stosw_data_forward();
    r16[ax] = pop();
    stosw_data_forward();
    r16[ax] = ds;
    stosw_data_forward();
    r16[ax] = pop();
    stosw_data_forward();
    r16[ax] = pop();
    stosw_data_forward();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
function* sub_8e10() {
    push(0x7777);
    bp = sp;
    yield* sub_8e3e();
    di = 0x1594;
    push(ds);
    push(di);
    push(cs);
    sub_9189();
    di = 0x1594;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_a719();
    assert(cs == 0x08e1);
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    sub_9189();
    di = 0x1694;
    push(ds);
    push(di);
    push(cs);
    cs = 0x0947;
    sub_a71e();
    assert(cs == 0x08e1);
    sp = bp;
    assert(pop() == 0x7777);
    cs = pop();
}
function* sub_8e3e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x0f;
        sub_9463();
        if (r8[al] == 0x07) {
            pc = 0x8e51;
            break;
        }
        if (r8[al] <= 0x03) {
            pc = 0x8e51;
            break;
        }
        r16[ax] = 0x0003;
        sub_8ec9();
    case 0x8e51:
        sub_8f2b();
        r8[ah] = 0x08;
        r8[bh] = 0;
        sub_9463();
        r8[al] = r8[ah];
        r8[al] &= 0x7f;
        memory[ds*16 + 0x1591] = r8[al];
        memory[ds*16 + 0x1580] = r8[al];
        r16[ax] = 0;
        memory[ds*16 + 0x157b] = r8[al];
        memory[ds*16 + 0x1592] = r8[al];
        memory[ds*16 + 0x1593] = r8[al];
        r16[ax]++;
        memory[ds*16 + 0x157a] = r8[al];
        r16[ax] = 0x0040;
        es = r16[ax];
        di = 0x006c;
        r8[al] = memoryBiosGet(es, di);
    case 0x8e7f:
        yield* sync();
        if (r8[al] == memoryBiosGet(es, di)) {
            pc = 0x8e7f;
            break;
        }
        r8[al] = memoryBiosGet(es, di);
        r16[cx] = 0xffff;
        sub_9119();
        r16[ax] = 0x0037;
        r16[tx] = r16[cx];
        r16[cx] = r16[ax];
        r16[ax] = r16[tx];
        r16[ax] = ~ax;
        r16[dx] = 0;
        div16(r16[cx]);
        memory16set(ds, 0x158d, r16[ax]);
        r16[ax] = 0x351b;
        interrupt(0x21);
        memory16set(ds, 0x1585, r16[bx]);
        memory16set(ds, 0x1587, es);
        push(ds);
        push(cs);
        ds = pop();
        r16[dx] = 0x017a;
        r16[ax] = 0x251b;
        interrupt(0x21);
        ds = pop();
        r16[ax] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        memory16set(ds, 0x1589, r16[ax]);
        memory16set(ds, 0x158b, es);
        memory16set(ds, 0x17a8, 0x0163);
        memory16set(ds, 0x17aa, cs);
        return;
    } while (1);
}
function sub_8ec9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x0040;
        es = r16[dx];
        memoryBiosSet(es, 0x0087, memoryBiosGet(es, 0x0087) & 0xfe);
        if (r8[al] == 0x07) {
            pc = 0x8ede;
            break;
        }
        if (r8[al] < 0x04) {
            pc = 0x8ede;
            break;
        }
        r8[al] = 0x03;
    case 0x8ede:
        push(r16[ax]);
        r8[ah] = 0x00;
        sub_9463();
        r16[ax] = pop();
        if (!r8[ah])
            return;
        r16[ax] = 0x1112;
        r8[bl] = 0x00;
        sub_9463();
        r16[ax] = 0x1130;
        r8[bh] = 0x00;
        r8[dl] = 0x00;
        sub_9463();
        if (r8[dl] != 0x2a)
            return;
        memory[es*16 + 0x0087] = memory[es*16 + 0x0087] | 0x01;
        r16[ax] = 0x0100;
        r16[cx] = 0x0600;
        sub_9463();
        if (memory[es*16 + 0x0049] != 0x07) {
            pc = 0x8f23;
            break;
        }
        r16[dx] = memory16get(es, 0x0063);
        r8[al] = 0x14;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r8[al] = 0x07;
        out8(r16[dx], r8[al]);
    case 0x8f23:
        r8[ah] = 0x12;
        r8[bl] = 0x20;
        sub_9463();
        return;
    } while (1);
}
function sub_8f2b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x0f;
        sub_9463();
        push(r16[ax]);
        r16[ax] = 0x1130;
        r8[bh] = 0x00;
        r8[dl] = 0x00;
        sub_9463();
        r16[ax] = pop();
        r8[cl] = 0x00;
        if (r8[dl]) {
            pc = 0x8f4a;
            break;
        }
        r8[dl] = 0x18;
        if (r8[al] > 0x03) {
            pc = 0x8f4a;
            break;
        }
        r8[cl] = 0x01;
    case 0x8f4a:
        r8[dh] = r8[dl];
        r8[dl] = r8[ah];
        r8[dl]--;
        r8[ah] = 0x00;
        if (r8[dh] <= 0x18) {
            pc = 0x8f59;
            break;
        }
        r8[ah] = 0x01;
    case 0x8f59:
        memory16set(ds, 0x157e, r16[ax]);
        memory16set(ds, 0x158f, r16[dx]);
        memory[ds*16 + 0x157d] = r8[cl];
        memory[ds*16 + 0x157c] = 0x01;
        r16[ax] = 0;
        memory16set(ds, 0x1581, r16[ax]);
        memory16set(ds, 0x1583, r16[dx]);
        return;
    } while (1);
}
function sub_8f8a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x0ac3;
        ds = r16[ax];
        if (memory[ds*16 + 0x157a] == 0x00) {
            pc = 0x8f9d;
            break;
        }
        memory[ds*16 + 0x1593] = 0x01;
    case 0x8f9d:
        ds = pop();
        r16[ax] = pop();
        stop();
        return;
    } while (1);
}
function sub_8fa0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x1593] != 0x00)
            {
            assert(0);
            pc = 0x8fa8;
            break;
        }
        return;
    case 0x8fa8:
        memory[ds*16 + 0x1593] = 0x00;
    case 0x8fad:
        r8[ah] = 0x01;
        interrupt(0x16);
        if (flags.zero) {
            pc = 0x8fb9;
            break;
        }
        r8[ah] = 0x00;
        interrupt(0x16);
        pc = 0x8fad;
        break;
    case 0x8fb9:
        r8[al] = 0x5e;
        sub_92d6();
        r8[al] = 0x43;
        sub_92d6();
        sub_92cf();
        interrupt(0x23);
        r16[bx] = sp;
        r16[ax] = memory16get(ss, r16[bx] + 4);
        sub_8ec9();
        sub_8f2b();
        r8[al] = memory[ds*16 + 0x1591];
        memory[ds*16 + 0x1580] = r8[al];
        stop(/*unk call conv*/);
        sp += 2;
        return;
    } while (1);
}
function sub_8fc8() {
    push(0x7777);
    r16[bx] = sp;
    r16[ax] = memory16get(ss, r16[bx] + 4);
    sub_8ec9();
    sub_8f2b();
    r8[al] = memory[ds*16 + 0x1591];
    memory[ds*16 + 0x1580] = r8[al];
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
function sub_8fdd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r8[dl] = memory[ss*16 + r16[bx] + 10];
        r8[dh] = memory[ss*16 + r16[bx] + 8];
        r8[cl] = memory[ss*16 + r16[bx] + 6];
        r8[ch] = memory[ss*16 + r16[bx] + 4];
        if (r8[dl] > r8[cl]) {
            pc = 0x901a;
            break;
        }
        if (r8[dh] > r8[ch]) {
            pc = 0x901a;
            break;
        }
        r8[dl]--;
        if (r8s[dl] < 0) {
            pc = 0x901a;
            break;
        }
        r8[dh]--;
        if (r8s[dh] < 0) {
            pc = 0x901a;
            break;
        }
        r8[cl]--;
        if (r8[cl] > memory[ds*16 + 0x158f]) {
            pc = 0x901a;
            break;
        }
        r8[ch]--;
        if (r8[ch] > memory[ds*16 + 0x1590]) {
            pc = 0x901a;
            break;
        }
        memory16set(ds, 0x1581, r16[dx]);
        memory16set(ds, 0x1583, r16[cx]);
        sub_9357();
    case 0x901a:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 8;
        return;
    } while (1);
}
function sub_901d() {
    r16[ax] = 0x0600;
    r8[bh] = memory[ds*16 + 0x1580];
    r16[cx] = memory16get(ds, 0x1581);
    r16[dx] = memory16get(ds, 0x1583);
    sub_9463();
    r16[dx] = memory16get(ds, 0x1581);
    sub_9357();
    cs = pop();
}
function sub_9070() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r8[dl] = memory[ss*16 + r16[bx] + 6];
        r8[dh] = memory[ss*16 + r16[bx] + 4];
        r8[dl]--;
        flags.carry = (r8[dl] + memory[ds*16 + 0x1581]) >= 0x100;
        r8[dl] += memory[ds*16 + 0x1581];
        if (flags.carry) {
            pc = 0x9099;
            break;
        }
        if (r8[dl] > memory[ds*16 + 0x1583]) {
            pc = 0x9099;
            break;
        }
        r8[dh]--;
        flags.carry = (r8[dh] + memory[ds*16 + 0x1582]) >= 0x100;
        r8[dh] += memory[ds*16 + 0x1582];
        if (flags.carry) {
            pc = 0x9099;
            break;
        }
        if (r8[dh] > memory[ds*16 + 0x1584]) {
            pc = 0x9099;
            break;
        }
        sub_9357();
    case 0x9099:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_90b4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r8[al] = memory[ss*16 + r16[bx] + 4];
        if (!(r8[al] & 0xf0)) {
            pc = 0x90c2;
            break;
        }
        r8[al] &= 0x0f;
        r8[al] |= 0x80;
    case 0x90c2:
        memory[ds*16 + 0x1580] = memory[ds*16 + 0x1580] & 0x70;
        memory[ds*16 + 0x1580] = memory[ds*16 + 0x1580] | r8[al];
        assert(pop() == 0x7777);
        cs = pop();
        sp += 2;
        return;
    } while (1);
}
function sub_90ce() {
    push(0x7777);
    r16[bx] = sp;
    r8[al] = memory[ss*16 + r16[bx] + 4];
    r8[al] &= 0x07;
    r8[cl] = 0x04;
    r8[al] <<= r8[cl];
    memory[ds*16 + 0x1580] = memory[ds*16 + 0x1580] & 0x8f;
    memory[ds*16 + 0x1580] = memory[ds*16 + 0x1580] | r8[al];
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
function sub_90f9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r16[dx] = memory16get(ss, r16[bx] + 4);
        if (!r16[dx]) {
            pc = 0x9116;
            break;
        }
        di = 0;
        es = di;
        r8[al] = memoryBiosGet(es, di);
        r16[bx] = memory16get(ds, 0x158d);
    case 0x910e:
        r16[cx] = r16[bx];
        sub_9119();
        r16[dx]--;
        if (r16[dx] != 0) {
            pc = 0x910e;
            break;
        }
    case 0x9116:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 2;
        return;
    } while (1);
}
function sub_9119() {
    var pc = 0;
    do switch (pc) {
    case 0:
        return;
    case 0x9119:
        if (r8[al] != memoryBiosGet(es, di))
            return;
        if (--r16[cx]) {
            pc = 0x9119;
            break;
        }
        return;
    } while (1);
}
function sub_9121() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r16[bx] = memory16get(ss, r16[bx] + 4);
        r16[ax] = 0x34dd;
        r16[dx] = 0x0012;
        if (r16[dx] >= r16[bx]) {
            pc = 0x914b;
            break;
        }
        div16(r16[bx]);
        r16[bx] = r16[ax];
        r8[al] = in8(0x61);
        if (r8[al] & 0x03) {
            pc = 0x9143;
            break;
        }
        r8[al] |= 0x03;
        out8(0x61, r8[al]);
        r8[al] = 0xb6;
        out8(0x43, r8[al]);
    case 0x9143:
        r8[al] = r8[bl];
        out8(0x42, r8[al]);
        r8[al] = r8[bh];
        out8(0x42, r8[al]);
    case 0x914b:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 2;
        return;
    } while (1);
}
function sub_914e() {
    r8[al] = in8(0x61);
    r8[al] &= 0xfc;
    out8(0x61, r8[al]);
    cs = pop();
}
function sub_9155() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x1592] != 0x00) {
            pc = 0x9164;
            break;
        }
        r8[ah] = 0x01;
        interrupt(0x16);
        r8[al] = 0x00;
        if (flags.zero) {
            pc = 0x9166;
            break;
        }
    case 0x9164:
        r8[al] = 0x01;
    case 0x9166:
        cs = pop();
        return;
    } while (1);
}
function sub_9167() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x1592];
        memory[ds*16 + 0x1592] = 0x00;
        if (r8[al]) {
            pc = 0x9185;
            break;
        }
        r8[ah] = 0;
        interrupt(0x16);
        if (r8[al]) {
            pc = 0x9185;
            break;
        }
        memory[ds*16 + 0x1592] = r8[ah];
        if (r8[ah]) {
            pc = 0x9185;
            break;
        }
        r8[al] = 0x03;
    case 0x9185:
        sub_8fa0();
        cs = pop();
        return;
    } while (1);
}
function sub_9189() {
    push(0x7777);
    r16[bx] = sp;
    push(ds);
    di = memory16get(ss, r16[bx] + 4);
    ds = memory16get(ss, r16[bx] + 4 + 2);
    memory16set(ds, di + 2, 0xd7b0);
    memory16set(ds, di + 4, 0x0080);
    r16[ax] = di + 0x80;
    memory16set(ds, di + 12, r16[ax]);
    memory16set(ds, di + 14, ds);
    memory16set(ds, di + 16, 0x03a4);
    memory16set(ds, di + 18, cs);
    memory[ds*16 + di + 48] = 0x00;
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 4;
}
function sub_91b4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        push(ds);
        di = memory16get(ss, r16[bx] + 4);
        ds = memory16get(ss, r16[bx] + 4 + 2);
        r16[ax] = 0x03dc;
        r16[bx] = 0x04ba;
        r16[cx] = r16[bx];
        if (memory16get(ds, di + 2) == 0xd7b1) {
            pc = 0x91d4;
            break;
        }
        memory16set(ds, di + 2, 0xd7b2);
        r16[ax] = 0x0489;
        r16[bx] = r16[ax];
    case 0x91d4:
        memory16set(ds, di + 20, r16[ax]);
        memory16set(ds, di + 22, cs);
        memory16set(ds, di + 24, r16[bx]);
        memory16set(ds, di + 26, cs);
        memory16set(ds, di + 28, r16[cx]);
        memory16set(ds, di + 30, cs);
        r16[ax] = 0;
        ds = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_9299() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        r16[cx] = memory16get(es, di + 8);
        memory16set(es, di + 8, memory16get(es, di + 8) - r16[cx]);
        if (r16[cx] == 0) {
            pc = 0x92c2;
            break;
        }
        r16[tx] = di;
        di = memory16get(es, r16[tx] + 12);
        es = memory16get(es, r16[tx] + 12 + 2);
        if (memory[ds*16 + 0x157c] != 0x00) {
            pc = 0x92bf;
            break;
        }
    case 0x92b4:
        r8[al] = memory[es*16 + di];
        sub_92d6();
        di++;
        if (--r16[cx]) {
            pc = 0x92b4;
            break;
        }
        pc = 0x92c2;
        break;
    case 0x92bf:
        sub_935e();
    case 0x92c2:
        sub_8fa0();
        r16[ax] = 0;
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_92cf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x0d;
        sub_92d6();
        r8[al] = 0x0a;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(es);
        push(r16[ax]);
        sub_9350();
        r16[ax] = pop();
        if (r8[al] == 0x07) {
            pc = 0x930d;
            break;
        }
        if (r8[al] == 0x08) {
            pc = 0x9314;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0x931e;
            break;
        }
        if (r8[al] == 0x0a) {
            pc = 0x9324;
            break;
        }
        r8[ah] = 0x09;
        r8[bl] = memory[ds*16 + 0x1580];
        r8[bh] = 0;
        r16[cx] = 0x0001;
        push(r16[dx]);
        sub_9463();
        r16[dx] = pop();
        r8[dl]++;
        if (r8[dl] <= memory[ds*16 + 0x1583]) {
            pc = 0x9327;
            break;
        }
        r8[dl] = memory[ds*16 + 0x1581];
        pc = 0x9324;
        break;
    case 0x930d:
        r8[ah] = 0x0e;
        sub_9463();
        pc = 0x9327;
        break;
    case 0x9314:
        if (r8[dl] == memory[ds*16 + 0x1581]) {
            pc = 0x9327;
            break;
        }
        r8[dl]--;
        pc = 0x9327;
        break;
    case 0x931e:
        r8[dl] = memory[ds*16 + 0x1581];
        pc = 0x9327;
        break;
    case 0x9324:
        sub_932f();
    case 0x9327:
        sub_9357();
        es = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function sub_92d6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(es);
        push(r16[ax]);
        sub_9350();
        r16[ax] = pop();
        if (r8[al] == 0x07) {
            pc = 0x930d;
            break;
        }
        if (r8[al] == 0x08) {
            pc = 0x9314;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0x931e;
            break;
        }
        if (r8[al] == 0x0a) {
            pc = 0x9324;
            break;
        }
        r8[ah] = 0x09;
        r8[bl] = memory[ds*16 + 0x1580];
        r8[bh] = 0;
        r16[cx] = 0x0001;
        push(r16[dx]);
        sub_9463();
        r16[dx] = pop();
        r8[dl]++;
        if (r8[dl] <= memory[ds*16 + 0x1583]) {
            pc = 0x9327;
            break;
        }
        r8[dl] = memory[ds*16 + 0x1581];
        pc = 0x9324;
        break;
    case 0x930d:
        r8[ah] = 0x0e;
        sub_9463();
        pc = 0x9327;
        break;
    case 0x9314:
        if (r8[dl] == memory[ds*16 + 0x1581]) {
            pc = 0x9327;
            break;
        }
        r8[dl]--;
        pc = 0x9327;
        break;
    case 0x931e:
        r8[dl] = memory[ds*16 + 0x1581];
        pc = 0x9327;
        break;
    case 0x9324:
        sub_932f();
    case 0x9327:
        sub_9357();
        es = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function sub_932f() {
    r8[dh]++;
    if (r8[dh] <= memory[ds*16 + 0x1584])
        return;
    r8[dh]--;
    push(r16[cx]);
    push(r16[dx]);
    r16[ax] = 0x0601;
    r8[bh] = memory[ds*16 + 0x1580];
    r16[cx] = memory16get(ds, 0x1581);
    r16[dx] = memory16get(ds, 0x1583);
    sub_9463();
    r16[dx] = pop();
    r16[cx] = pop();
}
function sub_9350() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x03;
        r8[bh] = 0;
        pc = 0x9463;
        break;
    case 0x9463:
        push(si);
        push(di);
        push(bp);
        push(es);
        interrupt(0x10);
        es = pop();
        bp = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function sub_9357() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x02;
        r8[bh] = 0;
        pc = 0x9463;
        break;
    case 0x9463:
        push(si);
        push(di);
        push(bp);
        push(es);
        interrupt(0x10);
        es = pop();
        bp = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function sub_935e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0040;
        ds = r16[ax];
        r16[dx] = memoryBiosGet16(ds, 0x0050);
        ds = pop();
        r16[bx] = r16[dx];
        si = di;
    case 0x936d:
        r8[al] = memory[es*16 + di];
        if (r8[al] == 0x07) {
            pc = 0x9395;
            break;
        }
        if (r8[al] == 0x08) {
            pc = 0x93a4;
            break;
        }
        if (r8[al] == 0x0a) {
            pc = 0x93b1;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0x93b9;
            break;
        }
        di++;
        r8[dl]++;
        if (r8[dl] <= memory[ds*16 + 0x1583]) {
            pc = 0x93c5;
            break;
        }
        sub_93fb();
        sub_932f();
        r8[dl] = memory[ds*16 + 0x1581];
        pc = 0x93c1;
        break;
    case 0x9395:
        sub_93fb();
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = 0x0e07;
        sub_9463();
        r16[dx] = pop();
        r16[cx] = pop();
        pc = 0x93c0;
        break;
    case 0x93a4:
        sub_93fb();
        if (r8[dl] == memory[ds*16 + 0x1581]) {
            pc = 0x93c0;
            break;
        }
        r8[dl]--;
        pc = 0x93c0;
        break;
    case 0x93b1:
        sub_93fb();
        sub_932f();
        pc = 0x93c0;
        break;
    case 0x93b9:
        sub_93fb();
        r8[dl] = memory[ds*16 + 0x1581];
    case 0x93c0:
        di++;
    case 0x93c1:
        si = di;
        r16[bx] = r16[dx];
    case 0x93c5:
        if (--r16[cx]) {
            pc = 0x936d;
            break;
        }
        sub_93fb();
        push(ds);
        r16[ax] = 0x0040;
        ds = r16[ax];
        memoryBiosSet16(ds, 0x0050, r16[dx]);
        r8[al] = r8[dh];
        mul8(memoryBiosGet(ds, 0x004a));
        r8[dh] = 0;
        r16[ax] += r16[dx];
        r16[cx] = r16[ax];
        r16[dx] = memoryBiosGet16(ds, 0x0063);
        r8[al] = 0x0e;
        out8(r16[dx], r8[al]);
        r8[al] = r8[ch];
        r16[dx]++;
        out8(r16[dx], r8[al]);
        r16[dx]--;
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        r8[al] = r8[cl];
        r16[dx]++;
        out8(r16[dx], r8[al]);
        ds = pop();
        return;
    } while (1);
}
function sub_93fb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (si == di)
            return;
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(ds);
        push(es);
        r16[cx] = di;
        r16[cx] -= si;
        r8[dl] = memory[ds*16 + 0x157d];
        r8[dh] = memory[ds*16 + 0x1580];
        r16[ax] = 0x0040;
        ds = r16[ax];
        r8[al] = r8[bh];
        mul8(memoryBiosGet(ds, 0x004a));
        r8[bh] = 0;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        di = r16[ax];
        r16[bx] = r16[dx];
        r16[dx] = memoryBiosGet16(ds, 0x0063);
        r16[dx] += 0x0006;
        r16[ax] = 0xb800;
        if (memoryBiosGet(ds, 0x0049) != 0x07) {
            pc = 0x9438;
            break;
        }
        r8[ah] = 0xb0;
    case 0x9438:
        push(es);
        ds = pop();
        es = r16[ax];
        flags.direction = false;
        if (!r8[bl]) {
            pc = 0x9457;
            break;
        }
    case 0x9441:
        lodsb_data_forward();
        r8[bl] = r8[al];
    case 0x9444:
        r8[al] = in8(r16[dx]);
        if (r8[al] & 0x01) {
            pc = 0x9444;
            break;
        }
        flags.interrupts = false;
    case 0x944a:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x01)) {
            pc = 0x944a;
            break;
        }
        r16[ax] = r16[bx];
        stosw_data_forward();
        flags.interrupts = true;
        if (--r16[cx]) {
            pc = 0x9441;
            break;
        }
        pc = 0x945d;
        break;
    case 0x9457:
        r8[ah] = r8[bh];
    case 0x9459:
        lodsb_data_forward();
        stosw_video_forward();
        if (--r16[cx]) {
            pc = 0x9459;
            break;
        }
    case 0x945d:
        es = pop();
        ds = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function sub_9463() {
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
function sub_9470() {
    push(0x7777);
    r16[dx] = 0x0ac3;
    ds = r16[dx];
    memory16set(ds, 0x1794, es);
    r16[ax] = sp;
    r16[ax] += 0x0013;
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[dx] = ss;
    r16[ax] += r16[dx];
    memory16set(ds, 0x1798, r16[ax]);
    memory16set(ds, 0x179c, r16[ax]);
    r16[ax] = memoryPsp16get(es, 0x0002);
    r16[ax] -= 0x1000;
    memory16set(ds, 0x17a0, r16[ax]);
    memory16set(ds, 0x17a4, 0x00dd);
    memory16set(ds, 0x17a6, cs);
    memory16set(ds, 0x17a8, 0x00e2);
    memory16set(ds, 0x17aa, cs);
    memory[ds*16 + 0x17ca] = 0x02;
    r16[ax] = 0;
    memory16set(ds, 0x1796, r16[ax]);
    memory16set(ds, 0x179a, r16[ax]);
    memory16set(ds, 0x179e, r16[ax]);
    memory16set(ds, 0x17a2, r16[ax]);
    memory16set(ds, 0x17b2, r16[ax]);
    memory16set(ds, 0x17b4, r16[ax]);
    memory16set(ds, 0x17cb, r16[ax]);
    r16[ax] = 0x3500;
    interrupt(0x21);
    memory16set(ds, 0x17b6, r16[bx]);
    memory16set(ds, 0x17b8, es);
    r16[ax] = 0x3502;
    interrupt(0x21);
    memory16set(ds, 0x17ba, r16[bx]);
    memory16set(ds, 0x17bc, es);
    r16[ax] = 0x3523;
    interrupt(0x21);
    memory16set(ds, 0x17be, r16[bx]);
    memory16set(ds, 0x17c0, es);
    r16[ax] = 0x3524;
    interrupt(0x21);
    memory16set(ds, 0x17c2, r16[bx]);
    memory16set(ds, 0x17c4, es);
    r16[ax] = 0x3575;
    interrupt(0x21);
    memory16set(ds, 0x17c6, r16[bx]);
    memory16set(ds, 0x17c8, es);
    push(ds);
    push(cs);
    ds = pop();
    r16[dx] = 0x01e9;
    r16[ax] = 0x2500;
    interrupt(0x21);
    r16[dx] = 0x01f0;
    r16[ax] = 0x2523;
    interrupt(0x21);
    r16[dx] = 0x01bf;
    r16[ax] = 0x2524;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0x1594;
    push(ds);
    push(r16[ax]);
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x00dc;
    push(cs);
    push(r16[ax]);
    push(cs);
    sub_a6a9();
    push(cs);
    sub_a719();
    r16[ax] = 0x1694;
    push(ds);
    push(r16[ax]);
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x00dc;
    push(cs);
    push(r16[ax]);
    push(cs);
    sub_a6a9();
    push(cs);
    sub_a71e();
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_962f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupts = true;
        sp += 0x0006;
        r16[ax] = pop();
        di &= 0x001f;
        di += 0x0096;
        if (r8[ah] >= 0x39) {
            pc = 0x9644;
            break;
        }
        di = 0xffff;
    case 0x9644:
        push(di);
        r8[ah] = 0x54;
        interrupt(0x21);
        bp = sp;
        memory[ss*16 + bp + 22] = memory[ss*16 + bp + 22] | 0x01;
        r16[ax] = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        r16[dx] = pop();
        si = pop();
        di = pop();
        bp = pop();
        ds = pop();
        es = pop();
        stop();
        return;
    } while (1);
}
function sub_9660() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x00ff;
        r16[cx] = 0;
        r16[bx] = 0;
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
        return;
    } while (1);
}
function sub_9663() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0;
        r16[bx] = 0;
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
        return;
    } while (1);
}
function sub_971d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0x971d;
        break;
    case 0x965c:
        stop(/*override stack*/);
        r16[cx] = pop();
        r16[bx] = pop();
        pc = 0x9667;
        break;
    case 0x9667:
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        assert(pop() == 0x7777);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
    case 0x971d:
        si = sp;
        r16[tx] = si;
        si -= r16[ax];
        if (r16[tx] < r16[ax]) {
            pc = 0x972a;
            break;
        }
        if (si < 0x0200) {
            pc = 0x972a;
            break;
        }
        assert(pop() == 0x7777);
        cs = pop();
        return;
    case 0x972a:
        r16[ax] = 0x00ca;
        pc = 0x965c;
        break;
        return;
    } while (1);
}
function sub_9730() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0x9730;
        break;
    case 0x965c:
        stop(/*override stack*/);
        r16[cx] = pop();
        r16[bx] = pop();
        pc = 0x9667;
        break;
    case 0x9667:
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        assert(pop() == 0x7777);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
    case 0x9730:
        push(bp);
        bp = sp;
    case 0x9733:
        r16[ax] = memory16get(ss, bp + 6);
        sub_9844();
        if (!flags.carry) {
            pc = 0x974d;
            break;
        }
        push(memory16get(ss, bp + 6));
        push(cs);
        cs = memory16get(ds, 0x17a4 + 2);
        callIndirect(memory16get(ds, 0x17a4 + 2), memory16get(ds, 0x17a4));
        assert(cs == 0x0947);
        if (!r16[ax]) {
            pc = 0x975b;
            break;
        }
        r16[ax]--;
        if (r16[ax] != 0) {
            pc = 0x9733;
            break;
        }
        r16[cx] = 0;
        r16[bx] = 0;
    case 0x974d:
        di = memory16get(ss, bp + 8);
        es = memory16get(ss, bp + 8 + 2);
        memory16set(es, di, r16[cx]);
        memory16set(es, di + 2, r16[bx]);
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 6;
        return;
    case 0x975b:
        bp = pop();
        r16[ax] = 0x00cb;
        pc = 0x965c;
        break;
        return;
    } while (1);
}
function sub_97f7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        sub_99cc();
        r16[ax] = si;
        r16[dx] = di;
        di = memory16get(ds, 0x179e);
        es = memory16get(ds, 0x179e + 2);
        r16[dx] -= memory16get(ds, 0x179c);
        flags.carry = r16[ax] < memory16get(ds, 0x179a);
        r16[ax] -= memory16get(ds, 0x179a);
        if (!flags.carry) {
            pc = 0x983c;
            break;
        }
        r16[ax] += 0x0010;
        r16[dx]--;
        pc = 0x983c;
        break;
    case 0x9812:
        r16[bx] = memory16get(es, di + 6);
        r16[bx] -= memory16get(es, di + 2);
        if (r16[bx] < r16[dx]) {
            pc = 0x9839;
            break;
        }
        r16[cx] = memory16get(es, di + 4);
        flags.carry = r16[cx] < memory16get(es, di);
        r16[cx] -= memory16get(es, di);
        if (!flags.carry) {
            pc = 0x982b;
            break;
        }
        r16[cx] += 0x0010;
        r16[bx]--;
    case 0x982b:
        if (r16[bx] > r16[dx]) {
            pc = 0x9835;
            break;
        }
        if (r16[bx] < r16[dx]) {
            pc = 0x9839;
            break;
        }
        if (r16[cx] < r16[ax]) {
            pc = 0x9839;
            break;
        }
    case 0x9835:
        r16[ax] = r16[cx];
        r16[dx] = r16[bx];
    case 0x9839:
        di += 0x0008;
    case 0x983c:
        if (di) {
            pc = 0x9812;
            break;
        }
        sub_9a24();
        cs = pop();
        return;
    } while (1);
}
function sub_9844() {
    var pc = 0;
    do switch (pc) {
    case 0:
        sub_9a16();
        di = memory16get(ds, 0x179e);
        es = memory16get(ds, 0x179e + 2);
        pc = 0x985c;
        break;
    case 0x984d:
        r16[bx] = memory16get(es, di + 6);
        r16[bx] -= memory16get(es, di + 2);
        if (r16[bx] >= r16[dx]) {
            pc = 0x989d;
            break;
        }
    case 0x9859:
        di += 0x0008;
    case 0x985c:
        if (di) {
            pc = 0x984d;
            break;
        }
        sub_99cc();
        r16[cx] = si;
        r16[bx] = di;
        r16[bx] -= memory16get(ds, 0x179c);
        flags.carry = r16[cx] < memory16get(ds, 0x179a);
        r16[cx] -= memory16get(ds, 0x179a);
        if (!flags.carry) {
            pc = 0x9875;
            break;
        }
        r16[cx] += 0x0010;
        r16[bx]--;
    case 0x9875:
        flags.carry = r16[bx] < r16[dx];
        if (r16[bx] > r16[dx]) {
            pc = 0x987f;
            break;
        }
        if (r16[bx] < r16[dx]) {
            pc = 0x989c;
            break;
        }
        flags.carry = r16[cx] < r16[ax];
        if (r16[cx] < r16[ax]) {
            pc = 0x989c;
            break;
        }
    case 0x987f:
        r16[cx] = memory16get(ds, 0x179a);
        r16[bx] = memory16get(ds, 0x179c);
        r16[dx] += r16[bx];
        r16[ax] += r16[cx];
        if (r16[ax] < 0x0010) {
            pc = 0x9894;
            break;
        }
        r16[ax] -= 0x0010;
        r16[dx]++;
    case 0x9894:
        memory16set(ds, 0x179a, r16[ax]);
        memory16set(ds, 0x179c, r16[dx]);
        flags.carry = false;
    case 0x989c:
        return;
    case 0x989d:
        r16[cx] = memory16get(es, di + 4);
        flags.carry = r16[cx] < memory16get(es, di);
        r16[cx] -= memory16get(es, di);
        if (!flags.carry) {
            pc = 0x98aa;
            break;
        }
        r16[cx] += 0x0010;
        r16[bx]--;
    case 0x98aa:
        if (r16[bx] > r16[dx]) {
            pc = 0x98b4;
            break;
        }
        if (r16[bx] < r16[dx]) {
            pc = 0x9859;
            break;
        }
        if (r16[cx] < r16[ax]) {
            pc = 0x9859;
            break;
        }
    case 0x98b4:
        r16[cx] = memory16get(es, di);
        r16[bx] = memory16get(es, di + 2);
        r16[dx] += r16[bx];
        r16[ax] += r16[cx];
        if (r16[ax] < 0x0010) {
            pc = 0x98c8;
            break;
        }
        r16[ax] -= 0x0010;
        r16[dx]++;
    case 0x98c8:
        memory16set(es, di, r16[ax]);
        memory16set(es, di + 2, r16[dx]);
        if (r16[dx] != memory16get(es, di + 6)) {
            pc = 0x98de;
            break;
        }
        if (r16[ax] != memory16get(es, di + 4)) {
            pc = 0x98de;
            break;
        }
        sub_99b7();
    case 0x98de:
        flags.carry = false;
        return;
    } while (1);
}
function sub_99b7() {
    si = memory16get(ds, 0x179e);
    flags.direction = false;
    movsw_data_data_forward();
    movsw_data_data_forward();
    movsw_data_data_forward();
    movsw_data_data_forward();
    di -= 0x0008;
    memory16set(ds, 0x179e, si);
}
function sub_99cc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = memory16get(ds, 0x179e);
        if (di) {
            pc = 0x99e5;
            break;
        }
        di -= memory16get(ds, 0x17a2);
        if (di != 0) {
            pc = 0x99ed;
            break;
        }
        si = 0;
        di = memory16get(ds, 0x17a0);
        di += 0x1000;
        return;
    case 0x99e5:
        flags.carry = di < memory16get(ds, 0x17a2);
        di -= memory16get(ds, 0x17a2);
        if (!flags.carry) {
            pc = 0x99ed;
            break;
        }
        di = 0;
    case 0x99ed:
        si = di;
        si &= 0x000f;
        di >>= 1;
        di >>= 1;
        di >>= 1;
        di >>= 1;
        di += memory16get(ds, 0x17a0);
        if (di > memory16get(ds, 0x179c))
            return;
        if (di < memory16get(ds, 0x179c)) {
            pc = 0x9a0d;
            break;
        }
        if (si >= memory16get(ds, 0x179a))
            return;
    case 0x9a0d:
        si = memory16get(ds, 0x179a);
        di = memory16get(ds, 0x179c);
        return;
    } while (1);
}
function sub_9a16() {
    r16[dx] = r16[ax];
    r16[ax] &= 0x000f;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
}
function sub_9a24() {
    r8[cl] = 0x04;
    r16[dx] = rol16(r16[dx], r8[cl]);
    r16[cx] = r16[dx];
    r16[cx] &= 0xfff0;
    r16[dx] &= 0x000f;
    r16[ax] |= r16[cx];
}
function sub_9a4f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        flags.direction = false;
        r16[bx] = sp;
        r16[dx] = ds;
        si = memory16get(ss, r16[bx] + 10);
        ds = memory16get(ss, r16[bx] + 10 + 2);
        di = memory16get(ss, r16[bx] + 6);
        es = memory16get(ss, r16[bx] + 6 + 2);
        r16[cx] = memory16get(ss, r16[bx] + 4);
        lodsb_data_forward();
        if (r8[al] <= r8[cl]) {
            pc = 0x9a67;
            break;
        }
        r8[al] = r8[cl];
    case 0x9a67:
        stosb_data_forward();
        r8[cl] = r8[al];
        r8[ch] = 0;
        rep_movsb_data_data_forward();
        ds = r16[dx];
        assert(pop() == 0x7777);
        cs = pop();
        sp += 10;
        return;
    } while (1);
}
function sub_9ac2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        flags.direction = false;
        r16[bx] = sp;
        r16[dx] = ds;
        di = memory16get(ss, r16[bx] + 8);
        es = memory16get(ss, r16[bx] + 8 + 2);
        si = memory16get(ss, r16[bx] + 4);
        ds = memory16get(ss, r16[bx] + 4 + 2);
        r8[cl] = memory[es*16 + di];
        r8[ch] = 0;
        lodsb_data_forward();
        flags.carry = (memory[es*16 + di] + r8[al]) >= 0x100;
        memory[es*16 + di] += r8[al];
        if (!flags.carry) {
            pc = 0x9ae2;
            break;
        }
        memory[es*16 + di] = 0xff;
        r8[al] = r8[cl];
        r8[al] = ~al;
    case 0x9ae2:
        di += r16[cx];
        di++;
        r8[cl] = r8[al];
        rep_movsb_data_data_forward();
        ds = r16[dx];
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_9b25() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        flags.direction = false;
        r16[bx] = sp;
        r16[dx] = ds;
        si = memory16get(ss, r16[bx] + 8);
        ds = memory16get(ss, r16[bx] + 8 + 2);
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        lodsb_data_forward();
        r8[ah] = memory[es*16 + di];
        di++;
        r8[cl] = r8[al];
        if (r8[cl] <= r8[ah]) {
            pc = 0x9b3f;
            break;
        }
        r8[cl] = r8[ah];
    case 0x9b3f:
        flags.zero = !r8[cl];
        if (!r8[cl]) {
            pc = 0x9b49;
            break;
        }
        r8[ch] = 0;
        repe_cmpsb_data_data_forward();
        if (!flags.zero) {
            pc = 0x9b4b;
            break;
        }
    case 0x9b49:
        flags.zero = r8[al] == r8[ah];
    case 0x9b4b:
        ds = r16[dx];
        assert(pop() == 0x7777);
        cs = pop();
        sp += 8;
        return;
    } while (1);
}
function sub_9b50() {
    push(0x7777);
    flags.direction = false;
    r16[bx] = sp;
    di = memory16get(ss, r16[bx] + 6);
    es = memory16get(ss, r16[bx] + 6 + 2);
    r8[al] = 0x01;
    stosb_data_forward();
    r8[al] = memory[ss*16 + r16[bx] + 4];
    stosb_data_forward();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
function sub_9c51() {
    push(0x7777);
    flags.direction = false;
    r16[bx] = sp;
    di = memory16get(ss, r16[bx] + 4);
    es = memory16get(ss, r16[bx] + 4 + 2);
    r16[cx] = 0x0010;
    r16[ax] = 0;
    rep_stosw_data_forward();
    assert(pop() == 0x7777);
    cs = pop();
}
function sub_9c60() {
    push(0x7777);
    r16[bx] = sp;
    di = memory16get(ss, r16[bx] + 6);
    es = memory16get(ss, r16[bx] + 6 + 2);
    r8[al] = memory[ss*16 + r16[bx] + 4];
    r8[bl] = r8[al];
    r8[bh] = 0;
    r8[cl] = 0x03;
    r16[bx] >>= r8[cl];
    r8[cl] = r8[al];
    r8[cl] &= 0x07;
    r8[al] = 0x01;
    r8[al] <<= r8[cl];
    memory[es*16 + r16[bx] + di] = memory[es*16 + r16[bx] + di] | r8[al];
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
function sub_9c81() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 8);
        es = memory16get(ss, r16[bx] + 8 + 2);
        r8[al] = memory[ss*16 + r16[bx] + 6];
        r8[dl] = memory[ss*16 + r16[bx] + 4];
        r8[tl] = r8[dl];
        r8[dl] -= r8[al];
        if (r8[tl] < r8[al]) {
            pc = 0x9cb2;
            break;
        }
        r8[dl]++;
        r8[bl] = r8[al];
        r8[bh] = 0;
        r8[cl] = 0x03;
        r16[bx] >>= r8[cl];
        r8[cl] = r8[al];
        r8[cl] &= 0x07;
        r8[al] = 0x01;
        r8[al] <<= r8[cl];
    case 0x9ca6:
        memory[es*16 + r16[bx] + di] = memory[es*16 + r16[bx] + di] | r8[al];
        flags.carry = !!(r8[al] & 0x80);
        r8[al] = rol8(r8[al], 0x01);
        r16[bx] += flags.carry;
        r8[dl]--;
        if (r8[dl] != 0) {
            pc = 0x9ca6;
            break;
        }
    case 0x9cb2:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_9cd5() {
    push(0x7777);
    r16[bx] = sp;
    di = memory16get(ss, r16[bx] + 4);
    es = memory16get(ss, r16[bx] + 4 + 2);
    r8[al] = memory[ss*16 + r16[bx] + 8];
    r8[bl] = r8[al];
    r8[bh] = 0;
    r8[cl] = 0x03;
    r16[bx] >>= r8[cl];
    r8[cl] = r8[al];
    r8[cl] &= 0x07;
    r8[al] = 0x01;
    r8[al] <<= r8[cl];
    flags.zero = !(memory[es*16 + r16[bx] + di] & r8[al]);
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
function sub_9d7d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di ^= 0x8000;
        if (!r8[cl]) {
            pc = 0x9d8f;
            break;
        }
        if (r8[al]) {
            pc = 0x9d90;
            break;
        }
    case 0x9d89:
        r16[ax] = r16[cx];
        r16[bx] = si;
        r16[dx] = di;
    case 0x9d8f:
        return;
    case 0x9d90:
        if (r8[al] <= r8[cl]) {
            pc = 0x9d99;
            break;
        }
        r16[tx] = r16[cx];
        r16[cx] = r16[ax];
        r16[ax] = r16[tx];
        r16[tx] = si;
        si = r16[bx];
        r16[bx] = r16[tx];
        r16[tx] = di;
        di = r16[dx];
        r16[dx] = r16[tx];
    case 0x9d99:
        r8[al] -= r8[cl];
        r8[al] = -r8[al];
        if (r8[al] >= 0x28) {
            pc = 0x9d89;
            break;
        }
        r8[tl] = r8[cl];
        r8[cl] = r8[al];
        r8[al] = r8[tl];
        push(bp);
        bp = di;
        bp ^= r16[dx];
        r16[tx] = flags.carry | (flags.zero << 1) | (bp & 0x8000);
        push(r16[tx]);
        bp = di;
        r8[dh] |= 0x80;
        di |= 0x8000;
    case 0x9db2:
        if (r8[cl] < 0x10) {
            pc = 0x9dc2;
            break;
        }
        r8[ah] = r8[bh];
        r16[bx] = r16[dx];
        r16[dx] = 0;
        r8[cl] -= 0x10;
        pc = 0x9db2;
        break;
    case 0x9dc2:
        if (r8[cl] < 0x08) {
            pc = 0x9dd4;
            break;
        }
        r8[ah] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = 0;
        r8[cl] -= 0x08;
    case 0x9dd4:
        if (!r8[cl]) {
            pc = 0x9de2;
            break;
        }
    case 0x9dd8:
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[bx] = rcr16(r16[bx], 0x0001);
        r8[ah] = rcr8(r8[ah], 0x01);
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x9dd8;
            break;
        }
    case 0x9de2:
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        if (r16[tx] & 0x8000) {
            pc = 0x9dfa;
            break;
        }
        flags.carry = (r8[ah] + r8[ch]) >= 0x100;
        r8[ah] += r8[ch];
        r8[tl] = flags.carry;
        flags.carry = (r16[bx] + si + r8[tl]) >= 0x10000;
        r16[bx] += si + r8[tl];
        r8[tl] = flags.carry;
        flags.carry = (r16[dx] + di + r8[tl]) >= 0x10000;
        r16[dx] += di + r8[tl];
        if (!flags.carry) {
            pc = 0x9e4c;
            break;
        }
        r16[dx] = rcr16(r16[dx], 0x0001);
        r16[bx] = rcr16(r16[bx], 0x0001);
        r8[ah] = rcr8(r8[ah], 0x01);
        r8[al]++;
        if (r8[al] != 0) {
            pc = 0x9e4c;
            break;
        }
        flags.carry = true;
        bp = pop();
        return;
    case 0x9dfa:
        r8[tl] = r8[ch];
        r8[ch] = r8[ah];
        r8[ah] = r8[tl];
        r16[tx] = si;
        si = r16[bx];
        r16[bx] = r16[tx];
        r16[tx] = di;
        di = r16[dx];
        r16[dx] = r16[tx];
        flags.carry = r8[ah] < r8[ch];
        r8[ah] -= r8[ch];
        r8[tl] = r16[bx] < si + flags.carry;
        r16[bx] -= si + flags.carry;
        flags.carry = r8[tl];
        r8[tl] = r16[dx] < di + flags.carry;
        r16[dx] -= di + flags.carry;
        flags.carry = r8[tl];
        if (!flags.carry) {
            pc = 0x9e1b;
            break;
        }
        bp ^= 0x8000;
        r8[ah] = ~ah;
        r16[bx] = ~bx;
        r16[dx] = ~dx;
        flags.carry = (r8[ah] + 0x01) >= 0x100;
        r8[ah] += 0x01;
        r8[tl] = flags.carry;
        flags.carry = (r16[bx] + 0x0000 + r8[tl]) >= 0x10000;
        r16[bx] += r8[tl];
        r16[dx] += flags.carry;
    case 0x9e1b:
        r8[cl] = 0x05;
    case 0x9e1d:
        if (r8[dh]) {
            pc = 0x9e35;
            break;
        }
        r8[dh] = r8[dl];
        r8[dl] = r8[bh];
        r8[bh] = r8[bl];
        r8[bl] = r8[ah];
        r8[ah] = 0;
        r8[tl] = r8[al];
        r8[al] -= 0x08;
        if (r8[tl] <= 0x08) {
            pc = 0x9e44;
            break;
        }
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x9e1d;
            break;
        }
        pc = 0x9e44;
        break;
    case 0x9e35:
        if (r8[dh] & 0x80) {
            pc = 0x9e4c;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x9e35;
            break;
        }
    case 0x9e44:
        r16[ax] = 0;
        r16[bx] = 0;
        r16[dx] = 0;
        bp = pop();
        return;
    case 0x9e4c:
        r8[dh] &= 0x7f;
        bp &= 0x8000;
        r16[dx] ^= bp;
        bp = pop();
        return;
    } while (1);
}
function sub_9d81() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!r8[cl]) {
            pc = 0x9d8f;
            break;
        }
        if (r8[al]) {
            pc = 0x9d90;
            break;
        }
    case 0x9d89:
        r16[ax] = r16[cx];
        r16[bx] = si;
        r16[dx] = di;
    case 0x9d8f:
        return;
    case 0x9d90:
        if (r8[al] <= r8[cl]) {
            pc = 0x9d99;
            break;
        }
        r16[tx] = r16[cx];
        r16[cx] = r16[ax];
        r16[ax] = r16[tx];
        r16[tx] = si;
        si = r16[bx];
        r16[bx] = r16[tx];
        r16[tx] = di;
        di = r16[dx];
        r16[dx] = r16[tx];
    case 0x9d99:
        r8[al] -= r8[cl];
        r8[al] = -r8[al];
        if (r8[al] >= 0x28) {
            pc = 0x9d89;
            break;
        }
        r8[tl] = r8[cl];
        r8[cl] = r8[al];
        r8[al] = r8[tl];
        push(bp);
        bp = di;
        bp ^= r16[dx];
        r16[tx] = flags.carry | (flags.zero << 1) | (bp & 0x8000);
        push(r16[tx]);
        bp = di;
        r8[dh] |= 0x80;
        di |= 0x8000;
    case 0x9db2:
        if (r8[cl] < 0x10) {
            pc = 0x9dc2;
            break;
        }
        r8[ah] = r8[bh];
        r16[bx] = r16[dx];
        r16[dx] = 0;
        r8[cl] -= 0x10;
        pc = 0x9db2;
        break;
    case 0x9dc2:
        if (r8[cl] < 0x08) {
            pc = 0x9dd4;
            break;
        }
        r8[ah] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = 0;
        r8[cl] -= 0x08;
    case 0x9dd4:
        if (!r8[cl]) {
            pc = 0x9de2;
            break;
        }
    case 0x9dd8:
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[bx] = rcr16(r16[bx], 0x0001);
        r8[ah] = rcr8(r8[ah], 0x01);
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x9dd8;
            break;
        }
    case 0x9de2:
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        if (r16[tx] & 0x8000) {
            pc = 0x9dfa;
            break;
        }
        flags.carry = (r8[ah] + r8[ch]) >= 0x100;
        r8[ah] += r8[ch];
        r8[tl] = flags.carry;
        flags.carry = (r16[bx] + si + r8[tl]) >= 0x10000;
        r16[bx] += si + r8[tl];
        r8[tl] = flags.carry;
        flags.carry = (r16[dx] + di + r8[tl]) >= 0x10000;
        r16[dx] += di + r8[tl];
        if (!flags.carry) {
            pc = 0x9e4c;
            break;
        }
        r16[dx] = rcr16(r16[dx], 0x0001);
        r16[bx] = rcr16(r16[bx], 0x0001);
        r8[ah] = rcr8(r8[ah], 0x01);
        r8[al]++;
        if (r8[al] != 0) {
            pc = 0x9e4c;
            break;
        }
        flags.carry = true;
        bp = pop();
        return;
    case 0x9dfa:
        r8[tl] = r8[ch];
        r8[ch] = r8[ah];
        r8[ah] = r8[tl];
        r16[tx] = si;
        si = r16[bx];
        r16[bx] = r16[tx];
        r16[tx] = di;
        di = r16[dx];
        r16[dx] = r16[tx];
        flags.carry = r8[ah] < r8[ch];
        r8[ah] -= r8[ch];
        r8[tl] = r16[bx] < si + flags.carry;
        r16[bx] -= si + flags.carry;
        flags.carry = r8[tl];
        r8[tl] = r16[dx] < di + flags.carry;
        r16[dx] -= di + flags.carry;
        flags.carry = r8[tl];
        if (!flags.carry) {
            pc = 0x9e1b;
            break;
        }
        bp ^= 0x8000;
        r8[ah] = ~ah;
        r16[bx] = ~bx;
        r16[dx] = ~dx;
        flags.carry = (r8[ah] + 0x01) >= 0x100;
        r8[ah] += 0x01;
        r8[tl] = flags.carry;
        flags.carry = (r16[bx] + 0x0000 + r8[tl]) >= 0x10000;
        r16[bx] += r8[tl];
        r16[dx] += flags.carry;
    case 0x9e1b:
        r8[cl] = 0x05;
    case 0x9e1d:
        if (r8[dh]) {
            pc = 0x9e35;
            break;
        }
        r8[dh] = r8[dl];
        r8[dl] = r8[bh];
        r8[bh] = r8[bl];
        r8[bl] = r8[ah];
        r8[ah] = 0;
        r8[tl] = r8[al];
        r8[al] -= 0x08;
        if (r8[tl] <= 0x08) {
            pc = 0x9e44;
            break;
        }
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x9e1d;
            break;
        }
        pc = 0x9e44;
        break;
    case 0x9e35:
        if (r8[dh] & 0x80) {
            pc = 0x9e4c;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x9e35;
            break;
        }
    case 0x9e44:
        r16[ax] = 0;
        r16[bx] = 0;
        r16[dx] = 0;
        bp = pop();
        return;
    case 0x9e4c:
        r8[dh] &= 0x7f;
        bp &= 0x8000;
        r16[dx] ^= bp;
        bp = pop();
        return;
    } while (1);
}
function sub_9ed4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        if (!r8[al]) {
            pc = 0x9f17;
            break;
        }
        r8[al] -= r8[cl];
        flags.carry = !flags.carry;
        sub_9f5d();
        if (flags.zero || flags.carry) {
            pc = 0x9f17;
            break;
        }
        push(bp);
        push(r16[cx]);
        sp -= 0x0004;
        push(r16[ax]);
        bp = sp;
        bp += 0x0005;
        r8[cl] = 0x08;
    case 0x9eed:
        flags.carry = r16[dx] < di;
        if (r16[dx] != di) {
            pc = 0x9ef7;
            break;
        }
        flags.carry = r16[bx] < si;
        if (r16[bx] != si) {
            pc = 0x9ef7;
            break;
        }
    case 0x9ef7:
        if (flags.carry) {
            pc = 0x9eff;
            break;
        }
        flags.carry = r8[ah] < r8[ch];
        r8[ah] -= r8[ch];
        r8[tl] = r16[bx] < si + flags.carry;
        r16[bx] -= si + flags.carry;
        flags.carry = r8[tl];
        r8[tl] = r16[dx] < di + flags.carry;
        r16[dx] -= di + flags.carry;
        flags.carry = r8[tl];
    case 0x9eff:
        flags.carry = !flags.carry;
    case 0x9f00:
        r8[al] = rcl8(r8[al], 0x01);
        r8[cl]--;
        if (r8[cl] == 0) {
            pc = 0x9f18;
            break;
        }
    case 0x9f06:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        if (!flags.carry) {
            pc = 0x9eed;
            break;
        }
        flags.carry = r8[ah] < r8[ch];
        r8[ah] -= r8[ch];
        r8[tl] = r16[bx] < si + flags.carry;
        r16[bx] -= si + flags.carry;
        flags.carry = r8[tl];
        r16[dx] -= di + flags.carry;
        flags.carry = true;
        pc = 0x9f00;
        break;
    case 0x9f17:
        assert(pop() == 0x7777);
        return;
    case 0x9f18:
        memory[ss*16 + bp] = r8[al];
        r8[cl] = 0x08;
        bp--;
        if (bp != sp) {
            pc = 0x9f06;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        if (flags.carry) {
            pc = 0x9f35;
            break;
        }
        if (r16[dx] != di) {
            pc = 0x9f34;
            break;
        }
        if (r16[bx] != si) {
            pc = 0x9f34;
            break;
        }
    case 0x9f34:
        flags.carry = !flags.carry;
    case 0x9f35:
        si = rcl16(si, 0x0001);
        r16[ax] = pop();
        r16[bx] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        bp = pop();
        if (r8[dh] & 0x80) {
            pc = 0x9f4b;
            break;
        }
        si = rcr16(si, 0x0001);
        r8[ah] = rcl8(r8[ah], 0x01);
        r16[bx] = rcl16(r16[bx], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        pc = 0x9f50;
        break;
    case 0x9f4b:
        r8[al]++;
        flags.carry = true;
        if (r8[al] == 0) {
            pc = 0x9f5c;
            break;
        }
    case 0x9f50:
        r8[dh] ^= r8[cl];
        if (r8[al]) {
            pc = 0x9f5c;
            break;
        }
        r16[ax] = 0;
        r16[bx] = 0;
        r16[dx] = 0;
    case 0x9f5c:
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function sub_9f5d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (flags.carry) {
            pc = 0x9f6a;
            break;
        }
        flags.carry = (r8[al] + 0x80) >= 0x100;
        r8[al] += 0x80;
        if (flags.carry) {
            pc = 0x9f6e;
            break;
        }
        r16[ax] = 0;
        r16[bx] = 0;
        flags.carry = false;
        r16[dx] = 0;
        flags.zero = true;
        return;
    case 0x9f6a:
        flags.carry = (r8[al] + 0x80) >= 0x100;
        r8[al] += 0x80;
        if (flags.carry) {
            pc = 0x9f7f;
            break;
        }
    case 0x9f6e:
        r16[tx] = di;
        di = r16[ax];
        r16[ax] = r16[tx];
        r8[cl] = r8[ah];
        r8[cl] ^= r8[dh];
        r8[cl] = ~cl;
        r8[cl] &= 0x80;
        r8[ah] |= 0x80;
        r8[dh] |= 0x80;
        r16[tx] = di;
        di = r16[ax];
        r16[ax] = r16[tx];
        flags.zero = false;
    case 0x9f7f:
        return;
    } while (1);
}
function sub_9faa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[ax];
        r16[bx] |= r16[dx];
        if (!r16[bx])
            return;
        r8[ch] = r8[dh];
        if (!(r16[dx] & 0x8000)) {
            pc = 0x9fc0;
            break;
        }
        r16[ax] = ~ax;
        r16[dx] = ~dx;
        flags.carry = (r16[ax] + 0x0001) >= 0x10000;
        r16[ax] += 0x0001;
        r16[dx] += flags.carry;
    case 0x9fc0:
        r16[bx] = r16[ax];
        r16[ax] = 0x00a0;
        if (r16[dx]) {
            pc = 0x9fd5;
            break;
        }
        r16[tx] = r16[bx];
        r16[bx] = r16[dx];
        r16[dx] = r16[tx];
        r8[al] = 0x90;
        if (r8[dh]) {
            pc = 0x9fd5;
            break;
        }
        r8[tl] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = r8[tl];
        r8[al] = 0x88;
    case 0x9fd5:
        if (r16[dx] & 0x8000) {
            pc = 0x9fe1;
            break;
        }
    case 0x9fd9:
        r8[al]--;
        flags.carry = (r16[bx] + r16[bx]) >= 0x10000;
        r16[bx] += r16[bx];
        r16[dx] += r16[dx] + flags.carry;
        if (r16s[dx] >= 0) {
            pc = 0x9fd9;
            break;
        }
    case 0x9fe1:
        if (r8[ch] & 0x80)
            return;
        r8[dh] &= 0x7f;
        return;
    } while (1);
}
function sub_9fe9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[tx] = r16[bx];
        r16[bx] = r16[ax];
        r16[ax] = r16[tx];
        r8[cl] = 0x9f;
        r8[tl] = r8[cl];
        r8[cl] -= r8[bl];
        if (r8[tl] < r8[bl]) {
            pc = 0xa03e;
            break;
        }
        flags.carry = false;
        if (r8[cl] > 0x1f) {
            pc = 0xa040;
            break;
        }
        r8[cl]++;
        r8[bh] = r8[dh];
        r8[dh] |= 0x80;
        if (r8[cl] < 0x11) {
            pc = 0xa008;
            break;
        }
        r16[ax] = r16[dx];
        r16[dx] = 0;
        r8[cl] -= 0x10;
    case 0xa008:
        if (r8[cl] < 0x09) {
            pc = 0xa018;
            break;
        }
        r8[al] = r8[ah];
        r8[ah] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = 0;
        r8[cl] -= 0x08;
    case 0xa018:
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r8[cl] == 0;
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0xa018;
            break;
        }
        if (!flags.carry) {
            pc = 0xa02e;
            break;
        }
        if (!r8[ch]) {
            pc = 0xa02e;
            break;
        }
        flags.carry = (r16[ax] + 0x0001) >= 0x10000;
        r16[ax] += 0x0001;
        r16[dx] += flags.carry;
        if (r16s[dx] < 0) {
            pc = 0xa03e;
            break;
        }
    case 0xa02e:
        if (!(r8[bh] & 0x80)) {
            pc = 0xa03c;
            break;
        }
        r16[ax] = ~ax;
        r16[dx] = ~dx;
        flags.carry = (r16[ax] + 0x0001) >= 0x10000;
        r16[ax] += 0x0001;
        r16[dx] += flags.carry;
    case 0xa03c:
        flags.carry = false;
        return;
    case 0xa03e:
        flags.carry = true;
        return;
    case 0xa040:
        r16[ax] = 0;
        flags.carry = false;
        r16[dx] = 0;
        return;
    } while (1);
}
function sub_a06b() {
    sub_9faa();
    cs = pop();
}
function sub_a06f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0xa06f;
        break;
    case 0x965c:
        stop(/*override stack*/);
        r16[cx] = pop();
        r16[bx] = pop();
        pc = 0x9667;
        break;
    case 0x9667:
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
    case 0xa06f:
        r8[ch] = 0x00;
        sub_9fe9();
        if (flags.carry) {
            pc = 0xa07f;
            break;
        }
        cs = pop();
        return;
    case 0xa07f:
        r16[ax] = 0x00cf;
        pc = 0x965c;
        break;
        return;
    } while (1);
}
function sub_a091() {
    push(di);
    push(si);
    push(r16[cx]);
    sub_9d81();
    r16[cx] = pop();
    si = pop();
    di = pop();
}
function sub_a0af() {
    push(di);
    push(si);
    push(r16[cx]);
    sub_9ed4();
    r16[cx] = pop();
    si = pop();
    di = pop();
}
function sub_a11e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0xa11e;
        break;
    case 0x965c:
        stop(/*override stack*/);
        r16[cx] = pop();
        r16[bx] = pop();
        pc = 0x9667;
        break;
    case 0x9667:
        r16[dx] = 0x0ac3;
        ds = r16[dx];
        r16[dx] = r16[cx];
        r16[dx] |= r16[bx];
        if (!r16[dx]) {
            pc = 0x9679;
            break;
        }
        r16[bx] -= memory16get(ds, 0x1794);
        r16[bx] -= 0x0010;
    case 0x9679:
        es = memory16get(ds, 0x1794);
        if (memory[es*16 + 0x0005] == 0xc3) {
            pc = 0x9692;
            break;
        }
        es = memory16get(es, 0x0016);
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x9697;
            break;
        }
    case 0x9692:
        push(cs);
        cs = memory16get(es, 0x0006 + 2);
        callIndirect(memory16get(es, 0x0006 + 2), memory16get(es, 0x0006));
        assert(cs == 0x0947);
    case 0x9697:
        memory16set(ds, 0x17ac, r16[ax]);
        memory16set(ds, 0x17ae, r16[cx]);
        memory16set(ds, 0x17b0, r16[bx]);
        r16[bx] = memory16get(ds, 0x17a8);
        es = memory16get(ds, 0x17a8 + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (!r16[ax]) {
            pc = 0x96bf;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x17a8, r16[ax]);
        memory16set(ds, 0x17aa, r16[ax]);
        memory16set(ds, 0x17cb, r16[ax]);
        r16[ax] = 0x0232;
        push(cs);
        push(r16[ax]);
        push(es);
        push(r16[bx]);
        assert(pop() == 0x7777);
        cs = pop();
        return;
    case 0x96bf:
        es = memory16get(ds, 0x1794);
        flags.carry = memory[es*16 + 0x0005] < 0xc3;
        if (memory[es*16 + 0x0005] != 0xc3) {
            pc = 0x96d6;
            break;
        }
        memory[es*16 + 0x0005] = 0x00;
        daa();
    case 0x96d6:
        r16[ax] = memory16get(ds, 0x17ac);
        r8[ah] = 0x4c;
        interrupt(0x21);
    case 0xa11e:
        push(bp);
        bp = sp;
        sp -= 0x0008;
        r16[cx] = r16[ax];
        si = r16[bx];
        di = r16[dx];
        if (!r8[al]) {
            pc = 0xa16a;
            break;
        }
        if (r8[dh] & 0x80) {
            pc = 0xa174;
            break;
        }
        memory16set(ss, bp - 8, r16[ax]);
        memory16set(ss, bp - 6, r16[bx]);
        memory16set(ss, bp - 4, r16[dx]);
        r8[cl] += 0x80;
        r8[cl] = sar8(r8[cl], 1);
        r8[cl] += 0x80;
        r8[al] = r8[cl];
        r8[al] -= 0x14;
        memory[ss*16 + bp - 2] = r8[al];
    case 0xa14b:
        r16[ax] = memory16get(ss, bp - 8);
        r16[bx] = memory16get(ss, bp - 6);
        r16[dx] = memory16get(ss, bp - 4);
        sub_a0af();
        sub_a091();
        r8[al]--;
        push(r16[dx]);
        push(r16[bx]);
        push(r16[ax]);
        sub_9d7d();
        r16[cx] = pop();
        si = pop();
        di = pop();
        if (r8[al] >= memory[ss*16 + bp - 2]) {
            pc = 0xa14b;
            break;
        }
    case 0xa16a:
        r16[ax] = r16[cx];
        r16[bx] = si;
        r16[dx] = di;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    case 0xa174:
        sp = bp;
        bp = pop();
        r16[ax] = 0x00cf;
        pc = 0x965c;
        break;
        return;
    } while (1);
}
function sub_a504() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        sub_a552();
        r16[ax] = 0;
        r16[bx] = sp;
        r16[bx] = memory16get(ss, r16[bx] + 4);
        if (!r16[bx]) {
            pc = 0xa517;
            break;
        }
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        div16(r16[bx]);
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
    case 0xa517:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 2;
        return;
    } while (1);
}
function sub_a552() {
    r16[ax] = memory16get(ds, 0x17b2);
    r16[bx] = memory16get(ds, 0x17b4);
    r16[cx] = r16[ax];
    mul16(memory16get(cs, 0x1118));
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r8[ch] += r8[cl];
    r16[dx] += r16[cx];
    r16[dx] += r16[bx];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[dx] += r16[bx];
    r8[dh] += r8[bl];
    r8[cl] = 0x05;
    r16[bx] <<= r8[cl];
    r8[dh] += r8[bl];
    flags.carry = (r16[ax] + 0x0001) >= 0x10000;
    r16[ax] += 0x0001;
    r16[dx] += flags.carry;
    memory16set(ds, 0x17b2, r16[ax]);
    memory16set(ds, 0x17b4, r16[dx]);
}
function sub_a58a() {
    r8[ah] = 0x2c;
    interrupt(0x21);
    memory16set(ds, 0x17b2, r16[cx]);
    memory16set(ds, 0x17b4, r16[dx]);
    cs = pop();
}
function sub_a597() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        flags.direction = false;
        r16[bx] = r16[ax];
        if (r16s[dx] >= 0) {
            pc = 0xa5ac;
            break;
        }
        r16[bx] = ~bx;
        r16[dx] = ~dx;
        flags.carry = (r16[bx] + 0x0001) >= 0x10000;
        r16[bx] += 0x0001;
        r16[dx] += flags.carry;
        r8[al] = 0x2d;
        stosb_data_forward();
    case 0xa5ac:
        si = 0x1179;
        r8[cl] = 0x09;
    case 0xa5b1:
        if (r16[dx] < memory16get(cs, si + 2)) {
            pc = 0xa5be;
            break;
        }
        if (r16[dx] > memory16get(cs, si + 2)) {
            pc = 0xa5c5;
            break;
        }
        if (r16[bx] >= memory16get(cs, si)) {
            pc = 0xa5c5;
            break;
        }
    case 0xa5be:
        si += 0x0004;
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0xa5b1;
            break;
        }
    case 0xa5c5:
        r8[cl]++;
    case 0xa5c7:
        r8[al] = 0x2f;
    case 0xa5c9:
        r8[al]++;
        flags.carry = r16[bx] < memory16get(cs, si);
        r16[bx] -= memory16get(cs, si);
        r8[tl] = r16[dx] < memory16get(cs, si + 2) + flags.carry;
        r16[dx] -= memory16get(cs, si + 2) + flags.carry;
        flags.carry = r8[tl];
        if (!flags.carry) {
            pc = 0xa5c9;
            break;
        }
        flags.carry = (r16[bx] + memory16get(cs, si)) >= 0x10000;
        r16[bx] += memory16get(cs, si);
        r16[dx] += memory16get(cs, si + 2) + flags.carry;
        si += 0x0004;
        stosb_data_forward();
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0xa5c7;
            break;
        }
        r16[cx] = di;
        di = pop();
        r16[cx] -= di;
        return;
    } while (1);
}
function sub_a6a9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        push(ds);
        di = memory16get(ss, r16[bx] + 8);
        es = memory16get(ss, r16[bx] + 8 + 2);
        si = memory16get(ss, r16[bx] + 4);
        ds = memory16get(ss, r16[bx] + 4 + 2);
        flags.direction = false;
        r16[ax] = 0;
        stosw_data_forward();
        r16[ax] = 0xd7b0;
        stosw_data_forward();
        r16[ax] = 0x0080;
        stosw_data_forward();
        r16[ax] = 0;
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[ax] = di + 0x74;
        stosw_data_forward();
        r16[ax] = es;
        stosw_data_forward();
        r16[ax] = 0x135d;
        stosw_data_forward();
        r16[ax] = cs;
        stosw_data_forward();
        r16[ax] = 0;
        r16[cx] = 0x000e;
        rep_stosw_data_forward();
        lodsb_data_forward();
        if (r8[al] <= 0x4f) {
            pc = 0xa6e1;
            break;
        }
        r8[al] = 0x4f;
    case 0xa6e1:
        r8[cl] = r8[al];
        r8[ch] = 0;
        rep_movsb_data_data_forward();
        r8[al] = 0;
        stosb_data_forward();
        ds = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 8;
        return;
    } while (1);
}
function sub_a719() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[dx] = 0xd7b1;
        pc = 0xa726;
        break;
    case 0xa726:
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        r16[ax] = memory16get(es, di + 2);
        if (r16[ax] == 0xd7b1) {
            pc = 0xa747;
            break;
        }
        if (r16[ax] == 0xd7b2) {
            pc = 0xa747;
            break;
        }
        if (r16[ax] == 0xd7b0) {
            pc = 0xa74c;
            break;
        }
        memory16set(ds, 0x17cb, 0x0066);
        pc = 0xa768;
        break;
    case 0xa747:
        push(r16[dx]);
        sub_a7b6();
        r16[dx] = pop();
    case 0xa74c:
        r16[ax] = 0;
        memory16set(es, di + 2, r16[dx]);
        memory16set(es, di + 8, r16[ax]);
        memory16set(es, di + 10, r16[ax]);
        r16[bx] = 0x0010;
        sub_a7bc();
        if (flags.zero) {
            pc = 0xa768;
            break;
        }
        memory16set(es, di + 2, 0xd7b0);
    case 0xa768:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_a71e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[dx] = 0xd7b2;
        pc = 0xa726;
        break;
    case 0xa726:
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        r16[ax] = memory16get(es, di + 2);
        if (r16[ax] == 0xd7b1) {
            pc = 0xa747;
            break;
        }
        if (r16[ax] == 0xd7b2) {
            pc = 0xa747;
            break;
        }
        if (r16[ax] == 0xd7b0) {
            pc = 0xa74c;
            break;
        }
        memory16set(ds, 0x17cb, 0x0066);
        pc = 0xa768;
        break;
    case 0xa747:
        push(r16[dx]);
        sub_a7b6();
        r16[dx] = pop();
    case 0xa74c:
        r16[ax] = 0;
        memory16set(es, di + 2, r16[dx]);
        memory16set(es, di + 8, r16[ax]);
        memory16set(es, di + 10, r16[ax]);
        r16[bx] = 0x0010;
        sub_a7bc();
        if (flags.zero) {
            pc = 0xa768;
            break;
        }
        memory16set(es, di + 2, 0xd7b0);
    case 0xa768:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_a7aa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0014;
        if (memory16get(es, di + 2) == 0xd7b2) {
            pc = 0xa7bc;
            break;
        }
        return;
    case 0xa7bc:
        push(es);
        push(di);
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, r16[bx] + di + 2);
        callIndirect(memory16get(es, r16[bx] + di + 2), memory16get(es, r16[bx] + di));
        assert(cs == 0x0947);
        if (!r16[ax]) {
            pc = 0xa7ca;
            break;
        }
        memory16set(ds, 0x17cb, r16[ax]);
    case 0xa7ca:
        di = pop();
        es = pop();
        return;
    } while (1);
}
function sub_a7b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        sub_a7aa();
        r16[bx] = 0x001c;
        push(es);
        push(di);
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, r16[bx] + di + 2);
        callIndirect(memory16get(es, r16[bx] + di + 2), memory16get(es, r16[bx] + di));
        assert(cs == 0x0947);
        if (!r16[ax]) {
            pc = 0xa7ca;
            break;
        }
        memory16set(ds, 0x17cb, r16[ax]);
    case 0xa7ca:
        di = pop();
        es = pop();
        return;
    } while (1);
}
function sub_a7bc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(di);
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, r16[bx] + di + 2);
        callIndirect(memory16get(es, r16[bx] + di + 2), memory16get(es, r16[bx] + di));
        assert(cs == 0x0947);
        flags.zero = r16[ax] == 0;
        if (!r16[ax]) {
            pc = 0xa7ca;
            break;
        }
        memory16set(ds, 0x17cb, r16[ax]);
    case 0xa7ca:
        di = pop();
        es = pop();
        return;
    } while (1);
}
function sub_a7cd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        push(ds);
        di = memory16get(ss, r16[bx] + 4);
        ds = memory16get(ss, r16[bx] + 4 + 2);
        r16[cx] = 0;
        memory16set(ds, di, r16[cx]);
        r16[ax] = 0x3d00;
        if (memory16get(ds, di + 2) == 0xd7b1) {
            pc = 0xa7ef;
            break;
        }
        r8[al] = 0x02;
        memory16set(ds, di, memory16get(ds, di) + 1);
        if (memory16get(ds, di + 2) == 0xd7b3) {
            pc = 0xa7ef;
            break;
        }
        r8[ah] = 0x3c;
    case 0xa7ef:
        if (memory[ds*16 + di + 48] == 0x00) {
            pc = 0xa7fe;
            break;
        }
        r16[dx] = di + 0x30;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0xa847;
            break;
        }
        memory16set(ds, di, r16[ax]);
    case 0xa7fe:
        r16[ax] = 0x143a;
        r16[bx] = 0x1435;
        if (memory16get(ds, di + 2) == 0xd7b1) {
            pc = 0xa831;
            break;
        }
        r16[bx] = memory16get(ds, di);
        r16[ax] = 0x4400;
        interrupt(0x21);
        r16[ax] = 0x1493;
        r16[bx] = r16[ax];
        if (r8[dl] & 0x80) {
            pc = 0xa82c;
            break;
        }
        if (memory16get(ds, di + 2) != 0xd7b3) {
            pc = 0xa826;
            break;
        }
        sub_a84b();
    case 0xa826:
        r16[ax] = 0x146a;
        r16[bx] = 0x1435;
    case 0xa82c:
        memory16set(ds, di + 2, 0xd7b2);
    case 0xa831:
        memory16set(ds, di + 20, r16[ax]);
        memory16set(ds, di + 22, cs);
        memory16set(ds, di + 24, r16[bx]);
        memory16set(ds, di + 26, cs);
        memory16set(ds, di + 28, 0x14b7);
        memory16set(ds, di + 30, cs);
        r16[ax] = 0;
    case 0xa847:
        ds = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_a84b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0;
        r16[cx] = 0;
        r16[bx] = memory16get(ds, di);
        r16[ax] = 0x4202;
        interrupt(0x21);
        flags.carry = r16[ax] < 0x0080;
        r16[ax] -= 0x0080;
        r8[tl] = r16[dx] < 0x0000 + flags.carry;
        r16[dx] -= flags.carry;
        flags.carry = r8[tl];
        if (!flags.carry) {
            pc = 0xa862;
            break;
        }
        r16[ax] = 0;
        r16[dx] = 0;
    case 0xa862:
        r16[cx] = r16[dx];
        r16[dx] = r16[ax];
        r16[bx] = memory16get(ds, di);
        r16[ax] = 0x4200;
        interrupt(0x21);
        r16[dx] = di + 0x80;
        r16[cx] = 0x0080;
        r16[bx] = memory16get(ds, di);
        r8[ah] = 0x3f;
        interrupt(0x21);
        if (!flags.carry) {
            pc = 0xa87e;
            break;
        }
        r16[ax] = 0;
    case 0xa87e:
        r16[bx] = 0;
    case 0xa880:
        if (r16[bx] == r16[ax])
            return;
        if (memory[ds*16 + r16[bx] + di + 128] == 0x1a) {
            pc = 0xa88e;
            break;
        }
        r16[bx]++;
        pc = 0xa880;
        break;
    case 0xa88e:
        r16[dx] = r16[bx];
        r16[dx] -= r16[ax];
        r16[cx] = 0xffff;
        r16[bx] = memory16get(ds, di);
        r16[ax] = 0x4202;
        interrupt(0x21);
        r16[cx] = 0;
        r16[bx] = memory16get(ds, di);
        r8[ah] = 0x40;
        interrupt(0x21);
        return;
    } while (1);
}
function sub_a93e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.zero = memory16get(es, di + 2) == 0xd7b1;
        if (memory16get(es, di + 2) != 0xd7b1) {
            pc = 0xa95f;
            break;
        }
        flags.zero = memory16get(ds, 0x17cb) == 0x0000;
        if (memory16get(ds, 0x17cb) != 0x0000)
            return;
        si = pop();
        push(ds);
        push(es);
        push(di);
        r16[bx] = memory16get(es, di + 8);
        r16[dx] = memory16get(es, di + 10);
        r16[tx] = di;
        di = memory16get(es, r16[tx] + 12);
        es = memory16get(es, r16[tx] + 12 + 2);
        stop(/*2*/);
    case 0xa95f:
        memory16set(ds, 0x17cb, 0x0068);
        return;
    } while (1);
}
function sub_a966() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[bx] == r16[dx]) {
            pc = 0xa96f;
            break;
        }
    case 0xa96a:
        r8[al] = memory[es*16 + r16[bx] + di];
        flags.carry = false;
        return;
    case 0xa96f:
        push(r16[cx]);
        push(ds);
        push(si);
        ds = memory16get(ss, bp - 2);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        memory16set(es, di + 8, r16[bx]);
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, di + 20 + 2);
        callIndirect(memory16get(es, di + 20 + 2), memory16get(es, di + 20));
        assert(cs == 0x0947);
        if (!r16[ax]) {
            pc = 0xa989;
            break;
        }
        memory16set(ds, 0x17cb, r16[ax]);
    case 0xa989:
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[bx] = memory16get(es, di + 8);
        r16[dx] = memory16get(es, di + 10);
        r16[tx] = di;
        di = memory16get(es, r16[tx] + 12);
        es = memory16get(es, r16[tx] + 12 + 2);
        si = pop();
        ds = pop();
        r16[cx] = pop();
        if (r16[bx] != r16[dx]) {
            pc = 0xa96a;
            break;
        }
        r8[al] = 0x1a;
        flags.carry = true;
        return;
    } while (1);
}
function sub_a9a3() {
    stop(/*override stack*/);
    si = pop();
    di = pop();
    es = pop();
    ds = pop();
    memory16set(es, di + 8, r16[bx]);
    stop(/*2*/);
}
function sub_a9ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.zero = memory16get(es, di + 2) == 0xd7b2;
        if (memory16get(es, di + 2) != 0xd7b2) {
            pc = 0xa9ce;
            break;
        }
        flags.zero = memory16get(ds, 0x17cb) == 0x0000;
        if (memory16get(ds, 0x17cb) != 0x0000)
            return;
        si = 0x6ab0;
        push(ds);
        push(es);
        push(di);
        r16[bx] = memory16get(es, di + 8);
        r16[dx] = memory16get(es, di + 4);
        r16[tx] = di;
        di = memory16get(es, r16[tx] + 12);
        es = memory16get(es, r16[tx] + 12 + 2);
        return;
    case 0xa9ce:
        memory16set(ds, 0x17cb, 0x0069);
        return;
    } while (1);
}
function sub_a9d5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[es*16 + r16[bx] + di] = r8[al];
        r16[bx]++;
        if (r16[bx] == r16[dx]) {
            pc = 0xa9de;
            break;
        }
        return;
    case 0xa9de:
        push(r16[cx]);
        push(ds);
        push(si);
        ds = memory16get(ss, bp - 2);
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        memory16set(es, di + 8, r16[bx]);
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, di + 20 + 2);
        callIndirect(memory16get(es, di + 20 + 2), memory16get(es, di + 20));
        assert(cs == 0x0947);
        if (!r16[ax]) {
            pc = 0xa9f8;
            break;
        }
        memory16set(ds, 0x17cb, r16[ax]);
    case 0xa9f8:
        di = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r16[bx] = memory16get(es, di + 8);
        r16[dx] = memory16get(es, di + 4);
        r16[tx] = di;
        di = memory16get(es, r16[tx] + 12);
        es = memory16get(es, r16[tx] + 12 + 2);
        si = pop();
        ds = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function sub_aa0b() {
    di = pop();
    es = pop();
    ds = pop();
    memory16set(es, di + 8, r16[bx]);
}
function sub_aa15() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        sub_a93e();
        if (!flags.zero) {
            pc = 0xaa37;
            break;
        }
    case 0xaa20:
        sub_a966();
        if (r8[al] == 0x1a) {
            pc = 0xaa34;
            break;
        }
        r16[bx]++;
        if (r8[al] != 0x0d) {
            pc = 0xaa20;
            break;
        }
        sub_a966();
        if (r8[al] != 0x0a) {
            pc = 0xaa34;
            break;
        }
        r16[bx]++;
    case 0xaa34:
        sub_a9a3();
    case 0xaa37:
        bp = pop();
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        if (memory16get(es, di + 2) != 0xd7b1) {
            pc = 0xaa5a;
            break;
        }
        if (memory16get(ds, 0x17cb) != 0x0000) {
            pc = 0xaa57;
            break;
        }
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, di + 24 + 2);
        callIndirect(memory16get(es, di + 24 + 2), memory16get(es, di + 24));
        assert(cs == 0x0947);
        if (r16[ax]) {
            pc = 0xaa5d;
            break;
        }
    case 0xaa57:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    case 0xaa5a:
        r16[ax] = 0x0068;
    case 0xaa5d:
        memory16set(ds, 0x17cb, r16[ax]);
        pc = 0xaa57;
        break;
        return;
    } while (1);
}
function sub_aa62() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        sub_a9ad();
        if (!flags.zero) {
            pc = 0xaa7a;
            break;
        }
        r8[al] = 0x0d;
        sub_a9d5();
        r8[al] = 0x0a;
        sub_a9d5();
        sub_aa0b();
    case 0xaa7a:
        bp = pop();
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        if (memory16get(es, di + 2) != 0xd7b2) {
            pc = 0xaa9d;
            break;
        }
        if (memory16get(ds, 0x17cb) != 0x0000) {
            pc = 0xaa9a;
            break;
        }
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, di + 24 + 2);
        callIndirect(memory16get(es, di + 24 + 2), memory16get(es, di + 24));
        assert(cs == 0x0947);
        if (r16[ax]) {
            pc = 0xaaa0;
            break;
        }
    case 0xaa9a:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    case 0xaa9d:
        r16[ax] = 0x0069;
    case 0xaaa0:
        memory16set(ds, 0x17cb, r16[ax]);
        pc = 0xaa9a;
        break;
        return;
    } while (1);
}
function sub_aa7b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        di = memory16get(ss, r16[bx] + 4);
        es = memory16get(ss, r16[bx] + 4 + 2);
        if (memory16get(es, di + 2) != 0xd7b2) {
            pc = 0xaa9d;
            break;
        }
        if (memory16get(ds, 0x17cb) != 0x0000) {
            pc = 0xaa9a;
            break;
        }
        push(es);
        push(di);
        push(cs);
        cs = memory16get(es, di + 24 + 2);
        callIndirect(memory16get(es, di + 24 + 2), memory16get(es, di + 24));
        assert(cs == 0x0947);
        if (r16[ax]) {
            pc = 0xaaa0;
            break;
        }
    case 0xaa9a:
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    case 0xaa9d:
        r16[ax] = 0x0069;
    case 0xaaa0:
        memory16set(ds, 0x17cb, r16[ax]);
        pc = 0xaa9a;
        break;
        return;
    } while (1);
}
function sub_aabf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 10);
        es = memory16get(ss, bp + 10 + 2);
        sub_a9ad();
        if (!flags.zero) {
            pc = 0xaae0;
            break;
        }
        r16[cx] = memory16get(ss, bp + 6);
        r16[cx]--;
        if (r16s[cx] <= 0) {
            pc = 0xaad7;
            break;
        }
    case 0xaad0:
        r8[al] = 0x20;
        sub_a9d5();
        if (--r16[cx]) {
            pc = 0xaad0;
            break;
        }
    case 0xaad7:
        r8[al] = memory[ss*16 + bp + 8];
        sub_a9d5();
        sub_aa0b();
    case 0xaae0:
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 4;
        return;
    } while (1);
}
function sub_ab1d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        di = memory16get(ss, bp + 12);
        es = memory16get(ss, bp + 12 + 2);
        sub_a9ad();
        if (!flags.zero) {
            pc = 0xab4d;
            break;
        }
        si = memory16get(ss, bp + 8);
        ds = memory16get(ss, bp + 8 + 2);
        r16[cx] = memory16get(ss, bp + 6);
        flags.direction = false;
        lodsb_data_forward();
        r8[ah] = 0;
        r16[tx] = r16[cx];
        r16[cx] -= r16[ax];
        if (r16s[tx] - r16s[ax] <= 0) {
            pc = 0xab3f;
            break;
        }
        push(r16[ax]);
    case 0xab37:
        r8[al] = 0x20;
        sub_a9d5();
        if (--r16[cx]) {
            pc = 0xab37;
            break;
        }
        r16[ax] = pop();
    case 0xab3f:
        r16[cx] = r16[ax];
        if (r16[cx] == 0) {
            pc = 0xab4a;
            break;
        }
    case 0xab43:
        flags.direction = false;
        lodsb_data_forward();
        sub_a9d5();
        if (--r16[cx]) {
            pc = 0xab43;
            break;
        }
    case 0xab4a:
        sub_aa0b();
    case 0xab4d:
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 6;
        return;
    } while (1);
}
function sub_aba8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        sp -= 0x0020;
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 40);
        r16[dx] = memory16get(ss, bp + 42);
        di = bp + 0x2;
        push(ss);
        es = pop();
        sub_a597();
        di = memory16get(ss, bp + 44);
        es = memory16get(ss, bp + 44 + 2);
        sub_a9ad();
        if (!flags.zero) {
            pc = 0xabe5;
            break;
        }
        r16[ax] = memory16get(ss, bp + 38);
        r16[tx] = r16[ax];
        r16[ax] -= r16[cx];
        if (r16s[tx] - r16s[cx] <= 0) {
            pc = 0xabd6;
            break;
        }
        push(r16[cx]);
        r16[cx] = r16[ax];
    case 0xabce:
        r8[al] = 0x20;
        sub_a9d5();
        if (--r16[cx]) {
            pc = 0xabce;
            break;
        }
        r16[cx] = pop();
    case 0xabd6:
        si = bp + 0x2;
        push(ss);
        ds = pop();
    case 0xabdb:
        flags.direction = false;
        lodsb_data_forward();
        sub_a9d5();
        if (--r16[cx]) {
            pc = 0xabdb;
            break;
        }
        sub_aa0b();
    case 0xabe5:
        bp = pop();
        sp += 0x0020;
        assert(pop() == 0x7777);
        cs = pop();
        sp += 6;
        return;
    } while (1);
}
function sub_abec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[bx] = sp;
        r16[dx] = ds;
        si = memory16get(ss, r16[bx] + 10);
        ds = memory16get(ss, r16[bx] + 10 + 2);
        di = memory16get(ss, r16[bx] + 6);
        es = memory16get(ss, r16[bx] + 6 + 2);
        r16[cx] = memory16get(ss, r16[bx] + 4);
        flags.direction = false;
        if (si >= di) {
            pc = 0xac08;
            break;
        }
        si += r16[cx];
        di += r16[cx];
        si--;
        di--;
        flags.direction = true;
    case 0xac08:
        rep_movsb_data_data_forward();
        ds = r16[dx];
        assert(pop() == 0x7777);
        cs = pop();
        sp += 10;
        return;
    } while (1);
}
function sub_ac0f() {
    push(0x7777);
    r16[bx] = sp;
    di = memory16get(ss, r16[bx] + 8);
    es = memory16get(ss, r16[bx] + 8 + 2);
    r16[cx] = memory16get(ss, r16[bx] + 6);
    r8[al] = memory[ss*16 + r16[bx] + 4];
    flags.direction = false;
    if (es == 0xb800)
        rep_stosb_video_forward();
    else
    rep_stosb_data_forward();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}