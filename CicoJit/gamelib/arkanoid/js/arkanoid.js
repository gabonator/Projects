var arkanoidLevel = 0;
var arkanoidSide = 0;
var arkanoidSkipIntro = false;

function* start() {
    headerSize = 0x00c0;
    loadAddress = 0x10df;
    cs = 0x1b0c;
    ds = 0x1afc;
    es = 0x1afc;
    ss = 0x10df;
    sp = 0x0190;
    overlay("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/arkanoid/dos", "REVOFDOH.DAT", 86544, 0x1b0c, -0xa390+headerSize*0);
    overlay("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/arkanoid/dos", "MEMDUMP.BIN", 0x100, 0x4dd, 0x0000);
    yield* sub_1b0c0(false);
}
function* jumpIndirect(seg, ofs) { 
  cs = seg;
  yield *callIndirect(seg, ofs); 
}
function* callIndirect(seg, ofs) {
    if(seg == 0x1b0c)
        switch (ofs)
    {
    case 0x4d7b: yield* sub_1fe3b(); return;
    case 0x4aa0: yield* sub_1fb60(); return;
    case 0x4ae3: yield* sub_1fba3(); return;
    case 0x4b5c: yield* sub_1fc1c(); return;
    case 0x4c62: yield* sub_1fd22(); return;
    case 0x4c8b: yield* sub_1fd4b(); return;
    case 0x4cfe: yield* sub_1fdbe(); return;
    case 0x4ce3: yield* sub_1fda3(); return;
    case 0x4d7c: yield* sub_1fe3c(); return;
    case 0x4dec: yield* sub_1feac(); return;
    case 0x4dde: yield* sub_1fe9e(); return;
    case 0x4e91: yield* sub_1ff51(); return;
    case 0x4fb0: yield* sub_20070(); return;
    case 0x4fd3: yield* sub_20093(); return;
    case 0x4b2b: yield* sub_1fbeb(); return;
    case 0x4b3e: yield* sub_1fbfe(); return;
    case 0x5053: yield* sub_20113(); return;
    case 0x4b7e: yield* sub_1fc3e(); return;
    case 0x4bce: yield* sub_1fc8e(); return;
    case 0x50b3: yield* sub_20173(); return;
        default:
        break;
    }
    if(seg == 0x1b0c)
        switch (ofs)
    {
    case 0x173c: yield* sub_1c7fc(); return;
    case 0x1771: yield* sub_1c831(); return;
    case 0x1789: yield* sub_1c849(); return;
    case 0x178f: yield* sub_1c84f(); return;
    case 0x1795: yield* sub_1c855(); return;
    case 0x179b: yield* sub_1c85b(); return;
    case 0x17a1: yield* sub_1c861(); return;
    case 0x2c1a: yield* sub_1dcda(); return;
    case 0x2edd: yield* sub_1df9d(); return;
    case 0x1783: yield* sub_1c843(); return;
    case 0x31a6: yield* sub_1e266(); return;
    case 0x321e: yield* sub_1e2de(); return;
    case 0x1bd5: yield* sub_1cc95(); return;
    case 0x2615: yield* sub_1d6d5(); return;
    case 0x1bf5: yield* sub_1ccb5(); return;
    case 0x1b93: yield* sub_1cc53(); return;
    case 0x1b13: yield* sub_1cbd3(); return;
    case 0x1c18: yield* sub_1ccd8(); return;
    case 0x1b71: yield* sub_1cc31(); return;
    case 0x1d13: yield* sub_1cdd3(); return;
    case 0x1acf: yield* sub_1cb8f(); return;
    case 0x1d3a: yield* sub_1cdfa(); return;
    case 0x253a: yield* sub_1d5fa(); return;
    case 0x257f: yield* sub_1d63f(); return;
    case 0x3151: yield* sub_1e211(); return;
    case 0x3139: yield* sub_1e1f9(); return;
    case 0x1a07: yield* sub_1cac7(); return;
    case 0x1c1c: yield* sub_1ccdc(); return;
    case 0x1a62: yield* sub_1cb22(); return;
    case 0x25ed: yield* sub_1d6ad(); return;
        default:
        break;
    }
    if(seg == 0x1b0c)
        switch (ofs)
    {
    case 0x173c: yield* sub_1c7fc(); return;
    case 0x2646: yield* sub_1d706(); return;
    case 0x2c3e: yield* sub_1dcfe(); return;
    case 0x2c14: yield* sub_1dcd4(); return;
    case 0x1a5d: yield* sub_1cb1d(); return;
    case 0x1ac3: yield* sub_1cb83(); return;
    case 0x2b2f: yield* sub_1dbef(); return;
        default:
        break;
    }
    if(seg == 0x1b0c)
        switch (ofs)
    {
    case 0x173c: yield* sub_1c7fc(); return;
    case 0x31a6: yield* sub_1e266(); return;
    case 0x321e: yield* sub_1e2de(); return;
    case 0x1bd5: yield* sub_1cc95(); return;
    case 0x2615: yield* sub_1d6d5(); return;
    case 0x1bf5: yield* sub_1ccb5(); return;
    case 0x1b93: yield* sub_1cc53(); return;
    case 0x1b13: yield* sub_1cbd3(); return;
    case 0x1c18: yield* sub_1ccd8(); return;
    case 0x1b71: yield* sub_1cc31(); return;
    case 0x1d13: yield* sub_1cdd3(); return;
    case 0x1acf: yield* sub_1cb8f(); return;
    case 0x1d3a: yield* sub_1cdfa(); return;
    case 0x253a: yield* sub_1d5fa(); return;
    case 0x257f: yield* sub_1d63f(); return;
    case 0x3151: yield* sub_1e211(); return;
    case 0x3139: yield* sub_1e1f9(); return;
    case 0x1a07: yield* sub_1cac7(); return;
    case 0x1c1c: yield* sub_1ccdc(); return;
    case 0x1a62: yield* sub_1cb22(); return;
    case 0x25ed: yield* sub_1d6ad(); return;
    case 0x2646: yield* sub_1d706(); return;
    case 0x2c3e: yield* sub_1dcfe(); return;
    case 0x2c14: yield* sub_1dcd4(); return;
    case 0x1a5d: yield* sub_1cb1d(); return;
    case 0x1ac3: yield* sub_1cb83(); return;
    case 0x2b2f: yield* sub_1dbef(); return;
    case 0x0: assert(0); /*yield* sub_1b0c0(false);*/ return;
        default:
        break;
    }
    switch (seg*0x10000+ofs)
    {
    case 0x19ee02f7: yield* sub_1a1d7(); return;
    case 0x19ee0418: yield* sub_1a2f8(); return;
    case 0x19ee0450: yield* sub_1a330(); return;
    case 0x19ee095d: yield* sub_1a83d(); return;
    case 0x19ee0a09: yield* sub_1a8e9(); return;
    case 0x19ee0b84: yield* sub_1aa64(); return;
    case 0x19ee0c92: yield* sub_1ab72(); return;
    case 0x1b0c1135: yield* sub_1c1f5(); return;
    case 0x1b0c4069: yield* sub_1f129(); return;
    case 0x1b0c4221: yield* sub_1f2e1(); return;
    case 0x1b0c42a4: yield* sub_1f364(); return;
    case 0x1b0c42af: yield* sub_1f36f(); return;
    case 0x1b0c43f3: yield* sub_1f4b3(); return;
    case 0x1b0c4efb: yield* sub_1ffbb(); return;
    case 0x1b0c4f2c: yield* sub_1ffec(); return;
    case 0x1b0c4f43: yield* sub_20003(); return;
        default:
        break;
    }
    assert(0);
}
function* sub_1a1d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[bx]);
        push(si);
        push(ds);
        push(cs);
        ds = pop();
        si = 0x0000;
        r16[cx] = 0x0009;
        flags.interrupts = false;
        memory16set(ds, 0x029e, 0x0000);
    case 0x1a1ea:
        memory16set(ds, si + 278, 0x0000);
        memory16set(ds, si + 296, 0x0000);
        memory16set(ds, si + 224, 0x0000);
        memory16set(ds, si + 332, 0x0000);
        memory16set(ds, si + 242, 0x0000);
        memory16set(ds, si + 368, 0x0000);
        memory16set(ds, si + 260, 0x0000);
        memory16set(ds, si + 386, 0x0000);
        yield* sub_1aa1a();
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x1a1ea;
            break;
        }
        memory[ds*16 + 0x02f6] = 0x00;
        flags.interrupts = true;
        ds = pop();
        si = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_1a2f8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(si);
        push(ds);
        push(cs);
        ds = pop();
        si = 0x0000;
        r16[cx] = 0x0009;
        flags.interrupts = false;
    case 0x1a306:
        push(r16[ax]);
        if (memory[ds*16 + si + 333] & 0x02) {
            pc = 0x1a323;
            break;
        }
        if (r8[al] != memory[ds*16 + si + 332]) {
            pc = 0x1a323;
            break;
        }
        memory[ds*16 + si + 333] = memory[ds*16 + si + 333] | 0x02;
        r16[bx] = memory16get(ds, 0x0000);
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 20));
        yield* sub_1aa1a();
    case 0x1a323:
        r16[ax] = pop();
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x1a306;
            break;
        }
        flags.interrupts = true;
        ds = pop();
        si = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_1a330() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(si);
        push(ds);
        push(cs);
        ds = pop();
        si = 0x0000;
        r16[cx] = 0x0009;
        flags.interrupts = false;
    case 0x1a33e:
        push(r16[ax]);
        if (!(memory[ds*16 + si + 333] & 0x02)) {
            pc = 0x1a35b;
            break;
        }
        if (r8[al] != memory[ds*16 + si + 332]) {
            pc = 0x1a35b;
            break;
        }
        memory[ds*16 + si + 333] = memory[ds*16 + si + 333] & 0xfd;
        yield* sub_1aa2a();
        r16[bx] = memory16get(ds, 0x0000);
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 36));
    case 0x1a35b:
        r16[ax] = pop();
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x1a33e;
            break;
        }
        flags.interrupts = true;
        ds = pop();
        si = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_1a83d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(si);
        push(ds);
        push(cs);
        ds = pop();
        si = 0x0000;
        r16[cx] = 0x0009;
        r16[bx] = 0;
    case 0x1a84b:
        if (r8[al] != memory[ds*16 + si + 332]) {
            pc = 0x1a855;
            break;
        }
        r16[bx] |= memory16get(ds, si + 278);
    case 0x1a855:
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x1a84b;
            break;
        }
        ds = pop();
        si = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        cs = pop();
        flags.zero = true;
        return;
    } while (1);
}
function* sub_1a861() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(ds);
    push(cs);
    ds = pop();
    memory16set(ds, 0x00d4, r16[ax]);
    memory[ds*16 + 0x02f5] = 0x00;
    memory[ds*16 + 0x02f6] = 0x00;
    r16[bx] = r16[cx];
    r16[bx] = memory16get(ds, r16[bx] + 2);
    memory16set(ds, 0x0000, r16[bx]);
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 34));
    push(cs);
    cs = 0x19ee;
    yield* sub_1a1d7();
    assert(cs == 0x19ee);
    ds = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    cs = pop();
}
function* sub_1a8e9() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(bp);
    push(ds);
    push(es);
    push(cs);
    ds = pop();
    yield* sub_1a905();
    memory[ds*16 + 0x02f6] = 0x00;
    flags.interrupts = true;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    cs = pop();
}
function* sub_1a905() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0;
        bp = 0x0000;
        r16[cx] = r16[ax];
        flags.interrupts = false;
        es = memory16get(ds, 0x00d4);
        r16[cx]++;
    case 0x1a912:
        r16[bx] = memory16get(es, bp);
        memory16set(ds, 0x00d6, bp);
        if (--r16[cx]) {
            pc = 0x1a93e;
            break;
        }
        if (!r16[bx])
            return;
        r16[bx] = memory16get(es, bp + 8);
        memory16set(ds, 0x00de, r16[bx]);
        r16[bx] = memory16get(es, bp + 4);
        r16[bx] += bp;
        memory16set(ds, 0x00da, r16[bx]);
        r16[bx] = memory16get(es, bp + 2);
        r16[bx] += bp;
        memory16set(ds, 0x00d8, r16[bx]);
        pc = 0x1a942;
        break;
    case 0x1a93e:
        bp += r16[bx];
        pc = 0x1a912;
        break;
    case 0x1a942:
        r16[dx] = bp;
        bp = r16[bx];
        si = 0x0000;
        r16[cx] = 0x0009;
        r16[bx] = r16[ax];
    case 0x1a94e:
        r16[ax] = memory16get(es, bp + si);
        if (!r16[ax]) {
            pc = 0x1a970;
            break;
        }
        r16[ax] += r16[dx];
        memory16set(ds, si + 278, r16[ax]);
        memory16set(ds, si + 296, r16[ax]);
        memory16set(ds, si + 224, 0x0001);
        memory16set(ds, si + 332, r16[bx]);
        r16[ax] = memory16get(ds, 0x00da);
        memory16set(ds, si + 350, r16[ax]);
    case 0x1a970:
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x1a94e;
            break;
        }
        return;
    } while (1);
}
function* sub_1aa1a() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    r16[bx] = memory16get(ds, 0x0000);
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 30));
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1aa2a() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    r16[bx] = memory16get(ds, 0x0000);
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 32));
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1aa3a() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    r16[dx] = 0x0388;
    out8(r16[dx], r8[al]);
    yield* sub_1aa52();
    r8[al] = r8[ah];
    r16[dx]++;
    out8(r16[dx], r8[al]);
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1aa52() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = 0x0388;
        r16[cx] = 0x0006;
    case 0x1aa5b:
        r8[al] = in8(r16[dx]);
        if (--r16[cx]) {
            pc = 0x1aa5b;
            break;
        }
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1aa64() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x2001;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[ax] = 0x0004;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[ax] = 0x8004;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[ax] = 0x4008;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[ax] = 0x00bd;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[cx] = 0x0012;
        r8[ah] = 0x3f;
    case 0x1aa96:
        r16[bx] = r16[cx];
        r8[al] = memory[ds*16 + r16[bx] + 727];
        r8[al] += 0x40;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        if (--r16[cx]) {
            pc = 0x1aa96;
            break;
        }
        r16[cx] = 0x0009;
        r8[ah] = 0;
    case 0x1aaab:
        r8[al] = r8[cl];
        r8[al]--;
        push(r16[ax]);
        r8[al] += 0xb0;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        r16[ax] = pop();
        r8[al] += 0xa0;
        yield* sub_1aa3a();
        yield* sub_1aac4();
        if (--r16[cx]) {
            pc = 0x1aaab;
            break;
        }
        return;
    } while (1);
}
function* sub_1aac4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = 0x0006;
    case 0x1aac8:
        yield* sub_1aa52();
        if (--r16[cx]) {
            pc = 0x1aac8;
            break;
        }
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_1ab72() {
    r16[ax] = si;
    r8[al] >>= 1;
    memory[ds*16 + si + 405] = memory[ds*16 + si + 405] & 0xdf;
    r8[ah] = memory[ds*16 + si + 405];
    r8[al] += 0xb0;
    yield* sub_1aa3a();
    yield* sub_1aac4();
}
function* sub_1b060() {
    push(r16[cx]);
    r16[cx] = 0x0000;
    push(cs);
    cs = 0x19ee;
    yield* sub_1a861();
    assert(cs == 0x19ee);
    r16[cx] = pop();
    cs = pop();
}
function* sub_1b06b() {
    cs = 0x19ee;
    yield* callIndirect(0x19ee, 0x0a09);
}
function* sub_1b07f() {
    cs = 0x19ee;
    yield* callIndirect(0x19ee, 0x02f7);
}
function* sub_1b08e() {
    cs = 0x19ee;
    yield* callIndirect(0x19ee, 0x095d);
}
function* sub_1b0b1() {
    cs = 0x19ee;
    yield* callIndirect(0x19ee, 0x0418);
}
function* sub_1b0b6() {
    cs = 0x19ee;
    yield* callIndirect(0x19ee, 0x0450);
}
function* sub_1b0c0(resume) {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (resume)
	{
            pc = 1;
            break;
            //goto resumelabel;
	}
        r16[ax] = 0x1118;
        ds = r16[ax];
        yield* sub_1b994();
        yield* sub_1b43e();
        yield* sub_1c38c();
        yield* sub_1c178();
        yield* sub_1f87a();
        yield* sub_1f158();
        yield* sub_1f320(false);
    case 1:
        yield* sub_1f072();
    case 0x1b0dd:
        yield* sub_1ba4f();
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al]) {
            pc = 0x1b10f;
            break;
        }
        yield* sub_1baf1();
        if (!arkanoidSkipIntro)
            yield* sub_1bb74();
        yield* sub_1b970();
        yield* sub_1bcf0();
        yield* sub_1b1aa();
        if (!(r8[ah] & 0x01)) {
            pc = 0x1b100;
            break;
        }
        r8[bl] = 0x31;
        yield* sub_1b1d9();
    case 0x1b100:
        if (!(r8[ah] & 0x02)) {
            pc = 0x1b10a;
            break;
        }
        r8[bl] = 0x32;
        yield* sub_1b1d9();
    case 0x1b10a:
        yield* sub_1b29e();
        pc = 0x1b0dd;
        break;
    case 0x1b10f:
        r8[al] = 0;
        memory[ds*16 + 0x0493] = r8[al];
        memory[ds*16 + 0x0494] = r8[al];
        memory[ds*16 + 0x0a4d] = 0x01;
        yield* sub_1b4f0();
        pc = 0x1b0dd;
        break;
        return;
    } while (1);
}
function* sub_1b130() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48d3] == 0x00) {
            pc = 0x1b141;
            break;
        }
        flags.carry = (r8[al] + r8[al]) >= 0x100;
        r8[al] += r8[al];
        daa();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        r8[tl] = flags.carry;
        flags.carry = (r8[al] + r8[al] + r8[tl]) >= 0x100;
        r8[al] += r8[al] + r8[tl];
        daa();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
    case 0x1b141:
        yield* sub_1b14b();
        push(si);
        yield* sub_1b160();
        si = pop();
        pc = 0x1b185;
        break;
    case 0x1b185:
        r16[ax] = memory16get(ds, 0x049c);
        if (r8[al] > memory[ds*16 + r16[bx]])
            return;
        if (r8[ah] > memory[ds*16 + r16[bx] + 1])
            return;
        r8[al] = memory[ds*16 + 0x049e];
        if (r8[al] > memory[ds*16 + r16[bx] + 3])
            return;
        r16[bx] += 0x0003;
        r16[ax] = 0x5000;
        r16[bx] = 0x049f;
        flags.carry = false;
        yield* sub_1b14f();
        yield* sub_1dbe2();
        return;
    } while (1);
}
function* sub_1b14b() {
    r16[bx] = 0x0493;
    flags.carry = false;
    yield* sub_1b159();
    r8[al] = r8[ah];
    yield* sub_1b159();
    r8[al] = 0x00;
    flags.carry = r16[bx] == 0;
    r16[bx]--;
    r8[tl] = flags.carry;
    flags.carry = (r8[al] + memory[ds*16 + r16[bx]] + r8[tl]) >= 0x100;
    r8[al] += memory[ds*16 + r16[bx]] + r8[tl];
    daa();
    memory[ds*16 + r16[bx]] = r8[al];
}
function* sub_1b14f() {
    yield* sub_1b159();
    r8[al] = r8[ah];
    yield* sub_1b159();
    r8[al] = 0x00;
    flags.carry = r16[bx] == 0;
    r16[bx]--;
    r8[tl] = flags.carry;
    flags.carry = (r8[al] + memory[ds*16 + r16[bx]] + r8[tl]) >= 0x100;
    r8[al] += memory[ds*16 + r16[bx]] + r8[tl];
    daa();
    memory[ds*16 + r16[bx]] = r8[al];
}
function* sub_1b159() {
    flags.carry = r16[bx] == 0;
    r16[bx]--;
    r8[tl] = flags.carry;
    flags.carry = (r8[al] + memory[ds*16 + r16[bx]] + r8[tl]) >= 0x100;
    r8[al] += memory[ds*16 + r16[bx]] + r8[tl];
    daa();
    memory[ds*16 + r16[bx]] = r8[al];
}
function* sub_1b160() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0490;
        si = 0x0a46;
        push(si);
        push(r16[bx]);
        yield* sub_1b1c6();
        r16[bx] = pop();
        si = pop();
        if (!flags.carry) {
            pc = 0x1b17f;
            break;
        }
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si, r16[ax]);
        r8[al] = memory[ds*16 + r16[bx] + 2];
        memory[ds*16 + si + 2] = r8[al];
        memory[ds*16 + 0x002e] = 0x01;
        return;
    case 0x1b17f:
        memory[ds*16 + 0x002e] = 0x00;
        return;
    } while (1);
}
function* sub_1b1aa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0;
        r16[bx] = 0x0680;
        yield* sub_1b1c3();
        if (!flags.carry) {
            pc = 0x1b1b7;
            break;
        }
        r8[ah] |= 0x01;
    case 0x1b1b7:
        r16[bx] = 0x0863;
        yield* sub_1b1c3();
        if (!flags.carry)
            return;
        r8[ah] |= 0x02;
        return;
    } while (1);
}
function* sub_1b1c3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x00c2;
        r16[cx] = 0x0003;
    case 0x1b1c9:
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] > memory[ds*16 + si]) {
            pc = 0x1b1d7;
            break;
        }
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        si++;
        r16[bx]++;
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        stop(/*e2*/);
        pc = 0x1b1c9;
        break;
        flags.carry = false;
        return;
    case 0x1b1d7:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1b1c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0003;
    case 0x1b1c9:
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] > memory[ds*16 + si]) {
            pc = 0x1b1d7;
            break;
        }
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        si++;
        r16[bx]++;
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        pc = 0x1b1c9;
        break;
        flags.carry = false;
        return;
    case 0x1b1d7:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1b1d9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        memory[cs*16 + 0x03c7] = 0x00;
        memory[ds*16 + 0x004b] = r8[bl];
        yield* sub_1b23c();
        if (flags.carry) {
            pc = 0x1b204;
            break;
        }
        r8[al] = 0x01;
        yield* sub_1b2b8();
        r16[bx] = 0x0109;
        if (r8[cl] != 0x06) {
            pc = 0x1b1f9;
            break;
        }
        r8[bl] = 0x0d;
    case 0x1b1f9:
        yield* sub_1f0d2();
        yield* sub_1b382();
        memory[ds*16 + 0x0004] = 0x01;
    case 0x1b204:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1b206() {
    if (memory[ds*16 + 0x0004] != 0x01)
        return;
    memory[ds*16 + 0x0004] = 0x00;
    r8[al] = 0x03;
    yield* sub_1f2dc();
    yield* sub_1f042();
    yield* sub_1b22b();
    yield* sub_1f83b();
    memory[cs*16 + 0x03c7] = 0x00;
    yield* sub_1f072();
}
function* sub_1b22b() {
    r16[dx] = 0x0068;
    yield* sub_1b41a();
    if (flags.carry)
        return;
    yield* sub_1b426();
    if (flags.carry)
        return;
    yield* sub_1b439();
}
function* sub_1b23c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0680;
        if (r8[bl] == 0x31) {
            pc = 0x1b247;
            break;
        }
        r16[bx] = 0x0863;
    case 0x1b247:
        r16[cx] = 0x0006;
        r16[dx] = 0x0041;
        si = 0x0081;
    case 0x1b250:
        push(r16[cx]);
        push(r16[bx]);
        push(si);
        yield* sub_1b1c6();
        si = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        if (flags.carry) {
            pc = 0x1b265;
            break;
        }
        r16[dx] -= 0x000d;
        si += 0x000d;
        if (--r16[cx]) {
            pc = 0x1b250;
            break;
        }
        flags.carry = true;
        return;
    case 0x1b265:
        push(r16[cx]);
        si -= 0x0009;
        if (!r16[dx]) {
            pc = 0x1b280;
            break;
        }
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[cx] = r16[dx];
        si = 0x00b8;
        di = 0x00c5;
        flags.direction = true;
        rep_movsb_data_data_forward();
        flags.direction = false;
        es = pop();
        si++;
    case 0x1b280:
        r8[al] = 0x20;
        r16[cx] = 0x0008;
        push(si);
    case 0x1b286:
        memory[ds*16 + si] = r8[al];
        si++;
        if (--r16[cx]) {
            pc = 0x1b286;
            break;
        }
        si++;
        r16[cx] = 0x0004;
    case 0x1b28f:
        r8[al] = memory[ds*16 + r16[bx]];
        memory[ds*16 + si] = r8[al];
        r16[bx]++;
        si++;
        if (--r16[cx]) {
            pc = 0x1b28f;
            break;
        }
        si--;
        memory[ds*16 + si] += 1;
        si = pop();
        r16[cx] = pop();
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1b29e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0;
        yield* sub_1b2b8();
        r16[cx] = 0x04b0;
    case 0x1b2a6:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl]) {
            pc = 0x1b2b4;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1b2a6;
            break;
        }
    case 0x1b2b4:
        yield* sub_1b206();
        return;
    } while (1);
}
function* sub_1b2b8() {
    push(si);
    push(r16[cx]);
    push(r16[ax]);
    yield* sub_1fb33();
    r16[bx] = 0x000a;
    r16[cx] = 0x0080;
    r16[dx] = 0x008c;
    yield* sub_1fb52();
    r16[bx] = 0x0007;
    r16[cx] = 0x0020;
    r16[dx] = 0x0005;
    yield* sub_1fb52();
    yield* sub_1b308();
    r16[ax] = pop();
    yield* sub_1b2e6();
    yield* sub_1fb2b();
    yield* sub_1fb33();
    r16[cx] = pop();
    si = pop();
}
function* sub_1b2e6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!r8[al]) {
            pc = 0x1b2f9;
            break;
        }
        si = 0x0044;
        r16[bx] = 0x0010;
        r16[cx] = 0x0044;
        r8[al] = 0x0f;
        yield* sub_1fb75();
        return;
    case 0x1b2f9:
        si = 0x002f;
        r16[bx] = 0x0050;
        r16[cx] = 0x0044;
        r8[al] = 0x0f;
        yield* sub_1fb75();
        return;
    } while (1);
}
function* sub_1b308() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0078;
        r16[cx] = 0x0050;
        r16[ax] = 0x060f;
    case 0x1b311:
        push(r16[ax]);
        push(r16[cx]);
        push(si);
        r16[bx] = 0x0040;
        yield* sub_1fb75();
        si = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        si += 0x000d;
        r16[cx] += 0x0009;
        r8[ah]--;
        if (r8[ah] != 0) {
            pc = 0x1b311;
            break;
        }
        di = 0x0081;
        r16[dx] = 0x0050;
        r16[cx] = 0x0006;
    case 0x1b330:
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        r16[ax] = memory16get(ds, di + 1);
        r8[cl] = memory[ds*16 + di];
        yield* sub_1da36();
        r8[al] = 0x0f;
        si = 0x495d;
        r16[bx] = 0x0088;
        r16[cx] = r16[dx];
        yield* sub_1fb75();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        di += 0x000d;
        r16[dx] += 0x0009;
        if (--r16[cx]) {
            pc = 0x1b330;
            break;
        }
        di = 0x0084;
        r16[dx] = 0x0050;
        r16[cx] = 0x0006;
        memory[ds*16 + 0x495f] = 0x00;
    case 0x1b361:
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        r8[al] = memory[ds*16 + di];
        yield* sub_1b3f3();
        r8[al] = 0x0f;
        si = 0x495d;
        r16[bx] = 0x00d0;
        r16[cx] = r16[dx];
        yield* sub_1fb75();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        di += 0x000d;
        r16[dx] += 0x0009;
        if (--r16[cx]) {
            pc = 0x1b361;
            break;
        }
        return;
    } while (1);
}
function* sub_1b382() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = si;
        r16[dx] = si;
        r16[dx] += 0x0007;
        r8[ch] = 0x06;
        r8[ch] -= r8[cl];
        r8[al] = 0x09;
        mul8(r8[ch]);
        r16[ax] += 0x0050;
        r16[cx] = r16[ax];
        memory[ds*16 + di] = 0x2a;
        memory[cs*16 + 0x0303] = 0x00;
        bp = 0x0040;
    case 0x1b3a2:
        push(si);
        push(r16[cx]);
        push(di);
        push(r16[dx]);
        push(bp);
        r8[al] = 0x0d;
        r16[bx] = bp;
        yield* sub_1fb75();
        yield* sub_1c413();
        bp = pop();
        r16[dx] = pop();
        di = pop();
        r16[cx] = pop();
        si = pop();
        if (r8[al] == 0x09) {
            pc = 0x1b3d2;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0x1b3dd;
            break;
        }
        if (r8[al] == 0x1b) {
            pc = 0x1b3e7;
            break;
        }
        if (r8[al] == 0x2e) {
            pc = 0x1b3ec;
            break;
        }
        memory[ds*16 + di] = r8[al];
        if (di == r16[dx]) {
            pc = 0x1b3ec;
            break;
        }
        di++;
        memory[ds*16 + di] = 0x2a;
        pc = 0x1b3a2;
        break;
    case 0x1b3d2:
        if (di == si) {
            pc = 0x1b3a2;
            break;
        }
        di--;
        memory16set(ds, di, 0x202a);
        pc = 0x1b3a2;
        break;
    case 0x1b3dd:
        if (memory[ds*16 + di] != 0x2a) {
            pc = 0x1b3e5;
            break;
        }
        memory[ds*16 + di] = 0x20;
    case 0x1b3e5:
        flags.carry = false;
        return;
    case 0x1b3e7:
        yield* sub_1b3dd();
        flags.carry = true;
        return;
    case 0x1b3ec:
        push(r16[dx]);
        yield* sub_1f293();
        r16[dx] = pop();
        pc = 0x1b3a2;
        break;
        return;
    } while (1);
}
function* sub_1b3dd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + di] != 0x2a) {
            pc = 0x1b3e5;
            break;
        }
        memory[ds*16 + di] = 0x20;
    case 0x1b3e5:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1b3f3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = 0x2f;
    case 0x1b3f5:
        r8[bl]++;
        r8[tl] = r8[al];
        r8[al] -= 0x0a;
        if (r8s[tl] - signed8(0x0a) >= 0) {
            pc = 0x1b3f5;
            break;
        }
        r8[al] += 0x0a;
        if (r8[bl] != 0x30) {
            pc = 0x1b404;
            break;
        }
        r8[bl] = 0x20;
    case 0x1b404:
        memory[ds*16 + 0x495d] = r8[bl];
        r8[al] += 0x30;
        memory[ds*16 + 0x495e] = r8[al];
        return;
    } while (1);
}
function* sub_1b41a() {
    yield* sub_1b488();
    r8[cl] = 0x00;
    r8[ah] = 0x3c;
    interrupt(0x21);
    r16[bx] = r16[ax];
    stop(/*inject ret*/);
}
function* sub_1b426() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x40;
        r16[dx] = 0x0078;
        r16[cx] = 0x004e;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x1b438;
            break;
        }
        if (r16[ax] == 0x004e) {
            pc = 0x1b438;
            break;
        }
        flags.carry = true;
    case 0x1b438:
        stop(/*inject ret*/);
        return;
    } while (1);
}
function* sub_1b439() {
    r8[ah] = 0x3e;
    interrupt(0x21);
}
function* sub_1b43e() {
    push(ds);
    r16[ax] = 0x3524;
    interrupt(0x21);
    memory16set(ds, 0x0000, r16[bx]);
    memory16set(ds, 0x0002, es);
    r16[ax] = cs;
    ds = r16[ax];
    r16[dx] = 0x03bb;
    r16[ax] = 0x2524;
    interrupt(0x21);
    ds = pop();
}
function* sub_1b45a() {
    r16[ax] = memory16get(ds, 0x0000);
    r16[ax] |= memory16get(ds, 0x0002);
    if (!r16[ax])
        return;
    push(ds);
    r16[dx] = memory16get(ds, 0x0000);
    ds = memory16get(ds, 0x0002);
    r16[ax] = 0x2524;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0;
    memory16set(ds, 0x0000, r16[ax]);
    memory16set(ds, 0x0002, r16[ax]);
}
function* sub_1b488() {
    yield* sub_1b4ac();
    if (!flags.carry)
        return;
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(di);
    r16[bx] = 0x0000;
    r16[cx] = 0x00c0;
    r8[al] = 0x0f;
    si = 0x0005;
    yield* sub_1fb75();
    yield* sub_1f293();
    yield* sub_1c413();
    di = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
}
function* sub_1b4ac() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(es);
        interrupt(0x11);
        r8[al] &= 0xc0;
        if (r8[al] != 0) {
            pc = 0x1b4ec;
            break;
        }
        r16[bx] = r16[dx];
        r16[bx]--;
    case 0x1b4b7:
        r16[bx]++;
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0x3a) {
            pc = 0x1b4c8;
            break;
        }
        if (r8[al]) {
            pc = 0x1b4b7;
            break;
        }
        r8[ah] = 0x19;
        interrupt(0x21);
        pc = 0x1b4d1;
        break;
    case 0x1b4c8:
        if (r16[bx] == r16[dx]) {
            pc = 0x1b4ec;
            break;
        }
        r8[al] = memory[ds*16 + r16[bx] + 65535];
        r8[al] -= 0x41;
    case 0x1b4d1:
        if (r8[al] >= 0x02) {
            pc = 0x1b4ec;
            break;
        }
        r16[bx] = 0;
        es = r16[bx];
        if (memory[es*16 + 0x0504] == r8[al]) {
            pc = 0x1b4ec;
            break;
        }
        memory[es*16 + 0x0504] = r8[al];
        r8[al] += 0x41;
        memory[ds*16 + 0x0011] = r8[al];
        flags.carry = true;
        pc = 0x1b4ed;
        break;
    case 0x1b4ec:
        flags.carry = false;
    case 0x1b4ed:
        es = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1b4f0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1b4f0;
        break;
    case 0x1b0dd:
        yield* sub_1ba4f();
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al]) {
            pc = 0x1b10f;
            break;
        }
        yield* sub_1baf1();
        yield* sub_1bb74();
    case 0x1b0ed:
        yield* sub_1b970();
        yield* sub_1bcf0();
        yield* sub_1b1aa();
        if (!(r8[ah] & 0x01)) {
            pc = 0x1b100;
            break;
        }
        r8[bl] = 0x31;
        yield* sub_1b1d9();
    case 0x1b100:
        if (!(r8[ah] & 0x02)) {
            pc = 0x1b10a;
            break;
        }
        r8[bl] = 0x32;
        yield* sub_1b1d9();
    case 0x1b10a:
        yield* sub_1b29e();
        pc = 0x1b0dd;
        break;
    case 0x1b10f:
        r8[al] = 0;
        memory[ds*16 + 0x0493] = r8[al];
        memory[ds*16 + 0x0494] = r8[al];
        memory[ds*16 + 0x0a4d] = 0x01;
        yield* sub_1b4f0();
        pc = 0x1b0dd;
        break;
    case 0x1b4f0:
        r16[bx] = 0x0000;
        yield* sub_1f0d2();
        yield* sub_1f2dc();
        r8[al] = memory[ds*16 + 0x0493];
        if (r8[al] == 0x10) {
            pc = 0x1b504;
            break;
        }
        if (r8[al] != 0x21) {
            pc = 0x1b508;
            break;
        }
    case 0x1b504:
        memory[ds*16 + 0x0493] -= 1;
    case 0x1b508:
        memory[ds*16 + 0x00cf] = 0x00;
        yield* sub_1b764();
    case 0x1b510:
        yield* sub_1c227();
        if (memory[ds*16 + 0x00c7] == 0x00) {
            pc = 0x1b528;
            break;
        }
        yield* sub_1b59a();
        if (r8[bl]) {
            pc = 0x1b523;
            break;
        }
        pc = 0x1b510;
        break;
    case 0x1b523:
        yield* sub_1b5d0();
        pc = 0x1b510;
        break;
    case 0x1b528:
        yield* sub_1fb2b();
        yield* sub_1fb42();
        r8[al] = 0;
        memory[ds*16 + 0x48c4] = r8[al];
        memory[ds*16 + 0x0a4d] = r8[al];
        r16[ax] = pop();
        pc = 0x1b0ed;
        break;
        return;
    } while (1);
}
function* sub_1b53a() {
    yield* sub_1f961();
    yield* sub_1fb33();
    yield* sub_1bfad();
    yield* sub_1c045();
    yield* sub_1c02d();
    yield* sub_1bfe4();
    yield* sub_1c0f7();
    yield* sub_1c064();
    yield* sub_1b562();
    yield* sub_1fb37();
    yield* sub_1fb2b();
    yield* sub_1fb42();
    yield* sub_1fb2f();
}
function* sub_1b562() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x002c;
        r16[cx] = 0x00f0;
        r16[dx] = 0x0010;
        yield* sub_1fb52();
        r16[bx] = 0x000d;
        r16[cx] = 0x00e0;
        r16[dx] = 0x00a1;
        yield* sub_1fb52();
        yield* sub_1e0fa();
        r8[al] = 0x4c;
        if (memory[ds*16 + 0x0494] == 0x00) {
            pc = 0x1b588;
            break;
        }
        r8[al] = 0x52;
    case 0x1b588:
        memory[ds*16 + 0x48c4] = r8[al];
        r8[al] = 0x0f;
        r16[bx] = 0x0108;
        r16[cx] = 0x0087;
        si = 0x48c2;
        yield* sub_1fb75();
        return;
    } while (1);
}
function* sub_1b59a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[dx]);
        push(r16[cx]);
        r8[bl] = memory[ds*16 + 0x00cf];
        if (!r8[bl]) {
            pc = 0x1b5b9;
            break;
        }
        r16[cx] += 0x0004;
        r8[dl] += 0x04;
        r8[bh] = 0;
        yield* sub_1d5c7();
        memory16set(ds, 0x00d0, r16[ax]);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
    case 0x1b5b9:
        r16[cx] = pop();
        r16[dx] = pop();
        push(r16[dx]);
        push(r16[cx]);
        r16[bx] = 0x00fc;
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        r16[cx] = pop();
        r16[dx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1b5d0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] += 0x0004;
        r8[dl] += 0x04;
        si = 0x00f6;
    case 0x1b5d9:
        if (r16[cx] < memory16get(ds, si)) {
            pc = 0x1b5fc;
            break;
        }
        if (r8[dl] < memory[ds*16 + si + 2]) {
            pc = 0x1b5fc;
            break;
        }
        r8[ah] = 0;
        r8[al] = memory[ds*16 + si + 3];
        r16[ax] += memory16get(ds, si);
        if (r16[cx] > r16[ax]) {
            pc = 0x1b5fc;
            break;
        }
        r8[ah] = 0;
        r8[al] = memory[ds*16 + si + 4];
        r8[al] += memory[ds*16 + si + 2];
        if (r16[dx] > r16[ax]) {
            pc = 0x1b5fc;
            break;
        }
        yield *jumpIndirect(cs, memory16get(ds, si + 5));
        return;
    case 0x1b5fc:
        si += 0x0007;
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x1b5d9;
            break;
        }
        return;
    } while (1);
}
function* sub_1b764() {
    yield* sub_1bf80();
    memory16set(ds, 0x00cd, si);
    yield* sub_1bf3a();
    yield* sub_1b53a();
}
function* sub_1b970() {
    r16[ax] = 0;
    memory[ds*16 + 0x0493] = arkanoidLevel;
    memory[ds*16 + 0x0494] = arkanoidSide;
    memory[ds*16 + 0x0490] = r8[al];
    memory16set(ds, 0x0491, r16[ax]);
    memory[ds*16 + 0x0497] = 0x03;
    memory[ds*16 + 0x0a49] = 0x31;
    memory16set(ds, 0x049c, 0x2000);
    memory[ds*16 + 0x049e] = 0x00;
}
function* sub_1b978() {
    memory[ds*16 + 0x0490] = r8[al];
    memory16set(ds, 0x0491, r16[ax]);
    memory[ds*16 + 0x0497] = 0x03;
    memory[ds*16 + 0x0a49] = 0x31;
    memory16set(ds, 0x049c, 0x2000);
    memory[ds*16 + 0x049e] = 0x00;
}
function* sub_1b994() {
    push(es);
    push(ds);
    r16[ax] = 0x04dd;
    si = 0x003c;
    es = r16[ax];
    r8[al] = memory[es*16 + si];
    memory[ds*16 + 0x00c7] = r8[al];
    r8[al] = memory[es*16 + si + 1];
    memory[ds*16 + 0x47e0] = r8[al];
    r8[al] = memory[es*16 + si + 2];
    memory[ds*16 + 0x048f] = r8[al];
    r8[al] = memory[es*16 + si + 3];
    memory[ds*16 + 0x0a4a] = r8[al];
    r8[al] = memory[es*16 + si + 4];
    memory[ds*16 + 0x0a4b] = r8[al];
    r8[al] = memory[es*16 + si + 5];
    memory[ds*16 + 0x049a] = r8[al];
    r8[al] = memory[es*16 + si + 6];
    memory[ds*16 + 0x0284] = r8[al];
    r8[al] = memory[es*16 + si + 7];
    memory[cs*16 + 0x325b] = r8[al];
    r8[al] = memory[es*16 + si + 8];
    memory[ds*16 + 0x5e36] = r8[al];
    r8[al] = memory[es*16 + si + 9];
    memory[ds*16 + 0x47e8] = r8[al];
    r8[al] = memory[es*16 + si + 10];
    memory[ds*16 + 0x5e35] = r8[al];
    r16[ax] = memory16get(es, si + 11);
    memory16set(ds, 0x47fb, r16[ax]);
    r16[ax] = memory16get(es, si + 13);
    memory16set(ds, 0x47fd, r16[ax]);
    r16[ax] = memory16get(es, si + 15);
    memory16set(ds, 0x47ff, r16[ax]);
    r16[ax] = memory16get(es, si + 17);
    memory16set(ds, 0x4801, r16[ax]);
    r16[ax] = memory16get(es, si + 19);
    memory16set(ds, 0x4803, r16[ax]);
    r16[ax] = es;
    r16[bx] = ds;
    ds = r16[ax];
    es = r16[bx];
    si += 0x0015;
    di = 0x0075;
    r16[cx] = 0x0051;
    rep_movsb_data_data_forward();
    ds = pop();
    r16[ax] = ds;
    es = r16[ax];
    r16[cx] = 0x0003;
    si = 0x0081;
    di = 0x0a46;
    rep_movsb_data_data_forward();
    r8[al] = memory[ds*16 + 0x0075];
    memory[cs*16 + 0x150a] = r8[al];
    r8[al] = memory[ds*16 + 0x0076];
    memory[cs*16 + 0x150b] = r8[al];
    r8[al] = memory[ds*16 + 0x0077];
    memory[cs*16 + 0x150c] = r8[al];
    es = pop();
}
function* sub_1ba4f() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1ba4f:
        memory[ds*16 + 0x4809] = 0x00;
        yield* sub_1fb33();
        r16[bx] = 0x0006;
        r16[cx] = 0x0060;
        r16[dx] = 0x0044;
        yield* sub_1fb52();
        r16[bx] = 0x0007;
        r16[cx] = 0x0020;
        r16[dx] = 0x0005;
        yield* sub_1fb52();
        r16[bx] = 0x0008;
        r16[cx] = 0x0000;
        r16[dx] = 0x0046;
        yield* sub_1fb52();
        r16[bx] = 0x0008;
        r16[cx] = 0x00e8;
        r16[dx] = 0x0046;
        yield* sub_1fb52();
        r16[bx] = 0x000d;
        r16[cx] = 0x00e0;
        r16[dx] = 0x00a1;
        yield* sub_1fb52();
        yield* sub_1fb2b();
        yield* sub_1f311();
        r16[bx] = 0x010c;
        yield* sub_1f0d2();
        if (memory[ds*16 + 0x027d] != 0x00) {
            pc = 0x1baa9;
            break;
        }
        yield* sub_1bc60();
    case 0x1baa9:
        r16[cx] = 0x03c0;
    case 0x1baac:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl])
            return;
        if (--r16[cx]) {
            pc = 0x1baac;
            break;
        }
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al])
            return;
        r8[al] = memory[cs*16 + 0x325b];
        memory[ds*16 + 0x0282] = r8[al];
        memory[cs*16 + 0x325b] = memory[cs*16 + 0x325b] & 0xfc;
        yield* sub_1f2dc();
        memory[ds*16 + 0x0283] = 0x00;
        yield* sub_1bc14();
        r8[al] = memory[ds*16 + 0x0282];
        memory[cs*16 + 0x325b] = r8[al];
        if (memory[ds*16 + 0x0283] != 0x00) {
            pc = 0x1baea;
            break;
        }
        pc = 0x1ba4f;
        break;
    case 0x1baea:
        r16[bx] = 0x010c;
        yield* sub_1f0d2();
        return;
    } while (1);
}
function* sub_1baf1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x4809] = 0x00;
        yield* sub_1fb33();
        r16[bx] = 0x0009;
        r16[cx] = 0x0000;
        r16[dx] = 0x006e;
        yield* sub_1fb52();
        yield* sub_1beac();
        yield* sub_1fb2b();
        si = 0x0285;
    case 0x1bb0f:
        r8[al] = 0x05;
        r16[bx] = 0x0008;
        r16[cx] = 0x005c;
        yield* sub_1fb75();
        si++;
        r8[al] = memory[ds*16 + si];
        if (r8[al] == 0xff) {
            pc = 0x1bb40;
            break;
        }
        r16[cx] = 0x0009;
    case 0x1bb24:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1fb7d();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl])
            return;
        if (--r16[cx]) {
            pc = 0x1bb24;
            break;
        }
        pc = 0x1bb0f;
        break;
    case 0x1bb40:
        r16[cx] = 0x0064;
    case 0x1bb43:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1fb7d();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl])
            return;
        if (--r16[cx]) {
            pc = 0x1bb43;
            break;
        }
        return;
    } while (1);
}
function* sub_1bb0f() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1bb0f:
        r8[al] = 0x05;
        r16[bx] = 0x0008;
        r16[cx] = 0x005c;
        yield* sub_1fb75();
        si++;
        r8[al] = memory[ds*16 + si];
        if (r8[al] == 0xff) {
            pc = 0x1bb40;
            break;
        }
        r16[cx] = 0x0009;
    case 0x1bb24:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1fb7d();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl])
            return;
        if (--r16[cx]) {
            pc = 0x1bb24;
            break;
        }
        pc = 0x1bb0f;
        break;
    case 0x1bb40:
        r16[cx] = 0x0064;
    case 0x1bb43:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1f961();
        yield* sub_1fb7d();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (r8[cl])
            return;
        if (--r16[cx]) {
            pc = 0x1bb43;
            break;
        }
        return;
    } while (1);
}
function* sub_1bb5e() {
    yield* sub_1bbe6();
    si = 0x045c;
    r16[cx] = 0x6e00;
    r16[dx] = 0x9600;
    yield* sub_1bb85();
    si = 0x03bb;
    yield* sub_1bb0f();
}
function* sub_1bb74() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x4809] = 0x00;
        yield* sub_1bbe6();
        si = 0x0429;
        r16[cx] = 0x1e00;
        r16[dx] = 0x1900;
    case 0x1bb85:
        r8[al] = memory[ds*16 + si];
        if (!r8[al]) {
            pc = 0x1bbc0;
            break;
        }
    case 0x1bb8b:
        r16[cx] += memory16get(ds, si + 1);
        r16[dx] += memory16get(ds, si + 3);
        r16[bx] = 0x00c8;
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        r8[cl] = r8[ch];
        r8[dl] = r8[dh];
        r8[ch] = 0;
        r8[dh] = r8[ch];
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1c1ac();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        if (r8[cl]) {
            pc = 0x1bbdf;
            break;
        }
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x1bb8b;
            break;
        }
        si += 0x0005;
        pc = 0x1bb85;
        break;
    case 0x1bbc0:
        if (!(memory[cs*16 + 0x325b] & 0x10)) {
            pc = 0x1bbdf;
            break;
        }
        yield* sub_1fb2b();
        yield* sub_1fb42();
    case 0x1bbce:
        r16[ax] = 0x0007;
        push(cs);
        cs = 0x19ee;
        yield* sub_1b08e();
        assert(cs == 0x1b0c);
        if (flags.zero) {
            pc = 0x1bbdf;
            break;
        }
        yield* sub_1c1ac();
        if (!r8[cl]) {
            pc = 0x1bbce;
            break;
        }
    case 0x1bbdf:
        yield* sub_1fb2b();
        yield* sub_1fb42();
        return;
    } while (1);
}
function* sub_1bb85() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1bb85:
        r8[al] = memory[ds*16 + si];
        if (!r8[al]) {
            pc = 0x1bbc0;
            break;
        }
    case 0x1bb8b:
        r16[cx] += memory16get(ds, si + 1);
        r16[dx] += memory16get(ds, si + 3);
        r16[bx] = 0x00c8;
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        push(si);
        r8[cl] = r8[ch];
        r8[dl] = r8[dh];
        r8[ch] = 0;
        r8[dh] = r8[ch];
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1c1ac();
        si = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        if (r8[cl]) {
            pc = 0x1bbdf;
            break;
        }
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x1bb8b;
            break;
        }
        si += 0x0005;
        pc = 0x1bb85;
        break;
    case 0x1bbc0:
        if (!(memory[cs*16 + 0x325b] & 0x10)) {
            pc = 0x1bbdf;
            break;
        }
        yield* sub_1fb2b();
        yield* sub_1fb42();
    case 0x1bbce:
        r16[ax] = 0x0007;
        push(cs);
        cs = 0x19ee;
        yield* sub_1b08e();
        assert(cs == 0x1b0c);
        if (flags.zero) {
            pc = 0x1bbdf;
            break;
        }
        yield* sub_1c1ac();
        if (!r8[cl]) {
            pc = 0x1bbce;
            break;
        }
    case 0x1bbdf:
        yield* sub_1fb2b();
        yield* sub_1fb42();
        return;
    } while (1);
}
function* sub_1bbe6() {
    yield* sub_1fb33();
    r16[bx] = 0x0009;
    r16[cx] = 0x0000;
    r16[dx] = 0x006e;
    yield* sub_1fb52();
    r16[bx] = 0x0010;
    r16[cx] = 0x0010;
    r16[dx] = 0x000a;
    yield* sub_1fb52();
    yield* sub_1beac();
    yield* sub_1fb2b();
    yield* sub_1fb2f();
    yield* sub_1f311();
    r16[bx] = 0x0108;
    yield* sub_1f0d2();
}
function* sub_1bc14() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0284];
        push(r16[ax]);
        r8[al] = 0x31;
        memory[ds*16 + 0x0284] = r8[al];
        r8[al] = memory[ds*16 + 0x0a4a];
        push(r16[ax]);
        r8[al] |= 0x80;
        memory[ds*16 + 0x0a4a] = r8[al];
        memory16set(ds, 0x027e, 0x5460);
        yield* sub_1bce1();
        r8[al] &= 0x01;
        memory[ds*16 + 0x0494] = r8[al];
    case 0x1bc34:
        yield* sub_1bce1();
        r8[al] &= 0x3f;
        if (r8[al] > 0x21) {
            pc = 0x1bc34;
            break;
        }
        memory[ds*16 + 0x0493] = r8[al];
        r16[ax] = 0;
        yield* sub_1b978();
        yield* sub_1bcf0();
        r16[ax] = pop();
        memory[ds*16 + 0x0a4a] = r8[al];
        memory[ds*16 + 0x049a] = r8[al];
        r16[ax] = pop();
        memory[ds*16 + 0x0284] = r8[al];
        yield* sub_1b970();
        return;
    } while (1);
}
function* sub_1bc60() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x027d] = 0x01;
        yield* sub_1f961();
        yield* sub_1f286();
        push(r16[ax]);
        r16[cx] = 0x0000;
        r16[dx] = 0x0000;
        r16[bx] = 0x00c8;
        yield* sub_1fb3b();
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        yield* sub_1f286();
        r16[bx] = pop();
        r16[bx] -= r16[ax];
        push(r16[bx]);
        yield* sub_1fb42();
        yield* sub_1f961();
        yield* sub_1f286();
        push(r16[ax]);
        r16[cx] = 0x0100;
    case 0x1bc92:
        r16[ax] = memory16get(ds, 0x0280);
        r16[bx] >>= 1;
        r16[bx] += r16[ax];
        if (--r16[cx]) {
            pc = 0x1bc92;
            break;
        }
        yield* sub_1f286();
        r16[bx] = pop();
        r16[bx] -= r16[ax];
        r16[ax] = pop();
        r16[ax] >>= 1;
        r16[bx] += r16[ax];
        r8[al] = 0x01;
        r16[cx] = 0x070f;
        if (r16[bx] < 0x122e) {
            pc = 0x1bcc7;
            break;
        }
        memory[cs*16 + 0x1cd0] = 0x01;
        r16[cx] = 0x0507;
        r8[al] = 0x02;
        if (r16[bx] < 0x245c) {
            pc = 0x1bcc7;
            break;
        }
        r16[cx] = 0x0303;
        r8[al] = 0x03;
    case 0x1bcc7:
        memory[ds*16 + 0x5870] = r8[al];
        r8[al] <<= 1;
        r8[ah] = 0;
        memory16set(ds, 0x586d, r16[ax]);
        memory[ds*16 + 0x586b] = r8[ch];
        memory[ds*16 + 0x586c] = r8[cl];
        return;
    } while (1);
}
function* sub_1bce1() {
    r16[ax] = memory16get(ds, 0x0280);
    r8[al] += 0x97;
    memory16set(ds, 0x0280, r16[ax]);
}
function* sub_1bcf0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1bf3a();
        yield* sub_1be22();
    case 0x1bcf6:
        yield* sub_1bd07();
        yield* sub_1bdcc();
        if (memory[ds*16 + 0x0497] != 0x00) {
            pc = 0x1bcf6;
            break;
        }
        yield* sub_1be93();
        return;
    } while (1);
}
function* sub_1bd07() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1bd07;
        break;
    case 0x1b0dd:
        yield* sub_1ba4f();
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al]) {
            pc = 0x1b10f;
            break;
        }
        yield* sub_1baf1();
        yield* sub_1bb74();
        yield* sub_1b970();
        yield* sub_1bcf0();
        yield* sub_1b1aa();
        if (!(r8[ah] & 0x01)) {
            pc = 0x1b100;
            break;
        }
        r8[bl] = 0x31;
        yield* sub_1b1d9();
    case 0x1b100:
        if (!(r8[ah] & 0x02)) {
            pc = 0x1b10a;
            break;
        }
        r8[bl] = 0x32;
        yield* sub_1b1d9();
    case 0x1b10a:
        yield* sub_1b29e();
        pc = 0x1b0dd;
        break;
    case 0x1b10f:
        r8[al] = 0;
        memory[ds*16 + 0x0493] = r8[al];
        memory[ds*16 + 0x0494] = r8[al];
        memory[ds*16 + 0x0a4d] = 0x01;
    case 0x1b11c:
        yield* sub_1b4f0();
        pc = 0x1b0dd;
        break;
    case 0x1bd07:
        r8[al] = memory[ds*16 + 0x0494];
        memory[ds*16 + 0x0ac2] = r8[al];
        yield* sub_1bd95();
        si = 0x58e2;
        yield* sub_1c8f8();
        yield* sub_1f961();
    case 0x1bd19:
        yield* sub_1c750();
        if (memory[ds*16 + 0x0a4c] < 0x01) {
            pc = 0x1bd19;
            break;
        }
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        yield* sub_1fb90();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        memory[ds*16 + 0x0a4c] = 0x00;
        memory[ds*16 + 0x47e1] = 0x00;
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        if (stop(/*70 - je*/)) {
            pc = 0x1bd41;
            break;
        }
        memory[ds*16 + 0x0497] -= 1;
        if (memory[ds*16 + 0x0497] == 0) {
            pc = 0x1bd5f;
            break;
        }
        return;
    case 0x1bd41:
        if (memory[ds*16 + 0x0a4d] == 0x01) {
            pc = 0x1bd86;
            break;
        }
        memory[ds*16 + 0x0493] += 1;
        yield* sub_1bf3a();
        if (memory[ds*16 + 0x0493] != 0x22) {
            pc = 0x1bd07;
            break;
        }
        yield* sub_1bb5e();
        memory[ds*16 + 0x0497] = 0x00;
        return;
    case 0x1bd5f:
        if (memory[ds*16 + 0x0a4d] == 0x01) {
            pc = 0x1bd86;
            break;
        }
        r16[bx] = 0x0107;
        yield* sub_1f0d2();
        r16[bx] = 0x0050;
        r16[cx] = 0x00a2;
        r8[al] = 0x0f;
        si = 0x0a59;
        yield* sub_1fb79();
        r16[cx] = 0x00b4;
    case 0x1bd7d:
        yield* sub_1c46f();
        yield* sub_1f961();
        if (--r16[cx]) {
            pc = 0x1bd7d;
            break;
        }
        return;
    case 0x1bd86:
        memory[ds*16 + 0x00c7] = 0xff;
        r8[al] = memory[ds*16 + 0x0ac2];
        memory[ds*16 + 0x0494] = r8[al];
        r16[ax] = pop();
        pc = 0x1b11c;
        break;
        return;
    } while (1);
}
function* sub_1bd95() {
    yield* sub_1f961();
    yield* sub_1fb33();
    yield* sub_1be6d();
    yield* sub_1c8de();
    yield* sub_1bfad();
    yield* sub_1c045();
    yield* sub_1c02d();
    yield* sub_1bfe4();
    yield* sub_1c0a5();
    yield* sub_1c064();
    yield* sub_1c008();
    yield* sub_1be47();
    yield* sub_1beac();
    yield* sub_1fb37();
    yield* sub_1f969();
    yield* sub_1fb2b();
    yield* sub_1fb2f();
    yield* sub_1fb81();
}
function* sub_1bdcc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x0284] == 0x31) {
            pc = 0x1bde0;
            break;
        }
        yield* sub_1bde4();
        if (memory[ds*16 + 0x0497] != 0x00) {
            pc = 0x1bde0;
            break;
        }
        yield* sub_1bde4();
    case 0x1bde0:
        yield* sub_1c178();
        return;
    } while (1);
}
function* sub_1bde4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = 0x0680;
        si = 0x0863;
        if (memory[ds*16 + 0x0a49] == 0x31) {
            pc = 0x1bdf8;
            break;
        }
        r16[tx] = di;
        di = si;
        si = r16[tx];
    case 0x1bdf8:
        push(si);
        si = 0x0490;
        r16[cx] = 0x01e3;
        rep_movsb_data_data_forward();
        si = pop();
        di = 0x0490;
        r16[cx] = 0x01e3;
        rep_movsb_data_data_forward();
        es = pop();
        memory[ds*16 + 0x58da] = 0x78;
        memory[ds*16 + 0x0a49] = memory[ds*16 + 0x0a49] ^ 0x03;
        if (memory[ds*16 + 0x0a49] == 0x31)
            return;
        memory[ds*16 + 0x58da] = 0x8c;
        return;
    } while (1);
}
function* sub_1be22() {
    push(es);
    r16[ax] = ds;
    es = r16[ax];
    di = 0x0863;
    r8[al] = memory[ds*16 + 0x0a4b];
    yield* sub_1be3b();
    di = 0x0680;
    r8[al] = memory[ds*16 + 0x0a4a];
    yield* sub_1be3b();
    es = pop();
}
function* sub_1be3b() {
    memory[ds*16 + 0x049a] = r8[al];
    si = 0x0490;
    r16[cx] = 0x01e3;
    rep_movsb_data_data_forward();
}
function* sub_1be47() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0493];
        if (r8[al] == 0x10) {
            pc = 0x1be53;
            break;
        }
        if (r8[al] == 0x21) {
            pc = 0x1be60;
            break;
        }
        return;
    case 0x1be53:
        r16[bx] = 0x0017;
        r16[cx] = 0x0050;
        r16[dx] = 0x0034;
        yield* sub_1fb52();
        return;
    case 0x1be60:
        r16[bx] = 0x0011;
        r16[cx] = 0x0058;
        r16[dx] = 0x003c;
        yield* sub_1fb52();
        return;
    } while (1);
}
function* sub_1be6d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0;
        memory[ds*16 + 0x48d5] = r8[al];
        memory[ds*16 + 0x48e0] = r8[al];
        memory[ds*16 + 0x48eb] = r8[al];
        memory[ds*16 + 0x48ec] = r8[al];
        memory[ds*16 + 0x48d3] = r8[al];
        r8[al] = memory[ds*16 + 0x0499];
        if (memory[ds*16 + 0x048f] != 0x07) {
            pc = 0x1be90;
            break;
        }
        r8[bl] = r8[al];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] += r8[bl];
    case 0x1be90:
        memory[ds*16 + 0x48e8] = r8[al];
        r16[bx] = 0x0680;
        if (memory[ds*16 + 0x0a49] == 0x31) {
            pc = 0x1bea0;
            break;
        }
        r16[bx] = 0x0863;
    case 0x1bea0:
        r16[ax] = memory16get(ds, 0x0490);
        memory16set(ds, r16[bx], r16[ax]);
        r16[ax] = memory16get(ds, 0x0492);
        memory16set(ds, r16[bx] + 2, r16[ax]);
        return;
    } while (1);
}
function* sub_1be93() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0680;
        if (memory[ds*16 + 0x0a49] == 0x31) {
            pc = 0x1bea0;
            break;
        }
        r16[bx] = 0x0863;
    case 0x1bea0:
        r16[ax] = memory16get(ds, 0x0490);
        memory16set(ds, r16[bx], r16[ax]);
        r16[ax] = memory16get(ds, 0x0492);
        memory16set(ds, r16[bx] + 2, r16[ax]);
        return;
    } while (1);
}
function* sub_1beac() {
    r16[bx] = 0x000b;
    r16[cx] = 0x00f0;
    r16[dx] = 0x0000;
    yield* sub_1fb52();
    r16[bx] = 0x000a;
    r16[cx] = 0x00f0;
    r16[dx] = 0x000e;
    yield* sub_1fb52();
    r16[bx] = 0x0008;
    r16[cx] = 0x00f0;
    r16[dx] = 0x0047;
    yield* sub_1fb52();
    r16[bx] = 0x000d;
    r16[cx] = 0x00e0;
    r16[dx] = 0x00a1;
    yield* sub_1fb52();
    r16[bx] = 0x000c;
    r16[cx] = 0x00f0;
    r16[dx] = 0x005a;
    yield* sub_1fb52();
    r16[bx] = 0x000e;
    r16[cx] = 0x00f8;
    r16[dx] = 0x006e;
    yield* sub_1fb52();
    r16[bx] = 0x000f;
    r16[cx] = 0x00f8;
    r16[dx] = 0x0082;
    yield* sub_1fb52();
    r8[cl] = memory[ds*16 + 0x0680];
    r16[ax] = memory16get(ds, 0x0681);
    yield* sub_1da36();
    r16[cx] = 0x0078;
    r16[bx] = 0x00f0;
    yield* sub_1cdef();
    r8[cl] = memory[ds*16 + 0x0863];
    r16[ax] = memory16get(ds, 0x0864);
    yield* sub_1da36();
    r16[cx] = 0x008c;
    r16[bx] = 0x00f0;
    yield* sub_1cdef();
    r8[cl] = memory[ds*16 + 0x0a46];
    r16[ax] = memory16get(ds, 0x0a47);
    yield* sub_1da36();
    r16[cx] = 0x0064;
    r16[bx] = 0x00f0;
    yield* sub_1cdef();
}
function* sub_1bf26() {
    r8[cl] = memory[ds*16 + 0x0a46];
    r16[ax] = memory16get(ds, 0x0a47);
    yield* sub_1da36();
    r16[cx] = 0x0064;
    r16[bx] = 0x00f0;
    yield* sub_1cdef();
}
function* sub_1bf3a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        yield* sub_1bf80();
        r8[al] = memory[ds*16 + si];
        memory[ds*16 + 0x0495] = r8[al];
        si++;
        r8[al] = memory[ds*16 + si];
        memory[ds*16 + 0x0496] = r8[al];
        si++;
        r8[ah] = memory[ds*16 + si];
        memory[ds*16 + 0x0499] = r8[ah];
        si++;
        di = 0x0a4e;
        r16[cx] = 0x000a;
        rep_movsb_data_data_forward();
        di = 0x0a4e;
        r8[cl] = 0xff;
    case 0x1bf62:
        r8[cl]++;
        r8[ah] = memory[ds*16 + di];
        di++;
        if (r8[ah]) {
            pc = 0x1bf62;
            break;
        }
        memory[ds*16 + 0x48ed] = r8[cl];
        di = 0x049f;
        r16[cx] = 0x00ea;
        push(r16[cx]);
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x0589;
        rep_movsb_data_data_forward();
        es = pop();
        return;
    } while (1);
}
function* sub_1bf80() {
    r8[bl] = memory[ds*16 + 0x0493];
    r8[bh] = 0;
    r16[bx] <<= 1;
    si = 0x0ad0;
    r8[al] = memory[ds*16 + 0x0494];
    r8[ah] = 0;
    r16[bx] += r16[ax];
    r8[al] = memory[ds*16 + r16[bx] + si];
    r16[cx] = 0x00f7;
    mul16(r16[cx]);
    si = 0x0b17;
    si += r16[ax];
}
function* sub_1bf9f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0009;
        r16[dx] = 0x0018;
        bp = 0x0020;
        si = 0x0005;
        pc = 0x1bfb9;
        break;
    case 0x1bfb9:
        r8[bh] = 0;
        r8[bl] = memory[ds*16 + 0x0495];
    case 0x1bfbf:
        push(r16[cx]);
        push(bp);
        push(si);
        r16[cx] = si;
        di = bp;
    case 0x1bfc6:
        push(r16[cx]);
        r16[cx] = di;
        push(r16[bx]);
        push(r16[dx]);
        push(di);
        yield* sub_1fb52();
        di = pop();
        r16[dx] = pop();
        r16[bx] = pop();
        di += 0x0020;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1bfc6;
            break;
        }
        si = pop();
        bp = pop();
        r16[cx] = pop();
        r16[dx] += 0x0012;
        if (--r16[cx]) {
            pc = 0x1bfbf;
            break;
        }
        yield* sub_1fb37();
        return;
    } while (1);
}
function* sub_1bfad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000b;
        r16[dx] = 0x0006;
        bp = 0x0000;
        si = 0x0007;
        r8[bh] = 0;
        r8[bl] = memory[ds*16 + 0x0495];
    case 0x1bfbf:
        push(r16[cx]);
        push(bp);
        push(si);
        r16[cx] = si;
        di = bp;
    case 0x1bfc6:
        push(r16[cx]);
        r16[cx] = di;
        push(r16[bx]);
        push(r16[dx]);
        push(di);
        yield* sub_1fb52();
        di = pop();
        r16[dx] = pop();
        r16[bx] = pop();
        di += 0x0020;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1bfc6;
            break;
        }
        si = pop();
        bp = pop();
        r16[cx] = pop();
        r16[dx] += 0x0012;
        if (--r16[cx]) {
            pc = 0x1bfbf;
            break;
        }
        yield* sub_1fb37();
        return;
    } while (1);
}
function* sub_1bfe4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0a62;
        r16[cx] = 0x0020;
    case 0x1bfea:
        push(r16[cx]);
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[bl] = memory[ds*16 + si];
        r8[cl] = memory[ds*16 + si + 1];
        r8[dl] = memory[ds*16 + si + 2];
        push(si);
        yield* sub_1fb4c();
        si = pop();
        si += 0x0003;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1bfea;
            break;
        }
        yield* sub_1fb37();
        return;
    } while (1);
}
function* sub_1c008() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0497];
        if (r8[al] < 0x06) {
            pc = 0x1c011;
            break;
        }
        r8[al] = 0x06;
    case 0x1c011:
        r8[al]--;
        if (r8[al] == 0)
            return;
        r16[cx] = 0x000a;
    case 0x1c018:
        push(r16[ax]);
        push(r16[cx]);
        r16[bx] = 0x00c8;
        r16[dx] = 0x00c3;
        yield* sub_1fb4c();
        r16[cx] = pop();
        r16[cx] += 0x0010;
        r16[ax] = pop();
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x1c018;
            break;
        }
        return;
    } while (1);
}
function* sub_1c02d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0001;
        r16[cx] = 0x0013;
    case 0x1c033:
        push(r16[cx]);
        r16[bx] = 0x0001;
        r16[cx] = 0x001a;
    case 0x1c03a:
        yield* sub_1fb65();
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1c03a;
            break;
        }
        r16[ax]++;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c033;
            break;
        }
        return;
    } while (1);
}
function* sub_1c045() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0001;
        r16[ax] = 0x0001;
        r16[cx] = 0x001b;
    case 0x1c04e:
        yield* sub_1fb58();
        r16[ax]++;
        if (--r16[cx]) {
            pc = 0x1c04e;
            break;
        }
        r16[bx] = 0x0002;
        r16[ax] = 0x0001;
        r16[cx] = 0x0019;
    case 0x1c05d:
        yield* sub_1fb58();
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1c05d;
            break;
        }
        return;
    } while (1);
}
function* sub_1c064() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0589;
        r16[ax] = 0x0002;
        r16[cx] = 0x0012;
    case 0x1c06d:
        push(r16[cx]);
        r16[bx] = 0x0002;
        r16[cx] = 0x000d;
    case 0x1c074:
        r8[dl] = memory[ds*16 + si];
        r8[dl] &= 0x0f;
        if (r8[dl] == 0) {
            pc = 0x1c09b;
            break;
        }
        r8[dl] = memory[ds*16 + si + 13];
        r8[dl] &= 0x0f;
        if (r8[dl] != 0) {
            pc = 0x1c089;
            break;
        }
        yield* sub_1fb58();
        yield* sub_1fb37();
    case 0x1c089:
        r8[dl] = memory[ds*16 + si + 14];
        r8[dl] &= 0x0f;
        if (r8[dl] != 0) {
            pc = 0x1c09b;
            break;
        }
        if (r16[bx] == 0x001a) {
            pc = 0x1c09b;
            break;
        }
        r16[bx]++;
        yield* sub_1fb58();
        r16[bx]--;
    case 0x1c09b:
        r16[bx]++;
        r16[bx]++;
        si++;
        if (--r16[cx]) {
            pc = 0x1c074;
            break;
        }
        r16[ax]++;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c06d;
            break;
        }
        return;
    } while (1);
}
function* sub_1c0a5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x0498] = 0x00;
        si = 0x0589;
        r16[cx] = 0x0012;
        r16[dx] = 0x000a;
    case 0x1c0b3:
        push(r16[cx]);
        r16[cx] = 0x000d;
        di = 0x0008;
    case 0x1c0ba:
        push(r16[cx]);
        r8[bl] = memory[ds*16 + si];
        r8[bl] &= 0x0f;
        if (r8[bl] == 0) {
            pc = 0x1c0de;
            break;
        }
        if (r8[bl] < 0x03) {
            pc = 0x1c0cb;
            break;
        }
        memory[ds*16 + 0x0498] += 1;
    case 0x1c0cb:
        r8[bh] = 0;
        r8[bl] += 0x0a;
        r16[cx] = di;
        push(di);
        push(si);
        push(r16[dx]);
        yield* sub_1fb4c();
        yield* sub_1fb37();
        r16[dx] = pop();
        si = pop();
        di = pop();
    case 0x1c0de:
        si++;
        r16[cx] = pop();
        di += 0x0010;
        if (--r16[cx]) {
            pc = 0x1c0ba;
            break;
        }
        r16[cx] = pop();
        r16[dx] += 0x0007;
        if (--r16[cx]) {
            pc = 0x1c0b3;
            break;
        }
        if (memory[ds*16 + 0x0498] != r8[cl])
            return;
        memory[ds*16 + 0x0498] = 0x01;
        return;
    } while (1);
}
function* sub_1c0f7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x00c6] = 0x00;
        si = 0x0589;
        r16[cx] = 0x0012;
        r16[dx] = 0x000a;
    case 0x1c105:
        push(r16[cx]);
        r16[cx] = 0x000d;
        di = 0x0008;
    case 0x1c10c:
        push(r16[cx]);
        r8[bl] = memory[ds*16 + si];
        r8[bl] &= 0x0f;
        if (r8[bl] == 0) {
            pc = 0x1c154;
            break;
        }
        r8[bh] = 0;
        r8[bl] += 0x0a;
        r16[cx] = di;
        push(di);
        push(si);
        push(r16[dx]);
        yield* sub_1fb4c();
        yield* sub_1fb37();
        r16[dx] = pop();
        si = pop();
        di = pop();
        if (!(memory[ds*16 + si] & 0x10)) {
            pc = 0x1c13a;
            break;
        }
        r16[cx] = di;
        push(di);
        push(si);
        push(r16[dx]);
        r16[bx] = 0x00fb;
        yield* sub_1fb4c();
        r16[dx] = pop();
        si = pop();
        di = pop();
    case 0x1c13a:
        if (!(memory[ds*16 + si] & 0x20)) {
            pc = 0x1c154;
            break;
        }
        r16[cx] = di;
        push(di);
        push(si);
        push(r16[dx]);
        memory[ds*16 + 0x00c6] += 1;
        r16[cx] += 0x0008;
        r16[bx] = 0x00fa;
        yield* sub_1fb4c();
        r16[dx] = pop();
        si = pop();
        di = pop();
    case 0x1c154:
        si++;
        r16[cx] = pop();
        di += 0x0010;
        if (--r16[cx]) {
            pc = 0x1c10c;
            break;
        }
        r16[cx] = pop();
        r16[dx] += 0x0007;
        if (--r16[cx]) {
            pc = 0x1c105;
            break;
        }
        return;
    } while (1);
}
function* sub_1c178() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        r8[al] = memory[ds*16 + 0x049a];
        r16[bx] = 0x111a;
        r16[cx] = 0x117d;
        if (r8[al] & 0x02) {
            pc = 0x1c1a1;
            break;
        }
        r16[bx] = 0x112c;
        r16[cx] = 0x116e;
        if (r8[al] & 0x04) {
            pc = 0x1c1a1;
            break;
        }
        r16[bx] = 0x1162;
        r16[cx] = 0x1178;
        if (r8[al] & 0x10) {
            pc = 0x1c1a1;
            break;
        }
        r16[bx] = 0x1135;
        r16[cx] = 0x1173;
    case 0x1c1a1:
        memory16set(ds, 0x47e9, r16[bx]);
        memory16set(ds, 0x47eb, r16[cx]);
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1c1ac() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1c46f();
        yield* callIndirect(cs, memory16get(ds, 0x47e9));
        if (!(memory[ds*16 + 0x049a] & 0x80)) {
            pc = 0x1c212;
            break;
        }
        if (!r8[cl]) {
            pc = 0x1c1c5;
            break;
        }
        memory[ds*16 + 0x0283] = 0x01;
        pc = 0x1c1cb;
        break;
    case 0x1c1c5:
        memory16set(ds, 0x027e, memory16get(ds, 0x027e) - 1);
        if (memory16get(ds, 0x027e) != 0) {
            pc = 0x1c1d5;
            break;
        }
    case 0x1c1cb:
        memory[ds*16 + 0x0497] = 0x01;
        memory[ds*16 + 0x0a4c] = 0x02;
    case 0x1c1d5:
        yield* sub_1dc70();
        pc = 0x1c1ff;
        break;
    case 0x1c1ff:
        if (r16s[bx] < signed16(0x0008)) {
            pc = 0x1c214;
            break;
        }
        r8[dl] = memory[ds*16 + 0x48d1];
        r8[dh] = 0;
        r16[dx] += r16[bx];
        if (r16[dx] > 0x00d1) {
            pc = 0x1c219;
            break;
        }
    case 0x1c212:
        flags.carry = false;
        return;
    case 0x1c214:
        r16[bx] = 0x0008;
        flags.carry = false;
        return;
    case 0x1c219:
        r16[bx] = 0x00d1;
        r8[bl] -= memory[ds*16 + 0x48d1];
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1c1f5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1c592();
        r8[al] = memory[ds*16 + 0x48d8];
        r8[ah] = 0;
        r16[bx] += r16[ax];
        if (r16s[bx] < signed16(0x0008)) {
            pc = 0x1c214;
            break;
        }
        r8[dl] = memory[ds*16 + 0x48d1];
        r8[dh] = 0;
        r16[dx] += r16[bx];
        if (r16[dx] > 0x00d1) {
            pc = 0x1c219;
            break;
        }
        flags.carry = false;
        return;
    case 0x1c214:
        r16[bx] = 0x0008;
        flags.carry = false;
        return;
    case 0x1c219:
        r16[bx] = 0x00d1;
        r8[bl] -= memory[ds*16 + 0x48d1];
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1c227() {
    yield* sub_1c46f();
    yield *jumpIndirect(cs, memory16get(ds, 0x47eb));
}
function* sub_1c363() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[ax] = 0x0000;
        es = r16[ax];
        r16[ax] = memory16get(cs, 0x325d);
        mul16(memory16get(ds, 0x595e));
        flags.carry = (memory16get(es, 0x046c) + r16[dx]) >= 0x10000;
        memory16set(es, 0x046c, memory16get(es, 0x046c) + r16[dx]);
        if (!flags.carry) {
            pc = 0x1c37d;
            break;
        }
        memory16set(es, 0x046e, memory16get(es, 0x046e) + 1);
    case 0x1c37d:
        r16[ax] = memory16get(cs, 0x325f);
        mul16(memory16get(ds, 0x595e));
        memory16set(es, 0x046e, memory16get(es, 0x046e) + r16[dx]);
        es = pop();
        return;
    } while (1);
}
function* sub_1c38c() {
    push(ds);
    r16[ax] = 0x3509;
    interrupt(0x21);
    memory16set(ds, 0x480b, r16[bx]);
    memory16set(ds, 0x480d, es);
    r16[ax] = cs;
    ds = r16[ax];
    r16[dx] = 0x1309;
    r16[ax] = 0x2509;
    interrupt(0x21);
    ds = pop();
}
function* sub_1c3a8() {
    r16[ax] = memory16get(ds, 0x480b);
    r16[ax] |= memory16get(ds, 0x480d);
    if (!r16[ax])
        return;
    push(ds);
    r16[dx] = memory16get(ds, 0x480b);
    ds = memory16get(ds, 0x480d);
    r16[ax] = 0x2509;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0;
    memory16set(ds, 0x480b, r16[ax]);
    memory16set(ds, 0x480d, r16[ax]);
}
function* sub_1c3c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r8[al] = in8(0x60);
        r8[ah] = r8[al];
        r8[al] = in8(0x61);
        r8[al] |= 0x80;
        out8(0x61, r8[al]);
        r8[al] &= 0x7f;
        out8(0x61, r8[al]);
        if (r8[ah] == 0xff) {
            pc = 0x1c3ec;
            break;
        }
        if (!(r8[ah] & 0x80)) {
            pc = 0x1c3ee;
            break;
        }
        r8[ah] &= 0x7f;
        if (memory[cs*16 + 0x1339] != r8[ah]) {
            pc = 0x1c3f3;
            break;
        }
    case 0x1c3ec:
        r8[ah] = 0;
    case 0x1c3ee:
        memory[cs*16 + 0x1339] = r8[ah];
    case 0x1c3f3:
        r8[al] = 0x20;
        out8(0x20, r8[al]);
        r16[ax] = pop();
        stop();
        return;
    } while (1);
}
function* sub_1c3fa() {
    if (memory16get(ds, 0x47e9) != 0x111a)
        return;
    r8[cl] = memory[ds*16 + 0x48d8];
    r8[ch] = 0;
    r16[cx] <<= 1;
    r16[ax] = 0x0004;
    r16[dx] = 0x0001;
    interrupt(0x33);
}
function* sub_1c413() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1c413:
        r8[al] = memory[cs*16 + 0x1339];
        if (!r8[al]) {
            pc = 0x1c413;
            break;
        }
        r16[bx] = 0;
        memory[cs*16 + 0x1339] = r8[bl];
        r16[cx] = 0x0022;
    case 0x1c425:
        if (memory[ds*16 + r16[bx] + 18490] == r8[al]) {
            pc = 0x1c430;
            break;
        }
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1c425;
            break;
        }
        pc = 0x1c413;
        break;
    case 0x1c430:
        r8[al] = memory[ds*16 + r16[bx] + 18524];
        return;
    } while (1);
}
function* sub_1c46f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1c46f;
        break;
    case 0x1c44b:
        memory[cs*16 + 0x1339] = 0x00;
        memory[cs*16 + 0x325b] = memory[cs*16 + 0x325b] ^ r8[al];
        if (memory[cs*16 + 0x325b] & r8[al]) {
            pc = 0x1c460;
            break;
        }
        pc = 0x1f2dc;
        break;
    case 0x1c460:
        pc = 0x1f2bc;
        break;
    case 0x1c46f:
        r8[ah] = memory[cs*16 + 0x1339];
        if (r8[ah] == 0x3b) {
            pc = 0x1c4b3;
            break;
        }
        if (r8[ah] == 0x43) {
            pc = 0x1c49c;
            break;
        }
        r8[al] = 0x01;
        if (r8[ah] == 0x3c) {
            pc = 0x1c44b;
            break;
        }
        r8[al]++;
        if (r8[ah] == 0x3d) {
            pc = 0x1c44b;
            break;
        }
        if (r8[ah] == 0x44) {
            pc = 0x1c4da;
            break;
        }
        if (r8[ah] == 0x30) {
            pc = 0x1c4a2;
            break;
        }
        if (r8[ah] == 0x19) {
            pc = 0x1c500;
            break;
        }
    case 0x1c49b:
        return;
    case 0x1c49c:
        memory[ds*16 + 0x00c7] = memory[ds*16 + 0x00c7] ^ 0xff;
        return;
    case 0x1c4a2:
        if (memory[ds*16 + 0x47e0] == 0x00) {
            pc = 0x1c49b;
            break;
        }
        if (memory[ds*16 + 0x47e1] == 0x00) {
            pc = 0x1c49b;
            break;
        }
        pc = 0x1dbc3;
        break;
    case 0x1c4b3:
        if (memory[ds*16 + 0x47e1] == 0x00) {
            pc = 0x1c49b;
            break;
        }
        memory[cs*16 + 0x1339] = 0x00;
        r8[bl] = memory[cs*16 + 0x325b];
        memory[cs*16 + 0x325b] = memory[cs*16 + 0x325b] & 0xfc;
        yield* sub_1c510();
        memory[cs*16 + 0x325b] = r8[bl];
        memory[cs*16 + 0x1339] = 0x00;
    case 0x1c4d9:
        return;
    case 0x1c4da:
        yield* sub_1c3a8();
        yield* sub_1f042();
        yield* sub_1b45a();
        r8[al] = 0x03;
        yield* sub_1f2dc();
        yield* sub_1c363();
        yield* sub_1f8c5();
        r16[ax] = 0x1118;
        ds = r16[ax];
        r16[dx] = memory16get(ds, 0x480f);
        r8[ah] = 0x09;
        interrupt(0x21);
        r16[ax] = 0x4c00;
        interrupt(0x21);
    case 0x1c500:
        if (memory[ds*16 + 0x47e0] == 0x00) {
            pc = 0x1c4d9;
            break;
        }
        memory[cs*16 + 0x1339] = 0x00;
        pc = 0x1dbe2;
        break;
    case 0x1dbc3:
        yield* sub_1dca8();
        memory[ds*16 + 0x48e0] = 0x01;
        memory[ds*16 + 0x47e1] = 0x00;
        r16[bx] = 0x590e;
        memory16set(ds, r16[bx] + 5, 0x7ffe);
        yield* sub_1c939();
        return;
    case 0x1dbe2:
        r16[bx] = 0x020b;
        yield* sub_1f0d2();
        memory[ds*16 + 0x0497] += 1;
        yield* sub_1d6f2();
        r8[cl] = memory[ds*16 + 0x0497];
        if (r8[cl] > 0x06) {
            pc = 0x1dc19;
            break;
        }
        push(si);
        r8[ch] = 0;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] -= 0x0016;
        r16[bx] = 0x00c8;
        r16[dx] = 0x00c3;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_1fb4c();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        yield* sub_1fb46();
        si = pop();
    case 0x1dc19:
        return;
    case 0x1f2bc:
        if (!(memory[cs*16 + 0x325b] & 0x10)) {
            pc = 0x1f2db;
            break;
        }
        r8[cl] = r8[al];
        r16[bx] = 0x5964;
        r16[ax] = 0;
    case 0x1f2cb:
        if (!(memory[ds*16 + r16[bx]] & r8[cl])) {
            pc = 0x1f2d4;
            break;
        }
        push(cs);
        cs = 0x19ee;
        yield* sub_1b0b6();
        assert(cs == 0x1b0c);
    case 0x1f2d4:
        r16[bx]++;
        r16[ax]++;
        if (r16[ax] < 0x0012) {
            pc = 0x1f2cb;
            break;
        }
    case 0x1f2db:
        return;
    case 0x1f2dc:
        yield *jumpIndirect(cs, memory16get(cs, 0x3263));
        return;
    } while (1);
}
function* sub_1c510() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        yield* sub_1f2dc();
        yield* sub_1c564();
    case 0x1c517:
        r8[ah] = memory[cs*16 + 0x1339];
        if (r8[ah] == 0x3b) {
            pc = 0x1c54d;
            break;
        }
        if (memory[cs*16 + 0x3259] < 0x3c) {
            pc = 0x1c517;
            break;
        }
        memory[cs*16 + 0x3259] = 0x00;
        yield* sub_1c534();
        pc = 0x1c517;
        break;
    case 0x1c54d:
        yield* sub_1f2bc();
        yield* sub_1c57c();
        yield* sub_1bf26();
        memory[cs*16 + 0x3259] = 0x01;
        memory[cs*16 + 0x325a] = 0x01;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1c534() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] ^= 0x01;
        push(r16[cx]);
        si = 0x487e;
        if (r8[cl]) {
            pc = 0x1c540;
            break;
        }
        si = 0x4886;
    case 0x1c540:
        r16[cx] = 0x0064;
        r16[bx] = 0x00f0;
        r8[al] = 0x0f;
        yield* sub_1fb75();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_1c564() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x47e9) != 0x111a) {
            pc = 0x1c579;
            break;
        }
        r16[ax] = 0x0003;
        interrupt(0x33);
        memory16set(ds, 0x4836, r16[cx]);
        memory16set(ds, 0x4838, r16[dx]);
    case 0x1c579:
        r8[cl] = 0;
        return;
    } while (1);
}
function* sub_1c57c() {
    if (memory16get(ds, 0x47e9) != 0x111a)
        return;
    r16[cx] = memory16get(ds, 0x4836);
    r16[dx] = memory16get(ds, 0x4838);
    r16[ax] = 0x0004;
    interrupt(0x33);
}
function* sub_1c592() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = memory[cs*16 + 0x1339];
        r16[bx] = 0xfffd;
        if (r8[ah] == memory[cs*16 + 0x150a]) {
            pc = 0x1c5b5;
            break;
        }
        r16[bx] = -r16[bx];
        if (r8[ah] == memory[cs*16 + 0x150b]) {
            pc = 0x1c5b5;
            break;
        }
        r16[bx] = 0;
        r8[cl] = 0x01;
        if (r8[ah] == memory[cs*16 + 0x150c]) {
            pc = 0x1c5c6;
            break;
        }
    case 0x1c5b5:
        r8[cl] = 0;
        r8[al] = memory[ds*16 + 0x5870];
        r8[al]--;
        if (r8[al] == 0) {
            pc = 0x1c5c6;
            break;
        }
        r16[bx] += r16[bx];
        r8[al]--;
        if (r8[al] == 0) {
            pc = 0x1c5c6;
            break;
        }
        r16[bx] += r16[bx];
    case 0x1c5c6:
        yield* sub_1c601();
        return;
    } while (1);
}
function* sub_1c601() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x5870];
        if (memory[ds*16 + 0x4808] == 0x00) {
            pc = 0x1c618;
            break;
        }
        r8[tl] = memory[ds*16 + 0x4809];
        memory[ds*16 + 0x4809] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1c625;
            break;
        }
        memory[ds*16 + 0x4809] = 0x0a;
        pc = 0x1c63e;
        break;
    case 0x1c618:
        if (memorys[ds*16 + 0x4809] <= signed8(0x00)) {
            pc = 0x1c625;
            break;
        }
        memory[ds*16 + 0x4809] -= r8[al];
        pc = 0x1c632;
        break;
    case 0x1c625:
        if (memory[ds*16 + 0x480a] == r8[cl]) {
            pc = 0x1c636;
            break;
        }
        if (memory[ds*16 + 0x480a] == 0x00) {
            pc = 0x1c639;
            break;
        }
    case 0x1c632:
        memory[ds*16 + 0x480a] = r8[cl];
    case 0x1c636:
        r8[cl] = 0;
        return;
    case 0x1c639:
        memory[ds*16 + 0x4809] = 0x0f;
    case 0x1c63e:
        memory[ds*16 + 0x480a] = r8[cl];
        return;
    } while (1);
}
function* sub_1c750() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1c750;
        break;
    case 0x1b0dd:
        yield* sub_1ba4f();
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al]) {
            pc = 0x1b10f;
            break;
        }
        yield* sub_1baf1();
        yield* sub_1bb74();
        yield* sub_1b970();
        yield* sub_1bcf0();
        yield* sub_1b1aa();
        if (!(r8[ah] & 0x01)) {
            pc = 0x1b100;
            break;
        }
        r8[bl] = 0x31;
        yield* sub_1b1d9();
    case 0x1b100:
        if (!(r8[ah] & 0x02)) {
            pc = 0x1b10a;
            break;
        }
        r8[bl] = 0x32;
        yield* sub_1b1d9();
    case 0x1b10a:
        yield* sub_1b29e();
        pc = 0x1b0dd;
        break;
    case 0x1b10f:
        r8[al] = 0;
        memory[ds*16 + 0x0493] = r8[al];
        memory[ds*16 + 0x0494] = r8[al];
        memory[ds*16 + 0x0a4d] = 0x01;
    case 0x1b11c:
        yield* sub_1b4f0();
        pc = 0x1b0dd;
        break;
    case 0x1c750:
        r8[ch] = 0;
    case 0x1c752:
        r8[dh] = memory[cs*16 + 0x325a];
        if (!r8[dh])
            {
            yield* sync();
            pc = 0x1c752;
            break;
        }
        if (r8[dh] <= 0x08) {
            pc = 0x1c762;
            break;
        }
        r8[dh] = 0x08;
    case 0x1c762:
        memory[cs*16 + 0x325a] = r8[ch];
        memory[ds*16 + 0x48f0] = r8[dh];
        r8[cl] = r8[dh];
    case 0x1c76d:
        push(r16[cx]);
        si = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1c775:
        push(r16[cx]);
        r8[bl] = memory[ds*16 + si];
        r8[bh] = 0;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 18827));
        si += 0x000b;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c775;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c76d;
            break;
        }
        si = 0x4d69;
    case 0x1c78a:
        yield* sub_1c97a();
    case 0x1c78d:
        r8[bl] = memory[ds*16 + si];
        if (r8[bl] == 0xff) {
            pc = 0x1c7b3;
            break;
        }
        r8[bh] = 0;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 18875));
        si += 0x000b;
        if (memory[cs*16 + 0x3259] == 0x00) {
            pc = 0x1c78d;
            break;
        }
        memory[ds*16 + 0x48e2] = memory[ds*16 + 0x48e2] ^ 0x01;
        if (!memory[ds*16 + 0x48e2]) {
            pc = 0x1c78d;
            break;
        }
        memory[cs*16 + 0x3259] -= 1;
        pc = 0x1c78a;
        break;
    case 0x1c7b3:
        yield* sub_1fb2b();
        if (memory[ds*16 + 0x48e5] == 0x00) {
            pc = 0x1c7ca;
            break;
        }
        r8[al] = memory[ds*16 + 0x48e5];
        memory[ds*16 + 0x48e5] = 0x00;
        r8[al]--;
        yield* sub_1fb9b();
    case 0x1c7ca:
        memory[ds*16 + 0x48de] -= 1;
        if (memory[ds*16 + 0x48de] != 0) {
            pc = 0x1c7d5;
            break;
        }
        memory[ds*16 + 0x48da] = 0x00;
    case 0x1c7d5:
        if (memory[ds*16 + 0x0a4c] != 0x00) {
            pc = 0x1c7ec;
            break;
        }
        memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
        yield* sub_1fb85();
        memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
        yield* sub_1c9b6();
    case 0x1c7ec:
        yield* sub_1fb42();
        yield* sub_1c957();
        yield* sub_1c91e();
        if (memory[ds*16 + 0x00c7] == 0xff) {
            pc = 0x1c7fd;
            break;
        }
        return;
    case 0x1c7fd:
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
        if (!(memory[ds*16 + 0x049a] & 0x80)) {
            pc = 0x1c819;
            break;
        }
        r16[ax] = pop();
        memory[ds*16 + 0x0a4a] = r8[al];
        memory[ds*16 + 0x049a] = r8[al];
        r16[ax] = pop();
        memory[ds*16 + 0x0284] = r8[al];
        r8[al] = memory[ds*16 + 0x0282];
        memory[cs*16 + 0x325b] = r8[al];
    case 0x1c819:
        r8[dl] = 0;
        memory[ds*16 + 0x47e1] = r8[dl];
        yield* sub_1fb90();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        pc = 0x1b11c;
        break;
        return;
    } while (1);
}
function* sub_1c78d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1c78d;
        break;
    case 0x1b0dd:
        yield* sub_1ba4f();
        r8[al] = memory[ds*16 + 0x00c7];
        if (r8[al]) {
            pc = 0x1b10f;
            break;
        }
        yield* sub_1baf1();
        yield* sub_1bb74();
        yield* sub_1b970();
        yield* sub_1bcf0();
        yield* sub_1b1aa();
        if (!(r8[ah] & 0x01)) {
            pc = 0x1b100;
            break;
        }
        r8[bl] = 0x31;
        yield* sub_1b1d9();
    case 0x1b100:
        if (!(r8[ah] & 0x02)) {
            pc = 0x1b10a;
            break;
        }
        r8[bl] = 0x32;
        yield* sub_1b1d9();
    case 0x1b10a:
        yield* sub_1b29e();
        pc = 0x1b0dd;
        break;
    case 0x1b10f:
        r8[al] = 0;
        memory[ds*16 + 0x0493] = r8[al];
        memory[ds*16 + 0x0494] = r8[al];
        memory[ds*16 + 0x0a4d] = 0x01;
    case 0x1b11c:
        yield* sub_1b4f0();
        pc = 0x1b0dd;
        break;
    case 0x1c78a:
        yield* sub_1c97a();
    case 0x1c78d:
        r8[bl] = memory[ds*16 + si];
        if (r8[bl] == 0xff) {
            pc = 0x1c7b3;
            break;
        }
        r8[bh] = 0;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 18875));
        si += 0x000b;
        if (memory[cs*16 + 0x3259] == 0x00) {
            pc = 0x1c78d;
            break;
        }
        memory[ds*16 + 0x48e2] = memory[ds*16 + 0x48e2] ^ 0x01;
        if (!memory[ds*16 + 0x48e2]) {
            pc = 0x1c78d;
            break;
        }
        memory[cs*16 + 0x3259] -= 1;
        pc = 0x1c78a;
        break;
    case 0x1c7b3:
        yield* sub_1fb2b();
        if (memory[ds*16 + 0x48e5] == 0x00) {
            pc = 0x1c7ca;
            break;
        }
        r8[al] = memory[ds*16 + 0x48e5];
        memory[ds*16 + 0x48e5] = 0x00;
        r8[al]--;
        yield* sub_1fb9b();
    case 0x1c7ca:
        memory[ds*16 + 0x48de] -= 1;
        if (memory[ds*16 + 0x48de] != 0) {
            pc = 0x1c7d5;
            break;
        }
        memory[ds*16 + 0x48da] = 0x00;
    case 0x1c7d5:
        if (memory[ds*16 + 0x0a4c] != 0x00) {
            pc = 0x1c7ec;
            break;
        }
        memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
        yield* sub_1fb85();
        memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
        yield* sub_1c9b6();
    case 0x1c7ec:
        yield* sub_1fb42();
        yield* sub_1c957();
        yield* sub_1c91e();
        if (memory[ds*16 + 0x00c7] == 0xff) {
            pc = 0x1c7fd;
            break;
        }
        return;
    case 0x1c7fd:
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
        if (!(memory[ds*16 + 0x049a] & 0x80)) {
            pc = 0x1c819;
            break;
        }
        r16[ax] = pop();
        memory[ds*16 + 0x0a4a] = r8[al];
        memory[ds*16 + 0x049a] = r8[al];
        r16[ax] = pop();
        memory[ds*16 + 0x0284] = r8[al];
        r8[al] = memory[ds*16 + 0x0282];
        memory[cs*16 + 0x325b] = r8[al];
    case 0x1c819:
        r8[dl] = 0;
        memory[ds*16 + 0x47e1] = r8[dl];
        yield* sub_1fb90();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        pc = 0x1b11c;
        break;
        return;
    } while (1);
}
function* sub_1c7fc() {
}
function* sub_1c831() {
    yield* sub_1ca4a();
    yield* sub_1ce96();
    if (memory[ds*16 + si] == 0x00)
        return;
    yield* sub_1ca4a();
    yield* sub_1ce96();
}
function* sub_1c843() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca4a();
        pc = 0x1ce65;
        break;
    case 0x1ce65:
        r8[ah] = memory[ds*16 + si + 4];
        if (r8[ah] < 0xb0)
            return;
        if (r8[ah] >= 0xb6) {
            pc = 0x1ce92;
            break;
        }
        r8[al] = memory[ds*16 + si + 2];
        r8[bl] = memory[ds*16 + 0x48d8];
        flags.carry = r8[bl] < 0x10;
        r8[bl] -= 0x10;
        if (!flags.carry) {
            pc = 0x1ce80;
            break;
        }
        r8[bl] = 0x04;
    case 0x1ce80:
        if (r8[al] < r8[bl])
            return;
        r8[bl] += 0x31;
        if (r8[al] > r8[bl])
            return;
        yield* sub_1e01c();
        r16[cx] = pop();
        r16[cx] = pop();
        r16[cx] = pop();
        return;
    case 0x1ce92:
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_1c849() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca54();
        pc = 0x1d2a2;
        break;
    case 0x1d2a2:
        yield* sub_1d2c8();
        yield* sub_1d2e9();
        r8[ah] = memory[ds*16 + si + 2];
        if (r8[ah] < 0x08) {
            pc = 0x1d2bf;
            break;
        }
        if (r8[ah] > 0xc8) {
            pc = 0x1d2b6;
            break;
        }
        return;
    case 0x1d2b6:
        memory[ds*16 + si + 6] = 0xff;
        memory[ds*16 + si + 2] = 0xc8;
        return;
    case 0x1d2bf:
        memory[ds*16 + si + 6] = 0x01;
        memory[ds*16 + si + 2] = 0x08;
        return;
    } while (1);
}
function* sub_1c84f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca4d();
        pc = 0x1d40d;
        break;
    case 0x1d40d:
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] < 0xb4)
            return;
        if (r8[al] < 0xba) {
            pc = 0x1d41c;
            break;
        }
        if (r8[al] > 0xc1) {
            pc = 0x1d436;
            break;
        }
    case 0x1d41c:
        r8[al] = memory[ds*16 + si + 2];
        r8[al] += 0x0e;
        if (r8[al] < memory[ds*16 + 0x48d8]) {
            pc = 0x1d443;
            break;
        }
        r8[al] = memory[ds*16 + 0x48d8];
        r8[al] += memory[ds*16 + 0x48d1];
        if (r8[al] < memory[ds*16 + si + 2])
            return;
        yield* sub_1da8d();
    case 0x1d436:
        memory[ds*16 + 0x48eb] -= 1;
        memory[ds*16 + si] = 0x00;
        r8[bl] = memory[ds*16 + si + 9];
        r8[bl] &= 0xf8;
    case 0x1d443:
        di = 0x48f2;
        r16[cx] = 0x0004;
    case 0x1d449:
        if (memory[ds*16 + di] == r8[bl]) {
            pc = 0x1d450;
            break;
        }
        di++;
        if (--r16[cx]) {
            pc = 0x1d449;
            break;
        }
    case 0x1d450:
        memory[ds*16 + di] = 0x00;
        return;
    } while (1);
}
function* sub_1c855() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca5b();
        pc = 0x1d326;
        break;
    case 0x1d326:
        yield* sub_1d330();
        yield* sub_1d37e();
        yield* sub_1d3a1();
        return;
    } while (1);
}
function* sub_1c85b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca4d();
        pc = 0x1d1fb;
        break;
    case 0x1d130:
        if (r8[al] >= 0x04) {
            pc = 0x1d141;
            break;
        }
        yield* sub_1dd10();
        if (r8[al] == 0x01) {
            pc = 0x1d15e;
            break;
        }
        memory[ds*16 + r16[bx] + 1183] -= 1;
        if (memory[ds*16 + r16[bx] + 1183] != 0) {
            pc = 0x1d15e;
            break;
        }
    case 0x1d141:
        push(r16[ax]);
        yield* sub_1d94d();
        r16[ax] = pop();
        yield* sub_1d250();
        r8[ch] &= 0xf0;
        memory[ds*16 + r16[bx] + 1417] = r8[ch];
        push(r16[bx]);
        r16[bx] = 0x0202;
        yield* sub_1f0d2();
        r16[bx] = pop();
        yield* sub_1d6db();
        yield* sub_1d6f6();
    case 0x1d15e:
        return;
    case 0x1d1fb:
        r8[bl] = memory[ds*16 + si + 4];
        if (r8[bl] < 0x0a) {
            pc = 0x1d224;
            break;
        }
        r8[bh] = 0;
        r8[al] = memory[ds*16 + si + 2];
        yield* sub_1d484();
        if (flags.carry) {
            pc = 0x1d217;
            break;
        }
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[ch] = r8[al];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1d21e;
            break;
        }
    case 0x1d217:
        yield* sub_1d15f();
        yield* sub_1d228();
        return;
    case 0x1d21e:
        memory[ds*16 + si] = 0x00;
        pc = 0x1d130;
        break;
    case 0x1d224:
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_1c861() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        if (memory[ds*16 + 0x0493] != 0x21) {
            pc = 0x1c86f;
            break;
        }
        r16[bx] = 0x010f;
        yield* sub_1f0d2();
    case 0x1c86f:
        memory[ds*16 + si] = 0x00;
        r16[bx] = 0x010e;
        yield* sub_1f0d2();
        yield* sub_1e093();
        if (!(memory[cs*16 + 0x325b] & 0x10)) {
            pc = 0x1c889;
            break;
        }
        r16[cx] = 0x008c;
        yield* sub_1e307();
    case 0x1c889:
        yield* sub_1dd5e();
        yield* sub_1ddb5();
        yield* sub_1dd99();
        yield* sub_1ddec();
        yield* sub_1de31();
        r16[cx] = 0x0014;
        yield* sub_1e307();
        yield* sub_1dd5e();
        r16[cx] = 0x0014;
        yield* sub_1e307();
        yield* sub_1dd99();
        yield* sub_1e105();
        r8[ch] = 0;
        memory[cs*16 + 0x3259] = r8[ch];
        memory[cs*16 + 0x325a] = r8[ch];
        if (!(memory[cs*16 + 0x325b] & 0x10)) {
            pc = 0x1c8c7;
            break;
        }
        r16[cx] = 0x001e;
        yield* sub_1e307();
    case 0x1c8c7:
        yield* sub_1c3fa();
        memory[ds*16 + 0x47e1] = 0x01;
        if (memory[ds*16 + 0x0493] != 0x21) {
            pc = 0x1c8dc;
            break;
        }
        r16[bx] = 0x010a;
        yield* sub_1f0d2();
    case 0x1c8dc:
        si = pop();
        return;
    } while (1);
}
function* sub_1c8de() {
    r16[ax] = 0;
    memory16set(ds, 0x48e3, 0x0001);
    memory[ds*16 + 0x4d69] = r8[al];
    memory[ds*16 + 0x4d74] = 0xff;
    memory[ds*16 + 0x4988] = r8[al];
    memory16set(ds, 0x4989, 0x49f9);
}
function* sub_1c8f8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1c8ff:
        r8[al] = memory[ds*16 + di];
        if (!r8[al]) {
            pc = 0x1c912;
            break;
        }
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1c8ff;
            break;
        }
        memory16set(ds, 0x48e3, memory16get(ds, 0x48e3) + 1);
        memory[ds*16 + di + 11] = 0xff;
    case 0x1c912:
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[cx] = 0x000b;
        rep_movsb_data_data_forward();
        es = pop();
        return;
    } while (1);
}
function* sub_1c912() {
    push(es);
    r16[ax] = ds;
    es = r16[ax];
    r16[cx] = 0x000b;
    rep_movsb_data_data_forward();
    es = pop();
}
function* sub_1c91e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ch] = 0;
        r8[cl] = memory[ds*16 + 0x4988];
        if (r16[cx] == 0)
            return;
        memory[ds*16 + 0x4988] = r8[ch];
        si = 0x49f9;
        memory16set(ds, 0x4989, si);
    case 0x1c931:
        push(r16[cx]);
        yield* sub_1c8f8();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c931;
            break;
        }
        return;
    } while (1);
}
function* sub_1c939() {
    push(si);
    si = r16[bx];
    di = memory16get(ds, 0x4989);
    r16[bx] = di;
    push(es);
    r16[ax] = ds;
    es = r16[ax];
    r16[cx] = 0x000b;
    rep_movsb_data_data_forward();
    es = pop();
    memory16set(ds, 0x4989, di);
    memory[ds*16 + 0x4988] += 1;
    si = pop();
}
function* sub_1c957() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16 + 0x4985];
        r8[ch] = 0;
        if (r16[cx] == 0)
            return;
        si = 0x5291;
        memory16set(ds, 0x4986, si);
    case 0x1c966:
        push(r16[cx]);
        r8[bl] = memory[ds*16 + si];
        r8[bh] = r8[ch];
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 18923));
        si += 0x0003;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1c966;
            break;
        }
        memory[ds*16 + 0x4985] = r8[ch];
        return;
    } while (1);
}
function* sub_1c97a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x0a4c] != 0x00)
            return;
        push(si);
        push(r16[cx]);
        memory[ds*16 + 0x586f] -= 1;
        if (memory[ds*16 + 0x586f] != 0) {
            pc = 0x1c9b3;
            break;
        }
        r8[al] = memory[ds*16 + 0x5870];
        memory[ds*16 + 0x586f] = r8[al];
        si = 0x4d5e;
        if (memory[ds*16 + si] != 0x06) {
            pc = 0x1c9ad;
            break;
        }
        r16[cx] = memory16get(ds, 0x586d);
    case 0x1c99b:
        push(r16[cx]);
        yield* sub_1ca4a();
        yield* sub_1ce96();
        r16[cx] = pop();
        if (memory[ds*16 + si] == 0x00) {
            pc = 0x1c9ad;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1c99b;
            break;
        }
        yield* sub_1caa4();
    case 0x1c9ad:
        yield* sub_1c9c5();
        yield* sub_1ccfc();
    case 0x1c9b3:
        r16[cx] = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_1c9b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x4d5e;
        if (memory[ds*16 + si] != 0x06) {
            pc = 0x1c9c1;
            break;
        }
        yield* sub_1caa4();
    case 0x1c9c1:
        yield* sub_1ccfc();
        return;
    } while (1);
}
function* sub_1c9c5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48df] == 0x01) {
            pc = 0x1ca49;
            break;
        }
        r8[bl] = memory[ds*16 + 0x48d8];
        memory[ds*16 + 0x48d9] = r8[bl];
        if (memory[ds*16 + 0x48e0] != 0x02) {
            pc = 0x1c9e3;
            break;
        }
        r8[cl] = 0;
        r8[bl] += memory[ds*16 + 0x48dd];
        pc = 0x1c9e6;
        break;
    case 0x1c9e3:
        yield* sub_1c1ac();
    case 0x1c9e6:
        memory[ds*16 + 0x48d8] = r8[bl];
        if (memory[ds*16 + 0x48d9] == r8[bl]) {
            pc = 0x1c9f5;
            break;
        }
        memory[ds*16 + 0x48d6] = 0x00;
    case 0x1c9f5:
        memory[ds*16 + 0x48da] = memory[ds*16 + 0x48da] | r8[cl];
        if (!r8[cl]) {
            pc = 0x1ca02;
            break;
        }
        memory[ds*16 + 0x48de] = 0x04;
    case 0x1ca02:
        if (memory[ds*16 + 0x48cf] != 0x0f) {
            pc = 0x1ca10;
            break;
        }
        if (!r8[cl]) {
            pc = 0x1ca10;
            break;
        }
        yield* sub_1df78();
    case 0x1ca10:
        if (memory[ds*16 + 0x48e0] == 0x00) {
            pc = 0x1ca49;
            break;
        }
        if (r8[bl] > 0x09) {
            pc = 0x1ca28;
            break;
        }
        memory[ds*16 + 0x0494] = 0x00;
        memory[ds*16 + 0x48dd] = 0xff;
        pc = 0x1ca3b;
        break;
    case 0x1ca28:
        r8[bl] += memory[ds*16 + 0x48d1];
        if (r8[bl] < 0xd0) {
            pc = 0x1ca49;
            break;
        }
        memory[ds*16 + 0x48dd] = 0x01;
        memory[ds*16 + 0x0494] = 0x01;
    case 0x1ca3b:
        memory[ds*16 + 0x48df] = 0x01;
        r16[ax] = 0x1000;
        yield* sub_1b130();
        pc = 0x1e10f;
        break;
    case 0x1ca49:
        return;
    case 0x1e10f:
        r16[ax] = pop();
        r16[cx] = pop();
        si = pop(); assert(si);
        yield* sub_1c78d();
        yield* sub_1d7c8();
        yield* sub_1e12b();
        yield* sub_1c750();
        yield* sub_1c750();
        yield* sub_1e14e();
        memory[ds*16 + 0x48df] = 0x00;
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1ca4a() {
    yield* sub_1ca54();
    r16[ax] = memory16get(ds, si + 7);
    memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[ax]);
}
function* sub_1ca4d() {
    r16[ax] = memory16get(ds, si + 7);
    memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[ax]);
}
function* sub_1ca54() {
    r16[ax] = memory16get(ds, si + 5);
    memory16set(ds, si + 1, memory16get(ds, si + 1) + r16[ax]);
}
function* sub_1ca5b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca85();
        r16[ax] = memory16get(ds, r16[bx] + 1);
        r16[dx] = memory16get(ds, r16[bx] + 3);
        memory16set(ds, si + 1, memory16get(ds, si + 1) + r16[ax]);
        memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[dx]);
        memory[ds*16 + si + 6] -= 1;
        if (memory[ds*16 + si + 6] != 0)
            return;
        r16[bx] += 0x0005;
        r8[cl]++;
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al]) {
            pc = 0x1ca7e;
            break;
        }
        r8[cl] = 0x00;
        r8[al] = memory[ds*16 + di];
    case 0x1ca7e:
        memory[ds*16 + si + 5] = r8[cl];
        memory[ds*16 + si + 6] = r8[al];
        return;
    } while (1);
}
function* sub_1ca6f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] += 0x0005;
        r8[cl]++;
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al]) {
            pc = 0x1ca7e;
            break;
        }
        r8[cl] = 0x00;
        r8[al] = memory[ds*16 + di];
    case 0x1ca7e:
        memory[ds*16 + si + 5] = r8[cl];
        memory[ds*16 + si + 6] = r8[al];
        return;
    } while (1);
}
function* sub_1ca85() {
    r8[bh] = 0;
    r8[ch] = r8[bh];
    r8[ah] = r8[bh];
    r8[bl] = memory[ds*16 + si + 7];
    r8[bl] <<= 1;
    r16[bx] = memory16get(ds, r16[bx] + 21737);
    di = r16[bx];
    r8[cl] = memory[ds*16 + si + 5];
    r8[al] = r8[cl];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[cx];
    r16[bx] += r16[ax];
}
function* sub_1caa4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = 0x17;
        if (memory[ds*16 + 0x48e9] != 0x00) {
            pc = 0x1caaf;
            break;
        }
        r8[bl] = 0x16;
    case 0x1caaf:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb90();
        yield* sub_1fb94();
        yield* sub_1fb46();
        si = pop();
        return;
    } while (1);
}
function* sub_1cac7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1caef;
            break;
        }
        r8[bl] = memory[ds*16 + si + 9];
        if (r8[bl] != 0x03) {
            pc = 0x1caf0;
            break;
        }
        memory[ds*16 + si + 10] = 0x01;
        r8[tl] = memory[ds*16 + si + 3];
        memory[ds*16 + si + 3] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1caef;
            break;
        }
        memory[ds*16 + si + 1] -= 1;
        if (memory[ds*16 + si + 1] == 0) {
            pc = 0x1caec;
            break;
        }
        memory[ds*16 + si + 3] = 0x5a;
        pc = 0x1df11;
        break;
    case 0x1caec:
        memory[ds*16 + si + 9] += 1;
    case 0x1caef:
        return;
    case 0x1caf0:
        r8[bl]++;
        memory[ds*16 + si + 9] = r8[bl];
        memory[ds*16 + si + 10] = 0x1e;
        if (r8[bl] < 0x05) {
            pc = 0x1cb09;
            break;
        }
        r8[al] = 0x08;
        r8[al] -= r8[bl];
        if (r8[al] != 0) {
            pc = 0x1cb07;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1cb07:
        r8[tl] = r8[bl];
        r8[bl] = r8[al];
        r8[al] = r8[tl];
    case 0x1cb09:
        r8[bh] = 0;
        r16[bx] += 0x0012;
        yield* sub_1d6c9();
        r16[cx] = 0x0068;
        r16[dx] = 0x0065;
        push(si);
        yield* sub_1fb52();
        si = pop();
        return;
    case 0x1df11:
        r16[bx] = 0x5944;
        r8[ah] = 0;
        r8[al] = memory[ds*16 + 0x48d8];
        r16[cx] = 0x0068;
        r16[ax] -= r16[cx];
        memory16set(ds, r16[bx] + 5, r16[ax]);
        yield* sub_1c939();
        return;
    } while (1);
}
function* sub_1cb1d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1cb1d;
        break;
    case 0x1cb11:
        r16[cx] = 0x0068;
        r16[dx] = 0x0065;
        push(si);
        yield* sub_1fb52();
        si = pop();
        return;
    case 0x1cb1d:
        r16[bx] = memory16get(ds, si + 1);
        pc = 0x1cb11;
        break;
        return;
    } while (1);
}
function* sub_1cb22() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0)
            return;
        memory[ds*16 + si + 10] = 0x0a;
        memory[ds*16 + si + 9] += 1;
        r8[bl] = memory[ds*16 + si + 9];
        if (r8[bl] != 0x03) {
            pc = 0x1cb4d;
            break;
        }
        r8[al] = memory[ds*16 + 0x48ec];
        if (r8[al] < memory[ds*16 + 0x48ed]) {
            pc = 0x1cb4a;
            break;
        }
        r8[bl] += 0x02;
        memory[ds*16 + si + 9] = r8[bl];
        pc = 0x1cb4d;
        break;
    case 0x1cb4a:
        yield* sub_1df25();
    case 0x1cb4d:
        push(r16[bx]);
        r16[bx] = si;
        yield* sub_1d6c5();
        r16[bx] = pop();
        if (r8[bl] < 0x04) {
            pc = 0x1cb6b;
            break;
        }
        r8[al] = 0x06;
        r8[al] -= r8[bl];
        if (r8[al] != 0) {
            pc = 0x1cb69;
            break;
        }
        memory[ds*16 + si] = 0x00;
        r8[bh] = memory[ds*16 + si + 6];
        memory[ds*16 + 0x4937] = memory[ds*16 + 0x4937] & r8[bh];
    case 0x1cb69:
        r8[bl] = r8[al];
    case 0x1cb6b:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[bl] += 0x18;
        r8[bl] += memory[ds*16 + si + 5];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb52();
        si = pop();
        return;
    } while (1);
}
function* sub_1cb54() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[bl] < 0x04) {
            pc = 0x1cb6b;
            break;
        }
        r8[al] = 0x06;
        r8[al] -= r8[bl];
        if (r8[al] != 0) {
            pc = 0x1cb69;
            break;
        }
        memory[ds*16 + si] = 0x00;
        r8[bh] = memory[ds*16 + si + 6];
        memory[ds*16 + 0x4937] = memory[ds*16 + 0x4937] & r8[bh];
    case 0x1cb69:
        r8[bl] = r8[al];
    case 0x1cb6b:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[bl] += 0x18;
        r8[bl] += memory[ds*16 + si + 5];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb52();
        si = pop();
        return;
    } while (1);
}
function* sub_1cb83() {
    push(si);
    si = memory16get(ds, si + 1);
    r8[bl] = memory[ds*16 + si + 9];
    yield* sub_1cb54();
    si = pop();
}
function* sub_1cb8f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0)
            return;
        memory[ds*16 + si + 10] = 0x0f;
        memory[ds*16 + si + 9] += 1;
        r8[bl] = memory[ds*16 + si + 9];
        if (r8[bl] != 0x04) {
            pc = 0x1cba9;
            break;
        }
        yield* sub_1df2b();
    case 0x1cba9:
        if (r8[bl] < 0x05) {
            pc = 0x1cbb9;
            break;
        }
        r8[al] = 0x08;
        r8[al] -= r8[bl];
        if (r8[al] != 0) {
            pc = 0x1cbb7;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1cbb7:
        r8[tl] = r8[bl];
        r8[bl] = r8[al];
        r8[al] = r8[tl];
    case 0x1cbb9:
        r8[bh] = 0;
        r16[bx] += 0x0006;
        r16[cx] = memory16get(ds, si + 1);
        r16[dx] = 0x0003;
        push(si);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_1fb4c();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        yield* sub_1fb46();
        si = pop();
        return;
    } while (1);
}
function* sub_1cbd3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16 + si + 9];
        r8[bl] = memory[ds*16 + si + 7];
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1cc24;
            break;
        }
        r8[al] = memory[ds*16 + si + 8];
        r8[ah] = r8[al];
        r8[al] &= 0x0f;
        if (!(r8[ah] & 0x20)) {
            pc = 0x1cc05;
            break;
        }
        r8[cl]++;
        if (r8[cl] != r8[al]) {
            pc = 0x1cc1d;
            break;
        }
        if (r8[ah] & 0x10) {
            pc = 0x1cbfc;
            break;
        }
        r8[cl] = 0x00;
        pc = 0x1cc1d;
        break;
    case 0x1cbfc:
        r8[cl] -= 0x02;
        memory[ds*16 + si + 8] = memory[ds*16 + si + 8] ^ 0x20;
        pc = 0x1cc1d;
        break;
    case 0x1cc05:
        r8[cl]--;
        if (r8[cl] != 0xff) {
            pc = 0x1cc1d;
            break;
        }
        if (r8[ah] & 0x10) {
            pc = 0x1cc17;
            break;
        }
        r8[cl] = r8[al];
        r8[cl]--;
        pc = 0x1cc1d;
        break;
    case 0x1cc17:
        r8[cl] = 0x01;
        memory[ds*16 + si + 8] = memory[ds*16 + si + 8] ^ 0x20;
    case 0x1cc1d:
        memory[ds*16 + si + 9] = r8[cl];
        memory[ds*16 + si + 10] = 0x0a;
    case 0x1cc24:
        r8[bh] = 0;
        r8[bl] = memory[ds*16 + r16[bx] + 18791];
        r8[bl] += r8[cl];
        r8[bl] += 0x7a;
        pc = 0x1cca0;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    } while (1);
}
function* sub_1cc31() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16 + si + 9];
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1cc4e;
            break;
        }
        memory[ds*16 + si + 10] = 0x06;
        r8[bl]++;
        if (r8[bl] != 0x07) {
            pc = 0x1cc4b;
            break;
        }
        memory[ds*16 + si] = 0x00;
        return;
    case 0x1cc4b:
        memory[ds*16 + si + 9] = r8[bl];
    case 0x1cc4e:
        r8[bl] += 0xb3;
        pc = 0x1cca0;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    } while (1);
}
function* sub_1cc53() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16 + si + 9];
        if (r8[bl] >= 0x68) {
            pc = 0x1cc67;
            break;
        }
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1cc90;
            break;
        }
        memory[ds*16 + si + 10] = 0x05;
    case 0x1cc67:
        r8[bl]++;
        if (r8[bl] <= 0x68) {
            pc = 0x1cc85;
            break;
        }
        if (r8[bl] != 0x70) {
            pc = 0x1cc75;
            break;
        }
        r8[bl] = 0x68;
    case 0x1cc75:
        memory[ds*16 + si + 9] = r8[bl];
        r8[bl] &= 0x07;
        r8[bl]++;
        r8[bl] <<= 1;
        r8[bl] <<= 1;
        r8[bl] <<= 1;
        pc = 0x1cc90;
        break;
    case 0x1cc85:
        if (r8[bl] & 0x07) {
            pc = 0x1cc8d;
            break;
        }
        r8[bl] -= 0x08;
    case 0x1cc8d:
        memory[ds*16 + si + 9] = r8[bl];
    case 0x1cc90:
        r8[bl] += 0x10;
        pc = 0x1cca0;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    } while (1);
}
function* sub_1cc95() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = 0x17;
        if (memory[ds*16 + 0x48e9] != 0x00) {
            pc = 0x1cca0;
            break;
        }
        r8[bl] = 0x16;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    } while (1);
}
function* sub_1ccb5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1ccb5;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    case 0x1ccb5:
        if (memory[ds*16 + si + 10] == 0x00) {
            pc = 0x1cccd;
            break;
        }
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1cccd;
            break;
        }
        memory[ds*16 + si + 10] = 0x00;
        r8[al] = memory[ds*16 + si + 9];
        memory[ds*16 + si + 1] = r8[al];
    case 0x1cccd:
        r8[bl] = memory[ds*16 + si + 1];
        r8[bl] &= 0x0f;
        r8[bl] += 0x0a;
        pc = 0x1cca0;
        break;
        return;
    } while (1);
}
function* sub_1ccd8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1ccd8;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    case 0x1ccd8:
        r8[bl] = 0x78;
        pc = 0x1cca0;
        break;
        return;
    } while (1);
}
function* sub_1ccdc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1ccdc;
        break;
    case 0x1cca0:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[dh] = r8[bh];
        r8[cl] = memory[ds*16 + si + 2];
        r8[dl] = memory[ds*16 + si + 4];
        push(si);
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        si = pop();
        return;
    case 0x1ccdc:
        r8[bl] = memory[ds*16 + si + 9];
        r8[al] = memory[ds*16 + 0x48f0];
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1ccf7;
            break;
        }
        memory[ds*16 + si + 10] = 0x06;
        r8[bl]++;
        if (r8[bl] != 0x04) {
            pc = 0x1ccf4;
            break;
        }
        r8[bl] = 0;
    case 0x1ccf4:
        memory[ds*16 + si + 9] = r8[bl];
    case 0x1ccf7:
        r8[bl] += 0xc4;
        pc = 0x1cca0;
        break;
        return;
    } while (1);
}
function* sub_1ccfc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0;
        r8[al] = memory[ds*16 + 0x5870];
        r8[tl] = memory[ds*16 + 0x48d7];
        memory[ds*16 + 0x48d7] -= r8[al];
        r8[al] = memory[ds*16 + 0x48d4];
        if (r8s[tl] - r8s[al] > 0) {
            pc = 0x1cd1c;
            break;
        }
        memory[ds*16 + 0x48d7] += 0x14;
        r8[al]++;
        if (r8[al] < memory[ds*16 + 0x48d2]) {
            pc = 0x1cd19;
            break;
        }
        r8[al] = 0;
    case 0x1cd19:
        memory[ds*16 + 0x48d4] = r8[al];
    case 0x1cd1c:
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r8[bl] = memory[ds*16 + 0x48cf];
        if (r8[bl] == 0x13) {
            pc = 0x1cd65;
            break;
        }
    case 0x1cd29:
        r8[bl] += 0xc9;
        r16[bx] += r16[ax];
        if (r8[al] != 0x03) {
            pc = 0x1cd41;
            break;
        }
        memory[ds*16 + 0x48cf] = 0x0f;
        memory[ds*16 + 0x48d2] = 0x01;
        memory[ds*16 + 0x48d4] = 0x00;
    case 0x1cd41:
        r8[cl] = memory[ds*16 + 0x48d8];
        if (memory[ds*16 + 0x48d6] != 0x00) {
            pc = 0x1cd57;
            break;
        }
        memory[ds*16 + 0x48d6] = 0x01;
        yield* sub_1fb85();
        yield* sub_1fb89();
    case 0x1cd57:
        r16[dx] = 0x00bb;
        yield* sub_1fb46();
        return;
    case 0x1cd5e:
        r8[bl] = 0x03;
        r8[al] = memory[ds*16 + 0x48d4];
        pc = 0x1cd29;
        break;
    case 0x1cd65:
        r8[al] = memory[ds*16 + 0x48db];
        r8[tl] = r8[al];
        r8[al] -= memory[ds*16 + 0x48d8];
        if (r8[al] == 0) {
            pc = 0x1cd5e;
            break;
        }
        memory[ds*16 + 0x48d6] = 0x00;
        r8[dh] = 0xff;
        if (r8[tl] > memory[ds*16 + 0x48d8]) {
            pc = 0x1cd7d;
            break;
        }
        r8[al] = -r8[al];
        r8[dh] = 0x01;
        r8[bl] = 0x21;
    case 0x1cd7d:
        if (r8[al] < 0x03) {
            pc = 0x1cd5e;
            break;
        }
        memory[ds*16 + 0x48d4] = 0x00;
        memory[ds*16 + 0x48dc] -= 1;
        if (memory[ds*16 + 0x48dc] != 0) {
            pc = 0x1cd95;
            break;
        }
        memory[ds*16 + 0x48dc] = 0x02;
        memory[ds*16 + 0x48db] += r8[dh];
    case 0x1cd95:
        if (r8[al] <= 0x3a) {
            pc = 0x1cdae;
            break;
        }
        r8[ah] = memory[ds*16 + 0x48d8];
        r8[al] = 0x3a;
        if (!(r8[dh] & 0x80)) {
            pc = 0x1cda8;
            break;
        }
        r8[ah] += r8[al];
        pc = 0x1cdaa;
        break;
    case 0x1cda8:
        r8[ah] -= r8[al];
    case 0x1cdaa:
        memory[ds*16 + 0x48db] = r8[ah];
    case 0x1cdae:
        r8[al] >>= 1;
        r8[al] >>= 1;
        if (!r8[al]) {
            pc = 0x1cdb8;
            break;
        }
        r8[al]--;
    case 0x1cdb8:
        r8[bl] += r8[al];
        r8[cl] = memory[ds*16 + 0x48d8];
        if (r8[dh] & 0x80) {
            pc = 0x1cdcc;
            break;
        }
        r8[cl] -= r8[al];
        r8[cl] -= r8[al];
        r8[cl] -= r8[al];
        r8[cl] -= 0x02;
    case 0x1cdcc:
        r8[bl] += 0xc9;
        yield* sub_1cd4c();
        return;
    } while (1);
}
function* sub_1cd4c() {
    memory[ds*16 + 0x48d6] = 0x01;
    yield* sub_1fb85();
    yield* sub_1fb89();
    r16[dx] = 0x00bb;
    yield* sub_1fb46();
}
function* sub_1cdd3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + si] = 0x00;
        if (memory[ds*16 + 0x002e] == 0x00) {
            pc = 0x1cde0;
            break;
        }
        yield* sub_1bf26();
    case 0x1cde0:
        r16[ax] = memory16get(ds, si + 5);
        r8[cl] = memory[ds*16 + si + 7];
        yield* sub_1da36();
        r16[bx] = memory16get(ds, si + 1);
        r16[cx] = memory16get(ds, si + 3);
        r8[al] = 0x0f;
        push(si);
        si = 0x495d;
        yield* sub_1fb75();
        si = pop();
        return;
    } while (1);
}
function* sub_1cdef() {
    r8[al] = 0x0f;
    push(si);
    si = 0x495d;
    yield* sub_1fb75();
    si = pop();
}
function* sub_1cdfa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x48f0);
        r16[tx] = memory16get(ds, si + 5);
        memory16set(ds, si + 5, memory16get(ds, si + 5) - r16[ax]);
        if (r16s[tx] - r16s[ax] > 0) {
            pc = 0x1ce1d;
            break;
        }
        memory16set(ds, si + 5, 0x7d00);
        memory[ds*16 + 0x48e0] = 0x02;
        memory[ds*16 + 0x48dd] = 0xfe;
        if (memory[ds*16 + 0x48d8] < 0x64) {
            pc = 0x1ce1d;
            break;
        }
        memory[ds*16 + 0x48dd] = 0x02;
    case 0x1ce1d:
        r8[tl] = memory[ds*16 + si + 10];
        memory[ds*16 + si + 10] -= r8[al];
        if (r8s[tl] - r8s[al] > 0)
            return;
        memory[ds*16 + si + 10] = 0x02;
        r8[bl] = memory[ds*16 + si + 9];
        r8[bl]++;
        if (r8[bl] != 0x03) {
            pc = 0x1ce32;
            break;
        }
        r8[bl] = 0;
    case 0x1ce32:
        memory[ds*16 + si + 9] = r8[bl];
        push(si);
        r8[bl] += 0xba;
        r16[cx] = 0x0000;
        r16[dx] = 0x00a2;
        push(r16[bx]);
        yield* sub_1fb4c();
        r16[bx] = pop();
        r16[cx] = 0x0000;
        r16[dx] = 0x00a2;
        push(r16[bx]);
        yield* sub_1fb46();
        r16[bx] = pop();
        r16[cx] = 0x00d8;
        r16[dx] = 0x00a2;
        push(r16[bx]);
        yield* sub_1fb4c();
        r16[bx] = pop();
        r16[cx] = 0x00d8;
        r16[dx] = 0x00a2;
        yield* sub_1fb46();
        si = pop();
        return;
    } while (1);
}
function* sub_1ce35() {
    push(si);
    r8[bl] += 0xba;
    r16[cx] = 0x0000;
    r16[dx] = 0x00a2;
    push(r16[bx]);
    yield* sub_1fb4c();
    r16[bx] = pop();
    r16[cx] = 0x0000;
    r16[dx] = 0x00a2;
    push(r16[bx]);
    yield* sub_1fb46();
    r16[bx] = pop();
    r16[cx] = 0x00d8;
    r16[dx] = 0x00a2;
    push(r16[bx]);
    yield* sub_1fb4c();
    r16[bx] = pop();
    r16[cx] = 0x00d8;
    r16[dx] = 0x00a2;
    yield* sub_1fb46();
    si = pop();
}
function* sub_1ce96() {
    yield* sub_1cee6();
    yield* sub_1d04b();
    yield* sub_1d15f();
    yield* sub_1d1ae();
    yield* sub_1d105();
}
function* sub_1cebd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dh] = memory[ds*16 + si + 1];
        memory[ds*16 + si + 4] = 0xb3;
        pc = 0x1cffd;
        break;
    case 0x1cffd:
        r8[dl] = memory[ds*16 + 0x48d0];
        r8[cl] = r8[dl];
        r8[dl] >>= 1;
        r8[bl] = 0x01;
        if (r8s[dh] < r8s[dl]) {
            pc = 0x1d011;
            break;
        }
        r8[cl] -= r8[dh];
        r8[dh] = r8[cl];
        r8[bl]--;
    case 0x1d011:
        r8[dl] >>= 1;
        r8[dl] >>= 1;
        di = 0x4979;
        r16[cx] = 0x0004;
    case 0x1d01b:
        di += 0x0002;
        r8[tl] = r8[dh];
        r8[dh] -= r8[dl];
        if (r8s[tl] - r8s[dl] <= 0) {
            pc = 0x1d024;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1d01b;
            break;
        }
    case 0x1d024:
        r8[cl] = memory[ds*16 + di];
        r8[al] = memory[ds*16 + 0x48e8];
        mul8(r8[cl]);
        if (!r8[bl]) {
            pc = 0x1d031;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1d031:
        memory16set(ds, si + 5, r16[ax]);
        r8[dl] = memory[ds*16 + di + 1];
        r8[al] = memory[ds*16 + 0x48e8];
        mul8(r8[dl]);
        r16[ax] = -r16[ax];
        memory16set(ds, si + 7, r16[ax]);
        return;
    } while (1);
}
function* sub_1cee6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1cee6;
        break;
    case 0x1ca4d:
        r16[ax] = memory16get(ds, si + 7);
        memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[ax]);
        return;
    case 0x1cea6:
        if (memory[ds*16 + 0x48da] != 0x00) {
            pc = 0x1cebd;
            break;
        }
        memory[ds*16 + si + 10] -= 1;
        if (memory[ds*16 + si + 10] == 0) {
            pc = 0x1cebd;
            break;
        }
        r8[al] = memory[ds*16 + si + 1];
        r8[al] += memory[ds*16 + 0x48d8];
        memory[ds*16 + si + 2] = r8[al];
        return;
    case 0x1cebd:
        r8[dh] = memory[ds*16 + si + 1];
        memory[ds*16 + si + 4] = 0xb3;
        pc = 0x1cffd;
        break;
    case 0x1cec7:
        push(si);
        si = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1cecf:
        if (memory[ds*16 + si] == 0x06) {
            pc = 0x1ced9;
            break;
        }
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1cecf;
            break;
        }
    case 0x1ced9:
        push(si);
        di = 0x4d5e;
        yield* sub_1c912();
        si = pop();
        memory[ds*16 + si] = 0x00;
        si = pop();
        return;
    case 0x1cee6:
        if (memory16get(ds, si + 5) == 0x0000) {
            pc = 0x1cea6;
            break;
        }
        r8[dh] = memory[ds*16 + si + 2];
        if (r8[dh] > 0xd1) {
            pc = 0x1ceff;
            break;
        }
        if (r8[dh] >= 0x08) {
            pc = 0x1cf09;
            break;
        }
        memory[ds*16 + si + 2] = 0x08;
        pc = 0x1cf03;
        break;
    case 0x1ceff:
        memory[ds*16 + si + 2] = 0xd1;
    case 0x1cf03:
        yield* sub_1dc26();
        yield* sub_1cf4d();
    case 0x1cf09:
        r8[ah] = memory[ds*16 + si + 4];
        if (r8[ah] < 0x0a) {
            pc = 0x1cf44;
            break;
        }
        if (r8[ah] > 0xc1) {
            pc = 0x1cf21;
            break;
        }
        if (r8[ah] < 0xb4) {
            pc = 0x1cf20;
            break;
        }
        if (r8[ah] <= 0xba) {
            pc = 0x1cf53;
            break;
        }
    case 0x1cf20:
        return;
    case 0x1cf21:
        memory[ds*16 + si] = 0x00;
        memory[ds*16 + 0x48ea] -= 1;
        if (memory[ds*16 + 0x48ea] == 0x01) {
            pc = 0x1cec7;
            break;
        }
        if (memory[ds*16 + 0x48ea] > 0x01) {
            pc = 0x1cf43;
            break;
        }
        yield* sub_1dea0();
        yield* sub_1e01c();
        if (si != 0x4d5e) {
            pc = 0x1cf42;
            break;
        }
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
    case 0x1cf42:
        r16[ax] = pop();
    case 0x1cf43:
        return;
    case 0x1cf44:
        yield* sub_1dc26();
    case 0x1cf47:
        memory16set(ds, si + 7, -memory16get(ds, si + 7));
        pc = 0x1ca4d;
        break;
    case 0x1cf53:
        r8[ah] = memory[ds*16 + 0x48d8];
        r8[ah] -= 0x05;
        if (r8[dh] < r8[ah]) {
            pc = 0x1cf6f;
            break;
        }
        r8[ah] += memory[ds*16 + 0x48d0];
        r8[ah] += 0x08;
        if (r8[dh] > r8[ah]) {
            pc = 0x1cf8e;
            break;
        }
        r8[ah] = memory[ds*16 + 0x48d8];
        pc = 0x1cfdb;
        break;
    case 0x1cf6f:
        if (memory[ds*16 + 0x48cf] != 0x13) {
            pc = 0x1cf43;
            break;
        }
        r8[ah] = memory[ds*16 + 0x48d8];
        r8[dl] = r8[ah];
        r8[ah] -= memory[ds*16 + 0x48db];
        yield* sub_1d042();
        r8[dl] -= r8[ah];
        r8[dl] -= 0x03;
        if (r8[dh] < r8[dl]) {
            pc = 0x1cf43;
            break;
        }
        pc = 0x1cfce;
        break;
    case 0x1cf8e:
        r8[al] = memory[ds*16 + 0x48cf];
        if (r8[al] == 0x13) {
            pc = 0x1cfb4;
            break;
        }
        if (r8[al] != 0x09) {
            pc = 0x1cf43;
            break;
        }
        r8[ah] += 0x08;
        if (r8[dh] < r8[ah]) {
            pc = 0x1cf43;
            break;
        }
        r8[ah] += memory[ds*16 + 0x48d0];
        r8[ah] += 0x08;
        if (r8[dh] > r8[ah]) {
            pc = 0x1cf43;
            break;
        }
        r8[ah] -= memory[ds*16 + 0x48d0];
        r8[ah] -= 0x08;
        pc = 0x1cfdb;
        break;
    case 0x1cfb4:
        r8[ah] = memory[ds*16 + 0x48db];
        r8[ah] -= memory[ds*16 + 0x48d8];
        yield* sub_1d042();
        r8[ah] += memory[ds*16 + 0x48d8];
        r8[ah] += memory[ds*16 + 0x48d0];
        r8[ah] += 0x03;
        if (r8[dh] > r8[ah])
            return;
    case 0x1cfce:
        r16[bx] = 0x0204;
        yield* sub_1f0d2();
        memory[ds*16 + si + 4] = 0xb4;
        pc = 0x1cf47;
        break;
    case 0x1cfdb:
        r8[dh] -= r8[ah];
        if (memory[ds*16 + 0x48d5] == 0x00) {
            pc = 0x1cff7;
            break;
        }
        r16[ax] = 0;
        memory[ds*16 + si + 1] = r8[dh];
        memory[ds*16 + si + 4] = 0xb5;
        memory16set(ds, si + 5, r16[ax]);
        memory16set(ds, si + 7, r16[ax]);
        memory[ds*16 + si + 10] = r8[al];
        return;
    case 0x1cff7:
        r16[bx] = 0x0204;
        yield* sub_1f0d2();
    case 0x1cffd:
        r8[dl] = memory[ds*16 + 0x48d0];
        r8[cl] = r8[dl];
        r8[dl] >>= 1;
        r8[bl] = 0x01;
        if (r8s[dh] < r8s[dl]) {
            pc = 0x1d011;
            break;
        }
        r8[cl] -= r8[dh];
        r8[dh] = r8[cl];
        r8[bl]--;
    case 0x1d011:
        r8[dl] >>= 1;
        r8[dl] >>= 1;
        di = 0x4979;
        r16[cx] = 0x0004;
    case 0x1d01b:
        di += 0x0002;
        r8[tl] = r8[dh];
        r8[dh] -= r8[dl];
        if (r8s[tl] - r8s[dl] <= 0) {
            pc = 0x1d024;
            break;
        }
        if (--r16[cx]) {
            pc = 0x1d01b;
            break;
        }
    case 0x1d024:
        r8[cl] = memory[ds*16 + di];
        r8[al] = memory[ds*16 + 0x48e8];
        mul8(r8[cl]);
        if (!r8[bl]) {
            pc = 0x1d031;
            break;
        }
        r16[ax] = -r16[ax];
    case 0x1d031:
        memory16set(ds, si + 5, r16[ax]);
        r8[dl] = memory[ds*16 + di + 1];
        r8[al] = memory[ds*16 + 0x48e8];
        mul8(r8[dl]);
        r16[ax] = -r16[ax];
        memory16set(ds, si + 7, r16[ax]);
        return;
    } while (1);
}
function* sub_1cf47() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1cf47;
        break;
    case 0x1ca4d:
        r16[ax] = memory16get(ds, si + 7);
        memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[ax]);
        return;
    case 0x1cf47:
        memory16set(ds, si + 7, -memory16get(ds, si + 7));
        pc = 0x1ca4d;
        break;
        return;
    } while (1);
}
function* sub_1cf4d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1cf4d;
        break;
    case 0x1ca54:
        r16[ax] = memory16get(ds, si + 5);
        memory16set(ds, si + 1, memory16get(ds, si + 1) + r16[ax]);
        return;
    case 0x1cf4d:
        memory16set(ds, si + 5, -memory16get(ds, si + 5));
        pc = 0x1ca54;
        break;
        return;
    } while (1);
}
function* sub_1d042() {
    r8[ah] >>= 1;
    r8[al] = r8[ah];
    r8[ah] >>= 1;
    r8[ah] += r8[al];
}
function* sub_1d04b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16 + 0x0493];
        if (r8[cl] == 0x10) {
            pc = 0x1d05a;
            break;
        }
        if (r8[cl] == 0x21) {
            pc = 0x1d05e;
            break;
        }
        return;
    case 0x1d05a:
        yield* sub_1d05e();
        return;
    case 0x1d05e:
        r8[bl] = memory[ds*16 + si + 4];
        if (r8[bl] < 0x38) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bl] > 0x88) {
            pc = 0x1d0b0;
            break;
        }
        r8[bh] = memory[ds*16 + si + 2];
        if (r8[bh] < 0x56) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bh] > 0x88) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bh] > 0x83) {
            pc = 0x1d082;
            break;
        }
        if (r8[bh] >= 0x5b) {
            pc = 0x1d085;
            break;
        }
    case 0x1d082:
        yield* sub_1cf4d();
    case 0x1d085:
        if (r8[bl] > 0x83) {
            pc = 0x1d08f;
            break;
        }
        if (r8[bl] >= 0x3d) {
            pc = 0x1d092;
            break;
        }
    case 0x1d08f:
        yield* sub_1cf47();
    case 0x1d092:
        yield* sub_1dc26();
        r16[bx] = 0x0203;
        yield* sub_1f0d2();
        memory[ds*16 + 0x4938] += 1;
        r8[al] = 0x10;
        if (memory[ds*16 + 0x4938] == r8[al]) {
            pc = 0x1d0b1;
            break;
        }
        memory[ds*16 + 0x48e5] = 0x02;
        yield* sub_1d6be();
        r16[ax] = pop();
    case 0x1d0b0:
        return;
    case 0x1d0b1:
        push(si);
        yield* sub_1d7c8();
        yield* sub_1c8de();
        r16[bx] = 0x587c;
        yield* sub_1c939();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1ccfc();
        r16[cx] = 0x003c;
    case 0x1d0d0:
        push(r16[cx]);
        yield* sub_1f961();
        r8[al] = 0x01;
        yield* sub_1fb9b();
        yield* sub_1f961();
        r8[al] = 0;
        yield* sub_1fb9b();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1d0d0;
            break;
        }
        yield* sub_1bf9f();
        r16[bx] = 0x0205;
        yield* sub_1f0d2();
        r16[cx] = 0x0034;
    case 0x1d0f0:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1fb9f();
        r16[cx] = pop();
        r16[cx]++;
        if (r16[cx] != 0x0099) {
            pc = 0x1d0f0;
            break;
        }
        yield* sub_1d28e();
        si = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1d05e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16 + si + 4];
        if (r8[bl] < 0x38) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bl] > 0x88) {
            pc = 0x1d0b0;
            break;
        }
        r8[bh] = memory[ds*16 + si + 2];
        if (r8[bh] < 0x56) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bh] > 0x88) {
            pc = 0x1d0b0;
            break;
        }
        if (r8[bh] > 0x83) {
            pc = 0x1d082;
            break;
        }
        if (r8[bh] >= 0x5b) {
            pc = 0x1d085;
            break;
        }
    case 0x1d082:
        yield* sub_1cf4d();
    case 0x1d085:
        if (r8[bl] > 0x83) {
            pc = 0x1d08f;
            break;
        }
        if (r8[bl] >= 0x3d) {
            pc = 0x1d092;
            break;
        }
    case 0x1d08f:
        yield* sub_1cf47();
    case 0x1d092:
        yield* sub_1dc26();
        r16[bx] = 0x0203;
        yield* sub_1f0d2();
        memory[ds*16 + 0x4938] += 1;
        r8[al] = 0x10;
        if (memory[ds*16 + 0x4938] == r8[al]) {
            pc = 0x1d0b1;
            break;
        }
        memory[ds*16 + 0x48e5] = 0x02;
        yield* sub_1d6be();
        r16[ax] = pop();
    case 0x1d0b0:
        return;
    case 0x1d0b1:
        push(si);
        yield* sub_1d7c8();
        yield* sub_1c8de();
        r16[bx] = 0x587c;
        yield* sub_1c939();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1fb2b();
        yield* sub_1ccfc();
        r16[cx] = 0x003c;
    case 0x1d0d0:
        push(r16[cx]);
        yield* sub_1f961();
        r8[al] = 0x01;
        yield* sub_1fb9b();
        yield* sub_1f961();
        r8[al] = 0;
        yield* sub_1fb9b();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1d0d0;
            break;
        }
        yield* sub_1bf9f();
        r16[bx] = 0x0205;
        yield* sub_1f0d2();
        r16[cx] = 0x0034;
    case 0x1d0f0:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1fb9f();
        r16[cx] = pop();
        r16[cx]++;
        if (r16[cx] != 0x0099) {
            pc = 0x1d0f0;
            break;
        }
        yield* sub_1d28e();
        si = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1d105() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = memory[ds*16 + si + 4];
        r8[al] = memory[ds*16 + si + 2];
        r8[bh] = 0;
        r8[al] += 0x04;
        r8[bl] += 0x04;
        yield* sub_1d484();
        if (flags.carry)
            return;
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[al] &= 0x0f;
        if (r8[al] == 0)
            return;
        r8[ch] = memory[ds*16 + r16[bx] + 1417];
        if (memory[ds*16 + 0x48e9] != 0x00) {
            pc = 0x1d141;
            break;
        }
        yield* sub_1dc1a();
        yield* sub_1d8a1();
        if (r8[al] >= 0x04) {
            pc = 0x1d141;
            break;
        }
        yield* sub_1dd10();
        if (r8[al] == 0x01)
            return;
        memory[ds*16 + r16[bx] + 1183] -= 1;
        if (memory[ds*16 + r16[bx] + 1183] != 0)
            return;
    case 0x1d141:
        push(r16[ax]);
        yield* sub_1d94d();
        r16[ax] = pop();
        yield* sub_1d250();
        r8[ch] &= 0xf0;
        memory[ds*16 + r16[bx] + 1417] = r8[ch];
        push(r16[bx]);
        r16[bx] = 0x0202;
        yield* sub_1f0d2();
        r16[bx] = pop();
        yield* sub_1d6db();
        yield* sub_1d6f6();
        return;
    } while (1);
}
function* sub_1d158() {
    yield* sub_1d6db();
    yield* sub_1d6f6();
}
function* sub_1d15f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
        r8[al] = memory[ds*16 + si + 2];
        r8[ah] = memory[ds*16 + si + 4];
        r16[ax] += 0x0505;
    case 0x1d16f:
        r8[bl] = memory[ds*16 + di];
        if (r8[bl] == 0x0a) {
            pc = 0x1d181;
            break;
        }
        if (r8[bl] == 0x0e) {
            pc = 0x1d186;
            break;
        }
    case 0x1d17b:
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d16f;
            break;
        }
        return;
    case 0x1d181:
        r16[dx] = 0x0c15;
        pc = 0x1d189;
        break;
    case 0x1d186:
        r16[dx] = 0x0b0b;
    case 0x1d189:
        r8[bl] = memory[ds*16 + di + 2];
        if (r8[al] < r8[bl]) {
            pc = 0x1d17b;
            break;
        }
        r8[bl] += r8[dl];
        if (r8[al] > r8[bl]) {
            pc = 0x1d17b;
            break;
        }
        r8[bh] = memory[ds*16 + di + 4];
        if (r8[ah] < r8[bh]) {
            pc = 0x1d17b;
            break;
        }
        r8[bh] += r8[dh];
        if (r8[ah] > r8[bh]) {
            pc = 0x1d17b;
            break;
        }
        if (r8[dl] == 0x15) {
            pc = 0x1d1ab;
            break;
        }
        r8[cl] = 0x02;
        return;
    case 0x1d1ab:
        r8[cl] = 0x01;
        return;
    } while (1);
}
function* sub_1d1ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1d1ae;
        break;
    case 0x1ca4d:
        r16[ax] = memory16get(ds, si + 7);
        memory16set(ds, si + 3, memory16get(ds, si + 3) + r16[ax]);
        return;
    case 0x1ca54:
        r16[ax] = memory16get(ds, si + 5);
        memory16set(ds, si + 1, memory16get(ds, si + 1) + r16[ax]);
        return;
    case 0x1cf47:
        memory16set(ds, si + 7, -memory16get(ds, si + 7));
        pc = 0x1ca4d;
        break;
    case 0x1cf4d:
        memory16set(ds, si + 5, -memory16get(ds, si + 5));
        pc = 0x1ca54;
        break;
    case 0x1d1ae:
        if (r8[cl] < 0x01) {
            pc = 0x1d1c4;
            break;
        }
        if (r8[cl] == 0x01) {
            pc = 0x1d1c5;
            break;
        }
        yield* sub_1d23b();
        if (!(memory[ds*16 + si + 8] & 0x80)) {
            pc = 0x1d1c1;
            break;
        }
        pc = 0x1cf47;
        break;
    case 0x1d1c1:
        pc = 0x1cf4d;
        break;
    case 0x1d1c4:
        return;
    case 0x1d1c5:
        r8[ch] = memory[ds*16 + di + 9];
        r8[al] = r8[ch];
        r8[al] &= 0x0f;
        if (memory[ds*16 + 0x48e9] != 0x00) {
            pc = 0x1d1f0;
            break;
        }
        r8[bl] -= r8[dl];
        r8[bh] -= r8[dh];
        r8[bl] -= r8[al];
        r8[bh] -= r8[ah];
        r16[tx] = r16[dx];
        r16[dx] = r16[bx];
        r16[bx] = r16[tx];
        yield* sub_1d88a();
        if (r8[al] >= 0x04) {
            pc = 0x1d1f0;
            break;
        }
        yield* sub_1dcc5();
        if (r8[al] == 0x01) {
            pc = 0x1d1c4;
            break;
        }
        memory[ds*16 + di + 8] -= 1;
        if (memory[ds*16 + di + 8] != 0) {
            pc = 0x1d1c4;
            break;
        }
    case 0x1d1f0:
        memory[ds*16 + di] = 0x00;
        push(r16[ax]);
        yield* sub_1d931();
        r16[ax] = pop();
        pc = 0x1d250;
        break;
    case 0x1d250:
        if (r8[al] < 0x02) {
            pc = 0x1d266;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x1d272;
            break;
        }
        memory[ds*16 + 0x0498] -= 1;
        if (memory[ds*16 + 0x0498] != 0) {
            pc = 0x1d266;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_1d7c8();
        yield* sub_1d28e();
        r16[bx] = pop();
        r16[cx] = pop();
    case 0x1d266:
        yield* sub_1d454();
        push(r16[bx]);
        r16[bx] = 0x0202;
        yield* sub_1f0d2();
        r16[bx] = pop();
        return;
    case 0x1d272:
        push(r16[bx]);
        memory16set(ds, 0x58ff, r16[bx]);
        memory[ds*16 + 0x5901] = r8[al];
        yield* sub_1d5a8();
        memory[ds*16 + 0x58f9] = r8[bl];
        memory[ds*16 + 0x58fb] = r8[dl];
        r16[bx] = 0x58f8;
        yield* sub_1c939();
        r16[bx] = pop();
        pc = 0x1d266;
        break;
        return;
    } while (1);
}
function* sub_1d228() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1d228;
        break;
    case 0x1d1c4:
        return;
    case 0x1d1e0:
        if (r8[al] >= 0x04) {
            pc = 0x1d1f0;
            break;
        }
        yield* sub_1dcc5();
        if (r8[al] == 0x01) {
            pc = 0x1d1c4;
            break;
        }
        memory[ds*16 + di + 8] -= 1;
        if (memory[ds*16 + di + 8] != 0) {
            pc = 0x1d1c4;
            break;
        }
    case 0x1d1f0:
        memory[ds*16 + di] = 0x00;
        push(r16[ax]);
        yield* sub_1d931();
        r16[ax] = pop();
        pc = 0x1d250;
        break;
    case 0x1d228:
        if (r8[cl] < 0x01) {
            pc = 0x1d24f;
            break;
        }
        memory[ds*16 + si] = 0x00;
        if (r8[cl] != 0x01) {
            pc = 0x1d23b;
            break;
        }
        r8[ch] = memory[ds*16 + di + 9];
        r8[al] = r8[ch];
        r8[al] &= 0x0f;
        pc = 0x1d1e0;
        break;
    case 0x1d23b:
        r8[al] = memory[ds*16 + di + 7];
        if (r8[al] == 0x04) {
            pc = 0x1d24f;
            break;
        }
        push(si);
        si = di;
        yield* sub_1d35e();
        si = pop();
        r16[ax] = 0x0010;
        yield* sub_1b130();
    case 0x1d24f:
        return;
    case 0x1d250:
        if (r8[al] < 0x02) {
            pc = 0x1d266;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x1d272;
            break;
        }
        memory[ds*16 + 0x0498] -= 1;
        if (memory[ds*16 + 0x0498] != 0) {
            pc = 0x1d266;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_1d7c8();
        yield* sub_1d28e();
        r16[bx] = pop();
        r16[cx] = pop();
    case 0x1d266:
        yield* sub_1d454();
        push(r16[bx]);
        r16[bx] = 0x0202;
        yield* sub_1f0d2();
        r16[bx] = pop();
        return;
    case 0x1d272:
        push(r16[bx]);
        memory16set(ds, 0x58ff, r16[bx]);
        memory[ds*16 + 0x5901] = r8[al];
        yield* sub_1d5a8();
        memory[ds*16 + 0x58f9] = r8[bl];
        memory[ds*16 + 0x58fb] = r8[dl];
        r16[bx] = 0x58f8;
        yield* sub_1c939();
        r16[bx] = pop();
        pc = 0x1d266;
        break;
        return;
    } while (1);
}
function* sub_1d23b() {
    r8[al] = memory[ds*16 + di + 7];
    if (r8[al] == 0x04)
        return;
    push(si);
    si = di;
    yield* sub_1d35e();
    si = pop();
    r16[ax] = 0x0010;
    yield* sub_1b130();
}
function* sub_1d250() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] < 0x02) {
            pc = 0x1d266;
            break;
        }
        if (r8[al] == 0x02) {
            pc = 0x1d272;
            break;
        }
        memory[ds*16 + 0x0498] -= 1;
        if (memory[ds*16 + 0x0498] != 0) {
            pc = 0x1d266;
            break;
        }
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_1d7c8();
        yield* sub_1d28e();
        r16[bx] = pop();
        r16[cx] = pop();
    case 0x1d266:
        yield* sub_1d454();
        push(r16[bx]);
        r16[bx] = 0x0202;
        yield* sub_1f0d2();
        r16[bx] = pop();
        return;
    case 0x1d272:
        push(r16[bx]);
        memory16set(ds, 0x58ff, r16[bx]);
        memory[ds*16 + 0x5901] = r8[al];
        yield* sub_1d5a8();
        memory[ds*16 + 0x58f9] = r8[bl];
        memory[ds*16 + 0x58fb] = r8[dl];
        r16[bx] = 0x58f8;
        yield* sub_1c939();
        r16[bx] = pop();
        pc = 0x1d266;
        break;
        return;
    } while (1);
}
function* sub_1d28e() {
    yield* sub_1dca8();
    memory[ds*16 + 0x48e0] = 0x01;
    r16[bx] = 0x590e;
    memory16set(ds, r16[bx] + 5, 0x0258);
    yield* sub_1c939();
}
function* sub_1d2c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1d2c8;
        break;
    case 0x1ca54:
        r16[ax] = memory16get(ds, si + 5);
        memory16set(ds, si + 1, memory16get(ds, si + 1) + r16[ax]);
        return;
    case 0x1cf4d:
        memory16set(ds, si + 5, -memory16get(ds, si + 5));
        pc = 0x1ca54;
        break;
    case 0x1d2c8:
        r8[bh] = 0;
        r8[bl] = memory[ds*16 + si + 3];
        r8[al] = memory[ds*16 + si + 2];
        yield* sub_1d498();
        r8[ah] = memory[ds*16 + r16[bx] + 1417];
        r8[ah] &= 0x0f;
        if (r8[ah] != 0) {
            pc = 0x1d2e6;
            break;
        }
        r8[ah] = memory[ds*16 + r16[bx] + 1418];
        r8[ah] &= 0x0f;
        if (r8[ah] != 0) {
            pc = 0x1d2e6;
            break;
        }
        return;
    case 0x1d2e6:
        pc = 0x1cf4d;
        break;
        return;
    } while (1);
}
function* sub_1d2e9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
        r8[al] = memory[ds*16 + si + 2];
        r8[ah] = memory[ds*16 + si + 4];
    case 0x1d2f6:
        r8[bl] = memory[ds*16 + di];
        if (r8[bl] != 0x0a) {
            pc = 0x1d320;
            break;
        }
        if (si == di) {
            pc = 0x1d320;
            break;
        }
        if (r8[ah] != memory[ds*16 + di + 4]) {
            pc = 0x1d320;
            break;
        }
        r8[bl] = memory[ds*16 + di + 2];
        if (r8[al] < r8[bl]) {
            pc = 0x1d316;
            break;
        }
        r8[bl] += 0x0f;
        if (r8[al] > r8[bl]) {
            pc = 0x1d320;
            break;
        }
        pc = 0x1d31d;
        break;
    case 0x1d316:
        r8[bl] -= 0x0f;
        if (r8[al] < r8[bl]) {
            pc = 0x1d320;
            break;
        }
    case 0x1d31d:
        yield* sub_1cf4d();
    case 0x1d320:
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d2f6;
            break;
        }
        return;
    } while (1);
}
function* sub_1d330() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si + 2];
        if (r8[al] >= 0xcc) {
            pc = 0x1d347;
            break;
        }
        if (r8[al] <= 0x08) {
            pc = 0x1d34d;
            break;
        }
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] < 0x0a) {
            pc = 0x1d353;
            break;
        }
        if (r8[al] > 0xb4) {
            pc = 0x1d35e;
            break;
        }
        return;
    case 0x1d347:
        memory[ds*16 + si + 2] -= 0x02;
        pc = 0x1d357;
        break;
    case 0x1d34d:
        memory[ds*16 + si + 2] += 0x02;
        pc = 0x1d357;
        break;
    case 0x1d353:
        memory[ds*16 + si + 4] += 0x02;
    case 0x1d357:
        yield* sub_1ca85();
        yield* sub_1ca6f();
        return;
    case 0x1d35e:
        r16[ax] = memory16get(ds, si + 1);
        memory16set(ds, 0x58cd, r16[ax]);
        r16[ax] = memory16get(ds, si + 3);
        memory16set(ds, 0x58cf, r16[ax]);
        r16[bx] = 0x58cc;
        yield* sub_1c939();
        r16[bx] = 0x0205;
        yield* sub_1f0d2();
        memory[ds*16 + 0x48ec] -= 1;
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_1d35e() {
    r16[ax] = memory16get(ds, si + 1);
    memory16set(ds, 0x58cd, r16[ax]);
    r16[ax] = memory16get(ds, si + 3);
    memory16set(ds, 0x58cf, r16[ax]);
    r16[bx] = 0x58cc;
    yield* sub_1c939();
    r16[bx] = 0x0205;
    yield* sub_1f0d2();
    memory[ds*16 + 0x48ec] -= 1;
    memory[ds*16 + si] = 0x00;
}
function* sub_1d37e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0493];
        if (r8[al] == 0x10) {
            pc = 0x1d386;
            break;
        }
        return;
    case 0x1d386:
        r8[al] = memory[ds*16 + si + 4];
        if (r8[al] < 0x2a) {
            pc = 0x1d39f;
            break;
        }
        if (r8[al] > 0x91) {
            pc = 0x1d39f;
            break;
        }
        r8[al] = memory[ds*16 + si + 2];
        if (r8[al] < 0x43) {
            pc = 0x1d39f;
            break;
        }
        if (r8[al] > 0x90) {
            pc = 0x1d39f;
            break;
        }
        yield* sub_1d3f0();
    case 0x1d39f:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1d3a1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16 + si + 4];
        r8[ch] = memory[ds*16 + si + 2];
        r8[bh] = 0;
        r8[bl] = r8[cl];
        r8[al] = r8[ch];
        yield* sub_1d484();
        if (flags.carry) {
            pc = 0x1d3cb;
            break;
        }
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1d3f0;
            break;
        }
        r8[bl] = r8[cl];
        r8[al] = r8[ch];
        r8[al] += 0x09;
        yield* sub_1d484();
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1d3f0;
            break;
        }
    case 0x1d3cb:
        r8[cl] += 0x09;
        r8[bl] = r8[cl];
        r8[al] = r8[ch];
        yield* sub_1d484();
        if (flags.carry)
            return;
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1d3f0;
            break;
        }
        r8[bl] = r8[cl];
        r8[al] = r8[ch];
        r8[al] += 0x09;
        yield* sub_1d484();
        r8[al] = memory[ds*16 + r16[bx] + 1417];
        r8[al] &= 0x0f;
        if (r8[al] == 0)
            return;
    case 0x1d3f0:
        yield* sub_1ca85();
        r8[al] = memory[ds*16 + si + 6];
        if (r8[al] != memory[ds*16 + r16[bx]]) {
            pc = 0x1d3fd;
            break;
        }
        r16[bx] -= 0x0005;
    case 0x1d3fd:
        r16[ax] = memory16get(ds, r16[bx] + 1);
        r16[dx] = memory16get(ds, r16[bx] + 3);
        memory16set(ds, si + 1, memory16get(ds, si + 1) - r16[ax]);
        memory16set(ds, si + 3, memory16get(ds, si + 3) - r16[dx]);
        yield* sub_1ca6f();
        return;
    } while (1);
}
function* sub_1d3f0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1ca85();
        r8[al] = memory[ds*16 + si + 6];
        if (r8[al] != memory[ds*16 + r16[bx]]) {
            pc = 0x1d3fd;
            break;
        }
        r16[bx] -= 0x0005;
    case 0x1d3fd:
        r16[ax] = memory16get(ds, r16[bx] + 1);
        r16[dx] = memory16get(ds, r16[bx] + 3);
        memory16set(ds, si + 1, memory16get(ds, si + 1) - r16[ax]);
        memory16set(ds, si + 3, memory16get(ds, si + 3) - r16[dx]);
        yield* sub_1ca6f();
        return;
    } while (1);
}
function* sub_1d443() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x48f2;
        r16[cx] = 0x0004;
    case 0x1d449:
        if (memory[ds*16 + di] == r8[bl]) {
            pc = 0x1d450;
            break;
        }
        di++;
        if (--r16[cx]) {
            pc = 0x1d449;
            break;
        }
    case 0x1d450:
        memory[ds*16 + di] = 0x00;
        return;
    } while (1);
}
function* sub_1d454() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r8[bl] = r8[ch];
        r8[bl] &= 0x0f;
        r8[bh] = 0;
        r8[al] = memory[ds*16 + r16[bx] + 18769];
        r8[ah] = r8[bh];
        if (r8[bl] > 0x03) {
            pc = 0x1d47f;
            break;
        }
        r8[bl] = memory[ds*16 + 0x0493];
        r8[bh] = 0;
    case 0x1d46d:
        if (r8[bl] < 0x0a) {
            pc = 0x1d47a;
            break;
        }
        r8[bh] += 0x10;
        r8[bl] -= 0x0a;
        pc = 0x1d46d;
        break;
    case 0x1d47a:
        r8[bh] += r8[bl];
        flags.carry = (r8[al] + r8[bh]) >= 0x100;
        r8[al] += r8[bh];
        daa();
    case 0x1d47f:
        yield* sub_1b130();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1d484() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[bl] > 0x88) {
            pc = 0x1d4aa;
            break;
        }
        r8[tl] = r8[bl];
        r8[bl] -= 0x0b;
        if (r8[tl] < 0x0b) {
            pc = 0x1d4aa;
            break;
        }
        r8[dh] = memory[cs*16 + r16[bx] + 9322];
        r8[bl] = memory[cs*16 + r16[bx] + 9196];
        r8[al] -= 0x08;
        r8[dl] = r8[al];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[ah] = r8[al];
        r8[bl] += r8[al];
        flags.carry = false;
        return;
    case 0x1d4aa:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1d498() {
    r8[al] -= 0x08;
    r8[dl] = r8[al];
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[ah] = r8[al];
    r8[bl] += r8[al];
    flags.carry = false;
}
function* sub_1d5a8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = 0x03;
        bp = 0xfff3;
    case 0x1d5ad:
        bp += 0x000d;
        r8[dl] += 0x07;
        r16[tx] = r16[bx];
        r16[bx] -= 0x000d;
        if (r16s[tx] - signed16(0x000d) >= 0) {
            pc = 0x1d5ad;
            break;
        }
        r8[bl] += 0x0d;
        r8[bl] <<= 1;
        r8[bl] <<= 1;
        r8[bl] <<= 1;
        r8[bl] <<= 1;
        r8[bl] += 0x08;
        return;
    } while (1);
}
function* sub_1d5c7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[cx] < 0x0008) {
            pc = 0x1d5f4;
            break;
        }
        if (r16[cx] >= 0x00d8) {
            pc = 0x1d5f4;
            break;
        }
        if (r8[dl] < 0x0b) {
            pc = 0x1d5f4;
            break;
        }
        if (r8[dl] >= 0x89) {
            pc = 0x1d5f4;
            break;
        }
        push(r16[bx]);
        r8[al] = r8[cl];
        r8[bl] = r8[dl];
        yield* sub_1d484();
        r8[bh] = 0;
        push(r16[bx]);
        yield* sub_1d5a8();
        r8[dh] = 0;
        r8[ch] = r8[dh];
        r8[cl] = r8[bl];
        r16[ax] = pop();
        r16[bx] = pop();
        flags.carry = false;
        return;
    case 0x1d5f4:
        r16[cx] &= 0x01f0;
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1d5fa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48ea] >= 0x03)
            return;
        memory[ds*16 + si + 10] -= 1;
        if (memory[ds*16 + si + 10] == 0) {
            pc = 0x1d63b;
            break;
        }
        memory[ds*16 + 0x48ea] += 1;
        push(si);
        si = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1d613:
        if (memory[ds*16 + si] == 0x06) {
            pc = 0x1d61d;
            break;
        }
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d613;
            break;
        }
    case 0x1d61d:
        yield* sub_1d697();
        r16[dx] = 0x0008;
        if (!(memory[ds*16 + si + 6] & 0x80)) {
            pc = 0x1d62b;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1d62b:
        r16[ax] += r16[dx];
        memory16set(ds, r16[bx] + 5, r16[ax]);
        memory16set(ds, r16[bx] + 7, bp);
        yield* sub_1c939();
        yield* sub_1d67f();
        si = pop();
        return;
    case 0x1d63b:
        memory[ds*16 + si] = 0x00;
        return;
    } while (1);
}
function* sub_1d63f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ch] = 0;
        r8[cl] = memory[ds*16 + si + 10];
        memory[ds*16 + 0x48ea] += r8[cl];
        yield* sub_1d697();
        r16[dx] = 0x0008;
        if (!(memory[ds*16 + si + 6] & 0x80)) {
            pc = 0x1d656;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1d656:
        di = 0x0002;
        if (!(memory[ds*16 + si + 8] & 0x80)) {
            pc = 0x1d661;
            break;
        }
        di = -di;
    case 0x1d661:
        r16[ax] += r16[dx];
        bp += di;
        push(r16[cx]);
        push(r16[ax]);
        push(bp);
        push(r16[dx]);
        push(di);
        push(r16[bx]);
        memory16set(ds, r16[bx] + 5, r16[ax]);
        memory16set(ds, r16[bx] + 7, bp);
        yield* sub_1c939();
        r16[bx] = pop();
        di = pop();
        r16[dx] = pop();
        bp = pop();
        r16[ax] = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1d661;
            break;
        }
        memory[ds*16 + si] = 0x00;
        push(si);
        r16[bx] = 0x4d5e;
        if (memory[ds*16 + r16[bx]] != 0x06) {
            pc = 0x1d695;
            break;
        }
        push(r16[bx]);
        yield* sub_1c939();
        r16[bx] = pop();
        memory[ds*16 + r16[bx]] = 0x00;
        r8[dl] = 0;
        yield* sub_1fb90();
    case 0x1d695:
        si = pop();
        return;
    } while (1);
}
function* sub_1d67f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r16[bx] = 0x4d5e;
        if (memory[ds*16 + r16[bx]] != 0x06) {
            pc = 0x1d695;
            break;
        }
        push(r16[bx]);
        yield* sub_1c939();
        r16[bx] = pop();
        memory[ds*16 + r16[bx]] = 0x00;
        r8[dl] = 0;
        yield* sub_1fb90();
    case 0x1d695:
        si = pop();
        return;
    } while (1);
}
function* sub_1d697() {
    r16[bx] = 0x5887;
    r16[ax] = memory16get(ds, si + 1);
    memory16set(ds, r16[bx] + 1, r16[ax]);
    r16[ax] = memory16get(ds, si + 3);
    memory16set(ds, r16[bx] + 3, r16[ax]);
    r16[ax] = memory16get(ds, si + 5);
    bp = memory16get(ds, si + 7);
}
function* sub_1d6ad() {
    r8[al] = memory[ds*16 + 0x48f0];
    r8[tl] = memory[ds*16 + si + 1];
    memory[ds*16 + si + 1] -= r8[al];
    if (r8s[tl] - r8s[al] > 0)
        return;
    memory[ds*16 + si] = 0x00;
    memory[ds*16 + 0x48e5] = 0x01;
}
function* sub_1d6be() {
    r16[bx] = 0x595a;
    yield* sub_1c939();
}
function* sub_1d6c5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x0a;
        pc = 0x1d6dd;
        break;
    case 0x1d6dd:
        memory[ds*16 + 0x4985] += 1;
        di = memory16get(ds, 0x4986);
        memory[ds*16 + di] = r8[al];
        memory16set(ds, di + 1, r16[bx]);
        di += 0x0003;
        memory16set(ds, 0x4986, di);
        return;
    } while (1);
}
function* sub_1d6c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x08;
        pc = 0x1d6dd;
        break;
    case 0x1d6dd:
        memory[ds*16 + 0x4985] += 1;
        di = memory16get(ds, 0x4986);
        memory[ds*16 + di] = r8[al];
        memory16set(ds, di + 1, r16[bx]);
        di += 0x0003;
        memory16set(ds, 0x4986, di);
        return;
    } while (1);
}
function* sub_1d6cd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x06;
        pc = 0x1d6dd;
        break;
    case 0x1d6dd:
        memory[ds*16 + 0x4985] += 1;
        di = memory16get(ds, 0x4986);
        memory[ds*16 + di] = r8[al];
        memory16set(ds, di + 1, r16[bx]);
        di += 0x0003;
        memory16set(ds, 0x4986, di);
        return;
    } while (1);
}
function* sub_1d6d1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x04;
        pc = 0x1d6dd;
        break;
    case 0x1d6dd:
        memory[ds*16 + 0x4985] += 1;
        di = memory16get(ds, 0x4986);
        memory[ds*16 + di] = r8[al];
        memory16set(ds, di + 1, r16[bx]);
        di += 0x0003;
        memory16set(ds, 0x4986, di);
        return;
    } while (1);
}
function* sub_1d6d5() {
    memory[ds*16 + si] = 0x00;
    r16[bx] = memory16get(ds, si + 1);
    r8[al] = 0x02;
    memory[ds*16 + 0x4985] += 1;
    di = memory16get(ds, 0x4986);
    memory[ds*16 + di] = r8[al];
    memory16set(ds, di + 1, r16[bx]);
    di += 0x0003;
    memory16set(ds, 0x4986, di);
}
function* sub_1d6db() {
    r8[al] = 0x02;
    memory[ds*16 + 0x4985] += 1;
    di = memory16get(ds, 0x4986);
    memory[ds*16 + di] = r8[al];
    memory16set(ds, di + 1, r16[bx]);
    di += 0x0003;
    memory16set(ds, 0x4986, di);
}
function* sub_1d6f2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1d6f2;
        break;
    case 0x1d6dd:
        memory[ds*16 + 0x4985] += 1;
        di = memory16get(ds, 0x4986);
        memory[ds*16 + di] = r8[al];
        memory16set(ds, di + 1, r16[bx]);
        di += 0x0003;
        memory16set(ds, 0x4986, di);
        return;
    case 0x1d6f2:
        r8[al] = 0x0c;
        pc = 0x1d6dd;
        break;
        return;
    } while (1);
}
function* sub_1d6f6() {
    push(r16[bx]);
    memory16set(ds, 0x589e, r16[bx]);
    r16[bx] = 0x589d;
    yield* sub_1c939();
    r16[bx] = pop();
}
function* sub_1d706() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, si + 1);
        push(si);
        yield* sub_1d83e();
        di = r16[bx];
        r16[ax] = 0;
    case 0x1d711:
        r8[al]++;
        r16[tx] = r16[bx];
        r16[bx] -= 0x000d;
        if (r16s[tx] - signed16(0x000d) >= 0) {
            pc = 0x1d711;
            break;
        }
        r16[bx] += 0x000d;
        r8[bl] <<= 1;
        r8[bl]++;
        yield* sub_1fb6d();
        if (r8[bl] == 0x01) {
            pc = 0x1d737;
            break;
        }
        if (r8[al] == 0x01) {
            pc = 0x1d737;
            break;
        }
        r8[cl] = memory[ds*16 + di + 1403];
        r8[cl] &= 0x0f;
        if (r8[cl] == 0) {
            pc = 0x1d737;
            break;
        }
        yield* sub_1fb58();
    case 0x1d737:
        r8[bl]++;
        yield* sub_1fb6d();
        if (r8[al] == 0x01) {
            pc = 0x1d74c;
            break;
        }
        r8[cl] = memory[ds*16 + di + 1404];
        r8[cl] &= 0x0f;
        if (r8[cl] == 0) {
            pc = 0x1d74c;
            break;
        }
        yield* sub_1fb58();
    case 0x1d74c:
        r8[al]++;
        r8[cl] = memory[ds*16 + di + 1430];
        r8[cl] &= 0x0f;
        if (r8[cl] != 0) {
            pc = 0x1d75a;
            break;
        }
        yield* sub_1fb6d();
    case 0x1d75a:
        if (r8[bl] == 0x1a) {
            pc = 0x1d76d;
            break;
        }
        r8[bl]++;
        r8[cl] = memory[ds*16 + di + 1431];
        r8[cl] &= 0x0f;
        if (r8[cl] != 0) {
            pc = 0x1d76d;
            break;
        }
        yield* sub_1fb6d();
    case 0x1d76d:
        si = pop();
        return;
    } while (1);
}
function* sub_1d7c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r8[dl] = 0;
        yield* sub_1fb90();
        si = pop();
        r8[ah] = 0;
        r8[ch] = r8[ah];
        r8[cl] = memory[ds*16 + 0x4988];
        if (r16[cx] == 0) {
            pc = 0x1d7df;
            break;
        }
        r16[bx] = 0x49f9;
        yield* sub_1d7e7();
    case 0x1d7df:
        r16[bx] = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1d7e7:
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0x06) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x10) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x20) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x22) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x24) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x26) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x2a) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0e) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x1c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x2c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x28) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x12) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0a) {
            pc = 0x1d831;
            break;
        }
        if (r8[al] == 0x04) {
            pc = 0x1d838;
            break;
        }
        if (r8[al] != 0x02) {
            pc = 0x1d82b;
            break;
        }
    case 0x1d829:
        memory[ds*16 + r16[bx]] = r8[ah];
    case 0x1d82b:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d7e7;
            break;
        }
        return;
    case 0x1d831:
        memory16set(ds, r16[bx] + 5, 0x0000);
        pc = 0x1d82b;
        break;
    case 0x1d838:
        memory[ds*16 + r16[bx] + 10] = 0x01;
        pc = 0x1d82b;
        break;
        return;
    } while (1);
}
function* sub_1d7e7() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1d7e7:
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0x06) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x10) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x20) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x22) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x24) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x26) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x2a) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0e) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x1c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x2c) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x28) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x12) {
            pc = 0x1d829;
            break;
        }
        if (r8[al] == 0x0a) {
            pc = 0x1d831;
            break;
        }
        if (r8[al] == 0x04) {
            pc = 0x1d838;
            break;
        }
        if (r8[al] != 0x02) {
            pc = 0x1d82b;
            break;
        }
    case 0x1d829:
        memory[ds*16 + r16[bx]] = r8[ah];
    case 0x1d82b:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d7e7;
            break;
        }
        return;
    case 0x1d831:
        memory16set(ds, r16[bx] + 5, 0x0000);
        pc = 0x1d82b;
        break;
    case 0x1d838:
        memory[ds*16 + r16[bx] + 10] = 0x01;
        pc = 0x1d82b;
        break;
        return;
    } while (1);
}
function* sub_1d83e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
        yield* sub_1d877();
        si = 0x49f9;
        r8[cl] = memory[ds*16 + 0x4988];
        if (r16[cx] == 0) {
            pc = 0x1d854;
            break;
        }
        yield* sub_1d877();
    case 0x1d854:
        r8[cl] = memory[ds*16 + 0x4985];
        if (r16[cx] == 0)
            return;
        si = 0x5291;
    case 0x1d85d:
        if (memory[ds*16 + si] == 0x06) {
            pc = 0x1d867;
            break;
        }
        if (memory[ds*16 + si] != 0x04) {
            pc = 0x1d871;
            break;
        }
    case 0x1d867:
        di = memory16get(ds, si + 1);
        if (r16[bx] != memory16get(ds, di + 5)) {
            pc = 0x1d871;
            break;
        }
        memory[ds*16 + si] = r8[ch];
    case 0x1d871:
        si += 0x0003;
        if (--r16[cx]) {
            pc = 0x1d85d;
            break;
        }
        return;
    } while (1);
}
function* sub_1d877() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1d877:
        if (memory[ds*16 + si] != 0x18) {
            pc = 0x1d884;
            break;
        }
        if (memory16get(ds, si + 5) != r16[bx]) {
            pc = 0x1d884;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1d884:
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1d877;
            break;
        }
        return;
    } while (1);
}
function* sub_1d88a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1d8f2();
        if (!(r8[ah] & 0x03)) {
            pc = 0x1d8e6;
            break;
        }
        if (!(r8[ah] & 0x0c)) {
            pc = 0x1d8ec;
            break;
        }
        yield* sub_1d918();
        if (!flags.zero) {
            pc = 0x1d8b3;
            break;
        }
        yield* sub_1d8e6();
        pc = 0x1d8ec;
        break;
    case 0x1d8b3:
        r8[ah] &= 0x0c;
        r8[cl] &= 0x0c;
        if (r8[ah] == r8[cl]) {
            pc = 0x1d8e6;
            break;
        }
        pc = 0x1d8ec;
        break;
    case 0x1d8e6:
        push(r16[ax]);
        yield* sub_1cf47();
        r16[ax] = pop();
        return;
    case 0x1d8ec:
        push(r16[ax]);
        yield* sub_1cf4d();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1d8a1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1d8f2();
        if (!(r8[ah] & 0x03)) {
            pc = 0x1d8e6;
            break;
        }
        if (!(r8[ah] & 0x0c)) {
            pc = 0x1d8ec;
            break;
        }
        yield* sub_1d918();
        if (flags.zero) {
            pc = 0x1d8bf;
            break;
        }
        r8[ah] &= 0x0c;
        r8[cl] &= 0x0c;
        if (r8[ah] == r8[cl]) {
            pc = 0x1d8e6;
            break;
        }
        pc = 0x1d8ec;
        break;
    case 0x1d8bf:
        r8[cl] = memory[ds*16 + r16[bx] + 1430];
        if (r8s[ah] >= signed8(0x08)) {
            pc = 0x1d8cc;
            break;
        }
        r8[cl] = memory[ds*16 + r16[bx] + 1404];
    case 0x1d8cc:
        r8[cl] &= 0x0f;
        if (r8[cl] == 0) {
            pc = 0x1d8e6;
            break;
        }
        r8[cl] = memory[ds*16 + r16[bx] + 1418];
        if (!(r8[ah] & 0x01)) {
            pc = 0x1d8de;
            break;
        }
        r8[cl] = memory[ds*16 + r16[bx] + 1416];
    case 0x1d8de:
        r8[cl] &= 0x0f;
        if (r8[cl] == 0) {
            pc = 0x1d8ec;
            break;
        }
        yield* sub_1d8ec();
    case 0x1d8e6:
        push(r16[ax]);
        yield* sub_1cf47();
        r16[ax] = pop();
        return;
    case 0x1d8ec:
        push(r16[ax]);
        yield* sub_1cf4d();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1d8e6() {
    push(r16[ax]);
    yield* sub_1cf47();
    r16[ax] = pop();
}
function* sub_1d8ec() {
    push(r16[ax]);
    yield* sub_1cf4d();
    r16[ax] = pop();
}
function* sub_1d8f2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0;
        r8[dl] &= 0x0f;
        if (r8[dl] > 0x02) {
            pc = 0x1d8ff;
            break;
        }
        r8[ah] |= 0x01;
    case 0x1d8ff:
        if (r8[dl] < 0x0d) {
            pc = 0x1d907;
            break;
        }
        r8[ah] |= 0x02;
    case 0x1d907:
        if (r8[dh] > 0x02) {
            pc = 0x1d90f;
            break;
        }
        r8[ah] |= 0x04;
    case 0x1d90f:
        if (r8[dh] < 0x05)
            return;
        r8[ah] |= 0x08;
        return;
    } while (1);
}
function* sub_1d918() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = 0x0a;
        if (memory[ds*16 + si + 8] & 0x80) {
            pc = 0x1d922;
            break;
        }
        r8[cl] = 0x06;
    case 0x1d922:
        if (memory[ds*16 + si + 6] & 0x80) {
            pc = 0x1d92e;
            break;
        }
        r8[cl] &= 0x0c;
        r8[cl] |= 0x01;
    case 0x1d92e:
        flags.zero = r8[ah] == r8[cl];
        return;
    } while (1);
}
function* sub_1d931() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(r8[ch] & 0x10))
            return;
        if (memory[ds*16 + 0x48eb] >= 0x04)
            return;
        memory[ds*16 + 0x48eb] += 1;
        push(r16[bx]);
        r8[bl] = memory[ds*16 + di + 2];
        r8[bl] &= 0xf8;
        r8[dl] = memory[ds*16 + di + 4];
        pc = 0x1d961;
        break;
    case 0x1d961:
        memory[ds*16 + 0x58ad] = r8[bl];
        memory[ds*16 + 0x58af] = r8[dl];
        yield* sub_1d97d();
        memory[ds*16 + 0x58b4] = r8[ch];
        r16[bx] = 0x58ab;
        yield* sub_1c939();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1d94d() {
    if (!(r8[ch] & 0x10))
        return;
    if (memory[ds*16 + 0x48eb] >= 0x04)
        return;
    memory[ds*16 + 0x48eb] += 1;
    push(r16[bx]);
    yield* sub_1d5a8();
    memory[ds*16 + 0x58ad] = r8[bl];
    memory[ds*16 + 0x58af] = r8[dl];
    yield* sub_1d97d();
    memory[ds*16 + 0x58b4] = r8[ch];
    r16[bx] = 0x58ab;
    yield* sub_1c939();
    r16[bx] = pop();
}
function* sub_1d97d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1d97d;
        break;
    case 0x1d978:
        r8[bl] = r8[ch];
        yield* sub_1d443();
    case 0x1d97d:
        yield* sub_1bce1();
        di = 0x48f5;
        r16[bx] = 0;
        r8[ch] = r8[bh];
    case 0x1d987:
        r8[ch] += 0x08;
        r8[bl] += 0x02;
        di++;
        if (r8[al] > memory[ds*16 + di]) {
            pc = 0x1d987;
            break;
        }
        if (r8[ch] == 0x08) {
            pc = 0x1d9a5;
            break;
        }
        if (r8[ch] == 0x68) {
            pc = 0x1d9ab;
            break;
        }
    case 0x1d99c:
        yield* sub_1d9f8();
        if (flags.carry) {
            pc = 0x1d97d;
            break;
        }
        switch (r16[bx])
        {
        case 2: pc = 0x1d9c9; break;
        case 4: pc = 0x1d9d8; break;
        case 6: pc = 0x1d9f7; break;
        case 8: pc = 0x1d9b9; break;
        case 10: pc = 0x1d9b1; break;
        case 12: pc = 0x1d9c1; break;
        case 14: pc = 0x1d9f7; break;
        case 16: pc = 0x1d9b1; break;
        case 18: pc = 0x1d9f0; break;
        case 20: pc = 0x1d9f7; break;
        case 22: pc = 0x1d9e8; break;
        case 24: pc = 0x1d9e0; break;
        case 26: pc = 0x1d9f7; break;
        case 28: pc = 0x1db56; break;
        case 30: pc = 0x1db38; break;
        case 32: pc = 0x1db87; break;
        case 34: pc = 0x1dbc3; break;
        case 36: pc = 0x1dae2; break;
        case 38: pc = 0x1db27; break;
        case 40: pc = 0x1dbdc; break;
        case 42: pc = 0x1dadb; break;
        case 44: pc = 0x1db17; break;
        case 46: pc = 0x1db7b; break;
        case 48: pc = 0x1db4c; break;
        case 50: pc = 0x1db42; break;
        case 52: pc = 0x1daab; break;
            default:
            assert(0);
        }
        break;
    case 0x1d9a5:
        r8[bl] = 0x1a;
        r8[ch] = 0x68;
        pc = 0x1d99c;
        break;
    case 0x1d9ab:
        r8[bl] = 0x02;
        r8[ch] = 0x08;
        pc = 0x1d99c;
        break;
    case 0x1d9b1:
        if (memory[ds*16 + 0x48ea] != 0x01) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9b9:
        if (memory[ds*16 + 0x48e0] != 0x00) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9c1:
        if (memory[ds*16 + 0x48d5] != 0x00) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9c9:
        if (memory[ds*16 + 0x48cf] == 0x0f) {
            pc = 0x1d978;
            break;
        }
        if (memory[ds*16 + 0x48cf] == 0x0c) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9d8:
        if (memory[ds*16 + 0x48cf] == 0x00) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9e0:
        if (memory[ds*16 + 0x48cf] == 0x06) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9e8:
        if (memory[ds*16 + 0x48cf] == 0x09) {
            pc = 0x1d978;
            break;
        }
        return;
    case 0x1d9f0:
        if (memory[ds*16 + 0x48cf] == 0x13) {
            pc = 0x1d978;
            break;
        }
    case 0x1d9f7:
        return;
    case 0x1daab:
        if (memory[ds*16 + 0x48ea] > 0x01) {
            pc = 0x1dad2;
            break;
        }
        if (memory[ds*16 + 0x48cf] == 0x0f) {
            pc = 0x1dacd;
            break;
        }
        yield* sub_1bce1();
        if (r8[al] < 0x50) {
            pc = 0x1dad2;
            break;
        }
        if (r8[al] < 0xa0) {
            pc = 0x1dacd;
            break;
        }
        yield* sub_1dacd();
        memory[ds*16 + 0x48e9] = 0x01;
        return;
    case 0x1dacd:
        r8[al] = memory[ds*16 + 0x586c];
        pc = 0x1dae5;
        break;
    case 0x1dad2:
        yield* sub_1db56();
        memory[ds*16 + 0x4808] = 0x01;
        return;
    case 0x1dadb:
        r16[bx] = 0x5919;
        yield* sub_1c939();
        return;
    case 0x1dae2:
        r8[al] = memory[ds*16 + 0x586b];
    case 0x1dae5:
        memory[ds*16 + 0x592e] = r8[al];
        di = memory16get(ds, 0x4d5f);
        bp = memory16get(ds, 0x4d61);
        r16[cx] = memory16get(ds, 0x4d63);
        r16[ax] = memory16get(ds, 0x4d65);
        memory16set(ds, 0x5925, di);
        memory16set(ds, 0x5927, bp);
        memory16set(ds, 0x5929, r16[cx]);
        memory16set(ds, 0x592b, r16[ax]);
        r16[bx] = 0x5924;
        yield* sub_1c939();
        return;
    case 0x1db17:
        r8[al] = memory[ds*16 + 0x48d8];
        memory[ds*16 + 0x48db] = r8[al];
        r16[bx] = 0x2a62;
        pc = 0x1db59;
        break;
    case 0x1db27:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        memory[ds*16 + 0x48d5] = 0x01;
        return;
    case 0x1db38:
        r16[bx] = 0x2a7d;
        pc = 0x1db59;
        break;
    case 0x1db42:
        r16[bx] = 0x2a87;
        pc = 0x1db59;
        break;
    case 0x1db4c:
        r16[bx] = 0x2a91;
        pc = 0x1db59;
        break;
    case 0x1db56:
        r16[bx] = 0x2ab6;
    case 0x1db59:
        di = 0x48cf;
        r16[cx] = 0x0005;
    case 0x1db5f:
        r8[al] = memory[cs*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1db5f;
            break;
        }
        memory16set(ds, di, r16[cx]);
        memory16set(ds, di + 2, r16[cx]);
        memory[ds*16 + 0x4808] = r8[cl];
        memory[ds*16 + 0x48e9] = r8[cl];
        return;
    case 0x1db7b:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        memory[ds*16 + 0x48e9] = 0x01;
        return;
    case 0x1db87:
        if (memory[ds*16 + 0x48e8] <= 0x12) {
            pc = 0x1dbc2;
            break;
        }
        memory[ds*16 + 0x48e8] -= 0x04;
        bp = 0x0020;
        r16[bx] = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1db9e:
        if (memory[ds*16 + r16[bx]] != 0x06) {
            pc = 0x1dbbd;
            break;
        }
        r16[dx] = bp;
        if (memory[ds*16 + r16[bx] + 6] & 0x80) {
            pc = 0x1dbad;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dbad:
        memory16set(ds, r16[bx] + 5, memory16get(ds, r16[bx] + 5) + r16[dx]);
        r16[dx] = bp;
        if (memory[ds*16 + r16[bx] + 8] & 0x80) {
            pc = 0x1dbba;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dbba:
        memory16set(ds, r16[bx] + 7, memory16get(ds, r16[bx] + 7) + r16[dx]);
    case 0x1dbbd:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1db9e;
            break;
        }
    case 0x1dbc2:
        return;
    case 0x1dbc3:
        yield* sub_1dca8();
        memory[ds*16 + 0x48e0] = 0x01;
        memory[ds*16 + 0x47e1] = 0x00;
        r16[bx] = 0x590e;
        memory16set(ds, r16[bx] + 5, 0x7ffe);
        yield* sub_1c939();
        return;
    case 0x1dbdc:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        r16[bx] = 0x020b;
        yield* sub_1f0d2();
        memory[ds*16 + 0x0497] += 1;
        yield* sub_1d6f2();
        r8[cl] = memory[ds*16 + 0x0497];
        if (r8[cl] > 0x06)
            return;
        push(si);
        r8[ch] = 0;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] -= 0x0016;
        r16[bx] = 0x00c8;
        r16[dx] = 0x00c3;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_1fb4c();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        yield* sub_1fb46();
        si = pop();
        return;
    } while (1);
}
function* sub_1d9f8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = 0x04;
        di = 0x48f2;
    case 0x1d9fd:
        if (r8[ch] == memory[ds*16 + di]) {
            pc = 0x1da19;
            break;
        }
        di++;
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x1d9fd;
            break;
        }
        r8[cl] = 0x04;
        di = 0x48f2;
    case 0x1da0b:
        if (memory[ds*16 + di] == 0x00) {
            pc = 0x1da15;
            break;
        }
        di++;
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0x1da0b;
            break;
        }
    case 0x1da15:
        memory[ds*16 + di] = r8[ch];
        flags.carry = false;
        return;
    case 0x1da19:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1da1b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[bl] = 0x2f;
    case 0x1da1d:
        r8[bl]++;
        r8[tl] = r8[al];
        r8[al] -= 0x0a;
        if (r8s[tl] - signed8(0x0a) >= 0) {
            pc = 0x1da1d;
            break;
        }
        r8[al] += 0x0a;
        if (r8[bl] != 0x30) {
            pc = 0x1da2c;
            break;
        }
        r8[bl] = 0x20;
    case 0x1da2c:
        memory[ds*16 + 0x48c2] = r8[bl];
        r8[al] += 0x30;
        memory[ds*16 + 0x48c3] = r8[al];
        return;
    } while (1);
}
function* sub_1da36() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x495d;
        push(di);
        yield* sub_1da58();
        r8[cl] = r8[al];
        yield* sub_1da58();
        r8[cl] = r8[ah];
        yield* sub_1da58();
        di = pop();
        r16[cx] = 0x0006;
        r16[bx] = 0x2030;
    case 0x1da4e:
        if (r8[bl] != memory[ds*16 + di])
            return;
        memory[ds*16 + di] = r8[bh];
        di++;
        if (--r16[cx]) {
            pc = 0x1da4e;
            break;
        }
        return;
    } while (1);
}
function* sub_1da58() {
    push(r16[cx]);
    r8[cl] >>= 1;
    r8[cl] >>= 1;
    r8[cl] >>= 1;
    r8[cl] >>= 1;
    yield* sub_1da68();
    r16[cx] = pop();
    r8[cl] &= 0x0f;
    r8[cl] += 0x30;
    memory[ds*16 + di] = r8[cl];
    di++;
}
function* sub_1da68() {
    r8[cl] += 0x30;
    memory[ds*16 + di] = r8[cl];
    di++;
}
function* sub_1da6f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        si = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1da78:
        if (memory[ds*16 + si] != 0x06) {
            pc = 0x1da86;
            break;
        }
        if (memory16get(ds, si + 5) != 0x0000) {
            pc = 0x1da86;
            break;
        }
        yield* sub_1cebd();
    case 0x1da86:
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1da78;
            break;
        }
        si = pop();
        return;
    } while (1);
}
function* sub_1da8d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1da8d;
        break;
    case 0x1d9f7:
        return;
    case 0x1da8d:
        yield* sub_1da6f();
        r16[ax] = 0x0100;
        yield* sub_1b130();
        r8[bl] = memory[ds*16 + si + 9];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] &= 0xfe;
        r8[bh] = 0;
        if (r8[bl] >= 0x1c) {
            pc = 0x1daab;
            break;
        }
        switch (r16[bx])
        {
        case 0: pc = 0x1d9f7; break;
        case 2: pc = 0x1db56; break;
        case 4: pc = 0x1db38; break;
        case 6: pc = 0x1db87; break;
        case 8: pc = 0x1dbc3; break;
        case 10: pc = 0x1dae2; break;
        case 12: pc = 0x1db27; break;
        case 14: pc = 0x1dbdc; break;
        case 16: pc = 0x1dadb; break;
        case 18: pc = 0x1db17; break;
        case 20: pc = 0x1db7b; break;
        case 22: pc = 0x1db4c; break;
        case 24: pc = 0x1db42; break;
        case 26: pc = 0x1daab; break;
            default:
            assert(0);
        }
        break;
    case 0x1daab:
        if (memory[ds*16 + 0x48ea] > 0x01) {
            pc = 0x1dad2;
            break;
        }
        if (memory[ds*16 + 0x48cf] == 0x0f) {
            pc = 0x1dacd;
            break;
        }
        yield* sub_1bce1();
        if (r8[al] < 0x50) {
            pc = 0x1dad2;
            break;
        }
        if (r8[al] < 0xa0) {
            pc = 0x1dacd;
            break;
        }
        yield* sub_1dacd();
        memory[ds*16 + 0x48e9] = 0x01;
        return;
    case 0x1dacd:
        r8[al] = memory[ds*16 + 0x586c];
        pc = 0x1dae5;
        break;
    case 0x1dad2:
        yield* sub_1db56();
        memory[ds*16 + 0x4808] = 0x01;
        return;
    case 0x1dadb:
        r16[bx] = 0x5919;
        yield* sub_1c939();
        return;
    case 0x1dae2:
        r8[al] = memory[ds*16 + 0x586b];
    case 0x1dae5:
        memory[ds*16 + 0x592e] = r8[al];
        di = memory16get(ds, 0x4d5f);
        bp = memory16get(ds, 0x4d61);
        r16[cx] = memory16get(ds, 0x4d63);
        r16[ax] = memory16get(ds, 0x4d65);
        memory16set(ds, 0x5925, di);
        memory16set(ds, 0x5927, bp);
        memory16set(ds, 0x5929, r16[cx]);
        memory16set(ds, 0x592b, r16[ax]);
        r16[bx] = 0x5924;
        yield* sub_1c939();
        return;
    case 0x1db17:
        r8[al] = memory[ds*16 + 0x48d8];
        memory[ds*16 + 0x48db] = r8[al];
        r16[bx] = 0x2a62;
        pc = 0x1db59;
        break;
    case 0x1db27:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        memory[ds*16 + 0x48d5] = 0x01;
        return;
    case 0x1db38:
        r16[bx] = 0x2a7d;
        pc = 0x1db59;
        break;
    case 0x1db42:
        r16[bx] = 0x2a87;
        pc = 0x1db59;
        break;
    case 0x1db4c:
        r16[bx] = 0x2a91;
        pc = 0x1db59;
        break;
    case 0x1db56:
        r16[bx] = 0x2ab6;
    case 0x1db59:
        di = 0x48cf;
        r16[cx] = 0x0005;
    case 0x1db5f:
        r8[al] = memory[cs*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1db5f;
            break;
        }
        memory16set(ds, di, r16[cx]);
        memory16set(ds, di + 2, r16[cx]);
        memory[ds*16 + 0x4808] = r8[cl];
        memory[ds*16 + 0x48e9] = r8[cl];
        return;
    case 0x1db7b:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        memory[ds*16 + 0x48e9] = 0x01;
        return;
    case 0x1db87:
        if (memory[ds*16 + 0x48e8] <= 0x12) {
            pc = 0x1dbc2;
            break;
        }
        memory[ds*16 + 0x48e8] -= 0x04;
        bp = 0x0020;
        r16[bx] = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1db9e:
        if (memory[ds*16 + r16[bx]] != 0x06) {
            pc = 0x1dbbd;
            break;
        }
        r16[dx] = bp;
        if (memory[ds*16 + r16[bx] + 6] & 0x80) {
            pc = 0x1dbad;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dbad:
        memory16set(ds, r16[bx] + 5, memory16get(ds, r16[bx] + 5) + r16[dx]);
        r16[dx] = bp;
        if (memory[ds*16 + r16[bx] + 8] & 0x80) {
            pc = 0x1dbba;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dbba:
        memory16set(ds, r16[bx] + 7, memory16get(ds, r16[bx] + 7) + r16[dx]);
    case 0x1dbbd:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1db9e;
            break;
        }
    case 0x1dbc2:
        return;
    case 0x1dbc3:
        yield* sub_1dca8();
        memory[ds*16 + 0x48e0] = 0x01;
        memory[ds*16 + 0x47e1] = 0x00;
        r16[bx] = 0x590e;
        memory16set(ds, r16[bx] + 5, 0x7ffe);
        yield* sub_1c939();
        return;
    case 0x1dbdc:
        r16[bx] = 0x2a73;
        yield* sub_1db59();
        r16[bx] = 0x020b;
        yield* sub_1f0d2();
        memory[ds*16 + 0x0497] += 1;
        yield* sub_1d6f2();
        r8[cl] = memory[ds*16 + 0x0497];
        if (r8[cl] > 0x06)
            return;
        push(si);
        r8[ch] = 0;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] -= 0x0016;
        r16[bx] = 0x00c8;
        r16[dx] = 0x00c3;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_1fb4c();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        yield* sub_1fb46();
        si = pop();
        return;
    } while (1);
}
function* sub_1dacd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x586c];
        pc = 0x1dae5;
        break;
    case 0x1dae5:
        memory[ds*16 + 0x592e] = r8[al];
        di = memory16get(ds, 0x4d5f);
        bp = memory16get(ds, 0x4d61);
        r16[cx] = memory16get(ds, 0x4d63);
        r16[ax] = memory16get(ds, 0x4d65);
        memory16set(ds, 0x5925, di);
        memory16set(ds, 0x5927, bp);
        memory16set(ds, 0x5929, r16[cx]);
        memory16set(ds, 0x592b, r16[ax]);
        r16[bx] = 0x5924;
        yield* sub_1c939();
        return;
    } while (1);
}
function* sub_1db0d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x2a52;
        pc = 0x1db59;
        break;
    case 0x1db59:
        di = 0x48cf;
        r16[cx] = 0x0005;
    case 0x1db5f:
        r8[al] = memory[cs*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1db5f;
            break;
        }
        memory16set(ds, di, r16[cx]);
        memory16set(ds, di + 2, r16[cx]);
        memory[ds*16 + 0x4808] = r8[cl];
        memory[ds*16 + 0x48e9] = r8[cl];
        return;
    } while (1);
}
function* sub_1db56() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x2ab6;
        di = 0x48cf;
        r16[cx] = 0x0005;
    case 0x1db5f:
        r8[al] = memory[cs*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1db5f;
            break;
        }
        memory16set(ds, di, r16[cx]);
        memory16set(ds, di + 2, r16[cx]);
        memory[ds*16 + 0x4808] = r8[cl];
        memory[ds*16 + 0x48e9] = r8[cl];
        return;
    } while (1);
}
function* sub_1db59() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x48cf;
        r16[cx] = 0x0005;
    case 0x1db5f:
        r8[al] = memory[cs*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1db5f;
            break;
        }
        memory16set(ds, di, r16[cx]);
        memory16set(ds, di + 2, r16[cx]);
        memory[ds*16 + 0x4808] = r8[cl];
        memory[ds*16 + 0x48e9] = r8[cl];
        return;
    } while (1);
}
function* sub_1dbe2() {
    r16[bx] = 0x020b;
    yield* sub_1f0d2();
    memory[ds*16 + 0x0497] += 1;
    yield* sub_1d6f2();
    r8[cl] = memory[ds*16 + 0x0497];
    if (r8[cl] > 0x06)
        return;
    push(si);
    r8[ch] = 0;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] -= 0x0016;
    r16[bx] = 0x00c8;
    r16[dx] = 0x00c3;
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1fb4c();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1fb46();
    si = pop();
}
function* sub_1dbef() {
    r8[cl] = memory[ds*16 + 0x0497];
    if (r8[cl] > 0x06)
        return;
    push(si);
    r8[ch] = 0;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] -= 0x0016;
    r16[bx] = 0x00c8;
    r16[dx] = 0x00c3;
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1fb4c();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1fb46();
    si = pop();
}
function* sub_1dc1a() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1dc26();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1dc26() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x48e7] -= 1;
        if (memory[ds*16 + 0x48e7] != 0)
            return;
        bp = 0x0009;
        if (memory[ds*16 + 0x48e8] >= 0x28) {
            pc = 0x1dc3e;
            break;
        }
        memory[ds*16 + 0x48e8] += 0x04;
        bp = 0x0020;
    case 0x1dc3e:
        memory[ds*16 + 0x48e7] = 0x28;
        r16[bx] = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
    case 0x1dc4b:
        if (memory[ds*16 + r16[bx]] != 0x06) {
            pc = 0x1dc6a;
            break;
        }
        r16[dx] = bp;
        if (!(memory[ds*16 + r16[bx] + 6] & 0x80)) {
            pc = 0x1dc5a;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dc5a:
        memory16set(ds, r16[bx] + 5, memory16get(ds, r16[bx] + 5) + r16[dx]);
        r16[dx] = bp;
        if (!(memory[ds*16 + r16[bx] + 8] & 0x80)) {
            pc = 0x1dc67;
            break;
        }
        r16[dx] = -r16[dx];
    case 0x1dc67:
        memory16set(ds, r16[bx] + 7, memory16get(ds, r16[bx] + 7) + r16[dx]);
    case 0x1dc6a:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1dc4b;
            break;
        }
        return;
    } while (1);
}
function* sub_1dc70() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x4d5e;
        r16[cx] = memory16get(ds, 0x48e3);
        r16[cx]++;
        r8[bh] = 0;
    case 0x1dc7a:
        if (memory[ds*16 + di] == 0x06) {
            pc = 0x1dc89;
            break;
        }
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1dc7a;
            break;
        }
    case 0x1dc84:
        r8[bl] = memory[ds*16 + 0x48d8];
        return;
    case 0x1dc89:
        r8[cl] = 0;
        yield* sub_1bce1();
        if (r8[al] > 0x08) {
            pc = 0x1dc94;
            break;
        }
        r8[cl]++;
    case 0x1dc94:
        if (memory[ds*16 + di + 4] > 0xb0) {
            pc = 0x1dc84;
            break;
        }
        r8[bl] = memory[ds*16 + di + 2];
        r8[bl] -= 0x0c;
        if (r8[bl] < 0xf0)
            return;
        r8[bl] = 0x04;
        return;
    } while (1);
}
function* sub_1dca8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48e0] == 0x00) {
            pc = 0x1dcc0;
            break;
        }
        r16[bx] = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1dcb6:
        if (memory[ds*16 + r16[bx]] == 0x1e) {
            pc = 0x1dcc1;
            break;
        }
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1dcb6;
            break;
        }
    case 0x1dcc0:
        return;
    case 0x1dcc1:
        memory[ds*16 + r16[bx]] = 0x00;
        return;
    } while (1);
}
function* sub_1dcc5() {
    r16[bx] = 0x0203;
    yield* sub_1f0d2();
    memory[ds*16 + di + 10] = 0x14;
    memory[ds*16 + di + 1] = 0x05;
}
function* sub_1dcd4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        si = memory16get(ds, si + 1);
        pc = 0x1dceb;
        break;
    case 0x1dceb:
        r16[cx] = memory16get(ds, si + 1);
        r16[dx] = memory16get(ds, si + 3);
        r8[bl] = memory[ds*16 + si + 9];
        r8[bh] = 0;
        r8[bl] += 0x0a;
        yield* sub_1fb4c();
        si = pop();
        return;
    } while (1);
}
function* sub_1dcda() {
    r8[al] = memory[ds*16 + 0x48f0];
    r8[tl] = memory[ds*16 + si + 10];
    memory[ds*16 + si + 10] -= r8[al];
    if (r8[tl] > r8[al])
        return;
    push(si);
    memory[ds*16 + si] = 0x00;
    r16[bx] = si;
    yield* sub_1d6cd();
    r16[cx] = memory16get(ds, si + 1);
    r16[dx] = memory16get(ds, si + 3);
    r8[bl] = memory[ds*16 + si + 9];
    r8[bh] = 0;
    r8[bl] += 0x0a;
    yield* sub_1fb4c();
    si = pop();
}
function* sub_1dcfe() {
    push(si);
    di = memory16get(ds, si + 1);
    r16[cx] = memory16get(ds, di + 1);
    r16[dx] = memory16get(ds, di + 3);
    r16[bx] = 0x000f;
    yield* sub_1fb4c();
    si = pop();
}
function* sub_1dd10() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + r16[bx] + 1183] == 0x01)
            return;
        push(r16[cx]);
        push(r16[bx]);
        push(r16[ax]);
        push(si);
        if (!(r8[ch] & 0x20)) {
            pc = 0x1dd2c;
            break;
        }
        si = r16[bx];
        yield* sub_1d5a8();
        di = r16[bx];
        yield* sub_1de68();
        pc = 0x1dd59;
        break;
    case 0x1dd2c:
        memory16set(ds, 0x58f2, r16[bx]);
        yield* sub_1d5a8();
        r8[cl] = r8[bl];
        r8[ch] = 0;
        r8[dh] = r8[ch];
        memory16set(ds, 0x58ee, r16[cx]);
        memory16set(ds, 0x58f0, r16[dx]);
        memory[ds*16 + 0x58f6] = r8[al];
        r16[bx] = 0x000f;
        yield* sub_1fb4c();
        r16[bx] = 0x58ed;
        yield* sub_1c939();
        yield* sub_1d6d1();
        r16[bx] = 0x0203;
        yield* sub_1f0d2();
    case 0x1dd59:
        si = pop();
        r16[ax] = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_1dd5e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0589;
        r16[cx] = 0x0012;
        r16[dx] = 0x000a;
    case 0x1dd67:
        push(r16[cx]);
        r16[cx] = 0x000d;
        di = 0x0008;
    case 0x1dd6e:
        push(r16[cx]);
        r8[bh] = 0x00;
        r8[bl] = memory[ds*16 + si];
        r8[bl] &= 0x0f;
        if (r8[bl] == 0) {
            pc = 0x1dd8b;
            break;
        }
        if (r8[bl] > 0x03) {
            pc = 0x1dd8b;
            break;
        }
        yield* sub_1dda7();
        r16[cx] = di;
        push(di);
        push(si);
        push(r16[dx]);
        yield* sub_1fb46();
        r16[dx] = pop();
        si = pop();
        di = pop();
    case 0x1dd8b:
        si++;
        r16[cx] = pop();
        di += 0x0010;
        if (--r16[cx]) {
            pc = 0x1dd6e;
            break;
        }
        r16[cx] = pop();
        r16[dx] += 0x0007;
        if (--r16[cx]) {
            pc = 0x1dd67;
            break;
        }
        return;
    } while (1);
}
function* sub_1dd99() {
    memory[ds*16 + 0x48e1] = 0x01;
    yield* sub_1dd5e();
    memory[ds*16 + 0x48e1] = 0x00;
}
function* sub_1dda7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48e1] == 0x00) {
            pc = 0x1ddb2;
            break;
        }
        r8[bl] += 0x0a;
        return;
    case 0x1ddb2:
        r8[bl] = 0x0f;
        return;
    } while (1);
}
function* sub_1ddb5() {
    yield* sub_1db0d();
    memory[ds*16 + 0x48d8] = 0x64;
    memory[ds*16 + 0x48d7] = 0x14;
    r16[bx] = 0x00d9;
    r8[cl] = 0x64;
    yield* sub_1fb89();
    yield* sub_1ccfc();
    yield* sub_1f961();
    yield* sub_1c46f();
    memory[ds*16 + 0x48cf] = 0x03;
    yield* sub_1ccfc();
}
function* sub_1ddec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0493];
        r16[bx] = 0x592f;
        if (r8[al] == 0x10) {
            pc = 0x1de00;
            break;
        }
        r16[bx] = 0x5934;
        if (r8[al] == 0x21) {
            pc = 0x1de00;
            break;
        }
        r16[bx] = 0x5871;
    case 0x1de00:
        yield* sub_1c939();
        si = 0x5892;
        di = 0x4d5e;
        yield* sub_1c912();
        r16[bx] = 0x587c;
        yield* sub_1c939();
        memory[ds*16 + 0x48ea] = 0x01;
        r16[ax] = 0;
        memory[ds*16 + 0x48da] = r8[al];
        memory16set(ds, 0x48f2, r16[ax]);
        memory16set(ds, 0x48f4, r16[ax]);
        memory[ds*16 + 0x48e9] = r8[al];
        memory[ds*16 + 0x4937] = r8[al];
        memory[ds*16 + 0x4938] = r8[al];
        memory[ds*16 + 0x48e7] = 0x28;
        return;
    } while (1);
}
function* sub_1de31() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0;
        r16[cx] = 0x0012;
        r8[dl] = 0x0a;
        bp = 0x0000;
    case 0x1de3b:
        push(r16[cx]);
        r16[cx] = 0x000d;
        di = 0x0008;
    case 0x1de42:
        push(r16[cx]);
        if (!(memory[ds*16 + si + 1417] & 0x20)) {
            pc = 0x1de57;
            break;
        }
        r8[al] = memory[ds*16 + si + 1417];
        r8[al] &= 0x0f;
        if (r8[al] <= 0x03) {
            pc = 0x1de57;
            break;
        }
        yield* sub_1de68();
    case 0x1de57:
        si++;
        r16[cx] = pop();
        di += 0x0010;
        if (--r16[cx]) {
            pc = 0x1de42;
            break;
        }
        r16[cx] = pop();
        bp += 0x000d;
        r8[dl] += 0x07;
        if (--r16[cx]) {
            pc = 0x1de3b;
            break;
        }
        return;
    } while (1);
}
function* sub_1de68() {
    r8[al] = memory[ds*16 + si + 1417];
    memory[ds*16 + si + 1417] = 0x00;
    memory[ds*16 + 0x58a9] = r8[al];
    memory[ds*16 + 0x58a1] = r8[al];
    r16[ax] = di;
    memory[ds*16 + 0x58a2] = r8[al];
    memory[ds*16 + 0x58a4] = r8[dl];
    memory16set(ds, 0x58a7, si);
    r8[al] = memory[ds*16 + si + 1183];
    memory[ds*16 + 0x58a8] = r8[al];
    r16[ax] = bp;
    memory[ds*16 + 0x58a3] = r8[al];
    r16[bx] = 0x58a0;
    push(r16[dx]);
    push(di);
    yield* sub_1c939();
    r16[bx] = si;
    yield* sub_1d158();
    di = pop();
    r16[dx] = pop();
}
function* sub_1dea0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x4d69;
        r8[ah] = 0;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1dea9:
        r8[al] = memory[ds*16 + r16[bx]];
        if (r8[al] == 0x1a) {
            pc = 0x1dece;
            break;
        }
        if (r8[al] != 0x0a) {
            pc = 0x1dec8;
            break;
        }
        r8[al] = memory[ds*16 + r16[bx] + 7];
        di = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9];
        r8[al] |= 0x20;
        memory[ds*16 + di + 1417] = r8[al];
    case 0x1dec1:
        r8[al] = memory[ds*16 + 0x0496];
        memory[ds*16 + di + 1183] = r8[al];
    case 0x1dec8:
        r16[bx] += 0x000b;
        if (--r16[cx]) {
            pc = 0x1dea9;
            break;
        }
        return;
    case 0x1dece:
        di = memory16get(ds, r16[bx] + 7);
        memory[ds*16 + di + 1417] = 0x02;
        pc = 0x1dec1;
        break;
        return;
    } while (1);
}
function* sub_1ded8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x48e6] == 0x00)
            return;
        memory[ds*16 + 0x48e6] -= 1;
        di = 0x4d69;
        r8[ah] = 0;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1deec:
        if (memory[ds*16 + di] != 0x0a) {
            pc = 0x1df0b;
            break;
        }
        push(r16[cx]);
        r8[bh] = r8[ch];
        r8[dh] = r8[ch];
        r8[bl] = memory[ds*16 + di + 1];
        r8[bl] &= 0x0f;
        r8[bl] += 0x0a;
        r8[cl] = memory[ds*16 + di + 2];
        r8[dl] = memory[ds*16 + di + 4];
        push(di);
        yield* sub_1fb4c();
        di = pop();
        r16[cx] = pop();
    case 0x1df0b:
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1deec;
            break;
        }
        return;
    } while (1);
}
function* sub_1df25() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + si + 3];
        pc = 0x1df2d;
        break;
    case 0x1df2d:
        memory[ds*16 + 0x58ba] = r8[al];
        push(r16[bx]);
        r8[al] = memory[ds*16 + si + 1];
        r8[al] += 0x08;
        memory[ds*16 + 0x58b8] = r8[al];
        r16[bx] = memory16get(ds, 0x48ee);
        r16[bx]++;
        if (r8[bl] < memory[ds*16 + 0x48ed]) {
            pc = 0x1df46;
            break;
        }
        r16[bx] = 0;
    case 0x1df46:
        memory16set(ds, 0x48ee, r16[bx]);
        r8[bl] = memory[ds*16 + r16[bx] + 2638];
        r8[bl]--;
        memory[ds*16 + 0x58bd] = r8[bl];
        r8[al] = memory[ds*16 + r16[bx] + 18800];
        memory[ds*16 + 0x58be] = r8[al];
        yield* sub_1bce1();
        r8[ah] = 0x0f;
        if (r8[bl] != 0x04) {
            pc = 0x1df67;
            break;
        }
        r8[ah] = 0x7f;
    case 0x1df67:
        r8[al] &= r8[ah];
        memory[ds*16 + 0x58bb] = r8[al];
        r16[bx] = 0x58b6;
        yield* sub_1c939();
        memory[ds*16 + 0x48ec] += 1;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1df2b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x0b;
        memory[ds*16 + 0x58ba] = r8[al];
        push(r16[bx]);
        r8[al] = memory[ds*16 + si + 1];
        r8[al] += 0x08;
        memory[ds*16 + 0x58b8] = r8[al];
        r16[bx] = memory16get(ds, 0x48ee);
        r16[bx]++;
        if (r8[bl] < memory[ds*16 + 0x48ed]) {
            pc = 0x1df46;
            break;
        }
        r16[bx] = 0;
    case 0x1df46:
        memory16set(ds, 0x48ee, r16[bx]);
        r8[bl] = memory[ds*16 + r16[bx] + 2638];
        r8[bl]--;
        memory[ds*16 + 0x58bd] = r8[bl];
        r8[al] = memory[ds*16 + r16[bx] + 18800];
        memory[ds*16 + 0x58be] = r8[al];
        yield* sub_1bce1();
        r8[ah] = 0x0f;
        if (r8[bl] != 0x04) {
            pc = 0x1df67;
            break;
        }
        r8[ah] = 0x7f;
    case 0x1df67:
        r8[al] &= r8[ah];
        memory[ds*16 + 0x58bb] = r8[al];
        r16[bx] = 0x58b6;
        yield* sub_1c939();
        memory[ds*16 + 0x48ec] += 1;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1df78() {
    push(r16[bx]);
    r8[cl] = r8[bl];
    r8[cl] += 0x05;
    r16[bx] = 0x58c1;
    memory[ds*16 + r16[bx] + 2] = r8[cl];
    push(r16[cx]);
    yield* sub_1c939();
    r16[cx] = pop();
    r8[cl] += 0x13;
    r16[bx] = 0x58c1;
    memory[ds*16 + r16[bx] + 2] = r8[cl];
    yield* sub_1c939();
    r16[bx] = 0x0201;
    yield* sub_1f0d2();
    r16[bx] = pop();
}
function* sub_1df9d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x48f0);
        r16[tx] = memory16get(ds, si + 5);
        memory16set(ds, si + 5, memory16get(ds, si + 5) - r16[ax]);
        if (r16[tx] > r16[ax])
            return;
        r16[bx] = memory16get(ds, si + 7);
        push(r16[bx]);
        yield* sub_1dfc5();
        r16[bx] = pop();
        if (flags.carry) {
            pc = 0x1dfbf;
            break;
        }
        memory[ds*16 + r16[bx] + 1417] = 0x02;
        r8[al] = memory[ds*16 + 0x0496];
        memory[ds*16 + r16[bx] + 1183] = r8[al];
        yield* sub_1dcda();
        return;
    case 0x1dfbf:
        memory16set(ds, si + 5, 0x003c);
        return;
    } while (1);
}
function* sub_1dfc5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1d5a8();
        di = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1dfcf:
        r8[al] = memory[ds*16 + di];
        if (r8[al] == 0x0a) {
            pc = 0x1dff9;
            break;
        }
        if (r8[al] != 0x0e) {
            pc = 0x1e013;
            break;
        }
        r8[al] = memory[ds*16 + di + 4];
        r8[al] -= 0x07;
        if (r8[al] > r8[dl]) {
            pc = 0x1e013;
            break;
        }
        r8[al] += 0x17;
        if (r8[al] < r8[dl]) {
            pc = 0x1e013;
            break;
        }
        r8[al] = memory[ds*16 + di + 2];
        r8[al] -= 0x10;
        if (r8[al] > r8[bl]) {
            pc = 0x1e013;
            break;
        }
        r8[al] += 0x20;
        if (r8[al] < r8[bl]) {
            pc = 0x1e013;
            break;
        }
        pc = 0x1e01a;
        break;
    case 0x1dff9:
        if (r8[dl] != memory[ds*16 + di + 4]) {
            pc = 0x1e013;
            break;
        }
        r8[al] = memory[ds*16 + di + 2];
        if (r8[bl] < r8[al]) {
            pc = 0x1e00d;
            break;
        }
        r8[al] += 0x10;
        if (r8[bl] > r8[al]) {
            pc = 0x1e013;
            break;
        }
        pc = 0x1e01a;
        break;
    case 0x1e00d:
        r8[al] -= 0x10;
        if (r8[bl] > r8[al]) {
            pc = 0x1e01a;
            break;
        }
    case 0x1e013:
        di += 0x000b;
        if (--r16[cx]) {
            pc = 0x1dfcf;
            break;
        }
        flags.carry = false;
        return;
    case 0x1e01a:
        flags.carry = true;
        return;
    } while (1);
}
function* sub_1e01c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        if (memory[ds*16 + 0x48d8] < 0xba) {
            pc = 0x1e029;
            break;
        }
        memory[ds*16 + 0x48d8] = 0xba;
    case 0x1e029:
        memory[ds*16 + 0x48e6] = 0x02;
        r16[bx] = 0x0206;
        yield* sub_1f0d2();
        yield* sub_1fb42();
        yield* sub_1ded8();
        yield* sub_1e1da();
        yield* sub_1fb2b();
        yield* sub_1fb42();
        yield* sub_1ded8();
        r16[bx] = 0x00cc;
        r8[ch] = 0;
        r8[cl] = memory[ds*16 + 0x48d8];
        r16[dx] = 0x00bb;
        yield* sub_1fb89();
        yield* sub_1fb46();
        r16[cx] = 0x0003;
        r16[bx] = 0x00db;
    case 0x1e05e:
        push(r16[cx]);
        push(r16[bx]);
        r16[cx] = 0x001e;
    case 0x1e063:
        yield* sub_1f961();
        if (--r16[cx]) {
            pc = 0x1e063;
            break;
        }
        r8[cl] = memory[ds*16 + 0x48d8];
        r16[dx] = 0x00bb;
        yield* sub_1fb85();
        yield* sub_1fb46();
        r16[bx] = pop();
        r16[cx] = pop();
        r16[bx]--;
        if (--r16[cx]) {
            pc = 0x1e05e;
            break;
        }
        r16[cx] = 0x001e;
    case 0x1e07d:
        yield* sub_1f961();
        if (--r16[cx]) {
            pc = 0x1e07d;
            break;
        }
        r8[cl] = memory[ds*16 + 0x48d8];
        r16[dx] = 0x00bb;
        yield* sub_1fb85();
        memory[ds*16 + 0x0a4c] = 0x02;
        si = pop();
        return;
    } while (1);
}
function* sub_1e093() {
    yield* sub_1e0ca();
    r16[cx] = 0x0058;
    r16[dx] = 0x0092;
    yield* sub_1fb46();
    r16[bx] = 0x0058;
    r16[cx] = 0x00a2;
    r8[al] = 0x0f;
    si = 0x48c6;
    yield* sub_1fb79();
    r8[al] = 0x0f;
    r16[bx] = 0x0058;
    r16[cx] = 0x00aa;
    si = 0x48bc;
    yield* sub_1fb79();
    r8[al] = 0x0f;
    r16[bx] = 0x00f0;
    r16[cx] = 0x0096;
    si = 0x48bc;
    yield* sub_1fb75();
}
function* sub_1e0ca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x0a49];
        memory[ds*16 + 0x48cd] = r8[al];
        yield* sub_1e0fa();
        r8[ah] = 0;
        if (r8[al] == 0x00) {
            pc = 0x1e0f4;
            break;
        }
        if (r8[al] == 0x11) {
            pc = 0x1e0f4;
            break;
        }
        r8[ah]++;
        if (r8[al] == 0x10) {
            pc = 0x1e0f4;
            break;
        }
        if (r8[al] == 0x21) {
            pc = 0x1e0f4;
            break;
        }
        r8[ah]++;
        if (r8[al] < 0x10) {
            pc = 0x1e0f0;
            break;
        }
        r8[ah] += 0x02;
    case 0x1e0f0:
        r8[ah] += memory[ds*16 + 0x0494];
    case 0x1e0f4:
        r16[bx] = 0x00be;
        r8[bl] += r8[ah];
        return;
    } while (1);
}
function* sub_1e0fa() {
    r8[al] = memory[ds*16 + 0x0493];
    push(r16[ax]);
    r8[al]++;
    yield* sub_1da1b();
    r16[ax] = pop();
}
function* sub_1e105() {
    yield* sub_1fb2b();
    yield* sub_1fb2f();
    yield* sub_1ccfc();
}
function* sub_1e12b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[cl] = memory[ds*16 + 0x4988];
        r8[ch] = 0;
        if (r16[cx] == 0) {
            pc = 0x1e139;
            break;
        }
        si = 0x49f9;
        yield* sub_1e140();
    case 0x1e139:
        si = 0x4d69;
        r16[cx] = memory16get(ds, 0x48e3);
    case 0x1e140:
        if (memory[ds*16 + si] != 0x1e) {
            pc = 0x1e148;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1e148:
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1e140;
            break;
        }
        return;
    } while (1);
}
function* sub_1e140() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1e140:
        if (memory[ds*16 + si] != 0x1e) {
            pc = 0x1e148;
            break;
        }
        memory[ds*16 + si] = 0x00;
    case 0x1e148:
        si += 0x000b;
        if (--r16[cx]) {
            pc = 0x1e140;
            break;
        }
        return;
    } while (1);
}
function* sub_1e14e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x0a4c] = 0x01;
        r16[bx] = 0x0210;
        yield* sub_1f0d2();
        yield* sub_1e1da();
        memory[ds*16 + 0x48e6] = 0x02;
        r16[bx] = 0x0003;
        yield* sub_1ce35();
        r16[cx] = 0x0028;
        if (memory[ds*16 + 0x48d8] < 0x64) {
            pc = 0x1e177;
            break;
        }
        r8[cl] = 0xe0;
        r8[cl] -= memory[ds*16 + 0x48d8];
    case 0x1e177:
        push(r16[cx]);
        r16[dx] = 0x00bb;
        r8[cl] = memory[ds*16 + 0x48dd];
        r8[cl] += memory[ds*16 + 0x48d8];
        memory[ds*16 + 0x48d8] = r8[cl];
        if (r8[cl] < 0xe6) {
            pc = 0x1e1af;
            break;
        }
        if (memory[ds*16 + 0x048f] == 0x07) {
            pc = 0x1e1d7;
            break;
        }
        r8[al] = 0xfe;
        if (memory[ds*16 + 0x048f] == 0x04) {
            pc = 0x1e1a7;
            break;
        }
        r8[al] = 0xfc;
        if (memory[ds*16 + 0x048f] == 0x09) {
            pc = 0x1e1a7;
            break;
        }
        r8[al] = 0xff;
    case 0x1e1a7:
        r8[dl] += r8[al];
        r8[ch] = 0xff;
        r16[cx] += 0x0140;
    case 0x1e1af:
        r16[bx] = 0x00cc;
        yield* sub_1fb3b();
        yield* sub_1fb4c();
        r16[bx] = 0x000d;
        r16[cx] = 0x00e0;
        r16[dx] = 0x00a1;
        yield* sub_1fb52();
        memory[cs*16 + 0x325a] = 0x00;
        yield* sub_1c750();
        yield* sub_1f961();
        yield* sub_1f961();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1e177;
            break;
        }
    case 0x1e1d6:
        return;
    case 0x1e1d7:
        r16[cx] = pop();
        pc = 0x1e1d6;
        break;
        return;
    } while (1);
}
function* sub_1e1da() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[dl] = 0;
        yield* sub_1fb90();
        yield* sub_1fb85();
        if (memory[ds*16 + 0x0493] == 0x10) {
            pc = 0x1e1f1;
            break;
        }
        if (memory[ds*16 + 0x0493] == 0x21) {
            pc = 0x1e1f1;
            break;
        }
        return;
    case 0x1e1f1:
        yield* sub_1f969();
        r8[al] = 0x00;
        pc = 0x1fb9b;
        break;
    case 0x1fb9b:
        yield *jumpIndirect(cs, memory16get(ds, 0x6413));
        return;
    } while (1);
}
function* sub_1e1f9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, si + 1);
        r16[ax] += memory16get(ds, 0x48f0);
        if (r16[ax] < memory16get(ds, si + 3)) {
            pc = 0x1e20d;
            break;
        }
        r16[bx] = 0x5939;
        yield* sub_1c939();
        r16[ax] = 0;
    case 0x1e20d:
        memory16set(ds, si + 1, r16[ax]);
        return;
    } while (1);
}
function* sub_1e211() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1e211;
        break;
    case 0x1e208:
        yield* sub_1c939();
        r16[ax] = 0;
    case 0x1e20d:
        memory16set(ds, si + 1, r16[ax]);
        return;
    case 0x1e211:
        r16[ax] = memory16get(ds, si + 1);
        r16[ax] += memory16get(ds, 0x48f0);
        if (r16[ax] < memory16get(ds, si + 3)) {
            pc = 0x1e20d;
            break;
        }
    case 0x1e21d:
        yield* sub_1bce1();
        di = 0x4939;
        r8[ah] = 0x10;
        r16[cx] = 0x0004;
    case 0x1e228:
        r8[ah] >>= 1;
        if (r8[al] <= memory[ds*16 + di]) {
            pc = 0x1e233;
            break;
        }
        di += 0x0005;
        if (--r16[cx]) {
            pc = 0x1e228;
            break;
        }
    case 0x1e233:
        if (memory[ds*16 + 0x4937] & r8[ah]) {
            pc = 0x1e21d;
            break;
        }
        memory[ds*16 + 0x4937] = memory[ds*16 + 0x4937] | r8[ah];
        r8[ah] ^= 0xff;
        memory[ds*16 + 0x5955] = r8[ah];
        r16[ax] = memory16get(ds, di + 1);
        r16[dx] = memory16get(ds, di + 3);
        memory[ds*16 + 0x5951] = r8[al];
        memory[ds*16 + 0x5953] = r8[ah];
        memory[ds*16 + 0x5950] = r8[dl];
        memory[ds*16 + 0x5952] = r8[dh];
        r8[cl] <<= 1;
        r8[cl] <<= 1;
        memory[ds*16 + 0x5954] = r8[cl];
        r16[bx] = 0x594f;
        pc = 0x1e208;
        break;
        return;
    } while (1);
}
function* sub_1e266() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x48ec];
        if (r8[al] >= memory[ds*16 + 0x48ed])
            return;
        r16[ax] = memory16get(ds, si + 1);
        r16[ax] += memory16get(ds, 0x48f0);
        if (r16[ax] < memory16get(ds, si + 5)) {
            pc = 0x1e2a3;
            break;
        }
        r8[al] = memory[ds*16 + 0x058b];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2a1;
            break;
        }
        r8[al] = memory[ds*16 + 0x058c];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2a1;
            break;
        }
        r8[al] = memory[ds*16 + 0x0598];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2a1;
            break;
        }
        r8[al] = memory[ds*16 + 0x0599];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2a1;
            break;
        }
        r16[bx] = 0x5903;
        memory[ds*16 + r16[bx] + 1] = 0x28;
        yield* sub_1c939();
    case 0x1e2a1:
        r16[ax] = 0;
    case 0x1e2a3:
        memory16set(ds, si + 1, r16[ax]);
        r16[ax] = memory16get(ds, si + 3);
        r16[ax] += memory16get(ds, 0x48f0);
        if (r16[ax] < memory16get(ds, si + 7)) {
            pc = 0x1e2da;
            break;
        }
        r8[al] = memory[ds*16 + 0x0592];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2d8;
            break;
        }
        r8[al] = memory[ds*16 + 0x0593];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2d8;
            break;
        }
        r8[al] = memory[ds*16 + 0x059f];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2d8;
            break;
        }
        r8[al] = memory[ds*16 + 0x05a0];
        r8[al] &= 0x0f;
        if (r8[al] != 0) {
            pc = 0x1e2d8;
            break;
        }
        r16[bx] = 0x5903;
        memory[ds*16 + r16[bx] + 1] = 0xa0;
        yield* sub_1c939();
    case 0x1e2d8:
        r16[ax] = 0;
    case 0x1e2da:
        memory16set(ds, si + 3, r16[ax]);
        return;
    } while (1);
}
function* sub_1e2de() {
    r8[al] = memory[ds*16 + 0x48f0];
    r8[tl] = memory[ds*16 + si + 10];
    memory[ds*16 + si + 10] -= r8[al];
    if (r8s[tl] - r8s[al] > 0)
        return;
    memory[ds*16 + si + 10] = 0x3c;
    r16[ax] = memory16get(ds, 0x0491);
    if (memory16get(ds, 0x4965) == r16[ax])
        return;
    memory16set(ds, 0x4965, r16[ax]);
    r8[cl] = memory[ds*16 + 0x0490];
    r16[bx] = 0x58d7;
    memory16set(ds, r16[bx] + 5, r16[ax]);
    memory[ds*16 + r16[bx] + 7] = r8[cl];
    yield* sub_1c939();
}
function* sub_1e307() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x1e307:
        yield* sub_1f961();
        if (--r16[cx]) {
            pc = 0x1e307;
            break;
        }
        return;
    } while (1);
}
function* sub_1f042() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x5960);
        r16[ax] |= memory16get(ds, 0x5962);
        if (!r16[ax]) {
            pc = 0x1f062;
            break;
        }
        push(ds);
        r16[dx] = memory16get(ds, 0x5960);
        ds = memory16get(ds, 0x5962);
        r16[ax] = 0x2508;
        interrupt(0x21);
        ds = pop();
        r16[ax] = 0;
        memory16set(ds, 0x5960, r16[ax]);
        memory16set(ds, 0x5962, r16[ax]);
    case 0x1f062:
        r8[al] = 0x36;
        out8(0x43, r8[al]);
        r8[al] = 0;
        out8(0x40, r8[al]);
        out8(0x40, r8[al]);
        r16[ax] = 0;
        memory16set(ds, 0x595e, r16[ax]);
        return;
    } while (1);
}
function* sub_1f072() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x40e5;
        r16[bx] = 0x4239;
        r16[cx] = 0x4069;
        if (memory[cs*16 + 0x325b] & 0x10) {
            pc = 0x1f09e;
            break;
        }
        r16[ax] = 0x4133;
        r16[bx] = 0x4228;
        r16[cx] = 0x403a;
        if (memory[cs*16 + 0x325b] & 0x08) {
            pc = 0x1f09e;
            break;
        }
        r16[ax] = 0x40eb;
        r16[bx] = 0x4221;
        r16[cx] = 0x4021;
    case 0x1f09e:
        memory16set(cs, 0x3261, r16[ax]);
        memory16set(cs, 0x3263, r16[bx]);
        memory16set(cs, 0x3265, r16[cx]);
        r16[ax] = 0x3508;
        interrupt(0x21);
        memory16set(ds, 0x5960, r16[bx]);
        memory16set(ds, 0x5962, es);
        r16[ax] = cs;
        ds = r16[ax];
        r16[dx] = 0x40ab;
        r16[ax] = 0x2508;
        interrupt(0x21);
        ds = pop();
        yield* sub_1f971();
        r16[ax] = memory16get(ds, 0x595c);
        memory16set(ds, 0x595e, r16[ax]);
        r16[bx] = 0x0000;
        push(r16[ax]);
        memory[cs*16 + 0x325c] = r8[bh];
        r8[al] = r8[bh];
        r8[bh] = 0;
        yield *jumpIndirect(cs, memory16get(cs, 0x3265));
        return;
    } while (1);
}
function* sub_1f0d2() {
    push(r16[ax]);
    memory[cs*16 + 0x325c] = r8[bh];
    r8[al] = r8[bh];
    r8[bh] = 0;
    yield *jumpIndirect(cs, memory16get(cs, 0x3265));
}
function* sub_1f129() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!r8[bl]) {
            pc = 0x1f151;
            break;
        }
        memory[ds*16 + r16[bx] + 22883] = r8[al];
        r16[tx] = r16[bx];
        r16[bx] = r16[ax];
        r16[ax] = r16[tx];
        r16[ax]--;
        if (!(memory[cs*16 + 0x325b] & r8[bl])) {
            pc = 0x1f141;
            break;
        }
        push(cs);
        cs = 0x19ee;
        yield* sub_1b06b();
        assert(cs == 0x1b0c);
        r16[ax] = pop();
        return;
    case 0x1f141:
        if (r8[al] != 0x0d) {
            pc = 0x1f14f;
            break;
        }
        push(cs);
        cs = 0x19ee;
        yield* sub_1b06b();
        assert(cs == 0x1b0c);
        push(cs);
        cs = 0x19ee;
        yield* sub_1b0b1();
        assert(cs == 0x1b0c);
    case 0x1f14f:
        r16[ax] = pop();
        return;
    case 0x1f151:
        push(cs);
        cs = 0x19ee;
        yield* sub_1b07f();
        assert(cs == 0x1b0c);
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_1f158() {
    if (!(memory[cs*16 + 0x325b] & 0x10))
        return;
    r16[ax] = 0x1766;
    push(cs);
    cs = 0x19ee;
    yield* sub_1b060();
    assert(cs == 0x1b0c);
}
function* sub_1f16c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = cs;
        ds = r16[ax];
        memory[ds*16 + 0x3259] += 1;
        memory16set(ds, 0x325d, memory16get(ds, 0x325d) + 1);
        memory[ds*16 + 0x325a] += 1;
        if (memory[ds*16 + 0x325a] != 0) {
            pc = 0x1f183;
            break;
        }
        memory16set(ds, 0x325f, memory16get(ds, 0x325f) + 1);
    case 0x1f183:
        r8[al] = memory[ds*16 + 0x40aa];
        r8[al] += 0x05;
        if (r8[al] < memory[ds*16 + 0x40a9]) {
            pc = 0x1f1a0;
            break;
        }
        r8[al] -= memory[ds*16 + 0x40a9];
        memory[ds*16 + 0x40aa] = r8[al];
        yield* callIndirect(cs, memory16get(ds, 0x3261));
    case 0x1f199:
        r8[al] = 0x20;
        out8(0x20, r8[al]);
        ds = pop();
        r16[ax] = pop();
        stop();
    case 0x1f1a0:
        memory[ds*16 + 0x40aa] = r8[al];
        pc = 0x1f199;
        break;
        return;
    } while (1);
}
function* sub_1f286() {
    r8[al] = 0x06;
    out8(0x43, r8[al]);
    r8[al] = in8(0x40);
    r8[ah] = r8[al];
    r8[al] = in8(0x40);
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
}
function* sub_1f293() {
    r16[bx] = 0x04b0;
    yield* sub_1f2b5();
    r8[al] = 0xb6;
    out8(0x43, r8[al]);
    r8[al] = r8[bl];
    out8(0x42, r8[al]);
    r8[al] = r8[bh];
    out8(0x42, r8[al]);
    yield* sub_1f961();
    yield* sub_1f961();
    yield* sub_1f961();
    yield* sub_1f961();
    yield* sub_1f2e1();
}
function* sub_1f2b5() {
    r8[al] = in8(0x61);
    r8[al] |= 0x03;
    out8(0x61, r8[al]);
}
function* sub_1f2bc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory[cs*16 + 0x325b] & 0x10))
            return;
        r8[cl] = r8[al];
        r16[bx] = 0x5964;
        r16[ax] = 0;
    case 0x1f2cb:
        if (!(memory[ds*16 + r16[bx]] & r8[cl])) {
            pc = 0x1f2d4;
            break;
        }
        push(cs);
        cs = 0x19ee;
        yield* sub_1b0b6();
        assert(cs == 0x1b0c);
    case 0x1f2d4:
        r16[bx]++;
        r16[ax]++;
        if (r16[ax] < 0x0012) {
            pc = 0x1f2cb;
            break;
        }
        return;
    } while (1);
}
function* sub_1f2dc() {
    yield *jumpIndirect(cs, memory16get(cs, 0x3263));
}
function* sub_1f2e1() {
    r8[al] = in8(0x61);
    r8[al] &= 0xfc;
    out8(0x61, r8[al]);
}
function* sub_1f311() {
    if (!(memory[cs*16 + 0x325b] & 0x10))
        return;
    push(cs);
    cs = 0x19ee;
    yield* sub_1b07f();
    assert(cs == 0x1b0c);
}
function* sub_1f320(resume) {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (resume)
        {
            //goto resume_1b0c_4269;
            pc = 0x4269;
            break;
        }
        pc = 0x1f320;
        break;
    case 0x1c4d9:
        return;
    case 0x1c4da:
        yield* sub_1c3a8();
        yield* sub_1f042();
        yield* sub_1b45a();
        r8[al] = 0x03;
        yield* sub_1f2dc();
        yield* sub_1c363();
        yield* sub_1f8c5();
        r16[ax] = 0x1118;
        ds = r16[ax];
        r16[dx] = memory16get(ds, 0x480f);
        r8[ah] = 0x09;
        interrupt(0x21);
        r16[ax] = 0x4c00;
        interrupt(0x21);
        if (memory[ds*16 + 0x47e0] == 0x00) {
            pc = 0x1c4d9;
            break;
        }
        memory[cs*16 + 0x1339] = 0x00;
        pc = 0x1dbe2;
        break;
    case 0x1dbe2:
        r16[bx] = 0x020b;
        yield* sub_1f0d2();
        memory[ds*16 + 0x0497] += 1;
        yield* sub_1d6f2();
        r8[cl] = memory[ds*16 + 0x0497];
        if (r8[cl] > 0x06) {
            pc = 0x1dc19;
            break;
        }
        push(si);
        r8[ch] = 0;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] -= 0x0016;
        r16[bx] = 0x00c8;
        r16[dx] = 0x00c3;
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_1fb4c();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        yield* sub_1fb46();
        si = pop();
    case 0x1dc19:
        return;
    case 0x1f320:
        yield* sub_1f6d9();
        yield* sub_1f6b1();
        yield* sub_1f64d();
    case 0x4269:
        if (flags.carry) {
            pc = 0x1f341;
            break;
        }
        yield* sub_1f66a();
        yield* sub_1f6be();
    case 0x1f331:
        push(r16[cx]);
        yield* sub_1f961();
        yield* sub_1c1ac();
        r16[cx] = pop();
        if (--r16[cx] && !r8[cl]) {
            pc = 0x1f331;
            break;
        }
        yield* sub_1f83b();
        if (resume)
            {
            yield* sub_1b0c0(true);
            assert(0);
        }
        return;
    case 0x1f341:
        r16[ax] = 0x5d95;
        memory16set(ds, 0x480f, r16[ax]);
        pc = 0x1c4da;
        break;
        return;
    } while (1);
}
function* sub_1f34a() {
    flags.carry = (r16[bx] + 0x000f) >= 0x10000;
    r16[bx] += 0x000f;
    r16[bx] = rcr16(r16[bx], 0x0001);
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[ax] += r16[bx];
    memory16set(cs, 0x429d, r16[ax]);
    flags.carry = false;
}
function* sub_1f35f() {
    push(r16[ax]);
    push(r16[bx]);
    yield* sub_1f37c_ctxswitch1();
    r16[bx] = pop();
    r16[ax] = pop();
    if (flags.carry)
        return;
    r16[cx] = 0;
    r16[dx] = 0;
    yield* sub_1f41f_ctxswitch2();
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1f404();
    r16[dx] = pop();
    r16[cx] = pop();
    flags.carry = false;
}
function* sub_1f364() {
    r16[bx] = pop();
    r16[ax] = pop();
    if (flags.carry)
        return;
    r16[cx] = 0;
    r16[dx] = 0;
    yield* sub_1f41f_ctxswitch2();
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1f404();
    r16[dx] = pop();
    r16[cx] = pop();
    flags.carry = false;
}
function* sub_1f36f() {
    push(r16[cx]);
    push(r16[dx]);
    yield* sub_1f404();
    r16[dx] = pop();
    r16[cx] = pop();
    flags.carry = false;
    yield* sub_1f320(true);
    assert(0);
}
function* sub_1f37c_ctxswitch1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        yield* sub_1f404();
        r8[ah] = 0x3d;
        r8[al] = 0;
        interrupt(0x21);
        if (!flags.carry) {
            pc = 0x1f388;
            break;
        }
        assert(pop() == 0x7777);
        return;
    case 0x1f388:
        memory16set(cs, 0x42ba, r16[ax]);
        r16[ax] = 0x1118;
        es = r16[ax];
        memory16set(es, 0x5d82, 0x0000);
        memory16set(es, 0x5d84, 0x0000);
        memory16set(es, 0x5d86, 0x0000);
        memory16set(es, 0x5d88, 0x0102);
        memory16set(es, 0x5d8a, 0x0000);
        memory16set(es, 0x5d8c, 0x0009);
        memory16set(es, 0x5d8e, 0x0200);
        memory[es*16 + 0x5d90] = 0x00;
        memory[es*16 + 0x5d91] = 0x00;
        memory16set(es, 0x5d80, 0x0000);
        r16[cx] = ss;
        r16[dx] = sp;
        flags.interrupts = false;
        r16[ax] = 0x10f8;
        ss = r16[ax];
        sp = 0x01fe;
        flags.interrupts = true;
        r16[ax] = 0x43f3;
        push(r16[ax]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(si);
        r16[ax] = 0x1118;
        push(r16[ax]);
        push(r16[ax]);
        memory16set(cs, 0x43ef, ss);
        memory16set(cs, 0x43f1, sp);
        flags.interrupts = false;
        ss = r16[cx];
        sp = r16[dx];
        flags.interrupts = true;
        flags.carry = false;
        assert(pop() == 0x7777);
        yield* sub_1f364();
        assert(0);
        return;
    } while (1);
}
function* sub_1f404() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(cs, 0x42ba) == 0xffff) {
            pc = 0x1f41d;
            break;
        }
        r8[ah] = 0x3e;
        r16[bx] = memory16get(cs, 0x42ba);
        interrupt(0x21);
        memory16set(cs, 0x42ba, 0xffff);
        return;
    case 0x1f41d:
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1f41f_ctxswitch2() {
    memory16set(cs, 0x455e, r16[ax]);
    memory16set(cs, 0x4560, r16[bx]);
    memory16set(cs, 0x43ae, r16[cx]);
    memory16set(cs, 0x43b0, r16[dx]);
    r16[ax] = 0;
    r16[bx] = 0;
    flags.carry = r16[ax] < r16[cx];
    r16[ax] -= r16[cx];
    r16[bx] -= r16[dx] + flags.carry;
    memory16set(cs, 0x4562, r16[ax]);
    memory16set(cs, 0x4564, r16[bx]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(di);
    push(si);
    push(ds);
    push(es);
    memory16set(cs, 0x43aa, ss);
    memory16set(cs, 0x43ac, sp);
    flags.interrupts = false;
    ss = memory16get(cs, 0x43ef);
    sp = memory16get(cs, 0x43f1);
    flags.interrupts = true;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    yield* sub_1f4b3();
}
function* sub_1f472_ctxswitch3() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(di);
    push(si);
    push(ds);
    push(es);
    memory16set(cs, 0x43ef, ss);
    memory16set(cs, 0x43f1, sp);
    flags.interrupts = false;
    ss = memory16get(cs, 0x43aa);
    sp = memory16get(cs, 0x43ac);
    flags.interrupts = true;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[tx] = flags.carry | (flags.zero << 1);
    push(r16[tx]);
    r16[cx] = memory16get(cs, 0x43ae);
    r16[dx] = memory16get(cs, 0x43b0);
    flags.carry = (r16[cx] + memory16get(cs, 0x4562)) >= 0x10000;
    r16[cx] += memory16get(cs, 0x4562);
    r16[dx] += memory16get(cs, 0x4564) + flags.carry;
    r16[tx] = pop();
    flags.carry = r16[tx] & 1;
    flags.zero = (r16[tx] << 1) & 1;
    yield* sub_1f36f();
}
function* sub_1f4b3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3f;
        r16[bx] = memory16get(cs, 0x42ba);
        r16[cx] = 0x0400;
        r16[dx] = 0x597e;
        interrupt(0x21);
    case 0x1f4c2:
        yield* sub_1f571();
        if (r16[ax] != 0x0101) {
            pc = 0x1f4ce;
            break;
        }
        flags.carry = false;
        yield* sub_1f472_ctxswitch3();
    case 0x1f4ce:
        if (r16[ax] != 0x0100) {
            pc = 0x1f4ed;
            break;
        }
        yield* sub_1f5da();
        yield* sub_1f571();
        memory16set(ds, 0x5d82, r16[ax]);
        memory16set(ds, 0x5d84, r16[ax]);
        memory[ds*16 + 0x5d91] = r8[al];
        memory[ds*16 + 0x5d90] = r8[al];
        r8[al] = memory[ds*16 + 0x5d91];
        yield* sub_1f5ed();
        pc = 0x1f4c2;
        break;
    case 0x1f4ed:
        memory16set(ds, 0x5d82, r16[ax]);
        memory16set(ds, 0x5d86, r16[ax]);
        es = memory16get(cs, 0x429d);
        if (r16s[ax] < memory16gets(ds, 0x5d88)) {
            pc = 0x1f50c;
            break;
        }
        r16[ax] = memory16get(ds, 0x5d84);
        memory16set(ds, 0x5d82, r16[ax]);
        r8[al] = memory[ds*16 + 0x5d90];
        push(r16[ax]);
        memory16set(ds, 0x5d8a, memory16get(ds, 0x5d8a) + 1);
    case 0x1f50c:
        if (memory16gets(ds, 0x5d82) <= signed16(0x00ff)) {
            pc = 0x1f52c;
            break;
        }
        r16[bx] = memory16get(ds, 0x5d82);
        yield* sub_1f626();
        r8[al] = memory[es*16 + r16[bx] + 2];
        push(r16[ax]);
        memory16set(ds, 0x5d8a, memory16get(ds, 0x5d8a) + 1);
        r16[ax] = memory16get(es, r16[bx]);
        memory16set(ds, 0x5d82, r16[ax]);
        pc = 0x1f50c;
        break;
    case 0x1f52c:
        push(ds);
        es = pop();
        r16[ax] = memory16get(ds, 0x5d82);
        memory[ds*16 + 0x5d90] = r8[al];
        memory[ds*16 + 0x5d91] = r8[al];
        push(r16[ax]);
        memory16set(ds, 0x5d8a, memory16get(ds, 0x5d8a) + 1);
        r16[cx] = memory16get(ds, 0x5d8a);
        if (r16[cx] == 0) {
            pc = 0x1f548;
            break;
        }
    case 0x1f542:
        r16[ax] = pop();
        yield* sub_1f5ed();
        if (--r16[cx]) {
            pc = 0x1f542;
            break;
        }
    case 0x1f548:
        memory16set(ds, 0x5d8a, r16[cx]);
        yield* sub_1f62d();
        r16[ax] = memory16get(ds, 0x5d86);
        memory16set(ds, 0x5d84, r16[ax]);
        r16[bx] = memory16get(ds, 0x5d88);
        if (r16s[bx] < memory16gets(ds, 0x5d8e)) {
            pc = 0x1f56e;
            break;
        }
        if (memory16get(ds, 0x5d8c) == 0x000c) {
            pc = 0x1f56e;
            break;
        }
        memory16set(ds, 0x5d8c, memory16get(ds, 0x5d8c) + 1);
        memory16set(ds, 0x5d8e, memory16get(ds, 0x5d8e) << 1);
    case 0x1f56e:
        pc = 0x1f4c2;
        break;
        return;
    } while (1);
}
function* sub_1f571() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x5d80);
        r16[ax] += memory16get(ds, 0x5d8c);
        r16[tx] = memory16get(ds, 0x5d80);
        memory16set(ds, 0x5d80, r16[ax]);
        r16[ax] = r16[tx];
        r16[dx] = r16[ax];
        r16[dx] &= 0x0007;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        if (r16s[ax] < signed16(0x03fd)) {
            pc = 0x1f5b7;
            break;
        }
        push(r16[dx]);
        r16[dx] += memory16get(ds, 0x5d8c);
        memory16set(ds, 0x5d80, r16[dx]);
        r16[cx] = 0x0400;
        bp = r16[ax];
        r16[cx] -= r16[ax];
        r16[ax] += 0x597e;
        si = r16[ax];
        di = 0x597e;
        rep_movsb_data_data_forward();
        r8[ah] = 0x3f;
        r16[bx] = memory16get(cs, 0x42ba);
        r16[cx] = bp;
        r16[dx] = di;
        interrupt(0x21);
        r16[ax] = 0;
        r16[dx] = pop();
    case 0x1f5b7:
        r16[ax] += 0x597e;
        si = r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        lodsb_data_forward();
        r16[cx] = r16[dx];
        if (r16[cx] == 0) {
            pc = 0x1f5ca;
            break;
        }
    case 0x1f5c4:
        flags.carry = r8[al] & 1;
        r8[al] >>= 1;
        r16[bx] = rcr16(r16[bx], 0x0001);
        if (--r16[cx]) {
            pc = 0x1f5c4;
            break;
        }
    case 0x1f5ca:
        r16[ax] = r16[bx];
        r16[bx] = memory16get(ds, 0x5d8c);
        r16[bx] -= 0x0009;
        r16[bx] <<= 1;
        r16[ax] &= memory16get(ds, r16[bx] + 22902);
        return;
    } while (1);
}
function* sub_1f5da() {
    memory16set(ds, 0x5d8c, 0x0009);
    memory16set(ds, 0x5d8e, 0x0200);
    memory16set(ds, 0x5d88, 0x0102);
}
function* sub_1f5ed() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        es = memory16get(cs, 0x455e);
        di = memory16get(cs, 0x4560);
        memory[es*16 + di] = r8[al];
        di = (di + 1) & 0xffff;
        if (di != 0) {
            pc = 0x1f605;
            break;
        }
        memory16set(cs, 0x455e, memory16get(cs, 0x455e) + 0x1000);
    case 0x1f605:
        memory16set(cs, 0x4560, di);
        es = pop();
        memory16set(cs, 0x4562, memory16get(cs, 0x4562) + 1);
        if (memory16get(cs, 0x4562) != 0)
            return;
        memory16set(cs, 0x4564, memory16get(cs, 0x4564) + 1);
        if (memory16get(cs, 0x4564) != 0)
            return;
        flags.carry = false;
        yield* sub_1f472_ctxswitch3();
        return;
    } while (1);
}
function* sub_1f626() {
    bp = r16[bx];
    r16[bx] <<= 1;
    r16[bx] += bp;
}
function* sub_1f62d() {
    r16[bx] = memory16get(ds, 0x5d88);
    yield* sub_1f626();
    push(es);
    es = memory16get(cs, 0x429d);
    r8[al] = memory[ds*16 + 0x5d91];
    memory[es*16 + r16[bx] + 2] = r8[al];
    r16[ax] = memory16get(ds, 0x5d84);
    memory16set(es, r16[bx], r16[ax]);
    es = pop();
    memory16set(ds, 0x5d88, memory16get(ds, 0x5d88) + 1);
}
function* sub_1f64d() {
    r16[ax] = memory16get(ds, 0x5e39);
    r16[ax] += memory16get(ds, 0x5dba);
    memory16set(ds, 0x5e3f, r16[ax]);
    r16[bx] = 0x0000;
    yield* sub_1f34a();
    r16[ax] = memory16get(ds, 0x5e39);
    r16[bx] = 0x0000;
    r16[dx] = 0x5dac;
    yield* sub_1f35f();
}
function* sub_1f66a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[dx] = memory16get(ds, 0x5e39);
        es = r16[dx];
        r16[bx] = memory16get(es, 0x018e);
        r16[ax] = memory16get(es, r16[bx] + 2);
        if (!(r8[al] & 0x0f)) {
            pc = 0x1f681;
            break;
        }
        r16[ax] += 0x0010;
    case 0x1f681:
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[dx] += r16[ax];
        memory16set(ds, 0x5e3b, r16[dx]);
        r16[bx] = memory16get(es, 0x01f8);
        es = r16[dx];
        r16[ax] = memory16get(es, r16[bx] + 2);
        if (!(r8[al] & 0x0f)) {
            pc = 0x1f6a1;
            break;
        }
        r16[ax] += 0x0010;
    case 0x1f6a1:
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[dx] += r16[ax];
        memory16set(ds, 0x5e3d, r16[dx]);
        es = pop();
        return;
    } while (1);
}
function* sub_1f6b1() {
//    r8[ah] = 0;
//    interrupt(0x1a);
//    memory16set(ds, 0x615b, r16[dx]);
//    memory16set(ds, 0x615d, r16[cx]);
}
function* sub_1f6be() {
/*
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0;
        interrupt(0x1a);
        flags.carry = r16[dx] < memory16get(ds, 0x615b);
        r16[dx] -= memory16get(ds, 0x615b);
        r16[cx] -= memory16get(ds, 0x615d) + flags.carry;
        if (r16[dx] > 0x005b) {
            pc = 0x1f6d5;
            break;
        }
        r16[cx] = 0x005c;
        r16[cx] -= r16[dx];
        return;
    case 0x1f6d5:
        r16[cx] = 0x0001;
        return;
    } while (1);
*/
    r16[cx] = 100;
}
function* sub_1f6d9() {
    push(es);
    push(ds);
    yield* sub_1f827();
    r8[bl] = memory[ds*16 + 0x048f];
    r16[ax]--;
    es = r16[ax];
    ds = r16[ax];
    si = 0x6ba0;
    si &= 0x000f;
    di = 0x4e20;
    yield* sub_1f854();
    yield* sub_1f6fc();
    ds = pop();
    yield* sub_1fb2b();
    es = pop();
    yield* sync();
}
function* sub_1f6fc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(ds);
        r16[bx] = ds;
        r16[bx] += 0x14b4;
        r16[ax] = 0x1118;
        ds = r16[ax];
        memory16set(ds, 0x5e3f, r16[bx]);
        yield* sub_1fb33();
        r16[ax] = r16[bx];
        ds = pop();
        r16[bx] = pop();
        si = 0x4e20;
        if (r8[bl] == 0x04) {
            pc = 0x1f79b;
            break;
        }
        if (r8[bl] == 0x09) {
            pc = 0x1f729;
            break;
        }
        if (r8[bl] == 0x0d) {
            pc = 0x1f749;
            break;
        }
        pc = 0x1f7eb;
        break;
    case 0x1f729:
        r16[ax] = 0xb800;
        es = r16[ax];
        r16[bx] = 0x0000;
        r16[cx] = 0x00c8;
    case 0x1f734:
        push(r16[bx]);
        push(r16[cx]);
        r16[cx] = 0x0000;
        yield* sub_2127e();
        di = r16[ax];
        r16[cx] = 0x0050;
        rep_movsw_data_data_forward();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x1f734;
            break;
        }
        return;
    case 0x1f749:
        r16[ax] = 0x1118;
        es = r16[ax];
        bp = memory16get(es, 0x5e37);
        r16[ax] = 0xa000;
        es = r16[ax];
        r8[bl] = 0x01;
        r16[dx] = 0x03c4;
    case 0x1f75d:
        r8[al] = 0x02;
        r8[ah] = r8[bl];
        out16(r16[dx], r16[ax]);
        di = bp;
        si = 0x4e20;
        r16[cx] = 0x1f40;
    case 0x1f76a:
        push(r16[cx]);
        r8[bh] = 0;
        r16[cx] = 0x0004;
    case 0x1f770:
        r8[bh] <<= 1;
        r8[bh] <<= 1;
        lodsb_data_forward();
        if (!(r8[bl] & r8[al])) {
            pc = 0x1f77c;
            break;
        }
        r8[bh] |= 0x01;
    case 0x1f77c:
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[al] >>= 1;
        if (!(r8[bl] & r8[al])) {
            pc = 0x1f78b;
            break;
        }
        r8[bh] |= 0x02;
    case 0x1f78b:
        if (--r16[cx]) {
            pc = 0x1f770;
            break;
        }
        r16[cx] = pop();
        r8[al] = r8[bh];
        stosb_video_forward();
        if (--r16[cx]) {
            pc = 0x1f76a;
            break;
        }
        r8[bl] <<= 1;
        if (r8s[bl] < signed8(0x09)) {
            pc = 0x1f75d;
            break;
        }
        return;
    case 0x1f79b:
        es = r16[ax];
        r16[ax] = 0x0020;
        yield* sub_20366();
        r16[cx] = 0x0000;
    case 0x1f7a6:
        push(r16[cx]);
        r16[bx] = 0x0000;
        yield* sub_20996();
        di = r16[bx];
        r16[cx] = 0x0050;
        r8[bh] = 0;
    case 0x1f7b4:
        push(r16[cx]);
        r16[cx] = 0x0002;
        r8[dl] = r8[ch];
    case 0x1f7ba:
        lodsb_data_forward();
        yield* sub_1f7d2();
        yield* sub_1f7d2();
        if (--r16[cx]) {
            pc = 0x1f7ba;
            break;
        }
        r8[al] = r8[dl];
        stosb_data_forward();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1f7b4;
            break;
        }
        r16[cx] = pop();
        r16[cx]++;
        if (r16[cx] != 0x00c8) {
            pc = 0x1f7a6;
            break;
        }
        return;
    case 0x1f7eb:
        es = r16[ax];
        r16[cx] = 0x0000;
        di = 0x0000;
    case 0x1f7f3:
        push(r16[cx]);
        r16[cx] = 0x0050;
        r8[bh] = 0;
    case 0x1f7f9:
        push(r16[cx]);
        r16[cx] = 0x0002;
        r8[dl] = r8[ch];
    case 0x1f7ff:
        lodsb_data_forward();
        yield* sub_1f7d2();
        yield* sub_1f7d2();
        if (--r16[cx]) {
            pc = 0x1f7ff;
            break;
        }
        r8[al] = r8[dl];
        stosb_data_forward();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1f7f9;
            break;
        }
        r16[cx] = pop();
        r16[cx]++;
        if (r16[cx] != 0x00c8) {
            pc = 0x1f7f3;
            break;
        }
        return;
    } while (1);
}
function* sub_1f7d2() {
    r8[dl] <<= 1;
    r8[dl] <<= 1;
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    r8[bl] = r8[al];
    r8[bl] &= 0x0f;
    r8[ah] = memory[cs*16 + r16[bx] + 18263];
    r8[dl] |= r8[ah];
}
function* sub_1f827() {
    r16[ax] = 0x6ba0;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax]++;
    r16[cx] = cs;
    r16[ax] += r16[cx];
    memory16set(ds, 0x5e39, r16[ax]);
}
function* sub_1f83b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(r16[ax]);
        push(r16[cx]);
        r16[ax] = 0;
        es = r16[ax];
        r8[al]++;
        memoryBiosSet(es, 0x0440, r8[al]);
        r16[cx] = 0x000a;
    case 0x1f84b:
        yield* sub_1f961();
        if (--r16[cx]) {
            pc = 0x1f84b;
            break;
        }
        r16[cx] = pop();
        r16[ax] = pop();
        es = pop();
        return;
    } while (1);
}
function* sub_1f854() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x7d00;
        r16[cx] = 0;
        bp = r16[cx];
    case 0x1f85b:
        r8[cl] = memory[ds*16 + si];
        si++;
        if (!(r8[cl] & 0x80)) {
            pc = 0x1f86e;
            break;
        }
        r8[cl] &= 0x7f;
        r8[cl]++;
        bp += r16[cx];
