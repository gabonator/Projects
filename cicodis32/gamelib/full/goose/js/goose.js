function* start() {
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1d20;
    cs = 0x1000;
    ds = 0x0ff0;
    es = 0x0ff0;
    ss = 0x1cfc;
    sp = 0x0100;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/goose/dos", "GOOSE.EXE", 53684);
    yield* sub_10010();
}
function* sub_10010() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x13a5;
        ds = r16[ax];
        r16[bx] = 0x9670;
        r16[bx] += 0x000f;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] += r16[bx];
        memory16set(ds, 0x94e8, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94ea, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94ec, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94ee, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94f0, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94f2, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94f4, r16[ax]);
        r16[ax] += 0x0800;
        memory16set(ds, 0x94f6, r16[ax]);
        interrupt(0x12);
        if (r16[ax] >= 0x0200) {
            pc = 0x10067;
            break;
        }
        r16[dx] = 0x0007;
        r8[ah] = 0x09;
        interrupt(0x21);
        r16[ax] = 0x4c00;
        interrupt(0x21);
        pc = 0x1006e;
        break;
    case 0x10067:
        r16[dx] = 0x002a;
        r8[ah] = 0x09;
        interrupt(0x21);
    case 0x1006e:
        yield* sub_10600();
        yield* sub_1333c();
        yield* sub_12762();
        yield* sub_105ec();
        yield* sub_10442();
        yield* sub_10588();
        yield* sub_10591();
        yield* sub_1382a();
        memory[ds*16 + 0x9501] = 0x00;
    case 0x1008b:
        yield* sub_100a9();
        yield* sub_100cf();
        yield* sub_100fd();
        pc = 0x1008b;
        break;
        return;
    } while (1);
}
function* sub_100a9() {
    yield* sub_10103();
    memory[ds*16 + 0x9500] = 0x00;
    memory[ds*16 + 0x94fe] = 0x01;
    memory[ds*16 + 0x94fc] = 0x10;
    memory[ds*16 + 0x94ff] = 0x00;
    memory[ds*16 + 0x9502] = 0x00;
    yield* sub_10da7();
    yield* sub_13423();
    yield* sub_121dc();
}
function* sub_100cf() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x100cf:
        yield* sub_101c0();
        yield* sub_10fda();
        r8[al] = memory[ds*16 + 0x94ff];
        if (r8[al] != 0x00) {
            pc = 0x100e4;
            break;
        }
        yield* sub_132fe();
        yield* sub_10b8e();
        pc = 0x100ed;
        break;
    case 0x100e4:
        yield* sub_134a8();
        yield* sub_131a4();
        yield* sub_10b8e();
    case 0x100ed:
        yield* sub_1220d();
        yield* sub_13383();
        r8[al] = memory[ds*16 + 0x9500];
        if (r8[al] != 0x00)
            return;
        pc = 0x100cf;
        break;
        return;
    } while (1);
}
function* sub_100fd() {
    memory[ds*16 + 0x0006] = 0x01;
}
function* sub_10103() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0006];
        if (r8[al] == 0x00) {
            pc = 0x10115;
            break;
        }
        memory16set(ds, 0x8e7e, 0x00da);
        yield* sub_1279f();
        pc = 0x1011e;
        break;
    case 0x10115:
        memory16set(ds, 0x8e7e, 0x00e9);
        yield* sub_128da();
    case 0x1011e:
        yield* sub_139b8();
        yield* sub_13472();
        memory[ds*16 + 0x9503] = 0x01;
        memory16set(ds, 0x8e80, 0x0000);
        yield* sub_10d98();
    case 0x10132:
        yield* sub_101c0();
        yield* sub_10fda();
        yield* sub_13498();
        yield* sub_10b8e();
        yield* sub_13383();
        r16[ax] = memory16get(ds, 0x954c);
        if (r16[ax] & 0x0080) {
            pc = 0x10197;
            break;
        }
        memory16set(ds, 0x8e80, memory16get(ds, 0x8e80) + 1);
        r16[bx] = memory16get(ds, 0x8e80);
        if (r16[bx] & 0x0007) {
            pc = 0x10195;
            break;
        }
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] += memory16get(ds, 0x8e7e);
        r8[al] = memory[ds*16 + r16[bx]];
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
        r8[al] = memory[ds*16 + 0x9546];
        if (r8[al] == 0x00) {
            pc = 0x1017b;
            break;
        }
        yield* sub_129db();
        pc = 0x1017e;
        break;
    case 0x1017b:
        yield* sub_101ad();
    case 0x1017e:
        pc = 0x10195;
        break;
    case 0x10180:
        if (r8[al] & 0x80) {
            pc = 0x10189;
            break;
        }
        yield* sub_1019d();
        pc = 0x10195;
        break;
    case 0x10189:
        r8[al] &= 0x3f;
        push(r16[ax]);
        yield* sub_1019d();
        r16[ax] = pop();
        r8[al]++;
        yield* sub_1019d();
    case 0x10195:
        pc = 0x10132;
        break;
    case 0x10197:
        memory[ds*16 + 0x9503] = 0x00;
        return;
    } while (1);
}
function* sub_1019d() {
    si = 0x0109;
    memory[ds*16 + si + 4] = r8[al];
    r16[bx] = 0x0120;
    yield* sub_12121();
    yield* sub_10b58();
}
function* sub_101ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x1f40;
    case 0x101b0:
        push(r16[cx]);
        yield* sub_101c0();
        r16[cx] = pop();
        r16[ax] = memory16get(ds, 0x954c);
        if (!(r8[al] & 0x80)) {
            pc = 0x101bd;
            break;
        }
        return;
    case 0x101bd:
        if (--r16[cx]) {
            pc = 0x101b0;
            break;
        }
        return;
    } while (1);
}
function* sub_101c0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x101c0;
        break;
    case 0x10096:
        yield* sub_139a3();
        yield* sub_105bc();
        yield* sub_104a5();
        r16[ax] = 0x0003;
        interrupt(0x10);
        r16[ax] = 0x4c00;
        interrupt(0x21);
        yield* sub_10103();
        memory[ds*16 + 0x9500] = 0x00;
        memory[ds*16 + 0x94fe] = 0x01;
        memory[ds*16 + 0x94fc] = 0x10;
        memory[ds*16 + 0x94ff] = 0x00;
        memory[ds*16 + 0x9502] = 0x00;
        yield* sub_10da7();
        yield* sub_13423();
        yield* sub_121dc();
        return;
    case 0x101c0:
        r16[bx] = 0x8e8a;
        si = 0x003d;
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101d5;
            break;
        }
        si = 0x003e;
    case 0x101cf:
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101cf;
            break;
        }
    case 0x101d5:
        si = 0x003b;
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101e1;
            break;
        }
        yield* sub_1033b();
    case 0x101e1:
        r16[bx] = 0x8e8a;
        si = memory16get(ds, 0x8f0d);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x101f6;
            break;
        }
        memory16set(ds, 0x954c, 0x0001);
        pc = 0x1020e;
        break;
    case 0x101f6:
        si = memory16get(ds, 0x8f0f);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x10208;
            break;
        }
        memory16set(ds, 0x954c, 0x0002);
        pc = 0x1020e;
        break;
    case 0x10208:
        memory16set(ds, 0x954c, 0x0000);
    case 0x1020e:
        si = memory16get(ds, 0x8f11);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1021f;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0004);
        pc = 0x1022e;
        break;
    case 0x1021f:
        si = memory16get(ds, 0x8f13);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1022e;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0008);
    case 0x1022e:
        si = memory16get(ds, 0x8f15);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1023e;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0080);
    case 0x1023e:
        si = memory16get(ds, 0x8f17);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1024d;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0040);
    case 0x1024d:
        si = memory16get(ds, 0x8f19);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1025c;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0020);
    case 0x1025c:
        si = memory16get(ds, 0x8f1b);
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x1028c;
            break;
        }
        yield* sub_12c45();
        r16[bx] = 0x8e8a;
    case 0x1026c:
        r8[al] = memory[ds*16 + r16[bx] + 21];
        if (r8[al] != 0x00) {
            pc = 0x1027c;
            break;
        }
        r8[al] = memory[ds*16 + r16[bx] + 49];
        if (r8[al] != 0x00) {
            pc = 0x1027c;
            break;
        }
        pc = 0x1026c;
        break;
    case 0x1027c:
        r16[bx] = 0x8e8a;
        r8[al] = memory[ds*16 + r16[bx] + 21];
        if (r8[al] == 0x00) {
            pc = 0x10289;
            break;
        }
        pc = 0x10096;
        break;
    case 0x10289:
        yield* sub_10529();
    case 0x1028c:
        r16[bx] = 0x8e8a;
        si = 0x003c;
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x102c5;
            break;
        }
        r8[al] = memory[ds*16 + 0x9505];
        if (r8[al] != 0x00) {
            pc = 0x102b0;
            break;
        }
        r8[al] = 0x0e;
        yield* sub_13840();
        memory[ds*16 + 0x9505] = 0x01;
        memory[ds*16 + 0x9506] = 0x00;
        pc = 0x102c3;
        break;
    case 0x102b0:
        if (r8[al] != 0x02) {
            pc = 0x102c3;
            break;
        }
        memory[ds*16 + 0x9505] = 0x03;
        memory[ds*16 + 0x9506] = 0x01;
        r8[al] = 0x0d;
        yield* sub_13840();
    case 0x102c3:
        pc = 0x102dc;
        break;
    case 0x102c5:
        r8[al] = memory[ds*16 + 0x9505];
        if (r8[al] != 0x01) {
            pc = 0x102d3;
            break;
        }
        memory[ds*16 + 0x9505] = 0x02;
        pc = 0x102dc;
        break;
    case 0x102d3:
        if (r8[al] != 0x03) {
            pc = 0x102dc;
            break;
        }
        memory[ds*16 + 0x9505] = 0x00;
    case 0x102dc:
        r8[al] = memory[ds*16 + 0x8f0a];
        if (r8[al] != 0x00) {
            pc = 0x102e4;
            break;
        }
        return;
    case 0x102e4:
        r16[ax] = 0x0003;
        interrupt(0x33);
        if (!(r16[bx] & 0x0001)) {
            pc = 0x102f5;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0080);
    case 0x102f5:
        if (!(r16[bx] & 0x0002)) {
            pc = 0x10300;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0020);
    case 0x10300:
        r16[ax] = memory16get(ds, 0x954c);
        r16[ax] &= 0x000f;
        if (r16[ax] == 0) {
            pc = 0x10309;
            break;
        }
        return;
    case 0x10309:
        r16[ax] = 0x000b;
        interrupt(0x33);
        if (r16s[cx] >= signed16(0xfffb)) {
            pc = 0x1031a;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0001);
        pc = 0x10324;
        break;
    case 0x1031a:
        if (r16s[cx] <= signed16(0x0005)) {
            pc = 0x10324;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0002);
    case 0x10324:
        if (r16s[dx] >= signed16(0xfff6)) {
            pc = 0x10330;
            break;
        }
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0004);
        return;
    case 0x10330:
        if (r16s[dx] <= signed16(0x000a))
            return;
        memory16set(ds, 0x954c, memory16get(ds, 0x954c) | 0x0008);
        return;
    } while (1);
}
function* sub_1033b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_12c07();
        r8[al] = 0x04;
        yield* sub_12c9a();
        yield* sub_104f3();
        memory16set(ds, 0x8f15, r16[ax]);
        r8[al] = 0x00;
        yield* sub_12c9a();
    case 0x1034e:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x1034e;
            break;
        }
        memory16set(ds, 0x8f0d, r16[ax]);
        r8[al] = 0x01;
        yield* sub_12c9a();
    case 0x1035f:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x1035f;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x1035f;
            break;
        }
        memory16set(ds, 0x8f0f, r16[ax]);
        r8[al] = 0x02;
        yield* sub_12c9a();
    case 0x10376:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x10376;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x10376;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0f)) {
            pc = 0x10376;
            break;
        }
        memory16set(ds, 0x8f11, r16[ax]);
        r8[al] = 0x03;
        yield* sub_12c9a();
    case 0x10393:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0f)) {
            pc = 0x10393;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f11)) {
            pc = 0x10393;
            break;
        }
        memory16set(ds, 0x8f13, r16[ax]);
        r8[al] = 0x06;
        yield* sub_12c9a();
    case 0x103b6:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x103b6;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x103b6;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0f)) {
            pc = 0x103b6;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f11)) {
            pc = 0x103b6;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f13)) {
            pc = 0x103b6;
            break;
        }
        memory16set(ds, 0x8f17, r16[ax]);
        r8[al] = 0x07;
        yield* sub_12c9a();
    case 0x103df:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x103df;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x103df;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0f)) {
            pc = 0x103df;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f11)) {
            pc = 0x103df;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f13)) {
            pc = 0x103df;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f17)) {
            pc = 0x103df;
            break;
        }
        memory16set(ds, 0x8f19, r16[ax]);
        r8[al] = 0x05;
        yield* sub_12c9a();
    case 0x1040e:
        yield* sub_104f3();
        if (r16[ax] == memory16get(ds, 0x8f15)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0d)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f0f)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f11)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f13)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f17)) {
            pc = 0x1040e;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x8f19)) {
            pc = 0x1040e;
            break;
        }
        memory16set(ds, 0x8f1b, r16[ax]);
        yield* sub_10529();
        return;
    } while (1);
}
function* sub_10442() {
    memory16set(ds, 0x8f0b, 0x0000);
    memory16set(ds, 0x8f0d, 0x004b);
    memory16set(ds, 0x8f0f, 0x004d);
    memory16set(ds, 0x8f11, 0x0048);
    memory16set(ds, 0x8f13, 0x0050);
    memory16set(ds, 0x8f15, 0x0039);
    memory16set(ds, 0x8f17, 0x0031);
    memory16set(ds, 0x8f19, 0x0032);
    memory16set(ds, 0x8f1b, 0x0010);
    r16[ax] = ds;
    es = r16[ax];
    r16[ax] = 0x0000;
    r16[cx] = 0x0040;
    di = 0x8e8a;
    rep_stosw_data_forward();
    r8[al] = 0x09;
    r8[ah] = 0x35;
    interrupt(0x21);
    memory16set(ds, 0x8e84, r16[bx]);
    memory16set(ds, 0x8e82, es);
    push(ds);
    r16[dx] = 0x04b7;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x09;
    r8[ah] = 0x25;
    interrupt(0x21);
    ds = pop();
}
function* sub_104a5() {
    r16[dx] = memory16get(ds, 0x8e84);
    r16[ax] = memory16get(ds, 0x8e82);
    push(ds);
    ds = r16[ax];
    r8[al] = 0x09;
    r8[ah] = 0x25;
    interrupt(0x21);
    ds = pop();
}
function* sub_104f3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
    case 0x104f4:
        si = 0x8e8a;
    case 0x104f7:
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
            pc = 0x104f7;
            break;
        }
        pc = 0x104f4;
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
    case 0x1052e:
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x10535;
            break;
        }
        r8[ah]++;
    case 0x10535:
        if (si != 0x8f0a) {
            pc = 0x1052e;
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
    case 0x1054a:
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x10557;
            break;
        }
        r8[ah] = 0x01;
        flags.zero = si == memory16get(ds, 0x8f0b);
        if (si != memory16get(ds, 0x8f0b)) {
            pc = 0x1055f;
            break;
        }
    case 0x10557:
        flags.zero = si == 0x8f0a;
        if (si == 0x8f0a) {
            pc = 0x1055f;
            break;
        }
        pc = 0x1054a;
        break;
    case 0x1055f:
        if (flags.zero) {
            pc = 0x10578;
            break;
        }
        memory16set(ds, 0x8f0b, si);
        si -= 0x8e8b;
        r8[al] = memory[ds*16 + si + 90];
        if (r8[al] == 0x00) {
            pc = 0x10576;
            break;
        }
        if (r8s[al] >= 0) {
            pc = 0x10575;
            break;
        }
        r8[al] = 0x00;
    case 0x10575:
        return;
    case 0x10576:
        pc = 0x10583;
        break;
    case 0x10578:
        if (r8[ah] != 0x00) {
            pc = 0x10583;
            break;
        }
        memory16set(ds, 0x8f0b, 0x0000);
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
    interrupt(0x33);
    memory[ds*16 + 0x8f0a] = r8[al];
}
function* sub_10591() {
    r8[al] = 0x1c;
    r8[ah] = 0x35;
    interrupt(0x21);
    memory16set(ds, 0x8e88, r16[bx]);
    memory16set(ds, 0x8e86, es);
    push(ds);
    r16[dx] = 0x05ce;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x1c;
    r8[ah] = 0x25;
    interrupt(0x21);
    ds = pop();
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    r16[ax] = 0x4d0e;
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
}
function* sub_105bc() {
    r16[dx] = memory16get(ds, 0x8e88);
    r16[ax] = memory16get(ds, 0x8e86);
    push(ds);
    ds = r16[ax];
    r8[al] = 0x1c;
    r8[ah] = 0x25;
    interrupt(0x21);
    ds = pop();
}
function* sub_105ec() {
    push(ds);
    r16[dx] = 0x05fc;
    r16[ax] = cs;
    ds = r16[ax];
    r8[al] = 0x24;
    r8[ah] = 0x25;
    interrupt(0x21);
    ds = pop();
}
function* sub_10600() {
    r16[dx] = 0x01e2;
    r16[ax] = memory16get(ds, 0x94e8);
    yield* sub_10637();
    r16[dx] = 0x01ea;
    r16[ax] = memory16get(ds, 0x94ea);
    yield* sub_10637();
    r16[dx] = 0x01f2;
    r16[ax] = memory16get(ds, 0x94ec);
    yield* sub_10637();
    r16[dx] = 0x01f9;
    r16[ax] = memory16get(ds, 0x94ee);
    yield* sub_10637();
    r16[dx] = 0x0203;
    r16[ax] = memory16get(ds, 0x94f0);
    yield* sub_10637();
    r16[dx] = 0x020b;
    r16[ax] = memory16get(ds, 0x94f2);
    yield* sub_10637();
}
function* sub_10637() {
    memory16set(ds, 0x8f20, r16[ax]);
    di = 0x0000;
    r16[cx] = 0x7d00;
    yield* sub_1064d();
}
function* sub_10644() {
    r16[ax] = ds;
    memory16set(ds, 0x8f20, r16[ax]);
    yield* sub_1064d();
}
function* sub_1064d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(r16[cx]);
        r16[ax] = 0x3d00;
        interrupt(0x21);
        r16[cx] = pop();
        r16[dx] = pop();
        if (!flags.carry) {
            pc = 0x10659;
            break;
        }
        return;
    case 0x10659:
        memory16set(ds, 0x8f1e, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, 0x8f20);
        push(ds);
        ds = r16[ax];
        r16[ax] = 0x3f00;
        interrupt(0x21);
        ds = pop();
        r16[ax] = 0x3e00;
        r16[bx] = memory16get(ds, 0x8f1e);
        interrupt(0x21);
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
        interrupt(0x21);
        r16[cx] = pop();
        r16[dx] = pop();
        if (!flags.carry) {
            pc = 0x10683;
            break;
        }
        return;
    case 0x10683:
        memory16set(ds, 0x8f1e, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] = 0x4000;
        interrupt(0x21);
        if (!flags.carry) {
            pc = 0x10690;
            break;
        }
        return;
    case 0x10690:
        r16[ax] = 0x3e00;
        r16[bx] = memory16get(ds, 0x8f1e);
        interrupt(0x21);
        return;
    } while (1);
}
function* sub_1069a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x9501];
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bl] += memory[ds*16 + 0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = memory16get(ds, r16[bx] + 580);
        di = 0x9229;
        r16[cx] = 0x0040;
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = 0x0000;
        flags.direction = false;
        rep_stosw_data_forward();
        di = 0x9229;
    case 0x106c2:
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x106eb;
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
        r16[ax] |= memory16get(ds, r16[bx] + 3287);
        r16[cx] = r16[ax];
        lodsb_data_forward();
        r8[al] = -r8[al];
        r8[al] += 0x3f;
        r8[al] <<= 1;
        r8[bl] = r8[al];
        memory16set(ds, r16[bx] + 37417, memory16get(ds, r16[bx] + 37417) | r16[cx]);
        pc = 0x106c2;
        break;
    case 0x106eb:
        r8[al] = memory[ds*16 + 0x9501];
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bl] += memory[ds*16 + 0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = memory16get(ds, r16[bx] + 532);
        di = 0x8f29;
        r16[cx] = 0x0300;
        r8[bl] = 0x00;
    case 0x10708:
        r8[bl]--;
        if (r8s[bl] >= 0) {
            pc = 0x1072c;
            break;
        }
        lodsb_data_forward();
        r8[dl] = r8[al];
        r8[dl] &= 0x3f;
        r8[al] &= 0xc0;
        if (r8[al] != 0) {
            pc = 0x1071a;
            break;
        }
        r8[bl] = 0x00;
        pc = 0x1072c;
        break;
    case 0x1071a:
        if (r8[al] != 0x40) {
            pc = 0x10722;
            break;
        }
        r8[bl] = 0x01;
        pc = 0x1072c;
        break;
    case 0x10722:
        if (r8[al] != 0x80) {
            pc = 0x1072a;
            break;
        }
        r8[bl] = 0x02;
        pc = 0x1072c;
        break;
    case 0x1072a:
        r8[bl] = 0x03;
    case 0x1072c:
        memory[ds*16 + di] = r8[dl];
        di++;
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
        memory16set(ds, 0x8f25, r16[ax]);
        memory16set(ds, 0x8f23, 0x03f0);
        r16[cx] = 0x0040;
    case 0x10759:
        push(r16[cx]);
        memory[ds*16 + 0x8f22] = 0x00;
        yield* sub_107af();
        memory16set(ds, 0x0279, 0x0000);
        memory[ds*16 + 0x027d] = 0x08;
        memory16set(ds, 0x0283, memory16get(ds, 0x0283) + 0x0008);
        si = 0x0274;
        yield* sub_10bc5();
        memory16set(ds, 0x0279, 0x0008);
        memory[ds*16 + 0x027d] = 0x18;
        r16[cx] = 0x000a;
    case 0x10786:
        push(r16[cx]);
        yield* sub_107af();
        si = 0x0274;
        yield* sub_10bc5();
        memory16set(ds, 0x0279, memory16get(ds, 0x0279) + 0x0018);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10786;
            break;
        }
        memory[ds*16 + 0x027d] = 0x08;
        yield* sub_107af();
        si = 0x0274;
        yield* sub_10bc5();
        memory16set(ds, 0x8f23, memory16get(ds, 0x8f23) - 0x0010);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10759;
            break;
        }
        return;
    } while (1);
}
function* sub_107af() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x8f22];
        memory[ds*16 + 0x0277] = r8[al];
        r16[bx] = memory16get(ds, 0x8f25);
        r8[al] = memory[ds*16 + r16[bx]];
        r16[bx]++;
        memory16set(ds, 0x8f25, r16[bx]);
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 1309];
        memory[ds*16 + 0x027e] = r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 1393];
        memory[ds*16 + 0x8f22] += r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 1351];
        cbw();
        r16[ax] += memory16get(ds, 0x8f23);
        memory16set(ds, 0x027b, r16[ax]);
        if (r16[bx] < 0x0026) {
            pc = 0x107ec;
            break;
        }
        memory16set(ds, 0x0281, 0x0002);
        pc = 0x107f2;
        break;
    case 0x107ec:
        memory16set(ds, 0x0281, 0x0004);
    case 0x107f2:
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 1519);
        memory16set(ds, 0x0283, r16[bx]);
        return;
    } while (1);
}
function* sub_107fd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        sp -= 0x0008;
        r16[ax] = memory16get(ss, bp + 6 - 2);
        r16[ax] += 0x0010;
        r8[cl] = 0x18;
        div8(r8[cl]);
        push(r16[ax]);
        r8[ah] = 0x00;
        memory16set(ss, bp - 2 - 2, r16[ax]);
        r16[ax] = pop();
        r8[al] = r8[ah];
        r8[ah] = 0x00;
        r8[cl] = 0x03;
        div8(r8[cl]);
        r8[ah] = 0x00;
        memory16set(ss, bp - 4 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
        r16[ax] &= 0x03ff;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] = -r16[ax];
        r16[ax] += 0x003f;
        memory16set(ss, bp - 6 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
        r16[ax] &= 0x000f;
        r16[ax] >>= 1;
        memory16set(ss, bp - 8 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp - 6 - 2);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] += 0x8f29;
        si = r16[bx];
        r16[bx] += memory16get(ss, bp - 2 - 2);
        r8[al] = memory[ds*16 + r16[bx]];
        r8[ah] = 0x00;
        push(r16[ax]);
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[bx] = memory16get(ds, r16[bx] + 1603);
        r16[ax] = memory16get(ss, bp - 8 - 2);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] += memory16get(ss, bp - 4 - 2);
        r8[cl] = memory[ds*16 + r16[bx]];
        push(r16[cx]);
        r8[cl] &= 0x1f;
        if (!(r8[cl] & 0x10)) {
            pc = 0x10881;
            break;
        }
        r8[cl] |= 0xe0;
    case 0x10881:
        r16[dx] = memory16get(ss, bp - 2 - 2);
        flags.direction = false;
    case 0x10885:
        if (r16[dx] == 0x0000) {
            pc = 0x10896;
            break;
        }
        lodsb_data_forward();
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r8[cl] += memory[ds*16 + r16[bx] + 1393];
        r16[dx]--;
        pc = 0x10885;
        break;
    case 0x10896:
        r8[al] = r8[cl];
        cbw();
        r16[cx] = pop();
        r16[bx] = pop();
        if (r8[cl] & 0x80) {
            pc = 0x108a6;
            break;
        }
        r8[bl] = memory[ds*16 + r16[bx] + 1435];
        pc = 0x108aa;
        break;
    case 0x108a6:
        r8[bl] = memory[ds*16 + r16[bx] + 1477];
    case 0x108aa:
        r8[bh] = 0x00;
        r16[cx] = memory16get(ss, bp - 6 - 2);
        r16[cx] = -r16[cx];
        r16[cx] += 0x003f;
        sp = bp;
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_108ba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 4 - 2);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 37417);
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
        si = memory16get(ds, r16[bx] + 651);
        if (r8[ah] < 0x0f) {
            pc = 0x10902;
            break;
        }
        if (r8[ah] > 0x14) {
            pc = 0x10902;
            break;
        }
        r8[ah] -= 0x0f;
        memory[ds*16 + si + 1] = r8[ah];
        r8[bl] = r8[ah];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 38190];
        if (r8[al] == 0x00) {
            pc = 0x108f9;
            break;
        }
        r16[ax] = pop();
        pc = 0x10946;
        break;
    case 0x108f9:
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 814);
        memory16set(ds, si + 15, r16[ax]);
    case 0x10902:
        memory[ds*16 + si + 19] = 0x0a;
        r16[ax] = memory16get(ss, bp + 4 - 2);
        memory[ds*16 + si + 20] = r8[al];
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
        yield* sub_1094a();
        r8[al] = memory[ds*16 + si + 19];
        r8[ah] = 0x00;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        yield* sub_109e9();
        if (r16[ax] == 0x0000) {
            pc = 0x10932;
            break;
        }
        push(si);
        yield* sub_10b58();
        si = pop();
        pc = 0x1093f;
        break;
    case 0x10932:
        push(si);
        yield* sub_10b58();
        if (si == 0x0000) {
            pc = 0x1093e;
            break;
        }
        yield* sub_10a1b();
    case 0x1093e:
        si = pop();
    case 0x1093f:
        r16[cx] = pop();
        r16[ax] = pop();
    case 0x10941:
        memory[ds*16 + si + 19] -= 1;
        if (--r16[cx]) {
            pc = 0x10910;
            break;
        }
    case 0x10946:
        bp = pop();
        sp += 2;
        return;
    } while (1);
}
function* sub_1094a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = memory[ds*16 + si + 19];
        push(si);
        r8[al] = 0x3f;
        r8[al] -= memory[ds*16 + si + 20];
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
        r8[cl] += memory[ds*16 + r16[bx] + 1393];
        r8[dl]--;
        pc = 0x10966;
        break;
    case 0x10978:
        si = pop();
        memory[ds*16 + si + 3] = r8[cl];
        r8[al] = memory[ds*16 + si + 20];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + si + 19];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[cx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[cx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] -= 0x0004;
        memory16set(ds, si + 5, r16[ax]);
        return;
    } while (1);
}
function* sub_109a4() {
    di = 0x92a9;
    r16[cx] = 0x00c0;
    r16[ax] = ds;
    es = r16[ax];
    r16[ax] = 0xffff;
    flags.direction = false;
    rep_stosw_data_forward();
}
function* sub_109b5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        si = memory16get(ss, bp + 8 - 2);
        yield* sub_10a1b();
        r16[bx] = memory16get(ss, bp + 6 - 2);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds, r16[bx] + 3307);
        r16[bx] = memory16get(ss, bp + 4 - 2);
        r16[bx] <<= 1;
        r8[al] = memory[ds*16 + 0x9502];
        if (r8[al] != 0x01) {
            pc = 0x109d9;
            break;
        }
        r16[bx] += 0x0080;
        pc = 0x109e1;
        break;
    case 0x109d9:
        if (r8[al] != 0x02) {
            pc = 0x109e1;
            break;
        }
        r16[bx] += 0x0100;
    case 0x109e1:
        memory16set(ds, r16[bx] + 37545, memory16get(ds, r16[bx] + 37545) & r16[cx]);
        bp = pop();
        sp += 6;
        return;
    } while (1);
}
function* sub_109e9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 6 - 2);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds, r16[bx] + 3307);
        r16[bx] = memory16get(ss, bp + 4 - 2);
        r16[bx] <<= 1;
        r8[al] = memory[ds*16 + 0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10a07;
            break;
        }
        r16[bx] += 0x0080;
        pc = 0x10a0f;
        break;
    case 0x10a07:
        if (r8[al] != 0x02) {
            pc = 0x10a0f;
            break;
        }
        r16[bx] += 0x0100;
    case 0x10a0f:
        r16[cx] = ~r16[cx];
        r16[ax] = memory16get(ds, r16[bx] + 37545);
        r16[ax] &= r16[cx];
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_10a1b() {
    r8[al] = memory[ds*16 + si + 18];
    r8[al] <<= 1;
    r8[bl] = r8[al];
    r8[bh] = 0x00;
    di = memory16get(ds, r16[bx] + 798);
    r8[al] = memory[ds*16 + di];
    memory[ds*16 + si] = r8[al];
    r8[al] = memory[ds*16 + di + 9];
    memory[ds*16 + si + 9] = r8[al];
    r8[al] = memory[ds*16 + di + 10];
    memory[ds*16 + si + 10] = r8[al];
    r8[al] = memory[ds*16 + di + 11];
    memory[ds*16 + si + 11] = r8[al];
    r8[al] = memory[ds*16 + di + 12];
    memory[ds*16 + si + 12] = r8[al];
    r16[ax] = memory16get(ds, di + 15);
    memory16set(ds, si + 15, r16[ax]);
    r8[al] = memory[ds*16 + di + 18];
    memory[ds*16 + si + 18] = r8[al];
}
function* sub_10a51() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16 + 0x1b9e];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        si = r16[bx];
        r8[al] = memory[ds*16 + 0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10a68;
            break;
        }
        si += 0x0080;
        pc = 0x10a70;
        break;
    case 0x10a68:
        if (r8[al] != 0x02) {
            pc = 0x10a70;
            break;
        }
        si += 0x0100;
    case 0x10a70:
        r16[ax] = memory16get(ds, si + 37545);
        r16[ax] &= memory16get(ds, r16[bx] + 37417);
        if (r16[ax] == 0x0000) {
            pc = 0x10ad1;
            break;
        }
        r8[bl] = r8[ah];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 693];
        if (r8[cl] == 0x00) {
            pc = 0x10ad1;
            break;
        }
        memory[ds*16 + 0x9429] = r8[cl];
        memory16set(ds, 0x942c, 0x000a);
        r16[bx] <<= 1;
        r16[dx] = memory16get(ds, r16[bx] + 714);
        r16[bx] = memory16get(ds, r16[bx] + 756);
        r16[cx] = 0x000a;
    case 0x10aa5:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (!flags.carry) {
            pc = 0x10ac8;
            break;
        }
        push(r16[bx]);
        r16[bx] -= r16[dx];
        if (r16s[bx] > memory16gets(ds, 0x1b8f)) {
            pc = 0x10ac7;
            break;
        }
        r16[bx] += r16[dx];
        r16[bx] += r16[dx];
        if (r16s[bx] < memory16gets(ds, 0x1b8f)) {
            pc = 0x10ac7;
            break;
        }
        r16[ax] = pop();
        r8[al] = memory[ds*16 + 0x9429];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x942c);
        return;
    case 0x10ac7:
        r16[bx] = pop();
    case 0x10ac8:
        r16[bx] -= 0x0018;
        memory16set(ds, 0x942c, memory16get(ds, 0x942c) - 1);
        if (--r16[cx]) {
            pc = 0x10aa5;
            break;
        }
    case 0x10ad1:
        r16[ax] = 0x0000;
        return;
    } while (1);
}
function* sub_10ad5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 4 - 2);
        r16[bx] <<= 1;
        si = r16[bx];
        r8[al] = memory[ds*16 + 0x9502];
        if (r8[al] != 0x01) {
            pc = 0x10aec;
            break;
        }
        si += 0x0080;
        pc = 0x10af4;
        break;
    case 0x10aec:
        if (r8[al] != 0x02) {
            pc = 0x10af4;
            break;
        }
        si += 0x0100;
    case 0x10af4:
        r16[ax] = memory16get(ds, si + 37545);
        r16[ax] &= memory16get(ds, r16[bx] + 37417);
        if (r16[ax] == 0x0000) {
            pc = 0x10b51;
            break;
        }
        r8[bl] = r8[ah];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 693];
        if (r8[cl] == 0x00) {
            pc = 0x10b51;
            break;
        }
        memory16set(ds, 0x942c, 0x000a);
        r16[bx] <<= 1;
        r16[dx] = memory16get(ds, r16[bx] + 714);
        r16[dx] -= 0x000e;
        r16[bx] = memory16get(ds, r16[bx] + 756);
        r16[cx] = 0x000a;
    case 0x10b28:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (!flags.carry) {
            pc = 0x10b48;
            break;
        }
        push(r16[bx]);
        r16[bx] -= r16[dx];
        if (r16s[bx] > memory16gets(ss, bp + 6 - 2)) {
            pc = 0x10b47;
            break;
        }
        r16[bx] += r16[dx];
        r16[bx] += r16[dx];
        if (r16s[bx] < memory16gets(ss, bp + 6 - 2)) {
            pc = 0x10b47;
            break;
        }
        r16[ax] = pop();
        r16[ax] = 0x0001;
        r16[bx] = memory16get(ds, 0x942c);
        pc = 0x10b54;
        break;
    case 0x10b47:
        r16[bx] = pop();
    case 0x10b48:
        r16[bx] -= 0x0018;
        memory16set(ds, 0x942c, memory16get(ds, 0x942c) - 1);
        if (--r16[cx]) {
            pc = 0x10b28;
            break;
        }
    case 0x10b51:
        r16[ax] = 0x0000;
    case 0x10b54:
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_10b58() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x13a5;
        es = r16[ax];
        di = 0x1b8a;
    case 0x10b60:
        r8[al] = memory[ds*16 + di];
        if (r8[al] & 0x80) {
            pc = 0x10b78;
            break;
        }
        if (r8[al] & 0x01) {
            pc = 0x10b73;
            break;
        }
        push(di);
        r16[cx] = 0x0017;
        flags.direction = false;
        rep_movsb_data_data_forward();
        si = pop();
        return;
    case 0x10b73:
        di += 0x0017;
        pc = 0x10b60;
        break;
    case 0x10b78:
        si = 0x0000;
        return;
    } while (1);
}
function* sub_10b7c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x1b8a;
    case 0x10b7f:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80)
            return;
        memory[ds*16 + si] = 0x00;
        si += 0x0017;
        pc = 0x10b7f;
        break;
        return;
    } while (1);
}
function* sub_10b8e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x94f8);
        memory16set(ds, 0x942e, r16[ax]);
        memory16set(cs, 0x0d93, 0x0028);
        memory16set(ds, 0x9430, 0x0001);
        r16[cx] = 0x0007;
    case 0x10ba4:
        si = 0x1b8a;
    case 0x10ba7:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80) {
            pc = 0x10bc2;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x10bbd;
            break;
        }
        if (r8[cl] != memory[ds*16 + si + 2]) {
            pc = 0x10bbd;
            break;
        }
        push(r16[cx]);
        push(si);
        yield* sub_10bdc();
        si = pop();
        r16[cx] = pop();
    case 0x10bbd:
        si += 0x0017;
        pc = 0x10ba7;
        break;
    case 0x10bc2:
        if (--r16[cx]) {
            pc = 0x10ba4;
            break;
        }
        return;
    } while (1);
}
function* sub_10bc5() {
    r16[ax] = 0xa800;
    memory16set(ds, 0x942e, r16[ax]);
    memory16set(cs, 0x0d93, 0x0020);
    memory16set(ds, 0x9430, 0x0000);
    yield* sub_10bdc();
}
function* sub_10bdc() {
    r8[al] = memory[ds*16 + si + 11];
    cbw();
    r16[bx] = memory16get(ds, si + 5);
    r16[bx] -= r16[ax];
    push(r16[bx]);
    r8[al] = memory[ds*16 + si + 3];
    r8[al] += memory[ds*16 + si + 12];
    cbw();
    r16[ax] = -r16[ax];
    r16[ax] += memory16get(ds, si + 7);
    push(r16[ax]);
    r8[al] = memory[ds*16 + si + 9];
    r8[ah] = 0x00;
    push(r16[ax]);
    r8[al] = memory[ds*16 + si + 10];
    r8[ah] = 0x00;
    push(r16[ax]);
    r16[bx] = memory16get(ds, si + 13);
    r16[bx] = memory16get(ds, r16[bx] + 38120);
    r8[al] = memory[ds*16 + si + 17];
    memory[cs*16 + 0x0d95] = r8[al];
    r8[cl] = r8[al];
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[al] |= r8[cl];
    memory[cs*16 + 0x0d96] = r8[al];
    si = memory16get(ds, si + 15);
    yield* sub_10c24();
}
function* sub_10c24() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ds, 0x9430);
        if (r16[ax] != 0x0000) {
            pc = 0x10c32;
            break;
        }
        pc = 0x10cbc;
        break;
    case 0x10c32:
        r16[ax] = memory16get(ss, bp + 8 - 2);
        r16[ax] -= memory16get(ds, 0x9528);
        r16[ax] &= 0x03ff;
        if (!(r16[ax] & 0x0200)) {
            pc = 0x10c44;
            break;
        }
        r16[ax] |= 0xfc00;
    case 0x10c44:
        memory16set(ss, bp + 8 - 2, r16[ax]);
        if (r16s[ax] >= signed16(0x0000)) {
            pc = 0x10c77;
            break;
        }
        memory16set(ss, bp + 4 - 2, memory16get(ss, bp + 4 - 2) + r16[ax]);
        if (memory16gets(ss, bp + 4 - 2) >= 0) {
            pc = 0x10c54;
            break;
        }
        pc = 0x10d8f;
        break;
    case 0x10c54:
        if (memory16get(ss, bp + 4 - 2) != 0) {
            pc = 0x10c59;
            break;
        }
        pc = 0x10d8f;
        break;
    case 0x10c59:
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
        memory16set(ss, bp + 8 - 2, r16[ax]);
        pc = 0x10c8f;
        break;
    case 0x10c77:
        r16[ax] += memory16get(ss, bp + 4 - 2);
        r16[ax] -= 0x00a0;
        if (r16s[ax] < 0) {
            pc = 0x10c8f;
            break;
        }
        r16[ax] = -r16[ax];
        r16[ax] += memory16get(ss, bp + 4 - 2);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x10c8c;
            break;
        }
        pc = 0x10d8f;
        break;
    case 0x10c8c:
        memory16set(ss, bp + 4 - 2, r16[ax]);
    case 0x10c8f:
        r16[ax] = 0x0020;
        memory16set(ss, bp + 10 - 2, memory16get(ss, bp + 10 - 2) + r16[ax]);
        r16[ax] = 0x0008;
        memory16set(ss, bp + 8 - 2, memory16get(ss, bp + 8 - 2) + r16[ax]);
        r16[ax] = memory16get(ss, bp + 10 - 2);
        if (r16s[ax] >= signed16(0x0020)) {
            pc = 0x10cab;
            break;
        }
        r16[ax] = 0x0020;
        memory16set(ss, bp + 10 - 2, r16[ax]);
        pc = 0x10cbc;
        break;
    case 0x10cab:
        r16[ax] += memory16get(ss, bp + 6 - 2);
        if (r16s[ax] <= signed16(0x0120)) {
            pc = 0x10cbc;
            break;
        }
        r16[ax] = 0x0120;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        memory16set(ss, bp + 10 - 2, r16[ax]);
    case 0x10cbc:
        push(ds);
        push(r16[bx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0a05;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0007;
        out16(r16[dx], r16[ax]);
        r16[ax] = memory16get(ss, bp + 10 - 2);
        r16[bx] = memory16get(ss, bp + 8 - 2);
        push(r16[cx]);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[cx] = memory16get(cs, 0x0d93);
        if (r16[cx] != 0x0028) {
            pc = 0x10ce4;
            break;
        }
        di = r16[bx];
        pc = 0x10ce7;
        break;
    case 0x10ce4:
        di = 0x0000;
    case 0x10ce7:
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
        r16[bx] = memory16get(ds, 0x942e);
        es = r16[bx];
        r16[cx] = pop();
        r16[cx] = memory16get(ss, bp + 6 - 2);
        r16[cx] >>= 1;
        r8[al] = 0x08;
        ds = pop();
        r16[bx] = memory16get(ss, bp + 4 - 2);
    case 0x10d13:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(di);
        push(si);
    case 0x10d18:
        r8[bh] = memory[cs*16 + 0x0d96];
    case 0x10d1d:
        r8[bl] = memory[ds*16 + si];
        si++;
        if (r8[bh] != r8[bl]) {
            pc = 0x10d3a;
            break;
        }
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10d2f;
            break;
        }
        r8[ah] = 0x40;
        di++;
        if (--r16[cx]) {
            pc = 0x10d1d;
            break;
        }
        pc = 0x10d6d;
        break;
    case 0x10d2f:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10d36;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x10d36:
        if (--r16[cx]) {
            pc = 0x10d1d;
            break;
        }
        pc = 0x10d6d;
        break;
    case 0x10d3a:
        r8[bh] = r8[bl];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        if (r8[bl] == memory[cs*16 + 0x0d95]) {
            pc = 0x10d4f;
            break;
        }
        out16(r16[dx], r16[ax]);
        videoSet(es, di, videoGet(es, di) & r8[bl]);
    case 0x10d4f:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10d56;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x10d56:
        r8[bh] &= 0x0f;
        if (r8[bh] == memory[cs*16 + 0x0d95]) {
            pc = 0x10d64;
            break;
        }
        out16(r16[dx], r16[ax]);
        videoSet(es, di, videoGet(es, di) & r8[bh]);
    case 0x10d64:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x10d6b;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x10d6b:
        if (--r16[cx]) {
            pc = 0x10d18;
            break;
        }
    case 0x10d6d:
        si = pop();
        si += 0x00a0;
        di = pop();
        di += memory16get(cs, 0x0d93);
        di &= 0x7fff;
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[bx]--;
        if (r16[bx] != 0) {
            pc = 0x10d13;
            break;
        }
        ds = pop();
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f07;
        out16(r16[dx], r16[ax]);
    case 0x10d8f:
        bp = pop();
        sp += 8;
        return;
    } while (1);
}
function* sub_10d98() {
    memory16set(ds, 0x9528, 0x001a);
    memory[ds*16 + 0x9513] = 0x00;
    yield* sub_10b7c();
}
function* sub_10da7() {
    yield* sub_109a4();
    yield* sub_1069a();
    memory[ds*16 + 0x9519] = 0x00;
    memory[ds*16 + 0x951a] = 0x00;
    memory[ds*16 + 0x951b] = 0x00;
    yield* sub_10e3d();
}
function* sub_10dc0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x94fe] += 1;
        r8[al] = memory[ds*16 + 0x94fe];
        if (r8[al] < 0x06) {
            pc = 0x10dd3;
            break;
        }
        memory16set(ds, 0x94fc, 0x0030);
        pc = 0x10de5;
        break;
    case 0x10dd3:
        if (r8[al] < 0x03) {
            pc = 0x10ddf;
            break;
        }
        memory16set(ds, 0x94fc, 0x0020);
        pc = 0x10de5;
        break;
    case 0x10ddf:
        memory16set(ds, 0x94fc, 0x0010);
    case 0x10de5:
        memory[ds*16 + 0x9501] += 1;
        r8[al] = memory[ds*16 + 0x9501];
        if (r8[al] <= 0x07) {
            pc = 0x10df5;
            break;
        }
        memory[ds*16 + 0x9501] = 0x01;
    case 0x10df5:
        yield* sub_109a4();
        yield* sub_1069a();
        memory[ds*16 + 0x9519] = 0x00;
        yield* sub_10e3d();
        yield* sub_12a7f();
        return;
    } while (1);
}
function* sub_10e07() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9534);
        if (r16[ax] != 0x0000) {
            pc = 0x10e15;
            break;
        }
        memory[ds*16 + 0x9500] = 0x01;
        return;
    case 0x10e15:
        yield* sub_12329();
        r8[al] = memory[ds*16 + 0x9502];
        if (r8[al] == 0x00) {
            pc = 0x10e27;
            break;
        }
        memory[ds*16 + 0x9502] = 0x00;
        yield* sub_1069a();
    case 0x10e27:
        yield* sub_12200();
        memory[ds*16 + 0x9519] = 0x01;
        memory[ds*16 + 0x951a] = 0x00;
        memory[ds*16 + 0x951b] = 0x00;
        yield* sub_10e3d();
        return;
    } while (1);
}
function* sub_10e3d() {
    r8[bl] = memory[ds*16 + 0x9501];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 5365);
    r16[ax] &= 0x03ff;
    memory16set(ds, 0x9528, r16[ax]);
    r16[ax] = memory16get(ds, 0x94fc);
    memory16set(ds, 0x952a, r16[ax]);
    memory16set(ds, 0x950a, 0x0080);
    memory[ds*16 + 0x950e] = 0x00;
    memory16set(ds, 0x950f, 0x0000);
    memory16set(ds, 0x9511, 0x0000);
    memory[ds*16 + 0x9513] = 0x00;
    memory[ds*16 + 0x9515] = 0x00;
    memory[ds*16 + 0x9517] = 0x00;
    memory[ds*16 + 0x9432] = 0x00;
    yield* sub_10e84();
}
function* sub_10e84() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x950e];
        if (r8[al] == 0x00) {
            pc = 0x10e93;
            break;
        }
        memory[ds*16 + 0x950e] = 0x00;
        yield* sub_1069a();
    case 0x10e93:
        memory16set(ds, 0x952c, 0x0000);
        yield* sub_10b7c();
        si = 0x0d32;
        yield* sub_10b58();
        r16[ax] = memory16get(ds, 0x950a);
        memory16set(ds, 0x1b8f, r16[ax]);
        yield* sub_11b57();
        r16[ax] = memory16get(ds, 0x9528);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] -= 0x0003;
        r16[ax] &= 0x003f;
        memory16set(ds, 0x9507, r16[ax]);
        r16[cx] = 0x000f;
    case 0x10ec2:
        push(r16[cx]);
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_108ba();
        r16[ax] = pop();
        r16[cx] = pop();
        r16[ax]++;
        r16[ax] &= 0x003f;
        if (--r16[cx]) {
            pc = 0x10ec2;
            break;
        }
        r8[al] = memory[ds*16 + 0x9432];
        if (r8[al] == 0x00) {
            pc = 0x10eea;
            break;
        }
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        memory[ds*16 + si + 4] = 0x0a;
        yield* sub_12121();
        memory[ds*16 + 0x1b9c] = 0x23;
        return;
    case 0x10eea:
        r8[al] = memory[ds*16 + 0x9519];
        if (r8[al] == 0x00) {
            pc = 0x10f08;
            break;
        }
        memory[ds*16 + 0x9519] = 0x00;
        si = 0x0da2;
        r16[ax] = memory16get(ds, 0x1b91);
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x1b8d];
        memory[ds*16 + si + 3] = r8[al];
        yield* sub_10b58();
    case 0x10f08:
        yield* sub_10f9d();
        r8[al] = memory[ds*16 + 0x951a];
        if (r8[al] == 0x00) {
            pc = 0x10f23;
            break;
        }
        memory[ds*16 + 0x951a] = 0x01;
        si = 0x0dc3;
        memory[ds*16 + si] = memory[ds*16 + si] & 0xdf;
        yield* sub_11cd9();
        yield* sub_10b58();
    case 0x10f23:
        r8[al] = memory[ds*16 + 0x951b];
        if (r8[al] == 0x00)
            return;
        memory[ds*16 + 0x951b] = 0x01;
        si = 0x0dc3;
        memory[ds*16 + si] = memory[ds*16 + si] | 0x20;
        yield* sub_11cd9();
        yield* sub_10b58();
        return;
    } while (1);
}
function* sub_10f3c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x951c] = 0x00;
        yield* sub_12ddc();
        memory16set(ds, 0x9528, 0x001a);
        memory16set(ds, 0x9547, 0x0000);
        memory16set(ds, 0x951e, 0x0000);
        memory[ds*16 + 0x9524] = 0x00;
        memory[ds*16 + 0x9549] = 0x03;
        yield* sub_10b7c();
        si = 0x0d04;
        yield* sub_10b58();
        yield* sub_12df6();
        r8[al] = memory[ds*16 + 0x951a];
        if (r8[al] == 0x00) {
            pc = 0x10f84;
            break;
        }
        memory[ds*16 + 0x951a] = 0x01;
        si = 0x0d1b;
        memory[ds*16 + si] = memory[ds*16 + si] & 0xdf;
        yield* sub_12f50();
        yield* sub_10b58();
    case 0x10f84:
        r8[al] = memory[ds*16 + 0x951b];
        if (r8[al] == 0x00)
            return;
        memory[ds*16 + 0x951b] = 0x01;
        si = 0x0d1b;
        memory[ds*16 + si] = memory[ds*16 + si] | 0x20;
        yield* sub_12f50();
        yield* sub_10b58();
        return;
    } while (1);
}
function* sub_10f9d() {
    r16[ax] = memory16get(ds, 0x1b8f);
    memory16set(ds, 0x9433, r16[ax]);
    memory16set(ds, 0x9435, r16[ax]);
    memory16set(ds, 0x9437, r16[ax]);
    memory16set(ds, 0x9439, r16[ax]);
    r16[ax] = memory16get(ds, 0x1b91);
    memory16set(ds, 0x943b, r16[ax]);
    memory16set(ds, 0x943d, r16[ax]);
    memory16set(ds, 0x943f, r16[ax]);
    memory16set(ds, 0x9441, r16[ax]);
    r8[al] = memory[ds*16 + 0x1b8e];
    memory[ds*16 + 0x9443] = r8[al];
    memory[ds*16 + 0x9444] = r8[al];
    memory[ds*16 + 0x9445] = r8[al];
    memory[ds*16 + 0x9446] = r8[al];
    r8[al] = memory[ds*16 + 0x1b8d];
    memory[ds*16 + 0x9447] = r8[al];
    memory[ds*16 + 0x9448] = r8[al];
    memory[ds*16 + 0x9449] = r8[al];
    memory[ds*16 + 0x944a] = r8[al];
}
function* sub_10fda() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x10fda:
        r8[al] = memory[ds*16 + 0x94ff];
        memory[ds*16 + 0x9509] = r8[al];
        si = 0x1b8a;
    case 0x10fe3:
        r8[al] = memory[ds*16 + 0x9513];
        if (r8[al] == 0x00) {
            pc = 0x10ff5;
            break;
        }
        yield* sub_10e07();
        r8[al] = memory[ds*16 + 0x9500];
        if (r8[al] == 0x00) {
            pc = 0x10fda;
            break;
        }
        return;
    case 0x10ff5:
        r8[al] = memory[ds*16 + 0x94ff];
        if (r8[al] == memory[ds*16 + 0x9509]) {
            pc = 0x11036;
            break;
        }
        if (r8[al] != 0x01) {
            pc = 0x1100e;
            break;
        }
        r8[al] = 0x0b;
        yield* sub_13840();
        yield* sub_10f3c();
        pc = 0x10fda;
        break;
    case 0x1100e:
        r8[al] = 0x0b;
        yield* sub_13840();
        r8[al] = memory[ds*16 + 0x951d];
        if (r8[al] != 0xf0) {
            pc = 0x1101f;
            break;
        }
        yield* sub_10dc0();
        pc = 0x11034;
        break;
    case 0x1101f:
        r8[al] = memory[ds*16 + 0x1ba0];
        r8[al] &= 0x7f;
        if (r8[al] <= 0x28) {
            pc = 0x11031;
            break;
        }
        if (r8[al] >= 0x58) {
            pc = 0x11031;
            break;
        }
        memory[ds*16 + 0x9432] = 0x01;
    case 0x11031:
        yield* sub_10e84();
    case 0x11034:
        pc = 0x10fda;
        break;
    case 0x11036:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80)
            return;
        if (!(r8[al] & 0x02)) {
            pc = 0x11054;
            break;
        }
        push(si);
        r8[bl] = memory[ds*16 + si + 18];
        if (r8[bl] == 0x00) {
            pc = 0x11053;
            break;
        }
        r8[bh] = 0x00;
        r16[bx]--;
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: yield* sub_11108(); break;
        case 2: yield* sub_1176c(); break;
        case 4: yield* sub_11783(); break;
        case 6: yield* sub_110c6(); break;
        case 8: yield* sub_117ac(); break;
        case 10: yield* sub_117d6(); break;
        case 12: yield* sub_118a9(); break;
        case 14: yield* sub_11a9e(); break;
        case 16: yield* sub_110c6(); break;
        case 18: yield* sub_11993(); break;
        case 20: yield* sub_119c2(); break;
        case 22: yield* sub_12e02(); break;
        case 24: yield* sub_110c6(); break;
        case 26: yield* sub_12fe8(); break;
        case 28: yield* sub_1300a(); break;
        case 30: yield* sub_116fe(); break;
        case 32: yield* sub_112cb(); break;
        case 34: yield* sub_110c6(); break;
        case 36: yield* sub_112eb(); break;
        case 38: yield* sub_115fc(); break;
        case 40: yield* sub_116df(); break;
        case 42: yield* sub_116d6(); break;
        case 44: yield* sub_11740(); break;
        case 46: yield* sub_11384(); break;
        case 48: yield* sub_113a8(); break;
        case 50: yield* sub_114f0(); break;
        case 52: yield* sub_110f3(); break;
        case 54: yield* sub_118c7(); break;
        case 56: yield* sub_11429(); break;
        case 58: yield* sub_117f4(); break;
        case 60: yield* sub_1171f(); break;
        case 62: yield* sub_11b09(); break;
        case 64: yield* sub_11b4a(); break;
        case 66: yield* sub_12f50(); break;
        case 68: yield* sub_112a7(); break;
            default:
            assert(0);
        }
    case 0x11053:
        si = pop();
    case 0x11054:
        si += 0x0017;
        pc = 0x10fe3;
        break;
        return;
    } while (1);
}
function* sub_110a0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si + 10];
        r8[al] -= memory[ds*16 + si + 3];
        r8[al] -= memory[ds*16 + si + 12];
        cbw();
        r16[ax] += memory16get(ds, si + 7);
        r16[ax] &= 0x03ff;
        r16[bx] = memory16get(ds, 0x9528);
        if (r16[ax] >= r16[bx]) {
            pc = 0x110bb;
            break;
        }
        r16[ax] += 0x0400;
    case 0x110bb:
        r16[ax] -= r16[bx];
        if (r16[ax] <= 0x0200)
            return;
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_110c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si + 3];
        r8[al] += memory[ds*16 + si + 12];
        cbw();
        r16[ax] = -r16[ax];
        r16[ax] += memory16get(ds, si + 7);
        r16[ax] &= 0x03ff;
        r16[bx] = memory16get(ds, 0x9528);
        r16[bx] += 0x00a0;
        r16[bx] &= 0x03ff;
        if (r16[ax] >= r16[bx]) {
            pc = 0x110e8;
            break;
        }
        r16[ax] += 0x0400;
    case 0x110e8:
        r16[ax] -= r16[bx];
        if (r16[ax] >= 0x0200)
            return;
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_110f3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si + 22] += 1;
        r8[al] = memory[ds*16 + si + 22];
        if (r8[al] <= 0x08) {
            pc = 0x110ff;
            break;
        }
        r8[al] = 0x08;
    case 0x110ff:
        r8[ah] = 0x00;
        memory16set(ds, si + 7, memory16get(ds, si + 7) - r16[ax]);
        yield* sub_110a0();
        return;
    } while (1);
}
function* sub_11108() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_11b80();
        yield* sub_11bb9();
        r16[bx] = memory16get(ds, 0x954c);
        r16[ax] = memory16get(ds, 0x952c);
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
            pc = 0x1112f;
            break;
        }
        r16[ax] = 0xffe8;
    case 0x1112f:
        pc = 0x11158;
        break;
    case 0x11131:
        if (!(r8[bl] & 0x02)) {
            pc = 0x1114d;
            break;
        }
        r16[ax] += 0x0001;
        if (r16s[ax] >= 0) {
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
            pc = 0x1114b;
            break;
        }
        r16[ax] = 0x0018;
    case 0x1114b:
        pc = 0x11158;
        break;
    case 0x1114d:
        if (r16[ax] == 0x0000) {
            pc = 0x11158;
            break;
        }
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x11157;
            break;
        }
        r16[ax]--;
        pc = 0x11158;
        break;
    case 0x11157:
        r16[ax]++;
    case 0x11158:
        memory16set(ds, 0x952c, r16[ax]);
        r16[ax] += 0x0003;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] += memory16get(ds, 0x1b8f);
        if (r16s[ax] >= signed16(0x0014)) {
            pc = 0x11174;
            break;
        }
        r16[ax] = 0x0014;
        memory16set(ds, 0x952c, 0x0000);
    case 0x11174:
        if (r16s[ax] <= signed16(0x00ec)) {
            pc = 0x11182;
            break;
        }
        r16[ax] = 0x00ec;
        memory16set(ds, 0x952c, 0x0000);
    case 0x11182:
        memory16set(ds, 0x1b8f, r16[ax]);
        r8[al] = memory[ds*16 + 0x1b8e];
        if (r8[al] == 0x00) {
            pc = 0x1118f;
            break;
        }
        yield* sub_11b57();
    case 0x1118f:
        yield* sub_11c78();
        yield* sub_10a51();
        if (r16[ax] == 0x0000) {
            pc = 0x1119f;
            break;
        }
        yield* sub_11c56();
        pc = 0x111bc;
        break;
    case 0x1119f:
        memory[ds*16 + 0x1b9e] += 1;
        memory[ds*16 + 0x1b9e] = memory[ds*16 + 0x1b9e] & 0x3f;
        yield* sub_10a51();
        if (r16[ax] == 0x0000) {
            pc = 0x111b3;
            break;
        }
        yield* sub_11c56();
    case 0x111b3:
        memory[ds*16 + 0x1b9e] -= 1;
        memory[ds*16 + 0x1b9e] = memory[ds*16 + 0x1b9e] & 0x3f;
    case 0x111bc:
        r16[ax] = memory16get(ds, 0x9542);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x111c8;
            break;
        }
        yield* sub_11c33();
        return;
    case 0x111c8:
        r8[al] = memory[ds*16 + 0x1b8e];
        if (r8[al] != 0x00) {
            pc = 0x111de;
            break;
        }
        memory[ds*16 + 0x9515] += 1;
        r8[al] = memory[ds*16 + 0x9515];
        if (r8[al] < 0x04) {
            pc = 0x111dd;
            break;
        }
        yield* sub_11c33();
    case 0x111dd:
        return;
    case 0x111de:
        r16[ax] = memory16get(ds, 0x953e);
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x111f0;
            break;
        }
        r16[ax] = memory16get(ds, 0x954c);
        if (!(r8[al] & 0x80)) {
            pc = 0x111f0;
            break;
        }
        yield* sub_11d1e();
    case 0x111f0:
        r16[ax] = memory16get(ds, 0x954c);
        r8[bl] = memory[ds*16 + 0x951a];
        if (!(r8[al] & 0x40)) {
            pc = 0x11235;
            break;
        }
        if (r8[bl] != 0x00) {
            pc = 0x11224;
            break;
        }
        r16[ax] = memory16get(ds, 0x9536);
        if (r16[ax] <= 0x0000) {
            pc = 0x11222;
            break;
        }
        memory[ds*16 + 0x951a] = 0x01;
        si = 0x0dc3;
        memory[ds*16 + si] = memory[ds*16 + si] & 0xdf;
        yield* sub_11cd9();
        yield* sub_10b58();
        memory16set(ds, 0x9538, memory16get(ds, 0x9538) - 1);
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
        memory[ds*16 + 0x951a] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
    case 0x11233:
        pc = 0x1124b;
        break;
    case 0x11235:
        if (r8[bl] != 0x01) {
            pc = 0x11241;
            break;
        }
        memory[ds*16 + 0x951a] = 0x02;
        pc = 0x1124b;
        break;
    case 0x11241:
        if (r8[bl] != 0x03) {
            pc = 0x1124b;
            break;
        }
        memory[ds*16 + 0x951a] = 0x00;
    case 0x1124b:
        r16[ax] = memory16get(ds, 0x954c);
        r8[bl] = memory[ds*16 + 0x951b];
        if (!(r8[al] & 0x20)) {
            pc = 0x11290;
            break;
        }
        if (r8[bl] != 0x00) {
            pc = 0x1127f;
            break;
        }
        r16[ax] = memory16get(ds, 0x9536);
        if (r16[ax] <= 0x0000) {
            pc = 0x1127d;
            break;
        }
        memory[ds*16 + 0x951b] = 0x01;
        si = 0x0dc3;
        memory[ds*16 + si] = memory[ds*16 + si] | 0x20;
        yield* sub_11cd9();
        yield* sub_10b58();
        memory16set(ds, 0x9538, memory16get(ds, 0x9538) - 1);
        r8[al] = 0x01;
        yield* sub_13840();
    case 0x1127d:
        pc = 0x1128e;
        break;
    case 0x1127f:
        if (r8[bl] != 0x02) {
            pc = 0x1128e;
            break;
        }
        memory[ds*16 + 0x951b] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
    case 0x1128e:
        return;
    case 0x11290:
        if (r8[bl] != 0x01) {
            pc = 0x1129c;
            break;
        }
        memory[ds*16 + 0x951b] = 0x02;
        return;
    case 0x1129c:
        if (r8[bl] != 0x03)
            return;
        memory[ds*16 + 0x951b] = 0x00;
        return;
    } while (1);
}
function* sub_112a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x952a);
        r16[ax] -= 0x0003;
        if (r16s[ax] < 0) {
            pc = 0x112b4;
            break;
        }
        memory16set(ds, 0x952a, r16[ax]);
        pc = 0x112b7;
        break;
    case 0x112b4:
        yield* sub_11c33();
    case 0x112b7:
        yield* sub_11bb9();
        yield* sub_11b57();
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        memory[ds*16 + si + 4] = 0x0a;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_112cb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x952a);
        r16[ax]--;
        if (r16s[ax] < 0) {
            pc = 0x112d4;
            break;
        }
        memory16set(ds, 0x952a, r16[ax]);
    case 0x112d4:
        yield* sub_11bb9();
        yield* sub_11b57();
        memory[ds*16 + 0x9514] += 1;
        r8[al] = memory[ds*16 + 0x9514];
        if (r8[al] < 0x28)
            return;
        memory[ds*16 + 0x9513] = 0x01;
        return;
    } while (1);
}
function* sub_112eb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110a0();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x112f5;
            break;
        }
        return;
    case 0x112f5:
        memory16set(ds, si + 7, memory16get(ds, si + 7) - 0x0010);
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] != 0x01) {
            pc = 0x11312;
            break;
        }
        r8[al] = memory[ds*16 + si + 3];
        if (r8s[al] <= signed8(0x9c)) {
            pc = 0x11310;
            break;
        }
        memory[ds*16 + si + 3] -= 0x08;
    case 0x11310:
        pc = 0x11321;
        break;
    case 0x11312:
        if (r8[al] != 0x02) {
            pc = 0x11321;
            break;
        }
        r8[al] = memory[ds*16 + si + 3];
        if (r8s[al] >= signed8(0x64)) {
            pc = 0x11321;
            break;
        }
        memory[ds*16 + si + 3] += 0x08;
    case 0x11321:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        push(r16[ax]);
        yield* sub_107fd();
        si = pop();
        if (r8s[al] < memorys[ds*16 + si + 3]) {
            pc = 0x11338;
            break;
        }
        yield* sub_12092();
        return;
    case 0x11338:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        memory[ds*16 + si + 20] = r8[cl];
        push(r16[cx]);
        yield* sub_10ad5();
        si = pop();
        if (r16[ax] == 0x0000)
            return;
        push(si);
        r8[al] = memory[ds*16 + si + 20];
        r8[ah] = 0x00;
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_11c0a();
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80) {
            pc = 0x11382;
            break;
        }
        r16[bx] = pop();
        push(r16[bx]);
        r8[al] = memory[ds*16 + si + 3];
        r8[al] -= memory[ds*16 + r16[bx] + 3];
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
        memory[ds*16 + si + 21] -= 1;
        if (memorys[ds*16 + si + 21] >= 0) {
            pc = 0x1137a;
            break;
        }
        yield* sub_120db();
        r8[al] = 0x06;
        yield* sub_13840();
        pc = 0x1137d;
        break;
    case 0x1137a:
        yield* sub_12662();
    case 0x1137d:
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
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x1138e;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1138e:
        yield* sub_11cd9();
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x20) {
            pc = 0x1139c;
            break;
        }
        r8[al] = memory[ds*16 + 0x951a];
        pc = 0x1139f;
        break;
    case 0x1139c:
        r8[al] = memory[ds*16 + 0x951b];
    case 0x1139f:
        if (r8[al] != 0x03)
            return;
        memory[ds*16 + si + 18] = 0x19;
        return;
    } while (1);
}
function* sub_113a8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110a0();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x113b2;
            break;
        }
        return;
    case 0x113b2:
        memory16set(ds, si + 7, memory16get(ds, si + 7) - 0x0006);
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        push(r16[ax]);
        yield* sub_107fd();
        si = pop();
        r8[al] += 0x04;
        memory[ds*16 + si + 3] = r8[al];
        memory[ds*16 + si + 20] = r8[cl];
        memory[ds*16 + si + 4] = r8[bl];
        r16[bx] = 0x0dda;
        yield* sub_12121();
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] != 0x00) {
            pc = 0x113f5;
            break;
        }
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0004);
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        memory[ds*16 + si + 21] -= 1;
        if (memorys[ds*16 + si + 21] >= 0) {
            pc = 0x113f5;
            break;
        }
        yield* sub_120f0();
        memory[ds*16 + si] = 0x00;
        return;
    case 0x113f5:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r8[cl] = memory[ds*16 + si + 20];
        r8[ch] = 0x00;
        push(r16[cx]);
        yield* sub_10ad5();
        si = pop();
        if (r16[ax] == 0x0000)
            return;
        push(si);
        r8[al] = memory[ds*16 + si + 20];
        r8[ah] = 0x00;
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_11c0a();
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80) {
            pc = 0x11427;
            break;
        }
        yield* sub_120db();
        r8[al] = 0x06;
        yield* sub_13840();
        si = pop();
        push(si);
        memory[ds*16 + si] = 0x00;
    case 0x11427:
        si = pop();
        return;
    } while (1);
}
function* sub_11429() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110c6();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x11433;
            break;
        }
        return;
    case 0x11433:
        r8[al] = memory[ds*16 + si + 1];
        if (r8[al] != 0x02) {
            pc = 0x11440;
            break;
        }
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0005);
        pc = 0x1146a;
        break;
    case 0x11440:
        if (r8[al] != 0x00) {
            pc = 0x1144a;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0005);
        pc = 0x1146a;
        break;
    case 0x1144a:
        if (r8[al] != 0x01) {
            pc = 0x11458;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0003);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0002);
        pc = 0x1146a;
        break;
    case 0x11458:
        if (r8[al] != 0x03) {
            pc = 0x11466;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0003);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0002);
        pc = 0x1146a;
        break;
    case 0x11466:
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0005);
    case 0x1146a:
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        r16[ax] = memory16get(ds, si + 5);
        if (r16s[ax] >= signed16(0x000c)) {
            pc = 0x1147b;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x1147b:
        if (r16s[ax] <= signed16(0x00f4)) {
            pc = 0x11484;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11484:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        push(r16[ax]);
        yield* sub_107fd();
        si = pop();
        r8[al] += 0x08;
        memory[ds*16 + si + 3] = r8[al];
        memory[ds*16 + si + 20] = r8[cl];
        memory[ds*16 + si + 4] = r8[bl];
        r8[bl] = memory[ds*16 + si + 1];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 4351);
        yield* sub_12121();
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x114b2;
            break;
        }
        return;
    case 0x114b2:
        r16[ax] = memory16get(ds, si + 5);
        r16[ax] -= memory16get(ds, 0x1b8f);
        if (r16s[ax] >= 0) {
            pc = 0x114bd;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x114bd:
        if (r16[ax] >= 0x0010)
            return;
        r16[ax] = memory16get(ds, si + 7);
        r16[ax] -= memory16get(ds, 0x1b91);
        r16[ax] -= 0x0008;
        if (r16s[ax] >= 0) {
            pc = 0x114d0;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x114d0:
        if (r16[ax] >= 0x0010)
            return;
        r8[al] = 0x05;
        yield* sub_13840();
        memory16set(ds, 0x9544, memory16get(ds, 0x9544) - 0x0064);
        memory[ds*16 + 0x12a0] = 0x01;
        yield* sub_120f0();
        memory[ds*16 + 0x12a0] = 0x05;
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_114f0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0001);
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        push(r16[ax]);
        yield* sub_107fd();
        si = pop();
        memory[ds*16 + si + 3] = r8[al];
        memory[ds*16 + si + 20] = r8[cl];
        memory[ds*16 + si + 4] = r8[bl];
        r8[bl] = memory[ds*16 + si + 1];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 4065);
        yield* sub_12121();
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] == 0x11) {
            pc = 0x11548;
            break;
        }
        r16[ax] = memory16get(ds, si + 5);
        r16[ax] -= memory16get(ds, 0x1b8f);
        if (r16s[ax] >= 0) {
            pc = 0x1152a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1152a:
        if (r16[ax] >= 0x001a) {
            pc = 0x11548;
            break;
        }
        r16[ax] = memory16get(ds, si + 7);
        r16[ax] -= memory16get(ds, 0x1b91);
        if (r16s[ax] >= 0) {
            pc = 0x1153a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1153a:
        if (r16[ax] >= 0x0012) {
            pc = 0x11548;
            break;
        }
        memory16set(ds, 0x9544, memory16get(ds, 0x9544) - 0x000c);
        memory[ds*16 + si + 21] = 0xff;
    case 0x11548:
        di = 0x1ba1;
    case 0x1154b:
        r8[al] = memory[ds*16 + si + 21];
        if (r8s[al] >= signed8(0x00)) {
            pc = 0x11561;
            break;
        }
        r8[al] = 0x07;
        yield* sub_13840();
        yield* sub_120f0();
        memory[ds*16 + si] = 0x00;
        yield* sub_12676();
        return;
    case 0x11561:
        r8[al] = memory[ds*16 + di];
        if (r8[al] & 0x80) {
            pc = 0x115c0;
            break;
        }
        if (!(r8[al] & 0x40)) {
            pc = 0x115bb;
            break;
        }
        push(di);
        r16[ax] = memory16get(ds, di + 5);
        r16[ax] -= memory16get(ds, si + 5);
        if (r16s[ax] >= 0) {
            pc = 0x11576;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11576:
        if (r16[ax] >= 0x0014) {
            pc = 0x115ba;
            break;
        }
        r16[ax] = memory16get(ds, di + 7);
        r16[ax] -= memory16get(ds, si + 7);
        if (r16s[ax] >= 0) {
            pc = 0x11585;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11585:
        if (r16[ax] >= 0x0010) {
            pc = 0x115ba;
            break;
        }
        r8[al] = memory[ds*16 + di + 18];
        if (r8[al] != 0x19) {
            pc = 0x1159a;
            break;
        }
        memory[ds*16 + si + 21] = 0xff;
        memory[ds*16 + di] = 0x00;
        pc = 0x115ba;
        break;
    case 0x1159a:
        r8[al] = memory[ds*16 + di + 3];
        r8[al] -= memory[ds*16 + si + 3];
        if (r8s[al] >= 0) {
            pc = 0x115a4;
            break;
        }
        r8[al] = -r8[al];
    case 0x115a4:
        if (r8[al] >= 0x10) {
            pc = 0x115ba;
            break;
        }
        memory[ds*16 + si + 21] -= 1;
        push(si);
        si = di;
        yield* sub_12092();
        r8[al] = 0x03;
        yield* sub_13840();
        yield* sub_12662();
        si = pop();
    case 0x115ba:
        di = pop();
    case 0x115bb:
        di += 0x0017;
        pc = 0x1154b;
        break;
    case 0x115c0:
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] == 0x11) {
            pc = 0x115f8;
            break;
        }
        r16[ax] = memory16get(ds, 0x1b91);
        if (r16[ax] <= memory16get(ds, si + 7)) {
            pc = 0x115f8;
            break;
        }
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
        if (r16s[ax] >= 0) {
            pc = 0x115d9;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x115d9:
        if (r16[ax] >= 0x0020) {
            pc = 0x115f8;
            break;
        }
        memory[ds*16 + si + 22] -= 1;
        if (memorys[ds*16 + si + 22] >= 0) {
            pc = 0x115ee;
            break;
        }
        memory[ds*16 + si + 22] = 0x07;
        memory[ds*16 + 0x9518] = 0x01;
        pc = 0x115f3;
        break;
    case 0x115ee:
        memory[ds*16 + 0x9518] = 0x00;
    case 0x115f3:
        push(si);
        yield* sub_11def();
        si = pop();
    case 0x115f8:
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_115fc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110c6();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x11606;
            break;
        }
        return;
    case 0x11606:
        r8[al] = memory[ds*16 + si + 1];
        if (r8[al] != 0x02) {
            pc = 0x11613;
            break;
        }
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0008);
        pc = 0x1163d;
        break;
    case 0x11613:
        if (r8[al] != 0x00) {
            pc = 0x1161d;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0008);
        pc = 0x1163d;
        break;
    case 0x1161d:
        if (r8[al] != 0x01) {
            pc = 0x1162b;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0006);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0004);
        pc = 0x1163d;
        break;
    case 0x1162b:
        if (r8[al] != 0x03) {
            pc = 0x11639;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0006);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0004);
        pc = 0x1163d;
        break;
    case 0x11639:
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0008);
    case 0x1163d:
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        r16[ax] = memory16get(ds, si + 5);
        if (r16s[ax] >= signed16(0x0004)) {
            pc = 0x1164e;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x1164e:
        if (r16s[ax] <= signed16(0x00fc)) {
            pc = 0x11657;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11657:
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] != 0x01) {
            pc = 0x1166b;
            break;
        }
        r8[al] = memory[ds*16 + si + 3];
        if (r8s[al] >= signed8(0x64)) {
            pc = 0x11669;
            break;
        }
        memory[ds*16 + si + 3] += 0x04;
    case 0x11669:
        pc = 0x1167a;
        break;
    case 0x1166b:
        if (r8[al] != 0x02) {
            pc = 0x1167a;
            break;
        }
        r8[al] = memory[ds*16 + si + 3];
        if (r8s[al] <= signed8(0x9c)) {
            pc = 0x1167a;
            break;
        }
        memory[ds*16 + si + 3] -= 0x04;
    case 0x1167a:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        push(r16[ax]);
        yield* sub_107fd();
        si = pop();
        if (r8s[al] < memorys[ds*16 + si + 3]) {
            pc = 0x11691;
            break;
        }
        yield* sub_12092();
        return;
    case 0x11691:
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x11699;
            break;
        }
        return;
    case 0x11699:
        r16[ax] = memory16get(ds, si + 5);
        r16[ax] -= memory16get(ds, 0x1b8f);
        if (r16s[ax] >= 0) {
            pc = 0x116a4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x116a4:
        if (r16[ax] >= 0x000c)
            return;
        r16[ax] = memory16get(ds, si + 7);
        r16[ax] -= memory16get(ds, 0x1b91);
        if (r16s[ax] >= 0) {
            pc = 0x116b4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x116b4:
        if (r16[ax] >= 0x0008)
            return;
        r8[al] = memory[ds*16 + si + 3];
        r8[al] -= memory[ds*16 + 0x1b8d];
        if (r8s[al] >= 0) {
            pc = 0x116c4;
            break;
        }
        r8[al] = -r8[al];
    case 0x116c4:
        if (r8[al] >= 0x10)
            return;
        memory16set(ds, 0x9544, memory16get(ds, 0x9544) - 0x0001);
        yield* sub_12092();
        r8[al] = 0x04;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_116d6() {
    memory[ds*16 + si + 4] -= 1;
    if (memorys[ds*16 + si + 4] >= 0)
        return;
    memory[ds*16 + si] = 0x00;
}
function* sub_116df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si + 4];
        memory[ds*16 + si + 4] += 1;
        if (r8[al] < 0x04) {
            pc = 0x116ed;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x116ed:
        r8[al] <<= 1;
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[ax] = memory16get(ds, r16[bx] + 5182);
        memory16set(ds, si + 15, r16[ax]);
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_116fe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si + 22] += 1;
        r8[al] = memory[ds*16 + si + 22];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x05)) {
            pc = 0x11712;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11712:
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x12b5;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_1171f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si + 22] += 1;
        r8[al] = memory[ds*16 + si + 22];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x06)) {
            pc = 0x11733;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11733:
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x12f5;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_11740() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si + 22] += 1;
        r8[al] = memory[ds*16 + si + 22];
        r8[al] &= 0x07;
        if (r8s[al] < signed8(0x04)) {
            pc = 0x11762;
            break;
        }
        r8[al] = memory[ds*16 + si];
        if (!(r8[al] & 0x20)) {
            pc = 0x11759;
            break;
        }
        memory[ds*16 + 0x9517] = memory[ds*16 + 0x9517] & 0x7f;
        pc = 0x1175e;
        break;
    case 0x11759:
        memory[ds*16 + 0x9517] = memory[ds*16 + 0x9517] & 0xfe;
    case 0x1175e:
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11762:
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x133d;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_1176c() {
    memory[ds*16 + si + 22] += 1;
    r8[al] = memory[ds*16 + si + 22];
    r8[al] >>= 1;
    r8[al] &= 0x03;
    memory[ds*16 + si + 4] = r8[al];
    r16[bx] = 0x0e2b;
    yield* sub_12121();
    yield* sub_110c6();
}
function* sub_11783() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si + 22] += 1;
        r8[al] = memory[ds*16 + si + 22];
        r8[al] >>= 1;
        r8[al] &= 0x07;
        if (r8[al] < 0x06) {
            pc = 0x11797;
            break;
        }
        r8[al] = 0x00;
        memory[ds*16 + si + 22] = 0x00;
    case 0x11797:
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 3660];
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x0e52;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_117ac() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215b();
        if (r16[cx] == 0x0000) {
            pc = 0x117cc;
            break;
        }
        memory[ds*16 + si + 22] -= 1;
        if (memorys[ds*16 + si + 22] >= 0) {
            pc = 0x117c4;
            break;
        }
        memory[ds*16 + si + 22] = 0x08;
        memory[ds*16 + 0x9518] = 0x01;
        pc = 0x117c9;
        break;
    case 0x117c4:
        memory[ds*16 + 0x9518] = 0x00;
    case 0x117c9:
        yield* sub_11f0b();
    case 0x117cc:
        r16[bx] = 0x0e73;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_117d6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215b();
        if (r16[cx] == 0x0000) {
            pc = 0x117ea;
            break;
        }
        memory[ds*16 + si + 22] -= 1;
        if (memorys[ds*16 + si + 22] >= 0) {
            pc = 0x117ea;
            break;
        }
        memory[ds*16 + si + 22] = 0x12;
        yield* sub_12005();
    case 0x117ea:
        r16[bx] = 0x0e9c;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_117f4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110c6();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x117fe;
            break;
        }
        return;
    case 0x117fe:
        r8[al] = memory[ds*16 + si + 1];
        if (r8[al] != 0x02) {
            pc = 0x1180b;
            break;
        }
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x1180b:
        if (r8[al] != 0x00) {
            pc = 0x11815;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0004);
        pc = 0x11835;
        break;
    case 0x11815:
        if (r8[al] != 0x01) {
            pc = 0x11823;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0004);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x11823:
        if (r8[al] != 0x03) {
            pc = 0x11831;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0004);
        memory16set(ds, si + 7, memory16get(ds, si + 7) + 0x0003);
        pc = 0x11835;
        break;
    case 0x11831:
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0004);
    case 0x11835:
        memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
        r16[ax] = memory16get(ds, si + 5);
        if (r16s[ax] >= signed16(0x0008)) {
            pc = 0x11846;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x11846:
        if (r16s[ax] <= signed16(0x00f8)) {
            pc = 0x1184f;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x1184f:
        memory[ds*16 + si + 22] += 1;
        r8[bl] = memory[ds*16 + si + 22];
        if (r8[bl] < 0x10) {
            pc = 0x1185e;
            break;
        }
        yield* sub_12099();
        return;
    case 0x1185e:
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5223];
        memory[ds*16 + si + 3] += r8[al];
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x1186f;
            break;
        }
        return;
    case 0x1186f:
        r16[ax] = memory16get(ds, si + 5);
        r16[ax] -= memory16get(ds, 0x1b8f);
        if (r16s[ax] >= 0) {
            pc = 0x1187a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1187a:
        if (r16[ax] >= 0x000e)
            return;
        r16[ax] = memory16get(ds, si + 7);
        r16[ax] -= memory16get(ds, 0x1b91);
        if (r16s[ax] >= 0) {
            pc = 0x1188a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1188a:
        if (r16[ax] >= 0x000a)
            return;
        r8[al] = memory[ds*16 + si + 3];
        r8[al] -= memory[ds*16 + 0x1b8d];
        if (r8s[al] >= 0) {
            pc = 0x1189a;
            break;
        }
        r8[al] = -r8[al];
    case 0x1189a:
        if (r8[al] >= 0x10)
            return;
        memory16set(ds, 0x9544, memory16get(ds, 0x9544) - 0x000a);
        r8[al] = 0x05;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_118a9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1215b();
        if (r16[cx] == 0x0000) {
            pc = 0x118bd;
            break;
        }
        memory[ds*16 + si + 22] -= 1;
        if (memorys[ds*16 + si + 22] >= 0) {
            pc = 0x118bd;
            break;
        }
        memory[ds*16 + si + 22] = 0x28;
        yield* sub_11fba();
    case 0x118bd:
        r16[bx] = 0x0ec5;
        yield* sub_12121();
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_118c7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x952e];
        r8[al] &= memory[ds*16 + 0x952f];
        r8[al] &= memory[ds*16 + 0x9530];
        r8[al] &= memory[ds*16 + 0x9531];
        r8[al] &= memory[ds*16 + 0x9532];
        r8[al] &= memory[ds*16 + 0x9533];
        if (r8[al] != 0) {
            pc = 0x118e4;
            break;
        }
        yield* sub_110c6();
        return;
    case 0x118e4:
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x118f1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x118f1:
        r16[cx] = memory16get(ds, 0x1b91);
        r16[cx] -= 0x0008;
        r16[cx] -= memory16get(ds, si + 7);
        if (r16s[cx] >= 0) {
            pc = 0x118ff;
            break;
        }
        r16[cx] = -r16[cx];
    case 0x118ff:
        r8[bl] = memory[ds*16 + si + 4];
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
        memory[ds*16 + si + 4] += 1;
    case 0x11913:
        pc = 0x1191d;
        break;
    case 0x11915:
        if (r8[bl] == 0x00) {
            pc = 0x1191d;
            break;
        }
        memory[ds*16 + si + 4] -= 1;
    case 0x1191d:
        push(r16[bx]);
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5251);
        memory16set(ds, si + 15, r16[ax]);
        r16[bx] = pop();
        if (r8[bl] < 0x02) {
            pc = 0x1196b;
            break;
        }
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
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
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) + 1);
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
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) - 1);
    case 0x11952:
        if (r8[bl] != 0x08) {
            pc = 0x1196b;
            break;
        }
        if (r16[cx] > 0x0008) {
            pc = 0x1196b;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x1196b;
            break;
        }
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] == 0x11) {
            pc = 0x1196b;
            break;
        }
        yield* sub_1196f();
    case 0x1196b:
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_1196f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x1b8e];
        if (r8[al] != 0x00) {
            pc = 0x11982;
            break;
        }
        memory[ds*16 + 0x951d] = 0xf0;
        memory[ds*16 + 0x94ff] = 0x01;
        return;
    case 0x11982:
        push(si);
        memory[ds*16 + 0x1b8e] = 0x00;
        si = 0x1b8a;
        r16[bx] = 0x0d49;
        yield* sub_12121();
        si = pop();
        return;
    } while (1);
}
function* sub_11993() {
    yield* sub_11a04();
    r8[al] = memory[ds*16 + 0x94ff];
    if (r8[al] != 0x01)
        return;
    r8[al] = memory[ds*16 + 0x9501];
    r8[bl] = r8[al];
    r8[al] <<= 1;
    r8[bl] += r8[al];
    r8[bl] += memory[ds*16 + 0x9502];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 5269);
    r8[bh] = r8[ah];
    r16[ax] &= 0x03ff;
    memory16set(ds, 0x950c, r16[ax]);
    r8[bh] &= 0xc0;
    memory[ds*16 + 0x951d] = r8[bh];
}
function* sub_119c2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_11a04();
        r8[al] = memory[ds*16 + 0x94ff];
        if (r8[al] != 0x01)
            return;
        r8[al] = memory[ds*16 + 0x9501];
        r8[bl] = r8[al];
        r8[al] <<= 1;
        r8[bl] += r8[al];
        r8[bl] += memory[ds*16 + 0x9502];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5317);
        r8[bh] = r8[ah];
        r16[ax] &= 0x03ff;
        memory16set(ds, 0x950c, r16[ax]);
        r8[bh] &= 0xc0;
        memory[ds*16 + 0x951d] = r8[bh];
        memory[ds*16 + 0x950e] = 0x01;
        r8[al] = memory[ds*16 + 0x9502];
        r8[al]++;
        if (r8[al] <= 0x02) {
            pc = 0x11a00;
            break;
        }
        r8[al] = 0x00;
    case 0x11a00:
        memory[ds*16 + 0x9502] = r8[al];
        return;
    } while (1);
}
function* sub_11a04() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11a11;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11a11:
        r16[cx] = memory16get(ds, 0x1b91);
        r16[cx] -= memory16get(ds, si + 7);
        if (r16s[cx] >= 0) {
            pc = 0x11a1c;
            break;
        }
        r16[cx] = -r16[cx];
    case 0x11a1c:
        r8[bl] = memory[ds*16 + si + 4];
        r8[bl] >>= 1;
        r16[ax] += r16[cx];
        if (r16[ax] > 0x0040) {
            pc = 0x11a32;
            break;
        }
        if (r8[bl] == 0x06) {
            pc = 0x11a30;
            break;
        }
        memory[ds*16 + si + 4] += 1;
    case 0x11a30:
        pc = 0x11a3a;
        break;
    case 0x11a32:
        if (r8[bl] == 0x00) {
            pc = 0x11a3a;
            break;
        }
        memory[ds*16 + si + 4] -= 1;
    case 0x11a3a:
        if (r8[bl] != 0x06) {
            pc = 0x11a45;
            break;
        }
        memory[ds*16 + si + 2] = 0x00;
        pc = 0x11a56;
        break;
    case 0x11a45:
        push(r16[bx]);
        memory[ds*16 + si + 2] = 0x07;
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5239);
        memory16set(ds, si + 15, r16[ax]);
        r16[bx] = pop();
    case 0x11a56:
        if (r8[bl] < 0x01) {
            pc = 0x11a9a;
            break;
        }
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11a73;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] > 0x0018) {
            pc = 0x11a71;
            break;
        }
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) + 1);
    case 0x11a71:
        pc = 0x11a7e;
        break;
    case 0x11a73:
        if (r16[ax] == 0) {
            pc = 0x11a7e;
            break;
        }
        if (r16[ax] > 0x0018) {
            pc = 0x11a7e;
            break;
        }
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) - 1);
    case 0x11a7e:
        if (r16[cx] > 0x0008) {
            pc = 0x11a9a;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x11a9a;
            break;
        }
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] == 0x11) {
            pc = 0x11a9a;
            break;
        }
        r16[ax] = memory16get(ds, 0x1b8f);
        memory16set(ds, 0x950a, r16[ax]);
        memory[ds*16 + 0x94ff] = 0x01;
    case 0x11a9a:
        yield* sub_110c6();
        return;
    } while (1);
}
function* sub_11a9e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110c6();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x11aa8;
            break;
        }
        return;
    case 0x11aa8:
        r16[bx] = memory16get(ds, 0x1b91);
        r16[bx] -= memory16get(ds, si + 7);
        if (r16s[bx] >= 0) {
            pc = 0x11abb;
            break;
        }
        if (r16s[bx] >= signed16(0xfff0)) {
            pc = 0x11aba;
            break;
        }
        memory[ds*16 + si + 2] = 0x01;
    case 0x11aba:
        return;
    case 0x11abb:
        if (r16s[bx] <= signed16(0x0020)) {
            pc = 0x11ac1;
            break;
        }
        return;
    case 0x11ac1:
        r16[ax] = memory16get(ds, 0x1b8f);
        r16[ax] -= memory16get(ds, si + 5);
        r16[ax] -= 0x000c;
        if (r16s[ax] >= 0) {
            pc = 0x11ad9;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] >= 0x0018) {
            pc = 0x11ad7;
            break;
        }
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) + 1);
    case 0x11ad7:
        pc = 0x11ae7;
        break;
    case 0x11ad9:
        if (r16[ax] >= 0x0018) {
            pc = 0x11ae7;
            break;
        }
        if (r16[ax] == 0x0000) {
            pc = 0x11ae7;
            break;
        }
        memory16set(ds, 0x1b8f, memory16get(ds, 0x1b8f) - 1);
    case 0x11ae7:
        if (r16[bx] <= 0x0008) {
            pc = 0x11aed;
            break;
        }
        return;
    case 0x11aed:
        if (r16[ax] > 0x0002) {
            pc = 0x11af8;
            break;
        }
        memory16set(ds, 0x9538, memory16get(ds, 0x9538) + 1);
        return;
    case 0x11af8:
        if (r16[ax] >= 0x0024)
            return;
        memory16set(ds, 0x9542, 0x0000);
        r8[al] = 0x06;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_11b09() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_110c6();
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0x00) {
            pc = 0x11b13;
            break;
        }
        return;
    case 0x11b13:
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x11b1b;
            break;
        }
        return;
    case 0x11b1b:
        r16[ax] = memory16get(ds, si + 5);
        r16[ax] -= memory16get(ds, 0x1b8f);
        if (r16s[ax] >= 0) {
            pc = 0x11b26;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11b26:
        if (r16[ax] >= 0x0012)
            return;
        r16[ax] = memory16get(ds, si + 7);
        r16[ax] -= memory16get(ds, 0x1b91);
        if (r16s[ax] >= 0) {
            pc = 0x11b36;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x11b36:
        if (r16[ax] >= 0x0010)
            return;
        memory[ds*16 + si] = 0x00;
        r8[al] = memory[ds*16 + si + 1];
        yield* sub_12b28();
        r8[al] = 0x0a;
        yield* sub_13840();
        return;
    } while (1);
}
function* sub_11b4a() {
    memory16set(ds, si + 7, memory16get(ds, si + 7) - 0x0002);
    memory16set(ds, si + 7, memory16get(ds, si + 7) & 0x03ff);
    yield* sub_110a0();
}
function* sub_11b57() {
    r16[ax] = memory16get(ds, 0x1b8f);
    push(r16[ax]);
    r16[ax] = memory16get(ds, 0x9528);
    r16[ax] += 0x0070;
    r16[ax] &= 0x03ff;
    memory16set(ds, 0x1b91, r16[ax]);
    push(r16[ax]);
    yield* sub_107fd();
    memory[ds*16 + 0x1b8d] = r8[al];
    memory[ds*16 + 0x1b9e] = r8[cl];
    memory[ds*16 + 0x1b8e] = r8[bl];
    si = 0x1b8a;
    r16[bx] = 0x0d49;
    yield* sub_12121();
}
function* sub_11b80() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x952a);
        r16[ax] = memory16get(ds, 0x953a);
        if (r16s[ax] > signed16(0x0000)) {
            pc = 0x11b91;
            break;
        }
        r16[ax] = 0x0008;
        pc = 0x11b94;
        break;
    case 0x11b91:
        r16[ax] = memory16get(ds, 0x954c);
    case 0x11b94:
        if (!(r8[al] & 0x04)) {
            pc = 0x11ba3;
            break;
        }
        r16[bx]++;
        if (r16s[bx] <= signed16(0x0040)) {
            pc = 0x11ba1;
            break;
        }
        r16[bx] = 0x0040;
    case 0x11ba1:
        pc = 0x11bb4;
        break;
    case 0x11ba3:
        if (!(r8[al] & 0x08)) {
            pc = 0x11bb4;
            break;
        }
        r16[bx] -= 0x0002;
        if (r16s[bx] >= memory16gets(ds, 0x94fc)) {
            pc = 0x11bb4;
            break;
        }
        r16[bx] = memory16get(ds, 0x94fc);
    case 0x11bb4:
        memory16set(ds, 0x952a, r16[bx]);
        return;
    } while (1);
}
function* sub_11bb9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x952a);
        r16[bx] += 0x000f;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] = r16[bx];
        r16[ax]--;
        r16[bx] >>= 1;
        r16[ax] += memory16get(ds, 0x950f);
        if (r16[ax] <= 0x008b) {
            pc = 0x11bdd;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds, 0x953c, 0xffff);
    case 0x11bdd:
        memory16set(ds, 0x950f, r16[ax]);
        r16[ax] = memory16get(ds, 0x9528);
        r16[ax] -= r16[bx];
        r16[ax] &= 0x03ff;
        memory16set(ds, 0x9528, r16[ax]);
        r16[ax] = memory16get(ds, 0x9528);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] -= 0x0003;
        r16[ax] &= 0x003f;
        if (r16[ax] == memory16get(ds, 0x9507))
            return;
        memory16set(ds, 0x9507, r16[ax]);
        push(r16[ax]);
        yield* sub_108ba();
        return;
    } while (1);
}
function* sub_11c0a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 6 - 2);
        r16[cx] = memory16get(ss, bp + 4 - 2);
        si = 0x1b8a;
    case 0x11c16:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80) {
            pc = 0x11c2f;
            break;
        }
        if (!(r8[al] & 0x08)) {
            pc = 0x11c2a;
            break;
        }
        if (r8[cl] != memory[ds*16 + si + 20]) {
            pc = 0x11c2a;
            break;
        }
        if (r8[bl] == memory[ds*16 + si + 19]) {
            pc = 0x11c2f;
            break;
        }
    case 0x11c2a:
        si += 0x0017;
        pc = 0x11c16;
        break;
    case 0x11c2f:
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_11c33() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x1b9c];
        if (r8[al] != 0x11) {
            pc = 0x11c3b;
            break;
        }
        return;
    case 0x11c3b:
        r8[al] = 0x0c;
        yield* sub_13840();
        si = 0x1b8a;
        yield* sub_120f0();
        memory[ds*16 + 0x1b9c] = 0x11;
        memory[ds*16 + 0x1b8c] = 0x00;
        memory[ds*16 + 0x9514] = 0x00;
        return;
    } while (1);
}
function* sub_11c56() {
    r16[ax] = -r16[ax];
    memory16set(ds, 0x9544, r16[ax]);
    push(r16[ax]);
    r8[al] = 0x06;
    yield* sub_13840();
    r16[ax] = pop();
    r16[ax] = r16[bx];
    push(r16[ax]);
    r8[al] = memory[ds*16 + 0x1b9e];
    r8[ah] = 0x00;
    push(r16[ax]);
    yield* sub_11c0a();
    r8[al] = memory[ds*16 + si];
    if (r8[al] & 0x80)
        return;
    yield* sub_120db();
}
function* sub_11c78() {
    r16[ax] = memory16get(ds, 0x9437);
    memory16set(ds, 0x9439, r16[ax]);
    r16[ax] = memory16get(ds, 0x9435);
    memory16set(ds, 0x9437, r16[ax]);
    r16[ax] = memory16get(ds, 0x9433);
    memory16set(ds, 0x9435, r16[ax]);
    r16[ax] = memory16get(ds, 0x1b8f);
    memory16set(ds, 0x9433, r16[ax]);
    r16[ax] = memory16get(ds, 0x943f);
    memory16set(ds, 0x9441, r16[ax]);
    r16[ax] = memory16get(ds, 0x943d);
    memory16set(ds, 0x943f, r16[ax]);
    r16[ax] = memory16get(ds, 0x943b);
    memory16set(ds, 0x943d, r16[ax]);
    r16[ax] = memory16get(ds, 0x1b91);
    memory16set(ds, 0x943b, r16[ax]);
    r8[al] = memory[ds*16 + 0x9445];
    memory[ds*16 + 0x9446] = r8[al];
    r8[al] = memory[ds*16 + 0x9444];
    memory[ds*16 + 0x9445] = r8[al];
    r8[al] = memory[ds*16 + 0x9443];
    memory[ds*16 + 0x9444] = r8[al];
    r8[al] = memory[ds*16 + 0x1b8e];
    memory[ds*16 + 0x9443] = r8[al];
    r8[al] = memory[ds*16 + 0x9449];
    memory[ds*16 + 0x944a] = r8[al];
    r8[al] = memory[ds*16 + 0x9448];
    memory[ds*16 + 0x9449] = r8[al];
    r8[al] = memory[ds*16 + 0x9447];
    memory[ds*16 + 0x9448] = r8[al];
    r8[al] = memory[ds*16 + 0x1b8d];
    memory[ds*16 + 0x9447] = r8[al];
}
function* sub_11cd9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9439);
        memory16set(ds, si + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x9441);
        r16[ax] += 0x0006;
        r16[ax] &= 0x03ff;
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x9446];
        memory[ds*16 + si + 4] = r8[al];
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 3513];
        r8[al] = memory[ds*16 + 0x944a];
        r8[al] += 0x06;
        memory[ds*16 + si + 3] = r8[al];
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x20) {
            pc = 0x11d10;
            break;
        }
        memory16set(ds, si + 5, memory16get(ds, si + 5) - 0x0008);
        memory[ds*16 + si + 3] += r8[cl];
        pc = 0x11d17;
        break;
    case 0x11d10:
        memory16set(ds, si + 5, memory16get(ds, si + 5) + 0x0008);
        memory[ds*16 + si + 3] -= r8[cl];
    case 0x11d17:
        r16[bx] = 0x0dda;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_11d1e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x135e;
        memory[ds*16 + si] = memory[ds*16 + si] & 0xdf;
        r8[bl] = memory[ds*16 + 0x1b8e];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5021];
        memory[ds*16 + si + 4] = r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 4981];
        cbw();
        r16[ax] += memory16get(ds, 0x1b8f);
        memory16set(ds, si + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x1b91);
        r16[ax] -= 0x0004;
        r16[ax] &= 0x03ff;
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x1b8d];
        r8[al] += memory[ds*16 + r16[bx] + 5001];
        memory[ds*16 + si + 3] = r8[al];
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5031];
        memory[ds*16 + si + 10] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5034);
        memory16set(ds, si + 15, r16[ax]);
        yield* sub_10b58();
        si = 0x0ff7;
        r16[ax] = memory16get(ds, 0x1363);
        memory16set(ds, si + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x1365);
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x1361];
        memory[ds*16 + si + 3] = r8[al];
        memory[ds*16 + 0x9516] += 1;
        r8[bl] = memory[ds*16 + 0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16 + r16[bx] + 4071];
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x100e;
        yield* sub_12121();
        yield* sub_10b58();
        si = 0x135e;
        memory[ds*16 + si] = memory[ds*16 + si] | 0x20;
        r8[bl] = memory[ds*16 + 0x1b8e];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 4991];
        cbw();
        r16[ax] += memory16get(ds, 0x1b8f);
        memory16set(ds, si + 5, r16[ax]);
        r8[al] = memory[ds*16 + 0x1b8d];
        r8[al] += memory[ds*16 + r16[bx] + 5011];
        memory[ds*16 + si + 3] = r8[al];
        yield* sub_10b58();
        si = 0x0ff7;
        r16[ax] = memory16get(ds, 0x1363);
        memory16set(ds, si + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x1365);
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x1361];
        memory[ds*16 + si + 3] = r8[al];
        yield* sub_10b58();
        r16[ax] = memory16get(ds, 0x9511);
        r16[ax] += r16[bx];
        if (r16[ax] <= 0x0010) {
            pc = 0x11deb;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds, 0x9540, 0xffff);
    case 0x11deb:
        memory16set(ds, 0x9511, r16[ax]);
        return;
    } while (1);
}
function* sub_11def() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x9516] += 1;
        r8[bl] = memory[ds*16 + 0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16 + r16[bx] + 4071];
        memory[ds*16 + 0x0ffb] = r8[al];
        r8[al] = memory[ds*16 + si + 1];
        if (r8[al] != 0x00) {
            pc = 0x11e2e;
            break;
        }
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5069];
        r16[ax] = 0xfffd;
        r16[bx] = 0x0008;
        yield* sub_11e7d();
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5079];
        r16[ax] = 0x0003;
        r16[bx] = 0x0008;
        yield* sub_11e7d();
        return;
    case 0x11e2e:
        if (r8[al] != 0x01) {
            pc = 0x11e46;
            break;
        }
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5089];
        r16[ax] = 0x0000;
        r16[bx] = 0x0008;
        yield* sub_11e7d();
        return;
    case 0x11e46:
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5099];
        r16[ax] = 0xfff9;
        r16[bx] = 0x0008;
        yield* sub_11e7d();
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5109];
        r16[ax] = 0x0000;
        r16[bx] = 0x000b;
        yield* sub_11e7d();
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 5119];
        r16[ax] = 0x0007;
        r16[bx] = 0x0008;
        yield* sub_11e7d();
        return;
    } while (1);
}
function* sub_11e7d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        di = 0x0ff7;
        r16[ax] += memory16get(ds, si + 5);
        memory16set(ds, di + 5, r16[ax]);
        r16[bx] += memory16get(ds, si + 7);
        r16[bx] &= 0x03ff;
        memory16set(ds, di + 7, r16[bx]);
        r8[cl] += memory[ds*16 + si + 3];
        memory[ds*16 + di + 3] = r8[cl];
        si = di;
        r16[bx] = 0x1039;
        yield* sub_12121();
        yield* sub_10b58();
        if (si == 0x0000) {
            pc = 0x11eb0;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11eb0;
            break;
        }
        yield* sub_116d6();
    case 0x11eb0:
        si = pop();
        r8[al] = memory[ds*16 + 0x9518];
        if (r8[al] != 0x00) {
            pc = 0x11eb9;
            break;
        }
        return;
    case 0x11eb9:
        push(si);
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        si = 0x13b0;
        r8[al] = memory[ds*16 + r16[bx] + 5021];
        memory[ds*16 + si + 4] = r8[al];
        r16[ax] = memory16get(ds, 0x0ffc);
        memory16set(ds, si + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x0ffe);
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x0ffa];
        memory[ds*16 + si + 3] = r8[al];
        memory[ds*16 + si + 1] = 0x02;
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5031];
        memory[ds*16 + si + 10] = r8[al];
        memory[ds*16 + si + 9] = 0x04;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5063);
        memory16set(ds, si + 15, r16[ax]);
        yield* sub_10b58();
        if (si == 0x0000) {
            pc = 0x11f09;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11f09;
            break;
        }
        yield* sub_115fc();
    case 0x11f09:
        si = pop();
        return;
    } while (1);
}
function* sub_11f0b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        memory[ds*16 + 0x9516] += 1;
        r8[bl] = memory[ds*16 + 0x9516];
        r16[bx] &= 0x000f;
        r8[al] = memory[ds*16 + r16[bx] + 4071];
        memory[ds*16 + 0x0ffb] = r8[al];
        di = 0x0ff7;
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5129];
        cbw();
        r16[ax] += memory16get(ds, si + 5);
        memory16set(ds, di + 5, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 5134];
        cbw();
        r16[ax] += memory16get(ds, si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds, di + 7, r16[ax]);
        r8[al] = memory[ds*16 + si + 3];
        r8[al] += 0x04;
        memory[ds*16 + di + 3] = r8[al];
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 4143);
        si = di;
        yield* sub_12121();
        yield* sub_10b58();
        if (si == 0x0000) {
            pc = 0x11f63;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11f63;
            break;
        }
        yield* sub_116d6();
    case 0x11f63:
        si = pop();
        r8[al] = memory[ds*16 + 0x9518];
        if (r8[al] != 0x00) {
            pc = 0x11f6c;
            break;
        }
        return;
    case 0x11f6c:
        push(si);
        di = 0x13b0;
        r8[bl] = memory[ds*16 + si + 4];
        r8[bh] = 0x00;
        memory[ds*16 + di + 1] = r8[bl];
        r16[ax] = memory16get(ds, 0x0ffc);
        memory16set(ds, di + 5, r16[ax]);
        r16[ax] = memory16get(ds, 0x0ffe);
        memory16set(ds, di + 7, r16[ax]);
        r8[al] = memory[ds*16 + 0x0ffa];
        memory[ds*16 + di + 3] = r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 5139];
        memory[ds*16 + di + 9] = r8[al];
        r8[al] = memory[ds*16 + r16[bx] + 5144];
        memory[ds*16 + di + 10] = r8[al];
        memory[ds*16 + di + 4] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5149);
        memory16set(ds, di + 15, r16[ax]);
        si = di;
        yield* sub_10b58();
        if (si == 0x0000) {
            pc = 0x11fb8;
            break;
        }
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] <= si) {
            pc = 0x11fb8;
            break;
        }
        yield* sub_115fc();
    case 0x11fb8:
        si = pop();
        return;
    } while (1);
}
function* sub_11fba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        di = 0x10e8;
        r8[bl] = memory[ds*16 + si + 4];
        memory[ds*16 + di + 1] = r8[bl];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 4318];
        cbw();
        r16[ax] += memory16get(ds, si + 5);
        memory16set(ds, di + 5, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 4323];
        cbw();
        r16[ax] += memory16get(ds, si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds, di + 7, r16[ax]);
        r8[al] = memory[ds*16 + si + 3];
        r8[al] += 0x08;
        memory[ds*16 + di + 3] = r8[al];
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 4351);
        si = di;
        yield* sub_12121();
        yield* sub_10b58();
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
        r8[bl] = memory[ds*16 + si + 4];
        memory[ds*16 + di + 1] = r8[bl];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 5213];
        cbw();
        r16[ax] += memory16get(ds, si + 5);
        memory16set(ds, di + 5, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 5218];
        cbw();
        r16[ax] += memory16get(ds, si + 7);
        r16[ax] &= 0x03ff;
        memory16set(ds, di + 7, r16[ax]);
        r8[al] = memory[ds*16 + si + 3];
        r8[al] += 0x08;
        memory[ds*16 + di + 3] = r8[al];
        si = di;
        yield* sub_10b58();
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
        yield* sub_117f4();
    case 0x12045:
        si = pop();
        return;
    } while (1);
}
function* sub_12047() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si];
        r8[bl] = memory[ds*16 + 0x9517];
        if (!(r8[al] & 0x20)) {
            pc = 0x12072;
            break;
        }
        if (r8[bl] & 0x80) {
            pc = 0x1206d;
            break;
        }
        memory[ds*16 + 0x9517] = memory[ds*16 + 0x9517] | 0x80;
        memory[ds*16 + 0x1326] = memory[ds*16 + 0x1326] | 0x20;
        di = 0x1326;
        yield* sub_120a0();
        r8[al] = 0x03;
        yield* sub_13840();
        pc = 0x12070;
        break;
    case 0x1206d:
        memory[ds*16 + si] = 0x00;
    case 0x12070:
        return;
    case 0x12072:
        if (r8[bl] & 0x01) {
            pc = 0x1208e;
            break;
        }
        memory[ds*16 + 0x9517] = memory[ds*16 + 0x9517] | 0x01;
        memory[ds*16 + 0x1326] = memory[ds*16 + 0x1326] & 0xdf;
        di = 0x1326;
        yield* sub_120a0();
        r8[al] = 0x03;
        yield* sub_13840();
        return;
    case 0x1208e:
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_12092() {
    di = 0x1427;
    yield* sub_120a0();
}
function* sub_12099() {
    di = 0x12de;
    yield* sub_120a0();
}
function* sub_120a0() {
    r8[al] = memory[ds*16 + di];
    memory[ds*16 + si] = r8[al];
    r8[al] = memory[ds*16 + di + 2];
    memory[ds*16 + si + 2] = r8[al];
    r8[al] = memory[ds*16 + di + 22];
    memory[ds*16 + si + 22] = r8[al];
    r8[al] = memory[ds*16 + di + 4];
    memory[ds*16 + si + 4] = r8[al];
    r8[al] = memory[ds*16 + di + 9];
    memory[ds*16 + si + 9] = r8[al];
    r8[al] = memory[ds*16 + di + 10];
    memory[ds*16 + si + 10] = r8[al];
    r8[al] = memory[ds*16 + di + 11];
    memory[ds*16 + si + 11] = r8[al];
    r8[al] = memory[ds*16 + di + 12];
    memory[ds*16 + si + 12] = r8[al];
    r16[ax] = memory16get(ds, di + 15);
    memory16set(ds, si + 15, r16[ax]);
    r8[al] = memory[ds*16 + di + 18];
    memory[ds*16 + si + 18] = r8[al];
}
function* sub_120db() {
    yield* sub_12676();
    yield* sub_120f0();
    push(si);
    r8[al] = memory[ds*16 + si + 19];
    r8[ah] = 0x00;
    push(r16[ax]);
    r8[al] = memory[ds*16 + si + 20];
    push(r16[ax]);
    yield* sub_109b5();
}
function* sub_120f0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r16[ax] = memory16get(ds, si + 5);
        memory16set(ds, 0x12a3, r16[ax]);
        r16[ax] = memory16get(ds, si + 7);
        memory16set(ds, 0x12a5, r16[ax]);
        r8[al] = memory[ds*16 + si + 3];
        memory[ds*16 + 0x12a1] = r8[al];
        r8[al] = memory[ds*16 + si];
        if (!(r8[al] & 0x10)) {
            pc = 0x12119;
            break;
        }
        memory16set(ds, 0x12a3, memory16get(ds, 0x12a3) - 0x000c);
        memory16set(ds, 0x12a5, memory16get(ds, 0x12a5) - 0x0008);
        memory16set(ds, 0x12a5, memory16get(ds, 0x12a5) & 0x03ff);
    case 0x12119:
        si = 0x129e;
        yield* sub_10b58();
        si = pop();
        return;
    } while (1);
}
function* sub_12121() {
    r8[cl] = memory[ds*16 + r16[bx]];
    r8[ch] = 0x00;
    r16[bx]++;
    r8[al] = memory[ds*16 + si + 4];
    r8[ah] = 0x00;
    di = r16[ax];
    r8[al] = memory[ds*16 + r16[bx] + di];
    memory[ds*16 + si + 9] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16 + r16[bx] + di];
    memory[ds*16 + si + 10] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16 + r16[bx] + di];
    memory[ds*16 + si + 11] = r8[al];
    r16[bx] += r16[cx];
    r8[al] = memory[ds*16 + r16[bx] + di];
    memory[ds*16 + si + 12] = r8[al];
    r16[bx] += r16[cx];
    di <<= 1;
    di <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + di);
    memory16set(ds, si + 13, r16[ax]);
    r16[bx] += 0x0002;
    r16[ax] = memory16get(ds, r16[bx] + di);
    memory16set(ds, si + 15, r16[ax]);
}
function* sub_1215b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0001;
        r16[ax] = memory16get(ds, 0x1b91);
        r16[ax] -= memory16get(ds, si + 7);
        if (r16s[ax] <= signed16(0x008c)) {
            pc = 0x12171;
            break;
        }
        memory[ds*16 + si + 4] = 0x02;
        r16[cx] = 0x0000;
        return;
    case 0x12171:
        if (r16s[ax] >= signed16(0xfff0)) {
            pc = 0x121a0;
            break;
        }
        r8[ah] = memory[ds*16 + si + 4];
        r8[al] = memory[ds*16 + si];
        if (!(r8[al] & 0x20)) {
            pc = 0x1218d;
            break;
        }
        r8[ah]++;
        if (r8s[ah] <= signed8(0x04)) {
            pc = 0x1218b;
            break;
        }
        memory[ds*16 + si] = memory[ds*16 + si] & 0xdf;
        r8[ah] = 0x04;
    case 0x1218b:
        pc = 0x12199;
        break;
    case 0x1218d:
        r8[ah]--;
        if (r8s[ah] >= signed8(0x00)) {
            pc = 0x12199;
            break;
        }
        memory[ds*16 + si] = memory[ds*16 + si] | 0x20;
        r8[ah] = 0x00;
    case 0x12199:
        memory[ds*16 + si + 4] = r8[ah];
        r16[cx] = 0x0000;
        return;
    case 0x121a0:
        r16[bx] = memory16get(ds, 0x1b8f);
        r16[bx] -= memory16get(ds, si + 5);
        if (r16s[bx] >= 0) {
            pc = 0x121c2;
            break;
        }
        if (r16s[bx] <= signed16(0xffe0)) {
            pc = 0x121b3;
            break;
        }
        memory[ds*16 + si + 4] = 0x02;
        return;
    case 0x121b3:
        if (r16s[ax] <= signed16(0x0020)) {
            pc = 0x121bd;
            break;
        }
        memory[ds*16 + si + 4] = 0x01;
        return;
    case 0x121bd:
        memory[ds*16 + si + 4] = 0x00;
        return;
    case 0x121c2:
        if (r16s[bx] >= signed16(0x0020)) {
            pc = 0x121cc;
            break;
        }
        memory[ds*16 + si + 4] = 0x02;
        return;
    case 0x121cc:
        if (r16s[ax] <= signed16(0x0020)) {
            pc = 0x121d6;
            break;
        }
        memory[ds*16 + si + 4] = 0x03;
        return;
    case 0x121d6:
        memory[ds*16 + si + 4] = 0x04;
        return;
    } while (1);
}
function* sub_121dc() {
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
    yield* sub_12cea();
    yield* sub_12200();
    yield* sub_1264a();
    yield* sub_12a7f();
    yield* sub_122b1();
}
function* sub_12200() {
    yield* sub_1250b();
    yield* sub_12553();
    yield* sub_1259b();
    yield* sub_1237c();
}
function* sub_1220d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x944c] += 1;
        r8[al] = memory[ds*16 + 0x944c];
        r8[al] &= 0x03;
        if (r8[al] != 0) {
            pc = 0x12228;
            break;
        }
        r16[ax] = 0x0000;
        push(r16[ax]);
        push(r16[ax]);
        push(r16[ax]);
        r8[al] = memory[ds*16 + 0x94fe];
        push(r16[ax]);
        yield* sub_1269e();
        yield* sub_12714();
    case 0x12228:
        r16[ax] = memory16get(ds, 0x953c);
        if (r16[ax] == 0x0000) {
            pc = 0x12246;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x12237;
            break;
        }
        yield* sub_1252f();
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
        memory16set(ds, 0x953c, 0x0000);
    case 0x12246:
        r16[ax] = memory16get(ds, 0x9540);
        if (r16[ax] == 0x0000) {
            pc = 0x12264;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x12255;
            break;
        }
        yield* sub_12577();
        pc = 0x1225e;
        break;
    case 0x12255:
        r16[cx] = r16[ax];
    case 0x12257:
        push(r16[cx]);
        yield* sub_1258a();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12257;
            break;
        }
    case 0x1225e:
        memory16set(ds, 0x9540, 0x0000);
    case 0x12264:
        r16[ax] = memory16get(ds, 0x9544);
        if (r16[ax] == 0x0000) {
            pc = 0x1228a;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x1227b;
            break;
        }
        r16[ax] = -r16[ax];
        r16[cx] = r16[ax];
    case 0x12272:
        push(r16[cx]);
        yield* sub_125bf();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x12272;
            break;
        }
        pc = 0x12284;
        break;
    case 0x1227b:
        r16[cx] = r16[ax];
    case 0x1227d:
        push(r16[cx]);
        yield* sub_125d2();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1227d;
            break;
        }
    case 0x12284:
        memory16set(ds, 0x9544, 0x0000);
    case 0x1228a:
        r16[ax] = memory16get(ds, 0x9538);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0) {
            pc = 0x122a1;
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
        pc = 0x122aa;
        break;
    case 0x122a1:
        r16[cx] = r16[ax];
    case 0x122a3:
        push(r16[cx]);
        yield* sub_1239b();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x122a3;
            break;
        }
    case 0x122aa:
        memory16set(ds, 0x9538, 0x0000);
        return;
    } while (1);
}
function* sub_122b1() {
    memory16set(ds, 0x9534, 0x0003);
    yield* sub_122e1();
    yield* sub_122f9();
    yield* sub_12311();
}
function* sub_122c1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x9534, memory16get(ds, 0x9534) + 1);
        r16[ax] = memory16get(ds, 0x9534);
        if (r16[ax] <= 0x0003) {
            pc = 0x122d4;
            break;
        }
        memory16set(ds, 0x9534, 0x0003);
        return;
    case 0x122d4:
        if (r16[ax] == 0x0003) {
            pc = 0x12311;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x122f9;
            break;
        }
        if (r16[ax] == 0x0001) {
            pc = 0x122e1;
            break;
        }
        return;
    case 0x122e1:
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
        yield* sub_12cea();
        return;
    case 0x122f9:
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
        yield* sub_12cea();
        return;
    case 0x12311:
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
        yield* sub_12cea();
        return;
    } while (1);
}
function* sub_122e1() {
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
    yield* sub_12cea();
}
function* sub_122f9() {
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
    yield* sub_12cea();
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
    yield* sub_12cea();
}
function* sub_12329() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x9534, memory16get(ds, 0x9534) - 1);
        r16[ax] = memory16get(ds, 0x9534);
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
        yield* sub_12d9a();
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
        yield* sub_12d9a();
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
        yield* sub_12d9a();
        return;
    } while (1);
}
function* sub_1237c() {
    memory16set(ds, 0x9536, 0x0006);
    memory16set(ds, 0x9538, 0x0000);
    yield* sub_123d4();
    yield* sub_123ec();
    yield* sub_12404();
    yield* sub_1241c();
    yield* sub_12434();
    yield* sub_1244c();
}
function* sub_1239b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x9536, memory16get(ds, 0x9536) + 1);
        r16[ax] = memory16get(ds, 0x9536);
        if (r16[ax] <= 0x0006) {
            pc = 0x123ae;
            break;
        }
        memory16set(ds, 0x9536, 0x0006);
        return;
    case 0x123ae:
        push(r16[ax]);
        r8[al] = 0x08;
        yield* sub_13840();
        r16[ax] = pop();
        if (r16[ax] == 0x0001) {
            pc = 0x123d4;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x123ec;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x12404;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x1241c;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x12434;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x1244c;
            break;
        }
        return;
    case 0x123d4:
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
        yield* sub_12cea();
        return;
    case 0x123ec:
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
        yield* sub_12cea();
        return;
    case 0x12404:
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
        yield* sub_12cea();
        return;
    case 0x1241c:
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
        yield* sub_12cea();
        return;
    case 0x12434:
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
        yield* sub_12cea();
        return;
    case 0x1244c:
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
        yield* sub_12cea();
        return;
    } while (1);
}
function* sub_123d4() {
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
    yield* sub_12cea();
}
function* sub_123ec() {
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
    yield* sub_12cea();
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
    yield* sub_12cea();
}
function* sub_1241c() {
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
    yield* sub_12cea();
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
    yield* sub_12cea();
}
function* sub_1244c() {
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
    yield* sub_12cea();
}
function* sub_12464() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9536);
        memory16set(ds, 0x9536, memory16get(ds, 0x9536) - 1);
        if (memory16gets(ds, 0x9536) >= 0) {
            pc = 0x12474;
            break;
        }
        memory16set(ds, 0x9536, 0x0000);
        return;
    case 0x12474:
        if (r16[ax] == 0x0001) {
            pc = 0x12493;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x124a7;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x124bb;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x124cf;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x124e3;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x124f7;
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
        yield* sub_12d9a();
        return;
    case 0x124a7:
        r16[ax] = 0x1b9b;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12d9a();
        return;
    case 0x124bb:
        r16[ax] = 0x1b9d;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12d9a();
        return;
    case 0x124cf:
        r16[ax] = 0x1b9f;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12d9a();
        return;
    case 0x124e3:
        r16[ax] = 0x1ba1;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12d9a();
        return;
    case 0x124f7:
        r16[ax] = 0x1ba3;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        yield* sub_12d9a();
        return;
    } while (1);
}
function* sub_1250b() {
    memory16set(ds, 0x953a, 0x002c);
    memory16set(ds, 0x953c, 0x0000);
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
    yield* sub_12cea();
}
function* sub_1252f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x953a);
        r16[ax]--;
        if (r16s[ax] >= 0) {
            pc = 0x12536;
            break;
        }
        return;
    case 0x12536:
        memory16set(ds, 0x953a, r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x1b88;
        push(r16[ax]);
        yield* sub_125e3();
        return;
    } while (1);
}
function* sub_12536() {
    memory16set(ds, 0x953a, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1b88;
    push(r16[ax]);
    yield* sub_125e3();
}
function* sub_12542() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x953a);
        if (r16[ax] < 0x002c) {
            pc = 0x1254b;
            break;
        }
        return;
    case 0x1254b:
        yield* sub_12536();
        memory16set(ds, 0x953a, memory16get(ds, 0x953a) + 1);
        return;
    } while (1);
}
function* sub_12553() {
    memory16set(ds, 0x953e, 0x0030);
    memory16set(ds, 0x9540, 0x0000);
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
    yield* sub_12cea();
}
function* sub_12577() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x953e);
        r16[ax]--;
        if (r16s[ax] >= 0) {
            pc = 0x1257e;
            break;
        }
        return;
    case 0x1257e:
        memory16set(ds, 0x953e, r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x1cc8;
        push(r16[ax]);
        yield* sub_125e3();
        return;
    } while (1);
}
function* sub_1257e() {
    memory16set(ds, 0x953e, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1cc8;
    push(r16[ax]);
    yield* sub_125e3();
}
function* sub_1258a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x953e);
        if (r16[ax] < 0x0030) {
            pc = 0x12593;
            break;
        }
        return;
    case 0x12593:
        yield* sub_1257e();
        memory16set(ds, 0x953e, memory16get(ds, 0x953e) + 1);
        return;
    } while (1);
}
function* sub_1259b() {
    memory16set(ds, 0x9542, 0x0038);
    memory16set(ds, 0x9544, 0x0000);
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
    yield* sub_12cea();
}
function* sub_125bf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9542);
        r16[ax]--;
        if (r16s[ax] >= 0) {
            pc = 0x125c6;
            break;
        }
        return;
    case 0x125c6:
        memory16set(ds, 0x9542, r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x1e08;
        push(r16[ax]);
        yield* sub_125e3();
        return;
    } while (1);
}
function* sub_125c6() {
    memory16set(ds, 0x9542, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x1e08;
    push(r16[ax]);
    yield* sub_125e3();
}
function* sub_125d2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9542);
        if (r16[ax] < 0x0038) {
            pc = 0x125db;
            break;
        }
        return;
    case 0x125db:
        yield* sub_125c6();
        memory16set(ds, 0x9542, memory16get(ds, 0x9542) + 1);
        return;
    } while (1);
}
function* sub_125e3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = memory16get(ss, bp + 6 - 2);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        di = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0805;
        out16(r16[dx], r16[ax]);
        r16[cx] = memory16get(ss, bp + 6 - 2);
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
    case 0x1261e:
        r8[al] = videoGet(es, di);
        if (r8[bl] & r8[al]) {
            pc = 0x1262d;
            break;
        }
        videoSet(es, di, r8[bl]);
        videoSet(es, di + 8192, r8[bl]);
    case 0x1262d:
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1261e;
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
        sp += 4;
        return;
    } while (1);
}
function* sub_1264a() {
    r8[al] = 0x00;
    memory[ds*16 + 0x94a9] = r8[al];
    memory[ds*16 + 0x94aa] = r8[al];
    memory[ds*16 + 0x94ab] = r8[al];
    memory[ds*16 + 0x94ac] = r8[al];
    memory[ds*16 + 0x94ad] = r8[al];
    memory[ds*16 + 0x94ae] = r8[al];
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
    yield* sub_1269e();
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
    yield* sub_1269e();
}
function* sub_1268a() {
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    r16[ax] = 0x0000;
    push(r16[ax]);
    yield* sub_1269e();
}
function* sub_1269e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r8[al] = memory[ds*16 + 0x94ae];
        r8[al] += memory[ss*16 + bp + 4 - 2];
        if (r8[al] <= 0x09) {
            pc = 0x126b1;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16 + 0x94ad] += 1;
    case 0x126b1:
        memory[ds*16 + 0x94ae] = r8[al];
        r8[al] = memory[ds*16 + 0x94ad];
        r8[al] += memory[ss*16 + bp + 6 - 2];
        if (r8[al] <= 0x09) {
            pc = 0x126c4;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16 + 0x94ac] += 1;
    case 0x126c4:
        memory[ds*16 + 0x94ad] = r8[al];
        r8[al] = memory[ds*16 + 0x94ac];
        r8[al] += memory[ss*16 + bp + 8 - 2];
        if (r8[al] <= 0x09) {
            pc = 0x126d7;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16 + 0x94ab] += 1;
    case 0x126d7:
        memory[ds*16 + 0x94ac] = r8[al];
        r8[al] = memory[ds*16 + 0x94ab];
        r8[al] += memory[ss*16 + bp + 10 - 2];
        if (r8[al] <= 0x09) {
            pc = 0x126ea;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16 + 0x94aa] += 1;
    case 0x126ea:
        memory[ds*16 + 0x94ab] = r8[al];
        r8[al] = memory[ds*16 + 0x94aa];
        if (r8[al] <= 0x09) {
            pc = 0x12701;
            break;
        }
        r8[al] -= 0x0a;
        memory[ds*16 + 0x94a9] += 1;
        push(r16[ax]);
        push(si);
        yield* sub_122c1();
        si = pop();
        r16[ax] = pop();
    case 0x12701:
        memory[ds*16 + 0x94aa] = r8[al];
        r8[al] = memory[ds*16 + 0x94a9];
        if (r8[al] <= 0x09) {
            pc = 0x1270d;
            break;
        }
        r8[al] -= 0x0a;
    case 0x1270d:
        memory[ds*16 + 0x94a9] = r8[al];
        bp = pop();
        sp += 8;
        return;
    } while (1);
}
function* sub_12714() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x944d] = 0x01;
        si = 0x94a9;
        r16[cx] = 0x0006;
        r16[dx] = 0x0000;
    case 0x12722:
        push(r16[cx]);
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x1272d;
            break;
        }
        memory[ds*16 + 0x944d] = 0x00;
    case 0x1272d:
        r8[cl] = memory[ds*16 + 0x944d];
        if (r8[cl] != 0x00) {
            pc = 0x1275e;
            break;
        }
        push(r16[dx]);
        push(si);
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5471);
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = memory16get(ds, r16[bx] + 5491);
        push(r16[ax]);
        r16[ax] = 0x0010;
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_12cea();
        si = pop();
        r16[dx] = pop();
        r16[dx] += 0x0002;
    case 0x1275e:
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
        memory[ds*16 + 0x9455] = 0x5f;
        r8[al] = 0x00;
        r16[cx] = 0x0007;
        si = 0x94da;
    case 0x1278b:
        memory[ds*16 + si] = r8[al];
        r8[al]++;
        si++;
        if (--r16[cx]) {
            pc = 0x1278b;
            break;
        }
        di = 0x9455;
        r16[dx] = 0x1506;
        r16[cx] = 0x008c;
        yield* sub_10644();
        return;
    } while (1);
}
function* sub_1279f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_12809();
        r8[al] = memory[ds*16 + 0x94e0];
        if (r8[al] != 0x00) {
            pc = 0x127af;
            break;
        }
        memory[ds*16 + 0x9546] = 0x00;
        return;
    case 0x127af:
        memory[ds*16 + 0x9546] = 0x01;
        r8[bl] = r8[al];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        push(r16[bx]);
        r16[bx] += 0x94a9;
        si = 0x94a9;
        r16[cx] = 0x0006;
    case 0x127c9:
        lodsb_data_forward();
        memory[ds*16 + r16[bx]] = r8[al];
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x127c9;
            break;
        }
        r16[bx] = pop();
        r16[bx] <<= 1;
        r16[bx] += 0x9455;
        memory16set(ds, 0x9451, r16[bx]);
        si = 0x9455;
        r16[cx] = 0x000c;
    case 0x127e0:
        lodsb_data_forward();
        memory[ds*16 + r16[bx]] = r8[al];
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x127e0;
            break;
        }
        si = 0x94da;
    case 0x127e9:
        r8[al] = memory[ds*16 + si];
        if (r8[al] == 0x00) {
            pc = 0x127f2;
            break;
        }
        si++;
        pc = 0x127e9;
        break;
    case 0x127f2:
        r8[al] = memory[ds*16 + 0x94e0];
        memory[ds*16 + si] = r8[al];
        memory[ds*16 + 0x94e0] = 0x00;
        si -= 0x94da;
        r16[ax] = si;
        memory[ds*16 + 0x9450] = r8[al];
        yield* sub_128da();
        return;
    } while (1);
}
function* sub_12809() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x94da];
        memory[ds*16 + 0x94d3] = r8[al];
        r8[al] = memory[ds*16 + 0x94db];
        memory[ds*16 + 0x94d4] = r8[al];
        r8[al] = memory[ds*16 + 0x94dc];
        memory[ds*16 + 0x94d5] = r8[al];
        r8[al] = memory[ds*16 + 0x94dd];
        memory[ds*16 + 0x94d6] = r8[al];
        r8[al] = memory[ds*16 + 0x94de];
        memory[ds*16 + 0x94d7] = r8[al];
        r8[al] = memory[ds*16 + 0x94df];
        memory[ds*16 + 0x94d8] = r8[al];
        r8[al] = memory[ds*16 + 0x94e0];
        memory[ds*16 + 0x94d9] = r8[al];
        si = 0x94d3;
        di = 0x94da;
        r16[cx] = 0x0007;
    case 0x1283c:
        push(r16[cx]);
        push(si);
    case 0x1283e:
        r8[al] = memory[ds*16 + si];
        if (r8[al] != 0xff) {
            pc = 0x12847;
            break;
        }
        si++;
        pc = 0x1283e;
        break;
    case 0x12847:
        if (si == 0x94d9) {
            pc = 0x12865;
            break;
        }
        r16[bx] = si;
    case 0x1284f:
        r16[bx]++;
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0xff) {
            pc = 0x1285f;
            break;
        }
        yield* sub_12872();
        if (r8[al] == 0x00) {
            pc = 0x1285f;
            break;
        }
        si = r16[bx];
    case 0x1285f:
        if (r16[bx] != 0x94d9) {
            pc = 0x1284f;
            break;
        }
    case 0x12865:
        r8[al] = memory[ds*16 + si];
        memory[ds*16 + si] = 0xff;
        memory[ds*16 + di] = r8[al];
        di++;
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1283c;
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
        r8[al] = memory[ds*16 + si];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
        r16[ax] += 0x94a9;
        si = r16[ax];
        r8[al] = memory[ds*16 + r16[bx]];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
        r16[ax] += 0x94a9;
        di = r16[ax];
        r8[al] = memory[ds*16 + di];
        if (r8[al] > memory[ds*16 + si]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si]) {
            pc = 0x128d0;
            break;
        }
        r8[al] = memory[ds*16 + di + 1];
        if (r8[al] > memory[ds*16 + si + 1]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si + 1]) {
            pc = 0x128d0;
            break;
        }
        r8[al] = memory[ds*16 + di + 2];
        if (r8[al] > memory[ds*16 + si + 2]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si + 2]) {
            pc = 0x128d0;
            break;
        }
        r8[al] = memory[ds*16 + di + 3];
        if (r8[al] > memory[ds*16 + si + 3]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si + 3]) {
            pc = 0x128d0;
            break;
        }
        r8[al] = memory[ds*16 + di + 4];
        if (r8[al] > memory[ds*16 + si + 4]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si + 4]) {
            pc = 0x128d0;
            break;
        }
        r8[al] = memory[ds*16 + di + 5];
        if (r8[al] > memory[ds*16 + si + 5]) {
            pc = 0x128d5;
            break;
        }
        if (r8[al] < memory[ds*16 + si + 5]) {
            pc = 0x128d0;
            break;
        }
    case 0x128d0:
        r8[al] = 0x00;
        di = pop();
        si = pop();
        return;
    case 0x128d5:
        r8[al] = 0x01;
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_128da() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x94da;
        di = 0x01b1;
        r16[cx] = 0x0006;
    case 0x128e3:
        push(r16[cx]);
        di += 0x0002;
        r16[ax] = memory16get(ds, di);
        di += 0x0002;
        push(si);
        push(di);
        yield* sub_12959();
        di = pop();
        si = pop();
        di += 0x0002;
        r16[ax] = memory16get(ds, di);
        di += 0x0002;
        push(si);
        push(di);
        yield* sub_12907();
        di = pop();
        si = pop();
        si++;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x128e3;
            break;
        }
        return;
    } while (1);
}
function* sub_12907() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x944e, r16[ax]);
        r8[al] = memory[ds*16 + si];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] += 0x94a9;
        si = r16[ax];
        memory[ds*16 + 0x944d] = 0x01;
        r16[cx] = 0x0006;
        r16[dx] = 0x0000;
    case 0x12926:
        push(r16[cx]);
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0x12931;
            break;
        }
        memory[ds*16 + 0x944d] = 0x00;
    case 0x12931:
        r8[cl] = memory[ds*16 + 0x944d];
        if (r8[cl] == 0x00) {
            pc = 0x1293f;
            break;
        }
        r16[ax] = 0x6f6c;
        pc = 0x12949;
        break;
    case 0x1293f:
        r8[bh] = 0x00;
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5503);
    case 0x12949:
        push(r16[dx]);
        push(si);
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_129ae();
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
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x944e, r16[ax]);
        r8[al] = memory[ds*16 + si];
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x9455;
        si = r16[ax];
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
        pc = 0x129a0;
        break;
    case 0x12982:
        if (r8[al] != 0x2e) {
            pc = 0x1298b;
            break;
        }
        r16[ax] = 0x6f6c;
        pc = 0x129a0;
        break;
    case 0x1298b:
        if (r8[al] != 0x5f) {
            pc = 0x12994;
            break;
        }
        r16[ax] = 0x764c;
        pc = 0x129a0;
        break;
    case 0x12994:
        r8[al] -= 0x41;
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
    case 0x129a0:
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_129ae();
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
function* sub_1296f() {
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
        pc = 0x129a0;
        break;
    case 0x12982:
        if (r8[al] != 0x2e) {
            pc = 0x1298b;
            break;
        }
        r16[ax] = 0x6f6c;
        pc = 0x129a0;
        break;
    case 0x1298b:
        if (r8[al] != 0x5f) {
            pc = 0x12994;
            break;
        }
        r16[ax] = 0x764c;
        pc = 0x129a0;
        break;
    case 0x12994:
        r8[al] -= 0x41;
        r8[ah] = r8[al];
        r8[al] <<= 1;
        r8[al] += r8[ah];
        r8[al] <<= 1;
        r8[ah] = 0x00;
    case 0x129a0:
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_129ae();
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
function* sub_129ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ds, 0x94f0);
        es = r16[ax];
        di = memory16get(ds, 0x944e);
        di += memory16get(ss, bp + 4 - 2);
        r16[ax] = memory16get(ds, 0x94ea);
        push(ds);
        ds = r16[ax];
        si = memory16get(ss, bp + 6 - 2);
        r16[cx] = 0x000b;
    case 0x129c9:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        di += 0x009a;
        si += 0x009a;
        if (--r16[cx]) {
            pc = 0x129c9;
            break;
        }
        ds = pop();
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_129db() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x9453, 0x0000);
    case 0x129e1:
        r16[ax] = memory16get(ds, 0x9453);
        if (r16[ax] >= 0x000c) {
            pc = 0x12a39;
            break;
        }
        yield* sub_10541();
        if (r8[al] == 0x00) {
            pc = 0x12a39;
            break;
        }
        if (r8[al] != 0x08) {
            pc = 0x12a0d;
            break;
        }
        r16[bx] = memory16get(ds, 0x9451);
        r16[bx] += memory16get(ds, 0x9453);
        memory[ds*16 + r16[bx]] = 0x2e;
        memory16set(ds, 0x9453, memory16get(ds, 0x9453) - 1);
        if (memory16gets(ds, 0x9453) >= 0) {
            pc = 0x12a0b;
            break;
        }
        memory16set(ds, 0x9453, 0x0000);
    case 0x12a0b:
        pc = 0x12a1b;
        break;
    case 0x12a0d:
        r16[bx] = memory16get(ds, 0x9451);
        r16[bx] += memory16get(ds, 0x9453);
        memory[ds*16 + r16[bx]] = r8[al];
        memory16set(ds, 0x9453, memory16get(ds, 0x9453) + 1);
    case 0x12a1b:
        r16[bx] = memory16get(ds, 0x9453);
        if (r16[bx] >= 0x000c) {
            pc = 0x12a2b;
            break;
        }
        r16[bx] += memory16get(ds, 0x9451);
        memory[ds*16 + r16[bx]] = 0x5f;
    case 0x12a2b:
        yield* sub_12a64();
        yield* sub_13498();
        yield* sub_10b8e();
        yield* sub_13383();
        pc = 0x129e1;
        break;
    case 0x12a39:
        r16[bx] = memory16get(ds, 0x9453);
        if (r16[bx] >= 0x000c) {
            pc = 0x12a52;
            break;
        }
        r16[bx] += memory16get(ds, 0x9451);
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] != 0x5f) {
            pc = 0x12a52;
            break;
        }
        memory[ds*16 + r16[bx]] = 0x2e;
        yield* sub_12a64();
    case 0x12a52:
        di = 0x9455;
        r16[dx] = 0x1506;
        r16[cx] = 0x008c;
        yield* sub_10674();
        memory[ds*16 + 0x9546] = 0x00;
        return;
    } while (1);
}
function* sub_12a64() {
    si = memory16get(ds, 0x9451);
    r8[bl] = memory[ds*16 + 0x9450];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 435);
    memory16set(ds, 0x944e, r16[ax]);
    yield* sub_1296f();
}
function* sub_12a7f() {
    memory[ds*16 + 0x952e] = 0x00;
    memory[ds*16 + 0x952f] = 0x00;
    memory[ds*16 + 0x9530] = 0x00;
    memory[ds*16 + 0x9531] = 0x00;
    memory[ds*16 + 0x9532] = 0x00;
    memory[ds*16 + 0x9533] = 0x00;
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
    yield* sub_12cea();
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
    yield* sub_12cea();
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
    yield* sub_12cea();
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
    yield* sub_12cea();
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
    yield* sub_12cea();
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
    yield* sub_12cea();
}
function* sub_12b28() {
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
        yield* sub_1269e();
        r16[ax] = pop();
        if (r8[al] == 0x00) {
            pc = 0x12b59;
            break;
        }
        if (r8[al] == 0x01) {
            pc = 0x12b76;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x12b93;
            break;
        }
        if (r8[al] == 0x03) {
            pc = 0x12bb0;
            break;
        }
        if (r8[al] == 0x04) {
            pc = 0x12bcd;
            break;
        }
        if (r8[al] != 0x05) {
            pc = 0x12b58;
            break;
        }
        pc = 0x12bea;
        break;
    case 0x12b58:
        return;
    case 0x12b59:
        memory[ds*16 + 0x952e] = 0x01;
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
        yield* sub_12cea();
        return;
    case 0x12b76:
        memory[ds*16 + 0x952f] = 0x01;
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
        yield* sub_12cea();
        return;
    case 0x12b93:
        memory[ds*16 + 0x9530] = 0x01;
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
        yield* sub_12cea();
        return;
    case 0x12bb0:
        memory[ds*16 + 0x9531] = 0x01;
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
        yield* sub_12cea();
        return;
    case 0x12bcd:
        memory[ds*16 + 0x9532] = 0x01;
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
        yield* sub_12cea();
        return;
    case 0x12bea:
        memory[ds*16 + 0x9533] = 0x01;
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
        yield* sub_12cea();
        return;
    } while (1);
}
function* sub_12c07() {
    r16[ax] = 0x0a0b;
    push(r16[ax]);
    r16[ax] = 0x0013;
    push(r16[ax]);
    r16[ax] = 0x0030;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_12d9a();
    r16[ax] = 0x0aac;
    push(r16[ax]);
    r16[ax] = 0x0011;
    push(r16[ax]);
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12d9a();
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
    yield* sub_12cea();
}
function* sub_12c45() {
    r16[ax] = 0x0aac;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_12d9a();
    r16[ax] = 0x0b4d;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_12d9a();
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
    yield* sub_12cea();
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
    yield* sub_12cea();
}
function* sub_12c9a() {
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
        yield* sub_12d9a();
        r16[ax] = pop();
        if (r8[al] != 0x06) {
            pc = 0x12cbc;
            break;
        }
        r8[al] = 0x00;
        yield* sub_12cc7();
        r8[al] = 0x06;
        pc = 0x12cc7;
        break;
    case 0x12cbc:
        if (r8[al] != 0x07) {
            pc = 0x12cc7;
            break;
        }
        r8[al] = 0x01;
        yield* sub_12cc7();
        r8[al] = 0x07;
    case 0x12cc7:
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 5407);
        push(r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 5423);
        push(r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 5439);
        push(r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 5455);
        push(r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 5391);
        push(r16[ax]);
        yield* sub_12cea();
        return;
    } while (1);
}
function* sub_12cc7() {
    r8[bl] = r8[al];
    r8[bh] = 0x00;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 5407);
    push(r16[ax]);
    r16[ax] = memory16get(ds, r16[bx] + 5423);
    push(r16[ax]);
    r16[ax] = memory16get(ds, r16[bx] + 5439);
    push(r16[ax]);
    r16[ax] = memory16get(ds, r16[bx] + 5455);
    push(r16[ax]);
    r16[ax] = memory16get(ds, r16[bx] + 5391);
    push(r16[ax]);
    yield* sub_12cea();
}
function* sub_12cea() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        di = memory16get(ss, bp + 10 - 2);
        r16[bx] = memory16get(ss, bp + 4 - 2);
        r16[bx] = memory16get(ds, r16[bx] + 38120);
        si = memory16get(ss, bp + 12 - 2);
        push(ds);
        push(r16[bx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0a05;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0007;
        out16(r16[dx], r16[ax]);
        r16[cx] = memory16get(ss, bp + 8 - 2);
        r16[cx] >>= 1;
        r8[ah] = 0x80;
        r8[al] = 0x08;
        ds = pop();
        r16[bx] = memory16get(ss, bp + 6 - 2);
    case 0x12d19:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(di);
        push(si);
    case 0x12d1e:
        r8[bh] = 0x22;
    case 0x12d20:
        r8[bl] = memory[ds*16 + si];
        si++;
        if (r8[bh] != r8[bl]) {
            pc = 0x12d3d;
            break;
        }
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12d32;
            break;
        }
        r8[ah] = 0x40;
        di++;
        if (--r16[cx]) {
            pc = 0x12d20;
            break;
        }
        pc = 0x12d76;
        break;
    case 0x12d32:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12d39;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x12d39:
        if (--r16[cx]) {
            pc = 0x12d20;
            break;
        }
        pc = 0x12d76;
        break;
    case 0x12d3d:
        r8[bh] = r8[bl];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        if (r8[bl] == 0x02) {
            pc = 0x12d55;
            break;
        }
        out16(r16[dx], r16[ax]);
        videoSet(es, di, videoGet(es, di) & r8[bl]);
        videoSet(es, di + 8192, videoGet(es, di + 8192) & r8[bl]);
    case 0x12d55:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12d5c;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x12d5c:
        r8[bh] &= 0x0f;
        if (r8[bh] == 0x02) {
            pc = 0x12d6d;
            break;
        }
        out16(r16[dx], r16[ax]);
        videoSet(es, di, videoGet(es, di) & r8[bh]);
        videoSet(es, di + 8192, videoGet(es, di + 8192) & r8[bh]);
    case 0x12d6d:
        r8[ah] >>= 1;
        if (r8[ah] != 0) {
            pc = 0x12d74;
            break;
        }
        r8[ah] = 0x80;
        di++;
    case 0x12d74:
        if (--r16[cx]) {
            pc = 0x12d1e;
            break;
        }
    case 0x12d76:
        si = pop();
        si += 0x00a0;
        di = pop();
        di += 0x0028;
        di &= 0x7fff;
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[bx]--;
        if (r16[bx] != 0) {
            pc = 0x12d19;
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
        sp += 10;
        return;
    } while (1);
}
function* sub_12d9a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = 0xa000;
        es = r16[ax];
        di = memory16get(ss, bp + 10 - 2);
        r16[dx] = 0x03ce;
        r16[ax] = memory16get(ss, bp + 4 - 2);
        r8[ah] = r8[al];
        r8[al] = 0x00;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        flags.direction = false;
        r16[bx] = memory16get(ss, bp + 6 - 2);
    case 0x12db8:
        push(di);
        r16[cx] = memory16get(ss, bp + 8 - 2);
        rep_stosb_video_forward();
        di = pop();
        push(di);
        di += 0x2000;
        r16[cx] = memory16get(ss, bp + 8 - 2);
        rep_stosb_video_forward();
        di = pop();
        di += 0x0028;
        r16[bx]--;
        if (r16[bx] != 0) {
            pc = 0x12db8;
            break;
        }
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al]++;
        out16(r16[dx], r16[ax]);
        bp = pop();
        sp += 8;
        return;
    } while (1);
}
function* sub_12ddc() {
    r8[bl] = memory[ds*16 + 0x94e4];
    r16[bx] &= 0x0003;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 6698);
    memory16set(ds, 0x94e2, r16[ax]);
    memory[ds*16 + 0x94e4] += 1;
    memory[ds*16 + 0x9527] = 0xff;
}
function* sub_12df6() {
    r8[al] = 0x00;
    memory[ds*16 + 0x94e5] = r8[al];
    memory[ds*16 + 0x94e6] = r8[al];
    memory[ds*16 + 0x94e7] = r8[al];
}
function* sub_12e02() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        yield* sub_11b80();
        yield* sub_1309d();
        si = pop();
        r16[ax] = memory16get(ds, 0x952a);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[bx] = memory16get(ds, 0x954c);
        if (!(r8[bl] & 0x01)) {
            pc = 0x12e23;
            break;
        }
        r16[ax] = -r16[ax];
        r16[ax] -= 0x0003;
        pc = 0x12e30;
        break;
    case 0x12e23:
        if (!(r8[bl] & 0x02)) {
            pc = 0x12e2d;
            break;
        }
        r16[ax] += 0x0003;
        pc = 0x12e30;
        break;
    case 0x12e2d:
        r16[ax] = 0x0000;
    case 0x12e30:
        memory16set(ds, 0x9522, r16[ax]);
        r8[al] = memory[ds*16 + si + 22];
        r16[ax] &= 0x007f;
        if (r8[al] <= 0x3f) {
            pc = 0x12e48;
            break;
        }
        r8[al] = -r8[al];
        r8[al] += 0x7f;
        yield* sub_13084();
        r16[ax] = -r16[ax];
        pc = 0x12e4b;
        break;
    case 0x12e48:
        yield* sub_13084();
    case 0x12e4b:
        memory16set(ds, 0x9520, r16[ax]);
        r16[ax] = memory16get(ds, 0x951e);
        r16[ax] += memory16get(ds, 0x9522);
        r16[ax] += memory16get(ds, 0x9520);
        if (r16[ax] == 0) {
            pc = 0x12e6a;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x12e63;
            break;
        }
        r16[ax]++;
        if (r16s[ax] >= 0) {
            pc = 0x12e61;
            break;
        }
        r16[ax]++;
    case 0x12e61:
        pc = 0x12e6a;
        break;
    case 0x12e63:
        r16[ax]--;
        if (r16s[ax] <= signed16(0x0000)) {
            pc = 0x12e6a;
            break;
        }
        r16[ax]--;
    case 0x12e6a:
        if (r16s[ax] <= signed16(0x0040)) {
            pc = 0x12e74;
            break;
        }
        r16[ax] = 0x0040;
        pc = 0x12e7c;
        break;
    case 0x12e74:
        if (r16s[ax] >= signed16(0xffc0)) {
            pc = 0x12e7c;
            break;
        }
        r16[ax] = 0xffc0;
    case 0x12e7c:
        memory16set(ds, 0x951e, r16[ax]);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ds*16 + si + 22] += r8[al];
        r8[al] = memory[ds*16 + si + 22];
        r16[ax] &= 0x007f;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 5749];
        cbw();
        r16[ax] <<= 1;
        r16[ax] += 0x0080;
        memory16set(ds, si + 5, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 5877];
        cbw();
        r16[ax] <<= 1;
        r16[ax] += 0x0080;
        push(r16[bx]);
        if (r16[ax] == 0x0000) {
            pc = 0x12ebe;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div8(r8[bl]);
        r8[ah] = 0x00;
    case 0x12ebe:
        r16[bx] = pop();
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 6005];
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x1594;
        yield* sub_12121();
        r8[al] = memory[ds*16 + 0x94e6];
        memory[ds*16 + 0x94e7] = r8[al];
        r8[al] = memory[ds*16 + 0x94e5];
        memory[ds*16 + 0x94e6] = r8[al];
        r8[al] = memory[ds*16 + 0x1ba0];
        memory[ds*16 + 0x94e5] = r8[al];
        r16[ax] = memory16get(ds, 0x954c);
        r8[bl] = memory[ds*16 + 0x951a];
        if (!(r8[al] & 0x40)) {
            pc = 0x12f02;
            break;
        }
        if (r8[bl] != 0x02) {
            pc = 0x12f00;
            break;
        }
        memory[ds*16 + 0x951a] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
        memory[ds*16 + 0x951c] = 0x02;
    case 0x12f00:
        pc = 0x12f18;
        break;
    case 0x12f02:
        if (r8[bl] != 0x01) {
            pc = 0x12f0e;
            break;
        }
        memory[ds*16 + 0x951a] = 0x02;
        pc = 0x12f18;
        break;
    case 0x12f0e:
        if (r8[bl] != 0x03) {
            pc = 0x12f18;
            break;
        }
        memory[ds*16 + 0x951a] = 0x00;
    case 0x12f18:
        r16[ax] = memory16get(ds, 0x954c);
        r8[bl] = memory[ds*16 + 0x951b];
        if (!(r8[al] & 0x20)) {
            pc = 0x12f39;
            break;
        }
        if (r8[bl] != 0x02) {
            pc = 0x12f37;
            break;
        }
        memory[ds*16 + 0x951b] = 0x03;
        r8[al] = 0x02;
        yield* sub_13840();
        memory[ds*16 + 0x951c] = 0x02;
    case 0x12f37:
        return;
    case 0x12f39:
        if (r8[bl] != 0x01) {
            pc = 0x12f45;
            break;
        }
        memory[ds*16 + 0x951b] = 0x02;
        return;
    case 0x12f45:
        if (r8[bl] != 0x03)
            return;
        memory[ds*16 + 0x951b] = 0x00;
        return;
    } while (1);
}
function* sub_12f50() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x20) {
            pc = 0x12f5e;
            break;
        }
        r8[ah] = memory[ds*16 + 0x951a];
        r8[al] = 0xf8;
        pc = 0x12f64;
        break;
    case 0x12f5e:
        r8[ah] = memory[ds*16 + 0x951b];
        r8[al] = 0x08;
    case 0x12f64:
        if (r8[ah] == 0x03) {
            pc = 0x12f6e;
            break;
        }
        if (r8[ah] != 0x00) {
            pc = 0x12f90;
            break;
        }
    case 0x12f6e:
        memory[ds*16 + si] = 0x00;
        si = 0x1ba1;
    case 0x12f74:
        r8[al] = memory[ds*16 + si];
        if (r8[al] & 0x80) {
            pc = 0x12f8f;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x12f8a;
            break;
        }
        r8[al] = memory[ds*16 + si + 18];
        if (r8[al] != 0x0f) {
            pc = 0x12f8a;
            break;
        }
        push(si);
        yield* sub_13059();
        si = pop();
    case 0x12f8a:
        si += 0x0017;
        pc = 0x12f74;
        break;
    case 0x12f8f:
        return;
    case 0x12f90:
        r8[al] += memory[ds*16 + 0x94e7];
        r16[ax] &= 0x007f;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 5749];
        cbw();
        r16[cx] = r16[ax];
        r16[cx] = sar16(r16[cx], 1);
        r16[ax] += r16[cx];
        r16[ax] += 0x0080;
        memory16set(ds, si + 5, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 5877];
        cbw();
        r16[cx] = r16[ax];
        r16[cx] = sar16(r16[cx], 1);
        r16[ax] += r16[cx];
        r16[ax] += 0x0080;
        if (r16[ax] == 0x0000) {
            pc = 0x12fd0;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div8(r8[bl]);
        r8[ah] = 0x00;
    case 0x12fd0:
        r8[bl] = memory[ds*16 + 0x1ba0];
        r16[bx] &= 0x007f;
        memory16set(ds, si + 7, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 6290];
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = 0x1811;
        yield* sub_12121();
        return;
    } while (1);
}
function* sub_12fe8() {
    r16[bx] = memory16get(ds, 0x9525);
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] &= 0x001f;
    r8[al] = memory[ds*16 + r16[bx] + 6666];
    memory[ds*16 + 0x9549] = r8[al];
    r8[al] = memory[ds*16 + r16[bx] + 6634];
    memory[ds*16 + si + 4] = r8[al];
    r16[bx] = 0x1929;
    yield* sub_12121();
}
function* sub_1300a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x9547);
        r16[ax] -= memory16get(ds, si + 19);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r16[ax] <= 0x002d) {
            pc = 0x1301f;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x1301f:
        push(r16[ax]);
        yield* sub_13130();
        r16[ax] = pop();
        r16[ax] >>= 1;
        memory[ds*16 + si + 4] = r8[al];
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 6810];
        memory[ds*16 + si + 2] = r8[al];
        r16[bx] = 0x1ac9;
        yield* sub_12121();
        r8[al] = memory[ds*16 + si + 2];
        if (r8[al] == 0x02) {
            pc = 0x13040;
            break;
        }
        return;
    case 0x13040:
        r8[bl] = memory[ds*16 + 0x1b8e];
        r8[bh] = 0x00;
        r8[al] = memory[ds*16 + r16[bx] + 6133];
        if (r8[al] == memory[ds*16 + si + 1]) {
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
        memory[ds*16 + si] = 0x00;
        r8[al] = memory[ds*16 + 0x951d];
        if (r8[al] != 0x40) {
            pc = 0x1306a;
            break;
        }
        memory16set(ds, 0x9540, memory16get(ds, 0x9540) + 0x0006);
        return;
    case 0x1306a:
        if (r8[al] != 0x80) {
            pc = 0x13075;
            break;
        }
        memory16set(ds, 0x953c, memory16get(ds, 0x953c) + 0x0004);
        return;
    case 0x13075:
        if (r8[al] != 0xc0) {
            pc = 0x13080;
            break;
        }
        memory16set(ds, 0x9544, memory16get(ds, 0x9544) + 0x0008);
        return;
    case 0x13080:
        yield* sub_1268a();
        return;
    } while (1);
}
function* sub_13084() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] -= 0x05;
        if (r8s[al] >= 0) {
            pc = 0x1308d;
            break;
        }
        r16[ax] = 0x0000;
        return;
    case 0x1308d:
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
function* sub_1309d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x952a);
        r16[bx] += 0x0007;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] += 0x0002;
        memory16set(ds, 0x9547, memory16get(ds, 0x9547) + r16[bx]);
        r16[ax] = memory16get(ds, 0x950f);
        r16[ax] += r16[bx];
        if (r16[ax] <= 0x02e8) {
            pc = 0x130c4;
            break;
        }
        r16[ax] = 0x0000;
        memory16set(ds, 0x953c, 0xffff);
    case 0x130c4:
        memory16set(ds, 0x950f, r16[ax]);
        r16[ax] = memory16get(ds, 0x9547);
        r16[ax] -= 0x0380;
        if (r16s[ax] >= 0) {
            pc = 0x13124;
            break;
        }
        r16[ax] = -r16[ax];
        if (r16[ax] >= 0x0100) {
            pc = 0x130ed;
            break;
        }
        memory16set(ds, 0x9525, r16[ax]);
        r8[al] = memory[ds*16 + 0x9524];
        if (r8[al] != 0x00) {
            pc = 0x130eb;
            break;
        }
        si = 0x1912;
        yield* sub_10b58();
        memory[ds*16 + 0x9524] = 0x01;
    case 0x130eb:
        pc = 0x13122;
        break;
    case 0x130ed:
        r16[ax] = memory16get(ds, 0x9547);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r8[al] == memory[ds*16 + 0x9527]) {
            pc = 0x13122;
            break;
        }
        memory[ds*16 + 0x9527] = r8[al];
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] += memory16get(ds, 0x94e2);
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0x00) {
            pc = 0x13122;
            break;
        }
        si = 0x1ab2;
        memory[ds*16 + si + 1] = r8[al];
        r16[ax] = memory16get(ds, 0x9547);
        memory16set(ds, si + 19, r16[ax]);
        yield* sub_10b58();
    case 0x13122:
        return;
    case 0x13124:
        memory[ds*16 + 0x94ff] = 0x00;
        r16[ax] = memory16get(ds, 0x950c);
        memory16set(ds, 0x9528, r16[ax]);
        return;
    } while (1);
}
function* sub_13130() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r8[cl] = memory[ds*16 + r16[bx] + 6762];
        r8[ch] = 0x00;
        r8[al] = memory[ds*16 + si + 1];
        if (r8[al] == 0x01) {
            pc = 0x1315e;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x13167;
            break;
        }
        if (r8[al] == 0x03) {
            pc = 0x13170;
            break;
        }
        if (r8[al] == 0x04) {
            pc = 0x13178;
            break;
        }
        if (r8[al] == 0x05) {
            pc = 0x13181;
            break;
        }
        if (r8[al] == 0x06) {
            pc = 0x13188;
            break;
        }
        if (r8[al] == 0x07) {
            pc = 0x13191;
            break;
        }
        if (r8[al] == 0x08) {
            pc = 0x1319b;
            break;
        }
        return;
    case 0x1315e:
        r16[cx] = -r16[cx];
        r16[cx] += 0x006a;
        memory16set(ds, si + 7, r16[cx]);
        return;
    case 0x13167:
        push(r16[cx]);
        yield* sub_1315e();
        r16[cx] = pop();
        yield* sub_13170();
        return;
    case 0x13170:
        r16[cx] += 0x0080;
        memory16set(ds, si + 5, r16[cx]);
        return;
    case 0x13178:
        push(r16[cx]);
        yield* sub_13170();
        r16[cx] = pop();
        yield* sub_13181();
        return;
    case 0x13181:
        r16[cx] += 0x006a;
        memory16set(ds, si + 7, r16[cx]);
        return;
    case 0x13188:
        push(r16[cx]);
        yield* sub_13181();
        r16[cx] = pop();
        yield* sub_13191();
        return;
    case 0x13191:
        r16[cx] = -r16[cx];
        r16[cx] += 0x0080;
        memory16set(ds, si + 5, r16[cx]);
        return;
    case 0x1319b:
        push(r16[cx]);
        yield* sub_13191();
        r16[cx] = pop();
        yield* sub_1315e();
        return;
    } while (1);
}
function* sub_1315e() {
    r16[cx] = -r16[cx];
    r16[cx] += 0x006a;
    memory16set(ds, si + 7, r16[cx]);
}
function* sub_13170() {
    r16[cx] += 0x0080;
    memory16set(ds, si + 5, r16[cx]);
}
function* sub_13181() {
    r16[cx] += 0x006a;
    memory16set(ds, si + 7, r16[cx]);
}
function* sub_13191() {
    r16[cx] = -r16[cx];
    r16[cx] += 0x0080;
    memory16set(ds, si + 5, r16[cx]);
}
function* sub_131a4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x94f8);
        es = r16[ax];
        di = 0x0144;
        r16[bx] = memory16get(ds, 0x94f4);
        si = 0x0340;
        yield* sub_131e7();
        r16[ax] = ~r16[ax];
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
    case 0x131d2:
        push(r16[cx]);
        r16[cx] = 0x0020;
        rep_movsb_video_data_forward();
        di += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x131d2;
            break;
        }
        ds = pop();
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al]++;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_131e7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x951d];
        if (r8[al] != 0x40) {
            pc = 0x131f3;
            break;
        }
        r16[ax] = 0x0002;
        return;
    case 0x131f3:
        if (r8[al] != 0x80) {
            pc = 0x131fc;
            break;
        }
        r16[ax] = 0x0004;
        return;
    case 0x131fc:
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
        r8[al] = memory[ds*16 + 0x951c];
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
        memory[ds*16 + 0x951c] = 0x00;
        return;
    case 0x13223:
        r16[ax] = 0x000f;
        memory[ds*16 + 0x951c] = 0x01;
        return;
    } while (1);
}
function* sub_13291() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 4 - 2);
        es = r16[ax];
        di = 0x0144;
        r16[bx] = memory16get(ss, bp + 6 - 2);
        si = 0x0144;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        push(ds);
        ds = r16[bx];
        flags.direction = false;
        r16[cx] = 0x00a0;
    case 0x132b0:
        push(r16[cx]);
        r16[cx] = 0x0020;
        rep_movsb_video_video_forward();
        si += 0x0008;
        di += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x132b0;
            break;
        }
        ds = pop();
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_132fe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[ax] = memory16get(ds, 0x94f8);
        es = r16[ax];
        di = 0x0144;
        r16[ax] = memory16get(ds, 0x9528);
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
function* sub_1333c() {
    r16[ax] = 0x000d;
    interrupt(0x10);
    r16[ax] = 0xa000;
    memory16set(ds, 0x94fa, r16[ax]);
    r16[ax] += 0x0200;
    memory16set(ds, 0x94f8, r16[ax]);
    r16[ax] = 0x0000;
    yield* sub_133b3();
    r16[ax] = memory16get(ds, 0x94f8);
    r16[bx] = memory16get(ds, 0x94fa);
    memory16set(ds, 0x94f8, r16[bx]);
    memory16set(ds, 0x94fa, r16[ax]);
    r16[bx] = memory16get(ds, 0x94fa);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    flags.interrupts = false;
    r16[dx] = 0x03d4;
    r8[ah] = r8[bh];
    r8[al] = 0x0c;
    out16(r16[dx], r16[ax]);
    r8[ah] = r8[bl];
    r8[al]++;
    out16(r16[dx], r16[ax]);
    flags.interrupts = true;
    yield* sub_133d7();
}
function* sub_13383() {
    r16[ax] = memory16get(ds, 0x94f8);
    r16[bx] = memory16get(ds, 0x94fa);
    memory16set(ds, 0x94f8, r16[bx]);
    memory16set(ds, 0x94fa, r16[ax]);
    r16[bx] = memory16get(ds, 0x94fa);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    flags.interrupts = false;
    r16[dx] = 0x03d4;
    r8[ah] = r8[bh];
    r8[al] = 0x0c;
    out16(r16[dx], r16[ax]);
    flags.interrupts = true;
    r16[dx] = 0x03da;
    yield* sync();
}
function* sub_133b3() {
    push(r16[ax]);
    r16[ax] = memory16get(ds, 0x94f8);
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
    r8[al]++;
    out16(r16[dx], r16[ax]);
}
function* sub_133d7() {
    yield* sync();
}
function* sub_133e5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x94f8);
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
        videoSet(es, di, videoGet(es, di) & r8[al]);
        di++;
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
    yield* sub_133b3();
    yield* sub_13439();
    yield* sub_13383();
    r16[ax] = 0x0000;
    yield* sub_133b3();
    yield* sub_13439();
}
function* sub_13439() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x94f8);
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
        videoSet(es, di, r8[al]);
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x13459;
            break;
        }
        di = 0x013c;
        r8[al] = 0x80;
        r16[cx] = 0x00a2;
    case 0x13469:
        videoSet(es, di, r8[al]);
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
    r16[bx] = memory16get(ds, 0x94f2);
    yield* sub_133e5();
    yield* sub_13383();
    si = 0x0000;
    r16[bx] = memory16get(ds, 0x94f2);
    yield* sub_133e5();
    r16[ax] = memory16get(ds, 0x94f8);
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
    r16[ax] = memory16get(ds, 0x94f8);
    push(r16[ax]);
    yield* sub_13291();
}
function* sub_134a8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x0000;
        r16[ax] = memory16get(ds, 0x94f4);
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
        yield* sub_136d4();
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x004f;
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = memory16get(ds, 0x9547);
        r16[ax] &= 0x003f;
        memory16set(ds, 0x954e, r16[ax]);
        r16[bx] = r16[ax];
        r16[ax] += 0x0040;
        push(r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 8156];
        r8[ah] = 0x00;
        push(r16[ax]);
        yield* sub_135bc();
        r16[ax] = memory16get(ds, 0x954e);
        if (r16[ax] <= 0x000c) {
            pc = 0x13527;
            break;
        }
        return;
    case 0x13527:
        r16[bx] = memory16get(ds, 0x954e);
        r8[al] = memory[ds*16 + r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        yield* sub_136d4();
        r16[bx] = memory16get(ds, 0x954e);
        r8[al] = memory[ds*16 + r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        yield* sub_136d4();
        r16[bx] = memory16get(ds, 0x954e);
        r8[al] = memory[ds*16 + r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        yield* sub_136d4();
        r16[bx] = memory16get(ds, 0x954e);
        r8[al] = memory[ds*16 + r16[bx] + 8220];
        r8[ah] = 0x00;
        r16[ax] = -r16[ax];
        r16[ax] += 0x007f;
        push(r16[ax]);
        r16[ax] = 0x00ff;
        push(r16[ax]);
        r16[ax] = 0x0000;
        push(r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 8233];
        r8[ah] = 0x00;
        r16[ax] += 0x0080;
        push(r16[ax]);
        yield* sub_136d4();
        return;
    } while (1);
}
function* sub_135bc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
    case 0x135bf:
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x0080;
        r16[ax] += memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 4 - 2);
        push(r16[ax]);
        r16[ax] = 0x007f;
        r16[ax] -= memory16get(ss, bp + 6 - 2);
        push(r16[ax]);
        yield* sub_136d4();
        r16[ax] = memory16get(ss, bp + 6 - 2);
        r16[ax] >>= 1;
        if (r8[al] <= memory[ds*16 + 0x9549]) {
            pc = 0x136d0;
            break;
        }
        memory16set(ss, bp + 6 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
        r16[ax] >>= 1;
        memory16set(ss, bp + 4 - 2, r16[ax]);
        pc = 0x135bf;
        break;
    case 0x136d0:
        bp = pop();
        sp += 4;
        return;
    } while (1);
}
function* sub_136d4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        bp = sp;
        sp -= 0x000a;
        r16[ax] = memory16get(ds, 0x94f4);
        es = r16[ax];
        r16[ax] = memory16get(ss, bp + 8 - 2);
        if (r16[ax] == 0x0000) {
            pc = 0x136fa;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0005;
        r8[bl] = 0x0c;
        div8(r8[bl]);
        r8[ah] = 0x00;
    case 0x136fa:
        memory16set(ss, bp + 8 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
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
        div8(r8[bl]);
        r8[ah] = 0x00;
    case 0x13718:
        memory16set(ss, bp + 4 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 10 - 2);
        r16[bx] = memory16get(ss, bp + 6 - 2);
        if (r16[bx] >= r16[ax]) {
            pc = 0x13737;
            break;
        }
        memory16set(ss, bp + 10 - 2, r16[bx]);
        memory16set(ss, bp + 6 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8 - 2);
        r16[bx] = memory16get(ss, bp + 4 - 2);
        memory16set(ss, bp + 8 - 2, r16[bx]);
        memory16set(ss, bp + 4 - 2, r16[ax]);
    case 0x13737:
        r16[ax] = memory16get(ss, bp + 6 - 2);
        r16[ax] -= memory16get(ss, bp + 10 - 2);
        memory16set(ss, bp - 2 - 2, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4 - 2);
        r16[ax] -= memory16get(ss, bp + 8 - 2);
        if (r16s[ax] >= 0) {
            pc = 0x13751;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ss, bp - 10 - 2, 0xffe0);
        pc = 0x13756;
        break;
    case 0x13751:
        memory16set(ss, bp - 10 - 2, 0x0020);
    case 0x13756:
        memory16set(ss, bp - 4 - 2, r16[ax]);
        r16[cx] = memory16get(ss, bp - 2 - 2);
        if (r16[cx] == 0x0000) {
            pc = 0x137db;
            break;
        }
        if (r16[ax] != 0x0000) {
            pc = 0x13769;
            break;
        }
        pc = 0x137ed;
        break;
    case 0x13769:
        if (r16[ax] >= memory16get(ss, bp - 2 - 2)) {
            pc = 0x137a4;
            break;
        }
        r16[ax] = memory16get(ss, bp - 2 - 2);
        r16[ax] >>= 1;
        memory16set(ss, bp - 6 - 2, r16[ax]);
        yield* sub_13801();
        r16[cx] = memory16get(ss, bp - 2 - 2);
    case 0x1377c:
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x13783;
            break;
        }
        r8[al] = 0x80;
        di++;
    case 0x13783:
        r16[bx] = memory16get(ss, bp - 6 - 2);
        r16[bx] += memory16get(ss, bp - 4 - 2);
        memory16set(ss, bp - 6 - 2, r16[bx]);
        if (r16[bx] <= memory16get(ss, bp - 2 - 2)) {
            pc = 0x1379d;
            break;
        }
        r16[bx] -= memory16get(ss, bp - 2 - 2);
        memory16set(ss, bp - 6 - 2, r16[bx]);
        r16[bx] = memory16get(ss, bp - 10 - 2);
        di += memory16get(ss, bp - 10 - 2);
    case 0x1379d:
        di &= 0xffff;
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
        if (--r16[cx]) {
            pc = 0x1377c;
            break;
        }
        pc = 0x137d5;
        break;
    case 0x137a4:
        r16[ax] = memory16get(ss, bp - 4 - 2);
        r16[ax] >>= 1;
        memory16set(ss, bp - 6 - 2, r16[ax]);
        yield* sub_13801();
        r16[cx] = memory16get(ss, bp - 4 - 2);
    case 0x137b2:
        di += memory16get(ss, bp - 10 - 2);
        r16[bx] = memory16get(ss, bp - 6 - 2);
        r16[bx] += memory16get(ss, bp - 2 - 2);
        memory16set(ss, bp - 6 - 2, r16[bx]);
        if (r16[bx] <= memory16get(ss, bp - 4 - 2)) {
            pc = 0x137d0;
            break;
        }
        r16[bx] -= memory16get(ss, bp - 4 - 2);
        memory16set(ss, bp - 6 - 2, r16[bx]);
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x137d0;
            break;
        }
        r8[al] = 0x80;
        di++;
    case 0x137d0:
        di &= 0xffff;
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
        if (--r16[cx]) {
            pc = 0x137b2;
            break;
        }
    case 0x137d5:
        sp = bp;
        bp = pop();
        sp += 8;
        return;
    case 0x137db:
        yield* sub_13801();
        r16[cx] = memory16get(ss, bp - 4 - 2);
        if (r16[cx] == 0) {
            pc = 0x137d5;
            break;
        }
    case 0x137e3:
        di += memory16get(ss, bp - 10 - 2);
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
        if (--r16[cx]) {
            pc = 0x137e3;
            break;
        }
        pc = 0x137d5;
        break;
    case 0x137ed:
        yield* sub_13801();
        r16[cx] = memory16get(ss, bp - 2 - 2);
    case 0x137f3:
        r8[al] >>= 1;
        if (r8[al] != 0) {
            pc = 0x137fa;
            break;
        }
        r8[al] = 0x80;
        di++;
    case 0x137fa:
        memory[es*16 + di] = memory[es*16 + di] | r8[al];
        if (--r16[cx]) {
            pc = 0x137f3;
            break;
        }
        pc = 0x137d5;
        break;
        return;
    } while (1);
}
function* sub_13801() {
    r16[ax] = memory16get(ss, bp + 8 - 2);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    di = r16[ax];
    r16[ax] = memory16get(ss, bp + 10 - 2);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    di += r16[ax];
    r16[cx] = memory16get(ss, bp + 10 - 2);
    r16[cx] &= 0x0007;
    r8[al] = 0x80;
    r8[al] >>= r8[cl];
    memory[es*16 + di] = memory[es*16 + di] | r8[al];
}
function* sub_1382a() {
    r8[al] = 0x00;
    memory[ds*16 + 0x9550] = r8[al];
    memory[ds*16 + 0x9551] = r8[al];
    memory[ds*16 + 0x9552] = r8[al];
    memory[ds*16 + 0x9506] = 0x01;
    memory[ds*16 + 0x9505] = 0x00;
}
function* sub_13840() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = memory[ds*16 + 0x955e];
        if (r8[ah] == 0x00) {
            pc = 0x1384a;
            break;
        }
        return;
    case 0x1384a:
        r8[ah] = memory[ds*16 + 0x9506];
        if (r8[ah] != 0x00) {
            pc = 0x13854;
            break;
        }
        return;
    case 0x13854:
        r8[ah] = memory[ds*16 + 0x9550];
        if (r8[ah] != 0x00) {
            pc = 0x13866;
            break;
        }
        push(r16[bx]);
        memory[ds*16 + 0x9550] = r8[al];
        yield* sub_13914();
        r16[bx] = pop();
        return;
    case 0x13866:
        r8[ah] = memory[ds*16 + 0x9551];
        if (r8[ah] != 0x00) {
            pc = 0x13873;
            break;
        }
        memory[ds*16 + 0x9551] = r8[al];
        return;
    case 0x13873:
        if (r8[al] <= memory[ds*16 + 0x9552])
            return;
        memory[ds*16 + 0x9552] = r8[al];
        return;
    } while (1);
}
function* sub_13914() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al]--;
        r8[bl] = r8[al];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds, r16[bx] + 35812);
        r8[al] = memory[ds*16 + r16[bx] + 1];
        memory[ds*16 + 0x9557] = r8[al];
        if (r16[bx] != 0x8c2c) {
            pc = 0x13941;
            break;
        }
        r16[ax] = memory16get(ds, 0x9536);
        r8[ah] = r8[al];
        r8[al] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] = -r16[ax];
        r16[ax] += 0x1f40;
        memory16set(ds, 0x8c2e, r16[ax]);
        pc = 0x13966;
        break;
    case 0x13941:
        if (r16[bx] != 0x8c32) {
            pc = 0x13966;
            break;
        }
        r8[al] = memory[ds*16 + 0x1ba0];
        r16[ax] &= 0x007f;
        if (r16[ax] <= 0x003f) {
            pc = 0x13957;
            break;
        }
        r16[ax] -= 0x0040;
        pc = 0x1395c;
        break;
    case 0x13957:
        r16[ax] = -r16[ax];
        r16[ax] += 0x003f;
    case 0x1395c:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x0190;
        memory16set(ds, 0x8c34, r16[ax]);
    case 0x13966:
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, 0x9558, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 4);
        memory16set(ds, 0x955a, r16[ax]);
        r8[bl] = memory[ds*16 + r16[bx]];
        memory[ds*16 + 0x9553] = r8[bl];
        if (r8s[bl] <= signed8(0x00)) {
            pc = 0x1398f;
            break;
        }
        r8[bl]--;
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 35932);
        memory16set(ds, 0x9555, r16[ax]);
        memory[ds*16 + 0x9554] = 0x00;
    case 0x1398f:
        r8[al] = 0xb6;
        out8(0x43, r8[al]);
        r16[ax] = memory16get(ds, 0x9558);
        out8(0x42, r8[al]);
        r8[al] = r8[ah];
        out8(0x42, r8[al]);
        r8[al] = in8(0x61);
        r8[al] |= 0x03;
        out8(0x61, r8[al]);
        return;
    } while (1);
}
function* sub_139a3() {
    r8[al] = 0x00;
    memory[ds*16 + 0x9550] = r8[al];
    memory[ds*16 + 0x9551] = r8[al];
    memory[ds*16 + 0x9552] = r8[al];
    memory[ds*16 + 0x9557] = r8[al];
    r8[al] = in8(0x61);
    r8[al] &= 0xfc;
    out8(0x61, r8[al]);
}
function* sub_139b8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x9561] = 0x00;
        memory16set(ds, 0x955f, 0x0000);
        memory[ds*16 + 0x955e] = 0x01;
        r8[al] = memory[ds*16 + 0x9546];
        if (r8[al] != 0x00) {
            pc = 0x139d4;
            break;
        }
        r16[ax] = 0x8dec;
        pc = 0x139d7;
        break;
    case 0x139d4:
        r16[ax] = 0x8d4c;
    case 0x139d7:
        memory16set(ds, 0x9562, r16[ax]);
        return;
    } while (1);
}