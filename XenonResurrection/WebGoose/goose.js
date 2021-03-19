function* start() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _dseg;
        ds = r16[ax];
        r16[bx] = 0x9670;
        r16[bx] += 0x000f;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] += r16[bx];
        memory16set(ds*16+0x94E8, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94EA, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94EC, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94EE, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94F0, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94F2, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94F4, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds*16+0x94F6, r16[ax]);
        interrupt(18);
        if (r16[ax] >= 0x0200) {
            pc = 0x10067;
            break;
        }
        r16[dx] = 0x0007;
        r8[ah] = 0x09;
        interrupt(33);
        r16[ax] = 0x4c00;
        interrupt(33);
        pc = 0x1006E;
        break;
    case 0x10067:
        r16[dx] = 0x002a;
        r8[ah] = 0x09;
        interrupt(33);
    case 0x1006E:
        yield* sub_10600();
        yield* sub_1333C();
        yield* sub_12762();
        yield* sub_105EC();
        yield* sub_10442();
        yield* sub_10588();
        yield* sub_10591();
        yield* sub_1382A();
        memory[ds*16+0x9501] = 0x00;
    case 0x1008B:
        yield* sub_100A9();
        yield* sub_100CF();
        yield* sub_100FD();
        pc = 0x1008B;
        break;
        return;
    } while (1);
}
function* loc_10096() {
    yield* sub_139A3();
    yield* sub_105BC();
    yield* sub_104A5();
    r16[ax] = 0x0003;
    interrupt(16);
    r16[ax] = 0x4c00;
    interrupt(33);
}
function* sub_100A9() {
    yield* sub_10103();
    memory[ds*16+0x9500] = 0x00;
    memory[ds*16+0x94FE] = 0x01;
    memory[ds*16+0x94FC] = 0x10;
    memory[ds*16+0x94FF] = 0x00;
    memory[ds*16+0x9502] = 0x00;
    yield* sub_10DA7();
    yield* sub_13423();
    yield* sub_121DC();
}
function* sub_100CF() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x100CF:
        yield* sub_101C0();
        yield* sub_10FDA();
        r8[al] = memory[ds*16+0x94FF];
        if (r8[al] != 0x00) {
            pc = 0x100E4;
            break;
        }
        yield* sub_132FE();
        yield* sub_10B8E();
        pc = 0x100ED;
        break;
    case 0x100E4:
        yield* sub_134A8();
        yield* sub_131A4();
        yield* sub_10B8E();
    case 0x100ED:
        yield* sub_1220D();
        yield* sub_13383();
        r8[al] = memory[ds*16+0x9500];
        if (r8[al] != 0x00)
            return;
        pc = 0x100CF;
        break;
        return;
    } while (1);
}
function* sub_100FD() {
    memory[ds*16+0x6] = 0x01;
}
function* sub_10103() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x6];
        if (r8[al] == 0x00) {
            pc = 0x10115;
            break;
        }
        memory16set(ds*16+0x8E7E, 0x00da);
        yield* sub_1279F();
        pc = 0x1011E;
        break;
    case 0x10115:
        memory16set(ds*16+0x8E7E, 0x00e9);
        yield* sub_128DA();
    case 0x1011E:
        yield* sub_139B8();
        yield* sub_13472();
        memory[ds*16+0x9503] = 0x01;
        memory16set(ds*16+0x8E80, 0x0000);
        yield* sub_10D98();
    case 0x10132:
        yield* sub_101C0();
        yield* sub_10FDA();
        yield* sub_13498();
        yield* sub_10B8E();
        yield* sub_13383();
        r16[ax] = memory16get(ds*16+0x954C);
        if (r16[ax] & 0x0080) {
            pc = 0x10197;
            break;
        }
        memory16set(ds*16+0x8E80, memory16get(ds*16+0x8E80) + 1);
        r16[bx] = memory16get(ds*16+0x8E80);
        if (r16[bx] & 0x0007) {
            pc = 0x10195;
            break;
        }
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+0x8E7E);
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] == 0x00) {
            pc = 0x10195;
            break;
        }
        if (r8[al] == 0xff) {
            pc = 0x10197;
            break;
        }
        if (r8[al] != 0xfe) {
            pc = 0x10180;
            break;
        }
        r8[al] = memory[ds*16+0x9546];
        if (r8[al] == 0x00) {
            pc = 0x1017B;
            break;
        }
        yield* sub_129DB();
        pc = 0x1017E;
        break;
    case 0x1017B:
        yield* sub_101AD();
    case 0x1017E:
        pc = 0x10195;
        break;
    case 0x10180:
        if (r8[al] & 0x80) {
            pc = 0x10189;
            break;
        }
        yield* sub_1019D();
        pc = 0x10195;
        break;
    case 0x10189:
        r8[al] &= 0x3f;
        push(r16[ax]);
        yield* sub_1019D();
        r16[ax] = pop();
        r8[al] += 1;
        yield* sub_1019D();
    case 0x10195:
        pc = 0x10132;
        break;
    case 0x10197:
        memory[ds*16+0x9503] = 0x00;
        return;
    } while (1);
}
function* sub_1019D() {
    si = 0x0109;
    memory[ds*16+si + 4] = r8[al];
    r16[bx] = 0x0120;
    yield* sub_12121();
    yield* sub_10B58();
}
function* sub_101AD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x1f40;
    case 0x101B0:
        push(r16[cx]);
        yield* sub_101C0();
        r16[cx] = pop();
        r16[ax] = memory16get(ds*16+0x954C);
        if (!(r8[al] & 0x80)) {
            pc = 0x101BD;
            break;
        }
        return;
    case 0x101BD:
        if (--r16[cx]) {
            pc = 0x101B0;
            break;
        }
        return;
    } while (1);
}
function* sub_101C0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x8e8a;
        si = 0x003d;
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101D5;
            break;
        }
        si = 0x003e;
    case 0x101CF:
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101CF;
            break;
        }
    case 0x101D5:
        si = 0x003b;
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101E1;
            break;
        }
        yield* sub_1033B();
    case 0x101E1:
        r16[bx] = 0x8e8a;
        si = memory16get(ds*16+0x8F0D);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101F6;
            break;
        }
        memory16set(ds*16+0x954C, 0x0001);
        pc = 0x1020E;
        break;
    case 0x101F6:
        si = memory16get(ds*16+0x8F0F);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x10208;
            break;
        }
        memory16set(ds*16+0x954C, 0x0002);
        pc = 0x1020E;
        break;
    case 0x10208:
        memory16set(ds*16+0x954C, 0x0000);
    case 0x1020E:
        si = memory16get(ds*16+0x8F11);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1021F;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0004);
        pc = 0x1022E;
        break;
    case 0x1021F:
        si = memory16get(ds*16+0x8F13);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1022E;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0008);
    case 0x1022E:
        si = memory16get(ds*16+0x8F15);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1023E;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0080);
    case 0x1023E:
        si = memory16get(ds*16+0x8F17);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1024D;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0040);
    case 0x1024D:
        si = memory16get(ds*16+0x8F19);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1025C;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0020);
    case 0x1025C:
        si = memory16get(ds*16+0x8F1B);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1028C;
            break;
        }
        yield* sub_12C45();
        r16[bx] = 0x8e8a;
    case 0x1026C:
        r8[al] = memory[ds*16+r16[bx] + 21];
        if (r8[al] != 0x00) {
            pc = 0x1027C;
            break;
        }
        r8[al] = memory[ds*16+r16[bx] + 49];
        if (r8[al] != 0x00) {
            pc = 0x1027C;
            break;
        }
        pc = 0x1026C;
        break;
    case 0x1027C:
        r16[bx] = 0x8e8a;
        r8[al] = memory[ds*16+r16[bx] + 21];
        if (r8[al] == 0x00) {
            pc = 0x10289;
            break;
        }
    {yield* loc_10096(); return; };
    case 0x10289:
        yield* sub_10529();
    case 0x1028C:
        r16[bx] = 0x8e8a;
        si = 0x003c;
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x102C5;
            break;
        }
        r8[al] = memory[ds*16+0x9505];
        if (r8[al] != 0x00) {
            pc = 0x102B0;
            break;
        }
        r8[al] = 0x0e;
        yield* sub_13840();
        memory[ds*16+0x9505] = 0x01;
        memory[ds*16+0x9506] = 0x00;
        pc = 0x102C3;
        break;
    case 0x102B0:
        if (r8[al] != 0x02) {
            pc = 0x102C3;
            break;
        }
        memory[ds*16+0x9505] = 0x03;
        memory[ds*16+0x9506] = 0x01;
        r8[al] = 0x0d;
        yield* sub_13840();
    case 0x102C3:
        pc = 0x102DC;
        break;
    case 0x102C5:
        r8[al] = memory[ds*16+0x9505];
        if (r8[al] != 0x01) {
            pc = 0x102D3;
            break;
        }
        memory[ds*16+0x9505] = 0x02;
        pc = 0x102DC;
        break;
    case 0x102D3:
        if (r8[al] != 0x03) {
            pc = 0x102DC;
            break;
        }
        memory[ds*16+0x9505] = 0x00;
    case 0x102DC:
        r8[al] = memory[ds*16+0x8F0A];
        if (r8[al] != 0x00) {
            pc = 0x102E4;
            break;
        }
        return;
    case 0x102E4:
        r16[ax] = 0x0003;
        interrupt(51);
        if (!(r16[bx] & 0x0001)) {
            pc = 0x102F5;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0080);
    case 0x102F5:
        if (!(r16[bx] & 0x0002)) {
            pc = 0x10300;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0020);
    case 0x10300:
        r16[ax] = memory16get(ds*16+0x954C);
        r16[ax] &= 0x000f;
        if (r16[ax] == 0) {
            pc = 0x10309;
            break;
        }
        return;
    case 0x10309:
        r16[ax] = 0x000b;
        interrupt(51);
        if (r16s[cx] >= signed16(0xfffb)) {
            pc = 0x1031A;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0001);
        pc = 0x10324;
        break;
    case 0x1031A:
        if (r16s[cx] <= signed16(0x0005)) {
            pc = 0x10324;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0002);
    case 0x10324:
        if (r16s[dx] >= signed16(0xfff6)) {
            pc = 0x10330;
            break;
        }
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0004);
        return;
    case 0x10330:
        if (r16s[dx] <= signed16(0x000a))
            return;
        memory16set(ds*16+0x954C, memory16get(ds*16+0x954C) | 0x0008);
        return;
    } while (1);
}
function* sub_1033B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_12C07();
        r8[al] = 0x04;
        yield* sub_12C9A();
        yield* sub_104F3();
        memory16set(ds*16+0x8F15, r16[ax]);
        r8[al] = 0x00;
        yield* sub_12C9A();
    case 0x1034E:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x1034E;
            break;
        }
        memory16set(ds*16+0x8F0D, r16[ax]);
        r8[al] = 0x01;
        yield* sub_12C9A();
    case 0x1035F:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x1035F;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x1035F;
            break;
        }
        memory16set(ds*16+0x8F0F, r16[ax]);
        r8[al] = 0x02;
        yield* sub_12C9A();
    case 0x10376:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x10376;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x10376;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0F)) {
            pc = 0x10376;
            break;
        }
        memory16set(ds*16+0x8F11, r16[ax]);
        r8[al] = 0x03;
        yield* sub_12C9A();
    case 0x10393:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0F)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F11)) {
            pc = 0x10393;
            break;
        }
        memory16set(ds*16+0x8F13, r16[ax]);
        r8[al] = 0x06;
        yield* sub_12C9A();
    case 0x103B6:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x103B6;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x103B6;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0F)) {
            pc = 0x103B6;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F11)) {
            pc = 0x103B6;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F13)) {
            pc = 0x103B6;
            break;
        }
        memory16set(ds*16+0x8F17, r16[ax]);
        r8[al] = 0x07;
        yield* sub_12C9A();
    case 0x103DF:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x103DF;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x103DF;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0F)) {
            pc = 0x103DF;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F11)) {
            pc = 0x103DF;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F13)) {
            pc = 0x103DF;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F17)) {
            pc = 0x103DF;
            break;
        }
        memory16set(ds*16+0x8F19, r16[ax]);
        r8[al] = 0x05;
        yield* sub_12C9A();
    case 0x1040E:
        yield* sub_104F3();
        if (r16[ax] == memory16get(ds*16+0x8F15)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0D)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F0F)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F11)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F13)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F17)) {
            pc = 0x1040E;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0x8F19)) {
            pc = 0x1040E;
            break;
        }
        memory16set(ds*16+0x8F1B, r16[ax]);
        yield* sub_10529();
        return;
    } while (1);
}
function* sub_10442() {
    var cs = _seg000;
    memory16set(ds*16+0x8F0B, 0x0000);
    memory16set(ds*16+0x8F0D, 0x004b);
    memory16set(ds*16+0x8F0F, 0x004d);
    memory16set(ds*16+0x8F11, 0x0048);
    memory16set(ds*16+0x8F13, 0x0050);
    memory16set(ds*16+0x8F15, 0x0039);
    memory16set(ds*16+0x8F17, 0x0031);
    memory16set(ds*16+0x8F19, 0x0032);
    memory16set(ds*16+0x8F1B, 0x0010);
    r16[ax] = ds;
    es = r16[ax];
    r16[ax] = 0x0000;
    r16[cx] = 0x0040;
    di = 0x8e8a;
    rep_stosw_data_forward();
    r8[al] = 0x09;
    r8[ah] = 0x35;
    interrupt(33);
    memory16set(ds*16+0x8E84, r16[bx]);
    memory16set(ds*16+0x8E82, es);
    push(ds);
    r16[dx] = 0x04b7;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x09;
    r8[ah] = 0x25;
    interrupt(33);
    ds = pop();
}
function* sub_104A5() {
    r16[dx] = memory16get(ds*16+0x8E84);
    r16[ax] = memory16get(ds*16+0x8E82);
    push(ds);
    ds = r16[ax];
    r8[al] = 0x09;
    r8[ah] = 0x25;
    interrupt(33);
    ds = pop();
}
function* loc_104E3() {
    r8[bl] &= 0x7f;
    memory[ds*16+r16[bx] + -29046] = 0x00;
    r8[al] = 0x20;
    out8(32, r8[al]);
    ds = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_104F3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
    case 0x104F4:
        si = 0x8e8a;
    case 0x104F7:
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x10520;
            break;
        }
        r16[ax] = si;
        r16[ax] -= 0x8e8b;
        if (r16[ax] == 0x003b) {
            pc = 0x10520;
            break;
        }
        if (r16[ax] == 0x003c) {
            pc = 0x10520;
            break;
        }
        if (r16[ax] == 0x003d) {
            pc = 0x10520;
            break;
        }
        if (r16[ax] == 0x003e) {
            pc = 0x10520;
            break;
        }
        if (r16[ax] == 0x002a) {
            pc = 0x10520;
            break;
        }
        if (r16[ax] == 0x0036) {
            pc = 0x10520;
            break;
        }
        return;
    case 0x10520:
        if (si != 0x8f0a) {
            pc = 0x104F7;
            break;
        }
        pc = 0x104F4;
        break;
        return;
    } while (1);
}
function* sub_10529() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x10529:
        si = 0x8e8a;
        r8[ah] = 0x00;
    case 0x1052E:
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x10535;
            break;
        }
        r8[ah] += 1;
    case 0x10535:
        if (si != 0x8f0a) {
            pc = 0x1052E;
            break;
        }
        if (r8[ah] != 0x00) {
            pc = 0x10529;
            break;
        }
        return;
    } while (1);
}
function* sub_10541() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x4e20;
    case 0x10544:
        si = 0x8e8a;
        r8[ah] = 0x00;
        flags.direction = false;
    case 0x1054A:
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x10557;
            break;
        }
        r8[ah] = 0x01;
        if (si != memory16get(ds*16+0x8F0B)) {
            pc = 0x1055F;
            break;
        }
    case 0x10557:
        if (si == 0x8f0a) {
            pc = 0x1055F;
            break;
        }
        pc = 0x1054A;
        break;
    case 0x1055F:
        _ASSERT(0);
        memory16set(ds*16+0x8F0B, si);
        si -= 0x8e8b;
        r8[al] = memory[ds*16+si + 90];
        if (r8[al] == 0x00) {
            pc = 0x10576;
            break;
        }
        if (r8s[al] >= 0 /*CHECK*/)
            return;
        r8[al] = 0x00;
        return;
    case 0x10576:
        pc = 0x10583;
        break;
    case 0x10578:
        if (r8[ah] != 0x00) {
            pc = 0x10583;
            break;
        }
        memory16set(ds*16+0x8F0B, 0x0000);
    case 0x10583:
        if (--r16[cx]) {
            pc = 0x10544;
            break;
        }
        r8[al] = 0x00;
        return;
    } while (1);
}
function* sub_10588() {
    r16[ax] = 0x0000;
    interrupt(51);
    memory[ds*16+0x8F0A] = r8[al];
}
function* sub_10591() {
    var cs = _seg000;
    r8[al] = 0x1c;
    r8[ah] = 0x35;
    interrupt(33);
    memory16set(ds*16+0x8E88, r16[bx]);
    memory16set(ds*16+0x8E86, es);
    push(ds);
    r16[dx] = 0x05ce;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x1c;
    r8[ah] = 0x25;
    interrupt(33);
    ds = pop();
    r8[al] = 0x36;
    out8(67, r8[al]);
    r16[ax] = 0x4d0e;
    out8(64, r8[al]);
    r8[al] = r8[ah];
    out8(64, r8[al]);
}
function* sub_105BC() {
    r16[dx] = memory16get(ds*16+0x8E88);
    r16[ax] = memory16get(ds*16+0x8E86);
    push(ds);
    ds = r16[ax];
    r8[al] = 0x1c;
    r8[ah] = 0x25;
    interrupt(33);
    ds = pop();
}
function* sub_105EC() {
    var cs = _seg000;
    push(ds);
    r16[dx] = 0x05fc;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x24;
    r8[ah] = 0x25;
    interrupt(33);
    ds = pop();
}
function* sub_10600() {
    r16[dx] = 0x01e2;
    r16[ax] = memory16get(ds*16+0x94E8);
    yield* sub_10637();
    r16[dx] = 0x01ea;
    r16[ax] = memory16get(ds*16+0x94EA);
    yield* sub_10637();
    r16[dx] = 0x01f2;
    r16[ax] = memory16get(ds*16+0x94EC);
    yield* sub_10637();
    r16[dx] = 0x01f9;
    r16[ax] = memory16get(ds*16+0x94EE);
    yield* sub_10637();
    r16[dx] = 0x0203;
    r16[ax] = memory16get(ds*16+0x94F0);
    yield* sub_10637();
    r16[dx] = 0x020b;
    r16[ax] = memory16get(ds*16+0x94F2);
    yield* sub_10637();
}
function* sub_10637() {
    memory16set(ds*16+0x8F20, r16[ax]);
    di = 0x0000;
    r16[cx] = 0x7d00;
    yield* sub_1064D();
}
function* sub_10644() {
    r16[ax] = ds;
    memory16set(ds*16+0x8F20, r16[ax]);
    yield* sub_1064D();
}
function* sub_1064D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(r16[cx]);
        r16[ax] = 0x3d00;
        interrupt(33);
        r16[cx] = pop();
        r16[dx] = pop();
        if (!flags.carry) {
            pc = 0x10659;
            break;
        }
        return;
    case 0x10659:
        memory16set(ds*16+0x8F1E, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds*16+0x8F20);
        push(ds);
        ds = r16[ax];
        r16[ax] = 0x3f00;
        interrupt(33);
        ds = pop();
        r16[ax] = 0x3e00;
        r16[bx] = memory16get(ds*16+0x8F1E);
        interrupt(33);
        return;
    } while (1);
}
function* sub_10674() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(r16[cx]);
        r16[cx] = 0x0000;
        r16[ax] = 0x3c00;
        interrupt(33);
        r16[cx] = pop();
        r16[dx] = pop();
        if (!flags.carry) {
            pc = 0x10683;
            break;
        }
        return;
    case 0x10683:
        memory16set(ds*16+0x8F1E, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] = 0x4000;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x10690;
            break;
        }
        return;
    case 0x10690:
        r16[ax] = 0x3e00;
        r16[bx] = memory16get(ds*16+0x8F1E);
        interrupt(33);
        return;
    } while (1);
}
function* sub_1069A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x9501];
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bl] = r8[bl] + memory[ds*16+0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = memory16get(ds*16+r16[bx] + 580);
        di = 0x9229;
        r16[cx] = 0x0040;
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = 0x0000;
        flags.direction = false;
        rep_stosw_data_forward();
        di = 0x9229;
    case 0x106C2:
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x106EB;
            break;
        }
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[ah] = r8[al];
        lodsb_data_forward();
        r8[al] <<= 1;
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[al] = 0x00;
        r16[ax] = r16[ax] | memory16get(ds*16+r16[bx] + 3287);
        r16[cx] = r16[ax];
        lodsb_data_forward();
        r8[al] = -r8[al];
        r8[al] += 0x3f;
        r8[al] <<= 1;
        r8[bl] = r8[al];
        memory16set(ds*16+r16[bx] + -28119 + 0x10000, memory16get(ds*16+r16[bx] + -28119 + 0x10000) | r16[cx]);
        pc = 0x106C2;
        break;
    case 0x106EB:
        r8[al] = memory[ds*16+0x9501];
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bl] = r8[bl] + memory[ds*16+0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = memory16get(ds*16+r16[bx] + 532);
        di = 0x8f29;
        r16[cx] = 0x0300;
        r8[bl] = 0x00;
    case 0x10708:
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1072C;
            break;
        }
        lodsb_data_forward();
        r8[dl] = r8[al];
        r8[dl] &= 0x3f;
        r8[al] &= 0xc0;
        if (r8[al] != 0) {
            pc = 0x1071A;
            break;
        }
        r8[bl] = 0x00;
        pc = 0x1072C;
        break;
    case 0x1071A:
        if (r8[al] != 0x40) {
            pc = 0x10722;
            break;
        }
        r8[bl] = 0x01;
        pc = 0x1072C;
        break;
    case 0x10722:
        if (r8[al] != 0x80) {
            pc = 0x1072A;
            break;
        }
        r8[bl] = 0x02;
        pc = 0x1072C;
        break;
    case 0x1072A:
        r8[bl] = 0x03;
    case 0x1072C:
        memory[ds*16+di] = r8[dl];
        di += 1;
        if (--r16[cx]) {
            pc = 0x10708;
            break;
        }
        di = 0x0000;
        r16[ax] = 0xa800;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r8[ah] = 0x00;
        r8[al] = 0x00;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x4000;
        rep_stosw_video_forward();
        r16[ax] = 0x8f29;
        memory16set(ds*16+0x8F25, r16[ax]);
        memory16set(ds*16+0x8F23, 0x03f0);
        r16[cx] = 0x0040;
    case 0x10759:
        push(r16[cx]);
        memory[ds*16+0x8F22] = 0x00;
        yield* sub_107AF();
        memory16set(ds*16+0x279, 0x0000);
        memory[ds*16+0x27D] = 0x08;
        memory16set(ds*16+0x283, memory16get(ds*16+0x283) + 0x0008);
        si = 0x0274;
        yield* sub_10BC5();
        memory16set(ds*16+0x279, 0x0008);
        memory[ds*16+0x27D] = 0x18;
        r16[cx] = 0x000a;
    case 0x10786:
        push(r16[cx]);
        yield* sub_107AF();
        si = 0x0274;
        yield* sub_10BC5();
        memory16set(ds*16+0x279, memory16get(ds*16+0x279) + 0x0018);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10786;
            break;
        }
        memory[ds*16+0x27D] = 0x08;
        yield* sub_107AF();
        si = 0x0274;
        yield* sub_10BC5();
        memory16set(ds*16+0x8F23, memory16get(ds*16+0x8F23) - 0x0010);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10759;
            break;
        }
        return;
    } while (1);
}
function* sub_107AF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x8F22];
        memory[ds*16+0x277] = r8[al];
        r16[bx] = memory16get(ds*16+0x8F25);
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        memory16set(ds*16+0x8F25, r16[bx]);
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 1309];
        memory[ds*16+0x27E] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 1393];
        memory[ds*16+0x8F22] += r8[al];
        r8[al] = memory[ds*16+r16[bx] + 1351];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+0x8F23);
        memory16set(ds*16+0x27B, r16[ax]);
        if (r16[bx] < 0x0026) {
            pc = 0x107EC;
            break;
        }
        memory16set(ds*16+0x281, 0x0002);
        pc = 0x107F2;
        break;
    case 0x107EC:
        memory16set(ds*16+0x281, 0x0004);
    case 0x107F2:
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 1519);
        memory16set(ds*16+0x283, r16[bx]);
        return;
    } while (1);
}
function* sub_107FD() {
    let var_8 = -8;
    let var_6 = -6;
    let var_4 = -4;
    let var_2 = -2;
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        sp -= 0x0008;
        r16[ax] = _stack16(bp + arg_2);
        r16[ax] += 0x0010;
        r8[cl] = 0x18;
        div(r8[cl]);
        push(r16[ax]);
        r8[ah] = 0x00;
        _stack16set(bp + var_2, r16[ax]);
        r16[ax] = pop();
        r8[al] = r8[ah];
        r8[ah] = 0x00;
        r8[cl] = 0x03;
        div(r8[cl]);
        r8[ah] = 0x00;
        _stack16set(bp + var_4, r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        r16[ax] &= 0x03ff;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] = -r16[ax];
        r16[ax] += 0x003f;
        _stack16set(bp + var_6, r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        r16[ax] &= 0x000f;
        r16[ax] >>= 1;
        _stack16set(bp + var_8, r16[ax]);
        r16[ax] = _stack16(bp + var_6);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] += 0x8f29;
        si = r16[bx];
        r16[bx] = r16[bx] + _stack16(bp + var_2);
        r8[al] = memory[ds*16+r16[bx]];
        r8[ah] = 0x00;
        push(r16[ax]);
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[bx] = memory16get(ds*16+r16[bx] + 1603);
        r16[ax] = _stack16(bp + var_8);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] = r16[bx] + _stack16(bp + var_4);
        r8[cl] = memory[ds*16+r16[bx]];
        push(r16[cx]);
        r8[cl] &= 0x1f;
        if (!(r8[cl] & 0x10)) {
            pc = 0x10881;
            break;
        }
        r8[cl] |= 0xe0;
    case 0x10881:
        r16[dx] = _stack16(bp + var_2);
        flags.direction = false;
    case 0x10885:
        if (r16[dx] == 0x0000) {
            pc = 0x10896;
            break;
        }
        lodsb_data_forward();
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r8[cl] = r8[cl] + memory[ds*16+r16[bx] + 1393];
        r16[dx] -= 1;
        pc = 0x10885;
        break;
    case 0x10896:
        r8[al] = r8[cl];
        _cbw();
        r16[cx] = pop();
        r16[bx] = pop();
        if (r8[cl] & 0x80) {
            pc = 0x108A6;
            break;
        }
        r8[bl] = memory[ds*16+r16[bx] + 1435];
        pc = 0x108AA;
        break;
    case 0x108A6:
        r8[bl] = memory[ds*16+r16[bx] + 1477];
    case 0x108AA:
        r8[bh] = 0x00;
        r16[cx] = _stack16(bp + var_6);
        r16[cx] = -r16[cx];
        r16[cx] += 0x003f;
        sp = bp;
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_108BA() {
    let arg_0 = 4;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = _stack16(bp + arg_0);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + -28119 + 0x10000);
        if (r16[ax] == 0x0000) {
            pc = 0x10946;
            break;
        }
        push(r16[ax]);
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        r8[bl] = r8[ah];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = memory16get(ds*16+r16[bx] + 651);
        if (r8[ah] < 0x0f) {
            pc = 0x10902;
            break;
        }
        if (r8[ah] > 0x14) {
            pc = 0x10902;
            break;
        }
        r8[ah] -= 0x0f;
        memory[ds*16+si + 1] = r8[ah];
        r8[bl] = r8[ah];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + -27346 + 0x10000];
        if (r8[al] == 0x00) {
            pc = 0x108F9;
            break;
        }
        r16[ax] = pop();
        pc = 0x10946;
        break;
    case 0x108F9:
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 814);
        memory16set(ds*16+si + 15, r16[ax]);
    case 0x10902:
        memory[ds*16+si + 19] = 0x0a;
        r16[ax] = _stack16(bp + arg_0);
        memory[ds*16+si + 20] = r8[al];
        r16[ax] = pop();
        r16[cx] = 0x000a;
    case 0x10910:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (!flags.carry) {
            pc = 0x10941;
            break;
        }
        push(r16[ax]);
        push(r16[cx]);
        yield* sub_1094A();
        r8[al] = memory[ds*16+si + 19];
        r8[ah] = 0x00;
        push(r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        push(r16[ax]);
        yield* sub_109E9();
        if (r16[ax] == 0x0000) {
            pc = 0x10932;
            break;
        }
        push(si);
        yield* sub_10B58();
        si = pop();
        pc = 0x1093F;
        break;
    case 0x10932:
        push(si);
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x1093E;
            break;
        }
        yield* sub_10A1B();
    case 0x1093E:
        si = pop();
    case 0x1093F:
        r16[cx] = pop();
        r16[ax] = pop();
    case 0x10941:
        memory[ds*16+si + 19] -= 1;
        if (--r16[cx]) {
            pc = 0x10910;
            break;
        }
    case 0x10946:
        bp = pop();
        _stackReduce(2);
        return;
    } while (1);
}
function* sub_1094A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = memory[ds*16+si + 19];
        push(si);
        r8[al] = 0x3f;
        r8[al] = r8[al] - memory[ds*16+si + 20];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[ah] = 0x00;
        si = r16[ax];
        r16[ax] <<= 1;
        si += r16[ax];
        si += 0x8f29;
        r8[cl] = 0x00;
        flags.direction = false;
    case 0x10966:
        if (r8[dl] == 0x00) {
            pc = 0x10978;
            break;
        }
        lodsb_data_forward();
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r8[cl] = r8[cl] + memory[ds*16+r16[bx] + 1393];
        r8[dl] -= 1;
        pc = 0x10966;
        break;
    case 0x10978:
        si = pop();
        memory[ds*16+si + 3] = r8[cl];
        r8[al] = memory[ds*16+si + 20];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+si + 19];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[cx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] -= 0x0004;
        memory16set(ds*16+si + 5, r16[ax]);
        return;
    } while (1);
}
function* sub_109A4() {
    di = 0x92a9;
    r16[cx] = 0x00c0;
    r16[ax] = ds;
    es = r16[ax];
    r16[ax] = 0xffff;
    flags.direction = false;
    rep_stosw_data_forward();
}
function* sub_109B5() {
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        si = _stack16(bp + arg_4);
        yield* sub_10A1B();
        r16[bx] = _stack16(bp + arg_2);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds*16+r16[bx] + 3307);
        r16[bx] = _stack16(bp + arg_0);
        r16[bx] <<= 1;
        r8[al] = memory[ds*16+0x9502];
        if (r8[al] != 0x01) {
            pc = 0x109D9;
            break;
        }
        r16[bx] += 0x0080;
        pc = 0x109E1;
        break;
    case 0x109D9:
        if (r8[al] != 0x02) {
            pc = 0x109E1;
            break;
        }
        r16[bx] += 0x0100;
    case 0x109E1:
        memory16set(ds*16+r16[bx] + -27991 + 0x10000, memory16get(ds*16+r16[bx] + -27991 + 0x10000) & r16[cx]);
        bp = pop();
        _stackReduce(6);
        return;
    } while (1);
}
function* sub_109E9() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = _stack16(bp + arg_2);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds*16+r16[bx] + 3307);
        r16[bx] = _stack16(bp + arg_0);
        r16[bx] <<= 1;
        r8[al] = memory[ds*16+0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10A07;
            break;
        }
        r16[bx] += 0x0080;
        pc = 0x10A0F;
        break;
    case 0x10A07:
        if (r8[al] != 0x02) {
            pc = 0x10A0F;
            break;
        }
        r16[bx] += 0x0100;
    case 0x10A0F:
        r16[cx] = (~r16[cx]);
        r16[ax] = memory16get(ds*16+r16[bx] + -27991 + 0x10000);
        r16[ax] &= r16[cx];
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_10A1B() {
    r8[al] = memory[ds*16+si + 18];
    r8[al] <<= 1;
    r8[bl] = r8[al];
    r8[bh] = 0x00;
    di = memory16get(ds*16+r16[bx] + 798);
    r8[al] = memory[ds*16+di];
    memory[ds*16+si] = r8[al];
    r8[al] = memory[ds*16+di + 9];
    memory[ds*16+si + 9] = r8[al];
    r8[al] = memory[ds*16+di + 10];
    memory[ds*16+si + 10] = r8[al];
    r8[al] = memory[ds*16+di + 11];
    memory[ds*16+si + 11] = r8[al];
    r8[al] = memory[ds*16+di + 12];
    memory[ds*16+si + 12] = r8[al];
    r16[ax] = memory16get(ds*16+di + 15);
    memory16set(ds*16+si + 15, r16[ax]);
    r8[al] = memory[ds*16+di + 18];
    memory[ds*16+si + 18] = r8[al];
}
function* sub_10A51() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16+0x1B9E];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = r16[bx];
        r8[al] = memory[ds*16+0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10A68;
            break;
        }
        si += 0x0080;
        pc = 0x10A70;
        break;
    case 0x10A68:
        if (r8[al] != 0x02) {
            pc = 0x10A70;
            break;
        }
        si += 0x0100;
    case 0x10A70:
        r16[ax] = memory16get(ds*16+si - 27991 + 0x10000);
        r16[ax] = r16[ax] & memory16get(ds*16+r16[bx] + -28119+ 0x10000);
        if (r16[ax] == 0x0000) {
            pc = 0x10AD1;
            break;
        }
        r8[bl] = r8[ah];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 693];
        if (r8[cl] == 0x00) {
            pc = 0x10AD1;
            break;
        }
        memory[ds*16+0x9429] = r8[cl];
        memory16set(ds*16+0x942C, 0x000a);
        r16[bx] <<= 1;
        r16[dx] = memory16get(ds*16+r16[bx] + 714);
        r16[bx] = memory16get(ds*16+r16[bx] + 756);
        r16[cx] = 0x000a;
    case 0x10AA5:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (!flags.carry) {
            pc = 0x10AC8;
            break;
        }
        push(r16[bx]);
        r16[bx] -= r16[dx];
        if (r16s[bx] > memory16gets(ds*16+0x1B8F)) {
            pc = 0x10AC7;
            break;
        }
        r16[bx] += r16[dx];
        r16[bx] += r16[dx];
        if (r16s[bx] < memory16gets(ds*16+0x1B8F)) {
            pc = 0x10AC7;
            break;
        }
        r16[ax] = pop();
        r8[al] = memory[ds*16+0x9429];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds*16+0x942C);
        return;
    case 0x10AC7:
        r16[bx] = pop();
    case 0x10AC8:
        r16[bx] -= 0x0018;
        memory16set(ds*16+0x942C, memory16get(ds*16+0x942C) - 1);
        if (--r16[cx]) {
            pc = 0x10AA5;
            break;
        }
    case 0x10AD1:
        r16[ax] = 0x0000;
        return;
    } while (1);
}
function* sub_10AD5() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = _stack16(bp + arg_0);
        r16[bx] <<= 1;
        si = r16[bx];
        r8[al] = memory[ds*16+0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10AEC;
            break;
        }
        si += 0x0080;
        pc = 0x10AF4;
        break;
    case 0x10AEC:
        if (r8[al] != 0x02) {
            pc = 0x10AF4;
            break;
        }
        si += 0x0100;
    case 0x10AF4:
        r16[ax] = memory16get(ds*16+si - 27991 + 0x10000);
        r16[ax] = r16[ax] & memory16get(ds*16+r16[bx] + -28119 + 0x10000);
        if (r16[ax] == 0x0000) {
            pc = 0x10B51;
            break;
        }
        r8[bl] = r8[ah];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 693];
        if (r8[cl] == 0x00) {
            pc = 0x10B51;
            break;
        }
        memory16set(ds*16+0x942C, 0x000a);
        r16[bx] <<= 1;
        r16[dx] = memory16get(ds*16+r16[bx] + 714);
        r16[dx] -= 0x000e;
        r16[bx] = memory16get(ds*16+r16[bx] + 756);
        r16[cx] = 0x000a;
    case 0x10B28:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (!flags.carry) {
            pc = 0x10B48;
            break;
        }
        push(r16[bx]);
        r16[bx] -= r16[dx];
        if (r16s[bx] > _stack16s(bp + arg_2)) {
            pc = 0x10B47;
            break;
        }
        r16[bx] += r16[dx];
        r16[bx] += r16[dx];
        if (r16s[bx] < _stack16s(bp + arg_2)) {
            pc = 0x10B47;
            break;
        }
        r16[ax] = pop();
        r16[ax] = 0x0001;
        r16[bx] = memory16get(ds*16+0x942C);
        pc = 0x10B54;
        break;
    case 0x10B47:
        r16[bx] = pop();
    case 0x10B48:
        r16[bx] -= 0x0018;
        memory16set(ds*16+0x942C, memory16get(ds*16+0x942C) - 1);
        if (--r16[cx]) {
            pc = 0x10B28;
            break;
        }
    case 0x10B51:
        r16[ax] = 0x0000;
    case 0x10B54:
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_10B58() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _dseg;
        es = r16[ax];
        di = 0x1b8a;
    case 0x10B60:
        r8[al] = memory[ds*16+di];
        if (r8[al] & 0x80) {
            pc = 0x10B78;
            break;
        }
        if (r8[al] & 0x01) {
            pc = 0x10B73;
            break;
        }
        push(di);
        r16[cx] = 0x0017;
        flags.direction = false;
        rep_movsb_data_data_forward();
        si = pop();
        return;
    case 0x10B73:
        di += 0x0017;
        pc = 0x10B60;
        break;
    case 0x10B78:
        si = 0x0000;
        return;
    } while (1);
}
function* sub_10B7C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x1b8a;
    case 0x10B7F:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80)
            return;
        memory[ds*16+si] = 0x00;
        si += 0x0017;
        pc = 0x10B7F;
        break;
        return;
    } while (1);
}
function* sub_10B8E() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x94F8);
        memory16set(ds*16+0x942E, r16[ax]);
        memory16set(cs*16+0xD93, 0x0028);
        memory16set(ds*16+0x9430, 0x0001);
        r16[cx] = 0x0007;
    case 0x10BA4:
        si = 0x1b8a;
    case 0x10BA7:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80) {
            pc = 0x10BC2;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x10BBD;
            break;
        }
        if (r8[cl] != memory[ds*16+si + 2]) {
            pc = 0x10BBD;
            break;
        }
        push(r16[cx]);
        push(si);
        yield* sub_10BDC();
        si = pop();
        r16[cx] = pop();
    case 0x10BBD:
        si += 0x0017;
        pc = 0x10BA7;
        break;
    case 0x10BC2:
        if (--r16[cx]) {
            pc = 0x10BA4;
            break;
        }
        return;
    } while (1);
}
function* sub_10BC5() {
    var cs = _seg000;
    r16[ax] = 0xa800;
    memory16set(ds*16+0x942E, r16[ax]);
    memory16set(cs*16+0xD93, 0x0020);
    memory16set(ds*16+0x9430, 0x0000);
    yield* sub_10BDC();
}
function* sub_10BDC() {
    var cs = _seg000;
    r8[al] = memory[ds*16+si + 11];
    _cbw();
    r16[bx] = memory16get(ds*16+si + 5);
    r16[bx] -= r16[ax];
    push(r16[bx]);
    r8[al] = memory[ds*16+si + 3];
    r8[al] = r8[al] + memory[ds*16+si + 12];
    _cbw();
    r16[ax] = -r16[ax];
    r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
    push(r16[ax]);
    r8[al] = memory[ds*16+si + 9];
    r8[ah] = 0x00;
    push(r16[ax]);
    r8[al] = memory[ds*16+si + 10];
    r8[ah] = 0x00;
    push(r16[ax]);
    r16[bx] = memory16get(ds*16+si + 13);
    r16[bx] = memory16get(ds*16+r16[bx] + -27416 + 0x10000);
    r8[al] = memory[ds*16+si + 17];
    memory[cs*16+0xD95] = r8[al];
    r8[cl] = r8[al];
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[al] |= r8[cl];
    memory[cs*16+0xD96] = r8[al];
    si = memory16get(ds*16+si + 15);
    yield* sub_10C24();
}
function* sub_10C24() {
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    let arg_6 = 10;
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ds*16+0x9430);
        if (r16[ax] != 0x0000) {
            pc = 0x10C32;
            break;
        }
        pc = 0x10CBC;
        break;
    case 0x10C32:
        r16[ax] = _stack16(bp + arg_4);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9528);
        r16[ax] &= 0x03ff;
        if (!(r16[ax] & 0x0200)) {
            pc = 0x10C44;
            break;
        }
        r16[ax] |= 0xfc00;
    case 0x10C44:
        _stack16set(bp + arg_4, r16[ax]);
        if (r16s[ax] >= signed16(0x0000)) {
            pc = 0x10C77;
            break;
        }
        flags.sign = signed16(_stack16(bp + arg_0) + r16[ax]) < 0;
        _stack16set(bp + arg_0, _stack16(bp + arg_0) + r16[ax]);
        if (!flags.sign) {
            pc = 0x10C54;
            break;
        }
        pc = 0x10D8F;
        break;
    case 0x10C54:
        if (_stack16(bp + arg_0) != 0) {
            pc = 0x10C59;
            break;
        }
        pc = 0x10D8F;
        break;
    case 0x10C59:
        r16[ax] = -r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[cx] += r16[ax];
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        si += r16[cx];
        r16[ax] = 0x0000;
        _stack16set(bp + arg_4, r16[ax]);
        pc = 0x10C8F;
        break;
    case 0x10C77:
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        r16[ax] -= 0x00a0;
        if (r16s[ax] < 0) {
            pc = 0x10C8F;
            break;
        }
        r16[ax] = -r16[ax];
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x10C8C;
            break;
        }
        pc = 0x10D8F;
        break;
    case 0x10C8C:
        _stack16set(bp + arg_0, r16[ax]);
    case 0x10C8F:
        r16[ax] = 0x0020;
        _stack16set(bp + arg_6, _stack16(bp + arg_6) + r16[ax]);
        r16[ax] = 0x0008;
        _stack16set(bp + arg_4, _stack16(bp + arg_4) + r16[ax]);
        r16[ax] = _stack16(bp + arg_6);
        if (r16s[ax] >= signed16(0x0020)) {
            pc = 0x10CAB;
            break;
        }
        r16[ax] = 0x0020;
        _stack16(bp + arg_6, r16[ax]);
        pc = 0x10CBC;
        break;
    case 0x10CAB:
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        if (r16s[ax] <= signed16(0x0120)) {
            pc = 0x10CBC;
            break;
        }
        r16[ax] = 0x0120;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        _stack16set(bp + arg_6, r16[ax]);
    case 0x10CBC:
        push(ds);
        push(r16[bx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0a05;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0007;
        out16(r16[dx], r16[ax]);
        r16[ax] = _stack16(bp + arg_6);
        r16[bx] = _stack16(bp + arg_4);
        push(r16[cx]);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[cx] = memory16get(cs*16+0xD93);
        if (r16[cx] != 0x0028) {
            pc = 0x10CE4;
            break;
        }
        di = r16[bx];
        pc = 0x10CE7;
        break;
    case 0x10CE4:
        di = 0x0000;
    case 0x10CE7:
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        di += r16[bx];
        r8[cl] = r8[al];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        di += r16[ax];
        r8[cl] &= 0x07;
        r16[ax] = 0x0080;
        r16[ax] >>= r8[cl];
        r8[ah] = r8[al];
        r16[bx] = memory16get(ds*16+0x942E);
        es = r16[bx];
        r16[cx] = pop();
        r16[cx] = _stack16(bp + arg_2);
        r16[cx] >>= 1;
        r8[al] = 0x08;
        ds = pop();
        r16[bx] = _stack16(bp + arg_0);
    case 0x10D13:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(di);
        push(si);
    case 0x10D18:
        r8[bh] = memory[cs*16+0xD96];
    case 0x10D1D:
        r8[bl] = memory[ds*16+si];
        si += 1;
        if (r8[bh] != r8[bl]) {
            pc = 0x10D3A;
            break;
        }
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10D2F;
            break;
        }
        r8[ah] = 0x40;
        di += 1;
        if (--r16[cx]) {
            pc = 0x10D1D;
            break;
        }
        pc = 0x10D6D;
        break;
    case 0x10D2F:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10D36;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x10D36:
        if (--r16[cx]) {
            pc = 0x10D1D;
            break;
        }
        pc = 0x10D6D;
        break;
    case 0x10D3A:
        r8[bh] = r8[bl];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        if (r8[bl] == memory[cs*16+0xD95]) {
            pc = 0x10D4F;
            break;
        }
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, di, r8[bl]);
    case 0x10D4F:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10D56;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x10D56:
        r8[bh] &= 0x0f;
        if (r8[bh] == memory[cs*16+0xD95]) {
            pc = 0x10D64;
            break;
        }
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, di, r8[bh]);
    case 0x10D64:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10D6B;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x10D6B:
        if (--r16[cx]) {
            pc = 0x10D18;
            break;
        }
    case 0x10D6D:
        si = pop();
        si += 0x00a0;
        di = pop();
        di = di + memory16get(cs*16+0xD93);
        di &= 0x7fff;
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x10D13;
            break;
        }
        ds = pop();
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f07;
        out16(r16[dx], r16[ax]);
    case 0x10D8F:
        bp = pop();
        _stackReduce(8);
        return;
    } while (1);
}
function* sub_10D98() {
    memory16set(ds*16+0x9528, 0x001a);
    memory[ds*16+0x9513] = 0x00;
    yield* sub_10B7C();
}
function* sub_10DA7() {
    yield* sub_109A4();
    yield* sub_1069A();
    memory[ds*16+0x9519] = 0x00;
    memory[ds*16+0x951A] = 0x00;
    memory[ds*16+0x951B] = 0x00;
    yield* sub_10E3D();
}
function* sub_10DC0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x94FE] += 1;
        r8[al] = memory[ds*16+0x94FE];
        if (r8[al] < 0x06) {
            pc = 0x10DD3;
            break;
        }
        memory16set(ds*16+0x94FC, 0x0030);
        pc = 0x10DE5;
        break;
    case 0x10DD3:
        if (r8[al] < 0x03) {
            pc = 0x10DDF;
            break;
        }
        memory16set(ds*16+0x94FC, 0x0020);
        pc = 0x10DE5;
        break;
    case 0x10DDF:
        memory16set(ds*16+0x94FC, 0x0010);
    case 0x10DE5:
        memory[ds*16+0x9501] += 1;
        r8[al] = memory[ds*16+0x9501];
        if (r8[al] <= 0x07) {
            pc = 0x10DF5;
            break;
        }
        memory[ds*16+0x9501] = 0x01;
    case 0x10DF5:
        yield* sub_109A4();
        yield* sub_1069A();
        memory[ds*16+0x9519] = 0x00;
        yield* sub_10E3D();
        yield* sub_12A7F();
        return;
    } while (1);
}
function* sub_10E07() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9534);
        if (r16[ax] != 0x0000) {
            pc = 0x10E15;
            break;
        }
        memory[ds*16+0x9500] = 0x01;
        return;
    case 0x10E15:
        yield* sub_12329();
        r8[al] = memory[ds*16+0x9502];
        if (r8[al] == 0x00) {
            pc = 0x10E27;
            break;
        }
        memory[ds*16+0x9502] = 0x00;
        yield* sub_1069A();
    case 0x10E27:
        yield* sub_12200();
        memory[ds*16+0x9519] = 0x01;
        memory[ds*16+0x951A] = 0x00;
        memory[ds*16+0x951B] = 0x00;
        yield* sub_10E3D();
        return;
    } while (1);
}
function* sub_10E3D() {
    r8[bl] = memory[ds*16+0x9501];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + 5365);
    r16[ax] &= 0x03ff;
    memory16set(ds*16+0x9528, r16[ax]);
    r16[ax] = memory16get(ds*16+0x94FC);
    memory16set(ds*16+0x952A, r16[ax]);
    memory16set(ds*16+0x950A, 0x0080);
    memory[ds*16+0x950E] = 0x00;
    memory16set(ds*16+0x950F, 0x0000);
    memory16set(ds*16+0x9511, 0x0000);
    memory[ds*16+0x9513] = 0x00;
    memory[ds*16+0x9515] = 0x00;
    memory[ds*16+0x9517] = 0x00;
    memory[ds*16+0x9432] = 0x00;
    yield* sub_10E84();
}
function* sub_10E84() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x950E];
        if (r8[al] == 0x00) {
            pc = 0x10E93;
            break;
        }
        memory[ds*16+0x950E] = 0x00;
        yield* sub_1069A();
    case 0x10E93:
        memory16set(ds*16+0x952C, 0x0000);
        yield* sub_10B7C();
        si = 0x0d32;
        yield* sub_10B58();
        r16[ax] = memory16get(ds*16+0x950A);
        memory16set(ds*16+0x1B8F, r16[ax]);
        yield* sub_11B57();
        r16[ax] = memory16get(ds*16+0x9528);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] -= 0x0003;
        r16[ax] &= 0x003f;
        memory16set(ds*16+0x9507, r16[ax]);
        r16[cx] = 0x000f;
    case 0x10EC2:
        push(r16[cx]);
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_108BA();
        r16[ax] = pop();
        r16[cx] = pop();
        r16[ax] += 1;
        r16[ax] &= 0x003f;
        if (--r16[cx]) {
            pc = 0x10EC2;
            break;
        }
        r8[al] = memory[ds*16+0x9432];
        if (r8[al] == 0x00) {
            pc = 0x10EEA;
            break;
        }
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        memory[ds*16+si + 4] = 0x0a;
        yield* sub_12121();
        memory[ds*16+0x1B9C] = 0x23;
        return;
    case 0x10EEA:
        r8[al] = memory[ds*16+0x9519];
        if (r8[al] == 0x00) {
            pc = 0x10F08;
            break;
        }
        memory[ds*16+0x9519] = 0x00;
        si = 0x0da2;
        r16[ax] = memory16get(ds*16+0x1B91);
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0x1B8D];
        memory[ds*16+si + 3] = r8[al];
        yield* sub_10B58();
    case 0x10F08:
        yield* sub_10F9D();
        r8[al] = memory[ds*16+0x951A];
        if (r8[al] == 0x00) {
            pc = 0x10F23;
            break;
        }
        memory[ds*16+0x951A] = 0x01;
        si = 0x0dc3;
        memory[ds*16+si] &= 0xdf;
        yield* sub_11CD9();
        yield* sub_10B58();
    case 0x10F23:
        r8[al] = memory[ds*16+0x951B];
        if (r8[al] == 0x00)
            return;
        memory[ds*16+0x951B] = 0x01;
        si = 0x0dc3;
        memory[ds*16+si] |= 0x20;
        yield* sub_11CD9();
        yield* sub_10B58();
        return;
    } while (1);
}
function* sub_10F3C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x951C] = 0x00;
        yield* sub_12DDC();
        memory16set(ds*16+0x9528, 0x001a);
        memory16set(ds*16+0x9547, 0x0000);
        memory16set(ds*16+0x951E, 0x0000);
        memory[ds*16+0x9524] = 0x00;
        memory[ds*16+0x9549] = 0x03;
        yield* sub_10B7C();
        si = 0x0d04;
        yield* sub_10B58();
        yield* sub_12DF6();
        r8[al] = memory[ds*16+0x951A];
        if (r8[al] == 0x00) {
            pc = 0x10F84;
            break;
        }
        memory[ds*16+0x951A] = 0x01;
        si = 0x0d1b;
        memory[ds*16+si] &= 0xdf;
        yield* sub_12F50();
        yield* sub_10B58();
    case 0x10F84:
        r8[al] = memory[ds*16+0x951B];
        if (r8[al] == 0x00)
            return;
        memory[ds*16+0x951B] = 0x01;
        si = 0x0d1b;
        memory[ds*16+si] |= 0x20;
        yield* sub_12F50();
        yield* sub_10B58();
        return;
    } while (1);
}
function* sub_10F9D() {
    r16[ax] = memory16get(ds*16+0x1B8F);
    memory16set(ds*16+0x9433, r16[ax]);
    memory16set(ds*16+0x9435, r16[ax]);
    memory16set(ds*16+0x9437, r16[ax]);
    memory16set(ds*16+0x9439, r16[ax]);
    r16[ax] = memory16get(ds*16+0x1B91);
    memory16set(ds*16+0x943B, r16[ax]);
    memory16set(ds*16+0x943D, r16[ax]);
    memory16set(ds*16+0x943F, r16[ax]);
    memory16set(ds*16+0x9441, r16[ax]);
    r8[al] = memory[ds*16+0x1B8E];
    memory[ds*16+0x9443] = r8[al];
    memory[ds*16+0x9444] = r8[al];
    memory[ds*16+0x9445] = r8[al];
    memory[ds*16+0x9446] = r8[al];
    r8[al] = memory[ds*16+0x1B8D];
    memory[ds*16+0x9447] = r8[al];
    memory[ds*16+0x9448] = r8[al];
    memory[ds*16+0x9449] = r8[al];
    memory[ds*16+0x944A] = r8[al];
}
function* sub_10FDA() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x10FDA:
        r8[al] = memory[ds*16+0x94FF];
        memory[ds*16+0x9509] = r8[al];
        si = 0x1b8a;
    case 0x10FE3:
        r8[al] = memory[ds*16+0x9513];
        if (r8[al] == 0x00) {
            pc = 0x10FF5;
            break;
        }
        yield* sub_10E07();
        r8[al] = memory[ds*16+0x9500];
        if (r8[al] == 0x00) {
            pc = 0x10FDA;
            break;
        }
        return;
    case 0x10FF5:
        r8[al] = memory[ds*16+0x94FF];
        if (r8[al] == memory[ds*16+0x9509]) {
            pc = 0x11036;
            break;
        }
        if (r8[al] != 0x01) {
            pc = 0x1100E;
            break;
        }
        r8[al] = 0x0b;
        yield* sub_13840();
        yield* sub_10F3C();
        pc = 0x10FDA;
        break;
        pc = 0x11036;
        break;
    case 0x1100E:
        r8[al] = 0x0b;
        yield* sub_13840();
        r8[al] = memory[ds*16+0x951D];
        if (r8[al] != 0xf0) {
            pc = 0x1101F;
            break;
        }
        yield* sub_10DC0();
        pc = 0x11034;
        break;
    case 0x1101F:
        r8[al] = memory[ds*16+0x1BA0];
        r8[al] &= 0x7f;
        if (r8[al] <= 0x28) {
            pc = 0x11031;
            break;
        }
        if (r8[al] >= 0x58) {
            pc = 0x11031;
            break;
        }
        memory[ds*16+0x9432] = 0x01;
    case 0x11031:
        yield* sub_10E84();
    case 0x11034:
        pc = 0x10FDA;
        break;
    case 0x11036:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80)
            return;
        if (!(r8[al] & 0x02)) {
            pc = 0x11054;
            break;
        }
        push(si);
        r8[bl] = memory[ds*16+si + 18];
        if (r8[bl] == 0x00) {
            pc = 0x11053;
            break;
        }
        r8[bh] = 0x00;
        r16[bx] -= 1;
        r16[bx] <<= 1;
        switch (r16[bx] << 1)
        {
        case 0: yield* sub_11108(); break;
        case 4: yield* sub_1176C(); break;
        case 8: yield* sub_11783(); break;
        case 12: yield* sub_110C6(); break;
        case 16: yield* sub_117AC(); break;
        case 20: yield* sub_117D6(); break;
        case 24: yield* sub_118A9(); break;
        case 28: yield* sub_11A9E(); break;
        case 32: yield* sub_110C6(); break;
        case 36: yield* sub_11993(); break;
        case 40: yield* sub_119C2(); break;
        case 44: yield* sub_12E02(); break;
        case 48: yield* sub_110C6(); break;
        case 52: yield* sub_12FE8(); break;
        case 56: yield* sub_1300A(); break;
        case 60: yield* sub_116FE(); break;
        case 64: yield* sub_112CB(); break;
        case 68: yield* sub_110C6(); break;
        case 72: yield* sub_112EB(); break;
        case 76: yield* sub_115FC(); break;
        case 80: yield* sub_116DF(); break;
        case 84: yield* sub_116D6(); break;
        case 88: yield* sub_11740(); break;
        case 92: yield* sub_11384(); break;
        case 96: yield* sub_113A8(); break;
        case 100: yield* sub_114F0(); break;
        case 104: yield* sub_110F3(); break;
        case 108: yield* sub_118C7(); break;
        case 112: yield* sub_11429(); break;
        case 116: yield* sub_117F4(); break;
        case 120: yield* sub_1171F(); break;
        case 124: yield* sub_11B09(); break;
        case 128: yield* sub_11B4A(); break;
        case 132: yield* sub_12F50(); break;
        case 136: yield* sub_112A7(); break;
            default:
            _ASSERT(0);
        }
    case 0x11053:
        si = pop();
    case 0x11054:
        si += 0x0017;
        pc = 0x10FE3;
        break;
        return;
    } while (1);
}
function* sub_110A0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si + 10];
        r8[al] = r8[al] - memory[ds*16+si + 3];
        r8[al] = r8[al] - memory[ds*16+si + 12];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
        r16[ax] &= 0x03ff;
        r16[bx] = memory16get(ds*16+0x9528);
        if (r16[ax] >= r16[bx]) {
            pc = 0x110BB;
            break;
        }
        r16[ax] += 0x0400;
    case 0x110BB:
        r16[ax] -= r16[bx];
        if (r16[ax] <= 0x0200)
            return;
        memory[ds*16+si] = 0x00;
        return;
    } while (1);
}
function* sub_110C6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si + 3];
        r8[al] = r8[al] + memory[ds*16+si + 12];
        _cbw();
        r16[ax] = -r16[ax];
        r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
        r16[ax] &= 0x03ff;
        r16[bx] = memory16get(ds*16+0x9528);
        r16[bx] += 0x00a0;
        r16[bx] &= 0x03ff;
        if (r16[ax] >= r16[bx]) {
            pc = 0x110E8;
            break;
        }
        r16[ax] += 0x0400;
    case 0x110E8:
        r16[ax] -= r16[bx];
        if (r16[ax] >= 0x0200)
            return;
        memory[ds*16+si] = 0x00;
        return;
    } while (1);
}
function* sub_110F3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si + 22] += 1;
        r8[al] = memory[ds*16+si + 22];
        if (r8[al] <= 0x08) {
            pc = 0x110FF;
            break;
        }
        r8[al] = 0x08;
    case 0x110FF:
        r8[ah] = 0x00;
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) - r16[ax]);
        yield* sub_110A0();
        return;
    } while (1);
}
function* sub_11108() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_11B80();
        yield* sub_11BB9();
        r16[bx] = memory16get(ds*16+0x954C);
        r16[ax] = memory16get(ds*16+0x952C);
        if (!(r8[bl] & 0x01)) {
            pc = 0x11131;
            break;
        }
        r16[ax] -= 0x0001;
        if (r16s[ax] < 0) {
            pc = 0x11127;
            break;
        }
        if (r16s[ax] <= signed16(0x0004)) {
            pc = 0x11127;
            break;
        }
        r16[ax] = 0x0004;
    case 0x11127:
        if (r16s[ax] >= signed16(0xffe8)) {
            pc = 0x1112F;
            break;
        }
        r16[ax] = 0xffe8;
    case 0x1112F:
        pc = 0x11158;
        break;
    case 0x11131:
        if (!(r8[bl] & 0x02)) {
            pc = 0x1114D;
            break;
        }
        flags.sign = signed16(r16[ax] + 0x0001) < 0;
        r16[ax] += 0x0001;
        if (!flags.sign) {
            pc = 0x11143;
            break;
        }
        if (r16s[ax] >= signed16(0xfffc)) {
            pc = 0x11143;
            break;
        }
        r16[ax] = 0xfffc;
    case 0x11143:
        if (r16s[ax] <= signed16(0x0018)) {
            pc = 0x1114B;
            break;
        }
        r16[ax] = 0x0018;
    case 0x1114B:
        pc = 0x11158;
        break;
    case 0x1114D:
        if (r16[ax] == 0x0000) {
            pc = 0x11158;
            break;
        }
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x11157;
            break;
        }
        r16[ax] -= 1;
        pc = 0x11158;
        break;
    case 0x11157:
        r16[ax] += 1;
    case 0x11158:
        memory16set(ds*16+0x952C, r16[ax]);
        r16[ax] += 0x0003;
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] = r16[ax] + memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= signed16(0x0014)) {
            pc = 0x11174;
            break;
        }
        r16[ax] = 0x0014;
        memory16set(ds*16+0x952C, 0x0000);
    case 0x11174:
        if (r16s[ax] <= signed16(0x00ec)) {
            pc = 0x11182;
            break;
        }
        r16[ax] = 0x00ec;
        memory16set(ds*16+0x952C, 0x0000);
    case 0x11182:
        memory16set(ds*16+0x1B8F, r16[ax]);
        r8[al] = memory[ds*16+0x1B8E];
        if (r8[al] == 0x00) {
            pc = 0x1118F;
            break;
        }
        yield* sub_11B57();
    case 0x1118F:
        yield* sub_11C78();
        yield* sub_10A51();
        if (r16[ax] == 0x0000) {
            pc = 0x1119F;
            break;
        }
        yield* sub_11C56();
        pc = 0x111BC;
        break;
    case 0x1119F:
        memory[ds*16+0x1B9E] += 1;
        memory[ds*16+0x1B9E] &= 0x3f;
        yield* sub_10A51();
        if (r16[ax] == 0x0000) {
            pc = 0x111B3;
            break;
        }
        yield* sub_11C56();
    case 0x111B3:
        memory[ds*16+0x1B9E] -= 1;
        memory[ds*16+0x1B9E] &= 0x3f;
    case 0x111BC:
        r16[ax] = memory16get(ds*16+0x9542);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x111C8;
            break;
        }
        yield* sub_11C33();
        return;
    case 0x111C8:
        r8[al] = memory[ds*16+0x1B8E];
        if (r8[al] != 0x00) {
            pc = 0x111DE;
            break;
        }
        memory[ds*16+0x9515] += 1;
        r8[al] = memory[ds*16+0x9515];
        if (r8[al] < 0x04)
            return;
        yield* sub_11C33();
        return;
    case 0x111DE:
        r16[ax] = memory16get(ds*16+0x953E);
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x111F0;
            break;
        }
        r16[ax] = memory16get(ds*16+0x954C);
        if (!(r8[al] & 0x80)) {
            pc = 0x111F0;
            break;
        }
        yield* sub_11D1E();
    case 0x111F0:
        r16[ax] = memory16get(ds*16+0x954C);
        r8[bl] = memory[ds*16+0x951A];
        if (!(r8[al] & 0x40)) {
            pc = 0x11235;
            break;
        }
        if (r8[bl] != 0x00) {
            pc = 0x11224;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9536);
        if (r16[ax] <= 0x0000) {
            pc = 0x11222;
            break;
        }
        memory[ds*16+0x951A] = 0x01;
        si = 0x0dc3;
        memory[ds*16+si] &= 0xdf;
        yield* sub_11CD9();
        yield* sub_10B58();
        memory16set(ds*16+0x9538, memory16get(ds*16+0x9538) - 1);
        r8[al] = 0x01;
        yield* sub_13840();
    case 0x11222:
        pc = 0x11233;
        break;
    case 0x11224:
        if (r8[bl] != 0x02) {
            pc = 0x11233;
            break;
        }
        memory[ds*16+0x951A] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
    case 0x11233:
        pc = 0x1124B;
        break;
    case 0x11235:
        if (r8[bl] != 0x01) {
            pc = 0x11241;
            break;
        }
        memory[ds*16+0x951A] = 0x02;
        pc = 0x1124B;
        break;
    case 0x11241:
        if (r8[bl] != 0x03) {
            pc = 0x1124B;
            break;
        }
        memory[ds*16+0x951A] = 0x00;
    case 0x1124B:
        r16[ax] = memory16get(ds*16+0x954C);
        r8[bl] = memory[ds*16+0x951B];
        if (!(r8[al] & 0x20)) {
            pc = 0x11290;
            break;
        }
        if (r8[bl] != 0x00) {
            pc = 0x1127F;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9536);
        if (r16[ax] <= 0x0000) {
            pc = 0x1127D;
            break;
        }
        memory[ds*16+0x951B] = 0x01;
        si = 0x0dc3;
        memory[ds*16+si] |= 0x20;
        yield* sub_11CD9();
        yield* sub_10B58();
        memory16set(ds*16+0x9538, memory16get(ds*16+0x9538) - 1);
        r8[al] = 0x01;
        yield* sub_13840();
    case 0x1127D:
        pc = 0x1128E;
        break;
    case 0x1127F:
        if (r8[bl] != 0x02) {
            pc = 0x1128E;
            break;
        }
        memory[ds*16+0x951B] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
    case 0x1128E:
        return;
    case 0x11290:
        if (r8[bl] != 0x01) {
            pc = 0x1129C;
            break;
        }
        memory[ds*16+0x951B] = 0x02;
        return;
    case 0x1129C:
        if (r8[bl] != 0x03)
            return;
        memory[ds*16+0x951B] = 0x00;
        return;
    } while (1);
}
function* sub_112A7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x952A);
        r16[ax] -= 0x0003;
        if (r16s[ax] < 0) {
            pc = 0x112B4;
            break;
        }
        memory16set(ds*16+0x952A, r16[ax]);
        pc = 0x112B7;
        break;
    case 0x112B4:
        yield* sub_11C33();
    case 0x112B7:
        yield* sub_11BB9();
        yield* sub_11B57();
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        memory[ds*16+si + 4] = 0x0a;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_112CB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x952A);
        r16[ax] -= 1;
        if (r16s[ax] < 0) {
            pc = 0x112D4;
            break;
        }
        memory16set(ds*16+0x952A, r16[ax]);
    case 0x112D4:
        yield* sub_11BB9();
        yield* sub_11B57();
        memory[ds*16+0x9514] += 1;
        r8[al] = memory[ds*16+0x9514];
        if (r8[al] < 0x28)
            return;
        memory[ds*16+0x9513] = 0x01;
        return;
    } while (1);
}
function* sub_112EB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110A0();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x112F5;
            break;
        }
        return;
    case 0x112F5:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) - 0x0010);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        r8[al] = memory[ds*16+si + 4];
        if (r8[al] != 0x01) {
            pc = 0x11312;
            break;
        }
        r8[al] = memory[ds*16+si + 3];
        if (r8s[al] <= signed8(0x9c)) {
            pc = 0x11310;
            break;
        }
        memory[ds*16+si + 3] -= 0x08;
    case 0x11310:
        pc = 0x11321;
        break;
    case 0x11312:
        if (r8[al] != 0x02) {
            pc = 0x11321;
            break;
        }
        r8[al] = memory[ds*16+si + 3];
        if (r8s[al] >= signed8(0x64)) {
            pc = 0x11321;
            break;
        }
        memory[ds*16+si + 3] += 0x08;
    case 0x11321:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        push(r16[ax]);
        yield* sub_107FD();
        si = pop();
        if (r8s[al] < memorys[ds*16+si + 3]) {
            pc = 0x11338;
            break;
        }
        yield* sub_12092();
        return;
    case 0x11338:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        memory[ds*16+si + 20] = r8[cl];
        push(r16[cx]);
        yield* sub_10AD5();
        si = pop();
        if (r16[ax] == 0x0000)
            return;
        push(si);
        r8[al] = memory[ds*16+si + 20];
        r8[ah] = 0x00;
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_11C0A();
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80) {
            pc = 0x11382;
            break;
        }
        r16[bx] = pop();
        push(r16[bx]);
        r8[al] = memory[ds*16+si + 3];
        r8[al] = r8[al] - memory[ds*16+r16[bx] + 3];
        if (r8s[al] >= 0) {
            pc = 0x11367;
            break;
        }
        r8[al] = -r8[al];
    case 0x11367:
        if (r8[al] >= 0x10) {
            pc = 0x11382;
            break;
        }
        memory[ds*16+si + 21] -= 1;
        if (memorys[ds*16+si + 21] >= 0) {
            pc = 0x1137A;
            break;
        }
        yield* sub_120DB();
        r8[al] = 0x06;
        yield* sub_13840();
        pc = 0x1137D;
        break;
    case 0x1137A:
        yield* sub_12662();
    case 0x1137D:
        si = pop();
        push(si);
        yield* sub_12047();
    case 0x11382:
        si = pop();
        return;
    } while (1);
}
function* sub_11384() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x1138E;
            break;
        }
        memory[ds*16+si] = 0x00;
    case 0x1138E:
        yield* sub_11CD9();
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x20) {
            pc = 0x1139C;
            break;
        }
        r8[al] = memory[ds*16+0x951A];
        pc = 0x1139F;
        break;
    case 0x1139C:
        r8[al] = memory[ds*16+0x951B];
    case 0x1139F:
        if (r8[al] != 0x03)
            return;
        memory[ds*16+si + 18] = 0x19;
        return;
    } while (1);
}
function* sub_113A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110A0();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x113B2;
            break;
        }
        return;
    case 0x113B2:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) - 0x0006);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        push(r16[ax]);
        yield* sub_107FD();
        si = pop();
        r8[al] += 0x04;
        memory[ds*16+si + 3] = r8[al];
        memory[ds*16+si + 20] = r8[cl];
        memory[ds*16+si + 4] = r8[bl];
        r16[bx] = 0x0dda;
        yield* sub_12121();
        r8[al] = memory[ds*16+si + 4];
        if (r8[al] != 0x00) {
            pc = 0x113F5;
            break;
        }
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0004);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        memory[ds*16+si + 21] -= 1;
        if (memorys[ds*16+si + 21] >= 0) {
            pc = 0x113F5;
            break;
        }
        yield* sub_120F0();
        memory[ds*16+si] = 0x00;
        return;
    case 0x113F5:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r8[cl] = memory[ds*16+si + 20];
        r8[ch] = 0x00;
        push(r16[cx]);
        yield* sub_10AD5();
        si = pop();
        if (r16[ax] == 0x0000)
            return;
        push(si);
        r8[al] = memory[ds*16+si + 20];
        r8[ah] = 0x00;
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_11C0A();
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80) {
            pc = 0x11427;
            break;
        }
        yield* sub_120DB();
        r8[al] = 0x06;
        yield* sub_13840();
        si = pop();
        push(si);
        memory[ds*16+si] = 0x00;
    case 0x11427:
        si = pop();
        return;
    } while (1);
}
function* sub_11429() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110C6();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x11433;
            break;
        }
        return;
    case 0x11433:
        r8[al] = memory[ds*16+si + 1];
        if (r8[al] != 0x02) {
            pc = 0x11440;
            break;
        }
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0005);
        pc = 0x1146A;
        break;
    case 0x11440:
        if (r8[al] != 0x00) {
            pc = 0x1144A;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0005);
        pc = 0x1146A;
        break;
    case 0x1144A:
        if (r8[al] != 0x01) {
            pc = 0x11458;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0003);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0002);
        pc = 0x1146A;
        break;
    case 0x11458:
        if (r8[al] != 0x03) {
            pc = 0x11466;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0003);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0002);
        pc = 0x1146A;
        break;
    case 0x11466:
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0005);
    case 0x1146A:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        r16[ax] = memory16get(ds*16+si + 5);
        if (r16s[ax] >= signed16(0x000c)) {
            pc = 0x1147B;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x1147B:
        if (r16s[ax] <= signed16(0x00f4)) {
            pc = 0x11484;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x11484:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        push(r16[ax]);
        yield* sub_107FD();
        si = pop();
        r8[al] += 0x08;
        memory[ds*16+si + 3] = r8[al];
        memory[ds*16+si + 20] = r8[cl];
        memory[ds*16+si + 4] = r8[bl];
        r8[bl] = memory[ds*16+si + 1];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 4351);
        yield* sub_12121();
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x114B2;
            break;
        }
        return;
    case 0x114B2:
        r16[ax] = memory16get(ds*16+si + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= 0) {
            pc = 0x114BD;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x114BD:
        if (r16[ax] >= 0x0010)
            return;
        r16[ax] = memory16get(ds*16+si + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B91);
        r16[ax] -= 0x0008;
        if (r16s[ax] >= 0) {
            pc = 0x114D0;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x114D0:
        if (r16[ax] >= 0x0010)
            return;
        r8[al] = 0x05;
        yield* sub_13840();
        memory16set(ds*16+0x9544, memory16get(ds*16+0x9544) - 0x0064);
        memory[ds*16+0x12A0] = 0x01;
        yield* sub_120F0();
        memory[ds*16+0x12A0] = 0x05;
        memory[ds*16+si] = 0x00;
        return;
    } while (1);
}
function* sub_114F0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0001);
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        push(r16[ax]);
        yield* sub_107FD();
        si = pop();
        memory[ds*16+si + 3] = r8[al];
        memory[ds*16+si + 20] = r8[cl];
        memory[ds*16+si + 4] = r8[bl];
        r8[bl] = memory[ds*16+si + 1];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 4065);
        yield* sub_12121();
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] == 0x11) {
            pc = 0x11548;
            break;
        }
        r16[ax] = memory16get(ds*16+si + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= 0) {
            pc = 0x1152A;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1152A:
        if (r16[ax] >= 0x001a) {
            pc = 0x11548;
            break;
        }
        r16[ax] = memory16get(ds*16+si + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B91);
        if (r16s[ax] >= 0) {
            pc = 0x1153A;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1153A:
        if (r16[ax] >= 0x0012) {
            pc = 0x11548;
            break;
        }
        memory16set(ds*16+0x9544, memory16get(ds*16+0x9544) - 0x000c);
        memory[ds*16+si + 21] = 0xff;
    case 0x11548:
        di = 0x1ba1;
    case 0x1154B:
        r8[al] = memory[ds*16+si + 21];
        if (r8s[al] >= signed8(0x00)) {
            pc = 0x11561;
            break;
        }
        r8[al] = 0x07;
        yield* sub_13840();
        yield* sub_120F0();
        memory[ds*16+si] = 0x00;
        yield* sub_12676();
        return;
    case 0x11561:
        r8[al] = memory[ds*16+di];
        if (r8[al] & 0x80) {
            pc = 0x115C0;
            break;
        }
        if (!(r8[al] & 0x40)) {
            pc = 0x115BB;
            break;
        }
        push(di);
        r16[ax] = memory16get(ds*16+di + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        if (r16s[ax] >= 0) {
            pc = 0x11576;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11576:
        if (r16[ax] >= 0x0014) {
            pc = 0x115BA;
            break;
        }
        r16[ax] = memory16get(ds*16+di + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 7);
        if (r16s[ax] >= 0) {
            pc = 0x11585;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11585:
        if (r16[ax] >= 0x0010) {
            pc = 0x115BA;
            break;
        }
        r8[al] = memory[ds*16+di + 18];
        if (r8[al] != 0x19) {
            pc = 0x1159A;
            break;
        }
        memory[ds*16+si + 21] = 0xff;
        memory[ds*16+di] = 0x00;
        pc = 0x115BA;
        break;
    case 0x1159A:
        r8[al] = memory[ds*16+di + 3];
        r8[al] = r8[al] - memory[ds*16+si + 3];
        if (r8s[al] >= 0) {
            pc = 0x115A4;
            break;
        }
        r8[al] = -r8[al];
    case 0x115A4:
        if (r8[al] >= 0x10) {
            pc = 0x115BA;
            break;
        }
        memory[ds*16+si + 21] -= 1;
        push(si);
        si = di;
        yield* sub_12092();
        r8[al] = 0x03;
        yield* sub_13840();
        yield* sub_12662();
        si = pop();
    case 0x115BA:
        di = pop();
    case 0x115BB:
        di += 0x0017;
        pc = 0x1154B;
        break;
    case 0x115C0:
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] == 0x11) {
            pc = 0x115F8;
            break;
        }
        r16[ax] = memory16get(ds*16+0x1B91);
        if (r16[ax] <= memory16get(ds*16+si + 7)) {
            pc = 0x115F8;
            break;
        }
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        if (r16s[ax] >= 0) {
            pc = 0x115D9;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x115D9:
        if (r16[ax] >= 0x0020) {
            pc = 0x115F8;
            break;
        }
        memory[ds*16+si + 22] -= 1;
        if (memorys[ds*16+si + 22] >= 0) {
            pc = 0x115EE;
            break;
        }
        memory[ds*16+si + 22] = 0x07;
        memory[ds*16+0x9518] = 0x01;
        pc = 0x115F3;
        break;
    case 0x115EE:
        memory[ds*16+0x9518] = 0x00;
    case 0x115F3:
        push(si);
        yield* sub_11DEF();
        si = pop();
    case 0x115F8:
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_115FC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110C6();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x11606;
            break;
        }
        return;
    case 0x11606:
        r8[al] = memory[ds*16+si + 1];
        if (r8[al] != 0x02) {
            pc = 0x11613;
            break;
        }
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0008);
        pc = 0x1163D;
        break;
    case 0x11613:
        if (r8[al] != 0x00) {
            pc = 0x1161D;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0008);
        pc = 0x1163D;
        break;
    case 0x1161D:
        if (r8[al] != 0x01) {
            pc = 0x1162B;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0006);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0004);
        pc = 0x1163D;
        break;
    case 0x1162B:
        if (r8[al] != 0x03) {
            pc = 0x11639;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0006);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0004);
        pc = 0x1163D;
        break;
    case 0x11639:
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0008);
    case 0x1163D:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        r16[ax] = memory16get(ds*16+si + 5);
        if (r16s[ax] >= signed16(0x0004)) {
            pc = 0x1164E;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x1164E:
        if (r16s[ax] <= signed16(0x00fc)) {
            pc = 0x11657;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x11657:
        r8[al] = memory[ds*16+si + 4];
        if (r8[al] != 0x01) {
            pc = 0x1166B;
            break;
        }
        r8[al] = memory[ds*16+si + 3];
        if (r8s[al] >= signed8(0x64)) {
            pc = 0x11669;
            break;
        }
        memory[ds*16+si + 3] += 0x04;
    case 0x11669:
        pc = 0x1167A;
        break;
    case 0x1166B:
        if (r8[al] != 0x02) {
            pc = 0x1167A;
            break;
        }
        r8[al] = memory[ds*16+si + 3];
        if (r8s[al] <= signed8(0x9c)) {
            pc = 0x1167A;
            break;
        }
        memory[ds*16+si + 3] -= 0x04;
    case 0x1167A:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        push(r16[ax]);
        yield* sub_107FD();
        si = pop();
        if (r8s[al] < memorys[ds*16+si + 3]) {
            pc = 0x11691;
            break;
        }
        yield* sub_12092();
        return;
    case 0x11691:
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x11699;
            break;
        }
        return;
    case 0x11699:
        r16[ax] = memory16get(ds*16+si + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= 0) {
            pc = 0x116A4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x116A4:
        if (r16[ax] >= 0x000c)
            return;
        r16[ax] = memory16get(ds*16+si + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B91);
        if (r16s[ax] >= 0) {
            pc = 0x116B4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x116B4:
        if (r16[ax] >= 0x0008)
            return;
        r8[al] = memory[ds*16+si + 3];
        r8[al] = r8[al] - memory[ds*16+0x1B8D];
        if (r8s[al] >= 0) {
            pc = 0x116C4;
            break;
        }
        r8[al] = -r8[al];
    case 0x116C4:
        if (r8[al] >= 0x10)
            return;
        memory16set(ds*16+0x9544, memory16get(ds*16+0x9544) - 0x0001);
        yield* sub_12092();
        r8[al] = 0x04;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_116D6() {
    memory[ds*16+si + 4] -= 1;
    if (memorys[ds*16+si + 4] >= 0)
        return;
    memory[ds*16+si] = 0x00;
    return;
}
function* sub_116DF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si + 4];
        memory[ds*16+si + 4] += 1;
        if (r8[al] < 0x04) {
            pc = 0x116ED;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x116ED:
        r8[al] <<= 1;
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[ax] = memory16get(ds*16+r16[bx] + 5182);
        memory16set(ds*16+si + 15, r16[ax]);
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_116FE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si + 22] += 1;
        r8[al] = memory[ds*16+si + 22];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x05)) {
            pc = 0x11712;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x11712:
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x12b5;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_1171F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si + 22] += 1;
        r8[al] = memory[ds*16+si + 22];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x06)) {
            pc = 0x11733;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x11733:
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x12f5;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_11740() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si + 22] += 1;
        r8[al] = memory[ds*16+si + 22];
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x04)) {
            pc = 0x11762;
            break;
        }
        r8[al] = memory[ds*16+si];
        if (!(r8[al] & 0x20)) {
            pc = 0x11759;
            break;
        }
        memory[ds*16+0x9517] &= 0x7f;
        pc = 0x1175E;
        break;
    case 0x11759:
        memory[ds*16+0x9517] &= 0xfe;
    case 0x1175E:
        memory[ds*16+si] = 0x00;
        return;
    case 0x11762:
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x133d;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_1176C() {
    memory[ds*16+si + 22] += 1;
    r8[al] = memory[ds*16+si + 22];
    r8[al] >>= 1;
    r8[al] &= 0x03;
    memory[ds*16+si + 4] = r8[al];
    r16[bx] = 0x0e2b;
    yield* sub_12121();
    yield* sub_110C6();
}
function* sub_11783() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si + 22] += 1;
        r8[al] = memory[ds*16+si + 22];
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8[al] < 0x06) {
            pc = 0x11797;
            break;
        }
        r8[al] = 0x00;
        memory[ds*16+si + 22] = 0x00;
    case 0x11797:
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 3660];
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x0e52;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_117AC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215B();
        if (r16[cx] == 0x0000) {
            pc = 0x117CC;
            break;
        }
        memory[ds*16+si + 22] -= 1;
        if (memorys[ds*16+si + 22] >= 0) {
            pc = 0x117C4;
            break;
        }
        memory[ds*16+si + 22] = 0x08;
        memory[ds*16+0x9518] = 0x01;
        pc = 0x117C9;
        break;
    case 0x117C4:
        memory[ds*16+0x9518] = 0x00;
    case 0x117C9:
        yield* sub_11F0B();
    case 0x117CC:
        r16[bx] = 0x0e73;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_117D6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215B();
        if (r16[cx] == 0x0000) {
            pc = 0x117EA;
            break;
        }
        memory[ds*16+si + 22] -= 1;
        if (memorys[ds*16+si + 22] >= 0) {
            pc = 0x117EA;
            break;
        }
        memory[ds*16+si + 22] = 0x12;
        yield* sub_12005();
    case 0x117EA:
        r16[bx] = 0x0e9c;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_117F4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110C6();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x117FE;
            break;
        }
        return;
    case 0x117FE:
        r8[al] = memory[ds*16+si + 1];
        if (r8[al] != 0x02) {
            pc = 0x1180B;
            break;
        }
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x1180B:
        if (r8[al] != 0x00) {
            pc = 0x11815;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0004);
        pc = 0x11835;
        break;
    case 0x11815:
        if (r8[al] != 0x01) {
            pc = 0x11823;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0004);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x11823:
        if (r8[al] != 0x03) {
            pc = 0x11831;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0004);
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x11831:
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0004);
    case 0x11835:
        memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
        r16[ax] = memory16get(ds*16+si + 5);
        if (r16s[ax] >= signed16(0x0008)) {
            pc = 0x11846;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x11846:
        if (r16s[ax] <= signed16(0x00f8)) {
            pc = 0x1184F;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x1184F:
        memory[ds*16+si + 22] += 1;
        r8[bl] = memory[ds*16+si + 22];
        if (r8[bl] < 0x10) {
            pc = 0x1185E;
            break;
        }
        yield* sub_12099();
        return;
    case 0x1185E:
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5223];
        memory[ds*16+si + 3] += r8[al];
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x1186F;
            break;
        }
        return;
    case 0x1186F:
        r16[ax] = memory16get(ds*16+si + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= 0) {
            pc = 0x1187A;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1187A:
        if (r16[ax] >= 0x000e)
            return;
        r16[ax] = memory16get(ds*16+si + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B91);
        if (r16s[ax] >= 0) {
            pc = 0x1188A;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1188A:
        if (r16[ax] >= 0x000a)
            return;
        r8[al] = memory[ds*16+si + 3];
        r8[al] = r8[al] - memory[ds*16+0x1B8D];
        if (r8s[al] >= 0) {
            pc = 0x1189A;
            break;
        }
        r8[al] = -r8[al];
    case 0x1189A:
        if (r8[al] >= 0x10)
            return;
        memory16set(ds*16+0x9544, memory16get(ds*16+0x9544) - 0x000a);
        r8[al] = 0x05;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_118A9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215B();
        if (r16[cx] == 0x0000) {
            pc = 0x118BD;
            break;
        }
        memory[ds*16+si + 22] -= 1;
        if (memorys[ds*16+si + 22] >= 0) {
            pc = 0x118BD;
            break;
        }
        memory[ds*16+si + 22] = 0x28;
        yield* sub_11FBA();
    case 0x118BD:
        r16[bx] = 0x0ec5;
        yield* sub_12121();
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_118C7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x952E];
        r8[al] = r8[al] & memory[ds*16+0x952F];
        r8[al] = r8[al] & memory[ds*16+0x9530];
        r8[al] = r8[al] & memory[ds*16+0x9531];
        r8[al] = r8[al] & memory[ds*16+0x9532];
        r8[al] = r8[al] & memory[ds*16+0x9533];
        if (r8[al] != 0) {
            pc = 0x118E4;
            break;
        }
        yield* sub_110C6();
        return;
    case 0x118E4:
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x118F1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x118F1:
        r16[cx] = memory16get(ds*16+0x1B91);
        r16[cx] -= 0x0008;
        r16[cx] = r16[cx] - memory16get(ds*16+si + 7);
        if (r16s[cx] >= 0) {
            pc = 0x118FF;
            break;
        }
        r16[cx] = -r16[cx];
    case 0x118FF:
        r8[bl] = memory[ds*16+si + 4];
        r8[bl] >>= 1;
        r16[ax] += r16[cx];
        if (r16[ax] > 0x0040) {
            pc = 0x11915;
            break;
        }
        if (r8[bl] == 0x08) {
            pc = 0x11913;
            break;
        }
        memory[ds*16+si + 4] += 1;
    case 0x11913:
        pc = 0x1191D;
        break;
    case 0x11915:
        if (r8[bl] == 0x00) {
            pc = 0x1191D;
            break;
        }
        memory[ds*16+si + 4] -= 1;
    case 0x1191D:
        push(r16[bx]);
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5251);
        memory16set(ds*16+si + 15, r16[ax]);
        r16[bx] = pop();
        if (r8[bl] < 0x02) {
            pc = 0x1196B;
            break;
        }
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11947;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] > 0x0018) {
            pc = 0x11945;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) + 1);
    case 0x11945:
        pc = 0x11952;
        break;
    case 0x11947:
        if (r16[ax] == 0) {
            pc = 0x11952;
            break;
        }
        if (r16[ax] > 0x0018) {
            pc = 0x11952;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) - 1);
    case 0x11952:
        if (r8[bl] != 0x08) {
            pc = 0x1196B;
            break;
        }
        if (r16[cx] > 0x0008) {
            pc = 0x1196B;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x1196B;
            break;
        }
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] == 0x11) {
            pc = 0x1196B;
            break;
        }
        yield* sub_1196F();
    case 0x1196B:
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_1196F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x1B8E];
        if (r8[al] != 0x00) {
            pc = 0x11982;
            break;
        }
        memory[ds*16+0x951D] = 0xf0;
        memory[ds*16+0x94FF] = 0x01;
        return;
    case 0x11982:
        push(si);
        memory[ds*16+0x1B8E] = 0x00;
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        yield* sub_12121();
        si = pop();
        return;
    } while (1);
}
function* sub_11993() {
    yield* sub_11A04();
    r8[al] = memory[ds*16+0x94FF];
    if (r8[al] != 0x01)
        return;
    r8[al] = memory[ds*16+0x9501];
    r8[bl] = r8[al];
    r8[al] <<= 1;
    r8[bl] += r8[al];
    r8[bl] = r8[bl] + memory[ds*16+0x9502];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + 5269);
    r8[bh] = r8[ah];
    r16[ax] &= 0x03ff;
    memory16set(ds*16+0x950C, r16[ax]);
    r8[bh] &= 0xc0;
    memory[ds*16+0x951D] = r8[bh];
    return;
}
function* sub_119C2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_11A04();
        r8[al] = memory[ds*16+0x94FF];
        if (r8[al] != 0x01)
            return;
        r8[al] = memory[ds*16+0x9501];
        r8[bl] = r8[al];
        r8[al] <<= 1;
        r8[bl] += r8[al];
        r8[bl] = r8[bl] + memory[ds*16+0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5317);
        r8[bh] = r8[ah];
        r16[ax] &= 0x03ff;
        memory16set(ds*16+0x950C, r16[ax]);
        r8[bh] &= 0xc0;
        memory[ds*16+0x951D] = r8[bh];
        memory[ds*16+0x950E] = 0x01;
        r8[al] = memory[ds*16+0x9502];
        r8[al] += 1;
        if (r8[al] <= 0x02) {
            pc = 0x11A00;
            break;
        }
        r8[al] = 0x00;
    case 0x11A00:
        memory[ds*16+0x9502] = r8[al];
        return;
    } while (1);
}
function* sub_11A04() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11A11;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11A11:
        r16[cx] = memory16get(ds*16+0x1B91);
        r16[cx] = r16[cx] - memory16get(ds*16+si + 7);
        if (r16s[cx] >= 0) {
            pc = 0x11A1C;
            break;
        }
        r16[cx] = -r16[cx];
    case 0x11A1C:
        r8[bl] = memory[ds*16+si + 4];
        r8[bl] >>= 1;
        r16[ax] += r16[cx];
        if (r16[ax] > 0x0040) {
            pc = 0x11A32;
            break;
        }
        if (r8[bl] == 0x06) {
            pc = 0x11A30;
            break;
        }
        memory[ds*16+si + 4] += 1;
    case 0x11A30:
        pc = 0x11A3A;
        break;
    case 0x11A32:
        if (r8[bl] == 0x00) {
            pc = 0x11A3A;
            break;
        }
        memory[ds*16+si + 4] -= 1;
    case 0x11A3A:
        if (r8[bl] != 0x06) {
            pc = 0x11A45;
            break;
        }
        memory[ds*16+si + 2] = 0x00;
        pc = 0x11A56;
        break;
    case 0x11A45:
        push(r16[bx]);
        memory[ds*16+si + 2] = 0x07;
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5239);
        memory16set(ds*16+si + 15, r16[ax]);
        r16[bx] = pop();
    case 0x11A56:
        if (r8[bl] < 0x01) {
            pc = 0x11A9A;
            break;
        }
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11A73;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] > 0x0018) {
            pc = 0x11A71;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) + 1);
    case 0x11A71:
        pc = 0x11A7E;
        break;
    case 0x11A73:
        if (r16[ax] == 0) {
            pc = 0x11A7E;
            break;
        }
        if (r16[ax] > 0x0018) {
            pc = 0x11A7E;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) - 1);
    case 0x11A7E:
        if (r16[cx] > 0x0008) {
            pc = 0x11A9A;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x11A9A;
            break;
        }
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] == 0x11) {
            pc = 0x11A9A;
            break;
        }
        r16[ax] = memory16get(ds*16+0x1B8F);
        memory16set(ds*16+0x950A, r16[ax]);
        memory[ds*16+0x94FF] = 0x01;
    case 0x11A9A:
        yield* sub_110C6();
        return;
    } while (1);
}
function* sub_11A9E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110C6();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x11AA8;
            break;
        }
        return;
    case 0x11AA8:
        r16[bx] = memory16get(ds*16+0x1B91);
        r16[bx] = r16[bx] - memory16get(ds*16+si + 7);
        if (r16s[bx] >= 0) {
            pc = 0x11ABB;
            break;
        }
        if (r16s[bx] >= signed16(0xfff0))
            return;
        memory[ds*16+si + 2] = 0x01;
        return;
    case 0x11ABB:
        if (r16s[bx] <= signed16(0x0020)) {
            pc = 0x11AC1;
            break;
        }
        return;
    case 0x11AC1:
        r16[ax] = memory16get(ds*16+0x1B8F);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11AD9;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] >= 0x0018) {
            pc = 0x11AD7;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) + 1);
    case 0x11AD7:
        pc = 0x11AE7;
        break;
    case 0x11AD9:
        if (r16[ax] >= 0x0018) {
            pc = 0x11AE7;
            break;
        }
        if (r16[ax] == 0x0000) {
            pc = 0x11AE7;
            break;
        }
        memory16set(ds*16+0x1B8F, memory16get(ds*16+0x1B8F) - 1);
    case 0x11AE7:
        if (r16[bx] <= 0x0008) {
            pc = 0x11AED;
            break;
        }
        return;
    case 0x11AED:
        if (r16[ax] > 0x0002) {
            pc = 0x11AF8;
            break;
        }
        memory16set(ds*16+0x9538, memory16get(ds*16+0x9538) + 1);
        return;
    case 0x11AF8:
        if (r16[ax] >= 0x0024)
            return;
        memory16set(ds*16+0x9542, 0x0000);
        r8[al] = 0x06;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_11B09() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110C6();
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x00) {
            pc = 0x11B13;
            break;
        }
        return;
    case 0x11B13:
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x11B1B;
            break;
        }
        return;
    case 0x11B1B:
        r16[ax] = memory16get(ds*16+si + 5);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B8F);
        if (r16s[ax] >= 0) {
            pc = 0x11B26;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11B26:
        if (r16[ax] >= 0x0012)
            return;
        r16[ax] = memory16get(ds*16+si + 7);
        r16[ax] = r16[ax] - memory16get(ds*16+0x1B91);
        if (r16s[ax] >= 0) {
            pc = 0x11B36;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11B36:
        if (r16[ax] >= 0x0010)
            return;
        memory[ds*16+si] = 0x00;
        r8[al] = memory[ds*16+si + 1];
        yield* sub_12B28();
        r8[al] = 0x0a;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_11B4A() {
    memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) - 0x0002);
    memory16set(ds*16+si + 7, memory16get(ds*16+si + 7) & 0x03ff);
    yield* sub_110A0();
}
function* sub_11B57() {
    r16[ax] = memory16get(ds*16+0x1B8F);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+0x9528);
    r16[ax] += 0x0070;
    r16[ax] &= 0x03ff;
    memory16set(ds*16+0x1B91, r16[ax]);
    push(r16[ax]);
    yield* sub_107FD();
    memory[ds*16+0x1B8D] = r8[al];
    memory[ds*16+0x1B9E] = r8[cl];
    memory[ds*16+0x1B8E] = r8[bl];
    si = 0x1b8a;
    r16[bx] = 0x0d49;
    yield* sub_12121();
}
function* sub_11B80() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x952A);
        r16[ax] = memory16get(ds*16+0x953A);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x11B91;
            break;
        }
        r16[ax] = 0x0008;
        pc = 0x11B94;
        break;
    case 0x11B91:
        r16[ax] = memory16get(ds*16+0x954C);
    case 0x11B94:
        if (!(r8[al] & 0x04)) {
            pc = 0x11BA3;
            break;
        }
        r16[bx] += 1;
        if (r16s[bx] <= signed16(0x0040)) {
            pc = 0x11BA1;
            break;
        }
        r16[bx] = 0x0040;
    case 0x11BA1:
        pc = 0x11BB4;
        break;
    case 0x11BA3:
        if (!(r8[al] & 0x08)) {
            pc = 0x11BB4;
            break;
        }
        r16[bx] -= 0x0002;
        if (r16s[bx] >= memory16gets(ds*16+0x94FC)) {
            pc = 0x11BB4;
            break;
        }
        r16[bx] = memory16get(ds*16+0x94FC);
    case 0x11BB4:
        memory16set(ds*16+0x952A, r16[bx]);
        return;
    } while (1);
}
function* sub_11BB9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x952A);
        r16[bx] += 0x000f;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] = r16[bx];
        r16[ax] -= 1;
        r16[bx] >>= 1;
        r16[ax] = r16[ax] + memory16get(ds*16+0x950F);
        if (r16[ax] <= 0x008b) {
            pc = 0x11BDD;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds*16+0x953C, 0xffff);
    case 0x11BDD:
        memory16set(ds*16+0x950F, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9528);
        r16[ax] -= r16[bx];
        r16[ax] &= 0x03ff;
        memory16set(ds*16+0x9528, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9528);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] -= 0x0003;
        r16[ax] &= 0x003f;
        if (r16[ax] == memory16get(ds*16+0x9507))
            return;
        memory16set(ds*16+0x9507, r16[ax]);
        push(r16[ax]);
        yield* sub_108BA();
        return;
    } while (1);
}
function* sub_11C0A() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = _stack16(bp + arg_2);
        r16[cx] = _stack16(bp + arg_0);
        si = 0x1b8a;
    case 0x11C16:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80) {
            pc = 0x11C2F;
            break;
        }
        if (!(r8[al] & 0x08)) {
            pc = 0x11C2A;
            break;
        }
        if (r8[cl] != memory[ds*16+si + 20]) {
            pc = 0x11C2A;
            break;
        }
        if (r8[bl] == memory[ds*16+si + 19]) {
            pc = 0x11C2F;
            break;
        }
    case 0x11C2A:
        si += 0x0017;
        pc = 0x11C16;
        break;
    case 0x11C2F:
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_11C33() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x1B9C];
        if (r8[al] != 0x11) {
            pc = 0x11C3B;
            break;
        }
        return;
    case 0x11C3B:
        r8[al] = 0x0c;
        yield* sub_13840();
        si = 0x1b8a;
        yield* sub_120F0();
        memory[ds*16+0x1B9C] = 0x11;
        memory[ds*16+0x1B8C] = 0x00;
        memory[ds*16+0x9514] = 0x00;
        return;
    } while (1);
}
function* sub_11C56() {
    r16[ax] = -r16[ax];
    memory16set(ds*16+0x9544, r16[ax]);
    push(r16[ax]);
    r8[al] = 0x06;
    yield* sub_13840();
    r16[ax] = pop();
    r16[ax] = r16[bx];
    push(r16[ax]);
    r8[al] = memory[ds*16+0x1B9E];
    r8[ah] = 0x00;
    push(r16[ax]);
    yield* sub_11C0A();
    r8[al] = memory[ds*16+si];
    if (r8[al] & 0x80)
        return;
    yield* sub_120DB();
    return;
}
function* sub_11C78() {
    r16[ax] = memory16get(ds*16+0x9437);
    memory16set(ds*16+0x9439, r16[ax]);
    r16[ax] = memory16get(ds*16+0x9435);
    memory16set(ds*16+0x9437, r16[ax]);
    r16[ax] = memory16get(ds*16+0x9433);
    memory16set(ds*16+0x9435, r16[ax]);
    r16[ax] = memory16get(ds*16+0x1B8F);
    memory16set(ds*16+0x9433, r16[ax]);
    r16[ax] = memory16get(ds*16+0x943F);
    memory16set(ds*16+0x9441, r16[ax]);
    r16[ax] = memory16get(ds*16+0x943D);
    memory16set(ds*16+0x943F, r16[ax]);
    r16[ax] = memory16get(ds*16+0x943B);
    memory16set(ds*16+0x943D, r16[ax]);
    r16[ax] = memory16get(ds*16+0x1B91);
    memory16set(ds*16+0x943B, r16[ax]);
    r8[al] = memory[ds*16+0x9445];
    memory[ds*16+0x9446] = r8[al];
    r8[al] = memory[ds*16+0x9444];
    memory[ds*16+0x9445] = r8[al];
    r8[al] = memory[ds*16+0x9443];
    memory[ds*16+0x9444] = r8[al];
    r8[al] = memory[ds*16+0x1B8E];
    memory[ds*16+0x9443] = r8[al];
    r8[al] = memory[ds*16+0x9449];
    memory[ds*16+0x944A] = r8[al];
    r8[al] = memory[ds*16+0x9448];
    memory[ds*16+0x9449] = r8[al];
    r8[al] = memory[ds*16+0x9447];
    memory[ds*16+0x9448] = r8[al];
    r8[al] = memory[ds*16+0x1B8D];
    memory[ds*16+0x9447] = r8[al];
}
function* sub_11CD9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9439);
        memory16set(ds*16+si + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9441);
        r16[ax] += 0x0006;
        r16[ax] &= 0x03ff;
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0x9446];
        memory[ds*16+si + 4] = r8[al];
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 3513];
        r8[al] = memory[ds*16+0x944A];
        r8[al] += 0x06;
        memory[ds*16+si + 3] = r8[al];
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x20) {
            pc = 0x11D10;
            break;
        }
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) - 0x0008);
        memory[ds*16+si + 3] += r8[cl];
        pc = 0x11D17;
        break;
    case 0x11D10:
        memory16set(ds*16+si + 5, memory16get(ds*16+si + 5) + 0x0008);
        memory[ds*16+si + 3] -= r8[cl];
    case 0x11D17:
        r16[bx] = 0x0dda;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_11D1E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x135e;
        memory[ds*16+si] &= 0xdf;
        r8[bl] = memory[ds*16+0x1B8E];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5021];
        memory[ds*16+si + 4] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 4981];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+0x1B8F);
        memory16set(ds*16+si + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0x1B91);
        r16[ax] -= 0x0004;
        r16[ax] &= 0x03ff;
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0x1B8D];
        r8[al] = r8[al] + memory[ds*16+r16[bx] + 5001];
        memory[ds*16+si + 3] = r8[al];
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5031];
        memory[ds*16+si + 10] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5034);
        memory16set(ds*16+si + 15, r16[ax]);
        yield* sub_10B58();
        si = 0x0ff7;
        r16[ax] = memory16get(ds*16+0x1363);
        memory16set(ds*16+si + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0x1365);
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0x1361];
        memory[ds*16+si + 3] = r8[al];
        memory[ds*16+0x9516] += 1;
        r8[bl] = memory[ds*16+0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16+r16[bx] + 4071];
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x100e;
        yield* sub_12121();
        yield* sub_10B58();
        si = 0x135e;
        memory[ds*16+si] |= 0x20;
        r8[bl] = memory[ds*16+0x1B8E];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 4991];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+0x1B8F);
        memory16set(ds*16+si + 5, r16[ax]);
        r8[al] = memory[ds*16+0x1B8D];
        r8[al] = r8[al] + memory[ds*16+r16[bx] + 5011];
        memory[ds*16+si + 3] = r8[al];
        yield* sub_10B58();
        si = 0x0ff7;
        r16[ax] = memory16get(ds*16+0x1363);
        memory16set(ds*16+si + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0x1365);
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0x1361];
        memory[ds*16+si + 3] = r8[al];
        yield* sub_10B58();
        r16[ax] = memory16get(ds*16+0x9511);
        r16[ax] += r16[bx];
        if (r16[ax] <= 0x0010) {
            pc = 0x11DEB;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds*16+0x9540, 0xffff);
    case 0x11DEB:
        memory16set(ds*16+0x9511, r16[ax]);
        return;
    } while (1);
}
function* sub_11DEF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x9516] += 1;
        r8[bl] = memory[ds*16+0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16+r16[bx] + 4071];
        memory[ds*16+0xFFB] = r8[al];
        r8[al] = memory[ds*16+si + 1];
        if (r8[al] != 0x00) {
            pc = 0x11E2E;
            break;
        }
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5069];
        r16[ax] = 0xfffd;
        r16[bx] = 0x0008;
        yield* sub_11E7D();
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5079];
        r16[ax] = 0x0003;
        r16[bx] = 0x0008;
        yield* sub_11E7D();
        return;
    case 0x11E2E:
        if (r8[al] != 0x01) {
            pc = 0x11E46;
            break;
        }
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5089];
        r16[ax] = 0x0000;
        r16[bx] = 0x0008;
        yield* sub_11E7D();
        return;
    case 0x11E46:
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5099];
        r16[ax] = 0xfff9;
        r16[bx] = 0x0008;
        yield* sub_11E7D();
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5109];
        r16[ax] = 0x0000;
        r16[bx] = 0x000b;
        yield* sub_11E7D();
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16+r16[bx] + 5119];
        r16[ax] = 0x0007;
        r16[bx] = 0x0008;
        yield* sub_11E7D();
        return;
    } while (1);
}
function* sub_11E7D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        di = 0x0ff7;
        r16[ax] = r16[ax] + memory16get(ds*16+si + 5);
        memory16set(ds*16+di + 5, r16[ax]);
        r16[bx] = r16[bx] + memory16get(ds*16+si + 7);
        r16[bx] &= 0x03ff;
        memory16set(ds*16+di + 7, r16[bx]);
        r8[cl] = r8[cl] + memory[ds*16+si + 3];
        memory[ds*16+di + 3] = r8[cl];
        si = di;
        r16[bx] = 0x1039;
        yield* sub_12121();
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x11EB0;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11EB0;
            break;
        }
        yield* sub_116D6();
    case 0x11EB0:
        si = pop();
        r8[al] = memory[ds*16+0x9518];
        if (r8[al] != 0x00) {
            pc = 0x11EB9;
            break;
        }
        return;
    case 0x11EB9:
        push(si);
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        si = 0x13b0;
        r8[al] = memory[ds*16+r16[bx] + 5021];
        memory[ds*16+si + 4] = r8[al];
        r16[ax] = memory16get(ds*16+0xFFC);
        memory16set(ds*16+si + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFFE);
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+0xFFA];
        memory[ds*16+si + 3] = r8[al];
        memory[ds*16+si + 1] = 0x02;
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5031];
        memory[ds*16+si + 10] = r8[al];
        memory[ds*16+si + 9] = 0x04;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5063);
        memory16set(ds*16+si + 15, r16[ax]);
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x11F09;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11F09;
            break;
        }
        yield* sub_115FC();
    case 0x11F09:
        si = pop();
        return;
    } while (1);
}
function* sub_11F0B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        memory[ds*16+0x9516] += 1;
        r8[bl] = memory[ds*16+0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16+r16[bx] + 4071];
        memory[ds*16+0xFFB] = r8[al];
        di = 0x0ff7;
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5129];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 5);
        memory16set(ds*16+di + 5, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 5134];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds*16+di + 7, r16[ax]);
        r8[al] = memory[ds*16+si + 3];
        r8[al] += 0x04;
        memory[ds*16+di + 3] = r8[al];
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 4143);
        si = di;
        yield* sub_12121();
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x11F63;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11F63;
            break;
        }
        yield* sub_116D6();
    case 0x11F63:
        si = pop();
        r8[al] = memory[ds*16+0x9518];
        if (r8[al] != 0x00) {
            pc = 0x11F6C;
            break;
        }
        return;
    case 0x11F6C:
        push(si);
        di = 0x13b0;
        r8[bl] = memory[ds*16+si + 4];
        r8[bh] = 0x00;
        memory[ds*16+di + 1] = r8[bl];
        r16[ax] = memory16get(ds*16+0xFFC);
        memory16set(ds*16+di + 5, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFFE);
        memory16set(ds*16+di + 7, r16[ax]);
        r8[al] = memory[ds*16+0xFFA];
        memory[ds*16+di + 3] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 5139];
        memory[ds*16+di + 9] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 5144];
        memory[ds*16+di + 10] = r8[al];
        memory[ds*16+di + 4] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5149);
        memory16set(ds*16+di + 15, r16[ax]);
        si = di;
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x11FB8;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11FB8;
            break;
        }
        yield* sub_115FC();
    case 0x11FB8:
        si = pop();
        return;
    } while (1);
}
function* sub_11FBA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        di = 0x10e8;
        r8[bl] = memory[ds*16+si + 4];
        memory[ds*16+di + 1] = r8[bl];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 4318];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 5);
        memory16set(ds*16+di + 5, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 4323];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds*16+di + 7, r16[ax]);
        r8[al] = memory[ds*16+si + 3];
        r8[al] += 0x08;
        memory[ds*16+di + 3] = r8[al];
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 4351);
        si = di;
        yield* sub_12121();
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x12003;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x12003;
            break;
        }
        yield* sub_11429();
    case 0x12003:
        si = pop();
        return;
    } while (1);
}
function* sub_12005() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        di = 0x1446;
        r8[bl] = memory[ds*16+si + 4];
        memory[ds*16+di + 1] = r8[bl];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 5213];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 5);
        memory16set(ds*16+di + 5, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 5218];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds*16+di + 7, r16[ax]);
        r8[al] = memory[ds*16+si + 3];
        r8[al] += 0x08;
        memory[ds*16+di + 3] = r8[al];
        si = di;
        yield* sub_10B58();
        if (si == 0x0000) {
            pc = 0x12045;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x12045;
            break;
        }
        yield* sub_117F4();
    case 0x12045:
        si = pop();
        return;
    } while (1);
}
function* sub_12047() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si];
        r8[bl] = memory[ds*16+0x9517];
        if (!(r8[al] & 0x20)) {
            pc = 0x12072;
            break;
        }
        if (r8[bl] & 0x80) {
            pc = 0x1206D;
            break;
        }
        memory[ds*16+0x9517] |= 0x80;
        memory[ds*16+0x1326] |= 0x20;
        di = 0x1326;
        yield* sub_120A0();
        r8[al] = 0x03;
        yield* sub_13840();
        pc = 0x12070;
        break;
    case 0x1206D:
        memory[ds*16+si] = 0x00;
    case 0x12070:
        return;
    case 0x12072:
        if (r8[bl] & 0x01) {
            pc = 0x1208E;
            break;
        }
        memory[ds*16+0x9517] |= 0x01;
        memory[ds*16+0x1326] &= 0xdf;
        di = 0x1326;
        yield* sub_120A0();
        r8[al] = 0x03;
        yield* sub_13840();
        return;
    case 0x1208E:
        memory[ds*16+si] = 0x00;
        return;
    } while (1);
}
function* sub_12092() {
    di = 0x1427;
    yield* sub_120A0();
}
function* sub_12099() {
    di = 0x12de;
    yield* sub_120A0();
}
function* sub_120A0() {
    r8[al] = memory[ds*16+di];
    memory[ds*16+si] = r8[al];
    r8[al] = memory[ds*16+di + 2];
    memory[ds*16+si + 2] = r8[al];
    r8[al] = memory[ds*16+di + 22];
    memory[ds*16+si + 22] = r8[al];
    r8[al] = memory[ds*16+di + 4];
    memory[ds*16+si + 4] = r8[al];
    r8[al] = memory[ds*16+di + 9];
    memory[ds*16+si + 9] = r8[al];
    r8[al] = memory[ds*16+di + 10];
    memory[ds*16+si + 10] = r8[al];
    r8[al] = memory[ds*16+di + 11];
    memory[ds*16+si + 11] = r8[al];
    r8[al] = memory[ds*16+di + 12];
    memory[ds*16+si + 12] = r8[al];
    r16[ax] = memory16get(ds*16+di + 15);
    memory16set(ds*16+si + 15, r16[ax]);
    r8[al] = memory[ds*16+di + 18];
    memory[ds*16+si + 18] = r8[al];
}
function* sub_120DB() {
    yield* sub_12676();
    yield* sub_120F0();
    push(si);
    r8[al] = memory[ds*16+si + 19];
    r8[ah] = 0x00;
    push(r16[ax]);
    r8[al] = memory[ds*16+si + 20];
    push(r16[ax]);
    yield* sub_109B5();
}
function* sub_120F0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r16[ax] = memory16get(ds*16+si + 5);
        memory16set(ds*16+0x12A3, r16[ax]);
        r16[ax] = memory16get(ds*16+si + 7);
        memory16set(ds*16+0x12A5, r16[ax]);
        r8[al] = memory[ds*16+si + 3];
        memory[ds*16+0x12A1] = r8[al];
        r8[al] = memory[ds*16+si];
        if (!(r8[al] & 0x10)) {
            pc = 0x12119;
            break;
        }
        memory16set(ds*16+0x12A3, memory16get(ds*16+0x12A3) - 0x000c);
        memory16set(ds*16+0x12A5, memory16get(ds*16+0x12A5) - 0x0008);
        memory16set(ds*16+0x12A5, memory16get(ds*16+0x12A5) & 0x03ff);
    case 0x12119:
        si = 0x129e;
        yield* sub_10B58();
        si = pop();
        return;
    } while (1);
}
function* sub_12121() {
    r8[cl] = memory[ds*16+r16[bx]];
    r8[ch] = 0x00;
    r16[bx] += 1;
    r8[al] = memory[ds*16+si + 4];
    r8[ah] = 0x00;
    di = r16[ax];
    r8[al] = memory[ds*16+r16[bx] + di];
    memory[ds*16+si + 9] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16+r16[bx] + di];
    memory[ds*16+si + 10] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16+r16[bx] + di];
    memory[ds*16+si + 11] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16+r16[bx] + di];
    memory[ds*16+si + 12] = r8[al];
    r16[bx] += r16[cx];
    di <<= 1;
    di <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + di);
    memory16set(ds*16+si + 13, r16[ax]);
    r16[bx] += 0x0002;
    r16[ax] = memory16get(ds*16+r16[bx] + di);
    memory16set(ds*16+si + 15, r16[ax]);
}
function* sub_1215B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0001;
        r16[ax] = memory16get(ds*16+0x1B91);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 7);
        if (r16s[ax] <= signed16(0x008c)) {
            pc = 0x12171;
            break;
        }
        memory[ds*16+si + 4] = 0x02;
        r16[cx] = 0x0000;
        return;
    case 0x12171:
        if (r16s[ax] >= signed16(0xfff0)) {
            pc = 0x121A0;
            break;
        }
        r8[ah] = memory[ds*16+si + 4];
        r8[al] = memory[ds*16+si];
        if (!(r8[al] & 0x20)) {
            pc = 0x1218D;
            break;
        }
        r8[ah] += 1;
        if (r8s[ah] <= signed8(0x04)) {
            pc = 0x1218B;
            break;
        }
        memory[ds*16+si] &= 0xdf;
        r8[ah] = 0x04;
    case 0x1218B:
        pc = 0x12199;
        break;
    case 0x1218D:
        r8[ah] -= 1;
        if (r8s[ah] >= signed8(0x00)) {
            pc = 0x12199;
            break;
        }
        memory[ds*16+si] |= 0x20;
        r8[ah] = 0x00;
    case 0x12199:
        memory[ds*16+si + 4] = r8[ah];
        r16[cx] = 0x0000;
        return;
    case 0x121A0:
        r16[bx] = memory16get(ds*16+0x1B8F);
        r16[bx] = r16[bx] - memory16get(ds*16+si + 5);
        if (r16s[bx] >= 0) {
            pc = 0x121C2;
            break;
        }
        if (r16s[bx] <= signed16(0xffe0)) {
            pc = 0x121B3;
            break;
        }
        memory[ds*16+si + 4] = 0x02;
        return;
    case 0x121B3:
        if (r16s[ax] <= signed16(0x0020)) {
            pc = 0x121BD;
            break;
        }
        memory[ds*16+si + 4] = 0x01;
        return;
    case 0x121BD:
        memory[ds*16+si + 4] = 0x00;
        return;
    case 0x121C2:
        if (r16s[bx] >= signed16(0x0020)) {
            pc = 0x121CC;
            break;
        }
        memory[ds*16+si + 4] = 0x02;
        return;
    case 0x121CC:
        if (r16s[ax] <= signed16(0x0020)) {
            pc = 0x121D6;
            break;
        }
        memory[ds*16+si + 4] = 0x03;
        return;
    case 0x121D6:
        memory[ds*16+si + 4] = 0x04;
        return;
    } while (1);
}
function* sub_121DC() {
    r16[ax] = 0x403c;
    push(r16[ax]);
    r16[ax] = 0x1e11;
    push(r16[ax]);
    r16[ax] = 0x0038;
    push(r16[ax]);
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
    yield* sub_12200();
    yield* sub_1264A();
    yield* sub_12A7F();
    yield* sub_122B1();
}
function* sub_12200() {
    yield* sub_1250B();
    yield* sub_12553();
    yield* sub_1259B();
    yield* sub_1237C();
}
function* sub_1220D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x944C] += 1;
        r8[al] = memory[ds*16+0x944C];
        r8[al] &= 0x03;
        if (r8[al] != 0) {
            pc = 0x12228;
            break;
        }
        r16[ax] = 0x0000;
        push(r16[ax]);
        push(r16[ax]);
        push(r16[ax]);
        r8[al] = memory[ds*16+0x94FE];
        push(r16[ax]);
        yield* sub_1269E();
        yield* sub_12714();
    case 0x12228:
        r16[ax] = memory16get(ds*16+0x953C);
        if (r16[ax] == 0x0000) {
            pc = 0x12246;
            break;
        }
        if (r16s[ax] >= 0 /*CHECK*/) {
            pc = 0x12237;
            break;
        }
        yield* sub_1252F();
        pc = 0x12240;
        break;
    case 0x12237:
        r16[cx] = r16[ax];
    case 0x12239:
        push(r16[cx]);
        yield* sub_12542();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12239;
            break;
        }
    case 0x12240:
        memory16set(ds*16+0x953C, 0x0000);
    case 0x12246:
        r16[ax] = memory16get(ds*16+0x9540);
        if (r16[ax] == 0x0000) {
            pc = 0x12264;
            break;
        }
        if (r16s[ax] >= 0 /*CHECK*/) {
            pc = 0x12255;
            break;
        }
        yield* sub_12577();
        pc = 0x1225E;
        break;
    case 0x12255:
        r16[cx] = r16[ax];
    case 0x12257:
        push(r16[cx]);
        yield* sub_1258A();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12257;
            break;
        }
    case 0x1225E:
        memory16set(ds*16+0x9540, 0x0000);
    case 0x12264:
        r16[ax] = memory16get(ds*16+0x9544);
        if (r16[ax] == 0x0000) {
            pc = 0x1228A;
            break;
        }
        if (r16s[ax] >= 0 /*CHECK*/) {
            pc = 0x1227B;
            break;
        }
        r16[ax] = -r16[ax];
        r16[cx] = r16[ax];
    case 0x12272:
        push(r16[cx]);
        yield* sub_125BF();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12272;
            break;
        }
        pc = 0x12284;
        break;
    case 0x1227B:
        r16[cx] = r16[ax];
    case 0x1227D:
        push(r16[cx]);
        yield* sub_125D2();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1227D;
            break;
        }
    case 0x12284:
        memory16set(ds*16+0x9544, 0x0000);
    case 0x1228A:
        r16[ax] = memory16get(ds*16+0x9538);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0 /*CHECK*/) {
            pc = 0x122A1;
            break;
        }
        r16[ax] = -r16[ax];
        r16[cx] = r16[ax];
    case 0x12298:
        push(r16[cx]);
        yield* sub_12464();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12298;
            break;
        }
        pc = 0x122AA;
        break;
    case 0x122A1:
        r16[cx] = r16[ax];
    case 0x122A3:
        push(r16[cx]);
        yield* sub_1239B();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x122A3;
            break;
        }
    case 0x122AA:
        memory16set(ds*16+0x9538, 0x0000);
        return;
    } while (1);
}
function* sub_122B1() {
    memory16set(ds*16+0x9534, 0x0003);
    yield* sub_122E1();
    yield* sub_122F9();
    yield* sub_12311();
}
function* sub_122C1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9534, memory16get(ds*16+0x9534) + 1);
        r16[ax] = memory16get(ds*16+0x9534);
        if (r16[ax] <= 0x0003) {
            pc = 0x122D4;
            break;
        }
        memory16set(ds*16+0x9534, 0x0003);
        return;
    case 0x122D4:
        if (r16[ax] == 0x0003)
            _STOP_("goto loc_12311");
        if (r16[ax] == 0x0002)
            _STOP_("goto loc_122F9");
        if (r16[ax] == 0x0001)
            _STOP_("goto loc_122E1");
        return;
    } while (1);
}
function* sub_122E1() {
    r16[ax] = 0x43e6;
    push(r16[ax]);
    r16[ax] = 0x1b90;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_122F9() {
    r16[ax] = 0x43e6;
    push(r16[ax]);
    r16[ax] = 0x1b93;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12311() {
    r16[ax] = 0x43e6;
    push(r16[ax]);
    r16[ax] = 0x1b96;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12329() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9534, memory16get(ds*16+0x9534) - 1);
        r16[ax] = memory16get(ds*16+0x9534);
        if (r16[ax] == 0x0002) {
            pc = 0x12368;
            break;
        }
        if (r16[ax] == 0x0001) {
            pc = 0x12354;
            break;
        }
        if (r16[ax] == 0x0000) {
            pc = 0x12340;
            break;
        }
        return;
    case 0x12340:
        r16[ax] = 0x1b90;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x12354:
        r16[ax] = 0x1b93;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x12368:
        r16[ax] = 0x1b96;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    } while (1);
}
function* sub_1237C() {
    memory16set(ds*16+0x9536, 0x0006);
    memory16set(ds*16+0x9538, 0x0000);
    yield* sub_123D4();
    yield* sub_123EC();
    yield* sub_12404();
    yield* sub_1241C();
    yield* sub_12434();
    yield* sub_1244C();
}
function* sub_1239B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9536, memory16get(ds*16+0x9536) + 1);
        r16[ax] = memory16get(ds*16+0x9536);
        if (r16[ax] <= 0x0006) {
            pc = 0x123AE;
            break;
        }
        memory16set(ds*16+0x9536, 0x0006);
        return;
    case 0x123AE:
        push(r16[ax]);
        r8[al] = 0x08;
        yield* sub_13840();
        r16[ax] = pop();
        if (r16[ax] == 0x0001)
            yield* sub_123D4();
        else if (r16[ax] == 0x0002)
            yield* sub_123EC();
        else if (r16[ax] == 0x0003)
            yield* sub_12404();
        else if (r16[ax] == 0x0004)
            yield* sub_1241C();
        else if (r16[ax] == 0x0005)
            yield* sub_12434();
        else if (r16[ax] == 0x0006)
            yield* sub_1244C();
        return;
    } while (1);
}
function* sub_123D4() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1b99;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_123EC() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1b9b;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12404() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1b9d;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_1241C() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1b9f;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12434() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1ba1;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_1244C() {
    r16[ax] = 0x43ee;
    push(r16[ax]);
    r16[ax] = 0x1ba3;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12464() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9536);
        memory16set(ds*16+0x9536, memory16get(ds*16+0x9536) - 1);
        if (memory16gets(ds*16+0x9536) >= 0) {
            pc = 0x12474;
            break;
        }
        memory16set(ds*16+0x9536, 0x0000);
        return;
    case 0x12474:
        if (r16[ax] == 0x0001) {
            pc = 0x12493;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x124A7;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x124BB;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x124CF;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x124E3;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x124F7;
            break;
        }
        return;
    case 0x12493:
        r16[ax] = 0x1b99;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x124A7:
        r16[ax] = 0x1b9b;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x124BB:
        r16[ax] = 0x1b9d;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x124CF:
        r16[ax] = 0x1b9f;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x124E3:
        r16[ax] = 0x1ba1;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    case 0x124F7:
        r16[ax] = 0x1ba3;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12D9A();
        return;
    } while (1);
}
function* sub_1250B() {
    memory16set(ds*16+0x953A, 0x002c);
    memory16set(ds*16+0x953C, 0x0000);
    r16[ax] = 0x48f6;
    push(r16[ax]);
    r16[ax] = 0x1b88;
    push(r16[ax]);
    r16[ax] = 0x002c;
    push(r16[ax]);
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_1252F() {
    r16[ax] = memory16get(ds*16+0x953A);
    r16[ax] -= 1;
    if (r16s[ax] >= 0)
        yield* sub_12536();
}
function* sub_12536() {
    memory16set(ds*16+0x953A, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1b88;
    push(r16[ax]);
    yield* sub_125E3();
}
function* sub_12542() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x953A);
        if (r16[ax] < 0x002c) {
            pc = 0x1254B;
            break;
        }
        return;
    case 0x1254B:
        yield* sub_12536();
        memory16set(ds*16+0x953A, memory16get(ds*16+0x953A) + 1);
        return;
    } while (1);
}
function* sub_12553() {
    memory16set(ds*16+0x953E, 0x0030);
    memory16set(ds*16+0x9540, 0x0000);
    r16[ax] = 0x2ce6;
    push(r16[ax]);
    r16[ax] = 0x1cc8;
    push(r16[ax]);
    r16[ax] = 0x0030;
    push(r16[ax]);
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12577() {
    r16[ax] = memory16get(ds*16+0x953E);
    r16[ax] -= 1;
    if (r16s[ax] >= 0)
        yield* sub_1257E();
}
function* sub_1257E() {
    memory16set(ds*16+0x953E, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1cc8;
    push(r16[ax]);
    yield* sub_125E3();
}
function* sub_1258A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x953E);
        if (r16[ax] < 0x0030) {
            pc = 0x12593;
            break;
        }
        return;
    case 0x12593:
        yield* sub_1257E();
        memory16set(ds*16+0x953E, memory16get(ds*16+0x953E) + 1);
        return;
    } while (1);
}
function* sub_1259B() {
    memory16set(ds*16+0x9542, 0x0038);
    memory16set(ds*16+0x9544, 0x0000);
    r16[ax] = 0x4496;
    push(r16[ax]);
    r16[ax] = 0x1e08;
    push(r16[ax]);
    r16[ax] = 0x0038;
    push(r16[ax]);
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_125BF() {
    r16[ax] = memory16get(ds*16+0x9542);
    r16[ax] -= 1;
    if (r16s[ax] >= 0)
        yield* sub_125C6();
}
function* sub_125C6() {
    memory16set(ds*16+0x9542, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1e08;
    push(r16[ax]);
    yield* sub_125E3();
}
function* sub_125D2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9542);
        if (r16[ax] < 0x0038) {
            pc = 0x125DB;
            break;
        }
        return;
    case 0x125DB:
        yield* sub_125C6();
        memory16set(ds*16+0x9542, memory16get(ds*16+0x9542) + 1);
        return;
    } while (1);
}
function* sub_125E3() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = _stack16(bp + arg_2);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        di = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0805;
        out16(r16[dx], r16[ax]);
        r16[cx] = _stack16(bp + arg_2);
        r16[cx] &= 0x0007;
        r8[ah] = 0x80;
        r8[ah] >>= r8[cl];
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[bl] = r8[ah];
        r16[ax] = 0x1803;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x0007;
    case 0x1261E:
        r8[al] = memoryVideoGet(es, di);
        if (r8[al] & r8[bl]) {
            pc = 0x1262D;
            break;
        }
        memoryVideoSet(es, di, r8[bl]);
        memoryVideoSet(es, di + 8192, r8[bl]);
    case 0x1262D:
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1261E;
            break;
        }
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_1264A() {
    r8[al] = 0x00;
    memory[ds*16+0x94A9] = r8[al];
    memory[ds*16+0x94AA] = r8[al];
    memory[ds*16+0x94AB] = r8[al];
    memory[ds*16+0x94AC] = r8[al];
    memory[ds*16+0x94AD] = r8[al];
    memory[ds*16+0x94AE] = r8[al];
    yield* sub_12714();
}
function* sub_12662() {
    r16[ax] = 0x0000;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    yield* sub_1269E();
}
function* sub_12676() {
    r16[ax] = 0x0000;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    yield* sub_1269E();
}
function* sub_1268A() {
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    yield* sub_1269E();
}
function* sub_1269E() {
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    let arg_6 = 10;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r8[al] = memory[ds*16+0x94AE];
        r8[al] = r8[al] + _stack16(bp + arg_0);
        if (r8[al] <= 0x09) {
            pc = 0x126B1;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16+0x94AD] += 1;
    case 0x126B1:
        memory[ds*16+0x94AE] = r8[al];
        r8[al] = memory[ds*16+0x94AD];
        r8[al] = r8[al] + _stack16(bp + arg_2);
        if (r8[al] <= 0x09) {
            pc = 0x126C4;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16+0x94AC] += 1;
    case 0x126C4:
        memory[ds*16+0x94AD] = r8[al];
        r8[al] = memory[ds*16+0x94AC];
        r8[al] = r8[al] + _stack16(bp + arg_4);
        if (r8[al] <= 0x09) {
            pc = 0x126D7;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16+0x94AB] += 1;
    case 0x126D7:
        memory[ds*16+0x94AC] = r8[al];
        r8[al] = memory[ds*16+0x94AB];
        r8[al] = r8[al] + _stack16(bp + arg_6);
        if (r8[al] <= 0x09) {
            pc = 0x126EA;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16+0x94AA] += 1;
    case 0x126EA:
        memory[ds*16+0x94AB] = r8[al];
        r8[al] = memory[ds*16+0x94AA];
        if (r8[al] <= 0x09) {
            pc = 0x12701;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16+0x94A9] += 1;
        push(r16[ax]);
        push(si);
        yield* sub_122C1();
        si = pop();
        r16[ax] = pop();
    case 0x12701:
        memory[ds*16+0x94AA] = r8[al];
        r8[al] = memory[ds*16+0x94A9];
        if (r8[al] <= 0x09) {
            pc = 0x1270D;
            break;
        }
        r8[al] -= 0x0a;
    case 0x1270D:
        memory[ds*16+0x94A9] = r8[al];
        bp = pop();
        _stackReduce(8);
        return;
    } while (1);
}
function* sub_12714() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x944D] = 0x01;
        si = 0x94a9;
        r16[cx] = 0x0006;
        r16[dx] = 0x0000;
    case 0x12722:
        push(r16[cx]);
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x1272D;
            break;
        }
        memory[ds*16+0x944D] = 0x00;
    case 0x1272D:
        r8[cl] = memory[ds*16+0x944D];
        if (r8[cl] != 0x00) {
            pc = 0x1275E;
            break;
        }
        push(r16[dx]);
        push(si);
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5471);
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = memory16get(ds*16+r16[bx] + 5491);
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_12CEA();
        si = pop();
        r16[dx] = pop();
        r16[dx] += 0x0002;
    case 0x1275E:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12722;
            break;
        }
        return;
    } while (1);
}
function* sub_12762() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0012;
        r16[ax] = ds;
        es = r16[ax];
        di = 0x94af;
        flags.direction = false;
        r16[ax] = 0x0000;
        rep_stosw_data_forward();
        r16[cx] = 0x002a;
        di = 0x9455;
        r8[al] = 0x2e;
        r8[ah] = 0x2e;
        rep_stosw_data_forward();
        memory[ds*16+0x9455] = 0x5f;
        r8[al] = 0x00;
        r16[cx] = 0x0007;
        si = 0x94da;
    case 0x1278B:
        memory[ds*16+si] = r8[al];
        r8[al] += 1;
        si += 1;
        if (--r16[cx]) {
            pc = 0x1278B;
            break;
        }
        di = 0x9455;
        r16[dx] = 0x1506;
        r16[cx] = 0x008c;
        yield* sub_10644();
        return;
    } while (1);
}
function* sub_1279F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_12809();
        r8[al] = memory[ds*16+0x94E0];
        if (r8[al] != 0x00) {
            pc = 0x127AF;
            break;
        }
        memory[ds*16+0x9546] = 0x00;
        return;
    case 0x127AF:
        memory[ds*16+0x9546] = 0x01;
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        push(r16[bx]);
        r16[bx] += 0x94a9;
        si = 0x94a9;
        r16[cx] = 0x0006;
    case 0x127C9:
        lodsb_data_forward();
        memory[ds*16+r16[bx]] = r8[al];
        r16[bx] += 1;
        if (--r16[cx]) {
            pc = 0x127C9;
            break;
        }
        r16[bx] = pop();
        r16[bx] <<= 1;
        r16[bx] += 0x9455;
        memory16set(ds*16+0x9451, r16[bx]);
        si = 0x9455;
        r16[cx] = 0x000c;
    case 0x127E0:
        lodsb_data_forward();
        memory[ds*16+r16[bx]] = r8[al];
        r16[bx] += 1;
        if (--r16[cx]) {
            pc = 0x127E0;
            break;
        }
        si = 0x94da;
    case 0x127E9:
        r8[al] = memory[ds*16+si];
        if (r8[al] == 0x00) {
            pc = 0x127F2;
            break;
        }
        si += 1;
        pc = 0x127E9;
        break;
    case 0x127F2:
        r8[al] = memory[ds*16+0x94E0];
        memory[ds*16+si] = r8[al];
        memory[ds*16+0x94E0] = 0x00;
        si -= 0x94da;
        r16[ax] = si;
        memory[ds*16+0x9450] = r8[al];
        yield* sub_128DA();
        return;
    } while (1);
}
function* sub_12809() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x94DA];
        memory[ds*16+0x94D3] = r8[al];
        r8[al] = memory[ds*16+0x94DB];
        memory[ds*16+0x94D4] = r8[al];
        r8[al] = memory[ds*16+0x94DC];
        memory[ds*16+0x94D5] = r8[al];
        r8[al] = memory[ds*16+0x94DD];
        memory[ds*16+0x94D6] = r8[al];
        r8[al] = memory[ds*16+0x94DE];
        memory[ds*16+0x94D7] = r8[al];
        r8[al] = memory[ds*16+0x94DF];
        memory[ds*16+0x94D8] = r8[al];
        r8[al] = memory[ds*16+0x94E0];
        memory[ds*16+0x94D9] = r8[al];
        si = 0x94d3;
        di = 0x94da;
        r16[cx] = 0x0007;
    case 0x1283C:
        push(r16[cx]);
        push(si);
    case 0x1283E:
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0xff) {
            pc = 0x12847;
            break;
        }
        si += 1;
        pc = 0x1283E;
        break;
    case 0x12847:
        if (si == 0x94d9) {
            pc = 0x12865;
            break;
        }
        r16[bx] = si;
    case 0x1284F:
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] == 0xff) {
            pc = 0x1285F;
            break;
        }
        yield* sub_12872();
        if (r8[al] == 0x00) {
            pc = 0x1285F;
            break;
        }
        si = r16[bx];
    case 0x1285F:
        if (r16[bx] != 0x94d9) {
            pc = 0x1284F;
            break;
        }
    case 0x12865:
        r8[al] = memory[ds*16+si];
        memory[ds*16+si] = 0xff;
        memory[ds*16+di] = r8[al];
        di += 1;
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1283C;
            break;
        }
        return;
    } while (1);
}
function* sub_12872() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        r8[al] = memory[ds*16+si];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
        r16[ax] += 0x94a9;
        si = r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
        r16[ax] += 0x94a9;
        di = r16[ax];
        r8[al] = memory[ds*16+di];
        if (r8[al] > memory[ds*16+si]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si]) {
            pc = 0x128D0;
            break;
        }
        r8[al] = memory[ds*16+di + 1];
        if (r8[al] > memory[ds*16+si + 1]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si + 1]) {
            pc = 0x128D0;
            break;
        }
        r8[al] = memory[ds*16+di + 2];
        if (r8[al] > memory[ds*16+si + 2]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si + 2]) {
            pc = 0x128D0;
            break;
        }
        r8[al] = memory[ds*16+di + 3];
        if (r8[al] > memory[ds*16+si + 3]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si + 3]) {
            pc = 0x128D0;
            break;
        }
        r8[al] = memory[ds*16+di + 4];
        if (r8[al] > memory[ds*16+si + 4]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si + 4]) {
            pc = 0x128D0;
            break;
        }
        r8[al] = memory[ds*16+di + 5];
        if (r8[al] > memory[ds*16+si + 5]) {
            pc = 0x128D5;
            break;
        }
        if (r8[al] < memory[ds*16+si + 5])
            _STOP_("goto $+2");
    case 0x128D0:
        r8[al] = 0x00;
        di = pop();
        si = pop();
        return;
    case 0x128D5:
        r8[al] = 0x01;
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_128DA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x94da;
        di = 0x01b1;
        r16[cx] = 0x0006;
    case 0x128E3:
        push(r16[cx]);
        di += 0x0002;
        r16[ax] = memory16get(ds*16+di);
        di += 0x0002;
        push(si);
        push(di);
        yield* sub_12959();
        di = pop();
        si = pop();
        di += 0x0002;
        r16[ax] = memory16get(ds*16+di);
        di += 0x0002;
        push(si);
        push(di);
        yield* sub_12907();
        di = pop();
        si = pop();
        si += 1;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x128E3;
            break;
        }
        return;
    } while (1);
}
function* sub_12907() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x944E, r16[ax]);
        r8[al] = memory[ds*16+si];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] += 0x94a9;
        si = r16[ax];
        memory[ds*16+0x944D] = 0x01;
        r16[cx] = 0x0006;
        r16[dx] = 0x0000;
    case 0x12926:
        push(r16[cx]);
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x12931;
            break;
        }
        memory[ds*16+0x944D] = 0x00;
    case 0x12931:
        r8[cl] = memory[ds*16+0x944D];
        if (r8[cl] == 0x00) {
            pc = 0x1293F;
            break;
        }
        r16[ax] = 0x6f6c;
        pc = 0x12949;
        break;
    case 0x1293F:
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 5503);
    case 0x12949:
        push(r16[dx]);
        push(si);
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_129AE();
        si = pop();
        r16[dx] = pop();
        r16[dx] += 0x0006;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12926;
            break;
        }
        return;
    } while (1);
}
function* sub_12959() {
    memory16set(ds*16+0x944E, r16[ax]);
    r8[al] = memory[ds*16+si];
    r8[ah] = r8[al];
    r8[al] <<= 1;
    r8[al] += r8[ah];
    r8[ah] = 0x00;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x9455;
    si = r16[ax];
    yield* sub_1296F();
}
function* sub_1296F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000c;
        r16[dx] = 0x0000;
    case 0x12975:
        push(r16[cx]);
        lodsb_data_forward();
        push(si);
        push(r16[dx]);
        if (r8[al] != 0x20) {
            pc = 0x12982;
            break;
        }
        r16[ax] = 0x6546;
        pc = 0x129A0;
        break;
    case 0x12982:
        if (r8[al] != 0x2e) {
            pc = 0x1298B;
            break;
        }
        r16[ax] = 0x6f6c;
        pc = 0x129A0;
        break;
    case 0x1298B:
        if (r8[al] != 0x5f) {
            pc = 0x12994;
            break;
        }
        r16[ax] = 0x764c;
        pc = 0x129A0;
        break;
    case 0x12994:
        r8[al] -= 0x41;
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
    case 0x129A0:
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_129AE();
        r16[dx] = pop();
        r16[dx] += 0x0006;
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12975;
            break;
        }
        return;
    } while (1);
}
function* sub_129AE() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ds*16+0x94F0);
        es = r16[ax];
        di = memory16get(ds*16+0x944E);
        di = di + _stack16(bp + arg_0);
        r16[ax] = memory16get(ds*16+0x94EA);
        push(ds);
        ds = r16[ax];
        si = _stack16(bp + arg_2);
        r16[cx] = 0x000b;
    case 0x129C9:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        di += 0x009a;
        si += 0x009a;
        if (--r16[cx]) {
            pc = 0x129C9;
            break;
        }
        ds = pop();
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_129DB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9453, 0x0000);
    case 0x129E1:
        r16[ax] = memory16get(ds*16+0x9453);
        if (r16[ax] >= 0x000c) {
            pc = 0x12A39;
            break;
        }
        yield* sub_10541();
        if (r8[al] == 0x00) {
            pc = 0x12A39;
            break;
        }
        if (r8[al] != 0x08) {
            pc = 0x12A0D;
            break;
        }
        r16[bx] = memory16get(ds*16+0x9451);
        r16[bx] = r16[bx] + memory16get(ds*16+0x9453);
        memory[ds*16+r16[bx]] = 0x2e;
        memory16set(ds*16+0x9453, memory16get(ds*16+0x9453) - 1);
        if (memory16gets(ds*16+0x9453) >= 0) {
            pc = 0x12A0B;
            break;
        }
        memory16set(ds*16+0x9453, 0x0000);
    case 0x12A0B:
        pc = 0x12A1B;
        break;
    case 0x12A0D:
        r16[bx] = memory16get(ds*16+0x9451);
        r16[bx] = r16[bx] + memory16get(ds*16+0x9453);
        memory[ds*16+r16[bx]] = r8[al];
        memory16set(ds*16+0x9453, memory16get(ds*16+0x9453) + 1);
    case 0x12A1B:
        r16[bx] = memory16get(ds*16+0x9453);
        if (r16[bx] >= 0x000c) {
            pc = 0x12A2B;
            break;
        }
        r16[bx] = r16[bx] + memory16get(ds*16+0x9451);
        memory[ds*16+r16[bx]] = 0x5f;
    case 0x12A2B:
        yield* sub_12A64();
        yield* sub_13498();
        yield* sub_10B8E();
        yield* sub_13383();
        pc = 0x129E1;
        break;
    case 0x12A39:
        r16[bx] = memory16get(ds*16+0x9453);
        if (r16[bx] >= 0x000c) {
            pc = 0x12A52;
            break;
        }
        r16[bx] = r16[bx] + memory16get(ds*16+0x9451);
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] != 0x5f) {
            pc = 0x12A52;
            break;
        }
        memory[ds*16+r16[bx]] = 0x2e;
        yield* sub_12A64();
    case 0x12A52:
        di = 0x9455;
        r16[dx] = 0x1506;
        r16[cx] = 0x008c;
        yield* sub_10674();
        memory[ds*16+0x9546] = 0x00;
        return;
    } while (1);
}
function* sub_12A64() {
    si = memory16get(ds*16+0x9451);
    r8[bl] = memory[ds*16+0x9450];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + 435);
    memory16set(ds*16+0x944E, r16[ax]);
    yield* sub_1296F();
}
function* sub_12A7F() {
    memory[ds*16+0x952E] = 0x00;
    memory[ds*16+0x952F] = 0x00;
    memory[ds*16+0x9530] = 0x00;
    memory[ds*16+0x9531] = 0x00;
    memory[ds*16+0x9532] = 0x00;
    memory[ds*16+0x9533] = 0x00;
    r16[ax] = 0x1178;
    push(r16[ax]);
    r16[ax] = 0x1b82;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x1678;
    push(r16[ax]);
    r16[ax] = 0x1cc2;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x1b78;
    push(r16[ax]);
    r16[ax] = 0x1e02;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x2078;
    push(r16[ax]);
    r16[ax] = 0x1b85;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x2578;
    push(r16[ax]);
    r16[ax] = 0x1cc5;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x2a78;
    push(r16[ax]);
    r16[ax] = 0x1e05;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12B28() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0005;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_1269E();
        r16[ax] = pop();
        if (r8[al] == 0x00) {
            pc = 0x12B59;
            break;
        }
        if (r8[al] == 0x01) {
            pc = 0x12B76;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x12B93;
            break;
        }
        if (r8[al] == 0x03) {
            pc = 0x12BB0;
            break;
        }
        if (r8[al] == 0x04) {
            pc = 0x12BCD;
            break;
        }
        if (r8[al] != 0x05)
            return;
        pc = 0x12BEA;
        break;
        return;
    case 0x12B59:
        memory[ds*16+0x952E] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1b82;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    case 0x12B76:
        memory[ds*16+0x952F] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1cc2;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    case 0x12B93:
        memory[ds*16+0x9530] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1e02;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    case 0x12BB0:
        memory[ds*16+0x9531] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1b85;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    case 0x12BCD:
        memory[ds*16+0x9532] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1cc5;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    case 0x12BEA:
        memory[ds*16+0x9533] = 0x01;
        r16[ax] = 0x2f78;
        push(r16[ax]);
        r16[ax] = 0x1e05;
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        yield* sub_12CEA();
        return;
    } while (1);
}
function* sub_12C07() {
    r16[ax] = 0x0a0b;
    push(r16[ax]);
    r16[ax] = 0x0013;
    push(r16[ax]);
    r16[ax] = 0x0030;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_12D9A();
    r16[ax] = 0x0aac;
    push(r16[ax]);
    r16[ax] = 0x0011;
    push(r16[ax]);
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12D9A();
    r16[ax] = 0x5a5c;
    push(r16[ax]);
    r16[ax] = 0x0b4d;
    push(r16[ax]);
    r16[ax] = 0x0078;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12C45() {
    r16[ax] = 0x0aac;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_12D9A();
    r16[ax] = 0x0b4d;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12D9A();
    r16[ax] = 0x7592;
    push(r16[ax]);
    r16[ax] = 0x0c8f;
    push(r16[ax]);
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x000c;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12CEA();
    r16[ax] = 0x1ab8;
    push(r16[ax]);
    r16[ax] = 0x0ce4;
    push(r16[ax]);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = 0x000d;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12C9A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = 0x0dcc;
        push(r16[ax]);
        r16[ax] = 0x0011;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_12D9A();
        r16[ax] = pop();
        if (r8[al] != 0x06) {
            pc = 0x12CBC;
            break;
        }
        r8[al] = 0x00;
        yield* sub_12CC7();
        r8[al] = 0x06;
    {yield* sub_12CC7(); return; };
    case 0x12CBC:
        if (r8[al] != 0x07)
            _STOP_("goto loc_12CC7");
        r8[al] = 0x01;
        yield* sub_12CC7();
        r8[al] = 0x07;
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_12CC7() {
    r8[bl] = r8[al];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + 5407);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+r16[bx] + 5423);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+r16[bx] + 5439);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+r16[bx] + 5455);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+r16[bx] + 5391);
    push(r16[ax]);
    yield* sub_12CEA();
}
function* sub_12CEA() {
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    let arg_6 = 10;
    let arg_8 = 12;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        di = _stack16(bp + arg_6);
        r16[bx] = _stack16(bp + arg_0);
        r16[bx] = memory16get(ds*16+r16[bx] + -27416 + 0x10000);
        si = _stack16(bp + arg_8);
        push(ds);
        push(r16[bx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0a05;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0007;
        out16(r16[dx], r16[ax]);
        r16[cx] = _stack16(bp + arg_4);
        r16[cx] >>= 1;
        r8[ah] = 0x80;
        r8[al] = 0x08;
        ds = pop();
        r16[bx] = _stack16(bp + arg_2);
    case 0x12D19:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(di);
        push(si);
    case 0x12D1E:
        r8[bh] = 0x22;
    case 0x12D20:
        r8[bl] = memory[ds*16+si];
        si += 1;
        if (r8[bh] != r8[bl]) {
            pc = 0x12D3D;
            break;
        }
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12D32;
            break;
        }
        r8[ah] = 0x40;
        di += 1;
        if (--r16[cx]) {
            pc = 0x12D20;
            break;
        }
        pc = 0x12D76;
        break;
    case 0x12D32:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12D39;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x12D39:
        if (--r16[cx]) {
            pc = 0x12D20;
            break;
        }
        pc = 0x12D76;
        break;
    case 0x12D3D:
        r8[bh] = r8[bl];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        if (r8[bl] == 0x02) {
            pc = 0x12D55;
            break;
        }
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, di, r8[bl]);
        memoryVideoAnd(es, di + 8192, r8[bl]);
    case 0x12D55:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12D5C;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x12D5C:
        r8[bh] &= 0x0f;
        if (r8[bh] == 0x02) {
            pc = 0x12D6D;
            break;
        }
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, di, r8[bh]);
        memoryVideoAnd(es, di + 8192, r8[bh]);
    case 0x12D6D:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12D74;
            break;
        }
        r8[ah] = 0x80;
        di += 1;
    case 0x12D74:
        if (--r16[cx]) {
            pc = 0x12D1E;
            break;
        }
    case 0x12D76:
        si = pop();
        si += 0x00a0;
        di = pop();
        di += 0x0028;
        di &= 0x7fff;
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x12D19;
            break;
        }
        ds = pop();
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f07;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(10);
        return;
    } while (1);
}
function* sub_12D9A() {
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    let arg_6 = 10;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        di = _stack16(bp + arg_6);
        r16[dx] = 0x03ce;
        r16[ax] = _stack16(bp + arg_0);
        r8[ah] = r8[al];
        r8[al] = 0x00;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        flags.direction = false;
        r16[bx] = _stack16(bp + arg_2);
    case 0x12DB8:
        push(di);
        r16[cx] = _stack16(bp + arg_4);
        rep_stosb_video_forward();
        di = pop();
        push(di);
        di += 0x2000;
        r16[cx] = _stack16(bp + arg_4);
        rep_stosb_video_forward();
        di = pop();
        di += 0x0028;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x12DB8;
            break;
        }
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al] += 1;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(8);
        return;
    } while (1);
}
function* sub_12DDC() {
    r8[bl] = memory[ds*16+0x94E4];
    r16[bx] &= 0x0003;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds*16+r16[bx] + 6698);
    memory16set(ds*16+0x94E2, r16[ax]);
    memory[ds*16+0x94E4] += 1;
    memory[ds*16+0x9527] = 0xff;
}
function* sub_12DF6() {
    r8[al] = 0x00;
    memory[ds*16+0x94E5] = r8[al];
    memory[ds*16+0x94E6] = r8[al];
    memory[ds*16+0x94E7] = r8[al];
}
function* sub_12E02() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        yield* sub_11B80();
        yield* sub_1309D();
        si = pop();
        r16[ax] = memory16get(ds*16+0x952A);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[bx] = memory16get(ds*16+0x954C);
        if (!(r8[bl] & 0x01)) {
            pc = 0x12E23;
            break;
        }
        r16[ax] = -r16[ax];
        r16[ax] -= 0x0003;
        pc = 0x12E30;
        break;
    case 0x12E23:
        if (!(r8[bl] & 0x02)) {
            pc = 0x12E2D;
            break;
        }
        r16[ax] += 0x0003;
        pc = 0x12E30;
        break;
    case 0x12E2D:
        r16[ax] = 0x0000;
    case 0x12E30:
        memory16set(ds*16+0x9522, r16[ax]);
        r8[al] = memory[ds*16+si + 22];
        r16[ax] &= 0x007f;
        if (r8[al] <= 0x3f) {
            pc = 0x12E48;
            break;
        }
        r8[al] = -r8[al];
        r8[al] += 0x7f;
        yield* sub_13084();
        r16[ax] = -r16[ax];
        pc = 0x12E4B;
        break;
    case 0x12E48:
        yield* sub_13084();
    case 0x12E4B:
        memory16set(ds*16+0x9520, r16[ax]);
        r16[ax] = memory16get(ds*16+0x951E);
        r16[ax] = r16[ax] + memory16get(ds*16+0x9522);
        flags.sign = signed16(r16[ax] + memory16get(ds*16+0x9520)) < 0;
        r16[ax] = r16[ax] + memory16get(ds*16+0x9520);
        if (r16[ax] == 0) {
            pc = 0x12E6A;
            break;
        }
        if (!flags.sign) {
            pc = 0x12E63;
            break;
        }
        r16[ax] += 1;
        if (r16s[ax] >= 0) {
            pc = 0x12E61;
            break;
        }
        r16[ax] += 1;
    case 0x12E61:
        pc = 0x12E6A;
        break;
    case 0x12E63:
        r16[ax] -= 1;
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x12E6A;
            break;
        }
        r16[ax] -= 1;
    case 0x12E6A:
        if (r16s[ax] <= signed16(0x0040)) {
            pc = 0x12E74;
            break;
        }
        r16[ax] = 0x0040;
        pc = 0x12E7C;
        break;
    case 0x12E74:
        if (r16s[ax] >= signed16(0xffc0)) {
            pc = 0x12E7C;
            break;
        }
        r16[ax] = 0xffc0;
    case 0x12E7C:
        memory16set(ds*16+0x951E, r16[ax]);
        sar16(ax, 1);
        sar16(ax, 1);
        memory[ds*16+si + 22] += r8[al];
        r8[al] = memory[ds*16+si + 22];
        r16[ax] &= 0x007f;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16+r16[bx] + 5749];
        _cbw();
        r16[ax] <<= 1;
        r16[ax] += 0x0080;
        memory16set(ds*16+si + 5, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 5877];
        _cbw();
        r16[ax] <<= 1;
        r16[ax] += 0x0080;
        push(r16[bx]);
        if (r16[ax] == 0x0000) {
            pc = 0x12EBE;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div(r8[bl]);
        r8[ah] = 0x00;
    case 0x12EBE:
        r16[bx] = pop();
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 6005];
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x1594;
        yield* sub_12121();
        r8[al] = memory[ds*16+0x94E6];
        memory[ds*16+0x94E7] = r8[al];
        r8[al] = memory[ds*16+0x94E5];
        memory[ds*16+0x94E6] = r8[al];
        r8[al] = memory[ds*16+0x1BA0];
        memory[ds*16+0x94E5] = r8[al];
        r16[ax] = memory16get(ds*16+0x954C);
        r8[bl] = memory[ds*16+0x951A];
        if (!(r8[al] & 0x40)) {
            pc = 0x12F02;
            break;
        }
        if (r8[bl] != 0x02) {
            pc = 0x12F00;
            break;
        }
        memory[ds*16+0x951A] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
        memory[ds*16+0x951C] = 0x02;
    case 0x12F00:
        pc = 0x12F18;
        break;
    case 0x12F02:
        if (r8[bl] != 0x01) {
            pc = 0x12F0E;
            break;
        }
        memory[ds*16+0x951A] = 0x02;
        pc = 0x12F18;
        break;
    case 0x12F0E:
        if (r8[bl] != 0x03) {
            pc = 0x12F18;
            break;
        }
        memory[ds*16+0x951A] = 0x00;
    case 0x12F18:
        r16[ax] = memory16get(ds*16+0x954C);
        r8[bl] = memory[ds*16+0x951B];
        if (!(r8[al] & 0x20)) {
            pc = 0x12F39;
            break;
        }
        if (r8[bl] != 0x02) {
            pc = 0x12F37;
            break;
        }
        memory[ds*16+0x951B] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
        memory[ds*16+0x951C] = 0x02;
    case 0x12F37:
        return;
    case 0x12F39:
        if (r8[bl] != 0x01) {
            pc = 0x12F45;
            break;
        }
        memory[ds*16+0x951B] = 0x02;
        return;
    case 0x12F45:
        if (r8[bl] != 0x03)
            return;
        memory[ds*16+0x951B] = 0x00;
        return;
    } while (1);
}
function* sub_12F50() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x20) {
            pc = 0x12F5E;
            break;
        }
        r8[ah] = memory[ds*16+0x951A];
        r8[al] = 0xf8;
        pc = 0x12F64;
        break;
    case 0x12F5E:
        r8[ah] = memory[ds*16+0x951B];
        r8[al] = 0x08;
    case 0x12F64:
        if (r8[ah] == 0x03) {
            pc = 0x12F6E;
            break;
        }
        if (r8[ah] != 0x00) {
            pc = 0x12F90;
            break;
        }
    case 0x12F6E:
        memory[ds*16+si] = 0x00;
        si = 0x1ba1;
    case 0x12F74:
        r8[al] = memory[ds*16+si];
        if (r8[al] & 0x80)
            return;
        if (!(r8[al] & 0x01)) {
            pc = 0x12F8A;
            break;
        }
        r8[al] = memory[ds*16+si + 18];
        if (r8[al] != 0x0f) {
            pc = 0x12F8A;
            break;
        }
        push(si);
        yield* sub_13059();
        si = pop();
    case 0x12F8A:
        si += 0x0017;
        pc = 0x12F74;
        break;
        return;
    case 0x12F90:
        r8[al] = r8[al] + memory[ds*16+0x94E7];
        r16[ax] &= 0x007f;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16+r16[bx] + 5749];
        _cbw();
        r16[cx] = r16[ax];
        sar16(cx, 1);
        r16[ax] += r16[cx];
        r16[ax] += 0x0080;
        memory16set(ds*16+si + 5, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 5877];
        _cbw();
        r16[cx] = r16[ax];
        sar16(cx, 1);
        r16[ax] += r16[cx];
        r16[ax] += 0x0080;
        if (r16[ax] == 0x0000) {
            pc = 0x12FD0;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div(r8[bl]);
        r8[ah] = 0x00;
    case 0x12FD0:
        r8[bl] = memory[ds*16+0x1BA0];
        r16[bx] &= 0x007f;
        memory16set(ds*16+si + 7, r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 6290];
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = 0x1811;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_12FE8() {
    r16[bx] = memory16get(ds*16+0x9525);
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] &= 0x001f;
    r8[al] = memory[ds*16+r16[bx] + 6666];
    memory[ds*16+0x9549] = r8[al];
    r8[al] = memory[ds*16+r16[bx] + 6634];
    memory[ds*16+si + 4] = r8[al];
    r16[bx] = 0x1929;
    yield* sub_12121();
}
function* sub_1300A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9547);
        r16[ax] = r16[ax] - memory16get(ds*16+si + 19);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r16[ax] <= 0x002d) {
            pc = 0x1301F;
            break;
        }
        memory[ds*16+si] = 0x00;
        return;
    case 0x1301F:
        push(r16[ax]);
        yield* sub_13130();
        r16[ax] = pop();
        r16[ax] >>= 1;
        memory[ds*16+si + 4] = r8[al];
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16+r16[bx] + 6810];
        memory[ds*16+si + 2] = r8[al];
        r16[bx] = 0x1ac9;
        yield* sub_12121();
        r8[al] = memory[ds*16+si + 2];
        if (r8[al] == 0x02) {
            pc = 0x13040;
            break;
        }
        return;
    case 0x13040:
        r8[bl] = memory[ds*16+0x1B8E];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16+r16[bx] + 6133];
        if (r8[al] == memory[ds*16+si + 1]) {
            pc = 0x13050;
            break;
        }
        return;
    case 0x13050:
        r8[al] = 0x09;
        yield* sub_13840();
        yield* sub_13059();
        return;
    } while (1);
}
function* sub_13059() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+si] = 0x00;
        r8[al] = memory[ds*16+0x951D];
        if (r8[al] != 0x40) {
            pc = 0x1306A;
            break;
        }
        memory16set(ds*16+0x9540, memory16get(ds*16+0x9540) + 0x0006);
        return;
    case 0x1306A:
        if (r8[al] != 0x80) {
            pc = 0x13075;
            break;
        }
        memory16set(ds*16+0x953C, memory16get(ds*16+0x953C) + 0x0004);
        return;
    case 0x13075:
        if (r8[al] != 0xc0) {
            pc = 0x13080;
            break;
        }
        memory16set(ds*16+0x9544, memory16get(ds*16+0x9544) + 0x0008);
        return;
    case 0x13080:
        yield* sub_1268A();
        return;
    } while (1);
}
function* sub_13084() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] -= 0x05;
        if (r8s[al] >= 0) {
            pc = 0x1308D;
            break;
        }
        r16[ax] = 0x0000;
        return;
    case 0x1308D:
        if (r8[al] <= 0x38) {
            pc = 0x13093;
            break;
        }
        r8[al] = 0x38;
    case 0x13093:
        r8[al] >>= 1;
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] -= 0x0003;
        return;
    } while (1);
}
function* sub_1309D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x952A);
        r16[bx] += 0x0007;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] += 0x0002;
        memory16set(ds*16+0x9547, memory16get(ds*16+0x9547) + r16[bx]);
        r16[ax] = memory16get(ds*16+0x950F);
        r16[ax] += r16[bx];
        if (r16[ax] <= 0x02e8) {
            pc = 0x130C4;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds*16+0x953C, 0xffff);
    case 0x130C4:
        memory16set(ds*16+0x950F, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9547);
        r16[ax] -= 0x0380;
        if (r16s[ax] >= 0) {
            pc = 0x13124;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] >= 0x0100) {
            pc = 0x130ED;
            break;
        }
        memory16set(ds*16+0x9525, r16[ax]);
        r8[al] = memory[ds*16+0x9524];
        if (r8[al] != 0x00) {
            pc = 0x130EB;
            break;
        }
        si = 0x1912;
        yield* sub_10B58();
        memory[ds*16+0x9524] = 0x01;
    case 0x130EB:
        pc = 0x13122;
        break;
    case 0x130ED:
        r16[ax] = memory16get(ds*16+0x9547);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r8[al] == memory[ds*16+0x9527]) {
            pc = 0x13122;
            break;
        }
        memory[ds*16+0x9527] = r8[al];
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] = r16[bx] + memory16get(ds*16+0x94E2);
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] == 0x00) {
            pc = 0x13122;
            break;
        }
        si = 0x1ab2;
        memory[ds*16+si + 1] = r8[al];
        r16[ax] = memory16get(ds*16+0x9547);
        memory16set(ds*16+si + 19, r16[ax]);
        yield* sub_10B58();
    case 0x13122:
        return;
    case 0x13124:
        memory[ds*16+0x94FF] = 0x00;
        r16[ax] = memory16get(ds*16+0x950C);
        memory16set(ds*16+0x9528, r16[ax]);
        return;
    } while (1);
}
function* sub_13130() {
    r8[bl] = r8[al];
    r8[bh] = 0x00;
    r8[cl] = memory[ds*16+r16[bx] + 6762];
    r8[ch] = 0x00;
    r8[al] = memory[ds*16+si + 1];
    if (r8[al] == 0x01)
        yield* sub_1315E();
    else if (r8[al] == 0x02)
        yield* sub_13167();
    else if (r8[al] == 0x03)
        yield* sub_13170();
    else if (r8[al] == 0x04)
        yield* sub_13178();
    else if (r8[al] == 0x05)
        yield* sub_13181();
    else if (r8[al] == 0x06)
        yield* sub_13188();
    else if (r8[al] == 0x07)
        yield* sub_13191();
    else if (r8[al] == 0x08)
        yield* sub_1319B();
}
function* sub_1315E() {
    r16[cx] = -r16[cx];
    r16[cx] += 0x006a;
    memory16set(ds*16+si + 7, r16[cx]);
}
function* sub_13167() {
    push(r16[cx]);
    yield* sub_1315E();
    r16[cx] = pop();
    yield* sub_13170();
}
function* sub_13170() {
    r16[cx] += 0x0080;
    memory16set(ds*16+si + 5, r16[cx]);
}
function* sub_13178() {
    push(r16[cx]);
    yield* sub_13170();
    r16[cx] = pop();
    yield* sub_13181();
}
function* sub_13181() {
    r16[cx] += 0x006a;
    memory16set(ds*16+si + 7, r16[cx]);
}
function* sub_13188() {
    push(r16[cx]);
    yield* sub_13181();
    r16[cx] = pop();
    yield* sub_13191();
}
function* sub_13191() {
    r16[cx] = -r16[cx];
    r16[cx] += 0x0080;
    memory16set(ds*16+si + 5, r16[cx]);
}
function* sub_1319B() {
    push(r16[cx]);
    yield* sub_13191();
    r16[cx] = pop();
    yield* sub_1315E();
}
function* sub_131A4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x94F8);
        es = r16[ax];
        di = 0x0144;
        r16[bx] = memory16get(ds*16+0x94F4);
        si = 0x0340;
        yield* sub_131E7();
        r16[ax] = (~r16[ax]);
        r16[ax] &= 0x000f;
        r8[ah] = r8[al];
        r8[al] = 0x01;
        r16[dx] = 0x03ce;
        out16(r16[dx], r16[ax]);
        yield* sub_13209();
        r8[ah] = r8[al];
        r8[al] = 0x00;
        out16(r16[dx], r16[ax]);
        push(ds);
        ds = r16[bx];
        flags.direction = false;
        r16[cx] = 0x00a0;
    case 0x131D2:
        push(r16[cx]);
        r16[cx] = 0x0020;
        rep_movsb_video_data_forward();
        di += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x131D2;
            break;
        }
        ds = pop();
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al] += 1;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_131E7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x951D];
        if (r8[al] != 0x40) {
            pc = 0x131F3;
            break;
        }
        r16[ax] = 0x0002;
        return;
    case 0x131F3:
        if (r8[al] != 0x80) {
            pc = 0x131FC;
            break;
        }
        r16[ax] = 0x0004;
        return;
    case 0x131FC:
        if (r8[al] != 0xc0) {
            pc = 0x13205;
            break;
        }
        r16[ax] = 0x0001;
        return;
    case 0x13205:
        r16[ax] = 0x0003;
        return;
    } while (1);
}
function* sub_13209() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x951C];
        if (r8[al] != 0x00) {
            pc = 0x13215;
            break;
        }
        r16[ax] = 0x0000;
        return;
    case 0x13215:
        if (r8[al] != 0x01) {
            pc = 0x13223;
            break;
        }
        r16[ax] = 0x0007;
        memory[ds*16+0x951C] = 0x00;
        return;
    case 0x13223:
        r16[ax] = 0x000f;
        memory[ds*16+0x951C] = 0x01;
        return;
    } while (1);
}
function* loc_13254() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x13254:
        out16(r16[dx], r16[ax]);
        push(r16[ax]);
        push(di);
        push(si);
        r16[cx] = _stack16(bp + 6);
    case 0x1325B:
        push(di);
        push(si);
        push(r16[cx]);
        r16[cx] = _stack16(bp + 8);
    case 0x13261:
        lodsb_data_forward();
        memory[es*16+di] &= r8[al];
        di += 1;
        if (--r16[cx]) {
            pc = 0x13261;
            break;
        }
        r16[cx] = pop();
        si = pop();
        di = pop();
        si += 0x0028;
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1325B;
            break;
        }
        si = pop();
        di = pop();
        r16[ax] = pop();
        si += 0x1f40;
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x13254;
            break;
        }
        ds = pop();
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f07;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(10);
        return;
    } while (1);
}
function* sub_13291() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = _stack16(bp + arg_0);
        es = r16[ax];
        di = 0x0144;
        r16[bx] = _stack16(bp + arg_2);
        si = 0x0144;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        push(ds);
        ds = r16[bx];
        flags.direction = false;
        r16[cx] = 0x00a0;
    case 0x132B0:
        push(r16[cx]);
        r16[cx] = 0x0020;
        rep_movsb_video_video_forward();
        si += 0x0008;
        di += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x132B0;
            break;
        }
        ds = pop();
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* loc_132E6() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x132E6:
        push(di);
        r16[cx] = _stack16(bp + 8);
        rep_stosb_data_forward();
        di = pop();
        di += 0x0028;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x132E6;
            break;
        }
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al] += 1;
        out16(r16[dx], r16[ax]);
        bp = pop();
        _stackReduce(8);
        return;
    } while (1);
}
function* sub_132FE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[ax] = memory16get(ds*16+0x94F8);
        es = r16[ax];
        di = 0x0144;
        r16[ax] = memory16get(ds*16+0x9528);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        si = r16[ax];
        push(ds);
        r16[ax] = 0xa800;
        ds = r16[ax];
        flags.direction = false;
        r16[cx] = 0x00a0;
    case 0x13326:
        push(r16[cx]);
        r16[cx] = 0x0020;
        rep_movsb_video_video_forward();
        si &= 0x7fff;
        di += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x13326;
            break;
        }
        ds = pop();
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_1333C() {
    r16[ax] = 0x000d;
    interrupt(16);
    r16[ax] = 0xa000;
    memory16set(ds*16+0x94FA, r16[ax]);
    r16[ax] += 0x0200;
    memory16set(ds*16+0x94F8, r16[ax]);
    r16[ax] = 0x0000;
    yield* sub_133B3();
    r16[ax] = memory16get(ds*16+0x94F8);
    r16[bx] = memory16get(ds*16+0x94FA);
    memory16set(ds*16+0x94F8, r16[bx]);
    memory16set(ds*16+0x94FA, r16[ax]);
    yield* sub_133D7();
    r16[bx] = memory16get(ds*16+0x94FA);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    flags.interrupt = false;
    r16[dx] = 0x03d4;
    r8[ah] = r8[bh];
    r8[al] = 0x0c;
    out16(r16[dx], r16[ax]);
    r8[ah] = r8[bl];
    r8[al] += 1;
    out16(r16[dx], r16[ax]);
    yield* _sync();
    flags.interrupt = true;
    yield* sub_133D7();
}
function* sub_13383() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x94F8);
        r16[bx] = memory16get(ds*16+0x94FA);
        memory16set(ds*16+0x94F8, r16[bx]);
        memory16set(ds*16+0x94FA, r16[ax]);
        r16[bx] = memory16get(ds*16+0x94FA);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        flags.interrupt = false;
        r16[dx] = 0x03d4;
        r8[ah] = r8[bh];
        r8[al] = 0x0c;
        out16(r16[dx], r16[ax]);
        yield* _sync();
        flags.interrupt = true;
        r16[dx] = 0x03da;
    case 0x133AA:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x133AA;
            break;
        }
        yield* sub_133D7();
        return;
    } while (1);
}
function* sub_133B3() {
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+0x94F8);
    es = r16[ax];
    di = 0x0000;
    r16[dx] = 0x03ce;
    r16[ax] = pop();
    r8[ah] = r8[al];
    r8[al] = 0x00;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0f01;
    out16(r16[dx], r16[ax]);
    flags.direction = false;
    r16[cx] = 0x0fa0;
    rep_stosw_video_forward();
    r16[ax] = 0x0000;
    out16(r16[dx], r16[ax]);
    r8[al] += 1;
    out16(r16[dx], r16[ax]);
}
function* sub_133D7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03da;
    case 0x133DA:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x133DA;
            break;
        }
    case 0x133DF:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x133DF;
            break;
        }
        return;
    } while (1);
}
function* sub_133E5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x94F8);
        es = r16[ax];
        di = 0x0000;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0805;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0007;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r16[ax] = 0x0802;
        push(ds);
        ds = r16[bx];
    case 0x13400:
        out16(r16[dx], r16[ax]);
        push(r16[ax]);
        push(di);
        r16[cx] = 0x1f40;
    case 0x13406:
        lodsb_data_forward();
        memoryVideoAnd(es, di, r8[al]);
        di += 1;
        if (--r16[cx]) {
            pc = 0x13406;
            break;
        }
        di = pop();
        r16[ax] = pop();
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x13400;
            break;
        }
        ds = pop();
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f07;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_13423() {
    r16[ax] = 0x0000;
    yield* sub_133B3();
    yield* sub_13439();
    yield* sub_13383();
    r16[ax] = 0x0000;
    yield* sub_133B3();
    yield* sub_13439();
}
function* sub_13439() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x94F8);
        es = r16[ax];
        di = 0x011c;
        r16[ax] = 0xffff;
        r16[cx] = 0x0010;
        rep_stosw_video_forward();
        di = 0x1a44;
        r16[cx] = 0x0010;
        rep_stosw_video_forward();
        di = 0x011b;
        r8[al] = 0x01;
        r16[cx] = 0x00a2;
    case 0x13459:
        memoryVideoSet(es, di, r8[al]);
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x13459;
            break;
        }
        di = 0x013c;
        r8[al] = 0x80;
        r16[cx] = 0x00a2;
    case 0x13469:
        memoryVideoSet(es, di, r8[al]);
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x13469;
            break;
        }
        return;
    } while (1);
}
function* sub_13472() {
    si = 0x0000;
    r16[bx] = memory16get(ds*16+0x94F2);
    yield* sub_133E5();
    yield* sub_13383();
    si = 0x0000;
    r16[bx] = memory16get(ds*16+0x94F2);
    yield* sub_133E5();
    r16[ax] = memory16get(ds*16+0x94F8);
    push(r16[ax]);
    r16[ax] = 0xa000;
    r16[ax] += 0x0400;
    push(r16[ax]);
    yield* sub_13291();
}
function* sub_13498() {
    r16[ax] = 0xa000;
    r16[ax] += 0x0400;
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+0x94F8);
    push(r16[ax]);
    yield* sub_13291();
}
function* sub_134A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x0000;
        r16[ax] = memory16get(ds*16+0x94F4);
        es = r16[ax];
        r16[ax] = 0x0000;
        r16[cx] = 0x1000;
        flags.direction = false;
        rep_stosw_data_forward();
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = memory16get(ds*16+0x9547);
        r16[ax] &= 0x003f;
        memory16set(ds*16+0x954E, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] += 0x0040;
        push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 8156];
        r8[ah] = 0x00;
        push(r16[ax]);
        yield* sub_135BC();
        r16[ax] = memory16get(ds*16+0x954E);
        if (r16[ax] <= 0x000c) {
            pc = 0x13527;
            break;
        }
        return;
    case 0x13527:
        r16[bx] = memory16get(ds*16+0x954E);
        r8[al] = memory[ds*16+r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        yield* sub_136D4();
        r16[bx] = memory16get(ds*16+0x954E);
        r8[al] = memory[ds*16+r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        yield* sub_136D4();
        r16[bx] = memory16get(ds*16+0x954E);
        r8[al] = memory[ds*16+r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        yield* sub_136D4();
        r16[bx] = memory16get(ds*16+0x954E);
        r8[al] = memory[ds*16+r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        yield* sub_136D4();
        return;
    } while (1);
}
function* sub_135BC() {
    let arg_0 = 4;
    let arg_2 = 6;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
    case 0x135BF:
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_2);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] = r16[ax] + _stack16(bp + arg_0);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_0);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] = r16[ax] - _stack16(bp + arg_2);
        push(r16[ax]);
        yield* sub_136D4();
        r16[ax] = _stack16(bp + arg_2);
        r16[ax] >>= 1;
        if (r8[al] <= memory[ds*16+0x9549]) {
            pc = 0x136D0;
            break;
        }
        _stack16set(bp + arg_2, r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        r16[ax] >>= 1;
        _stack16set(bp + arg_0, r16[ax]);
        pc = 0x135BF;
        break;
    case 0x136D0:
        bp = pop();
        _stackReduce(4);
        return;
    } while (1);
}
function* sub_136D4() {
    let var_A = -10;
    let var_6 = -6;
    let var_4 = -4;
    let var_2 = -2;
    let arg_0 = 4;
    let arg_2 = 6;
    let arg_4 = 8;
    let arg_6 = 10;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        sp -= 0x000a;
        r16[ax] = memory16get(ds*16+0x94F4);
        es = r16[ax];
        r16[ax] = _stack16(bp + arg_4);
        if (r16[ax] == 0x0000) {
            pc = 0x136FA;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div(r8[bl]);
        r8[ah] = 0x00;
    case 0x136FA:
        _stack16set(bp + arg_4, r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        if (r16[ax] == 0x0000) {
            pc = 0x13718;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div(r8[bl]);
        r8[ah] = 0x00;
    case 0x13718:
        _stack16set(bp + arg_0, r16[ax]);
        r16[ax] = _stack16(bp + arg_6);
        r16[bx] = _stack16(bp + arg_2);
        if (r16[bx] >= r16[ax]) {
            pc = 0x13737;
            break;
        }
        _stack16set(bp + arg_6, r16[bx]);
        _stack16set(bp + arg_2, r16[ax]);
        r16[ax] = _stack16(bp + arg_4);
        r16[bx] = _stack16(bp + arg_0);
        _stack16set(bp + arg_4, r16[bx]);
        _stack16set(bp + arg_0, r16[ax]);
    case 0x13737:
        r16[ax] = _stack16(bp + arg_2);
        r16[ax] = r16[ax] - _stack16(bp + arg_6);
        _stack16set(bp + var_2, r16[ax]);
        r16[ax] = _stack16(bp + arg_0);
        r16[ax] = r16[ax] - _stack16(bp + arg_4);
        if (r16s[ax] >= 0) {
            pc = 0x13751;
            break;
        }
        r16[ax] = -r16[ax];
        _stack16set(bp + var_A, 0xffe0);
        pc = 0x13756;
        break;
    case 0x13751:
        _stack16set(bp + var_A, 0x0020);
    case 0x13756:
        _stack16set(bp + var_4, r16[ax]);
        r16[cx] = _stack16(bp + var_2);
        if (r16[cx] == 0x0000) {
            pc = 0x137DB;
            break;
        }
        if (r16[ax] != 0x0000) {
            pc = 0x13769;
            break;
        }
        pc = 0x137ED;
        break;
    case 0x13769:
        if (r16[ax] >= _stack16(bp + var_2)) {
            pc = 0x137A4;
            break;
        }
        r16[ax] = _stack16(bp + var_2);
        r16[ax] >>= 1;
        _stack16set(bp + var_6, r16[ax]);
        yield* sub_13801();
        r16[cx] = _stack16(bp + var_2);
    case 0x1377C:
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x13783;
            break;
        }
        r8[al] = 0x80;
        di += 1;
    case 0x13783:
        r16[bx] = _stack16(bp + var_6);
        r16[bx] = r16[bx] + _stack16(bp + var_4);
        _stack16set(bp + var_6, r16[bx]);
        if (r16[bx] <= _stack16(bp + var_2)) {
            pc = 0x1379D;
            break;
        }
        r16[bx] = r16[bx] - _stack16(bp + var_2);
        _stack16set(bp + var_6, r16[bx]);
        r16[bx] = _stack16(bp + var_A);
        di = (di + _stack16(bp + var_A)) & 0xffff;
    case 0x1379D:
        memory[es*16+di] |= r8[al];
        if (--r16[cx]) {
            pc = 0x1377C;
            break;
        }
        pc = 0x137D5;
        break;
    case 0x137A4:
        r16[ax] = _stack16(bp + var_4);
        r16[ax] >>= 1;
        _stack16set(bp + var_6, r16[ax]);
        yield* sub_13801();
        r16[cx] = _stack16(bp + var_4);
    case 0x137B2:
        di = (di + _stack16(bp + var_A)) & 0xffff;
        r16[bx] = _stack16(bp + var_6);
        r16[bx] = r16[bx] + _stack16(bp + var_2);
        _stack16set(bp + var_6, r16[bx]);
        if (r16[bx] <= _stack16(bp + var_4)) {
            pc = 0x137D0;
            break;
        }
        r16[bx] = r16[bx] - _stack16(bp + var_4);
        _stack16set(bp + var_6, r16[bx]);
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x137D0;
            break;
        }
        r8[al] = 0x80;
        di += 1;
    case 0x137D0:
        memory[es*16+di] |= r8[al];
        if (--r16[cx]) {
            pc = 0x137B2;
            break;
        }
    case 0x137D5:
        sp = bp;
        bp = pop();
        _stackReduce(8);
        return;
    case 0x137DB:
        yield* sub_13801();
        r16[cx] = _stack16(bp + var_4);
        if (r16[cx] == 0) {
            pc = 0x137D5;
            break;
        }
    case 0x137E3:
        di = (di + _stack16(bp + var_A)) & 0xffff;
        memory[es*16+di] |= r8[al];
        if (--r16[cx]) {
            pc = 0x137E3;
            break;
        }
        pc = 0x137D5;
        break;
    case 0x137ED:
        yield* sub_13801();
        r16[cx] = _stack16(bp + var_2);
    case 0x137F3:
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x137FA;
            break;
        }
        r8[al] = 0x80;
        di += 1;
    case 0x137FA:
        memory[es*16+di] |= r8[al];
        if (--r16[cx]) {
            pc = 0x137F3;
            break;
        }
        pc = 0x137D5;
        break;
        return;
    } while (1);
}
function* sub_13801() {
    r16[ax] = _stack16(bp + 8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    di = r16[ax];
    r16[ax] = _stack16(bp + 10);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    di += r16[ax];
    r16[cx] = _stack16(bp + 10);
    r16[cx] &= 0x0007;
    r8[al] = 0x80;
    r8[al] >>= r8[cl];
    memory[es*16+di] |= r8[al];
}
function* sub_1382A() {
    r8[al] = 0x00;
    memory[ds*16+0x9550] = r8[al];
    memory[ds*16+0x9551] = r8[al];
    memory[ds*16+0x9552] = r8[al];
    memory[ds*16+0x9506] = 0x01;
    memory[ds*16+0x9505] = 0x00;
}
function* sub_13840() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = memory[ds*16+0x955E];
        if (r8[ah] == 0x00) {
            pc = 0x1384A;
            break;
        }
        return;
    case 0x1384A:
        r8[ah] = memory[ds*16+0x9506];
        if (r8[ah] != 0x00) {
            pc = 0x13854;
            break;
        }
        return;
    case 0x13854:
        r8[ah] = memory[ds*16+0x9550];
        if (r8[ah] != 0x00) {
            pc = 0x13866;
            break;
        }
        push(r16[bx]);
        memory[ds*16+0x9550] = r8[al];
        yield* sub_13914();
        r16[bx] = pop();
        return;
    case 0x13866:
        r8[ah] = memory[ds*16+0x9551];
        if (r8[ah] != 0x00) {
            pc = 0x13873;
            break;
        }
        memory[ds*16+0x9551] = r8[al];
        return;
    case 0x13873:
        if (r8[al] <= memory[ds*16+0x9552])
            return;
        memory[ds*16+0x9552] = r8[al];
        return;
    } while (1);
}
function* sub_1387D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x955E];
        if (r8[al] == 0x00) {
            pc = 0x1389B;
            break;
        }
        r8[al] = memory[ds*16+0x9506];
        if (r8[al] == 0x00) {
            pc = 0x13890;
            break;
        }
        yield* sub_139DB();
        pc = 0x1389B;
        break;
    case 0x13890:
        memory16set(ds*16+0x955F, 0x0000);
        memory[ds*16+0x955E] = 0x00;
    case 0x1389B:
        r8[al] = memory[ds*16+0x9550];
        if (r8[al] != 0x00) {
            pc = 0x138A3;
            break;
        }
        return;
    case 0x138A3:
        memory[ds*16+0x9557] -= 1;
        if (memory[ds*16+0x9557] != 0) {
            pc = 0x138D4;
            break;
        }
        r8[al] = memory[ds*16+0x9506];
        if (r8[al] != 0x00) {
            pc = 0x138B4;
            break;
        }
        yield* sub_139A3();
        return;
    case 0x138B4:
        r8[al] = memory[ds*16+0x9551];
        if (r8[al] == 0x00) {
            pc = 0x138D0;
            break;
        }
        memory[ds*16+0x9550] = r8[al];
        r8[bl] = memory[ds*16+0x9552];
        memory[ds*16+0x9551] = r8[bl];
        memory[ds*16+0x9552] = 0x00;
        yield* sub_13914();
        return;
    case 0x138D0:
        yield* sub_139A3();
        return;
    case 0x138D4:
        r16[ax] = memory16get(ds*16+0x9558);
        r16[ax] = r16[ax] + memory16get(ds*16+0x955A);
        memory16set(ds*16+0x9558, r16[ax]);
        r8[al] = memory[ds*16+0x9553];
        if (r8[al] == 0x00) {
            pc = 0x138FD;
            break;
        }
        r8[bl] = memory[ds*16+0x9554];
        memory[ds*16+0x9554] += 1;
        r16[bx] &= 0x000f;
        r16[bx] <<= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+0x9555);
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0x955C, r16[ax]);
        pc = 0x13903;
        break;
    case 0x138FD:
        memory16set(ds*16+0x955C, 0x0000);
    case 0x13903:
        r16[ax] = memory16get(ds*16+0x9558);
        memory16set(ds*16+0x955C, memory16get(ds*16+0x955C) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x955C);
        out8(66, r8[al]);
        r8[al] = r8[ah];
        out8(66, r8[al]);
        return;
    } while (1);
}
function* sub_13914() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] -= 1;
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16(ds, r16[bx] + -29724 + 0x10000
        );
        r8[al] = memory[ds*16+r16[bx] + 1];
        memory[ds*16+0x9557] = r8[al];
        if (r16[bx] != 0x8c2c) {
            pc = 0x13941;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9536);
        r8[ah] = r8[al];
        r8[al] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] = -r16[ax];
        r16[ax] += 0x1f40;
        memory16set(ds*16+0x8C2E, r16[ax]);
        pc = 0x13966;
        break;
    case 0x13941:
        if (r16[bx] != 0x8c32) {
            pc = 0x13966;
            break;
        }
        r8[al] = memory[ds*16+0x1BA0];
        r16[ax] &= 0x007f;
        if (r16[ax] <= 0x003f) {
            pc = 0x13957;
            break;
        }
        r16[ax] -= 0x0040;
        pc = 0x1395C;
        break;
    case 0x13957:
        r16[ax] = -r16[ax];
        r16[ax] += 0x003f;
    case 0x1395C:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x0190;
        memory16set(ds*16+0x8C34, r16[ax]);
    case 0x13966:
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+0x9558, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 4);
        memory16set(ds*16+0x955A, r16[ax]);
        r8[bl] = memory[ds*16+r16[bx]];
        memory[ds*16+0x9553] = r8[bl];
        if (r8s[bl] <= signed8(0x00)) {
            pc = 0x1398F;
            break;
        }
        r8[bl] -= 1;
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + -29604 + 0x10000);
        memory16set(ds*16+0x9555, r16[ax]);
        memory[ds*16+0x9554] = 0x00;
    case 0x1398F:
        r8[al] = 0xb6;
        out8(67, r8[al]);
        r16[ax] = memory16get(ds*16+0x9558);
        out8(66, r8[al]);
        r8[al] = r8[ah];
        out8(66, r8[al]);
        _in(r8[al], 97);
        r8[al] |= 0x03;
        out8(97, r8[al]);
        return;
    } while (1);
}
function* sub_139A3() {
    r8[al] = 0x00;
    memory[ds*16+0x9550] = r8[al];
    memory[ds*16+0x9551] = r8[al];
    memory[ds*16+0x9552] = r8[al];
    memory[ds*16+0x9557] = r8[al];
    _in(r8[al], 97);
    r8[al] &= 0xfc;
    out8(97, r8[al]);
}
function* sub_139B8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x9561] = 0x00;
        memory16set(ds*16+0x955F, 0x0000);
        memory[ds*16+0x955E] = 0x01;
        r8[al] = memory[ds*16+0x9546];
        if (r8[al] != 0x00) {
            pc = 0x139D4;
            break;
        }
        r16[ax] = 0x8dec;
        pc = 0x139D7;
        break;
    case 0x139D4:
        r16[ax] = 0x8d4c;
    case 0x139D7:
        memory16set(ds*16+0x9562, r16[ax]);
        return;
    } while (1);
}
function* sub_139DB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x9561] -= 1;
        if (memorys[ds*16+0x9561] < 0) {
            pc = 0x139E2;
            break;
        }
        return;
    case 0x139E2:
        memory[ds*16+0x9561] = 0x07;
        memory[ds*16+0x8C57] = 0x0e;
        memory[ds*16+0x8C56] = 0x04;
        r16[bx] = memory16get(ds*16+0x955F);
        si = memory16get(ds*16+0x9562);
        r8[al] = memory[ds*16+r16[bx] + si];
        if (r8[al] != 0xff) {
            pc = 0x13A05;
            break;
        }
        memory[ds*16+0x955E] = 0x00;
        return;
    case 0x13A05:
        if (r8[al] != 0x00) {
            pc = 0x13A29;
            break;
        }
        r8[al] = memory[ds*16+0x9550];
        if (r8[al] != 0x00) {
            pc = 0x13A25;
            break;
        }
        memory[ds*16+0x8C56] = 0x00;
        memory[ds*16+0x8C57] = 0x06;
        r16[bx] &= 0x001f;
        r8[al] = memory[ds*16+r16[bx] + -29091 + 0x10000];
        r8[al] -= 0x0c;
        pc = 0x13A27;
        break;
    case 0x13A25:
        r8[al] = 0x00;
    case 0x13A27:
        pc = 0x13A33;
        break;
    case 0x13A29:
        if (r8[al] != 0xfe) {
            pc = 0x13A31;
            break;
        }
        r8[al] = 0x00;
        pc = 0x13A33;
        break;
    case 0x13A31:
        r8[al] += 0x0c;
    case 0x13A33:
        yield* sub_13A3B();
        memory16set(ds*16+0x955F, memory16get(ds*16+0x955F) + 1);
        return;
    } while (1);
}
function* sub_13A3B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] -= 1;
        if (r8s[al] >= 0) {
            pc = 0x13A40;
            break;
        }
        return;
    case 0x13A40:
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + -29468 + 0x10000);
        memory16set(ds*16+0x8C58, r16[ax]);
        r8[al] = 0x0f;
        memory[ds*16+0x9550] = r8[al];
        yield* sub_13914();
        return;
    } while (1);
}