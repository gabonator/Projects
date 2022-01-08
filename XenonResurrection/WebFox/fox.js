function* entry() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupt = true;
        flags.direction = false;
        r16[dx] = 0xffff;
        r16[si] = 0x0080;
        lodsb_data_forward();
        _cbw();
        r16[cx] = r16[ax];
        if (r16[cx] == 0) {
            pc = 0x004f;
            break;
        }
    case 0x0013:
        lodsb_data_forward();
        if (r8[al] == 0x2f) {
            pc = 0x001c;
            break;
        }
        if (--r16[cx]) {
            pc = 0x0013;
            break;
        }
        pc = 0x004f;
        break;
    case 0x001c:
        lodsb_data_forward();
        r8[al] &= 0xdf;
        if (r8[al] != 0x56) {
            pc = 0x0025;
            break;
        }
        r8[dl] = 0x05;
    case 0x0025:
        if (r8[al] != 0x45) {
            pc = 0x002b;
            break;
        }
        r8[dl] = 0x03;
    case 0x002b:
        if (r8[al] != 0x54) {
            pc = 0x0031;
            break;
        }
        r8[dl] = 0x02;
    case 0x0031:
        if (r8[al] != 0x43) {
            pc = 0x0037;
            break;
        }
        r8[dl] = 0x01;
    case 0x0037:
        if (r8[al] != 0x48) {
            pc = 0x003d;
            break;
        }
        r8[dl] = 0x00;
    case 0x003d:
        if (r8[al] != 0x42) {
            pc = 0x0043;
            break;
        }
        r8[dh] = 0x00;
    case 0x0043:
        if (r8[al] != 0x46) {
            pc = 0x004d;
            break;
        }
        memory[cs*16+0x3] = 0x00;
    case 0x004d:
        if (--r16[cx]) {
            pc = 0x0013;
            break;
        }
    case 0x004f:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[cs*16+0x1] = r8[dl];
        memory[cs*16+0x2] = r8[dh];
        r16[ax] = 0x8f01;
        r8[cl] = 0x04;
        r16[ax] >>= r8[cl];
        r16[ax] += 0x1690;
        memory16set(ds*16+0x04c1, r16[ax]);
        push(ds);
        r16[ax] = r16[ax] ^ r16[ax];
        ds = r16[ax];
        bios16set(ds, 144, 0x08d0);
        bios16set(ds, 146, cs);
        ds = pop();
        yield* sub_17fe();
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_107d();
        yield* sub_0ceb();
        yield* sub_0701();
        yield* sub_307d();
        yield* sub_3160();
        r16[dx] = 0x0000;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x000e, r16[ax]);
        scene = "greeting";
        yield* sub_183f();
        yield* sub_1198();
        r16[ax] = 0x4000;
        out8(64, r8[al]);
        r8[al] = r8[ah];
        out8(64, r8[al]);
        scene = "titus";
        yield* sub_53a2();
        scene = "logo";
        yield* sub_52ec();
        yield* sub_24c9();
        r16[ax] = memory16get(ds*16+0x04c1);
        memory16set(ds*16+0x000c, r16[ax]);
    case 0x00c5:
        r16[dx] = memory16get(ds*16+12);
        memory16set(ds*16+1217, r16[dx]);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x00e9;
            break;
        }
        scene = "menu";
        yield* sub_51c6();
        yield* sub_3160();
        memory[ds*16+1051] = 0x02;
        memory[ds*16+1049] = 0x10;
        memory[ds*16+1050] = 0x00;
        scene = "info";
        yield* sub_0173();
        scene = "game";
    case 0x00e9:
        yield* sub_3160();
        r8[al] = memory[ds*16+0x5250];
        _setLevel(r8[al]);
        yield* sub_2eb7();
        _processMap();
        yield* sub_378d();
        yield* sub_56cc();
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[bl] = memory[ds*16+21072];
        r8[bh] = r8[bh] ^ r8[bh];
        r8[al] = memory[ds*16+r16[bx] + 20620];
        _cbw();
        yield* sub_10ff();
        yield* sub_3ee8();
        yield* sub_2d62();
        yield* sub_2c87();
        yield* sub_3271();
    case 0x0117:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory16set(ds*16+25854, memory16get(ds*16+25854) + 1);
        yield* sub_3e28();
        yield* sub_39c7();
        yield* sub_414b();
        yield* sub_5945();
        yield* sub_58c8();
        yield* sub_5737();
        yield* sub_38b5();
        yield* sub_37f5();
        yield* sub_3f46();
        yield* sub_2ba2();
        yield* sub_2c87();
        yield* sub_1c61();
        yield* sub_3627();
        if (!flags.carry) {
            pc = 0x014c;
            break;
        }
        pc = 0x00c5;
        break;
    case 0x014c:
        yield* sub_05b7();
        yield* sub_0158();
        yield* sub_3271();
        pc = 0x0117;
        break;
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_0158() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[cs*16+0x16E4] != 0x03) {
            pc = 0x0172;
            break;
        }
        if (memory[ds*16+2482] != 0x00) {
            pc = 0x0172;
            break;
        }
        r16[ax] = memory16get(ds*16+0x0913);
        yield* sub_10ff();
    case 0x0172:
        return;
    } while (1);
}
function* sub_0173() {
    var oldScene = scene;
    scene = "info";

    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = 0x0000;
        yield* sub_10ff();
        yield* sub_2811();
        yield* sub_01f8();
        if (memory[ds*16+1050] < 0x0a) {
            pc = 0x01c6;
            break;
        }
        yield* sub_03f2();
    case 0x0197:
        if (memory[ds*16+1050] < 0x0a) {
            pc = 0x01c6;
            break;
        }
        r16[dx] = 0x000a;
    case 0x01a1:
        memory[ds*16+1050] -= 1;
        push(r16[dx]);
        yield* sub_0244();
        r16[dx] = pop();
        r16[cx] = 0x000f;
    case 0x01ad:
        yield* sub_3243();
        if (--r16[cx]) {
            pc = 0x01ad;
            break;
        }
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x01a1;
            break;
        }
        memory[ds*16+1051] += 1;
        yield* sub_0244();
        r16[cx] = 0x000a;
    case 0x01bf:
        yield* sub_3243();
        if (--r16[cx]) {
            pc = 0x01bf;
            break;
        }
        pc = 0x0197;
        break;
    case 0x01c6:
        yield* sub_0244();
        yield* sub_03f2();
        yield* sub_03ae();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();

        scene = oldScene;
        return;
    } while (1);
}
function* sub_01d9() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(bp);
    yield* sub_2811();
    yield* sub_01f8();
    yield* sub_03f2();
    yield* sub_03ae();
    bp = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_01f8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_038a();
        memory16set(ds*16+501, 0x000d);
        memory16set(ds*16+503, 0x0960);
        yield* sub_03dc();
        r8[cl] = memory[ds*16+21072];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[si] = 0x5104;
        if (r16[cx] == 0) {
            pc = 0x0223;
            break;
        }
    case 0x021a:
        lodsb_data_forward();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x021a;
            break;
        }
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x021a;
            break;
        }
        r16[si] -= 1;
    case 0x0223:
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x0225:
        r16[bx] += 1;
        if (memory[ds*16+r16[bx] + r16[si]] != 0x00) {
            pc = 0x0225;
            break;
        }
        r16[bx] -= 1;
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r8[bl] = r8[bl] + 0x01 + flags.carry;
        memory16set(ds*16+501, 0x0014);
        memory16set(ds*16+503, 0x0be0);
        memory16set(ds*16+501, memory16get(ds*16+501) - r16[bx]);
        yield* sub_0488();
        yield* sub_0244();
        return;
    } while (1);
}
function* sub_0244() {
    memory16set(ds*16+501, 0x000a);
    memory16set(ds*16+503, 0x12c0);
    r16[si] = 0x0010;
    yield* sub_0488();
    r8[dl] = memory[ds*16+1050];
    r8[dh] = r8[dh] ^ r8[dh];
    yield* sub_0423();
    memory16set(ds*16+501, 0x000a);
    memory16set(ds*16+503, 0x14a0);
    r16[si] = 0x001e;
    yield* sub_0488();
    r8[dl] = memory[ds*16+1051];
    r8[dh] = r8[dh] ^ r8[dh];
    yield* sub_0423();
}
function* sub_027b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(bp);
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_3160();
        yield* sub_038a();
        memory16set(ds*16+501, 0x000e);
        memory16set(ds*16+503, 0x0c80);
        r16[si] = 0x002c;
        yield* sub_0488();
        memory16set(ds*16+501, memory16get(ds*16+501) - 0x0004);
        r16[dx] = r16[dx] ^ r16[dx];
        r16[cx] = 0x0004;
    case 0x02aa:
        memory[ds*16+1216] = 0x00;
    case 0x02af:
        yield* _sync();
        r8[bl] = memory[ds*16+1216];
        if (r8[bl] & 0x80) {
            pc = 0x02aa;
            break;
        }
        r8[bh] = r8[bh] ^ r8[bh];
        r8[al] = memory[ds*16+r16[bx] + 373];
        if (r8[al] == 0x2d) {
            pc = 0x02af;
            break;
        }
        r8[ah] = r8[al];
        r8[ah] -= 0x30;
        if (r8[ah] <= 0x09) {
            pc = 0x02cf;
            break;
        }
        r8[ah] -= 0x07;
    case 0x02cf:
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r8[dl] |= r8[ah];
        yield* sub_050e();
        if (--r16[cx]) {
            pc = 0x02aa;
            break;
        }
        memory16set(ds*16+501, 0x000b);
        memory16set(ds*16+503, 0x1040);
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x02ec:
        r16[ax] = r16[cx];
        yield* sub_6582();
        if (r16[ax] == r16[dx]) {
            pc = 0x0307;
            break;
        }
        r16[cx] += 1;
        if (r16[cx] <= 0x0014) {
            pc = 0x02ec;
            break;
        }
    case 0x02fb:
        r16[si] = 0x0037;
        yield* sub_0488();
        yield* sub_03f2();
        flags.carry = true;
        pc = 0x032a;
        break;
    case 0x0307:
        r16[si] = 0x0048;
        yield* sub_0488();
        r16[bx] = r16[cx];
        r8[dl] = memory[ds*16+r16[bx] + 21052];
        r8[dh] = r8[dh] ^ r8[dh];
        if (r8[dl] != 0xff) {
            pc = 0x0321;
            break;
        }
        memory16set(ds*16+501, memory16get(ds*16+501) - 0x0009);
        pc = 0x02fb;
        break;
    case 0x0321:
        push(r16[bx]);
        yield* sub_0423();
        yield* sub_03f2();
        r16[ax] = pop();
        flags.carry = false;
    case 0x032a:
        es = pop();
        ds = pop();
        bp = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_0333() {
    var oldscene = scene;
    scene = "info";

    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(bp);
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_2811();
    yield* sub_038a();
    memory16set(ds*16+501, 0x000d);
    memory16set(ds*16+503, 0x1040);
    yield* sub_03dc();
    memory16set(ds*16+501, 0x000e);
    memory16set(ds*16+503, 0x0c80);
    r16[si] = 0x0052;
    yield* sub_0488();
    r8[al] = memory[ds*16+0x5250];
    _cbw();
    yield* sub_6582();
    r16[dx] = r16[ax];
    yield* sub_0465();
    yield* sub_03f2();
    yield* sub_3243();
    yield* sub_03ae();
    yield* sub_276f();
    bp = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    scene = oldscene;
}
function* sub_038a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x039e;
            break;
        }
        if (r8[al] >= 0x03) {
            pc = 0x03a5;
            break;
        }
        return;
    case 0x039e:
        r16[dx] = 0x04c4;
        yield* sub_0410();
        return;
    case 0x03a5:
        r16[dx] = 0x04f4;
        r16[ax] = 0x1002;
        interrupt(16);
        return;
    } while (1);
}
function* sub_03ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        yield* sub_27df();
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x03c5;
            break;
        }
        if (r8[al] >= 0x03) {
            pc = 0x03d3;
            break;
        }
        return;
    case 0x03c5:
        r16[ax] = 0x1012;
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0010;
        r16[dx] = 0x5057;
        interrupt(16);
        return;
    case 0x03d3:
        r16[dx] = 0x5035;
        r16[ax] = 0x1002;
        interrupt(16);
        return;
    } while (1);
}
function* sub_03dc() {
    r16[si] = 0x0059;
    yield* sub_0488();
    r8[bl] = memory[ds*16+21072];
    r8[bh] = r8[bh] ^ r8[bh];
    r8[dl] = memory[ds*16+r16[bx] + 21052];
    r8[dh] = r8[dh] ^ r8[dh];
    yield* sub_0423();
}
function* sub_03f2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
    case 0x03f7:
        yield* sub_0805();
        r8[al] = memory[ds*16+0x47e];
        r8[al] = r8[al] | memory[ds*16+1067];
        {
            yield* _sync();
            // std::cout << "Ignore keyboard\n";
            //r8[al] = 1;
        }
        if (r8[al] == 0) {
            pc = 0x03f7;
            break;
        }
    case 0x0403:
        yield* _sync();
        yield* sub_0805();
        r8[al] = memory[ds*16+0x42b];
        r8[al] = r8[al] | memory[ds*16+1150];
        if (r8[al] != 0) {
            pc = 0x0403;
            break;
        }
        return;
    } while (1);
}
function* sub_0410() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[cs*16+0x1];
        if (r8[al] != 0x05) {
            pc = 0x0422;
            break;
        }
        r16[ax] = 0x1012;
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0010;
        interrupt(16);
    case 0x0422:
        return;
    } while (1);
}
function* sub_0423() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+1048] = 0x00;
        r16[bx] = 0x2710;
    case 0x042b:
        r8[al] = 0x30;
    case 0x042d:
        if (r16[dx] < r16[bx]) {
            pc = 0x0437;
            break;
        }
        r16[dx] -= r16[bx];
        r8[al] += 1;
        pc = 0x042d;
        break;
    case 0x0437:
        if (r8[al] != 0x30) {
            pc = 0x044b;
            break;
        }
        if (r16[bx] == 0x0001) {
            pc = 0x044b;
            break;
        }
        if (memory[ds*16+1048] != 0x00) {
            pc = 0x044b;
            break;
        }
        r8[al] = 0x20;
        pc = 0x0450;
        break;
    case 0x044b:
        memory[ds*16+1048] = 0x01;
    case 0x0450:
        yield* sub_050e();
        r16[ax] = r16[bx];
        push(r16[dx]);
        r16[dx] = r16[dx] ^ r16[dx];
        r16[bx] = 0x000a;
        _div16(r16[bx]);
        r16[dx] = pop();
        r16[bx] = r16[ax];
        r16[bx] |= r16[bx];
        if (r16[bx] != 0) {
            pc = 0x042b;
            break;
        }
        return;
    } while (1);
}
function* sub_0465() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0004;
    case 0x0468:
        r16[ax] = r16[ax] ^ r16[ax];
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl16(ax, 1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl16(ax, 1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl16(ax, 1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl16(ax, 1);
        if (r8[al] <= 0x09) {
            pc = 0x0480;
            break;
        }
        r8[al] += 0x07;
    case 0x0480:
        r8[al] += 0x30;
        yield* sub_050e();
        if (--r16[cx]) {
            pc = 0x0468;
            break;
        }
        return;
    } while (1);
}
function* sub_0488() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
    case 0x0489:
        lodsb_data_forward();
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x0493;
            break;
        }
        yield* sub_050e();
        pc = 0x0489;
        break;
    case 0x0493:
        r16[ax] = pop();
        return;
    case 0x0495:
        r8[dl] = r8[al];
        if (memory[ds*16+1083] != 0x00) {
            pc = 0x04bd;
            break;
        }
        memory[ds*16+1083] += 1;
        memory16set(cs*16+0x6676, 0x0597);
        ds = memory16get(ds*16+14);
        r16[si] = r16[si] ^ r16[si];
        r16[cx] = 0x0029;
    case 0x04b2:
        r16[ax] = 0x010c;
        yield* sub_65be();
        r16[si] += 0x0030;
        if (--r16[cx]) {
            pc = 0x04b2;
            break;
        }
    case 0x04bd:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[di] = memory16get(ds*16+501);
        r16[di] <<= 1;
        r16[di] = r16[di] + memory16get(ds*16+503);
        memory16set(ds*16+501, memory16get(ds*16+501) + 1);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[cx] = 0x0006;
        r8[al] = r8[dl];
        if (r8[al] != 0x20) {
            pc = 0x04ee;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x04e0:
        stosw_data_forward();
        r16[di] += 0x1ffe;
        stosw_data_forward();
        r16[di] -= 0x1fb2;
        if (--r16[cx]) {
            pc = 0x04e0;
            break;
        }
        pc = 0x050c;
        break;
    case 0x04ee:
        r8[al] -= 0x30;
        if (r8[al] <= 0x09) {
            pc = 0x04f6;
            break;
        }
        r8[al] -= 0x02;
    case 0x04f6:
        ds = memory16get(ds*16+14);
        r8[ah] = 0x30;
        _mul8(r8[ah]);
        r16[si] = r16[ax];
    case 0x0500:
        movsw_data_data_forward();
        r16[di] += 0x1ffe;
        movsw_data_data_forward();
        r16[di] -= 0x1fb2;
        if (--r16[cx]) {
            pc = 0x0500;
            break;
        }
    case 0x050c:
        _STOP_("goto loc_058d");
        return;
    } while (1);
}
function* sub_050e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x0522;
            break;
        }
        _STOP_("goto loc_0495");
    case 0x0522:
        r16[di] = memory16get(ds*16+503);
        r16[di] = r16[di] + memory16get(ds*16+501);
        r16[di] = r16[di] + memory16get(ds*16+21096);
        memory16set(ds*16+501, memory16get(ds*16+501) + 1);
        if (r8[al] != 0x20) {
            pc = 0x0556;
            break;
        }
        r16[ax] = 0xa000;
        es = r16[ax];
        yield* sub_32dc();
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[al] = r8[al] ^ r8[al];
        r16[cx] = 0x000c;
    case 0x054a:
        stosb_video_forward();
        r16[di] += 0x0027;
        if (--r16[cx]) {
            pc = 0x054a;
            break;
        }
        r16[di] -= 0x01e0;
        pc = 0x058d;
        break;
    case 0x0556:
        r8[al] -= 0x30;
        if (r8[al] <= 0x09) {
            pc = 0x055e;
            break;
        }
        r8[al] -= 0x02;
    case 0x055e:
        ds = memory16get(ds*16+14);
        r8[ah] = 0x30;
        _mul8(r8[ah]);
        r16[si] = r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        yield* sub_32dc();
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = 0x01;
    case 0x0579:
        out8(r16[dx], r8[al]);
        r16[cx] = 0x000c;
    case 0x057d:
        movsb_video_data_forward();
        r16[di] += 0x0027;
        if (--r16[cx]) {
            pc = 0x057d;
            break;
        }
        r16[di] -= 0x01e0;
        r8[al] <<= 1;
        if (r8[al] <= 0x08) {
            pc = 0x0579;
            break;
        }
    case 0x058d:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_05b7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.carry = memory[ds*16+25862] < 0x01;
        memory[ds*16+25862] -= 0x01;
        memory[ds*16+25862] = memory[ds*16 + 25862] + 0x00 + flags.carry;
        if (memory[ds*16+25862] == 0) {
            pc = 0x05c6;
            break;
        }
        yield* sub_05c7();
    case 0x05c6:
        return;
    } while (1);
}
function* sub_05c7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x0636;
            break;
        }
        r16[si] = memory16get(ds*16+21098);
        r16[si] += 0x0174;
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0100;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0f01;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xf008;
        out16(r16[dx], r16[ax]);
        r8[cl] = memory[ds*16+1049];
        r8[bl] = r8[cl];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[ax] = 0xa000;
        ds = r16[ax];
        bp = 0x0028;
        if (r16[cx] == 0) {
            pc = 0x0619;
            break;
        }
    case 0x0614:
        yield* sub_0691();
        if (--r16[cx]) {
            pc = 0x0614;
            break;
        }
    case 0x0619:
        r8[cl] = 0x10;
        r8[cl] -= r8[bl];
        if (r8[cl] == 0) {
            pc = 0x0624;
            break;
        }
    case 0x061f:
        yield* sub_06ea();
        if (--r16[cx]) {
            pc = 0x061f;
            break;
        }
    case 0x0624:
        r16[ax] = 0x0001;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
    case 0x062c:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x0636:
        bp = 0x004f;
        r16[di] = 0x02e8;
        es = memory16get(ds*16+21090);
        r8[al] = 0xff;
        r8[cl] = memory[ds*16+1049];
        r8[ch] = r8[ch] ^ r8[ch];
        if (r16[cx] == 0) {
            pc = 0x064f;
            break;
        }
    case 0x064a:
        yield* sub_065e();
        if (--r16[cx]) {
            pc = 0x064a;
            break;
        }
    case 0x064f:
        r8[cl] = 0x10;
        r8[cl] = r8[cl] - memory[ds*16+1049];
        if (r16[cx] == 0) {
            pc = 0x062c;
            break;
        }
    case 0x0657:
        yield* sub_06d4();
        if (--r16[cx]) {
            pc = 0x0657;
            break;
        }
        pc = 0x062c;
        break;
        return;
    } while (1);
}
function* sub_065e() {
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] -= 0x04af;
}
function* sub_0691() {
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] -= 0x0257;
}
function* sub_06d4() {
    r16[di] += 0x01e0;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] += bp;
    stosb_data_forward();
    r16[di] -= 0x031f;
}
function* sub_06ea() {
    r16[si] += 0x00f0;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] += bp;
    memoryVideoAdd(ds, r16[si], r8[al]);
    r16[si] -= 0x0167;
}
function* sub_0701() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[ds*16+1064] = 0x03;
    case 0x070b:
        memory[ds*16+1052] = 0x00;
        memory16set(ds*16+1053, 0x0320);
        r16[dx] = 0x0201;
        r16[cx] = 0x0c80;
        r8[ah] = 0x03;
        flags.interrupt = false;
    case 0x071f:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x03)) {
            pc = 0x0727;
            break;
        }
        r8[ah] &= 0x02;
    case 0x0727:
        if (!(r8[al] & 0x0c)) {
            pc = 0x072e;
            break;
        }
        r8[ah] &= 0x01;
    case 0x072e:
        if (--r16[cx]) {
            pc = 0x071f;
            break;
        }
        r8[al] = 0xff;
        if (!(r8[ah] & 0x02)) {
            pc = 0x073a;
            break;
        }
        r8[al] = memory[ds*16+0x42a];
    case 0x073a:
        if (!(r8[ah] & 0x01)) {
            pc = 0x0742;
            break;
        }
        r8[al] = memory[ds*16+0x429];
    case 0x0742:
        memory[ds*16+0x427] = r8[al];
        yield* sub_07b0();
        if (flags.carry) {
            pc = 0x0796;
            break;
        }
        if (r16[ax] >= 0x0320) {
            pc = 0x0796;
            break;
        }
        if (r16[bx] >= 0x0320) {
            pc = 0x0796;
            break;
        }
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x0796;
            break;
        }
        r16[bx] |= r16[bx];
        if (r16[bx] == 0) {
            pc = 0x0796;
            break;
        }
        r8[cl] = 0x02;
        bp = r16[ax];
        r16[ax] >>= r8[cl];
        r16[ax] -= bp;
        r16[ax] = -r16[ax];
        memory16set(ds*16+0x041f, r16[ax]);
        r16[ax] = bp;
        r16[ax] >>= r8[cl];
        r16[ax] += bp;
        memory16set(ds*16+0x0425, r16[ax]);
        bp = r16[bx];
        r16[bx] >>= r8[cl];
        r16[bx] -= bp;
        r16[bx] = -r16[bx];
        memory16set(ds*16+1057, r16[bx]);
        r16[bx] = bp;
        r16[bx] >>= r8[cl];
        r16[bx] += bp;
        memory16set(ds*16+1059, r16[bx]);
        if (r16[ax] >= r16[bx]) {
            pc = 0x078f;
            break;
        }
        r16[ax] = r16[bx];
    case 0x078f:
        r16[ax] <<= 1;
        memory16set(ds*16+0x041d, r16[ax]);
        pc = 0x07ae;
        break;
    case 0x0796:
        memory[ds*16+1064] -= 1;
        if (memory[ds*16+1064] == 0) {
            pc = 0x07a9;
            break;
        }
        r8[al] = memory[ds*16+0x429];
        var t = memory[ds*16+1066]; memory[ds*16+1066] = r8[al]; r8[al] = t; //_xchg(memory[ds*16+1066], r8[al]);
        memory[ds*16+0x429] = r8[al];
        pc = 0x070b;
        break;
    case 0x07a9:
        memory[ds*16+1063] = 0xff;
    case 0x07ae:
        flags.interrupt = true;
        return;
    } while (1);
}
function* sub_07b0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16+1063];
        flags.sign = !!(r8[cl] & 0x80);
        r8[cl] |= r8[cl];
        if (flags.sign) {
            pc = 0x0802;
            break;
        }
        if (memory[ds*16+1052] != 0x00) {
            pc = 0x0802;
            break;
        }
        r16[dx] = 0x0201;
        r8[al] = in8(r16[dx]);
        r8[al] >>= r8[cl];
        if (r8[al] & 0x03) {
            pc = 0x0802;
            break;
        }
        r8[al] = r8[al] ^ 0x30;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        bp = bp ^ bp;
        r16[di] = r16[di] ^ r16[di];
        r16[bx] = r16[bx] ^ r16[bx];
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        memory[ds*16+1067] -= r8[bh] + flags.carry;
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        memory[ds*16+1067] -= r8[bh] + flags.carry;
        r16[si] = memory16get(ds*16+1053);
        flags.interrupt = false;
        out8(r16[dx], r8[al]);
    case 0x07eb:
        r8[al] = in8(r16[dx]);
        r8[al] >>= r8[cl];
        if (!(r8[al] & 0x03)) {
            pc = 0x07fd;
            break;
        }
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        r16[di] = r16[di] + bp + flags.carry;
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        r16[bx] = r16[bx] + bp + flags.carry;
        r16[si] -= 1;
        if (r16[si] != 0) {
            pc = 0x07eb;
            break;
        }
    case 0x07fd:
        r16[ax] = r16[di];
        flags.interrupt = true;
        flags.carry = false;
        return;
    case 0x0802:
        flags.interrupt = true;
        flags.carry = true;
        return;
    } while (1);
}
function* sub_0805() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        memory[ds*16+0x42d] = r8[al];
        memory[ds*16+0x42e] = r8[al];
        memory[ds*16+0x42f] = r8[al];
        memory[ds*16+0x430] = r8[al];
        memory[ds*16+0x42b] = r8[al];
        memory[ds*16+0x42c] = r8[al];
        yield* sub_07b0();
        if (flags.carry) {
            pc = 0x085c;
            break;
        }
        if (r16[ax] > memory16get(ds*16+1055)) {
            pc = 0x0839;
            break;
        }
        memory[ds*16+1072] = 0xff;
        pc = 0x0844;
        break;
    case 0x0839:
        if (r16[ax] < memory16get(ds*16+1061)) {
            pc = 0x0844;
            break;
        }
        memory[ds*16+1071] = 0xff;
    case 0x0844:
        if (r16[bx] > memory16get(ds*16+1057)) {
            pc = 0x0851;
            break;
        }
        memory[ds*16+1069] = 0xff;
        pc = 0x085c;
        break;
    case 0x0851:
        if (r16[bx] < memory16get(ds*16+1059)) {
            pc = 0x085c;
            break;
        }
        memory[ds*16+1070] = 0xff;
    case 0x085c:
        r8[al] = memory[ds*16+0x488];
        r8[al] = r8[al] | memory[ds*16+1212];
        r8[al] = r8[al] | memory[ds*16+1129];
        r8[al] = r8[al] | memory[ds*16+1104];
        memory[ds*16+1069] |= r8[al];
        r8[al] = memory[ds*16+0x490];
        r8[al] = r8[al] | memory[ds*16+1211];
        r8[al] = r8[al] | memory[ds*16+1162];
        r8[al] = r8[al] | memory[ds*16+1118];
        memory[ds*16+1070] |= r8[al];
        r8[al] = memory[ds*16+0x48d];
        r8[al] = r8[al] | memory[ds*16+1209];
        r8[al] = r8[al] | memory[ds*16+1166];
        r8[al] = r8[al] | memory[ds*16+1127];
        memory[ds*16+1071] |= r8[al];
        r8[al] = memory[ds*16+0x48b];
        r8[al] = r8[al] | memory[ds*16+1210];
        r8[al] = r8[al] | memory[ds*16+1131];
        r8[al] = r8[al] | memory[ds*16+1126];
        memory[ds*16+1072] |= r8[al];
        r8[al] = memory[ds*16+0x45c];
        r8[al] = r8[al] | memory[ds*16+1145];
        r8[al] = r8[al] | memory[ds*16+1204];
        r8[al] = r8[al] | memory[ds*16+1175];
        memory[ds*16+1067] |= r8[al];
        r8[al] = memory[ds*16+0x459];
        r8[al] = r8[al] | memory[ds*16+1156];
        memory[ds*16+1068] |= r8[al];
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_08d0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0003;
        interrupt(16);
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[cs*16+0x6BB3] = 0x00;
        r8[ah] = 0x09;
        r16[dx] = 0x0061;
        interrupt(33);
        pc = 0x096c;
        break;
    case 0x08ea:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = 0x0003;
        interrupt(16);
        r8[ah] = 0x09;
        r16[dx] = 0x0077;
        interrupt(33);
        pc = 0x096c;
        break;
    case 0x08fd:
        r16[ax] = 0x0003;
        interrupt(16);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[ah] = 0x09;
        r16[dx] = 0x008a;
        interrupt(33);
        pc = 0x096c;
        break;
    case 0x0910:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        r16[ax] = 0x0003;
        interrupt(16);
        r16[di] = r16[dx];
        push(r16[dx]);
        if (memory[ds*16+1047] == 0x00) {
            pc = 0x092d;
            break;
        }
        r8[ah] = 0x09;
        r16[dx] = 0x009e;
        interrupt(33);
        pc = 0x0934;
        break;
    case 0x092d:
        r8[ah] = 0x09;
        r16[dx] = 0x00b1;
        interrupt(33);
    case 0x0934:
        r16[cx] = 0x005a;
        r16[ax] = r16[ax] ^ r16[ax];
        _repne_scasb();
        memory[ds*16+r16[di]] = 0x24;
        r16[dx] = pop();
        r8[ah] = 0x09;
        interrupt(33);
        if (memory[ds*16+1047] == 0x01) {
            pc = 0x096c;
            break;
        }
        memory[ds*16+1219] = 0x00;
        r8[ah] = 0x09;
        r16[dx] = 0x00d5;
        interrupt(33);
        memory[ds*16+1216] = 0x00;
    case 0x095b:
        r8[al] = memory[ds*16+0x4c0];
        if (r8[al] != 0x1c) {
            pc = 0x095b;
            break;
        }
        yield* sub_3160();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
    {yield* sub_097b(); return; };
    case 0x096c:
        r8[ah] = 0x09;
        r16[dx] = 0x0109;
        interrupt(33);
        memory[ds*16+1219] = 0x00;
        flags.interrupt = true;
    case 0x0979:
        pc = 0x0979;
        break;
        return;
    } while (1);
}
function* sub_097b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        memory[cs*16+0x6BB3] = 0x01;
        r16[ax] = 0x3d00;
        interrupt(33);
        memory[cs*16+0x6BB3] = 0x00;
        if (!flags.carry) {
            pc = 0x0998;
            break;
        }
        _STOP_("goto loc_0910");
    case 0x0998:
        memory16set(cs*16+0xAF2, r16[ax]);
        r16[ax] = memory16get(ds*16+0x04c1);
        memory16set(cs*16+0xAF4, r16[ax]);
        ds = r16[ax];
        memory[cs*16+0x6BB3] = 0x01;
        r16[bx] = memory16get(cs*16+0xAF2);
        r16[cx] = 0x0006;
        r16[dx] = 0x041a;
        r8[ah] = 0x3f;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x09bf;
            break;
        }
        _STOP_("goto loc_08fd");
    case 0x09bf:
        memory[cs*16+0x6BB3] -= 1;
        r16[si] = r16[dx];
        lodsw_data_forward();
        if (r8[ah] != 0x10) {
            pc = 0x09cf;
            break;
        }
        yield* loc_0af6();
        return;
    case 0x09cf:
        r16[bx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = 0x0004;
    case 0x09d5:
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        rcr16(ax, 1);
        if (--r16[cx]) {
            pc = 0x09d5;
            break;
        }
        r16[ax] += 1;
        r16[cx] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] + memory16get(es*16+1217);
        memory16set(es*16+1217, r16[ax]);
        ds = r16[ax];
        r16[ax] = memory16get(cs*16+0xAF4);
        es = r16[ax];
        memory[cs*16+0x6BB3] = 0x01;
        r16[bx] = memory16get(cs*16+0xAF2);
        r16[cx] = r16[cx];
        r16[dx] = 0x0006;
        r8[ah] = 0x3f;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x0a08;
            break;
        }
        _STOP_("goto loc_08fd");
    case 0x0a08:
        memory[cs*16+0x6BB3] -= 1;
        r8[dl] = 0x01;
        memory16set(ds*16+0, 0x0002);
        r16[di] = r16[di] ^ r16[di];
        yield* loc_0a17();
        return;
    } while (1);
}
function* loc_0a17() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x0a17:
        r16[bx] = r16[bx] ^ r16[bx];
        if (yield *sub_0abe())
            return;
        r8[bh] |= r8[bh];
        if (r8[bh] == 0) {
            pc = 0x0a66;
            break;
        }
        if (r8[bl] < 0x02) {
            pc = 0x0a35;
            break;
        }
        r8[cl] = r8[bl];
        r8[ch] = r8[ch] ^ r8[ch];
        bp = r16[ax];
        r8[al] = memory[es*16+r16[di] + -1];
        rep_stosb_data_forward();
        r16[ax] = bp;
        pc = 0x0a6a;
        break;
    case 0x0a35:
        r8[bl] |= r8[bl];
        if (r8[bl] != 0) {
            pc = 0x0a4c;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        if (yield *sub_0abe())
            return;
        bp = r16[ax];
        r16[cx] = r16[bx];
        r8[al] = memory[es*16+r16[di] + -1];
        rep_stosb_data_forward();
        r16[ax] = bp;
        pc = 0x0a6a;
        break;
    case 0x0a4c:
        r16[bx] = r16[bx] ^ r16[bx];
        if (yield *sub_0abe())
            return;
        r8[ch] = r8[bl];
        r16[bx] = r16[bx] ^ r16[bx];
        if (yield *sub_0abe())
            return;
        r8[cl] = r8[bl];
        bp = r16[ax];
        r8[al] = memory[es*16+r16[di] + -1];
        rep_stosb_data_forward();
        r16[ax] = bp;
        pc = 0x0a6a;
        break;
    case 0x0a66:
        memory[es*16+r16[di]] = r8[bl];
        r16[di] += 1;
    case 0x0a6a:
        if (r16[di] < 0x4000) {
            pc = 0x0a17;
            break;
        }
        r16[bx] = es;
        r16[bx] += 0x03ff;
        es = r16[bx];
        r16[di] -= 0x3ff0;
        pc = 0x0a6a;
        break;
        return;
    } while (1);
}
function* loc_0a7e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds*16+0, memory16get(ds*16+0) - 0x0002);
        if (memory16get(ds*16+0) != 0) {
            pc = 0x0ab9;
            break;
        }
        push(r16[bx]);
        push(r16[di]);
        memory[cs*16+0x6BB3] = 0x01;
        r16[bx] = memory16get(cs*16+0xAF2);
        r16[cx] = 0x1000;
        r16[dx] = 0x041a;
        r8[ah] = 0x3f;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x0aa1;
            break;
        }
        _STOP_("goto loc_08fd");
    case 0x0aa1:
        memory[cs*16+0x6BB3] -= 1;
        memory16set(ds*16+0x0000, r16[ax]);
        r16[ax] |= r16[ax];
        r16[di] = pop();
        r16[bx] = pop();
        if (r16[ax] == 0)
            {
            return yield* loc_0ad3();
        }
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        memory16set(ds*16+0, memory16get(ds*16+0) + 0x0000 + flags.carry);
        r16[si] = 0x041a;
    case 0x0ab9:
        lodsw_data_forward();
        xchg8(ah, al);
        r8[dl] = 0x11;
        if (yield *sub_0abe())
            {   _ASSERT(0);
            return true;
        }
        return false;
        return;
    } while (1);
}
function* sub_0abe() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x0abe:
        r8[dl] -= 1;
        if (r8[dl] == 0)
            {
            return yield* loc_0a7e();
        }
        flags.carry = !!(r16[ax] & 0x8000);
        rol16(ax, 1);
        if (!flags.carry) {
            pc = 0x0ac8;
            break;
        }
        r16[bx] += 1;
        r16[bx] += 1;
    case 0x0ac8:
        r16[bx] = memory16get(ds*16+r16[bx] + 6);
        flags.sign = !!(r8[bh] & 0x80);
        r8[bh] |= r8[bh];
        if (!flags.sign) {
            pc = 0x0abe;
            break;
        }
        r8[bh] &= 0x7f;
        return false;
        return;
    } while (1);
}
function* loc_0ad3() {
    memory[cs*16+0x6BB3] = 0x01;
    r16[bx] = memory16get(cs*16+0xAF2);
    r8[ah] = 0x3e;
    interrupt(33);
    memory[cs*16+0x6BB3] -= 1;
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = memory16get(cs*16+0xAF4);
    return true;
}
function* loc_0af6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = r16[dx] ^ r16[dx];
        r16[cx] = r16[cx] ^ r16[cx];
        r16[ax] = 0x4200;
        memory[cs*16+0x6BB3] = 0x01;
        interrupt(33);
        memory[cs*16+0x6BB3] = 0x00;
        r16[ax] = 0x168f;
        es = r16[ax];
        r16[ax] = memory16get(cs*16+0xAF4);
        ds = r16[ax];
        r16[cx] = 0x0004;
        r16[dx] = 0x000e;
        r16[bx] = memory16get(cs*16+0xAF2);
        r8[ah] = 0x3f;
        memory[cs*16+0x6BB3] = 0x01;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x0b30;
            break;
        }
        _STOP_("goto loc_08fd");
    case 0x0b30:
        memory[cs*16+0x6BB3] = 0x00;
        r8[al] = memory[ds*16+0x0f];
        r8[al] &= 0xf0;
        if (r8[al] == 0x10) {
            pc = 0x0b42;
            break;
        }
        _STOP_("goto loc_08ea");
    case 0x0b42:
        r16[di] = r16[di] ^ r16[di];
        r16[bx] = memory16get(ds*16+14);
        r16[ax] = memory16get(ds*16+0x0010);
        r16[cx] = 0x0004;
    case 0x0b4e:
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        rcr16(ax, 1);
        if (--r16[cx]) {
            pc = 0x0b4e;
            break;
        }
        r16[ax] += 1;
        r16[ax] = r16[ax] + memory16get(es*16+1217);
        memory16set(es*16+1217, r16[ax]);
        ds = r16[ax];
        r16[ax] = memory16get(cs*16+0xAF4);
        es = r16[ax];
        memory16set(ds*16+0, r16[di]);
        memory16set(ds*16+2, r16[di]);
    case 0x0b6e:
        yield* sub_0c1e();
        yield* sub_0c30();
        if (r16[ax] == 0x0101)
            {
            flags.zero = true;
            pc = 0x0b8b;
            break;
        }
        memory16set(ds*16+0x0005, r16[ax]);
        memory[ds*16+0x04] = r8[al];
        stosb_data_forward();
    case 0x0b80:
        yield* sub_0c30();
        if (r16[ax] == 0x0100) {
            pc = 0x0b6e;
            break;
        }
        flags.zero = r16[ax] == 0x0101;
    case 0x0b8b:
        if (flags.zero) {
            pc = 0x0c02;
            break;
        }
        memory16set(ds*16+0x0007, r16[ax]);
        r16[si] = 0x4010;
        if (memory16get(ds*16+12) > r16[ax]) {
            pc = 0x0ba3;
            break;
        }
        r8[dl] = memory[ds*16+4];
        memory[ds*16+r16[si]] = r8[dl];
        r16[si] += 1;
        r16[ax] = memory16get(ds*16+0x0005);
    case 0x0ba3:
        r8[ah] |= r8[ah];
        if (r8[ah] == 0) {
            pc = 0x0bb8;
            break;
        }
        r16[bx] = r16[ax];
        r8[dl] = memory[ds*16+r16[bx] + 4112];
        memory[ds*16+r16[si]] = r8[dl];
        r16[si] += 1;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 8208);
        pc = 0x0ba3;
        break;
    case 0x0bb8:
        memory[ds*16+r16[si]] = r8[al];
        r16[si] += 1;
        memory[ds*16+0x04] = r8[al];
    case 0x0bbe:
        r16[si] -= 1;
        r8[al] = memory[ds*16+r16[si]];
        stosb_data_forward();
        if (r16[di] < 0x8000) {
            pc = 0x0bd3;
            break;
        }
        r16[ax] = es;
        r16[ax] += 0x0800;
        es = r16[ax];
        r16[di] -= 0x8000;
    case 0x0bd3:
        if (r16[si] != 0x4010) {
            pc = 0x0bbe;
            break;
        }
        r16[bx] = memory16get(ds*16+12);
        if (r16[bx] >= 0x1000) {
            pc = 0x0bf9;
            break;
        }
        r8[dl] = memory[ds*16+4];
        memory[ds*16+r16[bx] + 4112] = r8[dl];
        r16[dx] = memory16get(ds*16+5);
        r16[bx] <<= 1;
        memory16set(ds*16+r16[bx] + 8208, r16[dx]);
        memory16set(ds*16+12, memory16get(ds*16+12) + 1);
    case 0x0bf9:
        r16[ax] = memory16get(ds*16+0x0007);
        memory16set(ds*16+0x0005, r16[ax]);
        pc = 0x0b80;
        break;
    case 0x0c02:
        memory[ds*16+1219] = 0x01;
        r16[bx] = memory16get(cs*16+0xAF2);
        r8[ah] = 0x3e;
        interrupt(33);
        memory[ds*16+1219] -= 1;
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = memory16get(cs*16+0xAF4);
        return;
    } while (1);
}
function* sub_0c1e() {
    memory16set(ds*16+10, 0x0200);
    memory[ds*16+9] = 0x09;
    memory16set(ds*16+12, 0x0102);
}
function* sub_0c30() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+0x000c);
        if (memory16get(ds*16+10) != r16[ax]) {
            pc = 0x0c48;
            break;
        }
        if (memory[ds*16+9] == 0x0c) {
            pc = 0x0c48;
            break;
        }
        memory[ds*16+9] += 1;
        memory16set(ds*16+10, memory16get(ds*16+10) << 1);
    case 0x0c48:
        r16[bx] = memory16get(ds*16+2);
        r16[si] = r16[bx];
        flags.carry = (r8[bl] + memory[ds*16+9]) >= 0x100;
        r8[bl] = r8[bl] + memory[ds*16+9];
        r8[bh] = r8[bh] + 0x00 + flags.carry;
        if (memory16get(ds*16+0) >= r16[bx]) {
            pc = 0x0caf;
            break;
        }
        r16[cx] = 0x1000;
        r16[dx] = 0x0010;
        r16[bx] = 0x0010;
        r16[bx] = r16[bx] - memory16get(ds*16+0);
        r16[bx] = r16[bx] + memory16get(ds*16+2);
        memory16set(ds*16+2, r16[bx]);
        r16[si] = r16[bx];
        r16[ax] = memory16get(ds*16+0x100e);
        memory16set(ds*16+0x000e, r16[ax]);
        r16[bx] = memory16get(cs*16+0xAF2);
        r8[ah] = 0x3f;
        memory[cs*16+0x6BB3] = 0x01;
        interrupt(33);
        if (!flags.carry) {
            pc = 0x0c8c;
            break;
        }
        _STOP_("goto loc_08fd");
    case 0x0c8c:
        memory[cs*16+0x6BB3] -= 1;
        r16[ax] += 1;
        r16[ax] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+0x0000, r16[ax]);
        push(r16[di]);
        r16[di] >>= 1;
        r16[di] >>= 1;
        r16[di] >>= 1;
        r16[di] >>= 1;
        r16[ax] = es;
        r16[ax] += r16[di];
        es = r16[ax];
        r16[di] = pop();
        r16[di] &= 0x000f;
    case 0x0caf:
        r16[cx] = r16[si];
        r16[si] >>= 1;
        r16[si] >>= 1;
        r16[si] >>= 1;
        r8[cl] &= 0x07;
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        xchg8(ah, al);
        r8[dh] = r8[dh] ^ r8[dh];
        r16[ax] <<= r8[cl];
        r8[ch] = 0x10;
        r8[ch] -= r8[cl];
        flags.carry = r8[ch] < memory[ds*16+9];
        r8[ch] = r8[ch] - memory[ds*16+9];
        if (!flags.carry) {
            pc = 0x0cd8;
            break;
        }
        r8[ch] = -r8[ch];
        r8[cl] = 0x08;
        r8[cl] -= r8[ch];
        r8[dh] = memory[ds*16+r16[si] + 16];
        r8[dh] >>= r8[cl];
    case 0x0cd8:
        r8[bl] = memory[ds*16+9];
        r8[bh] = r8[bh] ^ r8[bh];
        memory16set(ds*16+2, memory16get(ds*16+2) + r16[bx]);
        r8[cl] = 0x10;
        r8[cl] -= r8[bl];
        r16[ax] >>= r8[cl];
        r8[al] |= r8[dh];
        return;
    } while (1);
}
function* sub_0ceb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        es = r16[ax];
        r16[si] = 0x0433;
        r16[di] = 0x0020;
        r16[cx] = 0x0004;
        flags.interrupt = false;
        flags.direction = false;
    case 0x0d05:
        r16[ax] = bios16get(es, r16[di]);
        r16[ax] = 0; //_xchg(memory16get(ds*16+r16[si]), r16[ax]);
        stosw_bios_forward();
        r16[si] += 1;
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x0d05;
            break;
        }
        push(ds);
        es = pop();
        r16[di] = 0x0440;
        r16[ax] = r16[ax] ^ r16[ax];
        r16[cx] = 0x0040;
        rep_stosw_data_forward();
        flags.interrupt = true;
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_0d27() {
    memory16set(cs*16+0xD23, r16[ax]);
    memory16set(cs*16+0xD25, ds);
    r16[ax] = 0x168f;
    ds = r16[ax];
    flags.carry = (memory16get(ds*16+1084) + 0x0001) >= 0x10000;
    memory16set(ds*16+1084, memory16get(ds*16+1084) + 0x0001);
    memory16set(ds*16+1086, memory16get(ds*16+1086) + 0x0000 + flags.carry);
    push(memory16get(ds*16+1077));
    push(memory16get(ds*16+1075));
    ds = memory16get(cs*16+0xD25);
    r16[ax] = memory16get(cs*16+0xD23);
}
function* sub_0d51() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[bx]);
        push(r16[ax]);
        flags.direction = false;
        r16[ax] = 0x168f;
        ds = r16[ax];
        _in(r8[al], 96);
        r8[bl] = r8[al];
        _in(r8[al], 97);
        r8[ah] = r8[al];
        r8[al] |= 0x80;
        out8(97, r8[al]);
        r8[al] = r8[ah];
        out8(97, r8[al]);
        memory[ds*16+1216] = r8[bl];
        if (r8[bl] != 0x01) {
            pc = 0x0d79;
            break;
        }
    case 0x0d79:
        if (memory[cs*16+0x6BB3] != 0x00) {
            pc = 0x0df9;
            break;
        }
        r16[ax] = 0x0003;
        interrupt(16);
        r16[si] = 0x0127;
        r16[cx] = 0x0001;
        r8[ah] = 0x0e;
        r16[bx] = 0x0003;
    case 0x0d8b:
        lodsb_data_forward();
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x0d94;
            break;
        }
        interrupt(16);
        pc = 0x0d8b;
        break;
    case 0x0d94:
        r8[al] = r8[al] ^ r8[al];
        out8(64, r8[al]);
        out8(64, r8[al]);
        r16[dx] = 0x0040;
    case 0x0d9d:
        r8[al] = in8(r16[dx]);
        r8[ah] = r8[al];
        r8[al] = in8(r16[dx]);
        xchg8(ah, al);
        if (r16[ax] < 0xf000) {
            pc = 0x0d9d;
            break;
        }
    case 0x0da8:
        r8[al] = in8(r16[dx]);
        r8[ah] = r8[al];
        r8[al] = in8(r16[dx]);
        xchg8(ah, al);
        if (r16[ax] > 0x4000) {
            pc = 0x0da8;
            break;
        }
        r16[ax] = 0x0003;
        interrupt(16);
        yield* sub_0ceb();
        r8[al] = 0x0a;
        out8(66, r8[al]);
        r8[al] = r8[al] ^ r8[al];
        out8(66, r8[al]);
        _in(r8[al], 97);
        r8[al] &= 0xfc;
        out8(97, r8[al]);
        r16[ax] = cs;
        es = r16[ax];
        r16[cx] = 0x0dc9;
        r16[di] = r16[di] ^ r16[di];
        rep_stosb_data_forward();
        r16[di] = 0x0df9;
        r16[dx] = 0x015e;
    case 0x0dda:
        r16[cx] = 0x0400;
        rep_stosb_data_forward();
        r16[di] -= 0x0400;
        r16[ax] += 0x0040;
        es = r16[ax];
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x0dda;
            break;
        }
        r8[al] = 0x20;
        out8(32, r8[al]);
        r16[ax] = 0x4c00;
        interrupt(33);
        _STOP_("db 00h");
    case 0x0df9:
        if (r8[bl] != 0x3d) {
            pc = 0x0e1c;
            break;
        }
        memory[cs*16+0x16E4] = memory[cs*16 + 0x16E4] ^ 0x02;
        if (memory[cs*16+0x16E3] == 0x01) {
            pc = 0x0e1c;
            break;
        }
        _in(r8[al], 97);
        r8[al] &= 0xfc;
        if (!(memory[cs*16+0x16E4] & 0x02)) {
            pc = 0x0e1a;
            break;
        }
        r8[al] |= 0x03;
    case 0x0e1a:
        out8(97, r8[al]);
    case 0x0e1c:
        r8[bl] &= 0x7f;
        r8[bh] = r8[bh] ^ r8[bh];
        r8[al] = memory[ds*16+0x4c0];
        _cbw();
        r8[ah] = (~r8[ah]);
        memory[ds*16+r16[bx] + 1088] = r8[ah];
        r8[al] = 0x20;
        out8(32, r8[al]);
        r16[ax] = pop();
        r16[bx] = pop();
        ds = pop();
        return;
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_0e33() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        flags.interrupt = false;
        r16[ax] = r16[ax] ^ r16[ax];
        ds = r16[ax];
        r8[al] = 0xcf;
        _ASSERT(0);
        stosb_data_forward();
        memory16set(ds*16+4, 0x1028);
        memory16set(ds*16+6, cs);
        pushf();
        r16[ax] = pop();
        r8[ah] |= 0x01;
        push(r16[ax]);
        popf();
        flags.interrupt = true;
        r16[ax] = 0x168f;
        es = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        ds = r16[ax];
        r16[bx] = 0x0211;
        r8[ch] = 0x00;
    case 0x0e68:
        r8[cl] = 0x01;
    case 0x0e6a:
        r16[ax] = 0x0201;
        r16[dx] = r16[dx] ^ r16[dx];
        pushf();
        _STOP_("db 00h");
        flags.interrupt = false;
        r16[ax] = memory16get(cs*16+0xFFC);
        r16[ax] = r16[ax] | memory16get(cs*16+0xFFE);
        if (r16[ax] != 0) {
            pc = 0x0e92;
            break;
        }
        r8[cl] += 1;
        if (r8[cl] != 0x0a) {
            pc = 0x0e6a;
            break;
        }
        r8[ch] += 1;
        if (r8[ch] <= 0x27) {
            pc = 0x0e68;
            break;
        }
        r8[ah] = 0x4c;
        interrupt(33);
    case 0x0e92:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r8[ah] = 0x19;
        interrupt(33);
        r8[al] &= 0x01;
        memory[ds*16+0x210] = r8[al];
        yield* sub_0efe();
        if (!flags.carry) {
            pc = 0x0ede;
            break;
        }
        yield* sub_0efe();
        if (!flags.carry) {
            pc = 0x0ede;
            break;
        }
        memory[ds*16+528] = memory[ds*16 + 528] ^ 0x01;
        yield* sub_0efe();
        if (!flags.carry) {
            pc = 0x0ede;
            break;
        }
        yield* sub_0efe();
        if (!flags.carry) {
            pc = 0x0ede;
            break;
        }
        r16[ax] = 0x0003;
        interrupt(16);
        r16[dx] = 0x01f9;
        r8[ah] = 0x09;
        interrupt(33);
        r8[ah] = 0x0e;
        r8[al] = memory[ds*16+0x414];
        r8[al] += 0x30;
        interrupt(16);
        r8[al] = 0x2d;
        interrupt(16);
        r16[dx] = memory16get(ds*16+1045);
        yield* sub_1004();
        _STOP_("goto loc_096c");
    case 0x0ede:
        pushf();
        if (memory[ds*16+1047] == 0x01) {
            pc = 0x0ef3;
            break;
        }
        r8[ah] = 0x19;
        interrupt(33);
        if (r8[al] < 0x03) {
            pc = 0x0ef3;
            break;
        }
        memory[ds*16+1047] = 0x01;
    case 0x0ef3:
        popf();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_0efe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = memory[ds*16+528];
        r8[ah] = r8[ah] ^ r8[ah];
        interrupt(19);
        r16[ax] = 0x0201;
        r16[bx] = 0x0211;
        r16[cx] = 0x0002;
        r8[dl] = memory[ds*16+528];
        r8[dh] = 0x00;
        memory[ds*16+1041] = 0x01;
        yield* sub_0ffa();
        if (_FIXME_) {
            pc = 0x0f7c;
            break;
        }
        memory[ds*16+1047] = 0x00;
        r16[ax] = 0x2701;
        if (memory[ds*16+r16[bx]] != 0xf9) {
            pc = 0x0f34;
            break;
        }
        memory[ds*16+1047] = 0x01;
        r16[ax] = 0x4f00;
    case 0x0f34:
        memory[ds*16+527] = r8[ah];
        memory[ds*16+0x20e] = r8[al];
        memory[ds*16+1041] = 0x02;
        r8[cl] = 0x01;
    case 0x0f42:
        r16[ax] = 0x0201;
        r16[bx] = 0x0211;
        r8[ch] = memory[ds*16+527];
        r8[dh] = memory[ds*16+526];
        yield* sub_0ffa();
        if (_FIXME_) {
            pc = 0x0f7c;
            break;
        }
        r8[cl] += 1;
        if (r8[cl] <= 0x0a) {
            pc = 0x0f42;
            break;
        }
        r16[ax] = 0x0201;
        r8[cl] = 0xf7;
        r8[dl] = memory[ds*16+528];
        yield* sub_0ffa();
        memory[ds*16+1041] = 0x03;
        if (_FIXME_) {
            pc = 0x0f7c;
            break;
        }
        memory[ds*16+1041] = 0x04;
        memory16set(ds*16+0x0412, r16[ax]);
        if (r8[ah] == 0x10) {
            pc = 0x0f90;
            break;
        }
    case 0x0f7c:
        r8[al] = memory[ds*16+0x411];
        if (memory[ds*16+1044] >= r8[al]) {
            pc = 0x0f8e;
            break;
        }
        memory[ds*16+0x414] = r8[al];
        r16[ax] = memory16get(ds*16+0x0412);
        memory16set(ds*16+0x0415, r16[ax]);
    case 0x0f8e:
        flags.carry = true;
        return;
    case 0x0f90:
        memory[ds*16+1041] = 0x05;
        if (memory16get(ds*16+529) != 0x4f4d) {
            pc = 0x0f7c;
            break;
        }
        memory[ds*16+1041] = 0x06;
        if (memory16get(ds*16+531) != 0x544b) {
            pc = 0x0f7c;
            break;
        }
        memory[ds*16+1041] = 0x07;
        r16[di] = 0x0250;
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x0fb4:
        r16[bx] += 1;
        if (memory[ds*16+r16[bx] + r16[di]] == 0x4e) {
            pc = 0x0fb4;
            break;
        }
        memory16set(ds*16+1042, r16[bx]);
        _lea(di, ds, r16[bx] + r16[di] + 10);
        memory[ds*16+1041] = 0x08;
        r8[ah] = memory[ds*16+r16[di]];
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x0fcd:
        r16[bx] += 1;
        if (memory[ds*16+r16[bx] + r16[di]] == r8[ah]) {
            pc = 0x0fcd;
            break;
        }
        memory16set(ds*16+1042, r16[bx]);
        r16[di] += r16[bx];
        memory[ds*16+1041] = 0x09;
        r16[di] = 0x0410;
        r8[al] = memory[ds*16+r16[di]];
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x0fe7:
        r16[bx] -= 1;
        if (memory[ds*16+r16[bx] + r16[di]] == r8[al]) {
            pc = 0x0fe7;
            break;
        }
        r16[bx] = (~r16[bx]);
        memory16set(ds*16+1042, r16[bx]);
        if (r16[bx] < 0x00a8) {
            pc = 0x0f7c;
            break;
        }
        flags.carry = false;
        return;
    } while (1);
}
function* sub_0ffa() {
    pushf();
    _STOP_("db 00h");
    memory16set(ds*16+0x0412, r16[ax]);
}
function* sub_1004() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0004;
    case 0x1007:
        r8[al] = r8[al] ^ r8[al];
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl8(al,  1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl8(al,  1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl8(al,  1);
        flags.carry = !!(r16[dx] & 0x8000);
        r16[dx] <<= 1;
        _rcl8(al,  1);
        if (r8[al] <= 0x09) {
            pc = 0x101f;
            break;
        }
        r8[al] += 0x07;
    case 0x101f:
        r8[al] += 0x30;
        r8[ah] = 0x0e;
        interrupt(16);
        if (--r16[cx]) {
            pc = 0x1007;
            break;
        }
        return;
    } while (1);
}
function* sub_1028() {
    var pc = 0;
    do switch (pc) {
    case 0:
        _STOP_("db 00h");
        _STOP_("db 00h");
        push(bp);
        push(r16[ax]);
        bp = sp;
        if (memory16get(cs*16+0xFFE) != 0x0000) {
            pc = 0x1075;
            break;
        }
        _STOP_("db 00h");
        if (r16[ax] < 0xc000) {
            pc = 0x107a;
            break;
        }
        _STOP_("db 00h");
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        _STOP_("db 00h");
        if (r16[ax] < 0xc000) {
            pc = 0x107a;
            break;
        }
    case 0x104f:
        bp = sp;
        _STOP_("db 00h");
        _STOP_("db 00h");
        if (memory[ds*16+bp + 0] != 0xfa) {
            pc = 0x1065;
            break;
        }
        bp = sp;
        _STOP_("db 00h");
        pc = 0x104f;
        break;
    case 0x1065:
        bp = sp;
        _STOP_("db 00h");
        memory16set(cs*16+0xFFE, r16[ax]);
        _STOP_("db 00h");
        memory16set(cs*16+0xFFC, r16[ax]);
    case 0x1075:
        _STOP_("db 00h");
    case 0x107a:
        r16[ax] = pop();
        bp = pop();
        return;
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_107d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.interrupt = false;
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        es = r16[ax];
        push(bios16get(es, 24));
        push(bios16get(es, 26));
        bios16set(es, 24, 0x10bc);
        bios16set(es, 26, cs);
        r8[al] = 0x01;
        r8[cl] = 0x20;
        r8[al] <<= r8[cl];
        if (r8[al] == 0x01) {
            pc = 0x10b1;
            break;
        }
        memory[cs*16+0x4] = 0x00;
        pc = 0x10c5;
        break;
    case 0x10b1:
        r16[ax] = r16[ax] ^ r16[ax];
        memory[cs*16+0x4] = 0x03;
        pc = 0x10c5;
        break;
        _STOP_("db 2eh");
        _STOP_("db c6h");
        _STOP_("db 06h");
        _STOP_("db 04h");
        _STOP_("db 00h");
        _STOP_("db 02h");
        _STOP_("db 83h");
        _STOP_("db c4h");
        _STOP_("db 06h");
    case 0x10c5:
        bios16set(es, 26, pop());
        bios16set(es, 24, pop());
        flags.interrupt = true;
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_10d3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* _sync();
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[ds*16+25882] = 0x00;
    case 0x10dd:
        /*
        r16[ax] = memory16get(ds*16+0x0431);
        r16[ax] = r16[ax] - memory16get(cs*16+0x16E0);
        if (r16s[ax] >= 0) {
            pc = 0x10e9;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x10e9:
        if (r16[ax] < 0x0002) {
            pc = 0x10dd;
            break;
        }
        if (r16[ax] > 0x0002) {
            pc = 0x10f7;
            break;
        }
        yield* sub_3243();
        */
        memory[ds*16+25882] += 1;
    case 0x10f7:
        r16[ax] = memory16get(cs*16+0x16E0);
        memory16set(ds*16+0x0431, r16[ax]);
        return;
    } while (1);
}
function* sub_10ff() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[dx] = 0x168f;
        ds = r16[dx];
        es = r16[dx];
        r16[bx] = r16[ax];
        if (memory[ds*16+r16[bx] + 1285] == 0x01) {
            pc = 0x111d;
            break;
        }
        memory16set(ds*16+0x0913, r16[ax]);
        pc = 0x111d;
        break;
    case 0x111d:
        memory[cs*16+0x16E4] |= 0x01;
        flags.interrupt = false;
        if (memory[cs*16+0x16E3] == 0x01) {
            pc = 0x1157;
            break;
        }
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16+r16[bx] + 2466];
        memory[ds*16+0x980] = r8[al];
        memory[ds*16+0x981] = r8[al];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 2434);
        memory[cs*16+0x70A2] = 0x01;
        memory16set(ds*16+0x0b07, r16[ax]);
        if (!(memory[cs*16+0x16E4] & 0x02)) {
            pc = 0x118d;
            break;
        }
        _in(r8[al], 97);
        r8[al] |= 0x03;
        out8(97, r8[al]);
        pc = 0x118d;
        break;
    case 0x1157:
        yield* sub_164f();
        r16[bx] = 0x0515;
        r16[cx] = r16[ax];
        if (r16[cx] == 0) {
            pc = 0x116b;
            break;
        }
    case 0x1161:
        r16[bx] += 1;
        r16[bx] += 1;
        if (memory16get(ds*16+r16[bx] + -2) != 0xffff) {
            pc = 0x1161;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1161;
            break;
        }
    case 0x116b:
        r16[cx] = r16[ax];
        r16[ax] = r16[bx];
        r16[bx] = 0x0675;
        if (r16[cx] == 0) {
            pc = 0x117e;
            break;
        }
    case 0x1174:
        r16[bx] += 1;
        r16[bx] += 1;
        if (memory16get(ds*16+r16[bx] + -2) != 0xffff) {
            pc = 0x1174;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1174;
            break;
        }
    case 0x117e:
        r16[si] = r16[bx];
    case 0x1180:
        r16[si] += 1;
        r16[si] += 1;
        if (memory16get(ds*16+r16[si]) != 0xffff) {
            pc = 0x1180;
            break;
        }
        r16[cx] = memory16get(ds*16+r16[si] - 2);
        yield* sub_1269();
    case 0x118d:
        flags.interrupt = true;
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1198() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[cs*16+0x2] == 0x00) {
            pc = 0x11d2;
            break;
        }
        r16[ax] = 0x2001;
        yield* sub_15a7();
        yield* sub_1610();
        if (flags.carry) {
            pc = 0x11d2;
            break;
        }
        flags.interrupt = false;
        r16[ax] = 0x0008;
        yield* sub_15a7();
        r16[ax] = 0x00bd;
        yield* sub_15a7();
        yield* sub_164f();
        memory[cs*16+0x16E3] = 0x01;
        flags.interrupt = true;
        pc = 0x11dc;
        break;
    case 0x11d2:
        r8[al] = 0xb6;
        out8(67, r8[al]);
        _in(r8[al], 97);
        r8[al] |= 0x03;
        out8(97, r8[al]);
    case 0x11dc:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_11e6() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(bp);
    r16[bx] = 0x168f;
    ds = r16[bx];
    memory16set(ds*16+370, 0x000f);
    r8[bl] = r8[al];
    r8[bh] = r8[bh] ^ r8[bh];
    r16[bx] <<= 1;
    r16[bx] = memory16get(ds*16+r16[bx] + 342);
    memory[ds*16+372] = 0x01;
    flags.interrupt = false;
    r8[dl] = 0x13;
    yield* sub_15de();
    r8[dl] -= 0x03;
    r16[bx] += 0x0005;
    yield* sub_15de();
    r8[ah] = memory[ds*16+r16[bx] + 5];
    r8[al] = 0xc6;
    yield* sub_15a7();
    flags.interrupt = true;
    bp = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_122b() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(bp);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x20b6;
    yield* sub_15a7();
    flags.interrupt = false;
    r16[bx] = 0x0b9a;
    r8[dl] = 0x13;
    yield* sub_15de();
    r8[dl] -= 0x03;
    r16[bx] += 0x0005;
    yield* sub_15de();
    r8[ah] = memory[ds*16+r16[bx] + 5];
    r8[al] = 0xc6;
    yield* sub_15a7();
    memory[ds*16+372] = 0x00;
    flags.interrupt = true;
    bp = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1269() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[si]);
        push(r16[di]);
        memory[cs*16+0x16E2] = 0x00;
        memory[ds*16+2433] = r8[cl];
        memory[ds*16+2432] = r8[cl];
        memory16set(ds*16+2327, r16[bx]);
        r16[di] = 0x09b3;
        r16[si] = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r16[dx] = r16[dx] ^ r16[dx];
        memory[ds*16+2482] = 0xff;
    case 0x128d:
        r16[cx] = 0x0011;
        rep_stosb_data_forward();
        r16[cx] = memory16get(ds*16+r16[si]);
        r16[si] += 1;
        r16[si] += 1;
        memory[ds*16+2482] += 1;
        memory16set(ds*16+r16[di] + -4, r16[cx]);
        memory[ds*16+r16[di] + -12] = r8[dl];
        r16[dx] += 1;
        if (r16[cx] != 0xffff) {
            pc = 0x128d;
            break;
        }
        r16[di] = pop();
        r16[si] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_12ab() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        flags.direction = false;
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[ds*16+2432] -= 1;
        if (memory[ds*16+2432] != 0) {
            pc = 0x12c8;
            break;
        }
        r8[al] = memory[ds*16+0x981];
        memory[ds*16+0x980] = r8[al];
        pc = 0x1331;
        break;
    case 0x12c8:
        memory16set(ds*16+2325, 0x09b3);
    case 0x12ce:
        r16[di] = memory16get(ds*16+2325);
        r16[si] = memory16get(ds*16+r16[di] + 13);
        if (r16[si] == 0xffff) {
            pc = 0x1331;
            break;
        }
        if (r16[si] == 0xfffe) {
            pc = 0x1327;
            break;
        }
        memory[ds*16+r16[di] + 7] -= 0x01;
        if (_FIXME_) {
            pc = 0x1327;
            break;
        }
    case 0x12e5:
        r8[bh] = r8[bh] ^ r8[bh];
        lodsb_data_forward();
        if (!(r8[al] & 0x80)) {
            pc = 0x12ef;
            break;
        }
        _STOP_("goto loc_1454");
    case 0x12ef:
        r8[ah] = r8[al];
        r8[ah] &= 0x0f;
        r8[cl] = r8[ah];
        _xchg(memory[ds*16+r16[di] + 8], r8[cl]);
        memory[ds*16+r16[di] + 15] = r8[cl];
        r8[cl] = 0x04;
        r8[al] >>= r8[cl];
        memory[ds*16+r16[di] + 9] = r8[al];
        r8[bl] = memory[ds*16+r16[di] + 8];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 2406);
        r8[cl] = memory[ds*16+r16[di] + 9];
        yield* sub_13c2();
        r8[al] = 0x60;
        r8[cl] = memory[ds*16+r16[di]];
        if (r8[cl] != 0x07) {
            pc = 0x1322;
            break;
        }
        r8[al] = 0x40;
        r8[cl] = memory[ds*16+r16[di] + 3];
    case 0x1322:
        r8[al] >>= r8[cl];
        memory[ds*16+r16[di] + 7] = r8[al];
    case 0x1327:
        memory16set(ds*16+r16[di] + 13, r16[si]);
        memory16set(ds*16+2325, memory16get(ds*16+2325) + 0x0011);
        pc = 0x12ce;
        break;
    case 0x1331:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_133b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[ds*16+372] == 0x00) {
            pc = 0x1381;
            break;
        }
        r8[al] = 0xbd;
        r8[ah] = 0xef;
        r8[ah] = r8[ah] & memory[ds*16+2329];
        yield* sub_15a7();
        r16[ax] = 0x57a6;
        yield* sub_15a7();
        r16[ax] = 0x01b6;
        yield* sub_15a7();
        r16[ax] = 0x05b6;
        yield* sub_15a7();
        r8[al] = 0xbd;
        r8[ah] = 0x10;
        r8[ah] = r8[ah] | memory[ds*16+2329];
        yield* sub_15a7();
        memory16set(ds*16+370, memory16get(ds*16+370) - 1);
        if (memory16get(ds*16+370) != 0) {
            pc = 0x1381;
            break;
        }
        yield* sub_122b();
    case 0x1381:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_138b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x16E4] != 0x03) {
            pc = 0x13a6;
            break;
        }
        if (memory[cs*16+0x16E3] == 0x00) {
            pc = 0x13a3;
            break;
        }
        yield* sub_133b();
        yield* sub_12ab();
        pc = 0x13a6;
        break;
    case 0x13a3:
        yield* sub_16e5();
    case 0x13a6:
        memory16set(cs*16+0x16E0, memory16get(cs*16+0x16E0) + 1);
        memory[cs*16+0x16E2] += 1;
        memory[cs*16+0x16E2] &= 0x03;
        if (memory[cs*16+0x16E2] == 0) {
            pc = 0x13bf;
            break;
        }
        push(r16[ax]);
        r8[al] = 0x20;
        out8(32, r8[al]);
        r16[ax] = pop();
        return;
    case 0x13bf:
    {yield* sub_0d27(); return; };
        return;
    } while (1);
}
function* sub_13c2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] |= r16[ax];
        if (r16[ax] != 0) {
            pc = 0x13c9;
            break;
        }
        pc = 0x144d;
        break;
    case 0x13c9:
        if (memory[ds*16+r16[di] + 6] < 0x0f) {
            pc = 0x1417;
            break;
        }
        r8[cl] += 0x0f;
        if (memory[ds*16+r16[di] + 6] == r8[cl]) {
            pc = 0x13e0;
            break;
        }
        yield* sub_14e9();
        r8[al] = memory[ds*16+r16[di] + 1];
        yield* sub_147d();
    case 0x13e0:
        r8[cl] = memory[ds*16+r16[di] + 5];
        r8[cl] -= 0x06;
        r8[ah] = 0x10;
        r8[ah] >>= r8[cl];
        r8[ah] = (~r8[ah]);
        r8[ah] = r8[ah] & memory[ds*16+2329];
        r8[al] = 0xbd;
        yield* sub_15a7();
        if (memory[ds*16+r16[di] + 5] != 0x06) {
            pc = 0x140d;
            break;
        }
        r16[ax] = 0x57a6;
        yield* sub_15a7();
        r16[ax] = 0x00b6;
        yield* sub_15a7();
        r16[ax] = 0x05b6;
        yield* sub_15a7();
    case 0x140d:
        r8[ah] = memory[ds*16+2329];
        r8[al] = 0xbd;
        yield* sub_15a7();
        return;
    case 0x1417:
        r8[cl] += 0x02;
        r16[dx] = r16[ax];
        r8[ah] = r8[dl];
        r8[al] = memory[ds*16+r16[di] + 5];
        r8[al] += 0xa0;
        yield* sub_15a7();
        if (memory[ds*16+r16[di] + 16] == 0x01) {
            pc = 0x143a;
            break;
        }
        r8[al] = memory[ds*16+r16[di] + 5];
        r8[al] += 0xb0;
        r8[ah] = 0x00;
        yield* sub_15a7();
        r16[dx] |= r16[dx];
        if (r16[dx] == 0) {
            pc = 0x144d;
            break;
        }
    case 0x143a:
        r8[ah] = r8[dh];
        r8[cl] <<= 1;
        r8[cl] <<= 1;
        r8[ah] |= r8[cl];
        r8[ah] |= 0x20;
        r8[al] = memory[ds*16+r16[di] + 5];
        r8[al] += 0xb0;
        yield* sub_15a7();
    case 0x144d:
        r8[al] = memory[ds*16+r16[di] + 4];
        memory[ds*16+r16[di] + 16] = r8[al];
        return;
    case 0x1454:
        r8[ah] = r8[al];
        r8[al] &= 0x0f;
        r8[cl] = 0x04;
        r8[ah] &= 0x70;
        r8[ah] >>= r8[cl];
        if (r8[ah] == 0x07) {
            pc = 0x146f;
            break;
        }
        r8[bl] = r8[ah];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 2330));
        _STOP_("goto loc_12e5");
    case 0x146f:
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 2344));
        _STOP_("goto loc_12e5");
        return;
    } while (1);
}
function* sub_147a() {
    memory[ds*16+r16[di]] = r8[al];
}
function* sub_147d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+r16[di] + 1] = r8[al];
        r8[al] += 1;
        r8[bl] = memory[ds*16+r16[di] + 6];
        r8[cl] = r8[bl];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+2327);
        r16[bx] = memory16get(ds*16+r16[bx]);
        if (r8[cl] < 0x0f) {
            pc = 0x1497;
            break;
        }
        r16[bx] += 1;
    case 0x1497:
        r8[cl] = r8[al];
        r8[ch] = r8[ch] ^ r8[ch];
        r8[ah] = memory[ds*16+r16[bx] + 2];
        r8[ah] &= 0x3f;
        r8[ah] -= 0x3f;
        r8[ah] = -r8[ah];
        r8[al] = r8[al] ^ r8[al];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        _mul16(r16[cx]);
        r8[al] = 0x3f;
        r8[al] -= r8[ah];
        r8[bl] = memory[ds*16+r16[di] + 5];
        r8[bh] = 0x00;
        r8[bl] = memory[ds*16+r16[bx] + 2395];
        if (r8[bl] > 0x0d) {
            pc = 0x14c7;
            break;
        }
        r8[bl] += 0x03;
    case 0x14c7:
        r8[bl] = memory[ds*16+r16[bx] + 2376];
        r8[ah] = r8[al];
        r8[al] = r8[bl];
        r8[al] += 0x40;
        yield* sub_15a7();
        return;
    } while (1);
}
function* sub_14d5() {
    memory[ds*16+r16[di] + 2] = r8[al];
}
function* sub_14d9() {
    memory[ds*16+r16[di] + 3] = r8[al];
}
function* sub_14dd() {
    memory[ds*16+r16[di] + 4] = r8[al];
}
function* sub_14e1() {
    memory[ds*16+r16[di] + 5] = r8[al];
}
function* sub_14e5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] != 0x01)
            _STOP_("goto loc_1512");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_14e9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16+r16[di] + 9];
        r8[bh] = r8[bh] ^ r8[bh];
        r8[bl] += 0x0f;
        memory[ds*16+r16[di] + 6] = r8[bl];
        r16[bx] <<= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+2327);
        r16[bx] = memory16get(ds*16+r16[bx]);
        r8[cl] = memory[ds*16+r16[bx]];
        memory[ds*16+r16[di] + 5] = r8[cl];
        r8[ah] = 0x10;
        r8[cl] -= 0x06;
        r8[ah] >>= r8[cl];
        r8[ah] = r8[ah] | memory[ds*16+2329];
        memory[ds*16+2329] = r8[ah];
        pc = 0x1534;
        break;
    case 0x1512:
        if (_FIXME_) {
            pc = 0x1516;
            break;
        }
        r8[al] -= 1;
    case 0x1516:
        memory[ds*16+r16[di] + 6] = r8[al];
        r8[cl] = memory[ds*16+r16[di] + 5];
        flags.carry = r8[cl] < 0x06;
        r8[cl] -= 0x06;
        if (flags.carry) {
            pc = 0x1534;
            break;
        }
        r8[ah] = 0x10;
        r8[ah] >>= r8[cl];
        r8[ah] = (~r8[ah]);
        r8[ah] = r8[ah] & memory[ds*16+2329];
        memory[ds*16+2329] = r8[ah];
        r8[al] = 0xbd;
        yield* sub_15a7();
    case 0x1534:
        r8[bl] = memory[ds*16+r16[di] + 5];
        r8[bh] = r8[bh] ^ r8[bh];
        r8[bl] = memory[ds*16+r16[bx] + 2395];
        if (memory[ds*16+r16[di] + 5] > 0x06) {
            pc = 0x1546;
            break;
        }
        r8[bl] += 0x03;
    case 0x1546:
        r8[dl] = memory[ds*16+r16[bx] + 2376];
        r8[bl] = memory[ds*16+r16[di] + 6];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= 1;
        r16[bx] = r16[bx] + memory16get(ds*16+2327);
        r16[bx] = memory16get(ds*16+r16[bx]);
        if (memory[ds*16+r16[di] + 6] < 0x0f) {
            pc = 0x155e;
            break;
        }
        r16[bx] += 1;
    case 0x155e:
        yield* sub_15de();
        r8[dl] -= 0x03;
        r16[bx] += 0x0005;
        if (memory[ds*16+r16[di] + 5] >= 0x07) {
            pc = 0x157b;
            break;
        }
        yield* sub_15de();
        r8[ah] = memory[ds*16+r16[bx] + 5];
        r8[al] = memory[ds*16+r16[di] + 5];
        r8[al] += 0xc0;
        yield* sub_15a7();
    case 0x157b:
        return;
    } while (1);
}
function* sub_157c() {
    _lea(ax, ds, r16[si] + 2);
    memory16set(ds*16+r16[di] + 10, r16[ax]);
    r16[si] = memory16get(ds*16+r16[si]);
}
function* sub_1585() {
    r16[si] = memory16get(ds*16+r16[di] + 10);
}
function* sub_1589() {
    r16[si] = memory16get(ds*16+r16[si]);
}
function* sub_158c() {
    lodsb_data_forward();
    memory[ds*16+r16[di] + 12] = r8[al];
}
function* sub_1591() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+r16[di] + 12] -= 1;
        if (memory[ds*16+r16[di] + 12] == 0) {
            pc = 0x1599;
            break;
        }
        r16[si] = memory16get(ds*16+r16[si]);
        return;
    case 0x1599:
        r16[si] += 1;
        r16[si] += 1;
        return;
    } while (1);
}
function* sub_159c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = pop();
        r16[si] = 0xfffe;
        memory[ds*16+2482] -= 1;
        _STOP_("goto loc_1327");
        return;
    } while (1);
}
function* sub_15a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        push(r16[ax]);
        push(r16[cx]);
        if (memory[cs*16+0x4] >= 0x03) {
            pc = 0x15c8;
            break;
        }
        r16[dx] = 0x0388;
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0005;
    case 0x15b9:
        if (--r16[cx]) {
            pc = 0x15b9;
            break;
        }
        r16[dx] += 1;
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0023;
    case 0x15c2:
        if (--r16[cx]) {
            pc = 0x15c2;
            break;
        }
        r16[cx] = pop();
        r16[ax] = pop();
        r16[dx] = pop();
        return;
    case 0x15c8:
        r16[dx] = 0x0388;
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0014;
    case 0x15cf:
        if (--r16[cx]) {
            pc = 0x15cf;
            break;
        }
        r16[dx] += 1;
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r16[cx] = 0x008c;
    case 0x15d8:
        if (--r16[cx]) {
            pc = 0x15d8;
            break;
        }
        r16[cx] = pop();
        r16[ax] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_15de() {
    r8[ah] = memory[ds*16+r16[bx]];
    r8[al] = r8[dl];
    r8[al] += 0x60;
    yield* sub_15a7();
    r8[ah] = memory[ds*16+r16[bx] + 1];
    r8[al] = r8[dl];
    r8[al] += 0x80;
    yield* sub_15a7();
    r8[ah] = memory[ds*16+r16[bx] + 2];
    r8[al] = r8[dl];
    r8[al] += 0x40;
    yield* sub_15a7();
    r8[ah] = memory[ds*16+r16[bx] + 3];
    r8[al] = r8[dl];
    r8[al] += 0x20;
    yield* sub_15a7();
    r8[ah] = memory[ds*16+r16[bx] + 4];
    r8[al] = r8[dl];
    r8[al] += 0xe0;
    yield* sub_15a7();
}
function* sub_1610() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x6304;
        yield* sub_15a7();
        r16[dx] = 0x0388;
        r16[cx] = 0x2000;
    case 0x161c:
        /*
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x60;
        if (r8[al] != 0) {
            pc = 0x164d;
            break;
        }
        if (--r16[cx]) {
            pc = 0x161c;
            break;
        }
        */
        r16[ax] = 0x2304;
        yield* sub_15a7();
        r16[cx] = 0x9fff;
    case 0x162c:
        /*
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x60;
        if (r8[al] == 0x40) {
            pc = 0x1637;
            break;
        }
        if (--r16[cx]) {
            pc = 0x162c;
            break;
        }
        pc = 0x164d;
        break;
        */
    case 0x1637:
        r16[ax] = 0x4304;
        yield* sub_15a7();
        r16[cx] = 0x9fff;
    case 0x1640:
        /*
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x60;
        if (r8[al] == 0x20) {
            pc = 0x164b;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1640;
            break;
        }
        pc = 0x164d;
        break;
        */
    case 0x164b:
        flags.carry = false;
        return;
    case 0x164d:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_164f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = 0x00b0;
    case 0x1653:
        yield* sub_15a7();
        r16[ax] += 1;
        if (r8[al] < 0xb9) {
            pc = 0x1653;
            break;
        }
        r16[ax] = 0x00a0;
    case 0x165e:
        yield* sub_15a7();
        r16[ax] += 1;
        if (r8[al] < 0xb9) {
            pc = 0x165e;
            break;
        }
        r16[ax] = 0x0008;
        yield* sub_15a7();
        r16[ax] = 0x00bd;
        yield* sub_15a7();
        r16[ax] = 0x3f40;
        yield* sub_15a7();
        r16[ax] = 0x3f41;
        yield* sub_15a7();
        r16[ax] = 0x3f42;
        yield* sub_15a7();
        r16[ax] = 0x3f43;
        yield* sub_15a7();
        r16[ax] = 0x3f44;
        yield* sub_15a7();
        r16[ax] = 0x3f45;
        yield* sub_15a7();
        r16[ax] = 0x3f48;
        yield* sub_15a7();
        r16[ax] = 0x3f49;
        yield* sub_15a7();
        r16[ax] = 0x3f4a;
        yield* sub_15a7();
        r16[ax] = 0x3f4b;
        yield* sub_15a7();
        r16[ax] = 0x3f4c;
        yield* sub_15a7();
        r16[ax] = 0x3f4d;
        yield* sub_15a7();
        r16[ax] = 0x3f50;
        yield* sub_15a7();
        r16[ax] = 0x3f51;
        yield* sub_15a7();
        r16[ax] = 0x3f52;
        yield* sub_15a7();
        r16[ax] = 0x3f53;
        yield* sub_15a7();
        r16[ax] = 0x3f54;
        yield* sub_15a7();
        r16[ax] = 0x3f55;
        yield* sub_15a7();
        r16[ax] = pop();
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 02h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_16e5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        flags.direction = false;
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = memory16get(ds*16+2823);
        if (r16[si] < 0xfffe) {
            pc = 0x1700;
            break;
        }
        pc = 0x1783;
        break;
    case 0x1700:
        if (!(memory[cs*16+0x16E4] & 0x02)) {
            pc = 0x1783;
            break;
        }
        memory[ds*16+2432] -= 1;
        if (memory[ds*16+2432] != 0) {
            pc = 0x1716;
            break;
        }
        r8[al] = memory[ds*16+0x981];
        memory[ds*16+0x980] = r8[al];
        pc = 0x1783;
        break;
    case 0x1716:
        if (memory[ds*16+2825] != 0x02) {
            pc = 0x172f;
            break;
        }
        if (memory[ds*16+2835] == 0x01) {
            pc = 0x172f;
            break;
        }
        r16[ax] = 0x3a98;
        out8(66, r8[al]);
        r8[al] = r8[ah];
        out8(66, r8[al]);
        pc = 0x172f;
        break;
    case 0x172f:
        memory[ds*16+2825] -= 0x01;
        if (_FIXME_) {
            pc = 0x1783;
            break;
        }
    case 0x1736:
        r8[bh] = r8[bh] ^ r8[bh];
        lodsb_data_forward();
        if (r8[al] & 0x80) {
            pc = 0x1791;
            break;
        }
        r8[ah] = r8[al];
        r8[ah] &= 0x0f;
        memory[ds*16+2830] = r8[ah];
        r8[cl] = 0x04;
        r8[al] >>= r8[cl];
        memory[ds*16+0xb0d] = r8[al];
        r8[al] = 0x10;
        r8[cl] = memory[ds*16+2831];
        r8[al] >>= r8[cl];
        r8[bl] = memory[ds*16+2830];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 2848);
        r8[cl] = memory[ds*16+2829];
        r16[ax] >>= r8[cl];
        out8(66, r8[al]);
        r8[al] = r8[ah];
        out8(66, r8[al]);
        r8[al] = 0x60;
        r8[cl] = memory[ds*16+2831];
        if (r8[cl] != 0x07) {
            pc = 0x177e;
            break;
        }
        r8[al] = 0x40;
        r8[cl] = memory[ds*16+2834];
    case 0x177e:
        r8[al] >>= r8[cl];
        memory[ds*16+0xb09] = r8[al];
    case 0x1783:
        memory16set(ds*16+2823, r16[si]);
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x1791:
        r8[ah] = r8[al];
        r8[al] &= 0x0f;
        r8[cl] = 0x04;
        r8[ah] &= 0x70;
        r8[ah] >>= r8[cl];
        if (r8[ah] == 0x07) {
            pc = 0x17a9;
            break;
        }
        r8[bl] = r8[ah];
        memory[ds*16+r16[bx] + 2831] = r8[al];
        pc = 0x1736;
        break;
    case 0x17a9:
        if (r8[al] == 0x0f) {
            pc = 0x17b8;
            break;
        }
        r8[bl] = r8[al];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 2838));
        pc = 0x1736;
        break;
    case 0x17b8:
        _in(r8[al], 97);
        r8[al] &= 0xfc;
        out8(97, r8[al]);
        r16[si] = 0xfffe;
        memory[ds*16+2482] -= 1;
        pc = 0x1783;
        break;
        return;
    } while (1);
}
function* sub_17c7() {
    _lea(ax, ds, r16[si] + 2);
    memory16set(ds*16+0x0b0a, r16[ax]);
    r16[si] = memory16get(ds*16+r16[si]);
}
function* sub_17d0() {
    r16[si] = memory16get(ds*16+2826);
}
function* sub_17d5() {
    r16[si] = memory16get(ds*16+r16[si]);
}
function* sub_17d8() {
    r8[al] = memory[ds*16+r16[si]];
    memory[ds*16+0xb0c] = r8[al];
    r16[si] += 1;
}
function* sub_17df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+2828] -= 1;
        if (memory[ds*16+2828] == 0) {
            pc = 0x17e8;
            break;
        }
        r16[si] = memory16get(ds*16+r16[si]);
        return;
    case 0x17e8:
        r16[si] += 1;
        r16[si] += 1;
        return;
    } while (1);
}
function* sub_17eb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* _sync();
        return;
    case 0x17eb:
        r8[al] = memory[cs*16+0x16E4];
        r8[al] &= 0x03;
        if (r8[al] != 0x03) {
            pc = 0x17fc;
            break;
        }
        if (memory[ds*16+2482] != 0x00) {
            pc = 0x17eb;
            break;
        }
    case 0x17fc:
        return;
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_17fe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[ah] = 0x04;
        interrupt(26);
        if (flags.carry) {
            pc = 0x183d;
            break;
        }
        push(r16[dx]);
        r16[ax] = r16[ax] ^ r16[ax];
        r8[bl] = 0x04;
        bp = 0x000a;
    case 0x1811:
        _mul16(bp);
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        _rcl8(dh, 1);
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        _rcl8(dh, 1);
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        _rcl8(dh, 1);
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        _rcl8(dh, 1);
        r8[al] += r8[dh];
        r8[bl] -= 1;
        if (r8[bl] != 0) {
            pc = 0x1811;
            break;
        }
        r16[dx] = pop();
        if (r16[ax] >= 0x0813) {
            pc = 0x183d;
            break;
        }
        if (r16[ax] != 0x07c8) {
            pc = 0x183a;
            break;
        }
        if (r8[dh] >= 0x06) {
            pc = 0x183a;
            break;
        }
        r16[ax] -= 1;
    case 0x183a:
        memory16set(ds*16+0x000a, r16[ax]);
    case 0x183d:
        return;
    case 0x183e:
        return;
    } while (1);
}
function* sub_183f() {
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_27df();
    yield* sub_038a();
    memory16set(ds*16+501, 0x0005);
    memory16set(ds*16+503, 0x0960);
    r16[si] = 0x4e6e;
    yield* sub_0488();
    memory16set(ds*16+501, 0x0000);
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    r16[si] = 0x4e7a;
    yield* sub_0488();
    r16[dx] = memory16get(ds*16+10);
    yield* sub_0423();
    r16[si] = 0x4e9a;
    yield* sub_0488();
    memory16set(ds*16+501, 0x0001);
    memory16set(ds*16+503, 0x1680);
    r16[si] = 0x4e9e;
    yield* sub_0488();
    memory16set(ds*16+501, 0x0003);
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    r16[si] = 0x4ec3;
    yield* sub_0488();
    yield* sub_03f2();
    yield* sub_27df();
    return;
}
function* sub_18af() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x45d];
        r8[al] = r8[al] & memory[ds*16+1144];
        r8[ah] = r8[al];
        r8[ah] = r8[ah] & memory[ds*16+1105];
        if (r8[ah] != 0) {
            pc = 0x18c4;
            break;
        }
        r8[al] = r8[al] & memory[ds*16+1104];
        if (r8[al] == 0)
            return;
    case 0x18c4:
        r16[bx] = 0x0001;
        r8[al] = r8[al] ^ r8[al];
    case 0x18c9:
        if (r8[bl] == 0x10) {
            pc = 0x18e3;
            break;
        }
        if (r8[bl] == 0x11) {
            pc = 0x18e3;
            break;
        }
        if (r8[bl] == 0x1d) {
            pc = 0x18e3;
            break;
        }
        if (r8[bl] == 0x38) {
            pc = 0x18e3;
            break;
        }
        r8[al] = r8[al] | memory[ds*16+r16[bx] + 1088];
        if (r8[al] != 0)
            _STOP_("goto loc_18ae");
    case 0x18e3:
        r16[bx] += 1;
        if (r8[bl] < 0x7f) {
            pc = 0x18c9;
            break;
        }
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        if (memory[ds*16+1104] == 0x00) {
            pc = 0x1909;
            break;
        }
        if (memory[ds*16+1050] < 0x0a) {
            pc = 0x1909;
            break;
        }
        memory[ds*16+1051] += 1;
        memory[ds*16+1050] -= 0x0a;
    case 0x1909:
        yield* sub_1958();
        yield* sub_03f2();
        yield* sub_03ae();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_191c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_3160();
        yield* sub_1958();
        memory16set(ds*16+1084, 0x0000);
    case 0x1936:
        yield* sub_0805();
        if (memory[ds*16+1067] != 0x00) {
            pc = 0x1948;
            break;
        }
        if (memory16get(ds*16+1084) < 0x0168) {
            pc = 0x1936;
            break;
        }
    case 0x1948:
        memory16set(ds*16+1084, 0x0870);
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1958() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(bp);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x0009;
    yield* sub_10ff();
    yield* sub_2811();
    yield* sub_038a();
    memory16set(ds*16+501, 0x0005);
    memory16set(ds*16+503, 0x03c0);
    r16[si] = 0x4ee3;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f02;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f21;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f40;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f5f;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f7e;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4f9d;
    yield* sub_0488();
    memory16set(ds*16+503, memory16get(ds*16+503) + 0x01e0);
    memory16set(ds*16+501, memory16get(ds*16+501) - 0x001e);
    r16[si] = 0x4fbc;
    yield* sub_0488();
    memory16set(ds*16+501, 0x000f);
    memory16set(ds*16+503, 0x1770);
    r16[si] = 0x4fdb;
    yield* sub_0488();
    memory16set(ds*16+501, 0x0000);
    memory16set(ds*16+503, 0x1a40);
    r16[si] = 0x4fe5;
    yield* sub_0488();
    bp = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
}
function* sub_1a2a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+0x45d];
        r8[al] = r8[al] & memory[ds*16+1144];
        r8[al] = r8[al] & memory[ds*16+1106];
        if (r8[al] == 0)
            return;
        r16[bx] = 0x0001;
        r8[al] = r8[al] ^ r8[al];
    case 0x1a3c:
        if (r8[bl] == 0x12) {
            pc = 0x1a51;
            break;
        }
        if (r8[bl] == 0x1d) {
            pc = 0x1a51;
            break;
        }
        if (r8[bl] == 0x38) {
            pc = 0x1a51;
            break;
        }
        r8[al] = r8[al] | memory[ds*16+r16[bx] + 1088];
        if (r8[al] != 0)
            return;
    case 0x1a51:
        r16[bx] += 1;
        if (r8[bl] < 0x7f) {
            pc = 0x1a3c;
            break;
        }
        _STOP_("goto loc_1a61");
        return;
    } while (1);
}
function* sub_1a59() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+10) < 0x07c8)
            _STOP_("goto loc_1a29");
    case 0x1a61:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[dx] = 0x500e;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x4e52, r16[ax]);
        yield* sub_1a8d();
        r16[ax] = 0x0009;
        yield* sub_10ff();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1a8d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_3160();
        if (memory[cs*16+0x1] != 0x05) {
            pc = 0x1ae4;
            break;
        }
        r16[ax] = 0x000d;
        interrupt(16);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r16[dx] = 0x4e54;
        r16[ax] = 0x1002;
        interrupt(16);
        r16[dx] = 0x03c8;
        r8[al] = r8[al] ^ r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[cx] = 0x0010;
        r8[al] = r8[al] ^ r8[al];
    case 0x1ab8:
        out8(r16[dx], r8[al]);
        pc = 0x1abb;
        break;
    case 0x1abb:
        out8(r16[dx], r8[al]);
        pc = 0x1abe;
        break;
    case 0x1abe:
        out8(r16[dx], r8[al]);
        r8[al] += 0x04;
        if (--r16[cx]) {
            pc = 0x1ab8;
            break;
        }
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = memory16get(ds*16+20050);
        r16[si] = r16[si] ^ r16[si];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
    case 0x1ad4:
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x0fa0;
        r16[di] = r16[di] ^ r16[di];
        rep_movsw_data_data_forward();
        r8[ah] <<= 1;
        if (r8[ah] <= 0x08) {
            pc = 0x1ad4;
            break;
        }
        return;
    case 0x1ae4:
        if (memory[cs*16+0x1] == 0x00) {
            pc = 0x1af1;
            break;
        }
        r16[ax] = 0x0006;
        interrupt(16);
    case 0x1af1:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[cx] = 0x3e80;
        rep_stosw_data_forward();
        memory[ds*16+20074] = 0x00;
        memory16set(ds*16+20072, 0x0000);
        memory[ds*16+20077] = 0x00;
        memory16set(ds*16+20075, 0x0000);
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x1b17:
        yield* sub_1bb6();
        push(r16[ax]);
        r16[bx] += r16[ax];
        if (r16s[bx] < signed16(0x0010)) {
            pc = 0x1b30;
            break;
        }
        yield* sub_1b83();
        yield* sub_1c09();
        r16[ax] &= 0x0001;
        r16[bx] -= 0x0010;
        r16[bx] += r16[ax];
    case 0x1b30:
        memory16set(ds*16+20072, memory16get(ds*16+20072) + 1);
        r16[ax] = pop();
        r16[bx] += r16[ax];
        if (r16s[bx] < signed16(0x0010)) {
            pc = 0x1b4a;
            break;
        }
        yield* sub_1b83();
        yield* sub_1c09();
        r16[ax] &= 0x0001;
        r16[bx] -= 0x0010;
        r16[bx] += r16[ax];
    case 0x1b4a:
        memory16set(ds*16+20072, memory16get(ds*16+20072) + 1);
        if (memory16get(ds*16+20072) < 0x0280) {
            pc = 0x1b67;
            break;
        }
        memory16set(ds*16+20072, 0x0000);
        memory[ds*16+20074] += 1;
        if (memory[ds*16+20074] >= 0xc8) {
            pc = 0x1b82;
            break;
        }
    case 0x1b67:
        if (memory16get(ds*16+20075) < 0x0140) {
            pc = 0x1b80;
            break;
        }
        memory16set(ds*16+20075, 0x0000);
        memory[ds*16+20077] += 1;
        if (memory[ds*16+20077] >= 0xc8) {
            pc = 0x1b82;
            break;
        }
    case 0x1b80:
        pc = 0x1b17;
        break;
    case 0x1b82:
        return;
    } while (1);
}
function* sub_1b83() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[di]);
        r8[al] = memory[ds*16+0x4e6a];
        r8[al] >>= 1;
        r8[ah] = 0x50;
        _mul8(r8[ah]);
        if (!(memory[ds*16+20074] & 0x01)) {
            pc = 0x1b99;
            break;
        }
        r16[ax] += 0x2000;
    case 0x1b99:
        r16[di] = r16[ax];
        r16[ax] = memory16get(ds*16+0x4e68);
        r8[cl] = 0x03;
        r16[ax] >>= r8[cl];
        r16[di] += r16[ax];
        r8[cl] = memory[ds*16+20072];
        r8[cl] &= 0x07;
        r8[ah] = 0x80;
        r8[ah] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[ah];
        r16[di] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1bb6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[di]);
        r8[al] = memory[ds*16+0x4e6d];
        r8[ah] = 0x28;
        _mul8(r8[ah]);
        r16[di] = r16[di] ^ r16[di];
        r16[di] &= 0xfff0;
        r16[di] += r16[ax];
        r16[ax] = memory16get(ds*16+0x4e6b);
        r8[cl] = 0x03;
        r16[ax] >>= r8[cl];
        r16[di] += r16[ax];
        r8[cl] = memory[ds*16+20075];
        r8[cl] &= 0x07;
        r8[ah] = 0x80;
        r8[ah] >>= r8[cl];
        r8[al] = r8[al] ^ r8[al];
        push(ds);
        ds = memory16get(ds*16+20050);
        if (!(memory[ds*16+r16[di]] & r8[ah])) {
            pc = 0x1be7;
            break;
        }
        r8[al] += 1;
    case 0x1be7:
        if (!(memory[ds*16+r16[di] + 8000] & r8[ah])) {
            pc = 0x1bef;
            break;
        }
        r8[al] += 0x02;
    case 0x1bef:
        if (!(memory[ds*16+r16[di] + 16000] & r8[ah])) {
            pc = 0x1bf7;
            break;
        }
        r8[al] += 0x04;
    case 0x1bf7:
        if (!(memory[ds*16+r16[di] + 24000] & r8[ah])) {
            pc = 0x1bff;
            break;
        }
        r8[al] += 0x08;
    case 0x1bff:
        ds = pop();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+20075, memory16get(ds*16+20075) + 1);
        r16[di] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_1c09() {
    r16[ax] = memory16get(ds*16+0x4e65);
    r16[ax] += 0x9248;
    ror16(ax, 1);
    ror16(ax, 1);
    ror16(ax, 1);
    memory16set(ds*16+0x4e65, r16[ax]);
    return;
    _STOP_("db 00h");
    _STOP_("sp-trace-fail");
    _STOP_("continues");
}
function* sub_1c1a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x1c2f;
            break;
        }
        push(r16[dx]);
        push(r16[ax]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r8[dl] = 0xc0;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
    case 0x1c2f:
        return;
    } while (1);
}
function* sub_1c30() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x1c45;
            break;
        }
        push(r16[dx]);
        push(r16[ax]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r8[dl] = 0xc0;
        r8[al] = r8[al] ^ r8[al];
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
    case 0x1c45:
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_1c61() {
    collect = [];
/*
    push(ds);
    ds = 0x168f;
    for (var i=0x567e; i >= 0x527c; i-=0x0012)
    {
       if (memory16get(ds*16 + i + 4) != 0xffff)
       {
         var bb = memory16get(ds*16+i + 4);
         if (memory16get(ds*16+bb + 0x5aa4) == 0xa47) console.log("hit!");
         var rel8x = memory[ds*16+bb + 26927];
         if (rel8x & 0x0080) rel8x |= 0xff00;
         
         var rel8y = memory[ds*16+bb + 26928];
         if (rel8y & 0x0080) rel8y |= 0xff00;

         //in: ds, bx, si(i), cs(const)
         collect.push({
           x:(-rel8x + memory16get(ds*16+i)) - (memory16get(ds*16+21104)<<4), 
           y:rel8y + memory16get(ds*16+i + 2) + 1 - (memory16get(ds*16+21106) << 4) - (memory16get(ds*16+bb + 26213)>>8),
           w:(memory16get(ds*16+bb + 26213) & 0xff) >> memory[cs*16+0x0],
           h:memory16get(ds*16+bb + 26213)>>8, 
           o:memory16get(ds*16+bb + 0x5aa4),
           s:memory16get(ds*16+bb + 0x5dc4),
           t:memory[cs*16 + 0x1C48]&128
          });

       }
    }
    ds = pop();
*/
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = 0x567e;
    case 0x1c72:
        memory16set(ds*16+21114, r16[si]);
        if (memory16get(ds*16+r16[si] + 4) != 0xffff) {
            pc = 0x1c7f;
            break;
        }
        pc = 0x24a9;
        break;
    case 0x1c7f:
        yield* loc_1c7f();
    case 0x24a9:
        flags.direction = false;
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = memory16get(ds*16+21114);
        r16[si] -= 0x0012;
        if (r16[si] < 0x527c) {
            pc = 0x24bf;
            break;
        }
        pc = 0x1c72;
        break;
    case 0x24bf:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* loc_1c7f() {
    var pc = 0;
    do switch (pc) {
    case 0:
/*
       //in: ds, bx, si, cs
       var rel8x = memory[ds*16+r16[bx] + 26927];
       if (rel8x & 0x0080) rel8x |= 0xff00;
       
       var rel8y = memory[ds*16+r16[bx] + 26928];
       if (rel8y & 0x0080) rel8y |= 0xff00;
       collect.push({
         x:(-rel8x + memory16get(ds*16+r16[si])) - (memory16get(ds*16+21104)<<4), 
         y:rel8y + memory16get(ds*16+r16[si] + 2) + 1 - (memory16get(ds*16+21106) << 4) - (memory16get(ds*16+r16[bx] + 26213)>>8),
         w:(memory16get(ds*16+r16[bx] + 26213) & 0xff) >> memory[cs*16+0x0],
         h:memory16get(ds*16+r16[bx] + 26213)>>8, 
         o:memory16get(ds*16+r16[bx] + 0x5aa4),
         s:memory16get(ds*16+r16[bx] + 0x5dc4),
         t:memory[cs*16 + 0x1C48]&128
        });

*/

        r16[ax] = r16[ax] ^ r16[ax];
        memory[cs*16+0x1C49] = r8[al];
        memory[cs*16+0x1C53] = r8[al];
        memory[cs*16+0x1C56] = r8[al];
        memory[cs*16+0x1C57] = r8[al];
        memory16set(cs*16+0x1C46, r16[ax]);
        memory[ds*16+r16[si] + 5] &= 0xdf;
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        flags.carry = !!(r16[bx] & 0x8000);
        r16[bx] <<= 1;
        _rclm8(cs*16+0x1C48, 1);
        r8[al] = 0x01;
        if (!(r8[bh] & 0x80)) {
            pc = 0x1caf;
            break;
        }
        r8[al] = 0x41;
        r8[bh] &= 0x7f;

    case 0x1caf:

       var rel8x = memory[ds*16+r16[bx] + 26927];
       if (rel8x & 0x0080) rel8x |= 0xff00;
       
       var rel8y = memory[ds*16+r16[bx] + 26928];
       if (rel8y & 0x0080) rel8y |= 0xff00;
       collect.push({
         x:(-rel8x + memory16get(ds*16+r16[si])) - (memory16get(ds*16+21104)<<4), 
         y:rel8y + memory16get(ds*16+r16[si] + 2) + 1 - (memory16get(ds*16+21106) << 4) - (memory16get(ds*16+r16[bx] + 26213)>>8),
         w:(memory16get(ds*16+r16[bx] + 26213) & 0xff) >> memory[cs*16+0x0],
         h:memory16get(ds*16+r16[bx] + 26213)>>8, 
         o:memory16get(ds*16+r16[bx] + 0x5aa4),
         s:memory16get(ds*16+r16[bx] + 0x5dc4),
         t:memory[cs*16 + 0x1C48]&1
        });


        memory[cs*16+0x1C5E] = r8[al];
        r16[dx] = memory16get(ds*16+r16[bx] + 26213);


        r8[al] = memory[ds*16+r16[bx] + 26927];
        if (!(memory[cs*16+0x1C48] & 0x01)) {
            pc = 0x1cc9;
            break;
        }
        r8[al] = r8[al] - memory[ds*16+r16[bx] + 26213];
        r8[al] = -r8[al];
    case 0x1cc9:
        _cbw();
        r16[ax] = -r16[ax];
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si]);
        r16[cx] = memory16get(ds*16+21104);
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[ax] -= r16[cx];
        r16[cx] = r16[ax];


/*
       var rel8x = memory[ds*16+r16[bx] + 26927];
       if (rel8x & 0x0080) rel8x |= 0xff00;
       
       var rel8y = memory[ds*16+r16[bx] + 26928];
       if (rel8y & 0x0080) rel8y |= 0xff00;
       collect.push({
         x:(-rel8x + memory16get(ds*16+r16[si])) - (memory16get(ds*16+21104)<<4), 
         y:rel8y + memory16get(ds*16+r16[si] + 2) + 1 - (memory16get(ds*16+21106) << 4) - r8[dh],//memory16get(cs*16 + 0x1C4E),
         w:r8[dl] >> memory[cs*16+0x0], //memory[cs*16 + 0x1C4A],
         h:r8[dh], //memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 0x5aa4) + 0, //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 0x5dc4), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });
*/
        memory16set(cs*16+0x1C50, r16[ax]);
        if (r16s[ax] < signed16(0x0140)) {
            pc = 0x1cea;
            break;
        }
        return;
    case 0x1cea:
        flags.carry = (r8[cl] + r8[dl]) >= 0x100;
        r8[cl] += r8[dl];
        r8[ch] = r8[ch] + 0x00 + flags.carry;
        if ((r8[ch] & 0x80) == 0) {
            pc = 0x1cf4;
            break;
        }
        return;
    case 0x1cf4:
/*
push(r16[ax]);
        r8[al] = memory[ds*16+r16[bx] + 26928];
        _cbw();

        r16[ax] += memory16get(ds*16+r16[si] + 2) + 1;
        r16[ax] -= memory16get(ds*16+21106) << 4;

       collect.push({
         x:memory16get(cs*16 + 0x1C50), 
         y:r16[ax] - r8[dh],//memory16get(cs*16 + 0x1C4E),
         w:r8[dl] >> memory[cs*16+0x0], //memory[cs*16 + 0x1C4A],
         h:r8[dh], //memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 0x5aa4) + 0, //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 0x5dc4), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });
r16[ax] = pop();
*/

        r8[al] = memory[ds*16+r16[bx] + 26928];
        _cbw();
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 2);
        r16[ax] += 1;
        r16[cx] = memory16get(ds*16+21106);
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        flags.carry2 = r16s[ax] > r16s[cx];
        r16[ax] -= r16[cx];
/*
       collect.push({
         x:memory16get(cs*16 + 0x1C50), 
         y:r16[ax] - r8[dh],//memory16get(cs*16 + 0x1C4E),
         w:r8[dl] >> memory[cs*16+0x0], //memory[cs*16 + 0x1C4A],
         h:r8[dh], //memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 0x5aa4) + 0, //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 0x5dc4), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });
*/
        if (flags.carry2) {
            pc = 0x1d10;
            break;
        }
        return;
    case 0x1d10:
        memory16set(ds*16+0x5278, r16[ax]);
        memory[cs*16+0x1C52] = r8[dh];
        memory[cs*16+0x1C4C] = r8[dh];
/*
       collect.push({
         x:memory16get(cs*16 + 0x1C50), 
         y:r16[ax] - r8[dh],//memory16get(cs*16 + 0x1C4E),
         w:r8[dl] >> memory[cs*16+0x0], //memory[cs*16 + 0x1C4A],
         h:memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 0x5aa4) + 0, //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 0x5dc4), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });
*/
        flags.carry = r8[al] < r8[dh];
        r8[al] -= r8[dh];
        r8[ah] -= 0x00 + flags.carry;
        if (r16s[ax] < signed16(0x00c0)) {
            pc = 0x1d2a;
            break;
        }
        return;
    case 0x1d2a:
/*
       collect.push({
         x:memory16get(cs*16 + 0x1C50), 
         y:r16[ax],//memory16get(cs*16 + 0x1C4E),
         w:r8[dl] >> memory[cs*16+0x0], //memory[cs*16 + 0x1C4A],
         h:memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 0x5aa4) + 0, //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 0x5dc4), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });
*/
        memory16set(cs*16+0x1C4E, r16[ax]);
        r8[cl] = memory[cs*16+0x0];
        r8[dl] >>= r8[cl];
        memory[cs*16+0x1C4A] = r8[dl];
        memory[cs*16+0x1C4B] = r8[dl];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[cx] = r16[cx] ^ r16[cx];
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x1d5a;
            break;
        }
        r16[ax] = -r16[ax];
        memory[cs*16+0x1C52] -= r8[al];
        _mul8(r8[dl]);
        r16[cx] = r16[ax];
        memory16set(cs*16+0x1C46, r16[ax]);
        r16[di] = r16[di] ^ r16[di];
        pc = 0x1d60;
        break;
    case 0x1d5a:
        _mul8(memory[ds*16+21084]);
        r16[di] = r16[ax];
    case 0x1d60:
/*
       collect.push({
         x:memory16get(cs*16 + 0x1C50), 
         y:memory16get(cs*16 + 0x1C4E),
         w:memory[cs*16 + 0x1C4A],
         h:memory[cs*16 + 0x1C52],
         o:memory16get(ds*16+r16[bx] + 23204) + r16[cx], //memory16get(cs*16 + 0x1C5A), 
         s:memory16get(ds*16+r16[bx] + 24004), //memory16get(cs*16 + 0x1C5C),
         t:memory[cs*16 + 0x1C48]&1
        });

*/
        r16[di] = r16[di] + memory16get(ds*16+21098);
        memory16set(cs*16+0x1C58, r16[di]);
        r16[ax] = memory16get(ds*16+r16[bx] + 24004);
        memory16set(cs*16+0x1C5C, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[bx] + 23204);
        r16[ax] += r16[cx];
        memory16set(cs*16+0x1C5A, r16[ax]);
        r16[ax] = memory16get(ds*16+0x5278);


        flags.carry2 = r16s[ax] <= signed16(0x00c0);
        r16[ax] -= 0x00c0;
        if (flags.carry2) {
            pc = 0x1d8f;
            break;
        }
        memory[cs*16+0x1C52] -= r8[al];
        _mul8(r8[dl]);
        memory16set(cs*16+0x1C46, memory16get(cs*16+0x1C46) + r16[ax]);
    case 0x1d8f:
        r16[ax] = memory16get(cs*16+0x1C50);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x1db0;
            break;
        }
        r8[cl] = memory[cs*16+0x0];
        sar16(ax, r8[cl]);
        memory[cs*16+0x1C4A] += r8[al];
        r8[al] = -r8[al];
        memory[cs*16+0x1C53] = r8[al];
        memory[cs*16+0x1C49] += 1;
        pc = 0x1de8;
        break;
    case 0x1db0:
        r8[cl] = memory[cs*16+0x0];
        sar16(ax, r8[cl]);
        memory16set(cs*16+0x1C58, memory16get(cs*16+0x1C58) + r16[ax]);
        r16[ax] = memory16get(cs*16+0x1C50);
        r8[cl] = memory[cs*16+0x0];
        r16[ax] >>= r8[cl];
        flags.carry = (r8[al] + memory[cs*16+0x1C4A]) >= 0x100;
        r8[al] = r8[al] + memory[cs*16+0x1C4A];
        r8[ah] = r8[ah] + 0x00 + flags.carry;
        flags.carry = r16[ax] < memory16get(ds*16+21084);
        r16[ax] = r16[ax] - memory16get(ds*16+21084);
        if (flags.carry) {
            pc = 0x1de8;
            break;
        }
        memory[cs*16+0x1C4A] -= r8[al];
        memory[cs*16+0x1C49] += 1;
        memory[cs*16+0x1C56] = r8[al];
        memory[cs*16+0x1C57] = ~memory[cs*16+0x1C57];
    case 0x1de8:
        memory[ds*16+r16[si] + 5] |= 0x20;
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x1df7;
            break;
        }
        yield* loc_203a();
        return;
    case 0x1df7:
        if (memory[cs*16+0x1C5E] == 0x01) {
            pc = 0x1e02;
            break;
        }
        return;
    case 0x1e02:
        // std::cout << "  - draw B\n";
        r8[al] = memory[cs*16+0x1C4B];
        _mul8(memory[cs*16+0x1C4C]);
        memory16set(cs*16+0x1C5F, r16[ax]);
        es = memory16get(ds*16+21090);
        r16[di] = memory16get(cs*16+0x1C58);
        ds = memory16get(cs*16+0x1C5C);
        r16[bx] = memory16get(cs*16+0x1C5F);
        r16[si] = memory16get(cs*16+0x1C5A);
        r8[dl] = memory[cs*16+0x1C52];
        if (memory[cs*16+0x1C49] != 0x00)
            {
            // std::cout << "  - draw D\n";
            yield* loc_1ea3();
            return;
        }
        if (memory16get(cs*16+0x1C50) & 0x0003)
            {
            // std::cout << "  - draw E\n";
            yield* loc_1ea3();
            return;
        }
        r8[dh] = memory[cs*16+0x1C4A];
        r8[ch] = r8[ch] ^ r8[ch];
        r8[cl] = r8[dh];
        if (memory[cs*16+0x1C48] & 0x01)
            {
            // std::cout << "  - draw F\n";
            yield* loc_1e6c();
            return;
        }
        bp = 0x0050;
        bp -= r16[cx];
    case 0x1e53:
        r16[cx] >>= 1;
    case 0x1e55:
        r16[ax] = memory16get(es*16+r16[di]);
        r16[ax] = r16[ax] & memory16get(ds*16+r16[bx] + r16[si]);
        r16[ax] = r16[ax] | memory16get(ds*16+r16[si]);
        stosw_data_forward();
        r16[si] += 1;
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x1e55;
            break;
        }
        r8[cl] = r8[dh];
        r16[di] += bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x1e53;
            break;
        }
        return;
    } while (1);
}
function* loc_1e6c() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1e6c:
        bp = r16[bx];
        r16[bx] = 0x330e;
        r16[di] += r16[cx];
        r16[di] -= 1;
    case 0x1e74:
        r16[cx] >>= 1;
    case 0x1e76:
        r16[ax] = memory16get(ds*16+bp + r16[si] + 0);
        _xlatcs();
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        _xlatcs();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] -= 1;
        r8[al] = r8[ah];
        _xlatcs();
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        _xlatcs();
        memory[es*16+r16[di]] |= r8[al];
        r16[di] -= 1;
        if (--r16[cx]) {
            pc = 0x1e76;
            break;
        }
        r8[cl] = r8[dh];
        r16[di] += r16[cx];
        r16[di] += 0x0050;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x1e74;
            break;
        }
    case 0x1ea0:
        return;
    } while (1);
}
function* loc_1ea3() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1ea3:
        if (memory[cs*16+0x1C4A] == 0x00)
            {
            return;
        }
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x03;
        r8[cl] <<= 1;
        r8[ch] = 0xff;
        r8[ch] <<= r8[cl];
        if (memory[cs*16+0x1C48] & 0x01) {
            pc = 0x1f3e;
            break;
        }
    case 0x1ec1:
        r8[al] = memory[cs*16+0x1C4A];
        _cbw();
        bp = r16[ax];
        r8[al] = memory[cs*16+0x1C53];
        _cbw();
        r16[si] += r16[ax];
        r8[ch] = (~r8[ch]);
        r16[dx] = 0xff00;
        r8[dh] &= r8[ch];
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x1ee4;
            break;
        }
        r8[dh] = memory[ds*16+r16[bx] + r16[si] + -1];
        r8[dh] &= r8[ch];
        r8[dl] = memory[ds*16+r16[si] - 1];
        r8[dl] &= r8[ch];
    case 0x1ee4:
        r8[ch] = (~r8[ch]);
    case 0x1ee6:
        r8[al] = memory[ds*16+r16[bx] + r16[si]];
        r8[ah] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[dh];
        ror8(al, r8[cl]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        r8[dh] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[dl];
        ror8(al, r8[cl]);
        memory[es*16+r16[di]] |= r8[al];
        r8[ch] = (~r8[ch]);
        r8[dl] = r8[dh];
        r8[dh] = r8[ah];
        r8[dl] &= r8[ch];
        r8[dh] &= r8[ch];
        r8[ch] = (~r8[ch]);
        r16[di] += 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x1ee6;
            break;
        }
        if (memory[cs*16+0x1C57] != 0x00) {
            pc = 0x1f23;
            break;
        }
        r8[dh] |= r8[ch];
        ror8(dh, r8[cl]);
        ror8(dl, r8[cl]);
        memory[es*16+r16[di]] &= r8[dh];
        memory[es*16+r16[di]] |= r8[dl];
    case 0x1f23:
        r8[al] = memory[cs*16+0x1C4A];
        _cbw();
        r16[di] -= r16[ax];
        r16[di] += 0x0050;
        r8[al] = memory[cs*16+0x1C56];
        _cbw();
        r16[si] += r16[ax];
        memory[cs*16+0x1C52] -= 1;
        if (memory[cs*16+0x1C52] != 0) {
            pc = 0x1ec1;
            break;
        }
        return;
    case 0x1f3e:
        r8[al] = memory[cs*16+0x1C53];
        memory[cs*16+0x1C54] = r8[al];
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x03;
        r8[cl] -= 0x04;
        r8[cl] = -r8[cl];
        r8[cl] &= 0x03;
        r8[cl] <<= 1;
        r8[ch] = 0xff;
        r8[ch] >>= r8[cl];
        bp = r16[bx];
        r16[bx] = 0x330e;
        if (memory[cs*16+0x1C53] == 0x00) {
            pc = 0x1f7d;
            break;
        }
        r16[di] -= 1;
        if (!(memory16get(cs*16+0x1C50) & 0x0003)) {
            pc = 0x1f7d;
            break;
        }
        memory[cs*16+0x1C53] -= 1;
        memory[cs*16+0x1C4A] += 1;
    case 0x1f7d:
        if (memory[cs*16+0x1C57] == 0x00) {
            pc = 0x1f9a;
            break;
        }
        r16[di] -= 1;
        if (!(memory16get(cs*16+0x1C50) & 0x0003)) {
            pc = 0x1f9a;
            break;
        }
        r16[di] += 1;
        memory[cs*16+0x1C4A] -= 1;
        memory[cs*16+0x1C56] += 1;
    case 0x1f9a:
        r8[al] = memory[cs*16+0x1C4A];
        _cbw();
        r16[di] += r16[ax];
    case 0x1fa1:
        r8[al] = memory[cs*16+0x1C4A];
        memory[cs*16+0x1C4D] = r8[al];
        r8[ch] = (~r8[ch]);
        r16[dx] = 0xff00;
        r8[dh] &= r8[ch];
        r8[ch] = (~r8[ch]);
        if (memory[cs*16+0x1C57] == 0x00) {
            pc = 0x1fd7;
            break;
        }
        r8[al] = memory[cs*16+0x1C56];
        _cbw();
        r16[si] += r16[ax];
        r8[al] = memory[ds*16+bp + r16[si] + -1];
        _xlatcs();
        r8[dh] = r8[al];
        r8[al] = memory[ds*16+r16[si] - 1];
        _xlatcs();
        r8[dl] = r8[al];
        memory[cs*16+0x1C4D] += 1;
        pc = 0x1ffa;
        break;
    case 0x1fd7:
        r8[al] = memory[ds*16+bp + r16[si] + 0];
        _xlatcs();
        r8[ah] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[dh];
        rol8(al, r8[cl]);
        memory[es*16+r16[di]] &= r8[al];
        lodsb_data_forward();
        _xlatcs();
        r8[dh] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[dl];
        rol8(al, r8[cl]);
        memory[es*16+r16[di]] |= r8[al];
        r16[di] -= 1;
        r8[dl] = r8[dh];
        r8[dh] = r8[ah];
    case 0x1ffa:
        r8[ch] = (~r8[ch]);
        r8[dl] &= r8[ch];
        r8[dh] &= r8[ch];
        r8[ch] = (~r8[ch]);
        memory[cs*16+0x1C4D] -= 1;
        if (memory[cs*16+0x1C4D] != 0) {
            pc = 0x1fd7;
            break;
        }
        if (memory[cs*16+0x1C54] != 0x00) {
            pc = 0x201d;
            break;
        }
        r8[dh] |= r8[ch];
        rol8(dh, r8[cl]);
        rol8(dl, r8[cl]);
        memory[es*16+r16[di]] &= r8[dh];
        memory[es*16+r16[di]] |= r8[dl];
    case 0x201d:
        r8[al] = memory[cs*16+0x1C4A];
        _cbw();
        r16[di] += r16[ax];
        r16[di] += 0x0050;
        r8[al] = memory[cs*16+0x1C53];
        r16[si] += r16[ax];
        memory[cs*16+0x1C52] -= 1;
        if (memory[cs*16+0x1C52] == 0) {
            pc = 0x2037;
            break;
        }
        pc = 0x1fa1;
        break;
    case 0x2037:
        return;
    } while (1);
}
function* loc_203a() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x203a:
        yield* sub_32dc();
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x07;
        r8[ch] = 0xff;
        r8[ch] <<= r8[cl];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = memory16get(cs*16+0x1C5A);
        r8[dl] = 0xce;
        r8[al] = 0x03;
        r8[ah] = r8[cl];
        r8[ah] |= 0x08;
        out16(r16[dx], r16[ax]);
        r8[bh] = r8[ch];
        r8[bh] = (~r8[bh]);
        r8[dh] = memory[cs*16+0x1C4A];
        r8[cl] = r8[dh];
        r8[al] = r8[cl];
        _cbw();
        r16[ax] -= 0x0028;
        bp = r16[ax];
        r8[dl] = memory[cs*16+0x1C52];
        ds = memory16get(cs*16+0x1C5C);
        r16[ax] = 0xa000;
        es = r16[ax];
        if (memory[cs*16+0x1C48] & 0x01) {
            pc = 0x2091;
            break;
        }
        pc = 0x22e9;
        break;
    case 0x2091:
        memory[cs*16+0x1C4C] = r8[dl];
        r16[dx] = r16[bx];
        r16[bx] = 0x340e;
        flags.direction = true;
        r16[si] -= 1;
        if (memory[cs*16+0x1C49] == 0x00) {
            pc = 0x20a8;
            break;
        }
        pc = 0x21ef;
        break;
    case 0x20a8:
        r8[al] = r8[cl];
        _cbw();
        r16[si] += r16[ax];
        if (r8[ch] == 0xff) {
            pc = 0x20b5;
            break;
        }
        pc = 0x213c;
        break;
    case 0x20b5:
        r8[ch] = r8[ch] ^ r8[ch];
    case 0x20b7:
        lodsb_data_backward();
        _xlatcs();
        r8[al] = (~r8[al]);
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x20b7;
            break;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = r8[cl];
        _cbw();
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x20b7;
            break;
        }
        push(r16[dx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x1003;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
        memory[cs*16+0x1C57] = (~memory[cs*16+ 0x1C57]);
        r16[dx] = pop();
    case 0x20ee:
        push(r16[dx]);
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[cl] = memory[cs*16+0x1C4A];
        r8[dl] = memory[cs*16+0x1C52];
        memory[cs*16+0x1C4C] = r8[dl];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
        r16[dx] = pop();
    case 0x2111:
        lodsb_data_backward();
        _xlatcs();
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x2111;
            break;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = r8[cl];
        _cbw();
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x2111;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x20ee;
            break;
        }
        return;
    case 0x213c:
        if (flags.direction)
            lodsb_data_backward();
        else
        lodsb_data_forward();
        _xlatcs();
        r8[dl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        r8[al] = (~r8[al]);
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
        r8[dl] &= r8[dh];
        r8[ah] = r8[dl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x213c;
            break;
        }
        r8[ah] = (~r8[ah]);
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = r8[cl];
        _cbw();
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x213c;
            break;
        }
        push(r16[dx]);
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x07;
        r16[dx] = 0x03ce;
        r8[al] = 0x03;
        r8[ah] = r8[cl];
        r8[ah] |= 0x10;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
        memory[cs*16+0x1C57] = (~memory[cs*16+ 0x1C57]);
        r16[dx] = pop();
    case 0x2190:
        push(r16[dx]);
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[cl] = memory[cs*16+0x1C4A];
        r8[dl] = memory[cs*16+0x1C52];
        memory[cs*16+0x1C4C] = r8[dl];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
        r16[dx] = pop();
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x21b5:
        if (flags.direction)
            lodsb_data_backward();
        else
        lodsb_data_forward();
        _xlatcs();
        r8[dl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
        r8[dl] &= r8[dh];
        r8[ah] = r8[dl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x21b5;
            break;
        }
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = r8[cl];
        _cbw();
        r16[si] += r16[ax];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x21b5;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x2190;
            break;
        }
        return;
    case 0x21ef:
        r8[al] = memory[cs*16+0x1C4B];
        _cbw();
        r16[si] += r16[ax];
    case 0x21f6:
        r8[al] = memory[cs*16+0x1C53];
        _cbw();
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x220a;
            break;
        }
        r16[ax] -= 1;
        r16[si] -= r16[ax];
        lodsb_data_backward();
        _xlatcs();
        r8[dl] = r8[al];
        r16[cx] += 1;
        pc = 0x2219;
        break;
    case 0x220a:
        lodsb_data_backward();
        _xlatcs();
        r8[dl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        r8[al] = (~r8[al]);
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
    case 0x2219:
        r8[dl] &= r8[dh];
        r8[ah] = r8[dl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x220a;
            break;
        }
        r8[ah] = (~r8[ah]);
        r8[ah] = r8[ah] | memory[cs*16+0x1C57];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = memory[cs*16+0x1C4B];
        _cbw();
        r16[si] += r16[ax];
        r8[al] = r8[al] - memory[cs*16+0x1C56];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x21f6;
            break;
        }
        push(r16[dx]);
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x07;
        r16[dx] = 0x03ce;
        r8[al] = 0x03;
        r8[ah] = r8[cl];
        r8[ah] |= 0x10;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
        memory[cs*16+0x1C57] = (~memory[cs*16+ 0x1C57]);
        r16[dx] = pop();
    case 0x226a:
        push(r16[dx]);
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[cl] = memory[cs*16+0x1C4A];
        r8[dl] = memory[cs*16+0x1C52];
        memory[cs*16+0x1C4C] = r8[dl];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
        r16[dx] = pop();
    case 0x228d:
        r8[al] = memory[cs*16+0x1C53];
        _cbw();
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x22a1;
            break;
        }
        r16[ax] -= 1;
        r16[si] -= r16[ax];
        lodsb_data_backward();
        _xlatcs();
        r8[dl] = r8[al];
        r16[cx] += 1;
        pc = 0x22ae;
        break;
    case 0x22a1:
        lodsb_data_backward();
        _xlatcs();
        r8[dl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[al]);
            r8[al] = t;
        }
        r16[di] += 1;
    case 0x22ae:
        r8[dl] &= r8[dh];
        r8[ah] = r8[dl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x22a1;
            break;
        }
        r8[ah] = r8[ah] & memory[cs*16+0x1C57];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = memory[cs*16+0x1C4A];
        r8[al] = memory[cs*16+0x1C4B];
        _cbw();
        r16[si] += r16[ax];
        r8[al] = r8[al] - memory[cs*16+0x1C56];
        r16[si] += r16[ax];
        r16[di] -= bp;
        memory[cs*16+0x1C4C] -= 1;
        if (memory[cs*16+0x1C4C] != 0) {
            pc = 0x228d;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] >= 0x10) {
            pc = 0x22e6;
            break;
        }
        pc = 0x226a;
        break;
    case 0x22e6:
        return;
    case 0x22e9:
        if (memory[cs*16+0x1C49] == 0x00) {
            pc = 0x22f4;
            break;
        }
        pc = 0x23e2;
        break;
    case 0x22f4:
        if (r8[ch] != 0xff) {
            pc = 0x2354;
            break;
        }
        r8[ch] = r8[ch] ^ r8[ch];
    case 0x22fb:
        lodsb_data_forward();
        r8[al] = (~r8[al]);
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
        if (--r16[cx]) {
            pc = 0x22fb;
            break;
        }
        r8[cl] = r8[dh];
        r16[di] -= bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x22fb;
            break;
        }
        r16[dx] = 0x03ce;
        r16[ax] = 0x1003;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
    case 0x231b:
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[dh] = memory[cs*16+0x1C4A];
        r8[cl] = r8[dh];
        r8[dl] = memory[cs*16+0x1C52];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
    case 0x2339:
        lodsb_data_forward();
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
        if (--r16[cx]) {
            pc = 0x2339;
            break;
        }
        r16[di] -= bp;
        r8[cl] = r8[dh];
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x2339;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x231b;
            break;
        }
        return;
    case 0x2354:
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x2356:
        lodsb_data_forward();
        r8[bl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        r8[al] = (~r8[al]);
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
        r8[bl] &= r8[bh];
        r8[ah] = r8[bl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2356;
            break;
        }
        r8[ah] = (~r8[ah]);
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = r8[dh];
        r16[di] -= bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x2354;
            break;
        }
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x07;
        r16[dx] = 0x03ce;
        r8[al] = 0x03;
        r8[ah] = r8[cl];
        r8[ah] |= 0x10;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
        memory[cs*16+0x1C57] = (~memory[cs*16 + 0x1C57]);
    case 0x2398:
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[dh] = memory[cs*16+0x1C4A];
        r8[cl] = r8[dh];
        r8[dl] = memory[cs*16+0x1C52];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
    case 0x23b6:
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x23b8:
        lodsb_data_forward();
        r8[bl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
        r8[bl] &= r8[bh];
        r8[ah] = r8[bl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x23b8;
            break;
        }
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[cl] = r8[dh];
        r16[di] -= bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x23b6;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x2398;
            break;
        }
        return;
    case 0x23e2:
        r8[al] = memory[cs*16+0x1C53];
        _cbw();
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x23f4;
            break;
        }
        r16[ax] -= 1;
        r16[cx] += 1;
        r16[si] += r16[ax];
        lodsb_data_forward();
        r8[bl] = r8[al];
        pc = 0x2400;
        break;
    case 0x23f4:
        lodsb_data_forward();
        r8[bl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        r8[al] = (~r8[al]);
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
    case 0x2400:
        r8[bl] &= r8[bh];
        r8[ah] = r8[bl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x23f4;
            break;
        }
        r8[ah] = (~r8[ah]);
        r8[ah] = r8[ah] | memory[cs*16+0x1C57];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[al] = memory[cs*16+0x1C56];
        _cbw();
        r16[si] += r16[ax];
        r8[cl] = memory[cs*16+0x1C4A];
        r16[di] -= bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x23e2;
            break;
        }
        r8[cl] = memory[cs*16+0x1C50];
        r8[cl] &= 0x07;
        r16[dx] = 0x03ce;
        r8[al] = 0x03;
        r8[ah] = r8[cl];
        r8[ah] |= 0x10;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = memory[cs*16+0x1C5E];
        memory[cs*16+0x1C57] = (~memory[cs*16+ 0x1C57]);
    case 0x2445:
        memory[cs*16+0x1C4D] = r8[al];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[cl] = memory[cs*16+0x1C4A];
        r8[dl] = memory[cs*16+0x1C52];
        r16[di] = memory16get(cs*16+0x1C58);
        r16[si] = r16[si] + memory16get(cs*16+0x1C46);
    case 0x2461:
        r8[al] = memory[cs*16+0x1C53];
        _cbw();
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x2473;
            break;
        }
        r16[ax] -= 1;
        r16[cx] += 1;
        r16[si] += r16[ax];
        lodsb_data_forward();
        r8[bl] = r8[al];
        pc = 0x247d;
        break;
    case 0x2473:
        lodsb_data_forward();
        r8[bl] = r8[al];
        r8[al] &= r8[ch];
        r8[al] |= r8[ah];
        memoryVideoGet(es, r16[di]);
        stosb_video_forward();
    case 0x247d:
        r8[bl] &= r8[bh];
        r8[ah] = r8[bl];
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2473;
            break;
        }
        r8[ah] = r8[ah] & memory[cs*16+0x1C57];
        {
            var t = memoryVideoGet(es, r16[di]);
            memoryVideoSet(es, r16[di], r8[ah]);
            r8[ah] = t;
        }
        r8[al] = memory[cs*16+0x1C56];
        _cbw();
        r16[si] += r16[ax];
        r8[cl] = memory[cs*16+0x1C4A];
        r16[di] -= bp;
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x2461;
            break;
        }
        r8[al] = memory[cs*16+0x1C4D];
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x2445;
            break;
        }
    case 0x24a9:
        return;
    } while (1);
}
function* sub_24c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x24f1;
            break;
        }
        r16[ax] = memory16get(ds*16+0x04c1);
        memory16set(ds*16+0x5262, r16[ax]);
        r16[ax] += 0x0400;
        memory16set(ds*16+0x5264, r16[ax]);
        memory16set(ds*16+1217, memory16get(ds*16+1217) + 0x0800);
    case 0x24f1:
        r16[si] = 0x7255;
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x24f6:
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x251a;
            break;
        }
    case 0x24fc:
        if (r16[ax] == r16[bx]) {
            pc = 0x2508;
            break;
        }
        memory[ds*16+r16[bx] + 28869] = 0x00;
        r16[bx] += 1;
        pc = 0x24fc;
        break;
    case 0x2508:
        lodsw_data_forward();
    case 0x2509:
        memory[ds*16+r16[bx] + 28869] = 0x01;
        r16[bx] += 1;
        r16[ax] -= 1;
        if (r16[ax] != 0) {
            pc = 0x2509;
            break;
        }
        pc = 0x24f6;
        break;
    case 0x2514:
        memory[ds*16+r16[bx] + 28869] = 0x00;
        r16[bx] += 1;
    case 0x251a:
        if (r16[bx] == 0x0190) {
            pc = 0x2514;
            break;
        }
        r16[dx] = 0x501a;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x5260, r16[ax]);
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x252f:
        r8[al] = memory[ds*16+r16[bx] + 26214];
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x2543;
            break;
        }
        memory[ds*16+r16[bx] + 26928] -= r8[al];
        memory[ds*16+r16[bx] + 26928] = -memory[ds*16 + r16[bx] + 26928];
        r16[bx] += 1;
        r16[bx] += 1;
        pc = 0x252f;
        break;
    case 0x2543:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x254e;
            break;
        }
        pc = 0x263e;
        break;
    case 0x254e:
        r16[si] = r16[si] ^ r16[si];
        memory16set(cs*16+0x6676, 0x274f);
        r16[ax] = memory16get(ds*16+0x5260);
        memory16set(ds*16+0x5268, r16[ax]);
        memory16set(ds*16+21086, 0x0000);
        es = memory16get(ds*16+1217);
    case 0x2567:
        push(es);
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = 0x1ef0;
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[cx] = memory16get(ds*16+21086);
        r16[dx] = r16[cx];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[di] += r16[dx];
        r8[al] = 0xc0;
        r8[cl] &= 0x03;
        r8[cl] <<= 1;
        r8[al] >>= r8[cl];
        memory[es*16+r16[di]] |= r8[al];
        es = pop();
        r16[ax] = r16[si];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        memory16set(ds*16+21096, memory16get(ds*16+21096) + r16[ax]);
        r16[si] &= 0x000f;
        r16[di] = r16[di] ^ r16[di];
        r16[bx] = memory16get(ds*16+21086);
        memory16set(ds*16+21086, memory16get(ds*16+21086) + 1);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[bx] + 26213);
        r16[dx] = r16[ax];
        _mul8(r8[ah]);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r16[ax] == 0) {
            pc = 0x2608;
            break;
        }
        r16[cx] = r16[ax];
        push(r16[si]);
        ds = memory16get(ds*16+21096);
        rep_movsw_data_data_forward();
        r16[si] = pop();
        r16[bx] = r16[ax];
        r8[al] = r8[dh];
        r8[ah] = r8[dl];
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        yield* sub_65be();
        r16[si] += r16[bx];
        r16[bx] >>= 1;
        bp = r16[bx];
        r16[di] = r16[di] ^ r16[di];
    case 0x25da:
        r8[al] = memory[es*16+r16[di]];
        r16[di] += r16[bx];
        r8[al] = r8[al] | memory[es*16+r16[di]];
        r16[di] += r16[bx];
        r8[al] = r8[al] | memory[es*16+r16[di]];
        r8[al] = r8[al] | memory[es*16+r16[bx] + r16[di]];
        r16[di] -= r16[bx];
        r16[di] -= r16[bx];
        r16[cx] = 0x0008;
    case 0x25f1:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        rcr16(dx, 1);
        sar16(dx, 1);
        if (--r16[cx]) {
            pc = 0x25f1;
            break;
        }
        xchg8(dh, dl);
        r16[dx] = (~r16[dx]);
        memory16set(ds*16+r16[si], r16[dx]);
        r16[si] += 1;
        r16[si] += 1;
        r16[di] += 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x25da;
            break;
        }
        pc = 0x2567;
        break;
    case 0x2608:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[bx] = memory16get(ds*16+21088);
        r16[cx] = r16[cx] ^ r16[cx];
    case 0x2615:
        memory16set(ds*16+r16[di] + 24004, r16[bx]);
        memory16set(ds*16+r16[di] + 23204, r16[cx]);
        r16[ax] = memory16get(ds*16+r16[di] + 26213);
        r16[di] += 1;
        r16[di] += 1;
        _mul8(r8[ah]);
        r16[ax] >>= 1;
        if (r16[ax] == 0) {
            pc = 0x263b;
            break;
        }
        r16[cx] += r16[ax];
        if (r16[cx] < 0x1000) {
            pc = 0x2615;
            break;
        }
        r16[cx] -= 0x1000;
        r16[bx] += 0x0100;
        pc = 0x2615;
        break;
    case 0x263b:
        pc = 0x273d;
        break;
    case 0x263e:
        flags.direction = true;
        r16[ax] = memory16get(ds*16+0x04c1);
        r16[bx] = memory16get(ds*16+21088);
        r16[ax] -= r16[bx];
        bp = r16[ax];
        r16[dx] = r16[ax];
        r16[dx] >>= 1;
        r16[dx] >>= 1;
        r16[dx] += 1;
        r16[ax] += r16[dx];
        r16[ax] += r16[bx];
        memory16set(ds*16+0x04c1, r16[ax]);
        r16[ax] -= 1;
        r16[bx] = r16[ax];
        r16[ax] -= r16[dx];
    case 0x265d:
        ds = r16[ax];
        es = r16[bx];
        r16[si] = 0x000f;
        r16[di] = r16[si];
        r16[cx] = 0x0010;
        rep_movsb_data_data_backward();
        r16[ax] -= 1;
        r16[bx] -= 1;
        bp -= 1;
        if (bp != 0) {
            pc = 0x265d;
            break;
        }
        flags.direction = false;
        r16[dx] = 0x168f;
        ds = r16[dx];
        r16[ax] += 1;
        r16[bx] += 1;
        memory16set(ds*16+0x5087, r16[ax]);
        memory16set(ds*16+20617, r16[bx]);
        r16[bx] = 0x6665;
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
    case 0x2686:
        r16[ax] = r16[si];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        memory16set(ds*16+20617, memory16get(ds*16+20617) + r16[ax]);
        r16[si] &= 0x000f;
        r16[ax] = r16[di];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        memory16set(ds*16+20615, memory16get(ds*16+20615) + r16[ax]);
        r16[di] &= 0x000f;
        r16[ax] = memory16get(ds*16+r16[bx]);
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x26f2;
            break;
        }
        ror8(al, 1);
        ror8(al, 1);
        ror8(al, 1);
        if (!(r8[al] & 0xe0)) {
            pc = 0x26bc;
            break;
        }
        r8[al] &= 0x1f;
        r8[al] += 1;
    case 0x26bc:
        r16[bx] += 1;
        r16[bx] += 1;
        _mul8(r8[ah]);
        bp = r16[ax];
        es = memory16get(ds*16+20615);
        ds = memory16get(ds*16+20617);
        r16[cx] = bp;
        push(r16[si]);
    case 0x26cd:
        r8[al] = memory[ds*16+r16[si]];
        r8[al] = r8[al] | memory[ds*16+bp + r16[si] + 0];
        r16[si] += bp;
        r8[al] = r8[al] | memory[ds*16+bp + r16[si] + 0];
        r16[si] += bp;
        r8[al] = r8[al] | memory[ds*16+bp + r16[si] + 0];
        r16[si] -= bp;
        r16[si] -= bp;
        stosb_data_forward();
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x26cd;
            break;
        }
        r16[si] = pop();
        r16[cx] = bp;
        r16[cx] <<= 1;
        rep_movsw_data_data_forward();
        r16[ax] = 0x168f;
        ds = r16[ax];
        pc = 0x2686;
        break;
    case 0x26f2:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r16[bx] = memory16get(ds*16+21088);
        r16[si] = 0x6665;
        r16[di] = r16[di] ^ r16[di];
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x2704:
        lodsw_data_forward();
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x273d;
            break;
        }
        ror8(al, 1);
        ror8(al, 1);
        ror8(al, 1);
        if (!(r8[al] & 0xe0)) {
            pc = 0x2717;
            break;
        }
        r8[al] &= 0x1f;
        r8[al] += 1;
    case 0x2717:
        _mul8(r8[ah]);
        bp = r16[ax];
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += bp;
        memory16set(ds*16+r16[di] + 23204, r16[dx]);
        memory16set(ds*16+r16[di] + 24004, r16[bx]);
        if (r16[dx] < 0x1000) {
            pc = 0x2737;
            break;
        }
        r16[dx] -= 0x1000;
        r16[bx] += 0x0100;
    case 0x2737:
        r16[di] += 1;
        r16[di] += 1;
        r16[dx] += r16[ax];
        pc = 0x2704;
        break;
    case 0x273d:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_276f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(ds);
        push(es);
        yield* sub_2c87();
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_27df();
        yield* sub_32f4();
        bp = 0x0002;
        r16[di] = 0x0c92;
    case 0x2789:
        yield* sub_3243();
        r16[cx] = bp;
    case 0x278e:
        yield* sub_28cd();
        r16[di] += 1;
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x278e;
            break;
        }
        r16[di] -= 1;
        r16[di] -= 1;
        r16[cx] = bp;
        r16[cx] -= 1;
    case 0x279a:
        r16[di] += 0x0190;
        yield* sub_28cd();
        if (--r16[cx]) {
            pc = 0x279a;
            break;
        }
        r16[cx] = bp;
        r16[cx] -= 1;
    case 0x27a6:
        r16[di] -= 1;
        r16[di] -= 1;
        yield* sub_28cd();
        if (--r16[cx]) {
            pc = 0x27a6;
            break;
        }
        r16[cx] = bp;
        r16[cx] -= 1;
    case 0x27b0:
        r16[di] -= 0x0190;
        yield* sub_28cd();
        if (--r16[cx]) {
            pc = 0x27b0;
            break;
        }
        bp += 1;
        bp += 1;
        r16[di] -= 0x0192;
        if (bp < 0x0014) {
            pc = 0x2789;
            break;
        }
        r16[di] = memory16get(ds*16+21098);
        r16[si] = memory16get(ds*16+21096);
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = r16[ax];
        r16[cx] = 0x1e00;
        rep_movsb_video_video_forward();
        es = pop();
        ds = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_27df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x27ec;
            break;
        }
        yield* sub_3160();
        pc = 0x2810;
        break;
    case 0x27ec:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(es);
        yield* sub_32dc();
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[di] = memory16get(ds*16+21096);
        r16[cx] = 0x0f00;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_video_forward();
        es = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
    case 0x2810:
        return;
    } while (1);
}
function* sub_2811() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x281d;
            break;
        }
        yield* sub_3160();
        return;
    case 0x281d:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(ds);
        push(es);
        yield* sub_32dc();
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[di] = memory16get(ds*16+21096);
        r16[cx] = 0x0014;
        memory16set(cs*16+0x274D, 0x0026);
        memory16set(cs*16+0x274B, 0x1c70);
    case 0x2847:
        yield* sub_3243();
        push(r16[cx]);
        push(r16[di]);
        memory16set(cs*16+0x2747, 0x0000);
        memory16set(cs*16+0x2749, 0x0000);
    case 0x285a:
        r16[di] = r16[di] + memory16get(cs*16+0x2749);
        yield* sub_28f8();
        r16[di] = r16[di] + memory16get(cs*16+0x274B);
        yield* sub_28f8();
        r16[di] = r16[di] - memory16get(cs*16+0x274B);
        r16[di] = r16[di] - memory16get(cs*16+0x2749);
        if (memory16get(cs*16+0x2747) <= 0x1c70) {
            pc = 0x2883;
            break;
        }
        r16[di] += 0x1c70;
        pc = 0x2888;
        break;
    case 0x2883:
        r16[di] = r16[di] + memory16get(cs*16+0x2747);
    case 0x2888:
        yield* sub_28f8();
        r16[di] = r16[di] + memory16get(cs*16+0x274D);
        yield* sub_28f8();
        r16[di] = r16[di] - memory16get(cs*16+0x274D);
        r16[di] = r16[di] - memory16get(cs*16+0x2747);
        memory16set(cs*16+0x2747, memory16get(cs*16+0x2747) + 0x0190);
        memory16set(cs*16+0x2749, memory16get(cs*16+0x2749) + 0x0002);
        if (--r16[cx]) {
            pc = 0x285a;
            break;
        }
        r16[di] = pop();
        r16[di] += 0x0192;
        memory16set(cs*16+0x274D, memory16get(cs*16+0x274D) - 0x0004);
        memory16set(cs*16+0x274B, memory16get(cs*16+0x274B) - 0x0320);
        r16[cx] = pop();
        r16[cx] -= 1;
        r16[cx] -= 1;
        if (r16[cx] != 0) {
            pc = 0x2847;
            break;
        }
        yield* sub_32dc();
        es = pop();
        ds = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_28cd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        r16[si] = r16[di];
        r16[si] = r16[si] + memory16get(ds*16+21098);
        r16[di] = r16[di] + memory16get(ds*16+21096);
        r16[ax] = 0xa000;
        ds = r16[ax];
        es = r16[ax];
        r16[cx] = 0x000a;
    case 0x28e7:
        movsb_video_video_forward();
        movsb_video_video_forward();
        r16[di] += 0x0026;
        r16[si] += 0x0026;
        if (--r16[cx]) {
            pc = 0x28e7;
            break;
        }
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_28f8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[di]);
        push(es);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[cx] = 0x000a;
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x2906:
        stosw_video_forward();
        r16[di] += 0x0026;
        if (--r16[cx]) {
            pc = 0x2906;
            break;
        }
        es = pop();
        r16[di] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2911() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory16get(ds*16+21106) == 0x0000) {
            pc = 0x2946;
            break;
        }
        memory16set(ds*16+21106, memory16get(ds*16+21106) - 1);
        r16[ax] = memory16get(ds*16+0x5276);
        r16[ax] -= 1;
        if (r16s[ax] >= 0) {
            pc = 0x292e;
            break;
        }
        r16[ax] = 0x000b;
    case 0x292e:
        r16[di] = r16[di] ^ r16[di];
        memory16set(ds*16+0x5276, r16[ax]);
        r16[ax] = memory16get(ds*16+0x5274);
        yield* sub_2b67();
        r8[ah] = memory[ds*16+21106];
        r8[al] = memory[ds*16+0x5270];
        yield* sub_2a0d();
        flags.carry = false;
        pc = 0x2947;
        break;
    case 0x2946:
        flags.carry = true;
    case 0x2947:
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_294c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[al] = memory[ds*16+0x508b];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] -= 0x000c;
        if (memory16get(ds*16+21106) >= r16[ax]) {
            pc = 0x298e;
            break;
        }
        memory16set(ds*16+21106, memory16get(ds*16+21106) + 1);
        r16[ax] = memory16get(ds*16+0x5276);
        r16[ax] += 1;
        if (r16[ax] < 0x000c) {
            pc = 0x2972;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x2972:
        r16[di] = 0x1b80;
        memory16set(ds*16+0x5276, r16[ax]);
        r16[ax] = memory16get(ds*16+0x5274);
        yield* sub_2b67();
        r8[ah] = memory[ds*16+21106];
        r8[al] = memory[ds*16+0x5270];
        r16[ax] += 0x0b00;
        yield* sub_2a0d();
        flags.carry = false;
        pc = 0x298f;
        break;
    case 0x298e:
        flags.carry = true;
    case 0x298f:
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2994() {
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[di] = r16[di] ^ r16[di];
    if (memory16get(ds*16+21104) == 0x0000)
        {
        flags.carry = true;
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    }
    memory16set(ds*16+21104, memory16get(ds*16+21104) - 1);
    r16[ax] = memory16get(ds*16+0x5274);
    r16[ax] -= 1;
    if (r16s[ax] >= 0)
        {
        yield* sub_29b5(0x29f2);
        return;
    }
    r16[ax] = 0x0013;
    yield* sub_29b5(0x29f2);
}
function* sub_29b5(pc) {
    if (!pc) pc = 0;
    do switch (pc) {
    case 0:
        if (pc == 0x29f2) {
            pc = 0x29f2;
            break;
        }
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = memory16get(ds*16+0x527c);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        r16[ax] -= 0x0014;
        if (memory16gets(ds*16+32061) >= r16s[ax]) {
            pc = 0x29d7;
            break;
        }
        r16[ax] = 0x00ec;
        pc = 0x29da;
        break;
    case 0x29d7:
        r16[ax] = memory16get(ds*16+0x7d3d);
    case 0x29da:
        if (memory16get(ds*16+21104) >= r16[ax]) {
            pc = 0x2a07;
            break;
        }
        r16[di] = 0x0013;
        memory16set(ds*16+21104, memory16get(ds*16+21104) + 1);
        r16[ax] = memory16get(ds*16+0x5274);
        r16[ax] += 1;
        if (r16[ax] < 0x0014) {
            pc = 0x29f2;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x29f2:
        memory16set(ds*16+0x5274, r16[ax]);
        yield* sub_2b67();
        r8[ah] = memory[ds*16+21106];
        r8[al] = memory[ds*16+0x5270];
        r16[ax] += r16[di];
        yield* sub_2ab1();
        flags.carry = false;
        pc = 0x2a08;
        break;
    case 0x2a07:
        flags.carry = true;
    case 0x2a08:
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2a0d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        push(ds);
        es = pop();
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x2a6c;
            break;
        }
        yield* sub_32f4();
        r16[si] = r16[ax];
        r16[di] = r16[di] + memory16get(ds*16+21094);
        r16[dx] = memory16get(ds*16+21108);
        r16[bx] = 0x63e4;
        ds = memory16get(ds*16+21100);
        r16[cx] = 0x0014;
    case 0x2a36:
        if (r16[di] < 0x5c80) {
            pc = 0x2a40;
            break;
        }
        r16[di] -= 0x1e00;
    case 0x2a40:
        lodsb_data_forward();
        r8[ah] = r8[al];
        _xlates();
        memory[es*16+25845] |= r8[al];
        r8[al] = r8[ah];
        push(es);
        bp = 0xa000;
        es = bp;
        yield* sub_2df5();
        es = pop();
        r16[dx] += 1;
        if (r16[dx] < 0x0014) {
            pc = 0x2a61;
            break;
        }
        r16[di] -= 0x0028;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x2a61:
        if (--r16[cx]) {
            pc = 0x2a36;
            break;
        }
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    case 0x2a6c:
        r16[si] = r16[ax];
        r16[di] <<= 1;
        r16[di] = r16[di] + memory16get(ds*16+21094);
        r16[dx] = memory16get(ds*16+21108);
        r16[bx] = 0x63e4;
        ds = memory16get(ds*16+21100);
        r16[cx] = 0x0014;
    case 0x2a82:
        if (r16[di] < 0x3c00) {
            pc = 0x2a8c;
            break;
        }
        r16[di] -= 0x3c00;
    case 0x2a8c:
        lodsb_data_forward();
        r8[ah] = r8[al];
        _xlates();
        memory[es*16+25845] |= r8[al];
        r8[al] = r8[ah];
        yield* sub_2e53();
        r16[dx] += 1;
        if (r16[dx] < 0x0014) {
            pc = 0x2aa6;
            break;
        }
        r16[di] -= 0x0050;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x2aa6:
        if (--r16[cx]) {
            pc = 0x2a82;
            break;
        }
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2ab1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x2b0d;
            break;
        }
        push(ds);
        push(es);
        push(ds);
        es = pop();
        yield* sub_32f4();
        r16[si] = r16[ax];
        r16[ax] = r16[di];
        r16[di] <<= 1;
        r16[di] = r16[di] + memory16get(ds*16+21094);
        r16[ax] = r16[ax] + memory16get(ds*16+21108);
        if (r16[ax] < 0x0014) {
            pc = 0x2ad6;
            break;
        }
        r16[di] -= 0x0028;
    case 0x2ad6:
        ds = memory16get(ds*16+21100);
        r16[cx] = 0x000c;
        r16[bx] = 0x63e4;
    case 0x2ae0:
        if (r16[di] < 0x5c80) {
            pc = 0x2aea;
            break;
        }
        r16[di] -= 0x1e00;
    case 0x2aea:
        lodsb_data_forward();
        r8[ah] = r8[al];
        _xlates();
        memory[es*16+25845] |= r8[al];
        r8[al] = r8[ah];
        push(es);
        r16[dx] = 0xa000;
        es = r16[dx];
        yield* sub_2df5();
        es = pop();
        r16[si] += 0x00ff;
        r16[di] += 0x027e;
        if (--r16[cx]) {
            pc = 0x2ae0;
            break;
        }
        es = pop();
        ds = pop();
        return;
    case 0x2b0d:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        push(ds);
        es = pop();
        r16[si] = r16[ax];
        r16[ax] = r16[di];
        r16[di] <<= 1;
        r16[di] <<= 1;
        r16[di] = r16[di] + memory16get(ds*16+21094);
        r16[ax] = r16[ax] + memory16get(ds*16+21108);
        if (r16[ax] < 0x0014) {
            pc = 0x2b30;
            break;
        }
        r16[di] -= 0x0050;
    case 0x2b30:
        ds = memory16get(ds*16+21100);
        r16[cx] = 0x000c;
        r16[bx] = 0x63e4;
    case 0x2b3a:
        if (r16[di] < 0x3c00) {
            pc = 0x2b44;
            break;
        }
        r16[di] -= 0x3c00;
    case 0x2b44:
        lodsb_data_forward();
        r8[ah] = r8[al];
        _xlates();
        memory[es*16+25845] |= r8[al];
        r8[al] = r8[ah];
        yield* sub_2e53();
        r16[si] += 0x00ff;
        r16[di] += 0x04fc;
        if (--r16[cx]) {
            pc = 0x2b3a;
            break;
        }
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2b67() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x2b88;
            break;
        }
        r16[ax] <<= 1;
        r8[dh] = memory[ds*16+21110];
        r8[dl] = r8[dl] ^ r8[dl];
        r16[bx] = r16[dx];
        r16[bx] <<= 1;
        r16[dx] >>= 1;
        r16[ax] += r16[dx];
        r16[ax] += r16[bx];
        r16[ax] += 0x3e80;
        memory16set(ds*16+0x5266, r16[ax]);
        return;
    case 0x2b88:
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        push(r16[ax]);
        r16[ax] = 0x0500;
        r8[dl] = memory[ds*16+21110];
        r8[dh] = r8[dh] ^ r8[dh];
        _mul16(r16[dx]);
        r16[dx] = pop();
        r16[ax] += r16[dx];
        memory16set(ds*16+0x5266, r16[ax]);
        return;
    case 0x2b9f:
        _STOP_("goto loc_2c7d");
        return;
    } while (1);
}
function* sub_2ba2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = memory16get(ds*16+21100);
        yield* sub_32f4();
        if (memory[ds*16+25845] == 0x00)
            {
            bp = pop();
            es = pop();
            ds = pop();
            r16[si] = pop();
            r16[di] = pop();
            r16[dx] = pop();
            r16[cx] = pop();
            r16[bx] = pop();
            r16[ax] = pop();
            return;
        }
        if (memory[ds*16+25852] & 0x03)
            {
            bp = pop();
            es = pop();
            ds = pop();
            r16[si] = pop();
            r16[di] = pop();
            r16[dx] = pop();
            r16[cx] = pop();
            r16[bx] = pop();
            r16[ax] = pop();
            return;
        }
        memory[ds*16+25845] = 0x00;
        r8[ah] = memory[ds*16+21106];
        r8[al] = memory[ds*16+0x5270];
        r16[si] = r16[ax];
        r8[ch] = 0x0c;
        r8[bh] = r8[bh] ^ r8[bh];
        r16[di] = memory16get(ds*16+21094);
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x2c32;
            break;
        }
    case 0x2be3:
        r16[dx] = memory16get(ds*16+21108);
        r8[cl] = 0x14;
    case 0x2be9:
        r8[bl] = memory[es*16+r16[si]];
        if (memory[ds*16+r16[bx] + 25572] == 0x00) {
            pc = 0x2c11;
            break;
        }
        memory[ds*16+25845] = 0x01;
        r8[al] = r8[bl];
        r16[bx] = memory16get(ds*16+25846);
        _xlatds();
        r8[bh] = r8[bh] ^ r8[bh];
        if (r16[di] < 0x3c00) {
            pc = 0x2c0b;
            break;
        }
        r16[di] -= 0x3c00;
    case 0x2c0b:
        yield* sub_2e53();
        r16[di] -= 0x0004;
    case 0x2c11:
        r16[dx] += 1;
        if (r16[dx] < 0x0014) {
            pc = 0x2c1c;
            break;
        }
        r16[di] -= 0x0050;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x2c1c:
        r16[di] += 0x0004;
        r16[si] += 1;
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2be9;
            break;
        }
        r16[di] += 0x0500;
        r16[si] += 0x00ec;
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x2be3;
            break;
        }
        pc = 0x2c7d;
        break;
    case 0x2c32:
        r16[dx] = memory16get(ds*16+21108);
        r8[cl] = 0x14;
    case 0x2c38:
        r8[bl] = memory[es*16+r16[si]];
        if (memory[ds*16+r16[bx] + 25572] == 0x00) {
            pc = 0x2c5f;
            break;
        }
        memory[ds*16+25845] = 0x01;
        r8[al] = r8[bl];
        r16[bx] = memory16get(ds*16+25846);
        _xlatds();
        r8[bh] = r8[bh] ^ r8[bh];
        if (r16[di] < 0x5c80) {
            pc = 0x2c5a;
            break;
        }
        r16[di] -= 0x1e00;
    case 0x2c5a:
//        console.log("tile: "+r16[si].toString(16));
        tiles[r16[si]] = {
          x: (r16[si]&0xff)*16, // - memory16get(0x168f*16 + 0x5270)*16,
          y: (r16[si]>>8)*16, // - memory16get(0x168f*16 + 0x5272)*16,
          w:2,
          h:16, 
          o:0x5dc0 + r8[al]*32,
          s:0xa000,
          t:0
        };

        yield* sub_2de8();
        r16[di] -= 1;
        r16[di] -= 1;
    case 0x2c5f:
        r16[dx] += 1;
        if (r16[dx] < 0x0014) {
            pc = 0x2c6a;
            break;
        }
        r16[di] -= 0x0028;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x2c6a:
        r16[di] += 1;
        r16[di] += 1;
        r16[si] += 1;
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2c38;
            break;
        }
        r16[di] += 0x0280;
        r16[si] += 0x00ec;
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x2c32;
            break;
        }
    case 0x2c7d:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_2c87() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x2cfb;
            break;
        }
        push(r16[bx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        yield* sub_32f4();
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = memory16get(ds*16+21094);
        r16[di] = memory16get(ds*16+21098);
        r8[dl] = 0x14;
        r8[dh] = memory[ds*16+21108];
        r8[dl] -= r8[dh];
        r8[dl] <<= 1;
        r8[dh] <<= 1;
        bp = 0x000c;
        bp = bp - memory16get(ds*16+21110);
        r8[cl] = 0x04;
        bp <<= r8[cl];
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = r16[ax];
        r8[ch] = r8[ch] ^ r8[ch];
        r16[ax] = 0x0028;
        r16[bx] = 0x00c0;
        r16[bx] -= bp;
    case 0x2ccc:
        r8[cl] = r8[dl];
        rep_movsb_video_video_forward();
        r16[si] -= r16[ax];
        r8[cl] = r8[dh];
        rep_movsb_video_video_forward();
        r16[si] += r16[ax];
        bp -= 1;
        if (bp != 0) {
            pc = 0x2ccc;
            break;
        }
        r16[bx] |= r16[bx];
        if (r16[bx] == 0) {
            pc = 0x2cf5;
            break;
        }
        r16[si] = 0x3e80;
        r8[cl] = r8[dh];
        r16[si] += r16[cx];
    case 0x2ce6:
        r8[cl] = r8[dl];
        rep_movsb_video_video_forward();
        r16[si] -= r16[ax];
        r8[cl] = r8[dh];
        rep_movsb_video_video_forward();
        r16[si] += r16[ax];
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x2ce6;
            break;
        }
    case 0x2cf5:
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[bx] = pop();
        return;
    case 0x2cfb:
        push(r16[bx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = memory16get(ds*16+21094);
        r16[di] = r16[di] ^ r16[di];
        r8[dl] = 0x14;
        r8[dh] = memory[ds*16+21108];
        r8[dl] -= r8[dh];
        r8[dl] <<= 1;
        r8[dh] <<= 1;
        bp = 0x000c;
        bp = bp - memory16get(ds*16+21110);
        r8[cl] = 0x04;
        bp <<= r8[cl];
        es = memory16get(ds*16+21090);
        ds = memory16get(ds*16+21092);
        r8[ch] = r8[ch] ^ r8[ch];
        r16[ax] = 0x0050;
        r16[bx] = 0x00c0;
        r16[bx] -= bp;
    case 0x2d34:
        r8[cl] = r8[dl];
        rep_movsw_video_video_forward();
        r16[si] -= r16[ax];
        r8[cl] = r8[dh];
        rep_movsw_video_video_forward();
        r16[si] += r16[ax];
        bp -= 1;
        if (bp != 0) {
            pc = 0x2d34;
            break;
        }
        r16[bx] |= r16[bx];
        if (r16[bx] == 0) {
            pc = 0x2d5c;
            break;
        }
        r8[cl] = r8[dh];
        r16[si] = r16[cx];
        r16[si] += r16[cx];
    case 0x2d4d:
        r8[cl] = r8[dl];
        rep_movsw_video_video_forward();
        r16[si] -= r16[ax];
        r8[cl] = r8[dh];
        rep_movsw_video_video_forward();
        r16[si] += r16[ax];
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x2d4d;
            break;
        }
    case 0x2d5c:
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_2d62() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        yield* sub_2811();
        memory16set(ds*16+0x5270, r16[ax]);
        memory16set(ds*16+0x5272, r16[ax]);
        memory16set(ds*16+0x5274, r16[ax]);
        memory16set(ds*16+0x5276, r16[ax]);
        yield* sub_2b67();
        r16[di] = memory16get(ds*16+21094);
        es = memory16get(ds*16+21100);
        r16[si] = r16[si] ^ r16[si];
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x2daf;
            break;
        }
        yield* sub_32f4();
        r8[ch] = 0x0c;
    case 0x2d94:
        r8[cl] = 0x14;
    case 0x2d96:
        r8[al] = memory[es*16+r16[si]];
        yield* sub_2de8();
        r16[si] += 1;
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2d96;
            break;
        }
        r16[si] += 0x00ec;
        r16[di] += 0x0258;
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x2d94;
            break;
        }
        pc = 0x2dca;
        break;
    case 0x2daf:
        r8[ch] = 0x0c;
    case 0x2db1:
        r8[cl] = 0x14;
    case 0x2db3:
        r8[al] = memory[es*16+r16[si]];
        yield* sub_2e53();
        r16[si] += 1;
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x2db3;
            break;
        }
        r16[si] += 0x00ec;
        r16[di] += 0x04b0;
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x2db1;
            break;
        }
    case 0x2dca:
        yield* sub_3f46();
        r8[al] = memory[ds*16+0x6521];
        r8[al] = r8[al] | memory[ds*16+25888];
        if (r8[al] != 0) {
            pc = 0x2dca;
            break;
        }
        yield* sub_276f();
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_2ddc() {
    if (memory[cs*16+0x1] < 0x03)
    { yield* sub_2e53(); return; }
    r16[di] += 0x3e80;
    yield* sub_2de8();
}
function* sub_2de8() {
    push(r16[dx]);
    push(es);
    r16[dx] = 0xa000;
    es = r16[dx];
    yield* sub_2df5();
    es = pop();
    r16[dx] = pop();
}
function* sub_2df5() {
    push(r16[si]);
    push(ds);
    r8[ah] = r8[ah] ^ r8[ah];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] = r16[ax];
    r16[si] += 0x5dc0;
    push(es);
    ds = pop();
    bp = 0x0026;
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
    r16[di] -= 0x0258;
    ds = pop();
    r16[si] = pop();
}
function* sub_2e53() {
    push(r16[si]);
    push(ds);
    push(bp);
    push(es);
    r8[ah] = r8[al];
    r8[al] = r8[al] ^ r8[al];
    r16[ax] >>= 1;
    r16[si] = r16[ax];
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = memory16get(ds*16+21092);
    ds = memory16get(cs*16+0xB95E);
    bp = 0x004c;
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
    r16[di] -= 0x04b0;
    es = pop();
    bp = pop();
    ds = pop();
    r16[si] = pop();
}
function* sub_2eb7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[dx] = 0x168f;
        ds = r16[dx];
        es = r16[dx];
        memory[ds*16+0x5250] = r8[al];
        r8[al] += 0x30;
        if (r8[al] <= 0x39) {
            pc = 0x2eca;
            break;
        }
        r8[al] += 0x07;
    case 0x2eca:
        memory[ds*16+0x5256] = r8[al];  // set level char
        r16[di] = 0x72a3;
        r16[cx] = 0x0bf4;
        r8[al] = 0xff;
        rep_stosb_data_forward();
        r16[di] = 0x527c;
        r16[cx] = 0x020a;
        rep_stosw_data_forward();
        yield* sub_32dc();
        r16[dx] = 0x5251;
        yield* sub_097b();
        memory16set(ds*16+0x526c, r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r8[al] = memory[ds*16+0x5250];
        r8[ah] = 0x03;
        _mul8(r8[ah]);
        r16[si] = r16[ax];
        r16[si] += 0x50c8;
        r16[di] = 0x5081;
        r16[cx] = 0x0003;
        rep_movsb_data_data_forward();
        r16[dx] = 0x5057;
        yield* sub_0410();
        r16[ax] = pop();
        yield* sub_3009();
        r16[ax] = 0x168f;
        es = r16[ax];
        r16[di] = 0x72a3;
        r16[cx] = 0x0180;
        rep_movsw_data_data_forward();
        r16[cx] = 0x00f0;
        rep_movsb_data_data_forward();
        r8[cl] = 0x03;
        rep_movsw_data_data_forward();
        r16[cx] = 0x0514;
        rep_movsb_data_data_forward();
        r16[cx] = 0x0190;
        rep_movsb_data_data_forward();
        movsw_data_data_forward();
        r16[cx] = 0x008c;
        rep_movsb_data_data_forward();
        r16[cx] = 0x00c8;
        rep_movsb_data_data_forward();
        movsw_data_data_forward();
        movsw_data_data_forward();
        yield* sub_2f76();
        yield* sub_2fdd();
        r16[ax] = memory16get(ds*16+0x7695);
        memory16set(ds*16+0x64e4, r16[ax]);
        r16[ax] = memory16get(ds*16+0x7697);
        memory16set(ds*16+0x64e6, r16[ax]);
        r16[si] = 0x7dcb;
        r16[cx] = 0x000a;
    case 0x2f57:
        if (memory[es*16+r16[si] + 7] < 0x08) {
            pc = 0x2f64;
            break;
        }
        memory16set(es*16+r16[si] + 4, 0xffff);
    case 0x2f64:
        r16[si] += 0x0014;
        if (--r16[cx]) {
            pc = 0x2f57;
            break;
        }
        r16[si] = 0x75a3;
        r16[di] = 0x7e97;
        r16[cx] = 0x08f4;
        rep_movsb_data_data_forward();
        ds = pop();
        return;
    } while (1);
}
function* sub_2f76() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0100;
        r8[dl] = r8[dl] ^ r8[dl];
    case 0x2f82:
        if (memory[ds*16+r16[bx] + 29859] & 0x80) {
            pc = 0x2f9c;
            break;
        }
        memory[ds*16+r16[bx] + 24804] = r8[bl];
        memory[ds*16+r16[bx] + 25060] = r8[bl];
        memory[ds*16+r16[bx] + 25316] = r8[bl];
        memory[ds*16+r16[bx] + 25572] = 0x00;
        pc = 0x2fd3;
        break;
    case 0x2f9c:
        r8[dl] = 0x01;
        r8[al] = r8[bl];
        memory[ds*16+r16[bx] + 24804] = r8[al];
        memory[ds*16+r16[bx] + 25062] = r8[al];
        memory[ds*16+r16[bx] + 25317] = r8[al];
        r16[ax] += 1;
        memory[ds*16+r16[bx] + 24805] = r8[al];
        memory[ds*16+r16[bx] + 25060] = r8[al];
        memory[ds*16+r16[bx] + 25318] = r8[al];
        r16[ax] += 1;
        memory[ds*16+r16[bx] + 24806] = r8[al];
        memory[ds*16+r16[bx] + 25061] = r8[al];
        memory[ds*16+r16[bx] + 25316] = r8[al];
        memory[ds*16+r16[bx] + 25572] = 0x01;
        memory16set(ds*16+r16[bx] + 25573, 0x0101);
        r16[bx] += 1;
        r16[bx] += 1;
    case 0x2fd3:
        r16[bx] += 1;
        r8[bh] |= r8[bh];
        if (r8[bh] == 0) {
            pc = 0x2f82;
            break;
        }
        memory[ds*16+25845] = r8[dl];
        return;
    } while (1);
}
function* sub_2fdd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = memory16get(ds*16+21100);
        r16[si] = 0x7bad;
        r16[cx] = 0x0064;
    case 0x2ff2:
        r16[di] = memory16get(ds*16+r16[si] + 2);
        if (r16[di] == 0xffff) {
            pc = 0x2ffd;
            break;
        }
        r8[al] = memory[ds*16+r16[si]];
        stosb_data_forward();
    case 0x2ffd:
        r16[si] += 0x0004;
        if (--r16[cx]) {
            pc = 0x2ff2;
            break;
        }
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_3009() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16+21072];
        r8[bh] = memory[ds*16+r16[bx] + 20640];
        memory[ds*16+20619] = r8[bh];
        if (memory[cs*16+0x1] >= 0x03) {
            pc = 0x3044;
            break;
        }
        r8[bl] = r8[bl] ^ r8[bl];
        r8[cl] = 0x04;
        r16[bx] >>= r8[cl];
        r16[ax] += r16[bx];
        ds = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        memory16set(cs*16+0xB95E, r16[ax]);
        memory16set(cs*16+0x6676, 0x66b8);
        r16[cx] = 0x0100;
    case 0x3037:
        r16[ax] = 0x0210;
        yield* sub_65be();
        r16[si] += 0x0080;
        if (--r16[cx]) {
            pc = 0x3037;
            break;
        }
        return;
    case 0x3044:
        r8[bl] = r8[bl] ^ r8[bl];
        r8[cl] = 0x04;
        r16[bx] >>= r8[cl];
        r16[ax] += r16[bx];
        memory16set(ds*16+0x04c1, r16[ax]);
        ds = r16[ax];
        r16[si] = r16[si] ^ r16[si];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[di] = 0x5dc0;
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[bx] = 0x0100;
    case 0x3065:
        r8[al] = 0x01;
    case 0x3067:
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0010;
        rep_movsw_video_data_forward();
        r16[di] -= 0x0020;
        r8[al] <<= 1;
        if (r8[al] < 0x10) {
            pc = 0x3067;
            break;
        }
        r16[di] += 0x0020;
        r16[bx] -= 1;
        if (r16[bx] != 0) {
            pc = 0x3065;
            break;
        }
        return;
    } while (1);
}
function* sub_307d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[cs*16+0x1] == 0xff) {
            pc = 0x308d;
            break;
        }
    {yield* sub_3160(); return; };
    case 0x308d:
        r16[ax] = 0x000d;
        interrupt(16);
        r16[dx] = 0x03c8;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[cx] = 0x001e;
        r16[si] = 0x5057;
    case 0x309f:
        lodsb_data_forward();
        r8[al] &= 0x3f;
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x309f;
            break;
        }
        r16[cx] = 0x001e;
        r16[si] -= r16[cx];
        r8[al] = 0x40;
        r8[dl] = 0xc7;
        out8(r16[dx], r8[al]);
        r8[dl] = 0xc9;
    case 0x30b1:
        r8[ah] = memory[ds*16+r16[si]];
        r16[si] += 1;
        r8[ah] &= 0x3f;
        r8[al] = in8(r16[dx]);
        if (--r16[cx]) {
            pc = 0x30b1;
            break;
        }
        yield* sub_3126();
        if (flags.carry) {
            pc = 0x30e6;
            break;
        }
        memory[cs*16+0x1] = 0x05;
        return;
    case 0x30ca:
        yield* sub_3126();
        if (flags.carry) {
            pc = 0x30e6;
            break;
        }
        memory[cs*16+0x1] = 0x04;
        r8[ah] = 0x12;
        r8[bl] = 0x10;
        interrupt(16);
        r8[bl] |= r8[bl];
        if (r8[bl] != 0) {
            pc = 0x3125;
            break;
        }
        memory[cs*16+0x1] = 0x03;
        return;
    case 0x30e6:
        r16[ax] = 0x0003;
        interrupt(16);
        r8[ah] = 0x0f;
        interrupt(16);
        if (r16[ax] == 0x5003) {
            pc = 0x30fb;
            break;
        }
        memory[cs*16+0x1] = 0x00;
        return;
    case 0x30fb:
        memory[cs*16+0x1] = 0x02;
        r16[ax] = 0x0009;
        interrupt(16);
        r16[ax] = 0xb800;
        es = r16[ax];
        memory[es*16+16384] = 0xff;
        r8[al] = memory[es*16+16384];
        r8[ah] = memory[es*16+0];
        if (r16[ax] == 0x00ff) {
            pc = 0x3125;
            break;
        }
        memory[cs*16+0x1] = 0x01;
    case 0x3125:
        return;
    } while (1);
}
function* sub_3126() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x000d;
        interrupt(16);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0004;
        out16(r16[dx], r16[ax]);
        r8[al] = 0x51;
        memoryVideoSet(es, 8192, r8[al]);
        if (memoryVideoGet(es, 8192) != r8[al]) {
            pc = 0x315e;
            break;
        }
        r16[ax] = 0x0103;
        out16(r16[dx], r16[ax]);
        memoryVideoSet(es, r16[si], 0xaa);
        flags.carry = false;
        return;
    case 0x315e:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_3160() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x01) {
            pc = 0x31c5;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x31c5;
            break;
        }
        if (r8[al] == 0x00) {
            pc = 0x31e9;
            break;
        }
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r16[ax] = 0x000d;
        interrupt(16);
        r16[dx] = 0x03d4;
        r16[ax] = 0x2411;
        out16(r16[dx], r16[ax]);
        memory16set(ds*16+21096, 0x0000);
        memory16set(ds*16+21098, 0x1f40);
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x31a4;
            break;
        }
        if (r8[al] >= 0x03) {
            pc = 0x31bb;
            break;
        }
    case 0x31a4:
        r16[dx] = 0x5046;
        r16[ax] = 0x1002;
        interrupt(16);
        r16[ax] = 0x1012;
        r16[bx] = r16[bx] ^ r16[bx];
        r16[cx] = 0x0010;
        r16[dx] = 0x5057;
        interrupt(16);
        pc = 0x31e7;
        break;
    case 0x31bb:
        r16[dx] = 0x5035;
        r16[ax] = 0x1002;
        interrupt(16);
        pc = 0x31e7;
        break;
    case 0x31c5:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory16set(ds*16+21098, 0x0000);
        memory16set(ds*16+21096, 0x0000);
        memory16set(ds*16+21084, 0x0050);
        memory[cs*16+0x0] = 0x02;
        r16[ax] = 0x0004;
        interrupt(16);
    case 0x31e7:
        pc = 0x3239;
        break;
    case 0x31e9:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory16set(ds*16+21098, 0x0000);
        memory16set(ds*16+21096, 0x0000);
        memory16set(ds*16+21084, 0x0050);
        memory[cs*16+0x0] = 0x02;
        r16[si] = 0x5025;
        r16[dx] = 0x03bf;
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r8[dl] = 0xb8;
        r8[al] = 0x82;
        out8(r16[dx], r8[al]);
        r8[dl] = 0xb4;
        r16[cx] = 0x000e;
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x321b:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        r16[dx] -= 1;
        r8[ah] += 1;
        if (--r16[cx]) {
            pc = 0x321b;
            break;
        }
        r16[cx] = 0x2000;
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[ax] = r16[ax] ^ r16[ax];
        r16[di] = r16[di] ^ r16[di];
        rep_stosw_data_forward();
        r8[dl] = 0xb8;
        r8[al] = 0x8a;
        out8(r16[dx], r8[al]);
    case 0x3239:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_3243() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[dx]);
        if (memory[cs*16+0x1] == 0x00) {
            pc = 0x325f;
            break;
        }
        r16[dx] = 0x03da;
        r8[ah] = 0x08;
    case 0x3252:
        r8[al] = in8(r16[dx]);
        if (r8[ah] & r8[al]) {
            pc = 0x3252;
            break;
        }
    case 0x3257:
        r8[al] = in8(r16[dx]);
        if (!(r8[ah] & r8[al])) {
            pc = 0x3257;
            break;
        }
        r16[dx] = pop();
        r16[ax] = pop();
        return;
    case 0x325f:
        r16[dx] = 0x03ba;
        r8[ah] = 0x01;
    case 0x3264:
        r8[al] = in8(r16[dx]);
        if (r8[ah] & r8[al]) {
            pc = 0x3264;
            break;
        }
    case 0x3269:
        r8[al] = in8(r16[dx]);
        if (!(r8[ah] & r8[al])) {
            pc = 0x3269;
            break;
        }
        r16[dx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_3271() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x32a4;
            break;
        }
        yield* sub_10d3();
        r16[dx] = 0x03d4;
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[bx] = memory16get(ds*16+21098);
        r8[al] = 0x0d;
        r8[ah] = r8[bl];
        out16(r16[dx], r16[ax]);
        r16[ax] -= 1;
        r8[ah] = r8[bh];
        out16(r16[dx], r16[ax]);
        var t = memory16get(ds*16+21096); memory16set(ds*16+21096, r16[bx]); r16[bx] = t;//_xchg(memory16get(ds*16+21096), r16[bx]);
        memory16set(ds*16+21098, r16[bx]);
        if (memory[ds*16+25882] == 0x00) {
            pc = 0x32a3;
            break;
        }
        yield* sub_3243();
    case 0x32a3:
        return;
    case 0x32a4:
        push(ds);
        push(es);
        push(r16[si]);
        push(r16[di]);
        push(r16[dx]);
        push(r16[ax]);
        push(r16[cx]);
        ds = memory16get(ds*16+21090);
        r16[si] = r16[si] ^ r16[si];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r16[dx] = 0x0060;
        r16[ax] = 0x0028;
    case 0x32be:
        r16[cx] = r16[ax];
        rep_movsw_data_data_forward();
        r16[di] += 0x1fb0;
        r16[cx] = r16[ax];
        rep_movsw_data_data_forward();
        r16[di] -= 0x2000;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x32be;
            break;
        }
        yield* sub_10d3();
        r16[cx] = pop();
        r16[ax] = pop();
        r16[dx] = pop();
        r16[di] = pop();
        r16[si] = pop();
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_32dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x32f3;
            break;
        }
        push(r16[ax]);
        push(r16[dx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0005;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[dx] = pop();
        r16[ax] = pop();
    case 0x32f3:
        return;
    } while (1);
}
function* sub_32f4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x330d;
            break;
        }
        push(r16[ax]);
        push(r16[dx]);
        r16[dx] = 0x03ce;
        r16[ax] = 0x0105;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[dx] = pop();
        r16[ax] = pop();
    case 0x330d:
        return;
        _STOP_("db 00h");
        _STOP_("db 40h");
        _STOP_("db 80h");
        _STOP_("db c0h");
        _STOP_("db 10h");
        _STOP_("db 50h");
        _STOP_("db 90h");
        _STOP_("db d0h");
        _STOP_("db 20h");
        _STOP_("db 60h");
        _STOP_("db a0h");
        _STOP_("db e0h");
        _STOP_("db 30h");
        _STOP_("db 70h");
        _STOP_("db b0h");
        _STOP_("db f0h");
        _STOP_("db 04h");
        _STOP_("db 44h");
        _STOP_("db 84h");
        _STOP_("db c4h");
        _STOP_("db 14h");
        _STOP_("db 54h");
        _STOP_("db 94h");
        _STOP_("db d4h");
        _STOP_("db 24h");
        _STOP_("db 64h");
        _STOP_("db a4h");
        _STOP_("db e4h");
        _STOP_("db 34h");
        _STOP_("db 74h");
        _STOP_("db b4h");
        _STOP_("db f4h");
        _STOP_("db 08h");
        _STOP_("db 48h");
        _STOP_("db 88h");
        _STOP_("db c8h");
        _STOP_("db 18h");
        _STOP_("db 58h");
        _STOP_("db 98h");
        _STOP_("db d8h");
        _STOP_("db 28h");
        _STOP_("db 68h");
        _STOP_("db a8h");
        _STOP_("db e8h");
        _STOP_("db 38h");
        _STOP_("db 78h");
        _STOP_("db b8h");
        _STOP_("db f8h");
        _STOP_("db 0ch");
        _STOP_("db 4ch");
        _STOP_("db 8ch");
        _STOP_("db cch");
        _STOP_("db 1ch");
        _STOP_("db 5ch");
        _STOP_("db 9ch");
        _STOP_("db dch");
        _STOP_("db 2ch");
        _STOP_("db 6ch");
        _STOP_("db ach");
        _STOP_("db ech");
        _STOP_("db 3ch");
        _STOP_("db 7ch");
        _STOP_("db bch");
        _STOP_("db fch");
        _STOP_("db 01h");
        _STOP_("db 41h");
        _STOP_("db 81h");
        _STOP_("db c1h");
        _STOP_("db 11h");
        _STOP_("db 51h");
        _STOP_("db 91h");
        _STOP_("db d1h");
        _STOP_("db 21h");
        _STOP_("db 61h");
        _STOP_("db a1h");
        _STOP_("db e1h");
        _STOP_("db 31h");
        _STOP_("db 71h");
        _STOP_("db b1h");
        _STOP_("db f1h");
        _STOP_("db 05h");
        _STOP_("db 45h");
        _STOP_("db 85h");
        _STOP_("db c5h");
        _STOP_("db 15h");
        _STOP_("db 55h");
        _STOP_("db 95h");
        _STOP_("db d5h");
        _STOP_("db 25h");
        _STOP_("db 65h");
        _STOP_("db a5h");
        _STOP_("db e5h");
        _STOP_("db 35h");
        _STOP_("db 75h");
        _STOP_("db b5h");
        _STOP_("db f5h");
        _STOP_("db 09h");
        _STOP_("db 49h");
        _STOP_("db 89h");
        _STOP_("db c9h");
        _STOP_("db 19h");
        _STOP_("db 59h");
        _STOP_("db 99h");
        _STOP_("db d9h");
        _STOP_("db 29h");
        _STOP_("db 69h");
        _STOP_("db a9h");
        _STOP_("db e9h");
        _STOP_("db 39h");
        _STOP_("db 79h");
        _STOP_("db b9h");
        _STOP_("db f9h");
        _STOP_("db 0dh");
        _STOP_("db 4dh");
        _STOP_("db 8dh");
        _STOP_("db cdh");
        _STOP_("db 1dh");
        _STOP_("db 5dh");
        _STOP_("db 9dh");
        _STOP_("db ddh");
        _STOP_("db 2dh");
        _STOP_("db 6dh");
        _STOP_("db adh");
        _STOP_("db edh");
        _STOP_("db 3dh");
        _STOP_("db 7dh");
        _STOP_("db bdh");
        _STOP_("db fdh");
        _STOP_("db 02h");
        _STOP_("db 42h");
        _STOP_("db 82h");
        _STOP_("db c2h");
        _STOP_("db 12h");
        _STOP_("db 52h");
        _STOP_("db 92h");
        _STOP_("db d2h");
        _STOP_("db 22h");
        _STOP_("db 62h");
        _STOP_("db a2h");
        _STOP_("db e2h");
        _STOP_("db 32h");
        _STOP_("db 72h");
        _STOP_("db b2h");
        _STOP_("db f2h");
        _STOP_("db 06h");
        _STOP_("db 46h");
        _STOP_("db 86h");
        _STOP_("db c6h");
        _STOP_("db 16h");
        _STOP_("db 56h");
        _STOP_("db 96h");
        _STOP_("db d6h");
        _STOP_("db 26h");
        _STOP_("db 66h");
        _STOP_("db a6h");
        _STOP_("db e6h");
        _STOP_("db 36h");
        _STOP_("db 76h");
        _STOP_("db b6h");
        _STOP_("db f6h");
        _STOP_("db 0ah");
        _STOP_("db 4ah");
        _STOP_("db 8ah");
        _STOP_("db cah");
        _STOP_("db 1ah");
        _STOP_("db 5ah");
        _STOP_("db 9ah");
        _STOP_("db dah");
        _STOP_("db 2ah");
        _STOP_("db 6ah");
        _STOP_("db aah");
        _STOP_("db eah");
        _STOP_("db 3ah");
        _STOP_("db 7ah");
        _STOP_("db bah");
        _STOP_("db fah");
        _STOP_("db 0eh");
        _STOP_("db 4eh");
        _STOP_("db 8eh");
        _STOP_("db ceh");
        _STOP_("db 1eh");
        _STOP_("db 5eh");
        _STOP_("db 9eh");
        _STOP_("db deh");
        _STOP_("db 2eh");
        _STOP_("db 6eh");
        _STOP_("db aeh");
        _STOP_("db eeh");
        _STOP_("db 3eh");
        _STOP_("db 7eh");
        _STOP_("db beh");
        _STOP_("db feh");
        _STOP_("db 03h");
        _STOP_("db 43h");
        _STOP_("db 83h");
        _STOP_("db c3h");
        _STOP_("db 13h");
        _STOP_("db 53h");
        _STOP_("db 93h");
        _STOP_("db d3h");
        _STOP_("db 23h");
        _STOP_("db 63h");
        _STOP_("db a3h");
        _STOP_("db e3h");
        _STOP_("db 33h");
        _STOP_("db 73h");
        _STOP_("db b3h");
        _STOP_("db f3h");
        _STOP_("db 07h");
        _STOP_("db 47h");
        _STOP_("db 87h");
        _STOP_("db c7h");
        _STOP_("db 17h");
        _STOP_("db 57h");
        _STOP_("db 97h");
        _STOP_("db d7h");
        _STOP_("db 27h");
        _STOP_("db 67h");
        _STOP_("db a7h");
        _STOP_("db e7h");
        _STOP_("db 37h");
        _STOP_("db 77h");
        _STOP_("db b7h");
        _STOP_("db f7h");
        _STOP_("db 0bh");
        _STOP_("db 4bh");
        _STOP_("db 8bh");
        _STOP_("db cbh");
        _STOP_("db 1bh");
        _STOP_("db 5bh");
        _STOP_("db 9bh");
        _STOP_("db dbh");
        _STOP_("db 2bh");
        _STOP_("db 6bh");
        _STOP_("db abh");
        _STOP_("db ebh");
        _STOP_("db 3bh");
        _STOP_("db 7bh");
        _STOP_("db bbh");
        _STOP_("db fbh");
        _STOP_("db 0fh");
        _STOP_("db 4fh");
        _STOP_("db 8fh");
        _STOP_("db cfh");
        _STOP_("db 1fh");
        _STOP_("db 5fh");
        _STOP_("db 9fh");
        _STOP_("db dfh");
        _STOP_("db 2fh");
        _STOP_("db 6fh");
        _STOP_("db afh");
        _STOP_("db efh");
        _STOP_("db 3fh");
        _STOP_("db 7fh");
        _STOP_("db bfh");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 80h");
        _STOP_("db 40h");
        _STOP_("db c0h");
        _STOP_("db 20h");
        _STOP_("db a0h");
        _STOP_("db 60h");
        _STOP_("db e0h");
        _STOP_("db 10h");
        _STOP_("db 90h");
        _STOP_("db 50h");
        _STOP_("db d0h");
        _STOP_("db 30h");
        _STOP_("db b0h");
        _STOP_("db 70h");
        _STOP_("db f0h");
        _STOP_("db 08h");
        _STOP_("db 88h");
        _STOP_("db 48h");
        _STOP_("db c8h");
        _STOP_("db 28h");
        _STOP_("db a8h");
        _STOP_("db 68h");
        _STOP_("db e8h");
        _STOP_("db 18h");
        _STOP_("db 98h");
        _STOP_("db 58h");
        _STOP_("db d8h");
        _STOP_("db 38h");
        _STOP_("db b8h");
        _STOP_("db 78h");
        _STOP_("db f8h");
        _STOP_("db 04h");
        _STOP_("db 84h");
        _STOP_("db 44h");
        _STOP_("db c4h");
        _STOP_("db 24h");
        _STOP_("db a4h");
        _STOP_("db 64h");
        _STOP_("db e4h");
        _STOP_("db 14h");
        _STOP_("db 94h");
        _STOP_("db 54h");
        _STOP_("db d4h");
        _STOP_("db 34h");
        _STOP_("db b4h");
        _STOP_("db 74h");
        _STOP_("db f4h");
        _STOP_("db 0ch");
        _STOP_("db 8ch");
        _STOP_("db 4ch");
        _STOP_("db cch");
        _STOP_("db 2ch");
        _STOP_("db ach");
        _STOP_("db 6ch");
        _STOP_("db ech");
        _STOP_("db 1ch");
        _STOP_("db 9ch");
        _STOP_("db 5ch");
        _STOP_("db dch");
        _STOP_("db 3ch");
        _STOP_("db bch");
        _STOP_("db 7ch");
        _STOP_("db fch");
        _STOP_("db 02h");
        _STOP_("db 82h");
        _STOP_("db 42h");
        _STOP_("db c2h");
        _STOP_("db 22h");
        _STOP_("db a2h");
        _STOP_("db 62h");
        _STOP_("db e2h");
        _STOP_("db 12h");
        _STOP_("db 92h");
        _STOP_("db 52h");
        _STOP_("db d2h");
        _STOP_("db 32h");
        _STOP_("db b2h");
        _STOP_("db 72h");
        _STOP_("db f2h");
        _STOP_("db 0ah");
        _STOP_("db 8ah");
        _STOP_("db 4ah");
        _STOP_("db cah");
        _STOP_("db 2ah");
        _STOP_("db aah");
        _STOP_("db 6ah");
        _STOP_("db eah");
        _STOP_("db 1ah");
        _STOP_("db 9ah");
        _STOP_("db 5ah");
        _STOP_("db dah");
        _STOP_("db 3ah");
        _STOP_("db bah");
        _STOP_("db 7ah");
        _STOP_("db fah");
        _STOP_("db 06h");
        _STOP_("db 86h");
        _STOP_("db 46h");
        _STOP_("db c6h");
        _STOP_("db 26h");
        _STOP_("db a6h");
        _STOP_("db 66h");
        _STOP_("db e6h");
        _STOP_("db 16h");
        _STOP_("db 96h");
        _STOP_("db 56h");
        _STOP_("db d6h");
        _STOP_("db 36h");
        _STOP_("db b6h");
        _STOP_("db 76h");
        _STOP_("db f6h");
        _STOP_("db 0eh");
        _STOP_("db 8eh");
        _STOP_("db 4eh");
        _STOP_("db ceh");
        _STOP_("db 2eh");
        _STOP_("db aeh");
        _STOP_("db 6eh");
        _STOP_("db eeh");
        _STOP_("db 1eh");
        _STOP_("db 9eh");
        _STOP_("db 5eh");
        _STOP_("db deh");
        _STOP_("db 3eh");
        _STOP_("db beh");
        _STOP_("db 7eh");
        _STOP_("db feh");
        _STOP_("db 01h");
        _STOP_("db 81h");
        _STOP_("db 41h");
        _STOP_("db c1h");
        _STOP_("db 21h");
        _STOP_("db a1h");
        _STOP_("db 61h");
        _STOP_("db e1h");
        _STOP_("db 11h");
        _STOP_("db 91h");
        _STOP_("db 51h");
        _STOP_("db d1h");
        _STOP_("db 31h");
        _STOP_("db b1h");
        _STOP_("db 71h");
        _STOP_("db f1h");
        _STOP_("db 09h");
        _STOP_("db 89h");
        _STOP_("db 49h");
        _STOP_("db c9h");
        _STOP_("db 29h");
        _STOP_("db a9h");
        _STOP_("db 69h");
        _STOP_("db e9h");
        _STOP_("db 19h");
        _STOP_("db 99h");
        _STOP_("db 59h");
        _STOP_("db d9h");
        _STOP_("db 39h");
        _STOP_("db b9h");
        _STOP_("db 79h");
        _STOP_("db f9h");
        _STOP_("db 05h");
        _STOP_("db 85h");
        _STOP_("db 45h");
        _STOP_("db c5h");
        _STOP_("db 25h");
        _STOP_("db a5h");
        _STOP_("db 65h");
        _STOP_("db e5h");
        _STOP_("db 15h");
        _STOP_("db 95h");
        _STOP_("db 55h");
        _STOP_("db d5h");
        _STOP_("db 35h");
        _STOP_("db b5h");
        _STOP_("db 75h");
        _STOP_("db f5h");
        _STOP_("db 0dh");
        _STOP_("db 8dh");
        _STOP_("db 4dh");
        _STOP_("db cdh");
        _STOP_("db 2dh");
        _STOP_("db adh");
        _STOP_("db 6dh");
        _STOP_("db edh");
        _STOP_("db 1dh");
        _STOP_("db 9dh");
        _STOP_("db 5dh");
        _STOP_("db ddh");
        _STOP_("db 3dh");
        _STOP_("db bdh");
        _STOP_("db 7dh");
        _STOP_("db fdh");
        _STOP_("db 03h");
        _STOP_("db 83h");
        _STOP_("db 43h");
        _STOP_("db c3h");
        _STOP_("db 23h");
        _STOP_("db a3h");
        _STOP_("db 63h");
        _STOP_("db e3h");
        _STOP_("db 13h");
        _STOP_("db 93h");
        _STOP_("db 53h");
        _STOP_("db d3h");
        _STOP_("db 33h");
        _STOP_("db b3h");
        _STOP_("db 73h");
        _STOP_("db f3h");
        _STOP_("db 0bh");
        _STOP_("db 8bh");
        _STOP_("db 4bh");
        _STOP_("db cbh");
        _STOP_("db 2bh");
        _STOP_("db abh");
        _STOP_("db 6bh");
        _STOP_("db ebh");
        _STOP_("db 1bh");
        _STOP_("db 9bh");
        _STOP_("db 5bh");
        _STOP_("db dbh");
        _STOP_("db 3bh");
        _STOP_("db bbh");
        _STOP_("db 7bh");
        _STOP_("db fbh");
        _STOP_("db 07h");
        _STOP_("db 87h");
        _STOP_("db 47h");
        _STOP_("db c7h");
        _STOP_("db 27h");
        _STOP_("db a7h");
        _STOP_("db 67h");
        _STOP_("db e7h");
        _STOP_("db 17h");
        _STOP_("db 97h");
        _STOP_("db 57h");
        _STOP_("db d7h");
        _STOP_("db 37h");
        _STOP_("db b7h");
        _STOP_("db 77h");
        _STOP_("db f7h");
        _STOP_("db 0fh");
        _STOP_("db 8fh");
        _STOP_("db 4fh");
        _STOP_("db cfh");
        _STOP_("db 2fh");
        _STOP_("db afh");
        _STOP_("db 6fh");
        _STOP_("db efh");
        _STOP_("db 1fh");
        _STOP_("db 9fh");
        _STOP_("db 5fh");
        _STOP_("db dfh");
        _STOP_("db 3fh");
        _STOP_("db bfh");
        _STOP_("db 7fh");
        _STOP_("db ffh");
    case 0x350e:
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        memory[ds*16+21072] = 0x00;
        memory[ds*16+25880] = 0x00;
        r16[di] = 0x527c;
        r16[cx] = 0x003a;
    case 0x3525:
        memory16set(ds*16+r16[di] + 4, 0xffff);
        r16[di] += 0x0012;
        if (--r16[cx]) {
            pc = 0x3525;
            break;
        }
        memory16set(ds*16+21120, 0x0157);
        memory16set(ds*16+21116, 0xff9c);
        memory16set(ds*16+21118, 0x00b4);
        memory16set(ds*16+21128, 0x6609);
        memory16set(ds*16+21174, 0x0151);
        memory16set(ds*16+21170, 0x01a4);
        memory16set(ds*16+21172, 0x00b4);
        memory16set(ds*16+21182, 0x65e3);
    case 0x355f:
        yield* sub_3f46();
        yield* sub_2ba2();
        r16[si] = 0x527c;
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + 0x0003);
        yield* sub_3611();
        r16[si] = 0x52b2;
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - 0x0003);
        yield* sub_3611();
        yield* sub_2c87();
        yield* sub_1c61();
        yield* sub_3271();
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] += 0x001c;
        if (memory16gets(ds*16+21170) > r16s[ax]) {
            pc = 0x355f;
            break;
        }
        memory16set(ds*16+21174, 0x815a);
        memory16set(ds*16+21170, memory16get(ds*16+21170) - 0x0018);
        r16[si] = 0x527c;
        memory16set(ds*16+21128, 0x661d);
        memory16set(ds*16+21118, memory16get(ds*16+21118) - 0x0010);
        r16[cx] = 0x0010;
    case 0x35a8:
        push(r16[cx]);
        yield* sub_3611();
        yield* sub_3f46();
        yield* sub_2ba2();
        yield* sub_2c87();
        yield* sub_1c61();
        yield* sub_3271();
        memory16set(ds*16+21118, memory16get(ds*16+21118) + 1);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x35a8;
            break;
        }
        memory16set(ds*16+21120, 0x0163);
        r16[si] = 0x663f;
    case 0x35cb:
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x527c, r16[ax]);
        lodsb_data_forward();
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x527e, r16[ax]);
        push(r16[si]);
        yield* sub_3f46();
        yield* sub_2ba2();
        yield* sub_2c87();
        yield* sub_1c61();
        yield* sub_3271();
        yield* sub_0805();
        r16[si] = pop();
        if (memory[ds*16+1067] != 0x00) {
            pc = 0x35fd;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        if (r16[ax] != 0xffdc) {
            pc = 0x35cb;
            break;
        }
        r16[si] += r16[ax];
        pc = 0x35cb;
        break;
    case 0x35fd:
        r16[ax] = 0x014f;
        r16[dx] = 0x0150;
        r16[si] = 0x527c;
        yield* sub_372f();
        yield* sub_1a59();
        r16[ax] = 0x0001;
        flags.carry = true;
        return;
    } while (1);
}
function* sub_3611() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 12);
        r16[bx] += 1;
        r16[bx] += 1;
    case 0x3616:
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x3620;
            break;
        }
        r16[bx] += r16[ax];
        pc = 0x3616;
        break;
    case 0x3620:
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        memory16set(ds*16+r16[si] + 12, r16[bx]);
        return;
    } while (1);
}
function* sub_3627() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = r16[ax] ^ r16[ax];
        if (memory[ds*16+25881] == 0x01) {
            pc = 0x364e;
            break;
        }
        r16[ax] += 1;
        if (memory[ds*16+25879] != 0x01) {
            pc = 0x363b;
            break;
        }
        pc = 0x3710;
        break;
    case 0x363b:
        if (memory[ds*16+25878] == 0x01) {
            pc = 0x3660;
            break;
        }
        if (memory[ds*16+25880] != 0x01) {
            pc = 0x364c;
            break;
        }
        _STOP_("goto loc_350e");
    case 0x364c:
        flags.carry = false;
        return;
    case 0x364e:
        yield* sub_0173();
        memory[ds*16+1049] = 0x10;
        yield* sub_378d();
        r16[ax] = r16[ax] ^ r16[ax];
        memory16set(ds*16+0x64fa, r16[ax]);
        flags.carry = true;
        return;
    case 0x3660:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x0001;
        yield* sub_10ff();
        yield* sub_4ae9();
        memory16set(ds*16+21120, 0x000d);
        memory16set(ds*16+21130, 0x000f);
        r16[cx] = 0x003c;
    case 0x3681:
        push(r16[cx]);
        yield* sub_2c87();
        yield* sub_39c7();
        yield* sub_1c61();
        yield* sub_3271();
        yield* sub_3243();
        r16[ax] = memory16get(ds*16+0x528a);
        r16[ax] -= 1;
        if (r16s[ax] >= signed16(0xfff0)) {
            pc = 0x369d;
            break;
        }
        r16[ax] = 0xfff0;
    case 0x369d:
        memory16set(ds*16+0x528a, r16[ax]);
        memory16set(ds*16+21118, memory16get(ds*16+21118) - r16[ax]);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x3681;
            break;
        }
        yield* sub_378d();
        r16[ax] = memory16get(ds*16+0x64e4);
        memory16set(ds*16+0x527c, r16[ax]);
        r16[ax] = memory16get(ds*16+0x64e6);
        memory16set(ds*16+0x527e, r16[ax]);
        if (memory16get(ds*16+25850) == 0x0000) {
            pc = 0x36e3;
            break;
        }
        r16[si] = 0x52a0;
        r16[cx] = 0x0028;
    case 0x36c3:
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] -= 0x0038;
        if (r16[bx] > 0x0001) {
            pc = 0x36de;
            break;
        }
        r16[ax] = memory16get(ds*16+0x64f8);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+0x64fa);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        pc = 0x36e3;
        break;
    case 0x36de:
        r16[si] += 0x0012;
        if (--r16[cx]) {
            pc = 0x36c3;
            break;
        }
    case 0x36e3:
        memory[ds*16+1049] = 0x10;
        yield* sub_17eb();
        r16[ax] = 0x0000;
        yield* sub_10ff();
        yield* sub_01d9();
        r8[bl] = memory[ds*16+21072];
        r8[bh] = r8[bh] ^ r8[bh];
        r8[al] = memory[ds*16+r16[bx] + 20620];
        _cbw();
        yield* sub_10ff();
        yield* sub_2d62();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        flags.carry = false;
        return;
    case 0x3710:
        r16[ax] = 0x0002;
        yield* sub_10ff();
        memory[ds*16+1049] = 0x10;
        memory[ds*16+1050] = 0x00;
        memory16set(ds*16+21120, 0x000d);
        r16[si] = 0x528e;
        r16[ax] = 0x014d;
        r16[dx] = 0x014e;
        yield* sub_372f();
        return;
    } while (1);
}
function* sub_372f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        _lea(di, ds, r16[si] + 18);
        r8[cl] = 0x04;
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+0x5270);
        r16[ax] <<= r8[cl];
        r16[ax] -= 0x0076;
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+0x5272);
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0064;
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        memory16set(ds*16+r16[di] + 4, r16[dx]);
        r16[ax] = memory16get(ds*16+0x5270);
        r16[ax] <<= r8[cl];
        r16[ax] += 0x01b6;
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+0x5272);
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0064;
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[cx] = 0x001f;
    case 0x3767:
        push(r16[cx]);
        yield* sub_2c87();
        yield* sub_1c61();
        yield* sub_3271();
        r16[cx] = pop();
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + 0x0008);
        memory16set(ds*16+r16[di], memory16get(ds*16+r16[di]) - 0x0008);
        if (--r16[cx]) {
            pc = 0x3767;
            break;
        }
        yield* sub_1a2a();
        memory[ds*16+21072] = 0x00;
        memory16set(ds*16+25850, 0x0000);
        r16[ax] = 0x0001;
        flags.carry = true;
        return;
    } while (1);
}
function* sub_378d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r16[di] = 0x64fc;
        r16[cx] = 0x002b;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[si] = 0x7e97;
        r16[di] = 0x75a3;
        r16[cx] = 0x08f4;
        rep_movsb_data_data_forward();
        memory[ds*16+0x6504] = r8[al];
        memory[ds*16+0x6510] = r8[al];
        memory[ds*16+25873] = 0x04;
        memory[ds*16+0x650d] = r8[al];
        memory[ds*16+0x6512] = r8[al];
        memory[ds*16+0x6514] = r8[al];
        memory[ds*16+0x6513] = r8[al];
        memory[ds*16+0x6505] = r8[al];
        memory[ds*16+0x650a] = r8[al];
        memory[ds*16+0x6509] = r8[al];
        memory[ds*16+0x6502] = r8[al];
        memory[ds*16+0x6517] = r8[al];
        memory[ds*16+0x6519] = r8[al];
        memory[ds*16+0x6516] = r8[al];
        memory[ds*16+0x651b] = r8[al];
        memory[ds*16+0x6500] = r8[al];
        r16[ax] = 0xffff;
        r16[si] = 0x5600;
        r16[cx] = 0x0004;
    case 0x37e5:
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[si] += 0x0012;
        if (--r16[cx]) {
            pc = 0x37e5;
            break;
        }
        yield* sub_56cc();
        yield* sub_3ee8();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_37f5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+21127] != 0x00) {
            pc = 0x3820;
            break;
        }
        if (memory[ds*16+25884] != 0x01) {
            pc = 0x3820;
            break;
        }
        if (memory16get(ds*16+25886) < 0x008c) {
            pc = 0x3820;
            break;
        }
        r8[al] = 0x1d;
        if (memory16get(ds*16+25886) < 0x00af) {
            pc = 0x381d;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
        memory16set(ds*16+25886, 0x0000);
    case 0x381d:
        memory[ds*16+0x5280] = r8[al];
    case 0x3820:
        r16[si] = 0x528e;
        r16[cx] = 0x0029;
        r16[bx] = memory16get(ds*16+25854);
    case 0x382a:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        if (!(r8[ah] & 0x20)) {
            pc = 0x38ab;
            break;
        }
        if (r16[ax] == 0xffff) {
            pc = 0x38ab;
            break;
        }
        if (r8[bl] & 0x07) {
            pc = 0x386f;
            break;
        }
        r8[dl] = r8[al];
        r8[dl] -= 0x38;
        if (r8[dl] == 0) {
            pc = 0x384f;
            break;
        }
        if (r8[dl] > 0x01) {
            pc = 0x385a;
            break;
        }
        if (memory[ds*16+25854] & 0x3f) {
            pc = 0x38ab;
            break;
        }
    case 0x384f:
        r8[dl] = r8[dl] ^ 0x01;
        r8[dl] += 0x38;
        memory[ds*16+r16[si] + 4] = r8[dl];
        pc = 0x38ab;
        break;
    case 0x385a:
        r8[dl] = r8[al];
        r8[dl] -= 0x33;
        if (r8[dl] > 0x01) {
            pc = 0x386f;
            break;
        }
        r8[dl] = r8[dl] ^ 0x01;
        r8[dl] += 0x33;
        memory[ds*16+r16[si] + 4] = r8[dl];
        pc = 0x38ab;
        break;
    case 0x386f:
        if (r8[bl] & 0x01) {
            pc = 0x38ab;
            break;
        }
        r8[dl] = r8[al];
        r8[dl] -= 0x36;
        if (r8[dl] > 0x01) {
            pc = 0x38ab;
            break;
        }
        r8[dl] = 0x37;
        if (memory[ds*16+r16[si] + 8] == 0x00) {
            pc = 0x38a6;
            break;
        }
        r8[dh] = 0x01;
        if (memory[ds*16+25873] <= 0x01) {
            pc = 0x3891;
            break;
        }
        r8[dh] = r8[dh] ^ r8[dh];
    case 0x3891:
        memory[ds*16+r16[si] + 8] &= r8[dh];
        r8[dl] -= 1;
        if (r8[al] == 0x36) {
            pc = 0x38a6;
            break;
        }
        r16[di] = memory16get(ds*16+r16[si] + 9);
        memory16set(ds*16+r16[di] + 2, memory16get(ds*16+r16[di] + 2) + 0x0005);
        memory[ds*16+25873] = 0x03;
    case 0x38a6:
        memory[ds*16+r16[si] + 4] = r8[dl];
        pc = 0x38ab;
        break;
    case 0x38ab:
        r16[si] += 0x0012;
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x38b4;
            break;
        }
        pc = 0x382a;
        break;
    case 0x38b4:
        return;
    } while (1);
}
function* sub_38b5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[ds*16+25853] != 0x00) {
            pc = 0x3937;
            break;
        }
        if (memory[ds*16+21072] != 0x09) {
            pc = 0x38d6;
            break;
        }
        r16[ax] = memory16get(ds*16+0x5292);
        r8[ah] &= 0x1f;
        r16[ax] -= 0x0038;
        if (r16[ax] > 0x0001) {
            pc = 0x3937;
            break;
        }
    case 0x38d6:
        if (memory[ds*16+21072] != 0x10) {
            pc = 0x38e2;
            break;
        }
        memory[ds*16+25880] = 0x01;
    case 0x38e2:
        r16[ax] = memory16get(ds*16+0x527c);
        r8[al] &= 0xf0;
        if (memory16get(ds*16+32403) == r16[ax]) {
            pc = 0x38f6;
            break;
        }
        r16[ax] -= 0x0010;
        if (memory16get(ds*16+32403) != r16[ax]) {
            pc = 0x3937;
            break;
        }
    case 0x38f6:
        r16[ax] = memory16get(ds*16+0x527e);
        r8[al] &= 0xf0;
        if (memory16get(ds*16+32405) == r16[ax]) {
            pc = 0x390a;
            break;
        }
        r16[ax] -= 0x0010;
        if (memory16get(ds*16+32405) != r16[ax]) {
            pc = 0x3937;
            break;
        }
    case 0x390a:
        r16[ax] = 0x0004;
        yield* sub_10ff();
        yield* sub_17eb();
        yield* sub_2811();
        r8[bl] = memory[ds*16+21072];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[si] = 0x523c;
        r8[al] = memory[ds*16+r16[bx] + r16[si]];
        r16[ax] += 1;
    case 0x3922:
        if (memory[ds*16+r16[si]] == r8[al]) {
            pc = 0x3929;
            break;
        }
        r16[si] += 1;
        pc = 0x3922;
        break;
    case 0x3929:
        r16[ax] = r16[si];
        r16[ax] -= 0x523c;
        memory[ds*16+0x5250] = r8[al];
        memory[ds*16+25881] = 0x01;
        return;
    case 0x3937:
        if (memory[ds*16+25872] == 0x00) {
            pc = 0x395d;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+0x527e);
        sar16(ax, r8[cl]);
        r8[dh] = r8[al];
        r16[ax] = memory16get(ds*16+0x527c);
        sar16(ax, r8[cl]);
        r8[dl] = r8[al];
        r16[si] = 0x7d3f;
        r16[cx] = 0x0014;
    case 0x3954:
        if (memory16get(ds*16+r16[si]) == r16[dx]) {
            pc = 0x395e;
            break;
        }
        r16[si] += 0x0007;
        if (--r16[cx]) {
            pc = 0x3954;
            break;
        }
    case 0x395d:
        return;
    case 0x395e:
        memory16set(ds*16+21122, 0x0000);
        memory16set(ds*16+21130, 0x0000);
        yield* sub_2811();
        push(memory16get(ds*16+32061));
        push(r16[si]);
        memory16set(ds*16+32061, 0x00ec);
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r8[cl] = 0x04;
        r8[dl] = r8[al];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[dx] <<= r8[cl];
        memory16set(ds*16+21116, r16[dx]);
        r8[dl] = r8[ah];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[dx] <<= r8[cl];
        memory16set(ds*16+21118, r16[dx]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
    case 0x3994:
        if (memory[ds*16+21106] == r8[ah]) {
            pc = 0x39a6;
            break;
        }
        if (memory[ds*16+21106] < r8[ah]) {
            pc = 0x39a1;
            break;
        }
        yield* sub_2911();
        pc = 0x3994;
        break;
    case 0x39a1:
        yield* sub_294c();
        pc = 0x3994;
        break;
    case 0x39a6:
        if (memory[ds*16+21104] == r8[al]) {
            pc = 0x39b8;
            break;
        }
        if (memory[ds*16+21104] < r8[al]) {
            pc = 0x39b3;
            break;
        }
        yield* sub_2994();
        pc = 0x39a6;
        break;
    case 0x39b3:
        yield* sub_29b5();
        pc = 0x39a6;
        break;
    case 0x39b8:
        r16[si] = pop();
        memory16set(ds*16+32061, pop());
        r8[al] = memory[ds*16+r16[si] + 6];
        memory[ds*16+0x6502] = r8[al];
        yield* sub_276f();
        return;
    } while (1);
}
function* sub_39c7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+25873] != 0x00) {
            pc = 0x39d1;
            break;
        }
        pc = 0x3d96;
        break;
    case 0x39d1:
        es = memory16get(ds*16+21100);
        memory16set(ds*16+25835, 0x0028);
        r16[si] = 0x52a0;
        r8[cl] = 0x04;
    case 0x39e0:
        if (memory16get(ds*16+r16[si] + 4) != 0xffff) {
            pc = 0x39e9;
            break;
        }
        pc = 0x3d8a;
        break;
    case 0x39e9:
        r16[ax] = memory16get(ds*16+r16[si]);
        if (r16s[ax] > signed16(0x0008)) {
            pc = 0x39fa;
            break;
        }
        memory16set(ds*16+r16[si] + 6, 0x0020);
        memory16set(ds*16+r16[si] + 14, 0x0000);
    case 0x39fa:
        if (r16s[ax] < signed16(0x0ff8)) {
            pc = 0x3a09;
            break;
        }
        memory16set(ds*16+r16[si] + 6, 0xffe0);
        memory16set(ds*16+r16[si] + 14, 0x0000);
    case 0x3a09:
        r8[ah] = memory[ds*16+r16[si] + 4];
        r8[al] = r8[ah];
        if (memory16get(ds*16+25854) & 0x0003) {
            pc = 0x3a42;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 14) <= signed16(0x0000)) {
            pc = 0x3a42;
            break;
        }
        if (memory[ds*16+25859] == 0x02) {
            pc = 0x3a42;
            break;
        }
        r8[al] -= 0x31;
        if (r8[al] == 0) {
            pc = 0x3a30;
            break;
        }
        r8[al] -= 1;
        if (r8[al] != 0) {
            pc = 0x3a42;
            break;
        }
        memory16set(ds*16+r16[si] + 6, 0x0000);
    case 0x3a30:
        _ASSERT(0);
        _sar(memory16get(ds*16+r16[si] + 6), 1);
        memory16set(ds*16+r16[si] + 4, memory16get(ds*16+r16[si] + 4) + 1);
        memory[ds*16+25859] = 0x01;
        memory[ds*16+25860] = 0xc8;
        pc = 0x3a85;
        break;
    case 0x3a42:
        r8[ah] -= 0x33;
        if (r8[ah] > 0x01) {
            pc = 0x3a85;
            break;
        }
        memory[ds*16+25873] = 0x04;
        if (memory[ds*16+25859] == 0x00) {
            pc = 0x3a6f;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
        memory16set(ds*16+r16[si] + 12, r16[dx]);
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] -= 0x0008;
        if (memory16get(ds*16+r16[si] + 2) == r16[ax]) {
            pc = 0x3a6c;
            break;
        }
        r8[dl] = 0x10;
        if (memory16gets(ds*16+r16[si] + 2) < r16s[ax]) {
            pc = 0x3a6c;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x3a6c:
        memory16set(ds*16+r16[si] + 14, r16[dx]);
    case 0x3a6f:
        if (memory[ds*16+25860] != 0x00) {
            pc = 0x3a85;
            break;
        }
        memory16set(ds*16+r16[si] + 4, 0x0031);
        memory16set(ds*16+r16[si] + 6, 0x0000);
        memory[ds*16+25859] = 0x02;
    case 0x3a85:
        if (memory16get(ds*16+r16[si] + 6) != 0x0000) {
            pc = 0x3a8e;
            break;
        }
        pc = 0x3b25;
        break;
    case 0x3a8e:
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        sar16(ax, r8[cl]);
        if (memory[ds*16+r16[si] + 2] & 0x0f) {
            pc = 0x3a9a;
            break;
        }
        r16[ax] -= 1;
    case 0x3a9a:
        xchg8(al, ah);
        r16[di] = memory16get(ds*16+r16[si]);
        sar16(di, r8[cl]);
        r16[di] += r16[ax];
        r16[bx] = 0x72a3;
        r8[al] = memory[es*16+r16[di]];
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] != 0) {
            pc = 0x3ade;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = memory16get(ds*16+r16[si] + 6);
        sar16(dx, r8[cl]);
        r16[dx] += r16[ax];
        sar16(dx, r8[cl]);
        sar16(ax, r8[cl]);
        if (r16[ax] == r16[dx]) {
            pc = 0x3ae8;
            break;
        }
        r16[ax] = 0x0001;
        if (!(memory[ds*16+r16[si] + 7] & 0x80)) {
            pc = 0x3ac9;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3ac9:
        r16[di] += r16[ax];
        r16[dx] = memory16get(ds*16+r16[si]);
        sar16(dx, r8[cl]);
        r16[ax] += r16[dx];
        if (r16[ax] >= 0x0100) {
            pc = 0x3ade;
            break;
        }
        r8[al] = memory[es*16+r16[di]];
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x3ae8;
            break;
        }
    case 0x3ade:
        memory16set(ds*16+r16[si] + 6, -memory16get(ds*16+r16[si] + 6));
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
    case 0x3ae8:
        memory[ds*16+25873] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x3af6;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3af6:
        r16[dx] = 0x0003;
        if (r16[ax] < 0x0010) {
            pc = 0x3b00;
            break;
        }
        r8[dl] = 0x01;
    case 0x3b00:
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x3b09;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x3b09:
        bp = r16[ax];
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
        r16[ax] = bp;
        r16[ax] -= r16[dx];
        r16[dx] = r16[ax];
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x3b1b;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3b1b:
        if (r16[ax] >= 0x0010) {
            pc = 0x3b22;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x3b22:
        memory16set(ds*16+r16[si] + 6, r16[dx]);
    case 0x3b25:
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        sar16(ax, r8[cl]);
        memory16set(ds*16+0x64ed, r16[ax]);
        xchg8(al, ah);
        r16[di] = memory16get(ds*16+r16[si]);
        sar16(di, r8[cl]);
        r16[di] += r16[ax];
        if (memory16gets(ds*16+r16[si] + 14) >= signed16(0x0000)) {
            pc = 0x3b8a;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[al] = memory[ds*16+r16[bx] + 27640];
        r8[al] >>= r8[cl];
        _cbw();
        r16[ax] += 1;
        xchg8(al, ah);
        r16[di] -= r16[ax];
        r16[bx] = 0x74a3;
        r8[al] = memory[es*16+r16[di]];
        _xlatds();
        r8[al] &= 0x7f;
        if (r8[al] != 0) {
            pc = 0x3b78;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] + memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+25837);
        if (r16[ax] != 0) {
            pc = 0x3b6b;
            break;
        }
        pc = 0x3d5a;
        break;
    case 0x3b6b:
        r8[al] = memory[es*16+((r16[di] + 65280) & 0xffff)];
        _xlatds();
        r8[al] &= 0x7f;
        if (r8[al] != 0) {
            pc = 0x3b78;
            break;
        }
        pc = 0x3d5a;
        break;
    case 0x3b78:
        memory16set(ds*16+r16[si] + 14, 0x0000);
        push(r16[si]);
        yield* sub_5133();
        if (!flags.zero) {
            pc = 0x3b87;
            break;
        }
        memory[ds*16+r16[si] + 2] &= 0xf0;
    case 0x3b87:
        pc = 0x3d8a;
        break;
    case 0x3b8a:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r16[dx] = r16[ax];
        r8[dh] &= 0x1f;
        if (memory[ds*16+r16[si] + 11] & 0x01) {
            pc = 0x3ba8;
            break;
        }
        r16[bx] = r16[dx];
        if (!(memory[ds*16+r16[bx] + 28441] & 0x08)) {
            pc = 0x3bb8;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 14) < signed16(0x00a0)) {
            pc = 0x3bb8;
            break;
        }
    case 0x3ba8:
        if (!(r8[ah] & 0x20)) {
            pc = 0x3bb0;
            break;
        }
        pc = 0x3d5a;
        break;
    case 0x3bb0:
        memory16set(ds*16+r16[si] + 4, 0xffff);
        pc = 0x3d8a;
        break;
    case 0x3bb8:
        r16[bx] = 0x72a3;
        r8[al] = memory[es*16+r16[di]];
        r8[ah] = r8[al];
        _xlatds();
        xchg8(ah, al);
        r16[bx] = 0x73a3;
        _xlatds();
        if (memory16gets(ds*16+r16[si] + 2) > signed16(0x0006)) {
            pc = 0x3bd1;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
        pc = 0x3be8;
        break;
    case 0x3bd1:
        r8[dl] = memory[ds*16+20619];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[dx] <<= r8[cl];
        if (memory16gets(ds*16+r16[si] + 2) < r16s[dx]) {
            pc = 0x3be8;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
        r16[dx] += 0x0040;
        if (memory16gets(ds*16+r16[si] + 2) >= r16s[dx]) {
            pc = 0x3bfe;
            break;
        }
    case 0x3be8:
        if (r8[al] == 0x09) {
            pc = 0x3bfe;
            break;
        }
        if (r8[al] != 0x08) {
            pc = 0x3c03;
            break;
        }
        r16[dx] = memory16get(ds*16+r16[si] + 4);
        r8[dh] &= 0x1f;
        if (r16[dx] != 0x0027) {
            pc = 0x3bfe;
            break;
        }
        pc = 0x3b78;
        break;
    case 0x3bfe:
        memory16set(ds*16+r16[si] + 4, 0xffff);
    case 0x3c03:
        if (r8[al] == 0x06) {
            pc = 0x3c13;
            break;
        }
        r8[ah] &= 0x01;
        r8[al] |= r8[ah];
        r8[al] &= 0x07;
        if (r8[al] == 0) {
            pc = 0x3c13;
            break;
        }
        pc = 0x3b78;
        break;
    case 0x3c13:
        r16[dx] = memory16get(ds*16+r16[si] + 14);
        sar16(dx, r8[cl]);
        r16[dx] = r16[dx] + memory16get(ds*16+r16[si] + 2);
        sar16(dx, r8[cl]);
        r16[dx] = r16[dx] - memory16get(ds*16+25837);
        if (r16[dx] == 0) {
            pc = 0x3c70;
            break;
        }
        memory16set(ds*16+25837, r16[dx]);
        push(r16[bx]);
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        yield* sub_5045();
        r16[bx] = pop();
        if (flags.carry) {
            pc = 0x3c7b;
            break;
        }
        r16[dx] = memory16get(ds*16+25837);
    case 0x3c35:
        r16[di] += 0x0100;
        r8[al] = memory[es*16+r16[di]];
        push(r16[bx]);
        r16[bx] = 0x72a3;
        r8[ah] = r8[al];
        _xlatds();
        xchg8(ah, al);
        r16[bx] = pop();
        _xlatds();
        if (r8[al] == 0x09) {
            pc = 0x3bfe;
            break;
        }
        if (r8[al] != 0x08) {
            pc = 0x3c5d;
            break;
        }
        r16[dx] = memory16get(ds*16+r16[si] + 4);
        r8[dh] &= 0x1f;
        if (r16[dx] != 0x0027) {
            pc = 0x3c5d;
            break;
        }
        pc = 0x3ced;
        break;
    case 0x3c5d:
        if (r8[al] == 0x06) {
            pc = 0x3c6d;
            break;
        }
        r8[ah] &= 0x01;
        r8[al] |= r8[ah];
        r8[al] &= 0x07;
        if (r8[al] == 0) {
            pc = 0x3c6d;
            break;
        }
        pc = 0x3ced;
        break;
    case 0x3c6d:
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x3c35;
            break;
        }
    case 0x3c70:
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        yield* sub_5045();
        if (flags.carry) {
            pc = 0x3c7b;
            break;
        }
        pc = 0x3d5a;
        break;
    case 0x3c7b:
        memory16set(ds*16+r16[si] + 12, 0x0000);
        r16[di] = r16[ax];
        push(r16[si]);
        yield* sub_5133();
        if (!flags.zero) {
            pc = 0x3cd4;
            break;
        }
        push(r16[di]);
        yield* sub_5133();
        if (!flags.zero) {
            pc = 0x3c9e;
            break;
        }
        memory16set(ds*16+r16[si] + 2, r16[dx]);
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 12, 0x0000);
        pc = 0x3d8a;
        break;
    case 0x3c9e:
        memory[ds*16+r16[di] + 8] |= 0x01;
        memory16set(ds*16+r16[di] + 9, r16[si]);
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        r16[ax] = -r16[ax];
        sar16(ax, 1);
        r16[bx] = r16[ax];
        flags.sign = signed16(r16[ax] + 0x0010) < 0;
        r16[ax] += 0x0010;
        if (!flags.sign) {
            pc = 0x3cb8;
            break;
        }
        flags.sign = signed16(r16[bx] + 0x0020) < 0;
        r16[bx] += 0x0020;
        if (flags.sign) {
            pc = 0x3cc3;
            break;
        }
    case 0x3cb8:
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory16set(ds*16+r16[si] + 2, r16[dx]);
        pc = 0x3d8a;
        break;
    case 0x3cc3:
        memory16set(ds*16+r16[di] + 14, r16[bx]);
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        sar16(ax, 1);
        memory16set(ds*16+r16[di] + 6, r16[ax]);
        pc = 0x3d5a;
        break;
    case 0x3cd4:
        push(r16[di]);
        yield* sub_5133();
        if (!flags.zero) {
            pc = 0x3ceb;
            break;
        }
        memory16set(ds*16+r16[si] + 2, r16[dx]);
        if (memory16get(ds*16+r16[si] + 14) >= 0x0010) {
            pc = 0x3d3f;
            break;
        }
        memory16set(ds*16+r16[si] + 14, 0x0000);
        pc = 0x3d8a;
        break;
    case 0x3ceb:
        pc = 0x3c9e;
        break;
    case 0x3ced:
        push(r16[si]);
        yield* sub_5133();
        if (!flags.zero) {
            pc = 0x3d37;
            break;
        }
        memory16set(ds*16+r16[si] + 14, 0x0000);
        memory[ds*16+r16[si] + 2] &= 0xf0;
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + 0x0010);
        r8[al] = memory[ds*16+r16[si] + 4];
        r8[al] -= 0x31;
        if (r8[al] > 0x03) {
            pc = 0x3d12;
            break;
        }
        memory[ds*16+r16[si] + 4] = 0x31;
        memory[ds*16+25859] = 0x00;
    case 0x3d12:
        if (!(memory[ds*16+r16[si] + 5] & 0x20)) {
            pc = 0x3d8a;
            break;
        }
        if (memory16get(ds*16+21138) != 0xffff) {
            pc = 0x3d8a;
            break;
        }
        memory[ds*16+25861] = 0x20;
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+0x5290, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+0x528e, r16[ax]);
        memory16set(ds*16+21138, 0x002e);
        pc = 0x3d8a;
        break;
    case 0x3d37:
        memory[ds*16+r16[si] + 2] &= 0xf0;
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + 0x0010);
    case 0x3d3f:
        memory[ds*16+25873] = 0x04;
        memory16set(ds*16+r16[si] + 12, 0x0000);
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        r16[ax] = -r16[ax];
        r16[ax] += 0x0030;
        if (r16s[ax] < signed16(0)) {
            pc = 0x3d55;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x3d55:
        memory16set(ds*16+r16[si] + 14, r16[ax]);
        pc = 0x3d8a;
        break;
    case 0x3d5a:
        r8[dl] = 0x0f;
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        if (r8[bl] >= 0x65) {
            pc = 0x3d6b;
            break;
        }
        r8[dl] = memory[ds*16+r16[bx] + 28512];
    case 0x3d6b:
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        sar16(ax, r8[cl]);
        if (r16[ax] == 0) {
            pc = 0x3d77;
            break;
        }
        memory[ds*16+25873] = 0x04;
    case 0x3d77:
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        if (r8s[al] >= r8s[dl]) {
            pc = 0x3d87;
            break;
        }
        memory16set(ds*16+r16[si] + 14, memory16get(ds*16+r16[si] + 14) + 0x0010);
        if (memory16gets(ds*16+r16[si] + 14) <= signed16(0)) {
            pc = 0x3d87;
            break;
        }
        memory16set(ds*16+r16[si] + 12, memory16get(ds*16+r16[si] + 12) + 1);
    case 0x3d87:
        yield* sub_3d97();
    case 0x3d8a:
        r16[si] += 0x0012;
        memory16set(ds*16+25835, memory16get(ds*16+25835) - 1);
        if (memory16get(ds*16+25835) == 0) {
            pc = 0x3d96;
            break;
        }
        pc = 0x39e0;
        break;
    case 0x3d96:
        return;
    } while (1);
}
function* sub_3d97() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        if (memory16get(ds*16+r16[si] + 12) >= 0x000a) {
            pc = 0x3da3;
            break;
        }
        pc = 0x3e24;
        break;
    case 0x3da3:
        if (memory16gets(ds*16+21130) >= signed16(0x00c0)) {
            pc = 0x3e24;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x3db5;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3db5:
        if (r16[ax] >= 0x0020) {
            pc = 0x3e24;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x3dc3;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x3dc3:
        if (r16[ax] >= 0x0020) {
            pc = 0x3e24;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27639];
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = memory16get(ds*16+21116);
        if (r16s[ax] <= r16s[dx]) {
            pc = 0x3de1;
            break;
        }
        xchg16(ax, dx);
        r8[bl] = 0x18;
    case 0x3de1:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] += r16[bx];
        if (r16s[ax] < r16s[dx]) {
            pc = 0x3e24;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[dx] = memory16get(ds*16+21118);
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27640];
        r8[bl] -= 1;
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x3e05;
            break;
        }
        xchg16(ax, dx);
        r8[bl] = 0x20;
    case 0x3e05:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] -= r16[bx];
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x3e24;
            break;
        }
        r8[al] = 0x05;
        yield* sub_11e6();
        memory[ds*16+25875] = 0x18;
        if (!(memory[ds*16+r16[si] + 11] & 0x02)) {
            pc = 0x3e24;
            break;
        }
        yield* sub_59cc();
        memory[ds*16+r16[si] + 11] &= 0xfd;
    case 0x3e24:
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_3e28() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        bp = 0xffff;
        memory16set(ds*16+22092, bp);
        memory16set(ds*16+22110, bp);
        memory16set(ds*16+22128, bp);
        memory16set(ds*16+22146, bp);
        r16[si] = 0x7dcb;
        r16[di] = 0x5648;
        r16[ax] = memory16get(ds*16+0x5270);
        r16[dx] = memory16get(ds*16+21106);
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[dx] <<= r8[cl];
        r16[cx] = 0x000a;
    case 0x3e56:
        if (memory16get(ds*16+r16[si] + 4) == bp) {
            pc = 0x3ec7;
            break;
        }
        push(r16[ax]);
        push(r16[dx]);
        r8[al] = memory[ds*16+r16[si] + 7];
        _cbw();
        r8[dl] = memory[ds*16+r16[si] + 6];
        if (r8[dl] != 0x00) {
            pc = 0x3e6e;
            break;
        }
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) - r16[ax]);
        pc = 0x3ed0;
        break;
    case 0x3e6e:
        if (r8[dl] != 0x02) {
            pc = 0x3e78;
            break;
        }
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        pc = 0x3ed0;
        break;
    case 0x3e78:
        if (r8[dl] != 0x01) {
            pc = 0x3e81;
            break;
        }
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
        pc = 0x3ed0;
        break;
    case 0x3e81:
        if (r8[dl] != 0x03) {
            pc = 0x3e8a;
            break;
        }
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        pc = 0x3ed0;
        break;
    case 0x3e8a:
        r16[dx] = pop();
        r16[ax] = pop();
        r16[bx] = memory16get(ds*16+r16[si]);
        r16[bx] += 0x0010;
        flags.carry = r16[bx] < r16[ax];
        r16[bx] -= r16[ax];
        if (flags.carry) {
            pc = 0x3ec7;
            break;
        }
        r16[bx] -= 0x0020;
        if (r16s[bx] > signed16(0x0140)) {
            pc = 0x3ec7;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        flags.carry = r16[bx] < r16[dx];
        r16[bx] -= r16[dx];
        if (flags.carry) {
            pc = 0x3ec7;
            break;
        }
        r16[bx] -= 0x0010;
        if (r16s[bx] > signed16(0x00c0)) {
            pc = 0x3ec7;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r16[bx] += 0x001e;
        memory16set(ds*16+r16[di] + 4, r16[bx]);
        r16[bx] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[di], r16[bx]);
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[di] + 2, r16[bx]);
        memory16set(ds*16+r16[di] + 9, r16[si]);
        r16[di] += 0x0012;
    case 0x3ec7:
        r16[si] += 0x0014;
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x3ecf;
            break;
        }
        pc = 0x3e56;
        break;
    case 0x3ecf:
        return;
    case 0x3ed0:
        memory16set(ds*16+r16[si] + 17, memory16get(ds*16+r16[si] + 17) + 1);
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        if (memory16get(ds*16+r16[si] + 10) != r16[ax]) {
            pc = 0x3e8a;
            break;
        }
        r8[dl] = r8[dl] ^ 0x02;
        memory16set(ds*16+r16[si] + 17, 0x0000);
        memory[ds*16+r16[si] + 6] = r8[dl];
        pc = 0x3e8a;
        break;
        return;
    } while (1);
}
function* sub_3ee8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[di]);
        push(r16[si]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        es = r16[ax];
        r16[di] = 0x527c;
        r16[cx] = 0x020a;
        r16[ax] = r16[ax] ^ r16[ax];
        rep_stosw_data_forward();
        r16[di] = 0x527c;
        r16[cx] = 0x003a;
    case 0x3f02:
        memory16set(ds*16+r16[di] + 4, 0xffff);
        r16[di] += 0x0012;
        if (--r16[cx]) {
            pc = 0x3f02;
            break;
        }
        r16[si] = 0x52a0;
        r16[di] = 0x75a3;
        r16[cx] = 0x0028;
    case 0x3f15:
        r16[ax] = memory16get(ds*16+r16[di]);
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        memory[ds*16+r16[si] + 11] = 0x00;
        r16[si] += 0x0012;
        r16[di] += 0x0006;
        if (--r16[cx]) {
            pc = 0x3f15;
            break;
        }
        memory[ds*16+25873] = 0x04;
        r16[ax] = memory16get(ds*16+0x7695);
        memory16set(ds*16+0x527c, r16[ax]);
        r16[ax] = memory16get(ds*16+0x7697);
        memory16set(ds*16+0x527e, r16[ax]);
        r16[si] = pop();
        r16[di] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_3f46() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory[ds*16+25852] += 1;
        if (memory[ds*16+25852] & 0x03) {
            pc = 0x3f66;
            break;
        }
        r16[ax] = memory16get(ds*16+0x64f6);
        r8[ah] += 1;
        if (r16[ax] != 0x63e4) {
            pc = 0x3f63;
            break;
        }
        r8[ah] -= 0x03;
    case 0x3f63:
        memory16set(ds*16+0x64f6, r16[ax]);
    case 0x3f66:
        if (memory[ds*16+25858] != 0x00) {
            pc = 0x3f73;
            break;
        }
        yield* sub_403c();
        yield* sub_3f74();
    case 0x3f73:
        return;
    } while (1);
}
function* sub_3f74() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory16get(ds*16+21130) != 0x0000) {
            pc = 0x3f85;
            break;
        }
        memory[ds*16+25889] = 0x00;
    case 0x3f85:
        r16[dx] = memory16get(ds*16+21118);
        r8[cl] = 0x04;
        sar16(dx, r8[cl]);
        r16[dx] = r16[dx] - memory16get(ds*16+21106);
        if (memory[ds*16+25889] != 0x00) {
            pc = 0x3fcf;
            break;
        }
        if (memory16get(ds*16+21130) != 0x0000) {
            pc = 0x3fa6;
            break;
        }
        if (memory[ds*16+25869] == 0x00) {
            pc = 0x3fb8;
            break;
        }
    case 0x3fa6:
        r16[ax] = 0x0003;
        if (r16s[dx] >= signed16(0x000a)) {
            pc = 0x3fc8;
            break;
        }
        r16[ax] = 0x0009;
        if (r16s[dx] > signed16(0x0002)) {
            pc = 0x3fcf;
            break;
        }
        pc = 0x3fc8;
        break;
    case 0x3fb8:
        r16[ax] = 0x000a;
        if (r16s[dx] >= signed16(0x000b)) {
            pc = 0x3fc8;
            break;
        }
        r16[ax] = 0x0009;
        if (r16s[dx] > signed16(0x0002)) {
            pc = 0x3fcf;
            break;
        }
    case 0x3fc8:
        memory16set(ds*16+0x6524, r16[ax]);
        memory[ds*16+25889] += 1;
    case 0x3fcf:
        r16[ax] = memory16get(ds*16+0x7693);
        r16[ax] += 0x000c;
        r16[ax] <<= r8[cl];
        if (memory16get(ds*16+21118) > r16[ax]) {
            pc = 0x3fe8;
            break;
        }
        r16[bx] = memory16get(ds*16+21106);
        r16[bx] -= 1;
        if (memory16gets(ds*16+30355) < r16s[bx]) {
            pc = 0x4031;
            break;
        }
    case 0x3fe8:
        r16[ax] = memory16get(ds*16+0x7693);
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] >= 0x0005) {
            pc = 0x4005;
            break;
        }
        r16[ax] = memory16get(ds*16+0x7693);
        r16[ax] += 0x000c;
        r16[ax] <<= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        if (r16[ax] < 0x0070) {
            pc = 0x402a;
            break;
        }
    case 0x4005:
        if (memory[ds*16+25889] == 0x00) {
            pc = 0x403b;
            break;
        }
        if (memory16get(ds*16+25892) == r16[dx]) {
            pc = 0x4036;
            break;
        }
        if (memory16gets(ds*16+25892) > r16s[dx]) {
            pc = 0x4031;
            break;
        }
        r16[ax] = memory16get(ds*16+0x7693);
        r16[dx] = r16[ax];
        r16[dx] += 0x000c;
        r16[dx] <<= r8[cl];
        if (memory16get(ds*16+21118) > r16[dx]) {
            pc = 0x402a;
            break;
        }
        if (memory16get(ds*16+21106) > r16[ax]) {
            pc = 0x4036;
            break;
        }
    case 0x402a:
        yield* sub_294c();
        if (flags.carry) {
            pc = 0x4036;
            break;
        }
        pc = 0x403b;
        break;
    case 0x4031:
        yield* sub_2911();
        if (!flags.carry) {
            pc = 0x403b;
            break;
        }
    case 0x4036:
        memory[ds*16+25889] = 0x00;
    case 0x403b:
        return;
    } while (1);
}
function* sub_403c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[dx] = memory16get(ds*16+21116);
        r8[cl] = 0x04;
        sar16(dx, r8[cl]);
        r16[dx] = r16[dx] - memory16get(ds*16+21104);
        if (memory[ds*16+25888] == 0x00) {
            pc = 0x4057;
            break;
        }
        pc = 0x40d7;
        break;
    case 0x4057:
        if (memory16get(ds*16+25886) < 0x0016) {
            pc = 0x40c6;
            break;
        }
        r8[al] = memory[ds*16+0x5287];
        r8[al] &= 0x0f;
        if (r8[al] != 0x01) {
            pc = 0x40a1;
            break;
        }
        r16[ax] = memory16get(ds*16+0x5282);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x4070;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4070:
        if (r16[ax] == 0x0040) {
            pc = 0x407e;
            break;
        }
        if (memory16gets(ds*16+21120) < signed16(0x0000)) {
            pc = 0x409c;
            break;
        }
        pc = 0x408a;
        break;
    case 0x407e:
        if (memory16gets(ds*16+21122) < 0 /*CHECK*/) {
            pc = 0x4097;
            break;
        }
        if (r16s[dx] < signed16(0x000d)) {
            pc = 0x40d7;
            break;
        }
    case 0x408a:
        r16[ax] = 0x0002;
    case 0x408d:
        memory16set(ds*16+0x6522, r16[ax]);
        memory[ds*16+25888] = 0x01;
        pc = 0x40d7;
        break;
    case 0x4097:
        if (r16s[dx] > signed16(0x0007)) {
            pc = 0x40d7;
            break;
        }
    case 0x409c:
        r16[ax] = 0x0012;
        pc = 0x408d;
        break;
    case 0x40a1:
        r16[ax] = memory16get(ds*16+0x5282);
        r16[ax] = r16[ax] | memory16get(ds*16+21130);
        if (r16[ax] != 0) {
            pc = 0x40c6;
            break;
        }
        if (memory16get(ds*16+25886) != 0x0021) {
            pc = 0x40c6;
            break;
        }
        yield* sub_40fa();
        memory16set(ds*16+0x6522, r16[ax]);
        pc = 0x40bf;
        break;
    case 0x40b9:
        memory16set(ds*16+25890, 0x000a);
    case 0x40bf:
        memory[ds*16+25888] = 0x01;
        pc = 0x40d7;
        break;
    case 0x40c6:
        if (memory[ds*16+25888] != 0x00) {
            pc = 0x40d7;
            break;
        }
        if (r16s[dx] > signed16(0x0012)) {
            pc = 0x40b9;
            break;
        }
        if (r16s[dx] < signed16(0x0002)) {
            pc = 0x40b9;
            break;
        }
    case 0x40d7:
        if (memory[ds*16+25888] == 0x00) {
            pc = 0x40f9;
            break;
        }
        if (memory16get(ds*16+25890) == r16[dx]) {
            pc = 0x40f4;
            break;
        }
        if (memory16gets(ds*16+25890) > r16s[dx]) {
            pc = 0x40ed;
            break;
        }
        yield* sub_29b5();
        if (flags.carry) {
            pc = 0x40f4;
            break;
        }
        pc = 0x40f9;
        break;
    case 0x40ed:
        yield* sub_2994();
        if (flags.carry) {
            pc = 0x40f4;
            break;
        }
        pc = 0x40f9;
        break;
    case 0x40f4:
        memory[ds*16+25888] = 0x00;
    case 0x40f9:
        return;
    } while (1);
}
function* sub_40fa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[si]);
        r16[dx] = memory16get(ds*16+21116);
        r16[si] = 0x5570;
        r16[cx] = 0x0008;
        r16[ax] = 0x000a;
        flags.carry = false;
    case 0x410b:
        if (memory16get(ds*16+r16[si] + 4) == 0xffff) {
            pc = 0x4133;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        r8[bl] = r8[bl] + 0x00 + flags.carry;
        r8[bh] = memory[ds*16+21121];
        rol8(bh, 1);
        r8[bh] &= 0x01;
        r8[bl] = r8[bl] ^ r8[bh];
        if (r8[bl] == 0) {
            pc = 0x4133;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si]);
        r16[bx] -= r16[dx];
        if (r16s[bx] >= 0) {
            pc = 0x412d;
            break;
        }
        r16[bx] = -r16[bx];
    case 0x412d:
        if (r16[bx] < 0x00c8) {
            pc = 0x4146;
            break;
        }
    case 0x4133:
        flags.carry = r16[si] + 0x0012 >= 0x10000;
        r16[si] += 0x0012;
        if (--r16[cx]) {
            pc = 0x410b;
            break;
        }
        r16[ax] = 0x0003;
        if (!(memory16get(ds*16+21121) & 0x0080)) {
            pc = 0x4146;
            break;
        }
        r16[ax] = 0x0011;
    case 0x4146:
        r16[si] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_414b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        if (memory[ds*16+25878] != 0x00) {
            pc = 0x4171;
            break;
        }
        if (memory[ds*16+1147] == 0x00) {
            pc = 0x4171;
            break;
        }
        yield* sub_4dc0();
        memory[ds*16+25878] -= 1;
        pc = 0x447a;
        break;
    case 0x4171:
        if (memory[ds*16+1148] == 0x00) {
            pc = 0x4187;
            break;
        }
        memory[ds*16+25879] = 0x01;
    case 0x417d:
        if (memory[ds*16+1148] == 0x00) {
            pc = 0x417d;
            break;
        }
        pc = 0x447a;
        break;
    case 0x4187:
        if (memory[ds*16+1106] == 0x00) {
            pc = 0x4193;
            break;
        }
        memory[ds*16+25862] = 0x32;
    case 0x4193:
        if (memory[ds*16+1150] == 0x00) {
            pc = 0x41ad;
            break;
        }
    case 0x419a:
        if (memory[ds*16+1150] != 0x00) {
            pc = 0x419a;
            break;
        }
        yield* sub_27df();
        yield* sub_01f8();
        yield* sub_03f2();
        yield* sub_03ae();
    case 0x41ad:
        yield* sub_18af();
        es = memory16get(ds*16+21100);
        r16[si] = 0x527c;
        yield* sub_4b49();
        yield* sub_0805();
        r16[ax] = 0x550b;
        if (memory[ds*16+25875] == 0x00) {
            pc = 0x41ca;
            break;
        }
        pc = 0x428a;
        break;
    case 0x41ca:
        r8[al] = 0x0c;
        r8[al] = r8[al] + memory[ds*16+25857];
        if (memory[ds*16+25876] == 0x00) {
            pc = 0x41da;
            break;
        }
        pc = 0x428a;
        break;
    case 0x41da:
        memory[ds*16+25857] = 0x00;
        r8[al] = 0xaa;
        if (memory[ds*16+1071] == 0x00) {
            pc = 0x41eb;
            break;
        }
        r16[ax] = 0x0101;
    case 0x41eb:
        if (memory[ds*16+1072] == 0x00) {
            pc = 0x41f5;
            break;
        }
        r16[ax] = 0xff01;
    case 0x41f5:
        if (memory[ds*16+25869] == 0x00) {
            pc = 0x4200;
            break;
        }
        r8[al] = 0x06;
        pc = 0x4242;
        break;
    case 0x4200:
        if (memory[ds*16+25870] != 0x00) {
            pc = 0x4215;
            break;
        }
        if (memory[ds*16+25871] == 0x06) {
            pc = 0x4220;
            break;
        }
        if (memory[ds*16+1070] == 0x00) {
            pc = 0x4220;
            break;
        }
    case 0x4215:
        if (r8[ah] == 0x55) {
            pc = 0x421e;
            break;
        }
        r8[al] = 0x03;
        pc = 0x4220;
        break;
    case 0x421e:
        r8[al] = 0x05;
    case 0x4220:
        if (memory[ds*16+25870] != 0x00) {
            pc = 0x4242;
            break;
        }
        if (memory[ds*16+1069] == 0x00) {
            pc = 0x4242;
            break;
        }
        if (memory[ds*16+25871] != 0x00) {
            pc = 0x4242;
            break;
        }
        r8[al] = 0x02;
        if (memory[ds*16+r16[si] + 11] != 0x05) {
            pc = 0x4242;
            break;
        }
        memory[ds*16+25874] = 0x64;
    case 0x4242:
        if (r8[al] != 0xaa) {
            pc = 0x4248;
            break;
        }
        r8[al] = r8[al] ^ r8[al];
    case 0x4248:
        if (memory[ds*16+1067] == 0x00) {
            pc = 0x4280;
            break;
        }
        if (memory[ds*16+25870] != 0x00) {
            pc = 0x4280;
            break;
        }
        if (memory[ds*16+25866] != 0x00) {
            pc = 0x428a;
            break;
        }
        if (r8[al] == 0x03) {
            pc = 0x4265;
            break;
        }
        if (r8[al] != 0x05) {
            pc = 0x426e;
            break;
        }
    case 0x4265:
        memory[ds*16+25867] = 0x00;
        r8[al] = 0x07;
        pc = 0x428a;
        break;
    case 0x426e:
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x428a;
            break;
        }
        if (memory[ds*16+25867] == 0x00) {
            pc = 0x428a;
            break;
        }
        r8[al] = 0x08;
        pc = 0x428a;
        break;
    case 0x4280:
        memory[ds*16+25867] = 0x01;
        memory[ds*16+25868] = 0x00;
    case 0x428a:
        r8[al] = r8[al] + memory[ds*16+25865];
        if (r8[ah] != 0x55) {
            pc = 0x4296;
            break;
        }
        r8[ah] = memory[ds*16+r16[si] + 10];
    case 0x4296:
        r8[dl] = memory[ds*16+1072];
        r8[dl] = r8[dl] | memory[ds*16+1071];
        memory[ds*16+25863] = r8[dl];
        r8[dl] = memory[ds*16+1069];
        r8[dl] = r8[dl] | memory[ds*16+1070];
        memory[ds*16+25864] = r8[dl];
        _cwd();
        r8[dl] |= r8[ah];
        if (memory16get(ds*16+r16[si] + 9) == r16[dx]) {
            pc = 0x42c1;
            break;
        }
        memory16set(ds*16+r16[si] + 9, r16[dx]);
    case 0x42b9:
        memory16set(ds*16+25886, 0x0001);
        pc = 0x42e1;
        break;
    case 0x42c1:
        if (r8[al] == 0x01) {
            pc = 0x42c9;
            break;
        }
        if (r8[al] != 0x00) {
            pc = 0x42d2;
            break;
        }
    case 0x42c9:
        if (memory[ds*16+25874] == 0x00) {
            pc = 0x42d2;
            break;
        }
        r8[al] += 0x09;
    case 0x42d2:
        if (memory[ds*16+r16[si] + 11] != r8[al]) {
            pc = 0x42b9;
            break;
        }
        flags.carry = (memory16get(ds*16+25886) + 0x0001) >= 0x10000;
        memory16set(ds*16+25886, memory16get(ds*16+25886) + 0x0001);
        memory16set(ds*16+25886, memory16get(ds*16+25886) - 0x0000 + flags.carry);
    case 0x42e1:
        _cbw();
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 28411));
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        r8[cl] = 0x04;
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
        if (memory16gets(ds*16+r16[si]) < signed16(0x0008)) {
            pc = 0x42fe;
            break;
        }
        if (memory16get(ds*16+r16[si]) < 0x0ff8) {
            pc = 0x4300;
            break;
        }
    case 0x42fe:
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
    case 0x4300:
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        r8[cl] = 0x04;
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        yield* sub_4484();
        r8[al] = memory[ds*16+0x650a];
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x4378;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+0x5294);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] + memory16get(ds*16+21134);
        if (r16[ax] >= 0x1000) {
            pc = 0x436b;
            break;
        }
        r16[bx] = memory16get(ds*16+21104);
        r16[bx] <<= r8[cl];
        r16[bx] -= 0x0028;
        if (r16s[bx] > r16s[ax]) {
            pc = 0x436b;
            break;
        }
        r16[bx] += 0x0190;
        if (r16s[bx] < r16s[ax]) {
            pc = 0x436b;
            break;
        }
        memory16set(ds*16+0x528e, r16[ax]);
        r16[ax] = memory16get(ds*16+0x529c);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] + memory16get(ds*16+21136);
        r8[bl] = memory[ds*16+20619];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= r8[cl];
        if (r16[ax] >= r16[bx]) {
            pc = 0x436b;
            break;
        }
        r16[bx] = memory16get(ds*16+21106);
        r16[bx] <<= r8[cl];
        r16[bx] -= 0x0014;
        if (r16s[bx] > r16s[ax]) {
            pc = 0x436b;
            break;
        }
        r16[bx] += 0x00e8;
        if (r16s[bx] < r16s[ax]) {
            pc = 0x436b;
            break;
        }
        memory16set(ds*16+0x5290, r16[ax]);
        pc = 0x4376;
        break;
    case 0x436b:
        memory16set(ds*16+21138, 0xffff);
        memory[ds*16+25866] = 0x00;
    case 0x4376:
        pc = 0x43ea;
        break;
    case 0x4378:
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x43ea;
            break;
        }
        r16[bx] = memory16get(ds*16+21120);
        r16[dx] = r16[bx];
        r8[dh] &= 0x1f;
        r8[al] = memory[ds*16+0x5287];
        if (memory[ds*16+25869] != 0x00) {
            pc = 0x43ab;
            break;
        }
        if (r8[al] == 0x15) {
            pc = 0x439a;
            break;
        }
        if (r8[al] != 0x17) {
            pc = 0x43ab;
            break;
        }
    case 0x439a:
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] -= 0x0004;
        memory16set(ds*16+0x5290, r16[ax]);
        yield* sub_5122();
        memory16set(ds*16+0x528e, r16[ax]);
        pc = 0x43ea;
        break;
    case 0x43ab:
        r8[al] &= 0x0f;
        if (r16[dx] == 0x000e) {
            pc = 0x43ba;
            break;
        }
        if (r8[al] == 0x07) {
            pc = 0x43ea;
            break;
        }
        if (r8[al] == 0x08) {
            pc = 0x43ea;
            break;
        }
    case 0x43ba:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] += 1;
        r16[ax] += 1;
        flags.carry = r16[dx] < 0x0017;
        r16[dx] -= 0x0017;
        if (flags.carry) {
            pc = 0x43d4;
            break;
        }
        if (r16[dx] > 0x0001) {
            pc = 0x43d4;
            break;
        }
        r16[ax] -= 0x000a;
        if (!(r8[bh] & 0x80)) {
            pc = 0x43d4;
            break;
        }
        r16[ax] += 0x0012;
    case 0x43d4:
        r8[bh] &= 0x1f;
        memory16set(ds*16+0x528e, r16[ax]);
        r16[ax] = memory16get(ds*16+0x527e);
        r16[bx] <<= 1;
        flags.carry = r8[al] < memory[ds*16+r16[bx] + 27640];
        r8[al] = r8[al] - memory[ds*16+r16[bx] + 27640];
        r8[ah] -= 0x00 + flags.carry;
        r16[ax] += 1;
        memory16set(ds*16+0x5290, r16[ax]);
    case 0x43ea:
        if (memory[ds*16+25877] == 0x00) {
            pc = 0x43fd;
            break;
        }
        memory[ds*16+25877] -= 1;
        if (memory[ds*16+25877] != 0) {
            pc = 0x43fd;
            break;
        }
        memory16set(ds*16+21138, 0xffff);
    case 0x43fd:
        r16[dx] = 0x0001;
        flags.carry = memory[ds*16+25883] < r8[dl];
        memory[ds*16+25883] -= r8[dl];
        memory[ds*16+25883] = memory[ds*16 + 25883] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25878] < r8[dl];
        memory[ds*16+25878] -= r8[dl];
        memory[ds*16+25878] = memory[ds*16 + 25878] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25860] < r8[dl];
        memory[ds*16+25860] -= r8[dl];
        memory[ds*16+25860] = memory[ds*16 + 25860] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25872] < r8[dl];
        memory[ds*16+25872] -= r8[dl];
        memory[ds*16+25872] = memory[ds*16 + 25872] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25873] < r8[dl];
        memory[ds*16+25873] -= r8[dl];
        memory[ds*16+25873] = memory[ds*16 + 25873] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25874] < r8[dl];
        memory[ds*16+25874] -= r8[dl];
        memory[ds*16+25874] = memory[ds*16 + 25874] + r8[dh] + flags.carry;
        flags.carry = memory[ds*16+25876] < r8[dl];
        memory[ds*16+25876] -= r8[dl];
        memory[ds*16+25876] = memory[ds*16 + 25876] + r8[dh] + flags.carry;
        if (memory16get(ds*16+21130) != 0x0000) {
            pc = 0x4447;
            break;
        }
        flags.carry = memory[ds*16+25875] < r8[dl];
        memory[ds*16+25875] -= r8[dl];
        memory[ds*16+25875] = memory[ds*16 + 25875] + r8[dh] + flags.carry;
    case 0x4447:
        r16[ax] = memory16get(ds*16+0x5282);
        r16[ax] = r16[ax] | memory16get(ds*16+21130);
        if (r16[ax] != 0) {
            pc = 0x4454;
            break;
        }
        memory[ds*16+25876] = r8[dh];
    case 0x4454:
        flags.carry = memory[ds*16+25861] < r8[dl];
        memory[ds*16+25861] -= r8[dl];
        memory[ds*16+25861] = memory[ds*16 + 25861] + r8[dh] + flags.carry;
        if (memory[ds*16+25861]==0) {
            pc = 0x447a;
            break;
        }
        if (memory[ds*16+25861] & 0x03) {
            pc = 0x447a;
            break;
        }
        memory16set(ds*16+21138, memory16get(ds*16+21138) + 1);
        if (memory[ds*16+21138] != 0x31) {
            pc = 0x447a;
            break;
        }
        memory16set(ds*16+21138, 0xffff);
        memory[ds*16+25861] = r8[dh];
    case 0x447a:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4484() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[si] = 0x527c;
        r16[ax] = memory16get(ds*16+0x527e);
        r8[cl] = 0x04;
        sar16(ax, r8[cl]);
        r16[ax] -= 1;
        xchg8(al, ah);
        r16[bx] = memory16get(ds*16+21120);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[dh] = memory[ds*16+r16[bx] + 27640];
        r16[bx] = 0x0008;
        if (memory16gets(ds*16+21122) > signed16(0x0000)) {
            pc = 0x44b1;
            break;
        }
        if (memory16gets(ds*16+21122) < signed16(0x0000)) {
            pc = 0x44af;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
    case 0x44af:
        r16[bx] = -r16[bx];
    case 0x44b1:
        push(r16[ax]);
        push(r16[bx]);
        r16[bx] = memory16get(ds*16+21116);
        sar16(bx, r8[cl]);
        r16[bx] += r16[ax];
        if (memory16gets(ds*16+21118) <= signed16(0x0000)) {
            pc = 0x44d9;
            break;
        }
        r8[al] = memory[ds*16+0x508b];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[ax] += 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        if (memory16gets(ds*16+21118) <= r16s[ax]) {
            pc = 0x44d9;
            break;
        }
        yield* sub_4dc0();
    case 0x44d9:
        memory[ds*16+25894] = 0x00;
        r8[al] = memory[ds*16+0x527c];
        r8[al] &= 0x0f;
        flags.carry = r8[al] < 0x04;
        r8[al] -= 0x04;
        r16[bx] -= 0x0000 + flags.carry;
        bp = r16[bx];
        yield* sub_4561();
        if (memory[ds*16+25894] != 0x01) {
            pc = 0x4539;
            break;
        }
        flags.carry = (r8[al] + 0x08) >= 0x100;
        r8[al] += 0x08;
        r16[bx] = r16[bx] + 0x0000 + flags.carry;
        _cmc();
        r16[bx] = r16[bx] + 0x0000 + flags.carry;
        if (r16[bx] == bp) {
            pc = 0x4506;
            break;
        }
        yield* sub_4561();
    case 0x4506:
        if (memory[ds*16+25894] != 0x01) {
            pc = 0x4539;
            break;
        }
        if (memory[ds*16+25872] != 0x00) {
            pc = 0x4536;
            break;
        }
        if (memory[ds*16+25875] != 0x00) {
            pc = 0x4536;
            break;
        }
        yield* sub_4657();
        if (memory[ds*16+25894] != 0x01) {
            pc = 0x4539;
            break;
        }
        yield* sub_4f1f();
        if (memory[ds*16+25894] == 0x01) {
            pc = 0x4536;
            break;
        }
        memory[ds*16+21124] = 0x00;
        pc = 0x4539;
        break;
    case 0x4536:
        yield* sub_4c65();
    case 0x4539:
        r16[bx] = pop();
        r16[ax] = pop();
        if (memory16gets(ds*16+21118) <= signed16(0x0000)) {
            pc = 0x455d;
            break;
        }
        r16[bx] = r16[bx] + memory16get(ds*16+21116);
        sar16(bx, r8[cl]);
        r16[bx] += r16[ax];
        yield* sub_4617();
        pc = 0x4552;
        break;
    case 0x454f:
        yield* sub_4631();
    case 0x4552:
        flags.carry = r16[bx] < 0x0100;
        r16[bx] -= 0x0100;
        if (flags.carry) {
            pc = 0x455d;
            break;
        }
        flags.carry2 = r8[dh] > 0x10;
        r8[dh] -= 0x10;
        if (flags.carry2) {
            pc = 0x454f;
            break;
        }
    case 0x455d:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4561() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(bp);
        memory[ds*16+25884] = 0x00;
        memory[ds*16+25870] = 0x00;
        memory[ds*16+25869] = 0x00;
        if (memory16gets(ds*16+21118) > signed16(0xffff)) {
            pc = 0x4585;
            break;
        }
        yield* sub_4c65();
        memory[ds*16+25894] = 0xff;
        pc = 0x4613;
        break;
    case 0x4585:
        r8[al] = memory[ds*16+0x5287];
        r8[al] &= 0x0f;
        if (r8[al] == 0x02) {
            pc = 0x45a5;
            break;
        }
        push(r16[bx]);
        _lea(di, ds, r16[bx] + 256);
        r8[al] = memory[es*16+r16[di]];
        r16[bx] = 0x73a3;
        _xlatds();
        r8[ah] = r8[ah] ^ r8[ah];
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 29309));
        r16[bx] = pop();
    case 0x45a5:
        flags.carry = r16[bx] < 0x0100;
        r16[bx] -= 0x0100;
        if (flags.carry) {
            pc = 0x4613;
            break;
        }
        if (memory16gets(ds*16+21130) > signed16(0x0000)) {
            pc = 0x4613;
            break;
        }
        r16[di] = r16[bx];
        r8[ah] = memory[es*16+r16[bx]];
        r8[al] = memory[es*16+r16[bx] + 256];
        r16[bx] = 0x72a3;
        _xlatds();
        xchg8(al, ah);
        r16[bx] = 0x74a3;
        _xlatds();
        r8[al] &= 0x7f;
        r8[bl] = r8[al];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= 1;
        push(r16[ax]);
        yield* indirectCall(memory16get(ds*16+r16[bx] + 29337));
        r16[ax] = pop();
        r8[ah] &= 0x01;
        if (r8[ah] == 0) {
            pc = 0x4613;
            break;
        }
        if (memory16gets(ds*16+21118) <= signed16(0x0000)) {
            pc = 0x4613;
            break;
        }
        r16[dx] = 0xffff;
        r16[bx] = 0x72a3;
        if (memory16gets(ds*16+21122) > signed16(0x0000)) {
            pc = 0x45ef;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x45ef:
        push(r16[di]);
        r16[di] += r16[dx];
        r8[al] = memory[es*16+r16[di] + 256];
        _xlatds();
        r8[al] |= r8[al];
        if (r8[al] == 0) {
            pc = 0x460c;
            break;
        }
        r16[dx] = -r16[dx];
        r16[di] += r16[dx];
        r16[di] += r16[dx];
        r8[al] = memory[es*16+r16[di] + 256];
        _xlatds();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x4612;
            break;
        }
    case 0x460c:
        r16[dx] <<= 1;
        memory16set(ds*16+21116, memory16get(ds*16+21116) + r16[dx]);
    case 0x4612:
        r16[di] = pop();
    case 0x4613:
        bp = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4617() {
    push(r16[bx]);
    push(r16[dx]);
    push(r16[di]);
    r16[di] = r16[bx];
    r8[al] = memory[es*16+r16[bx]];
    r16[bx] = 0x72a3;
    _xlatds();
    r8[ah] = r8[ah] ^ r8[ah];
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    yield* indirectCall(memory16get(ds*16+r16[bx] + 29295));
    r16[di] = pop();
    r16[dx] = pop();
    r16[bx] = pop();
}
function* sub_4631() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[dx]);
        push(r16[di]);
        r16[di] = r16[bx];
        r8[al] = memory[es*16+r16[bx]];
        r16[bx] = 0x72a3;
        _xlatds();
        if (r8[al] == 0x04) {
            pc = 0x4645;
            break;
        }
        if (r8[al] != 0x02) {
            pc = 0x464f;
            break;
        }
    case 0x4645:
        r8[ah] = r8[ah] ^ r8[ah];
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 29295));
    case 0x464f:
        r16[di] = pop();
        r16[dx] = pop();
        r16[bx] = pop();
        return;
    case 0x4653:
        return;
    case 0x4654:
        _STOP_("goto loc_4735");
        return;
    } while (1);
}
function* sub_4657() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+21130) < signed16(0x0000))
            return;
        if (memory[ds*16+25872] != 0x00)
            return;
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[si] = 0x5648;
        r16[cx] = 0x0004;
    case 0x4674:
        if (memory16get(ds*16+r16[si] + 4) == 0xffff) {
            pc = 0x4735;
            break;
        }
        if (!(memory[ds*16+r16[si] + 5] & 0x20)) {
            pc = 0x4735;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x468a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x468a:
        if (r16[ax] >= 0x0040)
            _STOP_("goto loc_4654");
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        if (r16s[ax] >= 0) {
            pc = 0x469a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x469a:
        if (r16[ax] >= 0x0010)
            _STOP_("goto loc_4654");
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = memory16get(ds*16+21116);
        flags.carry = r8[dl] < memory[ds*16+26927];
        r8[dl] = r8[dl] - memory[ds*16+26927];
        r8[dh] -= 0x00 + flags.carry;
        r8[bl] = memory[ds*16+27639];
        if (r16s[dx] < r16s[ax]) {
            pc = 0x46c1;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27639];
        xchg16(ax, dx);
    case 0x46c1:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[dx] += r16[bx];
        if (r16s[dx] <= r16s[ax]) {
            pc = 0x4735;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[dx] = memory16get(ds*16+21118);
        flags.carry = r8[dl] < 0x06;
        r8[dl] -= 0x06;
        r8[dh] -= 0x00 + flags.carry;
        r8[bl] = 0x08;
        if (r16s[dx] < r16s[ax]) {
            pc = 0x46e9;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27640];
        xchg16(ax, dx);
    case 0x46e9:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[dx] += r16[bx];
        if (r16s[dx] <= r16s[ax]) {
            pc = 0x4735;
            break;
        }
        if (memory16get(ds*16+25886) != 0x000e) {
            pc = 0x46fe;
            break;
        }
        memory16set(ds*16+25886, 0x0010);
    case 0x46fe:
        memory[ds*16+25894] = 0x00;
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+0x527e, r16[ax]);
        yield* sub_4cf0();
        r16[bx] = memory16get(ds*16+r16[si] + 9);
        r8[al] = memory[ds*16+r16[bx] + 7];
        _cbw();
        r8[dl] = memory[ds*16+r16[bx] + 6];
        if (r8[dl] == 0x01) {
            pc = 0x472f;
            break;
        }
        if (r8[dl] == 0x02) {
            pc = 0x4729;
            break;
        }
        r16[ax] = -r16[ax];
        if (r8[dl] == 0x03) {
            pc = 0x472f;
            break;
        }
        pc = 0x473e;
        break;
    case 0x4729:
        memory16set(ds*16+21118, memory16get(ds*16+21118) + r16[ax]);
        pc = 0x473e;
        break;
    case 0x472f:
        memory16set(ds*16+21116, memory16get(ds*16+21116) + r16[ax]);
        pc = 0x473e;
        break;
    case 0x4735:
        r16[si] += 0x0012;
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x473e;
            break;
        }
        pc = 0x4674;
        break;
    case 0x473e:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4748() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+25885] < 0x03) {
            pc = 0x4755;
            break;
        }
        memory[ds*16+25871] = 0x06;
        return;
    case 0x4755:
        memory[ds*16+25885] += 1;
        bp = 0x0030;
        yield* sub_4bb6();
        bp = 0x0040;
        yield* sub_4b7d();
        yield* sub_4c12();
        yield* sub_4c2a();
        return;
    } while (1);
}
function* sub_476c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        memory[ds*16+0x5287] = r8[al];
        yield* sub_4be8();
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x477b;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x477b:
        if (r16[ax] < 0x0010) {
            pc = 0x479d;
            break;
        }
        r8[al] = memory[ds*16+0x5281];
        r8[ah] = memory[ds*16+21123];
        rol8(al, 1);
        rol8(ah, 1);
        r16[ax] &= 0x0101;
        if (r8[al] != r8[ah]) {
            pc = 0x479d;
            break;
        }
        r8[bl] = memory[ds*16+25865];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] += 0x0004;
        r16[bx] <<= 1;
    case 0x479d:
        r16[bx] = memory16get(ds*16+r16[bx] + 28351);
        memory16set(ds*16+21128, r16[bx]);
        r16[ax] = memory16get(ds*16+r16[bx]);
        r8[dh] = memory[ds*16+21125];
        r8[dh] &= 0x80;
        r8[ah] |= r8[dh];
        memory16set(ds*16+0x5280, r16[ax]);
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_47b7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_4c12();
        yield* sub_4c2a();
        yield* sub_4be8();
        if (memory16get(ds*16+25886) != 0x000f) {
            pc = 0x47d2;
            break;
        }
        memory[ds*16+25872] = 0x06;
        memory16set(ds*16+21130, 0x0000);
    case 0x47d2:
        return;
    } while (1);
}
function* sub_47d3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_4c12();
        yield* sub_4c2a();
        bp = 0x0020;
        yield* sub_4b7d();
        r16[ax] = memory16get(ds*16+0x5282);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x47e8;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x47e8:
        if (r16[ax] >= 0x0020) {
            pc = 0x47f9;
            break;
        }
        r8[al] = 0x06;
        r8[ah] = memory[ds*16+21125];
        r8[ah] &= 0x80;
        memory16set(ds*16+0x5280, r16[ax]);
    case 0x47f9:
        return;
    } while (1);
}
function* sub_47fa() {
    bp = 0x0040;
    yield* sub_4b7d();
    yield* sub_4c12();
    yield* sub_4c2a();
}
function* sub_4807() {
    bp = 0x0030;
    yield* sub_4b7d();
    yield* sub_4c12();
    yield* sub_4c2a();
}
function* sub_4814() {
    memory16set(ds*16+21122, 0x0000);
    yield* sub_4c12();
    yield* sub_4c2a();
}
function* sub_4821() {
    yield* sub_4ae9();
{yield* sub_4814(); return; };
}
function* sub_4826() {
    bp = 0x00c0;
    yield* sub_4bd0();
    yield* sub_4c12();
    yield* sub_4c2a();
}
function* sub_4833() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+25863] == 0x00) {
            pc = 0x4842;
            break;
        }
        bp = 0x0040;
        yield* sub_4b7d();
        pc = 0x4845;
        break;
    case 0x4842:
        yield* sub_4be8();
    case 0x4845:
        if (memory16get(ds*16+25886) > 0x0001) {
            pc = 0x485c;
            break;
        }
        r16[ax] = 0x000c;
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x4859;
            break;
        }
        r16[ax] = 0x0017;
    case 0x4859:
        memory16set(ds*16+0x5280, r16[ax]);
    case 0x485c:
        r16[ax] = r16[ax] ^ r16[ax];
        if (memory[ds*16+25864] == r8[al]) {
            pc = 0x48c8;
            break;
        }
        r8[al] = 0x06;
        r8[al] = r8[al] + memory[ds*16+25865];
        _cbw();
        r16[bx] = r16[ax];
        r16[bx] <<= 1;
        yield* sub_4c12();
        yield* sub_4c2a();
        memory[ds*16+21116] &= 0xf0;
        memory[ds*16+21116] += 0x08;
        r16[bx] = 0x73a3;
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+0x527e);
        r8[al] &= 0xf0;
        r16[ax] <<= r8[cl];
        r16[di] = memory16get(ds*16+21116);
        sar16(di, r8[cl]);
        r16[di] += r16[ax];
        es = memory16get(ds*16+21100);
        r8[al] = memory[es*16+r16[di]];
        _xlatds();
        if (r8[al] == 0x06) {
            pc = 0x48bc;
            break;
        }
        r16[dx] = 0xfff0;
        r8[al] = memory[es*16+r16[di] + -1];
        _xlatds();
        if (r8[al] == 0x06) {
            pc = 0x48b8;
            break;
        }
        r16[dx] = -r16[dx];
        r8[al] = memory[es*16+r16[di] + 1];
        _xlatds();
        if (r8[al] == 0x06) {
            pc = 0x48b8;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x48b8:
        memory16set(ds*16+21116, memory16get(ds*16+21116) + r16[dx]);
    case 0x48bc:
        r16[ax] = 0x0040;
        if (memory[ds*16+1069] == 0x00) {
            pc = 0x48c8;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x48c8:
        memory16set(ds*16+0x528a, r16[ax]);
        return;
    } while (1);
}
function* sub_48cc() {
    yield* sub_4c12();
    yield* sub_4c2a();
    yield* sub_4be8();
}
function* sub_48d6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_4c12();
        yield* sub_4c2a();
        yield* sub_4be8();
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x495a;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
        r16[dx] = 0xff60;
        if (memory[ds*16+1069] != 0x00) {
            pc = 0x490a;
            break;
        }
        r16[dx] = 0xff20;
        xchg16(ax, dx);
        if (memory[ds*16+21121] & 0x80) {
            pc = 0x48ff;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x48ff:
        r16[bx] = memory16get(ds*16+21118);
        r16[bx] -= 0x0010;
        memory16set(ds*16+21136, r16[bx]);
    case 0x490a:
        r16[dx] |= r16[dx];
        if (r16[dx] != 0) {
            pc = 0x4921;
            break;
        }
        r16[bx] = memory16get(ds*16+21138);
        r8[bh] &= 0x1f;
        if (r16[bx] >= 0x0065) {
            pc = 0x4938;
            break;
        }
        if (!(memory[ds*16+r16[bx] + 28441] & 0x04)) {
            pc = 0x4938;
            break;
        }
    case 0x4921:
        yield* sub_4ae9();
        r16[bx] = memory16get(ds*16+25833);
        memory16set(ds*16+r16[bx] + 14, r16[dx]);
        r16[dx] = r16[ax];
        sar16(dx, 1);
        sar16(dx, 1);
        r16[ax] -= r16[dx];
        memory16set(ds*16+r16[bx] + 6, r16[ax]);
        pc = 0x4949;
        break;
    case 0x4938:
        memory[ds*16+25866] = 0x01;
        memory16set(ds*16+0x5294, r16[ax]);
        memory16set(ds*16+21148, r16[dx]);
        r8[al] = 0x03;
        yield* sub_11e6();
    case 0x4949:
        r8[al] = 0x0a;
        r8[ah] = memory[ds*16+21125];
        r8[ah] &= 0x80;
        memory16set(ds*16+0x5280, r16[ax]);
        memory[ds*16+25865] = 0x00;
    case 0x495a:
        return;
    } while (1);
}
function* sub_495b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_4c12();
        yield* sub_4c2a();
        yield* sub_4be8();
        if (memory[ds*16+25868] != 0x00) {
            pc = 0x49af;
            break;
        }
        if (memory16get(ds*16+25886) != 0x0001) {
            pc = 0x49b2;
            break;
        }
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x49b2;
            break;
        }
        yield* sub_4ae9();
        r16[bx] = memory16get(ds*16+25833);
        r16[ax] = memory16get(ds*16+r16[bx] + 2);
        r8[cl] = 0x04;
        sar16(ax, r8[cl]);
        xchg8(al, ah);
        r16[di] = r16[ax];
        r16[ax] = memory16get(ds*16+r16[bx]);
        sar16(ax, r8[cl]);
        r16[di] += r16[ax];
        r16[ax] = memory16get(es*16+r16[di]);
        r16[bx] = 0x73a3;
        _xlatds();
        r8[al] &= 0x07;
        if (r8[al] == 0) {
            pc = 0x49af;
            break;
        }
        r16[dx] = 0xffd0;
        r8[al] = r8[ah];
        _xlatds();
        r8[al] &= 0x07;
        if (r8[al] == 0) {
            pc = 0x49a8;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x49a8:
        r16[bx] = memory16get(ds*16+25833);
        memory16set(ds*16+r16[bx] + 6, r16[dx]);
    case 0x49af:
        pc = 0x4ae3;
        break;
    case 0x49b2:
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x49bc;
            break;
        }
        pc = 0x4ac1;
        break;
    case 0x49bc:
        r16[di] = 0x52a0;
        r16[cx] = 0x0030;
        r16[bx] = memory16get(ds*16+21118);
        r16[dx] = memory16get(ds*16+21116);
    case 0x49ca:
        if (memory16get(ds*16+r16[di] + 4) != 0xffff) {
            pc = 0x49d3;
            break;
        }
        pc = 0x4ada;
        break;
    case 0x49d3:
        r16[ax] = r16[bx];
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x49dc;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x49dc:
        if (r16[ax] < 0x0014) {
            pc = 0x49e4;
            break;
        }
        pc = 0x4ada;
        break;
    case 0x49e4:
        r16[ax] = r16[dx];
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di]);
        if (memory[ds*16+21121] & 0x80) {
            pc = 0x49f1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x49f1:
        if (r16[ax] < 0x0014) {
            pc = 0x49f9;
            break;
        }
        pc = 0x4ada;
        break;
    case 0x49f9:
        if (r16[cx] > 0x0008) {
            pc = 0x4a11;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r8[al] = memory[ds*16+r16[bx] + 28538];
        r8[al] &= 0x0f;
        if (r8[al] != 0x0f) {
            pc = 0x4a11;
            break;
        }
        pc = 0x4ad2;
        break;
    case 0x4a11:
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27639];
        r16[ax] = memory16get(ds*16+0x527c);
        if (r16s[ax] <= r16s[dx]) {
            pc = 0x4a27;
            break;
        }
        xchg16(ax, dx);
        r8[bl] = 0x20;
    case 0x4a27:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] += r16[bx];
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x4a32;
            break;
        }
        pc = 0x4ad2;
        break;
    case 0x4a32:
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        r16[dx] = memory16get(ds*16+21118);
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27640];
        r8[bl] -= 1;
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x4a4e;
            break;
        }
        xchg16(ax, dx);
        r8[bl] = 0x0a;
    case 0x4a4e:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] -= r16[bx];
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x4ad2;
            break;
        }
        if (memory[ds*16+r16[di] + 4] < 0x65) {
            pc = 0x4a90;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di]);
        if (!(memory[ds*16+r16[di] + 5] & 0x80)) {
            pc = 0x4a69;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4a69:
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (flags.sign) {
            pc = 0x4ad2;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 9);
        memory16set(ds*16+r16[bx] + 4, 0xffff);
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r8[bl] = memory[ds*16+r16[bx] + 28538];
        r8[bl] &= 0x0f;
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] <<= 1;
        r16[bx] = memory16get(ds*16+r16[bx] + 28613);
        r16[bx] += 0x0065;
        memory16set(ds*16+r16[di] + 4, r16[bx]);
    case 0x4a90:
        r8[al] = 0x09;
        yield* sub_11e6();
        r16[ax] = r16[ax] ^ r16[ax];
        memory[ds*16+0x6505] = r8[al];
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        memory16set(ds*16+r16[di] + 6, r16[ax]);
        memory[ds*16+25873] = 0x04;
        r16[ax] = 0xffff;
        var t = memory16get(ds*16+r16[di] + 4); memory16set(ds*16+r16[di] + 4, r16[ax]); r16[ax] = t; //_xchg(memory16get(ds*16+r16[di] + 4), r16[ax]);
        memory16set(ds*16+0x5292, r16[ax]);
        memory[ds*16+25865] = 0x10;
        memory[ds*16+25877] = 0x00;
        if (r8[al] != 0x31) {
            pc = 0x4ac1;
            break;
        }
        memory[ds*16+25859] = 0x00;
    case 0x4ac1:
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] -= 0x0004;
        memory16set(ds*16+0x5290, r16[ax]);
        yield* sub_5122();
        memory16set(ds*16+0x528e, r16[ax]);
        pc = 0x4ae3;
        break;
    case 0x4ad2:
        r16[bx] = memory16get(ds*16+21118);
        r16[dx] = memory16get(ds*16+21116);
    case 0x4ada:
        r16[di] += 0x0012;
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x4ae3;
            break;
        }
        pc = 0x49ca;
        break;
    case 0x4ae3:
        memory[ds*16+25868] = 0x01;
        return;
    } while (1);
}
function* sub_4ae9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+21138) == 0xffff) {
            pc = 0x4b48;
            break;
        }
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x4b48;
            break;
        }
        push(r16[ax]);
        push(r16[di]);
        r16[di] = 0x528e;
        r16[ax] = 0xffff;
    case 0x4aff:
        r16[di] += 0x0012;
        if (memory16get(ds*16+r16[di] + 4) != r16[ax]) {
            pc = 0x4aff;
            break;
        }
        var t = memory16get(ds*16+21138); memory16set(ds*16+21138, r16[ax]); r16[ax] = t; //_xchg(memory16get(ds*16+21138), r16[ax]);
        memory16set(ds*16+r16[di] + 4, r16[ax]);
        r8[ah] &= 0x1f;
        r8[al] = 0x00;
        if (r16[ax] < 0x0065) {
            pc = 0x4b1a;
            break;
        }
        r8[al] += 1;
    case 0x4b1a:
        memory[ds*16+r16[di] + 11] = r8[al];
        r16[ax] = memory16get(ds*16+0x528e);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+0x5290);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[ax] = r16[ax] ^ r16[ax];
        memory[ds*16+0x6509] = r8[al];
        memory16set(ds*16+r16[di] + 12, r16[ax]);
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        memory16set(ds*16+r16[di] + 6, r16[ax]);
        memory[ds*16+r16[di] + 8] = r8[al];
        r16[ax] += 1;
        memory[ds*16+0x650c] = r8[al];
        memory[ds*16+25873] = 0x04;
        memory16set(ds*16+25833, r16[di]);
        r16[di] = pop();
        r16[ax] = pop();
    case 0x4b48:
        return;
    } while (1);
}
function* sub_4b49() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+1113] == 0x00) {
            pc = 0x4b7c;
            break;
        }
    case 0x4b50:
        yield* _sync();
        if (memory[ds*16+1113] != 0x00) {
            pc = 0x4b50;
            break;
        }
        yield* sub_2c87();
        push(memory16get(ds*16+21120));
        memory16set(ds*16+21120, 0x001d);
        yield* sub_1c61();
        yield* sub_3271();
        memory16set(ds*16+21120, pop());
    case 0x4b6e:
        yield* _sync();
        if (memory[ds*16+1113] == 0x00) {
            pc = 0x4b6e;
            break;
        }
    case 0x4b75:
        yield* _sync();
        if (memory[ds*16+1113] != 0x00) {
            pc = 0x4b75;
            break;
        }
    case 0x4b7c:
        return;
    } while (1);
}
function* sub_4b7d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(bp);
        r16[ax] = r16[ax] ^ r16[ax];
        if (memory[ds*16+25863] == 0x00) {
            pc = 0x4b95;
            break;
        }
        r16[ax] = memory16get(ds*16+0x5285);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
    case 0x4b95:
        r8[cl] = memory[ds*16+21124];
        sar16(ax, r8[cl]);
        r16[dx] = memory16get(ds*16+21122);
        r16[dx] += r16[ax];
        if (r16s[dx] >= signed16(bp)) {
            pc = 0x4bad;
            break;
        }
        bp = -bp;
        if (r16s[dx] <= signed16(bp)) {
            pc = 0x4bad;
            break;
        }
        bp = r16[dx];
    case 0x4bad:
        memory16set(ds*16+21122, bp);
        bp = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4bb6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = memory16get(ds*16+21130);
        r16[dx] += 0xffe0;
        bp = -bp;
        if (r16s[dx] >= signed16(bp)) {
            pc = 0x4bc8;
            break;
        }
        bp = r16[dx];
    case 0x4bc8:
        memory16set(ds*16+21130, bp);
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4bd0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = memory16get(ds*16+21130);
        r16[dx] += 0x0010;
        if (r16s[dx] >= signed16(bp)) {
            pc = 0x4be0;
            break;
        }
        bp = r16[dx];
    case 0x4be0:
        memory16set(ds*16+21130, bp);
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4be8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[dx]);
        r8[ch] = r8[ch] ^ r8[ch];
        r16[ax] = memory16get(ds*16+0x5282);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x4bf7;
            break;
        }
        r16[ax] = -r16[ax];
        r8[ch] += 1;
    case 0x4bf7:
        r8[cl] = memory[ds*16+21124];
        r16[dx] = 0x000c;
        r16[dx] >>= r8[cl];
        flags.carry = r16[ax] < r16[dx];
        r16[ax] -= r16[dx];
        if (!flags.carry) {
            pc = 0x4c06;
            break;
        }
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x4c06:
        r8[ch] |= r8[ch];
        if (r8[ch] == 0) {
            pc = 0x4c0c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4c0c:
        memory16set(ds*16+0x5282, r16[ax]);
        r16[dx] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_4c12() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+21127] == r8[al]) {
            pc = 0x4c25;
            break;
        }
        memory[ds*16+0x5287] = r8[al];
        r16[bx] = memory16get(ds*16+r16[bx] + 28351);
        memory16set(ds*16+21128, r16[bx]);
        pc = 0x4c29;
        break;
    case 0x4c25:
        r16[bx] = memory16get(ds*16+21128);
    case 0x4c29:
        return;
    } while (1);
}
function* sub_4c2a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x4c37;
            break;
        }
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds*16+r16[bx]);
    case 0x4c37:
        r8[dh] = memory[ds*16+21125];
        r8[dh] &= 0x80;
        r8[ah] |= r8[dh];
        memory16set(ds*16+0x5280, r16[ax]);
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+21128, r16[bx]);
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4c4d() {
    bp = 0x00c0;
    yield* sub_4bd0();
    r8[al] = 0x0e;
    r8[ah] = memory[ds*16+21125];
    r8[ah] &= 0x80;
    memory16set(ds*16+0x5280, r16[ax]);
    memory[ds*16+25871] = 0x06;
}
function* sub_4c65() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+25871] = 0x06;
        if (memory[ds*16+25876] != 0x00) {
            pc = 0x4ca1;
            break;
        }
        push(r16[ax]);
        push(bp);
        bp = 0x0040;
        yield* sub_4b7d();
        bp = 0x00c0;
        yield* sub_4bd0();
        if (memory[ds*16+25875] == 0x00) {
            pc = 0x4c8a;
            break;
        }
        r8[al] = 0x0f;
        pc = 0x4c95;
        break;
    case 0x4c8a:
        r8[al] = 0x0a;
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x4c95;
            break;
        }
        r8[al] = 0x15;
    case 0x4c95:
        r8[ah] = memory[ds*16+21125];
        r8[ah] &= 0x80;
        memory16set(ds*16+0x5280, r16[ax]);
        bp = pop();
        r16[ax] = pop();
    case 0x4ca1:
        return;
    } while (1);
}
function* sub_4ca2() {
    memory[ds*16+25894] |= 0x01;
}
function* sub_4ca8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(ds*16+0x5282);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        sar16(ax, 1);
        memory16set(ds*16+21116, memory16get(ds*16+21116) - r16[ax]);
        memory16set(ds*16+21122, 0x0000);
        if (memory[ds*16+25876] == 0x00) {
            pc = 0x4cd6;
            break;
        }
        if (memory[ds*16+25871] == 0x06) {
            pc = 0x4cd6;
            break;
        }
        memory[ds*16+25875] = 0x14;
        memory[ds*16+25876] = 0x00;
    case 0x4cd6:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4cd8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+25884] = 0x01;
        memory[ds*16+21124] = 0x00;
        if (memory16gets(ds*16+21130) >= signed16(0x0000)) {
            pc = 0x4ceb;
            break;
        }
    {yield* sub_4ca2(); return; };
    case 0x4ceb:
        memory[ds*16+21118] &= 0xf0;
        yield* sub_4cf0();
        return;
    } while (1);
}
function* sub_4cf0() {
    memory16set(ds*16+21130, 0x0000);
    yield* sub_4cf6();
}
function* sub_4cf6() {
    flags.carry = memory[ds*16+25871] < 0x01;
    memory[ds*16+25871] -= 0x01;
    memory[ds*16+25871] = memory[ds*16 + 25871] + 0x00 + flags.carry;
    memory[ds*16+25885] = 0x00;
    memory[ds*16+25894] = 0x02;
    return;
}
function* sub_4d0c() {
    yield* sub_4ca8();
}
function* sub_4d10() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[si] = 0x7bad;
        r16[cx] = 0x0064;
    case 0x4d1f:
        if (memory16get(ds*16+r16[si] + 2) == r16[di]) {
            pc = 0x4d2b;
            break;
        }
        r16[si] += 0x0004;
        if (--r16[cx]) {
            pc = 0x4d1f;
            break;
        }
        pc = 0x4d8f;
        break;
    case 0x4d2b:
        if (memory[ds*16+r16[si]] < 0xfd) {
            pc = 0x4d39;
            break;
        }
        r16[ax] = 0x0006;
        yield* sub_10ff();
        yield* sub_59a1();
    case 0x4d39:
        r8[al] = memory[ds*16+r16[si] + 1];
        memory[es*16+r16[di]] = r8[al];
        r8[bl] = 0x50;
        r8[bh] = 0x02;
        if (memory[cs*16+0x1] < 0x03) {
            pc = 0x4d52;
            break;
        }
        yield* sub_32f4();
        r8[bl] = 0x28;
        r8[bh] = 0x01;
    case 0x4d52:
        tiles[r16[di]] = {
          x: (r16[di]&0xff)*16,
          y: (r16[di]>>8)*16,
          w:2,
          h:16, 
          o:0x5dc0 + 0*32,
          s:0xa000,
          t:0
        };

        r16[ax] = r16[di];
        r8[al] = r8[ah];
        r8[ah] = r8[ah] ^ r8[ah];
        r8[dl] = 0x0c;
        _div8(r8[dl]);
        r8[al] = r8[bl];
        _mul8(r8[ah]);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        push(r16[ax]);
        r16[ax] = r16[di];
        r8[ah] = r8[ah] ^ r8[ah];
        r8[dl] = 0x14;
        _div8(r8[dl]);
        r8[al] = r8[ah];
        r8[ah] = r8[ah] ^ r8[ah];
        r8[cl] = r8[bh];
        r16[ax] <<= r8[cl];
        r16[di] = pop();
        r16[di] += r16[ax];
        r8[al] = memory[ds*16+r16[si] + 1];
        yield* sub_2ddc();
        memory[ds*16+25873] = 0x04;
        memory[ds*16+25845] = 0x01;
        flags.carry = false;
        pc = 0x4d90;
        break;
    case 0x4d8f:
        flags.carry = true;
    case 0x4d90:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_4d9a() {
    r16[ax] = 0x0007;
    yield* sub_10ff();
    r8[al] = memory[ds*16+0x5250];
    memory[ds*16+21072] = 0x0e;
    push(r16[ax]);
    yield* sub_4db1();
    r16[ax] = pop();
    memory[ds*16+0x5250] = r8[al];
}
function* sub_4db1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0007;
        yield* sub_10ff();
        yield* sub_4d10();
        if (flags.carry) {
            pc = 0x4dbf;
            break;
        }
        yield* sub_0333();
    case 0x4dbf:
        return;
    } while (1);
}
function* sub_4dc0() {
    yield* sub_59e7();
    memory[ds*16+25878] = 0x02;
}
function* sub_4dc9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0005;
        yield* sub_10ff();
        yield* sub_4d10();
        if (flags.carry) {
            pc = 0x4df8;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        memory16set(ds*16+0x64e4, r16[ax]);
        r16[dx] = memory16get(ds*16+21118);
        memory16set(ds*16+25830, r16[dx]);
        r16[bx] = memory16get(ds*16+21138);
        r8[bh] &= 0x1f;
        r16[bx] -= 0x0038;
        if (r16[bx] > 0x0001) {
            pc = 0x4df8;
            break;
        }
        memory16set(ds*16+0x64f8, r16[ax]);
        memory16set(ds*16+25850, r16[dx]);
    case 0x4df8:
        return;
    } while (1);
}
function* sub_4df9() {
    yield* sub_4ca2();
}
function* sub_4dfd() {
    yield* sub_4cd8();
}
function* sub_4e01() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+21124] = 0x00;
        if (memory[ds*16+25872] != 0x00) {
            pc = 0x4e10;
            break;
        }
    {yield* sub_4cd8(); return; };
    case 0x4e10:
    {yield* sub_4ca2(); return; };
        return;
    } while (1);
}
function* sub_4e13() {
    yield* sub_4cd8();
    memory[ds*16+21124] = 0x01;
}
function* sub_4e1c() {
    yield* sub_4cd8();
    memory[ds*16+21124] = 0x02;
}
function* sub_4e25() {
    yield* sub_4cd8();
    memory[ds*16+21124] = 0x03;
}
function* sub_4e2e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+25875] != 0x00)
        { yield* sub_4df9(); return; }
        r8[al] = memory[ds*16+0x5287];
        r8[al] &= 0x0f;
        if (r8[al] == 0x01)
        { yield* sub_4dfd(); return; }
        flags.zero = r8[al] == 0x03;
    case 0x4e40:
        if (flags.zero)
        { yield* sub_4dfd(); return; }
        if (r8[al] == 0x07)
        { yield* sub_4dfd(); return; }
        if (r8[al] == 0x08)
            {
            flags.zero = true;
            pc = 0x4e40;
            break;
        }
        if (r8[al] != 0x05) {
            pc = 0x4e5c;
            break;
        }
        yield* sub_4df9();
        memory16set(ds*16+21120, 0x000e);
        memory16set(ds*16+21118, memory16get(ds*16+21118) + 0x0008);
    case 0x4e5c:
        push(ds);
        ds = memory16get(ds*16+21100);
        r8[bl] = memory[ds*16+((r16[di] + 65280)&0xffff)];
        ds = pop();
        r8[bh] = r8[bh] ^ r8[bh];
        r8[ah] = memory[ds*16+r16[bx] + 29603];
        if (r8[ah] == 0x06) {
            pc = 0x4e7e;
            break;
        }
        if (r8[al] == 0x00)
            {
            flags.zero = true;
            pc = 0x4e40;
            break;
        }
        r8[ah] = memory[ds*16+1069];
        if (r16[ax] == 0xff06) {
            pc = 0x4e40;
            break;
        }
    case 0x4e7e:
        yield* sub_4cf6();
        memory[ds*16+25869] = 0x01;
        return;
    } while (1);
}
function* sub_4e88() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds*16+21130) == 0x0000) {
            pc = 0x4ea5;
            break;
        }
        memory16set(ds*16+21130, 0x0000);
        memory16set(ds*16+21118, memory16get(ds*16+21118) & 0xfff0);
        memory16set(ds*16+21118, memory16get(ds*16+21118) + 0x0010);
        memory[ds*16+25885] = 0xff;
        return;
    case 0x4ea5:
        r8[al] = memory[ds*16+0x5280];
        if (r8[al] == 0x0a) {
            pc = 0x4f02;
            break;
        }
        if (r8[al] == 0x15) {
            pc = 0x4f02;
            break;
        }
        if (memory[ds*16+25871] == 0x06) {
            pc = 0x4f02;
            break;
        }
        memory[ds*16+25870] = 0x01;
        if (memory[ds*16+25865] == 0x00) {
            pc = 0x4f02;
            break;
        }
        yield* sub_4ae9();
        push(r16[bx]);
        push(r16[di]);
        r16[di] = memory16get(ds*16+25833);
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[di] + 2);
        sar16(ax, r8[cl]);
        r8[bh] = r8[al];
        r16[ax] = memory16get(ds*16+r16[di]);
        sar16(ax, r8[cl]);
        r8[bl] = r8[al];
        r16[di] = r16[bx];
        es = memory16get(ds*16+21100);
        r16[bx] = 0x72a3;
        r8[al] = memory[es*16+r16[di]];
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x4f00;
            break;
        }
        r16[dx] = 0x0010;
        r8[al] = memory[es*16+r16[di] + -1];
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] != 0) {
            pc = 0x4efa;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x4efa:
        r16[di] = memory16get(ds*16+25833);
        memory16set(ds*16+r16[di], memory16get(ds*16+r16[di]) + r16[dx]);
    case 0x4f00:
        r16[di] = pop();
        r16[bx] = pop();
    case 0x4f02:
        return;
    } while (1);
}
function* sub_4f03() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds*16+21130) >= signed16(0x0000)) {
            pc = 0x4f1b;
            break;
        }
        if (memory16get(ds*16+21122) != 0x0000) {
            pc = 0x4f1b;
            break;
        }
        memory[ds*16+25885] = 0x0a;
        memory[ds*16+25869] = 0x01;
    case 0x4f1b:
        return;
    case 0x4f1c:
        _STOP_("goto loc_503b");
        return;
    } while (1);
}
function* sub_4f1f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        if (memory16gets(ds*16+r16[si] + 14) < signed16(0x0000))
            {
            bp = pop();
            es = pop();
            ds = pop();
            r16[si] = pop();
            r16[di] = pop();
            r16[dx] = pop();
            r16[cx] = pop();
            r16[bx] = pop();
            r16[ax] = pop();
            return;
            _STOP_("goto loc_4f1c");
        }
        r16[si] = 0x527c;
        r16[bx] = r16[bx] ^ r16[bx];
        yield* sub_5045();
        if (!flags.carry) {
            pc = 0x503b;
            break;
        }
        memory16set(ds*16+21118, r16[dx]);
        r16[di] = r16[ax];
        r8[al] = memory[ds*16+r16[di] + 4];
        r8[al] -= 0x36;
        if (r8[al] > 0x01) {
            pc = 0x4f4e;
            break;
        }
        memory[ds*16+r16[di] + 8] |= 0x02;
        memory16set(ds*16+r16[di] + 9, r16[si]);
    case 0x4f4e:
        r8[al] = memory[ds*16+r16[di] + 4];
        r8[al] -= 0x33;
        if (r8[al] > 0x01) {
            pc = 0x4f7b;
            break;
        }
        r16[ax] = 0x0060;
        r8[dl] = memory[ds*16+21121];
        r8[dl] &= 0x80;
        if (r8[dl] == 0) {
            pc = 0x4f65;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4f65:
        memory[ds*16+r16[di] + 5] &= 0x7f;
        memory[ds*16+r16[di] + 5] |= r8[dl];
        memory16set(ds*16+r16[di] + 6, r16[ax]);
        memory[ds*16+25873] = 0x04;
        memory[ds*16+25859] = 0x00;
        pc = 0x4fb9;
        break;
    case 0x4f7b:
        if (memory16gets(ds*16+25886) <= signed16(0x000a)) {
            pc = 0x4fb9;
            break;
        }
        if (memory[ds*16+21127] & 0x0f) {
            pc = 0x4fb9;
            break;
        }
        if (memory16get(ds*16+21130) != 0x0000) {
            pc = 0x4fb9;
            break;
        }
        r8[al] = memory[ds*16+r16[di] + 4];
        if (r8[al] == 0x53) {
            pc = 0x4f9b;
            break;
        }
        if (r8[al] != 0x5e) {
            pc = 0x4fb9;
            break;
        }
    case 0x4f9b:
        r16[ax] = 0x0030;
        if (!(memory[ds*16+21121] & 0x80)) {
            pc = 0x4fa7;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x4fa7:
        memory16set(ds*16+r16[di] + 6, r16[ax]);
        r8[ah] &= 0x80;
        memory[ds*16+r16[di] + 5] &= 0x7f;
        memory[ds*16+r16[di] + 5] |= r8[ah];
        memory[ds*16+25873] = 0x04;
    case 0x4fb9:
        r16[dx] = 0x0010;
        r16[ax] = memory16get(ds*16+r16[di] + 6);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x4fcc;
            break;
        }
        if (!flags.sign) {
            pc = 0x4fc7;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x4fc7:
        r16[ax] += r16[dx];
        memory16set(ds*16+0x5282, r16[ax]);
    case 0x4fcc:
        if (memory[ds*16+25872] != 0x00) {
            pc = 0x5029;
            break;
        }
        if (memory16gets(ds*16+21130) <= signed16(0x0030)) {
            pc = 0x5029;
            break;
        }
        push(r16[di]);
        yield* sub_5133();
        if (flags.zero) {
            pc = 0x5029;
            break;
        }
        r16[ax] = memory16get(ds*16+0x528a);
        r16[dx] = 0xfff0;
        if (memory[ds*16+1069] == 0x00) {
            pc = 0x4ff0;
            break;
        }
        r16[dx] = 0x0030;
    case 0x4ff0:
        if (memory[ds*16+1070] != 0x00) {
            pc = 0x4ffb;
            break;
        }
        flags.sign = signed16(r16[ax] + r16[dx]) < 0;
        r16[ax] += r16[dx];
        if (!flags.sign) {
            pc = 0x4ffd;
            break;
        }
    case 0x4ffb:
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x4ffd:
        r16[ax] = -r16[ax];
        memory16set(ds*16+0x528a, r16[ax]);
        memory16set(ds*16+25886, 0x0000);
        if (memory16get(ds*16+r16[di] + 14) != 0x0000) {
            pc = 0x503b;
            break;
        }
        r8[al] = 0x0c;
        yield* sub_11e6();
        r16[ax] = memory16get(ds*16+0x528a);
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[di] + 14, r16[ax]);
        r8[cl] = 0x04;
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[di] + 2, memory16get(ds*16+r16[di] + 2) - r16[ax]);
        memory[ds*16+25873] = 0x04;
        pc = 0x503b;
        break;
    case 0x5029:
        r16[ax] = memory16get(ds*16+r16[di] + 14);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x5038;
            break;
        }
        memory16set(ds*16+0x528a, r16[ax]);
        yield* sub_4cf6();
        pc = 0x503b;
        break;
    case 0x5038:
        yield* sub_4cf0();
    case 0x503b:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_5045() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[di]);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[al] = memory[ds*16+r16[bx] + 27639];
        r8[ah] = r8[ah] ^ r8[ah];
        memory16set(ds*16+0x64ef, r16[ax]);
        r8[bl] = memory[ds*16+r16[bx] + 26213];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = memory16get(ds*16+r16[si] + 2);
        r16[bx] >>= 1;
        r16[ax] -= r16[bx];
        memory16set(ds*16+0x64f1, r16[ax]);
        memory16set(ds*16+25843, r16[dx]);
        r16[cx] = 0x0028;
        r16[di] = 0x52a0;
    case 0x5071:
        if (r16[si] == r16[di]) {
            pc = 0x508c;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        if (r16[bx] == 0xffff) {
            pc = 0x508c;
            break;
        }
        r8[bh] &= 0x1f;
        if (!(memory[ds*16+r16[bx] + 28441] & 0x01)) {
            pc = 0x508c;
            break;
        }
        yield* sub_5153();
        if (flags.carry) {
            pc = 0x5092;
            break;
        }
    case 0x508c:
        r16[di] += 0x0012;
        if (--r16[cx]) {
            pc = 0x5071;
            break;
        }
        flags.carry = false;
    case 0x5092:
        r16[di] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_5095() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di]);
        if (r16s[ax] >= 0) {
            pc = 0x50a0;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x50a0:
        if (r16[ax] >= 0x0040) {
            pc = 0x511d;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[di] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x50af;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x50af:
        if (r16[ax] >= 0x0046) {
            pc = 0x511d;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[dx] = memory16get(ds*16+r16[di] + 2);
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x50c5;
            break;
        }
        xchg16(ax, dx);
        r16[bx] = memory16get(ds*16+r16[di] + 4);
    case 0x50c5:
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[bl] = memory[ds*16+r16[bx] + 27640];
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] -= 0x0003;
        r16[ax] -= r16[bx];
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x511d;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        bp = r16[bx];
        r8[al] = memory[ds*16+r16[bx] + 26927];
        r8[ah] = r8[ah] ^ r8[ah];
        r16[dx] = memory16get(ds*16+r16[si]);
        r16[dx] -= r16[ax];
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds*16+r16[di]);
        flags.carry = r8[al] < memory[ds*16+r16[bx] + 26927];
        r8[al] = r8[al] - memory[ds*16+r16[bx] + 26927];
        r8[ah] -= 0x00 + flags.carry;
        r8[bl] = memory[ds*16+r16[bx] + 27639];
        r8[bl] >>= 1;
        if (r16s[ax] < r16s[dx]) {
            pc = 0x5110;
            break;
        }
        xchg16(ax, dx);
        r8[bl] = memory[ds*16+bp + 27639];
        r8[bl] >>= 1;
    case 0x5110:
        r8[bh] = r8[bh] ^ r8[bh];
        r16[ax] += r16[bx];
        if (r16s[ax] <= r16s[dx]) {
            pc = 0x511d;
            break;
        }
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        flags.carry = true;
        return;
    case 0x511d:
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        flags.carry = false;
        return;
    } while (1);
}
function* sub_5122() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[dx] = 0x000c;
        if (!(memory[ds*16+r16[si] + 5] & 0x80)) {
            pc = 0x5130;
            break;
        }
        r16[dx] = 0xfff6;
    case 0x5130:
        r16[ax] += r16[dx];
        return;
    } while (1);
}
function* sub_5133() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss*16+bp + 2 -2 + 0x4);
        r16[bx] = memory16get(ds*16+r16[bx] + 4);
        r8[bh] &= 0x1f;
        if (r8[bl] < 0x65) {
            pc = 0x5149;
            break;
        }
        r16[bx] = r16[bx] ^ r16[bx];
        flags.zero = 1;
        pc = 0x514e;
        break;
    case 0x5149:
        flags.zero = !(memory[ds*16+r16[bx] + 0x6f19] & 2);
    case 0x514e:
        bp = pop();
        r16[bx] = pop();
        sp += 2;
        return;
    } while (1);
}
function* sub_5153() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[di]);
        r16[bx] -= r16[ax];
        if (r16s[bx] >= 0) {
            pc = 0x515b;
            break;
        }
        r16[bx] = -r16[bx];
    case 0x515b:
        if (r16[bx] > 0x0040) {
            pc = 0x51c3;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 2);
        r16[bx] -= r16[dx];
        if (r16s[bx] >= 0) {
            pc = 0x5169;
            break;
        }
        r16[bx] = -r16[bx];
    case 0x5169:
        if (r16[bx] > 0x0046) {
            pc = 0x51c3;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        bp = r16[bx];
        r8[bl] = memory[ds*16+r16[bx] + 27639];
        r8[bh] = r8[bh] ^ r8[bh];
        push(r16[bx]);
        r16[bx] >>= 1;
        r16[dx] = memory16get(ds*16+r16[di]);
        r16[dx] -= r16[bx];
        r16[bx] = pop();
        if (r16s[dx] <= r16s[ax]) {
            pc = 0x518f;
            break;
        }
        xchg16(ax, dx);
        r16[bx] = memory16get(ds*16+25839);
    case 0x518f:
        r16[dx] += r16[bx];
        if (r16s[dx] <= r16s[ax]) {
            pc = 0x51bc;
            break;
        }
        r8[bl] = memory[ds*16+bp + 27640];
        r8[bh] = r8[bh] ^ r8[bh];
        bp = r16[bx];
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[dx] = memory16get(ds*16+r16[di] + 2);
        r16[ax] = memory16get(ds*16+0x64f3);
        r16[dx] -= r16[bx];
        if (r16s[dx] < r16s[ax]) {
            pc = 0x51bc;
            break;
        }
        r16[dx] += r16[bx];
        r16[dx] -= bp;
        if (r16s[dx] > r16s[ax]) {
            pc = 0x51bc;
            break;
        }
        r16[ax] = r16[di];
        flags.carry = true;
        return;
    case 0x51bc:
        r16[ax] = memory16get(ds*16+0x64f1);
        r16[dx] = memory16get(ds*16+25843);
    case 0x51c3:
        flags.carry = false;
        return;
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_51c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        yield* sub_5338();
        memory16set(ds*16+1084, 0x0000);
    case 0x51d4:
        memory[ds*16+34772] = 0x00;
    case 0x51d9:
        if (memory16get(ds*16+10) < 0x07c8) {
            pc = 0x51f1;
            break;
        }
        if (memory16get(ds*16+1084) < 0x0ca8) {
            pc = 0x51f1;
            break;
        }
        yield* sub_191c();
        yield* sub_53c8();
        pc = 0x51d4;
        break;
    case 0x51f1:
        yield* sub_0805();
        yield* _sync();
        if (memory[ds*16+1069] == 0x00) {
            pc = 0x520b;
            break;
        }
        if (memory[ds*16+34772] == 0x00) {
            pc = 0x520b;
            break;
        }
        yield* sub_5252();
        memory[ds*16+34772] -= 1;
        pc = 0x51d9;
        break;
    case 0x520b:
        if (memory[ds*16+1070] == 0x00) {
            pc = 0x5222;
            break;
        }
        if (memory[ds*16+34772] != 0x00) {
            pc = 0x5222;
            break;
        }
        yield* sub_5252();
        memory[ds*16+34772] += 1;
        pc = 0x51d9;
        break;
    case 0x5222:
        if (memory[ds*16+1067] != 0x00) {
            pc = 0x522b;
            break;
        }
        pc = 0x51d9;
        break;
    case 0x522b:
        if (memory[ds*16+34772] == 0x00) {
            pc = 0x5244;
            break;
        }
        yield* sub_027b();
        if (_FIXME_) {
            pc = 0x523a;
            break;
        }
        memory[ds*16+0x5250] = r8[al];
    case 0x523a:
        yield* sub_53c8();
        memory[ds*16+34772] = 0x00;
        pc = 0x51d9;
        break;
    case 0x5244:
        yield* _sync();
        yield* sub_0805();
        if (memory[ds*16+1067] != 0x00) {
            pc = 0x5244;
            break;
        }
        yield* sub_5645();
        return;
    } while (1);
}
function* sub_5252() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x5260;
            break;
        }
        if (r8[al] >= 0x03) {
            pc = 0x528b;
            break;
        }
        pc = 0x52bb;
        break;
    case 0x5260:
        push(ds);
        r16[ax] = 0xa000;
        ds = r16[ax];
        r16[si] = 0xc878;
        r16[di] = 0xd8b8;
        r16[dx] = 0x0008;
    case 0x526f:
        r16[cx] = 0x0004;
    case 0x5272:
        r16[ax] = memoryVideoGet16(ds, r16[di]);
        {
            var t = memoryVideoGet16(ds, r16[si]);
            memoryVideoSet16(ds, r16[si], r16[ax]);
            r16[ax] = t;
        }
        memoryVideoSet16(ds, r16[di], r16[ax]);
        r16[si] += 1;
        r16[si] += 1;
        r16[di] += 1;
        r16[di] += 1;
        if (--r16[cx]) {
            pc = 0x5272;
            break;
        }
        r16[si] += 0x0138;
        r16[di] += 0x0138;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x526f;
            break;
        }
        ds = pop();
        return;
    case 0x528b:
        push(ds);
        r16[ax] = 0xa000;
        ds = r16[ax];
        yield* sub_32f4();
        r16[cx] = 0x0008;
        r16[si] = 0x190f;
        r16[di] = 0x1b17;
    case 0x529d:
        r8[al] = memory[ds*16+r16[si]];
        memory[ds*16+0x00] = r8[al];
        r8[al] = memory[ds*16+r16[di]];
        memory[ds*16+r16[si]] = r8[al];
        r8[al] = memory[ds*16+0x00];
        memory[ds*16+r16[di]] = r8[al];
        r8[al] = memory[ds*16+0x01];
        memory[ds*16+0x00] = r8[al];
        r16[si] += 0x0028;
        r16[di] += 0x0028;
        if (--r16[cx]) {
            pc = 0x529d;
            break;
        }
        ds = pop();
        return;
    case 0x52bb:
        push(ds);
        push(es);
        r16[ax] = 0xb800;
        ds = r16[ax];
        es = r16[ax];
        r16[cx] = 0x0005;
        r16[si] = 0x191e;
        r16[di] = 0x1afe;
    case 0x52cd:
        r16[ax] = memory16get(ds*16+r16[si]);
        _xchg(memory16get(es*16+r16[di]), r16[ax]);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 8192);
        _xchg(memory16get(es*16+r16[di] + 0x2000), r16[ax]);
        memory16set(ds*16+r16[si] + 8192, r16[ax]);
        r16[si] += 0x0050;
        r16[di] += 0x0050;
        if (--r16[cx]) {
            pc = 0x52cd;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_52ec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[al] = memory[cs*16+0x1];
        if (r8[al] != 0x05) {
            pc = 0x5315;
            break;
        }
        push(ds);
        r16[dx] = 0x878c;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x526c, r16[ax]);
        r16[ax] = 0x000f;
        yield* sub_10ff();
        yield* sub_5557();
        ds = pop();
        return;
    case 0x5315:
        push(ds);
        r16[dx] = 0x8796;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x526c, r16[ax]);
        r16[ax] = 0x000f;
        yield* sub_10ff();
        memory16set(cs*16+0x6676, 0x6678);
        yield* sub_5477();
        ds = pop();
        return;
    } while (1);
}
function* sub_5338() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x534b;
            break;
        }
        if (r8[al] >= 0x03) {
            pc = 0x5373;
            break;
        }
        pc = 0x5373;
        break;
    case 0x534b:
        push(ds);
        r16[dx] = 0x87a3;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x526c, r16[ax]);
        if (memory[ds*16+34771] == 0x00) {
            pc = 0x5366;
            break;
        }
        yield* sub_03f2();
    case 0x5366:
        memory[ds*16+34771] = 0x01;
        yield* sub_5645();
        yield* sub_5557();
        ds = pop();
        return;
    case 0x5373:
        push(ds);
        r16[dx] = 0x87ac;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x526c, r16[ax]);
        if (memory[ds*16+34771] == 0x00) {
            pc = 0x538e;
            break;
        }
        yield* sub_03f2();
    case 0x538e:
        memory[ds*16+34771] = 0x01;
        yield* sub_1c30();
        memory16set(cs*16+0x6676, 0x6698);
        yield* sub_5477();
        ds = pop();
        return;
    } while (1);
}
function* sub_53a2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        push(ds);
        r16[dx] = 0x87b8;
        push(ds);
        push(es);
        yield* sub_097b();
        es = pop();
        ds = pop();
        memory16set(ds*16+0x04c1, r16[ax]);
        memory16set(ds*16+0x526c, r16[ax]);
        yield* sub_5557();
        r16[cx] = 0x0046;
    case 0x53be:
        yield* sub_3243();
        if (--r16[cx]) {
            pc = 0x53be;
            break;
        }
        yield* sub_5645();
        ds = pop();
        return;
    } while (1);
}
function* sub_53c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x53d9;
            break;
        }
        if (r8[al] < 0x03) {
            pc = 0x53d7;
            break;
        }
    {yield* sub_5477(); return; };
    case 0x53d7:
        pc = 0x5425;
        break;
    case 0x53d9:
        push(ds);
        r16[ax] = 0x0013;
        interrupt(16);
        yield* sub_1c30();
        yield* sub_3243();
        r16[ax] = 0x168f;
        ds = r16[ax];
        ds = memory16get(ds*16+21100);
        r16[si] = r16[si] ^ r16[si];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[cx] = 0x0100;
    case 0x53ff:
        lodsb_data_forward();
        pc = 0x5402;
        break;
    case 0x5402:
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        pc = 0x5406;
        break;
    case 0x5406:
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        pc = 0x540a;
        break;
    case 0x540a:
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x53ff;
            break;
        }
        r16[si] = ds;
        r16[si] += 0x0030;
        ds = r16[si];
        r16[si] = r16[si] ^ r16[si];
        r16[cx] = 0x7d00;
        r16[di] = r16[di] ^ r16[di];
        rep_movsw_data_data_forward();
        yield* sub_3243();
        yield* sub_1c1a();
        ds = pop();
        return;
    case 0x5425:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[ax] = 0x168f;
        ds = r16[ax];
        ds = memory16get(ds*16+21100);
        pc = 0x544d;
        break;
    case 0x5439:
        yield* sub_3160();
        r16[ax] = 0x168f;
        ds = r16[ax];
        ds = memory16get(ds*16+21100);
        r16[si] = r16[si] ^ r16[si];
        r16[ax] = 0x28c8;
        yield* sub_65be();
    case 0x544d:
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[dx] = 0x0064;
    case 0x5459:
        r16[cx] = 0x0028;
        rep_movsw_data_data_forward();
        r16[di] += 0x1fb0;
        r8[cl] = 0x28;
        rep_movsw_data_data_forward();
        r16[di] -= 0x2000;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x5459;
            break;
        }
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_5477() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        if (memory[cs*16+0x1] < 0x03)
            _STOP_("goto loc_5439");
        r16[ax] = 0x000d;
        interrupt(16);
        yield* sub_1c30();
        r16[ax] = 0x168f;
        ds = r16[ax];
        ds = memory16get(ds*16+21100);
        r16[si] = r16[si] ^ r16[si];
        r16[di] = r16[di] ^ r16[di];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
    case 0x54a8:
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x0fa0;
        rep_movsw_data_data_forward();
        r16[di] = r16[di] ^ r16[di];
        r8[ah] <<= 1;
        if (r8[ah] < 0x10) {
            pc = 0x54a8;
            break;
        }
        yield* sub_1c1a();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x54c4:
        yield* sub_3160();
        yield* sub_562d();
        r16[bx] = 0x66e0;
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        r8[dl] = 0xc8;
    case 0x54d6:
        r8[ch] = 0x50;
    case 0x54d8:
        r8[ah] = r8[ah] ^ r8[ah];
        r8[cl] = 0x04;
    case 0x54dc:
        lodsb_data_forward();
        _xlatcs();
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        _rcl8(ah, 1);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        _rcl8(ah, 1);
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x54dc;
            break;
        }
        memory[es*16+r16[di]] = r8[ah];
        r16[di] += 1;
        r8[ch] -= 1;
        if (r8[ch] != 0) {
            pc = 0x54d8;
            break;
        }
        if (r16s[di] < signed16(0x2000)) {
            pc = 0x54ff;
            break;
        }
        r16[di] -= 0x2000;
        pc = 0x5503;
        break;
    case 0x54ff:
        r16[di] += 0x1fb0;
    case 0x5503:
        r8[dl] -= 1;
        if (r8[dl] != 0) {
            pc = 0x54d6;
            break;
        }
        return;
    case 0x5508:
        r16[ax] = 0x000d;
        interrupt(16);
        yield* sub_1c30();
        yield* sub_562d();
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[bl] = 0x01;
    case 0x551c:
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
    case 0x551f:
        r8[ah] = r8[ah] ^ r8[ah];
        r8[cl] = 0x08;
    case 0x5523:
        lodsb_data_forward();
        if (!(r8[bl] & r8[al])) {
            pc = 0x5529;
            break;
        }
        flags.carry = true;
    case 0x5529:
        _ASSERT(0); /* unk previous */ _rcl(r8[ah], 1);
        r8[cl] -= 1;
        if (r8[cl] != 0) {
            pc = 0x5523;
            break;
        }
        r8[al] = r8[ah];
        stosb_data_forward();
        if (r16[si] < 0xfa00) {
            pc = 0x551f;
            break;
        }
        r16[di] = r16[di] ^ r16[di];
        r16[si] -= 0xfa00;
        r8[bl] <<= 1;
        if (r8[bl] < 0x10) {
            pc = 0x551c;
            break;
        }
        r16[ax] = 0x168f;
        es = r16[ax];
        r16[dx] = 0x87c2;
        r16[ax] = 0x1002;
        interrupt(16);
        yield* sub_1c1a();
        return;
        _STOP_("db 00h");
        _STOP_("sp-trace-fail");
        _STOP_("continues");
        return;
    } while (1);
}
function* sub_5557() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x5566;
            break;
        }
        if (r8[al] >= 0x03)
            _STOP_("goto loc_5508");
        _STOP_("goto loc_54c4");
    case 0x5566:
        push(ds);
        r16[ax] = 0x0013;
        interrupt(16);
        yield* sub_1c30();
        yield* sub_3243();
        r16[dx] = 0x03c8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[cx] = 0x0300;
    case 0x557c:
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x557c;
            break;
        }
        yield* sub_562d();
        r16[cx] = 0x7d00;
        rep_movsw_video_data_forward();
        yield* sub_3243();
        yield* sub_1c1a();
        r16[si] = ds;
        r16[si] -= 0x0030;
        ds = r16[si];
    case 0x5594:
        memory[cs*16+0x5556] = 0x00;
        r16[si] = r16[si] ^ r16[si];
        bp = bp ^ bp;
    case 0x559e:
        if (memory[cs*16+0x5556] & 0x0f) {
            pc = 0x55a9;
            break;
        }
        yield* sub_3243();
    case 0x55a9:
        if (memory[cs*16+0x3] == 0x00) {
            pc = 0x561d;
            break;
        }
        r16[dx] = 0x03c7;
        r8[al] = memory[cs*16+0x5556];
        out8(r16[dx], r8[al]);
        r8[dl] = 0xc9;
        pc = 0x55bd;
        break;
    case 0x55bd:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[ah] = r8[al];
        pc = 0x55c4;
        break;
    case 0x55c4:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[bl] = r8[al];
        pc = 0x55cb;
        break;
    case 0x55cb:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[bh] = r8[al];
        r8[dl] = 0xc8;
        r8[al] = memory[cs*16+0x5556];
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = r8[ah];
        if (memory[ds*16+r16[si]] <= r8[al]) {
            pc = 0x55e5;
            break;
        }
        if (r8[al] > 0x3d) {
            pc = 0x55e5;
            break;
        }
        r8[al] += 0x02;
        bp += 1;
    case 0x55e5:
        out8(r16[dx], r8[al]);
        r8[al] = r8[bl];
        if (memory[ds*16+r16[si] + 1] <= r8[al]) {
            pc = 0x55f4;
            break;
        }
        if (r8[al] > 0x3d) {
            pc = 0x55f4;
            break;
        }
        r8[al] += 0x02;
        bp += 1;
    case 0x55f4:
        out8(r16[dx], r8[al]);
        r8[al] = r8[bh];
        if (memory[ds*16+r16[si] + 2] <= r8[al]) {
            pc = 0x5603;
            break;
        }
        if (r8[al] > 0x3d) {
            pc = 0x5603;
            break;
        }
        r8[al] += 0x02;
        bp += 1;
    case 0x5603:
        out8(r16[dx], r8[al]);
        r16[si] += 0x0003;
        memory[cs*16+0x5556] += 1;
        if (memory[cs*16+0x5556] < 0x40) {
            pc = 0x559e;
            break;
        }
        yield* _sync();
        bp |= bp;
        if (bp == 0) {
            pc = 0x561b;
            break;
        }
        pc = 0x5594;
        break;
    case 0x561b:
        pc = 0x562b;
        break;
    case 0x561d:
        r16[dx] = 0x03c8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r16[cx] = 0x00c0;
    case 0x5627:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x5627;
            break;
        }
    case 0x562b:
        ds = pop();
        return;
    } while (1);
}
function* sub_562d() {
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = memory16get(ds*16+21100);
    r16[si] += 0x0030;
    ds = r16[si];
    r16[si] = r16[si] ^ r16[si];
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = r16[di] ^ r16[di];
}
function* sub_5645() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x5645:
        if (memory[cs*16+0x3] == 0x00) {
            pc = 0x56cb;
            break;
        }
        r8[al] = memory[cs*16+0x1];
        if (r8[al] == 0x05) {
            pc = 0x5656;
            break;
        }
        return;
    case 0x5656:
        memory[cs*16+0x5556] = 0x00;
        bp = bp ^ bp;
    case 0x565e:
        if (memory[cs*16+0x5556] & 0x0f) {
            pc = 0x5669;
            break;
        }
        yield* sub_3243();
    case 0x5669:
        r16[dx] = 0x03c7;
        r8[al] = memory[cs*16+0x5556];
        out8(r16[dx], r8[al]);
        r8[dl] = 0xc9;
        pc = 0x5675;
        break;
    case 0x5675:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[ah] = r8[al];
        pc = 0x567c;
        break;
    case 0x567c:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[bl] = r8[al];
        pc = 0x5683;
        break;
    case 0x5683:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x3f;
        r8[bh] = r8[al];
        r8[dl] = 0xc8;
        r8[al] = memory[cs*16+0x5556];
        out8(r16[dx], r8[al]);
        r16[dx] += 1;
        r8[al] = r8[ah];
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        bp |= r16[ax];
        out8(r16[dx], r8[al]);
        r8[al] = r8[bl];
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        bp |= r16[ax];
        out8(r16[dx], r8[al]);
        r8[al] = r8[bh];
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        flags.carry = r8[al] < 0x01;
        r8[al] -= 0x01;
        r8[al] = r8[al] + 0x00 + flags.carry;
        bp |= r16[ax];
        out8(r16[dx], r8[al]);
        memory[cs*16+0x5556] += 1;
        if (memory[cs*16+0x5556] < 0x40) {
            pc = 0x565e;
            break;
        }
        bp |= bp;
        if (bp == 0) {
            pc = 0x56cb;
            break;
        }
        pc = 0x5645;
        break;
    case 0x56cb:
        return;
    } while (1);
}
function* sub_56cc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[si]);
        push(r16[cx]);
        push(r16[bx]);
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = 0x7699;
        r16[cx] = 0x0032;
        memory[ds*16+25853] = 0x00;
    case 0x56df:
        r16[di] = 0x87d3;
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        if (r16[ax] == 0xffff) {
            pc = 0x5700;
            break;
        }
        r8[ah] &= 0x1f;
    case 0x56ed:
        r16[di] += 1;
        r16[di] += 1;
        if (memory16get(ds*16+r16[di]) != r16[ax]) {
            pc = 0x56ed;
            break;
        }
        memory16set(ds*16+r16[si] + 10, r16[di]);
        r16[di] = r16[ax];
        r8[al] = memory[ds*16+r16[di] + 28869];
        memory[ds*16+25853] += r8[al];
    case 0x5700:
        r16[si] += 0x001a;
        if (--r16[cx]) {
            pc = 0x56df;
            break;
        }
        r16[si] = 0x7dcb;
        r16[cx] = 0x000a;
    case 0x570b:
        r16[ax] = memory16get(ds*16+r16[si] + 12);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r8[al] = memory[ds*16+r16[si] + 16];
        memory[ds*16+r16[si] + 6] = r8[al];
        memory16set(ds*16+r16[si] + 17, 0x0000);
        r16[si] += 0x0014;
        if (--r16[cx]) {
            pc = 0x570b;
            break;
        }
        r8[bl] = memory[ds*16+21072];
        r8[bh] = r8[bh] ^ r8[bh];
        r8[al] = memory[ds*16+r16[bx] + 20660];
        memory[ds*16+0x64e8] = r8[al];
        r16[bx] = pop();
        r16[cx] = pop();
        r16[si] = pop();
        return;
    } while (1);
}
function* sub_5737() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x7699;
        r16[di] = 0x5570;
        bp = 0xffff;
        memory16set(ds*16+21876, bp);
        memory16set(ds*16+21894, bp);
        memory16set(ds*16+21912, bp);
        memory16set(ds*16+21930, bp);
        memory16set(ds*16+21948, bp);
        memory16set(ds*16+21966, bp);
        memory16set(ds*16+21984, bp);
        memory16set(ds*16+22002, bp);
        r16[ax] = memory16get(ds*16+0x5270);
        r16[dx] = memory16get(ds*16+21106);
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[dx] <<= r8[cl];
        r16[cx] = 0x0032;
    case 0x5770:
        if (memory16get(ds*16+r16[si] + 4) != bp) {
            pc = 0x5778;
            break;
        }
        pc = 0x58a6;
        break;
    case 0x5778:
        memory[ds*16+r16[si] + 5] &= 0xdf;
        r16[bx] = memory16get(ds*16+r16[si]);
        r16[bx] += 0x0020;
        flags.carry = r16[bx] < r16[ax];
        r16[bx] -= r16[ax];
        if (!flags.carry) {
            pc = 0x5788;
            break;
        }
        pc = 0x589d;
        break;
    case 0x5788:
        r16[bx] -= 0x0040;
        if (r16s[bx] <= signed16(0x0140)) {
            pc = 0x5794;
            break;
        }
        pc = 0x589d;
        break;
    case 0x5794:
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        flags.carry = r16[bx] < r16[dx];
        r16[bx] -= r16[dx];
        if (!flags.carry) {
            pc = 0x579e;
            break;
        }
        pc = 0x589d;
        break;
    case 0x579e:
        r16[bx] -= 0x0020;
        if (r16s[bx] <= signed16(0x00c0)) {
            pc = 0x57aa;
            break;
        }
        pc = 0x589d;
        break;
    case 0x57aa:
        memory[ds*16+r16[si] + 5] |= 0x20;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_64ff();
        memory16set(ds*16+r16[di] + 9, r16[si]);
        r16[bx] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[di], r16[bx]);
        r16[bx] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[di] + 2, r16[bx]);
        push(r16[cx]);
        push(r16[si]);
        if (!(memory[ds*16+r16[si] + 7] & 0xc0)) {
            pc = 0x57cb;
            break;
        }
        pc = 0x5891;
        break;
    case 0x57cb:
        if (memory[ds*16+25876] != 0x00) {
            pc = 0x57e8;
            break;
        }
        if (memory16get(ds*16+r16[si] + 4) != 0x05aa) {
            pc = 0x57dc;
            break;
        }
        pc = 0x5891;
        break;
    case 0x57dc:
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 36571));
    case 0x57e8:
        if (memory[ds*16+25873] == 0x00) {
            pc = 0x5825;
            break;
        }
        r16[si] = 0x52a0;
        r16[cx] = 0x0028;
    case 0x57f5:
        if (memory16get(ds*16+r16[si] + 6) != 0x0000) {
            pc = 0x580a;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x5820;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 12);
        if (r16[ax] < 0x000a) {
            pc = 0x5820;
            break;
        }
    case 0x580a:
        r16[ax] = r16[bx];
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] = r16[ax];
        if (memory[ds*16+r16[bx] + 28441] & 0x10) {
            pc = 0x5820;
            break;
        }
        yield* sub_5095();
        if (flags.carry) {
            pc = 0x584e;
            break;
        }
    case 0x5820:
        r16[si] += 0x0012;
        if (--r16[cx]) {
            pc = 0x57f5;
            break;
        }
    case 0x5825:
        if (memory[ds*16+25866] == 0x00) {
            pc = 0x5891;
            break;
        }
        if (memory[ds*16+25865] != 0x00) {
            pc = 0x5891;
            break;
        }
        r16[si] = 0x528e;
        if (memory16get(ds*16+r16[si] + 4) == 0xffff) {
            pc = 0x5891;
            break;
        }
        yield* sub_5095();
        if (!flags.carry) {
            pc = 0x5891;
            break;
        }
        memory[ds*16+25883] = 0x00;
        memory16set(ds*16+r16[si] + 4, 0xffff);
        yield* sub_58b0();
    case 0x584e:
        if (memory[ds*16+r16[si] + 4] == 0x49) {
            pc = 0x5857;
            break;
        }
        memory16set(ds*16+r16[si] + 6, -memory16get(ds*16+r16[si] + 6));
    case 0x5857:
        r8[al] = 0x01;
        yield* sub_11e6();
        memory[ds*16+25866] = 0x00;
        r16[bx] = memory16get(ds*16+r16[di] + 4);
        r8[bh] &= 0x1f;
        if (memory[ds*16+r16[bx] + 28768] == 0x00) {
            pc = 0x5888;
            break;
        }
        if (memory[ds*16+25883] != 0x00) {
            pc = 0x5891;
            break;
        }
        memory[ds*16+25883] = 0x0a;
        memory[ds*16+r16[di] + 5] |= 0x40;
        memory[ds*16+25832] -= 1;
        if (memory[ds*16+25832] != 0) {
            pc = 0x5891;
            break;
        }
        memory[ds*16+25853] -= 1;
    case 0x5888:
        bp = sp;
        r16[si] = memory16get(ss*16+bp + 0);
        memory[ds*16+r16[si] + 7] |= 0x80;
    case 0x5891:
        r16[si] = pop();
        r16[cx] = pop();
        bp = 0xffff;
        r16[di] += 0x0012;
        r16[dx] = pop();
        r16[ax] = pop();
        pc = 0x58a6;
        break;
    case 0x589d:
        if (!(memory[ds*16+r16[si] + 7] & 0xc0)) {
            pc = 0x58a6;
            break;
        }
        memory16set(ds*16+r16[si] + 4, bp);
    case 0x58a6:
        r16[si] += 0x001a;
        r16[cx] -= 1;
        if (r16[cx] == 0) {
            pc = 0x58af;
            break;
        }
        pc = 0x5770;
        break;
    case 0x58af:
        return;
    } while (1);
}
function* sub_58b0() {
    memory16set(ds*16+21138, 0x002d);
    memory16set(ds*16+21140, 0x0000);
    memory16set(ds*16+21148, 0x0000);
    memory[ds*16+25877] = 0x05;
}
function* sub_58c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[si] = 0x5600;
        r16[dx] = 0x0004;
        r8[cl] = 0x04;
    case 0x58d0:
        if (memory16get(ds*16+r16[si] + 4) == 0xffff) {
            pc = 0x5926;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 6);
        r16[ax] |= r16[ax];
        if (r16[ax] == 0) {
            pc = 0x58f0;
            break;
        }
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] >>= r8[cl];
        flags.carry = r16[ax] < memory16get(ds*16+21104);
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (flags.carry) {
            pc = 0x590a;
            break;
        }
        if (r16s[ax] > signed16(0x0014)) {
            pc = 0x590a;
            break;
        }
    case 0x58f0:
        r16[ax] = memory16get(ds*16+r16[si] + 14);
        if (r16[ax] == 0x0014) {
            pc = 0x5911;
            break;
        }
        sar16(ax, r8[cl]);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] >>= r8[cl];
        flags.carry = r16[ax] < memory16get(ds*16+21106);
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (flags.carry) {
            pc = 0x590a;
            break;
        }
        if (r16s[ax] <= signed16(0x00c0)) {
            pc = 0x5911;
            break;
        }
    case 0x590a:
        memory16set(ds*16+r16[si] + 4, 0xffff);
        pc = 0x5926;
        break;
    case 0x5911:
        r16[di] = 0x527c;
        yield* sub_5095();
        if (!flags.carry) {
            pc = 0x5926;
            break;
        }
        bp = 0x0046;
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 6);
        yield* sub_596f();
        pc = 0x590a;
        break;
    case 0x5926:
        r16[si] += 0x0012;
        r16[dx] -= 1;
        if (r16[dx] != 0) {
            pc = 0x58d0;
            break;
        }
        return;
    } while (1);
}
function* sub_592d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[di] = 0x5600;
        push(r16[cx]);
        r16[cx] = 0x0004;
    case 0x5934:
        if (memory16get(ds*16+r16[di] + 4) != 0xffff) {
            pc = 0x593d;
            break;
        }
        r16[cx] = pop();
        flags.carry = false;
        return;
    case 0x593d:
        r16[di] += 0x0012;
        if (--r16[cx]) {
            pc = 0x5934;
            break;
        }
        r16[cx] = pop();
        flags.carry = true;
        return;
    } while (1);
}
function* sub_5945() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x168f;
        ds = r16[ax];
        memory16set(ds*16+36531, 0x0032);
        r16[si] = 0x7699;
    case 0x5953:
        if (memory16get(ds*16+r16[si] + 4) == 0xffff) {
            pc = 0x5965;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[si] + 6);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        yield* indirectCall(memory16get(ds*16+r16[bx] + 36533));
    case 0x5965:
        r16[si] += 0x001a;
        memory16set(ds*16+36531, memory16get(ds*16+36531) - 1);
        if (memory16get(ds*16+36531) != 0) {
            pc = 0x5953;
            break;
        }
        return;
    } while (1);
}
function* sub_596f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r8[al] = 0x04;
        yield* sub_11e6();
        r16[ax] = pop();
        yield* sub_59cc();
        yield* sub_59cc();
        memory[ds*16+25876] = 0x18;
        memory[ds*16+25875] = 0x00;
        memory[ds*16+21127] = 0x00;
        if (memory16gets(ds*16+21116) > r16s[ax]) {
            pc = 0x5993;
            break;
        }
        bp = -bp;
    case 0x5993:
        memory16set(ds*16+21122, bp);
        memory16set(ds*16+21130, 0xff80);
        yield* sub_4ae9();
        return;
    } while (1);
}
function* sub_59a1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+25862] = 0x32;
        memory[ds*16+1049] += 1;
        if (memory[ds*16+1049] <= 0x10) {
            pc = 0x59ba;
            break;
        }
        memory[ds*16+1049] = 0x10;
        memory[ds*16+1050] += 1;
    case 0x59ba:
        return;
    } while (1);
}
function* sub_59bb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+1051] == 0x09) {
            pc = 0x59c6;
            break;
        }
        memory[ds*16+1051] += 1;
    case 0x59c6:
        memory[ds*16+25862] = 0x00;
        return;
    } while (1);
}
function* sub_59cc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+25862] = 0x32;
        if (memory[ds*16+25878] != 0x00) {
            pc = 0x59e6;
            break;
        }
        memory[ds*16+1049] -= 1;
        if (memorys[ds*16+1049] >= 0) {
            pc = 0x59e6;
            break;
        }
        memory[ds*16+1049] = 0x00;
        yield* sub_59e7();
    case 0x59e6:
        return;
    } while (1);
}
function* sub_59e7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+25878] = 0x0a;
        if (memory[ds*16+1051] == 0x00) {
            pc = 0x59fd;
            break;
        }
        memory[ds*16+1051] -= 1;
        memory[ds*16+25862] = 0x00;
        return;
    case 0x59fd:
        memory[ds*16+25879] = 0x01;
        return;
    } while (1);
}
function* sub_5a04() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        r16[si] = 0x527c;
        yield* sub_5095();
        if (!flags.carry) {
            pc = 0x5a40;
            break;
        }
        r16[bx] = memory16get(ds*16+r16[di] + 9);
        if (memory[ds*16+r16[bx] + 6] == 0x0b) {
            pc = 0x5a2c;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[bx] + 4);
        r8[ah] &= 0x1f;
        if (r16[ax] == 0x00b2) {
            pc = 0x5a2c;
            break;
        }
        memory16set(ds*16+r16[bx] + 8, -memory16get(ds*16+r16[bx] + 8));
    case 0x5a2c:
        r16[ax] = memory16get(ds*16+r16[di] + 4);
        r8[ah] &= 0x1f;
        r16[ax] -= 0x009a;
        if (r16[ax] > 0x0002) {
            pc = 0x5a3f;
            break;
        }
        memory[ds*16+25857] = 0x01;
    case 0x5a3f:
        flags.carry = true;
    case 0x5a40:
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        if (!flags.carry) {
            pc = 0x5a57;
            break;
        }
        bp = memory16get(ds*16+r16[si] + 12);
        bp |= bp;
        if (bp == 0) {
            pc = 0x5a57;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        yield* sub_596f();
    case 0x5a57:
        return;
    } while (1)
}
function* loc_5a58() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] & 0x40) {
            pc = 0x5a98;
            break;
        }
        memory[ds*16+r16[si] + 7] |= 0x40;
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r8[bl] = memory[ds*16+r16[bx] + 28639];
        r8[bl] &= 0xf0;
        if (r8[bl] == 0xf0) {
            pc = 0x5a8f;
            break;
        }
        r8[cl] = 0x03;
        r8[bh] = r8[bh] ^ r8[bh];
        r16[bx] >>= r8[cl];
        r8[ah] = memory[ds*16+r16[si] + 5];
        r16[ax] &= 0x8000;
        r16[ax] = r16[ax] | memory16get(ds*16+r16[bx] + 28627);
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        memory16set(ds*16+r16[si] + 8, 0x0000);
        memory[ds*16+r16[si] + 14] = 0xff;
        return;
    case 0x5a8f:
        memory16set(ds*16+r16[si] + 8, 0xfff6);
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x5a98:
        if (memory[ds*16+r16[si] + 14] == 0xff) {
            pc = 0x5ab7;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        if (memory[ds*16+25877] == 0x00) {
            pc = 0x5aaf;
            break;
        }
        memory16set(ds*16+21136, memory16get(ds*16+21136) + r16[ax]);
    case 0x5aaf:
        if (r16s[ax] >= signed16(0x0014)) {
            pc = 0x5ab7;
            break;
        }
        memory16set(ds*16+r16[si] + 8, memory16get(ds*16+r16[si] + 8) + 1);
    case 0x5ab7:
        return;
    } while (1);
}
function* sub_5ab8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x5ac1;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x5ac1:
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        r16[dx] = memory16get(ds*16+r16[si] + 15);
        r16[ax] -= r16[dx];
        if (memory16gets(ds*16+21116) < r16s[ax]) {
            pc = 0x5b21;
            break;
        }
        r16[ax] += r16[dx];
        r16[ax] += r16[dx];
        if (memory16gets(ds*16+21116) > r16s[ax]) {
            pc = 0x5b21;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        r16[dx] = memory16get(ds*16+r16[si] + 17);
        r16[ax] -= r16[dx];
        if (memory16gets(ds*16+21118) < r16s[ax]) {
            pc = 0x5b21;
            break;
        }
        r16[ax] += r16[dx];
        r16[ax] += r16[dx];
        if (memory16gets(ds*16+21118) > r16s[ax]) {
            pc = 0x5b21;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x5afa;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5afa:
        r16[dx] = memory16get(ds*16+r16[si]);
        if (memory16get(ds*16+21116) == r16[dx]) {
            pc = 0x5b0b;
            break;
        }
        if (memory16gets(ds*16+21116) < r16s[dx]) {
            pc = 0x5b06;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5b06:
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
    case 0x5b0b:
        r8[al] = memory[ds*16+r16[si] + 19];
        r16[dx] = memory16get(ds*16+r16[si] + 2);
        if (memory16get(ds*16+21118) == r16[dx]) {
            pc = 0x5b1f;
            break;
        }
        if (memory16gets(ds*16+21118) < r16s[dx]) {
            pc = 0x5b1b;
            break;
        }
        r8[al] = -r8[al];
    case 0x5b1b:
        _cbw();
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) - r16[ax]);
    case 0x5b1f:
        pc = 0x5b4d;
        break;
    case 0x5b21:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x5b2a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5b2a:
        r16[dx] = memory16get(ds*16+r16[si]);
        if (memory16get(ds*16+r16[si] + 20) == r16[dx]) {
            pc = 0x5b3a;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 20) < r16s[dx]) {
            pc = 0x5b35;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5b35:
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
    case 0x5b3a:
        r8[al] = memory[ds*16+r16[si] + 19];
        r16[dx] = memory16get(ds*16+r16[si] + 2);
        if (memory16get(ds*16+r16[si] + 22) == r16[dx]) {
            pc = 0x5b4d;
            break;
        }
        if (memory16gets(ds*16+r16[si] + 22) < r16s[dx]) {
            pc = 0x5b49;
            break;
        }
        r8[al] = -r8[al];
    case 0x5b49:
        _cbw();
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) - r16[ax]);
    case 0x5b4d:
        return;
    } while (1);
}
function* sub_5b4e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+r16[si] + 7] &= 0x3f;
        r16[ax] = memory16get(ds*16+r16[si] + 19);
        r16[ax] += 1;
        if (memory16get(ds*16+r16[si] + 17) > r16[ax]) {
            pc = 0x5bb7;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x5b65;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5b65:
        if (memory16get(ds*16+r16[si] + 15) < r16[ax]) {
            pc = 0x5bb5;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (memory16gets(ds*16+r16[si] + 21) < r16s[ax]) {
            pc = 0x5bba;
            break;
        }
        r16[di] = 0x528e;
        r16[ax] = 0xffff;
    case 0x5b7b:
        r16[di] += 0x0012;
        if (memory16get(ds*16+r16[di] + 4) != r16[ax]) {
            pc = 0x5b7b;
            break;
        }
        if (r16[di] >= 0x5570) {
            pc = 0x5bb5;
            break;
        }
        yield* sub_64df();
        r16[bx] = memory16get(ds*16+r16[si] + 10);
        r16[ax] = memory16get(ds*16+r16[bx]);
        r8[ah] &= 0x1f;
        r8[ah] |= 0x80;
        memory16set(ds*16+r16[di] + 4, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        memory[ds*16+r16[di] + 11] = 0x03;
        memory16set(ds*16+r16[di] + 14, 0x0000);
        memory[ds*16+25873] = 0x04;
        yield* sub_64ef();
    case 0x5bb5:
        r16[ax] = r16[ax] ^ r16[ax];
    case 0x5bb7:
        memory16set(ds*16+r16[si] + 19, r16[ax]);
    case 0x5bba:
        return;
    } while (1);
}
function* sub_5bbb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x5bc5;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x5bc5:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x5c07;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x5bd5;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5bd5:
        r16[dx] = memory16get(ds*16+21116);
        r16[dx] = r16[dx] - memory16get(ds*16+r16[si]);
        if (r16s[dx] >= 0) {
            pc = 0x5be1;
            break;
        }
        r16[ax] = -r16[ax];
        r16[dx] = -r16[dx];
    case 0x5be1:
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        if (memory16get(ds*16+r16[si] + 23) < r16[dx]) {
            pc = 0x5c5f;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5bf5;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5bf5:
        if (r16[ax] > 0x0028) {
            pc = 0x5c5f;
            break;
        }
        yield* sub_64df();
        memory[ds*16+r16[si] + 14] += 1;
        memory16set(ds*16+r16[si] + 21, 0x000a);
        pc = 0x5c5f;
        break;
    case 0x5c07:
        if (r8[al] != 0x01) {
            pc = 0x5c23;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 21);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) - r16[ax]);
        memory16set(ds*16+r16[si] + 21, memory16get(ds*16+r16[si] + 21) - 1);
        if (memory16get(ds*16+r16[si] + 21) != 0) {
            pc = 0x5c5f;
            break;
        }
        yield* sub_64df();
        memory[ds*16+r16[si] + 14] += 1;
        pc = 0x5c5f;
        break;
    case 0x5c23:
        if (r8[al] != 0x02) {
            pc = 0x5c49;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 21);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        memory16set(ds*16+r16[si] + 21, memory16get(ds*16+r16[si] + 21) + 1);
        if (memory16get(ds*16+r16[si] + 21) <= 0x000a) {
            pc = 0x5c5f;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        r8[al] = memory[ds*16+r16[si] + 20];
        memory[ds*16+r16[si] + 21] = r8[al];
        pc = 0x5c5f;
        break;
    case 0x5c49:
        if (r8[al] != 0x03) {
            pc = 0x5c5f;
            break;
        }
        memory[ds*16+r16[si] + 21] -= 1;
        if (memory[ds*16+r16[si] + 21] != 0) {
            pc = 0x5c5f;
            break;
        }
        yield* sub_64ef();
        yield* sub_64ef();
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x5c5f:
        return;
    } while (1);
}
function* sub_5c60() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16+r16[si] + 7] &= 0x3f;
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x5c80;
            break;
        }
        yield* sub_64df();
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si] + 17, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        memory[ds*16+r16[si] + 14] = 0x01;
        pc = 0x5cc9;
        break;
    case 0x5c80:
        if (r8[al] != 0x01) {
            pc = 0x5c95;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) - r16[ax]);
        memory16set(ds*16+r16[si] + 17, memory16get(ds*16+r16[si] + 17) - 1);
        if (memory16get(ds*16+r16[si] + 17) != 0) {
            pc = 0x5cc9;
            break;
        }
        memory[ds*16+r16[si] + 14] = 0x02;
        pc = 0x5cc9;
        break;
    case 0x5c95:
        if (r8[al] != 0x02) {
            pc = 0x5cbc;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        memory16set(ds*16+r16[si] + 17, memory16get(ds*16+r16[si] + 17) + 1);
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        if (memory16gets(ds*16+r16[si] + 2) < r16s[ax]) {
            pc = 0x5cc9;
            break;
        }
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r8[al] = memory[ds*16+r16[si] + 19];
        memory[ds*16+r16[si] + 17] = r8[al];
        memory[ds*16+r16[si] + 14] = 0x03;
        yield* sub_64ef();
        pc = 0x5cc9;
        break;
    case 0x5cbc:
        if (r8[al] != 0x03) {
            pc = 0x5cc9;
            break;
        }
        memory[ds*16+r16[si] + 17] -= 1;
        if (memory[ds*16+r16[si] + 17] != 0) {
            pc = 0x5cc9;
            break;
        }
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x5cc9:
        return;
    } while (1);
}
function* sub_5cca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x5cd4;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x5cd4:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x5d09;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5ce4;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5ce4:
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x5d01;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5cf3;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5cf3:
        if (r16[ax] > 0x001a) {
            pc = 0x5d01;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        yield* sub_621c();
    case 0x5d01:
        return;
        _STOP_("db e8h");
        _STOP_("db eah");
        _STOP_("db 07h");
        _STOP_("db feh");
        _STOP_("db 4ch");
        _STOP_("db 0eh");
        _STOP_("db c3h");
    case 0x5d09:
        if (r8[al] != 0x01) {
            pc = 0x5d7a;
            break;
        }
        yield* sub_6567();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x5d17;
            break;
        }
        yield* sub_5eca();
    case 0x5d17:
        memory[ds*16+r16[si] + 2] &= 0xf0;
        r8[al] = memory[es*16+r16[di] + 65280];
        r16[bx] = 0x72a3;
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x5d2b;
            break;
        }
        memory16set(ds*16+r16[si] + 8, -memory16get(ds*16+r16[si] + 8));
    case 0x5d2b:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x5d39;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x5d39:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5d42;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5d42:
        if (r16[ax] < 0x0280) {
            pc = 0x5d4c;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        pc = 0x5d01;
        break;
    case 0x5d4c:
        flags.carry = memory[ds*16+r16[si] + 20] < 0x01;
        memory[ds*16+r16[si] + 20] -= 0x01;
        memory[ds*16+r16[si] + 20] = memory[ds*16 + r16[si] + 20] + 0x00 + flags.carry;
        if (_FIXME_) {
            pc = 0x5dcd;
            break;
        }
        if (r16[ax] > 0x0040) {
            pc = 0x5dcd;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5d65;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5d65:
        if (r16[ax] > 0x0014) {
            pc = 0x5dcd;
            break;
        }
        yield* sub_621c();
        memory[ds*16+r16[si] + 14] = 0x03;
        yield* sub_64df();
        memory[ds*16+r16[si] + 20] = 0x14;
        pc = 0x5dcd;
        break;
    case 0x5d7a:
        if (r8[al] != 0x02) {
            pc = 0x5db0;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (r16[ax] >= 0x0015) {
            pc = 0x5d9c;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] <= 0x000d) {
            pc = 0x5dcd;
            break;
        }
    case 0x5d9c:
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] = 0x00;
        pc = 0x5dcd;
        break;
    case 0x5db0:
        if (r8[al] != 0x03) {
            pc = 0x5dcd;
            break;
        }
        if (!(memory[ds*16+r16[si] + 7] & 0x20)) {
            pc = 0x5dcd;
            break;
        }
        yield* sub_592d();
        if (flags.carry) {
            pc = 0x5dc6;
            break;
        }
        memory16set(ds*16+r16[si] + 10, memory16get(ds*16+r16[si] + 10) + 0x0004);
        yield* sub_6496();
    case 0x5dc6:
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] = 0x01;
    case 0x5dcd:
        return;
    } while (1);
}
function* sub_5dce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x5dd8;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x5dd8:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x5e0e;
            break;
        }
        if (memory[ds*16+25874] != 0x00) {
            pc = 0x5e44;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5def;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5def:
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x5e44;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5dfe;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5dfe:
        if (r16[ax] > 0x001a) {
            pc = 0x5e44;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        yield* sub_621c();
        pc = 0x5e44;
        break;
    case 0x5e0e:
        if (r8[al] != 0x01) {
            pc = 0x5e4c;
            break;
        }
        if (memory[ds*16+25874] != 0x00) {
            pc = 0x5e44;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5e22;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5e22:
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x5e45;
            break;
        }
        r16[ax] += 0x0032;
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x5e44;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5e39;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5e39:
        if (r16[ax] > 0x003c) {
            pc = 0x5e44;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
    case 0x5e44:
        return;
    case 0x5e45:
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] -= 1;
        return;
    case 0x5e4c:
        if (r8[al] != 0x02) {
            pc = 0x5e92;
            break;
        }
        yield* sub_6567();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x5e5a;
            break;
        }
        yield* sub_5eca();
    case 0x5e5a:
        memory[ds*16+r16[si] + 2] &= 0xf0;
        yield* sub_5ee4();
        r8[al] = memory[es*16+((r16[di] + 65280)&0xffff)];
        r16[bx] = 0x72a3;
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x5e71;
            break;
        }
        yield* sub_5eca();
    case 0x5e71:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x5e7f;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x5e7f:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5e88;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5e88:
        if (r16[ax] < 0x0280) {
            pc = 0x5ec9;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        pc = 0x5ec9;
        break;
    case 0x5e92:
        if (r8[al] != 0x03) {
            pc = 0x5ec9;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (r16[ax] >= 0x0015) {
            pc = 0x5eb4;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        sar16(ax, r8[cl]);
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] <= 0x000d) {
            pc = 0x5ec9;
            break;
        }
    case 0x5eb4:
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        yield* sub_64ef();
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x5ec9:
        return;
    } while (1);
}
function* sub_5eca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[dx]);
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x5ed5;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5ed5:
        r16[dx] = memory16get(ds*16+r16[si]);
        if (memory16gets(ds*16+r16[si] + 15) <= r16s[dx]) {
            pc = 0x5ede;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5ede:
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        r16[dx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_5ee4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0001;
        if (memory16gets(ds*16+r16[si] + 8) > signed16(0x0000)) {
            pc = 0x5eef;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5eef:
        r16[di] -= r16[ax];
        return;
    } while (1);
}
function* sub_5ef2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x5efc;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x5efc:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x5f2a;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5f0c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5f0c:
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x5f29;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x5f1b;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5f1b:
        if (r16[ax] > 0x003c) {
            pc = 0x5f29;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        yield* sub_621c();
    case 0x5f29:
        return;
    case 0x5f2a:
        if (r8[al] != 0x01) {
            pc = 0x5f98;
            break;
        }
        memory[ds*16+25856] += 1;
        if (memory[ds*16+25856] & 0x04) {
            pc = 0x5f44;
            break;
        }
        if (memory16get(ds*16+25854) & 0x01ff) {
            pc = 0x5f44;
            break;
        }
        yield* sub_64df();
    case 0x5f44:
        if (memory[ds*16+25854] & 0x7f) {
            pc = 0x5f55;
            break;
        }
        r8[al] = 0x03;
        memory[ds*16+r16[si] + 14] = r8[al];
        yield* sub_64df();
        pc = 0x5f98;
        break;
    case 0x5f55:
        yield* sub_6567();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x5f5f;
            break;
        }
        yield* sub_5eca();
    case 0x5f5f:
        memory[ds*16+r16[si] + 2] &= 0xf0;
        yield* sub_5ee4();
        r8[al] = memory[es*16+r16[di] + 65280];
        r16[bx] = 0x72a3;
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x5f76;
            break;
        }
        memory16set(ds*16+r16[si] + 8, -memory16get(ds*16+r16[si] + 8));
    case 0x5f76:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x5f84;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x5f84:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x5f8d;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x5f8d:
        if (r16[ax] < 0x0500) {
            pc = 0x5f29;
            break;
        }
        memory[ds*16+r16[si] + 14] = 0x02;
        pc = 0x5ff8;
        break;
    case 0x5f98:
        if (r8[al] != 0x02) {
            pc = 0x5fce;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] > 0x000c) {
            pc = 0x5fba;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (r16[ax] < 0x0019) {
            pc = 0x5ff8;
            break;
        }
    case 0x5fba:
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si], r16[ax]);
        memory[ds*16+r16[si] + 14] = 0x00;
        yield* sub_64ef();
        pc = 0x5ff8;
        break;
    case 0x5fce:
        if (r8[al] != 0x03) {
            pc = 0x5ff8;
            break;
        }
        if (memory[ds*16+r16[si] + 5] & 0x20) {
            pc = 0x5feb;
            break;
        }
        yield* sub_64df();
        memory16set(ds*16+r16[si] + 10, memory16get(ds*16+r16[si] + 10) - 0x0002);
        yield* sub_64ff();
        yield* sub_621c();
        memory[ds*16+r16[si] + 14] = 0x01;
        pc = 0x5ff8;
        break;
    case 0x5feb:
        if (!(memory[ds*16+r16[si] + 7] & 0x20)) {
            pc = 0x5ff8;
            break;
        }
        yield* sub_621c();
        memory[ds*16+r16[si] + 14] = 0x01;
    case 0x5ff8:
        return;
        memory[ds*16+r16[si] + 7] &= 0x3f;
        return;
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x6008;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x6008:
        return;
        memory[ds*16+r16[si] + 7] &= 0x3f;
        pc = 0x6019;
        break;
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x6019;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x6019:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x604a;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x602a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x602a:
        if (r16[ax] > 0x0154) {
            pc = 0x603f;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        if (r16s[ax] >= 0) {
            pc = 0x603a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x603a:
        if (r16[ax] < 0x00e6) {
            pc = 0x6064;
            break;
        }
    case 0x603f:
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        yield* sub_621c();
        pc = 0x6064;
        break;
    case 0x604a:
        if (r8[al] != 0x01) {
            pc = 0x60ab;
            break;
        }
        yield* sub_6567();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x6065;
            break;
        }
        if (memory16get(ds*16+r16[si] + 21) >= 0x0010) {
            pc = 0x605e;
            break;
        }
        memory16set(ds*16+r16[si] + 21, memory16get(ds*16+r16[si] + 21) + 1);
    case 0x605e:
        r16[ax] = memory16get(ds*16+r16[si] + 21);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
    case 0x6064:
        return;
    case 0x6065:
        if (memory16get(ds*16+r16[si] + 21) == 0x0000) {
            pc = 0x606e;
            break;
        }
        yield* sub_621c();
    case 0x606e:
        memory16set(ds*16+r16[si] + 21, 0x0000);
        memory[ds*16+r16[si] + 2] &= 0xf0;
        yield* sub_5ee4();
        r8[al] = memory[es*16+r16[di] + 65280];
        r16[bx] = 0x72a3;
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x608a;
            break;
        }
        memory16set(ds*16+r16[si] + 8, -memory16get(ds*16+r16[si] + 8));
    case 0x608a:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x6098;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x6098:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x60a1;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x60a1:
        if (r16[ax] < 0x0280) {
            pc = 0x60df;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        pc = 0x60df;
        break;
    case 0x60ab:
        if (r8[al] != 0x02) {
            pc = 0x60df;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] > 0x000c) {
            pc = 0x60cd;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (r16[ax] < 0x0013) {
            pc = 0x60df;
            break;
        }
    case 0x60cd:
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si], r16[ax]);
        memory[ds*16+r16[si] + 14] = 0x00;
        yield* sub_64ef();
    case 0x60df:
        return;
    } while (1);
}
function* sub_60e0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x60ea;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x60ea:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x6123;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        if (memory16gets(ds*16+r16[si] + 2) > r16s[ax]) {
            pc = 0x6140;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x6103;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x6103:
        if (memory16get(ds*16+r16[si] + 23) < r16[ax]) {
            pc = 0x6140;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        if (r16s[ax] >= 0) {
            pc = 0x6113;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x6113:
        if (r16[ax] > 0x00c8) {
            pc = 0x6140;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        yield* sub_621c();
        pc = 0x6140;
        break;
    case 0x6123:
        if (r8[al] == 0x01) {
            pc = 0x612a;
            break;
        }
        pc = 0x61d4;
        break;
    case 0x612a:
        yield* sub_6567();
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x6141;
            break;
        }
        if (memory16get(ds*16+r16[si] + 21) >= 0x0010) {
            pc = 0x613a;
            break;
        }
        memory16set(ds*16+r16[si] + 21, memory16get(ds*16+r16[si] + 21) + 1);
    case 0x613a:
        r16[ax] = memory16get(ds*16+r16[si] + 21);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
    case 0x6140:
        return;
    case 0x6141:
        if (memory16get(ds*16+r16[si] + 21) == 0x0000) {
            pc = 0x614a;
            break;
        }
        yield* sub_621c();
    case 0x614a:
        memory16set(ds*16+r16[si] + 21, 0x0000);
        memory[ds*16+r16[si] + 2] &= 0xf0;
        yield* sub_5ee4();
        r8[al] = memory[es*16+r16[di] + 65280];
        r16[bx] = 0x72a3;
        _xlatds();
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x6166;
            break;
        }
        memory16set(ds*16+r16[si] + 8, -memory16get(ds*16+r16[si] + 8));
    case 0x6166:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        if (memory16gets(ds*16+r16[si]) >= 0) {
            pc = 0x6174;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x6174:
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x617d;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x617d:
        if (r16[ax] > 0x0280) {
            pc = 0x6191;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x618c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x618c:
        if (r16[ax] < 0x0190) {
            pc = 0x6198;
            break;
        }
    case 0x6191:
        memory[ds*16+r16[si] + 14] = 0x02;
        pc = 0x621b;
        break;
    case 0x6198:
        if (memory[ds*16+r16[si] + 14] != 0x01) {
            pc = 0x621b;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x61a7;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x61a7:
        r16[bx] = memory16get(ds*16+r16[si] + 4);
        r8[bh] &= 0x1f;
        r16[bx] <<= 1;
        r8[dl] = memory[ds*16+r16[bx] + 26213];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[dx] += 0x0006;
        if (r16[ax] > r16[dx]) {
            pc = 0x621b;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x61c6;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x61c6:
        if (r16[ax] > 0x0008) {
            pc = 0x621b;
            break;
        }
        memory[ds*16+r16[si] + 14] = 0x03;
        yield* sub_64df();
        pc = 0x621b;
        break;
    case 0x61d4:
        if (r8[al] != 0x02) {
            pc = 0x620a;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21106);
        if (r16[ax] > 0x000d) {
            pc = 0x61f6;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        r16[ax] >>= r8[cl];
        r16[ax] = r16[ax] - memory16get(ds*16+21104);
        if (r16[ax] < 0x0015) {
            pc = 0x621b;
            break;
        }
    case 0x61f6:
        r16[ax] = memory16get(ds*16+r16[si] + 17);
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 15);
        memory16set(ds*16+r16[si], r16[ax]);
        memory[ds*16+r16[si] + 14] = 0x00;
        yield* sub_64ef();
        pc = 0x621b;
        break;
    case 0x620a:
        if (r8[al] != 0x03) {
            pc = 0x621b;
            break;
        }
        if (memory[ds*16+r16[si] + 7] & 0x20) {
            pc = 0x6217;
            break;
        }
        pc = 0x612a;
        break;
    case 0x6217:
        memory[ds*16+r16[si] + 14] = 0x01;
    case 0x621b:
        return;
    } while (1);
}
function* sub_621c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = memory[ds*16+r16[si] + 19];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[ax] = memory16get(ds*16+0x527c);
        if (memory16gets(ds*16+r16[si]) > r16s[ax]) {
            pc = 0x622a;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x622a:
        memory16set(ds*16+r16[si] + 8, r16[dx]);
        return;
    } while (1);
}
function* sub_622e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x6238;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x6238:
        yield* sub_63c9();
        if (memory[ds*16+r16[si] + 5] & 0x20) {
            pc = 0x6244;
            break;
        }
        pc = 0x62c8;
        break;
    case 0x6244:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x6284;
            break;
        }
        r16[dx] = 0xfffe;
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        if (r16s[ax] >= 0) {
            pc = 0x625b;
            break;
        }
        r16[ax] = -r16[ax];
        r16[dx] = -r16[dx];
    case 0x625b:
        r8[cl] = memory[ds*16+r16[si] + 19];
        r8[ch] = r8[ch] ^ r8[ch];
        if (r16[ax] > r16[cx]) {
            pc = 0x62c8;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x626e;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x626e:
        if (r16[ax] > 0x0028) {
            pc = 0x62c8;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        memory16set(ds*16+r16[si] + 20, r16[dx]);
        memory[ds*16+r16[si] + 14] += 1;
        yield* sub_64df();
        pc = 0x62c8;
        break;
    case 0x6284:
        if (r8[al] != 0x01) {
            pc = 0x62ac;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 22);
        if (r16s[ax] >= 0) {
            pc = 0x6298;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x6298:
        r8[cl] = memory[ds*16+r16[si] + 19];
        r8[ch] = r8[ch] ^ r8[ch];
        if (r16[ax] < r16[cx]) {
            pc = 0x62c8;
            break;
        }
        memory16set(ds*16+r16[si] + 20, -memory16get(ds*16+r16[si] + 20));
        yield* sub_64df();
        memory[ds*16+r16[si] + 14] += 1;
        pc = 0x62c8;
        break;
    case 0x62ac:
        if (r8[al] != 0x02) {
            pc = 0x62c8;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        if (memory16get(ds*16+r16[si] + 2) != r16[ax]) {
            pc = 0x62c8;
            break;
        }
        yield* sub_64ef();
        yield* sub_64ef();
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x62c8:
        return;
    } while (1);
}
function* sub_62c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x62d3;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x62d3:
        r8[al] = memory[ds*16+r16[si] + 14];
        if (r8[al] != 0x00) {
            pc = 0x6342;
            break;
        }
        yield* sub_63c9();
        if (!(memory[ds*16+r16[si] + 5] & 0x20)) {
            pc = 0x6341;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[ax] = r16[ax] - memory16get(ds*16+21118);
        r8[ah] |= r8[ah];
        if (r8[ah] != 0) {
            pc = 0x6341;
            break;
        }
        if (memory[ds*16+r16[si] + 19] < r8[al]) {
            pc = 0x6341;
            break;
        }
        r8[cl] = r8[al];
        r8[dh] = r8[dh] ^ r8[dh];
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+21116);
        if (r16s[ax] >= 0) {
            pc = 0x6303;
            break;
        }
        r16[ax] = -r16[ax];
        r8[dh] = 0x80;
    case 0x6303:
        r8[dl] = memory[ds*16+r16[si] + 5];
        r8[dl] &= 0x80;
        if (r8[dl] != r8[dh]) {
            pc = 0x6341;
            break;
        }
        if (r16s[ax] >= signed16(0x0030)) {
            pc = 0x6341;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 15);
        if (r16s[ax] >= 0) {
            pc = 0x631c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x631c:
        if (memory16get(ds*16+r16[si] + 17) < r16[ax]) {
            pc = 0x6341;
            break;
        }
        memory[ds*16+r16[si] + 14] += 1;
        r16[dx] = r16[dx] ^ r16[dx];
    case 0x6326:
        r8[dl] += 1;
        r8[dh] += r8[dl];
        if (r8[cl] > r8[dh]) {
            pc = 0x6326;
            break;
        }
        r8[al] = r8[dl];
        _cbw();
        r16[ax] = -r16[ax];
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        memory16set(ds*16+r16[si] + 22, r16[ax]);
        yield* sub_64df();
        pc = 0x63be;
        break;
    case 0x6341:
        return;
    case 0x6342:
        if (!(memory[ds*16+r16[si] + 5] & 0x20)) {
            pc = 0x6341;
            break;
        }
        if (r8[al] != 0x01) {
            pc = 0x6391;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        r16[ax] += 1;
        if (r16[ax] == 0) {
            pc = 0x636f;
            break;
        }
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        flags.carry = r8[al] < memory[ds*16+r16[si] + 19];
        r8[al] = r8[al] - memory[ds*16+r16[si] + 19];
        r8[ah] -= 0x00 + flags.carry;
        if (memory16gets(ds*16+r16[si] + 2) > r16s[ax]) {
            pc = 0x63be;
            break;
        }
    case 0x636f:
        yield* sub_64df();
        memory[ds*16+r16[si] + 14] += 1;
        memory16set(ds*16+r16[si] + 20, 0x0000);
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x6383;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x6383:
        r16[dx] = memory16get(ds*16+r16[si] + 15);
        if (memory16gets(ds*16+r16[si]) <= r16s[dx]) {
            pc = 0x638c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x638c:
        memory16set(ds*16+r16[si] + 8, r16[ax]);
        pc = 0x63be;
        break;
    case 0x6391:
        if (r8[al] != 0x02) {
            pc = 0x63be;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 20);
        memory16set(ds*16+r16[si] + 2, memory16get(ds*16+r16[si] + 2) + r16[ax]);
        r16[ax] += 1;
        memory16set(ds*16+r16[si] + 20, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 22);
        if (memory16gets(ds*16+r16[si] + 2) < r16s[ax]) {
            pc = 0x63be;
            break;
        }
        memory16set(ds*16+r16[si] + 2, r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        memory[ds*16+r16[si] + 14] = 0x00;
        yield* sub_64ef();
        yield* sub_64ef();
    case 0x63be:
        return;
    } while (1);
}
function* sub_63bf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0))
        { yield* sub_63c9(); return; }
        yield* loc_5a58();
        return;
    } while (1);
}
function* sub_63c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        memory16set(ds*16+r16[si], memory16get(ds*16+r16[si]) - r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si]);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 15);
        r16[dx] = r16[ax];
        if (r16s[ax] >= 0) {
            pc = 0x63d9;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x63d9:
        if (r16[ax] <= memory16get(ds*16+r16[si] + 17)) {
            pc = 0x63f0;
            break;
        }
        r16[ax] = memory16get(ds*16+r16[si] + 8);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x63e7;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x63e7:
        flags.sign = !!(r16[dx] & 0x8000);
        r16[dx] |= r16[dx];
        if (!flags.sign) {
            pc = 0x63ed;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x63ed:
        memory16set(ds*16+r16[si] + 8, r16[ax]);
    case 0x63f0:
        return;
    } while (1);
}
function* sub_63f1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16+r16[si] + 7];
        if (!(r8[al] & 0xc0)) {
            pc = 0x63fb;
            break;
        }
        yield* loc_5a58();
        return;
    case 0x63fb:
        if (memory[ds*16+r16[si] + 5] & 0x20) {
            pc = 0x6404;
            break;
        }
        pc = 0x6495;
        break;
    case 0x6404:
        r8[al] = memory[ds*16+r16[si] + 18];
        if (!(r8[al] & 0xc0)) {
            pc = 0x6414;
            break;
        }
        r16[dx] = r16[dx] ^ r16[dx];
        if (r8[al] & 0x40) {
            pc = 0x641e;
            break;
        }
        r16[dx] -= 1;
        pc = 0x641e;
        break;
    case 0x6414:
        r16[dx] = r16[dx] ^ r16[dx];
        r16[ax] = memory16get(ds*16+0x527c);
        if (memory16gets(ds*16+r16[si]) >= r16s[ax]) {
            pc = 0x641e;
            break;
        }
        r16[dx] -= 1;
    case 0x641e:
        memory16set(ds*16+r16[si] + 8, r16[dx]);
        r8[al] = memory[ds*16+r16[si] + 14];
        r8[al] |= r8[al];
        if (r8[al] != 0) {
            pc = 0x6476;
            break;
        }
        flags.carry = memory[ds*16+r16[si] + 15] < 0x01;
        memory[ds*16+r16[si] + 15] -= 0x01;
        memory[ds*16+r16[si] + 15] = memory[ds*16 +r16[si] + 15] + 0x00 + flags.carry;
        if (memory[ds*16+r16[si] + 15] != 0) {
            pc = 0x6495;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527e);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si] + 2);
        if (r16s[ax] >= 0) {
            pc = 0x643c;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x643c:
        if (r16[ax] > 0x0018) {
            pc = 0x6495;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[ax] = r16[ax] - memory16get(ds*16+r16[si]);
        if (r16s[ax] >= 0) {
            pc = 0x644a;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x644a:
        r16[dx] = memory16get(ds*16+r16[si] + 17);
        r8[dh] &= 0x3f;
        if (r16[dx] < r16[ax]) {
            pc = 0x6495;
            break;
        }
        r8[al] = memory[ds*16+r16[si] + 18];
        rol8(al, 1);
        rol8(al, 1);
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x646d;
            break;
        }
        r16[ax] = memory16get(ds*16+0x527c);
        r16[dx] = memory16get(ds*16+r16[si]);
        if (r8[al] == 0x01) {
            pc = 0x6469;
            break;
        }
        xchg16(ax, dx);
    case 0x6469:
        if (r16s[ax] > r16s[dx]) {
            pc = 0x6495;
            break;
        }
    case 0x646d:
        memory[ds*16+r16[si] + 14] = 0x1e;
        yield* sub_64df();
        pc = 0x6495;
        break;
    case 0x6476:
        memory[ds*16+r16[si] + 14] -= 1;
        if (!(memory[ds*16+r16[si] + 7] & 0x20)) {
            pc = 0x6495;
            break;
        }
        memory16set(ds*16+r16[si] + 10, memory16get(ds*16+r16[si] + 10) + 0x0004);
        yield* sub_592d();
        if (flags.carry) {
            pc = 0x6491;
            break;
        }
        yield* sub_6496();
        r8[al] = memory[ds*16+r16[si] + 16];
        memory[ds*16+r16[si] + 15] = r8[al];
    case 0x6491:
        memory[ds*16+r16[si] + 14] = 0x00;
    case 0x6495:
        return;
    } while (1);
}
function* sub_6496() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds*16+r16[si]);
        memory16set(ds*16+r16[di], r16[ax]);
        r16[ax] = memory16get(ds*16+r16[si] + 2);
        r16[bx] = memory16get(ds*16+r16[si] + 10);
        bp = r16[bx];
        r16[bx] = memory16get(ds*16+r16[bx] + -2);
        r8[bh] = r8[bh] ^ r8[bh];
        xchg16(ax, bx);
        _cbw();
        xchg16(ax, bx);
        r16[ax] -= r16[bx];
        memory16set(ds*16+r16[di] + 2, r16[ax]);
        r16[bx] = memory16get(ds*16+bp + 4);
        r8[bh] &= 0x1f;
        r16[bx] += 0x801e;
        r16[dx] = 0x00b0;
        r16[ax] = memory16get(ds*16+0x527c);
        if (memory16gets(ds*16+r16[si]) < r16s[ax]) {
            pc = 0x64c9;
            break;
        }
        r16[dx] = -r16[dx];
        r8[bh] = r8[bh] ^ 0x80;
    case 0x64c9:
        memory16set(ds*16+r16[di] + 4, r16[bx]);
        memory16set(ds*16+r16[di] + 6, r16[dx]);
        memory16set(ds*16+r16[di] + 14, 0x0000);
        sar16(dx, 1);
        sar16(dx, 1);
        sar16(dx, 1);
        sar16(dx, 1);
        memory16set(ds*16+r16[di], memory16get(ds*16+r16[di]) + r16[dx]);
        return;
    } while (1);
}
function* sub_64df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 10);
    case 0x64e2:
        r16[bx] += 1;
        r16[bx] += 1;
        if (memory16gets(ds*16+r16[bx]) >= signed16(0x0000)) {
            pc = 0x64e2;
            break;
        }
        r16[bx] += 1;
        r16[bx] += 1;
        memory16set(ds*16+r16[si] + 10, r16[bx]);
        return;
    } while (1);
}
function* sub_64ef() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds*16+r16[si] + 10);
    case 0x64f2:
        r16[bx] -= 1;
        r16[bx] -= 1;
        if (memory16gets(ds*16+r16[bx]) >= signed16(0x0000)) {
            pc = 0x64f2;
            break;
        }
        r16[bx] -= 1;
        r16[bx] -= 1;
        memory16set(ds*16+r16[si] + 10, r16[bx]);
        return;
    } while (1);
}
function* sub_64ff() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16+r16[si] + 7] & 0xc0) {
            pc = 0x654b;
            break;
        }
        memory[ds*16+r16[si] + 7] &= 0xdf;
        r16[bx] = memory16get(ds*16+r16[si] + 10);
    case 0x650c:
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x6516;
            break;
        }
        r16[bx] += r16[ax];
        pc = 0x650c;
        break;
    case 0x6516:
        if (r16[ax] != 0x55aa) {
            pc = 0x6527;
            break;
        }
        memory16set(ds*16+r16[di] + 4, 0xffff);
        memory16set(ds*16+r16[si] + 4, 0x05aa);
    {yield* sub_655c(); return; };
    case 0x6527:
        r8[dh] = r8[ah];
        r8[dh] &= 0x20;
        r8[ah] &= 0xdf;
        memory[ds*16+r16[si] + 7] |= r8[dh];
        r8[dh] = memory[ds*16+r16[si] + 9];
        r8[dh] &= 0x80;
        r8[ah] |= r8[dh];
        memory16set(ds*16+r16[si] + 4, r16[ax]);
        r16[ax] += 0x0065;
        memory16set(ds*16+r16[di] + 4, r16[ax]);
        yield* sub_655c();
        memory16set(ds*16+r16[si] + 10, r16[bx]);
        pc = 0x6557;
        break;
    case 0x654b:
        r16[ax] = memory16get(ds*16+r16[si] + 4);
        r8[ah] &= 0xdf;
        r16[ax] += 0x0065;
        memory16set(ds*16+r16[di] + 4, r16[ax]);
    case 0x6557:
        memory[ds*16+r16[si] + 5] |= 0x20;
        return;
    } while (1);
}
function* sub_655c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] += 1;
        r16[bx] += 1;
        r16[ax] = memory16get(ds*16+r16[bx]);
        flags.sign = !!(r16[ax] & 0x8000);
        r16[ax] |= r16[ax];
        if (!flags.sign) {
            pc = 0x6566;
            break;
        }
        r16[bx] += r16[ax];
    case 0x6566:
        return;
    } while (1);
}
function* sub_6567() {
    r8[cl] = 0x04;
    r16[ax] = memory16get(ds*16+r16[si] + 2);
    r8[al] &= 0xf0;
    r16[ax] <<= r8[cl];
    r16[di] = memory16get(ds*16+r16[si]);
    r16[di] >>= r8[cl];
    r16[di] += r16[ax];
    es = memory16get(ds*16+21100);
    r8[al] = memory[es*16+r16[di]];
    r16[bx] = 0x73a3;
    _xlatds();
}
function* sub_6582() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(r16[si]);
        push(es);
        push(ds);
        r16[bx] = r16[ax];
        r16[ax] = 0xf000;
        es = r16[ax];
        r16[ax] = 0x168f;
        ds = r16[ax];
        r16[si] = 0xfff0;
        r16[ax] = bios16get(es, r16[bx]);
        r8[cl] = memory[cs*16+0x4];
        r8[al] = r8[al] + bios16get(es, r16[bx] + 61440);
        r8[ah] = r8[ah] - bios16get(es, r16[bx] + 61442);
        flags.carry = 0;
        ror16(ax, r8[cl]);
        r16[cx] = 0x0008;
    case 0x65ad:
        // std::cout << "fixme !!!!!!!!!! =========================\n";
        r16[ax] = r16[ax] + bios16get(es, r16[si]) + flags.carry;
        r16[si] += 1;
        r16[si] += 1;
        if (--r16[cx]) {
            pc = 0x65ad;
            break;
        }
        r8[cl] = r8[bl];
        rol16(ax, r8[cl]);
        ds = pop();
        es = pop();
        r16[si] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_65be() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[di]);
        push(r16[si]);
        push(ds);
        push(es);
        push(bp);
        push(r16[si]);
        memory[cs*16+0x66D9] = r8[al];
        memory[cs*16+0x66DA] = r8[ah];
        _mul8(r8[ah]);
        memory16set(cs*16+0x66DD, r16[ax]);
        r16[ax] = 0x168f;
        es = r16[ax];
        r16[ax] = memory16get(es*16+1217);
        r16[ax] += 0x07d1;
        es = r16[ax];
        r16[di] = r16[di] ^ r16[di];
        bp = bp ^ bp;
    case 0x65e9:
        r8[al] = memory[cs*16+0x66DA];
        memory[cs*16+0x66D8] = r8[al];
    case 0x65f1:
        r16[bx] = memory16get(cs*16+0x66DD);
        r8[ah] = memory[ds*16+r16[bx] + r16[si]];
        r16[dx] = r16[dx] ^ r16[dx];
        memory16set(cs*16+0x66DB, r16[dx]);
        if (memory[cs*16+0x66DF] != r8[dl]) {
            pc = 0x6611;
            break;
        }
        r16[bx] <<= 1;
        r8[dl] = memory[ds*16+r16[bx] + r16[si]];
        r16[bx] = r16[bx] + memory16get(cs*16+0x66DD);
        r8[dh] = memory[ds*16+r16[bx] + r16[si]];
    case 0x6611:
        lodsb_data_forward();
        r16[cx] = 0x0008;
    case 0x6615:
        r16[bx] = r16[bx] ^ r16[bx];
        flags.carry = !!(r8[dh] & 0x80);
        r8[dh] <<= 1;
        _rcl16(bx, 1);
        flags.carry = !!(r8[dl] & 0x80);
        r8[dl] <<= 1;
        _rcl16(bx, 1);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        _rcl16(bx, 1);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        _rcl16(bx, 1);
        r16[bx] <<= 1;
        r16[bx] += bp;
        r16[bx] = r16[bx] + memory16get(cs*16+0x6676);
        r8[bl] = memory[cs*16+r16[bx]];
        bp = bp ^ 0x0001;
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        _rclm16(cs*16+0x66DB, 1);
        flags.carry = !!(r8[bl] & 0x80);
        r8[bl] <<= 1;
        _rclm16(cs*16+0x66DB, 1);
        if (--r16[cx]) {
            pc = 0x6615;
            break;
        }
        r16[ax] = memory16get(cs*16+0x66DB);
        xchg8(ah, al);
        stosw_data_forward();
        memory[cs*16+0x66D8] -= 1;
        if (memory[cs*16+0x66D8] != 0) {
            pc = 0x65f1;
            break;
        }
        bp = bp ^ 0x0001;
        memory[cs*16+0x66D9] -= 1;
        if (memory[cs*16+0x66D9] != 0) {
            pc = 0x65e9;
            break;
        }
        r16[di] = pop();
        r16[si] = r16[si] ^ r16[si];
        push(ds);
        push(es);
        ds = pop();
        es = pop();
        r16[cx] = memory16get(cs*16+0x66DD);
        rep_movsw_data_data_forward();
        bp = pop();
        es = pop();
        ds = pop();
        r16[si] = pop();
        r16[di] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db ffh");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db ffh");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db 00h");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db aah");
        _STOP_("db ffh");
        _STOP_("db 55h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db 55h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db c0h");
        _STOP_("db 00h");
        _STOP_("db 00h");
        _STOP_("db c0h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        _STOP_("db 80h");
        return;
    } while (1);
}