function* sub_10000() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = ds;
        es = r16[ax];
        r16[cx] = 0x0008;
        r16[di] = 0x8e58;
        r8[al] = 0xff;
        rep_stosb_data_forward();
        r16[ax] = 0x1a00;
        interrupt(16);
        if (r8[al] != 0x1a) {
            pc = 0x10032;
            break;
        }
        if (r8[bl] >= r8[bh]) {
            pc = 0x1001D;
            break;
        }
        r8[bl] = r8[bh];
    case 0x1001D:
        if (r8[bl] < 0x0b) {
            pc = 0x1002C;
            break;
        }
        if (r8[bl] > 0x0c) {
            pc = 0x1002C;
            break;
        }
        memory[ds*16+0x8E5A] = 0x00;
    case 0x1002C:
        memory[ds*16+0x8E58] = 0x00;
        return;
    case 0x10032:
        memory[ds*16+0x8E59] = 0x00;
        yield* sub_10067();
        yield* sub_10089();
        yield* sub_10097();
        r16[dx] = 0x03b4;
        yield* sub_10101();
        if (_FIXME_) {
            pc = 0x1005C;
            break;
        }
        r8[dl] = 0xba;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x80;
        r8[ah] = r8[al];
        r16[cx] = 0x8000;
    case 0x10052:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x80;
        if (--r16[cx] && r8[al] == r8[ah]) {
            pc = 0x10052;
            break;
        }
        if (r8[al] == r8[ah]) {
            pc = 0x10061;
            break;
        }
        return;
    case 0x1005C:
        memory[ds*16+0x8E5C] = 0x00;
    case 0x10061:
        memory[ds*16+0x8E5D] = 0x00;
        return;
    } while (1);
}
function* sub_10067() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = 0x10;
        r8[ah] = 0x12;
        interrupt(16);
        if (r8[bl] == 0x10) {
            pc = 0x10083;
            break;
        }
        r8[ah] = 0x12;
        r8[bl] = 0x10;
        interrupt(16);
        if (r8[bl] >= 0x03)
            return;
        memory[ds*16+0x8E5E] = 0x00;
        return;
    case 0x10083:
        memory[ds*16+0x8E5A] = 0x00;
        return;
    } while (1);
}
function* sub_10089() {
    r16[dx] = 0x03d4;
    yield* sub_10101();
    if (_FIXME_)
        return;
    memory[ds*16+0x8E5B] = 0x00;
    return;
}
function* sub_10097() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0xb800;
        es = r16[bx];
        r16[di] = r16[di] ^ r16[di];
        push(memory16get(es*16+0x0));
        memory16set(es*16+0x0, 0x414a);
        interrupt(18);
        r16[ax] += 0x003f;
        r16[ax] &= 0xffc0;
        r16[ax] -= 0x0040;
        r8[cl] = 0x06;
        r16[ax] <<= r8[cl];
        es = r16[ax];
        r16[dx] = r16[ax];
        r16[ax] = 0x414a;
        r16[cx] = 0x8000;
    case 0x100C3:
        _repne_scasw();
        if (r16[ax] == 0) {
            pc = 0x100D6;
            break;
        }
        es = r16[bx];
        r16[di] = r16[di] ^ r16[di];
        memory16set(es*16+0x0, pop());
        memory[ds*16+0x8E58] = 0x00;
        return;
    case 0x100D6:
        r16[di] -= 0x0002;
        es = r16[bx];
        memory16set(es*16+0x0, 0x4849);
        es = r16[dx];
        if (memory16get(es*16+r16[di]) != 0x4849) {
            pc = 0x100F1;
            break;
        }
        memory16set(es*16+0x0, pop());
        return;
    case 0x100F1:
        es = r16[bx];
        memory16set(es*16+0x0, 0x414a);
        es = r16[dx];
        r16[di] += 0x0002;
        pc = 0x100C3;
        break;
        return;
    } while (1);
}
function* sub_10101() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = in8(r16[dx]);
        r8[ah] = r8[al];
        r8[al] = 0x66;
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0100;
    case 0x1010F:
        if (--r16[cx]) {
            pc = 0x1010F;
            break;
        }
        r8[al] = in8(r16[dx]);
        xchg8(al, ah);
        out8(r16[dx], r8[al]);
        if (r8[ah] == 0x66)
            return;
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1011C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x3d00;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x10126;
            break;
        }
    {yield* loc_15E04(); return; };
    case 0x10126:
        push(ds);
        r16[bx] = _seg003;
        ds = r16[bx];
        memory16set(ds*16+0x236C, r16[di]);
        memory16set(ds*16+0x236E, es);
        es = r16[bx];
        memory16set(ds*16+0x2370, r16[ax]);
        r8[ah] = 0x3f;
        r16[bx] = memory16get(ds*16+0x2370);
        r16[cx] = 0x0200;
        r16[dx] = 0x216c;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x1014C;
            break;
        }
    {yield* loc_15E04(); return; };
    case 0x1014C:
        r16[ax] = memory16get(ds*16+0x2177);
        memory16set(ds*16+0x0, r16[ax]);
        r16[ax] = memory16get(ds*16+0x2179);
        memory16set(ds*16+0x2, r16[ax]);
        r8[al] = memory[ds*16+0x216C];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] += 0x216e;
        memory16set(ds*16+0x216A, r16[ax]);
        yield* sub_1019A();
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds*16+0x2370);
        interrupt(33);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_10174() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = 0x216c;
        r16[cx] = 0x0100;
        rep_stosw_data_forward();
        r16[bx] = memory16get(ds*16+0x2370);
        r16[cx] = 0x0200;
        r16[dx] = 0x216c;
        r8[ah] = 0x3f;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x10195;
            break;
        }
    {yield* loc_15E04(); return; };
    case 0x10195:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_1019A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[di]);
        push(bp);
        r16[ax] = memory16get(ds*16+0x0);
        r16[ax] = r16[ax] | memory16get(ds*16+0x2);
        if (r16[ax] != 0) {
            pc = 0x101A9;
            break;
        }
        pc = 0x1022C;
        break;
    case 0x101A9:
        yield* sub_10230();
        yield* sub_102A8();
        r16[di] = 0x0fc4;
    case 0x101B2:
        push(r16[di]);
        yield* sub_102D4();
        r16[di] = r16[ax];
        if (r16s[ax] >= signed16(0x0100)) {
            pc = 0x101E0;
            break;
        }
        r16[di] = pop();
        push(es);
        push(r16[di]);
        les(di, ds, 0x236C);
        stosb_data_forward();
        memory16set(ds*16+0x236C, r16[di]);
        r16[di] = pop();
        es = pop();
        memory[ds*16+r16[di] + 4399] = r8[al];
        r16[di] += 1;
        r16[di] &= 0x0fff;
        flags.carry = memory16get(ds*16+0x0) < 0x0001;
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) - 0x0001);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) - 0x0000 - flags.carry);
        pc = 0x1021D;
        break;
    case 0x101E0:
        yield* sub_1034C();
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[di];
        r16[si] -= r16[ax];
        r16[si] -= 1;
        r16[si] &= 0x0fff;
        r16[cx] -= 0x00fd;
        flags.carry = memory16get(ds*16+0x0) < r16[cx];
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) - r16[cx]);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) - 0x0000 - flags.carry);
    case 0x101FC:
        r8[al] = memory[ds*16+r16[si] + 4399];
        memory[ds*16+r16[di] + 4399] = r8[al];
        r16[si] += 1;
        r16[di] += 1;
        r16[si] &= 0x0fff;
        r16[di] &= 0x0fff;
        push(es);
        push(r16[di]);
        les(di, ds, 0x236C);
        stosb_data_forward();
        memory16set(ds*16+0x236C, r16[di]);
        r16[di] = pop();
        es = pop();
        if (--r16[cx]) {
            pc = 0x101FC;
            break;
        }
    case 0x1021D:
        r16[ax] = memory16get(ds*16+0x2);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x1022C;
            break;
        }
        r16[ax] = r16[ax] | memory16get(ds*16+0x0);
        if (r16[ax] == 0) {
            pc = 0x1022C;
            break;
        }
        pc = 0x101B2;
        break;
    case 0x1022C:
        bp = pop();
        r16[di] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_10230() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[di]);
        r16[ax] = ds;
        es = r16[ax];
        flags.direction = false;
        r16[ax] = 0x0001;
        r16[cx] = 0x013a;
        r16[di] = 0x0004;
        rep_stosw_data_forward();
        r16[ax] = 0x04e6;
        r16[dx] = 0x0000;
        r16[cx] = 0x013a;
        r16[di] = 0x0c46;
        r16[bx] = 0x09d2;
    case 0x10251:
        stosw_data_forward();
        r16[ax] += 0x0002;
        memory16set(ds*16+r16[bx], r16[dx]);
        r16[bx] += 0x0002;
        r16[dx] += 0x0002;
        if (--r16[cx]) {
            pc = 0x10251;
            break;
        }
        r16[si] = 0x0000;
        r16[di] = 0x0002;
        r16[bx] = 0x0274;
        r16[cx] = 0x0139;
    case 0x1026B:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 4);
        memory16set(ds*16+r16[bx] + 4, r16[ax]);
        memory16set(ds*16+r16[bx] + 3142, r16[si]);
        memory16set(ds*16+r16[si] + 1260, r16[bx]);
        memory16set(ds*16+r16[di] + 1260, r16[bx]);
        r16[si] += 0x0004;
        r16[di] += 0x0004;
        r16[bx] += 0x0002;
        if (--r16[cx]) {
            pc = 0x1026B;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+0x112C, r16[ax]);
        memory16set(ds*16+0x112C, r16[ax]);
        memory[ds*16+0x112E] = r8[al];
        memory[ds*16+0x112E] = r8[al];
        memory16set(ds*16+0x4EA, 0xffff);
        memory16set(ds*16+0x9D0, r16[ax]);
        r16[di] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_102A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r16[di] = ds;
        es = r16[di];
        r16[di] = 0x112f;
        r8[al] = 0x00;
        r16[bx] = 0x000d;
    case 0x102B5:
        r16[cx] = r16[bx];
        rep_stosb_data_forward();
        r8[al] += 1;
        if (r8[al] != 0) {
            pc = 0x102B5;
            break;
        }
    case 0x102BD:
        stosb_data_forward();
        r8[al] += 1;
        if (r8[al] != 0) {
            pc = 0x102BD;
            break;
        }
    case 0x102C2:
        r8[al] -= 1;
        stosb_data_forward();
        if (r8[al] != 0) {
            pc = 0x102C2;
            break;
        }
        r16[cx] = 0x0080;
        rep_stosb_data_forward();
        r16[cx] = 0x0080;
        r8[al] = 0x20;
        rep_stosb_data_forward();
        return;
    } while (1);
}
function* sub_102D4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = memory16get(ds*16+0x112A);
        r16[dx] = memory16get(ds*16+0x112C);
        r8[cl] = memory[ds*16+0x112E];
        r16[cx] &= 0x00ff;
        pc = 0x102F4;
        break;
    case 0x102E6:
        r16[si] >>= 1;
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        r16[si] = r16[si] + 0x0000 + flags.carry;
        r16[si] <<= 1;
        r16[si] = memory16get(ds*16+r16[si] + 3142);
        r16[cx] -= 1;
    case 0x102F4:
        if (r16[cx] == 0) {
            pc = 0x10312;
            break;
        }
    case 0x102F6:
        if (r16[si] < 0x04e6) {
            pc = 0x102E6;
            break;
        }
        memory16set(ds*16+0x112C, r16[dx]);
        memory[ds*16+0x112E] = r8[cl];
        r16[si] -= 0x04e6;
        r16[dx] = r16[si];
        yield* sub_10373();
        r16[ax] = r16[dx];
        r16[ax] >>= 1;
        return;
    case 0x10312:
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x216A);
        if (r16s[si] < signed16(0x236c)) {
            pc = 0x10323;
            break;
        }
        yield* sub_10174();
        r16[si] = 0x216c;
    case 0x10323:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x216A, r16[si]);
        r16[si] = pop();
        r8[dh] = r8[al];
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x216A);
        if (r16s[si] < signed16(0x236c)) {
            pc = 0x1033E;
            break;
        }
        yield* sub_10174();
        r16[si] = 0x216c;
    case 0x1033E:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x216A, r16[si]);
        r16[si] = pop();
        r8[dl] = r8[al];
        r8[cl] = 0x10;
        pc = 0x102F6;
        break;
        return;
    } while (1);
}
function* sub_1034C() {
    yield* sub_103DD();
    r16[si] = r16[ax];
    r8[dl] = memory[ds*16+r16[si] + 9074];
    r8[dh] = 0x00;
    r8[cl] = 0x06;
    r16[dx] <<= r8[cl];
    push(r16[dx]);
    r8[cl] = memory[ds*16+r16[si] + 9330];
    r8[ch] = 0x00;
    r16[cx] -= 0x0002;
    yield* sub_103FD();
    r16[ax] |= r16[si];
    rol16(ax, r8[cl]);
    r16[ax] &= 0x003f;
    r16[dx] = pop();
    r16[ax] += r16[dx];
}
function* sub_10373() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x4E8) < 0x8000) {
            pc = 0x1037E;
            break;
        }
        yield* sub_10423();
    case 0x1037E:
        r16[si] = memory16get(ds*16+r16[si] + 2514);
    case 0x10382:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] += 1;
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        lea(di, ds, r16[si] + 2);
        if (r16[ax] > memory16get(ds*16+r16[di] + 4)) {
            pc = 0x10396;
            break;
        }
        pc = 0x103D2;
        break;
    case 0x10396:
        r16[di] += 1;
        r16[di] += 1;
        if (r16[ax] > memory16get(ds*16+r16[di] + 4)) {
            pc = 0x10396;
            break;
        }
        r16[di] -= 1;
        r16[di] -= 1;
        xchgr16(ax, ds*16+r16[di] + 4);
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 3142);
        memory16set(ds*16+r16[bx] + 1260, r16[di]);
        if (r16[bx] >= 0x04e6) {
            pc = 0x103BA;
            break;
        }
        memory16set(ds*16+r16[bx] + 1262, r16[di]);
    case 0x103BA:
        xchgr16(bx, ds*16+r16[di] + 3142);
        memory16set(ds*16+r16[bx] + 1260, r16[si]);
        if (r16[bx] >= 0x04e6) {
            pc = 0x103CC;
            break;
        }
        memory16set(ds*16+r16[bx] + 1262, r16[si]);
    case 0x103CC:
        memory16set(ds*16+r16[si] + 3142, r16[bx]);
        r16[si] = r16[di];
    case 0x103D2:
        r16[si] = memory16get(ds*16+r16[si] + 1260);
        r16[si] |= r16[si];
        if (r16[si] == 0)
            return;
        pc = 0x10382;
        break;
        return;
    } while (1);
}
function* sub_103DD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds*16+0x112C);
        if (memorys[ds*16+0x112E] > signed8(0x08)) {
            pc = 0x103EB;
            break;
        }
        yield* sub_104C9();
    case 0x103EB:
        xchg8(dl, dh);
        r16[ax] = r16[dx];
        r8[dl] = r8[dl] ^ r8[dl];
        memory16set(ds*16+0x112C, r16[dx]);
        memory[ds*16+0x112E] -= 0x08;
        r8[ah] = r8[ah] ^ r8[ah];
        return;
    } while (1);
}
function* sub_103FD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[dx] = memory16get(ds*16+0x112C);
        if (memorys[ds*16+0x112E] > signed8(0x08)) {
            pc = 0x1040C;
            break;
        }
        yield* sub_104C9();
    case 0x1040C:
        r16[cx] = pop();
        r16[ax] = r16[dx];
        r16[dx] <<= r8[cl];
        memory16set(ds*16+0x112C, r16[dx]);
        memory[ds*16+0x112E] -= r8[cl];
        r16[dx] = 0xffff;
        r16[dx] >>= r8[cl];
        r16[dx] = (~r16[dx]);
        r16[ax] &= r16[dx];
        return;
    } while (1);
}
function* sub_10423() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[ax] = ds;
        es = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[si];
    case 0x1042C:
        if (memory16get(ds*16+r16[si] + 3142) < 0x04e6) {
            pc = 0x10449;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] += 1;
        r16[ax] >>= 1;
        memory16set(ds*16+r16[di] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 3142);
        memory16set(ds*16+r16[di] + 3142, r16[ax]);
        r16[di] += 1;
        r16[di] += 1;
    case 0x10449:
        r16[si] += 1;
        r16[si] += 1;
        if (r16[si] < 0x04e6) {
            pc = 0x1042C;
            break;
        }
        r16[si] = r16[si] ^ r16[si];
        r16[di] = 0x0274;
    case 0x10456:
        r16[bx] = r16[si];
        r16[bx] += 1;
        r16[bx] += 1;
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[bx] + 4);
        memory16set(ds*16+r16[di] + 4, r16[ax]);
        r16[bx] = r16[di];
    case 0x10468:
        r16[bx] -= 1;
        r16[bx] -= 1;
        if (r16[ax] < memory16get(ds*16+r16[bx] + 4)) {
            pc = 0x10468;
            break;
        }
        r16[bx] += 1;
        r16[bx] += 1;
        r16[cx] = r16[di];
        r16[cx] -= r16[bx];
        r16[cx] >>= 1;
        flags.direction = true;
        push(r16[cx]);
        push(r16[si]);
        push(r16[di]);
        lea(si, ds, r16[di] + 4);
        r16[di] = r16[si];
        r16[si] -= 1;
        r16[si] -= 1;
        rep_movsw_data_data_forward();
        memory16set(ds*16+r16[bx] + 4, r16[ax]);
        r16[di] = pop();
        r16[si] = pop();
        r16[cx] = pop();
        push(r16[si]);
        push(r16[di]);
        lea(si, ds, r16[di] + 3142);
        r16[di] = r16[si];
        r16[si] -= 1;
        r16[si] -= 1;
        rep_movsw_data_data_forward();
        r16[di] = pop();
        r16[si] = pop();
        memory16set(ds*16+r16[bx] + 3142, r16[si]);
        r16[si] += 0x0004;
        r16[di] += 0x0002;
        if (r16[di] < 0x04e6) {
            pc = 0x10456;
            break;
        }
        r16[si] = r16[si] ^ r16[si];
    case 0x104AD:
        r16[di] = memory16get(ds*16+r16[si] + 3142);
        memory16set(ds*16+r16[di] + 1260, r16[si]);
        if (r16[di] >= 0x04e6) {
            pc = 0x104BF;
            break;
        }
        memory16set(ds*16+r16[di] + 1262, r16[si]);
    case 0x104BF:
        r16[si] += 1;
        r16[si] += 1;
        if (r16[si] < 0x04e6) {
            pc = 0x104AD;
            break;
        }
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_104C9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x216A);
        if (r16s[si] < signed16(0x236c)) {
            pc = 0x104DA;
            break;
        }
        yield* sub_10174();
        r16[si] = 0x216c;
    case 0x104DA:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x216A, r16[si]);
        r16[si] = pop();
        r8[cl] = 0x08;
        r8[cl] = r8[cl] - memory[ds*16+0x112E];
        r16[ax] <<= r8[cl];
        r16[dx] |= r16[ax];
        memory[ds*16+0x112E] += 0x08;
        return;
    } while (1);
}
function* start() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = dseg;
        ds = r16[ax];
        es = r16[ax];
        flags.direction = false;
        memory16set(ds*16+0x8E6A, sp);
        yield* sub_105A3();
        memory16set(ds*16+0x8E6C, 0x0000);
        yield* sub_107ED();
        memory16set(ds*16+0x8E88, 0x0000);
        memory16set(ds*16+0x8E8A, 0x0000);
        push(es);
        r16[ax] = r16[ax] ^ r16[ax];
        es = r16[ax];
        flags.interrupt = false;
        flags.interrupt = true;
        es = pop();
        r8[ah] = 0x22;
        r8[al] = 0x16;
        interrupt(128);
        yield* sub_15E8A();
        memory16set(ds*16+0x3048, 0x0000);
    case 0x1053B:
        yield* sub_15E5E();
        yield* sub_15C8B();
        r16[ax] = ds;
        es = r16[ax];
        yield* sub_13C75();
    case 0x1054F:
        if (memory16get(ds*16+0x3044) != 0x0004) {
            pc = 0x10585;
            break;
        }
        r16[dx] = 0x03b8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03b4;
        r16[si] = 0x2ee0;
        r16[cx] = 0x0009;
    case 0x10565:
        lodsw_data_forward();
        out16(r16[dx], r16[ax]);
        if (--r16[cx]) {
            pc = 0x10565;
            break;
        }
        push(es);
        r16[ax] = 0xb000;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x4000;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        es = pop();
        r16[dx] = 0x03b8;
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03bf;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
    case 0x10585:
        r8[ah] = 0x01;
        interrupt(128);
        yield* sub_15EC3();
        yield* sub_15E7A();
        r16[ax] = 0x0003;
        if (memory16get(ds*16+0x3044) != 0x0004) {
            pc = 0x1059C;
            break;
        }
        r16[ax] = 0x0007;
    case 0x1059C:
        interrupt(16);
        r16[ax] = 0x4c00;
        interrupt(33);
        return;
    } while (1);
}
function* sub_105A3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x8F57] = 0x00;
        yield* sub_10000();
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = 0x0004;
        if (memory[ds*16+0x8E59] != 0x00) {
            pc = 0x105DA;
            break;
        }
        r16[ax] = 0x0003;
        if (memory[ds*16+0x8E5A] != 0x00) {
            pc = 0x105DA;
            break;
        }
        r16[ax] = 0x0002;
        if (memory[ds*16+0x8E58] != 0x00) {
            pc = 0x105DA;
            break;
        }
        r16[ax] = 0x0000;
        if (memory[ds*16+0x8E5D] != 0x00) {
            pc = 0x105DA;
            break;
        }
        r16[ax] = 0x0001;
    case 0x105DA:
        memory16set(ds*16+0x3044, r16[ax]);
        r8[ah] = 0x0f;
        interrupt(16);
        memory[ds*16+0x2EF3] = r8[bh];
        memory[ds*16+0x2EF4] = r8[al];
        memory[ds*16+0x2EF5] = r8[ah];
        r8[ah] = 0x01;
        r8[ch] = 0x20;
        r8[cl] = 0x20;
        interrupt(16);
    case 0x105F4:
        r16[ax] = 0x0600;
        r8[bh] = r8[bh] ^ r8[bh];
        r16[cx] = r16[cx] ^ r16[cx];
        r8[dl] = memory[ds*16+0x2EF5];
        r8[dl] -= 1;
        r8[dh] = 0x18;
        interrupt(16);
    case 0x10605:
        yield* sub_106FE();
    case 0x10608:
        r8[ah] = r8[ah] ^ r8[ah];
        interrupt(22);
        if (r8[ah] == 0x1c) {
            pc = 0x10657;
            break;
        }
        if (r8[ah] == 0x41) {
            pc = 0x10652;
            break;
        }
        if (r8[ah] == 0x39) {
            pc = 0x10631;
            break;
        }
        if (r8[ah] == 0x50) {
            pc = 0x10631;
            break;
        }
        if (r8[ah] == 0x4d) {
            pc = 0x10631;
            break;
        }
        if (r8[ah] == 0x48) {
            pc = 0x10644;
            break;
        }
        if (r8[ah] == 0x4b) {
            pc = 0x10644;
            break;
        }
        pc = 0x10608;
        break;
    case 0x10631:
        memory16set(ds*16+0x3044, memory16get(ds*16+0x3044) + 1);
        if (memory16gets(ds*16+0x3044) < signed16(0x0006)) {
            pc = 0x10605;
            break;
        }
        memory16set(ds*16+0x3044, 0x0000);
        pc = 0x10605;
        break;
    case 0x10644:
        memory16set(ds*16+0x3044, memory16get(ds*16+0x3044) - 1);
        if (memory16gets(ds*16+0x3044) >= 0) {
            pc = 0x10605;
            break;
        }
        memory16set(ds*16+0x3044, 0x0005);
        pc = 0x10605;
        break;
    case 0x10652:
        memory[ds*16+0x8F57] = 0xff;
    case 0x10657:
        if (memory16get(ds*16+0x3044) != 0x0005) {
            pc = 0x10663;
            break;
        }
        yield* sub_1066E();
        pc = 0x105F4;
        break;
    case 0x10663:
        r16[ax] = memory16get(ds*16+0x3044);
        r16[bx] = 0x2ef8;
        _xlat();
        memory16set(ds*16+0x3044, r16[ax]);
        return;
    } while (1);
}
function* sub_1066E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0600;
        r8[bh] = r8[bh] ^ r8[bh];
        r16[cx] = r16[cx] ^ r16[cx];
        r8[dl] = memory[ds*16+0x2EF5];
        r8[dl] -= 1;
        r8[dh] = 0x18;
        interrupt(16);
        r16[si] = 0x2f9a;
        r16[cx] = 0x0006;
    case 0x10685:
        push(r16[cx]);
        r8[dl] = r8[dl] ^ r8[dl];
        lodsb_data_forward();
        r8[dh] = r8[al];
        r8[bh] = memory[ds*16+0x2EF3];
        r8[ah] = 0x02;
        interrupt(16);
    case 0x10693:
        r16[ax] = 0x0920;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x07;
        r16[cx] = 0x0001;
        interrupt(16);
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x106B2;
            break;
        }
        r8[ah] = 0x0e;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x07;
        interrupt(16);
        pc = 0x10693;
        break;
    case 0x106B2:
        r8[ah] = r8[ah] ^ r8[ah];
        interrupt(22);
        memory[ds*16+r16[si]] = r8[ah];
        r16[si] += 1;
        r8[ah] = r8[ah] ^ 0x80;
        memory[ds*16+r16[si]] = r8[ah];
        r16[si] += 1;
        if (r8s[al] >= signed8(0x20)) {
            pc = 0x106E0;
            break;
        }
        push(r16[ax]);
        r16[ax] = 0x0920;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x07;
        r16[cx] = 0x0001;
        interrupt(16);
        r16[ax] = 0x0e5e;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x0f;
        interrupt(16);
        r16[ax] = pop();
        r8[al] += 0x41;
    case 0x106E0:
        push(r16[ax]);
        r16[ax] = 0x0920;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x07;
        r16[cx] = 0x0001;
        interrupt(16);
        r16[ax] = pop();
        r8[ah] = 0x0e;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[bl] = 0x0f;
        interrupt(16);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x10685;
            break;
        }
        return;
    } while (1);
}
function* sub_106FE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x2efd;
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x10703:
        r8[bl] = 0x07;
        if (r16[cx] != memory16get(ds*16+0x3044)) {
            pc = 0x10716;
            break;
        }
        r8[bl] = 0x1f;
        if (memory[ds*16+0x2EF4] != 0x07) {
            pc = 0x10716;
            break;
        }
        r8[bl] = 0xf0;
    case 0x10716:
        memory[ds*16+0x2EF7] = r8[bl];
        lodsb_data_forward();
        if (!(r8[al] & r8[al]))
            return;
        r8[al] = r8[al] - memory[ds*16+0x2EF5];
        r8[al] = -r8[al];
        r8[al] >>= 1;
        memory[ds*16+0x2EF2] = r8[al];
        lodsb_data_forward();
        memory[ds*16+0x2EF6] = r8[al];
        push(r16[cx]);
    case 0x1072F:
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1075C;
            break;
        }
        r8[ah] = 0x02;
        r8[bh] = memory[ds*16+0x2EF3];
        r8[dh] = memory[ds*16+0x2EF6];
        r8[dl] = memory[ds*16+0x2EF2];
        interrupt(16);
        memory[ds*16+0x2EF2] += 1;
        r8[al] = memory[ds*16+r16[si] - 1];
        r8[ah] = 0x09;
        r8[bl] = memory[ds*16+0x2EF7];
        r8[bh] = memory[ds*16+0x2EF3];
        r16[cx] = 0x0001;
        interrupt(16);
        pc = 0x1072F;
        break;
    case 0x1075C:
        r16[cx] = pop();
        r16[cx] += 1;
        pc = 0x10703;
        break;
        return;
    } while (1);
}
function* sub_10762() {
    memory16set(ds*16+r16[si], 0x0000);
    memory16set(ds*16+r16[si] + 10, r16[si]);
    memory16set(ds*16+r16[si] + 8, r16[si]);
    memory16set(ds*16+r16[si] + 2, 0x0761);
    memory16set(ds*16+r16[si] + 4, 0x0761);
    memory16set(ds*16+r16[si] + 6, 0x0761);
}
function* sub_1077C() {
    push(r16[bx]);
    r16[bx] = memory16get(ds*16+r16[di] + 10);
    memory16set(ds*16+r16[di] + 10, r16[si]);
    memory16set(ds*16+r16[si] + 10, r16[bx]);
    memory16set(ds*16+r16[si] + 8, r16[di]);
    memory16set(ds*16+r16[bx] + 8, r16[si]);
    r16[bx] = pop();
}
function* sub_1078E() {
    push(r16[bx]);
    r16[bx] = memory16get(ds*16+r16[di] + 8);
    memory16set(ds*16+r16[di] + 8, r16[si]);
    memory16set(ds*16+r16[si] + 8, r16[bx]);
    memory16set(ds*16+r16[si] + 10, r16[di]);
    memory16set(ds*16+r16[bx] + 10, r16[si]);
    r16[bx] = pop();
}
function* sub_107A0() {
    push(r16[di]);
    push(r16[bx]);
    r16[di] = memory16get(ds*16+r16[si] + 8);
    r16[bx] = memory16get(ds*16+r16[si] + 10);
    memory16set(ds*16+r16[di] + 10, r16[bx]);
    memory16set(ds*16+r16[bx] + 8, r16[di]);
    r16[bx] = memory16get(ds*16+0x8E7C);
    memory16set(ds*16+r16[si] + 8, r16[bx]);
    memory16set(ds*16+0x8E7C, r16[si]);
    memory16set(ds*16+r16[si], 0x0000);
    r16[bx] = pop();
    r16[di] = pop();
}
function* sub_107C0() {
    memory16set(ds*16+r16[si], 0x0004);
    memory16set(ds*16+r16[si] + 2, 0x0f2b);
    memory16set(ds*16+r16[si] + 4, 0x0761);
    memory16set(ds*16+r16[si] + 6, 0x0761);
    memory[ds*16+r16[si] + 38] = 0x00;
    memory[ds*16+r16[si] + 74] = 0x00;
}
function* sub_107DC() {
    push(r16[di]);
    push(r16[bx]);
    r16[di] = memory16get(ds*16+r16[si] + 8);
    r16[bx] = memory16get(ds*16+r16[si] + 10);
    memory16set(ds*16+r16[di] + 10, r16[bx]);
    memory16set(ds*16+r16[bx] + 8, r16[di]);
    r16[bx] = pop();
    r16[di] = pop();
}
function* sub_107ED() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    yield* indirectCall(_seg000, memory16get(_seg000*16+bp+0x7FB));
}
function* sub_1080F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3EF();
}
function* sub_10831() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F492();
}
function* sub_10853() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F57C();
}
function* sub_10875() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F585();
}
function* sub_10897() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1FEA1();
}
function* sub_108B9() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1FF41();
}
function* sub_108DB() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* loc_1FF46();
}
function* sub_108FD() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* loc_1FF4F();
}
function* sub_1091F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_203DA();
}
function* sub_10941() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1EBD0();
}
function* sub_10963() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* loc_1EBD7();
}
function* sub_10985() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20482();
}
function* sub_109A7() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20568();
}
function* sub_109C9() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_2058D();
}
function* sub_109EB() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_2058D();
}
function* sub_10A0D() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_205A9();
}
function* sub_10A2F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_205AE();
    yield* _sync();
}
function* sub_10A51() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_205AE();
    yield* _sync();
}
function* sub_10A73() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_205ED();
}
function* sub_10A95() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20653();
}
function* sub_10AD9() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20973();
}
function* sub_10AFB() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_2098C();
}
function* loc_10B1D() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_209A6();
}
function* sub_10B3F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_209E9();
}
function* sub_10B61() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20A2E();
}
function* sub_10B83() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20A39();
}
function* sub_10BA5() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20AD0();
}
function* sub_10BC7() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20B5B();
}
function* sub_10BE9() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20B8A();
}
function* sub_10C0B() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20BE5();
}
function* sub_10C2D() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20C5E();
}
function* sub_10C4F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20C7B();
}
function* sub_10C71() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20D18();
}
function* sub_10C93() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20D8A();
}
function* sub_10CB5() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20F54();
}
function* sub_10CD7() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_21090();
}
function* sub_10CF9() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_21132();
}
function* sub_10D1B() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_211CC();
}
function* sub_10D3D() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_2120E();
}
function* sub_10D5F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3C7();
}
function* sub_10D81() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3D7();
}
function* sub_10DA3() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* nullsub_1();
}
function* sub_10DC5() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F325();
}
function* sub_10DE7() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3A7();
}
function* sub_10E09() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3AE();
}
function* sub_10E2B() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F3B5();
}
function* sub_10E4D() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_20854();
}
function* sub_10E6F() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_208DC();
}
function* sub_10E91() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_208F9();
}
function* sub_10EB3() {
    bp = memory16get(ds*16+0x3044);
    bp <<= 1;
    bp <<= 1;
    assert(bp == 12);
    yield* sub_1F2FF();
}
function* sub_10ED5() {
    yield* sub_1421C();
}
function* sub_10ED9() {
    yield* sub_14191();
}
function* sub_10EDD() {
    yield* sub_11CCC();
}
function* sub_10EE1() {
    yield* sub_13A36();
}
function* sub_10EE5() {
    yield* sub_15835();
}
function* sub_10EE9() {
    yield* sub_1561C();
}
function* loc_10EED() {
    yield* sub_15829();
}
function* sub_10EF1() {
    yield* sub_160A5();
}
function* sub_10EF5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(r16[cx]);
        push(r16[si]);
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
        r16[cx] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x10F0E;
            break;
        }
        r16[cx] = _seg008;
        r16[si] -= 1;
    case 0x10F0E:
        es = r16[cx];
        r16[ax] = r16[ax] - memory16get(es*16+r16[si]);
        r16[bx] = r16[bx] - memory16get(es*16+r16[si] + 2);
        r16[ax] <<= 1;
        r16[bx] <<= 1;
        r16[ax] = r16[ax] + memory16get(es*16+r16[si] + 4);
        r16[bx] = r16[bx] + memory16get(es*16+r16[si] + 6);
        sar16(ax, 1);
        sar16(bx, 1);
        r16[si] = pop();
        r16[cx] = pop();
        es = pop();
        return;
    } while (1);
}
function* sub_10F2B() {
    yield* sub_107A0();
}
function* sub_10F2F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0xFCFA);
        if (r16s[ax] < memory16gets(ds*16+0xFCE2)) {
            pc = 0x10F57;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCF2);
        if (r16s[ax] > memory16gets(ds*16+0xFCEA)) {
            pc = 0x10F57;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCFE);
        if (r16s[ax] < memory16gets(ds*16+0xFCE6)) {
            pc = 0x10F57;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCF6);
        if (r16s[ax] > memory16gets(ds*16+0xFCEE)) {
            pc = 0x10F57;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    case 0x10F57:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    } while (1);
}
function* sub_10F5A() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 3948));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(cs, pop());
}
function* sub_10F78() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 3978));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(_seg000, pop());
}
function* sub_10F96() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 4008));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(cs, pop());
}
function* sub_10FB4() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 4038));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(cs, pop());
}
function* sub_10FD2() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 4068));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(cs, pop());
}
function* sub_10FF0() {
    var cs = _seg000;
    memory16set(ds*16+0x8E74, r16[bx]);
    r16[bx] = memory16get(ds*16+0x991C);
    r16[bx] <<= 1;
    push(memory16get(cs*16+r16[bx] + 4098));
    r16[bx] = memory16get(ds*16+0x8E74);
    yield* indirectCall(_seg000, pop());
}
function* sub_1100E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = 0x9138;
        r16[cx] = 0x0004;
    case 0x11014:
        if (memory16get(ds*16+bp + 0) == 0x0000)
            {
            flags.zero = true;
            return;
        }
        bp += 0x0004;
        if (--r16[cx]) {
            pc = 0x11014;
            break;
        }
        r16[cx] -= 1;
        flags.zero = false;
        return;
    } while (1);
}
function* sub_11022() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E7C) == 0x0000) {
            pc = 0x11041;
            break;
        }
        r16[si] = memory16get(ds*16+0x8E7C);
        push(memory16get(ds*16+r16[si] + 8));
        memory16set(ds*16+0x8E7C, pop());
    case 0x11034:
        memory[ds*16+r16[si] + 38] = 0x00;
        memory[ds*16+r16[si] + 74] = 0x00;
        memory[ds*16+r16[si] + 75] = 0x00;
        return;
    case 0x11041:
        r16[si] = 0x9096;
    case 0x11044:
        r16[si] = memory16get(ds*16+r16[si] + 10);
        if (memory16get(ds*16+r16[si]) == 0x0004) {
            pc = 0x1106D;
            break;
        }
        if (memory16get(ds*16+r16[si]) == 0x000c) {
            pc = 0x1106D;
            break;
        }
        if (memory16get(ds*16+r16[si]) == 0x0010) {
            pc = 0x1106D;
            break;
        }
        if (memory16get(ds*16+r16[si]) != 0x0000) {
            pc = 0x11044;
            break;
        }
        r16[si] = memory16get(ds*16+0x90A0);
        if (memory16get(ds*16+r16[si]) != 0x0000) {
            pc = 0x1106D;
            break;
        }
        r16[si] = memory16get(ds*16+0x90EC);
        if (memory16get(ds*16+r16[si]) == 0x0000) {
            pc = 0x11072;
            break;
        }
    case 0x1106D:
        yield* sub_107DC();
        pc = 0x11034;
        break;
    case 0x11072:
        r16[si] = memory16get(ds*16+0x9054);
    case 0x11076:
        if (memory16gets(ds*16+r16[si]) >= signed16(0x00c8)) {
            pc = 0x1106D;
            break;
        }
        if (memory16get(ds*16+r16[si]) == 0x0004) {
            pc = 0x1106D;
            break;
        }
        r16[si] = memory16get(ds*16+r16[si] + 10);
        if (memory16get(ds*16+r16[si]) != 0x0000) {
            pc = 0x11076;
            break;
        }
        r16[si] = memory16get(ds*16+0x9054);
        pc = 0x1106D;
        break;
        return;
    } while (1);
}
function* loc_1109A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141A1();
        r16[cx] = 0x0005;
    case 0x110A0:
        r16[di] = memory16get(ds*16+0x9054);
    case 0x110A4:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x110D7;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x00b8) {
            pc = 0x110D0;
            break;
        }
        if (memory16gets(ds*16+r16[di] + 44) < 0 /*CHECK*/) {
            pc = 0x110D0;
            break;
        }
        if (memory16gets(ds*16+r16[di] + 40) >= signed16(0x0140)) {
            pc = 0x110D0;
            break;
        }
        if (memory16gets(ds*16+r16[di] + 46) < 0 /*CHECK*/) {
            pc = 0x110D0;
            break;
        }
        if (memory16gets(ds*16+r16[di] + 42) >= signed16(0x00c0)) {
            pc = 0x110D0;
            break;
        }
        r16[ax] -= 1;
        if (r16s[ax] >= 0) {
            pc = 0x110D0;
            break;
        }
        r16[cx] = pop();
        r16[ax] = pop();
        r16[si] = pop();
        return;
    case 0x110D0:
        r16[si] = r16[di];
        yield* sub_11689();
        pc = 0x110A4;
        break;
    case 0x110D7:
        if (--r16[cx]) {
            pc = 0x110A0;
            break;
        }
        r16[cx] = pop();
        r16[ax] = pop();
        r16[si] = pop();
        r16[di] = 0x904a;
        return;
        _STOP_("db 18h, 48h, 1, 0, 0B4h, 48h, 1, 0, 5Ah, 4...");
        _STOP_("db 48h, 1, 3 dup(0), 0E2h, 41h, 0E0h, 10h,...");
        _STOP_("db 6Ah, 4Ah, 1, 0, 0D4h, 4Ah, 1, 0, 6Ah, 4...");
        _STOP_("db 0E2h, 41h, 0F6h, 10h, 0E0h, 0A0h, 1, 0,...");
        _STOP_("db 0, 40h, 0A2h, 1, 0, 0F0h, 0A2h, 1, 3 du...");
        _STOP_("db 0Ch, 11h, 8Eh, 5Ah, 1, 0, 3Eh, 5Bh, 1, ...");
        _STOP_("db 1, 0, 9Eh, 5Ch, 1, 0, 4Eh, 5Dh, 1, 0, 0...");
        _STOP_("db 0, 0AEh, 5Eh, 1, 0, 5Eh, 5Fh, 1, 3 dup(...");
        _STOP_("db 22h, 11h, 0BEh, 9Ah, 2, 0, 4Eh, 9Dh, 2,...");
        _STOP_("db 41h, 48h, 11h, 58h, 0A6h, 2 dup(0), 0Eh...");
        _STOP_("db 0B4h, 6Ch, 1, 0, 5Ah, 6Dh, 1, 2 dup(0),...");
        _STOP_("db 0E2h, 41h, 5Ah, 11h, 0E4h, 8Ch, 1, 0, 4...");
        _STOP_("db 0F4h, 8Dh, 1, 0, 0A4h, 8Eh, 1, 0, 54h, ...");
        _STOP_("db 90h, 1, 3 dup(0), 0E2h, 41h, 70h, 11h, ...");
        _STOP_("db 0, 56h, 6Fh, 1, 0, 6, 70h, 1, 0, 0B6h, ...");
        _STOP_("db 71h, 1, 0, 16h, 72h, 1, 0, 0C6h, 72h, 1...");
        _STOP_("db 1, 3 dup(0), 0E2h, 41h, 8Eh, 11h, 78h, ...");
        _STOP_("db 0Eh, 1, 0, 0C4h, 0Eh, 1, 0, 6Ah, 0Fh, 1...");
        _STOP_("db 1, 0, 0B6h, 10h, 1, 0, 5Ch, 11h, 1, 0, ...");
        _STOP_("db 0A8h, 12h, 1, 0, 4Eh, 13h, 1, 0, 0F4h, ...");
        _STOP_("db 14h, 1, 0, 40h, 15h, 1, 0, 0E6h, 15h, 1...");
        _STOP_("db 41h, 0B4h, 11h, 34h, 41h, 1, 0, 0B2h, 4...");
        _STOP_("db 42h, 1, 0, 0AEh, 42h, 1, 0, 2Ch, 43h, 1...");
        _STOP_("db 1, 0, 28h, 44h, 1, 0, 0A6h, 44h, 1, 0, ...");
        _STOP_("db 0, 0A2h, 45h, 1, 0, 20h, 46h, 1, 0, 9Eh...");
        _STOP_("db 1Ch, 47h, 1, 0, 9Ah, 47h, 1, 3 dup(0), ...");
        _STOP_("db 11h, 28h, 0, 1, 0, 60h, 0, 1, 0, 0E8h, ...");
        _STOP_("db 2 dup(1), 0, 48h, 2, 1, 0, 0F8h, 2, 1, ...");
        _STOP_("db 41h, 8Ch, 16h, 1, 0, 7Ch, 19h, 1, 0, 4C...");
        _STOP_("db 6Ch, 23h, 1, 0, 0ECh, 27h, 1, 3 dup(0),...");
        _STOP_("db 16h, 1, 0, 4, 18h, 1, 0, 7Ch, 19h, 1, 0...");
        _STOP_("db 1, 0, 4Ch, 1Eh, 1, 0, 0DCh, 20h, 1, 0, ...");
        _STOP_("db 0, 0FCh, 25h, 1, 0, 0ECh, 27h, 2 dup(0)...");
        _STOP_("db 2, 0, 0CEh, 0A3h, 1, 0, 6, 0A4h, 1, 0, ...");
        _STOP_("db 0, 0Ch, 0A5h, 1, 0, 0A8h, 0A5h, 1, 3 du...");
        _STOP_("db 0CCh, 0A6h, 1, 0, 48h, 0A9h, 1, 3 dup(0...");
        _STOP_("db 0A4h, 12h, 0D8h, 44h, 0B0h, 46h, 8, 49h...");
        _STOP_("db 47h, 0B6h, 49h, 0C4h, 45h, 0DCh, 47h, 7...");
        _STOP_("db 46h, 6Ah, 48h, 22h, 4Bh, 0D6h, 86h, 1, ...");
        _STOP_("db 1, 0, 4, 88h, 1, 0, 96h, 88h, 1, 0, 26h...");
        _STOP_("db 26h, 86h, 1, 0, 0D6h, 86h, 1, 0, 86h, 8...");
        _STOP_("db 88h, 1, 0, 96h, 88h, 1, 3 dup(0), 0E2h,...");
        _STOP_("db 4Ch, 93h, 2 dup(0), 0FCh, 93h, 1, 0, 0A...");
        _STOP_("db 3Eh");
        _STOP_("db 95h, 1, 0, 0DAh, 95h, 1, 3 dup(0), 0E2h...");
        _STOP_("db 12h, 4Ch, 93h, 1, 0, 0FCh, 93h, 1, 0, 0...");
        _STOP_("db 0, 3Eh, 95h, 1, 0, 0DAh, 95h, 1, 3 dup(...");
        _STOP_("db 12h, 13h, 0A6h, 84h, 2, 0, 6, 85h, 2, 0...");
        _STOP_("db 0, 0C6h, 85h, 2, 3 dup(0), 0E2h, 41h, 2...");
        _STOP_("db 8Bh, 2, 0, 0D4h, 8Bh, 2, 0, 5Ch, 8Ch, 2...");
        _STOP_("db 41h, 42h, 13h, 3Ch, 89h, 2, 0, 0ECh, 89...");
        _STOP_("db 8Ah, 2, 3 dup(0), 0E2h, 41h, 54h, 13h, ...");
        _STOP_("db 0, 64h, 91h, 1, 0, 0Ah, 92h, 1, 0, 0A6h...");
        _STOP_("db 0E2h, 41h, 66h, 13h, 0E2h, 7Ah, 0Ah, 0,...");
        _STOP_("db 0, 86h, 7Ah, 1, 3 dup(0), 0E2h, 41h, 80...");
        _STOP_("db 7Ch, 0Ah, 0, 2Ah, 7Bh, 1, 0, 0BCh, 7Bh,...");
        _STOP_("db 0E2h, 41h, 92h, 13h, 78h, 7Dh, 0Ah, 0, ...");
        _STOP_("db 0, 18h, 7Dh, 1, 3 dup(0), 0E2h, 41h, 0A...");
        _STOP_("db 7Eh, 0Ah, 0, 0D8h, 7Dh, 1, 0, 6Ah, 7Eh,...");
        _STOP_("db 0E2h, 41h, 0B6h, 13h, 22h, 80h, 0Ah, 0,...");
        _STOP_("db 0, 0C6h, 7Fh, 1, 3 dup(0), 0E2h, 41h, 0...");
        _STOP_("db 81h, 0Ah, 0, 6Ah, 80h, 1, 0, 0FCh, 80h,...");
        _STOP_("db 0E2h, 41h, 0DAh, 13h, 0B8h, 82h, 0Ah, 0...");
        _STOP_("db 1, 0, 58h, 82h, 1, 3 dup(0), 0E2h, 41h,...");
        _STOP_("db 84h, 0Ah, 0, 18h, 83h, 1, 0, 0AAh, 83h,...");
        _STOP_("db 0E2h, 41h, 0FEh, 13h, 26h, 74h, 1, 0, 0...");
        _STOP_("db 0, 7Ch, 75h, 1, 0, 2Ch, 76h, 1, 0, 0C8h...");
        _STOP_("db 64h, 77h, 1, 0, 0ECh, 77h, 1, 0, 74h, 7...");
        _STOP_("db 79h, 1, 3 dup(0), 0E2h, 41h, 0Ch, 14h, ...");
        _STOP_("db 0, 3Ch, 34h, 1, 0, 0E2h, 34h, 1, 0, 88h...");
        _STOP_("db 2Eh, 36h, 1, 0, 0D4h, 36h, 1, 0, 7Ah, 3...");
        _STOP_("db 32h, 3, 3 dup(0), 0E2h, 41h, 36h, 14h, ...");
        _STOP_("db 0, 0C6h, 38h, 1, 0, 6Ch, 39h, 1, 0, 12h...");
        _STOP_("db 0B8h, 3Ah, 1, 0, 5Eh, 3Bh, 1, 0, 4, 3Ch...");
        _STOP_("db 32h, 3, 3 dup(0), 0E2h, 41h, 5Ch, 14h, ...");
        _STOP_("db 0, 0Ch, 2Fh, 1, 0, 0B2h, 2Fh, 1, 0, 58h...");
        _STOP_("db 0FEh, 30h, 1, 0, 0A4h, 31h, 1, 0, 4Ah, ...");
        _STOP_("db 32h, 3, 3 dup(0), 0E2h, 41h, 82h, 14h, ...");
        _STOP_("db 0, 82h, 2Ah, 1, 0, 28h, 2Bh, 1, 0, 0CEh...");
        _STOP_("db 74h, 2Ch, 1, 0, 1Ah, 2Dh, 1, 0, 0C0h, 2...");
        _STOP_("db 32h, 3, 3 dup(0), 0E2h, 41h, 0A8h, 14h,...");
        _STOP_("db 0, 50h, 3Dh, 1, 0, 0F6h, 3Dh, 1, 0, 9Ch...");
        _STOP_("db 42h, 3Fh, 1, 0, 0E8h, 3Fh, 1, 0, 8Eh, 4...");
        _STOP_("db 32h, 3, 3 dup(0), 0E2h, 41h, 0CEh, 14h,...");
        _STOP_("db 0, 0EEh, 50h, 1, 0, 9Eh, 51h, 1, 0, 4Eh...");
        _STOP_("db 0FEh, 52h, 1, 0, 4Eh, 52h, 1, 0, 9Eh, 5...");
        _STOP_("db 50h, 1, 3 dup(0), 0E2h, 41h, 0F4h, 14h,...");
        _STOP_("db 0, 5Eh, 54h, 1, 0, 0Eh, 55h, 1, 0, 0BEh...");
        _STOP_("db 6Eh, 56h, 1, 0, 0BEh");
        _STOP_("db  55h");
        _STOP_("db  0Eh");
        _STOP_("db  55h");
        _STOP_("db  5Eh");
        _STOP_("db  54h");
        _STOP_("db 0E2h");
        _STOP_("db  41h");
        _STOP_("db  1Ah");
        _STOP_("db  15h");
        _STOP_("db  1Eh");
        _STOP_("db  57h");
        _STOP_("db 0CEh");
        _STOP_("db  57h");
        _STOP_("db  7Eh");
        _STOP_("db  58h");
        _STOP_("db  2Eh");
        _STOP_("db  59h");
        _STOP_("db 0DEh");
        _STOP_("db  59h");
        _STOP_("db  2Eh");
        _STOP_("db  59h");
        _STOP_("db  7Eh");
        _STOP_("db  58h");
        _STOP_("db 0CEh");
        _STOP_("db  57h");
        _STOP_("db 0E2h");
        _STOP_("db  41h");
        _STOP_("db  40h");
        _STOP_("db  15h");
        _STOP_("db 0C0h");
        _STOP_("db  96h");
        _STOP_("db  70h");
        _STOP_("db  97h");
        _STOP_("db 0E4h");
        _STOP_("db  97h");
        _STOP_("db  62h");
        _STOP_("db  98h");
        _STOP_("db 0EAh");
        _STOP_("db  98h");
        _STOP_("db  7Ch");
        _STOP_("db  99h");
        _STOP_("db  18h");
        _STOP_("db  9Ah");
        _STOP_("db 0E2h");
        _STOP_("db  41h");
        _STOP_("db  66h");
        _STOP_("db  15h");
        return;
    } while (1);
}
function* sub_11588() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
    case 0x11589:
        push(r16[cx]);
        r16[cx] = r16[ax];
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x000c);
        memory16set(ds*16+r16[si] + 2, 0x3998);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = r16[dx];
        yield* sub_141A1();
        r16[ax] += r16[cx];
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = r16[di];
        yield* sub_141A1();
        r16[ax] += r16[bx];
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[si] + 16, bp);
        bp -= 0x0004;
        r16[ax] = r16[cx];
        r16[cx] = pop();
        r16[cx] -= 1;
        if (r16s[cx] >= 0) {
            pc = 0x11589;
            break;
        }
        r16[si] = pop();
        memory16set(ds*16+0x8E88, 0x0006);
        memory16set(ds*16+0x8E8A, 0x0006);
        return;
    } while (1);
}
function* sub_115E4() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
    case 0x115E5:
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1078E();
        r16[di] = 0x11f2;
        memory16set(ds*16+r16[si], 0x0060);
        memory16set(ds*16+r16[si] + 2, 0x28df);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        r16[ax] = 0x012c;
        yield* sub_141A1();
        r16[ax] += 0x000a;
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = 0x00b4;
        yield* sub_141A1();
        r16[ax] += 0x0006;
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0x0007);
        memory16set(ds*16+0x9164, memory16get(ds*16+0x9164) + 1);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1078E();
        r16[di] = 0x11b4;
        memory16set(ds*16+r16[si], 0x0018);
        memory16set(ds*16+r16[si] + 2, 0x28df);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        r16[ax] = 0x012c;
        yield* sub_141A1();
        r16[ax] += 0x000a;
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = 0x00b4;
        yield* sub_141A1();
        r16[ax] += 0x0006;
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0x0007);
        memory16set(ds*16+0x9164, memory16get(ds*16+0x9164) + 1);
        r16[cx] -= 1;
        if (r16s[cx] < 0) {
            pc = 0x11687;
            break;
        }
        pc = 0x115E5;
        break;
    case 0x11687:
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_11689() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+r16[si] + 10);
        if (memory[ds*16+r16[si] + 38] == 0x00)
            return;
        r16[di] = memory16get(ds*16+r16[si] + 68);
    case 0x11695:
        r16[di] = memory16get(ds*16+r16[di] + 10);
        if (memory16get(ds*16+r16[di]) == 0x0000)
            return;
        if (memory[ds*16+r16[di] + 38] == 0x00)
            return;
        if (r16[si] == memory16get(ds*16+r16[di] + 68)) {
            pc = 0x11695;
            break;
        }
        return;
    } while (1);
}
function* sub_116A9() {
    yield* sub_10E6F();
    memory16set(ds*16+0x8E7A, memory16get(ds*16+0x8E7A) ^ 0x0001);
    yield* sub_10E6F();
    memory16set(ds*16+0x8E7A, memory16get(ds*16+0x8E7A) ^ 0x0001);
}
function* sub_116BA() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x8fb2;
        yield* sub_10762();
        r16[si] = 0x8ffe;
        yield* sub_10762();
        r16[si] = 0x904a;
        yield* sub_10762();
        r16[si] = 0x9096;
        yield* sub_10762();
        r16[si] = 0x90e2;
        yield* sub_10762();
        r16[si] = 0x9f00;
        r16[di] = 0x8fb2;
        yield* sub_1077C();
        memory16set(ds*16+r16[si], 0x0008);
        memory16set(ds*16+r16[si] + 2, 0x4311);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory16set(ds*16+r16[si] + 12, 0x077a);
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 18, 0x00a0);
        memory16set(ds*16+r16[si] + 22, 0x00b0);
        r16[bx] = 0x3292;
        r16[cx] = 0x0004;
    case 0x11709:
        yield* sub_11022();
        r16[di] = 0x8fb2;
        yield* sub_1078E();
        memory16set(ds*16+r16[si], 0x00c4);
        memory16set(ds*16+r16[si] + 2, 0x4759);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        r16[di] = memory16get(ds*16+r16[bx]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        memory16set(ds*16+r16[si] + 18, 0x00a0);
        memory16set(ds*16+r16[si] + 22, 0x00b0);
        r16[ax] = r16[cx];
        r16[ax] -= 1;
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        if (--r16[cx]) {
            pc = 0x11709;
            break;
        }
        memory16set(ds*16+0x9134, 0x0000);
        memory16set(ds*16+0x914C, 0x0000);
        memory16set(ds*16+0x9138, 0x0000);
        memory16set(ds*16+0x913C, 0x0000);
        memory16set(ds*16+0x9140, 0x0000);
        memory16set(ds*16+0x9144, 0x0000);
        memory16set(ds*16+0x9148, 0x0000);
        yield* sub_12BCC();
        r16[cx] = 0x000e;
        r16[di] = 0x916a;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        yield* sub_135EB();
        memory16set(ds*16+0x912E, 0x0008);
        memory16set(ds*16+0x9130, 0x0008);
        memory16set(ds*16+0x9132, 0x0001);
        memory16set(ds*16+0x8E7E, 0x0000);
        memory16set(ds*16+0x9150, 0x0000);
        memory16set(ds*16+0x8E80, 0x0000);
        memory16set(ds*16+0x8E82, 0x0000);
        memory16set(ds*16+0x9152, 0x0000);
        memory16set(ds*16+0x9154, 0x0000);
        memory16set(ds*16+0x9156, 0x0000);
        memory16set(ds*16+0x9158, 0x0000);
        memory16set(ds*16+0x915E, 0x0000);
        memory16set(ds*16+0x9160, 0x0000);
        memory16set(ds*16+0x8E84, 0x0000);
        memory16set(ds*16+0x9162, 0x0000);
        r16[di] = 0x921c;
        r16[cx] = 0x0007;
        r8[al] = r8[al] ^ r8[al];
        rep_stosb_data_forward();
        memory16set(ds*16+0x9164, 0x0000);
        memory16set(ds*16+0x9186, 0x0027);
        memory16set(ds*16+0x9188, 0x0000);
        memory[ds*16+0x9223] = 0x00;
        memory[ds*16+0x9224] = 0x00;
        memory16set(ds*16+0x918A, 0x00ff);
        memory16set(ds*16+0x918C, 0x0001);
        memory[ds*16+0x9225] = 0x00;
        memory16set(ds*16+0x91B0, 0x0003);
        yield* sub_10E91();
        memory[ds*16+0x8FAF] = 0xff;
        yield* sub_10BA5();
        return;
    } while (1);
}
function* sub_11827() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x8F5C] = 0x00;
        memory[ds*16+0x8F5D] = 0xff;
        memory16set(ds*16+0x991E, 0x0008);
        memory16set(ds*16+0x991A, 0x0001);
        memory16set(ds*16+0x8E7A, 0x0000);
        memory[ds*16+0x8F5E] = 0x00;
        if (memory16get(ds*16+0x8E70) != 0x0002) {
            pc = 0x11854;
            break;
        }
        memory[ds*16+0x8F5E] = 0xff;
    case 0x11854:
        memory[ds*16+0x8F5F] = 0x00;
        memory[ds*16+0x8F60] = 0x00;
        yield* sub_109A7();
        yield* sub_10A73();
        memory[ds*16+0x8F61] = 0x00;
        r16[si] = 0x9f4c;
        r16[cx] = 0x009e;
        memory16set(ds*16+0x8E7C, r16[si]);
    case 0x11873:
        memory16set(ds*16+r16[si], 0x0000);
        lea(di, ds, r16[si] + 76);
        memory16set(ds*16+r16[si] + 8, r16[di]);
        r16[si] = r16[di];
        if (--r16[cx]) {
            pc = 0x11873;
            break;
        }
        memory16set(ds*16+r16[si], 0x0000);
        memory16set(ds*16+r16[si] + 8, 0x0000);
        r16[di] = 0x9c80;
        r16[ax] = 0xffff;
        r16[cx] = 0x0140;
        rep_stosw_data_forward();
        yield* sub_116A9();
        yield* sub_116BA();
        if (memory[ds*16+0x8F5E] == 0x00) {
            pc = 0x118AD;
            break;
        }
        yield* sub_11A19();
        yield* sub_116BA();
        yield* sub_11A19();
        return;
    case 0x118AD:
        yield* sub_11A19();
        memory16set(ds*16+0x918A, 0x0000);
        yield* sub_10E91();
        yield* sub_11A19();
        return;
    } while (1);
}
function* sub_118F5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x01;
        interrupt(128);
        if (memory16get(ds*16+0x9162) == 0x0000) {
            pc = 0x11903;
            break;
        }
        yield* sub_1472D();
    case 0x11903:
        r16[ax] = memory16get(ds*16+0x91A6);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCFE, r16[ax]);
        r16[si] = memory16get(ds*16+0x90EC);
        yield* sub_1371A();
        r16[si] = memory16get(ds*16+0x90A0);
        yield* sub_1371A();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_1371A();
    case 0x11922:
        r16[si] = memory16get(ds*16+0x9008);
        if (memory16get(ds*16+r16[si]) == 0x0000) {
            pc = 0x11930;
            break;
        }
        yield* sub_137A9();
        pc = 0x11922;
        break;
    case 0x11930:
        r16[di] = 0x9c80;
        r16[ax] = 0xffff;
        r16[cx] = 0x0140;
        rep_stosw_data_forward();
        return;
    } while (1);
}
function* sub_1193C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x916a;
        r16[cx] = 0x0007;
    case 0x11942:
        lodsw_data_forward();
        r16[bx] = r16[ax];
        lodsw_data_forward();
        if (!(r16[bx] & r16[bx])) {
            pc = 0x11958;
            break;
        }
        push(r16[si]);
        push(r16[cx]);
        push(r16[ax]);
        r16[ax] = r16[bx];
        yield* sub_129D7();
        r16[ax] = pop();
        memory16set(ds*16+r16[di] + 52, r16[ax]);
        r16[cx] = pop();
        r16[si] = pop();
    case 0x11958:
        if (--r16[cx]) {
            pc = 0x11942;
            break;
        }
        return;
    } while (1);
}
function* sub_1195B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x9f00;
        memory[ds*16+0x9224] = 0x00;
        r16[ax] = memory16get(ds*16+0x91A2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        memory16set(ds*16+r16[si] + 22, 0x00b0);
        r16[ax] = memory16get(ds*16+0x91A6);
        memory16set(ds*16+0x9190, r16[ax]);
        memory16set(ds*16+0x91AA, r16[ax]);
        r16[ax] += 1;
        memory16set(ds*16+0x9192, r16[ax]);
        r16[ax] += 0x00bf;
        memory16set(ds*16+0x9194, r16[ax]);
        r16[ax] = memory16get(ds*16+0x91A6);
        r16[ax] &= 0x000f;
        memory16set(ds*16+0x9196, r16[ax]);
        r16[ax] = memory16get(ds*16+0x91A6);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[dx] = 0x0028;
        _mul(r16[dx]);
        memory16set(ds*16+0x918E, r16[ax]);
        yield* sub_1193C();
        r16[ax] = memory16get(ds*16+0x9166);
        memory16set(ds*16+0x915A, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9168);
        memory16set(ds*16+0x915C, r16[ax]);
        r16[di] = 0x8e8c;
        r16[cx] = 0x0010;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        memory16set(ds*16+0x8E80, 0x0000);
        memory16set(ds*16+0x8E7E, 0x0000);
        memory[ds*16+0x8FAF] = 0xff;
        memory16set(ds*16+0x919E, 0x0000);
        r16[di] = 0x8ebc;
        r16[cx] = 0x0004;
    case 0x119D3:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        stosw_data_forward();
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x119D3;
            break;
        }
        r16[di] = 0x8ecc;
        r16[cx] = 0x0011;
    case 0x119E3:
        r16[ax] = memory16get(ds*16+0x9190);
        stosw_data_forward();
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        stosw_data_forward();
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x119E3;
            break;
        }
        push(r16[si]);
        r16[ax] = memory16get(ds*16+0x8E7A);
        r8[al] += 0x31;
        memory[ds*16+0x3727] = r8[al];
        r16[si] = 0x3715;
        memory[ds*16+0x374E] = 0xff;
        yield* sub_15926();
        memory[ds*16+0x374E] = 0x00;
        yield* sub_10D5F();
        r16[si] = pop();
        if (memory16get(ds*16+0x9162) == 0x0000)
            return;
        yield* sub_12B22();
        return;
    } while (1);
}
function* sub_11A19() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0xce80;
        r16[di] = 0x8fb2;
        r16[cx] = 0x0146;
    case 0x11A22:
        lodsw_data_forward();
        r16[bx] = memory16get(ds*16+r16[di]);
        memory16set(ds*16+r16[si] - 2, r16[bx]);
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x11A22;
            break;
        }
        r16[si] = 0x9f00;
        r16[di] = 0x8f62;
        r16[cx] = 0x004c;
    case 0x11A34:
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[di]];
        memory[ds*16+r16[si] - 1] = r8[ah];
        stosb_data_forward();
        if (--r16[cx]) {
            pc = 0x11A34;
            break;
        }
        r16[si] = 0x0000;
        r16[di] = 0x0000;
        r16[cx] = 0x1770;
        r16[ax] = _seg003;
        es = r16[ax];
    case 0x11A4B:
        lodsw_data_forward();
        r16[bx] = memory16get(es*16+r16[di]);
        memory16set(ds*16+r16[si] - 2, r16[bx]);
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x11A4B;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        memory16set(ds*16+0x8E7A, memory16get(ds*16+0x8E7A) ^ 0x0001);
        yield* sub_10F5A();
        return;
    } while (1);
}
function* sub_11A62() {
    yield* sub_118F5();
    yield* sub_11A65();
}
function* sub_11A65() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x8E7A);
        if (memory[ds*16+r16[bx] + -28835 + 65536] == 0x00) {
            pc = 0x11A8E;
            break;
        }
        r16[bx] = r16[bx] ^ 0x0001;
        if (memory[ds*16+r16[bx] + -28835 + 65536] == 0x00) {
            pc = 0x11A84;
            break;
        }
        if (memory[ds*16+r16[bx] + -28833 + 65536] != 0x00) {
            pc = 0x11A84;
            break;
        }
        yield* sub_11A19();
    case 0x11A84:
        yield* sub_1195B();
        memory16set(ds*16+0x991E, 0x0008);
        return;
    case 0x11A8E:
        yield* sub_11A19();
        r16[bx] = memory16get(ds*16+0x8E7A);
        if (memory[ds*16+r16[bx] + -28833 + 65536] == 0x00) {
            pc = 0x11A84;
            break;
        }
        memory[ds*16+0x8F61] = 0xff;
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x11A84;
            break;
        }
        memory[ds*16+0x8FB0] = 0xff;
        pc = 0x11A84;
        break;
        return;
    } while (1);
}
function* sub_11AAF() {
    memory16set(ds*16+0x918E, 0x2d00);
    memory16set(ds*16+0x9196, 0x0000);
    memory16set(ds*16+0x9190, 0x1200);
    memory16set(ds*16+0x9192, 0x7fee);
    memory16set(ds*16+0x9194, 0x7fee);
    memory16set(ds*16+0x91AE, 0x0010);
    r16[ax] = memory16get(ds*16+0x9F12);
    memory16set(ds*16+0x91A2, r16[ax]);
    r16[ax] = memory16get(ds*16+0x9F16);
    memory16set(ds*16+0x91A4, r16[ax]);
    r16[ax] = memory16get(ds*16+0x9190);
    memory16set(ds*16+0x91A6, r16[ax]);
    r16[ax] = memory16get(ds*16+0x915A);
    memory16set(ds*16+0x9166, r16[ax]);
    r16[ax] = memory16get(ds*16+0x915C);
    memory16set(ds*16+0x9168, r16[ax]);
    memory16set(ds*16+0x9198, 0x0001);
    memory16set(ds*16+0x919A, 0x0000);
    memory16set(ds*16+0x919E, 0x0000);
    yield* sub_10F78();
    memory16set(ds*16+0x91A0, 0x0000);
    memory16set(ds*16+0x8E7E, 0x0000);
    memory16set(ds*16+0x919C, 0x0000);
    memory16set(ds*16+0x915A, 0x0000);
    memory16set(ds*16+0x915C, 0x0000);
    memory16set(ds*16+0x9166, 0x0000);
    memory16set(ds*16+0x9168, 0x0000);
    memory16set(ds*16+0x9164, 0x0000);
    memory16set(ds*16+0x91AC, 0x0001);
    memory16set(ds*16+0x91B2, 0x0000);
}
function* sub_11B43() {
    r16[si] = 0x0000;
    r16[di] = 0x0000;
    r16[cx] = 0x1770;
    r16[ax] = _seg003;
    es = r16[ax];
    rep_movsw_data_data_forward();
    r16[ax] = ds;
    es = r16[ax];
    memory16set(ds*16+0x8F32, 0x0000);
    memory16set(ds*16+0x8E86, 0x0000);
    r16[di] = 0x8e8c;
    r16[cx] = 0x0010;
    r16[ax] = r16[ax] ^ r16[ax];
    rep_stosw_data_forward();
    memory[ds*16+0x8FB0] = 0x00;
    memory[ds*16+0x8F59] = 0x00;
    memory[ds*16+0x8F5B] = 0x00;
    yield* sub_11AAF();
    if (memory16get(ds*16+0x8E70) != 0x0002)
        return;
    yield* sub_11A19();
    yield* sub_11AAF();
    yield* sub_11A19();
    return;
}
function* sub_11B90() {
    if (r16s[bx] >= 0)
        {
        yield* sub_11BA2();
        return;
    }
    r16[bx] = -r16[bx];
    yield* sub_11BA2();
    r16[ax] -= 0x0004;
    r16[ax] = -r16[ax];
    r16[ax] &= 0x0007;
}
function* sub_11BA2() {
    if (r16s[ax] >= 0)
        {
        yield* sub_11BB4();
        return;
    }
    r16[ax] = -r16[ax];
    yield* sub_11BB4();
    r16[ax] -= 0x0008;
    r16[ax] = -r16[ax];
    r16[ax] &= 0x0007;
}
function* sub_11BB4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(r16[ax] & r16[ax])) {
            pc = 0x11BCF;
            break;
        }
        if (!(r16[bx] & r16[bx])) {
            pc = 0x11BE2;
            break;
        }
        if (r16[ax] == r16[bx]) {
            pc = 0x11BE6;
            break;
        }
        if (r16s[ax] > r16s[bx]) {
            pc = 0x11BD3;
            break;
        }
        r16[ax] >>= 1;
        r16[dx] = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        div(r16[bx]);
        if (r16s[ax] >= signed16(0x3504)) {
            pc = 0x11BE6;
            break;
        }
    case 0x11BCF:
        r16[ax] = 0x0004;
        return;
    case 0x11BD3:
        r16[bx] >>= 1;
        r16[dx] = r16[bx];
        r16[bx] = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        div(r16[bx]);
        if (r16s[ax] >= signed16(0x3504)) {
            pc = 0x11BE6;
            break;
        }
    case 0x11BE2:
        r16[ax] = 0x0002;
        return;
    case 0x11BE6:
        r16[ax] = 0x0003;
        return;
    } while (1);
}
function* sub_11BEA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] += 0x0028;
        lodsw_data_forward();
        memory16set(ds*16+0xFCE2, r16[ax]);
        memory16set(ds*16+0x8EB4, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+0xFCE6, r16[ax]);
        memory16set(ds*16+0x8EB6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+0xFCEA, r16[ax]);
        memory16set(ds*16+0x8EB8, r16[ax]);
        lodsw_data_forward();
        memory16set(ds*16+0xFCEE, r16[ax]);
        memory16set(ds*16+0x8EBA, r16[ax]);
        r16[di] = memory16get(ds*16+0x9054);
        yield* sub_11C18();
        if (!flags.zero) {
            pc = 0x11C16;
            break;
        }
        yield* sub_10F96();
    case 0x11C16:
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_11C18() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x11C18:
        if (memory16get(ds*16+r16[di]) == 0x0000)
            {
            flags.zero = true;
            return;
        }
        r16[ax] = memory16get(ds*16+r16[di] + 40);
        memory16set(ds*16+0xFCF2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 42);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 44);
        memory16set(ds*16+0xFCFA, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 46);
        memory16set(ds*16+0xFCFE, r16[ax]);
        yield* sub_10F2F();
        if (!flags.zero) {
            pc = 0x11C48;
            break;
        }
        if (memory16get(ds*16+r16[di]) != 0x00b8) {
            pc = 0x11C43;
            break;
        }
        r16[di] = memory16get(ds*16+r16[di] + 70);
    case 0x11C43:
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x11C18;
        break;
    case 0x11C48:
        if (memory16get(ds*16+r16[di]) == 0x00b8) {
            pc = 0x11C43;
            break;
        }
        flags.zero = false;
        return;
    } while (1);
}
function* loc_11C76() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x11C76:
        yield* sub_11C18();
        if (flags.zero) {
            pc = 0x11CC1;
            break;
        }
        memory16set(ds*16+0xFCC6, r16[si]);
        r16[si] = r16[di];
        yield* sub_11689();
        push(r16[di]);
        r16[ax] = memory16get(cs*16+0x1CCA);
        r16[di] = r16[si];
        r16[si] = memory16get(ds*16+0xFCC6);
        push(memory16get(ds*16+0xFCE2));
        push(memory16get(ds*16+0xFCE6));
        push(memory16get(ds*16+0xFCEA));
        push(memory16get(ds*16+0xFCEE));
        yield* sub_13A36();
        memory16set(ds*16+0xFCEE, pop());
        memory16set(ds*16+0xFCEA, pop());
        memory16set(ds*16+0xFCE6, pop());
        memory16set(ds*16+0xFCE2, pop());
        r16[di] = pop();
        if (memory16get(ds*16+r16[di]) == 0x0004)
            return;
        if (memory16get(ds*16+0x9164) != 0x0000)
            return;
        pc = 0x11C76;
        break;
    case 0x11CC1:
        yield* sub_10F96();
        if (_FIXME_)
            return;
    {yield* sub_13A36(); return; };
        return;
        _STOP_("word_11CCA dw 0");
        return;
    } while (1);
}
function* sub_11CCC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+0x9054);
        memory16set(ds*16+0x8EB4, r16[ax]);
        memory16set(ds*16+0x8EB8, r16[ax]);
        memory16set(ds*16+0x8EB6, r16[bx]);
        memory16set(ds*16+0x8EBA, r16[bx]);
    case 0x11CDE:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x11D0C;
            break;
        }
        if (r16s[ax] < memory16gets(ds*16+r16[di] + 40)) {
            pc = 0x11CFE;
            break;
        }
        if (r16s[ax] > memory16gets(ds*16+r16[di] + 44)) {
            pc = 0x11CFE;
            break;
        }
        if (r16s[bx] < memory16gets(ds*16+r16[di] + 42)) {
            pc = 0x11CFE;
            break;
        }
        if (r16s[bx] > memory16gets(ds*16+r16[di] + 46)) {
            pc = 0x11CFE;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x00b8) {
            pc = 0x11D07;
            break;
        }
        flags.zero = false;
        return;
    case 0x11CFE:
        if (memory16get(ds*16+r16[di]) != 0x00b8) {
            pc = 0x11D07;
            break;
        }
        r16[di] = memory16get(ds*16+r16[di] + 70);
    case 0x11D07:
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x11CDE;
        break;
    case 0x11D0C:
        memory16set(ds*16+0xFCE2, r16[ax]);
        memory16set(ds*16+0xFCE6, r16[bx]);
        memory16set(ds*16+0xFCEA, r16[ax]);
        memory16set(ds*16+0xFCEE, r16[bx]);
        yield* sub_10F96();
        return;
    } while (1);
}
function* sub_11D1E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[dx] = r16[dx] + memory16get(ds*16+0x9196);
        r16[bx] = r16[dx];
        r16[bx] &= 0x000f;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] &= 0x00fe;
        r16[si] += r16[ax];
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[si] += r16[ax];
        r16[dx] = 0x0004;
        r16[di] = 0x9920;
        push(r16[bx]);
        yield* sub_11E02();
        r16[bx] = pop();
        r16[di] = 0x9922;
        push(r16[bx]);
        yield* sub_11E02();
        r16[bx] = pop();
        r16[di] = 0x9924;
        push(r16[bx]);
        yield* sub_11E02();
        r16[bx] = pop();
        r16[di] -= 0x0004;
        r16[si] += 0x0022;
        r16[cx] += r16[bx];
        flags.carry2 = r16s[cx] <= 0x0010;
        r16[cx] -= 0x0010;
        if (flags.carry2) {
            pc = 0x11D97;
            break;
        }
    case 0x11D71:
        r16[bx] = r16[bx] ^ r16[bx];
        push(r16[di]);
        yield* sub_11E02();
        r16[di] = pop();
        r16[bx] = r16[bx] ^ r16[bx];
        r16[di] += 0x0002;
        push(r16[di]);
        yield* sub_11E02();
        r16[di] = pop();
        r16[bx] = r16[bx] ^ r16[bx];
        r16[di] += 0x0002;
        push(r16[di]);
        yield* sub_11E02();
        r16[di] = pop();
        r16[di] += 0x005c;
        r16[si] += 0x0022;
        flags.carry2 = r16s[cx] > 0x0010;
        r16[cx] -= 0x0010;
        if (flags.carry2) {
            pc = 0x11D71;
            break;
        }
    case 0x11D97:
        r16[si] = pop();
        return;
    } while (1);
}
function* loc_11DE4() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x11DE4:
        r16[bx] = r16[bx] ^ r16[bx];
        push(r16[di]);
        yield* sub_11E02();
        r16[di] = pop();
        r16[bx] = r16[bx] ^ r16[bx];
        r16[di] += 0x0002;
        push(r16[di]);
        yield* sub_11E02();
        r16[di] = pop();
        r16[di] -= 0x0002;
        r16[si] += 0x0024;
        r16[cx] -= 0x0010;
        if (_FIXME_) {
            pc = 0x11DE4;
            break;
        }
    case 0x11E00:
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_11E02() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[bx]);
        r16[bx] -= 0x0010;
        r16[bx] = -r16[bx];
        if (r16s[cx] <= r16s[bx]) {
            pc = 0x11E0F;
            break;
        }
        r16[cx] = r16[bx];
    case 0x11E0F:
        r16[bx] = pop();
        if (!(r16[cx] & r16[cx])) {
            pc = 0x11E27;
            break;
        }
        lodsw_data_forward();
        push(r16[si]);
        r16[si] = 0x5538;
        r16[ax] >>= 1;
        r16[si] += r16[ax];
        r16[si] += r16[bx];
        r16[si] += r16[bx];
    case 0x11E21:
        movsw_data_data_forward();
        r16[di] += r16[dx];
        if (--r16[cx]) {
            pc = 0x11E21;
            break;
        }
        r16[si] = pop();
    case 0x11E27:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_11E29() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] -= 0x000e;
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] -= 0x000e;
        r16[bx] = r16[ax];
        r16[bx] &= 0x000f;
        r16[bx] <<= 1;
        push(memory16get(ds*16+r16[bx] + 12954));
        r16[cx] = 0x0019;
        yield* sub_11D1E();
        r16[di] = pop();
        push(r16[si]);
        r16[si] = 0x9920;
        r16[cx] = 0x004b;
    case 0x11E4E:
        lodsw_data_forward();
        r16[ax] = r16[ax] & memory16get(ds*16+r16[di]);
        if (r16[ax] != 0) {
            pc = 0x11E5C;
            break;
        }
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x11E4E;
            break;
        }
        r16[si] = pop();
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    case 0x11E5C:
        r16[si] = pop();
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    } while (1);
}
function* sub_11E61() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = pop();
        r16[ax] = memory16get(ds*16+r16[di] + 34);
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = 0x31fe;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds*16+r16[bx]);
        r16[bx] += 0x0002;
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] <<= 1;
        r16[dx] = 0x000e;
        bp = 0x31d8;
        bp += r16[ax];
        if (!(memory16get(ds*16+bp + 0) & 0x0001)) {
            pc = 0x11E98;
            break;
        }
        r16[dx] = 0x000e;
    case 0x11E98:
        memory16set(ds*16+0x8E88, r16[dx]);
        memory16set(ds*16+r16[si] + 2, 0x28df);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[bx] = memory16get(ds*16+r16[bx]);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        memory16set(ds*16+r16[si] + 26, 0x0007);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_11ED3() {
    push(r16[si]);
    yield* sub_11022();
    r16[di] = 0x9096;
    yield* sub_1077C();
    r16[di] = r16[si];
    r16[si] = pop();
    memory16set(ds*16+r16[di], 0x0014);
    memory16set(ds*16+r16[di] + 2, 0x1f4d);
    memory16set(ds*16+r16[di] + 4, 0x0853);
    memory16set(ds*16+r16[di] + 12, bp);
    memory16set(ds*16+r16[di] + 14, 0x0000);
    memory16set(ds*16+r16[di] + 18, r16[ax]);
    memory16set(ds*16+r16[di] + 22, r16[bx]);
    memory16set(ds*16+r16[di] + 28, r16[cx]);
    memory16set(ds*16+r16[di] + 66, r16[dx]);
    memory16set(ds*16+r16[di] + 40, 0x03e8);
    memory16set(ds*16+r16[di] + 44, 0x03e8);
}
function* sub_11F4D() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r16[bx] <<= 1;
        r16[ax] = memory16get(cs*16+r16[bx] + 7949);
        imul16(memory16get(ds*16+r16[si] + 66));
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory16get(ds*16+r16[si] + 20) + r16[ax]) >= 0x10000;
        memory16set(ds*16+r16[si] + 20, memory16get(ds*16+r16[si] + 20) + r16[ax]);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[dx] + flags.carry);
        r16[ax] = memory16get(cs*16+r16[bx] + 7981);
        imul16(memory16get(ds*16+r16[si] + 66));
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory16get(ds*16+r16[si] + 24) + r16[ax]) >= 0x10000;
        memory16set(ds*16+r16[si] + 24, memory16get(ds*16+r16[si] + 24) + r16[ax]);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[dx] + flags.carry);
        r16[ax] = memory16get(ds*16+0x9198);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 18) >= 0x0140) {
            pc = 0x11FB0;
            break;
        }
        if (memory16get(ds*16+r16[si] + 22) >= 0x00c0) {
            pc = 0x11FB0;
            break;
        }
        yield* sub_13589();
        yield* sub_142AE();
        if (flags.zero)
            return;
        if (memory16get(ds*16+0x9188) != 0x0000) {
            pc = 0x11FB0;
            break;
        }
        r16[ax] = 0x0004;
        yield* sub_13C4F();
        memory16set(ds*16+0x9F04, 0x08b9);
    case 0x11FB0:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_125A8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+r16[si] + 68);
        bp = memory16get(ds*16+r16[di] + 10);
        if (bp == r16[si]) {
            pc = 0x12624;
            break;
        }
    case 0x125B2:
        if (memory16get(ds*16+bp + 4) != 0x0761) {
            pc = 0x125CD;
            break;
        }
        bp = memory16get(ds*16+bp + 10);
        if (bp != r16[si]) {
            pc = 0x125B2;
            break;
        }
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 44, 0x03e8);
        return;
    case 0x125CD:
        r16[ax] = memory16get(ds*16+bp + 40);
        r16[bx] = memory16get(ds*16+bp + 42);
        r16[cx] = memory16get(ds*16+bp + 44);
        r16[dx] = memory16get(ds*16+bp + 46);
    case 0x125DD:
        bp = memory16get(ds*16+bp + 10);
        if (r16[si] == bp) {
            pc = 0x12617;
            break;
        }
        if (memory16get(ds*16+bp + 4) == 0x0761) {
            pc = 0x125DD;
            break;
        }
        if (r16s[ax] <= memory16gets(ds*16+bp + 40)) {
            pc = 0x125F7;
            break;
        }
        r16[ax] = memory16get(ds*16+bp + 40);
    case 0x125F7:
        if (r16s[bx] <= memory16gets(ds*16+bp + 42)) {
            pc = 0x12601;
            break;
        }
        r16[bx] = memory16get(ds*16+bp + 42);
    case 0x12601:
        if (r16s[cx] >= memory16gets(ds*16+bp + 44)) {
            pc = 0x1260B;
            break;
        }
        r16[cx] = memory16get(ds*16+bp + 44);
    case 0x1260B:
        if (r16s[dx] >= memory16gets(ds*16+bp + 46)) {
            pc = 0x125DD;
            break;
        }
        r16[dx] = memory16get(ds*16+bp + 46);
        pc = 0x125DD;
        break;
    case 0x12617:
        memory16set(ds*16+r16[di] + 40, r16[ax]);
        memory16set(ds*16+r16[di] + 42, r16[bx]);
        memory16set(ds*16+r16[di] + 44, r16[cx]);
        memory16set(ds*16+r16[di] + 46, r16[dx]);
        return;
    case 0x12624:
        push(r16[di]);
        yield* sub_107C0();
        r16[si] = pop();
        yield* sub_107C0();
        return;
    } while (1);
}
function* loc_127E7() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x8F38);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        if (r16s[ax] >= 0) {
            pc = 0x127F1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x127F1:
        if (r16s[ax] >= signed16(0x0020)) {
            pc = 0x12805;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F3A);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 22);
        if (r16s[ax] >= 0) {
            pc = 0x12800;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x12800:
        if (r16s[ax] < signed16(0x0020))
            return;
    case 0x12805:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x8F38, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+0x8F3A, r16[ax]);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        bp = memory16get(ds*16+r16[si] + 16);
        bp -= 0x0004;
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 52);
        memory16set(ds*16+r16[di] + 52, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8E86);
        r16[ax] += 1;
        memory16set(ds*16+0x8E86, r16[ax]);
        r16[ax] = -r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+r16[di] + 26, r16[ax]);
        return;
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        if (r16s[ax] <= signed16(0x0008)) {
            pc = 0x12878;
            break;
        }
        r16[ax] = 0x0008;
    case 0x12878:
        if (r16s[ax] >= signed16(0xfff8)) {
            pc = 0x12880;
            break;
        }
        r16[ax] = 0xfff8;
    case 0x12880:
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 22);
        if (r16s[ax] <= signed16(0x0008)) {
            pc = 0x12894;
            break;
        }
        r16[ax] = 0x0008;
    case 0x12894:
        if (r16s[ax] >= signed16(0xfff8)) {
            pc = 0x1289C;
            break;
        }
        r16[ax] = 0xfff8;
    case 0x1289C:
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F12);
        if (r16[ax] != memory16get(ds*16+r16[si] + 18))
            return;
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        if (r16[ax] != memory16get(ds*16+r16[si] + 22))
            return;
        memory16set(ds*16+r16[si] + 26, 0x0000);
        return;
        if (memory[ds*16+0x9224] == 0x00) {
            pc = 0x128C2;
            break;
        }
        _STOP_("goto loc_13A2F");
    case 0x128C2:
        yield* sub_141B1();
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - 0x000a);
        if (memory16gets(ds*16+r16[si] + 22) >= 0) {
            pc = 0x128CF;
            break;
        }
        yield* sub_107C0();
        return;
    case 0x128CF:
        yield* sub_13589();
        yield* sub_11BEA();
        if (flags.zero)
            return;
        r16[ax] = memory16get(cs*16+0x13DA4);
    {yield* sub_13A36(); return; };
        return;
    } while (1);
}
function* sub_128DF() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        if (memory16get(ds*16+r16[si] + 26) == 0x0000) {
            pc = 0x128FE;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 26) >= 0 /*CHECK*/) {
            pc = 0x1291F;
            break;
        }
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] &= 0x0003;
        if (r16[ax] != 0) {
            pc = 0x1295E;
            break;
        }
        memory16set(ds*16+r16[si] + 28, memory16get(ds*16+r16[si] + 28) + 1);
        memory16set(ds*16+r16[si] + 28, memory16get(ds*16+r16[si] + 28) & 0x0007);
        pc = 0x1295E;
        break;
    case 0x128FE:
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + 0x0008);
        if (memory16gets(ds*16+r16[si] + 22) < signed16(0x00c8)) {
            pc = 0x12976;
            break;
        }
        if (memory16get(ds*16+0x9164) == 0x0000) {
            pc = 0x1291B;
            break;
        }
        memory16set(ds*16+0x9164, memory16get(ds*16+0x9164) - 1);
        if (memory16get(ds*16+0x9164) != 0) {
            pc = 0x1291B;
            break;
        }
        memory[ds*16+0x8FB0] = 0xff;
    case 0x1291B:
        yield* sub_107C0();
        return;
    case 0x1291F:
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) & 0x0007);
        if (memory16get(ds*16+r16[si] + 26) != 0) {
            pc = 0x12937;
            break;
        }
        r16[ax] = 0x00a0;
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        r16[bx] = 0x0064;
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si] + 22);
        yield* sub_11B90();
        memory16set(ds*16+r16[si] + 28, r16[ax]);
    case 0x12937:
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        r16[ax] = 0x00a0;
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        imul16(r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = r16[dx];
        r16[ax] = 0x0064;
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 22);
        imul16(r16[ax]);
        flags.carry = (r16[ax] + r16[bx]) >= 0x10000;
        r16[ax] += r16[bx];
        r16[dx] = r16[dx] + r16[cx] + flags.carry;
        if (r16[dx] != 0) {
            pc = 0x1295E;
            break;
        }
        if (r16[ax] >= 0x0190) {
            pc = 0x1295E;
            break;
        }
        memory16set(ds*16+r16[si] + 26, 0xffde);
    case 0x1295E:
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] &= 0x001c;
        r16[ax] = memory16get(ds*16+r16[bx] + 12728);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 12730);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
    case 0x12976:
        yield* sub_13589();
        yield* sub_142AE();
        if (flags.zero)
            return;
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = 0x0064;
        if (r16[ax] == 0x0018) {
            pc = 0x12990;
            break;
        }
        r16[dx] = 0x0032;
        if (r16[ax] != 0x0060) {
            pc = 0x129B5;
            break;
        }
    case 0x12990:
        flags.carry = (memory16get(ds*16+0x915A) + r16[dx]) >= 0x10000;
        memory16set(ds*16+0x915A, memory16get(ds*16+0x915A) + r16[dx]);
        memory16set(ds*16+0x915C, memory16get(ds*16+0x915C) + 0x0000 + flags.carry);
        memory16set(ds*16+0x8E88, 0x0004);
        if (memory16get(ds*16+0x9164) == 0x0000) {
            pc = 0x129B1;
            break;
        }
        memory16set(ds*16+0x9164, memory16get(ds*16+0x9164) - 1);
        if (memory16get(ds*16+0x9164) != 0) {
            pc = 0x129B1;
            break;
        }
        memory[ds*16+0x8FB0] = 0xff;
    case 0x129B1:
        yield* sub_107C0();
        return;
    case 0x129B5:
        push(memory16get(ds*16+r16[si] + 34));
        yield* sub_107C0();
        r16[bx] = pop();
        r16[bx] <<= 1;
        r16[di] = memory16get(ds*16+r16[bx] + 12760);
        r16[ax] = 0x000f;
        if (!(r16[di] & 0x0001)) {
            pc = 0x129CF;
            break;
        }
        r16[di] -= 1;
        r16[ax] = 0x000f;
    case 0x129CF:
        memory16set(ds*16+0x8E88, r16[ax]);
        push(r16[si]);
        yield* indirectCall(cs, r16[di]);
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_129D7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[ax] != 0x0044) {
            pc = 0x129DF;
            break;
        }
        yield* loc_1308C();
        return;
    case 0x129DF:
        if (r16[ax] != 0x0098) {
            pc = 0x129E7;
            break;
        }
    {yield* sub_12CA6(); return; };
    case 0x129E7:
        if (r16[ax] != 0x0034) {
            pc = 0x129EF;
            break;
        }
    {yield* sub_13246(); return; };
    case 0x129EF:
        if (r16[ax] != 0x002c) {
            pc = 0x129F7;
            break;
        }
    {yield* sub_12E84(); return; };
    case 0x129F7:
        if (r16[ax] != 0x0020) {
            pc = 0x129FF;
            break;
        }
    {yield* sub_131B6(); return; };
    case 0x129FF:
        if (r16[ax] != 0x004c) {
            pc = 0x12A07;
            break;
        }
    {yield* loc_12F08(); return; };
    case 0x12A07:
        if (r16[ax] != 0x003c) {
            pc = 0x12A0F;
            break;
        }
        _STOP_("goto loc_13004");
    case 0x12A0F:
        if (r16[ax] != 0x0038) {
            pc = 0x12A17;
            break;
        }
        _STOP_("goto loc_12F7C");
    case 0x12A17:
        if (r16[ax] != 0x00c0) {
            pc = 0x12A1F;
            break;
        }
    {yield* sub_12C32(); return; };
    case 0x12A1F:
        if (r16[ax] != 0x0090) {
            pc = 0x12A27;
            break;
        }
    {yield* loc_13126(); return; };
    case 0x12A27:
        if (r16[ax] != 0x0048) {
            pc = 0x12A2F;
            break;
        }
        _STOP_("goto loc_12D86");
    case 0x12A2F:
        if (r16[ax] != 0x00b0) {
            pc = 0x12A37;
            break;
        }
        _STOP_("goto loc_12DF0");
    case 0x12A37:
        if (r16[ax] != 0x0028) {
            pc = 0x12A3F;
            break;
        }
    {yield* loc_12D2A(); return; };
    case 0x12A3F:
        if (r16[ax] != 0x0094)
            return;
    {yield* sub_12BCC(); return; };
        return;
    } while (1);
}
function* sub_12A48() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x9186, memory16get(ds*16+0x9186) + 0x0014);
    case 0x12A4D:
        memory16set(ds*16+0x8E88, 0x0012);
        if (memory16gets(ds*16+0x9186) <= signed16(0x0027)) {
            pc = 0x12A60;
            break;
        }
        memory16set(ds*16+0x9186, 0x0027);
    case 0x12A60:
        memory[ds*16+0x8FAF] = 0xff;
        return;
    } while (1);
}
function* sub_12A6E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x9134;
        bp = r16[di];
        r16[ax] = 0x007f;
        r16[cx] = 0x0007;
    case 0x12A79:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x12A91;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 2);
        r16[dx] = memory16get(ds*16+r16[bx] + 52);
        if (r16[dx] == memory16get(ds*16+r16[bx] + 36)) {
            pc = 0x12A91;
            break;
        }
        if (r16s[dx] >= r16s[ax]) {
            pc = 0x12A91;
            break;
        }
        r16[ax] = r16[dx];
        bp = r16[di];
    case 0x12A91:
        r16[di] += 0x0004;
        if (--r16[cx]) {
            pc = 0x12A79;
            break;
        }
        if (r16[ax] == 0x007f)
            return;
        r16[di] = memory16get(ds*16+bp + 2);
        memory16set(ds*16+r16[di] + 52, memory16get(ds*16+r16[di] + 52) + 1);
        return;
    } while (1);
}
function* locret_12AAF() {
    return;
}
function* sub_12AB2() {
    if (memory16get(ds*16+0x915E) == 0x0002)
        return;
    memory16set(ds*16+0x915E, memory16get(ds*16+0x915E) + 1);
    return;
}
function* sub_12AD0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x8E88, 0x000b);
        yield* sub_10EB3();
        r16[di] = memory16get(ds*16+0x9054);
    case 0x12ADD:
        r16[ax] = memory16get(ds*16+r16[di]);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x12AFE;
            break;
        }
        r16[si] = r16[di];
        yield* sub_11689();
        push(r16[di]);
        if (r16[ax] == 0x0050) {
            pc = 0x12AFB;
            break;
        }
        if (r16[ax] == 0x0054) {
            pc = 0x12AFB;
            break;
        }
        r16[di] = r16[si];
        r16[si] = 0x8ffe;
        yield* sub_13A33();
    case 0x12AFB:
        r16[di] = pop();
        pc = 0x12ADD;
        break;
    case 0x12AFE:
        r16[di] = memory16get(ds*16+0x90A0);
    case 0x12B02:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x12B17;
            break;
        }
        push(memory16get(ds*16+r16[di] + 10));
        if (memory16get(ds*16+r16[di]) != 0x0014) {
            pc = 0x12B14;
            break;
        }
        r16[si] = r16[di];
        yield* sub_107C0();
    case 0x12B14:
        r16[di] = pop();
        pc = 0x12B02;
        break;
    case 0x12B17:
        r16[di] = 0x8e8c;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x0010;
        rep_stosw_data_forward();
        return;
    } while (1);
}
function* sub_12B22() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9008);
        memory16set(ds*16+0x91B4, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9006);
        memory16set(ds*16+0x91B6, r16[ax]);
        r16[di] = 0x9134;
        r16[bx] = 0x91b8;
        r16[cx] = 0x000e;
    case 0x12B37:
        r16[ax] = memory16get(ds*16+r16[di]);
        memory16set(ds*16+r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds*16+r16[di], 0x0000);
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x12B37;
            break;
        }
        r16[si] = 0x8ffe;
        yield* sub_10762();
        yield* sub_12BCC();
        yield* sub_13246();
        yield* sub_13246();
        yield* sub_131B6();
        memory16set(ds*16+r16[di] + 52, 0x0002);
        yield* sub_131B6();
        memory16set(ds*16+r16[di] + 52, 0x0002);
        yield* sub_12E84();
        memory16set(ds*16+r16[di] + 52, 0x0002);
        yield* sub_12CA6();
        memory16set(ds*16+r16[di] + 52, 0x0002);
        yield* sub_12C32();
        memory16set(ds*16+r16[di] + 52, 0x0002);
        return;
    } while (1);
}
function* loc_12BC5() {
    memory16set(ds*16+0x9188, memory16get(ds*16+0x9188) + 0x00aa);
}
function* sub_12BCC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9134) == 0x0000) {
            pc = 0x12BDC;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x9136);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12BDC:
        memory16set(ds*16+0x9134, 0x0094);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+0x9136, r16[si]);
        memory16set(ds*16+r16[si], 0x0094);
        memory16set(ds*16+r16[si] + 2, 0x37df);
        memory16set(ds*16+r16[si] + 6, 0x9134);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0002);
        memory16set(ds*16+r16[si] + 54, 0x0001);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x0008);
        return;
    } while (1);
}
function* loc_12C21() {
    r16[di] = memory16get(ds*16+0x9136);
    r16[ax] = memory16get(ds*16+r16[di] + 36);
    if (r16s[ax] <= memory16gets(ds*16+r16[di] + 52))
        return;
    memory16set(ds*16+r16[di] + 52, memory16get(ds*16+r16[di] + 52) + 1);
    return;
}
function* sub_12C32() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9134) == 0x00c0)
            _STOP_("goto loc_12C21");
        if (memory16get(ds*16+0x9134) == 0x0000) {
            pc = 0x12C4A;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x9136);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12C4A:
        memory16set(ds*16+0x9134, 0x00c0);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+0x9136, r16[si]);
        memory16set(ds*16+r16[si], 0x00c0);
        memory16set(ds*16+r16[si] + 2, 0x20f7);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory16set(ds*16+r16[si] + 6, 0x9134);
        memory16set(ds*16+r16[si] + 12, 0xa658);
        memory16set(ds*16+r16[si] + 14, 0x0000);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0002);
        memory16set(ds*16+r16[si] + 54, 0x000e);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x0008);
        return;
    } while (1);
}
function* sub_12CA6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x914C) == 0x0098) {
            pc = 0x12D19;
            break;
        }
        if (memory16get(ds*16+0x914C) == 0x0000) {
            pc = 0x12CBE;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x914E);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12CBE:
        if (memory16get(ds*16+0x9148) != 0x0044) {
            pc = 0x12CD4;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x914A);
        yield* sub_107C0();
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x0000);
    case 0x12CD4:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+0x914C, 0x0098);
        memory16set(ds*16+0x914E, r16[si]);
        memory16set(ds*16+r16[si], 0x0098);
        memory16set(ds*16+r16[si] + 2, 0x3801);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x914c);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0002);
        memory16set(ds*16+r16[si] + 54, 0x000a);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x0008);
        return;
    case 0x12D19:
        r16[di] = memory16get(ds*16+0x914E);
        r16[ax] = memory16get(ds*16+r16[di] + 36);
        if (r16s[ax] <= memory16gets(ds*16+r16[di] + 52))
            return;
        memory16set(ds*16+r16[di] + 52, memory16get(ds*16+r16[di] + 52) + 1);
        return;
    } while (1);
}
function* loc_12D2A() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x914C) == 0x0028)
            _STOP_("goto loc_12D19");
        if (memory16get(ds*16+0x914C) == 0x0000) {
            pc = 0x12D41;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x914E);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12D41:
        memory16set(ds*16+0x914C, 0x0028);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+0x914E, r16[si]);
        memory16set(ds*16+r16[si], 0x009c);
        memory16set(ds*16+r16[si] + 2, 0x3872);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x914c);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0000);
        memory16set(ds*16+r16[si] + 54, 0x0015);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x000c);
        return;
    case 0x12D86:
        if (memory16get(ds*16+0x9148) != 0x0048) {
            pc = 0x12D90;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x12D90:
        if (memory16get(ds*16+0x914C) == 0x0048)
            _STOP_("goto loc_12D19");
        r16[bx] = 0x9148;
        if (memory16get(ds*16+r16[bx]) == 0x0000) {
            pc = 0x12DAF;
            break;
        }
        r16[bx] = 0x914c;
        if (memory16get(ds*16+r16[bx]) == 0x0000) {
            pc = 0x12DAF;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+r16[bx] + 2);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12DAF:
        memory16set(ds*16+r16[bx], 0x0048);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+r16[bx] + 2, r16[si]);
        memory16set(ds*16+r16[si], 0x00a0);
        memory16set(ds*16+r16[si] + 2, 0x3900);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, r16[bx]);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0000);
        memory16set(ds*16+r16[si] + 54, 0x0017);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x001e);
        return;
    case 0x12DF0:
        if (memory16get(ds*16+0x9134) != 0x00b0) {
            pc = 0x12DFB;
            break;
        }
    {yield* loc_12C21(); return; };
    case 0x12DFB:
        if (memory16get(ds*16+0x9134) == 0x0000) {
            pc = 0x12E0B;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x9136);
        yield* sub_107C0();
        r16[si] = pop();
    case 0x12E0B:
        memory16set(ds*16+0x9134, 0x00b0);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        memory16set(ds*16+0x9136, r16[si]);
        memory16set(ds*16+r16[si], 0x00b0);
        memory16set(ds*16+r16[si] + 2, 0x213c);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory16set(ds*16+r16[si] + 6, 0x9134);
        bp = 0x110c;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[si] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0000);
        memory16set(ds*16+r16[si] + 36, 0x0002);
        memory16set(ds*16+r16[si] + 54, 0x0014);
        memory16set(ds*16+r16[si] + 72, 0xffff);
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9130, 0x0008);
        return;
    } while (1);
}
function* sub_12E73() {
    if (memory16get(ds*16+0x9148) == 0x0000)
        return;
    push(r16[si]);
    r16[si] = memory16get(ds*16+0x914A);
    yield* sub_107C0();
    r16[si] = pop();
    return;
}
function* sub_12E84() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9148) == 0x002c) {
            pc = 0x12EF8;
            break;
        }
        yield* sub_12E73();
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x002c);
        memory16set(ds*16+0x914A, r16[di]);
        memory16set(ds*16+r16[di], 0x002c);
        memory16set(ds*16+r16[di] + 2, 0x221a);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x9148);
        bp = 0x115a;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0002);
        memory16set(ds*16+r16[di] + 54, 0x0013);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        return;
    case 0x12EF8:
        r16[di] = memory16get(ds*16+0x914A);
        r16[ax] = memory16get(ds*16+r16[di] + 36);
        if (r16s[ax] <= memory16gets(ds*16+r16[di] + 52))
            return;
        memory16set(ds*16+r16[di] + 52, memory16get(ds*16+r16[di] + 52) + 1);
        return;
    } while (1);
}
function* loc_12F08() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9148) == 0x004c)
            _STOP_("goto loc_12EF8");
        yield* sub_12E73();
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x004c);
        memory16set(ds*16+0x914A, r16[di]);
        memory16set(ds*16+r16[di], 0x004c);
        memory16set(ds*16+r16[di] + 2, 0x229b);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x9148);
        bp = 0x140c;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0000);
        memory16set(ds*16+r16[di] + 54, 0x000b);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        return;
    case 0x12F7C:
        if (memory16get(ds*16+0x9148) != 0x0038) {
            pc = 0x12F86;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x12F86:
        if (memory16get(ds*16+0x9148) != 0x003c) {
            pc = 0x12F90;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x12F90:
        yield* sub_12E73();
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x0038);
        memory16set(ds*16+0x914A, r16[di]);
        memory16set(ds*16+r16[di], 0x0038);
        memory16set(ds*16+r16[di] + 2, 0x2697);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x9148);
        bp = 0x1342;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0001);
        memory16set(ds*16+r16[di] + 54, 0x0009);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        memory16set(ds*16+0x8F38, 0xff9c);
        return;
    case 0x13004:
        if (memory16get(ds*16+0x9148) != 0x0038) {
            pc = 0x1300E;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x1300E:
        if (memory16get(ds*16+0x9148) != 0x003c) {
            pc = 0x13018;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x13018:
        yield* sub_12E73();
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x003c);
        memory16set(ds*16+0x914A, r16[di]);
        memory16set(ds*16+r16[di], 0x003c);
        memory16set(ds*16+r16[di] + 2, 0x2697);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x9148);
        bp = 0x1354;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] += 0x0019;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0001);
        memory16set(ds*16+r16[di] + 36, 0x0001);
        memory16set(ds*16+r16[di] + 54, 0x000d);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        memory16set(ds*16+0x8F38, 0xff9c);
        return;
    } while (1);
}
function* loc_1308C() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9148) != 0x0044) {
            pc = 0x13096;
            break;
        }
        _STOP_("goto loc_12EF8");
    case 0x13096:
        if (memory16get(ds*16+0x914C) != 0x0098) {
            pc = 0x130AD;
            break;
        }
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x914E);
        yield* sub_107C0();
        r16[si] = pop();
        memory16set(ds*16+0x914C, 0x0000);
    case 0x130AD:
        yield* sub_12E73();
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+0x9148, 0x0044);
        memory16set(ds*16+0x914A, r16[di]);
        memory16set(ds*16+r16[di], 0x0044);
        memory16set(ds*16+r16[di] + 2, 0x3835);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x9148);
        bp = 0x12f8;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0002);
        memory16set(ds*16+r16[di] + 54, 0x0008);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        return;
    } while (1);
}
function* sub_13117() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1100E();
        if (!flags.zero) {
            pc = 0x13122;
            break;
        }
        r16[ax] = 0xffff;
        flags.zero = false;
        return;
    case 0x13122:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    } while (1);
}
function* loc_13126() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0090;
        yield* sub_13117();
        if (_FIXME_) {
            pc = 0x13131;
            break;
        }
        pc = 0x131B3;
        break;
    case 0x13131:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+bp + 0, 0x0090);
        memory16set(ds*16+bp + 2, r16[di]);
        memory16set(ds*16+r16[di], 0x0090);
        memory16set(ds*16+r16[di] + 2, 0x250b);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, bp);
        r16[cx] -= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        bp = 0x30a8;
        bp += r16[cx];
        r16[ax] = memory16get(ds*16+bp + 0);
        memory16set(ds*16+r16[di] + 48, r16[ax]);
        r16[ax] = memory16get(ds*16+bp + 2);
        memory16set(ds*16+r16[di] + 50, r16[ax]);
        bp = 0x1566;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 48);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 50);
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0000);
        memory16set(ds*16+r16[di] + 54, 0x0011);
        memory16set(ds*16+r16[di] + 72, 0xffff);
    case 0x131B3:
    {yield* sub_13319(); return; };
        return;
    } while (1);
}
function* sub_131B6() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0020;
        yield* sub_13117();
        if (!flags.zero) {
            pc = 0x131C1;
            break;
        }
        pc = 0x13243;
        break;
    case 0x131C1:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+bp + 0, 0x0020);
        memory16set(ds*16+bp + 2, r16[di]);
        memory16set(ds*16+r16[di], 0x0020);
        memory16set(ds*16+r16[di] + 2, 0x237e);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, bp);
        r16[cx] -= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        bp = 0x30a8;
        bp += r16[cx];
        r16[ax] = memory16get(ds*16+bp + 0);
        memory16set(ds*16+r16[di] + 48, r16[ax]);
        r16[ax] = memory16get(ds*16+bp + 2);
        memory16set(ds*16+r16[di] + 50, r16[ax]);
        bp = 0x118e;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 48);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 50);
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0002);
        memory16set(ds*16+r16[di] + 54, 0x0012);
        memory16set(ds*16+r16[di] + 72, 0xffff);
    case 0x13243:
    {yield* sub_13319(); return; };
        return;
    } while (1);
}
function* sub_13246() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0034;
        yield* sub_13117();
        if (!flags.zero) {
            pc = 0x13251;
            break;
        }
    {yield* sub_13319(); return; };
    case 0x13251:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x8ffe;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+bp + 0, 0x0034);
        memory16set(ds*16+bp + 2, r16[di]);
        memory16set(ds*16+r16[di], 0x0034);
        memory16set(ds*16+r16[di] + 2, 0x246d);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, bp);
        r16[cx] -= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        bp = 0x30a8;
        bp += r16[cx];
        r16[ax] = memory16get(ds*16+bp + 0);
        memory16set(ds*16+r16[di] + 48, r16[ax]);
        r16[ax] = memory16get(ds*16+bp + 2);
        memory16set(ds*16+r16[di] + 50, r16[ax]);
        bp = 0x12da;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 48);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 50);
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 52, 0x0000);
        memory16set(ds*16+r16[di] + 36, 0x0000);
        memory16set(ds*16+r16[di] + 54, 0x000f);
        memory16set(ds*16+r16[di] + 72, 0xffff);
        if (memory16get(ds*16+r16[di] + 48) == 0x0000)
            _STOP_("goto loc_13319");
        push(r16[si]);
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x9096;
        yield* sub_1078E();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x0040);
        memory16set(ds*16+r16[si] + 2, 0x21e9);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory[ds*16+r16[si] + 74] = 0xff;
        bp = 0x1366;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[si] + 16, bp);
        memory16set(ds*16+r16[si] + 28, r16[di]);
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[si] = pop();
        yield* sub_13319();
        return;
    } while (1);
}
function* sub_13319() {
    if (memory16get(ds*16+0x9134) != 0x0000)
        return;
    push(r16[di]);
    yield* sub_12BCC();
    r16[di] = pop();
    return;
}
function* sub_13326() {
    var cs = _seg000;
    push(r16[si]);
    push(r16[di]);
    memory16set(ds*16+0x8E8A, 0x0006);
    yield* sub_11022();
    r16[di] = 0x9096;
    yield* sub_1077C();
    memory16set(ds*16+r16[si], 0x000c);
    memory16set(ds*16+r16[si] + 2, 0x3998);
    memory16set(ds*16+r16[si] + 4, r16[dx]);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    memory16set(ds*16+r16[si] + 22, r16[bx]);
    r16[ax] = memory16get(cs*16+bp);
    memory16set(ds*16+r16[si] + 12, r16[ax]);
    r16[ax] = memory16get(cs*16+bp + 2);
    memory16set(ds*16+r16[si] + 14, r16[ax]);
    bp += 0x0004;
    memory16set(ds*16+r16[si] + 16, bp);
    r16[di] = pop();
    r16[si] = pop();
}
function* loc_13360() {
    r16[bx] = 0x3377;
    yield* sub_13389();
    r16[ax] = memory16get(ds*16+r16[si] + 66);
    memory16set(ds*16+r16[si] + 34, r16[ax]);
    memory16set(ds*16+r16[si] + 66, 0x0003);
    memory16set(ds*16+r16[si] + 54, 0x0000);
    return;
    _STOP_("db 64h, 3 dup(0), 0Bh, 48h, 53h, 8, 61h, 1...");
    _STOP_("db 6 dup(0)");
}
function* sub_13389() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[si];
        r16[cx] = memory16get(ds*16+r16[di] + 4);
        memory16set(ds*16+0xFCFA, 0x0000);
        if (r16[cx] == 0) {
            pc = 0x13398;
            break;
        }
        pc = 0x1339B;
        break;
    case 0x13398:
        return;
    case 0x1339B:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        bp = r16[bx];
        memory16set(ds*16+0xFCDA, r16[si]);
    case 0x133AC:
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 4);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 6);
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 8);
        memory16set(ds*16+r16[si] + 6, r16[ax]);
        push(r16[bx]);
        r16[bx] = memory16get(cs*16+bp + 10);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        r16[bx] = pop();
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        memory16set(ds*16+r16[si] + 20, 0x0000);
        memory16set(ds*16+r16[si] + 22, 0x0000);
        memory16set(ds*16+r16[si] + 24, 0x0000);
        memory16set(ds*16+r16[si] + 28, 0x0000);
        memory16set(ds*16+r16[si] + 30, 0x0000);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[si] + 52, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0x0000);
        if (memory16gets(ds*16+r16[di] + 8) >= signed16(0x0064)) {
            pc = 0x13426;
            break;
        }
        memory16set(ds*16+0xFCFA, -memory16get(ds*16+0xFCFA));
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        memory16set(ds*16+0xFCFA, -memory16get(ds*16+0xFCFA));
        memory16set(ds*16+r16[si] + 18, 0x0000);
    case 0x13426:
        if (r16[si] == memory16get(ds*16+0xFCDA)) {
            pc = 0x13433;
            break;
        }
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) - r16[ax]);
    case 0x13433:
        push(r16[bx]);
        r16[bx] = memory16get(ds*16+r16[di] + 6);
        r16[bx] -= 1;
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + -8656 + 65536);
        memory16set(ds*16+r16[si] + 56, r16[bx]);
        if (memory16get(ds*16+r16[bx]) != 0x000a) {
            pc = 0x13461;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 4);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        if (memory16gets(ds*16+r16[di] + 8) < signed16(0x0064)) {
            pc = 0x1345E;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[ax]);
    case 0x1345E:
        r16[bx] += 0x0006;
    case 0x13461:
        memory16set(ds*16+r16[si] + 58, r16[bx]);
        r16[bx] = pop();
        r16[ax] = memory16get(ds*16+r16[di] + 12);
        memory16set(ds*16+r16[si] + 66, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 10);
        xchg8(al, ah);
        memory16set(ds*16+r16[si] + 72, r16[ax]);
        yield* sub_14191();
        memory[ds*16+r16[si] + 72] = r8[al];
        r16[ax] = memory16get(ds*16+0x8E78);
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EB2);
        memory16set(ds*16+r16[si] + 54, r16[ax]);
        r8[al] = memory[cs*16+bp + 14];
        memory[ds*16+r16[si] + 39] = r8[al];
        if (memory[ds*16+r16[si] + 39] != 0x00) {
            pc = 0x1349E;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8E76);
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EB0);
        memory16set(ds*16+r16[si] + 54, r16[ax]);
    case 0x1349E:
        r8[al] = memory[cs*16+bp + 15];
        memory[ds*16+r16[si] + 38] = r8[al];
        yield* sub_13589();
        r16[ax] = memory16get(ds*16+0xFCDA);
        memory16set(ds*16+r16[si] + 68, r16[ax]);
        bp += 0x0010;
        if (memory16get(cs*16+bp + 0) == 0x0000) {
            pc = 0x134C8;
            break;
        }
        push(r16[di]);
        r16[di] = r16[si];
        yield* sub_11022();
        memory16set(ds*16+r16[di] + 70, r16[si]);
        yield* sub_1077C();
        r16[di] = pop();
        pc = 0x133AC;
        break;
    case 0x134C8:
        r16[ax] = memory16get(ds*16+r16[di] + 8);
    case 0x134CB:
        if (r16s[ax] < signed16(0x0064)) {
            pc = 0x134D5;
            break;
        }
        r16[ax] -= 0x0064;
        pc = 0x134CB;
        break;
    case 0x134D5:
        memory16set(ds*16+0xFCFA, memory16get(ds*16+0xFCFA) + r16[ax]);
        memory16set(ds*16+r16[si] + 70, 0x0000);
        if (--r16[cx]) {
            pc = 0x134E2;
            break;
        }
        pc = 0x134E5;
        break;
    case 0x134E2:
        pc = 0x1339B;
        break;
    case 0x134E5:
        r16[ax] = memory16get(ds*16+0x8EB2);
        if (memory[ds*16+r16[si] + 39] != 0x00) {
            pc = 0x134F1;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8EB0);
    case 0x134F1:
        r16[bx] = 0x8e8c;
        r16[cx] = 0x0008;
    case 0x134F7:
        if (r16[ax] == memory16get(ds*16+r16[bx])) {
            pc = 0x13502;
            break;
        }
        r16[bx] += 0x0004;
        if (--r16[cx]) {
            pc = 0x134F7;
            break;
        }
        pc = 0x1350A;
        break;
    case 0x13502:
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        memory16set(ds*16+r16[bx] + 2, memory16get(ds*16+r16[bx] + 2) + r16[ax]);
        return;
    case 0x1350A:
        r16[bx] = 0x8e8c;
        r16[cx] = 0x0008;
    case 0x13510:
        if (memory16get(ds*16+r16[bx]) == 0x0000) {
            pc = 0x1351C;
            break;
        }
        r16[bx] += 0x0004;
        if (--r16[cx]) {
            pc = 0x13510;
            break;
        }
        return;
    case 0x1351C:
        memory16set(ds*16+r16[bx], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        memory16set(ds*16+r16[bx] + 2, r16[ax]);
        memory16set(ds*16+0x91AC, memory16get(ds*16+0x91AC) + 1);
        return;
    } while (1);
}
function* sub_13529() {
    yield* sub_11022();
    push(r16[di]);
    r16[di] = 0x904a;
    yield* sub_1077C();
    r16[di] = pop();
    yield* loc_13541();
}
function* loc_13536() {
    yield* sub_11022();
    push(r16[di]);
    r16[di] = 0x90e2;
    yield* sub_1077C();
    r16[di] = pop();
    yield* loc_13541();
}
function* loc_13541() {
    memory16set(ds*16+r16[si], r16[ax]);
    memory16set(ds*16+r16[si] + 2, r16[bx]);
    memory16set(ds*16+r16[si] + 4, 0x0761);
    memory16set(ds*16+r16[si] + 72, 0x0000);
    r16[bx] = memory16get(ds*16+r16[di] + 8);
    r16[bx] -= 0x0008;
    memory16set(ds*16+r16[si] + 18, r16[bx]);
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] &= 0x00fe;
    r16[ax] = memory16get(ds*16+r16[di] + 10);
    r16[ax] -= 0x0008;
    memory16set(ds*16+r16[si] + 22, r16[ax]);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[dx] = 0x0028;
    _mul(r16[dx]);
    r16[ax] += r16[bx];
    memory16set(ds*16+r16[si] + 56, r16[ax]);
    memory16set(ds*16+r16[si] + 26, 0x0000);
    memory16set(ds*16+r16[si] + 34, 0x0000);
}
function* sub_13589() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(r16[di]);
        r16[di] = memory16get(ds*16+r16[si] + 12);
        r16[di] -= 0x0008;
        r16[ax] = _seg007;
        if (!(r16[di] & 0x0001)) {
            pc = 0x1359E;
            break;
        }
        r16[di] -= 1;
        r16[ax] = _seg008;
    case 0x1359E:
        es = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] = r16[ax] + memory16get(es*16+r16[di]);
        r16[ax] = r16[ax] - memory16get(es*16+r16[di] + 8);
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] = r16[ax] + memory16get(es*16+r16[di] + 4);
        r16[ax] -= 1;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] + memory16get(es*16+r16[di] + 2);
        r16[ax] = r16[ax] - memory16get(es*16+r16[di] + 10);
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] = r16[ax] + memory16get(es*16+r16[di] + 6);
        r16[ax] -= 1;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        r16[di] = pop();
        es = pop();
        return;
    } while (1);
}
function* loc_135CE() {
    r16[ax] = memory16get(ds*16+r16[si] + 8);
    memory16set(ds*16+0x91A2, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 10);
    memory16set(ds*16+0x91A4, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si]);
    memory16set(ds*16+0x91A6, r16[ax]);
    r16[ax] = memory16get(ds*16+0x915A);
    memory16set(ds*16+0x9166, r16[ax]);
    r16[ax] = memory16get(ds*16+0x915C);
    memory16set(ds*16+0x9168, r16[ax]);
}
function* sub_135EB() {
    if (memory16get(ds*16+0x9162) != 0x0000)
        _STOP_("goto locret_13614");
    yield* sub_135F2();
}
function* sub_135F2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x9134;
        r16[si] = 0x916a;
        r16[cx] = 0x0007;
    case 0x135FB:
        r16[ax] = memory16get(ds*16+r16[di]);
        memory16set(ds*16+r16[si], r16[ax]);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x13609;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 2);
        r16[ax] = memory16get(ds*16+r16[bx] + 52);
    case 0x13609:
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[si] += 0x0004;
        r16[di] += 0x0004;
        if (--r16[cx]) {
            pc = 0x135FB;
            break;
        }
        return;
    } while (1);
}
function* sub_13615() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0xd274;
        r16[bx] = memory16get(ds*16+0x9192);
        r16[cx] = memory16get(ds*16+0x9190);
    case 0x13620:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (r16s[ax] < 0) {
            pc = 0x13643;
            break;
        }
        if (r16s[bx] <= r16s[ax]) {
            pc = 0x1363E;
            break;
        }
        if (r16s[cx] > r16s[ax]) {
            pc = 0x1363E;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        push(r16[si]);
        yield* sub_10FB4();
        r16[si] = pop();
        r16[bx] = memory16get(ds*16+0x9192);
        r16[cx] = memory16get(ds*16+0x9190);
    case 0x1363E:
        r16[si] += 0x000e;
        pc = 0x13620;
        break;
    case 0x13643:
        if (r16s[cx] >= r16s[bx])
            return;
        memory16set(ds*16+0x9192, r16[cx]);
        r16[si] = 0xda9e;
        r16[bx] = memory16get(ds*16+0x9194);
        r16[cx] = memory16get(ds*16+0x9190);
    case 0x13656:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (r16s[ax] < 0) {
            pc = 0x13679;
            break;
        }
        if (r16s[bx] <= r16s[ax]) {
            pc = 0x13674;
            break;
        }
        if (r16s[cx] > r16s[ax]) {
            pc = 0x13674;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        push(r16[si]);
        yield* sub_10FD2();
        r16[si] = pop();
        r16[bx] = memory16get(ds*16+0x9194);
        r16[cx] = memory16get(ds*16+0x9190);
    case 0x13674:
        r16[si] += 0x000e;
        pc = 0x13656;
        break;
    case 0x13679:
        if (r16s[cx] >= r16s[bx])
            return;
        memory16set(ds*16+0x9194, r16[cx]);
        return;
    } while (1);
}
function* sub_13682() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = memory16get(ds*16+0x8FBC);
        yield* sub_136FC();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_136FC();
        r16[si] = memory16get(ds*16+0x9008);
        r8[al] = memory[ds*16+0x8F5B];
        memory[ds*16+0x8FAE] = r8[al];
        memory[ds*16+0x8F5B] = 0x00;
        yield* sub_136FC();
        r16[si] = memory16get(ds*16+0x90A0);
        yield* sub_136FC();
        r16[si] = memory16get(ds*16+0x90EC);
        yield* sub_136FC();
        r16[si] = memory16get(ds*16+0x8FBC);
        yield* sub_1370B();
        r16[si] = memory16get(ds*16+0x9008);
        yield* sub_1370B();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_1370B();
        r16[si] = memory16get(ds*16+0x90A0);
        yield* sub_1370B();
        r16[si] = memory16get(ds*16+0x90EC);
        yield* sub_1370B();
        r16[si] = 0x8e8c;
        r16[cx] = 0x0008;
    case 0x136D9:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x136F6;
            break;
        }
        r16[di] = memory16get(ds*16+0x9054);
    case 0x136E3:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x136F2;
            break;
        }
        if (r16[ax] == memory16get(ds*16+r16[di] + 54)) {
            pc = 0x136F6;
            break;
        }
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x136E3;
        break;
    case 0x136F2:
        memory16set(ds*16+r16[si], 0x0000);
    case 0x136F6:
        r16[si] += 0x0004;
        if (--r16[cx]) {
            pc = 0x136D9;
            break;
        }
        return;
    } while (1);
}
function* sub_136FC() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x136FC:
        if (memory16get(ds*16+r16[si]) == 0x0000)
            return;
        push(memory16get(ds*16+r16[si] + 10));
        yield* indirectCall(ds, memory16get(ds*16+r16[si] + 2));
        r16[si] = pop();
        pc = 0x136FC;
        break;
        return;
    } while (1);
}
function* sub_1370B() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1370B:
        if (memory16get(ds*16+r16[si]) == 0x0000)
            return;
        push(memory16get(ds*16+r16[si] + 10));
        yield* indirectCall(ds, memory16get(ds*16+r16[si] + 4));
        r16[si] = pop();
        pc = 0x1370B;
        break;
        return;
    } while (1);
}
function* sub_1371A() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1371A:
        if (memory16get(ds*16+r16[si]) == 0x0000)
            return;
        push(memory16get(ds*16+r16[si] + 10));
        if (memory[ds*16+r16[si] + 74] != 0x00) {
            pc = 0x1372D;
            break;
        }
        yield* sub_107A0();
        pc = 0x13739;
        break;
    case 0x1372D:
        if (memory[ds*16+r16[si] + 75] != 0x00) {
            pc = 0x13739;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - r16[ax]);
    case 0x13739:
        r16[si] = pop();
        pc = 0x1371A;
        break;
        return;
    } while (1);
}
function* sub_1373D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = memory16get(ds*16+0x9054);
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x13743:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x1375B;
            break;
        }
        if (r16[ax] == 0x0050) {
            pc = 0x13754;
            break;
        }
        if (r16[ax] == 0x0054) {
            pc = 0x13754;
            break;
        }
        r16[cx] += 1;
    case 0x13754:
        yield* sub_11689();
        r16[si] = r16[di];
        pc = 0x13743;
        break;
    case 0x1375B:
        memory16set(ds*16+0x8F32, r16[cx]);
        return;
    } while (1);
}
function* sub_13760() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x13760:
        if (memory16get(ds*16+r16[si]) == 0x0000)
            return;
        push(memory16get(ds*16+r16[si] + 10));
        yield* sub_107A0();
        r16[si] = pop();
        pc = 0x13760;
        break;
        return;
    } while (1);
}
function* sub_1376F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+0x90A0);
    case 0x13773:
        if (memory16get(ds*16+r16[di]) == 0x0000)
            return;
        if (memory16get(ds*16+r16[di]) != 0x0040) {
            pc = 0x13782;
            break;
        }
        if (r16[si] == memory16get(ds*16+r16[di] + 28))
            return;
    case 0x13782:
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x13773;
        break;
        return;
    } while (1);
}
function* sub_13788() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        if (memory16get(ds*16+r16[si]) != 0x0034) {
            pc = 0x1379D;
            break;
        }
        yield* sub_1376F();
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x1379D;
            break;
        }
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
    case 0x1379D:
        r16[di] = memory16get(ds*16+r16[si] + 6);
        memory16set(ds*16+r16[di], 0x0000);
        yield* sub_107C0();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_137A9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        if (memory16get(ds*16+r16[si]) != 0x0034) {
            pc = 0x137BE;
            break;
        }
        yield* sub_1376F();
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x137BE;
            break;
        }
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107A0();
        r16[si] = pop();
    case 0x137BE:
        r16[di] = memory16get(ds*16+r16[si] + 6);
        memory16set(ds*16+r16[di], 0x0000);
        yield* sub_107A0();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_137CA() {
    yield* sub_141B1();
    r16[di] = memory16get(ds*16+r16[si] + 68);
    r16[ax] = memory16get(ds*16+r16[di] + 18);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 22);
    memory16set(ds*16+r16[si] + 22, r16[ax]);
{yield* sub_13589(); return; };
}
function* sub_137DF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E80) == 0x0000) {
            pc = 0x137E7;
            break;
        }
        return;
    case 0x137E7:
        if (memory[ds*16+0x8FAE] == 0x00)
            return;
        r16[ax] = 0x0000;
        r16[bx] = 0xfff7;
        r16[cx] = 0x0000;
        r16[dx] = 0xfffa;
        bp = 0x12b8;
        yield* sub_145F4();
        return;
    } while (1);
}
function* loc_13809() {
    if (memory[ds*16+0x8FAE] == 0x00)
        return;
    r16[ax] = 0xfff7;
    r16[bx] = 0x0000;
    r16[cx] = 0xfffe;
    r16[dx] = 0xfffd;
    bp = 0x12b2;
    yield* sub_145F4();
    r16[ax] = 0x0009;
    r16[bx] = 0x0000;
    r16[cx] = 0x0002;
    r16[dx] = 0xfffd;
    bp = 0x12be;
    yield* sub_145F4();
    return;
}
function* sub_13835() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        if (memory16get(ds*16+0x991E) == 0x0000) {
            pc = 0x1384E;
            break;
        }
    {yield* loc_147A9(); return; };
    case 0x1384E:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        if (memory[ds*16+0x8FAE] == 0x00)
            return;
        memory16set(ds*16+r16[si] + 14, 0x0001);
        r16[ax] = 0x0000;
        r16[bx] = 0x0009;
        r16[cx] = 0x0000;
        r16[dx] = 0x0012;
        bp = 0x12c4;
        yield* sub_145F4();
        return;
    } while (1);
}
function* loc_1387A() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+r16[si] + 72) < 0 /*CHECK*/) {
            pc = 0x13883;
            break;
        }
        memory16set(ds*16+r16[si] + 72, memory16get(ds*16+r16[si] + 72) - 1);
    case 0x13883:
        if (memory[ds*16+0x8FAE] == 0x00)
            return;
        if (memory16gets(ds*16+r16[si] + 72) >= 0 /*CHECK*/)
            return;
        r16[di] = memory16get(ds*16+0x90A0);
    case 0x13894:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x138A3;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x0028)
            return;
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x13894;
        break;
    case 0x138A3:
        memory16set(ds*16+r16[si] + 72, 0x000f);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = 0x1170;
        memory16set(ds*16+r16[si], 0x0028);
        memory16set(ds*16+r16[si] + 2, 0x262d);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory[ds*16+r16[si] + 74] = 0xff;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] -= 0x000c;
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] += 0x0004;
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        memory16set(ds*16+r16[si] + 72, 0x0006);
        r16[si] = pop();
        return;
        if (memory16get(ds*16+0x8E80) == 0x0000) {
            pc = 0x13908;
            break;
        }
        return;
    case 0x13908:
        if (memory16gets(ds*16+r16[si] + 72) < 0 /*CHECK*/) {
            pc = 0x13911;
            break;
        }
        memory16set(ds*16+r16[si] + 72, memory16get(ds*16+r16[si] + 72) - 1);
    case 0x13911:
        if (memory[ds*16+0x8FAE] == 0x00)
            return;
        if (memory16gets(ds*16+r16[si] + 72) >= 0 /*CHECK*/)
            return;
        r16[di] = memory16get(ds*16+0x90A0);
    case 0x13922:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x13931;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x0048)
            return;
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x13922;
        break;
    case 0x13931:
        memory16set(ds*16+r16[si] + 72, 0x0012);
        memory16set(ds*16+0x8E88, 0x0000);
        push(r16[si]);
        r16[ax] = 0x0007;
    case 0x13940:
        push(r16[ax]);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[bx] = pop();
        push(r16[bx]);
        r16[bx] <<= 1;
        r16[di] = memory16get(ds*16+r16[bx] + 12874);
        memory16set(ds*16+r16[si], 0x0048);
        memory16set(ds*16+r16[si] + 2, 0x1ff3);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        memory[ds*16+r16[si] + 74] = 0xff;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        r16[ax] = memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 34, 0x0000);
        memory16set(ds*16+r16[si] + 26, 0x000d);
        r16[ax] = pop();
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] -= 0x0002;
        if (r16s[ax] >= 0) {
            pc = 0x13940;
            break;
        }
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_13998() {
    yield* sub_141B1();
}
function* sub_1399C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x9224] == 0x00) {
            pc = 0x139A6;
            break;
        }
        _STOP_("goto loc_13A2F");
    case 0x139A6:
        yield* sub_141B1();
        if (memory16get(ds*16+r16[si]) == 0x0004)
            _STOP_("goto nullsub_5");
        r16[dx] = memory16get(ds*16+r16[si] + 28);
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x0006;
    case 0x139B6:
        sar16(dx, 1);
        rcr16(ax, 1);
        if (--r16[cx]) {
            pc = 0x139B6;
            break;
        }
        flags.carry = (memory16get(ds*16+r16[si] + 20) + r16[ax]) >= 0x10000;
        memory16set(ds*16+r16[si] + 20, memory16get(ds*16+r16[si] + 20) + r16[ax]);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[dx] + flags.carry);
        if (memory16get(ds*16+r16[si] + 18) >= 0x0140) {
            pc = 0x139CF;
            break;
        }
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - 0x000c);
        if (memory16gets(ds*16+r16[si] + 22) >= 0)
            _STOP_("goto loc_139D3");
    case 0x139CF:
        yield* sub_107C0();
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_139D3() {
    var cs = _seg000;
    if (memory16get(ds*16+r16[si] + 34) == 0x0000)
        _STOP_("goto nullsub_5");
    yield* sub_13589();
    yield* sub_11BEA();
    if (flags.zero)
        _STOP_("goto nullsub_5");
    r16[ax] = memory16get(ds*16+r16[si] + 52);
    r16[ax] = r16[ax] + memory16get(cs*16+0x3DAC);
    yield* sub_107C0();
{yield* sub_13A36(); return; };
}
function* sub_139EE() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x9224] != 0x00) {
            pc = 0x13A2F;
            break;
        }
        yield* sub_141B1();
        r16[ax] = memory16get(ds*16+r16[si] + 28);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 18) >= 0x0138) {
            pc = 0x13A12;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 32);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 22) < 0x00c0) {
            pc = 0x13A16;
            break;
        }
    case 0x13A12:
        yield* sub_107C0();
        return;
    case 0x13A16:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        yield* sub_11CCC();
        if (flags.zero)
            return;
        r16[ax] = memory16get(ds*16+r16[si] + 52);
        r16[ax] = r16[ax] + memory16get(cs*16+0x3DAA);
        yield* sub_107C0();
    {yield* sub_13A36(); return; };
        return;
    case 0x13A2F:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_13A33() {
    r16[ax] = 0x007f;
    yield* sub_13A36();
}
function* sub_13A36() {
    yield* indirectCall(_seg000, memory16get(ds*16+r16[di]+6));
}
function* sub_13A39() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        r16[di] = memory16get(ds*16+r16[di] + 68);
        r16[bx] = r16[di];
    case 0x13A3F:
        memory16set(ds*16+r16[bx] + 4, 0x08b9);
        if (memory16get(ds*16+r16[bx] + 70) == 0x0000) {
            pc = 0x13A4F;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[bx] + 70);
        pc = 0x13A3F;
        break;
    case 0x13A4F:
        flags.carry2 = memory16get(ds*16+r16[di] + 36) > r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x13A8C;
            break;
        }
        push(memory16get(ds*16+r16[di] + 70));
    case 0x13A57:
        r16[bx] = pop();
        if (!(r16[bx] & r16[bx])) {
            pc = 0x13A89;
            break;
        }
        if (memorys[ds*16+r16[bx] + 38] < 0 /*CHECK*/) {
            pc = 0x13A7D;
            break;
        }
        push(r16[bx]);
        push(r16[si]);
        r16[si] = r16[bx];
        yield* sub_10EF5();
        r16[si] = pop();
        bp = 0x1230;
        if (memory[ds*16+r16[di] + 39] == 0x00) {
            pc = 0x13A76;
            break;
        }
        bp = 0x124c;
    case 0x13A76:
        r16[dx] = 0x0853;
        yield* sub_13326();
        r16[bx] = pop();
    case 0x13A7D:
        push(memory16get(ds*16+r16[bx] + 70));
        push(r16[si]);
        r16[si] = r16[bx];
        yield* sub_107C0();
        r16[si] = pop();
        pc = 0x13A57;
        break;
    case 0x13A89:
        yield* sub_13AB2();
    case 0x13A8C:
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_13A8E() {
    memory16set(ds*16+r16[di] + 4, 0x08b9);
}
function* sub_13A94() {
    memory16set(ds*16+r16[di] + 4, 0x08b9);
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_13A99() {
    if (memory16get(ds*16+r16[si]) == 0x0000)
        return;
    if (memory16get(ds*16+r16[si]) == 0x0008)
        return;
    yield* sub_107C0();
    return;
}
function* sub_13AA7() {
    memory16set(ds*16+r16[di] + 4, 0x08b9);
    flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
    memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
    if (flags.carry2)
        {
        yield* sub_13AB2();
    }
}
function* sub_13AB2() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_10EF5();
        r16[si] = pop();
        bp = 0x1230;
        if (memory[ds*16+r16[di] + 39] == 0x00) {
            pc = 0x13AC5;
            break;
        }
        bp = 0x124c;
    case 0x13AC5:
        r16[dx] = 0x0853;
        yield* sub_13326();
        r16[ax] = memory16get(ds*16+r16[di] + 54);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x13B41;
            break;
        }
        r16[bx] = 0x8e8c;
        r16[cx] = 0x0008;
    case 0x13AD8:
        if (r16[ax] == memory16get(ds*16+r16[bx])) {
            pc = 0x13AE3;
            break;
        }
        r16[bx] += 0x0004;
        if (--r16[cx]) {
            pc = 0x13AD8;
            break;
        }
        pc = 0x13B41;
        break;
    case 0x13AE3:
        memory16set(ds*16+r16[bx] + 2, memory16get(ds*16+r16[bx] + 2) - 1);
        if (memory16get(ds*16+r16[bx] + 2) != 0) {
            pc = 0x13B41;
            break;
        }
        memory16set(ds*16+r16[bx], 0x0000);
        push(r16[si]);
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = pop();
        r16[bx] = 0x11f2;
        memory16set(ds*16+r16[si], 0x0060);
        if (memory[ds*16+r16[di] + 39] == 0x00) {
            pc = 0x13B0C;
            break;
        }
        r16[bx] = 0x11b4;
        memory16set(ds*16+r16[si], 0x0018);
    case 0x13B0C:
        memory16set(ds*16+r16[si] + 26, 0x0007);
        memory16set(ds*16+r16[si] + 2, 0x28df);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        yield* sub_14191();
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[si] = pop();
    case 0x13B41:
        r16[ax] = memory16get(ds*16+r16[di] + 52);
        flags.carry = (memory16get(ds*16+0x9152) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0x9152, memory16get(ds*16+0x9152) + r16[ax]);
        memory16set(ds*16+0x9154, memory16get(ds*16+0x9154) + 0x0000 + flags.carry);
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_13B55() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_10EF5();
        r16[si] = pop();
        r16[dx] = 0x0853;
        bp = 0x1230;
        if (memory[ds*16+r16[di] + 39] == 0x00) {
            pc = 0x13B6B;
            break;
        }
        bp = 0x124c;
    case 0x13B6B:
        yield* sub_13326();
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_13B76() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x3bdf);
        flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x13B81;
            break;
        }
        return;
    case 0x13B81:
        r16[ax] = memory16get(ds*16+r16[di] + 52);
        flags.carry = (memory16get(ds*16+0x9152) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0x9152, memory16get(ds*16+0x9152) + r16[ax]);
        memory16set(ds*16+0x9154, memory16get(ds*16+0x9154) + 0x0000 + flags.carry);
        r16[ax] = memory16get(ds*16+r16[di] + 48);
        r16[ax] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 18);
        r16[bx] = memory16get(ds*16+r16[di] + 50);
        r16[bx] += 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+r16[di] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        bp = 0x124c;
        r16[dx] = 0x0853;
        yield* sub_13326();
        push(r16[si]);
        r16[bx] = memory16get(ds*16+r16[di] + 56);
        bp = memory16get(ds*16+r16[di] + 16);
        r16[si] = memory16get(ds*16+r16[di] + 50);
    case 0x13BBE:
        r16[cx] = memory16get(ds*16+r16[di] + 48);
        r16[cx] += 1;
        lea(dx, ds, r16[bx] + 40);
    case 0x13BC5:
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        bp += 0x0002;
        if (--r16[cx]) {
            pc = 0x13BC5;
            break;
        }
        r16[bx] = r16[dx];
        r16[si] -= 1;
        if (r16s[si] >= 0) {
            pc = 0x13BBE;
            break;
        }
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_13BDF() {
    memory16set(ds*16+r16[si] + 4, 0x0761);
    r16[ax] = memory16get(ds*16+r16[si] + 48);
    r16[ax] += 1;
    r16[bx] = memory16get(ds*16+r16[si] + 50);
    r16[bx] += 1;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[cx] = memory16get(ds*16+r16[si] + 18);
    r16[cx] >>= 1;
    push(r16[si]);
    r16[si] = memory16get(ds*16+r16[si] + 12);
    yield* sub_10963();
    r16[si] = pop();
}
function* sub_13C01() {
    var cs = _seg000;
    if (memory16get(ds*16+0x9164) != 0x0000)
        return;
    memory[ds*16+0x9224] = 0xff;
    memory16set(ds*16+0x9186, 0x0000);
    memory[ds*16+0x8FAF] = 0xff;
    memory16set(ds*16+0x8E88, 0x0006);
    memory16set(ds*16+0x8E8A, 0x0006);
    memory16set(ds*16+0x8E80, 0x0001);
    memory16set(ds*16+0x8E84, 0x0000);
    bp = 0x1264;
    r16[ax] = memory16get(cs*16+bp);
    memory16set(ds*16+0x9F0C, r16[ax]);
    r16[ax] = memory16get(cs*16+bp + 2);
    memory16set(ds*16+0x9F0E, r16[ax]);
    bp += 0x0004;
    memory16set(ds*16+0x9F10, bp);
    memory16set(ds*16+0x9F04, 0x0853);
    return;
}
function* sub_13C4F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x8F56] != 0x00)
            return;
        if (memory16get(ds*16+0x9164) != 0x0000)
            return;
        if (memory[ds*16+0x9223] == 0x00) {
            pc = 0x13C66;
            break;
        }
        r16[ax] >>= 1;
    case 0x13C66:
        memory[ds*16+0x8FAF] = 0xff;
        flags.carry2 = memory16get(ds*16+0x9186) > r16[ax];
        memory16set(ds*16+0x9186, memory16get(ds*16+0x9186) - r16[ax]);
        if (flags.carry2)
            return;
        // std::cout << "----- skip die\n";
        memory16set(ds*16+0x9186, 0x27);
        //yield* sub_13C01();
        return;
    } while (1);
}
function* sub_13C75() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_16058();
        memory[ds*16+0x8F54] = 0x00;
        memory16set(ds*16+0x8E6E, 0x0001);
        memory[ds*16+0x8F55] = 0x00;
        memory[ds*16+0x8F56] = 0x00;
        memory16set(_ss*16+16, 0x00bf);
        yield* sub_1426A();
        memory16set(ds*16+0x8E70, 0x0001);
    case 0x13C9D:
        sp = memory16get(ds*16+0x8E6A);
        yield* sub_10D5F();
        memory[ds*16+0x8F58] = 0x00;
        memory[ds*16+0x8F59] = 0x00;
        memory[ds*16+0x8F5B] = 0x00;
        memory16set(ds*16+0x8E88, 0x0000);
        memory16set(ds*16+0x8E8A, 0x0000);
        yield* sub_15863();
        yield* sub_15B21();
        yield* sub_10D5F();
        memory16set(ds*16+0x991C, 0x0001);
        memory[ds*16+0x3550] = 0x31;
        yield* sub_15CC5();
        yield* sub_11827();
        yield* sub_11B43();
        memory[ds*16+0x3727] = 0x31;
        if (memory[ds*16+0x8F5D] != 0x00) {
            pc = 0x13CED;
            break;
        }
        memory[ds*16+0x3727] = 0x32;
    case 0x13CED:
        r16[si] = 0x3715;
        memory[ds*16+0x374E] = 0xff;
        yield* sub_15926();
        memory[ds*16+0x374E] = 0x00;
        yield* sub_10D5F();
        if (memory[ds*16+0x8F54] == 0x00) {
            pc = 0x13D0D;
            break;
        }
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
    case 0x13D0D:
        yield* sub_10985();
        yield* sub_1080F();
        yield* sub_10A2F();
        yield* sub_10E2B();
        yield* sub_10D81();
        memory[ds*16+0x8F59] = 0x00;
        memory[ds*16+0x8F5B] = 0x00;
    case 0x13D26:
        memory16set(ds*16+0x919C, memory16get(ds*16+0x919C) + 1);
        r16[ax] = memory16get(ds*16+0x919C);
        r16[ax] &= 0x0003;
        if (r16[ax] != 0) {
            pc = 0x13D47;
            break;
        }
        r16[ax] = memory16get(ds*16+0x91AC);
        memory16set(ds*16+0x8EB0, r16[ax]);
        r16[ax] = memory16get(ds*16+0x91AC);
        memory16set(ds*16+0x8EB2, r16[ax]);
        memory16set(ds*16+0x8EB2, memory16get(ds*16+0x8EB2) + 1);
        memory16set(ds*16+0x91AC, memory16get(ds*16+0x91AC) + 0x0002);
    case 0x13D47:
        yield* sub_10985();
        memory16set(ds*16+0x919A, 0x0001);
        yield* sub_10E4D();
        yield* sub_10BA5();
        yield* sub_1373D();
        yield* sub_10FF0();
        yield* sub_13682();
        yield* sub_1080F();
        yield* sub_14675();
        yield* sub_10A95();
        yield* sub_13615();
        r8[al] = memory[ds*16+0x8F58];
        if (r8[al] & r8[al]) {
            pc = 0x13D75;
            break;
        }
        pc = 0x13E1A;
        break;
    case 0x13D75:
        memory[ds*16+0x8F58] = 0x00;
        r16[si] = 0x3d8f;
        memory[cs*16+0x3D9B] = r8[al];
    case 0x13D81:
        if (r8[al] == memory[cs*16+r16[si]]) {
            pc = 0x13D8B;
            break;
        }
        r16[si] += 0x0003;
        pc = 0x13D81;
        break;
    case 0x13D8B:
        _STOP_("goto word ptr cs:[si+1]");
        _STOP_("db 19h");
        _STOP_("db 1Ch");
        _STOP_("db  17h");
        _STOP_("byte_13D9B db 0");
        _STOP_("db 9");
        _STOP_("unk_13DA4 db    2");
        _STOP_("word_13DAA dw 1");
        _STOP_("word_13DAC dw 1");
        r16[ax] = r16[ax] + memory16get(ds*16+r16[bx] + r16[si]);
        memory[ds*16+r16[bx] + r16[si]] |= r8[al];
        r8[al] += 0x00;
    case 0x13DB4:
        r8[al] = memory[ds*16+0x8F57];
        memory[ds*16+0x8F56] = memory(ds, 0x8F56) ^ r8[al];
        pc = 0x13E1A;
        break;
    case 0x13DBD:
        if (memory[ds*16+0x9224] != 0x00) {
            pc = 0x13E1A;
            break;
        }
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x13DF0;
            break;
        }
        if (memory16get(ds*16+0x9160) == 0x0000) {
            pc = 0x13E1A;
            break;
        }
        memory16set(ds*16+0x8E82, 0x0001);
        memory16set(ds*16+0x8E88, 0x0018);
        memory16set(ds*16+0x8E80, 0x0001);
        memory16set(ds*16+0x9160, memory16get(ds*16+0x9160) - 1);
        memory16set(ds*16+0x8E84, 0x0088);
        pc = 0x13E1A;
        break;
    case 0x13DF0:
        memory16set(ds*16+0x8E84, 0x0001);
        pc = 0x13E1A;
        break;
    case 0x13DF8:
        memory[ds*16+0x8F5B] = 0x00;
    case 0x13DFD:
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x13E10;
            break;
        }
        if (memory[ds*16+0x8F58] != 0x00) {
            pc = 0x13E10;
            break;
        }
        yield* sub_160A5();
        pc = 0x13DFD;
        break;
    case 0x13E10:
        memory[ds*16+0x8F58] = 0x00;
        memory[ds*16+0x8F5B] = 0x00;
    case 0x13E1A:
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCFE, r16[ax]);
        r16[ax] = memory16get(ds*16+0x919A);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        if (r16[ax] == memory16get(ds*16+0x918C)) {
            pc = 0x13E46;
            break;
        }
        memory16set(ds*16+0x91A0, memory16get(ds*16+0x91A0) + 1);
        if (memory16gets(ds*16+0x91A0) < signed16(0x0023)) {
            pc = 0x13E4C;
            break;
        }
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) << 1);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0x919A, r16[ax]);
        pc = 0x13E4C;
        break;
    case 0x13E46:
        memory16set(ds*16+0x91A0, 0x0000);
    case 0x13E4C:
        r16[ax] = memory16get(ds*16+0x9196);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x918E);
        memory16set(ds*16+0xFCEA, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCEE, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) - r16[ax]);
        r16[ax] = memory16get(ds*16+0x91A8);
        if (memory16gets(ds*16+0xFCEE) >= r16s[ax]) {
            pc = 0x13E82;
            break;
        }
        r16[ax] = memory16get(ds*16+0x91A8);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x91A8);
        memory16set(ds*16+0xFCEE, r16[ax]);
    case 0x13E82:
        r16[ax] = memory16get(ds*16+0x91AA);
        if (memory16gets(ds*16+0xFCEE) <= r16s[ax]) {
            pc = 0x13E9F;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x91AA);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0x91AA);
        memory16set(ds*16+0xFCEE, r16[ax]);
    case 0x13E9F:
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        if (memory16gets(ds*16+0xFCE6) < 0) {
            pc = 0x13EBB;
            break;
        }
        if (memory16gets(ds*16+0xFCE6) < signed16(0x0010)) {
            pc = 0x13EC5;
            break;
        }
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - 0x0010);
        memory16set(ds*16+0xFCEA, memory16get(ds*16+0xFCEA) + 0x0028);
        pc = 0x13EC5;
        break;
    case 0x13EBB:
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + 0x0010);
        memory16set(ds*16+0xFCEA, memory16get(ds*16+0xFCEA) - 0x0028);
    case 0x13EC5:
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0x9198, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x9196, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEA);
        memory16set(ds*16+0x918E, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+0x9190, r16[ax]);
        r16[ax] = memory16get(ds*16+0x91AA);
        if (memory16get(ds*16+0xFCFE) != r16[ax]) {
            pc = 0x13EED;
            break;
        }
        if (memory[ds*16+0x8F59] & 0x02) {
            pc = 0x13EF4;
            break;
        }
    case 0x13EED:
        r16[ax] = memory16get(ds*16+0x91AE);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) + r16[ax]);
    case 0x13EF4:
        r16[ax] = memory16get(ds*16+0x91AA);
        if (memory16gets(ds*16+0xFCEE) > r16s[ax]) {
            pc = 0x13F03;
            break;
        }
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+0x91AA, r16[ax]);
    case 0x13F03:
        yield* sub_10A2F();
        yield* sub_10D81();
        if (memory[ds*16+0x8F5C] != 0x00) {
            pc = 0x13F13;
            break;
        }
        pc = 0x13FAA;
        break;
    case 0x13F13:
        memory[ds*16+0x8F5C] = 0x00;
        memory16set(ds*16+0x9132, 0x0001);
        memory16set(ds*16+0x9186, 0x0027);
        memory[ds*16+0x8FAF] = 0xff;
        memory16set(ds*16+0x918A, memory16get(ds*16+0x918A) - 1);
        yield* sub_10E91();
        if (memory16get(ds*16+0x918A) != 0x0000) {
            pc = 0x13F9A;
            break;
        }
        yield* sub_10D5F();
        yield* sub_159C8();
        yield* sub_10D5F();
        memory16set(ds*16+0x91B0, memory16get(ds*16+0x91B0) - 1);
        if (memory16get(ds*16+0x91B0) == 0) {
            pc = 0x13F7B;
            break;
        }
        yield* sub_15C0F();
        if (_FIXME_) {
            pc = 0x13F7B;
            break;
        }
        memory16set(ds*16+0x918A, 0x0003);
        yield* sub_10E91();
        memory16set(ds*16+0x9152, 0x0000);
        memory16set(ds*16+0x9154, 0x0000);
        r16[di] = 0x921c;
        r16[cx] = 0x0007;
        r8[al] = r8[al] ^ r8[al];
        rep_stosb_data_forward();
        memory16set(ds*16+0x9156, 0x0000);
        memory16set(ds*16+0x9158, 0x0000);
        yield* sub_10E6F();
        pc = 0x13F9A;
        break;
    case 0x13F7B:
        r16[si] = 0x3729;
        r16[cx] = 0x001e;
        yield* sub_15926();
        r16[bx] = memory16get(ds*16+0x8E7A);
        memory[ds*16+r16[bx] + -28835 + 65536] = 0x00;
        r16[bx] = r16[bx] ^ 0x0001;
        if (memory[ds*16+r16[bx] + -28835 + 65536] != 0x00) {
            pc = 0x13F9A;
            break;
        }
        pc = 0x13C9D;
        break;
    case 0x13F9A:
        yield* sub_11A62();
        if (memory[ds*16+0x8F54] == 0x00) {
            pc = 0x13FAA;
            break;
        }
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
    case 0x13FAA:
        if (memory16get(ds*16+0x9164) == 0x0000) {
            pc = 0x13FB4;
            break;
        }
        pc = 0x13D26;
        break;
    case 0x13FB4:
        if (memory[ds*16+0x8FB0] != 0x00) {
            pc = 0x13FC8;
            break;
        }
        if (memory[ds*16+0x8F61] == 0x00) {
            pc = 0x13FC5;
            break;
        }
        pc = 0x140A7;
        break;
    case 0x13FC5:
        pc = 0x13D26;
        break;
    case 0x13FC8:
        r8[ah] = 0x01;
        interrupt(128);
        if (memory16gets(ds*16+0x9190) > signed16(0x01e0)) {
            pc = 0x1400D;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8EAC);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x8F4A, r16[ax]);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + 0x0190);
        if (memory16get(ds*16+0x915C) != 0x0000) {
            pc = 0x1403E;
            break;
        }
        r16[ax] = memory16get(ds*16+0x915A);
        if (memory16gets(ds*16+0xFCE6) <= r16s[ax]) {
            pc = 0x1403E;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x0003;
        r16[dx] = 0x0032;
        _mul(r16[dx]);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x915A, r16[ax]);
        pc = 0x1403E;
        break;
    case 0x1400D:
        r16[ax] = memory16get(ds*16+0x8EAE);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x8F4A, r16[ax]);
        if (memory16get(ds*16+0x915C) != 0x0000) {
            pc = 0x1403E;
            break;
        }
        r16[ax] = memory16get(ds*16+0x915A);
        if (memory16gets(ds*16+0xFCE6) <= r16s[ax]) {
            pc = 0x1403E;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x0003;
        r16[dx] = 0x0032;
        _mul(r16[dx]);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x915A, r16[ax]);
    case 0x1403E:
        memory[ds*16+0x9223] = 0x00;
        memory[ds*16+0x8FB1] = 0x00;
        if (memory16gets(ds*16+0x9190) > signed16(0x03c0)) {
            pc = 0x14078;
            break;
        }
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14078;
            break;
        }
        memory[ds*16+0x8FB1] = 0xff;
        if (memory16get(ds*16+0x8E70) != 0x0002) {
            pc = 0x14078;
            break;
        }
        r16[bx] = memory16get(ds*16+0x8E7A);
        r16[bx] = r16[bx] ^ 0x0001;
        if (memory[ds*16+r16[bx] + -28835 + 65536] == 0x00) {
            pc = 0x14078;
            break;
        }
        if (memory[ds*16+r16[bx] + -28833 + 65536] == 0x00) {
            pc = 0x1407E;
            break;
        }
    case 0x14078:
        yield* sub_14A69();
        yield* sub_10E91();
    case 0x1407E:
        memory[ds*16+0x8FB0] = 0x00;
        if (memory16get(ds*16+0x9162) == 0x0000) {
            pc = 0x1408D;
            break;
        }
        yield* sub_12B22();
    case 0x1408D:
        if (memory[ds*16+0x8F61] != 0x00) {
            pc = 0x140A7;
            break;
        }
        if (memory[ds*16+0x8F54] != 0x00) {
            pc = 0x1409E;
            break;
        }
        pc = 0x13D26;
        break;
    case 0x1409E:
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
        pc = 0x13D26;
        break;
    case 0x140A7:
        memory[ds*16+0x8F61] = 0x00;
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x140CB;
            break;
        }
    case 0x140B3:
        r16[si] = memory16get(ds*16+0x9008);
        if (memory16get(ds*16+r16[si]) == 0x0000) {
            pc = 0x140C1;
            break;
        }
        yield* sub_137A9();
        pc = 0x140B3;
        break;
    case 0x140C1:
        yield* sub_13319();
        yield* sub_135EB();
        memory16set(ds*16+0x91B0, memory16get(ds*16+0x91B0) + 1);
    case 0x140CB:
        r16[bx] = memory16get(ds*16+0x8E7A);
        r16[bx] = r16[bx] ^ 0x0001;
        if (memory[ds*16+r16[bx] + -28835 + 65536] == 0x00) {
            pc = 0x14116;
            break;
        }
        if (memory[ds*16+r16[bx] + -28833 + 65536] != 0x00) {
            pc = 0x14116;
            break;
        }
        r16[bx] = r16[bx] ^ 0x0001;
        memory[ds*16+r16[bx] + -28833 + 65536] = 0xff;
        yield* sub_118F5();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_13760();
        r16[si] = memory16get(ds*16+0x90EC);
        yield* sub_13760();
        r16[si] = memory16get(ds*16+0x90A0);
        yield* sub_13760();
        yield* sub_11A65();
        if (memory[ds*16+0x8F54] != 0x00) {
            pc = 0x1410D;
            break;
        }
        pc = 0x13D26;
        break;
    case 0x1410D:
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
        pc = 0x13D26;
        break;
    case 0x14116:
        yield* sub_10D5F();
        yield* sub_118F5();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_13760();
        r16[si] = memory16get(ds*16+0x90EC);
        yield* sub_13760();
        r16[si] = memory16get(ds*16+0x90A0);
        yield* sub_13760();
        memory16set(ds*16+0x991C, memory16get(ds*16+0x991C) + 1);
        if (memory16gets(ds*16+0x991C) < signed16(0x0006)) {
            pc = 0x14146;
            break;
        }
        memory16set(ds*16+0x991C, 0x0001);
        memory16set(ds*16+0x991A, memory16get(ds*16+0x991A) + 1);
    case 0x14146:
        r16[ax] = memory16get(ds*16+0x991C);
        r16[ax] += 0x0030;
        memory[ds*16+0x3550] = r8[al];
        yield* sub_15CC5();
        yield* sub_1193C();
        if (memory16get(ds*16+0x9162) == 0x0000) {
            pc = 0x1415F;
            break;
        }
        yield* sub_12B22();
    case 0x1415F:
        yield* sub_11B43();
        memory[ds*16+0x8F5F] = 0x00;
        memory[ds*16+0x8F60] = 0x00;
        yield* sub_11A62();
        yield* sub_10985();
        yield* sub_1080F();
        yield* sub_10A2F();
        yield* sub_10E2B();
        yield* sub_10D81();
        if (memory[ds*16+0x8F54] != 0x00) {
            pc = 0x14188;
            break;
        }
        pc = 0x13D26;
        break;
    case 0x14188:
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
        pc = 0x13D26;
        break;
        return;
    } while (1);
}
function* sub_14191() {
    push(r16[dx]);
    r16[ax] = 0x6255;
    _mul(memory16get(ds*16+0x304A));
    r16[ax] += 0x3619;
    memory16set(ds*16+0x304A, r16[ax]);
    r16[dx] = pop();
}
function* sub_141A1() {
    push(r16[dx]);
    push(r16[cx]);
    push(r16[ax]);
    yield* sub_14191();
    r16[dx] = r16[dx] ^ r16[dx];
    r16[cx] = pop();
    div(r16[cx]);
    r16[ax] = r16[dx];
    r16[cx] = pop();
    r16[dx] = pop();
}
function* sub_141B1() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 14, memory16get(ds*16+r16[si] + 14) - 1);
        if (memory16gets(ds*16+r16[si] + 14) < 0) {
            pc = 0x141DC;
            break;
        }
        if (memory16get(ds*16+r16[si] + 14) != 0)
            return;
        r16[di] = memory16get(ds*16+r16[si] + 16);
        r16[ax] = memory16get(cs*16+r16[di]);
        r16[di] += 0x0002;
        if (r16[ax] & r16[ax]) {
            pc = 0x141CC;
            break;
        }
        r16[di] += 0x0002;
        yield* indirectCall(cs, memory16get(cs*16+r16[di]-2));
        return;
    case 0x141CC:
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        memory16set(ds*16+r16[si] + 16, r16[di]);
        return;
    case 0x141DC:
        memory16set(ds*16+r16[si] + 14, 0x0000);
        return;
    } while (1);
}
function* sub_141E2() {
    var cs = _seg000;
    r16[di] = memory16get(cs*16+r16[di]);
    r16[ax] = memory16get(cs*16+r16[di]);
    r16[di] += 0x0002;
    memory16set(ds*16+r16[si] + 12, r16[ax]);
    r16[ax] = memory16get(cs*16+r16[di]);
    r16[di] += 0x0002;
    memory16set(ds*16+r16[si] + 14, r16[ax]);
    memory16set(ds*16+r16[si] + 16, r16[di]);
}
function* sub_141FB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+r16[si] + 38] != 0x00) {
            pc = 0x14205;
            break;
        }
        yield* sub_107C0();
        return;
    case 0x14205:
        push(r16[si]);
        r16[si] = memory16get(ds*16+r16[si] + 68);
        push(memory16get(ds*16+r16[si] + 70));
    case 0x1420C:
        r16[si] = pop();
        if (!(r16[si] & r16[si])) {
            pc = 0x14219;
            break;
        }
        push(memory16get(ds*16+r16[si] + 70));
        yield* sub_107C0();
        pc = 0x1420C;
        break;
    case 0x14219:
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_1421C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x9a40;
        r16[dx] = r16[ax];
        r8[cl] = 0x03;
        r16[dx] <<= r8[cl];
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+(r16[bx] + 12422) & 65535);
        r16[cx] = 0x0030;
        bp = r16[dx];
    case 0x14232:
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        flags.sign = signed16(r16[bx] + r16[dx]) < 0;
        r16[bx] += r16[dx];
        if (!flags.sign) {
            pc = 0x14247;
            break;
        }
    case 0x14239:
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - 1);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x14241;
            break;
        }
        memory16set(ds*16+r16[si], 0x00bf);
    case 0x14241:
        flags.sign = signed16(r16[bx] + 0x0180) < 0;
        r16[bx] += 0x0180;
        if (flags.sign) {
            pc = 0x14239;
            break;
        }
    case 0x14247:
        if (r16s[bx] < signed16(0x0180)) {
            pc = 0x1425F;
            break;
        }
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + 1);
        if (memory16gets(ds*16+r16[si]) < signed16(0x00c0)) {
            pc = 0x14259;
            break;
        }
        memory16set(ds*16+r16[si], 0x0000);
    case 0x14259:
        r16[bx] -= 0x0180;
        pc = 0x14247;
        break;
    case 0x1425F:
        memory16set(ds*16+r16[si] + 4, r16[bx]);
        r16[si] += 0x0006;
        r16[dx] += bp;
        if (--r16[cx]) {
            pc = 0x14232;
            break;
        }
        return;
    } while (1);
}
function* sub_1426A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
    case 0x14270:
        r16[ax] = 0x00c0;
        yield* sub_141A1();
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = 0x0028;
        if (memory16get(ds*16+0x3044) == 0x0000) {
            pc = 0x1429D;
            break;
        }
        if (memory16get(ds*16+0x3044) == 0x0003) {
            pc = 0x1429D;
            break;
        }
        r16[ax] = 0x0050;
        if (memory16get(ds*16+0x3044) == 0x0002) {
            pc = 0x1429D;
            break;
        }
        if (memory16get(ds*16+0x3044) == 0x0004) {
            pc = 0x1429D;
            break;
        }
        r16[ax] = 0x00a0;
    case 0x1429D:
        yield* sub_141A1();
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        memory16set(ds*16+r16[si] + 4, 0x0000);
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x14270;
            break;
        }
        return;
    } while (1);
}
function* sub_142AE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x142E8;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 40);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 42);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 44);
        memory16set(ds*16+0xFCEA, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 46);
        memory16set(ds*16+0xFCEE, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F28);
        memory16set(ds*16+0xFCF2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F2A);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F2C);
        memory16set(ds*16+0xFCFA, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F2E);
        memory16set(ds*16+0xFCFE, r16[ax]);
    {yield* sub_10F2F(); return; };
    case 0x142E8:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    } while (1);
}
function* sub_142EB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x1430E;
            break;
        }
        if (r16s[ax] < memory16gets(ds*16+0x9F28)) {
            pc = 0x1430E;
            break;
        }
        if (r16s[ax] > memory16gets(ds*16+0x9F2C)) {
            pc = 0x1430E;
            break;
        }
        if (r16s[bx] < memory16gets(ds*16+0x9F2A)) {
            pc = 0x1430E;
            break;
        }
        if (r16s[bx] > memory16gets(ds*16+0x9F2E)) {
            pc = 0x1430E;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    case 0x1430E:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    } while (1);
}
function* sub_14311() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        if (memory[ds*16+0x9224] == 0x00) {
            pc = 0x1433E;
            break;
        }
        memory16set(ds*16+0x919A, 0x0000);
        yield* sub_141B1();
        if (memory16get(ds*16+r16[si] + 14) != 0x0000)
            return;
        memory16set(ds*16+r16[si] + 4, 0x0761);
        if (memory16gets(ds*16+0x991E) < signed16(0x0010))
            return;
        memory[ds*16+0x8F5C] = 0xff;
        return;
    case 0x1433E:
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x143B6;
            break;
        }
        if (memory16get(ds*16+0x9150) != 0x0000) {
            pc = 0x14356;
            break;
        }
        yield* sub_13589();
        yield* sub_11BEA();
        if (!flags.zero) {
            pc = 0x14381;
            break;
        }
        pc = 0x143B6;
        break;
    case 0x14356:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] -= 0x0040;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x0080;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] -= 0x0040;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0080;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        yield* sub_11BEA();
        if (flags.zero) {
            pc = 0x1437C;
            break;
        }
        yield* sub_13A33();
    case 0x1437C:
        yield* sub_13589();
        pc = 0x143B6;
        break;
    case 0x14381:
        if (memory16get(ds*16+0x9188) != 0x0000) {
            pc = 0x143A9;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x143B6;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x08b9);
        r16[ax] = 0x0008;
        if (memory[ds*16+r16[di] + 39] == 0x00) {
            pc = 0x1439E;
            break;
        }
        r16[ax] = 0x0010;
    case 0x1439E:
        yield* sub_13C4F();
        if (memory[ds*16+0x9224] == 0x00) {
            pc = 0x143A9;
            break;
        }
        return;
    case 0x143A9:
        if (memory16get(ds*16+r16[di]) == 0x0050) {
            pc = 0x143B6;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x0054) {
            pc = 0x143B6;
            break;
        }
        yield* sub_13A33();
    case 0x143B6:
        if (memory16get(ds*16+0x8E7E) == 0x0000) {
            pc = 0x14430;
            break;
        }
        if (memory16gets(ds*16+0x8E7E) >= 0 /*CHECK*/) {
            pc = 0x143D7;
            break;
        }
        yield* sub_11E29();
        if (!flags.zero) {
            pc = 0x143CC;
            break;
        }
        memory16set(ds*16+0x8E7E, 0x0000);
        pc = 0x14430;
        break;
    case 0x143CC:
        if (memory16get(ds*16+0x8E7E) != 0xffef) {
            pc = 0x143D7;
            break;
        }
        yield* sub_13C01();
        return;
    case 0x143D7:
        memory16set(ds*16+0x8E7E, memory16get(ds*16+0x8E7E) - 1);
        r16[ax] = memory16get(ds*16+0x918C);
        memory16set(ds*16+0x919A, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8ED2);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[bx] = memory16get(ds*16+0x8ED4);
        memory16set(ds*16+r16[si] + 18, r16[bx]);
        r16[ax] = r16[ax] + memory16get(ds*16+0x8ED6);
        if (r16s[ax] <= signed16(0x00b0)) {
            pc = 0x14402;
            break;
        }
        r16[ax] -= 0x00b0;
        memory16set(ds*16+0x919A, memory16get(ds*16+0x919A) - r16[ax]);
        r16[ax] = 0x00b0;
    case 0x14402:
        if (r16s[ax] >= signed16(0x0010)) {
            pc = 0x14411;
            break;
        }
        r16[ax] -= 0x0010;
        memory16set(ds*16+0x919A, memory16get(ds*16+0x919A) - r16[ax]);
        r16[ax] = 0x0010;
    case 0x14411:
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        push(r16[si]);
        r16[si] = 0x8ed2;
        r16[di] = 0x8ecc;
        r16[cx] = 0x0030;
        rep_movsw_data_data_forward();
        r16[si] = pop();
        if (memory16get(ds*16+0x8E7E) != 0x0000) {
            pc = 0x14483;
            break;
        }
        memory16set(ds*16+0x8E7E, 0xffff);
        pc = 0x14483;
        break;
    case 0x14430:
        yield* sub_144F3();
        push(r16[si]);
        r16[si] = 0x8f2a;
        r16[di] = 0x8f30;
        r16[cx] = 0x0030;
        flags.direction = true;
        rep_movsw_data_data_backward();
        flags.direction = false;
        r16[si] = pop();
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0x8ECC, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x8ECE, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+0x8ED0, r16[ax]);
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x14483;
            break;
        }
        if (memory16gets(ds*16+0x8E7E) < 0 /*CHECK*/) {
            pc = 0x14483;
            break;
        }
        yield* sub_11E29();
        if (flags.zero) {
            pc = 0x14483;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8E6E);
        memory16set(ds*16+0x8E7E, r16[ax]);
        memory16set(ds*16+0x919E, 0x0000);
        r16[ax] = memory16get(ds*16+0x9190);
        r16[ax] = r16[ax] + memory16get(ds*16+0x91AE);
        if (r16s[ax] <= memory16gets(ds*16+0x91AA)) {
            pc = 0x14483;
            break;
        }
        memory16set(ds*16+0x91AA, r16[ax]);
    case 0x14483:
        push(r16[si]);
        r16[si] = 0x8ec0;
        r16[di] = 0x8ebc;
        r16[cx] = 0x0004;
        rep_movsw_data_data_forward();
        r16[si] = pop();
        r16[ax] = memory16get(ds*16+0x8F34);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+0x8F36);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[bx] = memory16get(ds*16+0x8E80);
        if (r16[bx] & r16[bx]) {
            pc = 0x144B4;
            break;
        }
        r16[bx] = memory16get(ds*16+0x919E);
        r16[bx] += 0x0006;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 12364);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        return;
    case 0x144B4:
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 12888);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(ds*16+0x8E82);
        r16[ax] = r16[ax] + memory16get(ds*16+0x8E80);
        memory16set(ds*16+0x8E80, r16[ax]);
        if (r16[ax] == 0) {
            pc = 0x144E6;
            break;
        }
        if (r16[ax] != 0x0004)
            return;
        if (memory16get(ds*16+0x8E82) != 0x0000) {
            pc = 0x144DF;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0897);
    case 0x144DF:
        memory16set(ds*16+0x8E82, 0x0000);
        return;
    case 0x144E6:
        memory16set(ds*16+0x8E82, 0x0000);
        memory16set(ds*16+0x8E7E, 0xfff1);
        return;
    } while (1);
}
function* sub_144F3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x8F34, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+0x8F36, r16[ax]);
        if (memory[ds*16+0x8F59] & 0x04) {
            pc = 0x14518;
            break;
        }
        if (memory[ds*16+0x8F59] & 0x08) {
            pc = 0x14532;
            break;
        }
        r16[ax] = memory16get(ds*16+0x919E);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x1454A;
            break;
        }
        if (r16s[ax] < 0) {
            pc = 0x14546;
            break;
        }
        pc = 0x1452C;
        break;
    case 0x14518:
        if (memory16gets(ds*16+0x919E) <= signed16(0x0000)) {
            pc = 0x14525;
            break;
        }
        memory16set(ds*16+0x919E, 0x0000);
    case 0x14525:
        if (memory16gets(ds*16+0x919E) <= signed16(0xfffa)) {
            pc = 0x1454A;
            break;
        }
    case 0x1452C:
        memory16set(ds*16+0x919E, memory16get(ds*16+0x919E) - 1);
        pc = 0x1454A;
        break;
    case 0x14532:
        if (memory16gets(ds*16+0x919E) >= signed16(0x0000)) {
            pc = 0x1453F;
            break;
        }
        memory16set(ds*16+0x919E, 0x0000);
    case 0x1453F:
        memory16set(ds*16+0x919E, 6);
        if (memory16gets(ds*16+0x919E) >= signed16(0x0006)) {
            pc = 0x1454A;
            break;
        }
    case 0x14546:
        memory16set(ds*16+0x919E, memory16get(ds*16+0x919E) + 1);
    case 0x1454A:
        r16[ax] = memory16get(ds*16+0x918C);
        memory16set(ds*16+0x919A, r16[ax]);
        if (!(memory[ds*16+0x8F59] & 0x01)) {
            pc = 0x14576;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 22) <= signed16(0x0010)) {
            pc = 0x14569;
            break;
        }
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - 0x0003);
        r16[ax] = memory16get(ds*16+0x915E);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - r16[ax]);
        pc = 0x14576;
        break;
    case 0x14569:
        memory16set(ds*16+r16[si] + 22, 0x0010);
        memory16set(ds*16+0x919A, 0x0001);
        pc = 0x145A4;
        break;
    case 0x14576:
        if (!(memory[ds*16+0x8F59] & 0x02)) {
            pc = 0x145A4;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 22) >= signed16(0x00b0)) {
            pc = 0x14590;
            break;
        }
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + 0x0003);
        r16[ax] = memory16get(ds*16+0x915E);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        pc = 0x145A4;
        break;
    case 0x14590:
        r16[ax] = memory16get(ds*16+0x9190);
        if (r16[ax] == memory16get(ds*16+0x91AA)) {
            pc = 0x145A4;
            break;
        }
        memory16set(ds*16+0x919A, 0xffff);
        memory16set(ds*16+r16[si] + 22, 0x00b0);
    case 0x145A4:
        r16[ax] = memory16get(ds*16+0x919E);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x145C3;
            break;
        }
        if (r16s[ax] < 0) {
            pc = 0x145B9;
            break;
        }
        if (!(memory[ds*16+0x8F59] & 0x08)) {
            pc = 0x145C3;
            break;
        }
        r16[ax] = 0x0006;
        pc = 0x145C3;
        break;
    case 0x145B9:
        if (!(memory[ds*16+0x8F59] & 0x04)) {
            pc = 0x145C3;
            break;
        }
        r16[ax] = 0xfffa;
    case 0x145C3:
        if (memory16get(ds*16+0x915E) != 0x0000) {
            pc = 0x145CC;
            break;
        }
        sar16(ax, 1);
    case 0x145CC:
        if (memory16gets(ds*16+0x915E) < signed16(0x0002)) {
            pc = 0x145D9;
            break;
        }
        r16[bx] = r16[ax];
        sar16(bx, 1);
        r16[ax] += r16[bx];
    case 0x145D9:
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + r16[ax]);
        if (memory16gets(ds*16+r16[si] + 18) >= signed16(0x0010)) {
            pc = 0x145E7;
            break;
        }
        memory16set(ds*16+r16[si] + 18, 0x0010);
    case 0x145E7:
        if (memory16gets(ds*16+r16[si] + 18) <= signed16(0x012e))
            return;
        memory16set(ds*16+r16[si] + 18, 0x012e);
        return;
    } while (1);
}
function* sub_145F4() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E88) != 0x0000) {
            pc = 0x14601;
            break;
        }
        memory16set(ds*16+0x8E88, 0x0002);
    case 0x14601:
        if (memory16get(ds*16+r16[si] + 52) == 0x0000) {
            pc = 0x14613;
            break;
        }
        if (memory16get(ds*16+r16[si] + 52) == 0x0001) {
            pc = 0x14610;
            break;
        }
        bp += 0x0002;
    case 0x14610:
        bp += 0x0002;
    case 0x14613:
        push(r16[di]);
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+r16[di] + 28, r16[ax]);
        memory16set(ds*16+r16[di] + 32, r16[bx]);
        r16[cx] = r16[cx] + memory16get(ds*16+0x9F12);
        memory16set(ds*16+r16[di] + 18, r16[cx]);
        r16[dx] = r16[dx] + memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[di] + 22, r16[dx]);
        memory16set(ds*16+r16[di], 0x0010);
        memory16set(ds*16+r16[di] + 2, 0x39ee);
        memory16set(ds*16+r16[di] + 4, 0x091f);
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        memory16set(ds*16+r16[di] + 14, 0x0000);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        r16[ax] = memory16get(ds*16+r16[si] + 52);
        memory16set(ds*16+r16[di] + 52, r16[ax]);
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_1465C() {
    r16[dx] += 1;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0x000a;
    _mul(r16[cx]);
    r16[cx] = pop();
    div(r16[cx]);
    r16[si] = r16[ax];
    r16[si] <<= 1;
    r16[si] = memory16get(ds*16+r16[si] + 12898);
    r16[cx] = pop();
    r16[dx] = r16[bx];
{yield* sub_10875(); return; };
}
function* sub_14675() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x8E80) != 0x0000) {
            pc = 0x14690;
            break;
        }
        if (memory[ds*16+0x9224] != 0x00) {
            pc = 0x14690;
            break;
        }
        if (memory16get(ds*16+0x991E) == 0x0000) {
            pc = 0x1469B;
            break;
        }
        memory16set(ds*16+0x991E, memory16get(ds*16+0x991E) - 1);
        pc = 0x1469B;
        break;
    case 0x14690:
        if (memory16get(ds*16+0x991E) == 0x0010) {
            pc = 0x1469B;
            break;
        }
        memory16set(ds*16+0x991E, memory16get(ds*16+0x991E) + 1);
    case 0x1469B:
        if (memory16get(ds*16+0x9150) == 0x0000) {
            pc = 0x146B6;
            break;
        }
        memory16set(ds*16+0x9150, memory16get(ds*16+0x9150) - 1);
        r16[dx] = 0x00dd;
        r16[cx] = memory16get(ds*16+0x9150);
        r16[ax] = 0x0126;
        r16[bx] = 0x0008;
        yield* sub_1465C();
    case 0x146B6:
        if (memory16get(ds*16+0x8E84) == 0x0000) {
            pc = 0x146E4;
            break;
        }
        memory16set(ds*16+0x8E84, memory16get(ds*16+0x8E84) - 1);
        r16[dx] = 0x0088;
        r16[cx] = memory16get(ds*16+0x8E84);
        r16[ax] = 0x0098;
        r16[bx] = 0x0008;
        yield* sub_1465C();
        if (memory16get(ds*16+0x8E84) != 0x0000) {
            pc = 0x146E4;
            break;
        }
        memory16set(ds*16+0x8E82, 0xffff);
        memory16set(ds*16+0x8E88, 0x0018);
    case 0x146E4:
        if (memory16get(ds*16+0x9162) == 0x0000) {
            pc = 0x14709;
            break;
        }
        memory16set(ds*16+0x9162, memory16get(ds*16+0x9162) - 1);
        r16[dx] = 0x00aa;
        r16[cx] = memory16get(ds*16+0x9162);
        r16[ax] = 0x0098;
        r16[bx] = 0x00a0;
        yield* sub_1465C();
        if (memory16get(ds*16+0x9162) != 0x0000) {
            pc = 0x14709;
            break;
        }
        yield* sub_1472D();
    case 0x14709:
        if (memory[ds*16+0x8F59] & 0x80) {
            pc = 0x14717;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9130);
        memory16set(ds*16+0x912E, r16[ax]);
        return;
    case 0x14717:
        r16[ax] = memory16get(ds*16+0x9132);
        flags.carry2 = memory16get(ds*16+0x912E) > r16[ax];
        memory16set(ds*16+0x912E, memory16get(ds*16+0x912E) - r16[ax]);
        if (flags.carry2)
            return;
        r16[ax] = memory16get(ds*16+0x9130);
        memory16set(ds*16+0x912E, memory16get(ds*16+0x912E) + r16[ax]);
        memory[ds*16+0x8F5B] = 0xff;
        return;
    } while (1);
}
function* sub_1472D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x9008);
    case 0x14732:
        if (memory16get(ds*16+r16[si]) == 0x0000) {
            pc = 0x14740;
            break;
        }
        push(memory16get(ds*16+r16[si] + 10));
        yield* sub_137A9();
        r16[si] = pop();
        pc = 0x14732;
        break;
    case 0x14740:
        r16[ax] = memory16get(ds*16+0x91B4);
        memory16set(ds*16+0x9008, r16[ax]);
        r16[ax] = memory16get(ds*16+0x91B6);
        memory16set(ds*16+0x9006, r16[ax]);
        r16[si] = 0x91b8;
        r16[di] = 0x9134;
        r16[cx] = 0x000e;
        rep_movsw_data_data_forward();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_14759() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[bx] = memory16get(ds*16+0x919E);
        if (r16s[bx] >= 0) {
            pc = 0x14769;
            break;
        }
        r16[bx] = -r16[bx];
    case 0x14769:
        r16[bx] <<= 1;
        if (!(memory16get(ds*16+r16[si] + 34) & 0x0001)) {
            pc = 0x14775;
            break;
        }
        r16[bx] += 0x000e;
    case 0x14775:
        r16[ax] = r16[ax] + memory16get(ds*16+r16[bx] + 12918);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        if (memory16get(ds*16+0x8E80) == 0x0000) {
            pc = 0x1478F;
            break;
        }
        return;
    case 0x1478F:
        if (memory16gets(ds*16+r16[si] + 34) < signed16(0x0002)) {
            pc = 0x147A2;
            break;
        }
    case 0x1479A:
        if (!(memory[ds*16+0x8F59] & 0x02))
            return;
        memory16set(ds*16+r16[si] + 4, 0x0853);
        return;
    case 0x147A2:
        pc = 0x1479A;
        break;
        return;
    } while (1);
}
function* loc_147A9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x991E) != 0x0010) {
            pc = 0x147B6;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0761);
        return;
    case 0x147B6:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        yield* sub_10EF5();
        r16[cx] = r16[ax];
        r16[di] = r16[bx];
        push(r16[si]);
        r16[si] = 0x9f00;
        yield* sub_10EF5();
        r16[si] = pop();
        r16[cx] -= r16[ax];
        r16[di] -= r16[bx];
        bp = r16[ax];
        r16[ax] = memory16get(ds*16+0x991E);
        imul16(r16[cx]);
        r16[ax] += bp;
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x991E);
        imul16(r16[di]);
        r16[ax] += r16[bx];
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        return;
        _STOP_("word_147E5 dw 0");
        _STOP_("word_147E7 dw 0");
        return;
    } while (1);
}
function* sub_147E9() {
    var cs = _seg000;
    r16[ax] = memory16get(ds*16+0x304A);
    memory16set(cs*16+0x47E5, r16[ax]);
{yield* sub_1480B(); return; };
    r16[ax] = memory16get(ds*16+0x304A);
    memory16set(cs*16+0x47E7, r16[ax]);
    r16[ax] = memory16get(cs*16+0x47E5);
    memory16set(ds*16+0x304A, r16[ax]);
    yield* sub_1480B();
    r16[ax] = memory16get(cs*16+0x47E7);
    memory16set(ds*16+0x304A, r16[ax]);
}
function* sub_1480B(pc) {
    if (!pc) pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
    case 0x1480E:
        yield* sub_14865();
        if (memory16get(ds*16+r16[si]) == 0x0004)
            return;
        if (memory[ds*16+r16[si] + 73] == 0x00)
            return;
        r8[al] = memory[ds*16+r16[si] + 73];
    case 0x1481F:
        if (r8[al] < 0x64) {
            pc = 0x14827;
            break;
        }
        r8[al] -= 0x64;
        pc = 0x1481F;
        break;
    case 0x14827:
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry)
            return;
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
        if (memory[ds*16+r16[si] + 73] >= 0x64) {
            pc = 0x14842;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x0007;
        pc = 0x14852;
        break;
    case 0x14842:
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+0x9F16);
        r16[dx] = r16[dx] - memory16get(ds*16+r16[si] + 22);
        yield* sub_11B90();
    case 0x14852:
        r16[cx] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] = 0x0006;
        bp = memory16get(ds*16+0x8E72);
        yield* sub_11ED3();
        return;
    } while (1);
}
function* sub_14865() {
    yield* sub_14871();
    if (memory16get(ds*16+r16[si]) == 0x0004)
        return;
{yield* sub_13589(); return; };
    return;
}
function* sub_14871() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si] + 66);
        memory16set(ds*16+0xFCFE, r16[ax]);
        if (!(r16[ax] & r16[ax]))
            return;
        if (memory16get(ds*16+r16[si] + 26) != 0x0000) {
            pc = 0x14884;
            break;
        }
        pc = 0x1499F;
        break;
    case 0x14884:
        if (memory16gets(ds*16+r16[si] + 26) >= 0 /*CHECK*/) {
            pc = 0x1489E;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + r16[ax]);
        if (memory16gets(ds*16+0xFCFE) <= signed16(0x0000)) {
            pc = 0x14897;
            break;
        }
        pc = 0x1499F;
        break;
    case 0x14897:
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        return;
    case 0x1489E:
        r16[di] = 0x6116;
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        memory16set(ds*16+0xFCE4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 24);
        memory16set(ds*16+0xFCE8, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 28);
        memory16set(ds*16+0xFCEE, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 30);
        memory16set(ds*16+0xFCF0, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 60);
        memory16set(ds*16+0xFCF2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 62);
        memory16set(ds*16+0xFCF4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 64);
        _cwd();
        memory16set(ds*16+0xFCF6, r16[ax]);
        memory16set(ds*16+0xFCF8, r16[dx]);
        pc = 0x1492D;
        break;
    case 0x148DE:
        /*
        r16[bx] = memory16get(ds*16+0xFCEE);
        r8[ah] = memory[cs*16+r16[bx] + r16[di]];
        _cwd();
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory[ds*16+0xFCE9] + r8[ah]) >= 0x100;
        memory[ds*16+0xFCE9] += r8[ah];
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + r16[dx] + flags.carry);
        r8[ah] = memory[cs*16+r16[bx] + r16[di] + 64];
        _cwd();
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory[ds*16+0xFCE5] + r8[ah]) >= 0x100;
        memory[ds*16+0xFCE5] += r8[ah];
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[dx] + flags.carry);
        r16[ax] = memory16get(ds*16+0xFCF2);
        flags.carry = (memory16get(ds*16+0xFCF0) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0xFCF0, memory16get(ds*16+0xFCF0) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF4);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) + r16[ax] + flags.carry);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) & 0x00ff);
        r16[ax] = memory16get(ds*16+0xFCF6);
        flags.carry = (memory16get(ds*16+0xFCF2) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0xFCF2, memory16get(ds*16+0xFCF2) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF8);
        memory16set(ds*16+0xFCF4, memory16get(ds*16+0xFCF4) + r16[ax] + flags.carry);
        */
        r16[bx] = memory16get(ds*16+0xFCEE);
        r8[ah] = memory[cs*16+r16[bx] + r16[di]];
        _cwd();
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory[ds*16+0xFCE9] + r8[ah]) >= 0x100;
        memory[ds*16+0xFCE9] += r8[ah];
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + r16[dx] + flags.carry);
        r8[ah] = memory[cs*16+r16[bx] + r16[di] + 64];
        _cwd();
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = (memory[ds*16+0xFCE5] + r8[ah]) >= 0x100;
        memory[ds*16+0xFCE5] += r8[ah];
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[dx] + flags.carry);
        r16[ax] = memory16get(ds*16+0xFCF2);
        flags.carry = (memory16get(ds*16+0xFCF0) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0xFCF0, memory16get(ds*16+0xFCF0) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF4);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) + r16[ax] + flags.carry);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) & 0x00ff);
        r16[ax] = memory16get(ds*16+0xFCF6);
        flags.carry = (memory16get(ds*16+0xFCF3) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0xFCF2, memory16get(ds*16+0xFCF2) + r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF8);
        memory16set(ds*16+0xFCF4, memory16get(ds*16+0xFCF4) + r16[ax] + flags.carry);
    case 0x1492D:
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - 1);
        if (memory16gets(ds*16+0xFCFE) < 0) {
            pc = 0x1496E;
            break;
        }
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) - 1);
        if (memory16gets(ds*16+r16[si] + 26) >= 0) {
            pc = 0x148DE;
            break;
        }
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + 1);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE4);
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE8);
        memory16set(ds*16+r16[si] + 24, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF0);
        memory16set(ds*16+r16[si] + 30, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF2);
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF4);
        memory16set(ds*16+r16[si] + 62, r16[ax]);
        pc = 0x1499F;
        break;
    case 0x1496E:
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE4);
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE8);
        memory16set(ds*16+r16[si] + 24, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF0);
        memory16set(ds*16+r16[si] + 30, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF2);
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF4);
        memory16set(ds*16+r16[si] + 62, r16[ax]);
        return;
    case 0x1499F:
        r16[di] = memory16get(ds*16+r16[si] + 58);
        r16[bx] = memory16get(ds*16+r16[di]);
        assert(r16[bx] < 10);
        switch (r16[bx])
        {
            case 0: pc = 0x149B5; break;
            case 2: pc = 0x14A06; break;
            case 4: pc = 0x14A36; break;
            case 8: pc = 0x149F9; break;
            default:
            assert(0);
        }
        break;
        _STOP_("db  4Ah");
        _STOP_("db  36h");
        _STOP_("db  4Ah");
        _STOP_("db  4Fh");
        _STOP_("db  4Ah");
        _STOP_("db 0F9h");
        _STOP_("db  49h");
        _STOP_("db 0F1h");
        _STOP_("db  49h");

    case 0x149B5:
        r16[ax] = memory16get(ds*16+r16[si] + 54);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x149D6;
            break;
        }
        r16[di] = 0x8e8c;
        r16[cx] = 0x0008;
    case 0x149C2:
        if (r16[ax] == memory16get(ds*16+r16[di])) {
            pc = 0x149CD;
            break;
        }
        r16[di] += 0x0004;
        if (--r16[cx]) {
            pc = 0x149C2;
            break;
        }
        pc = 0x149D6;
        break;
    case 0x149CD:
        memory16set(ds*16+r16[di], 0x0000);
        memory16set(ds*16+r16[di] + 2, 0x0000);
    case 0x149D6:
        if (memory[ds*16+r16[si] + 38] != 0x00) {
            pc = 0x149E0;
            break;
        }
        yield* sub_107C0();
        return;
    case 0x149E0:
        r16[di] = memory16get(ds*16+r16[si] + 68);
    case 0x149E3:
        push(memory16get(ds*16+r16[di] + 70));
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[di] = pop();
        if (r16[di] & r16[di]) {
            pc = 0x149E3;
            break;
        }
        return;
    case 0x14A06:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        memory16set(ds*16+r16[si] + 30, 0x0000);
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        _cwd();
        r8[dl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[al] ^ r8[al];
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        memory16set(ds*16+r16[si] + 62, r16[dx]);
        r16[ax] = memory16get(ds*16+r16[di] + 6);
        memory16set(ds*16+r16[si] + 64, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 8);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        r16[di] += 0x000a;
        memory16set(ds*16+r16[si] + 58, r16[di]);
        pc = 0x1489E;
        break;
    case 0x14A36:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 58, r16[di]);
        flags.carry2 = memory16gets(ds*16+0xFCFE) <= r16s[ax];
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - r16[ax]);
        if (flags.carry2) {
            pc = 0x14A48;
            break;
        }
        pc = 0x1499F;
        break;
    case 0x14A48:
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        return;
    case 0x149F9:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[di] += r16[ax];
        memory16set(ds*16+r16[si] + 58, r16[di]);
        pc = 0x1499F;
        break;
        return;
    } while (1);
}
function* sub_149F1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] += 0x0006;
        memory16set(ds*16+r16[si] + 58, r16[di]);
        _STOP_("goto loc_1499F");
        return;
    } while (1);
}
function* sub_149F9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[di] += r16[ax];
        memory16set(ds*16+r16[si] + 58, r16[di]);
        _STOP_("goto loc_1499F");
        return;
    } while (1);
}
function* sub_14A06() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        memory16set(ds*16+r16[si] + 30, 0x0000);
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        _cwd();
        r8[dl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[al] ^ r8[al];
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        memory16set(ds*16+r16[si] + 62, r16[dx]);
        r16[ax] = memory16get(ds*16+r16[di] + 6);
        memory16set(ds*16+r16[si] + 64, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 8);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        r16[di] += 0x000a;
        memory16set(ds*16+r16[si] + 58, r16[di]);
        _STOP_("goto loc_1489E");
        return;
    } while (1);
}
function* sub_14A36() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 58, r16[di]);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - r16[ax]);
        if (_FIXME_) {
            pc = 0x14A48;
            break;
        }
        _STOP_("goto loc_1499F");
    case 0x14A48:
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        return;
    } while (1);
}
function* loc_14A4F() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x14A4F:
        yield* sub_14191();
        r16[ax] &= 0x000e;
        r16[bx] = r16[ax];
        r16[dx] = memory16get(ds*16+r16[bx] + r16[di] + 2);
        if (r16s[dx] < 0) {
            pc = 0x14A4F;
            break;
        }
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[di] += r16[dx];
        memory16set(ds*16+r16[si] + 58, r16[di]);
        _STOP_("goto loc_1499F");
        return;
    } while (1);
}
function* sub_14A69() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(_ss*16+16, 0x00c7);
        yield* sub_10BC7();
        yield* sub_10D5F();
        yield* sub_10C0B();
        memory[ds*16+0x3ADE] = 0xff;
        memory[ds*16+0x3ADF] = 0xff;
        memory[ds*16+0x3AE0] = 0x00;
        memory16set(ds*16+0x3816, 0x0000);
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x14A94:
        memory16set(ds*16+r16[si], 0xfff7);
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x14A94;
            break;
        }
        memory16set(ds*16+0x8F3C, 0x0030);
        memory16set(ds*16+0x8F3E, 0x0044);
        memory16set(ds*16+0x8F40, 0x0000);
        memory16set(ds*16+0x8F42, 0x0000);
        memory16set(ds*16+0x8F44, 0x0004);
        yield* sub_15488();
        memory16set(ds*16+0x8F42, 0x0001);
        memory16set(ds*16+0x8F44, 0x0004);
        yield* sub_15488();
        yield* sub_1577D();
        yield* sub_15612();
        yield* sub_10A51();
        yield* sub_15612();
        yield* sub_10E09();
        yield* sub_10D81();
        memory16set(ds*16+0x8E88, 0x0000);
        yield* sub_14BC7();
        memory16set(ds*16+0x8E88, 0x0007);
        yield* sub_14C59();
        if (memory[ds*16+0x8FB1] == 0x00) {
            pc = 0x14AFD;
            break;
        }
        yield* sub_14E12();
        pc = 0x14B00;
        break;
    case 0x14AFD:
        yield* sub_15119();
    case 0x14B00:
        yield* sub_1558E();
        yield* sub_15510();
        yield* sub_1576D();
        if (memory[ds*16+0x8FB1] == 0x00) {
            pc = 0x14B13;
            break;
        }
    {yield* loc_14BD4(); return; };
    case 0x14B13:
        r16[si] = 0x3da6;
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14B3E;
            break;
        }
        r16[si] = 0x3e82;
        yield* sub_15787();
        r16[cx] = 0x0011;
        yield* sub_154FC();
        yield* sub_1576D();
        r16[si] = 0x3ea6;
        yield* sub_15787();
        r16[cx] = 0x0011;
        yield* sub_154FC();
        yield* sub_1576D();
        r16[si] = 0x3eb9;
    case 0x14B3E:
        yield* sub_15787();
        yield* sub_15154();
        yield* sub_155D0();
        memory[ds*16+0x3ADE] = 0x00;
        memory16set(ds*16+0x8F42, 0x0001);
        memory16set(ds*16+0x8F44, 0x0004);
        yield* sub_15488();
        yield* sub_14D38();
        yield* sub_1558E();
        yield* sub_1576D();
        r16[si] = 0x3dc4;
        yield* sub_15787();
        yield* sub_14E78();
        yield* sub_155D0();
        memory16set(ds*16+0x8E88, 0x0007);
        yield* sub_14CAD();
        memory16set(ds*16+0x8E88, 0x0000);
        yield* sub_10A51();
        yield* sub_14BC7();
        yield* sub_15612();
        yield* sub_10A51();
        yield* sub_15612();
    case 0x14B8E:
        yield* sub_10D5F();
        yield* sub_10BE9();
        memory16set(_ss*16+16, 0x00bf);
        yield* sub_13319();
        yield* sub_135F2();
        if (memory[ds*16+0x8F61] != 0x00) {
            pc = 0x14BC0;
            break;
        }
        r16[ax] = memory16get(ds*16+0x3048);
    case 0x14BAB:
        yield* sub_10985();
        yield* sub_1080F();
        yield* sub_10A51();
        yield* sub_10E2B();
        yield* sub_10D81();
    case 0x14BC0:
        memory16set(ds*16+0x91B2, 0x000c);
        return;
    } while (1);
}
function* sub_14BC7() {
    r16[ax] = memory16get(ds*16+0x3046);
    r16[ax] += 0x0009;
}
function* loc_14BD4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3796;
        yield* sub_15787();
        r16[cx] = 0x001e;
        yield* sub_14C48();
        r16[si] = 0x37b1;
        yield* sub_15787();
        r16[cx] = 0x001e;
        yield* sub_14C48();
        yield* sub_1576D();
        r16[si] = 0x37d8;
        yield* sub_15787();
        r16[cx] = 0x0011;
        yield* sub_14C48();
        yield* sub_155D0();
        memory16set(ds*16+0x8E88, 0x0007);
        yield* sub_14CAD();
        memory16set(ds*16+0x8E88, 0x0000);
        yield* sub_10A51();
        yield* sub_14BC7();
        yield* sub_15612();
        yield* sub_10A51();
        yield* sub_15612();
        yield* sub_10D5F();
        memory16set(ds*16+0x8E88, 0x0000);
        r16[cx] = 0x0096;
    case 0x14C28:
        push(r16[cx]);
        yield* sub_10C4F();
        yield* sub_10A51();
        yield* sub_10E2B();
        yield* sub_10D81();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x14C28;
            break;
        }
        yield* sub_10D5F();
        r16[cx] = 0x0050;
    case 0x14C3E:
        push(r16[cx]);
        yield* sub_10A51();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x14C3E;
            break;
        }
        _STOP_("goto loc_14B8E");
        return;
    } while (1);
}
function* sub_14C48() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x14C48:
        push(r16[cx]);
        yield* sub_10C93();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10A51();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x14C48;
            break;
        }
        return;
    } while (1);
}
function* sub_14C59() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x14C59:
        yield* sub_10A51();
        if (memory16get(ds*16+0x8F3C) == 0x0000) {
            pc = 0x14C7C;
            break;
        }
        memory16set(ds*16+0x8F3C, memory16get(ds*16+0x8F3C) - 0x0004);
        if (memory16gets(ds*16+0x8F3C) < 0) {
            pc = 0x14C6C;
            break;
        }
        if (memory16get(ds*16+0x8F3C) != 0) {
            pc = 0x14C7C;
            break;
        }
    case 0x14C6C:
        r8[ah] = 0x01;
        interrupt(128);
        r8[ah] = 0x02;
        r8[al] = 0x01;
        interrupt(128);
        memory16set(ds*16+0x8F3C, 0x0000);
    case 0x14C7C:
        if (memory16get(ds*16+0x8F3E) == 0x0000) {
            pc = 0x14C92;
            break;
        }
        memory16set(ds*16+0x8F3E, memory16get(ds*16+0x8F3E) - 0x0004);
        if (memory16get(ds*16+0x8F3E) == 0) {
            pc = 0x14C92;
            break;
        }
        if (memory16gets(ds*16+0x8F3E) >= 0) {
            pc = 0x14C92;
            break;
        }
        memory16set(ds*16+0x8F3E, 0x0000);
    case 0x14C92:
        yield* sub_15612();
        yield* sub_14CFA();
        yield* sub_14D0D();
        if (memory16get(ds*16+0x8F3C) != 0x0000) {
            pc = 0x14C59;
            break;
        }
        if (memory16get(ds*16+0x8F3E) != 0x0000) {
            pc = 0x14C59;
            break;
        }
        yield* sub_10C71();
        return;
    } while (1);
}
function* sub_14CAD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_10C71();
    case 0x14CB0:
        yield* sub_10A51();
        if (memory16get(ds*16+0x8F3E) == 0x0044) {
            pc = 0x14CCC;
            break;
        }
        memory16set(ds*16+0x8F3E, memory16get(ds*16+0x8F3E) + 0x0004);
        if (memory16gets(ds*16+0x8F3E) <= signed16(0x0044)) {
            pc = 0x14CCC;
            break;
        }
        memory16set(ds*16+0x8F3E, 0x0044);
    case 0x14CCC:
        if (memory16get(ds*16+0x8F3C) == 0x0030) {
            pc = 0x14CE5;
            break;
        }
        memory16set(ds*16+0x8F3C, memory16get(ds*16+0x8F3C) + 0x0004);
        if (memory16gets(ds*16+0x8F3C) <= signed16(0x0030)) {
            pc = 0x14CE5;
            break;
        }
        memory16set(ds*16+0x8F3C, 0x0030);
    case 0x14CE5:
        yield* sub_15612();
        yield* sub_14D0D();
        yield* sub_14CFA();
        if (memory16get(ds*16+0x8F3E) != 0x0044) {
            pc = 0x14CB0;
            break;
        }
        r8[ah] = 0x01;
        interrupt(128);
        return;
    } while (1);
}
function* sub_14CFA() {
    r16[dx] = 0x0004;
    r16[si] = 0xb144;
    if (!(memory16get(ds*16+0x8F3C) & 0x0004))
    {sub_14D0D(0x14D1E); return;}
    r16[si] = 0xb1ae;
{sub_14D0D(0x14D1E); return;}
}
function* sub_14D0D(pc) {
//    var pc = 0;
    if (!pc)
      pc = 0;
    do switch (pc) {
    case 0:
        if (pc == 0x14D1E) {
            pc = 0x14D1E;
            break;
        }
        r16[dx] = 0x006d;
        r16[si] = 0xb144;
        if (!(memory16get(ds*16+0x8F3E) & 0x0004)) {
            pc = 0x14D1E;
            break;
        }
        r16[si] = 0xb1ae;
    case 0x14D1E:
        push(r16[dx]);
        push(r16[si]);
        r16[cx] = 0x00e2;
        yield* sub_10C2D();
        r16[si] = pop();
        r16[dx] = pop();
        push(r16[dx]);
        push(r16[si]);
        r16[cx] = 0x0102;
        yield* sub_10C2D();
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = 0x0122;
    {yield* sub_10C2D(); return; };
        return;
    } while (1);
}
function* sub_14D38() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x3816);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 14544);
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14D4B;
            break;
        }
        r16[ax] >>= 1;
    case 0x14D4B:
        _cwd();
        if (r16s[dx] < memory16gets(ds*16+0x915C)) {
            pc = 0x14D60;
            break;
        }
        if (r16[dx] != memory16get(ds*16+0x915C)) {
            pc = 0x14D5A;
            break;
        }
        if (r16[ax] <= memory16get(ds*16+0x915A)) {
            pc = 0x14D60;
            break;
        }
    case 0x14D5A:
        memory16set(ds*16+0x3816, 0x0000);
    case 0x14D60:
        r16[si] = 0x3cb6;
        bp = memory16get(ds*16+0x3816);
        bp += 0x0002;
        r16[bx] = bp;
        r16[bx] -= 1;
        r16[bx] <<= 1;
        r16[di] = 0x38d0;
        r16[di] += r16[bx];
        r16[bx] += 0x389a;
    case 0x14D78:
        r16[ax] = memory16get(ds*16+r16[di]);
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14D83;
            break;
        }
        r16[ax] >>= 1;
    case 0x14D83:
        if (r16s[ax] > memory16gets(ds*16+0x8F4A)) {
            pc = 0x14DA2;
            break;
        }
        _cwd();
        if (r16s[dx] > memory16gets(ds*16+0x915C)) {
            pc = 0x14DA2;
            break;
        }
        if (r16[dx] != memory16get(ds*16+0x915C)) {
            pc = 0x14D98;
            break;
        }
        if (r16[ax] > memory16get(ds*16+0x915A)) {
            pc = 0x14DA2;
            break;
        }
    case 0x14D98:
        memory16set(ds*16+r16[si] + 6, bp);
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        pc = 0x14DAC;
        break;
    case 0x14DA2:
        memory16set(ds*16+r16[si] + 6, 0x001a);
        memory16set(ds*16+r16[si] + 8, 0x3ae8);
    case 0x14DAC:
        bp += 1;
        r16[di] += 0x0002;
        r16[bx] += 0x0002;
        r16[si] += 0x000c;
        if (bp == 0x001a) {
            pc = 0x14DF5;
            break;
        }
        if (r16s[si] < signed16(0x3d9a)) {
            pc = 0x14D78;
            break;
        }
        if (r16s[si] > signed16(0x3d9a))
            return;
        if (memory16get(ds*16+0x3816) != 0x0000) {
            pc = 0x14DEA;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[di]);
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14DD5;
            break;
        }
        r16[ax] >>= 1;
    case 0x14DD5:
        if (r16s[ax] > memory16gets(ds*16+0x8F4A)) {
            pc = 0x14DA2;
            break;
        }
        _cwd();
        if (r16s[dx] > memory16gets(ds*16+0x915C)) {
            pc = 0x14DA2;
            break;
        }
        if (r16[dx] != memory16get(ds*16+0x915C)) {
            pc = 0x14DEA;
            break;
        }
        if (r16[ax] > memory16get(ds*16+0x915A)) {
            pc = 0x14DA2;
            break;
        }
    case 0x14DEA:
        memory16set(ds*16+r16[si] + 6, 0x001b);
        memory16set(ds*16+r16[si] + 8, 0x3ae2);
        return;
    case 0x14DF5:
        if (r16[si] == 0x3d9a) {
            pc = 0x14E05;
            break;
        }
        memory16set(ds*16+r16[si] + 6, 0x0000);
        r16[si] += 0x000c;
        pc = 0x14DF5;
        break;
    case 0x14E05:
        if (memory16get(ds*16+0x3816) != 0x0000) {
            pc = 0x14DEA;
            break;
        }
        memory16set(ds*16+r16[si] + 6, 0x0000);
        return;
    } while (1);
}
function* sub_14E12() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3cb6;
    case 0x14E15:
        memory16set(ds*16+r16[si] + 6, 0x001a);
        memory16set(ds*16+r16[si] + 8, 0x3ae8);
        r16[si] += 0x000c;
        if (r16s[si] < signed16(0x3d9a)) {
            pc = 0x14E15;
            break;
        }
        return;
    } while (1);
}
function* sub_14E29() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x14E2F:
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x14E72;
            break;
        }
        if (r16[ax] != 0x001b) {
            pc = 0x14E43;
            break;
        }
        if (memory16get(ds*16+r16[si] - 6) == 0x001a) {
            pc = 0x14E68;
            break;
        }
        pc = 0x14E72;
        break;
    case 0x14E43:
        if (r16s[ax] >= signed16(0x001a)) {
            pc = 0x14E72;
            break;
        }
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 14542);
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x14E59;
            break;
        }
        r16[ax] >>= 1;
    case 0x14E59:
        _cwd();
        if (r16s[dx] < memory16gets(ds*16+0x915C)) {
            pc = 0x14E72;
            break;
        }
        if (r16[dx] != memory16get(ds*16+0x915C)) {
            pc = 0x14E68;
            break;
        }
        if (r16[ax] <= memory16get(ds*16+0x915A)) {
            pc = 0x14E72;
            break;
        }
    case 0x14E68:
        memory16set(ds*16+r16[si] + 6, 0x001a);
        memory16set(ds*16+r16[si] + 8, 0x3ae8);
    case 0x14E72:
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x14E2F;
            break;
        }
        return;
    } while (1);
}
function* sub_14E78() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x8F42, 0x0000);
        memory16set(ds*16+0x8F44, 0x0000);
        memory16set(ds*16+0x3818, 0xffff);
        yield* sub_15435();
        memory16set(ds*16+0x39B2, 0xffff);
    case 0x14E93:
        memory[ds*16+0x8F5B] = 0x00;
        yield* sub_15369();
        if (memory16get(ds*16+0x8F44) == 0x0004) {
            pc = 0x14F20;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F42);
        r16[bx] = memory16get(ds*16+0x8F44);
        if (r16[ax] != memory16get(ds*16+0x3818)) {
            pc = 0x14EB5;
            break;
        }
        if (r16[bx] == memory16get(ds*16+0x381A)) {
            pc = 0x14F27;
            break;
        }
    case 0x14EB5:
        r16[dx] = r16[bx];
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] += r16[dx];
        r16[ax] += r16[bx];
        r16[bx] = 0x000c;
        _mul(r16[bx]);
        r16[si] = 0x3cb6;
        r16[si] += r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x14E93;
            break;
        }
        if (r16[ax] == 0x001a) {
            pc = 0x14EF3;
            break;
        }
        if (r16[ax] == 0x001b) {
            pc = 0x14F04;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F42);
        memory16set(ds*16+0x3818, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8F44);
        memory16set(ds*16+0x381A, r16[ax]);
        push(r16[si]);
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        yield* sub_15319();
        r16[si] = pop();
        yield* sub_1521A();
        pc = 0x14E93;
        break;
    case 0x14EF3:
        yield* sub_1576D();
        r16[si] = 0x392b;
        yield* sub_15787();
        memory16set(ds*16+0x39B2, 0xffff);
        pc = 0x14E93;
        break;
    case 0x14F04:
        r16[ax] = memory16get(ds*16+0x3816);
        r16[ax] += 0x0013;
        if (r16s[ax] < signed16(0x0019)) {
            pc = 0x14F11;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x14F11:
        memory16set(ds*16+0x3816, r16[ax]);
        yield* sub_14D38();
        memory16set(ds*16+0x39B2, 0xffff);
        pc = 0x14E93;
        break;
    case 0x14F20:
        if (memory16get(ds*16+0x8F42) == 0x0000) {
            pc = 0x14F92;
            break;
        }
    case 0x14F27:
        memory16set(ds*16+0x3818, 0xffff);
        if (memory16gets(ds*16+0x39B2) >= 0 /*CHECK*/) {
            pc = 0x14F37;
            break;
        }
        pc = 0x14E93;
        break;
    case 0x14F37:
        yield* sub_14FE3();
        if (flags.zero) {
            pc = 0x14F80;
            break;
        }
        yield* sub_1576D();
        r16[si] = 0x3952;
        yield* sub_15787();
        r16[ax] = memory16get(ds*16+0x39B2);
        _cwd();
        flags.carry = memory16get(ds*16+0x915A) < r16[ax];
        memory16set(ds*16+0x915A, memory16get(ds*16+0x915A) - r16[ax]);
        memory16set(ds*16+0x915C, memory16get(ds*16+0x915C) - r16[dx] - flags.carry);
        r16[si] = memory16get(ds*16+0x39B4);
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        r16[bx] <<= 1;
        yield* indirectCall(ds, memory16get(ds*16+r16[bx] + 14362));
        memory16set(ds*16+0x39B2, 0xffff);
        yield* sub_1577D();
        yield* sub_14E29();
        r16[si] = memory16get(ds*16+0x39B4);
        if (memory16get(ds*16+r16[si] + 6) != 0x0002) {
            pc = 0x14F77;
            break;
        }
        pc = 0x14E93;
        break;
    case 0x14F77:
        r16[si] = 0x3967;
        yield* sub_15787();
        pc = 0x14E93;
        break;
    case 0x14F80:
        yield* sub_1576D();
        r16[si] = 0x3902;
        yield* sub_15787();
        memory16set(ds*16+0x39B2, 0xffff);
        pc = 0x14E93;
        break;
    case 0x14F92:
        yield* sub_15488();
        return;
    } while (1);
}
function* loc_14FC6() {
    r16[bx] = r16[ax];
    r16[bx] >>= 1;
    r16[si] = memory16get(ds*16+r16[bx] + 16086);
    yield* sub_15787();
    memory[ds*16+0x3AE0] = 0x00;
    return;
    memory16set(ds*16+0x9150, 0x00dc);
    return;
    memory16set(ds*16+0x918A, memory16get(ds*16+0x918A) + 1);
}
function* sub_14FE3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = memory16get(ds*16+0x39B4);
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        if (r16[bx] != 0x0003) {
            pc = 0x14FF2;
            break;
        }
        pc = 0x150B4;
        break;
    case 0x14FF2:
        if (r16[bx] != 0x0004) {
            pc = 0x14FFA;
            break;
        }
        pc = 0x150BD;
        break;
    case 0x14FFA:
        if (r16[bx] != 0x0007) {
            pc = 0x15002;
            break;
        }
        pc = 0x150BD;
        break;
    case 0x15002:
        if (r16[bx] != 0x0005) {
            pc = 0x1500A;
            break;
        }
        pc = 0x150C6;
        break;
    case 0x1500A:
        if (r16[bx] != 0x0006) {
            pc = 0x15012;
            break;
        }
        pc = 0x150CF;
        break;
    case 0x15012:
        if (r16[bx] != 0x000c) {
            pc = 0x1501A;
            break;
        }
        pc = 0x150D8;
        break;
    case 0x1501A:
        if (r16[bx] != 0x0010) {
            pc = 0x15022;
            break;
        }
        pc = 0x150F5;
        break;
    case 0x15022:
        if (r16[bx] != 0x0016) {
            pc = 0x1502A;
            break;
        }
        pc = 0x150FE;
        break;
    case 0x1502A:
        if (r16[bx] != 0x0018) {
            pc = 0x15032;
            break;
        }
        pc = 0x15107;
        break;
    case 0x15032:
        if (r16[bx] != 0x0019) {
            pc = 0x1503A;
            break;
        }
        pc = 0x15110;
        break;
    case 0x1503A:
        r8[al] = memory[ds*16+r16[bx] + 14413];
        if (r8[al] & 0x01) {
            pc = 0x1508E;
            break;
        }
        if (r8[al] & 0x02) {
            pc = 0x150A8;
            break;
        }
        if (r8[al] & 0x04) {
            pc = 0x15074;
            break;
        }
        if (!(r8[al] & 0x10)) {
            pc = 0x1505E;
            break;
        }
        if (memory16get(ds*16+0x914C) == 0x0000) {
            pc = 0x150B0;
            break;
        }
        if (memory16get(ds*16+0x9148) == 0x0000) {
            pc = 0x150B0;
            break;
        }
        pc = 0x150AD;
        break;
    case 0x1505E:
        if (!(r8[al] & 0x08)) {
            pc = 0x150B0;
            break;
        }
        if (memory16get(ds*16+0x914C) == 0x0000) {
            pc = 0x150B0;
            break;
        }
        r16[di] = memory16get(ds*16+0x914E);
        if (r16[bx] == memory16get(ds*16+r16[di] + 54)) {
            pc = 0x15084;
            break;
        }
        pc = 0x150AD;
        break;
    case 0x15074:
        if (memory16get(ds*16+0x9148) == 0x0000) {
            pc = 0x150B0;
            break;
        }
        r16[di] = memory16get(ds*16+0x914A);
        if (r16[bx] != memory16get(ds*16+r16[di] + 54)) {
            pc = 0x150AD;
            break;
        }
    case 0x15084:
        r16[ax] = memory16get(ds*16+r16[di] + 52);
        if (r16[ax] != memory16get(ds*16+r16[di] + 36)) {
            pc = 0x150B0;
            break;
        }
        pc = 0x150AD;
        break;
    case 0x1508E:
        r16[di] = memory16get(ds*16+0x9136);
        if (r16[bx] == memory16get(ds*16+r16[di] + 54)) {
            pc = 0x15084;
            break;
        }
        if (memory16get(ds*16+0x9134) == 0x0000) {
            pc = 0x150B0;
            break;
        }
        if (memory16get(ds*16+0x9134) == 0x0094) {
            pc = 0x150B0;
            break;
        }
        pc = 0x150AD;
        break;
    case 0x150A8:
        yield* sub_1100E();
        if (_FIXME_) {
            pc = 0x150B0;
            break;
        }
    case 0x150AD:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    case 0x150B0:
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    case 0x150B4:
        if (memory16get(ds*16+0x915E) == 0x0002) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x150BD:
        if (memory16get(ds*16+0x9186) == 0x0027) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x150C6:
        if (memory16get(ds*16+0x9132) == 0x0003) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x150CF:
        if (memory16get(ds*16+0x9162) != 0x0000) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x150D8:
        r16[di] = 0x9134;
        r16[cx] = 0x0007;
    case 0x150DE:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x150EE;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 2);
        r16[ax] = memory16get(ds*16+r16[bx] + 52);
        if (r16[ax] != memory16get(ds*16+r16[bx] + 36)) {
            pc = 0x150B0;
            break;
        }
    case 0x150EE:
        r16[di] += 0x0006;
        if (--r16[cx]) {
            pc = 0x150DE;
            break;
        }
        pc = 0x150AD;
        break;
    case 0x150F5:
        if (memory16get(ds*16+0x9160) != 0x0000) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x150FE:
        if (memory16get(ds*16+0x918A) == 0x0009) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x15107:
        if (memory[ds*16+0x9223] != 0x00) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
    case 0x15110:
        if (memory16get(ds*16+0x9150) != 0x0000) {
            pc = 0x150AD;
            break;
        }
        pc = 0x150B0;
        break;
        return;
    } while (1);
}
function* sub_15119() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3cb6;
        r16[di] = memory16get(ds*16+0x9008);
    case 0x15120:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x15145;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0x0094) {
            pc = 0x15140;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 54);
        memory16set(ds*16+r16[si] + 6, r16[bx]);
        memory16set(ds*16+r16[si] + 10, r16[di]);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 14488);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        r16[si] += 0x000c;
    case 0x15140:
        r16[di] = memory16get(ds*16+r16[di] + 10);
        pc = 0x15120;
        break;
    case 0x15145:
        memory16set(ds*16+r16[si] + 6, 0x0000);
        r16[si] += 0x000c;
        if (r16s[si] <= signed16(0x3d9a)) {
            pc = 0x15145;
            break;
        }
        return;
    } while (1);
}
function* sub_15154() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x8F42, 0x0000);
        memory16set(ds*16+0x8F44, 0x0000);
        memory16set(ds*16+0x3818, 0xffff);
        yield* sub_15435();
        memory16set(ds*16+0x39B2, 0xffff);
    case 0x1516F:
        memory[ds*16+0x8F5B] = 0x00;
        yield* sub_15369();
        if (memory16get(ds*16+0x8F44) == 0x0004) {
            pc = 0x151D5;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F42);
        r16[bx] = memory16get(ds*16+0x8F44);
        if (r16[ax] != memory16get(ds*16+0x3818)) {
            pc = 0x15191;
            break;
        }
        if (r16[bx] == memory16get(ds*16+0x381A)) {
            pc = 0x151DC;
            break;
        }
    case 0x15191:
        r16[dx] = r16[bx];
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] += r16[dx];
        r16[ax] += r16[bx];
        r16[bx] = 0x000c;
        _mul(r16[bx]);
        r16[si] = 0x3cb6;
        r16[si] += r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x1516F;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F42);
        memory16set(ds*16+0x3818, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8F44);
        memory16set(ds*16+0x381A, r16[ax]);
        push(r16[si]);
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        r16[si] = memory16get(ds*16+r16[si] + 10);
        memory[ds*16+0x3AE1] = 0xff;
        r16[bx] = memory16get(ds*16+r16[si] + 52);
        yield* sub_15319();
        r16[si] = pop();
        yield* sub_15240();
        memory[ds*16+0x3AE1] = 0x00;
        pc = 0x1516F;
        break;
    case 0x151D5:
        if (memory16get(ds*16+0x8F42) == 0x0000) {
            pc = 0x15216;
            break;
        }
    case 0x151DC:
        memory16set(ds*16+0x3818, 0xffff);
        r16[ax] = memory16get(ds*16+0x39B2);
        if (r16s[ax] < 0) {
            pc = 0x1516F;
            break;
        }
        _cwd();
        flags.carry = (memory16get(ds*16+0x915A) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0x915A, memory16get(ds*16+0x915A) + r16[ax]);
        memory16set(ds*16+0x915C, memory16get(ds*16+0x915C) + r16[dx] + flags.carry);
        memory16set(ds*16+0x39B2, 0xffff);
        yield* sub_1577D();
        r16[si] = memory16get(ds*16+0x39B4);
        memory16set(ds*16+r16[si] + 6, 0x0000);
        r16[si] = memory16get(ds*16+r16[si] + 10);
        yield* sub_13788();
        yield* sub_1576D();
        r16[si] = 0x3980;
        yield* sub_15787();
        pc = 0x1516F;
        break;
    case 0x15216:
        yield* sub_15488();
        return;
    } while (1);
}
function* sub_1521A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x39B4, r16[si]);
        r16[si] = 0x3ac2;
        yield* sub_15787();
        r16[si] = memory16get(ds*16+0x39B4);
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 14542);
        if (memory16get(ds*16+0x991C) != 0x0005) {
            pc = 0x1523A;
            break;
        }
        r16[ax] >>= 1;
    case 0x1523A:
        memory16set(ds*16+0x39B2, r16[ax]);
    {yield* sub_157FA(); return; };
        return;
    } while (1);
}
function* sub_15240() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x39B4, r16[si]);
        memory16set(ds*16+0x3C9A, 0x00f7);
        memory16set(ds*16+0x3C9C, 0x0078);
        memory16set(ds*16+0x3C9E, 0xf700);
    case 0x15256:
        yield* sub_10A51();
        yield* sub_10C93();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_154DB();
        memory16set(ds*16+0x3C9C, memory16get(ds*16+0x3C9C) - 0x0002);
        if (memory16gets(ds*16+0x3C9C) > signed16(0x0068)) {
            pc = 0x15256;
            break;
        }
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf470);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf700);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf990);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf700);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf470);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf700);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf990);
        r16[cx] = 0x0003;
        yield* sub_154FC();
        memory16set(ds*16+0x3C9E, 0xf700);
        r16[cx] = 0x0003;
        yield* sub_154FC();
    case 0x152D7:
        yield* sub_10A51();
        yield* sub_10C93();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_154DB();
        memory16set(ds*16+0x3C9C, memory16get(ds*16+0x3C9C) + 0x0002);
        if (memory16gets(ds*16+0x3C9C) < signed16(0x0080)) {
            pc = 0x152D7;
            break;
        }
        r16[si] = 0x3ab4;
        yield* sub_15787();
        r16[si] = memory16get(ds*16+0x39B4);
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 14542);
        r16[di] = memory16get(ds*16+r16[si] + 10);
        r16[ax] = 0x07d0;
        _mul(memory16get(ds*16+r16[di] + 52));
        r16[ax] += r16[bx];
        r16[ax] >>= 1;
        memory16set(ds*16+0x39B2, r16[ax]);
    {yield* sub_157FA(); return; };
        return;
    } while (1);
}
function* sub_15319() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_1576D();
        r16[bx] = pop();
        push(r16[bx]);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 14438);
        yield* sub_15787();
        r16[ax] = pop();
        r16[bx] = pop();
        if (memory[ds*16+0x3ADE] == 0x00)
            return;
        if (r16[ax] == 0x0001) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x0013) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x0012) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x0008) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x000a) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x000e) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x0009) {
            pc = 0x1535C;
            break;
        }
        if (r16[ax] == 0x000d) {
            pc = 0x1535C;
            break;
        }
        return;
    case 0x1535C:
        push(r16[bx]);
        r16[si] = 0x3ad4;
        yield* sub_15787();
        r16[ax] = pop();
        r16[ax] += 1;
        yield* sub_157FA();
        return;
    } while (1);
}
function* sub_15369() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x15369:
        if (memory16get(ds*16+0x3ADC) == 0x0000) {
            pc = 0x15377;
            break;
        }
        memory16set(ds*16+0x3ADC, memory16get(ds*16+0x3ADC) - 1);
        pc = 0x15416;
        break;
    case 0x15377:
        if (memory[ds*16+0x8F5B] == 0x00) {
            pc = 0x15381;
            break;
        }
        pc = 0x15429;
        break;
    case 0x15381:
        if (memory[ds*16+0x8F59] != 0x00) {
            pc = 0x1538B;
            break;
        }
        pc = 0x15416;
        break;
    case 0x1538B:
        memory16set(ds*16+0x8E88, 0x0008);
        memory16set(ds*16+0x3ADC, 0x0004);
        yield* sub_15488();
        if (!(memory[ds*16+0x8F59] & 0x04)) {
            pc = 0x153C5;
            break;
        }
        if (memory16get(ds*16+0x8F44) != 0x0004) {
            pc = 0x153B7;
            break;
        }
    case 0x153A8:
        r16[ax] = r16[ax] ^ r16[ax];
        if (memory16get(ds*16+0x8F42) != 0x0000) {
            pc = 0x153B2;
            break;
        }
        r16[ax] += 1;
    case 0x153B2:
        memory16set(ds*16+0x8F42, r16[ax]);
        pc = 0x15413;
        break;
    case 0x153B7:
        memory16set(ds*16+0x8F42, memory16get(ds*16+0x8F42) - 1);
        if (memory16gets(ds*16+0x8F42) >= 0) {
            pc = 0x15413;
            break;
        }
        memory16set(ds*16+0x8F42, 0x0004);
        pc = 0x15413;
        break;
    case 0x153C5:
        if (!(memory[ds*16+0x8F59] & 0x08)) {
            pc = 0x153E6;
            break;
        }
        if (memory16get(ds*16+0x8F44) == 0x0004) {
            pc = 0x153A8;
            break;
        }
        memory16set(ds*16+0x8F42, memory16get(ds*16+0x8F42) + 1);
        if (memory16gets(ds*16+0x8F42) <= signed16(0x0004)) {
            pc = 0x15413;
            break;
        }
        memory16set(ds*16+0x8F42, 0x0000);
        pc = 0x15413;
        break;
    case 0x153E6:
        if (!(memory[ds*16+0x8F59] & 0x01)) {
            pc = 0x153FB;
            break;
        }
        memory16set(ds*16+0x8F44, memory16get(ds*16+0x8F44) - 1);
        if (memory16gets(ds*16+0x8F44) >= 0) {
            pc = 0x15413;
            break;
        }
        memory16set(ds*16+0x8F44, 0x0004);
        pc = 0x15413;
        break;
    case 0x153FB:
        if (!(memory[ds*16+0x8F59] & 0x02)) {
            pc = 0x15413;
            break;
        }
        memory16set(ds*16+0x8F44, memory16get(ds*16+0x8F44) + 1);
        if (memory16gets(ds*16+0x8F44) <= signed16(0x0004)) {
            pc = 0x15413;
            break;
        }
        memory16set(ds*16+0x8F44, 0x0000);
    case 0x15413:
        yield* sub_15435();
    case 0x15416:
        yield* sub_10C93();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10A51();
        memory16set(ds*16+0x919C, memory16get(ds*16+0x919C) + 1);
        pc = 0x15369;
        break;
    case 0x15429:
        memory[ds*16+0x8F5B] = 0x00;
        memory16set(ds*16+0x8E88, 0x0009);
        return;
    } while (1);
}
function* sub_15435() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x8F44);
        if (r16[bx] == 0x0004) {
            pc = 0x15465;
            break;
        }
        bp = r16[bx];
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] += bp;
        r16[bx] = r16[bx] + memory16get(ds*16+0x8F42);
        r16[ax] = 0x000c;
        _mul(r16[bx]);
        r16[bx] = r16[ax];
        r16[cx] = memory16get(ds*16+r16[bx] + 15544);
        r16[dx] = memory16get(ds*16+r16[bx] + 15546);
        r16[cx] += 0x000a;
        r16[dx] += 0x001f;
        r16[si] = 0xb282;
    {yield* sub_10C2D(); return; };
    case 0x15465:
        r16[cx] = 0x0004;
        r16[si] = 0xdde0;
        if (memory16get(ds*16+0x8F42) == 0x0000) {
            pc = 0x15482;
            break;
        }
        r16[cx] = 0x002d;
        r16[si] = 0xe1e8;
        if (memory[ds*16+0x3ADE] != 0x00) {
            pc = 0x15482;
            break;
        }
        r16[si] = 0xdfe4;
    case 0x15482:
        r16[dx] = 0x00a8;
    {yield* sub_10C2D(); return; };
        return;
    } while (1);
}
function* sub_15488() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+0x8F44);
        if (r16[bx] == 0x0004) {
            pc = 0x154B8;
            break;
        }
        r16[ax] = r16[bx];
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] += r16[ax];
        r16[bx] = r16[bx] + memory16get(ds*16+0x8F42);
        r16[ax] = 0x000c;
        _mul(r16[bx]);
        r16[bx] = r16[ax];
        r16[cx] = memory16get(ds*16+r16[bx] + 15544);
        r16[dx] = memory16get(ds*16+r16[bx] + 15546);
        r16[cx] += 0x000a;
        r16[dx] += 0x001f;
        r16[si] = 0xb218;
    {yield* sub_10C2D(); return; };
    case 0x154B8:
        r16[cx] = 0x0004;
        r16[si] = 0xe3ec;
        if (memory16get(ds*16+0x8F42) == 0x0000) {
            pc = 0x154D5;
            break;
        }
        r16[cx] = 0x002d;
        r16[si] = 0xe7f4;
        if (memory[ds*16+0x3ADE] != 0x00) {
            pc = 0x154D5;
            break;
        }
        r16[si] = 0xe5f0;
    case 0x154D5:
        r16[dx] = 0x00a8;
    {yield* sub_10C2D(); return; };
        return;
    } while (1);
}
function* sub_154DB() {
    push(memory16get(_ss*16+16));
    memory16set(_ss*16+16, 0x0068);
    r16[cx] = memory16get(ds*16+0x3C9A);
    r16[dx] = memory16get(ds*16+0x3C9C);
    r16[si] = memory16get(ds*16+0x3C9E);
    yield* sub_10875();
    memory16set(_ss*16+16, pop());
}
function* sub_154FC() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x154FC:
        push(r16[cx]);
        yield* sub_10A51();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10C93();
        yield* sub_154DB();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x154FC;
            break;
        }
        return;
    } while (1);
}
function* sub_15510() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x3C9A, 0x0106);
        memory16set(ds*16+0x3C9C, 0x0088);
        memory16set(ds*16+0x3C9E, 0xf700);
    case 0x15522:
        yield* sub_10A51();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10C93();
        yield* sub_154DB();
        if (memory16get(ds*16+0x3C9A) == 0x011c) {
            pc = 0x15545;
            break;
        }
        memory16set(ds*16+0x3C9A, memory16get(ds*16+0x3C9A) + 0x0002);
        memory16set(ds*16+0x3C9C, memory16get(ds*16+0x3C9C) - 0x0002);
        pc = 0x15522;
        break;
    case 0x15545:
        memory16set(ds*16+0x3C9E, 0xf990);
        r16[cx] = 0x0006;
        yield* sub_154FC();
        r8[ah] = 0x01;
        interrupt(128);
        memory16set(ds*16+0x8E88, 0x0008);
        memory[ds*16+0x3ADF] = 0x00;
        memory16set(ds*16+0x3C9E, 0xf700);
        r16[cx] = 0x0006;
        yield* sub_154FC();
    case 0x1556C:
        yield* sub_10A51();
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10C93();
        yield* sub_154DB();
        memory16set(ds*16+0x3C9A, memory16get(ds*16+0x3C9A) - 0x0002);
        memory16set(ds*16+0x3C9C, memory16get(ds*16+0x3C9C) + 0x0002);
        if (memory16gets(ds*16+0x3C9A) > signed16(0x0106)) {
            pc = 0x1556C;
            break;
        }
        return;
    } while (1);
}
function* sub_1558E() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1558E:
        yield* sub_10A51();
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x15597:
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + 1);
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x15597;
            break;
        }
        if (memory16get(ds*16+0x3CB6) == 0x0000) {
            pc = 0x155AD;
            break;
        }
        yield* sub_156B8();
        yield* sub_10C93();
        pc = 0x1558E;
        break;
    case 0x155AD:
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x155B3:
        memory16set(ds*16+r16[si], 0x0001);
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x155B3;
            break;
        }
        r16[cx] = 0x0005;
        push(r16[cx]);
        pc = 0x155C6;
        break;
    case 0x155C2:
        push(r16[cx]);
        yield* sub_10A51();
    case 0x155C6:
        yield* sub_156B8();
        yield* sub_10C93();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x155C2;
            break;
        }
        return;
    } while (1);
}
function* sub_155D0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x155D6:
        memory16set(ds*16+r16[si], 0x0000);
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x155D6;
            break;
        }
    case 0x155DF:
        yield* sub_10A51();
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x155E8:
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - 1);
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x155E8;
            break;
        }
        if (memory16get(ds*16+0x3CB6) == 0xfff7) {
            pc = 0x155FE;
            break;
        }
        yield* sub_156B8();
        yield* sub_10C93();
        pc = 0x155DF;
        break;
    case 0x155FE:
        r16[cx] = 0x000b;
        push(r16[cx]);
        pc = 0x15608;
        break;
    case 0x15604:
        push(r16[cx]);
        yield* sub_10A51();
    case 0x15608:
        yield* sub_156B8();
        yield* sub_10C93();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x15604;
            break;
        }
        return;
    } while (1);
}
function* sub_15612() {
    yield* sub_156B8();
    yield* sub_10C93();
    yield* sub_10CB5();
}
function* sub_1561C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x3ADF] != 0x00) {
            pc = 0x15632;
            break;
        }
        if (memory[ds*16+0x3AE0] != 0x00) {
            pc = 0x1563E;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x2654;
        if (r16[ax] != 0) {
            pc = 0x15655;
            break;
        }
    case 0x15632:
        r16[cx] = 0x0107;
        r16[dx] = 0x0029;
        r16[si] = 0xea9e;
        yield* sub_10875();
    case 0x1563E:
        r16[cx] = 0x00f7;
        r16[dx] = 0x0029;
        r16[si] = 0xe9f8;
        yield* sub_10875();
        if (memory[ds*16+0x3AE0] == 0x00) {
            pc = 0x15655;
            break;
        }
        memory[ds*16+0x3AE0] -= 1;
    case 0x15655:
        if (memory[ds*16+0x3ADF] != 0x00)
            return;
        if (memorys[ds*16+0x3AE1] < 0 /*CHECK*/) {
            pc = 0x15684;
            break;
        }
        if (memory[ds*16+0x3AE1] == 0x00) {
            pc = 0x1566B;
            break;
        }
        memory[ds*16+0x3AE1] -= 1;
        pc = 0x15678;
        break;
    case 0x1566B:
        yield* sub_14191();
        r16[ax] &= 0x2654;
        if (r16[ax] != 0)
            return;
        memory[ds*16+0x3AE1] = 0x08;
    case 0x15678:
        r16[cx] = 0x0107;
        r16[dx] = 0x0023;
        r16[si] = 0xebea;
        yield* sub_10875();
    case 0x15684:
        r16[cx] = 0x00f5;
        r16[dx] = 0x0023;
        r16[si] = 0xeb44;
        yield* sub_10875();
        return;
    } while (1);
}
function* sub_15691() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x15697:
        if (memory16get(ds*16+r16[si] + 6) != 0x0000) {
            pc = 0x156A3;
            break;
        }
        memory16set(ds*16+r16[si], 0x0000);
        pc = 0x156B2;
        break;
    case 0x156A3:
        flags.carry2 = memory16gets(ds*16+r16[si]) > 1;
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - 1);
        if (flags.carry2) {
            pc = 0x156B2;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x00ff;
        r16[ax] += 0x0014;
        memory16set(ds*16+r16[si], r16[ax]);
    case 0x156B2:
        r16[si] += 0x000c;
        if (--r16[cx]) {
            pc = 0x15697;
            break;
        }
        return;
    } while (1);
}
function* sub_156B8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x3cb6;
        r16[cx] = 0x0014;
    case 0x156BE:
        push(r16[cx]);
        if (memory16gets(ds*16+r16[di]) > signed16(0x0000)) {
            pc = 0x156EC;
            break;
        }
        if (memory16get(ds*16+r16[di]) == 0xfff8) {
            pc = 0x156D4;
            break;
        }
        yield* sub_10CD7();
        if (memory16get(ds*16+r16[di]) != 0x0000) {
            pc = 0x156D4;
            break;
        }
        pc = 0x15761;
        break;
    case 0x156D4:
        push(r16[di]);
        r16[cx] = memory16get(ds*16+r16[di] + 2);
        r16[dx] = memory16get(ds*16+r16[di] + 4);
        r16[bx] = memory16get(ds*16+r16[di]);
        r16[bx] += 0x0009;
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 15520);
        yield* sub_10875();
        r16[di] = pop();
        pc = 0x15761;
        break;
    case 0x156EC:
        if (memory16gets(ds*16+r16[di]) > signed16(0x0002)) {
            pc = 0x15705;
            break;
        }
        if (memory16get(ds*16+r16[di]) != 0x0002) {
            pc = 0x15700;
            break;
        }
        if (memory16gets(ds*16+0x8E88) >= 0 /*CHECK*/) {
            pc = 0x15700;
            break;
        }
        memory16set(ds*16+0x8E8A, 0x0000);
    case 0x15700:
        yield* sub_10CD7();
        pc = 0x15761;
        break;
    case 0x15705:
        r16[bx] = pop();
        push(r16[bx]);
        r16[bx] &= 0x0001;
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 15538);
        r16[cx] = memory16get(ds*16+r16[di] + 2);
        r16[dx] = memory16get(ds*16+r16[di] + 4);
        push(r16[di]);
        yield* sub_10875();
        r16[di] = pop();
        r16[bx] = memory16get(ds*16+r16[di] + 8);
        r16[si] = memory16get(ds*16+r16[bx]);
        r16[bx] += 0x0002;
        if (r16[si] & r16[si]) {
            pc = 0x1572E;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[bx]);
        r16[si] = memory16get(ds*16+r16[bx]);
        r16[bx] += 0x0002;
    case 0x1572E:
        memory16set(ds*16+r16[di] + 8, r16[bx]);
        r16[cx] = memory16get(ds*16+r16[di] + 2);
        r16[dx] = memory16get(ds*16+r16[di] + 4);
        push(es);
        r16[ax] = _seg007;
        es = r16[ax];
        r16[cx] = r16[cx] + memory16get(es*16+r16[si]);
        r16[dx] = r16[dx] + memory16get(es*16+r16[si] + 2);
        r16[ax] = memory16get(es*16+r16[si] + 4);
        r16[ax] >>= 1;
        r16[ax] -= 0x0010;
        r16[cx] -= r16[ax];
        r16[ax] = memory16get(es*16+r16[si] + 6);
        r16[ax] += 1;
        r16[ax] >>= 1;
        r16[ax] -= 0x000e;
        r16[dx] -= r16[ax];
        es = pop();
        push(r16[di]);
        yield* sub_10875();
        r16[di] = pop();
    case 0x15761:
        r16[di] += 0x000c;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x15769;
            break;
        }
        return;
    case 0x15769:
        pc = 0x156BE;
        break;
        return;
    } while (1);
}
function* sub_1576D() {
    yield* sub_10C71();
    memory16set(ds*16+0x8F46, 0x0037);
    memory16set(ds*16+0x8F48, 0x0076);
}
function* sub_1577D() {
    r16[ax] = memory16get(ds*16+0x915A);
    r16[dx] = memory16get(ds*16+0x915C);
{yield* loc_10B1D(); return; };
}
function* sub_15787() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x15787:
        memory[ds*16+0x8F40] = 0xff;
        push(r16[si]);
        yield* sub_15691();
        yield* sub_156B8();
        yield* sub_10C93();
        yield* sub_10A51();
        r16[si] = pop();
    case 0x1579A:
        yield* sub_14191();
        r16[ax] &= 0x0003;
        if (r16[ax] == 0) {
            pc = 0x1579A;
            break;
        }
        r16[ax] -= 1;
        r16[ax] |= 0x0080;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = r16[si];
    case 0x157AA:
        if (memory[ds*16+r16[di]] == 0x00) {
            pc = 0x157BD;
            break;
        }
        if (memory[ds*16+r16[di]] == 0x20) {
            pc = 0x157BD;
            break;
        }
        if (memory[ds*16+r16[di]] == 0x0d) {
            pc = 0x157BD;
            break;
        }
        r16[ax] += 1;
        r16[di] += 1;
        pc = 0x157AA;
        break;
    case 0x157BD:
        r16[ax] = r16[ax] + memory16get(ds*16+0x8F46);
        if (r16s[ax] <= signed16(0x004b)) {
            pc = 0x157C9;
            break;
        }
        yield* sub_15829();
    case 0x157C9:
        r16[ax] = r16[ax] ^ r16[ax];
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x157F4;
            break;
        }
        if (r8[al] == 0x20) {
            pc = 0x157E4;
            break;
        }
        if (r8[al] != 0x0d) {
            pc = 0x157DD;
            break;
        }
        yield* sub_15829();
        pc = 0x15787;
        break;
    case 0x157DD:
        push(r16[si]);
        yield* sub_10CF9();
        r16[si] = pop();
        pc = 0x157C9;
        break;
    case 0x157E4:
        memory16set(ds*16+0x8F46, memory16get(ds*16+0x8F46) + 1);
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x157F4;
            break;
        }
        if (r8[al] == 0x20) {
            pc = 0x157E4;
            break;
        }
        r16[si] -= 1;
        pc = 0x15787;
        break;
    case 0x157F4:
        memory[ds*16+0x8F40] = 0x00;
        return;
    } while (1);
}
function* sub_157FA() {
    memory[ds*16+0x8F40] = 0xff;
    push(r16[ax]);
    yield* sub_10A51();
    yield* sub_15691();
    yield* sub_156B8();
    yield* sub_10C93();
    r16[ax] = pop();
    yield* sub_1580D();
}
function* sub_1580D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[ax] < signed16(0x000a)) {
            pc = 0x1581D;
            break;
        }
        _cwd();
        r16[bx] = 0x000a;
        div(r16[bx]);
        push(r16[dx]);
        yield* sub_1580D();
        r16[ax] = pop();
    case 0x1581D:
        r16[ax] += 0x0030;
        yield* sub_10CF9();
        memory[ds*16+0x8F40] = 0x00;
        return;
    } while (1);
}
function* sub_15829() {
    r16[ax] = 0x0037;
    memory16set(ds*16+0x8F46, r16[ax]);
    memory16set(ds*16+0x8F48, memory16get(ds*16+0x8F48) + 0x0007);
}
function* sub_15835() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x3de4;
        r16[cx] = 0x0007;
    case 0x1583B:
        push(r16[cx]);
        lodsw_data_forward();
        r16[cx] = r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[di] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[di]);
        r16[di] += 0x0002;
        if (r16[ax] & r16[ax]) {
            pc = 0x15855;
            break;
        }
        r16[di] = memory16get(ds*16+r16[di]);
        r16[ax] = memory16get(ds*16+r16[di]);
        r16[di] += 0x0002;
    case 0x15855:
        memory16set(ds*16+r16[si] - 2, r16[di]);
        push(r16[si]);
        r16[si] = r16[ax];
        yield* sub_10875();
        r16[si] = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1583B;
            break;
        }
        return;
    } while (1);
}
function* sub_15863() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = r16[ax] ^ r16[ax];
        r8[ah] = 0x02;
        r8[al] = 0x00;
        interrupt(128);
        memory16set(ds*16+0x3754, 0x3625);
        memory16set(ds*16+0x3752, 0x0078);
        memory16set(ds*16+0x3750, 0x0000);
        r16[di] = 0x9a40;
        r16[cx] = 0x0030;
    case 0x15883:
        yield* sub_14191();
        stosw_data_forward();
        yield* sub_14191();
        stosw_data_forward();
        yield* sub_14191();
        r16[ax] &= 0x1fff;
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x15883;
            break;
        }
        yield* sub_10DE7();
        yield* sub_10D81();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15916;
            break;
        }
    case 0x158A1:
        yield* sub_10A0D();
        yield* sub_10D1B();
        if (memory16gets(ds*16+0x3750) < signed16(0x0012)) {
            pc = 0x158D9;
            break;
        }
        memory16set(ds*16+0x3752, 0x0078);
        r16[si] = memory16get(ds*16+0x3754);
        yield* sub_10AFB();
        if (memory16gets(ds*16+0x3750) < signed16(0x0024)) {
            pc = 0x158D9;
            break;
        }
        if (memory16gets(ds*16+0x3750) >= signed16(0x0036)) {
            pc = 0x158D9;
            break;
        }
        memory16set(ds*16+0x3752, 0x0096);
        r16[si] = memory16get(ds*16+0x3754);
        r16[si] += 0x0014;
        yield* sub_10AFB();
    case 0x158D9:
        yield* sub_10831();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15916;
            break;
        }
        yield* sub_10A51();
        memory16set(ds*16+0x3750, memory16get(ds*16+0x3750) + 1);
        if (memory16get(ds*16+0x3750) != 0x0048) {
            pc = 0x158A1;
            break;
        }
        memory16set(ds*16+0x3750, 0x0000);
        memory16set(ds*16+0x3754, memory16get(ds*16+0x3754) + 0x0028);
        if (memory16get(ds*16+0x3754) != 0x3715) {
            pc = 0x158A1;
            break;
        }
        yield* sub_159AA();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15916;
            break;
        }
        memory16set(ds*16+0x3754, 0x3625);
        pc = 0x158A1;
        break;
    case 0x15916:
        memory[ds*16+0x8F5B] = 0x00;
        r8[ah] = 0x01;
        interrupt(128);
        yield* sub_10DE7();
        yield* sub_10D81();
        return;
    } while (1);
}
function* sub_15926() {
    push(r16[si]);
    push(r16[cx]);
    yield* sub_15935();
    r16[cx] = pop();
    r16[si] = pop();
    r16[ax] = 0x0064;
    yield* sub_1595D();
{yield* sub_15950(); return; };
}
function* sub_15935() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_10BC7();
        r16[cx] = 0x0030;
        r16[di] = 0x9a40;
    case 0x1593E:
        yield* sub_14191();
        stosw_data_forward();
        yield* sub_14191();
        stosw_data_forward();
        yield* sub_14191();
        r16[ax] &= 0x1fff;
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x1593E;
            break;
        }
        return;
    } while (1);
}
function* sub_15950() {
    yield* sub_10E2B();
    yield* sub_10D81();
    yield* sub_10BE9();
    yield* sub_1426A();
}
function* sub_1595D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x3752, r16[ax]);
        memory16set(ds*16+0x3754, r16[si]);
        if (memory[ds*16+0x374E] == 0x00) {
            pc = 0x1598F;
            break;
        }
        yield* sub_10DE7();
    case 0x1596E:
        yield* sub_10A0D();
        r16[si] = memory16get(ds*16+0x3754);
        yield* sub_10AFB();
        yield* sub_10831();
        yield* sub_10A51();
        yield* sub_10D81();
        if (memory[ds*16+0x8F5B] == 0x00) {
            pc = 0x1596E;
            break;
        }
        memory[ds*16+0x8F5B] = 0x00;
        return;
    case 0x1598F:
        push(r16[cx]);
        yield* sub_10A0D();
        r16[si] = memory16get(ds*16+0x3754);
        yield* sub_10AFB();
        yield* sub_10831();
        yield* sub_10A51();
        yield* sub_10DE7();
        yield* sub_10D81();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1598F;
            break;
        }
        return;
    } while (1);
}
function* sub_159AA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x000c;
        r16[si] = 0x352b;
        r16[cx] = 0x0001;
        yield* sub_1595D();
        r16[cx] = 0x0055;
    case 0x159B9:
        push(r16[cx]);
        yield* sub_10B3F();
        r16[cx] = pop();
        if (memory[ds*16+0x8F5B] != 0x00)
            return;
        if (--r16[cx]) {
            pc = 0x159B9;
            break;
        }
        return;
    } while (1);
}
function* sub_159C8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9152);
        r16[dx] = memory16get(ds*16+0x9154);
        if (r16s[dx] >= memory16gets(ds*16+0x358D)) {
            pc = 0x159D8;
            break;
        }
        return;
    case 0x159D8:
        if (r16[dx] != memory16get(ds*16+0x358D)) {
            pc = 0x159E3;
            break;
        }
        if (r16s[ax] > memory16gets(ds*16+0x358B)) {
            pc = 0x159E3;
            break;
        }
        return;
    case 0x159E3:
        yield* sub_15B0B();
        r16[si] = 0x358b;
        r16[di] = 0x3616;
    case 0x159EC:
        r16[ax] = memory16get(ds*16+0x9152);
        r16[dx] = memory16get(ds*16+0x9154);
        if (r16s[dx] < memory16gets(ds*16+r16[si] - 2)) {
            pc = 0x15A21;
            break;
        }
        if (r16[dx] != memory16get(ds*16+r16[si] - 2)) {
            pc = 0x159FF;
            break;
        }
        if (r16[ax] <= memory16get(ds*16+r16[si] - 4)) {
            pc = 0x15A21;
            break;
        }
    case 0x159FF:
        r16[si] -= 0x0004;
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[si] + 6, r16[ax]);
        r16[cx] = 0x000b;
    case 0x15A10:
        r16[di] -= 1;
        r8[al] = memory[ds*16+r16[di]];
        memory[ds*16+r16[di] + 15] = r8[al];
        if (--r16[cx]) {
            pc = 0x15A10;
            break;
        }
        r16[di] -= 0x0004;
        if (r16s[si] > signed16(0x3567)) {
            pc = 0x159EC;
            break;
        }
    case 0x15A21:
        r16[ax] = memory16get(ds*16+0x9152);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+0x9154);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        memory[ds*16+r16[di] + 12] = 0x3a;
        memory[ds*16+r16[di] + 13] = 0x3a;
        memory[ds*16+r16[di] + 14] = 0x3a;
        lea(bp, ds, r16[di] + 4);
        r16[bx] = 0x3756;
        r16[ax] = memory16get(ds*16+0x9152);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9154);
        memory16set(ds*16+0xFCE4, r16[ax]);
    case 0x15A4A:
        if (memory16get(ds*16+r16[bx]) == 0x0000) {
            pc = 0x15A7C;
            break;
        }
        memory[ds*16+bp + 0] = 0x30;
    case 0x15A54:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        _FIXME_;
        if (memory16gets(ds*16+0xFCE2) < 0) {
            pc = 0x15A69;
            break;
        }
        memory[ds*16+bp + 0] += 1;
        pc = 0x15A54;
        break;
    case 0x15A69:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
assert(0);
        memory16set(ds*16+0xFCE4, memory16get(ds*16+0xFCE4) + r16[ax] + flags.carry);
        r16[bx] += 0x0004;
        bp += 1;
        pc = 0x15A4A;
        break;
    case 0x15A7C:
        memory[ds*16+0x8F5B] = 0x00;
        lea(bp, ds, r16[di] + 12);
        r16[bx] = 0x33ca;
        r16[di] = r16[di] ^ r16[di];
    case 0x15A89:
        r8[al] = memory[ds*16+r16[bx] + r16[di]];
        memory[ds*16+bp + 0] = r8[al];
    case 0x15A8F:
        push(bp);
        push(r16[bx]);
        push(r16[di]);
        yield* sub_10B3F();
        r16[di] = pop();
        r16[bx] = pop();
        bp = pop();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15AF0;
            break;
        }
        r8[ah] = memory[ds*16+0x8F59];
        r8[ah] &= 0x0c;
        r16[dx] = 0xffff;
        if (r8[ah] & 0x04) {
            pc = 0x15AB6;
            break;
        }
        r16[dx] = 0x0001;
        if (!(r8[ah] & 0x08)) {
            pc = 0x15A8F;
            break;
        }
    case 0x15AB6:
        r16[cx] = 0x0004;
        flags.sign = signed16(r16[di] + r16[dx]) < 0;
        r16[di] += r16[dx];
        if (!flags.sign) {
            pc = 0x15AC0;
            break;
        }
        r16[di] = 0x0027;
    case 0x15AC0:
        if (r16s[di] < signed16(0x0028)) {
            pc = 0x15AC7;
            break;
        }
        r16[di] = r16[di] ^ r16[di];
    case 0x15AC7:
        r8[al] = memory[ds*16+r16[bx] + r16[di]];
        memory[ds*16+bp + 0] = r8[al];
        push(r16[bx]);
        push(bp);
        push(r16[di]);
        push(r16[dx]);
        push(r16[cx]);
        push(r16[ax]);
        yield* sub_10B3F();
        r16[ax] = pop();
        r16[cx] = pop();
        r16[dx] = pop();
        r16[di] = pop();
        bp = pop();
        r16[bx] = pop();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15AF0;
            break;
        }
        r8[al] = memory[ds*16+0x8F59];
        r8[al] &= 0x0c;
        if (r8[al] != r8[ah]) {
            pc = 0x15A8F;
            break;
        }
        if (--r16[cx]) {
            pc = 0x15AC7;
            break;
        }
        pc = 0x15AB6;
        break;
    case 0x15AF0:
        memory[ds*16+0x8F5B] = 0x00;
        bp += 1;
        if (memory[ds*16+bp + 0] == 0x3a) {
            pc = 0x15A89;
            break;
        }
        r16[cx] = 0x0012;
    case 0x15B00:
        push(r16[cx]);
        yield* sub_10B3F();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x15B00;
            break;
        }
        yield* sub_15950();
        return;
    } while (1);
}
function* sub_15B0B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x352b;
        _STOP_("goto loc_15B13");
        return;
    } while (1);
}
function* sub_15B10() {
    r16[si] = 0x353f;
    loc_15B13:
    push(r16[si]);
    yield* sub_15935();
    r16[ax] = 0x000c;
    r16[si] = pop();
    r16[cx] = 0x0001;
{yield* sub_1595D(); return; };
}
function* sub_15B21() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x91B0, 0x0003);
        yield* sub_15935();
        r16[ax] = 0x000c;
        r16[si] = 0x3477;
        r16[cx] = 0x0001;
        yield* sub_1595D();
        memory[ds*16+0x8F5B] = 0x00;
        r16[ax] = r16[ax] ^ r16[ax];
        push(r16[ax]);
    case 0x15B3E:
        yield* sub_109EB();
        memory16set(ds*16+0x3752, 0x000c);
        r16[si] = 0x3477;
        yield* sub_10AFB();
        memory16set(ds*16+0x3752, 0x003c);
        r16[si] = 0x348b;
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] & r16[ax]) {
            pc = 0x15B5F;
            break;
        }
        r16[si] = 0x349f;
    case 0x15B5F:
        yield* sub_10AFB();
        memory16set(ds*16+0x3752, 0x0054);
        r16[si] = 0x34b3;
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] != 0x0001) {
            pc = 0x15B75;
            break;
        }
        r16[si] = 0x34c7;
    case 0x15B75:
        yield* sub_10AFB();
        memory16set(ds*16+0x3752, 0x006c);
        r16[si] = 0x34db;
        if (memory[ds*16+0x8F54] != 0x00) {
            pc = 0x15B8B;
            break;
        }
        r16[si] = 0x3503;
    case 0x15B8B:
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] != 0x0002) {
            pc = 0x15B95;
            break;
        }
        r16[si] += 0x0014;
    case 0x15B95:
        yield* sub_10AFB();
        yield* sub_15C7C();
        yield* sub_10831();
        yield* sub_10A51();
        if (!(memory[ds*16+0x8F59] & 0x01)) {
            pc = 0x15BC0;
            break;
        }
        memory[ds*16+0x8F59] = 0x00;
        memory16set(ds*16+0x8E88, 0x0008);
        r16[ax] = pop();
        r16[ax] -= 1;
        push(r16[ax]);
        if (r16s[ax] >= 0) {
            pc = 0x15B3E;
            break;
        }
        r16[ax] = pop();
        r16[ax] = 0x0002;
        push(r16[ax]);
        pc = 0x15B3E;
        break;
    case 0x15BC0:
        if (!(memory[ds*16+0x8F59] & 0x02)) {
            pc = 0x15BE4;
            break;
        }
        memory[ds*16+0x8F59] = 0x00;
        memory16set(ds*16+0x8E88, 0x0008);
        r16[ax] = pop();
        r16[ax] += 1;
        push(r16[ax]);
        if (r16s[ax] >= signed16(0x0003)) {
            pc = 0x15BDD;
            break;
        }
        pc = 0x15B3E;
        break;
    case 0x15BDD:
        r16[ax] = pop();
        r16[ax] = r16[ax] ^ r16[ax];
        push(r16[ax]);
        pc = 0x15B3E;
        break;
    case 0x15BE4:
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15BEE;
            break;
        }
        pc = 0x15B3E;
        break;
    case 0x15BEE:
        memory[ds*16+0x8F5B] = 0x00;
        memory16set(ds*16+0x8E88, 0x0009);
        r16[ax] = pop();
        push(r16[ax]);
        if (r16[ax] != 0x0002) {
            pc = 0x15C07;
            break;
        }
        memory[ds*16+0x8F54] = (~memory(ds, 0x8F54));
        pc = 0x15B3E;
        break;
    case 0x15C07:
        r16[ax] = pop();
        r16[ax] += 1;
        memory16set(ds*16+0x8E70, r16[ax]);
    {yield* sub_15950(); return; };
        return;
    } while (1);
}
function* sub_15C0F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_15935();
        r16[ax] = 0x0050;
        r16[si] = 0x344f;
        r16[cx] = 0x0001;
        yield* sub_1595D();
        memory[ds*16+0x8F5B] = 0x00;
        r16[ax] = 0x004f;
        push(r16[ax]);
    case 0x15C27:
        yield* sub_109EB();
        memory16set(ds*16+0x3752, 0x0050);
        r16[si] = 0x344f;
        yield* sub_10AFB();
        r16[ax] = pop();
        push(r16[ax]);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r8[al] += 0x30;
        memory[ds*16+0x346C] = r8[al];
        memory16set(ds*16+0x3752, 0x0078);
        r16[si] = 0x3463;
        yield* sub_10AFB();
        yield* sub_15C7C();
        yield* sub_10831();
        yield* sub_10A51();
        if (memory[ds*16+0x8F5B] != 0x00) {
            pc = 0x15C6D;
            break;
        }
        r16[ax] = pop();
        r16[ax] -= 1;
        push(r16[ax]);
        if (r16[ax] != 0) {
            pc = 0x15C27;
            break;
        }
        sp += 0x0002;
        yield* sub_15950();
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    case 0x15C6D:
        sp += 0x0002;
        yield* sub_15950();
        memory[ds*16+0x8F5B] = 0x00;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    } while (1);
}
function* sub_15C7C() {
    r16[ax] = memory16get(ds*16+0x91B0);
    r8[al] += 0x30;
    memory[ds*16+0x33FB] = r8[al];
    r16[si] = 0x33f3;
    yield* sub_10B83();
}
function* sub_15C8B() {
    r16[dx] = 0x41c8;
    r16[ax] = _seg007;
    es = r16[ax];
    r16[di] = r16[di] ^ r16[di];
    yield* sub_1011C();
    r16[dx] = 0x41d2;
    r16[ax] = _seg007;
    es = r16[ax];
    r16[di] = 0x6be6;
    yield* sub_1011C();
    r16[dx] = 0x41de;
    r16[ax] = _seg007;
    es = r16[ax];
    r16[di] = 0xabbc;
    yield* sub_1011C();
    r16[dx] = 0x41e7;
    r16[ax] = _seg005;
    es = r16[ax];
    r16[di] = r16[di] ^ r16[di];
    yield* sub_1011C();
    yield* sub_10DA3();
}
function* sub_15CC5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x991C);
        if (r16[ax] != memory16get(ds*16+0x8E6C)) {
            pc = 0x15CD1;
            break;
        }
        return;
    case 0x15CD1:
        memory16set(ds*16+0x8E6C, r16[ax]);
        yield* sub_15B10();
        r16[ax] = memory16get(ds*16+0x991C);
        r8[al] += 0x30;
        memory[ds*16+0x41EF] = r8[al];
        memory[ds*16+0x41FA] = r8[al];
        memory[ds*16+0x4206] = r8[al];
        memory[ds*16+0x4215] = r8[al];
        memory[ds*16+0x4222] = r8[al];
        memory[ds*16+0x4231] = r8[al];
        r16[dx] = 0x41ee;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0x2ee0;
        r16[dx] = 0xdf16;
        yield* sub_15E52();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        r16[di] = r16[di] ^ r16[di];
        r16[si] = 0xdf16;
        r8[ch] = r8[ch] ^ r8[ch];
    case 0x15D10:
        lodsb_data_forward();
        r8[cl] = r8[al];
        rep_movsw_data_data_forward();
        lodsb_data_forward();
        r8[cl] = r8[al];
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        if (r16s[di] >= signed16(0x2ee0)) {
            pc = 0x15D28;
            break;
        }
        if (r16s[di] < signed16(0x2ee0)) {
            pc = 0x15D10;
            break;
        }
    case 0x15D28:
        r16[dx] = 0x4214;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0x082a;
        r16[dx] = 0xd274;
        yield* sub_15E52();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        r16[dx] = 0x4221;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0x0392;
        r16[dx] = 0xda9e;
        yield* sub_15E52();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        r16[dx] = 0x4230;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0x1e96;
        r16[dx] = 0xde30;
        yield* sub_15E52();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        r16[si] = 0xde30;
        r16[cx] = 0x0073;
        r16[ax] = 0xdf16;
    case 0x15D82:
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
        r16[si] += 0x0002;
        if (--r16[cx]) {
            pc = 0x15D82;
            break;
        }
        r16[dx] = 0x41f9;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0xe480;
        r16[dx] = r16[dx] ^ r16[dx];
        r16[ax] = _seg009;
        push(ds);
        ds = r16[ax];
        yield* sub_15E52();
        ds = pop();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        push(es);
        r16[ax] = _seg008;
        es = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x7a34;
        rep_stosw_data_forward();
        es = pop();
        r16[dx] = 0x4205;
        yield* sub_15E24();
        memory16set(ds*16+0x8E60, r16[ax]);
        r16[bx] = r16[ax];
        r16[cx] = 0xf468;
        r16[dx] = 0x0000;
        r16[ax] = _seg008;
        push(ds);
        ds = r16[ax];
        yield* sub_15E52();
        ds = pop();
        r16[bx] = memory16get(ds*16+0x8E60);
        yield* sub_15E59();
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        r16[di] = 0x5538;
        r16[cx] = 0x1c90;
    case 0x15DEA:
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[dx] |= r16[ax];
        lodsw_data_forward();
        r16[dx] |= r16[ax];
        lodsw_data_forward();
        r16[ax] |= r16[dx];
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x15DEA;
            break;
        }
        ds = pop();
        yield* sub_10DC5();
        yield* sub_15950();
        yield* sub_10D5F();
        return;
    } while (1);
}
function* loc_15E04() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = dseg;
        ds = r16[ax];
        es = r16[ax];
        r16[ax] = 0x0003;
        if (memory16get(ds*16+0x3044) != 0x0004) {
            pc = 0x15E18;
            break;
        }
        r16[ax] = 0x0007;
    case 0x15E18:
        interrupt(16);
        r16[dx] = 0x300f;
        r8[ah] = 0x09;
        interrupt(33);
        _STOP_("goto loc_1054F");
        return;
    } while (1);
}
function* sub_15E24() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x15E24:
        push(r16[dx]);
        r16[ax] = 0x3d00;
        interrupt(33);
        r16[dx] = pop();
        if (!flags.carry)
            return;
        push(r16[dx]);
        yield* sub_15E35();
        r16[dx] = pop();
        pc = 0x15E24;
        break;
        return;
    } while (1);
}
function* sub_15E35() {
    yield* sub_15950();
    yield* sub_10D5F();
    r16[si] = 0x343b;
    memory[ds*16+0x374E] = 0xff;
    yield* sub_15926();
    memory[ds*16+0x374E] = 0x00;
    yield* sub_10D5F();
    yield* sub_15B10();
}
function* sub_15E52() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3f;
        interrupt(33);
        if (flags.carry)
            _STOP_("goto loc_15E04");
        return;
    } while (1);
}
function* sub_15E59() {
    r8[ah] = 0x3e;
    interrupt(33);
}
function* sub_15E5E() {
    var cs = _seg000;
    r16[ax] = 0x3509;
    interrupt(33);
    memory16set(ds*16+0x8E66, r16[bx]);
    memory16set(ds*16+0x8E68, es);
    r16[ax] = 0x2509;
    push(ds);
    r16[dx] = cs;
    ds = r16[dx];
    r16[dx] = 0x5eeb;
    interrupt(33);
    ds = pop();
}
function* sub_15E7A() {
    r16[ax] = 0x2509;
    push(ds);
    r16[dx] = memory16get(ds*16+0x8E66);
    ds = memory16get(ds*16+0x8E68);
    interrupt(33);
    ds = pop();
}
function* sub_15E8A() {
    var cs = _seg000;
    memory16set(cs*16+0x6009, 0x0003);
    r16[ax] = 0x3508;
    interrupt(33);
    memory16set(ds*16+0x8E62, r16[bx]);
    memory16set(ds*16+0x8E64, es);
    r16[ax] = 0x2508;
    push(ds);
    r16[dx] = 0x600b;
    r16[cx] = cs;
    ds = r16[cx];
    interrupt(33);
    ds = pop();
    flags.interrupt = false;
    r8[al] = 0x36;
    out8(67, r8[al]);
    r16[dx] = 0x5555;
    r8[al] = r8[dl];
    out8(64, r8[al]);
    r8[al] = r8[dh];
    out8(64, r8[al]);
    r8[al] = in8(97);
    memory[ds*16+0x3042] = r8[al];
    flags.interrupt = true;
}
function* sub_15EC3() {
    flags.interrupt = false;
    r8[al] = memory[ds*16+0x3042];
    out8(97, r8[al]);
    r8[al] = 0x36;
    out8(67, r8[al]);
    r16[dx] = 0xffff;
    r8[al] = r8[dl];
    out8(64, r8[al]);
    r8[al] = r8[dh];
    out8(64, r8[al]);
    r8[al] = in8(97);
    flags.interrupt = true;
    r16[ax] = 0x2508;
    push(ds);
    r16[dx] = memory16get(ds*16+0x8E62);
    ds = memory16get(ds*16+0x8E64);
    interrupt(33);
    ds = pop();
}
function* sub_15EEB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[ax]);
        push(r16[bx]);
        r16[ax] = dseg;
        ds = r16[ax];
        r8[al] = in8(96);
        if (r8[al] == memory[ds*16+0x2FB8]) {
            pc = 0x15F53;
            break;
        }
        if (r8[al] == memory[ds*16+0x2FC4]) {
            pc = 0x15F6F;
            break;
        }
        if (r8[al] != memory[ds*16+0x2FD0]) {
            pc = 0x15F0A;
            break;
        }
        pc = 0x15F8A;
        break;
    case 0x15F0A:
        if (r8[al] != memory[ds*16+0x2FDC]) {
            pc = 0x15F13;
            break;
        }
        pc = 0x15FA0;
        break;
    case 0x15F13:
        if (r8[al] != memory[ds*16+0x3001]) {
            pc = 0x15F1C;
            break;
        }
        pc = 0x15FB6;
        break;
    case 0x15F1C:
        if (r8[al] != memory[ds*16+0x300D]) {
            pc = 0x15F25;
            break;
        }
        pc = 0x15FEE;
        break;
    case 0x15F25:
        if (r8[al] == memory[ds*16+0x2FB9]) {
            pc = 0x15F5F;
            break;
        }
        if (r8[al] == memory[ds*16+0x2FC5]) {
            pc = 0x15F7F;
            break;
        }
        if (r8[al] == memory[ds*16+0x2FD1]) {
            pc = 0x15F95;
            break;
        }
        if (r8[al] == memory[ds*16+0x2FDD]) {
            pc = 0x15FAB;
            break;
        }
        if (r8[al] != memory[ds*16+0x3002]) {
            pc = 0x15F46;
            break;
        }
        pc = 0x15FCD;
        break;
    case 0x15F46:
        if (r8[al] != memory[ds*16+0x300E]) {
            pc = 0x15F4F;
            break;
        }
        pc = 0x15FF7;
        break;
    case 0x15F4F:
        if (r8[al] != 0x48) {
            pc = 0x15F5B;
            break;
        }
    case 0x15F53:
        memory[ds*16+0x8F59] |= 0x01;
        pc = 0x15FF7;
        break;
    case 0x15F5B:
        if (r8[al] != 0xc8) {
            pc = 0x15F67;
            break;
        }
    case 0x15F5F:
        memory[ds*16+0x8F59] &= 0xfe;
        pc = 0x15FF7;
        break;
    case 0x15F67:
        if (r8[al] == 0x4c) {
            pc = 0x15F6F;
            break;
        }
        if (r8[al] != 0x50) {
            pc = 0x15F77;
            break;
        }
    case 0x15F6F:
        memory[ds*16+0x8F59] |= 0x02;
        pc = 0x15FF7;
        break;
    case 0x15F77:
        if (r8[al] == 0xcc) {
            pc = 0x15F7F;
            break;
        }
        if (r8[al] != 0xd0) {
            pc = 0x15F86;
            break;
        }
    case 0x15F7F:
        memory[ds*16+0x8F59] &= 0xfd;
        pc = 0x15FF7;
        break;
    case 0x15F86:
        if (r8[al] != 0x4b) {
            pc = 0x15F91;
            break;
        }
    case 0x15F8A:
        memory[ds*16+0x8F59] |= 0x04;
        pc = 0x15FF7;
        break;
    case 0x15F91:
        if (r8[al] != 0xcb) {
            pc = 0x15F9C;
            break;
        }
    case 0x15F95:
        memory[ds*16+0x8F59] &= 0xfb;
        pc = 0x15FF7;
        break;
    case 0x15F9C:
        if (r8[al] != 0x4d) {
            pc = 0x15FA7;
            break;
        }
    case 0x15FA0:
        memory[ds*16+0x8F59] |= 0x08;
        pc = 0x15FF7;
        break;
    case 0x15FA7:
        if (r8[al] != 0xcd) {
            pc = 0x15FB2;
            break;
        }
    case 0x15FAB:
        memory[ds*16+0x8F59] &= 0xf7;
        pc = 0x15FF7;
        break;
    case 0x15FB2:
        if (r8[al] != 0x39) {
            pc = 0x15FC9;
            break;
        }
    case 0x15FB6:
        if (memory[ds*16+0x8F59] & 0x80) {
            pc = 0x15FF7;
            break;
        }
        memory[ds*16+0x8F5B] = 0xff;
        memory[ds*16+0x8F59] |= 0x80;
        pc = 0x15FF7;
        break;
    case 0x15FC9:
        if (r8[al] != 0xb9) {
            pc = 0x15FD4;
            break;
        }
    case 0x15FCD:
        memory[ds*16+0x8F59] &= 0x7f;
        pc = 0x15FF7;
        break;
    case 0x15FD4:
        if (r8[al] != 0x44) {
            pc = 0x15FF0;
            break;
        }
        r8[al] = in8(97);
        r8[al] |= 0x80;
        out8(97, r8[al]);
        r8[al] = r8[al] ^ 0x80;
        out8(97, r8[al]);
        r8[al] = 0x20;
        out8(32, r8[al]);
        r16[ax] = ds;
        es = r16[ax];
        flags.interrupt = true;
        _STOP_("goto loc_1054F");
    case 0x15FEE:
        r8[al] = 0x1c;
    case 0x15FF0:
        if (r8s[al] < 0) {
            pc = 0x15FF7;
            break;
        }
        memory[ds*16+0x8F58] = r8[al];
    case 0x15FF7:
        r8[al] = in8(97);
        r8[al] |= 0x80;
        out8(97, r8[al]);
        r8[al] = r8[al] ^ 0x80;
        out8(97, r8[al]);
        r8[al] = 0x20;
        out8(32, r8[al]);
        r16[bx] = pop();
        r16[ax] = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_16058() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x8F53] = 0x00;
        memory16set(ds*16+0x8F50, 0x0200);
    case 0x16063:
        memory16set(ds*16+0x8F50, memory16get(ds*16+0x8F50) >> 1);
        yield* sub_160EF();
        if (!(r16[bx] & r16[bx]))
            return;
        if (memory16get(ds*16+0x8F50) == 0x0000) {
            pc = 0x1607F;
            break;
        }
        if (r8[bl] < 0x20) {
            pc = 0x16063;
            break;
        }
        if (r8[bh] < 0x20) {
            pc = 0x16063;
            break;
        }
    case 0x1607F:
        r8[bh] >>= 1;
        r8[bl] >>= 1;
        memory16set(ds*16+0x8F4E, r16[bx]);
        r8[al] = r8[bh];
        r8[bh] <<= 1;
        r8[bh] += r8[al];
        r8[al] = r8[bl];
        r8[bl] <<= 1;
        r8[bl] += r8[al];
        memory16set(ds*16+0x8F4C, r16[bx]);
        r16[ax] = memory16get(ds*16+0x8F4D);
        xchg8(ah, al);
        memory16set(ds*16+0x8F4D, r16[ax]);
        memory[ds*16+0x8F53] = 0xff;
        return;
    } while (1);
}
function* sub_160A5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x8F53] == 0x00)
            return;
        yield* sub_160EF();
        r8[dl] = r8[dl] ^ r8[dl];
        r8[al] &= 0x30;
        if (r8[al] == 0x30) {
            pc = 0x160B9;
            break;
        }
        r8[dl] = 0x08;
    case 0x160B9:
        r16[ax] = memory16get(ds*16+0x8F4C);
        assert(0); /* FIXME */ rcl8(dl, 1);
        assert(0); /* FIXME */ rcl8(dl, 1);
        r16[ax] = memory16get(ds*16+0x8F4E);
        assert(0); /* FIXME */ rcl8(dl, 1);
        assert(0); /* FIXME */ rcl8(dl, 1);
        if (r8[dl] == memory[ds*16+0x8F5A])
            return;
        if (!(r8[dl] & 0x80)) {
            pc = 0x160E6;
            break;
        }
        if (memory[ds*16+0x8F5A] & 0x80) {
            pc = 0x160E6;
            break;
        }
        memory[ds*16+0x8F5B] = 0xff;
    case 0x160E6:
        memory[ds*16+0x8F5A] = r8[dl];
        memory[ds*16+0x8F59] = r8[dl];
        return;
    } while (1);
}
function* sub_160EF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupt = false;
        r16[dx] = 0x0201;
        bp = 0x0100;
        out8(r16[dx], r8[al]);
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x160F9:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x01)) {
            pc = 0x16100;
            break;
        }
        r8[bh] += 1;
    case 0x16100:
        if (!(r8[al] & 0x02)) {
            pc = 0x16106;
            break;
        }
        r8[bl] += 1;
    case 0x16106:
        if (!(r8[al] & 0x03)) {
            pc = 0x16114;
            break;
        }
        r16[ax] = memory16get(ds*16+0x8F50);
    case 0x1610D:
        r16[ax] -= 1;
        if (r16s[ax] >= 0) {
            pc = 0x1610D;
            break;
        }
        bp -= 1;
        if (bp != 0) {
            pc = 0x160F9;
            break;
        }
        r8[al] = in8(r16[dx]);
    case 0x16114:
        flags.interrupt = true;
        return;
    } while (1);
}
function* sub_1655B() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x922C] != 0x00) {
            pc = 0x16590;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9190);
        r16[ax] = r16[ax] + memory16get(ds*16+0x9F16);
        if (r16s[ax] >= signed16(0x0a80)) {
            pc = 0x16590;
            break;
        }
        memory[ds*16+0x8FB0] = 0xff;
        memory[ds*16+0x922C] = 0xff;
        memory16set(ds*16+0x9190, 0x09c0);
        memory16set(ds*16+0x91AA, 0x09c0);
        memory16set(ds*16+0x918E, 0x1860);
        memory16set(ds*16+0x9196, 0x0000);
    case 0x16590:
        if (memory16gets(ds*16+0x9190) < signed16(0x0a40)) {
            pc = 0x165DC;
            break;
        }
        if (memory16gets(ds*16+0x9190) > signed16(0x0d10)) {
            pc = 0x165DC;
            break;
        }
        if (memory16gets(ds*16+0x91AA) >= signed16(0x0d10)) {
            pc = 0x165AE;
            break;
        }
        memory16set(ds*16+0x91AA, 0x0d10);
    case 0x165AE:
        yield* sub_16807();
        r16[di] = 0x91d4;
        r16[si] = 0x65f6;
        r16[cx] = 0x0010;
    case 0x165BA:
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x165D4;
            break;
        }
        r16[bx] = 0x0000;
        r16[bx] = r16[bx] + memory16get(cs*16+r16[si]);
        memory16set(ds*16+r16[di], memory16get(ds*16+r16[di]) - 1);
        bp = memory16get(ds*16+r16[di]);
        bp &= 0x0003;
        bp <<= 1;
        r16[ax] = memory16get(cs*16+bp + r16[si] + 2);
        memory16set(ds*16+r16[bx], r16[ax]);
    case 0x165D4:
        r16[di] += 0x0002;
        r16[si] += 0x000a;
        if (--r16[cx]) {
            pc = 0x165BA;
            break;
        }
    case 0x165DC:
        memory[ds*16+0x9226] = 0x00;
        memory[ds*16+0x9227] = 0x00;
        memory[ds*16+0x9228] = 0x00;
        memory[ds*16+0x9229] = 0x00;
        memory[ds*16+0x922A] = 0x00;
        return;
    } while (1);
}
function* sub_16696() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x08b9);
        flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x166A1;
            break;
        }
        return;
    case 0x166A1:
        bp = 0x650d;
        yield* loc_166B6();
        return;
    } while (1);
}
function* sub_166A6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x08b9);
        flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x166B1;
            break;
        }
        return;
    case 0x166B1:
        bp = 0x6523;
        yield* loc_166B6();
        return;
    } while (1);
}
function* loc_166B6() {
    var cs = _seg000;
    push(r16[si]);
    yield* sub_11022();
    push(r16[di]);
    r16[di] = 0x9096;
    yield* sub_1077C();
    r16[di] = pop();
    r16[ax] = memory16get(ds*16+r16[di]);
    memory16set(ds*16+r16[si], r16[ax]);
    memory16set(ds*16+r16[si] + 2, 0x69d0);
    memory16set(ds*16+r16[si] + 4, 0x0853);
    r16[ax] = memory16get(ds*16+r16[di] + 18);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 22);
    memory16set(ds*16+r16[si] + 22, r16[ax]);
    r16[ax] = memory16get(cs*16+bp);
    memory16set(ds*16+r16[si] + 12, r16[ax]);
    r16[ax] = memory16get(cs*16+bp + 2);
    memory16set(ds*16+r16[si] + 14, r16[ax]);
    bp += 0x0004;
    memory16set(ds*16+r16[si] + 16, bp);
    yield* sub_14191();
    memory[ds*16+r16[si] + 28] = r8[al];
    memory[ds*16+r16[si] + 29] = 0x00;
    r16[ax] = memory16get(ds*16+r16[di] + 52);
    flags.carry = (memory16get(ds*16+0x9152) + r16[ax]) >= 0x10000;
    memory16set(ds*16+0x9152, memory16get(ds*16+0x9152) + r16[ax]);
    memory16set(ds*16+0x9154, memory16get(ds*16+0x9154) + 0x0000 + flags.carry);
    r16[si] = r16[di];
    yield* sub_107C0();
    r16[si] = pop();
}
function* sub_16807() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x9226;
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x1680C:
        if (memory[ds*16+r16[si]] != 0x00) {
            pc = 0x1681B;
            break;
        }
        memory[ds*16+r16[si]] = 0xff;
        push(r16[si]);
        push(r16[cx]);
        yield* sub_16823();
        r16[cx] = pop();
        r16[si] = pop();
    case 0x1681B:
        r16[si] += 1;
        r16[cx] += 1;
        if (r16s[cx] < signed16(0x0005)) {
            pc = 0x1680C;
            break;
        }
        return;
    } while (1);
}
function* sub_16823() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[cx];
        memory16set(ds*16+0xFCFA, r16[cx]);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + -28172 + 65536);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        memory16set(ds*16+r16[bx] + -28172 + 65536, r16[ax]);
        r16[ax] &= 0x000f;
        r16[bx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[di] = 0x6767;
        r16[di] += r16[ax];
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[bx] = memory16get(cs*16+r16[di] + 2);
        r16[bx] = r16[bx] - memory16get(ds*16+0x919A);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCE6, r16[bx]);
        bp = memory16get(cs*16+r16[di] + 4);
        bp <<= 1;
        if (memory16get(ds*16+bp + 28204) != 0x0000) {
            pc = 0x16876;
            break;
        }
        memory16set(ds*16+bp + 28204, 0x0014);
    case 0x16876:
        r16[dx] = memory16get(cs*16+r16[di] + 6);
        memory16set(ds*16+0xFCEE, r16[dx]);
        memory16set(ds*16+0xFCEA, 0x0000);
        r16[di] = memory16get(cs*16+r16[di] + 8);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + -8482 + 65536);
        r16[bx] = 0x670d;
        r16[cx] = memory16get(cs*16+r16[bx]);
        r16[bx] += 0x0002;
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        push(r16[si]);
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x010c);
        memory16set(ds*16+r16[si] + 2, 0x6aad);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x69c8);
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+r16[si] + 32, r16[ax]);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory16set(ds*16+r16[si] + 56, r16[di]);
        memory16set(ds*16+r16[si] + 58, r16[di]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEA);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        r16[ax] = memory[cs*16+0x6282];
        memory16set(ds*16+r16[si] + 66, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        memory16set(ds*16+r16[si] + 52, 0x0000);
    case 0x16900:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si], r16[ax]);
        memory16set(ds*16+r16[si] + 2, 0x6a0a);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 6, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(ds*16+r16[si] + 52, r16[ax]);
        r16[bx] += 0x0008;
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+r16[si] + 32, r16[ax]);
        memory16set(ds*16+r16[si] + 36, 0x0001);
        memory[ds*16+r16[si] + 39] = 0x00;
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 56, r16[di]);
        memory16set(ds*16+r16[si] + 58, r16[di]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        r16[ax] = memory16get(ds*16+0xFCEA);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        memory16set(ds*16+r16[si] + 66, 0x0004);
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        memory16set(ds*16+0xFCEA, memory16get(ds*16+0xFCEA) - 0x0007);
        yield* sub_13589();
        if (--r16[cx]) {
            pc = 0x16900;
            break;
        }
        yield* sub_11022();
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x00b8);
        memory16set(ds*16+r16[si] + 2, 0x0761);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x0761);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        memory16set(ds*16+r16[si] + 70, r16[di]);
        memory16set(ds*16+r16[di], 0x00bc);
        memory16set(ds*16+r16[di] + 2, 0x25a8);
        memory16set(ds*16+r16[di] + 4, 0x0761);
        memory16set(ds*16+r16[di] + 6, 0x0761);
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 44, 0x03e8);
        memory16set(ds*16+r16[di] + 68, r16[si]);
        return;
    } while (1);
}
function* sub_169C8() {
    push(r16[si]);
    r16[si] = r16[di];
    yield* sub_107C0();
    r16[si] = pop();
}
function* sub_169D0() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r8[al] = memory[cs*16+r16[bx] + 24854];
        _cbw();
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        if (r16[ax] >= 0x00c0) {
            pc = 0x16A06;
            break;
        }
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r8[al] = memory[cs*16+r16[bx] + 24918];
        _cbw();
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 18);
        if (r16[ax] >= 0x0140) {
            pc = 0x16A06;
            break;
        }
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        return;
    case 0x16A06:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_16A0A() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 34);
        memory[ds*16+r16[bx] + -28122 + 65536] = 0xff;
        r16[di] = memory16get(ds*16+r16[si] + 10);
        if (memory16get(ds*16+r16[di]) != 0x00bc) {
            pc = 0x16A33;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 32);
        r16[bx] <<= 1;
        if (memory16get(ds*16+r16[bx] + -28204 + 65536) != 0x0000) {
            pc = 0x16A2D;
            break;
        }
        memory16set(ds*16+r16[bx] + -28204 + 65536, 0x0014);
    case 0x16A2D:
        yield* sub_107C0();
        yield* indirectCall(_seg000, memory16get(ds*16+r16[si]+2));
    case 0x16A33:
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        r16[ax] = r16[ax] + memory16get(ds*16+0x9198);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 28);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 30);
        memory16set(ds*16+r16[si] + 30, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 26);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        if (memory16get(ds*16+r16[si] + 4) != 0x0761) {
            pc = 0x16A67;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 26) < 0 /*CHECK*/) {
            pc = 0x16A67;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0853);
    case 0x16A67:
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r16[bx] += 0x0010;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] &= 0x000e;
        r16[di] = 0x6a8d;
        if (memory16get(ds*16+r16[si]) != 0x0110) {
            pc = 0x16A84;
            break;
        }
        r16[di] = 0x6a9d;
    case 0x16A84:
        r16[ax] = memory16get(cs*16+r16[bx] + r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
    {yield* sub_13589(); return; };
        return;
    } while (1);
}
function* sub_16AAD() {
    r16[ax] = memory16get(ds*16+0x9198);
    memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
    r16[bx] = memory16get(ds*16+r16[si] + 34);
    memory[ds*16+r16[bx] + -28122 + 65536] = 0xff;
    yield* sub_14871();
    if (memory16get(ds*16+r16[si]) != 0x0004)
        return;
    yield* indirectCall(_seg000, memory16get(ds*16+r16[si]+2));
    return;
}
function* sub_16AC7() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x91AA);
        r16[ax] += 0x00d0;
        if (r16s[ax] >= memory16gets(ds*16+r16[si] + 22)) {
            pc = 0x16AD5;
            break;
        }
        pc = 0x16B76;
        break;
    case 0x16AD5:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x0004;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x0018;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0004;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0018;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 26);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[di] = 0x6b7a;
        if (memory16get(ds*16+r16[si]) == 0x00e0) {
            pc = 0x16B0C;
            break;
        }
        r16[di] = 0x6b9a;
    case 0x16B0C:
        r16[bx] += r16[di];
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(ds*16+r16[di] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(ds*16+r16[di] + 42, r16[ax]);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) & 0x0003);
        r8[al] = memory[cs*16+0x6262];
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry)
            return;
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x0010;
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[bx] += 0x000e;
        r16[cx] = 0x0002;
        bp = memory[cs*16+0x6264];
        bp <<= 1;
        bp = memory16get(cs*16+bp + 30294);
        if (memory16get(ds*16+r16[si]) == 0x00e4) {
            pc = 0x16B6E;
            break;
        }
        r16[cx] = 0x0006;
        r16[ax] -= 0x0010;
    case 0x16B6E:
        r16[dx] = memory[cs*16+0x6266];
    {yield* sub_11ED3(); return; };
    case 0x16B76:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_16BCA() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x91AA);
        r16[ax] += 0x00d0;
        if (r16s[ax] >= memory16gets(ds*16+r16[si] + 22)) {
            pc = 0x16BD8;
            break;
        }
        pc = 0x16C7E;
        break;
    case 0x16BD8:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x0008;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x0010;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0008;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0010;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 26);
        r16[bx] &= 0xfffe;
        r16[bx] <<= 1;
        r16[di] = 0x6cd2;
        if (memory16get(ds*16+r16[si]) == 0x00d8) {
            pc = 0x16C0E;
            break;
        }
        r16[di] = 0x6c82;
    case 0x16C0E:
        r16[bx] += r16[di];
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        if (memory16get(ds*16+r16[si] + 26) != 0x0000) {
            pc = 0x16C36;
            break;
        }
        r8[al] = memory[cs*16+0x6268];
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry)
            return;
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
    case 0x16C36:
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        if (memory16get(ds*16+r16[si] + 26) != 0x0028) {
            pc = 0x16C45;
            break;
        }
        memory16set(ds*16+r16[si] + 26, 0x0000);
        return;
    case 0x16C45:
        if (memory16get(ds*16+r16[si] + 26) != 0x0018)
            return;
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x001a;
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[bx] += 0x0002;
        bp = memory[cs*16+0x626A];
        bp <<= 1;
        bp = memory16get(cs*16+bp + 30294);
        r16[cx] = 0x0002;
        if (memory16get(ds*16+r16[si]) == 0x00dc) {
            pc = 0x16C76;
            break;
        }
        r16[cx] = 0x0006;
        r16[ax] -= 0x001a;
    case 0x16C76:
        r16[dx] = memory[cs*16+0x626C];
    {yield* sub_11ED3(); return; };
    case 0x16C7E:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_16D22() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x91AA);
        r16[ax] += 0x00d0;
        if (r16s[ax] >= memory16gets(ds*16+r16[si] + 22)) {
            pc = 0x16D30;
            break;
        }
        pc = 0x16DD0;
        break;
    case 0x16D30:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x000a;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x0012;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0004;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0018;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 26);
        r16[bx] &= 0xfffc;
        r16[bx] <<= 1;
        r16[di] = 0x6dfc;
        if (memory16get(ds*16+r16[si]) == 0x00e8) {
            pc = 0x16D66;
            break;
        }
        r16[di] = 0x6ddc;
    case 0x16D66:
        r16[bx] += r16[di];
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(ds*16+r16[di] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(ds*16+r16[di] + 42, r16[ax]);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) & 0x000f);
        r8[al] = memory[cs*16+0x626E];
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry)
            return;
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] += 0x0020;
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[bx] += 0x000e;
        bp = memory[cs*16+0x6270];
        bp <<= 1;
        bp = memory16get(cs*16+bp + 30294);
        r16[cx] = 0x0002;
        if (memory16get(ds*16+r16[si]) == 0x00ec) {
            pc = 0x16DC8;
            break;
        }
        r16[cx] = 0x0006;
        r16[ax] -= 0x0020;
    case 0x16DC8:
        r16[dx] = memory[cs*16+0x6272];
    {yield* sub_11ED3(); return; };
        return;
    case 0x16DD0:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_16E2C() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x91AA);
        r16[ax] += 0x00d0;
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        if (r16s[ax] >= memory16gets(ds*16+r16[si] + 22)) {
            pc = 0x16E3E;
            break;
        }
        pc = 0x16EEB;
        break;
    case 0x16E3E:
        yield* sub_141B1();
        r16[ax] = memory16get(ds*16+0x9198);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 26) != 0x0000) {
            pc = 0x16E50;
            break;
        }
        return;
    case 0x16E50:
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9F16);
        if (r16s[ax] > signed16(0x000a)) {
            pc = 0x16ED1;
            break;
        }
        if (r16s[ax] < signed16(0xffe2)) {
            pc = 0x16ED1;
            break;
        }
        yield* sub_14191();
        if (r8[al] >= 0x32) {
            pc = 0x16ED1;
            break;
        }
        memory16set(ds*16+r16[si] + 26, 0x0000);
        yield* sub_107DC();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = 0x64fd;
        if (memory16get(ds*16+r16[si]) == 0x00d4) {
            pc = 0x16E82;
            break;
        }
        r16[di] = 0x64d7;
    case 0x16E82:
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[di] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        memory16set(ds*16+0xFCFE, 0x0002);
    case 0x16E9D:
        bp = memory[cs*16+0x6274];
        bp <<= 1;
        bp = memory16get(cs*16+bp + 30294);
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] += 0x0007;
        r16[cx] = 0x0005;
        if (memory16get(ds*16+r16[si]) == 0x00d4) {
            pc = 0x16EBE;
            break;
        }
        r16[cx] = 0x0001;
    case 0x16EBE:
        r16[cx] = r16[cx] + memory16get(ds*16+0xFCFE);
        r16[dx] = memory[cs*16+0x6276];
        yield* sub_11ED3();
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - 1);
        if (memory16gets(ds*16+0xFCFE) >= 0) {
            pc = 0x16E9D;
            break;
        }
        return;
    case 0x16ED1:
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        memory16set(ds*16+r16[si] + 34, memory16get(ds*16+r16[si] + 34) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 34) == 0) {
            pc = 0x16EE4;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 34);
        if (r16[ax] != memory16get(ds*16+r16[si] + 28)) {
            pc = 0x16EE7;
            break;
        }
    case 0x16EE4:
        memory16set(ds*16+r16[si] + 26, -memory16get(ds*16+r16[si] + 26));
    case 0x16EE7:
        yield* sub_13589();
        return;
    case 0x16EEB:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_16F00() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[si];
        r16[ax] = 0x00e0;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x16F0E;
            break;
        }
        r16[ax] = 0x00e4;
    case 0x16F0E:
        r16[bx] = 0x6ac7;
        yield* sub_13529();
        memory16set(ds*16+r16[si] + 6, 0x3b76);
        r16[ax] = memory[cs*16+0x627A];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        r16[bx] = 0x6b9a;
        bp = 0x6bc2;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x16F44;
            break;
        }
        r16[bx] = 0x6b7a;
        bp = 0x6bba;
        memory16set(ds*16+r16[si] + 56, memory16get(ds*16+r16[si] + 56) + 0x0002);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) + 0x0010);
    case 0x16F44:
        memory16set(ds*16+r16[si] + 12, r16[bx]);
        memory16set(ds*16+r16[si] + 16, bp);
        memory16set(ds*16+r16[si] + 56, memory16get(ds*16+r16[si] + 56) - 0x0002);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) - 0x0010);
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(ds*16+r16[di] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(ds*16+r16[di] + 42, r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0064);
        memory16set(ds*16+r16[si] + 48, 0x0001);
        memory16set(ds*16+r16[si] + 50, 0x0001);
        return;
    } while (1);
}
function* sub_16F7F() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[si];
        r16[ax] = 0x00e8;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x16F8D;
            break;
        }
        r16[ax] = 0x00ec;
    case 0x16F8D:
        r16[bx] = 0x6d22;
        yield* sub_13529();
        memory16set(ds*16+r16[si] + 6, 0x3b76);
        r16[ax] = memory[cs*16+0x627C];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        r16[bx] = 0x6ddc;
        bp = 0x6e24;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x16FBB;
            break;
        }
        r16[bx] = 0x6dfc;
        bp = 0x6e1c;
    case 0x16FBB:
        r16[di] = memory16get(ds*16+r16[si] + 56);
        memory16set(ds*16+r16[si] + 12, r16[bx]);
        memory16set(ds*16+r16[si] + 16, bp);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0064);
        memory16set(ds*16+r16[si] + 48, 0x0001);
        memory16set(ds*16+r16[si] + 50, 0x0001);
        return;
    } while (1);
}
function* sub_16FE0() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[si];
        r16[ax] = 0x00d8;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x16FEE;
            break;
        }
        r16[ax] = 0x00dc;
    case 0x16FEE:
        r16[bx] = 0x6bca;
        yield* sub_13529();
        memory16set(ds*16+r16[si] + 6, 0x3b76);
        r16[ax] = memory[cs*16+0x627E];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        r16[bx] = 0x704b;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x17016;
            break;
        }
        r16[bx] = 0x7053;
    case 0x17016:
        r16[di] = memory16get(ds*16+r16[si] + 56);
        memory16set(ds*16+r16[si] + 12, r16[bx]);
        memory16set(ds*16+r16[si] + 16, 0x6dd4);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(ds*16+r16[di] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(ds*16+r16[di] + 42, r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0064);
        memory16set(ds*16+r16[si] + 48, 0x0001);
        memory16set(ds*16+r16[si] + 50, 0x0001);
        return;
    } while (1);
}
function* sub_1705B() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x00d4);
        r16[bx] = 0x64e7;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x1707A;
            break;
        }
        memory16set(ds*16+r16[si], 0x00d0);
        r16[bx] = 0x64c1;
    case 0x1707A:
        memory16set(ds*16+r16[si] + 2, 0x6e2c);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        memory16set(ds*16+r16[si] + 6, 0x3aa7);
        r16[ax] = memory[cs*16+0x6280];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory[ds*16+r16[si] + 39] = 0xff;
        memory16set(ds*16+r16[si] + 52, 0x00fa);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        r16[ax] = memory16get(ds*16+r16[di] + 8);
        r16[ax] -= 0x0008;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x170C2;
            break;
        }
        r16[ax] += 0x0010;
    case 0x170C2:
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 10);
        r16[ax] -= 0x0008;
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0xffff);
        r16[bx] = memory16get(ds*16+r16[di] + 6);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        memory16set(ds*16+r16[si] + 28, r16[bx]);
        memory16set(ds*16+r16[si] + 34, r16[bx]);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        yield* sub_13589();
        return;
    } while (1);
}
function* sub_170F1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: yield* loc_13360(); return;
        case 2: pc = 0x1710E; break;
        case 4: pc = 0x17114; break;
        case 6: pc = 0x1711A; break;
        case 8: pc = 0x17120; break;
        case 10: pc = 0x17126; break;
        case 12: pc = 0x1712C; break;
        case 14: pc = 0x17132; break;
        case 16: pc = 0x17138; break;
        case 18: pc = 0x1713E; break;
        case 20: pc = 0x17144; break;
        default: assert(0);
        }
        break;
    case 0x1710E:
        r16[bx] = 0x6285;
    {yield* sub_13389(); return; };
    case 0x17114:
        r16[bx] = 0x6297;
    {yield* sub_13389(); return; };
    case 0x1711A:
        r16[bx] = 0x62a9;
    {yield* sub_13389(); return; };
    case 0x17120:
        r16[bx] = 0x62bb;
    {yield* sub_13389(); return; };
    case 0x17126:
        r16[bx] = 0x62cd;
    {yield* sub_13389(); return; };
    case 0x1712C:
        r16[bx] = 0x62df;
    {yield* sub_13389(); return; };
    case 0x17132:
        r16[bx] = 0x62f1;
    {yield* sub_13389(); return; };
    case 0x17138:
        r16[bx] = 0x6313;
    {yield* sub_13389(); return; };
    case 0x1713E:
        r16[bx] = 0x6325;
    {yield* sub_13389(); return; };
    case 0x17144:
        r16[bx] = 0x6337;
    {yield* sub_13389(); return; };
        return;
    } while (1);
}
function* sub_1714A() {
    r16[ax] = r16[ax] ^ r16[ax];
    flags.zero = true;
}
function* sub_1714D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x922B] == 0x00)
            return;
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EB4);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EB6);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EB8);
        memory16set(ds*16+0xFCEA, r16[ax]);
        r16[ax] = memory16get(ds*16+0x8EBA);
        memory16set(ds*16+0xFCEE, r16[ax]);
        memory16set(ds*16+0xFCF2, 0x0098);
        memory16set(ds*16+0xFCFA, 0x00a7);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCF6, memory16get(ds*16+0xFCF6) - r16[ax]);
        memory16set(ds*16+0xFCF6, memory16get(ds*16+0xFCF6) + 0x0044);
        r16[ax] = memory16get(ds*16+0xFCF6);
        memory16set(ds*16+0xFCFE, r16[ax]);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + 0x000e);
        yield* sub_10F2F();
        if (flags.zero) {
            pc = 0x171A7;
            break;
        }
        r16[ax] = pop();
        memory16set(ds*16+r16[di] + 4, 0x7569);
        flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x171A9;
            break;
        }
        return;
    case 0x171A7:
        r16[ax] = pop();
        return;
    case 0x171A9:
        memory[ds*16+0x922B] = 0x00;
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[cx] = 0x0008;
        yield* sub_115E4();
        r16[cx] = 0x0013;
        r16[ax] = 0x0000;
        r16[bx] = 0x0000;
        r16[dx] = 0x0140;
        r16[di] = 0x00c0;
        bp = 0x124c;
        yield* sub_11588();
        r16[si] = memory16get(ds*16+0x9054);
        yield* sub_13760();
        r16[si] = pop();
        memory[ds*16+0x8F61] = 0xff;
        return;
    } while (1);
}
function* sub_171DD() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x922B] != 0x00) {
            pc = 0x171E7;
            break;
        }
        pc = 0x172C0;
        break;
    case 0x171E7:
        r16[di] = memory16get(ds*16+r16[si] + 16);
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 20);
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 24);
        memory16set(ds*16+r16[si] + 24, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 28);
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 30);
        memory16set(ds*16+r16[si] + 30, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 60);
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 62);
        memory16set(ds*16+r16[si] + 62, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 64);
        memory16set(ds*16+r16[si] + 64, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 66);
        memory16set(ds*16+r16[si] + 66, r16[ax]);
        if (memory16get(ds*16+r16[di]) != 0x0050) {
            pc = 0x17244;
            break;
        }
        memory16set(ds*16+r16[si] + 18, 0x00a0);
        memory16set(ds*16+r16[si] + 20, 0x0000);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + 0x0060);
        memory16set(ds*16+r16[si] + 24, 0x0000);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - r16[ax]);
    case 0x17244:
        memory16set(ds*16+r16[si] + 26, 0x0064);
        yield* loc_1480E();
        if (memory16get(ds*16+r16[si] + 66) == 0x0000) {
            pc = 0x172B5;
            break;
        }
        if (memory16get(ds*16+r16[si]) != 0x0100) {
            pc = 0x172B2;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+0x9F16);
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si] + 22);
        yield* sub_11B90();
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        r16[ax] = memory16get(cs*16+r16[bx] + 30444);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        if (memory16gets(ds*16+r16[si] + 66) < signed16(0x000b)) {
            pc = 0x172B2;
            break;
        }
        flags.carry = (memory[ds*16+r16[si] + 72] + 0x0f) >= 0x100;
        memory[ds*16+r16[si] + 72] += 0x0f;
        if (!flags.carry) {
            pc = 0x172B2;
            break;
        }
        yield* sub_14191();
        r16[ax] &= 0x003f;
        memory[ds*16+r16[si] + 72] = r8[al];
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[cx] = memory16get(ds*16+r16[si] + 28);
        r16[dx] = 0x0004;
        yield* sub_11ED3();
        bp = 0x6549;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
    case 0x172B2:
    {yield* sub_13589(); return; };
    case 0x172B5:
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        return;
    case 0x172C0:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_172C4() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+0x9190) <= signed16(0x01c0)) {
            pc = 0x172CF;
            break;
        }
        pc = 0x17515;
        break;
    case 0x172CF:
        if (memory[ds*16+0x922B] == 0x00) {
            pc = 0x172D9;
            break;
        }
        pc = 0x1736A;
        break;
    case 0x172D9:
        memory[ds*16+0x922B] = 0xff;
        r16[cx] = 0x0007;
        bp = r16[si];
    case 0x172E3:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = r16[si];
        r16[si] = pop();
        if (r16[cx] != 0x0007) {
            pc = 0x172FD;
            break;
        }
        push(r16[si]);
        r16[si] = r16[di];
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        pc = 0x17308;
        break;
    case 0x172FD:
        push(r16[si]);
        r16[si] = r16[di];
        r16[di] = bp;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
    case 0x17308:
        memory16set(ds*16+r16[di], 0x00fc);
        if (r16[cx] & r16[cx]) {
            pc = 0x17314;
            break;
        }
        memory16set(ds*16+r16[di], 0x0100);
    case 0x17314:
        memory16set(ds*16+r16[di] + 2, 0x71dd);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x3a99);
        memory16set(ds*16+r16[di] + 12, 0x2e0f);
        memory16set(ds*16+r16[di] + 14, 0x0000);
        memory16set(ds*16+r16[di] + 72, 0x0000);
        memory16set(ds*16+r16[di] + 16, bp);
        bp = r16[di];
        memory[ds*16+r16[di] + 39] = 0x00;
        memory[ds*16+r16[di] + 74] = 0xff;
        memory16set(ds*16+r16[di] + 22, 0xff9c);
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 44, 0x03e8);
        r16[cx] -= 1;
        if (r16s[cx] >= 0) {
            pc = 0x172E3;
            break;
        }
        memory16set(ds*16+r16[si] + 28, 0x0000);
        memory16set(ds*16+r16[si] + 30, 0x0000);
        memory16set(ds*16+r16[si] + 60, 0x0000);
        memory16set(ds*16+r16[si] + 62, 0x0000);
        memory16set(ds*16+r16[si] + 64, 0x0000);
    case 0x1736A:
        if (memory16gets(ds*16+0x91AA) > signed16(0x01c0)) {
            pc = 0x17378;
            break;
        }
        memory16set(ds*16+0x91AA, 0x01c0);
    case 0x17378:
        memory16set(ds*16+r16[si] + 40, 0x0080);
        memory16set(ds*16+r16[si] + 44, 0x00c8);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0004;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0050;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        if (memory16get(ds*16+r16[si] + 26) != 0x0000) {
            pc = 0x173B6;
            break;
        }
        r16[ax] = 0x0030;
        if (memory16gets(ds*16+0x9190) <= r16s[ax]) {
            pc = 0x173A7;
            break;
        }
        pc = 0x174B3;
        break;
    case 0x173A7:
        memory16set(ds*16+r16[si] + 26, 0x0001);
        memory16set(ds*16+r16[si] + 32, 0x0000);
        memory16set(ds*16+r16[si] + 34, 0x00aa);
    case 0x173B6:
        if (memory16gets(ds*16+r16[si] + 26) < 0 /*CHECK*/) {
            pc = 0x173D3;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 66) >= signed16(0x000b)) {
            pc = 0x173DC;
            break;
        }
        if (memory16get(ds*16+r16[si] + 66) != 0x0000) {
            pc = 0x173CE;
            break;
        }
        memory16set(ds*16+0x8E8A, 0x0001);
    case 0x173CE:
        memory16set(ds*16+r16[si] + 66, memory16get(ds*16+r16[si] + 66) + 1);
        pc = 0x173DC;
        break;
    case 0x173D3:
        if (memory16get(ds*16+r16[si] + 66) == 0x0000) {
            pc = 0x173DC;
            break;
        }
        memory16set(ds*16+r16[si] + 66, memory16get(ds*16+r16[si] + 66) - 1);
    case 0x173DC:
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        if (memory16get(ds*16+r16[si] + 26) == 0) {
            pc = 0x173DC;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 26) < signed16(0x0064)) {
            pc = 0x173EC;
            break;
        }
        memory16set(ds*16+r16[si] + 26, 0xffd8);
    case 0x173EC:
        r16[ax] = memory16get(ds*16+0x919C);
        r16[ax] &= 0x007f;
        if (!(r16[ax] & 0x0040)) {
            pc = 0x173FC;
            break;
        }
        r16[ax] -= 0x007f;
        r16[ax] = -r16[ax];
    case 0x173FC:
        _cbw();
        r16[ax] += 0x0020;
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        r16[ax] = memory16get(ds*16+0x919C);
        r16[ax] += 0x0050;
        r16[ax] &= 0x00ff;
        if (!(r16[ax] & 0x0080)) {
            pc = 0x17413;
            break;
        }
        r8[al] = (~r8[al]);
    case 0x17413:
        r16[ax] -= 0x0040;
        _cwd();
        r8[dh] = r8[dl];
        r8[dl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[al] ^ r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl16(dx, 1);
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        memory16set(ds*16+r16[si] + 62, r16[dx]);
        r16[ax] = memory16get(ds*16+0x919C);
        r16[ax] += 0x00a0;
        r16[ax] &= 0x01ff;
        if (!(r16[ax] & 0x0100)) {
            pc = 0x1743E;
            break;
        }
        r16[ax] = r16[ax] ^ 0x01ff;
    case 0x1743E:
        r16[ax] -= 0x0080;
        r8[cl] = 0x05;
        r16[ax] <<= r8[cl];
        memory16set(ds*16+r16[si] + 64, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 32);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        if (r16s[ax] >= signed16(0x0010)) {
            pc = 0x1745B;
            break;
        }
        r16[ax] = 0x0010;
        memory16set(ds*16+r16[si] + 34, 0x0000);
    case 0x1745B:
        if (r16s[ax] <= signed16(0x01e0)) {
            pc = 0x17468;
            break;
        }
        r16[ax] = 0x01e0;
        memory16set(ds*16+r16[si] + 34, 0x0000);
    case 0x17468:
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 34, memory16get(ds*16+r16[si] + 34) - 1);
        if (memory16gets(ds*16+r16[si] + 34) >= 0) {
            pc = 0x174A9;
            break;
        }
        if (memory16get(ds*16+r16[si] + 32) != 0xffff) {
            pc = 0x17482;
            break;
        }
        memory16set(ds*16+r16[si] + 32, 0x0000);
        memory16set(ds*16+r16[si] + 34, 0x00aa);
        pc = 0x174A9;
        break;
    case 0x17482:
        if (memory16get(ds*16+r16[si] + 32) != 0x0001) {
            pc = 0x17494;
            break;
        }
        memory16set(ds*16+r16[si] + 32, 0x0000);
        memory16set(ds*16+r16[si] + 34, 0x003c);
        pc = 0x174A9;
        break;
    case 0x17494:
        memory16set(ds*16+r16[si] + 34, 0x0032);
        memory16set(ds*16+r16[si] + 32, 0x0001);
        if (memory16get(ds*16+r16[si] + 22) == 0x0010) {
            pc = 0x174A9;
            break;
        }
        memory16set(ds*16+r16[si] + 32, 0xffff);
    case 0x174A9:
        r16[ax] = 0x001e;
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 36);
        memory[ds*16+0x91FE] += r8[al];
    case 0x174B3:
        r16[bx] = memory16get(ds*16+0x919C);
        r16[bx] &= 0x000c;
        r16[bx] >>= 1;
        r16[bx] = memory16get(cs*16+r16[bx] + 30436);
        r16[di] = 0x769e;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[di] += 0x0004;
        r16[bx] += 0x0004;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[bx] += 0x0004;
        r16[di] += 0x0008;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[di] += 0x0004;
        r16[bx] += 0x0004;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        if (memory16get(ds*16+r16[si] + 26) == 0x0000) {
            pc = 0x17515;
            break;
        }
        return;
    case 0x17515:
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        return;
    } while (1);
}
function* sub_17520() {
    var cs = _seg000;
    if (memory16gets(ds*16+0x9190) >= signed16(0x0280))
        return;
    r16[ax] = 0x0006;
    r16[bx] = 0x0007;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[cx] = 0x0038;
    push(r16[si]);
    r16[si] = 0x7660;
    yield* sub_10941();
    r16[si] = pop();
    r16[bx] = memory16get(ds*16+0x91FE);
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] &= 0x0006;
    r16[cx] = 0x0098;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[dx] += 0x0042;
    push(r16[si]);
    r16[si] = memory16get(cs*16+r16[bx] + 30460);
    yield* sub_10875();
    r16[si] = pop();
    return;
}
function* sub_17569() {
    memory16set(ds*16+r16[si] + 4, 0x7520);
    if (memory16gets(ds*16+0x9190) >= signed16(0x0280))
        return;
    r16[ax] = 0x0006;
    r16[bx] = 0x0007;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[cx] = 0x0038;
    push(r16[si]);
    r16[si] = 0x7660;
    yield* sub_10963();
    r16[si] = pop();
    return;
}
function* sub_1758F() {
    var cs = _seg000;
    memory16set(ds*16+0x8EAC, 0x0bb8);
    memory16set(ds*16+0x8EAE, 0x0258);
    memory16set(ds*16+0x91A8, 0x0000);
    memory16set(ds*16+0x91AA, 0x11ff);
    memory[ds*16+0x922C] = 0x00;
    memory16set(ds*16+0x91FE, 0x0000);
    yield* sub_11022();
    r16[di] = 0x904a;
    yield* sub_1077C();
    memory16set(ds*16+r16[si], 0x0050);
    memory16set(ds*16+r16[si] + 2, 0x72c4);
    memory16set(ds*16+r16[si] + 4, 0x7520);
    memory16set(ds*16+r16[si] + 6, 0x714d);
    memory16set(ds*16+r16[si] + 72, 0x0000);
    memory[ds*16+r16[si] + 74] = 0xff;
    memory[ds*16+r16[si] + 75] = 0xff;
    memory16set(ds*16+r16[si] + 22, 0x0010);
    r16[ax] = memory[cs*16+0x6278];
    memory16set(ds*16+r16[si] + 36, r16[ax]);
    memory16set(ds*16+r16[si] + 26, 0x0000);
    memory16set(ds*16+r16[si] + 66, 0x0000);
    memory[ds*16+0x922B] = 0x00;
    memory[ds*16+0x9226] = 0x00;
    memory[ds*16+0x9227] = 0x00;
    memory[ds*16+0x9228] = 0x00;
    memory[ds*16+0x9229] = 0x00;
    memory[ds*16+0x922A] = 0x00;
    r16[di] = 0x91d4;
    r16[cx] = 0x0010;
    r16[ax] = r16[ax] ^ r16[ax];
    rep_stosw_data_forward();
    memory16set(ds*16+0x91F4, 0xd272);
    memory16set(ds*16+0x91F6, 0x6a4a);
    memory16set(ds*16+0x91F8, 0xba5d);
    memory16set(ds*16+0x91FA, 0x2512);
    memory16set(ds*16+0x91FC, 0xe51a);
    r16[ax] = 0x0001;
    r16[dx] = r16[dx] ^ r16[dx];
    _mul(memory16get(ds*16+0x991A));
    memory16set(ds*16+0x8E76, r16[ax]);
    r16[ax] = 0x0002;
    r16[dx] = r16[dx] ^ r16[dx];
    _mul(memory16get(ds*16+0x991A));
    memory16set(ds*16+0x8E78, r16[ax]);
    memory16set(ds*16+0x8E72, 0x3463);
}
function* sub_17DDE() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x91AA);
        r16[ax] += 0x00d0;
        if (r16s[ax] >= memory16gets(ds*16+r16[si] + 22)) {
            pc = 0x17DEC;
            break;
        }
        pc = 0x17E83;
        break;
    case 0x17DEC:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] -= 0x0008;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x0014;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0004;
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x0008;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        if (r16[ax] & r16[ax]) {
            pc = 0x17E25;
            break;
        }
        yield* sub_14191();
        if (r8[al] >= memory[cs*16+0x7714])
            return;
        memory16set(ds*16+r16[si] + 26, 0x0001);
        return;
    case 0x17E25:
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        r16[bx] += 0x90c1;
        if (memory16get(ds*16+r16[si]) == 0x00e8) {
            pc = 0x17E36;
            break;
        }
        r16[bx] += 0x001e;
    case 0x17E36:
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di], r16[ax]);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        if (memory16get(ds*16+r16[si] + 26) == 0x0007) {
            pc = 0x17E53;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x000f)
            return;
        memory16set(ds*16+r16[si] + 26, 0x0000);
        return;
    case 0x17E53:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0008;
        r16[bx] += 0x0008;
        r16[di] = memory[cs*16+0x7716];
        r16[di] <<= 1;
        bp = memory16get(cs*16+r16[di] + -27991 + 65536);
        r16[cx] = 0x0002;
        if (memory16get(ds*16+r16[si]) == 0x00ec) {
            pc = 0x17E7B;
            break;
        }
        r16[cx] = 0x0006;
    case 0x17E7B:
        r16[dx] = memory[cs*16+0x7718];
    {yield* sub_11ED3(); return; };
    case 0x17E83:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_17F32() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x9230] != 0x00) {
            pc = 0x17F4E;
            break;
        }
        if (memory16gets(ds*16+0x9190) < signed16(0x09d0)) {
            pc = 0x17F6E;
            break;
        }
        if (memory16gets(ds*16+0x9190) > signed16(0x0b50)) {
            pc = 0x17F6E;
            break;
        }
        yield* sub_1818C();
        pc = 0x17F6E;
        break;
    case 0x17F4E:
        if (memory16gets(ds*16+0x9190) <= signed16(0x09f0)) {
            pc = 0x17F6E;
            break;
        }
        memory16set(ds*16+0x9190, 0x09f0);
        memory16set(ds*16+0x91AA, 0x09f0);
        memory16set(ds*16+0x918E, 0x18d8);
        memory16set(ds*16+0x9196, 0x0000);
    case 0x17F6E:
        memory[ds*16+0x922D] = 0x00;
        memory[ds*16+0x922E] = 0x00;
        return;
    } while (1);
}
function* sub_17F79() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[si];
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: yield* loc_135CE(); return;
            pc = 0x17F82;
            break;
            pc = 0x17FDB;
            break;
            pc = 0x18018;
            break;
            pc = 0x180A3;
            break;
            pc = 0x180BB;
            break;
        case 12: assert(0);
            pc = 0x180D1;
            break;
            pc = 0x180D7;
            break;
            pc = 0x180DD;
            break;
            pc = 0x180E3;
            break;
            pc = 0x180E9;
            break;
            pc = 0x180EF;
            break;
            default:
            assert(0);
        }
    case 0x17F82:
        r16[ax] = 0x00e8;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x17F8E;
            break;
        }
        r16[ax] = 0x00ec;
    case 0x17F8E:
        r16[bx] = 0x7dde;
        yield* sub_13529();
        memory16set(ds*16+r16[si] + 6, 0x3b76);
        r16[ax] = memory[cs*16+0x771C];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        r16[bx] = memory16get(ds*16+r16[si] + 56);
        bp = 0x90df;
        r16[dx] = 0x90bf;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x17FBF;
            break;
        }
        bp = 0x90c1;
        r16[dx] = 0x90bd;
    case 0x17FBF:
        memory16set(ds*16+r16[si] + 12, bp);
        memory16set(ds*16+r16[si] + 16, r16[dx]);
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[bx], r16[ax]);
        memory16set(ds*16+r16[si] + 52, 0x0064);
        memory16set(ds*16+r16[si] + 48, 0x0000);
        memory16set(ds*16+r16[si] + 50, 0x0000);
        return;
    case 0x17FDB:
        r16[ax] = 0x00f0;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x17FE7;
            break;
        }
        r16[ax] = 0x00f4;
    case 0x17FE7:
        r16[bx] = 0x7ce6;
        yield* loc_13536();
        r16[bx] = memory16get(ds*16+r16[si] + 56);
        bp = 0x906d;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x17FFC;
            break;
        }
        bp = 0x9095;
    case 0x17FFC:
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[bx], r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[bx] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 4);
        memory16set(ds*16+r16[bx] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 6);
        memory16set(ds*16+r16[bx] + 42, r16[ax]);
        return;
    case 0x18018:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x0100);
        r16[bx] = 0x7a56;
        if (memory16get(ds*16+r16[di] + 12) != 0x0000) {
            pc = 0x18037;
            break;
        }
        memory16set(ds*16+r16[si], 0x0104);
        r16[bx] = 0x7a2c;
    case 0x18037:
        memory16set(ds*16+r16[si] + 2, 0x7e87);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory16set(ds*16+r16[si] + 6, 0x3aa7);
        r16[ax] = memory[cs*16+0x771E];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory[ds*16+r16[si] + 39] = 0x00;
        memory16set(ds*16+r16[si] + 52, 0x00c8);
        r16[ax] = memory16get(ds*16+r16[di] + 8);
        r16[ax] -= 0x0008;
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 10);
        r16[ax] -= 0x0008;
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0xffff);
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+r16[si] + 28, r16[ax]);
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        yield* sub_13589();
        return;
    case 0x180A3:
        r16[ax] = 0x00fc;
        r16[bx] = 0x7bef;
        assert(0);
        memory16set(ds*16+r16[si] + 34, 0x0001);
        r16[di] = memory16get(ds*16+r16[si] + 56);
        r16[ax] = memory16get(cs*16+0x8FD7);
        memory16set(ds*16+r16[di], r16[ax]);
        return;
    case 0x180BB:
        r16[ax] = 0x00f8;
        r16[bx] = 0x7ac4;
        assert(0);
        memory16set(ds*16+r16[si] + 34, 0x0001);
        return;
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: assert(0);
            pc = 0x180D1;
            break;
            pc = 0x180D7;
            break;
            pc = 0x180DD;
            break;
            pc = 0x180E3;
            break;
            pc = 0x180E9;
            break;
            pc = 0x180EF;
            break;
            default:
            assert(0);
        }
    case 0x180D1:
        r16[bx] = 0x7736;
    {yield* sub_13389(); return; };
    case 0x180D7:
        r16[bx] = 0x7748;
    {yield* sub_13389(); return; };
    case 0x180DD:
        r16[bx] = 0x775a;
    {yield* sub_13389(); return; };
    case 0x180E3:
        r16[bx] = 0x776c;
    {yield* sub_13389(); return; };
    case 0x180E9:
        r16[bx] = 0x777e;
    {yield* sub_13389(); return; };
    case 0x180EF:
        r16[bx] = 0x7790;
    {yield* sub_13389(); return; };
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_1818C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x9230] != 0x00)
            return;
        if (memory[ds*16+0x922D] != 0x00) {
            pc = 0x181A8;
            break;
        }
        memory16set(ds*16+0xFCFA, 0x0000);
        yield* loc_181E7();
        memory[ds*16+0x922D] = 0xff;
    case 0x181A8:
        if (memory[ds*16+0x922E] != 0x00)
            return;
        memory16set(ds*16+0xFCFA, 0x0001);
        yield* loc_181E7();
        memory[ds*16+0x922E] = 0xff;
        return;
    } while (1);
}
function* sub_181BE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0xFCFA) != 0x0000) {
            pc = 0x181D6;
            break;
        }
        r16[ax] = memory16get(ds*16+0x91F4);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        memory16set(ds*16+0x91F4, r16[ax]);
        return;
    case 0x181D6:
        r16[ax] = memory16get(ds*16+0x91F6);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        memory16set(ds*16+0x91F6, r16[ax]);
        return;
    } while (1);
}
function* loc_181E7() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9200) == 0x0001) {
            pc = 0x181F9;
            break;
        }
        if (memory[ds*16+0x922F] == 0x00) {
            pc = 0x18201;
            break;
        }
        memory[ds*16+0x922F] -= 1;
    case 0x181F9:
        yield* sub_181BE();
        r16[ax] &= 0x0006;
        pc = 0x1820A;
        break;
    case 0x18201:
        yield* sub_181BE();
        r16[ax] &= 0x0006;
        r16[ax] += 0x0008;
    case 0x1820A:
        r16[ax] = r16[ax] + memory16get(ds*16+0xFCFA);
        r16[dx] = 0x000a;
        r16[ax] = r16[dx] * r8[al];
        r16[di] = 0x9179;
        r16[di] += r16[ax];
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[di] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[di] += 0x0002;
        r16[ax] = memory16get(ds*16+0x919A);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        r16[bx] = memory16get(cs*16+r16[di]);
        r16[di] += 0x0002;
        r16[bx] <<= 1;
        if (memory16get(ds*16+r16[bx] + -28206+65536) != 0x0000) {
            pc = 0x1824D;
            break;
        }
        memory16set(ds*16+r16[bx] + -28206+65535, 0x0018);
    case 0x1824D:
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+0xFCEE, r16[ax]);
        r16[di] += 0x0002;
        memory16set(ds*16+0xFCEA, 0x0000);
        r16[di] = memory16get(cs*16+r16[di]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + -8524+65536);
        r16[bx] = 0x9117;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+0xFCFE, r16[ax]);
        r16[bx] += 0x0002;
    case 0x18271:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds*16+r16[si] + 2, 0x866d);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 6, r16[ax]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 52, r16[ax]);
        r16[bx] += 0x0002;
        r16[ax] = memory16get(ds*16+0xFCEE);
        memory16set(ds*16+r16[si] + 32, r16[ax]);
        r16[ax] = memory[cs*16+0x7720];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory[ds*16+r16[si] + 39] = 0x00;
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 56, r16[di]);
        memory16set(ds*16+r16[si] + 58, r16[di]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        r16[ax] = memory16get(ds*16+0xFCEA);
        memory16set(ds*16+r16[si] + 26, r16[ax]);
        r16[ax] = memory[cs*16+0x7722];
        memory16set(ds*16+r16[si] + 66, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        memory16set(ds*16+0xFCEA, memory16get(ds*16+0xFCEA) - 0x000a);
        yield* sub_13589();
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - 1);
        if (memory16gets(ds*16+0xFCFE) < 0) {
            pc = 0x182FF;
            break;
        }
        pc = 0x18271;
        break;
    case 0x182FF:
        r8[al] = 0x01;
        r16[cx] = memory16get(ds*16+0xFCFA);
        r8[al] <<= r8[cl];
        memory[ds*16+0x9202] |= r8[al];
        return;
    } while (1);
}
function* sub_188A9() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+0x918C) >= 0 /*CHECK*/) {
            pc = 0x188BE;
            break;
        }
        if (memory16gets(ds*16+0x91AA) > signed16(0x0b40)) {
            pc = 0x188BE;
            break;
        }
        memory16set(ds*16+0x91AA, 0x0b40);
    case 0x188BE:
        if (memory16get(ds*16+r16[si] + 34) != 0x0002) {
            pc = 0x188CD;
            break;
        }
        if (memory16get(ds*16+0x9200) != 0x0001) {
            pc = 0x188EC;
            break;
        }
        pc = 0x188F8;
        break;
    case 0x188CD:
        if (memory16get(ds*16+r16[si] + 34) != 0x0001) {
            pc = 0x188DD;
            break;
        }
        if (memory16gets(ds*16+0x9F12) >= signed16(0x00a0)) {
            pc = 0x188EC;
            break;
        }
        pc = 0x188E5;
        break;
    case 0x188DD:
        if (memory16gets(ds*16+0x9F12) < signed16(0x00a0)) {
            pc = 0x188EC;
            break;
        }
    case 0x188E5:
        if (memory16get(ds*16+0x9202) != 0x0003) {
            pc = 0x188F8;
            break;
        }
    case 0x188EC:
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        pc = 0x18931;
        break;
    case 0x188F8:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] += 0x000f;
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] += 0x000f;
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        if (memory16get(ds*16+r16[si] + 26) != 0x0004) {
            pc = 0x18931;
            break;
        }
        if (memory16get(ds*16+0x9202) != 0x0003) {
            pc = 0x18940;
            break;
        }
    case 0x18931:
        if (memory16get(ds*16+0x919C) & 0x0001) {
            pc = 0x18940;
            break;
        }
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) + 1);
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) & 0x0007);
    case 0x18940:
        r16[bx] = memory16get(ds*16+r16[si] + 26);
        if (r16s[bx] <= signed16(0x0004)) {
            pc = 0x1894D;
            break;
        }
        r16[bx] -= 0x0008;
        r16[bx] = -r16[bx];
    case 0x1894D:
        r16[bx] <<= 1;
        r16[di] = memory16get(ds*16+r16[si] + 12);
        r16[ax] = memory16get(cs*16+r16[bx] + -27939 + 65536);
        memory16set(ds*16+r16[di], r16[ax]);
        if (memory16get(ds*16+r16[si] + 34) != 0x0002)
            return;
        bp = 0x91d4;
        r16[di] = 0x9219;
        r16[cx] = 0x0008;
    case 0x18968:
        if (memory16get(ds*16+bp + 0) == 0x0000) {
            pc = 0x189A5;
            break;
        }
        r16[bx] = 0x0000;
        r16[bx] = r16[bx] + memory16get(cs*16+r16[di]);
        memory16set(ds*16+bp + 0, memory16get(ds*16+bp + 0) - 1);
        push(r16[si]);
        if (memory16get(ds*16+bp + 0) & 0x0002) {
            pc = 0x18987;
            break;
        }
        lea(si, ds, r16[di] + 2);
        pc = 0x1898A;
        break;
    case 0x18987:
        lea(si, ds, r16[di] + 10);
    case 0x1898A:
        r16[ax] = memory16get(cs*16+r16[si]);
        memory16set(ds*16+r16[bx], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si] + 2);
        memory16set(ds*16+r16[bx] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si] + 4);
        memory16set(ds*16+r16[bx] + 40, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si] + 6);
        memory16set(ds*16+r16[bx] + 42, r16[ax]);
        r16[si] = pop();
    case 0x189A5:
        bp += 0x0002;
        r16[di] += 0x0012;
        if (--r16[cx]) {
            pc = 0x18968;
            break;
        }
        return;
    } while (1);
}
function* sub_189AE() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+0x91AA) > signed16(0x0120)) {
            pc = 0x189BC;
            break;
        }
        memory16set(ds*16+0x91AA, 0x0120);
    case 0x189BC:
        if (memory16get(ds*16+r16[si] + 32) != 0x0000) {
            pc = 0x18A0F;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 26) >= 0 /*CHECK*/) {
            pc = 0x189FB;
            break;
        }
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+0x9190);
        if (r16s[ax] > signed16(0x00b0))
            return;
        r16[ax] = memory16get(ds*16+0x9F12);
        if (r16s[ax] < signed16(0x0000))
            return;
        if (r16s[ax] > signed16(0x013f))
            return;
        memory16set(ds*16+r16[si] + 32, 0x03e8);
        memory16set(ds*16+r16[si] + 28, 0x0003);
        memory16set(ds*16+r16[si] + 26, 0x0154);
        return;
    case 0x189FB:
        memory16set(ds*16+r16[si] + 26, memory16get(ds*16+r16[si] + 26) - 1);
        if (memory16gets(ds*16+r16[si] + 26) >= 0) {
            pc = 0x18A0F;
            break;
        }
        memory16set(ds*16+r16[si] + 48, 0x0000);
        memory16set(ds*16+r16[si] + 32, 0x03e8);
        memory16set(ds*16+r16[si] + 28, 0xfffd);
    case 0x18A0F:
        r8[al] = memory[cs*16+0x7732];
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry) {
            pc = 0x18A8B;
            break;
        }
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
        yield* sub_14191();
        r16[ax] &= 0x0003;
        if (r16[ax] == 0) {
            pc = 0x18A58;
            break;
        }
        r16[ax] = 0x00a0;
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[bx] += 0x0070;
        r16[cx] = 0x0004;
        r16[dx] = memory[cs*16+0x7734];
        yield* sub_11ED3();
        r16[bx] = 0x7a80;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[di] + 16, r16[bx]);
        pc = 0x18A8B;
        break;
    case 0x18A58:
        r16[cx] = 0x0010;
    case 0x18A5B:
        push(r16[cx]);
        r16[ax] = 0x00a0;
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[bx] = r16[bx] - memory16get(ds*16+0x9190);
        r16[bx] += 0x0070;
        r16[cx] -= 1;
        r16[dx] = memory[cs*16+0x7734];
        yield* sub_11ED3();
        r16[bx] = 0x7a92;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[di] + 16, r16[bx]);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x18A5B;
            break;
        }
    case 0x18A8B:
        memory16set(ds*16+0xFCF2, 0x0098);
        memory16set(ds*16+0xFCFA, 0x00a7);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCF6, memory16get(ds*16+0xFCF6) - r16[ax]);
        memory16set(ds*16+0xFCF6, memory16get(ds*16+0xFCF6) + 0x0070);
        r16[ax] = memory16get(ds*16+0xFCF6);
        memory16set(ds*16+0xFCFE, r16[ax]);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + 0x000a);
        r16[ax] = memory16get(ds*16+0xFCF2);
        memory16set(ds*16+r16[si] + 40, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF6);
        memory16set(ds*16+r16[si] + 42, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFA);
        memory16set(ds*16+r16[si] + 44, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+r16[si] + 46, r16[ax]);
        if (memory16gets(ds*16+0x9190) < signed16(0x0160)) {
            pc = 0x18AD7;
            break;
        }
        return;
    case 0x18AD7:
        if (memory16get(ds*16+r16[si] + 48) != 0x0000) {
            pc = 0x18AE0;
            break;
        }
        pc = 0x18B78;
        break;
    case 0x18AE0:
        r16[bx] = memory16get(ds*16+r16[si] + 34);
        r16[bx] += 0x0002;
        r16[bx] &= 0x0006;
        memory16set(ds*16+r16[si] + 34, r16[bx]);
        r16[bx] = memory16get(cs*16+r16[bx] + -27405);
        r16[di] = 0x9333;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(cs*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(cs*16+r16[di] + 14, r16[ax]);
        memory16set(ds*16+r16[si] + 48, memory16get(ds*16+r16[si] + 48) - 1);
        if (memory16get(ds*16+r16[si] + 48) != 0)
            return;
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        memory16set(ds*16+r16[di], 0x010c);
        memory16set(ds*16+r16[di] + 2, 0x83bd);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 6, 0x0761);
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 44, 0x03e8);
        memory16set(ds*16+r16[di] + 18, 0x00a0);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9190);
        r16[ax] += 0x0080;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        r16[bx] = 0x78de;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[di] + 16, r16[bx]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        yield* sub_14191();
        r16[ax] &= 0x0007;
        memory16set(ds*16+r16[di] + 28, r16[ax]);
        return;
    case 0x18B78:
        if (memory16get(ds*16+r16[si] + 32) != 0x0000) {
            pc = 0x18B81;
            break;
        }
        pc = 0x18C0D;
        break;
    case 0x18B81:
        r8[ah] = 0x11;
        interrupt(128);
        if (r8[al] & r8[al]) {
            pc = 0x18B8F;
            break;
        }
        memory16set(ds*16+0x8E88, 0x0011);
    case 0x18B8F:
        memory16set(ds*16+r16[si] + 32, memory16get(ds*16+r16[si] + 32) - 1);
        r16[ax] = memory16get(ds*16+r16[si] + 28);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        if (r16s[ax] >= signed16(0x0060)) {
            pc = 0x18BA5;
            break;
        }
        r16[ax] = 0x0060;
        memory16set(ds*16+r16[si] + 32, 0x0000);
    case 0x18BA5:
        if (r16s[ax] <= signed16(0x00c0)) {
            pc = 0x18BB2;
            break;
        }
        r16[ax] = 0x00c0;
        memory16set(ds*16+r16[si] + 32, 0x0000);
    case 0x18BB2:
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[bx] = memory16get(ds*16+0x919C);
        r16[bx] &= 0x0001;
        r16[bx] <<= 1;
        push(r16[bx]);
        r16[bx] = memory16get(cs*16+r16[bx] + -27397);
        r16[di] = 0x933b;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(cs*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(cs*16+r16[di] + 14, r16[ax]);
        r16[bx] = pop();
        r16[bx] = memory16get(cs*16+r16[bx] + -27393);
        r16[di] = 0x9343;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(cs*16+r16[di], r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(cs*16+r16[di] + 2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 4);
        memory16set(cs*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 6);
        memory16set(cs*16+r16[di] + 14, r16[ax]);
        return;
    case 0x18C0D:
        if (memory16gets(ds*16+0x8F32) >= signed16(0x0010)) {
            pc = 0x18C26;
            break;
        }
        yield* sub_14191();
        if (r16[ax] & 0x2000) {
            pc = 0x18C26;
            break;
        }
        r16[ax] &= 0x0007;
        r16[ax] += 0x0002;
        memory16set(ds*16+r16[si] + 48, r16[ax]);
        return;
    case 0x18C26:
        r16[dx] = 0xfffd;
        if (r16[ax] & 0x4000) {
            pc = 0x18C31;
            break;
        }
        r16[dx] = 0x0003;
    case 0x18C31:
        r16[ax] &= 0x0007;
        r16[ax] += 0x0008;
        memory16set(ds*16+r16[si] + 32, r16[ax]);
        memory16set(ds*16+r16[si] + 28, r16[dx]);
        return;
    } while (1);
}
function* sub_18C3E() {
    if (memory16gets(ds*16+0x9190) >= signed16(0x0160))
        return;
    push(r16[si]);
    r16[ax] = 0x0006;
    r16[bx] = 0x0009;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[cx] = 0x0038;
    r16[si] = 0x92e7;
    yield* sub_10941();
    r16[si] = pop();
    return;
}
function* sub_18C5F() {
    memory16set(ds*16+r16[si] + 4, 0x8c3e);
    if (memory16gets(ds*16+0x9190) >= signed16(0x0160))
        return;
    push(r16[si]);
    r16[ax] = 0x0006;
    r16[bx] = 0x0009;
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
    r16[cx] = 0x0038;
    r16[si] = 0x92e7;
    yield* sub_10963();
    r16[si] = pop();
    return;
}
function* sub_18C85() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[bx] ^ r16[bx];
        if (memory16gets(ds*16+0xFCE6) > signed16(0x0080)) {
            pc = 0x18C92;
            break;
        }
        r16[bx] |= 0x0002;
    case 0x18C92:
        if (memory16gets(ds*16+0xFCE2) > signed16(0x0080)) {
            pc = 0x18C9D;
            break;
        }
        r16[bx] |= 0x0004;
    case 0x18C9D:
        r16[di] = memory16get(cs*16+r16[bx] + -27389);
        r16[di] += 0x938b;
        return;
    } while (1);
}
function* sub_18CA7() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCEE, memory16get(ds*16+0xFCEE) + r16[ax]);
        if (memory16gets(ds*16+0xFCE6) >= signed16(0x01b0)) {
            pc = 0x18D08;
            break;
        }
        yield* sub_18C85();
        r16[cx] = memory16get(cs*16+r16[di]);
        r16[di] += 0x0002;
    case 0x18CC6:
        push(r16[cx]);
        if (memory[cs*16+r16[di]] == 0x0000) {
            pc = 0x18CFF;
            break;
        }
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+0xFCF2, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCEA);
        if (memory16gets(ds*16+0xFCF2) > r16s[ax]) {
            pc = 0x18D07;
            break;
        }
        r16[ax] = memory16get(cs*16+r16[di] + 4);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF2);
        memory16set(ds*16+0xFCFA, r16[ax]);
        memory16set(ds*16+0xFCFA, memory16get(ds*16+0xFCFA) + 0x000f);
        r16[ax] = memory16get(ds*16+0xFCF6);
        memory16set(ds*16+0xFCFE, r16[ax]);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + 0x000f);
        yield* sub_10F2F();
        if (!flags.zero) {
            pc = 0x18D0B;
            break;
        }
    case 0x18CFF:
        r16[di] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x18CC6;
            break;
        }
        pc = 0x18D08;
        break;
    case 0x18D07:
        r16[cx] = pop();
    case 0x18D08:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.zero = true;
        return;
    case 0x18D0B:
        r16[bx] = 0x98ce;
        memory16set(ds*16+r16[bx] + 12, r16[di]);
        r16[di] = r16[bx];
        r16[cx] = pop();
        r16[ax] = r16[ax] ^ r16[ax];
        r16[ax] -= 1;
        flags.zero = false;
        return;
    } while (1);
}
function* loc_18D8E() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x18D8E:
        push(r16[cx]);
        if (memory[cs*16+r16[di]] != 0x0000) {
            pc = 0x18DE7;
            break;
        }
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+0xFCF2, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 4);
        memory16set(ds*16+0xFCF6, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCF2);
        memory16set(ds*16+0xFCFA, r16[ax]);
        memory16set(ds*16+0xFCFA, memory16get(ds*16+0xFCFA) + 0x000f);
        r16[ax] = memory16get(ds*16+0xFCF6);
        memory16set(ds*16+0xFCFE, r16[ax]);
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) + 0x000f);
        yield* sub_10F2F();
        if (flags.zero) {
            pc = 0x18DE7;
            break;
        }
        memory[cs*16+r16[di]] = 0x0001;
        r16[ax] = memory16get(ds*16+0xFCF6);
        r16[bx] = memory16get(ds*16+0xFCF2);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[dx] = 0x0014;
        _mul(r16[dx]);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(cs*16+r16[di] + 6);
        memory16set(ds*16+r16[bx] + 0, r16[ax]);
        pc = 0x18DEE;
        break;
    case 0x18DE7:
        r16[di] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x18D8E;
            break;
        }
        return;
    case 0x18DEE:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_18DF0() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
    case 0x18DF6:
        memory16set(cs*16+r16[si], 0x0001);
        r16[si] += 0x0008;
        if (--r16[cx]) {
            pc = 0x18DF6;
            break;
        }
        return;
    } while (1);
}
function* sub_18E01() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0x91A8, 0x09e0);
        memory16set(ds*16+0x91AA, 0x11ff);
        memory16set(ds*16+0x8EAC, 0x0fa0);
        memory16set(ds*16+0x8EAE, 0x04b0);
        memory[ds*16+0x9230] = 0x00;
        yield* sub_11022();
        r16[di] = 0x904a;
        yield* sub_1077C();
        memory16set(ds*16+r16[si], 0x0050);
        memory16set(ds*16+r16[si] + 2, 0x89ae);
        memory16set(ds*16+r16[si] + 4, 0x8c3e);
        memory16set(ds*16+r16[si] + 6, 0x8745);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory[ds*16+r16[si] + 74] = 0xff;
        memory[ds*16+r16[si] + 75] = 0xff;
        memory16set(ds*16+r16[si] + 22, 0x0060);
        r16[ax] = memory[cs*16+0x772C];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0xffff);
        memory16set(ds*16+r16[si] + 32, 0x0000);
        memory16set(ds*16+r16[si] + 48, 0x0000);
        memory16set(ds*16+r16[si] + 34, 0x0000);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        r16[cx] = 0x0003;
        r16[di] = 0x33b0;
    case 0x18E72:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x0054);
        memory16set(ds*16+r16[si] + 2, 0x88a9);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x87d5);
        r16[ax] = memory[cs*16+0x772E];
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory[ds*16+r16[si] + 74] = 0xff;
        memory[ds*16+r16[si] + 75] = 0xff;
        memory16set(ds*16+r16[si] + 72, 0x0000);
        r16[bx] = memory16get(ds*16+r16[di]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 18, r16[bx]);
        r16[ax] = memory16get(ds*16+r16[di]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[dx] = 0x0014;
        _mul(r16[dx]);
        r16[ax] += r16[bx];
        r16[ax] <<= 1;
        r16[ax] += 0x0000;
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0x0000);
        r16[cx] -= 1;
        memory16set(ds*16+r16[si] + 34, r16[cx]);
        r16[cx] += 1;
        if (--r16[cx]) {
            pc = 0x18E72;
            break;
        }
        memory16set(ds*16+0x9200, 0x0003);
        memory16set(ds*16+0x9202, 0x0000);
        memory[ds*16+0x922D] = 0x00;
        memory[ds*16+0x922E] = 0x00;
        memory[ds*16+0x922F] = 0x02;
        memory16set(ds*16+0x91D4, 0x0000);
        memory16set(ds*16+0x91D6, 0x0000);
        memory16set(ds*16+0x91D8, 0x0000);
        memory16set(ds*16+0x91DA, 0x0000);
        memory16set(ds*16+0x91DC, 0x0000);
        memory16set(ds*16+0x91DE, 0x0000);
        memory16set(ds*16+0x91E0, 0x0000);
        memory16set(ds*16+0x91E2, 0x0000);
        r16[si] = 0x938b;
        r16[si] += 0x0000;
        yield* sub_18DF0();
        r16[si] = 0x938b;
        r16[si] += 0x0062;
        yield* sub_18DF0();
        r16[si] = 0x938b;
        r16[si] += 0x00c4;
        yield* sub_18DF0();
        r16[si] = 0x938b;
        r16[si] += 0x0116;
        yield* sub_18DF0();
        r16[bx] = 0x98ce;
        memory16set(ds*16+r16[bx], 0x0000);
        memory16set(ds*16+r16[bx] + 10, r16[bx]);
        memory16set(ds*16+r16[bx] + 8, r16[bx]);
        memory16set(ds*16+r16[bx] + 2, 0x0761);
        memory16set(ds*16+r16[bx] + 4, 0x0761);
        memory16set(ds*16+r16[bx] + 6, 0x8d18);
        memory16set(ds*16+0x91F4, 0x45d2);
        memory16set(ds*16+0x91F6, 0xaa6a);
        r16[ax] = memory16get(ds*16+0x991A);
        memory16set(ds*16+0x8E76, r16[ax]);
        r16[ax] = memory16get(ds*16+0x991A);
        r16[ax] <<= 1;
        memory16set(ds*16+0x8E78, r16[ax]);
        r16[si] = 0x938b;
        r16[di] = 0xd10c;
        r16[cx] = 0x00b4;
    case 0x18F7F:
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        stosw_data_forward();
        if (--r16[cx]) {
            pc = 0x18F7F;
            break;
        }
        memory16set(ds*16+0x8E72, 0x1b55);
        return;
    } while (1);
}
function* sub_19E89() {
    yield* sub_141B1();
    r16[di] = memory16get(ds*16+r16[si] + 68);
    r16[ax] = memory16get(ds*16+r16[di] + 18);
    r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 60);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 22);
    r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 62);
    memory16set(ds*16+r16[si] + 22, r16[ax]);
{yield* sub_13589(); return; };
}
function* loc_19EB6() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 12, 0x7dbb);
    case 0x19EBB:
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 6, 0x0761);
        return;
    case 0x19ED0:
        if (memory16get(ds*16+0x9204) == 0x0000) {
            pc = 0x19ED9;
            break;
        }
        if (memory16gets(ds*16+0x9204) >= 0 /*CHECK*/) {
            pc = 0x19EE0;
            break;
        }
    case 0x19ED9:
        memory16set(ds*16+r16[si] + 12, 0x7d29);
        pc = 0x19EBB;
        break;
    case 0x19EE0:
        if (memory16get(ds*16+r16[si] + 14) != 0x0000)
            _STOP_("goto loc_19F19");
        r8[al] = memory[cs*16+0x9596];
        flags.carry = (memory[ds*16+r16[si] + 72] + r8[al]) >= 0x100;
        memory[ds*16+r16[si] + 72] += r8[al];
        if (!flags.carry)
            _STOP_("goto loc_19F0E");
        yield* sub_14191();
        r8[al] &= 0x3f;
        memory[ds*16+r16[si] + 72] = r8[al];
        bp = 0x9870;
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        _STOP_("db  2Eh");
        return;
    } while (1);
}
function* sub_19F02() {
    r16[ax] = _stack16(bp + 2);
    memory16set(ds*16+r16[si] + 14, r16[ax]);
    bp += 0x0004;
    memory16set(ds*16+r16[si] + 16, bp);
    loc_19F0E:
    memory16set(ds*16+r16[si] + 40, 0x03e8);
    memory16set(ds*16+r16[si] + 44, 0x03e8);
}
function* loc_19F19() {
    var pc = 0;
    do switch (pc) {
    case 0:
    {yield* sub_13589(); return; };
        r16[bx] = memory16get(ds*16+r16[di] + 68);
    case 0x19F1F:
        memory16set(ds*16+r16[bx] + 4, 0x08b9);
        r16[bx] = memory16get(ds*16+r16[bx] + 70);
        if (r16[bx] & r16[bx]) {
            pc = 0x19F1F;
            break;
        }
        if (memory16get(ds*16+r16[di] + 34) == 0x0028) {
            pc = 0x19F38;
            break;
        }
        memory16set(ds*16+0x9206, memory16get(ds*16+0x9206) - r16[ax]);
        if (_FIXME_) {
            pc = 0x19F3F;
            break;
        }
        return;
    case 0x19F38:
        memory16set(ds*16+0x9204, memory16get(ds*16+0x9204) - r16[ax]);
        if (_FIXME_) {
            pc = 0x19F3F;
            break;
        }
        return;
    case 0x19F3F:
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 6, 0x0761);
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_10EF5();
        r16[si] = pop();
        bp = 0x1230;
        r16[dx] = 0x0853;
        yield* sub_13326();
        memory16set(ds*16+0x920E, memory16get(ds*16+0x920E) - 1);
        if (memory16get(ds*16+0x920E) == 0) {
            pc = 0x19F65;
            break;
        }
        return;
    case 0x19F65:
        r16[bx] = memory16get(ds*16+r16[di] + 68);
        memory16set(ds*16+r16[bx] + 36, 0x0000);
        r16[ax] = 0x0001;
        yield* sub_13A39();
        r16[cx] = 0x0004;
        yield* sub_115E4();
        memory[ds*16+0x9225] = 0x00;
        return;
        yield* sub_19E89();
        if (memory16get(ds*16+r16[si] + 48) != 0x0000) {
            pc = 0x19FFC;
            break;
        }
        yield* sub_14191();
        if (r8[al] < 0x03) {
            pc = 0x19F92;
            break;
        }
        pc = 0x1A017;
        break;
    case 0x19F92:
        memory16set(ds*16+0x8E8A, 0x0001);
        memory16set(ds*16+r16[si] + 48, 0x0001);
        memory16set(ds*16+r16[si] + 32, 0x0001);
        r16[di] = memory16get(ds*16+r16[si] + 10);
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+0x9F16);
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si] + 22);
        yield* sub_11B90();
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r8[al] -= 0x60;
        memory16set(ds*16+r16[di] + 30, 0x0000);
        memory16set(ds*16+r16[di] + 28, r16[ax]);
        yield* sub_14191();
        r16[ax] &= 0x001f;
        r16[ax] += 0x0020;
        r8[ah] = r8[al];
        r8[al] = r8[al] ^ r8[al];
        r8[ah] <<= 1;
        r8[ah] <<= 1;
        memory16set(ds*16+r16[di] + 62, 0x0000);
        memory16set(ds*16+r16[di] + 60, r16[ax]);
        memory16set(ds*16+r16[di] + 64, 0x0000);
        memory16set(ds*16+r16[di] + 66, 0x0001);
        if (memory16get(ds*16+r16[si] + 34) != 0x003c) {
            pc = 0x19FF9;
            break;
        }
        memory[ds*16+r16[di] + 28] += 0x40;
        memory16set(ds*16+r16[di] + 60, -memory16get(ds*16+r16[di] + 60));
    case 0x19FF9:
    {yield* sub_13589(); return; };
    case 0x19FFC:
        r16[ax] = memory16get(ds*16+r16[si] + 32);
        memory16set(ds*16+r16[si] + 48, memory16get(ds*16+r16[si] + 48) + r16[ax]);
        if (memory16get(ds*16+r16[si] + 48) != 0x000e) {
            pc = 0x1A00B;
            break;
        }
        memory16set(ds*16+r16[si] + 32, -memory16get(ds*16+r16[si] + 32));
    case 0x1A00B:
        r16[di] = memory16get(ds*16+r16[si] + 10);
        r16[ax] = memory16get(ds*16+r16[si] + 48);
        memory16set(ds*16+r16[di] + 66, r16[ax]);
    {yield* sub_13589(); return; };
    case 0x1A017:
        r16[di] = memory16get(ds*16+r16[si] + 10);
        memory16set(ds*16+r16[di] + 66, 0x0000);
        memory16set(ds*16+r16[di] + 28, 0x0040);
    {yield* sub_13589(); return; };
        return;
    } while (1);
}
function* sub_1A027() {
    r16[di] = memory16get(ds*16+r16[si] + 8);
    r16[ax] = memory16get(ds*16+r16[di] + 18);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 20);
    memory16set(ds*16+r16[si] + 20, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 22);
    memory16set(ds*16+r16[si] + 22, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 24);
    memory16set(ds*16+r16[si] + 24, r16[ax]);
    memory16set(ds*16+r16[si] + 26, 0x03e8);
    push(memory16get(ds*16+r16[si] + 28));
    push(memory16get(ds*16+r16[si] + 30));
    push(memory16get(ds*16+r16[si] + 60));
    push(memory16get(ds*16+r16[si] + 62));
    push(memory16get(ds*16+r16[si] + 64));
    yield* sub_14865();
    r16[di] = memory16get(ds*16+r16[si] + 10);
    r16[ax] = memory16get(ds*16+r16[si] + 28);
    memory16set(ds*16+r16[di] + 28, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 30);
    memory16set(ds*16+r16[di] + 30, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 60);
    memory16set(ds*16+r16[di] + 60, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 62);
    memory16set(ds*16+r16[di] + 62, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 64);
    memory16set(ds*16+r16[di] + 64, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 66);
    memory16set(ds*16+r16[di] + 66, r16[ax]);
    memory16set(ds*16+r16[si] + 64, pop());
    memory16set(ds*16+r16[si] + 62, pop());
    memory16set(ds*16+r16[si] + 60, pop());
    memory16set(ds*16+r16[si] + 30, pop());
    memory16set(ds*16+r16[si] + 28, pop());
}
function* sub_1A090() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+r16[si] + 8);
        r16[ax] = memory16get(ds*16+r16[di] + 18);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 20);
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 22);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 24);
        memory16set(ds*16+r16[si] + 24, r16[ax]);
        memory16set(ds*16+r16[si] + 26, 0x03e8);
        yield* sub_14865();
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] &= 0x001c;
        if (memory16get(ds*16+r16[si] + 66) != 0x000e) {
            pc = 0x1A0CB;
            break;
        }
        memory16set(ds*16+0x8E88, 0x0001);
    case 0x1A0CB:
        r16[ax] = memory16get(ds*16+0x919C);
        r16[ax] &= 0x0004;
        r16[ax] >>= 1;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(cs*16+r16[bx] + -20881);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        memory16set(ds*16+r16[si] + 14, 0x0000);
    {yield* sub_13589(); return; };
        return;
    } while (1);
}
function* sub_1A0E5() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0xadc3;
        yield* sub_11022();
        bp = r16[si];
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1078E();
        r16[di] = pop();
        pc = 0x1A105;
        break;
    case 0x1A0F7:
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1078E();
        r16[di] = pop();
        memory16set(ds*16+r16[bx] + 70, r16[si]);
    case 0x1A105:
        memory16set(ds*16+r16[si], 0x0054);
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 6, r16[ax]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 26, 0x0000);
        r16[bx] = memory16get(cs*16+r16[di]);
        r16[di] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 60, r16[ax]);
        r16[di] += 0x0002;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 62, r16[ax]);
        r16[di] += 0x0002;
        memory16set(ds*16+r16[si] + 72, 0x0000);
        memory16set(ds*16+r16[si] + 52, 0x03e8);
        memory[ds*16+r16[si] + 39] = 0xff;
        r16[bx] = memory16get(ds*16+0xDED6);
        memory16set(ds*16+r16[si] + 56, r16[bx]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 4);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 18, memory16get(ds*16+r16[si] + 18) - 0x0020);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - 0x0028);
        memory16set(ds*16+r16[si] + 20, 0x0000);
        memory16set(ds*16+r16[si] + 24, 0x0000);
        r16[bx] += 0x0006;
        memory16set(ds*16+r16[si] + 58, r16[bx]);
        memory16set(ds*16+r16[si] + 28, 0x0000);
        memory16set(ds*16+r16[si] + 30, 0x0000);
        memory16set(ds*16+r16[si] + 64, 0x0000);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        r16[ax] = memory16get(cs*16+0x19564);
        memory16set(ds*16+r16[si] + 66, r16[ax]);
        yield* sub_13589();
        memory16set(ds*16+r16[si] + 68, bp);
        memory16set(ds*16+r16[si] + 70, 0x0000);
        r16[ax] = r16[di];
        r16[ax] -= 0xadc3;
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        memory16set(ds*16+r16[si] + 48, 0x0000);
        r16[bx] = r16[si];
        if (memory[cs*16+r16[di]] == 0x0000) {
            pc = 0x1A1C7;
            break;
        }
        pc = 0x1A0F7;
        break;
    case 0x1A1C7:
        memory[ds*16+0x9235] = 0xff;
        memory[ds*16+0x9225] = 0xff;
        return;
    } while (1);
}
function* loc_1A1F4() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[di] + 10);
        memory16set(ds*16+0xFCE6, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9190);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        memory16set(ds*16+0xFCFE, 0x0007);
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        bp = r16[si];
    case 0x1A214:
        memory16set(ds*16+r16[si], 0x00c8);
        memory16set(ds*16+r16[si] + 12, 0x4045);
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 72, 0x0000);
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x1A236;
            break;
        }
        memory16set(ds*16+r16[si], 0x00cc);
        memory16set(ds*16+r16[si] + 12, 0x3f95);
    case 0x1A236:
        if (memory16get(ds*16+0xFCFE) != 0x0000) {
            pc = 0x1A25C;
            break;
        }
        r16[bx] = 0x98b2;
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x1A249;
            break;
        }
        r16[bx] = 0x98cc;
    case 0x1A249:
        r16[ax] = memory16get(cs*16+r16[bx]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[bx] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[bx] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[bx]);
    case 0x1A25C:
        memory16set(ds*16+r16[si] + 2, 0xa656);
        if (memory16get(ds*16+0xFCFE) != 0x0000) {
            pc = 0x1A26D;
            break;
        }
        memory16set(ds*16+r16[si] + 2, 0xa613);
    case 0x1A26D:
        if (memory16get(ds*16+0xFCFE) != 0x0007) {
            pc = 0x1A279;
            break;
        }
        memory16set(ds*16+r16[si] + 2, 0xa5a4);
    case 0x1A279:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+r16[si] + 32, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 6, 0x3a39);
        memory[ds*16+r16[si] + 38] = 0x01;
        r16[ax] = memory16get(cs*16+0x19566);
        memory16set(ds*16+r16[si] + 36, r16[ax]);
        memory[ds*16+r16[si] + 39] = 0x00;
        memory16set(ds*16+r16[si] + 52, 0x0190);
        memory16set(ds*16+r16[si] + 26, 0x0000);
        memory16set(ds*16+r16[si] + 54, 0x0000);
        memory16set(ds*16+r16[si] + 28, 0x0000);
        r16[ax] = 0x0007;
        r16[ax] = r16[ax] - memory16get(ds*16+0xFCFE);
        if (memory16get(ds*16+r16[di] + 12) == 0x0000) {
            pc = 0x1A2C7;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1A2C7:
        memory16set(ds*16+r16[si] + 34, r16[ax]);
        yield* sub_13589();
        memory16set(ds*16+r16[si] + 68, bp);
        memory16set(ds*16+r16[si] + 70, 0x0000);
        if (memory16get(ds*16+0xFCFE) == 0x0000) {
            pc = 0x1A2E9;
            break;
        }
        push(r16[di]);
        r16[di] = r16[si];
        yield* sub_11022();
        yield* sub_1077C();
        memory16set(ds*16+r16[di] + 70, r16[si]);
        r16[di] = pop();
    case 0x1A2E9:
        memory16set(ds*16+0xFCFE, memory16get(ds*16+0xFCFE) - 1);
        if (memory16gets(ds*16+0xFCFE) < 0) {
            pc = 0x1A2F2;
            break;
        }
        pc = 0x1A214;
        break;
    case 0x1A2F2:
        r16[di] = pop();
        yield* sub_11022();
        push(r16[di]);
        r16[di] = 0x904a;
        yield* sub_1077C();
        r16[di] = pop();
        memory16set(ds*16+r16[si], 0x00b8);
        memory16set(ds*16+r16[si] + 2, 0x0761);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        memory16set(ds*16+r16[si] + 6, 0x0761);
        memory16set(ds*16+r16[si] + 40, 0x03e8);
        memory16set(ds*16+r16[si] + 44, 0x03e8);
        memory16set(ds*16+r16[si] + 70, r16[di]);
        memory16set(ds*16+r16[di], 0x00bc);
        memory16set(ds*16+r16[di] + 2, 0x25a8);
        memory16set(ds*16+r16[di] + 4, 0x0761);
        memory16set(ds*16+r16[di] + 6, 0x0761);
        memory16set(ds*16+r16[di] + 40, 0x03e8);
        memory16set(ds*16+r16[di] + 44, 0x03e8);
        memory16set(ds*16+r16[di] + 68, r16[si]);
        return;
        _STOP_("db 0E8h");
        _STOP_("db 0E0h");
        _STOP_("db  6Ch");
        _STOP_("db  57h");
        _STOP_("db 0BFh");
        _STOP_("db  4Ah");
        _STOP_("db  90h");
        _STOP_("db 0E8h");
        _STOP_("db  33h");
        _STOP_("db  64h");
        _STOP_("db  5Fh");
        _STOP_("db 0C7h");
        _STOP_("db 0D0h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  89h");
        _STOP_("db 0A6h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  53h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  48h");
        _STOP_("db  8Bh");
        _STOP_("db  45h");
        _STOP_("db  2Dh");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  12h");
        _STOP_("db  8Bh");
        _STOP_("db  45h");
        _STOP_("db  0Ah");
        _STOP_("db  2Bh");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  16h");
        _STOP_("db 0BBh");
        _STOP_("db 0E6h");
        _STOP_("db  98h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  1Ch");
        _STOP_("db  81h");
        _STOP_("db  7Ch");
        _STOP_("db  12h");
        _STOP_("db 0A0h");
        _STOP_("db  7Eh");
        _STOP_("db 0BBh");
        _STOP_("db  18h");
        _STOP_("db  99h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  1Ch");
        _STOP_("db 0FEh");
        _STOP_("db 0FFh");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  0Ch");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  47h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  0Eh");
        _STOP_("db  83h");
        _STOP_("db 0C3h");
        _STOP_("db  89h");
        _STOP_("db  5Ch");
        _STOP_("db  10h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db 0A7h");
        _STOP_("db  3Ah");
        _STOP_("db  2Eh");
        _STOP_("db 0A1h");
        _STOP_("db  68h");
        _STOP_("db  95h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  24h");
        _STOP_("db 0C6h");
        _STOP_("db  44h");
        _STOP_("db  27h");
        _STOP_("db 0FFh");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  34h");
        _STOP_("db  2Ch");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  1Ah");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  36h");
        _STOP_("db 0E9h");
        _STOP_("db 0CAh");
        _STOP_("db  91h");
        _STOP_("db 0B8h");
        _STOP_("db 0F8h");
        _STOP_("db 0BBh");
        _STOP_("db 0DFh");
        _STOP_("db 0A7h");
        _STOP_("db 0E8h");
        _STOP_("db  61h");
        _STOP_("db  91h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  61h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db 0D4h");
        _STOP_("db 0A8h");
        _STOP_("db  2Eh");
        _STOP_("db 0A1h");
        _STOP_("db  6Ah");
        _STOP_("db  95h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  24h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  28h");
        _STOP_("db 0E8h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  2Ch");
        _STOP_("db 0E8h");
        _STOP_("db  8Bh");
        _STOP_("db  7Ch");
        _STOP_("db  38h");
        _STOP_("db 0BBh");
        _STOP_("db  8Fh");
        _STOP_("db 0AEh");
        _STOP_("db 0B9h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  89h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  47h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  47h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  47h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  83h");
        _STOP_("db 0C3h");
        _STOP_("db  83h");
        _STOP_("db 0C7h");
        _STOP_("db  28h");
        _STOP_("db 0E2h");
        _STOP_("db 0DEh");
        _STOP_("db 0C3h");
        _STOP_("db 0B8h");
        _STOP_("db 0F0h");
        _STOP_("db  83h");
        _STOP_("db  7Dh");
        _STOP_("db  0Ch");
        _STOP_("db  74h");
        _STOP_("db 0B8h");
        _STOP_("db 0F4h");
        _STOP_("db 0BBh");
        _STOP_("db  25h");
        _STOP_("db 0ABh");
        _STOP_("db 0E8h");
        _STOP_("db  91h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  76h");
        _STOP_("db  3Bh");
        _STOP_("db  2Eh");
        _STOP_("db 0A1h");
        _STOP_("db  7Ch");
        _STOP_("db  95h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  24h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  28h");
        _STOP_("db 0E8h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  2Ch");
        _STOP_("db 0E8h");
        _STOP_("db  8Bh");
        _STOP_("db  6Ch");
        _STOP_("db  38h");
        _STOP_("db 0BBh");
        _STOP_("db  57h");
        _STOP_("db 0AFh");
        _STOP_("db 0BAh");
        _STOP_("db  73h");
        _STOP_("db 0AFh");
        _STOP_("db  83h");
        _STOP_("db  7Dh");
        _STOP_("db  0Ch");
        _STOP_("db  74h");
        _STOP_("db 0BBh");
        _STOP_("db  65h");
        _STOP_("db 0AFh");
        _STOP_("db 0BAh");
        _STOP_("db  75h");
        _STOP_("db 0AFh");
        _STOP_("db  89h");
        _STOP_("db  5Ch");
        _STOP_("db  0Ch");
        _STOP_("db  89h");
        _STOP_("db  54h");
        _STOP_("db  10h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  3Eh");
        _STOP_("db  89h");
        _STOP_("db  46h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  34h");
        _STOP_("db  64h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  30h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  32h");
        _STOP_("db 0C3h");
        _STOP_("db 0E8h");
        _STOP_("db  45h");
        _STOP_("db  9Dh");
        _STOP_("db 0A1h");
        _STOP_("db  98h");
        _STOP_("db  91h");
        _STOP_("db  44h");
        _STOP_("db  16h");
        _STOP_("db 0A1h");
        _STOP_("db 0AAh");
        _STOP_("db  91h");
        _STOP_("db 0D0h");
        _STOP_("db  2Bh");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  3Bh");
        _STOP_("db  44h");
        _STOP_("db  16h");
        _STOP_("db  7Dh");
        _STOP_("db 0E9h");
        _STOP_("db  1Ch");
        _STOP_("db  8Bh");
        _STOP_("db  5Ch");
        _STOP_("db  1Ch");
        _STOP_("db 0D1h");
        _STOP_("db 0E3h");
        _STOP_("db  8Bh");
        _STOP_("db  87h");
        _STOP_("db  82h");
        _STOP_("db  40h");
        _STOP_("db  85h");
        _STOP_("db 0C0h");
        _STOP_("db  74h");
        _STOP_("db  25h");
        _STOP_("db  79h");
        _STOP_("db  13h");
        _STOP_("db  44h");
        _STOP_("db 12h, 89h, 44h, 12h, 25h, 0Fh, 0, 3Dh, 0...");
        _STOP_("db 0E9h, 0BCh, 0, 0EBh, 3Ch, 3, 44h, 12h, ...");
        _STOP_("db 25h, 0Fh, 0, 74h, 3, 0E9h, 0ACh, 0, 0EB...");
        _STOP_("db 87h, 92h, 40h, 78h, 14h, 3, 44h, 16h, 8...");
        _STOP_("db 3, 6, 90h, 91h, 25h, 0Fh, 0, 74h, 3, 0E...");
        _STOP_("db 12h, 3, 44h, 16h, 89h, 44h, 16h, 3, 6, ...");
        _STOP_("db 0Fh, 0, 3Dh, 0Fh, 0, 75h, 7Eh, 8Bh, 44h...");
        _STOP_("db 74h, 48h, 3Dh, 40h, 1, 73h, 43h, 0BFh, ...");
        _STOP_("db 0E8h, 0D1h, 0E8h, 0D1h, 0E8h, 25h, 0FEh...");
        _STOP_("db 8Bh, 54h, 16h, 3, 16h, 90h, 91h, 0D1h, ...");
        _STOP_("db 0D1h, 0EAh, 0D1h, 0EAh, 0B8h, 28h, 0, 0...");
        _STOP_("db 0F8h, 83h, 3Dh, 0, 74h, 10h, 8Bh, 87h, ...");
        _STOP_("db 44h, 12h, 8Bh, 87h, 92h, 40h, 29h, 44h,...");
        _STOP_("db 8Bh, 0AFh, 0A2h, 40h, 3Eh, 83h, 3Bh, 0,...");
        _STOP_("db 87h, 0B2h, 40h, 1, 44h, 12h, 8Bh, 87h, ...");
        _STOP_("db 44h, 16h, 8Bh, 9Fh, 0D2h, 40h, 89h, 5Ch...");
        _STOP_("db 0E3h, 2Eh, 8Bh, 9Fh, 0B3h, 0ADh, 2Eh, 8...");
        _STOP_("db 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 44h, 0Eh, 8...");
        _STOP_("db 89h, 5Ch, 10h, 2Eh, 0A0h, 6Ch, 95h, 0, ...");
        _STOP_("db 34h, 0E8h, 25h, 9Ch, 24h, 3Fh, 88h, 44h...");
        _STOP_("db 1Eh, 6Eh, 95h, 0D1h, 0E3h, 2Eh, 8Bh, 0A...");
        _STOP_("db 0A1h, 12h, 9Fh, 2Bh, 44h, 12h, 8Bh, 1Eh...");
        _STOP_("db 5Ch, 16h, 0E8h, 3, 76h, 8Bh, 0C8h, 8Bh,...");
        _STOP_("db 5Ch, 16h, 2Eh, 8Bh, 16h, 70h, 95h, 0E8h...");
        _STOP_("db 8Fh, 0E8h, 1Dh, 62h, 0C3h, 0A1h, 98h, 9...");
        _STOP_("db 81h, 7Ch, 16h, 0E8h, 0, 7Dh, 5Eh, 0C7h,...");
        _STOP_("db 7, 83h, 7Ch, 1Ch, 0, 75h, 2Ch, 83h, 7Ch...");
        _STOP_("db 5, 0FFh, 44h, 22h, 0EBh, 45h, 8Bh, 44h,...");
        _STOP_("db 16h, 9Fh, 79h, 2, 0F7h, 0D8h, 3Dh, 20h,...");
        _STOP_("db 0C7h, 44h, 1Ch, 2, 0, 0E8h, 0B2h, 9Bh, ...");
        _STOP_("db 0Ah, 0, 89h, 44h, 22h, 0C7h, 44h, 4, 53...");
        _STOP_("db 1Ch, 3, 44h, 1Ah, 89h, 44h, 1Ah, 75h, 0...");
        _STOP_("db 1Ch, 2 dup(0), 0C7h, 44h, 22h, 0FBh, 0F...");
        _STOP_("db 3Bh, 44h, 22h, 75h, 3, 0F7h, 5Ch, 1Ch, ...");
        _STOP_("db 0E8h, 0AEh, 61h, 0C3h, 0A1h, 98h, 91h, ...");
        _STOP_("db 81h, 7Ch, 16h, 0E8h, 0, 7Dh, 32h, 0E8h,...");
        _STOP_("db 7Ch, 44h, 8Bh, 44h, 22h, 0F7h, 65h, 1Ah...");
        _STOP_("db 89h, 44h, 12h, 83h, 7Dh, 1Ch, 2, 75h, 6...");
        _STOP_("db 2, 74h, 0Ch, 8Bh, 45h, 22h, 85h, 0C0h, ...");
        _STOP_("db 45h, 1Ah, 75h, 5, 0C7h, 44h, 0Eh, 1, 0,...");
        _STOP_("db 0E8h, 6Bh, 61h, 0C3h, 0A1h, 98h, 91h, 1...");
        _STOP_("db 7Ch, 16h, 0E8h, 0, 7Dh, 22h, 0C7h, 44h,...");
        _STOP_("db 7Ch, 44h, 8Bh, 44h, 22h, 0F7h, 65h, 1Ah...");
        _STOP_("db 89h, 44h, 12h, 83h, 7Dh, 1Ch, 0, 74h, 5...");
        _STOP_("db 4, 53h, 8, 0E9h, 4, 8Fh, 0E8h, 38h, 61h...");
        _STOP_("db 98h, 91h, 1, 44h, 16h, 0A1h, 0AAh, 91h,...");
        _STOP_("db 2Bh, 6, 90h");
        _STOP_("db 91h, 3Bh, 44h, 16h, 7Dh, 3, 0E9h, 0Fh, ...");
        _STOP_("db 9Bh, 83h, 7Ch, 1Ah, 0, 75h, 5Fh, 8Bh, 4...");
        _STOP_("db 12h, 89h, 44h, 12h, 3Dh, 0E0h, 0FFh, 7F...");
        _STOP_("db 44h, 12h, 2 dup(0), 0BBh, 0E6h, 98h, 0F...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 44h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C3h, 4, 89h, 5Ch, 10h, 0E9h,...");
        _STOP_("db 60h, 1, 7Ch, 0Ah, 0C7h, 44h, 12h, 40h, ...");
        _STOP_("db 99h, 0EBh, 0D8h, 3Dh, 88h, 0, 75h, 0Ah,...");
        _STOP_("db 1, 0, 0BBh, 0FCh, 98h, 0EBh, 0CCh, 3Dh,...");
        _STOP_("db 0Ah, 0C7h, 44h, 1Ah, 1, 0, 0BBh, 2Eh, 9...");
        _STOP_("db 0E9h, 80h, 8Eh, 83h, 7Ch, 0Eh, 0, 75h, ...");
        _STOP_("db 1Ah, 2 dup(0), 81h, 7Ch, 12h, 0A0h, 0, ...");
        _STOP_("db 44h, 12h, 68h, 0, 0BBh, 18h, 99h, 0EBh,...");
        _STOP_("db 12h, 0D8h, 0, 0BBh, 0E6h, 98h, 0EBh, 91...");
        _STOP_("db 1Ah, 83h, 7Ch, 1Ah, 0Bh, 2 dup(75h), 8B...");
        _STOP_("db 0A3h, 0E2h, 0FCh, 8Bh, 44h, 16h, 0A3h, ...");
        _STOP_("db 2Eh, 0E2h, 0FCh, 5, 83h, 6, 0E6h, 0FCh,...");
        _STOP_("db 40h, 81h, 3Eh, 0E2h, 0FCh, 0A0h, 0, 7Eh...");
        _STOP_("db 0E2h, 0FCh, 0Ah, 0BBh, 29h, 41h, 56h, 0...");
        _STOP_("db 0BFh, 96h, 90h, 0E8h, 11h, 60h, 8Bh, 0F...");
        _STOP_("db 5, 14h, 0, 0C7h, 45h, 2, 0B4h, 0A7h, 0C...");
        _STOP_("db 8, 89h, 5Dh, 0Ch, 0C7h, 45h, 0Eh, 2 dup...");
        _STOP_("db 0FCh, 89h, 45h, 12h, 0A1h, 0E6h, 0FCh, ...");
        _STOP_("db 0C7h, 45h, 1Ah, 2 dup(0), 2Eh, 0A1h, 72...");
        _STOP_("db 45h, 42h, 0C7h, 45h, 1Ch, 3, 0, 81h, 7C...");
        _STOP_("db 0, 7Ch, 5, 0C7h, 45h, 1Ch, 5, 0, 0E9h, ...");
        _STOP_("db 0Dh, 60h, 0C3h, 0E8h, 96h, 77h, 83h, 3C...");
        _STOP_("db 22h, 81h, 7Ch, 12h, 80h, 0, 7Dh, 0Ah, 0...");
        _STOP_("db 3, 0, 0C7h, 44h, 0Ch, 0F5h, 40h, 81h, 7...");
        _STOP_("db 0, 7Ch, 0Ah, 0C7h, 44h, 1Ch, 5, 0, 0C7h...");
        _STOP_("db 41h, 0C3h, 0A1h, 0AAh, 91h, 5, 0D0h, 0,...");
        _STOP_("db 7Dh, 3, 0E9h, 0E3h, 0, 8Bh, 44h, 12h, 5...");
        _STOP_("db 44h, 28h, 5, 1Fh, 0, 89h, 44h, 2Ch, 8Bh...");
        _STOP_("db 6, 90h, 91h, 5, 40h, 0, 89h, 44h, 2Ah, ...");
        _STOP_("db 44h, 2Eh, 8Bh, 44h, 1Ah, 75h, 0Dh, 0E8h...");
        _STOP_("db 3Ah, 6, 74h, 95h, 73h, 63h, 0B8h, 2 dup...");
        _STOP_("db 0FFh, 0D1h, 0E0h, 0D1h, 0E0h, 8Bh, 0D8h...");
        _STOP_("db 2Eh, 8Bh, 87h, 0BFh, 0AEh, 89h, 85h, 0A...");
        _STOP_("db 87h, 0C1h, 0AEh, 89h, 85h, 0A4h, 0, 2Eh...");
        _STOP_("db 0AEh, 89h, 85h, 0CAh, 0, 2Eh, 8Bh, 87h,...");
        _STOP_("db 89h, 85h, 0CCh, 0, 0FFh, 44h, 1Ah, 83h,...");
        _STOP_("db 74h, 22h, 83h, 7Ch, 1Ah, 4, 7Ch, 21h, 8...");
        _STOP_("db 0Bh, 7Eh, 1Ch, 83h, 7Ch, 1Ah, 0Ch, 75h,...");
        _STOP_("db 99h, 2Eh, 3Ah, 6, 76h, 95h, 73h, 0Bh, 0...");
        _STOP_("db 4, 0, 0C3h, 0C7h, 44h, 1Ah, 2 dup(0), 0...");
        _STOP_("db 78h, 95h, 0, 44h, 48h, 73h, 0F6h, 0E8h,...");
        _STOP_("db 3Fh, 88h, 44h, 48h, 8Bh, 44h, 12h, 8Bh,...");
        _STOP_("db 20h, 0, 2Bh, 1Eh, 90h");
        _STOP_("db 0C3h");
        _STOP_("db  58h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  3Eh");
        _STOP_("db  7Ah");
        _STOP_("db  95h");
        _STOP_("db 0D1h");
        _STOP_("db 0E7h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db 0ADh");
        _STOP_("db 0C7h");
        _STOP_("db 0AFh");
        _STOP_("db 0B9h");
        _STOP_("db  8Bh");
        _STOP_("db  54h");
        _STOP_("db  1Ah");
        _STOP_("db  83h");
        _STOP_("db 0E2h");
        _STOP_("db 0FEh");
        _STOP_("db  83h");
        _STOP_("db 0FAh");
        _STOP_("db  75h");
        _STOP_("db 0B9h");
        _STOP_("db  83h");
        _STOP_("db 0FAh");
        _STOP_("db  75h");
        _STOP_("db 0B9h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  16h");
        _STOP_("db  7Ch");
        _STOP_("db  95h");
        _STOP_("db 0E9h");
        _STOP_("db  76h");
        _STOP_("db 0E8h");
        _STOP_("db 0EDh");
        _STOP_("db  5Eh");
        _STOP_("db 0C3h");
        _STOP_("db  29h");
        _STOP_("db  45h");
        _STOP_("db  24h");
        _STOP_("db  76h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  78h");
        _STOP_("db 0A9h");
        _STOP_("db 0C3h");
        _STOP_("db 0BAh");
        _STOP_("db  53h");
        _STOP_("db  8Bh");
        _STOP_("db  45h");
        _STOP_("db  12h");
        _STOP_("db  20h");
        _STOP_("db  8Bh");
        _STOP_("db  5Dh");
        _STOP_("db  16h");
        _STOP_("db  2Bh");
        _STOP_("db  1Eh");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  83h");
        _STOP_("db 0C3h");
        _STOP_("db  40h");
        _STOP_("db 0BDh");
        _STOP_("db  4Ch");
        _STOP_("db  12h");
        _STOP_("db 0E8h");
        _STOP_("db  2Eh");
        _STOP_("db  8Ah");
        _STOP_("db  8Bh");
        _STOP_("db  5Dh");
        _STOP_("db  38h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  50h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  52h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  54h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  56h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  78h");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  7Ah");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  7Ch");
        _STOP_("db 0C7h");
        _STOP_("db  47h");
        _STOP_("db  7Eh");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0A0h");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0A2h");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0A4h");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0A6h");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0CAh");
        _STOP_("db 0C7h");
        _STOP_("db  87h");
        _STOP_("db 0CCh");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db 0CFh");
        _STOP_("db 0A9h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  61h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  9Eh");
        _STOP_("db 0AAh");
        _STOP_("db  2Eh");
        _STOP_("db 0A1h");
        _STOP_("db  7Eh");
        _STOP_("db  95h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  24h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  28h");
        _STOP_("db 0E8h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  2Ch");
        _STOP_("db 0E8h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db  1Ah");
        _STOP_("db  81h");
        _STOP_("db  52h");
        _STOP_("db  91h");
        _STOP_("db 0F4h");
        _STOP_("db  83h");
        _STOP_("db  16h");
        _STOP_("db  54h");
        _STOP_("db  91h");
        _STOP_("db 0C3h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  61h");
        _STOP_("db 0B8h");
        _STOP_("db 0BBh");
        _STOP_("db  8Bh");
        _STOP_("db  54h");
        _STOP_("db  16h");
        _STOP_("db  2Bh");
        _STOP_("db  16h");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  83h");
        _STOP_("db 0C2h");
        _STOP_("db  20h");
        _STOP_("db  8Bh");
        _STOP_("db  4Ch");
        _STOP_("db  12h");
        _STOP_("db 0D1h");
        _STOP_("db 0E9h");
        _STOP_("db  83h");
        _STOP_("db 0E1h");
        _STOP_("db 0FCh");
        _STOP_("db  56h");
        _STOP_("db 0BEh");
        _STOP_("db 0AFh");
        _STOP_("db 0E8h");
        _STOP_("db 0C7h");
        _STOP_("db  5Fh");
        _STOP_("db  5Eh");
        _STOP_("db 0BFh");
        _STOP_("db 0BFh");
        _STOP_("db 0AEh");
        _STOP_("db  8Bh");
        _STOP_("db  44h");
        _STOP_("db  1Ah");
        _STOP_("db  25h");
        _STOP_("db 0FEh");
        _STOP_("db 0FFh");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db 0F8h");
        _STOP_("db 0B8h");
        _STOP_("db 0BBh");
        _STOP_("db  8Bh");
        _STOP_("db  54h");
        _STOP_("db  16h");
        _STOP_("db  2Bh");
        _STOP_("db  16h");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  83h");
        _STOP_("db 0C2h");
        _STOP_("db  40h");
        _STOP_("db  8Bh");
        _STOP_("db  4Ch");
        _STOP_("db  12h");
        _STOP_("db  83h");
        _STOP_("db 0C1h");
        _STOP_("db  10h");
        _STOP_("db 0D1h");
        _STOP_("db 0E9h");
        _STOP_("db  83h");
        _STOP_("db 0E1h");
        _STOP_("db 0FCh");
        _STOP_("db  56h");
        _STOP_("db  8Bh");
        _STOP_("db 0F7h");
        _STOP_("db 0E8h");
        _STOP_("db  96h");
        _STOP_("db  5Fh");
        _STOP_("db  5Eh");
        _STOP_("db 0C3h");
        _STOP_("db 0A1h");
        _STOP_("db 0AAh");
        _STOP_("db  91h");
        _STOP_("db 0D0h");
        _STOP_("db  3Bh");
        _STOP_("db  44h");
        _STOP_("db  16h");
        _STOP_("db  7Dh");
        _STOP_("db 0E9h");
        _STOP_("db 0BDh");
        _STOP_("db  8Bh");
        _STOP_("db  44h");
        _STOP_("db  12h");
        _STOP_("db  10h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  28h");
        _STOP_("db  1Fh");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  2Ch");
        _STOP_("db  8Bh");
        _STOP_("db  44h");
        _STOP_("db  16h");
        _STOP_("db  2Bh");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  89h");
        _STOP_("db  44h");
        _STOP_("db  2Ah");
        _STOP_("db  17h");
        _STOP_("db  44h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  44h");
        _STOP_("db  1Ah");
        _STOP_("db  75h");
        _STOP_("db  14h");
        _STOP_("db  2Eh");
        _STOP_("db 0A0h");
        _STOP_("db  80h");
        _STOP_("db  95h");
        _STOP_("db  44h");
        _STOP_("db  48h");
        _STOP_("db  73h");
        _STOP_("db  4Ch");
        _STOP_("db 0E8h");
        _STOP_("db  81h");
        _STOP_("db  97h");
        _STOP_("db  24h");
        _STOP_("db  3Fh");
        _STOP_("db  88h");
        _STOP_("db  44h");
        _STOP_("db  48h");
        _STOP_("db 0B8h");
        _STOP_("db  25h");
        _STOP_("db 0FEh");
        _STOP_("db 0FFh");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db  8Bh");
        _STOP_("db 0D8h");
        _STOP_("db  8Bh");
        _STOP_("db  7Ch");
        _STOP_("db  38h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  87h");
        _STOP_("db  2Fh");
        _STOP_("db 0AFh");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  87h");
        _STOP_("db  31h");
        _STOP_("db 0AFh");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  87h");
        _STOP_("db  33h");
        _STOP_("db 0AFh");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Ah");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  87h");
        _STOP_("db  35h");
        _STOP_("db 0AFh");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  2Ch");
        _STOP_("db 0FFh");
        _STOP_("db  44h");
        _STOP_("db  1Ah");
        _STOP_("db  83h");
        _STOP_("db  7Ch");
        _STOP_("db  1Ah");
        _STOP_("db  0Ah");
        _STOP_("db  74h");
        _STOP_("db  83h");
        _STOP_("db  7Ch");
        _STOP_("db  1Ah");
        _STOP_("db  74h");
        _STOP_("db 0C3h");
        _STOP_("db 0C7h");
        _STOP_("db  44h");
        _STOP_("db  1Ah");
        _STOP_("db 0C3h");
        _STOP_("db 0B9h");
        _STOP_("db 0BFh");
        _STOP_("db  1Fh");
        _STOP_("db 0AFh");
        _STOP_("db  8Bh");
        _STOP_("db  44h");
        _STOP_("db  12h");
        _STOP_("db  8Bh");
        _STOP_("db  5Ch");
        _STOP_("db  16h");
        _STOP_("db  20h");
        _STOP_("db  2Bh");
        _STOP_("db  1Eh");
        _STOP_("db  90h");
        _STOP_("db  91h");
        _STOP_("db  83h");
        _STOP_("db 0C3h");
        _STOP_("db  18h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  2Dh");
        _STOP_("db  83h");
        _STOP_("db 0C7h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  16h");
        _STOP_("db  82h");
        _STOP_("db  95h");
        _STOP_("db  57h");
        _STOP_("db 0E8h");
        _STOP_("db  54h");
        _STOP_("db  74h");
        _STOP_("db  50h");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  46h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  0Ch");
        _STOP_("db  2Eh");
        _STOP_("db  8Bh");
        _STOP_("db  46h");
        _STOP_("db  89h");
        _STOP_("db  45h");
        _STOP_("db  0Eh");
        _STOP_("db  58h");
        _STOP_("db  83h");
        _STOP_("db 0C5h");
        _STOP_("db  89h");
        _STOP_("db  6Dh");
        _STOP_("db  10h");
        _STOP_("db  5Fh");
        _STOP_("db  49h");
        _STOP_("db  79h");
        _STOP_("db 0D7h");
        _STOP_("db 0C3h");
        _STOP_("db 0E8h");
        _STOP_("db  23h");
        _STOP_("db  5Dh");
        _STOP_("db 0C3h");
        _STOP_("db  29h");
        _STOP_("db  45h");
        _STOP_("db  24h");
        _STOP_("db  76h");
        _STOP_("db 0C7h");
        _STOP_("db  45h");
        _STOP_("db 0FFh");
        _STOP_("db 0AAh");
        _STOP_("db 0C3h");
        _STOP_("db 0BAh");
        _STOP_("db  53h");
        _STOP_("db  8Bh");
        _STOP_("db  45h");
        _STOP_("db  12h");
        _STOP_("db  20h");
        _STOP_("db  8Bh");
        _STOP_("db  5Dh");
        _STOP_("db  16h");
        _STOP_("db  2Bh");
        _STOP_("db  1Eh");
        _STOP_("db 90h, 91h, 83h, 0C3h, 10h, 0BDh, 4Ch, 12...");
        _STOP_("db 88h, 8Bh, 5Dh, 38h, 0C7h, 7, 2 dup(0), ...");
        _STOP_("db 2 dup(0), 0C7h, 47h, 4, 2 dup(0), 0C7h,...");
        _STOP_("db 0C7h, 47h, 28h, 2 dup(0), 0C7h, 47h, 2A...");
        _STOP_("db 0C7h, 47h, 2Ch, 2 dup(0), 0C7h, 47h, 2E...");
        _STOP_("db 81h, 6, 52h, 91h, 0F4h, 1, 83h, 16h, 54...");
        _STOP_("db 8Bh, 0F7h, 0E8h, 0C3h, 5Ch, 5Eh, 0C3h, ...");
        _STOP_("db 61h, 7, 0B8h, 2, 0, 0BBh, 2, 0, 8Bh, 54...");
        _STOP_("db 16h, 90h, 91h, 8Bh, 4Ch, 12h, 83h, 0C1h...");
        _STOP_("db 0E9h, 83h, 0E1h, 0FCh, 56h, 0BEh, 2Fh, ...");
        _STOP_("db 2 dup(5Eh), 0C3h, 0A1h, 0AAh, 91h, 5, 0...");
        _STOP_("db 44h, 16h, 7Dh, 3, 0E9h, 95h, 0, 8Bh, 44...");
        _STOP_("db 0, 89h, 44h, 28h, 5, 0Ch, 0, 89h, 44h, ...");
        _STOP_("db 16h, 2Bh, 6, 90h, 91h, 5, 2, 0, 89h, 44...");
        _STOP_("db 0, 89h, 44h, 2Eh, 8Bh, 44h, 1Ah, 85h, 0...");
        _STOP_("db 2Eh, 0A0h, 84h, 95h, 0, 44h, 48h, 73h, ...");
        _STOP_("db 96h, 24h, 3Fh, 88h, 44h, 48h, 0C7h, 44h...");
        _STOP_("db 0C3h, 25h, 0FEh, 0FFh, 0BBh, 57h, 0AFh,...");
        _STOP_("db 0, 74h, 3, 0BBh, 65h, 0AFh, 8Bh, 7Ch, 3...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 5, 0FFh, 44h, 1Ah, 83...");
        _STOP_("db 8, 74h, 0Ch, 83h, 7Ch, 1Ah, 0Eh, 75h, 5...");
        _STOP_("db 1Ah, 2 dup(0), 0C3h, 8Bh, 44h, 12h, 8Bh...");
        _STOP_("db 8, 0, 2Bh, 1Eh, 90h, 91h, 0BDh, 0B7h, 7...");
        _STOP_("db 81h, 3Ch, 0F0h, 0, 74h, 6, 0B9h, 4, 0, ...");
        _STOP_("db 2Eh, 8Bh, 16h, 86h, 95h, 0E9h, 0Bh, 73h...");
        _STOP_("db 5Bh, 0C3h, 0D1h, 0E3h, 2Eh, 0FFh, 0A7h,...");
        _STOP_("db 9Ah, 95h, 0E9h, 0B0h, 87h, 0BBh, 0ACh, ...");
        _STOP_("db 87h, 0FFh, 36h, 78h, 8Eh, 2Eh, 0A1h, 98...");
        _STOP_("db 78h, 8Eh, 0BBh, 0BEh, 95h, 0E8h, 99h, 8...");
        _STOP_("db 8Eh, 0C3h, 0BBh, 30h, 96h, 0E9h, 8Eh, 8...");
        _STOP_("db 96h, 0E9h, 88h, 87h, 56h, 80h, 3Eh, 33h...");
        _STOP_("db 9, 80h, 3Eh, 34h, 92h, 0, 75h, 2, 5Eh, ...");
        _STOP_("db 0AFh, 2Eh, 83h, 3Ch, 0, 74h, 0F5h, 2Eh,...");
        _STOP_("db 8Bh, 44h, 2, 40h, 2Eh, 8Bh, 5Ch, 4, 43h...");
        _STOP_("db 6, 2Eh, 8Bh, 4Ch, 8, 83h, 0C6h, 0Ah, 2B...");
        _STOP_("db 91h, 81h, 0FAh, 0C0h, 0, 7Dh, 0D8h, 83h...");
        _STOP_("db 7Eh, 0D3h, 56h, 8Bh, 0F7h, 0E8h, 0F9h, ...");
        _STOP_("db 0CAh, 33h, 0C0h, 0C3h, 0C7h, 6, 0A8h, 9...");
        _STOP_("db 0C7h, 6, 0AAh, 91h, 0FFh, 11h, 0C7h, 6,...");
        _STOP_("db 13h, 0C7h, 6, 0AEh, 8Eh, 0D0h, 7, 0E8h,...");
        _STOP_("db 0E2h, 90h, 0E8h, 1Fh, 5Bh, 0C7h, 4, 50h...");
        _STOP_("db 2, 61h, 7, 0C7h, 44h, 4, 1, 0ACh, 0C6h,...");
        _STOP_("db 0C7h, 6, 0F4h, 91h, 96h, 0E4h, 0C7h, 6,...");
        _STOP_("db 52h, 0C6h, 6, 31h, 92h, 0, 0C6h, 6, 32h...");
        _STOP_("db 0C6h, 6, 33h, 92h, 0, 0C6h, 6, 34h, 92h...");
        _STOP_("db 8, 92h, 2 dup(0), 2Eh, 0A1h, 88h, 95h, ...");
        _STOP_("db 2Eh, 0A1h, 88h, 95h, 0A3h, 0Ch, 92h, 0C...");
        _STOP_("db 0, 0C7h, 6, 0Eh, 92h, 2, 0, 2Eh, 0A1h, 8Ah");
        _STOP_("db  92h");
        _STOP_("db  2Eh");
        _STOP_("db 0A1h");
        _STOP_("db  8Ah");
        _STOP_("db  95h");
        _STOP_("db 0A3h");
        _STOP_("db  92h");
        _STOP_("db 0A1h");
        _STOP_("db  1Ah");
        _STOP_("db  99h");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db 0A3h");
        _STOP_("db  76h");
        _STOP_("db  8Eh");
        _STOP_("db 0A1h");
        _STOP_("db  1Ah");
        _STOP_("db  99h");
        _STOP_("db  8Bh");
        _STOP_("db 0D8h");
        _STOP_("db 0D1h");
        _STOP_("db 0E0h");
        _STOP_("db 0C3h");
        _STOP_("db 0A3h");
        _STOP_("db  78h");
        _STOP_("db  8Eh");
        _STOP_("db 0C7h");
        _STOP_("db  72h");
        _STOP_("db  8Eh");
        _STOP_("db  8Dh");
        _STOP_("db  55h");
        _STOP_("db 0C3h");
        _STOP_("db  1Fh");
        _STOP_("db  78h");
        _STOP_("db 0CFh");
        _STOP_("db  78h");
        _STOP_("db 0FFh");
        _STOP_("db  73h");
        _STOP_("db 0AFh");
        _STOP_("db  74h");
        _STOP_("db  5Fh");
        _STOP_("db  75h");
        _STOP_("db  0Fh");
        _STOP_("db  76h");
        _STOP_("db 0BFh");
        _STOP_("db  76h");
        _STOP_("db  6Fh");
        _STOP_("db  77h");
        _STOP_("db 0AFh");
        _STOP_("db  6Dh");
        _STOP_("db 0FFh");
        _STOP_("db  6Ch");
        _STOP_("db  4Fh");
        _STOP_("db  6Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db 0AFh");
        _STOP_("db  6Dh");
        _STOP_("db 0FFh");
        _STOP_("db  6Ch");
        _STOP_("db  4Fh");
        _STOP_("db  6Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  57h");
        _STOP_("db  72h");
        _STOP_("db  73h");
        _STOP_("db  5Fh");
        _STOP_("db  6Eh");
        _STOP_("db 0FBh");
        _STOP_("db  6Eh");
        _STOP_("db 0ABh");
        _STOP_("db  6Fh");
        _STOP_("db  5Bh");
        _STOP_("db  70h");
        _STOP_("db  0Bh");
        _STOP_("db  71h");
        _STOP_("db 0A7h");
        _STOP_("db  71h");
        _STOP_("db 0C6h");
        _STOP_("db  96h");
        _STOP_("db 0DCh");
        _STOP_("db  96h");
        _STOP_("db 0F2h");
        _STOP_("db  96h");
        _STOP_("db  97h");
        _STOP_("db  0Ah");
        _STOP_("db  1Ch");
        _STOP_("db  4Fh");
        _STOP_("db  9Ch");
        _STOP_("db 0A1h");
        _STOP_("db  1Ch");
        _STOP_("db 0D6h");
        _STOP_("db  9Ch");
        _STOP_("db  5Dh");
        _STOP_("db 0C8h");
        _STOP_("db  15h");
        _STOP_("db 0D6h");
        _STOP_("db  9Ch");
        _STOP_("db  5Dh");
        _STOP_("db 0C8h");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db 0FBh");
        _STOP_("db  9Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  0Eh");
        _STOP_("db  20h");
        _STOP_("db  9Dh");
        _STOP_("db  5Fh");
        _STOP_("db  6Eh");
        _STOP_("db  34h");
        _STOP_("db  97h");
        _STOP_("db  64h");
        _STOP_("db  97h");
        _STOP_("db  82h");
        _STOP_("db  97h");
        _STOP_("db  7Eh");
        _STOP_("db  97h");
        _STOP_("db  68h");
        _STOP_("db  97h");
        _STOP_("db  98h");
        _STOP_("db  97h");
        _STOP_("db  4Eh");
        _STOP_("db  97h");
        _STOP_("db  4Ah");
        _STOP_("db  97h");
        _STOP_("db  11h");
        _STOP_("db 0D2h");
        _STOP_("db  29h");
        _STOP_("db 0D4h");
        _STOP_("db 0B9h");
        _STOP_("db 0D6h");
        _STOP_("db  49h");
        _STOP_("db 0D9h");
        _STOP_("db  5Dh");
        _STOP_("db 0C8h");
        _STOP_("db  75h");
        _STOP_("db 0CAh");
        _STOP_("db 0CDh");
        _STOP_("db  95h");
        _STOP_("db 0CFh");
        _STOP_("db 0AFh");
        _STOP_("db  6Dh");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  4Fh");
        _STOP_("db  6Ch");
        _STOP_("db 0FFh");
        _STOP_("db  6Ch");
        _STOP_("db 0AFh");
        _STOP_("db  6Dh");
        _STOP_("db  9Fh");
        _STOP_("db  6Bh");
        _STOP_("db  4Fh");
        _STOP_("db  6Ch");
        _STOP_("db 0FFh");
        _STOP_("db  6Ch");
        _STOP_("db  57h");
        _STOP_("db  72h");
        _STOP_("db  73h");
        _STOP_("db  5Fh");
        _STOP_("db  6Eh");
        _STOP_("db 0FBh");
        _STOP_("db  6Eh");
        _STOP_("db 0ABh");
        _STOP_("db  6Fh");
        _STOP_("db  5Bh");
        _STOP_("db  70h");
        _STOP_("db  0Bh");
        _STOP_("db  71h");
        _STOP_("db 0A7h");
        _STOP_("db  71h");
        _STOP_("db 0CEh");
        _STOP_("db  35h");
        _STOP_("db 0D2h");
        _STOP_("db 0A1h");
        _STOP_("db  3Fh");
        _STOP_("db 0A3h");
        _STOP_("db 0E5h");
        _STOP_("db 0A0h");
        _STOP_("db  0Fh");
        _STOP_("db 0A4h");
        _STOP_("db 0BFh");
        _STOP_("db 0A3h");
        _STOP_("db 0B3h");
        _STOP_("db  9Dh");
        _STOP_("db  9Ch");
        _STOP_("db  97h");
        _STOP_("db 0B2h");
        _STOP_("db  97h");
        _STOP_("db 0C8h");
        _STOP_("db  97h");
        _STOP_("db 0DEh");
        _STOP_("db  97h");
        _STOP_("db 0F4h");
        _STOP_("db  97h");
        _STOP_("db  0Ah");
        _STOP_("db  98h");
        _STOP_("db  20h");
        _STOP_("db  98h");
        _STOP_("db  36h");
        _STOP_("db  98h");
        _STOP_("db  32h");
        _STOP_("db  9Eh");
        _STOP_("db  61h");
        _STOP_("db  5Ah");
        _STOP_("db  98h");
        _STOP_("db  89h");
        _STOP_("db  9Eh");
        _STOP_("db  61h");
        _STOP_("db  4Ch");
        _STOP_("db  98h");
        _STOP_("db 0E0h");
        _STOP_("db 0FFh");
        _STOP_("db  89h");
        _STOP_("db  9Eh");
        _STOP_("db  61h");
        _STOP_("db  5Eh");
        _STOP_("db  98h");
        _STOP_("db  20h");
        _STOP_("db 0A4h");
        _STOP_("db  9Eh");
        _STOP_("db  1Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Ch");
        _STOP_("db  98h");
        _STOP_("db  38h");
        _STOP_("db 0A4h");
        _STOP_("db  9Eh");
        _STOP_("db  1Ch");
        _STOP_("db  9Fh");
        _STOP_("db  6Ch");
        _STOP_("db  98h");
        _STOP_("db  19h");
        _STOP_("db  38h");
        _STOP_("db  7Fh");
        _STOP_("db  9Fh");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db 0F6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db 0E6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db 0E6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db 0E6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db 0E6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  90h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Eh");
        _STOP_("db  98h");
        _STOP_("db 0E6h");
        _STOP_("db 0FFh");
        _STOP_("db  33h");
        _STOP_("db  7Fh");
        _STOP_("db  9Fh");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db  2Ah");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db  1Ah");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db  1Ah");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db  1Ah");
        _STOP_("db  33h");
        _STOP_("db  27h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Ah");
        _STOP_("db  98h");
        _STOP_("db  1Ah");
        _STOP_("db  33h");
        _STOP_("db  90h");
        _STOP_("db 0A0h");
        _STOP_("db  61h");
        _STOP_("db  8Eh");
        _STOP_("db  98h");
        _STOP_("db  1Ah");
        _STOP_("db  33h");
        _STOP_("db  89h");
        _STOP_("db  23h");
        _STOP_("db 0B5h");
        _STOP_("db  25h");
        _STOP_("db 0A5h");
        _STOP_("db  27h");
        _STOP_("db 0D1h");
        _STOP_("db  29h");
        _STOP_("db 0E9h");
        _STOP_("db  2Bh");
        _STOP_("db  15h");
        _STOP_("db  2Eh");
        _STOP_("db 0D9h");
        _STOP_("db  2Fh");
        _STOP_("db  32h");
        _STOP_("db  41h");
        _STOP_("db  12h");
        _STOP_("db  6Dh");
        _STOP_("db  14h");
        _STOP_("db  5Dh");
        _STOP_("db  16h");
        _STOP_("db  89h");
        _STOP_("db  18h");
        _STOP_("db 0A1h");
        _STOP_("db  1Ah");
        _STOP_("db 0CDh");
        _STOP_("db  1Ch");
        _STOP_("db  91h");
        _STOP_("db  1Eh");
        _STOP_("db  0Dh");
        _STOP_("db  21h");
        _STOP_("db  81h");
        _STOP_("db  2Ah");
        _STOP_("db 0C1h");
        _STOP_("db  34h");
        _STOP_("db  35h");
        _STOP_("db 0C1h");
        _STOP_("db  2Ah");
        _STOP_("db  41h");
        _STOP_("db  2Eh");
        _STOP_("db  41h");
        _STOP_("db  35h");
        _STOP_("db  81h");
        _STOP_("db  35h");
        _STOP_("db  81h");
        _STOP_("db  2Eh");
        _STOP_("db  41h");
        _STOP_("db  24h");
        _STOP_("db  81h");
        _STOP_("db  24h");
        _STOP_("db 0C1h");
        _STOP_("db  24h");
        _STOP_("db  25h");
        _STOP_("db  41h");
        _STOP_("db  27h");
        _STOP_("db  80h");
        _STOP_("db  27h");
        _STOP_("db 0C0h");
        _STOP_("db  27h");
        _STOP_("db  28h");
        _STOP_("db  41h");
        _STOP_("db  2Ah");
        _STOP_("db 0C1h");
        _STOP_("db  2Fh");
        _STOP_("db  30h");
        _STOP_("db  2Bh");
        _STOP_("db 0C1h");
        _STOP_("db  31h");
        _STOP_("db  32h");
        _STOP_("db 0C1h");
        _STOP_("db  2Fh");
        _STOP_("db  30h");
        _STOP_("db 0C1h");
        _STOP_("db  31h");
        _STOP_("db  32h");
        _STOP_("db  41h");
        _STOP_("db  30h");
        _STOP_("db  81h");
        _STOP_("db  30h");
        _STOP_("db  41h");
        _STOP_("db  32h");
        _STOP_("db 81h, 32h, 0C1h, 30h, 1, 31h, 0C1h, 32h,...");
        _STOP_("db 31h, 81h, 31h, 41h, 33h, 81h, 33h, 0C1h...");
        _STOP_("db 0C1h, 32h, 1, 33h, 0C1h, 33h, 1, 34h, 4...");
        _STOP_("db 34h, 0C1h, 30h, 1, 31h, 0C1h, 32h, 1, 3...");
        _STOP_("db 81h, 30h, 41h, 32h, 81h, 32h, 0C1h, 2Fh...");
        _STOP_("db 31h, 1, 32h, 41h, 24h, 81h, 24h, 0C1h, ...");
        _STOP_("db 41h, 27h, 80h, 27h, 0C0h, 27h, 1, 28h, ...");
        _STOP_("db 1, 2Bh, 0E4h, 99h, 0CEh, 99h, 0B8h, 99h...");
        _STOP_("db 8Ch, 99h, 76h, 99h, 60h, 99h, 4Ah, 99h,...");
        _STOP_("db 35h, 41h, 35h, 81h, 35h, 0C1h, 35h, 1, ...");
        _STOP_("db 1, 37h, 41h, 36h, 81h, 36h, 41h, 37h, 8...");
        _STOP_("db 35h, 1, 36h, 0C1h, 36h, 1, 37h, 0C1h, 3...");
        _STOP_("db 35h, 81h, 35h, 0C1h, 37h, 1, 38h, 41h, ...");
        _STOP_("db 41h, 38h, 1, 38h, 0C1h, 37h, 0C1h, 38h,...");
        _STOP_("db 39h, 81h, 39h, 41h, 39h, 1, 39h, 0C1h, ...");
        _STOP_("db 1, 3Ah, 60h, 33h, 0D3h, 0ABh, 0D9h, 0AB...");
        _STOP_("db 0F5h, 0ABh, 0FBh, 0ABh, 0B7h, 0AFh, 2 d...");
        _STOP_("db 10h, 1, 2 dup(0), 0B7h, 0AFh, 2 dup(0),...");
        _STOP_("db 0C3h, 0AFh, 1, 5 dup(0), 48h, 0, 0BDh, ...");
        _STOP_("db 2, 0, 60h, 0, 98h, 0, 0BDh, 0AFh, 2 dup...");
        _STOP_("db 1, 98h, 3 dup(0), 81h, 17h, 1, 1Bh, 81h...");
        _STOP_("db 0C1h, 1Ah, 41h, 1Eh, 0C1h, 21h, 1, 22h,...");
        _STOP_("db 55h, 0DFh, 7Ah, 36h, 68h, 5Ah, 68h, 0Fh...");
        _STOP_("db 4, 0, 40h, 0, 2, 0, 5, 0, 1, 0, 8, 0, 4...");
        _STOP_("db 6, 0, 6, 0, 7, 0, 4, 0, 7, 0, 2, 0, 0Ah...");
        _STOP_("db 6, 0, 10h, 0, 10h, 0, 1, 0, 6, 0, 32h, ...");
        _STOP_("db 0, 6, 0, 14h, 0, 14h, 0, 0AFh, 0, 6, 0,...");
        _STOP_("db 1, 0, 20h, 0, 8, 0, 2, 0, 0E8h, 0, 90h,...");
        _STOP_("db 53h, 8, 39h, 3Ah, 0F0h, 0B0h, 8, 0, 2 d...");
        _STOP_("db 3 dup(0), 0CAh, 37h, 53h, 8, 39h, 3Ah, ...");
        _STOP_("db 0, 2 dup(0FFh), 2 dup(0), 0ECh, 0, 0FAh...");
        _STOP_("db 53h, 8, 0A7h, 3Ah, 24h, 0B1h, 4, 5 dup(...");
        _STOP_("db 0C8h, 0, 0Bh, 48h, 53h, 8, 0A7h, 3Ah, 3...");
        _STOP_("db 6 dup(0), 1, 2Ch, 1, 0Bh, 48h, 53h, 8, ...");
        _STOP_("db 0B1h, 4, 5 dup(0), 4, 1, 64h, 0, 0Bh, 4...");
        _STOP_("db 3Ah, 0CAh, 0B0h, 4, 5 dup(0), 8, 1, 96h...");
        _STOP_("db 53h, 8, 0A7h, 3Ah, 0A4h, 0B0h, 4, 5 dup...");
        _STOP_("db 2, 0, 1, 9Fh, 2, 0, 0B1h, 9Fh, 2, 0, 61...");
        _STOP_("db 11h, 0A1h, 2, 0, 0C1h, 0A1h, 2, 0, 71h,...");
        _STOP_("db 21h, 0A3h, 2, 3 dup(0), 0E2h, 41h, 0A4h...");
        _STOP_("db 99h, 1, 0, 0D1h, 99h, 1, 0, 81h, 9Ah, 1...");
        _STOP_("db 1, 0, 0E1h, 9Bh, 1, 0, 41h, 9Ch, 1, 0, ...");
        _STOP_("db 0, 0A1h, 9Dh, 1, 3 dup(0), 0E2h, 41h, 0...");
        _STOP_("db 82h, 3, 0, 9Dh, 83h, 3, 0, 9Dh, 84h, 3,...");
        _STOP_("db 3, 0, 9Dh, 86h, 3, 3 dup(0), 0E2h, 41h,...");
        _STOP_("db 9Dh, 87h");
        _STOP_("db 3, 0, 8Fh, 88h, 3, 0, 81h, 89h, 3, 0, 7...");
        _STOP_("db 65h, 8Bh, 3, 3 dup(0), 0E2h, 41h, 0Ah, ...");
        _STOP_("db 2, 0, 0B5h, 8Dh, 2, 0, 5, 8Fh, 2, 0, 55...");
        _STOP_("db 0A5h, 91h, 2, 3 dup(0), 0E2h, 41h, 24h,...");
        _STOP_("db 2, 0, 29h, 7Eh, 2, 0, 0CFh, 7Eh, 2, 0, ...");
        _STOP_("db 0, 25h, 80h, 2, 0, 0CBh, 80h, 2, 3 dup(...");
        _STOP_("db 3Eh, 0B1h, 0F5h, 92h, 2, 0, 1Dh, 94h, 2...");
        _STOP_("db 2, 0, 0A9h, 96h, 2, 0, 0F9h, 97h, 2, 3 ...");
        _STOP_("db 41h, 5Ch, 0B1h, 29h, 0, 2, 0, 91h, 2 du...");
        _STOP_("db 4, 2, 0, 9Fh, 6, 2, 0, 0F3h, 8, 2, 0, 0...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 76h, 0B1h, 0FBh, 0...");
        _STOP_("db 0Fh, 2, 0, 9, 11h, 2, 0, 71h, 13h, 2, 0...");
        _STOP_("db 2, 0, 79h, 17h, 2, 3 dup(0), 0E2h, 41h,...");
        _STOP_("db 21h, 3, 0, 9, 24h, 3, 0, 49h, 26h, 3, 0...");
        _STOP_("db 0, 5, 2Bh, 3, 0, 31h, 2Dh, 3, 3 dup(0),...");
        _STOP_("db 0B1h, 71h, 2Fh, 3, 0, 0D9h, 31h, 3, 0, ...");
        _STOP_("db 0, 6Dh, 36h, 3, 0, 0D5h, 38h, 3, 0, 1, ...");
        _STOP_("db 0E2h, 41h, 0D0h, 0B1h, 0D9h, 75h, 0Ah, ...");
        _STOP_("db 2, 0, 39h, 77h, 2, 0, 0E9h, 77h, 2, 0, ...");
        _STOP_("db 0, 49h, 79h, 1, 0, 0A9h, 79h, 2, 0, 59h...");
        _STOP_("db 9, 7Bh, 2, 0, 0B9h, 7Bh, 2, 0, 0D9h, 75...");
        _STOP_("db 75h, 2 dup(0), 49h, 6Fh, 0Ah, 0, 0F9h, ...");
        _STOP_("db 70h, 2, 0, 59h, 71h, 2, 0, 9, 72h, 2, 0...");
        _STOP_("db 1, 0, 19h, 73h, 2, 0, 0C9h, 73h, 2, 0, ...");
        _STOP_("db 0, 29h, 75h, 2, 0, 49h, 6Fh, 1, 0, 49h,...");
        _STOP_("db 81h, 5Eh, 1, 0, 1Dh, 5Fh, 1, 0, 0B9h, 5...");
        _STOP_("db 60h, 1, 0, 0B9h, 5Fh, 1, 0, 1Dh, 5Fh, 1...");
        _STOP_("db 41h, 4Eh, 0B2h, 65h, 60h, 1, 0, 0E3h, 6...");
        _STOP_("db 1, 0, 0DFh, 61h, 1, 0, 2 dup(61h), 1, 0...");
        _STOP_("db 1, 3 dup(0), 0E2h, 41h, 6Ch, 0B2h, 5Dh,...");
        _STOP_("db 62h, 1, 0, 59h, 63h, 1, 0, 0A5h, 63h, 1...");
        _STOP_("db 1, 0, 0EFh, 62h, 1, 3 dup(0), 0E2h, 41h...");
        _STOP_("db 5, 64h, 1, 0, 0B5h, 64h, 1, 0, 5Bh, 65h...");
        _STOP_("db 65h, 1, 0, 5Bh, 65h, 1, 0, 0B5h, 64h, 1...");
        _STOP_("db 41h, 0A8h, 0B2h, 57h, 66h, 1, 0, 0F3h, ...");
        _STOP_("db 67h, 1, 0, 0E5h, 67h, 1, 0, 8Fh, 67h, 1...");
        _STOP_("db 1, 3 dup(0), 0E2h, 41h, 0C6h, 0B2h, 3Bh...");
        _STOP_("db 0EBh, 68h, 1, 0, 91h, 69h, 1, 0, 0Fh, 6...");
        _STOP_("db 69h, 1, 0, 0EBh, 68h, 1, 3 dup(0), 0E2h...");
        _STOP_("db 0B2h, 0E1h, 5Ah, 1, 0, 73h, 5Bh, 1, 0, ...");
        _STOP_("db 0, 29h, 5Ch, 1, 0, 0DDh, 5Bh, 1, 0, 73h...");
        _STOP_("db 0E2h, 41h, 2, 0B3h, 89h, 5Ch, 1, 0, 7, ...");
        _STOP_("db 5Dh, 1, 0, 3, 5Eh, 1, 0");
        _STOP_("db 85h, 5Dh, 1, 0, 7, 5Dh, 1, 3 dup(0), 0E...");
        _STOP_("db 0B3h, 0F9h, 0CCh, 1, 0, 6Dh, 0CDh, 1, 3...");
        _STOP_("db 41h, 3Eh, 0B3h, 81h, 0C8h, 1, 0, 71h, 0...");
        _STOP_("db 0E2h, 41h, 4Ch, 0B3h, 0ADh, 0CBh, 1, 0,...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 5Ah, 0B3h, 0B9h, 0...");
        _STOP_("db 0CEh, 1, 3 dup(0), 0E2h, 41h, 68h, 0B3h...");
        _STOP_("db 1, 0, 6Dh, 0CDh, 1, 3 dup(0), 0E2h, 41h...");
        _STOP_("db 0CDh, 19h, 2 dup(0), 0D1h, 0A3h, 2 dup(...");
        _STOP_("db 2 dup(0), 8Dh, 6Ah, 2 dup(0), 29h, 6Bh,...");
        _STOP_("db 6Bh, 1, 0, 89h, 6Ch, 1, 0, 39h, 6Dh, 1,...");
        _STOP_("db 1, 0, 99h, 6Eh, 1, 0, 0E9h, 6Dh, 1, 0, ...");
        _STOP_("db 0, 89h, 6Ch, 1, 0, 0D9h, 6Bh, 1, 3 dup(...");
        _STOP_("db 94h, 0B3h, 0B5h, 0E9h, 4, 0, 69h, 0EBh,...");
        _STOP_("db 0E2h, 41h, 0C2h, 0B3h, 1Dh, 0EDh, 4, 0,...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 0D0h, 0B3h, 0E5h, ...");
        _STOP_("db 0D2h, 4, 3 dup(0), 0E2h, 41h, 0DEh, 0B3...");
        _STOP_("db 4, 0, 0FBh, 0D6h, 4, 3 dup(0), 0E2h, 41...");
        _STOP_("db 63h, 0D9h, 4, 0, 17h, 0DBh, 4, 3 dup(0)...");
        _STOP_("db 0FAh, 0B3h, 0CBh, 0DCh, 4, 0, 0Bh, 0DFh...");
        _STOP_("db 0E2h, 41h, 8, 0B4h, 5Fh, 0E1h, 4, 0, 31...");
        _STOP_("db 0E2h, 41h, 16h, 0B4h, 21h, 0E5h, 4, 0, ...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 24h, 0B4h, 0B1h, 0...");
        _STOP_("db 0F2h, 1, 0, 11h, 0F3h, 1, 0, 0C1h, 0F3h...");
        _STOP_("db 0E2h, 41h, 32h, 0B4h, 69h, 0C0h, 2, 0, ...");
        _STOP_("db 0, 0BFh, 0C1h, 2, 0, 19h, 0C1h, 2, 3 du...");
        _STOP_("db 48h, 0B4h, 51h, 0C2h, 2, 0, 1, 0C3h, 2,...");
        _STOP_("db 2, 0, 1, 0C3h, 2, 3 dup(0), 0E2h, 41h, ...");
        _STOP_("db 0C4h, 2, 0, 11h, 0C5h, 2, 0, 0C1h, 0C5h...");
        _STOP_("db 0C5h, 2, 3 dup(0), 0E2h, 41h, 74h, 0B4h...");
        _STOP_("db 2, 0, 21h, 0C7h, 2, 0, 0D1h, 0C7h, 2, 0...");
        _STOP_("db 2, 3 dup(0), 0E2h, 41h, 8Ah, 0B4h, 51h,...");
        _STOP_("db 1, 0B9h, 2, 0, 0A7h, 0B9h, 2, 0, 1, 0B9...");
        _STOP_("db 0E2h, 41h, 0A0h, 0B4h, 39h, 0BAh, 2, 0,...");
        _STOP_("db 2, 0, 99h, 0BBh, 2, 0, 0E9h, 0BAh, 2, 3...");
        _STOP_("db 41h, 0B6h, 0B4h, 49h, 0BCh, 2, 0, 0F9h,...");
        _STOP_("db 0A9h, 0BDh, 2, 0, 0F9h, 0BCh, 2, 3 dup(...");
        _STOP_("db 0CCh, 0B4h, 59h, 0BEh, 2, 0, 9, 0BFh, 2...");
        _STOP_("db 2, 0, 9, 0BFh, 2, 3 dup(0), 0E2h, 41h, ...");
        _STOP_("db 52h, 2, 0, 0D1h, 53h, 2, 0, 61h, 56h, 2...");
        _STOP_("db 2, 3 dup(0), 0E2h, 41h, 0F8h, 0B4h, 0A9...");
        _STOP_("db 0C1h, 4Bh, 2, 0, 29h, 4Eh, 2, 0, 0B9h, ...");
        _STOP_("db 0E2h, 41h, 0Eh, 0B5h, 41h, 3Dh, 2 dup(0...");
        _STOP_("db 4, 0, 0F5h, 3Eh, 8, 0, 0E5h, 40h, 2 dup...");
        _STOP_("db 4, 0, 41h, 3Dh, 2 dup(0), 75h, 43h, 2 d...");
        _STOP_("db 4, 0, 29h, 45h, 8, 0, 19h, 47h, 2 dup(0...");
        _STOP_("db 4, 0, 75h, 43h, 2 dup(0), 0C3h, 81h, 3E...");
        _STOP_("db 0F0h, 0Dh, 7Ch, 0Eh, 81h, 3Eh, 90h, 91h...");
        _STOP_("db 7Fh, 6, 0C7h, 6, 0AAh, 91h, 0F0h, 0Dh, ...");
        _STOP_("db 25h, 0Fh, 0, 74h, 3, 0E9h, 9Ch, 0, 81h,...");
        _STOP_("db 50h, 0Eh, 7Eh, 3, 0E9h, 91h, 0, 81h, 3E...");
        _STOP_("db 0E0h, 0Ah, 7Dh, 3, 0E9h, 86h, 0, 0E8h, ...");
        _STOP_("db 4Ah, 90h, 0E8h, 0E7h, 51h, 0E8h, 0F9h, ...");
        _STOP_("db 0, 74h, 3, 0B8h, 8, 0, 0F7h, 6, 9Ch, 91...");
        _STOP_("db 3, 5, 10h, 0, 0BBh, 2Ah, 0C8h, 3, 0D8h,...");
        _STOP_("db 89h, 4, 83h, 0C3h, 2, 2Eh, 8Bh, 7, 89h,...");
        _STOP_("db 0C3h, 2, 2Eh, 8Bh, 7, 89h, 44h, 2, 83h,...");
        _STOP_("db 44h, 6, 0A7h, 3Ah, 0C7h, 44h, 4, 53h, 8...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 44h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C3h, 4, 89h, 5Ch, 10h, 0E8h,...");
        _STOP_("db 44h, 48h, 0C7h, 44h, 16h, 0E0h, 0FFh, 0...");
        _STOP_("db 2 dup(0), 2Eh, 0A1h, 0E0h, 0AFh, 89h, 4...");
        _STOP_("db 44h, 27h, 0FFh, 0C7h, 44h, 36h, 2 dup(0...");
        _STOP_("db 34h, 2Ch, 1, 0E8h, 77h, 7Fh, 0C3h, 0E8h...");
        _STOP_("db 98h, 91h, 2Eh, 3, 6, 0E2h, 0AFh, 1, 44h...");
        _STOP_("db 16h, 0C8h, 0, 7Ch, 3, 0E9h, 0BCh, 0, 0F...");
        _STOP_("db 83h, 7Ch, 1Ah, 8, 74h, 0Dh, 83h, 7Ch, 1...");
        _STOP_("db 70h, 0C7h, 44h, 1Ah, 2 dup(0), 0EBh, 69...");
        _STOP_("db 0E4h, 0AFh, 0, 44h, 48h, 73h, 60h, 0E8h...");
        _STOP_("db 3Fh, 88h, 44h, 48h, 56h, 0E8h, 0CCh, 59...");
        _STOP_("db 90h, 0E8h, 20h, 51h, 8Bh, 0FEh, 5Eh, 0B...");
        _STOP_("db 81h, 3Ch, 0C8h, 0, 74h, 3, 0BBh, 50h, 0...");
        _STOP_("db 7, 89h, 5, 83h, 0C3h, 2, 0C7h, 45h, 2, ...");
        _STOP_("db 45h, 4, 53h, 8, 2Eh, 8Bh, 7, 89h, 45h, ...");
        _STOP_("db 2, 8Bh, 44h, 16h, 2Dh, 1Eh, 0, 89h, 45h...");
        _STOP_("db 45h, 1Ah, 2 dup(0), 2Eh, 8Bh, 1Fh, 2Eh,...");
        _STOP_("db 45h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 45h, 0...");
        _STOP_("db 4, 89h, 5Dh, 10h, 2Eh, 0A0h, 4, 0B0h, 0...");
        _STOP_("db 31h, 0E8h, 0DBh, 8Ah, 24h, 3Fh, 88h, 44...");
        _STOP_("db 44h, 12h, 8Bh, 5Ch, 16h, 5, 14h, 0, 2Eh...");
        _STOP_("db 0B0h, 0D1h, 0E5h, 2Eh, 8Bh, 0AEh, 50h, ...");
        _STOP_("db 0, 81h, 3Ch, 0C8h, 0, 74h, 3, 2Dh, 24h,...");
        _STOP_("db 16h, 24h, 0B0h, 0E8h, 0EFh, 67h, 0E9h, ...");
        _STOP_("db 0D6h, 50h, 0C3h, 0A1h, 98h, 91h, 1, 44h...");
        _STOP_("db 0BDh, 8Ah, 83h, 7Ch, 0Eh, 0, 75h, 2Ah, ...");
        _STOP_("db 0C7h, 4, 0Ch, 0, 0C7h, 44h, 2, 98h, 39h...");
        _STOP_("db 89h, 5Ch, 16h, 0BDh, 30h, 12h, 2Eh, 8Bh...");
        _STOP_("db 44h, 0Ch, 2Eh, 8Bh, 46h, 2, 89h, 44h, 0...");
        _STOP_("db 4, 89h, 6Ch, 10h, 0C3h, 81h, 7Ch, 0Ch, ...");
        _STOP_("db 19h, 81h, 7Ch, 0Ch, 49h, 79h, 74h, 3, 0...");
        _STOP_("db 0B8h, 2 dup(0), 0BBh, 0Ah, 0, 8Bh, 2Eh,...");
        _STOP_("db 83h, 0C5h, 6, 0EBh, 0Dh, 0B8h, 80h, 0, ...");
        _STOP_("db 8Bh, 2Eh, 0C4h, 0DEh, 83h, 0C5h, 6, 56h...");
        _STOP_("db 58h, 0BFh, 4Ah, 90h, 0E8h, 21h, 50h, 8B...");
        _STOP_("db 0C7h, 5, 0F8h, 0, 0C7h, 45h, 2, 0Dh, 0B...");
        _STOP_("db 4, 53h, 8, 0C7h, 45h, 6, 0A7h, 3Ah, 0C7...");
        _STOP_("db 1Eh, 2 dup(0), 89h, 45h, 1Ch, 0C7h, 45h...");
        _STOP_("db 0C7h, 45h, 3Eh, 2 dup(0), 0C7h, 45h, 40...");
        _STOP_("db 3, 5Ch, 12h, 89h, 5Dh, 12h, 8Bh, 44h, 1...");
        _STOP_("db 16h, 0C7h, 45h, 1Ah, 2 dup(0), 0C7h, 45...");
        _STOP_("db 0, 2Eh, 0A1h, 0E6h, 0AFh, 89h, 45h, 24h...");
        _STOP_("db 27h, 0, 8Bh, 16h, 0ACh, 91h, 89h, 55h, ...");
        _STOP_("db 0ACh, 91h, 0BBh, 8Ch, 8Eh, 0B9h, 8, 0, ...");
        _STOP_("db 74h, 7, 83h, 0C3h, 4, 0E2h, 0F6h, 0EBh,...");
        _STOP_("db 0C7h, 47h, 2, 1, 0, 0C7h, 45h, 28h, 0E8...");
        _STOP_("db 2Ch, 0E8h, 3, 8Bh, 5Dh, 1Ch, 0D1h, 0EBh...");
        _STOP_("db 0D1h, 0EBh, 0D1h, 0EBh, 2Eh, 8Bh, 9Fh, ...");
        _STOP_("db 8Bh, 7, 89h, 45h, 0Ch, 2Eh, 8Bh, 47h, 2...");
        _STOP_("db 83h, 0C3h, 4, 89h, 5Dh, 10h, 89h, 6Dh, ...");
        _STOP_("db 3Ah, 2Eh, 0A1h, 0E8h, 0AFh, 89h, 45h, 4...");
        _STOP_("db 48h, 2 dup(0), 0C3h, 0FFh, 74h, 1Ch, 0E...");
        _STOP_("db 81h, 3Ch, 0F8h, 0, 74h, 3Dh, 0C7h, 4, 0...");
        _STOP_("db 44h, 2, 0Dh, 0B8h, 0C7h, 44h, 6, 0A7h, ...");
        _STOP_("db 4, 53h, 8, 0E8h, 62h, 89h, 25h, 4, 0, 8...");
        _STOP_("db 0A0h, 0, 7Ch, 3, 5, 2, 0, 8Bh, 0D8h, 8B...");
        _STOP_("db 41h, 0D1h, 0E3h, 8Bh, 9Fh, 0C0h, 0DEh, ...");
        _STOP_("db 89h, 5Ch, 38h, 89h, 5Ch, 3Ah, 0C7h, 44h...");
        _STOP_("db 8Bh, 5Ch, 1Ch, 83h, 0C3h, 10h, 0D1h, 0E...");
        _STOP_("db 0D1h, 0EBh, 0D1h, 0EBh, 83h, 0E3h, 0Eh,...");
        _STOP_("db 0, 0D1h, 0E8h, 0D1h, 0E8h, 0D1h, 0E8h, ...");
        _STOP_("db 0Eh, 0, 3Bh, 0C3h, 74h, 1Eh, 2Eh, 8Bh, ...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 44h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C3h, 4, 89h, 5Ch, 10h, 0E9h,...");
        _STOP_("db 28h, 4Fh, 0C3h, 0E8h, 15h, 89h, 0A1h, 9...");
        _STOP_("db 3, 6, 0EAh, 0AFh, 1, 44h, 16h, 81h, 7Ch...");
        _STOP_("db 0, 7Dh, 3Dh, 2Eh, 0A0h, 0ECh, 0AFh, 0, ...");
        _STOP_("db 31h, 0E8h, 0D7h, 88h, 24h, 3Fh, 88h, 44...");
        _STOP_("db 44h, 12h, 8Bh, 5Ch, 16h, 5, 1Ah, 0, 83h...");
        _STOP_("db 0BDh, 69h, 82h, 0B9h, 0Ah, 0, 81h, 3Ch,...");
        _STOP_("db 9, 0B9h, 0Dh, 0, 2Dh, 34h, 0, 0BDh, 35h...");
        _STOP_("db 16h, 0EEh, 0AFh, 0E8h, 0EBh, 65h, 0E9h,...");
        _STOP_("db 0D2h, 4Eh, 0C3h, 8Bh, 0FEh, 0D1h, 0E3h,...");
        _STOP_("db 5Eh, 0C9h, 0C7h, 45h, 4, 8Bh, 0B9h, 29h...");
        _STOP_("db 2Dh, 56h, 57h, 8Bh, 36h, 54h, 90h, 0E8h...");
        _STOP_("db 9, 0, 0E8h, 0D3h, 5Ch, 0B9h, 13h, 0, 0B...");
        _STOP_("db 57h, 8Bh, 5Dh, 16h, 0BAh, 60h, 0, 0BFh,...");
        _STOP_("db 4Ch, 12h, 0E8h, 60h, 5Ch, 0C6h, 6, 61h,...");
        _STOP_("db 5Eh, 0C3h, 0C7h, 45h, 4, 0B3h, 0B9h, 29...");
        _STOP_("db 76h, 1, 0C3h, 0FFh, 0Eh, 12h, 92h, 8Bh,...");
        _STOP_("db 5Dh, 16h, 2Bh, 1Eh, 90h, 91h, 5, 10h, 0...");
        _STOP_("db 20h, 0BDh, 4Ch, 12h, 0BAh, 53h, 8, 0E8h...");
        _STOP_("db 0C7h, 45h, 1Ch, 2 dup(0FFh), 0C7h, 45h,...");
        _STOP_("db 0C7h, 45h, 6, 61h, 7, 0C3h, 0B8h, 6, 0,...");
        _STOP_("db 8Bh, 54h, 16h, 0B9h, 38h, 0, 0BFh, 66h,...");
        _STOP_("db 1Ah, 0");
        _STOP_("db 74h, 6, 0BBh, 6, 0, 0BFh, 0A2h, 0C8h, 5...");
        _STOP_("db 0E8h, 0B8h, 4Fh, 5Eh, 0C3h, 0C7h, 44h, ...");
        _STOP_("db 0B8h, 6, 0, 0BBh, 5, 0, 8Bh, 54h, 16h, ...");
        _STOP_("db 0BFh, 66h, 0C8h, 83h, 7Ch, 1Ah, 0, 74h,...");
        _STOP_("db 0, 0BFh, 0A2h, 0C8h, 56h, 8Bh, 0F7h, 0E...");
        _STOP_("db 5Eh, 0C3h, 0C7h, 44h, 4, 0E3h, 0B9h, 0B...");
        _STOP_("db 81h, 7Ch, 12h, 0A0h, 0, 7Ch, 3, 0BFh, 0...");
        _STOP_("db 5Ch, 1Ch, 0D1h, 0E3h, 2Eh, 8Bh, 39h, 0B...");
        _STOP_("db 2, 0, 8Bh, 54h, 16h, 8Bh, 4Ch, 12h, 0D1...");
        _STOP_("db 8Bh, 0F7h, 0E8h, 82h, 4Fh, 5Eh, 0C3h, 0...");
        _STOP_("db 81h, 7Ch, 12h, 0A0h, 0, 7Ch, 3, 0BFh, 0...");
        _STOP_("db 5Ch, 1Ch, 0D1h, 0E3h, 2Eh, 8Bh, 39h, 0B...");
        _STOP_("db 2, 0, 8Bh, 54h, 16h, 8Bh, 4Ch, 12h, 0D1...");
        _STOP_("db 8Bh, 0F7h, 0E8h, 35h, 4Fh, 5Eh, 0C3h, 8...");
        _STOP_("db 0, 74h, 3, 0E9h, 3Ch, 4Eh, 0C3h, 0C7h, ...");
        _STOP_("db 0BAh, 83h, 7Ch, 42h, 0, 74h, 3, 0E9h, 0...");
        _STOP_("db 83h, 3Eh, 0AAh, 91h, 10h, 7Dh, 6, 0C7h,...");
        _STOP_("db 10h, 0, 0A1h, 98h, 91h, 8Bh, 1Eh, 9Ch, ...");
        _STOP_("db 0Fh, 0D1h, 0E3h, 3, 87h, 0E2h, 40h, 0A3...");
        _STOP_("db 1, 44h, 16h, 83h, 3Eh, 12h, 92h, 0, 74h...");
        _STOP_("db 44h, 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h...");
        _STOP_("db 0C7h, 44h, 28h, 94h, 0, 0C7h, 44h, 2Ch,...");
        _STOP_("db 44h, 16h, 5, 20h, 0, 89h, 44h, 2Ah, 5, ...");
        _STOP_("db 2Eh, 83h, 7Ch, 1Ah, 0, 75h, 17h, 2Eh, 0...");
        _STOP_("db 0, 44h, 48h, 73h, 25h, 0E8h, 9, 87h, 24...");
        _STOP_("db 44h, 48h, 0C7h, 6, 8Ah, 8Eh, 1, 0, 0FEh...");
        _STOP_("db 0Dh, 80h, 7Ch, 1Ah, 78h, 75h, 6, 0C7h, ...");
        _STOP_("db 1, 0, 0C3h, 0C7h, 44h, 1Ah, 2 dup(0), 0...");
        _STOP_("db 92h, 1, 44h, 16h, 8Bh, 44h, 12h, 5, 6, ...");
        _STOP_("db 28h, 5, 14h, 0, 89h, 44h, 2Ch, 8Bh, 44h...");
        _STOP_("db 0, 89h, 44h, 2Ah, 5, 14h, 0, 89h, 44h, ...");
        _STOP_("db 14h, 92h, 1, 44h, 16h, 8Bh, 44h, 12h, 5...");
        _STOP_("db 44h, 28h, 5, 14h, 0, 89h, 44h, 2Ch, 8Bh...");
        _STOP_("db 6, 0, 89h, 44h, 2Ah, 5, 14h, 0, 89h, 44...");
        _STOP_("db 12h, 9Fh, 2Bh, 44h, 12h, 2Dh, 10h, 0, 8...");
        _STOP_("db 9Fh, 2Bh, 5Ch, 16h, 83h, 0EBh, 10h, 0E8...");
        _STOP_("db 0BFh, 22h, 41h, 81h, 7Ch, 12h, 0A0h, 0,...");
        _STOP_("db 2Ah, 41h, 8Bh, 0D8h, 8Ah, 1, 89h, 44h, ...");
        _STOP_("db 0F2h, 0AFh, 0, 44h, 48h, 73h, 4Fh, 0E8h...");
        _STOP_("db 3Fh, 88h, 44h, 48h, 8Bh, 44h, 12h, 5, 1...");
        _STOP_("db 16h, 83h, 0C3h, 10h, 8Bh, 4Ch, 1Ch, 8Bh...");
        _STOP_("db 0E5h, 2Eh, 8Bh, 0AEh, 4Eh, 0CAh, 2Eh, 8...");
        _STOP_("db 0AFh, 0E8h, 84h, 63h, 2Eh, 8Bh, 46h, 0,...");
        _STOP_("db 2Eh, 8Bh, 46h, 2, 89h, 45h, 0Eh, 83h, 0...");
        _STOP_("db 6Dh, 10h, 8Bh, 5Dh, 1Ch, 0D1h, 0E3h, 8B...");
        _STOP_("db 1, 45h, 12h, 8Bh, 87h, 12h, 41h, 1, 45h...");
        _STOP_("db 0C7h, 44h, 0Ch, 19h, 7Dh");
        _STOP_("db 0C7h, 44h, 0Eh, 2 dup(0), 0A1h, 14h, 92...");
        _STOP_("db 0E8h, 75h, 4, 80h, 74h, 1Ch, 80h, 8Bh, ...");
        _STOP_("db 45h, 1Ah, 3Dh, 8, 0, 7Eh, 0Dh, 2Dh, 80h...");
        _STOP_("db 3Dh, 8, 0, 7Eh, 3, 0B8h, 8, 0, 89h, 44h...");
        _STOP_("db 75h, 0Ah, 0C7h, 44h, 28h, 0E8h, 3, 0C7h...");
        _STOP_("db 3, 0C3h, 0C7h, 44h, 0Ch, 19h, 7Dh, 0C7h...");
        _STOP_("db 0A1h, 14h, 92h, 1, 44h, 16h, 0E8h, 0F1h...");
        _STOP_("db 42h, 0, 75h, 0Ah, 0C7h, 44h, 28h, 0E8h,...");
        _STOP_("db 2Ch, 0E8h, 3, 0C3h, 0C7h, 44h, 0Ch, 69h...");
        _STOP_("db 44h, 0Eh, 2 dup(0), 0A1h, 14h, 92h, 1, ...");
        _STOP_("db 0CDh, 2, 83h, 7Ch, 42h, 0, 75h, 0Ah, 0C...");
        _STOP_("db 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, 0C3h,...");
        _STOP_("db 92h, 0, 74h, 3, 0E9h, 0A0h, 0, 0C6h, 6,...");
        _STOP_("db 0BFh, 6Ah, 0C9h, 0B9h, 13h, 0, 0E8h, 0A...");
        _STOP_("db 36h, 0DEh, 0FCh, 0EBh, 3, 0E8h, 1, 54h,...");
        _STOP_("db 90h, 0E8h, 66h, 4Bh, 5Fh, 0C7h, 4, 50h,...");
        _STOP_("db 5, 89h, 44h, 2, 2Eh, 8Bh, 45h, 2, 89h, ...");
        _STOP_("db 8Bh, 45h, 4, 89h, 44h, 4, 2Eh, 8Bh, 45h...");
        _STOP_("db 12h, 2Eh, 8Bh, 45h, 8, 0C6h, 44h, 4Ah, ...");
        _STOP_("db 90h, 91h, 89h, 44h, 16h, 0C7h, 44h, 1Ah...");
        _STOP_("db 44h, 1Ch, 2 dup(0), 0C7h, 44h, 1Eh, 2 d...");
        _STOP_("db 44h, 3Ch, 2 dup(0), 0C7h, 44h, 3Eh, 2 d...");
        _STOP_("db 44h, 40h, 2 dup(0), 0C7h, 44h, 42h, 3, ...");
        _STOP_("db 45h, 0Ah, 89h, 44h, 24h, 83h, 0C7h, 0Ch...");
        _STOP_("db 27h, 0FFh, 0C7h, 44h, 20h, 2 dup(0), 0C...");
        _STOP_("db 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, 0A1h,...");
        _STOP_("db 89h, 2 dup(44h), 0E2h, 2, 0EBh, 3, 0E9h...");
        _STOP_("db 0C7h, 6, 12h, 92h, 2, 0, 0C3h, 0C7h, 45...");
        _STOP_("db 29h, 45h, 24h, 77h, 1Dh, 0FEh, 0Eh, 10h...");
        _STOP_("db 6, 8Ch, 91h, 2 dup(0FFh), 0B9h, 0Ah, 0,...");
        _STOP_("db 34h, 64h, 0, 0FFh, 75h, 8, 0E8h, 0E4h, ...");
        _STOP_("db 0E2h, 0F0h, 0C3h, 50h, 0A1h, 0B4h, 8Eh,...");
        _STOP_("db 0FCh, 0A1h, 0B6h, 8Eh, 0A3h, 0E6h, 0FCh...");
        _STOP_("db 8Eh, 0A3h, 0EAh, 0FCh, 0A1h, 0BAh, 8Eh,...");
        _STOP_("db 0FCh, 8Bh, 45h, 28h, 0A3h, 0F2h, 0FCh, ...");
        _STOP_("db 0A3h, 0F6h, 0FCh, 8Bh, 45h, 2Ch, 0A3h, ...");
        _STOP_("db 45h, 2Eh, 0A3h, 0FEh, 0FCh, 0A1h, 0FEh,...");
        _STOP_("db 0F6h, 0FCh, 0E8h, 22h, 52h, 75h, 2Dh, 8...");
        _STOP_("db 0A3h, 0F6h, 0FCh, 0A1h, 0F6h, 0FCh, 0A3...");
        _STOP_("db 0E8h, 11h, 52h, 75h, 1Ch, 0E8h, 0Ch, 52...");
        _STOP_("db 58h, 0C7h, 45h, 4, 0B9h, 8, 29h, 45h, 2...");
        _STOP_("db 0FEh, 0Eh, 10h, 92h, 0C7h, 45h, 34h, 2C...");
        _STOP_("db 7Dh, 0E8h, 5Ah, 7Dh, 83h, 0C4h, 2, 0C3h...");
        _STOP_("db 83h, 3Eh, 10h, 92h, 0, 74h, 3, 0E9h, 84...");
        _STOP_("db 0Ah, 0C7h, 45h, 4, 0B9h, 8, 0C7h, 47h, ...");
        _STOP_("db 45h, 24h, 77h, 72h, 8Bh, 1Eh, 54h, 90h,...");
        _STOP_("db 74h, 0Dh, 0FFh, 77h, 0Ah, 56h, 8Bh, 0F3...");
        _STOP_("db 4Ah, 5Eh, 5Bh, 0EBh, 0EEh, 57h, 56h, 0B...");
        _STOP_("db 2 dup(0), 0BBh, 2 dup(0), 0BAh, 40h, 1,...");
        _STOP_("db 0, 0BDh");
        _STOP_("db 4Ch, 12h, 0E8h, 0F9h, 57h, 0B9h, 4, 0, ...");
        _STOP_("db 0BFh, 2 dup(0), 81h, 0C7h, 58h, 16h, 0B...");
        _STOP_("db 0C0h, 0F3h, 0ABh, 5Eh, 5Fh, 0C7h, 6, 0A...");
        _STOP_("db 81h, 6, 52h, 91h, 0D0h, 7, 83h, 16h, 54...");
        _STOP_("db 6, 8Ch, 91h, 1, 0, 0C7h, 6, 90h, 91h, 0...");
        _STOP_("db 6, 0AAh, 91h, 0A0h, 8, 0C7h, 6, 8Eh, 91...");
        _STOP_("db 0C7h, 6, 96h, 91h, 2 dup(0), 0C3h, 0A1h...");
        _STOP_("db 44h, 16h, 83h, 7Ch, 1Ah, 0, 74h, 3, 0E9...");
        _STOP_("db 12h, 9Fh, 2Bh, 44h, 12h, 8Bh, 1Eh, 16h,...");
        _STOP_("db 16h, 0E8h, 9Ch, 5Dh, 3Dh, 2, 0, 7Dh, 3,...");
        _STOP_("db 3Dh, 6, 0, 7Eh, 3, 0B8h, 6, 0, 0D1h, 0E...");
        _STOP_("db 0D1h, 0E0h, 0D1h, 0E0h, 0D1h, 0E0h, 2Ch...");
        _STOP_("db 44h, 1Eh, 2 dup(0), 89h, 44h, 1Ch, 0C7h...");
        _STOP_("db 0C7h, 44h, 3Eh, 2 dup(0), 0C7h, 44h, 40...");
        _STOP_("db 0E8h, 67h, 83h, 2Eh, 3Ah, 6, 0F6h, 0AFh...");
        _STOP_("db 0D8h, 0, 0C7h, 44h, 20h, 2, 0, 0A1h, 12...");
        _STOP_("db 44h, 12h, 8Bh, 1Eh, 16h, 9Fh, 2Bh, 5Ch,...");
        _STOP_("db 5Dh, 3Dh, 2, 0, 7Dh, 3, 0B8h, 2, 0, 3Dh...");
        _STOP_("db 3, 0B8h, 6, 0, 0D1h, 0E0h, 0D1h, 0E0h, ...");
        _STOP_("db 0E0h, 0D1h, 0E0h, 2Ch, 60h, 0C7h, 44h, ...");
        _STOP_("db 89h, 44h, 1Ch, 0E8h, 21h, 83h, 25h, 1Fh...");
        _STOP_("db 0, 8Ah, 0E0h, 32h, 0C0h, 0D0h, 0E4h, 0D...");
        _STOP_("db 44h, 3Ch, 0C7h, 44h, 3Eh, 2 dup(0), 0C7...");
        _STOP_("db 2 dup(0), 83h, 7Ch, 1Ch, 20h, 7Ch, 7, 8...");
        _STOP_("db 0A0h, 0, 7Ch, 0Ah, 80h, 44h, 1Ch, 40h, ...");
        _STOP_("db 0F7h, 54h, 3Ch, 8Bh, 44h, 20h, 1, 44h, ...");
        _STOP_("db 1Ah, 18h, 7Ch, 3, 0F7h, 5Ch, 20h, 8Bh, ...");
        _STOP_("db 4, 0, 89h, 44h, 42h, 0EBh, 50h, 8Bh, 7C...");
        _STOP_("db 12h, 89h, 44h, 12h, 8Bh, 45h, 14h, 89h,...");
        _STOP_("db 45h, 16h, 89h, 44h, 16h, 8Bh, 45h, 18h,...");
        _STOP_("db 8Bh, 45h, 1Ch, 89h, 44h, 1Ch, 8Bh, 45h,...");
        _STOP_("db 1Eh, 8Bh, 45h, 3Ch, 89h, 44h, 3Ch, 8Bh,...");
        _STOP_("db 44h, 3Eh, 8Bh, 45h, 40h, 89h, 44h, 40h,...");
        _STOP_("db 89h, 44h, 42h, 0C7h, 44h, 1Ah, 64h, 0, ...");
        _STOP_("db 0A1h, 98h, 91h, 1, 44h, 16h, 0E8h, 0B0h...");
        _STOP_("db 5Ch, 1Ch, 83h, 0C3h, 10h, 0D1h, 0EBh, 0...");
        _STOP_("db 0EBh, 0D1h, 0EBh, 83h, 0E3h, 6, 2Eh, 8B...");
        _STOP_("db 0CBh, 89h, 44h, 0Ch, 0E9h, 61h, 76h, 81...");
        _STOP_("db 91h, 0B0h, 9, 7Dh, 6, 0C7h, 6, 0AAh, 91...");
        _STOP_("db 98h, 91h, 1, 44h, 16h, 0E8h, 7Dh, 0FFh,...");
        _STOP_("db 2Bh, 44h, 12h, 8Bh, 1Eh, 16h, 9Fh, 2Bh,...");
        _STOP_("db 41h, 5Ch, 3Dh, 2, 0, 7Dh, 3, 0B8h, 2, 0...");
        _STOP_("db 7Eh, 3, 0B8h, 6, 0, 89h, 44h, 1Ch, 8Bh,...");
        _STOP_("db 0E3h, 2Eh, 8Bh, 87h, 7Eh, 0CBh, 89h, 44...");
        _STOP_("db 18h, 76h, 0E8h, 3Dh, 82h, 8Bh, 7Ch, 8, ...");
        _STOP_("db 89h, 44h, 12h, 8Bh, 45h, 16h, 89h, 44h,...");
        _STOP_("db 1Ch, 3Bh, 44h, 1Ch, 74h, 1Fh, 89h, 44h,...");
        _STOP_("db 0D1h, 0E3h, 2Eh, 8Bh");
        _STOP_("db 9Fh, 8Eh, 0CBh, 2Eh, 8Bh, 7, 89h, 44h, ...");
        _STOP_("db 47h, 2, 89h, 44h, 0Eh, 83h, 0C3h, 4, 89...");
        _STOP_("db 2Eh, 0A0h, 10h, 0B0h, 0, 44h, 48h, 73h,...");
        _STOP_("db 81h, 24h, 3Fh, 88h, 44h, 48h, 8Bh, 44h,...");
        _STOP_("db 16h, 8Bh, 4Ch, 1Ch, 8Bh, 0E9h, 0D1h, 0E...");
        _STOP_("db 32h, 41h, 3Eh, 3, 9Eh, 42h, 41h, 2Eh, 8...");
        _STOP_("db 0B0h, 0E8h, 0F9h, 5Eh, 0BDh, 32h, 0B4h,...");
        _STOP_("db 0, 89h, 45h, 0Ch, 2Eh, 8Bh, 46h, 2, 89h...");
        _STOP_("db 0C5h, 4, 89h, 6Dh, 10h, 0E9h, 95h, 75h,...");
        _STOP_("db 1, 44h, 16h, 0C7h, 44h, 42h, 0Ch, 0, 0A...");
        _STOP_("db 0D1h, 0E0h, 0D1h, 0E0h, 25h, 7Fh, 0, 0A...");
        _STOP_("db 5, 2Dh, 7Fh, 0, 0F7h, 0D8h, 5, 0A0h, 0,...");
        _STOP_("db 0A1h, 9Ch, 91h, 0D1h, 0E0h, 5, 50h, 0, ...");
        _STOP_("db 0A9h, 80h, 0, 74h, 2, 0F6h, 0D0h, 2Dh, ...");
        _STOP_("db 8Ah, 0F2h, 8Ah, 0D4h, 8Ah, 0E0h, 32h, 0...");
        _STOP_("db 3Ch, 89h, 54h, 3Eh, 0A1h, 9Ch, 91h, 5, ...");
        _STOP_("db 0FFh, 1, 0A9h, 0, 1, 74h, 3, 35h, 0FFh,...");
        _STOP_("db 0, 0D1h, 0E0h, 0D1h, 0E0h, 89h, 44h, 40...");
        _STOP_("db 75h, 0A1h, 98h, 91h, 1, 44h, 16h, 0E8h,...");
        _STOP_("db 22h, 75h, 0A1h, 98h, 91h, 1, 44h, 16h, ...");
        _STOP_("db 0E8h, 49h, 0FEh, 2Eh, 0A0h, 1Ch, 0B0h, ...");
        _STOP_("db 73h, 3Fh, 0E8h, 12h, 81h, 24h, 3Fh, 88h...");
        _STOP_("db 7, 0, 8Bh, 44h, 12h, 8Bh, 5Ch, 16h, 2Eh...");
        _STOP_("db 0B0h, 0D1h, 0E5h, 2Eh, 8Bh, 0AEh, 50h, ...");
        _STOP_("db 16h, 1Eh, 0B0h, 0E8h, 32h, 5Eh, 0BDh, 3...");
        _STOP_("db 8Bh, 46h, 0, 89h, 45h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C5h, 4, 89h, 6Dh, 10h, 49h, ...");
        _STOP_("db 0CBh, 74h, 0A1h, 98h, 91h, 1, 44h, 16h,...");
        _STOP_("db 80h, 0A1h, 12h, 9Fh, 2Bh, 44h, 12h, 8Bh...");
        _STOP_("db 2Bh, 5Ch, 16h, 0E8h, 0B9h, 5Ah, 3Bh, 44...");
        _STOP_("db 1Fh, 89h, 44h, 1Ch, 8Bh, 0D8h, 0D1h, 0E...");
        _STOP_("db 9Fh, 9Eh, 0CBh, 2Eh, 8Bh, 7, 89h, 44h, ...");
        _STOP_("db 47h, 2, 89h, 44h, 0Eh, 83h, 0C3h, 4, 89...");
        _STOP_("db 2Eh, 0A0h, 0F8h, 0AFh, 0, 44h, 48h, 73h...");
        _STOP_("db 8Ah, 80h, 24h, 3Fh, 88h, 44h, 48h, 8Bh,...");
        _STOP_("db 5Ch, 16h, 8Bh, 4Ch, 1Ch, 0BDh, 0C5h, 81...");
        _STOP_("db 16h, 0FAh, 0AFh, 0E8h, 0B3h, 5Dh, 0E8h,...");
        _STOP_("db 6Ch, 2Ah, 8, 83h, 44h, 2Eh, 8, 0C3h, 80...");
        _STOP_("db 92h, 0, 74h, 3, 0E9h, 0BCh, 0, 0C6h, 6,...");
        _STOP_("db 0C7h, 6, 0A6h, 91h, 0B0h, 9, 0C7h, 6, 0...");
        _STOP_("db 0, 0C7h, 6, 0A4h, 91h, 0B0h, 0, 0E8h, 9...");
        _STOP_("db 5Eh, 0CAh, 0B9h, 14h, 0, 0E8h, 0C9h, 4E...");
        _STOP_("db 4Ah, 90h, 0E8h, 2Eh, 46h, 5Fh, 0C7h, 4,...");
        _STOP_("db 8Bh, 5, 89h, 44h, 2, 0C7h, 44h, 4, 53h,...");
        _STOP_("db 45h, 2, 89h, 44h, 6, 2Eh, 8Bh, 5Dh, 4, ...");
        _STOP_("db 89h, 44h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 4...");
        _STOP_("db 0C3h, 4, 89h, 5Ch, 10h, 0C6h, 44h, 4Ah,...");
        _STOP_("db 45h, 6, 89h, 44h, 12h, 2Eh, 8Bh, 45h, 8...");
        _STOP_("db 91h, 89h, 44h, 16h, 0C7h, 44h, 1Ah, 2 d...");
        _STOP_("db 44h, 1Eh, 2 dup(0), 2Eh, 8Bh, 45h, 0Ah,...");
        _STOP_("db 0C7h, 44h, 3Ch, 2 dup(0), 0C7h, 44h, 3E...");
        _STOP_("db 0C7h, 44h, 40h, 2 dup(0), 0C7h, 44h, 42...");
        _STOP_("db 2 dup(0), 2Eh, 8Ah, 45h, 0Ch, 89h, 44h,...");
        _STOP_("db 45h, 0Dh, 88h, 44h, 27h, 83h, 0C7h, 0Eh...");
        _STOP_("db 20h, 2 dup(0), 0E8h, 0A4h, 73h, 0E2h, 2...");
        _STOP_("db 6Ah, 0FFh, 0B8h, 5, 0, 0A3h, 10h, 92h, ...");
        _STOP_("db 1, 83h, 7Dh, 0Ch, 0, 74h, 3, 0B8h, 10h,...");
        _STOP_("db 0C2h, 0E8h, 31h, 73h, 0A1h, 90h, 91h, 2...");
        _STOP_("db 0C7h, 44h, 4, 0D5h, 0C2h, 0BBh, 0F8h, 0...");
        _STOP_("db 0Ch, 1, 74h, 3, 0BBh, 0Eh, 0B5h, 2Eh, 8...");
        _STOP_("db 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 44h, 0Eh, 8...");
        _STOP_("db 89h, 5Ch, 10h, 0C3h, 0A1h, 98h, 91h, 1,...");
        _STOP_("db 7Ch, 16h, 88h, 1, 7Eh, 3, 0E9h, 91h, 0,...");
        _STOP_("db 83h, 7Ch, 1Ah, 0, 75h, 16h, 0C7h, 44h, ...");
        _STOP_("db 0A0h, 0FCh, 0AFh, 0, 44h, 48h, 73h, 17h...");
        _STOP_("db 7Fh, 24h, 3Fh, 88h, 44h, 48h, 8Bh, 44h,...");
        _STOP_("db 1Ah, 83h, 7Ch, 1Ah, 6, 75h, 3, 0F7h, 5C...");
        _STOP_("db 3Ch, 0Ch, 1, 75h, 15h, 8Bh, 44h, 12h, 8...");
        _STOP_("db 0D1h, 0E1h, 0D1h, 0E1h, 0D1h, 0E1h, 0D1...");
        _STOP_("db 83h, 0C1h, 10h, 0EBh, 18h, 8Bh, 4Ch, 12...");
        _STOP_("db 10h, 8Bh, 44h, 1Ah, 0D1h, 0E0h, 0D1h, 0...");
        _STOP_("db 0D1h, 0E0h, 0F7h, 0D8h, 3, 0C1h, 2Dh, 1...");
        _STOP_("db 16h, 83h, 0C3h, 8, 8Bh, 0D3h, 83h, 0C2h...");
        _STOP_("db 28h, 89h, 5Ch, 2Ah, 89h, 4Ch, 2Ch, 89h,...");
        _STOP_("db 0F3h, 7Fh, 74h, 13h, 83h, 3Eh, 88h, 91h...");
        _STOP_("db 0B8h, 6, 0, 0E8h, 85h, 79h, 0C7h, 6, 4,...");
        _STOP_("db 0C3h, 0E8h, 0ECh, 44h, 0C3h, 81h, 3Ch, ...");
        _STOP_("db 3Ch, 8Bh, 44h, 1Ah, 85h, 0C0h, 74h, 1Bh...");
        _STOP_("db 8Bh, 54h, 16h, 8Bh, 4Ch, 12h, 0D1h, 0E9...");
        _STOP_("db 0CBh, 2Bh, 7Ch, 1Ah, 2Bh, 7Ch, 1Ah, 56h...");
        _STOP_("db 0E8h, 45h, 46h, 5Eh, 8Bh, 4Ch, 1Ah, 0D1...");
        _STOP_("db 0E1h, 0D1h, 0E1h, 0D1h, 0E1h, 3, 4Ch, 1...");
        _STOP_("db 16h, 83h, 0C2h, 8, 8Bh, 74h, 0Ch, 0E9h,...");
        _STOP_("db 44h, 1Ah, 85h, 0C0h, 74h, 2Bh, 0BBh, 2,...");
        _STOP_("db 16h, 8Bh, 4Ch, 1Ah, 0D1h, 0E1h, 0D1h, 0...");
        _STOP_("db 0D1h, 0E1h, 0F7h, 0D9h, 3, 4Ch, 12h, 83...");
        _STOP_("db 0D1h, 0E9h, 0BFh, 0BAh, 0CBh, 2Bh, 7Ch,...");
        _STOP_("db 1Ah, 56h, 8Bh, 0F7h, 0E8h, 0F9h, 45h, 5...");
        _STOP_("db 1Ah, 0D1h, 0E1h, 0D1h, 0E1h, 0D1h, 0E1h...");
        _STOP_("db 0F7h, 0D9h, 3, 4Ch, 12h, 83h, 0C1h, 0Fh...");
        _STOP_("db 83h, 0C2h, 8, 8Bh, 74h, 0Ch, 0E9h, 0Dh,...");
        _STOP_("db 0, 83h, 7Dh, 0Ch, 0, 74h, 3, 0B8h, 0E4h...");
        _STOP_("db 0C3h, 0E8h, 0AFh, 71h, 83h, 44h, 16h, 1...");
        _STOP_("db 0E0h, 0, 75h, 4, 83h, 44h, 12h, 10h, 0C...");
        _STOP_("db 0C5h, 0C7h, 44h, 6, 0D8h, 0C4h, 2Eh, 0A...");
        _STOP_("db 89h, 44h, 24h, 0C6h, 44h");
        _STOP_("db 27h, 0FFh, 0C7h, 44h, 28h, 0E8h, 3, 0C7...");
        _STOP_("db 0E8h, 3, 0C7h, 44h, 34h, 0C8h, 0, 8Bh, ...");
        _STOP_("db 44h, 22h, 0BBh, 3Ch, 0B5h, 81h, 3Ch, 0E...");
        _STOP_("db 0BBh, 24h, 0B5h, 2Eh, 8Bh, 7, 89h, 44h,...");
        _STOP_("db 47h, 2, 89h, 44h, 0Eh, 83h, 0C3h, 4, 89...");
        _STOP_("db 0C7h, 44h, 36h, 2 dup(0), 2Eh, 0A1h, 1A...");
        _STOP_("db 44h, 48h, 8Bh, 44h, 12h, 89h, 44h, 30h,...");
        _STOP_("db 89h, 44h, 32h, 0C3h, 0A1h, 0AAh, 91h, 5...");
        _STOP_("db 44h, 16h, 7Ch, 7Bh, 0E8h, 0B9h, 7Dh, 83...");
        _STOP_("db 0, 75h, 15h, 0E8h, 90h, 7Dh, 2Eh, 3Ah, ...");
        _STOP_("db 0Ah, 0C7h, 44h, 1Ah, 1, 0, 0C7h, 44h, 0...");
        _STOP_("db 81h, 3Ch, 0E0h, 0, 75h, 9, 2Eh, 0A1h, 2...");
        _STOP_("db 12h, 0EBh, 7, 2Eh, 0A1h, 2, 0B0h, 29h, ...");
        _STOP_("db 7Ch, 1Ah, 1, 75h, 1Bh, 83h, 7Ch, 0Eh, 0...");
        _STOP_("db 44h, 1Ah, 2, 0, 0A1h, 16h, 9Fh, 2Bh, 44...");
        _STOP_("db 90h, 91h, 89h, 44h, 20h, 0E9h, 81h, 0, ...");
        _STOP_("db 0D1h, 0E3h, 83h, 7Ch, 12h, 28h, 7Ch, 27...");
        _STOP_("db 12h, 18h, 1, 7Fh, 20h, 8Bh, 87h, 52h, 4...");
        _STOP_("db 20h, 0, 79h, 0Eh, 2Eh, 8Bh, 1Eh, 2, 0B0...");
        _STOP_("db 16h, 0EBh, 0Ch, 0E8h, 4Dh, 43h, 0C3h, 2...");
        _STOP_("db 2, 0B0h, 1, 5Ch, 16h, 83h, 7Ch, 12h, 0E...");
        _STOP_("db 7Ch, 12h, 60h, 1, 7Ch, 42h, 8Bh, 44h, 3...");
        _STOP_("db 12h, 8Bh, 44h, 32h, 89h, 44h, 16h, 0C7h...");
        _STOP_("db 0C7h, 44h, 28h, 0E8h, 3, 0C7h, 44h, 2Ch...");
        _STOP_("db 3Ch, 0B5h, 81h, 3Ch, 0E0h, 0, 74h, 3, 0...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 44h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C3h, 4, 89h, 5Ch, 10h, 2Eh, ...");
        _STOP_("db 89h, 44h, 24h, 0C3h, 0E8h, 0BBh, 70h, 0...");
        _STOP_("db 29h, 44h, 2Ah, 29h, 44h, 2Eh, 0C3h, 29h...");
        _STOP_("db 6, 0C7h, 45h, 4, 55h, 0C5h, 0C3h, 56h, ...");
        _STOP_("db 0Ch, 4Ah, 5Eh, 2Bh, 1Eh, 90h, 91h, 0BDh...");
        _STOP_("db 53h, 8, 0E8h, 2Fh, 6Eh, 8Bh, 45h, 34h, ...");
        _STOP_("db 83h, 16h, 54h, 91h, 0, 56h, 0E8h, 1Bh, ...");
        _STOP_("db 96h, 90h, 0E8h, 6Eh, 42h, 5Fh, 0BBh, 0B...");
        _STOP_("db 4, 18h, 0, 0C7h, 44h, 1Ah, 7, 0, 0C7h, ...");
        _STOP_("db 28h, 0C7h, 44h, 4, 53h, 8, 2Eh, 8Bh, 7,...");
        _STOP_("db 2Eh, 8Bh, 47h, 2, 89h, 44h, 0Eh, 83h, 0...");
        _STOP_("db 5Ch, 10h, 8Bh, 45h, 12h, 89h, 44h, 12h,...");
        _STOP_("db 2Bh, 6, 90h, 91h, 89h, 44h, 16h, 0E8h, ...");
        _STOP_("db 44h, 1Ch, 8Bh, 0F7h, 0E8h, 36h, 0FFh, 5...");
        _STOP_("db 44h, 4, 75h, 0C5h, 8Bh, 4Ch, 12h, 8Bh, ...");
        _STOP_("db 16h, 90h, 91h, 81h, 0FAh, 0DCh, 0, 7Fh,...");
        _STOP_("db 74h, 0Ch, 0E8h, 8Ch, 43h, 5Eh, 0EBh, 19...");
        _STOP_("db 4Ch, 12h, 8Bh, 54h, 16h, 2Bh, 16h, 90h,...");
        _STOP_("db 0DCh, 0, 7Fh, 0EFh, 56h, 8Bh, 74h, 0Ch,...");
        _STOP_("db 42h, 5Eh, 8Bh, 6Ch, 22h, 0D1h, 0E5h, 8B...");
        _STOP_("db 3Dh, 2, 0, 7Ch, 1, 0C3h, 0BFh, 0C6h");
        _STOP_("db 0CBh, 81h, 3Ch, 0E0h, 0, 74h, 3, 0BFh, ...");
        _STOP_("db 1, 0, 0BBh, 3, 0, 3Eh, 8Bh, 8Eh, 94h, 4...");
        _STOP_("db 96h, 0AAh, 41h, 2Bh, 16h, 90h, 91h, 56h...");
        _STOP_("db 0E8h, 80h, 43h, 5Eh, 0C3h, 0B8h, 0D0h, ...");
        _STOP_("db 0Ch, 0, 75h, 3, 0B8h, 0D4h, 0, 0BBh, 1A...");
        _STOP_("db 54h, 6Fh, 0C7h, 44h, 4, 61h, 7, 0C7h, 4...");
        _STOP_("db 0C6h, 2Eh, 0A1h, 4, 0B0h, 89h, 44h, 24h...");
        _STOP_("db 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, ...");
        _STOP_("db 0BBh, 0D2h, 0CBh, 81h, 3Ch, 0D0h, 0, 74...");
        _STOP_("db 0CCh, 2Eh, 8Bh, 7, 89h, 5, 2Eh, 8Bh, 47...");
        _STOP_("db 2, 2Eh, 8Bh, 47h, 4, 89h, 45h, 28h, 2Eh...");
        _STOP_("db 89h, 45h, 2Ah, 0C3h, 0A1h, 0AAh, 91h, 5...");
        _STOP_("db 44h, 16h, 7Dh, 3, 0E9h, 0B9h, 0, 8Bh, 4...");
        _STOP_("db 0, 89h, 44h, 28h, 5, 1Ch, 0, 89h, 44h, ...");
        _STOP_("db 16h, 2Bh, 6, 90h, 91h, 5, 2, 0, 89h, 44...");
        _STOP_("db 0, 89h, 44h, 2Eh, 8Bh, 44h, 1Ah, 85h, 0...");
        _STOP_("db 2Eh, 0A0h, 6, 0B0h, 0, 44h, 48h, 73h, 0...");
        _STOP_("db 7Bh, 24h, 3Fh, 88h, 44h, 48h, 0C7h, 44h...");
        _STOP_("db 0C3h, 0D1h, 0E0h, 0D1h, 0E0h, 0D1h, 0E0...");
        _STOP_("db 0CBh, 81h, 3Ch, 0D0h, 0, 74h, 3, 0BBh, ...");
        _STOP_("db 7Ch, 38h, 3, 0D8h, 2Eh, 8Bh, 7, 89h, 5,...");
        _STOP_("db 2, 89h, 45h, 2, 2Eh, 8Bh, 47h, 4, 89h, ...");
        _STOP_("db 8Bh, 47h, 6, 89h, 45h, 2Ah, 0FFh, 44h, ...");
        _STOP_("db 1Ah, 4, 74h, 0Ch, 83h, 7Ch, 1Ah, 6, 75h...");
        _STOP_("db 1Ah, 2 dup(0), 0C3h, 8Bh, 44h, 12h, 8Bh...");
        _STOP_("db 1Eh, 90h, 91h, 5, 12h, 0, 83h, 0C3h, 0E...");
        _STOP_("db 2Eh, 8, 0B0h, 0D1h, 0E5h, 2Eh, 8Bh, 0AE...");
        _STOP_("db 0B9h, 2, 0, 81h, 3Ch, 0D4h, 0, 74h, 6, ...");
        _STOP_("db 8, 0, 2Eh, 8Bh, 16h, 0Ah, 0B0h, 0E9h, 0...");
        _STOP_("db 0DCh, 40h, 0C3h, 29h, 45h, 24h, 76h, 6,...");
        _STOP_("db 46h, 0C7h, 0C3h, 0BAh, 53h, 8, 8Bh, 45h...");
        _STOP_("db 0, 8Bh, 5Dh, 16h, 2Bh, 1Eh, 90h, 91h, 8...");
        _STOP_("db 0BDh, 4Ch, 12h, 0E8h, 1Dh, 6Ch, 8Bh, 5D...");
        _STOP_("db 32h, 0CCh, 81h, 3Dh, 0D0h, 0, 74h, 3, 0...");
        _STOP_("db 2Eh, 8Bh, 46h, 0, 89h, 7, 2Eh, 8Bh, 46h...");
        _STOP_("db 2, 2Eh, 8Bh, 46h, 4, 89h, 47h, 28h, 2Eh...");
        _STOP_("db 89h, 47h, 2Ah, 81h, 6, 52h, 91h, 90h, 1...");
        _STOP_("db 91h, 0, 56h, 8Bh, 0F7h, 0E8h, 7Ch, 40h,...");
        _STOP_("db 44h, 4, 61h, 7, 0BFh, 0D2h, 0CBh, 81h, ...");
        _STOP_("db 74h, 3, 0BFh, 2, 0CCh, 0B8h, 2, 0, 0BBh...");
        _STOP_("db 4Ch, 12h, 0D1h, 0E9h, 8Bh, 54h, 16h, 2B...");
        _STOP_("db 91h, 56h, 8Bh, 0F7h, 0E8h, 0F4h, 41h, 5...");
        _STOP_("db 0E3h, 2Eh, 0FFh, 0A7h, 42h, 0CCh, 0BBh,...");
        _STOP_("db 0Bh, 6Ch, 0BBh, 5Ch, 0B0h, 0E9h, 5, 6Ch...");
        _STOP_("db 0B0h, 0E9h, 0FFh, 6Bh, 0BBh, 4Ah, 0B0h,...");
        _STOP_("db 6Bh, 0BBh, 80h, 0B0h, 0E9h, 0F3h, 6Bh, ...");
        _STOP_("db 0E9h, 0EDh, 6Bh, 33h, 0C0h");
        _STOP_("db 0C3h, 0C7h, 6, 0A8h, 91h, 80h, 8, 0C7h,...");
        _STOP_("db 0FFh, 11h, 0C7h, 6, 0ACh, 8Eh, 70h, 17h...");
        _STOP_("db 8Eh, 0D0h, 7, 0C6h, 6, 36h, 92h, 0, 0C6...");
        _STOP_("db 0, 2Eh, 0A1h, 0Ch, 0B0h, 2Eh, 0A3h, 80h...");
        _STOP_("db 0A1h, 0Ch, 0B0h, 2Eh, 0A3h, 8Ch, 0C9h, ...");
        _STOP_("db 0B0h, 2Eh, 0A3h, 74h, 0C9h, 2Eh, 0A0h, ...");
        _STOP_("db 0A2h, 4Ah, 0CBh, 2Eh, 0A0h, 14h, 0B0h, ...");
        _STOP_("db 0CBh, 2Eh, 0A0h, 14h, 0B0h, 2Eh, 0A2h, ...");
        _STOP_("db 0A0h, 14h, 0B0h, 2Eh, 0A2h, 74h, 0CBh, ...");
        _STOP_("db 0B0h, 2Eh, 0A2h, 3Ch, 0CBh, 2Eh, 0A0h, ...");
        _STOP_("db 2 dup(0A2h), 0CAh, 0A1h, 1Ah, 99h, 8Bh,...");
        _STOP_("db 0E0h, 3, 0C3h, 0D1h, 0E0h, 0A3h, 76h, 8...");
        _STOP_("db 99h, 0D1h, 0E0h, 0D1h, 0E0h, 0D1h, 0E0h...");
        _STOP_("db 8Eh, 0C7h, 6, 72h, 8Eh, 9Bh, 81h, 0C3h,...");
        _STOP_("db 0, 13h, 0B6h, 76h, 0B1h, 0D8h, 0, 20h, ...");
        _STOP_("db 0B2h, 0B1h, 0CCh, 0, 20h, 1, 13h, 0B6h,...");
        _STOP_("db 0, 20h, 1, 99h, 0B8h, 0D0h, 0B1h, 0F0h,...");
        _STOP_("db 0B1h, 0F4h, 0, 20h, 1, 1Eh, 0B2h, 8Ah, ...");
        _STOP_("db 0C6h, 0B2h, 0E4h, 0B2h, 2, 0B3h, 20h, 0...");
        _STOP_("db 6Ch, 0B2h, 41h, 55h, 81h, 55h, 0C1h, 55...");
        _STOP_("db 56h, 81h, 56h, 0C1h, 59h, 0, 5Ah, 40h, ...");
        _STOP_("db 0C0h, 5Ah, 1, 5Bh, 41h, 5Eh, 80h, 5Eh, ...");
        _STOP_("db 5Fh, 40h, 5Fh, 81h, 5Fh, 0C1h, 62h, 0, ...");
        _STOP_("db 80h, 63h, 0C0h, 63h, 1, 64h, 2 dup(0), ...");
        _STOP_("db 67h, 0C1h, 67h, 1, 68h, 2 dup(0), 41h, ...");
        _STOP_("db 0C1h, 55h, 1, 56h, 41h, 56h, 81h, 56h, ...");
        _STOP_("db 5Ah, 40h, 5Ah, 80h, 5Ah, 0C0h, 5Ah, 1, ...");
        _STOP_("db 80h, 5Eh, 0C0h, 5Eh, 0, 5Fh, 40h, 5Fh, ...");
        _STOP_("db 62h, 0, 63h, 40h, 63h, 80h, 63h, 0C0h, ...");
        _STOP_("db 2 dup(0), 0C1h, 43h, 0, 44h, 40h, 44h, ...");
        _STOP_("db 0C1h, 48h, 1, 49h, 4 dup(0), 2Eh, 0C9h,...");
        _STOP_("db 0C9h, 26h, 0C9h, 26h, 0C9h, 1Eh, 0C9h, ...");
        _STOP_("db 0C9h, 0Eh, 0C9h, 56h, 0C9h, 36h, 0C9h, ...");
        _STOP_("db 0C9h, 3Eh, 0C9h, 46h, 0C9h, 4Eh, 0C9h, ...");
        _STOP_("db 0C9h, 41h, 4Dh, 81h, 4Dh, 41h, 52h, 81h...");
        _STOP_("db 56h, 1, 57h, 41h, 5Bh, 81h, 5Bh, 0C1h, ...");
        _STOP_("db 41h, 64h, 81h, 64h, 41h, 68h, 81h, 68h,...");
        _STOP_("db 6Bh, 41h, 6Eh, 81h, 6Eh, 41h, 71h, 81h,...");
        _STOP_("db 1, 4Eh, 0C1h, 52h, 1, 53h, 41h, 57h, 81...");
        _STOP_("db 5Bh, 1, 5Ch, 41h, 60h, 81h, 60h, 0C1h, ...");
        _STOP_("db 0C1h, 68h, 1, 69h, 0C1h, 6Bh, 1, 6Ch, 0...");
        _STOP_("db 6Fh, 0C1h, 71h, 1, 72h, 0CEh, 35h, 0C3h...");
        _STOP_("db 0C1h, 68h, 0C3h, 0, 0BCh, 0F3h, 0C1h, 2...");
        _STOP_("db 0B8h, 68h, 0B9h, 0A0h, 3 dup(0), 64h, 0...");
        _STOP_("db 30h, 0B9h, 0E3h, 0B9h, 70h, 0, 20h, 0, ...");
        _STOP_("db 0BAh, 30h, 0B9h, 0E3h, 0B9h, 0B0h, 0, 2...");
        _STOP_("db 77h, 0BBh, 99h, 3Ah, 0Eh, 0BAh, 0A0h, 0...");
        _STOP_("db 0B8h, 0BBh, 99h, 3Ah, 0Eh, 0BAh, 0A0h, ...");
        _STOP_("db 0B8h, 0BBh, 99h, 3Ah, 0Eh, 0BAh, 0A0h, ...");
        _STOP_("db 2 dup(0), 0B8h, 0BBh, 99h, 3Ah, 0Eh, 0B...");
        _STOP_("db 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah, 0E...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0B8h, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 3 dup(0), 0DCh, 0BBh, 99h, 3Ah,...");
        _STOP_("db 0, 58h, 7 dup(0), 3Eh, 0B3h, 4Ch, 0B3h,...");
        _STOP_("db 0B3h, 76h, 0B3h, 2 dup(0), 0D5h, 0BDh, ...");
        _STOP_("db 0B3h, 0A0h, 0, 0E8h, 9, 40h, 0, 32h, 0F...");
        _STOP_("db 61h, 7, 84h, 0B3h, 0A0h, 0, 0E8h, 9, 40...");
        _STOP_("db 3, 0BFh, 61h, 7, 84h, 0B3h, 0A0h, 0, 0E...");
        _STOP_("db 32h, 0FFh, 3, 0BFh, 61h, 7, 84h, 0B3h, ...");
        _STOP_("db 9, 40h, 0, 32h, 0FFh, 28h, 0BFh, 46h, 0...");
        _STOP_("db 0A0h, 2 dup(0), 0Ah, 40h, 0, 0AFh, 0FFh...");
        _STOP_("db 43h, 0BDh, 8Ch, 0B3h, 0A0h, 2 dup(0), 0...");
        _STOP_("db 0FFh, 0F4h, 0BFh, 61h, 7, 90h, 0B3h, 0A...");
        _STOP_("db 8, 0C0h, 0, 1, 0, 5Bh, 0C0h, 61h, 7, 90...");
        _STOP_("db 0, 0F8h, 8, 0C0h, 0, 1, 0, 5Bh, 0C0h, 6...");
        _STOP_("db 0A0h, 0, 0F8h, 8, 0C0h, 0, 1, 0, 5Bh, 0...");
        _STOP_("db 90h, 0B3h, 0A0h, 0, 0F8h, 8, 0C0h, 0, 1...");
        _STOP_("db 61h, 7, 90h, 0B3h, 0A0h, 0, 0F8h, 8, 0C...");
        _STOP_("db 5Bh, 0C0h, 61h, 7, 90h, 0B3h, 0A0h, 0, ...");
        _STOP_("db 0, 1, 0, 5Bh, 0C0h, 61h, 7, 90h, 0B3h, ...");
        _STOP_("db 8, 0C0h, 0, 1, 0, 5Bh, 0C0h, 61h, 7, 90...");
        _STOP_("db 0, 0F8h, 8, 0C0h, 0, 1, 0, 5Bh, 0C0h, 6...");
        _STOP_("db 0A0h, 0, 0F8h, 8, 0C0h, 0, 1, 0, 67h, 0...");
        _STOP_("db 94h, 0B3h, 0A0h, 0, 0F8h, 8, 0C0h, 0, 1...");
        _STOP_("db 0C0h, 0D3h, 0BCh, 0DEh, 0B3h, 78h, 0, 9...");
        _STOP_("db 14h, 0, 0BEh, 0C0h, 0D3h, 0BCh, 0DEh, 0...");
        _STOP_("db 57h, 9, 2 dup(0), 14h, 0, 0BEh, 0C0h, 0...");
        _STOP_("db 0B3h, 0C8h, 0, 97h, 9, 2 dup(0), 14h, 0...");
        _STOP_("db 0D3h, 0BCh, 0DEh, 0B3h, 0C8h, 0, 57h, 9...");
        _STOP_("db 0, 99h, 1Dh, 81h, 1Bh, 0CDh, 19h, 89h, ...");
        _STOP_("db 0A1h, 0B0h, 31h, 0B3h, 0C1h, 0B5h, 0D1h...");
        _STOP_("db 0A6h, 0F1h, 0A8h, 81h, 0ABh, 48h, 0B4h,...");
        _STOP_("db 0B4h, 8Ah, 0B4h, 0A0h, 0B4h, 0B6h, 0B4h...");
        _STOP_("db 0E2h, 0B4h, 16h, 0B4h, 24h, 0B4h, 0C2h,...");
        _STOP_("db 0B3h, 0DEh, 0B3h, 0ECh, 0B3h, 0FAh, 0B3...");
        _STOP_("db 3Fh, 41h, 3Fh, 41h, 3Fh, 41h, 3Fh, 41h,...");
        _STOP_("db 81h, 3Fh, 81h, 3Fh, 81h, 3Fh, 81h, 3Fh,...");
        _STOP_("db 3Fh, 1, 31h, 1, 35h, 1, 39h, 0C1h, 30h,...");
        _STOP_("db 38h, 41h, 39h, 81h, 39h");
        _STOP_("db 41h, 3Ch, 81h, 3Ch, 0C1h, 39h, 1, 3Ah, ...");
        _STOP_("db 3Dh, 0C1h, 39h, 1, 3Ah, 0C1h, 3Ch, 1, 3...");
        _STOP_("db 1, 3Ah, 0C1h, 3Ch, 1, 3Dh, 0C1h, 39h, 1...");
        _STOP_("db 3Ch, 1, 3Dh, 41h, 39h, 81h, 39h, 41h, 3...");
        _STOP_("db 0C1h, 3Ah, 1, 3Bh, 0C1h, 3Dh, 1, 3Eh, 4...");
        _STOP_("db 3Bh, 41h, 3Eh, 81h, 3Eh, 41h, 3Bh, 81h,...");
        _STOP_("db 81h, 3Eh, 41h, 3Bh, 81h, 3Bh, 41h, 3Eh,...");
        _STOP_("db 3Bh, 81h, 3Bh, 41h, 3Eh, 81h, 3Eh, 0C1h...");
        _STOP_("db 0C1h, 3Dh, 1, 3Eh, 41h, 3Ah, 81h, 3Ah, ...");
        _STOP_("db 3Dh, 0C1h, 3Bh, 1, 3Ch, 0C1h, 3Eh, 1, 3...");
        _STOP_("db 78h, 0C7h, 7Eh, 0C7h, 84h, 0C7h, 8Ah, 0...");
        _STOP_("db 96h, 0C7h, 71h, 81h, 0C5h, 81h, 9Bh, 81...");
        _STOP_("db 5Ah, 68h, 6 dup(0), 14h, 0, 0Ch, 0, 0Ah...");
        _STOP_("db 14h, 0, 6, 0, 50h, 0, 7, 0, 4, 0, 0Fh, ...");
        _STOP_("db 0, 0Ah, 0, 10h, 0, 0Ah, 0, 14h, 0, 14h,...");
        _STOP_("db 0, 0Ah, 0, 0Fh, 0, 8, 0, 1, 0, 14h, 0, ...");
        _STOP_("db 0, 0C8h, 0, 4, 0, 0Ah, 0, 1, 0, 0Eh, 0,...");
        _STOP_("db 1, 0Bh, 48h, 53h, 8, 0A7h, 3Ah, 2Eh, 0C...");
        _STOP_("db 3 dup(0), 0CCh, 0, 2Ch, 1, 0Bh, 48h, 53...");
        _STOP_("db 50h, 0CDh, 0Ah, 0, 0FFh, 3 dup(0), 0D0h...");
        _STOP_("db 0Bh, 48h, 53h, 8, 0A7h, 3Ah, 6Eh, 0CDh,...");
        _STOP_("db 0D4h, 0, 0FAh, 0, 0Bh, 48h, 53h, 8, 0A7...");
        _STOP_("db 0CDh, 5, 5 dup(0), 0D8h, 0, 64h, 0, 0Bh...");
        _STOP_("db 0A7h, 3Ah, 0DAh, 0CDh, 5, 5 dup(0), 0E0...");
        _STOP_("db 0Bh, 48h, 53h, 8, 0A7h, 3Ah, 0, 0CEh, 5...");
        _STOP_("db 0, 0C8h, 0, 3Ch, 0D2h, 53h, 8, 0A7h, 3A...");
        _STOP_("db 5, 5 dup(0), 0F0h, 0, 64h, 0, 0Bh, 48h,...");
        _STOP_("db 3Ah, 4Eh, 0CEh, 5, 5 dup(0), 29h, 0, 2,...");
        _STOP_("db 0, 35h, 5, 2, 0, 0C5h, 7, 2, 0, 41h, 0A...");
        _STOP_("db 0Ch, 2, 0, 4Dh, 0Fh, 2, 3 dup(0), 0E2h,...");
        _STOP_("db 0DDh, 11h, 3, 0, 9, 14h, 3, 0, 35h, 16h...");
        _STOP_("db 18h, 3, 0, 2Dh, 1Bh, 3, 0, 95h, 1Dh, 3,...");
        _STOP_("db 41h, 50h, 0CDh, 41h, 34h, 2, 0, 0F1h, 3...");
        _STOP_("db 35h, 2, 0, 47h, 36h, 2, 0, 0EDh, 36h, 2...");
        _STOP_("db 2, 0, 43h, 38h, 2, 0, 0F3h, 38h, 2, 3 d...");
        _STOP_("db 41h, 6Eh, 0CDh, 41h, 3Bh, 2, 0, 0F1h, 3...");
        _STOP_("db 3Ch, 2, 0, 15h, 3Dh, 2, 0, 93h, 3Dh, 2,...");
        _STOP_("db 2, 0, 99h, 3Eh, 2, 0, 21h, 3Fh, 2, 0, 0...");
        _STOP_("db 0, 6Dh, 40h, 2, 0, 9, 41h, 2, 0, 91h, 4...");
        _STOP_("db 42h, 2, 0, 97h, 42h, 2, 0, 15h, 43h, 2,...");
        _STOP_("db 2, 3 dup(0), 0E2h, 41h, 94h, 0CDh, 39h,...");
        _STOP_("db 44h, 1, 0, 5Dh, 45h, 1, 0, 0Dh, 46h, 1,...");
        _STOP_("db 1, 0, 6Dh, 47h, 1, 0, 1Dh, 48h, 1, 0, 0...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 0DAh, 0CDh, 69h, 54h");
        _STOP_("db 1, 0, 0Fh, 55h, 1, 0, 0B5h, 55h, 1, 0, ...");
        _STOP_("db 0, 0D9h, 56h, 1, 0, 7Fh, 57h, 1, 0, 7, ...");
        _STOP_("db 58h, 1, 0, 49h, 59h, 1, 0, 0EFh, 59h, 1...");
        _STOP_("db 1, 0, 31h, 5Bh, 1, 0, 0B9h, 5Bh, 1, 0, ...");
        _STOP_("db 0, 0F1h, 5Ch, 1, 0, 83h, 5Dh, 1, 0, 0Bh...");
        _STOP_("db 0A7h, 5Eh, 1, 3 dup(0), 0E2h, 41h, 0, 0...");
        _STOP_("db 1, 0, 0A9h, 0A6h, 1, 0, 31h, 0A7h, 1, 0...");
        _STOP_("db 1, 0, 2Dh, 0A8h, 1, 0, 0DDh, 0A8h, 1, 0...");
        _STOP_("db 1, 0, 0D9h, 0A9h, 1, 3 dup(0), 0E2h, 41...");
        _STOP_("db 6Dh, 83h, 2, 0, 1Dh, 84h, 2, 3 dup(0), ...");
        _STOP_("db 0CEh, 0CDh, 84h, 2, 0, 7Dh, 85h, 2, 3 d...");
        _STOP_("db 41h, 82h, 0CEh, 2Dh, 86h, 2, 0, 0DDh, 8...");
        _STOP_("db 0E2h, 41h, 90h, 0CEh, 69h, 49h, 3, 0, 1...");
        _STOP_("db 0E2h, 41h, 9Eh, 0CEh, 0C9h, 4Ah, 3, 0, ...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 0ACh, 0CEh, 29h, 4...");
        _STOP_("db 4Ch, 3, 3 dup(0), 0E2h, 41h, 0BAh, 0CEh...");
        _STOP_("db 0, 39h, 4Eh, 3, 3 dup(0), 0E2h, 41h, 0C...");
        _STOP_("db 4Eh, 3, 0, 99h, 4Fh, 3, 3 dup(0), 0E2h,...");
        _STOP_("db 49h, 50h, 3, 0, 0F9h, 50h, 3, 3 dup(0),...");
        _STOP_("db 0CEh, 0A9h, 51h, 3, 0, 59h, 52h, 3, 3 d...");
        _STOP_("db 41h, 0F2h, 0CEh, 9, 53h, 3, 0, 0B9h, 53...");
        _STOP_("db 0E2h, 41h, 0, 0CFh, 0C1h, 1Fh, 2, 0, 51...");
        _STOP_("db 0E1h, 24h, 2, 0, 71h, 27h, 2, 3 dup(0),...");
        _STOP_("db 0CFh, 1, 2Ah, 2, 0, 91h, 2Ch, 2, 0, 21h...");
        _STOP_("db 0B1h, 31h, 2, 3 dup(0), 0E2h, 41h, 24h,...");
        _STOP_("db 2, 0, 0E1h, 24h, 2, 0, 51h, 22h, 2, 0, ...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 3Ah, 0CFh, 0B1h, 3...");
        _STOP_("db 2Fh, 2, 0, 91h, 2Ch, 2, 0, 1, 2Ah, 2, 3...");
        _STOP_("db 41h, 50h, 0CFh, 61h, 7Ah, 2, 0, 11h, 7B...");
        _STOP_("db 0E2h, 41h, 66h, 0CFh, 0B7h, 7Bh, 2, 0, ...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 74h, 0CFh, 0DBh, 7...");
        _STOP_("db 7Dh, 2, 3 dup(0), 0E2h, 41h, 82h, 0CFh,...");
        _STOP_("db 0, 5Fh, 7Eh, 2, 3 dup(0), 0E2h, 41h, 90...");
        _STOP_("db 7Eh, 2, 0, 97h, 7Fh, 2, 3 dup(0), 0E2h,...");
        _STOP_("db 3Dh, 80h, 2, 0, 0D9h, 80h, 2, 3 dup(0),...");
        _STOP_("db 0CFh, 61h, 81h, 2, 0, 0D5h, 81h, 2, 3 d...");
        _STOP_("db 41h, 0BAh, 0CFh, 49h, 82h, 2, 0, 0E5h, ...");
        _STOP_("db 0E2h, 41h, 0C8h, 0CFh, 4 dup(0), 55h, 6...");
        _STOP_("db 61h, 0AAh, 2 dup(0), 0DDh, 99h, 2 dup(0...");
        _STOP_("db 2, 0, 9Fh, 9Dh, 2, 0, 0A9h, 9Eh, 2, 0, ...");
        _STOP_("db 3 dup(0), 0E2h, 41h, 0E2h, 0CFh, 29h, 9...");
        _STOP_("db 99h, 1, 0, 71h, 99h, 1, 0, 95h, 99h, 1,...");
        _STOP_("db 1, 0, 95h, 99h, 1, 0, 71h, 99h, 1, 0, 4...");
        _STOP_("db 0E2h, 41h, 0FCh, 0CFh, 0F9h, 0A0h, 2, 0...");
        _STOP_("db 2, 0, 0E9h, 0A4h, 2, 0, 61h, 0A3h, 2, 3...");
        _STOP_("db 41h, 22h, 0D0h, 8Dh, 87h, 2, 0, 3Dh, 88...");
        _STOP_("db 2 dup(0), 0E2h, 41h, 38h, 0D0h, 0EDh, 8...");
        _STOP_("db 89h, 2, 3 dup(0), 0E2h, 41h, 46h, 0D0h,...");
        _STOP_("db 0, 0FDh, 8Ah, 2, 3 dup(0), 0E2h, 41h, 5...");
        _STOP_("db 8Bh, 2, 0, 5Dh, 8Ch, 2, 3 dup(0), 0E2h,...");
        _STOP_("db 0Dh, 8Dh, 2, 0, 0BDh, 8Dh, 2, 3 dup(0),...");
        _STOP_("db 0D0h, 6Dh, 8Eh, 2, 0, 1Dh, 8Fh, 2, 3 du...");
        _STOP_("db 7Eh, 0D0h, 0CDh, 8Fh, 2, 0, 7Dh, 90h, 2...");
        _STOP_("db 41h, 8Ch, 0D0h, 2Dh, 91h, 2, 0, 0DDh, 9...");
        _STOP_("db 0E2h, 41h, 9Ah, 0D0h, 4Dh, 5Fh, 1, 0, 0...");
        _STOP_("db 0, 85h, 60h, 1, 0, 3, 61h, 1, 3 dup(0),...");
        _STOP_("db 0D0h, 99h, 39h, 3, 0, 0Dh, 3Ah, 3, 3 du...");
        _STOP_("db 0BEh, 0D0h, 6Dh, 3Ah, 3, 0, 0E1h, 3Ah, ...");
        _STOP_("db 0E2h, 41h, 0CCh, 0D0h, 0A1h, 16h, 92h, ...");
        _STOP_("db 0A1h, 18h, 92h, 0A3h, 74h, 0D2h, 2 dup(...");
        _STOP_("db 0D1h, 0E3h, 2Eh, 0FFh, 0A7h, 2Eh, 0E7h,...");
        _STOP_("db 0D1h, 0E3h, 8Bh, 9Fh, 0Ch, 0DFh, 8Dh, 6...");
        _STOP_("db 6, 0FEh, 0FCh, 9, 0, 0C7h, 6, 0FAh, 0FC...");
        _STOP_("db 8Bh, 45h, 8, 0A3h, 0E2h, 0FCh, 8Bh, 45h...");
        _STOP_("db 0E6h, 0FCh, 0A1h, 90h, 91h, 29h, 6, 0E6...");
        _STOP_("db 3, 3Fh, 0BFh, 4Ah, 90h, 0E8h, 69h, 36h,...");
        _STOP_("db 0, 0C7h, 44h, 2, 0B9h, 0D1h, 0C7h, 44h,...");
        _STOP_("db 44h, 6, 0A7h, 3Ah, 0C7h, 44h, 0Ch, 69h,...");
        _STOP_("db 0Eh, 2 dup(0), 8Bh, 47h, 2, 89h, 44h, 1...");
        _STOP_("db 4, 2Bh, 6, 90h, 91h, 89h, 44h, 16h, 2Eh...");
        _STOP_("db 0CCh, 89h, 44h, 24h, 0C6h, 44h, 27h, 0,...");
        _STOP_("db 2 dup(0), 0C7h, 44h, 1Eh, 2 dup(0), 0C7...");
        _STOP_("db 2 dup(0), 0C7h, 44h, 3Eh, 2 dup(0), 0C7...");
        _STOP_("db 2 dup(0), 89h, 5Ch, 38h, 89h, 6Ch, 3Ah,...");
        _STOP_("db 0FCh, 89h, 44h, 1Ah, 2Eh, 0A1h, 62h, 0C...");
        _STOP_("db 0FCh, 0C7h, 44h, 28h, 0E8h, 3, 0C7h, 44...");
        _STOP_("db 3, 0C7h, 44h, 34h, 0C8h, 0, 0C7h, 44h, ...");
        _STOP_("db 2Eh, 0A1h, 64h, 0CCh, 89h, 44h, 42h, 0B...");
        _STOP_("db 26h, 0FEh, 0FCh, 88h, 44h, 48h, 0FFh, 0...");
        _STOP_("db 78h, 3, 0E9h, 64h, 0FFh, 0C3h, 0A1h, 98...");
        _STOP_("db 16h, 81h, 7Ch, 16h, 90h, 1, 7Dh, 72h, 0...");
        _STOP_("db 0E8h, 99h, 76h, 8Bh, 5Ch, 1Ch, 83h, 0C3...");
        _STOP_("db 0EBh, 0D1h, 0EBh, 0D1h, 0EBh, 0D1h, 0EB...");
        _STOP_("db 0Eh, 58h, 5, 10h, 0, 0D1h, 0E8h, 0D1h, ...");
        _STOP_("db 0D1h, 0E8h, 25h, 0Eh, 0, 3Bh, 0C3h, 74h...");
        _STOP_("db 0BFh, 42h, 0E7h, 2Eh, 8Bh, 5, 89h, 44h,...");
        _STOP_("db 45h, 2, 89h, 44h, 0Eh, 83h, 0C7h, 4, 89...");
        _STOP_("db 2Eh, 0A0h, 96h, 0CCh, 0, 44h, 48h, 73h,...");
        _STOP_("db 48h, 0, 0B9h, 7, 0, 8Bh, 44h, 12h, 8Bh,...");
        _STOP_("db 8Bh, 2Eh, 9Ah, 0CCh, 0D1h, 0E5h, 2Eh, 8...");
        _STOP_("db 0EBh, 2Eh, 8Bh, 16h, 98h, 0CCh, 0E8h, 0...");
        _STOP_("db 79h, 0E3h, 0E9h, 51h, 63h, 0E8h, 85h, 3...");
        _STOP_("db 74h, 1Ch, 0E8h, 0C9h, 75h, 8Bh, 5Ch, 1C...");
        _STOP_("db 20h, 0D1h, 0EBh, 0D1h, 0EBh, 0D1h, 0EBh...");
        _STOP_("db 0D1h, 0EBh, 83h, 0E3h, 6, 58h, 2Dh, 20h...");
        _STOP_("db 0D1h, 0E8h, 0D1h");
        _STOP_("db 0E8h, 0D1h, 0E8h, 0D1h, 0E8h, 25h, 6, 0...");
        _STOP_("db 75h, 1, 0C3h, 2Eh, 8Bh, 9Fh, 52h, 0E7h,...");
        _STOP_("db 89h, 44h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 4...");
        _STOP_("db 0C3h, 4, 89h, 5Ch, 10h, 0E9h, 3, 63h, 0...");
        _STOP_("db 7Dh, 0Ch, 0, 74h, 3, 0B8h, 4, 1, 0BBh, ...");
        _STOP_("db 91h, 62h, 0A1h, 90h, 91h, 29h, 44h, 16h...");
        _STOP_("db 4, 53h, 8, 0C7h, 44h, 6, 0A7h, 3Ah, 2Eh...");
        _STOP_("db 0CCh, 89h, 44h, 24h, 0C6h, 44h, 27h, 0F...");
        _STOP_("db 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, ...");
        _STOP_("db 0FAh, 0, 0BBh, 0Eh, 0CFh, 81h, 3Ch, 0, ...");
        _STOP_("db 44h, 12h, 10h, 0BBh, 24h, 0CFh, 2Eh, 8B...");
        _STOP_("db 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 44h, 0Eh, 8...");
        _STOP_("db 89h, 5Ch, 10h, 0C7h, 44h, 36h, 2 dup(0)...");
        _STOP_("db 1Ch, 14h, 0, 0C3h, 0A1h, 98h, 91h, 1, 4...");
        _STOP_("db 7Ch, 16h, 90h, 1, 7Ch, 3, 0E9h, 88h, 0,...");
        _STOP_("db 6Eh, 0A1h, 90h, 91h, 83h, 7Ch, 1Ch, 0, ...");
        _STOP_("db 44h, 16h, 3, 44h, 16h, 3Dh, 20h, 0Fh, 7...");
        _STOP_("db 44h, 1Ch, 2 dup(0FFh), 0BFh, 3Ah, 0CFh,...");
        _STOP_("db 1, 74h, 21h, 0BFh, 50h, 0CFh, 0EBh, 1Ch...");
        _STOP_("db 16h, 3, 44h, 16h, 3Dh, 30h, 0Eh, 7Fh, 2...");
        _STOP_("db 1Ch, 1, 0, 0BFh, 0Eh, 0CFh, 81h, 3Ch, 0...");
        _STOP_("db 0BFh, 24h, 0CFh, 2Eh, 8Bh, 5, 89h, 44h,...");
        _STOP_("db 45h, 2, 89h, 44h, 0Eh, 83h, 0C7h, 4, 89...");
        _STOP_("db 2Eh, 0A0h, 68h, 0CCh, 0, 44h, 48h, 73h,...");
        _STOP_("db 6Eh, 24h, 3Fh, 88h, 44h, 48h, 8Bh, 44h,...");
        _STOP_("db 0, 8Bh, 5Ch, 16h, 0B9h, 2, 0, 81h, 3Ch,...");
        _STOP_("db 0B9h, 6, 0, 2Dh, 40h, 0, 0E8h, 7, 0, 0E...");
        _STOP_("db 35h, 34h, 0C3h, 56h, 0E8h, 92h, 3Ch, 0B...");
        _STOP_("db 0E8h, 0E6h, 33h, 8Bh, 0FEh, 5Eh, 0C7h, ...");
        _STOP_("db 45h, 2, 0FAh, 0D3h, 0C7h, 45h, 4, 53h, ...");
        _STOP_("db 6, 0A7h, 3Ah, 89h, 45h, 12h, 89h, 5Dh, ...");
        _STOP_("db 1Ch, 8Bh, 0D9h, 0D1h, 0E3h, 2Eh, 8Bh, 9...");
        _STOP_("db 2Eh, 8Bh, 7, 89h, 45h, 0Ch, 2Eh, 8Bh, 4...");
        _STOP_("db 0Eh, 83h, 0C3h, 4, 89h, 5Dh, 10h, 2Eh, ...");
        _STOP_("db 89h, 45h, 24h, 0C6h, 45h, 27h, 0, 0C7h,...");
        _STOP_("db 0, 0E8h, 0ADh, 6Dh, 25h, 1Fh, 0, 89h, 4...");
        _STOP_("db 45h, 36h, 2 dup(0), 0C7h, 45h, 28h, 0E8...");
        _STOP_("db 2Ch, 0E8h, 3, 0C3h, 0E8h, 0B4h, 6Dh, 0F...");
        _STOP_("db 8Bh, 44h, 1Ah, 2Eh, 3Bh, 6, 6Ch, 0CCh, ...");
        _STOP_("db 8Bh, 0, 25h, 7, 0, 75h, 50h, 0A1h, 12h,...");
        _STOP_("db 16h, 9Fh, 2Bh, 44h, 12h, 2Bh, 5Ch, 16h,...");
        _STOP_("db 2Bh, 44h, 1Ch, 74h, 3Bh, 79h, 3, 5, 8, ...");
        _STOP_("db 1Ch, 3Dh, 4, 0, 7Ch, 0Dh, 75h, 7, 0F7h,...");
        _STOP_("db 0, 75h, 4, 83h, 6Ch, 1Ch, 2, 83h, 64h, ...");
        _STOP_("db 5Ch, 1Ch, 0D1h, 0E3h, 2Eh, 8Bh, 9Fh, 5A...");
        _STOP_("db 8Bh, 7, 89h, 44h, 0Ch, 2Eh, 8Bh, 47h, 2...");
        _STOP_("db 83h, 0C3h, 4, 89h, 5Ch");
        _STOP_("db 10h, 8Bh, 5Ch, 1Ch, 0D1h, 0E3h, 8Bh, 87...");
        _STOP_("db 1, 44h, 12h, 8Bh, 87h, 80h, 33h, 3, 6, ...");
        _STOP_("db 44h, 16h, 0E8h, 0Dh, 61h, 0E8h, 6Ch, 6E...");
        _STOP_("db 83h, 3Eh, 88h, 91h, 0, 75h, 10h, 0C7h, ...");
        _STOP_("db 8, 0B8h, 4, 0, 0E8h, 0BBh, 67h, 0E8h, 2...");
        _STOP_("db 0E8h, 5Ah, 3Ah, 0BDh, 30h, 12h, 0BAh, 5...");
        _STOP_("db 82h, 5Eh, 0E8h, 19h, 33h, 0C3h, 80h, 3E...");
        _STOP_("db 0, 74h, 3, 0E9h, 2Ah, 1, 0C6h, 6, 38h, ...");
        _STOP_("db 6, 0A6h, 91h, 0A0h, 1, 0C7h, 6, 0A2h, 9...");
        _STOP_("db 0C7h, 6, 0A4h, 91h, 0B0h, 0, 0E8h, 1Fh,...");
        _STOP_("db 9Eh, 0DAh, 0FFh, 0C6h, 6, 74h, 0D2h, 0F...");
        _STOP_("db 16h, 92h, 2 dup(0FFh), 0C7h, 6, 18h, 92...");
        _STOP_("db 0BFh, 2 dup(0), 0B9h, 78h, 0, 33h, 0C0h...");
        _STOP_("db 0B9h, 12h, 0, 0BEh, 12h, 0E5h, 0C7h, 5,...");
        _STOP_("db 45h, 2, 2 dup(0), 0C7h, 45h, 4, 2 dup(0...");
        _STOP_("db 6, 51h, 0B9h, 1Eh, 0, 2Eh, 8Ah, 4, 46h,...");
        _STOP_("db 0F9h, 59h, 0C7h, 5, 2 dup(0), 0C7h, 45h...");
        _STOP_("db 83h, 0C7h, 4, 0E2h, 0D5h, 0B9h, 2Ch, 1,...");
        _STOP_("db 0ABh, 0C7h, 6, 8Eh, 91h, 10h, 4, 0C7h, ...");
        _STOP_("db 0A0h, 1, 0C7h, 6, 0AAh, 91h, 0A0h, 1, 0...");
        _STOP_("db 0B9h, 16h, 0, 0E8h, 0E3h, 3Ah, 89h, 36h...");
        _STOP_("db 0EBh, 3, 0E8h, 0DAh, 3Ah, 57h, 0BFh, 4A...");
        _STOP_("db 3Fh, 32h, 5Fh, 2Eh, 8Bh, 5, 89h, 4, 2Eh...");
        _STOP_("db 89h, 44h, 2, 2Eh, 8Bh, 45h, 4, 89h, 44h...");
        _STOP_("db 45h, 6, 89h, 44h, 6, 2Eh, 8Bh, 5Dh, 8, ...");
        _STOP_("db 89h, 44h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 4...");
        _STOP_("db 0C3h, 4, 89h, 5Ch, 10h, 0C7h, 44h, 12h,...");
        _STOP_("db 44h, 16h, 0C0h, 0FEh, 2Eh, 8Bh, 45h, 0A...");
        _STOP_("db 30h, 2Eh, 8Bh, 45h, 0Ch, 89h, 44h, 32h,...");
        _STOP_("db 2 dup(0), 0C6h, 44h, 4Ah, 0FFh, 0C7h, 4...");
        _STOP_("db 33h, 0C0h, 2Eh, 8Ah, 45h, 0Eh, 89h, 44h...");
        _STOP_("db 45h, 0Fh, 88h, 44h, 27h, 83h, 0C7h, 10h...");
        _STOP_("db 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, ...");
        _STOP_("db 89h, 2 dup(44h), 0C7h, 44h, 36h, 2 dup(...");
        _STOP_("db 0EBh, 3, 0E9h, 6Fh, 0FFh, 0C7h, 6, 1Ah,...");
        _STOP_("db 0C3h, 0C7h, 44h, 4, 4Ch, 0D7h, 0B8h, 0F...");
        _STOP_("db 0, 8Bh, 54h, 16h, 8Bh, 4Ch, 12h, 0D1h, ...");
        _STOP_("db 12h, 0E5h, 0E8h, 6Ch, 33h, 5Eh, 0C3h, 0...");
        _STOP_("db 8Bh, 44h, 12h, 8Bh, 5Ch, 16h, 89h, 44h,...");
        _STOP_("db 2Ah, 3, 44h, 24h, 2, 5Ch, 27h, 89h, 44h...");
        _STOP_("db 2Eh, 0C3h, 0E8h, 99h, 6Bh, 0E8h, 0F2h, ...");
        _STOP_("db 5Fh, 0E8h, 0ECh, 3, 83h, 3Eh, 1Ah, 92h,...");
        _STOP_("db 5Eh, 5Fh, 0C3h, 0C7h, 6, 0AAh, 91h, 0A0...");
        _STOP_("db 90h, 91h, 0, 75h, 8, 56h, 0A1h, 9Ah, 91...");
        _STOP_("db 6Bh, 5Eh, 0A1h, 98h, 91h, 1, 44h, 16h, ...");
        _STOP_("db 0, 74h, 41h, 78h, 23h, 83h, 44h, 1Ah, 2...");
        _STOP_("db 14h, 74h, 12h, 83h, 7Ch, 1Ah, 28h, 74h,...");
        _STOP_("db 1Ah, 3Ch, 75h, 52h, 0C7h, 44h, 1Ah, 2 d...");
        _STOP_("db 0C7h, 6");
        _STOP_("db 8Ah, 8Eh, 0Ch, 0, 0C3h, 83h, 6Ch, 1Ah, ...");
        _STOP_("db 1Ah, 0ECh, 74h, 0EFh, 83h, 7Ch, 1Ah, 0D...");
        _STOP_("db 83h, 7Ch, 1Ah, 0C4h, 75h, 2Fh, 0C7h, 44...");
        _STOP_("db 0C3h, 2Eh, 0A0h, 6Eh, 0CCh, 0, 44h, 48h...");
        _STOP_("db 0F7h, 6Ah, 24h, 3Fh, 88h, 44h, 48h, 0C7...");
        _STOP_("db 2 dup(0), 0C7h, 44h, 1Ah, 2, 0, 0F7h, 6...");
        _STOP_("db 0, 75h, 5, 0C7h, 44h, 1Ah, 0FEh, 0FFh, ...");
        _STOP_("db 0CDh, 80h, 8Bh, 44h, 12h, 0A3h, 0E2h, 0...");
        _STOP_("db 0E2h, 0FCh, 77h, 0C7h, 6, 0E6h, 0FCh, 6...");
        _STOP_("db 1Ah, 0, 79h, 6, 0C7h, 6, 0E6h, 0FCh, 0F...");
        _STOP_("db 16h, 1, 6, 0E6h, 0FCh, 56h, 0E8h, 3Eh, ...");
        _STOP_("db 90h, 0E8h, 0A4h, 30h, 8Bh, 0FEh, 5Eh, 0...");
        _STOP_("db 0, 0C7h, 45h, 2, 98h, 0D7h, 0C7h, 45h, ...");
        _STOP_("db 45h, 6, 0A7h, 3Ah, 0A1h, 0E2h, 0FCh, 89...");
        _STOP_("db 0A1h, 0E6h, 0FCh, 89h, 45h, 16h, 0C7h, ...");
        _STOP_("db 0BBh, 38h, 0D0h, 2Eh, 8Bh, 7, 89h, 45h,...");
        _STOP_("db 47h, 2, 89h, 45h, 0Eh, 83h, 0C3h, 4, 89...");
        _STOP_("db 2Eh, 0A1h, 70h, 0CCh, 89h, 45h, 24h, 0C...");
        _STOP_("db 0, 0C7h, 45h, 34h, 96h, 0, 0C7h, 45h, 1...");
        _STOP_("db 45h, 36h, 2 dup(0), 0C7h, 45h, 28h, 0E8...");
        _STOP_("db 2Ch, 0E8h, 3, 0C3h, 0BAh, 55h, 0, 8Bh, ...");
        _STOP_("db 0DBh, 74h, 41h, 79h, 5, 0BAh, 0E5h, 0, ...");
        _STOP_("db 0E3h, 0FCh, 8Bh, 4Ch, 12h, 83h, 0C1h, 6...");
        _STOP_("db 56h, 53h, 51h, 52h, 0D1h, 0EBh, 2Eh, 8B...");
        _STOP_("db 2 dup(0E8h), 0FEh, 30h, 5Ah, 59h, 5Bh, ...");
        _STOP_("db 14h, 7Ch, 17h, 83h, 0FBh, 28h, 7Dh, 12h...");
        _STOP_("db 0Eh, 83h, 0C2h, 10h, 56h, 0D1h, 0EBh, 2...");
        _STOP_("db 0C0h, 2 dup(0E8h), 0DFh, 30h, 5Eh, 0C3h...");
        _STOP_("db 6Ah, 0FFh, 44h, 1Ah, 8Bh, 44h, 1Ah, 25h...");
        _STOP_("db 47h, 0A1h, 12h, 9Fh, 8Bh, 1Eh, 16h, 9Fh...");
        _STOP_("db 2Bh, 5Ch, 16h, 0E8h, 0DAh, 43h, 2Bh, 44...");
        _STOP_("db 32h, 79h, 3, 5, 8, 0, 0FFh, 44h, 1Ch, 3...");
        _STOP_("db 4, 83h, 6Ch, 1Ch, 2, 83h, 64h, 1Ch, 7, ...");
        _STOP_("db 0D1h, 0E3h, 2Eh, 8Bh, 9Fh, 0F2h, 0E8h, ...");
        _STOP_("db 89h, 44h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 4...");
        _STOP_("db 0C3h, 4, 89h, 5Ch, 10h, 8Bh, 5Ch, 1Ch, ...");
        _STOP_("db 87h, 70h, 33h, 8Bh, 9Fh, 80h, 33h, 83h,...");
        _STOP_("db 0, 75h, 4, 0D1h, 0E0h, 0D1h, 0E3h, 1, 4...");
        _STOP_("db 16h, 0E8h, 7Bh, 5Dh, 0E8h, 9Dh, 6Ah, 74...");
        _STOP_("db 3Eh, 88h, 91h, 0, 75h, 0Ch, 0C7h, 6, 4,...");
        _STOP_("db 0B8h, 4, 0, 0E8h, 29h, 64h, 0E8h, 97h, ...");
        _STOP_("db 84h, 69h, 0E8h, 0DDh, 1, 81h, 7Ch, 0Ch,...");
        _STOP_("db 41h, 83h, 7Ch, 0Eh, 1, 75h, 3Bh, 56h, 0...");
        _STOP_("db 0BFh, 96h, 90h, 0E8h, 35h, 2Fh, 8Bh, 0F...");
        _STOP_("db 5, 10h, 1, 0C7h, 45h, 2, 0F5h, 0DCh, 0C...");
        _STOP_("db 0Dh, 8Bh, 44h, 12h, 2Dh, 2, 0, 89h, 45h...");
        _STOP_("db 16h, 2Dh, 18h, 0, 89h, 45h, 16h, 0C7h, ...");
        _STOP_("db 2Eh, 0A1h, 7Ah, 0CCh, 0F7h");
        _STOP_("db 0D8h, 89h, 45h, 1Ch, 83h, 7Ch, 0Eh, 0, ...");
        _STOP_("db 7Ch, 16h, 0, 78h, 16h, 2Eh, 0A0h, 72h, ...");
        _STOP_("db 48h, 73h, 0Dh, 0E8h, 1, 69h, 24h, 3Fh, ...");
        _STOP_("db 0C7h, 44h, 0Eh, 1, 0, 0E9h, 0ECh, 5Ch, ...");
        _STOP_("db 0B9h, 8, 29h, 45h, 24h, 76h, 1, 0C3h, 0...");
        _STOP_("db 92h, 81h, 6, 52h, 91h, 0C8h, 0, 83h, 16...");
        _STOP_("db 0, 56h, 57h, 8Bh, 0F7h, 0E8h, 37h, 36h,...");
        _STOP_("db 80h, 7Dh, 27h, 0, 74h, 3, 0BDh, 4Ch, 12...");
        _STOP_("db 8, 0E8h, 56h, 5Ah, 5Fh, 5Eh, 81h, 3Dh, ...");
        _STOP_("db 8, 56h, 8Bh, 0F7h, 0E8h, 0E2h, 2Eh, 5Eh...");
        _STOP_("db 45h, 2, 6Fh, 0DBh, 0C7h, 45h, 28h, 0E8h...");
        _STOP_("db 2Ch, 0E8h, 3, 0C7h, 45h, 6, 61h, 7, 0C3...");
        _STOP_("db 44h, 0C7h, 45h, 4, 0B9h, 8, 0C7h, 47h, ...");
        _STOP_("db 29h, 47h, 24h, 76h, 1Ch, 0B8h, 0Bh, 0, ...");
        _STOP_("db 33h, 0C9h, 2Eh, 8Ah, 0Eh, 78h, 0E7h, 0F...");
        _STOP_("db 0D8h, 0D1h, 0E3h, 2Eh, 8Bh, 87h, 2, 0E9...");
        _STOP_("db 0Ch, 0C3h, 57h, 56h, 0BFh, 0E0h, 1, 33h...");
        _STOP_("db 68h, 1, 0F3h, 0ABh, 8Bh, 36h, 54h, 90h,...");
        _STOP_("db 0B9h, 9, 0, 0E8h, 0A8h, 3Ch, 0B9h, 27h,...");
        _STOP_("db 0BBh, 2 dup(0), 0BAh, 40h, 1, 0BFh, 0C0...");
        _STOP_("db 12h, 0E8h, 37h, 3Ch, 0C6h, 6, 61h, 8Fh,...");
        _STOP_("db 2 dup(0), 33h, 0C0h, 0B9h, 0Ch, 3, 0F3h...");
        _STOP_("db 5Fh, 0C3h, 80h, 3Eh, 39h, 92h, 0, 74h, ...");
        _STOP_("db 0, 0C6h, 6, 39h, 92h, 0FFh, 8Bh, 45h, 0...");
        _STOP_("db 0FCh, 83h, 2Eh, 0E6h, 0FCh, 8, 0A1h, 90...");
        _STOP_("db 6, 0E6h, 0FCh, 0BFh, 1Ah, 0E9h, 0B9h, 0...");
        _STOP_("db 95h, 36h, 89h, 36h, 0DEh, 0FCh, 0EBh, 3...");
        _STOP_("db 36h, 57h, 0BFh, 4Ah, 90h, 0E8h, 0F1h, 2...");
        _STOP_("db 8Bh, 5, 89h, 4, 2Eh, 8Bh, 45h, 2, 89h, ...");
        _STOP_("db 8Bh, 45h, 4, 89h, 44h, 4, 2Eh, 8Bh, 45h...");
        _STOP_("db 6, 2Eh, 8Bh, 45h, 8, 89h, 44h, 0Ch, 0C7...");
        _STOP_("db 2 dup(0), 0C6h, 44h, 4Ah, 0FFh, 0C7h, 4...");
        _STOP_("db 0, 0A1h, 0E6h, 0FCh, 89h, 44h, 16h, 2Eh...");
        _STOP_("db 89h, 44h, 30h, 2Eh, 8Bh, 45h, 0Ch, 89h,...");
        _STOP_("db 44h, 1Ah, 2 dup(0), 0C7h, 44h, 1Ch, 4, ...");
        _STOP_("db 45h, 0Eh, 89h, 44h, 24h, 83h, 0C7h, 10h...");
        _STOP_("db 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, ...");
        _STOP_("db 89h, 2 dup(44h), 0C7h, 44h, 36h, 2 dup(...");
        _STOP_("db 0C3h, 8Bh, 7Ch, 44h, 8Bh, 45h, 12h, 3, ...");
        _STOP_("db 44h, 12h, 8Bh, 45h, 16h, 3, 44h, 32h, 8...");
        _STOP_("db 0C3h, 0E8h, 0E7h, 0FFh, 0BBh, 0, 1, 2Bh...");
        _STOP_("db 5Ch, 1Ah, 81h, 0FBh, 0, 6, 7Ch, 4, 81h,...");
        _STOP_("db 89h, 5Ch, 1Ah, 0D1h, 0EBh, 0D1h, 0EBh, ...");
        _STOP_("db 0EBh, 0D1h, 0EBh, 0D1h, 0EBh, 0D1h, 0EB...");
        _STOP_("db 0FEh, 2Eh, 8Bh, 87h, 0BAh, 0E9h, 89h, 4...");
        _STOP_("db 31h, 5Bh, 8Bh, 5Dh, 44h, 0C7h, 47h, 4, ...");
        _STOP_("db 45h, 24h, 76h, 1, 0C3h, 57h, 56h, 8Bh, ...");
        _STOP_("db 0E8h, 0F1h, 5Ch, 0B9h, 13h, 0, 0B8h, 70...");
        _STOP_("db 8, 2Bh, 1Eh, 90h");
        _STOP_("db 91h, 0BAh, 60h, 0, 0BFh, 0A0h, 0, 0BDh,...");
        _STOP_("db 0, 3Bh, 0B9h, 4, 0, 0E8h, 56h, 3Bh, 0BF...");
        _STOP_("db 0B9h, 0Ah, 0, 33h, 0C0h, 51h, 0B9h, 8, ...");
        _STOP_("db 59h, 83h, 0C7h, 18h, 0E2h, 0F4h, 5Eh, 5...");
        _STOP_("db 91h, 0DCh, 5, 83h, 16h, 54h, 91h, 0, 0C...");
        _STOP_("db 0FFh, 8Bh, 5Ch, 16h, 3, 1Eh, 90h, 91h, ...");
        _STOP_("db 0D1h, 0E3h, 0BFh, 0C6h, 0E9h, 81h, 3Ch,...");
        _STOP_("db 3, 0BFh, 0CEh, 0E9h, 2Eh, 8Bh, 1, 89h, ...");
        _STOP_("db 0E8h, 38h, 0FFh, 0A1h, 12h, 9Fh, 2Bh, 4...");
        _STOP_("db 1Eh, 16h, 9Fh, 2Bh, 5Ch, 16h, 0E8h, 0AB...");
        _STOP_("db 44h, 1Ch, 8Bh, 0D8h, 0D1h, 0E3h, 2Eh, 8...");
        _STOP_("db 0E9h, 89h, 44h, 0Ch, 2Eh, 0A0h, 74h, 0C...");
        _STOP_("db 73h, 2Bh, 0E8h, 91h, 66h, 24h, 3Fh, 88h...");
        _STOP_("db 44h, 12h, 5, 8, 0, 8Bh, 5Ch, 16h, 83h, ...");
        _STOP_("db 4Ch, 1Ch, 2Eh, 8Bh, 2Eh, 8Ch, 0CCh, 0D1...");
        _STOP_("db 8Bh, 0AEh, 0BCh, 0EBh, 2Eh, 8Bh, 16h, 7...");
        _STOP_("db 0ABh, 43h, 0E9h, 5Eh, 5Ah, 0C7h, 45h, 4...");
        _STOP_("db 45h, 24h, 76h, 1, 0C3h, 0C7h, 45h, 2, 6...");
        _STOP_("db 45h, 28h, 0E8h, 3, 0C7h, 45h, 2Ch, 0E8h...");
        _STOP_("db 6, 61h, 7, 81h, 6, 52h, 91h, 0C8h, 0, 8...");
        _STOP_("db 91h, 0, 56h, 57h, 8Bh, 45h, 12h, 5, 8, ...");
        _STOP_("db 16h, 83h, 0C3h, 8, 0BDh, 30h, 12h, 0BAh...");
        _STOP_("db 0BAh, 57h, 5Fh, 5Eh, 0C3h, 0E8h, 9Bh, 0...");
        _STOP_("db 0Ch, 15h, 67h, 0C7h, 44h, 28h, 0E8h, 3,...");
        _STOP_("db 0E8h, 3, 0C3h, 81h, 3Eh, 0AAh, 91h, 20h...");
        _STOP_("db 0C7h, 6, 0AAh, 91h, 20h, 9, 0A1h, 98h, ...");
        _STOP_("db 16h, 83h, 7Ch, 1Ch, 0, 74h, 1Eh, 78h, 0...");
        _STOP_("db 88h, 8Eh, 2 dup(0), 0FFh, 44h, 16h, 0FF...");
        _STOP_("db 0EBh, 44h, 0C7h, 6, 88h, 8Eh, 2 dup(0),...");
        _STOP_("db 0FFh, 44h, 1Ch, 0EBh, 36h, 0E8h, 0D4h, ...");
        _STOP_("db 73h, 2Fh, 0A9h, 1, 0, 74h, 15h, 0B8h, 1...");
        _STOP_("db 16h, 2Bh, 6, 90h, 91h, 74h, 1Eh, 0E8h, ...");
        _STOP_("db 89h, 44h, 1Ch, 0EBh, 15h, 8Bh, 44h, 16h...");
        _STOP_("db 91h, 2Dh, 0D0h, 8, 74h, 9, 0E8h, 0B7h, ...");
        _STOP_("db 0D8h, 89h, 44h, 1Ch, 83h, 7Ch, 1Ah, 0, ...");
        _STOP_("db 0A0h, 78h, 0CCh, 0, 44h, 48h, 73h, 59h,...");
        _STOP_("db 24h, 3Fh, 88h, 44h, 48h, 0FFh, 44h, 1Ah...");
        _STOP_("db 9, 74h, 43h, 83h, 7Ch, 1Ah, 3, 75h, 42h...");
        _STOP_("db 6, 88h, 8Eh, 2 dup(0), 0E8h, 2, 34h, 0B...");
        _STOP_("db 0E8h, 56h, 2Bh, 8Bh, 0FEh, 5Eh, 0C7h, 5...");
        _STOP_("db 45h, 2, 0F5h, 0DCh, 0C7h, 45h, 4, 3Dh, ...");
        _STOP_("db 12h, 96h, 0, 8Bh, 44h, 16h, 5, 30h, 0, ...");
        _STOP_("db 0C7h, 45h, 1Ah, 2 dup(0), 2Eh, 0A1h, 7A...");
        _STOP_("db 45h, 1Ch, 0EBh, 5, 0C7h, 44h, 1Ah, 2 du...");
        _STOP_("db 9Ch, 0CCh, 0, 44h, 49h, 73h, 26h, 0E8h,...");
        _STOP_("db 3Fh, 88h, 44h, 49h, 0B8h, 6Eh, 0, 8Bh, ...");
        _STOP_("db 0C3h, 30h, 0B9h, 6, 0, 0E8h, 14h, 0F7h,...");
        _STOP_("db 0, 8Bh, 5Ch, 16h, 83h, 0C3h");
        _STOP_("db 30h, 0B9h, 2, 0, 0E8h, 5, 0F7h, 0C3h, 0...");
        _STOP_("db 0A2h, 0DCh, 0B8h, 6, 0, 0BBh, 6, 0, 8Bh...");
        _STOP_("db 38h, 0, 56h, 0BEh, 52h, 0EAh, 0E8h, 0C3...");
        _STOP_("db 0C3h, 0B8h, 0Ch, 0, 0F7h, 64h, 1Ah, 8Bh...");
        _STOP_("db 8Bh, 87h, 0E6h, 0E9h, 2Eh, 0A3h, 62h, 0...");
        _STOP_("db 87h, 0E8h, 0E9h, 2Eh, 0A3h, 64h, 0EAh, ...");
        _STOP_("db 0EAh, 0E9h, 2Eh, 0A3h, 6Eh, 0EAh, 2Eh, ...");
        _STOP_("db 0E9h, 2Eh, 0A3h, 70h, 0EAh, 2Eh, 8Bh, 8...");
        _STOP_("db 2Eh, 0A3h, 7Ah, 0EAh, 2Eh, 8Bh, 87h, 0F...");
        _STOP_("db 0A3h, 7Ch, 0EAh, 0B8h, 6, 0, 0BBh, 6, 0...");
        _STOP_("db 0B9h, 38h, 0, 56h, 0BEh, 52h, 0EAh, 0E8...");
        _STOP_("db 5Eh, 0C3h, 8Bh, 44h, 12h, 89h, 44h, 28h...");
        _STOP_("db 89h, 44h, 2Ch, 83h, 7Ch, 1Ah, 30h, 74h,...");
        _STOP_("db 7Ah, 0CCh, 1, 44h, 1Ah, 83h, 7Ch, 1Ah, ...");
        _STOP_("db 0C7h, 44h, 1Ah, 30h, 0, 0A1h, 98h, 91h,...");
        _STOP_("db 83h, 7Ch, 1Ch, 0, 79h, 7, 2Eh, 0A1h, 7A...");
        _STOP_("db 44h, 16h, 8Bh, 44h, 16h, 89h, 44h, 2Ah,...");
        _STOP_("db 89h, 44h, 2Eh, 0EBh, 27h, 8Bh, 44h, 1Ch...");
        _STOP_("db 8Bh, 44h, 16h, 83h, 7Ch, 1Ch, 0, 78h, 7...");
        _STOP_("db 0, 7Dh, 2Dh, 0EBh, 5, 3, 44h, 1Ah, 78h,...");
        _STOP_("db 16h, 89h, 44h, 2Ah, 3, 44h, 1Ah, 89h, 4...");
        _STOP_("db 4Ah, 65h, 74h, 18h, 83h, 3Eh, 88h, 91h,...");
        _STOP_("db 0B8h, 6, 0, 56h, 0E8h, 0DBh, 2 dup(5Eh)...");
        _STOP_("db 9Fh, 0B9h, 8, 0E8h, 42h, 2Ah, 0C3h, 8Bh...");
        _STOP_("db 8, 0, 0A3h, 0E2h, 0FCh, 0D1h, 0E8h, 0D1...");
        _STOP_("db 0E8h, 25h, 0FEh, 0, 0A3h, 0EAh, 0FCh, 8...");
        _STOP_("db 2Dh, 8, 0, 0A3h, 0E6h, 0FCh, 0D1h, 0E8h...");
        _STOP_("db 0D1h, 0E8h, 0D1h, 0E8h, 0BAh, 28h, 0, 0...");
        _STOP_("db 0EEh, 0FCh, 0BBh, 2 dup(0), 3, 1Eh, 0EA...");
        _STOP_("db 0EEh, 0FCh, 0C7h, 7, 81h, 4Eh, 0C7h, 47...");
        _STOP_("db 0C7h, 47h, 4, 2 dup(0), 0C7h, 47h, 6, 0...");
        _STOP_("db 9Ah, 0EAh, 0B9h, 3, 0, 0E8h, 4Eh, 32h, ...");
        _STOP_("db 90h, 0E8h, 0B3h, 29h, 5Fh, 2Eh, 8Bh, 5,...");
        _STOP_("db 8Bh, 45h, 2, 89h, 44h, 2, 0C7h, 44h, 4,...");
        _STOP_("db 8Bh, 45h, 4, 89h, 44h, 6, 0A1h, 0E2h, 0...");
        _STOP_("db 12h, 0A1h, 0E6h, 0FCh, 89h, 44h, 16h, 0...");
        _STOP_("db 2 dup(0), 2Eh, 0A1h, 7Ch, 0CCh, 89h, 44...");
        _STOP_("db 44h, 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h...");
        _STOP_("db 38h, 2Eh, 8Bh, 45h, 6, 83h, 0C7h, 8, 3,...");
        _STOP_("db 0E0h, 0D1h, 0E0h, 0D1h, 0E0h, 1, 6, 0E2...");
        _STOP_("db 0A3h, 0C3h, 8Bh, 5Ch, 1Ah, 83h, 0C3h, 4...");
        _STOP_("db 10h, 7Ch, 2, 33h, 0DBh, 89h, 5Ch, 1Ah, ...");
        _STOP_("db 2Eh, 8Bh, 87h, 0B2h, 0EAh, 89h, 5, 2Eh,...");
        _STOP_("db 0EAh, 89h, 45h, 2, 8Bh, 44h, 12h, 89h, ...");
        _STOP_("db 20h, 0, 89h, 44h, 2Ch, 8Bh, 44h, 16h, 2...");
        _STOP_("db 5, 2, 0, 89h, 44h, 2Ah, 5, 0Ch, 0, 89h,...");
        _STOP_("db 0FFh, 44h, 1Ah, 83h, 64h, 1Ah, 3, 8Bh, ...");
        _STOP_("db 0E0h, 8Bh, 7Ch, 38h, 0BBh, 0C2h, 0EAh, ...");
        _STOP_("db 28h, 1, 74h, 3, 0BBh, 0CAh, 0EAh, 3, 0D...");
        _STOP_("db 7, 89h, 5, 8Bh, 44h, 12h, 5, 3, 0, 89h,...");
        _STOP_("db 0Ah, 0, 89h, 44h, 2Ch, 8Bh, 44h, 16h, 2...");
        _STOP_("db 5, 3, 0, 89h, 44h, 2Ah, 5, 0Ah, 0, 89h,...");
        _STOP_("db 0C7h, 45h, 4, 70h, 0DFh, 29h, 45h, 24h,...");
        _STOP_("db 8Bh, 45h, 12h, 5, 8, 0, 8Bh, 5Dh, 16h, ...");
        _STOP_("db 91h, 83h, 0C3h, 8, 0BDh, 30h, 12h, 0BAh...");
        _STOP_("db 4Ch, 54h, 8Bh, 5Dh, 38h, 0C7h, 7, 81h, ...");
        _STOP_("db 2, 2 dup(0), 0C7h, 47h, 4, 2 dup(0), 0C...");
        _STOP_("db 37h, 8Bh, 5Dh, 0Ah, 56h, 8Bh, 0F7h, 0E8...");
        _STOP_("db 8Bh, 6Fh, 0Ah, 8Bh, 0F3h, 0E8h, 0BFh, 2...");
        _STOP_("db 0E8h, 0BAh, 28h, 5Eh, 81h, 6, 52h, 91h,...");
        _STOP_("db 16h, 54h, 91h, 0, 0C3h, 0C7h, 45h, 4, 7...");
        _STOP_("db 45h, 24h, 76h, 1, 0C3h, 8Bh, 45h, 12h, ...");
        _STOP_("db 5Dh, 16h, 2Bh, 1Eh, 90h, 91h, 83h, 0C3h...");
        _STOP_("db 12h, 0BAh, 53h, 8, 0E8h, 0EFh, 53h, 8Bh...");
        _STOP_("db 7, 41h, 37h, 0C7h, 47h, 0FCh, 2 dup(0),...");
        _STOP_("db 2 dup(0), 0C7h, 47h, 0FAh, 81h, 37h, 8B...");
        _STOP_("db 8Bh, 0F7h, 0E8h, 6Ah, 28h, 8Bh, 6Fh, 8,...");
        _STOP_("db 62h, 28h, 8Bh, 0F5h, 0E8h, 5Dh, 28h, 5E...");
        _STOP_("db 91h, 0C8h, 0, 83h, 16h, 54h, 91h, 0, 0C...");
        _STOP_("db 0EAh, 0EBh, 3, 0BFh, 0D4h, 0EAh, 0C7h, ...");
        _STOP_("db 7, 0B8h, 1, 0, 0BBh, 1, 0, 8Bh, 54h, 16...");
        _STOP_("db 90h, 91h, 8Bh, 4Ch, 12h, 0D1h, 0E9h, 56...");
        _STOP_("db 0E8h, 0CEh, 29h, 5Eh, 0C3h, 0B8h, 0F8h,...");
        _STOP_("db 0DFh, 0E8h, 89h, 55h, 0C7h, 44h, 6, 97h...");
        _STOP_("db 0A1h, 7Eh, 0CCh, 89h, 44h, 24h, 0C7h, 4...");
        _STOP_("db 3, 0C7h, 44h, 2Ch, 0E8h, 3, 8Bh, 7Ch, 3...");
        _STOP_("db 0FEh, 41h, 2Eh, 75h, 0Ah, 0C7h, 45h, 0F...");
        _STOP_("db 0C7h, 45h, 26h, 0C0h, 0Ah, 81h, 7Dh, 4,...");
        _STOP_("db 0Ah, 0C7h, 45h, 4, 0C0h, 5, 0C7h, 45h, ...");
        _STOP_("db 2Eh, 0A1h, 0D6h, 0EAh, 89h, 5, 2Eh, 0A1...");
        _STOP_("db 89h, 45h, 28h, 0C3h, 0A1h, 0AAh, 91h, 5...");
        _STOP_("db 44h, 16h, 7Dh, 3, 0E9h, 9Ch, 0, 8Bh, 44...");
        _STOP_("db 0, 89h, 44h, 28h, 5, 18h, 0, 89h, 44h, ...");
        _STOP_("db 16h, 2Bh, 6, 90h, 91h, 5, 4, 0, 89h, 44...");
        _STOP_("db 0, 89h, 44h, 2Eh, 0FFh, 44h, 1Ah, 83h, ...");
        _STOP_("db 2Eh, 0A0h, 90h, 0CCh, 0, 44h, 48h, 73h,...");
        _STOP_("db 61h, 24h, 3Fh, 88h, 44h, 48h, 0B9h, 7, ...");
        _STOP_("db 12h, 5, 10h, 0, 8Bh, 5Ch, 16h, 2Bh, 1Eh...");
        _STOP_("db 0C3h, 10h, 2Eh, 8Bh, 16h, 92h, 0CCh, 0E...");
        _STOP_("db 0BDh, 0A8h, 0D0h, 2Eh, 8Bh, 46h, 0, 89h...");
        _STOP_("db 8Bh, 46h, 2, 89h, 45h, 0Eh, 83h, 0C5h, ...");
        _STOP_("db 10h, 49h, 79h, 0CEh, 8Bh, 7Ch, 38h, 8Bh...");
        _STOP_("db 0E3h, 0Eh, 0D1h, 0E3h, 0D1h, 0E3h, 2Eh,...");
        _STOP_("db 0EAh, 89h, 5, 2Eh, 8Bh, 87h, 0D8h, 0EAh...");
        _STOP_("db 2Eh, 8Bh, 87h, 0DAh, 0EAh, 89h, 45h");
        _STOP_("db 28h, 2Eh, 8Bh, 87h, 0DCh, 0EAh, 89h, 45...");
        _STOP_("db 0E8h, 2Ah, 27h, 0C3h, 0C7h, 45h, 4, 6, ...");
        _STOP_("db 24h, 76h, 1, 0C3h, 8Bh, 45h, 12h, 5, 10...");
        _STOP_("db 16h, 2Bh, 1Eh, 90h, 91h, 83h, 0C3h, 10h...");
        _STOP_("db 12h, 0BAh, 53h, 8, 0E8h, 6Bh, 52h, 8Bh,...");
        _STOP_("db 7Fh, 0FEh, 0C0h, 5, 75h, 0Ah, 0C7h, 47h...");
        _STOP_("db 2Eh, 0C7h, 47h, 26h, 0C1h, 32h, 81h, 7F...");
        _STOP_("db 75h, 0Ah, 0C7h, 47h, 4, 81h, 2Eh, 0C7h,...");
        _STOP_("db 33h, 0C7h, 7, 2 dup(0), 0C7h, 47h, 2, 2...");
        _STOP_("db 47h, 28h, 2 dup(0), 0C7h, 47h, 2Ah, 2 d...");
        _STOP_("db 52h, 91h, 0F4h, 1, 83h, 16h, 54h, 91h, ...");
        _STOP_("db 0F7h, 0E8h, 0BCh, 26h, 5Eh, 0C3h, 0C7h,...");
        _STOP_("db 7, 0B8h, 2, 0, 0BBh, 2, 0, 8Bh, 54h, 16...");
        _STOP_("db 90h, 91h, 8Bh, 4Ch, 12h, 0D1h, 0E9h, 56...");
        _STOP_("db 0EAh, 0E8h, 3Fh, 28h, 5Eh, 0C3h, 8Bh, 5...");
        _STOP_("db 3Ah, 92h, 0, 75h, 7, 53h, 0E8h, 4, 0, 8...");
        _STOP_("db 0C3h, 0B8h, 0F4h, 0, 0BBh, 0B0h, 0E1h, ...");
        _STOP_("db 53h, 8Bh, 45h, 0Ch, 89h, 44h, 1Ch, 0C7h...");
        _STOP_("db 0E2h, 2Eh, 0A1h, 80h, 0CCh, 89h, 44h, 2...");
        _STOP_("db 28h, 0E8h, 3, 0C7h, 44h, 2Ch, 0E8h, 3, ...");
        _STOP_("db 8Bh, 5Ch, 1Ch, 0C7h, 44h, 22h, 2 dup(0F...");
        _STOP_("db 0D1h, 0E3h, 0D1h, 0E3h, 81h, 7Dh, 0FEh,...");
        _STOP_("db 0Ah, 0C7h, 45h, 0FEh, 41h, 6, 0C7h, 45h...");
        _STOP_("db 81h, 7Dh, 4, 1, 2Fh, 75h, 0Ah, 0C7h, 45...");
        _STOP_("db 0C7h, 45h, 2Ch, 41h, 17h, 2Eh, 8Bh, 87h...");
        _STOP_("db 89h, 5, 2Eh, 8Bh, 87h, 18h, 0EBh, 89h, ...");
        _STOP_("db 8Bh, 87h, 1Ah, 0EBh, 89h, 45h, 28h, 2Eh...");
        _STOP_("db 0EBh, 89h, 45h, 2Ah, 0C3h, 0A1h, 0AAh, ...");
        _STOP_("db 0, 3Bh, 44h, 16h, 7Dh, 3, 0E9h, 0FDh, 0...");
        _STOP_("db 5, 4, 0, 89h, 44h, 28h, 5, 18h, 0, 89h,...");
        _STOP_("db 44h, 16h, 2Bh, 6, 90h, 91h, 5, 4, 0, 89...");
        _STOP_("db 5, 18h, 0, 89h, 44h, 2Eh, 83h, 7Ch, 1Ah...");
        _STOP_("db 8Bh, 44h, 16h, 2Bh, 6, 90h, 91h, 3Dh, 0...");
        _STOP_("db 3, 0E9h, 9Ah, 0, 83h, 7Ch, 1Ah, 8, 74h,...");
        _STOP_("db 1Ah, 0FFh, 44h, 1Ch, 83h, 64h, 1Ch, 7, ...");
        _STOP_("db 0A1h, 12h, 9Fh, 2Bh, 44h, 12h, 2Dh, 10h...");
        _STOP_("db 16h, 9Fh, 2Bh, 5Ch, 16h, 3, 1Eh, 90h, 9...");
        _STOP_("db 10h, 0E8h, 6Eh, 39h, 2Bh, 44h, 1Ch, 74h...");
        _STOP_("db 0, 3Dh, 4, 0, 7Dh, 5, 0FFh, 44h, 1Ch, 0...");
        _STOP_("db 4Ch, 1Ch, 83h, 64h, 1Ch, 7, 2Eh, 0A0h, ...");
        _STOP_("db 44h, 48h, 73h, 4Bh, 0E8h, 4Ah, 5Fh, 24h...");
        _STOP_("db 48h, 8Bh, 44h, 12h, 5, 10h, 0, 8Bh, 5Ch...");
        _STOP_("db 90h, 91h, 83h, 0C3h, 10h, 8Bh, 4Ch, 1Ch...");
        _STOP_("db 0D1h, 0E5h, 0D1h, 0E5h, 83h, 0E5h, 1Ch,...");
        _STOP_("db 56h, 0EBh, 2Eh, 3, 9Eh, 58h, 0EBh, 83h,...");
        _STOP_("db 6, 9Ch, 91h, 1, 0, 75h, 3, 83h, 0C5h, 1...");
        _STOP_("db 2Eh, 8Bh, 0AEh, 76h, 0EBh, 2Eh, 8Bh, 16...");
        _STOP_("db 0E8h, 44h, 3Ch");
        _STOP_("db 8Bh, 7Ch, 38h, 8Bh, 5Ch, 1Ch, 0D1h, 0E3...");
        _STOP_("db 0D1h, 0E3h, 2Eh, 8Bh, 87h, 16h, 0EBh, 8...");
        _STOP_("db 87h, 18h, 0EBh, 89h, 45h, 2, 2Eh, 8Bh, ...");
        _STOP_("db 89h, 45h, 28h, 2Eh, 8Bh, 87h, 1Ch, 0EBh...");
        _STOP_("db 0C3h, 0E8h, 2, 25h, 0C3h, 0C7h, 45h, 4,...");
        _STOP_("db 45h, 24h, 76h, 1, 0C3h, 8Bh, 5Dh, 22h, ...");
        _STOP_("db 5, 0C6h, 87h, 3Ah, 92h, 0FFh, 8Bh, 45h,...");
        _STOP_("db 0, 8Bh, 5Dh, 16h, 2Bh, 1Eh, 90h, 91h, 8...");
        _STOP_("db 0BDh, 4Ch, 12h, 0BAh, 53h, 8, 0E8h, 37h...");
        _STOP_("db 38h, 81h, 7Fh, 0FEh, 41h, 6, 75h, 0Ah, ...");
        _STOP_("db 0C1h, 2Eh, 0C7h, 47h, 26h, 41h, 33h, 81...");
        _STOP_("db 12h, 75h, 0Ah, 0C7h, 47h, 4, 1, 2Fh, 0C...");
        _STOP_("db 81h, 33h, 0C7h, 7, 2 dup(0), 0C7h, 47h,...");
        _STOP_("db 0C7h, 47h, 28h, 2 dup(0), 0C7h, 47h, 2A...");
        _STOP_("db 81h, 6, 52h, 91h, 90h, 1, 83h, 16h, 54h...");
        _STOP_("db 8Bh, 0F7h, 0E8h, 88h, 24h, 5Eh, 0C3h, 0...");
        _STOP_("db 61h, 7, 0B8h, 2, 0, 0BBh, 2, 0, 8Bh, 54...");
        _STOP_("db 16h, 90h, 91h, 8Bh, 4Ch, 12h, 0D1h, 0E9...");
        _STOP_("db 16h, 0EBh, 0E8h, 0Bh, 26h, 5Eh, 0C3h, 0...");
        _STOP_("db 7Dh, 0Ch, 0, 74h, 3, 0B8h, 0Ch, 1, 0BBh...");
        _STOP_("db 0E8h, 0BDh, 51h, 0C7h, 44h, 6, 76h, 3Bh...");
        _STOP_("db 86h, 0CCh, 89h, 44h, 24h, 0C7h, 44h, 28...");
        _STOP_("db 44h, 2Ch, 0E8h, 3, 8Bh, 5Ch, 38h, 0BDh,...");
        _STOP_("db 0A6h, 0EBh, 83h, 7Dh, 0Ch, 0, 74h, 6, 0...");
        _STOP_("db 0BAh, 0A8h, 0EBh, 89h, 6Ch, 0Ch, 89h, 5...");
        _STOP_("db 8Bh, 46h, 0, 89h, 7, 0C7h, 44h, 34h, 64...");
        _STOP_("db 30h, 2 dup(0), 0C7h, 44h, 32h, 2 dup(0)...");
        _STOP_("db 0AAh, 91h, 5, 0D0h, 0, 3Bh, 44h, 16h, 7...");
        _STOP_("db 0B0h, 0, 8Bh, 44h, 12h, 5, 2, 0, 89h, 4...");
        _STOP_("db 0, 89h, 44h, 2Ch, 8Bh, 44h, 16h, 2Bh, 6...");
        _STOP_("db 2, 0, 89h, 44h, 2Ah, 5, 0Ch, 0, 89h, 44...");
        _STOP_("db 7Ch, 1Ah, 0, 75h, 11h, 2Eh, 0A0h, 88h, ...");
        _STOP_("db 48h, 73h, 37h, 0E8h, 9Ch, 5Dh, 24h, 3Fh...");
        _STOP_("db 0FFh, 44h, 1Ah, 8Bh, 44h, 1Ah, 0D1h, 0E...");
        _STOP_("db 0EBh, 81h, 3Ch, 8, 1, 74h, 3, 0BBh, 86h...");
        _STOP_("db 8Bh, 7Ch, 38h, 2Eh, 8Bh, 7, 89h, 5, 83h...");
        _STOP_("db 74h, 0Ch, 83h, 7Ch, 1Ah, 7, 75h, 5, 0C7...");
        _STOP_("db 2 dup(0), 0C3h, 8Bh, 44h, 12h, 8Bh, 5Ch...");
        _STOP_("db 90h, 91h, 5, 18h, 0, 83h, 0C3h, 8, 0B9h...");
        _STOP_("db 3Ch, 8, 1, 74h, 6, 0B9h, 6, 0, 2Dh, 18h...");
        _STOP_("db 16h, 8Ah, 0CCh, 0E8h, 82h, 3Ah, 0BBh, 0...");
        _STOP_("db 3Ch, 8, 1, 74h, 3, 0BBh, 0CCh, 0D0h, 2E...");
        _STOP_("db 45h, 0Ch, 2Eh, 8Bh, 47h, 2, 89h, 45h, 0...");
        _STOP_("db 4, 89h, 5Dh, 10h, 0C3h, 0E8h, 4Ch, 23h,...");
        _STOP_("db 0E3h, 2Eh, 0FFh, 0A7h, 0AAh, 0EBh, 0BBh...");
        _STOP_("db 0E9h, 7, 4Fh, 0BBh, 0B0h, 0CCh, 0E9h, 1...");
        _STOP_("db 0C2h, 0CCh, 0E9h, 0FBh, 4Eh, 0BBh, 0D4h...");
        _STOP_("db 0F5h, 4Eh, 0BBh, 0E6h");
        _STOP_("db 0CCh, 0E9h, 0EFh, 4Eh, 0BBh, 0F8h, 0CCh...");
        _STOP_("db 4Eh, 0BBh, 0Ah, 0CDh, 0E9h, 0E3h, 4Eh, ...");
        _STOP_("db 0E9h, 0DDh, 4Eh, 33h, 0C0h, 0C3h, 0C7h,...");
        _STOP_("db 2 dup(0), 0C7h, 6, 0AAh, 91h, 0FFh, 11h...");
        _STOP_("db 8Eh, 70h, 17h, 0C7h, 6, 0AEh, 8Eh, 70h,...");
        _STOP_("db 38h, 92h, 0, 0C6h, 6, 39h, 92h, 0, 0C7h...");
        _STOP_("db 0, 12h, 0C7h, 6, 18h, 92h, 0A0h, 11h, 2...");
        _STOP_("db 0CCh, 2Eh, 0A2h, 78h, 0E7h, 2Eh, 0A1h, ...");
        _STOP_("db 0A3h, 78h, 0E9h, 0C6h, 6, 3Ah, 92h, 0, ...");
        _STOP_("db 92h, 0, 0B8h, 0Ch, 0, 0F7h, 26h, 1Ah, 9...");
        _STOP_("db 8Eh, 0B8h, 0Eh, 0, 0F7h, 26h, 1Ah, 99h,...");
        _STOP_("db 0C7h, 6, 72h, 8Eh, 0F5h, 98h, 0C3h, 0Ah...");
        _STOP_("db 41h, 50h, 81h, 50h, 0C1h, 50h, 1, 51h, ...");
        _STOP_("db 51h, 81h, 51h, 0C1h, 51h, 0, 52h, 41h, ...");
        _STOP_("db 0C1h, 52h, 1, 53h, 41h, 53h, 6 dup(0), ...");
        _STOP_("db 0C1h, 53h, 1, 54h, 40h, 54h, 80h, 54h, ...");
        _STOP_("db 55h, 40h, 55h, 81h, 55h, 0C1h, 55h, 4 d...");
        _STOP_("db 41h, 56h, 6 dup(0), 81h, 56h, 0C0h, 56h...");
        _STOP_("db 57h, 80h, 57h, 0C0h, 57h, 1, 58h, 6 dup...");
        _STOP_("db 81h, 58h, 2 dup(0), 0C1h, 58h, 1, 59h, ...");
        _STOP_("db 59h, 0C0h, 59h, 0, 5Ah, 40h, 5Ah, 80h, ...");
        _STOP_("db 1, 5Bh, 41h, 5Bh, 2 dup(0), 81h, 5Bh, 0...");
        _STOP_("db 5Ch, 41h, 5Ch, 81h, 5Ch, 0C1h, 5Ch, 0, ...");
        _STOP_("db 80h, 5Dh, 0C0h, 5Dh, 0, 5Eh, 41h, 5Eh, ...");
        _STOP_("db 5Eh, 1, 5Fh, 41h, 5Fh, 81h, 5Fh, 0C0h, ...");
        _STOP_("db 40h, 60h, 80h, 60h, 0C0h, 60h, 0, 61h, ...");
        _STOP_("db 61h, 0C0h, 61h, 0, 62h, 40h, 62h, 80h, ...");
        _STOP_("db 1, 63h, 41h, 63h, 81h, 63h, 0C1h, 63h, ...");
        _STOP_("db 64h, 80h, 64h, 0, 67h, 40h, 67h, 80h, 6...");
        _STOP_("db 0C0h, 65h, 1, 66h, 41h, 66h, 81h, 66h, ...");
        _STOP_("db 1, 68h, 41h, 68h, 81h, 68h, 80h, 6Ah, 0...");
        _STOP_("db 6Bh, 41h, 6Bh, 0C1h, 69h, 1, 6Ah, 10h d...");
        _STOP_("db 0C0h, 6Bh, 0, 6Ch, 40h, 6Ch, 81h, 6Ch, ...");
        _STOP_("db 51h, 0C1h, 6Ch, 1, 6Dh, 40h, 6Dh, 80h, ...");
        _STOP_("db 1, 6Eh, 41h, 6Eh, 41h, 53h, 6 dup(0), 8...");
        _STOP_("db 0C1h, 53h, 81h, 6Eh, 0C0h, 6Eh, 0, 6Fh,...");
        _STOP_("db 6Fh, 0C0h, 6Fh, 1, 70h, 0C1h, 55h, 4 du...");
        _STOP_("db 41h, 56h, 6 dup(0), 81h, 56h, 0C0h, 56h...");
        _STOP_("db 57h, 80h, 57h, 0C0h, 57h, 1, 58h, 6 dup...");
        _STOP_("db 81h, 58h, 2 dup(0), 0C1h, 58h, 1, 59h, ...");
        _STOP_("db 59h, 0C0h, 59h, 0, 5Ah, 40h, 5Ah, 80h, ...");
        _STOP_("db 1, 5Bh, 41h, 5Bh, 2 dup(0), 81h, 5Bh, 0...");
        _STOP_("db 5Ch, 41h, 5Ch, 81h, 5Ch, 0C1h, 5Ch, 0, ...");
        _STOP_("db 80h, 5Dh, 0C0h, 5Dh, 0, 5Eh, 41h, 5Eh, ...");
        _STOP_("db 5Eh, 1, 5Fh, 41h, 5Fh, 81h, 5Fh, 0C0h, ...");
        _STOP_("db 40h, 60h, 80h, 60h, 0C0h, 60h, 0, 61h, ...");
        _STOP_("db 61h, 0C0h, 61h, 0, 62h, 40h, 62h, 80h, ...");
        _STOP_("db 1, 63h, 41h, 63h, 81h, 63h, 0C1h, 63h, ...");
        _STOP_("db 64h, 80h, 64h, 0C1h, 64h, 0");
        _STOP_("db 65h, 41h, 65h, 80h, 65h, 0C0h, 65h, 1, ...");
        _STOP_("db 81h, 66h, 0C1h, 66h, 6 dup(0), 1, 68h, ...");
        _STOP_("db 68h, 0C1h, 68h, 1, 69h, 41h, 69h, 81h, ...");
        _STOP_("db 1, 6Ah, 6 dup(0), 0CEh, 35h, 7Fh, 0DDh,...");
        _STOP_("db 0E1h, 97h, 0DFh, 63h, 0D9h, 0A8h, 0D4h,...");
        _STOP_("db 86h, 0D2h, 26h, 0E1h, 0BAh, 0CEh, 0C8h,...");
        _STOP_("db 0CEh, 0E4h, 0CEh, 0F2h, 0CEh, 0, 0CFh, ...");
        _STOP_("db 0CEh, 82h, 0CEh, 90h, 0CEh, 82h, 0CEh, ...");
        _STOP_("db 0CFh, 74h, 0CFh, 82h, 0CFh, 90h, 0CFh, ...");
        _STOP_("db 0CFh, 0BAh, 0CFh, 0C8h, 0CFh, 34h, 1, 2...");
        _STOP_("db 0D7h, 61h, 7, 0D6h, 0CFh, 4 dup(0), 14h...");
        _STOP_("db 0F9h, 0D5h, 61h, 7, 99h, 3Ah, 0D6h, 0CF...");
        _STOP_("db 0E0h, 0, 0F0h, 10h, 44h, 1, 0F9h, 0D5h,...");
        _STOP_("db 3Ah, 0D6h, 0CFh, 2 dup(0), 50h, 0, 0F0h...");
        _STOP_("db 0D2h, 0DAh, 53h, 8, 9Dh, 0D8h, 0DAh, 0C...");
        _STOP_("db 0, 1Eh, 0, 14h, 1, 0D2h, 0DAh, 53h, 8, ...");
        _STOP_("db 0CFh, 9Ah, 0, 3Ah, 0, 1Eh, 0, 14h, 1, 0...");
        _STOP_("db 8, 9Dh, 0D8h, 0DAh, 0CFh, 3Fh, 0, 6Ch, ...");
        _STOP_("db 1, 0D2h, 0DAh, 53h, 8, 9Dh, 0D8h, 0DAh,...");
        _STOP_("db 0, 6Ch, 0, 1Eh, 0, 14h, 1, 0D2h, 0DAh, ...");
        _STOP_("db 0D8h, 0DAh, 0CFh, 48h, 0, 0C5h, 0, 1Eh,...");
        _STOP_("db 0DAh, 53h, 8, 9Dh, 0D8h, 0DAh, 0CFh, 9A...");
        _STOP_("db 1Eh, 0, 14h, 1, 0D2h, 0DAh, 53h, 8, 9Dh...");
        _STOP_("db 0CFh, 3Fh, 0, 0FCh, 0, 1Eh, 0, 14h, 1, ...");
        _STOP_("db 8, 9Dh, 0D8h, 0DAh, 0CFh, 0A2h, 0, 0FCh...");
        _STOP_("db 3Ch, 1, 2Ah, 0D8h, 53h, 8, 9Dh, 0D8h, 0...");
        _STOP_("db 0, 4Dh, 0, 0Ah, 0FFh, 3Ch, 1, 2Ah, 0D8h...");
        _STOP_("db 0D8h, 0E2h, 0CFh, 0BCh, 0, 4Dh, 0, 0Ah,...");
        _STOP_("db 2Ah, 0D8h, 53h, 8, 9Dh, 0D8h, 0E2h, 0CF...");
        _STOP_("db 0, 0Ah, 0FFh, 3Ch, 1, 2Ah, 0D8h, 53h, 8...");
        _STOP_("db 0E2h, 0CFh, 0BDh, 0, 0DDh, 0, 0Ah, 0FFh...");
        _STOP_("db 0D6h, 53h, 8, 9Dh, 0D8h, 0FCh, 0CFh, 3E...");
        _STOP_("db 5, 0, 40h, 1, 15h, 0D6h, 53h, 8, 9Dh, 0...");
        _STOP_("db 0AEh, 0, 12h, 0, 5, 0, 40h, 1, 15h, 0D6...");
        _STOP_("db 0D8h, 0FCh, 0CFh, 3Eh, 0, 0A2h, 0, 5, 0...");
        _STOP_("db 0D6h, 53h, 8, 9Dh, 0D8h, 0FCh, 0CFh, 0A...");
        _STOP_("db 0, 5, 0, 38h, 1, 15h, 0D6h, 53h, 8, 9Dh...");
        _STOP_("db 0D0h, 50h, 0, 19h, 1, 28h, 0FFh, 38h, 1...");
        _STOP_("db 53h, 8, 9Dh, 0D8h, 22h, 0D0h, 8Ah, 0, 1...");
        _STOP_("db 50h, 0, 1Eh, 0D6h, 53h, 8, 0F5h, 0D8h, ...");
        _STOP_("db 0, 0Fh, 1, 14h, 0FFh, 8Dh, 92h, 15h, 93...");
        _STOP_("db 25h, 94h, 0ADh, 94h, 0C5h, 67h, 55h, 6A...");
        _STOP_("db 75h, 6Fh, 5, 72h, 5, 72h, 5, 72h, 5, 72...");
        _STOP_("db 72h, 5, 72h, 75h, 6Fh, 0E5h, 6Ch, 55h, ...");
        _STOP_("db 38h, 0D0h, 46h, 0D0h, 54h, 0D0h, 62h, 0...");
        _STOP_("db 7Eh, 0D0h, 8Ch, 0D0h, 9Ah, 0D0h, 41h, 0...");
        _STOP_("db 0E1h, 0AFh, 31h, 0AFh, 81h, 0AEh, 0D1h,...");
        _STOP_("db 71h, 0ACh, 0C1h, 0ABh, 11h, 0ABh, 61h, ...");
        _STOP_("db 0FCh, 0, 82h, 0DBh, 0A2h, 0DCh, 61h, 7,...");
        _STOP_("db 1, 0D2h, 0DAh, 53h, 8, 2Bh, 0DBh, 55h, ...");
        _STOP_("db 28h, 0, 28h, 0, 14h, 1, 0D2h, 0DAh, 53h...");
        _STOP_("db 55h, 64h, 10h, 0, 38h, 0, 28h, 0, 14h, ...");
        _STOP_("db 53h, 8, 2Bh, 0DBh, 55h, 64h, 38h, 0, 38...");
        _STOP_("db 14h, 1, 0D2h, 0DAh, 53h, 8, 2Bh, 0DBh, ...");
        _STOP_("db 0, 28h, 0, 28h, 0, 20h, 1, 23h, 0DAh, 5...");
        _STOP_("db 0FDh, 78h, 28h, 0, 3Bh, 0, 0C8h, 0, 1Ch...");
        _STOP_("db 53h, 8, 61h, 7, 55h, 77h, 1, 5 dup(0), ...");
        _STOP_("db 0DAh, 53h, 8, 61h, 7, 55h, 77h, 48h, 5 ...");
        _STOP_("db 1, 0B0h, 0DAh, 53h, 8, 61h, 7, 95h, 74h...");
        _STOP_("db 3 dup(0), 18h, 1, 0B0h, 0DAh, 53h, 8, 6...");
        _STOP_("db 48h, 0, 48h, 3 dup(0), 0FDh, 78h, 35h, ...");
        _STOP_("db 0A5h, 79h, 6Dh, 79h, 35h, 79h, 95h, 74h...");
        _STOP_("db 75h, 0A5h, 76h, 93h, 78h, 29h, 78h, 0BF...");
        _STOP_("db 77h, 95h, 61h, 45h, 62h, 0F5h, 62h, 0A5...");
        _STOP_("db 64h, 5, 65h, 0B5h, 2 dup(65h), 66h, 0C0...");
        _STOP_("db 0C0h, 27h, 0, 28h, 40h, 2Bh, 80h, 2Bh, ...");
        _STOP_("db 2Ch, 0C0h, 30h, 0, 31h, 40h, 35h, 80h, ...");
        _STOP_("db 80h, 2Ch, 0C0h, 30h, 0, 31h, 40h, 35h, ...");
        _STOP_("db 2Ch, 0, 2Dh, 40h, 31h, 80h, 31h, 0C0h, ...");
        _STOP_("db 0C0h, 2Ch, 0, 2Dh, 40h, 31h, 80h, 31h, ...");
        _STOP_("db 36h, 40h, 2Dh, 80h, 2Dh, 0C0h, 31h, 0, ...");
        _STOP_("db 80h, 36h, 40h, 2Dh, 80h, 2Dh, 0C0h, 31h...");
        _STOP_("db 36h, 80h, 36h, 0C0h, 2Dh, 0, 2Eh, 40h, ...");
        _STOP_("db 0C0h, 36h, 0, 37h, 0C0h, 2Dh, 0, 2Eh, 4...");
        _STOP_("db 32h, 0C0h, 36h, 0, 37h, 41h, 1Eh, 81h, ...");
        _STOP_("db 1, 1Fh, 41h, 1Fh, 81h, 1Fh, 40h, 23h, 8...");
        _STOP_("db 23h, 0, 24h, 40h, 24h, 80h, 24h, 40h, 2...");
        _STOP_("db 0C0h, 27h, 0, 28h, 40h, 28h, 80h, 28h, ...");
        _STOP_("db 2Bh, 40h, 2Bh, 80h, 2Bh, 0C0h, 2Bh, 0, ...");
        _STOP_("db 80h, 2Fh, 0C1h, 2Fh, 1, 30h, 40h, 30h, ...");
        _STOP_("db 33h, 1, 34h, 41h, 34h, 81h, 34h, 0C1h, ...");
        _STOP_("db 28h, 1, 71h, 0DEh, 0B6h, 0DEh, 2, 0, 30...");
        _STOP_("db 61h, 7, 4, 0, 2Ch, 1, 71h, 0DEh, 13h, 0...");
        _STOP_("db 1, 4Dh, 1, 4Dh, 41h, 4Dh, 41h, 4Dh, 1, ...");
        _STOP_("db 1, 4Ch, 41h, 4Ch, 81h, 4Ch, 0C1h, 4Ch, ...");
        _STOP_("db 4Dh, 1, 4Eh, 41h, 4Eh, 1, 4Ch, 81h, 4Dh...");
        _STOP_("db 80h, 2 dup(40h), 44h, 80h, 44h, 0C0h, 4...");
        _STOP_("db 44h, 0, 45h, 40h, 41h, 80h, 41h, 40h, 4...");
        _STOP_("db 0C0h, 41h, 0, 42h, 0C0h, 45h, 0, 46h, 4...");
        _STOP_("db 42h, 40h, 46h, 80h, 46h, 0C0h, 42h, 0, ...");
        _STOP_("db 0, 47h, 40h, 43h, 80h, 43h, 40h, 47h, 8...");
        _STOP_("db 43h, 0, 44h, 0C0h, 47h, 0, 48h, 40h, 38...");
        _STOP_("db 41h, 3Ch, 80h, 3Ch, 0C0h, 38h, 0, 39h, ...");
        _STOP_("db 3Dh, 40h, 39h, 80h, 39h, 40h, 3Dh");
        _STOP_("db 80h, 3Dh, 0C0h, 39h, 0, 3Ah, 0C0h, 3Dh,...");
        _STOP_("db 3Ah, 80h, 3Ah, 40h, 3Eh, 80h, 3Eh, 0C0h...");
        _STOP_("db 0C0h, 3Eh, 0, 3Fh, 40h, 3Bh, 80h, 3Bh, ...");
        _STOP_("db 3Fh, 0C0h, 3Bh, 1, 3Ch, 0C0h, 3Fh, 1, 4...");
        _STOP_("db 0F5h, 0FFh, 7, 0, 0F9h, 0FFh, 0Eh, 0, 0...");
        _STOP_("db 0, 6, 3 dup(0), 0Bh, 0, 0F9h, 0FFh, 7, ...");
        _STOP_("db 2 dup(0), 0F9h, 0FFh, 0F9h, 0FFh, 35h, ...");
        _STOP_("db 96h, 69h, 96h, 0FBh, 96h, 5Bh, 97h, 0ED...");
        _STOP_("db 98h, 81h, 48h, 0C1h, 48h, 1, 49h, 41h, ...");
        _STOP_("db 0C1h, 49h, 1, 4Ah, 81h, 48h, 41h, 4Ah, ...");
        _STOP_("db 4Ah, 1, 4Bh, 41h, 4Bh, 81h, 4Bh, 0C1h, ...");
        _STOP_("db 1, 38h, 0C1h, 37h, 60h, 33h, 7Ch, 0E4h,...");
        _STOP_("db 0E4h, 8Eh, 0E4h, 94h, 0E4h, 9Ah, 0E4h, ...");
        _STOP_("db 0E4h, 0C1h, 98h, 0F5h, 98h, 36h, 68h, 5...");
        return;
    } while (1);
}
function* sub_1EBD0() {
    memory[ds*16+0x8F52] = 0x00;
    yield* loc_1EBDC();
}
function* loc_1EBD7() {
    memory[ds*16+0x8F52] = 0xff;
    yield* loc_1EBDC();
}
function* loc_1EBDC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = 0xa000;
        es = bp;
    case 0x1EBE1:
        if (r16s[dx] > signed16(0xfff0)) {
            pc = 0x1EBF2;
            break;
        }
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1EBE1;
            break;
        }
        pc = 0x1EC6A;
        break;
    case 0x1EBF2:
        r16[di] = memory16get(ds*16+0x425B);
        bp = r16[di];
        bp += 0x1ba8;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[di] += r16[cx];
        r16[cx] = r16[ax];
        if (r16s[dx] >= 0) {
            pc = 0x1EC21;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
    case 0x1EC0A:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[cx] += r16[dx];
        yield* sub_1EC6F();
        r16[di] += 0x0002;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EC0A;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] == 0) {
            pc = 0x1EC6A;
            break;
        }
    case 0x1EC21:
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[di] += r16[ax];
    case 0x1EC28:
        if (r16s[di] >= signed16(bp)) {
            pc = 0x1EC48;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
    case 0x1EC2E:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1EC6F();
        r16[di] += 0x0002;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EC2E;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[di] += 0x0280;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1EC28;
            break;
        }
        pc = 0x1EC6A;
        break;
    case 0x1EC48:
        push(r16[di]);
        r16[di] -= bp;
        r16[ax] = r16[di];
        r16[di] = pop();
        r16[dx] = r16[dx] ^ r16[dx];
        bp = 0x0028;
        div(bp);
        r16[ax] -= 0x000f;
        r16[ax] = -r16[ax];
        if (r16s[ax]<=0) {
            pc = 0x1EC6A;
            break;
        }
    case 0x1EC5C:
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1EC6F();
        r16[di] += 0x0002;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EC5C;
            break;
        }
    case 0x1EC6A:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_1EC6F() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (r16[ax] != 0) {
            pc = 0x1EC7D;
            break;
        }
        pc = 0x1EDCF;
        break;
    case 0x1EC7D:
        if (flags.carry) {
            pc = 0x1ECD8;
            break;
        }
        if (memory[ds*16+0x8F52] == 0x00) {
            pc = 0x1ECAE;
            break;
        }
        push(r16[dx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        push(r16[cx]);
    case 0x1EC94:
        memoryVideoSet(es, r16[di], r8[al]);
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1EC94;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[dx] = pop();
        pc = 0x1EDCF;
        break;
    case 0x1ECAE:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        push(r16[dx]);
        push(ds);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[ax] = 0xa400;
        ds = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
    case 0x1ECC5:
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += 0x0026;
        if (--r16[cx]) {
            pc = 0x1ECC5;
            break;
        }
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        pc = 0x1EDCF;
        break;
    case 0x1ECD8:
        if (memory[ds*16+0x8F52] == 0x00) {
            pc = 0x1ED27;
            break;
        }
        push(r16[dx]);
        push(r16[si]);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] += 0x5538;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        push(r16[di]);
        push(r16[cx]);
    case 0x1ECFC:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        r8[ah] = memoryVideoGet(es, r16[di] + 1);
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ECFC;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] -= 1;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[si] = pop();
        r16[dx] = pop();
        pc = 0x1EDCF;
        break;
    case 0x1ED27:
        push(r16[cx]);
        push(r16[dx]);
        push(r16[si]);
        push(r16[di]);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        r16[si] += 0x5538;
    case 0x1ED43:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        memoryVideoAnd(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ED43;
            break;
        }
        r16[dx] -= 1;
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x1003;
        out16(r16[dx], r16[ax]);
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        push(ds);
        r16[ax] = 0xa400;
        ds = r16[ax];
        memory[_ss*16+0x0] = 0x00;
        memory[_ss*16+0x1] = 0x01;
    case 0x1ED75:
        r16[dx] = 0x03c4;
        r8[ah] = memory[_ss*16+0x1];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r8[ah] = memory[_ss*16+0x0];
        r8[al] = 0x04;
        out16(r16[dx], r16[ax]);
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
    case 0x1ED8E:
        lodsb_video_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_video_forward();
        r8[ah] = memoryVideoGet(es, r16[di] + 1);
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ED8E;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        memory[_ss*16+0x0] += 1;
        memory[_ss*16+0x1] <<= 1;
        if (memorys[_ss*16+0x0] < signed8(0x04)) {
            pc = 0x1ED75;
            break;
        }
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0004;
        out16(r16[dx], r16[ax]);
        ds = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
    case 0x1EDCF:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1EDE0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x8F52] = 0x00;
        pc = 0x1EDEC;
        break;
    case 0x1EDE7:
        memory[ds*16+0x8F52] = 0xff;
    case 0x1EDEC:
        bp = memory16get(ds*16+0x4255);
        es = bp;
    case 0x1EDF2:
        if (r16s[dx] > signed16(0xfff0)) {
            pc = 0x1EE03;
            break;
        }
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1EDF2;
            break;
        }
        pc = 0x1EE73;
        break;
    case 0x1EE03:
        r16[cx] >>= 1;
        r16[di] = r16[cx];
        r16[cx] = r16[ax];
        if (r16s[dx] >= 0) {
            pc = 0x1EE26;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
    case 0x1EE0F:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[cx] += r16[dx];
        yield* sub_1EE78();
        r16[di] += 0x0004;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EE0F;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] == 0) {
            pc = 0x1EE73;
            break;
        }
    case 0x1EE26:
        r16[ax] = r16[dx];
        xchg16(di, dx);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] += r16[dx];
        r16[dx] = r16[ax];
    case 0x1EE34:
        if (r16s[dx] >= signed16(0x00b1)) {
            pc = 0x1EE5B;
            break;
        }
        push(r16[dx]);
        push(r16[di]);
        push(r16[cx]);
    case 0x1EE3D:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1EE78();
        r16[di] += 0x0004;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EE3D;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[di] += 0x0500;
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1EE34;
            break;
        }
        pc = 0x1EE73;
        break;
    case 0x1EE5B:
        r16[dx] -= 0x00c0;
        r16[dx] = -r16[dx];
        if (_FIXME_) {
            pc = 0x1EE73;
            break;
        }
        r16[ax] = r16[dx];
    case 0x1EE65:
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1EE78();
        r16[di] += 0x0004;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1EE65;
            break;
        }
    case 0x1EE73:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_1EE78() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (r16[ax] != 0) {
            pc = 0x1EE86;
            break;
        }
        pc = 0x1EFDE;
        break;
    case 0x1EE86:
        if (flags.carry) {
            pc = 0x1EEC1;
            break;
        }
        if (memory[ds*16+0x8F52] == 0x00) {
            pc = 0x1EEA0;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
        r16[ax] = 0xffff;
    case 0x1EE94:
        stosw_data_forward();
        stosw_data_forward();
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x1EE94;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        pc = 0x1EFDE;
        break;
    case 0x1EEA0:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        push(r16[dx]);
        push(ds);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] <<= 1;
        r16[si] <<= 1;
        r16[ax] = _seg009;
        ds = r16[ax];
    case 0x1EEB2:
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x1EEB2;
            break;
        }
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        pc = 0x1EFDE;
        break;
    case 0x1EEC1:
        if (memory[ds*16+0x8F52] == 0x00) {
            pc = 0x1EF38;
            break;
        }
        push(r16[dx]);
        push(r16[si]);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] += 0x5538;
        push(r16[di]);
        push(r16[cx]);
    case 0x1EED6:
        lodsb_data_forward();
        r8[ah] = r8[al];
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        lodsb_data_forward();
        r8[ah] = r8[al];
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x1EED6;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        pc = 0x1EFDE;
        break;
    case 0x1EF38:
        push(r16[cx]);
        push(r16[dx]);
        push(r16[si]);
        push(r16[di]);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        bp = r16[si];
        bp <<= 1;
        bp <<= 1;
        r16[si] -= r16[dx];
        r16[si] += 0x5538;
    case 0x1EF4C:
        lodsb_data_forward();
        r8[ah] = r8[al];
        push(ds);
        r16[dx] = _seg009;
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        ds = r16[dx];
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        r8[al] = (~r8[al]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        r8[al] = (~r8[al]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        ds = pop();
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        lodsb_data_forward();
        r8[ah] = r8[al];
        push(ds);
        r16[dx] = _seg009;
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        ds = r16[dx];
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        r8[al] = (~r8[al]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        r8[al] = (~r8[al]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        ds = pop();
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x1EFD7;
            break;
        }
        pc = 0x1EFDA;
        break;
    case 0x1EFD7:
        pc = 0x1EF4C;
        break;
    case 0x1EFDA:
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
    case 0x1EFDE:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1EFF0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+0x8F52] = 0x00;
        pc = 0x1EFFC;
        break;
    case 0x1EFF7:
        memory[ds*16+0x8F52] = 0xff;
    case 0x1EFFC:
        bp = 0xb800;
        es = bp;
    case 0x1F001:
        if (r16s[dx] > signed16(0xfff0)) {
            pc = 0x1F012;
            break;
        }
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1F001;
            break;
        }
        pc = 0x1F080;
        break;
    case 0x1F012:
        r16[di] = r16[cx];
        r16[cx] = r16[ax];
        if (r16s[dx] >= 0) {
            pc = 0x1F033;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
    case 0x1F01C:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[cx] += r16[dx];
        yield* sub_1F085();
        r16[di] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1F01C;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] == 0) {
            pc = 0x1F080;
            break;
        }
    case 0x1F033:
        r16[ax] = r16[dx];
        xchg16(di, dx);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] += r16[dx];
        r16[dx] = r16[ax];
    case 0x1F041:
        if (r16s[dx] >= signed16(0x00b1)) {
            pc = 0x1F068;
            break;
        }
        push(r16[dx]);
        push(r16[di]);
        push(r16[cx]);
    case 0x1F04A:
        push(r16[cx]);
        r16[cx] = 0x0010;
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1F085();
        r16[di] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1F04A;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[di] += 0x0280;
        r16[dx] += 0x0010;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x1F041;
            break;
        }
        pc = 0x1F080;
        break;
    case 0x1F068:
        r16[dx] -= 0x00c0;
        r16[dx] = -r16[dx];
        if (_FIXME_) {
            pc = 0x1F080;
            break;
        }
        r16[ax] = r16[dx];
    case 0x1F072:
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[dx] = r16[dx] ^ r16[dx];
        yield* sub_1F085();
        r16[di] += 0x0008;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1F072;
            break;
        }
    case 0x1F080:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_1F085() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (r16[ax] != 0) {
            pc = 0x1F093;
            break;
        }
        pc = 0x1F286;
        break;
    case 0x1F093:
        if (flags.carry) {
            pc = 0x1F0E2;
            break;
        }
        if (memory[ds*16+0x8F52] == 0x00) {
            pc = 0x1F0B6;
            break;
        }
        push(r16[di]);
        push(r16[cx]);
        r16[ax] = 0x7777;
    case 0x1F0A1:
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x1F0AF;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x1F0AF:
        if (--r16[cx]) {
            pc = 0x1F0A1;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        pc = 0x1F286;
        break;
    case 0x1F0B6:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        push(r16[dx]);
        push(ds);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] <<= 1;
        r16[si] <<= 1;
        r16[ax] = _seg009;
        ds = r16[ax];
    case 0x1F0CA:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x1F0D8;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x1F0D8:
        if (--r16[cx]) {
            pc = 0x1F0CA;
            break;
        }
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        pc = 0x1F286;
        break;
    case 0x1F0E2:
        if (memory[ds*16+0x8F52] != 0x00) {
            pc = 0x1F0EC;
            break;
        }
        pc = 0x1F1FF;
        break;
    case 0x1F0EC:
        push(r16[dx]);
        push(r16[si]);
        r16[si] = r16[ax];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] += 0x5538;
        push(r16[di]);
        push(r16[cx]);
    case 0x1F0FA:
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F10B;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F115;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F119;
        break;
    case 0x1F10B:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F119;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F119;
        break;
    case 0x1F115:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F119:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F128;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F132;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F136;
        break;
    case 0x1F128:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F136;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F136;
        break;
    case 0x1F132:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F136:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F145;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F14F;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F153;
        break;
    case 0x1F145:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F153;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F153;
        break;
    case 0x1F14F:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F153:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F162;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F16C;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F170;
        break;
    case 0x1F162:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F170;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F170;
        break;
    case 0x1F16C:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F170:
        r16[di] += 1;
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F182;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F18C;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F190;
        break;
    case 0x1F182:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F190;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F190;
        break;
    case 0x1F18C:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F190:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F19F;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1A9;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F1AD;
        break;
    case 0x1F19F:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1AD;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F1AD;
        break;
    case 0x1F1A9:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F1AD:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1BC;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1C6;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F1CA;
        break;
    case 0x1F1BC:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1CA;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F1CA;
        break;
    case 0x1F1C6:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F1CA:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1D9;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1E3;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x1F1E7;
        break;
    case 0x1F1D9:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x1F1E7;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x1F1E7;
        break;
    case 0x1F1E3:
        memory[es*16+r16[di]] |= 0x70;
    case 0x1F1E7:
        flags.sign = signed16(r16[di] + 0x1ff9) < 0;
        r16[di] += 0x1ff9;
        if (!flags.sign) {
            pc = 0x1F1F1;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x1F1F1:
        if (--r16[cx]) {
            pc = 0x1F1F5;
            break;
        }
        pc = 0x1F1F8;
        break;
    case 0x1F1F5:
        pc = 0x1F0FA;
        break;
    case 0x1F1F8:
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        pc = 0x1F286;
        break;
    case 0x1F1FF:
        push(r16[cx]);
        push(r16[dx]);
        push(r16[si]);
        push(r16[di]);
        r16[si] = r16[ax];
        r16[dx] <<= 1;
        r16[si] -= r16[dx];
        bp = r16[si];
        bp <<= 1;
        bp <<= 1;
        r16[si] += 0x5538;
    case 0x1F213:
        lodsb_data_forward();
        r8[ah] = r8[al];
        push(ds);
        r16[dx] = _seg009;
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        ds = r16[dx];
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F226;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F226:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F22F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F22F:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F238;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F238:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F241;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F241:
        r16[di] += 1;
        ds = pop();
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        lodsb_data_forward();
        r8[ah] = r8[al];
        push(ds);
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        r16[dx] = _seg009;
        ds = r16[dx];
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F258;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F258:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F261;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F261:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F26A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F26A:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x1F273;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x1F273:
        ds = pop();
        {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
        flags.sign = signed16(r16[di] + 0x1ff9) < 0;
        r16[di] += 0x1ff9;
        if (!flags.sign) {
            pc = 0x1F280;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x1F280:
        if (--r16[cx]) {
            pc = 0x1F213;
            break;
        }
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
    case 0x1F286:
        r16[ax] = pop();
        return;
    } while (1);
}
function* loc_1F290() {
    yield* sub_1F2D5();
    r16[ax] = 0x000d;
    interrupt(16);
    r16[ax] = 0x1002;
    r16[dx] = 0x425d;
    interrupt(16);
    r16[ax] = 0x1001;
    r8[bh] = r8[bh] ^ r8[bh];
    interrupt(16);
    r16[ax] = 0x0040;
    es = r16[ax];
    r16[dx] = memory16get(es*16+0x63);
    memory16set(ds*16+0x4257, r16[dx]);
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_1F2BA() {
    yield* sub_1F2D5();
    r16[ax] = 0x000d;
    interrupt(16);
    r16[ax] = 0x0040;
    es = r16[ax];
    r16[dx] = memoryBiosGet16(es, 0x63);
    memory16set(ds*16+0x4257, r16[dx]);
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_1F2D5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x973e;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x00c8;
    case 0x1F2DD:
        stosw_data_forward();
        r16[ax] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1F2DD;
            break;
        }
        return;
    } while (1);
}
function* sub_1F2E4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0010;
    case 0x1F2E9:
        r16[ax] = 0x1000;
        push(r16[bx]);
        push(r16[cx]);
        interrupt(16);
        r16[cx] = pop();
        r16[bx] = pop();
        r8[bh] = r8[bh] ^ 0x18;
        if (--r16[cx]) {
            pc = 0x1F2E9;
            break;
        }
        r16[ax] = 0x1000;
        r16[bx] = r16[bx] ^ r16[bx];
        interrupt(16);
        return;
    } while (1);
}
function* sub_1F2FF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0010;
        r8[dh] = r8[dh] ^ r8[dh];
    case 0x1F304:
        push(r16[cx]);
        push(r16[dx]);
        r8[cl] = r8[dh];
        r8[ch] = r8[dh];
        r16[ax] = 0x1010;
        r16[bx] = r16[bx] ^ r16[bx];
        interrupt(16);
        r16[dx] = pop();
        r16[cx] = pop();
        r8[dh] = r8[dh] ^ 0x3f;
        if (--r16[cx]) {
            pc = 0x1F304;
            break;
        }
        r16[ax] = 0x1010;
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = r16[cx] ^ r16[cx];
        r8[dh] = r8[dh] ^ r8[dh];
        interrupt(16);
        return;
    } while (1);
}
function* sub_1F325() {
    push(ds);
    r16[ax] = _seg009;
    ds = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = 0x4000;
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    r16[si] = r16[si] ^ r16[si];
    yield* sub_1F363();
    r8[ah] = 0x02;
    r16[si] = 0x0002;
    yield* sub_1F363();
    r8[ah] = 0x04;
    r16[si] = 0x0004;
    yield* sub_1F363();
    r8[ah] = 0x08;
    r16[si] = 0x0006;
    yield* sub_1F363();
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
}
function* sub_1F363() {
    var pc = 0;
    do switch (pc) {
    case 0:
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r16[cx] = 0x1c90;
    case 0x1F368:
        movsb_video_data_forward();
        movsb_video_data_forward();
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x1F368;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_1F371() {
    r16[ax] = 0x1002;
    r16[dx] = 0x425d;
    interrupt(16);
}
function* sub_1F37A() {
    r16[ax] = 0x1002;
    r16[dx] = 0x426d;
    interrupt(16);
}
function* sub_1F383() {
    r16[ax] = 0x1002;
    r16[dx] = 0x425d;
    interrupt(16);
}
function* sub_1F38C() {
    push(r16[dx]);
    r16[ax] = 0x1012;
    r16[bx] = r16[bx] ^ r16[bx];
    r16[cx] = 0x0010;
    interrupt(16);
    r16[dx] = pop();
    r16[ax] = 0x1012;
    r16[dx] += 0x0018;
    r16[bx] = 0x0010;
    r16[cx] = 0x0008;
    interrupt(16);
}
function* sub_1F3A7() {
    r16[dx] = 0x427d;
    yield* sub_1F38C();
}
function* sub_1F3AE() {
    r16[dx] = 0x427d;
    yield* sub_1F38C();
}
function* sub_1F3B5() {
    r16[ax] = 0x0030;
    _mul(memory16get(ds*16+0x991C));
    r16[dx] = r16[ax];
    r16[dx] += 0x427d;
    yield* sub_1F38C();
}
function* sub_1F3C7() {
    var cs = _seg001;
    r16[ax] = 0x1000;
    r8[bl] = 0x12;
    r8[bh] = 0x00;
    interrupt(16);
    memory[cs*16+0x136] = 0x01;
}
function* sub_1F3D7() {
    var cs = _seg001;
    if (memory[cs*16+0x136] == 0x00)
        return;
    memory[cs*16+0x136] = 0x00;
    r16[ax] = 0x1000;
    r8[bl] = 0x12;
    r8[bh] = 0x0f;
    interrupt(16);
    return;
}
function* sub_1F3EF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9198);
        yield* sub_10ED5();
        push(es);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x1003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0805;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0010;
        r16[ax] = 0x0400;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0808;
        out16(r16[dx], r16[ax]);
        r8[bl] = r8[al];
        bp = memory16get(ds*16+0x425B);
    case 0x1F420:
        r16[di] = memory16get(ds*16+r16[si]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+r16[si] + 2);
        r16[di] += bp;
        if (!(memoryVideoGet(es, r16[di]) & r8[bl])) {
            pc = 0x1F435;
            break;
        }
        memoryVideoSet(es, r16[di], r8[al]);
    case 0x1F435:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x1F420;
            break;
        }
        r16[cx] = 0x0010;
        r16[ax] = 0x0500;
        out16(r16[dx], r16[ax]);
    case 0x1F441:
        r16[di] = memory16get(ds*16+r16[si]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+r16[si] + 2);
        r16[di] += bp;
        if (!(memoryVideoGet(es, r16[di]) & r8[bl])) {
            pc = 0x1F456;
            break;
        }
        memoryVideoSet(es, r16[di], r8[al]);
    case 0x1F456:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x1F441;
            break;
        }
        r16[cx] = 0x0010;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
    case 0x1F462:
        r16[di] = memory16get(ds*16+r16[si]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+r16[si] + 2);
        r16[di] += bp;
        if (!(memoryVideoGet(es, r16[di]) & r8[bl])) {
            pc = 0x1F477;
            break;
        }
        memoryVideoSet(es, r16[di], r8[al]);
    case 0x1F477:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x1F462;
            break;
        }
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        es = pop();
        return;
    } while (1);
}
function* sub_1F492() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0805;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
    case 0x1F4A8:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] &= 0x7fff;
        r16[ax] -= 0x0200;
        if (r16s[ax] > signed16(0x0200)) {
            pc = 0x1F4D2;
            break;
        }
    case 0x1F4B6:
        yield* sub_10ED9();
        memory16set(ds*16+r16[si], r16[ax]);
        yield* sub_10ED9();
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        yield* sub_10ED9();
        r16[ax] &= 0x1fff;
        if (r16s[ax] <= signed16(0x0200)) {
            pc = 0x1F4B6;
            break;
        }
    case 0x1F4D2:
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x00a0;
        if (r16[ax] >= 0x0140) {
            pc = 0x1F4B6;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x0064;
        if (r16[ax] >= 0x00c8) {
            pc = 0x1F4B6;
            break;
        }
        r16[di] = 0x0028;
        _mul(r16[di]);
        r16[di] = r16[ax];
        r16[di] = r16[di] + memory16get(ds*16+0x425B);
        push(r16[cx]);
        r16[cx] = r16[bx];
        r16[cx] &= 0x0007;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[di] += r16[bx];
        r8[ah] = 0x80;
        r8[ah] >>= r8[cl];
        r16[cx] = pop();
        if (!(memoryVideoGet(es, r16[di]) & r8[ah])) {
            pc = 0x1F555;
            break;
        }
        r8[al] = 0x08;
        r16[dx] = 0x03ce;
        out16(r16[dx], r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        xchg8(bh, bl);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] &= 0x0007;
        r8[ah] = memory[ds*16+r16[bx] + 14141];
        r8[al] = r8[al] ^ r8[al];
        out16(r16[dx], r16[ax]);
        memoryVideoSet(es, r16[di], r8[al]);
        pc = 0x1F55A;
        break;
    case 0x1F555:
        memory16set(ds*16+r16[si] + 4, memory16get(ds*16+r16[si] + 4) | 0x8000);
    case 0x1F55A:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x1F561;
            break;
        }
        pc = 0x1F564;
        break;
    case 0x1F561:
        pc = 0x1F4A8;
        break;
    case 0x1F564:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_1F57C() {
    r16[cx] = memory16get(ds*16+r16[si] + 18);
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[si] = memory16get(ds*16+r16[si] + 12);
    yield* sub_1F585();
}
function* sub_1F585() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x1F592;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x1F592:
        r16[di] = memory16get(ds*16+0x425B);
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x1F5AE;
            break;
        }
        pc = 0x1FE9B;
        break;
    case 0x1F5AE:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x1F5B8;
            break;
        }
        pc = 0x1FE9B;
        break;
    case 0x1F5B8:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x1F5C1;
            break;
        }
        pc = 0x1FE9B;
        break;
    case 0x1F5C1:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x1F5CA;
            break;
        }
        pc = 0x1FE9B;
        break;
    case 0x1F5CA:
        memory16set(ds*16+0x0, 0x0000);
        memory16set(ds*16+0x2, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x1F5E7;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
        memory16set(ds*16+0x2, r16[ax]);
    case 0x1F5E7:
        if (r16s[dx] >= 0) {
            pc = 0x1F5F9;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        memory16set(ds*16+0x0, r16[dx]);
        memory16set(ds*16+0x2, r16[dx]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x1F5F9:
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x1F63F;
            break;
        }
        r16[ax] = memory16get(ds*16+0x0);
        r16[ax] = r16[ax] | memory16get(ds*16+0x2);
        if (r16[ax] == 0) {
            pc = 0x1F63F;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x1F616;
            break;
        }
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
        pc = 0x1F63F;
        break;
    case 0x1F616:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1F62F;
            break;
        }
        r16[ax] = memory16get(ds*16+0x0);
        r16[ax] <<= 1;
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x2);
        r16[ax] <<= 1;
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) + r16[ax]);
        pc = 0x1F63F;
        break;
    case 0x1F62F:
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
    case 0x1F63F:
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[di] += r16[ax];
        if (r16s[cx] >= 0) {
            pc = 0x1F64D;
            break;
        }
    {yield* loc_1FA46(); return; };
    case 0x1F64D:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] <= signed16(0x0140)) {
            pc = 0x1F659;
            break;
        }
    {yield* loc_1FC5C(); return; };
    case 0x1F659:
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[ch] = r8[ch] ^ r8[ch];
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x1F687;
            break;
        }
    {yield* loc_1F997(); return; };
    case 0x1F687:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x1F68F;
            break;
        }
    {yield* loc_1F8C1(); return; };
    case 0x1F68F:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1F697;
            break;
        }
    {yield* loc_1F7C0(); return; };
    case 0x1F697:
        bp += r16[cx];
        if (signed16(bp) > signed16(0x0020)) {
            pc = 0x1F6A1;
            break;
        }
    {yield* loc_1F73C(); return; };
    case 0x1F6A1:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        r8[al] = r8[al] ^ r8[al];
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 4, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F6A1;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F6F8();
        r8[ah] = 0x02;
        yield* sub_1F6F8();
        r8[ah] = 0x04;
        yield* sub_1F6F8();
        r8[ah] = 0x08;
        yield* sub_1F6F8();
    {yield* loc_1FE85(); return; };
    case 0x1FE9B:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_1F6F8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1F708:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 3, r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 4, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F708;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F73C() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1F73C:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F73C;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F787();
        r8[ah] = 0x02;
        yield* sub_1F787();
        r8[ah] = 0x04;
        yield* sub_1F787();
        r8[ah] = 0x08;
        yield* sub_1F787();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F787() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1F797:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 3, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F797;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F7C0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp += r16[cx];
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1F7CA;
            break;
        }
    {yield* loc_1F851(); return; };
    case 0x1F7CA:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        r8[al] = r8[al] ^ r8[al];
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F7CA;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F816();
        r8[ah] = 0x02;
        yield* sub_1F816();
        r8[ah] = 0x04;
        yield* sub_1F816();
        r8[ah] = 0x08;
        yield* sub_1F816();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F816() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1F826:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 3, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F826;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F851() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1F851:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F851;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F891();
        r8[ah] = 0x02;
        yield* sub_1F891();
        r8[ah] = 0x04;
        yield* sub_1F891();
        r8[ah] = 0x08;
        yield* sub_1F891();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F891() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1F8A1:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F8A1;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F8C1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0010))
            {
            yield* loc_1F93B();
            return;
        }
    case 0x1F8C8:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        r8[al] = r8[al] ^ r8[al];
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F8C8;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F909();
        r8[ah] = 0x02;
        yield* sub_1F909();
        r8[ah] = 0x04;
        yield* sub_1F909();
        r8[ah] = 0x08;
        yield* sub_1F909();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F909() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1F919:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F919;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F93B() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1F93B:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        lodsb_data_forward();
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F93B;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F970();
        r8[ah] = 0x02;
        yield* sub_1F970();
        r8[ah] = 0x04;
        yield* sub_1F970();
        r8[ah] = 0x08;
        yield* sub_1F970();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F970() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1F980:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F980;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F997() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0008))
            {
            yield* loc_1F9FD();
            return;
        }
    case 0x1F99E:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r8[ah] = memory[ds*16+r16[si] - 1];
        r8[al] = r8[al] ^ r8[al];
        ror16(ax, r8[cl]);
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F99E;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1F9D4();
        r8[ah] = 0x02;
        yield* sub_1F9D4();
        r8[ah] = 0x04;
        yield* sub_1F9D4();
        r8[ah] = 0x08;
        yield* sub_1F9D4();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1F9D4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1F9E4:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F9E4;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1F9FD() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1F9FD:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1F9FD;
            break;
        }
        r16[di] = pop();
        r16[dx] -= 1;
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FA27();
        r8[ah] = 0x02;
        yield* sub_1FA27();
        r8[ah] = 0x04;
        yield* sub_1FA27();
        r8[ah] = 0x08;
        yield* sub_1FA27();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FA27() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1FA37:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FA37;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FA46() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = r16[cx];
        r16[dx] = -r16[dx];
        r16[dx] -= 1;
        r16[dx] &= 0xfff8;
        bp -= r16[dx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        memory16set(ds*16+0x4, r16[dx]);
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[ch] = 0x08;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x1FA7A;
            break;
        }
    {yield* loc_1FC06(); return; };
    case 0x1FA7A:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x1FA82;
            break;
        }
    {yield* loc_1FB9B(); return; };
    case 0x1FA82:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1FA8A;
            break;
        }
    {yield* loc_1FB1B(); return; };
    case 0x1FA8A:
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FA8A;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FADB();
        r8[ah] = 0x02;
        yield* sub_1FADB();
        r8[ah] = 0x04;
        yield* sub_1FADB();
        r8[ah] = 0x08;
        yield* sub_1FADB();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FADB() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1FAEB:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di], r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 3, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FAEB;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FB1B() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FB1B:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FB1B;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FB64();
        r8[ah] = 0x02;
        yield* sub_1FB64();
        r8[ah] = 0x04;
        yield* sub_1FB64();
        r8[ah] = 0x08;
        yield* sub_1FB64();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FB64() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FB74:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di], r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FB74;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FB9B() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FB9B:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FB9B;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FBD8();
        r8[ah] = 0x02;
        yield* sub_1FBD8();
        r8[ah] = 0x04;
        yield* sub_1FBD8();
        r8[ah] = 0x08;
        yield* sub_1FBD8();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FBD8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FBE8:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di], r8[ah]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FBE8;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FC06() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FC06:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FC06;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FC37();
        r8[ah] = 0x02;
        yield* sub_1FC37();
        r8[ah] = 0x04;
        yield* sub_1FC37();
        r8[ah] = 0x08;
        yield* sub_1FC37();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FC37() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FC47:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di], r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FC47;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FC5C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = bp;
        bp = 0x0140;
        bp -= r16[cx];
        r16[ax] = bp;
        r16[ax] += 0x0007;
        r16[dx] += 0x0007;
        r16[dx] &= 0xfff8;
        r16[ax] &= 0xfff8;
        r16[dx] -= r16[ax];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        memory16set(ds*16+0x4, r16[dx]);
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[ch] = 0x08;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x1FCA7;
            break;
        }
    {yield* loc_1FE1D(); return; };
    case 0x1FCA7:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x1FCAF;
            break;
        }
    {yield* loc_1FDB8(); return; };
    case 0x1FCAF:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1FCB7;
            break;
        }
    {yield* loc_1FD3E(); return; };
    case 0x1FCB7:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FCB7;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FD05();
        r8[ah] = 0x02;
        yield* sub_1FD05();
        r8[ah] = 0x04;
        yield* sub_1FD05();
        r8[ah] = 0x08;
        yield* sub_1FD05();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FD05() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r8[bl] = r8[bh];
        r16[si] = r16[si] + memory16get(ds*16+0x2);
    case 0x1FD15:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 3, r8[ah]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FD15;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FD3E() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FD3E:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FD3E;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FD84();
        r8[ah] = 0x02;
        yield* sub_1FD84();
        r8[ah] = 0x04;
        yield* sub_1FD84();
        r8[ah] = 0x08;
        yield* sub_1FD84();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FD84() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FD94:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 2, r8[ah]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FD94;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FDB8() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FDB8:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FDB8;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FDF2();
        r8[ah] = 0x02;
        yield* sub_1FDF2();
        r8[ah] = 0x04;
        yield* sub_1FDF2();
        r8[ah] = 0x08;
        yield* sub_1FDF2();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FDF2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FE02:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        memoryVideoAnd(es, r16[di] + 1, r8[ah]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FE02;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* loc_1FE1D() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1FE1D:
        lodsb_data_forward();
        r8[ah] = r8[al];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FE1D;
            break;
        }
        r16[di] = pop();
        yield* sub_1FE70();
        r8[ah] = 0x01;
        yield* sub_1FE4D();
        r8[ah] = 0x02;
        yield* sub_1FE4D();
        r8[ah] = 0x04;
        yield* sub_1FE4D();
        r8[ah] = 0x08;
        yield* sub_1FE4D();
    {yield* loc_1FE85(); return; };
        return;
    } while (1);
}
function* sub_1FE4D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        push(r16[di]);
        r16[si] = r16[si] + memory16get(ds*16+0x2);
        r8[bl] = r8[bh];
    case 0x1FE5D:
        lodsb_data_forward();
        r8[al] >>= r8[cl];
        memoryVideoAnd(es, r16[di], r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x1FE5D;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_1FE70() {
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x1003;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0805;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0007;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
}
function* loc_1FE85() {
    r16[dx] = 0x03ce;
    r16[ax] = 0x0003;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0f07;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    loc_1FE9B:
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
}
function* sub_1FEA1() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(cs);
        yield* sub_1F57C();
        r16[si] = pop();
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[di] = memory16get(ds*16+r16[si] + 12);
        r16[cx] = _seg007;
        if (!(r16[di] & 0x0001)) {
            pc = 0x1FEBD;
            break;
        }
        r16[di] -= 1;
        r16[cx] = _seg008;
    case 0x1FEBD:
        push(es);
        es = r16[cx];
        r16[ax] = r16[ax] - memory16get(es*16+r16[di]);
        r16[bx] = r16[bx] - memory16get(es*16+r16[di] + 2);
        es = pop();
        yield* sub_1FEDE();
        r16[ax] += 0x0010;
        yield* sub_1FEDE();
        r16[bx] += 0x0010;
        yield* sub_1FEDE();
        r16[ax] -= 0x0010;
        yield* sub_1FEDE();
        return;
    } while (1);
}
function* sub_1FEDE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[ax]);
        push(r16[bx]);
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[cx] = r16[ax];
        r16[cx] &= 0xfff0;
        r16[cx] >>= 1;
        if (r16[cx] >= 0x00a0) {
            pc = 0x1FF3D;
            break;
        }
        r16[dx] = r16[bx];
        r16[dx] = r16[dx] + memory16get(ds*16+0x9196);
        r16[dx] &= 0xfff0;
        r16[dx] = r16[dx] - memory16get(ds*16+0x9196);
        r16[bx] = r16[bx] + memory16get(ds*16+0x9196);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] &= 0x00fe;
        r16[si] += r16[ax];
        r16[ax] = 0x0028;
        push(r16[dx]);
        _mul(r16[bx]);
        r16[dx] = pop();
        r16[si] += r16[ax];
        push(es);
        r16[ax] = _seg000;
        es = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(es*16+0xEDD1, r16[ax]);
        es = pop();
        r16[ax] = 0x0001;
        r16[bx] = 0x0001;
        r16[si] = 0xedd1;
        yield* sub_1EBD0();
    case 0x1FF3D:
        r16[bx] = pop();
        r16[ax] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_1FF41() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 4, 0x0853);
    case 0x1FF46:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
    case 0x1FF4F:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x1FF5C;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x1FF5C:
        r16[di] = memory16get(ds*16+0x425B);
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x1FF78;
            break;
        }
        pc = 0x203D4;
        break;
    case 0x1FF78:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x1FF82;
            break;
        }
        pc = 0x203D4;
        break;
    case 0x1FF82:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x1FF8B;
            break;
        }
        pc = 0x203D4;
        break;
    case 0x1FF8B:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x1FF94;
            break;
        }
        pc = 0x203D4;
        break;
    case 0x1FF94:
        memory16set(ds*16+0x0, 0x0000);
        memory16set(ds*16+0x2, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x1FFB1;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
        memory16set(ds*16+0x2, r16[ax]);
    case 0x1FFB1:
        if (r16s[dx] >= 0) {
            pc = 0x1FFC3;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        memory16set(ds*16+0x0, r16[dx]);
        memory16set(ds*16+0x2, r16[dx]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x1FFC3:
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x20009;
            break;
        }
        r16[ax] = memory16get(ds*16+0x0);
        r16[ax] = r16[ax] | memory16get(ds*16+0x2);
        if (r16[ax] == 0) {
            pc = 0x20009;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x1FFE0;
            break;
        }
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
        pc = 0x20009;
        break;
    case 0x1FFE0:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x1FFF9;
            break;
        }
        r16[ax] = memory16get(ds*16+0x0);
        r16[ax] <<= 1;
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) + r16[ax]);
        r16[ax] = memory16get(ds*16+0x2);
        r16[ax] <<= 1;
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) + r16[ax]);
        pc = 0x20009;
        break;
    case 0x1FFF9:
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x0, memory16get(ds*16+0x0) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
        memory16set(ds*16+0x2, memory16get(ds*16+0x2) << 1);
    case 0x20009:
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[di] += r16[ax];
        if (r16s[cx] >= 0) {
            pc = 0x20017;
            break;
        }
        pc = 0x201E0;
        break;
    case 0x20017:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] <= signed16(0x0140)) {
            pc = 0x20023;
            break;
        }
        pc = 0x202CE;
        break;
    case 0x20023:
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[ch] = 0x08;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x20051;
            break;
        }
        pc = 0x201A2;
        break;
    case 0x20051:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x20059;
            break;
        }
        pc = 0x2014F;
        break;
    case 0x20059:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x20061;
            break;
        }
        pc = 0x200E4;
        break;
    case 0x20061:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0020)) {
            pc = 0x200AD;
            break;
        }
    case 0x20068:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 4, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20068;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x200AD:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x200AD;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x200E4:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0018)) {
            pc = 0x20124;
            break;
        }
    case 0x200EB:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x200EB;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x20124:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20124;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x2014F:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0010)) {
            pc = 0x20183;
            break;
        }
    case 0x20156:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20156;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x20183:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20183;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x201A2:
        bp += r16[cx];
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x201CA;
            break;
        }
    case 0x201A9:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x201A9;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x201CA:
        lodsb_data_forward();
        r8[ah] = r8[al];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x201CA;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x201E0:
        r16[dx] = r16[cx];
        r16[dx] = -r16[dx];
        r16[dx] -= 1;
        r16[dx] &= 0xfff8;
        bp -= r16[dx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        memory16set(ds*16+0x4, r16[dx]);
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[ch] = 0x08;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x20218;
            break;
        }
        pc = 0x202B4;
        break;
    case 0x20218:
        if (signed16(bp) <= signed16(0x0010)) {
            pc = 0x2028E;
            break;
        }
        if (signed16(bp) <= signed16(0x0018)) {
            pc = 0x2025C;
            break;
        }
    case 0x20222:
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20222;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x2025C:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x2025C;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x2028E:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x2028E;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x202B4:
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x202B4;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x202CE:
        r16[dx] = bp;
        bp = 0x0140;
        bp -= r16[cx];
        r16[ax] = bp;
        r16[ax] += 0x0007;
        r16[dx] += 0x0007;
        r16[dx] &= 0xfff8;
        r16[ax] &= 0xfff8;
        r16[dx] -= r16[ax];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        memory16set(ds*16+0x4, r16[dx]);
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        push(r16[di]);
        r8[bh] = r8[bl];
        r8[ch] = 0x08;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x2031D;
            break;
        }
        pc = 0x203AD;
        break;
    case 0x2031D:
        if (signed16(bp) <= signed16(0x0010)) {
            pc = 0x2038B;
            break;
        }
        if (signed16(bp) <= signed16(0x0018)) {
            pc = 0x2035D;
            break;
        }
    case 0x20327:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 3, r8[al]);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x20327;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x2035D:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        r8[ah] = memory[ds*16+r16[si]];
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 2, r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x2035D;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x2038B:
        r8[ah] = memory[ds*16+r16[si]];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsw_data_forward();
        ror16(ax, r8[cl]);
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x2038B;
            break;
        }
        r16[di] = pop();
        pc = 0x203C6;
        break;
    case 0x203AD:
        lodsb_data_forward();
        r8[ah] = r8[al];
        r8[ah] >>= r8[cl];
        r8[al] = r8[ch];
        out16(r16[dx], r16[ax]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[si] = r16[si] + memory16get(ds*16+0x4);
        r16[di] += 0x0028;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x203AD;
            break;
        }
        r16[di] = pop();
        _STOP_("goto $+2");
    case 0x203C6:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r8[al] -= 1;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
    case 0x203D4:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_203DA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si]);
        if (r16[bx] < 0x0140) {
            pc = 0x203EE;
            break;
        }
        return;
    case 0x203EE:
        r16[dx] = r16[dx] - memory16get(ds*16+r16[si] + 2);
        if (r16s[dx] < signed16(0x00c0)) {
            pc = 0x203FA;
            break;
        }
        return;
    case 0x203FA:
        r16[cx] = memory16get(ds*16+r16[si] + 4);
        r16[ax] = r16[bx];
        r16[bx] &= 0x0007;
        r16[ax] = r16[ax] ^ r16[bx];
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + r16[si] + 6);
        if (r16s[dx] >= 0) {
            pc = 0x20417;
            break;
        }
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[cx] += r16[dx];
        if (r16s[cx] <= signed16(0))
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x20417:
        r16[bx] = r16[dx];
        r16[bx] += r16[cx];
        flags.carry2 = r16s[bx] <= signed16(0x00c0);
        r16[bx] -= 0x00c0;
        if (flags.carry2) {
            pc = 0x20425;
            break;
        }
        flags.carry2 = r16s[cx] <= r16s[bx];
        r16[cx] -= r16[bx];
        if (flags.carry2)
            return;
    case 0x20425:
        r16[bx] = r16[ax];
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += r16[ax];
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[di] += r16[bx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        if (r16s[bx] >= signed16(0x0138)) {
            pc = 0x20466;
            break;
        }
    case 0x20454:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x20454;
            break;
        }
        pc = 0x20471;
        break;
    case 0x20466:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        memoryVideoOr(es, r16[di], r8[al]);
        r16[si] += 1;
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x20466;
            break;
        }
    case 0x20471:
        r16[dx] -= 1;
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r8[al] -= 1;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_20482() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[di] = memory16get(ds*16+0x425B);
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[dx] = memory16get(ds*16+0x9196);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[cx] = 0x0010;
        r16[cx] -= r16[dx];
        r8[bl] = 0x14;
    case 0x204A4:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        push(ds);
        r16[ax] = 0xa400;
        ds = r16[ax];
        push(r16[di]);
        push(r16[cx]);
    case 0x204B6:
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += 0x0026;
        if (--r16[cx]) {
            pc = 0x204B6;
            break;
        }
        bp = r16[di];
        r16[cx] = pop();
        r16[di] = pop();
        r16[di] += 0x0002;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x204A4;
            break;
        }
        r16[di] = bp;
        r16[di] -= 0x0026;
        r16[bx] = 0x0b14;
        bp = 0x0026;
    case 0x204D5:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[cx] = ds;
        r16[ax] = 0xa400;
        ds = r16[ax];
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        r16[di] -= 0x027e;
        ds = r16[cx];
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x204D5;
            break;
        }
        r8[bl] = 0x14;
        r16[di] += 0x0258;
        r8[bh] -= 1;
        if (r8[bh] != 0) {
            pc = 0x204D5;
            break;
        }
        if (!(r16[dx] & r16[dx])) {
            pc = 0x2055C;
            break;
        }
        r8[bl] = 0x14;
    case 0x2053D:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        push(ds);
        r16[ax] = 0xa400;
        ds = r16[ax];
        push(r16[di]);
        r16[cx] = r16[dx];
    case 0x2054C:
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += bp;
        if (--r16[cx]) {
            pc = 0x2054C;
            break;
        }
        r16[di] = pop();
        r16[di] += 0x0002;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x2053D;
            break;
        }
    case 0x2055C:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_20568() {
    yield* sub_2058D();
    r16[ax] = memory16get(ds*16+0x425B);
    r16[bx] = memory16get(ds*16+0x4259);
    memory16set(ds*16+0x425B, r16[bx]);
    memory16set(ds*16+0x4259, r16[ax]);
    yield* sub_2058D();
    r16[ax] = memory16get(ds*16+0x425B);
    r16[bx] = memory16get(ds*16+0x4259);
    memory16set(ds*16+0x425B, r16[bx]);
    memory16set(ds*16+0x4259, r16[ax]);
}
function* sub_2058D() {
    push(es);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03ce;
    r16[ax] = 0x0f01;
    out16(r16[dx], r16[ax]);
    r16[di] = memory16get(ds*16+0x425B);
    r16[cx] = 0x1f40;
    rep_stosb_video_forward();
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    es = pop();
}
function* sub_205A9() {
    yield* sub_2058D();
}
function* sub_205AE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_10EF1();
    case 0x205B3:
        memory16set(ds*16+0x3046, 0x0000);
        r16[bx] = memory16get(ds*16+0x425B);
        r16[ax] = memory16get(ds*16+0x4259);
        memory16set(ds*16+0x425B, r16[ax]);
        memory16set(ds*16+0x4259, r16[bx]);
        r16[dx] = memory16get(ds*16+0x4257);
        r8[dl] += 0x06;
    case 0x205D5:
        r8[al] = in8(r16[dx]);
        if (r8[al] & 0x08) {
            pc = 0x205D5;
            break;
        }
        r8[dl] -= 0x06;
        flags.interrupt = false;
        r8[ah] = r8[bh];
        r8[al] = 0x0c;
        out16(r16[dx], r16[ax]);
        flags.interrupt = true;
        r8[dl] += 0x06;
    case 0x205E7:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x08)) {
            pc = 0x205E7;
            break;
        }
        return;
    } while (1);
}
function* sub_205ED() {
    push(ds);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[si] = 0x0000;
    r16[di] = memory16get(ds*16+0x4259);
    r16[di] += 0x1e00;
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[cx] = 0x0140;
    yield* sub_20627();
    ds = pop();
    push(ds);
    r16[si] = 0x0000;
    r16[di] = memory16get(ds*16+0x425B);
    r16[di] += 0x1e00;
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[cx] = 0x0140;
    yield* sub_20627();
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
}
function* sub_20627() {
    r16[dx] = 0x03c4;
    push(r16[cx]);
    push(r16[di]);
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    rep_movsb_video_data_forward();
    r16[di] = pop();
    r16[cx] = pop();
    push(r16[cx]);
    push(r16[di]);
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    rep_movsb_video_data_forward();
    r16[di] = pop();
    r16[cx] = pop();
    push(r16[cx]);
    push(r16[di]);
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    rep_movsb_video_data_forward();
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    rep_movsb_video_data_forward();
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
}
function* sub_20653() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[si] = 0x9c80;
        r16[cx] = 0x0050;
    case 0x2066C:
        lodsw_data_forward();
        if (r16s[ax] < 0) {
            pc = 0x206EA;
            break;
        }
        r16[bx] = r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[bx] += r16[ax];
        lodsw_data_forward();
        r16[dx] += r16[ax];
        if (r16[bx] >= 0x013c) {
            pc = 0x206E3;
            break;
        }
        if (r16[dx] >= 0x00bc) {
            pc = 0x206E3;
            break;
        }
        memory16set(ds*16+r16[si] - 8, r16[bx]);
        memory16set(ds*16+r16[si] - 6, r16[dx]);
        push(r16[bx]);
        push(r16[dx]);
        push(r16[cx]);
        r16[ax] = r16[bx];
        r16[bx] = r16[dx];
        yield* sub_10EDD();
        if (_FIXME_) {
            pc = 0x206B3;
            break;
        }
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = memory16get(es*16+0x3DA8);
        push(r16[si]);
        yield* sub_10EE1();
        r16[si] = pop();
        es = pop();
        r16[cx] = pop();
        sp += 0x0004;
        pc = 0x206E3;
        break;
    case 0x206B3:
        r16[cx] = pop();
        r16[dx] = pop();
        r16[di] = memory16get(ds*16+0x425B);
        r16[ax] = 0x0028;
        _mul(r16[dx]);
        r16[di] += r16[ax];
        r16[ax] = pop();
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[cx] &= 0x0007;
        r16[ax] = r16[ax] ^ r16[cx];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        r8[al] = 0xc0;
        r8[al] >>= r8[cl];
        r16[cx] = pop();
        r16[dx] = 0x03cf;
        out8(r16[dx], r8[al]);
        memory[es*16+r16[di]] &= r8[al];
        memory[es*16+r16[di] + 40] &= r8[al];
        pc = 0x206ED;
        break;
    case 0x206E3:
        memory16set(ds*16+r16[si] - 8, 0xffff);
        pc = 0x206ED;
        break;
    case 0x206EA:
        r16[si] += 0x0006;
    case 0x206ED:
        if (--r16[cx]) {
            pc = 0x206F1;
            break;
        }
        pc = 0x206F4;
        break;
    case 0x206F1:
        pc = 0x2066C;
        break;
    case 0x206F4:
        r16[ax] = ds;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_20708() {
    r16[ax] = memory16get(ds*16+r16[si] + 52);
    memory16set(ds*16+0xFCFE, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 18);
    memory16set(ds*16+0xFCE2, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 22);
    memory16set(ds*16+0xFCE6, r16[ax]);
    push(r16[si]);
    yield* sub_20721();
    r16[si] = pop();
}
function* sub_20721() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + 0x0004);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0x32C0, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        memory16set(ds*16+0x32BE, r16[ax]);
        if (memory16gets(ds*16+0xFCE2) > signed16(0xfff0)) {
            pc = 0x20756;
            break;
        }
        pc = 0x20815;
        break;
    case 0x20756:
        if (memory16gets(ds*16+0xFCE2) < signed16(0x0140)) {
            pc = 0x20761;
            break;
        }
        pc = 0x20815;
        break;
    case 0x20761:
        if (memory16gets(ds*16+0x32BE) < signed16(0x0041)) {
            pc = 0x2078B;
            break;
        }
        r16[bx] = memory16get(ds*16+0xFCFE);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 12994);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        r16[dx] += 1;
        yield* sub_1F585();
        r16[ax] = memory16get(ds*16+0x32BA);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x32BC);
        memory16set(ds*16+0xFCE6, r16[ax]);
    case 0x2078B:
        r16[ax] = memory16get(ds*16+0x32BE);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        r16[si] = 0x32c8;
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 13000);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        yield* sub_1F585();
        if (memory16gets(ds*16+0x32BC) < 0 /*CHECK*/) {
            pc = 0x20815;
            break;
        }
        r16[dx] = 0x03ce;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = 0x0028;
        _mul(memory16get(ds*16+0x32BC));
        r16[di] = memory16get(ds*16+0x425B);
        bp = r16[di];
        r16[di] += r16[ax];
        r16[ax] = memory16get(ds*16+0x32BA);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        r16[di] += r16[ax];
        r16[dx] = memory16get(ds*16+0x32BA);
        r16[dx] &= 0xfff8;
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds*16+0x32BA);
        r16[cx] &= 0x0007;
        r8[ah] = memory[ds*16+r16[bx] + 13246];
        r8[ah] >>= r8[cl];
        yield* sub_20829();
        r16[di] += 1;
        r16[dx] += 0x0008;
        r16[ax] = memory16get(ds*16+r16[bx] + 13246);
        ror16(ax, r8[cl]);
        yield* sub_20829();
        r16[di] += 1;
        r16[dx] += 0x0008;
        r8[ah] = r8[ah] ^ r8[ah];
        r8[al] = memory[ds*16+r16[bx] + 13247];
        ror16(ax, r8[cl]);
        yield* sub_20829();
    case 0x20815:
        r16[ax] = ds;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_20829() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[dx] >= 0x0140)
            return;
        if (!(r8[ah] & r8[ah]))
            return;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[di]);
        push(r16[dx]);
        r8[al] = 0x08;
        r16[dx] = 0x03ce;
        out16(r16[dx], r16[ax]);
        r16[cx] = memory16get(ds*16+0x32BE);
        if (r16[cx] == 0) {
            pc = 0x2084F;
            break;
        }
    case 0x20843:
        memory[es*16+r16[di]] &= r8[al];
        r16[di] -= 0x0028;
        if (r16s[di] < signed16(bp)) {
            pc = 0x2084F;
            break;
        }
        if (--r16[cx]) {
            pc = 0x20843;
            break;
        }
    case 0x2084F:
        r16[dx] = pop();
        r16[di] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_20854() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9152);
        r16[dx] = memory16get(ds*16+0x9154);
        flags.carry = r16[ax] < memory16get(ds*16+0x9156);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9156);
        r16[dx] -= memory16get(ds*16+0x9158) + flags.carry;
        if (r16s[ax] < 0) {
            pc = 0x208CF;
            break;
        }
        if (r16[ax] != 0) {
            pc = 0x2086B;
            break;
        }
        if (!(r16[ax] & r16[ax]))
            return;
    case 0x2086B:
        if (r16[dx] & r16[dx]) {
            pc = 0x20879;
            break;
        }
        if (r16s[ax] < signed16(0x00c8)) {
            pc = 0x20894;
            break;
        }
        if (r16s[ax] < signed16(0x07d0)) {
            pc = 0x20887;
            break;
        }
    case 0x20879:
        r16[bx] = 0x921f;
        r16[di] = 0x1e06;
        flags.carry = (memory16get(ds*16+0x9156) + 0x03e8) >= 0x10000;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x03e8);
        pc = 0x2089F;
        break;
    case 0x20887:
        r16[bx] = 0x9220;
        r16[di] = 0x1e07;
        flags.carry = (memory16get(ds*16+0x9156) + 0x0064) >= 0x10000;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x0064);
        pc = 0x2089F;
        break;
    case 0x20894:
        r16[bx] = 0x9221;
        r16[di] = 0x1e08;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x000a);
    case 0x2089F:
        memory16set(ds*16+0x9158, memory16get(ds*16+0x9158) + 0x0000 + flags.carry);
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x208AE;
            break;
        }
        r16[di] += 0x001b;
    case 0x208AE:
        r16[si] = 0x0500;
    case 0x208B1:
        memory[ds*16+r16[bx]] += 1;
        if (memorys[ds*16+r16[bx]] < signed8(0x0a)) {
            pc = 0x208BB;
            break;
        }
        memory[ds*16+r16[bx]] = 0x00;
    case 0x208BB:
        r8[al] = memory[ds*16+r16[bx]];
        yield* sub_20919();
        if (memory[ds*16+r16[bx]] != 0x00)
            return;
        r16[di] -= 1;
        r16[bx] -= 1;
        if (r16s[bx] >= signed16(0x921c)) {
            pc = 0x208B1;
            break;
        }
        return;
    case 0x208CF:
        r16[ax] = memory16get(ds*16+0x9156);
        memory16set(ds*16+0x9152, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9158);
        memory16set(ds*16+0x9154, r16[ax]);
        return;
    } while (1);
}
function* sub_208DC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x1e03;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x208E9;
            break;
        }
        r16[di] = 0x1e1e;
    case 0x208E9:
        r16[si] = 0x0500;
        r16[cx] = 0x0007;
    case 0x208EF:
        r8[al] = r8[al] ^ r8[al];
        yield* sub_20919();
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x208EF;
            break;
        }
        return;
    } while (1);
}
function* sub_208F9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x918A);
        if (r16s[ax] <= signed16(0x0009)) {
            pc = 0x20904;
            break;
        }
        r16[ax] = 0x0009;
    case 0x20904:
        r16[si] = 0x0640;
        r16[di] = 0x1e39;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x20914;
            break;
        }
        r16[di] = 0x1e3e;
    case 0x20914:
        yield* sub_20919();
        return;
    } while (1);
}
function* sub_20919() {
    push(r16[si]);
    push(r16[cx]);
    r8[ah] = r8[ah] ^ r8[ah];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] += r16[ax];
    push(ds);
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    yield* sub_2095F();
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    yield* sub_2095F();
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    yield* sub_2095F();
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    yield* sub_2095F();
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
    r16[cx] = pop();
    r16[si] = pop();
}
function* sub_2095F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        r16[cx] = 0x0008;
    case 0x20963:
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        memoryVideoSet(es, r16[di] + 8192, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x20963;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_20973() {
    push(r16[si]);
    push(r16[ax]);
    yield* sub_2098C();
    r16[ax] = pop();
    r16[si] = pop();
    memory16set(ds*16+0x425B, memory16get(ds*16+0x425B) ^ 0x2000);
    yield* sub_2098C();
    memory16set(ds*16+0x425B, memory16get(ds*16+0x425B) ^ 0x2000);
}
function* sub_2098C() {
    r16[ax] = 0x0028;
    _mul(memory16get(ds*16+0x3752));
    r16[di] = r16[ax];
    push(memory16get(ds*16+r16[si] + 20));
    push(r16[si]);
    memory[ds*16+r16[si] + 20] = 0x00;
    yield* sub_20A2E();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 20, pop());
}
function* sub_209A6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x1af1;
        memory16set(ds*16+0xFCE2, r16[ax]);
        memory16set(ds*16+0xFCE4, r16[dx]);
        r16[bx] = 0x3756;
        r16[si] = 0x0500;
    case 0x209B6:
        if (memory16get(ds*16+r16[bx]) == 0x0000)
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x209BD:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+0xFCE4, memory16get(ds*16+0xFCE4) - r16[ax] - flags.carry);
        if (memory16gets(ds*16+0xFCE4) < 0) {
            pc = 0x209CF;
            break;
        }
        r16[dx] += 1;
        pc = 0x209BD;
        break;
    case 0x209CF:
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.carry = (memory16get(ds*16+0xFCE2) + r16[ax]) >= 0x10000;
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+0xFCE4, memory16get(ds*16+0xFCE4) + r16[ax] + flags.carry);
        r16[bx] += 0x0004;
        r8[al] = r8[dl];
        yield* sub_20919();
        r16[di] += 1;
        pc = 0x209B6;
        break;
        return;
    } while (1);
}
function* sub_209E9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2058D();
        memory16set(ds*16+0x3752, 0x000c);
        r16[si] = 0x352b;
        yield* sub_20973();
        r16[si] = 0x358f;
        r16[di] = 0x05f4;
        r16[cx] = 0x000a;
    case 0x20A03:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        yield* sub_20A1D();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[si] += 0x000f;
        r16[di] += 0x0280;
        if (--r16[cx]) {
            pc = 0x20A03;
            break;
        }
        yield* sub_1F492();
    {yield* sub_205AE(); yield* _sync(); return; };
        return;
    } while (1);
}
function* sub_20A1D() {
    push(memory16get(ds*16+r16[si] + 15));
    push(r16[si]);
    memory[ds*16+r16[si] + 15] = 0x00;
    yield* sub_20A3C();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 15, pop());
}
function* sub_20A2E() {
    bp = 0x0780;
    r16[cx] = 0x0016;
    yield* sub_20A47();
}
function* sub_20A39() {
    r16[di] = 0x1cd6;
    yield* sub_20A3C();
}
function* sub_20A3C() {
    bp = 0x2300;
    r16[cx] = 0x000e;
    yield* sub_20A47();
}
function* sub_20A47() {
    lodsb_data_forward();
    if (!(r8[al] & r8[al]))
        return;
    {var t = r16[si]; r16[si] = bp; bp = t;} //_xchg(r16[si], bp);
    push(r16[si]);
    yield* sub_20A5C();
    r16[si] = pop();
    {var t = r16[si]; r16[si] = bp; bp = t;} //_xchg(r16[si], bp);
    r16[di] += 0x0002;
{yield* sub_20A47(); return; };
    return;
}
function* sub_20A5C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        push(r16[cx]);
        push(r16[di]);
        memory[ds*16+0x33F2] = r8[al];
        r16[di] = 0x33ca;
        r16[cx] = 0x33f2;
        r16[cx] -= 0x33ca;
        r16[cx] += 1;
        _repne_scasb();
        r16[ax] = r16[di];
        r16[ax] -= 0x33cb;
        r16[di] = pop();
        if (r16[ax] == 0x0028) {
            pc = 0x20ABD;
            break;
        }
        r16[di] = r16[di] + memory16get(ds*16+0x425B);
        r16[cx] = pop();
        _mul(r16[cx]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        push(r16[cx]);
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        yield* sub_20AC0();
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        yield* sub_20AC0();
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        yield* sub_20AC0();
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        yield* sub_20AC0();
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
    case 0x20ABD:
        r16[cx] = pop();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_20AC0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        push(r16[cx]);
    case 0x20AC2:
        lodsb_data_forward();
        stosb_video_forward();
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        r16[di] += 0x0027;
        if (--r16[cx]) {
            pc = 0x20AC2;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_20AD0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x8FAF] != 0x00) {
            pc = 0x20ADA;
            break;
        }
        return;
    case 0x20ADA:
        memory[ds*16+0x8FAF] = 0x00;
        r16[dx] = 0x03ce;
        r16[ax] = 0x0e00;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[bx] = memory16get(ds*16+0x9186);
        if (r16s[bx] <= signed16(0x0027)) {
            pc = 0x20AFF;
            break;
        }
        r16[bx] = 0x0027;
    case 0x20AFF:
        r16[bx] -= 0x0027;
        r16[bx] = -r16[bx];
        r16[di] = 0x1e83;
        r8[al] = 0x10;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x20B15;
            break;
        }
        r16[di] = 0x1e8f;
        r8[al] = 0x02;
    case 0x20B15:
        r16[cx] = 0x0027;
    case 0x20B18:
        if (r16[cx] != r16[bx]) {
            pc = 0x20B27;
            break;
        }
        push(r16[ax]);
        r16[dx] -= 1;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[ax] = pop();
    case 0x20B27:
        out8(r16[dx], r8[al]);
        memoryVideoAnd(es, r16[di], r8[al]);
        memoryVideoAnd(es, r16[di] + 40, r8[al]);
        memoryVideoAnd(es, r16[di] + 80, r8[al]);
        memoryVideoAnd(es, r16[di] + 8192, r8[al]);
        memoryVideoAnd(es, r16[di] + 8232, r8[al]);
        memoryVideoAnd(es, r16[di] + 8272, r8[al]);
        ror8(al, 1);
        flags.carry = !!(r8[al] & 0x80);
        if (!flags.carry) {
            pc = 0x20B47;
            break;
        }
        r16[di] += 1;
    case 0x20B47:
        if (--r16[cx]) {
            pc = 0x20B18;
            break;
        }
        r16[dx] -= 1;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_20B5B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x33BC) != 0x0000) {
            pc = 0x20B85;
            break;
        }
        push(ds);
        r16[ax] = 0xa000;
        ds = r16[ax];
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r16[si] = 0x1e00;
        r16[di] = 0xfec0;
        r16[cx] = 0x0140;
        rep_movsb_video_video_forward();
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
    case 0x20B85:
        memory[ds*16+0x33BC] += 1;
        return;
    } while (1);
}
function* sub_20B8A() {
    memory[ds*16+0x33BC] -= 1;
    if (memory[ds*16+0x33BC] != 0)
        return;
    push(ds);
    r16[ax] = 0xa000;
    ds = r16[ax];
    es = r16[ax];
    r16[dx] = 0x03ce;
    r16[ax] = 0x0105;
    out16(r16[dx], r16[ax]);
    r16[di] = 0x1e00;
    r16[si] = 0xfec0;
    r16[cx] = 0x0140;
    rep_movsb_video_video_forward();
    r16[di] = 0x3e00;
    r16[si] = 0xfec0;
    r16[cx] = 0x0140;
    rep_movsb_video_video_forward();
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
    return;
}
function* sub_20BBF() {
    r16[dx] = 0x03ce;
    r16[ax] = 0x0105;
    out16(r16[dx], r16[ax]);
    r16[si] = memory16get(ds*16+0x425B);
    r16[di] = memory16get(ds*16+0x4259);
    push(ds);
    r16[ax] = 0xa000;
    ds = r16[ax];
    es = r16[ax];
    r16[cx] = 0x1f40;
    rep_movsb_video_video_forward();
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
}
function* sub_20BE5() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2058D();
        r16[si] = 0x1f4c;
    case 0x20BEC:
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        if (!(r16[ax] & r16[ax])) {
            pc = 0x20C19;
            break;
        }
        bp = r16[ax];
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[di] = r16[ax];
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[dx] = r16[ax];
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[cx] = r16[ax];
        push(r16[si]);
        r16[si] = bp;
        yield* sub_20CBB();
        r16[si] = pop();
        pc = 0x20BEC;
        break;
    case 0x20C19:
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x20C1B:
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x20C1D:
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xec90;
        yield* sub_1F585();
        r16[dx] = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xefc0;
        yield* sub_1F585();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[cx] += 0x0029;
        if (r16s[cx] < signed16(0x00cd)) {
            pc = 0x20C1D;
            break;
        }
        r16[dx] += 0x0029;
        if (r16s[dx] < signed16(0x00a4)) {
            pc = 0x20C1B;
            break;
        }
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x20C59;
            break;
        }
        r16[si] = 0xfc20;
        r16[cx] = 0x00c1;
        r16[dx] = 0x00bc;
        yield* sub_1F585();
    case 0x20C59:
        yield* sub_20BBF();
        return;
    } while (1);
}
function* sub_20C5E() {
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    yield* sub_1F585();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    push(memory16get(ds*16+0x425B));
    r16[ax] = memory16get(ds*16+0x4259);
    memory16set(ds*16+0x425B, r16[ax]);
    yield* sub_1F585();
    memory16set(ds*16+0x425B, pop());
}
function* sub_20C7B() {
    yield* sub_2058D();
    r16[dx] = 0x03ce;
    r16[ax] = 0x0700;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0f01;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = memory16get(ds*16+0x425B);
    r16[di] += 0x0fb4;
    r16[ax] = 0x0608;
    out16(r16[dx], r16[ax]);
    memory[es*16+r16[di]] &= r8[al];
    memory[es*16+r16[di] + 80] &= r8[al];
    r16[ax] = 0x0f08;
    out16(r16[dx], r16[ax]);
    memory[es*16+r16[di] + 40] &= r8[al];
    r16[ax] = 0x0000;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_20CBB() {
    r16[di] = r16[di] + memory16get(ds*16+0x425B);
    push(ds);
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    bp = r16[dx];
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    yield* sub_20CFE();
    r16[si] += 0x0002;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    yield* sub_20CFE();
    r16[si] += 0x0002;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    yield* sub_20CFE();
    r16[si] += 0x0002;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    yield* sub_20CFE();
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
}
function* sub_20CFE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        push(bp);
    case 0x20D02:
        push(r16[di]);
        push(bp);
    case 0x20D04:
        movsb_video_data_forward();
        movsb_video_data_forward();
        r16[si] += 0x0006;
        bp -= 1;
        if (bp != 0) {
            pc = 0x20D04;
            break;
        }
        bp = pop();
        r16[di] = pop();
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x20D02;
            break;
        }
        bp = pop();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_20D18() {
    r16[dx] = 0x03ce;
    r16[ax] = 0x0f01;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = 0x11ea;
    r16[cx] = 0x0045;
    yield* sub_20D87();
    r16[di] = 0x31ea;
    r16[cx] = 0x0045;
    yield* sub_20D87();
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
    r16[ax] = ds;
    es = r16[ax];
}
function* loc_20D45() {
    r16[ax] = 0x0108;
    out16(r16[dx], r16[ax]);
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 1;
    r16[ax] = 0xfe08;
    out16(r16[dx], r16[ax]);
    memoryVideoAnd(es, r16[di], r8[al]);
    r16[di] += 0x001c;
    yield* sub_20D87();
}
function* sub_20D87() {
    if (--r16[cx])
        {
        yield* loc_20D45();
        return;
    }
    return;
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_20D8A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x8430;
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x0182;
        r16[cx] = 0x0034;
        yield* sub_20F91();
        r16[si] = 0x8f90;
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x0ef2;
        r16[cx] = 0x000a;
        yield* sub_20F91();
        r16[si] = 0x91c0;
        if (memory[ds*16+0x8F40] == 0x00) {
            pc = 0x20DCA;
            break;
        }
        yield* sub_10ED9();
        r16[cx] = 0x0004;
        pc = 0x20DC4;
        break;
    case 0x20DC0:
        r16[si] += 0x0770;
    case 0x20DC4:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (flags.carry) {
            pc = 0x20DCA;
            break;
        }
        if (--r16[cx]) {
            pc = 0x20DC0;
            break;
        }
    case 0x20DCA:
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x09a2;
        r16[cx] = 0x0022;
        yield* sub_20F91();
        yield* sub_10EE5();
        yield* sub_10EE9();
        if (memory16get(ds*16+0x8F3C) != 0x0000) {
            pc = 0x20DEC;
            break;
        }
        return;
    case 0x20DEC:
        if (memory16gets(ds*16+0x8F3C) <= signed16(0x0008)) {
            pc = 0x20E34;
            break;
        }
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x0182;
        r16[si] = 0x5c18;
        r16[ax] = 0x0030;
        r16[ax] = r16[ax] - memory16get(ds*16+0x8F3C);
        r16[dx] = 0x0038;
        _mul(r16[dx]);
        r16[si] += r16[ax];
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_20F91();
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x11c2;
        r16[ax] = 0x0028;
        _mul(memory16get(ds*16+0x8F3C));
        r16[di] -= r16[ax];
        r16[si] = 0x64d8;
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_20F91();
    case 0x20E34:
        r16[cx] = 0x00d7;
        r16[dx] = memory16get(ds*16+0x8F3C);
        r16[dx] += 1;
        push(r16[dx]);
        r16[si] = 0xabe4;
        yield* sub_1F585();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xace4;
        yield* sub_1F585();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xad94;
        yield* sub_1F585();
        r16[cx] = 0x00d7;
        r16[dx] = 0x0070;
        r16[dx] = r16[dx] - memory16get(ds*16+0x8F3C);
        push(r16[dx]);
        r16[si] = 0xae94;
        yield* sub_1F585();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xaf94;
        yield* sub_1F585();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xb044;
        yield* sub_1F585();
        if (memory16gets(ds*16+0x8F3C) < signed16(0x0008)) {
            pc = 0x20E8E;
            break;
        }
        return;
    case 0x20E8E:
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x001a;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4750;
        r16[cx] = 0x0009;
    case 0x20EA9:
        push(r16[cx]);
        r16[cx] = 0x0007;
    case 0x20EAD:
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x20EAD;
            break;
        }
        r16[cx] = pop();
        r16[di] += 0x001a;
        r16[si] += 0x0008;
        if (--r16[cx]) {
            pc = 0x20EA9;
            break;
        }
        ds = pop();
        r16[di] = memory16get(ds*16+0x425B);
        r16[di] += 0x1082;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4990;
        r16[cx] = 0x0009;
    case 0x20F04:
        push(r16[cx]);
        r16[cx] = 0x0007;
    case 0x20F08:
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x20F08;
            break;
        }
        r16[cx] = pop();
        r16[di] += 0x001a;
        r16[si] += 0x0008;
        if (--r16[cx]) {
            pc = 0x20F04;
            break;
        }
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_20F54() {
    if (memory16get(ds*16+0x8F3E) == 0x0000)
        return;
    r16[di] = memory16get(ds*16+0x425B);
    r16[di] += 0x11ea;
    r16[cx] = 0x0045;
    r16[cx] = r16[cx] - memory16get(ds*16+0x8F3E);
    r16[dx] = 0x03ce;
    r16[ax] = 0x0f01;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xa000;
    es = r16[ax];
    yield* sub_20D87();
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
    r16[ax] = ds;
    es = r16[ax];
    r16[si] = 0x6d98;
    r16[cx] = memory16get(ds*16+0x8F3E);
    yield* sub_20F91();
    return;
}
function* sub_20F91() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[dx] = 0x03c4;
    case 0x20F9F:
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0108;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[dx] = 0x03c4;
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0108;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[dx] = 0x03c4;
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0108;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[dx] = 0x03c4;
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0108;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[dx] = 0x03c4;
        r16[di] += 0x0002;
        push(r16[cx]);
        r16[cx] = 0x0005;
    case 0x2101E:
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di] + 1, r8[al]);
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x2101E;
            break;
        }
        r16[cx] = pop();
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        lodsb_data_forward();
        memoryVideoSet(es, r16[di], r8[al]);
        lodsb_data_forward();
        r16[di] += 0x001c;
        if (--r16[cx]) {
            pc = 0x21083;
            break;
        }
        pc = 0x21086;
        break;
    case 0x21083:
        pc = 0x20F9F;
        break;
    case 0x21086:
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21090() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[si] = memory16get(ds*16+0x425B);
        r16[ax] = 0x0028;
        _mul(memory16get(ds*16+r16[di] + 4));
        r16[si] += r16[ax];
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[cx] = r16[ax];
        r16[cx] &= 0x0007;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[si] += r16[ax];
        r8[bl] = 0x1c;
        r16[dx] = 0x03ce;
    case 0x210BD:
        yield* sub_10ED9();
        r8[bh] = r8[ah];
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x08;
        r8[ah] = r8[bh];
        r8[ah] >>= r8[cl];
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si], r8[al]);
        r8[ah] = r8[bh];
        ror8(ah, r8[cl]);
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si] + 1, r8[al]);
        memoryVideoAnd(es, r16[si] + 2, r8[al]);
        memoryVideoAnd(es, r16[si] + 3, r8[al]);
        r8[al] = r8[bh];
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si] + 4, r8[al]);
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r8[bh] = (~r8[bh]);
        r8[al] = 0x08;
        r8[ah] = r8[bh];
        r8[ah] >>= r8[cl];
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si], r8[al]);
        r8[ah] = r8[bh];
        ror8(ah, r8[cl]);
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si] + 1, r8[al]);
        memoryVideoAnd(es, r16[si] + 2, r8[al]);
        memoryVideoAnd(es, r16[si] + 3, r8[al]);
        r8[al] = r8[bh];
        r8[ah] = r8[ah] ^ r8[ah];
        ror16(ax, r8[cl]);
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        memoryVideoAnd(es, r16[si] + 4, r8[al]);
        r16[si] += 0x0028;
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x210BD;
            break;
        }
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21132() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] != 0x0d) {
            pc = 0x2113B;
            break;
        }
    {yield* loc_10EED(); return; };
    case 0x2113B:
        push(r16[ax]);
        r16[ax] = 0x0028;
        _mul(memory16get(ds*16+0x8F48));
        r16[di] = r16[ax];
        r16[ax] = memory16get(ds*16+0x8F46);
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        r16[ax] = pop();
        r8[al] -= 0x20;
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] = 0x7cb0;
        r16[si] += r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0xf008;
        if (!(memory16get(ds*16+0x8F46) & 0x0001)) {
            pc = 0x21175;
            break;
        }
        r8[ah] = 0x0f;
    case 0x21175:
        out16(r16[dx], r16[ax]);
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        yield* sub_211B0();
        r16[ax] = 0x0202;
        out16(r16[dx], r16[ax]);
        yield* sub_211B0();
        r16[ax] = 0x0402;
        out16(r16[dx], r16[ax]);
        yield* sub_211B0();
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        yield* sub_211B0();
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        memory16set(ds*16+0x8F46, memory16get(ds*16+0x8F46) + 1);
        return;
    } while (1);
}
function* sub_211B0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        r16[cx] = 0x0008;
    case 0x211B4:
        lodsb_data_forward();
        r8[ah] = memoryVideoGet(es, r16[di]);
        memoryVideoSet(es, r16[di], r8[al]);
        r8[ah] = memoryVideoGet(es, r16[di] + 8192);
        memoryVideoSet(es, r16[di] + 8192, r8[al]);
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x211B4;
            break;
        }
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_211CC() {
    r16[si] = 0xaf80;
    r16[di] = 0x0786;
    r16[dx] = 0x000d;
    r16[cx] = 0x0036;
    yield* sub_20CBB();
}
function* sub_2120E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+r16[si] + 28) < 0 /*CHECK*/) {
            pc = 0x2121A;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x2122A;
            break;
        }
    case 0x2121A:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32CA);
        yield* sub_1F585();
        r16[si] = pop();
    case 0x2122A:
        if (memory16gets(ds*16+r16[si] + 28) >= 0 /*CHECK*/) {
            pc = 0x21236;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x2124A;
            break;
        }
    case 0x21236:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] = r16[dx] + memory16get(ds*16+r16[si] + 26);
        r16[dx] -= 1;
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32C4);
        yield* sub_1F585();
        r16[si] = pop();
    case 0x2124A:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        r16[ax] -= 1;
        if (_FIXME_) {
            pc = 0x2125C;
            break;
        }
        return;
    case 0x2125C:
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] -= 1;
        r16[dx] = memory16get(ds*16+0x32BC);
        r16[dx] -= 0x00bf;
        if (_FIXME_) {
            pc = 0x21277;
            break;
        }
        r16[ax] -= r16[dx];
        if (_FIXME_)
            return;
        memory16set(ds*16+0x32BC, 0x00bf);
    case 0x21277:
        memory16set(ds*16+0x32BE, r16[ax]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0700;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = 0x0028;
        _mul(memory16get(ds*16+0x32BC));
        r16[di] = memory16get(ds*16+0x425B);
        bp = r16[di];
        r16[di] += r16[ax];
        r16[ax] = memory16get(ds*16+0x32BA);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        r16[di] += r16[ax];
        r16[dx] = memory16get(ds*16+0x32BA);
        r16[dx] &= 0xfff8;
        r16[cx] = memory16get(ds*16+0x32BA);
        r16[cx] &= 0x0007;
        r8[ah] = 0xff;
        r8[ah] >>= r8[cl];
        yield* sub_20829();
        r16[di] += 1;
        r16[dx] += 0x0008;
        r16[ax] = 0xf0ff;
        ror16(ax, r8[cl]);
        yield* sub_20829();
        r16[di] += 1;
        r16[dx] += 0x0008;
        r8[ah] = r8[ah] ^ r8[ah];
        r8[al] = 0xf0;
        ror16(ax, r8[cl]);
        yield* sub_20829();
        r16[ax] = ds;
        es = r16[ax];
        r16[dx] = 0x03ce;
        r16[ax] = 0x0000;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* loc_2130B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2133E();
        r16[dx] = 0x03bf;
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03b8;
        r8[al] = r8[al] ^ r8[al];
        out8(r16[dx], r8[al]);
        r8[dl] -= 0x04;
        r16[si] = 0x4243;
        r16[cx] = 0x0009;
    case 0x21323:
        lodsw_data_forward();
        out16(r16[dx], r16[ax]);
        if (--r16[cx]) {
            pc = 0x21323;
            break;
        }
        push(es);
        r16[ax] = 0xb000;
        es = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x4000;
        rep_stosw_data_forward();
        es = pop();
        r8[dl] += 0x04;
        r8[al] = 0x0a;
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_2133E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x973e;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x00c8;
    case 0x21346:
        stosw_data_forward();
        r16[ax] += 0x0050;
        if (--r16[cx]) {
            pc = 0x21346;
            break;
        }
        return;
    } while (1);
}
function* sub_2134D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000a;
    case 0x21350:
        push(r16[cx]);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[cx] = 0x2000;
        r16[si] = r16[si] ^ r16[si];
    case 0x2135B:
        memory16set(es*16+r16[si], memory16get(es*16+r16[si]) ^ 0xffff);
        r16[si] += 0x0002;
        if (--r16[cx]) {
            pc = 0x2135B;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x21350;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2136C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000a;
    case 0x2136F:
        push(r16[cx]);
        r16[ax] = 0xb000;
        es = r16[ax];
        r16[cx] = 0x4000;
        r16[si] = r16[si] ^ r16[si];
    case 0x2137A:
        memory16set(es*16+r16[si], memory16get(es*16+r16[si]) ^ 0xffff);
        r16[si] += 0x0002;
        if (--r16[cx]) {
            pc = 0x2137A;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2136F;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2138B() {
    var cs = _seg001;
    memory16set(cs*16+0x38A5, 0x38ad);
    r16[dx] = _seg007;
    r16[si] = r16[si] ^ r16[si];
    r16[cx] = 0x6be6;
    yield* sub_214E6();
    r16[dx] = _seg007;
    r16[si] = 0x6be6;
    r16[cx] = 0x3fd6;
    yield* sub_214E6();
    memory16set(cs*16+0x38A5, 0x396d);
    r16[dx] = _seg007;
    r16[si] = 0xabbc;
    r16[cx] = 0x5324;
    yield* sub_214E6();
    memory16set(cs*16+0x38A5, 0x38ad);
    r16[si] = 0x0000;
    r16[cx] = 0x0140;
    yield* sub_2162C();
    memory16set(cs*16+0x38A5, 0x398d);
    r16[si] = 0x0500;
    r16[cx] = 0x000a;
    yield* sub_21696();
    memory16set(cs*16+0x38A5, 0x39ad);
    r16[si] = 0x0640;
    r16[cx] = 0x000a;
    yield* sub_21696();
    memory16set(cs*16+0x38A5, 0x394d);
    r16[si] = 0x0780;
    r16[cx] = 0x0028;
    r16[dx] = 0x0016;
    yield* sub_216E8();
    r16[si] = 0x2300;
    r16[cx] = 0x002a;
    r16[dx] = 0x000e;
    yield* sub_216E8();
    r16[si] = 0xaf80;
    r16[cx] = 0x02be;
    memory16set(cs*16+0x38AB, 0x0017);
    yield* sub_215BB();
    memory16set(cs*16+0x38A5, 0x398d);
    r16[si] = 0x7cb0;
    r16[cx] = 0x003c;
    yield* sub_21696();
    memory16set(cs*16+0x38A5, 0x396d);
    memory16set(cs*16+0x38AB, 0x0007);
    r16[si] = 0x5c18;
    r16[cx] = 0x0118;
    yield* sub_215BB();
    r16[si] = 0x64d8;
    r16[cx] = 0x0118;
    yield* sub_215BB();
    r16[si] = 0x6d98;
    r16[cx] = 0x01e3;
    yield* sub_215BB();
    r16[si] = 0x8430;
    r16[cx] = 0x016c;
    yield* sub_215BB();
    r16[si] = 0x8f90;
    r16[cx] = 0x0046;
    yield* sub_215BB();
    r16[si] = 0x91c0;
    r16[cx] = 0x03b8;
    yield* sub_215BB();
    memory16set(cs*16+0x38AB, 0x0002);
    r16[si] = 0x3560;
    r16[cx] = 0x017e;
    yield* sub_215BB();
    memory16set(cs*16+0x38AB, 0x0001);
    r16[si] = 0x4150;
    r16[cx] = 0x00bf;
    yield* sub_215BB();
    memory16set(cs*16+0x38AB, 0x0008);
    r16[si] = 0x4748;
    r16[cx] = 0x0048;
    yield* sub_215BB();
    r16[si] = 0x4988;
    r16[cx] = 0x0048;
    yield* sub_215BB();
    r16[si] = 0x4bc8;
    r16[cx] = 0x005a;
    yield* sub_215BB();
    memory16set(cs*16+0x38AB, 0x000c);
    r16[si] = 0x4e98;
    r16[cx] = 0x01b0;
    yield* sub_215BB();
}
function* sub_214C2() {
    var cs = _seg001;
    r16[ax] = memory16get(ds*16+0x991C);
    r16[ax] -= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x38ad;
    memory16set(cs*16+0x38A5, r16[ax]);
    r16[dx] = _seg008;
    r16[si] = r16[si] ^ r16[si];
    r16[cx] = 0xf468;
    yield* sub_214E6();
    yield* sub_2154D();
}
function* sub_214E6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        ds = r16[dx];
        bp = r16[si];
        bp += r16[cx];
        r16[si] += 0x0020;
    case 0x214F5:
        r16[si] += 0x000c;
        lodsw_data_forward();
        if (!(r16[ax] & r16[ax])) {
            pc = 0x21547;
            break;
        }
        r16[bx] = r16[ax];
        lodsw_data_forward();
        push(r16[si]);
        r16[cx] = r16[ax];
        r16[cx] += 1;
        r16[dx] = r16[cx];
        if (r16s[bx] <= signed16(0x0008)) {
            pc = 0x2151B;
            break;
        }
        r16[dx] += r16[cx];
        if (r16s[bx] <= signed16(0x0010)) {
            pc = 0x2151B;
            break;
        }
        r16[dx] += r16[cx];
        if (r16s[bx] <= signed16(0x0018)) {
            pc = 0x2151B;
            break;
        }
        r16[dx] += r16[cx];
    case 0x2151B:
        push(bp);
        bp = r16[si];
        push(r16[si]);
        r16[di] = r16[di] ^ r16[di];
        yield* sub_21765();
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        bp = pop();
        r16[si] = pop();
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        r16[si] += 1;
        r16[si] &= 0xfffe;
        if (r16[si] < bp) {
            pc = 0x214F5;
            break;
        }
    case 0x21547:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2154D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg009;
        ds = r16[ax];
        r16[cx] = 0x01c9;
        r16[si] = r16[si] ^ r16[si];
    case 0x2155D:
        push(r16[si]);
        push(r16[cx]);
        push(r16[si]);
        r16[di] = r16[di] ^ r16[di];
        yield* sub_21582();
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[cx] = pop();
        r16[si] = pop();
        r16[si] += 0x0080;
        if (--r16[cx]) {
            pc = 0x2155D;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21582() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0010;
        memory16set(cs*16+0x38A7, 0x0000);
    case 0x2158C:
        yield* sub_2159D();
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        if (--r16[cx]) {
            pc = 0x2158C;
            break;
        }
        return;
    } while (1);
}
function* sub_2159D() {
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_217DB();
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_217DB();
    r16[si] += 0x0006;
}
function* sub_215BB() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        memory16set(cs*16+0x38A7, 0x0000);
        r16[ax] = memory16get(cs*16+0x38AB);
        memory16set(cs*16+0x38A9, r16[ax]);
        push(r16[si]);
    case 0x215D8:
        yield* sub_2160E();
        memory16set(cs*16+0x38A9, memory16get(cs*16+0x38A9) - 1);
        if (memory16get(cs*16+0x38A9) != 0) {
            pc = 0x215F5;
            break;
        }
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        r16[ax] = memory16get(cs*16+0x38AB);
        memory16set(cs*16+0x38A9, r16[ax]);
    case 0x215F5:
        if (--r16[cx]) {
            pc = 0x215D8;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        push(r16[si]);
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = pop();
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2160E() {
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_217DB();
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_217DB();
    r16[si] += 0x0006;
}
function* sub_2162C() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[dx] = r16[cx];
        memory16set(cs*16+0x38A7, 0x0000);
        memory16set(cs*16+0x38A9, 0x0028);
        push(r16[si]);
    case 0x2164A:
        yield* sub_2167F();
        memory16set(cs*16+0x38A9, memory16get(cs*16+0x38A9) - 1);
        if (memory16get(cs*16+0x38A9) != 0) {
            pc = 0x21666;
            break;
        }
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        memory16set(cs*16+0x38A9, 0x0028);
    case 0x21666:
        if (--r16[cx]) {
            pc = 0x2164A;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        push(r16[si]);
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = pop();
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2167F() {
    r16[si] += r16[dx];
    r8[ah] = memory[ds*16+r16[si]];
    r16[si] += r16[dx];
    r8[bl] = memory[ds*16+r16[si]];
    r16[si] += r16[dx];
    r8[bh] = memory[ds*16+r16[si]];
    r16[si] -= r16[dx];
    r16[si] -= r16[dx];
    r16[si] -= r16[dx];
    lodsb_data_forward();
    yield* sub_217DB();
}
function* sub_21696() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        push(r16[si]);
    case 0x216A4:
        push(r16[cx]);
        yield* sub_216C0();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x216A4;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_216C0() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0008;
        memory16set(cs*16+0x38A7, 0x0000);
    case 0x216CA:
        r8[ah] = memory[ds*16+r16[si] + 8];
        r8[bl] = memory[ds*16+r16[si] + 16];
        r8[bh] = memory[ds*16+r16[si] + 24];
        lodsb_data_forward();
        yield* sub_217DB();
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        if (--r16[cx]) {
            pc = 0x216CA;
            break;
        }
        r16[si] += 0x0018;
        return;
    } while (1);
}
function* sub_216E8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        push(r16[si]);
    case 0x216F6:
        push(r16[cx]);
        yield* sub_21712();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x216F6;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21712() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[cx] = r16[dx];
        r16[dx] <<= 1;
        memory16set(cs*16+0x38A7, 0x0000);
    case 0x2171E:
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        lodsb_data_forward();
        yield* sub_217DB();
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        lodsb_data_forward();
        yield* sub_217DB();
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        if (--r16[cx]) {
            pc = 0x2171E;
            break;
        }
        r16[dx] >>= 1;
        r16[si] = pop();
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        return;
    } while (1);
}
function* sub_21765() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(cs*16+0x38A7, 0x0000);
        push(r16[cx]);
    case 0x2176D:
        push(r16[cx]);
        yield* sub_21781();
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) + 1);
        memory16set(cs*16+0x38A7, memory16get(cs*16+0x38A7) & 0x0007);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2176D;
            break;
        }
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_21781() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
    case 0x21782:
        push(r16[bx]);
        r8[ah] = memory[ds*16+r16[si]];
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        stosb_data_forward();
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        rol16(ax, 1);
        assert(0); /* unk previous */ rcl8(al, 1);
        stosb_data_forward();
        r16[si] += r16[dx];
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] += 1;
        yield* sub_217DB();
        r8[al] = memory[es*16+r16[di] + -3];
        r8[ah] = memory[es*16+r16[di] + -2];
        memory[es*16+r16[di] + -2] = r8[al];
        memory[es*16+r16[di] + -3] = r8[ah];
        r16[bx] = pop();
        r16[bx] -= 0x0008;
        if (_FIXME_) {
            pc = 0x21782;
            break;
        }
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_217DB() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        push(r16[dx]);
        push(r16[cx]);
        r16[cx] = 0x0002;
    case 0x217E1:
        push(r16[cx]);
        r16[cx] = 0x0000;
        r8[dh] = r8[dh] ^ r8[dh];
    case 0x217E7:
        r8[dl] = r8[dl] ^ r8[dl];
        flags.carry = !!(r8[bh] & 0x80);
        r8[bh] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        rcl8(dl, 1);
        bp = r16[dx];
        bp &= 0x000f;
        bp <<= 1;
        bp = bp + memory16get(cs*16+0x38A5);
        bp = memory16get(cs*16+bp);
        bp <<= 1;
        bp <<= 1;
        bp <<= 1;
        bp = bp + memory16get(cs*16+0x38A7);
        r8[dl] = memory[cs*16+bp + 14381];
        r8[dl] <<= r8[cl];
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[cx] += 0x0002;
        if (r16s[cx] < signed16(0x0008)) {
            pc = 0x217E7;
            break;
        }
        memory[es*16+r16[di]] = r8[dh];
        r16[di] += 1;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x217E1;
            break;
        }
        r16[cx] = pop();
        r16[dx] = pop();
        bp = pop();
        return;
    } while (1);
}
function* sub_21836() {
    var cs = _seg001;
    memory[cs*16+0x25A5] = 0x01;
}
function* sub_2183D() {
    var cs = _seg001;
    memory[cs*16+0x25A5] = 0x00;
}
function* sub_21844() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9198);
        yield* sub_10ED5();
        push(es);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
        r8[al] = 0x08;
    case 0x2185A:
        r16[di] = memory16get(ds*16+r16[si]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+r16[si] + 2);
        memory[es*16+r16[di]] |= 0x18;
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x2185A;
            break;
        }
        es = pop();
        return;
    } while (1);
}
function* sub_21870() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
    case 0x2187B:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] &= 0x7fff;
        r16[ax] -= 0x0200;
        if (r16s[ax] > signed16(0x0200)) {
            pc = 0x218A5;
            break;
        }
    case 0x21889:
        yield* sub_10ED9();
        memory16set(ds*16+r16[si], r16[ax]);
        yield* sub_10ED9();
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        yield* sub_10ED9();
        r16[ax] &= 0x1fff;
        if (r16s[ax] <= signed16(0x0200)) {
            pc = 0x21889;
            break;
        }
    case 0x218A5:
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x00a0;
        if (r16[ax] >= 0x0140) {
            pc = 0x21889;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x0064;
        if (r16[ax] >= 0x00c8) {
            pc = 0x21889;
            break;
        }
        r16[di] = r16[ax];
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        push(r16[cx]);
        r16[cx] = r16[bx];
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[di] += r16[bx];
        r8[ah] = 0xc0;
        r8[ah] >>= r8[cl];
        r16[cx] = pop();
        memory[es*16+r16[di]] |= r8[ah];
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x2190C;
            break;
        }
        pc = 0x2190F;
        break;
    case 0x2190C:
        pc = 0x2187B;
        break;
    case 0x2190F:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21914() {
    r16[cx] = memory16get(ds*16+r16[si] + 18);
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[si] = memory16get(ds*16+r16[si] + 12);
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_2191D() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x2192A;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x2192A:
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x21942;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x21942:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x2194C;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x2194C:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x21955;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x21955:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x2195E;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x2195E:
        memory16set(ds*16+0x0, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x21972;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
    case 0x21972:
        if (r16s[dx] >= 0) {
            pc = 0x219A4;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x2199F;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x2198E;
            break;
        }
        r16[ax] <<= 1;
        pc = 0x2199F;
        break;
    case 0x2198E:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x2199B;
            break;
        }
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        pc = 0x2199F;
        break;
    case 0x2199B:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
    case 0x2199F:
        memory16set(ds*16+0x0, r16[ax]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x219A4:
        r16[di] = r16[dx];
        r16[di] <<= 1;
        push(ds);
        r16[ax] = dseg;
        ds = r16[ax];
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        ds = pop();
        if (r16s[cx] >= 0) {
            pc = 0x219BF;
            break;
        }
        pc = 0x21C06;
        break;
    case 0x219BF:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] <= signed16(0x0140)) {
            pc = 0x219CB;
            break;
        }
        pc = 0x21C06;
        break;
    case 0x219CB:
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x219E4;
            break;
        }
        pc = 0x21BC2;
        break;
    case 0x219E4:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x219EC;
            break;
        }
        pc = 0x21B54;
        break;
    case 0x219EC:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x219F4;
            break;
        }
        pc = 0x21AB9;
        break;
    case 0x219F4:
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[al] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[dl] >>= r8[cl];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r8[al] = r8[al] ^ r8[al];
        r8[dl] = r8[dl] ^ r8[dl];
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[dh] = memory[ds*16+r16[si] - 1];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r16[di] += 0x0047;
        r8[bl] -= 1;
        if (r8s[bl] < 0) {
            pc = 0x21AB6;
            break;
        }
        pc = 0x219F4;
        break;
    case 0x21AB6:
        pc = 0x21C9B;
        break;
    case 0x21AB9:
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[al] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[dl] >>= r8[cl];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r8[al] = r8[al] ^ r8[al];
        r8[dl] = r8[dl] ^ r8[dl];
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[dh] = memory[ds*16+r16[si] - 1];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r16[di] += 0x0049;
        r8[bl] -= 1;
        if (r8s[bl] < 0) {
            pc = 0x21B51;
            break;
        }
        pc = 0x21AB9;
        break;
    case 0x21B51:
        pc = 0x21C9B;
        break;
    case 0x21B54:
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[al] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[dl] >>= r8[cl];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r8[al] = r8[al] ^ r8[al];
        r8[dl] = r8[dl] ^ r8[dl];
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[dh] = memory[ds*16+r16[si] - 1];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r16[di] += 0x004b;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21B54;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x21BC2:
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[al] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[dl] >>= r8[cl];
        r8[al] |= r8[dl];
        stosb_data_forward();
        lodsw_data_forward();
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r8[al] = r8[al] ^ r8[al];
        r8[dl] = r8[dl] ^ r8[dl];
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[dh] = memory[ds*16+r16[si] - 1];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        stosb_data_forward();
        r16[di] += 0x004d;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21BC2;
            break;
        }
        pc = 0x21C9B;
        break;
    case 0x21C06:
        r16[dx] = r16[cx];
        sar16(dx, 1);
        sar16(dx, 1);
        r16[di] += r16[dx];
        r16[dx] = r16[cx];                    
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        {var t = r16[dx]; r16[dx] = bp; bp = t;}//_xchg(r16[dx], bp);
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        r16[dx] += 0x0007;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] <<= 1;
        r16[dx] -= 1;
        memory[cs*16+0x2A11] = r8[dl];
    case 0x21C2C:
        push(bp);
        push(r16[di]);
        lodsw_data_forward();
        if (bp >= 0x0140) {
            pc = 0x21C45;
            break;
        }
        r8[dl] = r8[ah];
        r8[al] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[dl] >>= r8[cl];
        r8[al] |= r8[dl];
        memory[es*16+r16[di]] = r8[al];
    case 0x21C45:
        r16[di] += 1;
        bp += 0x0004;
        r8[bh] = memory[cs*16+0x2A11];
    case 0x21C4E:
        lodsw_data_forward();
        if (bp >= 0x0140) {
            pc = 0x21C6B;
            break;
        }
        r8[dl] = r8[ah];
        r8[ah] = memory[ds*16+r16[si] - 4];
        r8[dh] = memory[ds*16+r16[si] - 3];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        memory[es*16+r16[di]] = r8[al];
    case 0x21C6B:
        r16[di] += 1;
        bp += 0x0004;
        r8[bh] -= 1;
        if (r8[bh] != 0) {
            pc = 0x21C4E;
            break;
        }
        if (bp >= 0x0140) {
            pc = 0x21C91;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
        r8[dl] = r8[dl] ^ r8[dl];
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[dh] = memory[ds*16+r16[si] - 1];
        r16[ax] >>= r8[cl];
        r16[dx] >>= r8[cl];
        r8[al] = (~r8[al]);
        r8[al] = r8[al] & memory[es*16+r16[di]];
        r8[al] |= r8[dl];
        memory[es*16+r16[di]] = r8[al];
    case 0x21C91:
        r16[di] += 1;
        r16[di] = pop();
        bp = pop();
        r16[di] += 0x0050;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21C2C;
            break;
        }
    case 0x21C9B:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21CA2() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(cs);
        yield* sub_21914();
        r16[si] = pop();
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[di] = memory16get(ds*16+r16[si] + 12);
        r16[cx] = _seg007;
        if (!(r16[di] & 0x0001)) {
            pc = 0x21CBE;
            break;
        }
        r16[di] -= 1;
        r16[cx] = _seg008;
    case 0x21CBE:
        push(es);
        es = r16[cx];
        r16[ax] = r16[ax] - memory16get(es*16+r16[di]);
        r16[bx] = r16[bx] - memory16get(es*16+r16[di] + 2);
        es = pop();
        yield* sub_21CDF();
        r16[ax] += 0x0010;
        yield* sub_21CDF();
        r16[bx] += 0x0010;
        yield* sub_21CDF();
        r16[ax] -= 0x0010;
        yield* sub_21CDF();
        return;
    } while (1);
}
function* sub_21CDF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[ax]);
        push(r16[bx]);
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[cx] = r16[ax];
        r16[cx] &= 0xfff0;
        r16[cx] >>= 1;
        if (r16[cx] >= 0x00a0) {
            pc = 0x21D3E;
            break;
        }
        r16[dx] = r16[bx];
        r16[dx] = r16[dx] + memory16get(ds*16+0x9196);
        r16[dx] &= 0xfff0;
        r16[dx] = r16[dx] - memory16get(ds*16+0x9196);
        r16[bx] = r16[bx] + memory16get(ds*16+0x9196);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] &= 0x00fe;
        r16[si] += r16[ax];
        r16[ax] = 0x0028;
        push(r16[dx]);
        _mul(r16[bx]);
        r16[dx] = pop();
        r16[si] += r16[ax];
        push(es);
        r16[ax] = _seg000;
        es = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(es*16+0xEFE0, r16[ax]);
        es = pop();
        r16[ax] = 0x0001;
        r16[bx] = 0x0001;
        r16[si] = 0xefe0;
        yield* sub_1EDE0();
    case 0x21D3E:
        r16[bx] = pop();
        r16[ax] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_21D42() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 4, 0x0853);
    case 0x21D47:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
    case 0x21D50:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x21D5D;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x21D5D:
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x21D75;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21D75:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x21D7F;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21D7F:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x21D88;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21D88:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x21D91;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21D91:
        memory16set(ds*16+0x0, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x21DA5;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
    case 0x21DA5:
        if (r16s[dx] >= 0) {
            pc = 0x21DD7;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x21DD2;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x21DC1;
            break;
        }
        r16[ax] <<= 1;
        pc = 0x21DD2;
        break;
    case 0x21DC1:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x21DCE;
            break;
        }
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        pc = 0x21DD2;
        break;
    case 0x21DCE:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
    case 0x21DD2:
        memory16set(ds*16+0x0, r16[ax]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x21DD7:
        r16[di] = r16[dx];
        r16[di] <<= 1;
        push(ds);
        r16[ax] = dseg;
        ds = r16[ax];
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        ds = pop();
        if (r16s[cx] >= 0) {
            pc = 0x21DF2;
            break;
        }
        pc = 0x21F41;
        break;
    case 0x21DF2:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] <= signed16(0x0140)) {
            pc = 0x21DFE;
            break;
        }
        pc = 0x21F43;
        break;
    case 0x21DFE:
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x21E17;
            break;
        }
        pc = 0x21F1B;
        break;
    case 0x21E17:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x21E1F;
            break;
        }
        pc = 0x21EDF;
        break;
    case 0x21E1F:
        if (signed16(bp) <= signed16(0x0018)) {
            pc = 0x21E8D;
            break;
        }
    case 0x21E24:
        lodsb_data_forward();
        r16[si] += 1;
        r8[al] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 1];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 0x0048;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21E24;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21E8D:
        lodsb_data_forward();
        r16[si] += 1;
        r8[al] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 0x004a;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21E8D;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21EDF:
        lodsb_data_forward();
        r16[si] += 1;
        r8[al] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 0x004c;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21EDF;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21F1B:
        lodsb_data_forward();
        r16[si] += 1;
        r8[al] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        lodsb_data_forward();
        r16[si] += 1;
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 1;
        r8[ah] = memory[ds*16+r16[si] - 2];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        r16[di] += 0x004e;
        r8[bl] -= 1;
        if (r8s[bl] >= 0) {
            pc = 0x21F1B;
            break;
        }
        pc = 0x21F45;
        break;
    case 0x21F41:
        pc = 0x21F45;
        break;
    case 0x21F43:
        _STOP_("goto $+2");
    case 0x21F45:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21F4B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si]);
        if (r16[bx] >= 0x0140)
            return;
        r16[dx] = r16[dx] - memory16get(ds*16+r16[si] + 2);
        if (r16s[dx] >= signed16(0x00c0))
            return;
        r16[cx] = memory16get(ds*16+r16[si] + 4);
        r16[ax] = r16[bx];
        r16[bx] &= 0x0003;
        r16[ax] = r16[ax] ^ r16[bx];
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + r16[si] + 6);
        if (r16s[dx] >= 0) {
            pc = 0x21F82;
            break;
        }
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[cx] += r16[dx];
        if (r16s[cx] <= signed16(0))
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x21F82:
        r16[bx] = r16[dx];
        r16[bx] += r16[cx];
        r16[bx] -= 0x00c0;
        if (_FIXME_) {
            pc = 0x21F90;
            break;
        }
        r16[cx] -= r16[bx];
        if (_FIXME_)
            return;
    case 0x21F90:
        r16[bx] = r16[ax];
        r16[di] = r16[dx];
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[di] += r16[bx];
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        if (r16s[bx] >= signed16(0x0138)) {
            pc = 0x21FBA;
            break;
        }
    case 0x21FAB:
        lodsb_data_forward();
        yield* sub_21FC9();
        lodsb_data_forward();
        yield* sub_21FC9();
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x21FAB;
            break;
        }
        pc = 0x21FC4;
        break;
    case 0x21FBA:
        lodsb_data_forward();
        yield* sub_21FC9();
        r16[si] += 1;
        r16[di] += 0x004e;
        if (--r16[cx]) {
            pc = 0x21FBA;
            break;
        }
    case 0x21FC4:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_21FC9() {
    r8[ah] = r8[al];
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    memory[es*16+r16[di]] |= r8[al];
    r16[di] += 1;
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    rol16(ax, 1);
    assert(0); /* unk previous */ rcl8(al, 1);
    memory[es*16+r16[di]] |= r8[al];
    r16[di] += 1;
}
function* sub_21FF4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[di] ^ r16[di];
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[dx] = memory16get(ds*16+0x9196);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[cx] = 0x0010;
        r16[cx] -= r16[dx];
        r8[bl] = 0x14;
    case 0x2200D:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] += r16[dx];
        r16[si] <<= 1;
        r16[si] <<= 1;
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        push(r16[cx]);
    case 0x22021:
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += 0x004c;
        if (--r16[cx]) {
            pc = 0x22021;
            break;
        }
        bp = r16[di];
        r16[cx] = pop();
        r16[di] = pop();
        r16[di] += 0x0004;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x2200D;
            break;
        }
        r16[di] = bp;
        r16[di] -= 0x004c;
        r16[bx] = 0x0b14;
        bp = 0x004c;
    case 0x22040:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] <<= 1;
        r16[si] <<= 1;
        r16[cx] = ds;
        r16[ax] = _seg009;
        ds = r16[ax];
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        r16[di] -= 0x04fc;
        ds = r16[cx];
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x22040;
            break;
        }
        r8[bl] = 0x14;
        r16[di] += 0x04b0;
        r8[bh] -= 1;
        if (r8[bh] != 0) {
            pc = 0x22040;
            break;
        }
        if (!(r16[dx] & r16[dx])) {
            pc = 0x220CF;
            break;
        }
        r8[bl] = 0x14;
    case 0x220AC:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] <<= 1;
        r16[si] <<= 1;
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        r16[cx] = r16[dx];
    case 0x220BF:
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += bp;
        if (--r16[cx]) {
            pc = 0x220BF;
            break;
        }
        r16[di] = pop();
        r16[di] += 0x0004;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x220AC;
            break;
        }
    case 0x220CF:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_220D4() {
    yield* sub_22152();
    yield* sub_220DC();
}
function* sub_220DC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        if (memory16get(ds*16+0x3044) == 0x0004) {
            pc = 0x22111;
            break;
        }
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[ax] = memory16get(ds*16+0x4255);
        ds = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x0064;
    case 0x220F5:
        push(r16[cx]);
        r16[cx] = 0x0028;
        rep_movsw_data_data_forward();
        r16[di] += 0x1fb0;
        r16[cx] = 0x0028;
        rep_movsw_data_data_forward();
        r16[di] -= 0x2000;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x220F5;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    case 0x22111:
        r16[ax] = 0xb000;
        es = r16[ax];
        r16[ax] = memory16get(ds*16+0x4255);
        ds = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x015c;
        r16[ax] = 0x00ae;
    case 0x22125:
        push(r16[cx]);
        r16[cx] = 0x0028;
        r16[di] += 0x0005;
        rep_movsw_data_data_forward();
        r16[di] += 0x0005;
        flags.sign = signed16(r16[di] + 0x1fa6) < 0;
        r16[di] += 0x1fa6;
        if (!flags.sign) {
            pc = 0x2213B;
            break;
        }
        r16[di] -= 0x7fa6;
    case 0x2213B:
        r16[ax] += 0x0094;
        if (r16s[ax] < signed16(0x015c)) {
            pc = 0x22149;
            break;
        }
        r16[si] -= 0x0050;
        r16[ax] -= 0x015c;
    case 0x22149:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x22125;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22152() {
    push(es);
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[ax] = r16[ax] ^ r16[ax];
    r16[di] = r16[di] ^ r16[di];
    r16[cx] = 0x1f40;
    rep_stosw_data_forward();
    es = pop();
}
function* sub_22163() {
    yield* sub_22152();
}
function* sub_22168() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_10EF1();
    case 0x2216D:
        if (memory16get(ds*16+0x3046) == 0x0000) {
            pc = 0x2216D;
            break;
        }
        memory16set(ds*16+0x3046, 0x0000);
        yield* sub_220DC();
        return;
    } while (1);
}
function* sub_2217E() {
    push(ds);
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[si] = 0x0000;
    r16[di] = 0x3c00;
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[cx] = 0x0140;
    rep_movsw_data_data_forward();
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
}
function* sub_2219A() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[si] = 0x9c80;
        r16[cx] = 0x0050;
    case 0x221A5:
        lodsw_data_forward();
        if (r16s[ax] < 0) {
            pc = 0x22223;
            break;
        }
        r16[bx] = r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[bx] += r16[ax];
        lodsw_data_forward();
        r16[dx] += r16[ax];
        if (r16[bx] >= 0x013c) {
            pc = 0x2221C;
            break;
        }
        if (r16[dx] >= 0x00bc) {
            pc = 0x2221C;
            break;
        }
        memory16set(ds*16+r16[si] - 8, r16[bx]);
        memory16set(ds*16+r16[si] - 6, r16[dx]);
        push(r16[bx]);
        push(r16[dx]);
        push(r16[cx]);
        r16[ax] = r16[bx];
        r16[bx] = r16[dx];
        yield* sub_10EDD();
        if (_FIXME_) {
            pc = 0x221EC;
            break;
        }
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = memory16get(cs*16+0x3DA8);
        push(r16[si]);
        yield* sub_10EE1();
        r16[si] = pop();
        es = pop();
        r16[cx] = pop();
        sp += 0x0004;
        pc = 0x2221C;
        break;
    case 0x221EC:
        r16[cx] = pop();
        r16[dx] = pop();
        r16[di] = r16[dx];
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = pop();
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        r16[ax] = 0xf000;
        r16[ax] >>= r8[cl];
        r16[cx] = pop();
        memory[es*16+r16[di]] |= r8[ah];
        memory[es*16+r16[di] + 80] |= r8[ah];
        memory[es*16+r16[di] + 1] |= r8[al];
        memory[es*16+r16[di] + 81] |= r8[al];
        pc = 0x22226;
        break;
    case 0x2221C:
        memory16set(ds*16+r16[si] - 8, 0xffff);
        pc = 0x22226;
        break;
    case 0x22223:
        r16[si] += 0x0006;
    case 0x22226:
        if (--r16[cx]) {
            pc = 0x2222A;
            break;
        }
        pc = 0x2222D;
        break;
    case 0x2222A:
        pc = 0x221A5;
        break;
    case 0x2222D:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22232() {
    r16[ax] = memory16get(ds*16+r16[si] + 52);
    memory16set(ds*16+0xFCFE, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 18);
    memory16set(ds*16+0xFCE2, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 22);
    memory16set(ds*16+0xFCE6, r16[ax]);
    push(r16[si]);
    yield* sub_2224B();
    r16[si] = pop();
}
function* sub_2224B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + 0x0004);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0x32C0, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        memory16set(ds*16+0x32BE, r16[ax]);
        if (memory16gets(ds*16+0xFCE2) > signed16(0xfff0)) {
            pc = 0x22280;
            break;
        }
        pc = 0x22349;
        break;
    case 0x22280:
        if (memory16gets(ds*16+0xFCE2) < signed16(0x0140)) {
            pc = 0x2228B;
            break;
        }
        pc = 0x22349;
        break;
    case 0x2228B:
        if (memory16gets(ds*16+0x32BE) < signed16(0x0041)) {
            pc = 0x222B5;
            break;
        }
        r16[bx] = memory16get(ds*16+0xFCFE);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 12994);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        r16[dx] += 1;
        yield* sub_2191D();
        r16[ax] = memory16get(ds*16+0x32BA);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x32BC);
        memory16set(ds*16+0xFCE6, r16[ax]);
    case 0x222B5:
        r16[ax] = memory16get(ds*16+0x32BE);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        r16[si] = 0x32c8;
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 13000);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        yield* sub_2191D();
        if (memory16gets(ds*16+0x32BC) < 0 /*CHECK*/) {
            pc = 0x22349;
            break;
        }
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[di] = memory16get(ds*16+0x32BC);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x32BA);
        sar16(ax, 1);
        sar16(ax, 1);
        r16[di] += r16[ax];
        bp = memory16get(ds*16+0x32BA);
        bp &= 0xfffc;
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds*16+0x32BA);
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r8[al] = 0xff;
        r8[al] >>= r8[cl];
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[al] = 0xff;
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[ah] = 0xff;
        r8[al] = memory[ds*16+r16[bx] + 16957];
        r16[ax] >>= r8[cl];
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[ah] = memory[ds*16+r16[bx] + 16957];
        r8[al] = memory[ds*16+r16[bx] + 16958];
        r16[ax] >>= r8[cl];
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[ah] = memory[ds*16+r16[bx] + 16958];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= r8[cl];
        yield* sub_2234E();
    case 0x22349:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2234E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (bp >= 0x0140)
            return;
        if (!(r8[al] & r8[al]))
            return;
        if (r8[al] == 0xff) {
            pc = 0x22371;
            break;
        }
        push(r16[cx]);
        push(r16[di]);
        r16[cx] = memory16get(ds*16+0x32BE);
        if (r16[cx] == 0) {
            pc = 0x2236E;
            break;
        }
    case 0x22364:
        memory[es*16+r16[di]] |= r8[al];
        r16[di] -= 0x0050;
        if (r16s[di] < 0) {
            pc = 0x2236E;
            break;
        }
        if (--r16[cx]) {
            pc = 0x22364;
            break;
        }
    case 0x2236E:
        r16[di] = pop();
        r16[cx] = pop();
        return;
    case 0x22371:
        push(r16[cx]);
        push(r16[di]);
        r16[cx] = memory16get(ds*16+0x32BE);
        if (r16[cx] == 0) {
            pc = 0x2236E;
            break;
        }
    case 0x22379:
        memory[es*16+r16[di]] = r8[al];
        r16[di] -= 0x0050;
        if (r16s[di] < 0) {
            pc = 0x2236E;
            break;
        }
        if (--r16[cx]) {
            pc = 0x22379;
            break;
        }
        r16[di] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_22386() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9152);
        r16[dx] = memory16get(ds*16+0x9154);
        flags.carry = r16[ax] < memory16get(ds*16+0x9156);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9156);
        r16[dx] -= memory16get(ds*16+0x9158) + flags.carry;
        if (r16s[ax] < 0) {
            pc = 0x22403;
            break;
        }
        if (r16[ax] != 0) {
            pc = 0x2239D;
            break;
        }
        if (!(r16[ax] & r16[ax]))
            return;
    case 0x2239D:
        if (r16[dx] & r16[dx]) {
            pc = 0x223AB;
            break;
        }
        if (r16s[ax] < signed16(0x00c8)) {
            pc = 0x223C6;
            break;
        }
        if (r16s[ax] < signed16(0x07d0)) {
            pc = 0x223B9;
            break;
        }
    case 0x223AB:
        r16[bx] = 0x921f;
        r16[di] = 0x3c0c;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x03e8);
        pc = 0x223D1;
        break;
    case 0x223B9:
        r16[bx] = 0x9220;
        r16[di] = 0x3c0e;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x0064);
        pc = 0x223D1;
        break;
    case 0x223C6:
        r16[bx] = 0x9221;
        r16[di] = 0x3c10;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x000a);
    case 0x223D1:
        memory16set(ds*16+0x9158, memory16get(ds*16+0x9158) + 0x0000 + flags.carry); assert(0);
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x223E0;
            break;
        }
        r16[di] += 0x0036;
    case 0x223E0:
        r16[si] = 0x0500;
    case 0x223E3:
        memory[ds*16+r16[bx]] += 1;
        if (memorys[ds*16+r16[bx]] < signed8(0x0a)) {
            pc = 0x223ED;
            break;
        }
        memory[ds*16+r16[bx]] = 0x00;
    case 0x223ED:
        r8[al] = memory[ds*16+r16[bx]];
        yield* sub_2244F();
        if (memory[ds*16+r16[bx]] != 0x00)
            return;
        r16[di] -= 0x0002;
        r16[bx] -= 1;
        if (r16s[bx] >= signed16(0x921c)) {
            pc = 0x223E3;
            break;
        }
        return;
    case 0x22403:
        r16[ax] = memory16get(ds*16+0x9156);
        memory16set(ds*16+0x9152, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9158);
        memory16set(ds*16+0x9154, r16[ax]);
        return;
    } while (1);
}
function* sub_22410() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x3c06;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x2241D;
            break;
        }
        r16[di] = 0x3c3c;
    case 0x2241D:
        r16[si] = 0x0500;
        r16[cx] = 0x0007;
    case 0x22423:
        r8[al] = r8[al] ^ r8[al];
        yield* sub_2244F();
        r16[di] += 0x0002;
        if (--r16[cx]) {
            pc = 0x22423;
            break;
        }
        return;
    } while (1);
}
function* sub_2242F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x918A);
        if (r16s[ax] <= signed16(0x0009)) {
            pc = 0x2243A;
            break;
        }
        r16[ax] = 0x0009;
    case 0x2243A:
        r16[si] = 0x0640;
        r16[di] = 0x3c72;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x2244A;
            break;
        }
        r16[di] = 0x3c7c;
    case 0x2244A:
        yield* sub_2244F();
        return;
    } while (1);
}
function* sub_2244F() {
    push(r16[di]);
    push(r16[si]);
    push(r16[cx]);
    r8[ah] = r8[ah] ^ r8[ah];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] += r16[ax];
    push(ds);
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[ax] = _seg005;
    ds = r16[ax];
    r16[cx] = 0x0008;
    r16[ax] = 0x004e;
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    movsw_data_data_forward();
    r16[di] += r16[ax];
    r16[ax] = pop();
    ds = r16[ax];
    es = r16[ax];
    r16[cx] = pop();
    r16[si] = pop();
    r16[di] = pop();
}
function* sub_22490() {
    yield* sub_22495();
}
function* sub_22495() {
    r16[di] = memory16get(ds*16+0x3752);
    r16[di] <<= 1;
    r16[di] = memory16get(ds*16+r16[di] + 38718);
    push(memory16get(ds*16+r16[si] + 20));
    push(r16[si]);
    memory[ds*16+r16[si] + 20] = 0x00;
    yield* sub_2253A();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 20, pop());
}
function* sub_224B0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x35e2;
        memory16set(ds*16+0xFCE2, r16[ax]);
        memory16set(ds*16+0xFCE4, r16[dx]);
        r16[bx] = 0x3756;
        r16[si] = 0x0500;
    case 0x224C0:
        if (memory16get(ds*16+r16[bx]) == 0x0000)
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x224C7:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        _FIXME_;
        if (memory16gets(ds*16+0xFCE2) < 0) {
            pc = 0x224D9;
            break;
        }
        r16[dx] += 1;
        pc = 0x224C7;
        break;
    case 0x224D9:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+0xFCE4, memory16get(ds*16+0xFCE4) + r16[ax] + flags.carry); assert(0);
        r16[bx] += 0x0004;
        r8[al] = r8[dl];
        yield* sub_2244F();
        r16[di] += 0x0002;
        pc = 0x224C0;
        break;
        return;
    } while (1);
}
function* sub_224F5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_22152();
        memory16set(ds*16+0x3752, 0x000c);
        r16[si] = 0x352b;
        yield* sub_22490();
        r16[si] = 0x358f;
        r16[di] = 0x0be8;
        r16[cx] = 0x000a;
    case 0x2250F:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        yield* sub_22529();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[si] += 0x000f;
        r16[di] += 0x0500;
        if (--r16[cx]) {
            pc = 0x2250F;
            break;
        }
        yield* sub_21870();
    {yield* sub_22168(); return; };
        return;
    } while (1);
}
function* sub_22529() {
    push(memory16get(ds*16+r16[si] + 15));
    push(r16[si]);
    memory[ds*16+r16[si] + 15] = 0x00;
    yield* sub_22548();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 15, pop());
}
function* sub_2253A() {
    bp = 0x0780;
    r16[cx] = 0x0016;
    yield* sub_22553();
}
function* sub_22545() {
    r16[di] = 0x39ac;
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_22548() {
    bp = 0x2300;
    r16[cx] = 0x000e;
    yield* sub_22553();
}
function* sub_22553() {
    lodsb_data_forward();
    if (!(r8[al] & r8[al]))
        return;
    {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
    push(r16[si]);
    yield* sub_22568();
    r16[si] = pop();
    {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
    r16[di] += 0x0004;
{yield* sub_22553(); return; };
    return;
}
function* sub_22568() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        push(r16[cx]);
        push(r16[di]);
        memory[ds*16+0x33F2] = r8[al];
        r16[di] = 0x33ca;
        r16[cx] = 0x33f2;
        r16[cx] -= 0x33ca;
        r16[cx] += 1;
        _repne_scasb();
        r16[ax] = r16[di];
        r16[ax] -= 0x33cb;
        r16[di] = pop();
        if (r16[ax] == 0x0028) {
            pc = 0x225A9;
            break;
        }
        r16[cx] = pop();
        _mul(r16[cx]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        push(r16[cx]);
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0x004c;
    case 0x2259E:
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] += r16[ax];
        if (--r16[cx]) {
            pc = 0x2259E;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
    case 0x225A9:
        r16[cx] = pop();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_225AC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x8FAF] == 0x00)
            return;
        memory[ds*16+0x8FAF] = 0x00;
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[bx] = memory16get(ds*16+0x9186);
        if (r16s[bx] <= signed16(0x0027)) {
            pc = 0x225C9;
            break;
        }
        r16[bx] = 0x0027;
    case 0x225C9:
        r16[bx] -= 0x0027;
        r16[bx] = -r16[bx];
        r16[di] = 0x3d06;
        r8[al] = 0x03;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x225DF;
            break;
        }
        r16[di] = 0x3d1f;
        r8[al] = 0x0c;
    case 0x225DF:
        r16[cx] = 0x0027;
        r8[ah] = r8[al];
        r8[ah] = (~r8[ah]);
    case 0x225E6:
        if (r16[cx] != r16[bx]) {
            pc = 0x225EC;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
    case 0x225EC:
        memory[es*16+r16[di]] &= r8[ah];
        memory[es*16+r16[di] + 80] &= r8[ah];
        memory[es*16+r16[di] + 160] &= r8[ah];
        memory[es*16+r16[di]] |= r8[al];
        memory[es*16+r16[di] + 80] |= r8[al];
        memory[es*16+r16[di] + 160] |= r8[al];
        ror8(al, 1);
        ror8(al, 1);
        ror8(ah, 1);
        ror8(ah, 1);
        flags.carry = !!(r8[ah] & 0x80);
        if (flags.carry) {
            pc = 0x2260F;
            break;
        }
        r16[di] += 1;
    case 0x2260F:
        if (--r16[cx]) {
            pc = 0x225E6;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22616() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x33BC) != 0x0000) {
            pc = 0x2262F;
            break;
        }
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        ds = r16[ax];
        r16[si] = 0x3c00;
        r16[di] = 0x923e;
        r16[cx] = 0x0140;
        rep_movsw_data_data_forward();
        ds = pop();
    case 0x2262F:
        memory[ds*16+0x33BC] += 1;
        return;
    } while (1);
}
function* sub_22634() {
    memory[ds*16+0x33BC] -= 1;
    if (memory[ds*16+0x33BC] != 0)
        return;
    push(es);
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[si] = 0x923e;
    r16[di] = 0x3c00;
    r16[cx] = 0x0140;
    rep_movsw_data_data_forward();
    es = pop();
    return;
}
function* sub_2264D() {
    yield* sub_220DC();
}
function* sub_22651() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_22152();
        r16[si] = 0x3740;
    case 0x22658:
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        if (!(r16[ax] & r16[ax])) {
            pc = 0x2267F;
            break;
        }
        bp = r16[ax];
        r16[di] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[dx] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[cx] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        push(r16[si]);
        r16[si] = bp;
        yield* sub_2273E();
        r16[si] = pop();
        pc = 0x22658;
        break;
    case 0x2267F:
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x22681:
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x22683:
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xec90;
        yield* sub_2191D();
        r16[dx] = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xefc0;
        yield* sub_2191D();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[cx] += 0x0029;
        if (r16s[cx] < signed16(0x00cd)) {
            pc = 0x22683;
            break;
        }
        r16[dx] += 0x0029;
        if (r16s[dx] < signed16(0x00a4)) {
            pc = 0x22681;
            break;
        }
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x226BF;
            break;
        }
        r16[si] = 0xfc4a;
        r16[cx] = 0x00c1;
        r16[dx] = 0x00bc;
        yield* sub_2191D();
    case 0x226BF:
        r16[si] = 0xfe00;
        r16[cx] = 0x0059;
        r16[dx] = 0x00aa;
        yield* sub_2191D();
        r16[si] = 0xfe74;
        r16[cx] = 0x00a5;
        r16[dx] = 0x00bc;
        yield* sub_2191D();
        yield* sub_2264D();
        return;
    } while (1);
}
function* sub_226DE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_2191D();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        r16[si] = 0xfd3a;
        if (r16[ax] == 0xe3ec) {
            pc = 0x22719;
            break;
        }
        r16[si] = 0xfd7c;
        if (r16[ax] == 0xe5f0) {
            pc = 0x22719;
            break;
        }
        r16[si] = 0xfdbe;
        if (r16[ax] == 0xe7f4) {
            pc = 0x22719;
            break;
        }
        r16[si] = 0xfc74;
        if (r16[ax] == 0xdde0) {
            pc = 0x22719;
            break;
        }
        r16[si] = 0xfcb6;
        if (r16[ax] == 0xdfe4) {
            pc = 0x22719;
            break;
        }
        r16[si] = 0xfcf8;
        if (r16[ax] == 0xe1e8) {
            pc = 0x22719;
            break;
        }
        return;
    case 0x22719:
        yield* sub_2191D();
        return;
    } while (1);
}
function* sub_2271E() {
    yield* sub_22152();
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[di] = 0x1f68;
    memory[es*16+r16[di]] |= 0x3c;
    memory[es*16+r16[di] + 80] |= 0xff;
    memory[es*16+r16[di] + 160] |= 0x3c;
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_2273E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
    case 0x22749:
        push(r16[di]);
        push(r16[cx]);
        r16[cx] = r16[dx];
        rep_movsw_data_data_forward();
        r16[cx] = pop();
        r16[di] = pop();
        r16[di] += 0x0050;
        if (--r16[cx]) {
            pc = 0x22749;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2275C() {
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    r16[di] = 0x23d4;
    r16[cx] = 0x0045;
    yield* sub_2276F();
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_2276F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x2278A;
        break;
    case 0x22771:
        memory[es*16+r16[di] + 1] &= 0xfc;
        r16[di] += 0x0002;
        r16[ax] = r16[ax] ^ r16[ax];
        push(r16[cx]);
        r16[cx] = 0x000b;
        rep_stosw_data_forward();
        r16[cx] = pop();
        stosb_data_forward();
        memory[es*16+r16[di]] &= 0x3f;
        r16[di] += 0x0037;
    case 0x2278A:
        if (--r16[cx]) {
            pc = 0x22771;
            break;
        }
        return;
    } while (1);
}
function* sub_2278D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x8430;
        r16[di] = 0x0304;
        r16[cx] = 0x0034;
        yield* sub_228E5();
        r16[si] = 0x8f90;
        r16[di] = 0x1de4;
        r16[cx] = 0x000a;
        yield* sub_228E5();
        r16[si] = 0x91c0;
        if (memory[ds*16+0x8F40] == 0x00) {
            pc = 0x227C3;
            break;
        }
        yield* sub_10ED9();
        r16[cx] = 0x0004;
        pc = 0x227BD;
        break;
    case 0x227B9:
        r16[si] += 0x03b8;
    case 0x227BD:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (flags.carry) {
            pc = 0x227C3;
            break;
        }
        if (--r16[cx]) {
            pc = 0x227B9;
            break;
        }
    case 0x227C3:
        r16[di] = 0x1344;
        r16[cx] = 0x0022;
        yield* sub_228E5();
        yield* sub_10EE5();
        yield* sub_10EE9();
        if (memory16get(ds*16+0x8F3C) != 0x0000) {
            pc = 0x227E0;
            break;
        }
        return;
    case 0x227E0:
        if (memory16gets(ds*16+0x8F3C) <= signed16(0x0008)) {
            pc = 0x2281E;
            break;
        }
        r16[di] = 0x0304;
        r16[si] = 0x5c18;
        r16[ax] = 0x0030;
        r16[ax] = r16[ax] - memory16get(ds*16+0x8F3C);
        r16[dx] = 0x001c;
        _mul(r16[dx]);
        r16[si] += r16[ax];
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_228E5();
        r16[di] = 0x2384;
        r16[ax] = 0x0050;
        _mul(memory16get(ds*16+0x8F3C));
        r16[di] -= r16[ax];
        r16[si] = 0x64d8;
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_228E5();
    case 0x2281E:
        r16[cx] = 0x00d7;
        r16[dx] = memory16get(ds*16+0x8F3C);
        r16[dx] += 1;
        push(r16[dx]);
        r16[si] = 0xabe4;
        yield* sub_2191D();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xace4;
        yield* sub_2191D();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xad94;
        yield* sub_2191D();
        r16[cx] = 0x00d7;
        r16[dx] = 0x0070;
        r16[dx] = r16[dx] - memory16get(ds*16+0x8F3C);
        push(r16[dx]);
        r16[si] = 0xae94;
        yield* sub_2191D();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xaf94;
        yield* sub_2191D();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xb044;
        yield* sub_2191D();
        if (memory16gets(ds*16+0x8F3C) >= signed16(0x0008))
            return;
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[di] = 0x0034;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4758;
        r16[cx] = 0x0009;
    case 0x22889:
        push(r16[cx]);
        r16[cx] = 0x000e;
        rep_movsw_data_data_forward();
        r16[cx] = pop();
        r16[di] += 0x0034;
        r16[si] += 0x0010;
        if (--r16[cx]) {
            pc = 0x22889;
            break;
        }
        ds = pop();
        r16[di] = 0x2104;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4998;
        r16[cx] = 0x0009;
    case 0x228A8:
        push(r16[cx]);
        r16[cx] = 0x000e;
        rep_movsw_data_data_forward();
        r16[cx] = pop();
        r16[di] += 0x0034;
        r16[si] += 0x0010;
        if (--r16[cx]) {
            pc = 0x228A8;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_228BD() {
    if (memory16get(ds*16+0x8F3E) == 0x0000)
        return;
    r16[di] = 0x23d4;
    r16[cx] = 0x0045;
    r16[cx] = r16[cx] - memory16get(ds*16+0x8F3E);
    r16[ax] = memory16get(ds*16+0x4255);
    es = r16[ax];
    yield* sub_2276F();
    r16[ax] = ds;
    es = r16[ax];
    r16[si] = 0x6d98;
    r16[cx] = memory16get(ds*16+0x8F3E);
    yield* sub_228E5();
    return;
}
function* sub_228E5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
    case 0x228F0:
        r16[si] += 1;
        lodsb_data_forward();
        r8[al] &= 0x03;
        memory[es*16+r16[di] + 1] |= r8[al];
        r16[di] += 0x0002;
        movsw_data_data_forward();
        push(r16[cx]);
        r16[cx] = 0x000b;
        rep_movsw_data_data_forward();
        r16[si] += 0x0002;
        r16[cx] = pop();
        r16[di] += 0x0036;
        if (--r16[cx]) {
            pc = 0x228F0;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22911() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[si] = memory16get(ds*16+r16[di] + 4);
        r16[si] <<= 1;
        r16[si] = memory16get(ds*16+r16[si] - 26818);
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[cx] = r16[ax];
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[si] += r16[ax];
        r8[bl] = 0x1c;
    case 0x22931:
        r16[ax] = 0xff00;
        r16[ax] >>= r8[cl];
        r16[ax] = (~r16[ax]);
        memory[es*16+r16[si]] &= r8[ah];
        memory[es*16+r16[si] + 8] &= r8[al];
        yield* sub_10ED9();
        r8[al] = r8[ah];
        r16[ax] >>= r8[cl];
        memory[es*16+r16[si]] |= r8[ah];
        memory[es*16+r16[si] + 1] = r8[al];
        memory[es*16+r16[si] + 2] = r8[al];
        memory[es*16+r16[si] + 3] = r8[al];
        memory[es*16+r16[si] + 4] = r8[al];
        memory[es*16+r16[si] + 5] = r8[al];
        memory[es*16+r16[si] + 6] = r8[al];
        memory[es*16+r16[si] + 7] = r8[al];
        r8[al] = r8[al] ^ r8[ah];
        memory[es*16+r16[si] + 8] |= r8[al];
        r16[si] += 0x0050;
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x22931;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22979() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] != 0x0d) {
            pc = 0x22982;
            break;
        }
    {yield* loc_10EED(); return; };
    case 0x22982:
        r16[di] = memory16get(ds*16+0x8F48);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+0x8F46);
        r8[al] -= 0x20;
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] = 0x7cb0;
        r16[si] += r16[ax];
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[cx] = 0x0008;
    case 0x229AF:
        movsb_data_data_forward();
        r16[si] += 1;
        r16[di] += 0x004f;
        if (--r16[cx]) {
            pc = 0x229AF;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        memory16set(ds*16+0x8F46, memory16get(ds*16+0x8F46) + 1);
        return;
    } while (1);
}
function* sub_229C0() {
    r16[si] = 0xaf80;
    r16[di] = 0x0f0c;
    r16[dx] = 0x001a;
    r16[cx] = 0x0036;
    yield* sub_2273E();
}
function* sub_22A02() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+r16[si] + 28) < 0 /*CHECK*/) {
            pc = 0x22A0E;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x22A1E;
            break;
        }
    case 0x22A0E:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32CA);
        yield* sub_2191D();
        r16[si] = pop();
    case 0x22A1E:
        if (memory16gets(ds*16+r16[si] + 28) >= 0 /*CHECK*/) {
            pc = 0x22A2A;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x22A3E;
            break;
        }
    case 0x22A2A:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] = r16[dx] + memory16get(ds*16+r16[si] + 26);
        r16[dx] -= 1;
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32C4);
        yield* sub_2191D();
        r16[si] = pop();
    case 0x22A3E:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        r16[ax] -= 1;
        if (_FIXME_)
            return;
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] -= 1;
        r16[dx] = memory16get(ds*16+0x32BC);
        r16[dx] -= 0x00bf;
        if (_FIXME_) {
            pc = 0x22A68;
            break;
        }
        r16[ax] -= r16[dx];
        if (_FIXME_)
            return;
        memory16set(ds*16+0x32BC, 0x00bf);
    case 0x22A68:
        memory16set(ds*16+0x32BE, r16[ax]);
        r16[ax] = memory16get(ds*16+0x4255);
        es = r16[ax];
        r16[di] = memory16get(ds*16+0x32BC);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x32BA);
        sar16(ax, 1);
        sar16(ax, 1);
        r16[di] += r16[ax];
        bp = memory16get(ds*16+0x32BA);
        bp &= 0xfffc;
        r16[cx] = memory16get(ds*16+0x32BA);
        r16[cx] &= 0x0003;
        r16[cx] <<= 1;
        r8[al] = 0xff;
        r8[al] >>= r8[cl];
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[al] = 0xff;
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r8[al] = 0xff;
        yield* sub_2234E();
        r16[di] += 1;
        bp += 0x0004;
        r16[ax] = 0xff00;
        r16[ax] >>= r8[cl];
        yield* sub_2234E();
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22CA8() {
    memory16set(ds*16+0x439D, r16[si]);
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_22CAC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = r8[bl] ^ r8[bl];
    case 0x22CAE:
        lodsb_data_forward();
        r8[bh] = r8[al];
        r16[ax] = 0x1000;
        interrupt(16);
        r8[bl] += 1;
        if (r8s[bl] < signed8(0x10)) {
            pc = 0x22CAE;
            break;
        }
        return;
    } while (1);
}
function* sub_22CBE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0010;
    case 0x22CC3:
        r16[ax] = 0x1000;
        push(r16[bx]);
        push(r16[cx]);
        interrupt(16);
        r16[cx] = pop();
        r16[bx] = pop();
        r8[bh] = r8[bh] ^ 0x0f;
        if (--r16[cx]) {
            pc = 0x22CC3;
            break;
        }
        r16[ax] = 0x1000;
        r16[bx] = r16[bx] ^ r16[bx];
        interrupt(16);
        return;
    } while (1);
}
function* sub_22CD9() {
    r16[dx] = _seg007;
    r16[si] = r16[si] ^ r16[si];
    r16[cx] = 0x6be6;
    yield* sub_22F4F();
    r16[dx] = _seg007;
    r16[si] = 0x6be6;
    r16[cx] = 0x3fd6;
    yield* sub_22F4F();
    r16[dx] = _seg007;
    r16[si] = 0xabbc;
    r16[cx] = 0x5324;
    yield* sub_22F4F();
    r16[si] = 0x0000;
    r16[cx] = 0x0140;
    yield* sub_22E5D();
    r16[si] = 0x0500;
    r16[cx] = 0x000a;
    yield* sub_22DAE();
    r16[si] = 0x0640;
    r16[cx] = 0x000a;
    yield* sub_22DAE();
    r16[si] = 0x0780;
    r16[cx] = 0x0028;
    r16[dx] = 0x0016;
    yield* sub_22DF0();
    r16[si] = 0x2300;
    r16[cx] = 0x002a;
    r16[dx] = 0x000e;
    yield* sub_22DF0();
    r16[si] = 0xaf80;
    r16[cx] = 0x02be;
    yield* sub_22EA0();
    r16[si] = 0x7cb0;
    r16[cx] = 0x003c;
    yield* sub_22DAE();
    r16[si] = 0x5c18;
    r16[cx] = 0x0118;
    yield* sub_22EA0();
    r16[si] = 0x64d8;
    r16[cx] = 0x0118;
    yield* sub_22EA0();
    r16[si] = 0x6d98;
    r16[cx] = 0x01e3;
    yield* sub_22EA0();
    r16[si] = 0x8430;
    r16[cx] = 0x016c;
    yield* sub_22EA0();
    r16[si] = 0x8f90;
    r16[cx] = 0x0046;
    yield* sub_22EA0();
    r16[si] = 0x91c0;
    r16[cx] = 0x03b8;
    yield* sub_22EA0();
    r16[si] = 0x3560;
    r16[cx] = 0x017e;
    yield* sub_22EA0();
    r16[si] = 0x4150;
    r16[cx] = 0x00bf;
    yield* sub_22EA0();
    r16[si] = 0x4748;
    r16[cx] = 0x0048;
    yield* sub_22EA0();
    r16[si] = 0x4988;
    r16[cx] = 0x0048;
    yield* sub_22EA0();
    r16[si] = 0x4bc8;
    r16[cx] = 0x005a;
    yield* sub_22EA0();
    r16[si] = 0x4e98;
    r16[cx] = 0x01b0;
    yield* sub_22EA0();
}
function* sub_22DAE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        push(r16[si]);
    case 0x22DBC:
        push(r16[cx]);
        yield* sub_22DDA();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x22DBC;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22DDA() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0008;
    case 0x22DDD:
        r8[ah] = memory[ds*16+r16[si] + 8];
        r8[bl] = memory[ds*16+r16[si] + 16];
        r8[bh] = memory[ds*16+r16[si] + 24];
        lodsb_data_forward();
        yield* sub_22FDF();
        if (--r16[cx]) {
            pc = 0x22DDD;
            break;
        }
        r16[si] += 0x0018;
        return;
    } while (1);
}
function* sub_22DF0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        push(r16[si]);
    case 0x22DFE:
        push(r16[cx]);
        yield* sub_22E1C();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x22DFE;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22E1C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[cx] = r16[dx];
        r16[dx] <<= 1;
    case 0x22E21:
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        lodsb_data_forward();
        yield* sub_22FDF();
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        lodsb_data_forward();
        yield* sub_22FDF();
        if (--r16[cx]) {
            pc = 0x22E21;
            break;
        }
        r16[dx] >>= 1;
        r16[si] = pop();
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        return;
    } while (1);
}
function* sub_22E5D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[dx] = r16[cx];
        push(r16[si]);
    case 0x22E6D:
        yield* sub_22E89();
        if (--r16[cx]) {
            pc = 0x22E6D;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22E89() {
    r16[si] += r16[dx];
    r8[ah] = memory[ds*16+r16[si]];
    r16[si] += r16[dx];
    r8[bl] = memory[ds*16+r16[si]];
    r16[si] += r16[dx];
    r8[bh] = memory[ds*16+r16[si]];
    r16[si] -= r16[dx];
    r16[si] -= r16[dx];
    r16[si] -= r16[dx];
    lodsb_data_forward();
    yield* sub_22FDF();
}
function* sub_22EA0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        push(r16[si]);
    case 0x22EAE:
        yield* sub_22ECA();
        if (--r16[cx]) {
            pc = 0x22EAE;
            break;
        }
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22ECA() {
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_22FDF();
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_22FDF();
    r16[si] += 0x0006;
}
function* sub_22EE8() {
    r16[dx] = _seg008;
    r16[si] = r16[si] ^ r16[si];
    r16[cx] = 0xf468;
    yield* sub_22F4F();
    yield* sub_22EF7();
}
function* sub_22EF7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[cx] = 0x01c9;
        r16[si] = r16[si] ^ r16[si];
    case 0x22F07:
        push(r16[cx]);
        push(r16[si]);
        r16[di] = r16[di] ^ r16[di];
        yield* sub_22F28();
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x22F07;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22F28() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0010;
    case 0x22F2B:
        yield* sub_22F31();
        if (--r16[cx]) {
            pc = 0x22F2B;
            break;
        }
        return;
    } while (1);
}
function* sub_22F31() {
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_22FDF();
    r8[ah] = memory[ds*16+r16[si] + 2];
    r8[bl] = memory[ds*16+r16[si] + 4];
    r8[bh] = memory[ds*16+r16[si] + 6];
    lodsb_data_forward();
    yield* sub_22FDF();
    r16[si] += 0x0006;
}
function* sub_22F4F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        ds = r16[dx];
        r16[ax] = 0xb800;
        es = r16[ax];
        bp = r16[si];
        bp += r16[cx];
        r16[si] += 0x0020;
    case 0x22F5E:
        r16[si] += 0x000c;
        lodsw_data_forward();
        if (!(r16[ax] & r16[ax])) {
            pc = 0x22FA8;
            break;
        }
        r16[bx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        r16[cx] += 1;
        r16[dx] = r16[cx];
        if (r16s[bx] <= signed16(0x0008)) {
            pc = 0x22F83;
            break;
        }
        r16[dx] += r16[cx];
        if (r16s[bx] <= signed16(0x0010)) {
            pc = 0x22F83;
            break;
        }
        r16[dx] += r16[cx];
        if (r16s[bx] <= signed16(0x0018)) {
            pc = 0x22F83;
            break;
        }
        r16[dx] += r16[cx];
    case 0x22F83:
        push(bp);
        bp = r16[si];
        push(r16[si]);
        r16[si] += r16[dx];
        r16[di] = r16[di] ^ r16[di];
        yield* sub_22FAE();
        r16[cx] = r16[di];
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        rep_movsb_data_data_forward();
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[si] = r16[di];
        r16[si] += 1;
        r16[si] &= 0xfffe;
        bp = pop();
        if (r16[si] < bp) {
            pc = 0x22F5E;
            break;
        }
    case 0x22FA8:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_22FAE() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
    case 0x22FAF:
        yield* sub_22FB6();
        if (--r16[cx]) {
            pc = 0x22FAF;
            break;
        }
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_22FB6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
    case 0x22FB7:
        push(r16[bx]);
        r8[al] = memory[ds*16+bp + 0];
        bp += 1;
        memory[es*16+r16[di]] = r8[al];
        r16[di] += 1;
        r16[si] += r16[dx];
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bl] = memory[ds*16+r16[si]];
        r16[si] += r16[dx];
        r8[bh] = memory[ds*16+r16[si]];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        lodsb_data_forward();
        yield* sub_22FDF();
        r16[bx] = pop();
        r16[bx] -= 0x0008;
        if (_FIXME_) {
            pc = 0x22FB7;
            break;
        }
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_22FDF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        push(r16[cx]);
        r16[cx] = 0x0004;
    case 0x22FE4:
        flags.carry = !!(r8[bh] & 0x80);
        r8[bh] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[bh] & 0x80);
        r8[bh] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        rcl8(dl, 1);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        rcl8(dl, 1);
        memory[es*16+r16[di]] = r8[dl];
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x22FE4;
            break;
        }
        r16[cx] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_2300D() {
    r16[si] = 0x439f;
    yield* sub_22CA8();
}
function* sub_23014() {
    r16[si] = 0x43af;
    yield* sub_22CA8();
}
function* sub_2301B() {
    r16[si] = 0x439f;
    yield* sub_22CA8();
}
function* sub_23023() {
    var cs = _seg001;
    r16[si] = 0x43bf;
    yield* sub_22CAC();
    memory[cs*16+0x3D92] = 0x01;
}
function* loc_23030() {
    var cs = _seg001;
    if (memory[cs*16+0x3D92] == 0x00)
        return;
    _STOP_("word_23038 dw 0C62Eh");
    push(es);
    xchg16(ax, dx);
    _STOP_("db 36h");
    popf();
    r16[bx] += 1;
    yield* sub_22CA8();
    return;
}
function* sub_23046() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9198);
        yield* sub_10ED5();
        push(es);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
        r8[ah] = 0x07;
    case 0x2305C:
        r16[di] = memory16get(ds*16+r16[si]);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] = r16[di] + memory16get(ds*16+r16[si] + 2);
        if (memory[es*16+r16[di]] != 0x00) {
            pc = 0x23070;
            break;
        }
        memory[es*16+r16[di]] = r8[ah];
    case 0x23070:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x2305C;
            break;
        }
        es = pop();
        return;
    } while (1);
}
function* sub_23077() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x9a40;
        r16[cx] = 0x0030;
    case 0x23082:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[ax] &= 0x7fff;
        r16[ax] -= 0x0200;
        if (r16s[ax] > signed16(0x0200)) {
            pc = 0x230AC;
            break;
        }
    case 0x23090:
        yield* sub_10ED9();
        memory16set(ds*16+r16[si], r16[ax]);
        yield* sub_10ED9();
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        yield* sub_10ED9();
        r16[ax] &= 0x1fff;
        if (r16s[ax] <= signed16(0x0200)) {
            pc = 0x23090;
            break;
        }
    case 0x230AC:
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x00a0;
        if (r16[ax] >= 0x0140) {
            pc = 0x23090;
            break;
        }
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        _cwd();
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        rcl16(dx, 1);
        _idiv(memory16get(ds*16+r16[si] + 4));
        r16[ax] += 0x0064;
        if (r16[ax] >= 0x00c8) {
            pc = 0x23090;
            break;
        }
        r16[di] = r16[ax];
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        push(r16[cx]);
        r16[cx] = r16[bx];
        r16[cx] &= 0x0001;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[bx] >>= 1;
        r16[di] += r16[bx];
        r8[ah] = 0xf0;
        r8[ah] >>= r8[cl];
        r16[cx] = pop();
        if (memory[es*16+r16[di]] & r8[ah]) {
            pc = 0x23116;
            break;
        }
        r8[ah] &= 0x77;
        memory[es*16+r16[di]] |= r8[ah];
        pc = 0x2311B;
        break;
    case 0x23116:
        memory16set(ds*16+r16[si] + 4, memory16get(ds*16+r16[si] + 4) | 0x8000);
    case 0x2311B:
        r16[si] += 0x0006;
        if (--r16[cx]) {
            pc = 0x23122;
            break;
        }
        pc = 0x23125;
        break;
    case 0x23122:
        pc = 0x23082;
        break;
    case 0x23125:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2312A() {
    var pc = 0;
    do switch (pc) {
    case 0:
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2313B;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23145;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23149;
        break;
    case 0x2313B:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23149;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23149;
        break;
    case 0x23145:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23149:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23158;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23162;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23166;
        break;
    case 0x23158:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23166;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23166;
        break;
    case 0x23162:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23166:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23175;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2317F;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23183;
        break;
    case 0x23175:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23183;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23183;
        break;
    case 0x2317F:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23183:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23192;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2319C;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x231A0;
        break;
    case 0x23192:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231A0;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x231A0;
        break;
    case 0x2319C:
        memory[es*16+r16[di]] |= 0x70;
    case 0x231A0:
        r16[di] += 1;
        r16[si] += 0x0004;
        return;
    } while (1);
}
function* sub_231A5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231B6;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231C0;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x231C4;
        break;
    case 0x231B6:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231C4;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x231C4;
        break;
    case 0x231C0:
        memory[es*16+r16[di]] |= 0x70;
    case 0x231C4:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231D3;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231DD;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x231E1;
        break;
    case 0x231D3:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231E1;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x231E1;
        break;
    case 0x231DD:
        memory[es*16+r16[di]] |= 0x70;
    case 0x231E1:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231F0;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231FA;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x231FE;
        break;
    case 0x231F0:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x231FE;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x231FE;
        break;
    case 0x231FA:
        memory[es*16+r16[di]] |= 0x70;
    case 0x231FE:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2320D;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23217;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x2321B;
        break;
    case 0x2320D:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2321B;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x2321B;
        break;
    case 0x23217:
        memory[es*16+r16[di]] |= 0x70;
    case 0x2321B:
        r16[di] += 1;
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2322D;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23237;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x2323B;
        break;
    case 0x2322D:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2323B;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x2323B;
        break;
    case 0x23237:
        memory[es*16+r16[di]] |= 0x70;
    case 0x2323B:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2324A;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23254;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23258;
        break;
    case 0x2324A:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23258;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23258;
        break;
    case 0x23254:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23258:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23267;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23271;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23275;
        break;
    case 0x23267:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23275;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23275;
        break;
    case 0x23271:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23275:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23284;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2328E;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x23292;
        break;
    case 0x23284:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23292;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x23292;
        break;
    case 0x2328E:
        memory[es*16+r16[di]] |= 0x70;
    case 0x23292:
        r16[di] += 1;
        return;
    } while (1);
}
function* sub_23294() {
    var pc = 0;
    do switch (pc) {
    case 0:
        lodsb_data_forward();
        r8[ah] = r8[al];
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232A5;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232AF;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x232B3;
        break;
    case 0x232A5:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232B3;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x232B3;
        break;
    case 0x232AF:
        memory[es*16+r16[di]] |= 0x70;
    case 0x232B3:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232C2;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232CC;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x232D0;
        break;
    case 0x232C2:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232D0;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x232D0;
        break;
    case 0x232CC:
        memory[es*16+r16[di]] |= 0x70;
    case 0x232D0:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232DF;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232E9;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x232ED;
        break;
    case 0x232DF:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232ED;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x232ED;
        break;
    case 0x232E9:
        memory[es*16+r16[di]] |= 0x70;
    case 0x232ED:
        r16[di] += 1;
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x232FC;
            break;
        }
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x23306;
            break;
        }
        memory[es*16+r16[di]] = 0x77;
        pc = 0x2330A;
        break;
    case 0x232FC:
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        if (!flags.carry) {
            pc = 0x2330A;
            break;
        }
        memory[es*16+r16[di]] |= 0x07;
        pc = 0x2330A;
        break;
    case 0x23306:
        memory[es*16+r16[di]] |= 0x70;
    case 0x2330A:
        r16[di] += 1;
        r16[si] += 1;
        return;
    } while (1);
}
function* sub_2330D() {
    r16[cx] = memory16get(ds*16+r16[si] + 18);
    r16[dx] = memory16get(ds*16+r16[si] + 22);
    r16[si] = memory16get(ds*16+r16[si] + 12);
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_23316() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x23323;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x23323:
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        r16[cx] &= 0xfffe;
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x2333E;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x2333E:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x23348;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23348:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x23351;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23351:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x2335A;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x2335A:
        memory16set(ds*16+0x0, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x2336E;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
    case 0x2336E:
        if (r16s[dx] >= 0) {
            pc = 0x233A2;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x2339D;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x2338C;
            break;
        }
        r16[ax] <<= 1;
        pc = 0x2339D;
        break;
    case 0x2338C:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x23399;
            break;
        }
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        pc = 0x2339D;
        break;
    case 0x23399:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
    case 0x2339D:
        memory16set(ds*16+0x0, r16[ax]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x233A2:
        r16[di] = r16[dx];
        r16[di] <<= 1;
        push(ds);
        r16[ax] = dseg;
        ds = r16[ax];
        r16[ax] = memory16get(ds*16+r16[di] + -26816);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + 38718);
        memory16set(_ss*16+32, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + -26814);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + -26816);
        memory16set(_ss*16+34, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + -26812);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + -26814);
        memory16set(_ss*16+36, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + -26810);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + -26812);
        memory16set(_ss*16+38, r16[ax]);
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        ds = pop();
        if (r16s[cx] >= 0) {
            pc = 0x233E8;
            break;
        }
        pc = 0x23AFA;
        break;
    case 0x233E8:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] <= signed16(0x0140)) {
            pc = 0x233F4;
            break;
        }
        pc = 0x23AFA;
        break;
    case 0x233F4:
        r16[cx] >>= 1;
        r16[di] += r16[cx];
        r16[ax] = 0xb800;
        es = r16[ax];
        r8[cl] = r8[bl];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[cx] += 1;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) > signed16(0x0008)) {
            pc = 0x2340E;
            break;
        }
        pc = 0x23A21;
        break;
    case 0x2340E:
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x23416;
            break;
        }
        pc = 0x238B4;
        break;
    case 0x23416:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x2341E;
            break;
        }
        pc = 0x236B3;
        break;
    case 0x2341E:
        memory16set(_ss*16+32, memory16get(_ss*16+32) - 0x0010);
        memory16set(_ss*16+34, memory16get(_ss*16+34) - 0x0010);
        memory16set(_ss*16+36, memory16get(_ss*16+36) - 0x0010);
        memory16set(_ss*16+38, memory16get(_ss*16+38) - 0x0010);
    case 0x23436:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2343F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2343F:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23448;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23448:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23451;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23451:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2345A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2345A:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23464;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23464:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2346D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2346D:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23476;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23476:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2347F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2347F:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23489;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23489:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23492;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23492:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2349B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2349B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234A4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234A4:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234AE;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234AE:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234B7;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234B7:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234C0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234C0:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234C9;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234C9:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+32);
        if (--r16[cx]) {
            pc = 0x234D4;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x234D4:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234DD;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234DD:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234E6;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234E6:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234EF;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234EF:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x234F8;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x234F8:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23502;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23502:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2350B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2350B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23514;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23514:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2351D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2351D:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23527;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23527:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23530;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23530:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23539;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23539:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23542;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23542:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2354C;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2354C:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23555;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23555:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2355E;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2355E:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23567;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23567:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+34);
        if (--r16[cx]) {
            pc = 0x23572;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23572:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2357B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2357B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23584;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23584:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2358D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2358D:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23596;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23596:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235A0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235A0:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235A9;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235A9:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235B2;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235B2:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235BB;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235BB:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235C5;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235C5:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235CE;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235CE:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235D7;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235D7:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235E0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235E0:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235EA;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235EA:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235F3;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235F3:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x235FC;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x235FC:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23605;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23605:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+36);
        if (--r16[cx]) {
            pc = 0x23610;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23610:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23619;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23619:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23622;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23622:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2362B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2362B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23634;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23634:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2363E;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2363E:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23647;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23647:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23650;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23650:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23659;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23659:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23663;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23663:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2366C;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2366C:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23675;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23675:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2367E;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2367E:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23688;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23688:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23691;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23691:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2369A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2369A:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236A3;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236A3:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+38);
        if (--r16[cx]) {
            pc = 0x236AD;
            break;
        }
        pc = 0x236B0;
        break;
    case 0x236AD:
        pc = 0x23436;
        break;
    case 0x236B0:
        pc = 0x23C6E;
        break;
    case 0x236B3:
        memory16set(_ss*16+32, memory16get(_ss*16+32) - 0x000c);
        memory16set(_ss*16+34, memory16get(_ss*16+34) - 0x000c);
        memory16set(_ss*16+36, memory16get(_ss*16+36) - 0x000c);
        memory16set(_ss*16+38, memory16get(_ss*16+38) - 0x000c);
    case 0x236CB:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236D4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236D4:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236DD;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236DD:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236E6;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236E6:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236EF;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236EF:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x236F9;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x236F9:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23702;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23702:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2370B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2370B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23714;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23714:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2371E;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2371E:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23727;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23727:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23730;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23730:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23739;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23739:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+32);
        if (--r16[cx]) {
            pc = 0x23744;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23744:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2374D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2374D:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23756;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23756:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2375F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2375F:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23768;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23768:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23772;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23772:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2377B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2377B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23784;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23784:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2378D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2378D:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23797;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23797:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237A0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237A0:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237A9;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237A9:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237B2;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237B2:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+34);
        if (--r16[cx]) {
            pc = 0x237BD;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x237BD:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237C6;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237C6:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237CF;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237CF:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237D8;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237D8:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237E1;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237E1:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237EB;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237EB:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237F4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237F4:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x237FD;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x237FD:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23806;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23806:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23810;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23810:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23819;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23819:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23822;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23822:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2382B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2382B:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+36);
        if (--r16[cx]) {
            pc = 0x23836;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23836:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2383F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2383F:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23848;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23848:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23851;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23851:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2385A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2385A:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23864;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23864:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2386D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2386D:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23876;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23876:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2387F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2387F:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23889;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23889:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23892;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23892:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2389B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2389B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238A4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238A4:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+38);
        if (--r16[cx]) {
            pc = 0x238AE;
            break;
        }
        pc = 0x238B1;
        break;
    case 0x238AE:
        pc = 0x236CB;
        break;
    case 0x238B1:
        pc = 0x23C6E;
        break;
    case 0x238B4:
        memory16set(_ss*16+32, memory16get(_ss*16+32) - 0x0008);
        memory16set(_ss*16+34, memory16get(_ss*16+34) - 0x0008);
        memory16set(_ss*16+36, memory16get(_ss*16+36) - 0x0008);
        memory16set(_ss*16+38, memory16get(_ss*16+38) - 0x0008);
    case 0x238CC:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238D5;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238D5:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238DE;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238DE:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238E7;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238E7:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238F0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238F0:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x238FA;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x238FA:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23903;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23903:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2390C;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2390C:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23915;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23915:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+32);
        if (--r16[cx]) {
            pc = 0x23920;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23920:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23929;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23929:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23932;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23932:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2393B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2393B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23944;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23944:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2394E;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2394E:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23957;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23957:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23960;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23960:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23969;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23969:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+34);
        if (--r16[cx]) {
            pc = 0x23974;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23974:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2397D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2397D:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23986;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23986:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x2398F;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x2398F:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23998;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23998:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239A2;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239A2:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239AB;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239AB:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239B4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239B4:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239BD;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239BD:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+36);
        if (--r16[cx]) {
            pc = 0x239C8;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x239C8:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239D1;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239D1:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239DA;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239DA:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239E3;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239E3:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239EC;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239EC:
        r16[di] += 1;
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239F6;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239F6:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x239FF;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x239FF:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A08;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A08:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A11;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A11:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+38);
        if (--r16[cx]) {
            pc = 0x23A1B;
            break;
        }
        pc = 0x23A1E;
        break;
    case 0x23A1B:
        pc = 0x238CC;
        break;
    case 0x23A1E:
        pc = 0x23C6E;
        break;
    case 0x23A21:
        memory16set(_ss*16+32, memory16get(_ss*16+32) - 0x0004);
        memory16set(_ss*16+34, memory16get(_ss*16+34) - 0x0004);
        memory16set(_ss*16+36, memory16get(_ss*16+36) - 0x0004);
        memory16set(_ss*16+38, memory16get(_ss*16+38) - 0x0004);
    case 0x23A39:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A42;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A42:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A4B;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A4B:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A54;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A54:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A5D;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A5D:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+32);
        if (--r16[cx]) {
            pc = 0x23A68;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23A68:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A71;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A71:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A7A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A7A:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A83;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A83:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23A8C;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23A8C:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+34);
        if (--r16[cx]) {
            pc = 0x23A97;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23A97:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AA0;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AA0:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AA9;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AA9:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AB2;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AB2:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23ABB;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23ABB:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+36);
        if (--r16[cx]) {
            pc = 0x23AC6;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23AC6:
        r16[si] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23ACF;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23ACF:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AD8;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AD8:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AE1;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AE1:
        r16[di] += 1;
        lodsb_data_forward();
        if (!(r8[al] & r8[al])) {
            pc = 0x23AEA;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23AEA:
        r16[di] += 1;
        r16[di] = r16[di] + memory16get(_ss*16+38);
        if (--r16[cx]) {
            pc = 0x23AF4;
            break;
        }
        pc = 0x23AF7;
        break;
    case 0x23AF4:
        pc = 0x23A39;
        break;
    case 0x23AF7:
        pc = 0x23C6E;
        break;
    case 0x23AFA:
        r16[dx] = r16[cx];
        sar16(cx, 1);
        r16[di] += r16[cx];
        r16[ax] = 0xb800;
        es = r16[ax];
        r8[cl] = r8[bl];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[cx] += 1;
        _xchg(bp, r16[dx]);
        r16[dx] += 0x0007;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        memory[cs*16+0x49E4] = r8[dl];
    case 0x23B1E:
        push(bp);
        push(r16[di]);
        r8[bh] = memory[cs*16+0x49E4];
        r16[si] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B34;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B34;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B34:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B46;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B46;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B46:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B58;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B58;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B58:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B6A;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B6A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B6A:
        bp += 0x0002;
        r16[di] += 1;
        r8[bh] -= 1;
        if (r8[bh] != 0) {
            pc = 0x23B75;
            break;
        }
        pc = 0x23C5B;
        break;
    case 0x23B75:
        r16[si] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B84;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B84;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B84:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23B96;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23B96;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23B96:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23BA8;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23BA8;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23BA8:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23BBA;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23BBA;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23BBA:
        bp += 0x0002;
        r16[di] += 1;
        r8[bh] -= 1;
        if (r8[bh] != 0) {
            pc = 0x23BC5;
            break;
        }
        pc = 0x23C5B;
        break;
    case 0x23BC5:
        r16[si] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23BD4;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23BD4;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23BD4:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23BE6;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23BE6;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23BE6:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23BF8;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23BF8;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23BF8:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23C0A;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23C0A;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23C0A:
        bp += 0x0002;
        r16[di] += 1;
        r8[bh] -= 1;
        if (r8[bh] == 0) {
            pc = 0x23C5B;
            break;
        }
        r16[si] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23C21;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23C21;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23C21:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23C33;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23C33;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23C33:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23C45;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23C45;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23C45:
        bp += 0x0002;
        r16[di] += 1;
        lodsb_data_forward();
        if (bp >= 0x0140) {
            pc = 0x23C57;
            break;
        }
        if (!(r8[al] & r8[al])) {
            pc = 0x23C57;
            break;
        }
        memory[es*16+r16[di]] = r8[al];
    case 0x23C57:
        bp += 0x0002;
        r16[di] += 1;
    case 0x23C5B:
        r16[di] = pop();
        bp = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x23C67;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23C67:
        if (--r16[cx]) {
            pc = 0x23C6B;
            break;
        }
        pc = 0x23C6E;
        break;
    case 0x23C6B:
        pc = 0x23B1E;
        break;
    case 0x23C6E:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_23C75() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(cs);
        yield* sub_2330D();
        r16[si] = pop();
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        r16[bx] = memory16get(ds*16+r16[si] + 22);
        r16[di] = memory16get(ds*16+r16[si] + 12);
        r16[cx] = _seg007;
        if (!(r16[di] & 0x0001)) {
            pc = 0x23C91;
            break;
        }
        r16[di] -= 1;
        r16[cx] = _seg008;
    case 0x23C91:
        push(es);
        es = r16[cx];
        r16[ax] = r16[ax] - memory16get(es*16+r16[di]);
        r16[bx] = r16[bx] - memory16get(es*16+r16[di] + 2);
        es = pop();
        yield* sub_23CB2();
        r16[ax] += 0x0010;
        yield* sub_23CB2();
        r16[bx] += 0x0010;
        yield* sub_23CB2();
        r16[ax] -= 0x0010;
        yield* sub_23CB2();
        return;
    } while (1);
}
function* sub_23CB2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[ax]);
        push(r16[bx]);
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[cx] = r16[ax];
        r16[cx] &= 0xfff0;
        r16[cx] >>= 1;
        if (r16[cx] >= 0x00a0) {
            pc = 0x23D11;
            break;
        }
        r16[dx] = r16[bx];
        r16[dx] = r16[dx] + memory16get(ds*16+0x9196);
        r16[dx] &= 0xfff0;
        r16[dx] = r16[dx] - memory16get(ds*16+0x9196);
        r16[bx] = r16[bx] + memory16get(ds*16+0x9196);
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] &= 0x00fe;
        r16[si] += r16[ax];
        r16[ax] = 0x0028;
        push(r16[dx]);
        _mul(r16[bx]);
        r16[dx] = pop();
        r16[si] += r16[ax];
        push(es);
        r16[ax] = _seg000;
        es = r16[ax];
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(es*16+0xF288, r16[ax]);
        es = pop();
        r16[ax] = 0x0001;
        r16[bx] = 0x0001;
        r16[si] = 0xf288;
        yield* sub_1EFF0();
    case 0x23D11:
        r16[bx] = pop();
        r16[ax] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_23D15() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[si] + 4, 0x0853);
    case 0x23D1A:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
    case 0x23D23:
        r16[ax] = _seg007;
        if (!(r16[si] & 0x0001)) {
            pc = 0x23D30;
            break;
        }
        r16[si] -= 1;
        r16[ax] = _seg008;
    case 0x23D30:
        push(ds);
        ds = r16[ax];
        lodsw_data_forward();
        r16[cx] -= r16[ax];
        r16[cx] &= 0xfffe;
        lodsw_data_forward();
        r16[dx] -= r16[ax];
        lodsw_data_forward();
        bp = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        if (r16s[cx] < signed16(0x0140)) {
            pc = 0x23D4B;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23D4B:
        if (r16s[dx] < memory16gets(_ss*16+16)) {
            pc = 0x23D55;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23D55:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > 0) {
            pc = 0x23D5E;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23D5E:
        r16[ax] = r16[dx];
        flags.sign = signed16(r16[ax] + r16[bx]) < 0;
        r16[ax] += r16[bx];
        if (!flags.sign) {
            pc = 0x23D67;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23D67:
        memory16set(ds*16+0x0, 0x0000);
        if (r16s[ax] <= memory16gets(_ss*16+16)) {
            pc = 0x23D7B;
            break;
        }
        r16[ax] = r16[ax] - memory16get(_ss*16+16);
        r16[bx] -= r16[ax];
    case 0x23D7B:
        if (r16s[dx] >= 0) {
            pc = 0x23DAF;
            break;
        }
        r16[bx] += r16[dx];
        r16[dx] = -r16[dx];
        r16[ax] = r16[dx];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x23DAA;
            break;
        }
        if (signed16(bp) > signed16(0x0010)) {
            pc = 0x23D99;
            break;
        }
        r16[ax] <<= 1;
        pc = 0x23DAA;
        break;
    case 0x23D99:
        if (signed16(bp) > signed16(0x0018)) {
            pc = 0x23DA6;
            break;
        }
        r16[dx] = r16[ax];
        r16[ax] <<= 1;
        r16[ax] += r16[dx];
        pc = 0x23DAA;
        break;
    case 0x23DA6:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
    case 0x23DAA:
        memory16set(ds*16+0x0, r16[ax]);
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x23DAF:
        r16[di] = r16[dx];
        r16[di] <<= 1;
        push(ds);
        r16[ax] = dseg;
        ds = r16[ax];
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        ds = pop();
        if (r16s[cx] >= 0) {
            pc = 0x23DC5;
            break;
        }
        pc = 0x23E45;
        break;
    case 0x23DC5:
        r16[ax] = r16[cx];
        r16[ax] += bp;
        if (r16s[ax] > signed16(0x0140)) {
            pc = 0x23E47;
            break;
        }
        r16[cx] >>= 1;
        r16[di] += r16[cx];
        r16[ax] = 0xb800;
        es = r16[ax];
        r8[cl] = r8[bl];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[cx] += 1;
        r16[si] = r16[si] + memory16get(ds*16+0x0);
        if (signed16(bp) <= signed16(0x0008)) {
            pc = 0x23E34;
            break;
        }
        if (signed16(bp) <= signed16(0x0010)) {
            pc = 0x23E20;
            break;
        }
        if (signed16(bp) <= signed16(0x0018)) {
            pc = 0x23E09;
            break;
        }
    case 0x23DEF:
        yield* sub_2312A();
        yield* sub_2312A();
        yield* sub_2312A();
        yield* sub_2312A();
        flags.sign = signed16(r16[di] + 0x1ff0) < 0;
        r16[di] += 0x1ff0;
        if (!flags.sign) {
            pc = 0x23E05;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23E05:
        if (--r16[cx]) {
            pc = 0x23DEF;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23E09:
        yield* sub_2312A();
        yield* sub_2312A();
        yield* sub_2312A();
        flags.sign = signed16(r16[di] + 0x1ff4) < 0;
        r16[di] += 0x1ff4;
        if (!flags.sign) {
            pc = 0x23E1C;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23E1C:
        if (--r16[cx]) {
            pc = 0x23E09;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23E20:
        yield* sub_2312A();
        yield* sub_2312A();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x23E30;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23E30:
        if (--r16[cx]) {
            pc = 0x23E20;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23E34:
        yield* sub_2312A();
        flags.sign = signed16(r16[di] + 0x1ffc) < 0;
        r16[di] += 0x1ffc;
        if (!flags.sign) {
            pc = 0x23E41;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23E41:
        if (--r16[cx]) {
            pc = 0x23E34;
            break;
        }
        pc = 0x23E49;
        break;
    case 0x23E45:
        pc = 0x23E49;
        break;
    case 0x23E47:
        _STOP_("goto $+2");
    case 0x23E49:
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_23E4F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[si] = memory16get(ds*16+r16[si] + 12);
        r16[bx] = r16[bx] - memory16get(ds*16+r16[si]);
        r16[bx] &= 0xfffe;
        if (r16[bx] >= 0x0140)
            return;
        r16[dx] = r16[dx] - memory16get(ds*16+r16[si] + 2);
        if (r16s[dx] >= signed16(0x00c0))
            return;
        r16[cx] = memory16get(ds*16+r16[si] + 4);
        r16[ax] = r16[bx];
        r16[bx] &= 0x0001;
        r16[ax] = r16[ax] ^ r16[bx];
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + r16[si] + 6);
        if (r16s[dx] >= 0) {
            pc = 0x23E89;
            break;
        }
        r16[si] -= r16[dx];
        r16[si] -= r16[dx];
        r16[cx] += r16[dx];
        if (r16s[cx] <= signed16(0))
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x23E89:
        r16[bx] = r16[dx];
        r16[bx] += r16[cx];
        r16[bx] -= 0x00c0;
        if (_FIXME_) {
            pc = 0x23E97;
            break;
        }
        r16[cx] -= r16[bx];
        if (_FIXME_)
            return;
    case 0x23E97:
        r16[di] = r16[dx];
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        r16[bx] = 0xb800;
        es = r16[bx];
        if (r16s[ax] >= signed16(0x0138)) {
            pc = 0x23EBE;
            break;
        }
    case 0x23EAD:
        yield* sub_231A5();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x23EBA;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23EBA:
        if (--r16[cx]) {
            pc = 0x23EAD;
            break;
        }
        pc = 0x23ECD;
        break;
    case 0x23EBE:
        yield* sub_23294();
        flags.sign = signed16(r16[di] + 0x1ffc) < 0;
        r16[di] += 0x1ffc;
        if (!flags.sign) {
            pc = 0x23ECB;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23ECB:
        if (--r16[cx]) {
            pc = 0x23EBE;
            break;
        }
    case 0x23ECD:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_23ED2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = r16[di] ^ r16[di];
        r16[si] = 0x0000;
        r16[si] = r16[si] + memory16get(ds*16+0x918E);
        r16[dx] = memory16get(ds*16+0x9196);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[cx] = 0x0010;
        r16[cx] -= r16[dx];
        r8[bl] = 0x14;
    case 0x23EEB:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] += r16[dx];
        r16[si] += r16[dx];
        r16[si] <<= 1;
        r16[si] <<= 1;
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        push(r16[cx]);
    case 0x23F01:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x23F0F;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x23F0F:
        if (--r16[cx]) {
            pc = 0x23F01;
            break;
        }
        bp = r16[di];
        r16[cx] = pop();
        r16[di] = pop();
        r16[di] += 0x0008;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x23EEB;
            break;
        }
        r16[di] = bp;
        r16[di] -= 0x0098;
        r16[bx] = 0x0010;
        r16[bx] = r16[bx] - memory16get(ds*16+0x9196);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + -26816);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[bx] + 38718);
        r16[ax] -= 0x0008;
        memory16set(_ss*16+32, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + -26814);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[bx] + -26816);
        r16[ax] -= 0x0008;
        memory16set(_ss*16+34, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + -26812);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[bx] + -26814);
        r16[ax] -= 0x0008;
        memory16set(_ss*16+36, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + -26810);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[bx] + -26812);
        r16[ax] -= 0x0008;
        memory16set(_ss*16+38, r16[ax]);
        r16[bx] = 0x0b14;
    case 0x23F6C:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        if (r16[ax] != 0) {
            pc = 0x23F75;
            break;
        }
        pc = 0x24016;
        break;
    case 0x23F75:
        r16[si] = r16[ax];
        r16[si] <<= 1;
        r16[si] <<= 1;
        r16[cx] = ds;
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        pc = 0x240B0;
        break;
    case 0x24016:
        r16[cx] = ds;
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        r16[ax] = r16[ax] ^ r16[ax];
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+32);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+34);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+36);
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        stosw_data_forward();
        r16[di] = r16[di] + memory16get(_ss*16+38);
    case 0x240B0:
        bp = r16[di];
        r16[di] = pop();
        r16[di] += 0x0008;
        ds = r16[cx];
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] == 0) {
            pc = 0x240C0;
            break;
        }
        pc = 0x23F6C;
        break;
    case 0x240C0:
        r8[bl] = 0x14;
        r16[di] = bp;
        r16[di] -= 0x0098;
        r8[bh] -= 1;
        if (r8[bh] == 0) {
            pc = 0x240CF;
            break;
        }
        pc = 0x23F6C;
        break;
    case 0x240CF:
        r16[dx] = memory16get(ds*16+0x9196);
        if (!(r16[dx] & r16[dx])) {
            pc = 0x24106;
            break;
        }
        r8[bl] = 0x14;
    case 0x240D9:
        lodsw_data_forward();
        push(r16[si]);
        r16[ax] >>= 1;
        r16[si] = r16[ax];
        r16[si] <<= 1;
        r16[si] <<= 1;
        push(ds);
        r16[ax] = _seg009;
        ds = r16[ax];
        push(r16[di]);
        r16[cx] = r16[dx];
    case 0x240EC:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x240FA;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x240FA:
        if (--r16[cx]) {
            pc = 0x240EC;
            break;
        }
        r16[di] = pop();
        r16[di] += 0x0008;
        ds = pop();
        r16[si] = pop();
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x240D9;
            break;
        }
    case 0x24106:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_2410B() {
    yield* sub_2411A();
    yield* sub_24130();
    yield* sub_2411A();
    yield* sub_24130();
}
function* sub_2411A() {
    push(es);
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[di] = r16[di] ^ r16[di];
    r16[ax] = r16[ax] ^ r16[ax];
    r16[cx] = 0x4000;
    rep_stosw_data_forward();
    es = pop();
}
function* sub_2412B() {
    yield* sub_2411A();
}
function* sub_24130() {
    push(r16[ax]);
    push(r16[bx]);
    r16[ax] = 0x0583;
    r16[bx] = memory16get(ds*16+0x4255);
    xchg8(bh, bl);
    memory16set(ds*16+0x4255, r16[bx]);
    interrupt(16);
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_24144() {
    push(r16[ax]);
    push(r16[bx]);
    r16[ax] = 0x0583;
    r16[bx] = memory16get(ds*16+0x4255);
    r8[bl] = r8[bh];
    interrupt(16);
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_24154() {
    push(r16[ax]);
    push(r16[bx]);
    r16[ax] = 0x0583;
    r16[bx] = memory16get(ds*16+0x4255);
    interrupt(16);
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_24162() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_10EF1();
    case 0x24167:
        if (memory16get(ds*16+0x3046) == 0x0000) {
            pc = 0x24167;
            break;
        }
        yield* sub_24130();
        memory16set(ds*16+0x3046, 0x0000);
        return;
    } while (1);
}
function* sub_24178() {
    yield* sub_24185();
    yield* sub_24130();
    yield* sub_24185();
    yield* sub_24130();
}
function* sub_24185() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x0000;
        r16[di] = memory16get(ds*16+0x98BE);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[cx] = 0x0008;
    case 0x2419A:
        push(r16[cx]);
        r16[cx] = 0x0050;
        rep_movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1f60) < 0;
        r16[di] += 0x1f60;
        if (!flags.sign) {
            pc = 0x241AA;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x241AA:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2419A;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_241B3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x9c80;
        r16[cx] = 0x0050;
    case 0x241BE:
        lodsw_data_forward();
        if (r16s[ax] < 0) {
            pc = 0x2422D;
            break;
        }
        r16[bx] = r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[bx] += r16[ax];
        lodsw_data_forward();
        r16[dx] += r16[ax];
        if (r16[bx] >= 0x013c) {
            pc = 0x24226;
            break;
        }
        if (r16[dx] >= 0x00bc) {
            pc = 0x24226;
            break;
        }
        memory16set(ds*16+r16[si] - 8, r16[bx]);
        memory16set(ds*16+r16[si] - 6, r16[dx]);
        push(r16[bx]);
        push(r16[dx]);
        push(r16[cx]);
        r16[ax] = r16[bx];
        r16[bx] = r16[dx];
        yield* sub_10EDD();
        if (_FIXME_) {
            pc = 0x24205;
            break;
        }
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[ax] = memory16get(es*16+0x3DA8);
        push(r16[si]);
        yield* sub_10EE1();
        r16[si] = pop();
        es = pop();
        r16[cx] = pop();
        sp += 0x0004;
        pc = 0x24226;
        break;
    case 0x24205:
        r16[cx] = pop();
        r16[di] = pop();
        r16[ax] = pop();
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        memory[es*16+r16[di]] = 0x77;
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x24220;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24220:
        memory[es*16+r16[di]] = 0x77;
        pc = 0x24230;
        break;
    case 0x24226:
        memory16set(ds*16+r16[si] - 8, 0xffff);
        pc = 0x24230;
        break;
    case 0x2422D:
        r16[si] += 0x0006;
    case 0x24230:
        if (--r16[cx]) {
            pc = 0x241BE;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24237() {
    r16[ax] = memory16get(ds*16+r16[si] + 52);
    memory16set(ds*16+0xFCFE, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 18);
    memory16set(ds*16+0xFCE2, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[si] + 22);
    memory16set(ds*16+0xFCE6, r16[ax]);
    push(r16[si]);
    yield* sub_24250();
    r16[si] = pop();
}
function* sub_24250() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + 0x0004);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE2);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCE6);
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+0xFCFE);
        memory16set(ds*16+0x32C0, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        memory16set(ds*16+0x32BE, r16[ax]);
        if (memory16gets(ds*16+0xFCE2) > signed16(0xfff0)) {
            pc = 0x24285;
            break;
        }
        pc = 0x2431E;
        break;
    case 0x24285:
        if (memory16gets(ds*16+0xFCE2) < signed16(0x0140)) {
            pc = 0x24290;
            break;
        }
        pc = 0x2431E;
        break;
    case 0x24290:
        if (memory16gets(ds*16+0x32BE) < signed16(0x0041)) {
            pc = 0x242BA;
            break;
        }
        r16[bx] = memory16get(ds*16+0xFCFE);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 12994);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        r16[dx] += 1;
        yield* sub_23316();
        r16[ax] = memory16get(ds*16+0x32BA);
        memory16set(ds*16+0xFCE2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x32BC);
        memory16set(ds*16+0xFCE6, r16[ax]);
    case 0x242BA:
        r16[ax] = memory16get(ds*16+0x32BE);
        memory16set(ds*16+0xFCE6, memory16get(ds*16+0xFCE6) - r16[ax]);
        r16[si] = 0x32c8;
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[si] = memory16get(ds*16+r16[bx] + 13000);
        r16[cx] = memory16get(ds*16+0xFCE2);
        r16[dx] = memory16get(ds*16+0xFCE6);
        yield* sub_23316();
        if (memory16gets(ds*16+0x32BC) < 0 /*CHECK*/) {
            pc = 0x2431E;
            break;
        }
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = memory16get(ds*16+0x32BC);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[bx] = memory16get(ds*16+0x32C0);
        r16[bx] <<= 1;
        r16[cx] = memory16get(ds*16+r16[bx] + 13252);
        r16[ax] = memory16get(ds*16+0x32BA);
        sar16(ax, 1);
        if (_FIXME_) {
            pc = 0x24307;
            break;
        }
        r16[cx] += r16[ax];
        if (r16s[cx] <= signed16(0)) {
            pc = 0x2431E;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x24307:
        r16[bx] = r16[ax];
        r16[bx] += r16[cx];
        if (r16s[bx] <= signed16(0x00a0)) {
            pc = 0x24319;
            break;
        }
        r16[bx] -= 0x00a0;
        r16[cx] -= r16[bx];
        if (_FIXME_) {
            pc = 0x2431E;
            break;
        }
    case 0x24319:
        r16[di] += r16[ax];
        yield* sub_24323();
    case 0x2431E:
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24323() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds*16+0x32BE);
        if (!(r16[dx] & r16[dx]))
            return;
        r16[ax] = 0x7777;
    case 0x2432E:
        push(r16[di]);
        push(r16[cx]);
        rep_stosb_data_forward();
        r16[cx] = pop();
        r16[di] = pop();
        if (r16s[di] < signed16(0x00a0))
            return;
        r16[di] -= 0x2000;
        if (r16s[di] >= 0) {
            pc = 0x24344;
            break;
        }
        r16[di] += 0x7f60;
    case 0x24344:
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x2432E;
            break;
        }
        return;
    } while (1);
}
function* sub_24348() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x9152);
        r16[dx] = memory16get(ds*16+0x9154);
        flags.carry = r16[ax] < memory16get(ds*16+0x9156);
        r16[ax] = r16[ax] - memory16get(ds*16+0x9156);
        r16[dx] -= memory16get(ds*16+0x9158) + flags.carry;
        if (r16s[ax] < 0) {
            pc = 0x243C9;
            break;
        }
        if (r16[ax] != 0) {
            pc = 0x2435F;
            break;
        }
        if (!(r16[ax] & r16[ax]))
            return;
    case 0x2435F:
        r16[di] = memory16get(ds*16+0x98BE);
        if (r16[dx] & r16[dx]) {
            pc = 0x24371;
            break;
        }
        if (r16s[ax] < signed16(0x00c8)) {
            pc = 0x2438C;
            break;
        }
        if (r16s[ax] < signed16(0x07d0)) {
            pc = 0x2437F;
            break;
        }
    case 0x24371:
        r16[bx] = 0x921f;
        r16[di] += 0x0018;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x03e8);
        pc = 0x24397;
        break;
    case 0x2437F:
        r16[bx] = 0x9220;
        r16[di] += 0x001c;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x0064);
        pc = 0x24397;
        break;
    case 0x2438C:
        r16[bx] = 0x9221;
        r16[di] += 0x0020;
        memory16set(ds*16+0x9156, memory16get(ds*16+0x9156) + 0x000a);
    case 0x24397:
        memory16set(ds*16+0x9158, memory16get(ds*16+0x9158) + 0x0000 + flags.carry); assert(0);
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x243A6;
            break;
        }
        r16[di] += 0x006c;
    case 0x243A6:
        r16[si] = 0x0500;
    case 0x243A9:
        memory[ds*16+r16[bx]] += 1;
        if (memorys[ds*16+r16[bx]] < signed8(0x0a)) {
            pc = 0x243B3;
            break;
        }
        memory[ds*16+r16[bx]] = 0x00;
    case 0x243B3:
        r8[al] = memory[ds*16+r16[bx]];
        yield* sub_2441D();
        if (memory[ds*16+r16[bx]] != 0x00)
            return;
        r16[di] -= 0x0004;
        r16[bx] -= 1;
        if (r16s[bx] >= signed16(0x921c)) {
            pc = 0x243A9;
            break;
        }
        return;
    case 0x243C9:
        r16[ax] = memory16get(ds*16+0x9156);
        memory16set(ds*16+0x9152, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9158);
        memory16set(ds*16+0x9154, r16[ax]);
        return;
    } while (1);
}
function* sub_243D6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+0x98BE);
        r16[di] += 0x000c;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x243E7;
            break;
        }
        r16[di] += 0x006c;
    case 0x243E7:
        r16[si] = 0x0500;
        r16[cx] = 0x0007;
    case 0x243ED:
        r8[al] = r8[al] ^ r8[al];
        yield* sub_2441D();
        r16[di] += 0x0004;
        if (--r16[cx]) {
            pc = 0x243ED;
            break;
        }
        return;
    } while (1);
}
function* sub_243F9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x918A);
        if (r16s[ax] <= signed16(0x0009)) {
            pc = 0x24404;
            break;
        }
        r16[ax] = 0x0009;
    case 0x24404:
        r16[si] = 0x0640;
        r16[di] = memory16get(ds*16+0x98C0);
        r16[di] += 0x0044;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x24418;
            break;
        }
        r16[di] += 0x0014;
    case 0x24418:
        yield* sub_2441D();
        return;
    } while (1);
}
function* sub_2441D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[cx]);
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        push(r16[si]);
        push(r16[di]);
        r16[cx] = 0x0008;
    case 0x2443D:
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ffc) < 0;
        r16[di] += 0x1ffc;
        if (!flags.sign) {
            pc = 0x24449;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24449:
        if (--r16[cx]) {
            pc = 0x2443D;
            break;
        }
        r16[di] = pop();
        r16[si] = pop();
        ds = pop();
        yield* sub_24144();
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        push(r16[di]);
        r16[cx] = 0x0008;
    case 0x2445B:
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ffc) < 0;
        r16[di] += 0x1ffc;
        if (!flags.sign) {
            pc = 0x24467;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24467:
        if (--r16[cx]) {
            pc = 0x2445B;
            break;
        }
        r16[di] = pop();
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        r16[cx] = pop();
        r16[si] = pop();
        yield* sub_24154();
        return;
    } while (1);
}
function* sub_24475() {
    push(r16[si]);
    push(r16[ax]);
    yield* sub_24488();
    yield* sub_24144();
    r16[ax] = pop();
    r16[si] = pop();
    yield* sub_24488();
    yield* sub_24154();
}
function* sub_24488() {
    r16[di] = memory16get(ds*16+0x3752);
    r16[di] <<= 1;
    r16[di] = memory16get(ds*16+r16[di] + 38718);
    push(memory16get(ds*16+r16[si] + 20));
    push(r16[si]);
    memory[ds*16+r16[si] + 20] = 0x00;
    yield* sub_24535();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 20, pop());
}
function* sub_244A3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = memory16get(ds*16+0x9896);
        r16[di] += 0x0044;
        memory16set(ds*16+0xFCE2, r16[ax]);
        memory16set(ds*16+0xFCE4, r16[dx]);
        r16[bx] = 0x3756;
        r16[si] = 0x0500;
    case 0x244B7:
        if (memory16get(ds*16+r16[bx]) == 0x0000)
            return;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x244BE:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        _FIXME_;
        if (memory16gets(ds*16+0xFCE2) < 0) {
            pc = 0x244D0;
            break;
        }
        r16[dx] += 1;
        pc = 0x244BE;
        break;
    case 0x244D0:
        r16[ax] = memory16get(ds*16+r16[bx]);
        memory16set(ds*16+0xFCE2, memory16get(ds*16+0xFCE2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        memory16set(ds*16+0xFCE4, memory16get(ds*16+0xFCE4) + r16[ax] + flags.carry); assert(0);
        r16[bx] += 0x0004;
        r8[al] = r8[dl];
        yield* sub_2441D();
        r16[di] += 0x0004;
        pc = 0x244B7;
        break;
        return;
    } while (1);
}
function* sub_244EC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2411A();
        memory16set(ds*16+0x3752, 0x000c);
        r16[si] = 0x352b;
        yield* sub_24475();
        r16[si] = 0x358f;
        r16[di] = memory16get(ds*16+0x978A);
        r16[di] += 0x0010;
        r16[cx] = 0x000a;
    case 0x2450A:
        push(r16[si]);
        push(r16[di]);
        push(r16[cx]);
        yield* sub_24524();
        r16[cx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[si] += 0x000f;
        r16[di] += 0x0280;
        if (--r16[cx]) {
            pc = 0x2450A;
            break;
        }
        yield* sub_23077();
    {yield* sub_24162(); return; };
        return;
    } while (1);
}
function* sub_24524() {
    push(memory16get(ds*16+r16[si] + 15));
    push(r16[si]);
    memory[ds*16+r16[si] + 15] = 0x00;
    yield* sub_24547();
    r16[si] = pop();
    memory16set(ds*16+r16[si] + 15, pop());
}
function* sub_24535() {
    bp = 0x0780;
    r16[cx] = 0x0016;
    yield* sub_24552();
}
function* sub_24540() {
    r16[di] = memory16get(ds*16+0x98AE);
    r16[di] += 0x0058;
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_24547() {
    bp = 0x2300;
    r16[cx] = 0x000e;
    yield* sub_24552();
}
function* sub_24552() {
    lodsb_data_forward();
    if (!(r8[al] & r8[al]))
        return;
    {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
    push(r16[si]);
    yield* sub_24567();
    r16[si] = pop();
    {var t = r16[si]; r16[si] = bp; bp = t;}//_xchg(r16[si], bp);
    r16[di] += 0x0008;
{yield* sub_24552(); return; };
    return;
}
function* sub_24567() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[di]);
        push(r16[cx]);
        push(r16[di]);
        memory[ds*16+0x33F2] = r8[al];
        r16[di] = 0x33ca;
        r16[cx] = 0x33f2;
        r16[cx] -= 0x33ca;
        r16[cx] += 1;
        _repne_scasb();
        r16[ax] = r16[di];
        r16[ax] -= 0x33cb;
        r16[di] = pop();
        if (r16[ax] == 0x0028) {
            pc = 0x245B1;
            break;
        }
        r16[cx] = pop();
        _mul(r16[cx]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] += r16[ax];
        push(r16[cx]);
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
    case 0x2459C:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1ff8) < 0;
        r16[di] += 0x1ff8;
        if (!flags.sign) {
            pc = 0x245AA;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x245AA:
        if (--r16[cx]) {
            pc = 0x2459C;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
    case 0x245B1:
        r16[cx] = pop();
        r16[di] = pop();
        return;
    } while (1);
}
function* sub_245B4() {
    if (memory[ds*16+0x8FAF] == 0x00)
        return;
    memory[ds*16+0x8FAF] = 0x00;
    yield* sub_245CD();
    yield* sub_24144();
    yield* sub_245CD();
    yield* sub_24154();
    return;
}
function* sub_245CD() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[bx] = memory16get(ds*16+0x9186);
        if (r16s[bx] <= signed16(0x0027)) {
            pc = 0x245DE;
            break;
        }
        r16[bx] = 0x0027;
    case 0x245DE:
        r16[bx] -= 0x0027;
        r16[bx] = -r16[bx];
        r16[di] = memory16get(ds*16+0x98C4);
        r16[di] += 0x002d;
        r16[ax] = 0x0f0e;
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x245FE;
            break;
        }
        r16[di] = memory16get(ds*16+0x98C4);
        r16[di] += 0x005f;
        r16[ax] = 0xf0e0;
    case 0x245FE:
        r16[cx] = 0x0027;
    case 0x24601:
        if (r16[cx] != r16[bx]) {
            pc = 0x24607;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
    case 0x24607:
        push(r16[di]);
        r8[ah] = (~r8[ah]);
        memory[es*16+r16[di]] &= r8[ah];
        memory[es*16+r16[di]] |= r8[al];
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x2461A;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x2461A:
        memory[es*16+r16[di]] &= r8[ah];
        memory[es*16+r16[di]] |= r8[al];
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x2462A;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x2462A:
        memory[es*16+r16[di]] &= r8[ah];
        memory[es*16+r16[di]] |= r8[al];
        r8[ah] = (~r8[ah]);
        r16[di] = pop();
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        ror16(ax, 1);
        if (!(r8[al] & 0xf0)) {
            pc = 0x24642;
            break;
        }
        xchg8(al, ah);
        r16[di] += 1;
    case 0x24642:
        if (--r16[cx]) {
            pc = 0x24601;
            break;
        }
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24649() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x33BC) != 0x0000) {
            pc = 0x24674;
            break;
        }
        r16[si] = memory16get(ds*16+0x98BE);
        push(ds);
        r16[ax] = 0xb800;
        ds = r16[ax];
        r16[di] = 0x923e;
        r16[cx] = 0x0008;
    case 0x24660:
        push(r16[cx]);
        r16[cx] = 0x0050;
        rep_movsw_data_data_forward();
        flags.sign = signed16(r16[si] + 0x1f60) < 0;
        r16[si] += 0x1f60;
        if (!flags.sign) {
            pc = 0x24670;
            break;
        }
        r16[si] -= 0x7f60;
    case 0x24670:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x24660;
            break;
        }
        ds = pop();
    case 0x24674:
        memory[ds*16+0x33BC] += 1;
        return;
    } while (1);
}
function* sub_24679() {
    memory[ds*16+0x33BC] -= 1;
    if (memory[ds*16+0x33BC] != 0)
        return;
    yield* sub_2468C();
    yield* sub_24144();
    yield* sub_2468C();
    yield* sub_24154();
    return;
}
function* sub_2468C() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x923e;
        r16[di] = memory16get(ds*16+0x98BE);
        r16[cx] = 0x0008;
    case 0x2469C:
        push(r16[cx]);
        r16[cx] = 0x0050;
        rep_movsw_data_data_forward();
        flags.sign = signed16(r16[di] + 0x1f60) < 0;
        r16[di] += 0x1f60;
        if (!flags.sign) {
            pc = 0x246AC;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x246AC:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2469C;
            break;
        }
        es = pop();
        return;
    } while (1);
}
function* sub_246B1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0080;
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
    case 0x246B8:
        push(r16[cx]);
        push(ds);
        push(r16[di]);
        r16[ax] = 0xb800;
        ds = r16[ax];
        r16[di] = 0x43cf;
        r16[cx] = 0x0080;
        rep_movsw_data_data_forward();
        r16[di] = pop();
        ds = pop();
        yield* sub_24144();
        push(es);
        push(r16[si]);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = 0x43cf;
        r16[cx] = 0x0080;
        rep_movsw_data_data_forward();
        r16[si] = pop();
        es = pop();
        yield* sub_24154();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x246B8;
            break;
        }
        return;
    } while (1);
}
function* sub_246E5() {
    var cs = _seg001;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2411A();
        r16[si] = 0x582e;
    case 0x246EC:
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        if (!(r16[ax] & r16[ax])) {
            pc = 0x24721;
            break;
        }
        bp = r16[ax];
        r16[ax] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[di] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] += r16[ax];
        r16[dx] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        r16[cx] = memory16get(cs*16+r16[si]);
        r16[si] += 0x0002;
        push(r16[si]);
        r16[si] = bp;
        yield* sub_247BF();
        r16[si] = pop();
        pc = 0x246EC;
        break;
    case 0x24721:
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x24723:
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x24725:
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xec90;
        yield* sub_23316();
        r16[dx] = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0xefc0;
        yield* sub_23316();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[cx] += 0x0029;
        if (r16s[cx] < signed16(0x00cd)) {
            pc = 0x24725;
            break;
        }
        r16[dx] += 0x0029;
        if (r16s[dx] < signed16(0x00a4)) {
            pc = 0x24723;
            break;
        }
        if (memory16get(ds*16+0x8E7A) == 0x0000) {
            pc = 0x24761;
            break;
        }
        r16[si] = 0xfc20;
        r16[cx] = 0x00c1;
        r16[dx] = 0x00bc;
        yield* sub_23316();
    case 0x24761:
        yield* sub_246B1();
        return;
    } while (1);
}
function* sub_24766() {
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    yield* sub_23316();
    yield* sub_24144();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    yield* sub_23316();
    yield* sub_24154();
}
function* sub_2477B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_2411A();
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = memory16get(ds*16+0x9806);
        r16[di] += 0x0052;
        memory[es*16+r16[di]] = 0x07;
        memory[es*16+r16[di] + 1] = 0x70;
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x2479E;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x2479E:
        memory[es*16+r16[di]] = 0x77;
        memory[es*16+r16[di] + 1] = 0x77;
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x247B1;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x247B1:
        memory[es*16+r16[di]] = 0x07;
        memory[es*16+r16[di] + 1] = 0x70;
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_247BF() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
    case 0x247CA:
        push(r16[cx]);
        r16[cx] = r16[dx];
        push(r16[di]);
        rep_movsb_data_data_forward();
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x247DB;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x247DB:
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x247CA;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_247E4() {
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[di] = memory16get(ds*16+0x9822);
    r16[di] += 0x0068;
    r16[cx] = 0x0045;
    yield* sub_2480E();
    yield* sub_24144();
    r16[di] = memory16get(ds*16+0x9822);
    r16[di] += 0x0068;
    r16[cx] = 0x0045;
    yield* sub_2480E();
    yield* sub_24154();
    r16[ax] = ds;
    es = r16[ax];
}
function* sub_2480E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x24832;
        break;
    case 0x24810:
        push(r16[di]);
        r16[di] += 0x0003;
        memory[es*16+r16[di]] &= 0xf0;
        r16[di] += 1;
        r16[ax] = r16[ax] ^ r16[ax];
        push(r16[cx]);
        r16[cx] = 0x0017;
        rep_stosw_data_forward();
        stosb_data_forward();
        r16[cx] = pop();
        memory[es*16+r16[di]] &= 0x0f;
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x24832;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24832:
        if (--r16[cx]) {
            pc = 0x24810;
            break;
        }
        return;
    } while (1);
}
function* sub_24835() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x8430;
        r16[di] = memory16get(ds*16+0x9750);
        r16[di] += 0x0068;
        r16[cx] = 0x0034;
        yield* sub_249C3();
        r16[si] = 0x8f90;
        r16[di] = memory16get(ds*16+0x97FC);
        r16[di] += 0x0068;
        r16[cx] = 0x000a;
        yield* sub_249C3();
        r16[si] = 0x91c0;
        if (memory[ds*16+0x8F40] == 0x00) {
            pc = 0x24873;
            break;
        }
        yield* sub_10ED9();
        r16[cx] = 0x0004;
        pc = 0x2486D;
        break;
    case 0x24869:
        r16[si] += 0x0770;
    case 0x2486D:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (flags.carry) {
            pc = 0x24873;
            break;
        }
        if (--r16[cx]) {
            pc = 0x24869;
            break;
        }
    case 0x24873:
        r16[di] = memory16get(ds*16+0x97B8);
        r16[di] += 0x0068;
        r16[cx] = 0x0022;
        yield* sub_249C3();
        yield* sub_10EE5();
        yield* sub_10EE9();
        if (memory16get(ds*16+0x8F3C) != 0x0000) {
            pc = 0x24894;
            break;
        }
        return;
    case 0x24894:
        if (memory16gets(ds*16+0x8F3C) <= signed16(0x0008)) {
            pc = 0x248DA;
            break;
        }
        r16[di] = memory16get(ds*16+0x9750);
        r16[di] += 0x0068;
        r16[si] = 0x5c18;
        r16[ax] = 0x0030;
        r16[ax] = r16[ax] - memory16get(ds*16+0x8F3C);
        r16[dx] = 0x0038;
        _mul(r16[dx]);
        r16[si] += r16[ax];
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_249C3();
        r16[di] = 0x0071;
        r16[di] = r16[di] - memory16get(ds*16+0x8F3C);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[di] += 0x0068;
        r16[si] = 0x64d8;
        r16[cx] = memory16get(ds*16+0x8F3C);
        r16[cx] -= 0x0008;
        yield* sub_249C3();
    case 0x248DA:
        r16[cx] = 0x00d7;
        r16[dx] = memory16get(ds*16+0x8F3C);
        r16[dx] += 1;
        push(r16[dx]);
        r16[si] = 0xabe4;
        yield* sub_23316();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xace4;
        yield* sub_23316();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xad94;
        yield* sub_23316();
        r16[cx] = 0x00d7;
        r16[dx] = 0x0070;
        r16[dx] = r16[dx] - memory16get(ds*16+0x8F3C);
        push(r16[dx]);
        r16[si] = 0xae94;
        yield* sub_23316();
        r16[cx] = 0x00f7;
        r16[dx] = pop();
        push(r16[dx]);
        r16[si] = 0xaf94;
        yield* sub_23316();
        r16[cx] = 0x0117;
        r16[dx] = pop();
        r16[si] = 0xb044;
        yield* sub_23316();
        if (memory16gets(ds*16+0x8F3C) >= signed16(0x0008))
            return;
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = 0x0068;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4750;
        r16[cx] = 0x0009;
    case 0x24945:
        push(r16[di]);
        push(r16[cx]);
        r16[cx] = 0x0007;
    case 0x2494A:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        if (--r16[cx]) {
            pc = 0x2494A;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x2495C;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x2495C:
        r16[si] += 0x0008;
        if (--r16[cx]) {
            pc = 0x24945;
            break;
        }
        ds = pop();
        r16[di] = memory16get(ds*16+0x9810);
        r16[di] += 0x0068;
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[si] = 0x4990;
        r16[cx] = 0x0009;
    case 0x24975:
        push(r16[di]);
        push(r16[cx]);
        r16[cx] = 0x0007;
    case 0x2497A:
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        if (--r16[cx]) {
            pc = 0x2497A;
            break;
        }
        r16[cx] = pop();
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x2498C;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x2498C:
        r16[si] += 0x0008;
        if (--r16[cx]) {
            pc = 0x24975;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24997() {
    if (memory16get(ds*16+0x8F3E) == 0x0000)
        return;
    r16[di] = memory16get(ds*16+0x9822);
    r16[di] += 0x0068;
    r16[cx] = 0x0045;
    r16[cx] = r16[cx] - memory16get(ds*16+0x8F3E);
    r16[ax] = 0xb800;
    es = r16[ax];
    yield* sub_2480E();
    r16[ax] = ds;
    es = r16[ax];
    r16[si] = 0x6d98;
    r16[cx] = memory16get(ds*16+0x8F3E);
    yield* sub_249C3();
    return;
}
function* sub_249C3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[ax] = _seg005;
        ds = r16[ax];
    case 0x249CE:
        push(r16[di]);
        r16[di] += 0x0003;
        r16[si] += 0x0003;
        movsb_data_data_forward();
        push(r16[cx]);
        r16[cx] = 0x0017;
        rep_movsw_data_data_forward();
        movsb_data_data_forward();
        r16[cx] = pop();
        r16[si] += 0x0005;
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x249EC;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x249EC:
        if (--r16[cx]) {
            pc = 0x249CE;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        return;
    } while (1);
}
function* sub_249F4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[si] = memory16get(ds*16+r16[di] + 4);
        r16[si] <<= 1;
        r16[si] = memory16get(ds*16+r16[si] - 26818);
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[ax] += 1;
        r16[ax] >>= 1;
        r16[si] += r16[ax];
        xchg16(si, di);
        r8[bl] = 0x1c;
    case 0x24A0E:
        yield* sub_10ED9();
        push(r16[di]);
        r16[cx] = 0x000f;
        rep_stosb_data_forward();
        r16[di] = pop();
        flags.sign = signed16(r16[di] + 0x2000) < 0;
        r16[di] += 0x2000;
        if (!flags.sign) {
            pc = 0x24A24;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24A24:
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x24A0E;
            break;
        }
        r16[di] = r16[si];
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24A2F() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] != 0x0d) {
            pc = 0x24A38;
            break;
        }
    {yield* loc_10EED(); return; };
    case 0x24A38:
        push(r16[ax]);
        r16[di] = memory16get(ds*16+0x8F48);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x8F46);
        r16[ax] <<= 1;
        r16[di] += r16[ax];
        r16[ax] = pop();
        r8[al] -= 0x20;
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[si] = 0x7cb0;
        r16[si] += r16[ax];
        r16[ax] = 0xb800;
        es = r16[ax];
        push(r16[si]);
        push(r16[di]);
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[cx] = 0x0008;
    case 0x24A6E:
        movsw_data_data_forward();
        r16[si] += 0x0002;
        flags.sign = signed16(r16[di] + 0x1ffe) < 0;
        r16[di] += 0x1ffe;
        if (!flags.sign) {
            pc = 0x24A7C;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24A7C:
        if (--r16[cx]) {
            pc = 0x24A6E;
            break;
        }
        ds = pop();
        yield* sub_24144();
        r16[di] = pop();
        r16[si] = pop();
        push(ds);
        r16[ax] = _seg005;
        ds = r16[ax];
        r16[cx] = 0x0008;
    case 0x24A8D:
        movsw_data_data_forward();
        r16[si] += 0x0002;
        flags.sign = signed16(r16[di] + 0x1ffe) < 0;
        r16[di] += 0x1ffe;
        if (!flags.sign) {
            pc = 0x24A9B;
            break;
        }
        r16[di] -= 0x7f60;
    case 0x24A9B:
        if (--r16[cx]) {
            pc = 0x24A8D;
            break;
        }
        r16[ax] = pop();
        ds = r16[ax];
        es = r16[ax];
        yield* sub_24154();
        memory16set(ds*16+0x8F46, memory16get(ds*16+0x8F46) + 1);
        return;
    } while (1);
}
function* sub_24AAA() {
    r16[si] = 0xaf80;
    r16[di] = memory16get(ds*16+0x979E);
    r16[di] += 0x0018;
    r16[dx] = 0x0068;
    r16[cx] = 0x0036;
    yield* sub_247BF();
}
function* sub_24AFC() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+r16[si] + 28) < 0 /*CHECK*/) {
            pc = 0x24B08;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x24B18;
            break;
        }
    case 0x24B08:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32CA);
        yield* sub_23316();
        r16[si] = pop();
    case 0x24B18:
        if (memory16gets(ds*16+r16[si] + 28) >= 0 /*CHECK*/) {
            pc = 0x24B24;
            break;
        }
        if (memory16get(ds*16+r16[si] + 26) != 0x0030) {
            pc = 0x24B38;
            break;
        }
    case 0x24B24:
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] = r16[dx] + memory16get(ds*16+r16[si] + 26);
        r16[dx] -= 1;
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x32C4);
        yield* sub_23316();
        r16[si] = pop();
    case 0x24B38:
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+0x32BA, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        r16[ax] -= 1;
        if (_FIXME_)
            return;
        memory16set(ds*16+0x32BC, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 26);
        r16[ax] -= 1;
        r16[dx] = memory16get(ds*16+0x32BC);
        if (r16s[dx] <= signed16(0x00bf)) {
            pc = 0x24B66;
            break;
        }
        r16[dx] -= 0x00bf;
        r16[ax] -= r16[dx];
        if (_FIXME_)
            return;
        memory16set(ds*16+0x32BC, 0x00bf);
    case 0x24B66:
        memory16set(ds*16+0x32BE, r16[ax]);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = memory16get(ds*16+0x32BC);
        r16[di] <<= 1;
        r16[di] = memory16get(ds*16+r16[di] + 38718);
        r16[ax] = memory16get(ds*16+0x32BA);
        r16[ax] >>= 1;
        r16[di] += r16[ax];
        r16[cx] = 0x0006;
        yield* sub_24323();
        r16[ax] = ds;
        es = r16[ax];
        return;
    } while (1);
}
function* sub_24B90() {
    var cs = _seg002;
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupt = true;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[si]);
        push(r16[di]);
        push(ds);
        push(cs);
        ds = pop();
        r8[bh] = r8[bh] ^ r8[bh];
        r8[bl] = r8[ah];
        flags.carry = r8[ah] <= 0x10;
        r8[ah] -= 0x10;
        if (flags.carry) {
            pc = 0x24BA5;
            break;
        }
        pc = 0x24CC0;
        break;
    case 0x24BA5:
        r8[bl] <<= 1;
        switch (r16[bx])
        {
        case 0: yield* sub_24D57(); break;
        case 2: yield* sub_24EFC(); break;
        case 4: yield* sub_24CD5(); break;
        case 6: yield* sub_24D33(); break;
        case 8: yield* sub_24F05(); break;
            default:
            assert(0);
        }
    case 0x24BAB:
        ds = pop();
        r16[di] = pop();
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
        _STOP_("db 3 dup(0), 1, 5 dup(0), 90h, 4 dup(0), 4...");
        _STOP_("db 2, 0B9h, 2, 0E7h, 2, 0EAh, 2, 8Dh, 2, 0...");
        _STOP_("db 3, 0A9h, 2, 0E2h, 2, 0F3h, 2, 0A4h, 2, ...");
        _STOP_("db 10h, 99h, 79h, 90h, 5Dh, 88h, 0B6h, 80h...");
        _STOP_("db 72h, 3Bh, 6Ch, 28h, 66h, 6Ch, 60h, 3, 5...");
        _STOP_("db 15h, 51h, 88h, 4Ch, 3Ch, 48h, 2Fh, 44h,...");
        _STOP_("db 3Ch, 55h, 39h, 1Eh, 36h, 14h, 33h, 36h,...");
        _STOP_("db 0F4h, 2Ah, 8Bh, 28h, 44h, 26h, 1Eh, 24h...");
        _STOP_("db 20h, 5Fh, 1Eh, 0ABh, 1Ch, 0Fh, 1Bh, 8Ah...");
        _STOP_("db 0C1h, 16h, 7Ah, 15h, 45h, 14h, 22h, 13h...");
        _STOP_("db 11h, 17h, 10h, 30h, 0Fh, 55h, 0Eh, 87h,...");
        _STOP_("db 0Eh, 0Ch, 60h, 0Bh, 0BDh, 0Ah, 23h, 0Ah...");
        _STOP_("db 9, 86h, 8, 0Bh, 8, 98h, 7, 2Bh, 7, 0C4h...");
        _STOP_("db 7, 6, 0B0h, 5, 5Eh, 5, 11h, 5, 0C9h, 4,...");
        _STOP_("db 4, 6, 4, 0CCh, 3, 95h, 3, 62h, 3, 31h, ...");
        _STOP_("db 2, 0AFh, 2, 89h, 2, 64h, 2, 42h, 2, 21h...");
        _STOP_("db 1, 0CBh, 1, 0B1h, 1, 99h, 1, 82h, 1, 6C...");
        _STOP_("db 44h, 1, 32h, 1, 21h, 1, 30h dup(0)");
    case 0x24CC0:
        flags.carry = r8[bl] < 0x20;
        r8[bl] -= 0x20;
        if (flags.carry) {
            pc = 0x24CCC;
            break;
        }
        memory[ds*16+r16[bx] + 34] = r8[al];
        pc = 0x24BAB;
        break;
    case 0x24CCC:
        r8[bl] = r8[ah];
        r8[al] = memory[ds*16+r16[bx] + 34];
        pc = 0x24BAB;
        break;
        return;
    } while (1);
}
function* sub_24CD5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = 0x09;
        r16[ax] = r8[cl] * r8[al];
        r16[bx] = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        memory[ds*16+0x22] = r8[al];
        memory[ds*16+0x29] = r8[al];
        memory[ds*16+0x28] = r8[al];
        r16[cx] = 0x0018;
        r16[si] = 0x0100;
    case 0x24CEC:
        memory16set(ds*16+r16[si], r16[ax]);
        r16[si] += 0x0002;
        if (--r16[cx]) {
            pc = 0x24CEC;
            break;
        }
        r8[al] = memory[ds*16+r16[bx] + 1506];
        memory[ds*16+0x25] = r8[al];
        memory[ds*16+0x26] = r8[al];
        r8[al] = 0xff;
        memory[ds*16+0x27] = r8[al];
        r16[di] = 0x0100;
        push(r16[bx]);
        yield* sub_24D1C();
        r16[bx] = pop();
        r16[bx] += 0x0004;
        r16[di] = 0x0118;
        yield* sub_24D1C();
        memory[ds*16+0x22] -= 1;
        memory[ds*16+0x29] -= 1;
        return;
    } while (1);
}
function* sub_24D1C() {
    r16[ax] = memory16get(ds*16+r16[bx] + 1509);
    memory16set(ds*16+r16[di] + 4, r16[ax]);
    r16[bx] = memory16get(ds*16+r16[bx] + 1507);
    memory16set(ds*16+r16[di], r16[bx]);
    r16[bx] = memory16get(ds*16+r16[bx]);
    memory16set(ds*16+r16[di] + 2, r16[bx]);
    memory[ds*16+r16[di] + 6] = 0x01;
}
function* sub_24D33() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000f;
        r16[bx] = 0x0420;
        r16[ax] = r8[cl] * r8[al];
        r16[bx] += r16[ax];
        r16[si] = 0x0410;
        memory[ds*16+0x23] = r8[ch];
    case 0x24D44:
        r8[al] = memory[ds*16+r16[bx]];
        memory[ds*16+r16[si]] = r8[al];
        r16[bx] += 1;
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x24D44;
            break;
        }
        r16[ax] = memory16get(ds*16+0x41D);
        memory16set(ds*16+0x40D, r16[ax]);
        memory[ds*16+0x23] -= 1;
        return;
    } while (1);
}
function* sub_24D57() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0002;
        r8[bh] = r8[ch];
        r8[al] = memory[ds*16+0x24];
        flags.carry = (memory[ds*16+0x28] + r8[al]) >= 0x100;
        memory[ds*16+0x28] += r8[al];
        if (flags.carry) {
            pc = 0x24DA8;
            break;
        }
        if (memory[ds*16+0x22] == r8[bh]) {
            pc = 0x24DA8;
            break;
        }
        r8[al] = memory[ds*16+0x25];
        flags.carry = (memory[ds*16+0x27] + r8[al]) >= 0x100;
        memory[ds*16+0x27] += r8[al];
        if (!flags.carry) {
            pc = 0x24D80;
            break;
        }
        r16[di] = 0x0100;
        yield* sub_24E8B();
        r16[di] = 0x0118;
        yield* sub_24E8B();
    case 0x24D80:
        r16[di] = 0x0100;
        yield* sub_24F12();
        memory16set(ds*16+0x2E, r16[cx]);
        r16[di] = 0x0118;
        yield* sub_24F12();
        r16[ax] = 0x0002;
        if (memory[ds*16+0x10A] == r8[bh]) {
            pc = 0x24DA0;
            break;
        }
        memory[ds*16+0x10A] -= 1;
        r16[ax] = memory16get(ds*16+0x2E);
    case 0x24DA0:
        flags.carry = memory[ds*16+0x122] & 1;
        memory[ds*16+0x122] >>= 1;
        if (flags.carry) {
            pc = 0x24DA8;
            break;
        }
        r16[cx] = r16[ax];
    case 0x24DA8:
        if (memory[ds*16+0x23] == r8[bh]) {
            pc = 0x24E00;
            break;
        }
        if (memory[ds*16+0x41C] == r8[bh]) {
            pc = 0x24DC0;
            break;
        }
        memory[ds*16+0x41C] -= 1;
        if (memory[ds*16+0x41C] != 0) {
            pc = 0x24DC0;
            break;
        }
        memory[ds*16+0x23] = r8[bh];
        pc = 0x24E00;
        break;
    case 0x24DC0:
        r16[ax] = memory16get(ds*16+0x41D);
        memory[ds*16+0x40E] -= 1;
        if (memory[ds*16+0x40E] != 0) {
            pc = 0x24DDF;
            break;
        }
        memory[ds*16+0x40E] = r8[ah];
        _ror(memory[ds*16+0x41A], 1);
        flags.carry = !!(memory[ds*16+0x41A] & 0x80);
        r16[dx] = memory16get(ds*16+0x416);
        if (flags.carry) {
            pc = 0x24DDB;
            break;
        }
        r16[dx] = memory16get(ds*16+0x418);
    case 0x24DDB:
        memory16set(ds*16+0x412, memory16get(ds*16+0x412) + r16[dx]);
    case 0x24DDF:
        r16[dx] = memory16get(ds*16+0x412);
        r16[dx] = r16[dx] + memory16get(ds*16+0x410);
        memory[ds*16+0x40D] -= 1;
        if (memory[ds*16+0x40D] != 0) {
            pc = 0x24DF4;
            break;
        }
        memory[ds*16+0x40D] = r8[al];
        r16[dx] = memory16get(ds*16+0x414);
    case 0x24DF4:
        memory16set(ds*16+0x412, r16[dx]);
        _ror(memory[ds*16+0x41B], 1);
        flags.carry = !!(memory[ds*16+0x41B] & 0x80);
        if (flags.carry) {
            pc = 0x24E00;
            break;
        }
        r16[cx] = r16[dx];
    case 0x24E00:
        if (memory16get(ds*16+0x2C) == r16[cx]) {
            pc = 0x24E16;
            break;
        }
        r8[al] = 0xb6;
        out8(67, r8[al]);
        r8[al] = r8[cl];
        out8(66, r8[al]);
        r8[al] = r8[ch];
        out8(66, r8[al]);
        memory16set(ds*16+0x2C, r16[cx]);
    case 0x24E16:
        r8[al] = in8(97);
        r8[al] |= 0x03;
        out8(97, r8[al]);
        return;
    } while (1);
}
function* loc_24E2D() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = memory16get(ds*16+r16[bx] + r16[si]);
        memory[ds*16+r16[di] + 19] = r8[bl];
        _STOP_("goto loc_24E99");
        r8[dl] |= 0x04;
        _STOP_("goto loc_24E99");
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+r16[di] + 23] = r8[al];
        _STOP_("goto loc_24E99");
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+0x2A] = r8[al];
        _STOP_("goto loc_24E99");
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[si] += 0x0002;
        memory16set(ds*16+r16[di] + 20, r16[ax]);
        r8[dl] |= 0x08;
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+r16[di] + 14] = r8[al];
        _STOP_("goto loc_24E99");
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+r16[di] + 16] = r8[al];
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+r16[di] + 17] = r8[al];
        r8[al] <<= 1;
        memory[ds*16+r16[di] + 15] = r8[al];
        r8[dl] |= 0x10;
        _STOP_("goto loc_24E99");
        r8[dl] |= 0x02;
        _STOP_("goto loc_24E99");
        r8[dl] |= 0x80;
        r8[dl] |= 0x40;
        _STOP_("goto loc_24E99");
        r8[dl] = r8[bh];
        _STOP_("goto loc_24E99");
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        memory[ds*16+r16[di] + 8] = r8[al];
        _STOP_("goto loc_24E99");
        return;
    } while (1);
}
function* sub_24E8B() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = memory[ds*16+r16[di] + 18];
        memory[ds*16+r16[di] + 6] -= 1;
        if (memory[ds*16+r16[di] + 6] != 0) {
            pc = 0x24EBF;
            break;
        }
        r8[dl] &= 0x30;
        r16[si] = memory16get(ds*16+r16[di] + 2);
    case 0x24E99:
        r8[al] = memory[ds*16+r16[si]];
        r16[si] += 1;
        if (r8[al] < 0xa0) {
            pc = 0x24EB5;
            break;
        }
        flags.carry = (r8[al] + 0x20) >= 0x100;
        r8[al] += 0x20;
        if (flags.carry) {
            pc = 0x24EAF;
            break;
        }
        r8[bl] = r8[al];
        r8[al] = memory[ds*16+r16[bx] + 1254];
        memory[ds*16+r16[di] + 9] = r8[al];
        pc = 0x24E99;
        break;
    case 0x24EAF:
        r16[ax] += 1;
        memory[ds*16+r16[di] + 7] = r8[al];
        pc = 0x24E99;
        break;
    case 0x24EB5:
        r8[bl] = r8[al];
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        if (!flags.carry) {
            pc = 0x24ED6;
            break;
        }
        _STOP_("goto word ptr [bx+30h]");
    case 0x24EBF:
        if (!(r8[dl] & 0x40))
            return;
        if (!(r8[dl] & 0x80)) {
            pc = 0x24ECD;
            break;
        }
        memory[ds*16+r16[di] + 22] -= 1;
        return;
    case 0x24ECD:
        memory[ds*16+r16[di] + 22] += 1;
        return;
        memory[ds*16+r16[di] + 10] = r8[bh];
        pc = 0x24EEC;
        break;
    case 0x24ED6:
        memory16set(ds*16+r16[di] + 12, 0x0000);
        memory[ds*16+r16[di] + 18] = r8[dl];
        memory[ds*16+r16[di] + 22] = r8[al];
        if (r8[dl] & 0x04) {
            pc = 0x24EEC;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[di] + 8);
        memory16set(ds*16+r16[di] + 10, r16[ax]);
    case 0x24EEC:
        r8[al] = memory[ds*16+r16[di] + 7];
        memory[ds*16+r16[di] + 6] = r8[al];
        memory16set(ds*16+r16[di] + 2, r16[si]);
        return;
    } while (1);
}
function* sub_24EFC() {
    r8[al] = r8[al] ^ r8[al];
    memory[ds*16+0x23] = r8[al];
    memory[ds*16+0x22] = r8[al];
}
function* sub_24F05() {
    if (memory[ds*16+0x29] == 0x00)
        return;
    memory[ds*16+0x22] = 0xff;
    return;
}
function* sub_24F12() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16+r16[di] + 11];
        r8[bl] += 1;
        r8[al] = memory[ds*16+r16[bx] + 1460];
        flags.sign = !!(r8[al] & 0x80);
        r8[al] |= r8[al];
        if (!flags.sign) {
            pc = 0x24F28;
            break;
        }
        r8[al] += 1;
        if (r8[al] == 0) {
            pc = 0x24F2B;
            break;
        }
        r8[al] += 0x7f;
        r8[bl] = memory[ds*16+r16[di] + 9];
    case 0x24F28:
        memory[ds*16+r16[di] + 11] = r8[bl];
    case 0x24F2B:
        r8[al] = r8[al] + memory[ds*16+r16[di] + 22];
        r8[al] = r8[al] + memory[ds*16+0x2A];
        r8[al] = r8[al] + memory[ds*16+r16[di] + 23];
        r8[al] <<= 1;
        r8[bl] = r8[al];
        r16[cx] = memory16get(ds*16+r16[bx] + 84);
        r8[bl] = memory[ds*16+r16[di] + 18];
        r8[bl] = r8[bl] ^ 0x01;
        if (!(r8[bl] & 0x10)) {
            pc = 0x24F77;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
        r8[al] = r8[al] | memory[ds*16+r16[di] + 16];
        if (r8[al] != 0) {
            pc = 0x24F52;
            break;
        }
        r16[ax] += 1;
        r8[al] &= r8[bl];
    case 0x24F52:
        r8[ah] = memory[ds*16+r16[di] + 17];
        r8[dl] = memory[ds*16+r16[di] + 15];
        if (r8[bl] & 0x20) {
            pc = 0x24F61;
            break;
        }
        r8[ah] -= r8[al];
        pc = 0x24F65;
        break;
    case 0x24F61:
        r8[ah] += r8[al];
    case 0x24F65:
        if (r8[ah] != r8[dl]) {
            pc = 0x24F6A;
            break;
        }
        r8[bl] = r8[bl] ^ 0x20;
    case 0x24F6A:
        memory[ds*16+r16[di] + 17] = r8[ah];
        r8[dl] >>= 1;
        r8[ah] -= r8[dl];
        r8[al] = r8[ah];
        _FIXME_;
        r16[cx] += r16[ax];
    case 0x24F77:
        if (!(r8[bl] & 0x08)) {
            pc = 0x24F8F;
            break;
        }
        memory[ds*16+r16[di] + 14] -= 1;
        if (memory[ds*16+r16[di] + 14] != 0) {
            pc = 0x24F8F;
            break;
        }
        memory[ds*16+r16[di] + 14] += 1;
        r16[ax] = memory16get(ds*16+r16[di] + 20);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 12);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[cx] += r16[ax];
    case 0x24F8F:
        memory[ds*16+r16[di] + 18] = r8[bl];
        r8[bl] = (~r8[bl]);
        r8[bl] &= 0x03;
        if (r8[bl] != 0)
            return;
        r16[cx] = 0x0002;
        return;
    } while (1);
}
function* sub_121E9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[di] = memory16get(ds*16+r16[si] + 28);
        if (memory16get(ds*16+r16[di]) != 0x0034) {
            pc = 0x12216;
            break;
        }
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 48);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[di] + 50);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        if (memory16get(ds*16+0x991E) == 0x0000) {
            pc = 0x12210;
            break;
        }
    {yield* loc_147A9(); return; };
    case 0x12210:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        return;
    case 0x12216:
        yield* sub_107C0();
        return;
    } while (1);
}
function* sub_1246D() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_141B1();
        r16[ax] = memory16get(ds*16+0x9F12);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 48);
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+0x9F16);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 50);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        if (memory16get(ds*16+0x991E) == 0x0000) {
            pc = 0x1248C;
            break;
        }
    {yield* loc_147A9(); return; };
    case 0x1248C:
        memory16set(ds*16+r16[si] + 4, 0x0853);
        if (memory16get(ds*16+r16[si] + 12) == 0x8786) {
            pc = 0x124C4;
            break;
        }
        if (memory[ds*16+0x8FAE] == 0x00)
            return;
        if (memory16get(ds*16+r16[si] + 12) != 0x8626)
            return;
        memory16set(ds*16+0x8E88, 0x0015);
        r16[di] = 0x12ca;
        r16[ax] = memory16get(cs*16+r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+r16[di] + 2);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[di] += 0x0004;
        memory16set(ds*16+r16[si] + 16, r16[di]);
        return;
    case 0x124C4:
        push(r16[si]);
        yield* sub_11022();
        r16[di] = 0x9096;
        yield* sub_1077C();
        r16[di] = r16[si];
        r16[si] = pop();
        bp = 0x132c;
        memory16set(ds*16+r16[di], 0x0030);
        memory16set(ds*16+r16[di] + 4, 0x0853);
        memory16set(ds*16+r16[di] + 2, 0x28b8);
        r16[ax] = memory16get(cs*16+bp);
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        r16[ax] = memory16get(cs*16+bp + 2);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        bp += 0x0004;
        memory16set(ds*16+r16[di] + 16, bp);
        r16[ax] = memory16get(ds*16+r16[si] + 18);
        memory16set(ds*16+r16[di] + 18, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[ax] -= 0x000b;
        memory16set(ds*16+r16[di] + 22, r16[ax]);
        memory16set(ds*16+r16[di] + 26, 0x0000);
        return;
    } while (1);
}
function* sub_128B8() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+0x9224] == 0x00) {
            pc = 0x128C2;
            break;
        }
        _STOP_("goto loc_13A2F");
    case 0x128C2:
        yield* sub_141B1();
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) - 0x000a);
        if (memory16gets(ds*16+r16[si] + 22) >= 0) {
            pc = 0x128CF;
            break;
        }
        yield* sub_107C0();
        return;
    case 0x128CF:
        yield* sub_13589();
        yield* sub_11BEA();
        if (flags.zero)
            return;
        r16[ax] = memory16get(cs*16+0x3DA4);
    {yield* sub_13A36(); return; };
        return;
    } while (1);
}
function* sub_14F96() {
    memory16set(ds*16+0x9162, 0x00aa);
}
function* sub_19F4E() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_10EF5();
        r16[si] = pop();
        bp = 0x1230;
        r16[dx] = 0x0853;
        yield* sub_13326();
        memory16set(ds*16+0x920E, memory16get(ds*16+0x920E) - 1);
        if (memory16get(ds*16+0x920E) == 0) {
            pc = 0x19F65;
            break;
        }
        return;
    case 0x19F65:
        r16[bx] = memory16get(ds*16+r16[di] + 68);
        memory16set(ds*16+r16[bx] + 36, 0x0000);
        r16[ax] = 0x0001;
        yield* sub_13A39();
        r16[cx] = 0x0004;
        yield* sub_115E4();
        memory[ds*16+0x9225] = 0x00;
        return;
    } while (1);
}
function* sub_12AA4() {
    if (memory16gets(ds*16+0x9132) >= signed16(0x0004))
        return;
    memory16set(ds*16+0x9132, memory16get(ds*16+0x9132) + 1);
    return;
}
function* sub_180CA() {
    r16[bx] <<= 1;
    switch (r16[bx])
    {
    case 0: yield* loc_13360(); return;
    case 2:     r16[bx] = 0x7736;
    {yield* sub_13389(); return; };
    case 4:     r16[bx] = 0x7748;
    {yield* sub_13389(); return; };
    case 6:     r16[bx] = 0x775a;
    {yield* sub_13389(); return; };
    case 8:     r16[bx] = 0x776c;
    {yield* sub_13389(); return; };
    case 10:     r16[bx] = 0x777e;
    {yield* sub_13389(); return; };
    case 12:     r16[bx] = 0x7790;
    {yield* sub_13389(); return; };
        default:
        assert(0);
    }
}
function* sub_1866D() {
    var cs = _seg000;
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+r16[si] + 26) != 0x8000) {
            pc = 0x186AE;
            break;
        }
        yield* sub_141B1();
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r8[al] = memory[cs*16+r16[bx] + 24854];
        _cbw();
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 22);
        if (r16[ax] >= 0x00c0) {
            pc = 0x186AA;
            break;
        }
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        r8[al] = memory[cs*16+r16[bx] + 24918];
        _cbw();
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 18);
        if (r16[ax] >= 0x0140) {
            pc = 0x186AA;
            break;
        }
        memory16set(ds*16+r16[si] + 18, r16[ax]);
        memory16set(ds*16+r16[si] + 4, 0x0853);
        return;
    case 0x186AA:
        yield* sub_107C0();
        return;
    case 0x186AE:
        r16[ax] = memory16get(ds*16+0x9198);
        memory16set(ds*16+r16[si] + 22, memory16get(ds*16+r16[si] + 22) + r16[ax]);
        r16[bx] = memory16get(ds*16+r16[si] + 34);
        memory[ds*16+r16[bx] + -28115 + 65536] = 0xff;
        yield* loc_1480E();
        if (memory16get(ds*16+r16[si]) != 0x0004) {
            pc = 0x186D7;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 32);
        r16[bx] <<= 1;
        if (memory16get(ds*16+r16[bx] + -28206+ 65536) != 0x0000)
            return;
        memory16set(ds*16+r16[bx] + -28206+ 65536, 0x0018);
        return;
    case 0x186D7:
        if (memory16get(ds*16+r16[si] + 4) == 0x0761) {
            pc = 0x1870B;
            break;
        }
        if (memory16get(ds*16+r16[si] + 4) == 0x0897) {
            pc = 0x186F4;
            break;
        }
        r16[di] = memory16get(ds*16+r16[si] + 58);
        if (memory16get(ds*16+r16[di]) != 0x0000) {
            pc = 0x18716;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0897);
        pc = 0x18716;
        break;
    case 0x186F4:
        r16[di] = memory16get(ds*16+r16[si] + 58);
        if (memory16get(ds*16+r16[di]) == 0x0000) {
            pc = 0x18716;
            break;
        }
        r16[di] -= 0x000a;
        if (r16[di] == memory16get(ds*16+r16[si] + 56)) {
            pc = 0x18716;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0853);
        pc = 0x18716;
        break;
    case 0x1870B:
        if (memory16gets(ds*16+r16[si] + 26) < 0 /*CHECK*/) {
            pc = 0x18716;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0897);
    case 0x18716:
        r16[bx] = memory16get(ds*16+r16[si] + 28);
        r16[bx] += 0x0010;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] &= 0x000e;
        r16[di] = 0x952b;
        if (memory16get(ds*16+r16[si]) != 0x0118) {
            pc = 0x18733;
            break;
        }
        r16[di] = 0x953b;
    case 0x18733:
        if (memory16get(ds*16+r16[si]) != 0x011c) {
            pc = 0x1873C;
            break;
        }
        r16[di] = 0x954b;
    case 0x1873C:
        r16[ax] = memory16get(cs*16+r16[bx] + r16[di]);
        memory16set(ds*16+r16[si] + 12, r16[ax]);
    {yield* sub_13589(); return; };
        return;
    } while (1);
}
function* sub_18114() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x08b9);
        if (r16s[ax] >= memory16gets(ds*16+r16[di] + 36)) {
            pc = 0x18121;
            break;
        }
    {yield* sub_13AA7(); return; };
    case 0x18121:
        r16[bx] = 0x7892;
        yield* loc_18136();
        return;
    } while (1);
}
function* loc_18136() {
    var cs = _seg000;
    push(r16[si]);
    yield* sub_11022();
    push(r16[di]);
    r16[di] = 0x9096;
    yield* sub_1077C();
    r16[di] = pop();
    r16[ax] = memory16get(ds*16+r16[di]);
    memory16set(ds*16+r16[si], r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 2);
    memory16set(ds*16+r16[si] + 2, r16[ax]);
    memory16set(ds*16+r16[si] + 4, 0x0853);
    r16[ax] = memory16get(ds*16+r16[di] + 18);
    memory16set(ds*16+r16[si] + 18, r16[ax]);
    r16[ax] = memory16get(ds*16+r16[di] + 22);
    memory16set(ds*16+r16[si] + 22, r16[ax]);
    r16[ax] = memory16get(cs*16+r16[bx]);
    memory16set(ds*16+r16[si] + 12, r16[ax]);
    r16[ax] = memory16get(cs*16+r16[bx] + 2);
    memory16set(ds*16+r16[si] + 14, r16[ax]);
    r16[bx] += 0x0004;
    memory16set(ds*16+r16[si] + 16, r16[bx]);
    memory16set(ds*16+r16[si] + 26, 0x8000);
    yield* sub_14191();
    memory16set(ds*16+r16[si] + 28, 0x0000);
    memory16set(ds*16+r16[si] + 30, 0x0000);
    memory[ds*16+r16[si] + 28] = r8[al];
    r16[si] = r16[di];
    yield* sub_107C0();
    r16[si] = pop();
}
function* sub_18126() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x08b9);
        if (r16s[ax] >= memory16gets(ds*16+r16[di] + 36)) {
            pc = 0x18133;
            break;
        }
    {yield* sub_13AA7(); return; };
    case 0x18133:
        r16[bx] = 0x78b8;
        yield* loc_18136();
        return;
    } while (1);
}
function* sub_180F5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+r16[di] + 4, 0x08b9);
        if (r16s[ax] >= memory16gets(ds*16+r16[di] + 36)) {
            pc = 0x18102;
            break;
        }
    {yield* sub_13AA7(); return; };
    case 0x18102:
        r16[cx] = memory16get(ds*16+r16[di] + 34);
        r8[al] = 0x01;
        r8[al] <<= r8[cl];
        r8[al] = (~r8[al]);
        memory[ds*16+0x9202] &= r8[al];
        r16[bx] = 0x786c;
        yield* loc_18136();
        return;
    } while (1);
}
function* sub_187D5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+0x9202) != 0x0003) {
            pc = 0x187DF;
            break;
        }
        return;
    case 0x187DF:
        memory16set(ds*16+r16[di] + 4, 0x8783);
        flags.carry2 = memory16get(ds*16+r16[di] + 36) <= r16[ax];
        memory16set(ds*16+r16[di] + 36, memory16get(ds*16+r16[di] + 36) - r16[ax]);
        if (flags.carry2) {
            pc = 0x187EC;
            break;
        }
        return;
    case 0x187EC:
        memory16set(ds*16+0x9202, 0x0003);
        r16[bx] = memory16get(ds*16+r16[di] + 12);
        memory16set(ds*16+r16[bx], 0x62c1);
        r16[dx] = 0x0853;
        r16[ax] = memory16get(ds*16+r16[di] + 40);
        r16[ax] += 0x0008;
        r16[bx] = memory16get(ds*16+r16[di] + 42);
        r16[bx] += 0x0008;
        bp = 0x1230;
        yield* sub_13326();
        push(r16[si]);
        r16[si] = r16[di];
        yield* sub_107C0();
        r16[si] = pop();
        memory16set(ds*16+0x9200, memory16get(ds*16+0x9200) - 1);
        if (memory16get(ds*16+0x9200) != 0x0001) {
            pc = 0x18832;
            break;
        }
        memory16set(ds*16+0x918C, 0xffff);
        memory16set(ds*16+0x91F4, 0xd251);
        memory16set(ds*16+0x91F6, 0x894d);
    case 0x18832:
        if (memory16get(ds*16+0x9200) != 0x0000)
            return;
        memory16set(ds*16+0x918C, 0x0001);
        push(r16[di]);
        r16[di] = 0x0000;
        r16[di] += 0x1950;
        r16[cx] = 0x01cc;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        push(r16[si]);
        r16[si] = memory16get(ds*16+0x9054);
    case 0x18853:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (!(r16[ax] & r16[ax])) {
            pc = 0x1886C;
            break;
        }
        push(r16[ax]);
        yield* sub_11689();
        r16[ax] = pop();
        push(r16[di]);
        if (r16[ax] == 0x0050) {
            pc = 0x18869;
            break;
        }
        r16[di] = r16[si];
        yield* sub_13A33();
    case 0x18869:
        r16[si] = pop();
        pc = 0x18853;
        break;
    case 0x1886C:
        memory[ds*16+0x922D] = 0x00;
        memory[ds*16+0x922E] = 0x00;
        r16[di] = 0x8e8c;
        r16[cx] = 0x0010;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        r16[cx] = 0x0027;
        r16[ax] = 0x0000;
        r16[bx] = 0x0000;
        r16[dx] = 0x0140;
        r16[di] = 0x00c0;
        bp = 0x124c;
        yield* sub_11588();
        r16[cx] = 0x0004;
        yield* sub_115E4();
        r16[si] = pop();
        r16[di] = pop();
        memory16set(ds*16+0x91A8, 0x0000);
        memory[ds*16+0x9230] = 0xff;
        return;
    } while (1);
}
function* sub_18783() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        memory16set(ds*16+r16[si] + 4, 0x0761);
        r16[di] = 0x92bf;
        r16[ax] = 0x0003;
        r16[bx] = 0x0002;
        r16[cx] = memory16get(ds*16+r16[si] + 18);
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] -= 0x0010;
        r16[dx] = memory16get(ds*16+r16[si] + 22);
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] = r16[dx] - memory16get(ds*16+0x9190);
        r16[dx] -= 0x0010;
        if (memory16get(ds*16+r16[si] + 34) == 0x0000) {
            pc = 0x187CE;
            break;
        }
        r16[cx] += 0x0010;
        r16[di] = 0x92b3;
        if (memory16get(ds*16+r16[si] + 34) == 0x0001) {
            pc = 0x187CE;
            break;
        }
        r16[di] = 0x92cb;
        r16[bx] = 0x0003;
        r16[dx] -= 0x0010;
        r16[cx] -= 0x0008;
    case 0x187CE:
        r16[si] = r16[di];
        yield* sub_10963();
        r16[si] = pop();
        return;
    } while (1);
}