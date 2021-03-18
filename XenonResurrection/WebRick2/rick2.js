function* sub_10524() {
    r8[ah] = 0x0f;
    interrupt(16);
    memory[ds*16+0x6A] = r8[al];
    r16[ax] = 0x000d;
    interrupt(16);
}
function* sub_10533() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x48;
        r16[bx] = 0x0200;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1053F;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1053F:
        memory16set(ds*16+0x4C, r16[ax]);
        r8[ah] = 0x48;
        r16[bx] = 0x0aaa;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1054E;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1054E:
        memory16set(ds*16+0x62, r16[ax]);
        r8[ah] = 0x48;
        r16[bx] = 0x0aaa;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1055D;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1055D:
        memory16set(ds*16+0x64, r16[ax]);
        r8[ah] = 0x48;
        r16[bx] = 0x0aaa;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1056C;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1056C:
        memory16set(ds*16+0x66, r16[ax]);
        r8[ah] = 0x48;
        r16[bx] = 0x0aaa;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1057B;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1057B:
        memory16set(ds*16+0x68, r16[ax]);
        r8[ah] = 0x48;
        r16[bx] = 0x0080;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1058A;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1058A:
        memory16set(ds*16+0x52, r16[ax]);
        memory16set(ds*16+0x56, 0xa400);
        return;
    } while (1);
}
function* sub_10594() {
    r16[ax] = memory16get(ds*16+0x62);
    r16[cx] = 0x4344;
    r16[dx] = 0x00cd;
    yield* sub_1A65B();
}
function* sub_105A1() {
    r16[ax] = memory16get(ds*16+0x4C);
    r16[cx] = 0x0000;
    r16[dx] = 0x00e5;
    yield* sub_1A65B();
    r16[cx] = 0x0400;
    r16[ax] = 0xa680;
    yield* sub_105F7();
    r16[ax] = memory16get(ds*16+0x4C);
    r16[cx] = 0x0000;
    r16[dx] = 0x00f1;
    yield* sub_1A65B();
    r16[cx] = 0x0080;
    r16[ax] = 0xa700;
    yield* sub_105F7();
}
function* sub_105CC() {
    r16[ax] = memory16get(ds*16+0x4C);
    r16[cx] = 0x0000;
    r16[dx] = 0x00d9;
    yield* sub_1A65B();
    r16[cx] = 0x0400;
    r16[ax] = 0xa600;
    yield* sub_105F7();
    r16[ax] = memory16get(ds*16+0x4C);
    r16[cx] = 0x0000;
    r16[dx] = 0x00fd;
    yield* sub_1A65B();
    r16[cx] = 0x0180;
    r16[ax] = 0xa980;
    yield* sub_105F7();
}
function* sub_105F7() {
    push(ds);
    push(es);
    bp = r16[cx];
    r16[dx] = memory16get(ds*16+0x4C);
    ds = r16[dx];
    es = r16[ax];
    si = si ^ si;
    di = di ^ di;
    push(r16[dx]);
    r16[ax] = 0x0005;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = bp;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = bp;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = bp;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = bp;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    es = pop();
    ds = pop();
}
function* sub_10661() {
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
    di += r16[cx];
    movsb_video_video_forward();
}
function* sub_10702() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x279] = 0x00;
        si = 0x029a;
        di = 0x02ce;
        r16[cx] = 0x0033;
        rep_movsb_data_data_forward();
        r16[ax] = 0x1a00;
        interrupt(16);
        if (r8s[bl] <= signed8(0x05)) {
            pc = 0x10731;
            break;
        }
        if (r8s[bl] < signed8(0x07)) {
            pc = 0x10731;
            break;
        }
        if (r8s[bl] > signed8(0x08)) {
            pc = 0x10731;
            break;
        }
        si = 0x028a;
        memory[ds*16+0x279] = 0x01;
        pc = 0x1073E;
        break;
        _STOP_("db 90h");
    case 0x10731:
        si = 0x027a;
        memory[ds*16+0x279] = 0x00;
        memory[ds*16+0x278] = 0x01;
    case 0x1073E:
        memory[ds*16+0x301] = 0x00;
        r16[cx] = 0x0010;
    case 0x10746:
        r8[ah] = 0x10;
        r8[al] = 0x00;
        r8[bh] = memory[ds*16+si];
        si += 1;
        r8[bl] = memory[ds*16+0x301];
        memory[ds*16+0x301] += 1;
        push(si);
        push(r16[cx]);
        interrupt(16);
        r16[cx] = pop();
        si = pop();
        if (--r16[cx]) {
            pc = 0x10746;
            break;
        }
        if (memory[ds*16+0x279] != 0x01) {
            pc = 0x1076A;
            break;
        }
        yield* sub_10776();
        yield* sub_1079D();
    case 0x1076A:
        di = 0x029a;
        si = 0x02ce;
        r16[cx] = 0x0033;
        rep_movsb_data_data_forward();
        return;
    } while (1);
}
function* sub_10776() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x029a;
        memory[ds*16+0x301] = 0x00;
        r16[cx] = 0x0010;
    case 0x10781:
        push(r16[cx]);
        r8[bh] = 0x09;
        r8[al] = memory[ds*16+si];
        imul8(r8[bh]);
        memory[ds*16+si] = r8[al];
        si += 1;
        r8[al] = memory[ds*16+si];
        imul8(r8[bh]);
        memory[ds*16+si] = r8[al];
        si += 1;
        r8[al] = memory[ds*16+si];
        imul8(r8[bh]);
        memory[ds*16+si] = r8[al];
        si += 1;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10781;
            break;
        }
        return;
    } while (1);
}
function* sub_1079D() {
    r16[bx] = r16[bx] ^ r16[bx];
    r16[cx] = 0x0010;
    r16[dx] = 0x029a;
    r8[al] = 0x12;
    r8[ah] = 0x10;
    interrupt(16);
}
function* sub_107AC() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = r16[dx] ^ r16[dx];
        r16[cx] = r16[dx];
        r8[ch] = r8[ah];
        r8[dh] = r8[ah];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] += r16[cx];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[dx] += r16[ax];
        di = r16[dx];
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5A);
        r16[cx] = 0x0027;
        r16[ax] = 0xa980;
        ds = r16[ax];
    case 0x107CE:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory16get(cs*16+si);
        si += 1;
        if (r8[al] == 0xff) {
            pc = 0x107EE;
            break;
        }
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = si;
        si = r16[ax];
        r16[ax] = di;
        yield* sub_10661();
        si = r16[bx];
        di = r16[ax];
        di += 1;
        pc = 0x107CE;
        break;
    case 0x107EE:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_107F1() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = r16[dx] ^ r16[dx];
        r16[cx] = r16[dx];
        r8[ch] = r8[ah];
        r8[dh] = r8[ah];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] += r16[cx];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[dx] += r16[ax];
        di = r16[dx];
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5A);
        r16[cx] = 0x0027;
        r16[ax] = 0xa600;
        ds = r16[ax];
    case 0x10813:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory16get(cs*16+si);
        si += 1;
        if (r8[al] == 0xff) {
            pc = 0x10833;
            break;
        }
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = si;
        si = r16[ax];
        r16[ax] = di;
        yield* sub_10661();
        si = r16[bx];
        di = r16[ax];
        di += 1;
        pc = 0x10813;
        break;
    case 0x10833:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10836() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = r16[dx] ^ r16[dx];
        r16[cx] = r16[dx];
        r8[ch] = r8[ah];
        r8[dh] = r8[ah];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] += r16[cx];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[dx] += r16[ax];
        di = r16[dx];
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5C);
        r16[cx] = 0x0027;
        r16[ax] = 0xa600;
        ds = r16[ax];
    case 0x10858:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory16get(cs*16+si);
        si += 1;
        if (r8[al] == 0xff) {
            pc = 0x10878;
            break;
        }
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = si;
        si = r16[ax];
        r16[ax] = di;
        yield* sub_10661();
        si = r16[bx];
        di = r16[ax];
        di += 1;
        pc = 0x10858;
        break;
    case 0x10878:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_1087B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0100;
        r16[ax] = 0x0000;
        r16[dx] = 0x0008;
        di = 0x2f73;
    case 0x10887:
        stosw_data_forward();
        r16[ax] += r16[dx];
        if (--r16[cx]) {
            pc = 0x10887;
            break;
        }
        return;
    } while (1);
}
function* sub_1088D() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        es = memory16get(ds*16+0x56);
        r16[ax] = 0xa680;
        ds = r16[ax];
        r16[cx] = 0x0020;
    case 0x1089B:
        bp = r16[cx];
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[cs*16+r16[bx]];
        if (r16s[ax] < signed16(0x00f8)) {
            pc = 0x108AA;
            break;
        }
        yield* sub_19593();
    case 0x108AA:
        r16[bx] += 1;
        r16[ax] <<= 1;
        r16[ax] += 0x2f73;
        si = r16[ax];
        si = memory16get(cs*16+si);
        r16[cx] = 0x001f;
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += r16[cx];
        movsb_video_video_forward();
        di += signed16(0xff20);
        r16[cx] = bp;
        if (--r16[cx]) {
            pc = 0x1089B;
            break;
        }
        di += 0x00e0;
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_108DD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x571c;
        di = 0x1e00;
        yield* sub_1088D();
        di = 0x0000;
        r16[bx] = 0x573c;
        r16[cx] = 0x001a;
    case 0x108EF:
        push(r16[cx]);
        yield* sub_1088D();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x108EF;
            break;
        }
        return;
    } while (1);
}
function* sub_108F7() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] |= r16[ax];
        if (r16[ax] == 0)
            return;
        push(ds);
        push(es);
        r16[dx] = r16[ax];
        bp = 0x0020;
        r16[bx] = 0x0008;
        es = memory16get(cs*16+0x5A);
        ds = memory16get(cs*16+0x56);
    case 0x1090F:
        r16[cx] = bp;
        rep_movsb_video_video_forward();
        di += r16[bx];
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x1090F;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_1091B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds*16+0x6C45);
        r16[dx] += 0x00c0;
        r16[dx] &= 0x00ff;
        if (r16s[dx] > memory16gets(ds*16+0x6C45)) {
            pc = 0x10969;
            break;
        }
        r16[ax] = r16[dx];
        si = 0x0000;
        di = 0x0144;
        r16[dx] = 0x0100;
        r16[dx] = r16[dx] - memory16get(ds*16+0x6C45);
        r16[dx] += r16[dx];
        r16[bx] = 0x3173;
        r16[bx] += r16[dx];
        di = di + memory16get(ds*16+r16[bx]);
        yield* sub_108F7();
        si = 0x0000;
        r16[dx] = memory16get(ds*16+0x6C45);
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        si += r16[dx];
        di = 0x0144;
        r16[ax] = 0x0100;
        r16[ax] = r16[ax] - memory16get(ds*16+0x6C45);
        yield* sub_108F7();
        return;
    case 0x10969:
        si = 0x0000;
        r16[dx] = memory16get(ds*16+0x6C45);
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        si += r16[dx];
        di = 0x0144;
        r16[ax] = 0x00c0;
        yield* sub_108F7();
        return;
    } while (1);
}
function* sub_10986() {
    r16[bx] = 0x573c;
    r16[ax] = memory16get(ds*16+0x6C45);
    r16[ax] &= 0x00f8;
    r16[ax] -= 0x0008;
    r16[ax] &= 0x00ff;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    di = r16[ax];
    yield* sub_1088D();
}
function* sub_109A5() {
    r16[bx] = 0x5a5c;
    r16[ax] = memory16get(ds*16+0x6C45);
    r16[ax] &= 0x00f8;
    r16[ax] += 0x00d0;
    r16[ax] &= 0x00ff;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    di = r16[ax];
    yield* sub_1088D();
}
function* sub_109C4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x3173;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x0100;
    case 0x109CC:
        stosw_data_forward();
        r16[ax] += 0x0028;
        if (--r16[cx]) {
            pc = 0x109CC;
            break;
        }
        return;
    } while (1);
}
function* sub_109D3() {
    memory16set(ds*16+0x5A, 0xa000);
    memory16set(ds*16+0x5C, 0xa200);
    memory16set(ds*16+0x5E, 0x0000);
    memory16set(ds*16+0x60, 0x2000);
}
function* sub_109EE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = memory16get(ds*16+0x5A);
        r16[dx] = memory16get(ds*16+0x5C);
        memory16set(ds*16+0x5C, r16[ax]);
        memory16set(ds*16+0x5A, r16[dx]);
        r16[ax] = memory16get(ds*16+0x5E);
        r16[dx] = memory16get(ds*16+0x60);
        memory16set(ds*16+0x60, r16[ax]);
        memory16set(ds*16+0x5E, r16[dx]);
        r16[cx] = memory16get(ds*16+0x60);
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0040;
        es = r16[ax];
        r16[dx] = memoryBiosGet16(es, 0x63);
        r16[dx] += 0x0006;
    case 0x10A22:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x10A22;
            break;
        }
    case 0x10A27:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x10A27;
            break;
        }
        r16[dx] -= 0x0006;
        flags.interrupt = false;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = r8[ch];
        out8(r16[dx], r8[al]);
        r16[dx] -= 1;
        r8[al] = 0x0d;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = r8[cl];
        out8(r16[dx], r8[al]);
        flags.interrupt = true;
        r8[ah] = r8[ch];
        r16[ax] <<= 1;
        memoryBiosSet16(es, 0x4E, r16[ax]);
        r16[ax] = 0x0040;
        es = r16[ax];
        r16[dx] = memoryBiosGet16(es, 0x63);
        r16[dx] += 0x0006;
    case 0x10A55:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x10A55;
            break;
        }
    case 0x10A5A:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x10A5A;
            break;
        }
        r16[ax] = pop();
        r16[dx] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10A67() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9173) != 0x0000) {
            pc = 0x10A6F;
            break;
        }
        return;
    case 0x10A6F:
        r16[bx] = memory16get(ds*16+0x9175);
        r16[cx] = 0x0008;
    case 0x10A76:
        push(r16[cx]);
        r8[al] = memory[ds*16+r16[bx]];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x10AD2;
            break;
        }
        if (flags.sign) {
            pc = 0x10ADC;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
        r8[dl] = memory[ds*16+r16[bx] + 1];
        r8[cl] = r8[dl];
        r8[cl] += 1;
        r8[cl] &= 0x03;
        r8[dl] &= 0xfc;
        r8[dl] |= r8[cl];
        memory[ds*16+r16[bx] + 1] = r8[dl];
        di = memory16get(ds*16+r16[bx] + 4);
        bp = memory16get(cs*16+r16[bx] + 6);
        si = si ^ si;
        push(ds);
        push(es);
        es = memory16get(ds*16+0x56);
        r16[ax] = 0xa700;
        ds = r16[ax];
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        si = r16[dx];
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        di += 0x001f;
        movsb_video_video_forward();
        es = pop();
        ds = pop();
    case 0x10AD2:
        r16[bx] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10A76;
            break;
        }
        pc = 0x10AE2;
        break;
    case 0x10ADC:
        r16[bx] = 0x54fa;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10A76;
            break;
        }
    case 0x10AE2:
        memory16set(ds*16+0x9175, r16[bx]);
        return;
    } while (1);
}
function* sub_10AE7() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[bx] = 0x573c;
        di = 0x0144;
        es = memory16get(ds*16+0x56);
        r16[ax] = 0xa680;
        ds = r16[ax];
        r16[cx] = 0x0018;
        r16[dx] = memory16get(cs*16+0x8BF0);
        r16[dx] &= 0x0007;
        if (r16[dx] == 0) {
            pc = 0x10B43;
            break;
        }
        si = r16[dx];
        bp = 0x0020;
        r16[dx] = r16[dx] ^ 0x0007;
    case 0x10B0D:
        push(si);
        push(di);
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[cs*16+r16[bx]];
        r16[bx] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        si += r16[ax];
        push(r16[dx]);
    case 0x10B1E:
        movsb_video_video_forward();
        di += 0x0027;
        r16[dx] -= 1;
        if (r16s[dx] >= 0) {
            pc = 0x10B1E;
            break;
        }
        r16[dx] = pop();
        di = pop();
        si = pop();
        di += 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10B0D;
            break;
        }
        r16[dx] += 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[ax] = r16[dx];
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] += r16[ax];
        r16[dx] += 0xffe0;
        di += r16[dx];
        pc = 0x10B80;
        break;
        _STOP_("db 90h");
    case 0x10B43:
        bp = 0x0020;
    case 0x10B46:
        push(si);
        push(di);
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[cs*16+r16[bx]];
        r16[bx] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        si = r16[ax];
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        movsb_video_video_forward();
        di += 0x0027;
        di = pop();
        si = pop();
        di += 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10B46;
            break;
        }
        di += 0x0120;
    case 0x10B80:
        if (--r16[cx]) {
            pc = 0x10B43;
            break;
        }
        r16[dx] = memory16get(cs*16+0x8BF0);
        r16[dx] &= 0x0007;
        if (r16[dx] == 0) {
            pc = 0x10BAE;
            break;
        }
        bp = 0x0020;
    case 0x10B8F:
        push(si);
        push(di);
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[cs*16+r16[bx]];
        r16[bx] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        si = r16[ax];
        push(r16[dx]);
    case 0x10BA0:
        movsb_video_video_forward();
        di += 0x0027;
        r16[dx] -= 1;
        if (r16s[dx] >= 0) {
            pc = 0x10BA0;
            break;
        }
        r16[dx] = pop();
        di = pop();
        si = pop();
        di += 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10B8F;
            break;
        }
    case 0x10BAE:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10BB1() {
    r16[ax] = memory16get(ds*16+0x5A);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+0x56);
    memory16set(ds*16+0x5A, r16[ax]);
    yield* indirectCall(ds, memory16get(ds*16+0x3E));
    r16[ax] = pop();
    memory16set(ds*16+0x5A, r16[ax]);
}
function* sub_10BC4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = memory16get(ds*16+0x96F4);
        push(r16[cx]);
        memory16set(ds*16+0x96F4, 0x0001);
        push(r16[ax]);
        push(r16[dx]);
        yield* indirectCall(ds, memory16get(ds*16+0x24));
        memory16set(ds*16+0xB1C, 0x0000);
        yield* indirectCall(ds, memory16get(ds*16+0x3E));
        memory16set(ds*16+0xB1C, 0x0001);
        r16[dx] = pop();
        r16[ax] = pop();
        yield* sub_19351();
        yield* sub_19214();
        yield* sub_10AE7();
        yield* sub_1618F();
        yield* sub_15FE4();
        memory[ds*16+0x5B3E] = 0x01;
        yield* sub_15F40();
        memory[ds*16+0x5B3E] = 0x00;
        yield* sub_10BB1();
        yield* sub_19AF6();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        si = 0x0162;
        r16[cx] = 0x0010;
    case 0x10C15:
        push(r16[cx]);
        push(si);
        yield* sub_10C98();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        si = pop();
        r16[cx] = pop();
        si += signed16(0xfffe);
        if (--r16[cx]) {
            pc = 0x10C15;
            break;
        }
        yield* sub_17047();
        r16[cx] = pop();
        memory16set(ds*16+0x96F4, r16[cx]);
        return;
    } while (1);
}
function* sub_10C2E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = memory16get(ds*16+0x96F4);
        push(r16[cx]);
        memory16set(ds*16+0x96F4, 0x0001);
        push(r16[ax]);
        push(r16[dx]);
        yield* indirectCall(ds, memory16get(ds*16+0x24));
        memory16set(ds*16+0xB1C, 0x0000);
        yield* indirectCall(ds, memory16get(ds*16+0x3E));
        memory16set(ds*16+0xB1C, 0x0001);
        r16[dx] = pop();
        r16[ax] = pop();
        yield* sub_19351();
        yield* sub_19214();
        yield* sub_1618F();
        yield* sub_10AE7();
        yield* sub_15FE4();
        memory[ds*16+0x5B3E] = 0x01;
        yield* sub_15F40();
        memory[ds*16+0x5B3E] = 0x00;
        yield* sub_10BB1();
        yield* sub_19AF6();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        si = 0x0144;
        r16[cx] = 0x0010;
    case 0x10C7F:
        push(r16[cx]);
        push(si);
        yield* sub_10CCD();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        si = pop();
        r16[cx] = pop();
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x10C7F;
            break;
        }
        yield* sub_17047();
        r16[cx] = pop();
        memory16set(ds*16+0x96F4, r16[cx]);
        return;
    } while (1);
}
function* sub_10C98() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[bx] = 0x0144;
        di = r16[bx];
        bp = 0x00c0;
        es = memory16get(ds*16+0x5A);
        r16[ax] = memory16get(ds*16+0x56);
        r16[dx] = memory16get(ds*16+0x5C);
    case 0x10CAD:
        ds = r16[ax];
        movsb_video_video_forward();
        movsb_video_video_forward();
        ds = r16[dx];
        push(si);
        si = r16[bx];
        r16[cx] = 0x001e;
        rep_movsb_video_video_forward();
        r16[bx] = si;
        si = pop();
        r16[bx] += 0x000a;
        si += 0x0026;
        di += 0x0008;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10CAD;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10CCD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[bx] = 0x0146;
        di = 0x0144;
        bp = 0x00c0;
        es = memory16get(ds*16+0x5A);
        r16[ax] = memory16get(ds*16+0x56);
        r16[dx] = memory16get(ds*16+0x5C);
    case 0x10CE3:
        ds = r16[dx];
        push(si);
        si = r16[bx];
        r16[cx] = 0x001e;
        rep_movsb_video_video_forward();
        r16[bx] = si;
        si = pop();
        ds = r16[ax];
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[bx] += 0x000a;
        si += 0x0026;
        di += 0x0008;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10CE3;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10D03() {
    var cs = _seg001;
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memory16get(cs*16+0x5A);
    si = 0x0100;
    lodsb_video_forward();
    di = di ^ di;
    r16[cx] = 0x1f40;
    rep_stosb_video_forward();
    es = pop();
    ds = pop();
    yield* sub_19B1C();
    yield* indirectCall(ds, memory16get(ds*16+0x1C));
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memory16get(cs*16+0x5A);
    si = 0x0100;
    lodsb_video_forward();
    di = di ^ di;
    r16[cx] = 0x1f40;
    rep_stosb_video_forward();
    es = pop();
    ds = pop();
}
function* sub_10D3D() {
    r16[ax] = memory16get(ds*16+0x62);
    r16[cx] = 0x0000;
    r16[dx] = 0x010a;
    yield* sub_1A65B();
    yield* sub_10D5C();
    r16[ax] = memory16get(ds*16+0x62);
    r16[cx] = 0x0000;
    r16[dx] = 0x0116;
    yield* sub_1A65B();
    yield* sub_10DAA();
}
function* sub_10D5C() {
    push(ds);
    push(es);
    r16[ax] = memory16get(ds*16+0x62);
    ds = r16[ax];
    r16[ax] = 0xa780;
    es = r16[ax];
    si = si ^ si;
    di = di ^ di;
    push(r16[dx]);
    r16[ax] = 0x0005;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    es = pop();
    ds = pop();
}
function* sub_10DAA() {
    push(ds);
    push(es);
    r16[ax] = memory16get(ds*16+0x62);
    ds = r16[ax];
    r16[ax] = 0xa780;
    es = r16[ax];
    si = si ^ si;
    di = di ^ di;
    push(r16[dx]);
    r16[ax] = 0x0005;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    di = di ^ di;
    rep_movsw_video_data_forward();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    push(r16[dx]);
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    es = pop();
    ds = pop();
}
function* sub_10DF8() {
    push(ds);
    push(es);
    r16[ax] = 0xa780;
    ds = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    si = si ^ si;
    di = si;
    r16[cx] = 0x1f40;
    rep_movsb_video_video_forward();
    r16[ax] = 0xa780;
    ds = r16[ax];
    r16[ax] = 0xa200;
    es = r16[ax];
    si = si ^ si;
    di = si;
    r16[cx] = 0x1f40;
    rep_movsb_video_video_forward();
    es = pop();
    ds = pop();
}
function* sub_10E23() {
    r16[dx] = r16[dx] ^ r16[dx];
    r8[dl] = r8[ah];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[cx] = r16[dx];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] += r16[cx];
    r8[cl] = 0x03;
    r16[dx] <<= r8[cl];
    di = r16[dx];
    r8[ah] = r8[ah] ^ r8[ah];
    di += r16[ax];
}
function* sub_10E40() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[ax] = 0xa600;
        ds = r16[ax];
        es = memory16get(cs*16+0x56);
    case 0x10E4C:
        push(r16[cx]);
        push(si);
        push(di);
    case 0x10E4F:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory16get(cs*16+si);
        si += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        push(si);
        push(di);
        si = r16[ax];
        push(r16[cx]);
        r16[cx] = 0x0027;
        yield* sub_10661();
        r16[cx] = pop();
        di = pop();
        si = pop();
        di += 1;
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x10E4F;
            break;
        }
        di = pop();
        di += 0x0140;
        si = pop();
        si += 0x0020;
        r16[cx] = pop();
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x10E4C;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10E7F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5A);
        ds = memory16get(ds*16+0x56);
        di = 0x0144;
        si = di;
        bp = 0x00c0;
    case 0x10E91:
        r16[cx] = 0x0020;
        push(si);
        push(di);
        rep_movsb_video_video_forward();
        di = pop();
        si = pop();
        si += 0x0028;
        di += 0x0028;
        bp -= 1;
        if (bp != 0) {
            pc = 0x10E91;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10EA6() {
    var cs = _seg001;
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memory16get(cs*16+0x56);
    si = 0x0100;
    lodsb_video_forward();
    di = di ^ di;
    r16[cx] = 0x1f40;
    rep_stosb_video_forward();
    es = pop();
    ds = pop();
}
function* sub_10EC0() {
    r16[dx] = memory16get(ds*16+0x5A);
    push(r16[dx]);
    r16[dx] = memory16get(ds*16+0x56);
    memory16set(ds*16+0x5A, r16[dx]);
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[dx] = pop();
    memory16set(ds*16+0x5A, r16[dx]);
}
function* sub_10EE8() {
    var cs = _seg001;
    r16[ax] = memory16get(cs*16+0x96F4);
    if (r16[ax] == 0x0001)
        return;
    r16[ax] -= 1;
    memory16set(cs*16+0x96F4, r16[ax]);
    return;
}
function* sub_11162() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5A);
        si = 0x0b00;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
    case 0x1117A:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x11196;
            break;
        }
        if (r16[ax] == 0) {
            pc = 0x11191;
            break;
        }
        if (memory16get(ds*16+si + 10) == 0x00fe) {
            pc = 0x11191;
            break;
        }
        push(ds);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x40));
        si = pop();
        ds = pop();
    case 0x11191:
        si += 0x001c;
        pc = 0x1117A;
        break;
    case 0x11196:
        si = 0x0b56;
    case 0x11199:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r8[ah] & 0x80);
        r8[ah] |= r8[ah];
        if (flags.sign) {
            pc = 0x111B7;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x111B2;
            break;
        }
        if (memory16get(ds*16+si + 10) == 0x00fe) {
            pc = 0x111B2;
            break;
        }
        push(ds);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x40));
        si = pop();
        ds = pop();
    case 0x111B2:
        si += 0x0034;
        pc = 0x11199;
        break;
    case 0x111B7:
        si = 0x0c28;
    case 0x111BA:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r8[ah] & 0x80);
        r8[ah] |= r8[ah];
        if (flags.sign) {
            pc = 0x111D8;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x111D3;
            break;
        }
        if (memory16get(ds*16+si + 10) == 0x00fe) {
            pc = 0x111D3;
            break;
        }
        push(ds);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x40));
        si = pop();
        ds = pop();
    case 0x111D3:
        si += 0x0034;
        pc = 0x111BA;
        break;
    case 0x111D8:
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_111F1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = bp ^ bp;
        r16[ax] = memory16get(ds*16+si + 4);
        r16[ax] -= 0x0038;
        r16[dx] = memory16get(ds*16+0x8BF0);
        r16[dx] &= 0x0007;
        r16[ax] -= r16[dx];
        if (r16s[ax] >= signed16(0x0008)) {
            pc = 0x1122C;
            break;
        }
        r16[cx] = 0x0008;
        r16[cx] -= r16[ax];
        r16[ax] = r16[cx];
        r16[cx] = -r16[cx];
        r16[cx] += 0x0015;
        if (r16s[cx] > 0) {
            pc = 0x11218;
            break;
        }
        return;
    case 0x11218:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        bp = r16[ax];
        r16[ax] = 0x0140;
        pc = 0x11252;
        break;
    case 0x1122C:
        if (r16s[ax] <= signed16(0x00b3)) {
            pc = 0x11241;
            break;
        }
        r16[cx] = 0x00b3;
        r16[cx] -= r16[ax];
        r16[cx] += 0x0015;
        if (r16s[cx] > 0) {
            pc = 0x1123E;
            break;
        }
        return;
    case 0x1123E:
        pc = 0x11244;
        break;
        _STOP_("db 90h");
    case 0x11241:
        r16[cx] = 0x0015;
    case 0x11244:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
    case 0x11252:
        di = r16[ax];
        r16[ax] = memory16get(ds*16+si + 2);
        r16[ax] += 0x0020;
        r16[ax] &= 0xfff8;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        di += r16[ax];
        r16[ax] = memory16get(ds*16+si + 10);
        if (r16s[ax] < signed16(0x0080)) {
            pc = 0x11270;
            break;
        }
        r16[ax] -= 0x0040;
    case 0x11270:
        r16[bx] = 0x01a4;
        imul16(r16[bx]);
        r16[bx] = memory16get(ds*16+si + 2);
        r16[bx] += 0x0020;
        r16[bx] &= 0x0006;
        r16[bx] += 0x0062;
        ds = memory16get(ds*16+r16[bx]);
        si = r16[ax];
        si += bp;
        bp = 0x0024;
        r8[dh] = 0x03;
    case 0x1128D:
        push(r16[cx]);
        r16[cx] = 0x0004;
    case 0x11291:
        r8[ah] = memory[ds*16+si];
        r8[ah] |= r8[ah];
        if (r8[ah] == 0) {
            pc = 0x112C9;
            break;
        }
        r8[al] = 0x08;
        r8[dl] = 0xce;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[ah] = memoryVideoGet(es, di);
        r8[ah] = 0x01;
        out16(r16[dx], r16[ax]);
        r8[ah] = memory[ds*16+si + 1];
        memoryVideoSet(es, di, r8[ah]);
        r8[ah] = 0x02;
        out16(r16[dx], r16[ax]);
        r8[ah] = memory[ds*16+si + 2];
        memoryVideoSet(es, di, r8[ah]);
        r8[ah] = 0x04;
        out16(r16[dx], r16[ax]);
        r8[ah] = memory[ds*16+si + 3];
        memoryVideoSet(es, di, r8[ah]);
        r8[ah] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[ah] = memory[ds*16+si + 4];
        memoryVideoSet(es, di, r8[ah]);
    case 0x112C9:
        di += 1;
        si += 0x0005;
        if (--r16[cx]) {
            pc = 0x11291;
            break;
        }
        di += bp;
        r16[cx] = pop();
        r16[cx] -= 1;
        if (r16[cx] != 0) {
            pc = 0x1128D;
            break;
        }
        return;
    } while (1);
}
function* sub_112D6() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        ds = memory16get(ds*16+0x62);
        bp = 0x0064;
        di = di ^ di;
        si = si ^ si;
        r16[cx] = 0x0888;
    case 0x112E6:
        push(r16[cx]);
        push(si);
        push(di);
        r8[ah] = memory[ds*16+si];
        r8[al] = memory[ds*16+si + 5];
        r8[bh] = memory[ds*16+si + 10];
        r8[bl] = 0x00;
        push(bp);
        r16[cx] = 0x0003;
    case 0x112F7:
        flags.carry = false;
        rcr8(ah, 1);
        rcr8(al, 1);
        rcr8(bh, 1);
        rcr8(bl, 1);
        flags.carry = false;
        rcr8(ah, 1);
        rcr8(al, 1);
        rcr8(bh, 1);
        rcr8(bl, 1);
        es = memory16get(cs*16+bp + 0);
        bp += 1;
        bp += 1;
        memory[es*16+di] = r8[ah];
        memory[es*16+di + 5] = r8[al];
        memory[es*16+di + 10] = r8[bh];
        memory[es*16+di + 15] = r8[bl];
        if (--r16[cx]) {
            pc = 0x112F7;
            break;
        }
        bp = pop();
        si += 1;
        di += 1;
        r16[cx] = 0x0004;
    case 0x11326:
        push(r16[cx]);
        r8[ah] = memory[ds*16+si];
        r8[al] = memory[ds*16+si + 5];
        r8[bh] = memory[ds*16+si + 10];
        r8[bl] = 0x00;
        push(bp);
        r16[cx] = 0x0003;
    case 0x11335:
        flags.carry = false;
        rcr8(ah, 1);
        rcr8(al, 1);
        rcr8(bh, 1);
        rcr8(bl, 1);
        flags.carry = false;
        rcr8(ah, 1);
        rcr8(al, 1);
        rcr8(bh, 1);
        rcr8(bl, 1);
        es = memory16get(cs*16+bp + 0);
        bp += 1;
        bp += 1;
        memory[es*16+di] = r8[ah];
        memory[es*16+di + 5] = r8[al];
        memory[es*16+di + 10] = r8[bh];
        memory[es*16+di + 15] = r8[bl];
        if (--r16[cx]) {
            pc = 0x11335;
            break;
        }
        bp = pop();
        si += 1;
        di += 1;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x11326;
            break;
        }
        di = pop();
        si = pop();
        si += 0x0014;
        di += 0x0014;
        r16[cx] = pop();
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x11373;
            break;
        }
        pc = 0x112E6;
        break;
    case 0x11373:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_11376() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        es = memory16get(ds*16+0x5A);
        si = 0x0b00;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        si = 0x9bd6;
    case 0x11391:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x113B0;
            break;
        }
        if (r16[ax] == 0) {
            pc = 0x113AA;
            break;
        }
        if (memory16get(ds*16+si + 10) == 0x00fe) {
            pc = 0x113AA;
            break;
        }
        push(r16[bx]);
        push(ds);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x40));
        si = pop();
        ds = pop();
        r16[bx] = pop();
    case 0x113AA:
        si += 0x001a;
        pc = 0x11391;
        break;
    case 0x113B0:
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_15F40() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x762D) != 0x0001) {
            pc = 0x15F52;
            break;
        }
        if (memory16get(ds*16+0x762F) == 0x0001)
            return;
        yield* sub_17A31();
        return;
    case 0x15F52:
        r16[bx] = memory16get(ds*16+0x5B3C);
        r16[bx] |= r16[bx];
        if (r16[bx] != 0) {
            pc = 0x15F5B;
            break;
        }
        return;
    case 0x15F5B:
        r16[cx] = memory16get(ds*16+0x8BF0);
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] += 0x0025;
    case 0x15F68:
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x15F6F;
            break;
        }
        return;
    case 0x15F6F:
        r8[ah] = r8[al];
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] < r8[cl]) {
            pc = 0x15F79;
            break;
        }
        return;
    case 0x15F79:
        if (!(r8[ah] & 0x80)) {
            pc = 0x15F90;
            break;
        }
        r16[bx] += 1;
    case 0x15F7F:
        r16[bx] += 1;
    case 0x15F80:
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x15F68;
            break;
        }
    case 0x15F87:
        r16[bx] += 0x0004;
        r8[al] -= 1;
        if (r8[al] != 0) {
            pc = 0x15F87;
            break;
        }
        pc = 0x15F68;
        break;
    case 0x15F90:
        r16[bx] += 1;
        if (!(memory[ds*16+r16[bx]] & 0x80)) {
            pc = 0x15FD4;
            break;
        }
        r8[al] = memory[ds*16+0x5B3E];
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x15FB9;
            break;
        }
        push(r16[cx]);
        r16[cx] = memory16get(ds*16+0x8BF0);
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r8[ah] = r8[cl];
        r16[bx] -= 1;
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[al] -= r8[ah];
        r16[cx] = pop();
        if (r8[al] < 0x05) {
            pc = 0x15FB9;
            break;
        }
        if (r8[al] < 0x22) {
            pc = 0x15F7F;
            break;
        }
    case 0x15FB9:
        r16[bx] -= 1;
        r16[bx] -= 1;
        push(r16[bx]);
    case 0x15FBC:
        si = r16[bx];
        yield* sub_16205();
        r16[bx] = pop();
    case 0x15FC2:
        r16[bx] += 1;
        r16[bx] += 1;
        r16[bx] += 1;
        r16[cx] = memory16get(ds*16+0x8BF0);
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] += 0x0025;
        pc = 0x15F80;
        break;
    case 0x15FD4:
        r16[bx] -= 1;
        r16[bx] -= 1;
        push(r16[bx]);
        si = r16[bx];
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_16222();
        r16[bx] = pop();
        if (!flags.carry) {
            pc = 0x15FC2;
            break;
        }
        push(r16[bx]);
        pc = 0x15FBC;
        break;
        return;
    } while (1);
}
function* sub_15FE4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x8BFC);
        memory16set(ds*16+0x5B3C, r16[bx]);
        r16[bx] |= r16[bx];
        if (r16[bx] != 0) {
            pc = 0x15FF1;
            break;
        }
        return;
    case 0x15FF1:
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x15FF8;
            break;
        }
        return;
    case 0x15FF8:
        r16[bx] += 1;
        r16[cx] = memory16get(ds*16+0x8BF0);
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        if (r8[cl] == memory[ds*16+r16[bx]]) {
            pc = 0x1601C;
            break;
        }
        if (r8[cl] < memory[ds*16+r16[bx]]) {
            pc = 0x1601C;
            break;
        }
        r16[bx] += 0x0002;
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x15FF1;
            break;
        }
    case 0x16013:
        r16[bx] += 0x0004;
        r8[al] -= 1;
        if (r8[al] != 0) {
            pc = 0x16013;
            break;
        }
        pc = 0x15FF1;
        break;
    case 0x1601C:
        r16[bx] -= 1;
        memory16set(ds*16+0x5B3C, r16[bx]);
        return;
    } while (1);
}
function* sub_16022() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_16126();
        if (!flags.carry) {
            pc = 0x16028;
            break;
        }
        return;
    case 0x16028:
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 50, r16[ax]);
        memory16set(ds*16+di + 24, r16[ax]);
        memory16set(ds*16+di + 34, r16[ax]);
        memory16set(ds*16+di + 28, si);
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = memory[ds*16+si];
        r16[cx] += r16[cx];
        r16[bx] = 0x117e;
        r16[bx] += r16[cx];
        r16[bx] = memory16get(ds*16+r16[bx]);
        r8[al] = memory[ds*16+r16[bx]];
        _cbw();
        memory16set(ds*16+di + 30, r16[ax]);
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        _cbw();
        memory16set(ds*16+di + 32, r16[ax]);
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] &= 0xc0;
        r8[dl] = r8[al];
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+si + 3];
        r8[al] &= 0x3c;
        if (r8[al] != 0x10) {
            pc = 0x16072;
            break;
        }
        memory16set(ds*16+di + 50, 0x0060);
        if (!(memory[ds*16+si + 3] & 0x40)) {
            pc = 0x16072;
            break;
        }
        memory16set(ds*16+di + 28, 0x0000);
    case 0x16072:
        r8[al] |= 0x01;
        r8[al] |= r8[dl];
        memory[ds*16+di] = r8[al];
        r8[al] &= 0x3f;
        r8[dl] = r8[al];
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] += r8[al];
        r8[al] += r8[al];
        r8[al] |= r8[dl];
        memory[ds*16+di + 44] = r8[al];
        r16[bx] += 1;
        r16[ax] = memory16get(ds*16+r16[bx]);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+di + 36, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx]);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+di + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx]);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+di + 40, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+di + 42, r16[ax]);
        r8[al] = memory[ds*16+si + 2];
        r16[ax] &= 0x001f;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (!(memory[ds*16+si + 2] & 0x20)) {
            pc = 0x160BA;
            break;
        }
        r16[ax] += 1;
        r16[ax] += 1;
        r16[ax] += 1;
        r16[ax] += 1;
    case 0x160BA:
        memory16set(ds*16+di + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r8[dl] = r8[al];
        r8[al] = memory[ds*16+si + 1];
        r8[al] -= r8[dl];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (!(memory[ds*16+si + 2] & 0x40)) {
            pc = 0x160DC;
            break;
        }
        r16[ax] += 1;
        r16[ax] += 1;
        r16[ax] += 1;
    case 0x160DC:
        memory16set(ds*16+di + 4, r16[ax]);
        memory[ds*16+si] |= 0x80;
        r8[al] = memory[ds*16+di];
        r8[al] &= 0x3f;
        r8[ah] = 0x29;
        if (r8[al] != 0x21) {
            pc = 0x160F2;
            break;
        }
        memory[ds*16+di + 10] = r8[ah];
        return;
    case 0x160F2:
        r8[ah] = 0x27;
        if (r8[al] != 0x29) {
            pc = 0x160FE;
            break;
        }
        memory[ds*16+di + 10] = r8[ah];
        return;
    case 0x160FE:
        r8[ah] = 0x28;
        if (r8[al] != 0x2d) {
            pc = 0x1610A;
            break;
        }
        memory[ds*16+di + 10] = r8[ah];
        return;
    case 0x1610A:
        push(si);
        push(di);
        push(r16[bx]);
        si = di;
        r16[ax] = memory16get(ds*16+si + 24);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+si + 22);
        push(r16[ax]);
        yield* sub_1718E();
        r16[ax] = pop();
        memory16set(ds*16+si + 22, r16[ax]);
        r16[ax] = pop();
        memory16set(ds*16+si + 24, r16[ax]);
        r16[bx] = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_16126() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x0c28;
    case 0x16129:
        r16[ax] = memory16get(ds*16+di);
        flags.sign = !!(r8[ah] & 0x80);
        r8[ah] |= r8[ah];
        if (flags.sign) {
            pc = 0x16138;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x1613A;
            break;
        }
        di += 0x0034;
        pc = 0x16129;
        break;
    case 0x16138:
        flags.carry = true;
        return;
    case 0x1613A:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1613C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = memory16get(ds*16+si + 2);
        if (r16s[cx] < signed16(0x0000)) {
            pc = 0x1615C;
            break;
        }
        if (r16s[cx] > signed16(0x00e8)) {
            pc = 0x1615C;
            break;
        }
        r16[cx] = memory16get(ds*16+si + 4);
        if (r16s[cx] < signed16(0x0000)) {
            pc = 0x1615C;
            break;
        }
        if (r16s[cx] >= signed16(0x0128)) {
            pc = 0x1615C;
            break;
        }
        r16[cx] = pop();
        flags.carry = false;
        return;
    case 0x1615C:
        r16[cx] = pop();
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1615F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory16get(ds*16+si) & 0x0001))
            return;
        r16[bx] = memory16get(ds*16+si + 28);
        r16[bx] |= r16[bx];
        if (r16[bx] == 0) {
            pc = 0x1616F;
            break;
        }
        memory[ds*16+r16[bx]] &= 0x7f;
    case 0x1616F:
        memory16set(ds*16+si, 0x0000);
        return;
    } while (1);
}
function* sub_16174() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory16get(ds*16+si) & 0x0001))
            return;
        r16[bx] = memory16get(ds*16+si + 28);
        r16[bx] |= r16[bx];
        if (r16[bx] == 0) {
            pc = 0x1618A;
            break;
        }
        if (memory[ds*16+r16[bx] + 3] & 0x40) {
            pc = 0x1618A;
            break;
        }
        memory[ds*16+r16[bx]] &= 0x7f;
    case 0x1618A:
        memory16set(ds*16+si, 0x0000);
        return;
    } while (1);
}
function* sub_1618F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        si = 0x0b56;
    case 0x16193:
        if (memory16get(ds*16+si) == 0xffff) {
            pc = 0x161AD;
            break;
        }
        if (!(memory16get(ds*16+si) & 0x0001)) {
            pc = 0x161A8;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 28);
        memory[ds*16+r16[bx]] &= 0x7f;
        memory16set(ds*16+si, 0x0000);
    case 0x161A8:
        si += 0x0034;
        pc = 0x16193;
        break;
    case 0x161AD:
        si = 0x0c28;
    case 0x161B0:
        if (memory16get(ds*16+si) == 0xffff) {
            pc = 0x161CA;
            break;
        }
        if (!(memory16get(ds*16+si) & 0x0001)) {
            pc = 0x161C5;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 28);
        memory[ds*16+r16[bx]] &= 0x7f;
        memory16set(ds*16+si, 0x0000);
    case 0x161C5:
        si += 0x0034;
        pc = 0x161B0;
        break;
    case 0x161CA:
        si = pop();
        return;
    } while (1);
}
function* loc_161CE() {
    memory[ds*16+si] |= 0x80;
    memory16set(ds*16+0x5DCC, 0x0001);
    memory16set(ds*16+0x65E1, 0x0018);
    si = 0x661d;
    di = 0x6624;
    r16[cx] = 0x0006;
    rep_movsb_data_data_forward();
    r16[ax] = 0x0013;
    yield* sub_1AECD();
    return;
}
function* loc_161EF() {
    memory[ds*16+si] |= 0x80;
    memory16set(ds*16+0x5DCC, 0x0000);
    si = 0x6624;
    yield* sub_16BC7();
    r16[ax] = 0x0001;
    yield* sub_1AECD();
}
function* sub_16205() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = r8[ah] ^ r8[ah];
        r8[al] = memory[ds*16+si];
        if (r16[ax] == 0x0078)
            {
            yield* loc_161CE();
            return;
        }
        if (r16[ax] == 0x007c)
            {
            yield* loc_161EF();
            return;
        }
        if (r16s[ax] >= signed16(0x0075)) {
            pc = 0x1621C;
            break;
        }
        yield* sub_16022();
        return;
    case 0x1621C:
        yield* sub_1691D();
        return;
    } while (1);
}
function* sub_16222() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        r8[al] = memory[ds*16+si + 3];
        r8[al] &= 0x03;
        if (r8[al] != 0) {
            pc = 0x1623E;
            break;
        }
        return;
    case 0x1623E:
        si += 0x0004;
        push(memory16get(ds*16+0x54F8));
        push(r16[ax]);
        memory16set(ds*16+0x54F8, pop());
        r16[ax] = pop();
        r8[al] = memory[ds*16+si + 2];
        r8[cl] = r8[al];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] &= 0x0f;
        r8[al] += 1;
        r8[ah] = r8[al];
        r16[dx] = memory16get(ds*16+0x8BF0);
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r8[al] = memory[ds*16+si + 1];
        r8[al] -= r8[dl];
        if (r8s[al] >= 0) {
            pc = 0x1627D;
            break;
        }
        flags.sign = signed8(r8[al] + r8[ah]) < 0;
        r8[al] += r8[ah];
        if (!flags.sign) {
            pc = 0x16277;
            break;
        }
    case 0x16273:
        flags.carry = false;
        pc = 0x163F5;
        break;
    case 0x16277:
        if (r8[al] == 0) {
            pc = 0x16273;
            break;
        }
        r8[ah] = r8[al];
        r8[al] = r8[al] ^ r8[al];
    case 0x1627D:
        if (r8[al] >= 0x20) {
            pc = 0x16273;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        r8[bl] = r8[al];
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        r8[ah] += r8[ah];
        r8[ah] += r8[ah];
        r8[ah] += r8[ah];
        r8[cl] &= 0x0f;
        r8[cl] += 1;
        r8[cl] += r8[cl];
        r8[cl] += r8[cl];
        r8[cl] += r8[cl];
        r8[dl] = r8[cl];
        r8[dh] = memory[ds*16+si];
        push(si);
        r8[al] = memory[ds*16+si + 3];
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x162CD;
            break;
        }
        push(r16[bx]);
        r8[cl] = r8[al];
        push(r16[cx]);
        si = 0x0b1c;
        yield* sub_16407();
        r16[cx] = pop();
        r8[al] = r8[cl];
        r16[bx] = pop();
        if (!flags.carry) {
            pc = 0x162CD;
            break;
        }
    case 0x162B8:
        si = pop();
        r8[al] = memory[ds*16+si + 3];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (!flags.sign) {
            pc = 0x162C3;
            break;
        }
        pc = 0x163F5;
        break;
    case 0x162C3:
        r8[al] &= 0x40;
        if (r8[al] != 0) {
            pc = 0x162CB;
            break;
        }
        memory[ds*16+si + 3] |= 0x80;
    case 0x162CB:
        flags.carry = true;
        return;
    case 0x162CD:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x162EC;
            break;
        }
        r8[cl] = r8[al];
        if (memory16get(ds*16+0xB00) != 0x0001) {
            pc = 0x162EA;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_164A0();
        r16[bx] = pop();
        r16[cx] = pop();
        if (!flags.carry) {
            pc = 0x162EA;
            break;
        }
        memory[ds*16+0x5E20] = 0xff;
        pc = 0x162B8;
        break;
    case 0x162EA:
        r8[al] = r8[cl];
    case 0x162EC:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x1630F;
            break;
        }
        r8[cl] = r8[al];
        if (memory16get(ds*16+0xB38) != 0x0002) {
            pc = 0x1630D;
            break;
        }
        r8[al] = memory[ds*16+0xB4A];
        if (r8s[al] <= signed8(0x01)) {
            pc = 0x1630D;
            break;
        }
        if (r8s[al] > signed8(0x04)) {
            pc = 0x1630D;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_164E1();
        r16[bx] = pop();
        r16[cx] = pop();
        if (flags.carry) {
            pc = 0x162B8;
            break;
        }
    case 0x1630D:
        r8[al] = r8[cl];
    case 0x1630F:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x1632F;
            break;
        }
        r8[cl] = r8[al];
        if (memory16get(ds*16+0x7ECC) != 0x0001) {
            pc = 0x1632D;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_1646E();
        r16[bx] = pop();
        r16[cx] = pop();
        if (!flags.carry) {
            pc = 0x1632D;
            break;
        }
        r16[ax] = 0x0014;
        yield* sub_1AECD();
        pc = 0x162B8;
        break;
    case 0x1632D:
        r8[al] = r8[cl];
    case 0x1632F:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x16389;
            break;
        }
        r8[cl] = r8[al];
        push(si);
        si = 0x0b56;
    case 0x16339:
        bp = memory16get(cs*16+si);
        if (bp == 0xffff) {
            pc = 0x1637D;
            break;
        }
        if (!(bp & 0x0001)) {
            pc = 0x16378;
            break;
        }
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_16519();
        r16[bx] = pop();
        r16[cx] = pop();
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        if (flags.carry) {
            pc = 0x16382;
            break;
        }
    case 0x16378:
        si += 0x0034;
        pc = 0x16339;
        break;
    case 0x1637D:
        si = pop();
        flags.carry = false;
        pc = 0x16387;
        break;
    case 0x16382:
        si = pop();
        flags.carry = true;
        pc = 0x162B8;
        break;
    case 0x16387:
        r8[al] = r8[cl];
    case 0x16389:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        if (!flags.carry) {
            pc = 0x163F0;
            break;
        }
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        r16[bx] = 0x0c28;
    case 0x163A4:
        r8[al] = memory[ds*16+r16[bx] + 1];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (flags.sign) {
            pc = 0x163F0;
            break;
        }
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x163EB;
            break;
        }
        if (r16[bx] == r16[dx]) {
            pc = 0x163EB;
            break;
        }
        si = r16[bx];
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_16555();
        r16[bx] = pop();
        r16[cx] = pop();
        push(memory16get(ds*16+0x54F4));
        push(r16[dx]);
        memory16set(ds*16+0x54F4, pop());
        r16[dx] = pop();
        push(memory16get(ds*16+0x54F6));
        push(r16[bx]);
        memory16set(ds*16+0x54F6, pop());
        r16[bx] = pop();
        if (!flags.carry) {
            pc = 0x163EB;
            break;
        }
        pc = 0x162B8;
        break;
    case 0x163EB:
        r16[bx] += 0x0034;
        pc = 0x163A4;
        break;
    case 0x163F0:
        si = pop();
        memory[ds*16+si + 3] &= 0x7f;
    case 0x163F5:
        push(memory16get(ds*16+0x54F8));
        push(r16[ax]);
        memory16set(ds*16+0x54F8, pop());
        r16[ax] = pop();
        r8[al] -= 1;
        if (r8[al] == 0)
            {
            flags.carry = 0;
            return;
        }
        pc = 0x1623E;
        break;
        return;
    } while (1);
}
function* sub_16407() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x7E16) != 0x0001) {
            pc = 0x16410;
            break;
        }
        flags.carry = false;
        return;
    case 0x16410:
        bp = memory16get(ds*16+0xB1E);
        bp += 0x0014;
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
        bp -= 0x0010;
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
        bp = memory16get(ds*16+0xB20);
        r16[cx] = r16[bx];
        if (memory16get(ds*16+0x7E04) == 0x0001) {
            pc = 0x16454;
            break;
        }
        bp += 0x0015;
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
        bp -= 0x0015;
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
        pc = 0x1646A;
        break;
    case 0x16454:
        bp += 0x0015;
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
        bp -= 0x0010;
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x1646C;
            break;
        }
    case 0x1646A:
        flags.carry = true;
        return;
    case 0x1646C:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1646E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = memory16get(ds*16+0x7ECE);
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x1649E;
            break;
        }
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] < signed16(bp)) {
            pc = 0x1649E;
            break;
        }
        bp = memory16get(ds*16+0x7ED0);
        r16[cx] = r16[bx];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x1649E;
            break;
        }
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] < signed16(bp)) {
            pc = 0x1649E;
            break;
        }
        flags.carry = true;
        return;
    case 0x1649E:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_164A0() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0xB00) != 0x0001) {
            pc = 0x164DF;
            break;
        }
        bp = memory16get(cs*16+0xB02);
        bp += 0x0008;
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x164DF;
            break;
        }
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] < signed16(bp)) {
            pc = 0x164DF;
            break;
        }
        bp = memory16get(cs*16+0xB04);
        bp += 0x0004;
        r16[cx] = r16[bx];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x164DF;
            break;
        }
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] < signed16(bp)) {
            pc = 0x164DF;
            break;
        }
        flags.carry = true;
        return;
    case 0x164DF:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_164E1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = memory16get(ds*16+0xB3A);
        bp += 0x000c;
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x16517;
            break;
        }
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] < signed16(bp)) {
            pc = 0x16517;
            break;
        }
        bp = memory16get(ds*16+0xB3C);
        bp += 0x000a;
        r16[cx] = r16[bx];
        if (r16s[cx] > signed16(bp)) {
            pc = 0x16517;
            break;
        }
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] < signed16(bp)) {
            pc = 0x16517;
            break;
        }
        flags.carry = true;
        return;
    case 0x16517:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_16519() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = memory16get(ds*16+si + 2);
        bp += 0x0014;
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x16553;
            break;
        }
        bp -= 0x0010;
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x16553;
            break;
        }
        bp = memory16get(ds*16+si + 4);
        r16[cx] = r16[bx];
        bp += 0x0015;
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x16553;
            break;
        }
        bp -= 0x0015;
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x16553;
            break;
        }
        flags.carry = true;
        return;
    case 0x16553:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_16555() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = memory16get(ds*16+si + 2);
        bp = bp + memory16get(ds*16+si + 30);
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[dh];
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x1658F;
            break;
        }
        bp = bp - memory16get(ds*16+si + 30);
        r8[al] = r8[dh];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        r8[dh] = r8[al];
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x1658F;
            break;
        }
        bp = memory16get(ds*16+si + 4);
        r16[cx] = r16[bx];
        bp = bp + memory16get(ds*16+si + 32);
        if (r16s[cx] >= signed16(bp)) {
            pc = 0x1658F;
            break;
        }
        bp = bp - memory16get(ds*16+si + 32);
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[cx] += r16[ax];
        xchg8(al, ah);
        if (r16s[cx] <= signed16(bp)) {
            pc = 0x1658F;
            break;
        }
        flags.carry = true;
        return;
    case 0x1658F:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_16591() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si];
        r8[al] &= 0x3f;
        r8[ah] = 0x29;
        if (r8[al] != 0x21) {
            pc = 0x1659E;
            break;
        }
        pc = 0x167D9;
        break;
    case 0x1659E:
        r8[ah] = 0x27;
        if (r8[al] != 0x29) {
            pc = 0x165A7;
            break;
        }
        pc = 0x167D9;
        break;
    case 0x165A7:
        r8[ah] = 0x28;
        if (r8[al] != 0x2d) {
            pc = 0x165B0;
            break;
        }
        pc = 0x167D9;
        break;
    case 0x165B0:
        if (!(r8[al] & 0x02)) {
            pc = 0x165B7;
            break;
        }
        pc = 0x16748;
        break;
    case 0x165B7:
        r16[bx] = memory16get(ds*16+si + 36);
    case 0x165BA:
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] == 0x00) {
            pc = 0x165CF;
            break;
        }
        if (r8[al] != 0xff) {
            pc = 0x16604;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[bx] + 1);
        yield* sub_1AECD();
        r16[bx] += 0x0003;
        pc = 0x165BA;
        break;
    case 0x165CF:
        r16[bx] += 1;
        r16[bx] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+si + 36, r16[bx]);
        r8[al] = memory[ds*16+si + 50];
        if (!(r8[al] & 0x20)) {
            pc = 0x165DF;
            break;
        }
    {yield* sub_16174(); return; };
    case 0x165DF:
        if (!(r8[al] & 0x10)) {
            pc = 0x165BA;
            break;
        }
        if (!(r8[al] & 0x08)) {
            pc = 0x165EE;
            break;
        }
        memory[ds*16+si + 50] &= 0xf7;
        pc = 0x165F2;
        break;
    case 0x165EE:
        memory[ds*16+si + 50] &= 0xef;
    case 0x165F2:
        r8[al] = memory[ds*16+si];
        r8[al] &= 0x1c;
        if (r8[al] == 0x14) {
            pc = 0x165FD;
            break;
        }
        pc = 0x1679D;
        break;
    case 0x165FD:
        memory[ds*16+si + 50] |= 0x20;
        pc = 0x1679D;
        break;
    case 0x16604:
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        if (r8[al] != 0x07) {
            pc = 0x16615;
            break;
        }
        r8[al] += 1;
    case 0x16615:
        _cbw();
        memory16set(ds*16+si + 46, r16[ax]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x16625;
            break;
        }
        flags.carry = (r16[ax] + memory16get(ds*16+si + 2)) >= 0x10000;
        r16[ax] = r16[ax] + memory16get(ds*16+si + 2);
        if (flags.carry) {
            pc = 0x1662A;
            break;
        }
        pc = 0x1662A;
        break;
        _STOP_("db 90h");
    case 0x16625:
        flags.carry = (r16[ax] + memory16get(ds*16+si + 2)) >= 0x10000;
        r16[ax] = r16[ax] + memory16get(ds*16+si + 2);
    case 0x1662A:
        memory16set(ds*16+si + 2, r16[ax]);
        r8[dh] = r8[dh] ^ r8[dh];
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] &= 0x0f;
        if (!(r8[al] & 0x08)) {
            pc = 0x1663B;
            break;
        }
        r8[dh] -= 1;
        r8[al] |= 0xf0;
    case 0x1663B:
        if (r8[al] != 0x07) {
            pc = 0x16641;
            break;
        }
        r8[al] += 1;
    case 0x16641:
        r8[dl] = r8[al];
        _cbw();
        memory16set(ds*16+si + 48, r16[ax]);
        r16[cx] = r16[bx];
        r16[bx] = memory16get(ds*16+si + 4);
        r16[bx] += r16[dx];
        memory16set(ds*16+si + 4, r16[bx]);
        yield* sub_1613C();
        if (!flags.carry) {
            pc = 0x16659;
            break;
        }
    {yield* sub_1615F(); return; };
    case 0x16659:
        r16[bx] = r16[cx];
        r16[bx] -= 1;
        r8[al] = memory[ds*16+r16[bx]];
        _cbw();
        memory16set(ds*16+si + 34, memory16get(ds*16+si + 34) + 1);
        if (r16[ax] == memory16get(ds*16+si + 34)) {
            pc = 0x16669;
            break;
        }
        if (r16[ax] >= memory16get(ds*16+si + 34)) {
            pc = 0x16673;
            break;
        }
    case 0x16669:
        memory16set(ds*16+si + 34, 0x0000);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+si + 36, r16[bx]);
    case 0x16673:
        yield* sub_1718E();
        if (!(memory16get(ds*16+si) & 0x0080)) {
            pc = 0x166BD;
            break;
        }
        if (memory16get(ds*16+si) & 0x0040) {
            pc = 0x16685;
            break;
        }
        pc = 0x16748;
        break;
    case 0x16685:
        if (memory16get(ds*16+0xB38) != 0x0001) {
            pc = 0x166BD;
            break;
        }
        r16[bx] = memory16get(ds*16+0xB3C);
        r8[dh] = memory[ds*16+0xB3A];
        r8[dh] += 0x08;
        r8[dl] = 0x08;
        r8[ah] = 0x10;
        yield* sub_16555();
        if (!flags.carry) {
            pc = 0x166BD;
            break;
        }
        memory16set(ds*16+0xB38, 0x0002);
        memory16set(ds*16+0xB50, 0x0000);
        memory16set(ds*16+0xB4E, 0x7eb2);
        memory16set(ds*16+0xB3C, memory16get(ds*16+0xB3C) - 0x0005);
        memory16set(ds*16+0xB4A, 0x0000);
    case 0x166BD:
        if (memory16get(ds*16+si) & 0x0040) {
            pc = 0x166C6;
            break;
        }
        pc = 0x16748;
        break;
    case 0x166C6:
        if (memory16get(ds*16+si + 10) == 0x00fe) {
            pc = 0x16748;
            break;
        }
        di = 0x0b56;
    case 0x166D3:
        r16[ax] = memory16get(ds*16+di);
        if (r16[ax] == 0xffff) {
            pc = 0x16717;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x16712;
            break;
        }
        if (memory16get(ds*16+di + 22) == 0x0001) {
            pc = 0x16712;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        push(si);
        push(di);
        si = di;
        yield* sub_16519();
        if (!flags.carry) {
            pc = 0x16710;
            break;
        }
        push(si);
        si = 0x6711;
        yield* sub_16BC7();
        si = pop();
        yield* sub_17674();
    case 0x16710:
        di = pop();
        si = pop();
    case 0x16712:
        di += 0x0034;
        pc = 0x166D3;
        break;
    case 0x16717:
        if (memory16get(ds*16+0x7E16) == 0x0001) {
            pc = 0x16748;
            break;
        }
        if (!(memory[ds*16+si] & 0x40)) {
            pc = 0x16748;
            break;
        }
        r16[ax] = memory16get(ds*16+si + 10);
        if (r16[ax] == 0x00fe) {
            pc = 0x16748;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x16748;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x16748:
        r8[al] = memory[ds*16+si + 50];
        if (!(r8[al] & 0x40)) {
            pc = 0x16750;
            break;
        }
        return;
    case 0x16750:
        if (!(memory[ds*16+si + 50] & 0x10)) {
            pc = 0x1675C;
            break;
        }
        if (!(memory[ds*16+si] & 0x20)) {
            pc = 0x1675C;
            break;
        }
        return;
    case 0x1675C:
        push(si);
        r16[dx] = si;
        si = memory16get(ds*16+si + 28);
        yield* sub_16222();
        si = pop();
        if (flags.carry) {
            pc = 0x16774;
            break;
        }
        r8[al] = memory[ds*16+si];
        r8[al] &= 0x1c;
        if (r8[al] == 0x1c) {
            pc = 0x16771;
            break;
        }
        return;
    case 0x16771:
    {yield* sub_16174(); return; };
    case 0x16774:
        r8[al] = memory[ds*16+si];
        r8[al] &= 0x1c;
        if (r8[al] != 0) {
            pc = 0x16781;
            break;
        }
        r8[al] = memory[ds*16+si];
        r8[al] = r8[al] ^ 0x02;
        memory[ds*16+si] = r8[al];
        return;
    case 0x16781:
        if (r8[al] != 0x1c) {
            pc = 0x16786;
            break;
        }
        return;
    case 0x16786:
        if (r8[al] != 0x0c) {
            pc = 0x1678D;
            break;
        }
    {yield* sub_16174(); return; };
    case 0x1678D:
        if (!(r8[al] & 0x08)) {
            pc = 0x167CA;
            break;
        }
        memory[ds*16+si + 50] |= 0x40;
        if (!(r8[al] & 0x10)) {
            pc = 0x1679D;
            break;
        }
        memory[ds*16+si + 50] |= 0x20;
    case 0x1679D:
        r16[bx] = memory16get(ds*16+si + 40);
        r16[cx] = memory16get(ds*16+si + 36);
        memory16set(ds*16+si + 40, r16[cx]);
        memory16set(ds*16+si + 36, r16[bx]);
        r16[bx] = memory16get(ds*16+si + 22);
        r16[cx] = memory16get(ds*16+si + 42);
        memory16set(ds*16+si + 22, r16[cx]);
        memory16set(ds*16+si + 42, r16[bx]);
        memory16set(ds*16+si + 24, 0x0000);
        memory16set(ds*16+si + 18, 0x0000);
        r8[al] = memory[ds*16+si];
        r8[ah] = memory[ds*16+si + 44];
        memory[ds*16+si] = r8[ah];
        memory[ds*16+si + 44] = r8[al];
        return;
    case 0x167CA:
        memory[ds*16+si + 50] |= 0x10;
        if (memory[ds*16+si] & 0x20) {
            pc = 0x167D4;
            break;
        }
        return;
    case 0x167D4:
        memory[ds*16+si + 50] |= 0x08;
        return;
    case 0x167D9:
        memory[ds*16+si] = r8[al];
        memory[ds*16+si + 10] = r8[ah];
        memory[ds*16+si + 11] = 0x00;
        memory16set(ds*16+si + 30, 0x0018);
        memory16set(ds*16+si + 32, 0x0015);
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x16803;
            break;
        }
        yield* sub_1686F();
        yield* sub_16174();
    case 0x16803:
        if (memory16get(ds*16+0xB38) != 0x0002) {
            pc = 0x1683F;
            break;
        }
        r8[al] = memory[ds*16+0xB4A];
        if (r8s[al] <= signed8(0x01)) {
            pc = 0x1683F;
            break;
        }
        if (r8s[al] > signed8(0x04)) {
            pc = 0x1683F;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        if (r8[dh] >= 0x0f) {
            pc = 0x1682B;
            break;
        }
        r8[dh] = r8[dh] ^ r8[dh];
        pc = 0x1682E;
        break;
        _STOP_("db 90h");
    case 0x1682B:
        r8[dh] -= 0x10;
    case 0x1682E:
        r16[bx] -= 0x000e;
        r8[dl] += 0x20;
        r8[ah] += 0x1d;
        yield* sub_164E1();
        if (!flags.carry) {
            pc = 0x1683F;
            break;
        }
        yield* sub_16174();
    case 0x1683F:
        if (memory16get(ds*16+0xB00) != 0x0001) {
            pc = 0x16866;
            break;
        }
        r8[al] = memory[ds*16+si];
        if (r8[al] == 0x21) {
            pc = 0x16866;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        yield* sub_164A0();
        if (!flags.carry) {
            pc = 0x16866;
            break;
        }
        yield* sub_16174();
        memory16set(ds*16+0xB00, 0x0000);
    case 0x16866:
        yield* sub_1613C();
        if (!flags.carry)
            return;
        yield* sub_1615F();
        return;
    } while (1);
}
function* sub_1686F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x21) {
            pc = 0x16884;
            break;
        }
        push(si);
        si = 0x6717;
        yield* sub_16BC7();
        si = pop();
        r16[ax] = 0x0012;
        yield* sub_1AECD();
        return;
    case 0x16884:
        if (r8[al] == 0x29) {
            pc = 0x16898;
            break;
        }
        memory16set(ds*16+0x6612, 0x0006);
        yield* sub_16C3D();
        r16[ax] = 0x0011;
        yield* sub_1AECD();
        return;
    case 0x16898:
        memory16set(ds*16+0x6610, 0x0006);
        yield* sub_16C27();
        r16[ax] = 0x0011;
        yield* sub_1AECD();
        return;
    } while (1);
}
function* sub_168A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x000b;
        yield* sub_1AECD();
        memory16set(ds*16+0x7E16, 0x0001);
        memory16set(ds*16+0xB24, 0xfb00);
        r16[ax] = memory16get(ds*16+0xB1E);
        if (r16s[ax] < signed16(0x0080)) {
            pc = 0x168CB;
            break;
        }
        memory16set(ds*16+0x7E1C, 0xfffe);
        pc = 0x168D1;
        break;
        _STOP_("db 90h");
    case 0x168CB:
        memory16set(ds*16+0x7E1C, 0x0002);
    case 0x168D1:
        r16[ax] = memory16get(ds*16+0x6614);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0)
            return;
        if (memory[ds*16+0x9804] == 0x01)
            return;
        // std::cout << "infinite lives";
        return;
    } while (1);
}
function* sub_168E4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x762D) != 0x0001) {
            pc = 0x168EF;
            break;
        }
        yield* sub_17A8B();
        return;
    case 0x168EF:
        si = 0x0c28;
    case 0x168F2:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (!(r8[al] & 0x01)) {
            pc = 0x16901;
            break;
        }
        push(si);
        yield* sub_16591();
        si = pop();
    case 0x16901:
        si += 0x0034;
        pc = 0x168F2;
        break;
        return;
    } while (1);
}
function* sub_16907() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x0b56;
    case 0x1690A:
        r16[ax] = memory16get(ds*16+di);
        flags.sign = !!(r8[ah] & 0x80);
        r8[ah] |= r8[ah];
        if (flags.sign) {
            pc = 0x16919;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x1691B;
            break;
        }
        di += 0x0034;
        pc = 0x1690A;
        break;
    case 0x16919:
        flags.carry = true;
        return;
    case 0x1691B:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1691D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_16907();
        if (!flags.carry) {
            pc = 0x16923;
            break;
        }
        return;
    case 0x16923:
        memory16set(ds*16+di + 22, 0x0000);
        memory16set(ds*16+di + 24, 0x0000);
        memory[ds*16+si] |= 0x80;
        r8[al] = memory[ds*16+si];
        r8[al] &= 0x03;
        memory[ds*16+di + 49] = 0x00;
        memory[ds*16+di + 48] = r8[al];
        memory16set(ds*16+di + 28, si);
        memory16set(ds*16+di, memory16get(ds*16+di) | 0x0001);
        r8[al] = memory[ds*16+si];
        if (!(r8[al] & 0x04)) {
            pc = 0x16954;
            break;
        }
        memory16set(ds*16+di + 10, 0x002a);
        memory16set(ds*16+di + 50, 0x002a);
        pc = 0x1695E;
        break;
    case 0x16954:
        memory16set(ds*16+di + 10, 0x0034);
        memory16set(ds*16+di + 50, 0x0034);
    case 0x1695E:
        r8[al] = memory[ds*16+si + 2];
        r16[ax] &= 0x001f;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+di + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r8[dl] = r8[al];
        r8[al] = memory[ds*16+si + 1];
        r8[al] -= r8[dl];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (!(memory[ds*16+si + 2] & 0x40)) {
            pc = 0x1698C;
            break;
        }
        r16[ax] += 1;
        r16[ax] += 1;
        r16[ax] += 1;
    case 0x1698C:
        memory16set(ds*16+di + 4, r16[ax]);
        memory16set(ds*16+di + 30, 0x0010);
        memory16set(ds*16+di + 32, 0x0015);
        r16[ax] = memory16get(ds*16+di + 48);
        if (r16[ax] != 0x0001) {
            pc = 0x169B3;
            break;
        }
        r8[al] = memory[ds*16+si + 3];
        r8[al] &= 0x3c;
        r16[ax] <<= 1;
        r16[ax] += 0x0008;
        memory16set(ds*16+di + 18, r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 20, r16[ax]);
    case 0x169B3:
        memory16set(ds*16+di + 8, 0x0100);
        memory[ds*16+di + 6] = 0x00;
        memory16set(ds*16+di + 16, 0x0000);
        r16[ax] = 0x0000;
        memory16set(ds*16+di + 34, r16[ax]);
        memory16set(ds*16+di + 36, r16[ax]);
        memory16set(ds*16+di + 38, r16[ax]);
        memory16set(ds*16+di + 40, r16[ax]);
        memory16set(ds*16+di + 42, r16[ax]);
        memory16set(ds*16+di + 44, r16[ax]);
        memory16set(ds*16+di + 26, 0x0000);
        memory16set(ds*16+di + 16, 0x0002);
        return;
    } while (1);
}
function* sub_169E3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x5DCC) == 0x0000)
            return;
        r16[ax] = memory16get(ds*16+0x65E1);
        r16[ax] += 1;
        if (r16[ax] != 0x0019) {
            pc = 0x16A0B;
            break;
        }
        si = 0x6624;
        r16[cx] = 0x0006;
        r8[al] = 0x00;
    case 0x169FB:
        if (r8[al] != memory[ds*16+si]) {
            pc = 0x16A03;
            break;
        }
        si += 1;
        if (--r16[cx]) {
            pc = 0x169FB;
            break;
        }
        return;
    case 0x16A03:
        si = 0x662b;
        yield* sub_16BF7();
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x16A0B:
        memory16set(ds*16+0x65E1, r16[ax]);
        return;
    } while (1);
}
function* sub_16B3B() {
    push(ds);
    push(es);
    push(r16[bx]);
    yield* sub_16C53();
    yield* sub_16C27();
    yield* sub_16C3D();
    r16[ax] = 0x0004;
    si = 0x6616;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = 0x000d;
    si = 0x66f6;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = 0x0015;
    si = 0x66fd;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = 0x001e;
    si = 0x6704;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = 0x0004;
    si = 0x6616;
    yield* indirectCall(ds, memory16get(ds*16+0xE));
    r16[ax] = 0x000d;
    si = 0x66f6;
    yield* indirectCall(ds, memory16get(ds*16+0xE));
    r16[ax] = 0x0015;
    si = 0x66fd;
    yield* indirectCall(ds, memory16get(ds*16+0xE));
    r16[ax] = 0x001e;
    si = 0x6704;
    yield* indirectCall(ds, memory16get(ds*16+0xE));
    r16[bx] = pop();
    es = pop();
    ds = pop();
}
function* sub_16B9B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        yield* indirectCall(ds, memory16get(ds*16+0x28));
        memory[ds*16+0x97DA] = 0x01;
        r16[cx] = 0x01e0;
    case 0x16BAC:
        push(r16[cx]);
        yield* _sync();
        yield* sub_19B1C();
        yield* sub_19BDC();
        if (r8[al] & 0x10) {
            pc = 0x16BC4;
            break;
        }
        r8[al] = memory[ds*16+0xB888];
        r8[al] &= 0x30;
        if (r8[al] == 0x30) {
            pc = 0x16BC4;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x16BAC;
            break;
        }
        return;
    case 0x16BC4:
    {yield* loc_1C3B0(); return; };
        return;
    } while (1);
}
function* sub_16BC7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si += 0x0005;
        di = 0x661b;
        r8[bl] = 0x00;
        r16[cx] = 0x0006;
    case 0x16BD2:
        r8[al] = memory[ds*16+si];
        r8[ah] = memory[ds*16+di];
        r8[ah] += r8[al];
        r8[ah] += r8[bl];
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        if (r16s[ax] < signed16(0x000a)) {
            pc = 0x16BEE;
            break;
        }
        r8[bl] = 0x01;
        r8[al] -= 0x0a;
        memory[ds*16+di] = r8[al];
        di -= 1;
        si -= 1;
        if (--r16[cx]) {
            pc = 0x16BD2;
            break;
        }
        return;
    case 0x16BEE:
        r8[bl] = 0x00;
        memory[ds*16+di] = r8[al];
        di -= 1;
        si -= 1;
        if (--r16[cx]) {
            pc = 0x16BD2;
            break;
        }
        return;
    } while (1);
}
function* sub_16BF7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si += 0x0005;
        di = 0x6629;
        r8[bl] = 0x00;
        r16[cx] = 0x0006;
    case 0x16C02:
        r8[al] = memory[ds*16+si];
        r8[ah] = memory[ds*16+di];
        r8[ah] += r8[al];
        r8[ah] += r8[bl];
        xchg8(al, ah);
        r8[ah] = r8[ah] ^ r8[ah];
        if (r16s[ax] < signed16(0x000a)) {
            pc = 0x16C1E;
            break;
        }
        r8[bl] = 0x01;
        r8[al] -= 0x0a;
        memory[ds*16+di] = r8[al];
        di -= 1;
        si -= 1;
        if (--r16[cx]) {
            pc = 0x16C02;
            break;
        }
        return;
    case 0x16C1E:
        r8[bl] = 0x00;
        memory[ds*16+di] = r8[al];
        di -= 1;
        si -= 1;
        if (--r16[cx]) {
            pc = 0x16C02;
            break;
        }
        return;
    } while (1);
}
function* sub_16C27() {
    di = 0x66f6;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    rep_stosb_data_forward();
    r16[cx] = memory16get(ds*16+0x6610);
    di = 0x66f6;
    r8[al] = 0x0a;
    rep_stosb_data_forward();
}
function* sub_16C3D() {
    di = 0x66fd;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    rep_stosb_data_forward();
    r16[cx] = memory16get(ds*16+0x6612);
    di = 0x66fd;
    r8[al] = 0x0b;
    rep_stosb_data_forward();
}
function* sub_16C53() {
    di = 0x6704;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    rep_stosb_data_forward();
    r16[cx] = memory16get(ds*16+0x6614);
    di = 0x6704;
    r8[al] = 0x0c;
    rep_stosb_data_forward();
}
function* sub_16C69() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0008;
        di = 0x6632;
        r16[bx] = 0x668d;
    case 0x16C72:
        si = 0x6616;
        yield* sub_16CB8();
        if (flags.carry) {
            pc = 0x16C84;
            break;
        }
        r16[bx] += 0x000b;
        di += 0x0007;
        if (--r16[cx]) {
            pc = 0x16C72;
            break;
        }
        flags.carry = false;
        return;
    case 0x16C84:
        si = 0x6663;
    case 0x16C87:
        if (si == di) {
            pc = 0x16C94;
            break;
        }
        r8[al] = memory[ds*16+si - 1];
        memory[ds*16+si + 6] = r8[al];
        si -= 1;
        pc = 0x16C87;
        break;
    case 0x16C94:
        r16[cx] = 0x0007;
        si = 0x6616;
        rep_movsb_data_data_forward();
        flags.carry = true;
        return;
    } while (1);
}
function* loc_16CA1() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x16CA1:
        if (si == di) {
            pc = 0x16CAE;
            break;
        }
        r8[al] = memory[ds*16+si - 1];
        memory[ds*16+si + 10] = r8[al];
        si -= 1;
        pc = 0x16CA1;
        break;
    case 0x16CAE:
        r16[cx] = 0x000b;
        si = 0x6671;
        rep_movsb_data_data_forward();
        flags.carry = true;
        return;
    } while (1);
}
function* sub_16CB8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(di);
        r16[cx] = 0x0006;
    case 0x16CBD:
        r8[al] = memory[ds*16+si];
        si += 1;
        r8[ah] = memory[ds*16+di];
        di += 1;
        if (r8s[al] < r8s[ah]) {
            pc = 0x16CCF;
            break;
        }
        if (r8s[al] > r8s[ah]) {
            pc = 0x16CD3;
            break;
        }
        if (--r16[cx]) {
            pc = 0x16CBD;
            break;
        }
        di = pop();
        r16[cx] = pop();
        flags.carry = true;
        return;
    case 0x16CCF:
        di = pop();
        r16[cx] = pop();
        flags.carry = false;
        return;
    case 0x16CD3:
        di = pop();
        r16[cx] = pop();
        flags.carry = true;
        return;
    } while (1);
}
function* sub_16CD7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        r16[ax] = 0x0008;
        si = 0x9401;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0108;
        si = 0x9421;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0208;
        si = 0x9441;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        si = 0x668d;
        r16[ax] = 0x0617;
        r16[cx] = 0x0008;
    case 0x16D02:
        push(si);
        push(r16[ax]);
        push(r16[cx]);
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        r16[cx] = pop();
        r16[ax] = pop();
        si = pop();
        si += 0x000b;
        r8[ah] += 1;
        r8[ah] += 1;
        if (--r16[cx]) {
            pc = 0x16D02;
            break;
        }
        si = 0x6632;
        r16[ax] = 0x0607;
        r16[cx] = 0x0008;
    case 0x16D1E:
        push(si);
        push(r16[ax]);
        push(r16[cx]);
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        r16[cx] = pop();
        r16[ax] = pop();
        si = pop();
        si += 0x0007;
        r8[ah] += 1;
        r8[ah] += 1;
        if (--r16[cx]) {
            pc = 0x16D1E;
            break;
        }
        si = 0x6682;
        r16[ax] = 0x060d;
        r16[cx] = 0x0008;
    case 0x16D3A:
        push(si);
        push(r16[ax]);
        push(r16[cx]);
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        r16[cx] = pop();
        r16[ax] = pop();
        si = pop();
        r8[ah] += 1;
        r8[ah] += 1;
        if (--r16[cx]) {
            pc = 0x16D3A;
            break;
        }
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        memory[ds*16+0x97DA] = 0x01;
        r16[cx] = 0x01e0;
    case 0x16D57:
        yield* _sync();
        push(r16[cx]);
        yield* sub_19B1C();
        yield* sub_19BDC();
        if (r8[al] & 0x10) {
            pc = 0x16D66;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x16D57;
            break;
        }
        return;
    case 0x16D66:
    {yield* loc_1C3B0(); return; };
        return;
    } while (1);
}
function* sub_16D69() {
    yield* sub_16C69();
    if (!flags.carry)
        return;
    push(r16[bx]);
    yield* sub_16EB2();
    r16[bx] = pop();
    r16[cx] = 0x000a;
    si = 0x6671;
    di = r16[bx];
    rep_movsb_data_data_forward();
    return;
}
function* sub_16E16() {
    r16[ax] = r16[ax] ^ r16[ax];
    r16[dx] = memory16get(ds*16+0x69F0);
    r8[al] = r8[dh];
    r8[al] -= 0x08;
    r16[ax] &= 0xfffe;
    r16[bx] = r16[ax];
    r16[ax] <<= 1;
    r16[bx] += r16[ax];
    r8[dh] = r8[dh] ^ r8[dh];
    r16[dx] -= 0x000e;
    r16[dx] >>= 1;
    r16[bx] += r16[dx];
    r16[bx] += 0x69f8;
    r8[al] = memory[ds*16+r16[bx]];
}
function* sub_16E39() {
    r16[ax] = memory16get(ds*16+0x69F2);
    si = 0x69ee;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = memory16get(ds*16+0x69F0);
    si = 0x69ec;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    yield* indirectCall(ds, memory16get(ds*16+0x1C));
    r16[ax] = memory16get(ds*16+0x69F2);
    si = 0x69ee;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = memory16get(ds*16+0x69F0);
    si = 0x69ec;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
}
function* sub_16E66() {
    r16[ax] = memory16get(ds*16+0x69F0);
    memory16set(ds*16+0x69F2, r16[ax]);
    memory16set(ds*16+0x69F0, r16[dx]);
    yield* sub_16E39();
}
function* sub_16E74() {
    r16[ax] = memory16get(ds*16+0x69F6);
    si = 0x69ee;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = memory16get(ds*16+0x69F4);
    si = 0x69ec;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    yield* indirectCall(ds, memory16get(ds*16+0x1C));
    r16[ax] = memory16get(ds*16+0x69F6);
    si = 0x69ee;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
    r16[ax] = memory16get(ds*16+0x69F4);
    si = 0x69ec;
    yield* indirectCall(ds, memory16get(ds*16+0xC));
}
function* sub_16EA1() {
    r16[ax] = memory16get(ds*16+0x69F4);
    memory16set(ds*16+0x69F6, r16[ax]);
    memory16set(ds*16+0x69F4, r16[dx]);
    yield* sub_16E74();
}
function* sub_16EB2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x090e;
        memory16set(ds*16+0x69F0, r16[ax]);
        memory16set(ds*16+0x69F2, r16[ax]);
        r16[ax] = 0x150e;
        memory16set(ds*16+0x69F4, r16[ax]);
        memory16set(ds*16+0x69F6, r16[ax]);
        di = 0x6671;
        r16[cx] = 0x000a;
        r8[al] = 0x0e;
        rep_stosb_data_forward();
        memory16set(ds*16+0x6AB0, 0x6671);
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        r16[ax] = 0x0005;
        si = 0x93a1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0105;
        si = 0x93c1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0205;
        si = 0x93e1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[bx] = 0x69de;
        yield* sub_19C43();
        r16[ax] = 0x140e;
        si = 0x6671;
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        r16[ax] = 0x0005;
        si = 0x93a1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0105;
        si = 0x93c1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[ax] = 0x0205;
        si = 0x93e1;
        yield* indirectCall(ds, memory16get(ds*16+0x46));
        r16[bx] = 0x69de;
        yield* sub_19C43();
        r16[ax] = 0x140e;
        si = 0x6671;
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        yield* sub_16E39();
        yield* sub_16E74();
    case 0x16F3E:
        r16[ax] = 0x140e;
        si = 0x6671;
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        r16[ax] = 0x140e;
        si = 0x6671;
        yield* indirectCall(ds, memory16get(ds*16+0xC));
        r16[cx] = 0x0006;
    case 0x16F59:
        yield* sub_19B1C();
        if (--r16[cx]) {
            pc = 0x16F59;
            break;
        }
        yield* sub_1C4CA();
        if (memory[ds*16+0x6AAF] != 0x01) {
            pc = 0x16F71;
            break;
        }
        if (r8[al] & 0x10) {
            pc = 0x16F71;
            break;
        }
        memory[ds*16+0x6AAF] = 0x00;
    case 0x16F71:
        r16[dx] = memory16get(ds*16+0x69F0);
        if (!(r8[al] & 0x08)) {
            pc = 0x16F7C;
            break;
        }
        r8[dh] -= 0x02;
    case 0x16F7C:
        if (!(r8[al] & 0x04)) {
            pc = 0x16F83;
            break;
        }
        r8[dh] += 0x02;
    case 0x16F83:
        if (!(r8[al] & 0x01)) {
            pc = 0x16F8A;
            break;
        }
        r8[dl] += 0x02;
    case 0x16F8A:
        if (!(r8[al] & 0x02)) {
            pc = 0x16F91;
            break;
        }
        r8[dl] -= 0x02;
    case 0x16F91:
        if (r8[al] & 0x10) {
            pc = 0x16FBC;
            break;
        }
        if (r8[dl] != 0x0c) {
            pc = 0x16F9F;
            break;
        }
        r8[dl] = 0x0e;
        pc = 0x16FA6;
        break;
        _STOP_("db 90h");
    case 0x16F9F:
        if (r8[dl] != 0x1a) {
            pc = 0x16FA6;
            break;
        }
        r8[dl] = 0x18;
    case 0x16FA6:
        if (r8[dh] != 0x07) {
            pc = 0x16FB0;
            break;
        }
        r8[dh] = 0x09;
        pc = 0x16FB7;
        break;
    case 0x16FB0:
        if (r8[dh] != 0x13) {
            pc = 0x16FB7;
            break;
        }
        r8[dh] = 0x11;
    case 0x16FB7:
        yield* sub_16E66();
        pc = 0x16F3E;
        break;
    case 0x16FBC:
        if (memory[ds*16+0x6AAF] != 0x01) {
            pc = 0x16FC6;
            break;
        }
        pc = 0x16F3E;
        break;
    case 0x16FC6:
        yield* sub_16E16();
        memory[ds*16+0x6AAF] = 0x01;
        if (r8[al] == 0x11) {
            pc = 0x16FE2;
            break;
        }
        if (r8[al] != 0x10) {
            pc = 0x16FDC;
            break;
        }
        yield* sub_16FF5();
        pc = 0x16F3E;
        break;
    case 0x16FDC:
        yield* sub_17018();
        pc = 0x16F3E;
        break;
    case 0x16FE2:
        si = 0x6671;
        r16[cx] = 0x000a;
    case 0x16FE8:
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0x0e) {
            pc = 0x16FF1;
            break;
        }
        memory[ds*16+si] = 0x20;
    case 0x16FF1:
        si += 1;
        if (--r16[cx]) {
            pc = 0x16FE8;
            break;
        }
        return;
    } while (1);
}
function* sub_16FF5() {
    di = memory16get(ds*16+0x6AB0);
    di -= 1;
    if (di == 0x6670)
        return;
    memory[ds*16+di] = 0x0e;
    memory16set(ds*16+0x6AB0, di);
    r16[dx] = memory16get(ds*16+0x6AB0);
    r16[dx] -= 0x6671;
    r8[dh] = 0x15;
    r8[dl] += 0x0e;
    yield* sub_16EA1();
    return;
}
function* sub_17018() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = memory16get(ds*16+0x6AB0);
        if (di == 0x667b) {
            pc = 0x17029;
            break;
        }
        memory[ds*16+di] = r8[al];
        di += 1;
        memory16set(ds*16+0x6AB0, di);
    case 0x17029:
        r16[dx] = memory16get(ds*16+0x6AB0);
        r16[dx] -= 0x6671;
        r8[dh] = 0x15;
        if (r8[dl] != 0x0a) {
            pc = 0x1703A;
            break;
        }
        r8[dl] = 0x09;
    case 0x1703A:
        r8[dl] += 0x0e;
        push(r16[ax]);
        yield* sub_16EA1();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_17047() {
    memory16set(ds*16+0x6C43, 0x0000);
    r16[ax] = memory16get(ds*16+0x8BF0);
    memory16set(ds*16+0x6C45, r16[ax]);
    memory16set(ds*16+0x6C45, memory16get(ds*16+0x6C45) & 0x0007);
    yield* indirectCall(ds, memory16get(ds*16+0x12));
}
function* sub_1705D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x7E16) != 0x0001) {
            pc = 0x17065;
            break;
        }
        return;
    case 0x17065:
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[ax] &= 0x0007;
        r16[dx] = memory16get(ds*16+0xB20);
        r16[dx] -= r16[ax];
        if (r16s[dx] >= signed16(0x009b)) {
            pc = 0x17082;
            break;
        }
        r16[bx] = memory16get(ds*16+0x6C43);
        flags.sign = !!(r16[bx] & 0x8000);
        r16[bx] |= r16[bx];
        if (flags.sign) {
            pc = 0x17099;
            break;
        }
        return;
    case 0x17082:
        if (r16s[dx] < signed16(0x0086))
            return;
        r16[bx] = memory16get(ds*16+0x6C43);
        flags.sign = !!(r16[bx] & 0x8000);
        r16[bx] |= r16[bx];
        if (r16[bx] == 0)
            return;
        if (!flags.sign) {
            pc = 0x17095;
            break;
        }
        return;
        _STOP_("db 90h");
    case 0x17095:
        yield* sub_170E6();
        return;
    case 0x17099:
        yield* sub_1709D();
        return;
    } while (1);
}
function* sub_1709D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[dx] = r16[ax];
        r16[ax] = r16[ax] + memory16get(ds*16+0x6C43);
        if (r16s[ax] >= memory16gets(ds*16+0x8BF2)) {
            pc = 0x170BB;
            break;
        }
        r16[cx] = memory16get(ds*16+0x8BF2);
        r16[cx] = r16[cx] - memory16get(ds*16+0x8BF0);
        memory16set(ds*16+0x6C43, r16[cx]);
        r16[ax] = memory16get(ds*16+0x8BF2);
    case 0x170BB:
        memory16set(ds*16+0x8BF0, r16[ax]);
        if (r16[dx] == r16[ax])
            return;
        r16[dx] &= 0x0007;
        flags.sign = signed16(r16[dx] + memory16get(ds*16+0x6C43)) < 0;
        r16[dx] = r16[dx] + memory16get(ds*16+0x6C43);
        if (!flags.sign) {
            pc = 0x170E2;
            break;
        }
        yield* sub_195EA();
        yield* sub_1930A();
        yield* indirectCall(ds, memory16get(ds*16+0x14));
        yield* sub_17180();
        r16[dx] = 0x0008;
        yield* sub_17132();
        yield* sub_15FE4();
        return;
    case 0x170E2:
        yield* sub_17180();
        return;
    } while (1);
}
function* sub_170E6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[dx] = r16[ax];
        r16[ax] = r16[ax] + memory16get(ds*16+0x6C43);
        if (r16s[ax] <= memory16gets(ds*16+0x8BF4)) {
            pc = 0x17104;
            break;
        }
        r16[cx] = memory16get(ds*16+0x8BF4);
        r16[cx] = r16[cx] - memory16get(ds*16+0x8BF0);
        memory16set(ds*16+0x6C43, r16[cx]);
        r16[ax] = memory16get(ds*16+0x8BF4);
    case 0x17104:
        memory16set(ds*16+0x8BF0, r16[ax]);
        if (r16[dx] == r16[ax])
            return;
        r16[dx] &= 0x0007;
        r16[dx] = r16[dx] + memory16get(ds*16+0x6C43);
        if (r16s[dx] <= signed16(0x0007)) {
            pc = 0x1712E;
            break;
        }
        yield* sub_1961D();
        yield* sub_192DA();
        yield* indirectCall(ds, memory16get(ds*16+0x16));
        yield* sub_17180();
        r16[dx] = 0xfff8;
        yield* sub_17132();
        yield* sub_15FE4();
        return;
    case 0x1712E:
        yield* sub_17180();
        return;
    } while (1);
}
function* sub_17132() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0b00;
    case 0x17135:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x17145;
            break;
        }
        if (r16[ax] == 0) {
            pc = 0x17140;
            break;
        }
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[dx]);
    case 0x17140:
        si += 0x001c;
        pc = 0x17135;
        break;
    case 0x17145:
        si = 0x0c28;
    case 0x17148:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x17162;
            break;
        }
        if (!(r8[al] & 0x01)) {
            pc = 0x1715D;
            break;
        }
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[dx]);
        yield* sub_1613C();
        if (!flags.carry) {
            pc = 0x1715D;
            break;
        }
        yield* sub_1615F();
    case 0x1715D:
        si += 0x0034;
        pc = 0x17148;
        break;
    case 0x17162:
        si = 0x0b56;
    case 0x17165:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (!(r8[al] & 0x01)) {
            pc = 0x1717A;
            break;
        }
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[dx]);
        yield* sub_1613C();
        if (!flags.carry) {
            pc = 0x1717A;
            break;
        }
        yield* sub_1615F();
    case 0x1717A:
        si += 0x0034;
        pc = 0x17165;
        break;
        return;
    } while (1);
}
function* sub_17180() {
    r16[ax] = memory16get(ds*16+0x6C45);
    r16[ax] = r16[ax] + memory16get(ds*16+0x6C43);
    r16[ax] &= 0x00ff;
    memory16set(ds*16+0x6C45, r16[ax]);
}
function* sub_1718E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+si) & 0xffff) {
            pc = 0x17196;
            break;
        }
        flags.carry = false;
        return;
    case 0x17196:
        if (!(memory16get(ds*16+si + 24) & 0xffff)) {
            pc = 0x171A2;
            break;
        }
        memory16set(ds*16+si + 24, memory16get(ds*16+si + 24) - 1);
        flags.carry = false;
        return;
    case 0x171A2:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        r16[dx] = r16[dx] ^ r16[dx];
        r16[bx] = memory16get(ds*16+si + 22);
    case 0x171AA:
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x171BB;
            break;
        }
        memory16set(ds*16+si + 10, r16[ax]);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+si + 22, r16[bx]);
        pc = 0x171F5;
        break;
        _STOP_("db 90h");
    case 0x171BB:
        if (r16[ax] != 0xffff) {
            pc = 0x171CD;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        r16[bx] += r16[ax];
        memory16set(ds*16+si + 22, si);
        r16[dx] = 0xffff;
        pc = 0x171AA;
        break;
    case 0x171CD:
        if (r16[ax] != 0xfffd) {
            pc = 0x171E0;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        yield* sub_1AECD();
        r16[bx] += 0x0004;
        memory16set(ds*16+si + 22, r16[bx]);
        pc = 0x171AA;
        break;
    case 0x171E0:
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+si + 24, r16[ax]);
        memory16set(ds*16+si + 24, memory16get(ds*16+si + 24) - 1);
        r16[ax] = memory16get(ds*16+r16[bx] + 4);
        memory16set(ds*16+si + 10, r16[ax]);
        r16[bx] += 0x0006;
        memory16set(ds*16+si + 22, r16[bx]);
    case 0x171F5:
        r16[dx] |= r16[dx];
        if (r16[dx] != 0) {
            pc = 0x171FE;
            break;
        }
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        flags.carry = false;
        return;
    case 0x171FE:
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        flags.carry = true;
        return;
    } while (1);
}
function* sub_17205() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_177FB();
        si = 0x0b56;
    case 0x1720B:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (!(r8[al] & 0x01)) {
            pc = 0x1721A;
            break;
        }
        push(si);
        yield* sub_17222();
        si = pop();
    case 0x1721A:
        si += 0x0034;
        pc = 0x1720B;
        break;
        return;
    } while (1);
}
function* sub_17222() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x6E20, 0x0000);
        memory16set(ds*16+0x6E03, 0x0000);
        if (memory16get(ds*16+si + 24) == 0x0000) {
            pc = 0x17246;
            break;
        }
        memory16set(ds*16+si + 24, memory16get(ds*16+si + 24) - 1);
        if (memory16get(ds*16+si + 22) != 0x0001) {
            pc = 0x17240;
            break;
        }
    {yield* loc_176A0(); return; };
    case 0x17240:
        memory16set(ds*16+0x6E20, 0x0001);
    case 0x17246:
        memory16set(ds*16+si + 44, 0x0000);
        memory16set(ds*16+si + 46, 0x0000);
        if (memory16get(ds*16+si + 22) != 0x0001) {
            pc = 0x17259;
            break;
        }
    {yield* loc_176A0(); return; };
    case 0x17259:
        if (memory16get(ds*16+si + 42) != 0x0001) {
            pc = 0x17262;
            break;
        }
        pc = 0x17644;
        break;
    case 0x17262:
        memory16set(ds*16+si + 44, 0x0000);
        memory16set(ds*16+si + 46, 0x0000);
        memory16set(ds*16+si + 34, 0x0000);
        memory16set(ds*16+si + 36, 0x0000);
        memory16set(ds*16+si + 38, 0x0000);
        memory16set(ds*16+si + 40, 0x0000);
        memory[ds*16+0x796B] = 0x01;
        memory16set(ds*16+0x6E03, 0x0000);
        r16[dx] = memory16get(ds*16+si + 8);
        r16[dx] += 0x0080;
        if (r16s[dx] <= signed16(0x0800)) {
            pc = 0x1729C;
            break;
        }
        r16[dx] = 0x0800;
    case 0x1729C:
        memory16set(ds*16+si + 8, r16[dx]);
        memory16set(ds*16+0x7961, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x172AC;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x172AE;
        break;
    case 0x172AC:
        r8[ch] = 0xff;
    case 0x172AE:
        r16[ax] = memory16get(ds*16+si + 4);
        r8[cl] = memory[ds*16+si + 6];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        memory16set(ds*16+0x795F, r16[ax]);
        r16[dx] = memory16get(ds*16+si + 2);
        memory16set(ds*16+0x795D, r16[dx]);
        memory[ds*16+0x796B] = 0x01;
        yield* sub_17DFB();
    case 0x172CD:
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x172DA;
            break;
        }
    {yield* sub_17674(); return; };
    case 0x172DA:
        if (!(r8[ch] & 0x40)) {
            pc = 0x1733D;
            break;
        }
        r16[ax] = memory16get(ds*16+0x7964);
        r8[cl] = r8[cl] ^ r8[cl];
        r16[ax] -= 0x0015;
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+si + 4, r16[ax]);
        memory[ds*16+si + 6] = 0x00;
        memory16set(ds*16+si + 34, 0x0001);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x7966);
        memory16set(ds*16+si + 44, r16[ax]);
        r16[ax] = pop();
        memory[ds*16+0x796B] = 0x00;
        yield* sub_17DFB();
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x17315;
            break;
        }
    {yield* sub_17674(); return; };
    case 0x17315:
        r8[ch] &= 0x06;
        if (r8[ch] == 0) {
            pc = 0x17321;
            break;
        }
        r8[ch] = memory[ds*16+0x7963];
        pc = 0x1735C;
        break;
        _STOP_("db 90h");
    case 0x17321:
        bp = memory16get(cs*16+si + 44);
        bp = bp | memory16get(cs*16+si + 46);
        bp |= bp;
        if (bp == 0) {
            pc = 0x17333;
            break;
        }
        memory16set(ds*16+0x6E03, 0x0001);
    case 0x17333:
        r8[ch] = memory[ds*16+0x7963];
        r16[dx] = 0x0100;
        pc = 0x173E4;
        break;
    case 0x1733D:
        if (!(r8[ch] & 0x20)) {
            pc = 0x17346;
            break;
        }
    {yield* sub_17674(); return; };
    case 0x17346:
        if (r8[ch] & 0x04) {
            pc = 0x1736D;
            break;
        }
        if (r8[ch] & 0x02) {
            pc = 0x17355;
            break;
        }
        pc = 0x1740E;
        break;
    case 0x17355:
        bp = memory16get(ds*16+si + 8);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (!flags.sign) {
            pc = 0x1736D;
            break;
        }
    case 0x1735C:
        r16[ax] |= 0x0007;
        r16[ax] += 1;
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+si + 8, 0x0100);
        r16[dx] = 0x0100;
        pc = 0x1740E;
        break;
    case 0x1736D:
        if (memory16get(ds*16+si + 48) != 0x0003) {
            pc = 0x17394;
            break;
        }
        if (!(r8[ch] & 0x10)) {
            pc = 0x17394;
            break;
        }
        yield* sub_176F4();
        if (flags.carry) {
            pc = 0x17394;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 2);
        r16[bx] &= 0x001f;
        if (r16[bx] != 0x0004) {
            pc = 0x17394;
            break;
        }
        memory16set(ds*16+si + 42, 0x0001);
        pc = 0x1740E;
        break;
    case 0x17394:
        memory16set(ds*16+si + 42, 0x0000);
        memory16set(ds*16+si + 34, 0x0001);
        r16[ax] += 0x000c;
        r16[ax] |= 0x0007;
        r16[ax] -= 0x0014;
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+si + 4, r16[ax]);
        memory[ds*16+si + 6] = r8[cl];
        r16[dx] = 0x0100;
        if (!(r8[ch] & 0x01)) {
            pc = 0x173E4;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0003) {
            pc = 0x173E4;
            break;
        }
        r16[dx] = memory16get(ds*16+si + 8);
        if (r16s[dx] < signed16(0x0200)) {
            pc = 0x173D8;
            break;
        }
        r16[dx] = -r16[dx];
        r16[dx] += 0x0060;
        memory16set(ds*16+si + 8, r16[dx]);
        r16[dx] = 0xf781;
        pc = 0x1740E;
        break;
    case 0x173D8:
        memory16set(ds*16+si + 8, 0x0100);
        r16[dx] = 0xfa00;
        pc = 0x1740E;
        break;
    case 0x173E4:
        memory16set(ds*16+si + 8, r16[dx]);
        r16[dx] = 0xfa00;
        if (!(r8[ch] & 0x01)) {
            pc = 0x1740E;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0001) {
            pc = 0x173FF;
            break;
        }
        r16[dx] = 0xfe00;
        pc = 0x1740E;
        break;
        _STOP_("db 90h");
    case 0x173FF:
        if (memory16get(ds*16+0x8BEC) != 0x0005) {
            pc = 0x1740E;
            break;
        }
        memory16set(ds*16+si + 8, 0xf781);
        pc = 0x1743B;
        break;
    case 0x1740E:
        memory16set(ds*16+si + 4, r16[ax]);
        memory[ds*16+si + 6] = r8[cl];
        if (memory16get(ds*16+si + 48) != 0x0003) {
            pc = 0x1743B;
            break;
        }
        if (!(r8[ch] & 0x08)) {
            pc = 0x1743B;
            break;
        }
        if (r8[ch] & 0x10) {
            pc = 0x1743B;
            break;
        }
        yield* sub_176F4();
        if (!flags.carry) {
            pc = 0x1743B;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 2);
        r16[bx] &= 0x001f;
        if (r16[bx] != 0x0004) {
            pc = 0x1743B;
            break;
        }
        memory16set(ds*16+si + 42, 0x0001);
    case 0x1743B:
        if (memory16get(ds*16+0x6E03) != 0x0001) {
            pc = 0x1744D;
            break;
        }
        r16[dx] = memory16get(ds*16+si + 44);
        r16[bx] = memory16get(ds*16+si + 2);
        r16[bx] += r16[dx];
        pc = 0x17573;
        break;
    case 0x1744D:
        bp = memory16get(cs*16+si + 8);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (flags.sign) {
            pc = 0x1745E;
            break;
        }
        if (memory16get(ds*16+si + 34) == 0x0001) {
            pc = 0x1745E;
            break;
        }
        pc = 0x1746A;
        break;
    case 0x1745E:
        if (memory16get(ds*16+si + 48) != 0x0003) {
            pc = 0x17473;
            break;
        }
        if (memory16get(ds*16+si + 42) != 0x0001) {
            pc = 0x17473;
            break;
        }
    case 0x1746A:
        r16[dx] = 0x0000;
        r16[bx] = memory16get(ds*16+si + 2);
        pc = 0x17573;
        break;
    case 0x17473:
        r16[dx] = memory16get(ds*16+si + 16);
        if (!(r8[ch] & 0x01)) {
            pc = 0x174A3;
            break;
        }
        if (memory16get(ds*16+0x8BEC) == 0x0002) {
            pc = 0x1749E;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0004) {
            pc = 0x174A3;
            break;
        }
        memory16set(ds*16+si + 38, 0x0001);
        r16[dx] = 0x0001;
        if (!(memory16get(ds*16+si + 16) & 0x8000)) {
            pc = 0x174A3;
            break;
        }
        r16[dx] = -r16[dx];
        pc = 0x174A3;
        break;
    case 0x1749E:
        memory16set(ds*16+si + 40, 0x0001);
    case 0x174A3:
        if (memory16get(ds*16+si + 48) != 0x0001) {
            pc = 0x174BE;
            break;
        }
        memory16set(ds*16+si + 20, memory16get(ds*16+si + 20) + 1);
        r16[ax] = memory16get(ds*16+si + 18);
        if (r16[ax] != memory16get(ds*16+si + 20)) {
            pc = 0x174F8;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+si + 20, r16[ax]);
        r16[dx] = -r16[dx];
        pc = 0x174F8;
        break;
    case 0x174BE:
        if (memory16get(ds*16+si + 48) != 0x0002) {
            pc = 0x174E0;
            break;
        }
        r16[ax] = memory16get(ds*16+si + 2);
        r16[ax] &= 0x000f;
        if (r16[ax] != 0x0004) {
            pc = 0x174F8;
            break;
        }
        yield* sub_19B40();
        if (memory[ds*16+0x973F] & 0x01) {
            pc = 0x174F8;
            break;
        }
        yield* sub_176E6();
        pc = 0x174F8;
        break;
    case 0x174E0:
        r16[ax] = memory16get(ds*16+si + 2);
        r16[ax] &= 0x000f;
        if (r16[ax] != 0x0004) {
            pc = 0x174F8;
            break;
        }
        yield* sub_19B40();
        if (memory[ds*16+0x973F] & 0x01) {
            pc = 0x174F8;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x174F8:
        r16[dx] = r16[dx] + memory16get(ds*16+si + 44);
        r16[bx] = memory16get(ds*16+si + 2);
        r16[bx] += r16[dx];
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (r16[dx] == 0) {
            pc = 0x1751E;
            break;
        }
        if (!flags.sign) {
            pc = 0x17513;
            break;
        }
        if (r16s[bx] >= signed16(0x0000)) {
            pc = 0x1751E;
            break;
        }
        r16[bx] = 0x0000;
        r16[dx] = -r16[dx];
        pc = 0x1751E;
        break;
        _STOP_("db 90h");
    case 0x17513:
        if (r16s[bx] < signed16(0x00e8)) {
            pc = 0x1751E;
            break;
        }
        r16[bx] = 0x00e8;
        r16[dx] = -r16[dx];
    case 0x1751E:
        r16[ax] = memory16get(ds*16+si + 4);
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0x7961, 0xffff);
        memory16set(ds*16+0x795D, r16[bx]);
        memory[ds*16+0x796B] = 0x01;
        yield* sub_17DFB();
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x17544;
            break;
        }
    {yield* sub_17674(); return; };
    case 0x17544:
        if (!(r8[ch] & 0x02)) {
            pc = 0x17573;
            break;
        }
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (!flags.sign) {
            pc = 0x17562;
            break;
        }
        r16[bx] += 0x000c;
        r16[bx] &= 0x00f8;
        r16[bx] -= 0x0004;
        r16[dx] = -r16[dx];
        memory16set(ds*16+si + 20, 0x0000);
        pc = 0x17573;
        break;
    case 0x17562:
        r16[bx] += 0x0003;
        r16[bx] &= 0x00f8;
        r16[bx] -= 0x0004;
        r16[dx] = -r16[dx];
        memory16set(ds*16+si + 20, 0x0000);
    case 0x17573:
        if (memory16get(ds*16+0x6E20) == 0x0001) {
            pc = 0x17584;
            break;
        }
        memory16set(ds*16+si + 2, r16[bx]);
        r16[dx] |= r16[dx];
        if (r16[dx] == 0) {
            pc = 0x17584;
            break;
        }
        memory16set(ds*16+si + 16, r16[dx]);
    case 0x17584:
        if (memory16get(ds*16+si + 48) != 0x0003) {
            pc = 0x17595;
            break;
        }
        if (r8[ch] & 0x08) {
            pc = 0x17595;
            break;
        }
        memory16set(ds*16+si + 42, 0x0000);
    case 0x17595:
        if (memory16get(ds*16+0x6E03) == 0x0001) {
            pc = 0x175A6;
            break;
        }
        if (memory16get(ds*16+0x6E20) == 0x0001) {
            pc = 0x175A6;
            break;
        }
        yield* sub_17723();
    case 0x175A6:
        if (memory16get(ds*16+0x7ECC) != 0x0001) {
            pc = 0x175C6;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        yield* sub_1646E();
        if (!flags.carry) {
            pc = 0x175C6;
            break;
        }
        memory16set(ds*16+si + 24, 0x0028);
        pc = 0x175DE;
        break;
    case 0x175C6:
        r16[bx] = memory16get(ds*16+si + 4);
        r16[bx] += 0x0004;
        r8[dh] = memory[ds*16+si + 2];
        r8[dh] += 0x04;
        r8[dl] = 0x10;
        r8[ah] = 0x15;
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x175DE;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x175DE:
        if (memory16get(ds*16+0xB00) != 0x0001) {
            pc = 0x175FF;
            break;
        }
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        yield* sub_164A0();
        if (!flags.carry) {
            pc = 0x175FF;
            break;
        }
        memory16set(ds*16+0xB00, 0x0000);
    {yield* sub_17674(); return; };
        _STOP_("db 90h");
    case 0x175FF:
        if (memory16get(ds*16+0xB38) != 0x0002)
            return;
        r8[al] = memory[ds*16+0xB4A];
        if (r8s[al] <= signed8(0x01))
            return;
        if (r8s[al] > signed8(0x04))
            return;
        r16[bx] = memory16get(ds*16+si + 4);
        r8[dh] = memory[ds*16+si + 2];
        r8[dl] = memory[ds*16+si + 30];
        r8[ah] = memory[ds*16+si + 32];
        if (r8[dh] >= 0x0f) {
            pc = 0x17627;
            break;
        }
        r8[dh] = r8[dh] ^ r8[dh];
        pc = 0x1762A;
        break;
        _STOP_("db 90h");
    case 0x17627:
        r8[dh] -= 0x10;
    case 0x1762A:
        r16[bx] -= 0x000e;
        r8[dl] += 0x20;
        r8[ah] += 0x1d;
        yield* sub_164E1();
        if (!flags.carry)
            return;
        push(si);
        si = 0x670b;
        yield* sub_16BC7();
        si = pop();
    {yield* sub_17674(); return; };
        _STOP_("db 90h");
        return;
    case 0x17644:
        r16[ax] = memory16get(ds*16+si + 4);
        r8[cl] = r8[cl] ^ r8[cl];
        bp = memory16get(ds*16+0xB20);
        bp += 1;
        bp &= 0x00fe;
        r16[ax] &= 0x00fe;
        yield* sub_17702();
        memory16set(ds*16+0x7961, bp);
        r16[ax] = memory16get(ds*16+si + 4);
        r16[ax] += bp;
        memory16set(ds*16+si + 8, bp);
        memory16set(ds*16+0x795F, r16[ax]);
        r16[bx] = memory16get(ds*16+si + 2);
        memory16set(ds*16+0x795D, r16[bx]);
        yield* sub_17DFB();
        pc = 0x172CD;
        break;
        return;
    } while (1);
}
function* sub_17674() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        si = 0x670b;
        yield* sub_16BC7();
        si = pop();
        memory16set(ds*16+si + 22, 0x0001);
        memory16set(ds*16+si + 8, 0xfb00);
        r16[ax] = 0x000c;
        yield* sub_1AECD();
        r16[ax] = memory16get(ds*16+si + 2);
        if (r16s[ax] < signed16(0x0080)) {
            pc = 0x1769A;
            break;
        }
        memory16set(ds*16+si + 16, 0xfffe);
        return;
    case 0x1769A:
        memory16set(ds*16+si + 16, 0x0002);
        return;
    } while (1);
}
function* loc_176A0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds*16+si + 8);
        r16[dx] += 0x0080;
        memory16set(ds*16+si + 8, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x176B3;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x176B5;
        break;
        _STOP_("db 90h");
    case 0x176B3:
        r8[ch] = 0xff;
    case 0x176B5:
        r16[ax] = memory16get(ds*16+si + 4);
        r8[cl] = memory[ds*16+si + 6];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        if (r16s[ax] <= signed16(0x0110)) {
            pc = 0x176CA;
            break;
        }
        yield* sub_16174();
        return;
    case 0x176CA:
        memory16set(ds*16+si + 4, r16[ax]);
        memory[ds*16+si + 6] = r8[cl];
        r16[ax] = memory16get(ds*16+0x73EF);
        r16[ax] += 0x0006;
        r16[ax] = r16[ax] + memory16get(ds*16+si + 50);
        memory16set(ds*16+si + 10, r16[ax]);
        r16[ax] = memory16get(ds*16+si + 16);
        r16[ax] = r16[ax] + memory16get(ds*16+si + 2);
        memory16set(ds*16+si + 2, r16[ax]);
        return;
    } while (1);
}
function* sub_176E6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[bx] <= memory16gets(ds*16+0xB1E)) {
            pc = 0x176F0;
            break;
        }
        r16[dx] = 0xfffe;
        return;
    case 0x176F0:
        r16[dx] = 0x0002;
        return;
    } while (1);
}
function* sub_176F4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[ax] < memory16gets(ds*16+0xB20)) {
            pc = 0x176FE;
            break;
        }
        if (r16[ax] == memory16get(ds*16+0xB20)) {
            pc = 0x17700;
            break;
        }
        flags.carry = true;
        return;
    case 0x176FE:
        flags.carry = false;
        return;
    case 0x17700:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_17702() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x6E20) != 0x0001) {
            pc = 0x1770E;
            break;
        }
        flags.carry = false;
        bp = 0x0000;
        return;
    case 0x1770E:
        if (r16s[ax] < signed16(bp)) {
            pc = 0x17719;
            break;
        }
        if (r16[ax] == bp) {
            pc = 0x1771E;
            break;
        }
        bp = 0xfffe;
        flags.carry = true;
        return;
    case 0x17719:
        bp = 0x0002;
        flags.carry = false;
        return;
    case 0x1771E:
        bp = 0x0000;
        flags.carry = false;
        return;
    } while (1);
}
function* sub_17723() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+si + 42) == 0x0001) {
            pc = 0x17756;
            break;
        }
        if (memory16get(ds*16+si + 38) == 0x0001) {
            pc = 0x17770;
            break;
        }
        if (memory16get(ds*16+si + 40) == 0x0001) {
            pc = 0x1778B;
            break;
        }
        if (memory16get(ds*16+si + 34) != 0x0001)
            return;
        r16[ax] = memory16get(ds*16+si + 16);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x17748;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x1774B;
        break;
    case 0x17748:
        r16[ax] = 0x0003;
    case 0x1774B:
        r16[ax] = r16[ax] + memory16get(ds*16+0x73E7);
        r16[ax] = r16[ax] + memory16get(ds*16+si + 50);
        memory16set(ds*16+si + 10, r16[ax]);
        return;
    case 0x17756:
        if (memory16get(ds*16+si + 42) != 0x0001) {
            pc = 0x17770;
            break;
        }
        r16[ax] = 0x0008;
        if (memory16get(ds*16+si + 8) == 0x0000) {
            pc = 0x17769;
            break;
        }
        r16[ax] = r16[ax] + memory16get(ds*16+0x73ED);
    case 0x17769:
        r16[ax] = r16[ax] + memory16get(ds*16+si + 50);
        memory16set(ds*16+si + 10, r16[ax]);
        return;
    case 0x17770:
        r16[ax] = memory16get(ds*16+si + 16);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x1777D;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x17780;
        break;
        _STOP_("db 90h");
    case 0x1777D:
        r16[ax] = 0x0003;
    case 0x17780:
        r16[ax] = r16[ax] + memory16get(ds*16+0x73E9);
        r16[ax] = r16[ax] + memory16get(ds*16+si + 50);
        memory16set(ds*16+si + 10, r16[ax]);
        return;
    case 0x1778B:
        r16[ax] = memory16get(ds*16+si + 16);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x17798;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x1779B;
        break;
    case 0x17798:
        r16[ax] = 0x0003;
    case 0x1779B:
        r16[ax] = r16[ax] + memory16get(ds*16+0x73EB);
        r16[ax] = r16[ax] + memory16get(ds*16+si + 50);
        memory16set(ds*16+si + 10, r16[ax]);
        return;
        return;
    } while (1);
}
function* sub_177FB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x73F1);
    case 0x177FE:
        r16[bx] = 0x73a7;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx]);
        if (r16[dx] != 0x00ff) {
            pc = 0x17810;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x177FE;
        break;
    case 0x17810:
        memory16set(ds*16+0x73E7, r16[dx]);
        r16[ax] += 1;
        r16[ax] += 1;
        memory16set(ds*16+0x73F1, r16[ax]);
        r16[ax] = memory16get(ds*16+0x73F3);
    case 0x1781C:
        r16[bx] = 0x73b5;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx]);
        if (r16[dx] != 0x00ff) {
            pc = 0x1782E;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x1781C;
        break;
    case 0x1782E:
        memory16set(ds*16+0x73E9, r16[dx]);
        r16[ax] += 1;
        r16[ax] += 1;
        memory16set(ds*16+0x73F3, r16[ax]);
        r16[ax] = memory16get(ds*16+0x73F5);
    case 0x1783A:
        r16[bx] = 0x73cf;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx]);
        if (r16[dx] != 0x00ff) {
            pc = 0x1784C;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x1783A;
        break;
    case 0x1784C:
        memory16set(ds*16+0x73EB, r16[dx]);
        r16[ax] += 1;
        r16[ax] += 1;
        memory16set(ds*16+0x73F5, r16[ax]);
        r16[ax] = memory16get(ds*16+0x73F7);
    case 0x17858:
        r16[bx] = 0x73d7;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx]);
        if (r16[dx] != 0x00ff) {
            pc = 0x1786A;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x17858;
        break;
    case 0x1786A:
        memory16set(ds*16+0x73ED, r16[dx]);
        r16[ax] += 1;
        r16[ax] += 1;
        memory16set(ds*16+0x73F7, r16[ax]);
        r16[ax] = memory16get(ds*16+0x73F9);
    case 0x17876:
        r16[bx] = 0x73e1;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx]);
        if (r16[dx] != 0x00ff) {
            pc = 0x17888;
            break;
        }
        r16[ax] = 0x0000;
        pc = 0x17876;
        break;
    case 0x17888:
        memory16set(ds*16+0x73EF, r16[dx]);
        r16[ax] += 1;
        r16[ax] += 1;
        memory16set(ds*16+0x73F9, r16[ax]);
        return;
    } while (1);
}
function* sub_17896() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+si + 16);
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] != 0x00) {
            pc = 0x178A5;
            break;
        }
        r16[bx] += 1;
        r16[bx] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+si + 16, r16[bx]);
    case 0x178A5:
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        if (r8[al] != 0x07) {
            pc = 0x178B6;
            break;
        }
        r8[al] += 1;
    case 0x178B6:
        _cbw();
        memory16set(ds*16+0x7492, r16[ax]);
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] &= 0x0f;
        if (!(r8[al] & 0x08)) {
            pc = 0x178C4;
            break;
        }
        r8[al] |= 0xf0;
    case 0x178C4:
        if (r8[al] != 0x07) {
            pc = 0x178CA;
            break;
        }
        r8[al] += 1;
    case 0x178CA:
        _cbw();
        memory16set(ds*16+0x7494, r16[ax]);
        r16[bx] -= 1;
        r8[al] = memory[ds*16+r16[bx]];
        _cbw();
        memory16set(ds*16+si + 18, memory16get(ds*16+si + 18) + 1);
        if (r16[ax] == memory16get(ds*16+si + 18)) {
            pc = 0x178DC;
            break;
        }
        if (r16[ax] >= memory16get(ds*16+si + 18)) {
            pc = 0x178E6;
            break;
        }
    case 0x178DC:
        memory16set(ds*16+si + 18, 0x0000);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+si + 16, r16[bx]);
    case 0x178E6:
        r16[ax] = memory16get(ds*16+0x7492);
        r16[dx] = memory16get(ds*16+0x7494);
        return;
    } while (1);
}
function* sub_17A31() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x7629, 0x0014);
        di = 0x0c28;
        si = 0x74ee;
        r16[cx] = 0x0005;
    case 0x17A40:
        memory16set(ds*16+di, 0x0001);
        lodsw_data_forward();
        memory16set(ds*16+di + 2, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+di + 4, r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 14, r16[ax]);
        memory16set(ds*16+di + 12, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+di + 22, r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 24, r16[ax]);
        push(si);
        push(di);
        push(r16[cx]);
        si = di;
        yield* sub_1718E();
        r16[cx] = pop();
        di = pop();
        si = pop();
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 24, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+di + 16, r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+di + 18, r16[ax]);
        memory16set(ds*16+di + 20, r16[ax]);
        di += 0x0034;
        if (--r16[cx]) {
            pc = 0x17A40;
            break;
        }
        memory16set(ds*16+0xD2C, r16[ax]);
        memory16set(ds*16+0x762B, r16[ax]);
        memory16set(ds*16+0x762F, 0x0001);
        return;
    } while (1);
}
function* sub_17A8B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x762D) != 0x0001)
            return;
        if (memory16get(ds*16+0x762F) == 0x0001) {
            pc = 0x17A9D;
            break;
        }
        return;
    case 0x17A9D:
        si = 0x0c28;
        yield* sub_17896();
        r16[cx] = 0x0005;
    case 0x17AA6:
        push(r16[cx]);
        memory16set(ds*16+si + 2, memory16get(ds*16+si + 2) + r16[ax]);
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[dx]);
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_1718E();
        r16[dx] = pop();
        r16[ax] = pop();
        si += 0x0034;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x17AA6;
            break;
        }
        r8[dh] = memory[ds*16+0xC2A];
        r16[bx] = memory16get(ds*16+0xC2C);
        r8[dl] = 0x1c;
        r8[ah] = 0x40;
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x17AD1;
            break;
        }
        yield* sub_168A8();
        pc = 0x17AEB;
        break;
        _STOP_("db 90h");
    case 0x17AD1:
        r8[dh] = memory[ds*16+0xC2A];
        r8[dh] += 0xec;
        r16[bx] = memory16get(ds*16+0xC2C);
        r16[bx] += 0x0018;
        r8[dl] = 0x14;
        r8[ah] = 0x20;
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x17AEB;
            break;
        }
        yield* sub_168A8();
    case 0x17AEB:
        r8[dh] = memory[ds*16+0xC2A];
        r16[bx] = memory16get(ds*16+0xC2C);
        r8[dl] = 0x1c;
        r8[ah] = 0x40;
        yield* sub_164A0();
        if (!flags.carry) {
            pc = 0x17B0D;
            break;
        }
        memory16set(ds*16+0xB00, 0x0000);
        yield* sub_17D53();
        if (!flags.carry) {
            pc = 0x17B0A;
            break;
        }
        pc = 0x17BA5;
        break;
    case 0x17B0A:
        pc = 0x17B2F;
        break;
        _STOP_("db 90h");
    case 0x17B0D:
        r8[dh] = memory[ds*16+0xC2A];
        r8[dh] += 0xec;
        r16[bx] = memory16get(ds*16+0xC2C);
        r16[bx] += 0x0018;
        r8[dl] = 0x14;
        r8[ah] = 0x20;
        yield* sub_164A0();
        if (!flags.carry) {
            pc = 0x17B2F;
            break;
        }
        memory16set(ds*16+0xB00, 0x0000);
        yield* sub_17D53();
        if (flags.carry) {
            pc = 0x17BA5;
            break;
        }
    case 0x17B2F:
        r8[dh] = memory[ds*16+0xC2A];
        r16[bx] = memory16get(ds*16+0xC2C);
        r8[dl] = 0x1c;
        r8[ah] = 0x40;
        r8[dh] -= 0x10;
        r16[bx] -= 0x000e;
        r8[dl] += 0x20;
        r8[ah] += 0x1d;
        if (memory16get(ds*16+0xB38) != 0x0002) {
            pc = 0x17B96;
            break;
        }
        if (memory16gets(ds*16+0xB4A) > signed16(0x0004)) {
            pc = 0x17B96;
            break;
        }
        if (memory16gets(ds*16+0xB4A) <= signed16(0x0001)) {
            pc = 0x17B96;
            break;
        }
        yield* sub_164E1();
        if (!flags.carry) {
            pc = 0x17B6E;
            break;
        }
        yield* sub_17D53();
        if (flags.carry) {
            pc = 0x17BA5;
            break;
        }
        yield* sub_17D53();
        if (flags.carry) {
            pc = 0x17BA5;
            break;
        }
        pc = 0x17B96;
        break;
    case 0x17B6E:
        r8[dh] = memory[ds*16+0xC2A];
        r8[dh] += 0xec;
        r16[bx] = memory16get(ds*16+0xC2C);
        r16[bx] += 0x0018;
        r8[dl] = 0x14;
        r8[ah] = 0x20;
        r8[dh] -= 0x10;
        r16[bx] -= 0x000e;
        r8[dl] += 0x20;
        r8[ah] += 0x1d;
        yield* sub_164E1();
        if (!flags.carry) {
            pc = 0x17B96;
            break;
        }
        yield* sub_17D53();
        if (flags.carry) {
            pc = 0x17BA5;
            break;
        }
    case 0x17B96:
        if (memory16get(ds*16+0xD2C) == 0x0001) {
            pc = 0x17BA1;
            break;
        }
        yield* sub_17C64();
        return;
    case 0x17BA1:
        yield* sub_17CF4();
        return;
    case 0x17BA5:
        memory16set(ds*16+0x762D, 0x0000);
        memory16set(ds*16+0x762F, 0x0000);
        memory[ds*16+0x5B3E] = 0x01;
        r16[cx] = 0x0005;
        si = 0x758b;
        di = 0x0c28;
    case 0x17BBF:
        memory16set(ds*16+di, 0x0011);
        memory16set(ds*16+di + 50, 0x0060);
        memory16set(ds*16+di + 28, 0x0000);
        memory16set(ds*16+di + 24, 0x0000);
        lodsw_data_forward();
        memory16set(ds*16+di + 22, r16[ax]);
        memory16set(ds*16+di + 18, 0x0000);
        memory16set(ds*16+di + 20, 0x0000);
        lodsw_data_forward();
        memory16set(ds*16+di + 16, r16[ax]);
        di += 0x0034;
        if (--r16[cx]) {
            pc = 0x17BBF;
            break;
        }
        di = 0x0b56;
        memory16set(ds*16+di, 0x0001);
        r16[ax] = memory16get(ds*16+0xC2A);
        memory16set(ds*16+di + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+0xC2C);
        memory16set(ds*16+di + 4, r16[ax]);
        memory16set(ds*16+di + 50, 0x0034);
        memory16set(ds*16+di + 22, 0x0001);
        memory16set(ds*16+di + 24, 0x0000);
        memory16set(ds*16+di + 6, 0x0000);
        memory16set(ds*16+di + 8, 0xfb00);
        memory16set(ds*16+di + 16, 0xfffe);
        memory16set(ds*16+di + 28, 0x0000);
        memory16set(ds*16+0xD2C, 0x0000);
        if (memory16get(ds*16+0x8BEE) != 0x0001)
            return;
        r16[cx] = memory16get(ds*16+0x6610);
        r16[cx] |= r16[cx];
        if (r16[cx] == 0) {
            pc = 0x17C3E;
            break;
        }
    case 0x17C34:
        si = 0x6729;
        push(r16[cx]);
        yield* sub_16BC7();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x17C34;
            break;
        }
    case 0x17C3E:
        r16[cx] = memory16get(ds*16+0x6612);
        r16[cx] |= r16[cx];
        if (r16[cx] == 0) {
            pc = 0x17C50;
            break;
        }
    case 0x17C46:
        si = 0x672f;
        push(r16[cx]);
        yield* sub_16BC7();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x17C46;
            break;
        }
    case 0x17C50:
        r16[cx] = memory16get(ds*16+0x6614);
        r16[cx] += 1;
        r16[cx] |= r16[cx];
        if (r16[cx] == 0)
            return;
    case 0x17C59:
        si = 0x6735;
        push(r16[cx]);
        yield* sub_16BC7();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x17C59;
            break;
        }
        return;
    } while (1);
}
function* sub_17C64() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory16get(ds*16+0x762B) & 0xffff)) {
            pc = 0x17C71;
            break;
        }
        memory16set(ds*16+0x762B, memory16get(ds*16+0x762B) - 1);
        return;
    case 0x17C71:
        r16[ax] = 0x000d;
        yield* sub_1AECD();
        memory16set(ds*16+0x762B, 0x0032);
        memory16set(ds*16+0xD2C, 0x0001);
        memory16set(ds*16+0xD36, 0x0055);
        r16[ax] = memory16get(ds*16+0xB1E);
        r16[ax] += 0x000c;
        r16[bx] = memory16get(ds*16+0xB20);
        r16[bx] += 0x000a;
        r16[cx] = memory16get(ds*16+0xC2A);
        r16[cx] += 0xffe4;
        memory16set(ds*16+0xD2E, r16[cx]);
        r16[dx] = memory16get(ds*16+0xC2C);
        r16[dx] += 0x002c;
        memory16set(ds*16+0xD30, r16[dx]);
        r16[ax] -= r16[cx];
        r16[cx] = r16[ax];
        r16[bx] -= r16[dx];
        r16[dx] = r16[bx];
    case 0x17CB4:
        if (r16s[ax] > signed16(0x0004)) {
            pc = 0x17CCB;
            break;
        }
        if (r16s[ax] < signed16(0xfffc)) {
            pc = 0x17CCB;
            break;
        }
        if (r16s[bx] > signed16(0x0004)) {
            pc = 0x17CCB;
            break;
        }
        if (r16s[bx] < signed16(0xfffc)) {
            pc = 0x17CCB;
            break;
        }
        pc = 0x17CEC;
        break;
        _STOP_("db 90h");
    case 0x17CCB:
        sar16(ax, 1);
        sar16(bx, 1);
        if (r16[ax] != 0x0000) {
            pc = 0x17CB4;
            break;
        }
        if (r16[bx] != 0x0000) {
            pc = 0x17CB4;
            break;
        }
        r16[ax] = 0x0004;
        r16[bx] = r16[ax];
        if (r16s[cx] >= signed16(0x0000)) {
            pc = 0x17CE5;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x17CE5:
        if (r16s[dx] >= signed16(0x0000)) {
            pc = 0x17CE5;
            break;
        }
        r16[bx] = -r16[bx];
    case 0x17CEC:
        memory16set(ds*16+0xD3C, r16[ax]);
        memory16set(ds*16+0xD34, r16[bx]);
        return;
    } while (1);
}
function* sub_17CF4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x762B, memory16get(ds*16+0x762B) - 1);
        if (memory16gets(ds*16+0x762B) >= 0) {
            pc = 0x17D00;
            break;
        }
        memory16set(ds*16+0x762B, 0x0000);
    case 0x17D00:
        r16[ax] = memory16get(ds*16+0xD2E);
        r16[ax] = r16[ax] + memory16get(ds*16+0xD3C);
        memory16set(ds*16+0xD2E, r16[ax]);
        r16[dx] = memory16get(ds*16+0xD30);
        r16[dx] = r16[dx] + memory16get(ds*16+0xD34);
        memory16set(ds*16+0xD30, r16[dx]);
        r16[ax] += 0x0004;
        if (r16s[ax] <= signed16(0x0004)) {
            pc = 0x17D4C;
            break;
        }
        if (r16s[ax] >= signed16(0x00fc)) {
            pc = 0x17D4C;
            break;
        }
        r16[dx] += 0x0004;
        memory16set(ds*16+0x795D, r16[ax]);
        memory16set(ds*16+0x795F, r16[dx]);
        yield* sub_18014();
        r8[ch] = memory[ds*16+0x7963];
        if (r8[ch] & 0x02) {
            pc = 0x17D4C;
            break;
        }
        r16[ax] -= 1;
        r16[ax] -= 1;
        r16[bx] = r16[dx];
        r8[dh] = r8[al];
        r8[dl] = 0x04;
        r8[ah] = 0x04;
        yield* sub_16407();
        if (!flags.carry)
            return;
        yield* sub_168A8();
    case 0x17D4C:
        memory16set(ds*16+0xD2C, 0x0000);
        return;
    } while (1);
}
function* sub_17D53() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x7629, memory16get(ds*16+0x7629) - 1);
        if (memory16get(ds*16+0x7629) == 0) {
            pc = 0x17D5B;
            break;
        }
        flags.carry = false;
        return;
    case 0x17D5B:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_17D70() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        memory16set(ds*16+0x796C, 0x0005);
        memory16set(ds*16+0x796E, 0x0010);
        memory16set(ds*16+0x7964, 0x7fff);
        memory16set(ds*16+0x7E02, 0x0000);
        r16[cx] = 0x0003;
        r16[dx] = memory16get(ds*16+0x795F);
        r16[dx] &= 0x0007;
        if (r16s[dx] >= signed16(0x0004)) {
            pc = 0x17D9F;
            break;
        }
        r16[cx] = 0x0002;
    case 0x17D9F:
        memory[ds*16+0x796A] = 0x00;
        bp = 0x0004;
        yield* sub_17FF3();
        r16[dx] &= 0x0007;
        if (r16[dx] == 0) {
            pc = 0x17DD7;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        si += 0x001d;
        r8[bl] &= 0x02;
        if (r8[bl] == 0)
            {
            yield* sub_17DFB(0x17E2F);
            return;
        }
        memory16set(ds*16+0x7E02, 0x0001);
        yield* sub_17DFB(0x17E2F);
        return;
        _STOP_("db 90h");
    case 0x17DD7:
        r16[ax] = r16[ax] ^ r16[ax];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        si += 0x001e;
        r8[bl] &= 0x02;
        if (r8[bl] != 0) {
            pc = 0x17DF2;
            break;
        }
        yield* sub_17DFB(0x17E8A);
        return;
    case 0x17DF2:
        memory16set(ds*16+0x7E02, 0x0001);
        yield* sub_17DFB(0x17E8A);
        return;
    } while (1);
}
function* sub_17DFB(pc) {
    if (!pc) pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        memory16set(ds*16+0x796C, 0x0000);
        memory16set(ds*16+0x796E, 0x0015);
        memory16set(ds*16+0x7964, 0x7fff);
        r16[cx] = 0x0004;
        r16[dx] = memory16get(ds*16+0x795F);
        r16[dx] &= 0x0007;
        if (r16s[dx] >= signed16(0x0004)) {
            pc = 0x17E24;
            break;
        }
        r16[cx] = 0x0003;
    case 0x17E24:
        bp = 0x0004;
        yield* sub_17FF3();
        r16[dx] &= 0x0007;
        if (r16[dx] == 0) {
            pc = 0x17E8A;
            break;
        }
    case 0x17E2F:
        r16[bx] = r16[bx] ^ r16[bx];
        r16[ax] = r16[ax] ^ r16[ax];
        pc = 0x17E4E;
        break;
    case 0x17E36:
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bh] = r8[bh] | memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        si += 0x001d;
    case 0x17E4E:
        if (--r16[cx]) {
            pc = 0x17E36;
            break;
        }
        r8[bl] &= 0x22;
        r8[bh] &= 0x2a;
        memory[ds*16+0x796A] = r8[bl];
        memory[ds*16+0x796A] |= r8[bh];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bh] = memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        r8[bl] &= 0x27;
        r8[bh] &= 0x7f;
        memory[ds*16+0x796A] |= r8[bl];
        memory[ds*16+0x796A] |= r8[bh];
        r8[al] = memory[ds*16+0x796A];
        memory[ds*16+0x7963] = r8[al];
        pc = 0x17EC9;
        break;
    case 0x17E8A:
        r16[bx] = r16[bx] ^ r16[bx];
        r16[ax] = r16[ax] ^ r16[ax];
        pc = 0x17EA2;
        break;
        _STOP_("db 90h");
    case 0x17E91:
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        si += 0x001e;
    case 0x17EA2:
        if (--r16[cx]) {
            pc = 0x17E91;
            break;
        }
        r8[bl] &= 0x2a;
        memory[ds*16+0x796A] = r8[bl];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+((di + 21492)&0xffff)];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+((di + 21492)&0xffff)];
        r8[bl] &= 0x7f;
        memory[ds*16+0x796A] |= r8[bl];
        r8[al] = memory[ds*16+0x796A];
        memory[ds*16+0x7963] = r8[al];
        pc = 0x17EC9;
        break;
        _STOP_("db 90h");
    case 0x17EC9:
        r16[ax] = memory16get(ds*16+0x7961);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x17ED8;
            break;
        }
        r8[al] = memory[ds*16+0x7963];
        r8[al] &= 0xfb;
        memory[ds*16+0x7963] = r8[al];
    case 0x17ED8:
        if (memory[ds*16+0x796B] == 0x01) {
            pc = 0x17EE2;
            break;
        }
        pc = 0x17FB9;
        break;
    case 0x17EE2:
        si = 0x0c28;
    case 0x17EE5:
        r16[ax] = memory16get(ds*16+si);
        if (r16[ax] != 0xffff) {
            pc = 0x17EEF;
            break;
        }
        pc = 0x17FB9;
        break;
    case 0x17EEF:
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x17EF6;
            break;
        }
        pc = 0x17FB3;
        break;
    case 0x17EF6:
        if (r8[al] & 0x80) {
            pc = 0x17EFD;
            break;
        }
        pc = 0x17FB3;
        break;
    case 0x17EFD:
        if (!(r8[al] & 0x40)) {
            pc = 0x17F68;
            break;
        }
        r8[cl] = memory[ds*16+si + 2];
        di = memory16get(ds*16+si + 4);
        r8[dl] = memory[ds*16+si + 30];
        r8[bl] = memory[ds*16+si + 32];
        r8[ch] = memory[ds*16+0x795D];
        r8[ch] += 0x04;
        bp = memory16get(ds*16+0x795F);
        bp = bp + memory16get(ds*16+0x796C);
        r8[dh] = 0x10;
        r8[bh] = memory[ds*16+0x796E];
        push(si);
        yield* sub_17FBF();
        si = pop();
        if (flags.carry) {
            pc = 0x17F2F;
            break;
        }
        pc = 0x17FB3;
        break;
    case 0x17F2F:
        memory[ds*16+0x7963] |= 0x02;
        if (signed16(di) > memory16gets(ds*16+0x7964)) {
            pc = 0x17F65;
            break;
        }
        r16[bx] = memory16get(ds*16+0x795F);
        r16[bx] += 0x0014;
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+0x7962];
        _cbw();
        r16[ax] += 0x0008;
        r16[ax] += di;
        if (r16s[bx] > r16s[ax]) {
            pc = 0x17F65;
            break;
        }
        memory16set(ds*16+0x7964, di);
        memory16set(ds*16+0x7966, 0x0000);
        memory16set(ds*16+0x7968, 0x0000);
        memory[ds*16+0x7963] |= 0x40;
    case 0x17F65:
        pc = 0x17FB3;
        break;
    case 0x17F68:
        r16[ax] = memory16get(ds*16+0x7961);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x17FB3;
            break;
        }
        r8[cl] = memory[ds*16+si + 2];
        di = memory16get(ds*16+si + 4);
        r8[dl] = memory[ds*16+si + 30];
        r8[bl] = memory[ds*16+0x7962];
        r8[bl] += 0x08;
        r8[ch] = memory[ds*16+0x795D];
        r8[ch] += 0x04;
        bp = memory16get(ds*16+0x795F);
        bp += 0x0014;
        r8[dh] = 0x10;
        r8[bh] = 0x01;
        push(si);
        yield* sub_17FBF();
        si = pop();
        if (!flags.carry) {
            pc = 0x17FB3;
            break;
        }
        if (signed16(di) > memory16gets(ds*16+0x7964)) {
            pc = 0x17FB3;
            break;
        }
        memory[ds*16+0x7963] |= 0x40;
        memory16set(ds*16+0x7964, di);
        r16[ax] = memory16get(ds*16+si + 46);
        memory16set(ds*16+0x7966, r16[ax]);
        r16[ax] = memory16get(ds*16+si + 48);
        memory16set(ds*16+0x7968, r16[ax]);
    case 0x17FB3:
        si += 0x0034;
        pc = 0x17EE5;
        break;
    case 0x17FB9:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_17FBF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = r8[ch];
        si = r16[ax];
        r8[al] = r8[dh];
        si += r16[ax];
        r8[al] = r8[cl];
        if (signed16(si) <= r16s[ax]) {
            pc = 0x17FF1;
            break;
        }
        si = r16[ax];
        r8[al] = r8[dl];
        si += r16[ax];
        r8[al] = r8[ch];
        if (signed16(si) <= r16s[ax]) {
            pc = 0x17FF1;
            break;
        }
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = r8[bh];
        r16[cx] += bp;
        if (r16s[cx] <= signed16(di)) {
            pc = 0x17FF1;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = r8[bl];
        r16[ax] += di;
        if (r16s[ax] <= signed16(bp)) {
            pc = 0x17FF1;
            break;
        }
        flags.carry = true;
        return;
    case 0x17FF1:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_17FF3() {
    si = 0x563c;
    r16[dx] = memory16get(ds*16+0x795F);
    r16[dx] &= 0xfff8;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    si += r16[dx];
    r16[dx] = memory16get(ds*16+0x795D);
    r16[dx] += bp;
    bp = r16[dx];
    bp >>= 1;
    bp >>= 1;
    bp >>= 1;
    si += bp;
}
function* sub_18014() {
    push(r16[ax]);
    push(r16[dx]);
    bp = bp ^ bp;
    yield* sub_17FF3();
    r16[ax] = r16[ax] ^ r16[ax];
    lodsb_data_forward();
    di = r16[ax];
    r8[al] = memory[ds*16+di + 21492];
    memory[ds*16+0x7963] = r8[al];
    yield* sub_181C6();
    r16[dx] = pop();
    r16[ax] = pop();
}
function* sub_1802D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        r16[cx] = 0x0002;
        r16[ax] = memory16get(ds*16+0x795F);
        r16[ax] &= 0x0007;
        if (r16[ax] == 0) {
            pc = 0x1803F;
            break;
        }
        r16[cx] = 0x0003;
    case 0x1803F:
        bp = 0x0008;
        yield* sub_17FF3();
        r16[dx] &= 0x0007;
        if (r16[dx] == 0) {
            pc = 0x18083;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        r16[ax] = r16[ax] ^ r16[ax];
        pc = 0x18062;
        break;
        _STOP_("db 90h");
    case 0x18051:
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+di + 21492];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+di + 21492];
        si += 0x001e;
    case 0x18062:
        if (--r16[cx]) {
            pc = 0x18051;
            break;
        }
        r8[bl] &= 0x23;
        r8[bh] = r8[bl];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+di + 21492];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+di + 21492];
        r8[bl] &= 0x27;
        r8[bh] |= r8[bl];
        memory[ds*16+0x7963] = r8[bh];
        pc = 0x180AE;
        break;
        _STOP_("db 90h");
    case 0x18083:
        r16[bx] = r16[bx] ^ r16[bx];
        r16[ax] = r16[ax] ^ r16[ax];
        pc = 0x18094;
        break;
    case 0x1808A:
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = r8[bl] | memory[ds*16+di + 21492];
        si += 0x001f;
    case 0x18094:
        if (--r16[cx]) {
            pc = 0x1808A;
            break;
        }
        r8[bl] &= 0x2b;
        r8[bh] = r8[bl];
        lodsb_data_forward();
        di = r16[ax];
        r8[bl] = memory[ds*16+di + 21492];
        r8[bl] &= 0x27;
        r8[bh] |= r8[bl];
        memory[ds*16+0x7963] = r8[bh];
        pc = 0x180AE;
        break;
    case 0x180AE:
        r16[ax] = memory16get(ds*16+0x7961);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x180C0;
            break;
        }
        r8[bh] = memory[ds*16+0x7963];
        r8[bh] &= 0xfb;
        memory[ds*16+0x7963] = r8[bh];
    case 0x180C0:
        if (memory[ds*16+0x796B] == 0x01) {
            pc = 0x180CA;
            break;
        }
        pc = 0x1819F;
        break;
    case 0x180CA:
        si = 0x0c28;
    case 0x180CD:
        r16[ax] = memory16get(ds*16+si);
        if (r16[ax] != 0xffff) {
            pc = 0x180D7;
            break;
        }
        pc = 0x1819F;
        break;
    case 0x180D7:
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x180DE;
            break;
        }
        pc = 0x18199;
        break;
    case 0x180DE:
        if (r8[al] & 0x80) {
            pc = 0x180E5;
            break;
        }
        pc = 0x18199;
        break;
    case 0x180E5:
        if (!(r8[al] & 0x40)) {
            pc = 0x1814E;
            break;
        }
        r8[cl] = memory[ds*16+si + 2];
        di = memory16get(ds*16+si + 4);
        r8[dl] = memory[ds*16+si + 30];
        r8[bl] = memory[ds*16+si + 32];
        r8[ch] = memory[ds*16+0x795D];
        r8[ch] += 0x08;
        bp = memory16get(ds*16+0x795F);
        bp = bp + memory16get(ds*16+0x796C);
        r8[dh] = 0x08;
        r8[bh] = 0x10;
        push(si);
        yield* sub_17FBF();
        si = pop();
        if (flags.carry) {
            pc = 0x18115;
            break;
        }
        pc = 0x18199;
        break;
    case 0x18115:
        memory[ds*16+0x7963] |= 0x02;
        if (signed16(di) > memory16gets(ds*16+0x7964)) {
            pc = 0x1814B;
            break;
        }
        r16[bx] = memory16get(ds*16+0x795F);
        r16[bx] += 0x0010;
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+0x7962];
        _cbw();
        r16[ax] += 0x0008;
        r16[ax] += di;
        if (r16s[bx] > r16s[ax]) {
            pc = 0x1814B;
            break;
        }
        memory16set(ds*16+0x7964, di);
        memory16set(ds*16+0x7966, 0x0000);
        memory16set(ds*16+0x7968, 0x0000);
        memory[ds*16+0x7963] |= 0x40;
    case 0x1814B:
        pc = 0x18199;
        break;
    case 0x1814E:
        r16[ax] = memory16get(ds*16+0x7961);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x18199;
            break;
        }
        r8[cl] = memory[ds*16+si + 2];
        di = memory16get(ds*16+si + 4);
        r8[dl] = memory[ds*16+si + 30];
        r8[bl] = memory[ds*16+0x7962];
        r8[bl] += 0x08;
        r8[ch] = memory[ds*16+0x795D];
        r8[ch] += 0x08;
        bp = memory16get(ds*16+0x795F);
        bp += 0x000f;
        r8[dh] = 0x08;
        r8[bh] = 0x01;
        push(si);
        yield* sub_17FBF();
        si = pop();
        if (!flags.carry) {
            pc = 0x18199;
            break;
        }
        if (signed16(di) > memory16gets(ds*16+0x7964)) {
            pc = 0x18199;
            break;
        }
        memory[ds*16+0x7963] |= 0x40;
        memory16set(ds*16+0x7964, di);
        r16[ax] = memory16get(ds*16+si + 46);
        memory16set(ds*16+0x7966, r16[ax]);
        r16[ax] = memory16get(ds*16+si + 48);
        memory16set(ds*16+0x7968, r16[ax]);
    case 0x18199:
        si += 0x0034;
        pc = 0x180CD;
        break;
    case 0x1819F:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_181A4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = r8[ch];
        r8[ah] = r8[ah] ^ r8[ah];
        r8[ch] = r8[ch] ^ r8[ch];
        if (r16s[ax] < r16s[cx]) {
            pc = 0x181C4;
            break;
        }
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] += r16[dx];
        if (r16s[ax] > r16s[cx]) {
            pc = 0x181C4;
            break;
        }
        if (signed16(bp) < signed16(di)) {
            pc = 0x181C4;
            break;
        }
        r8[bh] = r8[bh] ^ r8[bh];
        di += r16[bx];
        if (signed16(bp) > signed16(di)) {
            pc = 0x181C4;
            break;
        }
        flags.carry = true;
        return;
    case 0x181C4:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_181C6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0c28;
    case 0x181C9:
        r16[ax] = memory16get(ds*16+si);
        if (r16[ax] == 0xffff)
            return;
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x181F8;
            break;
        }
        if (!(r8[al] & 0x80)) {
            pc = 0x181F8;
            break;
        }
        if (!(r8[al] & 0x40)) {
            pc = 0x181F8;
            break;
        }
        r8[ch] = memory[ds*16+0x795D];
        bp = memory16get(ds*16+0x795F);
        r8[cl] = memory[ds*16+si + 2];
        di = memory16get(ds*16+si + 4);
        r8[dl] = 0x18;
        r8[bl] = 0x15;
        yield* sub_181A4();
        if (!flags.carry) {
            pc = 0x181F8;
            break;
        }
        memory[ds*16+0x7963] |= 0x40;
    case 0x181F8:
        si += 0x0034;
        pc = 0x181C9;
        break;
        return;
    } while (1);
}
function* sub_18351() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x7E16) != 0x0001) {
            pc = 0x1835B;
            break;
        }
    {yield* loc_18F9A(); return; };
    case 0x1835B:
        yield* sub_19C05();
        r16[ax] = memory16get(ds*16+0xB20);
        memory16set(ds*16+0x7DFE, r16[ax]);
        memory[ds*16+0x90C2] = 0x00;
        memory16set(ds*16+0x7E1A, 0x0000);
        yield* sub_1C4CA();
        if (!(memory16get(ds*16+0x7ED2) & 0x00ff)) {
            pc = 0x1837F;
            break;
        }
        memory16set(ds*16+0x7ED2, memory16get(ds*16+0x7ED2) - 1);
    case 0x1837F:
        if (r8[al] == memory[ds*16+0x7ECA]) {
            pc = 0x18396;
            break;
        }
        memory[ds*16+0x7ECA] = 0x00;
        memory16set(ds*16+0x7ECC, 0x0000);
        memory16set(ds*16+0x7ED2, 0x0000);
    case 0x18396:
        if (memory16get(ds*16+0x7E00) != 0x0001) {
            pc = 0x183A0;
            break;
        }
    {yield* loc_18B03(); return; };
    case 0x183A0:
        r16[ax] = memory16get(ds*16+0x7E06);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x183AA;
            break;
        }
        pc = 0x18987;
        break;
    case 0x183AA:
        memory16set(ds*16+0x7E08, 0x0000);
        memory16set(ds*16+0x7E0A, 0x0000);
        memory16set(ds*16+0x7E0C, 0x0000);
        memory16set(ds*16+0x7E0E, 0x0000);
        memory16set(ds*16+0x7E10, 0x0000);
        memory16set(ds*16+0x7E14, 0x0000);
        memory[ds*16+0x796B] = 0x01;
        r16[dx] = memory16get(ds*16+0xB24);
        r16[dx] += 0x0080;
        if (r16s[dx] <= signed16(0x0800)) {
            pc = 0x183E4;
            break;
        }
        r16[dx] = 0x0800;
    case 0x183E4:
        memory16set(ds*16+0xB24, r16[dx]);
        memory16set(ds*16+0x7961, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x183F5;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x183F7;
        break;
        _STOP_("db 90h");
    case 0x183F5:
        r8[ch] = 0xff;
    case 0x183F7:
        r16[ax] = memory16get(ds*16+0xB20);
        r8[cl] = memory[ds*16+0xB22];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        memory16set(ds*16+0x795F, r16[ax]);
        r16[dx] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0x795D, r16[dx]);
        memory[ds*16+0x796B] = 0x01;
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x18421;
            break;
        }
        yield* sub_17D70();
        pc = 0x18424;
        break;
        _STOP_("db 90h");
    case 0x18421:
        yield* sub_17DFB();
    case 0x18424:
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x40)) {
            pc = 0x18485;
            break;
        }
        r16[ax] = memory16get(ds*16+0x7964);
        r8[cl] = r8[cl] ^ r8[cl];
        r16[ax] -= 0x0015;
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0xB20, r16[ax]);
        memory[ds*16+0xB22] = 0x00;
        memory16set(ds*16+0x7E08, 0x0001);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x7966);
        memory16set(ds*16+0x7E1A, r16[ax]);
        r16[ax] = pop();
        memory[ds*16+0x796B] = 0x00;
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x18460;
            break;
        }
        yield* sub_17D70();
        pc = 0x18463;
        break;
    case 0x18460:
        yield* sub_17DFB();
    case 0x18463:
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x1846F;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x1846F:
        r8[ch] &= 0x06;
        if (r8[ch] == 0) {
            pc = 0x1847B;
            break;
        }
        r8[ch] = memory[ds*16+0x7963];
        pc = 0x184A3;
        break;
        _STOP_("db 90h");
    case 0x1847B:
        r8[ch] = memory[ds*16+0x7963];
        r16[dx] = 0x0100;
        pc = 0x1857C;
        break;
    case 0x18485:
        if (!(r8[ch] & 0x20)) {
            pc = 0x1848D;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x1848D:
        if (r8[ch] & 0x04) {
            pc = 0x184DA;
            break;
        }
        if (r8[ch] & 0x02) {
            pc = 0x1849A;
            break;
        }
        pc = 0x186A8;
        break;
    case 0x1849A:
        bp = memory16get(cs*16+0xB24);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (!flags.sign) {
            pc = 0x184DA;
            break;
        }
    case 0x184A3:
        if (memory16get(ds*16+0x7E06) != 0x0001) {
            pc = 0x184C8;
            break;
        }
        bp = memory16get(cs*16+0xB1E);
        bp &= 0x001f;
        if (signed16(bp) >= signed16(0x000a)) {
            pc = 0x184C8;
            break;
        }
        bp = memory16get(cs*16+0xB1E);
        bp &= 0x00f0;
        bp |= 0x0004;
        memory16set(cs*16+0xB1E, bp);
    case 0x184C8:
        r16[ax] |= 0x0007;
        r16[ax] += 1;
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+0xB24, 0x0100);
        r16[dx] = 0x0100;
        pc = 0x186A8;
        break;
    case 0x184DA:
        if (!(r8[ch] & 0x10)) {
            pc = 0x18524;
            break;
        }
        if (memory[ds*16+0xB884] & 0x10) {
            pc = 0x18524;
            break;
        }
        if (memory16get(ds*16+0x7E04) == 0x0001) {
            pc = 0x18524;
            break;
        }
        if (memory16get(ds*16+0x7E06) != 0x0001) {
            pc = 0x184F8;
            break;
        }
        pc = 0x186A8;
        break;
    case 0x184F8:
        if (!(memory[ds*16+0xB884] & 0x04)) {
            pc = 0x18524;
            break;
        }
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[bx] &= 0x001f;
        if (r16s[bx] >= signed16(0x000a)) {
            pc = 0x18524;
            break;
        }
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[bx] &= 0x00f0;
        r16[bx] |= 0x0004;
        memory16set(ds*16+0xB1E, r16[bx]);
        memory16set(ds*16+0x7E06, 0x0001);
        pc = 0x186A8;
        break;
    case 0x18524:
        memory16set(ds*16+0x7E06, 0x0000);
        memory16set(ds*16+0x7E08, 0x0001);
        r16[ax] += 0x000c;
        r16[ax] |= 0x0007;
        r16[ax] -= 0x0014;
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+0xB20, r16[ax]);
        memory[ds*16+0xB22] = r8[cl];
        r16[dx] = 0x0100;
        if (!(r8[ch] & 0x01)) {
            pc = 0x1857C;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0003) {
            pc = 0x1857C;
            break;
        }
        r16[dx] = memory16get(ds*16+0xB24);
        if (r16s[dx] < signed16(0x0200)) {
            pc = 0x18570;
            break;
        }
        r16[dx] = -r16[dx];
        r16[dx] += 0x0060;
        memory16set(ds*16+0xB24, r16[dx]);
        r16[dx] = 0xf781;
        r16[ax] = 0x0016;
        yield* sub_1AECD();
        pc = 0x185AB;
        break;
    case 0x18570:
        memory16set(ds*16+0xB24, 0x0100);
        r16[dx] = 0xfa00;
        pc = 0x185AB;
        break;
    case 0x1857C:
        memory16set(ds*16+0xB24, r16[dx]);
        r16[dx] = 0xfa00;
        if (!(r8[ch] & 0x01)) {
            pc = 0x185AB;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0001) {
            pc = 0x18595;
            break;
        }
        r16[dx] = 0xfe00;
        pc = 0x185AB;
        break;
        _STOP_("db 90h");
    case 0x18595:
        if (memory16get(ds*16+0x8BEC) != 0x0005) {
            pc = 0x185AB;
            break;
        }
        r16[ax] = 0x0017;
        yield* sub_1AECD();
        memory16set(ds*16+0xB24, 0xf781);
        pc = 0x186C1;
        break;
    case 0x185AB:
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x185C5;
            break;
        }
        if (memory16get(ds*16+0x7E02) != 0x0001) {
            pc = 0x185BC;
            break;
        }
        pc = 0x186C1;
        break;
    case 0x185BC:
        memory16set(ds*16+0x7E04, 0x0000);
        pc = 0x185F2;
        break;
        _STOP_("db 90h");
    case 0x185C5:
        if (memory[ds*16+0xB884] & 0x10) {
            pc = 0x18606;
            break;
        }
        if (!(memory[ds*16+0xB884] & 0x08)) {
            pc = 0x185F2;
            break;
        }
        memory16set(ds*16+0xB24, r16[dx]);
        if (!(r8[ch] & 0x10)) {
            pc = 0x185E1;
            break;
        }
        pc = 0x186C1;
        break;
    case 0x185E1:
        if (r8[ch] & 0x08) {
            pc = 0x185E9;
            break;
        }
        pc = 0x186C1;
        break;
    case 0x185E9:
        memory16set(ds*16+0x7E06, 0x0001);
        pc = 0x186C1;
        break;
    case 0x185F2:
        if (memory[ds*16+0xB884] & 0x04) {
            pc = 0x185FD;
            break;
        }
        pc = 0x186C1;
        break;
    case 0x185FD:
        memory16set(ds*16+0x7E04, 0x0001);
        pc = 0x186C1;
        break;
    case 0x18606:
        if (!(memory[ds*16+0xB884] & 0x08)) {
            pc = 0x18611;
            break;
        }
        pc = 0x189C2;
        break;
    case 0x18611:
        memory16set(ds*16+0x7E12, 0x0001);
        if (!(memory[ds*16+0xB884] & 0x04)) {
            pc = 0x18622;
            break;
        }
        pc = 0x189FF;
        break;
    case 0x18622:
        push(r16[ax]);
        r8[al] = memory[ds*16+0xB884];
        if (r8[al] != memory[ds*16+0x7ECA]) {
            pc = 0x18630;
            break;
        }
        r16[ax] = pop();
        pc = 0x189DE;
        break;
    case 0x18630:
        r16[ax] = pop();
        if (!(memory[ds*16+0xB884] & 0x02)) {
            pc = 0x1866A;
            break;
        }
        memory16set(ds*16+0xB36, 0x0001);
        r16[bx] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0x7ECE, r16[bx]);
        memory16set(ds*16+0x7ED0, r16[ax]);
        memory16set(ds*16+0x7ED0, memory16get(ds*16+0x7ED0) + 0x0008);
        memory16set(ds*16+0x7ECC, 0x0001);
        memory16set(ds*16+0x7ED2, 0x000a);
        r8[al] = memory[ds*16+0xB884];
        memory[ds*16+0x7ECA] = r8[al];
        r16[ax] = 0x0022;
        yield* sub_1AECD();
        pc = 0x189DE;
        break;
    case 0x1866A:
        if (!(memory[ds*16+0xB884] & 0x01)) {
            pc = 0x186C1;
            break;
        }
        memory16set(ds*16+0xB36, 0x0000);
        r16[bx] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0x7ECE, r16[bx]);
        memory16set(ds*16+0x7ECE, memory16get(ds*16+0x7ECE) + 0x0018);
        memory16set(ds*16+0x7ED0, r16[ax]);
        memory16set(ds*16+0x7ED0, memory16get(ds*16+0x7ED0) + 0x0008);
        memory16set(ds*16+0x7ECC, 0x0001);
        memory16set(ds*16+0x7ED2, 0x000a);
        r8[al] = memory[ds*16+0xB884];
        memory[ds*16+0x7ECA] = r8[al];
        r16[ax] = 0x0022;
        yield* sub_1AECD();
        pc = 0x189DE;
        break;
    case 0x186A8:
        memory16set(ds*16+0xB20, r16[ax]);
        memory[ds*16+0xB22] = r8[cl];
        r8[al] = memory[ds*16+0xB884];
        r8[al] &= 0x0c;
        if (r8[al] == 0) {
            pc = 0x186C1;
            break;
        }
        if (!(r8[ch] & 0x08)) {
            pc = 0x186C1;
            break;
        }
        memory16set(ds*16+0x7E06, 0x0001);
    case 0x186C1:
        if (memory16get(ds*16+0x7E06) != 0x0001) {
            pc = 0x186E2;
            break;
        }
        if (r8[ch] & 0x08) {
            pc = 0x186E2;
            break;
        }
        memory16set(ds*16+0x7E06, 0x0000);
        bp = memory16get(cs*16+0xB24);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (!flags.sign) {
            pc = 0x186E2;
            break;
        }
        memory16set(ds*16+0xB24, 0xfe00);
    case 0x186E2:
        if (!(memory[ds*16+0xB884] & 0x02)) {
            pc = 0x1871E;
            break;
        }
        memory16set(ds*16+0xB36, 0x0001);
        r16[dx] = 0xfffe;
        if (r8[ch] & 0x01) {
            pc = 0x186FB;
            break;
        }
        pc = 0x1878A;
        break;
    case 0x186FB:
        if (memory16get(ds*16+0x8BEC) != 0x0004) {
            pc = 0x1870E;
            break;
        }
        r16[dx] = 0xffff;
        memory16set(ds*16+0x7E0C, 0x0001);
        pc = 0x1878A;
        break;
    case 0x1870E:
        if (memory16get(ds*16+0x8BEC) != 0x0002) {
            pc = 0x1878A;
            break;
        }
        memory16set(ds*16+0x7E0E, 0x0001);
        pc = 0x1878A;
        break;
    case 0x1871E:
        if (!(memory[ds*16+0xB884] & 0x01)) {
            pc = 0x18757;
            break;
        }
        memory16set(ds*16+0xB36, 0x0000);
        r16[dx] = 0x0002;
        if (!(r8[ch] & 0x01)) {
            pc = 0x1878A;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0004) {
            pc = 0x18747;
            break;
        }
        r16[dx] = 0x0001;
        memory16set(ds*16+0x7E0C, 0x0001);
        pc = 0x1878A;
        break;
        _STOP_("db 90h");
    case 0x18747:
        if (memory16get(ds*16+0x8BEC) != 0x0002) {
            pc = 0x1878A;
            break;
        }
        memory16set(ds*16+0x7E0E, 0x0001);
        pc = 0x1878A;
        break;
        _STOP_("db 90h");
    case 0x18757:
        r16[dx] = r16[dx] ^ r16[dx];
        if (r8[ch] & 0x01) {
            pc = 0x18767;
            break;
        }
        memory16set(ds*16+0xB34, 0xffff);
        pc = 0x1878A;
        break;
        _STOP_("db 90h");
    case 0x18767:
        if (memory16get(ds*16+0x8BEC) == 0x0002) {
            pc = 0x18777;
            break;
        }
        memory16set(ds*16+0xB34, 0xffff);
        pc = 0x1878A;
        break;
        _STOP_("db 90h");
    case 0x18777:
        memory16set(ds*16+0x7E0A, 0x0001);
        r16[dx] = 0x0002;
        if (memory16get(ds*16+0xB36) == 0x0000) {
            pc = 0x1878A;
            break;
        }
        r16[dx] = 0xfffe;
    case 0x1878A:
        r16[dx] = r16[dx] + memory16get(ds*16+0x7E1A);
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[bx] += r16[dx];
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (r16[dx] == 0) {
            pc = 0x187B9;
            break;
        }
        if (!flags.sign) {
            pc = 0x187AA;
            break;
        }
        if (r16s[bx] >= signed16(0x0000)) {
            pc = 0x187B9;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        memory[ds*16+0x90C2] = 0x01;
        pc = 0x187B9;
        break;
    case 0x187AA:
        if (r16s[bx] < signed16(0x00e8)) {
            pc = 0x187B9;
            break;
        }
        r16[bx] = 0x00e8;
        memory[ds*16+0x90C2] = 0x02;
    case 0x187B9:
        r16[ax] = memory16get(ds*16+0xB20);
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0x7961, 0xffff);
        memory16set(ds*16+0x795D, r16[bx]);
        memory[ds*16+0x796B] = 0x01;
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x187DB;
            break;
        }
        yield* sub_17D70();
        pc = 0x187DE;
        break;
        _STOP_("db 90h");
    case 0x187DB:
        yield* sub_17DFB();
    case 0x187DE:
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x187EA;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x187EA:
        if (!(r8[ch] & 0x02)) {
            pc = 0x18815;
            break;
        }
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (!flags.sign) {
            pc = 0x18804;
            break;
        }
        r16[bx] += 0x000c;
        r16[bx] &= 0x00f8;
        r16[bx] -= 0x0004;
        memory16set(ds*16+0xB1E, r16[bx]);
        pc = 0x1882B;
        break;
    case 0x18804:
        r16[bx] += 0x0003;
        r16[bx] &= 0x00f8;
        r16[bx] -= 0x0004;
        memory16set(ds*16+0xB1E, r16[bx]);
        pc = 0x1882B;
        break;
        _STOP_("db 90h");
    case 0x18815:
        memory16set(ds*16+0xB1E, r16[bx]);
        if (memory16get(ds*16+0x7E06) != 0x0001) {
            pc = 0x1882B;
            break;
        }
        if (r8[ch] & 0x08) {
            pc = 0x1882B;
            break;
        }
        memory16set(ds*16+0x7E06, 0x0000);
    case 0x1882B:
        if (memory16get(ds*16+0x7E00) != 0x0001) {
            pc = 0x1883E;
            break;
        }
        memory16set(ds*16+0xB26, 0x000c);
        yield* sub_18C83();
        pc = 0x18975;
        break;
    case 0x1883E:
        if (memory16get(ds*16+0x7E06) != 0x0001) {
            pc = 0x18865;
            break;
        }
        memory16set(ds*16+0xB26, 0x001a);
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[ax] = memory16get(ds*16+0xB20);
        r16[ax] = r16[ax] ^ r16[bx];
        r16[ax] &= 0x0004;
        if (r16[ax] != 0) {
            pc = 0x1885C;
            break;
        }
        pc = 0x18A8F;
        break;
    case 0x1885C:
        memory16set(ds*16+0xB26, 0x001b);
        pc = 0x18A8F;
        break;
    case 0x18865:
        if (memory16get(ds*16+0x7E08) == 0x0001) {
            pc = 0x18875;
            break;
        }
        memory16set(ds*16+0xB26, 0x0008);
        pc = 0x18975;
        break;
    case 0x18875:
        if (!(memory16get(ds*16+0x7ED2) & 0x00ff)) {
            pc = 0x18886;
            break;
        }
        memory16set(ds*16+0xB26, 0x000a);
        pc = 0x18975;
        break;
    case 0x18886:
        if (memory16get(ds*16+0x7E10) != 0x0001) {
            pc = 0x18896;
            break;
        }
        memory16set(ds*16+0xB26, 0x0009);
        pc = 0x18975;
        break;
    case 0x18896:
        if (memory16get(ds*16+0x7E14) != 0x0001) {
            pc = 0x188B6;
            break;
        }
        memory16set(ds*16+0xB26, 0x0000);
        if (memory16get(ds*16+0xB52) != 0x0000) {
            pc = 0x188AD;
            break;
        }
        pc = 0x18975;
        break;
    case 0x188AD:
        memory16set(ds*16+0xB26, 0x000b);
        pc = 0x18975;
        break;
    case 0x188B6:
        if (memory16get(ds*16+0x7E0A) != 0x0001) {
            pc = 0x188D6;
            break;
        }
        memory16set(ds*16+0xB26, 0x0006);
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x188CD;
            break;
        }
        pc = 0x18975;
        break;
    case 0x188CD:
        memory16set(ds*16+0xB26, 0x0000);
        pc = 0x18975;
        break;
    case 0x188D6:
        if (!(memory[ds*16+0x7ECA] & 0xff)) {
            pc = 0x188E6;
            break;
        }
        memory16set(ds*16+0xB26, 0x0000);
        pc = 0x18975;
        break;
    case 0x188E6:
        si = 0x7e2c;
        memory16set(ds*16+0xB26, 0x0006);
        if (memory16get(ds*16+0x7E04) == 0x0001) {
            pc = 0x188FF;
            break;
        }
        si = 0x7e22;
        memory16set(ds*16+0xB26, 0x0000);
    case 0x188FF:
        if (memory16get(ds*16+0xB34) != 0xffff) {
            pc = 0x1890F;
            break;
        }
        memory16set(ds*16+0xB34, 0x0000);
        pc = 0x18975;
        break;
        _STOP_("db 90h");
    case 0x1890F:
        r16[ax] = 0x0001;
        if (memory16get(ds*16+0x7E0C) == 0x0001) {
            pc = 0x18926;
            break;
        }
        r16[ax] = 0x0004;
        if (memory16get(ds*16+0x7E0E) == 0x0001) {
            pc = 0x18926;
            break;
        }
        r16[ax] = 0x0002;
    case 0x18926:
        r16[ax] = r16[ax] + memory16get(ds*16+0xB34);
        if (r16s[ax] < signed16(0x0028)) {
            pc = 0x18932;
            break;
        }
        r16[ax] -= 0x0028;
    case 0x18932:
        memory16set(ds*16+0xB34, r16[ax]);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (memory16get(ds*16+0x7E04) != 0x0001) {
            pc = 0x18950;
            break;
        }
        if (!(r16[ax] & 0x0001)) {
            pc = 0x1896C;
            break;
        }
        push(r16[ax]);
        r16[ax] = 0x0026;
        yield* sub_1AECD();
        r16[ax] = pop();
        pc = 0x1896C;
        break;
    case 0x18950:
        if (r16[ax] == 0x0002) {
            pc = 0x18964;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x18964;
            break;
        }
        if (r16[ax] == 0x0007) {
            pc = 0x18964;
            break;
        }
        if (r16[ax] != 0x0000) {
            pc = 0x1896C;
            break;
        }
    case 0x18964:
        push(r16[ax]);
        r16[ax] = 0x0025;
        yield* sub_1AECD();
        r16[ax] = pop();
    case 0x1896C:
        si += r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+si];
        memory16set(ds*16+0xB26, r16[ax]);
    case 0x18975:
        if (memory16get(ds*16+0xB36) != 0x0000) {
            pc = 0x1897F;
            break;
        }
        pc = 0x18A8F;
        break;
    case 0x1897F:
        memory16set(ds*16+0xB26, memory16get(ds*16+0xB26) + 0x000d);
        pc = 0x18A8F;
        break;
    case 0x18987:
        r16[ax] = memory16get(ds*16+0xB20);
        r8[cl] = r8[cl] ^ r8[cl];
        r16[dx] = r16[dx] ^ r16[dx];
        if (!(memory[ds*16+0xB884] & 0x08)) {
            pc = 0x1899C;
            break;
        }
        r16[dx] = 0xfffe;
        pc = 0x189A7;
        break;
    case 0x1899C:
        if (!(memory[ds*16+0xB884] & 0x04)) {
            pc = 0x189A7;
            break;
        }
        r16[dx] = 0x0002;
    case 0x189A7:
        memory16set(ds*16+0xB24, r16[dx]);
        r16[ax] += r16[dx];
        memory16set(ds*16+0x7961, r16[dx]);
        memory16set(ds*16+0x795F, r16[ax]);
        r16[bx] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0x795D, r16[bx]);
        yield* sub_17DFB();
        pc = 0x18424;
        break;
    case 0x189C2:
        memory16set(ds*16+0x7E10, 0x0001);
        if (memory16get(ds*16+0x7E12) == 0x0000) {
            pc = 0x189DE;
            break;
        }
        if (!(memory16get(ds*16+0x6610) & 0x00ff)) {
            pc = 0x189DE;
            break;
        }
        if (memory16get(ds*16+0xB00) != 0x0001) {
            pc = 0x189F9;
            break;
        }
    case 0x189DE:
        if (r8[ch] & 0x01) {
            pc = 0x189E6;
            break;
        }
        pc = 0x1882B;
        break;
    case 0x189E6:
        if (memory16get(ds*16+0x8BEC) == 0x0002) {
            pc = 0x189F0;
            break;
        }
        pc = 0x1882B;
        break;
    case 0x189F0:
        memory16set(ds*16+0x7E0A, 0x0001);
        pc = 0x186C1;
        break;
    case 0x189F9:
        yield* sub_18A9A();
        pc = 0x1882B;
        break;
    case 0x189FF:
        memory16set(ds*16+0x7E14, 0x0001);
        if (memory16gets(ds*16+0xB38) >= signed16(0x0001)) {
            pc = 0x189DE;
            break;
        }
        r16[ax] = memory16get(ds*16+0x6612);
        r16[ax] |= r16[ax];
        if (r16[ax] != 0) {
            pc = 0x18A16;
            break;
        }
        pc = 0x1882B;
        break;
    case 0x18A16:
        if (memory[ds*16+0x9804] == 0x01) {
            pc = 0x18A21;
            break;
        }
        memory16set(ds*16+0x6612, memory16get(ds*16+0x6612) - 1);
    case 0x18A21:
        memory16set(ds*16+0xB38, 0x0001);
        r16[ax] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0xB3A, r16[ax]);
        memory[ds*16+0xB3F] = 0x00;
        r16[ax] = memory16get(ds*16+0xB20);
        r16[ax] += 0x0005;
        memory16set(ds*16+0xB3C, r16[ax]);
        memory[ds*16+0xB3E] = 0x00;
        memory16set(ds*16+0xB4A, 0x0000);
        memory16set(ds*16+0xB50, 0x0000);
        memory16set(ds*16+0xB52, 0x0000);
        memory16set(ds*16+0xB40, 0x0100);
        memory16set(ds*16+0xB4E, 0x7e36);
        if (!(memory[ds*16+0xB884] & 0x02)) {
            pc = 0x18A75;
            break;
        }
        memory16set(ds*16+0xB36, 0x0001);
        memory16set(ds*16+0xB52, 0xfe00);
        pc = 0x1882B;
        break;
    case 0x18A75:
        if (memory[ds*16+0xB884] & 0x01) {
            pc = 0x18A80;
            break;
        }
        pc = 0x1882B;
        break;
    case 0x18A80:
        memory16set(ds*16+0xB36, 0x0000);
        memory16set(ds*16+0xB52, 0x0200);
        pc = 0x1882B;
        break;
    case 0x18A8F:
        r16[ax] = memory16get(ds*16+0xB20);
        r16[ax] = r16[ax] - memory16get(ds*16+0x7DFE);
        memory16set(ds*16+0x6C43, r16[ax]);
        return;
    } while (1);
}
function* sub_18A9A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x6610);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0)
            return;
        if (memory[ds*16+0x9804] == 0x01) {
            pc = 0x18AB2;
            break;
        }
        memory16set(ds*16+0x6610, memory16get(ds*16+0x6610) - 1);
    case 0x18AB2:
        r16[ax] = 0x000d;
        yield* sub_1AECD();
        memory16set(ds*16+0xB00, 0x0001);
        r16[ax] = memory16get(ds*16+0xB20);
        r16[ax] += 0x0007;
        memory16set(ds*16+0xB04, r16[ax]);
        if (memory16get(ds*16+0xB36) != 0x0000) {
            pc = 0x18AEA;
            break;
        }
        memory16set(ds*16+0xB1A, 0x0008);
        r16[ax] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0xB02, r16[ax]);
        memory16set(ds*16+0xB0A, 0x001f);
        memory16set(ds*16+0x7E12, 0x0000);
        return;
    case 0x18AEA:
        memory16set(ds*16+0xB1A, 0xfff8);
        r16[ax] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0xB02, r16[ax]);
        memory16set(ds*16+0xB0A, 0x001e);
        memory16set(ds*16+0x7E12, 0x0000);
        return;
    } while (1);
}
function* loc_18B03() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x7E08, 0x0000);
        memory16set(ds*16+0x7E0A, 0x0000);
        memory16set(ds*16+0x7E0C, 0x0000);
        memory16set(ds*16+0x7E0E, 0x0000);
        memory16set(ds*16+0x7E10, 0x0000);
        memory16set(ds*16+0x7E14, 0x0000);
        memory16set(ds*16+0x7E06, 0x0000);
        r16[dx] = memory16get(ds*16+0xB24);
        r16[dx] += 0x0040;
        if (r16s[dx] <= signed16(0x0400)) {
            pc = 0x18B40;
            break;
        }
        r16[dx] = 0x0400;
    case 0x18B40:
        if (!(memory[ds*16+0xB884] & 0x08)) {
            pc = 0x18B5E;
            break;
        }
        r16[dx] += 0xff40;
        if (r16s[dx] >= signed16(0xfc00)) {
            pc = 0x18B79;
            break;
        }
        r16[dx] = 0xfc00;
        pc = 0x18B79;
        break;
    case 0x18B5E:
        if (!(memory[ds*16+0xB884] & 0x04)) {
            pc = 0x18B79;
            break;
        }
        r16[dx] += 0x0080;
        if (r16s[dx] <= signed16(0x0400)) {
            pc = 0x18B79;
            break;
        }
        r16[dx] = 0x0400;
    case 0x18B79:
        memory16set(ds*16+0xB24, r16[dx]);
        memory16set(ds*16+0x7961, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x18B8D;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x18B8F;
        break;
        _STOP_("db 90h");
    case 0x18B8D:
        r8[ch] = 0xff;
    case 0x18B8F:
        r16[ax] = memory16get(ds*16+0xB20);
        r8[cl] = memory[ds*16+0xB22];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        memory16set(ds*16+0x795F, r16[ax]);
        r16[dx] = memory16get(ds*16+0xB1E);
        memory16set(ds*16+0x795D, r16[dx]);
        memory[ds*16+0x796B] = 0x01;
        yield* sub_17DFB();
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x20)) {
            pc = 0x18BBE;
            break;
        }
    {yield* sub_168A8(); return; };
    case 0x18BBE:
        if (r8[ch] & 0x04) {
            pc = 0x18BEB;
            break;
        }
        if (!(r8[ch] & 0x02)) {
            pc = 0x18C00;
            break;
        }
        bp = memory16get(cs*16+0xB24);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (!flags.sign) {
            pc = 0x18BEB;
            break;
        }
        r16[ax] |= 0x0007;
        r16[ax] += 1;
        r16[dx] = r16[dx] ^ r16[dx];
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+0xB24, 0x0000);
        pc = 0x18C00;
        break;
        _STOP_("db 90h");
    case 0x18BEB:
        r16[ax] += 0x000c;
        r16[ax] |= 0x0007;
        r16[ax] -= 0x0014;
        r8[cl] = r8[cl] ^ r8[cl];
        r16[dx] = r16[dx] ^ r16[dx];
        r8[cl] = r8[cl] ^ r8[cl];
        memory16set(ds*16+0xB24, 0x0000);
    case 0x18C00:
        memory16set(ds*16+0xB20, r16[ax]);
        bp = 0x0000;
        if (!(memory[ds*16+0xB884] & 0x02)) {
            pc = 0x18C1D;
            break;
        }
        bp = 0xfffc;
        memory16set(ds*16+0xB36, 0x0001);
        pc = 0x18C31;
        break;
        _STOP_("db 90h");
    case 0x18C1D:
        if (!(memory[ds*16+0xB884] & 0x01)) {
            pc = 0x18C31;
            break;
        }
        bp = 0x0004;
        memory16set(ds*16+0xB36, 0x0000);
    case 0x18C31:
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[bx] += bp;
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (bp == 0) {
            pc = 0x18C69;
            break;
        }
        if (!flags.sign) {
            pc = 0x18C57;
            break;
        }
        if (r16s[bx] >= signed16(0x0000)) {
            pc = 0x18C69;
            break;
        }
        r16[bx] = 0x0000;
        memory[ds*16+0x90C2] = 0x01;
        pc = 0x18C69;
        break;
        _STOP_("db 90h");
    case 0x18C57:
        if (r16s[bx] < signed16(0x00e8)) {
            pc = 0x18C69;
            break;
        }
        r16[bx] = 0x00e8;
        memory[ds*16+0x90C2] = 0x02;
    case 0x18C69:
        r16[ax] = memory16get(ds*16+0xB20);
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0x7961, 0xffff);
        memory[ds*16+0x796B] = 0x01;
        memory16set(ds*16+0x795D, r16[bx]);
        r16[dx] = bp;
        _STOP_("goto loc_187DB");
        return;
    } while (1);
}
function* sub_18C83() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0xB884] & 0x10) {
            pc = 0x18C95;
            break;
        }
        memory16set(ds*16+0x7E12, 0x0001);
        return;
    case 0x18C95:
        memory16set(ds*16+0x7E10, 0x0001);
        if (memory16get(ds*16+0x7E12) == 0x0000)
            return;
        if (!(memory16get(ds*16+0x6610) & 0x00ff))
            return;
        if (memory16get(ds*16+0xB00) == 0x0001)
            return;
    {yield* sub_18A9A(); return; };
        return;
    } while (1);
}
function* sub_18CBE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0xB00) == 0x0001) {
            pc = 0x18CC9;
            break;
        }
        return;
    case 0x18CC9:
        r16[dx] = 0x0004;
        r16[ax] = memory16get(ds*16+0xB1A);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x18CD9;
            break;
        }
        r16[dx] = 0x0014;
    case 0x18CD9:
        r16[ax] = r16[ax] + memory16get(ds*16+0xB02);
        r16[dx] += r16[ax];
        if (r16s[dx] < signed16(0x0003)) {
            pc = 0x18D21;
            break;
        }
        if (r16s[dx] > signed16(0x00fc)) {
            pc = 0x18D21;
            break;
        }
        memory16set(ds*16+0x795D, r16[dx]);
        r16[cx] = memory16get(ds*16+0xB04);
        memory16set(ds*16+0x795F, r16[cx]);
        memory16set(ds*16+0x795F, memory16get(ds*16+0x795F) + 0x0004);
        yield* sub_18014();
        push(r16[ax]);
        yield* sub_181C6();
        r16[ax] = pop();
        r8[ch] = memory[ds*16+0x7963];
        if (r8[ch] & 0x02) {
            pc = 0x18D21;
            break;
        }
        if (r8[ch] & 0x40) {
            pc = 0x18D21;
            break;
        }
        memory16set(ds*16+0xB02, r16[ax]);
        return;
    case 0x18D21:
        memory16set(ds*16+0xB00, 0x0000);
        return;
    } while (1);
}
function* sub_18D28() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x7E1E, 0x0000);
        if (memory16gets(ds*16+0xB38) >= signed16(0x0001)) {
            pc = 0x18D39;
            break;
        }
        return;
    case 0x18D39:
        if (memory16gets(ds*16+0xB38) <= signed16(0x0001)) {
            pc = 0x18D3E;
            break;
        }
        pc = 0x18F57;
        break;
    case 0x18D3E:
        si = 0x0b38;
        yield* sub_1718E();
        if (!flags.carry) {
            pc = 0x18D49;
            break;
        }
        pc = 0x18F3A;
        break;
    case 0x18D49:
        r16[dx] = memory16get(ds*16+0xB40);
        r16[dx] += 0x0080;
        if (r16s[dx] <= signed16(0x0800)) {
            pc = 0x18D5A;
            break;
        }
        r16[dx] = 0x0800;
    case 0x18D5A:
        memory16set(ds*16+0xB40, r16[dx]);
        memory16set(ds*16+0x7961, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x18D6B;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x18D6D;
        break;
        _STOP_("db 90h");
    case 0x18D6B:
        r8[ch] = 0xff;
    case 0x18D6D:
        r16[ax] = memory16get(ds*16+0xB3C);
        r8[cl] = memory[ds*16+0xB3E];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        r16[dx] = r16[ax];
        if (r16s[dx] <= signed16(0x0171)) {
            pc = 0x18D85;
            break;
        }
        pc = 0x18F91;
        break;
    case 0x18D85:
        if (r16s[dx] >= signed16(0x0000)) {
            pc = 0x18D8D;
            break;
        }
        pc = 0x18F91;
        break;
    case 0x18D8D:
        memory16set(ds*16+0x795F, r16[dx]);
        r16[ax] = memory16get(ds*16+0xB3A);
        memory16set(ds*16+0x795D, r16[ax]);
        memory[ds*16+0x796B] = 0x01;
        yield* sub_1802D();
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x40)) {
            pc = 0x18DEC;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
        r16[ax] = memory16get(ds*16+0x7964);
        r8[cl] = r8[cl] ^ r8[cl];
        r16[ax] -= 0x0010;
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0xB3C, r16[ax]);
        memory[ds*16+0xB3E] = 0x00;
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x7966);
        memory16set(ds*16+0x7E1E, r16[ax]);
        r16[ax] = pop();
        memory[ds*16+0x796B] = 0x00;
        yield* sub_1802D();
        r8[ch] = memory[ds*16+0x7963];
        if (r8[ch] & 0x20) {
            pc = 0x18DE4;
            break;
        }
        if (r8[ch] & 0x06) {
            pc = 0x18E08;
            break;
        }
        memory16set(ds*16+0xB40, 0x0100);
        pc = 0x18E5A;
        break;
    case 0x18DE4:
        if (!(r8[ch] & 0x20)) {
            pc = 0x18DEC;
            break;
        }
        pc = 0x18F3A;
        break;
    case 0x18DEC:
        if (r8[ch] & 0x04) {
            pc = 0x18E11;
            break;
        }
        if (r8[ch] & 0x02) {
            pc = 0x18E01;
            break;
        }
        memory16set(ds*16+0xB3C, r16[dx]);
        memory[ds*16+0xB3E] = r8[cl];
        pc = 0x18E5A;
        break;
        _STOP_("db 90h");
    case 0x18E01:
        r16[ax] = memory16get(ds*16+0xB40);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x18E11;
            break;
        }
    case 0x18E08:
        r16[dx] |= 0x0007;
        r16[dx] += 1;
        r8[cl] = r8[cl] ^ r8[cl];
        pc = 0x18E18;
        break;
        _STOP_("db 90h");
    case 0x18E11:
        r16[dx] -= 1;
        r16[dx] &= 0x0ff8;
        r8[cl] = r8[cl] ^ r8[cl];
    case 0x18E18:
        memory16set(ds*16+0xB3C, r16[dx]);
        memory[ds*16+0xB3E] = r8[cl];
        if (!(r8[ch] & 0x20)) {
            pc = 0x18E28;
            break;
        }
        pc = 0x18F3A;
        break;
    case 0x18E28:
        if (!(r8[ch] & 0x01)) {
            pc = 0x18E54;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0003) {
            pc = 0x18E47;
            break;
        }
        r16[ax] = memory16get(ds*16+0xB40);
        if (r16s[ax] < signed16(0x0200)) {
            pc = 0x18E54;
            break;
        }
        r16[ax] = -r16[ax];
        r16[ax] += 0x0060;
        memory16set(ds*16+0xB40, r16[ax]);
        pc = 0x18E5A;
        break;
        _STOP_("db 90h");
    case 0x18E47:
        if (memory16get(ds*16+0x8BEC) != 0x0005) {
            pc = 0x18E54;
            break;
        }
        r16[ax] = 0xf781;
        pc = 0x18E57;
        break;
    case 0x18E54:
        r16[ax] = 0x0100;
    case 0x18E57:
        memory16set(ds*16+0xB40, r16[ax]);
    case 0x18E5A:
        r16[dx] = memory16get(ds*16+0xB52);
        r16[bx] = 0x0008;
        if (!(r8[ch] & 0x01)) {
            pc = 0x18E7E;
            break;
        }
        if (memory16get(ds*16+0x8BEC) == 0x0001) {
            pc = 0x18E92;
            break;
        }
        if (memory16get(ds*16+0x8BEC) == 0x0002) {
            pc = 0x18EAD;
            break;
        }
        if (memory16get(ds*16+0x8BEC) != 0x0004) {
            pc = 0x18E7E;
            break;
        }
        r16[bx] = 0x0010;
    case 0x18E7E:
        bp = memory16get(cs*16+0xB52);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (flags.sign) {
            pc = 0x18E8E;
            break;
        }
        r16[dx] -= r16[bx];
        if (r16s[dx] >= 0) {
            pc = 0x18E94;
            break;
        }
        pc = 0x18E92;
        break;
    case 0x18E8E:
        flags.sign = signed16(r16[dx] + r16[bx]) < 0;
        r16[dx] += r16[bx];
        if (flags.sign) {
            pc = 0x18E94;
            break;
        }
    case 0x18E92:
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x18E94:
        memory16set(ds*16+0xB52, r16[dx]);
        r16[ax] = memory16get(ds*16+0x7E1E);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[dx] += r16[ax];
    case 0x18EAD:
        r16[bx] = memory16get(ds*16+0xB3A);
        r8[cl] = memory[ds*16+0xB3F];
        r16[ax] = memory16get(ds*16+0xB3C);
        memory16set(ds*16+0x795F, r16[ax]);
        memory16set(ds*16+0x7961, 0xffff);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x18ECA;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x18ECC;
        break;
    case 0x18ECA:
        r8[ch] = 0xff;
    case 0x18ECC:
        r16[bx] = memory16get(ds*16+0xB3A);
        r8[cl] = memory[ds*16+0xB3F];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[bl] + r8[dh] + flags.carry) >= 0x100;
        r8[bl] = r8[bl] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[bh] = r8[bh] + r8[ch] + flags.carry;
        if (r16s[bx] < signed16(0x00e8)) {
            pc = 0x18EEE;
            break;
        }
        r8[cl] = r8[cl] ^ r8[cl];
        r16[bx] = 0x00e8;
        memory16set(ds*16+0xB52, 0x0000);
        pc = 0x18EFD;
        break;
    case 0x18EEE:
        if (r16s[bx] >= signed16(0x0000)) {
            pc = 0x18EFD;
            break;
        }
        r8[cl] = r8[cl] ^ r8[cl];
        r16[bx] = r16[bx] ^ r16[bx];
        memory16set(ds*16+0xB52, 0x0000);
    case 0x18EFD:
        memory16set(ds*16+0x795D, r16[bx]);
        memory[ds*16+0x796B] = 0x01;
        yield* sub_1802D();
        r8[ch] = memory[ds*16+0x7963];
        if (!(r8[ch] & 0x02)) {
            pc = 0x18F2C;
            break;
        }
        r8[cl] = r8[cl] ^ r8[cl];
        bp = memory16get(ds*16+0xB52);
        bp = bp + memory16get(ds*16+0x7E1E);
        flags.sign = !!(bp & 0x8000);
        bp |= bp;
        if (!flags.sign) {
            pc = 0x18F27;
            break;
        }
        r16[bx] |= 0x0007;
        r16[bx] += 1;
        pc = 0x18F2C;
        break;
        _STOP_("db 90h");
    case 0x18F27:
        r16[bx] -= 1;
        r16[bx] &= 0x00f8;
    case 0x18F2C:
        memory16set(ds*16+0xB3A, r16[bx]);
        memory[ds*16+0xB3F] = r8[cl];
        if (r8[ch] & 0x20) {
            pc = 0x18F3A;
            break;
        }
        return;
    case 0x18F3A:
        memory16set(ds*16+0xB38, 0x0002);
        memory16set(ds*16+0xB50, 0x0000);
        memory16set(ds*16+0xB4E, 0x7eb2);
        memory16set(ds*16+0xB3C, memory16get(ds*16+0xB3C) - 0x0005);
        memory16set(ds*16+0xB4A, 0x0000);
    case 0x18F57:
        si = 0x0b38;
        memory16set(ds*16+0xB4A, memory16get(ds*16+0xB4A) + 1);
        if (memorys[ds*16+0xB4A] <= signed8(0x01)) {
            pc = 0x18F8C;
            break;
        }
        if (memorys[ds*16+0xB4A] > signed8(0x04)) {
            pc = 0x18F8C;
            break;
        }
        r16[dx] = memory16get(ds*16+0xB3A);
        r16[dx] -= 0x0004;
        if (r16s[dx] >= 0) {
            pc = 0x18F77;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x18F77:
        xchg8(dl, dh);
        r16[bx] = memory16get(ds*16+0xB3C);
        r16[bx] -= 0x0004;
        r8[dl] = 0x20;
        r8[ah] = 0x1c;
        yield* sub_16407();
        if (!flags.carry) {
            pc = 0x18F8C;
            break;
        }
        yield* sub_168A8();
    case 0x18F8C:
        yield* sub_1718E();
        if (!flags.carry)
            return;
    case 0x18F91:
        memory16set(ds*16+0xB38, 0x0000);
        return;
    } while (1);
}
function* loc_18F9A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds*16+0xB24);
        r16[dx] += 0x0080;
        memory16set(ds*16+0xB24, r16[dx]);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x18FAF;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
        pc = 0x18FB1;
        break;
        _STOP_("db 90h");
    case 0x18FAF:
        r8[ch] = 0xff;
    case 0x18FB1:
        r16[ax] = memory16get(ds*16+0xB20);
        r8[cl] = memory[ds*16+0xB22];
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        flags.carry2 = (r8[al] + r8[dh] + flags.carry) >= 0x100;
        r8[al] = r8[al] + r8[dh] + flags.carry;flags.carry = flags.carry2;
        r8[ah] = r8[ah] + r8[ch] + flags.carry;
        if (r16s[ax] <= signed16(0x0110)) {
            pc = 0x18FCA;
            break;
        }
        memory16set(ds*16+0x7E18, 0x0001);
        return;
    case 0x18FCA:
        memory16set(ds*16+0xB20, r16[ax]);
        memory[ds*16+0xB22] = r8[cl];
        r8[al] = memory[ds*16+0x8B98];
        r8[al] = (~r8[al]);
        memory[ds*16+0x8B98] = r8[al];
        r8[al] &= 0x01;
        r16[ax] += 0x001c;
        memory16set(ds*16+0xB26, r16[ax]);
        r16[ax] = memory16get(ds*16+0x7E1C);
        r16[ax] = r16[ax] + memory16get(ds*16+0xB1E);
        memory16set(ds*16+0xB1E, r16[ax]);
        return;
        _STOP_("word_18FEC dw 1");
        _STOP_("word_18FEE dw 0");
        _STOP_("word_18FF0 dw 0");
        _STOP_("db 3 dup(0), 1, 74h, 33h, 1Bh dup(0), 90h,...");
        return;
    } while (1);
}
function* sub_19214() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x8BF6);
        di = 0x563c;
        r16[cx] = 0x000a;
        r16[dx] = memory16get(ds*16+0x8BF0);
        r16[dx] &= 0xfff8;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[ax] = r16[dx];
        r16[dx] &= 0xfffc;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[bx] += r16[dx];
        memory16set(ds*16+0x8BF8, r16[bx]);
        r16[ax] &= 0x0003;
        memory16set(ds*16+0x8BFA, r16[ax]);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x19257;
            break;
        }
        r16[dx] = 0x0004;
        r16[dx] -= r16[ax];
        push(r16[cx]);
        yield* sub_1926D();
        r16[cx] = pop();
        pc = 0x1925C;
        break;
        _STOP_("db 90h");
    case 0x19257:
        push(r16[cx]);
        yield* sub_192AE();
        r16[cx] = pop();
    case 0x1925C:
        if (--r16[cx]) {
            pc = 0x19257;
            break;
        }
        r16[dx] = memory16get(ds*16+0x8BFA);
        r16[dx] |= r16[dx];
        if (r16[dx] == 0)
            return;
        r16[ax] = 0x0000;
        yield* sub_1926D();
        return;
    } while (1);
}
function* sub_1926D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(r16[dx]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[cx] = 0x0008;
    case 0x19276:
        push(r16[cx]);
        push(r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r16[ax] <<= 1;
        si = 0x8c14;
        si += r16[ax];
        r16[ax] = pop();
        si = memory16get(ds*16+si);
        si += r16[ax];
        bp = di;
        push(r16[dx]);
    case 0x1928C:
        r16[cx] = 0x0004;
        rep_movsb_data_data_forward();
        di += 0x001c;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x1928C;
            break;
        }
        r16[dx] = pop();
        di = bp;
        di += 0x0004;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x19276;
            break;
        }
        r16[dx] = pop();
        di = pop();
        r16[dx] -= 1;
        r16[dx] &= 0x0003;
        r16[dx] += 1;
        r8[cl] = 0x05;
        r16[dx] <<= r8[cl];
        di += r16[dx];
        return;
    } while (1);
}
function* sub_192AE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0008;
    case 0x192B1:
        bp = r16[cx];
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r16[ax] <<= 1;
        si = 0x8c14;
        si += r16[ax];
        si = memory16get(ds*16+si);
        r16[dx] = 0x0004;
    case 0x192C4:
        r16[cx] = 0x0004;
        rep_movsb_data_data_forward();
        di += 0x001c;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x192C4;
            break;
        }
        di += signed16(0xff84);
        r16[cx] = bp;
        if (--r16[cx]) {
            pc = 0x192B1;
            break;
        }
        di += 0x0060;
        return;
    } while (1);
}
function* sub_192DA() {
    di = 0x563c;
    si = 0x565c;
    r16[cx] = 0x0270;
    rep_movsw_data_data_forward();
    r16[ax] = memory16get(ds*16+0x8BFA);
    r16[dx] = 0x0001;
    r16[bx] = memory16get(ds*16+0x8BF8);
    r16[bx] += 0x0050;
    di = 0x5b1c;
    yield* sub_1926D();
    memory16set(ds*16+0x8BFA, memory16get(ds*16+0x8BFA) + 0x0001);
    memory16set(ds*16+0x8BFA, memory16get(ds*16+0x8BFA) & 0x0003);
    if (memory16get(ds*16+0x8BFA) != 0)
        return;
    memory16set(ds*16+0x8BF8, memory16get(ds*16+0x8BF8) + 0x0008);
    return;
}
function* sub_1930A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x5b1a;
        di = 0x5b3a;
        flags.direction = true;
        r16[cx] = 0x0270;
        rep_movsw_data_data_backward();
        flags.direction = false;
        r16[bx] = memory16get(ds*16+0x8BF8);
        memory16set(ds*16+0x8BFA, memory16get(ds*16+0x8BFA) - 1);
        memory16set(ds*16+0x8BFA, memory16get(ds*16+0x8BFA) & 0x0003);
        if (memory16get(ds*16+0x8BFA) != 0x0003) {
            pc = 0x19332;
            break;
        }
        r16[bx] -= 0x0008;
        memory16set(ds*16+0x8BF8, r16[bx]);
    case 0x19332:
        di = 0x563c;
        r16[ax] = memory16get(ds*16+0x8BFA);
        r16[dx] = 0x0001;
        yield* sub_1926D();
        return;
    } while (1);
}
function* sub_1933F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x3c74;
        di = 0x8c14;
        r16[dx] = 0x0010;
        r16[cx] = 0x0100;
    case 0x1934B:
        stosw_data_forward();
        r16[ax] += r16[dx];
        if (--r16[cx]) {
            pc = 0x1934B;
            break;
        }
        return;
    } while (1);
}
function* sub_19351() {
    memory16set(ds*16+0xB00, 0x0000);
    memory16set(ds*16+0xB38, 0x0000);
    push(r16[ax]);
    r16[ax] = memory16get(ds*16+0xB1E);
    memory16set(ds*16+0x8C00, r16[ax]);
    r16[ax] = memory16get(ds*16+0xB20);
    memory16set(ds*16+0x8C02, r16[ax]);
    r16[ax] = memory16get(ds*16+0xB24);
    memory16set(ds*16+0x8C08, r16[ax]);
    r8[al] = memory[ds*16+0xB22];
    memory[ds*16+0x8C12] = r8[al];
    r16[ax] = memory16get(ds*16+0x7E02);
    memory16set(ds*16+0x8C0A, r16[ax]);
    r16[ax] = memory16get(ds*16+0x7E04);
    memory16set(ds*16+0x8C0C, r16[ax]);
    r16[ax] = memory16get(ds*16+0xB36);
    memory16set(ds*16+0x8C0E, r16[ax]);
    r16[ax] = memory16get(ds*16+0x7E00);
    memory16set(ds*16+0x8C10, r16[ax]);
    r16[ax] = pop();
    memory16set(ds*16+0x8C04, r16[ax]);
    memory16set(ds*16+0x8C06, r16[dx]);
    si = 0x4c74;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    si += r16[ax];
    r16[ax] = r16[ax] ^ r16[ax];
    r16[ax] = r16[ax] + memory16get(ds*16+si);
    si += 1;
    si += 1;
    xchg8(al, ah);
    r16[ax] += 0x3374;
    memory16set(ds*16+0x8BF6, r16[ax]);
    memory16set(ds*16+0x8BF2, 0x0000);
    r16[ax] = memory16get(ds*16+si);
    si += 1;
    si += 1;
    xchg8(al, ah);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    memory16set(ds*16+0x8BF4, r16[ax]);
    r16[ax] = memory16get(ds*16+si);
    si += 1;
    si += 1;
    xchg8(al, ah);
    r16[ax] += 0x4c74;
    memory16set(ds*16+0x8BFE, r16[ax]);
    r16[ax] = memory16get(ds*16+si);
    si += 1;
    si += 1;
    xchg8(al, ah);
    r16[ax] += 0x4c74;
    memory16set(ds*16+0x8BFC, r16[ax]);
    memory16set(ds*16+0x8BF0, r16[dx]);
    yield* sub_19577();
}
function* sub_19420() {
    si = 0x8fe4;
    r16[ax] = memory16get(ds*16+0x8BEC);
    r16[ax] -= 1;
    r16[ax] <<= 1;
    si += r16[ax];
    si = memory16get(ds*16+si);
    r16[ax] = memory16get(ds*16+si);
    memory16set(ds*16+0xB1E, r16[ax]);
    r16[ax] = memory16get(ds*16+si + 2);
    memory16set(ds*16+0xB20, r16[ax]);
    r16[ax] = memory16get(ds*16+si + 4);
    r16[dx] = memory16get(ds*16+si + 6);
    r16[cx] = memory16get(ds*16+si + 8);
    memory16set(ds*16+0xB36, r16[cx]);
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_19577();
    yield* sub_17047();
    yield* sub_15FE4();
    memory[ds*16+0x5B3E] = 0x01;
    yield* sub_15F40();
    memory[ds*16+0x5B3E] = 0x00;
}
function* sub_19462() {
    r16[ax] = memory16get(ds*16+0x8C00);
    memory16set(ds*16+0xB1E, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C02);
    memory16set(ds*16+0xB20, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C08);
    memory16set(ds*16+0xB24, r16[ax]);
    r8[al] = memory[ds*16+0x8C12];
    memory[ds*16+0xB22] = r8[al];
    r16[ax] = memory16get(ds*16+0x8C0A);
    memory16set(ds*16+0x7E02, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C0C);
    memory16set(ds*16+0x7E04, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C0E);
    memory16set(ds*16+0xB36, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C10);
    memory16set(ds*16+0x7E00, r16[ax]);
    r16[ax] = memory16get(ds*16+0x8C04);
    r16[dx] = memory16get(ds*16+0x8C06);
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_19577();
    yield* sub_17047();
    memory16set(ds*16+0x6612, 0x0006);
    memory16set(ds*16+0x6610, 0x0006);
    yield* sub_15FE4();
    memory[ds*16+0x5B3E] = 0x01;
    yield* sub_15F40();
    memory[ds*16+0x5B3E] = 0x00;
}
function* sub_194C4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x90C2];
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x194CC;
            break;
        }
        return;
    case 0x194CC:
        si = memory16get(ds*16+0x8BFE);
    case 0x194D0:
        r8[al] = memory[ds*16+si];
        r8[al] |= r8[al];
        if (r8[al] == 0)
            return;
        r8[al] &= 0x03;
        if (r8[al] != memory[ds*16+0x90C2]) {
            pc = 0x194F6;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8BF0);
        r16[ax] &= 0xfff8;
        r16[ax] = r16[ax] + memory16get(ds*16+0xB20);
        r16[ax] += 0x0014;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r8[al] == memory[ds*16+si + 1]) {
            pc = 0x194FB;
            break;
        }
    case 0x194F6:
        si += 0x0004;
        pc = 0x194D0;
        break;
    case 0x194FB:
        r8[al] = memory[ds*16+si];
        r8[ah] = r8[al];
        r8[ah] &= 0x90;
        if (r8[ah] != 0x90) {
            pc = 0x1950A;
            break;
        }
    {yield* loc_19650(); return; };
    case 0x1950A:
        if (!(r8[al] & 0x40)) {
            pc = 0x19514;
            break;
        }
        memory16set(ds*16+0x762D, 0x0001);
    case 0x19514:
        if (!(r8[al] & 0x20)) {
            pc = 0x19521;
            break;
        }
        memory16set(ds*16+0x7E00, 0x0001);
        pc = 0x19527;
        break;
        _STOP_("db 90h");
    case 0x19521:
        memory16set(ds*16+0x7E00, 0x0000);
    case 0x19527:
        r16[cx] = r16[cx] ^ r16[cx];
        r8[al] = memory[ds*16+si + 2];
        r16[dx] = r16[dx] ^ r16[dx];
        r8[dl] = memory[ds*16+si + 3];
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[cx] = memory16get(ds*16+0xB20);
        r16[cx] += 0x0014;
        r16[cx] &= 0xfff8;
        r16[dx] -= r16[cx];
        r16[cx] = memory16get(ds*16+0x8BF0);
        r16[cx] &= 0x0007;
        r16[dx] &= 0xfff8;
        r16[dx] |= r16[cx];
        yield* sub_19553();
        return;
    } while (1);
}
function* sub_19553() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0xB1E);
        r16[bx] |= r16[bx];
        if (r16[bx] != 0) {
            pc = 0x19568;
            break;
        }
        memory16set(ds*16+0xB1E, 0x00e8);
        yield* indirectCall(ds, memory16get(ds*16+0x20));
        return;
    case 0x19568:
        memory16set(ds*16+0xB1E, 0x0000);
        yield* indirectCall(ds, memory16get(ds*16+0x22));
        return;
    } while (1);
}
function* sub_19577() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9173, 0x0000);
        si = 0x54fa;
        memory16set(ds*16+0x9175, si);
    case 0x19584:
        r8[al] = memory[ds*16+si];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (flags.sign)
            return;
        memory[ds*16+si] = 0x00;
        si += 0x0008;
        pc = 0x19584;
        break;
        return;
    } while (1);
}
function* sub_19593() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        push(di);
        push(r16[ax]);
        push(cs);
        ds = pop();
        if (memory16gets(ds*16+0x9173) < signed16(0x0028)) {
            pc = 0x195A5;
            break;
        }
        r16[ax] = pop();
        di = pop();
        es = pop();
        ds = pop();
        return;
    case 0x195A5:
        r16[dx] = r16[dx] ^ r16[dx];
        r8[dl] = r8[al];
        r16[dx] -= 0x00f8;
        r16[dx] += r16[dx];
        r16[dx] += r16[dx];
        r16[ax] = r16[ax] ^ r16[ax];
        yield* sub_19B40();
        r8[al] = memory[ds*16+0x973F];
        _cbw();
        r8[al] &= 0x03;
        r16[dx] += r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        si = 0x54fa;
    case 0x195C3:
        r8[al] = memory[ds*16+si];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (flags.sign) {
            pc = 0x195E0;
            break;
        }
        if (r8[al] != 0) {
            pc = 0x195E5;
            break;
        }
        memory[ds*16+si] = 0x01;
        si += 1;
        memory[ds*16+si] = r8[dl];
        si += 1;
        memory16set(ds*16+si, r16[bx]);
        si += 1;
        si += 1;
        memory16set(ds*16+si, di);
        si += 1;
        si += 1;
        memory16set(ds*16+si, bp);
        memory16set(ds*16+0x9173, memory16get(ds*16+0x9173) + 1);
    case 0x195E0:
        r16[ax] = pop();
        di = pop();
        es = pop();
        ds = pop();
        return;
    case 0x195E5:
        si += 0x0008;
        pc = 0x195C3;
        break;
        return;
    } while (1);
}
function* sub_195EA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9173) != 0x0000) {
            pc = 0x195F2;
            break;
        }
        return;
    case 0x195F2:
        si = 0x54fa;
    case 0x195F5:
        r8[al] = memory[ds*16+si];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x19617;
            break;
        }
        if (flags.sign)
            return;
        r16[ax] = memory16get(ds*16+si + 2);
        r16[ax] += 0x0020;
        if (r16s[ax] < signed16(0x5a7c)) {
            pc = 0x19614;
            break;
        }
        memory[ds*16+si] = 0x00;
        memory16set(ds*16+0x9173, memory16get(ds*16+0x9173) - 1);
        si += 0x0008;
        pc = 0x195F5;
        break;
    case 0x19614:
        memory16set(ds*16+si + 2, r16[ax]);
    case 0x19617:
        si += 0x0008;
        pc = 0x195F5;
        break;
        return;
    } while (1);
}
function* sub_1961D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9173) != 0x0000) {
            pc = 0x19625;
            break;
        }
        return;
    case 0x19625:
        si = 0x54fa;
    case 0x19628:
        r8[al] = memory[ds*16+si];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x1964A;
            break;
        }
        if (flags.sign)
            return;
        r16[ax] = memory16get(ds*16+si + 2);
        r16[ax] -= 0x0020;
        if (r16s[ax] >= signed16(0x573c)) {
            pc = 0x19647;
            break;
        }
        memory[ds*16+si] = 0x00;
        memory16set(ds*16+0x9173, memory16get(ds*16+0x9173) - 1);
        si += 0x0008;
        pc = 0x19628;
        break;
    case 0x19647:
        memory16set(ds*16+si + 2, r16[ax]);
    case 0x1964A:
        si += 0x0008;
        pc = 0x19628;
        break;
        return;
    } while (1);
}
function* loc_19650() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* indirectCall(ds, memory16get(ds*16+0x3C));
        r16[ax] = memory16get(ds*16+0x8BEC);
        if (r16[ax] != 0x0004) {
            pc = 0x19687;
            break;
        }
        if (memory16get(ds*16+0x95C4) == 0x0001) {
            pc = 0x19673;
            break;
        }
        if (memory16get(ds*16+0x8BEE) == 0x0001) {
            pc = 0x19673;
            break;
        }
        r16[ax] = 0x0001;
        yield* sub_1A257();
    {yield* loc_19F12(); return; };
    case 0x19673:
        memory16set(ds*16+0x8BEC, memory16get(ds*16+0x8BEC) + 1);
        if (memory16get(ds*16+0x8BEC) != 0x0005) {
            pc = 0x19684;
            break;
        }
        memory16set(ds*16+0x95C4, 0x0001);
    case 0x19684:
        _STOP_("goto loc_1C3B9");
    case 0x19687:
        if (memory16get(ds*16+0x8BEC) != 0x0005) {
            pc = 0x196A7;
            break;
        }
        if (memory16get(ds*16+0x8BEE) != 0x0001) {
            pc = 0x19698;
            break;
        }
        _STOP_("goto loc_19F37");
    case 0x19698:
        memory16set(ds*16+0x95C4, 0x0001);
        r16[ax] = 0x0001;
        yield* sub_1A257();
    {yield* loc_19F12(); return; };
    case 0x196A7:
        memory16set(ds*16+0x8BEC, memory16get(ds*16+0x8BEC) + 1);
        _STOP_("goto loc_1C3B9");
    {yield* loc_19F12(); return; };
        _STOP_("db 4Dh, 65h, 6Dh, 6Fh, 72h, 79h, 20h, 41h,...");
        _STOP_("db 6Fh, 63h, 61h, 74h, 69h, 6Fh, 6Eh, 20h,...");
        _STOP_("db 6Fh, 72h, 3Ah, 20h, 43h, 61h, 2 dup(6Eh...");
        _STOP_("db 20h, 72h, 75h, 6Eh, 20h, 52h, 49h, 43h,...");
        _STOP_("db 0Dh, 24h");
        return;
    } while (1);
}
function* sub_196DD() {
    yield* indirectCall(ds, memory16get(ds*16+0x0));
    yield* sub_1933F();
    yield* indirectCall(ds, memory16get(ds*16+0x10));
    yield* indirectCall(ds, memory16get(ds*16+0x18));
    yield* sub_1ADCB();
    yield* sub_1BC92();
}
function* loc_196F3() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupt = false;
        yield* sub_1AE03();
        yield* sub_1BCB7();
        flags.interrupt = true;
        r8[al] = memory[ds*16+0x6A];
        r8[ah] = r8[ah] ^ r8[ah];
        interrupt(16);
        if (memory16get(ds*16+0xAB2B) == 0x0001) {
            pc = 0x1970F;
            break;
        }
        yield* sub_1ADB0();
        pc = 0x1972D;
        break;
        _STOP_("db 90h");
    case 0x1970F:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = cs;
        es = r16[bx];
        si = 0x0000;
        r16[bx] = 0xb3a7;
        interrupt(101);
        es = pop();
        ds = pop();
        bp = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
    case 0x1972D:
        r8[ah] = 0x4c;
        interrupt(33);
    case 0x19731:
        r8[ah] = 0x09;
        r16[dx] = _seg001;
        ds = r16[dx];
        r16[dx] = 0x92b1;
        interrupt(33);
        r8[ah] = 0x4c;
        interrupt(33);
        _STOP_("db 1, 2, 7, 0Ah, 0Bh, 0Fh, 10h, 2 dup(0), ...");
        _STOP_("db 12h, 1Ch, 1Dh, 0Ah, 0Bh, 1, 27h, 1, 2, ...");
        _STOP_("db 2Dh, 2Eh, 2Fh, 2 dup(0), 2 dup(7), 0FFh...");
        _STOP_("db 0, 3, 11h, 2 dup(0), 13h, 14h, 18h, 19h...");
        _STOP_("db 21h, 28h, 29h, 3, 4, 13h, 14h, 13h, 14h...");
        _STOP_("db 2 dup(8), 0FFh, 5, 6, 9, 0Dh, 0Eh, 5, 6...");
        _STOP_("db 16h, 1Ah, 1Bh, 5, 20h, 0Dh, 22h, 15h, 2...");
        _STOP_("db 16h, 2Bh, 16h, 32h, 16h, 2 dup(0), 2 du...");
        _STOP_("db 0Bh, 0Ah, 12h, 1Ch, 1Dh, 0Ah, 0Bh, 1, 2...");
        _STOP_("db 34h, 2Ch, 2Dh, 2Ch, 0, 17h, 12h, 33h, 3...");
        _STOP_("db 1Ch, 1Dh, 2Eh, 2Fh, 3Ah, 3Bh, 0FFh, 0Ch...");
        _STOP_("db 1Eh, 1Fh, 0Ch, 21h, 3, 4, 18h, 19h, 35h...");
        _STOP_("db 13h, 0, 18h, 19h, 35h, 36h, 8, 0Ch, 14h...");
        _STOP_("db 31h, 3Ch, 3Dh, 0FFh, 0Dh, 0Eh, 0Dh, 16h...");
        _STOP_("db 22h, 5, 6, 1Ah, 1Bh, 37h, 38h, 2Bh, 16h...");
        _STOP_("db 1Bh, 37h, 38h, 9, 0Dh, 16h, 5, 20h, 32h...");
        _STOP_("db 0FFh, 39h, 1Dh, 17h, 12h, 2Ch, 0, 2Ch, ...");
        _STOP_("db 12h, 1, 27h, 2 dup(0), 1, 27h, 17h, 12h...");
        _STOP_("db 27h, 7 dup(0), 0FFh, 18h, 19h, 18h, 19h...");
        _STOP_("db 3 dup(0), 0Ch, 14h, 28h, 29h, 2 dup(0),...");
        _STOP_("db 19h, 24h, 25h, 28h, 29h, 7 dup(0), 0FFh...");
        _STOP_("db 1Bh, 15h, 2Ah, 15h, 2Ah, 2 dup(0), 0Dh,...");
        _STOP_("db 1Ah, 0, 1Ah, 1Bh, 5, 26h, 15h, 2Ah, 7 d...");
        _STOP_("db 2Eh, 2Fh, 1, 27h, 2Ch, 0, 1, 27h, 0Ah, ...");
        _STOP_("db 2 dup(0), 2Ch, 0, 1, 27h, 2Ch, 2Dh, 1, ...");
        _STOP_("db 0FFh, 30h, 31h, 28h, 29h, 13h, 0, 28h, ...");
        _STOP_("db 35h, 36h, 2 dup(0), 13h, 0, 28h, 29h, 4...");
        _STOP_("db 29h, 13h, 8 dup(0), 0FFh, 32h, 16h, 15h...");
        _STOP_("db 15h, 2Ah, 0Dh, 0Eh, 37h, 38h, 2 dup(0),...");
        _STOP_("db 2Ah, 42h, 43h, 15h, 2Ah, 15h, 2Ah, 7 du...");
        _STOP_("db 0, 0Ah, 12h, 17h, 12h, 1, 12h, 7, 1Ch, ...");
        _STOP_("db 12h dup(0), 0FFh, 13h, 0, 0Ch, 14h, 18h...");
        _STOP_("db 8, 1Eh, 1Fh, 0Ch, 21h, 12h dup(0), 0FFh...");
        _STOP_("db 16h, 1Ah, 1Bh, 15h, 16h, 9, 5, 20h, 0Dh...");
        _STOP_("db 3Eh, 3Fh, 3Eh, 3Fh, 0Ch dup(0), 0FFh, 0...");
        _STOP_("db 20h, 48h, 59h, 44h, 45h, 20h, 50h, 41h,...");
        _STOP_("db 20h, 4Ch, 4Fh, 4Eh, 44h, 4Fh, 4Eh, 0FFh...");
        _STOP_("db 54h, 48h, 45h, 20h, 49h, 43h, 45h, 20h,...");
        _STOP_("db 45h, 52h, 4Eh, 53h, 20h, 4Fh, 46h, 20h,...");
        _STOP_("db 5Ah, 49h, 41h, 0FFh, 6, 0Ch, 3, 20h, 54...");
        _STOP_("db 20h, 46h, 4Fh, 52h, 45h, 53h, 54h, 53h,...");
        _STOP_("db 20h, 56h, 45h, 47h, 45h, 54h, 41h, 42h,...");
        _STOP_("db 0FFh, 6, 0Fh, 4, 20h, 54h, 48h, 45h, 20...");
        _STOP_("db 4Fh, 4Dh, 49h, 43h, 20h, 4Dh, 55h, 44h,...");
        _STOP_("db 4Eh, 45h, 53h, 0FFh, 6, 12h, 5, 20h, 54...");
        _STOP_("db 20h, 46h, 41h, 54h, 20h, 47h, 55h, 59h,...");
        _STOP_("db 48h, 45h, 41h, 44h, 51h, 55h, 41h, 52h,...");
        _STOP_("db 53h, 0FFh");
        _STOP_("byte_199AD db 1");
        memory16set(ds*16+r16[bx] + di, memory16get(ds*16+r16[bx] + di) + 1);
        r8[al] = r8[al] + memory[ds*16+bp + di + 0];
        r8[al] += 0x05;
        _STOP_("goto word ptr [bp+si]");
        _STOP_("db 0, 8Eh, 95h, 2 dup(0)");
        _STOP_("byte_199C3 db 0");
        _STOP_("word_199C4 dw 0");
        return;
    } while (1);
}
function* sub_199C8() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x95AD] = 0x01;
        yield* off_10426();
        r16[ax] = 0x0706;
        memory16set(ds*16+0x69F0, r16[ax]);
        memory16set(ds*16+0x69F2, r16[ax]);
        yield* sub_16E39();
        r16[ax] = 0x0008;
        si = 0x9461;
        yield* off_10446();
        r16[ax] = 0x0108;
        si = 0x9481;
        yield* off_10446();
        r16[ax] = 0x0208;
        si = 0x94a1;
        yield* off_10446();
        r16[bx] = 0x95b5;
        yield* sub_19C43();
        push(cs);
        ds = pop();
        if (memory16get(ds*16+0x95C4) != 0x0001) {
            pc = 0x19A10;
            break;
        }
        r16[bx] = 0x95bf;
        yield* sub_19C43();
    case 0x19A10:
        yield* off_1041C();
        r16[ax] = 0x0008;
        si = 0x9461;
        yield* off_10446();
        r16[ax] = 0x0108;
        si = 0x9481;
        yield* off_10446();
        r16[ax] = 0x0208;
        si = 0x94a1;
        yield* off_10446();
        r16[bx] = 0x95b5;
        yield* sub_19C43();
        if (memory16get(ds*16+0x95C4) != 0x0001) {
            pc = 0x19A45;
            break;
        }
        r16[bx] = 0x95bf;
        yield* sub_19C43();
    case 0x19A45:
        memory[ds*16+0x97DA] = 0x01;
    case 0x19A4B:
        yield* _sync();
        yield* sub_19BDC();
        if (!(r8[al] & 0x10)) {
            pc = 0x19A55;
            break;
        }
        pc = 0x19AE0;
        break;
    case 0x19A55:
        if (r8[al] == memory[ds*16+0x95C3]) {
            pc = 0x19A4B;
            break;
        }
        memory[ds*16+0x95C3] = r8[al];
        if (!(r8[al] & 0x08)) {
            pc = 0x19A9E;
            break;
        }
        r16[dx] = memory16get(ds*16+0x69F0);
        r8[dh] -= 1;
        r8[dh] -= 1;
        r8[dh] -= 1;
        if (memory16get(ds*16+0x95C4) == 0x0001) {
            pc = 0x19A84;
            break;
        }
        if (r8[dh] != 0x04) {
            pc = 0x19A95;
            break;
        }
        r8[dh] = 0x10;
        memory[ds*16+0x95AD] = 0x04;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19A84:
        if (r8[dh] != 0x04) {
            pc = 0x19A95;
            break;
        }
        r8[dh] = 0x13;
        memory[ds*16+0x95AD] = 0x05;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19A95:
        memory[ds*16+0x95AD] -= 1;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19A9E:
        if (!(r8[al] & 0x04)) {
            pc = 0x19A4B;
            break;
        }
        r16[dx] = memory16get(ds*16+0x69F0);
        r8[dh] += 1;
        r8[dh] += 1;
        r8[dh] += 1;
        if (memory16get(ds*16+0x95C4) == 0x0001) {
            pc = 0x19AC4;
            break;
        }
        if (r8[dh] != 0x13) {
            pc = 0x19AD6;
            break;
        }
        r8[dh] = 0x07;
        memory[ds*16+0x95AD] = 0x01;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19AC4:
        if (r8[dh] != 0x16) {
            pc = 0x19AD6;
            break;
        }
        r8[dh] = 0x07;
        memory[ds*16+0x95AD] = 0x01;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19AD6:
        memory[ds*16+0x95AD] += 1;
        yield* sub_16E66();
        pc = 0x19A4B;
        break;
    case 0x19AE0:
        r8[al] = memory[ds*16+0x95AD];
        _cbw();
        r16[ax] -= 1;
        si = 0x95af;
        si += r16[ax];
        r8[al] = memory[ds*16+si];
        _cbw();
        memory16set(ds*16+0x8BEC, r16[ax]);
        memory16set(ds*16+0x8BEE, r16[ax]);
        return;
    } while (1);
}
function* sub_19AF6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x96F4);
    case 0x19AFB:
        push(r16[ax]);
        push(es);
        r16[dx] = 0x0040;
        es = r16[dx];
        r16[dx] = memoryBiosGet16(es, 0x63);
        es = pop();
        r8[dl] += 0x06;
    case 0x19B0B:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x19B0B;
            break;
        }
    case 0x19B10:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x19B10;
            break;
        }
        r16[ax] = pop();
        r16[ax] -= 1;
        if (r16[ax] != 0) {
            pc = 0x19AFB;
            break;
        }
        r16[ax] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_19B1C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        push(r16[ax]);
        push(r16[ax]);
        push(es);
        r16[dx] = 0x0040;
        es = r16[dx];
        r16[dx] = memoryBiosGet16(es, 0x63);
        es = pop();
        r8[dl] += 0x06;
    case 0x19B2E:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x19B2E;
            break;
        }
    case 0x19B33:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x19B33;
            break;
        }
        r16[ax] = pop();
        r16[ax] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_19B40() {
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memory16get(ds*16+0x973C);
    r16[dx] = memory16get(ds*16+0x973E);
    xchg16(ax, dx);
    rol16(dx, 1);
    rol16(dx, 1);
    rol16(dx, 1);
    r16[dx] -= 0x0007;
    r16[dx] = r16[dx] ^ r16[ax];
    memory16set(ds*16+0x973C, r16[ax]);
    memory16set(ds*16+0x973E, r16[dx]);
    r16[dx] = pop();
    r16[ax] = pop();
}
function* sub_19BAC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x11;
        if (memory[ds*16+0x97AB] == 0x01) {
            pc = 0x19BCE;
            break;
        }
        if (memory[ds*16+0xB888] == r8[al]) {
            pc = 0x19BBC;
            break;
        }
        return;
    case 0x19BBC:
        if (memory[ds*16+0xB888] == r8[al]) {
            pc = 0x19BBC;
            break;
        }
    case 0x19BC2:
        if (memory[ds*16+0xB888] != r8[al]) {
            pc = 0x19BC2;
            break;
        }
        memory[ds*16+0x97AB] = 0x01;
        return;
    case 0x19BCE:
        if (r8[al] == memory[ds*16+0xB888])
            return;
        memory[ds*16+0x97AB] = 0x00;
        return;
    } while (1);
}
function* sub_19BDC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1C4CA();
        if (!(r8[al] & 0x10)) {
            pc = 0x19BF0;
            break;
        }
        if (memory[ds*16+0x97DA] == 0x01) {
            pc = 0x19BF5;
            break;
        }
        memory[ds*16+0x97DA] = 0x01;
        return;
    case 0x19BF0:
        memory[ds*16+0x97DA] = 0x00;
    case 0x19BF5:
        r8[al] &= 0xef;
        return;
    } while (1);
}
function* sub_19C05() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pushf();
        push(si);
        push(r16[ax]);
        if (memory[ds*16+0x9804] == 0x01) {
            pc = 0x19C3F;
            break;
        }
        si = memory16get(ds*16+0x97F8);
        r8[al] = memory[ds*16+0xB888];
        if (r8[al] & 0x80) {
            pc = 0x19C39;
            break;
        }
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x19C39;
            break;
        }
        r8[ah] = memory[ds*16+si];
        if (r8[al] != r8[ah]) {
            pc = 0x19C33;
            break;
        }
        si += 1;
        memory16set(ds*16+0x97F8, si);
        if (memory[ds*16+si] != 0xff) {
            pc = 0x19C39;
            break;
        }
        memory[ds*16+0x9804] = 0x01;
    case 0x19C33:
        memory16set(ds*16+0x97F8, 0x97fa);
    case 0x19C39:
        memory[ds*16+0xB888] = 0x00;
    case 0x19C3F:
        r16[ax] = pop();
        si = pop();
        popf();
        return;
    } while (1);
}
function* sub_19C43() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x19C43:
        si = memory16get(ds*16+r16[bx]);
        si |= si;
        if (si == 0)
            return;
        r8[al] = memory[ds*16+si];
        si += 1;
        r8[ah] = memory[ds*16+si];
        si += 1;
        push(r16[bx]);
        yield* off_1040C();
        r16[bx] = pop();
        r16[bx] += 1;
        r16[bx] += 1;
        pc = 0x19C43;
        break;
        return;
    } while (1);
}
function* sub_19E18() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16+0xBDA2] = 0xc3;
        flags.carry = false;
        return;
        memory16set(ds*16+0x9A16, 0x0000);
        yield* off_10426();
    case 0x19E22:
        yield* sub_19EBB();
        r16[bx] = 0x99b3;
        yield* sub_19C43();
        yield* off_1041C();
        r16[bx] = 0x99b3;
        yield* sub_19C43();
        yield* off_1041C();
        memory[ds*16+0xB888] = 0x00;
        r16[ax] = memory16get(ds*16+0x9A16);
        r16[ax] <<= 1;
        di = 0x9a0c;
        di += r16[ax];
        di = memory16get(ds*16+di);
    case 0x19E4B:
        yield* _sync();
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] != 0) {
            pc = 0x19E6A;
            break;
        }
        r8[ah] = memory[ds*16+0xB888];
        flags.sign = !!(r8[ah] & 0x80);
        r8[ah] |= r8[ah];
        if (flags.sign) {
            pc = 0x19E4B;
            break;
        }
        if (r8[ah] == 0) {
            pc = 0x19E4B;
            break;
        }
        if (r8[ah] != 0x01) {
            pc = 0x19E6C;
            break;
        }
        memory[cs*16+0xBDA2] = 0xc3;
        flags.carry = false;
        return;
    case 0x19E6A:
        flags.carry = true;
        return;
    case 0x19E6C:
        if (r8[ah] != 0x1c) {
            pc = 0x19E7D;
            break;
        }
        yield* sub_19ED0();
        si = 0x9a06;
        yield* sub_19EB5();
        pc = 0x19E9B;
        break;
        _STOP_("db 90h");
    case 0x19E7D:
        si = 0x99e5;
    case 0x19E80:
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x19EB2;
            break;
        }
        if (r8[al] != r8[ah]) {
            pc = 0x19E80;
            break;
        }
        yield* sub_19ED0();
        si -= 1;
        si -= 0x001a;
        r8[al] = memory[ds*16+si];
        memory[ds*16+0x9A00] = r8[al];
        si = 0x9a00;
        yield* sub_19EB5();
    case 0x19E9B:
        memory16set(ds*16+0x9A16, memory16get(ds*16+0x9A16) + 1);
        if (memory16get(ds*16+0x9A16) != 0x0005) {
            pc = 0x19EAF;
            break;
        }
        memory16set(ds*16+0x9A16, 0x0000);
        pc = 0x19E22;
        break;
    case 0x19EAF:
        pc = 0x19E22;
        break;
    case 0x19EB2:
        pc = 0x19E22;
        break;
        return;
    } while (1);
}
function* sub_19EB5() {
    r16[cx] = 0x0006;
    rep_movsb_data_data_forward();
}
function* sub_19EBB() {
    r16[ax] = memory16get(ds*16+0x9A16);
    r16[ax] <<= 1;
    si = 0x99a9;
    si += r16[ax];
    si = memory16get(ds*16+si);
    di = 0x9958;
    r16[cx] = 0x0005;
    rep_movsb_data_data_forward();
}
function* sub_19ED0() {
    r16[bx] = 0xb874;
    r16[cx] = memory16get(ds*16+0x9A16);
    r16[bx] += r16[cx];
    memory[ds*16+r16[bx]] = r8[ah];
}
function* sub_19EE5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* off_1043A();
        yield* off_10426();
        yield* sub_16B3B();
        r16[ax] = 0x0c0f;
        si = 0x9adc;
        yield* off_1040C();
        yield* off_1041C();
        r16[cx] = 0x01e0;
    case 0x19F01:
        push(r16[cx]);
        yield* sub_19B1C();
        yield* sub_19BDC();
        if (r8[al] & 0x10) {
            pc = 0x19F10;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x19F01;
            break;
        }
        return;
    case 0x19F10:
        r16[cx] = pop();
        return;
    } while (1);
}
function* loc_19F12() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* off_1043A();
        r16[ax] = 0x0004;
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        r16[ax] = 0x0002;
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        yield* sub_19EE5();
        yield* sub_16D69();
        yield* sub_1A5E3();
        yield* sub_16CD7();
        _STOP_("goto loc_1C359");
    case 0x19F37:
        yield* off_1043A();
        r16[ax] = 0x0004;
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        r16[ax] = 0x0006;
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        r16[ax] = 0x0002;
        yield* sub_1A257();
        yield* sub_16D69();
        yield* sub_1A5E3();
        yield* sub_16CD7();
        _STOP_("goto loc_1C359");
        _STOP_("db 44h, 4Fh, 20h, 59h, 4Fh, 55h, 20h, 57h,...");
        _STOP_("db 20h, 54h, 4Fh, 20h, 51h, 55h, 49h, 54h,...");
        _STOP_("db 49h, 53h, 20h, 47h, 41h, 4Dh, 45h, 0FFh...");
        _STOP_("db 2 dup(53h), 20h, 59h, 20h, 4Fh, 52h, 20...");
        return;
    } while (1);
}
function* sub_19F8A() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[ax] = 0x0c05;
        si = 0x9b5f;
        yield* off_1040E();
        r16[ax] = 0x0d0e;
        si = 0x9b7d;
        yield* off_1040E();
        yield* off_10438();
    case 0x19FA4:
        r8[al] = memory[cs*16+0xB888];
        if (r8[al] != 0x15) {
            pc = 0x19FB0;
            break;
        }
        flags.carry = true;
        pc = 0x19FB5;
        break;
    case 0x19FB0:
        if (r8[al] != 0x31) {
            pc = 0x19FA4;
            break;
        }
        flags.carry = false;
    case 0x19FB5:
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_1A102() {
    di = 0x9ca8;
    r16[ax] = r16[ax] ^ r16[ax];
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    r16[ax] <<= 1;
    di += r16[ax];
    di = memory16get(ds*16+di);
}
function* sub_1A111() {
    di = 0x9cfa;
    r16[ax] = r16[ax] ^ r16[ax];
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    r16[ax] <<= 1;
    di += r16[ax];
    di = memory16get(ds*16+di);
}
function* sub_1A121() {
    yield* sub_1A102();
    memory16set(ds*16+di, 0x0001);
    r16[ax] = r16[ax] ^ r16[ax];
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 2, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 4, r16[ax]);
}
function* sub_1A137() {
    yield* sub_1A102();
    memory16set(ds*16+di, 0x0000);
}
function* sub_1A13F() {
    yield* sub_1A102();
    memory16set(ds*16+di, 0x0002);
    r16[ax] = r16[ax] ^ r16[ax];
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 18, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 20, r16[ax]);
}
function* sub_1A155() {
    yield* sub_1A102();
    r16[ax] = memory16get(ds*16+r16[bx]);
    r16[bx] += 1;
    r16[bx] += 1;
    r16[ax] += 0x2314;
    memory16set(ds*16+di + 22, r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+di + 24, r16[ax]);
}
function* sub_1A168() {
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    yield* sub_1A16B();
}
function* sub_1A16B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x1A174;
            break;
        }
        yield* indirectCall(ds, memory16get(ds*16+0x30));
        return;
    case 0x1A174:
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] -= 1;
        r16[ax] <<= 1;
        si = 0x2314;
        si = memory16get(ds*16+si);
        si += 0x2314;
        si += r16[ax];
        si = memory16get(ds*16+si);
        si += 0x2314;
        si += 0x0008;
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[ah] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        yield* indirectCall(ds, memory16get(ds*16+0x2C));
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        si += r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[cl] = 0x05;
        r16[ax] <<= r8[cl];
        si += r16[ax];
        r8[cl] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[ch] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(di);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x2E));
        si = pop();
        di = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1A1BC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        r8[ah] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        si = r16[bx];
        push(r16[ax]);
        push(r16[bx]);
        push(si);
        yield* indirectCall(ds, memory16get(ds*16+0x32));
        si = pop();
        r16[bx] = pop();
        r16[ax] = pop();
    case 0x1A1CE:
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        if (r8[al] != 0xff) {
            pc = 0x1A1CE;
            break;
        }
        return;
    } while (1);
}
function* sub_1A1D7() {
    r8[al] = memory[ds*16+r16[bx]];
    _cbw();
    r16[bx] += 1;
    push(r16[bx]);
    memory16set(ds*16+0xBDF2, r16[ax]);
    yield* sub_1AECD();
    r16[bx] = pop();
}
function* sub_1A1E4() {
    r16[bx] += 1;
}
function* sub_1A1E6() {
    yield* sub_1A102();
    memory16set(ds*16+di, 0x0003);
    r16[ax] = memory16get(ds*16+r16[bx]);
    r16[bx] += 1;
    r16[bx] += 1;
    r16[ax] += 0x2314;
    memory16set(ds*16+di + 6, r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+di + 8, r16[ax]);
}
function* sub_1A1FD() {
    yield* sub_1A111();
    memory16set(ds*16+di, 0x0001);
    r16[ax] = r16[ax] ^ r16[ax];
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 2, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 4, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 6, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 8, r16[ax]);
    r8[al] = memory[ds*16+r16[bx]];
    r16[bx] += 1;
    memory16set(ds*16+di + 10, r16[ax]);
    memory16set(ds*16+di + 12, 0x0000);
    r16[ax] = memory16get(ds*16+r16[bx]);
    r16[bx] += 1;
    r16[bx] += 1;
    r16[ax] += 0x2314;
    memory16set(ds*16+di + 14, r16[ax]);
}
function* sub_1A234() {
    yield* sub_1A111();
    memory16set(ds*16+di, 0x0000);
}
function* sub_1A23E() {
    r16[ax] = memory16get(ds*16+r16[bx]);
    r16[bx] += 1;
    r16[bx] += 1;
    r16[ax] += 0x2314;
    memory16set(ds*16+0x9E3C, r16[bx]);
    r16[bx] = r16[ax];
}
function* sub_1A24C() {
    r16[bx] = memory16get(ds*16+0x9E3C);
}
function* sub_1A257() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9E51, sp);
        memory16set(ds*16+0x8BF0, 0x0000);
        memory16set(ds*16+0x9E55, r16[ax]);
        memory16set(ds*16+0x9E53, 0x0000);
        yield* sub_1C4CA();
        if (!(r8[al] & 0x10)) {
            pc = 0x1A277;
            break;
        }
        memory16set(ds*16+0x9E53, 0x0001);
    case 0x1A277:
        yield* sub_16B3B();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        yield* sub_16B3B();
        r16[ax] = memory16get(ds*16+0x9E55);
        r16[ax] <<= 1;
        r16[bx] = 0x2316;
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds*16+r16[bx]);
        r16[bx] += 0x2314;
        di = 0x9bd6;
        r16[cx] = 0x0008;
    case 0x1A297:
        memory16set(ds*16+di, 0x0000);
        di += 0x001a;
        if (--r16[cx]) {
            pc = 0x1A297;
            break;
        }
        di = 0x9cb8;
        r16[cx] = 0x0004;
    case 0x1A2A6:
        memory16set(ds*16+di, 0x0000);
        di += 0x0010;
        if (--r16[cx]) {
            pc = 0x1A2A6;
            break;
        }
    case 0x1A2AF:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[al] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
        if (r8[al] == 0x00)
            return;
        r16[ax] <<= 1;
        si = 0x9bb8;
        si += r16[ax];
        // std::cout << "Skip intro\n";
        yield* indirectCall(ds, memory16get(ds*16+si));
        pc = 0x1A2AF;
        break;
        return;
    } while (1);
}
function* sub_1A2C4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        yield* sub_1C4CA();
        r16[bx] = pop();
        r16[dx] = memory16get(ds*16+0x9E55);
        if (r16[dx] != 0x0000) {
            pc = 0x1A2D3;
            break;
        }
        return;
    case 0x1A2D3:
        if (r16[dx] != 0x0001) {
            pc = 0x1A2F1;
            break;
        }
        if (!(r8[al] & 0x10)) {
            pc = 0x1A2E8;
            break;
        }
        if (memory16get(ds*16+0x9E53) == 0x0001) {
            pc = 0x1A2EE;
            break;
        }
        sp = memory16get(ds*16+0x9E51);
        return;
    case 0x1A2E8:
        memory16set(ds*16+0x9E53, 0x0000);
    case 0x1A2EE:
        r8[al] &= 0xef;
        return;
    case 0x1A2F1:
        r8[al] &= 0xef;
        return;
    } while (1);
}
function* sub_1A2F6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_16B3B();
        memory16set(ds*16+0x9EF4, 0x0000);
        r16[cx] = r16[cx] ^ r16[cx];
        r8[cl] = memory[ds*16+r16[bx]];
        r16[bx] += 1;
    case 0x1A304:
        push(r16[cx]);
        memory16set(ds*16+0x9EF4, memory16get(ds*16+0x9EF4) + 1);
        if (memory16get(ds*16+0x9EF4) != 0x0007) {
            pc = 0x1A316;
            break;
        }
        memory16set(ds*16+0x9EF4, 0x0000);
    case 0x1A316:
        yield* sub_1A389();
        yield* sub_1A437();
        yield* sub_1A2C4();
        if (!(r8[al] & 0x10)) {
            pc = 0x1A32A;
            break;
        }
        if (memory16get(ds*16+0x9EF4) != 0x0000) {
            pc = 0x1A33D;
            break;
        }
    case 0x1A32A:
        yield* indirectCall(ds, memory16get(ds*16+0x34));
        yield* indirectCall(ds, memory16get(ds*16+0x44));
        yield* sub_19B1C();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        yield* indirectCall(ds, memory16get(ds*16+0x38));
    case 0x1A33D:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1A304;
            break;
        }
        return;
    } while (1);
}
function* sub_1A341() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x9cb8;
    case 0x1A344:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (r16[ax] == 0) {
            pc = 0x1A353;
            break;
        }
        push(si);
        push(r16[bx]);
        yield* sub_1A359();
        r16[bx] = pop();
        si = pop();
    case 0x1A353:
        si += 0x0010;
        pc = 0x1A344;
        break;
        return;
    } while (1);
}
function* sub_1A359() {
    r8[al] = memory[ds*16+si + 2];
    r8[ah] = memory[ds*16+si + 4];
    push(r16[ax]);
    push(r16[bx]);
    push(si);
    si = memory16get(ds*16+si + 14);
    yield* indirectCall(ds, memory16get(ds*16+0x32));
    si = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    memory16set(ds*16+si + 12, memory16get(ds*16+si + 12) + 1);
    r16[ax] = memory16get(ds*16+si + 10);
    if (r16[ax] != memory16get(ds*16+si + 12))
        return;
    r16[ax] = memory16get(ds*16+si + 6);
    memory16set(ds*16+si + 2, memory16get(ds*16+si + 2) + r16[ax]);
    r16[ax] = memory16get(ds*16+si + 8);
    memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+si + 12, r16[ax]);
    return;
}
function* sub_1A389() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x9bd6;
    case 0x1A38C:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (r16[ax] == 0) {
            pc = 0x1A3C9;
            break;
        }
        if (r16[ax] == 0x0001) {
            pc = 0x1A3C9;
            break;
        }
        if (r16[ax] != 0x0002) {
            pc = 0x1A3C2;
            break;
        }
        r16[ax] = memory16get(ds*16+si + 18);
        memory16set(ds*16+si + 2, memory16get(ds*16+si + 2) + r16[ax]);
        if (memory16gets(ds*16+si + 2) < signed16(0x00e8)) {
            pc = 0x1A3AF;
            break;
        }
        memory16set(ds*16+si, 0x0000);
    case 0x1A3AF:
        if (memory16gets(ds*16+si + 2) >= signed16(0x0000)) {
            pc = 0x1A3B9;
            break;
        }
        memory16set(ds*16+si, 0x0000);
    case 0x1A3B9:
        r16[ax] = memory16get(ds*16+si + 20);
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[ax]);
        pc = 0x1A3C9;
        break;
        _STOP_("db  90h");
    case 0x1A3C2:
        push(r16[bx]);
        push(si);
        yield* sub_1A3CF();
        si = pop();
        r16[bx] = pop();
    case 0x1A3C9:
        si += 0x001a;
        pc = 0x1A38C;
        break;
        return;
    } while (1);
}
function* sub_1A3CF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[bx] = memory16get(ds*16+si + 6);
        r8[al] = memory[ds*16+r16[bx]];
        if (r8[al] != 0x00) {
            pc = 0x1A3DF;
            break;
        }
        r16[bx] += 1;
        r16[bx] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+si + 6, r16[bx]);
    case 0x1A3DF:
        r16[bx] += 1;
        r8[al] = memory[ds*16+r16[bx]];
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        sar8(al, 1);
        if (r8[al] != 0x07) {
            pc = 0x1A3F0;
            break;
        }
        r8[al] += 1;
    case 0x1A3F0:
        _cbw();
        memory16set(ds*16+si + 2, memory16get(ds*16+si + 2) + r16[ax]);
        if (memory16gets(ds*16+si + 2) < signed16(0x00e8)) {
            pc = 0x1A3FF;
            break;
        }
        memory16set(ds*16+si, 0x0000);
    case 0x1A3FF:
        if (memory16gets(ds*16+si + 2) >= signed16(0x0000)) {
            pc = 0x1A409;
            break;
        }
        memory16set(ds*16+si, 0x0000);
    case 0x1A409:
        r8[al] = memory[ds*16+r16[bx]];
        r8[al] &= 0x0f;
        if (!(r8[al] & 0x08)) {
            pc = 0x1A413;
            break;
        }
        r8[al] |= 0xf0;
    case 0x1A413:
        if (r8[al] != 0x07) {
            pc = 0x1A419;
            break;
        }
        r8[al] += 1;
    case 0x1A419:
        _cbw();
        memory16set(ds*16+si + 4, memory16get(ds*16+si + 4) + r16[ax]);
        r16[bx] -= 1;
        r8[al] = memory[ds*16+r16[bx]];
        _cbw();
        memory16set(ds*16+si + 8, memory16get(ds*16+si + 8) + 1);
        if (r16[ax] == memory16get(ds*16+si + 8)) {
            pc = 0x1A42B;
            break;
        }
        if (r16[ax] >= memory16get(ds*16+si + 8)) {
            pc = 0x1A435;
            break;
        }
    case 0x1A42B:
        memory16set(ds*16+si + 8, 0x0000);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+si + 6, r16[bx]);
    case 0x1A435:
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1A437() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x9bd6;
    case 0x1A43A:
        r16[ax] = memory16get(ds*16+si);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign)
            return;
        if (r16[ax] == 0) {
            pc = 0x1A449;
            break;
        }
        push(r16[bx]);
        push(si);
        yield* sub_1718E();
        si = pop();
        r16[bx] = pop();
    case 0x1A449:
        si += 0x001a;
        pc = 0x1A43A;
        break;
        return;
    } while (1);
}
function* sub_1A44F() {
    r16[ax] = memory16get(ds*16+0x62);
    r16[cx] = 0x0000;
    r16[dx] = 0x00c1;
    yield* sub_1A65B();
}
function* sub_1A45C() {
    r16[ax] = _seg001;
    r16[cx] = 0x3374;
    r16[dx] = 0x006b;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x3974;
    r16[dx] = 0x0077;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x3c74;
    r16[dx] = 0x0084;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x4c74;
    r16[dx] = 0x0091;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x53f4;
    r16[dx] = 0x009d;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x1180;
    r16[dx] = 0x00aa;
    yield* sub_1A65B();
    r16[ax] = _seg001;
    r16[cx] = 0x2314;
    r16[dx] = 0x00b6;
    yield* sub_1A65B();
}
function* sub_1A54A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x006b;
        r16[ax] = memory16get(ds*16+0x8BEC);
        r16[ax] -= 1;
        r16[ax] += 0x0031;
    case 0x1A554:
        r8[ah] = memory[ds*16+si];
        if (r8[ah] == 0xff)
            return;
        if (r8s[ah] < signed8(0x31)) {
            pc = 0x1A567;
            break;
        }
        if (r8s[ah] > signed8(0x35)) {
            pc = 0x1A567;
            break;
        }
        memory[ds*16+si] = r8[al];
    case 0x1A567:
        si += 1;
        pc = 0x1A554;
        break;
        return;
    } while (1);
}
function* sub_1A56B() {
    yield* indirectCall(ds, memory16get(ds*16+0x26));
    r16[ax] = 0x0a0c;
    si = 0x94c1;
    yield* indirectCall(ds, memory16get(ds*16+0x46));
    r16[ax] = 0x0b0c;
    si = 0x94e1;
    yield* indirectCall(ds, memory16get(ds*16+0x46));
    r16[ax] = 0x0c0c;
    si = 0x9501;
    yield* indirectCall(ds, memory16get(ds*16+0x46));
    yield* indirectCall(ds, memory16get(ds*16+0x1C));
}
function* sub_1A592() {
    var cs = _seg001;
    push(cs);
    ds = pop();
    di = 0x66f6;
    r16[cx] = 0x0006;
    r8[al] = 0x0a;
    rep_stosb_data_forward();
    memory16set(ds*16+0x6610, 0x0006);
    di = 0x66fd;
    r16[cx] = 0x0006;
    r8[al] = 0x0b;
    rep_stosb_data_forward();
    memory16set(ds*16+0x6612, 0x0006);
    di = 0x6704;
    r16[cx] = 0x0006;
    r8[al] = 0x0c;
    rep_stosb_data_forward();
    memory16set(ds*16+0x6614, 0x0006);
    yield* sub_1A5F0();
    yield* off_1041A();
    memory16set(ds*16+0x8BEC, 0x0001);
    memory16set(ds*16+0x7E16, 0x0000);
    memory16set(ds*16+0x7E18, 0x0000);
    memory16set(ds*16+0x7E00, 0x0000);
    yield* sub_1A5E3();
}
function* sub_1A5E3() {
    var cs = _seg001;
    push(cs);
    ds = pop();
    di = 0x6616;
    r16[cx] = 0x0006;
    r8[al] = r8[al] ^ r8[al];
    rep_stosb_data_forward();
}
function* sub_1A5F0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+0xB00, r16[ax]);
        memory16set(ds*16+0xB38, r16[ax]);
        r16[ax] += 1;
        memory16set(ds*16+0xB1C, r16[ax]);
        r16[ax] -= 1;
        di = 0x0b56;
    case 0x1A600:
        r16[dx] = memory16get(ds*16+di);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign) {
            pc = 0x1A60C;
            break;
        }
        stosw_data_forward();
        di += 0x0032;
        pc = 0x1A600;
        break;
    case 0x1A60C:
        di = 0x0c28;
    case 0x1A60F:
        r16[dx] = memory16get(ds*16+di);
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (flags.sign)
            return;
        stosw_data_forward();
        di += 0x0032;
        pc = 0x1A60F;
        break;
        return;
    } while (1);
}
function* sub_1A65B() {
    memory16set(ds*16+0xA255, r16[ax]);
    memory16set(ds*16+0xA257, r16[cx]);
    yield* sub_1A67B();
    push(ds);
    r16[bx] = memory16get(ds*16+0xA259);
    r16[ax] = memory16get(ds*16+0xA255);
    r16[dx] = memory16get(ds*16+0xA257);
    ds = r16[ax];
    yield* sub_1A693();
    ds = pop();
    yield* sub_1A69D();
}
function* sub_1A67B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3d;
        r8[al] = 0x00;
        interrupt(33);
        if (flags.carry)
            _STOP_("goto loc_1A6FB");
        push(ds);
        push(r16[ax]);
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[ax] = pop();
        memory16set(ds*16+0xA259, r16[ax]);
        ds = pop();
        return;
    } while (1);
}
function* sub_1A693() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3f;
        r16[cx] = 0xffff;
        interrupt(33);
        if (flags.carry)
            _STOP_("goto loc_1A6FB");
        return;
    } while (1);
}
function* sub_1A69D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds*16+0xA259);
        interrupt(33);
        if (flags.carry) {
            pc = 0x1A6FB;
            break;
        }
        return;
    case 0x1A6A8:
        memory16set(ds*16+0xA24F, r16[ax]);
        memory16set(ds*16+0xA251, r16[bx]);
        memory16set(ds*16+0xA253, r16[cx]);
        yield* loc_1A6E0();
        r16[ax] = memory16get(ds*16+0xA24F);
        r16[bx] = memory16get(ds*16+0xA251);
        r16[cx] = memory16get(ds*16+0xA253);
        push(ds);
        ds = r16[ax];
        r16[dx] = r16[bx];
        yield* loc_1A6CE();
        ds = pop();
        yield* sub_1A69D();
        return;
    case 0x1A6CE:
        push(ds);
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[bx] = memory16get(ds*16+0xA259);
        ds = pop();
        r8[ah] = 0x40;
        interrupt(33);
        if (flags.carry) {
            pc = 0x1A6FB;
            break;
        }
        return;
    case 0x1A6E0:
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[cx] = 0x0000;
        r8[ah] = 0x3c;
        interrupt(33);
        if (flags.carry) {
            pc = 0x1A6FB;
            break;
        }
        push(ds);
        push(r16[ax]);
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[ax] = pop();
        memory16set(ds*16+0xA259, r16[ax]);
        ds = pop();
        return;
    case 0x1A6FB:
        push(ds);
        r16[ax] = 0x0003;
        interrupt(16);
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[dx] = 0xa21c;
        r8[ah] = 0x09;
        interrupt(33);
        ds = pop();
        r16[ax] = _seg001;
        ds = r16[ax];
        memory[ds*16+0xB888] = 0x00;
    case 0x1A719:
        r8[al] = memory[ds*16+0xB888];
        if (r8[al] == 0x00) {
            pc = 0x1A719;
            break;
        }
    {yield* loc_196F3(); return; };
        return;
    } while (1);
}
function* sub_1AC6D() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1AC6D:
        r16[ax] = _seg001;
        ds = r16[ax];
        if (memory[ds*16+0xA85E] == 0xff) {
            pc = 0x1AC7D;
            break;
        }
        yield* sub_1AEE6();
        return;
    case 0x1AC7D:
        if (memory[ds*16+0xA860] == 0x01) {
            pc = 0x1AC8A;
            break;
        }
        memory[ds*16+0xA85E] = 0x00;
        return;
    case 0x1AC8A:
        if (!(memory[ds*16+0xA85A] & 0xff)) {
            pc = 0x1AC94;
            break;
        }
        pc = 0x1AD0F;
        break;
    case 0x1AC94:
        memory16set(ds*16+0xA850, 0x0000);
        memory[ds*16+0xA85E] = 0xff;
        memory[ds*16+0xA852] -= 1;
        if (memory[ds*16+0xA852] == 0) {
            pc = 0x1ACB5;
            break;
        }
        si = memory16get(ds*16+0xA858);
        memory16set(ds*16+0xA856, si);
        memory[ds*16+0xA85A] = 0xff;
        pc = 0x1AD0F;
        break;
        _STOP_("db 90h");
    case 0x1ACB5:
        memory[ds*16+0xA852] = 0x01;
        si = memory16get(ds*16+0xA854);
    case 0x1ACBE:
        r8[al] = memory[ds*16+si];
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        if (r16[ax] != 0x00ff) {
            pc = 0x1ACD1;
            break;
        }
        yield* sub_1ADB0();
        memory[ds*16+0xA85E] = 0x00;
        return;
    case 0x1ACD1:
        if (r16s[ax] < signed16(0x00c0)) {
            pc = 0x1ACE0;
            break;
        }
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory[ds*16+0xA84E] = r8[al];
        lodsb_data_forward();
        pc = 0x1ACF3;
        break;
    case 0x1ACE0:
        if (r16s[ax] < signed16(0x0081)) {
            pc = 0x1ACE7;
            break;
        }
        pc = 0x1ACBE;
        break;
    case 0x1ACE7:
        if (r16s[ax] < signed16(0x0080)) {
            pc = 0x1ACF3;
            break;
        }
        r16[ax] -= 0x0080;
        memory[ds*16+0xA852] = r8[al];
        lodsb_data_forward();
    case 0x1ACF3:
        r16[bx] = 0xa5e1;
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xA856, r16[bx]);
        memory16set(ds*16+0xA854, si);
        memory16set(ds*16+0xA858, r16[bx]);
        memory[ds*16+0xA85A] = 0xff;
    case 0x1AD0F:
        memory16set(ds*16+0xA850, memory16get(ds*16+0xA850) - 1);
        if (memory16gets(ds*16+0xA850) <= signed16(0x0003)) {
            pc = 0x1AD1B;
            break;
        }
        return;
    case 0x1AD1B:
        if (memory16get(ds*16+0xA850) == 0xffff) {
            pc = 0x1AD25;
            break;
        }
        pc = 0x1AD6A;
        break;
        _STOP_("db 90h");
    case 0x1AD25:
        si = memory16get(ds*16+0xA856);
        r16[bx] = 0xa7d2;
    case 0x1AD2C:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        if (r16[ax] != 0x00ff) {
            pc = 0x1AD3C;
            break;
        }
        memory[ds*16+0xA85A] = 0x00;
        pc = 0x1AC6D;
        break;
    case 0x1AD3C:
        if (r16[ax] == 0x003d) {
            pc = 0x1AD60;
            break;
        }
        if (r16s[ax] < signed16(0x0081)) {
            pc = 0x1AD48;
            break;
        }
        pc = 0x1AD2C;
        break;
    case 0x1AD48:
        r8[al] = r8[al] + memory[ds*16+0xA84E];
        r16[ax] <<= 1;
        r16[bx] += r16[ax];
        r16[cx] = memory16get(ds*16+r16[bx]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0xA856, si);
        memory16set(ds*16+0xA850, r16[ax]);
        yield* sub_1ADB7();
        return;
    case 0x1AD60:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0xA856, si);
        memory16set(ds*16+0xA850, r16[ax]);
    case 0x1AD6A:
        yield* sub_1ADB0();
        return;
    } while (1);
}
function* sub_1AD6E() {
    r8[ah] = r8[ah] ^ r8[ah];
    r16[ax] <<= 1;
    r16[bx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] += r16[bx];
    r16[bx] = 0xa64d;
    r16[bx] += r16[ax];
    r16[bx] = memory16get(ds*16+r16[bx]);
    memory16set(ds*16+0xA854, r16[bx]);
    memory[ds*16+0xA852] = 0x01;
    memory[ds*16+0xA84E] = 0x00;
    memory16set(ds*16+0xA850, 0x0001);
    memory16set(ds*16+0xA856, 0x0000);
    memory16set(ds*16+0xA858, 0x0000);
    memory[ds*16+0xA85A] = 0x00;
    memory16set(ds*16+0xA85C, 0x0000);
    memory[ds*16+0xA85E] = 0xff;
}
function* sub_1ADB0() {
    _in(r8[al], 97);
    r8[al] &= 0xfd;
    out8(97, r8[al]);
}
function* sub_1ADB7() {
    r16[dx] = 0x0043;
    r8[al] = 0xb6;
    out8(r16[dx], r8[al]);
    r16[dx] -= 1;
    r8[al] = r8[cl];
    out8(r16[dx], r8[al]);
    r8[al] = r8[ch];
    out8(r16[dx], r8[al]);
    _in(r8[al], 97);
    r8[al] |= 0x03;
    out8(97, r8[al]);
}
function* sub_1ADCB() {
    var cs = _seg001;
    push(ds);
    push(es);
    r8[ah] = 0x35;
    r8[al] = 0x08;
    interrupt(33);
    push(r16[ax]);
    r16[ax] = _seg001;
    ds = r16[ax];
    r16[ax] = pop();
    memory16set(ds*16+0xB88E, es);
    memory16set(cs*16+0xAA7B, es);
    memory16set(ds*16+0xB890, r16[bx]);
    memory16set(cs*16+0xAA79, r16[bx]);
    r8[ah] = 0x25;
    r8[al] = 0x08;
    push(cs);
    ds = pop();
    r16[dx] = 0xaa28;
    interrupt(33);
    r16[ax] = 0x4000;
    out8(64, r8[al]);
    r8[al] = r8[ah];
    out8(64, r8[al]);
    es = pop();
    ds = pop();
}
function* sub_1AE03() {
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x0000;
    out8(64, r8[al]);
    r8[al] = r8[ah];
    out8(64, r8[al]);
    r16[ax] = _seg001;
    ds = r16[ax];
    r16[dx] = memory16get(ds*16+0xB890);
    ds = memory16get(ds*16+0xB88E);
    r8[ah] = 0x25;
    r8[al] = 0x08;
    interrupt(33);
    r16[ax] = pop();
    ds = pop();
}
function* sub_1AE81() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0xAA26];
    case 0x1AE84:
        if (r8[al] == memory[ds*16+0xAA26]) {
            pc = 0x1AE84;
            break;
        }
        r8[al] = memory[ds*16+0xAA26];
    case 0x1AE8D:
        flags.carry = (memory[ds*16+0xAA7D] + 0x01) >= 0x100;
        memory[ds*16+0xAA7D] += 0x01;
        flags.carry2 = (memory[ds*16+0xAA7E] + 0x00 + flags.carry) >= 0x100;
        memory[ds*16+0xAA7E] = memory(ds, 0xAA7E) + 0x00 + flags.carry;flags.carry = flags.carry2;
        flags.carry2 = (memory[ds*16+0xAA7F] + 0x00 + flags.carry) >= 0x100;
        memory[ds*16+0xAA7F] = memory(ds, 0xAA7F) + 0x00 + flags.carry;flags.carry = flags.carry2;
        memory[ds*16+0xAA80] = memory(ds, 0xAA80) + 0x00 + flags.carry;
        if (r8[al] == memory[ds*16+0xAA26]) {
            pc = 0x1AE8D;
            break;
        }
        r16[ax] = memory16get(ds*16+0xAA7D);
        if (r16s[ax] < signed16(0x0b00)) {
            pc = 0x1AEB6;
            break;
        }
        memory16set(ds*16+0x96F4, 0x0003);
        return;
    case 0x1AEB6:
        if (r16s[ax] < signed16(0x0700)) {
            pc = 0x1AEC2;
            break;
        }
        memory16set(ds*16+0x96F4, 0x0002);
        return;
    case 0x1AEC2:
        memory16set(ds*16+0x96F4, 0x0001);
        yield* indirectCall(ds, memory16get(ds*16+0x4A));
        return;
    } while (1);
}
function* sub_1AECD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[ax] < signed16(0x000b)) {
            pc = 0x1AED5;
            break;
        }
    {yield* loc_1BB82(); return; };
    case 0x1AED5:
        if (memory16get(ds*16+0xAB2B) == 0x0001) {
            pc = 0x1AEE0;
            break;
        }
        yield* sub_1AD6E();
        return;
    case 0x1AEE0:
        r16[bx] = r16[ax];
        yield* sub_1B95D();
        return;
    } while (1);
}
function* sub_1AEE6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _seg001;
        ds = r16[ax];
        if (memory16get(ds*16+0xAB2B) == 0x0001)
            return;
        if (memory[ds*16+0xA85E] == 0xff)
            return;
        si = memory16get(ds*16+0xAB29);
        si |= si;
        if (si != 0) {
            pc = 0x1AF02;
            break;
        }
        return;
    case 0x1AF02:
        r8[cl] = memory[ds*16+si];
        r8[ch] = r8[ch] ^ r8[ch];
        si += 1;
        memory16set(ds*16+0xAB29, si);
        r16[cx] |= r16[cx];
        if (r16[cx] == 0) {
            pc = 0x1AF1C;
            break;
        }
        r16[cx] += r16[cx];
        r16[bx] = 0xa7d2;
        r16[bx] += r16[cx];
        r16[cx] = memory16get(ds*16+r16[bx]);
        yield* sub_1ADB7();
        return;
    case 0x1AF1C:
        memory16set(ds*16+0xAB29, 0x0000);
        yield* sub_1ADB0();
        return;
    } while (1);
}
function* sub_1B93B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _seg001;
        ds = r16[ax];
        r16[ax] = memory16get(ds*16+0xB369);
        r16[ax] = r16[ax] | memory16get(ds*16+0xB37D);
        r16[ax] = r16[ax] | memory16get(ds*16+0xB391);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x1B955;
            break;
        }
        memory[ds*16+0xA85E] = 0xff;
        return;
    case 0x1B955:
        memory[ds*16+0xA85E] = 0x00;
        return;
    } while (1);
}
function* sub_1B95D() {
    var cs = _seg001;
    r16[ax] = cs;
    ds = r16[ax];
    memory16set(ds*16+0xB55B, 0x0001);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    si = 0x0000;
    r16[bx] = 0xb3a7;
    interrupt(101);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    memory16set(ds*16+0xB3A7, 0x0001);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(di);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    si = 0x0006;
    r16[bx] = 0xb3a7;
    interrupt(101);
    es = pop();
    ds = pop();
    bp = pop();
    di = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[bx] += r16[bx];
    r16[ax] = r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[ax];
    r16[bx] += 0xa64d;
    di = 0xb369;
    memory16set(ds*16+di, 0x00ff);
    r16[ax] = memory16get(ds*16+r16[bx]);
    memory16set(ds*16+di + 2, r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+di + 16, r16[ax]);
    memory16set(ds*16+di + 12, r16[ax]);
    memory16set(ds*16+di + 18, r16[ax]);
    push(r16[bx]);
    yield* sub_1BB3F();
    r16[bx] = pop();
    r16[bx] += 1;
    r16[bx] += 1;
    di = 0xb37d;
    memory16set(ds*16+di, 0x00ff);
    r16[ax] = memory16get(ds*16+r16[bx]);
    memory16set(ds*16+di + 2, r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+di + 16, r16[ax]);
    r16[ax] = 0x0001;
    memory16set(ds*16+di + 12, r16[ax]);
    memory16set(ds*16+di + 18, r16[ax]);
    push(r16[bx]);
    yield* sub_1BB3F();
    r16[bx] = pop();
    r16[bx] += 1;
    r16[bx] += 1;
    di = 0xb391;
    memory16set(ds*16+di, 0x00ff);
    r16[ax] = memory16get(ds*16+r16[bx]);
    memory16set(ds*16+di + 2, r16[ax]);
    r16[ax] = r16[ax] ^ r16[ax];
    memory16set(ds*16+di + 16, r16[ax]);
    r16[ax] = 0x0002;
    memory16set(ds*16+di + 12, r16[ax]);
    memory16set(ds*16+di + 18, r16[ax]);
    yield* sub_1BB3F();
    memory16set(ds*16+0xB55B, 0x0000);
}
function* sub_1BA18() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0xA860] == 0x01) {
            pc = 0x1BA20;
            break;
        }
        return;
    case 0x1BA20:
        r16[ax] = cs;
        ds = r16[ax];
        di = 0xb369;
        yield* sub_1BA3A();
        di = 0xb37d;
        yield* sub_1BA3A();
        di = 0xb391;
        yield* sub_1BA3A();
        yield* sub_1B93B();
        return;
    } while (1);
}
function* sub_1BA3A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+di);
        r16[ax] |= r16[ax];
        if (r16[ax] != 0) {
            pc = 0x1BA41;
            break;
        }
        return;
    case 0x1BA41:
        r16[ax] = memory16get(ds*16+di + 12);
        memory16set(ds*16+di + 18, r16[ax]);
        si = memory16get(ds*16+di + 6);
        memory[ds*16+di + 8] += 1;
        r8[al] = memory[ds*16+si + 1];
        if (r8[al] == memory[ds*16+di + 8]) {
            pc = 0x1BA56;
            break;
        }
        return;
    case 0x1BA56:
        si += 1;
        si += 1;
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_1BB3F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+di + 10, 0x0001);
        si = memory16get(ds*16+di + 2);
    case 0x1BB47:
        r8[al] = memory[ds*16+si];
        if (r8[al] != 0xff) {
            pc = 0x1BB52;
            break;
        }
        memory16set(ds*16+di, 0x0000);
        return;
    case 0x1BB52:
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (!flags.sign) {
            pc = 0x1BB6C;
            break;
        }
        if (r8[al] != 0xc0) {
            pc = 0x1BB64;
            break;
        }
        si += 1;
        r8[al] = memory[ds*16+si];
        _cbw();
        memory16set(ds*16+di + 16, r16[ax]);
        si += 1;
        pc = 0x1BB47;
        break;
    case 0x1BB64:
        r8[al] &= 0x7f;
        memory[ds*16+di + 10] = r8[al];
        si += 1;
        pc = 0x1BB47;
        break;
    case 0x1BB6C:
        si += 1;
        memory16set(ds*16+di + 2, si);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] += r16[ax];
        r16[bx] = r16[ax];
        r16[bx] += 0xa5e1;
        si = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+di + 4, si);
        _STOP_("goto loc_1BA58");
        return;
    } while (1);
}
function* loc_1BB82() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = cs;
        ds = r16[bx];
        es = r16[bx];
        r16[ax] -= 0x000b;
        if (memory16get(ds*16+0xAB2B) == 0x0001) {
            pc = 0x1BB9E;
            break;
        }
        pc = 0x1BC4A;
        break;
    case 0x1BB9E:
        if (memory[ds*16+0xA85E] != 0xff) {
            pc = 0x1BBA8;
            break;
        }
        pc = 0x1BC40;
        break;
    case 0x1BBA8:
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si = 0xb181;
        si += r16[ax];
        r16[ax] = memory16get(ds*16+0xAB27);
        r16[ax] -= 1;
        if (r16s[ax] >= 0) {
            pc = 0x1BBBA;
            break;
        }
        r16[ax] = 0x0005;
    case 0x1BBBA:
        memory16set(ds*16+0xAB27, r16[ax]);
        r16[ax] = memory16get(ds*16+si + 2);
        push(r16[ax]);
        si = memory16get(ds*16+si);
        push(si);
        r16[ax] = memory16get(ds*16+0xAB27);
        memory16set(ds*16+0xB3A7, r16[ax]);
        si += 1;
        si += 1;
        memory16set(ds*16+0xB3A9, si);
        memory16set(ds*16+0xB3AB, ds);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = cs;
        es = r16[bx];
        si = 0x0015;
        r16[bx] = 0xb3a7;
        interrupt(101);
        es = pop();
        ds = pop();
        bp = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[ax] = memory16get(ds*16+0xAB27);
        memory16set(ds*16+0xB3A7, r16[ax]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = cs;
        es = r16[bx];
        si = 0x0014;
        r16[bx] = 0xb3a7;
        interrupt(101);
        es = pop();
        ds = pop();
        bp = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[ax] = memory16get(ds*16+0xAB27);
        memory16set(ds*16+0xB3A7, r16[ax]);
        si = pop();
        r16[ax] = pop();
        _cbw();
        memory16set(ds*16+0xB3A9, r16[ax]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        push(di);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = cs;
        es = r16[bx];
        si = 0x0013;
        r16[bx] = 0xb3a7;
        interrupt(101);
        es = pop();
        ds = pop();
        bp = pop();
        di = pop();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
    case 0x1BC40:
        es = pop();
        ds = pop();
        bp = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        di = pop();
        si = pop();
        return;
    case 0x1BC4A:
    case 0x1BC4F:
        if (memory[ds*16+0xA85E] != 0xff) {
            pc = 0x1BC53;
            break;
        }
        pc = 0x1BC40;
        break;
    case 0x1BC53:
        r16[dx] = memory16get(ds*16+0xAB29);
        r16[dx] |= r16[dx];
        if (r16[dx] == 0) {
            pc = 0x1BC65;
            break;
        }
        if (r16[ax] == 0x001a) {
            pc = 0x1BC40;
            break;
        }
        if (r16[ax] == 0x001b) {
            pc = 0x1BC40;
            break;
        }
    case 0x1BC65:
        r16[ax] += r16[ax];
        si = 0xb32d;
        si += r16[ax];
        si = memory16get(ds*16+si);
        memory16set(ds*16+0xAB29, si);
        pc = 0x1BC40;
        break;
        _STOP_("byte_1BC74 db 18h, 25h, 2Ch, 2Dh, 19h, 0Ah...");
        _STOP_("byte_1BC84 db 0");
        _STOP_("db 90h");
        _STOP_("byte_1BC86 db 0");
        _STOP_("db  90h");
        _STOP_("byte_1BC88 db 0");
        _STOP_("word_1BC8A dw 0");
        _STOP_("word_1BC8C dw 0");
        _STOP_("word_1BC8E dw 0");
        _STOP_("word_1BC90 dw 0");
        return;
    } while (1);
}
function* sub_1BC92() {
    var cs = _seg001;
    push(ds);
    push(es);
    r8[ah] = 0x35;
    r8[al] = 0x09;
    interrupt(33);
    r16[ax] = _seg001;
    ds = r16[ax];
    memory16set(ds*16+0xB88A, es);
    memory16set(ds*16+0xB88C, r16[bx]);
    r8[ah] = 0x25;
    r8[al] = 0x09;
    r16[dx] = cs;
    ds = r16[dx];
    r16[dx] = 0xb8cd;
    interrupt(33);
    es = pop();
    ds = pop();
}
function* sub_1BCB7() {
    push(ds);
    r16[ax] = _seg001;
    ds = r16[ax];
    r16[dx] = memory16get(ds*16+0xB88C);
    ds = memory16get(ds*16+0xB88A);
    r8[ah] = 0x25;
    r8[al] = 0x09;
    interrupt(33);
    ds = pop();
}
function* sub_1BCCD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pushf();
        flags.interrupt = false;
        push(r16[ax]);
        push(ds);
        r16[ax] = _seg001;
        ds = r16[ax];
        _in(r8[al], 96);
        memory[ds*16+0xB888] = r8[al];
        _in(r8[al], 97);
        r8[al] |= 0x80;
        out8(97, r8[al]);
        r8[al] &= 0x7f;
        out8(97, r8[al]);
        push(r16[bx]);
        r8[al] = memory[ds*16+0xB888];
        r8[ah] = r8[al];
        r8[ah] &= 0x80;
        if (r8[ah] != 0) {
            pc = 0x1BCF3;
            break;
        }
        pc = 0x1BE27;
        break;
    case 0x1BCF3:
        r8[bl] = memory[ds*16+0xB886];
        r8[al] &= 0x7f;
        if (r8[al] != 0x39) {
            pc = 0x1BD06;
            break;
        }
        r8[bl] &= 0xef;
        pc = 0x1BF56;
        break;
    case 0x1BD06:
        if (r8[al] != memory[ds*16+0xB874]) {
            pc = 0x1BD15;
            break;
        }
        r8[bl] &= 0xf7;
        pc = 0x1BF56;
        break;
    case 0x1BD15:
        if (r8[al] != memory[ds*16+0xB875]) {
            pc = 0x1BD24;
            break;
        }
        r8[bl] &= 0xfb;
        pc = 0x1BF56;
        break;
    case 0x1BD24:
        if (r8[al] != memory[ds*16+0xB876]) {
            pc = 0x1BD33;
            break;
        }
        r8[bl] &= 0xfd;
        pc = 0x1BF56;
        break;
    case 0x1BD33:
        if (r8[al] != memory[ds*16+0xB877]) {
            pc = 0x1BD42;
            break;
        }
        r8[bl] &= 0xfe;
        pc = 0x1BF56;
        break;
    case 0x1BD42:
        if (r8[al] != memory[ds*16+0xB878]) {
            pc = 0x1BD51;
            break;
        }
        r8[bl] &= 0xef;
        pc = 0x1BF56;
        break;
    case 0x1BD51:
        if (r8[al] != 0x7c) {
            pc = 0x1BD5E;
            break;
        }
        r8[bl] &= 0xf7;
        pc = 0x1BF56;
        break;
    case 0x1BD5E:
        if (r8[al] != 0x7b) {
            pc = 0x1BD6B;
            break;
        }
        r8[bl] &= 0xfb;
        pc = 0x1BF56;
        break;
    case 0x1BD6B:
        if (r8[al] != 0x7a) {
            pc = 0x1BD78;
            break;
        }
        r8[bl] &= 0xfd;
        pc = 0x1BF56;
        break;
    case 0x1BD78:
        if (r8[al] != 0x79) {
            pc = 0x1BD85;
            break;
        }
        r8[bl] &= 0xfe;
        pc = 0x1BF56;
        break;
    case 0x1BD85:
        if (r8[al] != 0x77) {
            pc = 0x1BD92;
            break;
        }
        r8[bl] &= 0xef;
        pc = 0x1BF56;
        break;
    case 0x1BD92:
        if (r8[al] != 0x48) {
            pc = 0x1BD9F;
            break;
        }
        r8[bl] &= 0xf7;
        pc = 0x1BF56;
        break;
    case 0x1BD9F:
        if (r8[al] != 0x50) {
            pc = 0x1BDAC;
            break;
        }
        r8[bl] &= 0xfb;
        pc = 0x1BF56;
        break;
    case 0x1BDAC:
        if (r8[al] != 0x4d) {
            pc = 0x1BDB9;
            break;
        }
        r8[bl] &= 0xfe;
        pc = 0x1BF56;
        break;
    case 0x1BDB9:
        if (r8[al] != 0x4b) {
            pc = 0x1BDC6;
            break;
        }
        r8[bl] &= 0xfd;
        pc = 0x1BF56;
        break;
    case 0x1BDC6:
        if (r8[al] != 0x1d) {
            pc = 0x1BDD5;
            break;
        }
        memory[ds*16+0xB879] &= 0xfe;
        pc = 0x1BF56;
        break;
    case 0x1BDD5:
        if (r8[al] != 0x38) {
            pc = 0x1BDE4;
            break;
        }
        memory[ds*16+0xB879] &= 0xfd;
        pc = 0x1BF56;
        break;
    case 0x1BDE4:
        if (r8[al] != 0x53) {
            pc = 0x1BDF3;
            break;
        }
        memory[ds*16+0xB879] &= 0xfb;
        pc = 0x1BF56;
        break;
    case 0x1BDF3:
        if (r8[al] != 0x47) {
            pc = 0x1BE00;
            break;
        }
        r8[bl] &= 0xf5;
        pc = 0x1BF56;
        break;
    case 0x1BE00:
        if (r8[al] != 0x49) {
            pc = 0x1BE0D;
            break;
        }
        r8[bl] &= 0xf6;
        pc = 0x1BF56;
        break;
    case 0x1BE0D:
        if (r8[al] != 0x4f) {
            pc = 0x1BE1A;
            break;
        }
        r8[bl] &= 0xf9;
        pc = 0x1BF56;
        break;
    case 0x1BE1A:
        if (r8[al] == 0x51) {
            pc = 0x1BE21;
            break;
        }
        pc = 0x1BF56;
        break;
    case 0x1BE21:
        r8[bl] &= 0xfa;
        pc = 0x1BF56;
        break;
    case 0x1BE27:
        r8[bl] = memory[ds*16+0xB886];
        if (r8[al] != 0x39) {
            pc = 0x1BE38;
            break;
        }
        r8[bl] |= 0x10;
        pc = 0x1BF56;
        break;
    case 0x1BE38:
        if (r8[al] != memory[ds*16+0xB874]) {
            pc = 0x1BE47;
            break;
        }
        r8[bl] |= 0x08;
        pc = 0x1BF56;
        break;
    case 0x1BE47:
        if (r8[al] != memory[ds*16+0xB875]) {
            pc = 0x1BE56;
            break;
        }
        r8[bl] |= 0x04;
        pc = 0x1BF56;
        break;
    case 0x1BE56:
        if (r8[al] != memory[ds*16+0xB876]) {
            pc = 0x1BE65;
            break;
        }
        r8[bl] |= 0x02;
        pc = 0x1BF56;
        break;
    case 0x1BE65:
        if (r8[al] != memory[ds*16+0xB877]) {
            pc = 0x1BE74;
            break;
        }
        r8[bl] |= 0x01;
        pc = 0x1BF56;
        break;
    case 0x1BE74:
        if (r8[al] != memory[ds*16+0xB878]) {
            pc = 0x1BE83;
            break;
        }
        r8[bl] |= 0x10;
        pc = 0x1BF56;
        break;
    case 0x1BE83:
        if (r8[al] != 0x7c) {
            pc = 0x1BE90;
            break;
        }
        r8[bl] |= 0x08;
        pc = 0x1BF56;
        break;
    case 0x1BE90:
        if (r8[al] != 0x7b) {
            pc = 0x1BE9D;
            break;
        }
        r8[bl] |= 0x04;
        pc = 0x1BF56;
        break;
    case 0x1BE9D:
        if (r8[al] != 0x7a) {
            pc = 0x1BEAA;
            break;
        }
        r8[bl] |= 0x02;
        pc = 0x1BF56;
        break;
    case 0x1BEAA:
        if (r8[al] != 0x79) {
            pc = 0x1BEB7;
            break;
        }
        r8[bl] |= 0x01;
        pc = 0x1BF56;
        break;
    case 0x1BEB7:
        if (r8[al] != 0x77) {
            pc = 0x1BEC4;
            break;
        }
        r8[bl] |= 0x10;
        pc = 0x1BF56;
        break;
    case 0x1BEC4:
        if (r8[al] != 0x48) {
            pc = 0x1BED1;
            break;
        }
        r8[bl] |= 0x08;
        pc = 0x1BF56;
        break;
    case 0x1BED1:
        if (r8[al] != 0x50) {
            pc = 0x1BEDE;
            break;
        }
        r8[bl] |= 0x04;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BEDE:
        if (r8[al] != 0x4d) {
            pc = 0x1BEEB;
            break;
        }
        r8[bl] |= 0x01;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BEEB:
        if (r8[al] != 0x4b) {
            pc = 0x1BEF8;
            break;
        }
        r8[bl] |= 0x02;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BEF8:
        if (r8[al] != 0x47) {
            pc = 0x1BF05;
            break;
        }
        r8[bl] |= 0x0a;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF05:
        if (r8[al] != 0x49) {
            pc = 0x1BF12;
            break;
        }
        r8[bl] |= 0x09;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF12:
        if (r8[al] != 0x4f) {
            pc = 0x1BF1F;
            break;
        }
        r8[bl] |= 0x06;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF1F:
        if (r8[al] != 0x51) {
            pc = 0x1BF2C;
            break;
        }
        r8[bl] |= 0x05;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF2C:
        if (r8[al] != 0x1d) {
            pc = 0x1BF3B;
            break;
        }
        memory[ds*16+0xB879] |= 0x01;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF3B:
        if (r8[al] != 0x38) {
            pc = 0x1BF4A;
            break;
        }
        memory[ds*16+0xB879] |= 0x02;
        pc = 0x1BF56;
        break;
        _STOP_("db  90h");
    case 0x1BF4A:
        if (r8[al] != 0x53) {
            pc = 0x1BF56;
            break;
        }
        memory[ds*16+0xB879] |= 0x04;
    case 0x1BF56:
        memory[ds*16+0xB886] = r8[bl];
        r8[bh] = memory[ds*16+0xB882];
        r8[bl] |= r8[bh];
        memory[ds*16+0xB884] = r8[bl];
        if (memory[ds*16+0xB879] != 0x07) {
            pc = 0x1BF73;
            break;
        }
        _STOP_("goto far ptr 0FFFFh:0");
    case 0x1BF73:
        r16[bx] = pop();
        ds = pop();
        r8[al] = 0x61;
        out8(32, r8[al]);
        r16[ax] = pop();
        popf();
        return;
    } while (1);
}
function* sub_1BF7C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x0201;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = r16[cx] ^ r16[cx];
        r8[al] = in8(r16[dx]);
        r16[ax] &= 0x0030;
        if (r16[ax] == 0x0030) {
            pc = 0x1BF8F;
            break;
        }
        r16[cx] = 0xffff;
    case 0x1BF8F:
        push(r16[cx]);
        r8[bl] = 0x01;
        yield* sub_1BFA0();
        push(r16[cx]);
        r8[bl] = 0x02;
        yield* sub_1BFA0();
        r16[dx] = r16[cx];
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1BFA0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        flags.interrupt = false;
        r8[al] = 0x00;
        out8(67, r8[al]);
    case 0x1BFA8:
        _in(r8[al], 64);
        r8[ah] = r8[al];
    case 0x1BFAE:
        _in(r8[al], 64);
        xchg8(ah, al);
        push(r16[ax]);
        r16[cx] = 0x04ff;
        out8(r16[dx], r8[al]);
    case 0x1BFB9:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & r8[bl]) {
            pc = 0x1BFB9;
            break;
        }
        r16[cx] = pop();
        if (r16[cx] != 0x0000) {
            pc = 0x1BFC9;
            break;
        }
        r16[cx] = r16[cx] ^ r16[cx];
        pc = 0x1BFF7;
        break;
        _STOP_("db 90h");
    case 0x1BFC9:
        r8[al] = 0x00;
        out8(67, r8[al]);
    case 0x1BFCF:
        _in(r8[al], 64);
        r8[ah] = r8[al];
    case 0x1BFD5:
        _in(r8[al], 64);
        xchg8(ah, al);
        if (r16[cx] >= r16[ax]) {
            pc = 0x1BFE9;
            break;
        }
        push(r16[dx]);
        r16[dx] = 0xffff;
        r16[dx] -= r16[ax];
        r16[cx] += r16[dx];
        r16[dx] = pop();
        pc = 0x1BFEB;
        break;
        _STOP_("db 90h");
    case 0x1BFE9:
        r16[cx] -= r16[ax];
    case 0x1BFEB:
        r16[cx] &= 0x1ff0;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
    case 0x1BFF7:
        flags.interrupt = true;
        r16[dx] = 0x0201;
        push(r16[cx]);
        push(r16[ax]);
        r16[cx] = 0x04ff;
    case 0x1C000:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & 0x0f) {
            pc = 0x1C000;
            break;
        }
        r16[ax] = pop();
        r16[cx] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_1C0A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        r16[bx] = 0xbc80;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        r16[bx] = 0xbc80;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
    case 0x1C0C0:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] != 0) {
            pc = 0x1C0C0;
            break;
        }
    case 0x1C0C8:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] == 0) {
            pc = 0x1C0C8;
            break;
        }
        memory16set(ds*16+0xBC98, r16[cx]);
        memory16set(ds*16+0xBC9A, r16[dx]);
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        r16[bx] = 0xbc88;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        r16[bx] = 0xbc88;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
    case 0x1C0F0:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] != 0) {
            pc = 0x1C0F0;
            break;
        }
    case 0x1C0F8:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] == 0) {
            pc = 0x1C0F8;
            break;
        }
        memory16set(ds*16+0xBC9C, r16[cx]);
        memory16set(ds*16+0xBC9E, r16[dx]);
        yield* indirectCall(ds, memory16get(ds*16+0x26));
        r16[bx] = 0xbc90;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
        r16[bx] = 0xbc90;
        yield* sub_19C43();
        yield* indirectCall(ds, memory16get(ds*16+0x1C));
    case 0x1C120:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] != 0) {
            pc = 0x1C120;
            break;
        }
    case 0x1C128:
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] == 0) {
            pc = 0x1C128;
            break;
        }
        memory16set(ds*16+0xBCA0, r16[cx]);
        memory16set(ds*16+0xBCA2, r16[dx]);
        r16[ax] = memory16get(ds*16+0xBC9C);
        r16[ax] = r16[ax] - memory16get(ds*16+0xBC98);
        r16[bx] = memory16get(ds*16+0xBC9E);
        r16[bx] = r16[bx] - memory16get(ds*16+0xBC9A);
        r8[dl] = 0x06;
        _idiv(r8[dl]);
        r16[ax] &= 0x00ff;
        _cbw();
        push(r16[ax]);
        r16[ax] = r16[bx];
        r8[dl] = 0x06;
        _idiv(r8[dl]);
        r8[al] &= 0xff;
        _cbw();
        r16[bx] = r16[ax];
        r16[ax] = pop();
        memory16set(ds*16+0xBCA4, r16[ax]);
        memory16set(ds*16+0xBCA6, r16[bx]);
        return;
    } while (1);
}
function* sub_1C164() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1C0A8();
        yield* sub_1BF7C();
        r16[cx] |= r16[dx];
        if (r16[cx] != 0) {
            pc = 0x1C175;
            break;
        }
        memory[cs*16+0xBDA2] = 0xc3;
        return;
    case 0x1C175:
        r16[ax] = memory16get(ds*16+0xBCA0);
        r16[dx] = memory16get(ds*16+0xBCA4);
        r16[ax] += r16[dx];
        memory16set(ds*16+0xB87E, r16[ax]);
        r16[ax] = memory16get(ds*16+0xBCA0);
        r16[dx] = -r16[dx];
        r16[ax] += r16[dx];
        memory16set(ds*16+0xB880, r16[ax]);
        r16[ax] = memory16get(ds*16+0xBCA2);
        r16[dx] = memory16get(ds*16+0xBCA6);
        r16[ax] += r16[dx];
        memory16set(ds*16+0xB87C, r16[ax]);
        r16[ax] = memory16get(ds*16+0xBCA2);
        r16[dx] = -r16[dx];
        r16[ax] += r16[dx];
        memory16set(ds*16+0xB87A, r16[ax]);
        return;
    } while (1);
}
function* loc_1C1A2() {
    if (memory[_seg001*16+0xBDA2] == 0xC3)
        return;
    r16[ax] = _seg001;
    yield* sub_1C1A5();
}
function* sub_1C1A5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        ds = r16[ax];
        yield* sub_1BF7C();
        r16[bx] &= 0x0003;
        if (r16[bx] == 0) {
            pc = 0x1C1B7;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        r8[bl] |= 0x10;
        pc = 0x1C1B9;
        break;
        _STOP_("db 90h");
    case 0x1C1B7:
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x1C1B9:
        if (r16[cx] < memory16get(ds*16+0xB87E)) {
            pc = 0x1C1C5;
            break;
        }
        r8[bl] |= 0x01;
        pc = 0x1C1CE;
        break;
        _STOP_("db 90h");
    case 0x1C1C5:
        if (r16[cx] >= memory16get(ds*16+0xB880)) {
            pc = 0x1C1CE;
            break;
        }
        r8[bl] |= 0x02;
    case 0x1C1CE:
        if (r16[dx] >= memory16get(ds*16+0xB87A)) {
            pc = 0x1C1DA;
            break;
        }
        r8[bl] |= 0x08;
        pc = 0x1C1E3;
        break;
    case 0x1C1DA:
        if (r16[dx] < memory16get(ds*16+0xB87C)) {
            pc = 0x1C1E3;
            break;
        }
        r8[bl] |= 0x04;
    case 0x1C1E3:
        memory[ds*16+0xB882] = r8[bl];
        r8[bh] = memory[ds*16+0xB886];
        r8[bl] |= r8[bh];
        memory[ds*16+0xB884] = r8[bl];
        return;
    } while (1);
}
function* start(pc) {
    assert(!pc);
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r8[ah] = 0x4a;
        r16[bx] = 0x0e00;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1C283;
            break;
        }
        _STOP_("goto loc_19731");
    case 0x1C283:
        r16[ax] = cs;
        es = r16[ax];
        si = 0x0080;
        di = _seg001;
        es = di;
        di = 0xbdf6;
        r8[cl] = memory[ds*16+si];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[cx] += 1;
        flags.direction = false;
        rep_movsb_data_data_forward();
        push(es);
        ds = pop();
        si = 0xbdf6;
        r16[cx] = 0x0080;
    case 0x1C2A2:
        r8[al] = memory[ds*16+si];
        si += 1;
        if (r8[al] == 0x2f) {
            pc = 0x1C2AE;
            break;
        }
    case 0x1C2A9:
        if (--r16[cx]) {
            pc = 0x1C2A2;
            break;
        }
        pc = 0x1C2E2;
        break;
    case 0x1C2AE:
        r8[al] = memory[ds*16+si];
        if (r8[al] == 0x63) {
            pc = 0x1C2D3;
            break;
        }
        if (r8[al] == 0x43) {
            pc = 0x1C2D3;
            break;
        }
        if (r8[al] == 0x65) {
            pc = 0x1C2CA;
            break;
        }
        if (r8[al] == 0x45) {
            pc = 0x1C2CA;
            break;
        }
        if (r8[al] == 0x74) {
            pc = 0x1C2E5;
            break;
        }
        if (r8[al] == 0x54) {
            pc = 0x1C2E5;
            break;
        }
        pc = 0x1C2A9;
        break;
    case 0x1C2CA:
        memory16set(ds*16+0x2F67, 0x2f4f);
        pc = 0x1C2E2;
        break;
        _STOP_("db 90h");
    case 0x1C2D3:
        memory16set(ds*16+0x2F67, 0x2f57);
        pc = 0x1C2E2;
        break;
        memory16set(ds*16+0x2F67, 0x2f5f);
    case 0x1C2E2:
    case 0x1C2E5:
        yield* off_10402();
        si = 0xbdf6;
        r16[cx] = 0x0080;
    case 0x1C2EF:
        r8[al] = memory[ds*16+si];
        si += 1;
        if (r8[al] == 0x2f) {
            pc = 0x1C308;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1C2EF;
            break;
        }
        push(ds);
        r16[ax] = _seg001;
        ds = r16[ax];
        memory16set(ds*16+0xAB2B, 0x0000);
        ds = pop();
        pc = 0x1C31F;
        break;
    case 0x1C308:
        r8[al] = memory[ds*16+si];
        if (r8[al] == 0x61) {
            pc = 0x1C312;
            break;
        }
        if (r8[al] != 0x41) {
            pc = 0x1C31F;
            break;
        }
    case 0x1C312:
        r16[ax] = _seg001;
        ds = r16[ax];
        es = r16[ax];
        memory16set(ds*16+0xAB2B, 0x0001);
    case 0x1C31F:
        yield* sub_196DD();
        memory[ds*16+0xA860] = 0x01;
        yield* nullsub_5();
        yield* off_1042A();
        yield* off_10408();
        yield* sub_1A44F();
        yield* off_1040A();
        yield* off_1043A();
        yield* sub_1A592();
        yield* sub_19E18();
        if (!flags.carry) {
            pc = 0x1C34B;
            break;
        }
        yield* sub_1C164();
    case 0x1C34B:
        memory16set(ds*16+0x95C4, 0x0000);
        yield* off_1043C();
        memory16set(ds*16+0xC0DF, sp);
    case 0x1C359:
        sp = memory16get(ds*16+0xC0DF);
        yield* off_1040A();
        yield* sub_1A592();
        yield* off_1043A();
        memory16set(ds*16+0xBDF2, 0x0003);
        r16[ax] = memory16get(ds*16+0xBDF2);
        yield* sub_1AECD();
        yield* off_10428();
    case 0x1C378:
        pc = 0x1C398;
        break;
    case 0x1C382:
        if (memory[ds*16+0xA85E] == 0xff) {
            pc = 0x1C395;
            break;
        }
        memory16set(ds*16+0xBDF2, 0x0000);
        r16[ax] = memory16get(ds*16+0xBDF2);
        yield* sub_1AECD();
    case 0x1C395:
        yield* sub_16B9B();
    case 0x1C398:
        if (memory[ds*16+0xA85E] == 0xff) {
            pc = 0x1C3AB;
            break;
        }
        memory16set(ds*16+0xBDF2, 0x0000);
        r16[ax] = memory16get(ds*16+0xBDF2);
        yield* sub_1AECD();
    case 0x1C3AB:
        yield* sub_16CD7();
        pc = 0x1C382;
        break;
        return;
    } while (1);
}
function* loc_1C3B0() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x6614, 0x0006);
        yield* sub_199C8();
    case 0x1C3B9:
        sp = memory16get(ds*16+0xC0DF);
        memory16set(ds*16+0x6610, 0x0006);
        memory16set(ds*16+0x6612, 0x0006);
        memory16set(ds*16+0x7E00, 0x0000);
        memory16set(ds*16+0x762D, 0x0000);
        memory16set(ds*16+0x762F, 0x0000);
        yield* sub_1A54A();
        push(cs);
        ds = pop();
        yield* sub_1A56B();
        yield* off_10404();
        yield* off_10406();
        yield* sub_1A45C();
        yield* sub_1C4E2();
        yield* off_10442();
        yield* off_10426();
        yield* off_1043C();
        yield* off_10448();
        r16[ax] = 0x0004;
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        r16[ax] = memory16get(ds*16+0x8BEC);
        r16[ax] -= 1;
        r16[ax] += r16[ax];
        si = 0x2f69;
        si += r16[ax];
        r16[ax] = memory16get(ds*16+si);
        memory16set(ds*16+0xBDF2, r16[ax]);
        yield* sub_1AECD();
        r16[ax] = 0x0000;
        yield* sub_1A257();
        yield* sub_1A5F0();
        yield* off_10426();
        yield* sub_19420();
        memory16set(ds*16+0x973C, 0x3245);
        memory16set(ds*16+0x973E, 0x5432);
    case 0x1C439:
        memory16set(ds*16+0x7E16, 0x0000);
        memory16set(ds*16+0x7E18, 0x0000);
    case 0x1C445:
        yield* sub_16B3B();
        if (memory16get(ds*16+0x7E18) != 0x0001) {
            pc = 0x1C467;
            break;
        }
        memory16set(ds*16+0x762F, 0x0000);
        yield* sub_1618F();
        yield* sub_19462();
        if (memory16get(ds*16+0x6614) != 0x0000) {
            pc = 0x1C465;
            break;
        }
    {yield* loc_19F12(); return; };
    case 0x1C465:
        pc = 0x1C439;
        break;
    case 0x1C467:
        yield* sub_19BAC();
        yield* sub_15F40();
        memory[ds*16+0x5B3E] = 0x00;
        yield* sub_169E3();
        yield* sub_168E4();
        yield* sub_17205();
        yield* sub_18351();
        yield* sub_18CBE();
        yield* sub_18D28();
        yield* sub_1705D();
        yield* off_1041E();
        yield* off_10424();
        yield* off_1043E();
        yield* off_1041C();
        yield* sub_19AF6();
        yield* off_10438();
        yield* sub_194C4();
        if (memory[ds*16+0xB888] != 0x10) {
            pc = 0x1C4B3;
            break;
        }
        yield* sub_19F8A();
        if (!flags.carry) {
            pc = 0x1C4B3;
            break;
        }
        _STOP_("goto loc_1C359");
    case 0x1C4B3:
        if (memory[ds*16+0xB888] != 0x01) {
            pc = 0x1C445;
            break;
        }
    {yield* loc_196F3(); return; };
        return;
    } while (1);
}
function* sub_1C4BD() {
    var cs = _seg001;
    r16[ax] = cs;
    r16[cx] = 0x0000;
    r16[dx] = memory16get(ds*16+0x2F67);
    yield* sub_1A65B();
}
function* sub_1C4CA() {
    yield* loc_1C1A2();
    r8[al] = memory[ds*16+0xB884];
}
function* sub_1C4E2() {
    r16[ax] = memory16get(ds*16+0x6614);
    r16[ax] += 1;
    if (r16s[ax] > signed16(0x0006))
        return;
    memory16set(ds*16+0x6614, r16[ax]);
    return;
}