//console.log("rep movsb", [es, di, ds, si, r16[cx], memory[ds*16+si]].map(x=>x.toString(16)))
        rep_movsb_data_data_forward();
        pc = 0x1f875;
        break;
    case 0x1f86e:
        r8[cl]++;
        bp += r16[cx];
        lodsb_data_forward();
        rep_stosb_data_forward();
    case 0x1f875:
        if (bp < r16[dx]) {
            pc = 0x1f85b;
            break;
        }
        return;
    } while (1);
}
function* sub_1f87a() {
    r8[bh] = memory[ds*16 + 0x048f];
    yield* sub_1f888();
    yield* sub_1f8fd();
    yield* sub_1fb27();
}
function* sub_1f888() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0xff;
        if (!(r8[bh] & 0x02)) {
            pc = 0x1f894;
            break;
        }
        r8[al] = 0x07;
        si = 0x6479;
    case 0x1f894:
        if (!(r8[bh] & 0x04)) {
            pc = 0x1f89e;
            break;
        }
        r8[al] = 0x04;
        si = 0x644b;
    case 0x1f89e:
        if (!(r8[bh] & 0x80)) {
            pc = 0x1f8a8;
            break;
        }
        r8[al] = 0x09;
        si = 0x64a7;
    case 0x1f8a8:
        if (!(r8[bh] & 0x18)) {
            pc = 0x1f8b2;
            break;
        }
        r8[al] = 0x0d;
        si = 0x641d;
    case 0x1f8b2:
        memory[ds*16 + 0x048f] = r8[al];
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        r16[cx] = 0x002e;
        di = 0x63ef;
        rep_movsb_data_data_forward();
        es = pop();
        flags.carry = false;
        return;
    } while (1);
}
function* sub_1f8c5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory[ds*16 + 0x5e36] & 0x80)) {
            pc = 0x1f8d2;
            break;
        }
        yield* sub_20b66();
        pc = 0x1f8f6;
        break;
    case 0x1f8d2:
        push(es);
        r16[bx] = 0x0040;
        es = r16[bx];
        r16[ax] = memory16get(ds, 0x5d92);
        memory16set(es, 0x0063, r16[ax]);
        es = pop();
        if (memory[ds*16 + 0x5d94] != 0x01) {
            pc = 0x1f8f6;
            break;
        }
        r8[al] = 0x62;
        if (memory[ds*16 + 0x5e36] & 0x10) {
            pc = 0x1f8f2;
            break;
        }
        r8[al] = 0x22;
    case 0x1f8f2:
        r16[dx] = 0x03c2;
        out8(r16[dx], r8[al]);
    case 0x1f8f6:
        r8[al] = memory[ds*16 + 0x5e35];
        yield* sub_1f925();
        return;
    } while (1);
}
function* sub_1f8fd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory[ds*16 + 0x5e36] & 0x18)) {
            pc = 0x1f922;
            break;
        }
        if (memory[ds*16 + 0x048f] == 0x0d) {
            pc = 0x1f912;
            break;
        }
        if (memory[ds*16 + 0x048f] != 0x04) {
            pc = 0x1f922;
            break;
        }
    case 0x1f912:
        r8[ah] = 0x12;
        r8[bl] = 0x10;
        interrupt(0x10);
        if (r8[bh] == 0x00) {
            pc = 0x1f922;
            break;
        }
        memory[ds*16 + 0x5d94] = 0x01;
    case 0x1f922:
        r8[al] = memory[ds*16 + 0x048f];
        push(es);
        r16[bx] = 0x0040;
        es = r16[bx];
        r16[bx] = memoryBiosGet16(es, 0x0063);
        memory16set(ds, 0x5d92, r16[bx]);
        r8[bl] = memoryBiosGet(es, 0x0010);
        r8[bl] &= 0xcf;
        if (r8[al] != 0x07) {
            pc = 0x1f94c;
            break;
        }
        memory16set(es, 0x0063, 0x03b4);
        r8[bl] |= 0x30;
        pc = 0x1f956;
        break;
    case 0x1f94c:
        memoryBiosSet16(es, 0x0063, 0x03d4);
        r8[bl] |= 0x20;
    case 0x1f956:
        memoryBiosSet(es, 0x0010, r8[bl]);
        r8[ah] = 0x00;
        interrupt(0x10);
        es = pop();
        return;
    } while (1);
}
function* sub_1f925() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        r16[bx] = 0x0040;
        es = r16[bx];
        r16[bx] = memory16get(es, 0x0063);
        memory16set(ds, 0x5d92, r16[bx]);
        r8[bl] = memory[es*16 + 0x0010];
        r8[bl] &= 0xcf;
        if (r8[al] != 0x07) {
            pc = 0x1f94c;
            break;
        }
        memory16set(es, 0x0063, 0x03b4);
        r8[bl] |= 0x30;
        pc = 0x1f956;
        break;
    case 0x1f94c:
        memory16set(es, 0x0063, 0x03d4);
        r8[bl] |= 0x20;
    case 0x1f956:
        memory[es*16 + 0x0010] = r8[bl];
        r8[ah] = 0x00;
        interrupt(0x10);
        es = pop();
        return;
    } while (1);
}
function* sub_1f961() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03da;
    case 0x1f964:
        r8[al] = in8(r16[dx]);
        if (r8[al] & 0x08) {
            pc = 0x1f964;
            break;
        }
        r16[dx] = 0x03da;
    case 0x1f96c:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x08)) {
            pc = 0x1f96c;
            break;
        }
        r8[al] = 0x36;
        out8(0x43, r8[al]);
        r16[ax] = memory16get(ds, 0x595c);
        out8(0x40, r8[al]);
        r8[al] = r8[ah];
        out8(0x40, r8[al]);
        memory[cs*16 + 0x3259] = 0x00;
        return;
    } while (1);
}
function* sub_1f969() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03da;
    case 0x1f96c:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x08)) {
            pc = 0x1f96c;
            break;
        }
        r8[al] = 0x36;
        out8(0x43, r8[al]);
        r16[ax] = memory16get(ds, 0x595c);
        out8(0x40, r8[al]);
        r8[al] = r8[ah];
        out8(0x40, r8[al]);
        memory[cs*16 + 0x3259] = 0x00;
        return;
    } while (1);
}
function* sub_1f971() {
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    r16[ax] = memory16get(ds, 0x595c);
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
    memory[cs*16 + 0x3259] = 0x00;
}
function* sub_1f985() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[bx] = 0x48dc;
        r16[cx] = 0x002b;
        bp = 0x4907;
    case 0x1f98f:
        if (r8[ah] == memory[cs*16 + r16[bx]]) {
            pc = 0x1f99a;
            break;
        }
        r16[bx]++;
        bp += 0x0008;
        if (--r16[cx]) {
            pc = 0x1f98f;
            break;
        }
    case 0x1f99a:
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1fb27() {
    yield *jumpIndirect(cs, memory16get(ds, 0x63ef));
}
function* sub_1fb2b() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6407));
}
function* sub_1fb2f() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6409));
}
function* sub_1fb33() {
    yield *jumpIndirect(cs, memory16get(ds, 0x63f1));
}
function* sub_1fb37() {
    yield *jumpIndirect(cs, memory16get(ds, 0x640b));
}
function* sub_1fb3b() {
    push(r16[bx]);
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x63f7));
}
function* sub_1fb42() {
    yield *jumpIndirect(cs, memory16get(ds, 0x63fb));
}
function* sub_1fb46() {
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x63ff));
}
function* sub_1fb4c() {
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x63fd));
}
function* sub_1fb52() {
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x6401));
}
function* sub_1fb58() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(ds);
    yield *jumpIndirect(cs, memory16get(ds, 0x6417));
}
function* sub_1fb60() {
    stop(/*override stack*/);
    ds = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1fb65() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(ds);
    yield *jumpIndirect(cs, memory16get(ds, 0x6419));
}
function* sub_1fb6d() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(ds);
    yield *jumpIndirect(cs, memory16get(ds, 0x641b));
}
function* sub_1fb75() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6403));
}
function* sub_1fb79() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6405));
}
function* sub_1fb7d() {
    yield *jumpIndirect(cs, memory16get(ds, 0x640d));
}
function* sub_1fb81() {
    yield *jumpIndirect(cs, memory16get(ds, 0x63f3));
}
function* sub_1fb85() {
    yield *jumpIndirect(cs, memory16get(ds, 0x63f5));
}
function* sub_1fb89() {
    push(r16[bx]);
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x63f9));
}
function* sub_1fb90() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6411));
}
function* sub_1fb94() {
    push(r16[bx]);
    r16[bx] <<= 1;
    yield *jumpIndirect(cs, memory16get(ds, 0x640f));
}
function* sub_1fb9b() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6413));
}
function* sub_1fb9f() {
    yield *jumpIndirect(cs, memory16get(ds, 0x6415));
}
function* sub_1fba3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x06;
        if (!(memory[ds*16 + 0x5e36] & 0x10)) {
            pc = 0x1fbb4;
            break;
        }
        memory16set(ds, 0x595c, 0x4074);
        r8[al]++;
    case 0x1fbb4:
        memory[cs*16 + 0x40a9] = r8[al];
        if (memory[ds*16 + 0x5d94] != 0x01) {
            pc = 0x1fbce;
            break;
        }
        r8[al] = 0x63;
        if (memory[ds*16 + 0x5e36] & 0x10) {
            pc = 0x1fbca;
            break;
        }
        r8[al] = 0x23;
    case 0x1fbca:
        r16[dx] = 0x03c2;
        out8(r16[dx], r8[al]);
    case 0x1fbce:
        yield* sub_20014();
        r16[ax] = 0x0003;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        r16[ax] = 0x200c;
        r8[dl] = 0xd4;
        out16(r16[dx], r16[ax]);
        memory[ds*16 + 0x5db5] = 0x45;
        r16[ax] = memory16get(ds, 0x5dbc);
        memory16set(ds, 0x5dba, r16[ax]);
        return;
    } while (1);
}
function* sub_1fbeb() {
    r8[ah] = memory[ds*16 + 0x5e38];
    r8[al] = 0x0c;
    r16[dx] = 0x03d4;
    out16(r16[dx], r16[ax]);
    memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
    yield* sub_1f969();
}
function* sub_1fbfe() {
    push(ds);
    yield* sub_2001c();
    si = memory16get(ds, 0x5e37);
    di = si;
    si ^= 0x2000;
    r16[ax] = 0xa000;
    ds = r16[ax];
    r16[cx] = 0x2000;
    yield* sub_20413();
    yield* sub_20014();
    ds = pop();
}
function* sub_1fc1c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0xa000;
        if (!(memory[ds*16 + 0x5e38] & 0x20)) {
            pc = 0x1fc30;
            break;
        }
        r8[dh] += 0x02;
    case 0x1fc30:
        r16[cx] = 0x0fa0;
        push(es);
        es = r16[dx];
        r16[ax] = 0;
        di = r16[ax];
        rep_stosw_video_forward();
        es = pop();
        return;
    } while (1);
}
function* sub_1fc33() {
    push(es);
    es = r16[dx];
    r16[ax] = 0;
    di = r16[ax];
    rep_stosw_data_forward();
    es = pop();
}
function* sub_1fc3e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = memory16get(ds, 0x5e39);
        es = r16[ax];
        si = memory16get(es, r16[bx]);
        r16[bx] = r16[dx];
        yield* sub_20181();
        r8[ah] ^= 0x20;
        memory16set(ds, 0x5e4a, r16[ax]);
        r8[bl] = memory[es*16 + si];
        memory[ds*16 + 0x5e4c] = r8[bl];
        r8[cl] = memory[es*16 + si + 1];
        memory[ds*16 + 0x5e4d] = r8[cl];
        si = r16[ax];
        di = memory16get(ds, 0x5e48);
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r16[ax] = 0xa000;
        push(ds);
        ds = r16[ax];
        es = r16[ax];
        yield* sub_2001c();
    case 0x1fc78:
        push(si);
        push(r16[cx]);
        r16[cx] = r16[bx];
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        si = pop();
        si += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fc78;
            break;
        }
        yield* sub_20014();
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        es = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1fc8e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        r8[cl] = memory[ds*16 + 0x5e4d];
        if (!r8[cl]) {
            pc = 0x1fcd8;
            break;
        }
        push(r16[dx]);
        r8[bl] = memory[ds*16 + 0x5e4c];
        di = memory16get(ds, 0x5e4a);
        si = memory16get(ds, 0x5e48);
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r16[ax] = 0xa000;
        push(ds);
        push(es);
        ds = r16[ax];
        es = r16[ax];
        yield* sub_2001c();
    case 0x1fcb5:
        push(di);
        push(r16[cx]);
        r16[cx] = r16[bx];
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        di = pop();
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fcb5;
            break;
        }
        es = pop();
        ds = pop();
        memory[ds*16 + 0x5e4d] = r8[cl];
        r16[dx] = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(r16[dx]);
        if (r8[dl] <= 0xb5) {
            pc = 0x1fcd4;
            break;
        }
        yield* sub_1fcdb();
    case 0x1fcd4:
        yield* sub_20014();
        r16[dx] = pop();
    case 0x1fcd8:
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1fcdb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(es);
        di = 0x1d39;
        r16[bx] = di;
        r16[bx] ^= memory16get(ds, 0x5e37);
        if (r8[bh] & 0x20) {
            pc = 0x1fcef;
            break;
        }
        di ^= 0x2000;
    case 0x1fcef:
        si = 0x9000;
        r8[bl] = r8[cl];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl]--;
        r8[bh] = 0;
        di += r16[bx];
        si += r16[bx];
        r16[cx] = 0x0007;
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = r16[ax];
    case 0x1fd0c:
        push(si);
        push(di);
        push(r16[cx]);
        r16[cx] = 0x0002;
        rep_movsb_video_data_forward();
        r16[cx] = pop();
        di = pop();
        si = pop();
        di += 0x0028;
        si += 0x001b;
        if (--r16[cx]) {
            pc = 0x1fd0c;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_1fd22() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(ds);
        r16[cx] = 0x0007;
        si = 0x1d39;
        di = 0x9000;
        r16[ax] = 0xa000;
        ds = r16[ax];
        es = r16[ax];
        yield* sub_2001c();
    case 0x1fd37:
        push(si);
        push(r16[cx]);
        r16[cx] = 0x001b;
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        si = pop();
        si += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fd37;
            break;
        }
        yield* sub_20014();
        ds = pop();
        es = pop();
        return;
    } while (1);
}
function* sub_1fd4b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(ds);
        push(es);
        di = 0x1d39;
        r16[bx] = di;
        r16[bx] ^= memory16get(ds, 0x5e37);
        if (r8[bh] & 0x20) {
            pc = 0x1fd62;
            break;
        }
        di ^= 0x2000;
    case 0x1fd62:
        si = 0x9000;
        r8[bl] = memory[ds*16 + 0x5e43];
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl] >>= 1;
        r8[bl]--;
        r8[bh] = 0;
        di += r16[bx];
        si += r16[bx];
        r8[bl] = memory[ds*16 + 0x5e41];
        r16[cx] = 0x0007;
        r16[ax] = 0xa000;
        ds = r16[ax];
        es = r16[ax];
        yield* sub_2001c();
    case 0x1fd88:
        push(si);
        push(di);
        push(r16[cx]);
        r16[cx] = r16[bx];
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        di = pop();
        si = pop();
        di += 0x0028;
        si += 0x001b;
        if (--r16[cx]) {
            pc = 0x1fd88;
            break;
        }
        yield* sub_20014();
        es = pop();
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1fda3() {
    push(es);
    r16[ax] = memory16get(ds, 0x5e39);
    es = r16[ax];
    di = memory16get(es, r16[bx]);
    r16[ax] = memory16get(ds, 0x5e3b);
    es = r16[ax];
    r8[al] = memory[es*16 + di];
    memory[ds*16 + 0x5e41] = r8[al];
    memory[ds*16 + 0x5e43] = r8[cl];
    es = pop();
    r16[bx] = pop();
}
function* sub_1fdbe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(es);
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = memory16get(ds, 0x5e39);
        es = r16[ax];
        si = memory16get(es, r16[bx]);
        if (r16[bx] < 0x0190) {
            pc = 0x1fdd4;
            break;
        }
        r16[ax] = memory16get(ds, 0x5e3b);
        es = r16[ax];
    case 0x1fdd4:
        bp = 0;
        if (!(memory[ds*16 + 0x5e38] & 0x20)) {
            pc = 0x1fde0;
            break;
        }
        bp = 0x0005;
    case 0x1fde0:
        memory[ds*16 + bp + 24143] += 1;
        di = memory16get(ds, bp + 24144);
        r16[bx] = r16[dx];
        yield* sub_20181();
        memory16set(ds, di + 2, r16[ax]);
        r8[bl] = memory[es*16 + si];
        memory[ds*16 + di] = r8[bl];
        r8[cl] = memory[es*16 + si + 1];
        memory[ds*16 + di + 1] = r8[cl];
        si = r16[ax];
        r16[ax] = memory16get(ds, bp + 24146);
        memory16set(ds, di + 4, r16[ax]);
        di += 0x0006;
        memory16set(ds, bp + 24144, di);
        di = r16[ax];
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r16[ax] = 0xa000;
        push(ds);
        ds = r16[ax];
        es = r16[ax];
        yield* sub_2001c();
    case 0x1fe21:
        push(si);
        push(r16[cx]);
        r16[cx] = r16[bx];
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        si = pop();
        si += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fe21;
            break;
        }
        yield* sub_20014();
        ds = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        es = pop();
        memory16set(ds, bp + 24146, di);
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_1fe3b() {
}
function* sub_1fe3c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        bp = 0;
        if (!(memory[ds*16 + 0x5e38] & 0x20)) {
            pc = 0x1fe48;
            break;
        }
        bp = 0x0005;
    case 0x1fe48:
        r8[ch] = 0;
        r8[cl] = memory[ds*16 + bp + 24143];
        if (r16[cx] == 0)
            return;
        yield* sub_2001c();
    case 0x1fe54:
        push(r16[cx]);
        yield* sub_1fe64();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x1fe54;
            break;
        }
        memory[ds*16 + bp + 24143] = r8[cl];
        yield* sub_20014();
        return;
    } while (1);
}
function* sub_1fe64() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = memory16get(ds, bp + 24144);
        si -= 0x0006;
        memory16set(ds, bp + 24144, si);
        r8[bl] = memory[ds*16 + si];
        r8[cl] = memory[ds*16 + si + 1];
        di = memory16get(ds, si + 2);
        si = memory16get(ds, si + 4);
        memory16set(ds, bp + 24146, si);
        r8[bh] = 0;
        r8[ch] = r8[bh];
        r16[ax] = 0xa000;
        push(ds);
        push(es);
        ds = r16[ax];
        es = r16[ax];
    case 0x1fe8e:
        push(di);
        push(r16[cx]);
        r16[cx] = r16[bx];
        rep_movsb_video_video_forward();
        r16[cx] = pop();
        di = pop();
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fe8e;
            break;
        }
        es = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_1fe9e() {
    memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
    yield* sub_1feac();
    memory[ds*16 + 0x5e38] = memory[ds*16 + 0x5e38] ^ 0x20;
}
function* sub_1feac() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[bx] > 0x0015) {
            pc = 0x1fec1;
            break;
        }
        if (r16[bx] < 0x000b) {
            pc = 0x1fec1;
            break;
        }
        if (r16[cx] < 0x0008)
            return;
        if (r16[cx] > 0x00dc)
            return;
    case 0x1fec1:
        push(es);
        push(ds);
        r16[ax] = memory16get(ds, 0x5e39);
        es = r16[ax];
        bp = memory16get(es, r16[bx]);
        r16[tx] = r16[dx];
        r16[dx] = r16[bx];
        r16[bx] = r16[tx];
        if (r16[dx] >= 0x0190) {
            pc = 0x1fed9;
            break;
        }
        yield* sub_1fee6();
        ds = pop();
        es = pop();
        return;
    case 0x1fed9:
        yield* sub_20181();
        r16[dx] = memory16get(ds, 0x5e3b);
        yield* sub_1feed();
        ds = pop();
        es = pop();
        return;
    } while (1);
}
function* sub_1fee6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_20181();
        r16[dx] = memory16get(ds, 0x5e39);
        push(r16[ax]);
        ds = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[bx] &= 0x0007;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        di = r16[bx];
        r16[bx] = bp;
        r8[ch] = memory[ds*16 + r16[bx]];
        r8[cl] = memory[ds*16 + r16[bx] + 1];
        si = memory16get(ds, r16[bx] + di + 4);
        di = memory16get(ds, r16[bx] + di + 6);
        bp = pop();
        r8[bl] = r8[ch];
        r8[ch] = 0;
        r8[bh] = 0x00;
        r16[ax] = 0x0102;
        r8[dh] = 0x03;
    case 0x1ff17:
        push(r16[ax]);
        r8[dl] = 0xc4;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r8[al] = 0x04;
        r8[ah] = r8[bh];
        out16(r16[dx], r16[ax]);
        push(r16[cx]);
        push(bp);
        push(di);
    case 0x1ff25:
        push(r16[cx]);
        push(bp);
        r8[ch] = 0;
        r8[cl] = r8[bl];
    case 0x1ff2b:
        r8[ah] = videoGet(es, bp);
        r8[ah] &= memory[ds*16 + di];
        r8[ah] |= memory[ds*16 + si];
        videoSet(es, bp, r8[ah]);
        bp++;
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x1ff2b;
            break;
        }
        bp = pop();
        r16[cx] = pop();
        bp += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ff25;
            break;
        }
        di = pop();
        bp = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        r8[ah] <<= 1;
        r8[bh]++;
        if (r8[bh] != 0x04) {
            pc = 0x1ff17;
            break;
        }
        return;
    } while (1);
}
function* sub_1feed() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        ds = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[bx] &= 0x0007;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        di = r16[bx];
        r16[bx] = bp;
        r8[ch] = memory[ds*16 + r16[bx]];
        r8[cl] = memory[ds*16 + r16[bx] + 1];
        si = memory16get(ds, r16[bx] + di + 4);
        di = memory16get(ds, r16[bx] + di + 6);
        bp = pop();
        r8[bl] = r8[ch];
        r8[ch] = 0;
        r8[bh] = 0x00;
        r16[ax] = 0x0102;
        r8[dh] = 0x03;
    case 0x1ff17:
        push(r16[ax]);
        r8[dl] = 0xc4;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r8[al] = 0x04;
        r8[ah] = r8[bh];
        out16(r16[dx], r16[ax]);
        push(r16[cx]);
        push(bp);
        push(di);
    case 0x1ff25:
        push(r16[cx]);
        push(bp);
        r8[ch] = 0;
        r8[cl] = r8[bl];
    case 0x1ff2b:
        r8[ah] = videoGet(es, bp);
        r8[ah] &= memory[ds*16 + di];
        r8[ah] |= memory[ds*16 + si];
        videoSet(es, bp, r8[ah]);
        bp++;
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x1ff2b;
            break;
        }
        bp = pop();
        r16[cx] = pop();
        bp += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ff25;
            break;
        }
        di = pop();
        bp = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        r8[ah] <<= 1;
        r8[bh]++;
        if (r8[bh] != 0x04) {
            pc = 0x1ff17;
            break;
        }
        return;
    } while (1);
}
function* sub_1ff51() {
    push(es);
    push(ds);
    r16[ax] = memory16get(ds, 0x5e39);
    es = r16[ax];
    bp = memory16get(es, r16[bx] + 506);
    r16[bx] = r16[dx];
    r16[ax] = 0xa000;
    es = r16[ax];
    yield* sub_1ff6a();
    ds = pop();
    es = pop();
}
function* sub_1ff6a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_20181();
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x5e3d);
        ds = r16[ax];
        r16[bx] &= 0x0007;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        di = r16[bx];
        r16[bx] = bp;
        r8[ch] = memory[ds*16 + r16[bx]];
        r8[cl] = memory[ds*16 + r16[bx] + 1];
        si = memory16get(ds, r16[bx] + di + 4);
        di = pop();
        r8[bl] = r8[ch];
        r8[ch] = 0;
        r8[bh] = 0x00;
        r16[ax] = 0x0102;
        r8[dh] = 0x03;
    case 0x1ff92:
        push(r16[ax]);
        r8[dl] = 0xc4;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r8[al] = 0x04;
        r8[ah] = r8[bh];
        out16(r16[dx], r16[ax]);
        push(r16[cx]);
        push(di);
    case 0x1ff9f:
        push(r16[cx]);
        push(di);
        r8[ch] = 0;
        r8[cl] = r8[bl];
        si &= 0xffff;
        di &= 0xffff;
        assert(r16[cx]);
        if (es >= 0xa000)
          rep_movsb_video_data_forward();
        else
          rep_movsb_data_video_forward();
        di = pop();
        r16[cx] = pop();
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ff9f;
            break;
        }
        di = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        r8[ah] <<= 1;
        r8[bh]++;
        if (r8[bh] != 0x04) {
            pc = 0x1ff92;
            break;
        }
        return;
    } while (1);
}
function* sub_1ffbb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1ffbb;
        break;
    case 0x1fb60:
        ds = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x1ffbb:
        yield* sub_20049();
        r16[dx] = 0x03ce;
    case 0x1ffc1:
        r16[ax] = 0x0304;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xc4;
        r16[ax] = 0x0802;
        out16(r16[dx], r16[ax]);
        r8[ah] = videoGet(ds, r16[bx]);
        push(r16[ax]);
        videoSet(ds, r16[bx], 0x00);
        r16[ax] = 0x0702;
        out16(r16[dx], r16[ax]);
        r8[dl] = 0xce;
        r16[ax] = pop();
        r8[al] = 0x08;
        r8[ah] ^= 0xff;
        out16(r16[dx], r16[ax]);
        videoSet(ds, r16[bx], videoGet(ds, r16[bx]) & 0x00);
        r8[ah] = 0xff;
        out16(r16[dx], r16[ax]);
        r16[bx] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1ffc1;
            break;
        }
        pc = 0x1fb60;
        break;
        return;
    } while (1);
}
function* sub_1ffec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x1ffec;
        break;
    case 0x1fb60:
        ds = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x1ffec:
        yield* sub_2002a();
        di = si;
        push(es);
        es = r16[ax];
    case 0x1fff4:
        r8[al] = videoGet(ds, r16[bx]);
        stosb_video_forward();
        r16[bx] += 0x0028;
        if (--r16[cx]) {
            pc = 0x1fff4;
            break;
        }
        es = pop();
        yield* sub_20014();
        pc = 0x1fb60;
        break;
        return;
    } while (1);
}
function* sub_20003() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0x20003;
        break;
    case 0x1fb60:
        ds = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0x20003:
        yield* sub_2002a();
    case 0x20006:
        lodsb_video_forward();
        videoSet(ds, r16[bx], r8[al]);
        r16[bx] += 0x0028;
        if (--r16[cx]) {
            pc = 0x20006;
            break;
        }
        yield* sub_20014();
        pc = 0x1fb60;
        break;
        return;
    } while (1);
}
function* sub_20014() {
    r16[ax] = 0x0005;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
}
function* sub_2001c() {
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r16[ax] = 0xff02;
    out16(r16[dx], r16[ax]);
}
function* sub_2002a() {
    push(r16[ax]);
    push(r16[bx]);
    r8[al]--;
    r8[dl] = 0xb6;
    mul8(r8[dl]);
    r16[bx]--;
    r16[dx] = r16[bx];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] -= r16[dx];
    r16[ax] += r16[bx];
    r16[ax] += 0x8000;
    si = r16[ax];
    yield* sub_2001c();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[dx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] -= r16[dx];
    r16[ax] += 0x0003;
    r16[ax] <<= 1;
    push(r16[bx]);
    r16[bx] = r16[ax];
    r16[ax] = memory16get(cs, r16[bx] + 20695);
    r16[bx] = pop();
    r16[ax] += memory16get(ds, 0x5e37);
    r16[bx] += r16[ax];
    r16[ax] = 0xa000;
    ds = r16[ax];
    r16[cx] = 0x0007;
}
function* sub_20049() {
    r16[dx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] -= r16[dx];
    r16[ax] += 0x0003;
    r16[ax] <<= 1;
    push(r16[bx]);
    r16[bx] = r16[ax];
    r16[ax] = memory16get(cs, r16[bx] + 20695);
    r16[bx] = pop();
    r16[ax] += memory16get(ds, 0x5e37);
    r16[bx] += r16[ax];
    r16[ax] = 0xa000;
    ds = r16[ax];
    r16[cx] = 0x0007;
}
function* sub_20070() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        push(es);
        push(r16[ax]);
        r16[tx] = r16[cx];
        r16[cx] = r16[bx];
        r16[bx] = r16[tx];
        yield* sub_20181();
        r8[ah] &= 0xdf;
        di = r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[bx] = pop();
    case 0x20083:
        r8[ah] = memory[ds*16 + si];
        if (!r8[ah]) {
            pc = 0x20090;
            break;
        }
        yield* sub_200b6();
        si++;
        di++;
        pc = 0x20083;
        break;
    case 0x20090:
        es = pop();
        bp = pop();
        return;
    } while (1);
}
function* sub_20093() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(bp);
        push(es);
        push(r16[ax]);
        r16[tx] = r16[cx];
        r16[cx] = r16[bx];
        r16[bx] = r16[tx];
        yield* sub_20181();
        r8[ah] ^= 0x20;
        di = r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[bx] = pop();
    case 0x200a6:
        r8[ah] = memory[ds*16 + si];
        if (!r8[ah]) {
            pc = 0x200b3;
            break;
        }
        yield* sub_200e7();
        si++;
        di++;
        pc = 0x200a6;
        break;
    case 0x200b3:
        es = pop();
        bp = pop();
        return;
    } while (1);
}
function* sub_200b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1f985();
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
    case 0x200bf:
        push(di);
        push(bp);
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x0008;
    case 0x200c5:
        r8[bh] = memory[cs*16 + bp];
        if (r8[ah] & r8[bl]) {
            pc = 0x200cf;
            break;
        }
        r8[bh] = 0x00;
    case 0x200cf:
        videoSet(es, di, r8[bh]);
        videoSet(es, di + 8192, r8[bh]);
        bp++;
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x200c5;
            break;
        }
        bp = pop();
        di = pop();
        r8[ah] <<= 1;
        if (r8s[ah] < signed8(0x09)) {
            pc = 0x200bf;
            break;
        }
        return;
    } while (1);
}
function* sub_200e7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_1f985();
        r16[dx] = 0x03c4;
        r16[ax] = 0x0102;
    case 0x200f0:
        push(di);
        push(bp);
        out16(r16[dx], r16[ax]);
        r16[cx] = 0x0008;
    case 0x200f6:
        r8[bh] = memory[cs*16 + bp];
        if (r8[ah] & r8[bl]) {
            pc = 0x20100;
            break;
        }
        r8[bh] = 0x00;
    case 0x20100:
        videoSet(es, di, r8[bh]);
        bp++;
        di += 0x0028;
        if (--r16[cx]) {
            pc = 0x200f6;
            break;
        }
        bp = pop();
        di = pop();
        r8[ah] <<= 1;
        if (r8s[ah] < signed8(0x09)) {
            pc = 0x200f0;
            break;
        }
        return;
    } while (1);
}
function* sub_20113() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        push(ds);
        push(es);
        r16[cx] = 0x0000;
        r16[bx] = 0x0000;
        yield* sub_20181();
        r8[ah] ^= 0x20;
        di = r16[ax];
        r16[ax] += 0x0028;
        si = r16[ax];
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = r16[ax];
        yield* sub_2001c();
        r16[cx] = 0x0064;
    case 0x20137:
        push(r16[cx]);
        r16[cx] = 0x001d;
        rep_movsb_video_video_forward();
        si += 0x000b;
        di += 0x000b;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x20137;
            break;
        }
        yield* sub_20014();
        es = pop();
        ds = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_20173() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0505;
        if (!r8[al]) {
            pc = 0x2017d;
            break;
        }
        r16[ax] = 0x0507;
    case 0x2017d:
        yield* sub_2039b();
        return;
    } while (1);
}
function* sub_20181() {
    r16[bx] <<= 1;
    r16[ax] = memory16get(cs, r16[bx] + 20695);
    r16[bx] = r16[cx];
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[ax] += r16[cx];
    r16[ax] += memory16get(ds, 0x5e37);
}
function* sub_20366() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!(memory[ds*16 + 0x5e36] & 0x18)) {
            pc = 0x203ad;
            break;
        }
        r8[bl] = r8[al];
        r8[al] &= 0x1f;
        r8[ah] = 0;
        yield* sub_2039b();
        r8[al] = r8[bl];
        r8[al] &= 0xf0;
        r8[al] |= 0x02;
        if (!(r8[bl] & 0x20)) {
            pc = 0x20383;
            break;
        }
        r8[al] |= 0x03;
    case 0x20383:
        r8[bl] = r8[al];
        r8[ah] = 0x01;
        yield* sub_2039b();
        r8[bl] += 0x02;
        r8[al] = r8[bl];
        r8[ah] = 0x02;
        yield* sub_2039b();
        r8[bl] += 0x02;
        r8[al] = r8[bl];
        r8[ah] = 0x03;
        push(r16[ax]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[ax] = pop();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        r8[dl] = 0xc0;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        out8(r16[dx], r8[al]);
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        return;
    case 0x203ad:
        r16[dx] = 0x03d9;
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_2039b() {
    push(r16[ax]);
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    r16[ax] = pop();
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    r8[dl] = 0xc0;
    out8(r16[dx], r8[al]);
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    out8(r16[dx], r8[al]);
    r8[al] = 0x20;
    out8(r16[dx], r8[al]);
}
function* sub_20413() {
    push(es);
    es = r16[ax];
    rep_movsb_video_video_forward();
    es = pop();
}
function* sub_20996() {
    r16[tx] = r16[cx];
    r16[cx] = r16[bx];
    r16[bx] = r16[tx];
    push(r16[cx]);
    r16[bx] <<= 1;
    r16[bx] = memory16get(cs, r16[bx] + 22765);
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[bx] += r16[cx];
    r16[cx] = pop();
    r8[cl] &= 0x03;
    r8[cl] <<= 1;
}
function* sub_20b66() {
    r8[al] = 0xd0;
    yield* sub_20be5();
    yield* sub_20be3();
}
function* sub_20be3() {
    r8[al] = 0xc2;
    r16[dx] = 0x03df;
    out8(r16[dx], r8[al]);
    r16[dx] = 0xb800;
    r16[cx] = 0x4000;
    yield* sub_1fc33();
}
function* sub_20be5() {
    r16[dx] = 0x03df;
    out8(r16[dx], r8[al]);
    r16[dx] = 0xb800;
    r16[cx] = 0x4000;
    yield* sub_1fc33();
}
function* sub_2127e() {
    r16[bx] <<= 1;
    r16[ax] = memory16get(cs, r16[bx] + 25036);
    r16[bx] = r16[cx];
    r16[cx] >>= 1;
    r16[ax] += r16[cx];
}